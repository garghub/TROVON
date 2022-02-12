void
uuid_getnodeuniq(uuid_t *uuid, int fsid [2])
{
xfs_uu_t *uup = (xfs_uu_t *)uuid;
fsid[0] = (be16_to_cpu(uup->uu_clockseq) << 16) |
be16_to_cpu(uup->uu_timemid);
fsid[1] = be32_to_cpu(uup->uu_timelow);
}
int
uuid_is_nil(uuid_t *uuid)
{
int i;
char *cp = (char *)uuid;
if (uuid == NULL)
return 0;
for (i = 0; i < sizeof *uuid; i++)
if (*cp++) return 0;
return 1;
}
int
uuid_equal(uuid_t *uuid1, uuid_t *uuid2)
{
return memcmp(uuid1, uuid2, sizeof(uuid_t)) ? 0 : 1;
}
