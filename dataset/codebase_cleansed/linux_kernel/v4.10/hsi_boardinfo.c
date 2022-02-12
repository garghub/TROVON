int __init hsi_register_board_info(struct hsi_board_info const *info,
unsigned int len)
{
struct hsi_cl_info *cl_info;
cl_info = kzalloc(sizeof(*cl_info) * len, GFP_KERNEL);
if (!cl_info)
return -ENOMEM;
for (; len; len--, info++, cl_info++) {
cl_info->info = *info;
list_add_tail(&cl_info->list, &hsi_board_list);
}
return 0;
}
