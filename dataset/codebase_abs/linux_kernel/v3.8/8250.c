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
V_11 = V_16 [ V_11 ] << V_10 -> V_13 ;
return F_13 ( V_10 -> V_14 + V_11 ) ;
}
static void F_14 ( struct V_1 * V_10 , int V_11 , int V_9 )
{
V_11 = V_17 [ V_11 ] << V_10 -> V_13 ;
F_15 ( V_9 , V_10 -> V_14 + V_11 ) ;
}
static int F_16 ( struct V_5 * V_6 )
{
return ( ( F_7 ( V_6 -> V_2 . V_14 + 0x10 ) << 8 ) |
( F_7 ( V_6 -> V_2 . V_14 + 0x08 ) & 0xff ) ) & 0xffff ;
}
static void F_17 ( struct V_5 * V_6 , int V_9 )
{
F_9 ( V_9 , V_6 -> V_2 . V_14 + 0x08 ) ;
F_9 ( V_9 >> 8 , V_6 -> V_2 . V_14 + 0x10 ) ;
}
static unsigned int F_18 ( struct V_1 * V_10 , int V_11 )
{
V_11 = V_11 << V_10 -> V_13 ;
F_19 ( V_10 -> V_18 - 1 + V_11 , V_10 -> V_19 ) ;
return F_20 ( V_10 -> V_19 + 1 ) ;
}
static void F_21 ( struct V_1 * V_10 , int V_11 , int V_9 )
{
V_11 = V_11 << V_10 -> V_13 ;
F_19 ( V_10 -> V_18 - 1 + V_11 , V_10 -> V_19 ) ;
F_19 ( V_9 , V_10 -> V_19 + 1 ) ;
}
static unsigned int F_22 ( struct V_1 * V_10 , int V_11 )
{
V_11 = V_11 << V_10 -> V_13 ;
return F_23 ( V_10 -> V_14 + V_11 ) ;
}
static void F_24 ( struct V_1 * V_10 , int V_11 , int V_9 )
{
V_11 = V_11 << V_10 -> V_13 ;
F_25 ( V_9 , V_10 -> V_14 + V_11 ) ;
}
static void F_26 ( struct V_1 * V_10 , int V_11 , int V_9 )
{
V_11 = V_11 << V_10 -> V_13 ;
F_15 ( V_9 , V_10 -> V_14 + V_11 ) ;
}
static unsigned int F_27 ( struct V_1 * V_10 , int V_11 )
{
V_11 = V_11 << V_10 -> V_13 ;
return F_13 ( V_10 -> V_14 + V_11 ) ;
}
static unsigned int F_28 ( struct V_1 * V_10 , int V_11 )
{
V_11 = V_11 << V_10 -> V_13 ;
return F_20 ( V_10 -> V_19 + V_11 ) ;
}
static void F_29 ( struct V_1 * V_10 , int V_11 , int V_9 )
{
V_11 = V_11 << V_10 -> V_13 ;
F_19 ( V_9 , V_10 -> V_19 + V_11 ) ;
}
static void F_30 ( struct V_1 * V_10 )
{
struct V_5 * V_6 =
F_31 ( V_10 , struct V_5 , V_2 ) ;
V_6 -> V_20 = F_2 ;
V_6 -> V_21 = F_4 ;
switch ( V_10 -> V_22 ) {
case V_23 :
V_10 -> F_3 = F_18 ;
V_10 -> F_5 = F_21 ;
break;
case V_24 :
V_10 -> F_3 = F_22 ;
V_10 -> F_5 = F_24 ;
break;
case V_25 :
V_10 -> F_3 = F_27 ;
V_10 -> F_5 = F_26 ;
break;
#ifdef F_32
case V_26 :
V_10 -> F_3 = F_12 ;
V_10 -> F_5 = F_14 ;
V_6 -> V_20 = F_16 ;
V_6 -> V_21 = F_17 ;
break;
#endif
#ifdef F_33
case V_27 :
V_10 -> F_3 = F_6 ;
V_10 -> F_5 = F_8 ;
V_6 -> V_20 = F_10 ;
V_6 -> V_21 = F_11 ;
break;
#endif
default:
V_10 -> F_3 = F_28 ;
V_10 -> F_5 = F_29 ;
break;
}
V_6 -> V_28 = V_10 -> V_22 ;
V_10 -> V_29 = V_30 ;
}
static void
F_34 ( struct V_1 * V_10 , int V_11 , int V_9 )
{
switch ( V_10 -> V_22 ) {
case V_24 :
case V_25 :
case V_27 :
V_10 -> F_5 ( V_10 , V_11 , V_9 ) ;
V_10 -> F_3 ( V_10 , V_31 ) ;
break;
default:
V_10 -> F_5 ( V_10 , V_11 , V_9 ) ;
}
}
static void F_35 ( struct V_5 * V_6 , int V_11 , int V_9 )
{
F_5 ( V_6 , V_32 , V_11 ) ;
F_5 ( V_6 , V_33 , V_9 ) ;
}
static unsigned int F_36 ( struct V_5 * V_6 , int V_11 )
{
unsigned int V_9 ;
F_35 ( V_6 , V_34 , V_6 -> V_35 | V_36 ) ;
F_5 ( V_6 , V_32 , V_11 ) ;
V_9 = F_3 ( V_6 , V_33 ) ;
F_35 ( V_6 , V_34 , V_6 -> V_35 ) ;
return V_9 ;
}
static void F_37 ( struct V_5 * V_10 )
{
if ( V_10 -> V_37 & V_38 ) {
F_5 ( V_10 , V_39 , V_40 ) ;
F_5 ( V_10 , V_39 , V_40 |
V_41 | V_42 ) ;
F_5 ( V_10 , V_39 , 0 ) ;
}
}
void F_38 ( struct V_5 * V_10 )
{
unsigned char V_43 ;
F_37 ( V_10 ) ;
V_43 = V_44 [ V_10 -> V_2 . type ] . V_43 ;
F_5 ( V_10 , V_39 , V_43 ) ;
}
static void F_39 ( struct V_5 * V_10 , int V_45 )
{
if ( ( V_10 -> V_2 . type == V_46 ) ||
( V_10 -> V_2 . type == V_47 ) ) {
F_5 ( V_10 , V_48 , 0xff ) ;
return;
}
if ( V_10 -> V_37 & V_49 ) {
if ( V_10 -> V_37 & V_50 ) {
F_5 ( V_10 , V_31 , V_51 ) ;
F_5 ( V_10 , V_52 , V_53 ) ;
F_5 ( V_10 , V_31 , 0 ) ;
}
F_5 ( V_10 , V_54 , V_45 ? V_55 : 0 ) ;
if ( V_10 -> V_37 & V_50 ) {
F_5 ( V_10 , V_31 , V_51 ) ;
F_5 ( V_10 , V_52 , 0 ) ;
F_5 ( V_10 , V_31 , 0 ) ;
}
}
}
static int F_40 ( struct V_5 * V_6 )
{
unsigned char V_56 ;
int V_57 ;
V_56 = F_3 ( V_6 , V_58 ) ;
V_57 = V_56 & V_59 ;
if ( ! V_57 ) {
F_5 ( V_6 , V_58 , V_56 | V_59 ) ;
V_56 = F_3 ( V_6 , V_58 ) ;
V_57 = V_56 & V_59 ;
}
if ( V_57 )
V_6 -> V_2 . V_60 = V_61 * 16 ;
return V_57 ;
}
static void F_41 ( struct V_5 * V_6 )
{
if ( V_6 -> V_2 . type == V_62 ) {
if ( V_6 -> V_2 . V_60 != V_61 * 16 ) {
F_42 ( & V_6 -> V_2 . V_63 ) ;
F_40 ( V_6 ) ;
F_43 ( & V_6 -> V_2 . V_63 ) ;
}
if ( V_6 -> V_2 . V_60 == V_61 * 16 )
F_5 ( V_6 , V_64 , 0 ) ;
}
}
static void F_44 ( struct V_5 * V_6 )
{
unsigned char V_56 ;
int V_57 ;
if ( V_6 -> V_2 . type == V_62 &&
V_6 -> V_2 . V_60 == V_61 * 16 ) {
F_42 ( & V_6 -> V_2 . V_63 ) ;
V_56 = F_3 ( V_6 , V_58 ) ;
V_57 = ! ( V_56 & V_59 ) ;
if ( ! V_57 ) {
F_5 ( V_6 , V_58 , V_56 & ~ V_59 ) ;
V_56 = F_3 ( V_6 , V_58 ) ;
V_57 = ! ( V_56 & V_59 ) ;
}
if ( V_57 )
V_6 -> V_2 . V_60 = V_65 * 16 ;
F_43 ( & V_6 -> V_2 . V_63 ) ;
}
}
static int F_45 ( struct V_5 * V_6 )
{
unsigned char V_66 , V_67 , V_68 ;
unsigned short V_69 ;
int V_70 ;
V_68 = F_3 ( V_6 , V_31 ) ;
F_5 ( V_6 , V_31 , 0 ) ;
V_66 = F_3 ( V_6 , V_39 ) ;
V_67 = F_3 ( V_6 , V_71 ) ;
F_5 ( V_6 , V_39 , V_40 |
V_41 | V_42 ) ;
F_5 ( V_6 , V_71 , V_72 ) ;
F_5 ( V_6 , V_31 , V_73 ) ;
V_69 = F_46 ( V_6 ) ;
F_47 ( V_6 , 0x0001 ) ;
F_5 ( V_6 , V_31 , 0x03 ) ;
for ( V_70 = 0 ; V_70 < 256 ; V_70 ++ )
F_5 ( V_6 , V_74 , V_70 ) ;
F_48 ( 20 ) ;
for ( V_70 = 0 ; ( F_3 ( V_6 , V_75 ) & V_76 ) &&
( V_70 < 256 ) ; V_70 ++ )
F_3 ( V_6 , V_77 ) ;
F_5 ( V_6 , V_39 , V_66 ) ;
F_5 ( V_6 , V_71 , V_67 ) ;
F_5 ( V_6 , V_31 , V_73 ) ;
F_47 ( V_6 , V_69 ) ;
F_5 ( V_6 , V_31 , V_68 ) ;
return V_70 ;
}
static unsigned int F_49 ( struct V_5 * V_10 )
{
unsigned char V_78 , V_79 , V_68 ;
unsigned int V_80 ;
V_68 = F_3 ( V_10 , V_31 ) ;
F_5 ( V_10 , V_31 , V_73 ) ;
V_78 = F_3 ( V_10 , V_7 ) ;
V_79 = F_3 ( V_10 , V_8 ) ;
F_5 ( V_10 , V_7 , 0 ) ;
F_5 ( V_10 , V_8 , 0 ) ;
V_80 = F_3 ( V_10 , V_7 ) | F_3 ( V_10 , V_8 ) << 8 ;
F_5 ( V_10 , V_7 , V_78 ) ;
F_5 ( V_10 , V_8 , V_79 ) ;
F_5 ( V_10 , V_31 , V_68 ) ;
return V_80 ;
}
static void F_50 ( struct V_5 * V_6 )
{
unsigned int V_81 , V_82 , V_83 , V_84 ;
V_6 -> V_37 |= V_50 | V_49 ;
V_6 -> V_35 = 0 ;
F_5 ( V_6 , V_31 , V_51 ) ;
F_5 ( V_6 , V_52 , V_53 ) ;
F_5 ( V_6 , V_31 , 0x00 ) ;
V_81 = F_36 ( V_6 , V_85 ) ;
V_82 = F_36 ( V_6 , V_86 ) ;
V_83 = F_36 ( V_6 , V_87 ) ;
V_84 = F_36 ( V_6 , V_88 ) ;
F_51 ( L_1 , V_81 , V_82 , V_83 , V_84 ) ;
if ( V_81 == 0x16 && V_82 == 0xC9 &&
( V_83 == 0x50 || V_83 == 0x52 || V_83 == 0x54 ) ) {
V_6 -> V_2 . type = V_89 ;
if ( V_83 == 0x52 && V_84 == 0x01 )
V_6 -> V_90 |= V_91 ;
return;
}
V_81 = F_49 ( V_6 ) ;
F_51 ( L_2 , V_81 ) ;
V_82 = V_81 >> 8 ;
if ( V_82 == 0x10 || V_82 == 0x12 || V_82 == 0x14 ) {
V_6 -> V_2 . type = V_92 ;
return;
}
if ( F_45 ( V_6 ) == 64 )
V_6 -> V_2 . type = V_93 ;
else
V_6 -> V_2 . type = V_94 ;
}
static void F_52 ( struct V_5 * V_6 )
{
unsigned char V_95 , V_96 , V_97 ;
V_6 -> V_2 . type = V_98 ;
V_95 = F_3 ( V_6 , V_32 ) ;
F_5 ( V_6 , V_32 , 0xa5 ) ;
V_96 = F_3 ( V_6 , V_32 ) ;
F_5 ( V_6 , V_32 , 0x5a ) ;
V_97 = F_3 ( V_6 , V_32 ) ;
F_5 ( V_6 , V_32 , V_95 ) ;
if ( V_96 == 0xa5 && V_97 == 0x5a )
V_6 -> V_2 . type = V_99 ;
}
static int F_53 ( struct V_5 * V_6 )
{
if ( F_49 ( V_6 ) == 0x0201 && F_45 ( V_6 ) == 16 )
return 1 ;
return 0 ;
}
static inline int F_54 ( struct V_5 * V_6 )
{
unsigned char V_100 ;
V_100 = F_3 ( V_6 , 0x04 ) ;
#define F_55 ( T_1 ) ((x) & 0x30)
if ( F_55 ( V_100 ) == 0x10 ) {
return 0 ;
} else {
V_100 &= ~ 0xB0 ;
V_100 |= 0x10 ;
F_5 ( V_6 , 0x04 , V_100 ) ;
}
return 1 ;
}
static void F_56 ( struct V_5 * V_6 )
{
unsigned char V_96 , V_97 ;
unsigned int V_101 ;
V_6 -> V_2 . type = V_102 ;
V_6 -> V_37 |= V_38 ;
if ( V_6 -> V_2 . V_103 & V_104 ) {
V_96 = F_3 ( V_6 , V_105 ) ;
if ( V_96 == 0x82 || V_96 == 0x84 || V_96 == 0x88 ) {
F_51 ( L_3 ) ;
V_6 -> V_2 . type = V_46 ;
V_6 -> V_37 |= V_106 | V_50 |
V_49 ;
return;
}
}
F_5 ( V_6 , V_31 , V_73 ) ;
if ( F_3 ( V_6 , V_52 ) == 0 ) {
F_5 ( V_6 , V_52 , 0xA8 ) ;
if ( F_3 ( V_6 , V_52 ) != 0 ) {
F_51 ( L_4 ) ;
V_6 -> V_2 . type = V_107 ;
V_6 -> V_37 |= V_50 | V_49 ;
} else {
F_51 ( L_5 ) ;
}
F_5 ( V_6 , V_52 , 0 ) ;
return;
}
F_5 ( V_6 , V_31 , V_51 ) ;
if ( F_3 ( V_6 , V_52 ) == 0 && ! F_53 ( V_6 ) ) {
F_51 ( L_6 ) ;
F_50 ( V_6 ) ;
return;
}
F_5 ( V_6 , V_31 , 0 ) ;
V_96 = F_3 ( V_6 , V_71 ) ;
F_5 ( V_6 , V_31 , 0xE0 ) ;
V_97 = F_3 ( V_6 , 0x02 ) ;
if ( ! ( ( V_97 ^ V_96 ) & V_72 ) ) {
F_5 ( V_6 , V_31 , 0 ) ;
F_5 ( V_6 , V_71 , V_96 ^ V_72 ) ;
F_5 ( V_6 , V_31 , 0xE0 ) ;
V_97 = F_3 ( V_6 , 0x02 ) ;
F_5 ( V_6 , V_31 , 0 ) ;
F_5 ( V_6 , V_71 , V_96 ) ;
if ( ( V_97 ^ V_96 ) & V_72 ) {
unsigned short V_108 ;
F_5 ( V_6 , V_31 , 0xE0 ) ;
V_108 = F_46 ( V_6 ) ;
V_108 <<= 3 ;
if ( F_54 ( V_6 ) )
F_47 ( V_6 , V_108 ) ;
F_5 ( V_6 , V_31 , 0 ) ;
V_6 -> V_2 . V_60 = 921600 * 16 ;
V_6 -> V_2 . type = V_109 ;
V_6 -> V_37 |= V_110 ;
return;
}
}
F_5 ( V_6 , V_31 , 0 ) ;
F_5 ( V_6 , V_39 , V_40 | V_111 ) ;
V_96 = F_3 ( V_6 , V_112 ) >> 5 ;
F_5 ( V_6 , V_39 , V_40 ) ;
F_5 ( V_6 , V_31 , V_73 ) ;
F_5 ( V_6 , V_39 , V_40 | V_111 ) ;
V_97 = F_3 ( V_6 , V_112 ) >> 5 ;
F_5 ( V_6 , V_39 , V_40 ) ;
F_5 ( V_6 , V_31 , 0 ) ;
F_51 ( L_7 , V_96 , V_97 ) ;
if ( V_96 == 6 && V_97 == 7 ) {
V_6 -> V_2 . type = V_113 ;
V_6 -> V_37 |= V_106 | V_49 ;
return;
}
V_101 = F_3 ( V_6 , V_54 ) ;
F_5 ( V_6 , V_54 , V_101 & ~ V_114 ) ;
if ( ! ( F_3 ( V_6 , V_54 ) & V_114 ) ) {
F_5 ( V_6 , V_54 , V_101 | V_114 ) ;
if ( F_3 ( V_6 , V_54 ) & V_114 ) {
F_51 ( L_8 ) ;
V_6 -> V_2 . type = V_115 ;
V_6 -> V_37 |= V_116 | V_117 ;
return;
}
} else {
F_51 ( L_9 ) ;
}
F_5 ( V_6 , V_54 , V_101 ) ;
if ( V_6 -> V_2 . V_103 & V_104 ) {
F_51 ( L_10 ) ;
V_6 -> V_2 . type = V_47 ;
V_6 -> V_37 |= V_106 | V_50 |
V_49 ;
return;
}
if ( V_6 -> V_2 . type == V_102 && F_45 ( V_6 ) == 64 ) {
V_6 -> V_2 . type = V_118 ;
V_6 -> V_37 |= V_106 ;
}
}
static void F_57 ( struct V_5 * V_6 , unsigned int V_119 )
{
unsigned char V_96 , V_95 , V_120 , V_121 ;
unsigned char V_122 , V_123 ;
struct V_1 * V_2 = & V_6 -> V_2 ;
unsigned long V_103 ;
unsigned int V_124 ;
if ( ! V_2 -> V_19 && ! V_2 -> V_125 && ! V_2 -> V_14 )
return;
F_51 ( L_11 ,
F_1 ( V_2 ) , V_2 -> V_19 , V_2 -> V_14 ) ;
F_58 ( & V_2 -> V_63 , V_103 ) ;
V_6 -> V_37 = 0 ;
V_6 -> V_90 = 0 ;
if ( ! ( V_2 -> V_103 & V_126 ) ) {
V_95 = F_3 ( V_6 , V_54 ) ;
F_5 ( V_6 , V_54 , 0 ) ;
#ifdef F_59
F_19 ( 0xff , 0x080 ) ;
#endif
V_120 = F_3 ( V_6 , V_54 ) & 0x0f ;
F_5 ( V_6 , V_54 , 0x0F ) ;
#ifdef F_59
F_19 ( 0 , 0x080 ) ;
#endif
V_121 = F_3 ( V_6 , V_54 ) & 0x0f ;
F_5 ( V_6 , V_54 , V_95 ) ;
if ( V_120 != 0 || V_121 != 0x0F ) {
F_60 ( & V_2 -> V_63 , V_103 ) ;
F_51 ( L_12 ,
V_120 , V_121 ) ;
goto V_127;
}
}
V_123 = F_3 ( V_6 , V_71 ) ;
V_122 = F_3 ( V_6 , V_31 ) ;
if ( ! ( V_2 -> V_103 & V_128 ) ) {
F_5 ( V_6 , V_71 , V_72 | 0x0A ) ;
V_96 = F_3 ( V_6 , V_129 ) & 0xF0 ;
F_5 ( V_6 , V_71 , V_123 ) ;
if ( V_96 != 0x90 ) {
F_60 ( & V_2 -> V_63 , V_103 ) ;
F_51 ( L_13 ,
V_96 ) ;
goto V_127;
}
}
F_5 ( V_6 , V_31 , V_51 ) ;
F_5 ( V_6 , V_52 , 0 ) ;
F_5 ( V_6 , V_31 , 0 ) ;
F_5 ( V_6 , V_39 , V_40 ) ;
V_95 = F_3 ( V_6 , V_112 ) >> 6 ;
switch ( V_95 ) {
case 0 :
F_52 ( V_6 ) ;
break;
case 1 :
V_2 -> type = V_130 ;
break;
case 2 :
V_2 -> type = V_131 ;
break;
case 3 :
F_56 ( V_6 ) ;
break;
}
#ifdef F_61
if ( V_2 -> type == V_102 && V_119 & V_132 ) {
int V_133 ;
for ( V_133 = 0 ; V_133 < V_134 ; ++ V_133 ) {
if ( V_135 [ V_133 ] == V_2 -> V_19 && F_40 ( V_6 ) ) {
V_2 -> type = V_62 ;
break;
}
}
}
#endif
F_5 ( V_6 , V_31 , V_122 ) ;
V_2 -> V_136 = V_44 [ V_6 -> V_2 . type ] . V_137 ;
V_124 = V_6 -> V_37 ;
V_6 -> V_37 = V_44 [ V_2 -> type ] . V_103 ;
V_6 -> V_138 = V_44 [ V_2 -> type ] . V_138 ;
if ( V_2 -> type == V_130 )
goto V_139;
#ifdef F_61
if ( V_2 -> type == V_62 )
F_5 ( V_6 , V_64 , 0 ) ;
#endif
F_5 ( V_6 , V_71 , V_123 ) ;
F_37 ( V_6 ) ;
F_3 ( V_6 , V_77 ) ;
if ( V_6 -> V_37 & V_116 )
F_5 ( V_6 , V_54 , V_114 ) ;
else
F_5 ( V_6 , V_54 , 0 ) ;
V_139:
F_60 ( & V_2 -> V_63 , V_103 ) ;
if ( V_6 -> V_37 != V_124 ) {
F_62 ( V_140
L_14 ,
F_1 ( V_2 ) , V_124 ,
V_6 -> V_37 ) ;
}
V_127:
F_51 ( L_15 , V_95 ) ;
F_51 ( L_16 , V_44 [ V_2 -> type ] . V_141 ) ;
}
static void F_63 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = & V_6 -> V_2 ;
unsigned char V_123 , V_142 ;
unsigned char V_143 = 0 ;
unsigned int V_144 = 0 ;
unsigned long V_145 ;
int V_146 ;
if ( V_2 -> V_103 & V_147 ) {
V_144 = ( V_2 -> V_19 & 0xfe0 ) | 0x1f ;
V_143 = F_64 ( V_144 ) ;
F_65 ( 0x80 , V_144 ) ;
F_64 ( V_144 ) ;
}
F_66 ( F_67 () ) ;
V_123 = F_3 ( V_6 , V_71 ) ;
V_142 = F_3 ( V_6 , V_54 ) ;
F_5 ( V_6 , V_71 , V_148 | V_149 ) ;
V_145 = F_67 () ;
F_5 ( V_6 , V_71 , 0 ) ;
F_68 ( 10 ) ;
if ( V_2 -> V_103 & V_147 ) {
F_5 ( V_6 , V_71 ,
V_150 | V_151 ) ;
} else {
F_5 ( V_6 , V_71 ,
V_150 | V_151 | V_149 ) ;
}
F_5 ( V_6 , V_54 , 0x0f ) ;
F_3 ( V_6 , V_75 ) ;
F_3 ( V_6 , V_77 ) ;
F_3 ( V_6 , V_112 ) ;
F_3 ( V_6 , V_129 ) ;
F_5 ( V_6 , V_74 , 0xFF ) ;
F_68 ( 20 ) ;
V_146 = F_66 ( V_145 ) ;
F_5 ( V_6 , V_71 , V_123 ) ;
F_5 ( V_6 , V_54 , V_142 ) ;
if ( V_2 -> V_103 & V_147 )
F_65 ( V_143 , V_144 ) ;
V_2 -> V_146 = ( V_146 > 0 ) ? V_146 : 0 ;
}
static inline void F_69 ( struct V_5 * V_10 )
{
if ( V_10 -> V_152 & V_153 ) {
V_10 -> V_152 &= ~ V_153 ;
F_5 ( V_10 , V_54 , V_10 -> V_152 ) ;
}
}
static void F_70 ( struct V_1 * V_2 )
{
struct V_5 * V_6 =
F_31 ( V_2 , struct V_5 , V_2 ) ;
F_69 ( V_6 ) ;
if ( V_2 -> type == V_89 ) {
V_6 -> V_35 |= V_154 ;
F_35 ( V_6 , V_34 , V_6 -> V_35 ) ;
}
}
static void F_71 ( struct V_1 * V_2 )
{
struct V_5 * V_6 =
F_31 ( V_2 , struct V_5 , V_2 ) ;
if ( ! ( V_6 -> V_152 & V_153 ) ) {
V_6 -> V_152 |= V_153 ;
F_72 ( V_2 , V_54 , V_6 -> V_152 ) ;
if ( V_6 -> V_90 & V_155 ) {
unsigned char V_156 ;
V_156 = F_3 ( V_6 , V_75 ) ;
V_6 -> V_157 |= V_156 & V_158 ;
if ( ( V_2 -> type == V_159 ) ?
( V_156 & V_160 ) :
( V_156 & V_161 ) )
F_73 ( V_6 ) ;
}
}
if ( V_2 -> type == V_89 && V_6 -> V_35 & V_154 ) {
V_6 -> V_35 &= ~ V_154 ;
F_35 ( V_6 , V_34 , V_6 -> V_35 ) ;
}
}
static void F_74 ( struct V_1 * V_2 )
{
struct V_5 * V_6 =
F_31 ( V_2 , struct V_5 , V_2 ) ;
V_6 -> V_152 &= ~ V_162 ;
V_6 -> V_2 . V_163 &= ~ V_76 ;
F_72 ( V_2 , V_54 , V_6 -> V_152 ) ;
}
static void F_75 ( struct V_1 * V_2 )
{
struct V_5 * V_6 =
F_31 ( V_2 , struct V_5 , V_2 ) ;
if ( V_6 -> V_90 & V_164 )
return;
V_6 -> V_152 |= V_165 ;
F_72 ( V_2 , V_54 , V_6 -> V_152 ) ;
}
unsigned char
F_76 ( struct V_5 * V_6 , unsigned char V_156 )
{
struct V_1 * V_2 = & V_6 -> V_2 ;
struct V_166 * V_167 = V_2 -> V_168 -> V_2 . V_167 ;
unsigned char V_169 ;
int V_170 = 256 ;
char V_171 ;
do {
if ( F_77 ( V_156 & V_76 ) )
V_169 = F_3 ( V_6 , V_77 ) ;
else
V_169 = 0 ;
V_171 = V_172 ;
V_2 -> V_173 . V_174 ++ ;
V_156 |= V_6 -> V_157 ;
V_6 -> V_157 = 0 ;
if ( F_78 ( V_156 & V_175 ) ) {
if ( V_156 & V_176 ) {
V_156 &= ~ ( V_177 | V_178 ) ;
V_2 -> V_173 . V_179 ++ ;
if ( F_79 ( V_2 ) )
goto V_180;
} else if ( V_156 & V_178 )
V_2 -> V_173 . V_181 ++ ;
else if ( V_156 & V_177 )
V_2 -> V_173 . V_182 ++ ;
if ( V_156 & V_183 )
V_2 -> V_173 . V_184 ++ ;
V_156 &= V_2 -> V_163 ;
if ( V_156 & V_176 ) {
F_80 ( L_17 ) ;
V_171 = V_185 ;
} else if ( V_156 & V_178 )
V_171 = V_186 ;
else if ( V_156 & V_177 )
V_171 = V_187 ;
}
if ( F_81 ( V_2 , V_169 ) )
goto V_180;
F_82 ( V_2 , V_156 , V_183 , V_169 , V_171 ) ;
V_180:
V_156 = F_3 ( V_6 , V_75 ) ;
} while ( ( V_156 & ( V_76 | V_176 ) ) && ( V_170 -- > 0 ) );
F_83 ( & V_2 -> V_63 ) ;
F_84 ( V_167 ) ;
F_85 ( & V_2 -> V_63 ) ;
return V_156 ;
}
void F_73 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = & V_6 -> V_2 ;
struct V_188 * V_189 = & V_2 -> V_168 -> V_189 ;
int V_70 ;
if ( V_2 -> V_190 ) {
F_5 ( V_6 , V_74 , V_2 -> V_190 ) ;
V_2 -> V_173 . V_191 ++ ;
V_2 -> V_190 = 0 ;
return;
}
if ( F_86 ( V_2 ) ) {
F_70 ( V_2 ) ;
return;
}
if ( F_87 ( V_189 ) ) {
F_69 ( V_6 ) ;
return;
}
V_70 = V_6 -> V_138 ;
do {
F_5 ( V_6 , V_74 , V_189 -> V_192 [ V_189 -> V_193 ] ) ;
V_189 -> V_193 = ( V_189 -> V_193 + 1 ) & ( V_194 - 1 ) ;
V_2 -> V_173 . V_191 ++ ;
if ( F_87 ( V_189 ) )
break;
if ( V_6 -> V_37 & V_195 ) {
if ( ( F_88 ( V_2 , V_75 ) & V_196 ) !=
V_196 )
break;
}
} while ( -- V_70 > 0 );
if ( F_89 ( V_189 ) < V_197 )
F_90 ( V_2 ) ;
F_80 ( L_18 ) ;
if ( F_87 ( V_189 ) )
F_69 ( V_6 ) ;
}
unsigned int F_91 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = & V_6 -> V_2 ;
unsigned int V_100 = F_3 ( V_6 , V_129 ) ;
V_100 |= V_6 -> V_198 ;
V_6 -> V_198 = 0 ;
if ( V_100 & V_199 && V_6 -> V_152 & V_165 &&
V_2 -> V_168 != NULL ) {
if ( V_100 & V_200 )
V_2 -> V_173 . V_201 ++ ;
if ( V_100 & V_202 )
V_2 -> V_173 . V_203 ++ ;
if ( V_100 & V_204 )
F_92 ( V_2 , V_100 & V_205 ) ;
if ( V_100 & V_206 )
F_93 ( V_2 , V_100 & V_207 ) ;
F_94 ( & V_2 -> V_168 -> V_2 . V_208 ) ;
}
return V_100 ;
}
int F_95 ( struct V_1 * V_2 , unsigned int V_209 )
{
unsigned char V_100 ;
unsigned long V_103 ;
struct V_5 * V_6 =
F_31 ( V_2 , struct V_5 , V_2 ) ;
if ( V_209 & V_210 )
return 0 ;
F_58 ( & V_2 -> V_63 , V_103 ) ;
V_100 = F_88 ( V_2 , V_75 ) ;
F_80 ( L_19 , V_100 ) ;
if ( V_100 & ( V_76 | V_176 ) )
V_100 = F_76 ( V_6 , V_100 ) ;
F_91 ( V_6 ) ;
if ( V_100 & V_160 )
F_73 ( V_6 ) ;
F_60 ( & V_2 -> V_63 , V_103 ) ;
return 1 ;
}
static int V_30 ( struct V_1 * V_2 )
{
unsigned int V_209 = F_88 ( V_2 , V_112 ) ;
return F_95 ( V_2 , V_209 ) ;
}
static int F_96 ( struct V_1 * V_2 )
{
unsigned char V_211 , V_212 , V_213 , V_214 ;
unsigned int V_209 = F_88 ( V_2 , V_112 ) ;
int V_215 ;
V_215 = F_95 ( V_2 , V_209 ) ;
if ( ( V_2 -> type == V_46 ) ||
( V_2 -> type == V_47 ) ) {
V_211 = F_88 ( V_2 , 0x80 ) ;
V_212 = F_88 ( V_2 , 0x81 ) ;
V_213 = F_88 ( V_2 , 0x82 ) ;
V_214 = F_88 ( V_2 , 0x83 ) ;
}
return V_215 ;
}
static T_2 F_97 ( int V_146 , void * V_216 )
{
struct V_217 * V_133 = V_216 ;
struct V_218 * V_219 , * V_220 = NULL ;
int V_221 = 0 , V_222 = 0 ;
F_80 ( L_20 , V_146 ) ;
F_85 ( & V_133 -> V_63 ) ;
V_219 = V_133 -> V_223 ;
do {
struct V_5 * V_6 ;
struct V_1 * V_2 ;
V_6 = F_98 ( V_219 , struct V_5 , V_224 ) ;
V_2 = & V_6 -> V_2 ;
if ( V_2 -> V_29 ( V_2 ) ) {
V_222 = 1 ;
V_220 = NULL ;
} else if ( V_220 == NULL )
V_220 = V_219 ;
V_219 = V_219 -> V_225 ;
if ( V_219 == V_133 -> V_223 && V_221 ++ > V_226 ) {
F_99 ( V_227
L_21 , V_146 ) ;
break;
}
} while ( V_219 != V_220 );
F_83 ( & V_133 -> V_63 ) ;
F_80 ( L_22 ) ;
return F_100 ( V_222 ) ;
}
static void F_101 ( struct V_217 * V_133 , struct V_5 * V_6 )
{
F_42 ( & V_133 -> V_63 ) ;
if ( ! F_102 ( V_133 -> V_223 ) ) {
if ( V_133 -> V_223 == & V_6 -> V_224 )
V_133 -> V_223 = V_133 -> V_223 -> V_225 ;
F_103 ( & V_6 -> V_224 ) ;
} else {
F_104 ( V_133 -> V_223 != & V_6 -> V_224 ) ;
V_133 -> V_223 = NULL ;
}
F_43 ( & V_133 -> V_63 ) ;
if ( V_133 -> V_223 == NULL ) {
F_105 ( & V_133 -> V_228 ) ;
F_106 ( V_133 ) ;
}
}
static int F_107 ( struct V_5 * V_6 )
{
struct V_229 * V_230 ;
struct V_231 * V_232 ;
struct V_217 * V_133 ;
int V_215 , V_233 = V_6 -> V_2 . V_103 & V_234 ? V_235 : 0 ;
F_108 ( & V_236 ) ;
V_230 = & V_237 [ V_6 -> V_2 . V_146 % V_238 ] ;
F_109 (n, h) {
V_133 = F_110 ( V_232 , struct V_217 , V_228 ) ;
if ( V_133 -> V_146 == V_6 -> V_2 . V_146 )
break;
}
if ( V_232 == NULL ) {
V_133 = F_111 ( sizeof( struct V_217 ) , V_239 ) ;
if ( V_133 == NULL ) {
F_112 ( & V_236 ) ;
return - V_240 ;
}
F_113 ( & V_133 -> V_63 ) ;
V_133 -> V_146 = V_6 -> V_2 . V_146 ;
F_114 ( & V_133 -> V_228 , V_230 ) ;
}
F_112 ( & V_236 ) ;
F_42 ( & V_133 -> V_63 ) ;
if ( V_133 -> V_223 ) {
F_115 ( & V_6 -> V_224 , V_133 -> V_223 ) ;
F_43 ( & V_133 -> V_63 ) ;
V_215 = 0 ;
} else {
F_116 ( & V_6 -> V_224 ) ;
V_133 -> V_223 = & V_6 -> V_224 ;
F_43 ( & V_133 -> V_63 ) ;
V_233 |= V_6 -> V_2 . V_241 ;
V_215 = F_117 ( V_6 -> V_2 . V_146 , F_97 ,
V_233 , L_23 , V_133 ) ;
if ( V_215 < 0 )
F_101 ( V_133 , V_6 ) ;
}
return V_215 ;
}
static void F_118 ( struct V_5 * V_6 )
{
struct V_217 * V_133 ;
struct V_231 * V_232 ;
struct V_229 * V_230 ;
F_108 ( & V_236 ) ;
V_230 = & V_237 [ V_6 -> V_2 . V_146 % V_238 ] ;
F_109 (n, h) {
V_133 = F_110 ( V_232 , struct V_217 , V_228 ) ;
if ( V_133 -> V_146 == V_6 -> V_2 . V_146 )
break;
}
F_104 ( V_232 == NULL ) ;
F_104 ( V_133 -> V_223 == NULL ) ;
if ( F_102 ( V_133 -> V_223 ) )
F_119 ( V_6 -> V_2 . V_146 , V_133 ) ;
F_101 ( V_133 , V_6 ) ;
F_112 ( & V_236 ) ;
}
static void F_120 ( unsigned long V_242 )
{
struct V_5 * V_6 = (struct V_5 * ) V_242 ;
V_6 -> V_2 . V_29 ( & V_6 -> V_2 ) ;
F_121 ( & V_6 -> V_243 , V_244 + F_122 ( & V_6 -> V_2 ) ) ;
}
static void F_123 ( unsigned long V_242 )
{
struct V_5 * V_6 = (struct V_5 * ) V_242 ;
unsigned int V_209 , V_152 = 0 , V_156 ;
unsigned long V_103 ;
F_58 ( & V_6 -> V_2 . V_63 , V_103 ) ;
if ( V_6 -> V_2 . V_146 ) {
V_152 = F_3 ( V_6 , V_54 ) ;
F_5 ( V_6 , V_54 , 0 ) ;
}
V_209 = F_3 ( V_6 , V_112 ) ;
V_156 = F_3 ( V_6 , V_75 ) ;
V_6 -> V_157 |= V_156 & V_158 ;
if ( ( V_209 & V_210 ) && ( V_6 -> V_152 & V_153 ) &&
( ! F_87 ( & V_6 -> V_2 . V_168 -> V_189 ) || V_6 -> V_2 . V_190 ) &&
( V_156 & V_160 ) ) {
V_209 &= ~ ( V_245 | V_210 ) ;
V_209 |= V_246 ;
}
if ( ! ( V_209 & V_210 ) )
F_73 ( V_6 ) ;
if ( V_6 -> V_2 . V_146 )
F_5 ( V_6 , V_54 , V_152 ) ;
F_60 ( & V_6 -> V_2 . V_63 , V_103 ) ;
F_121 ( & V_6 -> V_243 ,
V_244 + F_122 ( & V_6 -> V_2 ) + V_247 / 5 ) ;
}
static unsigned int F_124 ( struct V_1 * V_2 )
{
struct V_5 * V_6 =
F_31 ( V_2 , struct V_5 , V_2 ) ;
unsigned long V_103 ;
unsigned int V_156 ;
F_58 ( & V_2 -> V_63 , V_103 ) ;
V_156 = F_88 ( V_2 , V_75 ) ;
V_6 -> V_157 |= V_156 & V_158 ;
F_60 ( & V_2 -> V_63 , V_103 ) ;
return ( V_156 & V_196 ) == V_196 ? V_248 : 0 ;
}
static unsigned int F_125 ( struct V_1 * V_2 )
{
struct V_5 * V_6 =
F_31 ( V_2 , struct V_5 , V_2 ) ;
unsigned int V_100 ;
unsigned int V_215 ;
V_100 = F_91 ( V_6 ) ;
V_215 = 0 ;
if ( V_100 & V_205 )
V_215 |= V_249 ;
if ( V_100 & V_250 )
V_215 |= V_251 ;
if ( V_100 & V_252 )
V_215 |= V_253 ;
if ( V_100 & V_207 )
V_215 |= V_254 ;
return V_215 ;
}
static void F_126 ( struct V_1 * V_2 , unsigned int V_255 )
{
struct V_5 * V_6 =
F_31 ( V_2 , struct V_5 , V_2 ) ;
unsigned char V_256 = 0 ;
if ( V_255 & V_257 )
V_256 |= V_151 ;
if ( V_255 & V_258 )
V_256 |= V_150 ;
if ( V_255 & V_259 )
V_256 |= V_148 ;
if ( V_255 & V_260 )
V_256 |= V_149 ;
if ( V_255 & V_261 )
V_256 |= V_72 ;
V_256 = ( V_256 & V_6 -> V_262 ) | V_6 -> V_263 | V_6 -> V_256 ;
F_72 ( V_2 , V_71 , V_256 ) ;
}
static void F_127 ( struct V_1 * V_2 , int V_264 )
{
struct V_5 * V_6 =
F_31 ( V_2 , struct V_5 , V_2 ) ;
unsigned long V_103 ;
F_58 ( & V_2 -> V_63 , V_103 ) ;
if ( V_264 == - 1 )
V_6 -> V_265 |= V_266 ;
else
V_6 -> V_265 &= ~ V_266 ;
F_72 ( V_2 , V_31 , V_6 -> V_265 ) ;
F_60 ( & V_2 -> V_63 , V_103 ) ;
}
static void F_128 ( struct V_5 * V_6 , int V_267 )
{
unsigned int V_100 , V_268 = 10000 ;
for (; ; ) {
V_100 = F_3 ( V_6 , V_75 ) ;
V_6 -> V_157 |= V_100 & V_158 ;
if ( ( V_100 & V_267 ) == V_267 )
break;
if ( -- V_268 == 0 )
break;
F_68 ( 1 ) ;
}
if ( V_6 -> V_2 . V_103 & V_269 ) {
unsigned int V_268 ;
for ( V_268 = 1000000 ; V_268 ; V_268 -- ) {
unsigned int V_270 = F_3 ( V_6 , V_129 ) ;
V_6 -> V_198 |= V_270 & V_271 ;
if ( V_270 & V_207 )
break;
F_68 ( 1 ) ;
F_129 () ;
}
}
}
static int F_130 ( struct V_1 * V_2 )
{
unsigned char V_156 = F_88 ( V_2 , V_75 ) ;
if ( ! ( V_156 & V_76 ) )
return V_272 ;
return F_88 ( V_2 , V_77 ) ;
}
static void F_131 ( struct V_1 * V_2 ,
unsigned char V_273 )
{
unsigned int V_152 ;
struct V_5 * V_6 =
F_31 ( V_2 , struct V_5 , V_2 ) ;
V_152 = F_88 ( V_2 , V_54 ) ;
if ( V_6 -> V_37 & V_116 )
F_72 ( V_2 , V_54 , V_114 ) ;
else
F_72 ( V_2 , V_54 , 0 ) ;
F_128 ( V_6 , V_196 ) ;
F_72 ( V_2 , V_74 , V_273 ) ;
if ( V_273 == 10 ) {
F_128 ( V_6 , V_196 ) ;
F_72 ( V_2 , V_74 , 13 ) ;
}
F_128 ( V_6 , V_196 ) ;
F_72 ( V_2 , V_54 , V_152 ) ;
}
static int F_132 ( struct V_1 * V_2 )
{
struct V_5 * V_6 =
F_31 ( V_2 , struct V_5 , V_2 ) ;
unsigned long V_103 ;
unsigned char V_156 , V_209 ;
int V_274 ;
if ( V_2 -> type == V_275 )
return - V_276 ;
V_2 -> V_136 = V_44 [ V_6 -> V_2 . type ] . V_137 ;
V_6 -> V_138 = V_44 [ V_6 -> V_2 . type ] . V_138 ;
V_6 -> V_37 = V_44 [ V_6 -> V_2 . type ] . V_103 ;
V_6 -> V_256 = 0 ;
if ( V_2 -> V_22 != V_6 -> V_28 )
F_30 ( V_2 ) ;
if ( V_2 -> type == V_89 ) {
V_6 -> V_35 = 0 ;
F_72 ( V_2 , V_31 , V_51 ) ;
F_72 ( V_2 , V_52 , V_53 ) ;
F_72 ( V_2 , V_54 , 0 ) ;
F_72 ( V_2 , V_31 , 0 ) ;
F_35 ( V_6 , V_277 , 0 ) ;
F_72 ( V_2 , V_31 , V_51 ) ;
F_72 ( V_2 , V_52 , V_53 ) ;
F_72 ( V_2 , V_31 , 0 ) ;
}
#ifdef F_61
F_41 ( V_6 ) ;
#endif
F_37 ( V_6 ) ;
F_88 ( V_2 , V_75 ) ;
F_88 ( V_2 , V_77 ) ;
F_88 ( V_2 , V_112 ) ;
F_88 ( V_2 , V_129 ) ;
if ( ! ( V_2 -> V_103 & V_126 ) &&
( F_88 ( V_2 , V_75 ) == 0xff ) ) {
F_99 ( V_278 L_24 ,
F_1 ( V_2 ) ) ;
return - V_276 ;
}
if ( V_2 -> type == V_92 ) {
unsigned char V_279 ;
F_5 ( V_6 , V_31 , V_51 ) ;
V_279 = F_3 ( V_6 , V_280 ) & ~ ( V_281 | V_282 ) ;
F_72 ( V_2 , V_280 ,
V_279 | V_283 | V_281 ) ;
F_72 ( V_2 , V_284 , V_285 ) ;
F_72 ( V_2 , V_280 ,
V_279 | V_283 | V_282 ) ;
F_72 ( V_2 , V_284 , V_285 ) ;
F_72 ( V_2 , V_31 , 0 ) ;
}
if ( V_2 -> V_146 ) {
unsigned char V_286 ;
F_58 ( & V_2 -> V_63 , V_103 ) ;
if ( V_6 -> V_2 . V_241 & V_235 )
F_133 ( V_2 -> V_146 ) ;
F_128 ( V_6 , V_160 ) ;
F_34 ( V_2 , V_54 , V_153 ) ;
F_68 ( 1 ) ;
V_286 = F_88 ( V_2 , V_112 ) ;
F_72 ( V_2 , V_54 , 0 ) ;
F_34 ( V_2 , V_54 , V_153 ) ;
F_68 ( 1 ) ;
V_209 = F_88 ( V_2 , V_112 ) ;
F_72 ( V_2 , V_54 , 0 ) ;
if ( V_2 -> V_241 & V_235 )
F_134 ( V_2 -> V_146 ) ;
F_60 ( & V_2 -> V_63 , V_103 ) ;
if ( ( ! ( V_286 & V_210 ) && ( V_209 & V_210 ) ) ||
V_6 -> V_2 . V_103 & V_287 ) {
V_6 -> V_90 |= V_288 ;
F_135 ( L_25 ,
F_1 ( V_2 ) ) ;
}
}
if ( V_6 -> V_90 & V_288 ) {
V_6 -> V_243 . V_289 = F_123 ;
V_6 -> V_243 . V_242 = ( unsigned long ) V_6 ;
F_121 ( & V_6 -> V_243 , V_244 +
F_122 ( V_2 ) + V_247 / 5 ) ;
}
if ( ! V_2 -> V_146 ) {
V_6 -> V_243 . V_242 = ( unsigned long ) V_6 ;
F_121 ( & V_6 -> V_243 , V_244 + F_122 ( V_2 ) ) ;
} else {
V_274 = F_107 ( V_6 ) ;
if ( V_274 )
return V_274 ;
}
F_72 ( V_2 , V_31 , V_290 ) ;
F_58 ( & V_2 -> V_63 , V_103 ) ;
if ( V_6 -> V_2 . V_103 & V_147 ) {
if ( ! V_6 -> V_2 . V_146 )
V_6 -> V_2 . V_255 |= V_259 ;
} else
if ( V_2 -> V_146 )
V_6 -> V_2 . V_255 |= V_260 ;
F_126 ( V_2 , V_2 -> V_255 ) ;
if ( V_291 || V_6 -> V_2 . V_103 & V_292 )
goto V_293;
F_72 ( V_2 , V_54 , V_153 ) ;
V_156 = F_88 ( V_2 , V_75 ) ;
V_209 = F_88 ( V_2 , V_112 ) ;
F_72 ( V_2 , V_54 , 0 ) ;
if ( V_156 & V_161 && V_209 & V_210 ) {
if ( ! ( V_6 -> V_90 & V_155 ) ) {
V_6 -> V_90 |= V_155 ;
F_135 ( L_26 ,
F_1 ( V_2 ) ) ;
}
} else {
V_6 -> V_90 &= ~ V_155 ;
}
V_293:
F_60 ( & V_2 -> V_63 , V_103 ) ;
F_88 ( V_2 , V_75 ) ;
F_88 ( V_2 , V_77 ) ;
F_88 ( V_2 , V_112 ) ;
F_88 ( V_2 , V_129 ) ;
V_6 -> V_157 = 0 ;
V_6 -> V_198 = 0 ;
V_6 -> V_152 = V_162 | V_294 ;
F_72 ( V_2 , V_54 , V_6 -> V_152 ) ;
if ( V_2 -> V_103 & V_147 ) {
unsigned int V_295 ;
V_295 = ( V_2 -> V_19 & 0xfe0 ) | 0x01f ;
F_65 ( 0x80 , V_295 ) ;
F_64 ( V_295 ) ;
}
return 0 ;
}
static void F_136 ( struct V_1 * V_2 )
{
struct V_5 * V_6 =
F_31 ( V_2 , struct V_5 , V_2 ) ;
unsigned long V_103 ;
V_6 -> V_152 = 0 ;
F_72 ( V_2 , V_54 , 0 ) ;
F_58 ( & V_2 -> V_63 , V_103 ) ;
if ( V_2 -> V_103 & V_147 ) {
F_20 ( ( V_2 -> V_19 & 0xfe0 ) | 0x1f ) ;
V_2 -> V_255 |= V_259 ;
} else
V_2 -> V_255 &= ~ V_260 ;
F_126 ( V_2 , V_2 -> V_255 ) ;
F_60 ( & V_2 -> V_63 , V_103 ) ;
F_72 ( V_2 , V_31 ,
F_88 ( V_2 , V_31 ) & ~ V_266 ) ;
F_37 ( V_6 ) ;
#ifdef F_61
F_44 ( V_6 ) ;
#endif
F_88 ( V_2 , V_77 ) ;
F_137 ( & V_6 -> V_243 ) ;
V_6 -> V_243 . V_289 = F_120 ;
if ( V_2 -> V_146 )
F_118 ( V_6 ) ;
}
static unsigned int F_138 ( struct V_1 * V_2 , unsigned int V_296 )
{
unsigned int V_108 ;
if ( ( V_2 -> V_103 & V_297 ) &&
V_296 == ( V_2 -> V_60 / 4 ) )
V_108 = 0x8001 ;
else if ( ( V_2 -> V_103 & V_297 ) &&
V_296 == ( V_2 -> V_60 / 8 ) )
V_108 = 0x8002 ;
else
V_108 = F_139 ( V_2 , V_296 ) ;
return V_108 ;
}
void
F_140 ( struct V_1 * V_2 , struct V_298 * V_299 ,
struct V_298 * V_300 )
{
struct V_5 * V_6 =
F_31 ( V_2 , struct V_5 , V_2 ) ;
unsigned char V_301 , V_43 = 0 ;
unsigned long V_103 ;
unsigned int V_296 , V_108 ;
int V_302 = 0 ;
switch ( V_299 -> V_303 & V_304 ) {
case V_305 :
V_301 = V_306 ;
break;
case V_307 :
V_301 = V_308 ;
break;
case V_309 :
V_301 = V_310 ;
break;
default:
case V_311 :
V_301 = V_290 ;
break;
}
if ( V_299 -> V_303 & V_312 )
V_301 |= V_313 ;
if ( V_299 -> V_303 & V_314 ) {
V_301 |= V_315 ;
if ( V_6 -> V_90 & V_316 )
V_302 = 1 ;
}
if ( ! ( V_299 -> V_303 & V_317 ) )
V_301 |= V_318 ;
#ifdef F_141
if ( V_299 -> V_303 & F_141 )
V_301 |= V_319 ;
#endif
V_296 = F_142 ( V_2 , V_299 , V_300 ,
V_2 -> V_60 / 16 / 0xffff ,
V_2 -> V_60 / 16 ) ;
V_108 = F_138 ( V_2 , V_296 ) ;
if ( V_6 -> V_90 & V_91 && ( V_108 & 0xff ) == 0 )
V_108 ++ ;
if ( V_6 -> V_37 & V_38 && V_2 -> V_136 > 1 ) {
V_43 = V_44 [ V_2 -> type ] . V_43 ;
if ( V_296 < 2400 || V_302 ) {
V_43 &= ~ V_320 ;
V_43 |= V_321 ;
}
}
if ( V_6 -> V_37 & V_106 && V_2 -> V_136 >= 32 ) {
V_6 -> V_256 &= ~ V_322 ;
if ( V_299 -> V_303 & V_323 )
V_6 -> V_256 |= V_322 ;
}
F_58 ( & V_2 -> V_63 , V_103 ) ;
F_143 ( V_2 , V_299 -> V_303 , V_296 ) ;
V_2 -> V_163 = V_183 | V_160 | V_76 ;
if ( V_299 -> V_324 & V_325 )
V_2 -> V_163 |= V_177 | V_178 ;
if ( V_299 -> V_324 & ( V_326 | V_327 ) )
V_2 -> V_163 |= V_176 ;
V_2 -> V_328 = 0 ;
if ( V_299 -> V_324 & V_329 )
V_2 -> V_328 |= V_178 | V_177 ;
if ( V_299 -> V_324 & V_330 ) {
V_2 -> V_328 |= V_176 ;
if ( V_299 -> V_324 & V_329 )
V_2 -> V_328 |= V_183 ;
}
if ( ( V_299 -> V_303 & V_331 ) == 0 )
V_2 -> V_328 |= V_76 ;
V_6 -> V_152 &= ~ V_165 ;
if ( ! ( V_6 -> V_90 & V_164 ) &&
F_144 ( & V_6 -> V_2 , V_299 -> V_303 ) )
V_6 -> V_152 |= V_165 ;
if ( V_6 -> V_37 & V_116 )
V_6 -> V_152 |= V_114 ;
if ( V_6 -> V_37 & V_117 )
V_6 -> V_152 |= V_332 ;
F_72 ( V_2 , V_54 , V_6 -> V_152 ) ;
if ( V_6 -> V_37 & V_50 ) {
unsigned char V_333 = 0 ;
if ( V_299 -> V_303 & V_323 )
V_333 |= V_334 ;
F_72 ( V_2 , V_31 , V_51 ) ;
if ( V_2 -> V_103 & V_104 )
F_72 ( V_2 , V_335 , V_333 ) ;
else
F_72 ( V_2 , V_52 , V_333 ) ;
}
if ( F_145 ( V_6 ) ) {
if ( V_296 == 115200 ) {
V_108 = 1 ;
F_72 ( V_2 , V_336 , 1 ) ;
} else
F_72 ( V_2 , V_336 , 0 ) ;
}
if ( V_6 -> V_37 & V_110 )
F_72 ( V_2 , V_31 , 0xe0 ) ;
else
F_72 ( V_2 , V_31 , V_301 | V_337 ) ;
F_47 ( V_6 , V_108 ) ;
if ( V_2 -> type == V_113 )
F_72 ( V_2 , V_39 , V_43 ) ;
F_72 ( V_2 , V_31 , V_301 ) ;
V_6 -> V_265 = V_301 ;
if ( V_2 -> type != V_113 ) {
if ( V_43 & V_40 )
F_72 ( V_2 , V_39 , V_40 ) ;
F_72 ( V_2 , V_39 , V_43 ) ;
}
F_126 ( V_2 , V_2 -> V_255 ) ;
F_60 ( & V_2 -> V_63 , V_103 ) ;
if ( F_146 ( V_299 ) )
F_147 ( V_299 , V_296 , V_296 ) ;
}
static void
F_148 ( struct V_1 * V_2 , struct V_298 * V_299 ,
struct V_298 * V_300 )
{
if ( V_2 -> V_338 )
V_2 -> V_338 ( V_2 , V_299 , V_300 ) ;
else
F_140 ( V_2 , V_299 , V_300 ) ;
}
static void
F_149 ( struct V_1 * V_2 , int V_339 )
{
if ( V_339 == V_340 ) {
V_2 -> V_103 |= V_341 ;
F_75 ( V_2 ) ;
} else
V_2 -> V_103 &= ~ V_341 ;
}
void F_150 ( struct V_1 * V_2 , unsigned int V_168 ,
unsigned int V_342 )
{
struct V_5 * V_10 =
F_31 ( V_2 , struct V_5 , V_2 ) ;
F_39 ( V_10 , V_168 != 0 ) ;
}
static void
F_151 ( struct V_1 * V_2 , unsigned int V_168 ,
unsigned int V_342 )
{
if ( V_2 -> V_343 )
V_2 -> V_343 ( V_2 , V_168 , V_342 ) ;
else
F_150 ( V_2 , V_168 , V_342 ) ;
}
static unsigned int F_152 ( struct V_5 * V_344 )
{
if ( V_344 -> V_2 . V_22 == V_27 )
return 0x1000 ;
if ( F_153 ( V_344 ) )
return 0x16 << V_344 -> V_2 . V_13 ;
return 8 << V_344 -> V_2 . V_13 ;
}
static int F_154 ( struct V_5 * V_6 )
{
unsigned int V_345 = F_152 ( V_6 ) ;
struct V_1 * V_2 = & V_6 -> V_2 ;
int V_215 = 0 ;
switch ( V_2 -> V_22 ) {
case V_27 :
case V_346 :
case V_25 :
case V_24 :
if ( ! V_2 -> V_125 )
break;
if ( ! F_155 ( V_2 -> V_125 , V_345 , L_23 ) ) {
V_215 = - V_347 ;
break;
}
if ( V_2 -> V_103 & V_348 ) {
V_2 -> V_14 = F_156 ( V_2 -> V_125 , V_345 ) ;
if ( ! V_2 -> V_14 ) {
F_157 ( V_2 -> V_125 , V_345 ) ;
V_215 = - V_240 ;
}
}
break;
case V_23 :
case V_349 :
if ( ! F_158 ( V_2 -> V_19 , V_345 , L_23 ) )
V_215 = - V_347 ;
break;
}
return V_215 ;
}
static void F_159 ( struct V_5 * V_6 )
{
unsigned int V_345 = F_152 ( V_6 ) ;
struct V_1 * V_2 = & V_6 -> V_2 ;
switch ( V_2 -> V_22 ) {
case V_27 :
case V_346 :
case V_25 :
case V_24 :
if ( ! V_2 -> V_125 )
break;
if ( V_2 -> V_103 & V_348 ) {
F_160 ( V_2 -> V_14 ) ;
V_2 -> V_14 = NULL ;
}
F_157 ( V_2 -> V_125 , V_345 ) ;
break;
case V_23 :
case V_349 :
F_161 ( V_2 -> V_19 , V_345 ) ;
break;
}
}
static int F_162 ( struct V_5 * V_6 )
{
unsigned long V_350 = V_351 << V_6 -> V_2 . V_13 ;
unsigned int V_345 = 8 << V_6 -> V_2 . V_13 ;
struct V_1 * V_2 = & V_6 -> V_2 ;
int V_215 = - V_352 ;
switch ( V_2 -> V_22 ) {
case V_23 :
case V_349 :
V_350 += V_2 -> V_19 ;
if ( F_158 ( V_350 , V_345 , L_27 ) )
V_215 = 0 ;
else
V_215 = - V_347 ;
break;
}
return V_215 ;
}
static void F_163 ( struct V_5 * V_6 )
{
unsigned long V_11 = V_351 << V_6 -> V_2 . V_13 ;
unsigned int V_345 = 8 << V_6 -> V_2 . V_13 ;
struct V_1 * V_2 = & V_6 -> V_2 ;
switch ( V_2 -> V_22 ) {
case V_23 :
case V_349 :
F_161 ( V_2 -> V_19 + V_11 , V_345 ) ;
break;
}
}
static void F_164 ( struct V_1 * V_2 )
{
struct V_5 * V_6 =
F_31 ( V_2 , struct V_5 , V_2 ) ;
F_159 ( V_6 ) ;
if ( V_2 -> type == V_62 )
F_163 ( V_6 ) ;
}
static int F_165 ( struct V_1 * V_2 )
{
struct V_5 * V_6 =
F_31 ( V_2 , struct V_5 , V_2 ) ;
int V_215 ;
if ( V_2 -> type == V_275 )
return - V_276 ;
V_215 = F_154 ( V_6 ) ;
if ( V_215 == 0 && V_2 -> type == V_62 ) {
V_215 = F_162 ( V_6 ) ;
if ( V_215 < 0 )
F_159 ( V_6 ) ;
}
return V_215 ;
}
static void F_166 ( struct V_1 * V_2 , int V_103 )
{
struct V_5 * V_6 =
F_31 ( V_2 , struct V_5 , V_2 ) ;
int V_119 = V_353 ;
int V_215 ;
if ( V_2 -> type == V_275 )
return;
V_215 = F_154 ( V_6 ) ;
if ( V_215 < 0 )
return;
V_215 = F_162 ( V_6 ) ;
if ( V_215 < 0 )
V_119 &= ~ V_132 ;
if ( V_2 -> V_22 != V_6 -> V_28 )
F_30 ( V_2 ) ;
if ( V_103 & V_354 )
F_57 ( V_6 , V_119 ) ;
if ( V_2 -> type == V_102 && V_2 -> V_22 == V_27 )
V_6 -> V_90 |= V_164 ;
if ( V_2 -> type != V_130 && V_103 & V_355 )
F_63 ( V_6 ) ;
if ( V_2 -> type != V_62 && V_119 & V_132 )
F_163 ( V_6 ) ;
if ( V_2 -> type == V_130 )
F_159 ( V_6 ) ;
if ( ( V_2 -> type == V_46 ) ||
( V_2 -> type == V_47 ) )
V_2 -> V_29 = F_96 ;
}
static int
F_167 ( struct V_1 * V_2 , struct V_356 * V_357 )
{
if ( V_357 -> V_146 >= V_358 || V_357 -> V_146 < 0 ||
V_357 -> V_359 < 9600 || V_357 -> type < V_130 ||
V_357 -> type >= F_168 ( V_44 ) || V_357 -> type == V_360 ||
V_357 -> type == V_361 )
return - V_352 ;
return 0 ;
}
static const char *
F_169 ( struct V_1 * V_2 )
{
int type = V_2 -> type ;
if ( type >= F_168 ( V_44 ) )
type = 0 ;
return V_44 [ type ] . V_141 ;
}
void F_170 (
void (* F_171)( int V_2 , struct V_1 * V_6 , unsigned short * V_37 ) )
{
V_362 = F_171 ;
}
static void T_3 F_172 ( void )
{
struct V_5 * V_6 ;
static int V_363 = 1 ;
int V_133 , V_364 = 0 ;
if ( ! V_363 )
return;
V_363 = 0 ;
if ( V_365 > V_366 )
V_365 = V_366 ;
for ( V_133 = 0 ; V_133 < V_365 ; V_133 ++ ) {
struct V_5 * V_6 = & V_367 [ V_133 ] ;
struct V_1 * V_2 = & V_6 -> V_2 ;
V_2 -> line = V_133 ;
F_113 ( & V_2 -> V_63 ) ;
F_173 ( & V_6 -> V_243 ) ;
V_6 -> V_243 . V_289 = F_120 ;
V_6 -> V_28 = 0xFF ;
V_6 -> V_262 = ~ V_368 ;
V_6 -> V_263 = V_368 ;
V_2 -> V_369 = & V_370 ;
}
if ( V_371 )
V_364 = V_235 ;
for ( V_133 = 0 , V_6 = V_367 ;
V_133 < F_168 ( V_372 ) && V_133 < V_365 ;
V_133 ++ , V_6 ++ ) {
struct V_1 * V_2 = & V_6 -> V_2 ;
V_2 -> V_19 = V_372 [ V_133 ] . V_2 ;
V_2 -> V_146 = F_174 ( V_372 [ V_133 ] . V_146 ) ;
V_2 -> V_241 = V_372 [ V_133 ] . V_241 ;
V_2 -> V_60 = V_372 [ V_133 ] . V_359 * 16 ;
V_2 -> V_103 = V_372 [ V_133 ] . V_103 ;
V_2 -> V_18 = V_372 [ V_133 ] . V_18 ;
V_2 -> V_14 = V_372 [ V_133 ] . V_373 ;
V_2 -> V_22 = V_372 [ V_133 ] . V_374 ;
V_2 -> V_13 = V_372 [ V_133 ] . V_375 ;
F_30 ( V_2 ) ;
V_2 -> V_241 |= V_364 ;
if ( V_362 != NULL )
V_362 ( V_133 , & V_6 -> V_2 , & V_6 -> V_37 ) ;
}
}
static void
F_175 ( struct V_5 * V_6 , unsigned int type )
{
V_6 -> V_2 . type = type ;
V_6 -> V_2 . V_136 = V_44 [ type ] . V_137 ;
V_6 -> V_37 = V_44 [ type ] . V_103 ;
V_6 -> V_138 = V_44 [ type ] . V_138 ;
}
static void T_3
F_176 ( struct V_376 * V_377 , struct V_378 * V_379 )
{
int V_133 ;
for ( V_133 = 0 ; V_133 < V_365 ; V_133 ++ ) {
struct V_5 * V_6 = & V_367 [ V_133 ] ;
if ( V_6 -> V_2 . V_379 )
continue;
V_6 -> V_2 . V_379 = V_379 ;
if ( V_6 -> V_2 . V_103 & V_380 )
F_175 ( V_6 , V_6 -> V_2 . type ) ;
F_177 ( V_377 , & V_6 -> V_2 ) ;
}
}
static void F_178 ( struct V_1 * V_2 , int V_169 )
{
struct V_5 * V_6 =
F_31 ( V_2 , struct V_5 , V_2 ) ;
F_128 ( V_6 , V_160 ) ;
F_72 ( V_2 , V_74 , V_169 ) ;
}
static void
F_179 ( struct V_381 * V_382 , const char * V_383 , unsigned int V_70 )
{
struct V_5 * V_6 = & V_367 [ V_382 -> V_384 ] ;
struct V_1 * V_2 = & V_6 -> V_2 ;
unsigned long V_103 ;
unsigned int V_152 ;
int V_385 = 1 ;
F_129 () ;
F_180 ( V_103 ) ;
if ( V_2 -> V_386 ) {
V_385 = 0 ;
} else if ( V_387 ) {
V_385 = F_181 ( & V_2 -> V_63 ) ;
} else
F_85 ( & V_2 -> V_63 ) ;
V_152 = F_88 ( V_2 , V_54 ) ;
if ( V_6 -> V_37 & V_116 )
F_72 ( V_2 , V_54 , V_114 ) ;
else
F_72 ( V_2 , V_54 , 0 ) ;
F_182 ( V_2 , V_383 , V_70 , F_178 ) ;
F_128 ( V_6 , V_196 ) ;
F_72 ( V_2 , V_54 , V_152 ) ;
if ( V_6 -> V_198 )
F_91 ( V_6 ) ;
if ( V_385 )
F_83 ( & V_2 -> V_63 ) ;
F_183 ( V_103 ) ;
}
static int T_3 F_184 ( struct V_381 * V_382 , char * V_388 )
{
struct V_1 * V_2 ;
int V_296 = 9600 ;
int V_267 = 8 ;
int V_181 = 'n' ;
int V_389 = 'n' ;
if ( V_382 -> V_384 >= V_365 )
V_382 -> V_384 = 0 ;
V_2 = & V_367 [ V_382 -> V_384 ] . V_2 ;
if ( ! V_2 -> V_19 && ! V_2 -> V_14 )
return - V_276 ;
if ( V_388 )
F_185 ( V_388 , & V_296 , & V_181 , & V_267 , & V_389 ) ;
return F_186 ( V_2 , V_382 , V_296 , V_181 , V_267 , V_389 ) ;
}
static int F_187 ( void )
{
return F_188 () ;
}
static int T_3 F_189 ( void )
{
F_172 () ;
F_190 ( & V_390 ) ;
return 0 ;
}
int F_191 ( struct V_1 * V_10 )
{
int line ;
struct V_1 * V_2 ;
for ( line = 0 ; line < V_365 ; line ++ ) {
V_2 = & V_367 [ line ] . V_2 ;
if ( F_192 ( V_10 , V_2 ) )
return line ;
}
return - V_276 ;
}
int T_3 F_193 ( struct V_1 * V_2 )
{
struct V_1 * V_10 ;
if ( V_2 -> line >= F_168 ( V_367 ) )
return - V_276 ;
F_172 () ;
V_10 = & V_367 [ V_2 -> line ] . V_2 ;
V_10 -> V_19 = V_2 -> V_19 ;
V_10 -> V_14 = V_2 -> V_14 ;
V_10 -> V_146 = V_2 -> V_146 ;
V_10 -> V_241 = V_2 -> V_241 ;
V_10 -> V_60 = V_2 -> V_60 ;
V_10 -> V_136 = V_2 -> V_136 ;
V_10 -> V_13 = V_2 -> V_13 ;
V_10 -> V_22 = V_2 -> V_22 ;
V_10 -> V_103 = V_2 -> V_103 ;
V_10 -> V_125 = V_2 -> V_125 ;
V_10 -> V_391 = V_2 -> V_391 ;
V_10 -> type = V_2 -> type ;
V_10 -> line = V_2 -> line ;
F_30 ( V_10 ) ;
if ( V_2 -> F_3 )
V_10 -> F_3 = V_2 -> F_3 ;
if ( V_2 -> F_5 )
V_10 -> F_5 = V_2 -> F_5 ;
if ( V_2 -> V_29 )
V_10 -> V_29 = V_2 -> V_29 ;
else
V_10 -> V_29 = V_30 ;
return 0 ;
}
void F_194 ( int line )
{
F_195 ( & V_3 , & V_367 [ line ] . V_2 ) ;
}
void F_196 ( int line )
{
struct V_5 * V_6 = & V_367 [ line ] ;
struct V_1 * V_2 = & V_6 -> V_2 ;
if ( V_6 -> V_37 & V_110 ) {
F_72 ( V_2 , V_31 , 0xE0 ) ;
F_54 ( V_6 ) ;
F_72 ( V_2 , V_31 , 0 ) ;
V_2 -> V_60 = 921600 * 16 ;
}
F_197 ( & V_3 , V_2 ) ;
}
static int F_198 ( struct V_392 * V_379 )
{
struct V_393 * V_10 = V_379 -> V_379 . V_394 ;
struct V_5 V_395 ;
int V_215 , V_133 , V_364 = 0 ;
memset ( & V_395 , 0 , sizeof( V_395 ) ) ;
if ( V_371 )
V_364 = V_235 ;
for ( V_133 = 0 ; V_10 && V_10 -> V_103 != 0 ; V_10 ++ , V_133 ++ ) {
V_395 . V_2 . V_19 = V_10 -> V_19 ;
V_395 . V_2 . V_14 = V_10 -> V_14 ;
V_395 . V_2 . V_146 = V_10 -> V_146 ;
V_395 . V_2 . V_241 = V_10 -> V_241 ;
V_395 . V_2 . V_60 = V_10 -> V_60 ;
V_395 . V_2 . V_13 = V_10 -> V_13 ;
V_395 . V_2 . V_22 = V_10 -> V_22 ;
V_395 . V_2 . V_103 = V_10 -> V_103 ;
V_395 . V_2 . V_125 = V_10 -> V_125 ;
V_395 . V_2 . V_18 = V_10 -> V_18 ;
V_395 . V_2 . V_391 = V_10 -> V_391 ;
V_395 . V_2 . type = V_10 -> type ;
V_395 . V_2 . F_3 = V_10 -> F_3 ;
V_395 . V_2 . F_5 = V_10 -> F_5 ;
V_395 . V_2 . V_29 = V_10 -> V_29 ;
V_395 . V_2 . V_396 = V_10 -> V_396 ;
V_395 . V_2 . V_338 = V_10 -> V_338 ;
V_395 . V_2 . V_343 = V_10 -> V_343 ;
V_395 . V_2 . V_379 = & V_379 -> V_379 ;
V_395 . V_2 . V_241 |= V_364 ;
V_215 = F_199 ( & V_395 ) ;
if ( V_215 < 0 ) {
F_200 ( & V_379 -> V_379 , L_28
L_29 , V_133 ,
V_10 -> V_19 , ( unsigned long long ) V_10 -> V_125 ,
V_10 -> V_146 , V_215 ) ;
}
}
return 0 ;
}
static int F_201 ( struct V_392 * V_379 )
{
int V_133 ;
for ( V_133 = 0 ; V_133 < V_365 ; V_133 ++ ) {
struct V_5 * V_6 = & V_367 [ V_133 ] ;
if ( V_6 -> V_2 . V_379 == & V_379 -> V_379 )
F_202 ( V_133 ) ;
}
return 0 ;
}
static int F_203 ( struct V_392 * V_379 , T_4 V_168 )
{
int V_133 ;
for ( V_133 = 0 ; V_133 < V_366 ; V_133 ++ ) {
struct V_5 * V_6 = & V_367 [ V_133 ] ;
if ( V_6 -> V_2 . type != V_130 && V_6 -> V_2 . V_379 == & V_379 -> V_379 )
F_195 ( & V_3 , & V_6 -> V_2 ) ;
}
return 0 ;
}
static int F_204 ( struct V_392 * V_379 )
{
int V_133 ;
for ( V_133 = 0 ; V_133 < V_366 ; V_133 ++ ) {
struct V_5 * V_6 = & V_367 [ V_133 ] ;
if ( V_6 -> V_2 . type != V_130 && V_6 -> V_2 . V_379 == & V_379 -> V_379 )
F_196 ( V_133 ) ;
}
return 0 ;
}
static struct V_5 * F_205 ( struct V_1 * V_2 )
{
int V_133 ;
for ( V_133 = 0 ; V_133 < V_365 ; V_133 ++ )
if ( F_192 ( & V_367 [ V_133 ] . V_2 , V_2 ) )
return & V_367 [ V_133 ] ;
for ( V_133 = 0 ; V_133 < V_365 ; V_133 ++ )
if ( V_367 [ V_133 ] . V_2 . type == V_130 &&
V_367 [ V_133 ] . V_2 . V_19 == 0 )
return & V_367 [ V_133 ] ;
for ( V_133 = 0 ; V_133 < V_365 ; V_133 ++ )
if ( V_367 [ V_133 ] . V_2 . type == V_130 )
return & V_367 [ V_133 ] ;
return NULL ;
}
int F_199 ( struct V_5 * V_6 )
{
struct V_5 * V_395 ;
int V_215 = - V_397 ;
if ( V_6 -> V_2 . V_60 == 0 )
return - V_352 ;
F_108 ( & V_398 ) ;
V_395 = F_205 ( & V_6 -> V_2 ) ;
if ( V_395 && V_395 -> V_2 . type != V_275 ) {
if ( V_395 -> V_2 . V_379 )
F_206 ( & V_3 , & V_395 -> V_2 ) ;
V_395 -> V_2 . V_19 = V_6 -> V_2 . V_19 ;
V_395 -> V_2 . V_14 = V_6 -> V_2 . V_14 ;
V_395 -> V_2 . V_146 = V_6 -> V_2 . V_146 ;
V_395 -> V_2 . V_241 = V_6 -> V_2 . V_241 ;
V_395 -> V_2 . V_60 = V_6 -> V_2 . V_60 ;
V_395 -> V_2 . V_136 = V_6 -> V_2 . V_136 ;
V_395 -> V_2 . V_13 = V_6 -> V_2 . V_13 ;
V_395 -> V_2 . V_22 = V_6 -> V_2 . V_22 ;
V_395 -> V_2 . V_103 = V_6 -> V_2 . V_103 | V_399 ;
V_395 -> V_90 = V_6 -> V_90 ;
V_395 -> V_2 . V_125 = V_6 -> V_2 . V_125 ;
V_395 -> V_2 . V_391 = V_6 -> V_2 . V_391 ;
if ( V_6 -> V_2 . V_379 )
V_395 -> V_2 . V_379 = V_6 -> V_2 . V_379 ;
if ( V_6 -> V_2 . V_103 & V_380 )
F_175 ( V_395 , V_6 -> V_2 . type ) ;
F_30 ( & V_395 -> V_2 ) ;
if ( V_6 -> V_2 . F_3 )
V_395 -> V_2 . F_3 = V_6 -> V_2 . F_3 ;
if ( V_6 -> V_2 . F_5 )
V_395 -> V_2 . F_5 = V_6 -> V_2 . F_5 ;
if ( V_6 -> V_2 . V_29 )
V_395 -> V_2 . V_29 = V_6 -> V_2 . V_29 ;
if ( V_6 -> V_2 . V_338 )
V_395 -> V_2 . V_338 = V_6 -> V_2 . V_338 ;
if ( V_6 -> V_2 . V_343 )
V_395 -> V_2 . V_343 = V_6 -> V_2 . V_343 ;
if ( V_6 -> V_2 . V_396 )
V_395 -> V_2 . V_396 = V_6 -> V_2 . V_396 ;
if ( V_6 -> V_20 )
V_395 -> V_20 = V_6 -> V_20 ;
if ( V_6 -> V_21 )
V_395 -> V_21 = V_6 -> V_21 ;
if ( V_362 != NULL )
V_362 ( 0 , & V_395 -> V_2 ,
& V_395 -> V_37 ) ;
V_215 = F_177 ( & V_3 , & V_395 -> V_2 ) ;
if ( V_215 == 0 )
V_215 = V_395 -> V_2 . line ;
}
F_112 ( & V_398 ) ;
return V_215 ;
}
void F_202 ( int line )
{
struct V_5 * V_395 = & V_367 [ line ] ;
F_108 ( & V_398 ) ;
F_206 ( & V_3 , & V_395 -> V_2 ) ;
if ( V_400 ) {
V_395 -> V_2 . V_103 &= ~ V_399 ;
V_395 -> V_2 . type = V_130 ;
V_395 -> V_2 . V_379 = & V_400 -> V_379 ;
V_395 -> V_37 = V_44 [ V_395 -> V_2 . type ] . V_103 ;
F_177 ( & V_3 , & V_395 -> V_2 ) ;
} else {
V_395 -> V_2 . V_379 = NULL ;
}
F_112 ( & V_398 ) ;
}
static int T_3 F_207 ( void )
{
int V_215 ;
F_172 () ;
F_62 ( V_278 L_30
L_31 , V_365 ,
V_371 ? L_32 : L_33 ) ;
#ifdef F_208
V_215 = F_209 ( & V_3 , V_366 ) ;
#else
V_3 . V_401 = V_366 ;
V_215 = F_210 ( & V_3 ) ;
#endif
if ( V_215 )
goto V_127;
V_215 = F_211 () ;
if ( V_215 )
goto V_402;
V_400 = F_212 ( L_34 ,
V_403 ) ;
if ( ! V_400 ) {
V_215 = - V_240 ;
goto V_404;
}
V_215 = F_213 ( V_400 ) ;
if ( V_215 )
goto V_405;
F_176 ( & V_3 , & V_400 -> V_379 ) ;
V_215 = F_214 ( & V_406 ) ;
if ( V_215 == 0 )
goto V_127;
F_215 ( V_400 ) ;
V_405:
F_216 ( V_400 ) ;
V_404:
F_217 () ;
V_402:
#ifdef F_208
F_218 ( & V_3 , V_366 ) ;
#else
F_219 ( & V_3 ) ;
#endif
V_127:
return V_215 ;
}
static void T_5 F_220 ( void )
{
struct V_392 * V_407 = V_400 ;
V_400 = NULL ;
F_221 ( & V_406 ) ;
F_222 ( V_407 ) ;
F_217 () ;
#ifdef F_208
F_218 ( & V_3 , V_366 ) ;
#else
F_219 ( & V_3 ) ;
#endif
}
