void
debug_string_indication(unifi_priv_t *priv, const unsigned char *extra, unsigned int extralen)
{
const unsigned int maxlen = sizeof(priv->last_debug_string) - 1;
if (extralen > maxlen) {
extralen = maxlen;
}
strncpy(priv->last_debug_string, extra, extralen);
priv->last_debug_string[extralen] = '\0';
unifi_info(priv, "unifi debug: %s\n", priv->last_debug_string);
}
void
debug_word16_indication(unifi_priv_t *priv, const CSR_SIGNAL *sigptr)
{
int i;
if (priv == NULL) {
unifi_info(priv, "Priv is NULL\n");
return;
}
for (i = 0; i < 16; i++) {
priv->last_debug_word16[i] =
sigptr->u.DebugWord16Indication.DebugWords[i];
}
if (priv->last_debug_word16[0] == 0xFA11) {
unsigned long ts;
ts = (priv->last_debug_word16[6] << 16) | priv->last_debug_word16[5];
unifi_info(priv, " %10lu: %s fault %04x, arg %04x (x%d)\n",
ts,
priv->last_debug_word16[3] == 0x8000 ? "MAC" :
priv->last_debug_word16[3] == 0x4000 ? "PHY" :
"???",
priv->last_debug_word16[1],
priv->last_debug_word16[2],
priv->last_debug_word16[4]);
}
else if (priv->last_debug_word16[0] != 0xDBAC)
{
unifi_info(priv, "unifi debug: %04X %04X %04X %04X %04X %04X %04X %04X\n",
priv->last_debug_word16[0], priv->last_debug_word16[1],
priv->last_debug_word16[2], priv->last_debug_word16[3],
priv->last_debug_word16[4], priv->last_debug_word16[5],
priv->last_debug_word16[6], priv->last_debug_word16[7]);
unifi_info(priv, " %04X %04X %04X %04X %04X %04X %04X %04X\n",
priv->last_debug_word16[8], priv->last_debug_word16[9],
priv->last_debug_word16[10], priv->last_debug_word16[11],
priv->last_debug_word16[12], priv->last_debug_word16[13],
priv->last_debug_word16[14], priv->last_debug_word16[15]);
}
}
void
debug_generic_indication(unifi_priv_t *priv, const CSR_SIGNAL *sigptr)
{
unifi_info(priv, "debug: %04X %04X %04X %04X %04X %04X %04X %04X\n",
sigptr->u.DebugGenericIndication.DebugWords[0],
sigptr->u.DebugGenericIndication.DebugWords[1],
sigptr->u.DebugGenericIndication.DebugWords[2],
sigptr->u.DebugGenericIndication.DebugWords[3],
sigptr->u.DebugGenericIndication.DebugWords[4],
sigptr->u.DebugGenericIndication.DebugWords[5],
sigptr->u.DebugGenericIndication.DebugWords[6],
sigptr->u.DebugGenericIndication.DebugWords[7]);
}
