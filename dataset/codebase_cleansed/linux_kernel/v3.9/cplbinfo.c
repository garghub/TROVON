static void cplbinfo_print_header(struct seq_file *m)
{
seq_printf(m, "Index\tAddress\t\tData\tSize\tU/RD\tU/WR\tS/WR\tSwitch\n");
}
static int cplbinfo_nomore(struct cplbinfo_data *cdata)
{
return cdata->pos >= MAX_CPLBS;
}
static int cplbinfo_show(struct seq_file *m, void *p)
{
struct cplbinfo_data *cdata;
unsigned long data, addr;
loff_t pos;
cdata = p;
pos = cdata->pos;
addr = cdata->tbl[pos].addr;
data = cdata->tbl[pos].data;
seq_printf(m,
"%d\t0x%08lx\t%05lx\t%s\t%c\t%c\t%c\t%c\n",
(int)pos, addr, data, strpage(data),
(data & CPLB_USER_RD) ? 'Y' : 'N',
(data & CPLB_USER_WR) ? 'Y' : 'N',
(data & CPLB_SUPV_WR) ? 'Y' : 'N',
pos < cdata->switched ? 'N' : 'Y');
return 0;
}
static void cplbinfo_seq_init(struct cplbinfo_data *cdata, unsigned int cpu)
{
if (cdata->cplb_type == 'I') {
cdata->mem_control = bfin_read_IMEM_CONTROL();
cdata->tbl = icplb_tbl[cpu];
cdata->switched = first_switched_icplb;
} else {
cdata->mem_control = bfin_read_DMEM_CONTROL();
cdata->tbl = dcplb_tbl[cpu];
cdata->switched = first_switched_dcplb;
}
}
static void *cplbinfo_start(struct seq_file *m, loff_t *pos)
{
struct cplbinfo_data *cdata = m->private;
if (!*pos) {
seq_printf(m, "%cCPLBs are %sabled: 0x%x\n", cdata->cplb_type,
(cdata->mem_control & ENDCPLB ? "en" : "dis"),
cdata->mem_control);
cplbinfo_print_header(m);
} else if (cplbinfo_nomore(cdata))
return NULL;
get_cpu();
return cdata;
}
static void *cplbinfo_next(struct seq_file *m, void *p, loff_t *pos)
{
struct cplbinfo_data *cdata = p;
cdata->pos = ++(*pos);
if (cplbinfo_nomore(cdata))
return NULL;
else
return cdata;
}
static void cplbinfo_stop(struct seq_file *m, void *p)
{
put_cpu();
}
static int cplbinfo_open(struct inode *inode, struct file *file)
{
struct proc_dir_entry *pde = PDE(file_inode(file));
char cplb_type;
unsigned int cpu;
int ret;
struct seq_file *m;
struct cplbinfo_data *cdata;
cpu = (unsigned int)pde->data;
cplb_type = cpu & CPLBINFO_DCPLB_FLAG ? 'D' : 'I';
cpu &= ~CPLBINFO_DCPLB_FLAG;
if (!cpu_online(cpu))
return -ENODEV;
ret = seq_open_private(file, &cplbinfo_sops, sizeof(*cdata));
if (ret)
return ret;
m = file->private_data;
cdata = m->private;
cdata->pos = 0;
cdata->cplb_type = cplb_type;
cplbinfo_seq_init(cdata, cpu);
return 0;
}
static int __init cplbinfo_init(void)
{
struct proc_dir_entry *cplb_dir, *cpu_dir;
char buf[10];
unsigned int cpu;
cplb_dir = proc_mkdir("cplbinfo", NULL);
if (!cplb_dir)
return -ENOMEM;
for_each_possible_cpu(cpu) {
sprintf(buf, "cpu%i", cpu);
cpu_dir = proc_mkdir(buf, cplb_dir);
if (!cpu_dir)
return -ENOMEM;
proc_create_data("icplb", S_IRUGO, cpu_dir, &cplbinfo_fops,
(void *)cpu);
proc_create_data("dcplb", S_IRUGO, cpu_dir, &cplbinfo_fops,
(void *)(cpu | CPLBINFO_DCPLB_FLAG));
}
return 0;
}
