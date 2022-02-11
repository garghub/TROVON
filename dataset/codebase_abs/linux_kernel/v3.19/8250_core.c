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
void F_34 ( struct V_5 * V_10 )
{
if ( ! ( V_10 -> V_36 & V_43 ) )
return;
F_35 ( V_10 -> V_2 . V_44 ) ;
}
void F_36 ( struct V_5 * V_10 )
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
unsigned char V_48 = 0 , V_49 = 0 ;
F_34 ( V_10 ) ;
if ( ( V_10 -> V_2 . type == V_50 ) ||
( V_10 -> V_2 . type == V_51 ) ) {
F_5 ( V_10 , V_52 , V_47 ? 0xff : 0 ) ;
goto V_53;
}
if ( V_10 -> V_36 & V_54 ) {
if ( V_10 -> V_36 & V_55 ) {
V_48 = F_3 ( V_10 , V_30 ) ;
V_49 = F_3 ( V_10 , V_56 ) ;
F_5 ( V_10 , V_30 , V_57 ) ;
F_5 ( V_10 , V_56 , V_58 ) ;
F_5 ( V_10 , V_30 , 0 ) ;
}
F_5 ( V_10 , V_59 , V_47 ? V_60 : 0 ) ;
if ( V_10 -> V_36 & V_55 ) {
F_5 ( V_10 , V_30 , V_57 ) ;
F_5 ( V_10 , V_56 , V_49 ) ;
F_5 ( V_10 , V_30 , V_48 ) ;
}
}
V_53:
F_36 ( V_10 ) ;
}
static int F_43 ( struct V_5 * V_6 )
{
unsigned char V_61 ;
int V_62 ;
V_61 = F_3 ( V_6 , V_63 ) ;
V_62 = V_61 & V_64 ;
if ( ! V_62 ) {
F_5 ( V_6 , V_63 , V_61 | V_64 ) ;
V_61 = F_3 ( V_6 , V_63 ) ;
V_62 = V_61 & V_64 ;
}
if ( V_62 )
V_6 -> V_2 . V_65 = V_66 * 16 ;
return V_62 ;
}
static void F_44 ( struct V_5 * V_6 )
{
if ( V_6 -> V_2 . type == V_67 ) {
if ( V_6 -> V_2 . V_65 != V_66 * 16 ) {
F_45 ( & V_6 -> V_2 . V_68 ) ;
F_43 ( V_6 ) ;
F_46 ( & V_6 -> V_2 . V_68 ) ;
}
if ( V_6 -> V_2 . V_65 == V_66 * 16 )
F_5 ( V_6 , V_69 , 0 ) ;
}
}
static void F_47 ( struct V_5 * V_6 )
{
unsigned char V_61 ;
int V_62 ;
if ( V_6 -> V_2 . type == V_67 &&
V_6 -> V_2 . V_65 == V_66 * 16 ) {
F_45 ( & V_6 -> V_2 . V_68 ) ;
V_61 = F_3 ( V_6 , V_63 ) ;
V_62 = ! ( V_61 & V_64 ) ;
if ( ! V_62 ) {
F_5 ( V_6 , V_63 , V_61 & ~ V_64 ) ;
V_61 = F_3 ( V_6 , V_63 ) ;
V_62 = ! ( V_61 & V_64 ) ;
}
if ( V_62 )
V_6 -> V_2 . V_65 = V_70 * 16 ;
F_46 ( & V_6 -> V_2 . V_68 ) ;
}
}
static int F_48 ( struct V_5 * V_6 )
{
unsigned char V_71 , V_72 , V_73 ;
unsigned short V_74 ;
int V_75 ;
V_73 = F_3 ( V_6 , V_30 ) ;
F_5 ( V_6 , V_30 , 0 ) ;
V_71 = F_3 ( V_6 , V_38 ) ;
V_72 = F_3 ( V_6 , V_76 ) ;
F_5 ( V_6 , V_38 , V_39 |
V_40 | V_41 ) ;
F_5 ( V_6 , V_76 , V_77 ) ;
F_5 ( V_6 , V_30 , V_78 ) ;
V_74 = F_49 ( V_6 ) ;
F_50 ( V_6 , 0x0001 ) ;
F_5 ( V_6 , V_30 , 0x03 ) ;
for ( V_75 = 0 ; V_75 < 256 ; V_75 ++ )
F_5 ( V_6 , V_79 , V_75 ) ;
F_51 ( 20 ) ;
for ( V_75 = 0 ; ( F_3 ( V_6 , V_80 ) & V_81 ) &&
( V_75 < 256 ) ; V_75 ++ )
F_3 ( V_6 , V_82 ) ;
F_5 ( V_6 , V_38 , V_71 ) ;
F_5 ( V_6 , V_76 , V_72 ) ;
F_5 ( V_6 , V_30 , V_78 ) ;
F_50 ( V_6 , V_74 ) ;
F_5 ( V_6 , V_30 , V_73 ) ;
return V_75 ;
}
static unsigned int F_52 ( struct V_5 * V_10 )
{
unsigned char V_83 , V_84 , V_73 ;
unsigned int V_85 ;
V_73 = F_3 ( V_10 , V_30 ) ;
F_5 ( V_10 , V_30 , V_78 ) ;
V_83 = F_3 ( V_10 , V_7 ) ;
V_84 = F_3 ( V_10 , V_8 ) ;
F_5 ( V_10 , V_7 , 0 ) ;
F_5 ( V_10 , V_8 , 0 ) ;
V_85 = F_3 ( V_10 , V_7 ) | F_3 ( V_10 , V_8 ) << 8 ;
F_5 ( V_10 , V_7 , V_83 ) ;
F_5 ( V_10 , V_8 , V_84 ) ;
F_5 ( V_10 , V_30 , V_73 ) ;
return V_85 ;
}
static void F_53 ( struct V_5 * V_6 )
{
unsigned int V_86 , V_87 , V_88 , V_89 ;
V_6 -> V_36 |= V_55 | V_54 ;
V_6 -> V_34 = 0 ;
F_5 ( V_6 , V_30 , V_57 ) ;
F_5 ( V_6 , V_56 , V_58 ) ;
F_5 ( V_6 , V_30 , 0x00 ) ;
V_86 = F_31 ( V_6 , V_90 ) ;
V_87 = F_31 ( V_6 , V_91 ) ;
V_88 = F_31 ( V_6 , V_92 ) ;
V_89 = F_31 ( V_6 , V_93 ) ;
F_54 ( L_1 , V_86 , V_87 , V_88 , V_89 ) ;
if ( V_86 == 0x16 && V_87 == 0xC9 &&
( V_88 == 0x50 || V_88 == 0x52 || V_88 == 0x54 ) ) {
V_6 -> V_2 . type = V_94 ;
if ( V_88 == 0x52 && V_89 == 0x01 )
V_6 -> V_95 |= V_96 ;
return;
}
V_86 = F_52 ( V_6 ) ;
F_54 ( L_2 , V_86 ) ;
V_87 = V_86 >> 8 ;
if ( V_87 == 0x10 || V_87 == 0x12 || V_87 == 0x14 ) {
V_6 -> V_2 . type = V_97 ;
return;
}
if ( F_48 ( V_6 ) == 64 )
V_6 -> V_2 . type = V_98 ;
else
V_6 -> V_2 . type = V_99 ;
}
static void F_55 ( struct V_5 * V_6 )
{
unsigned char V_100 , V_101 , V_102 ;
V_6 -> V_2 . type = V_103 ;
V_100 = F_3 ( V_6 , V_31 ) ;
F_5 ( V_6 , V_31 , 0xa5 ) ;
V_101 = F_3 ( V_6 , V_31 ) ;
F_5 ( V_6 , V_31 , 0x5a ) ;
V_102 = F_3 ( V_6 , V_31 ) ;
F_5 ( V_6 , V_31 , V_100 ) ;
if ( V_101 == 0xa5 && V_102 == 0x5a )
V_6 -> V_2 . type = V_104 ;
}
static int F_56 ( struct V_5 * V_6 )
{
if ( F_52 ( V_6 ) == 0x0201 && F_48 ( V_6 ) == 16 )
return 1 ;
return 0 ;
}
static inline int F_57 ( struct V_5 * V_6 )
{
unsigned char V_105 ;
V_105 = F_3 ( V_6 , 0x04 ) ;
#define F_58 ( T_1 ) ((x) & 0x30)
if ( F_58 ( V_105 ) == 0x10 ) {
return 0 ;
} else {
V_105 &= ~ 0xB0 ;
V_105 |= 0x10 ;
F_5 ( V_6 , 0x04 , V_105 ) ;
}
return 1 ;
}
static void F_59 ( struct V_5 * V_6 )
{
unsigned char V_101 , V_102 ;
unsigned int V_106 ;
V_6 -> V_2 . type = V_107 ;
V_6 -> V_36 |= V_37 ;
if ( V_6 -> V_2 . V_108 & V_109 ) {
V_101 = F_3 ( V_6 , V_110 ) ;
if ( V_101 == 0x82 || V_101 == 0x84 || V_101 == 0x88 ) {
F_54 ( L_3 ) ;
V_6 -> V_2 . type = V_50 ;
V_6 -> V_36 |= V_111 | V_55 |
V_54 ;
return;
}
}
F_5 ( V_6 , V_30 , V_78 ) ;
if ( F_3 ( V_6 , V_56 ) == 0 ) {
F_5 ( V_6 , V_56 , 0xA8 ) ;
if ( F_3 ( V_6 , V_56 ) != 0 ) {
F_54 ( L_4 ) ;
V_6 -> V_2 . type = V_112 ;
V_6 -> V_36 |= V_55 | V_54 ;
} else {
F_54 ( L_5 ) ;
}
F_5 ( V_6 , V_56 , 0 ) ;
return;
}
F_5 ( V_6 , V_30 , V_57 ) ;
if ( F_3 ( V_6 , V_56 ) == 0 && ! F_56 ( V_6 ) ) {
F_54 ( L_6 ) ;
F_53 ( V_6 ) ;
return;
}
F_5 ( V_6 , V_30 , 0 ) ;
V_101 = F_3 ( V_6 , V_76 ) ;
F_5 ( V_6 , V_30 , 0xE0 ) ;
V_102 = F_3 ( V_6 , 0x02 ) ;
if ( ! ( ( V_102 ^ V_101 ) & V_77 ) ) {
F_5 ( V_6 , V_30 , 0 ) ;
F_5 ( V_6 , V_76 , V_101 ^ V_77 ) ;
F_5 ( V_6 , V_30 , 0xE0 ) ;
V_102 = F_3 ( V_6 , 0x02 ) ;
F_5 ( V_6 , V_30 , 0 ) ;
F_5 ( V_6 , V_76 , V_101 ) ;
if ( ( V_102 ^ V_101 ) & V_77 ) {
unsigned short V_113 ;
F_5 ( V_6 , V_30 , 0xE0 ) ;
V_113 = F_49 ( V_6 ) ;
V_113 <<= 3 ;
if ( F_57 ( V_6 ) )
F_50 ( V_6 , V_113 ) ;
F_5 ( V_6 , V_30 , 0 ) ;
V_6 -> V_2 . V_65 = 921600 * 16 ;
V_6 -> V_2 . type = V_114 ;
V_6 -> V_36 |= V_115 ;
return;
}
}
F_5 ( V_6 , V_30 , 0 ) ;
F_5 ( V_6 , V_38 , V_39 | V_116 ) ;
V_101 = F_3 ( V_6 , V_117 ) >> 5 ;
F_5 ( V_6 , V_38 , V_39 ) ;
F_5 ( V_6 , V_30 , V_78 ) ;
F_5 ( V_6 , V_38 , V_39 | V_116 ) ;
V_102 = F_3 ( V_6 , V_117 ) >> 5 ;
F_5 ( V_6 , V_38 , V_39 ) ;
F_5 ( V_6 , V_30 , 0 ) ;
F_54 ( L_7 , V_101 , V_102 ) ;
if ( V_101 == 6 && V_102 == 7 ) {
V_6 -> V_2 . type = V_118 ;
V_6 -> V_36 |= V_111 | V_54 ;
return;
}
V_106 = F_3 ( V_6 , V_59 ) ;
F_5 ( V_6 , V_59 , V_106 & ~ V_119 ) ;
if ( ! ( F_3 ( V_6 , V_59 ) & V_119 ) ) {
F_5 ( V_6 , V_59 , V_106 | V_119 ) ;
if ( F_3 ( V_6 , V_59 ) & V_119 ) {
F_54 ( L_8 ) ;
V_6 -> V_2 . type = V_120 ;
V_6 -> V_36 |= V_121 | V_122 ;
return;
}
} else {
F_54 ( L_9 ) ;
}
F_5 ( V_6 , V_59 , V_106 ) ;
if ( V_6 -> V_2 . V_108 & V_109 ) {
F_54 ( L_10 ) ;
V_6 -> V_2 . type = V_51 ;
V_6 -> V_36 |= V_111 | V_55 |
V_54 ;
return;
}
if ( V_6 -> V_2 . type == V_107 && F_48 ( V_6 ) == 64 ) {
V_6 -> V_2 . type = V_123 ;
V_6 -> V_36 |= V_111 ;
}
}
static void F_60 ( struct V_5 * V_6 , unsigned int V_124 )
{
unsigned char V_101 , V_100 , V_125 , V_126 ;
unsigned char V_127 , V_128 ;
struct V_1 * V_2 = & V_6 -> V_2 ;
unsigned long V_108 ;
unsigned int V_129 ;
if ( ! V_2 -> V_17 && ! V_2 -> V_130 && ! V_2 -> V_14 )
return;
F_54 ( L_11 ,
F_1 ( V_2 ) , V_2 -> V_17 , V_2 -> V_14 ) ;
F_61 ( & V_2 -> V_68 , V_108 ) ;
V_6 -> V_36 = 0 ;
V_6 -> V_95 = 0 ;
if ( ! ( V_2 -> V_108 & V_131 ) ) {
V_100 = F_3 ( V_6 , V_59 ) ;
F_5 ( V_6 , V_59 , 0 ) ;
#ifdef F_62
F_13 ( 0xff , 0x080 ) ;
#endif
V_125 = F_3 ( V_6 , V_59 ) & 0x0f ;
F_5 ( V_6 , V_59 , 0x0F ) ;
#ifdef F_62
F_13 ( 0 , 0x080 ) ;
#endif
V_126 = F_3 ( V_6 , V_59 ) & 0x0f ;
F_5 ( V_6 , V_59 , V_100 ) ;
if ( V_125 != 0 || V_126 != 0x0F ) {
F_63 ( & V_2 -> V_68 , V_108 ) ;
F_54 ( L_12 ,
V_125 , V_126 ) ;
goto V_53;
}
}
V_128 = F_3 ( V_6 , V_76 ) ;
V_127 = F_3 ( V_6 , V_30 ) ;
if ( ! ( V_2 -> V_108 & V_132 ) ) {
F_5 ( V_6 , V_76 , V_77 | 0x0A ) ;
V_101 = F_3 ( V_6 , V_133 ) & 0xF0 ;
F_5 ( V_6 , V_76 , V_128 ) ;
if ( V_101 != 0x90 ) {
F_63 ( & V_2 -> V_68 , V_108 ) ;
F_54 ( L_13 ,
V_101 ) ;
goto V_53;
}
}
F_5 ( V_6 , V_30 , V_57 ) ;
F_5 ( V_6 , V_56 , 0 ) ;
F_5 ( V_6 , V_30 , 0 ) ;
F_5 ( V_6 , V_38 , V_39 ) ;
V_100 = F_3 ( V_6 , V_117 ) >> 6 ;
switch ( V_100 ) {
case 0 :
F_55 ( V_6 ) ;
break;
case 1 :
V_2 -> type = V_134 ;
break;
case 2 :
V_2 -> type = V_135 ;
break;
case 3 :
F_59 ( V_6 ) ;
break;
}
#ifdef F_64
if ( V_2 -> type == V_107 && V_124 & V_136 ) {
int V_137 ;
for ( V_137 = 0 ; V_137 < V_138 ; ++ V_137 ) {
if ( V_139 [ V_137 ] == V_2 -> V_17 && F_43 ( V_6 ) ) {
V_2 -> type = V_67 ;
break;
}
}
}
#endif
F_5 ( V_6 , V_30 , V_127 ) ;
V_2 -> V_140 = V_141 [ V_6 -> V_2 . type ] . V_142 ;
V_129 = V_6 -> V_36 ;
V_6 -> V_36 = V_141 [ V_2 -> type ] . V_108 ;
V_6 -> V_143 = V_141 [ V_2 -> type ] . V_143 ;
if ( V_2 -> type == V_134 )
goto V_144;
#ifdef F_64
if ( V_2 -> type == V_67 )
F_5 ( V_6 , V_69 , 0 ) ;
#endif
F_5 ( V_6 , V_76 , V_128 ) ;
F_32 ( V_6 ) ;
F_3 ( V_6 , V_82 ) ;
if ( V_6 -> V_36 & V_121 )
F_5 ( V_6 , V_59 , V_119 ) ;
else
F_5 ( V_6 , V_59 , 0 ) ;
V_144:
F_63 ( & V_2 -> V_68 , V_108 ) ;
if ( V_6 -> V_36 != V_129 ) {
F_65 ( V_145
L_14 ,
F_1 ( V_2 ) , V_129 ,
V_6 -> V_36 ) ;
}
V_53:
F_54 ( L_15 , V_100 ) ;
F_54 ( L_16 , V_141 [ V_2 -> type ] . V_146 ) ;
}
static void F_66 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = & V_6 -> V_2 ;
unsigned char V_128 , V_147 ;
unsigned char V_148 = 0 ;
unsigned int V_149 = 0 ;
unsigned long V_150 ;
int V_151 ;
if ( V_2 -> V_108 & V_152 ) {
V_149 = ( V_2 -> V_17 & 0xfe0 ) | 0x1f ;
V_148 = F_67 ( V_149 ) ;
F_68 ( 0x80 , V_149 ) ;
F_67 ( V_149 ) ;
}
F_69 ( F_70 () ) ;
V_128 = F_3 ( V_6 , V_76 ) ;
V_147 = F_3 ( V_6 , V_59 ) ;
F_5 ( V_6 , V_76 , V_153 | V_154 ) ;
V_150 = F_70 () ;
F_5 ( V_6 , V_76 , 0 ) ;
F_71 ( 10 ) ;
if ( V_2 -> V_108 & V_152 ) {
F_5 ( V_6 , V_76 ,
V_155 | V_156 ) ;
} else {
F_5 ( V_6 , V_76 ,
V_155 | V_156 | V_154 ) ;
}
F_5 ( V_6 , V_59 , 0x0f ) ;
F_3 ( V_6 , V_80 ) ;
F_3 ( V_6 , V_82 ) ;
F_3 ( V_6 , V_117 ) ;
F_3 ( V_6 , V_133 ) ;
F_5 ( V_6 , V_79 , 0xFF ) ;
F_71 ( 20 ) ;
V_151 = F_69 ( V_150 ) ;
F_5 ( V_6 , V_76 , V_128 ) ;
F_5 ( V_6 , V_59 , V_147 ) ;
if ( V_2 -> V_108 & V_152 )
F_68 ( V_148 , V_149 ) ;
V_2 -> V_151 = ( V_151 > 0 ) ? V_151 : 0 ;
}
static inline void F_72 ( struct V_5 * V_10 )
{
if ( V_10 -> V_157 & V_158 ) {
V_10 -> V_157 &= ~ V_158 ;
F_5 ( V_10 , V_59 , V_10 -> V_157 ) ;
F_41 ( V_10 ) ;
}
}
static void F_73 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_27 ( V_2 ) ;
F_34 ( V_6 ) ;
F_72 ( V_6 ) ;
if ( V_2 -> type == V_94 ) {
V_6 -> V_34 |= V_159 ;
F_30 ( V_6 , V_33 , V_6 -> V_34 ) ;
}
F_36 ( V_6 ) ;
}
static void F_74 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_27 ( V_2 ) ;
F_39 ( V_6 ) ;
if ( V_6 -> V_160 && ! V_6 -> V_160 -> V_161 ( V_6 ) ) {
return;
} else if ( ! ( V_6 -> V_157 & V_158 ) ) {
V_6 -> V_157 |= V_158 ;
F_75 ( V_2 , V_59 , V_6 -> V_157 ) ;
if ( V_6 -> V_95 & V_162 ) {
unsigned char V_163 ;
V_163 = F_3 ( V_6 , V_80 ) ;
V_6 -> V_164 |= V_163 & V_165 ;
if ( V_163 & V_166 )
F_76 ( V_6 ) ;
}
}
if ( V_2 -> type == V_94 && V_6 -> V_34 & V_159 ) {
V_6 -> V_34 &= ~ V_159 ;
F_30 ( V_6 , V_33 , V_6 -> V_34 ) ;
}
}
static void F_77 ( struct V_1 * V_2 )
{
V_2 -> V_167 ( V_2 ) ;
}
static void F_78 ( struct V_1 * V_2 )
{
V_2 -> V_168 ( V_2 ) ;
}
static void F_79 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_27 ( V_2 ) ;
F_34 ( V_6 ) ;
V_6 -> V_157 &= ~ ( V_169 | V_170 ) ;
V_6 -> V_2 . V_171 &= ~ V_81 ;
F_75 ( V_2 , V_59 , V_6 -> V_157 ) ;
F_36 ( V_6 ) ;
}
static void F_80 ( struct V_1 * V_2 )
{
struct V_5 * V_6 =
F_81 ( V_2 , struct V_5 , V_2 ) ;
if ( V_6 -> V_95 & V_172 )
return;
V_6 -> V_157 &= ~ V_173 ;
F_75 ( V_2 , V_59 , V_6 -> V_157 ) ;
}
static void F_82 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_27 ( V_2 ) ;
if ( V_6 -> V_95 & V_172 )
return;
V_6 -> V_157 |= V_173 ;
F_34 ( V_6 ) ;
F_75 ( V_2 , V_59 , V_6 -> V_157 ) ;
F_36 ( V_6 ) ;
}
unsigned char
F_83 ( struct V_5 * V_6 , unsigned char V_163 )
{
struct V_1 * V_2 = & V_6 -> V_2 ;
unsigned char V_174 ;
int V_175 = 256 ;
char V_176 ;
do {
if ( F_84 ( V_163 & V_81 ) )
V_174 = F_3 ( V_6 , V_82 ) ;
else
V_174 = 0 ;
V_176 = V_177 ;
V_2 -> V_178 . V_179 ++ ;
V_163 |= V_6 -> V_164 ;
V_6 -> V_164 = 0 ;
if ( F_85 ( V_163 & V_180 ) ) {
if ( V_163 & V_181 ) {
V_163 &= ~ ( V_182 | V_183 ) ;
V_2 -> V_178 . V_184 ++ ;
if ( F_86 ( V_2 ) )
goto V_185;
} else if ( V_163 & V_183 )
V_2 -> V_178 . V_186 ++ ;
else if ( V_163 & V_182 )
V_2 -> V_178 . V_187 ++ ;
if ( V_163 & V_188 )
V_2 -> V_178 . V_189 ++ ;
V_163 &= V_2 -> V_171 ;
if ( V_163 & V_181 ) {
F_87 ( L_17 ) ;
V_176 = V_190 ;
} else if ( V_163 & V_183 )
V_176 = V_191 ;
else if ( V_163 & V_182 )
V_176 = V_192 ;
}
if ( F_88 ( V_2 , V_174 ) )
goto V_185;
F_89 ( V_2 , V_163 , V_188 , V_174 , V_176 ) ;
V_185:
V_163 = F_3 ( V_6 , V_80 ) ;
} while ( ( V_163 & ( V_81 | V_181 ) ) && ( -- V_175 > 0 ) );
F_90 ( & V_2 -> V_68 ) ;
F_91 ( & V_2 -> V_193 -> V_2 ) ;
F_92 ( & V_2 -> V_68 ) ;
return V_163 ;
}
void F_76 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = & V_6 -> V_2 ;
struct V_194 * V_195 = & V_2 -> V_193 -> V_195 ;
int V_75 ;
if ( V_2 -> V_196 ) {
F_5 ( V_6 , V_79 , V_2 -> V_196 ) ;
V_2 -> V_178 . V_197 ++ ;
V_2 -> V_196 = 0 ;
return;
}
if ( F_93 ( V_2 ) ) {
F_73 ( V_2 ) ;
return;
}
if ( F_94 ( V_195 ) ) {
F_72 ( V_6 ) ;
return;
}
V_75 = V_6 -> V_143 ;
do {
F_5 ( V_6 , V_79 , V_195 -> V_198 [ V_195 -> V_199 ] ) ;
V_195 -> V_199 = ( V_195 -> V_199 + 1 ) & ( V_200 - 1 ) ;
V_2 -> V_178 . V_197 ++ ;
if ( F_94 ( V_195 ) )
break;
if ( V_6 -> V_36 & V_201 ) {
if ( ( F_95 ( V_2 , V_80 ) & V_202 ) !=
V_202 )
break;
}
} while ( -- V_75 > 0 );
if ( F_96 ( V_195 ) < V_203 )
F_97 ( V_2 ) ;
F_87 ( L_18 ) ;
if ( F_94 ( V_195 ) && ! ( V_6 -> V_36 & V_43 ) )
F_72 ( V_6 ) ;
}
unsigned int F_98 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = & V_6 -> V_2 ;
unsigned int V_105 = F_3 ( V_6 , V_133 ) ;
V_105 |= V_6 -> V_204 ;
V_6 -> V_204 = 0 ;
if ( V_105 & V_205 && V_6 -> V_157 & V_173 &&
V_2 -> V_193 != NULL ) {
if ( V_105 & V_206 )
V_2 -> V_178 . V_207 ++ ;
if ( V_105 & V_208 )
V_2 -> V_178 . V_209 ++ ;
if ( V_105 & V_210 )
F_99 ( V_2 , V_105 & V_211 ) ;
if ( V_105 & V_212 )
F_100 ( V_2 , V_105 & V_213 ) ;
F_101 ( & V_2 -> V_193 -> V_2 . V_214 ) ;
}
return V_105 ;
}
int F_102 ( struct V_1 * V_2 , unsigned int V_215 )
{
unsigned char V_105 ;
unsigned long V_108 ;
struct V_5 * V_6 = F_27 ( V_2 ) ;
int V_216 = 0 ;
if ( V_215 & V_217 )
return 0 ;
F_61 ( & V_2 -> V_68 , V_108 ) ;
V_105 = F_95 ( V_2 , V_80 ) ;
F_87 ( L_19 , V_105 ) ;
if ( V_105 & ( V_81 | V_181 ) ) {
if ( V_6 -> V_160 )
V_216 = V_6 -> V_160 -> V_218 ( V_6 , V_215 ) ;
if ( ! V_6 -> V_160 || V_216 )
V_105 = F_83 ( V_6 , V_105 ) ;
}
F_98 ( V_6 ) ;
if ( ( ! V_6 -> V_160 || ( V_6 -> V_160 && V_6 -> V_160 -> V_219 ) ) &&
( V_105 & V_220 ) )
F_76 ( V_6 ) ;
F_63 ( & V_2 -> V_68 , V_108 ) ;
return 1 ;
}
static int V_29 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_27 ( V_2 ) ;
unsigned int V_215 ;
int V_221 ;
F_34 ( V_6 ) ;
V_215 = F_95 ( V_2 , V_117 ) ;
V_221 = F_102 ( V_2 , V_215 ) ;
F_36 ( V_6 ) ;
return V_221 ;
}
static int F_103 ( struct V_1 * V_2 )
{
unsigned char V_222 , V_223 , V_224 , V_225 ;
unsigned int V_215 = F_95 ( V_2 , V_117 ) ;
int V_221 ;
V_221 = F_102 ( V_2 , V_215 ) ;
if ( ( V_2 -> type == V_50 ) ||
( V_2 -> type == V_51 ) ) {
V_222 = F_95 ( V_2 , 0x80 ) ;
V_223 = F_95 ( V_2 , 0x81 ) ;
V_224 = F_95 ( V_2 , 0x82 ) ;
V_225 = F_95 ( V_2 , 0x83 ) ;
}
return V_221 ;
}
static T_2 F_104 ( int V_151 , void * V_226 )
{
struct V_227 * V_137 = V_226 ;
struct V_228 * V_229 , * V_230 = NULL ;
int V_231 = 0 , V_232 = 0 ;
F_87 ( L_20 , V_151 ) ;
F_92 ( & V_137 -> V_68 ) ;
V_229 = V_137 -> V_233 ;
do {
struct V_5 * V_6 ;
struct V_1 * V_2 ;
V_6 = F_105 ( V_229 , struct V_5 , V_234 ) ;
V_2 = & V_6 -> V_2 ;
if ( V_2 -> V_28 ( V_2 ) ) {
V_232 = 1 ;
V_230 = NULL ;
} else if ( V_230 == NULL )
V_230 = V_229 ;
V_229 = V_229 -> V_235 ;
if ( V_229 == V_137 -> V_233 && V_231 ++ > V_236 ) {
F_106 ( V_237
L_21 , V_151 ) ;
break;
}
} while ( V_229 != V_230 );
F_90 ( & V_137 -> V_68 ) ;
F_87 ( L_22 ) ;
return F_107 ( V_232 ) ;
}
static void F_108 ( struct V_227 * V_137 , struct V_5 * V_6 )
{
F_45 ( & V_137 -> V_68 ) ;
if ( ! F_109 ( V_137 -> V_233 ) ) {
if ( V_137 -> V_233 == & V_6 -> V_234 )
V_137 -> V_233 = V_137 -> V_233 -> V_235 ;
F_110 ( & V_6 -> V_234 ) ;
} else {
F_111 ( V_137 -> V_233 != & V_6 -> V_234 ) ;
V_137 -> V_233 = NULL ;
}
F_46 ( & V_137 -> V_68 ) ;
if ( V_137 -> V_233 == NULL ) {
F_112 ( & V_137 -> V_238 ) ;
F_113 ( V_137 ) ;
}
}
static int F_114 ( struct V_5 * V_6 )
{
struct V_239 * V_240 ;
struct V_241 * V_242 ;
struct V_227 * V_137 ;
int V_221 , V_243 = V_6 -> V_2 . V_108 & V_244 ? V_245 : 0 ;
F_115 ( & V_246 ) ;
V_240 = & V_247 [ V_6 -> V_2 . V_151 % V_248 ] ;
F_116 (n, h) {
V_137 = F_117 ( V_242 , struct V_227 , V_238 ) ;
if ( V_137 -> V_151 == V_6 -> V_2 . V_151 )
break;
}
if ( V_242 == NULL ) {
V_137 = F_118 ( sizeof( struct V_227 ) , V_249 ) ;
if ( V_137 == NULL ) {
F_119 ( & V_246 ) ;
return - V_250 ;
}
F_120 ( & V_137 -> V_68 ) ;
V_137 -> V_151 = V_6 -> V_2 . V_151 ;
F_121 ( & V_137 -> V_238 , V_240 ) ;
}
F_119 ( & V_246 ) ;
F_45 ( & V_137 -> V_68 ) ;
if ( V_137 -> V_233 ) {
F_122 ( & V_6 -> V_234 , V_137 -> V_233 ) ;
F_46 ( & V_137 -> V_68 ) ;
V_221 = 0 ;
} else {
F_123 ( & V_6 -> V_234 ) ;
V_137 -> V_233 = & V_6 -> V_234 ;
F_46 ( & V_137 -> V_68 ) ;
V_243 |= V_6 -> V_2 . V_251 ;
V_221 = F_124 ( V_6 -> V_2 . V_151 , F_104 ,
V_243 , L_23 , V_137 ) ;
if ( V_221 < 0 )
F_108 ( V_137 , V_6 ) ;
}
return V_221 ;
}
static void F_125 ( struct V_5 * V_6 )
{
struct V_227 * V_137 ;
struct V_241 * V_242 ;
struct V_239 * V_240 ;
F_115 ( & V_246 ) ;
V_240 = & V_247 [ V_6 -> V_2 . V_151 % V_248 ] ;
F_116 (n, h) {
V_137 = F_117 ( V_242 , struct V_227 , V_238 ) ;
if ( V_137 -> V_151 == V_6 -> V_2 . V_151 )
break;
}
F_111 ( V_242 == NULL ) ;
F_111 ( V_137 -> V_233 == NULL ) ;
if ( F_109 ( V_137 -> V_233 ) )
F_126 ( V_6 -> V_2 . V_151 , V_137 ) ;
F_108 ( V_137 , V_6 ) ;
F_119 ( & V_246 ) ;
}
static void F_127 ( unsigned long V_252 )
{
struct V_5 * V_6 = (struct V_5 * ) V_252 ;
V_6 -> V_2 . V_28 ( & V_6 -> V_2 ) ;
F_128 ( & V_6 -> V_253 , V_254 + F_129 ( & V_6 -> V_2 ) ) ;
}
static void F_130 ( unsigned long V_252 )
{
struct V_5 * V_6 = (struct V_5 * ) V_252 ;
unsigned int V_215 , V_157 = 0 , V_163 ;
unsigned long V_108 ;
F_61 ( & V_6 -> V_2 . V_68 , V_108 ) ;
if ( V_6 -> V_2 . V_151 ) {
V_157 = F_3 ( V_6 , V_59 ) ;
F_5 ( V_6 , V_59 , 0 ) ;
}
V_215 = F_3 ( V_6 , V_117 ) ;
V_163 = F_3 ( V_6 , V_80 ) ;
V_6 -> V_164 |= V_163 & V_165 ;
if ( ( V_215 & V_217 ) && ( V_6 -> V_157 & V_158 ) &&
( ! F_94 ( & V_6 -> V_2 . V_193 -> V_195 ) || V_6 -> V_2 . V_196 ) &&
( V_163 & V_220 ) ) {
V_215 &= ~ ( V_255 | V_217 ) ;
V_215 |= V_256 ;
}
if ( ! ( V_215 & V_217 ) )
F_76 ( V_6 ) ;
if ( V_6 -> V_2 . V_151 )
F_5 ( V_6 , V_59 , V_157 ) ;
F_63 ( & V_6 -> V_2 . V_68 , V_108 ) ;
F_128 ( & V_6 -> V_253 ,
V_254 + F_129 ( & V_6 -> V_2 ) + V_257 / 5 ) ;
}
static unsigned int F_131 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_27 ( V_2 ) ;
unsigned long V_108 ;
unsigned int V_163 ;
F_34 ( V_6 ) ;
F_61 ( & V_2 -> V_68 , V_108 ) ;
V_163 = F_95 ( V_2 , V_80 ) ;
V_6 -> V_164 |= V_163 & V_165 ;
F_63 ( & V_2 -> V_68 , V_108 ) ;
F_36 ( V_6 ) ;
return ( V_163 & V_202 ) == V_202 ? V_258 : 0 ;
}
static unsigned int F_132 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_27 ( V_2 ) ;
unsigned int V_105 ;
unsigned int V_221 ;
F_34 ( V_6 ) ;
V_105 = F_98 ( V_6 ) ;
F_36 ( V_6 ) ;
V_221 = 0 ;
if ( V_105 & V_211 )
V_221 |= V_259 ;
if ( V_105 & V_260 )
V_221 |= V_261 ;
if ( V_105 & V_262 )
V_221 |= V_263 ;
if ( V_105 & V_213 )
V_221 |= V_264 ;
return V_221 ;
}
static void F_133 ( struct V_1 * V_2 , unsigned int V_265 )
{
struct V_5 * V_6 = F_27 ( V_2 ) ;
unsigned char V_266 = 0 ;
if ( V_265 & V_267 )
V_266 |= V_156 ;
if ( V_265 & V_268 )
V_266 |= V_155 ;
if ( V_265 & V_269 )
V_266 |= V_153 ;
if ( V_265 & V_270 )
V_266 |= V_154 ;
if ( V_265 & V_271 )
V_266 |= V_77 ;
V_266 = ( V_266 & V_6 -> V_272 ) | V_6 -> V_273 | V_6 -> V_266 ;
F_75 ( V_2 , V_76 , V_266 ) ;
}
static void F_134 ( struct V_1 * V_2 , int V_274 )
{
struct V_5 * V_6 = F_27 ( V_2 ) ;
unsigned long V_108 ;
F_34 ( V_6 ) ;
F_61 ( & V_2 -> V_68 , V_108 ) ;
if ( V_274 == - 1 )
V_6 -> V_48 |= V_275 ;
else
V_6 -> V_48 &= ~ V_275 ;
F_75 ( V_2 , V_30 , V_6 -> V_48 ) ;
F_63 ( & V_2 -> V_68 , V_108 ) ;
F_36 ( V_6 ) ;
}
static void F_135 ( struct V_5 * V_6 , int V_276 )
{
unsigned int V_105 , V_277 = 10000 ;
for (; ; ) {
V_105 = F_3 ( V_6 , V_80 ) ;
V_6 -> V_164 |= V_105 & V_165 ;
if ( ( V_105 & V_276 ) == V_276 )
break;
if ( -- V_277 == 0 )
break;
F_71 ( 1 ) ;
}
if ( V_6 -> V_2 . V_108 & V_278 ) {
unsigned int V_277 ;
for ( V_277 = 1000000 ; V_277 ; V_277 -- ) {
unsigned int V_279 = F_3 ( V_6 , V_133 ) ;
V_6 -> V_204 |= V_279 & V_280 ;
if ( V_279 & V_213 )
break;
F_71 ( 1 ) ;
F_136 () ;
}
}
}
static int F_137 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_27 ( V_2 ) ;
unsigned char V_163 ;
int V_105 ;
F_34 ( V_6 ) ;
V_163 = F_95 ( V_2 , V_80 ) ;
if ( ! ( V_163 & V_81 ) ) {
V_105 = V_281 ;
goto V_53;
}
V_105 = F_95 ( V_2 , V_82 ) ;
V_53:
F_36 ( V_6 ) ;
return V_105 ;
}
static void F_138 ( struct V_1 * V_2 ,
unsigned char V_282 )
{
unsigned int V_157 ;
struct V_5 * V_6 = F_27 ( V_2 ) ;
F_34 ( V_6 ) ;
V_157 = F_95 ( V_2 , V_59 ) ;
if ( V_6 -> V_36 & V_121 )
F_75 ( V_2 , V_59 , V_119 ) ;
else
F_75 ( V_2 , V_59 , 0 ) ;
F_135 ( V_6 , V_202 ) ;
F_75 ( V_2 , V_79 , V_282 ) ;
F_135 ( V_6 , V_202 ) ;
F_75 ( V_2 , V_59 , V_157 ) ;
F_36 ( V_6 ) ;
}
int F_139 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_27 ( V_2 ) ;
unsigned long V_108 ;
unsigned char V_163 , V_215 ;
int V_283 ;
if ( V_2 -> type == V_284 )
return - V_285 ;
if ( ! V_2 -> V_140 )
V_2 -> V_140 = V_141 [ V_2 -> type ] . V_142 ;
if ( ! V_6 -> V_143 )
V_6 -> V_143 = V_141 [ V_2 -> type ] . V_143 ;
if ( ! V_6 -> V_36 )
V_6 -> V_36 = V_141 [ V_2 -> type ] . V_108 ;
V_6 -> V_266 = 0 ;
if ( V_2 -> V_20 != V_6 -> V_27 )
F_26 ( V_2 ) ;
F_34 ( V_6 ) ;
if ( V_2 -> type == V_94 ) {
V_6 -> V_34 = 0 ;
F_75 ( V_2 , V_30 , V_57 ) ;
F_75 ( V_2 , V_56 , V_58 ) ;
F_75 ( V_2 , V_59 , 0 ) ;
F_75 ( V_2 , V_30 , 0 ) ;
F_30 ( V_6 , V_286 , 0 ) ;
F_75 ( V_2 , V_30 , V_57 ) ;
F_75 ( V_2 , V_56 , V_58 ) ;
F_75 ( V_2 , V_30 , 0 ) ;
}
#ifdef F_64
F_44 ( V_6 ) ;
#endif
F_32 ( V_6 ) ;
if ( F_95 ( V_2 , V_80 ) & V_81 )
F_95 ( V_2 , V_82 ) ;
F_95 ( V_2 , V_117 ) ;
F_95 ( V_2 , V_133 ) ;
if ( ! ( V_2 -> V_108 & V_131 ) &&
( F_95 ( V_2 , V_80 ) == 0xff ) ) {
F_106 ( V_287 L_24 ,
F_1 ( V_2 ) ) ;
V_283 = - V_285 ;
goto V_53;
}
if ( V_2 -> type == V_97 ) {
unsigned char V_288 ;
F_5 ( V_6 , V_30 , V_57 ) ;
V_288 = F_3 ( V_6 , V_289 ) & ~ ( V_290 | V_291 ) ;
F_75 ( V_2 , V_289 ,
V_288 | V_292 | V_290 ) ;
F_75 ( V_2 , V_293 , V_294 ) ;
F_75 ( V_2 , V_289 ,
V_288 | V_292 | V_291 ) ;
F_75 ( V_2 , V_293 , V_294 ) ;
F_75 ( V_2 , V_30 , 0 ) ;
}
if ( V_2 -> V_151 ) {
unsigned char V_295 ;
F_61 ( & V_2 -> V_68 , V_108 ) ;
if ( V_6 -> V_2 . V_251 & V_245 )
F_140 ( V_2 -> V_151 ) ;
F_135 ( V_6 , V_220 ) ;
F_29 ( V_2 , V_59 , V_158 ) ;
F_71 ( 1 ) ;
V_295 = F_95 ( V_2 , V_117 ) ;
F_75 ( V_2 , V_59 , 0 ) ;
F_29 ( V_2 , V_59 , V_158 ) ;
F_71 ( 1 ) ;
V_215 = F_95 ( V_2 , V_117 ) ;
F_75 ( V_2 , V_59 , 0 ) ;
if ( V_2 -> V_251 & V_245 )
F_141 ( V_2 -> V_151 ) ;
F_63 ( & V_2 -> V_68 , V_108 ) ;
if ( ( ! ( V_295 & V_217 ) && ( V_215 & V_217 ) ) ||
V_6 -> V_2 . V_108 & V_296 ) {
V_6 -> V_95 |= V_297 ;
F_142 ( L_25 ,
F_1 ( V_2 ) ) ;
}
}
if ( V_6 -> V_95 & V_297 ) {
V_6 -> V_253 . V_298 = F_130 ;
V_6 -> V_253 . V_252 = ( unsigned long ) V_6 ;
F_128 ( & V_6 -> V_253 , V_254 +
F_129 ( V_2 ) + V_257 / 5 ) ;
}
if ( ! V_2 -> V_151 ) {
V_6 -> V_253 . V_252 = ( unsigned long ) V_6 ;
F_128 ( & V_6 -> V_253 , V_254 + F_129 ( V_2 ) ) ;
} else {
V_283 = F_114 ( V_6 ) ;
if ( V_283 )
goto V_53;
}
F_75 ( V_2 , V_30 , V_299 ) ;
F_61 ( & V_2 -> V_68 , V_108 ) ;
if ( V_6 -> V_2 . V_108 & V_152 ) {
if ( ! V_6 -> V_2 . V_151 )
V_6 -> V_2 . V_265 |= V_269 ;
} else
if ( V_2 -> V_151 )
V_6 -> V_2 . V_265 |= V_270 ;
F_133 ( V_2 , V_2 -> V_265 ) ;
if ( V_300 || V_6 -> V_2 . V_108 & V_301 )
goto V_302;
F_75 ( V_2 , V_59 , V_158 ) ;
V_163 = F_95 ( V_2 , V_80 ) ;
V_215 = F_95 ( V_2 , V_117 ) ;
F_75 ( V_2 , V_59 , 0 ) ;
if ( V_163 & V_166 && V_215 & V_217 ) {
if ( ! ( V_6 -> V_95 & V_162 ) ) {
V_6 -> V_95 |= V_162 ;
F_142 ( L_26 ,
F_1 ( V_2 ) ) ;
}
} else {
V_6 -> V_95 &= ~ V_162 ;
}
V_302:
F_63 ( & V_2 -> V_68 , V_108 ) ;
if ( F_95 ( V_2 , V_80 ) & V_81 )
F_95 ( V_2 , V_82 ) ;
F_95 ( V_2 , V_117 ) ;
F_95 ( V_2 , V_133 ) ;
V_6 -> V_164 = 0 ;
V_6 -> V_204 = 0 ;
if ( V_6 -> V_160 ) {
V_283 = F_143 ( V_6 ) ;
if ( V_283 ) {
F_144 ( L_27 ,
F_1 ( V_2 ) ) ;
V_6 -> V_160 = NULL ;
}
}
V_6 -> V_157 = V_169 | V_170 ;
F_75 ( V_2 , V_59 , V_6 -> V_157 ) ;
if ( V_2 -> V_108 & V_152 ) {
unsigned int V_303 ;
V_303 = ( V_2 -> V_17 & 0xfe0 ) | 0x01f ;
F_68 ( 0x80 , V_303 ) ;
F_67 ( V_303 ) ;
}
V_283 = 0 ;
V_53:
F_36 ( V_6 ) ;
return V_283 ;
}
static int F_145 ( struct V_1 * V_2 )
{
if ( V_2 -> V_304 )
return V_2 -> V_304 ( V_2 ) ;
return F_139 ( V_2 ) ;
}
void F_146 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_27 ( V_2 ) ;
unsigned long V_108 ;
F_34 ( V_6 ) ;
V_6 -> V_157 = 0 ;
F_75 ( V_2 , V_59 , 0 ) ;
if ( V_6 -> V_160 )
F_147 ( V_6 ) ;
F_61 ( & V_2 -> V_68 , V_108 ) ;
if ( V_2 -> V_108 & V_152 ) {
F_14 ( ( V_2 -> V_17 & 0xfe0 ) | 0x1f ) ;
V_2 -> V_265 |= V_269 ;
} else
V_2 -> V_265 &= ~ V_270 ;
F_133 ( V_2 , V_2 -> V_265 ) ;
F_63 ( & V_2 -> V_68 , V_108 ) ;
F_75 ( V_2 , V_30 ,
F_95 ( V_2 , V_30 ) & ~ V_275 ) ;
F_32 ( V_6 ) ;
#ifdef F_64
F_47 ( V_6 ) ;
#endif
if ( F_95 ( V_2 , V_80 ) & V_81 )
F_95 ( V_2 , V_82 ) ;
F_36 ( V_6 ) ;
F_148 ( & V_6 -> V_253 ) ;
V_6 -> V_253 . V_298 = F_127 ;
if ( V_2 -> V_151 )
F_125 ( V_6 ) ;
}
static void F_149 ( struct V_1 * V_2 )
{
if ( V_2 -> V_305 )
V_2 -> V_305 ( V_2 ) ;
else
F_146 ( V_2 ) ;
}
static unsigned int F_150 ( struct V_1 * V_2 , unsigned int V_306 )
{
unsigned int V_113 ;
if ( ( V_2 -> V_108 & V_307 ) &&
V_306 == ( V_2 -> V_65 / 4 ) )
V_113 = 0x8001 ;
else if ( ( V_2 -> V_108 & V_307 ) &&
V_306 == ( V_2 -> V_65 / 8 ) )
V_113 = 0x8002 ;
else
V_113 = F_151 ( V_2 , V_306 ) ;
return V_113 ;
}
void
F_152 ( struct V_1 * V_2 , struct V_308 * V_309 ,
struct V_308 * V_310 )
{
struct V_5 * V_6 = F_27 ( V_2 ) ;
unsigned char V_311 ;
unsigned long V_108 ;
unsigned int V_306 , V_113 ;
switch ( V_309 -> V_312 & V_313 ) {
case V_314 :
V_311 = V_315 ;
break;
case V_316 :
V_311 = V_317 ;
break;
case V_318 :
V_311 = V_319 ;
break;
default:
case V_320 :
V_311 = V_299 ;
break;
}
if ( V_309 -> V_312 & V_321 )
V_311 |= V_322 ;
if ( V_309 -> V_312 & V_323 ) {
V_311 |= V_324 ;
if ( V_6 -> V_95 & V_325 )
V_6 -> V_326 = true ;
}
if ( ! ( V_309 -> V_312 & V_327 ) )
V_311 |= V_328 ;
#ifdef F_153
if ( V_309 -> V_312 & F_153 )
V_311 |= V_329 ;
#endif
V_306 = F_154 ( V_2 , V_309 , V_310 ,
V_2 -> V_65 / 16 / 0xffff ,
V_2 -> V_65 / 16 ) ;
V_113 = F_150 ( V_2 , V_306 ) ;
if ( V_6 -> V_95 & V_96 && ( V_113 & 0xff ) == 0 )
V_113 ++ ;
if ( V_6 -> V_36 & V_37 && V_2 -> V_140 > 1 ) {
if ( ( V_306 < 2400 && ! V_6 -> V_160 ) || V_6 -> V_326 ) {
V_6 -> V_42 &= ~ V_330 ;
V_6 -> V_42 |= V_331 ;
}
}
if ( V_6 -> V_36 & V_111 && V_2 -> V_140 >= 32 ) {
V_6 -> V_266 &= ~ V_332 ;
if ( V_309 -> V_312 & V_333 )
V_6 -> V_266 |= V_332 ;
}
F_34 ( V_6 ) ;
F_61 ( & V_2 -> V_68 , V_108 ) ;
F_155 ( V_2 , V_309 -> V_312 , V_306 ) ;
V_2 -> V_171 = V_188 | V_220 | V_81 ;
if ( V_309 -> V_334 & V_335 )
V_2 -> V_171 |= V_182 | V_183 ;
if ( V_309 -> V_334 & ( V_336 | V_337 | V_338 ) )
V_2 -> V_171 |= V_181 ;
V_2 -> V_339 = 0 ;
if ( V_309 -> V_334 & V_340 )
V_2 -> V_339 |= V_183 | V_182 ;
if ( V_309 -> V_334 & V_336 ) {
V_2 -> V_339 |= V_181 ;
if ( V_309 -> V_334 & V_340 )
V_2 -> V_339 |= V_188 ;
}
if ( ( V_309 -> V_312 & V_341 ) == 0 )
V_2 -> V_339 |= V_81 ;
V_6 -> V_157 &= ~ V_173 ;
if ( ! ( V_6 -> V_95 & V_172 ) &&
F_156 ( & V_6 -> V_2 , V_309 -> V_312 ) )
V_6 -> V_157 |= V_173 ;
if ( V_6 -> V_36 & V_121 )
V_6 -> V_157 |= V_119 ;
if ( V_6 -> V_36 & V_122 )
V_6 -> V_157 |= V_342 ;
F_75 ( V_2 , V_59 , V_6 -> V_157 ) ;
if ( V_6 -> V_36 & V_55 ) {
unsigned char V_49 = 0 ;
if ( V_309 -> V_312 & V_333 )
V_49 |= V_343 ;
F_75 ( V_2 , V_30 , V_57 ) ;
if ( V_2 -> V_108 & V_109 )
F_75 ( V_2 , V_344 , V_49 ) ;
else
F_75 ( V_2 , V_56 , V_49 ) ;
}
if ( F_157 ( V_6 ) ) {
if ( V_306 == 115200 ) {
V_113 = 1 ;
F_75 ( V_2 , V_345 , 1 ) ;
} else
F_75 ( V_2 , V_345 , 0 ) ;
}
if ( V_6 -> V_36 & V_115 )
F_75 ( V_2 , V_30 , 0xe0 ) ;
else
F_75 ( V_2 , V_30 , V_311 | V_346 ) ;
F_50 ( V_6 , V_113 ) ;
if ( V_6 -> V_2 . type == V_50 ) {
unsigned int V_347 = ( V_2 -> V_65 * 2 ) / V_306 ;
T_3 V_113 = V_347 / 32 ;
T_4 V_348 = F_158 ( V_347 % 32 , 2 ) ;
F_50 ( V_6 , V_113 ) ;
F_75 ( V_2 , 0x2 , V_348 & 0xf ) ;
}
if ( V_2 -> type == V_118 )
F_75 ( V_2 , V_38 , V_6 -> V_42 ) ;
F_75 ( V_2 , V_30 , V_311 ) ;
V_6 -> V_48 = V_311 ;
if ( V_2 -> type != V_118 ) {
if ( V_6 -> V_42 & V_39 )
F_75 ( V_2 , V_38 , V_39 ) ;
F_75 ( V_2 , V_38 , V_6 -> V_42 ) ;
}
F_133 ( V_2 , V_2 -> V_265 ) ;
F_63 ( & V_2 -> V_68 , V_108 ) ;
F_36 ( V_6 ) ;
if ( F_159 ( V_309 ) )
F_160 ( V_309 , V_306 , V_306 ) ;
}
static void
F_161 ( struct V_1 * V_2 , struct V_308 * V_309 ,
struct V_308 * V_310 )
{
if ( V_2 -> V_349 )
V_2 -> V_349 ( V_2 , V_309 , V_310 ) ;
else
F_152 ( V_2 , V_309 , V_310 ) ;
}
static void
F_162 ( struct V_1 * V_2 , struct V_308 * V_309 )
{
if ( V_309 -> V_350 == V_351 ) {
V_2 -> V_108 |= V_352 ;
F_45 ( & V_2 -> V_68 ) ;
F_82 ( V_2 ) ;
F_46 ( & V_2 -> V_68 ) ;
} else {
V_2 -> V_108 &= ~ V_352 ;
if ( ! F_156 ( V_2 , V_309 -> V_312 ) ) {
F_45 ( & V_2 -> V_68 ) ;
F_80 ( V_2 ) ;
F_46 ( & V_2 -> V_68 ) ;
}
}
}
void F_163 ( struct V_1 * V_2 , unsigned int V_193 ,
unsigned int V_353 )
{
struct V_5 * V_10 = F_27 ( V_2 ) ;
F_42 ( V_10 , V_193 != 0 ) ;
}
static void
F_164 ( struct V_1 * V_2 , unsigned int V_193 ,
unsigned int V_353 )
{
if ( V_2 -> V_354 )
V_2 -> V_354 ( V_2 , V_193 , V_353 ) ;
else
F_163 ( V_2 , V_193 , V_353 ) ;
}
static unsigned int F_165 ( struct V_5 * V_355 )
{
if ( V_355 -> V_2 . V_20 == V_26 ) {
if ( V_355 -> V_2 . type == V_356 )
return 0x100 ;
return 0x1000 ;
}
if ( F_166 ( V_355 ) )
return 0x16 << V_355 -> V_2 . V_13 ;
return 8 << V_355 -> V_2 . V_13 ;
}
static int F_167 ( struct V_5 * V_6 )
{
unsigned int V_357 = F_165 ( V_6 ) ;
struct V_1 * V_2 = & V_6 -> V_2 ;
int V_221 = 0 ;
switch ( V_2 -> V_20 ) {
case V_26 :
case V_358 :
case V_23 :
case V_22 :
if ( ! V_2 -> V_130 )
break;
if ( ! F_168 ( V_2 -> V_130 , V_357 , L_23 ) ) {
V_221 = - V_359 ;
break;
}
if ( V_2 -> V_108 & V_360 ) {
V_2 -> V_14 = F_169 ( V_2 -> V_130 , V_357 ) ;
if ( ! V_2 -> V_14 ) {
F_170 ( V_2 -> V_130 , V_357 ) ;
V_221 = - V_250 ;
}
}
break;
case V_21 :
case V_361 :
if ( ! F_171 ( V_2 -> V_17 , V_357 , L_23 ) )
V_221 = - V_359 ;
break;
}
return V_221 ;
}
static void F_172 ( struct V_5 * V_6 )
{
unsigned int V_357 = F_165 ( V_6 ) ;
struct V_1 * V_2 = & V_6 -> V_2 ;
switch ( V_2 -> V_20 ) {
case V_26 :
case V_358 :
case V_23 :
case V_22 :
if ( ! V_2 -> V_130 )
break;
if ( V_2 -> V_108 & V_360 ) {
F_173 ( V_2 -> V_14 ) ;
V_2 -> V_14 = NULL ;
}
F_170 ( V_2 -> V_130 , V_357 ) ;
break;
case V_21 :
case V_361 :
F_174 ( V_2 -> V_17 , V_357 ) ;
break;
}
}
static int F_175 ( struct V_5 * V_6 )
{
unsigned long V_362 = V_363 << V_6 -> V_2 . V_13 ;
unsigned int V_357 = 8 << V_6 -> V_2 . V_13 ;
struct V_1 * V_2 = & V_6 -> V_2 ;
int V_221 = - V_364 ;
switch ( V_2 -> V_20 ) {
case V_21 :
case V_361 :
V_362 += V_2 -> V_17 ;
if ( F_171 ( V_362 , V_357 , L_28 ) )
V_221 = 0 ;
else
V_221 = - V_359 ;
break;
}
return V_221 ;
}
static void F_176 ( struct V_5 * V_6 )
{
unsigned long V_11 = V_363 << V_6 -> V_2 . V_13 ;
unsigned int V_357 = 8 << V_6 -> V_2 . V_13 ;
struct V_1 * V_2 = & V_6 -> V_2 ;
switch ( V_2 -> V_20 ) {
case V_21 :
case V_361 :
F_174 ( V_2 -> V_17 + V_11 , V_357 ) ;
break;
}
}
static void F_177 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_27 ( V_2 ) ;
F_172 ( V_6 ) ;
if ( V_2 -> type == V_67 )
F_176 ( V_6 ) ;
}
static int F_178 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_27 ( V_2 ) ;
int V_221 ;
if ( V_2 -> type == V_284 )
return - V_285 ;
V_221 = F_167 ( V_6 ) ;
if ( V_221 == 0 && V_2 -> type == V_67 ) {
V_221 = F_175 ( V_6 ) ;
if ( V_221 < 0 )
F_172 ( V_6 ) ;
}
return V_221 ;
}
static int F_179 ( struct V_5 * V_6 )
{
const struct V_365 * V_366 = & V_141 [ V_6 -> V_2 . type ] ;
unsigned char V_367 ;
V_367 = V_366 -> V_368 [ F_180 ( V_6 -> V_42 ) ] ;
return V_367 ? V_367 : - V_369 ;
}
static int F_181 ( struct V_5 * V_6 , unsigned char V_367 )
{
const struct V_365 * V_366 = & V_141 [ V_6 -> V_2 . type ] ;
int V_137 ;
if ( ! V_366 -> V_368 [ F_180 ( V_370 ) ] )
return - V_369 ;
for ( V_137 = 1 ; V_137 < V_371 ; V_137 ++ ) {
if ( V_367 < V_366 -> V_368 [ V_137 ] )
return ( -- V_137 ) << V_372 ;
}
return V_373 ;
}
static int F_182 ( struct V_374 * V_2 )
{
struct V_375 * V_193 = F_81 ( V_2 , struct V_375 , V_2 ) ;
struct V_1 * V_376 = V_193 -> V_1 ;
struct V_5 * V_6 =
F_81 ( V_376 , struct V_5 , V_2 ) ;
if ( ! ( V_6 -> V_36 & V_37 ) || V_376 -> V_140 <= 1 )
return - V_364 ;
return F_179 ( V_6 ) ;
}
static int F_183 ( struct V_374 * V_2 )
{
int V_368 ;
F_115 ( & V_2 -> V_377 ) ;
V_368 = F_182 ( V_2 ) ;
F_119 ( & V_2 -> V_377 ) ;
return V_368 ;
}
static T_5 F_184 ( struct V_378 * V_44 ,
struct V_379 * V_380 , char * V_198 )
{
struct V_374 * V_2 = F_185 ( V_44 ) ;
int V_368 ;
V_368 = F_183 ( V_2 ) ;
if ( V_368 < 0 )
return V_368 ;
return snprintf ( V_198 , V_381 , L_29 , V_368 ) ;
}
static int F_186 ( struct V_374 * V_2 , unsigned char V_367 )
{
struct V_375 * V_193 = F_81 ( V_2 , struct V_375 , V_2 ) ;
struct V_1 * V_376 = V_193 -> V_1 ;
struct V_5 * V_6 =
F_81 ( V_376 , struct V_5 , V_2 ) ;
int V_382 ;
if ( ! ( V_6 -> V_36 & V_37 ) || V_376 -> V_140 <= 1 ||
V_6 -> V_326 )
return - V_364 ;
V_382 = F_181 ( V_6 , V_367 ) ;
if ( V_382 < 0 )
return V_382 ;
F_32 ( V_6 ) ;
V_6 -> V_42 &= ~ V_330 ;
V_6 -> V_42 |= ( unsigned char ) V_382 ;
F_5 ( V_6 , V_38 , V_6 -> V_42 ) ;
return 0 ;
}
static int F_187 ( struct V_374 * V_2 , unsigned char V_367 )
{
int V_221 ;
F_115 ( & V_2 -> V_377 ) ;
V_221 = F_186 ( V_2 , V_367 ) ;
F_119 ( & V_2 -> V_377 ) ;
return V_221 ;
}
static T_5 F_188 ( struct V_378 * V_44 ,
struct V_379 * V_380 , const char * V_198 , T_6 V_75 )
{
struct V_374 * V_2 = F_185 ( V_44 ) ;
unsigned char V_367 ;
int V_221 ;
if ( ! V_75 )
return - V_364 ;
V_221 = F_189 ( V_198 , 10 , & V_367 ) ;
if ( V_221 < 0 )
return V_221 ;
V_221 = F_187 ( V_2 , V_367 ) ;
if ( V_221 < 0 )
return V_221 ;
return V_75 ;
}
static void F_190 ( struct V_5 * V_6 )
{
const struct V_365 * V_366 = & V_141 [ V_6 -> V_2 . type ] ;
if ( V_366 -> V_368 [ 0 ] )
V_6 -> V_2 . V_383 = & V_384 ;
}
static void F_191 ( struct V_1 * V_2 , int V_108 )
{
struct V_5 * V_6 = F_27 ( V_2 ) ;
int V_124 = V_385 ;
int V_221 ;
if ( V_2 -> type == V_284 )
return;
V_221 = F_167 ( V_6 ) ;
if ( V_221 < 0 )
return;
V_221 = F_175 ( V_6 ) ;
if ( V_221 < 0 )
V_124 &= ~ V_136 ;
if ( V_2 -> V_20 != V_6 -> V_27 )
F_26 ( V_2 ) ;
if ( V_108 & V_386 )
F_60 ( V_6 , V_124 ) ;
if ( V_2 -> type == V_107 && V_2 -> V_20 == V_26 )
V_6 -> V_95 |= V_172 ;
if ( V_2 -> type == V_387 )
V_6 -> V_95 |= V_172 ;
if ( V_2 -> type != V_134 && V_108 & V_388 )
F_66 ( V_6 ) ;
if ( V_2 -> type != V_67 && V_124 & V_136 )
F_176 ( V_6 ) ;
if ( V_2 -> type == V_134 )
F_172 ( V_6 ) ;
if ( ( V_2 -> type == V_50 ) ||
( V_2 -> type == V_51 ) )
V_2 -> V_28 = F_103 ;
F_190 ( V_6 ) ;
V_6 -> V_42 = V_141 [ V_6 -> V_2 . type ] . V_42 ;
}
static int
F_192 ( struct V_1 * V_2 , struct V_389 * V_390 )
{
if ( V_390 -> V_151 >= V_391 || V_390 -> V_151 < 0 ||
V_390 -> V_392 < 9600 || V_390 -> type < V_134 ||
V_390 -> type >= F_193 ( V_141 ) || V_390 -> type == V_393 ||
V_390 -> type == V_394 )
return - V_364 ;
return 0 ;
}
static const char *
F_194 ( struct V_1 * V_2 )
{
int type = V_2 -> type ;
if ( type >= F_193 ( V_141 ) )
type = 0 ;
return V_141 [ type ] . V_146 ;
}
struct V_5 * F_195 ( int line )
{
return & V_395 [ line ] ;
}
void F_196 (
void (* F_197)( int V_2 , struct V_1 * V_6 , unsigned short * V_36 ) )
{
V_396 = F_197 ;
}
static void T_7 F_198 ( void )
{
struct V_5 * V_6 ;
static int V_397 = 1 ;
int V_137 , V_398 = 0 ;
if ( ! V_397 )
return;
V_397 = 0 ;
if ( V_399 > V_400 )
V_399 = V_400 ;
for ( V_137 = 0 ; V_137 < V_399 ; V_137 ++ ) {
struct V_5 * V_6 = & V_395 [ V_137 ] ;
struct V_1 * V_2 = & V_6 -> V_2 ;
V_2 -> line = V_137 ;
F_120 ( & V_2 -> V_68 ) ;
F_199 ( & V_6 -> V_253 ) ;
V_6 -> V_253 . V_298 = F_127 ;
V_6 -> V_27 = 0xFF ;
V_6 -> V_272 = ~ V_401 ;
V_6 -> V_273 = V_401 ;
V_2 -> V_402 = & V_403 ;
}
if ( V_404 )
V_398 = V_245 ;
for ( V_137 = 0 , V_6 = V_395 ;
V_137 < F_193 ( V_405 ) && V_137 < V_399 ;
V_137 ++ , V_6 ++ ) {
struct V_1 * V_2 = & V_6 -> V_2 ;
V_2 -> V_17 = V_405 [ V_137 ] . V_2 ;
V_2 -> V_151 = F_200 ( V_405 [ V_137 ] . V_151 ) ;
V_2 -> V_251 = V_405 [ V_137 ] . V_251 ;
V_2 -> V_65 = V_405 [ V_137 ] . V_392 * 16 ;
V_2 -> V_108 = V_405 [ V_137 ] . V_108 ;
V_2 -> V_16 = V_405 [ V_137 ] . V_16 ;
V_2 -> V_14 = V_405 [ V_137 ] . V_406 ;
V_2 -> V_20 = V_405 [ V_137 ] . V_407 ;
V_2 -> V_13 = V_405 [ V_137 ] . V_408 ;
F_26 ( V_2 ) ;
V_2 -> V_251 |= V_398 ;
if ( V_396 != NULL )
V_396 ( V_137 , & V_6 -> V_2 , & V_6 -> V_36 ) ;
}
}
static void
F_201 ( struct V_5 * V_6 , unsigned int type )
{
V_6 -> V_2 . type = type ;
if ( ! V_6 -> V_2 . V_140 )
V_6 -> V_2 . V_140 = V_141 [ type ] . V_142 ;
if ( ! V_6 -> V_143 )
V_6 -> V_143 = V_141 [ type ] . V_143 ;
if ( ! V_6 -> V_36 )
V_6 -> V_36 = V_141 [ type ] . V_108 ;
}
static void T_7
F_202 ( struct V_409 * V_410 , struct V_378 * V_44 )
{
int V_137 ;
for ( V_137 = 0 ; V_137 < V_399 ; V_137 ++ ) {
struct V_5 * V_6 = & V_395 [ V_137 ] ;
if ( V_6 -> V_2 . V_44 )
continue;
V_6 -> V_2 . V_44 = V_44 ;
if ( V_6 -> V_2 . V_108 & V_411 )
F_201 ( V_6 , V_6 -> V_2 . type ) ;
F_203 ( V_410 , & V_6 -> V_2 ) ;
}
}
static void F_204 ( struct V_1 * V_2 , int V_174 )
{
struct V_5 * V_6 = F_27 ( V_2 ) ;
F_135 ( V_6 , V_220 ) ;
F_75 ( V_2 , V_79 , V_174 ) ;
}
static void
F_205 ( struct V_412 * V_413 , const char * V_414 , unsigned int V_75 )
{
struct V_5 * V_6 = & V_395 [ V_413 -> V_415 ] ;
struct V_1 * V_2 = & V_6 -> V_2 ;
unsigned long V_108 ;
unsigned int V_157 ;
int V_416 = 1 ;
F_136 () ;
F_34 ( V_6 ) ;
if ( V_2 -> V_417 )
V_416 = 0 ;
else if ( V_418 )
V_416 = F_206 ( & V_2 -> V_68 , V_108 ) ;
else
F_61 ( & V_2 -> V_68 , V_108 ) ;
V_157 = F_95 ( V_2 , V_59 ) ;
if ( V_6 -> V_36 & V_121 )
F_75 ( V_2 , V_59 , V_119 ) ;
else
F_75 ( V_2 , V_59 , 0 ) ;
F_207 ( V_2 , V_414 , V_75 , F_204 ) ;
F_135 ( V_6 , V_202 ) ;
F_75 ( V_2 , V_59 , V_157 ) ;
if ( V_6 -> V_204 )
F_98 ( V_6 ) ;
if ( V_416 )
F_63 ( & V_2 -> V_68 , V_108 ) ;
F_36 ( V_6 ) ;
}
static int F_208 ( struct V_412 * V_413 , char * V_419 )
{
struct V_1 * V_2 ;
int V_306 = 9600 ;
int V_276 = 8 ;
int V_186 = 'n' ;
int V_420 = 'n' ;
if ( V_413 -> V_415 >= V_399 )
V_413 -> V_415 = 0 ;
V_2 = & V_395 [ V_413 -> V_415 ] . V_2 ;
if ( ! V_2 -> V_17 && ! V_2 -> V_14 )
return - V_285 ;
if ( V_419 )
F_209 ( V_419 , & V_306 , & V_186 , & V_276 , & V_420 ) ;
return F_210 ( V_2 , V_413 , V_306 , V_186 , V_276 , V_420 ) ;
}
static int F_211 ( void )
{
return F_212 () ;
}
static int T_7 F_213 ( void )
{
F_198 () ;
F_214 ( & V_421 ) ;
return 0 ;
}
int F_215 ( struct V_1 * V_10 )
{
int line ;
struct V_1 * V_2 ;
for ( line = 0 ; line < V_399 ; line ++ ) {
V_2 = & V_395 [ line ] . V_2 ;
if ( F_216 ( V_10 , V_2 ) )
return line ;
}
return - V_285 ;
}
int T_7 F_217 ( struct V_1 * V_2 )
{
struct V_1 * V_10 ;
if ( V_2 -> line >= F_193 ( V_395 ) )
return - V_285 ;
F_198 () ;
V_10 = & V_395 [ V_2 -> line ] . V_2 ;
V_10 -> V_17 = V_2 -> V_17 ;
V_10 -> V_14 = V_2 -> V_14 ;
V_10 -> V_151 = V_2 -> V_151 ;
V_10 -> V_251 = V_2 -> V_251 ;
V_10 -> V_65 = V_2 -> V_65 ;
V_10 -> V_140 = V_2 -> V_140 ;
V_10 -> V_13 = V_2 -> V_13 ;
V_10 -> V_20 = V_2 -> V_20 ;
V_10 -> V_108 = V_2 -> V_108 ;
V_10 -> V_130 = V_2 -> V_130 ;
V_10 -> V_422 = V_2 -> V_422 ;
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
void F_218 ( int line )
{
F_219 ( & V_3 , & V_395 [ line ] . V_2 ) ;
}
void F_220 ( int line )
{
struct V_5 * V_6 = & V_395 [ line ] ;
struct V_1 * V_2 = & V_6 -> V_2 ;
if ( V_6 -> V_36 & V_115 ) {
F_75 ( V_2 , V_30 , 0xE0 ) ;
F_57 ( V_6 ) ;
F_75 ( V_2 , V_30 , 0 ) ;
V_2 -> V_65 = 921600 * 16 ;
}
F_221 ( & V_3 , V_2 ) ;
}
static int F_222 ( struct V_423 * V_44 )
{
struct V_424 * V_10 = F_223 ( & V_44 -> V_44 ) ;
struct V_5 V_425 ;
int V_221 , V_137 , V_398 = 0 ;
memset ( & V_425 , 0 , sizeof( V_425 ) ) ;
if ( V_404 )
V_398 = V_245 ;
for ( V_137 = 0 ; V_10 && V_10 -> V_108 != 0 ; V_10 ++ , V_137 ++ ) {
V_425 . V_2 . V_17 = V_10 -> V_17 ;
V_425 . V_2 . V_14 = V_10 -> V_14 ;
V_425 . V_2 . V_151 = V_10 -> V_151 ;
V_425 . V_2 . V_251 = V_10 -> V_251 ;
V_425 . V_2 . V_65 = V_10 -> V_65 ;
V_425 . V_2 . V_13 = V_10 -> V_13 ;
V_425 . V_2 . V_20 = V_10 -> V_20 ;
V_425 . V_2 . V_108 = V_10 -> V_108 ;
V_425 . V_2 . V_130 = V_10 -> V_130 ;
V_425 . V_2 . V_16 = V_10 -> V_16 ;
V_425 . V_2 . V_422 = V_10 -> V_422 ;
V_425 . V_2 . type = V_10 -> type ;
V_425 . V_2 . F_3 = V_10 -> F_3 ;
V_425 . V_2 . F_5 = V_10 -> F_5 ;
V_425 . V_2 . V_28 = V_10 -> V_28 ;
V_425 . V_2 . V_426 = V_10 -> V_426 ;
V_425 . V_2 . V_349 = V_10 -> V_349 ;
V_425 . V_2 . V_354 = V_10 -> V_354 ;
V_425 . V_2 . V_44 = & V_44 -> V_44 ;
V_425 . V_2 . V_251 |= V_398 ;
V_221 = F_224 ( & V_425 ) ;
if ( V_221 < 0 ) {
F_225 ( & V_44 -> V_44 , L_30
L_31 , V_137 ,
V_10 -> V_17 , ( unsigned long long ) V_10 -> V_130 ,
V_10 -> V_151 , V_221 ) ;
}
}
return 0 ;
}
static int F_226 ( struct V_423 * V_44 )
{
int V_137 ;
for ( V_137 = 0 ; V_137 < V_399 ; V_137 ++ ) {
struct V_5 * V_6 = & V_395 [ V_137 ] ;
if ( V_6 -> V_2 . V_44 == & V_44 -> V_44 )
F_227 ( V_137 ) ;
}
return 0 ;
}
static int F_228 ( struct V_423 * V_44 , T_8 V_193 )
{
int V_137 ;
for ( V_137 = 0 ; V_137 < V_400 ; V_137 ++ ) {
struct V_5 * V_6 = & V_395 [ V_137 ] ;
if ( V_6 -> V_2 . type != V_134 && V_6 -> V_2 . V_44 == & V_44 -> V_44 )
F_219 ( & V_3 , & V_6 -> V_2 ) ;
}
return 0 ;
}
static int F_229 ( struct V_423 * V_44 )
{
int V_137 ;
for ( V_137 = 0 ; V_137 < V_400 ; V_137 ++ ) {
struct V_5 * V_6 = & V_395 [ V_137 ] ;
if ( V_6 -> V_2 . type != V_134 && V_6 -> V_2 . V_44 == & V_44 -> V_44 )
F_220 ( V_137 ) ;
}
return 0 ;
}
static struct V_5 * F_230 ( struct V_1 * V_2 )
{
int V_137 ;
for ( V_137 = 0 ; V_137 < V_399 ; V_137 ++ )
if ( F_216 ( & V_395 [ V_137 ] . V_2 , V_2 ) )
return & V_395 [ V_137 ] ;
V_137 = V_2 -> line ;
if ( V_137 < V_399 && V_395 [ V_137 ] . V_2 . type == V_134 &&
V_395 [ V_137 ] . V_2 . V_17 == 0 )
return & V_395 [ V_137 ] ;
for ( V_137 = 0 ; V_137 < V_399 ; V_137 ++ )
if ( V_395 [ V_137 ] . V_2 . type == V_134 &&
V_395 [ V_137 ] . V_2 . V_17 == 0 )
return & V_395 [ V_137 ] ;
for ( V_137 = 0 ; V_137 < V_399 ; V_137 ++ )
if ( V_395 [ V_137 ] . V_2 . type == V_134 )
return & V_395 [ V_137 ] ;
return NULL ;
}
int F_224 ( struct V_5 * V_6 )
{
struct V_5 * V_425 ;
int V_221 = - V_427 ;
if ( V_6 -> V_2 . V_65 == 0 )
return - V_364 ;
F_115 ( & V_428 ) ;
V_425 = F_230 ( & V_6 -> V_2 ) ;
if ( V_425 && V_425 -> V_2 . type != V_284 ) {
if ( V_425 -> V_2 . V_44 )
F_231 ( & V_3 , & V_425 -> V_2 ) ;
V_425 -> V_2 . V_17 = V_6 -> V_2 . V_17 ;
V_425 -> V_2 . V_14 = V_6 -> V_2 . V_14 ;
V_425 -> V_2 . V_151 = V_6 -> V_2 . V_151 ;
V_425 -> V_2 . V_251 = V_6 -> V_2 . V_251 ;
V_425 -> V_2 . V_65 = V_6 -> V_2 . V_65 ;
V_425 -> V_2 . V_140 = V_6 -> V_2 . V_140 ;
V_425 -> V_2 . V_13 = V_6 -> V_2 . V_13 ;
V_425 -> V_2 . V_20 = V_6 -> V_2 . V_20 ;
V_425 -> V_2 . V_108 = V_6 -> V_2 . V_108 | V_429 ;
V_425 -> V_95 = V_6 -> V_95 ;
V_425 -> V_2 . V_130 = V_6 -> V_2 . V_130 ;
V_425 -> V_2 . V_422 = V_6 -> V_2 . V_422 ;
V_425 -> V_2 . V_140 = V_6 -> V_2 . V_140 ;
V_425 -> V_143 = V_6 -> V_143 ;
V_425 -> V_36 = V_6 -> V_36 ;
V_425 -> V_2 . V_167 = V_6 -> V_2 . V_167 ;
V_425 -> V_2 . V_168 = V_6 -> V_2 . V_168 ;
V_425 -> V_2 . V_430 = V_6 -> V_2 . V_430 ;
V_425 -> V_2 . V_431 = V_6 -> V_2 . V_431 ;
if ( V_425 -> V_2 . V_140 && ! V_425 -> V_143 )
V_425 -> V_143 = V_425 -> V_2 . V_140 ;
if ( V_6 -> V_2 . V_44 )
V_425 -> V_2 . V_44 = V_6 -> V_2 . V_44 ;
if ( V_6 -> V_2 . V_108 & V_411 )
F_201 ( V_425 , V_6 -> V_2 . type ) ;
F_26 ( & V_425 -> V_2 ) ;
if ( V_6 -> V_2 . F_3 )
V_425 -> V_2 . F_3 = V_6 -> V_2 . F_3 ;
if ( V_6 -> V_2 . F_5 )
V_425 -> V_2 . F_5 = V_6 -> V_2 . F_5 ;
if ( V_6 -> V_2 . V_28 )
V_425 -> V_2 . V_28 = V_6 -> V_2 . V_28 ;
if ( V_6 -> V_2 . V_349 )
V_425 -> V_2 . V_349 = V_6 -> V_2 . V_349 ;
if ( V_6 -> V_2 . V_304 )
V_425 -> V_2 . V_304 = V_6 -> V_2 . V_304 ;
if ( V_6 -> V_2 . V_305 )
V_425 -> V_2 . V_305 = V_6 -> V_2 . V_305 ;
if ( V_6 -> V_2 . V_354 )
V_425 -> V_2 . V_354 = V_6 -> V_2 . V_354 ;
if ( V_6 -> V_2 . V_426 )
V_425 -> V_2 . V_426 = V_6 -> V_2 . V_426 ;
if ( V_6 -> V_18 )
V_425 -> V_18 = V_6 -> V_18 ;
if ( V_6 -> V_19 )
V_425 -> V_19 = V_6 -> V_19 ;
if ( V_6 -> V_160 ) {
V_425 -> V_160 = V_6 -> V_160 ;
if ( ! V_425 -> V_160 -> V_161 )
V_425 -> V_160 -> V_161 = V_432 ;
if ( ! V_425 -> V_160 -> V_218 )
V_425 -> V_160 -> V_218 = V_433 ;
}
if ( V_396 != NULL )
V_396 ( 0 , & V_425 -> V_2 ,
& V_425 -> V_36 ) ;
V_221 = F_203 ( & V_3 , & V_425 -> V_2 ) ;
if ( V_221 == 0 )
V_221 = V_425 -> V_2 . line ;
}
F_119 ( & V_428 ) ;
return V_221 ;
}
void F_227 ( int line )
{
struct V_5 * V_425 = & V_395 [ line ] ;
F_115 ( & V_428 ) ;
F_231 ( & V_3 , & V_425 -> V_2 ) ;
if ( V_434 ) {
V_425 -> V_2 . V_108 &= ~ V_429 ;
V_425 -> V_2 . type = V_134 ;
V_425 -> V_2 . V_44 = & V_434 -> V_44 ;
V_425 -> V_36 = V_141 [ V_425 -> V_2 . type ] . V_108 ;
F_203 ( & V_3 , & V_425 -> V_2 ) ;
} else {
V_425 -> V_2 . V_44 = NULL ;
}
F_119 ( & V_428 ) ;
}
static int T_7 F_232 ( void )
{
int V_221 ;
F_198 () ;
F_65 ( V_287 L_32
L_33 , V_399 ,
V_404 ? L_34 : L_35 ) ;
#ifdef F_233
V_221 = F_234 ( & V_3 , V_400 ) ;
#else
V_3 . V_435 = V_400 ;
V_221 = F_235 ( & V_3 ) ;
#endif
if ( V_221 )
goto V_53;
V_221 = F_236 () ;
if ( V_221 )
goto V_436;
V_434 = F_237 ( L_36 ,
V_437 ) ;
if ( ! V_434 ) {
V_221 = - V_250 ;
goto V_438;
}
V_221 = F_238 ( V_434 ) ;
if ( V_221 )
goto V_439;
F_202 ( & V_3 , & V_434 -> V_44 ) ;
V_221 = F_239 ( & V_440 ) ;
if ( V_221 == 0 )
goto V_53;
F_240 ( V_434 ) ;
V_439:
F_241 ( V_434 ) ;
V_438:
F_242 () ;
V_436:
#ifdef F_233
F_243 ( & V_3 , V_400 ) ;
#else
F_244 ( & V_3 ) ;
#endif
V_53:
return V_221 ;
}
static void T_9 F_245 ( void )
{
struct V_423 * V_441 = V_434 ;
V_434 = NULL ;
F_246 ( & V_440 ) ;
F_247 ( V_441 ) ;
F_242 () ;
#ifdef F_233
F_243 ( & V_3 , V_400 ) ;
#else
F_244 ( & V_3 ) ;
#endif
}
static void T_10 F_248 ( void )
{
#undef V_442
#define V_442 "8250_core."
F_249 ( V_404 , & V_443 , & V_404 , 0644 ) ;
F_249 ( V_399 , & V_443 , & V_399 , 0644 ) ;
F_249 ( V_300 , & V_443 , & V_300 , 0644 ) ;
#ifdef F_64
F_250 ( V_442 , V_139 ,
& V_444 , . V_445 = & V_446 ,
0444 , - 1 , 0 ) ;
#endif
}
