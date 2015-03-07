#include "randpw.h"

/**
 * Print usage.
 * @param Name of this program.
 **/
void 
usage(const string &prog) {
    string file_basename( basename(prog.c_str()) );

    cout << "Usage:   " << file_basename << " [Options] LENGTH"                  << endl \
         << "Options: --nosymbols|-S"                                            << endl \
         << "               Exclude symbol characters in the password string."   << endl \
         << "               [Default: included]"                                 << endl \
         << "         --nonumbers|-N"                                            << endl \
         << "               Exclude number characters in the password string."   << endl \
         << "               [Default: included]"                                 << endl \
         << "         --noucalpha|-U"                                            << endl \
         << "               Exclude upper case letters in the password string."  << endl \
         << "               [Default: included]"                                 << endl \
         << "         --nolcalpha|-L"                                            << endl \
         << "               Exclude lower case letters in the password string."  << endl \
         << "               [Default: included]"                                 << endl \
         << "         --iterations|-i <number>"                                  << endl \
         << "               Number of passwords to generate at once."            << endl \
         << "               [Default: 1]"                                        << endl \
         << "         --help|-h"                                                 << endl \
         << "               This help usage."                                    << endl \
    ;
}

/**
 * Get a random character.
 * @param Strings to pick a random character from.
 * @return A random character
 **/
char 
get_random_char(const string &candidateset) {
    int len = 0;
    int pos = 0;
    
    len = candidateset.length() - 1;
    pos = (rand() % len) + 1;
    
    #ifdef _DEBUG
        cout << "[DEBUG] get_randow_char() : candidateset[" << pos << "] = " << candidateset[pos] << endl;
    #endif
    
    return candidateset[pos];
}


int 
main(int argc, char **argv) {
    string pw_buf;
    int pw_len         = 0;
    int opt            = 0;
    int opt_wo_sym     = 0;
    int opt_wo_num     = 0;
    int opt_wo_lcalpha = 0;
    int opt_wo_ucalpha = 0;
    int opt_iter       = 1;
    int long_idx       = 0;
    static const char *optstring = "SNLUi:h";
    static const struct option longopts[] = {
        { "nosymbols", no_argument, NULL, 'S' },
        { "nonumbers", no_argument, NULL, 'N' },
        { "nolcalpha", no_argument, NULL, 'L' },
        { "noucalpha", no_argument, NULL, 'U' },
        { "iterations", required_argument, NULL, 'i' },
        { "help", no_argument, NULL, 'h' },
        { NULL, no_argument, NULL, 0 },
    };
    
    if (argc < 2) {
        cout << "Error: LENGTH argument is required." << endl;
        usage(argv[0]);
        exit(1);    
    }

    srand(time(0));
    while ( (opt = getopt_long(argc, argv, optstring, longopts, &long_idx)) != -1  ) {
        /* Detect the end of the options. */
        if (opt == -1)
            break;
 
        switch(opt) {
            case 'S':
                opt_wo_sym = 1;
                break;
            case 'N':
                opt_wo_num = 1;
                break;
            case 'L':
                opt_wo_lcalpha = 1;
                break;
            case 'U':
                opt_wo_ucalpha = 1;
                break;
            case 'i':
                opt_iter = atoi(optarg);
                break;
            case 'h':
                usage(argv[0]);
                exit(0);
            default:
                cout << "Invalid option " << optarg << "." << endl;
                   usage(argv[0]);
                   exit(1);
         }
    }
    
    #ifdef _DEBUG
        cout << "[DEBUG] opt_wo_sym, opt_wo_num, opt_wo_lcalpha, opt_wo_ucalpha = "                   \
             << opt_wo_sym << ", " << opt_wo_num << ", " << opt_wo_lcalpha << ", " << opt_wo_ucalpha  \
             << endl;
    #endif
    /* Check every character in the LENGTH argument to make sure everyone is a digit. */
    for (int i = 0; i < strlen(argv[argc-1]); ++i) {
        #ifdef _DEBUG
            cout << "[DEBUG] LENGTH character position [" << i << "] = " << argv[argc-1][i] << endl;
        #endif
        if ( ! isdigit(argv[argc-1][i]) ) {
            cout << "Error: LENGTH value " << argv[argc-1] << " is an invalid number." << endl;
            exit(1);
        }
    }
    pw_len = atoi(argv[argc-1]);
    
    /* Include numbers */
    if ( opt_wo_num == 0 )
        candidateset_buf += NUMBERS;
    /* Include upper case letters */
    if ( opt_wo_lcalpha == 0 )
        candidateset_buf += UC_ALPHA;
    /* Include lower case letters */
    if ( opt_wo_ucalpha == 0 )
        candidateset_buf += LC_ALPHA;
    /* Include symbols */
    if ( opt_wo_sym == 0 )
        candidateset_buf += SYMBOLS;
        
    #ifdef _DEBUG
        cout << "[DEBUG] pw_len = " << pw_len << endl;
        cout << "[DEBUG] candidateset = " << candidateset_buf << endl;
        cout << "[DEBUG] candidateset length = " << candidateset_buf.length() << endl;
    #endif
    
    if (pw_len < 1) {
        usage( argv[0] );
        exit(1);
    }
    
    if (candidateset_buf.length() == 0) {
        cout << "Error: zero-size candidate set." << endl;
        exit(1);
    }
    
    for (int i = 0; i < opt_iter; i++) {
        pw_buf.clear();    
        for (int i = 0; i < pw_len; ++i) {
            string s(1, get_random_char(candidateset_buf));    // overloaded string ctor from char 
            pw_buf += s;
        }
        
        fprintf(stdout, "%s\n", pw_buf.c_str());
    }
    
    return 0;
}
