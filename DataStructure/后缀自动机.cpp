const int MAXL(1e6+7);
string s;
int maxlen[2*MAXL], minlen[2*MAXL], suffix[2*MAXL], trans[2*MAXL][26];  //保证节点数少于2N-2
int len, pos, nodeNum = 0;
ll outt = 0;  //子串种数

inline int newNode(const int& maxl=0, const int& minl=0, const int& suffixp=-1) {
    int nowpos = nodeNum++;
    maxlen[nowpos] = maxl;
    minlen[nowpos] = minl;
    suffix[nowpos] = suffixp;
    per(i, 0, 26) {
        trans[nowpos][i] = -1;
    }
    return nowpos;
}

//每次在原有SAM上插入新字符
int addChar(int ch, int endpos) {
    int newpos = newNode(maxlen[endpos]+1, 1);
    int judgepos = endpos;
    while(judgepos>-1 && trans[judgepos][ch]==-1) {
        trans[judgepos][ch] = newpos;
        judgepos = suffix[judgepos];
    }
    //情况1
    if(judgepos==-1) {
        suffix[newpos] = 0;
        return newpos;
    }
    //情况2
    int transpos = trans[judgepos][ch];
    if(maxlen[judgepos]+1 == maxlen[transpos]) {
        minlen[newpos] = maxlen[transpos]+1;
        suffix[newpos] = transpos;
        return newpos;
    }
    //情况3
    {
        //split the transpos
        int splitpos = newNode(maxlen[judgepos]+1, minlen[transpos], suffix[transpos]);
        per(i,0,26) {
            trans[splitpos][i] = trans[transpos][i];
        }
        minlen[transpos] = maxlen[splitpos]+1;
        suffix[transpos] = splitpos;
        //set newpos
        minlen[newpos] = maxlen[splitpos]+1;
        suffix[newpos] = splitpos;
        //set suffix node
        while(judgepos>-1 && trans[judgepos][ch]==transpos) {
            trans[judgepos][ch] = splitpos;
            judgepos = suffix[judgepos];
        }
        return newpos;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> s;
    len = s.length();
    //judge
    pos = newNode();
    per(i, 0, len) {
        pos = addChar(s[i]-'a', pos);
    }
    //output
    per(i, 1, nodeNum) {
        outt += maxlen[i]-minlen[i]+1;
    }
    cout << outt << endl;
    return 0;
}
