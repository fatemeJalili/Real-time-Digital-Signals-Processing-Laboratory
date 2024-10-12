#include <stdio.h>
# define N  80
# define H  55
float out;
int i;
int j;
float temp[H + N - 1];

float sine1[H + N -1] = {0.982287250728689,0.998026728428272,0.998026728428272,0.982287250728689,0.951056516295154,0.904827052466019,0.844327925502015,0.770513242775789,0.684547105928688,0.587785252292473,0.481753674101715,0.368124552684678,0.248689887164854,0.125333233564303,-1.22464679914735e-16,-0.125333233564305,-0.248689887164855,-0.368124552684679,-0.481753674101716,-0.587785252292474,-0.684547105928689,-0.770513242775790,-0.844327925502015,-0.904827052466020,-0.951056516295154,-0.982287250728689,-0.998026728428272,-0.998026728428272,-0.982287250728689,-0.951056516295154,-0.904827052466019,-0.844327925502015,-0.770513242775789,-0.684547105928688,-0.587785252292473,-0.481753674101715,-0.368124552684678,-0.248689887164854,-0.125333233564304,6.81224316017311e-16,0.125333233564304,0.248689887164855,0.368124552684678,0.481753674101715,0.587785252292473,0.684547105928689,0.770513242775789,0.844327925502015,0.904827052466020,0.951056516295154,0.982287250728689,0.998026728428272,0.998026728428272,0.982287250728689,0.951056516295154,0.904827052466020,0.844327925502015,0.770513242775789,0.684547105928689,0.587785252292473,0.481753674101716,0.368124552684678,0.248689887164855,0.125333233564305,1.22464679914735e-16,-0.125333233564304,-0.248689887164855,-0.368124552684678,-0.481753674101715,-0.587785252292473,-0.684547105928688,-0.770513242775789,-0.844327925502015,-0.904827052466019,-0.951056516295154,-0.982287250728689,-0.998026728428272,-0.998026728428272,-0.982287250728689,-0.951056516295154};
float sine2[H + N -1] = {0.368124552684677,0.125333233564303,-0.125333233564306,-0.368124552684680,-0.587785252292473,-0.770513242775791,-0.904827052466020,-0.982287250728689,-0.998026728428272,-0.951056516295153,-0.844327925502015,-0.684547105928688,-0.481753674101713,-0.248689887164853,2.44929359829471e-16,0.248689887164856,0.481753674101716,0.684547105928690,0.844327925502016,0.951056516295154,0.998026728428272,0.982287250728689,0.904827052466019,0.770513242775789,0.587785252292472,0.368124552684678,0.125333233564303,-0.125333233564305,-0.368124552684679,-0.587785252292474,-0.770513242775790,-0.904827052466020,-0.982287250728689,-0.998026728428271,-0.951056516295153,-0.844327925502014,-0.684547105928688,-0.481753674101714,-0.248689887164854,1.36244863203462e-15,0.248689887164854,0.481753674101715,0.684547105928688,0.844327925502015,0.951056516295153,0.998026728428272,0.982287250728689,0.904827052466020,0.770513242775789,0.587785252292474,0.368124552684678,0.125333233564305,-0.125333233564304,-0.368124552684678,-0.587785252292473,-0.770513242775789,-0.904827052466019,-0.982287250728689,-0.998026728428272,-0.951056516295154,-0.844327925502016,-0.684547105928689,-0.481753674101715,-0.248689887164855,-2.44929359829471e-16,0.248689887164855,0.481753674101715,0.684547105928688,0.844327925502015,0.951056516295154,0.998026728428272,0.982287250728689,0.904827052466020,0.770513242775790,0.587785252292473,0.368124552684678,0.125333233564306,-0.125333233564303,-0.368124552684677,-0.587785252292473};
float sine3[H + N -1] = {0.951056516295154,0.587785252292472,-0.587785252292475,-0.951056516295153,1.71450551880629e-15,0.951056516295154,0.587785252292472,-0.587785252292474,-0.951056516295153,1.46957615897682e-15,0.951056516295154,0.587785252292472,-0.587785252292480,-0.951056516295153,1.22464679914735e-15,0.951056516295155,0.587785252292469,-0.587785252292474,-0.951056516295153,9.79717439317883e-16,0.951056516295154,0.587785252292473,-0.587785252292474,-0.951056516295153,4.28750175828891e-15,0.951056516295154,0.587785252292470,-0.587785252292475,-0.951056516295152,4.89858719658941e-16,0.951056516295155,0.587785252292473,-0.587785252292476,-0.951056516295151,3.79764303862997e-15,0.951056516295156,0.587785252292470,-0.587785252292479,-0.951056516295152,6.81224316017311e-15,0.951056516295152,0.587785252292473,-0.587785252292470,-0.951056516295154,-3.79764303862997e-15,0.951056516295153,0.587785252292476,-0.587785252292473,-0.951056516295153,-4.89858719658941e-16,0.951056516295154,0.587785252292475,-0.587785252292476,-0.951056516295154,2.81792559931209e-15,0.951056516295153,0.587785252292471,-0.587785252292475,-0.951056516295153,2.57299623948262e-15,0.951056516295153,0.587785252292474,-0.587785252292472,-0.951056516295154,-1.22464679914735e-15,0.951056516295155,0.587785252292474,-0.587785252292472,-0.951056516295154,5.63585119862418e-15,0.951056516295153,0.587785252292469,-0.587785252292472,-0.951056516295152,-1.71450551880629e-15,0.951056516295155,0.587785252292475,-0.587785252292477,-0.951056516295154,5.14599247896524e-15};
float h[H] = {-0.00120295857096518,-0.00239558663205205,-0.00204368405826441,-0.000474427646026957,0.00253874816230716,0.00399729223017862,0.00246489895435800,-0.00227641756481881,-0.00652201334037918,-0.00629377639174331,6.72278710016486e-05,0.00850466552148789,0.0118941062372055,0.00522516378495524,-0.00848857329928923,-0.0187904972984968,-0.0148646161651623,0.00432000897917206,0.0260706925455878,0.0308942670202486,0.00790927625387178,-0.0325407837552200,-0.0599057473887772,-0.0408577209977637,0.0370128683536389,0.151525593471142,0.253802210532860,0.294723324577415,0.253802210532860,0.151525593471142,0.0370128683536389,-0.0408577209977637,-0.0599057473887772,-0.0325407837552200,0.00790927625387178,0.0308942670202486,0.0260706925455878,0.00432000897917206,-0.0148646161651623,-0.0187904972984968,-0.00848857329928923,0.00522516378495524,0.0118941062372055,0.00850466552148789,6.72278710016486e-05,-0.00629377639174331,-0.00652201334037918,-0.00227641756481881,0.00246489895435800,0.00399729223017862,0.00253874816230716,-0.000474427646026957,-0.00204368405826441,-0.00239558663205205,-0.00120295857096518};

void convolution(float* x, float* h, float* y)
{
    int len = H + N -1;
    for (int n = 0; n < len; n++)
    {
        y[n] = 0;
        for (int k = 0; k < H; k++)
        {
            if (n - k >= 0 && n - k < N)
            {
                y[n] += x[n - k] * h[k];
            }
        }
    }
}

int main() {
    float result[H + N - 1];
    convolution(sine2 , h, result);
    for (int i = 0; i < N + H - 1; i++)
    {
        printf("%f\n", result[i]);
    }
    return 0;
}


