/*-
 * Copyright (c) 2009-2010 Tom Rhodes. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 * notice, this list of conditions and the following disclaimer in the
 * documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 */

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cstdlib>
#include <ctime>

using namespace std;

/*
 * Tokenizer function.
 *
 * Works like:
 * string test = "zero:one:two:three:four:five";
 * string sep = ":";
 *
 * vector <string> *blah;
 * blah = fsctok(test, sep);
 * for (int x = 0; x < blah->size(); x++) {
 *     cout << blah->at(x) << endl;
 * }
 *
 * And it prints all the separated bits.
 */
vector <string> *fsctok(string &orig_str, string delim)
{
	vector <string> *str_vec = new vector <string>();
	string tempstr;

	while (orig_str.find(delim, 0) != string::npos) {
	    /* Does the string contain a delimiter? */
	    size_t pos = orig_str.find(delim, 0);
	    tempstr = orig_str.substr(0, pos);
	    orig_str.erase(0, pos + 1);
	    str_vec->push_back(tempstr);
	}
	str_vec->push_back(orig_str);

	return(str_vec);
}
