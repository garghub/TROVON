static int nfsd_proc_show(struct seq_file *seq, void *v)
{
int i;
seq_printf(seq, "rc %u %u %u\nfh %u %u %u %u %u\nio %u %u\n",
nfsdstats.rchits,
nfsdstats.rcmisses,
nfsdstats.rcnocache,
nfsdstats.fh_stale,
nfsdstats.fh_lookup,
nfsdstats.fh_anon,
nfsdstats.fh_nocache_dir,
nfsdstats.fh_nocache_nondir,
nfsdstats.io_read,
nfsdstats.io_write);
seq_printf(seq, "th %u %u", nfsdstats.th_cnt, nfsdstats.th_fullcnt);
for (i=0; i<10; i++) {
unsigned int jifs = nfsdstats.th_usage[i];
unsigned int sec = jifs / HZ, msec = (jifs % HZ)*1000/HZ;
seq_printf(seq, " %u.%03u", sec, msec);
}
seq_printf(seq, "\nra %u", nfsdstats.ra_size);
for (i=0; i<11; i++)
seq_printf(seq, " %u", nfsdstats.ra_depth[i]);
seq_putc(seq, '\n');
svc_seq_show(seq, &nfsd_svcstats);
#ifdef CONFIG_NFSD_V4
seq_printf(seq,"proc4ops %u", LAST_NFS4_OP + 1);
for (i = 0; i <= LAST_NFS4_OP; i++)
seq_printf(seq, " %u", nfsdstats.nfs4_opcount[i]);
seq_putc(seq, '\n');
#endif
return 0;
}
static int nfsd_proc_open(struct inode *inode, struct file *file)
{
return single_open(file, nfsd_proc_show, NULL);
}
void
nfsd_stat_init(void)
{
svc_proc_register(&nfsd_svcstats, &nfsd_proc_fops);
}
void
nfsd_stat_shutdown(void)
{
svc_proc_unregister("nfsd");
}
