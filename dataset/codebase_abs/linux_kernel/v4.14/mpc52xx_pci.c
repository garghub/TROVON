static int
F_1 ( struct V_1 * V_2 , unsigned int V_3 ,
int V_4 , int V_5 , T_1 * V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
T_1 V_9 ;
if ( V_10 . V_11 )
if ( V_10 . V_11 ( V_8 , V_2 -> V_12 , V_3 ) )
return V_13 ;
F_3 ( V_8 -> V_14 ,
( 1 << 31 ) |
( V_2 -> V_12 << 16 ) |
( V_3 << 8 ) |
( V_4 & 0xfc ) ) ;
F_4 () ;
#if F_5 ( V_15 )
if ( V_2 -> V_12 ) {
switch ( V_5 ) {
case 1 :
V_9 = F_6 ( ( ( V_16 V_17 * ) V_8 -> V_18 ) +
( V_4 & 3 ) ) ;
break;
case 2 :
V_9 = F_7 ( ( ( V_19 V_17 * ) V_8 -> V_18 ) +
( ( V_4 >> 1 ) & 1 ) ) ;
break;
default:
V_9 = F_7 ( ( V_19 V_17 * ) V_8 -> V_18 ) |
( F_7 ( ( ( V_19 V_17 * ) V_8 -> V_18 ) + 1 ) << 16 ) ;
break;
}
}
else
#endif
{
V_9 = F_8 ( V_8 -> V_18 ) ;
if ( V_5 != 4 ) {
V_9 >>= ( ( V_4 & 0x3 ) << 3 ) ;
V_9 &= 0xffffffff >> ( 32 - ( V_5 << 3 ) ) ;
}
}
* V_6 = V_9 ;
F_3 ( V_8 -> V_14 , 0 ) ;
F_4 () ;
return V_20 ;
}
static int
F_9 ( struct V_1 * V_2 , unsigned int V_3 ,
int V_4 , int V_5 , T_1 V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
T_1 V_9 , V_21 ;
if ( V_10 . V_11 )
if ( V_10 . V_11 ( V_8 , V_2 -> V_12 , V_3 ) )
return V_13 ;
F_3 ( V_8 -> V_14 ,
( 1 << 31 ) |
( V_2 -> V_12 << 16 ) |
( V_3 << 8 ) |
( V_4 & 0xfc ) ) ;
F_4 () ;
#if F_5 ( V_15 )
if ( V_2 -> V_12 ) {
switch ( V_5 ) {
case 1 :
F_10 ( ( ( V_16 V_17 * ) V_8 -> V_18 ) +
( V_4 & 3 ) , V_6 ) ;
break;
case 2 :
F_11 ( ( ( V_19 V_17 * ) V_8 -> V_18 ) +
( ( V_4 >> 1 ) & 1 ) , V_6 ) ;
break;
default:
F_11 ( ( V_19 V_17 * ) V_8 -> V_18 ,
( V_19 ) V_6 ) ;
F_11 ( ( ( V_19 V_17 * ) V_8 -> V_18 ) + 1 ,
( V_19 ) ( V_6 >> 16 ) ) ;
break;
}
}
else
#endif
{
if ( V_5 != 4 ) {
V_9 = F_8 ( V_8 -> V_18 ) ;
V_4 = ( V_4 & 0x3 ) << 3 ;
V_21 = ( 0xffffffff >> ( 32 - ( V_5 << 3 ) ) ) ;
V_21 <<= V_4 ;
V_9 &= ~ V_21 ;
V_6 = V_9 | ( ( V_6 << V_4 ) & V_21 ) ;
}
F_12 ( V_8 -> V_18 , V_6 ) ;
}
F_4 () ;
F_3 ( V_8 -> V_14 , 0 ) ;
F_4 () ;
return V_20 ;
}
static void T_2
F_13 ( struct V_7 * V_8 ,
struct V_22 V_17 * V_23 , T_3 V_24 )
{
struct V_25 * V_26 ;
T_1 V_27 ;
int V_28 = 0 , V_29 = 0 , V_30 = 0 ;
F_14 ( L_1 , V_8 , V_23 ) ;
V_8 -> V_14 = & V_23 -> V_31 ;
V_8 -> V_18 = V_8 -> V_32 ;
V_27 = F_15 ( & V_23 -> V_33 ) ;
V_27 |= V_34 | V_35 ;
F_3 ( & V_23 -> V_33 , V_27 ) ;
V_26 = & V_8 -> V_36 [ 0 ] ;
if ( V_26 -> V_37 ) {
F_14 ( L_2
L_3 ,
( unsigned long long ) V_26 -> V_38 ,
( unsigned long long ) V_26 -> V_39 ,
( unsigned long long ) V_26 -> V_37 ) ;
F_3 ( & V_23 -> V_40 ,
F_16 ( V_26 -> V_38 , V_26 -> V_38 ,
F_17 ( V_26 ) ) ) ;
V_28 = V_41 | V_42 ;
if ( V_26 -> V_37 & V_43 )
V_28 |= V_44 ;
else
V_28 |= V_45 ;
}
V_26 = & V_8 -> V_36 [ 1 ] ;
if ( V_26 -> V_37 ) {
F_14 ( L_4 ,
V_26 -> V_38 , V_26 -> V_39 , V_26 -> V_37 ) ;
F_3 ( & V_23 -> V_46 ,
F_16 ( V_26 -> V_38 , V_26 -> V_38 ,
F_17 ( V_26 ) ) ) ;
V_29 = V_41 | V_42 ;
if ( V_26 -> V_37 & V_43 )
V_29 |= V_44 ;
else
V_29 |= V_45 ;
}
V_26 = & V_8 -> V_47 ;
if ( ! V_26 ) {
F_18 ( V_48 L_5 , __FILE__ ) ;
return;
}
F_14 ( L_6
L_7 ,
( unsigned long long ) V_26 -> V_38 ,
( unsigned long long ) V_26 -> V_39 ,
( unsigned long long ) V_26 -> V_37 , ( void * ) V_8 -> V_49 ) ;
F_3 ( & V_23 -> V_50 ,
F_16 ( V_8 -> V_49 ,
V_26 -> V_38 ,
F_17 ( V_26 ) ) ) ;
V_30 = V_41 | V_51 ;
F_3 ( & V_23 -> V_52 , F_19 ( V_28 , V_29 , V_30 ) ) ;
V_24 &= 0xfffc0000 ;
F_3 ( & V_23 -> V_53 , V_54 | V_24 ) ;
F_3 ( & V_23 -> V_55 , V_56 | V_24 ) ;
F_3 ( & V_23 -> V_57 , V_54 ) ;
F_3 ( & V_23 -> V_58 , V_56 ) ;
F_3 ( & V_23 -> V_59 , V_60 | V_61 ) ;
V_27 = F_15 ( & V_23 -> V_62 ) ;
#if 0
out_be32(&pci_regs->gscr, tmp | MPC52xx_PCI_GSCR_PR);
udelay(50);
#endif
F_3 ( & V_23 -> V_62 , V_27 & ~ V_63 ) ;
}
static void
F_20 ( struct V_64 * V_65 )
{
int V_66 ;
F_14 ( L_8 ,
V_65 -> V_67 , V_65 -> V_68 ) ;
for ( V_66 = 0 ; V_66 < V_69 ; V_66 ++ ) {
struct V_25 * V_26 = & V_65 -> V_25 [ V_66 ] ;
if ( V_26 -> V_39 > V_26 -> V_38 ) {
V_26 -> V_39 -= V_26 -> V_38 ;
V_26 -> V_38 = 0 ;
V_26 -> V_37 |= V_70 ;
}
}
if ( ( V_65 -> V_67 == V_71 ) &&
( V_65 -> V_68 == V_72
|| V_65 -> V_68 == V_73 ) ) {
struct V_25 * V_26 = & V_65 -> V_25 [ 1 ] ;
V_26 -> V_38 = V_26 -> V_39 = V_26 -> V_37 = 0 ;
}
}
int T_2
F_21 ( struct V_74 * V_75 )
{
int V_5 ;
struct V_22 V_17 * V_23 ;
struct V_7 * V_8 ;
const int * V_76 ;
struct V_25 V_77 ;
F_14 ( L_9 , V_75 ) ;
F_22 ( V_78 ) ;
if ( F_23 ( V_75 , 0 , & V_77 ) != 0 ) {
F_18 ( V_48 L_10 , V_75 ) ;
return - V_79 ;
}
V_76 = F_24 ( V_75 , L_11 , & V_5 ) ;
if ( V_76 == NULL || V_5 < 2 * sizeof( int ) ) {
F_18 ( V_80 L_12 ,
V_75 ) ;
V_76 = NULL ;
}
V_10 . V_81 = F_20 ;
V_8 = F_25 ( V_75 ) ;
if ( ! V_8 )
return - V_82 ;
V_8 -> V_83 = V_76 ? V_76 [ 0 ] : 0 ;
V_8 -> V_84 = V_76 ? V_76 [ 1 ] : 0xff ;
V_8 -> V_85 = & V_86 ;
V_23 = F_26 ( V_77 . V_38 , F_17 ( & V_77 ) ) ;
if ( ! V_23 )
return - V_82 ;
F_27 ( V_8 , V_75 , 1 ) ;
F_13 ( V_8 , V_23 , V_77 . V_38 ) ;
return 0 ;
}
void T_2 F_28 ( void )
{
struct V_74 * V_87 ;
V_87 = F_29 ( NULL , V_88 ) ;
if ( ! V_87 )
return;
F_21 ( V_87 ) ;
F_30 ( V_87 ) ;
}
