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
F_52 ( & V_7 -> V_49 -> V_53 , V_54 ,
V_55 ) ;
F_52 ( & V_7 -> V_49 -> V_56 , V_54 ,
V_55 ) ;
V_7 -> V_49 -> V_53 . V_57 = & V_58 ;
V_7 -> V_49 -> V_56 . V_57 = & V_59 ;
V_7 -> V_49 -> V_14 = V_7 ;
V_7 -> V_49 -> V_60 = NULL ;
F_41 ( V_7 ) ;
return 0 ;
}
void F_53 ( struct V_1 * V_7 )
{
if ( ! V_7 -> V_49 )
return;
F_54 ( & V_7 -> V_49 -> V_56 ) ;
F_54 ( & V_7 -> V_49 -> V_53 ) ;
F_55 ( V_7 -> V_49 ) ;
V_7 -> V_49 = NULL ;
}
void F_56 ( struct V_1 * V_7 )
{
unsigned char V_61 ;
if ( ! ( V_7 -> V_35 & V_47 ) )
return;
V_61 = F_57 ( & V_7 -> V_62 , 1 ) ;
if ( V_61 )
return;
F_46 ( V_7 -> V_14 . V_48 ) ;
}
void F_58 ( struct V_1 * V_7 )
{
unsigned char V_61 ;
if ( ! ( V_7 -> V_35 & V_47 ) )
return;
V_61 = F_57 ( & V_7 -> V_62 , 0 ) ;
if ( ! V_61 )
return;
F_48 ( V_7 -> V_14 . V_48 ) ;
F_49 ( V_7 -> V_14 . V_48 ) ;
}
static void F_59 ( struct V_1 * V_7 , int V_63 )
{
unsigned char V_64 = 0 , V_65 = 0 ;
F_45 ( V_7 ) ;
if ( ( V_7 -> V_14 . type == V_66 ) ||
( V_7 -> V_14 . type == V_67 ) ) {
F_4 ( V_7 , V_68 , V_63 ? 0xff : 0 ) ;
goto V_69;
}
if ( V_7 -> V_35 & V_70 ) {
if ( V_7 -> V_35 & V_71 ) {
V_64 = F_2 ( V_7 , V_29 ) ;
V_65 = F_2 ( V_7 , V_72 ) ;
F_4 ( V_7 , V_29 , V_73 ) ;
F_4 ( V_7 , V_72 , V_74 ) ;
F_4 ( V_7 , V_29 , 0 ) ;
}
F_4 ( V_7 , V_75 , V_63 ? V_76 : 0 ) ;
if ( V_7 -> V_35 & V_71 ) {
F_4 ( V_7 , V_29 , V_73 ) ;
F_4 ( V_7 , V_72 , V_65 ) ;
F_4 ( V_7 , V_29 , V_64 ) ;
}
}
V_69:
F_47 ( V_7 ) ;
}
static int F_60 ( struct V_1 * V_2 )
{
unsigned char V_77 ;
int V_78 ;
V_77 = F_2 ( V_2 , V_79 ) ;
V_78 = V_77 & V_80 ;
if ( ! V_78 ) {
F_4 ( V_2 , V_79 , V_77 | V_80 ) ;
V_77 = F_2 ( V_2 , V_79 ) ;
V_78 = V_77 & V_80 ;
}
if ( V_78 )
V_2 -> V_14 . V_81 = V_82 * 16 ;
return V_78 ;
}
static void F_61 ( struct V_1 * V_2 )
{
if ( V_2 -> V_14 . type == V_83 ) {
if ( V_2 -> V_14 . V_81 != V_82 * 16 ) {
F_62 ( & V_2 -> V_14 . V_84 ) ;
F_60 ( V_2 ) ;
F_63 ( & V_2 -> V_14 . V_84 ) ;
}
if ( V_2 -> V_14 . V_81 == V_82 * 16 )
F_4 ( V_2 , V_85 , 0 ) ;
}
}
static void F_64 ( struct V_1 * V_2 )
{
unsigned char V_77 ;
int V_78 ;
if ( V_2 -> V_14 . type == V_83 &&
V_2 -> V_14 . V_81 == V_82 * 16 ) {
F_62 ( & V_2 -> V_14 . V_84 ) ;
V_77 = F_2 ( V_2 , V_79 ) ;
V_78 = ! ( V_77 & V_80 ) ;
if ( ! V_78 ) {
F_4 ( V_2 , V_79 , V_77 & ~ V_80 ) ;
V_77 = F_2 ( V_2 , V_79 ) ;
V_78 = ! ( V_77 & V_80 ) ;
}
if ( V_78 )
V_2 -> V_14 . V_81 = V_86 * 16 ;
F_63 ( & V_2 -> V_14 . V_84 ) ;
}
}
static int F_65 ( struct V_1 * V_2 )
{
unsigned char V_87 , V_88 , V_89 ;
unsigned short V_90 ;
int V_91 ;
V_89 = F_2 ( V_2 , V_29 ) ;
F_4 ( V_2 , V_29 , 0 ) ;
V_87 = F_2 ( V_2 , V_37 ) ;
V_88 = F_42 ( V_2 ) ;
F_4 ( V_2 , V_37 , V_38 |
V_39 | V_40 ) ;
F_43 ( V_2 , V_92 ) ;
F_4 ( V_2 , V_29 , V_93 ) ;
V_90 = F_66 ( V_2 ) ;
F_67 ( V_2 , 0x0001 ) ;
F_4 ( V_2 , V_29 , 0x03 ) ;
for ( V_91 = 0 ; V_91 < 256 ; V_91 ++ )
F_4 ( V_2 , V_94 , V_91 ) ;
F_68 ( 20 ) ;
for ( V_91 = 0 ; ( F_2 ( V_2 , V_95 ) & V_96 ) &&
( V_91 < 256 ) ; V_91 ++ )
F_2 ( V_2 , V_97 ) ;
F_4 ( V_2 , V_37 , V_87 ) ;
F_43 ( V_2 , V_88 ) ;
F_4 ( V_2 , V_29 , V_93 ) ;
F_67 ( V_2 , V_90 ) ;
F_4 ( V_2 , V_29 , V_89 ) ;
return V_91 ;
}
static unsigned int F_69 ( struct V_1 * V_7 )
{
unsigned char V_89 ;
unsigned int V_98 , V_90 ;
V_89 = F_2 ( V_7 , V_29 ) ;
F_4 ( V_7 , V_29 , V_93 ) ;
V_90 = F_66 ( V_7 ) ;
F_67 ( V_7 , 0 ) ;
V_98 = F_66 ( V_7 ) ;
F_67 ( V_7 , V_90 ) ;
F_4 ( V_7 , V_29 , V_89 ) ;
return V_98 ;
}
static void F_70 ( struct V_1 * V_2 )
{
unsigned int V_99 , V_100 , V_101 , V_102 ;
V_2 -> V_35 |= V_71 | V_70 ;
V_2 -> V_33 = 0 ;
F_4 ( V_2 , V_29 , V_73 ) ;
F_4 ( V_2 , V_72 , V_74 ) ;
F_4 ( V_2 , V_29 , 0x00 ) ;
V_99 = F_39 ( V_2 , V_103 ) ;
V_100 = F_39 ( V_2 , V_104 ) ;
V_101 = F_39 ( V_2 , V_105 ) ;
V_102 = F_39 ( V_2 , V_106 ) ;
F_71 ( L_1 , V_99 , V_100 , V_101 , V_102 ) ;
if ( V_99 == 0x16 && V_100 == 0xC9 &&
( V_101 == 0x50 || V_101 == 0x52 || V_101 == 0x54 ) ) {
V_2 -> V_14 . type = V_107 ;
if ( V_101 == 0x52 && V_102 == 0x01 )
V_2 -> V_108 |= V_109 ;
return;
}
V_99 = F_69 ( V_2 ) ;
F_71 ( L_2 , V_99 ) ;
V_100 = V_99 >> 8 ;
if ( V_100 == 0x10 || V_100 == 0x12 || V_100 == 0x14 ) {
V_2 -> V_14 . type = V_110 ;
return;
}
if ( F_65 ( V_2 ) == 64 )
V_2 -> V_14 . type = V_111 ;
else
V_2 -> V_14 . type = V_112 ;
}
static void F_72 ( struct V_1 * V_2 )
{
unsigned char V_113 , V_114 , V_115 ;
V_2 -> V_14 . type = V_116 ;
V_113 = F_2 ( V_2 , V_30 ) ;
F_4 ( V_2 , V_30 , 0xa5 ) ;
V_114 = F_2 ( V_2 , V_30 ) ;
F_4 ( V_2 , V_30 , 0x5a ) ;
V_115 = F_2 ( V_2 , V_30 ) ;
F_4 ( V_2 , V_30 , V_113 ) ;
if ( V_114 == 0xa5 && V_115 == 0x5a )
V_2 -> V_14 . type = V_117 ;
}
static int F_73 ( struct V_1 * V_2 )
{
if ( F_69 ( V_2 ) == 0x0201 && F_65 ( V_2 ) == 16 )
return 1 ;
return 0 ;
}
static void F_74 ( struct V_1 * V_2 )
{
unsigned char V_114 , V_115 ;
unsigned int V_118 ;
V_2 -> V_14 . type = V_119 ;
V_2 -> V_35 |= V_36 ;
if ( V_2 -> V_14 . V_43 & V_120 ) {
V_114 = F_2 ( V_2 , V_121 ) ;
if ( V_114 == 0x82 || V_114 == 0x84 || V_114 == 0x88 ) {
F_71 ( L_3 ) ;
V_2 -> V_14 . type = V_66 ;
V_2 -> V_35 |= V_122 | V_71 |
V_70 ;
return;
}
}
F_4 ( V_2 , V_29 , V_93 ) ;
if ( F_2 ( V_2 , V_72 ) == 0 ) {
F_4 ( V_2 , V_72 , 0xA8 ) ;
if ( F_2 ( V_2 , V_72 ) != 0 ) {
F_71 ( L_4 ) ;
V_2 -> V_14 . type = V_123 ;
V_2 -> V_35 |= V_71 | V_70 ;
} else {
F_4 ( V_2 , V_29 , 0 ) ;
F_4 ( V_2 , V_37 , V_38 |
V_124 ) ;
V_114 = F_2 ( V_2 , V_125 ) >> 5 ;
F_4 ( V_2 , V_37 , 0 ) ;
F_4 ( V_2 , V_29 , 0 ) ;
if ( V_114 == 7 )
V_2 -> V_14 . type = V_126 ;
else
F_71 ( L_5 ) ;
}
F_4 ( V_2 , V_72 , 0 ) ;
return;
}
F_4 ( V_2 , V_29 , V_73 ) ;
if ( F_2 ( V_2 , V_72 ) == 0 && ! F_73 ( V_2 ) ) {
F_71 ( L_6 ) ;
F_70 ( V_2 ) ;
return;
}
F_4 ( V_2 , V_29 , 0 ) ;
V_114 = F_42 ( V_2 ) ;
F_4 ( V_2 , V_29 , 0xE0 ) ;
V_115 = F_2 ( V_2 , 0x02 ) ;
if ( ! ( ( V_115 ^ V_114 ) & V_92 ) ) {
F_4 ( V_2 , V_29 , 0 ) ;
F_43 ( V_2 , V_114 ^ V_92 ) ;
F_4 ( V_2 , V_29 , 0xE0 ) ;
V_115 = F_2 ( V_2 , 0x02 ) ;
F_4 ( V_2 , V_29 , 0 ) ;
F_43 ( V_2 , V_114 ) ;
if ( ( V_115 ^ V_114 ) & V_92 ) {
unsigned short V_127 ;
F_4 ( V_2 , V_29 , 0xE0 ) ;
V_127 = F_66 ( V_2 ) ;
V_127 <<= 3 ;
if ( F_75 ( V_2 ) )
F_67 ( V_2 , V_127 ) ;
F_4 ( V_2 , V_29 , 0 ) ;
V_2 -> V_14 . V_81 = 921600 * 16 ;
V_2 -> V_14 . type = V_128 ;
V_2 -> V_35 |= V_129 ;
return;
}
}
F_4 ( V_2 , V_29 , 0 ) ;
F_4 ( V_2 , V_37 , V_38 | V_124 ) ;
V_114 = F_2 ( V_2 , V_125 ) >> 5 ;
F_4 ( V_2 , V_37 , V_38 ) ;
F_4 ( V_2 , V_29 , V_93 ) ;
F_4 ( V_2 , V_37 , V_38 | V_124 ) ;
V_115 = F_2 ( V_2 , V_125 ) >> 5 ;
F_4 ( V_2 , V_37 , V_38 ) ;
F_4 ( V_2 , V_29 , 0 ) ;
F_71 ( L_7 , V_114 , V_115 ) ;
if ( V_114 == 6 && V_115 == 7 ) {
V_2 -> V_14 . type = V_130 ;
V_2 -> V_35 |= V_122 | V_70 ;
return;
}
V_118 = F_2 ( V_2 , V_75 ) ;
F_4 ( V_2 , V_75 , V_118 & ~ V_131 ) ;
if ( ! ( F_2 ( V_2 , V_75 ) & V_131 ) ) {
F_4 ( V_2 , V_75 , V_118 | V_131 ) ;
if ( F_2 ( V_2 , V_75 ) & V_131 ) {
F_71 ( L_8 ) ;
V_2 -> V_14 . type = V_132 ;
V_2 -> V_35 |= V_133 | V_134 ;
return;
}
} else {
F_71 ( L_9 ) ;
}
F_4 ( V_2 , V_75 , V_118 ) ;
if ( V_2 -> V_14 . V_43 & V_120 ) {
F_71 ( L_10 ) ;
V_2 -> V_14 . type = V_67 ;
V_2 -> V_35 |= V_122 | V_71 |
V_70 ;
return;
}
if ( V_2 -> V_14 . type == V_119 && F_65 ( V_2 ) == 64 ) {
V_2 -> V_14 . type = V_135 ;
V_2 -> V_35 |= V_122 ;
}
}
static void F_76 ( struct V_1 * V_2 )
{
unsigned char V_114 , V_113 , V_136 , V_137 ;
unsigned char V_138 , V_139 ;
struct V_6 * V_14 = & V_2 -> V_14 ;
unsigned long V_43 ;
unsigned int V_140 ;
if ( ! V_14 -> V_16 && ! V_14 -> V_141 && ! V_14 -> V_11 )
return;
F_71 ( L_11 ,
F_77 ( V_14 ) , V_14 -> V_16 , V_14 -> V_11 ) ;
F_78 ( & V_14 -> V_84 , V_43 ) ;
V_2 -> V_35 = 0 ;
V_2 -> V_108 = 0 ;
if ( ! ( V_14 -> V_43 & V_142 ) ) {
V_113 = F_2 ( V_2 , V_75 ) ;
F_4 ( V_2 , V_75 , 0 ) ;
#ifdef F_79
F_13 ( 0xff , 0x080 ) ;
#endif
V_136 = F_2 ( V_2 , V_75 ) & 0x0f ;
F_4 ( V_2 , V_75 , 0x0F ) ;
#ifdef F_79
F_13 ( 0 , 0x080 ) ;
#endif
V_137 = F_2 ( V_2 , V_75 ) & 0x0f ;
F_4 ( V_2 , V_75 , V_113 ) ;
if ( V_136 != 0 || V_137 != 0x0F ) {
F_80 ( & V_14 -> V_84 , V_43 ) ;
F_71 ( L_12 ,
V_136 , V_137 ) ;
goto V_69;
}
}
V_139 = F_42 ( V_2 ) ;
V_138 = F_2 ( V_2 , V_29 ) ;
if ( ! ( V_14 -> V_43 & V_143 ) ) {
F_43 ( V_2 , V_92 | 0x0A ) ;
V_114 = F_2 ( V_2 , V_144 ) & 0xF0 ;
F_43 ( V_2 , V_139 ) ;
if ( V_114 != 0x90 ) {
F_80 ( & V_14 -> V_84 , V_43 ) ;
F_71 ( L_13 ,
V_114 ) ;
goto V_69;
}
}
F_4 ( V_2 , V_29 , V_73 ) ;
F_4 ( V_2 , V_72 , 0 ) ;
F_4 ( V_2 , V_29 , 0 ) ;
F_4 ( V_2 , V_37 , V_38 ) ;
V_113 = F_2 ( V_2 , V_125 ) >> 6 ;
switch ( V_113 ) {
case 0 :
F_72 ( V_2 ) ;
break;
case 1 :
V_14 -> type = V_145 ;
break;
case 2 :
V_14 -> type = V_146 ;
break;
case 3 :
F_74 ( V_2 ) ;
break;
}
#ifdef F_81
if ( V_14 -> type == V_119 && V_2 -> V_147 & V_148 &&
F_60 ( V_2 ) )
V_14 -> type = V_83 ;
#endif
F_4 ( V_2 , V_29 , V_138 ) ;
V_14 -> V_149 = V_150 [ V_2 -> V_14 . type ] . V_151 ;
V_140 = V_2 -> V_35 ;
V_2 -> V_35 = V_150 [ V_14 -> type ] . V_43 ;
V_2 -> V_152 = V_150 [ V_14 -> type ] . V_152 ;
if ( V_14 -> type == V_145 )
goto V_153;
#ifdef F_81
if ( V_14 -> type == V_83 )
F_4 ( V_2 , V_85 , 0 ) ;
#endif
F_43 ( V_2 , V_139 ) ;
F_40 ( V_2 ) ;
F_2 ( V_2 , V_97 ) ;
if ( V_2 -> V_35 & V_133 )
F_4 ( V_2 , V_75 , V_131 ) ;
else
F_4 ( V_2 , V_75 , 0 ) ;
V_153:
F_80 ( & V_14 -> V_84 , V_43 ) ;
if ( V_14 -> type == V_119 && V_14 -> V_19 == V_154 )
F_82 ( V_2 ) ;
if ( V_2 -> V_35 != V_140 ) {
F_83 ( L_14 ,
F_77 ( V_14 ) , V_140 ,
V_2 -> V_35 ) ;
}
V_69:
F_71 ( L_15 , V_113 ) ;
F_71 ( L_16 , V_150 [ V_14 -> type ] . V_155 ) ;
}
static void F_84 ( struct V_1 * V_2 )
{
struct V_6 * V_14 = & V_2 -> V_14 ;
unsigned char V_139 , V_156 ;
unsigned char V_157 = 0 ;
unsigned int V_158 = 0 ;
unsigned long V_159 ;
int V_160 ;
if ( V_14 -> V_43 & V_161 ) {
V_158 = ( V_14 -> V_16 & 0xfe0 ) | 0x1f ;
V_157 = F_85 ( V_158 ) ;
F_86 ( 0x80 , V_158 ) ;
F_85 ( V_158 ) ;
}
if ( F_87 ( V_14 ) )
F_88 () ;
F_89 ( F_90 () ) ;
V_139 = F_42 ( V_2 ) ;
V_156 = F_2 ( V_2 , V_75 ) ;
F_43 ( V_2 , V_162 | V_163 ) ;
V_159 = F_90 () ;
F_43 ( V_2 , 0 ) ;
F_91 ( 10 ) ;
if ( V_14 -> V_43 & V_161 ) {
F_43 ( V_2 , V_164 | V_45 ) ;
} else {
F_43 ( V_2 ,
V_164 | V_45 | V_163 ) ;
}
F_4 ( V_2 , V_75 , 0x0f ) ;
F_2 ( V_2 , V_95 ) ;
F_2 ( V_2 , V_97 ) ;
F_2 ( V_2 , V_125 ) ;
F_2 ( V_2 , V_144 ) ;
F_4 ( V_2 , V_94 , 0xFF ) ;
F_91 ( 20 ) ;
V_160 = F_89 ( V_159 ) ;
F_43 ( V_2 , V_139 ) ;
F_4 ( V_2 , V_75 , V_156 ) ;
if ( V_14 -> V_43 & V_161 )
F_86 ( V_157 , V_158 ) ;
if ( F_87 ( V_14 ) )
F_92 () ;
V_14 -> V_160 = ( V_160 > 0 ) ? V_160 : 0 ;
}
static void F_93 ( struct V_6 * V_14 )
{
struct V_1 * V_2 = F_35 ( V_14 ) ;
F_45 ( V_2 ) ;
V_2 -> V_165 &= ~ ( V_166 | V_167 ) ;
V_2 -> V_14 . V_168 &= ~ V_96 ;
F_94 ( V_14 , V_75 , V_2 -> V_165 ) ;
F_47 ( V_2 ) ;
}
static void F_95 ( struct V_1 * V_7 )
{
F_41 ( V_7 ) ;
if ( ! ( V_7 -> V_14 . V_42 . V_43 & V_169 ) ) {
F_44 ( V_7 ) ;
V_7 -> V_165 |= V_166 | V_167 ;
F_94 ( & V_7 -> V_14 , V_75 , V_7 -> V_165 ) ;
}
}
static enum V_170 V_58 ( struct V_171 * V_172 )
{
struct V_50 * V_49 ;
struct V_1 * V_7 ;
unsigned long V_43 ;
V_49 = F_96 ( V_172 , struct V_50 , V_53 ) ;
V_7 = V_49 -> V_14 ;
F_45 ( V_7 ) ;
F_78 ( & V_7 -> V_14 . V_84 , V_43 ) ;
if ( V_49 -> V_60 == & V_49 -> V_53 ) {
F_95 ( V_7 ) ;
V_49 -> V_60 = NULL ;
}
F_80 ( & V_7 -> V_14 . V_84 , V_43 ) ;
F_47 ( V_7 ) ;
return V_173 ;
}
static void F_97 ( struct V_171 * V_174 , unsigned long V_175 )
{
long V_176 = V_175 / 1000 ;
long V_177 = ( V_175 % 1000 ) * 1000000 ;
T_1 V_172 = F_98 ( V_176 , V_177 ) ;
F_99 ( V_174 , V_172 , V_55 ) ;
}
static void F_100 ( struct V_1 * V_7 )
{
struct V_50 * V_49 = V_7 -> V_49 ;
if ( V_7 -> V_14 . V_42 . V_178 > 0 ) {
V_49 -> V_60 = & V_49 -> V_53 ;
F_97 ( & V_49 -> V_53 ,
V_7 -> V_14 . V_42 . V_178 ) ;
} else {
F_95 ( V_7 ) ;
}
}
static inline void F_101 ( struct V_1 * V_7 )
{
if ( V_7 -> V_165 & V_179 ) {
V_7 -> V_165 &= ~ V_179 ;
F_4 ( V_7 , V_75 , V_7 -> V_165 ) ;
F_58 ( V_7 ) ;
}
}
static inline void F_102 ( struct V_1 * V_7 )
{
struct V_50 * V_49 = V_7 -> V_49 ;
if ( V_49 ) {
unsigned char V_180 = F_2 ( V_7 , V_95 ) ;
if ( ( V_180 & V_181 ) != V_181 )
return;
V_49 -> V_60 = NULL ;
F_54 ( & V_49 -> V_56 ) ;
F_100 ( V_7 ) ;
}
F_101 ( V_7 ) ;
}
static void F_103 ( struct V_6 * V_14 )
{
struct V_1 * V_2 = F_35 ( V_14 ) ;
F_45 ( V_2 ) ;
F_102 ( V_2 ) ;
if ( V_14 -> type == V_107 ) {
V_2 -> V_33 |= V_182 ;
F_38 ( V_2 , V_32 , V_2 -> V_33 ) ;
}
F_47 ( V_2 ) ;
}
static inline void F_104 ( struct V_6 * V_14 )
{
struct V_1 * V_2 = F_35 ( V_14 ) ;
if ( V_2 -> V_183 && ! V_2 -> V_183 -> V_184 ( V_2 ) )
return;
if ( ! ( V_2 -> V_165 & V_179 ) ) {
V_2 -> V_165 |= V_179 ;
F_94 ( V_14 , V_75 , V_2 -> V_165 ) ;
if ( V_2 -> V_108 & V_185 ) {
unsigned char V_180 ;
V_180 = F_2 ( V_2 , V_95 ) ;
V_2 -> V_186 |= V_180 & V_187 ;
if ( V_180 & V_188 )
F_105 ( V_2 ) ;
}
}
if ( V_14 -> type == V_107 && V_2 -> V_33 & V_182 ) {
V_2 -> V_33 &= ~ V_182 ;
F_38 ( V_2 , V_32 , V_2 -> V_33 ) ;
}
}
static inline void F_106 ( struct V_6 * V_14 )
{
struct V_1 * V_2 = F_35 ( V_14 ) ;
struct V_50 * V_49 = V_2 -> V_49 ;
unsigned char V_41 ;
if ( ! ( V_2 -> V_14 . V_42 . V_43 & V_169 ) )
F_93 ( & V_2 -> V_14 ) ;
V_49 -> V_60 = NULL ;
if ( F_107 ( & V_49 -> V_53 ) )
F_54 ( & V_49 -> V_53 ) ;
V_41 = F_42 ( V_2 ) ;
if ( ! ! ( V_2 -> V_14 . V_42 . V_43 & V_189 ) !=
! ! ( V_41 & V_45 ) ) {
if ( V_2 -> V_14 . V_42 . V_43 & V_189 )
V_41 |= V_45 ;
else
V_41 &= ~ V_45 ;
F_43 ( V_2 , V_41 ) ;
if ( V_2 -> V_14 . V_42 . V_190 > 0 ) {
V_49 -> V_60 = & V_49 -> V_56 ;
F_97 ( & V_49 -> V_56 ,
V_2 -> V_14 . V_42 . V_190 ) ;
return;
}
}
F_104 ( V_14 ) ;
}
static enum V_170 V_59 ( struct V_171 * V_172 )
{
struct V_50 * V_49 ;
struct V_1 * V_7 ;
unsigned long V_43 ;
V_49 = F_96 ( V_172 , struct V_50 , V_56 ) ;
V_7 = V_49 -> V_14 ;
F_78 ( & V_7 -> V_14 . V_84 , V_43 ) ;
if ( V_49 -> V_60 == & V_49 -> V_56 ) {
F_104 ( & V_7 -> V_14 ) ;
V_49 -> V_60 = NULL ;
}
F_80 ( & V_7 -> V_14 . V_84 , V_43 ) ;
return V_173 ;
}
static void F_108 ( struct V_6 * V_14 )
{
struct V_1 * V_2 = F_35 ( V_14 ) ;
struct V_50 * V_49 = V_2 -> V_49 ;
F_56 ( V_2 ) ;
if ( V_49 &&
V_49 -> V_60 == & V_49 -> V_56 )
return;
if ( V_49 )
F_106 ( V_14 ) ;
else
F_104 ( V_14 ) ;
}
static void F_109 ( struct V_6 * V_14 )
{
V_14 -> V_191 ( V_14 ) ;
}
static void F_110 ( struct V_6 * V_14 )
{
V_14 -> V_192 ( V_14 ) ;
}
static void F_111 ( struct V_6 * V_14 )
{
struct V_1 * V_2 = F_35 ( V_14 ) ;
if ( V_2 -> V_108 & V_193 )
return;
V_2 -> V_165 &= ~ V_194 ;
F_94 ( V_14 , V_75 , V_2 -> V_165 ) ;
}
static void F_112 ( struct V_6 * V_14 )
{
struct V_1 * V_2 = F_35 ( V_14 ) ;
if ( V_2 -> V_108 & V_193 )
return;
V_2 -> V_165 |= V_194 ;
F_45 ( V_2 ) ;
F_94 ( V_14 , V_75 , V_2 -> V_165 ) ;
F_47 ( V_2 ) ;
}
static void F_113 ( struct V_1 * V_2 , unsigned char V_180 )
{
struct V_6 * V_14 = & V_2 -> V_14 ;
unsigned char V_195 ;
char V_196 = V_197 ;
if ( F_114 ( V_180 & V_96 ) )
V_195 = F_2 ( V_2 , V_97 ) ;
else
V_195 = 0 ;
V_14 -> V_198 . V_199 ++ ;
V_180 |= V_2 -> V_186 ;
V_2 -> V_186 = 0 ;
if ( F_115 ( V_180 & V_200 ) ) {
if ( V_180 & V_201 ) {
V_180 &= ~ ( V_202 | V_203 ) ;
V_14 -> V_198 . V_204 ++ ;
if ( F_116 ( V_14 ) )
return;
} else if ( V_180 & V_203 )
V_14 -> V_198 . V_205 ++ ;
else if ( V_180 & V_202 )
V_14 -> V_198 . V_206 ++ ;
if ( V_180 & V_207 )
V_14 -> V_198 . V_208 ++ ;
V_180 &= V_14 -> V_168 ;
if ( V_180 & V_201 ) {
F_117 ( L_17 , V_209 ) ;
V_196 = V_210 ;
} else if ( V_180 & V_203 )
V_196 = V_211 ;
else if ( V_180 & V_202 )
V_196 = V_212 ;
}
if ( F_118 ( V_14 , V_195 ) )
return;
F_119 ( V_14 , V_180 , V_207 , V_195 , V_196 ) ;
}
unsigned char F_120 ( struct V_1 * V_2 , unsigned char V_180 )
{
struct V_6 * V_14 = & V_2 -> V_14 ;
int V_213 = 256 ;
do {
F_113 ( V_2 , V_180 ) ;
if ( -- V_213 == 0 )
break;
V_180 = F_2 ( V_2 , V_95 ) ;
} while ( V_180 & ( V_96 | V_201 ) );
F_121 ( & V_14 -> V_214 -> V_14 ) ;
return V_180 ;
}
void F_105 ( struct V_1 * V_2 )
{
struct V_6 * V_14 = & V_2 -> V_14 ;
struct V_215 * V_216 = & V_14 -> V_214 -> V_216 ;
int V_91 ;
if ( V_14 -> V_217 ) {
F_4 ( V_2 , V_94 , V_14 -> V_217 ) ;
V_14 -> V_198 . V_218 ++ ;
V_14 -> V_217 = 0 ;
return;
}
if ( F_122 ( V_14 ) ) {
F_103 ( V_14 ) ;
return;
}
if ( F_123 ( V_216 ) ) {
F_102 ( V_2 ) ;
return;
}
V_91 = V_2 -> V_152 ;
do {
F_4 ( V_2 , V_94 , V_216 -> V_219 [ V_216 -> V_220 ] ) ;
V_216 -> V_220 = ( V_216 -> V_220 + 1 ) & ( V_221 - 1 ) ;
V_14 -> V_198 . V_218 ++ ;
if ( F_123 ( V_216 ) )
break;
if ( ( V_2 -> V_35 & V_222 ) &&
( F_2 ( V_2 , V_95 ) & V_181 ) != V_181 )
break;
if ( ( V_2 -> V_35 & V_223 ) &&
! ( F_2 ( V_2 , V_95 ) & V_188 ) )
break;
} while ( -- V_91 > 0 );
if ( F_124 ( V_216 ) < V_224 )
F_125 ( V_14 ) ;
if ( F_123 ( V_216 ) && ! ( V_2 -> V_35 & V_47 ) )
F_102 ( V_2 ) ;
}
unsigned int F_126 ( struct V_1 * V_2 )
{
struct V_6 * V_14 = & V_2 -> V_14 ;
unsigned int V_225 = F_2 ( V_2 , V_144 ) ;
V_225 |= V_2 -> V_226 ;
V_2 -> V_226 = 0 ;
if ( V_225 & V_227 && V_2 -> V_165 & V_194 &&
V_14 -> V_214 != NULL ) {
if ( V_225 & V_228 )
V_14 -> V_198 . V_229 ++ ;
if ( V_225 & V_230 )
V_14 -> V_198 . V_231 ++ ;
if ( V_225 & V_232 )
F_127 ( V_14 , V_225 & V_233 ) ;
if ( V_225 & V_234 )
F_128 ( V_14 , V_225 & V_235 ) ;
F_129 ( & V_14 -> V_214 -> V_14 . V_236 ) ;
}
return V_225 ;
}
static bool F_130 ( struct V_1 * V_2 , unsigned int V_237 )
{
switch ( V_237 & 0x3f ) {
case V_238 :
F_131 ( V_2 ) ;
case V_239 :
return true ;
}
return V_2 -> V_183 -> V_240 ( V_2 ) ;
}
int F_132 ( struct V_6 * V_14 , unsigned int V_237 )
{
unsigned char V_225 ;
unsigned long V_43 ;
struct V_1 * V_2 = F_35 ( V_14 ) ;
if ( V_237 & V_241 )
return 0 ;
F_78 ( & V_14 -> V_84 , V_43 ) ;
V_225 = F_133 ( V_14 , V_95 ) ;
if ( V_225 & ( V_96 | V_201 ) ) {
if ( ! V_2 -> V_183 || F_130 ( V_2 , V_237 ) )
V_225 = F_120 ( V_2 , V_225 ) ;
}
F_126 ( V_2 ) ;
if ( ( ! V_2 -> V_183 || V_2 -> V_183 -> V_242 ) && ( V_225 & V_188 ) )
F_105 ( V_2 ) ;
F_80 ( & V_14 -> V_84 , V_43 ) ;
return 1 ;
}
static int V_28 ( struct V_6 * V_14 )
{
struct V_1 * V_2 = F_35 ( V_14 ) ;
unsigned int V_237 ;
int V_243 ;
F_45 ( V_2 ) ;
V_237 = F_133 ( V_14 , V_125 ) ;
V_243 = F_132 ( V_14 , V_237 ) ;
F_47 ( V_2 ) ;
return V_243 ;
}
static int F_134 ( struct V_6 * V_14 )
{
unsigned int V_237 = F_133 ( V_14 , V_125 ) ;
int V_243 = 0 ;
if ( ( ( V_14 -> type == V_66 ) || ( V_14 -> type == V_67 ) ) &&
F_133 ( V_14 , V_244 ) != 0 )
V_243 = 1 ;
V_243 |= F_132 ( V_14 , V_237 ) ;
return V_243 ;
}
static int F_135 ( struct V_6 * V_14 )
{
unsigned long V_43 ;
unsigned int V_237 = F_133 ( V_14 , V_125 ) ;
if ( ( V_237 & V_245 ) == V_246 ) {
struct V_1 * V_2 = F_35 ( V_14 ) ;
F_78 ( & V_14 -> V_84 , V_43 ) ;
F_105 ( V_2 ) ;
F_80 ( & V_14 -> V_84 , V_43 ) ;
}
V_237 = F_133 ( V_14 , V_125 ) ;
return F_132 ( V_14 , V_237 ) ;
}
static unsigned int F_136 ( struct V_6 * V_14 )
{
struct V_1 * V_2 = F_35 ( V_14 ) ;
unsigned long V_43 ;
unsigned int V_180 ;
F_45 ( V_2 ) ;
F_78 ( & V_14 -> V_84 , V_43 ) ;
V_180 = F_133 ( V_14 , V_95 ) ;
V_2 -> V_186 |= V_180 & V_187 ;
F_80 ( & V_14 -> V_84 , V_43 ) ;
F_47 ( V_2 ) ;
return ( V_180 & V_181 ) == V_181 ? V_247 : 0 ;
}
unsigned int F_137 ( struct V_6 * V_14 )
{
struct V_1 * V_2 = F_35 ( V_14 ) ;
unsigned int V_225 ;
unsigned int V_243 ;
F_45 ( V_2 ) ;
V_225 = F_126 ( V_2 ) ;
F_47 ( V_2 ) ;
V_243 = 0 ;
if ( V_225 & V_233 )
V_243 |= V_248 ;
if ( V_225 & V_249 )
V_243 |= V_250 ;
if ( V_225 & V_251 )
V_243 |= V_252 ;
if ( V_225 & V_235 )
V_243 |= V_253 ;
return V_243 ;
}
static unsigned int F_138 ( struct V_6 * V_14 )
{
if ( V_14 -> V_254 )
return V_14 -> V_254 ( V_14 ) ;
return F_137 ( V_14 ) ;
}
void F_139 ( struct V_6 * V_14 , unsigned int V_255 )
{
struct V_1 * V_2 = F_35 ( V_14 ) ;
unsigned char V_41 = 0 ;
if ( V_255 & V_256 )
V_41 |= V_45 ;
if ( V_255 & V_257 )
V_41 |= V_164 ;
if ( V_255 & V_258 )
V_41 |= V_162 ;
if ( V_255 & V_259 )
V_41 |= V_163 ;
if ( V_255 & V_260 )
V_41 |= V_92 ;
V_41 = ( V_41 & V_2 -> V_261 ) | V_2 -> V_262 | V_2 -> V_41 ;
F_43 ( V_2 , V_41 ) ;
}
static void F_140 ( struct V_6 * V_14 , unsigned int V_255 )
{
if ( V_14 -> V_263 )
V_14 -> V_263 ( V_14 , V_255 ) ;
else
F_139 ( V_14 , V_255 ) ;
}
static void F_141 ( struct V_6 * V_14 , int V_264 )
{
struct V_1 * V_2 = F_35 ( V_14 ) ;
unsigned long V_43 ;
F_45 ( V_2 ) ;
F_78 ( & V_14 -> V_84 , V_43 ) ;
if ( V_264 == - 1 )
V_2 -> V_64 |= V_265 ;
else
V_2 -> V_64 &= ~ V_265 ;
F_94 ( V_14 , V_29 , V_2 -> V_64 ) ;
F_80 ( & V_14 -> V_84 , V_43 ) ;
F_47 ( V_2 ) ;
}
static void F_142 ( struct V_1 * V_2 , int V_266 )
{
unsigned int V_225 , V_267 = 10000 ;
for (; ; ) {
V_225 = F_2 ( V_2 , V_95 ) ;
V_2 -> V_186 |= V_225 & V_187 ;
if ( ( V_225 & V_266 ) == V_266 )
break;
if ( -- V_267 == 0 )
break;
F_91 ( 1 ) ;
F_143 () ;
}
if ( V_2 -> V_14 . V_43 & V_268 ) {
for ( V_267 = 1000000 ; V_267 ; V_267 -- ) {
unsigned int V_269 = F_2 ( V_2 , V_144 ) ;
V_2 -> V_226 |= V_269 & V_270 ;
if ( V_269 & V_235 )
break;
F_91 ( 1 ) ;
F_143 () ;
}
}
}
static int F_144 ( struct V_6 * V_14 )
{
struct V_1 * V_2 = F_35 ( V_14 ) ;
unsigned char V_180 ;
int V_225 ;
F_45 ( V_2 ) ;
V_180 = F_133 ( V_14 , V_95 ) ;
if ( ! ( V_180 & V_96 ) ) {
V_225 = V_271 ;
goto V_69;
}
V_225 = F_133 ( V_14 , V_97 ) ;
V_69:
F_47 ( V_2 ) ;
return V_225 ;
}
static void F_145 ( struct V_6 * V_14 ,
unsigned char V_272 )
{
unsigned int V_165 ;
struct V_1 * V_2 = F_35 ( V_14 ) ;
F_45 ( V_2 ) ;
V_165 = F_133 ( V_14 , V_75 ) ;
if ( V_2 -> V_35 & V_133 )
F_94 ( V_14 , V_75 , V_131 ) ;
else
F_94 ( V_14 , V_75 , 0 ) ;
F_142 ( V_2 , V_181 ) ;
F_94 ( V_14 , V_94 , V_272 ) ;
F_142 ( V_2 , V_181 ) ;
F_94 ( V_14 , V_75 , V_165 ) ;
F_47 ( V_2 ) ;
}
int F_146 ( struct V_6 * V_14 )
{
struct V_1 * V_2 = F_35 ( V_14 ) ;
unsigned long V_43 ;
unsigned char V_180 , V_237 ;
int V_273 ;
if ( ! V_14 -> V_149 )
V_14 -> V_149 = V_150 [ V_14 -> type ] . V_151 ;
if ( ! V_2 -> V_152 )
V_2 -> V_152 = V_150 [ V_14 -> type ] . V_152 ;
if ( ! V_2 -> V_35 )
V_2 -> V_35 = V_150 [ V_14 -> type ] . V_43 ;
V_2 -> V_41 = 0 ;
if ( V_14 -> V_19 != V_2 -> V_26 )
F_34 ( V_14 ) ;
F_45 ( V_2 ) ;
if ( V_14 -> type == V_107 ) {
V_2 -> V_33 = 0 ;
F_94 ( V_14 , V_29 , V_73 ) ;
F_94 ( V_14 , V_72 , V_74 ) ;
F_94 ( V_14 , V_75 , 0 ) ;
F_94 ( V_14 , V_29 , 0 ) ;
F_38 ( V_2 , V_274 , 0 ) ;
F_94 ( V_14 , V_29 , V_73 ) ;
F_94 ( V_14 , V_72 , V_74 ) ;
F_94 ( V_14 , V_29 , 0 ) ;
}
if ( V_14 -> type == V_275 ) {
F_94 ( V_14 , V_75 , 0 ) ;
F_94 ( V_14 , V_276 , 0 ) ;
F_68 ( 10 ) ;
F_94 ( V_14 , V_276 ,
V_277 |
V_278 |
V_279 ) ;
}
#ifdef F_81
F_61 ( V_2 ) ;
#endif
if ( V_14 -> type == V_66 ) {
F_94 ( V_14 , V_280 , V_74 ) ;
F_94 ( V_14 , V_75 , 0 ) ;
}
F_40 ( V_2 ) ;
F_133 ( V_14 , V_95 ) ;
F_133 ( V_14 , V_97 ) ;
F_133 ( V_14 , V_125 ) ;
F_133 ( V_14 , V_144 ) ;
if ( ( V_14 -> type == V_66 ) || ( V_14 -> type == V_67 ) )
F_133 ( V_14 , V_244 ) ;
if ( ! ( V_14 -> V_43 & V_142 ) &&
( F_133 ( V_14 , V_95 ) == 0xff ) ) {
F_147 ( V_281 L_18 ,
F_77 ( V_14 ) ) ;
V_273 = - V_282 ;
goto V_69;
}
if ( V_14 -> type == V_110 ) {
unsigned char V_283 ;
F_4 ( V_2 , V_29 , V_73 ) ;
V_283 = F_2 ( V_2 , V_284 ) & ~ ( V_285 | V_286 ) ;
F_94 ( V_14 , V_284 ,
V_283 | V_287 | V_285 ) ;
F_94 ( V_14 , V_288 , V_289 ) ;
F_94 ( V_14 , V_284 ,
V_283 | V_287 | V_286 ) ;
F_94 ( V_14 , V_288 , V_289 ) ;
F_94 ( V_14 , V_29 , 0 ) ;
}
if ( ( ( V_14 -> type == V_290 ) ||
( V_14 -> type == V_291 ) ||
( V_14 -> type == V_292 ) ) && ( V_14 -> V_149 > 1 ) ) {
if ( ( V_2 -> V_152 < 2 ) || ( V_2 -> V_152 > V_14 -> V_149 ) ) {
F_148 ( L_19 ,
F_77 ( V_14 ) ) ;
} else {
F_94 ( V_14 , V_293 ,
V_294 ) ;
F_94 ( V_14 , V_295 ,
V_14 -> V_149 - V_2 -> V_152 ) ;
V_14 -> V_27 = F_135 ;
}
}
if ( V_14 -> V_160 && ! ( V_2 -> V_14 . V_43 & V_296 ) ) {
unsigned char V_297 ;
F_78 ( & V_14 -> V_84 , V_43 ) ;
if ( V_2 -> V_14 . V_298 & V_299 )
F_149 ( V_14 -> V_160 ) ;
F_142 ( V_2 , V_188 ) ;
F_37 ( V_14 , V_75 , V_179 ) ;
F_91 ( 1 ) ;
V_297 = F_133 ( V_14 , V_125 ) ;
F_94 ( V_14 , V_75 , 0 ) ;
F_37 ( V_14 , V_75 , V_179 ) ;
F_91 ( 1 ) ;
V_237 = F_133 ( V_14 , V_125 ) ;
F_94 ( V_14 , V_75 , 0 ) ;
if ( V_14 -> V_298 & V_299 )
F_150 ( V_14 -> V_160 ) ;
F_80 ( & V_14 -> V_84 , V_43 ) ;
if ( ( ! ( V_297 & V_241 ) && ( V_237 & V_241 ) ) ||
V_2 -> V_14 . V_43 & V_300 ) {
V_2 -> V_108 |= V_301 ;
}
}
V_273 = V_2 -> V_302 -> V_303 ( V_2 ) ;
if ( V_273 )
goto V_69;
F_94 ( V_14 , V_29 , V_304 ) ;
F_78 ( & V_14 -> V_84 , V_43 ) ;
if ( V_2 -> V_14 . V_43 & V_161 ) {
if ( ! V_2 -> V_14 . V_160 )
V_2 -> V_14 . V_255 |= V_258 ;
} else
if ( V_14 -> V_160 )
V_2 -> V_14 . V_255 |= V_259 ;
F_140 ( V_14 , V_14 -> V_255 ) ;
if ( V_2 -> V_14 . V_305 & V_306 )
goto V_307;
F_94 ( V_14 , V_75 , V_179 ) ;
V_180 = F_133 ( V_14 , V_95 ) ;
V_237 = F_133 ( V_14 , V_125 ) ;
F_94 ( V_14 , V_75 , 0 ) ;
if ( V_180 & V_308 && V_237 & V_241 ) {
if ( ! ( V_2 -> V_108 & V_185 ) ) {
V_2 -> V_108 |= V_185 ;
F_117 ( L_20 ,
F_77 ( V_14 ) ) ;
}
} else {
V_2 -> V_108 &= ~ V_185 ;
}
V_307:
F_80 ( & V_14 -> V_84 , V_43 ) ;
F_133 ( V_14 , V_95 ) ;
F_133 ( V_14 , V_97 ) ;
F_133 ( V_14 , V_125 ) ;
F_133 ( V_14 , V_144 ) ;
if ( ( V_14 -> type == V_66 ) || ( V_14 -> type == V_67 ) )
F_133 ( V_14 , V_244 ) ;
V_2 -> V_186 = 0 ;
V_2 -> V_226 = 0 ;
if ( V_2 -> V_183 ) {
V_273 = F_151 ( V_2 ) ;
if ( V_273 ) {
F_152 ( L_21 ,
F_77 ( V_14 ) ) ;
V_2 -> V_183 = NULL ;
}
}
V_2 -> V_165 = V_166 | V_167 ;
if ( V_14 -> V_43 & V_161 ) {
unsigned int V_309 ;
V_309 = ( V_14 -> V_16 & 0xfe0 ) | 0x01f ;
F_86 ( 0x80 , V_309 ) ;
F_85 ( V_309 ) ;
}
V_273 = 0 ;
V_69:
F_47 ( V_2 ) ;
return V_273 ;
}
static int F_153 ( struct V_6 * V_14 )
{
if ( V_14 -> V_310 )
return V_14 -> V_310 ( V_14 ) ;
return F_146 ( V_14 ) ;
}
void F_154 ( struct V_6 * V_14 )
{
struct V_1 * V_2 = F_35 ( V_14 ) ;
unsigned long V_43 ;
F_45 ( V_2 ) ;
F_78 ( & V_14 -> V_84 , V_43 ) ;
V_2 -> V_165 = 0 ;
F_94 ( V_14 , V_75 , 0 ) ;
F_80 ( & V_14 -> V_84 , V_43 ) ;
F_155 ( V_14 -> V_160 ) ;
if ( V_2 -> V_183 )
F_156 ( V_2 ) ;
F_78 ( & V_14 -> V_84 , V_43 ) ;
if ( V_14 -> V_43 & V_161 ) {
F_14 ( ( V_14 -> V_16 & 0xfe0 ) | 0x1f ) ;
V_14 -> V_255 |= V_258 ;
} else
V_14 -> V_255 &= ~ V_259 ;
F_140 ( V_14 , V_14 -> V_255 ) ;
F_80 ( & V_14 -> V_84 , V_43 ) ;
F_94 ( V_14 , V_29 ,
F_133 ( V_14 , V_29 ) & ~ V_265 ) ;
F_40 ( V_2 ) ;
#ifdef F_81
F_64 ( V_2 ) ;
#endif
F_133 ( V_14 , V_97 ) ;
F_47 ( V_2 ) ;
V_2 -> V_302 -> V_311 ( V_2 ) ;
}
static void F_157 ( struct V_6 * V_14 )
{
if ( V_14 -> V_312 )
V_14 -> V_312 ( V_14 ) ;
else
F_154 ( V_14 ) ;
}
static unsigned int F_158 ( struct V_1 * V_2 ,
unsigned int V_313 ,
unsigned int * V_314 )
{
struct V_6 * V_14 = & V_2 -> V_14 ;
unsigned int V_315 ;
V_315 = F_159 ( V_14 -> V_81 , V_313 ) ;
* V_314 = V_315 & 0x0f ;
return V_315 >> 4 ;
}
static unsigned int F_160 ( struct V_1 * V_2 ,
unsigned int V_313 ,
unsigned int * V_314 )
{
struct V_6 * V_14 = & V_2 -> V_14 ;
unsigned int V_127 ;
if ( ( V_14 -> V_43 & V_316 ) &&
V_313 == ( V_14 -> V_81 / 4 ) )
V_127 = 0x8001 ;
else if ( ( V_14 -> V_43 & V_316 ) &&
V_313 == ( V_14 -> V_81 / 8 ) )
V_127 = 0x8002 ;
else if ( V_2 -> V_14 . type == V_66 )
V_127 = F_158 ( V_2 , V_313 , V_314 ) ;
else
V_127 = F_161 ( V_14 , V_313 ) ;
if ( V_2 -> V_108 & V_109 && ( V_127 & 0xff ) == 0 )
V_127 ++ ;
return V_127 ;
}
static unsigned char F_162 ( struct V_1 * V_2 ,
T_2 V_317 )
{
unsigned char V_318 ;
switch ( V_317 & V_319 ) {
case V_320 :
V_318 = V_321 ;
break;
case V_322 :
V_318 = V_323 ;
break;
case V_324 :
V_318 = V_325 ;
break;
default:
case V_326 :
V_318 = V_304 ;
break;
}
if ( V_317 & V_327 )
V_318 |= V_328 ;
if ( V_317 & V_329 ) {
V_318 |= V_330 ;
if ( V_2 -> V_108 & V_331 )
V_2 -> V_332 = true ;
}
if ( ! ( V_317 & V_333 ) )
V_318 |= V_334 ;
#ifdef F_163
if ( V_317 & F_163 )
V_318 |= V_335 ;
#endif
return V_318 ;
}
static void F_164 ( struct V_6 * V_14 , unsigned int V_313 ,
unsigned int V_127 , unsigned int V_336 )
{
struct V_1 * V_2 = F_35 ( V_14 ) ;
if ( F_165 ( V_2 ) ) {
if ( V_313 == 115200 ) {
V_127 = 1 ;
F_94 ( V_14 , V_337 , 1 ) ;
} else
F_94 ( V_14 , V_337 , 0 ) ;
}
if ( V_2 -> V_35 & V_129 )
F_94 ( V_14 , V_29 , 0xe0 ) ;
else
F_94 ( V_14 , V_29 , V_2 -> V_64 | V_338 ) ;
F_67 ( V_2 , V_127 ) ;
if ( V_2 -> V_14 . type == V_66 )
F_94 ( V_14 , 0x2 , V_336 ) ;
}
static unsigned int F_166 ( struct V_6 * V_14 ,
struct V_339 * V_340 ,
struct V_339 * V_341 )
{
return F_167 ( V_14 , V_340 , V_341 ,
V_14 -> V_81 / 16 / 0xffff ,
V_14 -> V_81 ) ;
}
void
F_168 ( struct V_6 * V_14 , struct V_339 * V_340 ,
struct V_339 * V_341 )
{
struct V_1 * V_2 = F_35 ( V_14 ) ;
unsigned char V_318 ;
unsigned long V_43 ;
unsigned int V_313 , V_127 , V_314 = 0 ;
if ( V_2 -> V_35 & V_223 ) {
V_340 -> V_317 &= ~ ( V_327 | V_329 | V_333 | F_163 ) ;
if ( ( V_340 -> V_317 & V_319 ) == V_320 ||
( V_340 -> V_317 & V_319 ) == V_322 )
V_340 -> V_317 = ( V_340 -> V_317 & ~ V_319 ) | V_324 ;
}
V_318 = F_162 ( V_2 , V_340 -> V_317 ) ;
V_313 = F_166 ( V_14 , V_340 , V_341 ) ;
V_127 = F_160 ( V_2 , V_313 , & V_314 ) ;
F_45 ( V_2 ) ;
F_78 ( & V_14 -> V_84 , V_43 ) ;
V_2 -> V_64 = V_318 ;
if ( V_2 -> V_35 & V_36 && V_14 -> V_149 > 1 ) {
if ( ( V_313 < 2400 && ! V_2 -> V_183 ) || V_2 -> V_332 ) {
V_2 -> V_46 &= ~ V_342 ;
V_2 -> V_46 |= V_343 ;
}
}
if ( V_2 -> V_35 & V_122 ) {
V_2 -> V_41 &= ~ V_344 ;
if ( V_340 -> V_317 & V_345 )
V_2 -> V_41 |= V_344 ;
}
F_169 ( V_14 , V_340 -> V_317 , V_313 ) ;
V_14 -> V_168 = V_207 | V_188 | V_96 ;
if ( V_340 -> V_346 & V_347 )
V_14 -> V_168 |= V_202 | V_203 ;
if ( V_340 -> V_346 & ( V_348 | V_349 | V_350 ) )
V_14 -> V_168 |= V_201 ;
V_14 -> V_351 = 0 ;
if ( V_340 -> V_346 & V_352 )
V_14 -> V_351 |= V_203 | V_202 ;
if ( V_340 -> V_346 & V_348 ) {
V_14 -> V_351 |= V_201 ;
if ( V_340 -> V_346 & V_352 )
V_14 -> V_351 |= V_207 ;
}
if ( ( V_340 -> V_317 & V_353 ) == 0 )
V_14 -> V_351 |= V_96 ;
V_2 -> V_165 &= ~ V_194 ;
if ( ! ( V_2 -> V_108 & V_193 ) &&
F_170 ( & V_2 -> V_14 , V_340 -> V_317 ) )
V_2 -> V_165 |= V_194 ;
if ( V_2 -> V_35 & V_133 )
V_2 -> V_165 |= V_131 ;
if ( V_2 -> V_35 & V_134 )
V_2 -> V_165 |= V_354 ;
F_94 ( V_14 , V_75 , V_2 -> V_165 ) ;
if ( V_2 -> V_35 & V_71 ) {
unsigned char V_65 = 0 ;
if ( V_340 -> V_317 & V_345 )
V_65 |= V_355 ;
F_94 ( V_14 , V_29 , V_73 ) ;
if ( V_14 -> V_43 & V_120 )
F_94 ( V_14 , V_280 , V_65 ) ;
else
F_94 ( V_14 , V_72 , V_65 ) ;
}
F_164 ( V_14 , V_313 , V_127 , V_314 ) ;
if ( V_14 -> type == V_130 )
F_94 ( V_14 , V_37 , V_2 -> V_46 ) ;
F_94 ( V_14 , V_29 , V_2 -> V_64 ) ;
if ( V_14 -> type != V_130 ) {
if ( V_2 -> V_46 & V_38 )
F_94 ( V_14 , V_37 , V_38 ) ;
F_94 ( V_14 , V_37 , V_2 -> V_46 ) ;
}
F_140 ( V_14 , V_14 -> V_255 ) ;
F_80 ( & V_14 -> V_84 , V_43 ) ;
F_47 ( V_2 ) ;
if ( F_171 ( V_340 ) )
F_172 ( V_340 , V_313 , V_313 ) ;
}
static void
F_173 ( struct V_6 * V_14 , struct V_339 * V_340 ,
struct V_339 * V_341 )
{
if ( V_14 -> V_356 )
V_14 -> V_356 ( V_14 , V_340 , V_341 ) ;
else
F_168 ( V_14 , V_340 , V_341 ) ;
}
void F_174 ( struct V_6 * V_14 , struct V_339 * V_340 )
{
if ( V_340 -> V_357 == V_358 ) {
V_14 -> V_43 |= V_359 ;
F_62 ( & V_14 -> V_84 ) ;
F_112 ( V_14 ) ;
F_63 ( & V_14 -> V_84 ) ;
} else {
V_14 -> V_43 &= ~ V_359 ;
if ( ! F_170 ( V_14 , V_340 -> V_317 ) ) {
F_62 ( & V_14 -> V_84 ) ;
F_111 ( V_14 ) ;
F_63 ( & V_14 -> V_84 ) ;
}
}
}
static void
F_175 ( struct V_6 * V_14 , struct V_339 * V_340 )
{
if ( V_14 -> V_360 )
V_14 -> V_360 ( V_14 , V_340 ) ;
else
F_174 ( V_14 , V_340 ) ;
}
void F_176 ( struct V_6 * V_14 , unsigned int V_214 ,
unsigned int V_361 )
{
struct V_1 * V_7 = F_35 ( V_14 ) ;
F_59 ( V_7 , V_214 != 0 ) ;
}
static void
F_177 ( struct V_6 * V_14 , unsigned int V_214 ,
unsigned int V_361 )
{
if ( V_14 -> V_362 )
V_14 -> V_362 ( V_14 , V_214 , V_361 ) ;
else
F_176 ( V_14 , V_214 , V_361 ) ;
}
static unsigned int F_178 ( struct V_1 * V_363 )
{
if ( V_363 -> V_14 . V_364 )
return V_363 -> V_14 . V_364 ;
if ( V_363 -> V_14 . V_19 == V_25 ) {
if ( V_363 -> V_14 . type == V_365 )
return 0x100 ;
return 0x1000 ;
}
if ( F_179 ( V_363 ) )
return 0x16 << V_363 -> V_14 . V_12 ;
return 8 << V_363 -> V_14 . V_12 ;
}
static int F_180 ( struct V_1 * V_2 )
{
unsigned int V_366 = F_178 ( V_2 ) ;
struct V_6 * V_14 = & V_2 -> V_14 ;
int V_243 = 0 ;
switch ( V_14 -> V_19 ) {
case V_25 :
case V_367 :
case V_23 :
case V_24 :
case V_22 :
case V_21 :
if ( ! V_14 -> V_141 )
break;
if ( ! F_181 ( V_14 -> V_141 , V_366 , L_22 ) ) {
V_243 = - V_368 ;
break;
}
if ( V_14 -> V_43 & V_369 ) {
V_14 -> V_11 = F_182 ( V_14 -> V_141 , V_366 ) ;
if ( ! V_14 -> V_11 ) {
F_183 ( V_14 -> V_141 , V_366 ) ;
V_243 = - V_52 ;
}
}
break;
case V_20 :
case V_154 :
if ( ! F_184 ( V_14 -> V_16 , V_366 , L_22 ) )
V_243 = - V_368 ;
break;
}
return V_243 ;
}
static void F_185 ( struct V_1 * V_2 )
{
unsigned int V_366 = F_178 ( V_2 ) ;
struct V_6 * V_14 = & V_2 -> V_14 ;
switch ( V_14 -> V_19 ) {
case V_25 :
case V_367 :
case V_23 :
case V_24 :
case V_22 :
case V_21 :
if ( ! V_14 -> V_141 )
break;
if ( V_14 -> V_43 & V_369 ) {
F_186 ( V_14 -> V_11 ) ;
V_14 -> V_11 = NULL ;
}
F_183 ( V_14 -> V_141 , V_366 ) ;
break;
case V_20 :
case V_154 :
F_187 ( V_14 -> V_16 , V_366 ) ;
break;
}
}
static void F_188 ( struct V_6 * V_14 )
{
struct V_1 * V_2 = F_35 ( V_14 ) ;
F_185 ( V_2 ) ;
}
static int F_189 ( struct V_6 * V_14 )
{
struct V_1 * V_2 = F_35 ( V_14 ) ;
return F_180 ( V_2 ) ;
}
static int F_190 ( struct V_1 * V_2 )
{
const struct V_370 * V_371 = & V_150 [ V_2 -> V_14 . type ] ;
unsigned char V_372 ;
V_372 = V_371 -> V_373 [ F_191 ( V_2 -> V_46 ) ] ;
return V_372 ? V_372 : - V_374 ;
}
static int F_192 ( struct V_1 * V_2 , unsigned char V_372 )
{
const struct V_370 * V_371 = & V_150 [ V_2 -> V_14 . type ] ;
int V_375 ;
if ( ! V_371 -> V_373 [ F_191 ( V_376 ) ] )
return - V_374 ;
for ( V_375 = 1 ; V_375 < V_377 ; V_375 ++ ) {
if ( V_372 < V_371 -> V_373 [ V_375 ] )
return ( -- V_375 ) << V_378 ;
}
return V_379 ;
}
static int F_193 ( struct V_380 * V_14 )
{
struct V_381 * V_214 = F_96 ( V_14 , struct V_381 , V_14 ) ;
struct V_6 * V_382 = V_214 -> V_6 ;
struct V_1 * V_2 = F_35 ( V_382 ) ;
if ( ! ( V_2 -> V_35 & V_36 ) || V_382 -> V_149 <= 1 )
return - V_383 ;
return F_190 ( V_2 ) ;
}
static int F_194 ( struct V_380 * V_14 )
{
int V_373 ;
F_195 ( & V_14 -> V_384 ) ;
V_373 = F_193 ( V_14 ) ;
F_196 ( & V_14 -> V_384 ) ;
return V_373 ;
}
static T_3 F_197 ( struct V_385 * V_48 ,
struct V_386 * V_387 , char * V_219 )
{
struct V_380 * V_14 = F_198 ( V_48 ) ;
int V_373 ;
V_373 = F_194 ( V_14 ) ;
if ( V_373 < 0 )
return V_373 ;
return snprintf ( V_219 , V_388 , L_23 , V_373 ) ;
}
static int F_199 ( struct V_380 * V_14 , unsigned char V_372 )
{
struct V_381 * V_214 = F_96 ( V_14 , struct V_381 , V_14 ) ;
struct V_6 * V_382 = V_214 -> V_6 ;
struct V_1 * V_2 = F_35 ( V_382 ) ;
int V_389 ;
if ( ! ( V_2 -> V_35 & V_36 ) || V_382 -> V_149 <= 1 ||
V_2 -> V_332 )
return - V_383 ;
V_389 = F_192 ( V_2 , V_372 ) ;
if ( V_389 < 0 )
return V_389 ;
F_40 ( V_2 ) ;
V_2 -> V_46 &= ~ V_342 ;
V_2 -> V_46 |= ( unsigned char ) V_389 ;
F_4 ( V_2 , V_37 , V_2 -> V_46 ) ;
return 0 ;
}
static int F_200 ( struct V_380 * V_14 , unsigned char V_372 )
{
int V_243 ;
F_195 ( & V_14 -> V_384 ) ;
V_243 = F_199 ( V_14 , V_372 ) ;
F_196 ( & V_14 -> V_384 ) ;
return V_243 ;
}
static T_3 F_201 ( struct V_385 * V_48 ,
struct V_386 * V_387 , const char * V_219 , T_4 V_91 )
{
struct V_380 * V_14 = F_198 ( V_48 ) ;
unsigned char V_372 ;
int V_243 ;
if ( ! V_91 )
return - V_383 ;
V_243 = F_202 ( V_219 , 10 , & V_372 ) ;
if ( V_243 < 0 )
return V_243 ;
V_243 = F_200 ( V_14 , V_372 ) ;
if ( V_243 < 0 )
return V_243 ;
return V_91 ;
}
static void F_203 ( struct V_1 * V_2 )
{
const struct V_370 * V_371 = & V_150 [ V_2 -> V_14 . type ] ;
if ( V_371 -> V_373 [ 0 ] )
V_2 -> V_14 . V_390 = & V_391 ;
}
static void F_204 ( struct V_6 * V_14 , int V_43 )
{
struct V_1 * V_2 = F_35 ( V_14 ) ;
int V_243 ;
V_243 = F_180 ( V_2 ) ;
if ( V_243 < 0 )
return;
if ( V_14 -> V_19 != V_2 -> V_26 )
F_34 ( V_14 ) ;
if ( V_43 & V_392 )
F_76 ( V_2 ) ;
if ( V_14 -> type == V_119 && V_14 -> V_19 == V_25 )
V_2 -> V_108 |= V_193 ;
if ( V_14 -> type == V_393 )
V_2 -> V_108 |= V_193 ;
if ( V_14 -> type != V_145 && V_43 & V_394 )
F_84 ( V_2 ) ;
if ( V_14 -> type == V_145 )
F_185 ( V_2 ) ;
if ( ( V_14 -> type == V_66 ) ||
( V_14 -> type == V_67 ) )
V_14 -> V_27 = F_134 ;
F_203 ( V_2 ) ;
V_2 -> V_46 = V_150 [ V_2 -> V_14 . type ] . V_46 ;
}
static int
F_205 ( struct V_6 * V_14 , struct V_395 * V_396 )
{
if ( V_396 -> V_160 >= V_397 || V_396 -> V_160 < 0 ||
V_396 -> V_398 < 9600 || V_396 -> type < V_145 ||
V_396 -> type >= F_6 ( V_150 ) || V_396 -> type == V_399 ||
V_396 -> type == V_400 )
return - V_383 ;
return 0 ;
}
static const char * F_206 ( struct V_6 * V_14 )
{
int type = V_14 -> type ;
if ( type >= F_6 ( V_150 ) )
type = 0 ;
return V_150 [ type ] . V_155 ;
}
void F_207 ( struct V_1 * V_2 )
{
struct V_6 * V_14 = & V_2 -> V_14 ;
F_208 ( & V_14 -> V_84 ) ;
V_14 -> V_302 = & V_401 ;
V_2 -> V_26 = 0xFF ;
}
void F_209 ( struct V_1 * V_2 )
{
struct V_6 * V_14 = & V_2 -> V_14 ;
if ( V_2 -> V_14 . V_43 & V_402 ) {
unsigned int type = V_2 -> V_14 . type ;
if ( ! V_2 -> V_14 . V_149 )
V_2 -> V_14 . V_149 = V_150 [ type ] . V_151 ;
if ( ! V_2 -> V_152 )
V_2 -> V_152 = V_150 [ type ] . V_152 ;
if ( ! V_2 -> V_35 )
V_2 -> V_35 = V_150 [ type ] . V_43 ;
}
F_34 ( V_14 ) ;
if ( V_2 -> V_183 ) {
if ( ! V_2 -> V_183 -> V_184 )
V_2 -> V_183 -> V_184 = V_403 ;
if ( ! V_2 -> V_183 -> V_240 )
V_2 -> V_183 -> V_240 = V_404 ;
}
}
static void F_210 ( struct V_6 * V_14 , int V_195 )
{
struct V_1 * V_2 = F_35 ( V_14 ) ;
F_142 ( V_2 , V_188 ) ;
F_94 ( V_14 , V_94 , V_195 ) ;
}
static void F_211 ( struct V_1 * V_2 )
{
struct V_6 * V_14 = & V_2 -> V_14 ;
struct V_339 V_340 ;
unsigned int V_313 , V_127 , V_314 = 0 ;
V_340 . V_317 = V_14 -> V_405 -> V_406 ;
if ( V_14 -> V_214 -> V_14 . V_407 && V_340 . V_317 == 0 )
V_340 . V_317 = V_14 -> V_214 -> V_14 . V_407 -> V_340 . V_317 ;
V_313 = F_166 ( V_14 , & V_340 , NULL ) ;
V_127 = F_160 ( V_2 , V_313 , & V_314 ) ;
F_164 ( V_14 , V_313 , V_127 , V_314 ) ;
F_94 ( V_14 , V_29 , V_2 -> V_64 ) ;
F_43 ( V_2 , V_164 | V_45 ) ;
}
void F_212 ( struct V_1 * V_2 , const char * V_408 ,
unsigned int V_91 )
{
struct V_6 * V_14 = & V_2 -> V_14 ;
unsigned long V_43 ;
unsigned int V_165 ;
int V_409 = 1 ;
F_143 () ;
F_45 ( V_2 ) ;
if ( V_14 -> V_410 )
V_409 = 0 ;
else if ( V_411 )
V_409 = F_213 ( & V_14 -> V_84 , V_43 ) ;
else
F_78 ( & V_14 -> V_84 , V_43 ) ;
V_165 = F_133 ( V_14 , V_75 ) ;
if ( V_2 -> V_35 & V_133 )
F_94 ( V_14 , V_75 , V_131 ) ;
else
F_94 ( V_14 , V_75 , 0 ) ;
if ( V_2 -> V_412 && ( V_2 -> V_412 != F_133 ( V_14 , V_30 ) ) ) {
F_211 ( V_2 ) ;
V_2 -> V_412 = 0 ;
}
F_214 ( V_14 , V_408 , V_91 , F_210 ) ;
F_142 ( V_2 , V_181 ) ;
F_94 ( V_14 , V_75 , V_165 ) ;
if ( V_2 -> V_226 )
F_126 ( V_2 ) ;
if ( V_409 )
F_80 ( & V_14 -> V_84 , V_43 ) ;
F_47 ( V_2 ) ;
}
static unsigned int F_215 ( struct V_6 * V_14 )
{
unsigned char V_64 , V_413 , V_414 ;
unsigned int V_127 ;
V_64 = F_133 ( V_14 , V_29 ) ;
F_94 ( V_14 , V_29 , V_64 | V_338 ) ;
V_413 = F_133 ( V_14 , V_3 ) ;
V_414 = F_133 ( V_14 , V_4 ) ;
F_94 ( V_14 , V_29 , V_64 ) ;
V_127 = ( V_414 << 8 ) | V_413 ;
return ( V_14 -> V_81 / 16 ) / V_127 ;
}
int F_216 ( struct V_6 * V_14 , char * V_415 , bool V_147 )
{
int V_313 = 9600 ;
int V_266 = 8 ;
int V_205 = 'n' ;
int V_416 = 'n' ;
if ( ! V_14 -> V_16 && ! V_14 -> V_11 )
return - V_282 ;
if ( V_415 )
F_217 ( V_415 , & V_313 , & V_205 , & V_266 , & V_416 ) ;
else if ( V_147 )
V_313 = F_215 ( V_14 ) ;
return F_218 ( V_14 , V_14 -> V_405 , V_313 , V_205 , V_266 , V_416 ) ;
}
