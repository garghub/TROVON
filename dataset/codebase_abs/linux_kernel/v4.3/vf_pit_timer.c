static inline void F_1 ( void )
{
F_2 ( V_1 | V_2 , V_3 + V_4 ) ;
}
static inline void F_3 ( void )
{
F_2 ( 0 , V_3 + V_4 ) ;
}
static inline void F_4 ( void )
{
F_2 ( V_5 , V_3 + V_6 ) ;
}
static T_1 T_2 F_5 ( void )
{
return ~ F_6 ( V_7 + V_8 ) ;
}
static int T_3 F_7 ( unsigned long V_9 )
{
F_2 ( 0 , V_7 + V_4 ) ;
F_2 ( ~ 0UL , V_7 + V_10 ) ;
F_2 ( V_1 , V_7 + V_4 ) ;
F_8 ( F_5 , 32 , V_9 ) ;
return F_9 ( V_7 + V_8 , L_1 , V_9 ,
300 , 32 , V_11 ) ;
}
static int F_10 ( unsigned long V_12 ,
struct V_13 * V_14 )
{
F_3 () ;
F_2 ( V_12 - 1 , V_3 + V_10 ) ;
F_1 () ;
return 0 ;
}
static int F_11 ( struct V_13 * V_15 )
{
F_3 () ;
return 0 ;
}
static int F_12 ( struct V_13 * V_15 )
{
F_10 ( V_16 , V_15 ) ;
return 0 ;
}
static T_4 F_13 ( int V_17 , void * V_18 )
{
struct V_13 * V_15 = V_18 ;
F_4 () ;
if ( F_14 ( F_15 ( V_15 ) ) )
F_3 () ;
V_15 -> V_19 ( V_15 ) ;
return V_20 ;
}
static int T_3 F_16 ( unsigned long V_9 , int V_17 )
{
F_2 ( 0 , V_3 + V_4 ) ;
F_2 ( V_5 , V_3 + V_6 ) ;
F_17 ( F_18 ( V_17 , & V_21 ) ) ;
V_22 . V_23 = F_19 ( 0 ) ;
V_22 . V_17 = V_17 ;
F_20 ( & V_22 , V_9 , 2 , 0xffffffff ) ;
return 0 ;
}
static void T_3 F_21 ( struct V_24 * V_25 )
{
struct V_26 * V_27 ;
void T_5 * V_28 ;
unsigned long V_29 ;
int V_17 ;
V_28 = F_22 ( V_25 , 0 ) ;
F_17 ( ! V_28 ) ;
V_7 = V_28 + F_23 ( 2 ) ;
V_3 = V_28 + F_23 ( 3 ) ;
V_17 = F_24 ( V_25 , 0 ) ;
F_17 ( V_17 <= 0 ) ;
V_27 = F_25 ( V_25 , 0 ) ;
F_17 ( F_26 ( V_27 ) ) ;
F_17 ( F_27 ( V_27 ) ) ;
V_29 = F_28 ( V_27 ) ;
V_16 = V_29 / ( V_30 ) ;
F_2 ( ~ V_31 , V_28 + V_32 ) ;
F_17 ( F_7 ( V_29 ) ) ;
F_16 ( V_29 , V_17 ) ;
}
