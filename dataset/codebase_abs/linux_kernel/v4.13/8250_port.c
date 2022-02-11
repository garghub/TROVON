static int F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_2 , V_3 ) | F_2 ( V_2 , V_4 ) << 8 ;
}
static void F_3 ( struct V_1 * V_2 , int V_5 )
{
F_4 ( V_2 , V_3 , V_5 & 0xff ) ;
F_4 ( V_2 , V_4 , V_5 >> 8 & 0xff ) ;
}
unsigned int F_5 ( struct V_6 * V_7 , int V_8 )
{
if ( V_8 >= F_6 ( V_9 ) )
return V_10 ;
V_8 = V_9 [ V_8 ] ;
if ( V_8 < 0 )
return V_10 ;
return F_7 ( V_7 -> V_11 + ( V_8 << V_7 -> V_12 ) ) ;
}
void F_8 ( struct V_6 * V_7 , int V_8 , int V_5 )
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
if ( V_14 -> type == V_116 && V_14 -> V_19 == V_151 )
F_82 ( V_2 ) ;
if ( V_2 -> V_35 != V_137 ) {
F_83 ( L_14 ,
F_77 ( V_14 ) , V_137 ,
V_2 -> V_35 ) ;
}
V_66:
F_71 ( L_15 , V_110 ) ;
F_71 ( L_16 , V_147 [ V_14 -> type ] . V_152 ) ;
}
static void F_84 ( struct V_1 * V_2 )
{
struct V_6 * V_14 = & V_2 -> V_14 ;
unsigned char V_136 , V_153 ;
unsigned char V_154 = 0 ;
unsigned int V_155 = 0 ;
unsigned long V_156 ;
int V_157 ;
if ( V_14 -> V_43 & V_158 ) {
V_155 = ( V_14 -> V_16 & 0xfe0 ) | 0x1f ;
V_154 = F_85 ( V_155 ) ;
F_86 ( 0x80 , V_155 ) ;
F_85 ( V_155 ) ;
}
if ( F_87 ( V_14 ) )
F_88 () ;
F_89 ( F_90 () ) ;
V_136 = F_42 ( V_2 ) ;
V_153 = F_2 ( V_2 , V_72 ) ;
F_43 ( V_2 , V_159 | V_160 ) ;
V_156 = F_90 () ;
F_43 ( V_2 , 0 ) ;
F_91 ( 10 ) ;
if ( V_14 -> V_43 & V_158 ) {
F_43 ( V_2 , V_161 | V_45 ) ;
} else {
F_43 ( V_2 ,
V_161 | V_45 | V_160 ) ;
}
F_4 ( V_2 , V_72 , 0x0f ) ;
F_2 ( V_2 , V_92 ) ;
F_2 ( V_2 , V_94 ) ;
F_2 ( V_2 , V_122 ) ;
F_2 ( V_2 , V_141 ) ;
F_4 ( V_2 , V_91 , 0xFF ) ;
F_91 ( 20 ) ;
V_157 = F_89 ( V_156 ) ;
F_43 ( V_2 , V_136 ) ;
F_4 ( V_2 , V_72 , V_153 ) ;
if ( V_14 -> V_43 & V_158 )
F_86 ( V_154 , V_155 ) ;
if ( F_87 ( V_14 ) )
F_92 () ;
V_14 -> V_157 = ( V_157 > 0 ) ? V_157 : 0 ;
}
static void F_93 ( struct V_6 * V_14 )
{
struct V_1 * V_2 = F_35 ( V_14 ) ;
F_45 ( V_2 ) ;
V_2 -> V_162 &= ~ ( V_163 | V_164 ) ;
V_2 -> V_14 . V_165 &= ~ V_93 ;
F_94 ( V_14 , V_72 , V_2 -> V_162 ) ;
F_47 ( V_2 ) ;
}
static void F_95 ( struct V_1 * V_7 )
{
F_41 ( V_7 ) ;
if ( ! ( V_7 -> V_14 . V_42 . V_43 & V_166 ) ) {
F_44 ( V_7 ) ;
V_7 -> V_162 |= V_163 | V_164 ;
F_94 ( & V_7 -> V_14 , V_72 , V_7 -> V_162 ) ;
}
}
static void V_54 ( unsigned long V_167 )
{
struct V_1 * V_7 = (struct V_1 * ) V_167 ;
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
if ( V_7 -> V_14 . V_42 . V_168 > 0 ) {
V_49 -> V_57 = & V_49 -> V_53 ;
F_97 ( & V_49 -> V_53 , V_169 +
V_7 -> V_14 . V_42 . V_168 * V_170 / 1000 ) ;
} else {
F_95 ( V_7 ) ;
}
}
static inline void F_98 ( struct V_1 * V_7 )
{
if ( V_7 -> V_162 & V_171 ) {
V_7 -> V_162 &= ~ V_171 ;
F_4 ( V_7 , V_72 , V_7 -> V_162 ) ;
F_58 ( V_7 ) ;
}
}
static inline void F_99 ( struct V_1 * V_7 )
{
struct V_50 * V_49 = V_7 -> V_49 ;
if ( V_49 ) {
unsigned char V_172 = F_2 ( V_7 , V_92 ) ;
if ( ( V_172 & V_173 ) != V_173 )
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
V_2 -> V_33 |= V_174 ;
F_38 ( V_2 , V_32 , V_2 -> V_33 ) ;
}
F_47 ( V_2 ) ;
}
static inline void F_101 ( struct V_6 * V_14 )
{
struct V_1 * V_2 = F_35 ( V_14 ) ;
if ( V_2 -> V_175 && ! V_2 -> V_175 -> V_176 ( V_2 ) )
return;
if ( ! ( V_2 -> V_162 & V_171 ) ) {
V_2 -> V_162 |= V_171 ;
F_94 ( V_14 , V_72 , V_2 -> V_162 ) ;
if ( V_2 -> V_105 & V_177 ) {
unsigned char V_172 ;
V_172 = F_2 ( V_2 , V_92 ) ;
V_2 -> V_178 |= V_172 & V_179 ;
if ( V_172 & V_180 )
F_102 ( V_2 ) ;
}
}
if ( V_14 -> type == V_104 && V_2 -> V_33 & V_174 ) {
V_2 -> V_33 &= ~ V_174 ;
F_38 ( V_2 , V_32 , V_2 -> V_33 ) ;
}
}
static inline void F_103 ( struct V_6 * V_14 )
{
struct V_1 * V_2 = F_35 ( V_14 ) ;
struct V_50 * V_49 = V_2 -> V_49 ;
unsigned char V_41 ;
if ( ! ( V_2 -> V_14 . V_42 . V_43 & V_166 ) )
F_93 ( & V_2 -> V_14 ) ;
F_54 ( & V_49 -> V_53 ) ;
V_49 -> V_57 = NULL ;
V_41 = F_42 ( V_2 ) ;
if ( ! ! ( V_2 -> V_14 . V_42 . V_43 & V_181 ) !=
! ! ( V_41 & V_45 ) ) {
if ( V_2 -> V_14 . V_42 . V_43 & V_181 )
V_41 |= V_45 ;
else
V_41 &= ~ V_45 ;
F_43 ( V_2 , V_41 ) ;
if ( V_2 -> V_14 . V_42 . V_182 > 0 ) {
V_49 -> V_57 = & V_49 -> V_55 ;
F_97 ( & V_49 -> V_55 , V_169 +
V_2 -> V_14 . V_42 . V_182 * V_170 / 1000 ) ;
return;
}
}
F_101 ( V_14 ) ;
}
static void V_56 ( unsigned long V_167 )
{
struct V_1 * V_7 = (struct V_1 * ) V_167 ;
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
V_14 -> V_183 ( V_14 ) ;
}
static void F_106 ( struct V_6 * V_14 )
{
V_14 -> V_184 ( V_14 ) ;
}
static void F_107 ( struct V_6 * V_14 )
{
struct V_1 * V_2 = F_35 ( V_14 ) ;
if ( V_2 -> V_105 & V_185 )
return;
V_2 -> V_162 &= ~ V_186 ;
F_94 ( V_14 , V_72 , V_2 -> V_162 ) ;
}
static void F_108 ( struct V_6 * V_14 )
{
struct V_1 * V_2 = F_35 ( V_14 ) ;
if ( V_2 -> V_105 & V_185 )
return;
V_2 -> V_162 |= V_186 ;
F_45 ( V_2 ) ;
F_94 ( V_14 , V_72 , V_2 -> V_162 ) ;
F_47 ( V_2 ) ;
}
static void F_109 ( struct V_1 * V_2 , unsigned char V_172 )
{
struct V_6 * V_14 = & V_2 -> V_14 ;
unsigned char V_187 ;
char V_188 = V_189 ;
if ( F_110 ( V_172 & V_93 ) )
V_187 = F_2 ( V_2 , V_94 ) ;
else
V_187 = 0 ;
V_14 -> V_190 . V_191 ++ ;
V_172 |= V_2 -> V_178 ;
V_2 -> V_178 = 0 ;
if ( F_111 ( V_172 & V_192 ) ) {
if ( V_172 & V_193 ) {
V_172 &= ~ ( V_194 | V_195 ) ;
V_14 -> V_190 . V_196 ++ ;
if ( F_112 ( V_14 ) )
return;
} else if ( V_172 & V_195 )
V_14 -> V_190 . V_197 ++ ;
else if ( V_172 & V_194 )
V_14 -> V_190 . V_198 ++ ;
if ( V_172 & V_199 )
V_14 -> V_190 . V_200 ++ ;
V_172 &= V_14 -> V_165 ;
if ( V_172 & V_193 ) {
F_113 ( L_17 , V_201 ) ;
V_188 = V_202 ;
} else if ( V_172 & V_195 )
V_188 = V_203 ;
else if ( V_172 & V_194 )
V_188 = V_204 ;
}
if ( F_114 ( V_14 , V_187 ) )
return;
F_115 ( V_14 , V_172 , V_199 , V_187 , V_188 ) ;
}
unsigned char F_116 ( struct V_1 * V_2 , unsigned char V_172 )
{
struct V_6 * V_14 = & V_2 -> V_14 ;
int V_205 = 256 ;
do {
F_109 ( V_2 , V_172 ) ;
if ( -- V_205 == 0 )
break;
V_172 = F_2 ( V_2 , V_92 ) ;
} while ( V_172 & ( V_93 | V_193 ) );
F_117 ( & V_14 -> V_206 -> V_14 ) ;
return V_172 ;
}
void F_102 ( struct V_1 * V_2 )
{
struct V_6 * V_14 = & V_2 -> V_14 ;
struct V_207 * V_208 = & V_14 -> V_206 -> V_208 ;
int V_88 ;
if ( V_14 -> V_209 ) {
F_4 ( V_2 , V_91 , V_14 -> V_209 ) ;
V_14 -> V_190 . V_210 ++ ;
V_14 -> V_209 = 0 ;
return;
}
if ( F_118 ( V_14 ) ) {
F_100 ( V_14 ) ;
return;
}
if ( F_119 ( V_208 ) ) {
F_99 ( V_2 ) ;
return;
}
V_88 = V_2 -> V_149 ;
do {
F_4 ( V_2 , V_91 , V_208 -> V_211 [ V_208 -> V_212 ] ) ;
V_208 -> V_212 = ( V_208 -> V_212 + 1 ) & ( V_213 - 1 ) ;
V_14 -> V_190 . V_210 ++ ;
if ( F_119 ( V_208 ) )
break;
if ( ( V_2 -> V_35 & V_214 ) &&
( F_2 ( V_2 , V_92 ) & V_173 ) != V_173 )
break;
if ( ( V_2 -> V_35 & V_215 ) &&
! ( F_2 ( V_2 , V_92 ) & V_180 ) )
break;
} while ( -- V_88 > 0 );
if ( F_120 ( V_208 ) < V_216 )
F_121 ( V_14 ) ;
if ( F_119 ( V_208 ) && ! ( V_2 -> V_35 & V_47 ) )
F_99 ( V_2 ) ;
}
unsigned int F_122 ( struct V_1 * V_2 )
{
struct V_6 * V_14 = & V_2 -> V_14 ;
unsigned int V_217 = F_2 ( V_2 , V_141 ) ;
V_217 |= V_2 -> V_218 ;
V_2 -> V_218 = 0 ;
if ( V_217 & V_219 && V_2 -> V_162 & V_186 &&
V_14 -> V_206 != NULL ) {
if ( V_217 & V_220 )
V_14 -> V_190 . V_221 ++ ;
if ( V_217 & V_222 )
V_14 -> V_190 . V_223 ++ ;
if ( V_217 & V_224 )
F_123 ( V_14 , V_217 & V_225 ) ;
if ( V_217 & V_226 )
F_124 ( V_14 , V_217 & V_227 ) ;
F_125 ( & V_14 -> V_206 -> V_14 . V_228 ) ;
}
return V_217 ;
}
static bool F_126 ( struct V_1 * V_2 , unsigned int V_229 )
{
switch ( V_229 & 0x3f ) {
case V_230 :
F_127 ( V_2 ) ;
case V_231 :
return true ;
}
return V_2 -> V_175 -> V_232 ( V_2 ) ;
}
int F_128 ( struct V_6 * V_14 , unsigned int V_229 )
{
unsigned char V_217 ;
unsigned long V_43 ;
struct V_1 * V_2 = F_35 ( V_14 ) ;
if ( V_229 & V_233 )
return 0 ;
F_78 ( & V_14 -> V_81 , V_43 ) ;
V_217 = F_129 ( V_14 , V_92 ) ;
if ( V_217 & ( V_93 | V_193 ) ) {
if ( ! V_2 -> V_175 || F_126 ( V_2 , V_229 ) )
V_217 = F_116 ( V_2 , V_217 ) ;
}
F_122 ( V_2 ) ;
if ( ( ! V_2 -> V_175 || V_2 -> V_175 -> V_234 ) && ( V_217 & V_180 ) )
F_102 ( V_2 ) ;
F_80 ( & V_14 -> V_81 , V_43 ) ;
return 1 ;
}
static int V_28 ( struct V_6 * V_14 )
{
struct V_1 * V_2 = F_35 ( V_14 ) ;
unsigned int V_229 ;
int V_235 ;
F_45 ( V_2 ) ;
V_229 = F_129 ( V_14 , V_122 ) ;
V_235 = F_128 ( V_14 , V_229 ) ;
F_47 ( V_2 ) ;
return V_235 ;
}
static int F_130 ( struct V_6 * V_14 )
{
unsigned int V_229 = F_129 ( V_14 , V_122 ) ;
int V_235 = 0 ;
if ( ( ( V_14 -> type == V_63 ) || ( V_14 -> type == V_64 ) ) &&
F_129 ( V_14 , V_236 ) != 0 )
V_235 = 1 ;
V_235 |= F_128 ( V_14 , V_229 ) ;
return V_235 ;
}
static int F_131 ( struct V_6 * V_14 )
{
unsigned long V_43 ;
unsigned int V_229 = F_129 ( V_14 , V_122 ) ;
if ( ( V_229 & V_237 ) == V_238 ) {
struct V_1 * V_2 = F_35 ( V_14 ) ;
F_78 ( & V_14 -> V_81 , V_43 ) ;
F_102 ( V_2 ) ;
F_80 ( & V_14 -> V_81 , V_43 ) ;
}
V_229 = F_129 ( V_14 , V_122 ) ;
return F_128 ( V_14 , V_229 ) ;
}
static unsigned int F_132 ( struct V_6 * V_14 )
{
struct V_1 * V_2 = F_35 ( V_14 ) ;
unsigned long V_43 ;
unsigned int V_172 ;
F_45 ( V_2 ) ;
F_78 ( & V_14 -> V_81 , V_43 ) ;
V_172 = F_129 ( V_14 , V_92 ) ;
V_2 -> V_178 |= V_172 & V_179 ;
F_80 ( & V_14 -> V_81 , V_43 ) ;
F_47 ( V_2 ) ;
return ( V_172 & V_173 ) == V_173 ? V_239 : 0 ;
}
unsigned int F_133 ( struct V_6 * V_14 )
{
struct V_1 * V_2 = F_35 ( V_14 ) ;
unsigned int V_217 ;
unsigned int V_235 ;
F_45 ( V_2 ) ;
V_217 = F_122 ( V_2 ) ;
F_47 ( V_2 ) ;
V_235 = 0 ;
if ( V_217 & V_225 )
V_235 |= V_240 ;
if ( V_217 & V_241 )
V_235 |= V_242 ;
if ( V_217 & V_243 )
V_235 |= V_244 ;
if ( V_217 & V_227 )
V_235 |= V_245 ;
return V_235 ;
}
static unsigned int F_134 ( struct V_6 * V_14 )
{
if ( V_14 -> V_246 )
return V_14 -> V_246 ( V_14 ) ;
return F_133 ( V_14 ) ;
}
void F_135 ( struct V_6 * V_14 , unsigned int V_247 )
{
struct V_1 * V_2 = F_35 ( V_14 ) ;
unsigned char V_41 = 0 ;
if ( V_247 & V_248 )
V_41 |= V_45 ;
if ( V_247 & V_249 )
V_41 |= V_161 ;
if ( V_247 & V_250 )
V_41 |= V_159 ;
if ( V_247 & V_251 )
V_41 |= V_160 ;
if ( V_247 & V_252 )
V_41 |= V_89 ;
V_41 = ( V_41 & V_2 -> V_253 ) | V_2 -> V_254 | V_2 -> V_41 ;
F_43 ( V_2 , V_41 ) ;
}
static void F_136 ( struct V_6 * V_14 , unsigned int V_247 )
{
if ( V_14 -> V_255 )
V_14 -> V_255 ( V_14 , V_247 ) ;
else
F_135 ( V_14 , V_247 ) ;
}
static void F_137 ( struct V_6 * V_14 , int V_256 )
{
struct V_1 * V_2 = F_35 ( V_14 ) ;
unsigned long V_43 ;
F_45 ( V_2 ) ;
F_78 ( & V_14 -> V_81 , V_43 ) ;
if ( V_256 == - 1 )
V_2 -> V_61 |= V_257 ;
else
V_2 -> V_61 &= ~ V_257 ;
F_94 ( V_14 , V_29 , V_2 -> V_61 ) ;
F_80 ( & V_14 -> V_81 , V_43 ) ;
F_47 ( V_2 ) ;
}
static void F_138 ( struct V_1 * V_2 , int V_258 )
{
unsigned int V_217 , V_259 = 10000 ;
for (; ; ) {
V_217 = F_2 ( V_2 , V_92 ) ;
V_2 -> V_178 |= V_217 & V_179 ;
if ( ( V_217 & V_258 ) == V_258 )
break;
if ( -- V_259 == 0 )
break;
F_91 ( 1 ) ;
F_139 () ;
}
if ( V_2 -> V_14 . V_43 & V_260 ) {
for ( V_259 = 1000000 ; V_259 ; V_259 -- ) {
unsigned int V_261 = F_2 ( V_2 , V_141 ) ;
V_2 -> V_218 |= V_261 & V_262 ;
if ( V_261 & V_227 )
break;
F_91 ( 1 ) ;
F_139 () ;
}
}
}
static int F_140 ( struct V_6 * V_14 )
{
struct V_1 * V_2 = F_35 ( V_14 ) ;
unsigned char V_172 ;
int V_217 ;
F_45 ( V_2 ) ;
V_172 = F_129 ( V_14 , V_92 ) ;
if ( ! ( V_172 & V_93 ) ) {
V_217 = V_263 ;
goto V_66;
}
V_217 = F_129 ( V_14 , V_94 ) ;
V_66:
F_47 ( V_2 ) ;
return V_217 ;
}
static void F_141 ( struct V_6 * V_14 ,
unsigned char V_264 )
{
unsigned int V_162 ;
struct V_1 * V_2 = F_35 ( V_14 ) ;
F_45 ( V_2 ) ;
V_162 = F_129 ( V_14 , V_72 ) ;
if ( V_2 -> V_35 & V_130 )
F_94 ( V_14 , V_72 , V_128 ) ;
else
F_94 ( V_14 , V_72 , 0 ) ;
F_138 ( V_2 , V_173 ) ;
F_94 ( V_14 , V_91 , V_264 ) ;
F_138 ( V_2 , V_173 ) ;
F_94 ( V_14 , V_72 , V_162 ) ;
F_47 ( V_2 ) ;
}
int F_142 ( struct V_6 * V_14 )
{
struct V_1 * V_2 = F_35 ( V_14 ) ;
unsigned long V_43 ;
unsigned char V_172 , V_229 ;
int V_265 ;
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
F_38 ( V_2 , V_266 , 0 ) ;
F_94 ( V_14 , V_29 , V_70 ) ;
F_94 ( V_14 , V_69 , V_71 ) ;
F_94 ( V_14 , V_29 , 0 ) ;
}
if ( V_14 -> type == V_267 ) {
F_94 ( V_14 , V_72 , 0 ) ;
F_94 ( V_14 , V_268 , 0 ) ;
F_68 ( 10 ) ;
F_94 ( V_14 , V_268 ,
V_269 |
V_270 |
V_271 ) ;
}
#ifdef F_81
F_61 ( V_2 ) ;
#endif
if ( V_14 -> type == V_63 ) {
F_94 ( V_14 , V_272 , V_71 ) ;
F_94 ( V_14 , V_72 , 0 ) ;
}
F_40 ( V_2 ) ;
F_129 ( V_14 , V_92 ) ;
F_129 ( V_14 , V_94 ) ;
F_129 ( V_14 , V_122 ) ;
F_129 ( V_14 , V_141 ) ;
if ( ( V_14 -> type == V_63 ) || ( V_14 -> type == V_64 ) )
F_129 ( V_14 , V_236 ) ;
if ( ! ( V_14 -> V_43 & V_139 ) &&
( F_129 ( V_14 , V_92 ) == 0xff ) ) {
F_143 ( V_273 L_18 ,
F_77 ( V_14 ) ) ;
V_265 = - V_274 ;
goto V_66;
}
if ( V_14 -> type == V_107 ) {
unsigned char V_275 ;
F_4 ( V_2 , V_29 , V_70 ) ;
V_275 = F_2 ( V_2 , V_276 ) & ~ ( V_277 | V_278 ) ;
F_94 ( V_14 , V_276 ,
V_275 | V_279 | V_277 ) ;
F_94 ( V_14 , V_280 , V_281 ) ;
F_94 ( V_14 , V_276 ,
V_275 | V_279 | V_278 ) ;
F_94 ( V_14 , V_280 , V_281 ) ;
F_94 ( V_14 , V_29 , 0 ) ;
}
if ( ( ( V_14 -> type == V_282 ) ||
( V_14 -> type == V_283 ) ||
( V_14 -> type == V_284 ) ) && ( V_14 -> V_146 > 1 ) ) {
if ( ( V_2 -> V_149 < 2 ) || ( V_2 -> V_149 > V_14 -> V_146 ) ) {
F_144 ( L_19 ,
F_77 ( V_14 ) ) ;
} else {
F_94 ( V_14 , V_285 ,
V_286 ) ;
F_94 ( V_14 , V_287 ,
V_14 -> V_146 - V_2 -> V_149 ) ;
V_14 -> V_27 = F_131 ;
}
}
if ( V_14 -> V_157 && ! ( V_2 -> V_14 . V_43 & V_288 ) ) {
unsigned char V_289 ;
F_78 ( & V_14 -> V_81 , V_43 ) ;
if ( V_2 -> V_14 . V_290 & V_291 )
F_145 ( V_14 -> V_157 ) ;
F_138 ( V_2 , V_180 ) ;
F_37 ( V_14 , V_72 , V_171 ) ;
F_91 ( 1 ) ;
V_289 = F_129 ( V_14 , V_122 ) ;
F_94 ( V_14 , V_72 , 0 ) ;
F_37 ( V_14 , V_72 , V_171 ) ;
F_91 ( 1 ) ;
V_229 = F_129 ( V_14 , V_122 ) ;
F_94 ( V_14 , V_72 , 0 ) ;
if ( V_14 -> V_290 & V_291 )
F_146 ( V_14 -> V_157 ) ;
F_80 ( & V_14 -> V_81 , V_43 ) ;
if ( ( ! ( V_289 & V_233 ) && ( V_229 & V_233 ) ) ||
V_2 -> V_14 . V_43 & V_292 ) {
V_2 -> V_105 |= V_293 ;
}
}
V_265 = V_2 -> V_294 -> V_295 ( V_2 ) ;
if ( V_265 )
goto V_66;
F_94 ( V_14 , V_29 , V_296 ) ;
F_78 ( & V_14 -> V_81 , V_43 ) ;
if ( V_2 -> V_14 . V_43 & V_158 ) {
if ( ! V_2 -> V_14 . V_157 )
V_2 -> V_14 . V_247 |= V_250 ;
} else
if ( V_14 -> V_157 )
V_2 -> V_14 . V_247 |= V_251 ;
F_136 ( V_14 , V_14 -> V_247 ) ;
if ( V_2 -> V_14 . V_43 & V_297 )
goto V_298;
F_94 ( V_14 , V_72 , V_171 ) ;
V_172 = F_129 ( V_14 , V_92 ) ;
V_229 = F_129 ( V_14 , V_122 ) ;
F_94 ( V_14 , V_72 , 0 ) ;
if ( V_172 & V_299 && V_229 & V_233 ) {
if ( ! ( V_2 -> V_105 & V_177 ) ) {
V_2 -> V_105 |= V_177 ;
F_113 ( L_20 ,
F_77 ( V_14 ) ) ;
}
} else {
V_2 -> V_105 &= ~ V_177 ;
}
V_298:
F_80 ( & V_14 -> V_81 , V_43 ) ;
F_129 ( V_14 , V_92 ) ;
F_129 ( V_14 , V_94 ) ;
F_129 ( V_14 , V_122 ) ;
F_129 ( V_14 , V_141 ) ;
if ( ( V_14 -> type == V_63 ) || ( V_14 -> type == V_64 ) )
F_129 ( V_14 , V_236 ) ;
V_2 -> V_178 = 0 ;
V_2 -> V_218 = 0 ;
if ( V_2 -> V_175 ) {
V_265 = F_147 ( V_2 ) ;
if ( V_265 ) {
F_148 ( L_21 ,
F_77 ( V_14 ) ) ;
V_2 -> V_175 = NULL ;
}
}
V_2 -> V_162 = V_163 | V_164 ;
if ( V_14 -> V_43 & V_158 ) {
unsigned int V_300 ;
V_300 = ( V_14 -> V_16 & 0xfe0 ) | 0x01f ;
F_86 ( 0x80 , V_300 ) ;
F_85 ( V_300 ) ;
}
V_265 = 0 ;
V_66:
F_47 ( V_2 ) ;
return V_265 ;
}
static int F_149 ( struct V_6 * V_14 )
{
if ( V_14 -> V_301 )
return V_14 -> V_301 ( V_14 ) ;
return F_142 ( V_14 ) ;
}
void F_150 ( struct V_6 * V_14 )
{
struct V_1 * V_2 = F_35 ( V_14 ) ;
unsigned long V_43 ;
F_45 ( V_2 ) ;
F_78 ( & V_14 -> V_81 , V_43 ) ;
V_2 -> V_162 = 0 ;
F_94 ( V_14 , V_72 , 0 ) ;
F_80 ( & V_14 -> V_81 , V_43 ) ;
F_151 ( V_14 -> V_157 ) ;
if ( V_2 -> V_175 )
F_152 ( V_2 ) ;
F_78 ( & V_14 -> V_81 , V_43 ) ;
if ( V_14 -> V_43 & V_158 ) {
F_14 ( ( V_14 -> V_16 & 0xfe0 ) | 0x1f ) ;
V_14 -> V_247 |= V_250 ;
} else
V_14 -> V_247 &= ~ V_251 ;
F_136 ( V_14 , V_14 -> V_247 ) ;
F_80 ( & V_14 -> V_81 , V_43 ) ;
F_94 ( V_14 , V_29 ,
F_129 ( V_14 , V_29 ) & ~ V_257 ) ;
F_40 ( V_2 ) ;
#ifdef F_81
F_64 ( V_2 ) ;
#endif
F_129 ( V_14 , V_94 ) ;
F_47 ( V_2 ) ;
V_2 -> V_294 -> V_302 ( V_2 ) ;
}
static void F_153 ( struct V_6 * V_14 )
{
if ( V_14 -> V_303 )
V_14 -> V_303 ( V_14 ) ;
else
F_150 ( V_14 ) ;
}
static unsigned int F_154 ( struct V_1 * V_2 ,
unsigned int V_304 ,
unsigned int * V_305 )
{
struct V_6 * V_14 = & V_2 -> V_14 ;
unsigned int V_306 ;
V_306 = F_155 ( V_14 -> V_78 , V_304 ) ;
* V_305 = V_306 & 0x0f ;
return V_306 >> 4 ;
}
static unsigned int F_156 ( struct V_1 * V_2 ,
unsigned int V_304 ,
unsigned int * V_305 )
{
struct V_6 * V_14 = & V_2 -> V_14 ;
unsigned int V_124 ;
if ( ( V_14 -> V_43 & V_307 ) &&
V_304 == ( V_14 -> V_78 / 4 ) )
V_124 = 0x8001 ;
else if ( ( V_14 -> V_43 & V_307 ) &&
V_304 == ( V_14 -> V_78 / 8 ) )
V_124 = 0x8002 ;
else if ( V_2 -> V_14 . type == V_63 )
V_124 = F_154 ( V_2 , V_304 , V_305 ) ;
else
V_124 = F_157 ( V_14 , V_304 ) ;
if ( V_2 -> V_105 & V_106 && ( V_124 & 0xff ) == 0 )
V_124 ++ ;
return V_124 ;
}
static unsigned char F_158 ( struct V_1 * V_2 ,
T_1 V_308 )
{
unsigned char V_309 ;
switch ( V_308 & V_310 ) {
case V_311 :
V_309 = V_312 ;
break;
case V_313 :
V_309 = V_314 ;
break;
case V_315 :
V_309 = V_316 ;
break;
default:
case V_317 :
V_309 = V_296 ;
break;
}
if ( V_308 & V_318 )
V_309 |= V_319 ;
if ( V_308 & V_320 ) {
V_309 |= V_321 ;
if ( V_2 -> V_105 & V_322 )
V_2 -> V_323 = true ;
}
if ( ! ( V_308 & V_324 ) )
V_309 |= V_325 ;
#ifdef F_159
if ( V_308 & F_159 )
V_309 |= V_326 ;
#endif
return V_309 ;
}
static void F_160 ( struct V_6 * V_14 , unsigned int V_304 ,
unsigned int V_124 , unsigned int V_327 )
{
struct V_1 * V_2 = F_35 ( V_14 ) ;
if ( F_161 ( V_2 ) ) {
if ( V_304 == 115200 ) {
V_124 = 1 ;
F_94 ( V_14 , V_328 , 1 ) ;
} else
F_94 ( V_14 , V_328 , 0 ) ;
}
if ( V_2 -> V_35 & V_126 )
F_94 ( V_14 , V_29 , 0xe0 ) ;
else
F_94 ( V_14 , V_29 , V_2 -> V_61 | V_329 ) ;
F_67 ( V_2 , V_124 ) ;
if ( V_2 -> V_14 . type == V_63 )
F_94 ( V_14 , 0x2 , V_327 ) ;
}
static unsigned int F_162 ( struct V_6 * V_14 ,
struct V_330 * V_331 ,
struct V_330 * V_332 )
{
return F_163 ( V_14 , V_331 , V_332 ,
V_14 -> V_78 / 16 / 0xffff ,
V_14 -> V_78 ) ;
}
void
F_164 ( struct V_6 * V_14 , struct V_330 * V_331 ,
struct V_330 * V_332 )
{
struct V_1 * V_2 = F_35 ( V_14 ) ;
unsigned char V_309 ;
unsigned long V_43 ;
unsigned int V_304 , V_124 , V_305 = 0 ;
if ( V_2 -> V_35 & V_215 ) {
V_331 -> V_308 &= ~ ( V_318 | V_320 | V_324 | F_159 ) ;
if ( ( V_331 -> V_308 & V_310 ) == V_311 ||
( V_331 -> V_308 & V_310 ) == V_313 )
V_331 -> V_308 = ( V_331 -> V_308 & ~ V_310 ) | V_315 ;
}
V_309 = F_158 ( V_2 , V_331 -> V_308 ) ;
V_304 = F_162 ( V_14 , V_331 , V_332 ) ;
V_124 = F_156 ( V_2 , V_304 , & V_305 ) ;
F_45 ( V_2 ) ;
F_78 ( & V_14 -> V_81 , V_43 ) ;
V_2 -> V_61 = V_309 ;
if ( V_2 -> V_35 & V_36 && V_14 -> V_146 > 1 ) {
if ( ( V_304 < 2400 && ! V_2 -> V_175 ) || V_2 -> V_323 ) {
V_2 -> V_46 &= ~ V_333 ;
V_2 -> V_46 |= V_334 ;
}
}
if ( V_2 -> V_35 & V_119 ) {
V_2 -> V_41 &= ~ V_335 ;
if ( V_331 -> V_308 & V_336 )
V_2 -> V_41 |= V_335 ;
}
F_165 ( V_14 , V_331 -> V_308 , V_304 ) ;
V_14 -> V_165 = V_199 | V_180 | V_93 ;
if ( V_331 -> V_337 & V_338 )
V_14 -> V_165 |= V_194 | V_195 ;
if ( V_331 -> V_337 & ( V_339 | V_340 | V_341 ) )
V_14 -> V_165 |= V_193 ;
V_14 -> V_342 = 0 ;
if ( V_331 -> V_337 & V_343 )
V_14 -> V_342 |= V_195 | V_194 ;
if ( V_331 -> V_337 & V_339 ) {
V_14 -> V_342 |= V_193 ;
if ( V_331 -> V_337 & V_343 )
V_14 -> V_342 |= V_199 ;
}
if ( ( V_331 -> V_308 & V_344 ) == 0 )
V_14 -> V_342 |= V_93 ;
V_2 -> V_162 &= ~ V_186 ;
if ( ! ( V_2 -> V_105 & V_185 ) &&
F_166 ( & V_2 -> V_14 , V_331 -> V_308 ) )
V_2 -> V_162 |= V_186 ;
if ( V_2 -> V_35 & V_130 )
V_2 -> V_162 |= V_128 ;
if ( V_2 -> V_35 & V_131 )
V_2 -> V_162 |= V_345 ;
F_94 ( V_14 , V_72 , V_2 -> V_162 ) ;
if ( V_2 -> V_35 & V_68 ) {
unsigned char V_62 = 0 ;
if ( V_331 -> V_308 & V_336 )
V_62 |= V_346 ;
F_94 ( V_14 , V_29 , V_70 ) ;
if ( V_14 -> V_43 & V_117 )
F_94 ( V_14 , V_272 , V_62 ) ;
else
F_94 ( V_14 , V_69 , V_62 ) ;
}
F_160 ( V_14 , V_304 , V_124 , V_305 ) ;
if ( V_14 -> type == V_127 )
F_94 ( V_14 , V_37 , V_2 -> V_46 ) ;
F_94 ( V_14 , V_29 , V_2 -> V_61 ) ;
if ( V_14 -> type != V_127 ) {
if ( V_2 -> V_46 & V_38 )
F_94 ( V_14 , V_37 , V_38 ) ;
F_94 ( V_14 , V_37 , V_2 -> V_46 ) ;
}
F_136 ( V_14 , V_14 -> V_247 ) ;
F_80 ( & V_14 -> V_81 , V_43 ) ;
F_47 ( V_2 ) ;
if ( F_167 ( V_331 ) )
F_168 ( V_331 , V_304 , V_304 ) ;
}
static void
F_169 ( struct V_6 * V_14 , struct V_330 * V_331 ,
struct V_330 * V_332 )
{
if ( V_14 -> V_347 )
V_14 -> V_347 ( V_14 , V_331 , V_332 ) ;
else
F_164 ( V_14 , V_331 , V_332 ) ;
}
void F_170 ( struct V_6 * V_14 , struct V_330 * V_331 )
{
if ( V_331 -> V_348 == V_349 ) {
V_14 -> V_43 |= V_350 ;
F_62 ( & V_14 -> V_81 ) ;
F_108 ( V_14 ) ;
F_63 ( & V_14 -> V_81 ) ;
} else {
V_14 -> V_43 &= ~ V_350 ;
if ( ! F_166 ( V_14 , V_331 -> V_308 ) ) {
F_62 ( & V_14 -> V_81 ) ;
F_107 ( V_14 ) ;
F_63 ( & V_14 -> V_81 ) ;
}
}
}
static void
F_171 ( struct V_6 * V_14 , struct V_330 * V_331 )
{
if ( V_14 -> V_351 )
V_14 -> V_351 ( V_14 , V_331 ) ;
else
F_170 ( V_14 , V_331 ) ;
}
void F_172 ( struct V_6 * V_14 , unsigned int V_206 ,
unsigned int V_352 )
{
struct V_1 * V_7 = F_35 ( V_14 ) ;
F_59 ( V_7 , V_206 != 0 ) ;
}
static void
F_173 ( struct V_6 * V_14 , unsigned int V_206 ,
unsigned int V_352 )
{
if ( V_14 -> V_353 )
V_14 -> V_353 ( V_14 , V_206 , V_352 ) ;
else
F_172 ( V_14 , V_206 , V_352 ) ;
}
static unsigned int F_174 ( struct V_1 * V_354 )
{
if ( V_354 -> V_14 . V_355 )
return V_354 -> V_14 . V_355 ;
if ( V_354 -> V_14 . V_19 == V_25 ) {
if ( V_354 -> V_14 . type == V_356 )
return 0x100 ;
return 0x1000 ;
}
if ( F_175 ( V_354 ) )
return 0x16 << V_354 -> V_14 . V_12 ;
return 8 << V_354 -> V_14 . V_12 ;
}
static int F_176 ( struct V_1 * V_2 )
{
unsigned int V_357 = F_174 ( V_2 ) ;
struct V_6 * V_14 = & V_2 -> V_14 ;
int V_235 = 0 ;
switch ( V_14 -> V_19 ) {
case V_25 :
case V_358 :
case V_23 :
case V_24 :
case V_22 :
case V_21 :
if ( ! V_14 -> V_138 )
break;
if ( ! F_177 ( V_14 -> V_138 , V_357 , L_22 ) ) {
V_235 = - V_359 ;
break;
}
if ( V_14 -> V_43 & V_360 ) {
V_14 -> V_11 = F_178 ( V_14 -> V_138 , V_357 ) ;
if ( ! V_14 -> V_11 ) {
F_179 ( V_14 -> V_138 , V_357 ) ;
V_235 = - V_52 ;
}
}
break;
case V_20 :
case V_151 :
if ( ! F_180 ( V_14 -> V_16 , V_357 , L_22 ) )
V_235 = - V_359 ;
break;
}
return V_235 ;
}
static void F_181 ( struct V_1 * V_2 )
{
unsigned int V_357 = F_174 ( V_2 ) ;
struct V_6 * V_14 = & V_2 -> V_14 ;
switch ( V_14 -> V_19 ) {
case V_25 :
case V_358 :
case V_23 :
case V_24 :
case V_22 :
case V_21 :
if ( ! V_14 -> V_138 )
break;
if ( V_14 -> V_43 & V_360 ) {
F_182 ( V_14 -> V_11 ) ;
V_14 -> V_11 = NULL ;
}
F_179 ( V_14 -> V_138 , V_357 ) ;
break;
case V_20 :
case V_151 :
F_183 ( V_14 -> V_16 , V_357 ) ;
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
const struct V_361 * V_362 = & V_147 [ V_2 -> V_14 . type ] ;
unsigned char V_363 ;
V_363 = V_362 -> V_364 [ F_187 ( V_2 -> V_46 ) ] ;
return V_363 ? V_363 : - V_365 ;
}
static int F_188 ( struct V_1 * V_2 , unsigned char V_363 )
{
const struct V_361 * V_362 = & V_147 [ V_2 -> V_14 . type ] ;
int V_366 ;
if ( ! V_362 -> V_364 [ F_187 ( V_367 ) ] )
return - V_365 ;
for ( V_366 = 1 ; V_366 < V_368 ; V_366 ++ ) {
if ( V_363 < V_362 -> V_364 [ V_366 ] )
return ( -- V_366 ) << V_369 ;
}
return V_370 ;
}
static int F_189 ( struct V_371 * V_14 )
{
struct V_372 * V_206 = F_190 ( V_14 , struct V_372 , V_14 ) ;
struct V_6 * V_373 = V_206 -> V_6 ;
struct V_1 * V_2 = F_35 ( V_373 ) ;
if ( ! ( V_2 -> V_35 & V_36 ) || V_373 -> V_146 <= 1 )
return - V_374 ;
return F_186 ( V_2 ) ;
}
static int F_191 ( struct V_371 * V_14 )
{
int V_364 ;
F_192 ( & V_14 -> V_375 ) ;
V_364 = F_189 ( V_14 ) ;
F_193 ( & V_14 -> V_375 ) ;
return V_364 ;
}
static T_2 F_194 ( struct V_376 * V_48 ,
struct V_377 * V_378 , char * V_211 )
{
struct V_371 * V_14 = F_195 ( V_48 ) ;
int V_364 ;
V_364 = F_191 ( V_14 ) ;
if ( V_364 < 0 )
return V_364 ;
return snprintf ( V_211 , V_379 , L_23 , V_364 ) ;
}
static int F_196 ( struct V_371 * V_14 , unsigned char V_363 )
{
struct V_372 * V_206 = F_190 ( V_14 , struct V_372 , V_14 ) ;
struct V_6 * V_373 = V_206 -> V_6 ;
struct V_1 * V_2 = F_35 ( V_373 ) ;
int V_380 ;
if ( ! ( V_2 -> V_35 & V_36 ) || V_373 -> V_146 <= 1 ||
V_2 -> V_323 )
return - V_374 ;
V_380 = F_188 ( V_2 , V_363 ) ;
if ( V_380 < 0 )
return V_380 ;
F_40 ( V_2 ) ;
V_2 -> V_46 &= ~ V_333 ;
V_2 -> V_46 |= ( unsigned char ) V_380 ;
F_4 ( V_2 , V_37 , V_2 -> V_46 ) ;
return 0 ;
}
static int F_197 ( struct V_371 * V_14 , unsigned char V_363 )
{
int V_235 ;
F_192 ( & V_14 -> V_375 ) ;
V_235 = F_196 ( V_14 , V_363 ) ;
F_193 ( & V_14 -> V_375 ) ;
return V_235 ;
}
static T_2 F_198 ( struct V_376 * V_48 ,
struct V_377 * V_378 , const char * V_211 , T_3 V_88 )
{
struct V_371 * V_14 = F_195 ( V_48 ) ;
unsigned char V_363 ;
int V_235 ;
if ( ! V_88 )
return - V_374 ;
V_235 = F_199 ( V_211 , 10 , & V_363 ) ;
if ( V_235 < 0 )
return V_235 ;
V_235 = F_197 ( V_14 , V_363 ) ;
if ( V_235 < 0 )
return V_235 ;
return V_88 ;
}
static void F_200 ( struct V_1 * V_2 )
{
const struct V_361 * V_362 = & V_147 [ V_2 -> V_14 . type ] ;
if ( V_362 -> V_364 [ 0 ] )
V_2 -> V_14 . V_381 = & V_382 ;
}
static void F_201 ( struct V_6 * V_14 , int V_43 )
{
struct V_1 * V_2 = F_35 ( V_14 ) ;
int V_235 ;
V_235 = F_176 ( V_2 ) ;
if ( V_235 < 0 )
return;
if ( V_14 -> V_19 != V_2 -> V_26 )
F_34 ( V_14 ) ;
if ( V_43 & V_383 )
F_76 ( V_2 ) ;
if ( V_14 -> type == V_116 && V_14 -> V_19 == V_25 )
V_2 -> V_105 |= V_185 ;
if ( V_14 -> type == V_384 )
V_2 -> V_105 |= V_185 ;
if ( V_14 -> type != V_142 && V_43 & V_385 )
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
F_202 ( struct V_6 * V_14 , struct V_386 * V_387 )
{
if ( V_387 -> V_157 >= V_388 || V_387 -> V_157 < 0 ||
V_387 -> V_389 < 9600 || V_387 -> type < V_142 ||
V_387 -> type >= F_6 ( V_147 ) || V_387 -> type == V_390 ||
V_387 -> type == V_391 )
return - V_374 ;
return 0 ;
}
static const char * F_203 ( struct V_6 * V_14 )
{
int type = V_14 -> type ;
if ( type >= F_6 ( V_147 ) )
type = 0 ;
return V_147 [ type ] . V_152 ;
}
void F_204 ( struct V_1 * V_2 )
{
struct V_6 * V_14 = & V_2 -> V_14 ;
F_205 ( & V_14 -> V_81 ) ;
V_14 -> V_294 = & V_392 ;
V_2 -> V_26 = 0xFF ;
}
void F_206 ( struct V_1 * V_2 )
{
struct V_6 * V_14 = & V_2 -> V_14 ;
if ( V_2 -> V_14 . V_43 & V_393 ) {
unsigned int type = V_2 -> V_14 . type ;
if ( ! V_2 -> V_14 . V_146 )
V_2 -> V_14 . V_146 = V_147 [ type ] . V_148 ;
if ( ! V_2 -> V_149 )
V_2 -> V_149 = V_147 [ type ] . V_149 ;
if ( ! V_2 -> V_35 )
V_2 -> V_35 = V_147 [ type ] . V_43 ;
}
F_34 ( V_14 ) ;
if ( V_2 -> V_175 ) {
if ( ! V_2 -> V_175 -> V_176 )
V_2 -> V_175 -> V_176 = V_394 ;
if ( ! V_2 -> V_175 -> V_232 )
V_2 -> V_175 -> V_232 = V_395 ;
}
}
static void F_207 ( struct V_6 * V_14 , int V_187 )
{
struct V_1 * V_2 = F_35 ( V_14 ) ;
F_138 ( V_2 , V_180 ) ;
F_94 ( V_14 , V_91 , V_187 ) ;
}
static void F_208 ( struct V_1 * V_2 )
{
struct V_6 * V_14 = & V_2 -> V_14 ;
struct V_330 V_331 ;
unsigned int V_304 , V_124 , V_305 = 0 ;
V_331 . V_308 = V_14 -> V_396 -> V_397 ;
if ( V_14 -> V_206 -> V_14 . V_398 && V_331 . V_308 == 0 )
V_331 . V_308 = V_14 -> V_206 -> V_14 . V_398 -> V_331 . V_308 ;
V_304 = F_162 ( V_14 , & V_331 , NULL ) ;
V_124 = F_156 ( V_2 , V_304 , & V_305 ) ;
F_160 ( V_14 , V_304 , V_124 , V_305 ) ;
F_94 ( V_14 , V_29 , V_2 -> V_61 ) ;
F_43 ( V_2 , V_161 | V_45 ) ;
}
void F_209 ( struct V_1 * V_2 , const char * V_399 ,
unsigned int V_88 )
{
struct V_6 * V_14 = & V_2 -> V_14 ;
unsigned long V_43 ;
unsigned int V_162 ;
int V_400 = 1 ;
F_139 () ;
F_45 ( V_2 ) ;
if ( V_14 -> V_401 )
V_400 = 0 ;
else if ( V_402 )
V_400 = F_210 ( & V_14 -> V_81 , V_43 ) ;
else
F_78 ( & V_14 -> V_81 , V_43 ) ;
V_162 = F_129 ( V_14 , V_72 ) ;
if ( V_2 -> V_35 & V_130 )
F_94 ( V_14 , V_72 , V_128 ) ;
else
F_94 ( V_14 , V_72 , 0 ) ;
if ( V_2 -> V_403 && ( V_2 -> V_403 != F_129 ( V_14 , V_30 ) ) ) {
F_208 ( V_2 ) ;
V_2 -> V_403 = 0 ;
}
F_211 ( V_14 , V_399 , V_88 , F_207 ) ;
F_138 ( V_2 , V_173 ) ;
F_94 ( V_14 , V_72 , V_162 ) ;
if ( V_2 -> V_218 )
F_122 ( V_2 ) ;
if ( V_400 )
F_80 ( & V_14 -> V_81 , V_43 ) ;
F_47 ( V_2 ) ;
}
static unsigned int F_212 ( struct V_6 * V_14 )
{
unsigned char V_61 , V_404 , V_405 ;
unsigned int V_124 ;
V_61 = F_129 ( V_14 , V_29 ) ;
F_94 ( V_14 , V_29 , V_61 | V_329 ) ;
V_404 = F_129 ( V_14 , V_3 ) ;
V_405 = F_129 ( V_14 , V_4 ) ;
F_94 ( V_14 , V_29 , V_61 ) ;
V_124 = ( V_405 << 8 ) | V_404 ;
return ( V_14 -> V_78 / 16 ) / V_124 ;
}
int F_213 ( struct V_6 * V_14 , char * V_406 , bool V_144 )
{
int V_304 = 9600 ;
int V_258 = 8 ;
int V_197 = 'n' ;
int V_407 = 'n' ;
if ( ! V_14 -> V_16 && ! V_14 -> V_11 )
return - V_274 ;
if ( V_406 )
F_214 ( V_406 , & V_304 , & V_197 , & V_258 , & V_407 ) ;
else if ( V_144 )
V_304 = F_212 ( V_14 ) ;
return F_215 ( V_14 , V_14 -> V_396 , V_304 , V_197 , V_258 , V_407 ) ;
}
