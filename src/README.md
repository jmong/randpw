randpw
======

Generate random passwords.

Description
-----------

Yet another random password generator.

I added a few features (some obvious) to hopefully make it more useful:

- Specify password length
- Exclude set(s) of characters, symbols, or numbers
- Specify number of passwords to generate per run


Installation
------------

    make
    
Examples
--------

Generate a 10-character password.
```
$ randpw 10
```

Generate a 10-character password without numbers nor symbols
(that is, you want a password with only lower- and
upper-case alphabetic characters).
```
$ randpw --nosymbols --nonumbers 10
```

Generate five(5) 10-character passwords without upper-case
alphabetic characters.
```
$ randpw --iterations 5 --noucalpha 10
```

Copyright
---------

Copyright 2015 Joe Mong. Licensed under the Apache License 2.0
