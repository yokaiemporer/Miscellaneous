import Foundation
var t = "abacaabadcabacabaabb"
var p = "abacab"
var LC:[String : Int]=["a":-1,"b":-1,"c":-1]
var alphabet:String="abcdefghijklmnopqrstuvwxyz"
extension String {

    var length: Int {
        return count
    }

    subscript (i: Int) -> String {
        return self[i ..< i + 1]
    }

    func substring(fromIndex: Int) -> String {
        return self[min(fromIndex, length) ..< length]
    }

    func substring(toIndex: Int) -> String {
        return self[0 ..< max(0, toIndex)]
    }

    subscript (r: Range<Int>) -> String {
        let range = Range(uncheckedBounds: (lower: max(0, min(length, r.lowerBound)),
                                            upper: min(length, max(0, r.upperBound))))
        let start = index(startIndex, offsetBy: range.lowerBound)
        let end = index(start, offsetBy: range.upperBound - range.lowerBound)
        return String(self[start ..< end])
    }
}
for c in 0..<alphabet.count
{
    let x:String = alphabet[c]
    LC[x] = -1
    
}
func boyermoore(t: String,p: String)->Int
{
    var n = t.count
    var m = p.count
    var i = m-1
    var j = m-1
    var l:Int
    while(i<t.count)
    {
        if t[i]==p[j]{
            if j==0{
            return i
            }
            else {
                i-=1;
                j-=1;
            }
        }
        else
        {
            var temp = t[i]
            if let temp = LC[temp] {
                if temp != -1
                {l = temp}
                else
                {l=0}
                }
                else 
                {l=0} 
            i = i+m-min(j,1+l)
            j = m-1
        }
    }
    return -1
}
print(boyermoore(t:t,p:p))


