static inline void T_1 * F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
return V_2 -> V_4 -> V_5 [ V_6 ] + V_2 -> V_7 * 0x100 + V_3 ;
}
static inline void T_1 * F_2 ( struct V_1 * V_2 , struct V_8 * V_9 , unsigned int V_3 )
{
T_2 V_10 = ( V_9 -> V_11 ) ? 0x08 : 0x00 ;
return F_1 ( V_2 , V_3 ) + V_10 ;
}
static int F_3 ( struct V_1 * V_2 )
{
T_3 V_12 ;
V_12 = F_4 ( F_1 ( V_2 , V_13 ) ) ;
if ( V_12 & ( 1 << 26 ) )
goto V_14;
F_5 ( L_1 , V_2 -> V_7 ) ;
return V_15 ;
V_14:
F_6 (KERN_INFO DRV_NAME L_2 , ap->port_no) ;
return V_16 ;
}
static inline int F_7 ( struct V_1 * V_2 )
{
return F_8 ( F_1 ( V_2 , V_17 ) ) & 0x02 ;
}
static int F_9 ( struct V_18 * V_19 , unsigned long V_20 )
{
if ( ! F_7 ( V_19 -> V_2 ) )
return - V_21 ;
return F_10 ( V_19 , V_20 ) ;
}
static unsigned long F_11 ( struct V_8 * V_9 , unsigned long V_22 )
{
unsigned char V_23 [ V_24 + 1 ] ;
struct V_8 * V_25 = F_12 ( V_9 ) ;
if ( V_9 -> V_26 != V_27 || V_9 -> V_11 == 0 || V_25 == NULL )
return V_22 ;
F_13 ( V_25 -> V_28 , V_23 , V_29 ,
V_24 + 1 ) ;
if ( strstr ( V_23 , L_3 ) == NULL && V_25 -> V_30 == V_31 )
V_22 &= ~ ( 1 << ( 6 + V_32 ) ) ;
return V_22 ;
}
static void F_14 ( struct V_1 * V_2 , struct V_8 * V_9 )
{
unsigned int V_33 = V_9 -> V_34 - V_35 ;
T_3 V_36 , V_37 ;
F_5 ( L_4 , V_9 -> V_34 ) ;
if ( V_33 > 4 ) {
F_6 (KERN_ERR DRV_NAME L_5 , pio) ;
return;
}
F_5 ( L_6 ) ;
V_36 = F_4 ( F_2 ( V_2 , V_9 , V_38 ) ) ;
V_36 &= 0xffff0000 ;
V_36 |= V_39 [ V_33 ] . V_40 |
( V_39 [ V_33 ] . V_41 << 8 ) ;
F_15 ( V_36 , F_2 ( V_2 , V_9 , V_38 ) ) ;
V_37 = F_4 ( F_2 ( V_2 , V_9 , V_42 ) ) ;
V_37 &= 0x00ffffff ;
V_37 |= ( V_39 [ V_33 ] . V_43 << 24 ) ;
F_15 ( V_37 , F_2 ( V_2 , V_9 , V_42 ) ) ;
F_5 ( L_7 ) ;
F_5 ( L_8 , V_33 ) ;
}
static void F_16 ( struct V_1 * V_2 , struct V_8 * V_9 )
{
unsigned int V_30 = V_9 -> V_30 ;
T_3 V_36 , V_37 ;
if ( ( V_30 >= V_44 ) &&
( V_30 <= V_31 ) ) {
unsigned int V_45 = V_30 & 0x07 ;
if ( V_30 == V_46 ) {
V_37 = F_4 ( F_2 ( V_2 , V_9 , V_42 ) ) ;
F_15 ( V_37 & ~ ( 1 << 7 ) , F_2 ( V_2 , V_9 , V_42 ) ) ;
}
F_5 ( L_9 ) ;
V_37 = F_4 ( F_2 ( V_2 , V_9 , V_42 ) ) ;
V_37 &= 0xff000000 ;
V_37 |= V_47 [ V_45 ] . V_40 |
( V_47 [ V_45 ] . V_41 << 8 ) |
( V_47 [ V_45 ] . V_43 << 16 ) ;
F_15 ( V_37 , F_2 ( V_2 , V_9 , V_42 ) ) ;
F_5 ( L_10 ) ;
F_5 ( L_11 , V_45 ) ;
} else if ( ( V_30 >= V_48 ) &&
( V_30 <= V_49 ) ) {
unsigned int V_50 = V_30 & 0x07 ;
F_5 ( L_12 ) ;
V_36 = F_4 ( F_2 ( V_2 , V_9 , V_38 ) ) ;
V_36 &= 0x0000ffff ;
V_36 |= ( V_51 [ V_50 ] . V_40 << 16 ) |
( V_51 [ V_50 ] . V_41 << 24 ) ;
F_15 ( V_36 , F_2 ( V_2 , V_9 , V_38 ) ) ;
F_5 ( L_13 ) ;
F_5 ( L_14 , V_50 ) ;
} else {
F_6 (KERN_ERR DRV_NAME L_15 , dma_mode) ;
}
}
static int F_17 ( struct V_18 * V_19 , struct V_8 * * V_52 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_8 * V_53 ;
int V_54 ;
V_54 = F_18 ( V_19 , V_52 ) ;
if ( V_54 < 0 )
return V_54 ;
F_19 (dev, link, ENABLED) {
F_14 ( V_2 , V_53 ) ;
if ( V_53 -> V_55 == V_56 ) {
T_3 V_37 = F_4 ( F_2 ( V_2 , V_53 , V_42 ) ) ;
V_37 |= ( 1 << 25 ) ;
F_15 ( V_37 , F_2 ( V_2 , V_53 , V_42 ) ) ;
F_5 ( L_16 ) ;
} else {
F_16 ( V_2 , V_53 ) ;
}
}
return 0 ;
}
static int F_20 ( struct V_57 * V_58 )
{
struct V_59 * V_60 = V_58 -> V_61 ;
T_2 * V_61 = V_60 -> V_62 ;
int V_54 = 1 ;
switch ( V_61 [ 0 ] ) {
case V_63 :
case V_64 :
case V_65 :
case V_66 :
case V_67 :
case V_68 :
case 0xad :
case 0xbe :
V_54 = 0 ;
break;
default:
;
}
return V_54 ;
}
static long F_21 ( struct V_69 * V_4 )
{
void T_1 * V_70 = V_4 -> V_5 [ V_6 ] ;
long V_71 ;
int V_72 = 1 ;
T_3 V_73 , V_74 , V_75 , V_76 ;
V_72:
V_73 = F_4 ( V_70 + V_77 ) & 0x7fff ;
V_74 = F_4 ( V_70 + V_77 + 0x100 ) & 0x7fff ;
V_75 = F_4 ( V_70 + V_77 ) & 0x7fff ;
V_76 = F_4 ( V_70 + V_77 + 0x100 ) & 0x7fff ;
V_71 = ( V_74 << 15 ) | V_73 ;
F_5 ( L_17 , V_74 , V_73 ) ;
F_5 ( L_18 , V_76 , V_75 ) ;
if ( V_72 && ! ( V_74 == V_76 && V_73 >= V_75 ) ) {
V_72 -- ;
F_5 ( L_19 ) ;
goto V_72;
}
return V_71 ;
}
static void F_22 ( struct V_69 * V_4 , long V_78 , unsigned int V_79 )
{
void T_1 * V_70 = V_4 -> V_5 [ V_6 ] ;
T_4 V_80 ;
long V_81 = V_78 / 1000 ;
long V_82 = V_79 ? V_83 : V_84 ;
long V_85 = V_82 / V_81 ;
int V_86 , V_87 ;
if ( F_23 ( V_81 < 5000L || V_81 > 70000L ) ) {
F_6 (KERN_ERR DRV_NAME L_20 , pll_clock_khz) ;
return;
}
#ifdef F_24
F_5 ( L_21 , V_82 ) ;
V_80 = F_25 ( V_70 + V_88 ) ;
F_5 ( L_22 , V_80 ) ;
#endif
if ( V_85 < 8600L ) {
V_87 = 0x0d ;
} else if ( V_85 < 12900L ) {
V_87 = 0x08 ;
} else if ( V_85 < 16100L ) {
V_87 = 0x06 ;
} else if ( V_85 < 64000L ) {
V_87 = 0x00 ;
} else {
F_6 (KERN_ERR DRV_NAME L_23 , ratio) ;
return;
}
V_86 = ( V_85 * ( V_87 + 2 ) ) / 1000 - 2 ;
if ( F_23 ( V_86 < 0 || V_86 > 127 ) ) {
F_6 (KERN_ERR DRV_NAME L_24 , F) ;
return;
}
F_5 ( L_25 , V_86 , V_87 , V_85 ) ;
V_80 = ( V_87 << 8 ) | V_86 ;
F_5 ( L_26 , V_80 ) ;
F_26 ( V_80 , V_70 + V_88 ) ;
F_25 ( V_70 + V_88 ) ;
F_27 ( 30 ) ;
#ifdef F_24
V_80 = F_25 ( V_70 + V_88 ) ;
F_5 ( L_22 , V_80 ) ;
#endif
return;
}
static long F_28 ( struct V_69 * V_4 )
{
void T_1 * V_70 = V_4 -> V_5 [ V_6 ] ;
T_3 V_89 ;
long V_90 , V_91 ;
struct V_92 V_93 , V_94 ;
long V_78 , V_95 ;
V_89 = F_4 ( V_70 + V_96 ) ;
F_5 ( L_27 , V_89 ) ;
F_15 ( V_89 | ( 0x01 << 14 ) , V_70 + V_96 ) ;
F_4 ( V_70 + V_96 ) ;
V_90 = F_21 ( V_4 ) ;
F_29 ( & V_93 ) ;
F_27 ( 100 ) ;
V_91 = F_21 ( V_4 ) ;
F_29 ( & V_94 ) ;
V_89 = F_4 ( V_70 + V_96 ) ;
F_5 ( L_27 , V_89 ) ;
F_15 ( V_89 & ~ ( 0x01 << 14 ) , V_70 + V_96 ) ;
F_4 ( V_70 + V_96 ) ;
V_95 = ( V_94 . V_97 - V_93 . V_97 ) * 1000000 +
( V_94 . V_98 - V_93 . V_98 ) ;
V_78 = ( ( V_90 - V_91 ) & 0x3fffffff ) / 100 *
( 100000000 / V_95 ) ;
F_5 ( L_28 , V_90 , V_91 ) ;
F_5 ( L_29 , V_78 ) ;
return V_78 ;
}
static int F_30 ( struct V_69 * V_4 , unsigned int V_79 )
{
long V_78 ;
V_78 = F_28 ( V_4 ) ;
F_31 ( V_4 -> V_53 , L_30 , V_78 / 1000 ) ;
F_22 ( V_4 , V_78 , V_79 ) ;
return 0 ;
}
static void F_32 ( struct V_99 * V_100 , void T_1 * V_101 )
{
V_100 -> V_102 =
V_100 -> V_103 = V_101 ;
V_100 -> V_104 =
V_100 -> V_105 = V_101 + 0x05 ;
V_100 -> V_106 = V_101 + 0x0a ;
V_100 -> V_107 = V_101 + 0x0f ;
V_100 -> V_108 = V_101 + 0x10 ;
V_100 -> V_109 = V_101 + 0x15 ;
V_100 -> V_110 = V_101 + 0x1a ;
V_100 -> V_111 =
V_100 -> V_112 = V_101 + 0x1f ;
V_100 -> V_113 =
V_100 -> V_114 = V_101 + 0x81a ;
}
static int T_5 F_33 ( struct V_115 * V_116 , const struct V_117 * V_118 )
{
static const unsigned long V_119 [] = { 0x17c0 , 0x15c0 } ;
static const unsigned long V_120 [] = { 0x1000 , 0x1008 } ;
unsigned int V_79 = ( unsigned int ) V_118 -> V_121 ;
const struct V_122 * V_123 [] =
{ & V_124 [ V_79 ] , NULL } ;
struct V_69 * V_4 ;
void T_1 * V_70 ;
int V_125 , V_54 ;
F_34 ( & V_116 -> V_53 , V_126 ) ;
V_4 = F_35 ( & V_116 -> V_53 , V_123 , 2 ) ;
if ( ! V_4 )
return - V_127 ;
V_54 = F_36 ( V_116 ) ;
if ( V_54 )
return V_54 ;
V_54 = F_37 ( V_116 , 1 << V_6 , V_128 ) ;
if ( V_54 )
return V_54 ;
V_4 -> V_5 = F_38 ( V_116 ) ;
V_54 = F_39 ( V_116 , V_129 ) ;
if ( V_54 )
return V_54 ;
V_54 = F_40 ( V_116 , V_129 ) ;
if ( V_54 )
return V_54 ;
V_70 = V_4 -> V_5 [ V_6 ] ;
for ( V_125 = 0 ; V_125 < 2 ; V_125 ++ ) {
struct V_1 * V_2 = V_4 -> V_130 [ V_125 ] ;
F_32 ( & V_2 -> V_131 , V_70 + V_119 [ V_125 ] ) ;
V_2 -> V_131 . V_132 = V_70 + V_120 [ V_125 ] ;
F_41 ( V_2 , V_6 , - 1 , L_31 ) ;
F_41 ( V_2 , V_6 , V_119 [ V_125 ] , L_32 ) ;
}
if ( F_30 ( V_4 , V_79 ) != 0 )
return - V_133 ;
F_42 ( V_116 ) ;
return F_43 ( V_4 , V_116 -> V_134 , V_135 ,
V_136 , & V_137 ) ;
}
static int F_44 ( struct V_115 * V_116 )
{
struct V_69 * V_4 = F_45 ( & V_116 -> V_53 ) ;
unsigned int V_79 ;
int V_54 ;
V_54 = F_46 ( V_116 ) ;
if ( V_54 )
return V_54 ;
if ( V_116 -> V_138 == V_139 ||
V_116 -> V_138 == V_140 )
V_79 = V_141 ;
else
V_79 = V_142 ;
if ( F_30 ( V_4 , V_79 ) )
return - V_133 ;
F_47 ( V_4 ) ;
return 0 ;
}
