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
static T_1 F_5 ( void )
{
return ~ F_6 ( V_7 + V_8 ) ;
}
static int T_2 F_7 ( unsigned long V_9 )
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
case V_20 :
case V_21 :
F_3 () ;
break;
default:
break;
}
}
static T_3 F_12 ( int V_22 , void * V_23 )
{
struct V_13 * V_17 = V_23 ;
F_4 () ;
if ( F_13 ( V_17 -> V_16 == V_24 ) )
F_3 () ;
V_17 -> V_25 ( V_17 ) ;
return V_26 ;
}
static int T_2 F_14 ( unsigned long V_9 , int V_22 )
{
F_2 ( 0 , V_3 + V_4 ) ;
F_2 ( V_5 , V_3 + V_6 ) ;
F_15 ( F_16 ( V_22 , & V_27 ) ) ;
V_28 . V_29 = F_17 ( 0 ) ;
V_28 . V_22 = V_22 ;
F_18 ( & V_28 , V_9 , 2 , 0xffffffff ) ;
return 0 ;
}
static void T_2 F_19 ( struct V_30 * V_31 )
{
struct V_32 * V_33 ;
void T_4 * V_34 ;
unsigned long V_35 ;
int V_22 ;
V_34 = F_20 ( V_31 , 0 ) ;
F_15 ( ! V_34 ) ;
V_7 = V_34 + F_21 ( 2 ) ;
V_3 = V_34 + F_21 ( 3 ) ;
V_22 = F_22 ( V_31 , 0 ) ;
F_15 ( V_22 <= 0 ) ;
V_33 = F_23 ( V_31 , 0 ) ;
F_15 ( F_24 ( V_33 ) ) ;
F_15 ( F_25 ( V_33 ) ) ;
V_35 = F_26 ( V_33 ) ;
V_19 = V_35 / ( V_36 ) ;
F_2 ( ~ V_37 , V_34 + V_38 ) ;
F_15 ( F_7 ( V_35 ) ) ;
F_14 ( V_35 , V_22 ) ;
}
