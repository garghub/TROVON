void lh_stats(LHASH *lh, FILE *out)
{
fprintf(out,"num_items = %lu\n",lh->num_items);
fprintf(out,"num_nodes = %u\n",lh->num_nodes);
fprintf(out,"num_alloc_nodes = %u\n",lh->num_alloc_nodes);
fprintf(out,"num_expands = %lu\n",lh->num_expands);
fprintf(out,"num_expand_reallocs = %lu\n",lh->num_expand_reallocs);
fprintf(out,"num_contracts = %lu\n",lh->num_contracts);
fprintf(out,"num_contract_reallocs = %lu\n",lh->num_contract_reallocs);
fprintf(out,"num_hash_calls = %lu\n",lh->num_hash_calls);
fprintf(out,"num_comp_calls = %lu\n",lh->num_comp_calls);
fprintf(out,"num_insert = %lu\n",lh->num_insert);
fprintf(out,"num_replace = %lu\n",lh->num_replace);
fprintf(out,"num_delete = %lu\n",lh->num_delete);
fprintf(out,"num_no_delete = %lu\n",lh->num_no_delete);
fprintf(out,"num_retrieve = %lu\n",lh->num_retrieve);
fprintf(out,"num_retrieve_miss = %lu\n",lh->num_retrieve_miss);
fprintf(out,"num_hash_comps = %lu\n",lh->num_hash_comps);
#ifdef DEBUG
fprintf(out,"p = %u\n",lh->p);
fprintf(out,"pmax = %u\n",lh->pmax);
fprintf(out,"up_load = %lu\n",lh->up_load);
fprintf(out,"down_load = %lu\n",lh->down_load);
#endif
}
void lh_node_stats(LHASH *lh, FILE *out)
{
LHASH_NODE *n;
unsigned int i,num;
for (i=0; i<lh->num_nodes; i++)
{
for (n=lh->b[i],num=0; n != NULL; n=n->next)
num++;
fprintf(out,"node %6u -> %3u\n",i,num);
}
}
void lh_node_usage_stats(LHASH *lh, FILE *out)
{
LHASH_NODE *n;
unsigned long num;
unsigned int i;
unsigned long total=0,n_used=0;
for (i=0; i<lh->num_nodes; i++)
{
for (n=lh->b[i],num=0; n != NULL; n=n->next)
num++;
if (num != 0)
{
n_used++;
total+=num;
}
}
fprintf(out,"%lu nodes used out of %u\n",n_used,lh->num_nodes);
fprintf(out,"%lu items\n",total);
if (n_used == 0) return;
fprintf(out,"load %d.%02d actual load %d.%02d\n",
(int)(total/lh->num_nodes),
(int)((total%lh->num_nodes)*100/lh->num_nodes),
(int)(total/n_used),
(int)((total%n_used)*100/n_used));
}
void lh_stats(LHASH *lh, FILE *fp)
{
BIO *bp;
bp=BIO_new(BIO_s_file());
if (bp == NULL) goto end;
BIO_set_fp(bp,fp,BIO_NOCLOSE);
lh_stats_bio(lh,bp);
BIO_free(bp);
end:;
}
void lh_node_stats(LHASH *lh, FILE *fp)
{
BIO *bp;
bp=BIO_new(BIO_s_file());
if (bp == NULL) goto end;
BIO_set_fp(bp,fp,BIO_NOCLOSE);
lh_node_stats_bio(lh,bp);
BIO_free(bp);
end:;
}
void lh_node_usage_stats(LHASH *lh, FILE *fp)
{
BIO *bp;
bp=BIO_new(BIO_s_file());
if (bp == NULL) goto end;
BIO_set_fp(bp,fp,BIO_NOCLOSE);
lh_node_usage_stats_bio(lh,bp);
BIO_free(bp);
end:;
}
void lh_stats_bio(LHASH *lh, BIO *out)
{
char buf[128];
sprintf(buf,"num_items = %lu\n",lh->num_items);
BIO_puts(out,buf);
sprintf(buf,"num_nodes = %u\n",lh->num_nodes);
BIO_puts(out,buf);
sprintf(buf,"num_alloc_nodes = %u\n",lh->num_alloc_nodes);
BIO_puts(out,buf);
sprintf(buf,"num_expands = %lu\n",lh->num_expands);
BIO_puts(out,buf);
sprintf(buf,"num_expand_reallocs = %lu\n",lh->num_expand_reallocs);
BIO_puts(out,buf);
sprintf(buf,"num_contracts = %lu\n",lh->num_contracts);
BIO_puts(out,buf);
sprintf(buf,"num_contract_reallocs = %lu\n",lh->num_contract_reallocs);
BIO_puts(out,buf);
sprintf(buf,"num_hash_calls = %lu\n",lh->num_hash_calls);
BIO_puts(out,buf);
sprintf(buf,"num_comp_calls = %lu\n",lh->num_comp_calls);
BIO_puts(out,buf);
sprintf(buf,"num_insert = %lu\n",lh->num_insert);
BIO_puts(out,buf);
sprintf(buf,"num_replace = %lu\n",lh->num_replace);
BIO_puts(out,buf);
sprintf(buf,"num_delete = %lu\n",lh->num_delete);
BIO_puts(out,buf);
sprintf(buf,"num_no_delete = %lu\n",lh->num_no_delete);
BIO_puts(out,buf);
sprintf(buf,"num_retrieve = %lu\n",lh->num_retrieve);
BIO_puts(out,buf);
sprintf(buf,"num_retrieve_miss = %lu\n",lh->num_retrieve_miss);
BIO_puts(out,buf);
sprintf(buf,"num_hash_comps = %lu\n",lh->num_hash_comps);
BIO_puts(out,buf);
#ifdef DEBUG
sprintf(buf,"p = %u\n",lh->p);
BIO_puts(out,buf);
sprintf(buf,"pmax = %u\n",lh->pmax);
BIO_puts(out,buf);
sprintf(buf,"up_load = %lu\n",lh->up_load);
BIO_puts(out,buf);
sprintf(buf,"down_load = %lu\n",lh->down_load);
BIO_puts(out,buf);
#endif
}
void lh_node_stats_bio(LHASH *lh, BIO *out)
{
LHASH_NODE *n;
unsigned int i,num;
char buf[128];
for (i=0; i<lh->num_nodes; i++)
{
for (n=lh->b[i],num=0; n != NULL; n=n->next)
num++;
sprintf(buf,"node %6u -> %3u\n",i,num);
BIO_puts(out,buf);
}
}
void lh_node_usage_stats_bio(LHASH *lh, BIO *out)
{
LHASH_NODE *n;
unsigned long num;
unsigned int i;
unsigned long total=0,n_used=0;
char buf[128];
for (i=0; i<lh->num_nodes; i++)
{
for (n=lh->b[i],num=0; n != NULL; n=n->next)
num++;
if (num != 0)
{
n_used++;
total+=num;
}
}
sprintf(buf,"%lu nodes used out of %u\n",n_used,lh->num_nodes);
BIO_puts(out,buf);
sprintf(buf,"%lu items\n",total);
BIO_puts(out,buf);
if (n_used == 0) return;
sprintf(buf,"load %d.%02d actual load %d.%02d\n",
(int)(total/lh->num_nodes),
(int)((total%lh->num_nodes)*100/lh->num_nodes),
(int)(total/n_used),
(int)((total%n_used)*100/n_used));
BIO_puts(out,buf);
}
