static void F_1 ( void )
{
T_1 V_1 = F_2 ( V_2 + F_3 ( 1 ) ) ;
while ( ( V_1 - F_2 ( V_2 + F_3 ( 1 ) ) ) < V_3 )
F_4 () ;
}
static void F_5 ( T_2 V_4 )
{
T_1 V_5 = F_2 ( V_2 + F_6 ( V_4 ) ) ;
F_7 ( V_5 & ~ V_6 , V_2 + F_6 ( V_4 ) ) ;
F_1 () ;
}
static void F_8 ( T_2 V_4 , unsigned long V_7 )
{
F_7 ( V_7 , V_2 + F_9 ( V_4 ) ) ;
}
static void F_10 ( T_2 V_4 , bool V_8 )
{
T_1 V_5 = F_2 ( V_2 + F_6 ( V_4 ) ) ;
if ( V_8 )
V_5 &= ~ V_9 ;
else
V_5 |= V_9 ;
F_7 ( V_5 | V_6 | V_10 ,
V_2 + F_6 ( V_4 ) ) ;
}
static int F_11 ( struct V_11 * V_12 )
{
F_5 ( 0 ) ;
return 0 ;
}
static int F_12 ( struct V_11 * V_12 )
{
F_5 ( 0 ) ;
F_10 ( 0 , false ) ;
return 0 ;
}
static int F_13 ( struct V_11 * V_12 )
{
F_5 ( 0 ) ;
F_8 ( 0 , V_13 ) ;
F_10 ( 0 , true ) ;
return 0 ;
}
static int F_14 ( unsigned long V_12 ,
struct V_11 * V_14 )
{
F_5 ( 0 ) ;
F_8 ( 0 , V_12 - V_3 ) ;
F_10 ( 0 , false ) ;
return 0 ;
}
static T_3 F_15 ( int V_15 , void * V_16 )
{
struct V_11 * V_12 = (struct V_11 * ) V_16 ;
F_7 ( 0x1 , V_2 + V_17 ) ;
V_12 -> V_18 ( V_12 ) ;
return V_19 ;
}
static T_4 T_5 F_16 ( void )
{
return ~ F_2 ( V_2 + F_3 ( 1 ) ) ;
}
static void T_6 F_17 ( struct V_20 * V_21 )
{
unsigned long V_22 = 0 ;
struct V_23 * V_23 ;
int V_24 , V_15 ;
T_1 V_5 ;
V_2 = F_18 ( V_21 , 0 ) ;
if ( ! V_2 )
F_19 ( L_1 ) ;
V_15 = F_20 ( V_21 , 0 ) ;
if ( V_15 <= 0 )
F_19 ( L_2 ) ;
V_23 = F_21 ( V_21 , 0 ) ;
if ( F_22 ( V_23 ) )
F_19 ( L_3 ) ;
F_23 ( V_23 ) ;
V_22 = F_24 ( V_23 ) ;
F_7 ( ~ 0 , V_2 + F_9 ( 1 ) ) ;
F_7 ( V_6 | V_10 |
F_25 ( V_25 ) ,
V_2 + F_6 ( 1 ) ) ;
if ( F_26 ( L_4 ) ||
F_26 ( L_5 ) ||
F_26 ( L_6 ) )
F_27 ( F_16 , 32 , V_22 ) ;
F_28 ( V_2 + F_3 ( 1 ) , V_21 -> V_26 ,
V_22 , 350 , 32 , V_27 ) ;
V_13 = F_29 ( V_22 , V_28 ) ;
F_7 ( F_25 ( V_25 ) ,
V_2 + F_6 ( 0 ) ) ;
F_5 ( 0 ) ;
V_29 . V_30 = V_31 ;
V_29 . V_15 = V_15 ;
F_30 ( & V_29 , V_22 ,
V_3 , 0xffffffff ) ;
V_24 = F_31 ( V_15 , & V_32 ) ;
if ( V_24 )
F_32 ( L_7 , V_15 ) ;
V_5 = F_2 ( V_2 + V_33 ) ;
F_7 ( V_5 | F_33 ( 0 ) , V_2 + V_33 ) ;
}
