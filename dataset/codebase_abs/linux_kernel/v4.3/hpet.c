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
unsigned int V_22 ;
int V_23 ;
V_22 = F_4 ( V_9 ) ;
V_22 += V_21 ;
F_5 ( V_19 , V_22 ) ;
V_23 = ( ( int ) ( F_4 ( V_9 ) - V_22 ) > 0 ) ? - V_24 : 0 ;
return V_23 ;
}
static T_1 F_20 ( int V_25 , void * V_3 )
{
int V_26 ;
struct V_10 * V_27 ;
unsigned int V_28 = F_21 () ;
V_26 = F_4 ( V_29 ) ;
if ( V_26 & V_30 ) {
F_5 ( V_29 , V_30 ) ;
V_27 = & F_22 ( V_31 , V_28 ) ;
V_27 -> V_32 ( V_27 ) ;
return V_33 ;
}
return V_34 ;
}
static void F_23 ( void )
{
F_2 ( V_35 , V_36 ) ;
F_3 ( V_37 , ( 1 << 28 ) ) ;
F_3 ( V_38 , ( 1 << 10 ) ) ;
F_10 () ;
}
void T_2 F_24 ( void )
{
unsigned int V_28 = F_21 () ;
struct V_10 * V_27 ;
F_23 () ;
V_27 = & F_22 ( V_31 , V_28 ) ;
V_27 -> V_39 = L_3 ;
V_27 -> V_40 = 320 ;
V_27 -> V_41 = V_42 | V_43 ;
V_27 -> V_44 = F_16 ;
V_27 -> V_45 = F_11 ;
V_27 -> V_46 = F_17 ;
V_27 -> V_47 = F_18 ;
V_27 -> V_48 = F_19 ;
V_27 -> V_25 = V_49 ;
V_27 -> V_50 = F_25 ( V_28 ) ;
F_26 ( V_27 , V_51 ) ;
V_27 -> V_52 = F_27 ( 0x7fffffff , V_27 ) ;
V_27 -> V_53 = 5000 ;
F_28 ( V_27 ) ;
F_29 ( V_49 , & V_54 ) ;
F_13 ( L_4 ) ;
}
static T_3 F_30 ( struct V_55 * V_56 )
{
return ( T_3 ) F_4 ( V_9 ) ;
}
static void F_31 ( struct V_55 * V_56 )
{
}
static void F_32 ( struct V_55 * V_56 )
{
F_23 () ;
F_9 () ;
}
int T_2 F_33 ( void )
{
V_57 . V_58 = F_34 ( V_51 , V_57 . V_59 ) ;
return F_35 ( & V_57 , V_51 ) ;
}
