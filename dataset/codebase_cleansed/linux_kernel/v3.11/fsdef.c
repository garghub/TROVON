static uint16_t fscache_fsdef_netfs_get_key(const void *cookie_netfs_data,
void *buffer, uint16_t bufmax)
{
const struct fscache_netfs *netfs = cookie_netfs_data;
unsigned klen;
_enter("{%s.%u},", netfs->name, netfs->version);
klen = strlen(netfs->name);
if (klen > bufmax)
return 0;
memcpy(buffer, netfs->name, klen);
return klen;
}
static uint16_t fscache_fsdef_netfs_get_aux(const void *cookie_netfs_data,
void *buffer, uint16_t bufmax)
{
const struct fscache_netfs *netfs = cookie_netfs_data;
unsigned dlen;
_enter("{%s.%u},", netfs->name, netfs->version);
dlen = sizeof(uint32_t);
if (dlen > bufmax)
return 0;
memcpy(buffer, &netfs->version, dlen);
return dlen;
}
static enum fscache_checkaux fscache_fsdef_netfs_check_aux(
void *cookie_netfs_data,
const void *data,
uint16_t datalen)
{
struct fscache_netfs *netfs = cookie_netfs_data;
uint32_t version;
_enter("{%s},,%hu", netfs->name, datalen);
if (datalen != sizeof(version)) {
_leave(" = OBSOLETE [dl=%d v=%zu]", datalen, sizeof(version));
return FSCACHE_CHECKAUX_OBSOLETE;
}
memcpy(&version, data, sizeof(version));
if (version != netfs->version) {
_leave(" = OBSOLETE [ver=%x net=%x]", version, netfs->version);
return FSCACHE_CHECKAUX_OBSOLETE;
}
_leave(" = OKAY");
return FSCACHE_CHECKAUX_OKAY;
}
