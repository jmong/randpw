/**
 * Random password generator.
 * 
 * Copyright (C) 2015
 * Joe Mong
 * 
 * Changelog:
 *   1.0.1 [2015-03-06]
 *     - Fixed exclude lower- and upper-case alpha options ignored.
 *     - Updated readme.md.
 *   1.0.0 [2015-02-18]
 */

#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include <ctime>
#include <cstdlib>
#include <getopt.h>
#include <string.h>
#include <string>
#include <ctype.h>

using namespace std;

static const string LC_ALPHA  = "abcdefghijklmnopqrstuvwxyz";
static const string UC_ALPHA  = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
static const string NUMBERS   = "1234567890";
static const string SYMBOLS   = "~!@#$%^&*()-+_={}|[]'\"<>,.\\:;/?";

/* Numbers and characters to pick randomly from. */
string candidateset_buf;

/**
 * Print usage.
 * @param Name of this program.
 **/
void usage(const string &prog);

/**
 * Get a random character.
 * @param Strings to pick a random character from.
 * @return A random character
 **/
char get_random_char(const string &candidateset);
