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
static unsigned int F_5 ( void )
{
return F_6 ( V_7 + V_8 ) ;
}
static int T_1 F_7 ( unsigned long V_9 )
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
static void F_11 ( enum V_15 V_16 ,
struct V_13 * V_17 )
{
switch ( V_16 ) {
case V_18 :
F_10 ( V_19 , V_17 ) ;
break;
default:
break;
}
}
static T_2 F_12 ( int V_20 , void * V_21 )
{
struct V_13 * V_17 = V_21 ;
F_4 () ;
if ( F_13 ( V_17 -> V_16 == V_22 ) )
F_3 () ;
V_17 -> V_23 ( V_17 ) ;
return V_24 ;
}
static int T_1 F_14 ( unsigned long V_9 , int V_20 )
{
F_2 ( 0 , V_3 + V_4 ) ;
F_2 ( V_5 , V_3 + V_6 ) ;
F_15 ( F_16 ( V_20 , & V_25 ) ) ;
V_26 . V_27 = F_17 ( 0 ) ;
V_26 . V_20 = V_20 ;
F_18 ( & V_26 , V_9 , 2 , 0xffffffff ) ;
return 0 ;
}
static void T_1 F_19 ( struct V_28 * V_29 )
{
struct V_30 * V_31 ;
void T_3 * V_32 ;
unsigned long V_33 ;
int V_20 ;
V_32 = F_20 ( V_29 , 0 ) ;
F_15 ( ! V_32 ) ;
V_7 = V_32 + F_21 ( 2 ) ;
V_3 = V_32 + F_21 ( 3 ) ;
V_20 = F_22 ( V_29 , 0 ) ;
F_15 ( V_20 <= 0 ) ;
V_31 = F_23 ( V_29 , 0 ) ;
F_15 ( F_24 ( V_31 ) ) ;
F_15 ( F_25 ( V_31 ) ) ;
V_33 = F_26 ( V_31 ) ;
V_19 = V_33 / ( V_34 ) ;
F_2 ( ~ V_35 , V_32 + V_36 ) ;
F_15 ( F_7 ( V_33 ) ) ;
F_14 ( V_33 , V_20 ) ;
}
