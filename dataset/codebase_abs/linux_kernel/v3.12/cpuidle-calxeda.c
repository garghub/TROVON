static T_1 void F_1 ( void )
{
F_2 ( F_3 () | V_1 ) ;
F_4 ( F_5 () | 0x40 ) ;
F_6 ( V_2 , V_3 ) ;
}
static int F_7 ( unsigned long V_4 )
{
F_8 () ;
F_4 ( F_5 () & ~ 0x40 ) ;
F_2 ( F_3 () & ~ V_1 ) ;
F_6 ( V_2 , V_5 ) ;
F_9 () ;
F_1 () ;
return 1 ;
}
static int F_10 ( struct V_6 * V_7 ,
struct V_8 * V_9 ,
int V_10 )
{
F_11 ( F_12 () , V_11 ) ;
F_13 ( 0 , F_7 ) ;
return V_10 ;
}
static int T_2 F_14 ( void )
{
if ( ! F_15 ( L_1 ) )
return - V_12 ;
return F_16 ( & V_13 , NULL ) ;
}
