static inline void ehci_qtd_init(struct ehci_hcd *ehci, struct ehci_qtd *qtd,
dma_addr_t dma)
{
memset (qtd, 0, sizeof *qtd);
qtd->qtd_dma = dma;
qtd->hw_token = cpu_to_hc32(ehci, QTD_STS_HALT);
qtd->hw_next = EHCI_LIST_END(ehci);
qtd->hw_alt_next = EHCI_LIST_END(ehci);
INIT_LIST_HEAD (&qtd->qtd_list);
}
static struct ehci_qtd *ehci_qtd_alloc (struct ehci_hcd *ehci, gfp_t flags)
{
struct ehci_qtd *qtd;
dma_addr_t dma;
qtd = dma_pool_alloc (ehci->qtd_pool, flags, &dma);
if (qtd != NULL) {
ehci_qtd_init(ehci, qtd, dma);
}
return qtd;
}
static inline void ehci_qtd_free (struct ehci_hcd *ehci, struct ehci_qtd *qtd)
{
dma_pool_free (ehci->qtd_pool, qtd, qtd->qtd_dma);
}
static void qh_destroy(struct ehci_qh *qh)
{
struct ehci_hcd *ehci = qh->ehci;
if (!list_empty (&qh->qtd_list) || qh->qh_next.ptr) {
ehci_dbg (ehci, "unused qh not empty!\n");
BUG ();
}
if (qh->dummy)
ehci_qtd_free (ehci, qh->dummy);
dma_pool_free(ehci->qh_pool, qh->hw, qh->qh_dma);
kfree(qh);
}
static struct ehci_qh *ehci_qh_alloc (struct ehci_hcd *ehci, gfp_t flags)
{
struct ehci_qh *qh;
dma_addr_t dma;
qh = kzalloc(sizeof *qh, GFP_ATOMIC);
if (!qh)
goto done;
qh->hw = (struct ehci_qh_hw *)
dma_pool_alloc(ehci->qh_pool, flags, &dma);
if (!qh->hw)
goto fail;
memset(qh->hw, 0, sizeof *qh->hw);
qh->refcount = 1;
qh->ehci = ehci;
qh->qh_dma = dma;
INIT_LIST_HEAD (&qh->qtd_list);
qh->dummy = ehci_qtd_alloc (ehci, flags);
if (qh->dummy == NULL) {
ehci_dbg (ehci, "no dummy td\n");
goto fail1;
}
done:
return qh;
fail1:
dma_pool_free(ehci->qh_pool, qh->hw, qh->qh_dma);
fail:
kfree(qh);
return NULL;
}
static inline struct ehci_qh *qh_get (struct ehci_qh *qh)
{
WARN_ON(!qh->refcount);
qh->refcount++;
return qh;
}
static inline void qh_put (struct ehci_qh *qh)
{
if (!--qh->refcount)
qh_destroy(qh);
}
static void ehci_mem_cleanup (struct ehci_hcd *ehci)
{
free_cached_lists(ehci);
if (ehci->async)
qh_put (ehci->async);
ehci->async = NULL;
if (ehci->dummy)
qh_put(ehci->dummy);
ehci->dummy = NULL;
if (ehci->qtd_pool)
dma_pool_destroy (ehci->qtd_pool);
ehci->qtd_pool = NULL;
if (ehci->qh_pool) {
dma_pool_destroy (ehci->qh_pool);
ehci->qh_pool = NULL;
}
if (ehci->itd_pool)
dma_pool_destroy (ehci->itd_pool);
ehci->itd_pool = NULL;
if (ehci->sitd_pool)
dma_pool_destroy (ehci->sitd_pool);
ehci->sitd_pool = NULL;
if (ehci->periodic)
dma_free_coherent (ehci_to_hcd(ehci)->self.controller,
ehci->periodic_size * sizeof (u32),
ehci->periodic, ehci->periodic_dma);
ehci->periodic = NULL;
kfree(ehci->pshadow);
ehci->pshadow = NULL;
}
static int ehci_mem_init (struct ehci_hcd *ehci, gfp_t flags)
{
int i;
ehci->qtd_pool = dma_pool_create ("ehci_qtd",
ehci_to_hcd(ehci)->self.controller,
sizeof (struct ehci_qtd),
32 ,
4096 );
if (!ehci->qtd_pool) {
goto fail;
}
ehci->qh_pool = dma_pool_create ("ehci_qh",
ehci_to_hcd(ehci)->self.controller,
sizeof(struct ehci_qh_hw),
32 ,
4096 );
if (!ehci->qh_pool) {
goto fail;
}
ehci->async = ehci_qh_alloc (ehci, flags);
if (!ehci->async) {
goto fail;
}
ehci->itd_pool = dma_pool_create ("ehci_itd",
ehci_to_hcd(ehci)->self.controller,
sizeof (struct ehci_itd),
32 ,
4096 );
if (!ehci->itd_pool) {
goto fail;
}
ehci->sitd_pool = dma_pool_create ("ehci_sitd",
ehci_to_hcd(ehci)->self.controller,
sizeof (struct ehci_sitd),
32 ,
4096 );
if (!ehci->sitd_pool) {
goto fail;
}
ehci->periodic = (__le32 *)
dma_alloc_coherent (ehci_to_hcd(ehci)->self.controller,
ehci->periodic_size * sizeof(__le32),
&ehci->periodic_dma, 0);
if (ehci->periodic == NULL) {
goto fail;
}
if (ehci->use_dummy_qh) {
struct ehci_qh_hw *hw;
ehci->dummy = ehci_qh_alloc(ehci, flags);
if (!ehci->dummy)
goto fail;
hw = ehci->dummy->hw;
hw->hw_next = EHCI_LIST_END(ehci);
hw->hw_qtd_next = EHCI_LIST_END(ehci);
hw->hw_alt_next = EHCI_LIST_END(ehci);
hw->hw_token &= ~QTD_STS_ACTIVE;
ehci->dummy->hw = hw;
for (i = 0; i < ehci->periodic_size; i++)
ehci->periodic[i] = ehci->dummy->qh_dma;
} else {
for (i = 0; i < ehci->periodic_size; i++)
ehci->periodic[i] = EHCI_LIST_END(ehci);
}
ehci->pshadow = kcalloc(ehci->periodic_size, sizeof(void *), flags);
if (ehci->pshadow != NULL)
return 0;
fail:
ehci_dbg (ehci, "couldn't init memory\n");
ehci_mem_cleanup (ehci);
return -ENOMEM;
}
