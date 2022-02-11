static void F_1 ( char * V_1 )
{
#if 0
int i;
#endif
F_2 ( L_1 , F_3 () ) ;
#ifdef F_4
F_5 () ;
#endif
#if 0
for_each_online_node(i)
REMOTE_HUB_S(COMPACT_TO_NASID_NODEID(i), PROMOP_REG,
PROMOP_REBOOT);
#else
F_6 ( V_2 , V_3 | V_4 ) ;
#endif
noreturn ;
}
static void F_7 ( void )
{
int V_5 ;
#ifdef F_4
F_5 () ;
#endif
F_8 (i)
F_9 ( F_10 ( V_5 ) , V_6 ,
V_7 ) ;
F_6 ( V_2 , V_3 | V_4 ) ;
noreturn ;
}
static void F_11 ( void )
{
noreturn ;
}
void F_12 ( void )
{
V_8 = F_1 ;
V_9 = F_7 ;
V_10 = F_11 ;
}
