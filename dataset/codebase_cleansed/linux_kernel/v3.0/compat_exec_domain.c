static int __init s390_init (void)
{
s390_exec_domain.name = "Linux/s390";
s390_exec_domain.handler = NULL;
s390_exec_domain.pers_low = PER_LINUX32;
s390_exec_domain.pers_high = PER_LINUX32;
s390_exec_domain.signal_map = default_exec_domain.signal_map;
s390_exec_domain.signal_invmap = default_exec_domain.signal_invmap;
register_exec_domain(&s390_exec_domain);
return 0;
}
