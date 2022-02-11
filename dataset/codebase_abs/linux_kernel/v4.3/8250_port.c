static int F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_2 , V_3 ) | F_2 ( V_2 , V_4 ) << 8 ;
}
static void F_3 ( struct V_1 * V_2 , int V_5 )
{
F_4 ( V_2 , V_3 , V_5 & 0xff ) ;
F_4 ( V_2 , V_4 , V_5 >> 8 & 0xff ) ;
}
static unsigned int F_5 ( struct V_6 * V_7 , int V_8 )
{
if ( V_8 >= F_6 ( V_9 ) )
return V_10 ;
V_8 = V_9 [ V_8 ] ;
if ( V_8 < 0 )
return V_10 ;
return F_7 ( V_7 -> V_11 + ( V_8 << V_7 -> V_12 ) ) ;
}
static void F_8 ( struct V_6 * V_7 , int V_8 , int V_5 )
{
if ( V_8 >= F_6 ( V_13 ) )
return;
V_8 = V_13 [ V_8 ] ;
if ( V_8 < 0 )
return;
F_9 ( V_5 , V_7 -> V_11 + ( V_8 << V_7 -> V_12 ) ) ;
}
static int F_10 ( struct V_1 * V_2 )
{
return F_7 ( V_2 -> V_14 . V_11 + 0x28 ) ;
}
static void F_11 ( struct V_1 * V_2 , int V_5 )
{
F_9 ( V_5 , V_2 -> V_14 . V_11 + 0x28 ) ;
}
static unsigned int F_12 ( struct V_6 * V_7 , int V_8 )
{
V_8 = V_8 << V_7 -> V_12 ;
F_13 ( V_7 -> V_15 - 1 + V_8 , V_7 -> V_16 ) ;
return F_14 ( V_7 -> V_16 + 1 ) ;
}
static void F_15 ( struct V_6 * V_7 , int V_8 , int V_5 )
{
V_8 = V_8 << V_7 -> V_12 ;
F_13 ( V_7 -> V_15 - 1 + V_8 , V_7 -> V_16 ) ;
F_13 ( V_5 , V_7 -> V_16 + 1 ) ;
}
static unsigned int F_16 ( struct V_6 * V_7 , int V_8 )
{
V_8 = V_8 << V_7 -> V_12 ;
return F_17 ( V_7 -> V_11 + V_8 ) ;
}
static void F_18 ( struct V_6 * V_7 , int V_8 , int V_5 )
{
V_8 = V_8 << V_7 -> V_12 ;
F_19 ( V_5 , V_7 -> V_11 + V_8 ) ;
}
static void F_20 ( struct V_6 * V_7 , int V_8 , int V_5 )
{
V_8 = V_8 << V_7 -> V_12 ;
F_21 ( V_5 , V_7 -> V_11 + V_8 ) ;
}
static unsigned int F_22 ( struct V_6 * V_7 , int V_8 )
{
V_8 = V_8 << V_7 -> V_12 ;
return F_23 ( V_7 -> V_11 + V_8 ) ;
}
static void F_24 ( struct V_6 * V_7 , int V_8 , int V_5 )
{
V_8 = V_8 << V_7 -> V_12 ;
F_25 ( V_5 , V_7 -> V_11 + V_8 ) ;
}
static unsigned int F_26 ( struct V_6 * V_7 , int V_8 )
{
V_8 = V_8 << V_7 -> V_12 ;
return F_27 ( V_7 -> V_11 + V_8 ) ;
}
static unsigned int F_28 ( struct V_6 * V_7 , int V_8 )
{
V_8 = V_8 << V_7 -> V_12 ;
return F_14 ( V_7 -> V_16 + V_8 ) ;
}
static void F_29 ( struct V_6 * V_7 , int V_8 , int V_5 )
{
V_8 = V_8 << V_7 -> V_12 ;
F_13 ( V_5 , V_7 -> V_16 + V_8 ) ;
}
static void F_30 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_31 ( V_7 ) ;
V_2 -> V_17 = F_1 ;
V_2 -> V_18 = F_3 ;
switch ( V_7 -> V_19 ) {
case V_20 :
V_7 -> F_2 = F_12 ;
V_7 -> F_4 = F_15 ;
break;
case V_21 :
V_7 -> F_2 = F_16 ;
V_7 -> F_4 = F_18 ;
break;
case V_22 :
V_7 -> F_2 = F_22 ;
V_7 -> F_4 = F_20 ;
break;
case V_23 :
V_7 -> F_2 = F_26 ;
V_7 -> F_4 = F_24 ;
break;
#if F_32 ( V_24 ) || F_32 ( V_25 )
case V_26 :
V_7 -> F_2 = F_5 ;
V_7 -> F_4 = F_8 ;
V_2 -> V_17 = F_10 ;
V_2 -> V_18 = F_11 ;
break;
#endif
default:
V_7 -> F_2 = F_28 ;
V_7 -> F_4 = F_29 ;
break;
}
V_2 -> V_27 = V_7 -> V_19 ;
V_7 -> V_28 = V_29 ;
}
static void
F_33 ( struct V_6 * V_7 , int V_8 , int V_5 )
{
switch ( V_7 -> V_19 ) {
case V_21 :
case V_22 :
case V_23 :
case V_26 :
V_7 -> F_4 ( V_7 , V_8 , V_5 ) ;
V_7 -> F_2 ( V_7 , V_30 ) ;
break;
default:
V_7 -> F_4 ( V_7 , V_8 , V_5 ) ;
}
}
static void F_34 ( struct V_1 * V_2 , int V_8 , int V_5 )
{
F_4 ( V_2 , V_31 , V_8 ) ;
F_4 ( V_2 , V_32 , V_5 ) ;
}
static unsigned int F_35 ( struct V_1 * V_2 , int V_8 )
{
unsigned int V_5 ;
F_34 ( V_2 , V_33 , V_2 -> V_34 | V_35 ) ;
F_4 ( V_2 , V_31 , V_8 ) ;
V_5 = F_2 ( V_2 , V_32 ) ;
F_34 ( V_2 , V_33 , V_2 -> V_34 ) ;
return V_5 ;
}
static void F_36 ( struct V_1 * V_7 )
{
if ( V_7 -> V_36 & V_37 ) {
F_4 ( V_7 , V_38 , V_39 ) ;
F_4 ( V_7 , V_38 , V_39 |
V_40 | V_41 ) ;
F_4 ( V_7 , V_38 , 0 ) ;
}
}
void F_37 ( struct V_1 * V_7 )
{
F_36 ( V_7 ) ;
F_4 ( V_7 , V_38 , V_7 -> V_42 ) ;
}
void F_38 ( struct V_1 * V_7 )
{
if ( ! ( V_7 -> V_36 & V_43 ) )
return;
F_39 ( V_7 -> V_14 . V_44 ) ;
}
void F_40 ( struct V_1 * V_7 )
{
if ( ! ( V_7 -> V_36 & V_43 ) )
return;
F_41 ( V_7 -> V_14 . V_44 ) ;
F_42 ( V_7 -> V_14 . V_44 ) ;
}
static void F_43 ( struct V_1 * V_7 )
{
unsigned char V_45 ;
if ( ! ( V_7 -> V_36 & V_43 ) )
return;
V_45 = F_44 ( & V_7 -> V_46 , 1 ) ;
if ( V_45 )
return;
F_39 ( V_7 -> V_14 . V_44 ) ;
}
static void F_45 ( struct V_1 * V_7 )
{
unsigned char V_45 ;
if ( ! ( V_7 -> V_36 & V_43 ) )
return;
V_45 = F_44 ( & V_7 -> V_46 , 0 ) ;
if ( ! V_45 )
return;
F_41 ( V_7 -> V_14 . V_44 ) ;
F_42 ( V_7 -> V_14 . V_44 ) ;
}
static void F_46 ( struct V_1 * V_7 , int V_47 )
{
unsigned char V_48 = 0 , V_49 = 0 ;
F_38 ( V_7 ) ;
if ( ( V_7 -> V_14 . type == V_50 ) ||
( V_7 -> V_14 . type == V_51 ) ) {
F_4 ( V_7 , V_52 , V_47 ? 0xff : 0 ) ;
goto V_53;
}
if ( V_7 -> V_36 & V_54 ) {
if ( V_7 -> V_36 & V_55 ) {
V_48 = F_2 ( V_7 , V_30 ) ;
V_49 = F_2 ( V_7 , V_56 ) ;
F_4 ( V_7 , V_30 , V_57 ) ;
F_4 ( V_7 , V_56 , V_58 ) ;
F_4 ( V_7 , V_30 , 0 ) ;
}
F_4 ( V_7 , V_59 , V_47 ? V_60 : 0 ) ;
if ( V_7 -> V_36 & V_55 ) {
F_4 ( V_7 , V_30 , V_57 ) ;
F_4 ( V_7 , V_56 , V_49 ) ;
F_4 ( V_7 , V_30 , V_48 ) ;
}
}
V_53:
F_40 ( V_7 ) ;
}
static int F_47 ( struct V_1 * V_2 )
{
unsigned char V_61 ;
int V_62 ;
V_61 = F_2 ( V_2 , V_63 ) ;
V_62 = V_61 & V_64 ;
if ( ! V_62 ) {
F_4 ( V_2 , V_63 , V_61 | V_64 ) ;
V_61 = F_2 ( V_2 , V_63 ) ;
V_62 = V_61 & V_64 ;
}
if ( V_62 )
V_2 -> V_14 . V_65 = V_66 * 16 ;
return V_62 ;
}
static void F_48 ( struct V_1 * V_2 )
{
if ( V_2 -> V_14 . type == V_67 ) {
if ( V_2 -> V_14 . V_65 != V_66 * 16 ) {
F_49 ( & V_2 -> V_14 . V_68 ) ;
F_47 ( V_2 ) ;
F_50 ( & V_2 -> V_14 . V_68 ) ;
}
if ( V_2 -> V_14 . V_65 == V_66 * 16 )
F_4 ( V_2 , V_69 , 0 ) ;
}
}
static void F_51 ( struct V_1 * V_2 )
{
unsigned char V_61 ;
int V_62 ;
if ( V_2 -> V_14 . type == V_67 &&
V_2 -> V_14 . V_65 == V_66 * 16 ) {
F_49 ( & V_2 -> V_14 . V_68 ) ;
V_61 = F_2 ( V_2 , V_63 ) ;
V_62 = ! ( V_61 & V_64 ) ;
if ( ! V_62 ) {
F_4 ( V_2 , V_63 , V_61 & ~ V_64 ) ;
V_61 = F_2 ( V_2 , V_63 ) ;
V_62 = ! ( V_61 & V_64 ) ;
}
if ( V_62 )
V_2 -> V_14 . V_65 = V_70 * 16 ;
F_50 ( & V_2 -> V_14 . V_68 ) ;
}
}
static int F_52 ( struct V_1 * V_2 )
{
unsigned char V_71 , V_72 , V_73 ;
unsigned short V_74 ;
int V_75 ;
V_73 = F_2 ( V_2 , V_30 ) ;
F_4 ( V_2 , V_30 , 0 ) ;
V_71 = F_2 ( V_2 , V_38 ) ;
V_72 = F_2 ( V_2 , V_76 ) ;
F_4 ( V_2 , V_38 , V_39 |
V_40 | V_41 ) ;
F_4 ( V_2 , V_76 , V_77 ) ;
F_4 ( V_2 , V_30 , V_78 ) ;
V_74 = F_53 ( V_2 ) ;
F_54 ( V_2 , 0x0001 ) ;
F_4 ( V_2 , V_30 , 0x03 ) ;
for ( V_75 = 0 ; V_75 < 256 ; V_75 ++ )
F_4 ( V_2 , V_79 , V_75 ) ;
F_55 ( 20 ) ;
for ( V_75 = 0 ; ( F_2 ( V_2 , V_80 ) & V_81 ) &&
( V_75 < 256 ) ; V_75 ++ )
F_2 ( V_2 , V_82 ) ;
F_4 ( V_2 , V_38 , V_71 ) ;
F_4 ( V_2 , V_76 , V_72 ) ;
F_4 ( V_2 , V_30 , V_78 ) ;
F_54 ( V_2 , V_74 ) ;
F_4 ( V_2 , V_30 , V_73 ) ;
return V_75 ;
}
static unsigned int F_56 ( struct V_1 * V_7 )
{
unsigned char V_83 , V_84 , V_73 ;
unsigned int V_85 ;
V_73 = F_2 ( V_7 , V_30 ) ;
F_4 ( V_7 , V_30 , V_78 ) ;
V_83 = F_2 ( V_7 , V_3 ) ;
V_84 = F_2 ( V_7 , V_4 ) ;
F_4 ( V_7 , V_3 , 0 ) ;
F_4 ( V_7 , V_4 , 0 ) ;
V_85 = F_2 ( V_7 , V_3 ) | F_2 ( V_7 , V_4 ) << 8 ;
F_4 ( V_7 , V_3 , V_83 ) ;
F_4 ( V_7 , V_4 , V_84 ) ;
F_4 ( V_7 , V_30 , V_73 ) ;
return V_85 ;
}
static void F_57 ( struct V_1 * V_2 )
{
unsigned int V_86 , V_87 , V_88 , V_89 ;
V_2 -> V_36 |= V_55 | V_54 ;
V_2 -> V_34 = 0 ;
F_4 ( V_2 , V_30 , V_57 ) ;
F_4 ( V_2 , V_56 , V_58 ) ;
F_4 ( V_2 , V_30 , 0x00 ) ;
V_86 = F_35 ( V_2 , V_90 ) ;
V_87 = F_35 ( V_2 , V_91 ) ;
V_88 = F_35 ( V_2 , V_92 ) ;
V_89 = F_35 ( V_2 , V_93 ) ;
F_58 ( L_1 , V_86 , V_87 , V_88 , V_89 ) ;
if ( V_86 == 0x16 && V_87 == 0xC9 &&
( V_88 == 0x50 || V_88 == 0x52 || V_88 == 0x54 ) ) {
V_2 -> V_14 . type = V_94 ;
if ( V_88 == 0x52 && V_89 == 0x01 )
V_2 -> V_95 |= V_96 ;
return;
}
V_86 = F_56 ( V_2 ) ;
F_58 ( L_2 , V_86 ) ;
V_87 = V_86 >> 8 ;
if ( V_87 == 0x10 || V_87 == 0x12 || V_87 == 0x14 ) {
V_2 -> V_14 . type = V_97 ;
return;
}
if ( F_52 ( V_2 ) == 64 )
V_2 -> V_14 . type = V_98 ;
else
V_2 -> V_14 . type = V_99 ;
}
static void F_59 ( struct V_1 * V_2 )
{
unsigned char V_100 , V_101 , V_102 ;
V_2 -> V_14 . type = V_103 ;
V_100 = F_2 ( V_2 , V_31 ) ;
F_4 ( V_2 , V_31 , 0xa5 ) ;
V_101 = F_2 ( V_2 , V_31 ) ;
F_4 ( V_2 , V_31 , 0x5a ) ;
V_102 = F_2 ( V_2 , V_31 ) ;
F_4 ( V_2 , V_31 , V_100 ) ;
if ( V_101 == 0xa5 && V_102 == 0x5a )
V_2 -> V_14 . type = V_104 ;
}
static int F_60 ( struct V_1 * V_2 )
{
if ( F_56 ( V_2 ) == 0x0201 && F_52 ( V_2 ) == 16 )
return 1 ;
return 0 ;
}
static void F_61 ( struct V_1 * V_2 )
{
unsigned char V_101 , V_102 ;
unsigned int V_105 ;
V_2 -> V_14 . type = V_106 ;
V_2 -> V_36 |= V_37 ;
if ( V_2 -> V_14 . V_107 & V_108 ) {
V_101 = F_2 ( V_2 , V_109 ) ;
if ( V_101 == 0x82 || V_101 == 0x84 || V_101 == 0x88 ) {
F_58 ( L_3 ) ;
V_2 -> V_14 . type = V_50 ;
V_2 -> V_36 |= V_110 | V_55 |
V_54 ;
return;
}
}
F_4 ( V_2 , V_30 , V_78 ) ;
if ( F_2 ( V_2 , V_56 ) == 0 ) {
F_4 ( V_2 , V_56 , 0xA8 ) ;
if ( F_2 ( V_2 , V_56 ) != 0 ) {
F_58 ( L_4 ) ;
V_2 -> V_14 . type = V_111 ;
V_2 -> V_36 |= V_55 | V_54 ;
} else {
F_4 ( V_2 , V_30 , 0 ) ;
F_4 ( V_2 , V_38 , V_39 |
V_112 ) ;
V_101 = F_2 ( V_2 , V_113 ) >> 5 ;
F_4 ( V_2 , V_38 , 0 ) ;
F_4 ( V_2 , V_30 , 0 ) ;
if ( V_101 == 7 )
V_2 -> V_14 . type = V_114 ;
else
F_58 ( L_5 ) ;
}
F_4 ( V_2 , V_56 , 0 ) ;
return;
}
F_4 ( V_2 , V_30 , V_57 ) ;
if ( F_2 ( V_2 , V_56 ) == 0 && ! F_60 ( V_2 ) ) {
F_58 ( L_6 ) ;
F_57 ( V_2 ) ;
return;
}
F_4 ( V_2 , V_30 , 0 ) ;
V_101 = F_2 ( V_2 , V_76 ) ;
F_4 ( V_2 , V_30 , 0xE0 ) ;
V_102 = F_2 ( V_2 , 0x02 ) ;
if ( ! ( ( V_102 ^ V_101 ) & V_77 ) ) {
F_4 ( V_2 , V_30 , 0 ) ;
F_4 ( V_2 , V_76 , V_101 ^ V_77 ) ;
F_4 ( V_2 , V_30 , 0xE0 ) ;
V_102 = F_2 ( V_2 , 0x02 ) ;
F_4 ( V_2 , V_30 , 0 ) ;
F_4 ( V_2 , V_76 , V_101 ) ;
if ( ( V_102 ^ V_101 ) & V_77 ) {
unsigned short V_115 ;
F_4 ( V_2 , V_30 , 0xE0 ) ;
V_115 = F_53 ( V_2 ) ;
V_115 <<= 3 ;
if ( F_62 ( V_2 ) )
F_54 ( V_2 , V_115 ) ;
F_4 ( V_2 , V_30 , 0 ) ;
V_2 -> V_14 . V_65 = 921600 * 16 ;
V_2 -> V_14 . type = V_116 ;
V_2 -> V_36 |= V_117 ;
return;
}
}
F_4 ( V_2 , V_30 , 0 ) ;
F_4 ( V_2 , V_38 , V_39 | V_112 ) ;
V_101 = F_2 ( V_2 , V_113 ) >> 5 ;
F_4 ( V_2 , V_38 , V_39 ) ;
F_4 ( V_2 , V_30 , V_78 ) ;
F_4 ( V_2 , V_38 , V_39 | V_112 ) ;
V_102 = F_2 ( V_2 , V_113 ) >> 5 ;
F_4 ( V_2 , V_38 , V_39 ) ;
F_4 ( V_2 , V_30 , 0 ) ;
F_58 ( L_7 , V_101 , V_102 ) ;
if ( V_101 == 6 && V_102 == 7 ) {
V_2 -> V_14 . type = V_118 ;
V_2 -> V_36 |= V_110 | V_54 ;
return;
}
V_105 = F_2 ( V_2 , V_59 ) ;
F_4 ( V_2 , V_59 , V_105 & ~ V_119 ) ;
if ( ! ( F_2 ( V_2 , V_59 ) & V_119 ) ) {
F_4 ( V_2 , V_59 , V_105 | V_119 ) ;
if ( F_2 ( V_2 , V_59 ) & V_119 ) {
F_58 ( L_8 ) ;
V_2 -> V_14 . type = V_120 ;
V_2 -> V_36 |= V_121 | V_122 ;
return;
}
} else {
F_58 ( L_9 ) ;
}
F_4 ( V_2 , V_59 , V_105 ) ;
if ( V_2 -> V_14 . V_107 & V_108 ) {
F_58 ( L_10 ) ;
V_2 -> V_14 . type = V_51 ;
V_2 -> V_36 |= V_110 | V_55 |
V_54 ;
return;
}
if ( V_2 -> V_14 . type == V_106 && F_52 ( V_2 ) == 64 ) {
V_2 -> V_14 . type = V_123 ;
V_2 -> V_36 |= V_110 ;
}
}
static void F_63 ( struct V_1 * V_2 )
{
unsigned char V_101 , V_100 , V_124 , V_125 ;
unsigned char V_126 , V_127 ;
struct V_6 * V_14 = & V_2 -> V_14 ;
unsigned long V_107 ;
unsigned int V_128 ;
if ( ! V_14 -> V_16 && ! V_14 -> V_129 && ! V_14 -> V_11 )
return;
F_58 ( L_11 ,
F_64 ( V_14 ) , V_14 -> V_16 , V_14 -> V_11 ) ;
F_65 ( & V_14 -> V_68 , V_107 ) ;
V_2 -> V_36 = 0 ;
V_2 -> V_95 = 0 ;
if ( ! ( V_14 -> V_107 & V_130 ) ) {
V_100 = F_2 ( V_2 , V_59 ) ;
F_4 ( V_2 , V_59 , 0 ) ;
#ifdef F_66
F_13 ( 0xff , 0x080 ) ;
#endif
V_124 = F_2 ( V_2 , V_59 ) & 0x0f ;
F_4 ( V_2 , V_59 , 0x0F ) ;
#ifdef F_66
F_13 ( 0 , 0x080 ) ;
#endif
V_125 = F_2 ( V_2 , V_59 ) & 0x0f ;
F_4 ( V_2 , V_59 , V_100 ) ;
if ( V_124 != 0 || V_125 != 0x0F ) {
F_67 ( & V_14 -> V_68 , V_107 ) ;
F_58 ( L_12 ,
V_124 , V_125 ) ;
goto V_53;
}
}
V_127 = F_2 ( V_2 , V_76 ) ;
V_126 = F_2 ( V_2 , V_30 ) ;
if ( ! ( V_14 -> V_107 & V_131 ) ) {
F_4 ( V_2 , V_76 , V_77 | 0x0A ) ;
V_101 = F_2 ( V_2 , V_132 ) & 0xF0 ;
F_4 ( V_2 , V_76 , V_127 ) ;
if ( V_101 != 0x90 ) {
F_67 ( & V_14 -> V_68 , V_107 ) ;
F_58 ( L_13 ,
V_101 ) ;
goto V_53;
}
}
F_4 ( V_2 , V_30 , V_57 ) ;
F_4 ( V_2 , V_56 , 0 ) ;
F_4 ( V_2 , V_30 , 0 ) ;
F_4 ( V_2 , V_38 , V_39 ) ;
V_100 = F_2 ( V_2 , V_113 ) >> 6 ;
switch ( V_100 ) {
case 0 :
F_59 ( V_2 ) ;
break;
case 1 :
V_14 -> type = V_133 ;
break;
case 2 :
V_14 -> type = V_134 ;
break;
case 3 :
F_61 ( V_2 ) ;
break;
}
#ifdef F_68
if ( V_14 -> type == V_106 && V_2 -> V_135 & V_136 &&
F_47 ( V_2 ) )
V_14 -> type = V_67 ;
#endif
F_4 ( V_2 , V_30 , V_126 ) ;
V_14 -> V_137 = V_138 [ V_2 -> V_14 . type ] . V_139 ;
V_128 = V_2 -> V_36 ;
V_2 -> V_36 = V_138 [ V_14 -> type ] . V_107 ;
V_2 -> V_140 = V_138 [ V_14 -> type ] . V_140 ;
if ( V_14 -> type == V_133 )
goto V_141;
#ifdef F_68
if ( V_14 -> type == V_67 )
F_4 ( V_2 , V_69 , 0 ) ;
#endif
F_4 ( V_2 , V_76 , V_127 ) ;
F_36 ( V_2 ) ;
F_2 ( V_2 , V_82 ) ;
if ( V_2 -> V_36 & V_121 )
F_4 ( V_2 , V_59 , V_119 ) ;
else
F_4 ( V_2 , V_59 , 0 ) ;
V_141:
F_67 ( & V_14 -> V_68 , V_107 ) ;
if ( V_2 -> V_36 != V_128 ) {
F_69 ( V_142
L_14 ,
F_64 ( V_14 ) , V_128 ,
V_2 -> V_36 ) ;
}
V_53:
F_58 ( L_15 , V_100 ) ;
F_58 ( L_16 , V_138 [ V_14 -> type ] . V_143 ) ;
}
static void F_70 ( struct V_1 * V_2 )
{
struct V_6 * V_14 = & V_2 -> V_14 ;
unsigned char V_127 , V_144 ;
unsigned char V_145 = 0 ;
unsigned int V_146 = 0 ;
unsigned long V_147 ;
int V_148 ;
if ( V_14 -> V_107 & V_149 ) {
V_146 = ( V_14 -> V_16 & 0xfe0 ) | 0x1f ;
V_145 = F_71 ( V_146 ) ;
F_72 ( 0x80 , V_146 ) ;
F_71 ( V_146 ) ;
}
F_73 ( F_74 () ) ;
V_127 = F_2 ( V_2 , V_76 ) ;
V_144 = F_2 ( V_2 , V_59 ) ;
F_4 ( V_2 , V_76 , V_150 | V_151 ) ;
V_147 = F_74 () ;
F_4 ( V_2 , V_76 , 0 ) ;
F_75 ( 10 ) ;
if ( V_14 -> V_107 & V_149 ) {
F_4 ( V_2 , V_76 ,
V_152 | V_153 ) ;
} else {
F_4 ( V_2 , V_76 ,
V_152 | V_153 | V_151 ) ;
}
F_4 ( V_2 , V_59 , 0x0f ) ;
F_2 ( V_2 , V_80 ) ;
F_2 ( V_2 , V_82 ) ;
F_2 ( V_2 , V_113 ) ;
F_2 ( V_2 , V_132 ) ;
F_4 ( V_2 , V_79 , 0xFF ) ;
F_75 ( 20 ) ;
V_148 = F_73 ( V_147 ) ;
F_4 ( V_2 , V_76 , V_127 ) ;
F_4 ( V_2 , V_59 , V_144 ) ;
if ( V_14 -> V_107 & V_149 )
F_72 ( V_145 , V_146 ) ;
V_14 -> V_148 = ( V_148 > 0 ) ? V_148 : 0 ;
}
static inline void F_76 ( struct V_1 * V_7 )
{
if ( V_7 -> V_154 & V_155 ) {
V_7 -> V_154 &= ~ V_155 ;
F_4 ( V_7 , V_59 , V_7 -> V_154 ) ;
F_45 ( V_7 ) ;
}
}
static void F_77 ( struct V_6 * V_14 )
{
struct V_1 * V_2 = F_31 ( V_14 ) ;
F_38 ( V_2 ) ;
F_76 ( V_2 ) ;
if ( V_14 -> type == V_94 ) {
V_2 -> V_34 |= V_156 ;
F_34 ( V_2 , V_33 , V_2 -> V_34 ) ;
}
F_40 ( V_2 ) ;
}
static void F_78 ( struct V_6 * V_14 )
{
struct V_1 * V_2 = F_31 ( V_14 ) ;
F_43 ( V_2 ) ;
if ( V_2 -> V_157 && ! V_2 -> V_157 -> V_158 ( V_2 ) )
return;
if ( ! ( V_2 -> V_154 & V_155 ) ) {
V_2 -> V_154 |= V_155 ;
F_79 ( V_14 , V_59 , V_2 -> V_154 ) ;
if ( V_2 -> V_95 & V_159 ) {
unsigned char V_160 ;
V_160 = F_2 ( V_2 , V_80 ) ;
V_2 -> V_161 |= V_160 & V_162 ;
if ( V_160 & V_163 )
F_80 ( V_2 ) ;
}
}
if ( V_14 -> type == V_94 && V_2 -> V_34 & V_156 ) {
V_2 -> V_34 &= ~ V_156 ;
F_34 ( V_2 , V_33 , V_2 -> V_34 ) ;
}
}
static void F_81 ( struct V_6 * V_14 )
{
V_14 -> V_164 ( V_14 ) ;
}
static void F_82 ( struct V_6 * V_14 )
{
V_14 -> V_165 ( V_14 ) ;
}
static void F_83 ( struct V_6 * V_14 )
{
struct V_1 * V_2 = F_31 ( V_14 ) ;
F_38 ( V_2 ) ;
V_2 -> V_154 &= ~ ( V_166 | V_167 ) ;
V_2 -> V_14 . V_168 &= ~ V_81 ;
F_79 ( V_14 , V_59 , V_2 -> V_154 ) ;
F_40 ( V_2 ) ;
}
static void F_84 ( struct V_6 * V_14 )
{
struct V_1 * V_2 =
F_85 ( V_14 , struct V_1 , V_14 ) ;
if ( V_2 -> V_95 & V_169 )
return;
V_2 -> V_154 &= ~ V_170 ;
F_79 ( V_14 , V_59 , V_2 -> V_154 ) ;
}
static void F_86 ( struct V_6 * V_14 )
{
struct V_1 * V_2 = F_31 ( V_14 ) ;
if ( V_2 -> V_95 & V_169 )
return;
V_2 -> V_154 |= V_170 ;
F_38 ( V_2 ) ;
F_79 ( V_14 , V_59 , V_2 -> V_154 ) ;
F_40 ( V_2 ) ;
}
unsigned char
F_87 ( struct V_1 * V_2 , unsigned char V_160 )
{
struct V_6 * V_14 = & V_2 -> V_14 ;
unsigned char V_171 ;
int V_172 = 256 ;
char V_173 ;
do {
if ( F_88 ( V_160 & V_81 ) )
V_171 = F_2 ( V_2 , V_82 ) ;
else
V_171 = 0 ;
V_173 = V_174 ;
V_14 -> V_175 . V_176 ++ ;
V_160 |= V_2 -> V_161 ;
V_2 -> V_161 = 0 ;
if ( F_89 ( V_160 & V_177 ) ) {
if ( V_160 & V_178 ) {
V_160 &= ~ ( V_179 | V_180 ) ;
V_14 -> V_175 . V_181 ++ ;
if ( F_90 ( V_14 ) )
goto V_182;
} else if ( V_160 & V_180 )
V_14 -> V_175 . V_183 ++ ;
else if ( V_160 & V_179 )
V_14 -> V_175 . V_184 ++ ;
if ( V_160 & V_185 )
V_14 -> V_175 . V_186 ++ ;
V_160 &= V_14 -> V_168 ;
if ( V_160 & V_178 ) {
F_91 ( L_17 ) ;
V_173 = V_187 ;
} else if ( V_160 & V_180 )
V_173 = V_188 ;
else if ( V_160 & V_179 )
V_173 = V_189 ;
}
if ( F_92 ( V_14 , V_171 ) )
goto V_182;
F_93 ( V_14 , V_160 , V_185 , V_171 , V_173 ) ;
V_182:
V_160 = F_2 ( V_2 , V_80 ) ;
} while ( ( V_160 & ( V_81 | V_178 ) ) && ( -- V_172 > 0 ) );
F_94 ( & V_14 -> V_68 ) ;
F_95 ( & V_14 -> V_190 -> V_14 ) ;
F_96 ( & V_14 -> V_68 ) ;
return V_160 ;
}
void F_80 ( struct V_1 * V_2 )
{
struct V_6 * V_14 = & V_2 -> V_14 ;
struct V_191 * V_192 = & V_14 -> V_190 -> V_192 ;
int V_75 ;
if ( V_14 -> V_193 ) {
F_4 ( V_2 , V_79 , V_14 -> V_193 ) ;
V_14 -> V_175 . V_194 ++ ;
V_14 -> V_193 = 0 ;
return;
}
if ( F_97 ( V_14 ) ) {
F_77 ( V_14 ) ;
return;
}
if ( F_98 ( V_192 ) ) {
F_76 ( V_2 ) ;
return;
}
V_75 = V_2 -> V_140 ;
do {
F_4 ( V_2 , V_79 , V_192 -> V_195 [ V_192 -> V_196 ] ) ;
V_192 -> V_196 = ( V_192 -> V_196 + 1 ) & ( V_197 - 1 ) ;
V_14 -> V_175 . V_194 ++ ;
if ( F_98 ( V_192 ) )
break;
if ( V_2 -> V_36 & V_198 ) {
if ( ( F_99 ( V_14 , V_80 ) & V_199 ) !=
V_199 )
break;
}
} while ( -- V_75 > 0 );
if ( F_100 ( V_192 ) < V_200 )
F_101 ( V_14 ) ;
F_91 ( L_18 ) ;
if ( F_98 ( V_192 ) && ! ( V_2 -> V_36 & V_43 ) )
F_76 ( V_2 ) ;
}
unsigned int F_102 ( struct V_1 * V_2 )
{
struct V_6 * V_14 = & V_2 -> V_14 ;
unsigned int V_201 = F_2 ( V_2 , V_132 ) ;
V_201 |= V_2 -> V_202 ;
V_2 -> V_202 = 0 ;
if ( V_201 & V_203 && V_2 -> V_154 & V_170 &&
V_14 -> V_190 != NULL ) {
if ( V_201 & V_204 )
V_14 -> V_175 . V_205 ++ ;
if ( V_201 & V_206 )
V_14 -> V_175 . V_207 ++ ;
if ( V_201 & V_208 )
F_103 ( V_14 , V_201 & V_209 ) ;
if ( V_201 & V_210 )
F_104 ( V_14 , V_201 & V_211 ) ;
F_105 ( & V_14 -> V_190 -> V_14 . V_212 ) ;
}
return V_201 ;
}
int F_106 ( struct V_6 * V_14 , unsigned int V_213 )
{
unsigned char V_201 ;
unsigned long V_107 ;
struct V_1 * V_2 = F_31 ( V_14 ) ;
int V_214 = 0 ;
if ( V_213 & V_215 )
return 0 ;
F_65 ( & V_14 -> V_68 , V_107 ) ;
V_201 = F_99 ( V_14 , V_80 ) ;
F_91 ( L_19 , V_201 ) ;
if ( V_201 & ( V_81 | V_178 ) ) {
if ( V_2 -> V_157 )
V_214 = V_2 -> V_157 -> V_216 ( V_2 , V_213 ) ;
if ( ! V_2 -> V_157 || V_214 )
V_201 = F_87 ( V_2 , V_201 ) ;
}
F_102 ( V_2 ) ;
if ( ( ! V_2 -> V_157 || ( V_2 -> V_157 && V_2 -> V_157 -> V_217 ) ) &&
( V_201 & V_163 ) )
F_80 ( V_2 ) ;
F_67 ( & V_14 -> V_68 , V_107 ) ;
return 1 ;
}
static int V_29 ( struct V_6 * V_14 )
{
struct V_1 * V_2 = F_31 ( V_14 ) ;
unsigned int V_213 ;
int V_218 ;
F_38 ( V_2 ) ;
V_213 = F_99 ( V_14 , V_113 ) ;
V_218 = F_106 ( V_14 , V_213 ) ;
F_40 ( V_2 ) ;
return V_218 ;
}
static int F_107 ( struct V_6 * V_14 )
{
unsigned char V_219 , V_220 , V_221 , V_222 ;
unsigned int V_213 = F_99 ( V_14 , V_113 ) ;
int V_218 ;
V_218 = F_106 ( V_14 , V_213 ) ;
if ( ( V_14 -> type == V_50 ) ||
( V_14 -> type == V_51 ) ) {
V_219 = F_99 ( V_14 , 0x80 ) ;
V_220 = F_99 ( V_14 , 0x81 ) ;
V_221 = F_99 ( V_14 , 0x82 ) ;
V_222 = F_99 ( V_14 , 0x83 ) ;
}
return V_218 ;
}
static unsigned int F_108 ( struct V_6 * V_14 )
{
struct V_1 * V_2 = F_31 ( V_14 ) ;
unsigned long V_107 ;
unsigned int V_160 ;
F_38 ( V_2 ) ;
F_65 ( & V_14 -> V_68 , V_107 ) ;
V_160 = F_99 ( V_14 , V_80 ) ;
V_2 -> V_161 |= V_160 & V_162 ;
F_67 ( & V_14 -> V_68 , V_107 ) ;
F_40 ( V_2 ) ;
return ( V_160 & V_199 ) == V_199 ? V_223 : 0 ;
}
static unsigned int F_109 ( struct V_6 * V_14 )
{
struct V_1 * V_2 = F_31 ( V_14 ) ;
unsigned int V_201 ;
unsigned int V_218 ;
F_38 ( V_2 ) ;
V_201 = F_102 ( V_2 ) ;
F_40 ( V_2 ) ;
V_218 = 0 ;
if ( V_201 & V_209 )
V_218 |= V_224 ;
if ( V_201 & V_225 )
V_218 |= V_226 ;
if ( V_201 & V_227 )
V_218 |= V_228 ;
if ( V_201 & V_211 )
V_218 |= V_229 ;
return V_218 ;
}
void F_110 ( struct V_6 * V_14 , unsigned int V_230 )
{
struct V_1 * V_2 = F_31 ( V_14 ) ;
unsigned char V_231 = 0 ;
if ( V_230 & V_232 )
V_231 |= V_153 ;
if ( V_230 & V_233 )
V_231 |= V_152 ;
if ( V_230 & V_234 )
V_231 |= V_150 ;
if ( V_230 & V_235 )
V_231 |= V_151 ;
if ( V_230 & V_236 )
V_231 |= V_77 ;
V_231 = ( V_231 & V_2 -> V_237 ) | V_2 -> V_238 | V_2 -> V_231 ;
F_79 ( V_14 , V_76 , V_231 ) ;
}
static void F_111 ( struct V_6 * V_14 , unsigned int V_230 )
{
if ( V_14 -> V_239 )
V_14 -> V_239 ( V_14 , V_230 ) ;
else
F_110 ( V_14 , V_230 ) ;
}
static void F_112 ( struct V_6 * V_14 , int V_240 )
{
struct V_1 * V_2 = F_31 ( V_14 ) ;
unsigned long V_107 ;
F_38 ( V_2 ) ;
F_65 ( & V_14 -> V_68 , V_107 ) ;
if ( V_240 == - 1 )
V_2 -> V_48 |= V_241 ;
else
V_2 -> V_48 &= ~ V_241 ;
F_79 ( V_14 , V_30 , V_2 -> V_48 ) ;
F_67 ( & V_14 -> V_68 , V_107 ) ;
F_40 ( V_2 ) ;
}
static void F_113 ( struct V_1 * V_2 , int V_242 )
{
unsigned int V_201 , V_243 = 10000 ;
for (; ; ) {
V_201 = F_2 ( V_2 , V_80 ) ;
V_2 -> V_161 |= V_201 & V_162 ;
if ( ( V_201 & V_242 ) == V_242 )
break;
if ( -- V_243 == 0 )
break;
F_75 ( 1 ) ;
}
if ( V_2 -> V_14 . V_107 & V_244 ) {
unsigned int V_243 ;
for ( V_243 = 1000000 ; V_243 ; V_243 -- ) {
unsigned int V_245 = F_2 ( V_2 , V_132 ) ;
V_2 -> V_202 |= V_245 & V_246 ;
if ( V_245 & V_211 )
break;
F_75 ( 1 ) ;
F_114 () ;
}
}
}
static int F_115 ( struct V_6 * V_14 )
{
struct V_1 * V_2 = F_31 ( V_14 ) ;
unsigned char V_160 ;
int V_201 ;
F_38 ( V_2 ) ;
V_160 = F_99 ( V_14 , V_80 ) ;
if ( ! ( V_160 & V_81 ) ) {
V_201 = V_247 ;
goto V_53;
}
V_201 = F_99 ( V_14 , V_82 ) ;
V_53:
F_40 ( V_2 ) ;
return V_201 ;
}
static void F_116 ( struct V_6 * V_14 ,
unsigned char V_248 )
{
unsigned int V_154 ;
struct V_1 * V_2 = F_31 ( V_14 ) ;
F_38 ( V_2 ) ;
V_154 = F_99 ( V_14 , V_59 ) ;
if ( V_2 -> V_36 & V_121 )
F_79 ( V_14 , V_59 , V_119 ) ;
else
F_79 ( V_14 , V_59 , 0 ) ;
F_113 ( V_2 , V_199 ) ;
F_79 ( V_14 , V_79 , V_248 ) ;
F_113 ( V_2 , V_199 ) ;
F_79 ( V_14 , V_59 , V_154 ) ;
F_40 ( V_2 ) ;
}
int F_117 ( struct V_6 * V_14 )
{
struct V_1 * V_2 = F_31 ( V_14 ) ;
unsigned long V_107 ;
unsigned char V_160 , V_213 ;
int V_249 ;
if ( V_14 -> type == V_250 )
return - V_251 ;
if ( ! V_14 -> V_137 )
V_14 -> V_137 = V_138 [ V_14 -> type ] . V_139 ;
if ( ! V_2 -> V_140 )
V_2 -> V_140 = V_138 [ V_14 -> type ] . V_140 ;
if ( ! V_2 -> V_36 )
V_2 -> V_36 = V_138 [ V_14 -> type ] . V_107 ;
V_2 -> V_231 = 0 ;
if ( V_14 -> V_19 != V_2 -> V_27 )
F_30 ( V_14 ) ;
F_38 ( V_2 ) ;
if ( V_14 -> type == V_94 ) {
V_2 -> V_34 = 0 ;
F_79 ( V_14 , V_30 , V_57 ) ;
F_79 ( V_14 , V_56 , V_58 ) ;
F_79 ( V_14 , V_59 , 0 ) ;
F_79 ( V_14 , V_30 , 0 ) ;
F_34 ( V_2 , V_252 , 0 ) ;
F_79 ( V_14 , V_30 , V_57 ) ;
F_79 ( V_14 , V_56 , V_58 ) ;
F_79 ( V_14 , V_30 , 0 ) ;
}
#ifdef F_68
F_48 ( V_2 ) ;
#endif
if ( V_14 -> type == V_50 ) {
F_79 ( V_14 , V_253 , V_58 ) ;
F_79 ( V_14 , V_59 , 0 ) ;
}
F_36 ( V_2 ) ;
F_99 ( V_14 , V_80 ) ;
F_99 ( V_14 , V_82 ) ;
F_99 ( V_14 , V_113 ) ;
F_99 ( V_14 , V_132 ) ;
if ( ! ( V_14 -> V_107 & V_130 ) &&
( F_99 ( V_14 , V_80 ) == 0xff ) ) {
F_118 ( V_254 L_20 ,
F_64 ( V_14 ) ) ;
V_249 = - V_251 ;
goto V_53;
}
if ( V_14 -> type == V_97 ) {
unsigned char V_255 ;
F_4 ( V_2 , V_30 , V_57 ) ;
V_255 = F_2 ( V_2 , V_256 ) & ~ ( V_257 | V_258 ) ;
F_79 ( V_14 , V_256 ,
V_255 | V_259 | V_257 ) ;
F_79 ( V_14 , V_260 , V_261 ) ;
F_79 ( V_14 , V_256 ,
V_255 | V_259 | V_258 ) ;
F_79 ( V_14 , V_260 , V_261 ) ;
F_79 ( V_14 , V_30 , 0 ) ;
}
if ( V_14 -> V_148 ) {
unsigned char V_262 ;
F_65 ( & V_14 -> V_68 , V_107 ) ;
if ( V_2 -> V_14 . V_263 & V_264 )
F_119 ( V_14 -> V_148 ) ;
F_113 ( V_2 , V_163 ) ;
F_33 ( V_14 , V_59 , V_155 ) ;
F_75 ( 1 ) ;
V_262 = F_99 ( V_14 , V_113 ) ;
F_79 ( V_14 , V_59 , 0 ) ;
F_33 ( V_14 , V_59 , V_155 ) ;
F_75 ( 1 ) ;
V_213 = F_99 ( V_14 , V_113 ) ;
F_79 ( V_14 , V_59 , 0 ) ;
if ( V_14 -> V_263 & V_264 )
F_120 ( V_14 -> V_148 ) ;
F_67 ( & V_14 -> V_68 , V_107 ) ;
if ( ( ! ( V_262 & V_215 ) && ( V_213 & V_215 ) ) ||
V_2 -> V_14 . V_107 & V_265 ) {
V_2 -> V_95 |= V_266 ;
}
}
V_249 = V_2 -> V_267 -> V_268 ( V_2 ) ;
if ( V_249 )
goto V_53;
F_79 ( V_14 , V_30 , V_269 ) ;
F_65 ( & V_14 -> V_68 , V_107 ) ;
if ( V_2 -> V_14 . V_107 & V_149 ) {
if ( ! V_2 -> V_14 . V_148 )
V_2 -> V_14 . V_230 |= V_234 ;
} else
if ( V_14 -> V_148 )
V_2 -> V_14 . V_230 |= V_235 ;
F_111 ( V_14 , V_14 -> V_230 ) ;
if ( V_2 -> V_14 . V_107 & V_270 )
goto V_271;
F_79 ( V_14 , V_59 , V_155 ) ;
V_160 = F_99 ( V_14 , V_80 ) ;
V_213 = F_99 ( V_14 , V_113 ) ;
F_79 ( V_14 , V_59 , 0 ) ;
if ( V_160 & V_272 && V_213 & V_215 ) {
if ( ! ( V_2 -> V_95 & V_159 ) ) {
V_2 -> V_95 |= V_159 ;
F_121 ( L_21 ,
F_64 ( V_14 ) ) ;
}
} else {
V_2 -> V_95 &= ~ V_159 ;
}
V_271:
F_67 ( & V_14 -> V_68 , V_107 ) ;
F_99 ( V_14 , V_80 ) ;
F_99 ( V_14 , V_82 ) ;
F_99 ( V_14 , V_113 ) ;
F_99 ( V_14 , V_132 ) ;
V_2 -> V_161 = 0 ;
V_2 -> V_202 = 0 ;
if ( V_2 -> V_157 ) {
V_249 = F_122 ( V_2 ) ;
if ( V_249 ) {
F_123 ( L_22 ,
F_64 ( V_14 ) ) ;
V_2 -> V_157 = NULL ;
}
}
V_2 -> V_154 = V_166 | V_167 ;
if ( V_14 -> V_107 & V_149 ) {
unsigned int V_273 ;
V_273 = ( V_14 -> V_16 & 0xfe0 ) | 0x01f ;
F_72 ( 0x80 , V_273 ) ;
F_71 ( V_273 ) ;
}
V_249 = 0 ;
V_53:
F_40 ( V_2 ) ;
return V_249 ;
}
static int F_124 ( struct V_6 * V_14 )
{
if ( V_14 -> V_274 )
return V_14 -> V_274 ( V_14 ) ;
return F_117 ( V_14 ) ;
}
void F_125 ( struct V_6 * V_14 )
{
struct V_1 * V_2 = F_31 ( V_14 ) ;
unsigned long V_107 ;
F_38 ( V_2 ) ;
V_2 -> V_154 = 0 ;
F_79 ( V_14 , V_59 , 0 ) ;
if ( V_2 -> V_157 )
F_126 ( V_2 ) ;
F_65 ( & V_14 -> V_68 , V_107 ) ;
if ( V_14 -> V_107 & V_149 ) {
F_14 ( ( V_14 -> V_16 & 0xfe0 ) | 0x1f ) ;
V_14 -> V_230 |= V_234 ;
} else
V_14 -> V_230 &= ~ V_235 ;
F_111 ( V_14 , V_14 -> V_230 ) ;
F_67 ( & V_14 -> V_68 , V_107 ) ;
F_79 ( V_14 , V_30 ,
F_99 ( V_14 , V_30 ) & ~ V_241 ) ;
F_36 ( V_2 ) ;
#ifdef F_68
F_51 ( V_2 ) ;
#endif
F_99 ( V_14 , V_82 ) ;
F_40 ( V_2 ) ;
V_2 -> V_267 -> V_275 ( V_2 ) ;
}
static void F_127 ( struct V_6 * V_14 )
{
if ( V_14 -> V_276 )
V_14 -> V_276 ( V_14 ) ;
else
F_125 ( V_14 ) ;
}
static unsigned int F_128 ( struct V_1 * V_2 ,
unsigned int V_277 ,
unsigned int * V_278 )
{
struct V_6 * V_14 = & V_2 -> V_14 ;
unsigned int V_279 ;
V_279 = F_129 ( V_14 -> V_65 , V_277 ) ;
* V_278 = V_279 & 0x0f ;
return V_279 >> 4 ;
}
static unsigned int F_130 ( struct V_1 * V_2 ,
unsigned int V_277 ,
unsigned int * V_278 )
{
struct V_6 * V_14 = & V_2 -> V_14 ;
unsigned int V_115 ;
if ( ( V_14 -> V_107 & V_280 ) &&
V_277 == ( V_14 -> V_65 / 4 ) )
V_115 = 0x8001 ;
else if ( ( V_14 -> V_107 & V_280 ) &&
V_277 == ( V_14 -> V_65 / 8 ) )
V_115 = 0x8002 ;
else if ( V_2 -> V_14 . type == V_50 )
V_115 = F_128 ( V_2 , V_277 , V_278 ) ;
else
V_115 = F_131 ( V_14 , V_277 ) ;
if ( V_2 -> V_95 & V_96 && ( V_115 & 0xff ) == 0 )
V_115 ++ ;
return V_115 ;
}
static unsigned char F_132 ( struct V_1 * V_2 ,
T_1 V_281 )
{
unsigned char V_282 ;
switch ( V_281 & V_283 ) {
case V_284 :
V_282 = V_285 ;
break;
case V_286 :
V_282 = V_287 ;
break;
case V_288 :
V_282 = V_289 ;
break;
default:
case V_290 :
V_282 = V_269 ;
break;
}
if ( V_281 & V_291 )
V_282 |= V_292 ;
if ( V_281 & V_293 ) {
V_282 |= V_294 ;
if ( V_2 -> V_95 & V_295 )
V_2 -> V_296 = true ;
}
if ( ! ( V_281 & V_297 ) )
V_282 |= V_298 ;
#ifdef F_133
if ( V_281 & F_133 )
V_282 |= V_299 ;
#endif
return V_282 ;
}
static void F_134 ( struct V_6 * V_14 , unsigned int V_277 ,
unsigned int V_115 , unsigned int V_300 )
{
struct V_1 * V_2 = F_31 ( V_14 ) ;
if ( F_135 ( V_2 ) ) {
if ( V_277 == 115200 ) {
V_115 = 1 ;
F_79 ( V_14 , V_301 , 1 ) ;
} else
F_79 ( V_14 , V_301 , 0 ) ;
}
if ( V_2 -> V_36 & V_117 )
F_79 ( V_14 , V_30 , 0xe0 ) ;
else
F_79 ( V_14 , V_30 , V_2 -> V_48 | V_302 ) ;
F_54 ( V_2 , V_115 ) ;
if ( V_2 -> V_14 . type == V_50 )
F_79 ( V_14 , 0x2 , V_300 ) ;
}
void
F_136 ( struct V_6 * V_14 , struct V_303 * V_304 ,
struct V_303 * V_305 )
{
struct V_1 * V_2 = F_31 ( V_14 ) ;
unsigned char V_282 ;
unsigned long V_107 ;
unsigned int V_277 , V_115 , V_278 = 0 ;
V_282 = F_132 ( V_2 , V_304 -> V_281 ) ;
V_277 = F_137 ( V_14 , V_304 , V_305 ,
V_14 -> V_65 / 16 / 0xffff ,
V_14 -> V_65 / 16 ) ;
V_115 = F_130 ( V_2 , V_277 , & V_278 ) ;
F_38 ( V_2 ) ;
F_65 ( & V_14 -> V_68 , V_107 ) ;
V_2 -> V_48 = V_282 ;
if ( V_2 -> V_36 & V_37 && V_14 -> V_137 > 1 ) {
if ( ( V_277 < 2400 && ! V_2 -> V_157 ) || V_2 -> V_296 ) {
V_2 -> V_42 &= ~ V_306 ;
V_2 -> V_42 |= V_307 ;
}
}
if ( V_2 -> V_36 & V_110 && V_14 -> V_137 >= 32 ) {
V_2 -> V_231 &= ~ V_308 ;
if ( V_304 -> V_281 & V_309 )
V_2 -> V_231 |= V_308 ;
}
F_138 ( V_14 , V_304 -> V_281 , V_277 ) ;
V_14 -> V_168 = V_185 | V_163 | V_81 ;
if ( V_304 -> V_310 & V_311 )
V_14 -> V_168 |= V_179 | V_180 ;
if ( V_304 -> V_310 & ( V_312 | V_313 | V_314 ) )
V_14 -> V_168 |= V_178 ;
V_14 -> V_315 = 0 ;
if ( V_304 -> V_310 & V_316 )
V_14 -> V_315 |= V_180 | V_179 ;
if ( V_304 -> V_310 & V_312 ) {
V_14 -> V_315 |= V_178 ;
if ( V_304 -> V_310 & V_316 )
V_14 -> V_315 |= V_185 ;
}
if ( ( V_304 -> V_281 & V_317 ) == 0 )
V_14 -> V_315 |= V_81 ;
V_2 -> V_154 &= ~ V_170 ;
if ( ! ( V_2 -> V_95 & V_169 ) &&
F_139 ( & V_2 -> V_14 , V_304 -> V_281 ) )
V_2 -> V_154 |= V_170 ;
if ( V_2 -> V_36 & V_121 )
V_2 -> V_154 |= V_119 ;
if ( V_2 -> V_36 & V_122 )
V_2 -> V_154 |= V_318 ;
F_79 ( V_14 , V_59 , V_2 -> V_154 ) ;
if ( V_2 -> V_36 & V_55 ) {
unsigned char V_49 = 0 ;
if ( V_304 -> V_281 & V_309 )
V_49 |= V_319 ;
F_79 ( V_14 , V_30 , V_57 ) ;
if ( V_14 -> V_107 & V_108 )
F_79 ( V_14 , V_253 , V_49 ) ;
else
F_79 ( V_14 , V_56 , V_49 ) ;
}
F_134 ( V_14 , V_277 , V_115 , V_278 ) ;
if ( V_14 -> type == V_118 )
F_79 ( V_14 , V_38 , V_2 -> V_42 ) ;
F_79 ( V_14 , V_30 , V_2 -> V_48 ) ;
if ( V_14 -> type != V_118 ) {
if ( V_2 -> V_42 & V_39 )
F_79 ( V_14 , V_38 , V_39 ) ;
F_79 ( V_14 , V_38 , V_2 -> V_42 ) ;
}
F_111 ( V_14 , V_14 -> V_230 ) ;
F_67 ( & V_14 -> V_68 , V_107 ) ;
F_40 ( V_2 ) ;
if ( F_140 ( V_304 ) )
F_141 ( V_304 , V_277 , V_277 ) ;
}
static void
F_142 ( struct V_6 * V_14 , struct V_303 * V_304 ,
struct V_303 * V_305 )
{
if ( V_14 -> V_320 )
V_14 -> V_320 ( V_14 , V_304 , V_305 ) ;
else
F_136 ( V_14 , V_304 , V_305 ) ;
}
static void
F_143 ( struct V_6 * V_14 , struct V_303 * V_304 )
{
if ( V_304 -> V_321 == V_322 ) {
V_14 -> V_107 |= V_323 ;
F_49 ( & V_14 -> V_68 ) ;
F_86 ( V_14 ) ;
F_50 ( & V_14 -> V_68 ) ;
} else {
V_14 -> V_107 &= ~ V_323 ;
if ( ! F_139 ( V_14 , V_304 -> V_281 ) ) {
F_49 ( & V_14 -> V_68 ) ;
F_84 ( V_14 ) ;
F_50 ( & V_14 -> V_68 ) ;
}
}
}
void F_144 ( struct V_6 * V_14 , unsigned int V_190 ,
unsigned int V_324 )
{
struct V_1 * V_7 = F_31 ( V_14 ) ;
F_46 ( V_7 , V_190 != 0 ) ;
}
static void
F_145 ( struct V_6 * V_14 , unsigned int V_190 ,
unsigned int V_324 )
{
if ( V_14 -> V_325 )
V_14 -> V_325 ( V_14 , V_190 , V_324 ) ;
else
F_144 ( V_14 , V_190 , V_324 ) ;
}
static unsigned int F_146 ( struct V_1 * V_326 )
{
if ( V_326 -> V_14 . V_327 )
return V_326 -> V_14 . V_327 ;
if ( V_326 -> V_14 . V_19 == V_26 ) {
if ( V_326 -> V_14 . type == V_328 )
return 0x100 ;
return 0x1000 ;
}
if ( F_147 ( V_326 ) )
return 0x16 << V_326 -> V_14 . V_12 ;
return 8 << V_326 -> V_14 . V_12 ;
}
static int F_148 ( struct V_1 * V_2 )
{
unsigned int V_329 = F_146 ( V_2 ) ;
struct V_6 * V_14 = & V_2 -> V_14 ;
int V_218 = 0 ;
switch ( V_14 -> V_19 ) {
case V_26 :
case V_330 :
case V_22 :
case V_23 :
case V_21 :
if ( ! V_14 -> V_129 )
break;
if ( ! F_149 ( V_14 -> V_129 , V_329 , L_23 ) ) {
V_218 = - V_331 ;
break;
}
if ( V_14 -> V_107 & V_332 ) {
V_14 -> V_11 = F_150 ( V_14 -> V_129 , V_329 ) ;
if ( ! V_14 -> V_11 ) {
F_151 ( V_14 -> V_129 , V_329 ) ;
V_218 = - V_333 ;
}
}
break;
case V_20 :
case V_334 :
if ( ! F_152 ( V_14 -> V_16 , V_329 , L_23 ) )
V_218 = - V_331 ;
break;
}
return V_218 ;
}
static void F_153 ( struct V_1 * V_2 )
{
unsigned int V_329 = F_146 ( V_2 ) ;
struct V_6 * V_14 = & V_2 -> V_14 ;
switch ( V_14 -> V_19 ) {
case V_26 :
case V_330 :
case V_22 :
case V_23 :
case V_21 :
if ( ! V_14 -> V_129 )
break;
if ( V_14 -> V_107 & V_332 ) {
F_154 ( V_14 -> V_11 ) ;
V_14 -> V_11 = NULL ;
}
F_151 ( V_14 -> V_129 , V_329 ) ;
break;
case V_20 :
case V_334 :
F_155 ( V_14 -> V_16 , V_329 ) ;
break;
}
}
static void F_156 ( struct V_6 * V_14 )
{
struct V_1 * V_2 = F_31 ( V_14 ) ;
F_153 ( V_2 ) ;
}
static int F_157 ( struct V_6 * V_14 )
{
struct V_1 * V_2 = F_31 ( V_14 ) ;
int V_218 ;
if ( V_14 -> type == V_250 )
return - V_251 ;
V_218 = F_148 ( V_2 ) ;
return V_218 ;
}
static int F_158 ( struct V_1 * V_2 )
{
const struct V_335 * V_336 = & V_138 [ V_2 -> V_14 . type ] ;
unsigned char V_337 ;
V_337 = V_336 -> V_338 [ F_159 ( V_2 -> V_42 ) ] ;
return V_337 ? V_337 : - V_339 ;
}
static int F_160 ( struct V_1 * V_2 , unsigned char V_337 )
{
const struct V_335 * V_336 = & V_138 [ V_2 -> V_14 . type ] ;
int V_340 ;
if ( ! V_336 -> V_338 [ F_159 ( V_341 ) ] )
return - V_339 ;
for ( V_340 = 1 ; V_340 < V_342 ; V_340 ++ ) {
if ( V_337 < V_336 -> V_338 [ V_340 ] )
return ( -- V_340 ) << V_343 ;
}
return V_344 ;
}
static int F_161 ( struct V_345 * V_14 )
{
struct V_346 * V_190 = F_85 ( V_14 , struct V_346 , V_14 ) ;
struct V_6 * V_347 = V_190 -> V_6 ;
struct V_1 * V_2 =
F_85 ( V_347 , struct V_1 , V_14 ) ;
if ( ! ( V_2 -> V_36 & V_37 ) || V_347 -> V_137 <= 1 )
return - V_348 ;
return F_158 ( V_2 ) ;
}
static int F_162 ( struct V_345 * V_14 )
{
int V_338 ;
F_163 ( & V_14 -> V_349 ) ;
V_338 = F_161 ( V_14 ) ;
F_164 ( & V_14 -> V_349 ) ;
return V_338 ;
}
static T_2 F_165 ( struct V_350 * V_44 ,
struct V_351 * V_352 , char * V_195 )
{
struct V_345 * V_14 = F_166 ( V_44 ) ;
int V_338 ;
V_338 = F_162 ( V_14 ) ;
if ( V_338 < 0 )
return V_338 ;
return snprintf ( V_195 , V_353 , L_24 , V_338 ) ;
}
static int F_167 ( struct V_345 * V_14 , unsigned char V_337 )
{
struct V_346 * V_190 = F_85 ( V_14 , struct V_346 , V_14 ) ;
struct V_6 * V_347 = V_190 -> V_6 ;
struct V_1 * V_2 =
F_85 ( V_347 , struct V_1 , V_14 ) ;
int V_354 ;
if ( ! ( V_2 -> V_36 & V_37 ) || V_347 -> V_137 <= 1 ||
V_2 -> V_296 )
return - V_348 ;
V_354 = F_160 ( V_2 , V_337 ) ;
if ( V_354 < 0 )
return V_354 ;
F_36 ( V_2 ) ;
V_2 -> V_42 &= ~ V_306 ;
V_2 -> V_42 |= ( unsigned char ) V_354 ;
F_4 ( V_2 , V_38 , V_2 -> V_42 ) ;
return 0 ;
}
static int F_168 ( struct V_345 * V_14 , unsigned char V_337 )
{
int V_218 ;
F_163 ( & V_14 -> V_349 ) ;
V_218 = F_167 ( V_14 , V_337 ) ;
F_164 ( & V_14 -> V_349 ) ;
return V_218 ;
}
static T_2 F_169 ( struct V_350 * V_44 ,
struct V_351 * V_352 , const char * V_195 , T_3 V_75 )
{
struct V_345 * V_14 = F_166 ( V_44 ) ;
unsigned char V_337 ;
int V_218 ;
if ( ! V_75 )
return - V_348 ;
V_218 = F_170 ( V_195 , 10 , & V_337 ) ;
if ( V_218 < 0 )
return V_218 ;
V_218 = F_168 ( V_14 , V_337 ) ;
if ( V_218 < 0 )
return V_218 ;
return V_75 ;
}
static void F_171 ( struct V_1 * V_2 )
{
const struct V_335 * V_336 = & V_138 [ V_2 -> V_14 . type ] ;
if ( V_336 -> V_338 [ 0 ] )
V_2 -> V_14 . V_355 = & V_356 ;
}
static void F_172 ( struct V_6 * V_14 , int V_107 )
{
struct V_1 * V_2 = F_31 ( V_14 ) ;
int V_218 ;
if ( V_14 -> type == V_250 )
return;
V_218 = F_148 ( V_2 ) ;
if ( V_218 < 0 )
return;
if ( V_14 -> V_19 != V_2 -> V_27 )
F_30 ( V_14 ) ;
if ( V_107 & V_357 )
F_63 ( V_2 ) ;
if ( V_14 -> type == V_106 && V_14 -> V_19 == V_26 )
V_2 -> V_95 |= V_169 ;
if ( V_14 -> type == V_358 )
V_2 -> V_95 |= V_169 ;
if ( V_14 -> type != V_133 && V_107 & V_359 )
F_70 ( V_2 ) ;
if ( V_14 -> type == V_133 )
F_153 ( V_2 ) ;
if ( ( V_14 -> type == V_50 ) ||
( V_14 -> type == V_51 ) )
V_14 -> V_28 = F_107 ;
F_171 ( V_2 ) ;
V_2 -> V_42 = V_138 [ V_2 -> V_14 . type ] . V_42 ;
}
static int
F_173 ( struct V_6 * V_14 , struct V_360 * V_361 )
{
if ( V_361 -> V_148 >= V_362 || V_361 -> V_148 < 0 ||
V_361 -> V_363 < 9600 || V_361 -> type < V_133 ||
V_361 -> type >= F_6 ( V_138 ) || V_361 -> type == V_364 ||
V_361 -> type == V_365 )
return - V_348 ;
return 0 ;
}
static const char *
F_174 ( struct V_6 * V_14 )
{
int type = V_14 -> type ;
if ( type >= F_6 ( V_138 ) )
type = 0 ;
return V_138 [ type ] . V_143 ;
}
void F_175 ( struct V_1 * V_2 )
{
struct V_6 * V_14 = & V_2 -> V_14 ;
F_176 ( & V_14 -> V_68 ) ;
V_14 -> V_267 = & V_366 ;
V_2 -> V_27 = 0xFF ;
}
void F_177 ( struct V_1 * V_2 )
{
struct V_6 * V_14 = & V_2 -> V_14 ;
if ( V_2 -> V_14 . V_107 & V_367 ) {
unsigned int type = V_2 -> V_14 . type ;
if ( ! V_2 -> V_14 . V_137 )
V_2 -> V_14 . V_137 = V_138 [ type ] . V_139 ;
if ( ! V_2 -> V_140 )
V_2 -> V_140 = V_138 [ type ] . V_140 ;
if ( ! V_2 -> V_36 )
V_2 -> V_36 = V_138 [ type ] . V_107 ;
}
F_30 ( V_14 ) ;
if ( V_2 -> V_157 ) {
if ( ! V_2 -> V_157 -> V_158 )
V_2 -> V_157 -> V_158 = V_368 ;
if ( ! V_2 -> V_157 -> V_216 )
V_2 -> V_157 -> V_216 = V_369 ;
}
}
static void F_178 ( struct V_6 * V_14 , int V_171 )
{
struct V_1 * V_2 = F_31 ( V_14 ) ;
F_113 ( V_2 , V_163 ) ;
F_79 ( V_14 , V_79 , V_171 ) ;
}
void F_179 ( struct V_1 * V_2 , const char * V_370 ,
unsigned int V_75 )
{
struct V_6 * V_14 = & V_2 -> V_14 ;
unsigned long V_107 ;
unsigned int V_154 ;
int V_371 = 1 ;
F_114 () ;
F_38 ( V_2 ) ;
if ( V_14 -> V_372 )
V_371 = 0 ;
else if ( V_373 )
V_371 = F_180 ( & V_14 -> V_68 , V_107 ) ;
else
F_65 ( & V_14 -> V_68 , V_107 ) ;
V_154 = F_99 ( V_14 , V_59 ) ;
if ( V_2 -> V_36 & V_121 )
F_79 ( V_14 , V_59 , V_119 ) ;
else
F_79 ( V_14 , V_59 , 0 ) ;
if ( V_2 -> V_374 && ( V_2 -> V_374 != F_99 ( V_14 , V_31 ) ) ) {
struct V_303 V_304 ;
unsigned int V_277 , V_115 , V_278 = 0 ;
V_304 . V_281 = V_14 -> V_375 -> V_376 ;
if ( V_14 -> V_190 -> V_14 . V_377 && V_304 . V_281 == 0 )
V_304 . V_281 = V_14 -> V_190 -> V_14 . V_377 -> V_304 . V_281 ;
V_277 = F_137 ( V_14 , & V_304 , NULL ,
V_14 -> V_65 / 16 / 0xffff ,
V_14 -> V_65 / 16 ) ;
V_115 = F_130 ( V_2 , V_277 , & V_278 ) ;
F_134 ( V_14 , V_277 , V_115 , V_278 ) ;
F_79 ( V_14 , V_30 , V_2 -> V_48 ) ;
F_79 ( V_14 , V_76 , V_152 | V_153 ) ;
V_2 -> V_374 = 0 ;
}
F_181 ( V_14 , V_370 , V_75 , F_178 ) ;
F_113 ( V_2 , V_199 ) ;
F_79 ( V_14 , V_59 , V_154 ) ;
if ( V_2 -> V_202 )
F_102 ( V_2 ) ;
if ( V_371 )
F_67 ( & V_14 -> V_68 , V_107 ) ;
F_40 ( V_2 ) ;
}
static unsigned int F_182 ( struct V_6 * V_14 )
{
unsigned char V_48 , V_378 , V_379 ;
unsigned int V_115 ;
V_48 = F_99 ( V_14 , V_30 ) ;
F_79 ( V_14 , V_30 , V_48 | V_302 ) ;
V_378 = F_99 ( V_14 , V_3 ) ;
V_379 = F_99 ( V_14 , V_4 ) ;
F_79 ( V_14 , V_30 , V_48 ) ;
V_115 = ( V_379 << 8 ) | V_378 ;
return ( V_14 -> V_65 / 16 ) / V_115 ;
}
int F_183 ( struct V_6 * V_14 , char * V_380 , bool V_135 )
{
int V_277 = 9600 ;
int V_242 = 8 ;
int V_183 = 'n' ;
int V_381 = 'n' ;
if ( ! V_14 -> V_16 && ! V_14 -> V_11 )
return - V_251 ;
if ( V_380 )
F_184 ( V_380 , & V_277 , & V_183 , & V_242 , & V_381 ) ;
else if ( V_135 )
V_277 = F_182 ( V_14 ) ;
return F_185 ( V_14 , V_14 -> V_375 , V_277 , V_183 , V_242 , V_381 ) ;
}
