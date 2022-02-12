int ec_GFp_recp_group_init(EC_GROUP *group)
{
int ok;
ok = ec_GFp_simple_group_init(group);
group->field_data1 = NULL;
return ok;
}
