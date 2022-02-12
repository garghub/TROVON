int
uf_verify_m4(unifi_priv_t *priv, const unsigned char *packet, unsigned int length)
{
const unsigned char *p = packet;
u16 keyinfo;
if (length < (4 + 5 + 8 + 32 + 16 + 8 + 8 + 16 + 1 + 8))
return 1;
p += 8;
keyinfo = p[5] << 8 | p[6];
if (
(p[0] == 1 || p[0] == 2) &&
p[1] == 3 &&
(p[4] == 254 || p[4] == 2) &&
((keyinfo & 0x0007) == 1 || (keyinfo & 0x0007) == 2) &&
(keyinfo & ~0x0207U) == 0x0108 &&
(p[4 + 5 + 8 + 32 + 16 + 8 + 8 + 16 + 0] == 0 &&
p[4 + 5 + 8 + 32 + 16 + 8 + 8 + 16 + 1] == 0)
) {
unifi_trace(priv, UDBG1, "uf_verify_m4: M4 detected\n");
return 0;
} else {
return 1;
}
}
