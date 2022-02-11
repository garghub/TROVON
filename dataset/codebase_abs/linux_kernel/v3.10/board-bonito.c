static T_1 F_1 ( T_2 V_1 )
{
return F_2 ( F_3 ( 0xf0003000 ) + V_1 ) ;
}
static void F_4 ( T_2 V_1 , T_1 V_2 )
{
F_5 ( V_2 , F_3 ( 0xf0003000 ) + V_1 ) ;
}
static void F_6 ( struct V_3 * V_4 )
{
unsigned int V_5 = V_4 -> V_5 ;
T_2 V_6 = ( V_5 < 1016 ) ? V_7 : V_8 ;
int V_9 = V_5 % 16 ;
F_4 ( V_6 , F_1 ( V_6 ) | ( 1 << V_9 ) ) ;
}
static void F_7 ( struct V_3 * V_4 )
{
unsigned int V_5 = V_4 -> V_5 ;
T_2 V_6 = ( V_5 < 1016 ) ? V_7 : V_8 ;
int V_9 = V_5 % 16 ;
F_4 ( V_6 , F_1 ( V_6 ) & ~ ( 1 << V_9 ) ) ;
}
static void F_8 ( unsigned int V_5 , struct V_10 * V_11 )
{
T_2 V_2 = F_1 ( V_12 ) << 16 |
F_1 ( V_13 ) ;
T_2 V_14 = F_1 ( V_8 ) << 16 |
F_1 ( V_7 ) ;
int V_15 ;
V_2 &= ~ V_14 ;
for ( V_15 = 0 ; V_15 < 32 ; V_15 ++ ) {
if ( ! ( V_2 & ( 1 << V_15 ) ) )
continue;
F_9 ( V_16 + V_15 ) ;
}
}
static void F_10 ( void )
{
int V_15 ;
F_4 ( V_7 , 0xffff ) ;
F_4 ( V_8 , 0xffff ) ;
F_4 ( V_17 ,
( 1 << 2 ) ) ;
for ( V_15 = V_16 ; V_15 < V_16 + 32 ; V_15 ++ ) {
F_11 ( V_15 , & V_18 ,
V_19 , L_1 ) ;
F_12 ( V_15 , V_20 ) ;
}
F_13 ( F_14 ( 0x0340 ) , F_8 ) ;
F_15 ( F_14 ( 0x0340 ) , V_21 ) ;
}
static int T_3 F_16 ( void )
{
struct V_22 * V_23 = F_17 ( 0 ) ;
struct V_24 V_25 ;
T_4 V_26 [ 2 ] ;
int V_15 , V_27 ;
if ( ! V_28 )
return 0 ;
if ( ! V_23 )
return 0 ;
V_25 . V_6 = 0x46 ;
V_25 . V_26 = V_26 ;
V_25 . V_29 = 2 ;
V_25 . V_30 = 0 ;
for ( V_15 = 0 ; ; V_15 += 2 ) {
V_26 [ 0 ] = V_28 [ V_15 + 0 ] ;
V_26 [ 1 ] = V_28 [ V_15 + 1 ] ;
if ( ( 0xff == V_26 [ 0 ] ) && ( 0xff == V_26 [ 1 ] ) )
break;
V_27 = F_18 ( V_23 , & V_25 , 1 ) ;
if ( V_27 < 0 ) {
F_19 ( L_2 ) ;
break;
}
}
return 0 ;
}
static void T_3 F_20 ( void )
{
F_21 () ;
F_22 ( V_31 , F_23 ( V_31 ) ) ;
}
static void T_3 F_24 ( void )
{
T_1 V_2 ;
F_25 ( 0 , V_32 , F_23 ( V_32 ) ) ;
F_26 () ;
F_10 () ;
V_28 = V_33 ;
#ifdef F_27
F_28 ( F_3 ( 0xf0002000 ) , 0x40440000 , 0x82000fff ) ;
#endif
F_29 () ;
F_30 ( V_34 ,
F_23 ( V_34 ) ) ;
F_31 ( 176 , V_35 , NULL ) ;
if ( ! F_32 ( 176 ) ) {
T_1 V_36 ;
T_1 V_37 ;
T_1 V_38 ;
F_33 ( V_39 , NULL ) ;
F_33 ( V_40 , NULL ) ;
F_33 ( V_41 , NULL ) ;
F_33 ( V_42 , NULL ) ;
V_2 = F_1 ( V_43 ) ;
F_34 ( L_3 ,
( ( V_2 >> 8 ) & 0xFF ) ,
( ( V_2 >> 0 ) & 0xFF ) ) ;
V_36 = F_1 ( V_44 ) ;
V_37 = F_1 ( V_45 ) ;
V_38 = F_1 ( V_46 ) ;
if ( F_35 ( V_36 , 1 ) &&
F_35 ( V_37 , 9 ) &&
F_35 ( V_38 , 4 ) ) {
F_33 ( V_47 , NULL ) ;
F_33 ( V_48 , NULL ) ;
}
if ( F_36 ( V_36 , 3 ) &&
F_36 ( V_36 , 2 ) ) {
F_37 ( V_49 ,
F_23 ( V_49 ) ) ;
F_33 ( V_50 , NULL ) ;
F_31 ( 61 , V_51 ,
NULL ) ;
F_4 ( V_52 , 1 ) ;
F_5 ( 0x00FF , V_53 ) ;
F_5 ( 0xFFFF , V_54 ) ;
}
F_30 ( V_55 ,
F_23 ( V_55 ) ) ;
}
}
static void T_3 F_38 ( void )
{
T_1 V_2 ;
T_5 V_56 = 0 ;
V_2 = F_1 ( V_57 ) ;
if ( V_2 & ( 1 << 10 ) )
V_56 |= V_58 ;
if ( V_2 & ( 1 << 9 ) )
V_56 |= V_59 ;
if ( V_2 & ( 1 << 8 ) )
V_56 |= V_60 ;
F_39 ( V_56 ) ;
F_40 () ;
}
static void T_3 F_41 ( void )
{
F_42 () ;
}
