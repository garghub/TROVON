static void *fm10k_dbg_desc_seq_start(struct seq_file *s, loff_t *pos)
{
struct fm10k_ring *ring = s->private;
return (*pos < ring->count) ? pos : NULL;
}
static void *fm10k_dbg_desc_seq_next(struct seq_file *s,
void __always_unused *v, loff_t *pos)
{
struct fm10k_ring *ring = s->private;
return (++(*pos) < ring->count) ? pos : NULL;
}
static void fm10k_dbg_desc_seq_stop(struct seq_file __always_unused *s,
__always_unused void *v)
{
}
static void fm10k_dbg_desc_break(struct seq_file *s, int i)
{
while (i--)
seq_puts(s, "-");
seq_puts(s, "\n");
}
static int fm10k_dbg_tx_desc_seq_show(struct seq_file *s, void *v)
{
struct fm10k_ring *ring = s->private;
int i = *(loff_t *)v;
static const char tx_desc_hdr[] =
"DES BUFFER_ADDRESS LENGTH VLAN MSS HDRLEN FLAGS\n";
if (!i) {
seq_printf(s, tx_desc_hdr);
fm10k_dbg_desc_break(s, sizeof(tx_desc_hdr) - 1);
}
if (!ring->desc) {
seq_printf(s, "%03X Descriptor ring not allocated.\n", i);
} else {
struct fm10k_tx_desc *txd = FM10K_TX_DESC(ring, i);
seq_printf(s, "%03X %#018llx %#06x %#06x %#06x %#06x %#04x\n",
i, txd->buffer_addr, txd->buflen, txd->vlan,
txd->mss, txd->hdrlen, txd->flags);
}
return 0;
}
static int fm10k_dbg_rx_desc_seq_show(struct seq_file *s, void *v)
{
struct fm10k_ring *ring = s->private;
int i = *(loff_t *)v;
static const char rx_desc_hdr[] =
"DES DATA RSS STATERR LENGTH VLAN DGLORT SGLORT TIMESTAMP\n";
if (!i) {
seq_printf(s, rx_desc_hdr);
fm10k_dbg_desc_break(s, sizeof(rx_desc_hdr) - 1);
}
if (!ring->desc) {
seq_printf(s, "%03X Descriptor ring not allocated.\n", i);
} else {
union fm10k_rx_desc *rxd = FM10K_RX_DESC(ring, i);
seq_printf(s,
"%03X %#010x %#010x %#010x %#06x %#06x %#06x %#06x %#018llx\n",
i, rxd->d.data, rxd->d.rss, rxd->d.staterr,
rxd->w.length, rxd->w.vlan, rxd->w.dglort,
rxd->w.sglort, rxd->q.timestamp);
}
return 0;
}
static int fm10k_dbg_desc_open(struct inode *inode, struct file *filep)
{
struct fm10k_ring *ring = inode->i_private;
struct fm10k_q_vector *q_vector = ring->q_vector;
const struct seq_operations *desc_seq_ops;
int err;
if (ring < q_vector->rx.ring)
desc_seq_ops = &fm10k_dbg_tx_desc_seq_ops;
else
desc_seq_ops = &fm10k_dbg_rx_desc_seq_ops;
err = seq_open(filep, desc_seq_ops);
if (err)
return err;
((struct seq_file *)filep->private_data)->private = ring;
return 0;
}
void fm10k_dbg_q_vector_init(struct fm10k_q_vector *q_vector)
{
struct fm10k_intfc *interface = q_vector->interface;
char name[16];
int i;
if (!interface->dbg_intfc)
return;
sprintf(name, "q_vector.%03d", q_vector->v_idx);
q_vector->dbg_q_vector = debugfs_create_dir(name, interface->dbg_intfc);
if (!q_vector->dbg_q_vector)
return;
for (i = 0; i < q_vector->tx.count; i++) {
struct fm10k_ring *ring = &q_vector->tx.ring[i];
sprintf(name, "tx_ring.%03d", ring->queue_index);
debugfs_create_file(name, 0600,
q_vector->dbg_q_vector, ring,
&fm10k_dbg_desc_fops);
}
for (i = 0; i < q_vector->rx.count; i++) {
struct fm10k_ring *ring = &q_vector->rx.ring[i];
sprintf(name, "rx_ring.%03d", ring->queue_index);
debugfs_create_file(name, 0600,
q_vector->dbg_q_vector, ring,
&fm10k_dbg_desc_fops);
}
}
void fm10k_dbg_q_vector_exit(struct fm10k_q_vector *q_vector)
{
struct fm10k_intfc *interface = q_vector->interface;
if (interface->dbg_intfc)
debugfs_remove_recursive(q_vector->dbg_q_vector);
q_vector->dbg_q_vector = NULL;
}
void fm10k_dbg_intfc_init(struct fm10k_intfc *interface)
{
const char *name = pci_name(interface->pdev);
if (dbg_root)
interface->dbg_intfc = debugfs_create_dir(name, dbg_root);
}
void fm10k_dbg_intfc_exit(struct fm10k_intfc *interface)
{
if (dbg_root)
debugfs_remove_recursive(interface->dbg_intfc);
interface->dbg_intfc = NULL;
}
void fm10k_dbg_init(void)
{
dbg_root = debugfs_create_dir(fm10k_driver_name, NULL);
}
void fm10k_dbg_exit(void)
{
debugfs_remove_recursive(dbg_root);
dbg_root = NULL;
}
