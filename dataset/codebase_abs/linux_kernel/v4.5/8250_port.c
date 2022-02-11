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
static void F_28 ( struct V_6 * V_7 , int V_8 , int V_5 )
{
V_8 = V_8 << V_7 -> V_12 ;
F_29 ( V_5 , V_7 -> V_11 + V_8 ) ;
}
static unsigned int F_30 ( struct V_6 * V_7 , int V_8 )
{
V_8 = V_8 << V_7 -> V_12 ;
return F_31 ( V_7 -> V_11 + V_8 ) ;
}
static unsigned int F_32 ( struct V_6 * V_7 , int V_8 )
{
V_8 = V_8 << V_7 -> V_12 ;
return F_14 ( V_7 -> V_16 + V_8 ) ;
}
static void F_33 ( struct V_6 * V_7 , int V_8 , int V_5 )
{
V_8 = V_8 << V_7 -> V_12 ;
F_13 ( V_5 , V_7 -> V_16 + V_8 ) ;
}
static void F_34 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_35 ( V_7 ) ;
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
case V_24 :
V_7 -> F_2 = F_30 ;
V_7 -> F_4 = F_28 ;
break;
#ifdef F_36
case V_25 :
V_7 -> F_2 = F_5 ;
V_7 -> F_4 = F_8 ;
V_2 -> V_17 = F_10 ;
V_2 -> V_18 = F_11 ;
break;
#endif
default:
V_7 -> F_2 = F_32 ;
V_7 -> F_4 = F_33 ;
break;
}
V_2 -> V_26 = V_7 -> V_19 ;
V_7 -> V_27 = V_28 ;
}
static void
F_37 ( struct V_6 * V_7 , int V_8 , int V_5 )
{
switch ( V_7 -> V_19 ) {
case V_21 :
case V_22 :
case V_23 :
case V_24 :
case V_25 :
V_7 -> F_4 ( V_7 , V_8 , V_5 ) ;
V_7 -> F_2 ( V_7 , V_29 ) ;
break;
default:
V_7 -> F_4 ( V_7 , V_8 , V_5 ) ;
}
}
static void F_38 ( struct V_1 * V_2 , int V_8 , int V_5 )
{
F_4 ( V_2 , V_30 , V_8 ) ;
F_4 ( V_2 , V_31 , V_5 ) ;
}
static unsigned int F_39 ( struct V_1 * V_2 , int V_8 )
{
unsigned int V_5 ;
F_38 ( V_2 , V_32 , V_2 -> V_33 | V_34 ) ;
F_4 ( V_2 , V_30 , V_8 ) ;
V_5 = F_2 ( V_2 , V_31 ) ;
F_38 ( V_2 , V_32 , V_2 -> V_33 ) ;
return V_5 ;
}
static void F_40 ( struct V_1 * V_7 )
{
if ( V_7 -> V_35 & V_36 ) {
F_4 ( V_7 , V_37 , V_38 ) ;
F_4 ( V_7 , V_37 , V_38 |
V_39 | V_40 ) ;
F_4 ( V_7 , V_37 , 0 ) ;
}
}
void F_41 ( struct V_1 * V_7 )
{
F_40 ( V_7 ) ;
F_4 ( V_7 , V_37 , V_7 -> V_41 ) ;
}
void F_42 ( struct V_1 * V_7 )
{
if ( ! ( V_7 -> V_35 & V_42 ) )
return;
F_43 ( V_7 -> V_14 . V_43 ) ;
}
void F_44 ( struct V_1 * V_7 )
{
if ( ! ( V_7 -> V_35 & V_42 ) )
return;
F_45 ( V_7 -> V_14 . V_43 ) ;
F_46 ( V_7 -> V_14 . V_43 ) ;
}
static void F_47 ( struct V_1 * V_7 )
{
unsigned char V_44 ;
if ( ! ( V_7 -> V_35 & V_42 ) )
return;
V_44 = F_48 ( & V_7 -> V_45 , 1 ) ;
if ( V_44 )
return;
F_43 ( V_7 -> V_14 . V_43 ) ;
}
static void F_49 ( struct V_1 * V_7 )
{
unsigned char V_44 ;
if ( ! ( V_7 -> V_35 & V_42 ) )
return;
V_44 = F_48 ( & V_7 -> V_45 , 0 ) ;
if ( ! V_44 )
return;
F_45 ( V_7 -> V_14 . V_43 ) ;
F_46 ( V_7 -> V_14 . V_43 ) ;
}
static void F_50 ( struct V_1 * V_7 , int V_46 )
{
unsigned char V_47 = 0 , V_48 = 0 ;
F_42 ( V_7 ) ;
if ( ( V_7 -> V_14 . type == V_49 ) ||
( V_7 -> V_14 . type == V_50 ) ) {
F_4 ( V_7 , V_51 , V_46 ? 0xff : 0 ) ;
goto V_52;
}
if ( V_7 -> V_35 & V_53 ) {
if ( V_7 -> V_35 & V_54 ) {
V_47 = F_2 ( V_7 , V_29 ) ;
V_48 = F_2 ( V_7 , V_55 ) ;
F_4 ( V_7 , V_29 , V_56 ) ;
F_4 ( V_7 , V_55 , V_57 ) ;
F_4 ( V_7 , V_29 , 0 ) ;
}
F_4 ( V_7 , V_58 , V_46 ? V_59 : 0 ) ;
if ( V_7 -> V_35 & V_54 ) {
F_4 ( V_7 , V_29 , V_56 ) ;
F_4 ( V_7 , V_55 , V_48 ) ;
F_4 ( V_7 , V_29 , V_47 ) ;
}
}
V_52:
F_44 ( V_7 ) ;
}
static int F_51 ( struct V_1 * V_2 )
{
unsigned char V_60 ;
int V_61 ;
V_60 = F_2 ( V_2 , V_62 ) ;
V_61 = V_60 & V_63 ;
if ( ! V_61 ) {
F_4 ( V_2 , V_62 , V_60 | V_63 ) ;
V_60 = F_2 ( V_2 , V_62 ) ;
V_61 = V_60 & V_63 ;
}
if ( V_61 )
V_2 -> V_14 . V_64 = V_65 * 16 ;
return V_61 ;
}
static void F_52 ( struct V_1 * V_2 )
{
if ( V_2 -> V_14 . type == V_66 ) {
if ( V_2 -> V_14 . V_64 != V_65 * 16 ) {
F_53 ( & V_2 -> V_14 . V_67 ) ;
F_51 ( V_2 ) ;
F_54 ( & V_2 -> V_14 . V_67 ) ;
}
if ( V_2 -> V_14 . V_64 == V_65 * 16 )
F_4 ( V_2 , V_68 , 0 ) ;
}
}
static void F_55 ( struct V_1 * V_2 )
{
unsigned char V_60 ;
int V_61 ;
if ( V_2 -> V_14 . type == V_66 &&
V_2 -> V_14 . V_64 == V_65 * 16 ) {
F_53 ( & V_2 -> V_14 . V_67 ) ;
V_60 = F_2 ( V_2 , V_62 ) ;
V_61 = ! ( V_60 & V_63 ) ;
if ( ! V_61 ) {
F_4 ( V_2 , V_62 , V_60 & ~ V_63 ) ;
V_60 = F_2 ( V_2 , V_62 ) ;
V_61 = ! ( V_60 & V_63 ) ;
}
if ( V_61 )
V_2 -> V_14 . V_64 = V_69 * 16 ;
F_54 ( & V_2 -> V_14 . V_67 ) ;
}
}
static int F_56 ( struct V_1 * V_2 )
{
unsigned char V_70 , V_71 , V_72 ;
unsigned short V_73 ;
int V_74 ;
V_72 = F_2 ( V_2 , V_29 ) ;
F_4 ( V_2 , V_29 , 0 ) ;
V_70 = F_2 ( V_2 , V_37 ) ;
V_71 = F_2 ( V_2 , V_75 ) ;
F_4 ( V_2 , V_37 , V_38 |
V_39 | V_40 ) ;
F_4 ( V_2 , V_75 , V_76 ) ;
F_4 ( V_2 , V_29 , V_77 ) ;
V_73 = F_57 ( V_2 ) ;
F_58 ( V_2 , 0x0001 ) ;
F_4 ( V_2 , V_29 , 0x03 ) ;
for ( V_74 = 0 ; V_74 < 256 ; V_74 ++ )
F_4 ( V_2 , V_78 , V_74 ) ;
F_59 ( 20 ) ;
for ( V_74 = 0 ; ( F_2 ( V_2 , V_79 ) & V_80 ) &&
( V_74 < 256 ) ; V_74 ++ )
F_2 ( V_2 , V_81 ) ;
F_4 ( V_2 , V_37 , V_70 ) ;
F_4 ( V_2 , V_75 , V_71 ) ;
F_4 ( V_2 , V_29 , V_77 ) ;
F_58 ( V_2 , V_73 ) ;
F_4 ( V_2 , V_29 , V_72 ) ;
return V_74 ;
}
static unsigned int F_60 ( struct V_1 * V_7 )
{
unsigned char V_82 , V_83 , V_72 ;
unsigned int V_84 ;
V_72 = F_2 ( V_7 , V_29 ) ;
F_4 ( V_7 , V_29 , V_77 ) ;
V_82 = F_2 ( V_7 , V_3 ) ;
V_83 = F_2 ( V_7 , V_4 ) ;
F_4 ( V_7 , V_3 , 0 ) ;
F_4 ( V_7 , V_4 , 0 ) ;
V_84 = F_2 ( V_7 , V_3 ) | F_2 ( V_7 , V_4 ) << 8 ;
F_4 ( V_7 , V_3 , V_82 ) ;
F_4 ( V_7 , V_4 , V_83 ) ;
F_4 ( V_7 , V_29 , V_72 ) ;
return V_84 ;
}
static void F_61 ( struct V_1 * V_2 )
{
unsigned int V_85 , V_86 , V_87 , V_88 ;
V_2 -> V_35 |= V_54 | V_53 ;
V_2 -> V_33 = 0 ;
F_4 ( V_2 , V_29 , V_56 ) ;
F_4 ( V_2 , V_55 , V_57 ) ;
F_4 ( V_2 , V_29 , 0x00 ) ;
V_85 = F_39 ( V_2 , V_89 ) ;
V_86 = F_39 ( V_2 , V_90 ) ;
V_87 = F_39 ( V_2 , V_91 ) ;
V_88 = F_39 ( V_2 , V_92 ) ;
F_62 ( L_1 , V_85 , V_86 , V_87 , V_88 ) ;
if ( V_85 == 0x16 && V_86 == 0xC9 &&
( V_87 == 0x50 || V_87 == 0x52 || V_87 == 0x54 ) ) {
V_2 -> V_14 . type = V_93 ;
if ( V_87 == 0x52 && V_88 == 0x01 )
V_2 -> V_94 |= V_95 ;
return;
}
V_85 = F_60 ( V_2 ) ;
F_62 ( L_2 , V_85 ) ;
V_86 = V_85 >> 8 ;
if ( V_86 == 0x10 || V_86 == 0x12 || V_86 == 0x14 ) {
V_2 -> V_14 . type = V_96 ;
return;
}
if ( F_56 ( V_2 ) == 64 )
V_2 -> V_14 . type = V_97 ;
else
V_2 -> V_14 . type = V_98 ;
}
static void F_63 ( struct V_1 * V_2 )
{
unsigned char V_99 , V_100 , V_101 ;
V_2 -> V_14 . type = V_102 ;
V_99 = F_2 ( V_2 , V_30 ) ;
F_4 ( V_2 , V_30 , 0xa5 ) ;
V_100 = F_2 ( V_2 , V_30 ) ;
F_4 ( V_2 , V_30 , 0x5a ) ;
V_101 = F_2 ( V_2 , V_30 ) ;
F_4 ( V_2 , V_30 , V_99 ) ;
if ( V_100 == 0xa5 && V_101 == 0x5a )
V_2 -> V_14 . type = V_103 ;
}
static int F_64 ( struct V_1 * V_2 )
{
if ( F_60 ( V_2 ) == 0x0201 && F_56 ( V_2 ) == 16 )
return 1 ;
return 0 ;
}
static void F_65 ( struct V_1 * V_2 )
{
unsigned char V_100 , V_101 ;
unsigned int V_104 ;
V_2 -> V_14 . type = V_105 ;
V_2 -> V_35 |= V_36 ;
if ( V_2 -> V_14 . V_106 & V_107 ) {
V_100 = F_2 ( V_2 , V_108 ) ;
if ( V_100 == 0x82 || V_100 == 0x84 || V_100 == 0x88 ) {
F_62 ( L_3 ) ;
V_2 -> V_14 . type = V_49 ;
V_2 -> V_35 |= V_109 | V_54 |
V_53 ;
return;
}
}
F_4 ( V_2 , V_29 , V_77 ) ;
if ( F_2 ( V_2 , V_55 ) == 0 ) {
F_4 ( V_2 , V_55 , 0xA8 ) ;
if ( F_2 ( V_2 , V_55 ) != 0 ) {
F_62 ( L_4 ) ;
V_2 -> V_14 . type = V_110 ;
V_2 -> V_35 |= V_54 | V_53 ;
} else {
F_4 ( V_2 , V_29 , 0 ) ;
F_4 ( V_2 , V_37 , V_38 |
V_111 ) ;
V_100 = F_2 ( V_2 , V_112 ) >> 5 ;
F_4 ( V_2 , V_37 , 0 ) ;
F_4 ( V_2 , V_29 , 0 ) ;
if ( V_100 == 7 )
V_2 -> V_14 . type = V_113 ;
else
F_62 ( L_5 ) ;
}
F_4 ( V_2 , V_55 , 0 ) ;
return;
}
F_4 ( V_2 , V_29 , V_56 ) ;
if ( F_2 ( V_2 , V_55 ) == 0 && ! F_64 ( V_2 ) ) {
F_62 ( L_6 ) ;
F_61 ( V_2 ) ;
return;
}
F_4 ( V_2 , V_29 , 0 ) ;
V_100 = F_2 ( V_2 , V_75 ) ;
F_4 ( V_2 , V_29 , 0xE0 ) ;
V_101 = F_2 ( V_2 , 0x02 ) ;
if ( ! ( ( V_101 ^ V_100 ) & V_76 ) ) {
F_4 ( V_2 , V_29 , 0 ) ;
F_4 ( V_2 , V_75 , V_100 ^ V_76 ) ;
F_4 ( V_2 , V_29 , 0xE0 ) ;
V_101 = F_2 ( V_2 , 0x02 ) ;
F_4 ( V_2 , V_29 , 0 ) ;
F_4 ( V_2 , V_75 , V_100 ) ;
if ( ( V_101 ^ V_100 ) & V_76 ) {
unsigned short V_114 ;
F_4 ( V_2 , V_29 , 0xE0 ) ;
V_114 = F_57 ( V_2 ) ;
V_114 <<= 3 ;
if ( F_66 ( V_2 ) )
F_58 ( V_2 , V_114 ) ;
F_4 ( V_2 , V_29 , 0 ) ;
V_2 -> V_14 . V_64 = 921600 * 16 ;
V_2 -> V_14 . type = V_115 ;
V_2 -> V_35 |= V_116 ;
return;
}
}
F_4 ( V_2 , V_29 , 0 ) ;
F_4 ( V_2 , V_37 , V_38 | V_111 ) ;
V_100 = F_2 ( V_2 , V_112 ) >> 5 ;
F_4 ( V_2 , V_37 , V_38 ) ;
F_4 ( V_2 , V_29 , V_77 ) ;
F_4 ( V_2 , V_37 , V_38 | V_111 ) ;
V_101 = F_2 ( V_2 , V_112 ) >> 5 ;
F_4 ( V_2 , V_37 , V_38 ) ;
F_4 ( V_2 , V_29 , 0 ) ;
F_62 ( L_7 , V_100 , V_101 ) ;
if ( V_100 == 6 && V_101 == 7 ) {
V_2 -> V_14 . type = V_117 ;
V_2 -> V_35 |= V_109 | V_53 ;
return;
}
V_104 = F_2 ( V_2 , V_58 ) ;
F_4 ( V_2 , V_58 , V_104 & ~ V_118 ) ;
if ( ! ( F_2 ( V_2 , V_58 ) & V_118 ) ) {
F_4 ( V_2 , V_58 , V_104 | V_118 ) ;
if ( F_2 ( V_2 , V_58 ) & V_118 ) {
F_62 ( L_8 ) ;
V_2 -> V_14 . type = V_119 ;
V_2 -> V_35 |= V_120 | V_121 ;
return;
}
} else {
F_62 ( L_9 ) ;
}
F_4 ( V_2 , V_58 , V_104 ) ;
if ( V_2 -> V_14 . V_106 & V_107 ) {
F_62 ( L_10 ) ;
V_2 -> V_14 . type = V_50 ;
V_2 -> V_35 |= V_109 | V_54 |
V_53 ;
return;
}
if ( V_2 -> V_14 . type == V_105 && F_56 ( V_2 ) == 64 ) {
V_2 -> V_14 . type = V_122 ;
V_2 -> V_35 |= V_109 ;
}
}
static void F_67 ( struct V_1 * V_2 )
{
unsigned char V_100 , V_99 , V_123 , V_124 ;
unsigned char V_125 , V_126 ;
struct V_6 * V_14 = & V_2 -> V_14 ;
unsigned long V_106 ;
unsigned int V_127 ;
if ( ! V_14 -> V_16 && ! V_14 -> V_128 && ! V_14 -> V_11 )
return;
F_62 ( L_11 ,
F_68 ( V_14 ) , V_14 -> V_16 , V_14 -> V_11 ) ;
F_69 ( & V_14 -> V_67 , V_106 ) ;
V_2 -> V_35 = 0 ;
V_2 -> V_94 = 0 ;
if ( ! ( V_14 -> V_106 & V_129 ) ) {
V_99 = F_2 ( V_2 , V_58 ) ;
F_4 ( V_2 , V_58 , 0 ) ;
#ifdef F_70
F_13 ( 0xff , 0x080 ) ;
#endif
V_123 = F_2 ( V_2 , V_58 ) & 0x0f ;
F_4 ( V_2 , V_58 , 0x0F ) ;
#ifdef F_70
F_13 ( 0 , 0x080 ) ;
#endif
V_124 = F_2 ( V_2 , V_58 ) & 0x0f ;
F_4 ( V_2 , V_58 , V_99 ) ;
if ( V_123 != 0 || V_124 != 0x0F ) {
F_71 ( & V_14 -> V_67 , V_106 ) ;
F_62 ( L_12 ,
V_123 , V_124 ) ;
goto V_52;
}
}
V_126 = F_2 ( V_2 , V_75 ) ;
V_125 = F_2 ( V_2 , V_29 ) ;
if ( ! ( V_14 -> V_106 & V_130 ) ) {
F_4 ( V_2 , V_75 , V_76 | 0x0A ) ;
V_100 = F_2 ( V_2 , V_131 ) & 0xF0 ;
F_4 ( V_2 , V_75 , V_126 ) ;
if ( V_100 != 0x90 ) {
F_71 ( & V_14 -> V_67 , V_106 ) ;
F_62 ( L_13 ,
V_100 ) ;
goto V_52;
}
}
F_4 ( V_2 , V_29 , V_56 ) ;
F_4 ( V_2 , V_55 , 0 ) ;
F_4 ( V_2 , V_29 , 0 ) ;
F_4 ( V_2 , V_37 , V_38 ) ;
V_99 = F_2 ( V_2 , V_112 ) >> 6 ;
switch ( V_99 ) {
case 0 :
F_63 ( V_2 ) ;
break;
case 1 :
V_14 -> type = V_132 ;
break;
case 2 :
V_14 -> type = V_133 ;
break;
case 3 :
F_65 ( V_2 ) ;
break;
}
#ifdef F_72
if ( V_14 -> type == V_105 && V_2 -> V_134 & V_135 &&
F_51 ( V_2 ) )
V_14 -> type = V_66 ;
#endif
F_4 ( V_2 , V_29 , V_125 ) ;
V_14 -> V_136 = V_137 [ V_2 -> V_14 . type ] . V_138 ;
V_127 = V_2 -> V_35 ;
V_2 -> V_35 = V_137 [ V_14 -> type ] . V_106 ;
V_2 -> V_139 = V_137 [ V_14 -> type ] . V_139 ;
if ( V_14 -> type == V_132 )
goto V_140;
#ifdef F_72
if ( V_14 -> type == V_66 )
F_4 ( V_2 , V_68 , 0 ) ;
#endif
F_4 ( V_2 , V_75 , V_126 ) ;
F_40 ( V_2 ) ;
F_2 ( V_2 , V_81 ) ;
if ( V_2 -> V_35 & V_120 )
F_4 ( V_2 , V_58 , V_118 ) ;
else
F_4 ( V_2 , V_58 , 0 ) ;
V_140:
F_71 ( & V_14 -> V_67 , V_106 ) ;
if ( V_2 -> V_35 != V_127 ) {
F_73 ( V_141
L_14 ,
F_68 ( V_14 ) , V_127 ,
V_2 -> V_35 ) ;
}
V_52:
F_62 ( L_15 , V_99 ) ;
F_62 ( L_16 , V_137 [ V_14 -> type ] . V_142 ) ;
}
static void F_74 ( struct V_1 * V_2 )
{
struct V_6 * V_14 = & V_2 -> V_14 ;
unsigned char V_126 , V_143 ;
unsigned char V_144 = 0 ;
unsigned int V_145 = 0 ;
unsigned long V_146 ;
int V_147 ;
if ( V_14 -> V_106 & V_148 ) {
V_145 = ( V_14 -> V_16 & 0xfe0 ) | 0x1f ;
V_144 = F_75 ( V_145 ) ;
F_76 ( 0x80 , V_145 ) ;
F_75 ( V_145 ) ;
}
if ( F_77 ( V_14 ) )
F_78 () ;
F_79 ( F_80 () ) ;
V_126 = F_2 ( V_2 , V_75 ) ;
V_143 = F_2 ( V_2 , V_58 ) ;
F_4 ( V_2 , V_75 , V_149 | V_150 ) ;
V_146 = F_80 () ;
F_4 ( V_2 , V_75 , 0 ) ;
F_81 ( 10 ) ;
if ( V_14 -> V_106 & V_148 ) {
F_4 ( V_2 , V_75 ,
V_151 | V_152 ) ;
} else {
F_4 ( V_2 , V_75 ,
V_151 | V_152 | V_150 ) ;
}
F_4 ( V_2 , V_58 , 0x0f ) ;
F_2 ( V_2 , V_79 ) ;
F_2 ( V_2 , V_81 ) ;
F_2 ( V_2 , V_112 ) ;
F_2 ( V_2 , V_131 ) ;
F_4 ( V_2 , V_78 , 0xFF ) ;
F_81 ( 20 ) ;
V_147 = F_79 ( V_146 ) ;
F_4 ( V_2 , V_75 , V_126 ) ;
F_4 ( V_2 , V_58 , V_143 ) ;
if ( V_14 -> V_106 & V_148 )
F_76 ( V_144 , V_145 ) ;
if ( F_77 ( V_14 ) )
F_82 () ;
V_14 -> V_147 = ( V_147 > 0 ) ? V_147 : 0 ;
}
static inline void F_83 ( struct V_1 * V_7 )
{
if ( V_7 -> V_153 & V_154 ) {
V_7 -> V_153 &= ~ V_154 ;
F_4 ( V_7 , V_58 , V_7 -> V_153 ) ;
F_49 ( V_7 ) ;
}
}
static void F_84 ( struct V_6 * V_14 )
{
struct V_1 * V_2 = F_35 ( V_14 ) ;
F_42 ( V_2 ) ;
F_83 ( V_2 ) ;
if ( V_14 -> type == V_93 ) {
V_2 -> V_33 |= V_155 ;
F_38 ( V_2 , V_32 , V_2 -> V_33 ) ;
}
F_44 ( V_2 ) ;
}
static void F_85 ( struct V_6 * V_14 )
{
struct V_1 * V_2 = F_35 ( V_14 ) ;
F_47 ( V_2 ) ;
if ( V_2 -> V_156 && ! V_2 -> V_156 -> V_157 ( V_2 ) )
return;
if ( ! ( V_2 -> V_153 & V_154 ) ) {
V_2 -> V_153 |= V_154 ;
F_86 ( V_14 , V_58 , V_2 -> V_153 ) ;
if ( V_2 -> V_94 & V_158 ) {
unsigned char V_159 ;
V_159 = F_2 ( V_2 , V_79 ) ;
V_2 -> V_160 |= V_159 & V_161 ;
if ( V_159 & V_162 )
F_87 ( V_2 ) ;
}
}
if ( V_14 -> type == V_93 && V_2 -> V_33 & V_155 ) {
V_2 -> V_33 &= ~ V_155 ;
F_38 ( V_2 , V_32 , V_2 -> V_33 ) ;
}
}
static void F_88 ( struct V_6 * V_14 )
{
V_14 -> V_163 ( V_14 ) ;
}
static void F_89 ( struct V_6 * V_14 )
{
V_14 -> V_164 ( V_14 ) ;
}
static void F_90 ( struct V_6 * V_14 )
{
struct V_1 * V_2 = F_35 ( V_14 ) ;
F_42 ( V_2 ) ;
V_2 -> V_153 &= ~ ( V_165 | V_166 ) ;
V_2 -> V_14 . V_167 &= ~ V_80 ;
F_86 ( V_14 , V_58 , V_2 -> V_153 ) ;
F_44 ( V_2 ) ;
}
static void F_91 ( struct V_6 * V_14 )
{
struct V_1 * V_2 =
F_92 ( V_14 , struct V_1 , V_14 ) ;
if ( V_2 -> V_94 & V_168 )
return;
V_2 -> V_153 &= ~ V_169 ;
F_86 ( V_14 , V_58 , V_2 -> V_153 ) ;
}
static void F_93 ( struct V_6 * V_14 )
{
struct V_1 * V_2 = F_35 ( V_14 ) ;
if ( V_2 -> V_94 & V_168 )
return;
V_2 -> V_153 |= V_169 ;
F_42 ( V_2 ) ;
F_86 ( V_14 , V_58 , V_2 -> V_153 ) ;
F_44 ( V_2 ) ;
}
unsigned char
F_94 ( struct V_1 * V_2 , unsigned char V_159 )
{
struct V_6 * V_14 = & V_2 -> V_14 ;
unsigned char V_170 ;
int V_171 = 256 ;
char V_172 ;
do {
if ( F_95 ( V_159 & V_80 ) )
V_170 = F_2 ( V_2 , V_81 ) ;
else
V_170 = 0 ;
V_172 = V_173 ;
V_14 -> V_174 . V_175 ++ ;
V_159 |= V_2 -> V_160 ;
V_2 -> V_160 = 0 ;
if ( F_96 ( V_159 & V_176 ) ) {
if ( V_159 & V_177 ) {
V_159 &= ~ ( V_178 | V_179 ) ;
V_14 -> V_174 . V_180 ++ ;
if ( F_97 ( V_14 ) )
goto V_181;
} else if ( V_159 & V_179 )
V_14 -> V_174 . V_182 ++ ;
else if ( V_159 & V_178 )
V_14 -> V_174 . V_183 ++ ;
if ( V_159 & V_184 )
V_14 -> V_174 . V_185 ++ ;
V_159 &= V_14 -> V_167 ;
if ( V_159 & V_177 ) {
F_98 ( L_17 ) ;
V_172 = V_186 ;
} else if ( V_159 & V_179 )
V_172 = V_187 ;
else if ( V_159 & V_178 )
V_172 = V_188 ;
}
if ( F_99 ( V_14 , V_170 ) )
goto V_181;
F_100 ( V_14 , V_159 , V_184 , V_170 , V_172 ) ;
V_181:
V_159 = F_2 ( V_2 , V_79 ) ;
} while ( ( V_159 & ( V_80 | V_177 ) ) && ( -- V_171 > 0 ) );
F_101 ( & V_14 -> V_67 ) ;
F_102 ( & V_14 -> V_189 -> V_14 ) ;
F_103 ( & V_14 -> V_67 ) ;
return V_159 ;
}
void F_87 ( struct V_1 * V_2 )
{
struct V_6 * V_14 = & V_2 -> V_14 ;
struct V_190 * V_191 = & V_14 -> V_189 -> V_191 ;
int V_74 ;
if ( V_14 -> V_192 ) {
F_4 ( V_2 , V_78 , V_14 -> V_192 ) ;
V_14 -> V_174 . V_193 ++ ;
V_14 -> V_192 = 0 ;
return;
}
if ( F_104 ( V_14 ) ) {
F_84 ( V_14 ) ;
return;
}
if ( F_105 ( V_191 ) ) {
F_83 ( V_2 ) ;
return;
}
V_74 = V_2 -> V_139 ;
do {
F_4 ( V_2 , V_78 , V_191 -> V_194 [ V_191 -> V_195 ] ) ;
V_191 -> V_195 = ( V_191 -> V_195 + 1 ) & ( V_196 - 1 ) ;
V_14 -> V_174 . V_193 ++ ;
if ( F_105 ( V_191 ) )
break;
if ( V_2 -> V_35 & V_197 ) {
if ( ( F_106 ( V_14 , V_79 ) & V_198 ) !=
V_198 )
break;
}
} while ( -- V_74 > 0 );
if ( F_107 ( V_191 ) < V_199 )
F_108 ( V_14 ) ;
F_98 ( L_18 ) ;
if ( F_105 ( V_191 ) && ! ( V_2 -> V_35 & V_42 ) )
F_83 ( V_2 ) ;
}
unsigned int F_109 ( struct V_1 * V_2 )
{
struct V_6 * V_14 = & V_2 -> V_14 ;
unsigned int V_200 = F_2 ( V_2 , V_131 ) ;
V_200 |= V_2 -> V_201 ;
V_2 -> V_201 = 0 ;
if ( V_200 & V_202 && V_2 -> V_153 & V_169 &&
V_14 -> V_189 != NULL ) {
if ( V_200 & V_203 )
V_14 -> V_174 . V_204 ++ ;
if ( V_200 & V_205 )
V_14 -> V_174 . V_206 ++ ;
if ( V_200 & V_207 )
F_110 ( V_14 , V_200 & V_208 ) ;
if ( V_200 & V_209 )
F_111 ( V_14 , V_200 & V_210 ) ;
F_112 ( & V_14 -> V_189 -> V_14 . V_211 ) ;
}
return V_200 ;
}
int F_113 ( struct V_6 * V_14 , unsigned int V_212 )
{
unsigned char V_200 ;
unsigned long V_106 ;
struct V_1 * V_2 = F_35 ( V_14 ) ;
int V_213 = 0 ;
if ( V_212 & V_214 )
return 0 ;
F_69 ( & V_14 -> V_67 , V_106 ) ;
V_200 = F_106 ( V_14 , V_79 ) ;
F_98 ( L_19 , V_200 ) ;
if ( V_200 & ( V_80 | V_177 ) ) {
if ( V_2 -> V_156 )
V_213 = V_2 -> V_156 -> V_215 ( V_2 , V_212 ) ;
if ( ! V_2 -> V_156 || V_213 )
V_200 = F_94 ( V_2 , V_200 ) ;
}
F_109 ( V_2 ) ;
if ( ( ! V_2 -> V_156 || ( V_2 -> V_156 && V_2 -> V_156 -> V_216 ) ) &&
( V_200 & V_162 ) )
F_87 ( V_2 ) ;
F_71 ( & V_14 -> V_67 , V_106 ) ;
return 1 ;
}
static int V_28 ( struct V_6 * V_14 )
{
struct V_1 * V_2 = F_35 ( V_14 ) ;
unsigned int V_212 ;
int V_217 ;
F_42 ( V_2 ) ;
V_212 = F_106 ( V_14 , V_112 ) ;
V_217 = F_113 ( V_14 , V_212 ) ;
F_44 ( V_2 ) ;
return V_217 ;
}
static int F_114 ( struct V_6 * V_14 )
{
unsigned char V_218 , V_219 , V_220 , V_221 ;
unsigned int V_212 = F_106 ( V_14 , V_112 ) ;
int V_217 ;
V_217 = F_113 ( V_14 , V_212 ) ;
if ( ( V_14 -> type == V_49 ) ||
( V_14 -> type == V_50 ) ) {
V_218 = F_106 ( V_14 , 0x80 ) ;
V_219 = F_106 ( V_14 , 0x81 ) ;
V_220 = F_106 ( V_14 , 0x82 ) ;
V_221 = F_106 ( V_14 , 0x83 ) ;
}
return V_217 ;
}
static unsigned int F_115 ( struct V_6 * V_14 )
{
struct V_1 * V_2 = F_35 ( V_14 ) ;
unsigned long V_106 ;
unsigned int V_159 ;
F_42 ( V_2 ) ;
F_69 ( & V_14 -> V_67 , V_106 ) ;
V_159 = F_106 ( V_14 , V_79 ) ;
V_2 -> V_160 |= V_159 & V_161 ;
F_71 ( & V_14 -> V_67 , V_106 ) ;
F_44 ( V_2 ) ;
return ( V_159 & V_198 ) == V_198 ? V_222 : 0 ;
}
static unsigned int F_116 ( struct V_6 * V_14 )
{
struct V_1 * V_2 = F_35 ( V_14 ) ;
unsigned int V_200 ;
unsigned int V_217 ;
F_42 ( V_2 ) ;
V_200 = F_109 ( V_2 ) ;
F_44 ( V_2 ) ;
V_217 = 0 ;
if ( V_200 & V_208 )
V_217 |= V_223 ;
if ( V_200 & V_224 )
V_217 |= V_225 ;
if ( V_200 & V_226 )
V_217 |= V_227 ;
if ( V_200 & V_210 )
V_217 |= V_228 ;
return V_217 ;
}
void F_117 ( struct V_6 * V_14 , unsigned int V_229 )
{
struct V_1 * V_2 = F_35 ( V_14 ) ;
unsigned char V_230 = 0 ;
if ( V_229 & V_231 )
V_230 |= V_152 ;
if ( V_229 & V_232 )
V_230 |= V_151 ;
if ( V_229 & V_233 )
V_230 |= V_149 ;
if ( V_229 & V_234 )
V_230 |= V_150 ;
if ( V_229 & V_235 )
V_230 |= V_76 ;
V_230 = ( V_230 & V_2 -> V_236 ) | V_2 -> V_237 | V_2 -> V_230 ;
F_86 ( V_14 , V_75 , V_230 ) ;
}
static void F_118 ( struct V_6 * V_14 , unsigned int V_229 )
{
if ( V_14 -> V_238 )
V_14 -> V_238 ( V_14 , V_229 ) ;
else
F_117 ( V_14 , V_229 ) ;
}
static void F_119 ( struct V_6 * V_14 , int V_239 )
{
struct V_1 * V_2 = F_35 ( V_14 ) ;
unsigned long V_106 ;
F_42 ( V_2 ) ;
F_69 ( & V_14 -> V_67 , V_106 ) ;
if ( V_239 == - 1 )
V_2 -> V_47 |= V_240 ;
else
V_2 -> V_47 &= ~ V_240 ;
F_86 ( V_14 , V_29 , V_2 -> V_47 ) ;
F_71 ( & V_14 -> V_67 , V_106 ) ;
F_44 ( V_2 ) ;
}
static void F_120 ( struct V_1 * V_2 , int V_241 )
{
unsigned int V_200 , V_242 = 10000 ;
for (; ; ) {
V_200 = F_2 ( V_2 , V_79 ) ;
V_2 -> V_160 |= V_200 & V_161 ;
if ( ( V_200 & V_241 ) == V_241 )
break;
if ( -- V_242 == 0 )
break;
F_81 ( 1 ) ;
}
if ( V_2 -> V_14 . V_106 & V_243 ) {
unsigned int V_242 ;
for ( V_242 = 1000000 ; V_242 ; V_242 -- ) {
unsigned int V_244 = F_2 ( V_2 , V_131 ) ;
V_2 -> V_201 |= V_244 & V_245 ;
if ( V_244 & V_210 )
break;
F_81 ( 1 ) ;
F_121 () ;
}
}
}
static int F_122 ( struct V_6 * V_14 )
{
struct V_1 * V_2 = F_35 ( V_14 ) ;
unsigned char V_159 ;
int V_200 ;
F_42 ( V_2 ) ;
V_159 = F_106 ( V_14 , V_79 ) ;
if ( ! ( V_159 & V_80 ) ) {
V_200 = V_246 ;
goto V_52;
}
V_200 = F_106 ( V_14 , V_81 ) ;
V_52:
F_44 ( V_2 ) ;
return V_200 ;
}
static void F_123 ( struct V_6 * V_14 ,
unsigned char V_247 )
{
unsigned int V_153 ;
struct V_1 * V_2 = F_35 ( V_14 ) ;
F_42 ( V_2 ) ;
V_153 = F_106 ( V_14 , V_58 ) ;
if ( V_2 -> V_35 & V_120 )
F_86 ( V_14 , V_58 , V_118 ) ;
else
F_86 ( V_14 , V_58 , 0 ) ;
F_120 ( V_2 , V_198 ) ;
F_86 ( V_14 , V_78 , V_247 ) ;
F_120 ( V_2 , V_198 ) ;
F_86 ( V_14 , V_58 , V_153 ) ;
F_44 ( V_2 ) ;
}
int F_124 ( struct V_6 * V_14 )
{
struct V_1 * V_2 = F_35 ( V_14 ) ;
unsigned long V_106 ;
unsigned char V_159 , V_212 ;
int V_248 ;
if ( ! V_14 -> V_136 )
V_14 -> V_136 = V_137 [ V_14 -> type ] . V_138 ;
if ( ! V_2 -> V_139 )
V_2 -> V_139 = V_137 [ V_14 -> type ] . V_139 ;
if ( ! V_2 -> V_35 )
V_2 -> V_35 = V_137 [ V_14 -> type ] . V_106 ;
V_2 -> V_230 = 0 ;
if ( V_14 -> V_19 != V_2 -> V_26 )
F_34 ( V_14 ) ;
F_42 ( V_2 ) ;
if ( V_14 -> type == V_93 ) {
V_2 -> V_33 = 0 ;
F_86 ( V_14 , V_29 , V_56 ) ;
F_86 ( V_14 , V_55 , V_57 ) ;
F_86 ( V_14 , V_58 , 0 ) ;
F_86 ( V_14 , V_29 , 0 ) ;
F_38 ( V_2 , V_249 , 0 ) ;
F_86 ( V_14 , V_29 , V_56 ) ;
F_86 ( V_14 , V_55 , V_57 ) ;
F_86 ( V_14 , V_29 , 0 ) ;
}
#ifdef F_72
F_52 ( V_2 ) ;
#endif
if ( V_14 -> type == V_49 ) {
F_86 ( V_14 , V_250 , V_57 ) ;
F_86 ( V_14 , V_58 , 0 ) ;
}
F_40 ( V_2 ) ;
F_106 ( V_14 , V_79 ) ;
F_106 ( V_14 , V_81 ) ;
F_106 ( V_14 , V_112 ) ;
F_106 ( V_14 , V_131 ) ;
if ( ! ( V_14 -> V_106 & V_129 ) &&
( F_106 ( V_14 , V_79 ) == 0xff ) ) {
F_125 ( V_251 L_20 ,
F_68 ( V_14 ) ) ;
V_248 = - V_252 ;
goto V_52;
}
if ( V_14 -> type == V_96 ) {
unsigned char V_253 ;
F_4 ( V_2 , V_29 , V_56 ) ;
V_253 = F_2 ( V_2 , V_254 ) & ~ ( V_255 | V_256 ) ;
F_86 ( V_14 , V_254 ,
V_253 | V_257 | V_255 ) ;
F_86 ( V_14 , V_258 , V_259 ) ;
F_86 ( V_14 , V_254 ,
V_253 | V_257 | V_256 ) ;
F_86 ( V_14 , V_258 , V_259 ) ;
F_86 ( V_14 , V_29 , 0 ) ;
}
if ( V_14 -> V_147 ) {
unsigned char V_260 ;
F_69 ( & V_14 -> V_67 , V_106 ) ;
if ( V_2 -> V_14 . V_261 & V_262 )
F_126 ( V_14 -> V_147 ) ;
F_120 ( V_2 , V_162 ) ;
F_37 ( V_14 , V_58 , V_154 ) ;
F_81 ( 1 ) ;
V_260 = F_106 ( V_14 , V_112 ) ;
F_86 ( V_14 , V_58 , 0 ) ;
F_37 ( V_14 , V_58 , V_154 ) ;
F_81 ( 1 ) ;
V_212 = F_106 ( V_14 , V_112 ) ;
F_86 ( V_14 , V_58 , 0 ) ;
if ( V_14 -> V_261 & V_262 )
F_127 ( V_14 -> V_147 ) ;
F_71 ( & V_14 -> V_67 , V_106 ) ;
if ( ( ! ( V_260 & V_214 ) && ( V_212 & V_214 ) ) ||
V_2 -> V_14 . V_106 & V_263 ) {
V_2 -> V_94 |= V_264 ;
}
}
V_248 = V_2 -> V_265 -> V_266 ( V_2 ) ;
if ( V_248 )
goto V_52;
F_86 ( V_14 , V_29 , V_267 ) ;
F_69 ( & V_14 -> V_67 , V_106 ) ;
if ( V_2 -> V_14 . V_106 & V_148 ) {
if ( ! V_2 -> V_14 . V_147 )
V_2 -> V_14 . V_229 |= V_233 ;
} else
if ( V_14 -> V_147 )
V_2 -> V_14 . V_229 |= V_234 ;
F_118 ( V_14 , V_14 -> V_229 ) ;
if ( V_2 -> V_14 . V_106 & V_268 )
goto V_269;
F_86 ( V_14 , V_58 , V_154 ) ;
V_159 = F_106 ( V_14 , V_79 ) ;
V_212 = F_106 ( V_14 , V_112 ) ;
F_86 ( V_14 , V_58 , 0 ) ;
if ( V_159 & V_270 && V_212 & V_214 ) {
if ( ! ( V_2 -> V_94 & V_158 ) ) {
V_2 -> V_94 |= V_158 ;
F_128 ( L_21 ,
F_68 ( V_14 ) ) ;
}
} else {
V_2 -> V_94 &= ~ V_158 ;
}
V_269:
F_71 ( & V_14 -> V_67 , V_106 ) ;
F_106 ( V_14 , V_79 ) ;
F_106 ( V_14 , V_81 ) ;
F_106 ( V_14 , V_112 ) ;
F_106 ( V_14 , V_131 ) ;
V_2 -> V_160 = 0 ;
V_2 -> V_201 = 0 ;
if ( V_2 -> V_156 ) {
V_248 = F_129 ( V_2 ) ;
if ( V_248 ) {
F_130 ( L_22 ,
F_68 ( V_14 ) ) ;
V_2 -> V_156 = NULL ;
}
}
V_2 -> V_153 = V_165 | V_166 ;
if ( V_14 -> V_106 & V_148 ) {
unsigned int V_271 ;
V_271 = ( V_14 -> V_16 & 0xfe0 ) | 0x01f ;
F_76 ( 0x80 , V_271 ) ;
F_75 ( V_271 ) ;
}
V_248 = 0 ;
V_52:
F_44 ( V_2 ) ;
return V_248 ;
}
static int F_131 ( struct V_6 * V_14 )
{
if ( V_14 -> V_272 )
return V_14 -> V_272 ( V_14 ) ;
return F_124 ( V_14 ) ;
}
void F_132 ( struct V_6 * V_14 )
{
struct V_1 * V_2 = F_35 ( V_14 ) ;
unsigned long V_106 ;
F_42 ( V_2 ) ;
V_2 -> V_153 = 0 ;
F_86 ( V_14 , V_58 , 0 ) ;
if ( V_2 -> V_156 )
F_133 ( V_2 ) ;
F_69 ( & V_14 -> V_67 , V_106 ) ;
if ( V_14 -> V_106 & V_148 ) {
F_14 ( ( V_14 -> V_16 & 0xfe0 ) | 0x1f ) ;
V_14 -> V_229 |= V_233 ;
} else
V_14 -> V_229 &= ~ V_234 ;
F_118 ( V_14 , V_14 -> V_229 ) ;
F_71 ( & V_14 -> V_67 , V_106 ) ;
F_86 ( V_14 , V_29 ,
F_106 ( V_14 , V_29 ) & ~ V_240 ) ;
F_40 ( V_2 ) ;
#ifdef F_72
F_55 ( V_2 ) ;
#endif
F_106 ( V_14 , V_81 ) ;
F_44 ( V_2 ) ;
V_2 -> V_265 -> V_273 ( V_2 ) ;
}
static void F_134 ( struct V_6 * V_14 )
{
if ( V_14 -> V_274 )
V_14 -> V_274 ( V_14 ) ;
else
F_132 ( V_14 ) ;
}
static unsigned int F_135 ( struct V_1 * V_2 ,
unsigned int V_275 ,
unsigned int * V_276 )
{
struct V_6 * V_14 = & V_2 -> V_14 ;
unsigned int V_277 ;
V_277 = F_136 ( V_14 -> V_64 , V_275 ) ;
* V_276 = V_277 & 0x0f ;
return V_277 >> 4 ;
}
static unsigned int F_137 ( struct V_1 * V_2 ,
unsigned int V_275 ,
unsigned int * V_276 )
{
struct V_6 * V_14 = & V_2 -> V_14 ;
unsigned int V_114 ;
if ( ( V_14 -> V_106 & V_278 ) &&
V_275 == ( V_14 -> V_64 / 4 ) )
V_114 = 0x8001 ;
else if ( ( V_14 -> V_106 & V_278 ) &&
V_275 == ( V_14 -> V_64 / 8 ) )
V_114 = 0x8002 ;
else if ( V_2 -> V_14 . type == V_49 )
V_114 = F_135 ( V_2 , V_275 , V_276 ) ;
else
V_114 = F_138 ( V_14 , V_275 ) ;
if ( V_2 -> V_94 & V_95 && ( V_114 & 0xff ) == 0 )
V_114 ++ ;
return V_114 ;
}
static unsigned char F_139 ( struct V_1 * V_2 ,
T_1 V_279 )
{
unsigned char V_280 ;
switch ( V_279 & V_281 ) {
case V_282 :
V_280 = V_283 ;
break;
case V_284 :
V_280 = V_285 ;
break;
case V_286 :
V_280 = V_287 ;
break;
default:
case V_288 :
V_280 = V_267 ;
break;
}
if ( V_279 & V_289 )
V_280 |= V_290 ;
if ( V_279 & V_291 ) {
V_280 |= V_292 ;
if ( V_2 -> V_94 & V_293 )
V_2 -> V_294 = true ;
}
if ( ! ( V_279 & V_295 ) )
V_280 |= V_296 ;
#ifdef F_140
if ( V_279 & F_140 )
V_280 |= V_297 ;
#endif
return V_280 ;
}
static void F_141 ( struct V_6 * V_14 , unsigned int V_275 ,
unsigned int V_114 , unsigned int V_298 )
{
struct V_1 * V_2 = F_35 ( V_14 ) ;
if ( F_142 ( V_2 ) ) {
if ( V_275 == 115200 ) {
V_114 = 1 ;
F_86 ( V_14 , V_299 , 1 ) ;
} else
F_86 ( V_14 , V_299 , 0 ) ;
}
if ( V_2 -> V_35 & V_116 )
F_86 ( V_14 , V_29 , 0xe0 ) ;
else
F_86 ( V_14 , V_29 , V_2 -> V_47 | V_300 ) ;
F_58 ( V_2 , V_114 ) ;
if ( V_2 -> V_14 . type == V_49 )
F_86 ( V_14 , 0x2 , V_298 ) ;
}
static unsigned int
F_143 ( struct V_6 * V_14 , struct V_301 * V_302 ,
struct V_301 * V_303 )
{
unsigned int V_304 = V_14 -> V_64 / 100 ;
return F_144 ( V_14 , V_302 , V_303 ,
V_14 -> V_64 / 16 / 0xffff ,
( V_14 -> V_64 + V_304 ) / 16 ) ;
}
void
F_145 ( struct V_6 * V_14 , struct V_301 * V_302 ,
struct V_301 * V_303 )
{
struct V_1 * V_2 = F_35 ( V_14 ) ;
unsigned char V_280 ;
unsigned long V_106 ;
unsigned int V_275 , V_114 , V_276 = 0 ;
V_280 = F_139 ( V_2 , V_302 -> V_279 ) ;
V_275 = F_143 ( V_14 , V_302 , V_303 ) ;
V_114 = F_137 ( V_2 , V_275 , & V_276 ) ;
F_42 ( V_2 ) ;
F_69 ( & V_14 -> V_67 , V_106 ) ;
V_2 -> V_47 = V_280 ;
if ( V_2 -> V_35 & V_36 && V_14 -> V_136 > 1 ) {
if ( ( V_275 < 2400 && ! V_2 -> V_156 ) || V_2 -> V_294 ) {
V_2 -> V_41 &= ~ V_305 ;
V_2 -> V_41 |= V_306 ;
}
}
if ( V_2 -> V_35 & V_109 && V_14 -> V_136 >= 32 ) {
V_2 -> V_230 &= ~ V_307 ;
if ( V_302 -> V_279 & V_308 )
V_2 -> V_230 |= V_307 ;
}
F_146 ( V_14 , V_302 -> V_279 , V_275 ) ;
V_14 -> V_167 = V_184 | V_162 | V_80 ;
if ( V_302 -> V_309 & V_310 )
V_14 -> V_167 |= V_178 | V_179 ;
if ( V_302 -> V_309 & ( V_311 | V_312 | V_313 ) )
V_14 -> V_167 |= V_177 ;
V_14 -> V_314 = 0 ;
if ( V_302 -> V_309 & V_315 )
V_14 -> V_314 |= V_179 | V_178 ;
if ( V_302 -> V_309 & V_311 ) {
V_14 -> V_314 |= V_177 ;
if ( V_302 -> V_309 & V_315 )
V_14 -> V_314 |= V_184 ;
}
if ( ( V_302 -> V_279 & V_316 ) == 0 )
V_14 -> V_314 |= V_80 ;
V_2 -> V_153 &= ~ V_169 ;
if ( ! ( V_2 -> V_94 & V_168 ) &&
F_147 ( & V_2 -> V_14 , V_302 -> V_279 ) )
V_2 -> V_153 |= V_169 ;
if ( V_2 -> V_35 & V_120 )
V_2 -> V_153 |= V_118 ;
if ( V_2 -> V_35 & V_121 )
V_2 -> V_153 |= V_317 ;
F_86 ( V_14 , V_58 , V_2 -> V_153 ) ;
if ( V_2 -> V_35 & V_54 ) {
unsigned char V_48 = 0 ;
if ( V_302 -> V_279 & V_308 )
V_48 |= V_318 ;
F_86 ( V_14 , V_29 , V_56 ) ;
if ( V_14 -> V_106 & V_107 )
F_86 ( V_14 , V_250 , V_48 ) ;
else
F_86 ( V_14 , V_55 , V_48 ) ;
}
F_141 ( V_14 , V_275 , V_114 , V_276 ) ;
if ( V_14 -> type == V_117 )
F_86 ( V_14 , V_37 , V_2 -> V_41 ) ;
F_86 ( V_14 , V_29 , V_2 -> V_47 ) ;
if ( V_14 -> type != V_117 ) {
if ( V_2 -> V_41 & V_38 )
F_86 ( V_14 , V_37 , V_38 ) ;
F_86 ( V_14 , V_37 , V_2 -> V_41 ) ;
}
F_118 ( V_14 , V_14 -> V_229 ) ;
F_71 ( & V_14 -> V_67 , V_106 ) ;
F_44 ( V_2 ) ;
if ( F_148 ( V_302 ) )
F_149 ( V_302 , V_275 , V_275 ) ;
}
static void
F_150 ( struct V_6 * V_14 , struct V_301 * V_302 ,
struct V_301 * V_303 )
{
if ( V_14 -> V_319 )
V_14 -> V_319 ( V_14 , V_302 , V_303 ) ;
else
F_145 ( V_14 , V_302 , V_303 ) ;
}
static void
F_151 ( struct V_6 * V_14 , struct V_301 * V_302 )
{
if ( V_302 -> V_320 == V_321 ) {
V_14 -> V_106 |= V_322 ;
F_53 ( & V_14 -> V_67 ) ;
F_93 ( V_14 ) ;
F_54 ( & V_14 -> V_67 ) ;
} else {
V_14 -> V_106 &= ~ V_322 ;
if ( ! F_147 ( V_14 , V_302 -> V_279 ) ) {
F_53 ( & V_14 -> V_67 ) ;
F_91 ( V_14 ) ;
F_54 ( & V_14 -> V_67 ) ;
}
}
}
void F_152 ( struct V_6 * V_14 , unsigned int V_189 ,
unsigned int V_323 )
{
struct V_1 * V_7 = F_35 ( V_14 ) ;
F_50 ( V_7 , V_189 != 0 ) ;
}
static void
F_153 ( struct V_6 * V_14 , unsigned int V_189 ,
unsigned int V_323 )
{
if ( V_14 -> V_324 )
V_14 -> V_324 ( V_14 , V_189 , V_323 ) ;
else
F_152 ( V_14 , V_189 , V_323 ) ;
}
static unsigned int F_154 ( struct V_1 * V_325 )
{
if ( V_325 -> V_14 . V_326 )
return V_325 -> V_14 . V_326 ;
if ( V_325 -> V_14 . V_19 == V_25 ) {
if ( V_325 -> V_14 . type == V_327 )
return 0x100 ;
return 0x1000 ;
}
if ( F_155 ( V_325 ) )
return 0x16 << V_325 -> V_14 . V_12 ;
return 8 << V_325 -> V_14 . V_12 ;
}
static int F_156 ( struct V_1 * V_2 )
{
unsigned int V_328 = F_154 ( V_2 ) ;
struct V_6 * V_14 = & V_2 -> V_14 ;
int V_217 = 0 ;
switch ( V_14 -> V_19 ) {
case V_25 :
case V_329 :
case V_23 :
case V_24 :
case V_22 :
case V_21 :
if ( ! V_14 -> V_128 )
break;
if ( ! F_157 ( V_14 -> V_128 , V_328 , L_23 ) ) {
V_217 = - V_330 ;
break;
}
if ( V_14 -> V_106 & V_331 ) {
V_14 -> V_11 = F_158 ( V_14 -> V_128 , V_328 ) ;
if ( ! V_14 -> V_11 ) {
F_159 ( V_14 -> V_128 , V_328 ) ;
V_217 = - V_332 ;
}
}
break;
case V_20 :
case V_333 :
if ( ! F_160 ( V_14 -> V_16 , V_328 , L_23 ) )
V_217 = - V_330 ;
break;
}
return V_217 ;
}
static void F_161 ( struct V_1 * V_2 )
{
unsigned int V_328 = F_154 ( V_2 ) ;
struct V_6 * V_14 = & V_2 -> V_14 ;
switch ( V_14 -> V_19 ) {
case V_25 :
case V_329 :
case V_23 :
case V_24 :
case V_22 :
case V_21 :
if ( ! V_14 -> V_128 )
break;
if ( V_14 -> V_106 & V_331 ) {
F_162 ( V_14 -> V_11 ) ;
V_14 -> V_11 = NULL ;
}
F_159 ( V_14 -> V_128 , V_328 ) ;
break;
case V_20 :
case V_333 :
F_163 ( V_14 -> V_16 , V_328 ) ;
break;
}
}
static void F_164 ( struct V_6 * V_14 )
{
struct V_1 * V_2 = F_35 ( V_14 ) ;
F_161 ( V_2 ) ;
}
static int F_165 ( struct V_6 * V_14 )
{
struct V_1 * V_2 = F_35 ( V_14 ) ;
return F_156 ( V_2 ) ;
}
static int F_166 ( struct V_1 * V_2 )
{
const struct V_334 * V_335 = & V_137 [ V_2 -> V_14 . type ] ;
unsigned char V_336 ;
V_336 = V_335 -> V_337 [ F_167 ( V_2 -> V_41 ) ] ;
return V_336 ? V_336 : - V_338 ;
}
static int F_168 ( struct V_1 * V_2 , unsigned char V_336 )
{
const struct V_334 * V_335 = & V_137 [ V_2 -> V_14 . type ] ;
int V_339 ;
if ( ! V_335 -> V_337 [ F_167 ( V_340 ) ] )
return - V_338 ;
for ( V_339 = 1 ; V_339 < V_341 ; V_339 ++ ) {
if ( V_336 < V_335 -> V_337 [ V_339 ] )
return ( -- V_339 ) << V_342 ;
}
return V_343 ;
}
static int F_169 ( struct V_344 * V_14 )
{
struct V_345 * V_189 = F_92 ( V_14 , struct V_345 , V_14 ) ;
struct V_6 * V_346 = V_189 -> V_6 ;
struct V_1 * V_2 =
F_92 ( V_346 , struct V_1 , V_14 ) ;
if ( ! ( V_2 -> V_35 & V_36 ) || V_346 -> V_136 <= 1 )
return - V_347 ;
return F_166 ( V_2 ) ;
}
static int F_170 ( struct V_344 * V_14 )
{
int V_337 ;
F_171 ( & V_14 -> V_348 ) ;
V_337 = F_169 ( V_14 ) ;
F_172 ( & V_14 -> V_348 ) ;
return V_337 ;
}
static T_2 F_173 ( struct V_349 * V_43 ,
struct V_350 * V_351 , char * V_194 )
{
struct V_344 * V_14 = F_174 ( V_43 ) ;
int V_337 ;
V_337 = F_170 ( V_14 ) ;
if ( V_337 < 0 )
return V_337 ;
return snprintf ( V_194 , V_352 , L_24 , V_337 ) ;
}
static int F_175 ( struct V_344 * V_14 , unsigned char V_336 )
{
struct V_345 * V_189 = F_92 ( V_14 , struct V_345 , V_14 ) ;
struct V_6 * V_346 = V_189 -> V_6 ;
struct V_1 * V_2 =
F_92 ( V_346 , struct V_1 , V_14 ) ;
int V_353 ;
if ( ! ( V_2 -> V_35 & V_36 ) || V_346 -> V_136 <= 1 ||
V_2 -> V_294 )
return - V_347 ;
V_353 = F_168 ( V_2 , V_336 ) ;
if ( V_353 < 0 )
return V_353 ;
F_40 ( V_2 ) ;
V_2 -> V_41 &= ~ V_305 ;
V_2 -> V_41 |= ( unsigned char ) V_353 ;
F_4 ( V_2 , V_37 , V_2 -> V_41 ) ;
return 0 ;
}
static int F_176 ( struct V_344 * V_14 , unsigned char V_336 )
{
int V_217 ;
F_171 ( & V_14 -> V_348 ) ;
V_217 = F_175 ( V_14 , V_336 ) ;
F_172 ( & V_14 -> V_348 ) ;
return V_217 ;
}
static T_2 F_177 ( struct V_349 * V_43 ,
struct V_350 * V_351 , const char * V_194 , T_3 V_74 )
{
struct V_344 * V_14 = F_174 ( V_43 ) ;
unsigned char V_336 ;
int V_217 ;
if ( ! V_74 )
return - V_347 ;
V_217 = F_178 ( V_194 , 10 , & V_336 ) ;
if ( V_217 < 0 )
return V_217 ;
V_217 = F_176 ( V_14 , V_336 ) ;
if ( V_217 < 0 )
return V_217 ;
return V_74 ;
}
static void F_179 ( struct V_1 * V_2 )
{
const struct V_334 * V_335 = & V_137 [ V_2 -> V_14 . type ] ;
if ( V_335 -> V_337 [ 0 ] )
V_2 -> V_14 . V_354 = & V_355 ;
}
static void F_180 ( struct V_6 * V_14 , int V_106 )
{
struct V_1 * V_2 = F_35 ( V_14 ) ;
int V_217 ;
V_217 = F_156 ( V_2 ) ;
if ( V_217 < 0 )
return;
if ( V_14 -> V_19 != V_2 -> V_26 )
F_34 ( V_14 ) ;
if ( V_106 & V_356 )
F_67 ( V_2 ) ;
if ( V_14 -> type == V_105 && V_14 -> V_19 == V_25 )
V_2 -> V_94 |= V_168 ;
if ( V_14 -> type == V_357 )
V_2 -> V_94 |= V_168 ;
if ( V_14 -> type != V_132 && V_106 & V_358 )
F_74 ( V_2 ) ;
if ( V_14 -> type == V_132 )
F_161 ( V_2 ) ;
if ( ( V_14 -> type == V_49 ) ||
( V_14 -> type == V_50 ) )
V_14 -> V_27 = F_114 ;
F_179 ( V_2 ) ;
V_2 -> V_41 = V_137 [ V_2 -> V_14 . type ] . V_41 ;
}
static int
F_181 ( struct V_6 * V_14 , struct V_359 * V_360 )
{
if ( V_360 -> V_147 >= V_361 || V_360 -> V_147 < 0 ||
V_360 -> V_362 < 9600 || V_360 -> type < V_132 ||
V_360 -> type >= F_6 ( V_137 ) || V_360 -> type == V_363 ||
V_360 -> type == V_364 )
return - V_347 ;
return 0 ;
}
static const char *
F_182 ( struct V_6 * V_14 )
{
int type = V_14 -> type ;
if ( type >= F_6 ( V_137 ) )
type = 0 ;
return V_137 [ type ] . V_142 ;
}
void F_183 ( struct V_1 * V_2 )
{
struct V_6 * V_14 = & V_2 -> V_14 ;
F_184 ( & V_14 -> V_67 ) ;
V_14 -> V_265 = & V_365 ;
V_2 -> V_26 = 0xFF ;
}
void F_185 ( struct V_1 * V_2 )
{
struct V_6 * V_14 = & V_2 -> V_14 ;
if ( V_2 -> V_14 . V_106 & V_366 ) {
unsigned int type = V_2 -> V_14 . type ;
if ( ! V_2 -> V_14 . V_136 )
V_2 -> V_14 . V_136 = V_137 [ type ] . V_138 ;
if ( ! V_2 -> V_139 )
V_2 -> V_139 = V_137 [ type ] . V_139 ;
if ( ! V_2 -> V_35 )
V_2 -> V_35 = V_137 [ type ] . V_106 ;
}
F_34 ( V_14 ) ;
if ( V_2 -> V_156 ) {
if ( ! V_2 -> V_156 -> V_157 )
V_2 -> V_156 -> V_157 = V_367 ;
if ( ! V_2 -> V_156 -> V_215 )
V_2 -> V_156 -> V_215 = V_368 ;
}
}
static void F_186 ( struct V_6 * V_14 , int V_170 )
{
struct V_1 * V_2 = F_35 ( V_14 ) ;
F_120 ( V_2 , V_162 ) ;
F_86 ( V_14 , V_78 , V_170 ) ;
}
static void F_187 ( struct V_1 * V_2 )
{
struct V_6 * V_14 = & V_2 -> V_14 ;
struct V_301 V_302 ;
unsigned int V_275 , V_114 , V_276 = 0 ;
V_302 . V_279 = V_14 -> V_369 -> V_370 ;
if ( V_14 -> V_189 -> V_14 . V_371 && V_302 . V_279 == 0 )
V_302 . V_279 = V_14 -> V_189 -> V_14 . V_371 -> V_302 . V_279 ;
V_275 = F_143 ( V_14 , & V_302 , NULL ) ;
V_114 = F_137 ( V_2 , V_275 , & V_276 ) ;
F_141 ( V_14 , V_275 , V_114 , V_276 ) ;
F_86 ( V_14 , V_29 , V_2 -> V_47 ) ;
F_86 ( V_14 , V_75 , V_151 | V_152 ) ;
}
void F_188 ( struct V_1 * V_2 , const char * V_372 ,
unsigned int V_74 )
{
struct V_6 * V_14 = & V_2 -> V_14 ;
unsigned long V_106 ;
unsigned int V_153 ;
int V_373 = 1 ;
F_121 () ;
F_42 ( V_2 ) ;
if ( V_14 -> V_374 )
V_373 = 0 ;
else if ( V_375 )
V_373 = F_189 ( & V_14 -> V_67 , V_106 ) ;
else
F_69 ( & V_14 -> V_67 , V_106 ) ;
V_153 = F_106 ( V_14 , V_58 ) ;
if ( V_2 -> V_35 & V_120 )
F_86 ( V_14 , V_58 , V_118 ) ;
else
F_86 ( V_14 , V_58 , 0 ) ;
if ( V_2 -> V_376 && ( V_2 -> V_376 != F_106 ( V_14 , V_30 ) ) ) {
F_187 ( V_2 ) ;
V_2 -> V_376 = 0 ;
}
F_190 ( V_14 , V_372 , V_74 , F_186 ) ;
F_120 ( V_2 , V_198 ) ;
F_86 ( V_14 , V_58 , V_153 ) ;
if ( V_2 -> V_201 )
F_109 ( V_2 ) ;
if ( V_373 )
F_71 ( & V_14 -> V_67 , V_106 ) ;
F_44 ( V_2 ) ;
}
static unsigned int F_191 ( struct V_6 * V_14 )
{
unsigned char V_47 , V_377 , V_378 ;
unsigned int V_114 ;
V_47 = F_106 ( V_14 , V_29 ) ;
F_86 ( V_14 , V_29 , V_47 | V_300 ) ;
V_377 = F_106 ( V_14 , V_3 ) ;
V_378 = F_106 ( V_14 , V_4 ) ;
F_86 ( V_14 , V_29 , V_47 ) ;
V_114 = ( V_378 << 8 ) | V_377 ;
return ( V_14 -> V_64 / 16 ) / V_114 ;
}
int F_192 ( struct V_6 * V_14 , char * V_379 , bool V_134 )
{
int V_275 = 9600 ;
int V_241 = 8 ;
int V_182 = 'n' ;
int V_380 = 'n' ;
if ( ! V_14 -> V_16 && ! V_14 -> V_11 )
return - V_252 ;
if ( V_379 )
F_193 ( V_379 , & V_275 , & V_182 , & V_241 , & V_380 ) ;
else if ( V_134 )
V_275 = F_191 ( V_14 ) ;
return F_194 ( V_14 , V_14 -> V_369 , V_275 , V_182 , V_241 , V_380 ) ;
}
