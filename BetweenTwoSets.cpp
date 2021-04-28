int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}

int gcd1(int a, int b)
{
    int c = 0;
    while (b)
    {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int lcm(int a, int b)
{
    return a * (b / gcd(a, b));
}

int gcd(vector<int> arr)
{
    int result = arr[0];
    for (size_t i = 1; i < arr.size(); i++)
    {
        result = gcd(result, arr[i]);
    }
    return result;
}

int lcm(vector<int> arr)
{
    int result = arr[0];
    for (size_t i = 1; i < arr.size(); i++)
    {
        result = lcm(result, arr[i]);
    }
    return result;
}

int getTotalX(vector<int> a, vector<int> b)
{
    int a_lcm = lcm(a);
    int b_gcd = gcd(b);
    int count = 0;

    for (int i = a_lcm, j = 2; i <= b_gcd; i = a_lcm * j, j++)
    {
        if (b_gcd % i == 0)
        {
            count++;
        }
    }

    return count;
}
