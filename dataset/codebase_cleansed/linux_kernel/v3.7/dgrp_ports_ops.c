void dgrp_register_ports_hook(struct proc_dir_entry *de)
{
struct nd_struct *node = de->data;
de->proc_iops = &ports_inode_ops;
de->proc_fops = &ports_ops;
node->nd_ports_de = de;
}
static void *dgrp_ports_seq_start(struct seq_file *seq, loff_t *pos)
{
if (*pos == 0)
seq_puts(seq, "#num tty_open pr_open tot_wait MSTAT IFLAG OFLAG CFLAG BPS DIGIFLAGS\n");
return pos;
}
static void *dgrp_ports_seq_next(struct seq_file *seq, void *v, loff_t *pos)
{
struct nd_struct *nd = seq->private;
if (*pos >= nd->nd_chan_count)
return NULL;
*pos += 1;
return pos;
}
static void dgrp_ports_seq_stop(struct seq_file *seq, void *v)
{
}
static int dgrp_ports_seq_show(struct seq_file *seq, void *v)
{
loff_t *pos = v;
struct nd_struct *nd;
struct ch_struct *ch;
struct un_struct *tun, *pun;
unsigned int totcnt;
nd = seq->private;
if (!nd)
return 0;
if (*pos >= nd->nd_chan_count)
return 0;
ch = &nd->nd_chan[*pos];
tun = &ch->ch_tun;
pun = &ch->ch_pun;
totcnt = tun->un_open_count +
pun->un_open_count +
ch->ch_wait_count[0] +
ch->ch_wait_count[1] +
ch->ch_wait_count[2];
seq_printf(seq, "%02d %02d %02d %02d 0x%04X 0x%04X 0x%04X 0x%04X %-6d 0x%04X\n",
(int) *pos,
tun->un_open_count,
pun->un_open_count,
ch->ch_wait_count[0] +
ch->ch_wait_count[1] +
ch->ch_wait_count[2],
(totcnt ? ch->ch_s_mlast : 0),
ch->ch_s_iflag,
ch->ch_s_oflag,
ch->ch_s_cflag,
(ch->ch_s_brate ? (1843200 / ch->ch_s_brate) : 0),
ch->ch_digi.digi_flags);
return 0;
}
static int dgrp_ports_open(struct inode *inode, struct file *file)
{
struct seq_file *seq;
int rtn;
rtn = seq_open(file, &ports_seq_ops);
if (!rtn) {
seq = file->private_data;
seq->private = PDE(inode)->data;
}
return rtn;
}
