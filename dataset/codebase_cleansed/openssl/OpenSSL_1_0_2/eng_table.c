unsigned int ENGINE_get_table_flags(void)
{
return table_flags;
}
void ENGINE_set_table_flags(unsigned int flags)
{
table_flags = flags;
}
static unsigned long engine_pile_hash(const ENGINE_PILE *c)
{
return c->nid;
}
static int engine_pile_cmp(const ENGINE_PILE *a, const ENGINE_PILE *b)
{
return a->nid - b->nid;
}
static void int_unregister_cb_doall_arg(ENGINE_PILE *pile, ENGINE *e)
{
int n;
while ((n = sk_ENGINE_find(pile->sk, e)) >= 0) {
(void)sk_ENGINE_delete(pile->sk, n);
pile->uptodate = 0;
}
if (pile->funct == e) {
engine_unlocked_finish(e, 0);
pile->funct = NULL;
}
}
void int_cleanup_cb_doall(ENGINE_PILE *p)
{
sk_ENGINE_free(p->sk);
if (p->funct)
engine_unlocked_finish(p->funct, 0);
OPENSSL_free(p);
}
void int_cb_doall_arg(ENGINE_PILE *pile, ENGINE_PILE_DOALL *dall)
{
dall->cb(pile->nid, pile->sk, pile->funct, dall->arg);
}
