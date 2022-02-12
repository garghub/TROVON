static bool iov_empty(const struct iovec iov[], unsigned int num_iov)
{
unsigned int i;
for (i = 0; i < num_iov; i++)
if (iov[i].iov_len)
return false;
return true;
}
static void iov_consume(struct device *d,
struct iovec iov[], unsigned num_iov,
void *dest, unsigned len)
{
unsigned int i;
for (i = 0; i < num_iov; i++) {
unsigned int used;
used = iov[i].iov_len < len ? iov[i].iov_len : len;
if (dest) {
memcpy(dest, iov[i].iov_base, used);
dest += used;
}
iov[i].iov_base += used;
iov[i].iov_len -= used;
len -= used;
}
if (len != 0)
bad_driver(d, "iovec too short!");
}
static void *from_guest_phys(unsigned long addr)
{
return guest_base + addr;
}
static unsigned long to_guest_phys(const void *addr)
{
return (addr - guest_base);
}
static int open_or_die(const char *name, int flags)
{
int fd = open(name, flags);
if (fd < 0)
err(1, "Failed to open %s", name);
return fd;
}
static void *map_zeroed_pages(unsigned int num)
{
int fd = open_or_die("/dev/zero", O_RDONLY);
void *addr;
addr = mmap(NULL, getpagesize() * (num+2),
PROT_NONE, MAP_PRIVATE, fd, 0);
if (addr == MAP_FAILED)
err(1, "Mmapping %u pages of /dev/zero", num);
if (mprotect(addr + getpagesize(), getpagesize() * num,
PROT_READ|PROT_WRITE) == -1)
err(1, "mprotect rw %u pages failed", num);
close(fd);
return addr + getpagesize();
}
static unsigned long get_mmio_region(size_t size)
{
unsigned long addr = guest_mmio;
size_t i;
if (!size)
return addr;
for (i = 1; i < size; i <<= 1);
guest_mmio += i;
return addr;
}
static void map_at(int fd, void *addr, unsigned long offset, unsigned long len)
{
ssize_t r;
if (mmap(addr, len, PROT_READ|PROT_WRITE,
MAP_FIXED|MAP_PRIVATE, fd, offset) != MAP_FAILED)
return;
r = pread(fd, addr, len, offset);
if (r != len)
err(1, "Reading offset %lu len %lu gave %zi", offset, len, r);
}
static unsigned long map_elf(int elf_fd, const Elf32_Ehdr *ehdr)
{
Elf32_Phdr phdr[ehdr->e_phnum];
unsigned int i;
if (ehdr->e_type != ET_EXEC
|| ehdr->e_machine != EM_386
|| ehdr->e_phentsize != sizeof(Elf32_Phdr)
|| ehdr->e_phnum < 1 || ehdr->e_phnum > 65536U/sizeof(Elf32_Phdr))
errx(1, "Malformed elf header");
if (lseek(elf_fd, ehdr->e_phoff, SEEK_SET) < 0)
err(1, "Seeking to program headers");
if (read(elf_fd, phdr, sizeof(phdr)) != sizeof(phdr))
err(1, "Reading program headers");
for (i = 0; i < ehdr->e_phnum; i++) {
if (phdr[i].p_type != PT_LOAD)
continue;
verbose("Section %i: size %i addr %p\n",
i, phdr[i].p_memsz, (void *)phdr[i].p_paddr);
map_at(elf_fd, from_guest_phys(phdr[i].p_paddr),
phdr[i].p_offset, phdr[i].p_filesz);
}
return ehdr->e_entry;
}
static unsigned long load_bzimage(int fd)
{
struct boot_params boot;
int r;
void *p = from_guest_phys(0x100000);
lseek(fd, 0, SEEK_SET);
read(fd, &boot, sizeof(boot));
if (memcmp(&boot.hdr.header, "HdrS", 4) != 0)
errx(1, "This doesn't look like a bzImage to me");
lseek(fd, (boot.hdr.setup_sects+1) * 512, SEEK_SET);
while ((r = read(fd, p, 65536)) > 0)
p += r;
return boot.hdr.code32_start;
}
static unsigned long load_kernel(int fd)
{
Elf32_Ehdr hdr;
if (read(fd, &hdr, sizeof(hdr)) != sizeof(hdr))
err(1, "Reading kernel");
if (memcmp(hdr.e_ident, ELFMAG, SELFMAG) == 0)
return map_elf(fd, &hdr);
return load_bzimage(fd);
}
static inline unsigned long page_align(unsigned long addr)
{
return ((addr + getpagesize()-1) & ~(getpagesize()-1));
}
static unsigned long load_initrd(const char *name, unsigned long mem)
{
int ifd;
struct stat st;
unsigned long len;
ifd = open_or_die(name, O_RDONLY);
if (fstat(ifd, &st) < 0)
err(1, "fstat() on initrd '%s'", name);
len = page_align(st.st_size);
map_at(ifd, from_guest_phys(mem - len), 0, st.st_size);
close(ifd);
verbose("mapped initrd %s size=%lu @ %p\n", name, len, (void*)mem-len);
return len;
}
static void concat(char *dst, char *args[])
{
unsigned int i, len = 0;
for (i = 0; args[i]; i++) {
if (i) {
strcat(dst+len, " ");
len++;
}
strcpy(dst+len, args[i]);
len += strlen(args[i]);
}
dst[len] = '\0';
}
static void tell_kernel(unsigned long start)
{
unsigned long args[] = { LHREQ_INITIALIZE,
(unsigned long)guest_base,
guest_limit / getpagesize(), start,
(guest_mmio+getpagesize()-1) / getpagesize() };
verbose("Guest: %p - %p (%#lx, MMIO %#lx)\n",
guest_base, guest_base + guest_limit,
guest_limit, guest_mmio);
lguest_fd = open_or_die("/dev/lguest", O_RDWR);
if (write(lguest_fd, args, sizeof(args)) < 0)
err(1, "Writing to /dev/lguest");
}
static void *_check_pointer(struct device *d,
unsigned long addr, unsigned int size,
unsigned int line)
{
if ((addr + size) > guest_limit || (addr + size) < addr)
bad_driver(d, "%s:%i: Invalid address %#lx",
__FILE__, line, addr);
return from_guest_phys(addr);
}
static unsigned next_desc(struct device *d, struct vring_desc *desc,
unsigned int i, unsigned int max)
{
unsigned int next;
if (!(desc[i].flags & VRING_DESC_F_NEXT))
return max;
next = desc[i].next;
wmb();
if (next >= max)
bad_driver(d, "Desc next is %u", next);
return next;
}
static void trigger_irq(struct virtqueue *vq)
{
unsigned long buf[] = { LHREQ_IRQ, vq->dev->config.irq_line };
if (!vq->pending_used)
return;
vq->pending_used = 0;
if (vq->vring.avail->flags > 1)
bad_driver_vq(vq, "avail->flags = %u\n", vq->vring.avail->flags);
if (vq->vring.avail->flags & VRING_AVAIL_F_NO_INTERRUPT) {
return;
}
vq->dev->mmio->isr = 0x1;
if (write(lguest_fd, buf, sizeof(buf)) != 0)
err(1, "Triggering irq %i", vq->dev->config.irq_line);
}
static unsigned wait_for_vq_desc(struct virtqueue *vq,
struct iovec iov[],
unsigned int *out_num, unsigned int *in_num)
{
unsigned int i, head, max;
struct vring_desc *desc;
u16 last_avail = lg_last_avail(vq);
while (last_avail == vq->vring.avail->idx) {
u64 event;
trigger_irq(vq);
vq->vring.used->flags &= ~VRING_USED_F_NO_NOTIFY;
mb();
if (last_avail != vq->vring.avail->idx) {
vq->vring.used->flags |= VRING_USED_F_NO_NOTIFY;
break;
}
if (read(vq->eventfd, &event, sizeof(event)) != sizeof(event))
errx(1, "Event read failed?");
vq->vring.used->flags |= VRING_USED_F_NO_NOTIFY;
}
if ((u16)(vq->vring.avail->idx - last_avail) > vq->vring.num)
bad_driver_vq(vq, "Guest moved used index from %u to %u",
last_avail, vq->vring.avail->idx);
rmb();
head = vq->vring.avail->ring[last_avail % vq->vring.num];
lg_last_avail(vq)++;
if (head >= vq->vring.num)
bad_driver_vq(vq, "Guest says index %u is available", head);
*out_num = *in_num = 0;
max = vq->vring.num;
desc = vq->vring.desc;
i = head;
do {
if (desc[i].flags & VRING_DESC_F_INDIRECT) {
if (!(vq->dev->features_accepted &
(1<<VIRTIO_RING_F_INDIRECT_DESC)))
bad_driver_vq(vq, "vq indirect not negotiated");
if (desc != vq->vring.desc)
bad_driver_vq(vq, "Indirect within indirect");
if (desc[i].flags & VRING_DESC_F_NEXT)
bad_driver_vq(vq, "indirect and next together");
if (desc[i].len % sizeof(struct vring_desc))
bad_driver_vq(vq,
"Invalid size for indirect table");
max = desc[i].len / sizeof(struct vring_desc);
desc = check_pointer(vq->dev, desc[i].addr, desc[i].len);
i = 0;
if (max > vq->pci_config.queue_size)
bad_driver_vq(vq,
"indirect has too many entries");
}
iov[*out_num + *in_num].iov_len = desc[i].len;
iov[*out_num + *in_num].iov_base
= check_pointer(vq->dev, desc[i].addr, desc[i].len);
if (desc[i].flags & VRING_DESC_F_WRITE)
(*in_num)++;
else {
if (*in_num)
bad_driver_vq(vq,
"Descriptor has out after in");
(*out_num)++;
}
if (*out_num + *in_num > max)
bad_driver_vq(vq, "Looped descriptor");
} while ((i = next_desc(vq->dev, desc, i, max)) != max);
return head;
}
static void add_used(struct virtqueue *vq, unsigned int head, int len)
{
struct vring_used_elem *used;
used = &vq->vring.used->ring[vq->vring.used->idx % vq->vring.num];
used->id = head;
used->len = len;
wmb();
vq->vring.used->idx++;
vq->pending_used++;
}
static void add_used_and_trigger(struct virtqueue *vq, unsigned head, int len)
{
add_used(vq, head, len);
trigger_irq(vq);
}
static void console_input(struct virtqueue *vq)
{
int len;
unsigned int head, in_num, out_num;
struct console_abort *abort = vq->dev->priv;
struct iovec iov[vq->vring.num];
head = wait_for_vq_desc(vq, iov, &out_num, &in_num);
if (out_num)
bad_driver_vq(vq, "Output buffers in console in queue?");
len = readv(STDIN_FILENO, iov, in_num);
if (len <= 0) {
warnx("Failed to get console input, ignoring console.");
for (;;)
pause();
}
add_used_and_trigger(vq, head, len);
if (len != 1 || ((char *)iov[0].iov_base)[0] != 3) {
abort->count = 0;
return;
}
abort->count++;
if (abort->count == 1)
gettimeofday(&abort->start, NULL);
else if (abort->count == 3) {
struct timeval now;
gettimeofday(&now, NULL);
if (now.tv_sec <= abort->start.tv_sec+1)
kill(0, SIGINT);
abort->count = 0;
}
}
static void console_output(struct virtqueue *vq)
{
unsigned int head, out, in;
struct iovec iov[vq->vring.num];
head = wait_for_vq_desc(vq, iov, &out, &in);
if (in)
bad_driver_vq(vq, "Input buffers in console output queue?");
while (!iov_empty(iov, out)) {
int len = writev(STDOUT_FILENO, iov, out);
if (len <= 0) {
warn("Write to stdout gave %i (%d)", len, errno);
break;
}
iov_consume(vq->dev, iov, out, NULL, len);
}
add_used(vq, head, 0);
}
static void net_output(struct virtqueue *vq)
{
struct net_info *net_info = vq->dev->priv;
unsigned int head, out, in;
struct iovec iov[vq->vring.num];
head = wait_for_vq_desc(vq, iov, &out, &in);
if (in)
bad_driver_vq(vq, "Input buffers in net output queue?");
if (writev(net_info->tunfd, iov, out) < 0)
warnx("Write to tun failed (%d)?", errno);
add_used(vq, head, 0);
}
static bool will_block(int fd)
{
fd_set fdset;
struct timeval zero = { 0, 0 };
FD_ZERO(&fdset);
FD_SET(fd, &fdset);
return select(fd+1, &fdset, NULL, NULL, &zero) != 1;
}
static void net_input(struct virtqueue *vq)
{
int len;
unsigned int head, out, in;
struct iovec iov[vq->vring.num];
struct net_info *net_info = vq->dev->priv;
head = wait_for_vq_desc(vq, iov, &out, &in);
if (out)
bad_driver_vq(vq, "Output buffers in net input queue?");
if (vq->pending_used && will_block(net_info->tunfd))
trigger_irq(vq);
len = readv(net_info->tunfd, iov, in);
if (len <= 0)
warn("Failed to read from tun (%d).", errno);
add_used(vq, head, len);
}
static int do_thread(void *_vq)
{
struct virtqueue *vq = _vq;
for (;;)
vq->service(vq);
return 0;
}
static void kill_launcher(int signal)
{
kill(0, SIGTERM);
}
static void reset_vq_pci_config(struct virtqueue *vq)
{
vq->pci_config.queue_size = VIRTQUEUE_NUM;
vq->pci_config.queue_enable = 0;
}
static void reset_device(struct device *dev)
{
struct virtqueue *vq;
verbose("Resetting device %s\n", dev->name);
dev->features_accepted = 0;
signal(SIGCHLD, SIG_IGN);
dev->mmio->cfg.queue_enable = 0;
for (vq = dev->vq; vq; vq = vq->next) {
vq->last_avail_idx = 0;
reset_vq_pci_config(vq);
if (vq->thread != (pid_t)-1) {
kill(vq->thread, SIGTERM);
waitpid(vq->thread, NULL, 0);
vq->thread = (pid_t)-1;
}
}
dev->running = false;
dev->wrote_features_ok = false;
signal(SIGCHLD, (void *)kill_launcher);
}
static void cleanup_devices(void)
{
unsigned int i;
for (i = 1; i < MAX_PCI_DEVICES; i++) {
struct device *d = devices.pci[i];
if (!d)
continue;
reset_device(d);
}
if (orig_term.c_lflag & (ISIG|ICANON|ECHO))
tcsetattr(STDIN_FILENO, TCSANOW, &orig_term);
}
static void init_pci_host_bridge(void)
{
pci_host_bridge.name = "PCI Host Bridge";
pci_host_bridge.config.class = 0x06;
pci_host_bridge.config.subclass = 0;
devices.pci[0] = &pci_host_bridge;
}
static struct device *find_pci_device(unsigned int index)
{
return devices.pci[index];
}
static void ioread(u16 off, u32 v, u32 mask, u32 *val)
{
assert(off < 4);
assert(mask == 0xFF || mask == 0xFFFF || mask == 0xFFFFFFFF);
*val = (v >> (off * 8)) & mask;
}
static void iowrite(u16 off, u32 v, u32 mask, u32 *dst)
{
assert(off < 4);
assert(mask == 0xFF || mask == 0xFFFF || mask == 0xFFFFFFFF);
*dst &= ~(mask << (off * 8));
*dst |= (v & mask) << (off * 8);
}
static struct device *dev_and_reg(u32 *reg)
{
if (!pci_config_addr.bits.enabled)
return NULL;
if (pci_config_addr.bits.funcnum != 0)
return NULL;
if (pci_config_addr.bits.busnum != 0)
return NULL;
if (pci_config_addr.bits.offset * 4 >= sizeof(struct pci_config))
return NULL;
*reg = pci_config_addr.bits.offset;
return find_pci_device(pci_config_addr.bits.devnum);
}
static bool valid_bar_access(struct device *d,
struct virtio_pci_cfg_cap_u32 *cfg_access)
{
if (cfg_access->cap.bar != 0)
return false;
if (cfg_access->cap.offset >= d->mmio_size
|| cfg_access->cap.offset + cfg_access->cap.length > d->mmio_size)
return false;
if (cfg_access->cap.length != 1
&& cfg_access->cap.length != 2
&& cfg_access->cap.length != 4)
return false;
if (cfg_access->cap.offset % cfg_access->cap.length != 0)
return false;
return true;
}
static bool is_pci_addr_port(u16 port)
{
return port >= PCI_CONFIG_ADDR && port < PCI_CONFIG_ADDR + 4;
}
static bool pci_addr_iowrite(u16 port, u32 mask, u32 val)
{
iowrite(port - PCI_CONFIG_ADDR, val, mask,
&pci_config_addr.val);
verbose("PCI%s: %#x/%x: bus %u dev %u func %u reg %u\n",
pci_config_addr.bits.enabled ? "" : " DISABLED",
val, mask,
pci_config_addr.bits.busnum,
pci_config_addr.bits.devnum,
pci_config_addr.bits.funcnum,
pci_config_addr.bits.offset);
return true;
}
static void pci_addr_ioread(u16 port, u32 mask, u32 *val)
{
ioread(port - PCI_CONFIG_ADDR, pci_config_addr.val, mask, val);
}
static bool is_pci_data_port(u16 port)
{
return port >= PCI_CONFIG_DATA && port < PCI_CONFIG_DATA + 4;
}
static bool pci_data_iowrite(u16 port, u32 mask, u32 val)
{
u32 reg, portoff;
struct device *d = dev_and_reg(&reg);
if (!d)
return false;
portoff = port - PCI_CONFIG_DATA;
if (&d->config_words[reg] == &d->config.bar[0]) {
int i;
iowrite(portoff, val, mask, &d->config.bar[0]);
for (i = 0; (1 << i) < d->mmio_size; i++)
d->config.bar[0] &= ~(1 << i);
return true;
} else if ((&d->config_words[reg] > &d->config.bar[0]
&& &d->config_words[reg] <= &d->config.bar[6])
|| &d->config_words[reg] == &d->config.expansion_rom_addr) {
iowrite(portoff, val, mask, &d->config_words[reg]);
return true;
} else if (&d->config_words[reg] == (void *)&d->config.cacheline_size) {
if (mask == 0xFFFFFFFF)
mask = 0xFFFF;
iowrite(portoff, val, mask, &d->config_words[reg]);
return true;
} else if (&d->config_words[reg] == (void *)&d->config.command
&& mask == 0xFFFF) {
return true;
} else if (&d->config_words[reg]
== (void *)&d->config.cfg_access.cap.bar
|| &d->config_words[reg]
== &d->config.cfg_access.cap.length
|| &d->config_words[reg]
== &d->config.cfg_access.cap.offset) {
iowrite(portoff, val, mask, &d->config_words[reg]);
return true;
} else if (&d->config_words[reg] == &d->config.cfg_access.pci_cfg_data) {
u32 write_mask;
if (!valid_bar_access(d, &d->config.cfg_access))
return false;
iowrite(portoff, val, mask, &d->config.cfg_access.pci_cfg_data);
write_mask = (1ULL<<(8*d->config.cfg_access.cap.length)) - 1;
verbose("Window writing %#x/%#x to bar %u, offset %u len %u\n",
d->config.cfg_access.pci_cfg_data, write_mask,
d->config.cfg_access.cap.bar,
d->config.cfg_access.cap.offset,
d->config.cfg_access.cap.length);
emulate_mmio_write(d, d->config.cfg_access.cap.offset,
d->config.cfg_access.pci_cfg_data,
write_mask);
return true;
}
return false;
}
static void pci_data_ioread(u16 port, u32 mask, u32 *val)
{
u32 reg;
struct device *d = dev_and_reg(&reg);
if (!d)
return;
if (&d->config_words[reg] == &d->config.cfg_access.pci_cfg_data) {
u32 read_mask;
if (!valid_bar_access(d, &d->config.cfg_access))
bad_driver(d,
"Invalid cfg_access to bar%u, offset %u len %u",
d->config.cfg_access.cap.bar,
d->config.cfg_access.cap.offset,
d->config.cfg_access.cap.length);
read_mask = (1ULL<<(8*d->config.cfg_access.cap.length))-1;
d->config.cfg_access.pci_cfg_data
= emulate_mmio_read(d,
d->config.cfg_access.cap.offset,
read_mask);
verbose("Window read %#x/%#x from bar %u, offset %u len %u\n",
d->config.cfg_access.pci_cfg_data, read_mask,
d->config.cfg_access.cap.bar,
d->config.cfg_access.cap.offset,
d->config.cfg_access.cap.length);
}
ioread(port - PCI_CONFIG_DATA, d->config_words[reg], mask, val);
}
static u32 getreg_off(size_t offset)
{
u32 r;
unsigned long args[] = { LHREQ_GETREG, offset };
if (pwrite(lguest_fd, args, sizeof(args), cpu_id) < 0)
err(1, "Getting register %u", offset);
if (pread(lguest_fd, &r, sizeof(r), cpu_id) != sizeof(r))
err(1, "Reading register %u", offset);
return r;
}
static void setreg_off(size_t offset, u32 val)
{
unsigned long args[] = { LHREQ_SETREG, offset, val };
if (pwrite(lguest_fd, args, sizeof(args), cpu_id) < 0)
err(1, "Setting register %u", offset);
}
static u32 getreg_num(unsigned regnum, u32 mask)
{
if (mask == 0xFF && (regnum & 0x4))
return getreg_num(regnum & 0x3, 0xFFFF) >> 8;
switch (regnum) {
case 0: return getreg(eax) & mask;
case 1: return getreg(ecx) & mask;
case 2: return getreg(edx) & mask;
case 3: return getreg(ebx) & mask;
case 4: return getreg(esp) & mask;
case 5: return getreg(ebp) & mask;
case 6: return getreg(esi) & mask;
case 7: return getreg(edi) & mask;
}
abort();
}
static void setreg_num(unsigned regnum, u32 val, u32 mask)
{
assert(~(val & ~mask));
if (mask == 0xFF && (regnum & 0x4)) {
val = (val << 8) | getreg_num(regnum & 0x3, 0xFF);
setreg_num(regnum & 0x3, val, 0xFFFF);
return;
}
switch (regnum) {
case 0: setreg(eax, val | (getreg(eax) & ~mask)); return;
case 1: setreg(ecx, val | (getreg(ecx) & ~mask)); return;
case 2: setreg(edx, val | (getreg(edx) & ~mask)); return;
case 3: setreg(ebx, val | (getreg(ebx) & ~mask)); return;
case 4: setreg(esp, val | (getreg(esp) & ~mask)); return;
case 5: setreg(ebp, val | (getreg(ebp) & ~mask)); return;
case 6: setreg(esi, val | (getreg(esi) & ~mask)); return;
case 7: setreg(edi, val | (getreg(edi) & ~mask)); return;
}
abort();
}
static u32 insn_displacement_len(u8 mod_reg_rm)
{
switch (mod_reg_rm >> 6) {
case 0:
if ((mod_reg_rm & 0x7) == 0x5)
return 2;
return 0;
case 1:
return 1;
case 2:
return 4;
case 3:
return 0;
}
abort();
}
static void emulate_insn(const u8 insn[])
{
unsigned long args[] = { LHREQ_TRAP, 13 };
unsigned int insnlen = 0, in = 0, small_operand = 0, byte_access;
unsigned int eax, port, mask;
u32 val = 0xFFFFFFFF;
if ((getreg(xcs) & 3) != 0x1)
goto no_emulate;
if (insn[insnlen] == 0xfa) {
insnlen = 1;
goto skip_insn;
}
if (insn[insnlen] == 0x66) {
small_operand = 1;
insnlen = 1;
}
byte_access = !(insn[insnlen] & 1);
switch (insn[insnlen] & 0xFE) {
case 0xE4:
port = insn[insnlen+1];
insnlen += 2;
in = 1;
break;
case 0xEC:
port = getreg(edx) & 0xFFFF;
insnlen += 1;
in = 1;
break;
case 0xE6:
port = insn[insnlen+1];
insnlen += 2;
break;
case 0xEE:
port = getreg(edx) & 0xFFFF;
insnlen += 1;
break;
default:
goto no_emulate;
}
if (byte_access)
mask = 0xFF;
else if (small_operand)
mask = 0xFFFF;
else
mask = 0xFFFFFFFF;
eax = getreg(eax);
if (in) {
if (port == 0x64)
val = 1;
else if (is_pci_addr_port(port))
pci_addr_ioread(port, mask, &val);
else if (is_pci_data_port(port))
pci_data_ioread(port, mask, &val);
eax &= ~mask;
eax |= val & mask;
setreg(eax, eax);
} else {
if (is_pci_addr_port(port)) {
if (!pci_addr_iowrite(port, mask, eax))
goto bad_io;
} else if (is_pci_data_port(port)) {
if (!pci_data_iowrite(port, mask, eax))
goto bad_io;
}
}
verbose("IO %s of %x to %u: %#08x\n",
in ? "IN" : "OUT", mask, port, eax);
skip_insn:
setreg(eip, getreg(eip) + insnlen);
return;
bad_io:
warnx("Attempt to %s port %u (%#x mask)",
in ? "read from" : "write to", port, mask);
no_emulate:
if (write(lguest_fd, args, sizeof(args)) < 0)
err(1, "Reinjecting trap 13 for fault at %#x", getreg(eip));
}
static struct device *find_mmio_region(unsigned long paddr, u32 *off)
{
unsigned int i;
for (i = 1; i < MAX_PCI_DEVICES; i++) {
struct device *d = devices.pci[i];
if (!d)
continue;
if (paddr < d->mmio_addr)
continue;
if (paddr >= d->mmio_addr + d->mmio_size)
continue;
*off = paddr - d->mmio_addr;
return d;
}
return NULL;
}
static struct virtqueue *vq_by_num(struct device *d, u32 num)
{
struct virtqueue *vq = d->vq;
while (num-- && vq)
vq = vq->next;
return vq;
}
static void save_vq_config(const struct virtio_pci_common_cfg *cfg,
struct virtqueue *vq)
{
vq->pci_config = *cfg;
}
static void restore_vq_config(struct virtio_pci_common_cfg *cfg,
struct virtqueue *vq)
{
size_t off = offsetof(struct virtio_pci_common_cfg, queue_size);
memcpy((void *)cfg + off, (void *)&vq->pci_config + off,
sizeof(*cfg) - off);
}
static void check_virtqueue(struct device *d, struct virtqueue *vq)
{
if (vq->pci_config.queue_desc_hi
|| vq->pci_config.queue_avail_hi
|| vq->pci_config.queue_used_hi)
bad_driver_vq(vq, "invalid 64-bit queue address");
if (vq->pci_config.queue_desc_lo % 16
|| vq->pci_config.queue_avail_lo % 2
|| vq->pci_config.queue_used_lo % 4)
bad_driver_vq(vq, "invalid alignment in queue addresses");
vq->vring.num = vq->pci_config.queue_size;
vq->vring.desc = check_pointer(vq->dev,
vq->pci_config.queue_desc_lo,
sizeof(*vq->vring.desc) * vq->vring.num);
vq->vring.avail = check_pointer(vq->dev,
vq->pci_config.queue_avail_lo,
sizeof(*vq->vring.avail)
+ (sizeof(vq->vring.avail->ring[0])
* vq->vring.num));
vq->vring.used = check_pointer(vq->dev,
vq->pci_config.queue_used_lo,
sizeof(*vq->vring.used)
+ (sizeof(vq->vring.used->ring[0])
* vq->vring.num));
if (vq->vring.used->flags != 0)
bad_driver_vq(vq, "invalid initial used.flags %#x",
vq->vring.used->flags);
}
static void start_virtqueue(struct virtqueue *vq)
{
char *stack = malloc(32768);
vq->eventfd = eventfd(0, 0);
if (vq->eventfd < 0)
err(1, "Creating eventfd");
vq->thread = clone(do_thread, stack + 32768, CLONE_VM | SIGCHLD, vq);
if (vq->thread == (pid_t)-1)
err(1, "Creating clone");
}
static void start_virtqueues(struct device *d)
{
struct virtqueue *vq;
for (vq = d->vq; vq; vq = vq->next) {
if (vq->pci_config.queue_enable)
start_virtqueue(vq);
}
}
static void emulate_mmio_write(struct device *d, u32 off, u32 val, u32 mask)
{
struct virtqueue *vq;
switch (off) {
case offsetof(struct virtio_pci_mmio, cfg.device_feature_select):
if (val == 0)
d->mmio->cfg.device_feature = d->features;
else if (val == 1)
d->mmio->cfg.device_feature = (d->features >> 32);
else
d->mmio->cfg.device_feature = 0;
goto feature_write_through32;
case offsetof(struct virtio_pci_mmio, cfg.guest_feature_select):
if (val > 1)
bad_driver(d, "Unexpected driver select %u", val);
goto feature_write_through32;
case offsetof(struct virtio_pci_mmio, cfg.guest_feature):
if (d->mmio->cfg.guest_feature_select == 0) {
d->features_accepted &= ~((u64)0xFFFFFFFF);
d->features_accepted |= val;
} else {
assert(d->mmio->cfg.guest_feature_select == 1);
d->features_accepted &= 0xFFFFFFFF;
d->features_accepted |= ((u64)val) << 32;
}
if (d->features_accepted & ~d->features)
bad_driver(d, "over-accepted features %#llx of %#llx",
d->features_accepted, d->features);
goto feature_write_through32;
case offsetof(struct virtio_pci_mmio, cfg.device_status): {
u8 prev;
verbose("%s: device status -> %#x\n", d->name, val);
if (val == 0) {
reset_device(d);
goto write_through8;
}
if (d->mmio->cfg.device_status & ~val)
bad_driver(d, "unset of device status bit %#x -> %#x",
d->mmio->cfg.device_status, val);
if (val & VIRTIO_CONFIG_S_DRIVER_OK
&& !(d->mmio->cfg.device_status & VIRTIO_CONFIG_S_DRIVER_OK))
start_virtqueues(d);
prev = 0;
switch (val & ~d->mmio->cfg.device_status) {
case VIRTIO_CONFIG_S_DRIVER_OK:
prev |= VIRTIO_CONFIG_S_FEATURES_OK;
case VIRTIO_CONFIG_S_FEATURES_OK:
prev |= VIRTIO_CONFIG_S_DRIVER;
case VIRTIO_CONFIG_S_DRIVER:
prev |= VIRTIO_CONFIG_S_ACKNOWLEDGE;
case VIRTIO_CONFIG_S_ACKNOWLEDGE:
break;
default:
bad_driver(d, "unknown device status bit %#x -> %#x",
d->mmio->cfg.device_status, val);
}
if (d->mmio->cfg.device_status != prev)
bad_driver(d, "unexpected status transition %#x -> %#x",
d->mmio->cfg.device_status, val);
switch (val & ~d->mmio->cfg.device_status) {
case VIRTIO_CONFIG_S_FEATURES_OK:
d->wrote_features_ok = true;
break;
case VIRTIO_CONFIG_S_DRIVER_OK:
if (d->wrote_features_ok)
bad_driver(d, "did not re-read FEATURES_OK");
break;
}
goto write_through8;
}
case offsetof(struct virtio_pci_mmio, cfg.queue_select):
vq = vq_by_num(d, val);
if (!vq) {
d->mmio->cfg.queue_size = 0;
goto write_through16;
}
if (d->mmio->cfg.queue_size)
save_vq_config(&d->mmio->cfg,
vq_by_num(d, d->mmio->cfg.queue_select));
restore_vq_config(&d->mmio->cfg, vq);
goto write_through16;
case offsetof(struct virtio_pci_mmio, cfg.queue_size):
if (val & (val-1))
bad_driver(d, "invalid queue size %u", val);
if (d->mmio->cfg.queue_enable)
bad_driver(d, "changing queue size on live device");
goto write_through16;
case offsetof(struct virtio_pci_mmio, cfg.queue_msix_vector):
bad_driver(d, "attempt to set MSIX vector to %u", val);
case offsetof(struct virtio_pci_mmio, cfg.queue_enable): {
struct virtqueue *vq = vq_by_num(d, d->mmio->cfg.queue_select);
if (val != 1)
bad_driver(d, "setting queue_enable to %u", val);
if (d->mmio->cfg.device_status & VIRTIO_CONFIG_S_DRIVER_OK)
bad_driver(d, "enabling vq after DRIVER_OK");
d->mmio->cfg.queue_enable = val;
save_vq_config(&d->mmio->cfg, vq);
check_virtqueue(d, vq);
goto write_through16;
}
case offsetof(struct virtio_pci_mmio, cfg.queue_notify_off):
bad_driver(d, "attempt to write to queue_notify_off");
case offsetof(struct virtio_pci_mmio, cfg.queue_desc_lo):
case offsetof(struct virtio_pci_mmio, cfg.queue_desc_hi):
case offsetof(struct virtio_pci_mmio, cfg.queue_avail_lo):
case offsetof(struct virtio_pci_mmio, cfg.queue_avail_hi):
case offsetof(struct virtio_pci_mmio, cfg.queue_used_lo):
case offsetof(struct virtio_pci_mmio, cfg.queue_used_hi):
if (d->mmio->cfg.queue_enable)
bad_driver(d, "changing queue on live device");
if (!(d->mmio->cfg.device_status & VIRTIO_CONFIG_S_FEATURES_OK))
bad_driver(d, "setting up vq before FEATURES_OK");
if (d->wrote_features_ok)
bad_driver(d, "didn't re-read FEATURES_OK before setup");
goto write_through32;
case offsetof(struct virtio_pci_mmio, notify):
vq = vq_by_num(d, val);
if (!vq)
bad_driver(d, "Invalid vq notification on %u", val);
write(vq->eventfd, "\1\0\0\0\0\0\0\0", 8);
goto write_through16;
case offsetof(struct virtio_pci_mmio, isr):
bad_driver(d, "Unexpected write to isr");
case sizeof(struct virtio_pci_mmio)
+ offsetof(struct virtio_console_config, emerg_wr):
if (strcmp(d->name, "console") == 0) {
char c = val;
write(STDOUT_FILENO, &c, 1);
goto write_through32;
}
default:
bad_driver(d, "Unexpected write to offset %u", off);
}
feature_write_through32:
if (!(d->mmio->cfg.device_status & VIRTIO_CONFIG_S_DRIVER))
bad_driver(d, "feature write before VIRTIO_CONFIG_S_DRIVER");
if (d->mmio->cfg.device_status & VIRTIO_CONFIG_S_FEATURES_OK)
bad_driver(d, "feature write after VIRTIO_CONFIG_S_FEATURES_OK");
write_through32:
if (mask != 0xFFFFFFFF) {
bad_driver(d, "non-32-bit write to offset %u (%#x)",
off, getreg(eip));
return;
}
memcpy((char *)d->mmio + off, &val, 4);
return;
write_through16:
if (mask != 0xFFFF)
bad_driver(d, "non-16-bit write to offset %u (%#x)",
off, getreg(eip));
memcpy((char *)d->mmio + off, &val, 2);
return;
write_through8:
if (mask != 0xFF)
bad_driver(d, "non-8-bit write to offset %u (%#x)",
off, getreg(eip));
memcpy((char *)d->mmio + off, &val, 1);
return;
}
static u32 emulate_mmio_read(struct device *d, u32 off, u32 mask)
{
u8 isr;
u32 val = 0;
switch (off) {
case offsetof(struct virtio_pci_mmio, cfg.device_feature_select):
case offsetof(struct virtio_pci_mmio, cfg.device_feature):
case offsetof(struct virtio_pci_mmio, cfg.guest_feature_select):
case offsetof(struct virtio_pci_mmio, cfg.guest_feature):
if (!(d->mmio->cfg.device_status & VIRTIO_CONFIG_S_DRIVER))
bad_driver(d,
"feature read before VIRTIO_CONFIG_S_DRIVER");
goto read_through32;
case offsetof(struct virtio_pci_mmio, cfg.msix_config):
bad_driver(d, "read of msix_config");
case offsetof(struct virtio_pci_mmio, cfg.num_queues):
goto read_through16;
case offsetof(struct virtio_pci_mmio, cfg.device_status):
d->wrote_features_ok = false;
goto read_through8;
case offsetof(struct virtio_pci_mmio, cfg.config_generation):
goto read_through8;
case offsetof(struct virtio_pci_mmio, notify):
if (!(d->mmio->cfg.device_status & VIRTIO_CONFIG_S_DRIVER_OK))
bad_driver(d, "notify before VIRTIO_CONFIG_S_DRIVER_OK");
goto read_through16;
case offsetof(struct virtio_pci_mmio, isr):
if (mask != 0xFF)
bad_driver(d, "non-8-bit read from offset %u (%#x)",
off, getreg(eip));
isr = d->mmio->isr;
d->mmio->isr = 0;
return isr;
case offsetof(struct virtio_pci_mmio, padding):
bad_driver(d, "read from padding (%#x)", getreg(eip));
default:
if (off > d->mmio_size - 4)
bad_driver(d, "read past end (%#x)", getreg(eip));
if (!(d->mmio->cfg.device_status & VIRTIO_CONFIG_S_DRIVER))
bad_driver(d,
"config read before VIRTIO_CONFIG_S_DRIVER");
if (mask == 0xFFFFFFFF)
goto read_through32;
else if (mask == 0xFFFF)
goto read_through16;
else
goto read_through8;
}
read_through32:
if (mask != 0xFFFFFFFF)
bad_driver(d, "non-32-bit read to offset %u (%#x)",
off, getreg(eip));
memcpy(&val, (char *)d->mmio + off, 4);
return val;
read_through16:
if (mask != 0xFFFF)
bad_driver(d, "non-16-bit read to offset %u (%#x)",
off, getreg(eip));
memcpy(&val, (char *)d->mmio + off, 2);
return val;
read_through8:
if (mask != 0xFF)
bad_driver(d, "non-8-bit read to offset %u (%#x)",
off, getreg(eip));
memcpy(&val, (char *)d->mmio + off, 1);
return val;
}
static void emulate_mmio(unsigned long paddr, const u8 *insn)
{
u32 val, off, mask = 0xFFFFFFFF, insnlen = 0;
struct device *d = find_mmio_region(paddr, &off);
unsigned long args[] = { LHREQ_TRAP, 14 };
if (!d) {
warnx("MMIO touching %#08lx (not a device)", paddr);
goto reinject;
}
if (insn[0] == 0x66) {
mask = 0xFFFF;
insnlen++;
}
if (insn[insnlen] == 0x89) {
val = getreg_num((insn[insnlen+1] >> 3) & 0x7, mask);
emulate_mmio_write(d, off, val, mask);
insnlen += 2 + insn_displacement_len(insn[insnlen+1]);
} else if (insn[insnlen] == 0x8b) {
val = emulate_mmio_read(d, off, mask);
setreg_num((insn[insnlen+1] >> 3) & 0x7, val, mask);
insnlen += 2 + insn_displacement_len(insn[insnlen+1]);
} else if (insn[0] == 0x88) {
mask = 0xff;
val = getreg_num((insn[1] >> 3) & 0x7, mask);
emulate_mmio_write(d, off, val, mask);
insnlen = 2 + insn_displacement_len(insn[1]);
} else if (insn[0] == 0x8a) {
mask = 0xff;
val = emulate_mmio_read(d, off, mask);
setreg_num((insn[1] >> 3) & 0x7, val, mask);
insnlen = 2 + insn_displacement_len(insn[1]);
} else {
warnx("Unknown MMIO instruction touching %#08lx:"
" %02x %02x %02x %02x at %u",
paddr, insn[0], insn[1], insn[2], insn[3], getreg(eip));
reinject:
if (write(lguest_fd, args, sizeof(args)) < 0)
err(1, "Reinjecting trap 14 for fault at %#x",
getreg(eip));
return;
}
setreg(eip, getreg(eip) + insnlen);
}
static void add_pci_virtqueue(struct device *dev,
void (*service)(struct virtqueue *),
const char *name)
{
struct virtqueue **i, *vq = malloc(sizeof(*vq));
vq->next = NULL;
vq->last_avail_idx = 0;
vq->dev = dev;
vq->name = name;
vq->service = service;
vq->thread = (pid_t)-1;
reset_vq_pci_config(vq);
vq->pci_config.queue_notify_off = 0;
vq->dev->mmio->cfg.num_queues++;
for (i = &dev->vq; *i; i = &(*i)->next);
*i = vq;
}
static void add_pci_feature(struct device *dev, unsigned bit)
{
dev->features |= (1ULL << bit);
}
static void no_device_config(struct device *dev)
{
dev->mmio_addr = get_mmio_region(dev->mmio_size);
dev->config.bar[0] = dev->mmio_addr;
assert(~(dev->config.bar[0] & 0xF));
}
static void set_device_config(struct device *dev, const void *conf, size_t len)
{
dev->mmio_size += len;
dev->mmio = realloc(dev->mmio, dev->mmio_size);
memcpy(dev->mmio + 1, conf, len);
dev->config.cfg_access.cap.cap_next
= offsetof(struct pci_config, device);
assert(dev->config.cfg_access.cap.cap_next % 4 == 0);
dev->config.device.length = len;
no_device_config(dev);
}
static void init_cap(struct virtio_pci_cap *cap, size_t caplen, int type,
size_t bar_offset, size_t bar_bytes, u8 next)
{
cap->cap_vndr = PCI_CAP_ID_VNDR;
cap->cap_next = next;
cap->cap_len = caplen;
cap->cfg_type = type;
cap->bar = 0;
memset(cap->padding, 0, sizeof(cap->padding));
cap->offset = bar_offset;
cap->length = bar_bytes;
}
static void init_pci_config(struct pci_config *pci, u16 type,
u8 class, u8 subclass)
{
size_t bar_offset, bar_len;
memset(pci, 0, sizeof(*pci));
pci->vendor_id = 0x1AF4;
pci->device_id = 0x1040 + type;
pci->class = class;
pci->subclass = subclass;
pci->revid = 1;
pci->subsystem_device_id = 0x40;
pci->irq_line = devices.next_irq++;
pci->irq_pin = 0;
pci->status = (1 << 4);
pci->capabilities = offsetof(struct pci_config, common);
assert(pci->capabilities % 4 == 0);
bar_offset = offsetof(struct virtio_pci_mmio, cfg);
bar_len = sizeof(((struct virtio_pci_mmio *)0)->cfg);
init_cap(&pci->common, sizeof(pci->common), VIRTIO_PCI_CAP_COMMON_CFG,
bar_offset, bar_len,
offsetof(struct pci_config, notify));
bar_offset += bar_len;
bar_len = sizeof(((struct virtio_pci_mmio *)0)->notify);
assert(pci->common.cap_next % 2 == 0);
assert(bar_len >= 2);
init_cap(&pci->notify.cap, sizeof(pci->notify),
VIRTIO_PCI_CAP_NOTIFY_CFG,
bar_offset, bar_len,
offsetof(struct pci_config, isr));
bar_offset += bar_len;
bar_len = sizeof(((struct virtio_pci_mmio *)0)->isr);
init_cap(&pci->isr, sizeof(pci->isr),
VIRTIO_PCI_CAP_ISR_CFG,
bar_offset, bar_len,
offsetof(struct pci_config, cfg_access));
init_cap(&pci->cfg_access.cap, sizeof(pci->cfg_access),
VIRTIO_PCI_CAP_PCI_CFG,
0, 0, 0);
bar_offset += bar_len + sizeof(((struct virtio_pci_mmio *)0)->padding);
assert(bar_offset == sizeof(struct virtio_pci_mmio));
init_cap(&pci->device, sizeof(pci->device), VIRTIO_PCI_CAP_DEVICE_CFG,
bar_offset, 0, 0);
}
static struct device *new_pci_device(const char *name, u16 type,
u8 class, u8 subclass)
{
struct device *dev = malloc(sizeof(*dev));
dev->name = name;
dev->vq = NULL;
dev->running = false;
dev->wrote_features_ok = false;
dev->mmio_size = sizeof(struct virtio_pci_mmio);
dev->mmio = calloc(1, dev->mmio_size);
dev->features = (u64)1 << VIRTIO_F_VERSION_1;
dev->features_accepted = 0;
if (devices.device_num + 1 >= MAX_PCI_DEVICES)
errx(1, "Can only handle 31 PCI devices");
init_pci_config(&dev->config, type, class, subclass);
assert(!devices.pci[devices.device_num+1]);
devices.pci[++devices.device_num] = dev;
return dev;
}
static void setup_console(void)
{
struct device *dev;
struct virtio_console_config conf;
if (tcgetattr(STDIN_FILENO, &orig_term) == 0) {
struct termios term = orig_term;
term.c_lflag &= ~(ISIG|ICANON|ECHO);
tcsetattr(STDIN_FILENO, TCSANOW, &term);
}
dev = new_pci_device("console", VIRTIO_ID_CONSOLE, 0x07, 0x00);
dev->priv = malloc(sizeof(struct console_abort));
((struct console_abort *)dev->priv)->count = 0;
add_pci_virtqueue(dev, console_input, "input");
add_pci_virtqueue(dev, console_output, "output");
add_pci_feature(dev, VIRTIO_CONSOLE_F_EMERG_WRITE);
set_device_config(dev, &conf, sizeof(conf));
verbose("device %u: console\n", devices.device_num);
}
static u32 str2ip(const char *ipaddr)
{
unsigned int b[4];
if (sscanf(ipaddr, "%u.%u.%u.%u", &b[0], &b[1], &b[2], &b[3]) != 4)
errx(1, "Failed to parse IP address '%s'", ipaddr);
return (b[0] << 24) | (b[1] << 16) | (b[2] << 8) | b[3];
}
static void str2mac(const char *macaddr, unsigned char mac[6])
{
unsigned int m[6];
if (sscanf(macaddr, "%02x:%02x:%02x:%02x:%02x:%02x",
&m[0], &m[1], &m[2], &m[3], &m[4], &m[5]) != 6)
errx(1, "Failed to parse mac address '%s'", macaddr);
mac[0] = m[0];
mac[1] = m[1];
mac[2] = m[2];
mac[3] = m[3];
mac[4] = m[4];
mac[5] = m[5];
}
static void add_to_bridge(int fd, const char *if_name, const char *br_name)
{
int ifidx;
struct ifreq ifr;
if (!*br_name)
errx(1, "must specify bridge name");
ifidx = if_nametoindex(if_name);
if (!ifidx)
errx(1, "interface %s does not exist!", if_name);
strncpy(ifr.ifr_name, br_name, IFNAMSIZ);
ifr.ifr_name[IFNAMSIZ-1] = '\0';
ifr.ifr_ifindex = ifidx;
if (ioctl(fd, SIOCBRADDIF, &ifr) < 0)
err(1, "can't add %s to bridge %s", if_name, br_name);
}
static void configure_device(int fd, const char *tapif, u32 ipaddr)
{
struct ifreq ifr;
struct sockaddr_in sin;
memset(&ifr, 0, sizeof(ifr));
strcpy(ifr.ifr_name, tapif);
sin.sin_family = AF_INET;
sin.sin_addr.s_addr = htonl(ipaddr);
memcpy(&ifr.ifr_addr, &sin, sizeof(sin));
if (ioctl(fd, SIOCSIFADDR, &ifr) != 0)
err(1, "Setting %s interface address", tapif);
ifr.ifr_flags = IFF_UP;
if (ioctl(fd, SIOCSIFFLAGS, &ifr) != 0)
err(1, "Bringing interface %s up", tapif);
}
static int get_tun_device(char tapif[IFNAMSIZ])
{
struct ifreq ifr;
int vnet_hdr_sz;
int netfd;
memset(&ifr, 0, sizeof(ifr));
netfd = open_or_die("/dev/net/tun", O_RDWR);
ifr.ifr_flags = IFF_TAP | IFF_NO_PI | IFF_VNET_HDR;
strcpy(ifr.ifr_name, "tap%d");
if (ioctl(netfd, TUNSETIFF, &ifr) != 0)
err(1, "configuring /dev/net/tun");
if (ioctl(netfd, TUNSETOFFLOAD,
TUN_F_CSUM|TUN_F_TSO4|TUN_F_TSO6|TUN_F_TSO_ECN) != 0)
err(1, "Could not set features for tun device");
ioctl(netfd, TUNSETNOCSUM, 1);
vnet_hdr_sz = sizeof(struct virtio_net_hdr_v1);
if (ioctl(netfd, TUNSETVNETHDRSZ, &vnet_hdr_sz) != 0)
err(1, "Setting tun header size to %u", vnet_hdr_sz);
memcpy(tapif, ifr.ifr_name, IFNAMSIZ);
return netfd;
}
static void setup_tun_net(char *arg)
{
struct device *dev;
struct net_info *net_info = malloc(sizeof(*net_info));
int ipfd;
u32 ip = INADDR_ANY;
bool bridging = false;
char tapif[IFNAMSIZ], *p;
struct virtio_net_config conf;
net_info->tunfd = get_tun_device(tapif);
dev = new_pci_device("net", VIRTIO_ID_NET, 0x02, 0x00);
dev->priv = net_info;
add_pci_virtqueue(dev, net_input, "rx");
add_pci_virtqueue(dev, net_output, "tx");
ipfd = socket(PF_INET, SOCK_DGRAM, IPPROTO_IP);
if (ipfd < 0)
err(1, "opening IP socket");
if (!strncmp(BRIDGE_PFX, arg, strlen(BRIDGE_PFX))) {
arg += strlen(BRIDGE_PFX);
bridging = true;
}
p = strchr(arg, ':');
if (p) {
str2mac(p+1, conf.mac);
add_pci_feature(dev, VIRTIO_NET_F_MAC);
*p = '\0';
}
if (bridging)
add_to_bridge(ipfd, tapif, arg);
else
ip = str2ip(arg);
configure_device(ipfd, tapif, ip);
add_pci_feature(dev, VIRTIO_NET_F_CSUM);
add_pci_feature(dev, VIRTIO_NET_F_GUEST_CSUM);
add_pci_feature(dev, VIRTIO_NET_F_GUEST_TSO4);
add_pci_feature(dev, VIRTIO_NET_F_GUEST_TSO6);
add_pci_feature(dev, VIRTIO_NET_F_GUEST_ECN);
add_pci_feature(dev, VIRTIO_NET_F_HOST_TSO4);
add_pci_feature(dev, VIRTIO_NET_F_HOST_TSO6);
add_pci_feature(dev, VIRTIO_NET_F_HOST_ECN);
add_pci_feature(dev, VIRTIO_RING_F_INDIRECT_DESC);
set_device_config(dev, &conf, sizeof(conf));
close(ipfd);
if (bridging)
verbose("device %u: tun %s attached to bridge: %s\n",
devices.device_num, tapif, arg);
else
verbose("device %u: tun %s: %s\n",
devices.device_num, tapif, arg);
}
static void blk_request(struct virtqueue *vq)
{
struct vblk_info *vblk = vq->dev->priv;
unsigned int head, out_num, in_num, wlen;
int ret, i;
u8 *in;
struct virtio_blk_outhdr out;
struct iovec iov[vq->vring.num];
off64_t off;
head = wait_for_vq_desc(vq, iov, &out_num, &in_num);
iov_consume(vq->dev, iov, out_num, &out, sizeof(out));
in = NULL;
for (i = out_num + in_num - 1; i >= out_num; i--) {
if (iov[i].iov_len > 0) {
in = iov[i].iov_base + iov[i].iov_len - 1;
iov[i].iov_len--;
break;
}
}
if (!in)
bad_driver_vq(vq, "Bad virtblk cmd with no room for status");
off = out.sector * 512;
if (out.type & VIRTIO_BLK_T_OUT) {
if (lseek64(vblk->fd, off, SEEK_SET) != off)
err(1, "Bad seek to sector %llu", out.sector);
ret = writev(vblk->fd, iov, out_num);
verbose("WRITE to sector %llu: %i\n", out.sector, ret);
if (ret > 0 && off + ret > vblk->len) {
ftruncate64(vblk->fd, vblk->len);
bad_driver_vq(vq, "Write past end %llu+%u", off, ret);
}
wlen = sizeof(*in);
*in = (ret >= 0 ? VIRTIO_BLK_S_OK : VIRTIO_BLK_S_IOERR);
} else if (out.type & VIRTIO_BLK_T_FLUSH) {
ret = fdatasync(vblk->fd);
verbose("FLUSH fdatasync: %i\n", ret);
wlen = sizeof(*in);
*in = (ret >= 0 ? VIRTIO_BLK_S_OK : VIRTIO_BLK_S_IOERR);
} else {
if (lseek64(vblk->fd, off, SEEK_SET) != off)
err(1, "Bad seek to sector %llu", out.sector);
ret = readv(vblk->fd, iov + out_num, in_num);
if (ret >= 0) {
wlen = sizeof(*in) + ret;
*in = VIRTIO_BLK_S_OK;
} else {
wlen = sizeof(*in);
*in = VIRTIO_BLK_S_IOERR;
}
}
add_used(vq, head, wlen);
}
static void setup_block_file(const char *filename)
{
struct device *dev;
struct vblk_info *vblk;
struct virtio_blk_config conf;
dev = new_pci_device("block", VIRTIO_ID_BLOCK, 0x01, 0x80);
add_pci_virtqueue(dev, blk_request, "request");
vblk = dev->priv = malloc(sizeof(*vblk));
vblk->fd = open_or_die(filename, O_RDWR|O_LARGEFILE);
vblk->len = lseek64(vblk->fd, 0, SEEK_END);
conf.capacity = cpu_to_le64(vblk->len / 512);
add_pci_feature(dev, VIRTIO_BLK_F_SEG_MAX);
conf.seg_max = cpu_to_le32(VIRTQUEUE_NUM - 2);
set_device_config(dev, &conf, sizeof(struct virtio_blk_config));
verbose("device %u: virtblock %llu sectors\n",
devices.device_num, le64_to_cpu(conf.capacity));
}
static void rng_input(struct virtqueue *vq)
{
int len;
unsigned int head, in_num, out_num, totlen = 0;
struct rng_info *rng_info = vq->dev->priv;
struct iovec iov[vq->vring.num];
head = wait_for_vq_desc(vq, iov, &out_num, &in_num);
if (out_num)
bad_driver_vq(vq, "Output buffers in rng?");
while (!iov_empty(iov, in_num)) {
len = readv(rng_info->rfd, iov, in_num);
if (len <= 0)
err(1, "Read from /dev/urandom gave %i", len);
iov_consume(vq->dev, iov, in_num, NULL, len);
totlen += len;
}
add_used(vq, head, totlen);
}
static void setup_rng(void)
{
struct device *dev;
struct rng_info *rng_info = malloc(sizeof(*rng_info));
rng_info->rfd = open_or_die("/dev/urandom", O_RDONLY);
dev = new_pci_device("rng", VIRTIO_ID_RNG, 0xff, 0);
dev->priv = rng_info;
add_pci_virtqueue(dev, rng_input, "input");
no_device_config(dev);
verbose("device %u: rng\n", devices.device_num);
}
static void usage(void)
{
errx(1, "Usage: lguest [--verbose] "
"[--tunnet=(<ipaddr>:<macaddr>|bridge:<bridgename>:<macaddr>)\n"
"|--block=<filename>|--initrd=<filename>]...\n"
"<mem-in-mb> vmlinux [args...]");
}
int main(int argc, char *argv[])
{
unsigned long mem = 0, start, initrd_size = 0;
int i, c;
struct boot_params *boot;
const char *initrd_name = NULL;
struct passwd *user_details = NULL;
char *chroot_path = NULL;
main_args = argv;
devices.next_irq = 1;
cpu_id = 0;
for (i = 1; i < argc; i++) {
if (argv[i][0] != '-') {
mem = atoi(argv[i]) * 1024 * 1024;
guest_base = map_zeroed_pages(mem / getpagesize()
+ DEVICE_PAGES);
guest_limit = mem;
guest_max = guest_mmio = mem + DEVICE_PAGES*getpagesize();
break;
}
}
atexit(cleanup_devices);
setup_console();
while ((c = getopt_long(argc, argv, "v", opts, NULL)) != EOF) {
switch (c) {
case 'v':
verbose = true;
break;
case 't':
setup_tun_net(optarg);
break;
case 'b':
setup_block_file(optarg);
break;
case 'r':
setup_rng();
break;
case 'i':
initrd_name = optarg;
break;
case 'u':
user_details = getpwnam(optarg);
if (!user_details)
err(1, "getpwnam failed, incorrect username?");
break;
case 'c':
chroot_path = optarg;
break;
default:
warnx("Unknown argument %s", argv[optind]);
usage();
}
}
if (optind + 2 > argc)
usage();
verbose("Guest base is at %p\n", guest_base);
init_pci_host_bridge();
start = load_kernel(open_or_die(argv[optind+1], O_RDONLY));
boot = from_guest_phys(0);
if (initrd_name) {
initrd_size = load_initrd(initrd_name, mem);
boot->hdr.ramdisk_image = mem - initrd_size;
boot->hdr.ramdisk_size = initrd_size;
boot->hdr.type_of_loader = 0xFF;
}
boot->e820_entries = 1;
boot->e820_map[0] = ((struct e820entry) { 0, mem, E820_RAM });
boot->hdr.cmd_line_ptr = to_guest_phys(boot + 1);
concat((char *)(boot + 1), argv+optind+2);
boot->hdr.kernel_alignment = 0x1000000;
boot->hdr.version = 0x207;
boot->hdr.hardware_subarch = X86_SUBARCH_LGUEST;
boot->hdr.loadflags |= KEEP_SEGMENTS;
boot->tboot_addr = 0;
boot->apm_bios_info.version = 0;
tell_kernel(start);
signal(SIGCHLD, kill_launcher);
if (chroot_path) {
if (chroot(chroot_path) != 0)
err(1, "chroot(\"%s\") failed", chroot_path);
if (chdir("/") != 0)
err(1, "chdir(\"/\") failed");
verbose("chroot done\n");
}
if (user_details) {
uid_t u;
gid_t g;
u = user_details->pw_uid;
g = user_details->pw_gid;
if (initgroups(user_details->pw_name, g) != 0)
err(1, "initgroups failed");
if (setresgid(g, g, g) != 0)
err(1, "setresgid failed");
if (setresuid(u, u, u) != 0)
err(1, "setresuid failed");
verbose("Dropping privileges completed\n");
}
run_guest();
}
