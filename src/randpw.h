/**
 * Copyright 2015 Joe Mong
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
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
