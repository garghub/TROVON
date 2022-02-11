static inline unsigned int F_1 ( void )
{
unsigned int V_1 ;
asm("mrc p15, 0, %0, c1, c0, 1 @ get AUXCR" : "=r" (val) : : "cc");
return V_1 ;
}
static inline void F_2 ( unsigned int V_1 )
{
asm volatile("mcr p15, 0, %0, c1, c0, 1 @ set AUXCR"
: : "r" (val) : "cc");
F_3 () ;
}
static T_1 void F_4 ( void )
{
F_5 ( F_6 () | V_2 ) ;
F_2 ( F_1 () | 0x40 ) ;
F_7 ( V_3 , V_4 ) ;
}
static int F_8 ( unsigned long V_1 )
{
F_9 () ;
F_2 ( F_1 () & ~ 0x40 ) ;
F_5 ( F_6 () & ~ V_2 ) ;
F_7 ( V_3 , V_5 ) ;
F_10 () ;
F_4 () ;
return 1 ;
}
static int F_11 ( struct V_6 * V_7 ,
struct V_8 * V_9 ,
int V_10 )
{
F_12 ( F_13 () , V_11 ) ;
F_14 ( 0 , F_8 ) ;
return V_10 ;
}
static int T_2 F_15 ( void )
{
if ( ! F_16 ( L_1 ) )
return - V_12 ;
return F_17 ( & V_13 , NULL ) ;
}
