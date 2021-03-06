unsigned ceph_str_hash_rjenkins(const char *str, unsigned length)
{
const unsigned char *k = (const unsigned char *)str;
__u32 a, b, c;
__u32 len;
len = length;
a = 0x9e3779b9;
b = a;
c = 0;
while (len >= 12) {
a = a + (k[0] + ((__u32)k[1] << 8) + ((__u32)k[2] << 16) +
((__u32)k[3] << 24));
b = b + (k[4] + ((__u32)k[5] << 8) + ((__u32)k[6] << 16) +
((__u32)k[7] << 24));
c = c + (k[8] + ((__u32)k[9] << 8) + ((__u32)k[10] << 16) +
((__u32)k[11] << 24));
mix(a, b, c);
k = k + 12;
len = len - 12;
}
c = c + length;
switch (len) {
case 11:
c = c + ((__u32)k[10] << 24);
case 10:
c = c + ((__u32)k[9] << 16);
case 9:
c = c + ((__u32)k[8] << 8);
case 8:
b = b + ((__u32)k[7] << 24);
case 7:
b = b + ((__u32)k[6] << 16);
case 6:
b = b + ((__u32)k[5] << 8);
case 5:
b = b + k[4];
case 4:
a = a + ((__u32)k[3] << 24);
case 3:
a = a + ((__u32)k[2] << 16);
case 2:
a = a + ((__u32)k[1] << 8);
case 1:
a = a + k[0];
}
mix(a, b, c);
return c;
}
unsigned ceph_str_hash_linux(const char *str, unsigned length)
{
unsigned long hash = 0;
unsigned char c;
while (length--) {
c = *str++;
hash = (hash + (c << 4) + (c >> 4)) * 11;
}
return hash;
}
unsigned ceph_str_hash(int type, const char *s, unsigned len)
{
switch (type) {
case CEPH_STR_HASH_LINUX:
return ceph_str_hash_linux(s, len);
case CEPH_STR_HASH_RJENKINS:
return ceph_str_hash_rjenkins(s, len);
default:
return -1;
}
}
const char *ceph_str_hash_name(int type)
{
switch (type) {
case CEPH_STR_HASH_LINUX:
return "linux";
case CEPH_STR_HASH_RJENKINS:
return "rjenkins";
default:
return "unknown";
}
}
