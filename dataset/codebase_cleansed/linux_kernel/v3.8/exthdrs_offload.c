int __init ipv6_exthdrs_offload_init(void)
{
int ret;
ret = inet6_add_offload(&rthdr_offload, IPPROTO_ROUTING);
if (!ret)
goto out;
ret = inet6_add_offload(&dstopt_offload, IPPROTO_DSTOPTS);
if (!ret)
goto out_rt;
out:
return ret;
out_rt:
inet_del_offload(&rthdr_offload, IPPROTO_ROUTING);
goto out;
}
