static int F_1 ( struct V_1 * V_2 )
{
return V_2 -> V_3 - 64 ;
}
static int F_2 ( struct V_4 * V_5 )
{
return F_3 ( V_5 , V_6 ) | F_3 ( V_5 , V_7 ) << 8 ;
}
static void F_4 ( struct V_4 * V_5 , int V_8 )
{
F_5 ( V_5 , V_6 , V_8 & 0xff ) ;
F_5 ( V_5 , V_7 , V_8 >> 8 & 0xff ) ;
}
static unsigned int F_6 ( struct V_1 * V_9 , int V_10 )
{
if ( V_10 >= F_7 ( V_11 ) )
return V_12 ;
V_10 = V_11 [ V_10 ] ;
if ( V_10 < 0 )
return V_12 ;
return F_8 ( V_9 -> V_13 + ( V_10 << V_9 -> V_14 ) ) ;
}
static void F_9 ( struct V_1 * V_9 , int V_10 , int V_8 )
{
if ( V_10 >= F_7 ( V_15 ) )
return;
V_10 = V_15 [ V_10 ] ;
if ( V_10 < 0 )
return;
F_10 ( V_8 , V_9 -> V_13 + ( V_10 << V_9 -> V_14 ) ) ;
}
static int F_11 ( struct V_4 * V_5 )
{
return F_8 ( V_5 -> V_2 . V_13 + 0x28 ) ;
}
static void F_12 ( struct V_4 * V_5 , int V_8 )
{
F_10 ( V_8 , V_5 -> V_2 . V_13 + 0x28 ) ;
}
static unsigned int F_13 ( struct V_1 * V_9 , int V_10 )
{
V_10 = V_10 << V_9 -> V_14 ;
F_14 ( V_9 -> V_16 - 1 + V_10 , V_9 -> V_17 ) ;
return F_15 ( V_9 -> V_17 + 1 ) ;
}
static void F_16 ( struct V_1 * V_9 , int V_10 , int V_8 )
{
V_10 = V_10 << V_9 -> V_14 ;
F_14 ( V_9 -> V_16 - 1 + V_10 , V_9 -> V_17 ) ;
F_14 ( V_8 , V_9 -> V_17 + 1 ) ;
}
static unsigned int F_17 ( struct V_1 * V_9 , int V_10 )
{
V_10 = V_10 << V_9 -> V_14 ;
return F_18 ( V_9 -> V_13 + V_10 ) ;
}
static void F_19 ( struct V_1 * V_9 , int V_10 , int V_8 )
{
V_10 = V_10 << V_9 -> V_14 ;
F_20 ( V_8 , V_9 -> V_13 + V_10 ) ;
}
static void F_21 ( struct V_1 * V_9 , int V_10 , int V_8 )
{
V_10 = V_10 << V_9 -> V_14 ;
F_22 ( V_8 , V_9 -> V_13 + V_10 ) ;
}
static unsigned int F_23 ( struct V_1 * V_9 , int V_10 )
{
V_10 = V_10 << V_9 -> V_14 ;
return F_24 ( V_9 -> V_13 + V_10 ) ;
}
static void F_25 ( struct V_1 * V_9 , int V_10 , int V_8 )
{
V_10 = V_10 << V_9 -> V_14 ;
F_26 ( V_8 , V_9 -> V_13 + V_10 ) ;
}
static unsigned int F_27 ( struct V_1 * V_9 , int V_10 )
{
V_10 = V_10 << V_9 -> V_14 ;
return F_28 ( V_9 -> V_13 + V_10 ) ;
}
static unsigned int F_29 ( struct V_1 * V_9 , int V_10 )
{
V_10 = V_10 << V_9 -> V_14 ;
return F_15 ( V_9 -> V_17 + V_10 ) ;
}
static void F_30 ( struct V_1 * V_9 , int V_10 , int V_8 )
{
V_10 = V_10 << V_9 -> V_14 ;
F_14 ( V_8 , V_9 -> V_17 + V_10 ) ;
}
static void F_31 ( struct V_1 * V_9 )
{
struct V_4 * V_5 = F_32 ( V_9 ) ;
V_5 -> V_18 = F_2 ;
V_5 -> V_19 = F_4 ;
switch ( V_9 -> V_20 ) {
case V_21 :
V_9 -> F_3 = F_13 ;
V_9 -> F_5 = F_16 ;
break;
case V_22 :
V_9 -> F_3 = F_17 ;
V_9 -> F_5 = F_19 ;
break;
case V_23 :
V_9 -> F_3 = F_23 ;
V_9 -> F_5 = F_21 ;
break;
case V_24 :
V_9 -> F_3 = F_27 ;
V_9 -> F_5 = F_25 ;
break;
#if F_33 ( V_25 ) || F_33 ( V_26 )
case V_27 :
V_9 -> F_3 = F_6 ;
V_9 -> F_5 = F_9 ;
V_5 -> V_18 = F_11 ;
V_5 -> V_19 = F_12 ;
break;
#endif
default:
V_9 -> F_3 = F_29 ;
V_9 -> F_5 = F_30 ;
break;
}
V_5 -> V_28 = V_9 -> V_20 ;
V_9 -> V_29 = V_30 ;
}
static void
F_34 ( struct V_1 * V_9 , int V_10 , int V_8 )
{
switch ( V_9 -> V_20 ) {
case V_22 :
case V_23 :
case V_24 :
case V_27 :
V_9 -> F_5 ( V_9 , V_10 , V_8 ) ;
V_9 -> F_3 ( V_9 , V_31 ) ;
break;
default:
V_9 -> F_5 ( V_9 , V_10 , V_8 ) ;
}
}
static void F_35 ( struct V_4 * V_5 , int V_10 , int V_8 )
{
F_5 ( V_5 , V_32 , V_10 ) ;
F_5 ( V_5 , V_33 , V_8 ) ;
}
static unsigned int F_36 ( struct V_4 * V_5 , int V_10 )
{
unsigned int V_8 ;
F_35 ( V_5 , V_34 , V_5 -> V_35 | V_36 ) ;
F_5 ( V_5 , V_32 , V_10 ) ;
V_8 = F_3 ( V_5 , V_33 ) ;
F_35 ( V_5 , V_34 , V_5 -> V_35 ) ;
return V_8 ;
}
static void F_37 ( struct V_4 * V_9 )
{
if ( V_9 -> V_37 & V_38 ) {
F_5 ( V_9 , V_39 , V_40 ) ;
F_5 ( V_9 , V_39 , V_40 |
V_41 | V_42 ) ;
F_5 ( V_9 , V_39 , 0 ) ;
}
}
void F_38 ( struct V_4 * V_9 )
{
F_37 ( V_9 ) ;
F_5 ( V_9 , V_39 , V_9 -> V_43 ) ;
}
void F_39 ( struct V_4 * V_9 )
{
if ( ! ( V_9 -> V_37 & V_44 ) )
return;
F_40 ( V_9 -> V_2 . V_45 ) ;
}
void F_41 ( struct V_4 * V_9 )
{
if ( ! ( V_9 -> V_37 & V_44 ) )
return;
F_42 ( V_9 -> V_2 . V_45 ) ;
F_43 ( V_9 -> V_2 . V_45 ) ;
}
static void F_44 ( struct V_4 * V_9 )
{
unsigned char V_46 ;
if ( ! ( V_9 -> V_37 & V_44 ) )
return;
V_46 = F_45 ( & V_9 -> V_47 , 1 ) ;
if ( V_46 )
return;
F_40 ( V_9 -> V_2 . V_45 ) ;
}
static void F_46 ( struct V_4 * V_9 )
{
unsigned char V_46 ;
if ( ! ( V_9 -> V_37 & V_44 ) )
return;
V_46 = F_45 ( & V_9 -> V_47 , 0 ) ;
if ( ! V_46 )
return;
F_42 ( V_9 -> V_2 . V_45 ) ;
F_43 ( V_9 -> V_2 . V_45 ) ;
}
static void F_47 ( struct V_4 * V_9 , int V_48 )
{
unsigned char V_49 = 0 , V_50 = 0 ;
F_39 ( V_9 ) ;
if ( ( V_9 -> V_2 . type == V_51 ) ||
( V_9 -> V_2 . type == V_52 ) ) {
F_5 ( V_9 , V_53 , V_48 ? 0xff : 0 ) ;
goto V_54;
}
if ( V_9 -> V_37 & V_55 ) {
if ( V_9 -> V_37 & V_56 ) {
V_49 = F_3 ( V_9 , V_31 ) ;
V_50 = F_3 ( V_9 , V_57 ) ;
F_5 ( V_9 , V_31 , V_58 ) ;
F_5 ( V_9 , V_57 , V_59 ) ;
F_5 ( V_9 , V_31 , 0 ) ;
}
F_5 ( V_9 , V_60 , V_48 ? V_61 : 0 ) ;
if ( V_9 -> V_37 & V_56 ) {
F_5 ( V_9 , V_31 , V_58 ) ;
F_5 ( V_9 , V_57 , V_50 ) ;
F_5 ( V_9 , V_31 , V_49 ) ;
}
}
V_54:
F_41 ( V_9 ) ;
}
static int F_48 ( struct V_4 * V_5 )
{
unsigned char V_62 ;
int V_63 ;
V_62 = F_3 ( V_5 , V_64 ) ;
V_63 = V_62 & V_65 ;
if ( ! V_63 ) {
F_5 ( V_5 , V_64 , V_62 | V_65 ) ;
V_62 = F_3 ( V_5 , V_64 ) ;
V_63 = V_62 & V_65 ;
}
if ( V_63 )
V_5 -> V_2 . V_66 = V_67 * 16 ;
return V_63 ;
}
static void F_49 ( struct V_4 * V_5 )
{
if ( V_5 -> V_2 . type == V_68 ) {
if ( V_5 -> V_2 . V_66 != V_67 * 16 ) {
F_50 ( & V_5 -> V_2 . V_69 ) ;
F_48 ( V_5 ) ;
F_51 ( & V_5 -> V_2 . V_69 ) ;
}
if ( V_5 -> V_2 . V_66 == V_67 * 16 )
F_5 ( V_5 , V_70 , 0 ) ;
}
}
static void F_52 ( struct V_4 * V_5 )
{
unsigned char V_62 ;
int V_63 ;
if ( V_5 -> V_2 . type == V_68 &&
V_5 -> V_2 . V_66 == V_67 * 16 ) {
F_50 ( & V_5 -> V_2 . V_69 ) ;
V_62 = F_3 ( V_5 , V_64 ) ;
V_63 = ! ( V_62 & V_65 ) ;
if ( ! V_63 ) {
F_5 ( V_5 , V_64 , V_62 & ~ V_65 ) ;
V_62 = F_3 ( V_5 , V_64 ) ;
V_63 = ! ( V_62 & V_65 ) ;
}
if ( V_63 )
V_5 -> V_2 . V_66 = V_71 * 16 ;
F_51 ( & V_5 -> V_2 . V_69 ) ;
}
}
static int F_53 ( struct V_4 * V_5 )
{
unsigned char V_72 , V_73 , V_74 ;
unsigned short V_75 ;
int V_76 ;
V_74 = F_3 ( V_5 , V_31 ) ;
F_5 ( V_5 , V_31 , 0 ) ;
V_72 = F_3 ( V_5 , V_39 ) ;
V_73 = F_3 ( V_5 , V_77 ) ;
F_5 ( V_5 , V_39 , V_40 |
V_41 | V_42 ) ;
F_5 ( V_5 , V_77 , V_78 ) ;
F_5 ( V_5 , V_31 , V_79 ) ;
V_75 = F_54 ( V_5 ) ;
F_55 ( V_5 , 0x0001 ) ;
F_5 ( V_5 , V_31 , 0x03 ) ;
for ( V_76 = 0 ; V_76 < 256 ; V_76 ++ )
F_5 ( V_5 , V_80 , V_76 ) ;
F_56 ( 20 ) ;
for ( V_76 = 0 ; ( F_3 ( V_5 , V_81 ) & V_82 ) &&
( V_76 < 256 ) ; V_76 ++ )
F_3 ( V_5 , V_83 ) ;
F_5 ( V_5 , V_39 , V_72 ) ;
F_5 ( V_5 , V_77 , V_73 ) ;
F_5 ( V_5 , V_31 , V_79 ) ;
F_55 ( V_5 , V_75 ) ;
F_5 ( V_5 , V_31 , V_74 ) ;
return V_76 ;
}
static unsigned int F_57 ( struct V_4 * V_9 )
{
unsigned char V_84 , V_85 , V_74 ;
unsigned int V_86 ;
V_74 = F_3 ( V_9 , V_31 ) ;
F_5 ( V_9 , V_31 , V_79 ) ;
V_84 = F_3 ( V_9 , V_6 ) ;
V_85 = F_3 ( V_9 , V_7 ) ;
F_5 ( V_9 , V_6 , 0 ) ;
F_5 ( V_9 , V_7 , 0 ) ;
V_86 = F_3 ( V_9 , V_6 ) | F_3 ( V_9 , V_7 ) << 8 ;
F_5 ( V_9 , V_6 , V_84 ) ;
F_5 ( V_9 , V_7 , V_85 ) ;
F_5 ( V_9 , V_31 , V_74 ) ;
return V_86 ;
}
static void F_58 ( struct V_4 * V_5 )
{
unsigned int V_87 , V_88 , V_89 , V_90 ;
V_5 -> V_37 |= V_56 | V_55 ;
V_5 -> V_35 = 0 ;
F_5 ( V_5 , V_31 , V_58 ) ;
F_5 ( V_5 , V_57 , V_59 ) ;
F_5 ( V_5 , V_31 , 0x00 ) ;
V_87 = F_36 ( V_5 , V_91 ) ;
V_88 = F_36 ( V_5 , V_92 ) ;
V_89 = F_36 ( V_5 , V_93 ) ;
V_90 = F_36 ( V_5 , V_94 ) ;
F_59 ( L_1 , V_87 , V_88 , V_89 , V_90 ) ;
if ( V_87 == 0x16 && V_88 == 0xC9 &&
( V_89 == 0x50 || V_89 == 0x52 || V_89 == 0x54 ) ) {
V_5 -> V_2 . type = V_95 ;
if ( V_89 == 0x52 && V_90 == 0x01 )
V_5 -> V_96 |= V_97 ;
return;
}
V_87 = F_57 ( V_5 ) ;
F_59 ( L_2 , V_87 ) ;
V_88 = V_87 >> 8 ;
if ( V_88 == 0x10 || V_88 == 0x12 || V_88 == 0x14 ) {
V_5 -> V_2 . type = V_98 ;
return;
}
if ( F_53 ( V_5 ) == 64 )
V_5 -> V_2 . type = V_99 ;
else
V_5 -> V_2 . type = V_100 ;
}
static void F_60 ( struct V_4 * V_5 )
{
unsigned char V_101 , V_102 , V_103 ;
V_5 -> V_2 . type = V_104 ;
V_101 = F_3 ( V_5 , V_32 ) ;
F_5 ( V_5 , V_32 , 0xa5 ) ;
V_102 = F_3 ( V_5 , V_32 ) ;
F_5 ( V_5 , V_32 , 0x5a ) ;
V_103 = F_3 ( V_5 , V_32 ) ;
F_5 ( V_5 , V_32 , V_101 ) ;
if ( V_102 == 0xa5 && V_103 == 0x5a )
V_5 -> V_2 . type = V_105 ;
}
static int F_61 ( struct V_4 * V_5 )
{
if ( F_57 ( V_5 ) == 0x0201 && F_53 ( V_5 ) == 16 )
return 1 ;
return 0 ;
}
static void F_62 ( struct V_4 * V_5 )
{
unsigned char V_102 , V_103 ;
unsigned int V_106 ;
V_5 -> V_2 . type = V_107 ;
V_5 -> V_37 |= V_38 ;
if ( V_5 -> V_2 . V_108 & V_109 ) {
V_102 = F_3 ( V_5 , V_110 ) ;
if ( V_102 == 0x82 || V_102 == 0x84 || V_102 == 0x88 ) {
F_59 ( L_3 ) ;
V_5 -> V_2 . type = V_51 ;
V_5 -> V_37 |= V_111 | V_56 |
V_55 ;
return;
}
}
F_5 ( V_5 , V_31 , V_79 ) ;
if ( F_3 ( V_5 , V_57 ) == 0 ) {
F_5 ( V_5 , V_57 , 0xA8 ) ;
if ( F_3 ( V_5 , V_57 ) != 0 ) {
F_59 ( L_4 ) ;
V_5 -> V_2 . type = V_112 ;
V_5 -> V_37 |= V_56 | V_55 ;
} else {
F_5 ( V_5 , V_31 , 0 ) ;
F_5 ( V_5 , V_39 , V_40 |
V_113 ) ;
V_102 = F_3 ( V_5 , V_114 ) >> 5 ;
F_5 ( V_5 , V_39 , 0 ) ;
F_5 ( V_5 , V_31 , 0 ) ;
if ( V_102 == 7 )
V_5 -> V_2 . type = V_115 ;
else
F_59 ( L_5 ) ;
}
F_5 ( V_5 , V_57 , 0 ) ;
return;
}
F_5 ( V_5 , V_31 , V_58 ) ;
if ( F_3 ( V_5 , V_57 ) == 0 && ! F_61 ( V_5 ) ) {
F_59 ( L_6 ) ;
F_58 ( V_5 ) ;
return;
}
F_5 ( V_5 , V_31 , 0 ) ;
V_102 = F_3 ( V_5 , V_77 ) ;
F_5 ( V_5 , V_31 , 0xE0 ) ;
V_103 = F_3 ( V_5 , 0x02 ) ;
if ( ! ( ( V_103 ^ V_102 ) & V_78 ) ) {
F_5 ( V_5 , V_31 , 0 ) ;
F_5 ( V_5 , V_77 , V_102 ^ V_78 ) ;
F_5 ( V_5 , V_31 , 0xE0 ) ;
V_103 = F_3 ( V_5 , 0x02 ) ;
F_5 ( V_5 , V_31 , 0 ) ;
F_5 ( V_5 , V_77 , V_102 ) ;
if ( ( V_103 ^ V_102 ) & V_78 ) {
unsigned short V_116 ;
F_5 ( V_5 , V_31 , 0xE0 ) ;
V_116 = F_54 ( V_5 ) ;
V_116 <<= 3 ;
if ( F_63 ( V_5 ) )
F_55 ( V_5 , V_116 ) ;
F_5 ( V_5 , V_31 , 0 ) ;
V_5 -> V_2 . V_66 = 921600 * 16 ;
V_5 -> V_2 . type = V_117 ;
V_5 -> V_37 |= V_118 ;
return;
}
}
F_5 ( V_5 , V_31 , 0 ) ;
F_5 ( V_5 , V_39 , V_40 | V_113 ) ;
V_102 = F_3 ( V_5 , V_114 ) >> 5 ;
F_5 ( V_5 , V_39 , V_40 ) ;
F_5 ( V_5 , V_31 , V_79 ) ;
F_5 ( V_5 , V_39 , V_40 | V_113 ) ;
V_103 = F_3 ( V_5 , V_114 ) >> 5 ;
F_5 ( V_5 , V_39 , V_40 ) ;
F_5 ( V_5 , V_31 , 0 ) ;
F_59 ( L_7 , V_102 , V_103 ) ;
if ( V_102 == 6 && V_103 == 7 ) {
V_5 -> V_2 . type = V_119 ;
V_5 -> V_37 |= V_111 | V_55 ;
return;
}
V_106 = F_3 ( V_5 , V_60 ) ;
F_5 ( V_5 , V_60 , V_106 & ~ V_120 ) ;
if ( ! ( F_3 ( V_5 , V_60 ) & V_120 ) ) {
F_5 ( V_5 , V_60 , V_106 | V_120 ) ;
if ( F_3 ( V_5 , V_60 ) & V_120 ) {
F_59 ( L_8 ) ;
V_5 -> V_2 . type = V_121 ;
V_5 -> V_37 |= V_122 | V_123 ;
return;
}
} else {
F_59 ( L_9 ) ;
}
F_5 ( V_5 , V_60 , V_106 ) ;
if ( V_5 -> V_2 . V_108 & V_109 ) {
F_59 ( L_10 ) ;
V_5 -> V_2 . type = V_52 ;
V_5 -> V_37 |= V_111 | V_56 |
V_55 ;
return;
}
if ( V_5 -> V_2 . type == V_107 && F_53 ( V_5 ) == 64 ) {
V_5 -> V_2 . type = V_124 ;
V_5 -> V_37 |= V_111 ;
}
}
static void F_64 ( struct V_4 * V_5 )
{
unsigned char V_102 , V_101 , V_125 , V_126 ;
unsigned char V_127 , V_128 ;
struct V_1 * V_2 = & V_5 -> V_2 ;
unsigned long V_108 ;
unsigned int V_129 ;
if ( ! V_2 -> V_17 && ! V_2 -> V_130 && ! V_2 -> V_13 )
return;
F_59 ( L_11 ,
F_1 ( V_2 ) , V_2 -> V_17 , V_2 -> V_13 ) ;
F_65 ( & V_2 -> V_69 , V_108 ) ;
V_5 -> V_37 = 0 ;
V_5 -> V_96 = 0 ;
if ( ! ( V_2 -> V_108 & V_131 ) ) {
V_101 = F_3 ( V_5 , V_60 ) ;
F_5 ( V_5 , V_60 , 0 ) ;
#ifdef F_66
F_14 ( 0xff , 0x080 ) ;
#endif
V_125 = F_3 ( V_5 , V_60 ) & 0x0f ;
F_5 ( V_5 , V_60 , 0x0F ) ;
#ifdef F_66
F_14 ( 0 , 0x080 ) ;
#endif
V_126 = F_3 ( V_5 , V_60 ) & 0x0f ;
F_5 ( V_5 , V_60 , V_101 ) ;
if ( V_125 != 0 || V_126 != 0x0F ) {
F_67 ( & V_2 -> V_69 , V_108 ) ;
F_59 ( L_12 ,
V_125 , V_126 ) ;
goto V_54;
}
}
V_128 = F_3 ( V_5 , V_77 ) ;
V_127 = F_3 ( V_5 , V_31 ) ;
if ( ! ( V_2 -> V_108 & V_132 ) ) {
F_5 ( V_5 , V_77 , V_78 | 0x0A ) ;
V_102 = F_3 ( V_5 , V_133 ) & 0xF0 ;
F_5 ( V_5 , V_77 , V_128 ) ;
if ( V_102 != 0x90 ) {
F_67 ( & V_2 -> V_69 , V_108 ) ;
F_59 ( L_13 ,
V_102 ) ;
goto V_54;
}
}
F_5 ( V_5 , V_31 , V_58 ) ;
F_5 ( V_5 , V_57 , 0 ) ;
F_5 ( V_5 , V_31 , 0 ) ;
F_5 ( V_5 , V_39 , V_40 ) ;
V_101 = F_3 ( V_5 , V_114 ) >> 6 ;
switch ( V_101 ) {
case 0 :
F_60 ( V_5 ) ;
break;
case 1 :
V_2 -> type = V_134 ;
break;
case 2 :
V_2 -> type = V_135 ;
break;
case 3 :
F_62 ( V_5 ) ;
break;
}
#ifdef F_68
if ( V_2 -> type == V_107 && V_5 -> V_136 & V_137 &&
F_48 ( V_5 ) )
V_2 -> type = V_68 ;
#endif
F_5 ( V_5 , V_31 , V_127 ) ;
V_2 -> V_138 = V_139 [ V_5 -> V_2 . type ] . V_140 ;
V_129 = V_5 -> V_37 ;
V_5 -> V_37 = V_139 [ V_2 -> type ] . V_108 ;
V_5 -> V_141 = V_139 [ V_2 -> type ] . V_141 ;
if ( V_2 -> type == V_134 )
goto V_142;
#ifdef F_68
if ( V_2 -> type == V_68 )
F_5 ( V_5 , V_70 , 0 ) ;
#endif
F_5 ( V_5 , V_77 , V_128 ) ;
F_37 ( V_5 ) ;
F_3 ( V_5 , V_83 ) ;
if ( V_5 -> V_37 & V_122 )
F_5 ( V_5 , V_60 , V_120 ) ;
else
F_5 ( V_5 , V_60 , 0 ) ;
V_142:
F_67 ( & V_2 -> V_69 , V_108 ) ;
if ( V_5 -> V_37 != V_129 ) {
F_69 ( V_143
L_14 ,
F_1 ( V_2 ) , V_129 ,
V_5 -> V_37 ) ;
}
V_54:
F_59 ( L_15 , V_101 ) ;
F_59 ( L_16 , V_139 [ V_2 -> type ] . V_144 ) ;
}
static void F_70 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = & V_5 -> V_2 ;
unsigned char V_128 , V_145 ;
unsigned char V_146 = 0 ;
unsigned int V_147 = 0 ;
unsigned long V_148 ;
int V_149 ;
if ( V_2 -> V_108 & V_150 ) {
V_147 = ( V_2 -> V_17 & 0xfe0 ) | 0x1f ;
V_146 = F_71 ( V_147 ) ;
F_72 ( 0x80 , V_147 ) ;
F_71 ( V_147 ) ;
}
F_73 ( F_74 () ) ;
V_128 = F_3 ( V_5 , V_77 ) ;
V_145 = F_3 ( V_5 , V_60 ) ;
F_5 ( V_5 , V_77 , V_151 | V_152 ) ;
V_148 = F_74 () ;
F_5 ( V_5 , V_77 , 0 ) ;
F_75 ( 10 ) ;
if ( V_2 -> V_108 & V_150 ) {
F_5 ( V_5 , V_77 ,
V_153 | V_154 ) ;
} else {
F_5 ( V_5 , V_77 ,
V_153 | V_154 | V_152 ) ;
}
F_5 ( V_5 , V_60 , 0x0f ) ;
F_3 ( V_5 , V_81 ) ;
F_3 ( V_5 , V_83 ) ;
F_3 ( V_5 , V_114 ) ;
F_3 ( V_5 , V_133 ) ;
F_5 ( V_5 , V_80 , 0xFF ) ;
F_75 ( 20 ) ;
V_149 = F_73 ( V_148 ) ;
F_5 ( V_5 , V_77 , V_128 ) ;
F_5 ( V_5 , V_60 , V_145 ) ;
if ( V_2 -> V_108 & V_150 )
F_72 ( V_146 , V_147 ) ;
V_2 -> V_149 = ( V_149 > 0 ) ? V_149 : 0 ;
}
static inline void F_76 ( struct V_4 * V_9 )
{
if ( V_9 -> V_155 & V_156 ) {
V_9 -> V_155 &= ~ V_156 ;
F_5 ( V_9 , V_60 , V_9 -> V_155 ) ;
F_46 ( V_9 ) ;
}
}
static void F_77 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_32 ( V_2 ) ;
F_39 ( V_5 ) ;
F_76 ( V_5 ) ;
if ( V_2 -> type == V_95 ) {
V_5 -> V_35 |= V_157 ;
F_35 ( V_5 , V_34 , V_5 -> V_35 ) ;
}
F_41 ( V_5 ) ;
}
static void F_78 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_32 ( V_2 ) ;
F_44 ( V_5 ) ;
if ( V_5 -> V_158 && ! V_5 -> V_158 -> V_159 ( V_5 ) )
return;
if ( ! ( V_5 -> V_155 & V_156 ) ) {
V_5 -> V_155 |= V_156 ;
F_79 ( V_2 , V_60 , V_5 -> V_155 ) ;
if ( V_5 -> V_96 & V_160 ) {
unsigned char V_161 ;
V_161 = F_3 ( V_5 , V_81 ) ;
V_5 -> V_162 |= V_161 & V_163 ;
if ( V_161 & V_164 )
F_80 ( V_5 ) ;
}
}
if ( V_2 -> type == V_95 && V_5 -> V_35 & V_157 ) {
V_5 -> V_35 &= ~ V_157 ;
F_35 ( V_5 , V_34 , V_5 -> V_35 ) ;
}
}
static void F_81 ( struct V_1 * V_2 )
{
V_2 -> V_165 ( V_2 ) ;
}
static void F_82 ( struct V_1 * V_2 )
{
V_2 -> V_166 ( V_2 ) ;
}
static void F_83 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_32 ( V_2 ) ;
F_39 ( V_5 ) ;
V_5 -> V_155 &= ~ ( V_167 | V_168 ) ;
V_5 -> V_2 . V_169 &= ~ V_82 ;
F_79 ( V_2 , V_60 , V_5 -> V_155 ) ;
F_41 ( V_5 ) ;
}
static void F_84 ( struct V_1 * V_2 )
{
struct V_4 * V_5 =
F_85 ( V_2 , struct V_4 , V_2 ) ;
if ( V_5 -> V_96 & V_170 )
return;
V_5 -> V_155 &= ~ V_171 ;
F_79 ( V_2 , V_60 , V_5 -> V_155 ) ;
}
static void F_86 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_32 ( V_2 ) ;
if ( V_5 -> V_96 & V_170 )
return;
V_5 -> V_155 |= V_171 ;
F_39 ( V_5 ) ;
F_79 ( V_2 , V_60 , V_5 -> V_155 ) ;
F_41 ( V_5 ) ;
}
unsigned char
F_87 ( struct V_4 * V_5 , unsigned char V_161 )
{
struct V_1 * V_2 = & V_5 -> V_2 ;
unsigned char V_172 ;
int V_173 = 256 ;
char V_174 ;
do {
if ( F_88 ( V_161 & V_82 ) )
V_172 = F_3 ( V_5 , V_83 ) ;
else
V_172 = 0 ;
V_174 = V_175 ;
V_2 -> V_176 . V_177 ++ ;
V_161 |= V_5 -> V_162 ;
V_5 -> V_162 = 0 ;
if ( F_89 ( V_161 & V_178 ) ) {
if ( V_161 & V_179 ) {
V_161 &= ~ ( V_180 | V_181 ) ;
V_2 -> V_176 . V_182 ++ ;
if ( F_90 ( V_2 ) )
goto V_183;
} else if ( V_161 & V_181 )
V_2 -> V_176 . V_184 ++ ;
else if ( V_161 & V_180 )
V_2 -> V_176 . V_185 ++ ;
if ( V_161 & V_186 )
V_2 -> V_176 . V_187 ++ ;
V_161 &= V_2 -> V_169 ;
if ( V_161 & V_179 ) {
F_91 ( L_17 ) ;
V_174 = V_188 ;
} else if ( V_161 & V_181 )
V_174 = V_189 ;
else if ( V_161 & V_180 )
V_174 = V_190 ;
}
if ( F_92 ( V_2 , V_172 ) )
goto V_183;
F_93 ( V_2 , V_161 , V_186 , V_172 , V_174 ) ;
V_183:
V_161 = F_3 ( V_5 , V_81 ) ;
} while ( ( V_161 & ( V_82 | V_179 ) ) && ( -- V_173 > 0 ) );
F_94 ( & V_2 -> V_69 ) ;
F_95 ( & V_2 -> V_191 -> V_2 ) ;
F_96 ( & V_2 -> V_69 ) ;
return V_161 ;
}
void F_80 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = & V_5 -> V_2 ;
struct V_192 * V_193 = & V_2 -> V_191 -> V_193 ;
int V_76 ;
if ( V_2 -> V_194 ) {
F_5 ( V_5 , V_80 , V_2 -> V_194 ) ;
V_2 -> V_176 . V_195 ++ ;
V_2 -> V_194 = 0 ;
return;
}
if ( F_97 ( V_2 ) ) {
F_77 ( V_2 ) ;
return;
}
if ( F_98 ( V_193 ) ) {
F_76 ( V_5 ) ;
return;
}
V_76 = V_5 -> V_141 ;
do {
F_5 ( V_5 , V_80 , V_193 -> V_196 [ V_193 -> V_197 ] ) ;
V_193 -> V_197 = ( V_193 -> V_197 + 1 ) & ( V_198 - 1 ) ;
V_2 -> V_176 . V_195 ++ ;
if ( F_98 ( V_193 ) )
break;
if ( V_5 -> V_37 & V_199 ) {
if ( ( F_99 ( V_2 , V_81 ) & V_200 ) !=
V_200 )
break;
}
} while ( -- V_76 > 0 );
if ( F_100 ( V_193 ) < V_201 )
F_101 ( V_2 ) ;
F_91 ( L_18 ) ;
if ( F_98 ( V_193 ) && ! ( V_5 -> V_37 & V_44 ) )
F_76 ( V_5 ) ;
}
unsigned int F_102 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = & V_5 -> V_2 ;
unsigned int V_202 = F_3 ( V_5 , V_133 ) ;
V_202 |= V_5 -> V_203 ;
V_5 -> V_203 = 0 ;
if ( V_202 & V_204 && V_5 -> V_155 & V_171 &&
V_2 -> V_191 != NULL ) {
if ( V_202 & V_205 )
V_2 -> V_176 . V_206 ++ ;
if ( V_202 & V_207 )
V_2 -> V_176 . V_208 ++ ;
if ( V_202 & V_209 )
F_103 ( V_2 , V_202 & V_210 ) ;
if ( V_202 & V_211 )
F_104 ( V_2 , V_202 & V_212 ) ;
F_105 ( & V_2 -> V_191 -> V_2 . V_213 ) ;
}
return V_202 ;
}
int F_106 ( struct V_1 * V_2 , unsigned int V_214 )
{
unsigned char V_202 ;
unsigned long V_108 ;
struct V_4 * V_5 = F_32 ( V_2 ) ;
int V_215 = 0 ;
if ( V_214 & V_216 )
return 0 ;
F_65 ( & V_2 -> V_69 , V_108 ) ;
V_202 = F_99 ( V_2 , V_81 ) ;
F_91 ( L_19 , V_202 ) ;
if ( V_202 & ( V_82 | V_179 ) ) {
if ( V_5 -> V_158 )
V_215 = V_5 -> V_158 -> V_217 ( V_5 , V_214 ) ;
if ( ! V_5 -> V_158 || V_215 )
V_202 = F_87 ( V_5 , V_202 ) ;
}
F_102 ( V_5 ) ;
if ( ( ! V_5 -> V_158 || ( V_5 -> V_158 && V_5 -> V_158 -> V_218 ) ) &&
( V_202 & V_164 ) )
F_80 ( V_5 ) ;
F_67 ( & V_2 -> V_69 , V_108 ) ;
return 1 ;
}
static int V_30 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_32 ( V_2 ) ;
unsigned int V_214 ;
int V_219 ;
F_39 ( V_5 ) ;
V_214 = F_99 ( V_2 , V_114 ) ;
V_219 = F_106 ( V_2 , V_214 ) ;
F_41 ( V_5 ) ;
return V_219 ;
}
static int F_107 ( struct V_1 * V_2 )
{
unsigned char V_220 , V_221 , V_222 , V_223 ;
unsigned int V_214 = F_99 ( V_2 , V_114 ) ;
int V_219 ;
V_219 = F_106 ( V_2 , V_214 ) ;
if ( ( V_2 -> type == V_51 ) ||
( V_2 -> type == V_52 ) ) {
V_220 = F_99 ( V_2 , 0x80 ) ;
V_221 = F_99 ( V_2 , 0x81 ) ;
V_222 = F_99 ( V_2 , 0x82 ) ;
V_223 = F_99 ( V_2 , 0x83 ) ;
}
return V_219 ;
}
static T_1 F_108 ( int V_149 , void * V_224 )
{
struct V_225 * V_226 = V_224 ;
struct V_227 * V_228 , * V_229 = NULL ;
int V_230 = 0 , V_231 = 0 ;
F_91 ( L_20 , V_149 ) ;
F_96 ( & V_226 -> V_69 ) ;
V_228 = V_226 -> V_232 ;
do {
struct V_4 * V_5 ;
struct V_1 * V_2 ;
V_5 = F_109 ( V_228 , struct V_4 , V_233 ) ;
V_2 = & V_5 -> V_2 ;
if ( V_2 -> V_29 ( V_2 ) ) {
V_231 = 1 ;
V_229 = NULL ;
} else if ( V_229 == NULL )
V_229 = V_228 ;
V_228 = V_228 -> V_234 ;
if ( V_228 == V_226 -> V_232 && V_230 ++ > V_235 ) {
F_110 ( V_236
L_21 , V_149 ) ;
break;
}
} while ( V_228 != V_229 );
F_94 ( & V_226 -> V_69 ) ;
F_91 ( L_22 ) ;
return F_111 ( V_231 ) ;
}
static void F_112 ( struct V_225 * V_226 , struct V_4 * V_5 )
{
F_50 ( & V_226 -> V_69 ) ;
if ( ! F_113 ( V_226 -> V_232 ) ) {
if ( V_226 -> V_232 == & V_5 -> V_233 )
V_226 -> V_232 = V_226 -> V_232 -> V_234 ;
F_114 ( & V_5 -> V_233 ) ;
} else {
F_115 ( V_226 -> V_232 != & V_5 -> V_233 ) ;
V_226 -> V_232 = NULL ;
}
F_51 ( & V_226 -> V_69 ) ;
if ( V_226 -> V_232 == NULL ) {
F_116 ( & V_226 -> V_237 ) ;
F_117 ( V_226 ) ;
}
}
static int F_118 ( struct V_4 * V_5 )
{
struct V_238 * V_239 ;
struct V_240 * V_241 ;
struct V_225 * V_226 ;
int V_219 , V_242 = V_5 -> V_2 . V_108 & V_243 ? V_244 : 0 ;
F_119 ( & V_245 ) ;
V_239 = & V_246 [ V_5 -> V_2 . V_149 % V_247 ] ;
F_120 (n, h) {
V_226 = F_121 ( V_241 , struct V_225 , V_237 ) ;
if ( V_226 -> V_149 == V_5 -> V_2 . V_149 )
break;
}
if ( V_241 == NULL ) {
V_226 = F_122 ( sizeof( struct V_225 ) , V_248 ) ;
if ( V_226 == NULL ) {
F_123 ( & V_245 ) ;
return - V_249 ;
}
F_124 ( & V_226 -> V_69 ) ;
V_226 -> V_149 = V_5 -> V_2 . V_149 ;
F_125 ( & V_226 -> V_237 , V_239 ) ;
}
F_123 ( & V_245 ) ;
F_50 ( & V_226 -> V_69 ) ;
if ( V_226 -> V_232 ) {
F_126 ( & V_5 -> V_233 , V_226 -> V_232 ) ;
F_51 ( & V_226 -> V_69 ) ;
V_219 = 0 ;
} else {
F_127 ( & V_5 -> V_233 ) ;
V_226 -> V_232 = & V_5 -> V_233 ;
F_51 ( & V_226 -> V_69 ) ;
V_242 |= V_5 -> V_2 . V_250 ;
V_219 = F_128 ( V_5 -> V_2 . V_149 , F_108 ,
V_242 , L_23 , V_226 ) ;
if ( V_219 < 0 )
F_112 ( V_226 , V_5 ) ;
}
return V_219 ;
}
static void F_129 ( struct V_4 * V_5 )
{
struct V_225 * V_226 ;
struct V_240 * V_241 ;
struct V_238 * V_239 ;
F_119 ( & V_245 ) ;
V_239 = & V_246 [ V_5 -> V_2 . V_149 % V_247 ] ;
F_120 (n, h) {
V_226 = F_121 ( V_241 , struct V_225 , V_237 ) ;
if ( V_226 -> V_149 == V_5 -> V_2 . V_149 )
break;
}
F_115 ( V_241 == NULL ) ;
F_115 ( V_226 -> V_232 == NULL ) ;
if ( F_113 ( V_226 -> V_232 ) )
F_130 ( V_5 -> V_2 . V_149 , V_226 ) ;
F_112 ( V_226 , V_5 ) ;
F_123 ( & V_245 ) ;
}
static void F_131 ( unsigned long V_251 )
{
struct V_4 * V_5 = (struct V_4 * ) V_251 ;
V_5 -> V_2 . V_29 ( & V_5 -> V_2 ) ;
F_132 ( & V_5 -> V_252 , V_253 + F_133 ( & V_5 -> V_2 ) ) ;
}
static void F_134 ( unsigned long V_251 )
{
struct V_4 * V_5 = (struct V_4 * ) V_251 ;
unsigned int V_214 , V_155 = 0 , V_161 ;
unsigned long V_108 ;
F_65 ( & V_5 -> V_2 . V_69 , V_108 ) ;
if ( V_5 -> V_2 . V_149 ) {
V_155 = F_3 ( V_5 , V_60 ) ;
F_5 ( V_5 , V_60 , 0 ) ;
}
V_214 = F_3 ( V_5 , V_114 ) ;
V_161 = F_3 ( V_5 , V_81 ) ;
V_5 -> V_162 |= V_161 & V_163 ;
if ( ( V_214 & V_216 ) && ( V_5 -> V_155 & V_156 ) &&
( ! F_98 ( & V_5 -> V_2 . V_191 -> V_193 ) || V_5 -> V_2 . V_194 ) &&
( V_161 & V_164 ) ) {
V_214 &= ~ ( V_254 | V_216 ) ;
V_214 |= V_255 ;
}
if ( ! ( V_214 & V_216 ) )
F_80 ( V_5 ) ;
if ( V_5 -> V_2 . V_149 )
F_5 ( V_5 , V_60 , V_155 ) ;
F_67 ( & V_5 -> V_2 . V_69 , V_108 ) ;
F_132 ( & V_5 -> V_252 ,
V_253 + F_133 ( & V_5 -> V_2 ) + V_256 / 5 ) ;
}
static int F_135 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = & V_5 -> V_2 ;
int V_257 = 0 ;
if ( V_5 -> V_96 & V_258 ) {
F_136 ( L_24 , F_1 ( V_2 ) ) ;
V_5 -> V_252 . V_259 = F_134 ;
V_5 -> V_252 . V_251 = ( unsigned long ) V_5 ;
F_132 ( & V_5 -> V_252 , V_253 +
F_133 ( V_2 ) + V_256 / 5 ) ;
}
if ( ! V_2 -> V_149 ) {
V_5 -> V_252 . V_251 = ( unsigned long ) V_5 ;
F_132 ( & V_5 -> V_252 , V_253 + F_133 ( V_2 ) ) ;
} else
V_257 = F_118 ( V_5 ) ;
return V_257 ;
}
static void F_137 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = & V_5 -> V_2 ;
F_138 ( & V_5 -> V_252 ) ;
V_5 -> V_252 . V_259 = F_131 ;
if ( V_2 -> V_149 )
F_129 ( V_5 ) ;
}
static unsigned int F_139 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_32 ( V_2 ) ;
unsigned long V_108 ;
unsigned int V_161 ;
F_39 ( V_5 ) ;
F_65 ( & V_2 -> V_69 , V_108 ) ;
V_161 = F_99 ( V_2 , V_81 ) ;
V_5 -> V_162 |= V_161 & V_163 ;
F_67 ( & V_2 -> V_69 , V_108 ) ;
F_41 ( V_5 ) ;
return ( V_161 & V_200 ) == V_200 ? V_260 : 0 ;
}
static unsigned int F_140 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_32 ( V_2 ) ;
unsigned int V_202 ;
unsigned int V_219 ;
F_39 ( V_5 ) ;
V_202 = F_102 ( V_5 ) ;
F_41 ( V_5 ) ;
V_219 = 0 ;
if ( V_202 & V_210 )
V_219 |= V_261 ;
if ( V_202 & V_262 )
V_219 |= V_263 ;
if ( V_202 & V_264 )
V_219 |= V_265 ;
if ( V_202 & V_212 )
V_219 |= V_266 ;
return V_219 ;
}
void F_141 ( struct V_1 * V_2 , unsigned int V_267 )
{
struct V_4 * V_5 = F_32 ( V_2 ) ;
unsigned char V_268 = 0 ;
if ( V_267 & V_269 )
V_268 |= V_154 ;
if ( V_267 & V_270 )
V_268 |= V_153 ;
if ( V_267 & V_271 )
V_268 |= V_151 ;
if ( V_267 & V_272 )
V_268 |= V_152 ;
if ( V_267 & V_273 )
V_268 |= V_78 ;
V_268 = ( V_268 & V_5 -> V_274 ) | V_5 -> V_275 | V_5 -> V_268 ;
F_79 ( V_2 , V_77 , V_268 ) ;
}
static void F_142 ( struct V_1 * V_2 , unsigned int V_267 )
{
if ( V_2 -> V_276 )
return V_2 -> V_276 ( V_2 , V_267 ) ;
return F_141 ( V_2 , V_267 ) ;
}
static void F_143 ( struct V_1 * V_2 , int V_277 )
{
struct V_4 * V_5 = F_32 ( V_2 ) ;
unsigned long V_108 ;
F_39 ( V_5 ) ;
F_65 ( & V_2 -> V_69 , V_108 ) ;
if ( V_277 == - 1 )
V_5 -> V_49 |= V_278 ;
else
V_5 -> V_49 &= ~ V_278 ;
F_79 ( V_2 , V_31 , V_5 -> V_49 ) ;
F_67 ( & V_2 -> V_69 , V_108 ) ;
F_41 ( V_5 ) ;
}
static void F_144 ( struct V_4 * V_5 , int V_279 )
{
unsigned int V_202 , V_280 = 10000 ;
for (; ; ) {
V_202 = F_3 ( V_5 , V_81 ) ;
V_5 -> V_162 |= V_202 & V_163 ;
if ( ( V_202 & V_279 ) == V_279 )
break;
if ( -- V_280 == 0 )
break;
F_75 ( 1 ) ;
}
if ( V_5 -> V_2 . V_108 & V_281 ) {
unsigned int V_280 ;
for ( V_280 = 1000000 ; V_280 ; V_280 -- ) {
unsigned int V_282 = F_3 ( V_5 , V_133 ) ;
V_5 -> V_203 |= V_282 & V_283 ;
if ( V_282 & V_212 )
break;
F_75 ( 1 ) ;
F_145 () ;
}
}
}
static int F_146 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_32 ( V_2 ) ;
unsigned char V_161 ;
int V_202 ;
F_39 ( V_5 ) ;
V_161 = F_99 ( V_2 , V_81 ) ;
if ( ! ( V_161 & V_82 ) ) {
V_202 = V_284 ;
goto V_54;
}
V_202 = F_99 ( V_2 , V_83 ) ;
V_54:
F_41 ( V_5 ) ;
return V_202 ;
}
static void F_147 ( struct V_1 * V_2 ,
unsigned char V_285 )
{
unsigned int V_155 ;
struct V_4 * V_5 = F_32 ( V_2 ) ;
F_39 ( V_5 ) ;
V_155 = F_99 ( V_2 , V_60 ) ;
if ( V_5 -> V_37 & V_122 )
F_79 ( V_2 , V_60 , V_120 ) ;
else
F_79 ( V_2 , V_60 , 0 ) ;
F_144 ( V_5 , V_200 ) ;
F_79 ( V_2 , V_80 , V_285 ) ;
F_144 ( V_5 , V_200 ) ;
F_79 ( V_2 , V_60 , V_155 ) ;
F_41 ( V_5 ) ;
}
int F_148 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_32 ( V_2 ) ;
unsigned long V_108 ;
unsigned char V_161 , V_214 ;
int V_257 ;
if ( V_2 -> type == V_286 )
return - V_287 ;
if ( ! V_2 -> V_138 )
V_2 -> V_138 = V_139 [ V_2 -> type ] . V_140 ;
if ( ! V_5 -> V_141 )
V_5 -> V_141 = V_139 [ V_2 -> type ] . V_141 ;
if ( ! V_5 -> V_37 )
V_5 -> V_37 = V_139 [ V_2 -> type ] . V_108 ;
V_5 -> V_268 = 0 ;
if ( V_2 -> V_20 != V_5 -> V_28 )
F_31 ( V_2 ) ;
F_39 ( V_5 ) ;
if ( V_2 -> type == V_95 ) {
V_5 -> V_35 = 0 ;
F_79 ( V_2 , V_31 , V_58 ) ;
F_79 ( V_2 , V_57 , V_59 ) ;
F_79 ( V_2 , V_60 , 0 ) ;
F_79 ( V_2 , V_31 , 0 ) ;
F_35 ( V_5 , V_288 , 0 ) ;
F_79 ( V_2 , V_31 , V_58 ) ;
F_79 ( V_2 , V_57 , V_59 ) ;
F_79 ( V_2 , V_31 , 0 ) ;
}
#ifdef F_68
F_49 ( V_5 ) ;
#endif
F_37 ( V_5 ) ;
F_99 ( V_2 , V_81 ) ;
F_99 ( V_2 , V_83 ) ;
F_99 ( V_2 , V_114 ) ;
F_99 ( V_2 , V_133 ) ;
if ( ! ( V_2 -> V_108 & V_131 ) &&
( F_99 ( V_2 , V_81 ) == 0xff ) ) {
F_110 ( V_289 L_25 ,
F_1 ( V_2 ) ) ;
V_257 = - V_287 ;
goto V_54;
}
if ( V_2 -> type == V_98 ) {
unsigned char V_290 ;
F_5 ( V_5 , V_31 , V_58 ) ;
V_290 = F_3 ( V_5 , V_291 ) & ~ ( V_292 | V_293 ) ;
F_79 ( V_2 , V_291 ,
V_290 | V_294 | V_292 ) ;
F_79 ( V_2 , V_295 , V_296 ) ;
F_79 ( V_2 , V_291 ,
V_290 | V_294 | V_293 ) ;
F_79 ( V_2 , V_295 , V_296 ) ;
F_79 ( V_2 , V_31 , 0 ) ;
}
if ( V_2 -> V_149 ) {
unsigned char V_297 ;
F_65 ( & V_2 -> V_69 , V_108 ) ;
if ( V_5 -> V_2 . V_250 & V_244 )
F_149 ( V_2 -> V_149 ) ;
F_144 ( V_5 , V_164 ) ;
F_34 ( V_2 , V_60 , V_156 ) ;
F_75 ( 1 ) ;
V_297 = F_99 ( V_2 , V_114 ) ;
F_79 ( V_2 , V_60 , 0 ) ;
F_34 ( V_2 , V_60 , V_156 ) ;
F_75 ( 1 ) ;
V_214 = F_99 ( V_2 , V_114 ) ;
F_79 ( V_2 , V_60 , 0 ) ;
if ( V_2 -> V_250 & V_244 )
F_150 ( V_2 -> V_149 ) ;
F_67 ( & V_2 -> V_69 , V_108 ) ;
if ( ( ! ( V_297 & V_216 ) && ( V_214 & V_216 ) ) ||
V_5 -> V_2 . V_108 & V_298 ) {
V_5 -> V_96 |= V_258 ;
}
}
V_257 = V_5 -> V_299 -> V_300 ( V_5 ) ;
if ( V_257 )
goto V_54;
F_79 ( V_2 , V_31 , V_301 ) ;
F_65 ( & V_2 -> V_69 , V_108 ) ;
if ( V_5 -> V_2 . V_108 & V_150 ) {
if ( ! V_5 -> V_2 . V_149 )
V_5 -> V_2 . V_267 |= V_271 ;
} else
if ( V_2 -> V_149 )
V_5 -> V_2 . V_267 |= V_272 ;
F_142 ( V_2 , V_2 -> V_267 ) ;
if ( V_5 -> V_2 . V_108 & V_302 )
goto V_303;
F_79 ( V_2 , V_60 , V_156 ) ;
V_161 = F_99 ( V_2 , V_81 ) ;
V_214 = F_99 ( V_2 , V_114 ) ;
F_79 ( V_2 , V_60 , 0 ) ;
if ( V_161 & V_304 && V_214 & V_216 ) {
if ( ! ( V_5 -> V_96 & V_160 ) ) {
V_5 -> V_96 |= V_160 ;
F_136 ( L_26 ,
F_1 ( V_2 ) ) ;
}
} else {
V_5 -> V_96 &= ~ V_160 ;
}
V_303:
F_67 ( & V_2 -> V_69 , V_108 ) ;
F_99 ( V_2 , V_81 ) ;
F_99 ( V_2 , V_83 ) ;
F_99 ( V_2 , V_114 ) ;
F_99 ( V_2 , V_133 ) ;
V_5 -> V_162 = 0 ;
V_5 -> V_203 = 0 ;
if ( V_5 -> V_158 ) {
V_257 = F_151 ( V_5 ) ;
if ( V_257 ) {
F_152 ( L_27 ,
F_1 ( V_2 ) ) ;
V_5 -> V_158 = NULL ;
}
}
V_5 -> V_155 = V_167 | V_168 ;
F_79 ( V_2 , V_60 , V_5 -> V_155 ) ;
if ( V_2 -> V_108 & V_150 ) {
unsigned int V_305 ;
V_305 = ( V_2 -> V_17 & 0xfe0 ) | 0x01f ;
F_72 ( 0x80 , V_305 ) ;
F_71 ( V_305 ) ;
}
V_257 = 0 ;
V_54:
F_41 ( V_5 ) ;
return V_257 ;
}
static int F_153 ( struct V_1 * V_2 )
{
if ( V_2 -> V_306 )
return V_2 -> V_306 ( V_2 ) ;
return F_148 ( V_2 ) ;
}
void F_154 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_32 ( V_2 ) ;
unsigned long V_108 ;
F_39 ( V_5 ) ;
V_5 -> V_155 = 0 ;
F_79 ( V_2 , V_60 , 0 ) ;
if ( V_5 -> V_158 )
F_155 ( V_5 ) ;
F_65 ( & V_2 -> V_69 , V_108 ) ;
if ( V_2 -> V_108 & V_150 ) {
F_15 ( ( V_2 -> V_17 & 0xfe0 ) | 0x1f ) ;
V_2 -> V_267 |= V_271 ;
} else
V_2 -> V_267 &= ~ V_272 ;
F_142 ( V_2 , V_2 -> V_267 ) ;
F_67 ( & V_2 -> V_69 , V_108 ) ;
F_79 ( V_2 , V_31 ,
F_99 ( V_2 , V_31 ) & ~ V_278 ) ;
F_37 ( V_5 ) ;
#ifdef F_68
F_52 ( V_5 ) ;
#endif
F_99 ( V_2 , V_83 ) ;
F_41 ( V_5 ) ;
V_5 -> V_299 -> V_307 ( V_5 ) ;
}
static void F_156 ( struct V_1 * V_2 )
{
if ( V_2 -> V_308 )
V_2 -> V_308 ( V_2 ) ;
else
F_154 ( V_2 ) ;
}
static unsigned int F_157 ( struct V_4 * V_5 ,
unsigned int V_309 ,
unsigned int * V_310 )
{
struct V_1 * V_2 = & V_5 -> V_2 ;
unsigned int V_311 ;
V_311 = F_158 ( V_2 -> V_66 , V_309 ) ;
* V_310 = V_311 & 0x0f ;
return V_311 >> 4 ;
}
static unsigned int F_159 ( struct V_4 * V_5 ,
unsigned int V_309 ,
unsigned int * V_310 )
{
struct V_1 * V_2 = & V_5 -> V_2 ;
unsigned int V_116 ;
if ( ( V_2 -> V_108 & V_312 ) &&
V_309 == ( V_2 -> V_66 / 4 ) )
V_116 = 0x8001 ;
else if ( ( V_2 -> V_108 & V_312 ) &&
V_309 == ( V_2 -> V_66 / 8 ) )
V_116 = 0x8002 ;
else if ( V_5 -> V_2 . type == V_51 )
V_116 = F_157 ( V_5 , V_309 , V_310 ) ;
else
V_116 = F_160 ( V_2 , V_309 ) ;
if ( V_5 -> V_96 & V_97 && ( V_116 & 0xff ) == 0 )
V_116 ++ ;
return V_116 ;
}
static unsigned char F_161 ( struct V_4 * V_5 ,
T_2 V_313 )
{
unsigned char V_314 ;
switch ( V_313 & V_315 ) {
case V_316 :
V_314 = V_317 ;
break;
case V_318 :
V_314 = V_319 ;
break;
case V_320 :
V_314 = V_321 ;
break;
default:
case V_322 :
V_314 = V_301 ;
break;
}
if ( V_313 & V_323 )
V_314 |= V_324 ;
if ( V_313 & V_325 ) {
V_314 |= V_326 ;
if ( V_5 -> V_96 & V_327 )
V_5 -> V_328 = true ;
}
if ( ! ( V_313 & V_329 ) )
V_314 |= V_330 ;
#ifdef F_162
if ( V_313 & F_162 )
V_314 |= V_331 ;
#endif
return V_314 ;
}
static void F_163 ( struct V_1 * V_2 , unsigned int V_309 ,
unsigned int V_116 , unsigned int V_332 )
{
struct V_4 * V_5 = F_32 ( V_2 ) ;
if ( F_164 ( V_5 ) ) {
if ( V_309 == 115200 ) {
V_116 = 1 ;
F_79 ( V_2 , V_333 , 1 ) ;
} else
F_79 ( V_2 , V_333 , 0 ) ;
}
if ( V_5 -> V_37 & V_118 )
F_79 ( V_2 , V_31 , 0xe0 ) ;
else
F_79 ( V_2 , V_31 , V_5 -> V_49 | V_334 ) ;
F_55 ( V_5 , V_116 ) ;
if ( V_5 -> V_2 . type == V_51 )
F_79 ( V_2 , 0x2 , V_332 ) ;
}
void
F_165 ( struct V_1 * V_2 , struct V_335 * V_336 ,
struct V_335 * V_337 )
{
struct V_4 * V_5 = F_32 ( V_2 ) ;
unsigned char V_314 ;
unsigned long V_108 ;
unsigned int V_309 , V_116 , V_310 = 0 ;
V_314 = F_161 ( V_5 , V_336 -> V_313 ) ;
V_309 = F_166 ( V_2 , V_336 , V_337 ,
V_2 -> V_66 / 16 / 0xffff ,
V_2 -> V_66 / 16 ) ;
V_116 = F_159 ( V_5 , V_309 , & V_310 ) ;
F_39 ( V_5 ) ;
F_65 ( & V_2 -> V_69 , V_108 ) ;
V_5 -> V_49 = V_314 ;
if ( V_5 -> V_37 & V_38 && V_2 -> V_138 > 1 ) {
if ( ( V_309 < 2400 && ! V_5 -> V_158 ) || V_5 -> V_328 ) {
V_5 -> V_43 &= ~ V_338 ;
V_5 -> V_43 |= V_339 ;
}
}
if ( V_5 -> V_37 & V_111 && V_2 -> V_138 >= 32 ) {
V_5 -> V_268 &= ~ V_340 ;
if ( V_336 -> V_313 & V_341 )
V_5 -> V_268 |= V_340 ;
}
F_167 ( V_2 , V_336 -> V_313 , V_309 ) ;
V_2 -> V_169 = V_186 | V_164 | V_82 ;
if ( V_336 -> V_342 & V_343 )
V_2 -> V_169 |= V_180 | V_181 ;
if ( V_336 -> V_342 & ( V_344 | V_345 | V_346 ) )
V_2 -> V_169 |= V_179 ;
V_2 -> V_347 = 0 ;
if ( V_336 -> V_342 & V_348 )
V_2 -> V_347 |= V_181 | V_180 ;
if ( V_336 -> V_342 & V_344 ) {
V_2 -> V_347 |= V_179 ;
if ( V_336 -> V_342 & V_348 )
V_2 -> V_347 |= V_186 ;
}
if ( ( V_336 -> V_313 & V_349 ) == 0 )
V_2 -> V_347 |= V_82 ;
V_5 -> V_155 &= ~ V_171 ;
if ( ! ( V_5 -> V_96 & V_170 ) &&
F_168 ( & V_5 -> V_2 , V_336 -> V_313 ) )
V_5 -> V_155 |= V_171 ;
if ( V_5 -> V_37 & V_122 )
V_5 -> V_155 |= V_120 ;
if ( V_5 -> V_37 & V_123 )
V_5 -> V_155 |= V_350 ;
F_79 ( V_2 , V_60 , V_5 -> V_155 ) ;
if ( V_5 -> V_37 & V_56 ) {
unsigned char V_50 = 0 ;
if ( V_336 -> V_313 & V_341 )
V_50 |= V_351 ;
F_79 ( V_2 , V_31 , V_58 ) ;
if ( V_2 -> V_108 & V_109 )
F_79 ( V_2 , V_352 , V_50 ) ;
else
F_79 ( V_2 , V_57 , V_50 ) ;
}
F_163 ( V_2 , V_309 , V_116 , V_310 ) ;
if ( V_2 -> type == V_119 )
F_79 ( V_2 , V_39 , V_5 -> V_43 ) ;
F_79 ( V_2 , V_31 , V_5 -> V_49 ) ;
if ( V_2 -> type != V_119 ) {
if ( V_5 -> V_43 & V_40 )
F_79 ( V_2 , V_39 , V_40 ) ;
F_79 ( V_2 , V_39 , V_5 -> V_43 ) ;
}
F_142 ( V_2 , V_2 -> V_267 ) ;
F_67 ( & V_2 -> V_69 , V_108 ) ;
F_41 ( V_5 ) ;
if ( F_169 ( V_336 ) )
F_170 ( V_336 , V_309 , V_309 ) ;
}
static void
F_171 ( struct V_1 * V_2 , struct V_335 * V_336 ,
struct V_335 * V_337 )
{
if ( V_2 -> V_353 )
V_2 -> V_353 ( V_2 , V_336 , V_337 ) ;
else
F_165 ( V_2 , V_336 , V_337 ) ;
}
static void
F_172 ( struct V_1 * V_2 , struct V_335 * V_336 )
{
if ( V_336 -> V_354 == V_355 ) {
V_2 -> V_108 |= V_356 ;
F_50 ( & V_2 -> V_69 ) ;
F_86 ( V_2 ) ;
F_51 ( & V_2 -> V_69 ) ;
} else {
V_2 -> V_108 &= ~ V_356 ;
if ( ! F_168 ( V_2 , V_336 -> V_313 ) ) {
F_50 ( & V_2 -> V_69 ) ;
F_84 ( V_2 ) ;
F_51 ( & V_2 -> V_69 ) ;
}
}
}
void F_173 ( struct V_1 * V_2 , unsigned int V_191 ,
unsigned int V_357 )
{
struct V_4 * V_9 = F_32 ( V_2 ) ;
F_47 ( V_9 , V_191 != 0 ) ;
}
static void
F_174 ( struct V_1 * V_2 , unsigned int V_191 ,
unsigned int V_357 )
{
if ( V_2 -> V_358 )
V_2 -> V_358 ( V_2 , V_191 , V_357 ) ;
else
F_173 ( V_2 , V_191 , V_357 ) ;
}
static unsigned int F_175 ( struct V_4 * V_359 )
{
if ( V_359 -> V_2 . V_360 )
return V_359 -> V_2 . V_360 ;
if ( V_359 -> V_2 . V_20 == V_27 ) {
if ( V_359 -> V_2 . type == V_361 )
return 0x100 ;
return 0x1000 ;
}
if ( F_176 ( V_359 ) )
return 0x16 << V_359 -> V_2 . V_14 ;
return 8 << V_359 -> V_2 . V_14 ;
}
static int F_177 ( struct V_4 * V_5 )
{
unsigned int V_362 = F_175 ( V_5 ) ;
struct V_1 * V_2 = & V_5 -> V_2 ;
int V_219 = 0 ;
switch ( V_2 -> V_20 ) {
case V_27 :
case V_363 :
case V_23 :
case V_24 :
case V_22 :
if ( ! V_2 -> V_130 )
break;
if ( ! F_178 ( V_2 -> V_130 , V_362 , L_23 ) ) {
V_219 = - V_364 ;
break;
}
if ( V_2 -> V_108 & V_365 ) {
V_2 -> V_13 = F_179 ( V_2 -> V_130 , V_362 ) ;
if ( ! V_2 -> V_13 ) {
F_180 ( V_2 -> V_130 , V_362 ) ;
V_219 = - V_249 ;
}
}
break;
case V_21 :
case V_366 :
if ( ! F_181 ( V_2 -> V_17 , V_362 , L_23 ) )
V_219 = - V_364 ;
break;
}
return V_219 ;
}
static void F_182 ( struct V_4 * V_5 )
{
unsigned int V_362 = F_175 ( V_5 ) ;
struct V_1 * V_2 = & V_5 -> V_2 ;
switch ( V_2 -> V_20 ) {
case V_27 :
case V_363 :
case V_23 :
case V_24 :
case V_22 :
if ( ! V_2 -> V_130 )
break;
if ( V_2 -> V_108 & V_365 ) {
F_183 ( V_2 -> V_13 ) ;
V_2 -> V_13 = NULL ;
}
F_180 ( V_2 -> V_130 , V_362 ) ;
break;
case V_21 :
case V_366 :
F_184 ( V_2 -> V_17 , V_362 ) ;
break;
}
}
static int F_185 ( struct V_4 * V_5 )
{
unsigned long V_367 = V_368 << V_5 -> V_2 . V_14 ;
unsigned int V_362 = 8 << V_5 -> V_2 . V_14 ;
struct V_1 * V_2 = & V_5 -> V_2 ;
int V_219 = - V_369 ;
switch ( V_2 -> V_20 ) {
case V_21 :
case V_366 :
V_367 += V_2 -> V_17 ;
if ( F_181 ( V_367 , V_362 , L_28 ) )
V_219 = 0 ;
else
V_219 = - V_364 ;
break;
}
return V_219 ;
}
static void F_186 ( struct V_4 * V_5 )
{
unsigned long V_10 = V_368 << V_5 -> V_2 . V_14 ;
unsigned int V_362 = 8 << V_5 -> V_2 . V_14 ;
struct V_1 * V_2 = & V_5 -> V_2 ;
switch ( V_2 -> V_20 ) {
case V_21 :
case V_366 :
F_184 ( V_2 -> V_17 + V_10 , V_362 ) ;
break;
}
}
static void F_187 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_32 ( V_2 ) ;
F_182 ( V_5 ) ;
}
static int F_188 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_32 ( V_2 ) ;
int V_219 ;
if ( V_2 -> type == V_286 )
return - V_287 ;
V_219 = F_177 ( V_5 ) ;
return V_219 ;
}
static int F_189 ( struct V_4 * V_5 )
{
const struct V_370 * V_371 = & V_139 [ V_5 -> V_2 . type ] ;
unsigned char V_372 ;
V_372 = V_371 -> V_373 [ F_190 ( V_5 -> V_43 ) ] ;
return V_372 ? V_372 : - V_374 ;
}
static int F_191 ( struct V_4 * V_5 , unsigned char V_372 )
{
const struct V_370 * V_371 = & V_139 [ V_5 -> V_2 . type ] ;
int V_226 ;
if ( ! V_371 -> V_373 [ F_190 ( V_375 ) ] )
return - V_374 ;
for ( V_226 = 1 ; V_226 < V_376 ; V_226 ++ ) {
if ( V_372 < V_371 -> V_373 [ V_226 ] )
return ( -- V_226 ) << V_377 ;
}
return V_378 ;
}
static int F_192 ( struct V_379 * V_2 )
{
struct V_380 * V_191 = F_85 ( V_2 , struct V_380 , V_2 ) ;
struct V_1 * V_381 = V_191 -> V_1 ;
struct V_4 * V_5 =
F_85 ( V_381 , struct V_4 , V_2 ) ;
if ( ! ( V_5 -> V_37 & V_38 ) || V_381 -> V_138 <= 1 )
return - V_369 ;
return F_189 ( V_5 ) ;
}
static int F_193 ( struct V_379 * V_2 )
{
int V_373 ;
F_119 ( & V_2 -> V_382 ) ;
V_373 = F_192 ( V_2 ) ;
F_123 ( & V_2 -> V_382 ) ;
return V_373 ;
}
static T_3 F_194 ( struct V_383 * V_45 ,
struct V_384 * V_385 , char * V_196 )
{
struct V_379 * V_2 = F_195 ( V_45 ) ;
int V_373 ;
V_373 = F_193 ( V_2 ) ;
if ( V_373 < 0 )
return V_373 ;
return snprintf ( V_196 , V_386 , L_29 , V_373 ) ;
}
static int F_196 ( struct V_379 * V_2 , unsigned char V_372 )
{
struct V_380 * V_191 = F_85 ( V_2 , struct V_380 , V_2 ) ;
struct V_1 * V_381 = V_191 -> V_1 ;
struct V_4 * V_5 =
F_85 ( V_381 , struct V_4 , V_2 ) ;
int V_387 ;
if ( ! ( V_5 -> V_37 & V_38 ) || V_381 -> V_138 <= 1 ||
V_5 -> V_328 )
return - V_369 ;
V_387 = F_191 ( V_5 , V_372 ) ;
if ( V_387 < 0 )
return V_387 ;
F_37 ( V_5 ) ;
V_5 -> V_43 &= ~ V_338 ;
V_5 -> V_43 |= ( unsigned char ) V_387 ;
F_5 ( V_5 , V_39 , V_5 -> V_43 ) ;
return 0 ;
}
static int F_197 ( struct V_379 * V_2 , unsigned char V_372 )
{
int V_219 ;
F_119 ( & V_2 -> V_382 ) ;
V_219 = F_196 ( V_2 , V_372 ) ;
F_123 ( & V_2 -> V_382 ) ;
return V_219 ;
}
static T_3 F_198 ( struct V_383 * V_45 ,
struct V_384 * V_385 , const char * V_196 , T_4 V_76 )
{
struct V_379 * V_2 = F_195 ( V_45 ) ;
unsigned char V_372 ;
int V_219 ;
if ( ! V_76 )
return - V_369 ;
V_219 = F_199 ( V_196 , 10 , & V_372 ) ;
if ( V_219 < 0 )
return V_219 ;
V_219 = F_197 ( V_2 , V_372 ) ;
if ( V_219 < 0 )
return V_219 ;
return V_76 ;
}
static void F_200 ( struct V_4 * V_5 )
{
const struct V_370 * V_371 = & V_139 [ V_5 -> V_2 . type ] ;
if ( V_371 -> V_373 [ 0 ] )
V_5 -> V_2 . V_388 = & V_389 ;
}
static void F_201 ( struct V_1 * V_2 , int V_108 )
{
struct V_4 * V_5 = F_32 ( V_2 ) ;
int V_219 ;
if ( V_2 -> type == V_286 )
return;
V_219 = F_177 ( V_5 ) ;
if ( V_219 < 0 )
return;
if ( V_2 -> V_20 != V_5 -> V_28 )
F_31 ( V_2 ) ;
if ( V_108 & V_390 )
F_64 ( V_5 ) ;
if ( V_2 -> type == V_107 && V_2 -> V_20 == V_27 )
V_5 -> V_96 |= V_170 ;
if ( V_2 -> type == V_391 )
V_5 -> V_96 |= V_170 ;
if ( V_2 -> type != V_134 && V_108 & V_392 )
F_70 ( V_5 ) ;
if ( V_2 -> type == V_134 )
F_182 ( V_5 ) ;
if ( ( V_2 -> type == V_51 ) ||
( V_2 -> type == V_52 ) )
V_2 -> V_29 = F_107 ;
F_200 ( V_5 ) ;
V_5 -> V_43 = V_139 [ V_5 -> V_2 . type ] . V_43 ;
}
static int
F_202 ( struct V_1 * V_2 , struct V_393 * V_394 )
{
if ( V_394 -> V_149 >= V_395 || V_394 -> V_149 < 0 ||
V_394 -> V_396 < 9600 || V_394 -> type < V_134 ||
V_394 -> type >= F_7 ( V_139 ) || V_394 -> type == V_397 ||
V_394 -> type == V_398 )
return - V_369 ;
return 0 ;
}
static const char *
F_203 ( struct V_1 * V_2 )
{
int type = V_2 -> type ;
if ( type >= F_7 ( V_139 ) )
type = 0 ;
return V_139 [ type ] . V_144 ;
}
struct V_4 * F_204 ( int line )
{
return & V_399 [ line ] ;
}
void F_205 (
void (* F_206)( int V_2 , struct V_1 * V_5 , unsigned short * V_37 ) )
{
V_400 = F_206 ;
}
static void F_207 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = & V_5 -> V_2 ;
F_124 ( & V_2 -> V_69 ) ;
V_2 -> V_299 = & V_401 ;
V_5 -> V_28 = 0xFF ;
}
static void F_208 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = & V_5 -> V_2 ;
if ( V_5 -> V_2 . V_108 & V_402 ) {
unsigned int type = V_5 -> V_2 . type ;
if ( ! V_5 -> V_2 . V_138 )
V_5 -> V_2 . V_138 = V_139 [ type ] . V_140 ;
if ( ! V_5 -> V_141 )
V_5 -> V_141 = V_139 [ type ] . V_141 ;
if ( ! V_5 -> V_37 )
V_5 -> V_37 = V_139 [ type ] . V_108 ;
}
F_31 ( V_2 ) ;
if ( V_5 -> V_158 ) {
if ( ! V_5 -> V_158 -> V_159 )
V_5 -> V_158 -> V_159 = V_403 ;
if ( ! V_5 -> V_158 -> V_217 )
V_5 -> V_158 -> V_217 = V_404 ;
}
}
static void F_209 ( struct V_1 * V_2 , int V_108 )
{
struct V_4 * V_5 = F_32 ( V_2 ) ;
V_5 -> V_136 &= ~ V_137 ;
if ( V_2 -> type == V_68 ) {
if ( F_185 ( V_5 ) == 0 )
V_5 -> V_136 |= V_137 ;
} else if ( V_108 & V_390 ) {
int V_226 ;
for ( V_226 = 0 ; V_226 < V_405 ; V_226 ++ ) {
if ( V_406 [ V_226 ] == V_5 -> V_2 . V_17 ) {
if ( F_185 ( V_5 ) == 0 )
V_5 -> V_136 |= V_137 ;
break;
}
}
}
V_407 -> V_408 ( V_2 , V_108 ) ;
if ( V_2 -> type != V_68 && V_5 -> V_136 & V_137 )
F_186 ( V_5 ) ;
}
static int F_210 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_32 ( V_2 ) ;
int V_219 ;
V_219 = V_407 -> V_409 ( V_2 ) ;
if ( V_219 == 0 && V_2 -> type == V_68 ) {
V_219 = F_185 ( V_5 ) ;
if ( V_219 < 0 )
V_407 -> V_410 ( V_2 ) ;
}
return V_219 ;
}
static void F_211 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_32 ( V_2 ) ;
if ( V_2 -> type == V_68 )
F_186 ( V_5 ) ;
V_407 -> V_410 ( V_2 ) ;
}
static void F_212 ( struct V_411 * V_299 )
{
V_299 -> V_408 = F_209 ;
V_299 -> V_409 = F_210 ;
V_299 -> V_410 = F_211 ;
}
static void T_5 F_213 ( void )
{
struct V_4 * V_5 ;
static int V_412 = 1 ;
int V_226 , V_413 = 0 ;
if ( ! V_412 )
return;
V_412 = 0 ;
if ( V_414 > V_415 )
V_414 = V_415 ;
for ( V_226 = 0 ; V_226 < V_414 ; V_226 ++ ) {
struct V_4 * V_5 = & V_399 [ V_226 ] ;
struct V_1 * V_2 = & V_5 -> V_2 ;
V_2 -> line = V_226 ;
F_207 ( V_5 ) ;
if ( ! V_407 )
V_407 = V_2 -> V_299 ;
V_2 -> V_299 = & V_416 ;
F_214 ( & V_5 -> V_252 ) ;
V_5 -> V_252 . V_259 = F_131 ;
V_5 -> V_299 = & V_417 ;
V_5 -> V_274 = ~ V_418 ;
V_5 -> V_275 = V_418 ;
}
V_416 = * V_407 ;
F_212 ( & V_416 ) ;
if ( V_419 )
V_413 = V_244 ;
for ( V_226 = 0 , V_5 = V_399 ;
V_226 < F_7 ( V_420 ) && V_226 < V_414 ;
V_226 ++ , V_5 ++ ) {
struct V_1 * V_2 = & V_5 -> V_2 ;
V_2 -> V_17 = V_420 [ V_226 ] . V_2 ;
V_2 -> V_149 = F_215 ( V_420 [ V_226 ] . V_149 ) ;
V_2 -> V_250 = V_420 [ V_226 ] . V_250 ;
V_2 -> V_66 = V_420 [ V_226 ] . V_396 * 16 ;
V_2 -> V_108 = V_420 [ V_226 ] . V_108 ;
V_2 -> V_16 = V_420 [ V_226 ] . V_16 ;
V_2 -> V_13 = V_420 [ V_226 ] . V_421 ;
V_2 -> V_20 = V_420 [ V_226 ] . V_422 ;
V_2 -> V_14 = V_420 [ V_226 ] . V_423 ;
F_208 ( V_5 ) ;
V_2 -> V_250 |= V_413 ;
if ( V_400 != NULL )
V_400 ( V_226 , & V_5 -> V_2 , & V_5 -> V_37 ) ;
}
}
static void T_5
F_216 ( struct V_424 * V_425 , struct V_383 * V_45 )
{
int V_226 ;
for ( V_226 = 0 ; V_226 < V_414 ; V_226 ++ ) {
struct V_4 * V_5 = & V_399 [ V_226 ] ;
if ( V_5 -> V_2 . V_45 )
continue;
V_5 -> V_2 . V_45 = V_45 ;
if ( V_426 )
V_5 -> V_2 . V_108 |= V_302 ;
F_217 ( V_425 , & V_5 -> V_2 ) ;
}
}
static void F_218 ( struct V_1 * V_2 , int V_172 )
{
struct V_4 * V_5 = F_32 ( V_2 ) ;
F_144 ( V_5 , V_164 ) ;
F_79 ( V_2 , V_80 , V_172 ) ;
}
static void F_219 ( struct V_4 * V_5 , const char * V_427 ,
unsigned int V_76 )
{
struct V_1 * V_2 = & V_5 -> V_2 ;
unsigned long V_108 ;
unsigned int V_155 ;
int V_428 = 1 ;
F_145 () ;
F_39 ( V_5 ) ;
if ( V_2 -> V_429 )
V_428 = 0 ;
else if ( V_430 )
V_428 = F_220 ( & V_2 -> V_69 , V_108 ) ;
else
F_65 ( & V_2 -> V_69 , V_108 ) ;
V_155 = F_99 ( V_2 , V_60 ) ;
if ( V_5 -> V_37 & V_122 )
F_79 ( V_2 , V_60 , V_120 ) ;
else
F_79 ( V_2 , V_60 , 0 ) ;
if ( V_5 -> V_431 && ( V_5 -> V_431 != F_99 ( V_2 , V_32 ) ) ) {
struct V_335 V_336 ;
unsigned int V_309 , V_116 , V_310 = 0 ;
V_336 . V_313 = V_2 -> V_432 -> V_433 ;
if ( V_2 -> V_191 -> V_2 . V_434 && V_336 . V_313 == 0 )
V_336 . V_313 = V_2 -> V_191 -> V_2 . V_434 -> V_336 . V_313 ;
V_309 = F_166 ( V_2 , & V_336 , NULL ,
V_2 -> V_66 / 16 / 0xffff ,
V_2 -> V_66 / 16 ) ;
V_116 = F_159 ( V_5 , V_309 , & V_310 ) ;
F_163 ( V_2 , V_309 , V_116 , V_310 ) ;
F_79 ( V_2 , V_31 , V_5 -> V_49 ) ;
F_79 ( V_2 , V_77 , V_153 | V_154 ) ;
V_5 -> V_431 = 0 ;
}
F_221 ( V_2 , V_427 , V_76 , F_218 ) ;
F_144 ( V_5 , V_200 ) ;
F_79 ( V_2 , V_60 , V_155 ) ;
if ( V_5 -> V_203 )
F_102 ( V_5 ) ;
if ( V_428 )
F_67 ( & V_2 -> V_69 , V_108 ) ;
F_41 ( V_5 ) ;
}
static void F_222 ( struct V_435 * V_436 , const char * V_427 ,
unsigned int V_76 )
{
struct V_4 * V_5 = & V_399 [ V_436 -> V_437 ] ;
F_219 ( V_5 , V_427 , V_76 ) ;
}
static unsigned int F_223 ( struct V_1 * V_2 )
{
unsigned char V_49 , V_438 , V_439 ;
unsigned int V_116 ;
V_49 = F_99 ( V_2 , V_31 ) ;
F_79 ( V_2 , V_31 , V_49 | V_334 ) ;
V_438 = F_99 ( V_2 , V_6 ) ;
V_439 = F_99 ( V_2 , V_7 ) ;
F_79 ( V_2 , V_31 , V_49 ) ;
V_116 = ( V_439 << 8 ) | V_438 ;
return ( V_2 -> V_66 / 16 ) / V_116 ;
}
static int F_224 ( struct V_1 * V_2 , char * V_440 , bool V_136 )
{
int V_309 = 9600 ;
int V_279 = 8 ;
int V_184 = 'n' ;
int V_441 = 'n' ;
if ( ! V_2 -> V_17 && ! V_2 -> V_13 )
return - V_287 ;
if ( V_440 )
F_225 ( V_440 , & V_309 , & V_184 , & V_279 , & V_441 ) ;
else if ( V_136 )
V_309 = F_223 ( V_2 ) ;
return F_226 ( V_2 , V_2 -> V_432 , V_309 , V_184 , V_279 , V_441 ) ;
}
static int F_227 ( struct V_435 * V_436 , char * V_440 )
{
struct V_1 * V_2 ;
if ( V_436 -> V_437 >= V_414 )
V_436 -> V_437 = 0 ;
V_2 = & V_399 [ V_436 -> V_437 ] . V_2 ;
V_2 -> V_432 = V_436 ;
return F_224 ( V_2 , V_440 , false ) ;
}
static int F_228 ( struct V_435 * V_436 , char * V_144 , int V_442 ,
char * V_440 )
{
char V_443 [] = L_30 ;
unsigned char V_20 ;
unsigned long V_444 ;
int V_226 ;
if ( strncmp ( V_144 , V_443 , 4 ) != 0 )
return - V_287 ;
if ( F_229 ( V_440 , & V_20 , & V_444 , & V_440 ) )
return - V_287 ;
for ( V_226 = 0 ; V_226 < V_414 ; V_226 ++ ) {
struct V_1 * V_2 = & V_399 [ V_226 ] . V_2 ;
if ( V_2 -> V_20 != V_20 )
continue;
if ( ( V_20 == V_22 || V_20 == V_23 ) &&
( V_2 -> V_130 != V_444 ) )
continue;
if ( V_20 == V_366 && V_2 -> V_17 != V_444 )
continue;
V_436 -> V_437 = V_226 ;
V_2 -> V_432 = V_436 ;
return F_224 ( V_2 , V_440 , true ) ;
}
return - V_287 ;
}
static int T_5 F_230 ( void )
{
F_213 () ;
F_231 ( & V_445 ) ;
return 0 ;
}
int T_5 F_232 ( struct V_1 * V_2 )
{
struct V_1 * V_9 ;
if ( V_2 -> line >= F_7 ( V_399 ) )
return - V_287 ;
F_213 () ;
V_9 = & V_399 [ V_2 -> line ] . V_2 ;
V_9 -> V_17 = V_2 -> V_17 ;
V_9 -> V_13 = V_2 -> V_13 ;
V_9 -> V_149 = V_2 -> V_149 ;
V_9 -> V_250 = V_2 -> V_250 ;
V_9 -> V_66 = V_2 -> V_66 ;
V_9 -> V_138 = V_2 -> V_138 ;
V_9 -> V_14 = V_2 -> V_14 ;
V_9 -> V_20 = V_2 -> V_20 ;
V_9 -> V_108 = V_2 -> V_108 ;
V_9 -> V_130 = V_2 -> V_130 ;
V_9 -> V_360 = V_2 -> V_360 ;
V_9 -> V_446 = V_2 -> V_446 ;
V_9 -> type = V_2 -> type ;
V_9 -> line = V_2 -> line ;
F_208 ( F_32 ( V_9 ) ) ;
if ( V_2 -> F_3 )
V_9 -> F_3 = V_2 -> F_3 ;
if ( V_2 -> F_5 )
V_9 -> F_5 = V_2 -> F_5 ;
if ( V_2 -> V_29 )
V_9 -> V_29 = V_2 -> V_29 ;
return 0 ;
}
void F_233 ( int line )
{
struct V_4 * V_5 = & V_399 [ line ] ;
struct V_1 * V_2 = & V_5 -> V_2 ;
if ( ! V_447 && F_234 ( V_2 ) &&
V_2 -> type != V_104 ) {
unsigned char V_431 = 0xa5 ;
F_5 ( V_5 , V_32 , V_431 ) ;
if ( F_3 ( V_5 , V_32 ) == V_431 )
V_5 -> V_431 = V_431 ;
}
F_235 ( & V_448 , V_2 ) ;
}
void F_236 ( int line )
{
struct V_4 * V_5 = & V_399 [ line ] ;
struct V_1 * V_2 = & V_5 -> V_2 ;
V_5 -> V_431 = 0 ;
if ( V_5 -> V_37 & V_118 ) {
F_79 ( V_2 , V_31 , 0xE0 ) ;
F_63 ( V_5 ) ;
F_79 ( V_2 , V_31 , 0 ) ;
V_2 -> V_66 = 921600 * 16 ;
}
F_237 ( & V_448 , V_2 ) ;
}
static int F_238 ( struct V_449 * V_45 )
{
struct V_450 * V_9 = F_239 ( & V_45 -> V_45 ) ;
struct V_4 V_451 ;
int V_219 , V_226 , V_413 = 0 ;
memset ( & V_451 , 0 , sizeof( V_451 ) ) ;
if ( V_419 )
V_413 = V_244 ;
for ( V_226 = 0 ; V_9 && V_9 -> V_108 != 0 ; V_9 ++ , V_226 ++ ) {
V_451 . V_2 . V_17 = V_9 -> V_17 ;
V_451 . V_2 . V_13 = V_9 -> V_13 ;
V_451 . V_2 . V_149 = V_9 -> V_149 ;
V_451 . V_2 . V_250 = V_9 -> V_250 ;
V_451 . V_2 . V_66 = V_9 -> V_66 ;
V_451 . V_2 . V_14 = V_9 -> V_14 ;
V_451 . V_2 . V_20 = V_9 -> V_20 ;
V_451 . V_2 . V_108 = V_9 -> V_108 ;
V_451 . V_2 . V_130 = V_9 -> V_130 ;
V_451 . V_2 . V_16 = V_9 -> V_16 ;
V_451 . V_2 . V_446 = V_9 -> V_446 ;
V_451 . V_2 . type = V_9 -> type ;
V_451 . V_2 . F_3 = V_9 -> F_3 ;
V_451 . V_2 . F_5 = V_9 -> F_5 ;
V_451 . V_2 . V_29 = V_9 -> V_29 ;
V_451 . V_2 . V_452 = V_9 -> V_452 ;
V_451 . V_2 . V_353 = V_9 -> V_353 ;
V_451 . V_2 . V_358 = V_9 -> V_358 ;
V_451 . V_2 . V_45 = & V_45 -> V_45 ;
V_451 . V_2 . V_250 |= V_413 ;
V_219 = F_240 ( & V_451 ) ;
if ( V_219 < 0 ) {
F_241 ( & V_45 -> V_45 , L_31
L_32 , V_226 ,
V_9 -> V_17 , ( unsigned long long ) V_9 -> V_130 ,
V_9 -> V_149 , V_219 ) ;
}
}
return 0 ;
}
static int F_242 ( struct V_449 * V_45 )
{
int V_226 ;
for ( V_226 = 0 ; V_226 < V_414 ; V_226 ++ ) {
struct V_4 * V_5 = & V_399 [ V_226 ] ;
if ( V_5 -> V_2 . V_45 == & V_45 -> V_45 )
F_243 ( V_226 ) ;
}
return 0 ;
}
static int F_244 ( struct V_449 * V_45 , T_6 V_191 )
{
int V_226 ;
for ( V_226 = 0 ; V_226 < V_415 ; V_226 ++ ) {
struct V_4 * V_5 = & V_399 [ V_226 ] ;
if ( V_5 -> V_2 . type != V_134 && V_5 -> V_2 . V_45 == & V_45 -> V_45 )
F_235 ( & V_448 , & V_5 -> V_2 ) ;
}
return 0 ;
}
static int F_245 ( struct V_449 * V_45 )
{
int V_226 ;
for ( V_226 = 0 ; V_226 < V_415 ; V_226 ++ ) {
struct V_4 * V_5 = & V_399 [ V_226 ] ;
if ( V_5 -> V_2 . type != V_134 && V_5 -> V_2 . V_45 == & V_45 -> V_45 )
F_236 ( V_226 ) ;
}
return 0 ;
}
static struct V_4 * F_246 ( struct V_1 * V_2 )
{
int V_226 ;
for ( V_226 = 0 ; V_226 < V_414 ; V_226 ++ )
if ( F_247 ( & V_399 [ V_226 ] . V_2 , V_2 ) )
return & V_399 [ V_226 ] ;
V_226 = V_2 -> line ;
if ( V_226 < V_414 && V_399 [ V_226 ] . V_2 . type == V_134 &&
V_399 [ V_226 ] . V_2 . V_17 == 0 )
return & V_399 [ V_226 ] ;
for ( V_226 = 0 ; V_226 < V_414 ; V_226 ++ )
if ( V_399 [ V_226 ] . V_2 . type == V_134 &&
V_399 [ V_226 ] . V_2 . V_17 == 0 )
return & V_399 [ V_226 ] ;
for ( V_226 = 0 ; V_226 < V_414 ; V_226 ++ )
if ( V_399 [ V_226 ] . V_2 . type == V_134 )
return & V_399 [ V_226 ] ;
return NULL ;
}
int F_240 ( struct V_4 * V_5 )
{
struct V_4 * V_451 ;
int V_219 = - V_453 ;
if ( V_5 -> V_2 . V_66 == 0 )
return - V_369 ;
F_119 ( & V_454 ) ;
V_451 = F_246 ( & V_5 -> V_2 ) ;
if ( V_451 && V_451 -> V_2 . type != V_286 ) {
if ( V_451 -> V_2 . V_45 )
F_248 ( & V_448 , & V_451 -> V_2 ) ;
V_451 -> V_2 . V_17 = V_5 -> V_2 . V_17 ;
V_451 -> V_2 . V_13 = V_5 -> V_2 . V_13 ;
V_451 -> V_2 . V_149 = V_5 -> V_2 . V_149 ;
V_451 -> V_2 . V_250 = V_5 -> V_2 . V_250 ;
V_451 -> V_2 . V_66 = V_5 -> V_2 . V_66 ;
V_451 -> V_2 . V_138 = V_5 -> V_2 . V_138 ;
V_451 -> V_2 . V_14 = V_5 -> V_2 . V_14 ;
V_451 -> V_2 . V_20 = V_5 -> V_2 . V_20 ;
V_451 -> V_2 . V_108 = V_5 -> V_2 . V_108 | V_455 ;
V_451 -> V_96 = V_5 -> V_96 ;
V_451 -> V_2 . V_130 = V_5 -> V_2 . V_130 ;
V_451 -> V_2 . V_360 = V_5 -> V_2 . V_360 ;
V_451 -> V_2 . V_446 = V_5 -> V_2 . V_446 ;
V_451 -> V_2 . V_138 = V_5 -> V_2 . V_138 ;
V_451 -> V_141 = V_5 -> V_141 ;
V_451 -> V_37 = V_5 -> V_37 ;
V_451 -> V_2 . V_165 = V_5 -> V_2 . V_165 ;
V_451 -> V_2 . V_166 = V_5 -> V_2 . V_166 ;
V_451 -> V_2 . V_456 = V_5 -> V_2 . V_456 ;
V_451 -> V_2 . V_457 = V_5 -> V_2 . V_457 ;
V_451 -> V_158 = V_5 -> V_158 ;
if ( V_451 -> V_2 . V_138 && ! V_451 -> V_141 )
V_451 -> V_141 = V_451 -> V_2 . V_138 ;
if ( V_5 -> V_2 . V_45 )
V_451 -> V_2 . V_45 = V_5 -> V_2 . V_45 ;
if ( V_426 )
V_451 -> V_2 . V_108 |= V_302 ;
if ( V_5 -> V_2 . V_108 & V_402 )
V_451 -> V_2 . type = V_5 -> V_2 . type ;
F_208 ( V_451 ) ;
if ( V_5 -> V_2 . F_3 )
V_451 -> V_2 . F_3 = V_5 -> V_2 . F_3 ;
if ( V_5 -> V_2 . F_5 )
V_451 -> V_2 . F_5 = V_5 -> V_2 . F_5 ;
if ( V_5 -> V_2 . V_29 )
V_451 -> V_2 . V_29 = V_5 -> V_2 . V_29 ;
if ( V_5 -> V_2 . V_353 )
V_451 -> V_2 . V_353 = V_5 -> V_2 . V_353 ;
if ( V_5 -> V_2 . V_276 )
V_451 -> V_2 . V_276 = V_5 -> V_2 . V_276 ;
if ( V_5 -> V_2 . V_306 )
V_451 -> V_2 . V_306 = V_5 -> V_2 . V_306 ;
if ( V_5 -> V_2 . V_308 )
V_451 -> V_2 . V_308 = V_5 -> V_2 . V_308 ;
if ( V_5 -> V_2 . V_358 )
V_451 -> V_2 . V_358 = V_5 -> V_2 . V_358 ;
if ( V_5 -> V_2 . V_452 )
V_451 -> V_2 . V_452 = V_5 -> V_2 . V_452 ;
if ( V_5 -> V_18 )
V_451 -> V_18 = V_5 -> V_18 ;
if ( V_5 -> V_19 )
V_451 -> V_19 = V_5 -> V_19 ;
if ( V_400 != NULL )
V_400 ( 0 , & V_451 -> V_2 ,
& V_451 -> V_37 ) ;
V_219 = F_217 ( & V_448 , & V_451 -> V_2 ) ;
if ( V_219 == 0 )
V_219 = V_451 -> V_2 . line ;
}
F_123 ( & V_454 ) ;
return V_219 ;
}
void F_243 ( int line )
{
struct V_4 * V_451 = & V_399 [ line ] ;
F_119 ( & V_454 ) ;
F_248 ( & V_448 , & V_451 -> V_2 ) ;
if ( V_458 ) {
V_451 -> V_2 . V_108 &= ~ V_455 ;
if ( V_426 )
V_451 -> V_2 . V_108 |= V_302 ;
V_451 -> V_2 . type = V_134 ;
V_451 -> V_2 . V_45 = & V_458 -> V_45 ;
V_451 -> V_37 = 0 ;
F_217 ( & V_448 , & V_451 -> V_2 ) ;
} else {
V_451 -> V_2 . V_45 = NULL ;
}
F_123 ( & V_454 ) ;
}
static int T_5 F_249 ( void )
{
int V_219 ;
F_213 () ;
F_69 ( V_289 L_33
L_34 , V_414 ,
V_419 ? L_35 : L_36 ) ;
#ifdef F_250
V_219 = F_251 ( & V_448 , V_415 ) ;
#else
V_448 . V_459 = V_415 ;
V_219 = F_252 ( & V_448 ) ;
#endif
if ( V_219 )
goto V_54;
V_219 = F_253 () ;
if ( V_219 )
goto V_460;
V_458 = F_254 ( L_37 ,
V_461 ) ;
if ( ! V_458 ) {
V_219 = - V_249 ;
goto V_462;
}
V_219 = F_255 ( V_458 ) ;
if ( V_219 )
goto V_463;
F_216 ( & V_448 , & V_458 -> V_45 ) ;
V_219 = F_256 ( & V_464 ) ;
if ( V_219 == 0 )
goto V_54;
F_257 ( V_458 ) ;
V_463:
F_258 ( V_458 ) ;
V_462:
F_259 () ;
V_460:
#ifdef F_250
F_260 ( & V_448 , V_415 ) ;
#else
F_261 ( & V_448 ) ;
#endif
V_54:
return V_219 ;
}
static void T_7 F_262 ( void )
{
struct V_449 * V_465 = V_458 ;
V_458 = NULL ;
F_263 ( & V_464 ) ;
F_264 ( V_465 ) ;
F_259 () ;
#ifdef F_250
F_260 ( & V_448 , V_415 ) ;
#else
F_261 ( & V_448 ) ;
#endif
}
static void T_8 F_265 ( void )
{
#undef V_466
#define V_466 "8250_core."
F_266 ( V_419 , & V_467 , & V_419 , 0644 ) ;
F_266 ( V_414 , & V_467 , & V_414 , 0644 ) ;
F_266 ( V_426 , & V_467 , & V_426 , 0644 ) ;
#ifdef F_68
F_267 ( V_466 , V_406 ,
& V_468 , . V_469 = & V_470 ,
0444 , - 1 , 0 ) ;
#endif
}
