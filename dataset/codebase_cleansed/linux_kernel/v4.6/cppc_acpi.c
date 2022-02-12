static int check_pcc_chan(void)
{
int ret = -EIO;
struct acpi_pcct_shared_memory __iomem *generic_comm_base = pcc_comm_addr;
ktime_t next_deadline = ktime_add(ktime_get(), deadline);
while (!ktime_after(ktime_get(), next_deadline)) {
if (readw_relaxed(&generic_comm_base->status) & PCC_CMD_COMPLETE) {
ret = 0;
break;
}
udelay(3);
}
return ret;
}
static int send_pcc_cmd(u16 cmd)
{
int ret = -EIO;
struct acpi_pcct_shared_memory *generic_comm_base =
(struct acpi_pcct_shared_memory *) pcc_comm_addr;
static ktime_t last_cmd_cmpl_time, last_mpar_reset;
static int mpar_count;
unsigned int time_delta;
if (cmd == CMD_READ) {
ret = check_pcc_chan();
if (ret)
return ret;
}
if (pcc_mrtt) {
time_delta = ktime_us_delta(ktime_get(), last_cmd_cmpl_time);
if (pcc_mrtt > time_delta)
udelay(pcc_mrtt - time_delta);
}
if (pcc_mpar) {
if (mpar_count == 0) {
time_delta = ktime_ms_delta(ktime_get(), last_mpar_reset);
if (time_delta < 60 * MSEC_PER_SEC) {
pr_debug("PCC cmd not sent due to MPAR limit");
return -EIO;
}
last_mpar_reset = ktime_get();
mpar_count = pcc_mpar;
}
mpar_count--;
}
writew_relaxed(cmd, &generic_comm_base->command);
writew_relaxed(0, &generic_comm_base->status);
ret = mbox_send_message(pcc_channel, &cmd);
if (ret < 0) {
pr_err("Err sending PCC mbox message. cmd:%d, ret:%d\n",
cmd, ret);
return ret;
}
if (cmd == CMD_READ || pcc_mrtt) {
ret = check_pcc_chan();
if (pcc_mrtt)
last_cmd_cmpl_time = ktime_get();
}
mbox_client_txdone(pcc_channel, ret);
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
int acpi_get_psd_map(struct cpudata **all_cpu_data)
{
int count_target;
int retval = 0;
unsigned int i, j;
cpumask_var_t covered_cpus;
struct cpudata *pr, *match_pr;
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
if (!cpc_ptr)
continue;
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
if (!match_cpc_ptr)
continue;
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
if (!match_cpc_ptr)
continue;
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
unsigned int len;
u64 usecs_lat;
if (pcc_subspace_idx >= 0) {
pcc_channel = pcc_mbox_request_channel(&cppc_mbox_cl,
pcc_subspace_idx);
if (IS_ERR(pcc_channel)) {
pr_err("Failed to find PCC communication channel\n");
return -ENODEV;
}
cppc_ss = pcc_channel->con_priv;
if (!cppc_ss) {
pr_err("No PCC subspace found for CPPC\n");
return -ENODEV;
}
comm_base_addr = cppc_ss->base_address;
len = cppc_ss->length;
usecs_lat = NUM_RETRIES * cppc_ss->latency;
deadline = ns_to_ktime(usecs_lat * NSEC_PER_USEC);
pcc_mrtt = cppc_ss->min_turnaround_time;
pcc_mpar = cppc_ss->max_access_rate;
pcc_comm_addr = acpi_os_ioremap(comm_base_addr, len);
if (!pcc_comm_addr) {
pr_err("Failed to ioremap PCC comm region mem\n");
return -ENOMEM;
}
pcc_channel_acquired = true;
}
return 0;
}
int acpi_cppc_processor_probe(struct acpi_processor *pr)
{
struct acpi_buffer output = {ACPI_ALLOCATE_BUFFER, NULL};
union acpi_object *out_obj, *cpc_obj;
struct cpc_desc *cpc_ptr;
struct cpc_reg *gas_t;
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
if (pcc_subspace_idx < 0)
pcc_subspace_idx = gas_t->access_width;
else if (pcc_subspace_idx != gas_t->access_width) {
pr_debug("Mismatched PCC ids.\n");
goto out_free;
}
} else if (gas_t->space_id != ACPI_ADR_SPACE_SYSTEM_MEMORY) {
pr_debug("Unsupported register type: %d\n", gas_t->space_id);
goto out_free;
}
cpc_ptr->cpc_regs[i-2].type = ACPI_TYPE_BUFFER;
memcpy(&cpc_ptr->cpc_regs[i-2].cpc_entry.reg, gas_t, sizeof(*gas_t));
} else {
pr_debug("Err in entry:%d in CPC table of CPU:%d \n", i, pr->id);
goto out_free;
}
}
cpc_ptr->cpu_id = pr->id;
per_cpu(cpc_desc_ptr, pr->id) = cpc_ptr;
ret = acpi_get_psd(cpc_ptr, handle);
if (ret)
goto out_free;
if (!pcc_channel_acquired) {
ret = register_pcc_channel(pcc_subspace_idx);
if (ret)
goto out_free;
}
pr_debug("Parsed CPC struct for CPU: %d\n", pr->id);
kfree(output.pointer);
return 0;
out_free:
kfree(cpc_ptr);
out_buf_free:
kfree(output.pointer);
return ret;
}
void acpi_cppc_processor_exit(struct acpi_processor *pr)
{
struct cpc_desc *cpc_ptr;
cpc_ptr = per_cpu(cpc_desc_ptr, pr->id);
kfree(cpc_ptr);
}
static int cpc_read(struct cpc_reg *reg, u64 *val)
{
int ret_val = 0;
*val = 0;
if (reg->space_id == ACPI_ADR_SPACE_PLATFORM_COMM) {
void __iomem *vaddr = GET_PCC_VADDR(reg->address);
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
} else
ret_val = acpi_os_read_memory((acpi_physical_address)reg->address,
val, reg->bit_width);
return ret_val;
}
static int cpc_write(struct cpc_reg *reg, u64 val)
{
int ret_val = 0;
if (reg->space_id == ACPI_ADR_SPACE_PLATFORM_COMM) {
void __iomem *vaddr = GET_PCC_VADDR(reg->address);
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
} else
ret_val = acpi_os_write_memory((acpi_physical_address)reg->address,
val, reg->bit_width);
return ret_val;
}
int cppc_get_perf_caps(int cpunum, struct cppc_perf_caps *perf_caps)
{
struct cpc_desc *cpc_desc = per_cpu(cpc_desc_ptr, cpunum);
struct cpc_register_resource *highest_reg, *lowest_reg, *ref_perf,
*nom_perf;
u64 high, low, ref, nom;
int ret = 0;
if (!cpc_desc) {
pr_debug("No CPC descriptor for CPU:%d\n", cpunum);
return -ENODEV;
}
highest_reg = &cpc_desc->cpc_regs[HIGHEST_PERF];
lowest_reg = &cpc_desc->cpc_regs[LOWEST_PERF];
ref_perf = &cpc_desc->cpc_regs[REFERENCE_PERF];
nom_perf = &cpc_desc->cpc_regs[NOMINAL_PERF];
spin_lock(&pcc_lock);
if ((highest_reg->cpc_entry.reg.space_id == ACPI_ADR_SPACE_PLATFORM_COMM) ||
(lowest_reg->cpc_entry.reg.space_id == ACPI_ADR_SPACE_PLATFORM_COMM) ||
(ref_perf->cpc_entry.reg.space_id == ACPI_ADR_SPACE_PLATFORM_COMM) ||
(nom_perf->cpc_entry.reg.space_id == ACPI_ADR_SPACE_PLATFORM_COMM)) {
if (send_pcc_cmd(CMD_READ) < 0) {
ret = -EIO;
goto out_err;
}
}
cpc_read(&highest_reg->cpc_entry.reg, &high);
perf_caps->highest_perf = high;
cpc_read(&lowest_reg->cpc_entry.reg, &low);
perf_caps->lowest_perf = low;
cpc_read(&ref_perf->cpc_entry.reg, &ref);
perf_caps->reference_perf = ref;
cpc_read(&nom_perf->cpc_entry.reg, &nom);
perf_caps->nominal_perf = nom;
if (!ref)
perf_caps->reference_perf = perf_caps->nominal_perf;
if (!high || !low || !nom)
ret = -EFAULT;
out_err:
spin_unlock(&pcc_lock);
return ret;
}
int cppc_get_perf_ctrs(int cpunum, struct cppc_perf_fb_ctrs *perf_fb_ctrs)
{
struct cpc_desc *cpc_desc = per_cpu(cpc_desc_ptr, cpunum);
struct cpc_register_resource *delivered_reg, *reference_reg;
u64 delivered, reference;
int ret = 0;
if (!cpc_desc) {
pr_debug("No CPC descriptor for CPU:%d\n", cpunum);
return -ENODEV;
}
delivered_reg = &cpc_desc->cpc_regs[DELIVERED_CTR];
reference_reg = &cpc_desc->cpc_regs[REFERENCE_CTR];
spin_lock(&pcc_lock);
if ((delivered_reg->cpc_entry.reg.space_id == ACPI_ADR_SPACE_PLATFORM_COMM) ||
(reference_reg->cpc_entry.reg.space_id == ACPI_ADR_SPACE_PLATFORM_COMM)) {
if (send_pcc_cmd(CMD_READ) < 0) {
ret = -EIO;
goto out_err;
}
}
cpc_read(&delivered_reg->cpc_entry.reg, &delivered);
cpc_read(&reference_reg->cpc_entry.reg, &reference);
if (!delivered || !reference) {
ret = -EFAULT;
goto out_err;
}
perf_fb_ctrs->delivered = delivered;
perf_fb_ctrs->reference = reference;
perf_fb_ctrs->delivered -= perf_fb_ctrs->prev_delivered;
perf_fb_ctrs->reference -= perf_fb_ctrs->prev_reference;
perf_fb_ctrs->prev_delivered = delivered;
perf_fb_ctrs->prev_reference = reference;
out_err:
spin_unlock(&pcc_lock);
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
spin_lock(&pcc_lock);
if (desired_reg->cpc_entry.reg.space_id == ACPI_ADR_SPACE_PLATFORM_COMM) {
ret = check_pcc_chan();
if (ret)
goto busy_channel;
}
cpc_write(&desired_reg->cpc_entry.reg, perf_ctrls->desired_perf);
if (desired_reg->cpc_entry.reg.space_id == ACPI_ADR_SPACE_PLATFORM_COMM) {
if (send_pcc_cmd(CMD_WRITE) < 0)
ret = -EIO;
}
busy_channel:
spin_unlock(&pcc_lock);
return ret;
}
