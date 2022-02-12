void *kmalloc_kernel(size_t siz)
{
return kmalloc(siz, GFP_KERNEL | __GFP_NORETRY);
}
struct seq_file *visor_seq_file_new_buffer(void *buf, size_t buf_size)
{
struct seq_file *rc = NULL;
struct seq_file *m = kmalloc_kernel(sizeof(struct seq_file));
if (m == NULL) {
rc = NULL;
goto Away;
}
memset(m, 0, sizeof(struct seq_file));
m->buf = buf;
m->size = buf_size;
rc = m;
Away:
if (rc == NULL) {
visor_seq_file_done_buffer(m);
m = NULL;
}
return rc;
}
void visor_seq_file_done_buffer(struct seq_file *m)
{
if (!m)
return;
kfree(m);
}
static __init uint32_t
visorutil_spar_detect(void)
{
unsigned int eax, ebx, ecx, edx;
if (cpu_has_hypervisor) {
cpuid(UNISYS_SPAR_LEAF_ID, &eax, &ebx, &ecx, &edx);
return (ebx == UNISYS_SPAR_ID_EBX) &&
(ecx == UNISYS_SPAR_ID_ECX) &&
(edx == UNISYS_SPAR_ID_EDX);
} else
return 0;
}
static __init int
visorutil_mod_init(void)
{
if (visorutil_spar_detect()) {
unisys_spar_platform = TRUE;
return 0;
} else
return -ENODEV;
}
static __exit void
visorutil_mod_exit(void)
{
}
