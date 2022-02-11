static int F_1 ( struct V_1 * V_2 )
{
return ( V_3 . V_4 - 64 ) + V_2 -> line ;
}
static int F_2 ( struct V_5 * V_6 )
{
return F_3 ( V_6 , V_7 ) | F_3 ( V_6 , V_8 ) << 8 ;
}
static void F_4 ( struct V_5 * V_6 , int V_9 )
{
F_5 ( V_6 , V_7 , V_9 & 0xff ) ;
F_5 ( V_6 , V_8 , V_9 >> 8 & 0xff ) ;
}
static unsigned int F_6 ( struct V_1 * V_10 , int V_11 )
{
V_11 = V_12 [ V_11 ] << V_10 -> V_13 ;
return F_7 ( V_10 -> V_14 + V_11 ) ;
}
static void F_8 ( struct V_1 * V_10 , int V_11 , int V_9 )
{
V_11 = V_15 [ V_11 ] << V_10 -> V_13 ;
F_9 ( V_9 , V_10 -> V_14 + V_11 ) ;
}
static int F_10 ( struct V_5 * V_6 )
{
return F_7 ( V_6 -> V_2 . V_14 + 0x28 ) ;
}
static void F_11 ( struct V_5 * V_6 , int V_9 )
{
F_9 ( V_9 , V_6 -> V_2 . V_14 + 0x28 ) ;
}
static unsigned int F_12 ( struct V_1 * V_10 , int V_11 )
{
V_11 = V_11 << V_10 -> V_13 ;
F_13 ( V_10 -> V_16 - 1 + V_11 , V_10 -> V_17 ) ;
return F_14 ( V_10 -> V_17 + 1 ) ;
}
static void F_15 ( struct V_1 * V_10 , int V_11 , int V_9 )
{
V_11 = V_11 << V_10 -> V_13 ;
F_13 ( V_10 -> V_16 - 1 + V_11 , V_10 -> V_17 ) ;
F_13 ( V_9 , V_10 -> V_17 + 1 ) ;
}
static unsigned int F_16 ( struct V_1 * V_10 , int V_11 )
{
V_11 = V_11 << V_10 -> V_13 ;
return F_17 ( V_10 -> V_14 + V_11 ) ;
}
static void F_18 ( struct V_1 * V_10 , int V_11 , int V_9 )
{
V_11 = V_11 << V_10 -> V_13 ;
F_19 ( V_9 , V_10 -> V_14 + V_11 ) ;
}
static void F_20 ( struct V_1 * V_10 , int V_11 , int V_9 )
{
V_11 = V_11 << V_10 -> V_13 ;
F_21 ( V_9 , V_10 -> V_14 + V_11 ) ;
}
static unsigned int F_22 ( struct V_1 * V_10 , int V_11 )
{
V_11 = V_11 << V_10 -> V_13 ;
return F_23 ( V_10 -> V_14 + V_11 ) ;
}
static unsigned int F_24 ( struct V_1 * V_10 , int V_11 )
{
V_11 = V_11 << V_10 -> V_13 ;
return F_14 ( V_10 -> V_17 + V_11 ) ;
}
static void F_25 ( struct V_1 * V_10 , int V_11 , int V_9 )
{
V_11 = V_11 << V_10 -> V_13 ;
F_13 ( V_9 , V_10 -> V_17 + V_11 ) ;
}
static void F_26 ( struct V_1 * V_10 )
{
struct V_5 * V_6 = F_27 ( V_10 ) ;
V_6 -> V_18 = F_2 ;
V_6 -> V_19 = F_4 ;
switch ( V_10 -> V_20 ) {
case V_21 :
V_10 -> F_3 = F_12 ;
V_10 -> F_5 = F_15 ;
break;
case V_22 :
V_10 -> F_3 = F_16 ;
V_10 -> F_5 = F_18 ;
break;
case V_23 :
V_10 -> F_3 = F_22 ;
V_10 -> F_5 = F_20 ;
break;
#if F_28 ( V_24 ) || F_28 ( V_25 )
case V_26 :
V_10 -> F_3 = F_6 ;
V_10 -> F_5 = F_8 ;
V_6 -> V_18 = F_10 ;
V_6 -> V_19 = F_11 ;
break;
#endif
default:
V_10 -> F_3 = F_24 ;
V_10 -> F_5 = F_25 ;
break;
}
V_6 -> V_27 = V_10 -> V_20 ;
V_10 -> V_28 = V_29 ;
}
static void
F_29 ( struct V_1 * V_10 , int V_11 , int V_9 )
{
switch ( V_10 -> V_20 ) {
case V_22 :
case V_23 :
case V_26 :
V_10 -> F_5 ( V_10 , V_11 , V_9 ) ;
V_10 -> F_3 ( V_10 , V_30 ) ;
break;
default:
V_10 -> F_5 ( V_10 , V_11 , V_9 ) ;
}
}
static void F_30 ( struct V_5 * V_6 , int V_11 , int V_9 )
{
F_5 ( V_6 , V_31 , V_11 ) ;
F_5 ( V_6 , V_32 , V_9 ) ;
}
static unsigned int F_31 ( struct V_5 * V_6 , int V_11 )
{
unsigned int V_9 ;
F_30 ( V_6 , V_33 , V_6 -> V_34 | V_35 ) ;
F_5 ( V_6 , V_31 , V_11 ) ;
V_9 = F_3 ( V_6 , V_32 ) ;
F_30 ( V_6 , V_33 , V_6 -> V_34 ) ;
return V_9 ;
}
static void F_32 ( struct V_5 * V_10 )
{
if ( V_10 -> V_36 & V_37 ) {
F_5 ( V_10 , V_38 , V_39 ) ;
F_5 ( V_10 , V_38 , V_39 |
V_40 | V_41 ) ;
F_5 ( V_10 , V_38 , 0 ) ;
}
}
void F_33 ( struct V_5 * V_10 )
{
F_32 ( V_10 ) ;
F_5 ( V_10 , V_38 , V_10 -> V_42 ) ;
}
static void F_34 ( struct V_5 * V_10 )
{
if ( ! ( V_10 -> V_36 & V_43 ) )
return;
F_35 ( V_10 -> V_2 . V_44 ) ;
}
static void F_36 ( struct V_5 * V_10 )
{
if ( ! ( V_10 -> V_36 & V_43 ) )
return;
F_37 ( V_10 -> V_2 . V_44 ) ;
F_38 ( V_10 -> V_2 . V_44 ) ;
}
static void F_39 ( struct V_5 * V_10 )
{
unsigned char V_45 ;
if ( ! ( V_10 -> V_36 & V_43 ) )
return;
V_45 = F_40 ( & V_10 -> V_46 , 1 ) ;
if ( V_45 )
return;
F_35 ( V_10 -> V_2 . V_44 ) ;
}
static void F_41 ( struct V_5 * V_10 )
{
unsigned char V_45 ;
if ( ! ( V_10 -> V_36 & V_43 ) )
return;
V_45 = F_40 ( & V_10 -> V_46 , 0 ) ;
if ( ! V_45 )
return;
F_37 ( V_10 -> V_2 . V_44 ) ;
F_38 ( V_10 -> V_2 . V_44 ) ;
}
static void F_42 ( struct V_5 * V_10 , int V_47 )
{
F_34 ( V_10 ) ;
if ( ( V_10 -> V_2 . type == V_48 ) ||
( V_10 -> V_2 . type == V_49 ) ) {
F_5 ( V_10 , V_50 , V_47 ? 0xff : 0 ) ;
goto V_51;
}
if ( V_10 -> V_36 & V_52 ) {
if ( V_10 -> V_36 & V_53 ) {
F_5 ( V_10 , V_30 , V_54 ) ;
F_5 ( V_10 , V_55 , V_56 ) ;
F_5 ( V_10 , V_30 , 0 ) ;
}
F_5 ( V_10 , V_57 , V_47 ? V_58 : 0 ) ;
if ( V_10 -> V_36 & V_53 ) {
F_5 ( V_10 , V_30 , V_54 ) ;
F_5 ( V_10 , V_55 , 0 ) ;
F_5 ( V_10 , V_30 , 0 ) ;
}
}
V_51:
F_36 ( V_10 ) ;
}
static int F_43 ( struct V_5 * V_6 )
{
unsigned char V_59 ;
int V_60 ;
V_59 = F_3 ( V_6 , V_61 ) ;
V_60 = V_59 & V_62 ;
if ( ! V_60 ) {
F_5 ( V_6 , V_61 , V_59 | V_62 ) ;
V_59 = F_3 ( V_6 , V_61 ) ;
V_60 = V_59 & V_62 ;
}
if ( V_60 )
V_6 -> V_2 . V_63 = V_64 * 16 ;
return V_60 ;
}
static void F_44 ( struct V_5 * V_6 )
{
if ( V_6 -> V_2 . type == V_65 ) {
if ( V_6 -> V_2 . V_63 != V_64 * 16 ) {
F_45 ( & V_6 -> V_2 . V_66 ) ;
F_43 ( V_6 ) ;
F_46 ( & V_6 -> V_2 . V_66 ) ;
}
if ( V_6 -> V_2 . V_63 == V_64 * 16 )
F_5 ( V_6 , V_67 , 0 ) ;
}
}
static void F_47 ( struct V_5 * V_6 )
{
unsigned char V_59 ;
int V_60 ;
if ( V_6 -> V_2 . type == V_65 &&
V_6 -> V_2 . V_63 == V_64 * 16 ) {
F_45 ( & V_6 -> V_2 . V_66 ) ;
V_59 = F_3 ( V_6 , V_61 ) ;
V_60 = ! ( V_59 & V_62 ) ;
if ( ! V_60 ) {
F_5 ( V_6 , V_61 , V_59 & ~ V_62 ) ;
V_59 = F_3 ( V_6 , V_61 ) ;
V_60 = ! ( V_59 & V_62 ) ;
}
if ( V_60 )
V_6 -> V_2 . V_63 = V_68 * 16 ;
F_46 ( & V_6 -> V_2 . V_66 ) ;
}
}
static int F_48 ( struct V_5 * V_6 )
{
unsigned char V_69 , V_70 , V_71 ;
unsigned short V_72 ;
int V_73 ;
V_71 = F_3 ( V_6 , V_30 ) ;
F_5 ( V_6 , V_30 , 0 ) ;
V_69 = F_3 ( V_6 , V_38 ) ;
V_70 = F_3 ( V_6 , V_74 ) ;
F_5 ( V_6 , V_38 , V_39 |
V_40 | V_41 ) ;
F_5 ( V_6 , V_74 , V_75 ) ;
F_5 ( V_6 , V_30 , V_76 ) ;
V_72 = F_49 ( V_6 ) ;
F_50 ( V_6 , 0x0001 ) ;
F_5 ( V_6 , V_30 , 0x03 ) ;
for ( V_73 = 0 ; V_73 < 256 ; V_73 ++ )
F_5 ( V_6 , V_77 , V_73 ) ;
F_51 ( 20 ) ;
for ( V_73 = 0 ; ( F_3 ( V_6 , V_78 ) & V_79 ) &&
( V_73 < 256 ) ; V_73 ++ )
F_3 ( V_6 , V_80 ) ;
F_5 ( V_6 , V_38 , V_69 ) ;
F_5 ( V_6 , V_74 , V_70 ) ;
F_5 ( V_6 , V_30 , V_76 ) ;
F_50 ( V_6 , V_72 ) ;
F_5 ( V_6 , V_30 , V_71 ) ;
return V_73 ;
}
static unsigned int F_52 ( struct V_5 * V_10 )
{
unsigned char V_81 , V_82 , V_71 ;
unsigned int V_83 ;
V_71 = F_3 ( V_10 , V_30 ) ;
F_5 ( V_10 , V_30 , V_76 ) ;
V_81 = F_3 ( V_10 , V_7 ) ;
V_82 = F_3 ( V_10 , V_8 ) ;
F_5 ( V_10 , V_7 , 0 ) ;
F_5 ( V_10 , V_8 , 0 ) ;
V_83 = F_3 ( V_10 , V_7 ) | F_3 ( V_10 , V_8 ) << 8 ;
F_5 ( V_10 , V_7 , V_81 ) ;
F_5 ( V_10 , V_8 , V_82 ) ;
F_5 ( V_10 , V_30 , V_71 ) ;
return V_83 ;
}
static void F_53 ( struct V_5 * V_6 )
{
unsigned int V_84 , V_85 , V_86 , V_87 ;
V_6 -> V_36 |= V_53 | V_52 ;
V_6 -> V_34 = 0 ;
F_5 ( V_6 , V_30 , V_54 ) ;
F_5 ( V_6 , V_55 , V_56 ) ;
F_5 ( V_6 , V_30 , 0x00 ) ;
V_84 = F_31 ( V_6 , V_88 ) ;
V_85 = F_31 ( V_6 , V_89 ) ;
V_86 = F_31 ( V_6 , V_90 ) ;
V_87 = F_31 ( V_6 , V_91 ) ;
F_54 ( L_1 , V_84 , V_85 , V_86 , V_87 ) ;
if ( V_84 == 0x16 && V_85 == 0xC9 &&
( V_86 == 0x50 || V_86 == 0x52 || V_86 == 0x54 ) ) {
V_6 -> V_2 . type = V_92 ;
if ( V_86 == 0x52 && V_87 == 0x01 )
V_6 -> V_93 |= V_94 ;
return;
}
V_84 = F_52 ( V_6 ) ;
F_54 ( L_2 , V_84 ) ;
V_85 = V_84 >> 8 ;
if ( V_85 == 0x10 || V_85 == 0x12 || V_85 == 0x14 ) {
V_6 -> V_2 . type = V_95 ;
return;
}
if ( F_48 ( V_6 ) == 64 )
V_6 -> V_2 . type = V_96 ;
else
V_6 -> V_2 . type = V_97 ;
}
static void F_55 ( struct V_5 * V_6 )
{
unsigned char V_98 , V_99 , V_100 ;
V_6 -> V_2 . type = V_101 ;
V_98 = F_3 ( V_6 , V_31 ) ;
F_5 ( V_6 , V_31 , 0xa5 ) ;
V_99 = F_3 ( V_6 , V_31 ) ;
F_5 ( V_6 , V_31 , 0x5a ) ;
V_100 = F_3 ( V_6 , V_31 ) ;
F_5 ( V_6 , V_31 , V_98 ) ;
if ( V_99 == 0xa5 && V_100 == 0x5a )
V_6 -> V_2 . type = V_102 ;
}
static int F_56 ( struct V_5 * V_6 )
{
if ( F_52 ( V_6 ) == 0x0201 && F_48 ( V_6 ) == 16 )
return 1 ;
return 0 ;
}
static inline int F_57 ( struct V_5 * V_6 )
{
unsigned char V_103 ;
V_103 = F_3 ( V_6 , 0x04 ) ;
#define F_58 ( T_1 ) ((x) & 0x30)
if ( F_58 ( V_103 ) == 0x10 ) {
return 0 ;
} else {
V_103 &= ~ 0xB0 ;
V_103 |= 0x10 ;
F_5 ( V_6 , 0x04 , V_103 ) ;
}
return 1 ;
}
static void F_59 ( struct V_5 * V_6 )
{
unsigned char V_99 , V_100 ;
unsigned int V_104 ;
V_6 -> V_2 . type = V_105 ;
V_6 -> V_36 |= V_37 ;
if ( V_6 -> V_2 . V_106 & V_107 ) {
V_99 = F_3 ( V_6 , V_108 ) ;
if ( V_99 == 0x82 || V_99 == 0x84 || V_99 == 0x88 ) {
F_54 ( L_3 ) ;
V_6 -> V_2 . type = V_48 ;
V_6 -> V_36 |= V_109 | V_53 |
V_52 ;
return;
}
}
F_5 ( V_6 , V_30 , V_76 ) ;
if ( F_3 ( V_6 , V_55 ) == 0 ) {
F_5 ( V_6 , V_55 , 0xA8 ) ;
if ( F_3 ( V_6 , V_55 ) != 0 ) {
F_54 ( L_4 ) ;
V_6 -> V_2 . type = V_110 ;
V_6 -> V_36 |= V_53 | V_52 ;
} else {
F_54 ( L_5 ) ;
}
F_5 ( V_6 , V_55 , 0 ) ;
return;
}
F_5 ( V_6 , V_30 , V_54 ) ;
if ( F_3 ( V_6 , V_55 ) == 0 && ! F_56 ( V_6 ) ) {
F_54 ( L_6 ) ;
F_53 ( V_6 ) ;
return;
}
F_5 ( V_6 , V_30 , 0 ) ;
V_99 = F_3 ( V_6 , V_74 ) ;
F_5 ( V_6 , V_30 , 0xE0 ) ;
V_100 = F_3 ( V_6 , 0x02 ) ;
if ( ! ( ( V_100 ^ V_99 ) & V_75 ) ) {
F_5 ( V_6 , V_30 , 0 ) ;
F_5 ( V_6 , V_74 , V_99 ^ V_75 ) ;
F_5 ( V_6 , V_30 , 0xE0 ) ;
V_100 = F_3 ( V_6 , 0x02 ) ;
F_5 ( V_6 , V_30 , 0 ) ;
F_5 ( V_6 , V_74 , V_99 ) ;
if ( ( V_100 ^ V_99 ) & V_75 ) {
unsigned short V_111 ;
F_5 ( V_6 , V_30 , 0xE0 ) ;
V_111 = F_49 ( V_6 ) ;
V_111 <<= 3 ;
if ( F_57 ( V_6 ) )
F_50 ( V_6 , V_111 ) ;
F_5 ( V_6 , V_30 , 0 ) ;
V_6 -> V_2 . V_63 = 921600 * 16 ;
V_6 -> V_2 . type = V_112 ;
V_6 -> V_36 |= V_113 ;
return;
}
}
F_5 ( V_6 , V_30 , 0 ) ;
F_5 ( V_6 , V_38 , V_39 | V_114 ) ;
V_99 = F_3 ( V_6 , V_115 ) >> 5 ;
F_5 ( V_6 , V_38 , V_39 ) ;
F_5 ( V_6 , V_30 , V_76 ) ;
F_5 ( V_6 , V_38 , V_39 | V_114 ) ;
V_100 = F_3 ( V_6 , V_115 ) >> 5 ;
F_5 ( V_6 , V_38 , V_39 ) ;
F_5 ( V_6 , V_30 , 0 ) ;
F_54 ( L_7 , V_99 , V_100 ) ;
if ( V_99 == 6 && V_100 == 7 ) {
V_6 -> V_2 . type = V_116 ;
V_6 -> V_36 |= V_109 | V_52 ;
return;
}
V_104 = F_3 ( V_6 , V_57 ) ;
F_5 ( V_6 , V_57 , V_104 & ~ V_117 ) ;
if ( ! ( F_3 ( V_6 , V_57 ) & V_117 ) ) {
F_5 ( V_6 , V_57 , V_104 | V_117 ) ;
if ( F_3 ( V_6 , V_57 ) & V_117 ) {
F_54 ( L_8 ) ;
V_6 -> V_2 . type = V_118 ;
V_6 -> V_36 |= V_119 | V_120 ;
return;
}
} else {
F_54 ( L_9 ) ;
}
F_5 ( V_6 , V_57 , V_104 ) ;
if ( V_6 -> V_2 . V_106 & V_107 ) {
F_54 ( L_10 ) ;
V_6 -> V_2 . type = V_49 ;
V_6 -> V_36 |= V_109 | V_53 |
V_52 ;
return;
}
if ( V_6 -> V_2 . type == V_105 && F_48 ( V_6 ) == 64 ) {
V_6 -> V_2 . type = V_121 ;
V_6 -> V_36 |= V_109 ;
}
}
static void F_60 ( struct V_5 * V_6 , unsigned int V_122 )
{
unsigned char V_99 , V_98 , V_123 , V_124 ;
unsigned char V_125 , V_126 ;
struct V_1 * V_2 = & V_6 -> V_2 ;
unsigned long V_106 ;
unsigned int V_127 ;
if ( ! V_2 -> V_17 && ! V_2 -> V_128 && ! V_2 -> V_14 )
return;
F_54 ( L_11 ,
F_1 ( V_2 ) , V_2 -> V_17 , V_2 -> V_14 ) ;
F_61 ( & V_2 -> V_66 , V_106 ) ;
V_6 -> V_36 = 0 ;
V_6 -> V_93 = 0 ;
if ( ! ( V_2 -> V_106 & V_129 ) ) {
V_98 = F_3 ( V_6 , V_57 ) ;
F_5 ( V_6 , V_57 , 0 ) ;
#ifdef F_62
F_13 ( 0xff , 0x080 ) ;
#endif
V_123 = F_3 ( V_6 , V_57 ) & 0x0f ;
F_5 ( V_6 , V_57 , 0x0F ) ;
#ifdef F_62
F_13 ( 0 , 0x080 ) ;
#endif
V_124 = F_3 ( V_6 , V_57 ) & 0x0f ;
F_5 ( V_6 , V_57 , V_98 ) ;
if ( V_123 != 0 || V_124 != 0x0F ) {
F_63 ( & V_2 -> V_66 , V_106 ) ;
F_54 ( L_12 ,
V_123 , V_124 ) ;
goto V_51;
}
}
V_126 = F_3 ( V_6 , V_74 ) ;
V_125 = F_3 ( V_6 , V_30 ) ;
if ( ! ( V_2 -> V_106 & V_130 ) ) {
F_5 ( V_6 , V_74 , V_75 | 0x0A ) ;
V_99 = F_3 ( V_6 , V_131 ) & 0xF0 ;
F_5 ( V_6 , V_74 , V_126 ) ;
if ( V_99 != 0x90 ) {
F_63 ( & V_2 -> V_66 , V_106 ) ;
F_54 ( L_13 ,
V_99 ) ;
goto V_51;
}
}
F_5 ( V_6 , V_30 , V_54 ) ;
F_5 ( V_6 , V_55 , 0 ) ;
F_5 ( V_6 , V_30 , 0 ) ;
F_5 ( V_6 , V_38 , V_39 ) ;
V_98 = F_3 ( V_6 , V_115 ) >> 6 ;
switch ( V_98 ) {
case 0 :
F_55 ( V_6 ) ;
break;
case 1 :
V_2 -> type = V_132 ;
break;
case 2 :
V_2 -> type = V_133 ;
break;
case 3 :
F_59 ( V_6 ) ;
break;
}
#ifdef F_64
if ( V_2 -> type == V_105 && V_122 & V_134 ) {
int V_135 ;
for ( V_135 = 0 ; V_135 < V_136 ; ++ V_135 ) {
if ( V_137 [ V_135 ] == V_2 -> V_17 && F_43 ( V_6 ) ) {
V_2 -> type = V_65 ;
break;
}
}
}
#endif
F_5 ( V_6 , V_30 , V_125 ) ;
V_2 -> V_138 = V_139 [ V_6 -> V_2 . type ] . V_140 ;
V_127 = V_6 -> V_36 ;
V_6 -> V_36 = V_139 [ V_2 -> type ] . V_106 ;
V_6 -> V_141 = V_139 [ V_2 -> type ] . V_141 ;
if ( V_2 -> type == V_132 )
goto V_142;
#ifdef F_64
if ( V_2 -> type == V_65 )
F_5 ( V_6 , V_67 , 0 ) ;
#endif
F_5 ( V_6 , V_74 , V_126 ) ;
F_32 ( V_6 ) ;
F_3 ( V_6 , V_80 ) ;
if ( V_6 -> V_36 & V_119 )
F_5 ( V_6 , V_57 , V_117 ) ;
else
F_5 ( V_6 , V_57 , 0 ) ;
V_142:
F_63 ( & V_2 -> V_66 , V_106 ) ;
if ( V_6 -> V_36 != V_127 ) {
F_65 ( V_143
L_14 ,
F_1 ( V_2 ) , V_127 ,
V_6 -> V_36 ) ;
}
V_51:
F_54 ( L_15 , V_98 ) ;
F_54 ( L_16 , V_139 [ V_2 -> type ] . V_144 ) ;
}
static void F_66 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = & V_6 -> V_2 ;
unsigned char V_126 , V_145 ;
unsigned char V_146 = 0 ;
unsigned int V_147 = 0 ;
unsigned long V_148 ;
int V_149 ;
if ( V_2 -> V_106 & V_150 ) {
V_147 = ( V_2 -> V_17 & 0xfe0 ) | 0x1f ;
V_146 = F_67 ( V_147 ) ;
F_68 ( 0x80 , V_147 ) ;
F_67 ( V_147 ) ;
}
F_69 ( F_70 () ) ;
V_126 = F_3 ( V_6 , V_74 ) ;
V_145 = F_3 ( V_6 , V_57 ) ;
F_5 ( V_6 , V_74 , V_151 | V_152 ) ;
V_148 = F_70 () ;
F_5 ( V_6 , V_74 , 0 ) ;
F_71 ( 10 ) ;
if ( V_2 -> V_106 & V_150 ) {
F_5 ( V_6 , V_74 ,
V_153 | V_154 ) ;
} else {
F_5 ( V_6 , V_74 ,
V_153 | V_154 | V_152 ) ;
}
F_5 ( V_6 , V_57 , 0x0f ) ;
F_3 ( V_6 , V_78 ) ;
F_3 ( V_6 , V_80 ) ;
F_3 ( V_6 , V_115 ) ;
F_3 ( V_6 , V_131 ) ;
F_5 ( V_6 , V_77 , 0xFF ) ;
F_71 ( 20 ) ;
V_149 = F_69 ( V_148 ) ;
F_5 ( V_6 , V_74 , V_126 ) ;
F_5 ( V_6 , V_57 , V_145 ) ;
if ( V_2 -> V_106 & V_150 )
F_68 ( V_146 , V_147 ) ;
V_2 -> V_149 = ( V_149 > 0 ) ? V_149 : 0 ;
}
static inline void F_72 ( struct V_5 * V_10 )
{
if ( V_10 -> V_155 & V_156 ) {
V_10 -> V_155 &= ~ V_156 ;
F_5 ( V_10 , V_57 , V_10 -> V_155 ) ;
F_41 ( V_10 ) ;
}
}
static void F_73 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_27 ( V_2 ) ;
F_34 ( V_6 ) ;
F_72 ( V_6 ) ;
if ( V_2 -> type == V_92 ) {
V_6 -> V_34 |= V_157 ;
F_30 ( V_6 , V_33 , V_6 -> V_34 ) ;
}
F_36 ( V_6 ) ;
}
static void F_74 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_27 ( V_2 ) ;
F_39 ( V_6 ) ;
if ( V_6 -> V_158 && ! F_75 ( V_6 ) ) {
return;
} else if ( ! ( V_6 -> V_155 & V_156 ) ) {
V_6 -> V_155 |= V_156 ;
F_76 ( V_2 , V_57 , V_6 -> V_155 ) ;
if ( V_6 -> V_93 & V_159 ) {
unsigned char V_160 ;
V_160 = F_3 ( V_6 , V_78 ) ;
V_6 -> V_161 |= V_160 & V_162 ;
if ( V_160 & V_163 )
F_77 ( V_6 ) ;
}
}
if ( V_2 -> type == V_92 && V_6 -> V_34 & V_157 ) {
V_6 -> V_34 &= ~ V_157 ;
F_30 ( V_6 , V_33 , V_6 -> V_34 ) ;
}
}
static void F_78 ( struct V_1 * V_2 )
{
V_2 -> V_164 ( V_2 ) ;
}
static void F_79 ( struct V_1 * V_2 )
{
V_2 -> V_165 ( V_2 ) ;
}
static void F_80 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_27 ( V_2 ) ;
F_34 ( V_6 ) ;
V_6 -> V_155 &= ~ ( V_166 | V_167 ) ;
V_6 -> V_2 . V_168 &= ~ V_79 ;
F_76 ( V_2 , V_57 , V_6 -> V_155 ) ;
F_36 ( V_6 ) ;
}
static void F_81 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_27 ( V_2 ) ;
if ( V_6 -> V_93 & V_169 )
return;
V_6 -> V_155 |= V_170 ;
F_34 ( V_6 ) ;
F_76 ( V_2 , V_57 , V_6 -> V_155 ) ;
F_36 ( V_6 ) ;
}
unsigned char
F_82 ( struct V_5 * V_6 , unsigned char V_160 )
{
struct V_1 * V_2 = & V_6 -> V_2 ;
unsigned char V_171 ;
int V_172 = 256 ;
char V_173 ;
do {
if ( F_83 ( V_160 & V_79 ) )
V_171 = F_3 ( V_6 , V_80 ) ;
else
V_171 = 0 ;
V_173 = V_174 ;
V_2 -> V_175 . V_176 ++ ;
V_160 |= V_6 -> V_161 ;
V_6 -> V_161 = 0 ;
if ( F_84 ( V_160 & V_177 ) ) {
if ( V_160 & V_178 ) {
V_160 &= ~ ( V_179 | V_180 ) ;
V_2 -> V_175 . V_181 ++ ;
if ( F_85 ( V_2 ) )
goto V_182;
} else if ( V_160 & V_180 )
V_2 -> V_175 . V_183 ++ ;
else if ( V_160 & V_179 )
V_2 -> V_175 . V_184 ++ ;
if ( V_160 & V_185 )
V_2 -> V_175 . V_186 ++ ;
V_160 &= V_2 -> V_168 ;
if ( V_160 & V_178 ) {
F_86 ( L_17 ) ;
V_173 = V_187 ;
} else if ( V_160 & V_180 )
V_173 = V_188 ;
else if ( V_160 & V_179 )
V_173 = V_189 ;
}
if ( F_87 ( V_2 , V_171 ) )
goto V_182;
F_88 ( V_2 , V_160 , V_185 , V_171 , V_173 ) ;
V_182:
V_160 = F_3 ( V_6 , V_78 ) ;
} while ( ( V_160 & ( V_79 | V_178 ) ) && ( V_172 -- > 0 ) );
F_89 ( & V_2 -> V_66 ) ;
F_90 ( & V_2 -> V_190 -> V_2 ) ;
F_91 ( & V_2 -> V_66 ) ;
return V_160 ;
}
void F_77 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = & V_6 -> V_2 ;
struct V_191 * V_192 = & V_2 -> V_190 -> V_192 ;
int V_73 ;
if ( V_2 -> V_193 ) {
F_5 ( V_6 , V_77 , V_2 -> V_193 ) ;
V_2 -> V_175 . V_194 ++ ;
V_2 -> V_193 = 0 ;
return;
}
if ( F_92 ( V_2 ) ) {
F_73 ( V_2 ) ;
return;
}
if ( F_93 ( V_192 ) ) {
F_72 ( V_6 ) ;
return;
}
V_73 = V_6 -> V_141 ;
do {
F_5 ( V_6 , V_77 , V_192 -> V_195 [ V_192 -> V_196 ] ) ;
V_192 -> V_196 = ( V_192 -> V_196 + 1 ) & ( V_197 - 1 ) ;
V_2 -> V_175 . V_194 ++ ;
if ( F_93 ( V_192 ) )
break;
if ( V_6 -> V_36 & V_198 ) {
if ( ( F_94 ( V_2 , V_78 ) & V_199 ) !=
V_199 )
break;
}
} while ( -- V_73 > 0 );
if ( F_95 ( V_192 ) < V_200 )
F_96 ( V_2 ) ;
F_86 ( L_18 ) ;
if ( F_93 ( V_192 ) && ! ( V_6 -> V_36 & V_43 ) )
F_72 ( V_6 ) ;
}
unsigned int F_97 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = & V_6 -> V_2 ;
unsigned int V_103 = F_3 ( V_6 , V_131 ) ;
V_103 |= V_6 -> V_201 ;
V_6 -> V_201 = 0 ;
if ( V_103 & V_202 && V_6 -> V_155 & V_170 &&
V_2 -> V_190 != NULL ) {
if ( V_103 & V_203 )
V_2 -> V_175 . V_204 ++ ;
if ( V_103 & V_205 )
V_2 -> V_175 . V_206 ++ ;
if ( V_103 & V_207 )
F_98 ( V_2 , V_103 & V_208 ) ;
if ( V_103 & V_209 )
F_99 ( V_2 , V_103 & V_210 ) ;
F_100 ( & V_2 -> V_190 -> V_2 . V_211 ) ;
}
return V_103 ;
}
int F_101 ( struct V_1 * V_2 , unsigned int V_212 )
{
unsigned char V_103 ;
unsigned long V_106 ;
struct V_5 * V_6 = F_27 ( V_2 ) ;
int V_213 = 0 ;
if ( V_212 & V_214 )
return 0 ;
F_61 ( & V_2 -> V_66 , V_106 ) ;
V_103 = F_94 ( V_2 , V_78 ) ;
F_86 ( L_19 , V_103 ) ;
if ( V_103 & ( V_79 | V_178 ) ) {
if ( V_6 -> V_158 )
V_213 = F_102 ( V_6 , V_212 ) ;
if ( ! V_6 -> V_158 || V_213 )
V_103 = F_82 ( V_6 , V_103 ) ;
}
F_97 ( V_6 ) ;
if ( ! V_6 -> V_158 && ( V_103 & V_215 ) )
F_77 ( V_6 ) ;
F_63 ( & V_2 -> V_66 , V_106 ) ;
return 1 ;
}
static int V_29 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_27 ( V_2 ) ;
unsigned int V_212 ;
int V_216 ;
F_34 ( V_6 ) ;
V_212 = F_94 ( V_2 , V_115 ) ;
V_216 = F_101 ( V_2 , V_212 ) ;
F_36 ( V_6 ) ;
return V_216 ;
}
static int F_103 ( struct V_1 * V_2 )
{
unsigned char V_217 , V_218 , V_219 , V_220 ;
unsigned int V_212 = F_94 ( V_2 , V_115 ) ;
int V_216 ;
V_216 = F_101 ( V_2 , V_212 ) ;
if ( ( V_2 -> type == V_48 ) ||
( V_2 -> type == V_49 ) ) {
V_217 = F_94 ( V_2 , 0x80 ) ;
V_218 = F_94 ( V_2 , 0x81 ) ;
V_219 = F_94 ( V_2 , 0x82 ) ;
V_220 = F_94 ( V_2 , 0x83 ) ;
}
return V_216 ;
}
static T_2 F_104 ( int V_149 , void * V_221 )
{
struct V_222 * V_135 = V_221 ;
struct V_223 * V_224 , * V_225 = NULL ;
int V_226 = 0 , V_227 = 0 ;
F_86 ( L_20 , V_149 ) ;
F_91 ( & V_135 -> V_66 ) ;
V_224 = V_135 -> V_228 ;
do {
struct V_5 * V_6 ;
struct V_1 * V_2 ;
V_6 = F_105 ( V_224 , struct V_5 , V_229 ) ;
V_2 = & V_6 -> V_2 ;
if ( V_2 -> V_28 ( V_2 ) ) {
V_227 = 1 ;
V_225 = NULL ;
} else if ( V_225 == NULL )
V_225 = V_224 ;
V_224 = V_224 -> V_230 ;
if ( V_224 == V_135 -> V_228 && V_226 ++ > V_231 ) {
F_106 ( V_232
L_21 , V_149 ) ;
break;
}
} while ( V_224 != V_225 );
F_89 ( & V_135 -> V_66 ) ;
F_86 ( L_22 ) ;
return F_107 ( V_227 ) ;
}
static void F_108 ( struct V_222 * V_135 , struct V_5 * V_6 )
{
F_45 ( & V_135 -> V_66 ) ;
if ( ! F_109 ( V_135 -> V_228 ) ) {
if ( V_135 -> V_228 == & V_6 -> V_229 )
V_135 -> V_228 = V_135 -> V_228 -> V_230 ;
F_110 ( & V_6 -> V_229 ) ;
} else {
F_111 ( V_135 -> V_228 != & V_6 -> V_229 ) ;
V_135 -> V_228 = NULL ;
}
F_46 ( & V_135 -> V_66 ) ;
if ( V_135 -> V_228 == NULL ) {
F_112 ( & V_135 -> V_233 ) ;
F_113 ( V_135 ) ;
}
}
static int F_114 ( struct V_5 * V_6 )
{
struct V_234 * V_235 ;
struct V_236 * V_237 ;
struct V_222 * V_135 ;
int V_216 , V_238 = V_6 -> V_2 . V_106 & V_239 ? V_240 : 0 ;
F_115 ( & V_241 ) ;
V_235 = & V_242 [ V_6 -> V_2 . V_149 % V_243 ] ;
F_116 (n, h) {
V_135 = F_117 ( V_237 , struct V_222 , V_233 ) ;
if ( V_135 -> V_149 == V_6 -> V_2 . V_149 )
break;
}
if ( V_237 == NULL ) {
V_135 = F_118 ( sizeof( struct V_222 ) , V_244 ) ;
if ( V_135 == NULL ) {
F_119 ( & V_241 ) ;
return - V_245 ;
}
F_120 ( & V_135 -> V_66 ) ;
V_135 -> V_149 = V_6 -> V_2 . V_149 ;
F_121 ( & V_135 -> V_233 , V_235 ) ;
}
F_119 ( & V_241 ) ;
F_45 ( & V_135 -> V_66 ) ;
if ( V_135 -> V_228 ) {
F_122 ( & V_6 -> V_229 , V_135 -> V_228 ) ;
F_46 ( & V_135 -> V_66 ) ;
V_216 = 0 ;
} else {
F_123 ( & V_6 -> V_229 ) ;
V_135 -> V_228 = & V_6 -> V_229 ;
F_46 ( & V_135 -> V_66 ) ;
V_238 |= V_6 -> V_2 . V_246 ;
V_216 = F_124 ( V_6 -> V_2 . V_149 , F_104 ,
V_238 , L_23 , V_135 ) ;
if ( V_216 < 0 )
F_108 ( V_135 , V_6 ) ;
}
return V_216 ;
}
static void F_125 ( struct V_5 * V_6 )
{
struct V_222 * V_135 ;
struct V_236 * V_237 ;
struct V_234 * V_235 ;
F_115 ( & V_241 ) ;
V_235 = & V_242 [ V_6 -> V_2 . V_149 % V_243 ] ;
F_116 (n, h) {
V_135 = F_117 ( V_237 , struct V_222 , V_233 ) ;
if ( V_135 -> V_149 == V_6 -> V_2 . V_149 )
break;
}
F_111 ( V_237 == NULL ) ;
F_111 ( V_135 -> V_228 == NULL ) ;
if ( F_109 ( V_135 -> V_228 ) )
F_126 ( V_6 -> V_2 . V_149 , V_135 ) ;
F_108 ( V_135 , V_6 ) ;
F_119 ( & V_241 ) ;
}
static void F_127 ( unsigned long V_247 )
{
struct V_5 * V_6 = (struct V_5 * ) V_247 ;
V_6 -> V_2 . V_28 ( & V_6 -> V_2 ) ;
F_128 ( & V_6 -> V_248 , V_249 + F_129 ( & V_6 -> V_2 ) ) ;
}
static void F_130 ( unsigned long V_247 )
{
struct V_5 * V_6 = (struct V_5 * ) V_247 ;
unsigned int V_212 , V_155 = 0 , V_160 ;
unsigned long V_106 ;
F_61 ( & V_6 -> V_2 . V_66 , V_106 ) ;
if ( V_6 -> V_2 . V_149 ) {
V_155 = F_3 ( V_6 , V_57 ) ;
F_5 ( V_6 , V_57 , 0 ) ;
}
V_212 = F_3 ( V_6 , V_115 ) ;
V_160 = F_3 ( V_6 , V_78 ) ;
V_6 -> V_161 |= V_160 & V_162 ;
if ( ( V_212 & V_214 ) && ( V_6 -> V_155 & V_156 ) &&
( ! F_93 ( & V_6 -> V_2 . V_190 -> V_192 ) || V_6 -> V_2 . V_193 ) &&
( V_160 & V_215 ) ) {
V_212 &= ~ ( V_250 | V_214 ) ;
V_212 |= V_251 ;
}
if ( ! ( V_212 & V_214 ) )
F_77 ( V_6 ) ;
if ( V_6 -> V_2 . V_149 )
F_5 ( V_6 , V_57 , V_155 ) ;
F_63 ( & V_6 -> V_2 . V_66 , V_106 ) ;
F_128 ( & V_6 -> V_248 ,
V_249 + F_129 ( & V_6 -> V_2 ) + V_252 / 5 ) ;
}
static unsigned int F_131 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_27 ( V_2 ) ;
unsigned long V_106 ;
unsigned int V_160 ;
F_34 ( V_6 ) ;
F_61 ( & V_2 -> V_66 , V_106 ) ;
V_160 = F_94 ( V_2 , V_78 ) ;
V_6 -> V_161 |= V_160 & V_162 ;
F_63 ( & V_2 -> V_66 , V_106 ) ;
F_36 ( V_6 ) ;
return ( V_160 & V_199 ) == V_199 ? V_253 : 0 ;
}
static unsigned int F_132 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_27 ( V_2 ) ;
unsigned int V_103 ;
unsigned int V_216 ;
F_34 ( V_6 ) ;
V_103 = F_97 ( V_6 ) ;
F_36 ( V_6 ) ;
V_216 = 0 ;
if ( V_103 & V_208 )
V_216 |= V_254 ;
if ( V_103 & V_255 )
V_216 |= V_256 ;
if ( V_103 & V_257 )
V_216 |= V_258 ;
if ( V_103 & V_210 )
V_216 |= V_259 ;
return V_216 ;
}
static void F_133 ( struct V_1 * V_2 , unsigned int V_260 )
{
struct V_5 * V_6 = F_27 ( V_2 ) ;
unsigned char V_261 = 0 ;
if ( V_260 & V_262 )
V_261 |= V_154 ;
if ( V_260 & V_263 )
V_261 |= V_153 ;
if ( V_260 & V_264 )
V_261 |= V_151 ;
if ( V_260 & V_265 )
V_261 |= V_152 ;
if ( V_260 & V_266 )
V_261 |= V_75 ;
V_261 = ( V_261 & V_6 -> V_267 ) | V_6 -> V_268 | V_6 -> V_261 ;
F_76 ( V_2 , V_74 , V_261 ) ;
}
static void F_134 ( struct V_1 * V_2 , int V_269 )
{
struct V_5 * V_6 = F_27 ( V_2 ) ;
unsigned long V_106 ;
F_34 ( V_6 ) ;
F_61 ( & V_2 -> V_66 , V_106 ) ;
if ( V_269 == - 1 )
V_6 -> V_270 |= V_271 ;
else
V_6 -> V_270 &= ~ V_271 ;
F_76 ( V_2 , V_30 , V_6 -> V_270 ) ;
F_63 ( & V_2 -> V_66 , V_106 ) ;
F_36 ( V_6 ) ;
}
static void F_135 ( struct V_5 * V_6 , int V_272 )
{
unsigned int V_103 , V_273 = 10000 ;
for (; ; ) {
V_103 = F_3 ( V_6 , V_78 ) ;
V_6 -> V_161 |= V_103 & V_162 ;
if ( ( V_103 & V_272 ) == V_272 )
break;
if ( -- V_273 == 0 )
break;
F_71 ( 1 ) ;
}
if ( V_6 -> V_2 . V_106 & V_274 ) {
unsigned int V_273 ;
for ( V_273 = 1000000 ; V_273 ; V_273 -- ) {
unsigned int V_275 = F_3 ( V_6 , V_131 ) ;
V_6 -> V_201 |= V_275 & V_276 ;
if ( V_275 & V_210 )
break;
F_71 ( 1 ) ;
F_136 () ;
}
}
}
static int F_137 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_27 ( V_2 ) ;
unsigned char V_160 ;
int V_103 ;
F_34 ( V_6 ) ;
V_160 = F_94 ( V_2 , V_78 ) ;
if ( ! ( V_160 & V_79 ) ) {
V_103 = V_277 ;
goto V_51;
}
V_103 = F_94 ( V_2 , V_80 ) ;
V_51:
F_36 ( V_6 ) ;
return V_103 ;
}
static void F_138 ( struct V_1 * V_2 ,
unsigned char V_278 )
{
unsigned int V_155 ;
struct V_5 * V_6 = F_27 ( V_2 ) ;
F_34 ( V_6 ) ;
V_155 = F_94 ( V_2 , V_57 ) ;
if ( V_6 -> V_36 & V_119 )
F_76 ( V_2 , V_57 , V_117 ) ;
else
F_76 ( V_2 , V_57 , 0 ) ;
F_135 ( V_6 , V_199 ) ;
F_76 ( V_2 , V_77 , V_278 ) ;
F_135 ( V_6 , V_199 ) ;
F_76 ( V_2 , V_57 , V_155 ) ;
F_36 ( V_6 ) ;
}
int F_139 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_27 ( V_2 ) ;
unsigned long V_106 ;
unsigned char V_160 , V_212 ;
int V_279 ;
if ( V_2 -> type == V_280 )
return - V_281 ;
if ( ! V_2 -> V_138 )
V_2 -> V_138 = V_139 [ V_2 -> type ] . V_140 ;
if ( ! V_6 -> V_141 )
V_6 -> V_141 = V_139 [ V_2 -> type ] . V_141 ;
if ( ! V_6 -> V_36 )
V_6 -> V_36 = V_139 [ V_2 -> type ] . V_106 ;
V_6 -> V_261 = 0 ;
if ( V_2 -> V_20 != V_6 -> V_27 )
F_26 ( V_2 ) ;
F_34 ( V_6 ) ;
if ( V_2 -> type == V_92 ) {
V_6 -> V_34 = 0 ;
F_76 ( V_2 , V_30 , V_54 ) ;
F_76 ( V_2 , V_55 , V_56 ) ;
F_76 ( V_2 , V_57 , 0 ) ;
F_76 ( V_2 , V_30 , 0 ) ;
F_30 ( V_6 , V_282 , 0 ) ;
F_76 ( V_2 , V_30 , V_54 ) ;
F_76 ( V_2 , V_55 , V_56 ) ;
F_76 ( V_2 , V_30 , 0 ) ;
}
#ifdef F_64
F_44 ( V_6 ) ;
#endif
F_32 ( V_6 ) ;
if ( F_94 ( V_2 , V_78 ) & V_79 )
F_94 ( V_2 , V_80 ) ;
F_94 ( V_2 , V_115 ) ;
F_94 ( V_2 , V_131 ) ;
if ( ! ( V_2 -> V_106 & V_129 ) &&
( F_94 ( V_2 , V_78 ) == 0xff ) ) {
F_106 ( V_283 L_24 ,
F_1 ( V_2 ) ) ;
V_279 = - V_281 ;
goto V_51;
}
if ( V_2 -> type == V_95 ) {
unsigned char V_284 ;
F_5 ( V_6 , V_30 , V_54 ) ;
V_284 = F_3 ( V_6 , V_285 ) & ~ ( V_286 | V_287 ) ;
F_76 ( V_2 , V_285 ,
V_284 | V_288 | V_286 ) ;
F_76 ( V_2 , V_289 , V_290 ) ;
F_76 ( V_2 , V_285 ,
V_284 | V_288 | V_287 ) ;
F_76 ( V_2 , V_289 , V_290 ) ;
F_76 ( V_2 , V_30 , 0 ) ;
}
if ( V_2 -> V_149 ) {
unsigned char V_291 ;
F_61 ( & V_2 -> V_66 , V_106 ) ;
if ( V_6 -> V_2 . V_246 & V_240 )
F_140 ( V_2 -> V_149 ) ;
F_135 ( V_6 , V_215 ) ;
F_29 ( V_2 , V_57 , V_156 ) ;
F_71 ( 1 ) ;
V_291 = F_94 ( V_2 , V_115 ) ;
F_76 ( V_2 , V_57 , 0 ) ;
F_29 ( V_2 , V_57 , V_156 ) ;
F_71 ( 1 ) ;
V_212 = F_94 ( V_2 , V_115 ) ;
F_76 ( V_2 , V_57 , 0 ) ;
if ( V_2 -> V_246 & V_240 )
F_141 ( V_2 -> V_149 ) ;
F_63 ( & V_2 -> V_66 , V_106 ) ;
if ( ( ! ( V_291 & V_214 ) && ( V_212 & V_214 ) ) ||
V_6 -> V_2 . V_106 & V_292 ) {
V_6 -> V_93 |= V_293 ;
F_142 ( L_25 ,
F_1 ( V_2 ) ) ;
}
}
if ( V_6 -> V_93 & V_293 ) {
V_6 -> V_248 . V_294 = F_130 ;
V_6 -> V_248 . V_247 = ( unsigned long ) V_6 ;
F_128 ( & V_6 -> V_248 , V_249 +
F_129 ( V_2 ) + V_252 / 5 ) ;
}
if ( ! V_2 -> V_149 ) {
V_6 -> V_248 . V_247 = ( unsigned long ) V_6 ;
F_128 ( & V_6 -> V_248 , V_249 + F_129 ( V_2 ) ) ;
} else {
V_279 = F_114 ( V_6 ) ;
if ( V_279 )
goto V_51;
}
F_76 ( V_2 , V_30 , V_295 ) ;
F_61 ( & V_2 -> V_66 , V_106 ) ;
if ( V_6 -> V_2 . V_106 & V_150 ) {
if ( ! V_6 -> V_2 . V_149 )
V_6 -> V_2 . V_260 |= V_264 ;
} else
if ( V_2 -> V_149 )
V_6 -> V_2 . V_260 |= V_265 ;
F_133 ( V_2 , V_2 -> V_260 ) ;
if ( V_296 || V_6 -> V_2 . V_106 & V_297 )
goto V_298;
F_76 ( V_2 , V_57 , V_156 ) ;
V_160 = F_94 ( V_2 , V_78 ) ;
V_212 = F_94 ( V_2 , V_115 ) ;
F_76 ( V_2 , V_57 , 0 ) ;
if ( V_160 & V_163 && V_212 & V_214 ) {
if ( ! ( V_6 -> V_93 & V_159 ) ) {
V_6 -> V_93 |= V_159 ;
F_142 ( L_26 ,
F_1 ( V_2 ) ) ;
}
} else {
V_6 -> V_93 &= ~ V_159 ;
}
V_298:
F_63 ( & V_2 -> V_66 , V_106 ) ;
if ( F_94 ( V_2 , V_78 ) & V_79 )
F_94 ( V_2 , V_80 ) ;
F_94 ( V_2 , V_115 ) ;
F_94 ( V_2 , V_131 ) ;
V_6 -> V_161 = 0 ;
V_6 -> V_201 = 0 ;
if ( V_6 -> V_158 ) {
V_279 = F_143 ( V_6 ) ;
if ( V_279 ) {
F_144 ( L_27 ,
F_1 ( V_2 ) ) ;
V_6 -> V_158 = NULL ;
}
}
V_6 -> V_155 = V_166 | V_167 ;
F_76 ( V_2 , V_57 , V_6 -> V_155 ) ;
if ( V_2 -> V_106 & V_150 ) {
unsigned int V_299 ;
V_299 = ( V_2 -> V_17 & 0xfe0 ) | 0x01f ;
F_68 ( 0x80 , V_299 ) ;
F_67 ( V_299 ) ;
}
V_279 = 0 ;
V_51:
F_36 ( V_6 ) ;
return V_279 ;
}
static int F_145 ( struct V_1 * V_2 )
{
if ( V_2 -> V_300 )
return V_2 -> V_300 ( V_2 ) ;
return F_139 ( V_2 ) ;
}
void F_146 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_27 ( V_2 ) ;
unsigned long V_106 ;
F_34 ( V_6 ) ;
V_6 -> V_155 = 0 ;
F_76 ( V_2 , V_57 , 0 ) ;
if ( V_6 -> V_158 )
F_147 ( V_6 ) ;
F_61 ( & V_2 -> V_66 , V_106 ) ;
if ( V_2 -> V_106 & V_150 ) {
F_14 ( ( V_2 -> V_17 & 0xfe0 ) | 0x1f ) ;
V_2 -> V_260 |= V_264 ;
} else
V_2 -> V_260 &= ~ V_265 ;
F_133 ( V_2 , V_2 -> V_260 ) ;
F_63 ( & V_2 -> V_66 , V_106 ) ;
F_76 ( V_2 , V_30 ,
F_94 ( V_2 , V_30 ) & ~ V_271 ) ;
F_32 ( V_6 ) ;
#ifdef F_64
F_47 ( V_6 ) ;
#endif
if ( F_94 ( V_2 , V_78 ) & V_79 )
F_94 ( V_2 , V_80 ) ;
F_36 ( V_6 ) ;
F_148 ( & V_6 -> V_248 ) ;
V_6 -> V_248 . V_294 = F_127 ;
if ( V_2 -> V_149 )
F_125 ( V_6 ) ;
}
static void F_149 ( struct V_1 * V_2 )
{
if ( V_2 -> V_301 )
V_2 -> V_301 ( V_2 ) ;
else
F_146 ( V_2 ) ;
}
static unsigned int F_150 ( struct V_1 * V_2 , unsigned int V_302 )
{
unsigned int V_111 ;
if ( ( V_2 -> V_106 & V_303 ) &&
V_302 == ( V_2 -> V_63 / 4 ) )
V_111 = 0x8001 ;
else if ( ( V_2 -> V_106 & V_303 ) &&
V_302 == ( V_2 -> V_63 / 8 ) )
V_111 = 0x8002 ;
else
V_111 = F_151 ( V_2 , V_302 ) ;
return V_111 ;
}
void
F_152 ( struct V_1 * V_2 , struct V_304 * V_305 ,
struct V_304 * V_306 )
{
struct V_5 * V_6 = F_27 ( V_2 ) ;
unsigned char V_307 ;
unsigned long V_106 ;
unsigned int V_302 , V_111 ;
switch ( V_305 -> V_308 & V_309 ) {
case V_310 :
V_307 = V_311 ;
break;
case V_312 :
V_307 = V_313 ;
break;
case V_314 :
V_307 = V_315 ;
break;
default:
case V_316 :
V_307 = V_295 ;
break;
}
if ( V_305 -> V_308 & V_317 )
V_307 |= V_318 ;
if ( V_305 -> V_308 & V_319 ) {
V_307 |= V_320 ;
if ( V_6 -> V_93 & V_321 )
V_6 -> V_322 = true ;
}
if ( ! ( V_305 -> V_308 & V_323 ) )
V_307 |= V_324 ;
#ifdef F_153
if ( V_305 -> V_308 & F_153 )
V_307 |= V_325 ;
#endif
V_302 = F_154 ( V_2 , V_305 , V_306 ,
V_2 -> V_63 / 16 / 0xffff ,
V_2 -> V_63 / 16 ) ;
V_111 = F_150 ( V_2 , V_302 ) ;
if ( V_6 -> V_93 & V_94 && ( V_111 & 0xff ) == 0 )
V_111 ++ ;
if ( V_6 -> V_36 & V_37 && V_2 -> V_138 > 1 ) {
if ( ( V_302 < 2400 && ! V_6 -> V_158 ) || V_6 -> V_322 ) {
V_6 -> V_42 &= ~ V_326 ;
V_6 -> V_42 |= V_327 ;
}
}
if ( V_6 -> V_36 & V_109 && V_2 -> V_138 >= 32 ) {
V_6 -> V_261 &= ~ V_328 ;
if ( V_305 -> V_308 & V_329 )
V_6 -> V_261 |= V_328 ;
}
F_34 ( V_6 ) ;
F_61 ( & V_2 -> V_66 , V_106 ) ;
F_155 ( V_2 , V_305 -> V_308 , V_302 ) ;
V_2 -> V_168 = V_185 | V_215 | V_79 ;
if ( V_305 -> V_330 & V_331 )
V_2 -> V_168 |= V_179 | V_180 ;
if ( V_305 -> V_330 & ( V_332 | V_333 | V_334 ) )
V_2 -> V_168 |= V_178 ;
V_2 -> V_335 = 0 ;
if ( V_305 -> V_330 & V_336 )
V_2 -> V_335 |= V_180 | V_179 ;
if ( V_305 -> V_330 & V_332 ) {
V_2 -> V_335 |= V_178 ;
if ( V_305 -> V_330 & V_336 )
V_2 -> V_335 |= V_185 ;
}
if ( ( V_305 -> V_308 & V_337 ) == 0 )
V_2 -> V_335 |= V_79 ;
V_6 -> V_155 &= ~ V_170 ;
if ( ! ( V_6 -> V_93 & V_169 ) &&
F_156 ( & V_6 -> V_2 , V_305 -> V_308 ) )
V_6 -> V_155 |= V_170 ;
if ( V_6 -> V_36 & V_119 )
V_6 -> V_155 |= V_117 ;
if ( V_6 -> V_36 & V_120 )
V_6 -> V_155 |= V_338 ;
F_76 ( V_2 , V_57 , V_6 -> V_155 ) ;
if ( V_6 -> V_36 & V_53 ) {
unsigned char V_339 = 0 ;
if ( V_305 -> V_308 & V_329 )
V_339 |= V_340 ;
F_76 ( V_2 , V_30 , V_54 ) ;
if ( V_2 -> V_106 & V_107 )
F_76 ( V_2 , V_341 , V_339 ) ;
else
F_76 ( V_2 , V_55 , V_339 ) ;
}
if ( F_157 ( V_6 ) ) {
if ( V_302 == 115200 ) {
V_111 = 1 ;
F_76 ( V_2 , V_342 , 1 ) ;
} else
F_76 ( V_2 , V_342 , 0 ) ;
}
if ( V_6 -> V_36 & V_113 )
F_76 ( V_2 , V_30 , 0xe0 ) ;
else
F_76 ( V_2 , V_30 , V_307 | V_343 ) ;
F_50 ( V_6 , V_111 ) ;
if ( V_6 -> V_2 . type == V_48 ) {
unsigned int V_344 = ( V_2 -> V_63 * 2 ) / V_302 ;
T_3 V_111 = V_344 / 32 ;
T_4 V_345 = F_158 ( V_344 % 32 , 2 ) ;
F_50 ( V_6 , V_111 ) ;
F_76 ( V_2 , 0x2 , V_345 & 0xf ) ;
}
if ( V_2 -> type == V_116 )
F_76 ( V_2 , V_38 , V_6 -> V_42 ) ;
F_76 ( V_2 , V_30 , V_307 ) ;
V_6 -> V_270 = V_307 ;
if ( V_2 -> type != V_116 ) {
if ( V_6 -> V_42 & V_39 )
F_76 ( V_2 , V_38 , V_39 ) ;
F_76 ( V_2 , V_38 , V_6 -> V_42 ) ;
}
F_133 ( V_2 , V_2 -> V_260 ) ;
F_63 ( & V_2 -> V_66 , V_106 ) ;
F_36 ( V_6 ) ;
if ( F_159 ( V_305 ) )
F_160 ( V_305 , V_302 , V_302 ) ;
}
static void
F_161 ( struct V_1 * V_2 , struct V_304 * V_305 ,
struct V_304 * V_306 )
{
if ( V_2 -> V_346 )
V_2 -> V_346 ( V_2 , V_305 , V_306 ) ;
else
F_152 ( V_2 , V_305 , V_306 ) ;
}
static void
F_162 ( struct V_1 * V_2 , int V_347 )
{
if ( V_347 == V_348 ) {
V_2 -> V_106 |= V_349 ;
F_81 ( V_2 ) ;
} else
V_2 -> V_106 &= ~ V_349 ;
}
void F_163 ( struct V_1 * V_2 , unsigned int V_190 ,
unsigned int V_350 )
{
struct V_5 * V_10 = F_27 ( V_2 ) ;
F_42 ( V_10 , V_190 != 0 ) ;
}
static void
F_164 ( struct V_1 * V_2 , unsigned int V_190 ,
unsigned int V_350 )
{
if ( V_2 -> V_351 )
V_2 -> V_351 ( V_2 , V_190 , V_350 ) ;
else
F_163 ( V_2 , V_190 , V_350 ) ;
}
static unsigned int F_165 ( struct V_5 * V_352 )
{
if ( V_352 -> V_2 . V_20 == V_26 )
return 0x1000 ;
if ( F_166 ( V_352 ) )
return 0x16 << V_352 -> V_2 . V_13 ;
return 8 << V_352 -> V_2 . V_13 ;
}
static int F_167 ( struct V_5 * V_6 )
{
unsigned int V_353 = F_165 ( V_6 ) ;
struct V_1 * V_2 = & V_6 -> V_2 ;
int V_216 = 0 ;
switch ( V_2 -> V_20 ) {
case V_26 :
case V_354 :
case V_23 :
case V_22 :
if ( ! V_2 -> V_128 )
break;
if ( ! F_168 ( V_2 -> V_128 , V_353 , L_23 ) ) {
V_216 = - V_355 ;
break;
}
if ( V_2 -> V_106 & V_356 ) {
V_2 -> V_14 = F_169 ( V_2 -> V_128 , V_353 ) ;
if ( ! V_2 -> V_14 ) {
F_170 ( V_2 -> V_128 , V_353 ) ;
V_216 = - V_245 ;
}
}
break;
case V_21 :
case V_357 :
if ( ! F_171 ( V_2 -> V_17 , V_353 , L_23 ) )
V_216 = - V_355 ;
break;
}
return V_216 ;
}
static void F_172 ( struct V_5 * V_6 )
{
unsigned int V_353 = F_165 ( V_6 ) ;
struct V_1 * V_2 = & V_6 -> V_2 ;
switch ( V_2 -> V_20 ) {
case V_26 :
case V_354 :
case V_23 :
case V_22 :
if ( ! V_2 -> V_128 )
break;
if ( V_2 -> V_106 & V_356 ) {
F_173 ( V_2 -> V_14 ) ;
V_2 -> V_14 = NULL ;
}
F_170 ( V_2 -> V_128 , V_353 ) ;
break;
case V_21 :
case V_357 :
F_174 ( V_2 -> V_17 , V_353 ) ;
break;
}
}
static int F_175 ( struct V_5 * V_6 )
{
unsigned long V_358 = V_359 << V_6 -> V_2 . V_13 ;
unsigned int V_353 = 8 << V_6 -> V_2 . V_13 ;
struct V_1 * V_2 = & V_6 -> V_2 ;
int V_216 = - V_360 ;
switch ( V_2 -> V_20 ) {
case V_21 :
case V_357 :
V_358 += V_2 -> V_17 ;
if ( F_171 ( V_358 , V_353 , L_28 ) )
V_216 = 0 ;
else
V_216 = - V_355 ;
break;
}
return V_216 ;
}
static void F_176 ( struct V_5 * V_6 )
{
unsigned long V_11 = V_359 << V_6 -> V_2 . V_13 ;
unsigned int V_353 = 8 << V_6 -> V_2 . V_13 ;
struct V_1 * V_2 = & V_6 -> V_2 ;
switch ( V_2 -> V_20 ) {
case V_21 :
case V_357 :
F_174 ( V_2 -> V_17 + V_11 , V_353 ) ;
break;
}
}
static void F_177 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_27 ( V_2 ) ;
F_172 ( V_6 ) ;
if ( V_2 -> type == V_65 )
F_176 ( V_6 ) ;
}
static int F_178 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_27 ( V_2 ) ;
int V_216 ;
if ( V_2 -> type == V_280 )
return - V_281 ;
V_216 = F_167 ( V_6 ) ;
if ( V_216 == 0 && V_2 -> type == V_65 ) {
V_216 = F_175 ( V_6 ) ;
if ( V_216 < 0 )
F_172 ( V_6 ) ;
}
return V_216 ;
}
static int F_179 ( struct V_5 * V_6 )
{
const struct V_361 * V_362 = & V_139 [ V_6 -> V_2 . type ] ;
unsigned char V_363 ;
V_363 = V_362 -> V_364 [ F_180 ( V_6 -> V_42 ) ] ;
return V_363 ? V_363 : - V_365 ;
}
static int F_181 ( struct V_5 * V_6 , unsigned char V_363 )
{
const struct V_361 * V_362 = & V_139 [ V_6 -> V_2 . type ] ;
int V_135 ;
if ( ! V_362 -> V_364 [ F_180 ( V_366 ) ] )
return - V_365 ;
for ( V_135 = 1 ; V_135 < V_367 ; V_135 ++ ) {
if ( V_363 < V_362 -> V_364 [ V_135 ] )
return ( -- V_135 ) << V_368 ;
}
return V_369 ;
}
static int F_182 ( struct V_370 * V_2 )
{
struct V_371 * V_190 = F_183 ( V_2 , struct V_371 , V_2 ) ;
struct V_1 * V_372 = V_190 -> V_1 ;
struct V_5 * V_6 =
F_183 ( V_372 , struct V_5 , V_2 ) ;
if ( ! ( V_6 -> V_36 & V_37 ) || V_372 -> V_138 <= 1 )
return - V_360 ;
return F_179 ( V_6 ) ;
}
static int F_184 ( struct V_370 * V_2 )
{
int V_364 ;
F_115 ( & V_2 -> V_373 ) ;
V_364 = F_182 ( V_2 ) ;
F_119 ( & V_2 -> V_373 ) ;
return V_364 ;
}
static T_5 F_185 ( struct V_374 * V_44 ,
struct V_375 * V_376 , char * V_195 )
{
struct V_370 * V_2 = F_186 ( V_44 ) ;
int V_364 ;
V_364 = F_184 ( V_2 ) ;
if ( V_364 < 0 )
return V_364 ;
return snprintf ( V_195 , V_377 , L_29 , V_364 ) ;
}
static int F_187 ( struct V_370 * V_2 , unsigned char V_363 )
{
struct V_371 * V_190 = F_183 ( V_2 , struct V_371 , V_2 ) ;
struct V_1 * V_372 = V_190 -> V_1 ;
struct V_5 * V_6 =
F_183 ( V_372 , struct V_5 , V_2 ) ;
int V_378 ;
if ( ! ( V_6 -> V_36 & V_37 ) || V_372 -> V_138 <= 1 ||
V_6 -> V_322 )
return - V_360 ;
V_378 = F_181 ( V_6 , V_363 ) ;
if ( V_378 < 0 )
return V_378 ;
F_32 ( V_6 ) ;
V_6 -> V_42 &= ~ V_326 ;
V_6 -> V_42 |= ( unsigned char ) V_378 ;
F_5 ( V_6 , V_38 , V_6 -> V_42 ) ;
return 0 ;
}
static int F_188 ( struct V_370 * V_2 , unsigned char V_363 )
{
int V_216 ;
F_115 ( & V_2 -> V_373 ) ;
V_216 = F_187 ( V_2 , V_363 ) ;
F_119 ( & V_2 -> V_373 ) ;
return V_216 ;
}
static T_5 F_189 ( struct V_374 * V_44 ,
struct V_375 * V_376 , const char * V_195 , T_6 V_73 )
{
struct V_370 * V_2 = F_186 ( V_44 ) ;
unsigned char V_363 ;
int V_216 ;
if ( ! V_73 )
return - V_360 ;
V_216 = F_190 ( V_195 , 10 , & V_363 ) ;
if ( V_216 < 0 )
return V_216 ;
V_216 = F_188 ( V_2 , V_363 ) ;
if ( V_216 < 0 )
return V_216 ;
return V_73 ;
}
static void F_191 ( struct V_5 * V_6 )
{
const struct V_361 * V_362 = & V_139 [ V_6 -> V_2 . type ] ;
if ( V_362 -> V_364 [ 0 ] )
V_6 -> V_2 . V_379 = & V_380 ;
}
static void F_192 ( struct V_1 * V_2 , int V_106 )
{
struct V_5 * V_6 = F_27 ( V_2 ) ;
int V_122 = V_381 ;
int V_216 ;
if ( V_2 -> type == V_280 )
return;
V_216 = F_167 ( V_6 ) ;
if ( V_216 < 0 )
return;
V_216 = F_175 ( V_6 ) ;
if ( V_216 < 0 )
V_122 &= ~ V_134 ;
if ( V_2 -> V_20 != V_6 -> V_27 )
F_26 ( V_2 ) ;
if ( V_106 & V_382 )
F_60 ( V_6 , V_122 ) ;
if ( V_2 -> type == V_105 && V_2 -> V_20 == V_26 )
V_6 -> V_93 |= V_169 ;
if ( V_2 -> type == V_383 )
V_6 -> V_93 |= V_169 ;
if ( V_2 -> type != V_132 && V_106 & V_384 )
F_66 ( V_6 ) ;
if ( V_2 -> type != V_65 && V_122 & V_134 )
F_176 ( V_6 ) ;
if ( V_2 -> type == V_132 )
F_172 ( V_6 ) ;
if ( ( V_2 -> type == V_48 ) ||
( V_2 -> type == V_49 ) )
V_2 -> V_28 = F_103 ;
F_191 ( V_6 ) ;
V_6 -> V_42 = V_139 [ V_6 -> V_2 . type ] . V_42 ;
}
static int
F_193 ( struct V_1 * V_2 , struct V_385 * V_386 )
{
if ( V_386 -> V_149 >= V_387 || V_386 -> V_149 < 0 ||
V_386 -> V_388 < 9600 || V_386 -> type < V_132 ||
V_386 -> type >= F_194 ( V_139 ) || V_386 -> type == V_389 ||
V_386 -> type == V_390 )
return - V_360 ;
return 0 ;
}
static int F_195 ( struct V_1 * V_2 , unsigned int V_391 ,
unsigned long V_392 )
{
struct V_5 * V_6 =
F_183 ( V_2 , struct V_5 , V_2 ) ;
int V_216 ;
struct V_393 V_394 ;
if ( ! V_6 -> V_394 )
return - V_395 ;
switch ( V_391 ) {
case V_396 :
if ( F_196 ( & V_394 , ( void V_397 * ) V_392 ,
sizeof( V_394 ) ) )
return - V_398 ;
V_216 = V_6 -> V_394 ( V_6 , & V_394 ) ;
if ( V_216 )
return V_216 ;
memcpy ( & V_6 -> V_399 , & V_394 , sizeof( V_394 ) ) ;
return 0 ;
case V_400 :
if ( F_197 ( ( void V_397 * ) V_392 , & V_6 -> V_399 ,
sizeof( V_6 -> V_399 ) ) )
return - V_398 ;
return 0 ;
default:
break;
}
return - V_395 ;
}
static const char *
F_198 ( struct V_1 * V_2 )
{
int type = V_2 -> type ;
if ( type >= F_194 ( V_139 ) )
type = 0 ;
return V_139 [ type ] . V_144 ;
}
struct V_5 * F_199 ( int line )
{
return & V_401 [ line ] ;
}
void F_200 (
void (* F_201)( int V_2 , struct V_1 * V_6 , unsigned short * V_36 ) )
{
V_402 = F_201 ;
}
static void T_7 F_202 ( void )
{
struct V_5 * V_6 ;
static int V_403 = 1 ;
int V_135 , V_404 = 0 ;
if ( ! V_403 )
return;
V_403 = 0 ;
if ( V_405 > V_406 )
V_405 = V_406 ;
for ( V_135 = 0 ; V_135 < V_405 ; V_135 ++ ) {
struct V_5 * V_6 = & V_401 [ V_135 ] ;
struct V_1 * V_2 = & V_6 -> V_2 ;
V_2 -> line = V_135 ;
F_120 ( & V_2 -> V_66 ) ;
F_203 ( & V_6 -> V_248 ) ;
V_6 -> V_248 . V_294 = F_127 ;
V_6 -> V_27 = 0xFF ;
V_6 -> V_267 = ~ V_407 ;
V_6 -> V_268 = V_407 ;
V_2 -> V_408 = & V_409 ;
}
if ( V_410 )
V_404 = V_240 ;
for ( V_135 = 0 , V_6 = V_401 ;
V_135 < F_194 ( V_411 ) && V_135 < V_405 ;
V_135 ++ , V_6 ++ ) {
struct V_1 * V_2 = & V_6 -> V_2 ;
V_2 -> V_17 = V_411 [ V_135 ] . V_2 ;
V_2 -> V_149 = F_204 ( V_411 [ V_135 ] . V_149 ) ;
V_2 -> V_246 = V_411 [ V_135 ] . V_246 ;
V_2 -> V_63 = V_411 [ V_135 ] . V_388 * 16 ;
V_2 -> V_106 = V_411 [ V_135 ] . V_106 ;
V_2 -> V_16 = V_411 [ V_135 ] . V_16 ;
V_2 -> V_14 = V_411 [ V_135 ] . V_412 ;
V_2 -> V_20 = V_411 [ V_135 ] . V_413 ;
V_2 -> V_13 = V_411 [ V_135 ] . V_414 ;
F_26 ( V_2 ) ;
V_2 -> V_246 |= V_404 ;
if ( V_402 != NULL )
V_402 ( V_135 , & V_6 -> V_2 , & V_6 -> V_36 ) ;
}
}
static void
F_205 ( struct V_5 * V_6 , unsigned int type )
{
V_6 -> V_2 . type = type ;
if ( ! V_6 -> V_2 . V_138 )
V_6 -> V_2 . V_138 = V_139 [ type ] . V_140 ;
if ( ! V_6 -> V_141 )
V_6 -> V_141 = V_139 [ type ] . V_141 ;
if ( ! V_6 -> V_36 )
V_6 -> V_36 = V_139 [ type ] . V_106 ;
}
static void T_7
F_206 ( struct V_415 * V_416 , struct V_374 * V_44 )
{
int V_135 ;
for ( V_135 = 0 ; V_135 < V_405 ; V_135 ++ ) {
struct V_5 * V_6 = & V_401 [ V_135 ] ;
if ( V_6 -> V_2 . V_44 )
continue;
V_6 -> V_2 . V_44 = V_44 ;
if ( V_6 -> V_2 . V_106 & V_417 )
F_205 ( V_6 , V_6 -> V_2 . type ) ;
F_207 ( V_416 , & V_6 -> V_2 ) ;
}
}
static void F_208 ( struct V_1 * V_2 , int V_171 )
{
struct V_5 * V_6 = F_27 ( V_2 ) ;
F_135 ( V_6 , V_215 ) ;
F_76 ( V_2 , V_77 , V_171 ) ;
}
static void
F_209 ( struct V_418 * V_419 , const char * V_420 , unsigned int V_73 )
{
struct V_5 * V_6 = & V_401 [ V_419 -> V_421 ] ;
struct V_1 * V_2 = & V_6 -> V_2 ;
unsigned long V_106 ;
unsigned int V_155 ;
int V_422 = 1 ;
F_136 () ;
F_34 ( V_6 ) ;
if ( V_2 -> V_423 || V_424 )
V_422 = F_210 ( & V_2 -> V_66 , V_106 ) ;
else
F_61 ( & V_2 -> V_66 , V_106 ) ;
V_155 = F_94 ( V_2 , V_57 ) ;
if ( V_6 -> V_36 & V_119 )
F_76 ( V_2 , V_57 , V_117 ) ;
else
F_76 ( V_2 , V_57 , 0 ) ;
F_211 ( V_2 , V_420 , V_73 , F_208 ) ;
F_135 ( V_6 , V_199 ) ;
F_76 ( V_2 , V_57 , V_155 ) ;
if ( V_6 -> V_201 )
F_97 ( V_6 ) ;
if ( V_422 )
F_63 ( & V_2 -> V_66 , V_106 ) ;
F_36 ( V_6 ) ;
}
static int T_7 F_212 ( struct V_418 * V_419 , char * V_425 )
{
struct V_1 * V_2 ;
int V_302 = 9600 ;
int V_272 = 8 ;
int V_183 = 'n' ;
int V_426 = 'n' ;
if ( V_419 -> V_421 >= V_405 )
V_419 -> V_421 = 0 ;
V_2 = & V_401 [ V_419 -> V_421 ] . V_2 ;
if ( ! V_2 -> V_17 && ! V_2 -> V_14 )
return - V_281 ;
if ( V_425 )
F_213 ( V_425 , & V_302 , & V_183 , & V_272 , & V_426 ) ;
return F_214 ( V_2 , V_419 , V_302 , V_183 , V_272 , V_426 ) ;
}
static int F_215 ( void )
{
return F_216 () ;
}
static int T_7 F_217 ( void )
{
F_202 () ;
F_218 ( & V_427 ) ;
return 0 ;
}
int F_219 ( struct V_1 * V_10 )
{
int line ;
struct V_1 * V_2 ;
for ( line = 0 ; line < V_405 ; line ++ ) {
V_2 = & V_401 [ line ] . V_2 ;
if ( F_220 ( V_10 , V_2 ) )
return line ;
}
return - V_281 ;
}
int T_7 F_221 ( struct V_1 * V_2 )
{
struct V_1 * V_10 ;
if ( V_2 -> line >= F_194 ( V_401 ) )
return - V_281 ;
F_202 () ;
V_10 = & V_401 [ V_2 -> line ] . V_2 ;
V_10 -> V_17 = V_2 -> V_17 ;
V_10 -> V_14 = V_2 -> V_14 ;
V_10 -> V_149 = V_2 -> V_149 ;
V_10 -> V_246 = V_2 -> V_246 ;
V_10 -> V_63 = V_2 -> V_63 ;
V_10 -> V_138 = V_2 -> V_138 ;
V_10 -> V_13 = V_2 -> V_13 ;
V_10 -> V_20 = V_2 -> V_20 ;
V_10 -> V_106 = V_2 -> V_106 ;
V_10 -> V_128 = V_2 -> V_128 ;
V_10 -> V_428 = V_2 -> V_428 ;
V_10 -> type = V_2 -> type ;
V_10 -> line = V_2 -> line ;
F_26 ( V_10 ) ;
if ( V_2 -> F_3 )
V_10 -> F_3 = V_2 -> F_3 ;
if ( V_2 -> F_5 )
V_10 -> F_5 = V_2 -> F_5 ;
if ( V_2 -> V_28 )
V_10 -> V_28 = V_2 -> V_28 ;
else
V_10 -> V_28 = V_29 ;
return 0 ;
}
void F_222 ( int line )
{
F_223 ( & V_3 , & V_401 [ line ] . V_2 ) ;
}
void F_224 ( int line )
{
struct V_5 * V_6 = & V_401 [ line ] ;
struct V_1 * V_2 = & V_6 -> V_2 ;
if ( V_6 -> V_36 & V_113 ) {
F_76 ( V_2 , V_30 , 0xE0 ) ;
F_57 ( V_6 ) ;
F_76 ( V_2 , V_30 , 0 ) ;
V_2 -> V_63 = 921600 * 16 ;
}
F_225 ( & V_3 , V_2 ) ;
}
static int F_226 ( struct V_429 * V_44 )
{
struct V_430 * V_10 = F_227 ( & V_44 -> V_44 ) ;
struct V_5 V_431 ;
int V_216 , V_135 , V_404 = 0 ;
memset ( & V_431 , 0 , sizeof( V_431 ) ) ;
if ( V_410 )
V_404 = V_240 ;
for ( V_135 = 0 ; V_10 && V_10 -> V_106 != 0 ; V_10 ++ , V_135 ++ ) {
V_431 . V_2 . V_17 = V_10 -> V_17 ;
V_431 . V_2 . V_14 = V_10 -> V_14 ;
V_431 . V_2 . V_149 = V_10 -> V_149 ;
V_431 . V_2 . V_246 = V_10 -> V_246 ;
V_431 . V_2 . V_63 = V_10 -> V_63 ;
V_431 . V_2 . V_13 = V_10 -> V_13 ;
V_431 . V_2 . V_20 = V_10 -> V_20 ;
V_431 . V_2 . V_106 = V_10 -> V_106 ;
V_431 . V_2 . V_128 = V_10 -> V_128 ;
V_431 . V_2 . V_16 = V_10 -> V_16 ;
V_431 . V_2 . V_428 = V_10 -> V_428 ;
V_431 . V_2 . type = V_10 -> type ;
V_431 . V_2 . F_3 = V_10 -> F_3 ;
V_431 . V_2 . F_5 = V_10 -> F_5 ;
V_431 . V_2 . V_28 = V_10 -> V_28 ;
V_431 . V_2 . V_432 = V_10 -> V_432 ;
V_431 . V_2 . V_346 = V_10 -> V_346 ;
V_431 . V_2 . V_351 = V_10 -> V_351 ;
V_431 . V_2 . V_44 = & V_44 -> V_44 ;
V_431 . V_2 . V_246 |= V_404 ;
V_216 = F_228 ( & V_431 ) ;
if ( V_216 < 0 ) {
F_229 ( & V_44 -> V_44 , L_30
L_31 , V_135 ,
V_10 -> V_17 , ( unsigned long long ) V_10 -> V_128 ,
V_10 -> V_149 , V_216 ) ;
}
}
return 0 ;
}
static int F_230 ( struct V_429 * V_44 )
{
int V_135 ;
for ( V_135 = 0 ; V_135 < V_405 ; V_135 ++ ) {
struct V_5 * V_6 = & V_401 [ V_135 ] ;
if ( V_6 -> V_2 . V_44 == & V_44 -> V_44 )
F_231 ( V_135 ) ;
}
return 0 ;
}
static int F_232 ( struct V_429 * V_44 , T_8 V_190 )
{
int V_135 ;
for ( V_135 = 0 ; V_135 < V_406 ; V_135 ++ ) {
struct V_5 * V_6 = & V_401 [ V_135 ] ;
if ( V_6 -> V_2 . type != V_132 && V_6 -> V_2 . V_44 == & V_44 -> V_44 )
F_223 ( & V_3 , & V_6 -> V_2 ) ;
}
return 0 ;
}
static int F_233 ( struct V_429 * V_44 )
{
int V_135 ;
for ( V_135 = 0 ; V_135 < V_406 ; V_135 ++ ) {
struct V_5 * V_6 = & V_401 [ V_135 ] ;
if ( V_6 -> V_2 . type != V_132 && V_6 -> V_2 . V_44 == & V_44 -> V_44 )
F_224 ( V_135 ) ;
}
return 0 ;
}
static struct V_5 * F_234 ( struct V_1 * V_2 )
{
int V_135 ;
for ( V_135 = 0 ; V_135 < V_405 ; V_135 ++ )
if ( F_220 ( & V_401 [ V_135 ] . V_2 , V_2 ) )
return & V_401 [ V_135 ] ;
V_135 = V_2 -> line ;
if ( V_135 < V_405 && V_401 [ V_135 ] . V_2 . type == V_132 &&
V_401 [ V_135 ] . V_2 . V_17 == 0 )
return & V_401 [ V_135 ] ;
for ( V_135 = 0 ; V_135 < V_405 ; V_135 ++ )
if ( V_401 [ V_135 ] . V_2 . type == V_132 &&
V_401 [ V_135 ] . V_2 . V_17 == 0 )
return & V_401 [ V_135 ] ;
for ( V_135 = 0 ; V_135 < V_405 ; V_135 ++ )
if ( V_401 [ V_135 ] . V_2 . type == V_132 )
return & V_401 [ V_135 ] ;
return NULL ;
}
int F_228 ( struct V_5 * V_6 )
{
struct V_5 * V_431 ;
int V_216 = - V_433 ;
if ( V_6 -> V_2 . V_63 == 0 )
return - V_360 ;
F_115 ( & V_434 ) ;
V_431 = F_234 ( & V_6 -> V_2 ) ;
if ( V_431 && V_431 -> V_2 . type != V_280 ) {
if ( V_431 -> V_2 . V_44 )
F_235 ( & V_3 , & V_431 -> V_2 ) ;
V_431 -> V_2 . V_17 = V_6 -> V_2 . V_17 ;
V_431 -> V_2 . V_14 = V_6 -> V_2 . V_14 ;
V_431 -> V_2 . V_149 = V_6 -> V_2 . V_149 ;
V_431 -> V_2 . V_246 = V_6 -> V_2 . V_246 ;
V_431 -> V_2 . V_63 = V_6 -> V_2 . V_63 ;
V_431 -> V_2 . V_138 = V_6 -> V_2 . V_138 ;
V_431 -> V_2 . V_13 = V_6 -> V_2 . V_13 ;
V_431 -> V_2 . V_20 = V_6 -> V_2 . V_20 ;
V_431 -> V_2 . V_106 = V_6 -> V_2 . V_106 | V_435 ;
V_431 -> V_93 = V_6 -> V_93 ;
V_431 -> V_2 . V_128 = V_6 -> V_2 . V_128 ;
V_431 -> V_2 . V_428 = V_6 -> V_2 . V_428 ;
V_431 -> V_2 . V_138 = V_6 -> V_2 . V_138 ;
V_431 -> V_141 = V_6 -> V_141 ;
V_431 -> V_36 = V_6 -> V_36 ;
V_431 -> V_394 = V_6 -> V_394 ;
V_431 -> V_399 = V_6 -> V_399 ;
V_431 -> V_2 . V_164 = V_6 -> V_2 . V_164 ;
V_431 -> V_2 . V_165 = V_6 -> V_2 . V_165 ;
if ( V_431 -> V_2 . V_138 && ! V_431 -> V_141 )
V_431 -> V_141 = V_431 -> V_2 . V_138 ;
if ( V_6 -> V_2 . V_44 )
V_431 -> V_2 . V_44 = V_6 -> V_2 . V_44 ;
if ( V_6 -> V_2 . V_106 & V_417 )
F_205 ( V_431 , V_6 -> V_2 . type ) ;
F_26 ( & V_431 -> V_2 ) ;
if ( V_6 -> V_2 . F_3 )
V_431 -> V_2 . F_3 = V_6 -> V_2 . F_3 ;
if ( V_6 -> V_2 . F_5 )
V_431 -> V_2 . F_5 = V_6 -> V_2 . F_5 ;
if ( V_6 -> V_2 . V_28 )
V_431 -> V_2 . V_28 = V_6 -> V_2 . V_28 ;
if ( V_6 -> V_2 . V_346 )
V_431 -> V_2 . V_346 = V_6 -> V_2 . V_346 ;
if ( V_6 -> V_2 . V_300 )
V_431 -> V_2 . V_300 = V_6 -> V_2 . V_300 ;
if ( V_6 -> V_2 . V_301 )
V_431 -> V_2 . V_301 = V_6 -> V_2 . V_301 ;
if ( V_6 -> V_2 . V_351 )
V_431 -> V_2 . V_351 = V_6 -> V_2 . V_351 ;
if ( V_6 -> V_2 . V_432 )
V_431 -> V_2 . V_432 = V_6 -> V_2 . V_432 ;
if ( V_6 -> V_18 )
V_431 -> V_18 = V_6 -> V_18 ;
if ( V_6 -> V_19 )
V_431 -> V_19 = V_6 -> V_19 ;
if ( V_6 -> V_158 )
V_431 -> V_158 = V_6 -> V_158 ;
if ( V_402 != NULL )
V_402 ( 0 , & V_431 -> V_2 ,
& V_431 -> V_36 ) ;
V_216 = F_207 ( & V_3 , & V_431 -> V_2 ) ;
if ( V_216 == 0 )
V_216 = V_431 -> V_2 . line ;
}
F_119 ( & V_434 ) ;
return V_216 ;
}
void F_231 ( int line )
{
struct V_5 * V_431 = & V_401 [ line ] ;
F_115 ( & V_434 ) ;
F_235 ( & V_3 , & V_431 -> V_2 ) ;
if ( V_436 ) {
V_431 -> V_2 . V_106 &= ~ V_435 ;
V_431 -> V_2 . type = V_132 ;
V_431 -> V_2 . V_44 = & V_436 -> V_44 ;
V_431 -> V_36 = V_139 [ V_431 -> V_2 . type ] . V_106 ;
F_207 ( & V_3 , & V_431 -> V_2 ) ;
} else {
V_431 -> V_2 . V_44 = NULL ;
}
F_119 ( & V_434 ) ;
}
static int T_7 F_236 ( void )
{
int V_216 ;
F_202 () ;
F_65 ( V_283 L_32
L_33 , V_405 ,
V_410 ? L_34 : L_35 ) ;
#ifdef F_237
V_216 = F_238 ( & V_3 , V_406 ) ;
#else
V_3 . V_437 = V_406 ;
V_216 = F_239 ( & V_3 ) ;
#endif
if ( V_216 )
goto V_51;
V_216 = F_240 () ;
if ( V_216 )
goto V_438;
V_436 = F_241 ( L_36 ,
V_439 ) ;
if ( ! V_436 ) {
V_216 = - V_245 ;
goto V_440;
}
V_216 = F_242 ( V_436 ) ;
if ( V_216 )
goto V_441;
F_206 ( & V_3 , & V_436 -> V_44 ) ;
V_216 = F_243 ( & V_442 ) ;
if ( V_216 == 0 )
goto V_51;
F_244 ( V_436 ) ;
V_441:
F_245 ( V_436 ) ;
V_440:
F_246 () ;
V_438:
#ifdef F_237
F_247 ( & V_3 , V_406 ) ;
#else
F_248 ( & V_3 ) ;
#endif
V_51:
return V_216 ;
}
static void T_9 F_249 ( void )
{
struct V_429 * V_443 = V_436 ;
V_436 = NULL ;
F_250 ( & V_442 ) ;
F_251 ( V_443 ) ;
F_246 () ;
#ifdef F_237
F_247 ( & V_3 , V_406 ) ;
#else
F_248 ( & V_3 ) ;
#endif
}
static void T_10 F_252 ( void )
{
#undef V_444
#define V_444 "8250_core."
F_253 ( V_410 , & V_445 , & V_410 , 0644 ) ;
F_253 ( V_405 , & V_445 , & V_405 , 0644 ) ;
F_253 ( V_296 , & V_445 , & V_296 , 0644 ) ;
#ifdef F_64
F_254 ( V_444 , V_137 ,
& V_446 , . V_447 = & V_448 ,
0444 , - 1 , 0 ) ;
#endif
}
