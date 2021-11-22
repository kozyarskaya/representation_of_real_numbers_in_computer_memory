#include <iostream>
#include <string>
using namespace std;

long long itc_len(string str){
    long long kol = 0, i = 0;
    while (str[i] != '\0'){
        kol++;
        i++;
    }
   return kol;
}



int itc_len_num(unsigned long long number){
    if (number < 0){
        number *= -1;
    }
   int kol = 0;
   if (number == 0){

       return 1;
   }
   else{
   while (number > 0){
        number /= 10;
        kol += 1;
   }
   return kol;
 }
}

int itc_find_str(string str1, string str2){
    long long len1 = 0;
    len1 =  itc_len(str1);
    long long len2 = 0;
    len2 = itc_len(str2);
    long long kol = 0;
    for (long long i = 0; i < len1; i++){
        kol = 0;
        if (str1[i] == str2[0]){
        for (long long j = 0; j < len2; j++){
            if (str1[i + j] == str2[j]){
                kol += 1;
            }
        }
        }
        if (kol == len2){
            return i;
        }
    }
    return -1;
}

string itc_slice_str(string str, int start, int finish){
    long long len = itc_len(str);
    string new_str = "";
    if (finish >= len){
        for (long long i = start; i < len; i++){
            new_str += str[i];
        }
    }
   else if (start >= len){
        return str;
    }
    else if (start == (len - 1)){
        return new_str += str[len - 1];
    }
    else{
        for (long long i = start; i <= finish; i++){
            new_str += str[i];
        }
    }
    return new_str;
return "-1";
}


string itc_int_to_str(unsigned long long num){
    char ch = '#';
    string str = "", new_str = "";
    while(num > 0){
        ch = (num % 10) + 48;
        str += ch;
        num /=10;
    }
    for(long long i = (itc_len(str) - 1); i >= 0; i--){
        new_str += str[i];
    }
    return new_str;
}

 unsigned long long itc_str_to_int(string str){
    long long number = 0, i = 0;
    int ch = 0;
    while(str[i] != '\0'){
        ch = str[i] - 48;
        number = number * 10 + ch;
        i ++;
    }
    return number;
}
string itc_reverse_str(string str){
	string new_str = "";
	for (int i = itc_len(str) - 1; i >= 0; i--)
	{
		new_str += str[i];
	}
	return new_str;
}

string itc_chs_to_bin(unsigned long long number){
    string new_str = "";
    while(number > 0){
        if (number % 2 == 0)
            new_str += "0";
        if (number % 2 == 1)
            new_str += "1" ;

        number /= 2;
    }
    return itc_reverse_str(new_str);
}
bool only_null(string str) {
    long long i = 0;
    bool bol = true;
    while(str[i] != '\0'){
        if (str[i] != '0' && str[i] != '.')
            bol = false;
        i++;
       }
    return bol;
   }

long long itc_covert_num(long long number, int ss){

    long long new_num = 0, pow_of_ten = 1;
    if (number < 0)
        return (itc_covert_num((number * -1), ss))* -1;
    while(number > 0){
        new_num += number % ss * pow_of_ten;
        number /= ss;
        pow_of_ten *= 10;
    }
    return new_num;
}

string ex(string nums){

    string dr_ch = "";
    if (nums == "0")
        return "0";
    unsigned long long num;
    num = itc_str_to_int(nums);
    int len = itc_len_num(num);
    dr_ch = itc_chs_to_bin(num);
    return dr_ch;
}
string per_drob(string nums){
    string dr_ch = "";
    int len = itc_len(nums);
    unsigned long long num = itc_str_to_int(nums);

    unsigned long long poww = 1;
    for (long long i = 0;i < len; i++){
    poww *= 10;
    }
    for(int j = 0; j <64; j++){
        num *= 2;
        if (itc_len_num(num) > len){
        dr_ch += "1";
        num %= poww;

        }
        else
        dr_ch += "0";
}
    return dr_ch;
}



string print_all_num(string str){
    string bin_num = "";
    string exponenta = "";
    string mantissa = "";
    string ex1 = "", dr = "";

    int in1 = itc_find_str(str,".");
    int in2 = itc_find_str(str,",");
    string chs,chf;
    int in = (in1 + in2) + 1;
    if (in + in2 == -2){
        chs = str;
        chf = "0";}

    if (str[0] == '-'){
        bin_num += "1";
        chs = itc_slice_str(str, 1, in - 1);}
    if (str[0] == '+'){
        bin_num+= "0";
        chs = itc_slice_str(str, 1, in - 1);}
    if (str[0] != '-' && str[0] != '+' ){
        bin_num+= "0";
        chs = itc_slice_str(str, 0, in - 1);}

        chf = itc_slice_str(str, in + 1, itc_len(str) - 1);


    if(str == "0" || str == "-0" || str == "-0.0" || str == "0.0" || str == "-0,0" || str == "0,0" || only_null(str))
        bin_num += "0000000000000000000000000000000";
    else if (str == "inf" || str == "INF" || str == "Inf" || str == "infinity" || str == "INFINITY" || str == "Infinity" || str == "-inf" || str == "-INF" || str == "-Inf" || str == "-infinity" || str == "-INFINITY" || str == "-Infinity")
	    bin_num += "1111111100000000000000000000000";
    else if (str == "nan" || str == "NaN" || str == "NAN" || str == "-nan" || str == "-NaN" || str == "-NAN")
        bin_num += "1111111111111111111111111111111";


    else{

        ex1 += ex(chs);
        dr += per_drob(chf);
        int ss;


        if(ex1 == "0"){
            ss = (itc_find_str(dr, "1") + 1) * (-1);
            mantissa += itc_slice_str(dr, (ss * -1), itc_len(dr));
        }

        else{
            ss = itc_len(ex1) - (itc_find_str(ex1, "1") + 1);
            mantissa += itc_slice_str(ex1, (itc_find_str(ex1, "1") + 1), itc_len(ex1));
            mantissa += dr;
        }

        long long smesh = itc_covert_num((127 + ss), 2);
        if(itc_len_num(smesh) < 8){
            for(int i = 0; i < (8 - itc_len_num(smesh)); i++){
                exponenta += "0";

            }
        }

        exponenta += itc_int_to_str(smesh);
        bin_num += exponenta;
        bin_num += itc_slice_str(mantissa, 0, 22);
    }
return bin_num;
}

int main()
{
string str;
getline(cin, str);
cout << print_all_num(str) << endl;
//cout << itc_len(print_all_num(str));

    return 0;
}
