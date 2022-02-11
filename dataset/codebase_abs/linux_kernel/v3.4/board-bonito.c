static T_1 F_1 ( T_2 V_1 )
{
return F_2 ( 0xf0003000 + V_1 ) ;
}
static void F_3 ( T_2 V_1 , T_1 V_2 )
{
F_4 ( V_2 , 0xf0003000 + V_1 ) ;
}
static void F_5 ( struct V_3 * V_4 )
{
unsigned int V_5 = V_4 -> V_5 ;
T_2 V_6 = ( V_5 < 1016 ) ? V_7 : V_8 ;
int V_9 = V_5 % 16 ;
F_3 ( V_6 , F_1 ( V_6 ) | ( 1 << V_9 ) ) ;
}
static void F_6 ( struct V_3 * V_4 )
{
unsigned int V_5 = V_4 -> V_5 ;
T_2 V_6 = ( V_5 < 1016 ) ? V_7 : V_8 ;
int V_9 = V_5 % 16 ;
F_3 ( V_6 , F_1 ( V_6 ) & ~ ( 1 << V_9 ) ) ;
}
static void F_7 ( unsigned int V_5 , struct V_10 * V_11 )
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
F_8 ( V_16 + V_15 ) ;
}
}
static void F_9 ( void )
{
int V_15 ;
F_3 ( V_7 , 0xffff ) ;
F_3 ( V_8 , 0xffff ) ;
F_3 ( V_17 ,
( 1 << 2 ) ) ;
for ( V_15 = V_16 ; V_15 < V_16 + 32 ; V_15 ++ ) {
F_10 ( V_15 , & V_18 ,
V_19 , L_1 ) ;
F_11 ( V_15 , V_20 ) ;
}
F_12 ( F_13 ( 0x0340 ) , F_7 ) ;
F_14 ( F_13 ( 0x0340 ) , V_21 ) ;
}
static int T_3 F_15 ( void )
{
struct V_22 * V_23 = F_16 ( 0 ) ;
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
V_27 = F_17 ( V_23 , & V_25 , 1 ) ;
if ( V_27 < 0 ) {
F_18 ( L_2 ) ;
break;
}
}
return 0 ;
}
static void T_3 F_19 ( void )
{
F_20 () ;
F_21 ( V_31 , F_22 ( V_31 ) ) ;
}
static void T_3 F_23 ( void )
{
T_1 V_2 ;
F_24 () ;
F_9 () ;
V_28 = V_32 ;
#ifdef F_25
F_26 ( F_27 ( 0xf0002000 ) , 0x40440000 , 0x82000fff ) ;
#endif
F_28 () ;
F_29 ( V_33 ,
F_22 ( V_33 ) ) ;
F_30 ( V_34 , NULL ) ;
F_31 ( V_34 ) ;
if ( ! F_32 ( V_34 ) ) {
T_1 V_35 ;
T_1 V_36 ;
T_1 V_37 ;
F_30 ( V_38 , NULL ) ;
F_30 ( V_39 , NULL ) ;
F_30 ( V_40 , NULL ) ;
F_30 ( V_41 , NULL ) ;
V_2 = F_1 ( V_42 ) ;
F_33 ( L_3 ,
( ( V_2 >> 8 ) & 0xFF ) ,
( ( V_2 >> 0 ) & 0xFF ) ) ;
V_35 = F_1 ( V_43 ) ;
V_36 = F_1 ( V_44 ) ;
V_37 = F_1 ( V_45 ) ;
if ( F_34 ( V_35 , 1 ) &&
F_34 ( V_36 , 9 ) &&
F_34 ( V_37 , 4 ) ) {
F_30 ( V_46 , NULL ) ;
F_30 ( V_47 , NULL ) ;
}
if ( F_35 ( V_35 , 3 ) &&
F_35 ( V_35 , 2 ) ) {
F_30 ( V_48 , NULL ) ;
F_30 ( V_49 , NULL ) ;
F_30 ( V_50 , NULL ) ;
F_30 ( V_51 , NULL ) ;
F_30 ( V_52 , NULL ) ;
F_30 ( V_53 , NULL ) ;
F_30 ( V_54 , NULL ) ;
F_30 ( V_55 , NULL ) ;
F_30 ( V_56 , NULL ) ;
F_30 ( V_57 , NULL ) ;
F_30 ( V_58 , NULL ) ;
F_30 ( V_59 , NULL ) ;
F_30 ( V_60 , NULL ) ;
F_30 ( V_61 , NULL ) ;
F_30 ( V_62 , NULL ) ;
F_30 ( V_63 , NULL ) ;
F_30 ( V_64 , NULL ) ;
F_30 ( V_65 , NULL ) ;
F_30 ( V_66 , NULL ) ;
F_30 ( V_67 , NULL ) ;
F_30 ( V_68 , NULL ) ;
F_30 ( V_69 , NULL ) ;
F_30 ( V_70 , NULL ) ;
F_30 ( V_71 , NULL ) ;
F_30 ( V_72 , NULL ) ;
F_30 ( V_73 , NULL ) ;
F_30 ( V_74 , NULL ) ;
F_30 ( V_75 , NULL ) ;
F_30 ( V_76 , NULL ) ;
F_30 ( V_77 , NULL ) ;
F_30 ( V_78 , NULL ) ;
F_36 ( V_78 , 1 ) ;
F_3 ( V_79 , 1 ) ;
F_4 ( 0x00FF , V_80 ) ;
F_4 ( 0xFFFF , V_81 ) ;
}
F_29 ( V_82 ,
F_22 ( V_82 ) ) ;
}
}
static void T_3 F_37 ( void )
{
T_1 V_2 ;
T_5 V_83 = 0 ;
V_2 = F_1 ( V_84 ) ;
if ( V_2 & ( 1 << 10 ) )
V_83 |= V_85 ;
if ( V_2 & ( 1 << 9 ) )
V_83 |= V_86 ;
if ( V_2 & ( 1 << 8 ) )
V_83 |= V_87 ;
F_38 ( V_83 ) ;
F_39 () ;
}
void T_3 F_40 ( void )
{
F_41 () ;
V_88 . V_89 = F_37 ;
}
