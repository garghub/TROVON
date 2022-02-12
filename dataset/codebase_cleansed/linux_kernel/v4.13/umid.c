static int __init set_umid_arg(char *name, int *add)
{
int err;
if (umid_inited) {
os_warn("umid already set\n");
return 0;
}
*add = 0;
err = set_umid(name);
if (err == -EEXIST)
os_warn("umid '%s' already in use\n", name);
else if (!err)
umid_inited = 1;
return 0;
}
