int uuid_create(uuid_t *uuid)
{
uuid_time_t timestamp, last_time;
unsigned16 clockseq;
uuid_node_t node;
uuid_node_t last_node;
int f;
LOCK;
get_current_time(&timestamp);
get_ieee_node_identifier(&node);
f = read_state(&clockseq, &last_time, &last_node);
if (!f || memcmp(&node, &last_node, sizeof node))
clockseq = true_random();
else if (timestamp < last_time)
clockseq++;
write_state(clockseq, timestamp, node);
UNLOCK;
format_uuid_v1(uuid, clockseq, timestamp, node);
return 1;
}
void format_uuid_v1(uuid_t* uuid, unsigned16 clock_seq,
uuid_time_t timestamp, uuid_node_t node)
{
uuid->time_low = (unsigned long)(timestamp & 0xFFFFFFFF);
uuid->time_mid = (unsigned short)((timestamp >> 32) & 0xFFFF);
uuid->time_hi_and_version =
(unsigned short)((timestamp >> 48) & 0x0FFF);
uuid->time_hi_and_version |= (1 << 12);
uuid->clock_seq_low = clock_seq & 0xFF;
uuid->clock_seq_hi_and_reserved = (clock_seq & 0x3F00) >> 8;
uuid->clock_seq_hi_and_reserved |= 0x80;
memcpy(&uuid->node, &node, sizeof uuid->node);
}
int read_state(unsigned16 *clockseq, uuid_time_t *timestamp,
uuid_node_t *node)
{
static int inited = 0;
FILE *fp;
if (!inited) {
fp = fopen("state", "rb");
if (fp == NULL)
return 0;
fread(&st, sizeof st, 1, fp);
fclose(fp);
inited = 1;
}
*clockseq = st.cs;
*timestamp = st.ts;
*node = st.node;
return 1;
}
void write_state(unsigned16 clockseq, uuid_time_t timestamp,
uuid_node_t node)
{
static int inited = 0;
static uuid_time_t next_save;
FILE* fp;
if (!inited) {
next_save = timestamp;
inited = 1;
}
st.cs = clockseq;
st.ts = timestamp;
st.node = node;
if (timestamp >= next_save) {
fp = fopen("state", "wb");
fwrite(&st, sizeof st, 1, fp);
fclose(fp);
next_save = timestamp + (10 * 10 * 1000 * 1000);
}
}
void get_current_time(uuid_time_t *timestamp)
{
static int inited = 0;
static uuid_time_t time_last;
static unsigned16 uuids_this_tick;
uuid_time_t time_now;
if (!inited) {
get_system_time(&time_now);
uuids_this_tick = UUIDS_PER_TICK;
inited = 1;
}
for ( ; ; ) {
get_system_time(&time_now);
if (time_last != time_now) {
uuids_this_tick = 0;
time_last = time_now;
break;
}
if (uuids_this_tick < UUIDS_PER_TICK) {
uuids_this_tick++;
break;
}
}
*timestamp = time_now + uuids_this_tick;
}
static unsigned16 true_random(void)
{
static int inited = 0;
uuid_time_t time_now;
if (!inited) {
get_system_time(&time_now);
time_now = time_now / UUIDS_PER_TICK;
srand((unsigned int)
(((time_now >> 32) ^ time_now) & 0xffffffff));
inited = 1;
}
return rand();
}
void uuid_create_md5_from_name(uuid_t *uuid, uuid_t nsid, void *name,
int namelen)
{
MD5_CTX c;
unsigned char hash[16];
uuid_t net_nsid;
net_nsid = nsid;
net_nsid.time_low = htonl(net_nsid.time_low);
net_nsid.time_mid = htons(net_nsid.time_mid);
net_nsid.time_hi_and_version = htons(net_nsid.time_hi_and_version);
MD5Init(&c);
MD5Update(&c, &net_nsid, sizeof net_nsid);
MD5Update(&c, name, namelen);
MD5Final(hash, &c);
format_uuid_v3or5(uuid, hash, 3);
}
void uuid_create_sha1_from_name(uuid_t *uuid, uuid_t nsid, void *name,
int namelen)
{
SHA_CTX c;
unsigned char hash[20];
uuid_t net_nsid;
net_nsid = nsid;
net_nsid.time_low = htonl(net_nsid.time_low);
net_nsid.time_mid = htons(net_nsid.time_mid);
net_nsid.time_hi_and_version = htons(net_nsid.time_hi_and_version);
SHA1_Init(&c);
SHA1_Update(&c, &net_nsid, sizeof net_nsid);
SHA1_Update(&c, name, namelen);
SHA1_Final(hash, &c);
format_uuid_v3or5(uuid, hash, 5);
}
void format_uuid_v3or5(uuid_t *uuid, unsigned char hash[16], int v)
{
memcpy(uuid, hash, sizeof *uuid);
uuid->time_low = ntohl(uuid->time_low);
uuid->time_mid = ntohs(uuid->time_mid);
uuid->time_hi_and_version = ntohs(uuid->time_hi_and_version);
uuid->time_hi_and_version &= 0x0FFF;
uuid->time_hi_and_version |= (v << 12);
uuid->clock_seq_hi_and_reserved &= 0x3F;
uuid->clock_seq_hi_and_reserved |= 0x80;
}
int uuid_compare(uuid_t *u1, uuid_t *u2)
{
int i;
CHECK(u1->time_low, u2->time_low);
CHECK(u1->time_mid, u2->time_mid);
CHECK(u1->time_hi_and_version, u2->time_hi_and_version);
CHECK(u1->clock_seq_hi_and_reserved, u2->clock_seq_hi_and_reserved);
CHECK(u1->clock_seq_low, u2->clock_seq_low)
for (i = 0; i < 6; i++) {
if (u1->node[i] < u2->node[i])
return -1;
if (u1->node[i] > u2->node[i])
return 1;
}
return 0;
}
