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
F_5 ( V_6 , V_30 , 0 ) ;
F_5 ( V_6 , V_38 , V_39 |
V_113 ) ;
V_101 = F_3 ( V_6 , V_114 ) >> 5 ;
F_5 ( V_6 , V_38 , 0 ) ;
F_5 ( V_6 , V_30 , 0 ) ;
if ( V_101 == 7 )
V_6 -> V_2 . type = V_115 ;
else
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
unsigned short V_116 ;
F_5 ( V_6 , V_30 , 0xE0 ) ;
V_116 = F_49 ( V_6 ) ;
V_116 <<= 3 ;
if ( F_57 ( V_6 ) )
F_50 ( V_6 , V_116 ) ;
F_5 ( V_6 , V_30 , 0 ) ;
V_6 -> V_2 . V_65 = 921600 * 16 ;
V_6 -> V_2 . type = V_117 ;
V_6 -> V_36 |= V_118 ;
return;
}
}
F_5 ( V_6 , V_30 , 0 ) ;
F_5 ( V_6 , V_38 , V_39 | V_113 ) ;
V_101 = F_3 ( V_6 , V_114 ) >> 5 ;
F_5 ( V_6 , V_38 , V_39 ) ;
F_5 ( V_6 , V_30 , V_78 ) ;
F_5 ( V_6 , V_38 , V_39 | V_113 ) ;
V_102 = F_3 ( V_6 , V_114 ) >> 5 ;
F_5 ( V_6 , V_38 , V_39 ) ;
F_5 ( V_6 , V_30 , 0 ) ;
F_54 ( L_7 , V_101 , V_102 ) ;
if ( V_101 == 6 && V_102 == 7 ) {
V_6 -> V_2 . type = V_119 ;
V_6 -> V_36 |= V_111 | V_54 ;
return;
}
V_106 = F_3 ( V_6 , V_59 ) ;
F_5 ( V_6 , V_59 , V_106 & ~ V_120 ) ;
if ( ! ( F_3 ( V_6 , V_59 ) & V_120 ) ) {
F_5 ( V_6 , V_59 , V_106 | V_120 ) ;
if ( F_3 ( V_6 , V_59 ) & V_120 ) {
F_54 ( L_8 ) ;
V_6 -> V_2 . type = V_121 ;
V_6 -> V_36 |= V_122 | V_123 ;
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
V_6 -> V_2 . type = V_124 ;
V_6 -> V_36 |= V_111 ;
}
}
static void F_60 ( struct V_5 * V_6 , unsigned int V_125 )
{
unsigned char V_101 , V_100 , V_126 , V_127 ;
unsigned char V_128 , V_129 ;
struct V_1 * V_2 = & V_6 -> V_2 ;
unsigned long V_108 ;
unsigned int V_130 ;
if ( ! V_2 -> V_17 && ! V_2 -> V_131 && ! V_2 -> V_14 )
return;
F_54 ( L_11 ,
F_1 ( V_2 ) , V_2 -> V_17 , V_2 -> V_14 ) ;
F_61 ( & V_2 -> V_68 , V_108 ) ;
V_6 -> V_36 = 0 ;
V_6 -> V_95 = 0 ;
if ( ! ( V_2 -> V_108 & V_132 ) ) {
V_100 = F_3 ( V_6 , V_59 ) ;
F_5 ( V_6 , V_59 , 0 ) ;
#ifdef F_62
F_13 ( 0xff , 0x080 ) ;
#endif
V_126 = F_3 ( V_6 , V_59 ) & 0x0f ;
F_5 ( V_6 , V_59 , 0x0F ) ;
#ifdef F_62
F_13 ( 0 , 0x080 ) ;
#endif
V_127 = F_3 ( V_6 , V_59 ) & 0x0f ;
F_5 ( V_6 , V_59 , V_100 ) ;
if ( V_126 != 0 || V_127 != 0x0F ) {
F_63 ( & V_2 -> V_68 , V_108 ) ;
F_54 ( L_12 ,
V_126 , V_127 ) ;
goto V_53;
}
}
V_129 = F_3 ( V_6 , V_76 ) ;
V_128 = F_3 ( V_6 , V_30 ) ;
if ( ! ( V_2 -> V_108 & V_133 ) ) {
F_5 ( V_6 , V_76 , V_77 | 0x0A ) ;
V_101 = F_3 ( V_6 , V_134 ) & 0xF0 ;
F_5 ( V_6 , V_76 , V_129 ) ;
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
V_100 = F_3 ( V_6 , V_114 ) >> 6 ;
switch ( V_100 ) {
case 0 :
F_55 ( V_6 ) ;
break;
case 1 :
V_2 -> type = V_135 ;
break;
case 2 :
V_2 -> type = V_136 ;
break;
case 3 :
F_59 ( V_6 ) ;
break;
}
#ifdef F_64
if ( V_2 -> type == V_107 && V_125 & V_137 ) {
int V_138 ;
for ( V_138 = 0 ; V_138 < V_139 ; ++ V_138 ) {
if ( V_140 [ V_138 ] == V_2 -> V_17 && F_43 ( V_6 ) ) {
V_2 -> type = V_67 ;
break;
}
}
}
#endif
F_5 ( V_6 , V_30 , V_128 ) ;
V_2 -> V_141 = V_142 [ V_6 -> V_2 . type ] . V_143 ;
V_130 = V_6 -> V_36 ;
V_6 -> V_36 = V_142 [ V_2 -> type ] . V_108 ;
V_6 -> V_144 = V_142 [ V_2 -> type ] . V_144 ;
if ( V_2 -> type == V_135 )
goto V_145;
#ifdef F_64
if ( V_2 -> type == V_67 )
F_5 ( V_6 , V_69 , 0 ) ;
#endif
F_5 ( V_6 , V_76 , V_129 ) ;
F_32 ( V_6 ) ;
F_3 ( V_6 , V_82 ) ;
if ( V_6 -> V_36 & V_122 )
F_5 ( V_6 , V_59 , V_120 ) ;
else
F_5 ( V_6 , V_59 , 0 ) ;
V_145:
F_63 ( & V_2 -> V_68 , V_108 ) ;
if ( V_6 -> V_36 != V_130 ) {
F_65 ( V_146
L_14 ,
F_1 ( V_2 ) , V_130 ,
V_6 -> V_36 ) ;
}
V_53:
F_54 ( L_15 , V_100 ) ;
F_54 ( L_16 , V_142 [ V_2 -> type ] . V_147 ) ;
}
static void F_66 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = & V_6 -> V_2 ;
unsigned char V_129 , V_148 ;
unsigned char V_149 = 0 ;
unsigned int V_150 = 0 ;
unsigned long V_151 ;
int V_152 ;
if ( V_2 -> V_108 & V_153 ) {
V_150 = ( V_2 -> V_17 & 0xfe0 ) | 0x1f ;
V_149 = F_67 ( V_150 ) ;
F_68 ( 0x80 , V_150 ) ;
F_67 ( V_150 ) ;
}
F_69 ( F_70 () ) ;
V_129 = F_3 ( V_6 , V_76 ) ;
V_148 = F_3 ( V_6 , V_59 ) ;
F_5 ( V_6 , V_76 , V_154 | V_155 ) ;
V_151 = F_70 () ;
F_5 ( V_6 , V_76 , 0 ) ;
F_71 ( 10 ) ;
if ( V_2 -> V_108 & V_153 ) {
F_5 ( V_6 , V_76 ,
V_156 | V_157 ) ;
} else {
F_5 ( V_6 , V_76 ,
V_156 | V_157 | V_155 ) ;
}
F_5 ( V_6 , V_59 , 0x0f ) ;
F_3 ( V_6 , V_80 ) ;
F_3 ( V_6 , V_82 ) ;
F_3 ( V_6 , V_114 ) ;
F_3 ( V_6 , V_134 ) ;
F_5 ( V_6 , V_79 , 0xFF ) ;
F_71 ( 20 ) ;
V_152 = F_69 ( V_151 ) ;
F_5 ( V_6 , V_76 , V_129 ) ;
F_5 ( V_6 , V_59 , V_148 ) ;
if ( V_2 -> V_108 & V_153 )
F_68 ( V_149 , V_150 ) ;
V_2 -> V_152 = ( V_152 > 0 ) ? V_152 : 0 ;
}
static inline void F_72 ( struct V_5 * V_10 )
{
if ( V_10 -> V_158 & V_159 ) {
V_10 -> V_158 &= ~ V_159 ;
F_5 ( V_10 , V_59 , V_10 -> V_158 ) ;
F_41 ( V_10 ) ;
}
}
static void F_73 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_27 ( V_2 ) ;
F_34 ( V_6 ) ;
F_72 ( V_6 ) ;
if ( V_2 -> type == V_94 ) {
V_6 -> V_34 |= V_160 ;
F_30 ( V_6 , V_33 , V_6 -> V_34 ) ;
}
F_36 ( V_6 ) ;
}
static void F_74 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_27 ( V_2 ) ;
F_39 ( V_6 ) ;
if ( V_6 -> V_161 && ! V_6 -> V_161 -> V_162 ( V_6 ) )
return;
if ( ! ( V_6 -> V_158 & V_159 ) ) {
V_6 -> V_158 |= V_159 ;
F_75 ( V_2 , V_59 , V_6 -> V_158 ) ;
if ( V_6 -> V_95 & V_163 ) {
unsigned char V_164 ;
V_164 = F_3 ( V_6 , V_80 ) ;
V_6 -> V_165 |= V_164 & V_166 ;
if ( V_164 & V_167 )
F_76 ( V_6 ) ;
}
}
if ( V_2 -> type == V_94 && V_6 -> V_34 & V_160 ) {
V_6 -> V_34 &= ~ V_160 ;
F_30 ( V_6 , V_33 , V_6 -> V_34 ) ;
}
}
static void F_77 ( struct V_1 * V_2 )
{
V_2 -> V_168 ( V_2 ) ;
}
static void F_78 ( struct V_1 * V_2 )
{
V_2 -> V_169 ( V_2 ) ;
}
static void F_79 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_27 ( V_2 ) ;
F_34 ( V_6 ) ;
V_6 -> V_158 &= ~ ( V_170 | V_171 ) ;
V_6 -> V_2 . V_172 &= ~ V_81 ;
F_75 ( V_2 , V_59 , V_6 -> V_158 ) ;
F_36 ( V_6 ) ;
}
static void F_80 ( struct V_1 * V_2 )
{
struct V_5 * V_6 =
F_81 ( V_2 , struct V_5 , V_2 ) ;
if ( V_6 -> V_95 & V_173 )
return;
V_6 -> V_158 &= ~ V_174 ;
F_75 ( V_2 , V_59 , V_6 -> V_158 ) ;
}
static void F_82 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_27 ( V_2 ) ;
if ( V_6 -> V_95 & V_173 )
return;
V_6 -> V_158 |= V_174 ;
F_34 ( V_6 ) ;
F_75 ( V_2 , V_59 , V_6 -> V_158 ) ;
F_36 ( V_6 ) ;
}
unsigned char
F_83 ( struct V_5 * V_6 , unsigned char V_164 )
{
struct V_1 * V_2 = & V_6 -> V_2 ;
unsigned char V_175 ;
int V_176 = 256 ;
char V_177 ;
do {
if ( F_84 ( V_164 & V_81 ) )
V_175 = F_3 ( V_6 , V_82 ) ;
else
V_175 = 0 ;
V_177 = V_178 ;
V_2 -> V_179 . V_180 ++ ;
V_164 |= V_6 -> V_165 ;
V_6 -> V_165 = 0 ;
if ( F_85 ( V_164 & V_181 ) ) {
if ( V_164 & V_182 ) {
V_164 &= ~ ( V_183 | V_184 ) ;
V_2 -> V_179 . V_185 ++ ;
if ( F_86 ( V_2 ) )
goto V_186;
} else if ( V_164 & V_184 )
V_2 -> V_179 . V_187 ++ ;
else if ( V_164 & V_183 )
V_2 -> V_179 . V_188 ++ ;
if ( V_164 & V_189 )
V_2 -> V_179 . V_190 ++ ;
V_164 &= V_2 -> V_172 ;
if ( V_164 & V_182 ) {
F_87 ( L_17 ) ;
V_177 = V_191 ;
} else if ( V_164 & V_184 )
V_177 = V_192 ;
else if ( V_164 & V_183 )
V_177 = V_193 ;
}
if ( F_88 ( V_2 , V_175 ) )
goto V_186;
F_89 ( V_2 , V_164 , V_189 , V_175 , V_177 ) ;
V_186:
V_164 = F_3 ( V_6 , V_80 ) ;
} while ( ( V_164 & ( V_81 | V_182 ) ) && ( -- V_176 > 0 ) );
F_90 ( & V_2 -> V_68 ) ;
F_91 ( & V_2 -> V_194 -> V_2 ) ;
F_92 ( & V_2 -> V_68 ) ;
return V_164 ;
}
void F_76 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = & V_6 -> V_2 ;
struct V_195 * V_196 = & V_2 -> V_194 -> V_196 ;
int V_75 ;
if ( V_2 -> V_197 ) {
F_5 ( V_6 , V_79 , V_2 -> V_197 ) ;
V_2 -> V_179 . V_198 ++ ;
V_2 -> V_197 = 0 ;
return;
}
if ( F_93 ( V_2 ) ) {
F_73 ( V_2 ) ;
return;
}
if ( F_94 ( V_196 ) ) {
F_72 ( V_6 ) ;
return;
}
V_75 = V_6 -> V_144 ;
do {
F_5 ( V_6 , V_79 , V_196 -> V_199 [ V_196 -> V_200 ] ) ;
V_196 -> V_200 = ( V_196 -> V_200 + 1 ) & ( V_201 - 1 ) ;
V_2 -> V_179 . V_198 ++ ;
if ( F_94 ( V_196 ) )
break;
if ( V_6 -> V_36 & V_202 ) {
if ( ( F_95 ( V_2 , V_80 ) & V_203 ) !=
V_203 )
break;
}
} while ( -- V_75 > 0 );
if ( F_96 ( V_196 ) < V_204 )
F_97 ( V_2 ) ;
F_87 ( L_18 ) ;
if ( F_94 ( V_196 ) && ! ( V_6 -> V_36 & V_43 ) )
F_72 ( V_6 ) ;
}
unsigned int F_98 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = & V_6 -> V_2 ;
unsigned int V_105 = F_3 ( V_6 , V_134 ) ;
V_105 |= V_6 -> V_205 ;
V_6 -> V_205 = 0 ;
if ( V_105 & V_206 && V_6 -> V_158 & V_174 &&
V_2 -> V_194 != NULL ) {
if ( V_105 & V_207 )
V_2 -> V_179 . V_208 ++ ;
if ( V_105 & V_209 )
V_2 -> V_179 . V_210 ++ ;
if ( V_105 & V_211 )
F_99 ( V_2 , V_105 & V_212 ) ;
if ( V_105 & V_213 )
F_100 ( V_2 , V_105 & V_214 ) ;
F_101 ( & V_2 -> V_194 -> V_2 . V_215 ) ;
}
return V_105 ;
}
int F_102 ( struct V_1 * V_2 , unsigned int V_216 )
{
unsigned char V_105 ;
unsigned long V_108 ;
struct V_5 * V_6 = F_27 ( V_2 ) ;
int V_217 = 0 ;
if ( V_216 & V_218 )
return 0 ;
F_61 ( & V_2 -> V_68 , V_108 ) ;
V_105 = F_95 ( V_2 , V_80 ) ;
F_87 ( L_19 , V_105 ) ;
if ( V_105 & ( V_81 | V_182 ) ) {
if ( V_6 -> V_161 )
V_217 = V_6 -> V_161 -> V_219 ( V_6 , V_216 ) ;
if ( ! V_6 -> V_161 || V_217 )
V_105 = F_83 ( V_6 , V_105 ) ;
}
F_98 ( V_6 ) ;
if ( ( ! V_6 -> V_161 || ( V_6 -> V_161 && V_6 -> V_161 -> V_220 ) ) &&
( V_105 & V_167 ) )
F_76 ( V_6 ) ;
F_63 ( & V_2 -> V_68 , V_108 ) ;
return 1 ;
}
static int V_29 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_27 ( V_2 ) ;
unsigned int V_216 ;
int V_221 ;
F_34 ( V_6 ) ;
V_216 = F_95 ( V_2 , V_114 ) ;
V_221 = F_102 ( V_2 , V_216 ) ;
F_36 ( V_6 ) ;
return V_221 ;
}
static int F_103 ( struct V_1 * V_2 )
{
unsigned char V_222 , V_223 , V_224 , V_225 ;
unsigned int V_216 = F_95 ( V_2 , V_114 ) ;
int V_221 ;
V_221 = F_102 ( V_2 , V_216 ) ;
if ( ( V_2 -> type == V_50 ) ||
( V_2 -> type == V_51 ) ) {
V_222 = F_95 ( V_2 , 0x80 ) ;
V_223 = F_95 ( V_2 , 0x81 ) ;
V_224 = F_95 ( V_2 , 0x82 ) ;
V_225 = F_95 ( V_2 , 0x83 ) ;
}
return V_221 ;
}
static T_2 F_104 ( int V_152 , void * V_226 )
{
struct V_227 * V_138 = V_226 ;
struct V_228 * V_229 , * V_230 = NULL ;
int V_231 = 0 , V_232 = 0 ;
F_87 ( L_20 , V_152 ) ;
F_92 ( & V_138 -> V_68 ) ;
V_229 = V_138 -> V_233 ;
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
if ( V_229 == V_138 -> V_233 && V_231 ++ > V_236 ) {
F_106 ( V_237
L_21 , V_152 ) ;
break;
}
} while ( V_229 != V_230 );
F_90 ( & V_138 -> V_68 ) ;
F_87 ( L_22 ) ;
return F_107 ( V_232 ) ;
}
static void F_108 ( struct V_227 * V_138 , struct V_5 * V_6 )
{
F_45 ( & V_138 -> V_68 ) ;
if ( ! F_109 ( V_138 -> V_233 ) ) {
if ( V_138 -> V_233 == & V_6 -> V_234 )
V_138 -> V_233 = V_138 -> V_233 -> V_235 ;
F_110 ( & V_6 -> V_234 ) ;
} else {
F_111 ( V_138 -> V_233 != & V_6 -> V_234 ) ;
V_138 -> V_233 = NULL ;
}
F_46 ( & V_138 -> V_68 ) ;
if ( V_138 -> V_233 == NULL ) {
F_112 ( & V_138 -> V_238 ) ;
F_113 ( V_138 ) ;
}
}
static int F_114 ( struct V_5 * V_6 )
{
struct V_239 * V_240 ;
struct V_241 * V_242 ;
struct V_227 * V_138 ;
int V_221 , V_243 = V_6 -> V_2 . V_108 & V_244 ? V_245 : 0 ;
F_115 ( & V_246 ) ;
V_240 = & V_247 [ V_6 -> V_2 . V_152 % V_248 ] ;
F_116 (n, h) {
V_138 = F_117 ( V_242 , struct V_227 , V_238 ) ;
if ( V_138 -> V_152 == V_6 -> V_2 . V_152 )
break;
}
if ( V_242 == NULL ) {
V_138 = F_118 ( sizeof( struct V_227 ) , V_249 ) ;
if ( V_138 == NULL ) {
F_119 ( & V_246 ) ;
return - V_250 ;
}
F_120 ( & V_138 -> V_68 ) ;
V_138 -> V_152 = V_6 -> V_2 . V_152 ;
F_121 ( & V_138 -> V_238 , V_240 ) ;
}
F_119 ( & V_246 ) ;
F_45 ( & V_138 -> V_68 ) ;
if ( V_138 -> V_233 ) {
F_122 ( & V_6 -> V_234 , V_138 -> V_233 ) ;
F_46 ( & V_138 -> V_68 ) ;
V_221 = 0 ;
} else {
F_123 ( & V_6 -> V_234 ) ;
V_138 -> V_233 = & V_6 -> V_234 ;
F_46 ( & V_138 -> V_68 ) ;
V_243 |= V_6 -> V_2 . V_251 ;
V_221 = F_124 ( V_6 -> V_2 . V_152 , F_104 ,
V_243 , L_23 , V_138 ) ;
if ( V_221 < 0 )
F_108 ( V_138 , V_6 ) ;
}
return V_221 ;
}
static void F_125 ( struct V_5 * V_6 )
{
struct V_227 * V_138 ;
struct V_241 * V_242 ;
struct V_239 * V_240 ;
F_115 ( & V_246 ) ;
V_240 = & V_247 [ V_6 -> V_2 . V_152 % V_248 ] ;
F_116 (n, h) {
V_138 = F_117 ( V_242 , struct V_227 , V_238 ) ;
if ( V_138 -> V_152 == V_6 -> V_2 . V_152 )
break;
}
F_111 ( V_242 == NULL ) ;
F_111 ( V_138 -> V_233 == NULL ) ;
if ( F_109 ( V_138 -> V_233 ) )
F_126 ( V_6 -> V_2 . V_152 , V_138 ) ;
F_108 ( V_138 , V_6 ) ;
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
unsigned int V_216 , V_158 = 0 , V_164 ;
unsigned long V_108 ;
F_61 ( & V_6 -> V_2 . V_68 , V_108 ) ;
if ( V_6 -> V_2 . V_152 ) {
V_158 = F_3 ( V_6 , V_59 ) ;
F_5 ( V_6 , V_59 , 0 ) ;
}
V_216 = F_3 ( V_6 , V_114 ) ;
V_164 = F_3 ( V_6 , V_80 ) ;
V_6 -> V_165 |= V_164 & V_166 ;
if ( ( V_216 & V_218 ) && ( V_6 -> V_158 & V_159 ) &&
( ! F_94 ( & V_6 -> V_2 . V_194 -> V_196 ) || V_6 -> V_2 . V_197 ) &&
( V_164 & V_167 ) ) {
V_216 &= ~ ( V_255 | V_218 ) ;
V_216 |= V_256 ;
}
if ( ! ( V_216 & V_218 ) )
F_76 ( V_6 ) ;
if ( V_6 -> V_2 . V_152 )
F_5 ( V_6 , V_59 , V_158 ) ;
F_63 ( & V_6 -> V_2 . V_68 , V_108 ) ;
F_128 ( & V_6 -> V_253 ,
V_254 + F_129 ( & V_6 -> V_2 ) + V_257 / 5 ) ;
}
static unsigned int F_131 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_27 ( V_2 ) ;
unsigned long V_108 ;
unsigned int V_164 ;
F_34 ( V_6 ) ;
F_61 ( & V_2 -> V_68 , V_108 ) ;
V_164 = F_95 ( V_2 , V_80 ) ;
V_6 -> V_165 |= V_164 & V_166 ;
F_63 ( & V_2 -> V_68 , V_108 ) ;
F_36 ( V_6 ) ;
return ( V_164 & V_203 ) == V_203 ? V_258 : 0 ;
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
if ( V_105 & V_212 )
V_221 |= V_259 ;
if ( V_105 & V_260 )
V_221 |= V_261 ;
if ( V_105 & V_262 )
V_221 |= V_263 ;
if ( V_105 & V_214 )
V_221 |= V_264 ;
return V_221 ;
}
void F_133 ( struct V_1 * V_2 , unsigned int V_265 )
{
struct V_5 * V_6 = F_27 ( V_2 ) ;
unsigned char V_266 = 0 ;
if ( V_265 & V_267 )
V_266 |= V_157 ;
if ( V_265 & V_268 )
V_266 |= V_156 ;
if ( V_265 & V_269 )
V_266 |= V_154 ;
if ( V_265 & V_270 )
V_266 |= V_155 ;
if ( V_265 & V_271 )
V_266 |= V_77 ;
V_266 = ( V_266 & V_6 -> V_272 ) | V_6 -> V_273 | V_6 -> V_266 ;
F_75 ( V_2 , V_76 , V_266 ) ;
}
static void F_134 ( struct V_1 * V_2 , unsigned int V_265 )
{
if ( V_2 -> V_274 )
return V_2 -> V_274 ( V_2 , V_265 ) ;
return F_133 ( V_2 , V_265 ) ;
}
static void F_135 ( struct V_1 * V_2 , int V_275 )
{
struct V_5 * V_6 = F_27 ( V_2 ) ;
unsigned long V_108 ;
F_34 ( V_6 ) ;
F_61 ( & V_2 -> V_68 , V_108 ) ;
if ( V_275 == - 1 )
V_6 -> V_48 |= V_276 ;
else
V_6 -> V_48 &= ~ V_276 ;
F_75 ( V_2 , V_30 , V_6 -> V_48 ) ;
F_63 ( & V_2 -> V_68 , V_108 ) ;
F_36 ( V_6 ) ;
}
static void F_136 ( struct V_5 * V_6 , int V_277 )
{
unsigned int V_105 , V_278 = 10000 ;
for (; ; ) {
V_105 = F_3 ( V_6 , V_80 ) ;
V_6 -> V_165 |= V_105 & V_166 ;
if ( ( V_105 & V_277 ) == V_277 )
break;
if ( -- V_278 == 0 )
break;
F_71 ( 1 ) ;
}
if ( V_6 -> V_2 . V_108 & V_279 ) {
unsigned int V_278 ;
for ( V_278 = 1000000 ; V_278 ; V_278 -- ) {
unsigned int V_280 = F_3 ( V_6 , V_134 ) ;
V_6 -> V_205 |= V_280 & V_281 ;
if ( V_280 & V_214 )
break;
F_71 ( 1 ) ;
F_137 () ;
}
}
}
static int F_138 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_27 ( V_2 ) ;
unsigned char V_164 ;
int V_105 ;
F_34 ( V_6 ) ;
V_164 = F_95 ( V_2 , V_80 ) ;
if ( ! ( V_164 & V_81 ) ) {
V_105 = V_282 ;
goto V_53;
}
V_105 = F_95 ( V_2 , V_82 ) ;
V_53:
F_36 ( V_6 ) ;
return V_105 ;
}
static void F_139 ( struct V_1 * V_2 ,
unsigned char V_283 )
{
unsigned int V_158 ;
struct V_5 * V_6 = F_27 ( V_2 ) ;
F_34 ( V_6 ) ;
V_158 = F_95 ( V_2 , V_59 ) ;
if ( V_6 -> V_36 & V_122 )
F_75 ( V_2 , V_59 , V_120 ) ;
else
F_75 ( V_2 , V_59 , 0 ) ;
F_136 ( V_6 , V_203 ) ;
F_75 ( V_2 , V_79 , V_283 ) ;
F_136 ( V_6 , V_203 ) ;
F_75 ( V_2 , V_59 , V_158 ) ;
F_36 ( V_6 ) ;
}
int F_140 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_27 ( V_2 ) ;
unsigned long V_108 ;
unsigned char V_164 , V_216 ;
int V_284 ;
if ( V_2 -> type == V_285 )
return - V_286 ;
if ( ! V_2 -> V_141 )
V_2 -> V_141 = V_142 [ V_2 -> type ] . V_143 ;
if ( ! V_6 -> V_144 )
V_6 -> V_144 = V_142 [ V_2 -> type ] . V_144 ;
if ( ! V_6 -> V_36 )
V_6 -> V_36 = V_142 [ V_2 -> type ] . V_108 ;
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
F_30 ( V_6 , V_287 , 0 ) ;
F_75 ( V_2 , V_30 , V_57 ) ;
F_75 ( V_2 , V_56 , V_58 ) ;
F_75 ( V_2 , V_30 , 0 ) ;
}
#ifdef F_64
F_44 ( V_6 ) ;
#endif
F_32 ( V_6 ) ;
F_95 ( V_2 , V_80 ) ;
F_95 ( V_2 , V_82 ) ;
F_95 ( V_2 , V_114 ) ;
F_95 ( V_2 , V_134 ) ;
if ( ! ( V_2 -> V_108 & V_132 ) &&
( F_95 ( V_2 , V_80 ) == 0xff ) ) {
F_106 ( V_288 L_24 ,
F_1 ( V_2 ) ) ;
V_284 = - V_286 ;
goto V_53;
}
if ( V_2 -> type == V_97 ) {
unsigned char V_289 ;
F_5 ( V_6 , V_30 , V_57 ) ;
V_289 = F_3 ( V_6 , V_290 ) & ~ ( V_291 | V_292 ) ;
F_75 ( V_2 , V_290 ,
V_289 | V_293 | V_291 ) ;
F_75 ( V_2 , V_294 , V_295 ) ;
F_75 ( V_2 , V_290 ,
V_289 | V_293 | V_292 ) ;
F_75 ( V_2 , V_294 , V_295 ) ;
F_75 ( V_2 , V_30 , 0 ) ;
}
if ( V_2 -> V_152 ) {
unsigned char V_296 ;
F_61 ( & V_2 -> V_68 , V_108 ) ;
if ( V_6 -> V_2 . V_251 & V_245 )
F_141 ( V_2 -> V_152 ) ;
F_136 ( V_6 , V_167 ) ;
F_29 ( V_2 , V_59 , V_159 ) ;
F_71 ( 1 ) ;
V_296 = F_95 ( V_2 , V_114 ) ;
F_75 ( V_2 , V_59 , 0 ) ;
F_29 ( V_2 , V_59 , V_159 ) ;
F_71 ( 1 ) ;
V_216 = F_95 ( V_2 , V_114 ) ;
F_75 ( V_2 , V_59 , 0 ) ;
if ( V_2 -> V_251 & V_245 )
F_142 ( V_2 -> V_152 ) ;
F_63 ( & V_2 -> V_68 , V_108 ) ;
if ( ( ! ( V_296 & V_218 ) && ( V_216 & V_218 ) ) ||
V_6 -> V_2 . V_108 & V_297 ) {
V_6 -> V_95 |= V_298 ;
F_143 ( L_25 ,
F_1 ( V_2 ) ) ;
}
}
if ( V_6 -> V_95 & V_298 ) {
V_6 -> V_253 . V_299 = F_130 ;
V_6 -> V_253 . V_252 = ( unsigned long ) V_6 ;
F_128 ( & V_6 -> V_253 , V_254 +
F_129 ( V_2 ) + V_257 / 5 ) ;
}
if ( ! V_2 -> V_152 ) {
V_6 -> V_253 . V_252 = ( unsigned long ) V_6 ;
F_128 ( & V_6 -> V_253 , V_254 + F_129 ( V_2 ) ) ;
} else {
V_284 = F_114 ( V_6 ) ;
if ( V_284 )
goto V_53;
}
F_75 ( V_2 , V_30 , V_300 ) ;
F_61 ( & V_2 -> V_68 , V_108 ) ;
if ( V_6 -> V_2 . V_108 & V_153 ) {
if ( ! V_6 -> V_2 . V_152 )
V_6 -> V_2 . V_265 |= V_269 ;
} else
if ( V_2 -> V_152 )
V_6 -> V_2 . V_265 |= V_270 ;
F_134 ( V_2 , V_2 -> V_265 ) ;
if ( V_301 || V_6 -> V_2 . V_108 & V_302 )
goto V_303;
F_75 ( V_2 , V_59 , V_159 ) ;
V_164 = F_95 ( V_2 , V_80 ) ;
V_216 = F_95 ( V_2 , V_114 ) ;
F_75 ( V_2 , V_59 , 0 ) ;
if ( V_164 & V_304 && V_216 & V_218 ) {
if ( ! ( V_6 -> V_95 & V_163 ) ) {
V_6 -> V_95 |= V_163 ;
F_143 ( L_26 ,
F_1 ( V_2 ) ) ;
}
} else {
V_6 -> V_95 &= ~ V_163 ;
}
V_303:
F_63 ( & V_2 -> V_68 , V_108 ) ;
F_95 ( V_2 , V_80 ) ;
F_95 ( V_2 , V_82 ) ;
F_95 ( V_2 , V_114 ) ;
F_95 ( V_2 , V_134 ) ;
V_6 -> V_165 = 0 ;
V_6 -> V_205 = 0 ;
if ( V_6 -> V_161 ) {
V_284 = F_144 ( V_6 ) ;
if ( V_284 ) {
F_145 ( L_27 ,
F_1 ( V_2 ) ) ;
V_6 -> V_161 = NULL ;
}
}
V_6 -> V_158 = V_170 | V_171 ;
F_75 ( V_2 , V_59 , V_6 -> V_158 ) ;
if ( V_2 -> V_108 & V_153 ) {
unsigned int V_305 ;
V_305 = ( V_2 -> V_17 & 0xfe0 ) | 0x01f ;
F_68 ( 0x80 , V_305 ) ;
F_67 ( V_305 ) ;
}
V_284 = 0 ;
V_53:
F_36 ( V_6 ) ;
return V_284 ;
}
static int F_146 ( struct V_1 * V_2 )
{
if ( V_2 -> V_306 )
return V_2 -> V_306 ( V_2 ) ;
return F_140 ( V_2 ) ;
}
void F_147 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_27 ( V_2 ) ;
unsigned long V_108 ;
F_34 ( V_6 ) ;
V_6 -> V_158 = 0 ;
F_75 ( V_2 , V_59 , 0 ) ;
if ( V_6 -> V_161 )
F_148 ( V_6 ) ;
F_61 ( & V_2 -> V_68 , V_108 ) ;
if ( V_2 -> V_108 & V_153 ) {
F_14 ( ( V_2 -> V_17 & 0xfe0 ) | 0x1f ) ;
V_2 -> V_265 |= V_269 ;
} else
V_2 -> V_265 &= ~ V_270 ;
F_134 ( V_2 , V_2 -> V_265 ) ;
F_63 ( & V_2 -> V_68 , V_108 ) ;
F_75 ( V_2 , V_30 ,
F_95 ( V_2 , V_30 ) & ~ V_276 ) ;
F_32 ( V_6 ) ;
#ifdef F_64
F_47 ( V_6 ) ;
#endif
F_95 ( V_2 , V_82 ) ;
F_36 ( V_6 ) ;
F_149 ( & V_6 -> V_253 ) ;
V_6 -> V_253 . V_299 = F_127 ;
if ( V_2 -> V_152 )
F_125 ( V_6 ) ;
}
static void F_150 ( struct V_1 * V_2 )
{
if ( V_2 -> V_307 )
V_2 -> V_307 ( V_2 ) ;
else
F_147 ( V_2 ) ;
}
static unsigned int F_151 ( struct V_5 * V_6 ,
unsigned int V_308 ,
unsigned int * V_309 )
{
struct V_1 * V_2 = & V_6 -> V_2 ;
unsigned int V_310 ;
V_310 = F_152 ( V_2 -> V_65 , V_308 ) ;
* V_309 = V_310 & 0x0f ;
return V_310 >> 4 ;
}
static unsigned int F_153 ( struct V_5 * V_6 ,
unsigned int V_308 ,
unsigned int * V_309 )
{
struct V_1 * V_2 = & V_6 -> V_2 ;
unsigned int V_116 ;
if ( ( V_2 -> V_108 & V_311 ) &&
V_308 == ( V_2 -> V_65 / 4 ) )
V_116 = 0x8001 ;
else if ( ( V_2 -> V_108 & V_311 ) &&
V_308 == ( V_2 -> V_65 / 8 ) )
V_116 = 0x8002 ;
else if ( V_6 -> V_2 . type == V_50 )
V_116 = F_151 ( V_6 , V_308 , V_309 ) ;
else
V_116 = F_154 ( V_2 , V_308 ) ;
if ( V_6 -> V_95 & V_96 && ( V_116 & 0xff ) == 0 )
V_116 ++ ;
return V_116 ;
}
static unsigned char F_155 ( struct V_5 * V_6 ,
T_3 V_312 )
{
unsigned char V_313 ;
switch ( V_312 & V_314 ) {
case V_315 :
V_313 = V_316 ;
break;
case V_317 :
V_313 = V_318 ;
break;
case V_319 :
V_313 = V_320 ;
break;
default:
case V_321 :
V_313 = V_300 ;
break;
}
if ( V_312 & V_322 )
V_313 |= V_323 ;
if ( V_312 & V_324 ) {
V_313 |= V_325 ;
if ( V_6 -> V_95 & V_326 )
V_6 -> V_327 = true ;
}
if ( ! ( V_312 & V_328 ) )
V_313 |= V_329 ;
#ifdef F_156
if ( V_312 & F_156 )
V_313 |= V_330 ;
#endif
return V_313 ;
}
static void F_157 ( struct V_1 * V_2 , unsigned int V_308 ,
unsigned int V_116 , unsigned int V_331 )
{
struct V_5 * V_6 = F_27 ( V_2 ) ;
if ( F_158 ( V_6 ) ) {
if ( V_308 == 115200 ) {
V_116 = 1 ;
F_75 ( V_2 , V_332 , 1 ) ;
} else
F_75 ( V_2 , V_332 , 0 ) ;
}
if ( V_6 -> V_36 & V_118 )
F_75 ( V_2 , V_30 , 0xe0 ) ;
else
F_75 ( V_2 , V_30 , V_6 -> V_48 | V_333 ) ;
F_50 ( V_6 , V_116 ) ;
if ( V_6 -> V_2 . type == V_50 )
F_75 ( V_2 , 0x2 , V_331 ) ;
}
void
F_159 ( struct V_1 * V_2 , struct V_334 * V_335 ,
struct V_334 * V_336 )
{
struct V_5 * V_6 = F_27 ( V_2 ) ;
unsigned char V_313 ;
unsigned long V_108 ;
unsigned int V_308 , V_116 , V_309 = 0 ;
V_313 = F_155 ( V_6 , V_335 -> V_312 ) ;
V_308 = F_160 ( V_2 , V_335 , V_336 ,
V_2 -> V_65 / 16 / 0xffff ,
V_2 -> V_65 / 16 ) ;
V_116 = F_153 ( V_6 , V_308 , & V_309 ) ;
F_34 ( V_6 ) ;
F_61 ( & V_2 -> V_68 , V_108 ) ;
V_6 -> V_48 = V_313 ;
if ( V_6 -> V_36 & V_37 && V_2 -> V_141 > 1 ) {
if ( ( V_308 < 2400 && ! V_6 -> V_161 ) || V_6 -> V_327 ) {
V_6 -> V_42 &= ~ V_337 ;
V_6 -> V_42 |= V_338 ;
}
}
if ( V_6 -> V_36 & V_111 && V_2 -> V_141 >= 32 ) {
V_6 -> V_266 &= ~ V_339 ;
if ( V_335 -> V_312 & V_340 )
V_6 -> V_266 |= V_339 ;
}
F_161 ( V_2 , V_335 -> V_312 , V_308 ) ;
V_2 -> V_172 = V_189 | V_167 | V_81 ;
if ( V_335 -> V_341 & V_342 )
V_2 -> V_172 |= V_183 | V_184 ;
if ( V_335 -> V_341 & ( V_343 | V_344 | V_345 ) )
V_2 -> V_172 |= V_182 ;
V_2 -> V_346 = 0 ;
if ( V_335 -> V_341 & V_347 )
V_2 -> V_346 |= V_184 | V_183 ;
if ( V_335 -> V_341 & V_343 ) {
V_2 -> V_346 |= V_182 ;
if ( V_335 -> V_341 & V_347 )
V_2 -> V_346 |= V_189 ;
}
if ( ( V_335 -> V_312 & V_348 ) == 0 )
V_2 -> V_346 |= V_81 ;
V_6 -> V_158 &= ~ V_174 ;
if ( ! ( V_6 -> V_95 & V_173 ) &&
F_162 ( & V_6 -> V_2 , V_335 -> V_312 ) )
V_6 -> V_158 |= V_174 ;
if ( V_6 -> V_36 & V_122 )
V_6 -> V_158 |= V_120 ;
if ( V_6 -> V_36 & V_123 )
V_6 -> V_158 |= V_349 ;
F_75 ( V_2 , V_59 , V_6 -> V_158 ) ;
if ( V_6 -> V_36 & V_55 ) {
unsigned char V_49 = 0 ;
if ( V_335 -> V_312 & V_340 )
V_49 |= V_350 ;
F_75 ( V_2 , V_30 , V_57 ) ;
if ( V_2 -> V_108 & V_109 )
F_75 ( V_2 , V_351 , V_49 ) ;
else
F_75 ( V_2 , V_56 , V_49 ) ;
}
F_157 ( V_2 , V_308 , V_116 , V_309 ) ;
if ( V_2 -> type == V_119 )
F_75 ( V_2 , V_38 , V_6 -> V_42 ) ;
F_75 ( V_2 , V_30 , V_6 -> V_48 ) ;
if ( V_2 -> type != V_119 ) {
if ( V_6 -> V_42 & V_39 )
F_75 ( V_2 , V_38 , V_39 ) ;
F_75 ( V_2 , V_38 , V_6 -> V_42 ) ;
}
F_134 ( V_2 , V_2 -> V_265 ) ;
F_63 ( & V_2 -> V_68 , V_108 ) ;
F_36 ( V_6 ) ;
if ( F_163 ( V_335 ) )
F_164 ( V_335 , V_308 , V_308 ) ;
}
static void
F_165 ( struct V_1 * V_2 , struct V_334 * V_335 ,
struct V_334 * V_336 )
{
if ( V_2 -> V_352 )
V_2 -> V_352 ( V_2 , V_335 , V_336 ) ;
else
F_159 ( V_2 , V_335 , V_336 ) ;
}
static void
F_166 ( struct V_1 * V_2 , struct V_334 * V_335 )
{
if ( V_335 -> V_353 == V_354 ) {
V_2 -> V_108 |= V_355 ;
F_45 ( & V_2 -> V_68 ) ;
F_82 ( V_2 ) ;
F_46 ( & V_2 -> V_68 ) ;
} else {
V_2 -> V_108 &= ~ V_355 ;
if ( ! F_162 ( V_2 , V_335 -> V_312 ) ) {
F_45 ( & V_2 -> V_68 ) ;
F_80 ( V_2 ) ;
F_46 ( & V_2 -> V_68 ) ;
}
}
}
void F_167 ( struct V_1 * V_2 , unsigned int V_194 ,
unsigned int V_356 )
{
struct V_5 * V_10 = F_27 ( V_2 ) ;
F_42 ( V_10 , V_194 != 0 ) ;
}
static void
F_168 ( struct V_1 * V_2 , unsigned int V_194 ,
unsigned int V_356 )
{
if ( V_2 -> V_357 )
V_2 -> V_357 ( V_2 , V_194 , V_356 ) ;
else
F_167 ( V_2 , V_194 , V_356 ) ;
}
static unsigned int F_169 ( struct V_5 * V_358 )
{
if ( V_358 -> V_2 . V_20 == V_26 ) {
if ( V_358 -> V_2 . type == V_359 )
return 0x100 ;
return 0x1000 ;
}
if ( F_170 ( V_358 ) )
return 0x16 << V_358 -> V_2 . V_13 ;
return 8 << V_358 -> V_2 . V_13 ;
}
static int F_171 ( struct V_5 * V_6 )
{
unsigned int V_360 = F_169 ( V_6 ) ;
struct V_1 * V_2 = & V_6 -> V_2 ;
int V_221 = 0 ;
switch ( V_2 -> V_20 ) {
case V_26 :
case V_361 :
case V_23 :
case V_22 :
if ( ! V_2 -> V_131 )
break;
if ( ! F_172 ( V_2 -> V_131 , V_360 , L_23 ) ) {
V_221 = - V_362 ;
break;
}
if ( V_2 -> V_108 & V_363 ) {
V_2 -> V_14 = F_173 ( V_2 -> V_131 , V_360 ) ;
if ( ! V_2 -> V_14 ) {
F_174 ( V_2 -> V_131 , V_360 ) ;
V_221 = - V_250 ;
}
}
break;
case V_21 :
case V_364 :
if ( ! F_175 ( V_2 -> V_17 , V_360 , L_23 ) )
V_221 = - V_362 ;
break;
}
return V_221 ;
}
static void F_176 ( struct V_5 * V_6 )
{
unsigned int V_360 = F_169 ( V_6 ) ;
struct V_1 * V_2 = & V_6 -> V_2 ;
switch ( V_2 -> V_20 ) {
case V_26 :
case V_361 :
case V_23 :
case V_22 :
if ( ! V_2 -> V_131 )
break;
if ( V_2 -> V_108 & V_363 ) {
F_177 ( V_2 -> V_14 ) ;
V_2 -> V_14 = NULL ;
}
F_174 ( V_2 -> V_131 , V_360 ) ;
break;
case V_21 :
case V_364 :
F_178 ( V_2 -> V_17 , V_360 ) ;
break;
}
}
static int F_179 ( struct V_5 * V_6 )
{
unsigned long V_365 = V_366 << V_6 -> V_2 . V_13 ;
unsigned int V_360 = 8 << V_6 -> V_2 . V_13 ;
struct V_1 * V_2 = & V_6 -> V_2 ;
int V_221 = - V_367 ;
switch ( V_2 -> V_20 ) {
case V_21 :
case V_364 :
V_365 += V_2 -> V_17 ;
if ( F_175 ( V_365 , V_360 , L_28 ) )
V_221 = 0 ;
else
V_221 = - V_362 ;
break;
}
return V_221 ;
}
static void F_180 ( struct V_5 * V_6 )
{
unsigned long V_11 = V_366 << V_6 -> V_2 . V_13 ;
unsigned int V_360 = 8 << V_6 -> V_2 . V_13 ;
struct V_1 * V_2 = & V_6 -> V_2 ;
switch ( V_2 -> V_20 ) {
case V_21 :
case V_364 :
F_178 ( V_2 -> V_17 + V_11 , V_360 ) ;
break;
}
}
static void F_181 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_27 ( V_2 ) ;
F_176 ( V_6 ) ;
if ( V_2 -> type == V_67 )
F_180 ( V_6 ) ;
}
static int F_182 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_27 ( V_2 ) ;
int V_221 ;
if ( V_2 -> type == V_285 )
return - V_286 ;
V_221 = F_171 ( V_6 ) ;
if ( V_221 == 0 && V_2 -> type == V_67 ) {
V_221 = F_179 ( V_6 ) ;
if ( V_221 < 0 )
F_176 ( V_6 ) ;
}
return V_221 ;
}
static int F_183 ( struct V_5 * V_6 )
{
const struct V_368 * V_369 = & V_142 [ V_6 -> V_2 . type ] ;
unsigned char V_370 ;
V_370 = V_369 -> V_371 [ F_184 ( V_6 -> V_42 ) ] ;
return V_370 ? V_370 : - V_372 ;
}
static int F_185 ( struct V_5 * V_6 , unsigned char V_370 )
{
const struct V_368 * V_369 = & V_142 [ V_6 -> V_2 . type ] ;
int V_138 ;
if ( ! V_369 -> V_371 [ F_184 ( V_373 ) ] )
return - V_372 ;
for ( V_138 = 1 ; V_138 < V_374 ; V_138 ++ ) {
if ( V_370 < V_369 -> V_371 [ V_138 ] )
return ( -- V_138 ) << V_375 ;
}
return V_376 ;
}
static int F_186 ( struct V_377 * V_2 )
{
struct V_378 * V_194 = F_81 ( V_2 , struct V_378 , V_2 ) ;
struct V_1 * V_379 = V_194 -> V_1 ;
struct V_5 * V_6 =
F_81 ( V_379 , struct V_5 , V_2 ) ;
if ( ! ( V_6 -> V_36 & V_37 ) || V_379 -> V_141 <= 1 )
return - V_367 ;
return F_183 ( V_6 ) ;
}
static int F_187 ( struct V_377 * V_2 )
{
int V_371 ;
F_115 ( & V_2 -> V_380 ) ;
V_371 = F_186 ( V_2 ) ;
F_119 ( & V_2 -> V_380 ) ;
return V_371 ;
}
static T_4 F_188 ( struct V_381 * V_44 ,
struct V_382 * V_383 , char * V_199 )
{
struct V_377 * V_2 = F_189 ( V_44 ) ;
int V_371 ;
V_371 = F_187 ( V_2 ) ;
if ( V_371 < 0 )
return V_371 ;
return snprintf ( V_199 , V_384 , L_29 , V_371 ) ;
}
static int F_190 ( struct V_377 * V_2 , unsigned char V_370 )
{
struct V_378 * V_194 = F_81 ( V_2 , struct V_378 , V_2 ) ;
struct V_1 * V_379 = V_194 -> V_1 ;
struct V_5 * V_6 =
F_81 ( V_379 , struct V_5 , V_2 ) ;
int V_385 ;
if ( ! ( V_6 -> V_36 & V_37 ) || V_379 -> V_141 <= 1 ||
V_6 -> V_327 )
return - V_367 ;
V_385 = F_185 ( V_6 , V_370 ) ;
if ( V_385 < 0 )
return V_385 ;
F_32 ( V_6 ) ;
V_6 -> V_42 &= ~ V_337 ;
V_6 -> V_42 |= ( unsigned char ) V_385 ;
F_5 ( V_6 , V_38 , V_6 -> V_42 ) ;
return 0 ;
}
static int F_191 ( struct V_377 * V_2 , unsigned char V_370 )
{
int V_221 ;
F_115 ( & V_2 -> V_380 ) ;
V_221 = F_190 ( V_2 , V_370 ) ;
F_119 ( & V_2 -> V_380 ) ;
return V_221 ;
}
static T_4 F_192 ( struct V_381 * V_44 ,
struct V_382 * V_383 , const char * V_199 , T_5 V_75 )
{
struct V_377 * V_2 = F_189 ( V_44 ) ;
unsigned char V_370 ;
int V_221 ;
if ( ! V_75 )
return - V_367 ;
V_221 = F_193 ( V_199 , 10 , & V_370 ) ;
if ( V_221 < 0 )
return V_221 ;
V_221 = F_191 ( V_2 , V_370 ) ;
if ( V_221 < 0 )
return V_221 ;
return V_75 ;
}
static void F_194 ( struct V_5 * V_6 )
{
const struct V_368 * V_369 = & V_142 [ V_6 -> V_2 . type ] ;
if ( V_369 -> V_371 [ 0 ] )
V_6 -> V_2 . V_386 = & V_387 ;
}
static void F_195 ( struct V_1 * V_2 , int V_108 )
{
struct V_5 * V_6 = F_27 ( V_2 ) ;
int V_125 = V_388 ;
int V_221 ;
if ( V_2 -> type == V_285 )
return;
V_221 = F_171 ( V_6 ) ;
if ( V_221 < 0 )
return;
V_221 = F_179 ( V_6 ) ;
if ( V_221 < 0 )
V_125 &= ~ V_137 ;
if ( V_2 -> V_20 != V_6 -> V_27 )
F_26 ( V_2 ) ;
if ( V_108 & V_389 )
F_60 ( V_6 , V_125 ) ;
if ( V_2 -> type == V_107 && V_2 -> V_20 == V_26 )
V_6 -> V_95 |= V_173 ;
if ( V_2 -> type == V_390 )
V_6 -> V_95 |= V_173 ;
if ( V_2 -> type != V_135 && V_108 & V_391 )
F_66 ( V_6 ) ;
if ( V_2 -> type != V_67 && V_125 & V_137 )
F_180 ( V_6 ) ;
if ( V_2 -> type == V_135 )
F_176 ( V_6 ) ;
if ( ( V_2 -> type == V_50 ) ||
( V_2 -> type == V_51 ) )
V_2 -> V_28 = F_103 ;
F_194 ( V_6 ) ;
V_6 -> V_42 = V_142 [ V_6 -> V_2 . type ] . V_42 ;
}
static int
F_196 ( struct V_1 * V_2 , struct V_392 * V_393 )
{
if ( V_393 -> V_152 >= V_394 || V_393 -> V_152 < 0 ||
V_393 -> V_395 < 9600 || V_393 -> type < V_135 ||
V_393 -> type >= F_197 ( V_142 ) || V_393 -> type == V_396 ||
V_393 -> type == V_397 )
return - V_367 ;
return 0 ;
}
static const char *
F_198 ( struct V_1 * V_2 )
{
int type = V_2 -> type ;
if ( type >= F_197 ( V_142 ) )
type = 0 ;
return V_142 [ type ] . V_147 ;
}
struct V_5 * F_199 ( int line )
{
return & V_398 [ line ] ;
}
void F_200 (
void (* F_201)( int V_2 , struct V_1 * V_6 , unsigned short * V_36 ) )
{
V_399 = F_201 ;
}
static void T_6 F_202 ( void )
{
struct V_5 * V_6 ;
static int V_400 = 1 ;
int V_138 , V_401 = 0 ;
if ( ! V_400 )
return;
V_400 = 0 ;
if ( V_402 > V_403 )
V_402 = V_403 ;
for ( V_138 = 0 ; V_138 < V_402 ; V_138 ++ ) {
struct V_5 * V_6 = & V_398 [ V_138 ] ;
struct V_1 * V_2 = & V_6 -> V_2 ;
V_2 -> line = V_138 ;
F_120 ( & V_2 -> V_68 ) ;
F_203 ( & V_6 -> V_253 ) ;
V_6 -> V_253 . V_299 = F_127 ;
V_6 -> V_27 = 0xFF ;
V_6 -> V_272 = ~ V_404 ;
V_6 -> V_273 = V_404 ;
V_2 -> V_405 = & V_406 ;
}
if ( V_407 )
V_401 = V_245 ;
for ( V_138 = 0 , V_6 = V_398 ;
V_138 < F_197 ( V_408 ) && V_138 < V_402 ;
V_138 ++ , V_6 ++ ) {
struct V_1 * V_2 = & V_6 -> V_2 ;
V_2 -> V_17 = V_408 [ V_138 ] . V_2 ;
V_2 -> V_152 = F_204 ( V_408 [ V_138 ] . V_152 ) ;
V_2 -> V_251 = V_408 [ V_138 ] . V_251 ;
V_2 -> V_65 = V_408 [ V_138 ] . V_395 * 16 ;
V_2 -> V_108 = V_408 [ V_138 ] . V_108 ;
V_2 -> V_16 = V_408 [ V_138 ] . V_16 ;
V_2 -> V_14 = V_408 [ V_138 ] . V_409 ;
V_2 -> V_20 = V_408 [ V_138 ] . V_410 ;
V_2 -> V_13 = V_408 [ V_138 ] . V_411 ;
F_26 ( V_2 ) ;
V_2 -> V_251 |= V_401 ;
if ( V_399 != NULL )
V_399 ( V_138 , & V_6 -> V_2 , & V_6 -> V_36 ) ;
}
}
static void
F_205 ( struct V_5 * V_6 , unsigned int type )
{
V_6 -> V_2 . type = type ;
if ( ! V_6 -> V_2 . V_141 )
V_6 -> V_2 . V_141 = V_142 [ type ] . V_143 ;
if ( ! V_6 -> V_144 )
V_6 -> V_144 = V_142 [ type ] . V_144 ;
if ( ! V_6 -> V_36 )
V_6 -> V_36 = V_142 [ type ] . V_108 ;
}
static void T_6
F_206 ( struct V_412 * V_413 , struct V_381 * V_44 )
{
int V_138 ;
for ( V_138 = 0 ; V_138 < V_402 ; V_138 ++ ) {
struct V_5 * V_6 = & V_398 [ V_138 ] ;
if ( V_6 -> V_2 . V_44 )
continue;
V_6 -> V_2 . V_44 = V_44 ;
if ( V_6 -> V_2 . V_108 & V_414 )
F_205 ( V_6 , V_6 -> V_2 . type ) ;
F_207 ( V_413 , & V_6 -> V_2 ) ;
}
}
static void F_208 ( struct V_1 * V_2 , int V_175 )
{
struct V_5 * V_6 = F_27 ( V_2 ) ;
F_136 ( V_6 , V_167 ) ;
F_75 ( V_2 , V_79 , V_175 ) ;
}
static void
F_209 ( struct V_415 * V_416 , const char * V_417 , unsigned int V_75 )
{
struct V_5 * V_6 = & V_398 [ V_416 -> V_418 ] ;
struct V_1 * V_2 = & V_6 -> V_2 ;
unsigned long V_108 ;
unsigned int V_158 ;
int V_419 = 1 ;
F_137 () ;
F_34 ( V_6 ) ;
if ( V_2 -> V_420 )
V_419 = 0 ;
else if ( V_421 )
V_419 = F_210 ( & V_2 -> V_68 , V_108 ) ;
else
F_61 ( & V_2 -> V_68 , V_108 ) ;
V_158 = F_95 ( V_2 , V_59 ) ;
if ( V_6 -> V_36 & V_122 )
F_75 ( V_2 , V_59 , V_120 ) ;
else
F_75 ( V_2 , V_59 , 0 ) ;
if ( V_6 -> V_422 && ( V_6 -> V_422 != F_95 ( V_2 , V_31 ) ) ) {
struct V_334 V_335 ;
unsigned int V_308 , V_116 , V_309 = 0 ;
V_335 . V_312 = V_2 -> V_423 -> V_424 ;
if ( V_2 -> V_194 -> V_2 . V_425 && V_335 . V_312 == 0 )
V_335 . V_312 = V_2 -> V_194 -> V_2 . V_425 -> V_335 . V_312 ;
V_308 = F_160 ( V_2 , & V_335 , NULL ,
V_2 -> V_65 / 16 / 0xffff ,
V_2 -> V_65 / 16 ) ;
V_116 = F_153 ( V_6 , V_308 , & V_309 ) ;
F_157 ( V_2 , V_308 , V_116 , V_309 ) ;
F_75 ( V_2 , V_30 , V_6 -> V_48 ) ;
F_75 ( V_2 , V_76 , V_156 | V_157 ) ;
V_6 -> V_422 = 0 ;
}
F_211 ( V_2 , V_417 , V_75 , F_208 ) ;
F_136 ( V_6 , V_203 ) ;
F_75 ( V_2 , V_59 , V_158 ) ;
if ( V_6 -> V_205 )
F_98 ( V_6 ) ;
if ( V_419 )
F_63 ( & V_2 -> V_68 , V_108 ) ;
F_36 ( V_6 ) ;
}
static int F_212 ( struct V_415 * V_416 , char * V_426 )
{
struct V_1 * V_2 ;
int V_308 = 9600 ;
int V_277 = 8 ;
int V_187 = 'n' ;
int V_427 = 'n' ;
if ( V_416 -> V_418 >= V_402 )
V_416 -> V_418 = 0 ;
V_2 = & V_398 [ V_416 -> V_418 ] . V_2 ;
if ( ! V_2 -> V_17 && ! V_2 -> V_14 )
return - V_286 ;
if ( V_426 )
F_213 ( V_426 , & V_308 , & V_187 , & V_277 , & V_427 ) ;
return F_214 ( V_2 , V_416 , V_308 , V_187 , V_277 , V_427 ) ;
}
static int F_215 ( void )
{
return F_216 () ;
}
static int T_6 F_217 ( void )
{
F_202 () ;
F_218 ( & V_428 ) ;
return 0 ;
}
int F_219 ( struct V_1 * V_10 )
{
int line ;
struct V_1 * V_2 ;
for ( line = 0 ; line < V_402 ; line ++ ) {
V_2 = & V_398 [ line ] . V_2 ;
if ( F_220 ( V_10 , V_2 ) )
return line ;
}
return - V_286 ;
}
int T_6 F_221 ( struct V_1 * V_2 )
{
struct V_1 * V_10 ;
if ( V_2 -> line >= F_197 ( V_398 ) )
return - V_286 ;
F_202 () ;
V_10 = & V_398 [ V_2 -> line ] . V_2 ;
V_10 -> V_17 = V_2 -> V_17 ;
V_10 -> V_14 = V_2 -> V_14 ;
V_10 -> V_152 = V_2 -> V_152 ;
V_10 -> V_251 = V_2 -> V_251 ;
V_10 -> V_65 = V_2 -> V_65 ;
V_10 -> V_141 = V_2 -> V_141 ;
V_10 -> V_13 = V_2 -> V_13 ;
V_10 -> V_20 = V_2 -> V_20 ;
V_10 -> V_108 = V_2 -> V_108 ;
V_10 -> V_131 = V_2 -> V_131 ;
V_10 -> V_429 = V_2 -> V_429 ;
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
struct V_5 * V_6 = & V_398 [ line ] ;
struct V_1 * V_2 = & V_6 -> V_2 ;
if ( ! V_430 && F_223 ( V_2 ) &&
V_2 -> type != V_103 ) {
unsigned char V_422 = 0xa5 ;
F_5 ( V_6 , V_31 , V_422 ) ;
V_6 -> V_422 = V_422 ;
}
F_224 ( & V_3 , V_2 ) ;
}
void F_225 ( int line )
{
struct V_5 * V_6 = & V_398 [ line ] ;
struct V_1 * V_2 = & V_6 -> V_2 ;
V_6 -> V_422 = 0 ;
if ( V_6 -> V_36 & V_118 ) {
F_75 ( V_2 , V_30 , 0xE0 ) ;
F_57 ( V_6 ) ;
F_75 ( V_2 , V_30 , 0 ) ;
V_2 -> V_65 = 921600 * 16 ;
}
F_226 ( & V_3 , V_2 ) ;
}
static int F_227 ( struct V_431 * V_44 )
{
struct V_432 * V_10 = F_228 ( & V_44 -> V_44 ) ;
struct V_5 V_433 ;
int V_221 , V_138 , V_401 = 0 ;
memset ( & V_433 , 0 , sizeof( V_433 ) ) ;
if ( V_407 )
V_401 = V_245 ;
for ( V_138 = 0 ; V_10 && V_10 -> V_108 != 0 ; V_10 ++ , V_138 ++ ) {
V_433 . V_2 . V_17 = V_10 -> V_17 ;
V_433 . V_2 . V_14 = V_10 -> V_14 ;
V_433 . V_2 . V_152 = V_10 -> V_152 ;
V_433 . V_2 . V_251 = V_10 -> V_251 ;
V_433 . V_2 . V_65 = V_10 -> V_65 ;
V_433 . V_2 . V_13 = V_10 -> V_13 ;
V_433 . V_2 . V_20 = V_10 -> V_20 ;
V_433 . V_2 . V_108 = V_10 -> V_108 ;
V_433 . V_2 . V_131 = V_10 -> V_131 ;
V_433 . V_2 . V_16 = V_10 -> V_16 ;
V_433 . V_2 . V_429 = V_10 -> V_429 ;
V_433 . V_2 . type = V_10 -> type ;
V_433 . V_2 . F_3 = V_10 -> F_3 ;
V_433 . V_2 . F_5 = V_10 -> F_5 ;
V_433 . V_2 . V_28 = V_10 -> V_28 ;
V_433 . V_2 . V_434 = V_10 -> V_434 ;
V_433 . V_2 . V_352 = V_10 -> V_352 ;
V_433 . V_2 . V_357 = V_10 -> V_357 ;
V_433 . V_2 . V_44 = & V_44 -> V_44 ;
V_433 . V_2 . V_251 |= V_401 ;
V_221 = F_229 ( & V_433 ) ;
if ( V_221 < 0 ) {
F_230 ( & V_44 -> V_44 , L_30
L_31 , V_138 ,
V_10 -> V_17 , ( unsigned long long ) V_10 -> V_131 ,
V_10 -> V_152 , V_221 ) ;
}
}
return 0 ;
}
static int F_231 ( struct V_431 * V_44 )
{
int V_138 ;
for ( V_138 = 0 ; V_138 < V_402 ; V_138 ++ ) {
struct V_5 * V_6 = & V_398 [ V_138 ] ;
if ( V_6 -> V_2 . V_44 == & V_44 -> V_44 )
F_232 ( V_138 ) ;
}
return 0 ;
}
static int F_233 ( struct V_431 * V_44 , T_7 V_194 )
{
int V_138 ;
for ( V_138 = 0 ; V_138 < V_403 ; V_138 ++ ) {
struct V_5 * V_6 = & V_398 [ V_138 ] ;
if ( V_6 -> V_2 . type != V_135 && V_6 -> V_2 . V_44 == & V_44 -> V_44 )
F_224 ( & V_3 , & V_6 -> V_2 ) ;
}
return 0 ;
}
static int F_234 ( struct V_431 * V_44 )
{
int V_138 ;
for ( V_138 = 0 ; V_138 < V_403 ; V_138 ++ ) {
struct V_5 * V_6 = & V_398 [ V_138 ] ;
if ( V_6 -> V_2 . type != V_135 && V_6 -> V_2 . V_44 == & V_44 -> V_44 )
F_225 ( V_138 ) ;
}
return 0 ;
}
static struct V_5 * F_235 ( struct V_1 * V_2 )
{
int V_138 ;
for ( V_138 = 0 ; V_138 < V_402 ; V_138 ++ )
if ( F_220 ( & V_398 [ V_138 ] . V_2 , V_2 ) )
return & V_398 [ V_138 ] ;
V_138 = V_2 -> line ;
if ( V_138 < V_402 && V_398 [ V_138 ] . V_2 . type == V_135 &&
V_398 [ V_138 ] . V_2 . V_17 == 0 )
return & V_398 [ V_138 ] ;
for ( V_138 = 0 ; V_138 < V_402 ; V_138 ++ )
if ( V_398 [ V_138 ] . V_2 . type == V_135 &&
V_398 [ V_138 ] . V_2 . V_17 == 0 )
return & V_398 [ V_138 ] ;
for ( V_138 = 0 ; V_138 < V_402 ; V_138 ++ )
if ( V_398 [ V_138 ] . V_2 . type == V_135 )
return & V_398 [ V_138 ] ;
return NULL ;
}
int F_229 ( struct V_5 * V_6 )
{
struct V_5 * V_433 ;
int V_221 = - V_435 ;
if ( V_6 -> V_2 . V_65 == 0 )
return - V_367 ;
F_115 ( & V_436 ) ;
V_433 = F_235 ( & V_6 -> V_2 ) ;
if ( V_433 && V_433 -> V_2 . type != V_285 ) {
if ( V_433 -> V_2 . V_44 )
F_236 ( & V_3 , & V_433 -> V_2 ) ;
V_433 -> V_2 . V_17 = V_6 -> V_2 . V_17 ;
V_433 -> V_2 . V_14 = V_6 -> V_2 . V_14 ;
V_433 -> V_2 . V_152 = V_6 -> V_2 . V_152 ;
V_433 -> V_2 . V_251 = V_6 -> V_2 . V_251 ;
V_433 -> V_2 . V_65 = V_6 -> V_2 . V_65 ;
V_433 -> V_2 . V_141 = V_6 -> V_2 . V_141 ;
V_433 -> V_2 . V_13 = V_6 -> V_2 . V_13 ;
V_433 -> V_2 . V_20 = V_6 -> V_2 . V_20 ;
V_433 -> V_2 . V_108 = V_6 -> V_2 . V_108 | V_437 ;
V_433 -> V_95 = V_6 -> V_95 ;
V_433 -> V_2 . V_131 = V_6 -> V_2 . V_131 ;
V_433 -> V_2 . V_429 = V_6 -> V_2 . V_429 ;
V_433 -> V_2 . V_141 = V_6 -> V_2 . V_141 ;
V_433 -> V_144 = V_6 -> V_144 ;
V_433 -> V_36 = V_6 -> V_36 ;
V_433 -> V_2 . V_168 = V_6 -> V_2 . V_168 ;
V_433 -> V_2 . V_169 = V_6 -> V_2 . V_169 ;
V_433 -> V_2 . V_438 = V_6 -> V_2 . V_438 ;
V_433 -> V_2 . V_439 = V_6 -> V_2 . V_439 ;
if ( V_433 -> V_2 . V_141 && ! V_433 -> V_144 )
V_433 -> V_144 = V_433 -> V_2 . V_141 ;
if ( V_6 -> V_2 . V_44 )
V_433 -> V_2 . V_44 = V_6 -> V_2 . V_44 ;
if ( V_6 -> V_2 . V_108 & V_414 )
F_205 ( V_433 , V_6 -> V_2 . type ) ;
F_26 ( & V_433 -> V_2 ) ;
if ( V_6 -> V_2 . F_3 )
V_433 -> V_2 . F_3 = V_6 -> V_2 . F_3 ;
if ( V_6 -> V_2 . F_5 )
V_433 -> V_2 . F_5 = V_6 -> V_2 . F_5 ;
if ( V_6 -> V_2 . V_28 )
V_433 -> V_2 . V_28 = V_6 -> V_2 . V_28 ;
if ( V_6 -> V_2 . V_352 )
V_433 -> V_2 . V_352 = V_6 -> V_2 . V_352 ;
if ( V_6 -> V_2 . V_274 )
V_433 -> V_2 . V_274 = V_6 -> V_2 . V_274 ;
if ( V_6 -> V_2 . V_306 )
V_433 -> V_2 . V_306 = V_6 -> V_2 . V_306 ;
if ( V_6 -> V_2 . V_307 )
V_433 -> V_2 . V_307 = V_6 -> V_2 . V_307 ;
if ( V_6 -> V_2 . V_357 )
V_433 -> V_2 . V_357 = V_6 -> V_2 . V_357 ;
if ( V_6 -> V_2 . V_434 )
V_433 -> V_2 . V_434 = V_6 -> V_2 . V_434 ;
if ( V_6 -> V_18 )
V_433 -> V_18 = V_6 -> V_18 ;
if ( V_6 -> V_19 )
V_433 -> V_19 = V_6 -> V_19 ;
if ( V_6 -> V_161 ) {
V_433 -> V_161 = V_6 -> V_161 ;
if ( ! V_433 -> V_161 -> V_162 )
V_433 -> V_161 -> V_162 = V_440 ;
if ( ! V_433 -> V_161 -> V_219 )
V_433 -> V_161 -> V_219 = V_441 ;
}
if ( V_399 != NULL )
V_399 ( 0 , & V_433 -> V_2 ,
& V_433 -> V_36 ) ;
V_221 = F_207 ( & V_3 , & V_433 -> V_2 ) ;
if ( V_221 == 0 )
V_221 = V_433 -> V_2 . line ;
}
F_119 ( & V_436 ) ;
return V_221 ;
}
void F_232 ( int line )
{
struct V_5 * V_433 = & V_398 [ line ] ;
F_115 ( & V_436 ) ;
F_236 ( & V_3 , & V_433 -> V_2 ) ;
if ( V_442 ) {
V_433 -> V_2 . V_108 &= ~ V_437 ;
V_433 -> V_2 . type = V_135 ;
V_433 -> V_2 . V_44 = & V_442 -> V_44 ;
V_433 -> V_36 = V_142 [ V_433 -> V_2 . type ] . V_108 ;
F_207 ( & V_3 , & V_433 -> V_2 ) ;
} else {
V_433 -> V_2 . V_44 = NULL ;
}
F_119 ( & V_436 ) ;
}
static int T_6 F_237 ( void )
{
int V_221 ;
F_202 () ;
F_65 ( V_288 L_32
L_33 , V_402 ,
V_407 ? L_34 : L_35 ) ;
#ifdef F_238
V_221 = F_239 ( & V_3 , V_403 ) ;
#else
V_3 . V_443 = V_403 ;
V_221 = F_240 ( & V_3 ) ;
#endif
if ( V_221 )
goto V_53;
V_221 = F_241 () ;
if ( V_221 )
goto V_444;
V_442 = F_242 ( L_36 ,
V_445 ) ;
if ( ! V_442 ) {
V_221 = - V_250 ;
goto V_446;
}
V_221 = F_243 ( V_442 ) ;
if ( V_221 )
goto V_447;
F_206 ( & V_3 , & V_442 -> V_44 ) ;
V_221 = F_244 ( & V_448 ) ;
if ( V_221 == 0 )
goto V_53;
F_245 ( V_442 ) ;
V_447:
F_246 ( V_442 ) ;
V_446:
F_247 () ;
V_444:
#ifdef F_238
F_248 ( & V_3 , V_403 ) ;
#else
F_249 ( & V_3 ) ;
#endif
V_53:
return V_221 ;
}
static void T_8 F_250 ( void )
{
struct V_431 * V_449 = V_442 ;
V_442 = NULL ;
F_251 ( & V_448 ) ;
F_252 ( V_449 ) ;
F_247 () ;
#ifdef F_238
F_248 ( & V_3 , V_403 ) ;
#else
F_249 ( & V_3 ) ;
#endif
}
static void T_9 F_253 ( void )
{
#undef V_450
#define V_450 "8250_core."
F_254 ( V_407 , & V_451 , & V_407 , 0644 ) ;
F_254 ( V_402 , & V_451 , & V_402 , 0644 ) ;
F_254 ( V_301 , & V_451 , & V_301 , 0644 ) ;
#ifdef F_64
F_255 ( V_450 , V_140 ,
& V_452 , . V_453 = & V_454 ,
0444 , - 1 , 0 ) ;
#endif
}
