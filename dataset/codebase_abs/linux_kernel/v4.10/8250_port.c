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
static inline void F_41 ( struct V_1 * V_7 )
{
unsigned char V_41 = F_42 ( V_7 ) ;
if ( V_7 -> V_14 . V_42 . V_43 & V_44 )
V_41 |= V_45 ;
else
V_41 &= ~ V_45 ;
F_43 ( V_7 , V_41 ) ;
}
void F_44 ( struct V_1 * V_7 )
{
F_40 ( V_7 ) ;
F_4 ( V_7 , V_37 , V_7 -> V_46 ) ;
}
void F_45 ( struct V_1 * V_7 )
{
if ( ! ( V_7 -> V_35 & V_47 ) )
return;
F_46 ( V_7 -> V_14 . V_48 ) ;
}
void F_47 ( struct V_1 * V_7 )
{
if ( ! ( V_7 -> V_35 & V_47 ) )
return;
F_48 ( V_7 -> V_14 . V_48 ) ;
F_49 ( V_7 -> V_14 . V_48 ) ;
}
int F_50 ( struct V_1 * V_7 )
{
if ( V_7 -> V_49 )
return 0 ;
V_7 -> V_49 = F_51 ( sizeof( struct V_50 ) , V_51 ) ;
if ( ! V_7 -> V_49 )
return - V_52 ;
F_52 ( & V_7 -> V_49 -> V_53 ,
V_54 , ( unsigned long ) V_7 ) ;
F_52 ( & V_7 -> V_49 -> V_55 ,
V_56 , ( unsigned long ) V_7 ) ;
V_7 -> V_49 -> V_57 = NULL ;
F_41 ( V_7 ) ;
return 0 ;
}
void F_53 ( struct V_1 * V_7 )
{
if ( ! V_7 -> V_49 )
return;
F_54 ( & V_7 -> V_49 -> V_55 ) ;
F_54 ( & V_7 -> V_49 -> V_53 ) ;
F_55 ( V_7 -> V_49 ) ;
V_7 -> V_49 = NULL ;
}
void F_56 ( struct V_1 * V_7 )
{
unsigned char V_58 ;
if ( ! ( V_7 -> V_35 & V_47 ) )
return;
V_58 = F_57 ( & V_7 -> V_59 , 1 ) ;
if ( V_58 )
return;
F_46 ( V_7 -> V_14 . V_48 ) ;
}
void F_58 ( struct V_1 * V_7 )
{
unsigned char V_58 ;
if ( ! ( V_7 -> V_35 & V_47 ) )
return;
V_58 = F_57 ( & V_7 -> V_59 , 0 ) ;
if ( ! V_58 )
return;
F_48 ( V_7 -> V_14 . V_48 ) ;
F_49 ( V_7 -> V_14 . V_48 ) ;
}
static void F_59 ( struct V_1 * V_7 , int V_60 )
{
unsigned char V_61 = 0 , V_62 = 0 ;
F_45 ( V_7 ) ;
if ( ( V_7 -> V_14 . type == V_63 ) ||
( V_7 -> V_14 . type == V_64 ) ) {
F_4 ( V_7 , V_65 , V_60 ? 0xff : 0 ) ;
goto V_66;
}
if ( V_7 -> V_35 & V_67 ) {
if ( V_7 -> V_35 & V_68 ) {
V_61 = F_2 ( V_7 , V_29 ) ;
V_62 = F_2 ( V_7 , V_69 ) ;
F_4 ( V_7 , V_29 , V_70 ) ;
F_4 ( V_7 , V_69 , V_71 ) ;
F_4 ( V_7 , V_29 , 0 ) ;
}
F_4 ( V_7 , V_72 , V_60 ? V_73 : 0 ) ;
if ( V_7 -> V_35 & V_68 ) {
F_4 ( V_7 , V_29 , V_70 ) ;
F_4 ( V_7 , V_69 , V_62 ) ;
F_4 ( V_7 , V_29 , V_61 ) ;
}
}
V_66:
F_47 ( V_7 ) ;
}
static int F_60 ( struct V_1 * V_2 )
{
unsigned char V_74 ;
int V_75 ;
V_74 = F_2 ( V_2 , V_76 ) ;
V_75 = V_74 & V_77 ;
if ( ! V_75 ) {
F_4 ( V_2 , V_76 , V_74 | V_77 ) ;
V_74 = F_2 ( V_2 , V_76 ) ;
V_75 = V_74 & V_77 ;
}
if ( V_75 )
V_2 -> V_14 . V_78 = V_79 * 16 ;
return V_75 ;
}
static void F_61 ( struct V_1 * V_2 )
{
if ( V_2 -> V_14 . type == V_80 ) {
if ( V_2 -> V_14 . V_78 != V_79 * 16 ) {
F_62 ( & V_2 -> V_14 . V_81 ) ;
F_60 ( V_2 ) ;
F_63 ( & V_2 -> V_14 . V_81 ) ;
}
if ( V_2 -> V_14 . V_78 == V_79 * 16 )
F_4 ( V_2 , V_82 , 0 ) ;
}
}
static void F_64 ( struct V_1 * V_2 )
{
unsigned char V_74 ;
int V_75 ;
if ( V_2 -> V_14 . type == V_80 &&
V_2 -> V_14 . V_78 == V_79 * 16 ) {
F_62 ( & V_2 -> V_14 . V_81 ) ;
V_74 = F_2 ( V_2 , V_76 ) ;
V_75 = ! ( V_74 & V_77 ) ;
if ( ! V_75 ) {
F_4 ( V_2 , V_76 , V_74 & ~ V_77 ) ;
V_74 = F_2 ( V_2 , V_76 ) ;
V_75 = ! ( V_74 & V_77 ) ;
}
if ( V_75 )
V_2 -> V_14 . V_78 = V_83 * 16 ;
F_63 ( & V_2 -> V_14 . V_81 ) ;
}
}
static int F_65 ( struct V_1 * V_2 )
{
unsigned char V_84 , V_85 , V_86 ;
unsigned short V_87 ;
int V_88 ;
V_86 = F_2 ( V_2 , V_29 ) ;
F_4 ( V_2 , V_29 , 0 ) ;
V_84 = F_2 ( V_2 , V_37 ) ;
V_85 = F_42 ( V_2 ) ;
F_4 ( V_2 , V_37 , V_38 |
V_39 | V_40 ) ;
F_43 ( V_2 , V_89 ) ;
F_4 ( V_2 , V_29 , V_90 ) ;
V_87 = F_66 ( V_2 ) ;
F_67 ( V_2 , 0x0001 ) ;
F_4 ( V_2 , V_29 , 0x03 ) ;
for ( V_88 = 0 ; V_88 < 256 ; V_88 ++ )
F_4 ( V_2 , V_91 , V_88 ) ;
F_68 ( 20 ) ;
for ( V_88 = 0 ; ( F_2 ( V_2 , V_92 ) & V_93 ) &&
( V_88 < 256 ) ; V_88 ++ )
F_2 ( V_2 , V_94 ) ;
F_4 ( V_2 , V_37 , V_84 ) ;
F_43 ( V_2 , V_85 ) ;
F_4 ( V_2 , V_29 , V_90 ) ;
F_67 ( V_2 , V_87 ) ;
F_4 ( V_2 , V_29 , V_86 ) ;
return V_88 ;
}
static unsigned int F_69 ( struct V_1 * V_7 )
{
unsigned char V_86 ;
unsigned int V_95 , V_87 ;
V_86 = F_2 ( V_7 , V_29 ) ;
F_4 ( V_7 , V_29 , V_90 ) ;
V_87 = F_66 ( V_7 ) ;
F_67 ( V_7 , 0 ) ;
V_95 = F_66 ( V_7 ) ;
F_67 ( V_7 , V_87 ) ;
F_4 ( V_7 , V_29 , V_86 ) ;
return V_95 ;
}
static void F_70 ( struct V_1 * V_2 )
{
unsigned int V_96 , V_97 , V_98 , V_99 ;
V_2 -> V_35 |= V_68 | V_67 ;
V_2 -> V_33 = 0 ;
F_4 ( V_2 , V_29 , V_70 ) ;
F_4 ( V_2 , V_69 , V_71 ) ;
F_4 ( V_2 , V_29 , 0x00 ) ;
V_96 = F_39 ( V_2 , V_100 ) ;
V_97 = F_39 ( V_2 , V_101 ) ;
V_98 = F_39 ( V_2 , V_102 ) ;
V_99 = F_39 ( V_2 , V_103 ) ;
F_71 ( L_1 , V_96 , V_97 , V_98 , V_99 ) ;
if ( V_96 == 0x16 && V_97 == 0xC9 &&
( V_98 == 0x50 || V_98 == 0x52 || V_98 == 0x54 ) ) {
V_2 -> V_14 . type = V_104 ;
if ( V_98 == 0x52 && V_99 == 0x01 )
V_2 -> V_105 |= V_106 ;
return;
}
V_96 = F_69 ( V_2 ) ;
F_71 ( L_2 , V_96 ) ;
V_97 = V_96 >> 8 ;
if ( V_97 == 0x10 || V_97 == 0x12 || V_97 == 0x14 ) {
V_2 -> V_14 . type = V_107 ;
return;
}
if ( F_65 ( V_2 ) == 64 )
V_2 -> V_14 . type = V_108 ;
else
V_2 -> V_14 . type = V_109 ;
}
static void F_72 ( struct V_1 * V_2 )
{
unsigned char V_110 , V_111 , V_112 ;
V_2 -> V_14 . type = V_113 ;
V_110 = F_2 ( V_2 , V_30 ) ;
F_4 ( V_2 , V_30 , 0xa5 ) ;
V_111 = F_2 ( V_2 , V_30 ) ;
F_4 ( V_2 , V_30 , 0x5a ) ;
V_112 = F_2 ( V_2 , V_30 ) ;
F_4 ( V_2 , V_30 , V_110 ) ;
if ( V_111 == 0xa5 && V_112 == 0x5a )
V_2 -> V_14 . type = V_114 ;
}
static int F_73 ( struct V_1 * V_2 )
{
if ( F_69 ( V_2 ) == 0x0201 && F_65 ( V_2 ) == 16 )
return 1 ;
return 0 ;
}
static void F_74 ( struct V_1 * V_2 )
{
unsigned char V_111 , V_112 ;
unsigned int V_115 ;
V_2 -> V_14 . type = V_116 ;
V_2 -> V_35 |= V_36 ;
if ( V_2 -> V_14 . V_43 & V_117 ) {
V_111 = F_2 ( V_2 , V_118 ) ;
if ( V_111 == 0x82 || V_111 == 0x84 || V_111 == 0x88 ) {
F_71 ( L_3 ) ;
V_2 -> V_14 . type = V_63 ;
V_2 -> V_35 |= V_119 | V_68 |
V_67 ;
return;
}
}
F_4 ( V_2 , V_29 , V_90 ) ;
if ( F_2 ( V_2 , V_69 ) == 0 ) {
F_4 ( V_2 , V_69 , 0xA8 ) ;
if ( F_2 ( V_2 , V_69 ) != 0 ) {
F_71 ( L_4 ) ;
V_2 -> V_14 . type = V_120 ;
V_2 -> V_35 |= V_68 | V_67 ;
} else {
F_4 ( V_2 , V_29 , 0 ) ;
F_4 ( V_2 , V_37 , V_38 |
V_121 ) ;
V_111 = F_2 ( V_2 , V_122 ) >> 5 ;
F_4 ( V_2 , V_37 , 0 ) ;
F_4 ( V_2 , V_29 , 0 ) ;
if ( V_111 == 7 )
V_2 -> V_14 . type = V_123 ;
else
F_71 ( L_5 ) ;
}
F_4 ( V_2 , V_69 , 0 ) ;
return;
}
F_4 ( V_2 , V_29 , V_70 ) ;
if ( F_2 ( V_2 , V_69 ) == 0 && ! F_73 ( V_2 ) ) {
F_71 ( L_6 ) ;
F_70 ( V_2 ) ;
return;
}
F_4 ( V_2 , V_29 , 0 ) ;
V_111 = F_42 ( V_2 ) ;
F_4 ( V_2 , V_29 , 0xE0 ) ;
V_112 = F_2 ( V_2 , 0x02 ) ;
if ( ! ( ( V_112 ^ V_111 ) & V_89 ) ) {
F_4 ( V_2 , V_29 , 0 ) ;
F_43 ( V_2 , V_111 ^ V_89 ) ;
F_4 ( V_2 , V_29 , 0xE0 ) ;
V_112 = F_2 ( V_2 , 0x02 ) ;
F_4 ( V_2 , V_29 , 0 ) ;
F_43 ( V_2 , V_111 ) ;
if ( ( V_112 ^ V_111 ) & V_89 ) {
unsigned short V_124 ;
F_4 ( V_2 , V_29 , 0xE0 ) ;
V_124 = F_66 ( V_2 ) ;
V_124 <<= 3 ;
if ( F_75 ( V_2 ) )
F_67 ( V_2 , V_124 ) ;
F_4 ( V_2 , V_29 , 0 ) ;
V_2 -> V_14 . V_78 = 921600 * 16 ;
V_2 -> V_14 . type = V_125 ;
V_2 -> V_35 |= V_126 ;
return;
}
}
F_4 ( V_2 , V_29 , 0 ) ;
F_4 ( V_2 , V_37 , V_38 | V_121 ) ;
V_111 = F_2 ( V_2 , V_122 ) >> 5 ;
F_4 ( V_2 , V_37 , V_38 ) ;
F_4 ( V_2 , V_29 , V_90 ) ;
F_4 ( V_2 , V_37 , V_38 | V_121 ) ;
V_112 = F_2 ( V_2 , V_122 ) >> 5 ;
F_4 ( V_2 , V_37 , V_38 ) ;
F_4 ( V_2 , V_29 , 0 ) ;
F_71 ( L_7 , V_111 , V_112 ) ;
if ( V_111 == 6 && V_112 == 7 ) {
V_2 -> V_14 . type = V_127 ;
V_2 -> V_35 |= V_119 | V_67 ;
return;
}
V_115 = F_2 ( V_2 , V_72 ) ;
F_4 ( V_2 , V_72 , V_115 & ~ V_128 ) ;
if ( ! ( F_2 ( V_2 , V_72 ) & V_128 ) ) {
F_4 ( V_2 , V_72 , V_115 | V_128 ) ;
if ( F_2 ( V_2 , V_72 ) & V_128 ) {
F_71 ( L_8 ) ;
V_2 -> V_14 . type = V_129 ;
V_2 -> V_35 |= V_130 | V_131 ;
return;
}
} else {
F_71 ( L_9 ) ;
}
F_4 ( V_2 , V_72 , V_115 ) ;
if ( V_2 -> V_14 . V_43 & V_117 ) {
F_71 ( L_10 ) ;
V_2 -> V_14 . type = V_64 ;
V_2 -> V_35 |= V_119 | V_68 |
V_67 ;
return;
}
if ( V_2 -> V_14 . type == V_116 && F_65 ( V_2 ) == 64 ) {
V_2 -> V_14 . type = V_132 ;
V_2 -> V_35 |= V_119 ;
}
}
static void F_76 ( struct V_1 * V_2 )
{
unsigned char V_111 , V_110 , V_133 , V_134 ;
unsigned char V_135 , V_136 ;
struct V_6 * V_14 = & V_2 -> V_14 ;
unsigned long V_43 ;
unsigned int V_137 ;
if ( ! V_14 -> V_16 && ! V_14 -> V_138 && ! V_14 -> V_11 )
return;
F_71 ( L_11 ,
F_77 ( V_14 ) , V_14 -> V_16 , V_14 -> V_11 ) ;
F_78 ( & V_14 -> V_81 , V_43 ) ;
V_2 -> V_35 = 0 ;
V_2 -> V_105 = 0 ;
if ( ! ( V_14 -> V_43 & V_139 ) ) {
V_110 = F_2 ( V_2 , V_72 ) ;
F_4 ( V_2 , V_72 , 0 ) ;
#ifdef F_79
F_13 ( 0xff , 0x080 ) ;
#endif
V_133 = F_2 ( V_2 , V_72 ) & 0x0f ;
F_4 ( V_2 , V_72 , 0x0F ) ;
#ifdef F_79
F_13 ( 0 , 0x080 ) ;
#endif
V_134 = F_2 ( V_2 , V_72 ) & 0x0f ;
F_4 ( V_2 , V_72 , V_110 ) ;
if ( V_133 != 0 || V_134 != 0x0F ) {
F_80 ( & V_14 -> V_81 , V_43 ) ;
F_71 ( L_12 ,
V_133 , V_134 ) ;
goto V_66;
}
}
V_136 = F_42 ( V_2 ) ;
V_135 = F_2 ( V_2 , V_29 ) ;
if ( ! ( V_14 -> V_43 & V_140 ) ) {
F_43 ( V_2 , V_89 | 0x0A ) ;
V_111 = F_2 ( V_2 , V_141 ) & 0xF0 ;
F_43 ( V_2 , V_136 ) ;
if ( V_111 != 0x90 ) {
F_80 ( & V_14 -> V_81 , V_43 ) ;
F_71 ( L_13 ,
V_111 ) ;
goto V_66;
}
}
F_4 ( V_2 , V_29 , V_70 ) ;
F_4 ( V_2 , V_69 , 0 ) ;
F_4 ( V_2 , V_29 , 0 ) ;
F_4 ( V_2 , V_37 , V_38 ) ;
V_110 = F_2 ( V_2 , V_122 ) >> 6 ;
switch ( V_110 ) {
case 0 :
F_72 ( V_2 ) ;
break;
case 1 :
V_14 -> type = V_142 ;
break;
case 2 :
V_14 -> type = V_143 ;
break;
case 3 :
F_74 ( V_2 ) ;
break;
}
#ifdef F_81
if ( V_14 -> type == V_116 && V_2 -> V_144 & V_145 &&
F_60 ( V_2 ) )
V_14 -> type = V_80 ;
#endif
F_4 ( V_2 , V_29 , V_135 ) ;
V_14 -> V_146 = V_147 [ V_2 -> V_14 . type ] . V_148 ;
V_137 = V_2 -> V_35 ;
V_2 -> V_35 = V_147 [ V_14 -> type ] . V_43 ;
V_2 -> V_149 = V_147 [ V_14 -> type ] . V_149 ;
if ( V_14 -> type == V_142 )
goto V_150;
#ifdef F_81
if ( V_14 -> type == V_80 )
F_4 ( V_2 , V_82 , 0 ) ;
#endif
F_43 ( V_2 , V_136 ) ;
F_40 ( V_2 ) ;
F_2 ( V_2 , V_94 ) ;
if ( V_2 -> V_35 & V_130 )
F_4 ( V_2 , V_72 , V_128 ) ;
else
F_4 ( V_2 , V_72 , 0 ) ;
V_150:
F_80 ( & V_14 -> V_81 , V_43 ) ;
if ( V_14 -> type == V_116 )
F_82 ( V_2 ) ;
if ( V_2 -> V_35 != V_137 ) {
F_83 ( L_14 ,
F_77 ( V_14 ) , V_137 ,
V_2 -> V_35 ) ;
}
V_66:
F_71 ( L_15 , V_110 ) ;
F_71 ( L_16 , V_147 [ V_14 -> type ] . V_151 ) ;
}
static void F_84 ( struct V_1 * V_2 )
{
struct V_6 * V_14 = & V_2 -> V_14 ;
unsigned char V_136 , V_152 ;
unsigned char V_153 = 0 ;
unsigned int V_154 = 0 ;
unsigned long V_155 ;
int V_156 ;
if ( V_14 -> V_43 & V_157 ) {
V_154 = ( V_14 -> V_16 & 0xfe0 ) | 0x1f ;
V_153 = F_85 ( V_154 ) ;
F_86 ( 0x80 , V_154 ) ;
F_85 ( V_154 ) ;
}
if ( F_87 ( V_14 ) )
F_88 () ;
F_89 ( F_90 () ) ;
V_136 = F_42 ( V_2 ) ;
V_152 = F_2 ( V_2 , V_72 ) ;
F_43 ( V_2 , V_158 | V_159 ) ;
V_155 = F_90 () ;
F_43 ( V_2 , 0 ) ;
F_91 ( 10 ) ;
if ( V_14 -> V_43 & V_157 ) {
F_43 ( V_2 , V_160 | V_45 ) ;
} else {
F_43 ( V_2 ,
V_160 | V_45 | V_159 ) ;
}
F_4 ( V_2 , V_72 , 0x0f ) ;
F_2 ( V_2 , V_92 ) ;
F_2 ( V_2 , V_94 ) ;
F_2 ( V_2 , V_122 ) ;
F_2 ( V_2 , V_141 ) ;
F_4 ( V_2 , V_91 , 0xFF ) ;
F_91 ( 20 ) ;
V_156 = F_89 ( V_155 ) ;
F_43 ( V_2 , V_136 ) ;
F_4 ( V_2 , V_72 , V_152 ) ;
if ( V_14 -> V_43 & V_157 )
F_86 ( V_153 , V_154 ) ;
if ( F_87 ( V_14 ) )
F_92 () ;
V_14 -> V_156 = ( V_156 > 0 ) ? V_156 : 0 ;
}
static void F_93 ( struct V_6 * V_14 )
{
struct V_1 * V_2 = F_35 ( V_14 ) ;
F_45 ( V_2 ) ;
V_2 -> V_161 &= ~ ( V_162 | V_163 ) ;
V_2 -> V_14 . V_164 &= ~ V_93 ;
F_94 ( V_14 , V_72 , V_2 -> V_161 ) ;
F_47 ( V_2 ) ;
}
static void F_95 ( struct V_1 * V_7 )
{
F_41 ( V_7 ) ;
if ( ! ( V_7 -> V_14 . V_42 . V_43 & V_165 ) ) {
F_44 ( V_7 ) ;
V_7 -> V_161 |= V_162 | V_163 ;
F_94 ( & V_7 -> V_14 , V_72 , V_7 -> V_161 ) ;
}
}
static void V_54 ( unsigned long V_166 )
{
struct V_1 * V_7 = (struct V_1 * ) V_166 ;
struct V_50 * V_49 = V_7 -> V_49 ;
unsigned long V_43 ;
F_45 ( V_7 ) ;
F_78 ( & V_7 -> V_14 . V_81 , V_43 ) ;
if ( V_49 &&
V_49 -> V_57 == & V_49 -> V_53 ) {
F_95 ( V_7 ) ;
V_49 -> V_57 = NULL ;
}
F_80 ( & V_7 -> V_14 . V_81 , V_43 ) ;
F_47 ( V_7 ) ;
}
static void F_96 ( struct V_1 * V_7 )
{
struct V_50 * V_49 = V_7 -> V_49 ;
if ( V_7 -> V_14 . V_42 . V_167 > 0 ) {
V_49 -> V_57 = & V_49 -> V_53 ;
F_97 ( & V_49 -> V_53 , V_168 +
V_7 -> V_14 . V_42 . V_167 * V_169 / 1000 ) ;
} else {
F_95 ( V_7 ) ;
}
}
static inline void F_98 ( struct V_1 * V_7 )
{
if ( V_7 -> V_161 & V_170 ) {
V_7 -> V_161 &= ~ V_170 ;
F_4 ( V_7 , V_72 , V_7 -> V_161 ) ;
F_58 ( V_7 ) ;
}
}
static inline void F_99 ( struct V_1 * V_7 )
{
struct V_50 * V_49 = V_7 -> V_49 ;
if ( V_49 ) {
unsigned char V_171 = F_2 ( V_7 , V_92 ) ;
if ( ( V_171 & V_172 ) != V_172 )
return;
F_54 ( & V_49 -> V_55 ) ;
V_49 -> V_57 = NULL ;
F_96 ( V_7 ) ;
}
F_98 ( V_7 ) ;
}
static void F_100 ( struct V_6 * V_14 )
{
struct V_1 * V_2 = F_35 ( V_14 ) ;
F_45 ( V_2 ) ;
F_99 ( V_2 ) ;
if ( V_14 -> type == V_104 ) {
V_2 -> V_33 |= V_173 ;
F_38 ( V_2 , V_32 , V_2 -> V_33 ) ;
}
F_47 ( V_2 ) ;
}
static inline void F_101 ( struct V_6 * V_14 )
{
struct V_1 * V_2 = F_35 ( V_14 ) ;
if ( V_2 -> V_174 && ! V_2 -> V_174 -> V_175 ( V_2 ) )
return;
if ( ! ( V_2 -> V_161 & V_170 ) ) {
V_2 -> V_161 |= V_170 ;
F_94 ( V_14 , V_72 , V_2 -> V_161 ) ;
if ( V_2 -> V_105 & V_176 ) {
unsigned char V_171 ;
V_171 = F_2 ( V_2 , V_92 ) ;
V_2 -> V_177 |= V_171 & V_178 ;
if ( V_171 & V_179 )
F_102 ( V_2 ) ;
}
}
if ( V_14 -> type == V_104 && V_2 -> V_33 & V_173 ) {
V_2 -> V_33 &= ~ V_173 ;
F_38 ( V_2 , V_32 , V_2 -> V_33 ) ;
}
}
static inline void F_103 ( struct V_6 * V_14 )
{
struct V_1 * V_2 = F_35 ( V_14 ) ;
struct V_50 * V_49 = V_2 -> V_49 ;
unsigned char V_41 ;
if ( ! ( V_2 -> V_14 . V_42 . V_43 & V_165 ) )
F_93 ( & V_2 -> V_14 ) ;
F_54 ( & V_49 -> V_53 ) ;
V_49 -> V_57 = NULL ;
V_41 = F_42 ( V_2 ) ;
if ( ! ! ( V_2 -> V_14 . V_42 . V_43 & V_180 ) !=
! ! ( V_41 & V_45 ) ) {
if ( V_2 -> V_14 . V_42 . V_43 & V_180 )
V_41 |= V_45 ;
else
V_41 &= ~ V_45 ;
F_43 ( V_2 , V_41 ) ;
if ( V_2 -> V_14 . V_42 . V_181 > 0 ) {
V_49 -> V_57 = & V_49 -> V_55 ;
F_97 ( & V_49 -> V_55 , V_168 +
V_2 -> V_14 . V_42 . V_181 * V_169 / 1000 ) ;
return;
}
}
F_101 ( V_14 ) ;
}
static void V_56 ( unsigned long V_166 )
{
struct V_1 * V_7 = (struct V_1 * ) V_166 ;
struct V_50 * V_49 = V_7 -> V_49 ;
unsigned long V_43 ;
F_78 ( & V_7 -> V_14 . V_81 , V_43 ) ;
if ( V_49 &&
V_49 -> V_57 == & V_49 -> V_55 ) {
F_101 ( & V_7 -> V_14 ) ;
V_49 -> V_57 = NULL ;
}
F_80 ( & V_7 -> V_14 . V_81 , V_43 ) ;
}
static void F_104 ( struct V_6 * V_14 )
{
struct V_1 * V_2 = F_35 ( V_14 ) ;
struct V_50 * V_49 = V_2 -> V_49 ;
F_56 ( V_2 ) ;
if ( V_49 &&
V_49 -> V_57 == & V_49 -> V_55 )
return;
if ( V_49 )
F_103 ( V_14 ) ;
else
F_101 ( V_14 ) ;
}
static void F_105 ( struct V_6 * V_14 )
{
V_14 -> V_182 ( V_14 ) ;
}
static void F_106 ( struct V_6 * V_14 )
{
V_14 -> V_183 ( V_14 ) ;
}
static void F_107 ( struct V_6 * V_14 )
{
struct V_1 * V_2 = F_35 ( V_14 ) ;
if ( V_2 -> V_105 & V_184 )
return;
V_2 -> V_161 &= ~ V_185 ;
F_94 ( V_14 , V_72 , V_2 -> V_161 ) ;
}
static void F_108 ( struct V_6 * V_14 )
{
struct V_1 * V_2 = F_35 ( V_14 ) ;
if ( V_2 -> V_105 & V_184 )
return;
V_2 -> V_161 |= V_185 ;
F_45 ( V_2 ) ;
F_94 ( V_14 , V_72 , V_2 -> V_161 ) ;
F_47 ( V_2 ) ;
}
static void F_109 ( struct V_1 * V_2 , unsigned char V_171 )
{
struct V_6 * V_14 = & V_2 -> V_14 ;
unsigned char V_186 ;
char V_187 = V_188 ;
if ( F_110 ( V_171 & V_93 ) )
V_186 = F_2 ( V_2 , V_94 ) ;
else
V_186 = 0 ;
V_14 -> V_189 . V_190 ++ ;
V_171 |= V_2 -> V_177 ;
V_2 -> V_177 = 0 ;
if ( F_111 ( V_171 & V_191 ) ) {
if ( V_171 & V_192 ) {
V_171 &= ~ ( V_193 | V_194 ) ;
V_14 -> V_189 . V_195 ++ ;
if ( F_112 ( V_14 ) )
return;
} else if ( V_171 & V_194 )
V_14 -> V_189 . V_196 ++ ;
else if ( V_171 & V_193 )
V_14 -> V_189 . V_197 ++ ;
if ( V_171 & V_198 )
V_14 -> V_189 . V_199 ++ ;
V_171 &= V_14 -> V_164 ;
if ( V_171 & V_192 ) {
F_113 ( L_17 , V_200 ) ;
V_187 = V_201 ;
} else if ( V_171 & V_194 )
V_187 = V_202 ;
else if ( V_171 & V_193 )
V_187 = V_203 ;
}
if ( F_114 ( V_14 , V_186 ) )
return;
F_115 ( V_14 , V_171 , V_198 , V_186 , V_187 ) ;
}
unsigned char F_116 ( struct V_1 * V_2 , unsigned char V_171 )
{
struct V_6 * V_14 = & V_2 -> V_14 ;
int V_204 = 256 ;
do {
F_109 ( V_2 , V_171 ) ;
if ( -- V_204 == 0 )
break;
V_171 = F_2 ( V_2 , V_92 ) ;
} while ( V_171 & ( V_93 | V_192 ) );
F_117 ( & V_14 -> V_205 -> V_14 ) ;
return V_171 ;
}
void F_102 ( struct V_1 * V_2 )
{
struct V_6 * V_14 = & V_2 -> V_14 ;
struct V_206 * V_207 = & V_14 -> V_205 -> V_207 ;
int V_88 ;
if ( V_14 -> V_208 ) {
F_4 ( V_2 , V_91 , V_14 -> V_208 ) ;
V_14 -> V_189 . V_209 ++ ;
V_14 -> V_208 = 0 ;
return;
}
if ( F_118 ( V_14 ) ) {
F_100 ( V_14 ) ;
return;
}
if ( F_119 ( V_207 ) ) {
F_99 ( V_2 ) ;
return;
}
V_88 = V_2 -> V_149 ;
do {
F_4 ( V_2 , V_91 , V_207 -> V_210 [ V_207 -> V_211 ] ) ;
V_207 -> V_211 = ( V_207 -> V_211 + 1 ) & ( V_212 - 1 ) ;
V_14 -> V_189 . V_209 ++ ;
if ( F_119 ( V_207 ) )
break;
if ( ( V_2 -> V_35 & V_213 ) &&
( F_2 ( V_2 , V_92 ) & V_172 ) != V_172 )
break;
} while ( -- V_88 > 0 );
if ( F_120 ( V_207 ) < V_214 )
F_121 ( V_14 ) ;
F_113 ( L_18 , V_200 ) ;
if ( F_119 ( V_207 ) && ! ( V_2 -> V_35 & V_47 ) )
F_99 ( V_2 ) ;
}
unsigned int F_122 ( struct V_1 * V_2 )
{
struct V_6 * V_14 = & V_2 -> V_14 ;
unsigned int V_215 = F_2 ( V_2 , V_141 ) ;
V_215 |= V_2 -> V_216 ;
V_2 -> V_216 = 0 ;
if ( V_215 & V_217 && V_2 -> V_161 & V_185 &&
V_14 -> V_205 != NULL ) {
if ( V_215 & V_218 )
V_14 -> V_189 . V_219 ++ ;
if ( V_215 & V_220 )
V_14 -> V_189 . V_221 ++ ;
if ( V_215 & V_222 )
F_123 ( V_14 , V_215 & V_223 ) ;
if ( V_215 & V_224 )
F_124 ( V_14 , V_215 & V_225 ) ;
F_125 ( & V_14 -> V_205 -> V_14 . V_226 ) ;
}
return V_215 ;
}
static bool F_126 ( struct V_1 * V_2 , unsigned int V_227 )
{
switch ( V_227 & 0x3f ) {
case V_228 :
F_127 ( V_2 ) ;
case V_229 :
return true ;
}
return V_2 -> V_174 -> V_230 ( V_2 ) ;
}
int F_128 ( struct V_6 * V_14 , unsigned int V_227 )
{
unsigned char V_215 ;
unsigned long V_43 ;
struct V_1 * V_2 = F_35 ( V_14 ) ;
if ( V_227 & V_231 )
return 0 ;
F_78 ( & V_14 -> V_81 , V_43 ) ;
V_215 = F_129 ( V_14 , V_92 ) ;
F_113 ( L_19 , V_200 , V_215 ) ;
if ( V_215 & ( V_93 | V_192 ) ) {
if ( ! V_2 -> V_174 || F_126 ( V_2 , V_227 ) )
V_215 = F_116 ( V_2 , V_215 ) ;
}
F_122 ( V_2 ) ;
if ( ( ! V_2 -> V_174 || V_2 -> V_174 -> V_232 ) && ( V_215 & V_179 ) )
F_102 ( V_2 ) ;
F_80 ( & V_14 -> V_81 , V_43 ) ;
return 1 ;
}
static int V_28 ( struct V_6 * V_14 )
{
struct V_1 * V_2 = F_35 ( V_14 ) ;
unsigned int V_227 ;
int V_233 ;
F_45 ( V_2 ) ;
V_227 = F_129 ( V_14 , V_122 ) ;
V_233 = F_128 ( V_14 , V_227 ) ;
F_47 ( V_2 ) ;
return V_233 ;
}
static int F_130 ( struct V_6 * V_14 )
{
unsigned int V_227 = F_129 ( V_14 , V_122 ) ;
int V_233 ;
V_233 = F_128 ( V_14 , V_227 ) ;
if ( ( V_14 -> type == V_63 ) ||
( V_14 -> type == V_64 ) ) {
F_129 ( V_14 , 0x80 ) ;
F_129 ( V_14 , 0x81 ) ;
F_129 ( V_14 , 0x82 ) ;
F_129 ( V_14 , 0x83 ) ;
}
return V_233 ;
}
static int F_131 ( struct V_6 * V_14 )
{
unsigned long V_43 ;
unsigned int V_227 = F_129 ( V_14 , V_122 ) ;
if ( ( V_227 & V_234 ) == V_235 ) {
struct V_1 * V_2 = F_35 ( V_14 ) ;
F_78 ( & V_14 -> V_81 , V_43 ) ;
F_102 ( V_2 ) ;
F_80 ( & V_14 -> V_81 , V_43 ) ;
}
V_227 = F_129 ( V_14 , V_122 ) ;
return F_128 ( V_14 , V_227 ) ;
}
static unsigned int F_132 ( struct V_6 * V_14 )
{
struct V_1 * V_2 = F_35 ( V_14 ) ;
unsigned long V_43 ;
unsigned int V_171 ;
F_45 ( V_2 ) ;
F_78 ( & V_14 -> V_81 , V_43 ) ;
V_171 = F_129 ( V_14 , V_92 ) ;
V_2 -> V_177 |= V_171 & V_178 ;
F_80 ( & V_14 -> V_81 , V_43 ) ;
F_47 ( V_2 ) ;
return ( V_171 & V_172 ) == V_172 ? V_236 : 0 ;
}
unsigned int F_133 ( struct V_6 * V_14 )
{
struct V_1 * V_2 = F_35 ( V_14 ) ;
unsigned int V_215 ;
unsigned int V_233 ;
F_45 ( V_2 ) ;
V_215 = F_122 ( V_2 ) ;
F_47 ( V_2 ) ;
V_233 = 0 ;
if ( V_215 & V_223 )
V_233 |= V_237 ;
if ( V_215 & V_238 )
V_233 |= V_239 ;
if ( V_215 & V_240 )
V_233 |= V_241 ;
if ( V_215 & V_225 )
V_233 |= V_242 ;
return V_233 ;
}
static unsigned int F_134 ( struct V_6 * V_14 )
{
if ( V_14 -> V_243 )
return V_14 -> V_243 ( V_14 ) ;
return F_133 ( V_14 ) ;
}
void F_135 ( struct V_6 * V_14 , unsigned int V_244 )
{
struct V_1 * V_2 = F_35 ( V_14 ) ;
unsigned char V_41 = 0 ;
if ( V_244 & V_245 )
V_41 |= V_45 ;
if ( V_244 & V_246 )
V_41 |= V_160 ;
if ( V_244 & V_247 )
V_41 |= V_158 ;
if ( V_244 & V_248 )
V_41 |= V_159 ;
if ( V_244 & V_249 )
V_41 |= V_89 ;
V_41 = ( V_41 & V_2 -> V_250 ) | V_2 -> V_251 | V_2 -> V_41 ;
F_43 ( V_2 , V_41 ) ;
}
static void F_136 ( struct V_6 * V_14 , unsigned int V_244 )
{
if ( V_14 -> V_252 )
V_14 -> V_252 ( V_14 , V_244 ) ;
else
F_135 ( V_14 , V_244 ) ;
}
static void F_137 ( struct V_6 * V_14 , int V_253 )
{
struct V_1 * V_2 = F_35 ( V_14 ) ;
unsigned long V_43 ;
F_45 ( V_2 ) ;
F_78 ( & V_14 -> V_81 , V_43 ) ;
if ( V_253 == - 1 )
V_2 -> V_61 |= V_254 ;
else
V_2 -> V_61 &= ~ V_254 ;
F_94 ( V_14 , V_29 , V_2 -> V_61 ) ;
F_80 ( & V_14 -> V_81 , V_43 ) ;
F_47 ( V_2 ) ;
}
static void F_138 ( struct V_1 * V_2 , int V_255 )
{
unsigned int V_215 , V_256 = 10000 ;
for (; ; ) {
V_215 = F_2 ( V_2 , V_92 ) ;
V_2 -> V_177 |= V_215 & V_178 ;
if ( ( V_215 & V_255 ) == V_255 )
break;
if ( -- V_256 == 0 )
break;
F_91 ( 1 ) ;
F_139 () ;
}
if ( V_2 -> V_14 . V_43 & V_257 ) {
for ( V_256 = 1000000 ; V_256 ; V_256 -- ) {
unsigned int V_258 = F_2 ( V_2 , V_141 ) ;
V_2 -> V_216 |= V_258 & V_259 ;
if ( V_258 & V_225 )
break;
F_91 ( 1 ) ;
F_139 () ;
}
}
}
static int F_140 ( struct V_6 * V_14 )
{
struct V_1 * V_2 = F_35 ( V_14 ) ;
unsigned char V_171 ;
int V_215 ;
F_45 ( V_2 ) ;
V_171 = F_129 ( V_14 , V_92 ) ;
if ( ! ( V_171 & V_93 ) ) {
V_215 = V_260 ;
goto V_66;
}
V_215 = F_129 ( V_14 , V_94 ) ;
V_66:
F_47 ( V_2 ) ;
return V_215 ;
}
static void F_141 ( struct V_6 * V_14 ,
unsigned char V_261 )
{
unsigned int V_161 ;
struct V_1 * V_2 = F_35 ( V_14 ) ;
F_45 ( V_2 ) ;
V_161 = F_129 ( V_14 , V_72 ) ;
if ( V_2 -> V_35 & V_130 )
F_94 ( V_14 , V_72 , V_128 ) ;
else
F_94 ( V_14 , V_72 , 0 ) ;
F_138 ( V_2 , V_172 ) ;
F_94 ( V_14 , V_91 , V_261 ) ;
F_138 ( V_2 , V_172 ) ;
F_94 ( V_14 , V_72 , V_161 ) ;
F_47 ( V_2 ) ;
}
int F_142 ( struct V_6 * V_14 )
{
struct V_1 * V_2 = F_35 ( V_14 ) ;
unsigned long V_43 ;
unsigned char V_171 , V_227 ;
int V_262 ;
if ( ! V_14 -> V_146 )
V_14 -> V_146 = V_147 [ V_14 -> type ] . V_148 ;
if ( ! V_2 -> V_149 )
V_2 -> V_149 = V_147 [ V_14 -> type ] . V_149 ;
if ( ! V_2 -> V_35 )
V_2 -> V_35 = V_147 [ V_14 -> type ] . V_43 ;
V_2 -> V_41 = 0 ;
if ( V_14 -> V_19 != V_2 -> V_26 )
F_34 ( V_14 ) ;
F_45 ( V_2 ) ;
if ( V_14 -> type == V_104 ) {
V_2 -> V_33 = 0 ;
F_94 ( V_14 , V_29 , V_70 ) ;
F_94 ( V_14 , V_69 , V_71 ) ;
F_94 ( V_14 , V_72 , 0 ) ;
F_94 ( V_14 , V_29 , 0 ) ;
F_38 ( V_2 , V_263 , 0 ) ;
F_94 ( V_14 , V_29 , V_70 ) ;
F_94 ( V_14 , V_69 , V_71 ) ;
F_94 ( V_14 , V_29 , 0 ) ;
}
#ifdef F_81
F_61 ( V_2 ) ;
#endif
if ( V_14 -> type == V_63 ) {
F_94 ( V_14 , V_264 , V_71 ) ;
F_94 ( V_14 , V_72 , 0 ) ;
}
F_40 ( V_2 ) ;
F_129 ( V_14 , V_92 ) ;
F_129 ( V_14 , V_94 ) ;
F_129 ( V_14 , V_122 ) ;
F_129 ( V_14 , V_141 ) ;
if ( ! ( V_14 -> V_43 & V_139 ) &&
( F_129 ( V_14 , V_92 ) == 0xff ) ) {
F_143 ( V_265 L_20 ,
F_77 ( V_14 ) ) ;
V_262 = - V_266 ;
goto V_66;
}
if ( V_14 -> type == V_107 ) {
unsigned char V_267 ;
F_4 ( V_2 , V_29 , V_70 ) ;
V_267 = F_2 ( V_2 , V_268 ) & ~ ( V_269 | V_270 ) ;
F_94 ( V_14 , V_268 ,
V_267 | V_271 | V_269 ) ;
F_94 ( V_14 , V_272 , V_273 ) ;
F_94 ( V_14 , V_268 ,
V_267 | V_271 | V_270 ) ;
F_94 ( V_14 , V_272 , V_273 ) ;
F_94 ( V_14 , V_29 , 0 ) ;
}
if ( ( ( V_14 -> type == V_274 ) ||
( V_14 -> type == V_275 ) ||
( V_14 -> type == V_276 ) ) && ( V_14 -> V_146 > 1 ) ) {
if ( ( V_2 -> V_149 < 2 ) || ( V_2 -> V_149 > V_14 -> V_146 ) ) {
F_144 ( L_21 ,
F_77 ( V_14 ) ) ;
} else {
F_94 ( V_14 , V_277 ,
V_278 ) ;
F_94 ( V_14 , V_279 ,
V_14 -> V_146 - V_2 -> V_149 ) ;
V_14 -> V_27 = F_131 ;
}
}
if ( V_14 -> V_156 ) {
unsigned char V_280 ;
F_78 ( & V_14 -> V_81 , V_43 ) ;
if ( V_2 -> V_14 . V_281 & V_282 )
F_145 ( V_14 -> V_156 ) ;
F_138 ( V_2 , V_179 ) ;
F_37 ( V_14 , V_72 , V_170 ) ;
F_91 ( 1 ) ;
V_280 = F_129 ( V_14 , V_122 ) ;
F_94 ( V_14 , V_72 , 0 ) ;
F_37 ( V_14 , V_72 , V_170 ) ;
F_91 ( 1 ) ;
V_227 = F_129 ( V_14 , V_122 ) ;
F_94 ( V_14 , V_72 , 0 ) ;
if ( V_14 -> V_281 & V_282 )
F_146 ( V_14 -> V_156 ) ;
F_80 ( & V_14 -> V_81 , V_43 ) ;
if ( ( ! ( V_280 & V_231 ) && ( V_227 & V_231 ) ) ||
V_2 -> V_14 . V_43 & V_283 ) {
V_2 -> V_105 |= V_284 ;
}
}
V_262 = V_2 -> V_285 -> V_286 ( V_2 ) ;
if ( V_262 )
goto V_66;
F_94 ( V_14 , V_29 , V_287 ) ;
F_78 ( & V_14 -> V_81 , V_43 ) ;
if ( V_2 -> V_14 . V_43 & V_157 ) {
if ( ! V_2 -> V_14 . V_156 )
V_2 -> V_14 . V_244 |= V_247 ;
} else
if ( V_14 -> V_156 )
V_2 -> V_14 . V_244 |= V_248 ;
F_136 ( V_14 , V_14 -> V_244 ) ;
if ( V_2 -> V_14 . V_43 & V_288 )
goto V_289;
F_94 ( V_14 , V_72 , V_170 ) ;
V_171 = F_129 ( V_14 , V_92 ) ;
V_227 = F_129 ( V_14 , V_122 ) ;
F_94 ( V_14 , V_72 , 0 ) ;
if ( V_171 & V_290 && V_227 & V_231 ) {
if ( ! ( V_2 -> V_105 & V_176 ) ) {
V_2 -> V_105 |= V_176 ;
F_113 ( L_22 ,
F_77 ( V_14 ) ) ;
}
} else {
V_2 -> V_105 &= ~ V_176 ;
}
V_289:
F_80 ( & V_14 -> V_81 , V_43 ) ;
F_129 ( V_14 , V_92 ) ;
F_129 ( V_14 , V_94 ) ;
F_129 ( V_14 , V_122 ) ;
F_129 ( V_14 , V_141 ) ;
V_2 -> V_177 = 0 ;
V_2 -> V_216 = 0 ;
if ( V_2 -> V_174 ) {
V_262 = F_147 ( V_2 ) ;
if ( V_262 ) {
F_148 ( L_23 ,
F_77 ( V_14 ) ) ;
V_2 -> V_174 = NULL ;
}
}
V_2 -> V_161 = V_162 | V_163 ;
if ( V_14 -> V_43 & V_157 ) {
unsigned int V_291 ;
V_291 = ( V_14 -> V_16 & 0xfe0 ) | 0x01f ;
F_86 ( 0x80 , V_291 ) ;
F_85 ( V_291 ) ;
}
V_262 = 0 ;
V_66:
F_47 ( V_2 ) ;
return V_262 ;
}
static int F_149 ( struct V_6 * V_14 )
{
if ( V_14 -> V_292 )
return V_14 -> V_292 ( V_14 ) ;
return F_142 ( V_14 ) ;
}
void F_150 ( struct V_6 * V_14 )
{
struct V_1 * V_2 = F_35 ( V_14 ) ;
unsigned long V_43 ;
F_45 ( V_2 ) ;
F_78 ( & V_14 -> V_81 , V_43 ) ;
V_2 -> V_161 = 0 ;
F_94 ( V_14 , V_72 , 0 ) ;
F_80 ( & V_14 -> V_81 , V_43 ) ;
F_151 ( V_14 -> V_156 ) ;
if ( V_2 -> V_174 )
F_152 ( V_2 ) ;
F_78 ( & V_14 -> V_81 , V_43 ) ;
if ( V_14 -> V_43 & V_157 ) {
F_14 ( ( V_14 -> V_16 & 0xfe0 ) | 0x1f ) ;
V_14 -> V_244 |= V_247 ;
} else
V_14 -> V_244 &= ~ V_248 ;
F_136 ( V_14 , V_14 -> V_244 ) ;
F_80 ( & V_14 -> V_81 , V_43 ) ;
F_94 ( V_14 , V_29 ,
F_129 ( V_14 , V_29 ) & ~ V_254 ) ;
F_40 ( V_2 ) ;
#ifdef F_81
F_64 ( V_2 ) ;
#endif
F_129 ( V_14 , V_94 ) ;
F_47 ( V_2 ) ;
V_2 -> V_285 -> V_293 ( V_2 ) ;
}
static void F_153 ( struct V_6 * V_14 )
{
if ( V_14 -> V_294 )
V_14 -> V_294 ( V_14 ) ;
else
F_150 ( V_14 ) ;
}
static unsigned int F_154 ( struct V_1 * V_2 ,
unsigned int V_295 ,
unsigned int * V_296 )
{
struct V_6 * V_14 = & V_2 -> V_14 ;
unsigned int V_297 ;
V_297 = F_155 ( V_14 -> V_78 , V_295 ) ;
* V_296 = V_297 & 0x0f ;
return V_297 >> 4 ;
}
static unsigned int F_156 ( struct V_1 * V_2 ,
unsigned int V_295 ,
unsigned int * V_296 )
{
struct V_6 * V_14 = & V_2 -> V_14 ;
unsigned int V_124 ;
if ( ( V_14 -> V_43 & V_298 ) &&
V_295 == ( V_14 -> V_78 / 4 ) )
V_124 = 0x8001 ;
else if ( ( V_14 -> V_43 & V_298 ) &&
V_295 == ( V_14 -> V_78 / 8 ) )
V_124 = 0x8002 ;
else if ( V_2 -> V_14 . type == V_63 )
V_124 = F_154 ( V_2 , V_295 , V_296 ) ;
else
V_124 = F_157 ( V_14 , V_295 ) ;
if ( V_2 -> V_105 & V_106 && ( V_124 & 0xff ) == 0 )
V_124 ++ ;
return V_124 ;
}
static unsigned char F_158 ( struct V_1 * V_2 ,
T_1 V_299 )
{
unsigned char V_300 ;
switch ( V_299 & V_301 ) {
case V_302 :
V_300 = V_303 ;
break;
case V_304 :
V_300 = V_305 ;
break;
case V_306 :
V_300 = V_307 ;
break;
default:
case V_308 :
V_300 = V_287 ;
break;
}
if ( V_299 & V_309 )
V_300 |= V_310 ;
if ( V_299 & V_311 ) {
V_300 |= V_312 ;
if ( V_2 -> V_105 & V_313 )
V_2 -> V_314 = true ;
}
if ( ! ( V_299 & V_315 ) )
V_300 |= V_316 ;
#ifdef F_159
if ( V_299 & F_159 )
V_300 |= V_317 ;
#endif
return V_300 ;
}
static void F_160 ( struct V_6 * V_14 , unsigned int V_295 ,
unsigned int V_124 , unsigned int V_318 )
{
struct V_1 * V_2 = F_35 ( V_14 ) ;
if ( F_161 ( V_2 ) ) {
if ( V_295 == 115200 ) {
V_124 = 1 ;
F_94 ( V_14 , V_319 , 1 ) ;
} else
F_94 ( V_14 , V_319 , 0 ) ;
}
if ( V_2 -> V_35 & V_126 )
F_94 ( V_14 , V_29 , 0xe0 ) ;
else
F_94 ( V_14 , V_29 , V_2 -> V_61 | V_320 ) ;
F_67 ( V_2 , V_124 ) ;
if ( V_2 -> V_14 . type == V_63 )
F_94 ( V_14 , 0x2 , V_318 ) ;
}
static unsigned int F_162 ( struct V_6 * V_14 ,
struct V_321 * V_322 ,
struct V_321 * V_323 )
{
return F_163 ( V_14 , V_322 , V_323 ,
V_14 -> V_78 / 16 / 0xffff ,
V_14 -> V_78 ) ;
}
void
F_164 ( struct V_6 * V_14 , struct V_321 * V_322 ,
struct V_321 * V_323 )
{
struct V_1 * V_2 = F_35 ( V_14 ) ;
unsigned char V_300 ;
unsigned long V_43 ;
unsigned int V_295 , V_124 , V_296 = 0 ;
V_300 = F_158 ( V_2 , V_322 -> V_299 ) ;
V_295 = F_162 ( V_14 , V_322 , V_323 ) ;
V_124 = F_156 ( V_2 , V_295 , & V_296 ) ;
F_45 ( V_2 ) ;
F_78 ( & V_14 -> V_81 , V_43 ) ;
V_2 -> V_61 = V_300 ;
if ( V_2 -> V_35 & V_36 && V_14 -> V_146 > 1 ) {
if ( ( V_295 < 2400 && ! V_2 -> V_174 ) || V_2 -> V_314 ) {
V_2 -> V_46 &= ~ V_324 ;
V_2 -> V_46 |= V_325 ;
}
}
if ( V_2 -> V_35 & V_119 ) {
V_2 -> V_41 &= ~ V_326 ;
if ( V_322 -> V_299 & V_327 )
V_2 -> V_41 |= V_326 ;
}
F_165 ( V_14 , V_322 -> V_299 , V_295 ) ;
V_14 -> V_164 = V_198 | V_179 | V_93 ;
if ( V_322 -> V_328 & V_329 )
V_14 -> V_164 |= V_193 | V_194 ;
if ( V_322 -> V_328 & ( V_330 | V_331 | V_332 ) )
V_14 -> V_164 |= V_192 ;
V_14 -> V_333 = 0 ;
if ( V_322 -> V_328 & V_334 )
V_14 -> V_333 |= V_194 | V_193 ;
if ( V_322 -> V_328 & V_330 ) {
V_14 -> V_333 |= V_192 ;
if ( V_322 -> V_328 & V_334 )
V_14 -> V_333 |= V_198 ;
}
if ( ( V_322 -> V_299 & V_335 ) == 0 )
V_14 -> V_333 |= V_93 ;
V_2 -> V_161 &= ~ V_185 ;
if ( ! ( V_2 -> V_105 & V_184 ) &&
F_166 ( & V_2 -> V_14 , V_322 -> V_299 ) )
V_2 -> V_161 |= V_185 ;
if ( V_2 -> V_35 & V_130 )
V_2 -> V_161 |= V_128 ;
if ( V_2 -> V_35 & V_131 )
V_2 -> V_161 |= V_336 ;
F_94 ( V_14 , V_72 , V_2 -> V_161 ) ;
if ( V_2 -> V_35 & V_68 ) {
unsigned char V_62 = 0 ;
if ( V_322 -> V_299 & V_327 )
V_62 |= V_337 ;
F_94 ( V_14 , V_29 , V_70 ) ;
if ( V_14 -> V_43 & V_117 )
F_94 ( V_14 , V_264 , V_62 ) ;
else
F_94 ( V_14 , V_69 , V_62 ) ;
}
F_160 ( V_14 , V_295 , V_124 , V_296 ) ;
if ( V_14 -> type == V_127 )
F_94 ( V_14 , V_37 , V_2 -> V_46 ) ;
F_94 ( V_14 , V_29 , V_2 -> V_61 ) ;
if ( V_14 -> type != V_127 ) {
if ( V_2 -> V_46 & V_38 )
F_94 ( V_14 , V_37 , V_38 ) ;
F_94 ( V_14 , V_37 , V_2 -> V_46 ) ;
}
F_136 ( V_14 , V_14 -> V_244 ) ;
F_80 ( & V_14 -> V_81 , V_43 ) ;
F_47 ( V_2 ) ;
if ( F_167 ( V_322 ) )
F_168 ( V_322 , V_295 , V_295 ) ;
}
static void
F_169 ( struct V_6 * V_14 , struct V_321 * V_322 ,
struct V_321 * V_323 )
{
if ( V_14 -> V_338 )
V_14 -> V_338 ( V_14 , V_322 , V_323 ) ;
else
F_164 ( V_14 , V_322 , V_323 ) ;
}
void F_170 ( struct V_6 * V_14 , struct V_321 * V_322 )
{
if ( V_322 -> V_339 == V_340 ) {
V_14 -> V_43 |= V_341 ;
F_62 ( & V_14 -> V_81 ) ;
F_108 ( V_14 ) ;
F_63 ( & V_14 -> V_81 ) ;
} else {
V_14 -> V_43 &= ~ V_341 ;
if ( ! F_166 ( V_14 , V_322 -> V_299 ) ) {
F_62 ( & V_14 -> V_81 ) ;
F_107 ( V_14 ) ;
F_63 ( & V_14 -> V_81 ) ;
}
}
}
static void
F_171 ( struct V_6 * V_14 , struct V_321 * V_322 )
{
if ( V_14 -> V_342 )
V_14 -> V_342 ( V_14 , V_322 ) ;
else
F_170 ( V_14 , V_322 ) ;
}
void F_172 ( struct V_6 * V_14 , unsigned int V_205 ,
unsigned int V_343 )
{
struct V_1 * V_7 = F_35 ( V_14 ) ;
F_59 ( V_7 , V_205 != 0 ) ;
}
static void
F_173 ( struct V_6 * V_14 , unsigned int V_205 ,
unsigned int V_343 )
{
if ( V_14 -> V_344 )
V_14 -> V_344 ( V_14 , V_205 , V_343 ) ;
else
F_172 ( V_14 , V_205 , V_343 ) ;
}
static unsigned int F_174 ( struct V_1 * V_345 )
{
if ( V_345 -> V_14 . V_346 )
return V_345 -> V_14 . V_346 ;
if ( V_345 -> V_14 . V_19 == V_25 ) {
if ( V_345 -> V_14 . type == V_347 )
return 0x100 ;
return 0x1000 ;
}
if ( F_175 ( V_345 ) )
return 0x16 << V_345 -> V_14 . V_12 ;
return 8 << V_345 -> V_14 . V_12 ;
}
static int F_176 ( struct V_1 * V_2 )
{
unsigned int V_348 = F_174 ( V_2 ) ;
struct V_6 * V_14 = & V_2 -> V_14 ;
int V_233 = 0 ;
switch ( V_14 -> V_19 ) {
case V_25 :
case V_349 :
case V_23 :
case V_24 :
case V_22 :
case V_21 :
if ( ! V_14 -> V_138 )
break;
if ( ! F_177 ( V_14 -> V_138 , V_348 , L_24 ) ) {
V_233 = - V_350 ;
break;
}
if ( V_14 -> V_43 & V_351 ) {
V_14 -> V_11 = F_178 ( V_14 -> V_138 , V_348 ) ;
if ( ! V_14 -> V_11 ) {
F_179 ( V_14 -> V_138 , V_348 ) ;
V_233 = - V_52 ;
}
}
break;
case V_20 :
case V_352 :
if ( ! F_180 ( V_14 -> V_16 , V_348 , L_24 ) )
V_233 = - V_350 ;
break;
}
return V_233 ;
}
static void F_181 ( struct V_1 * V_2 )
{
unsigned int V_348 = F_174 ( V_2 ) ;
struct V_6 * V_14 = & V_2 -> V_14 ;
switch ( V_14 -> V_19 ) {
case V_25 :
case V_349 :
case V_23 :
case V_24 :
case V_22 :
case V_21 :
if ( ! V_14 -> V_138 )
break;
if ( V_14 -> V_43 & V_351 ) {
F_182 ( V_14 -> V_11 ) ;
V_14 -> V_11 = NULL ;
}
F_179 ( V_14 -> V_138 , V_348 ) ;
break;
case V_20 :
case V_352 :
F_183 ( V_14 -> V_16 , V_348 ) ;
break;
}
}
static void F_184 ( struct V_6 * V_14 )
{
struct V_1 * V_2 = F_35 ( V_14 ) ;
F_181 ( V_2 ) ;
}
static int F_185 ( struct V_6 * V_14 )
{
struct V_1 * V_2 = F_35 ( V_14 ) ;
return F_176 ( V_2 ) ;
}
static int F_186 ( struct V_1 * V_2 )
{
const struct V_353 * V_354 = & V_147 [ V_2 -> V_14 . type ] ;
unsigned char V_355 ;
V_355 = V_354 -> V_356 [ F_187 ( V_2 -> V_46 ) ] ;
return V_355 ? V_355 : - V_357 ;
}
static int F_188 ( struct V_1 * V_2 , unsigned char V_355 )
{
const struct V_353 * V_354 = & V_147 [ V_2 -> V_14 . type ] ;
int V_358 ;
if ( ! V_354 -> V_356 [ F_187 ( V_359 ) ] )
return - V_357 ;
for ( V_358 = 1 ; V_358 < V_360 ; V_358 ++ ) {
if ( V_355 < V_354 -> V_356 [ V_358 ] )
return ( -- V_358 ) << V_361 ;
}
return V_362 ;
}
static int F_189 ( struct V_363 * V_14 )
{
struct V_364 * V_205 = F_190 ( V_14 , struct V_364 , V_14 ) ;
struct V_6 * V_365 = V_205 -> V_6 ;
struct V_1 * V_2 = F_35 ( V_365 ) ;
if ( ! ( V_2 -> V_35 & V_36 ) || V_365 -> V_146 <= 1 )
return - V_366 ;
return F_186 ( V_2 ) ;
}
static int F_191 ( struct V_363 * V_14 )
{
int V_356 ;
F_192 ( & V_14 -> V_367 ) ;
V_356 = F_189 ( V_14 ) ;
F_193 ( & V_14 -> V_367 ) ;
return V_356 ;
}
static T_2 F_194 ( struct V_368 * V_48 ,
struct V_369 * V_370 , char * V_210 )
{
struct V_363 * V_14 = F_195 ( V_48 ) ;
int V_356 ;
V_356 = F_191 ( V_14 ) ;
if ( V_356 < 0 )
return V_356 ;
return snprintf ( V_210 , V_371 , L_25 , V_356 ) ;
}
static int F_196 ( struct V_363 * V_14 , unsigned char V_355 )
{
struct V_364 * V_205 = F_190 ( V_14 , struct V_364 , V_14 ) ;
struct V_6 * V_365 = V_205 -> V_6 ;
struct V_1 * V_2 = F_35 ( V_365 ) ;
int V_372 ;
if ( ! ( V_2 -> V_35 & V_36 ) || V_365 -> V_146 <= 1 ||
V_2 -> V_314 )
return - V_366 ;
V_372 = F_188 ( V_2 , V_355 ) ;
if ( V_372 < 0 )
return V_372 ;
F_40 ( V_2 ) ;
V_2 -> V_46 &= ~ V_324 ;
V_2 -> V_46 |= ( unsigned char ) V_372 ;
F_4 ( V_2 , V_37 , V_2 -> V_46 ) ;
return 0 ;
}
static int F_197 ( struct V_363 * V_14 , unsigned char V_355 )
{
int V_233 ;
F_192 ( & V_14 -> V_367 ) ;
V_233 = F_196 ( V_14 , V_355 ) ;
F_193 ( & V_14 -> V_367 ) ;
return V_233 ;
}
static T_2 F_198 ( struct V_368 * V_48 ,
struct V_369 * V_370 , const char * V_210 , T_3 V_88 )
{
struct V_363 * V_14 = F_195 ( V_48 ) ;
unsigned char V_355 ;
int V_233 ;
if ( ! V_88 )
return - V_366 ;
V_233 = F_199 ( V_210 , 10 , & V_355 ) ;
if ( V_233 < 0 )
return V_233 ;
V_233 = F_197 ( V_14 , V_355 ) ;
if ( V_233 < 0 )
return V_233 ;
return V_88 ;
}
static void F_200 ( struct V_1 * V_2 )
{
const struct V_353 * V_354 = & V_147 [ V_2 -> V_14 . type ] ;
if ( V_354 -> V_356 [ 0 ] )
V_2 -> V_14 . V_373 = & V_374 ;
}
static void F_201 ( struct V_6 * V_14 , int V_43 )
{
struct V_1 * V_2 = F_35 ( V_14 ) ;
int V_233 ;
V_233 = F_176 ( V_2 ) ;
if ( V_233 < 0 )
return;
if ( V_14 -> V_19 != V_2 -> V_26 )
F_34 ( V_14 ) ;
if ( V_43 & V_375 )
F_76 ( V_2 ) ;
if ( V_14 -> type == V_116 && V_14 -> V_19 == V_25 )
V_2 -> V_105 |= V_184 ;
if ( V_14 -> type == V_376 )
V_2 -> V_105 |= V_184 ;
if ( V_14 -> type != V_142 && V_43 & V_377 )
F_84 ( V_2 ) ;
if ( V_14 -> type == V_142 )
F_181 ( V_2 ) ;
if ( ( V_14 -> type == V_63 ) ||
( V_14 -> type == V_64 ) )
V_14 -> V_27 = F_130 ;
F_200 ( V_2 ) ;
V_2 -> V_46 = V_147 [ V_2 -> V_14 . type ] . V_46 ;
}
static int
F_202 ( struct V_6 * V_14 , struct V_378 * V_379 )
{
if ( V_379 -> V_156 >= V_380 || V_379 -> V_156 < 0 ||
V_379 -> V_381 < 9600 || V_379 -> type < V_142 ||
V_379 -> type >= F_6 ( V_147 ) || V_379 -> type == V_382 ||
V_379 -> type == V_383 )
return - V_366 ;
return 0 ;
}
static const char * F_203 ( struct V_6 * V_14 )
{
int type = V_14 -> type ;
if ( type >= F_6 ( V_147 ) )
type = 0 ;
return V_147 [ type ] . V_151 ;
}
void F_204 ( struct V_1 * V_2 )
{
struct V_6 * V_14 = & V_2 -> V_14 ;
F_205 ( & V_14 -> V_81 ) ;
V_14 -> V_285 = & V_384 ;
V_2 -> V_26 = 0xFF ;
}
void F_206 ( struct V_1 * V_2 )
{
struct V_6 * V_14 = & V_2 -> V_14 ;
if ( V_2 -> V_14 . V_43 & V_385 ) {
unsigned int type = V_2 -> V_14 . type ;
if ( ! V_2 -> V_14 . V_146 )
V_2 -> V_14 . V_146 = V_147 [ type ] . V_148 ;
if ( ! V_2 -> V_149 )
V_2 -> V_149 = V_147 [ type ] . V_149 ;
if ( ! V_2 -> V_35 )
V_2 -> V_35 = V_147 [ type ] . V_43 ;
}
F_34 ( V_14 ) ;
if ( V_2 -> V_174 ) {
if ( ! V_2 -> V_174 -> V_175 )
V_2 -> V_174 -> V_175 = V_386 ;
if ( ! V_2 -> V_174 -> V_230 )
V_2 -> V_174 -> V_230 = V_387 ;
}
}
static void F_207 ( struct V_6 * V_14 , int V_186 )
{
struct V_1 * V_2 = F_35 ( V_14 ) ;
F_138 ( V_2 , V_179 ) ;
F_94 ( V_14 , V_91 , V_186 ) ;
}
static void F_208 ( struct V_1 * V_2 )
{
struct V_6 * V_14 = & V_2 -> V_14 ;
struct V_321 V_322 ;
unsigned int V_295 , V_124 , V_296 = 0 ;
V_322 . V_299 = V_14 -> V_388 -> V_389 ;
if ( V_14 -> V_205 -> V_14 . V_390 && V_322 . V_299 == 0 )
V_322 . V_299 = V_14 -> V_205 -> V_14 . V_390 -> V_322 . V_299 ;
V_295 = F_162 ( V_14 , & V_322 , NULL ) ;
V_124 = F_156 ( V_2 , V_295 , & V_296 ) ;
F_160 ( V_14 , V_295 , V_124 , V_296 ) ;
F_94 ( V_14 , V_29 , V_2 -> V_61 ) ;
F_43 ( V_2 , V_160 | V_45 ) ;
}
void F_209 ( struct V_1 * V_2 , const char * V_391 ,
unsigned int V_88 )
{
struct V_6 * V_14 = & V_2 -> V_14 ;
unsigned long V_43 ;
unsigned int V_161 ;
int V_392 = 1 ;
F_139 () ;
F_45 ( V_2 ) ;
if ( V_14 -> V_393 )
V_392 = 0 ;
else if ( V_394 )
V_392 = F_210 ( & V_14 -> V_81 , V_43 ) ;
else
F_78 ( & V_14 -> V_81 , V_43 ) ;
V_161 = F_129 ( V_14 , V_72 ) ;
if ( V_2 -> V_35 & V_130 )
F_94 ( V_14 , V_72 , V_128 ) ;
else
F_94 ( V_14 , V_72 , 0 ) ;
if ( V_2 -> V_395 && ( V_2 -> V_395 != F_129 ( V_14 , V_30 ) ) ) {
F_208 ( V_2 ) ;
V_2 -> V_395 = 0 ;
}
F_211 ( V_14 , V_391 , V_88 , F_207 ) ;
F_138 ( V_2 , V_172 ) ;
F_94 ( V_14 , V_72 , V_161 ) ;
if ( V_2 -> V_216 )
F_122 ( V_2 ) ;
if ( V_392 )
F_80 ( & V_14 -> V_81 , V_43 ) ;
F_47 ( V_2 ) ;
}
static unsigned int F_212 ( struct V_6 * V_14 )
{
unsigned char V_61 , V_396 , V_397 ;
unsigned int V_124 ;
V_61 = F_129 ( V_14 , V_29 ) ;
F_94 ( V_14 , V_29 , V_61 | V_320 ) ;
V_396 = F_129 ( V_14 , V_3 ) ;
V_397 = F_129 ( V_14 , V_4 ) ;
F_94 ( V_14 , V_29 , V_61 ) ;
V_124 = ( V_397 << 8 ) | V_396 ;
return ( V_14 -> V_78 / 16 ) / V_124 ;
}
int F_213 ( struct V_6 * V_14 , char * V_398 , bool V_144 )
{
int V_295 = 9600 ;
int V_255 = 8 ;
int V_196 = 'n' ;
int V_399 = 'n' ;
if ( ! V_14 -> V_16 && ! V_14 -> V_11 )
return - V_266 ;
if ( V_398 )
F_214 ( V_398 , & V_295 , & V_196 , & V_255 , & V_399 ) ;
else if ( V_144 )
V_295 = F_212 ( V_14 ) ;
return F_215 ( V_14 , V_14 -> V_388 , V_295 , V_196 , V_255 , V_399 ) ;
}
