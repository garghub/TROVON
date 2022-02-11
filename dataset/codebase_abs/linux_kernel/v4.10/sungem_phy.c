static inline int F_1 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
return V_2 -> V_5 ( V_2 -> V_6 , V_3 , V_4 ) ;
}
static inline void F_2 ( struct V_1 * V_2 , int V_3 , int V_4 , int V_7 )
{
V_2 -> V_8 ( V_2 -> V_6 , V_3 , V_4 , V_7 ) ;
}
static inline int F_3 ( struct V_1 * V_2 , int V_4 )
{
return V_2 -> V_5 ( V_2 -> V_6 , V_2 -> V_9 , V_4 ) ;
}
static inline void F_4 ( struct V_1 * V_2 , int V_4 , int V_7 )
{
V_2 -> V_8 ( V_2 -> V_6 , V_2 -> V_9 , V_4 , V_7 ) ;
}
static int F_5 ( struct V_1 * V_2 , int V_10 )
{
T_1 V_7 ;
int V_11 = 10000 ;
V_7 = F_1 ( V_2 , V_10 , V_12 ) ;
V_7 &= ~ ( V_13 | V_14 ) ;
V_7 |= V_15 ;
F_2 ( V_2 , V_10 , V_12 , V_7 ) ;
F_6 ( 100 ) ;
while ( -- V_11 ) {
V_7 = F_1 ( V_2 , V_10 , V_12 ) ;
if ( ( V_7 & V_15 ) == 0 )
break;
F_6 ( 10 ) ;
}
if ( ( V_7 & V_13 ) && V_11 > 0 )
F_2 ( V_2 , V_10 , V_12 , V_7 & ~ V_13 ) ;
return V_11 <= 0 ;
}
static int F_7 ( struct V_1 * V_2 )
{
T_1 V_16 ;
V_16 = F_3 ( V_2 , V_17 ) ;
V_16 &= ~ V_18 ;
F_4 ( V_2 , V_17 , V_16 ) ;
F_4 ( V_2 , V_19 , 0 ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 )
{
F_4 ( V_2 , V_19 , 0 ) ;
F_4 ( V_2 , V_17 , V_18 ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 )
{
T_1 V_16 ;
V_16 = F_3 ( V_2 , V_20 ) ;
F_4 ( V_2 , V_20 ,
V_16 | V_21 ) ;
V_16 = F_3 ( V_2 , V_22 ) ;
F_4 ( V_2 , V_22 ,
V_16 | V_23 ) ;
V_16 = F_3 ( V_2 , V_24 ) ;
F_4 ( V_2 , V_24 ,
V_16 | V_25 ) ;
V_16 = F_3 ( V_2 , V_20 ) ;
F_4 ( V_2 , V_20 ,
V_16 & ~ V_21 ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 )
{
T_1 V_16 ;
V_16 = F_3 ( V_2 , V_20 ) ;
F_4 ( V_2 , V_20 ,
V_16 | V_21 ) ;
V_16 = F_3 ( V_2 , V_24 ) ;
F_4 ( V_2 , V_24 ,
V_16 | V_26 ) ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 )
{
T_1 V_16 ;
V_16 = F_3 ( V_2 , V_20 ) ;
F_4 ( V_2 , V_20 ,
V_16 | V_21 ) ;
V_16 = F_3 ( V_2 , V_22 ) ;
F_4 ( V_2 , V_22 ,
V_16 | V_23 ) ;
V_16 = F_3 ( V_2 , V_24 ) ;
F_4 ( V_2 , V_24 ,
V_16 & ~ V_27 ) ;
V_16 = F_3 ( V_2 , V_20 ) ;
F_4 ( V_2 , V_20 ,
V_16 & ~ V_21 ) ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 )
{
T_1 V_16 ;
V_16 = F_3 ( V_2 , V_20 ) ;
F_4 ( V_2 , V_20 ,
V_16 | V_21 ) ;
V_16 = F_3 ( V_2 , V_24 ) ;
F_4 ( V_2 , V_24 ,
V_16 | V_27 ) ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 )
{
T_1 V_16 ;
V_16 = F_3 ( V_2 , V_28 ) ;
V_16 |= V_29 ;
F_4 ( V_2 , V_28 , V_16 ) ;
V_16 = F_3 ( V_2 , V_30 ) ;
V_16 |= V_31 ;
F_4 ( V_2 , V_30 , V_16 ) ;
F_6 ( 100 ) ;
( void ) F_5 ( V_2 , 0x1f ) ;
V_16 = F_1 ( V_2 , 0x1f , V_17 ) ;
V_16 |= V_32 ;
F_2 ( V_2 , 0x1f , V_17 , V_16 ) ;
V_16 = F_3 ( V_2 , V_28 ) ;
V_16 &= ~ V_29 ;
F_4 ( V_2 , V_28 , V_16 ) ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 )
{
#if 0
sungem_phy_write(phy, MII_BMCR, BMCR_PDOWN);
#endif
return 0 ;
}
static int F_15 ( struct V_1 * V_2 )
{
T_1 V_16 ;
int V_33 ;
V_33 = F_3 ( V_2 , V_34 ) & 0x000f ;
if ( V_33 == 0 || V_33 == 3 ) {
F_4 ( V_2 , 0x18 , 0x0c20 ) ;
F_4 ( V_2 , 0x17 , 0x0012 ) ;
F_4 ( V_2 , 0x15 , 0x1804 ) ;
F_4 ( V_2 , 0x17 , 0x0013 ) ;
F_4 ( V_2 , 0x15 , 0x1204 ) ;
F_4 ( V_2 , 0x17 , 0x8006 ) ;
F_4 ( V_2 , 0x15 , 0x0132 ) ;
F_4 ( V_2 , 0x17 , 0x8006 ) ;
F_4 ( V_2 , 0x15 , 0x0232 ) ;
F_4 ( V_2 , 0x17 , 0x201f ) ;
F_4 ( V_2 , 0x15 , 0x0a20 ) ;
}
V_16 = F_3 ( V_2 , V_30 ) ;
V_16 |= V_31 ;
F_4 ( V_2 , V_30 , V_16 ) ;
F_6 ( 10 ) ;
( void ) F_5 ( V_2 , 0x1f ) ;
V_16 = F_1 ( V_2 , 0x1f , V_17 ) ;
V_16 |= V_32 ;
F_2 ( V_2 , 0x1f , V_17 , V_16 ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 )
{
#if 0
sungem_phy_write(phy, MII_BMCR, BMCR_PDOWN);
#endif
return 0 ;
}
static int F_17 ( struct V_1 * V_2 )
{
T_1 V_16 ;
F_4 ( V_2 , 0x1c , 0x8c23 ) ;
F_4 ( V_2 , 0x1c , 0x8ca3 ) ;
F_4 ( V_2 , 0x1c , 0x8c23 ) ;
F_4 ( V_2 , V_12 , V_15 ) ;
F_4 ( V_2 , V_12 , 0x1340 ) ;
V_16 = F_3 ( V_2 , V_30 ) ;
V_16 |= V_31 ;
F_4 ( V_2 , V_30 , V_16 ) ;
F_6 ( 10 ) ;
( void ) F_5 ( V_2 , 0x1f ) ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 , T_2 V_35 )
{
T_1 V_36 , V_37 ;
V_2 -> V_38 = 1 ;
V_2 -> V_39 = V_40 ;
V_2 -> V_41 = V_42 ;
V_2 -> V_43 = 0 ;
V_2 -> V_44 = V_35 ;
V_37 = F_3 ( V_2 , V_45 ) ;
V_37 &= ~ ( V_46 | V_47 ) ;
if ( V_35 & V_48 )
V_37 |= V_49 ;
if ( V_35 & V_50 )
V_37 |= V_51 ;
if ( V_35 & V_52 )
V_37 |= V_53 ;
if ( V_35 & V_54 )
V_37 |= V_55 ;
F_4 ( V_2 , V_45 , V_37 ) ;
V_36 = F_3 ( V_2 , V_12 ) ;
V_36 |= ( V_56 | V_57 ) ;
F_4 ( V_2 , V_12 , V_36 ) ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 , int V_39 , int V_58 )
{
T_1 V_36 ;
V_2 -> V_38 = 0 ;
V_2 -> V_39 = V_39 ;
V_2 -> V_41 = V_58 ;
V_2 -> V_43 = 0 ;
V_36 = F_3 ( V_2 , V_12 ) ;
V_36 &= ~ ( V_59 | V_60 | V_56 ) ;
F_4 ( V_2 , V_12 , V_36 | V_15 ) ;
switch( V_39 ) {
case V_40 :
break;
case V_61 :
V_36 |= V_60 ;
break;
case V_62 :
default:
return - V_63 ;
}
if ( V_58 == V_64 )
V_36 |= V_59 ;
F_4 ( V_2 , V_12 , V_36 ) ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 )
{
T_1 V_65 ;
( void ) F_3 ( V_2 , V_66 ) ;
V_65 = F_3 ( V_2 , V_66 ) ;
if ( ( V_65 & V_67 ) == 0 )
return 0 ;
if ( V_2 -> V_38 && ! ( V_65 & V_68 ) )
return 0 ;
return 1 ;
}
static int F_21 ( struct V_1 * V_2 )
{
T_1 V_69 ;
if ( V_2 -> V_38 ) {
V_69 = F_3 ( V_2 , V_70 ) ;
if ( V_69 & ( V_71 | V_72 ) )
V_2 -> V_41 = V_64 ;
else
V_2 -> V_41 = V_42 ;
if ( V_69 & ( V_72 | V_73 ) )
V_2 -> V_39 = V_61 ;
else
V_2 -> V_39 = V_40 ;
V_2 -> V_43 = 0 ;
}
return 0 ;
}
static int F_22 ( struct V_1 * V_2 )
{
F_4 ( V_2 , V_12 , V_14 ) ;
return 0 ;
}
static int F_23 ( struct V_1 * V_2 )
{
T_1 V_16 ;
unsigned int V_3 ;
V_3 = ( F_3 ( V_2 , V_74 ) << 16 | F_3 ( V_2 , V_34 ) ) ;
if ( V_3 == 0x002060e0 ) {
F_4 ( V_2 , 0x18 , 0x1007 ) ;
V_16 = F_3 ( V_2 , 0x18 ) ;
F_4 ( V_2 , 0x18 , V_16 | 0x0400 ) ;
F_4 ( V_2 , 0x18 , 0x0007 ) ;
V_16 = F_3 ( V_2 , 0x18 ) ;
F_4 ( V_2 , 0x18 , V_16 | 0x0800 ) ;
F_4 ( V_2 , 0x17 , 0x000a ) ;
V_16 = F_3 ( V_2 , 0x15 ) ;
F_4 ( V_2 , 0x15 , V_16 | 0x0200 ) ;
}
if ( ( V_3 & 0xfffffff0 ) == 0x002062e0 ) {
F_4 ( V_2 , 4 , 0x01e1 ) ;
F_4 ( V_2 , 9 , 0x0300 ) ;
}
#ifdef F_24
if ( V_2 -> V_75 ) {
struct V_76 * V_77 = F_25 ( V_2 -> V_75 ) ;
int V_78 = 1 ;
if ( V_77 == NULL || F_26 ( V_77 , L_1 , NULL ) )
V_78 = 0 ;
if ( V_78 ) {
F_4 ( V_2 , 0x1c , 0x9002 ) ;
F_4 ( V_2 , 0x1c , 0xa821 ) ;
F_4 ( V_2 , 0x1c , 0x941d ) ;
}
}
#endif
return 0 ;
}
static int F_27 ( struct V_1 * V_2 , T_2 V_35 )
{
T_1 V_36 , V_37 ;
V_2 -> V_38 = 1 ;
V_2 -> V_39 = V_40 ;
V_2 -> V_41 = V_42 ;
V_2 -> V_43 = 0 ;
V_2 -> V_44 = V_35 ;
V_37 = F_3 ( V_2 , V_45 ) ;
V_37 &= ~ ( V_46 | V_47 ) ;
if ( V_35 & V_48 )
V_37 |= V_49 ;
if ( V_35 & V_50 )
V_37 |= V_51 ;
if ( V_35 & V_52 )
V_37 |= V_53 ;
if ( V_35 & V_54 )
V_37 |= V_55 ;
if ( V_35 & V_79 )
V_37 |= V_80 ;
if ( V_35 & V_81 )
V_37 |= V_82 ;
F_4 ( V_2 , V_45 , V_37 ) ;
V_37 = F_3 ( V_2 , V_83 ) ;
V_37 &= ~ ( V_84 | V_85 ) ;
if ( V_35 & V_86 )
V_37 |= V_85 ;
if ( V_35 & V_87 )
V_37 |= V_84 ;
F_4 ( V_2 , V_83 , V_37 ) ;
V_36 = F_3 ( V_2 , V_12 ) ;
V_36 |= ( V_56 | V_57 ) ;
F_4 ( V_2 , V_12 , V_36 ) ;
return 0 ;
}
static int F_28 ( struct V_1 * V_2 , int V_39 , int V_58 )
{
T_1 V_36 ;
V_2 -> V_38 = 0 ;
V_2 -> V_39 = V_39 ;
V_2 -> V_41 = V_58 ;
V_2 -> V_43 = 0 ;
V_36 = F_3 ( V_2 , V_12 ) ;
V_36 &= ~ ( V_59 | V_60 | V_88 | V_56 ) ;
F_4 ( V_2 , V_12 , V_36 | V_15 ) ;
switch( V_39 ) {
case V_40 :
break;
case V_61 :
V_36 |= V_60 ;
break;
case V_62 :
V_36 |= V_88 ;
}
if ( V_58 == V_64 )
V_36 |= V_59 ;
F_4 ( V_2 , V_12 , V_36 ) ;
return 0 ;
}
static int F_29 ( struct V_1 * V_2 )
{
int V_89 ;
T_1 V_7 ;
if ( V_2 -> V_38 ) {
V_7 = F_3 ( V_2 , V_90 ) ;
V_89 = ( ( V_7 & V_91 ) >>
V_92 ) ;
V_2 -> V_41 = V_93 [ V_89 ] [ 0 ] ?
V_64 : V_42 ;
V_2 -> V_39 = V_93 [ V_89 ] [ 2 ] ?
V_62 :
( V_93 [ V_89 ] [ 1 ] ?
V_61 : V_40 ) ;
V_7 = F_3 ( V_2 , V_70 ) ;
V_2 -> V_43 = ( V_2 -> V_41 == V_64 ) &&
( ( V_7 & V_94 ) != 0 ) ;
}
return 0 ;
}
static int F_30 ( struct V_1 * V_2 )
{
T_1 V_33 ;
V_33 = F_3 ( V_2 , V_34 ) & 0x000f ;
if ( V_33 == 0 ) {
F_4 ( V_2 , 0x1d , 0x000a ) ;
F_4 ( V_2 , 0x1e , 0x0821 ) ;
F_4 ( V_2 , 0x1d , 0x0006 ) ;
F_4 ( V_2 , 0x1e , 0x8600 ) ;
F_4 ( V_2 , 0x1d , 0x000b ) ;
F_4 ( V_2 , 0x1e , 0x0100 ) ;
F_4 ( V_2 , 0x1d , 0x0004 ) ;
F_4 ( V_2 , 0x1e , 0x4850 ) ;
}
return 0 ;
}
static int F_31 ( struct V_1 * V_2 )
{
T_2 V_95 ;
int V_96 ;
F_4 ( V_2 , V_97 , 0x1000 ) ;
V_95 = F_3 ( V_2 , V_97 ) ;
V_96 = ( V_95 & V_98 ) >> 5 ;
if ( V_96 == V_99 )
return F_20 ( V_2 ) ;
F_4 ( V_2 , V_97 , 0x2000 ) ;
V_95 = F_3 ( V_2 , V_97 ) ;
if ( V_95 & 0x0020 )
return 0 ;
else
return 1 ;
}
static int F_32 ( struct V_1 * V_2 )
{
T_2 V_95 ;
int V_96 ;
F_4 ( V_2 , V_97 , 0x1000 ) ;
V_95 = F_3 ( V_2 , V_97 ) ;
V_96 = ( V_95 & V_98 ) >> 5 ;
if ( V_96 == V_99 )
return F_29 ( V_2 ) ;
V_2 -> V_39 = V_62 ;
F_4 ( V_2 , V_97 , 0x2000 ) ;
V_95 = F_3 ( V_2 , V_97 ) ;
if ( ( V_95 & 0x0080 ) >> 7 )
V_2 -> V_41 |= V_42 ;
else
V_2 -> V_41 |= V_64 ;
return 0 ;
}
static int F_33 ( struct V_1 * V_2 , int V_38 )
{
F_4 ( V_2 , V_97 , 0x9020 ) ;
F_4 ( V_2 , V_97 , 0x945f ) ;
if ( ! V_38 ) {
F_4 ( V_2 , V_97 , 0xfc01 ) ;
F_4 ( V_2 , 0x0b , 0x0004 ) ;
}
V_2 -> V_38 = V_38 ;
return 0 ;
}
static int F_34 ( struct V_1 * V_2 )
{
T_2 V_95 ;
int V_96 ;
F_4 ( V_2 , V_97 , 0x7c00 ) ;
V_95 = F_3 ( V_2 , V_97 ) ;
V_96 = ( V_95 & V_100 ) >> 1 ;
if ( V_96 == V_99 )
return F_20 ( V_2 ) ;
F_4 ( V_2 , V_97 , 0x7000 ) ;
V_95 = F_3 ( V_2 , V_97 ) ;
if ( V_95 & V_101 )
return 1 ;
else
return 0 ;
}
static int F_35 ( struct V_1 * V_2 )
{
T_2 V_95 ;
int V_96 ;
F_4 ( V_2 , V_97 , 0x7c00 ) ;
V_95 = F_3 ( V_2 , V_97 ) ;
V_96 = ( V_95 & V_100 ) >> 1 ;
if ( V_96 == V_99 ) {
return F_29 ( V_2 ) ;
}
V_2 -> V_39 = V_62 ;
F_4 ( V_2 , V_97 , 0x7000 ) ;
V_95 = F_3 ( V_2 , V_97 ) ;
if ( V_95 & V_102 )
V_2 -> V_41 |= V_64 ;
else
V_2 -> V_41 |= V_42 ;
return 0 ;
}
static int F_36 ( struct V_1 * V_2 , int V_38 )
{
F_4 ( V_2 , V_97 , 0xfc0b ) ;
if ( V_38 ) {
F_4 ( V_2 , V_45 , 0x01e0 ) ;
F_4 ( V_2 , V_12 , 0x1140 ) ;
} else {
F_4 ( V_2 , V_12 , 0x0140 ) ;
}
V_2 -> V_38 = V_38 ;
return 0 ;
}
static int F_37 ( struct V_1 * V_2 , T_2 V_35 )
{
T_1 V_36 , V_37 ;
V_2 -> V_38 = 1 ;
V_2 -> V_39 = V_40 ;
V_2 -> V_41 = V_42 ;
V_2 -> V_43 = 0 ;
V_2 -> V_44 = V_35 ;
V_37 = F_3 ( V_2 , V_45 ) ;
V_37 &= ~ ( V_46 | V_47 ) ;
if ( V_35 & V_48 )
V_37 |= V_49 ;
if ( V_35 & V_50 )
V_37 |= V_51 ;
if ( V_35 & V_52 )
V_37 |= V_53 ;
if ( V_35 & V_54 )
V_37 |= V_55 ;
if ( V_35 & V_79 )
V_37 |= V_80 ;
if ( V_35 & V_81 )
V_37 |= V_82 ;
F_4 ( V_2 , V_45 , V_37 ) ;
V_37 = F_3 ( V_2 , V_103 ) ;
V_37 |= V_104 ;
V_37 &= ~ ( V_84 |
V_85 ) ;
if ( V_35 & V_86 )
V_37 |= V_85 ;
if ( V_35 & V_87 )
V_37 |= V_84 ;
F_4 ( V_2 , V_83 , V_37 ) ;
V_36 = F_3 ( V_2 , V_12 ) ;
V_36 |= ( V_56 | V_57 ) ;
F_4 ( V_2 , V_12 , V_36 ) ;
return 0 ;
}
static int F_38 ( struct V_1 * V_2 , int V_39 , int V_58 )
{
T_1 V_36 , V_105 ;
V_2 -> V_38 = 0 ;
V_2 -> V_39 = V_39 ;
V_2 -> V_41 = V_58 ;
V_2 -> V_43 = 0 ;
V_36 = F_3 ( V_2 , V_12 ) ;
V_36 &= ~ ( V_59 | V_60 | V_88 | V_56 ) ;
V_36 |= V_15 ;
switch( V_39 ) {
case V_40 :
break;
case V_61 :
V_36 |= V_60 ;
break;
case V_62 :
V_36 |= V_88 ;
}
if ( V_58 == V_64 )
V_36 |= V_59 ;
V_105 = F_3 ( V_2 , V_103 ) ;
V_105 &= ~ ( V_106 |
V_104 |
V_84 |
V_85 ) ;
if ( V_39 == V_62 )
V_105 |= ( V_58 == V_64 ) ?
V_84 :
V_85 ;
F_4 ( V_2 , V_83 , V_105 ) ;
F_4 ( V_2 , V_12 , V_36 ) ;
return 0 ;
}
static int F_39 ( struct V_1 * V_2 )
{
T_1 V_65 , V_107 ;
if ( V_2 -> V_38 ) {
V_65 = F_3 ( V_2 , V_108 ) ;
if ( ( V_65 & V_109 ) == 0 )
return - V_110 ;
if ( V_65 & V_111 )
V_2 -> V_39 = V_62 ;
else if ( V_65 & V_112 )
V_2 -> V_39 = V_61 ;
else
V_2 -> V_39 = V_40 ;
if ( V_65 & V_113 )
V_2 -> V_41 = V_64 ;
else
V_2 -> V_41 = V_42 ;
V_107 = V_114 |
V_115 ;
V_2 -> V_43 = ( V_65 & V_107 ) == V_107 ;
}
return 0 ;
}
int F_40 ( struct V_1 * V_2 , int V_9 )
{
int V_116 ;
T_2 V_3 ;
struct V_117 * V_118 ;
int V_119 ;
V_2 -> V_9 = V_9 ;
V_116 = F_5 ( V_2 , V_9 ) ;
if ( V_116 )
goto V_120;
V_3 = ( F_3 ( V_2 , V_74 ) << 16 | F_3 ( V_2 , V_34 ) ) ;
F_41 (KERN_DEBUG KBUILD_MODNAME L_2 L_3 ,
id, mii_id) ;
for ( V_119 = 0 ; ( V_118 = V_121 [ V_119 ] ) != NULL ; V_119 ++ )
if ( ( V_3 & V_118 -> V_122 ) == V_118 -> V_10 )
break;
if ( V_118 == NULL )
goto V_120;
V_2 -> V_118 = V_118 ;
return 0 ;
V_120:
V_2 -> V_39 = 0 ;
V_2 -> V_41 = 0 ;
V_2 -> V_43 = 0 ;
V_2 -> V_44 = 0 ;
return - V_123 ;
}
