static ssize_t show_feedback_ctrs(struct kobject *kobj,
struct attribute *attr, char *buf)
{
struct cpc_desc *cpc_ptr = to_cpc_desc(kobj);
struct cppc_perf_fb_ctrs fb_ctrs = {0};
cppc_get_perf_ctrs(cpc_ptr->cpu_id, &fb_ctrs);
return scnprintf(buf, PAGE_SIZE, "ref:%llu del:%llu\n",
fb_ctrs.reference, fb_ctrs.delivered);
}
static ssize_t show_reference_perf(struct kobject *kobj,
struct attribute *attr, char *buf)
{
struct cpc_desc *cpc_ptr = to_cpc_desc(kobj);
struct cppc_perf_fb_ctrs fb_ctrs = {0};
cppc_get_perf_ctrs(cpc_ptr->cpu_id, &fb_ctrs);
return scnprintf(buf, PAGE_SIZE, "%llu\n",
fb_ctrs.reference_perf);
}
static ssize_t show_wraparound_time(struct kobject *kobj,
struct attribute *attr, char *buf)
{
struct cpc_desc *cpc_ptr = to_cpc_desc(kobj);
struct cppc_perf_fb_ctrs fb_ctrs = {0};
cppc_get_perf_ctrs(cpc_ptr->cpu_id, &fb_ctrs);
return scnprintf(buf, PAGE_SIZE, "%llu\n", fb_ctrs.ctr_wrap_time);
}
static int check_pcc_chan(bool chk_err_bit)
{
int ret = -EIO, status = 0;
struct acpi_pcct_shared_memory __iomem *generic_comm_base = pcc_data.pcc_comm_addr;
ktime_t next_deadline = ktime_add(ktime_get(), pcc_data.deadline);
if (!pcc_data.platform_owns_pcc)
return 0;
while (!ktime_after(ktime_get(), next_deadline)) {
status = readw_relaxed(&generic_comm_base->status);
if (status & PCC_CMD_COMPLETE_MASK) {
ret = 0;
if (chk_err_bit && (status & PCC_ERROR_MASK))
ret = -EIO;
break;
}
udelay(3);
}
if (likely(!ret))
pcc_data.platform_owns_pcc = false;
else
pr_err("PCC check channel failed. Status=%x\n", status);
return ret;
}
static int send_pcc_cmd(u16 cmd)
{
int ret = -EIO, i;
struct acpi_pcct_shared_memory *generic_comm_base =
(struct acpi_pcct_shared_memory *) pcc_data.pcc_comm_addr;
static ktime_t last_cmd_cmpl_time, last_mpar_reset;
static int mpar_count;
unsigned int time_delta;
if (cmd == CMD_READ) {
if (pcc_data.pending_pcc_write_cmd)
send_pcc_cmd(CMD_WRITE);
ret = check_pcc_chan(false);
if (ret)
goto end;
} else
pcc_data.pending_pcc_write_cmd = FALSE;
if (pcc_data.pcc_mrtt) {
time_delta = ktime_us_delta(ktime_get(), last_cmd_cmpl_time);
if (pcc_data.pcc_mrtt > time_delta)
udelay(pcc_data.pcc_mrtt - time_delta);
}
if (pcc_data.pcc_mpar) {
if (mpar_count == 0) {
time_delta = ktime_ms_delta(ktime_get(), last_mpar_reset);
if (time_delta < 60 * MSEC_PER_SEC) {
pr_debug("PCC cmd not sent due to MPAR limit");
ret = -EIO;
goto end;
}
last_mpar_reset = ktime_get();
mpar_count = pcc_data.pcc_mpar;
}
mpar_count--;
}
writew_relaxed(cmd, &generic_comm_base->command);
writew_relaxed(0, &generic_comm_base->status);
pcc_data.platform_owns_pcc = true;
ret = mbox_send_message(pcc_data.pcc_channel, &cmd);
if (ret < 0) {
pr_err("Err sending PCC mbox message. cmd:%d, ret:%d\n",
cmd, ret);
goto end;
}
ret = check_pcc_chan(true);
if (pcc_data.pcc_mrtt)
last_cmd_cmpl_time = ktime_get();
if (pcc_data.pcc_channel->mbox->txdone_irq)
mbox_chan_txdone(pcc_data.pcc_channel, ret);
else
mbox_client_txdone(pcc_data.pcc_channel, ret);
end:
if (cmd == CMD_WRITE) {
if (unlikely(ret)) {
for_each_possible_cpu(i) {
struct cpc_desc *desc = per_cpu(cpc_desc_ptr, i);
if (!desc)
continue;
if (desc->write_cmd_id == pcc_data.pcc_write_cnt)
desc->write_cmd_status = ret;
}
}
pcc_data.pcc_write_cnt++;
wake_up_all(&pcc_data.pcc_write_wait_q);
}
return ret;
}
static void cppc_chan_tx_done(struct mbox_client *cl, void *msg, int ret)
{
if (ret < 0)
pr_debug("TX did not complete: CMD sent:%x, ret:%d\n",
*(u16 *)msg, ret);
else
pr_debug("TX completed. CMD sent:%x, ret:%d\n",
*(u16 *)msg, ret);
}
static int acpi_get_psd(struct cpc_desc *cpc_ptr, acpi_handle handle)
{
int result = -EFAULT;
acpi_status status = AE_OK;
struct acpi_buffer buffer = {ACPI_ALLOCATE_BUFFER, NULL};
struct acpi_buffer format = {sizeof("NNNNN"), "NNNNN"};
struct acpi_buffer state = {0, NULL};
union acpi_object *psd = NULL;
struct acpi_psd_package *pdomain;
status = acpi_evaluate_object_typed(handle, "_PSD", NULL, &buffer,
ACPI_TYPE_PACKAGE);
if (ACPI_FAILURE(status))
return -ENODEV;
psd = buffer.pointer;
if (!psd || psd->package.count != 1) {
pr_debug("Invalid _PSD data\n");
goto end;
}
pdomain = &(cpc_ptr->domain_info);
state.length = sizeof(struct acpi_psd_package);
state.pointer = pdomain;
status = acpi_extract_package(&(psd->package.elements[0]),
&format, &state);
if (ACPI_FAILURE(status)) {
pr_debug("Invalid _PSD data for CPU:%d\n", cpc_ptr->cpu_id);
goto end;
}
if (pdomain->num_entries != ACPI_PSD_REV0_ENTRIES) {
pr_debug("Unknown _PSD:num_entries for CPU:%d\n", cpc_ptr->cpu_id);
goto end;
}
if (pdomain->revision != ACPI_PSD_REV0_REVISION) {
pr_debug("Unknown _PSD:revision for CPU: %d\n", cpc_ptr->cpu_id);
goto end;
}
if (pdomain->coord_type != DOMAIN_COORD_TYPE_SW_ALL &&
pdomain->coord_type != DOMAIN_COORD_TYPE_SW_ANY &&
pdomain->coord_type != DOMAIN_COORD_TYPE_HW_ALL) {
pr_debug("Invalid _PSD:coord_type for CPU:%d\n", cpc_ptr->cpu_id);
goto end;
}
result = 0;
end:
kfree(buffer.pointer);
return result;
}
int acpi_get_psd_map(struct cppc_cpudata **all_cpu_data)
{
int count_target;
int retval = 0;
unsigned int i, j;
cpumask_var_t covered_cpus;
struct cppc_cpudata *pr, *match_pr;
struct acpi_psd_package *pdomain;
struct acpi_psd_package *match_pdomain;
struct cpc_desc *cpc_ptr, *match_cpc_ptr;
if (!zalloc_cpumask_var(&covered_cpus, GFP_KERNEL))
return -ENOMEM;
for_each_possible_cpu(i) {
pr = all_cpu_data[i];
if (!pr)
continue;
if (cpumask_test_cpu(i, covered_cpus))
continue;
cpc_ptr = per_cpu(cpc_desc_ptr, i);
if (!cpc_ptr) {
retval = -EFAULT;
goto err_ret;
}
pdomain = &(cpc_ptr->domain_info);
cpumask_set_cpu(i, pr->shared_cpu_map);
cpumask_set_cpu(i, covered_cpus);
if (pdomain->num_processors <= 1)
continue;
count_target = pdomain->num_processors;
if (pdomain->coord_type == DOMAIN_COORD_TYPE_SW_ALL)
pr->shared_type = CPUFREQ_SHARED_TYPE_ALL;
else if (pdomain->coord_type == DOMAIN_COORD_TYPE_HW_ALL)
pr->shared_type = CPUFREQ_SHARED_TYPE_HW;
else if (pdomain->coord_type == DOMAIN_COORD_TYPE_SW_ANY)
pr->shared_type = CPUFREQ_SHARED_TYPE_ANY;
for_each_possible_cpu(j) {
if (i == j)
continue;
match_cpc_ptr = per_cpu(cpc_desc_ptr, j);
if (!match_cpc_ptr) {
retval = -EFAULT;
goto err_ret;
}
match_pdomain = &(match_cpc_ptr->domain_info);
if (match_pdomain->domain != pdomain->domain)
continue;
if (match_pdomain->num_processors != count_target) {
retval = -EFAULT;
goto err_ret;
}
if (pdomain->coord_type != match_pdomain->coord_type) {
retval = -EFAULT;
goto err_ret;
}
cpumask_set_cpu(j, covered_cpus);
cpumask_set_cpu(j, pr->shared_cpu_map);
}
for_each_possible_cpu(j) {
if (i == j)
continue;
match_pr = all_cpu_data[j];
if (!match_pr)
continue;
match_cpc_ptr = per_cpu(cpc_desc_ptr, j);
if (!match_cpc_ptr) {
retval = -EFAULT;
goto err_ret;
}
match_pdomain = &(match_cpc_ptr->domain_info);
if (match_pdomain->domain != pdomain->domain)
continue;
match_pr->shared_type = pr->shared_type;
cpumask_copy(match_pr->shared_cpu_map,
pr->shared_cpu_map);
}
}
err_ret:
for_each_possible_cpu(i) {
pr = all_cpu_data[i];
if (!pr)
continue;
if (retval) {
cpumask_clear(pr->shared_cpu_map);
cpumask_set_cpu(i, pr->shared_cpu_map);
pr->shared_type = CPUFREQ_SHARED_TYPE_ALL;
}
}
free_cpumask_var(covered_cpus);
return retval;
}
static int register_pcc_channel(int pcc_subspace_idx)
{
struct acpi_pcct_hw_reduced *cppc_ss;
u64 usecs_lat;
if (pcc_subspace_idx >= 0) {
pcc_data.pcc_channel = pcc_mbox_request_channel(&cppc_mbox_cl,
pcc_subspace_idx);
if (IS_ERR(pcc_data.pcc_channel)) {
pr_err("Failed to find PCC communication channel\n");
return -ENODEV;
}
cppc_ss = (pcc_data.pcc_channel)->con_priv;
if (!cppc_ss) {
pr_err("No PCC subspace found for CPPC\n");
return -ENODEV;
}
usecs_lat = NUM_RETRIES * cppc_ss->latency;
pcc_data.deadline = ns_to_ktime(usecs_lat * NSEC_PER_USEC);
pcc_data.pcc_mrtt = cppc_ss->min_turnaround_time;
pcc_data.pcc_mpar = cppc_ss->max_access_rate;
pcc_data.pcc_nominal = cppc_ss->latency;
pcc_data.pcc_comm_addr = acpi_os_ioremap(cppc_ss->base_address, cppc_ss->length);
if (!pcc_data.pcc_comm_addr) {
pr_err("Failed to ioremap PCC comm region mem\n");
return -ENOMEM;
}
pcc_data.pcc_channel_acquired = true;
}
return 0;
}
bool __weak cpc_ffh_supported(void)
{
return false;
}
int acpi_cppc_processor_probe(struct acpi_processor *pr)
{
struct acpi_buffer output = {ACPI_ALLOCATE_BUFFER, NULL};
union acpi_object *out_obj, *cpc_obj;
struct cpc_desc *cpc_ptr;
struct cpc_reg *gas_t;
struct device *cpu_dev;
acpi_handle handle = pr->handle;
unsigned int num_ent, i, cpc_rev;
acpi_status status;
int ret = -EFAULT;
status = acpi_evaluate_object_typed(handle, "_CPC", NULL, &output,
ACPI_TYPE_PACKAGE);
if (ACPI_FAILURE(status)) {
ret = -ENODEV;
goto out_buf_free;
}
out_obj = (union acpi_object *) output.pointer;
cpc_ptr = kzalloc(sizeof(struct cpc_desc), GFP_KERNEL);
if (!cpc_ptr) {
ret = -ENOMEM;
goto out_buf_free;
}
cpc_obj = &out_obj->package.elements[0];
if (cpc_obj->type == ACPI_TYPE_INTEGER) {
num_ent = cpc_obj->integer.value;
} else {
pr_debug("Unexpected entry type(%d) for NumEntries\n",
cpc_obj->type);
goto out_free;
}
if (num_ent != CPPC_NUM_ENT) {
pr_debug("Firmware exports %d entries. Expected: %d\n",
num_ent, CPPC_NUM_ENT);
goto out_free;
}
cpc_ptr->num_entries = num_ent;
cpc_obj = &out_obj->package.elements[1];
if (cpc_obj->type == ACPI_TYPE_INTEGER) {
cpc_rev = cpc_obj->integer.value;
} else {
pr_debug("Unexpected entry type(%d) for Revision\n",
cpc_obj->type);
goto out_free;
}
if (cpc_rev != CPPC_REV) {
pr_debug("Firmware exports revision:%d. Expected:%d\n",
cpc_rev, CPPC_REV);
goto out_free;
}
for (i = 2; i < num_ent; i++) {
cpc_obj = &out_obj->package.elements[i];
if (cpc_obj->type == ACPI_TYPE_INTEGER) {
cpc_ptr->cpc_regs[i-2].type = ACPI_TYPE_INTEGER;
cpc_ptr->cpc_regs[i-2].cpc_entry.int_value = cpc_obj->integer.value;
} else if (cpc_obj->type == ACPI_TYPE_BUFFER) {
gas_t = (struct cpc_reg *)
cpc_obj->buffer.pointer;
if (gas_t->space_id == ACPI_ADR_SPACE_PLATFORM_COMM) {
if (pcc_data.pcc_subspace_idx < 0)
pcc_data.pcc_subspace_idx = gas_t->access_width;
else if (pcc_data.pcc_subspace_idx != gas_t->access_width) {
pr_debug("Mismatched PCC ids.\n");
goto out_free;
}
} else if (gas_t->space_id == ACPI_ADR_SPACE_SYSTEM_MEMORY) {
if (gas_t->address) {
void __iomem *addr;
addr = ioremap(gas_t->address, gas_t->bit_width/8);
if (!addr)
goto out_free;
cpc_ptr->cpc_regs[i-2].sys_mem_vaddr = addr;
}
} else {
if (gas_t->space_id != ACPI_ADR_SPACE_FIXED_HARDWARE || !cpc_ffh_supported()) {
pr_debug("Unsupported register type: %d\n", gas_t->space_id);
goto out_free;
}
}
cpc_ptr->cpc_regs[i-2].type = ACPI_TYPE_BUFFER;
memcpy(&cpc_ptr->cpc_regs[i-2].cpc_entry.reg, gas_t, sizeof(*gas_t));
} else {
pr_debug("Err in entry:%d in CPC table of CPU:%d \n", i, pr->id);
goto out_free;
}
}
cpc_ptr->cpu_id = pr->id;
ret = acpi_get_psd(cpc_ptr, handle);
if (ret)
goto out_free;
if (!pcc_data.pcc_channel_acquired) {
ret = register_pcc_channel(pcc_data.pcc_subspace_idx);
if (ret)
goto out_free;
init_rwsem(&pcc_data.pcc_lock);
init_waitqueue_head(&pcc_data.pcc_write_wait_q);
}
per_cpu(cpc_desc_ptr, pr->id) = cpc_ptr;
pr_debug("Parsed CPC struct for CPU: %d\n", pr->id);
cpu_dev = get_cpu_device(pr->id);
if (!cpu_dev)
goto out_free;
ret = kobject_init_and_add(&cpc_ptr->kobj, &cppc_ktype, &cpu_dev->kobj,
"acpi_cppc");
if (ret)
goto out_free;
kfree(output.pointer);
return 0;
out_free:
for (i = 2; i < cpc_ptr->num_entries; i++) {
void __iomem *addr = cpc_ptr->cpc_regs[i-2].sys_mem_vaddr;
if (addr)
iounmap(addr);
}
kfree(cpc_ptr);
out_buf_free:
kfree(output.pointer);
return ret;
}
void acpi_cppc_processor_exit(struct acpi_processor *pr)
{
struct cpc_desc *cpc_ptr;
unsigned int i;
void __iomem *addr;
cpc_ptr = per_cpu(cpc_desc_ptr, pr->id);
for (i = 2; i < cpc_ptr->num_entries; i++) {
addr = cpc_ptr->cpc_regs[i-2].sys_mem_vaddr;
if (addr)
iounmap(addr);
}
kobject_put(&cpc_ptr->kobj);
kfree(cpc_ptr);
}
int __weak cpc_read_ffh(int cpunum, struct cpc_reg *reg, u64 *val)
{
return -ENOTSUPP;
}
int __weak cpc_write_ffh(int cpunum, struct cpc_reg *reg, u64 val)
{
return -ENOTSUPP;
}
static int cpc_read(int cpu, struct cpc_register_resource *reg_res, u64 *val)
{
int ret_val = 0;
void __iomem *vaddr = 0;
struct cpc_reg *reg = &reg_res->cpc_entry.reg;
if (reg_res->type == ACPI_TYPE_INTEGER) {
*val = reg_res->cpc_entry.int_value;
return ret_val;
}
*val = 0;
if (reg->space_id == ACPI_ADR_SPACE_PLATFORM_COMM)
vaddr = GET_PCC_VADDR(reg->address);
else if (reg->space_id == ACPI_ADR_SPACE_SYSTEM_MEMORY)
vaddr = reg_res->sys_mem_vaddr;
else if (reg->space_id == ACPI_ADR_SPACE_FIXED_HARDWARE)
return cpc_read_ffh(cpu, reg, val);
else
return acpi_os_read_memory((acpi_physical_address)reg->address,
val, reg->bit_width);
switch (reg->bit_width) {
case 8:
*val = readb_relaxed(vaddr);
break;
case 16:
*val = readw_relaxed(vaddr);
break;
case 32:
*val = readl_relaxed(vaddr);
break;
case 64:
*val = readq_relaxed(vaddr);
break;
default:
pr_debug("Error: Cannot read %u bit width from PCC\n",
reg->bit_width);
ret_val = -EFAULT;
}
return ret_val;
}
static int cpc_write(int cpu, struct cpc_register_resource *reg_res, u64 val)
{
int ret_val = 0;
void __iomem *vaddr = 0;
struct cpc_reg *reg = &reg_res->cpc_entry.reg;
if (reg->space_id == ACPI_ADR_SPACE_PLATFORM_COMM)
vaddr = GET_PCC_VADDR(reg->address);
else if (reg->space_id == ACPI_ADR_SPACE_SYSTEM_MEMORY)
vaddr = reg_res->sys_mem_vaddr;
else if (reg->space_id == ACPI_ADR_SPACE_FIXED_HARDWARE)
return cpc_write_ffh(cpu, reg, val);
else
return acpi_os_write_memory((acpi_physical_address)reg->address,
val, reg->bit_width);
switch (reg->bit_width) {
case 8:
writeb_relaxed(val, vaddr);
break;
case 16:
writew_relaxed(val, vaddr);
break;
case 32:
writel_relaxed(val, vaddr);
break;
case 64:
writeq_relaxed(val, vaddr);
break;
default:
pr_debug("Error: Cannot write %u bit width to PCC\n",
reg->bit_width);
ret_val = -EFAULT;
break;
}
return ret_val;
}
int cppc_get_perf_caps(int cpunum, struct cppc_perf_caps *perf_caps)
{
struct cpc_desc *cpc_desc = per_cpu(cpc_desc_ptr, cpunum);
struct cpc_register_resource *highest_reg, *lowest_reg, *ref_perf,
*nom_perf;
u64 high, low, nom;
int ret = 0, regs_in_pcc = 0;
if (!cpc_desc) {
pr_debug("No CPC descriptor for CPU:%d\n", cpunum);
return -ENODEV;
}
highest_reg = &cpc_desc->cpc_regs[HIGHEST_PERF];
lowest_reg = &cpc_desc->cpc_regs[LOWEST_PERF];
ref_perf = &cpc_desc->cpc_regs[REFERENCE_PERF];
nom_perf = &cpc_desc->cpc_regs[NOMINAL_PERF];
if (CPC_IN_PCC(highest_reg) || CPC_IN_PCC(lowest_reg) ||
CPC_IN_PCC(ref_perf) || CPC_IN_PCC(nom_perf)) {
regs_in_pcc = 1;
down_write(&pcc_data.pcc_lock);
if (send_pcc_cmd(CMD_READ) < 0) {
ret = -EIO;
goto out_err;
}
}
cpc_read(cpunum, highest_reg, &high);
perf_caps->highest_perf = high;
cpc_read(cpunum, lowest_reg, &low);
perf_caps->lowest_perf = low;
cpc_read(cpunum, nom_perf, &nom);
perf_caps->nominal_perf = nom;
if (!high || !low || !nom)
ret = -EFAULT;
out_err:
if (regs_in_pcc)
up_write(&pcc_data.pcc_lock);
return ret;
}
int cppc_get_perf_ctrs(int cpunum, struct cppc_perf_fb_ctrs *perf_fb_ctrs)
{
struct cpc_desc *cpc_desc = per_cpu(cpc_desc_ptr, cpunum);
struct cpc_register_resource *delivered_reg, *reference_reg,
*ref_perf_reg, *ctr_wrap_reg;
u64 delivered, reference, ref_perf, ctr_wrap_time;
int ret = 0, regs_in_pcc = 0;
if (!cpc_desc) {
pr_debug("No CPC descriptor for CPU:%d\n", cpunum);
return -ENODEV;
}
delivered_reg = &cpc_desc->cpc_regs[DELIVERED_CTR];
reference_reg = &cpc_desc->cpc_regs[REFERENCE_CTR];
ref_perf_reg = &cpc_desc->cpc_regs[REFERENCE_PERF];
ctr_wrap_reg = &cpc_desc->cpc_regs[CTR_WRAP_TIME];
if (!CPC_SUPPORTED(ref_perf_reg))
ref_perf_reg = &cpc_desc->cpc_regs[NOMINAL_PERF];
if (CPC_IN_PCC(delivered_reg) || CPC_IN_PCC(reference_reg) ||
CPC_IN_PCC(ctr_wrap_reg) || CPC_IN_PCC(ref_perf_reg)) {
down_write(&pcc_data.pcc_lock);
regs_in_pcc = 1;
if (send_pcc_cmd(CMD_READ) < 0) {
ret = -EIO;
goto out_err;
}
}
cpc_read(cpunum, delivered_reg, &delivered);
cpc_read(cpunum, reference_reg, &reference);
cpc_read(cpunum, ref_perf_reg, &ref_perf);
ctr_wrap_time = (u64)(~((u64)0));
if (CPC_SUPPORTED(ctr_wrap_reg))
cpc_read(cpunum, ctr_wrap_reg, &ctr_wrap_time);
if (!delivered || !reference || !ref_perf) {
ret = -EFAULT;
goto out_err;
}
perf_fb_ctrs->delivered = delivered;
perf_fb_ctrs->reference = reference;
perf_fb_ctrs->reference_perf = ref_perf;
perf_fb_ctrs->ctr_wrap_time = ctr_wrap_time;
out_err:
if (regs_in_pcc)
up_write(&pcc_data.pcc_lock);
return ret;
}
int cppc_set_perf(int cpu, struct cppc_perf_ctrls *perf_ctrls)
{
struct cpc_desc *cpc_desc = per_cpu(cpc_desc_ptr, cpu);
struct cpc_register_resource *desired_reg;
int ret = 0;
if (!cpc_desc) {
pr_debug("No CPC descriptor for CPU:%d\n", cpu);
return -ENODEV;
}
desired_reg = &cpc_desc->cpc_regs[DESIRED_PERF];
if (CPC_IN_PCC(desired_reg)) {
down_read(&pcc_data.pcc_lock);
if (pcc_data.platform_owns_pcc) {
ret = check_pcc_chan(false);
if (ret) {
up_read(&pcc_data.pcc_lock);
return ret;
}
}
pcc_data.pending_pcc_write_cmd = true;
cpc_desc->write_cmd_id = pcc_data.pcc_write_cnt;
cpc_desc->write_cmd_status = 0;
}
cpc_write(cpu, desired_reg, perf_ctrls->desired_perf);
if (CPC_IN_PCC(desired_reg))
up_read(&pcc_data.pcc_lock);
if (CPC_IN_PCC(desired_reg)) {
if (down_write_trylock(&pcc_data.pcc_lock)) {
if (pcc_data.pending_pcc_write_cmd)
send_pcc_cmd(CMD_WRITE);
up_write(&pcc_data.pcc_lock);
} else
wait_event(pcc_data.pcc_write_wait_q,
cpc_desc->write_cmd_id != pcc_data.pcc_write_cnt);
ret = cpc_desc->write_cmd_status;
}
return ret;
}
unsigned int cppc_get_transition_latency(int cpu_num)
{
unsigned int latency_ns = 0;
struct cpc_desc *cpc_desc;
struct cpc_register_resource *desired_reg;
cpc_desc = per_cpu(cpc_desc_ptr, cpu_num);
if (!cpc_desc)
return CPUFREQ_ETERNAL;
desired_reg = &cpc_desc->cpc_regs[DESIRED_PERF];
if (!CPC_IN_PCC(desired_reg))
return CPUFREQ_ETERNAL;
if (pcc_data.pcc_mpar)
latency_ns = 60 * (1000 * 1000 * 1000 / pcc_data.pcc_mpar);
latency_ns = max(latency_ns, pcc_data.pcc_nominal * 1000);
latency_ns = max(latency_ns, pcc_data.pcc_mrtt * 1000);
return latency_ns;
}
