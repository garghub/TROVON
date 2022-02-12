int p9_error_init(void)
{
struct errormap *c;
int bucket;
for (bucket = 0; bucket < ERRHASHSZ; bucket++)
INIT_HLIST_HEAD(&hash_errmap[bucket]);
for (c = errmap; c->name != NULL; c++) {
c->namelen = strlen(c->name);
bucket = jhash(c->name, c->namelen, 0) % ERRHASHSZ;
INIT_HLIST_NODE(&c->list);
hlist_add_head(&c->list, &hash_errmap[bucket]);
}
return 1;
}
int p9_errstr2errno(char *errstr, int len)
{
int errno;
struct hlist_node *p;
struct errormap *c;
int bucket;
errno = 0;
p = NULL;
c = NULL;
bucket = jhash(errstr, len, 0) % ERRHASHSZ;
hlist_for_each_entry(c, p, &hash_errmap[bucket], list) {
if (c->namelen == len && !memcmp(c->name, errstr, len)) {
errno = c->val;
break;
}
}
if (errno == 0) {
errstr[len] = 0;
pr_err("%s: server reported unknown error %s\n",
__func__, errstr);
errno = ESERVERFAULT;
}
return -errno;
}
