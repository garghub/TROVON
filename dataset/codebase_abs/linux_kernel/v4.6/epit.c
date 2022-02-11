static inline void F_1 ( void )
{
T_1 V_1 ;
V_1 = F_2 ( V_2 + V_3 ) ;
V_1 &= ~ V_4 ;
F_3 ( V_1 , V_2 + V_3 ) ;
}
static inline void F_4 ( void )
{
T_1 V_1 ;
V_1 = F_2 ( V_2 + V_3 ) ;
V_1 |= V_4 ;
F_3 ( V_1 , V_2 + V_3 ) ;
}
static void F_5 ( void )
{
F_3 ( V_5 , V_2 + V_6 ) ;
}
static int T_2 F_6 ( struct V_7 * V_8 )
{
unsigned int V_9 = F_7 ( V_8 ) ;
return F_8 ( V_2 + V_10 , L_1 , V_9 , 200 , 32 ,
V_11 ) ;
}
static int F_9 ( unsigned long V_12 ,
struct V_13 * V_14 )
{
unsigned long V_15 ;
V_15 = F_2 ( V_2 + V_10 ) ;
F_3 ( V_15 - V_12 , V_2 + V_16 ) ;
return 0 ;
}
static int F_10 ( struct V_13 * V_12 )
{
unsigned long V_17 ;
F_11 ( V_17 ) ;
F_1 () ;
F_5 () ;
F_12 ( V_17 ) ;
return 0 ;
}
static int F_13 ( struct V_13 * V_12 )
{
unsigned long V_17 ;
F_11 ( V_17 ) ;
F_1 () ;
if ( ! F_14 ( V_12 ) )
F_5 () ;
F_4 () ;
F_12 ( V_17 ) ;
return 0 ;
}
static T_3 F_15 ( int V_18 , void * V_19 )
{
struct V_13 * V_12 = & V_20 ;
F_5 () ;
V_12 -> V_21 ( V_12 ) ;
return V_22 ;
}
static int T_2 F_16 ( struct V_7 * V_8 )
{
V_20 . V_23 = F_17 ( 0 ) ;
F_18 ( & V_20 ,
F_7 ( V_8 ) ,
0x800 , 0xfffffffe ) ;
return 0 ;
}
void T_2 F_19 ( void T_4 * V_24 , int V_18 )
{
struct V_7 * V_8 ;
V_8 = F_20 ( L_2 , NULL ) ;
if ( F_21 ( V_8 ) ) {
F_22 ( L_3 ) ;
return;
}
F_23 ( V_8 ) ;
V_2 = V_24 ;
F_3 ( 0x0 , V_2 + V_3 ) ;
F_3 ( 0xffffffff , V_2 + V_25 ) ;
F_3 ( V_26 | V_27 | V_28 ,
V_2 + V_3 ) ;
F_6 ( V_8 ) ;
F_16 ( V_8 ) ;
F_24 ( V_18 , & V_29 ) ;
}
