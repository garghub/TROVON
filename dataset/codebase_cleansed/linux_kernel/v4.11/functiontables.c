static int phm_run_table(struct pp_hwmgr *hwmgr,
struct phm_runtime_table_header *rt_table,
void *input,
void *output,
void *temp_storage)
{
int result = 0;
phm_table_function *function;
if (rt_table->function_list == NULL) {
pr_debug("this function not implement!\n");
return 0;
}
for (function = rt_table->function_list; NULL != *function; function++) {
int tmp = (*function)(hwmgr, input, output, temp_storage, result);
if (tmp == PP_Result_TableImmediateExit)
break;
if (tmp) {
if (0 == result)
result = tmp;
if (rt_table->exit_error)
break;
}
}
return result;
}
int phm_dispatch_table(struct pp_hwmgr *hwmgr,
struct phm_runtime_table_header *rt_table,
void *input, void *output)
{
int result;
void *temp_storage;
if (hwmgr == NULL || rt_table == NULL) {
pr_err("Invalid Parameter!\n");
return -EINVAL;
}
if (0 != rt_table->storage_size) {
temp_storage = kzalloc(rt_table->storage_size, GFP_KERNEL);
if (temp_storage == NULL) {
pr_err("Could not allocate table temporary storage\n");
return -ENOMEM;
}
} else {
temp_storage = NULL;
}
result = phm_run_table(hwmgr, rt_table, input, output, temp_storage);
kfree(temp_storage);
return result;
}
int phm_construct_table(struct pp_hwmgr *hwmgr,
const struct phm_master_table_header *master_table,
struct phm_runtime_table_header *rt_table)
{
uint32_t function_count = 0;
const struct phm_master_table_item *table_item;
uint32_t size;
phm_table_function *run_time_list;
phm_table_function *rtf;
if (hwmgr == NULL || master_table == NULL || rt_table == NULL) {
pr_err("Invalid Parameter!\n");
return -EINVAL;
}
for (table_item = master_table->master_list;
NULL != table_item->tableFunction; table_item++) {
if ((NULL == table_item->isFunctionNeededInRuntimeTable) ||
(table_item->isFunctionNeededInRuntimeTable(hwmgr)))
function_count++;
}
size = (function_count + 1) * sizeof(phm_table_function);
run_time_list = kzalloc(size, GFP_KERNEL);
if (NULL == run_time_list)
return -ENOMEM;
rtf = run_time_list;
for (table_item = master_table->master_list;
NULL != table_item->tableFunction; table_item++) {
if ((rtf - run_time_list) > function_count) {
pr_err("Check function results have changed\n");
kfree(run_time_list);
return -EINVAL;
}
if ((NULL == table_item->isFunctionNeededInRuntimeTable) ||
(table_item->isFunctionNeededInRuntimeTable(hwmgr))) {
*(rtf++) = table_item->tableFunction;
}
}
if ((rtf - run_time_list) > function_count) {
pr_err("Check function results have changed\n");
kfree(run_time_list);
return -EINVAL;
}
*rtf = NULL;
rt_table->function_list = run_time_list;
rt_table->exit_error = (0 != (master_table->flags & PHM_MasterTableFlag_ExitOnError));
rt_table->storage_size = master_table->storage_size;
return 0;
}
int phm_destroy_table(struct pp_hwmgr *hwmgr,
struct phm_runtime_table_header *rt_table)
{
if (hwmgr == NULL || rt_table == NULL) {
pr_err("Invalid Parameter\n");
return -EINVAL;
}
if (NULL == rt_table->function_list)
return 0;
kfree(rt_table->function_list);
rt_table->function_list = NULL;
rt_table->storage_size = 0;
rt_table->exit_error = false;
return 0;
}
