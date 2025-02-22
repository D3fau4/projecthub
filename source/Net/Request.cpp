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

#include <switch.h>
#include "Request.hpp"

static struct curl_slist *hosts = NULL;

Net::Net() {
    curl_global_init(CURL_GLOBAL_DEFAULT);
    hosts = curl_slist_append(NULL, "github.com:140.82.118.4");
}

size_t writeFunction(void *ptr, size_t size, size_t nmemb, std::string* data) {
    data->append((char*) ptr, size * nmemb);
    return size * nmemb;
}

static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}
//UnderProjectNX
string Net::Request(string method, string url) {
    CURLcode res = CURLE_OK;
    CURL *curl = curl_easy_init();
    string response;
    if(curl) {
		curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
//		curl_easy_setopt(curl, CURLOPT_USERPWD, "CXboS8mjRWZneBS:");
		curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, method);
		curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
		curl_easy_setopt(curl, CURLOPT_RESOLVE, hosts);
		curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
		curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);
        	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        	curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
		res = curl_easy_perform(curl);
		curl_easy_cleanup(curl);
		std::cout << readBuffer << std::endl;
    }

    return !res ? response : "{}";
}

bool Net::Download(string url, string filepath) {
    FILE *fp;
    CURLcode res = CURLE_OK;
    CURL *curl = curl_easy_init();
    
    if (curl) {   
        fp = fopen(filepath.c_str(),"wb");
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
		curl_easy_setopt(curl, CURLOPT_USERPWD, "CXboS8mjRWZneBS:");
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(curl, CURLOPT_RESOLVE, hosts);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, fwrite);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
        curl_easy_setopt(curl, CURLOPT_FAILONERROR, true);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
        fclose(fp);
    } else {
        res = CURLE_HTTP_RETURNED_ERROR;
    }
    if (res != CURLE_OK)
        remove(filepath.c_str());
    return res == CURLE_OK ? false : true;
}
//Isaac
string Net::Request3(string method, string url) {
    CURLcode res = CURLE_OK;
    CURL *curl = curl_easy_init();
    string response;
    if(curl) {
		curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
//		curl_easy_setopt(curl, CURLOPT_USERPWD, "tfagdYSR6TdNmSX:");
		curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, method);
		curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
		curl_easy_setopt(curl, CURLOPT_RESOLVE, hosts);
		curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
		curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);
        	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        	curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
		res = curl_easy_perform(curl);
		curl_easy_cleanup(curl);
		std::cout << readBuffer << std::endl;
    }

    return !res ? response : "{}";
}

bool Net::Downloader3(string url, string filepath) {
    FILE *fp;
    CURLcode res = CURLE_OK;
    CURL *curl = curl_easy_init();
    
    if (curl) {   
        fp = fopen(filepath.c_str(),"wb");
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
		curl_easy_setopt(curl, CURLOPT_USERPWD, "tfagdYSR6TdNmSX:");
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(curl, CURLOPT_RESOLVE, hosts);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, fwrite);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
        curl_easy_setopt(curl, CURLOPT_FAILONERROR, true);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
        fclose(fp);
    } else {
        res = CURLE_HTTP_RETURNED_ERROR;
    }
    if (res != CURLE_OK)
        remove(filepath.c_str());
    return res == CURLE_OK ? false : true;
}

//DeltaProjectNX
/*
string Net::Request1(string method, string url) {
    CURLcode res = CURLE_OK;
    CURL *curl = curl_easy_init();
    string response;
    if(curl) {
		curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
		curl_easy_setopt(curl, CURLOPT_USERPWD, "NA9CsKnyApss5Lr:");
		curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, method);
		curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
		curl_easy_setopt(curl, CURLOPT_RESOLVE, hosts);
		curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
		curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);
        	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        	curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
		res = curl_easy_perform(curl);
		curl_easy_cleanup(curl);
		std::cout << readBuffer << std::endl;
    }

    return !res ? response : "{}";
}
*/
bool Net::Downloader1(string url, string filepath) {
    FILE *fp;
    CURLcode res = CURLE_OK;
    CURL *curl = curl_easy_init();
    
    if (curl) {   
        fp = fopen(filepath.c_str(),"wb");
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
		curl_easy_setopt(curl, CURLOPT_USERPWD, "NA9CsKnyApss5Lr:");
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(curl, CURLOPT_RESOLVE, hosts);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, fwrite);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
        curl_easy_setopt(curl, CURLOPT_FAILONERROR, true);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
        fclose(fp);
    } else {
        res = CURLE_HTTP_RETURNED_ERROR;
    }
    if (res != CURLE_OK)
        remove(filepath.c_str());
    return res == CURLE_OK ? false : true;
}
//NRO
/*
string Net::Request2(string method, string url) {
    CURLcode res = CURLE_OK;
    CURL *curl = curl_easy_init();
    string response;
    if(curl) {
		curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
		curl_easy_setopt(curl, CURLOPT_USERPWD, "2SY6ndgeyatE2j3:");
		curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, method);
		curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
		curl_easy_setopt(curl, CURLOPT_RESOLVE, hosts);
		curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
		curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);
        	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        	curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
		res = curl_easy_perform(curl);
		curl_easy_cleanup(curl);
		std::cout << readBuffer << std::endl;
    }

    return !res ? response : "{}";
}
*/

bool Net::Downloader2(string url, string filepath) {
    FILE *fp;
    CURLcode res = CURLE_OK;
    CURL *curl = curl_easy_init();
    
    if (curl) {   
        fp = fopen(filepath.c_str(),"wb");
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
		curl_easy_setopt(curl, CURLOPT_USERPWD, "2SY6ndgeyatE2j3:");
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(curl, CURLOPT_RESOLVE, hosts);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, fwrite);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
        curl_easy_setopt(curl, CURLOPT_FAILONERROR, true);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
        fclose(fp);
    } else {
        res = CURLE_HTTP_RETURNED_ERROR;
    }
    if (res != CURLE_OK)
        remove(filepath.c_str());
    return res == CURLE_OK ? false : true;
}