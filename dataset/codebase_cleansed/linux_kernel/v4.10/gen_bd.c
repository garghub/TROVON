struct bcom_task *
bcom_gen_bd_rx_init(int queue_len, phys_addr_t fifo,
int initiator, int ipr, int maxbufsize)
{
struct bcom_task *tsk;
struct bcom_gen_bd_priv *priv;
tsk = bcom_task_alloc(queue_len, sizeof(struct bcom_gen_bd),
sizeof(struct bcom_gen_bd_priv));
if (!tsk)
return NULL;
tsk->flags = BCOM_FLAGS_NONE;
priv = tsk->priv;
priv->fifo = fifo;
priv->initiator = initiator;
priv->ipr = ipr;
priv->maxbufsize = maxbufsize;
if (bcom_gen_bd_rx_reset(tsk)) {
bcom_task_free(tsk);
return NULL;
}
return tsk;
}
int
bcom_gen_bd_rx_reset(struct bcom_task *tsk)
{
struct bcom_gen_bd_priv *priv = tsk->priv;
struct bcom_gen_bd_rx_var *var;
struct bcom_gen_bd_rx_inc *inc;
bcom_disable_task(tsk->tasknum);
var = (struct bcom_gen_bd_rx_var *) bcom_task_var(tsk->tasknum);
inc = (struct bcom_gen_bd_rx_inc *) bcom_task_inc(tsk->tasknum);
if (bcom_load_image(tsk->tasknum, bcom_gen_bd_rx_task))
return -1;
var->enable = bcom_eng->regs_base +
offsetof(struct mpc52xx_sdma, tcr[tsk->tasknum]);
var->fifo = (u32) priv->fifo;
var->bd_base = tsk->bd_pa;
var->bd_last = tsk->bd_pa + ((tsk->num_bd-1) * tsk->bd_size);
var->bd_start = tsk->bd_pa;
var->buffer_size = priv->maxbufsize;
inc->incr_bytes = -(s16)sizeof(u32);
inc->incr_dst = sizeof(u32);
tsk->index = 0;
tsk->outdex = 0;
memset(tsk->bd, 0x00, tsk->num_bd * tsk->bd_size);
bcom_set_task_pragma(tsk->tasknum, BCOM_GEN_RX_BD_PRAGMA);
bcom_set_task_auto_start(tsk->tasknum, tsk->tasknum);
out_8(&bcom_eng->regs->ipr[priv->initiator], priv->ipr);
bcom_set_initiator(tsk->tasknum, priv->initiator);
out_be32(&bcom_eng->regs->IntPend, 1<<tsk->tasknum);
return 0;
}
void
bcom_gen_bd_rx_release(struct bcom_task *tsk)
{
bcom_task_free(tsk);
}
extern struct bcom_task *
bcom_gen_bd_tx_init(int queue_len, phys_addr_t fifo,
int initiator, int ipr)
{
struct bcom_task *tsk;
struct bcom_gen_bd_priv *priv;
tsk = bcom_task_alloc(queue_len, sizeof(struct bcom_gen_bd),
sizeof(struct bcom_gen_bd_priv));
if (!tsk)
return NULL;
tsk->flags = BCOM_FLAGS_NONE;
priv = tsk->priv;
priv->fifo = fifo;
priv->initiator = initiator;
priv->ipr = ipr;
if (bcom_gen_bd_tx_reset(tsk)) {
bcom_task_free(tsk);
return NULL;
}
return tsk;
}
int
bcom_gen_bd_tx_reset(struct bcom_task *tsk)
{
struct bcom_gen_bd_priv *priv = tsk->priv;
struct bcom_gen_bd_tx_var *var;
struct bcom_gen_bd_tx_inc *inc;
bcom_disable_task(tsk->tasknum);
var = (struct bcom_gen_bd_tx_var *) bcom_task_var(tsk->tasknum);
inc = (struct bcom_gen_bd_tx_inc *) bcom_task_inc(tsk->tasknum);
if (bcom_load_image(tsk->tasknum, bcom_gen_bd_tx_task))
return -1;
var->enable = bcom_eng->regs_base +
offsetof(struct mpc52xx_sdma, tcr[tsk->tasknum]);
var->fifo = (u32) priv->fifo;
var->bd_base = tsk->bd_pa;
var->bd_last = tsk->bd_pa + ((tsk->num_bd-1) * tsk->bd_size);
var->bd_start = tsk->bd_pa;
inc->incr_bytes = -(s16)sizeof(u32);
inc->incr_src = sizeof(u32);
inc->incr_src_ma = sizeof(u8);
tsk->index = 0;
tsk->outdex = 0;
memset(tsk->bd, 0x00, tsk->num_bd * tsk->bd_size);
bcom_set_task_pragma(tsk->tasknum, BCOM_GEN_TX_BD_PRAGMA);
bcom_set_task_auto_start(tsk->tasknum, tsk->tasknum);
out_8(&bcom_eng->regs->ipr[priv->initiator], priv->ipr);
bcom_set_initiator(tsk->tasknum, priv->initiator);
out_be32(&bcom_eng->regs->IntPend, 1<<tsk->tasknum);
return 0;
}
void
bcom_gen_bd_tx_release(struct bcom_task *tsk)
{
bcom_task_free(tsk);
}
struct bcom_task * bcom_psc_gen_bd_rx_init(unsigned psc_num, int queue_len,
phys_addr_t fifo, int maxbufsize)
{
if (psc_num >= MPC52xx_PSC_MAXNUM)
return NULL;
return bcom_gen_bd_rx_init(queue_len, fifo,
bcom_psc_params[psc_num].rx_initiator,
bcom_psc_params[psc_num].rx_ipr,
maxbufsize);
}
struct bcom_task *
bcom_psc_gen_bd_tx_init(unsigned psc_num, int queue_len, phys_addr_t fifo)
{
struct psc;
return bcom_gen_bd_tx_init(queue_len, fifo,
bcom_psc_params[psc_num].tx_initiator,
bcom_psc_params[psc_num].tx_ipr);
}
