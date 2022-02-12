unsigned int lustre_errno_hton(unsigned int h)
{
unsigned int n;
if (h == 0) {
n = 0;
} else if (h < ARRAY_SIZE(lustre_errno_hton_mapping)) {
n = lustre_errno_hton_mapping[h];
if (n == 0)
goto generic;
} else {
generic:
n = LUSTRE_EIO;
}
return n;
}
unsigned int lustre_errno_ntoh(unsigned int n)
{
unsigned int h;
if (n == 0) {
h = 0;
} else if (n < ARRAY_SIZE(lustre_errno_ntoh_mapping)) {
h = lustre_errno_ntoh_mapping[n];
if (h == 0)
goto generic;
} else {
generic:
h = EIO;
}
return h;
}
