static int __init
setup_nobau(char *arg)
{
nobau = 1;
return 0;
}
static int __init uvhub_to_first_node(int uvhub)
{
int node, b;
for_each_online_node(node) {
b = uv_node_to_blade_id(node);
if (uvhub == b)
return node;
}
return -1;
}
static int __init uvhub_to_first_apicid(int uvhub)
{
int cpu;
for_each_present_cpu(cpu)
if (uvhub == uv_cpu_to_blade_id(cpu))
return per_cpu(x86_cpu_to_apicid, cpu);
return -1;
}
static void reply_to_message(struct msg_desc *mdp, struct bau_control *bcp)
{
unsigned long dw;
struct bau_pq_entry *msg;
msg = mdp->msg;
if (!msg->canceled) {
dw = (msg->swack_vec << UV_SW_ACK_NPENDING) | msg->swack_vec;
write_mmr_sw_ack(dw);
}
msg->replied_to = 1;
msg->swack_vec = 0;
}
static void bau_process_retry_msg(struct msg_desc *mdp,
struct bau_control *bcp)
{
int i;
int cancel_count = 0;
unsigned long msg_res;
unsigned long mmr = 0;
struct bau_pq_entry *msg = mdp->msg;
struct bau_pq_entry *msg2;
struct ptc_stats *stat = bcp->statp;
stat->d_retries++;
for (msg2 = msg+1, i = 0; i < DEST_Q_SIZE; msg2++, i++) {
if (msg2 > mdp->queue_last)
msg2 = mdp->queue_first;
if (msg2 == msg)
break;
if ((msg2->replied_to == 0) && (msg2->canceled == 0) &&
(msg2->swack_vec) && ((msg2->swack_vec &
msg->swack_vec) == 0) &&
(msg2->sending_cpu == msg->sending_cpu) &&
(msg2->msg_type != MSG_NOOP)) {
mmr = read_mmr_sw_ack();
msg_res = msg2->swack_vec;
if (mmr & (msg_res << UV_SW_ACK_NPENDING)) {
unsigned long mr;
msg2->canceled = 1;
stat->d_canceled++;
cancel_count++;
mr = (msg_res << UV_SW_ACK_NPENDING) | msg_res;
write_mmr_sw_ack(mr);
}
}
}
if (!cancel_count)
stat->d_nocanceled++;
}
static void bau_process_message(struct msg_desc *mdp,
struct bau_control *bcp)
{
short socket_ack_count = 0;
short *sp;
struct atomic_short *asp;
struct ptc_stats *stat = bcp->statp;
struct bau_pq_entry *msg = mdp->msg;
struct bau_control *smaster = bcp->socket_master;
if (msg->address == TLB_FLUSH_ALL) {
local_flush_tlb();
stat->d_alltlb++;
} else {
__flush_tlb_one(msg->address);
stat->d_onetlb++;
}
stat->d_requestee++;
if (msg->msg_type == MSG_RETRY && bcp == bcp->uvhub_master)
bau_process_retry_msg(mdp, bcp);
sp = &smaster->socket_acknowledge_count[mdp->msg_slot];
asp = (struct atomic_short *)sp;
socket_ack_count = atom_asr(1, asp);
if (socket_ack_count == bcp->cpus_in_socket) {
int msg_ack_count;
smaster->socket_acknowledge_count[mdp->msg_slot] = 0;
asp = (struct atomic_short *)&msg->acknowledge_count;
msg_ack_count = atom_asr(socket_ack_count, asp);
if (msg_ack_count == bcp->cpus_in_uvhub) {
reply_to_message(mdp, bcp);
}
}
return;
}
static int pnode_to_first_cpu(int pnode, struct bau_control *smaster)
{
int cpu;
struct hub_and_pnode *hpp;
for_each_present_cpu(cpu) {
hpp = &smaster->thp[cpu];
if (pnode == hpp->pnode)
return cpu;
}
return -1;
}
static void do_reset(void *ptr)
{
int i;
struct bau_control *bcp = &per_cpu(bau_control, smp_processor_id());
struct reset_args *rap = (struct reset_args *)ptr;
struct bau_pq_entry *msg;
struct ptc_stats *stat = bcp->statp;
stat->d_resets++;
for (msg = bcp->queue_first, i = 0; i < DEST_Q_SIZE; msg++, i++) {
unsigned long msg_res;
if ((msg->replied_to == 0) &&
(msg->canceled == 0) &&
(msg->sending_cpu == rap->sender) &&
(msg->swack_vec) &&
(msg->msg_type != MSG_NOOP)) {
unsigned long mmr;
unsigned long mr;
msg->canceled = 1;
mmr = read_mmr_sw_ack();
msg_res = msg->swack_vec;
mr = (msg_res << UV_SW_ACK_NPENDING) | msg_res;
if (mmr & msg_res) {
stat->d_rcanceled++;
write_mmr_sw_ack(mr);
}
}
}
return;
}
static void reset_with_ipi(struct pnmask *distribution, struct bau_control *bcp)
{
int pnode;
int apnode;
int maskbits;
int sender = bcp->cpu;
cpumask_t *mask = bcp->uvhub_master->cpumask;
struct bau_control *smaster = bcp->socket_master;
struct reset_args reset_args;
reset_args.sender = sender;
cpus_clear(*mask);
maskbits = sizeof(struct pnmask) * BITSPERBYTE;
for (pnode = 0; pnode < maskbits; pnode++) {
int cpu;
if (!bau_uvhub_isset(pnode, distribution))
continue;
apnode = pnode + bcp->partition_base_pnode;
cpu = pnode_to_first_cpu(apnode, smaster);
cpu_set(cpu, *mask);
}
smp_call_function_many(mask, do_reset, (void *)&reset_args, 1);
return;
}
static inline unsigned long cycles_2_us(unsigned long long cyc)
{
unsigned long long ns;
unsigned long us;
int cpu = smp_processor_id();
ns = (cyc * per_cpu(cyc2ns, cpu)) >> CYC2NS_SCALE_FACTOR;
us = ns / 1000;
return us;
}
static inline void quiesce_local_uvhub(struct bau_control *hmaster)
{
atom_asr(1, (struct atomic_short *)&hmaster->uvhub_quiesce);
}
static inline void end_uvhub_quiesce(struct bau_control *hmaster)
{
atom_asr(-1, (struct atomic_short *)&hmaster->uvhub_quiesce);
}
static unsigned long uv1_read_status(unsigned long mmr_offset, int right_shift)
{
unsigned long descriptor_status;
descriptor_status = uv_read_local_mmr(mmr_offset);
descriptor_status >>= right_shift;
descriptor_status &= UV_ACT_STATUS_MASK;
return descriptor_status;
}
static int uv1_wait_completion(struct bau_desc *bau_desc,
unsigned long mmr_offset, int right_shift,
struct bau_control *bcp, long try)
{
unsigned long descriptor_status;
cycles_t ttm;
struct ptc_stats *stat = bcp->statp;
descriptor_status = uv1_read_status(mmr_offset, right_shift);
while ((descriptor_status != DS_IDLE)) {
if (descriptor_status == DS_SOURCE_TIMEOUT) {
stat->s_stimeout++;
return FLUSH_GIVEUP;
} else if (descriptor_status == DS_DESTINATION_TIMEOUT) {
stat->s_dtimeout++;
ttm = get_cycles();
if (cycles_2_us(ttm - bcp->send_message) < timeout_us) {
bcp->conseccompletes = 0;
return FLUSH_RETRY_PLUGGED;
}
bcp->conseccompletes = 0;
return FLUSH_RETRY_TIMEOUT;
} else {
cpu_relax();
}
descriptor_status = uv1_read_status(mmr_offset, right_shift);
}
bcp->conseccompletes++;
return FLUSH_COMPLETE;
}
static unsigned long uv2_read_status(unsigned long offset, int rshft, int cpu)
{
unsigned long descriptor_status;
unsigned long descriptor_status2;
descriptor_status = ((read_lmmr(offset) >> rshft) & UV_ACT_STATUS_MASK);
descriptor_status2 = (read_mmr_uv2_status() >> cpu) & 0x1UL;
descriptor_status = (descriptor_status << 1) | descriptor_status2;
return descriptor_status;
}
static int uv2_wait_completion(struct bau_desc *bau_desc,
unsigned long mmr_offset, int right_shift,
struct bau_control *bcp, long try)
{
unsigned long descriptor_stat;
cycles_t ttm;
int cpu = bcp->uvhub_cpu;
struct ptc_stats *stat = bcp->statp;
descriptor_stat = uv2_read_status(mmr_offset, right_shift, cpu);
while (descriptor_stat != UV2H_DESC_IDLE) {
if ((descriptor_stat == UV2H_DESC_SOURCE_TIMEOUT) ||
(descriptor_stat == UV2H_DESC_DEST_STRONG_NACK) ||
(descriptor_stat == UV2H_DESC_DEST_PUT_ERR)) {
stat->s_stimeout++;
return FLUSH_GIVEUP;
} else if (descriptor_stat == UV2H_DESC_DEST_TIMEOUT) {
stat->s_dtimeout++;
ttm = get_cycles();
if (cycles_2_us(ttm - bcp->send_message) < timeout_us) {
bcp->conseccompletes = 0;
return FLUSH_RETRY_PLUGGED;
}
bcp->conseccompletes = 0;
return FLUSH_RETRY_TIMEOUT;
} else {
cpu_relax();
}
descriptor_stat = uv2_read_status(mmr_offset, right_shift, cpu);
}
bcp->conseccompletes++;
return FLUSH_COMPLETE;
}
static int wait_completion(struct bau_desc *bau_desc,
struct bau_control *bcp, long try)
{
int right_shift;
unsigned long mmr_offset;
int cpu = bcp->uvhub_cpu;
if (cpu < UV_CPUS_PER_AS) {
mmr_offset = UVH_LB_BAU_SB_ACTIVATION_STATUS_0;
right_shift = cpu * UV_ACT_STATUS_SIZE;
} else {
mmr_offset = UVH_LB_BAU_SB_ACTIVATION_STATUS_1;
right_shift = ((cpu - UV_CPUS_PER_AS) * UV_ACT_STATUS_SIZE);
}
if (is_uv1_hub())
return uv1_wait_completion(bau_desc, mmr_offset, right_shift,
bcp, try);
else
return uv2_wait_completion(bau_desc, mmr_offset, right_shift,
bcp, try);
}
static inline cycles_t sec_2_cycles(unsigned long sec)
{
unsigned long ns;
cycles_t cyc;
ns = sec * 1000000000;
cyc = (ns << CYC2NS_SCALE_FACTOR)/(per_cpu(cyc2ns, smp_processor_id()));
return cyc;
}
static void destination_plugged(struct bau_desc *bau_desc,
struct bau_control *bcp,
struct bau_control *hmaster, struct ptc_stats *stat)
{
udelay(bcp->plugged_delay);
bcp->plugged_tries++;
if (bcp->plugged_tries >= bcp->plugsb4reset) {
bcp->plugged_tries = 0;
quiesce_local_uvhub(hmaster);
spin_lock(&hmaster->queue_lock);
reset_with_ipi(&bau_desc->distribution, bcp);
spin_unlock(&hmaster->queue_lock);
end_uvhub_quiesce(hmaster);
bcp->ipi_attempts++;
stat->s_resets_plug++;
}
}
static void destination_timeout(struct bau_desc *bau_desc,
struct bau_control *bcp, struct bau_control *hmaster,
struct ptc_stats *stat)
{
hmaster->max_concurr = 1;
bcp->timeout_tries++;
if (bcp->timeout_tries >= bcp->timeoutsb4reset) {
bcp->timeout_tries = 0;
quiesce_local_uvhub(hmaster);
spin_lock(&hmaster->queue_lock);
reset_with_ipi(&bau_desc->distribution, bcp);
spin_unlock(&hmaster->queue_lock);
end_uvhub_quiesce(hmaster);
bcp->ipi_attempts++;
stat->s_resets_timeout++;
}
}
static void disable_for_congestion(struct bau_control *bcp,
struct ptc_stats *stat)
{
spin_lock(&disable_lock);
if (!baudisabled && bcp->period_requests &&
((bcp->period_time / bcp->period_requests) > congested_cycles)) {
int tcpu;
struct bau_control *tbcp;
baudisabled = 1;
bcp->set_bau_off = 1;
bcp->set_bau_on_time = get_cycles();
bcp->set_bau_on_time += sec_2_cycles(bcp->cong_period);
stat->s_bau_disabled++;
for_each_present_cpu(tcpu) {
tbcp = &per_cpu(bau_control, tcpu);
tbcp->baudisabled = 1;
}
}
spin_unlock(&disable_lock);
}
static void count_max_concurr(int stat, struct bau_control *bcp,
struct bau_control *hmaster)
{
bcp->plugged_tries = 0;
bcp->timeout_tries = 0;
if (stat != FLUSH_COMPLETE)
return;
if (bcp->conseccompletes <= bcp->complete_threshold)
return;
if (hmaster->max_concurr >= hmaster->max_concurr_const)
return;
hmaster->max_concurr++;
}
static void record_send_stats(cycles_t time1, cycles_t time2,
struct bau_control *bcp, struct ptc_stats *stat,
int completion_status, int try)
{
cycles_t elapsed;
if (time2 > time1) {
elapsed = time2 - time1;
stat->s_time += elapsed;
if ((completion_status == FLUSH_COMPLETE) && (try == 1)) {
bcp->period_requests++;
bcp->period_time += elapsed;
if ((elapsed > congested_cycles) &&
(bcp->period_requests > bcp->cong_reps))
disable_for_congestion(bcp, stat);
}
} else
stat->s_requestor--;
if (completion_status == FLUSH_COMPLETE && try > 1)
stat->s_retriesok++;
else if (completion_status == FLUSH_GIVEUP)
stat->s_giveup++;
}
static void uv1_throttle(struct bau_control *hmaster, struct ptc_stats *stat)
{
spinlock_t *lock = &hmaster->uvhub_lock;
atomic_t *v;
v = &hmaster->active_descriptor_count;
if (!atomic_inc_unless_ge(lock, v, hmaster->max_concurr)) {
stat->s_throttles++;
do {
cpu_relax();
} while (!atomic_inc_unless_ge(lock, v, hmaster->max_concurr));
}
}
static void handle_cmplt(int completion_status, struct bau_desc *bau_desc,
struct bau_control *bcp, struct bau_control *hmaster,
struct ptc_stats *stat)
{
if (completion_status == FLUSH_RETRY_PLUGGED)
destination_plugged(bau_desc, bcp, hmaster, stat);
else if (completion_status == FLUSH_RETRY_TIMEOUT)
destination_timeout(bau_desc, bcp, hmaster, stat);
}
int uv_flush_send_and_wait(struct bau_desc *bau_desc,
struct cpumask *flush_mask, struct bau_control *bcp)
{
int seq_number = 0;
int completion_stat = 0;
long try = 0;
unsigned long index;
cycles_t time1;
cycles_t time2;
struct ptc_stats *stat = bcp->statp;
struct bau_control *hmaster = bcp->uvhub_master;
if (is_uv1_hub())
uv1_throttle(hmaster, stat);
while (hmaster->uvhub_quiesce)
cpu_relax();
time1 = get_cycles();
do {
if (try == 0) {
bau_desc->header.msg_type = MSG_REGULAR;
seq_number = bcp->message_number++;
} else {
bau_desc->header.msg_type = MSG_RETRY;
stat->s_retry_messages++;
}
bau_desc->header.sequence = seq_number;
index = (1UL << AS_PUSH_SHIFT) | bcp->uvhub_cpu;
bcp->send_message = get_cycles();
write_mmr_activation(index);
try++;
completion_stat = wait_completion(bau_desc, bcp, try);
handle_cmplt(completion_stat, bau_desc, bcp, hmaster, stat);
if (bcp->ipi_attempts >= bcp->ipi_reset_limit) {
bcp->ipi_attempts = 0;
completion_stat = FLUSH_GIVEUP;
break;
}
cpu_relax();
} while ((completion_stat == FLUSH_RETRY_PLUGGED) ||
(completion_stat == FLUSH_RETRY_TIMEOUT));
time2 = get_cycles();
count_max_concurr(completion_stat, bcp, hmaster);
while (hmaster->uvhub_quiesce)
cpu_relax();
atomic_dec(&hmaster->active_descriptor_count);
record_send_stats(time1, time2, bcp, stat, completion_stat, try);
if (completion_stat == FLUSH_GIVEUP)
return 1;
return 0;
}
static int check_enable(struct bau_control *bcp, struct ptc_stats *stat)
{
int tcpu;
struct bau_control *tbcp;
if (bcp->set_bau_off) {
if (get_cycles() >= bcp->set_bau_on_time) {
stat->s_bau_reenabled++;
baudisabled = 0;
for_each_present_cpu(tcpu) {
tbcp = &per_cpu(bau_control, tcpu);
tbcp->baudisabled = 0;
tbcp->period_requests = 0;
tbcp->period_time = 0;
}
return 0;
}
}
return -1;
}
static void record_send_statistics(struct ptc_stats *stat, int locals, int hubs,
int remotes, struct bau_desc *bau_desc)
{
stat->s_requestor++;
stat->s_ntargcpu += remotes + locals;
stat->s_ntargremotes += remotes;
stat->s_ntarglocals += locals;
hubs = bau_uvhub_weight(&bau_desc->distribution);
if (locals) {
stat->s_ntarglocaluvhub++;
stat->s_ntargremoteuvhub += (hubs - 1);
} else
stat->s_ntargremoteuvhub += hubs;
stat->s_ntarguvhub += hubs;
if (hubs >= 16)
stat->s_ntarguvhub16++;
else if (hubs >= 8)
stat->s_ntarguvhub8++;
else if (hubs >= 4)
stat->s_ntarguvhub4++;
else if (hubs >= 2)
stat->s_ntarguvhub2++;
else
stat->s_ntarguvhub1++;
}
static int set_distrib_bits(struct cpumask *flush_mask, struct bau_control *bcp,
struct bau_desc *bau_desc, int *localsp, int *remotesp)
{
int cpu;
int pnode;
int cnt = 0;
struct hub_and_pnode *hpp;
for_each_cpu(cpu, flush_mask) {
hpp = &bcp->socket_master->thp[cpu];
pnode = hpp->pnode - bcp->partition_base_pnode;
bau_uvhub_set(pnode, &bau_desc->distribution);
cnt++;
if (hpp->uvhub == bcp->uvhub)
(*localsp)++;
else
(*remotesp)++;
}
if (!cnt)
return 1;
return 0;
}
const struct cpumask *uv_flush_tlb_others(const struct cpumask *cpumask,
struct mm_struct *mm, unsigned long va,
unsigned int cpu)
{
int locals = 0;
int remotes = 0;
int hubs = 0;
struct bau_desc *bau_desc;
struct cpumask *flush_mask;
struct ptc_stats *stat;
struct bau_control *bcp;
if (nobau)
return cpumask;
bcp = &per_cpu(bau_control, cpu);
stat = bcp->statp;
if (bcp->baudisabled) {
if (check_enable(bcp, stat))
return cpumask;
}
flush_mask = (struct cpumask *)per_cpu(uv_flush_tlb_mask, cpu);
cpumask_andnot(flush_mask, cpumask, cpumask_of(cpu));
if (cpu_isset(cpu, *cpumask))
stat->s_ntargself++;
bau_desc = bcp->descriptor_base;
bau_desc += ITEMS_PER_DESC * bcp->uvhub_cpu;
bau_uvhubs_clear(&bau_desc->distribution, UV_DISTRIBUTION_SIZE);
if (set_distrib_bits(flush_mask, bcp, bau_desc, &locals, &remotes))
return NULL;
record_send_statistics(stat, locals, hubs, remotes, bau_desc);
bau_desc->payload.address = va;
bau_desc->payload.sending_cpu = cpu;
if (!uv_flush_send_and_wait(bau_desc, flush_mask, bcp))
return NULL;
else
return cpumask;
}
void uv_bau_message_interrupt(struct pt_regs *regs)
{
int count = 0;
cycles_t time_start;
struct bau_pq_entry *msg;
struct bau_control *bcp;
struct ptc_stats *stat;
struct msg_desc msgdesc;
time_start = get_cycles();
bcp = &per_cpu(bau_control, smp_processor_id());
stat = bcp->statp;
msgdesc.queue_first = bcp->queue_first;
msgdesc.queue_last = bcp->queue_last;
msg = bcp->bau_msg_head;
while (msg->swack_vec) {
count++;
msgdesc.msg_slot = msg - msgdesc.queue_first;
msgdesc.swack_slot = ffs(msg->swack_vec) - 1;
msgdesc.msg = msg;
bau_process_message(&msgdesc, bcp);
msg++;
if (msg > msgdesc.queue_last)
msg = msgdesc.queue_first;
bcp->bau_msg_head = msg;
}
stat->d_time += (get_cycles() - time_start);
if (!count)
stat->d_nomsg++;
else if (count > 1)
stat->d_multmsg++;
ack_APIC_irq();
}
static void __init enable_timeouts(void)
{
int uvhub;
int nuvhubs;
int pnode;
unsigned long mmr_image;
nuvhubs = uv_num_possible_blades();
for (uvhub = 0; uvhub < nuvhubs; uvhub++) {
if (!uv_blade_nr_possible_cpus(uvhub))
continue;
pnode = uv_blade_to_pnode(uvhub);
mmr_image = read_mmr_misc_control(pnode);
mmr_image &= ~(1L << SOFTACK_MSHIFT);
write_mmr_misc_control(pnode, mmr_image);
mmr_image &= ~((unsigned long)0xf << SOFTACK_PSHIFT);
mmr_image |= (SOFTACK_TIMEOUT_PERIOD << SOFTACK_PSHIFT);
write_mmr_misc_control(pnode, mmr_image);
mmr_image |= (1L << SOFTACK_MSHIFT);
if (is_uv2_hub()) {
mmr_image |= (1L << UV2_LEG_SHFT);
mmr_image |= (1L << UV2_EXT_SHFT);
}
write_mmr_misc_control(pnode, mmr_image);
}
}
static void *ptc_seq_start(struct seq_file *file, loff_t *offset)
{
if (*offset < num_possible_cpus())
return offset;
return NULL;
}
static void *ptc_seq_next(struct seq_file *file, void *data, loff_t *offset)
{
(*offset)++;
if (*offset < num_possible_cpus())
return offset;
return NULL;
}
static void ptc_seq_stop(struct seq_file *file, void *data)
{
}
static inline unsigned long long usec_2_cycles(unsigned long microsec)
{
unsigned long ns;
unsigned long long cyc;
ns = microsec * 1000;
cyc = (ns << CYC2NS_SCALE_FACTOR)/(per_cpu(cyc2ns, smp_processor_id()));
return cyc;
}
static int ptc_seq_show(struct seq_file *file, void *data)
{
struct ptc_stats *stat;
int cpu;
cpu = *(loff_t *)data;
if (!cpu) {
seq_printf(file,
"# cpu sent stime self locals remotes ncpus localhub ");
seq_printf(file,
"remotehub numuvhubs numuvhubs16 numuvhubs8 ");
seq_printf(file,
"numuvhubs4 numuvhubs2 numuvhubs1 dto retries rok ");
seq_printf(file,
"resetp resett giveup sto bz throt swack recv rtime ");
seq_printf(file,
"all one mult none retry canc nocan reset rcan ");
seq_printf(file,
"disable enable\n");
}
if (cpu < num_possible_cpus() && cpu_online(cpu)) {
stat = &per_cpu(ptcstats, cpu);
seq_printf(file,
"cpu %d %ld %ld %ld %ld %ld %ld %ld %ld %ld %ld ",
cpu, stat->s_requestor, cycles_2_us(stat->s_time),
stat->s_ntargself, stat->s_ntarglocals,
stat->s_ntargremotes, stat->s_ntargcpu,
stat->s_ntarglocaluvhub, stat->s_ntargremoteuvhub,
stat->s_ntarguvhub, stat->s_ntarguvhub16);
seq_printf(file, "%ld %ld %ld %ld %ld ",
stat->s_ntarguvhub8, stat->s_ntarguvhub4,
stat->s_ntarguvhub2, stat->s_ntarguvhub1,
stat->s_dtimeout);
seq_printf(file, "%ld %ld %ld %ld %ld %ld %ld %ld ",
stat->s_retry_messages, stat->s_retriesok,
stat->s_resets_plug, stat->s_resets_timeout,
stat->s_giveup, stat->s_stimeout,
stat->s_busy, stat->s_throttles);
seq_printf(file,
"%lx %ld %ld %ld %ld %ld %ld %ld %ld %ld %ld %ld ",
read_gmmr_sw_ack(uv_cpu_to_pnode(cpu)),
stat->d_requestee, cycles_2_us(stat->d_time),
stat->d_alltlb, stat->d_onetlb, stat->d_multmsg,
stat->d_nomsg, stat->d_retries, stat->d_canceled,
stat->d_nocanceled, stat->d_resets,
stat->d_rcanceled);
seq_printf(file, "%ld %ld\n",
stat->s_bau_disabled, stat->s_bau_reenabled);
}
return 0;
}
static ssize_t tunables_read(struct file *file, char __user *userbuf,
size_t count, loff_t *ppos)
{
char *buf;
int ret;
buf = kasprintf(GFP_KERNEL, "%s %s %s\n%d %d %d %d %d %d %d %d %d\n",
"max_concur plugged_delay plugsb4reset",
"timeoutsb4reset ipi_reset_limit complete_threshold",
"congested_response_us congested_reps congested_period",
max_concurr, plugged_delay, plugsb4reset,
timeoutsb4reset, ipi_reset_limit, complete_threshold,
congested_respns_us, congested_reps, congested_period);
if (!buf)
return -ENOMEM;
ret = simple_read_from_buffer(userbuf, count, ppos, buf, strlen(buf));
kfree(buf);
return ret;
}
static ssize_t ptc_proc_write(struct file *file, const char __user *user,
size_t count, loff_t *data)
{
int cpu;
int i;
int elements;
long input_arg;
char optstr[64];
struct ptc_stats *stat;
if (count == 0 || count > sizeof(optstr))
return -EINVAL;
if (copy_from_user(optstr, user, count))
return -EFAULT;
optstr[count - 1] = '\0';
if (strict_strtol(optstr, 10, &input_arg) < 0) {
printk(KERN_DEBUG "%s is invalid\n", optstr);
return -EINVAL;
}
if (input_arg == 0) {
elements = sizeof(stat_description)/sizeof(*stat_description);
printk(KERN_DEBUG "# cpu: cpu number\n");
printk(KERN_DEBUG "Sender statistics:\n");
for (i = 0; i < elements; i++)
printk(KERN_DEBUG "%s\n", stat_description[i]);
} else if (input_arg == -1) {
for_each_present_cpu(cpu) {
stat = &per_cpu(ptcstats, cpu);
memset(stat, 0, sizeof(struct ptc_stats));
}
}
return count;
}
static int local_atoi(const char *name)
{
int val = 0;
for (;; name++) {
switch (*name) {
case '0' ... '9':
val = 10*val+(*name-'0');
break;
default:
return val;
}
}
}
static int parse_tunables_write(struct bau_control *bcp, char *instr,
int count)
{
char *p;
char *q;
int cnt = 0;
int val;
int e = sizeof(tunables) / sizeof(*tunables);
p = instr + strspn(instr, WHITESPACE);
q = p;
for (; *p; p = q + strspn(q, WHITESPACE)) {
q = p + strcspn(p, WHITESPACE);
cnt++;
if (q == p)
break;
}
if (cnt != e) {
printk(KERN_INFO "bau tunable error: should be %d values\n", e);
return -EINVAL;
}
p = instr + strspn(instr, WHITESPACE);
q = p;
for (cnt = 0; *p; p = q + strspn(q, WHITESPACE), cnt++) {
q = p + strcspn(p, WHITESPACE);
val = local_atoi(p);
switch (cnt) {
case 0:
if (val == 0) {
max_concurr = MAX_BAU_CONCURRENT;
max_concurr_const = MAX_BAU_CONCURRENT;
continue;
}
if (val < 1 || val > bcp->cpus_in_uvhub) {
printk(KERN_DEBUG
"Error: BAU max concurrent %d is invalid\n",
val);
return -EINVAL;
}
max_concurr = val;
max_concurr_const = val;
continue;
default:
if (val == 0)
*tunables[cnt].tunp = tunables[cnt].deflt;
else
*tunables[cnt].tunp = val;
continue;
}
if (q == p)
break;
}
return 0;
}
static ssize_t tunables_write(struct file *file, const char __user *user,
size_t count, loff_t *data)
{
int cpu;
int ret;
char instr[100];
struct bau_control *bcp;
if (count == 0 || count > sizeof(instr)-1)
return -EINVAL;
if (copy_from_user(instr, user, count))
return -EFAULT;
instr[count] = '\0';
cpu = get_cpu();
bcp = &per_cpu(bau_control, cpu);
ret = parse_tunables_write(bcp, instr, count);
put_cpu();
if (ret)
return ret;
for_each_present_cpu(cpu) {
bcp = &per_cpu(bau_control, cpu);
bcp->max_concurr = max_concurr;
bcp->max_concurr_const = max_concurr;
bcp->plugged_delay = plugged_delay;
bcp->plugsb4reset = plugsb4reset;
bcp->timeoutsb4reset = timeoutsb4reset;
bcp->ipi_reset_limit = ipi_reset_limit;
bcp->complete_threshold = complete_threshold;
bcp->cong_response_us = congested_respns_us;
bcp->cong_reps = congested_reps;
bcp->cong_period = congested_period;
}
return count;
}
static int ptc_proc_open(struct inode *inode, struct file *file)
{
return seq_open(file, &uv_ptc_seq_ops);
}
static int tunables_open(struct inode *inode, struct file *file)
{
return 0;
}
static int __init uv_ptc_init(void)
{
struct proc_dir_entry *proc_uv_ptc;
if (!is_uv_system())
return 0;
proc_uv_ptc = proc_create(UV_PTC_BASENAME, 0444, NULL,
&proc_uv_ptc_operations);
if (!proc_uv_ptc) {
printk(KERN_ERR "unable to create %s proc entry\n",
UV_PTC_BASENAME);
return -EINVAL;
}
tunables_dir = debugfs_create_dir(UV_BAU_TUNABLES_DIR, NULL);
if (!tunables_dir) {
printk(KERN_ERR "unable to create debugfs directory %s\n",
UV_BAU_TUNABLES_DIR);
return -EINVAL;
}
tunables_file = debugfs_create_file(UV_BAU_TUNABLES_FILE, 0600,
tunables_dir, NULL, &tunables_fops);
if (!tunables_file) {
printk(KERN_ERR "unable to create debugfs file %s\n",
UV_BAU_TUNABLES_FILE);
return -EINVAL;
}
return 0;
}
static void activation_descriptor_init(int node, int pnode, int base_pnode)
{
int i;
int cpu;
unsigned long pa;
unsigned long m;
unsigned long n;
size_t dsize;
struct bau_desc *bau_desc;
struct bau_desc *bd2;
struct bau_control *bcp;
dsize = sizeof(struct bau_desc) * ADP_SZ * ITEMS_PER_DESC;
bau_desc = kmalloc_node(dsize, GFP_KERNEL, node);
BUG_ON(!bau_desc);
pa = uv_gpa(bau_desc);
n = pa >> uv_nshift;
m = pa & uv_mmask;
write_mmr_descriptor_base(pnode, (n << UV_DESC_PSHIFT | m));
for (i = 0, bd2 = bau_desc; i < (ADP_SZ * ITEMS_PER_DESC); i++, bd2++) {
memset(bd2, 0, sizeof(struct bau_desc));
bd2->header.swack_flag = 1;
bd2->header.base_dest_nasid = UV_PNODE_TO_NASID(base_pnode);
bd2->header.dest_subnodeid = UV_LB_SUBNODEID;
bd2->header.command = UV_NET_ENDPOINT_INTD;
bd2->header.int_both = 1;
}
for_each_present_cpu(cpu) {
if (pnode != uv_blade_to_pnode(uv_cpu_to_blade_id(cpu)))
continue;
bcp = &per_cpu(bau_control, cpu);
bcp->descriptor_base = bau_desc;
}
}
static void pq_init(int node, int pnode)
{
int cpu;
size_t plsize;
char *cp;
void *vp;
unsigned long pn;
unsigned long first;
unsigned long pn_first;
unsigned long last;
struct bau_pq_entry *pqp;
struct bau_control *bcp;
plsize = (DEST_Q_SIZE + 1) * sizeof(struct bau_pq_entry);
vp = kmalloc_node(plsize, GFP_KERNEL, node);
pqp = (struct bau_pq_entry *)vp;
BUG_ON(!pqp);
cp = (char *)pqp + 31;
pqp = (struct bau_pq_entry *)(((unsigned long)cp >> 5) << 5);
for_each_present_cpu(cpu) {
if (pnode != uv_cpu_to_pnode(cpu))
continue;
bcp = &per_cpu(bau_control, cpu);
bcp->queue_first = pqp;
bcp->bau_msg_head = pqp;
bcp->queue_last = pqp + (DEST_Q_SIZE - 1);
}
pn = uv_gpa(pqp) >> uv_nshift;
first = uv_physnodeaddr(pqp);
pn_first = ((unsigned long)pn << UV_PAYLOADQ_PNODE_SHIFT) | first;
last = uv_physnodeaddr(pqp + (DEST_Q_SIZE - 1));
write_mmr_payload_first(pnode, pn_first);
write_mmr_payload_tail(pnode, first);
write_mmr_payload_last(pnode, last);
memset(pqp, 0, sizeof(struct bau_pq_entry) * DEST_Q_SIZE);
}
static void __init init_uvhub(int uvhub, int vector, int base_pnode)
{
int node;
int pnode;
unsigned long apicid;
node = uvhub_to_first_node(uvhub);
pnode = uv_blade_to_pnode(uvhub);
activation_descriptor_init(node, pnode, base_pnode);
pq_init(node, pnode);
apicid = uvhub_to_first_apicid(uvhub) | uv_apicid_hibits;
write_mmr_data_config(pnode, ((apicid << 32) | vector));
}
static int calculate_destination_timeout(void)
{
unsigned long mmr_image;
int mult1;
int mult2;
int index;
int base;
int ret;
unsigned long ts_ns;
if (is_uv1_hub()) {
mult1 = SOFTACK_TIMEOUT_PERIOD & BAU_MISC_CONTROL_MULT_MASK;
mmr_image = uv_read_local_mmr(UVH_AGING_PRESCALE_SEL);
index = (mmr_image >> BAU_URGENCY_7_SHIFT) & BAU_URGENCY_7_MASK;
mmr_image = uv_read_local_mmr(UVH_TRANSACTION_TIMEOUT);
mult2 = (mmr_image >> BAU_TRANS_SHIFT) & BAU_TRANS_MASK;
base = timeout_base_ns[index];
ts_ns = base * mult1 * mult2;
ret = ts_ns / 1000;
} else {
mmr_image = uv_read_local_mmr(UVH_AGING_PRESCALE_SEL);
mmr_image = (mmr_image & UV_SA_MASK) >> UV_SA_SHFT;
if (mmr_image & (1L << UV2_ACK_UNITS_SHFT))
mult1 = 80;
else
mult1 = 10;
base = mmr_image & UV2_ACK_MASK;
ret = mult1 * base;
}
return ret;
}
static void __init init_per_cpu_tunables(void)
{
int cpu;
struct bau_control *bcp;
for_each_present_cpu(cpu) {
bcp = &per_cpu(bau_control, cpu);
bcp->baudisabled = 0;
bcp->statp = &per_cpu(ptcstats, cpu);
bcp->timeout_interval = usec_2_cycles(2*timeout_us);
bcp->max_concurr = max_concurr;
bcp->max_concurr_const = max_concurr;
bcp->plugged_delay = plugged_delay;
bcp->plugsb4reset = plugsb4reset;
bcp->timeoutsb4reset = timeoutsb4reset;
bcp->ipi_reset_limit = ipi_reset_limit;
bcp->complete_threshold = complete_threshold;
bcp->cong_response_us = congested_respns_us;
bcp->cong_reps = congested_reps;
bcp->cong_period = congested_period;
}
}
static int __init get_cpu_topology(int base_pnode,
struct uvhub_desc *uvhub_descs,
unsigned char *uvhub_mask)
{
int cpu;
int pnode;
int uvhub;
int socket;
struct bau_control *bcp;
struct uvhub_desc *bdp;
struct socket_desc *sdp;
for_each_present_cpu(cpu) {
bcp = &per_cpu(bau_control, cpu);
memset(bcp, 0, sizeof(struct bau_control));
pnode = uv_cpu_hub_info(cpu)->pnode;
if ((pnode - base_pnode) >= UV_DISTRIBUTION_SIZE) {
printk(KERN_EMERG
"cpu %d pnode %d-%d beyond %d; BAU disabled\n",
cpu, pnode, base_pnode, UV_DISTRIBUTION_SIZE);
return 1;
}
bcp->osnode = cpu_to_node(cpu);
bcp->partition_base_pnode = base_pnode;
uvhub = uv_cpu_hub_info(cpu)->numa_blade_id;
*(uvhub_mask + (uvhub/8)) |= (1 << (uvhub%8));
bdp = &uvhub_descs[uvhub];
bdp->num_cpus++;
bdp->uvhub = uvhub;
bdp->pnode = pnode;
socket = bcp->osnode & 1;
bdp->socket_mask |= (1 << socket);
sdp = &bdp->socket[socket];
sdp->cpu_number[sdp->num_cpus] = cpu;
sdp->num_cpus++;
if (sdp->num_cpus > MAX_CPUS_PER_SOCKET) {
printk(KERN_EMERG "%d cpus per socket invalid\n",
sdp->num_cpus);
return 1;
}
}
return 0;
}
static void make_per_cpu_thp(struct bau_control *smaster)
{
int cpu;
size_t hpsz = sizeof(struct hub_and_pnode) * num_possible_cpus();
smaster->thp = kmalloc_node(hpsz, GFP_KERNEL, smaster->osnode);
memset(smaster->thp, 0, hpsz);
for_each_present_cpu(cpu) {
smaster->thp[cpu].pnode = uv_cpu_hub_info(cpu)->pnode;
smaster->thp[cpu].uvhub = uv_cpu_hub_info(cpu)->numa_blade_id;
}
}
static void make_per_hub_cpumask(struct bau_control *hmaster)
{
int sz = sizeof(cpumask_t);
hmaster->cpumask = kzalloc_node(sz, GFP_KERNEL, hmaster->osnode);
}
static int scan_sock(struct socket_desc *sdp, struct uvhub_desc *bdp,
struct bau_control **smasterp,
struct bau_control **hmasterp)
{
int i;
int cpu;
struct bau_control *bcp;
for (i = 0; i < sdp->num_cpus; i++) {
cpu = sdp->cpu_number[i];
bcp = &per_cpu(bau_control, cpu);
bcp->cpu = cpu;
if (i == 0) {
*smasterp = bcp;
if (!(*hmasterp))
*hmasterp = bcp;
}
bcp->cpus_in_uvhub = bdp->num_cpus;
bcp->cpus_in_socket = sdp->num_cpus;
bcp->socket_master = *smasterp;
bcp->uvhub = bdp->uvhub;
bcp->uvhub_master = *hmasterp;
bcp->uvhub_cpu = uv_cpu_hub_info(cpu)->blade_processor_id;
if (bcp->uvhub_cpu >= MAX_CPUS_PER_UVHUB) {
printk(KERN_EMERG "%d cpus per uvhub invalid\n",
bcp->uvhub_cpu);
return 1;
}
}
return 0;
}
static int __init summarize_uvhub_sockets(int nuvhubs,
struct uvhub_desc *uvhub_descs,
unsigned char *uvhub_mask)
{
int socket;
int uvhub;
unsigned short socket_mask;
for (uvhub = 0; uvhub < nuvhubs; uvhub++) {
struct uvhub_desc *bdp;
struct bau_control *smaster = NULL;
struct bau_control *hmaster = NULL;
if (!(*(uvhub_mask + (uvhub/8)) & (1 << (uvhub%8))))
continue;
bdp = &uvhub_descs[uvhub];
socket_mask = bdp->socket_mask;
socket = 0;
while (socket_mask) {
struct socket_desc *sdp;
if ((socket_mask & 1)) {
sdp = &bdp->socket[socket];
if (scan_sock(sdp, bdp, &smaster, &hmaster))
return 1;
make_per_cpu_thp(smaster);
}
socket++;
socket_mask = (socket_mask >> 1);
}
make_per_hub_cpumask(hmaster);
}
return 0;
}
static int __init init_per_cpu(int nuvhubs, int base_part_pnode)
{
unsigned char *uvhub_mask;
void *vp;
struct uvhub_desc *uvhub_descs;
timeout_us = calculate_destination_timeout();
vp = kmalloc(nuvhubs * sizeof(struct uvhub_desc), GFP_KERNEL);
uvhub_descs = (struct uvhub_desc *)vp;
memset(uvhub_descs, 0, nuvhubs * sizeof(struct uvhub_desc));
uvhub_mask = kzalloc((nuvhubs+7)/8, GFP_KERNEL);
if (get_cpu_topology(base_part_pnode, uvhub_descs, uvhub_mask))
goto fail;
if (summarize_uvhub_sockets(nuvhubs, uvhub_descs, uvhub_mask))
goto fail;
kfree(uvhub_descs);
kfree(uvhub_mask);
init_per_cpu_tunables();
return 0;
fail:
kfree(uvhub_descs);
kfree(uvhub_mask);
return 1;
}
static int __init uv_bau_init(void)
{
int uvhub;
int pnode;
int nuvhubs;
int cur_cpu;
int cpus;
int vector;
cpumask_var_t *mask;
if (!is_uv_system())
return 0;
if (nobau)
return 0;
for_each_possible_cpu(cur_cpu) {
mask = &per_cpu(uv_flush_tlb_mask, cur_cpu);
zalloc_cpumask_var_node(mask, GFP_KERNEL, cpu_to_node(cur_cpu));
}
uv_nshift = uv_hub_info->m_val;
uv_mmask = (1UL << uv_hub_info->m_val) - 1;
nuvhubs = uv_num_possible_blades();
spin_lock_init(&disable_lock);
congested_cycles = usec_2_cycles(congested_respns_us);
uv_base_pnode = 0x7fffffff;
for (uvhub = 0; uvhub < nuvhubs; uvhub++) {
cpus = uv_blade_nr_possible_cpus(uvhub);
if (cpus && (uv_blade_to_pnode(uvhub) < uv_base_pnode))
uv_base_pnode = uv_blade_to_pnode(uvhub);
}
if (init_per_cpu(nuvhubs, uv_base_pnode)) {
nobau = 1;
return 0;
}
vector = UV_BAU_MESSAGE;
for_each_possible_blade(uvhub)
if (uv_blade_nr_possible_cpus(uvhub))
init_uvhub(uvhub, vector, uv_base_pnode);
enable_timeouts();
alloc_intr_gate(vector, uv_bau_message_intr1);
for_each_possible_blade(uvhub) {
if (uv_blade_nr_possible_cpus(uvhub)) {
unsigned long val;
unsigned long mmr;
pnode = uv_blade_to_pnode(uvhub);
val = 1L << 63;
write_gmmr_activation(pnode, val);
mmr = 1;
write_mmr_data_broadcast(pnode, mmr);
}
}
return 0;
}
