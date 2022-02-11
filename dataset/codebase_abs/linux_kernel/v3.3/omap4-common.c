void F_1 ( void )
{
if ( V_1 && V_2 ) {
F_2 ( F_3 ( V_1 ) , V_1 ) ;
F_2 ( F_3 ( V_2 ) , V_2 ) ;
F_4 () ;
}
}
int T_1 F_5 ( void )
{
V_3 = F_6 ( V_4 , V_5 ) ;
V_6 = F_7 ( V_3 , V_5 ) ;
return 0 ;
}
void T_1 F_8 ( void )
{
struct V_7 V_8 [ 1 ] ;
V_8 [ 0 ] . V_9 = V_10 ;
V_8 [ 0 ] . V_11 = F_9 ( V_6 ) ;
V_8 [ 0 ] . V_12 = V_3 ;
V_8 [ 0 ] . type = V_13 ;
F_10 ( V_8 , F_11 ( V_8 ) ) ;
V_1 = ( void V_14 * ) V_8 [ 0 ] . V_9 ;
V_2 = ( void V_14 * ) V_15 ;
F_12 ( L_1 ,
( long long ) V_6 , V_8 [ 0 ] . V_9 ) ;
}
void T_1 F_8 ( void )
{}
void T_1 F_13 ( void )
{
void V_14 * V_16 ;
void V_14 * V_17 ;
V_17 = F_14 ( V_18 , V_19 ) ;
F_15 ( ! V_17 ) ;
V_16 = F_14 ( V_20 , V_21 ) ;
F_15 ( ! V_16 ) ;
F_16 () ;
F_17 ( 0 , 29 , V_17 , V_16 ) ;
}
void V_14 * F_18 ( void )
{
return V_22 ;
}
static void F_19 ( void )
{
F_20 ( 0x102 , 0x0 ) ;
}
static void F_21 ( unsigned long V_23 )
{
F_20 ( 0x100 , V_23 ) ;
}
static int T_1 F_22 ( void )
{
T_2 V_24 = 0 ;
if ( ! F_23 () )
return - V_25 ;
V_22 = F_14 ( V_26 , V_19 ) ;
if ( F_24 ( ! V_22 ) )
return - V_27 ;
V_24 = ( ( 1 << V_28 ) |
( 0x1 << 25 ) |
( 0x1 << V_29 ) |
( 0x1 << V_30 ) ) ;
if ( F_25 () == V_31 ) {
V_24 |= 0x2 << V_32 ;
} else {
V_24 |= ( ( 0x3 << V_32 ) |
( 1 << V_33 ) |
( 1 << V_34 ) |
( 1 << V_35 ) |
( 1 << V_36 ) ) ;
}
if ( F_25 () != V_31 )
F_20 ( 0x109 , V_24 ) ;
F_20 ( 0x102 , 0x1 ) ;
F_26 ( V_22 , V_24 , V_37 ) ;
V_38 . V_39 = F_19 ;
V_38 . V_40 = F_21 ;
return 0 ;
}
void V_14 * F_27 ( void )
{
return V_41 ;
}
static int T_1 F_28 ( void )
{
if ( ! F_23 () )
return - V_27 ;
V_41 = F_14 ( V_42 , V_43 ) ;
if ( F_24 ( ! V_41 ) )
return - V_27 ;
return 0 ;
}
