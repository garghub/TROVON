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
static int int_table_check(ENGINE_TABLE **t, int create)
{
LHASH_OF(ENGINE_PILE) *lh;
if (*t)
return 1;
if (!create)
return 0;
if ((lh = lh_ENGINE_PILE_new(engine_pile_hash, engine_pile_cmp)) == NULL)
return 0;
*t = (ENGINE_TABLE *)lh;
return 1;
}
int engine_table_register(ENGINE_TABLE **table, ENGINE_CLEANUP_CB *cleanup,
ENGINE *e, const int *nids, int num_nids,
int setdefault)
{
int ret = 0, added = 0;
ENGINE_PILE tmplate, *fnd;
CRYPTO_THREAD_write_lock(global_engine_lock);
if (!(*table))
added = 1;
if (!int_table_check(table, 1))
goto end;
if (added)
engine_cleanup_add_first(cleanup);
while (num_nids--) {
tmplate.nid = *nids;
fnd = lh_ENGINE_PILE_retrieve(&(*table)->piles, &tmplate);
if (!fnd) {
fnd = OPENSSL_malloc(sizeof(*fnd));
if (fnd == NULL)
goto end;
fnd->uptodate = 1;
fnd->nid = *nids;
fnd->sk = sk_ENGINE_new_null();
if (!fnd->sk) {
OPENSSL_free(fnd);
goto end;
}
fnd->funct = NULL;
(void)lh_ENGINE_PILE_insert(&(*table)->piles, fnd);
}
(void)sk_ENGINE_delete_ptr(fnd->sk, e);
if (!sk_ENGINE_push(fnd->sk, e))
goto end;
fnd->uptodate = 0;
if (setdefault) {
if (!engine_unlocked_init(e)) {
ENGINEerr(ENGINE_F_ENGINE_TABLE_REGISTER,
ENGINE_R_INIT_FAILED);
goto end;
}
if (fnd->funct)
engine_unlocked_finish(fnd->funct, 0);
fnd->funct = e;
fnd->uptodate = 1;
}
nids++;
}
ret = 1;
end:
CRYPTO_THREAD_unlock(global_engine_lock);
return ret;
}
static void int_unregister_cb(ENGINE_PILE *pile, ENGINE *e)
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
void engine_table_unregister(ENGINE_TABLE **table, ENGINE *e)
{
CRYPTO_THREAD_write_lock(global_engine_lock);
if (int_table_check(table, 0))
lh_ENGINE_PILE_doall_ENGINE(&(*table)->piles, int_unregister_cb, e);
CRYPTO_THREAD_unlock(global_engine_lock);
}
static void int_cleanup_cb_doall(ENGINE_PILE *p)
{
if (!p)
return;
sk_ENGINE_free(p->sk);
if (p->funct)
engine_unlocked_finish(p->funct, 0);
OPENSSL_free(p);
}
void engine_table_cleanup(ENGINE_TABLE **table)
{
CRYPTO_THREAD_write_lock(global_engine_lock);
if (*table) {
lh_ENGINE_PILE_doall(&(*table)->piles, int_cleanup_cb_doall);
lh_ENGINE_PILE_free(&(*table)->piles);
*table = NULL;
}
CRYPTO_THREAD_unlock(global_engine_lock);
}
static void int_dall(const ENGINE_PILE *pile, ENGINE_PILE_DOALL *dall)
{
dall->cb(pile->nid, pile->sk, pile->funct, dall->arg);
}
void engine_table_doall(ENGINE_TABLE *table, engine_table_doall_cb *cb,
void *arg)
{
ENGINE_PILE_DOALL dall;
dall.cb = cb;
dall.arg = arg;
if (table)
lh_ENGINE_PILE_doall_ENGINE_PILE_DOALL(&table->piles, int_dall, &dall);
}
