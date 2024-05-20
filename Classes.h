#include <cmath>
#include <iostream>

using namespace std;

class User
{
public:
    int mod_index;
    int altitudes;
    double code_rate;
    double spec_eff;
    User(int mod = 0, int alt=0, double code = 0, double spec = 0)
    {
        mod_index = mod;
        altitudes=alt;
        code_rate = code;
        spec_eff = spec;
    }
};

class Utility
{
public:
    static int getRequiredResourceBlocks(int mod_index, double code_rate)
    {
        return 4 * ceil((32 * 1024) /
                        ((mod_index) * (code_rate) * (12) * (14) * (0.6)));
    }

    static double getPower(int requiredResourceBlocks)
    {
        return 39.81 / requiredResourceBlocks;
    }

    static double getSNR(int bandwidth, double spectralEfficiency)
    {
        return pow(2, spectralEfficiency / bandwidth) - 1;
    }

    static double getChannelQuality(double SNR, double power,int altitudes)
    {
        return (SNR / power)*pow(2.718,-(altitudes/1000));
    }
    
    static double getDataRate(double spec_eff, int bandwidth)
    {
        return spec_eff * bandwidth;
    }
};