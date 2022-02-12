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
static void int_unregister_cb(ENGINE_PILE *pile, ENGINE *e)
{
int n;
while((n = sk_ENGINE_find(pile->sk, e)) >= 0)
{
sk_ENGINE_delete(pile->sk, n);
pile->uptodate = 0;
}
if(pile->funct == e)
{
engine_unlocked_finish(e, 0);
pile->funct = NULL;
}
}
void int_cleanup_cb(ENGINE_PILE *p)
{
sk_ENGINE_free(p->sk);
if(p->funct)
engine_unlocked_finish(p->funct, 0);
OPENSSL_free(p);
}
