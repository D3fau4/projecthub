/*
* ReiNX Toolkit
* Copyright (C) 2018  Team ReiSwitched
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
* 
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once
#include <iostream>
#include <string>
#include <sys/select.h>
#include <curl/curl.h>
#include <switch.h>

using namespace std;

class Net {
    public:
        Net();
	std::string readBuffer;
    string Request(string method, string url);
    bool Download(string url, string filepath);
	
	string Request1(string method, string url);
    bool Downloader1(string url, string filepath);
	 
	string Request2(string method, string url);
    bool Downloader2(string url, string filepath);
	
	string Request3(string method, string url);
    bool Downloader3(string url, string filepath);
};
