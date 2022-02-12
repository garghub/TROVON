struct io_pgtable_ops *alloc_io_pgtable_ops(enum io_pgtable_fmt fmt,
struct io_pgtable_cfg *cfg,
void *cookie)
{
struct io_pgtable *iop;
const struct io_pgtable_init_fns *fns;
if (fmt >= IO_PGTABLE_NUM_FMTS)
return NULL;
fns = io_pgtable_init_table[fmt];
if (!fns)
return NULL;
iop = fns->alloc(cfg, cookie);
if (!iop)
return NULL;
iop->fmt = fmt;
iop->cookie = cookie;
iop->cfg = *cfg;
return &iop->ops;
}
void free_io_pgtable_ops(struct io_pgtable_ops *ops)
{
struct io_pgtable *iop;
if (!ops)
return;
iop = container_of(ops, struct io_pgtable, ops);
iop->cfg.tlb->tlb_flush_all(iop->cookie);
io_pgtable_init_table[iop->fmt]->free(iop);
}
