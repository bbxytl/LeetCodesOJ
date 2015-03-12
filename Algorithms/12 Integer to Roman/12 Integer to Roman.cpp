class Solution {
public:
    string intToRoman_1(int num) {
        if(num<=0||num>3999)return string();
        map<int,string> one,two,three,four;  //这里使用的是 Map
        one[0]="";      two[0]="";      three[0]="";
        one[1]="I";     two[1]="X";     three[1]="C";       four[1]="M";
        one[2]="II";    two[2]="XX";    three[2]="CC";      four[2]="MM";
        one[3]="III";   two[3]="XXX";   three[3]="CCC";     four[3]="MMM";
        one[4]="IV";    two[4]="XL";    three[4]="CD";
        one[5]="V";     two[5]="L";     three[5]="D";
        one[6]="VI";    two[6]="LX";    three[6]="DC";
        one[7]="VII";   two[7]="LXX";   three[7]="DCC";
        one[8]="VIII";  two[8]="LXXX";  three[8]="DCCC";
        one[9]="IX";    two[9]="XC";    three[9]="CM";

        int mod=0,idx=1;
        string rs="",tmp="";
        while(num>0){
            mod=num%10;
            switch(idx){
            case 1:{
                tmp=one[mod];
                rs=tmp+rs;
                break;
            }
            case 2:{
                tmp=two[mod];
                rs=tmp+rs;
                break;
            }
            case 3:{
                tmp=three[mod];
                rs=tmp+rs;
                break;
            }
            case 4:{
                tmp=four[mod];
                rs=tmp+rs;
                break;
            }
            }
            num=num/10;
            ++idx;
        }
        return rs;
    }
};

class Solution {
public:
    string intToRoman_2(int num) {
        if(num<=0||num>3999)return string();
        string* one=new string[10],*two=new string[10],*three=new string[10],*four=new string[4];
        one[0]="";      two[0]="";      three[0]="";        four[0]="";
        one[1]="I";     two[1]="X";     three[1]="C";       four[1]="M";
        one[2]="II";    two[2]="XX";    three[2]="CC";      four[2]="MM";
        one[3]="III";   two[3]="XXX";   three[3]="CCC";     four[3]="MMM";
        one[4]="IV";    two[4]="XL";    three[4]="CD";
        one[5]="V";     two[5]="L";     three[5]="D";
        one[6]="VI";    two[6]="LX";    three[6]="DC";
        one[7]="VII";   two[7]="LXX";   three[7]="DCC";
        one[8]="VIII";  two[8]="LXXX";  three[8]="DCCC";
        one[9]="IX";    two[9]="XC";    three[9]="CM";

        int mod=0,idx=1;
        string rs="",tmp="";
        while(num>0){
            mod=num%10;
            switch(idx){
                case 1:{
                    tmp=one[mod];
                    rs=tmp+rs;
                    break;
                }
                case 2:{
                    tmp=two[mod];
                    rs=tmp+rs;
                    break;
                }
                case 3:{
                    tmp=three[mod];
                    rs=tmp+rs;
                    break;
                }
                case 4:{
                    tmp=four[mod];
                    rs=tmp+rs;
                    break;
                }
            }
            num=num/10;
            ++idx;
        }
        return rs;
    }
};


class Solution {
public:
    string intToRoman_3(int num) {
        if(num<=0||num>3999)return string();
        string roman="IVXLCDM";
        string rs="",tmp="";
        int ndx=0,mod=0;
        while(num>0){
            mod=num%10;
            if(ndx==6){
                rs=string(mod,'M')+rs;
                break;
            }
            if(mod==0){
                tmp="";
            }else if(mod<4){
                tmp=string(mod,roman[ndx]);
            }else if(mod==4){
                tmp=string(1,roman[ndx])+string(1,roman[ndx+1]);
            }else if(mod<9){
                tmp=string(1,roman[ndx+1])+string(mod-5,roman[ndx]);
            }else if(mod==9){
                tmp=string(1,roman[ndx])+string(1,roman[ndx+2]);
            }
            rs=tmp+rs;
            ndx+=2;
            num/=10;
        }
        return rs;
    }
};

class Solution {
public:
    string intToRoman_4(int num) {
        if(num<=0||num>3999)return string();
        char roman[]="IVXLCDM";
        string rs="";
        int ndx=0,mod=0;
        while(num>0){
            mod=num%10;
            if(ndx==6){
                rs=string(mod,'M')+rs;
                break;
            }
            if(mod<4){
                rs=string(mod,roman[ndx])+rs;
            }else if(mod==4){
                rs.insert(rs.begin(),roman[ndx+1]);
                rs.insert(rs.begin(),roman[ndx]);
                // rs=string(1,roman[ndx])+string(1,roman[ndx+1])+rs;
            }else if(mod<9){
                // rs=string(1,roman[ndx+1])+string(mod-5,roman[ndx])+rs;
                rs=string(mod-5,roman[ndx])+rs;
                rs.insert(rs.begin(),roman[ndx+1]);
            }else if(mod==9){
                rs.insert(rs.begin(),roman[ndx+2]);
                rs.insert(rs.begin(),roman[ndx]);
                // rs=string(1,roman[ndx])+string(1,roman[ndx+2])+rs;
            }
            ndx+=2;
            num/=10;
        }
        return rs;
    }
};

class Solution {
public:
    string intToRoman_5(int num) {
        string M[] = {"", "M", "MM", "MMM"};
        string C[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        string X[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        string I[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        return M[num/1000] + C[(num%1000)/100] + X[(num%100)/10] + I[num%10];
    }
};

class Solution {
public:
    string intToRoman_6(int num) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        string result = "";
        int base[] = {1000,500,100,50,10,5,1,0};
        char baseC[] = {'M','D','C','L','X','V','I'};
        int basen = 0;
        while(num) {
            if(basen%2 == 0 && num/base[basen] == 4) {
                result += baseC[basen];
                result += baseC[basen-1];
                num -= base[basen] * 4;
            } else if(num >= base[basen]) {
                result += baseC[basen];
                num -= base[basen];
            } else if(basen%2 == 0 && num / base[basen+2] == 9) {
                result += baseC[basen+2];
                result += baseC[basen];
                num -= base[basen+2]*9;
            } else {
                basen++;
            }
        }
        return result;
    }
};
