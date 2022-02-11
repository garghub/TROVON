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
if ( V_14 -> type == V_117 )
F_80 ( V_2 ) ;
if ( V_2 -> V_35 != V_138 ) {
F_81 ( L_14 ,
F_75 ( V_14 ) , V_138 ,
V_2 -> V_35 ) ;
}
V_67:
F_69 ( L_15 , V_111 ) ;
F_69 ( L_16 , V_148 [ V_14 -> type ] . V_152 ) ;
}
static void F_82 ( struct V_1 * V_2 )
{
struct V_6 * V_14 = & V_2 -> V_14 ;
unsigned char V_137 , V_153 ;
unsigned char V_154 = 0 ;
unsigned int V_155 = 0 ;
unsigned long V_156 ;
int V_157 ;
if ( V_14 -> V_44 & V_158 ) {
V_155 = ( V_14 -> V_16 & 0xfe0 ) | 0x1f ;
V_154 = F_83 ( V_155 ) ;
F_84 ( 0x80 , V_155 ) ;
F_83 ( V_155 ) ;
}
if ( F_85 ( V_14 ) )
F_86 () ;
F_87 ( F_88 () ) ;
V_137 = F_2 ( V_2 , V_42 ) ;
V_153 = F_2 ( V_2 , V_73 ) ;
F_4 ( V_2 , V_42 , V_159 | V_160 ) ;
V_156 = F_88 () ;
F_4 ( V_2 , V_42 , 0 ) ;
F_89 ( 10 ) ;
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
F_89 ( 20 ) ;
V_157 = F_87 ( V_156 ) ;
F_4 ( V_2 , V_42 , V_137 ) ;
F_4 ( V_2 , V_73 , V_153 ) ;
if ( V_14 -> V_44 & V_158 )
F_84 ( V_154 , V_155 ) ;
if ( F_85 ( V_14 ) )
F_90 () ;
V_14 -> V_157 = ( V_157 > 0 ) ? V_157 : 0 ;
}
static void F_91 ( struct V_6 * V_14 )
{
struct V_1 * V_2 = F_35 ( V_14 ) ;
F_43 ( V_2 ) ;
V_2 -> V_162 &= ~ ( V_163 | V_164 ) ;
V_2 -> V_14 . V_165 &= ~ V_94 ;
F_92 ( V_14 , V_73 , V_2 -> V_162 ) ;
F_45 ( V_2 ) ;
}
static void F_93 ( struct V_1 * V_7 )
{
if ( ! V_7 -> V_50 )
return;
F_41 ( V_7 ) ;
if ( ! ( V_7 -> V_14 . V_43 . V_44 & V_166 ) ) {
F_40 ( V_7 ) ;
F_43 ( V_7 ) ;
V_7 -> V_162 |= V_163 | V_164 ;
F_92 ( & V_7 -> V_14 , V_73 , V_7 -> V_162 ) ;
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
F_93 ( V_7 ) ;
V_50 -> V_58 = NULL ;
}
F_78 ( & V_7 -> V_14 . V_82 , V_44 ) ;
}
static void F_94 ( struct V_1 * V_7 )
{
struct V_51 * V_50 = V_7 -> V_50 ;
if ( ! V_50 )
return;
if ( V_7 -> V_14 . V_43 . V_168 > 0 ) {
V_50 -> V_58 = & V_50 -> V_54 ;
F_95 ( & V_50 -> V_54 , V_169 +
V_7 -> V_14 . V_43 . V_168 * V_170 / 1000 ) ;
} else {
F_93 ( V_7 ) ;
}
}
static inline void F_96 ( struct V_1 * V_7 )
{
if ( V_7 -> V_162 & V_171 ) {
V_7 -> V_162 &= ~ V_171 ;
F_4 ( V_7 , V_73 , V_7 -> V_162 ) ;
F_56 ( V_7 ) ;
}
}
static inline void F_97 ( struct V_1 * V_7 )
{
struct V_51 * V_50 = V_7 -> V_50 ;
if ( V_50 ) {
unsigned char V_172 = F_2 ( V_7 , V_93 ) ;
if ( ( V_172 & V_173 ) != V_173 )
return;
F_52 ( & V_50 -> V_56 ) ;
V_50 -> V_58 = NULL ;
}
F_96 ( V_7 ) ;
F_94 ( V_7 ) ;
}
static void F_98 ( struct V_6 * V_14 )
{
struct V_1 * V_2 = F_35 ( V_14 ) ;
F_43 ( V_2 ) ;
F_97 ( V_2 ) ;
if ( V_14 -> type == V_105 ) {
V_2 -> V_33 |= V_174 ;
F_38 ( V_2 , V_32 , V_2 -> V_33 ) ;
}
F_45 ( V_2 ) ;
}
static inline void F_99 ( struct V_6 * V_14 )
{
struct V_1 * V_2 = F_35 ( V_14 ) ;
if ( V_2 -> V_175 && ! V_2 -> V_175 -> V_176 ( V_2 ) )
return;
if ( ! ( V_2 -> V_162 & V_171 ) ) {
V_2 -> V_162 |= V_171 ;
F_92 ( V_14 , V_73 , V_2 -> V_162 ) ;
if ( V_2 -> V_106 & V_177 ) {
unsigned char V_172 ;
V_172 = F_2 ( V_2 , V_93 ) ;
V_2 -> V_178 |= V_172 & V_179 ;
if ( V_172 & V_180 )
F_100 ( V_2 ) ;
}
}
if ( V_14 -> type == V_105 && V_2 -> V_33 & V_174 ) {
V_2 -> V_33 &= ~ V_174 ;
F_38 ( V_2 , V_32 , V_2 -> V_33 ) ;
}
}
static inline void F_101 ( struct V_6 * V_14 )
{
struct V_1 * V_2 = F_35 ( V_14 ) ;
struct V_51 * V_50 = V_2 -> V_50 ;
unsigned char V_41 ;
if ( ! ( V_2 -> V_14 . V_43 . V_44 & V_166 ) )
F_91 ( & V_2 -> V_14 ) ;
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
F_95 ( & V_50 -> V_56 , V_169 +
V_2 -> V_14 . V_43 . V_182 * V_170 / 1000 ) ;
return;
}
}
F_99 ( V_14 ) ;
}
static void V_57 ( unsigned long V_167 )
{
struct V_1 * V_7 = (struct V_1 * ) V_167 ;
struct V_51 * V_50 = V_7 -> V_50 ;
unsigned long V_44 ;
F_76 ( & V_7 -> V_14 . V_82 , V_44 ) ;
if ( V_50 &&
V_50 -> V_58 == & V_50 -> V_56 ) {
F_99 ( & V_7 -> V_14 ) ;
V_50 -> V_58 = NULL ;
}
F_78 ( & V_7 -> V_14 . V_82 , V_44 ) ;
}
static void F_102 ( struct V_6 * V_14 )
{
struct V_1 * V_2 = F_35 ( V_14 ) ;
struct V_51 * V_50 = V_2 -> V_50 ;
F_54 ( V_2 ) ;
if ( V_50 &&
V_50 -> V_58 == & V_50 -> V_56 )
return;
if ( V_50 )
F_101 ( V_14 ) ;
else
F_99 ( V_14 ) ;
}
static void F_103 ( struct V_6 * V_14 )
{
V_14 -> V_183 ( V_14 ) ;
}
static void F_104 ( struct V_6 * V_14 )
{
V_14 -> V_184 ( V_14 ) ;
}
static void F_105 ( struct V_6 * V_14 )
{
struct V_1 * V_2 = F_35 ( V_14 ) ;
if ( V_2 -> V_106 & V_185 )
return;
V_2 -> V_162 &= ~ V_186 ;
F_92 ( V_14 , V_73 , V_2 -> V_162 ) ;
}
static void F_106 ( struct V_6 * V_14 )
{
struct V_1 * V_2 = F_35 ( V_14 ) ;
if ( V_2 -> V_106 & V_185 )
return;
V_2 -> V_162 |= V_186 ;
F_43 ( V_2 ) ;
F_92 ( V_14 , V_73 , V_2 -> V_162 ) ;
F_45 ( V_2 ) ;
}
static void F_107 ( struct V_1 * V_2 , unsigned char V_172 )
{
struct V_6 * V_14 = & V_2 -> V_14 ;
unsigned char V_187 ;
char V_188 = V_189 ;
if ( F_108 ( V_172 & V_94 ) )
V_187 = F_2 ( V_2 , V_95 ) ;
else
V_187 = 0 ;
V_14 -> V_190 . V_191 ++ ;
V_172 |= V_2 -> V_178 ;
V_2 -> V_178 = 0 ;
if ( F_109 ( V_172 & V_192 ) ) {
if ( V_172 & V_193 ) {
V_172 &= ~ ( V_194 | V_195 ) ;
V_14 -> V_190 . V_196 ++ ;
if ( F_110 ( V_14 ) )
return;
} else if ( V_172 & V_195 )
V_14 -> V_190 . V_197 ++ ;
else if ( V_172 & V_194 )
V_14 -> V_190 . V_198 ++ ;
if ( V_172 & V_199 )
V_14 -> V_190 . V_200 ++ ;
V_172 &= V_14 -> V_165 ;
if ( V_172 & V_193 ) {
F_111 ( L_17 ) ;
V_188 = V_201 ;
} else if ( V_172 & V_195 )
V_188 = V_202 ;
else if ( V_172 & V_194 )
V_188 = V_203 ;
}
if ( F_112 ( V_14 , V_187 ) )
return;
F_113 ( V_14 , V_172 , V_199 , V_187 , V_188 ) ;
}
unsigned char F_114 ( struct V_1 * V_2 , unsigned char V_172 )
{
struct V_6 * V_14 = & V_2 -> V_14 ;
int V_204 = 256 ;
do {
F_107 ( V_2 , V_172 ) ;
if ( -- V_204 == 0 )
break;
V_172 = F_2 ( V_2 , V_93 ) ;
} while ( V_172 & ( V_94 | V_193 ) );
F_115 ( & V_14 -> V_205 -> V_14 ) ;
return V_172 ;
}
void F_100 ( struct V_1 * V_2 )
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
if ( F_116 ( V_14 ) ) {
F_98 ( V_14 ) ;
return;
}
if ( F_117 ( V_207 ) ) {
F_97 ( V_2 ) ;
return;
}
V_89 = V_2 -> V_150 ;
do {
F_4 ( V_2 , V_92 , V_207 -> V_210 [ V_207 -> V_211 ] ) ;
V_207 -> V_211 = ( V_207 -> V_211 + 1 ) & ( V_212 - 1 ) ;
V_14 -> V_190 . V_209 ++ ;
if ( F_117 ( V_207 ) )
break;
if ( ( V_2 -> V_35 & V_213 ) &&
( F_2 ( V_2 , V_93 ) & V_173 ) != V_173 )
break;
} while ( -- V_89 > 0 );
if ( F_118 ( V_207 ) < V_214 )
F_119 ( V_14 ) ;
F_111 ( L_18 ) ;
if ( F_117 ( V_207 ) && ! ( V_2 -> V_35 & V_48 ) )
F_97 ( V_2 ) ;
}
unsigned int F_120 ( struct V_1 * V_2 )
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
F_121 ( V_14 , V_215 & V_223 ) ;
if ( V_215 & V_224 )
F_122 ( V_14 , V_215 & V_225 ) ;
F_123 ( & V_14 -> V_205 -> V_14 . V_226 ) ;
}
return V_215 ;
}
static bool F_124 ( struct V_1 * V_2 , unsigned int V_227 )
{
switch ( V_227 & 0x3f ) {
case V_228 :
F_125 ( V_2 ) ;
case V_229 :
return true ;
}
return V_2 -> V_175 -> V_230 ( V_2 ) ;
}
int F_126 ( struct V_6 * V_14 , unsigned int V_227 )
{
unsigned char V_215 ;
unsigned long V_44 ;
struct V_1 * V_2 = F_35 ( V_14 ) ;
if ( V_227 & V_231 )
return 0 ;
F_76 ( & V_14 -> V_82 , V_44 ) ;
V_215 = F_127 ( V_14 , V_93 ) ;
F_111 ( L_19 , V_215 ) ;
if ( V_215 & ( V_94 | V_193 ) ) {
if ( ! V_2 -> V_175 || F_124 ( V_2 , V_227 ) )
V_215 = F_114 ( V_2 , V_215 ) ;
}
F_120 ( V_2 ) ;
if ( ( ! V_2 -> V_175 || V_2 -> V_175 -> V_232 ) && ( V_215 & V_180 ) )
F_100 ( V_2 ) ;
F_78 ( & V_14 -> V_82 , V_44 ) ;
return 1 ;
}
static int V_28 ( struct V_6 * V_14 )
{
struct V_1 * V_2 = F_35 ( V_14 ) ;
unsigned int V_227 ;
int V_233 ;
F_43 ( V_2 ) ;
V_227 = F_127 ( V_14 , V_123 ) ;
V_233 = F_126 ( V_14 , V_227 ) ;
F_45 ( V_2 ) ;
return V_233 ;
}
static int F_128 ( struct V_6 * V_14 )
{
unsigned char V_234 , V_235 , V_236 , V_237 ;
unsigned int V_227 = F_127 ( V_14 , V_123 ) ;
int V_233 ;
V_233 = F_126 ( V_14 , V_227 ) ;
if ( ( V_14 -> type == V_64 ) ||
( V_14 -> type == V_65 ) ) {
V_234 = F_127 ( V_14 , 0x80 ) ;
V_235 = F_127 ( V_14 , 0x81 ) ;
V_236 = F_127 ( V_14 , 0x82 ) ;
V_237 = F_127 ( V_14 , 0x83 ) ;
}
return V_233 ;
}
static unsigned int F_129 ( struct V_6 * V_14 )
{
struct V_1 * V_2 = F_35 ( V_14 ) ;
unsigned long V_44 ;
unsigned int V_172 ;
F_43 ( V_2 ) ;
F_76 ( & V_14 -> V_82 , V_44 ) ;
V_172 = F_127 ( V_14 , V_93 ) ;
V_2 -> V_178 |= V_172 & V_179 ;
F_78 ( & V_14 -> V_82 , V_44 ) ;
F_45 ( V_2 ) ;
return ( V_172 & V_173 ) == V_173 ? V_238 : 0 ;
}
unsigned int F_130 ( struct V_6 * V_14 )
{
struct V_1 * V_2 = F_35 ( V_14 ) ;
unsigned int V_215 ;
unsigned int V_233 ;
F_43 ( V_2 ) ;
V_215 = F_120 ( V_2 ) ;
F_45 ( V_2 ) ;
V_233 = 0 ;
if ( V_215 & V_223 )
V_233 |= V_239 ;
if ( V_215 & V_240 )
V_233 |= V_241 ;
if ( V_215 & V_242 )
V_233 |= V_243 ;
if ( V_215 & V_225 )
V_233 |= V_244 ;
return V_233 ;
}
static unsigned int F_131 ( struct V_6 * V_14 )
{
if ( V_14 -> V_245 )
return V_14 -> V_245 ( V_14 ) ;
return F_130 ( V_14 ) ;
}
void F_132 ( struct V_6 * V_14 , unsigned int V_246 )
{
struct V_1 * V_2 = F_35 ( V_14 ) ;
unsigned char V_41 = 0 ;
if ( V_246 & V_247 )
V_41 |= V_46 ;
if ( V_246 & V_248 )
V_41 |= V_161 ;
if ( V_246 & V_249 )
V_41 |= V_159 ;
if ( V_246 & V_250 )
V_41 |= V_160 ;
if ( V_246 & V_251 )
V_41 |= V_90 ;
V_41 = ( V_41 & V_2 -> V_252 ) | V_2 -> V_253 | V_2 -> V_41 ;
F_92 ( V_14 , V_42 , V_41 ) ;
}
static void F_133 ( struct V_6 * V_14 , unsigned int V_246 )
{
if ( V_14 -> V_254 )
V_14 -> V_254 ( V_14 , V_246 ) ;
else
F_132 ( V_14 , V_246 ) ;
}
static void F_134 ( struct V_6 * V_14 , int V_255 )
{
struct V_1 * V_2 = F_35 ( V_14 ) ;
unsigned long V_44 ;
F_43 ( V_2 ) ;
F_76 ( & V_14 -> V_82 , V_44 ) ;
if ( V_255 == - 1 )
V_2 -> V_62 |= V_256 ;
else
V_2 -> V_62 &= ~ V_256 ;
F_92 ( V_14 , V_29 , V_2 -> V_62 ) ;
F_78 ( & V_14 -> V_82 , V_44 ) ;
F_45 ( V_2 ) ;
}
static void F_135 ( struct V_1 * V_2 , int V_257 )
{
unsigned int V_215 , V_258 = 10000 ;
for (; ; ) {
V_215 = F_2 ( V_2 , V_93 ) ;
V_2 -> V_178 |= V_215 & V_179 ;
if ( ( V_215 & V_257 ) == V_257 )
break;
if ( -- V_258 == 0 )
break;
F_89 ( 1 ) ;
}
if ( V_2 -> V_14 . V_44 & V_259 ) {
unsigned int V_258 ;
for ( V_258 = 1000000 ; V_258 ; V_258 -- ) {
unsigned int V_260 = F_2 ( V_2 , V_142 ) ;
V_2 -> V_216 |= V_260 & V_261 ;
if ( V_260 & V_225 )
break;
F_89 ( 1 ) ;
F_136 () ;
}
}
}
static int F_137 ( struct V_6 * V_14 )
{
struct V_1 * V_2 = F_35 ( V_14 ) ;
unsigned char V_172 ;
int V_215 ;
F_43 ( V_2 ) ;
V_172 = F_127 ( V_14 , V_93 ) ;
if ( ! ( V_172 & V_94 ) ) {
V_215 = V_262 ;
goto V_67;
}
V_215 = F_127 ( V_14 , V_95 ) ;
V_67:
F_45 ( V_2 ) ;
return V_215 ;
}
static void F_138 ( struct V_6 * V_14 ,
unsigned char V_263 )
{
unsigned int V_162 ;
struct V_1 * V_2 = F_35 ( V_14 ) ;
F_43 ( V_2 ) ;
V_162 = F_127 ( V_14 , V_73 ) ;
if ( V_2 -> V_35 & V_131 )
F_92 ( V_14 , V_73 , V_129 ) ;
else
F_92 ( V_14 , V_73 , 0 ) ;
F_135 ( V_2 , V_173 ) ;
F_92 ( V_14 , V_92 , V_263 ) ;
F_135 ( V_2 , V_173 ) ;
F_92 ( V_14 , V_73 , V_162 ) ;
F_45 ( V_2 ) ;
}
int F_139 ( struct V_6 * V_14 )
{
struct V_1 * V_2 = F_35 ( V_14 ) ;
unsigned long V_44 ;
unsigned char V_172 , V_227 ;
int V_264 ;
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
F_92 ( V_14 , V_29 , V_71 ) ;
F_92 ( V_14 , V_70 , V_72 ) ;
F_92 ( V_14 , V_73 , 0 ) ;
F_92 ( V_14 , V_29 , 0 ) ;
F_38 ( V_2 , V_265 , 0 ) ;
F_92 ( V_14 , V_29 , V_71 ) ;
F_92 ( V_14 , V_70 , V_72 ) ;
F_92 ( V_14 , V_29 , 0 ) ;
}
#ifdef F_79
F_59 ( V_2 ) ;
#endif
if ( V_14 -> type == V_64 ) {
F_92 ( V_14 , V_266 , V_72 ) ;
F_92 ( V_14 , V_73 , 0 ) ;
}
F_40 ( V_2 ) ;
F_127 ( V_14 , V_93 ) ;
F_127 ( V_14 , V_95 ) ;
F_127 ( V_14 , V_123 ) ;
F_127 ( V_14 , V_142 ) ;
if ( ! ( V_14 -> V_44 & V_140 ) &&
( F_127 ( V_14 , V_93 ) == 0xff ) ) {
F_140 ( V_267 L_20 ,
F_75 ( V_14 ) ) ;
V_264 = - V_268 ;
goto V_67;
}
if ( V_14 -> type == V_108 ) {
unsigned char V_269 ;
F_4 ( V_2 , V_29 , V_71 ) ;
V_269 = F_2 ( V_2 , V_270 ) & ~ ( V_271 | V_272 ) ;
F_92 ( V_14 , V_270 ,
V_269 | V_273 | V_271 ) ;
F_92 ( V_14 , V_274 , V_275 ) ;
F_92 ( V_14 , V_270 ,
V_269 | V_273 | V_272 ) ;
F_92 ( V_14 , V_274 , V_275 ) ;
F_92 ( V_14 , V_29 , 0 ) ;
}
if ( V_14 -> V_157 ) {
unsigned char V_276 ;
F_76 ( & V_14 -> V_82 , V_44 ) ;
if ( V_2 -> V_14 . V_277 & V_278 )
F_141 ( V_14 -> V_157 ) ;
F_135 ( V_2 , V_180 ) ;
F_37 ( V_14 , V_73 , V_171 ) ;
F_89 ( 1 ) ;
V_276 = F_127 ( V_14 , V_123 ) ;
F_92 ( V_14 , V_73 , 0 ) ;
F_37 ( V_14 , V_73 , V_171 ) ;
F_89 ( 1 ) ;
V_227 = F_127 ( V_14 , V_123 ) ;
F_92 ( V_14 , V_73 , 0 ) ;
if ( V_14 -> V_277 & V_278 )
F_142 ( V_14 -> V_157 ) ;
F_78 ( & V_14 -> V_82 , V_44 ) ;
if ( ( ! ( V_276 & V_231 ) && ( V_227 & V_231 ) ) ||
V_2 -> V_14 . V_44 & V_279 ) {
V_2 -> V_106 |= V_280 ;
}
}
V_264 = V_2 -> V_281 -> V_282 ( V_2 ) ;
if ( V_264 )
goto V_67;
F_92 ( V_14 , V_29 , V_283 ) ;
F_76 ( & V_14 -> V_82 , V_44 ) ;
if ( V_2 -> V_14 . V_44 & V_158 ) {
if ( ! V_2 -> V_14 . V_157 )
V_2 -> V_14 . V_246 |= V_249 ;
} else
if ( V_14 -> V_157 )
V_2 -> V_14 . V_246 |= V_250 ;
F_133 ( V_14 , V_14 -> V_246 ) ;
if ( V_2 -> V_14 . V_44 & V_284 )
goto V_285;
F_92 ( V_14 , V_73 , V_171 ) ;
V_172 = F_127 ( V_14 , V_93 ) ;
V_227 = F_127 ( V_14 , V_123 ) ;
F_92 ( V_14 , V_73 , 0 ) ;
if ( V_172 & V_286 && V_227 & V_231 ) {
if ( ! ( V_2 -> V_106 & V_177 ) ) {
V_2 -> V_106 |= V_177 ;
F_143 ( L_21 ,
F_75 ( V_14 ) ) ;
}
} else {
V_2 -> V_106 &= ~ V_177 ;
}
V_285:
F_78 ( & V_14 -> V_82 , V_44 ) ;
F_127 ( V_14 , V_93 ) ;
F_127 ( V_14 , V_95 ) ;
F_127 ( V_14 , V_123 ) ;
F_127 ( V_14 , V_142 ) ;
V_2 -> V_178 = 0 ;
V_2 -> V_216 = 0 ;
if ( V_2 -> V_175 ) {
V_264 = F_144 ( V_2 ) ;
if ( V_264 ) {
F_145 ( L_22 ,
F_75 ( V_14 ) ) ;
V_2 -> V_175 = NULL ;
}
}
V_2 -> V_162 = V_163 | V_164 ;
if ( V_14 -> V_44 & V_158 ) {
unsigned int V_287 ;
V_287 = ( V_14 -> V_16 & 0xfe0 ) | 0x01f ;
F_84 ( 0x80 , V_287 ) ;
F_83 ( V_287 ) ;
}
V_264 = 0 ;
V_67:
F_45 ( V_2 ) ;
return V_264 ;
}
static int F_146 ( struct V_6 * V_14 )
{
if ( V_14 -> V_288 )
return V_14 -> V_288 ( V_14 ) ;
return F_139 ( V_14 ) ;
}
void F_147 ( struct V_6 * V_14 )
{
struct V_1 * V_2 = F_35 ( V_14 ) ;
unsigned long V_44 ;
F_43 ( V_2 ) ;
F_76 ( & V_14 -> V_82 , V_44 ) ;
V_2 -> V_162 = 0 ;
F_92 ( V_14 , V_73 , 0 ) ;
F_78 ( & V_14 -> V_82 , V_44 ) ;
F_148 ( V_14 -> V_157 ) ;
if ( V_2 -> V_175 )
F_149 ( V_2 ) ;
F_76 ( & V_14 -> V_82 , V_44 ) ;
if ( V_14 -> V_44 & V_158 ) {
F_14 ( ( V_14 -> V_16 & 0xfe0 ) | 0x1f ) ;
V_14 -> V_246 |= V_249 ;
} else
V_14 -> V_246 &= ~ V_250 ;
F_133 ( V_14 , V_14 -> V_246 ) ;
F_78 ( & V_14 -> V_82 , V_44 ) ;
F_92 ( V_14 , V_29 ,
F_127 ( V_14 , V_29 ) & ~ V_256 ) ;
F_40 ( V_2 ) ;
#ifdef F_79
F_62 ( V_2 ) ;
#endif
F_127 ( V_14 , V_95 ) ;
F_45 ( V_2 ) ;
V_2 -> V_281 -> V_289 ( V_2 ) ;
}
static void F_150 ( struct V_6 * V_14 )
{
if ( V_14 -> V_290 )
V_14 -> V_290 ( V_14 ) ;
else
F_147 ( V_14 ) ;
}
static unsigned int F_151 ( struct V_1 * V_2 ,
unsigned int V_291 ,
unsigned int * V_292 )
{
struct V_6 * V_14 = & V_2 -> V_14 ;
unsigned int V_293 ;
V_293 = F_152 ( V_14 -> V_79 , V_291 ) ;
* V_292 = V_293 & 0x0f ;
return V_293 >> 4 ;
}
static unsigned int F_153 ( struct V_1 * V_2 ,
unsigned int V_291 ,
unsigned int * V_292 )
{
struct V_6 * V_14 = & V_2 -> V_14 ;
unsigned int V_125 ;
if ( ( V_14 -> V_44 & V_294 ) &&
V_291 == ( V_14 -> V_79 / 4 ) )
V_125 = 0x8001 ;
else if ( ( V_14 -> V_44 & V_294 ) &&
V_291 == ( V_14 -> V_79 / 8 ) )
V_125 = 0x8002 ;
else if ( V_2 -> V_14 . type == V_64 )
V_125 = F_151 ( V_2 , V_291 , V_292 ) ;
else
V_125 = F_154 ( V_14 , V_291 ) ;
if ( V_2 -> V_106 & V_107 && ( V_125 & 0xff ) == 0 )
V_125 ++ ;
return V_125 ;
}
static unsigned char F_155 ( struct V_1 * V_2 ,
T_1 V_295 )
{
unsigned char V_296 ;
switch ( V_295 & V_297 ) {
case V_298 :
V_296 = V_299 ;
break;
case V_300 :
V_296 = V_301 ;
break;
case V_302 :
V_296 = V_303 ;
break;
default:
case V_304 :
V_296 = V_283 ;
break;
}
if ( V_295 & V_305 )
V_296 |= V_306 ;
if ( V_295 & V_307 ) {
V_296 |= V_308 ;
if ( V_2 -> V_106 & V_309 )
V_2 -> V_310 = true ;
}
if ( ! ( V_295 & V_311 ) )
V_296 |= V_312 ;
#ifdef F_156
if ( V_295 & F_156 )
V_296 |= V_313 ;
#endif
return V_296 ;
}
static void F_157 ( struct V_6 * V_14 , unsigned int V_291 ,
unsigned int V_125 , unsigned int V_314 )
{
struct V_1 * V_2 = F_35 ( V_14 ) ;
if ( F_158 ( V_2 ) ) {
if ( V_291 == 115200 ) {
V_125 = 1 ;
F_92 ( V_14 , V_315 , 1 ) ;
} else
F_92 ( V_14 , V_315 , 0 ) ;
}
if ( V_2 -> V_35 & V_127 )
F_92 ( V_14 , V_29 , 0xe0 ) ;
else
F_92 ( V_14 , V_29 , V_2 -> V_62 | V_316 ) ;
F_65 ( V_2 , V_125 ) ;
if ( V_2 -> V_14 . type == V_64 )
F_92 ( V_14 , 0x2 , V_314 ) ;
}
static unsigned int F_159 ( struct V_6 * V_14 ,
struct V_317 * V_318 ,
struct V_317 * V_319 )
{
unsigned int V_320 = V_14 -> V_79 / 100 ;
return F_160 ( V_14 , V_318 , V_319 ,
V_14 -> V_79 / 16 / 0xffff ,
( V_14 -> V_79 + V_320 ) / 16 ) ;
}
void
F_161 ( struct V_6 * V_14 , struct V_317 * V_318 ,
struct V_317 * V_319 )
{
struct V_1 * V_2 = F_35 ( V_14 ) ;
unsigned char V_296 ;
unsigned long V_44 ;
unsigned int V_291 , V_125 , V_292 = 0 ;
V_296 = F_155 ( V_2 , V_318 -> V_295 ) ;
V_291 = F_159 ( V_14 , V_318 , V_319 ) ;
V_125 = F_153 ( V_2 , V_291 , & V_292 ) ;
F_43 ( V_2 ) ;
F_76 ( & V_14 -> V_82 , V_44 ) ;
V_2 -> V_62 = V_296 ;
if ( V_2 -> V_35 & V_36 && V_14 -> V_147 > 1 ) {
if ( ( V_291 < 2400 && ! V_2 -> V_175 ) || V_2 -> V_310 ) {
V_2 -> V_47 &= ~ V_321 ;
V_2 -> V_47 |= V_322 ;
}
}
if ( V_2 -> V_35 & V_120 && V_14 -> V_147 >= 32 ) {
V_2 -> V_41 &= ~ V_323 ;
if ( V_318 -> V_295 & V_324 )
V_2 -> V_41 |= V_323 ;
}
F_162 ( V_14 , V_318 -> V_295 , V_291 ) ;
V_14 -> V_165 = V_199 | V_180 | V_94 ;
if ( V_318 -> V_325 & V_326 )
V_14 -> V_165 |= V_194 | V_195 ;
if ( V_318 -> V_325 & ( V_327 | V_328 | V_329 ) )
V_14 -> V_165 |= V_193 ;
V_14 -> V_330 = 0 ;
if ( V_318 -> V_325 & V_331 )
V_14 -> V_330 |= V_195 | V_194 ;
if ( V_318 -> V_325 & V_327 ) {
V_14 -> V_330 |= V_193 ;
if ( V_318 -> V_325 & V_331 )
V_14 -> V_330 |= V_199 ;
}
if ( ( V_318 -> V_295 & V_332 ) == 0 )
V_14 -> V_330 |= V_94 ;
V_2 -> V_162 &= ~ V_186 ;
if ( ! ( V_2 -> V_106 & V_185 ) &&
F_163 ( & V_2 -> V_14 , V_318 -> V_295 ) )
V_2 -> V_162 |= V_186 ;
if ( V_2 -> V_35 & V_131 )
V_2 -> V_162 |= V_129 ;
if ( V_2 -> V_35 & V_132 )
V_2 -> V_162 |= V_333 ;
F_92 ( V_14 , V_73 , V_2 -> V_162 ) ;
if ( V_2 -> V_35 & V_69 ) {
unsigned char V_63 = 0 ;
if ( V_318 -> V_295 & V_324 )
V_63 |= V_334 ;
F_92 ( V_14 , V_29 , V_71 ) ;
if ( V_14 -> V_44 & V_118 )
F_92 ( V_14 , V_266 , V_63 ) ;
else
F_92 ( V_14 , V_70 , V_63 ) ;
}
F_157 ( V_14 , V_291 , V_125 , V_292 ) ;
if ( V_14 -> type == V_128 )
F_92 ( V_14 , V_37 , V_2 -> V_47 ) ;
F_92 ( V_14 , V_29 , V_2 -> V_62 ) ;
if ( V_14 -> type != V_128 ) {
if ( V_2 -> V_47 & V_38 )
F_92 ( V_14 , V_37 , V_38 ) ;
F_92 ( V_14 , V_37 , V_2 -> V_47 ) ;
}
F_133 ( V_14 , V_14 -> V_246 ) ;
F_78 ( & V_14 -> V_82 , V_44 ) ;
F_45 ( V_2 ) ;
if ( F_164 ( V_318 ) )
F_165 ( V_318 , V_291 , V_291 ) ;
}
static void
F_166 ( struct V_6 * V_14 , struct V_317 * V_318 ,
struct V_317 * V_319 )
{
if ( V_14 -> V_335 )
V_14 -> V_335 ( V_14 , V_318 , V_319 ) ;
else
F_161 ( V_14 , V_318 , V_319 ) ;
}
static void
F_167 ( struct V_6 * V_14 , struct V_317 * V_318 )
{
if ( V_318 -> V_336 == V_337 ) {
V_14 -> V_44 |= V_338 ;
F_60 ( & V_14 -> V_82 ) ;
F_106 ( V_14 ) ;
F_61 ( & V_14 -> V_82 ) ;
} else {
V_14 -> V_44 &= ~ V_338 ;
if ( ! F_163 ( V_14 , V_318 -> V_295 ) ) {
F_60 ( & V_14 -> V_82 ) ;
F_105 ( V_14 ) ;
F_61 ( & V_14 -> V_82 ) ;
}
}
}
void F_168 ( struct V_6 * V_14 , unsigned int V_205 ,
unsigned int V_339 )
{
struct V_1 * V_7 = F_35 ( V_14 ) ;
F_57 ( V_7 , V_205 != 0 ) ;
}
static void
F_169 ( struct V_6 * V_14 , unsigned int V_205 ,
unsigned int V_339 )
{
if ( V_14 -> V_340 )
V_14 -> V_340 ( V_14 , V_205 , V_339 ) ;
else
F_168 ( V_14 , V_205 , V_339 ) ;
}
static unsigned int F_170 ( struct V_1 * V_341 )
{
if ( V_341 -> V_14 . V_342 )
return V_341 -> V_14 . V_342 ;
if ( V_341 -> V_14 . V_19 == V_25 ) {
if ( V_341 -> V_14 . type == V_343 )
return 0x100 ;
return 0x1000 ;
}
if ( F_171 ( V_341 ) )
return 0x16 << V_341 -> V_14 . V_12 ;
return 8 << V_341 -> V_14 . V_12 ;
}
static int F_172 ( struct V_1 * V_2 )
{
unsigned int V_344 = F_170 ( V_2 ) ;
struct V_6 * V_14 = & V_2 -> V_14 ;
int V_233 = 0 ;
switch ( V_14 -> V_19 ) {
case V_25 :
case V_345 :
case V_23 :
case V_24 :
case V_22 :
case V_21 :
if ( ! V_14 -> V_139 )
break;
if ( ! F_173 ( V_14 -> V_139 , V_344 , L_23 ) ) {
V_233 = - V_346 ;
break;
}
if ( V_14 -> V_44 & V_347 ) {
V_14 -> V_11 = F_174 ( V_14 -> V_139 , V_344 ) ;
if ( ! V_14 -> V_11 ) {
F_175 ( V_14 -> V_139 , V_344 ) ;
V_233 = - V_53 ;
}
}
break;
case V_20 :
case V_348 :
if ( ! F_176 ( V_14 -> V_16 , V_344 , L_23 ) )
V_233 = - V_346 ;
break;
}
return V_233 ;
}
static void F_177 ( struct V_1 * V_2 )
{
unsigned int V_344 = F_170 ( V_2 ) ;
struct V_6 * V_14 = & V_2 -> V_14 ;
switch ( V_14 -> V_19 ) {
case V_25 :
case V_345 :
case V_23 :
case V_24 :
case V_22 :
case V_21 :
if ( ! V_14 -> V_139 )
break;
if ( V_14 -> V_44 & V_347 ) {
F_178 ( V_14 -> V_11 ) ;
V_14 -> V_11 = NULL ;
}
F_175 ( V_14 -> V_139 , V_344 ) ;
break;
case V_20 :
case V_348 :
F_179 ( V_14 -> V_16 , V_344 ) ;
break;
}
}
static void F_180 ( struct V_6 * V_14 )
{
struct V_1 * V_2 = F_35 ( V_14 ) ;
F_177 ( V_2 ) ;
}
static int F_181 ( struct V_6 * V_14 )
{
struct V_1 * V_2 = F_35 ( V_14 ) ;
return F_172 ( V_2 ) ;
}
static int F_182 ( struct V_1 * V_2 )
{
const struct V_349 * V_350 = & V_148 [ V_2 -> V_14 . type ] ;
unsigned char V_351 ;
V_351 = V_350 -> V_352 [ F_183 ( V_2 -> V_47 ) ] ;
return V_351 ? V_351 : - V_353 ;
}
static int F_184 ( struct V_1 * V_2 , unsigned char V_351 )
{
const struct V_349 * V_350 = & V_148 [ V_2 -> V_14 . type ] ;
int V_354 ;
if ( ! V_350 -> V_352 [ F_183 ( V_355 ) ] )
return - V_353 ;
for ( V_354 = 1 ; V_354 < V_356 ; V_354 ++ ) {
if ( V_351 < V_350 -> V_352 [ V_354 ] )
return ( -- V_354 ) << V_357 ;
}
return V_358 ;
}
static int F_185 ( struct V_359 * V_14 )
{
struct V_360 * V_205 = F_186 ( V_14 , struct V_360 , V_14 ) ;
struct V_6 * V_361 = V_205 -> V_6 ;
struct V_1 * V_2 = F_35 ( V_361 ) ;
if ( ! ( V_2 -> V_35 & V_36 ) || V_361 -> V_147 <= 1 )
return - V_362 ;
return F_182 ( V_2 ) ;
}
static int F_187 ( struct V_359 * V_14 )
{
int V_352 ;
F_188 ( & V_14 -> V_363 ) ;
V_352 = F_185 ( V_14 ) ;
F_189 ( & V_14 -> V_363 ) ;
return V_352 ;
}
static T_2 F_190 ( struct V_364 * V_49 ,
struct V_365 * V_366 , char * V_210 )
{
struct V_359 * V_14 = F_191 ( V_49 ) ;
int V_352 ;
V_352 = F_187 ( V_14 ) ;
if ( V_352 < 0 )
return V_352 ;
return snprintf ( V_210 , V_367 , L_24 , V_352 ) ;
}
static int F_192 ( struct V_359 * V_14 , unsigned char V_351 )
{
struct V_360 * V_205 = F_186 ( V_14 , struct V_360 , V_14 ) ;
struct V_6 * V_361 = V_205 -> V_6 ;
struct V_1 * V_2 = F_35 ( V_361 ) ;
int V_368 ;
if ( ! ( V_2 -> V_35 & V_36 ) || V_361 -> V_147 <= 1 ||
V_2 -> V_310 )
return - V_362 ;
V_368 = F_184 ( V_2 , V_351 ) ;
if ( V_368 < 0 )
return V_368 ;
F_40 ( V_2 ) ;
V_2 -> V_47 &= ~ V_321 ;
V_2 -> V_47 |= ( unsigned char ) V_368 ;
F_4 ( V_2 , V_37 , V_2 -> V_47 ) ;
return 0 ;
}
static int F_193 ( struct V_359 * V_14 , unsigned char V_351 )
{
int V_233 ;
F_188 ( & V_14 -> V_363 ) ;
V_233 = F_192 ( V_14 , V_351 ) ;
F_189 ( & V_14 -> V_363 ) ;
return V_233 ;
}
static T_2 F_194 ( struct V_364 * V_49 ,
struct V_365 * V_366 , const char * V_210 , T_3 V_89 )
{
struct V_359 * V_14 = F_191 ( V_49 ) ;
unsigned char V_351 ;
int V_233 ;
if ( ! V_89 )
return - V_362 ;
V_233 = F_195 ( V_210 , 10 , & V_351 ) ;
if ( V_233 < 0 )
return V_233 ;
V_233 = F_193 ( V_14 , V_351 ) ;
if ( V_233 < 0 )
return V_233 ;
return V_89 ;
}
static void F_196 ( struct V_1 * V_2 )
{
const struct V_349 * V_350 = & V_148 [ V_2 -> V_14 . type ] ;
if ( V_350 -> V_352 [ 0 ] )
V_2 -> V_14 . V_369 = & V_370 ;
}
static void F_197 ( struct V_6 * V_14 , int V_44 )
{
struct V_1 * V_2 = F_35 ( V_14 ) ;
int V_233 ;
V_233 = F_172 ( V_2 ) ;
if ( V_233 < 0 )
return;
if ( V_14 -> V_19 != V_2 -> V_26 )
F_34 ( V_14 ) ;
if ( V_44 & V_371 )
F_74 ( V_2 ) ;
if ( V_14 -> type == V_117 && V_14 -> V_19 == V_25 )
V_2 -> V_106 |= V_185 ;
if ( V_14 -> type == V_372 )
V_2 -> V_106 |= V_185 ;
if ( V_14 -> type != V_143 && V_44 & V_373 )
F_82 ( V_2 ) ;
if ( V_14 -> type == V_143 )
F_177 ( V_2 ) ;
if ( ( V_14 -> type == V_64 ) ||
( V_14 -> type == V_65 ) )
V_14 -> V_27 = F_128 ;
F_196 ( V_2 ) ;
V_2 -> V_47 = V_148 [ V_2 -> V_14 . type ] . V_47 ;
}
static int
F_198 ( struct V_6 * V_14 , struct V_374 * V_375 )
{
if ( V_375 -> V_157 >= V_376 || V_375 -> V_157 < 0 ||
V_375 -> V_377 < 9600 || V_375 -> type < V_143 ||
V_375 -> type >= F_6 ( V_148 ) || V_375 -> type == V_378 ||
V_375 -> type == V_379 )
return - V_362 ;
return 0 ;
}
static const char * F_199 ( struct V_6 * V_14 )
{
int type = V_14 -> type ;
if ( type >= F_6 ( V_148 ) )
type = 0 ;
return V_148 [ type ] . V_152 ;
}
void F_200 ( struct V_1 * V_2 )
{
struct V_6 * V_14 = & V_2 -> V_14 ;
F_201 ( & V_14 -> V_82 ) ;
V_14 -> V_281 = & V_380 ;
V_2 -> V_26 = 0xFF ;
}
void F_202 ( struct V_1 * V_2 )
{
struct V_6 * V_14 = & V_2 -> V_14 ;
if ( V_2 -> V_14 . V_44 & V_381 ) {
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
V_2 -> V_175 -> V_176 = V_382 ;
if ( ! V_2 -> V_175 -> V_230 )
V_2 -> V_175 -> V_230 = V_383 ;
}
}
static void F_203 ( struct V_6 * V_14 , int V_187 )
{
struct V_1 * V_2 = F_35 ( V_14 ) ;
F_135 ( V_2 , V_180 ) ;
F_92 ( V_14 , V_92 , V_187 ) ;
}
static void F_204 ( struct V_1 * V_2 )
{
struct V_6 * V_14 = & V_2 -> V_14 ;
struct V_317 V_318 ;
unsigned int V_291 , V_125 , V_292 = 0 ;
V_318 . V_295 = V_14 -> V_384 -> V_385 ;
if ( V_14 -> V_205 -> V_14 . V_386 && V_318 . V_295 == 0 )
V_318 . V_295 = V_14 -> V_205 -> V_14 . V_386 -> V_318 . V_295 ;
V_291 = F_159 ( V_14 , & V_318 , NULL ) ;
V_125 = F_153 ( V_2 , V_291 , & V_292 ) ;
F_157 ( V_14 , V_291 , V_125 , V_292 ) ;
F_92 ( V_14 , V_29 , V_2 -> V_62 ) ;
F_92 ( V_14 , V_42 , V_161 | V_46 ) ;
}
void F_205 ( struct V_1 * V_2 , const char * V_387 ,
unsigned int V_89 )
{
struct V_6 * V_14 = & V_2 -> V_14 ;
unsigned long V_44 ;
unsigned int V_162 ;
int V_388 = 1 ;
F_136 () ;
F_43 ( V_2 ) ;
if ( V_14 -> V_389 )
V_388 = 0 ;
else if ( V_390 )
V_388 = F_206 ( & V_14 -> V_82 , V_44 ) ;
else
F_76 ( & V_14 -> V_82 , V_44 ) ;
V_162 = F_127 ( V_14 , V_73 ) ;
if ( V_2 -> V_35 & V_131 )
F_92 ( V_14 , V_73 , V_129 ) ;
else
F_92 ( V_14 , V_73 , 0 ) ;
if ( V_2 -> V_391 && ( V_2 -> V_391 != F_127 ( V_14 , V_30 ) ) ) {
F_204 ( V_2 ) ;
V_2 -> V_391 = 0 ;
}
F_207 ( V_14 , V_387 , V_89 , F_203 ) ;
F_135 ( V_2 , V_173 ) ;
F_92 ( V_14 , V_73 , V_162 ) ;
if ( V_2 -> V_216 )
F_120 ( V_2 ) ;
if ( V_388 )
F_78 ( & V_14 -> V_82 , V_44 ) ;
F_45 ( V_2 ) ;
}
static unsigned int F_208 ( struct V_6 * V_14 )
{
unsigned char V_62 , V_392 , V_393 ;
unsigned int V_125 ;
V_62 = F_127 ( V_14 , V_29 ) ;
F_92 ( V_14 , V_29 , V_62 | V_316 ) ;
V_392 = F_127 ( V_14 , V_3 ) ;
V_393 = F_127 ( V_14 , V_4 ) ;
F_92 ( V_14 , V_29 , V_62 ) ;
V_125 = ( V_393 << 8 ) | V_392 ;
return ( V_14 -> V_79 / 16 ) / V_125 ;
}
int F_209 ( struct V_6 * V_14 , char * V_394 , bool V_145 )
{
int V_291 = 9600 ;
int V_257 = 8 ;
int V_197 = 'n' ;
int V_395 = 'n' ;
if ( ! V_14 -> V_16 && ! V_14 -> V_11 )
return - V_268 ;
if ( V_394 )
F_210 ( V_394 , & V_291 , & V_197 , & V_257 , & V_395 ) ;
else if ( V_145 )
V_291 = F_208 ( V_14 ) ;
return F_211 ( V_14 , V_14 -> V_384 , V_291 , V_197 , V_257 , V_395 ) ;
}
