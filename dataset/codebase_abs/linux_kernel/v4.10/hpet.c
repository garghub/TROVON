static unsigned int F_1 ( int V_1 )
{
return * ( volatile unsigned int * ) ( V_2 + V_1 ) ;
}
static void F_2 ( int V_1 , int V_3 )
{
* ( volatile unsigned int * ) ( V_2 + V_1 ) = V_3 ;
}
static void F_3 ( int V_1 , int V_4 )
{
unsigned int V_5 = F_1 ( V_1 ) ;
V_5 |= V_4 ;
F_2 ( V_1 , V_5 ) ;
}
static int F_4 ( int V_1 )
{
return * ( volatile unsigned int * ) ( V_6 + V_1 ) ;
}
static void F_5 ( int V_1 , int V_3 )
{
* ( volatile unsigned int * ) ( V_6 + V_1 ) = V_3 ;
}
static void F_6 ( void )
{
unsigned int V_5 = F_4 ( V_7 ) ;
V_5 |= V_8 ;
F_5 ( V_7 , V_5 ) ;
}
static void F_7 ( void )
{
unsigned int V_5 = F_4 ( V_7 ) ;
V_5 &= ~ V_8 ;
F_5 ( V_7 , V_5 ) ;
}
static void F_8 ( void )
{
F_5 ( V_9 , 0 ) ;
F_5 ( V_9 + 4 , 0 ) ;
}
static void F_9 ( void )
{
F_7 () ;
F_8 () ;
F_6 () ;
}
static void F_10 ( void )
{
}
static int F_11 ( struct V_10 * V_11 )
{
int V_5 ;
F_12 ( & V_12 ) ;
F_13 ( L_1 ) ;
F_7 () ;
V_5 = F_4 ( V_13 ) ;
V_5 &= ~ V_14 ;
V_5 |= V_15 | V_16 | V_17 |
V_18 ;
F_5 ( V_13 , V_5 ) ;
F_5 ( V_19 , V_20 ) ;
F_14 ( 1 ) ;
F_5 ( V_19 , V_20 ) ;
F_6 () ;
F_15 ( & V_12 ) ;
return 0 ;
}
static int F_16 ( struct V_10 * V_11 )
{
int V_5 ;
F_12 ( & V_12 ) ;
V_5 = F_4 ( V_13 ) ;
V_5 &= ~ V_15 ;
F_5 ( V_13 , V_5 ) ;
F_15 ( & V_12 ) ;
return 0 ;
}
static int F_17 ( struct V_10 * V_11 )
{
int V_5 ;
F_12 ( & V_12 ) ;
F_13 ( L_2 ) ;
V_5 = F_4 ( V_13 ) ;
V_5 &= ~ V_16 ;
V_5 |= V_15 | V_18 ;
F_5 ( V_13 , V_5 ) ;
F_15 ( & V_12 ) ;
return 0 ;
}
static int F_18 ( struct V_10 * V_11 )
{
F_12 ( & V_12 ) ;
F_10 () ;
F_15 ( & V_12 ) ;
return 0 ;
}
static int F_19 ( unsigned long V_21 ,
struct V_10 * V_11 )
{
T_1 V_22 ;
T_2 V_23 ;
V_22 = F_4 ( V_9 ) ;
V_22 += ( T_1 ) V_21 ;
F_5 ( V_19 , V_22 ) ;
V_23 = ( T_2 ) ( V_22 - F_4 ( V_9 ) ) ;
return V_23 < V_24 ? - V_25 : 0 ;
}
static T_3 F_20 ( int V_26 , void * V_3 )
{
int V_27 ;
struct V_10 * V_28 ;
unsigned int V_29 = F_21 () ;
V_27 = F_4 ( V_30 ) ;
if ( V_27 & V_31 ) {
F_5 ( V_30 , V_31 ) ;
V_28 = & F_22 ( V_32 , V_29 ) ;
V_28 -> V_33 ( V_28 ) ;
return V_34 ;
}
return V_35 ;
}
static void F_23 ( void )
{
F_2 ( V_36 , V_37 ) ;
F_3 ( V_38 , ( 1 << 28 ) ) ;
F_3 ( V_39 , ( 1 << 10 ) ) ;
F_10 () ;
}
void T_4 F_24 ( void )
{
unsigned int V_29 = F_21 () ;
struct V_10 * V_28 ;
F_23 () ;
V_28 = & F_22 ( V_32 , V_29 ) ;
V_28 -> V_40 = L_3 ;
V_28 -> V_41 = 100 ;
V_28 -> V_42 = V_43 | V_44 ;
V_28 -> V_45 = F_16 ;
V_28 -> V_46 = F_11 ;
V_28 -> V_47 = F_17 ;
V_28 -> V_48 = F_18 ;
V_28 -> V_49 = F_19 ;
V_28 -> V_26 = V_50 ;
V_28 -> V_51 = F_25 ( V_29 ) ;
F_26 ( V_28 , V_52 ) ;
V_28 -> V_53 = F_27 ( 0x7fffffff , V_28 ) ;
V_28 -> V_54 = F_27 ( V_55 , V_28 ) ;
F_28 ( V_28 ) ;
F_29 ( V_50 , & V_56 ) ;
F_13 ( L_4 ) ;
}
static T_5 F_30 ( struct V_57 * V_58 )
{
return ( T_5 ) F_4 ( V_9 ) ;
}
static void F_31 ( struct V_57 * V_58 )
{
}
static void F_32 ( struct V_57 * V_58 )
{
F_23 () ;
F_9 () ;
}
int T_4 F_33 ( void )
{
V_59 . V_60 = F_34 ( V_52 , V_59 . V_61 ) ;
return F_35 ( & V_59 , V_52 ) ;
}
