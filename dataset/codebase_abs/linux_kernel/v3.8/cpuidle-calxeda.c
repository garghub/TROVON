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
static void F_15 ( void )
{
int V_12 ;
struct V_6 * V_7 ;
F_16 (i) {
V_7 = F_17 ( V_13 , V_12 ) ;
F_18 ( V_7 ) ;
}
F_19 ( V_13 ) ;
}
static int T_2 F_20 ( void )
{
int V_14 ;
int V_15 ;
struct V_6 * V_7 ;
struct V_8 * V_9 = & V_16 ;
if ( ! F_21 ( L_1 ) )
return - V_17 ;
V_15 = F_22 ( V_9 ) ;
if ( V_15 )
return V_15 ;
V_13 = F_23 ( struct V_6 ) ;
if ( V_13 == NULL ) {
V_15 = - V_18 ;
goto V_19;
}
F_16 (cpu_id) {
V_7 = F_17 ( V_13 , V_14 ) ;
V_7 -> V_20 = V_14 ;
V_7 -> V_21 = V_9 -> V_21 ;
V_15 = F_24 ( V_7 ) ;
if ( V_15 ) {
F_25 ( L_2 ,
V_14 , V_15 ) ;
goto V_22;
}
}
return 0 ;
V_22:
F_15 () ;
V_19:
F_26 ( V_9 ) ;
return V_15 ;
}
