#include<bits/stdc++.h>
using namespace std;
class reg{
    vector<float> x;
    vector<float> y;
    float coeff;
    float constTerm;
    float sum_xy;
    float sum_x;
    float sum_y;
    float sum_x_square;
    float sum_y_square;

    public:
    reg(){
        coeff = 0;
        constTerm = 0;
        sum_y = 0;
        sum_x = 0;
        sum_x_square = 0;
        sum_xy = 0;
        sum_y_square = 0;
    }

    void calc_coeff(){
        float N = x.size();
        float numerator = (N * sum_xy - sum_x * sum_y);
        float denominator = (N * sum_x_square - pow(sum_x,2));
        coeff = numerator/denominator;
    }

    void calc_const_term(){
        float N = x.size();
        float numerator = (sum_y * sum_x_square - sum_x * sum_xy);
        float denominator = (N * sum_x_square - pow(sum_x,2));
        constTerm = numerator/denominator;
    }

    int sizeofData(){
        return x.size();
    }

    float coefficient(){
        if(coeff == 0){
            calc_coeff();
        }
        return coeff;
    }

    float constant(){
        if(constTerm == 0){
            calc_const_term();
        }
        return constTerm;
    }

    void bestfitline(){
        if(coeff == 0 && constTerm == 0){
            calc_coeff();
            calc_const_term();
        }
        cout << "The Best Fitting Line is y = " << coeff << "x + " << constTerm << endl;
    }

    void input(int n){
        for(int i = 0; i < n; i++){
            char comma;
            float xi;
            float yi;
            cin >> xi >> comma >> yi;
            sum_xy += xi * yi;
            sum_x += xi;
            sum_y += yi;
            sum_x_square += xi * xi;
            sum_y_square += yi * yi;
            x.push_back(xi);
            y.push_back(yi);
        }
    }

    float predict(float x){
        return coeff * x + constTerm;
    }

    float error_square(){
        float ans = 0;
        for(int i = 0; i < x.size(); i++){
            ans += ((predict(x[i]) - y[i]) *(predict(x[i]) - y[i]));
        }
        return ans;
    }

    float errorIn(float num){
        for(int i = 0; i < x.size(); i++){
            if(num == x[i]){
                return(y[i] - predict(x[i]));
            }
        }
        return 0;
    }
};

int main(){
    freopen("input.txt", "r", stdin);
    reg regi;
    int n;
    cin >> n;
    
    regi.input(n);
    regi.bestfitline();
    cout << "Predicted value at 3500 = " << regi.predict(3500) << endl;
    cout << "The errorSquared is = " << regi.error_square() << endl;
    cout << "Error in 1990 = " << regi.errorIn(1990) << endl;
}
