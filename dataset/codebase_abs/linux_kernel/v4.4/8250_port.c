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
#ifdef F_32
case V_24 :
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
V_2 -> V_25 = V_7 -> V_19 ;
V_7 -> V_26 = V_27 ;
}
static void
F_33 ( struct V_6 * V_7 , int V_8 , int V_5 )
{
switch ( V_7 -> V_19 ) {
case V_21 :
case V_22 :
case V_23 :
case V_24 :
V_7 -> F_4 ( V_7 , V_8 , V_5 ) ;
V_7 -> F_2 ( V_7 , V_28 ) ;
break;
default:
V_7 -> F_4 ( V_7 , V_8 , V_5 ) ;
}
}
static void F_34 ( struct V_1 * V_2 , int V_8 , int V_5 )
{
F_4 ( V_2 , V_29 , V_8 ) ;
F_4 ( V_2 , V_30 , V_5 ) ;
}
static unsigned int F_35 ( struct V_1 * V_2 , int V_8 )
{
unsigned int V_5 ;
F_34 ( V_2 , V_31 , V_2 -> V_32 | V_33 ) ;
F_4 ( V_2 , V_29 , V_8 ) ;
V_5 = F_2 ( V_2 , V_30 ) ;
F_34 ( V_2 , V_31 , V_2 -> V_32 ) ;
return V_5 ;
}
static void F_36 ( struct V_1 * V_7 )
{
if ( V_7 -> V_34 & V_35 ) {
F_4 ( V_7 , V_36 , V_37 ) ;
F_4 ( V_7 , V_36 , V_37 |
V_38 | V_39 ) ;
F_4 ( V_7 , V_36 , 0 ) ;
}
}
void F_37 ( struct V_1 * V_7 )
{
F_36 ( V_7 ) ;
F_4 ( V_7 , V_36 , V_7 -> V_40 ) ;
}
void F_38 ( struct V_1 * V_7 )
{
if ( ! ( V_7 -> V_34 & V_41 ) )
return;
F_39 ( V_7 -> V_14 . V_42 ) ;
}
void F_40 ( struct V_1 * V_7 )
{
if ( ! ( V_7 -> V_34 & V_41 ) )
return;
F_41 ( V_7 -> V_14 . V_42 ) ;
F_42 ( V_7 -> V_14 . V_42 ) ;
}
static void F_43 ( struct V_1 * V_7 )
{
unsigned char V_43 ;
if ( ! ( V_7 -> V_34 & V_41 ) )
return;
V_43 = F_44 ( & V_7 -> V_44 , 1 ) ;
if ( V_43 )
return;
F_39 ( V_7 -> V_14 . V_42 ) ;
}
static void F_45 ( struct V_1 * V_7 )
{
unsigned char V_43 ;
if ( ! ( V_7 -> V_34 & V_41 ) )
return;
V_43 = F_44 ( & V_7 -> V_44 , 0 ) ;
if ( ! V_43 )
return;
F_41 ( V_7 -> V_14 . V_42 ) ;
F_42 ( V_7 -> V_14 . V_42 ) ;
}
static void F_46 ( struct V_1 * V_7 , int V_45 )
{
unsigned char V_46 = 0 , V_47 = 0 ;
F_38 ( V_7 ) ;
if ( ( V_7 -> V_14 . type == V_48 ) ||
( V_7 -> V_14 . type == V_49 ) ) {
F_4 ( V_7 , V_50 , V_45 ? 0xff : 0 ) ;
goto V_51;
}
if ( V_7 -> V_34 & V_52 ) {
if ( V_7 -> V_34 & V_53 ) {
V_46 = F_2 ( V_7 , V_28 ) ;
V_47 = F_2 ( V_7 , V_54 ) ;
F_4 ( V_7 , V_28 , V_55 ) ;
F_4 ( V_7 , V_54 , V_56 ) ;
F_4 ( V_7 , V_28 , 0 ) ;
}
F_4 ( V_7 , V_57 , V_45 ? V_58 : 0 ) ;
if ( V_7 -> V_34 & V_53 ) {
F_4 ( V_7 , V_28 , V_55 ) ;
F_4 ( V_7 , V_54 , V_47 ) ;
F_4 ( V_7 , V_28 , V_46 ) ;
}
}
V_51:
F_40 ( V_7 ) ;
}
static int F_47 ( struct V_1 * V_2 )
{
unsigned char V_59 ;
int V_60 ;
V_59 = F_2 ( V_2 , V_61 ) ;
V_60 = V_59 & V_62 ;
if ( ! V_60 ) {
F_4 ( V_2 , V_61 , V_59 | V_62 ) ;
V_59 = F_2 ( V_2 , V_61 ) ;
V_60 = V_59 & V_62 ;
}
if ( V_60 )
V_2 -> V_14 . V_63 = V_64 * 16 ;
return V_60 ;
}
static void F_48 ( struct V_1 * V_2 )
{
if ( V_2 -> V_14 . type == V_65 ) {
if ( V_2 -> V_14 . V_63 != V_64 * 16 ) {
F_49 ( & V_2 -> V_14 . V_66 ) ;
F_47 ( V_2 ) ;
F_50 ( & V_2 -> V_14 . V_66 ) ;
}
if ( V_2 -> V_14 . V_63 == V_64 * 16 )
F_4 ( V_2 , V_67 , 0 ) ;
}
}
static void F_51 ( struct V_1 * V_2 )
{
unsigned char V_59 ;
int V_60 ;
if ( V_2 -> V_14 . type == V_65 &&
V_2 -> V_14 . V_63 == V_64 * 16 ) {
F_49 ( & V_2 -> V_14 . V_66 ) ;
V_59 = F_2 ( V_2 , V_61 ) ;
V_60 = ! ( V_59 & V_62 ) ;
if ( ! V_60 ) {
F_4 ( V_2 , V_61 , V_59 & ~ V_62 ) ;
V_59 = F_2 ( V_2 , V_61 ) ;
V_60 = ! ( V_59 & V_62 ) ;
}
if ( V_60 )
V_2 -> V_14 . V_63 = V_68 * 16 ;
F_50 ( & V_2 -> V_14 . V_66 ) ;
}
}
static int F_52 ( struct V_1 * V_2 )
{
unsigned char V_69 , V_70 , V_71 ;
unsigned short V_72 ;
int V_73 ;
V_71 = F_2 ( V_2 , V_28 ) ;
F_4 ( V_2 , V_28 , 0 ) ;
V_69 = F_2 ( V_2 , V_36 ) ;
V_70 = F_2 ( V_2 , V_74 ) ;
F_4 ( V_2 , V_36 , V_37 |
V_38 | V_39 ) ;
F_4 ( V_2 , V_74 , V_75 ) ;
F_4 ( V_2 , V_28 , V_76 ) ;
V_72 = F_53 ( V_2 ) ;
F_54 ( V_2 , 0x0001 ) ;
F_4 ( V_2 , V_28 , 0x03 ) ;
for ( V_73 = 0 ; V_73 < 256 ; V_73 ++ )
F_4 ( V_2 , V_77 , V_73 ) ;
F_55 ( 20 ) ;
for ( V_73 = 0 ; ( F_2 ( V_2 , V_78 ) & V_79 ) &&
( V_73 < 256 ) ; V_73 ++ )
F_2 ( V_2 , V_80 ) ;
F_4 ( V_2 , V_36 , V_69 ) ;
F_4 ( V_2 , V_74 , V_70 ) ;
F_4 ( V_2 , V_28 , V_76 ) ;
F_54 ( V_2 , V_72 ) ;
F_4 ( V_2 , V_28 , V_71 ) ;
return V_73 ;
}
static unsigned int F_56 ( struct V_1 * V_7 )
{
unsigned char V_81 , V_82 , V_71 ;
unsigned int V_83 ;
V_71 = F_2 ( V_7 , V_28 ) ;
F_4 ( V_7 , V_28 , V_76 ) ;
V_81 = F_2 ( V_7 , V_3 ) ;
V_82 = F_2 ( V_7 , V_4 ) ;
F_4 ( V_7 , V_3 , 0 ) ;
F_4 ( V_7 , V_4 , 0 ) ;
V_83 = F_2 ( V_7 , V_3 ) | F_2 ( V_7 , V_4 ) << 8 ;
F_4 ( V_7 , V_3 , V_81 ) ;
F_4 ( V_7 , V_4 , V_82 ) ;
F_4 ( V_7 , V_28 , V_71 ) ;
return V_83 ;
}
static void F_57 ( struct V_1 * V_2 )
{
unsigned int V_84 , V_85 , V_86 , V_87 ;
V_2 -> V_34 |= V_53 | V_52 ;
V_2 -> V_32 = 0 ;
F_4 ( V_2 , V_28 , V_55 ) ;
F_4 ( V_2 , V_54 , V_56 ) ;
F_4 ( V_2 , V_28 , 0x00 ) ;
V_84 = F_35 ( V_2 , V_88 ) ;
V_85 = F_35 ( V_2 , V_89 ) ;
V_86 = F_35 ( V_2 , V_90 ) ;
V_87 = F_35 ( V_2 , V_91 ) ;
F_58 ( L_1 , V_84 , V_85 , V_86 , V_87 ) ;
if ( V_84 == 0x16 && V_85 == 0xC9 &&
( V_86 == 0x50 || V_86 == 0x52 || V_86 == 0x54 ) ) {
V_2 -> V_14 . type = V_92 ;
if ( V_86 == 0x52 && V_87 == 0x01 )
V_2 -> V_93 |= V_94 ;
return;
}
V_84 = F_56 ( V_2 ) ;
F_58 ( L_2 , V_84 ) ;
V_85 = V_84 >> 8 ;
if ( V_85 == 0x10 || V_85 == 0x12 || V_85 == 0x14 ) {
V_2 -> V_14 . type = V_95 ;
return;
}
if ( F_52 ( V_2 ) == 64 )
V_2 -> V_14 . type = V_96 ;
else
V_2 -> V_14 . type = V_97 ;
}
static void F_59 ( struct V_1 * V_2 )
{
unsigned char V_98 , V_99 , V_100 ;
V_2 -> V_14 . type = V_101 ;
V_98 = F_2 ( V_2 , V_29 ) ;
F_4 ( V_2 , V_29 , 0xa5 ) ;
V_99 = F_2 ( V_2 , V_29 ) ;
F_4 ( V_2 , V_29 , 0x5a ) ;
V_100 = F_2 ( V_2 , V_29 ) ;
F_4 ( V_2 , V_29 , V_98 ) ;
if ( V_99 == 0xa5 && V_100 == 0x5a )
V_2 -> V_14 . type = V_102 ;
}
static int F_60 ( struct V_1 * V_2 )
{
if ( F_56 ( V_2 ) == 0x0201 && F_52 ( V_2 ) == 16 )
return 1 ;
return 0 ;
}
static void F_61 ( struct V_1 * V_2 )
{
unsigned char V_99 , V_100 ;
unsigned int V_103 ;
V_2 -> V_14 . type = V_104 ;
V_2 -> V_34 |= V_35 ;
if ( V_2 -> V_14 . V_105 & V_106 ) {
V_99 = F_2 ( V_2 , V_107 ) ;
if ( V_99 == 0x82 || V_99 == 0x84 || V_99 == 0x88 ) {
F_58 ( L_3 ) ;
V_2 -> V_14 . type = V_48 ;
V_2 -> V_34 |= V_108 | V_53 |
V_52 ;
return;
}
}
F_4 ( V_2 , V_28 , V_76 ) ;
if ( F_2 ( V_2 , V_54 ) == 0 ) {
F_4 ( V_2 , V_54 , 0xA8 ) ;
if ( F_2 ( V_2 , V_54 ) != 0 ) {
F_58 ( L_4 ) ;
V_2 -> V_14 . type = V_109 ;
V_2 -> V_34 |= V_53 | V_52 ;
} else {
F_4 ( V_2 , V_28 , 0 ) ;
F_4 ( V_2 , V_36 , V_37 |
V_110 ) ;
V_99 = F_2 ( V_2 , V_111 ) >> 5 ;
F_4 ( V_2 , V_36 , 0 ) ;
F_4 ( V_2 , V_28 , 0 ) ;
if ( V_99 == 7 )
V_2 -> V_14 . type = V_112 ;
else
F_58 ( L_5 ) ;
}
F_4 ( V_2 , V_54 , 0 ) ;
return;
}
F_4 ( V_2 , V_28 , V_55 ) ;
if ( F_2 ( V_2 , V_54 ) == 0 && ! F_60 ( V_2 ) ) {
F_58 ( L_6 ) ;
F_57 ( V_2 ) ;
return;
}
F_4 ( V_2 , V_28 , 0 ) ;
V_99 = F_2 ( V_2 , V_74 ) ;
F_4 ( V_2 , V_28 , 0xE0 ) ;
V_100 = F_2 ( V_2 , 0x02 ) ;
if ( ! ( ( V_100 ^ V_99 ) & V_75 ) ) {
F_4 ( V_2 , V_28 , 0 ) ;
F_4 ( V_2 , V_74 , V_99 ^ V_75 ) ;
F_4 ( V_2 , V_28 , 0xE0 ) ;
V_100 = F_2 ( V_2 , 0x02 ) ;
F_4 ( V_2 , V_28 , 0 ) ;
F_4 ( V_2 , V_74 , V_99 ) ;
if ( ( V_100 ^ V_99 ) & V_75 ) {
unsigned short V_113 ;
F_4 ( V_2 , V_28 , 0xE0 ) ;
V_113 = F_53 ( V_2 ) ;
V_113 <<= 3 ;
if ( F_62 ( V_2 ) )
F_54 ( V_2 , V_113 ) ;
F_4 ( V_2 , V_28 , 0 ) ;
V_2 -> V_14 . V_63 = 921600 * 16 ;
V_2 -> V_14 . type = V_114 ;
V_2 -> V_34 |= V_115 ;
return;
}
}
F_4 ( V_2 , V_28 , 0 ) ;
F_4 ( V_2 , V_36 , V_37 | V_110 ) ;
V_99 = F_2 ( V_2 , V_111 ) >> 5 ;
F_4 ( V_2 , V_36 , V_37 ) ;
F_4 ( V_2 , V_28 , V_76 ) ;
F_4 ( V_2 , V_36 , V_37 | V_110 ) ;
V_100 = F_2 ( V_2 , V_111 ) >> 5 ;
F_4 ( V_2 , V_36 , V_37 ) ;
F_4 ( V_2 , V_28 , 0 ) ;
F_58 ( L_7 , V_99 , V_100 ) ;
if ( V_99 == 6 && V_100 == 7 ) {
V_2 -> V_14 . type = V_116 ;
V_2 -> V_34 |= V_108 | V_52 ;
return;
}
V_103 = F_2 ( V_2 , V_57 ) ;
F_4 ( V_2 , V_57 , V_103 & ~ V_117 ) ;
if ( ! ( F_2 ( V_2 , V_57 ) & V_117 ) ) {
F_4 ( V_2 , V_57 , V_103 | V_117 ) ;
if ( F_2 ( V_2 , V_57 ) & V_117 ) {
F_58 ( L_8 ) ;
V_2 -> V_14 . type = V_118 ;
V_2 -> V_34 |= V_119 | V_120 ;
return;
}
} else {
F_58 ( L_9 ) ;
}
F_4 ( V_2 , V_57 , V_103 ) ;
if ( V_2 -> V_14 . V_105 & V_106 ) {
F_58 ( L_10 ) ;
V_2 -> V_14 . type = V_49 ;
V_2 -> V_34 |= V_108 | V_53 |
V_52 ;
return;
}
if ( V_2 -> V_14 . type == V_104 && F_52 ( V_2 ) == 64 ) {
V_2 -> V_14 . type = V_121 ;
V_2 -> V_34 |= V_108 ;
}
}
static void F_63 ( struct V_1 * V_2 )
{
unsigned char V_99 , V_98 , V_122 , V_123 ;
unsigned char V_124 , V_125 ;
struct V_6 * V_14 = & V_2 -> V_14 ;
unsigned long V_105 ;
unsigned int V_126 ;
if ( ! V_14 -> V_16 && ! V_14 -> V_127 && ! V_14 -> V_11 )
return;
F_58 ( L_11 ,
F_64 ( V_14 ) , V_14 -> V_16 , V_14 -> V_11 ) ;
F_65 ( & V_14 -> V_66 , V_105 ) ;
V_2 -> V_34 = 0 ;
V_2 -> V_93 = 0 ;
if ( ! ( V_14 -> V_105 & V_128 ) ) {
V_98 = F_2 ( V_2 , V_57 ) ;
F_4 ( V_2 , V_57 , 0 ) ;
#ifdef F_66
F_13 ( 0xff , 0x080 ) ;
#endif
V_122 = F_2 ( V_2 , V_57 ) & 0x0f ;
F_4 ( V_2 , V_57 , 0x0F ) ;
#ifdef F_66
F_13 ( 0 , 0x080 ) ;
#endif
V_123 = F_2 ( V_2 , V_57 ) & 0x0f ;
F_4 ( V_2 , V_57 , V_98 ) ;
if ( V_122 != 0 || V_123 != 0x0F ) {
F_67 ( & V_14 -> V_66 , V_105 ) ;
F_58 ( L_12 ,
V_122 , V_123 ) ;
goto V_51;
}
}
V_125 = F_2 ( V_2 , V_74 ) ;
V_124 = F_2 ( V_2 , V_28 ) ;
if ( ! ( V_14 -> V_105 & V_129 ) ) {
F_4 ( V_2 , V_74 , V_75 | 0x0A ) ;
V_99 = F_2 ( V_2 , V_130 ) & 0xF0 ;
F_4 ( V_2 , V_74 , V_125 ) ;
if ( V_99 != 0x90 ) {
F_67 ( & V_14 -> V_66 , V_105 ) ;
F_58 ( L_13 ,
V_99 ) ;
goto V_51;
}
}
F_4 ( V_2 , V_28 , V_55 ) ;
F_4 ( V_2 , V_54 , 0 ) ;
F_4 ( V_2 , V_28 , 0 ) ;
F_4 ( V_2 , V_36 , V_37 ) ;
V_98 = F_2 ( V_2 , V_111 ) >> 6 ;
switch ( V_98 ) {
case 0 :
F_59 ( V_2 ) ;
break;
case 1 :
V_14 -> type = V_131 ;
break;
case 2 :
V_14 -> type = V_132 ;
break;
case 3 :
F_61 ( V_2 ) ;
break;
}
#ifdef F_68
if ( V_14 -> type == V_104 && V_2 -> V_133 & V_134 &&
F_47 ( V_2 ) )
V_14 -> type = V_65 ;
#endif
F_4 ( V_2 , V_28 , V_124 ) ;
V_14 -> V_135 = V_136 [ V_2 -> V_14 . type ] . V_137 ;
V_126 = V_2 -> V_34 ;
V_2 -> V_34 = V_136 [ V_14 -> type ] . V_105 ;
V_2 -> V_138 = V_136 [ V_14 -> type ] . V_138 ;
if ( V_14 -> type == V_131 )
goto V_139;
#ifdef F_68
if ( V_14 -> type == V_65 )
F_4 ( V_2 , V_67 , 0 ) ;
#endif
F_4 ( V_2 , V_74 , V_125 ) ;
F_36 ( V_2 ) ;
F_2 ( V_2 , V_80 ) ;
if ( V_2 -> V_34 & V_119 )
F_4 ( V_2 , V_57 , V_117 ) ;
else
F_4 ( V_2 , V_57 , 0 ) ;
V_139:
F_67 ( & V_14 -> V_66 , V_105 ) ;
if ( V_2 -> V_34 != V_126 ) {
F_69 ( V_140
L_14 ,
F_64 ( V_14 ) , V_126 ,
V_2 -> V_34 ) ;
}
V_51:
F_58 ( L_15 , V_98 ) ;
F_58 ( L_16 , V_136 [ V_14 -> type ] . V_141 ) ;
}
static void F_70 ( struct V_1 * V_2 )
{
struct V_6 * V_14 = & V_2 -> V_14 ;
unsigned char V_125 , V_142 ;
unsigned char V_143 = 0 ;
unsigned int V_144 = 0 ;
unsigned long V_145 ;
int V_146 ;
if ( V_14 -> V_105 & V_147 ) {
V_144 = ( V_14 -> V_16 & 0xfe0 ) | 0x1f ;
V_143 = F_71 ( V_144 ) ;
F_72 ( 0x80 , V_144 ) ;
F_71 ( V_144 ) ;
}
if ( F_73 ( V_14 ) )
F_74 () ;
F_75 ( F_76 () ) ;
V_125 = F_2 ( V_2 , V_74 ) ;
V_142 = F_2 ( V_2 , V_57 ) ;
F_4 ( V_2 , V_74 , V_148 | V_149 ) ;
V_145 = F_76 () ;
F_4 ( V_2 , V_74 , 0 ) ;
F_77 ( 10 ) ;
if ( V_14 -> V_105 & V_147 ) {
F_4 ( V_2 , V_74 ,
V_150 | V_151 ) ;
} else {
F_4 ( V_2 , V_74 ,
V_150 | V_151 | V_149 ) ;
}
F_4 ( V_2 , V_57 , 0x0f ) ;
F_2 ( V_2 , V_78 ) ;
F_2 ( V_2 , V_80 ) ;
F_2 ( V_2 , V_111 ) ;
F_2 ( V_2 , V_130 ) ;
F_4 ( V_2 , V_77 , 0xFF ) ;
F_77 ( 20 ) ;
V_146 = F_75 ( V_145 ) ;
F_4 ( V_2 , V_74 , V_125 ) ;
F_4 ( V_2 , V_57 , V_142 ) ;
if ( V_14 -> V_105 & V_147 )
F_72 ( V_143 , V_144 ) ;
if ( F_73 ( V_14 ) )
F_78 () ;
V_14 -> V_146 = ( V_146 > 0 ) ? V_146 : 0 ;
}
static inline void F_79 ( struct V_1 * V_7 )
{
if ( V_7 -> V_152 & V_153 ) {
V_7 -> V_152 &= ~ V_153 ;
F_4 ( V_7 , V_57 , V_7 -> V_152 ) ;
F_45 ( V_7 ) ;
}
}
static void F_80 ( struct V_6 * V_14 )
{
struct V_1 * V_2 = F_31 ( V_14 ) ;
F_38 ( V_2 ) ;
F_79 ( V_2 ) ;
if ( V_14 -> type == V_92 ) {
V_2 -> V_32 |= V_154 ;
F_34 ( V_2 , V_31 , V_2 -> V_32 ) ;
}
F_40 ( V_2 ) ;
}
static void F_81 ( struct V_6 * V_14 )
{
struct V_1 * V_2 = F_31 ( V_14 ) ;
F_43 ( V_2 ) ;
if ( V_2 -> V_155 && ! V_2 -> V_155 -> V_156 ( V_2 ) )
return;
if ( ! ( V_2 -> V_152 & V_153 ) ) {
V_2 -> V_152 |= V_153 ;
F_82 ( V_14 , V_57 , V_2 -> V_152 ) ;
if ( V_2 -> V_93 & V_157 ) {
unsigned char V_158 ;
V_158 = F_2 ( V_2 , V_78 ) ;
V_2 -> V_159 |= V_158 & V_160 ;
if ( V_158 & V_161 )
F_83 ( V_2 ) ;
}
}
if ( V_14 -> type == V_92 && V_2 -> V_32 & V_154 ) {
V_2 -> V_32 &= ~ V_154 ;
F_34 ( V_2 , V_31 , V_2 -> V_32 ) ;
}
}
static void F_84 ( struct V_6 * V_14 )
{
V_14 -> V_162 ( V_14 ) ;
}
static void F_85 ( struct V_6 * V_14 )
{
V_14 -> V_163 ( V_14 ) ;
}
static void F_86 ( struct V_6 * V_14 )
{
struct V_1 * V_2 = F_31 ( V_14 ) ;
F_38 ( V_2 ) ;
V_2 -> V_152 &= ~ ( V_164 | V_165 ) ;
V_2 -> V_14 . V_166 &= ~ V_79 ;
F_82 ( V_14 , V_57 , V_2 -> V_152 ) ;
F_40 ( V_2 ) ;
}
static void F_87 ( struct V_6 * V_14 )
{
struct V_1 * V_2 =
F_88 ( V_14 , struct V_1 , V_14 ) ;
if ( V_2 -> V_93 & V_167 )
return;
V_2 -> V_152 &= ~ V_168 ;
F_82 ( V_14 , V_57 , V_2 -> V_152 ) ;
}
static void F_89 ( struct V_6 * V_14 )
{
struct V_1 * V_2 = F_31 ( V_14 ) ;
if ( V_2 -> V_93 & V_167 )
return;
V_2 -> V_152 |= V_168 ;
F_38 ( V_2 ) ;
F_82 ( V_14 , V_57 , V_2 -> V_152 ) ;
F_40 ( V_2 ) ;
}
unsigned char
F_90 ( struct V_1 * V_2 , unsigned char V_158 )
{
struct V_6 * V_14 = & V_2 -> V_14 ;
unsigned char V_169 ;
int V_170 = 256 ;
char V_171 ;
do {
if ( F_91 ( V_158 & V_79 ) )
V_169 = F_2 ( V_2 , V_80 ) ;
else
V_169 = 0 ;
V_171 = V_172 ;
V_14 -> V_173 . V_174 ++ ;
V_158 |= V_2 -> V_159 ;
V_2 -> V_159 = 0 ;
if ( F_92 ( V_158 & V_175 ) ) {
if ( V_158 & V_176 ) {
V_158 &= ~ ( V_177 | V_178 ) ;
V_14 -> V_173 . V_179 ++ ;
if ( F_93 ( V_14 ) )
goto V_180;
} else if ( V_158 & V_178 )
V_14 -> V_173 . V_181 ++ ;
else if ( V_158 & V_177 )
V_14 -> V_173 . V_182 ++ ;
if ( V_158 & V_183 )
V_14 -> V_173 . V_184 ++ ;
V_158 &= V_14 -> V_166 ;
if ( V_158 & V_176 ) {
F_94 ( L_17 ) ;
V_171 = V_185 ;
} else if ( V_158 & V_178 )
V_171 = V_186 ;
else if ( V_158 & V_177 )
V_171 = V_187 ;
}
if ( F_95 ( V_14 , V_169 ) )
goto V_180;
F_96 ( V_14 , V_158 , V_183 , V_169 , V_171 ) ;
V_180:
V_158 = F_2 ( V_2 , V_78 ) ;
} while ( ( V_158 & ( V_79 | V_176 ) ) && ( -- V_170 > 0 ) );
F_97 ( & V_14 -> V_66 ) ;
F_98 ( & V_14 -> V_188 -> V_14 ) ;
F_99 ( & V_14 -> V_66 ) ;
return V_158 ;
}
void F_83 ( struct V_1 * V_2 )
{
struct V_6 * V_14 = & V_2 -> V_14 ;
struct V_189 * V_190 = & V_14 -> V_188 -> V_190 ;
int V_73 ;
if ( V_14 -> V_191 ) {
F_4 ( V_2 , V_77 , V_14 -> V_191 ) ;
V_14 -> V_173 . V_192 ++ ;
V_14 -> V_191 = 0 ;
return;
}
if ( F_100 ( V_14 ) ) {
F_80 ( V_14 ) ;
return;
}
if ( F_101 ( V_190 ) ) {
F_79 ( V_2 ) ;
return;
}
V_73 = V_2 -> V_138 ;
do {
F_4 ( V_2 , V_77 , V_190 -> V_193 [ V_190 -> V_194 ] ) ;
V_190 -> V_194 = ( V_190 -> V_194 + 1 ) & ( V_195 - 1 ) ;
V_14 -> V_173 . V_192 ++ ;
if ( F_101 ( V_190 ) )
break;
if ( V_2 -> V_34 & V_196 ) {
if ( ( F_102 ( V_14 , V_78 ) & V_197 ) !=
V_197 )
break;
}
} while ( -- V_73 > 0 );
if ( F_103 ( V_190 ) < V_198 )
F_104 ( V_14 ) ;
F_94 ( L_18 ) ;
if ( F_101 ( V_190 ) && ! ( V_2 -> V_34 & V_41 ) )
F_79 ( V_2 ) ;
}
unsigned int F_105 ( struct V_1 * V_2 )
{
struct V_6 * V_14 = & V_2 -> V_14 ;
unsigned int V_199 = F_2 ( V_2 , V_130 ) ;
V_199 |= V_2 -> V_200 ;
V_2 -> V_200 = 0 ;
if ( V_199 & V_201 && V_2 -> V_152 & V_168 &&
V_14 -> V_188 != NULL ) {
if ( V_199 & V_202 )
V_14 -> V_173 . V_203 ++ ;
if ( V_199 & V_204 )
V_14 -> V_173 . V_205 ++ ;
if ( V_199 & V_206 )
F_106 ( V_14 , V_199 & V_207 ) ;
if ( V_199 & V_208 )
F_107 ( V_14 , V_199 & V_209 ) ;
F_108 ( & V_14 -> V_188 -> V_14 . V_210 ) ;
}
return V_199 ;
}
int F_109 ( struct V_6 * V_14 , unsigned int V_211 )
{
unsigned char V_199 ;
unsigned long V_105 ;
struct V_1 * V_2 = F_31 ( V_14 ) ;
int V_212 = 0 ;
if ( V_211 & V_213 )
return 0 ;
F_65 ( & V_14 -> V_66 , V_105 ) ;
V_199 = F_102 ( V_14 , V_78 ) ;
F_94 ( L_19 , V_199 ) ;
if ( V_199 & ( V_79 | V_176 ) ) {
if ( V_2 -> V_155 )
V_212 = V_2 -> V_155 -> V_214 ( V_2 , V_211 ) ;
if ( ! V_2 -> V_155 || V_212 )
V_199 = F_90 ( V_2 , V_199 ) ;
}
F_105 ( V_2 ) ;
if ( ( ! V_2 -> V_155 || ( V_2 -> V_155 && V_2 -> V_155 -> V_215 ) ) &&
( V_199 & V_161 ) )
F_83 ( V_2 ) ;
F_67 ( & V_14 -> V_66 , V_105 ) ;
return 1 ;
}
static int V_27 ( struct V_6 * V_14 )
{
struct V_1 * V_2 = F_31 ( V_14 ) ;
unsigned int V_211 ;
int V_216 ;
F_38 ( V_2 ) ;
V_211 = F_102 ( V_14 , V_111 ) ;
V_216 = F_109 ( V_14 , V_211 ) ;
F_40 ( V_2 ) ;
return V_216 ;
}
static int F_110 ( struct V_6 * V_14 )
{
unsigned char V_217 , V_218 , V_219 , V_220 ;
unsigned int V_211 = F_102 ( V_14 , V_111 ) ;
int V_216 ;
V_216 = F_109 ( V_14 , V_211 ) ;
if ( ( V_14 -> type == V_48 ) ||
( V_14 -> type == V_49 ) ) {
V_217 = F_102 ( V_14 , 0x80 ) ;
V_218 = F_102 ( V_14 , 0x81 ) ;
V_219 = F_102 ( V_14 , 0x82 ) ;
V_220 = F_102 ( V_14 , 0x83 ) ;
}
return V_216 ;
}
static unsigned int F_111 ( struct V_6 * V_14 )
{
struct V_1 * V_2 = F_31 ( V_14 ) ;
unsigned long V_105 ;
unsigned int V_158 ;
F_38 ( V_2 ) ;
F_65 ( & V_14 -> V_66 , V_105 ) ;
V_158 = F_102 ( V_14 , V_78 ) ;
V_2 -> V_159 |= V_158 & V_160 ;
F_67 ( & V_14 -> V_66 , V_105 ) ;
F_40 ( V_2 ) ;
return ( V_158 & V_197 ) == V_197 ? V_221 : 0 ;
}
static unsigned int F_112 ( struct V_6 * V_14 )
{
struct V_1 * V_2 = F_31 ( V_14 ) ;
unsigned int V_199 ;
unsigned int V_216 ;
F_38 ( V_2 ) ;
V_199 = F_105 ( V_2 ) ;
F_40 ( V_2 ) ;
V_216 = 0 ;
if ( V_199 & V_207 )
V_216 |= V_222 ;
if ( V_199 & V_223 )
V_216 |= V_224 ;
if ( V_199 & V_225 )
V_216 |= V_226 ;
if ( V_199 & V_209 )
V_216 |= V_227 ;
return V_216 ;
}
void F_113 ( struct V_6 * V_14 , unsigned int V_228 )
{
struct V_1 * V_2 = F_31 ( V_14 ) ;
unsigned char V_229 = 0 ;
if ( V_228 & V_230 )
V_229 |= V_151 ;
if ( V_228 & V_231 )
V_229 |= V_150 ;
if ( V_228 & V_232 )
V_229 |= V_148 ;
if ( V_228 & V_233 )
V_229 |= V_149 ;
if ( V_228 & V_234 )
V_229 |= V_75 ;
V_229 = ( V_229 & V_2 -> V_235 ) | V_2 -> V_236 | V_2 -> V_229 ;
F_82 ( V_14 , V_74 , V_229 ) ;
}
static void F_114 ( struct V_6 * V_14 , unsigned int V_228 )
{
if ( V_14 -> V_237 )
V_14 -> V_237 ( V_14 , V_228 ) ;
else
F_113 ( V_14 , V_228 ) ;
}
static void F_115 ( struct V_6 * V_14 , int V_238 )
{
struct V_1 * V_2 = F_31 ( V_14 ) ;
unsigned long V_105 ;
F_38 ( V_2 ) ;
F_65 ( & V_14 -> V_66 , V_105 ) ;
if ( V_238 == - 1 )
V_2 -> V_46 |= V_239 ;
else
V_2 -> V_46 &= ~ V_239 ;
F_82 ( V_14 , V_28 , V_2 -> V_46 ) ;
F_67 ( & V_14 -> V_66 , V_105 ) ;
F_40 ( V_2 ) ;
}
static void F_116 ( struct V_1 * V_2 , int V_240 )
{
unsigned int V_199 , V_241 = 10000 ;
for (; ; ) {
V_199 = F_2 ( V_2 , V_78 ) ;
V_2 -> V_159 |= V_199 & V_160 ;
if ( ( V_199 & V_240 ) == V_240 )
break;
if ( -- V_241 == 0 )
break;
F_77 ( 1 ) ;
}
if ( V_2 -> V_14 . V_105 & V_242 ) {
unsigned int V_241 ;
for ( V_241 = 1000000 ; V_241 ; V_241 -- ) {
unsigned int V_243 = F_2 ( V_2 , V_130 ) ;
V_2 -> V_200 |= V_243 & V_244 ;
if ( V_243 & V_209 )
break;
F_77 ( 1 ) ;
F_117 () ;
}
}
}
static int F_118 ( struct V_6 * V_14 )
{
struct V_1 * V_2 = F_31 ( V_14 ) ;
unsigned char V_158 ;
int V_199 ;
F_38 ( V_2 ) ;
V_158 = F_102 ( V_14 , V_78 ) ;
if ( ! ( V_158 & V_79 ) ) {
V_199 = V_245 ;
goto V_51;
}
V_199 = F_102 ( V_14 , V_80 ) ;
V_51:
F_40 ( V_2 ) ;
return V_199 ;
}
static void F_119 ( struct V_6 * V_14 ,
unsigned char V_246 )
{
unsigned int V_152 ;
struct V_1 * V_2 = F_31 ( V_14 ) ;
F_38 ( V_2 ) ;
V_152 = F_102 ( V_14 , V_57 ) ;
if ( V_2 -> V_34 & V_119 )
F_82 ( V_14 , V_57 , V_117 ) ;
else
F_82 ( V_14 , V_57 , 0 ) ;
F_116 ( V_2 , V_197 ) ;
F_82 ( V_14 , V_77 , V_246 ) ;
F_116 ( V_2 , V_197 ) ;
F_82 ( V_14 , V_57 , V_152 ) ;
F_40 ( V_2 ) ;
}
int F_120 ( struct V_6 * V_14 )
{
struct V_1 * V_2 = F_31 ( V_14 ) ;
unsigned long V_105 ;
unsigned char V_158 , V_211 ;
int V_247 ;
if ( ! V_14 -> V_135 )
V_14 -> V_135 = V_136 [ V_14 -> type ] . V_137 ;
if ( ! V_2 -> V_138 )
V_2 -> V_138 = V_136 [ V_14 -> type ] . V_138 ;
if ( ! V_2 -> V_34 )
V_2 -> V_34 = V_136 [ V_14 -> type ] . V_105 ;
V_2 -> V_229 = 0 ;
if ( V_14 -> V_19 != V_2 -> V_25 )
F_30 ( V_14 ) ;
F_38 ( V_2 ) ;
if ( V_14 -> type == V_92 ) {
V_2 -> V_32 = 0 ;
F_82 ( V_14 , V_28 , V_55 ) ;
F_82 ( V_14 , V_54 , V_56 ) ;
F_82 ( V_14 , V_57 , 0 ) ;
F_82 ( V_14 , V_28 , 0 ) ;
F_34 ( V_2 , V_248 , 0 ) ;
F_82 ( V_14 , V_28 , V_55 ) ;
F_82 ( V_14 , V_54 , V_56 ) ;
F_82 ( V_14 , V_28 , 0 ) ;
}
#ifdef F_68
F_48 ( V_2 ) ;
#endif
if ( V_14 -> type == V_48 ) {
F_82 ( V_14 , V_249 , V_56 ) ;
F_82 ( V_14 , V_57 , 0 ) ;
}
F_36 ( V_2 ) ;
F_102 ( V_14 , V_78 ) ;
F_102 ( V_14 , V_80 ) ;
F_102 ( V_14 , V_111 ) ;
F_102 ( V_14 , V_130 ) ;
if ( ! ( V_14 -> V_105 & V_128 ) &&
( F_102 ( V_14 , V_78 ) == 0xff ) ) {
F_121 ( V_250 L_20 ,
F_64 ( V_14 ) ) ;
V_247 = - V_251 ;
goto V_51;
}
if ( V_14 -> type == V_95 ) {
unsigned char V_252 ;
F_4 ( V_2 , V_28 , V_55 ) ;
V_252 = F_2 ( V_2 , V_253 ) & ~ ( V_254 | V_255 ) ;
F_82 ( V_14 , V_253 ,
V_252 | V_256 | V_254 ) ;
F_82 ( V_14 , V_257 , V_258 ) ;
F_82 ( V_14 , V_253 ,
V_252 | V_256 | V_255 ) ;
F_82 ( V_14 , V_257 , V_258 ) ;
F_82 ( V_14 , V_28 , 0 ) ;
}
if ( V_14 -> V_146 ) {
unsigned char V_259 ;
F_65 ( & V_14 -> V_66 , V_105 ) ;
if ( V_2 -> V_14 . V_260 & V_261 )
F_122 ( V_14 -> V_146 ) ;
F_116 ( V_2 , V_161 ) ;
F_33 ( V_14 , V_57 , V_153 ) ;
F_77 ( 1 ) ;
V_259 = F_102 ( V_14 , V_111 ) ;
F_82 ( V_14 , V_57 , 0 ) ;
F_33 ( V_14 , V_57 , V_153 ) ;
F_77 ( 1 ) ;
V_211 = F_102 ( V_14 , V_111 ) ;
F_82 ( V_14 , V_57 , 0 ) ;
if ( V_14 -> V_260 & V_261 )
F_123 ( V_14 -> V_146 ) ;
F_67 ( & V_14 -> V_66 , V_105 ) ;
if ( ( ! ( V_259 & V_213 ) && ( V_211 & V_213 ) ) ||
V_2 -> V_14 . V_105 & V_262 ) {
V_2 -> V_93 |= V_263 ;
}
}
V_247 = V_2 -> V_264 -> V_265 ( V_2 ) ;
if ( V_247 )
goto V_51;
F_82 ( V_14 , V_28 , V_266 ) ;
F_65 ( & V_14 -> V_66 , V_105 ) ;
if ( V_2 -> V_14 . V_105 & V_147 ) {
if ( ! V_2 -> V_14 . V_146 )
V_2 -> V_14 . V_228 |= V_232 ;
} else
if ( V_14 -> V_146 )
V_2 -> V_14 . V_228 |= V_233 ;
F_114 ( V_14 , V_14 -> V_228 ) ;
if ( V_2 -> V_14 . V_105 & V_267 )
goto V_268;
F_82 ( V_14 , V_57 , V_153 ) ;
V_158 = F_102 ( V_14 , V_78 ) ;
V_211 = F_102 ( V_14 , V_111 ) ;
F_82 ( V_14 , V_57 , 0 ) ;
if ( V_158 & V_269 && V_211 & V_213 ) {
if ( ! ( V_2 -> V_93 & V_157 ) ) {
V_2 -> V_93 |= V_157 ;
F_124 ( L_21 ,
F_64 ( V_14 ) ) ;
}
} else {
V_2 -> V_93 &= ~ V_157 ;
}
V_268:
F_67 ( & V_14 -> V_66 , V_105 ) ;
F_102 ( V_14 , V_78 ) ;
F_102 ( V_14 , V_80 ) ;
F_102 ( V_14 , V_111 ) ;
F_102 ( V_14 , V_130 ) ;
V_2 -> V_159 = 0 ;
V_2 -> V_200 = 0 ;
if ( V_2 -> V_155 ) {
V_247 = F_125 ( V_2 ) ;
if ( V_247 ) {
F_126 ( L_22 ,
F_64 ( V_14 ) ) ;
V_2 -> V_155 = NULL ;
}
}
V_2 -> V_152 = V_164 | V_165 ;
if ( V_14 -> V_105 & V_147 ) {
unsigned int V_270 ;
V_270 = ( V_14 -> V_16 & 0xfe0 ) | 0x01f ;
F_72 ( 0x80 , V_270 ) ;
F_71 ( V_270 ) ;
}
V_247 = 0 ;
V_51:
F_40 ( V_2 ) ;
return V_247 ;
}
static int F_127 ( struct V_6 * V_14 )
{
if ( V_14 -> V_271 )
return V_14 -> V_271 ( V_14 ) ;
return F_120 ( V_14 ) ;
}
void F_128 ( struct V_6 * V_14 )
{
struct V_1 * V_2 = F_31 ( V_14 ) ;
unsigned long V_105 ;
F_38 ( V_2 ) ;
V_2 -> V_152 = 0 ;
F_82 ( V_14 , V_57 , 0 ) ;
if ( V_2 -> V_155 )
F_129 ( V_2 ) ;
F_65 ( & V_14 -> V_66 , V_105 ) ;
if ( V_14 -> V_105 & V_147 ) {
F_14 ( ( V_14 -> V_16 & 0xfe0 ) | 0x1f ) ;
V_14 -> V_228 |= V_232 ;
} else
V_14 -> V_228 &= ~ V_233 ;
F_114 ( V_14 , V_14 -> V_228 ) ;
F_67 ( & V_14 -> V_66 , V_105 ) ;
F_82 ( V_14 , V_28 ,
F_102 ( V_14 , V_28 ) & ~ V_239 ) ;
F_36 ( V_2 ) ;
#ifdef F_68
F_51 ( V_2 ) ;
#endif
F_102 ( V_14 , V_80 ) ;
F_40 ( V_2 ) ;
V_2 -> V_264 -> V_272 ( V_2 ) ;
}
static void F_130 ( struct V_6 * V_14 )
{
if ( V_14 -> V_273 )
V_14 -> V_273 ( V_14 ) ;
else
F_128 ( V_14 ) ;
}
static unsigned int F_131 ( struct V_1 * V_2 ,
unsigned int V_274 ,
unsigned int * V_275 )
{
struct V_6 * V_14 = & V_2 -> V_14 ;
unsigned int V_276 ;
V_276 = F_132 ( V_14 -> V_63 , V_274 ) ;
* V_275 = V_276 & 0x0f ;
return V_276 >> 4 ;
}
static unsigned int F_133 ( struct V_1 * V_2 ,
unsigned int V_274 ,
unsigned int * V_275 )
{
struct V_6 * V_14 = & V_2 -> V_14 ;
unsigned int V_113 ;
if ( ( V_14 -> V_105 & V_277 ) &&
V_274 == ( V_14 -> V_63 / 4 ) )
V_113 = 0x8001 ;
else if ( ( V_14 -> V_105 & V_277 ) &&
V_274 == ( V_14 -> V_63 / 8 ) )
V_113 = 0x8002 ;
else if ( V_2 -> V_14 . type == V_48 )
V_113 = F_131 ( V_2 , V_274 , V_275 ) ;
else
V_113 = F_134 ( V_14 , V_274 ) ;
if ( V_2 -> V_93 & V_94 && ( V_113 & 0xff ) == 0 )
V_113 ++ ;
return V_113 ;
}
static unsigned char F_135 ( struct V_1 * V_2 ,
T_1 V_278 )
{
unsigned char V_279 ;
switch ( V_278 & V_280 ) {
case V_281 :
V_279 = V_282 ;
break;
case V_283 :
V_279 = V_284 ;
break;
case V_285 :
V_279 = V_286 ;
break;
default:
case V_287 :
V_279 = V_266 ;
break;
}
if ( V_278 & V_288 )
V_279 |= V_289 ;
if ( V_278 & V_290 ) {
V_279 |= V_291 ;
if ( V_2 -> V_93 & V_292 )
V_2 -> V_293 = true ;
}
if ( ! ( V_278 & V_294 ) )
V_279 |= V_295 ;
#ifdef F_136
if ( V_278 & F_136 )
V_279 |= V_296 ;
#endif
return V_279 ;
}
static void F_137 ( struct V_6 * V_14 , unsigned int V_274 ,
unsigned int V_113 , unsigned int V_297 )
{
struct V_1 * V_2 = F_31 ( V_14 ) ;
if ( F_138 ( V_2 ) ) {
if ( V_274 == 115200 ) {
V_113 = 1 ;
F_82 ( V_14 , V_298 , 1 ) ;
} else
F_82 ( V_14 , V_298 , 0 ) ;
}
if ( V_2 -> V_34 & V_115 )
F_82 ( V_14 , V_28 , 0xe0 ) ;
else
F_82 ( V_14 , V_28 , V_2 -> V_46 | V_299 ) ;
F_54 ( V_2 , V_113 ) ;
if ( V_2 -> V_14 . type == V_48 )
F_82 ( V_14 , 0x2 , V_297 ) ;
}
static unsigned int
F_139 ( struct V_6 * V_14 , struct V_300 * V_301 ,
struct V_300 * V_302 )
{
unsigned int V_303 = V_14 -> V_63 / 100 ;
return F_140 ( V_14 , V_301 , V_302 ,
V_14 -> V_63 / 16 / 0xffff ,
( V_14 -> V_63 + V_303 ) / 16 ) ;
}
void
F_141 ( struct V_6 * V_14 , struct V_300 * V_301 ,
struct V_300 * V_302 )
{
struct V_1 * V_2 = F_31 ( V_14 ) ;
unsigned char V_279 ;
unsigned long V_105 ;
unsigned int V_274 , V_113 , V_275 = 0 ;
V_279 = F_135 ( V_2 , V_301 -> V_278 ) ;
V_274 = F_139 ( V_14 , V_301 , V_302 ) ;
V_113 = F_133 ( V_2 , V_274 , & V_275 ) ;
F_38 ( V_2 ) ;
F_65 ( & V_14 -> V_66 , V_105 ) ;
V_2 -> V_46 = V_279 ;
if ( V_2 -> V_34 & V_35 && V_14 -> V_135 > 1 ) {
if ( ( V_274 < 2400 && ! V_2 -> V_155 ) || V_2 -> V_293 ) {
V_2 -> V_40 &= ~ V_304 ;
V_2 -> V_40 |= V_305 ;
}
}
if ( V_2 -> V_34 & V_108 && V_14 -> V_135 >= 32 ) {
V_2 -> V_229 &= ~ V_306 ;
if ( V_301 -> V_278 & V_307 )
V_2 -> V_229 |= V_306 ;
}
F_142 ( V_14 , V_301 -> V_278 , V_274 ) ;
V_14 -> V_166 = V_183 | V_161 | V_79 ;
if ( V_301 -> V_308 & V_309 )
V_14 -> V_166 |= V_177 | V_178 ;
if ( V_301 -> V_308 & ( V_310 | V_311 | V_312 ) )
V_14 -> V_166 |= V_176 ;
V_14 -> V_313 = 0 ;
if ( V_301 -> V_308 & V_314 )
V_14 -> V_313 |= V_178 | V_177 ;
if ( V_301 -> V_308 & V_310 ) {
V_14 -> V_313 |= V_176 ;
if ( V_301 -> V_308 & V_314 )
V_14 -> V_313 |= V_183 ;
}
if ( ( V_301 -> V_278 & V_315 ) == 0 )
V_14 -> V_313 |= V_79 ;
V_2 -> V_152 &= ~ V_168 ;
if ( ! ( V_2 -> V_93 & V_167 ) &&
F_143 ( & V_2 -> V_14 , V_301 -> V_278 ) )
V_2 -> V_152 |= V_168 ;
if ( V_2 -> V_34 & V_119 )
V_2 -> V_152 |= V_117 ;
if ( V_2 -> V_34 & V_120 )
V_2 -> V_152 |= V_316 ;
F_82 ( V_14 , V_57 , V_2 -> V_152 ) ;
if ( V_2 -> V_34 & V_53 ) {
unsigned char V_47 = 0 ;
if ( V_301 -> V_278 & V_307 )
V_47 |= V_317 ;
F_82 ( V_14 , V_28 , V_55 ) ;
if ( V_14 -> V_105 & V_106 )
F_82 ( V_14 , V_249 , V_47 ) ;
else
F_82 ( V_14 , V_54 , V_47 ) ;
}
F_137 ( V_14 , V_274 , V_113 , V_275 ) ;
if ( V_14 -> type == V_116 )
F_82 ( V_14 , V_36 , V_2 -> V_40 ) ;
F_82 ( V_14 , V_28 , V_2 -> V_46 ) ;
if ( V_14 -> type != V_116 ) {
if ( V_2 -> V_40 & V_37 )
F_82 ( V_14 , V_36 , V_37 ) ;
F_82 ( V_14 , V_36 , V_2 -> V_40 ) ;
}
F_114 ( V_14 , V_14 -> V_228 ) ;
F_67 ( & V_14 -> V_66 , V_105 ) ;
F_40 ( V_2 ) ;
if ( F_144 ( V_301 ) )
F_145 ( V_301 , V_274 , V_274 ) ;
}
static void
F_146 ( struct V_6 * V_14 , struct V_300 * V_301 ,
struct V_300 * V_302 )
{
if ( V_14 -> V_318 )
V_14 -> V_318 ( V_14 , V_301 , V_302 ) ;
else
F_141 ( V_14 , V_301 , V_302 ) ;
}
static void
F_147 ( struct V_6 * V_14 , struct V_300 * V_301 )
{
if ( V_301 -> V_319 == V_320 ) {
V_14 -> V_105 |= V_321 ;
F_49 ( & V_14 -> V_66 ) ;
F_89 ( V_14 ) ;
F_50 ( & V_14 -> V_66 ) ;
} else {
V_14 -> V_105 &= ~ V_321 ;
if ( ! F_143 ( V_14 , V_301 -> V_278 ) ) {
F_49 ( & V_14 -> V_66 ) ;
F_87 ( V_14 ) ;
F_50 ( & V_14 -> V_66 ) ;
}
}
}
void F_148 ( struct V_6 * V_14 , unsigned int V_188 ,
unsigned int V_322 )
{
struct V_1 * V_7 = F_31 ( V_14 ) ;
F_46 ( V_7 , V_188 != 0 ) ;
}
static void
F_149 ( struct V_6 * V_14 , unsigned int V_188 ,
unsigned int V_322 )
{
if ( V_14 -> V_323 )
V_14 -> V_323 ( V_14 , V_188 , V_322 ) ;
else
F_148 ( V_14 , V_188 , V_322 ) ;
}
static unsigned int F_150 ( struct V_1 * V_324 )
{
if ( V_324 -> V_14 . V_325 )
return V_324 -> V_14 . V_325 ;
if ( V_324 -> V_14 . V_19 == V_24 ) {
if ( V_324 -> V_14 . type == V_326 )
return 0x100 ;
return 0x1000 ;
}
if ( F_151 ( V_324 ) )
return 0x16 << V_324 -> V_14 . V_12 ;
return 8 << V_324 -> V_14 . V_12 ;
}
static int F_152 ( struct V_1 * V_2 )
{
unsigned int V_327 = F_150 ( V_2 ) ;
struct V_6 * V_14 = & V_2 -> V_14 ;
int V_216 = 0 ;
switch ( V_14 -> V_19 ) {
case V_24 :
case V_328 :
case V_22 :
case V_23 :
case V_21 :
if ( ! V_14 -> V_127 )
break;
if ( ! F_153 ( V_14 -> V_127 , V_327 , L_23 ) ) {
V_216 = - V_329 ;
break;
}
if ( V_14 -> V_105 & V_330 ) {
V_14 -> V_11 = F_154 ( V_14 -> V_127 , V_327 ) ;
if ( ! V_14 -> V_11 ) {
F_155 ( V_14 -> V_127 , V_327 ) ;
V_216 = - V_331 ;
}
}
break;
case V_20 :
case V_332 :
if ( ! F_156 ( V_14 -> V_16 , V_327 , L_23 ) )
V_216 = - V_329 ;
break;
}
return V_216 ;
}
static void F_157 ( struct V_1 * V_2 )
{
unsigned int V_327 = F_150 ( V_2 ) ;
struct V_6 * V_14 = & V_2 -> V_14 ;
switch ( V_14 -> V_19 ) {
case V_24 :
case V_328 :
case V_22 :
case V_23 :
case V_21 :
if ( ! V_14 -> V_127 )
break;
if ( V_14 -> V_105 & V_330 ) {
F_158 ( V_14 -> V_11 ) ;
V_14 -> V_11 = NULL ;
}
F_155 ( V_14 -> V_127 , V_327 ) ;
break;
case V_20 :
case V_332 :
F_159 ( V_14 -> V_16 , V_327 ) ;
break;
}
}
static void F_160 ( struct V_6 * V_14 )
{
struct V_1 * V_2 = F_31 ( V_14 ) ;
F_157 ( V_2 ) ;
}
static int F_161 ( struct V_6 * V_14 )
{
struct V_1 * V_2 = F_31 ( V_14 ) ;
return F_152 ( V_2 ) ;
}
static int F_162 ( struct V_1 * V_2 )
{
const struct V_333 * V_334 = & V_136 [ V_2 -> V_14 . type ] ;
unsigned char V_335 ;
V_335 = V_334 -> V_336 [ F_163 ( V_2 -> V_40 ) ] ;
return V_335 ? V_335 : - V_337 ;
}
static int F_164 ( struct V_1 * V_2 , unsigned char V_335 )
{
const struct V_333 * V_334 = & V_136 [ V_2 -> V_14 . type ] ;
int V_338 ;
if ( ! V_334 -> V_336 [ F_163 ( V_339 ) ] )
return - V_337 ;
for ( V_338 = 1 ; V_338 < V_340 ; V_338 ++ ) {
if ( V_335 < V_334 -> V_336 [ V_338 ] )
return ( -- V_338 ) << V_341 ;
}
return V_342 ;
}
static int F_165 ( struct V_343 * V_14 )
{
struct V_344 * V_188 = F_88 ( V_14 , struct V_344 , V_14 ) ;
struct V_6 * V_345 = V_188 -> V_6 ;
struct V_1 * V_2 =
F_88 ( V_345 , struct V_1 , V_14 ) ;
if ( ! ( V_2 -> V_34 & V_35 ) || V_345 -> V_135 <= 1 )
return - V_346 ;
return F_162 ( V_2 ) ;
}
static int F_166 ( struct V_343 * V_14 )
{
int V_336 ;
F_167 ( & V_14 -> V_347 ) ;
V_336 = F_165 ( V_14 ) ;
F_168 ( & V_14 -> V_347 ) ;
return V_336 ;
}
static T_2 F_169 ( struct V_348 * V_42 ,
struct V_349 * V_350 , char * V_193 )
{
struct V_343 * V_14 = F_170 ( V_42 ) ;
int V_336 ;
V_336 = F_166 ( V_14 ) ;
if ( V_336 < 0 )
return V_336 ;
return snprintf ( V_193 , V_351 , L_24 , V_336 ) ;
}
static int F_171 ( struct V_343 * V_14 , unsigned char V_335 )
{
struct V_344 * V_188 = F_88 ( V_14 , struct V_344 , V_14 ) ;
struct V_6 * V_345 = V_188 -> V_6 ;
struct V_1 * V_2 =
F_88 ( V_345 , struct V_1 , V_14 ) ;
int V_352 ;
if ( ! ( V_2 -> V_34 & V_35 ) || V_345 -> V_135 <= 1 ||
V_2 -> V_293 )
return - V_346 ;
V_352 = F_164 ( V_2 , V_335 ) ;
if ( V_352 < 0 )
return V_352 ;
F_36 ( V_2 ) ;
V_2 -> V_40 &= ~ V_304 ;
V_2 -> V_40 |= ( unsigned char ) V_352 ;
F_4 ( V_2 , V_36 , V_2 -> V_40 ) ;
return 0 ;
}
static int F_172 ( struct V_343 * V_14 , unsigned char V_335 )
{
int V_216 ;
F_167 ( & V_14 -> V_347 ) ;
V_216 = F_171 ( V_14 , V_335 ) ;
F_168 ( & V_14 -> V_347 ) ;
return V_216 ;
}
static T_2 F_173 ( struct V_348 * V_42 ,
struct V_349 * V_350 , const char * V_193 , T_3 V_73 )
{
struct V_343 * V_14 = F_170 ( V_42 ) ;
unsigned char V_335 ;
int V_216 ;
if ( ! V_73 )
return - V_346 ;
V_216 = F_174 ( V_193 , 10 , & V_335 ) ;
if ( V_216 < 0 )
return V_216 ;
V_216 = F_172 ( V_14 , V_335 ) ;
if ( V_216 < 0 )
return V_216 ;
return V_73 ;
}
static void F_175 ( struct V_1 * V_2 )
{
const struct V_333 * V_334 = & V_136 [ V_2 -> V_14 . type ] ;
if ( V_334 -> V_336 [ 0 ] )
V_2 -> V_14 . V_353 = & V_354 ;
}
static void F_176 ( struct V_6 * V_14 , int V_105 )
{
struct V_1 * V_2 = F_31 ( V_14 ) ;
int V_216 ;
V_216 = F_152 ( V_2 ) ;
if ( V_216 < 0 )
return;
if ( V_14 -> V_19 != V_2 -> V_25 )
F_30 ( V_14 ) ;
if ( V_105 & V_355 )
F_63 ( V_2 ) ;
if ( V_14 -> type == V_104 && V_14 -> V_19 == V_24 )
V_2 -> V_93 |= V_167 ;
if ( V_14 -> type == V_356 )
V_2 -> V_93 |= V_167 ;
if ( V_14 -> type != V_131 && V_105 & V_357 )
F_70 ( V_2 ) ;
if ( V_14 -> type == V_131 )
F_157 ( V_2 ) ;
if ( ( V_14 -> type == V_48 ) ||
( V_14 -> type == V_49 ) )
V_14 -> V_26 = F_110 ;
F_175 ( V_2 ) ;
V_2 -> V_40 = V_136 [ V_2 -> V_14 . type ] . V_40 ;
}
static int
F_177 ( struct V_6 * V_14 , struct V_358 * V_359 )
{
if ( V_359 -> V_146 >= V_360 || V_359 -> V_146 < 0 ||
V_359 -> V_361 < 9600 || V_359 -> type < V_131 ||
V_359 -> type >= F_6 ( V_136 ) || V_359 -> type == V_362 ||
V_359 -> type == V_363 )
return - V_346 ;
return 0 ;
}
static const char *
F_178 ( struct V_6 * V_14 )
{
int type = V_14 -> type ;
if ( type >= F_6 ( V_136 ) )
type = 0 ;
return V_136 [ type ] . V_141 ;
}
void F_179 ( struct V_1 * V_2 )
{
struct V_6 * V_14 = & V_2 -> V_14 ;
F_180 ( & V_14 -> V_66 ) ;
V_14 -> V_264 = & V_364 ;
V_2 -> V_25 = 0xFF ;
}
void F_181 ( struct V_1 * V_2 )
{
struct V_6 * V_14 = & V_2 -> V_14 ;
if ( V_2 -> V_14 . V_105 & V_365 ) {
unsigned int type = V_2 -> V_14 . type ;
if ( ! V_2 -> V_14 . V_135 )
V_2 -> V_14 . V_135 = V_136 [ type ] . V_137 ;
if ( ! V_2 -> V_138 )
V_2 -> V_138 = V_136 [ type ] . V_138 ;
if ( ! V_2 -> V_34 )
V_2 -> V_34 = V_136 [ type ] . V_105 ;
}
F_30 ( V_14 ) ;
if ( V_2 -> V_155 ) {
if ( ! V_2 -> V_155 -> V_156 )
V_2 -> V_155 -> V_156 = V_366 ;
if ( ! V_2 -> V_155 -> V_214 )
V_2 -> V_155 -> V_214 = V_367 ;
}
}
static void F_182 ( struct V_6 * V_14 , int V_169 )
{
struct V_1 * V_2 = F_31 ( V_14 ) ;
F_116 ( V_2 , V_161 ) ;
F_82 ( V_14 , V_77 , V_169 ) ;
}
static void F_183 ( struct V_1 * V_2 )
{
struct V_6 * V_14 = & V_2 -> V_14 ;
struct V_300 V_301 ;
unsigned int V_274 , V_113 , V_275 = 0 ;
V_301 . V_278 = V_14 -> V_368 -> V_369 ;
if ( V_14 -> V_188 -> V_14 . V_370 && V_301 . V_278 == 0 )
V_301 . V_278 = V_14 -> V_188 -> V_14 . V_370 -> V_301 . V_278 ;
V_274 = F_139 ( V_14 , & V_301 , NULL ) ;
V_113 = F_133 ( V_2 , V_274 , & V_275 ) ;
F_137 ( V_14 , V_274 , V_113 , V_275 ) ;
F_82 ( V_14 , V_28 , V_2 -> V_46 ) ;
F_82 ( V_14 , V_74 , V_150 | V_151 ) ;
}
void F_184 ( struct V_1 * V_2 , const char * V_371 ,
unsigned int V_73 )
{
struct V_6 * V_14 = & V_2 -> V_14 ;
unsigned long V_105 ;
unsigned int V_152 ;
int V_372 = 1 ;
F_117 () ;
F_38 ( V_2 ) ;
if ( V_14 -> V_373 )
V_372 = 0 ;
else if ( V_374 )
V_372 = F_185 ( & V_14 -> V_66 , V_105 ) ;
else
F_65 ( & V_14 -> V_66 , V_105 ) ;
V_152 = F_102 ( V_14 , V_57 ) ;
if ( V_2 -> V_34 & V_119 )
F_82 ( V_14 , V_57 , V_117 ) ;
else
F_82 ( V_14 , V_57 , 0 ) ;
if ( V_2 -> V_375 && ( V_2 -> V_375 != F_102 ( V_14 , V_29 ) ) ) {
F_183 ( V_2 ) ;
V_2 -> V_375 = 0 ;
}
F_186 ( V_14 , V_371 , V_73 , F_182 ) ;
F_116 ( V_2 , V_197 ) ;
F_82 ( V_14 , V_57 , V_152 ) ;
if ( V_2 -> V_200 )
F_105 ( V_2 ) ;
if ( V_372 )
F_67 ( & V_14 -> V_66 , V_105 ) ;
F_40 ( V_2 ) ;
}
static unsigned int F_187 ( struct V_6 * V_14 )
{
unsigned char V_46 , V_376 , V_377 ;
unsigned int V_113 ;
V_46 = F_102 ( V_14 , V_28 ) ;
F_82 ( V_14 , V_28 , V_46 | V_299 ) ;
V_376 = F_102 ( V_14 , V_3 ) ;
V_377 = F_102 ( V_14 , V_4 ) ;
F_82 ( V_14 , V_28 , V_46 ) ;
V_113 = ( V_377 << 8 ) | V_376 ;
return ( V_14 -> V_63 / 16 ) / V_113 ;
}
int F_188 ( struct V_6 * V_14 , char * V_378 , bool V_133 )
{
int V_274 = 9600 ;
int V_240 = 8 ;
int V_181 = 'n' ;
int V_379 = 'n' ;
if ( ! V_14 -> V_16 && ! V_14 -> V_11 )
return - V_251 ;
if ( V_378 )
F_189 ( V_378 , & V_274 , & V_181 , & V_240 , & V_379 ) ;
else if ( V_133 )
V_274 = F_187 ( V_14 ) ;
return F_190 ( V_14 , V_14 -> V_368 , V_274 , V_181 , V_240 , V_379 ) ;
}
