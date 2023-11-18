int mx_strncmp(const char *s1, const char *s2, int n)
{
    int indx = 0;
    while (indx < n)
    {
        if (s1[indx] != s2[indx])
        {
            return s1[indx] - s2[indx];
        }
        indx++;
    }
    return 0;
}
