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
unsigned char V_41 = F_2 ( V_7 , V_42 ) ;
if ( V_7 -> V_14 . V_43 . V_44 & V_45 )
V_41 |= V_46 ;
else
V_41 &= ~ V_46 ;
F_4 ( V_7 , V_42 , V_41 ) ;
}
void F_42 ( struct V_1 * V_7 )
{
F_40 ( V_7 ) ;
F_4 ( V_7 , V_37 , V_7 -> V_47 ) ;
}
void F_43 ( struct V_1 * V_7 )
{
if ( ! ( V_7 -> V_35 & V_48 ) )
return;
F_44 ( V_7 -> V_14 . V_49 ) ;
}
void F_45 ( struct V_1 * V_7 )
{
if ( ! ( V_7 -> V_35 & V_48 ) )
return;
F_46 ( V_7 -> V_14 . V_49 ) ;
F_47 ( V_7 -> V_14 . V_49 ) ;
}
int F_48 ( struct V_1 * V_7 )
{
if ( V_7 -> V_50 != NULL )
return 0 ;
V_7 -> V_50 = F_49 ( sizeof( struct V_51 ) , V_52 ) ;
if ( V_7 -> V_50 == NULL )
return - V_53 ;
F_50 ( & V_7 -> V_50 -> V_54 ,
V_55 , ( unsigned long ) V_7 ) ;
F_50 ( & V_7 -> V_50 -> V_56 ,
V_57 , ( unsigned long ) V_7 ) ;
V_7 -> V_50 -> V_58 = NULL ;
F_41 ( V_7 ) ;
return 0 ;
}
void F_51 ( struct V_1 * V_7 )
{
if ( V_7 -> V_50 == NULL )
return;
F_52 ( & V_7 -> V_50 -> V_56 ) ;
F_52 ( & V_7 -> V_50 -> V_54 ) ;
F_53 ( V_7 -> V_50 ) ;
V_7 -> V_50 = NULL ;
}
static void F_54 ( struct V_1 * V_7 )
{
unsigned char V_59 ;
if ( ! ( V_7 -> V_35 & V_48 ) )
return;
V_59 = F_55 ( & V_7 -> V_60 , 1 ) ;
if ( V_59 )
return;
F_44 ( V_7 -> V_14 . V_49 ) ;
}
static void F_56 ( struct V_1 * V_7 )
{
unsigned char V_59 ;
if ( ! ( V_7 -> V_35 & V_48 ) )
return;
V_59 = F_55 ( & V_7 -> V_60 , 0 ) ;
if ( ! V_59 )
return;
F_46 ( V_7 -> V_14 . V_49 ) ;
F_47 ( V_7 -> V_14 . V_49 ) ;
}
static void F_57 ( struct V_1 * V_7 , int V_61 )
{
unsigned char V_62 = 0 , V_63 = 0 ;
F_43 ( V_7 ) ;
if ( ( V_7 -> V_14 . type == V_64 ) ||
( V_7 -> V_14 . type == V_65 ) ) {
F_4 ( V_7 , V_66 , V_61 ? 0xff : 0 ) ;
goto V_67;
}
if ( V_7 -> V_35 & V_68 ) {
if ( V_7 -> V_35 & V_69 ) {
V_62 = F_2 ( V_7 , V_29 ) ;
V_63 = F_2 ( V_7 , V_70 ) ;
F_4 ( V_7 , V_29 , V_71 ) ;
F_4 ( V_7 , V_70 , V_72 ) ;
F_4 ( V_7 , V_29 , 0 ) ;
}
F_4 ( V_7 , V_73 , V_61 ? V_74 : 0 ) ;
if ( V_7 -> V_35 & V_69 ) {
F_4 ( V_7 , V_29 , V_71 ) ;
F_4 ( V_7 , V_70 , V_63 ) ;
F_4 ( V_7 , V_29 , V_62 ) ;
}
}
V_67:
F_45 ( V_7 ) ;
}
static int F_58 ( struct V_1 * V_2 )
{
unsigned char V_75 ;
int V_76 ;
V_75 = F_2 ( V_2 , V_77 ) ;
V_76 = V_75 & V_78 ;
if ( ! V_76 ) {
F_4 ( V_2 , V_77 , V_75 | V_78 ) ;
V_75 = F_2 ( V_2 , V_77 ) ;
V_76 = V_75 & V_78 ;
}
if ( V_76 )
V_2 -> V_14 . V_79 = V_80 * 16 ;
return V_76 ;
}
static void F_59 ( struct V_1 * V_2 )
{
if ( V_2 -> V_14 . type == V_81 ) {
if ( V_2 -> V_14 . V_79 != V_80 * 16 ) {
F_60 ( & V_2 -> V_14 . V_82 ) ;
F_58 ( V_2 ) ;
F_61 ( & V_2 -> V_14 . V_82 ) ;
}
if ( V_2 -> V_14 . V_79 == V_80 * 16 )
F_4 ( V_2 , V_83 , 0 ) ;
}
}
static void F_62 ( struct V_1 * V_2 )
{
unsigned char V_75 ;
int V_76 ;
if ( V_2 -> V_14 . type == V_81 &&
V_2 -> V_14 . V_79 == V_80 * 16 ) {
F_60 ( & V_2 -> V_14 . V_82 ) ;
V_75 = F_2 ( V_2 , V_77 ) ;
V_76 = ! ( V_75 & V_78 ) ;
if ( ! V_76 ) {
F_4 ( V_2 , V_77 , V_75 & ~ V_78 ) ;
V_75 = F_2 ( V_2 , V_77 ) ;
V_76 = ! ( V_75 & V_78 ) ;
}
if ( V_76 )
V_2 -> V_14 . V_79 = V_84 * 16 ;
F_61 ( & V_2 -> V_14 . V_82 ) ;
}
}
static int F_63 ( struct V_1 * V_2 )
{
unsigned char V_85 , V_86 , V_87 ;
unsigned short V_88 ;
int V_89 ;
V_87 = F_2 ( V_2 , V_29 ) ;
F_4 ( V_2 , V_29 , 0 ) ;
V_85 = F_2 ( V_2 , V_37 ) ;
V_86 = F_2 ( V_2 , V_42 ) ;
F_4 ( V_2 , V_37 , V_38 |
V_39 | V_40 ) ;
F_4 ( V_2 , V_42 , V_90 ) ;
F_4 ( V_2 , V_29 , V_91 ) ;
V_88 = F_64 ( V_2 ) ;
F_65 ( V_2 , 0x0001 ) ;
F_4 ( V_2 , V_29 , 0x03 ) ;
for ( V_89 = 0 ; V_89 < 256 ; V_89 ++ )
F_4 ( V_2 , V_92 , V_89 ) ;
F_66 ( 20 ) ;
for ( V_89 = 0 ; ( F_2 ( V_2 , V_93 ) & V_94 ) &&
( V_89 < 256 ) ; V_89 ++ )
F_2 ( V_2 , V_95 ) ;
F_4 ( V_2 , V_37 , V_85 ) ;
F_4 ( V_2 , V_42 , V_86 ) ;
F_4 ( V_2 , V_29 , V_91 ) ;
F_65 ( V_2 , V_88 ) ;
F_4 ( V_2 , V_29 , V_87 ) ;
return V_89 ;
}
static unsigned int F_67 ( struct V_1 * V_7 )
{
unsigned char V_87 ;
unsigned int V_96 , V_88 ;
V_87 = F_2 ( V_7 , V_29 ) ;
F_4 ( V_7 , V_29 , V_91 ) ;
V_88 = F_64 ( V_7 ) ;
F_65 ( V_7 , 0 ) ;
V_96 = F_64 ( V_7 ) ;
F_65 ( V_7 , V_88 ) ;
F_4 ( V_7 , V_29 , V_87 ) ;
return V_96 ;
}
static void F_68 ( struct V_1 * V_2 )
{
unsigned int V_97 , V_98 , V_99 , V_100 ;
V_2 -> V_35 |= V_69 | V_68 ;
V_2 -> V_33 = 0 ;
F_4 ( V_2 , V_29 , V_71 ) ;
F_4 ( V_2 , V_70 , V_72 ) ;
F_4 ( V_2 , V_29 , 0x00 ) ;
V_97 = F_39 ( V_2 , V_101 ) ;
V_98 = F_39 ( V_2 , V_102 ) ;
V_99 = F_39 ( V_2 , V_103 ) ;
V_100 = F_39 ( V_2 , V_104 ) ;
F_69 ( L_1 , V_97 , V_98 , V_99 , V_100 ) ;
if ( V_97 == 0x16 && V_98 == 0xC9 &&
( V_99 == 0x50 || V_99 == 0x52 || V_99 == 0x54 ) ) {
V_2 -> V_14 . type = V_105 ;
if ( V_99 == 0x52 && V_100 == 0x01 )
V_2 -> V_106 |= V_107 ;
return;
}
V_97 = F_67 ( V_2 ) ;
F_69 ( L_2 , V_97 ) ;
V_98 = V_97 >> 8 ;
if ( V_98 == 0x10 || V_98 == 0x12 || V_98 == 0x14 ) {
V_2 -> V_14 . type = V_108 ;
return;
}
if ( F_63 ( V_2 ) == 64 )
V_2 -> V_14 . type = V_109 ;
else
V_2 -> V_14 . type = V_110 ;
}
static void F_70 ( struct V_1 * V_2 )
{
unsigned char V_111 , V_112 , V_113 ;
V_2 -> V_14 . type = V_114 ;
V_111 = F_2 ( V_2 , V_30 ) ;
F_4 ( V_2 , V_30 , 0xa5 ) ;
V_112 = F_2 ( V_2 , V_30 ) ;
F_4 ( V_2 , V_30 , 0x5a ) ;
V_113 = F_2 ( V_2 , V_30 ) ;
F_4 ( V_2 , V_30 , V_111 ) ;
if ( V_112 == 0xa5 && V_113 == 0x5a )
V_2 -> V_14 . type = V_115 ;
}
static int F_71 ( struct V_1 * V_2 )
{
if ( F_67 ( V_2 ) == 0x0201 && F_63 ( V_2 ) == 16 )
return 1 ;
return 0 ;
}
static void F_72 ( struct V_1 * V_2 )
{
unsigned char V_112 , V_113 ;
unsigned int V_116 ;
V_2 -> V_14 . type = V_117 ;
V_2 -> V_35 |= V_36 ;
if ( V_2 -> V_14 . V_44 & V_118 ) {
V_112 = F_2 ( V_2 , V_119 ) ;
if ( V_112 == 0x82 || V_112 == 0x84 || V_112 == 0x88 ) {
F_69 ( L_3 ) ;
V_2 -> V_14 . type = V_64 ;
V_2 -> V_35 |= V_120 | V_69 |
V_68 ;
return;
}
}
F_4 ( V_2 , V_29 , V_91 ) ;
if ( F_2 ( V_2 , V_70 ) == 0 ) {
F_4 ( V_2 , V_70 , 0xA8 ) ;
if ( F_2 ( V_2 , V_70 ) != 0 ) {
F_69 ( L_4 ) ;
V_2 -> V_14 . type = V_121 ;
V_2 -> V_35 |= V_69 | V_68 ;
} else {
F_4 ( V_2 , V_29 , 0 ) ;
F_4 ( V_2 , V_37 , V_38 |
V_122 ) ;
V_112 = F_2 ( V_2 , V_123 ) >> 5 ;
F_4 ( V_2 , V_37 , 0 ) ;
F_4 ( V_2 , V_29 , 0 ) ;
if ( V_112 == 7 )
V_2 -> V_14 . type = V_124 ;
else
F_69 ( L_5 ) ;
}
F_4 ( V_2 , V_70 , 0 ) ;
return;
}
F_4 ( V_2 , V_29 , V_71 ) ;
if ( F_2 ( V_2 , V_70 ) == 0 && ! F_71 ( V_2 ) ) {
F_69 ( L_6 ) ;
F_68 ( V_2 ) ;
return;
}
F_4 ( V_2 , V_29 , 0 ) ;
V_112 = F_2 ( V_2 , V_42 ) ;
F_4 ( V_2 , V_29 , 0xE0 ) ;
V_113 = F_2 ( V_2 , 0x02 ) ;
if ( ! ( ( V_113 ^ V_112 ) & V_90 ) ) {
F_4 ( V_2 , V_29 , 0 ) ;
F_4 ( V_2 , V_42 , V_112 ^ V_90 ) ;
F_4 ( V_2 , V_29 , 0xE0 ) ;
V_113 = F_2 ( V_2 , 0x02 ) ;
F_4 ( V_2 , V_29 , 0 ) ;
F_4 ( V_2 , V_42 , V_112 ) ;
if ( ( V_113 ^ V_112 ) & V_90 ) {
unsigned short V_125 ;
F_4 ( V_2 , V_29 , 0xE0 ) ;
V_125 = F_64 ( V_2 ) ;
V_125 <<= 3 ;
if ( F_73 ( V_2 ) )
F_65 ( V_2 , V_125 ) ;
F_4 ( V_2 , V_29 , 0 ) ;
V_2 -> V_14 . V_79 = 921600 * 16 ;
V_2 -> V_14 . type = V_126 ;
V_2 -> V_35 |= V_127 ;
return;
}
}
F_4 ( V_2 , V_29 , 0 ) ;
F_4 ( V_2 , V_37 , V_38 | V_122 ) ;
V_112 = F_2 ( V_2 , V_123 ) >> 5 ;
F_4 ( V_2 , V_37 , V_38 ) ;
F_4 ( V_2 , V_29 , V_91 ) ;
F_4 ( V_2 , V_37 , V_38 | V_122 ) ;
V_113 = F_2 ( V_2 , V_123 ) >> 5 ;
F_4 ( V_2 , V_37 , V_38 ) ;
F_4 ( V_2 , V_29 , 0 ) ;
F_69 ( L_7 , V_112 , V_113 ) ;
if ( V_112 == 6 && V_113 == 7 ) {
V_2 -> V_14 . type = V_128 ;
V_2 -> V_35 |= V_120 | V_68 ;
return;
}
V_116 = F_2 ( V_2 , V_73 ) ;
F_4 ( V_2 , V_73 , V_116 & ~ V_129 ) ;
if ( ! ( F_2 ( V_2 , V_73 ) & V_129 ) ) {
F_4 ( V_2 , V_73 , V_116 | V_129 ) ;
if ( F_2 ( V_2 , V_73 ) & V_129 ) {
F_69 ( L_8 ) ;
V_2 -> V_14 . type = V_130 ;
V_2 -> V_35 |= V_131 | V_132 ;
return;
}
} else {
F_69 ( L_9 ) ;
}
F_4 ( V_2 , V_73 , V_116 ) ;
if ( V_2 -> V_14 . V_44 & V_118 ) {
F_69 ( L_10 ) ;
V_2 -> V_14 . type = V_65 ;
V_2 -> V_35 |= V_120 | V_69 |
V_68 ;
return;
}
if ( V_2 -> V_14 . type == V_117 && F_63 ( V_2 ) == 64 ) {
V_2 -> V_14 . type = V_133 ;
V_2 -> V_35 |= V_120 ;
}
}
static void F_74 ( struct V_1 * V_2 )
{
unsigned char V_112 , V_111 , V_134 , V_135 ;
unsigned char V_136 , V_137 ;
struct V_6 * V_14 = & V_2 -> V_14 ;
unsigned long V_44 ;
unsigned int V_138 ;
if ( ! V_14 -> V_16 && ! V_14 -> V_139 && ! V_14 -> V_11 )
return;
F_69 ( L_11 ,
F_75 ( V_14 ) , V_14 -> V_16 , V_14 -> V_11 ) ;
F_76 ( & V_14 -> V_82 , V_44 ) ;
V_2 -> V_35 = 0 ;
V_2 -> V_106 = 0 ;
if ( ! ( V_14 -> V_44 & V_140 ) ) {
V_111 = F_2 ( V_2 , V_73 ) ;
F_4 ( V_2 , V_73 , 0 ) ;
#ifdef F_77
F_13 ( 0xff , 0x080 ) ;
#endif
V_134 = F_2 ( V_2 , V_73 ) & 0x0f ;
F_4 ( V_2 , V_73 , 0x0F ) ;
#ifdef F_77
F_13 ( 0 , 0x080 ) ;
#endif
V_135 = F_2 ( V_2 , V_73 ) & 0x0f ;
F_4 ( V_2 , V_73 , V_111 ) ;
if ( V_134 != 0 || V_135 != 0x0F ) {
F_78 ( & V_14 -> V_82 , V_44 ) ;
F_69 ( L_12 ,
V_134 , V_135 ) ;
goto V_67;
}
}
V_137 = F_2 ( V_2 , V_42 ) ;
V_136 = F_2 ( V_2 , V_29 ) ;
if ( ! ( V_14 -> V_44 & V_141 ) ) {
F_4 ( V_2 , V_42 , V_90 | 0x0A ) ;
V_112 = F_2 ( V_2 , V_142 ) & 0xF0 ;
F_4 ( V_2 , V_42 , V_137 ) ;
if ( V_112 != 0x90 ) {
F_78 ( & V_14 -> V_82 , V_44 ) ;
F_69 ( L_13 ,
V_112 ) ;
goto V_67;
}
}
F_4 ( V_2 , V_29 , V_71 ) ;
F_4 ( V_2 , V_70 , 0 ) ;
F_4 ( V_2 , V_29 , 0 ) ;
F_4 ( V_2 , V_37 , V_38 ) ;
V_111 = F_2 ( V_2 , V_123 ) >> 6 ;
switch ( V_111 ) {
case 0 :
F_70 ( V_2 ) ;
break;
case 1 :
V_14 -> type = V_143 ;
break;
case 2 :
V_14 -> type = V_144 ;
break;
case 3 :
F_72 ( V_2 ) ;
break;
}
#ifdef F_79
if ( V_14 -> type == V_117 && V_2 -> V_145 & V_146 &&
F_58 ( V_2 ) )
V_14 -> type = V_81 ;
#endif
F_4 ( V_2 , V_29 , V_136 ) ;
V_14 -> V_147 = V_148 [ V_2 -> V_14 . type ] . V_149 ;
V_138 = V_2 -> V_35 ;
V_2 -> V_35 = V_148 [ V_14 -> type ] . V_44 ;
V_2 -> V_150 = V_148 [ V_14 -> type ] . V_150 ;
if ( V_14 -> type == V_143 )
goto V_151;
#ifdef F_79
if ( V_14 -> type == V_81 )
F_4 ( V_2 , V_83 , 0 ) ;
#endif
F_4 ( V_2 , V_42 , V_137 ) ;
F_40 ( V_2 ) ;
F_2 ( V_2 , V_95 ) ;
if ( V_2 -> V_35 & V_131 )
F_4 ( V_2 , V_73 , V_129 ) ;
else
F_4 ( V_2 , V_73 , 0 ) ;
V_151:
F_78 ( & V_14 -> V_82 , V_44 ) ;
if ( V_2 -> V_35 != V_138 ) {
F_80 ( L_14 ,
F_75 ( V_14 ) , V_138 ,
V_2 -> V_35 ) ;
}
V_67:
F_69 ( L_15 , V_111 ) ;
F_69 ( L_16 , V_148 [ V_14 -> type ] . V_152 ) ;
}
static void F_81 ( struct V_1 * V_2 )
{
struct V_6 * V_14 = & V_2 -> V_14 ;
unsigned char V_137 , V_153 ;
unsigned char V_154 = 0 ;
unsigned int V_155 = 0 ;
unsigned long V_156 ;
int V_157 ;
if ( V_14 -> V_44 & V_158 ) {
V_155 = ( V_14 -> V_16 & 0xfe0 ) | 0x1f ;
V_154 = F_82 ( V_155 ) ;
F_83 ( 0x80 , V_155 ) ;
F_82 ( V_155 ) ;
}
if ( F_84 ( V_14 ) )
F_85 () ;
F_86 ( F_87 () ) ;
V_137 = F_2 ( V_2 , V_42 ) ;
V_153 = F_2 ( V_2 , V_73 ) ;
F_4 ( V_2 , V_42 , V_159 | V_160 ) ;
V_156 = F_87 () ;
F_4 ( V_2 , V_42 , 0 ) ;
F_88 ( 10 ) ;
if ( V_14 -> V_44 & V_158 ) {
F_4 ( V_2 , V_42 ,
V_161 | V_46 ) ;
} else {
F_4 ( V_2 , V_42 ,
V_161 | V_46 | V_160 ) ;
}
F_4 ( V_2 , V_73 , 0x0f ) ;
F_2 ( V_2 , V_93 ) ;
F_2 ( V_2 , V_95 ) ;
F_2 ( V_2 , V_123 ) ;
F_2 ( V_2 , V_142 ) ;
F_4 ( V_2 , V_92 , 0xFF ) ;
F_88 ( 20 ) ;
V_157 = F_86 ( V_156 ) ;
F_4 ( V_2 , V_42 , V_137 ) ;
F_4 ( V_2 , V_73 , V_153 ) ;
if ( V_14 -> V_44 & V_158 )
F_83 ( V_154 , V_155 ) ;
if ( F_84 ( V_14 ) )
F_89 () ;
V_14 -> V_157 = ( V_157 > 0 ) ? V_157 : 0 ;
}
static void F_90 ( struct V_6 * V_14 )
{
struct V_1 * V_2 = F_35 ( V_14 ) ;
F_43 ( V_2 ) ;
V_2 -> V_162 &= ~ ( V_163 | V_164 ) ;
V_2 -> V_14 . V_165 &= ~ V_94 ;
F_91 ( V_14 , V_73 , V_2 -> V_162 ) ;
F_45 ( V_2 ) ;
}
static void F_92 ( struct V_1 * V_7 )
{
if ( ! V_7 -> V_50 )
return;
F_41 ( V_7 ) ;
if ( ! ( V_7 -> V_14 . V_43 . V_44 & V_166 ) ) {
F_40 ( V_7 ) ;
F_43 ( V_7 ) ;
V_7 -> V_162 |= V_163 | V_164 ;
F_91 ( & V_7 -> V_14 , V_73 , V_7 -> V_162 ) ;
F_45 ( V_7 ) ;
}
}
static void V_55 ( unsigned long V_167 )
{
struct V_1 * V_7 = (struct V_1 * ) V_167 ;
struct V_51 * V_50 = V_7 -> V_50 ;
unsigned long V_44 ;
F_76 ( & V_7 -> V_14 . V_82 , V_44 ) ;
if ( V_50 &&
V_50 -> V_58 == & V_50 -> V_54 ) {
F_92 ( V_7 ) ;
V_50 -> V_58 = NULL ;
}
F_78 ( & V_7 -> V_14 . V_82 , V_44 ) ;
}
static void F_93 ( struct V_1 * V_7 )
{
struct V_51 * V_50 = V_7 -> V_50 ;
if ( ! V_50 )
return;
if ( V_7 -> V_14 . V_43 . V_168 > 0 ) {
V_50 -> V_58 = & V_50 -> V_54 ;
F_94 ( & V_50 -> V_54 , V_169 +
V_7 -> V_14 . V_43 . V_168 * V_170 / 1000 ) ;
} else {
F_92 ( V_7 ) ;
}
}
static inline void F_95 ( struct V_1 * V_7 )
{
if ( V_7 -> V_162 & V_171 ) {
V_7 -> V_162 &= ~ V_171 ;
F_4 ( V_7 , V_73 , V_7 -> V_162 ) ;
F_56 ( V_7 ) ;
}
}
static inline void F_96 ( struct V_1 * V_7 )
{
struct V_51 * V_50 = V_7 -> V_50 ;
if ( V_50 ) {
unsigned char V_172 = F_2 ( V_7 , V_93 ) ;
if ( ( V_172 & V_173 ) != V_173 )
return;
F_52 ( & V_50 -> V_56 ) ;
V_50 -> V_58 = NULL ;
}
F_95 ( V_7 ) ;
F_93 ( V_7 ) ;
}
static void F_97 ( struct V_6 * V_14 )
{
struct V_1 * V_2 = F_35 ( V_14 ) ;
F_43 ( V_2 ) ;
F_96 ( V_2 ) ;
if ( V_14 -> type == V_105 ) {
V_2 -> V_33 |= V_174 ;
F_38 ( V_2 , V_32 , V_2 -> V_33 ) ;
}
F_45 ( V_2 ) ;
}
static inline void F_98 ( struct V_6 * V_14 )
{
struct V_1 * V_2 = F_35 ( V_14 ) ;
if ( V_2 -> V_175 && ! V_2 -> V_175 -> V_176 ( V_2 ) )
return;
if ( ! ( V_2 -> V_162 & V_171 ) ) {
V_2 -> V_162 |= V_171 ;
F_91 ( V_14 , V_73 , V_2 -> V_162 ) ;
if ( V_2 -> V_106 & V_177 ) {
unsigned char V_172 ;
V_172 = F_2 ( V_2 , V_93 ) ;
V_2 -> V_178 |= V_172 & V_179 ;
if ( V_172 & V_180 )
F_99 ( V_2 ) ;
}
}
if ( V_14 -> type == V_105 && V_2 -> V_33 & V_174 ) {
V_2 -> V_33 &= ~ V_174 ;
F_38 ( V_2 , V_32 , V_2 -> V_33 ) ;
}
}
static inline void F_100 ( struct V_6 * V_14 )
{
struct V_1 * V_2 = F_35 ( V_14 ) ;
struct V_51 * V_50 = V_2 -> V_50 ;
unsigned char V_41 ;
if ( ! ( V_2 -> V_14 . V_43 . V_44 & V_166 ) )
F_90 ( & V_2 -> V_14 ) ;
F_52 ( & V_50 -> V_54 ) ;
V_50 -> V_58 = NULL ;
V_41 = F_2 ( V_2 , V_42 ) ;
if ( ! ! ( V_2 -> V_14 . V_43 . V_44 & V_181 ) !=
! ! ( V_41 & V_46 ) ) {
if ( V_2 -> V_14 . V_43 . V_44 & V_181 )
V_41 |= V_46 ;
else
V_41 &= ~ V_46 ;
F_4 ( V_2 , V_42 , V_41 ) ;
if ( V_2 -> V_14 . V_43 . V_182 > 0 ) {
V_50 -> V_58 = & V_50 -> V_56 ;
F_94 ( & V_50 -> V_56 , V_169 +
V_2 -> V_14 . V_43 . V_182 * V_170 / 1000 ) ;
return;
}
}
F_98 ( V_14 ) ;
}
static void V_57 ( unsigned long V_167 )
{
struct V_1 * V_7 = (struct V_1 * ) V_167 ;
struct V_51 * V_50 = V_7 -> V_50 ;
unsigned long V_44 ;
F_76 ( & V_7 -> V_14 . V_82 , V_44 ) ;
if ( V_50 &&
V_50 -> V_58 == & V_50 -> V_56 ) {
F_98 ( & V_7 -> V_14 ) ;
V_50 -> V_58 = NULL ;
}
F_78 ( & V_7 -> V_14 . V_82 , V_44 ) ;
}
static void F_101 ( struct V_6 * V_14 )
{
struct V_1 * V_2 = F_35 ( V_14 ) ;
struct V_51 * V_50 = V_2 -> V_50 ;
F_54 ( V_2 ) ;
if ( V_50 &&
V_50 -> V_58 == & V_50 -> V_56 )
return;
if ( V_50 )
F_100 ( V_14 ) ;
else
F_98 ( V_14 ) ;
}
static void F_102 ( struct V_6 * V_14 )
{
V_14 -> V_183 ( V_14 ) ;
}
static void F_103 ( struct V_6 * V_14 )
{
V_14 -> V_184 ( V_14 ) ;
}
static void F_104 ( struct V_6 * V_14 )
{
struct V_1 * V_2 = F_35 ( V_14 ) ;
if ( V_2 -> V_106 & V_185 )
return;
V_2 -> V_162 &= ~ V_186 ;
F_91 ( V_14 , V_73 , V_2 -> V_162 ) ;
}
static void F_105 ( struct V_6 * V_14 )
{
struct V_1 * V_2 = F_35 ( V_14 ) ;
if ( V_2 -> V_106 & V_185 )
return;
V_2 -> V_162 |= V_186 ;
F_43 ( V_2 ) ;
F_91 ( V_14 , V_73 , V_2 -> V_162 ) ;
F_45 ( V_2 ) ;
}
static void F_106 ( struct V_1 * V_2 , unsigned char V_172 )
{
struct V_6 * V_14 = & V_2 -> V_14 ;
unsigned char V_187 ;
char V_188 = V_189 ;
if ( F_107 ( V_172 & V_94 ) )
V_187 = F_2 ( V_2 , V_95 ) ;
else
V_187 = 0 ;
V_14 -> V_190 . V_191 ++ ;
V_172 |= V_2 -> V_178 ;
V_2 -> V_178 = 0 ;
if ( F_108 ( V_172 & V_192 ) ) {
if ( V_172 & V_193 ) {
V_172 &= ~ ( V_194 | V_195 ) ;
V_14 -> V_190 . V_196 ++ ;
if ( F_109 ( V_14 ) )
return;
} else if ( V_172 & V_195 )
V_14 -> V_190 . V_197 ++ ;
else if ( V_172 & V_194 )
V_14 -> V_190 . V_198 ++ ;
if ( V_172 & V_199 )
V_14 -> V_190 . V_200 ++ ;
V_172 &= V_14 -> V_165 ;
if ( V_172 & V_193 ) {
F_110 ( L_17 ) ;
V_188 = V_201 ;
} else if ( V_172 & V_195 )
V_188 = V_202 ;
else if ( V_172 & V_194 )
V_188 = V_203 ;
}
if ( F_111 ( V_14 , V_187 ) )
return;
F_112 ( V_14 , V_172 , V_199 , V_187 , V_188 ) ;
}
unsigned char F_113 ( struct V_1 * V_2 , unsigned char V_172 )
{
struct V_6 * V_14 = & V_2 -> V_14 ;
int V_204 = 256 ;
do {
F_106 ( V_2 , V_172 ) ;
if ( -- V_204 == 0 )
break;
V_172 = F_2 ( V_2 , V_93 ) ;
} while ( V_172 & ( V_94 | V_193 ) );
F_114 ( & V_14 -> V_205 -> V_14 ) ;
return V_172 ;
}
void F_99 ( struct V_1 * V_2 )
{
struct V_6 * V_14 = & V_2 -> V_14 ;
struct V_206 * V_207 = & V_14 -> V_205 -> V_207 ;
int V_89 ;
if ( V_14 -> V_208 ) {
F_4 ( V_2 , V_92 , V_14 -> V_208 ) ;
V_14 -> V_190 . V_209 ++ ;
V_14 -> V_208 = 0 ;
return;
}
if ( F_115 ( V_14 ) ) {
F_97 ( V_14 ) ;
return;
}
if ( F_116 ( V_207 ) ) {
F_96 ( V_2 ) ;
return;
}
V_89 = V_2 -> V_150 ;
do {
F_4 ( V_2 , V_92 , V_207 -> V_210 [ V_207 -> V_211 ] ) ;
V_207 -> V_211 = ( V_207 -> V_211 + 1 ) & ( V_212 - 1 ) ;
V_14 -> V_190 . V_209 ++ ;
if ( F_116 ( V_207 ) )
break;
if ( ( V_2 -> V_35 & V_213 ) &&
( F_2 ( V_2 , V_93 ) & V_173 ) != V_173 )
break;
} while ( -- V_89 > 0 );
if ( F_117 ( V_207 ) < V_214 )
F_118 ( V_14 ) ;
F_110 ( L_18 ) ;
if ( F_116 ( V_207 ) && ! ( V_2 -> V_35 & V_48 ) )
F_96 ( V_2 ) ;
}
unsigned int F_119 ( struct V_1 * V_2 )
{
struct V_6 * V_14 = & V_2 -> V_14 ;
unsigned int V_215 = F_2 ( V_2 , V_142 ) ;
V_215 |= V_2 -> V_216 ;
V_2 -> V_216 = 0 ;
if ( V_215 & V_217 && V_2 -> V_162 & V_186 &&
V_14 -> V_205 != NULL ) {
if ( V_215 & V_218 )
V_14 -> V_190 . V_219 ++ ;
if ( V_215 & V_220 )
V_14 -> V_190 . V_221 ++ ;
if ( V_215 & V_222 )
F_120 ( V_14 , V_215 & V_223 ) ;
if ( V_215 & V_224 )
F_121 ( V_14 , V_215 & V_225 ) ;
F_122 ( & V_14 -> V_205 -> V_14 . V_226 ) ;
}
return V_215 ;
}
int F_123 ( struct V_6 * V_14 , unsigned int V_227 )
{
unsigned char V_215 ;
unsigned long V_44 ;
struct V_1 * V_2 = F_35 ( V_14 ) ;
int V_228 = 0 ;
if ( V_227 & V_229 )
return 0 ;
F_76 ( & V_14 -> V_82 , V_44 ) ;
V_215 = F_124 ( V_14 , V_93 ) ;
F_110 ( L_19 , V_215 ) ;
if ( V_215 & ( V_94 | V_193 ) ) {
if ( V_2 -> V_175 )
V_228 = V_2 -> V_175 -> V_230 ( V_2 , V_227 ) ;
if ( ! V_2 -> V_175 || V_228 )
V_215 = F_113 ( V_2 , V_215 ) ;
}
F_119 ( V_2 ) ;
if ( ( ! V_2 -> V_175 || ( V_2 -> V_175 && V_2 -> V_175 -> V_231 ) ) &&
( V_215 & V_180 ) )
F_99 ( V_2 ) ;
F_78 ( & V_14 -> V_82 , V_44 ) ;
return 1 ;
}
static int V_28 ( struct V_6 * V_14 )
{
struct V_1 * V_2 = F_35 ( V_14 ) ;
unsigned int V_227 ;
int V_232 ;
F_43 ( V_2 ) ;
V_227 = F_124 ( V_14 , V_123 ) ;
V_232 = F_123 ( V_14 , V_227 ) ;
F_45 ( V_2 ) ;
return V_232 ;
}
static int F_125 ( struct V_6 * V_14 )
{
unsigned char V_233 , V_234 , V_235 , V_236 ;
unsigned int V_227 = F_124 ( V_14 , V_123 ) ;
int V_232 ;
V_232 = F_123 ( V_14 , V_227 ) ;
if ( ( V_14 -> type == V_64 ) ||
( V_14 -> type == V_65 ) ) {
V_233 = F_124 ( V_14 , 0x80 ) ;
V_234 = F_124 ( V_14 , 0x81 ) ;
V_235 = F_124 ( V_14 , 0x82 ) ;
V_236 = F_124 ( V_14 , 0x83 ) ;
}
return V_232 ;
}
static unsigned int F_126 ( struct V_6 * V_14 )
{
struct V_1 * V_2 = F_35 ( V_14 ) ;
unsigned long V_44 ;
unsigned int V_172 ;
F_43 ( V_2 ) ;
F_76 ( & V_14 -> V_82 , V_44 ) ;
V_172 = F_124 ( V_14 , V_93 ) ;
V_2 -> V_178 |= V_172 & V_179 ;
F_78 ( & V_14 -> V_82 , V_44 ) ;
F_45 ( V_2 ) ;
return ( V_172 & V_173 ) == V_173 ? V_237 : 0 ;
}
static unsigned int F_127 ( struct V_6 * V_14 )
{
struct V_1 * V_2 = F_35 ( V_14 ) ;
unsigned int V_215 ;
unsigned int V_232 ;
F_43 ( V_2 ) ;
V_215 = F_119 ( V_2 ) ;
F_45 ( V_2 ) ;
V_232 = 0 ;
if ( V_215 & V_223 )
V_232 |= V_238 ;
if ( V_215 & V_239 )
V_232 |= V_240 ;
if ( V_215 & V_241 )
V_232 |= V_242 ;
if ( V_215 & V_225 )
V_232 |= V_243 ;
return V_232 ;
}
void F_128 ( struct V_6 * V_14 , unsigned int V_244 )
{
struct V_1 * V_2 = F_35 ( V_14 ) ;
unsigned char V_41 = 0 ;
if ( V_244 & V_245 )
V_41 |= V_46 ;
if ( V_244 & V_246 )
V_41 |= V_161 ;
if ( V_244 & V_247 )
V_41 |= V_159 ;
if ( V_244 & V_248 )
V_41 |= V_160 ;
if ( V_244 & V_249 )
V_41 |= V_90 ;
V_41 = ( V_41 & V_2 -> V_250 ) | V_2 -> V_251 | V_2 -> V_41 ;
F_91 ( V_14 , V_42 , V_41 ) ;
}
static void F_129 ( struct V_6 * V_14 , unsigned int V_244 )
{
if ( V_14 -> V_252 )
V_14 -> V_252 ( V_14 , V_244 ) ;
else
F_128 ( V_14 , V_244 ) ;
}
static void F_130 ( struct V_6 * V_14 , int V_253 )
{
struct V_1 * V_2 = F_35 ( V_14 ) ;
unsigned long V_44 ;
F_43 ( V_2 ) ;
F_76 ( & V_14 -> V_82 , V_44 ) ;
if ( V_253 == - 1 )
V_2 -> V_62 |= V_254 ;
else
V_2 -> V_62 &= ~ V_254 ;
F_91 ( V_14 , V_29 , V_2 -> V_62 ) ;
F_78 ( & V_14 -> V_82 , V_44 ) ;
F_45 ( V_2 ) ;
}
static void F_131 ( struct V_1 * V_2 , int V_255 )
{
unsigned int V_215 , V_256 = 10000 ;
for (; ; ) {
V_215 = F_2 ( V_2 , V_93 ) ;
V_2 -> V_178 |= V_215 & V_179 ;
if ( ( V_215 & V_255 ) == V_255 )
break;
if ( -- V_256 == 0 )
break;
F_88 ( 1 ) ;
}
if ( V_2 -> V_14 . V_44 & V_257 ) {
unsigned int V_256 ;
for ( V_256 = 1000000 ; V_256 ; V_256 -- ) {
unsigned int V_258 = F_2 ( V_2 , V_142 ) ;
V_2 -> V_216 |= V_258 & V_259 ;
if ( V_258 & V_225 )
break;
F_88 ( 1 ) ;
F_132 () ;
}
}
}
static int F_133 ( struct V_6 * V_14 )
{
struct V_1 * V_2 = F_35 ( V_14 ) ;
unsigned char V_172 ;
int V_215 ;
F_43 ( V_2 ) ;
V_172 = F_124 ( V_14 , V_93 ) ;
if ( ! ( V_172 & V_94 ) ) {
V_215 = V_260 ;
goto V_67;
}
V_215 = F_124 ( V_14 , V_95 ) ;
V_67:
F_45 ( V_2 ) ;
return V_215 ;
}
static void F_134 ( struct V_6 * V_14 ,
unsigned char V_261 )
{
unsigned int V_162 ;
struct V_1 * V_2 = F_35 ( V_14 ) ;
F_43 ( V_2 ) ;
V_162 = F_124 ( V_14 , V_73 ) ;
if ( V_2 -> V_35 & V_131 )
F_91 ( V_14 , V_73 , V_129 ) ;
else
F_91 ( V_14 , V_73 , 0 ) ;
F_131 ( V_2 , V_173 ) ;
F_91 ( V_14 , V_92 , V_261 ) ;
F_131 ( V_2 , V_173 ) ;
F_91 ( V_14 , V_73 , V_162 ) ;
F_45 ( V_2 ) ;
}
int F_135 ( struct V_6 * V_14 )
{
struct V_1 * V_2 = F_35 ( V_14 ) ;
unsigned long V_44 ;
unsigned char V_172 , V_227 ;
int V_262 ;
if ( ! V_14 -> V_147 )
V_14 -> V_147 = V_148 [ V_14 -> type ] . V_149 ;
if ( ! V_2 -> V_150 )
V_2 -> V_150 = V_148 [ V_14 -> type ] . V_150 ;
if ( ! V_2 -> V_35 )
V_2 -> V_35 = V_148 [ V_14 -> type ] . V_44 ;
V_2 -> V_41 = 0 ;
if ( V_14 -> V_19 != V_2 -> V_26 )
F_34 ( V_14 ) ;
F_43 ( V_2 ) ;
if ( V_14 -> type == V_105 ) {
V_2 -> V_33 = 0 ;
F_91 ( V_14 , V_29 , V_71 ) ;
F_91 ( V_14 , V_70 , V_72 ) ;
F_91 ( V_14 , V_73 , 0 ) ;
F_91 ( V_14 , V_29 , 0 ) ;
F_38 ( V_2 , V_263 , 0 ) ;
F_91 ( V_14 , V_29 , V_71 ) ;
F_91 ( V_14 , V_70 , V_72 ) ;
F_91 ( V_14 , V_29 , 0 ) ;
}
#ifdef F_79
F_59 ( V_2 ) ;
#endif
if ( V_14 -> type == V_64 ) {
F_91 ( V_14 , V_264 , V_72 ) ;
F_91 ( V_14 , V_73 , 0 ) ;
}
F_40 ( V_2 ) ;
F_124 ( V_14 , V_93 ) ;
F_124 ( V_14 , V_95 ) ;
F_124 ( V_14 , V_123 ) ;
F_124 ( V_14 , V_142 ) ;
if ( ! ( V_14 -> V_44 & V_140 ) &&
( F_124 ( V_14 , V_93 ) == 0xff ) ) {
F_136 ( V_265 L_20 ,
F_75 ( V_14 ) ) ;
V_262 = - V_266 ;
goto V_67;
}
if ( V_14 -> type == V_108 ) {
unsigned char V_267 ;
F_4 ( V_2 , V_29 , V_71 ) ;
V_267 = F_2 ( V_2 , V_268 ) & ~ ( V_269 | V_270 ) ;
F_91 ( V_14 , V_268 ,
V_267 | V_271 | V_269 ) ;
F_91 ( V_14 , V_272 , V_273 ) ;
F_91 ( V_14 , V_268 ,
V_267 | V_271 | V_270 ) ;
F_91 ( V_14 , V_272 , V_273 ) ;
F_91 ( V_14 , V_29 , 0 ) ;
}
if ( V_14 -> V_157 ) {
unsigned char V_274 ;
F_76 ( & V_14 -> V_82 , V_44 ) ;
if ( V_2 -> V_14 . V_275 & V_276 )
F_137 ( V_14 -> V_157 ) ;
F_131 ( V_2 , V_180 ) ;
F_37 ( V_14 , V_73 , V_171 ) ;
F_88 ( 1 ) ;
V_274 = F_124 ( V_14 , V_123 ) ;
F_91 ( V_14 , V_73 , 0 ) ;
F_37 ( V_14 , V_73 , V_171 ) ;
F_88 ( 1 ) ;
V_227 = F_124 ( V_14 , V_123 ) ;
F_91 ( V_14 , V_73 , 0 ) ;
if ( V_14 -> V_275 & V_276 )
F_138 ( V_14 -> V_157 ) ;
F_78 ( & V_14 -> V_82 , V_44 ) ;
if ( ( ! ( V_274 & V_229 ) && ( V_227 & V_229 ) ) ||
V_2 -> V_14 . V_44 & V_277 ) {
V_2 -> V_106 |= V_278 ;
}
}
V_262 = V_2 -> V_279 -> V_280 ( V_2 ) ;
if ( V_262 )
goto V_67;
F_91 ( V_14 , V_29 , V_281 ) ;
F_76 ( & V_14 -> V_82 , V_44 ) ;
if ( V_2 -> V_14 . V_44 & V_158 ) {
if ( ! V_2 -> V_14 . V_157 )
V_2 -> V_14 . V_244 |= V_247 ;
} else
if ( V_14 -> V_157 )
V_2 -> V_14 . V_244 |= V_248 ;
F_129 ( V_14 , V_14 -> V_244 ) ;
if ( V_2 -> V_14 . V_44 & V_282 )
goto V_283;
F_91 ( V_14 , V_73 , V_171 ) ;
V_172 = F_124 ( V_14 , V_93 ) ;
V_227 = F_124 ( V_14 , V_123 ) ;
F_91 ( V_14 , V_73 , 0 ) ;
if ( V_172 & V_284 && V_227 & V_229 ) {
if ( ! ( V_2 -> V_106 & V_177 ) ) {
V_2 -> V_106 |= V_177 ;
F_139 ( L_21 ,
F_75 ( V_14 ) ) ;
}
} else {
V_2 -> V_106 &= ~ V_177 ;
}
V_283:
F_78 ( & V_14 -> V_82 , V_44 ) ;
F_124 ( V_14 , V_93 ) ;
F_124 ( V_14 , V_95 ) ;
F_124 ( V_14 , V_123 ) ;
F_124 ( V_14 , V_142 ) ;
V_2 -> V_178 = 0 ;
V_2 -> V_216 = 0 ;
if ( V_2 -> V_175 ) {
V_262 = F_140 ( V_2 ) ;
if ( V_262 ) {
F_141 ( L_22 ,
F_75 ( V_14 ) ) ;
V_2 -> V_175 = NULL ;
}
}
V_2 -> V_162 = V_163 | V_164 ;
if ( V_14 -> V_44 & V_158 ) {
unsigned int V_285 ;
V_285 = ( V_14 -> V_16 & 0xfe0 ) | 0x01f ;
F_83 ( 0x80 , V_285 ) ;
F_82 ( V_285 ) ;
}
V_262 = 0 ;
V_67:
F_45 ( V_2 ) ;
return V_262 ;
}
static int F_142 ( struct V_6 * V_14 )
{
if ( V_14 -> V_286 )
return V_14 -> V_286 ( V_14 ) ;
return F_135 ( V_14 ) ;
}
void F_143 ( struct V_6 * V_14 )
{
struct V_1 * V_2 = F_35 ( V_14 ) ;
unsigned long V_44 ;
F_43 ( V_2 ) ;
F_76 ( & V_14 -> V_82 , V_44 ) ;
V_2 -> V_162 = 0 ;
F_91 ( V_14 , V_73 , 0 ) ;
F_78 ( & V_14 -> V_82 , V_44 ) ;
F_144 ( V_14 -> V_157 ) ;
if ( V_2 -> V_175 )
F_145 ( V_2 ) ;
F_76 ( & V_14 -> V_82 , V_44 ) ;
if ( V_14 -> V_44 & V_158 ) {
F_14 ( ( V_14 -> V_16 & 0xfe0 ) | 0x1f ) ;
V_14 -> V_244 |= V_247 ;
} else
V_14 -> V_244 &= ~ V_248 ;
F_129 ( V_14 , V_14 -> V_244 ) ;
F_78 ( & V_14 -> V_82 , V_44 ) ;
F_91 ( V_14 , V_29 ,
F_124 ( V_14 , V_29 ) & ~ V_254 ) ;
F_40 ( V_2 ) ;
#ifdef F_79
F_62 ( V_2 ) ;
#endif
F_124 ( V_14 , V_95 ) ;
F_45 ( V_2 ) ;
V_2 -> V_279 -> V_287 ( V_2 ) ;
}
static void F_146 ( struct V_6 * V_14 )
{
if ( V_14 -> V_288 )
V_14 -> V_288 ( V_14 ) ;
else
F_143 ( V_14 ) ;
}
static unsigned int F_147 ( struct V_1 * V_2 ,
unsigned int V_289 ,
unsigned int * V_290 )
{
struct V_6 * V_14 = & V_2 -> V_14 ;
unsigned int V_291 ;
V_291 = F_148 ( V_14 -> V_79 , V_289 ) ;
* V_290 = V_291 & 0x0f ;
return V_291 >> 4 ;
}
static unsigned int F_149 ( struct V_1 * V_2 ,
unsigned int V_289 ,
unsigned int * V_290 )
{
struct V_6 * V_14 = & V_2 -> V_14 ;
unsigned int V_125 ;
if ( ( V_14 -> V_44 & V_292 ) &&
V_289 == ( V_14 -> V_79 / 4 ) )
V_125 = 0x8001 ;
else if ( ( V_14 -> V_44 & V_292 ) &&
V_289 == ( V_14 -> V_79 / 8 ) )
V_125 = 0x8002 ;
else if ( V_2 -> V_14 . type == V_64 )
V_125 = F_147 ( V_2 , V_289 , V_290 ) ;
else
V_125 = F_150 ( V_14 , V_289 ) ;
if ( V_2 -> V_106 & V_107 && ( V_125 & 0xff ) == 0 )
V_125 ++ ;
return V_125 ;
}
static unsigned char F_151 ( struct V_1 * V_2 ,
T_1 V_293 )
{
unsigned char V_294 ;
switch ( V_293 & V_295 ) {
case V_296 :
V_294 = V_297 ;
break;
case V_298 :
V_294 = V_299 ;
break;
case V_300 :
V_294 = V_301 ;
break;
default:
case V_302 :
V_294 = V_281 ;
break;
}
if ( V_293 & V_303 )
V_294 |= V_304 ;
if ( V_293 & V_305 ) {
V_294 |= V_306 ;
if ( V_2 -> V_106 & V_307 )
V_2 -> V_308 = true ;
}
if ( ! ( V_293 & V_309 ) )
V_294 |= V_310 ;
#ifdef F_152
if ( V_293 & F_152 )
V_294 |= V_311 ;
#endif
return V_294 ;
}
static void F_153 ( struct V_6 * V_14 , unsigned int V_289 ,
unsigned int V_125 , unsigned int V_312 )
{
struct V_1 * V_2 = F_35 ( V_14 ) ;
if ( F_154 ( V_2 ) ) {
if ( V_289 == 115200 ) {
V_125 = 1 ;
F_91 ( V_14 , V_313 , 1 ) ;
} else
F_91 ( V_14 , V_313 , 0 ) ;
}
if ( V_2 -> V_35 & V_127 )
F_91 ( V_14 , V_29 , 0xe0 ) ;
else
F_91 ( V_14 , V_29 , V_2 -> V_62 | V_314 ) ;
F_65 ( V_2 , V_125 ) ;
if ( V_2 -> V_14 . type == V_64 )
F_91 ( V_14 , 0x2 , V_312 ) ;
}
static unsigned int F_155 ( struct V_6 * V_14 ,
struct V_315 * V_316 ,
struct V_315 * V_317 )
{
unsigned int V_318 = V_14 -> V_79 / 100 ;
return F_156 ( V_14 , V_316 , V_317 ,
V_14 -> V_79 / 16 / 0xffff ,
( V_14 -> V_79 + V_318 ) / 16 ) ;
}
void
F_157 ( struct V_6 * V_14 , struct V_315 * V_316 ,
struct V_315 * V_317 )
{
struct V_1 * V_2 = F_35 ( V_14 ) ;
unsigned char V_294 ;
unsigned long V_44 ;
unsigned int V_289 , V_125 , V_290 = 0 ;
V_294 = F_151 ( V_2 , V_316 -> V_293 ) ;
V_289 = F_155 ( V_14 , V_316 , V_317 ) ;
V_125 = F_149 ( V_2 , V_289 , & V_290 ) ;
F_43 ( V_2 ) ;
F_76 ( & V_14 -> V_82 , V_44 ) ;
V_2 -> V_62 = V_294 ;
if ( V_2 -> V_35 & V_36 && V_14 -> V_147 > 1 ) {
if ( ( V_289 < 2400 && ! V_2 -> V_175 ) || V_2 -> V_308 ) {
V_2 -> V_47 &= ~ V_319 ;
V_2 -> V_47 |= V_320 ;
}
}
if ( V_2 -> V_35 & V_120 && V_14 -> V_147 >= 32 ) {
V_2 -> V_41 &= ~ V_321 ;
if ( V_316 -> V_293 & V_322 )
V_2 -> V_41 |= V_321 ;
}
F_158 ( V_14 , V_316 -> V_293 , V_289 ) ;
V_14 -> V_165 = V_199 | V_180 | V_94 ;
if ( V_316 -> V_323 & V_324 )
V_14 -> V_165 |= V_194 | V_195 ;
if ( V_316 -> V_323 & ( V_325 | V_326 | V_327 ) )
V_14 -> V_165 |= V_193 ;
V_14 -> V_328 = 0 ;
if ( V_316 -> V_323 & V_329 )
V_14 -> V_328 |= V_195 | V_194 ;
if ( V_316 -> V_323 & V_325 ) {
V_14 -> V_328 |= V_193 ;
if ( V_316 -> V_323 & V_329 )
V_14 -> V_328 |= V_199 ;
}
if ( ( V_316 -> V_293 & V_330 ) == 0 )
V_14 -> V_328 |= V_94 ;
V_2 -> V_162 &= ~ V_186 ;
if ( ! ( V_2 -> V_106 & V_185 ) &&
F_159 ( & V_2 -> V_14 , V_316 -> V_293 ) )
V_2 -> V_162 |= V_186 ;
if ( V_2 -> V_35 & V_131 )
V_2 -> V_162 |= V_129 ;
if ( V_2 -> V_35 & V_132 )
V_2 -> V_162 |= V_331 ;
F_91 ( V_14 , V_73 , V_2 -> V_162 ) ;
if ( V_2 -> V_35 & V_69 ) {
unsigned char V_63 = 0 ;
if ( V_316 -> V_293 & V_322 )
V_63 |= V_332 ;
F_91 ( V_14 , V_29 , V_71 ) ;
if ( V_14 -> V_44 & V_118 )
F_91 ( V_14 , V_264 , V_63 ) ;
else
F_91 ( V_14 , V_70 , V_63 ) ;
}
F_153 ( V_14 , V_289 , V_125 , V_290 ) ;
if ( V_14 -> type == V_128 )
F_91 ( V_14 , V_37 , V_2 -> V_47 ) ;
F_91 ( V_14 , V_29 , V_2 -> V_62 ) ;
if ( V_14 -> type != V_128 ) {
if ( V_2 -> V_47 & V_38 )
F_91 ( V_14 , V_37 , V_38 ) ;
F_91 ( V_14 , V_37 , V_2 -> V_47 ) ;
}
F_129 ( V_14 , V_14 -> V_244 ) ;
F_78 ( & V_14 -> V_82 , V_44 ) ;
F_45 ( V_2 ) ;
if ( F_160 ( V_316 ) )
F_161 ( V_316 , V_289 , V_289 ) ;
}
static void
F_162 ( struct V_6 * V_14 , struct V_315 * V_316 ,
struct V_315 * V_317 )
{
if ( V_14 -> V_333 )
V_14 -> V_333 ( V_14 , V_316 , V_317 ) ;
else
F_157 ( V_14 , V_316 , V_317 ) ;
}
static void
F_163 ( struct V_6 * V_14 , struct V_315 * V_316 )
{
if ( V_316 -> V_334 == V_335 ) {
V_14 -> V_44 |= V_336 ;
F_60 ( & V_14 -> V_82 ) ;
F_105 ( V_14 ) ;
F_61 ( & V_14 -> V_82 ) ;
} else {
V_14 -> V_44 &= ~ V_336 ;
if ( ! F_159 ( V_14 , V_316 -> V_293 ) ) {
F_60 ( & V_14 -> V_82 ) ;
F_104 ( V_14 ) ;
F_61 ( & V_14 -> V_82 ) ;
}
}
}
void F_164 ( struct V_6 * V_14 , unsigned int V_205 ,
unsigned int V_337 )
{
struct V_1 * V_7 = F_35 ( V_14 ) ;
F_57 ( V_7 , V_205 != 0 ) ;
}
static void
F_165 ( struct V_6 * V_14 , unsigned int V_205 ,
unsigned int V_337 )
{
if ( V_14 -> V_338 )
V_14 -> V_338 ( V_14 , V_205 , V_337 ) ;
else
F_164 ( V_14 , V_205 , V_337 ) ;
}
static unsigned int F_166 ( struct V_1 * V_339 )
{
if ( V_339 -> V_14 . V_340 )
return V_339 -> V_14 . V_340 ;
if ( V_339 -> V_14 . V_19 == V_25 ) {
if ( V_339 -> V_14 . type == V_341 )
return 0x100 ;
return 0x1000 ;
}
if ( F_167 ( V_339 ) )
return 0x16 << V_339 -> V_14 . V_12 ;
return 8 << V_339 -> V_14 . V_12 ;
}
static int F_168 ( struct V_1 * V_2 )
{
unsigned int V_342 = F_166 ( V_2 ) ;
struct V_6 * V_14 = & V_2 -> V_14 ;
int V_232 = 0 ;
switch ( V_14 -> V_19 ) {
case V_25 :
case V_343 :
case V_23 :
case V_24 :
case V_22 :
case V_21 :
if ( ! V_14 -> V_139 )
break;
if ( ! F_169 ( V_14 -> V_139 , V_342 , L_23 ) ) {
V_232 = - V_344 ;
break;
}
if ( V_14 -> V_44 & V_345 ) {
V_14 -> V_11 = F_170 ( V_14 -> V_139 , V_342 ) ;
if ( ! V_14 -> V_11 ) {
F_171 ( V_14 -> V_139 , V_342 ) ;
V_232 = - V_53 ;
}
}
break;
case V_20 :
case V_346 :
if ( ! F_172 ( V_14 -> V_16 , V_342 , L_23 ) )
V_232 = - V_344 ;
break;
}
return V_232 ;
}
static void F_173 ( struct V_1 * V_2 )
{
unsigned int V_342 = F_166 ( V_2 ) ;
struct V_6 * V_14 = & V_2 -> V_14 ;
switch ( V_14 -> V_19 ) {
case V_25 :
case V_343 :
case V_23 :
case V_24 :
case V_22 :
case V_21 :
if ( ! V_14 -> V_139 )
break;
if ( V_14 -> V_44 & V_345 ) {
F_174 ( V_14 -> V_11 ) ;
V_14 -> V_11 = NULL ;
}
F_171 ( V_14 -> V_139 , V_342 ) ;
break;
case V_20 :
case V_346 :
F_175 ( V_14 -> V_16 , V_342 ) ;
break;
}
}
static void F_176 ( struct V_6 * V_14 )
{
struct V_1 * V_2 = F_35 ( V_14 ) ;
F_173 ( V_2 ) ;
}
static int F_177 ( struct V_6 * V_14 )
{
struct V_1 * V_2 = F_35 ( V_14 ) ;
return F_168 ( V_2 ) ;
}
static int F_178 ( struct V_1 * V_2 )
{
const struct V_347 * V_348 = & V_148 [ V_2 -> V_14 . type ] ;
unsigned char V_349 ;
V_349 = V_348 -> V_350 [ F_179 ( V_2 -> V_47 ) ] ;
return V_349 ? V_349 : - V_351 ;
}
static int F_180 ( struct V_1 * V_2 , unsigned char V_349 )
{
const struct V_347 * V_348 = & V_148 [ V_2 -> V_14 . type ] ;
int V_352 ;
if ( ! V_348 -> V_350 [ F_179 ( V_353 ) ] )
return - V_351 ;
for ( V_352 = 1 ; V_352 < V_354 ; V_352 ++ ) {
if ( V_349 < V_348 -> V_350 [ V_352 ] )
return ( -- V_352 ) << V_355 ;
}
return V_356 ;
}
static int F_181 ( struct V_357 * V_14 )
{
struct V_358 * V_205 = F_182 ( V_14 , struct V_358 , V_14 ) ;
struct V_6 * V_359 = V_205 -> V_6 ;
struct V_1 * V_2 = F_35 ( V_359 ) ;
if ( ! ( V_2 -> V_35 & V_36 ) || V_359 -> V_147 <= 1 )
return - V_360 ;
return F_178 ( V_2 ) ;
}
static int F_183 ( struct V_357 * V_14 )
{
int V_350 ;
F_184 ( & V_14 -> V_361 ) ;
V_350 = F_181 ( V_14 ) ;
F_185 ( & V_14 -> V_361 ) ;
return V_350 ;
}
static T_2 F_186 ( struct V_362 * V_49 ,
struct V_363 * V_364 , char * V_210 )
{
struct V_357 * V_14 = F_187 ( V_49 ) ;
int V_350 ;
V_350 = F_183 ( V_14 ) ;
if ( V_350 < 0 )
return V_350 ;
return snprintf ( V_210 , V_365 , L_24 , V_350 ) ;
}
static int F_188 ( struct V_357 * V_14 , unsigned char V_349 )
{
struct V_358 * V_205 = F_182 ( V_14 , struct V_358 , V_14 ) ;
struct V_6 * V_359 = V_205 -> V_6 ;
struct V_1 * V_2 = F_35 ( V_359 ) ;
int V_366 ;
if ( ! ( V_2 -> V_35 & V_36 ) || V_359 -> V_147 <= 1 ||
V_2 -> V_308 )
return - V_360 ;
V_366 = F_180 ( V_2 , V_349 ) ;
if ( V_366 < 0 )
return V_366 ;
F_40 ( V_2 ) ;
V_2 -> V_47 &= ~ V_319 ;
V_2 -> V_47 |= ( unsigned char ) V_366 ;
F_4 ( V_2 , V_37 , V_2 -> V_47 ) ;
return 0 ;
}
static int F_189 ( struct V_357 * V_14 , unsigned char V_349 )
{
int V_232 ;
F_184 ( & V_14 -> V_361 ) ;
V_232 = F_188 ( V_14 , V_349 ) ;
F_185 ( & V_14 -> V_361 ) ;
return V_232 ;
}
static T_2 F_190 ( struct V_362 * V_49 ,
struct V_363 * V_364 , const char * V_210 , T_3 V_89 )
{
struct V_357 * V_14 = F_187 ( V_49 ) ;
unsigned char V_349 ;
int V_232 ;
if ( ! V_89 )
return - V_360 ;
V_232 = F_191 ( V_210 , 10 , & V_349 ) ;
if ( V_232 < 0 )
return V_232 ;
V_232 = F_189 ( V_14 , V_349 ) ;
if ( V_232 < 0 )
return V_232 ;
return V_89 ;
}
static void F_192 ( struct V_1 * V_2 )
{
const struct V_347 * V_348 = & V_148 [ V_2 -> V_14 . type ] ;
if ( V_348 -> V_350 [ 0 ] )
V_2 -> V_14 . V_367 = & V_368 ;
}
static void F_193 ( struct V_6 * V_14 , int V_44 )
{
struct V_1 * V_2 = F_35 ( V_14 ) ;
int V_232 ;
V_232 = F_168 ( V_2 ) ;
if ( V_232 < 0 )
return;
if ( V_14 -> V_19 != V_2 -> V_26 )
F_34 ( V_14 ) ;
if ( V_44 & V_369 )
F_74 ( V_2 ) ;
if ( V_14 -> type == V_117 && V_14 -> V_19 == V_25 )
V_2 -> V_106 |= V_185 ;
if ( V_14 -> type == V_370 )
V_2 -> V_106 |= V_185 ;
if ( V_14 -> type != V_143 && V_44 & V_371 )
F_81 ( V_2 ) ;
if ( V_14 -> type == V_143 )
F_173 ( V_2 ) ;
if ( ( V_14 -> type == V_64 ) ||
( V_14 -> type == V_65 ) )
V_14 -> V_27 = F_125 ;
F_192 ( V_2 ) ;
V_2 -> V_47 = V_148 [ V_2 -> V_14 . type ] . V_47 ;
}
static int
F_194 ( struct V_6 * V_14 , struct V_372 * V_373 )
{
if ( V_373 -> V_157 >= V_374 || V_373 -> V_157 < 0 ||
V_373 -> V_375 < 9600 || V_373 -> type < V_143 ||
V_373 -> type >= F_6 ( V_148 ) || V_373 -> type == V_376 ||
V_373 -> type == V_377 )
return - V_360 ;
return 0 ;
}
static const char * F_195 ( struct V_6 * V_14 )
{
int type = V_14 -> type ;
if ( type >= F_6 ( V_148 ) )
type = 0 ;
return V_148 [ type ] . V_152 ;
}
void F_196 ( struct V_1 * V_2 )
{
struct V_6 * V_14 = & V_2 -> V_14 ;
F_197 ( & V_14 -> V_82 ) ;
V_14 -> V_279 = & V_378 ;
V_2 -> V_26 = 0xFF ;
}
void F_198 ( struct V_1 * V_2 )
{
struct V_6 * V_14 = & V_2 -> V_14 ;
if ( V_2 -> V_14 . V_44 & V_379 ) {
unsigned int type = V_2 -> V_14 . type ;
if ( ! V_2 -> V_14 . V_147 )
V_2 -> V_14 . V_147 = V_148 [ type ] . V_149 ;
if ( ! V_2 -> V_150 )
V_2 -> V_150 = V_148 [ type ] . V_150 ;
if ( ! V_2 -> V_35 )
V_2 -> V_35 = V_148 [ type ] . V_44 ;
}
F_34 ( V_14 ) ;
if ( V_2 -> V_175 ) {
if ( ! V_2 -> V_175 -> V_176 )
V_2 -> V_175 -> V_176 = V_380 ;
if ( ! V_2 -> V_175 -> V_230 )
V_2 -> V_175 -> V_230 = V_381 ;
}
}
static void F_199 ( struct V_6 * V_14 , int V_187 )
{
struct V_1 * V_2 = F_35 ( V_14 ) ;
F_131 ( V_2 , V_180 ) ;
F_91 ( V_14 , V_92 , V_187 ) ;
}
static void F_200 ( struct V_1 * V_2 )
{
struct V_6 * V_14 = & V_2 -> V_14 ;
struct V_315 V_316 ;
unsigned int V_289 , V_125 , V_290 = 0 ;
V_316 . V_293 = V_14 -> V_382 -> V_383 ;
if ( V_14 -> V_205 -> V_14 . V_384 && V_316 . V_293 == 0 )
V_316 . V_293 = V_14 -> V_205 -> V_14 . V_384 -> V_316 . V_293 ;
V_289 = F_155 ( V_14 , & V_316 , NULL ) ;
V_125 = F_149 ( V_2 , V_289 , & V_290 ) ;
F_153 ( V_14 , V_289 , V_125 , V_290 ) ;
F_91 ( V_14 , V_29 , V_2 -> V_62 ) ;
F_91 ( V_14 , V_42 , V_161 | V_46 ) ;
}
void F_201 ( struct V_1 * V_2 , const char * V_385 ,
unsigned int V_89 )
{
struct V_6 * V_14 = & V_2 -> V_14 ;
unsigned long V_44 ;
unsigned int V_162 ;
int V_386 = 1 ;
F_132 () ;
F_43 ( V_2 ) ;
if ( V_14 -> V_387 )
V_386 = 0 ;
else if ( V_388 )
V_386 = F_202 ( & V_14 -> V_82 , V_44 ) ;
else
F_76 ( & V_14 -> V_82 , V_44 ) ;
V_162 = F_124 ( V_14 , V_73 ) ;
if ( V_2 -> V_35 & V_131 )
F_91 ( V_14 , V_73 , V_129 ) ;
else
F_91 ( V_14 , V_73 , 0 ) ;
if ( V_2 -> V_389 && ( V_2 -> V_389 != F_124 ( V_14 , V_30 ) ) ) {
F_200 ( V_2 ) ;
V_2 -> V_389 = 0 ;
}
F_203 ( V_14 , V_385 , V_89 , F_199 ) ;
F_131 ( V_2 , V_173 ) ;
F_91 ( V_14 , V_73 , V_162 ) ;
if ( V_2 -> V_216 )
F_119 ( V_2 ) ;
if ( V_386 )
F_78 ( & V_14 -> V_82 , V_44 ) ;
F_45 ( V_2 ) ;
}
static unsigned int F_204 ( struct V_6 * V_14 )
{
unsigned char V_62 , V_390 , V_391 ;
unsigned int V_125 ;
V_62 = F_124 ( V_14 , V_29 ) ;
F_91 ( V_14 , V_29 , V_62 | V_314 ) ;
V_390 = F_124 ( V_14 , V_3 ) ;
V_391 = F_124 ( V_14 , V_4 ) ;
F_91 ( V_14 , V_29 , V_62 ) ;
V_125 = ( V_391 << 8 ) | V_390 ;
return ( V_14 -> V_79 / 16 ) / V_125 ;
}
int F_205 ( struct V_6 * V_14 , char * V_392 , bool V_145 )
{
int V_289 = 9600 ;
int V_255 = 8 ;
int V_197 = 'n' ;
int V_393 = 'n' ;
if ( ! V_14 -> V_16 && ! V_14 -> V_11 )
return - V_266 ;
if ( V_392 )
F_206 ( V_392 , & V_289 , & V_197 , & V_255 , & V_393 ) ;
else if ( V_145 )
V_289 = F_204 ( V_14 ) ;
return F_207 ( V_14 , V_14 -> V_382 , V_289 , V_197 , V_255 , V_393 ) ;
}
