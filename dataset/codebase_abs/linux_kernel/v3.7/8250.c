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
if ( V_10 -> V_37 & V_46 ) {
if ( V_10 -> V_37 & V_47 ) {
F_5 ( V_10 , V_31 , V_48 ) ;
F_5 ( V_10 , V_49 , V_50 ) ;
F_5 ( V_10 , V_31 , 0 ) ;
}
F_5 ( V_10 , V_51 , V_45 ? V_52 : 0 ) ;
if ( V_10 -> V_37 & V_47 ) {
F_5 ( V_10 , V_31 , V_48 ) ;
F_5 ( V_10 , V_49 , 0 ) ;
F_5 ( V_10 , V_31 , 0 ) ;
}
}
}
static int F_40 ( struct V_5 * V_6 )
{
unsigned char V_53 ;
int V_54 ;
V_53 = F_3 ( V_6 , V_55 ) ;
V_54 = V_53 & V_56 ;
if ( ! V_54 ) {
F_5 ( V_6 , V_55 , V_53 | V_56 ) ;
V_53 = F_3 ( V_6 , V_55 ) ;
V_54 = V_53 & V_56 ;
}
if ( V_54 )
V_6 -> V_2 . V_57 = V_58 * 16 ;
return V_54 ;
}
static void F_41 ( struct V_5 * V_6 )
{
if ( V_6 -> V_2 . type == V_59 ) {
if ( V_6 -> V_2 . V_57 != V_58 * 16 ) {
F_42 ( & V_6 -> V_2 . V_60 ) ;
F_40 ( V_6 ) ;
F_43 ( & V_6 -> V_2 . V_60 ) ;
}
if ( V_6 -> V_2 . V_57 == V_58 * 16 )
F_5 ( V_6 , V_61 , 0 ) ;
}
}
static void F_44 ( struct V_5 * V_6 )
{
unsigned char V_53 ;
int V_54 ;
if ( V_6 -> V_2 . type == V_59 &&
V_6 -> V_2 . V_57 == V_58 * 16 ) {
F_42 ( & V_6 -> V_2 . V_60 ) ;
V_53 = F_3 ( V_6 , V_55 ) ;
V_54 = ! ( V_53 & V_56 ) ;
if ( ! V_54 ) {
F_5 ( V_6 , V_55 , V_53 & ~ V_56 ) ;
V_53 = F_3 ( V_6 , V_55 ) ;
V_54 = ! ( V_53 & V_56 ) ;
}
if ( V_54 )
V_6 -> V_2 . V_57 = V_62 * 16 ;
F_43 ( & V_6 -> V_2 . V_60 ) ;
}
}
static int F_45 ( struct V_5 * V_6 )
{
unsigned char V_63 , V_64 , V_65 ;
unsigned short V_66 ;
int V_67 ;
V_65 = F_3 ( V_6 , V_31 ) ;
F_5 ( V_6 , V_31 , 0 ) ;
V_63 = F_3 ( V_6 , V_39 ) ;
V_64 = F_3 ( V_6 , V_68 ) ;
F_5 ( V_6 , V_39 , V_40 |
V_41 | V_42 ) ;
F_5 ( V_6 , V_68 , V_69 ) ;
F_5 ( V_6 , V_31 , V_70 ) ;
V_66 = F_46 ( V_6 ) ;
F_47 ( V_6 , 0x0001 ) ;
F_5 ( V_6 , V_31 , 0x03 ) ;
for ( V_67 = 0 ; V_67 < 256 ; V_67 ++ )
F_5 ( V_6 , V_71 , V_67 ) ;
F_48 ( 20 ) ;
for ( V_67 = 0 ; ( F_3 ( V_6 , V_72 ) & V_73 ) &&
( V_67 < 256 ) ; V_67 ++ )
F_3 ( V_6 , V_74 ) ;
F_5 ( V_6 , V_39 , V_63 ) ;
F_5 ( V_6 , V_68 , V_64 ) ;
F_5 ( V_6 , V_31 , V_70 ) ;
F_47 ( V_6 , V_66 ) ;
F_5 ( V_6 , V_31 , V_65 ) ;
return V_67 ;
}
static unsigned int F_49 ( struct V_5 * V_10 )
{
unsigned char V_75 , V_76 , V_65 ;
unsigned int V_77 ;
V_65 = F_3 ( V_10 , V_31 ) ;
F_5 ( V_10 , V_31 , V_70 ) ;
V_75 = F_3 ( V_10 , V_7 ) ;
V_76 = F_3 ( V_10 , V_8 ) ;
F_5 ( V_10 , V_7 , 0 ) ;
F_5 ( V_10 , V_8 , 0 ) ;
V_77 = F_3 ( V_10 , V_7 ) | F_3 ( V_10 , V_8 ) << 8 ;
F_5 ( V_10 , V_7 , V_75 ) ;
F_5 ( V_10 , V_8 , V_76 ) ;
F_5 ( V_10 , V_31 , V_65 ) ;
return V_77 ;
}
static void F_50 ( struct V_5 * V_6 )
{
unsigned int V_78 , V_79 , V_80 , V_81 ;
V_6 -> V_37 |= V_47 | V_46 ;
V_6 -> V_35 = 0 ;
F_5 ( V_6 , V_31 , V_48 ) ;
F_5 ( V_6 , V_49 , V_50 ) ;
F_5 ( V_6 , V_31 , 0x00 ) ;
V_78 = F_36 ( V_6 , V_82 ) ;
V_79 = F_36 ( V_6 , V_83 ) ;
V_80 = F_36 ( V_6 , V_84 ) ;
V_81 = F_36 ( V_6 , V_85 ) ;
F_51 ( L_1 , V_78 , V_79 , V_80 , V_81 ) ;
if ( V_78 == 0x16 && V_79 == 0xC9 &&
( V_80 == 0x50 || V_80 == 0x52 || V_80 == 0x54 ) ) {
V_6 -> V_2 . type = V_86 ;
if ( V_80 == 0x52 && V_81 == 0x01 )
V_6 -> V_87 |= V_88 ;
return;
}
V_78 = F_49 ( V_6 ) ;
F_51 ( L_2 , V_78 ) ;
V_79 = V_78 >> 8 ;
if ( V_79 == 0x10 || V_79 == 0x12 || V_79 == 0x14 ) {
V_6 -> V_2 . type = V_89 ;
return;
}
if ( F_45 ( V_6 ) == 64 )
V_6 -> V_2 . type = V_90 ;
else
V_6 -> V_2 . type = V_91 ;
}
static void F_52 ( struct V_5 * V_6 )
{
unsigned char V_92 , V_93 , V_94 ;
V_6 -> V_2 . type = V_95 ;
V_92 = F_3 ( V_6 , V_32 ) ;
F_5 ( V_6 , V_32 , 0xa5 ) ;
V_93 = F_3 ( V_6 , V_32 ) ;
F_5 ( V_6 , V_32 , 0x5a ) ;
V_94 = F_3 ( V_6 , V_32 ) ;
F_5 ( V_6 , V_32 , V_92 ) ;
if ( V_93 == 0xa5 && V_94 == 0x5a )
V_6 -> V_2 . type = V_96 ;
}
static int F_53 ( struct V_5 * V_6 )
{
if ( F_49 ( V_6 ) == 0x0201 && F_45 ( V_6 ) == 16 )
return 1 ;
return 0 ;
}
static inline int F_54 ( struct V_5 * V_6 )
{
unsigned char V_97 ;
V_97 = F_3 ( V_6 , 0x04 ) ;
#define F_55 ( T_1 ) ((x) & 0x30)
if ( F_55 ( V_97 ) == 0x10 ) {
return 0 ;
} else {
V_97 &= ~ 0xB0 ;
V_97 |= 0x10 ;
F_5 ( V_6 , 0x04 , V_97 ) ;
}
return 1 ;
}
static void F_56 ( struct V_5 * V_6 )
{
unsigned char V_93 , V_94 ;
unsigned int V_98 ;
V_6 -> V_2 . type = V_99 ;
V_6 -> V_37 |= V_38 ;
F_5 ( V_6 , V_31 , V_70 ) ;
if ( F_3 ( V_6 , V_49 ) == 0 ) {
F_5 ( V_6 , V_49 , 0xA8 ) ;
if ( F_3 ( V_6 , V_49 ) != 0 ) {
F_51 ( L_3 ) ;
V_6 -> V_2 . type = V_100 ;
V_6 -> V_37 |= V_47 | V_46 ;
} else {
F_51 ( L_4 ) ;
}
F_5 ( V_6 , V_49 , 0 ) ;
return;
}
F_5 ( V_6 , V_31 , V_48 ) ;
if ( F_3 ( V_6 , V_49 ) == 0 && ! F_53 ( V_6 ) ) {
F_51 ( L_5 ) ;
F_50 ( V_6 ) ;
return;
}
F_5 ( V_6 , V_31 , 0 ) ;
V_93 = F_3 ( V_6 , V_68 ) ;
F_5 ( V_6 , V_31 , 0xE0 ) ;
V_94 = F_3 ( V_6 , 0x02 ) ;
if ( ! ( ( V_94 ^ V_93 ) & V_69 ) ) {
F_5 ( V_6 , V_31 , 0 ) ;
F_5 ( V_6 , V_68 , V_93 ^ V_69 ) ;
F_5 ( V_6 , V_31 , 0xE0 ) ;
V_94 = F_3 ( V_6 , 0x02 ) ;
F_5 ( V_6 , V_31 , 0 ) ;
F_5 ( V_6 , V_68 , V_93 ) ;
if ( ( V_94 ^ V_93 ) & V_69 ) {
unsigned short V_101 ;
F_5 ( V_6 , V_31 , 0xE0 ) ;
V_101 = F_46 ( V_6 ) ;
V_101 <<= 3 ;
if ( F_54 ( V_6 ) )
F_47 ( V_6 , V_101 ) ;
F_5 ( V_6 , V_31 , 0 ) ;
V_6 -> V_2 . V_57 = 921600 * 16 ;
V_6 -> V_2 . type = V_102 ;
V_6 -> V_37 |= V_103 ;
return;
}
}
F_5 ( V_6 , V_31 , 0 ) ;
F_5 ( V_6 , V_39 , V_40 | V_104 ) ;
V_93 = F_3 ( V_6 , V_105 ) >> 5 ;
F_5 ( V_6 , V_39 , V_40 ) ;
F_5 ( V_6 , V_31 , V_70 ) ;
F_5 ( V_6 , V_39 , V_40 | V_104 ) ;
V_94 = F_3 ( V_6 , V_105 ) >> 5 ;
F_5 ( V_6 , V_39 , V_40 ) ;
F_5 ( V_6 , V_31 , 0 ) ;
F_51 ( L_6 , V_93 , V_94 ) ;
if ( V_93 == 6 && V_94 == 7 ) {
V_6 -> V_2 . type = V_106 ;
V_6 -> V_37 |= V_107 | V_46 ;
return;
}
V_98 = F_3 ( V_6 , V_51 ) ;
F_5 ( V_6 , V_51 , V_98 & ~ V_108 ) ;
if ( ! ( F_3 ( V_6 , V_51 ) & V_108 ) ) {
F_5 ( V_6 , V_51 , V_98 | V_108 ) ;
if ( F_3 ( V_6 , V_51 ) & V_108 ) {
F_51 ( L_7 ) ;
V_6 -> V_2 . type = V_109 ;
V_6 -> V_37 |= V_110 | V_111 ;
return;
}
} else {
F_51 ( L_8 ) ;
}
F_5 ( V_6 , V_51 , V_98 ) ;
if ( V_6 -> V_2 . V_112 & V_113 ) {
V_6 -> V_2 . type = V_114 ;
V_6 -> V_37 |= V_107 | V_47 ;
}
if ( V_6 -> V_2 . type == V_99 && F_45 ( V_6 ) == 64 ) {
V_6 -> V_2 . type = V_115 ;
V_6 -> V_37 |= V_107 ;
}
}
static void F_57 ( struct V_5 * V_6 , unsigned int V_116 )
{
unsigned char V_93 , V_92 , V_117 , V_118 ;
unsigned char V_119 , V_120 ;
struct V_1 * V_2 = & V_6 -> V_2 ;
unsigned long V_112 ;
unsigned int V_121 ;
if ( ! V_2 -> V_19 && ! V_2 -> V_122 && ! V_2 -> V_14 )
return;
F_51 ( L_9 ,
F_1 ( V_2 ) , V_2 -> V_19 , V_2 -> V_14 ) ;
F_58 ( & V_2 -> V_60 , V_112 ) ;
V_6 -> V_37 = 0 ;
V_6 -> V_87 = 0 ;
if ( ! ( V_2 -> V_112 & V_123 ) ) {
V_92 = F_3 ( V_6 , V_51 ) ;
F_5 ( V_6 , V_51 , 0 ) ;
#ifdef F_59
F_19 ( 0xff , 0x080 ) ;
#endif
V_117 = F_3 ( V_6 , V_51 ) & 0x0f ;
F_5 ( V_6 , V_51 , 0x0F ) ;
#ifdef F_59
F_19 ( 0 , 0x080 ) ;
#endif
V_118 = F_3 ( V_6 , V_51 ) & 0x0f ;
F_5 ( V_6 , V_51 , V_92 ) ;
if ( V_117 != 0 || V_118 != 0x0F ) {
F_60 ( & V_2 -> V_60 , V_112 ) ;
F_51 ( L_10 ,
V_117 , V_118 ) ;
goto V_124;
}
}
V_120 = F_3 ( V_6 , V_68 ) ;
V_119 = F_3 ( V_6 , V_31 ) ;
if ( ! ( V_2 -> V_112 & V_125 ) ) {
F_5 ( V_6 , V_68 , V_69 | 0x0A ) ;
V_93 = F_3 ( V_6 , V_126 ) & 0xF0 ;
F_5 ( V_6 , V_68 , V_120 ) ;
if ( V_93 != 0x90 ) {
F_60 ( & V_2 -> V_60 , V_112 ) ;
F_51 ( L_11 ,
V_93 ) ;
goto V_124;
}
}
F_5 ( V_6 , V_31 , V_48 ) ;
F_5 ( V_6 , V_49 , 0 ) ;
F_5 ( V_6 , V_31 , 0 ) ;
F_5 ( V_6 , V_39 , V_40 ) ;
V_92 = F_3 ( V_6 , V_105 ) >> 6 ;
switch ( V_92 ) {
case 0 :
F_52 ( V_6 ) ;
break;
case 1 :
V_2 -> type = V_127 ;
break;
case 2 :
V_2 -> type = V_128 ;
break;
case 3 :
F_56 ( V_6 ) ;
break;
}
#ifdef F_61
if ( V_2 -> type == V_99 && V_116 & V_129 ) {
int V_130 ;
for ( V_130 = 0 ; V_130 < V_131 ; ++ V_130 ) {
if ( V_132 [ V_130 ] == V_2 -> V_19 && F_40 ( V_6 ) ) {
V_2 -> type = V_59 ;
break;
}
}
}
#endif
F_5 ( V_6 , V_31 , V_119 ) ;
V_2 -> V_133 = V_44 [ V_6 -> V_2 . type ] . V_134 ;
V_121 = V_6 -> V_37 ;
V_6 -> V_37 = V_44 [ V_2 -> type ] . V_112 ;
V_6 -> V_135 = V_44 [ V_2 -> type ] . V_135 ;
if ( V_2 -> type == V_127 )
goto V_136;
#ifdef F_61
if ( V_2 -> type == V_59 )
F_5 ( V_6 , V_61 , 0 ) ;
#endif
F_5 ( V_6 , V_68 , V_120 ) ;
F_37 ( V_6 ) ;
F_3 ( V_6 , V_74 ) ;
if ( V_6 -> V_37 & V_110 )
F_5 ( V_6 , V_51 , V_108 ) ;
else
F_5 ( V_6 , V_51 , 0 ) ;
V_136:
F_60 ( & V_2 -> V_60 , V_112 ) ;
if ( V_6 -> V_37 != V_121 ) {
F_62 ( V_137
L_12 ,
F_1 ( V_2 ) , V_121 ,
V_6 -> V_37 ) ;
}
V_124:
F_51 ( L_13 , V_92 ) ;
F_51 ( L_14 , V_44 [ V_2 -> type ] . V_138 ) ;
}
static void F_63 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = & V_6 -> V_2 ;
unsigned char V_120 , V_139 ;
unsigned char V_140 = 0 ;
unsigned int V_141 = 0 ;
unsigned long V_142 ;
int V_143 ;
if ( V_2 -> V_112 & V_144 ) {
V_141 = ( V_2 -> V_19 & 0xfe0 ) | 0x1f ;
V_140 = F_64 ( V_141 ) ;
F_65 ( 0x80 , V_141 ) ;
F_64 ( V_141 ) ;
}
F_66 ( F_67 () ) ;
V_120 = F_3 ( V_6 , V_68 ) ;
V_139 = F_3 ( V_6 , V_51 ) ;
F_5 ( V_6 , V_68 , V_145 | V_146 ) ;
V_142 = F_67 () ;
F_5 ( V_6 , V_68 , 0 ) ;
F_68 ( 10 ) ;
if ( V_2 -> V_112 & V_144 ) {
F_5 ( V_6 , V_68 ,
V_147 | V_148 ) ;
} else {
F_5 ( V_6 , V_68 ,
V_147 | V_148 | V_146 ) ;
}
F_5 ( V_6 , V_51 , 0x0f ) ;
F_3 ( V_6 , V_72 ) ;
F_3 ( V_6 , V_74 ) ;
F_3 ( V_6 , V_105 ) ;
F_3 ( V_6 , V_126 ) ;
F_5 ( V_6 , V_71 , 0xFF ) ;
F_68 ( 20 ) ;
V_143 = F_66 ( V_142 ) ;
F_5 ( V_6 , V_68 , V_120 ) ;
F_5 ( V_6 , V_51 , V_139 ) ;
if ( V_2 -> V_112 & V_144 )
F_65 ( V_140 , V_141 ) ;
V_2 -> V_143 = ( V_143 > 0 ) ? V_143 : 0 ;
}
static inline void F_69 ( struct V_5 * V_10 )
{
if ( V_10 -> V_149 & V_150 ) {
V_10 -> V_149 &= ~ V_150 ;
F_5 ( V_10 , V_51 , V_10 -> V_149 ) ;
}
}
static void F_70 ( struct V_1 * V_2 )
{
struct V_5 * V_6 =
F_31 ( V_2 , struct V_5 , V_2 ) ;
F_69 ( V_6 ) ;
if ( V_2 -> type == V_86 ) {
V_6 -> V_35 |= V_151 ;
F_35 ( V_6 , V_34 , V_6 -> V_35 ) ;
}
}
static void F_71 ( struct V_1 * V_2 )
{
struct V_5 * V_6 =
F_31 ( V_2 , struct V_5 , V_2 ) ;
if ( ! ( V_6 -> V_149 & V_150 ) ) {
V_6 -> V_149 |= V_150 ;
F_72 ( V_2 , V_51 , V_6 -> V_149 ) ;
if ( V_6 -> V_87 & V_152 ) {
unsigned char V_153 ;
V_153 = F_3 ( V_6 , V_72 ) ;
V_6 -> V_154 |= V_153 & V_155 ;
if ( ( V_2 -> type == V_156 ) ?
( V_153 & V_157 ) :
( V_153 & V_158 ) )
F_73 ( V_6 ) ;
}
}
if ( V_2 -> type == V_86 && V_6 -> V_35 & V_151 ) {
V_6 -> V_35 &= ~ V_151 ;
F_35 ( V_6 , V_34 , V_6 -> V_35 ) ;
}
}
static void F_74 ( struct V_1 * V_2 )
{
struct V_5 * V_6 =
F_31 ( V_2 , struct V_5 , V_2 ) ;
V_6 -> V_149 &= ~ V_159 ;
V_6 -> V_2 . V_160 &= ~ V_73 ;
F_72 ( V_2 , V_51 , V_6 -> V_149 ) ;
}
static void F_75 ( struct V_1 * V_2 )
{
struct V_5 * V_6 =
F_31 ( V_2 , struct V_5 , V_2 ) ;
if ( V_6 -> V_87 & V_161 )
return;
V_6 -> V_149 |= V_162 ;
F_72 ( V_2 , V_51 , V_6 -> V_149 ) ;
}
unsigned char
F_76 ( struct V_5 * V_6 , unsigned char V_153 )
{
struct V_1 * V_2 = & V_6 -> V_2 ;
struct V_163 * V_164 = V_2 -> V_165 -> V_2 . V_164 ;
unsigned char V_166 ;
int V_167 = 256 ;
char V_168 ;
do {
if ( F_77 ( V_153 & V_73 ) )
V_166 = F_3 ( V_6 , V_74 ) ;
else
V_166 = 0 ;
V_168 = V_169 ;
V_2 -> V_170 . V_171 ++ ;
V_153 |= V_6 -> V_154 ;
V_6 -> V_154 = 0 ;
if ( F_78 ( V_153 & V_172 ) ) {
if ( V_153 & V_173 ) {
V_153 &= ~ ( V_174 | V_175 ) ;
V_2 -> V_170 . V_176 ++ ;
if ( F_79 ( V_2 ) )
goto V_177;
} else if ( V_153 & V_175 )
V_2 -> V_170 . V_178 ++ ;
else if ( V_153 & V_174 )
V_2 -> V_170 . V_179 ++ ;
if ( V_153 & V_180 )
V_2 -> V_170 . V_181 ++ ;
V_153 &= V_2 -> V_160 ;
if ( V_153 & V_173 ) {
F_80 ( L_15 ) ;
V_168 = V_182 ;
} else if ( V_153 & V_175 )
V_168 = V_183 ;
else if ( V_153 & V_174 )
V_168 = V_184 ;
}
if ( F_81 ( V_2 , V_166 ) )
goto V_177;
F_82 ( V_2 , V_153 , V_180 , V_166 , V_168 ) ;
V_177:
V_153 = F_3 ( V_6 , V_72 ) ;
} while ( ( V_153 & ( V_73 | V_173 ) ) && ( V_167 -- > 0 ) );
F_83 ( & V_2 -> V_60 ) ;
F_84 ( V_164 ) ;
F_85 ( & V_2 -> V_60 ) ;
return V_153 ;
}
void F_73 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = & V_6 -> V_2 ;
struct V_185 * V_186 = & V_2 -> V_165 -> V_186 ;
int V_67 ;
if ( V_2 -> V_187 ) {
F_5 ( V_6 , V_71 , V_2 -> V_187 ) ;
V_2 -> V_170 . V_188 ++ ;
V_2 -> V_187 = 0 ;
return;
}
if ( F_86 ( V_2 ) ) {
F_70 ( V_2 ) ;
return;
}
if ( F_87 ( V_186 ) ) {
F_69 ( V_6 ) ;
return;
}
V_67 = V_6 -> V_135 ;
do {
F_5 ( V_6 , V_71 , V_186 -> V_189 [ V_186 -> V_190 ] ) ;
V_186 -> V_190 = ( V_186 -> V_190 + 1 ) & ( V_191 - 1 ) ;
V_2 -> V_170 . V_188 ++ ;
if ( F_87 ( V_186 ) )
break;
} while ( -- V_67 > 0 );
if ( F_88 ( V_186 ) < V_192 )
F_89 ( V_2 ) ;
F_80 ( L_16 ) ;
if ( F_87 ( V_186 ) )
F_69 ( V_6 ) ;
}
unsigned int F_90 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = & V_6 -> V_2 ;
unsigned int V_97 = F_3 ( V_6 , V_126 ) ;
V_97 |= V_6 -> V_193 ;
V_6 -> V_193 = 0 ;
if ( V_97 & V_194 && V_6 -> V_149 & V_162 &&
V_2 -> V_165 != NULL ) {
if ( V_97 & V_195 )
V_2 -> V_170 . V_196 ++ ;
if ( V_97 & V_197 )
V_2 -> V_170 . V_198 ++ ;
if ( V_97 & V_199 )
F_91 ( V_2 , V_97 & V_200 ) ;
if ( V_97 & V_201 )
F_92 ( V_2 , V_97 & V_202 ) ;
F_93 ( & V_2 -> V_165 -> V_2 . V_203 ) ;
}
return V_97 ;
}
int F_94 ( struct V_1 * V_2 , unsigned int V_204 )
{
unsigned char V_97 ;
unsigned long V_112 ;
struct V_5 * V_6 =
F_31 ( V_2 , struct V_5 , V_2 ) ;
if ( V_204 & V_205 )
return 0 ;
F_58 ( & V_2 -> V_60 , V_112 ) ;
V_97 = F_95 ( V_2 , V_72 ) ;
F_80 ( L_17 , V_97 ) ;
if ( V_97 & ( V_73 | V_173 ) )
V_97 = F_76 ( V_6 , V_97 ) ;
F_90 ( V_6 ) ;
if ( V_97 & V_157 )
F_73 ( V_6 ) ;
F_60 ( & V_2 -> V_60 , V_112 ) ;
return 1 ;
}
static int V_30 ( struct V_1 * V_2 )
{
unsigned int V_204 = F_95 ( V_2 , V_105 ) ;
return F_94 ( V_2 , V_204 ) ;
}
static T_2 F_96 ( int V_143 , void * V_206 )
{
struct V_207 * V_130 = V_206 ;
struct V_208 * V_209 , * V_210 = NULL ;
int V_211 = 0 , V_212 = 0 ;
F_80 ( L_18 , V_143 ) ;
F_85 ( & V_130 -> V_60 ) ;
V_209 = V_130 -> V_213 ;
do {
struct V_5 * V_6 ;
struct V_1 * V_2 ;
V_6 = F_97 ( V_209 , struct V_5 , V_214 ) ;
V_2 = & V_6 -> V_2 ;
if ( V_2 -> V_29 ( V_2 ) ) {
V_212 = 1 ;
V_210 = NULL ;
} else if ( V_210 == NULL )
V_210 = V_209 ;
V_209 = V_209 -> V_215 ;
if ( V_209 == V_130 -> V_213 && V_211 ++ > V_216 ) {
F_98 ( V_217
L_19 , V_143 ) ;
break;
}
} while ( V_209 != V_210 );
F_83 ( & V_130 -> V_60 ) ;
F_80 ( L_20 ) ;
return F_99 ( V_212 ) ;
}
static void F_100 ( struct V_207 * V_130 , struct V_5 * V_6 )
{
F_42 ( & V_130 -> V_60 ) ;
if ( ! F_101 ( V_130 -> V_213 ) ) {
if ( V_130 -> V_213 == & V_6 -> V_214 )
V_130 -> V_213 = V_130 -> V_213 -> V_215 ;
F_102 ( & V_6 -> V_214 ) ;
} else {
F_103 ( V_130 -> V_213 != & V_6 -> V_214 ) ;
V_130 -> V_213 = NULL ;
}
F_43 ( & V_130 -> V_60 ) ;
if ( V_130 -> V_213 == NULL ) {
F_104 ( & V_130 -> V_218 ) ;
F_105 ( V_130 ) ;
}
}
static int F_106 ( struct V_5 * V_6 )
{
struct V_219 * V_220 ;
struct V_221 * V_222 ;
struct V_207 * V_130 ;
int V_223 , V_224 = V_6 -> V_2 . V_112 & V_225 ? V_226 : 0 ;
F_107 ( & V_227 ) ;
V_220 = & V_228 [ V_6 -> V_2 . V_143 % V_229 ] ;
F_108 (n, h) {
V_130 = F_109 ( V_222 , struct V_207 , V_218 ) ;
if ( V_130 -> V_143 == V_6 -> V_2 . V_143 )
break;
}
if ( V_222 == NULL ) {
V_130 = F_110 ( sizeof( struct V_207 ) , V_230 ) ;
if ( V_130 == NULL ) {
F_111 ( & V_227 ) ;
return - V_231 ;
}
F_112 ( & V_130 -> V_60 ) ;
V_130 -> V_143 = V_6 -> V_2 . V_143 ;
F_113 ( & V_130 -> V_218 , V_220 ) ;
}
F_111 ( & V_227 ) ;
F_42 ( & V_130 -> V_60 ) ;
if ( V_130 -> V_213 ) {
F_114 ( & V_6 -> V_214 , V_130 -> V_213 ) ;
F_43 ( & V_130 -> V_60 ) ;
V_223 = 0 ;
} else {
F_115 ( & V_6 -> V_214 ) ;
V_130 -> V_213 = & V_6 -> V_214 ;
F_43 ( & V_130 -> V_60 ) ;
V_224 |= V_6 -> V_2 . V_232 ;
V_223 = F_116 ( V_6 -> V_2 . V_143 , F_96 ,
V_224 , L_21 , V_130 ) ;
if ( V_223 < 0 )
F_100 ( V_130 , V_6 ) ;
}
return V_223 ;
}
static void F_117 ( struct V_5 * V_6 )
{
struct V_207 * V_130 ;
struct V_221 * V_222 ;
struct V_219 * V_220 ;
F_107 ( & V_227 ) ;
V_220 = & V_228 [ V_6 -> V_2 . V_143 % V_229 ] ;
F_108 (n, h) {
V_130 = F_109 ( V_222 , struct V_207 , V_218 ) ;
if ( V_130 -> V_143 == V_6 -> V_2 . V_143 )
break;
}
F_103 ( V_222 == NULL ) ;
F_103 ( V_130 -> V_213 == NULL ) ;
if ( F_101 ( V_130 -> V_213 ) )
F_118 ( V_6 -> V_2 . V_143 , V_130 ) ;
F_100 ( V_130 , V_6 ) ;
F_111 ( & V_227 ) ;
}
static void F_119 ( unsigned long V_233 )
{
struct V_5 * V_6 = (struct V_5 * ) V_233 ;
V_6 -> V_2 . V_29 ( & V_6 -> V_2 ) ;
F_120 ( & V_6 -> V_234 , V_235 + F_121 ( & V_6 -> V_2 ) ) ;
}
static void F_122 ( unsigned long V_233 )
{
struct V_5 * V_6 = (struct V_5 * ) V_233 ;
unsigned int V_204 , V_149 = 0 , V_153 ;
unsigned long V_112 ;
F_58 ( & V_6 -> V_2 . V_60 , V_112 ) ;
if ( V_6 -> V_2 . V_143 ) {
V_149 = F_3 ( V_6 , V_51 ) ;
F_5 ( V_6 , V_51 , 0 ) ;
}
V_204 = F_3 ( V_6 , V_105 ) ;
V_153 = F_3 ( V_6 , V_72 ) ;
V_6 -> V_154 |= V_153 & V_155 ;
if ( ( V_204 & V_205 ) && ( V_6 -> V_149 & V_150 ) &&
( ! F_87 ( & V_6 -> V_2 . V_165 -> V_186 ) || V_6 -> V_2 . V_187 ) &&
( V_153 & V_157 ) ) {
V_204 &= ~ ( V_236 | V_205 ) ;
V_204 |= V_237 ;
}
if ( ! ( V_204 & V_205 ) )
F_73 ( V_6 ) ;
if ( V_6 -> V_2 . V_143 )
F_5 ( V_6 , V_51 , V_149 ) ;
F_60 ( & V_6 -> V_2 . V_60 , V_112 ) ;
F_120 ( & V_6 -> V_234 ,
V_235 + F_121 ( & V_6 -> V_2 ) + V_238 / 5 ) ;
}
static unsigned int F_123 ( struct V_1 * V_2 )
{
struct V_5 * V_6 =
F_31 ( V_2 , struct V_5 , V_2 ) ;
unsigned long V_112 ;
unsigned int V_153 ;
F_58 ( & V_2 -> V_60 , V_112 ) ;
V_153 = F_95 ( V_2 , V_72 ) ;
V_6 -> V_154 |= V_153 & V_155 ;
F_60 ( & V_2 -> V_60 , V_112 ) ;
return ( V_153 & V_239 ) == V_239 ? V_240 : 0 ;
}
static unsigned int F_124 ( struct V_1 * V_2 )
{
struct V_5 * V_6 =
F_31 ( V_2 , struct V_5 , V_2 ) ;
unsigned int V_97 ;
unsigned int V_223 ;
V_97 = F_90 ( V_6 ) ;
V_223 = 0 ;
if ( V_97 & V_200 )
V_223 |= V_241 ;
if ( V_97 & V_242 )
V_223 |= V_243 ;
if ( V_97 & V_244 )
V_223 |= V_245 ;
if ( V_97 & V_202 )
V_223 |= V_246 ;
return V_223 ;
}
static void F_125 ( struct V_1 * V_2 , unsigned int V_247 )
{
struct V_5 * V_6 =
F_31 ( V_2 , struct V_5 , V_2 ) ;
unsigned char V_248 = 0 ;
if ( V_247 & V_249 )
V_248 |= V_148 ;
if ( V_247 & V_250 )
V_248 |= V_147 ;
if ( V_247 & V_251 )
V_248 |= V_145 ;
if ( V_247 & V_252 )
V_248 |= V_146 ;
if ( V_247 & V_253 )
V_248 |= V_69 ;
V_248 = ( V_248 & V_6 -> V_254 ) | V_6 -> V_255 | V_6 -> V_248 ;
F_72 ( V_2 , V_68 , V_248 ) ;
}
static void F_126 ( struct V_1 * V_2 , int V_256 )
{
struct V_5 * V_6 =
F_31 ( V_2 , struct V_5 , V_2 ) ;
unsigned long V_112 ;
F_58 ( & V_2 -> V_60 , V_112 ) ;
if ( V_256 == - 1 )
V_6 -> V_257 |= V_258 ;
else
V_6 -> V_257 &= ~ V_258 ;
F_72 ( V_2 , V_31 , V_6 -> V_257 ) ;
F_60 ( & V_2 -> V_60 , V_112 ) ;
}
static void F_127 ( struct V_5 * V_6 , int V_259 )
{
unsigned int V_97 , V_260 = 10000 ;
for (; ; ) {
V_97 = F_3 ( V_6 , V_72 ) ;
V_6 -> V_154 |= V_97 & V_155 ;
if ( ( V_97 & V_259 ) == V_259 )
break;
if ( -- V_260 == 0 )
break;
F_68 ( 1 ) ;
}
if ( V_6 -> V_2 . V_112 & V_261 ) {
unsigned int V_260 ;
for ( V_260 = 1000000 ; V_260 ; V_260 -- ) {
unsigned int V_262 = F_3 ( V_6 , V_126 ) ;
V_6 -> V_193 |= V_262 & V_263 ;
if ( V_262 & V_202 )
break;
F_68 ( 1 ) ;
F_128 () ;
}
}
}
static int F_129 ( struct V_1 * V_2 )
{
unsigned char V_153 = F_95 ( V_2 , V_72 ) ;
if ( ! ( V_153 & V_73 ) )
return V_264 ;
return F_95 ( V_2 , V_74 ) ;
}
static void F_130 ( struct V_1 * V_2 ,
unsigned char V_265 )
{
unsigned int V_149 ;
struct V_5 * V_6 =
F_31 ( V_2 , struct V_5 , V_2 ) ;
V_149 = F_95 ( V_2 , V_51 ) ;
if ( V_6 -> V_37 & V_110 )
F_72 ( V_2 , V_51 , V_108 ) ;
else
F_72 ( V_2 , V_51 , 0 ) ;
F_127 ( V_6 , V_239 ) ;
F_72 ( V_2 , V_71 , V_265 ) ;
if ( V_265 == 10 ) {
F_127 ( V_6 , V_239 ) ;
F_72 ( V_2 , V_71 , 13 ) ;
}
F_127 ( V_6 , V_239 ) ;
F_72 ( V_2 , V_51 , V_149 ) ;
}
static int F_131 ( struct V_1 * V_2 )
{
struct V_5 * V_6 =
F_31 ( V_2 , struct V_5 , V_2 ) ;
unsigned long V_112 ;
unsigned char V_153 , V_204 ;
int V_266 ;
if ( V_2 -> type == V_267 )
return - V_268 ;
V_2 -> V_133 = V_44 [ V_6 -> V_2 . type ] . V_134 ;
V_6 -> V_135 = V_44 [ V_6 -> V_2 . type ] . V_135 ;
V_6 -> V_37 = V_44 [ V_6 -> V_2 . type ] . V_112 ;
V_6 -> V_248 = 0 ;
if ( V_2 -> V_22 != V_6 -> V_28 )
F_30 ( V_2 ) ;
if ( V_2 -> type == V_86 ) {
V_6 -> V_35 = 0 ;
F_72 ( V_2 , V_31 , V_48 ) ;
F_72 ( V_2 , V_49 , V_50 ) ;
F_72 ( V_2 , V_51 , 0 ) ;
F_72 ( V_2 , V_31 , 0 ) ;
F_35 ( V_6 , V_269 , 0 ) ;
F_72 ( V_2 , V_31 , V_48 ) ;
F_72 ( V_2 , V_49 , V_50 ) ;
F_72 ( V_2 , V_31 , 0 ) ;
}
#ifdef F_61
F_41 ( V_6 ) ;
#endif
F_37 ( V_6 ) ;
F_95 ( V_2 , V_72 ) ;
F_95 ( V_2 , V_74 ) ;
F_95 ( V_2 , V_105 ) ;
F_95 ( V_2 , V_126 ) ;
if ( ! ( V_2 -> V_112 & V_123 ) &&
( F_95 ( V_2 , V_72 ) == 0xff ) ) {
F_98 ( V_270 L_22 ,
F_1 ( V_2 ) ) ;
return - V_268 ;
}
if ( V_2 -> type == V_89 ) {
unsigned char V_271 ;
F_5 ( V_6 , V_31 , V_48 ) ;
V_271 = F_3 ( V_6 , V_272 ) & ~ ( V_273 | V_274 ) ;
F_72 ( V_2 , V_272 ,
V_271 | V_275 | V_273 ) ;
F_72 ( V_2 , V_276 , V_277 ) ;
F_72 ( V_2 , V_272 ,
V_271 | V_275 | V_274 ) ;
F_72 ( V_2 , V_276 , V_277 ) ;
F_72 ( V_2 , V_31 , 0 ) ;
}
if ( V_2 -> V_143 ) {
unsigned char V_278 ;
F_58 ( & V_2 -> V_60 , V_112 ) ;
if ( V_6 -> V_2 . V_232 & V_226 )
F_132 ( V_2 -> V_143 ) ;
F_127 ( V_6 , V_157 ) ;
F_34 ( V_2 , V_51 , V_150 ) ;
F_68 ( 1 ) ;
V_278 = F_95 ( V_2 , V_105 ) ;
F_72 ( V_2 , V_51 , 0 ) ;
F_34 ( V_2 , V_51 , V_150 ) ;
F_68 ( 1 ) ;
V_204 = F_95 ( V_2 , V_105 ) ;
F_72 ( V_2 , V_51 , 0 ) ;
if ( V_2 -> V_232 & V_226 )
F_133 ( V_2 -> V_143 ) ;
F_60 ( & V_2 -> V_60 , V_112 ) ;
if ( ( ! ( V_278 & V_205 ) && ( V_204 & V_205 ) ) ||
V_6 -> V_2 . V_112 & V_279 ) {
V_6 -> V_87 |= V_280 ;
F_134 ( L_23 ,
F_1 ( V_2 ) ) ;
}
}
if ( V_6 -> V_87 & V_280 ) {
V_6 -> V_234 . V_281 = F_122 ;
V_6 -> V_234 . V_233 = ( unsigned long ) V_6 ;
F_120 ( & V_6 -> V_234 , V_235 +
F_121 ( V_2 ) + V_238 / 5 ) ;
}
if ( ! V_2 -> V_143 ) {
V_6 -> V_234 . V_233 = ( unsigned long ) V_6 ;
F_120 ( & V_6 -> V_234 , V_235 + F_121 ( V_2 ) ) ;
} else {
V_266 = F_106 ( V_6 ) ;
if ( V_266 )
return V_266 ;
}
F_72 ( V_2 , V_31 , V_282 ) ;
F_58 ( & V_2 -> V_60 , V_112 ) ;
if ( V_6 -> V_2 . V_112 & V_144 ) {
if ( ! V_6 -> V_2 . V_143 )
V_6 -> V_2 . V_247 |= V_251 ;
} else
if ( V_2 -> V_143 )
V_6 -> V_2 . V_247 |= V_252 ;
F_125 ( V_2 , V_2 -> V_247 ) ;
if ( V_283 || V_6 -> V_2 . V_112 & V_284 )
goto V_285;
F_72 ( V_2 , V_51 , V_150 ) ;
V_153 = F_95 ( V_2 , V_72 ) ;
V_204 = F_95 ( V_2 , V_105 ) ;
F_72 ( V_2 , V_51 , 0 ) ;
if ( V_153 & V_158 && V_204 & V_205 ) {
if ( ! ( V_6 -> V_87 & V_152 ) ) {
V_6 -> V_87 |= V_152 ;
F_134 ( L_24 ,
F_1 ( V_2 ) ) ;
}
} else {
V_6 -> V_87 &= ~ V_152 ;
}
V_285:
F_60 ( & V_2 -> V_60 , V_112 ) ;
F_95 ( V_2 , V_72 ) ;
F_95 ( V_2 , V_74 ) ;
F_95 ( V_2 , V_105 ) ;
F_95 ( V_2 , V_126 ) ;
V_6 -> V_154 = 0 ;
V_6 -> V_193 = 0 ;
V_6 -> V_149 = V_159 | V_286 ;
F_72 ( V_2 , V_51 , V_6 -> V_149 ) ;
if ( V_2 -> V_112 & V_144 ) {
unsigned int V_287 ;
V_287 = ( V_2 -> V_19 & 0xfe0 ) | 0x01f ;
F_65 ( 0x80 , V_287 ) ;
F_64 ( V_287 ) ;
}
return 0 ;
}
static void F_135 ( struct V_1 * V_2 )
{
struct V_5 * V_6 =
F_31 ( V_2 , struct V_5 , V_2 ) ;
unsigned long V_112 ;
V_6 -> V_149 = 0 ;
F_72 ( V_2 , V_51 , 0 ) ;
F_58 ( & V_2 -> V_60 , V_112 ) ;
if ( V_2 -> V_112 & V_144 ) {
F_20 ( ( V_2 -> V_19 & 0xfe0 ) | 0x1f ) ;
V_2 -> V_247 |= V_251 ;
} else
V_2 -> V_247 &= ~ V_252 ;
F_125 ( V_2 , V_2 -> V_247 ) ;
F_60 ( & V_2 -> V_60 , V_112 ) ;
F_72 ( V_2 , V_31 ,
F_95 ( V_2 , V_31 ) & ~ V_258 ) ;
F_37 ( V_6 ) ;
#ifdef F_61
F_44 ( V_6 ) ;
#endif
F_95 ( V_2 , V_74 ) ;
F_136 ( & V_6 -> V_234 ) ;
V_6 -> V_234 . V_281 = F_119 ;
if ( V_2 -> V_143 )
F_117 ( V_6 ) ;
}
static unsigned int F_137 ( struct V_1 * V_2 , unsigned int V_288 )
{
unsigned int V_101 ;
if ( ( V_2 -> V_112 & V_289 ) &&
V_288 == ( V_2 -> V_57 / 4 ) )
V_101 = 0x8001 ;
else if ( ( V_2 -> V_112 & V_289 ) &&
V_288 == ( V_2 -> V_57 / 8 ) )
V_101 = 0x8002 ;
else
V_101 = F_138 ( V_2 , V_288 ) ;
return V_101 ;
}
void
F_139 ( struct V_1 * V_2 , struct V_290 * V_291 ,
struct V_290 * V_292 )
{
struct V_5 * V_6 =
F_31 ( V_2 , struct V_5 , V_2 ) ;
unsigned char V_293 , V_43 = 0 ;
unsigned long V_112 ;
unsigned int V_288 , V_101 ;
int V_294 = 0 ;
switch ( V_291 -> V_295 & V_296 ) {
case V_297 :
V_293 = V_298 ;
break;
case V_299 :
V_293 = V_300 ;
break;
case V_301 :
V_293 = V_302 ;
break;
default:
case V_303 :
V_293 = V_282 ;
break;
}
if ( V_291 -> V_295 & V_304 )
V_293 |= V_305 ;
if ( V_291 -> V_295 & V_306 ) {
V_293 |= V_307 ;
if ( V_6 -> V_87 & V_308 )
V_294 = 1 ;
}
if ( ! ( V_291 -> V_295 & V_309 ) )
V_293 |= V_310 ;
#ifdef F_140
if ( V_291 -> V_295 & F_140 )
V_293 |= V_311 ;
#endif
V_288 = F_141 ( V_2 , V_291 , V_292 ,
V_2 -> V_57 / 16 / 0xffff ,
V_2 -> V_57 / 16 ) ;
V_101 = F_137 ( V_2 , V_288 ) ;
if ( V_6 -> V_87 & V_88 && ( V_101 & 0xff ) == 0 )
V_101 ++ ;
if ( V_6 -> V_37 & V_38 && V_2 -> V_133 > 1 ) {
V_43 = V_44 [ V_2 -> type ] . V_43 ;
if ( V_288 < 2400 || V_294 ) {
V_43 &= ~ V_312 ;
V_43 |= V_313 ;
}
}
if ( V_6 -> V_37 & V_107 && V_2 -> V_133 >= 32 ) {
V_6 -> V_248 &= ~ V_314 ;
if ( V_291 -> V_295 & V_315 )
V_6 -> V_248 |= V_314 ;
}
F_58 ( & V_2 -> V_60 , V_112 ) ;
F_142 ( V_2 , V_291 -> V_295 , V_288 ) ;
V_2 -> V_160 = V_180 | V_157 | V_73 ;
if ( V_291 -> V_316 & V_317 )
V_2 -> V_160 |= V_174 | V_175 ;
if ( V_291 -> V_316 & ( V_318 | V_319 ) )
V_2 -> V_160 |= V_173 ;
V_2 -> V_320 = 0 ;
if ( V_291 -> V_316 & V_321 )
V_2 -> V_320 |= V_175 | V_174 ;
if ( V_291 -> V_316 & V_322 ) {
V_2 -> V_320 |= V_173 ;
if ( V_291 -> V_316 & V_321 )
V_2 -> V_320 |= V_180 ;
}
if ( ( V_291 -> V_295 & V_323 ) == 0 )
V_2 -> V_320 |= V_73 ;
V_6 -> V_149 &= ~ V_162 ;
if ( ! ( V_6 -> V_87 & V_161 ) &&
F_143 ( & V_6 -> V_2 , V_291 -> V_295 ) )
V_6 -> V_149 |= V_162 ;
if ( V_6 -> V_37 & V_110 )
V_6 -> V_149 |= V_108 ;
if ( V_6 -> V_37 & V_111 )
V_6 -> V_149 |= V_324 ;
F_72 ( V_2 , V_51 , V_6 -> V_149 ) ;
if ( V_6 -> V_37 & V_47 ) {
unsigned char V_325 = 0 ;
if ( V_291 -> V_295 & V_315 )
V_325 |= V_326 ;
F_72 ( V_2 , V_31 , V_48 ) ;
if ( V_2 -> V_112 & V_113 )
F_72 ( V_2 , V_327 , V_325 ) ;
else
F_72 ( V_2 , V_49 , V_325 ) ;
}
#ifdef F_144
if ( F_145 () && F_146 ( V_6 ) ) {
if ( V_288 == 115200 ) {
V_101 = 1 ;
F_72 ( V_2 , V_328 , 1 ) ;
} else
F_72 ( V_2 , V_328 , 0 ) ;
}
#endif
if ( V_6 -> V_37 & V_103 )
F_72 ( V_2 , V_31 , 0xe0 ) ;
else
F_72 ( V_2 , V_31 , V_293 | V_329 ) ;
F_47 ( V_6 , V_101 ) ;
if ( V_2 -> type == V_106 )
F_72 ( V_2 , V_39 , V_43 ) ;
F_72 ( V_2 , V_31 , V_293 ) ;
V_6 -> V_257 = V_293 ;
if ( V_2 -> type != V_106 ) {
if ( V_43 & V_40 )
F_72 ( V_2 , V_39 , V_40 ) ;
F_72 ( V_2 , V_39 , V_43 ) ;
}
F_125 ( V_2 , V_2 -> V_247 ) ;
F_60 ( & V_2 -> V_60 , V_112 ) ;
if ( F_147 ( V_291 ) )
F_148 ( V_291 , V_288 , V_288 ) ;
}
static void
F_149 ( struct V_1 * V_2 , struct V_290 * V_291 ,
struct V_290 * V_292 )
{
if ( V_2 -> V_330 )
V_2 -> V_330 ( V_2 , V_291 , V_292 ) ;
else
F_139 ( V_2 , V_291 , V_292 ) ;
}
static void
F_150 ( struct V_1 * V_2 , int V_331 )
{
if ( V_331 == V_332 ) {
V_2 -> V_112 |= V_333 ;
F_75 ( V_2 ) ;
} else
V_2 -> V_112 &= ~ V_333 ;
}
void F_151 ( struct V_1 * V_2 , unsigned int V_165 ,
unsigned int V_334 )
{
struct V_5 * V_10 =
F_31 ( V_2 , struct V_5 , V_2 ) ;
F_39 ( V_10 , V_165 != 0 ) ;
}
static void
F_152 ( struct V_1 * V_2 , unsigned int V_165 ,
unsigned int V_334 )
{
if ( V_2 -> V_335 )
V_2 -> V_335 ( V_2 , V_165 , V_334 ) ;
else
F_151 ( V_2 , V_165 , V_334 ) ;
}
static unsigned int F_153 ( struct V_5 * V_336 )
{
if ( V_336 -> V_2 . V_22 == V_27 )
return 0x1000 ;
#ifdef F_144
if ( F_146 ( V_336 ) )
return 0x16 << V_336 -> V_2 . V_13 ;
#endif
return 8 << V_336 -> V_2 . V_13 ;
}
static int F_154 ( struct V_5 * V_6 )
{
unsigned int V_337 = F_153 ( V_6 ) ;
struct V_1 * V_2 = & V_6 -> V_2 ;
int V_223 = 0 ;
switch ( V_2 -> V_22 ) {
case V_27 :
case V_338 :
case V_25 :
case V_24 :
if ( ! V_2 -> V_122 )
break;
if ( ! F_155 ( V_2 -> V_122 , V_337 , L_21 ) ) {
V_223 = - V_339 ;
break;
}
if ( V_2 -> V_112 & V_340 ) {
V_2 -> V_14 = F_156 ( V_2 -> V_122 , V_337 ) ;
if ( ! V_2 -> V_14 ) {
F_157 ( V_2 -> V_122 , V_337 ) ;
V_223 = - V_231 ;
}
}
break;
case V_23 :
case V_341 :
if ( ! F_158 ( V_2 -> V_19 , V_337 , L_21 ) )
V_223 = - V_339 ;
break;
}
return V_223 ;
}
static void F_159 ( struct V_5 * V_6 )
{
unsigned int V_337 = F_153 ( V_6 ) ;
struct V_1 * V_2 = & V_6 -> V_2 ;
switch ( V_2 -> V_22 ) {
case V_27 :
case V_338 :
case V_25 :
case V_24 :
if ( ! V_2 -> V_122 )
break;
if ( V_2 -> V_112 & V_340 ) {
F_160 ( V_2 -> V_14 ) ;
V_2 -> V_14 = NULL ;
}
F_157 ( V_2 -> V_122 , V_337 ) ;
break;
case V_23 :
case V_341 :
F_161 ( V_2 -> V_19 , V_337 ) ;
break;
}
}
static int F_162 ( struct V_5 * V_6 )
{
unsigned long V_342 = V_343 << V_6 -> V_2 . V_13 ;
unsigned int V_337 = 8 << V_6 -> V_2 . V_13 ;
struct V_1 * V_2 = & V_6 -> V_2 ;
int V_223 = - V_344 ;
switch ( V_2 -> V_22 ) {
case V_23 :
case V_341 :
V_342 += V_2 -> V_19 ;
if ( F_158 ( V_342 , V_337 , L_25 ) )
V_223 = 0 ;
else
V_223 = - V_339 ;
break;
}
return V_223 ;
}
static void F_163 ( struct V_5 * V_6 )
{
unsigned long V_11 = V_343 << V_6 -> V_2 . V_13 ;
unsigned int V_337 = 8 << V_6 -> V_2 . V_13 ;
struct V_1 * V_2 = & V_6 -> V_2 ;
switch ( V_2 -> V_22 ) {
case V_23 :
case V_341 :
F_161 ( V_2 -> V_19 + V_11 , V_337 ) ;
break;
}
}
static void F_164 ( struct V_1 * V_2 )
{
struct V_5 * V_6 =
F_31 ( V_2 , struct V_5 , V_2 ) ;
F_159 ( V_6 ) ;
if ( V_2 -> type == V_59 )
F_163 ( V_6 ) ;
}
static int F_165 ( struct V_1 * V_2 )
{
struct V_5 * V_6 =
F_31 ( V_2 , struct V_5 , V_2 ) ;
int V_223 ;
if ( V_2 -> type == V_267 )
return - V_268 ;
V_223 = F_154 ( V_6 ) ;
if ( V_223 == 0 && V_2 -> type == V_59 ) {
V_223 = F_162 ( V_6 ) ;
if ( V_223 < 0 )
F_159 ( V_6 ) ;
}
return V_223 ;
}
static void F_166 ( struct V_1 * V_2 , int V_112 )
{
struct V_5 * V_6 =
F_31 ( V_2 , struct V_5 , V_2 ) ;
int V_116 = V_345 ;
int V_223 ;
if ( V_2 -> type == V_267 )
return;
V_223 = F_154 ( V_6 ) ;
if ( V_223 < 0 )
return;
V_223 = F_162 ( V_6 ) ;
if ( V_223 < 0 )
V_116 &= ~ V_129 ;
if ( V_2 -> V_22 != V_6 -> V_28 )
F_30 ( V_2 ) ;
if ( V_112 & V_346 )
F_57 ( V_6 , V_116 ) ;
if ( V_2 -> type == V_99 && V_2 -> V_22 == V_27 )
V_6 -> V_87 |= V_161 ;
if ( V_2 -> type != V_127 && V_112 & V_347 )
F_63 ( V_6 ) ;
if ( V_2 -> type != V_59 && V_116 & V_129 )
F_163 ( V_6 ) ;
if ( V_2 -> type == V_127 )
F_159 ( V_6 ) ;
}
static int
F_167 ( struct V_1 * V_2 , struct V_348 * V_349 )
{
if ( V_349 -> V_143 >= V_350 || V_349 -> V_143 < 0 ||
V_349 -> V_351 < 9600 || V_349 -> type < V_127 ||
V_349 -> type >= F_168 ( V_44 ) || V_349 -> type == V_352 ||
V_349 -> type == V_353 )
return - V_344 ;
return 0 ;
}
static const char *
F_169 ( struct V_1 * V_2 )
{
int type = V_2 -> type ;
if ( type >= F_168 ( V_44 ) )
type = 0 ;
return V_44 [ type ] . V_138 ;
}
void F_170 (
void (* F_171)( int V_2 , struct V_1 * V_6 , unsigned short * V_37 ) )
{
V_354 = F_171 ;
}
static void T_3 F_172 ( void )
{
struct V_5 * V_6 ;
static int V_355 = 1 ;
int V_130 , V_356 = 0 ;
if ( ! V_355 )
return;
V_355 = 0 ;
if ( V_357 > V_358 )
V_357 = V_358 ;
for ( V_130 = 0 ; V_130 < V_357 ; V_130 ++ ) {
struct V_5 * V_6 = & V_359 [ V_130 ] ;
struct V_1 * V_2 = & V_6 -> V_2 ;
V_2 -> line = V_130 ;
F_112 ( & V_2 -> V_60 ) ;
F_173 ( & V_6 -> V_234 ) ;
V_6 -> V_234 . V_281 = F_119 ;
V_6 -> V_28 = 0xFF ;
V_6 -> V_254 = ~ V_360 ;
V_6 -> V_255 = V_360 ;
V_2 -> V_361 = & V_362 ;
}
if ( V_363 )
V_356 = V_226 ;
for ( V_130 = 0 , V_6 = V_359 ;
V_130 < F_168 ( V_364 ) && V_130 < V_357 ;
V_130 ++ , V_6 ++ ) {
struct V_1 * V_2 = & V_6 -> V_2 ;
V_2 -> V_19 = V_364 [ V_130 ] . V_2 ;
V_2 -> V_143 = F_174 ( V_364 [ V_130 ] . V_143 ) ;
V_2 -> V_232 = V_364 [ V_130 ] . V_232 ;
V_2 -> V_57 = V_364 [ V_130 ] . V_351 * 16 ;
V_2 -> V_112 = V_364 [ V_130 ] . V_112 ;
V_2 -> V_18 = V_364 [ V_130 ] . V_18 ;
V_2 -> V_14 = V_364 [ V_130 ] . V_365 ;
V_2 -> V_22 = V_364 [ V_130 ] . V_366 ;
V_2 -> V_13 = V_364 [ V_130 ] . V_367 ;
F_30 ( V_2 ) ;
V_2 -> V_232 |= V_356 ;
if ( V_354 != NULL )
V_354 ( V_130 , & V_6 -> V_2 , & V_6 -> V_37 ) ;
}
}
static void
F_175 ( struct V_5 * V_6 , unsigned int type )
{
V_6 -> V_2 . type = type ;
V_6 -> V_2 . V_133 = V_44 [ type ] . V_134 ;
V_6 -> V_37 = V_44 [ type ] . V_112 ;
V_6 -> V_135 = V_44 [ type ] . V_135 ;
}
static void T_3
F_176 ( struct V_368 * V_369 , struct V_370 * V_371 )
{
int V_130 ;
for ( V_130 = 0 ; V_130 < V_357 ; V_130 ++ ) {
struct V_5 * V_6 = & V_359 [ V_130 ] ;
if ( V_6 -> V_2 . V_371 )
continue;
V_6 -> V_2 . V_371 = V_371 ;
if ( V_6 -> V_2 . V_112 & V_372 )
F_175 ( V_6 , V_6 -> V_2 . type ) ;
F_177 ( V_369 , & V_6 -> V_2 ) ;
}
}
static void F_178 ( struct V_1 * V_2 , int V_166 )
{
struct V_5 * V_6 =
F_31 ( V_2 , struct V_5 , V_2 ) ;
F_127 ( V_6 , V_157 ) ;
F_72 ( V_2 , V_71 , V_166 ) ;
}
static void
F_179 ( struct V_373 * V_374 , const char * V_375 , unsigned int V_67 )
{
struct V_5 * V_6 = & V_359 [ V_374 -> V_376 ] ;
struct V_1 * V_2 = & V_6 -> V_2 ;
unsigned long V_112 ;
unsigned int V_149 ;
int V_377 = 1 ;
F_128 () ;
F_180 ( V_112 ) ;
if ( V_2 -> V_378 ) {
V_377 = 0 ;
} else if ( V_379 ) {
V_377 = F_181 ( & V_2 -> V_60 ) ;
} else
F_85 ( & V_2 -> V_60 ) ;
V_149 = F_95 ( V_2 , V_51 ) ;
if ( V_6 -> V_37 & V_110 )
F_72 ( V_2 , V_51 , V_108 ) ;
else
F_72 ( V_2 , V_51 , 0 ) ;
F_182 ( V_2 , V_375 , V_67 , F_178 ) ;
F_127 ( V_6 , V_239 ) ;
F_72 ( V_2 , V_51 , V_149 ) ;
if ( V_6 -> V_193 )
F_90 ( V_6 ) ;
if ( V_377 )
F_83 ( & V_2 -> V_60 ) ;
F_183 ( V_112 ) ;
}
static int T_3 F_184 ( struct V_373 * V_374 , char * V_380 )
{
struct V_1 * V_2 ;
int V_288 = 9600 ;
int V_259 = 8 ;
int V_178 = 'n' ;
int V_381 = 'n' ;
if ( V_374 -> V_376 >= V_357 )
V_374 -> V_376 = 0 ;
V_2 = & V_359 [ V_374 -> V_376 ] . V_2 ;
if ( ! V_2 -> V_19 && ! V_2 -> V_14 )
return - V_268 ;
if ( V_380 )
F_185 ( V_380 , & V_288 , & V_178 , & V_259 , & V_381 ) ;
return F_186 ( V_2 , V_374 , V_288 , V_178 , V_259 , V_381 ) ;
}
static int F_187 ( void )
{
return F_188 () ;
}
static int T_3 F_189 ( void )
{
F_172 () ;
F_190 ( & V_382 ) ;
return 0 ;
}
int F_191 ( struct V_1 * V_10 )
{
int line ;
struct V_1 * V_2 ;
for ( line = 0 ; line < V_357 ; line ++ ) {
V_2 = & V_359 [ line ] . V_2 ;
if ( F_192 ( V_10 , V_2 ) )
return line ;
}
return - V_268 ;
}
int T_3 F_193 ( struct V_1 * V_2 )
{
struct V_1 * V_10 ;
if ( V_2 -> line >= F_168 ( V_359 ) )
return - V_268 ;
F_172 () ;
V_10 = & V_359 [ V_2 -> line ] . V_2 ;
V_10 -> V_19 = V_2 -> V_19 ;
V_10 -> V_14 = V_2 -> V_14 ;
V_10 -> V_143 = V_2 -> V_143 ;
V_10 -> V_232 = V_2 -> V_232 ;
V_10 -> V_57 = V_2 -> V_57 ;
V_10 -> V_133 = V_2 -> V_133 ;
V_10 -> V_13 = V_2 -> V_13 ;
V_10 -> V_22 = V_2 -> V_22 ;
V_10 -> V_112 = V_2 -> V_112 ;
V_10 -> V_122 = V_2 -> V_122 ;
V_10 -> V_383 = V_2 -> V_383 ;
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
F_195 ( & V_3 , & V_359 [ line ] . V_2 ) ;
}
void F_196 ( int line )
{
struct V_5 * V_6 = & V_359 [ line ] ;
struct V_1 * V_2 = & V_6 -> V_2 ;
if ( V_6 -> V_37 & V_103 ) {
F_72 ( V_2 , V_31 , 0xE0 ) ;
F_54 ( V_6 ) ;
F_72 ( V_2 , V_31 , 0 ) ;
V_2 -> V_57 = 921600 * 16 ;
}
F_197 ( & V_3 , V_2 ) ;
}
static int T_4 F_198 ( struct V_384 * V_371 )
{
struct V_385 * V_10 = V_371 -> V_371 . V_386 ;
struct V_5 V_387 ;
int V_223 , V_130 , V_356 = 0 ;
memset ( & V_387 , 0 , sizeof( V_387 ) ) ;
if ( V_363 )
V_356 = V_226 ;
for ( V_130 = 0 ; V_10 && V_10 -> V_112 != 0 ; V_10 ++ , V_130 ++ ) {
V_387 . V_2 . V_19 = V_10 -> V_19 ;
V_387 . V_2 . V_14 = V_10 -> V_14 ;
V_387 . V_2 . V_143 = V_10 -> V_143 ;
V_387 . V_2 . V_232 = V_10 -> V_232 ;
V_387 . V_2 . V_57 = V_10 -> V_57 ;
V_387 . V_2 . V_13 = V_10 -> V_13 ;
V_387 . V_2 . V_22 = V_10 -> V_22 ;
V_387 . V_2 . V_112 = V_10 -> V_112 ;
V_387 . V_2 . V_122 = V_10 -> V_122 ;
V_387 . V_2 . V_18 = V_10 -> V_18 ;
V_387 . V_2 . V_383 = V_10 -> V_383 ;
V_387 . V_2 . type = V_10 -> type ;
V_387 . V_2 . F_3 = V_10 -> F_3 ;
V_387 . V_2 . F_5 = V_10 -> F_5 ;
V_387 . V_2 . V_29 = V_10 -> V_29 ;
V_387 . V_2 . V_388 = V_10 -> V_388 ;
V_387 . V_2 . V_330 = V_10 -> V_330 ;
V_387 . V_2 . V_335 = V_10 -> V_335 ;
V_387 . V_2 . V_371 = & V_371 -> V_371 ;
V_387 . V_2 . V_232 |= V_356 ;
V_223 = F_199 ( & V_387 ) ;
if ( V_223 < 0 ) {
F_200 ( & V_371 -> V_371 , L_26
L_27 , V_130 ,
V_10 -> V_19 , ( unsigned long long ) V_10 -> V_122 ,
V_10 -> V_143 , V_223 ) ;
}
}
return 0 ;
}
static int T_5 F_201 ( struct V_384 * V_371 )
{
int V_130 ;
for ( V_130 = 0 ; V_130 < V_357 ; V_130 ++ ) {
struct V_5 * V_6 = & V_359 [ V_130 ] ;
if ( V_6 -> V_2 . V_371 == & V_371 -> V_371 )
F_202 ( V_130 ) ;
}
return 0 ;
}
static int F_203 ( struct V_384 * V_371 , T_6 V_165 )
{
int V_130 ;
for ( V_130 = 0 ; V_130 < V_358 ; V_130 ++ ) {
struct V_5 * V_6 = & V_359 [ V_130 ] ;
if ( V_6 -> V_2 . type != V_127 && V_6 -> V_2 . V_371 == & V_371 -> V_371 )
F_195 ( & V_3 , & V_6 -> V_2 ) ;
}
return 0 ;
}
static int F_204 ( struct V_384 * V_371 )
{
int V_130 ;
for ( V_130 = 0 ; V_130 < V_358 ; V_130 ++ ) {
struct V_5 * V_6 = & V_359 [ V_130 ] ;
if ( V_6 -> V_2 . type != V_127 && V_6 -> V_2 . V_371 == & V_371 -> V_371 )
F_196 ( V_130 ) ;
}
return 0 ;
}
static struct V_5 * F_205 ( struct V_1 * V_2 )
{
int V_130 ;
for ( V_130 = 0 ; V_130 < V_357 ; V_130 ++ )
if ( F_192 ( & V_359 [ V_130 ] . V_2 , V_2 ) )
return & V_359 [ V_130 ] ;
for ( V_130 = 0 ; V_130 < V_357 ; V_130 ++ )
if ( V_359 [ V_130 ] . V_2 . type == V_127 &&
V_359 [ V_130 ] . V_2 . V_19 == 0 )
return & V_359 [ V_130 ] ;
for ( V_130 = 0 ; V_130 < V_357 ; V_130 ++ )
if ( V_359 [ V_130 ] . V_2 . type == V_127 )
return & V_359 [ V_130 ] ;
return NULL ;
}
int F_199 ( struct V_5 * V_6 )
{
struct V_5 * V_387 ;
int V_223 = - V_389 ;
if ( V_6 -> V_2 . V_57 == 0 )
return - V_344 ;
F_107 ( & V_390 ) ;
V_387 = F_205 ( & V_6 -> V_2 ) ;
if ( V_387 && V_387 -> V_2 . type != V_267 ) {
if ( V_387 -> V_2 . V_371 )
F_206 ( & V_3 , & V_387 -> V_2 ) ;
V_387 -> V_2 . V_19 = V_6 -> V_2 . V_19 ;
V_387 -> V_2 . V_14 = V_6 -> V_2 . V_14 ;
V_387 -> V_2 . V_143 = V_6 -> V_2 . V_143 ;
V_387 -> V_2 . V_232 = V_6 -> V_2 . V_232 ;
V_387 -> V_2 . V_57 = V_6 -> V_2 . V_57 ;
V_387 -> V_2 . V_133 = V_6 -> V_2 . V_133 ;
V_387 -> V_2 . V_13 = V_6 -> V_2 . V_13 ;
V_387 -> V_2 . V_22 = V_6 -> V_2 . V_22 ;
V_387 -> V_2 . V_112 = V_6 -> V_2 . V_112 | V_391 ;
V_387 -> V_87 = V_6 -> V_87 ;
V_387 -> V_2 . V_122 = V_6 -> V_2 . V_122 ;
V_387 -> V_2 . V_383 = V_6 -> V_2 . V_383 ;
if ( V_6 -> V_2 . V_371 )
V_387 -> V_2 . V_371 = V_6 -> V_2 . V_371 ;
if ( V_6 -> V_2 . V_112 & V_372 )
F_175 ( V_387 , V_6 -> V_2 . type ) ;
F_30 ( & V_387 -> V_2 ) ;
if ( V_6 -> V_2 . F_3 )
V_387 -> V_2 . F_3 = V_6 -> V_2 . F_3 ;
if ( V_6 -> V_2 . F_5 )
V_387 -> V_2 . F_5 = V_6 -> V_2 . F_5 ;
if ( V_6 -> V_2 . V_29 )
V_387 -> V_2 . V_29 = V_6 -> V_2 . V_29 ;
if ( V_6 -> V_2 . V_330 )
V_387 -> V_2 . V_330 = V_6 -> V_2 . V_330 ;
if ( V_6 -> V_2 . V_335 )
V_387 -> V_2 . V_335 = V_6 -> V_2 . V_335 ;
if ( V_6 -> V_2 . V_388 )
V_387 -> V_2 . V_388 = V_6 -> V_2 . V_388 ;
if ( V_6 -> V_20 )
V_387 -> V_20 = V_6 -> V_20 ;
if ( V_6 -> V_21 )
V_387 -> V_21 = V_6 -> V_21 ;
if ( V_354 != NULL )
V_354 ( 0 , & V_387 -> V_2 ,
& V_387 -> V_37 ) ;
V_223 = F_177 ( & V_3 , & V_387 -> V_2 ) ;
if ( V_223 == 0 )
V_223 = V_387 -> V_2 . line ;
}
F_111 ( & V_390 ) ;
return V_223 ;
}
void F_202 ( int line )
{
struct V_5 * V_387 = & V_359 [ line ] ;
F_107 ( & V_390 ) ;
F_206 ( & V_3 , & V_387 -> V_2 ) ;
if ( V_392 ) {
V_387 -> V_2 . V_112 &= ~ V_391 ;
V_387 -> V_2 . type = V_127 ;
V_387 -> V_2 . V_371 = & V_392 -> V_371 ;
V_387 -> V_37 = V_44 [ V_387 -> V_2 . type ] . V_112 ;
F_177 ( & V_3 , & V_387 -> V_2 ) ;
} else {
V_387 -> V_2 . V_371 = NULL ;
}
F_111 ( & V_390 ) ;
}
static int T_3 F_207 ( void )
{
int V_223 ;
F_172 () ;
F_62 ( V_270 L_28
L_29 , V_357 ,
V_363 ? L_30 : L_31 ) ;
#ifdef F_208
V_223 = F_209 ( & V_3 , V_358 ) ;
#else
V_3 . V_393 = V_358 ;
V_223 = F_210 ( & V_3 ) ;
#endif
if ( V_223 )
goto V_124;
V_223 = F_211 () ;
if ( V_223 )
goto V_394;
V_392 = F_212 ( L_32 ,
V_395 ) ;
if ( ! V_392 ) {
V_223 = - V_231 ;
goto V_396;
}
V_223 = F_213 ( V_392 ) ;
if ( V_223 )
goto V_397;
F_176 ( & V_3 , & V_392 -> V_371 ) ;
V_223 = F_214 ( & V_398 ) ;
if ( V_223 == 0 )
goto V_124;
F_215 ( V_392 ) ;
V_397:
F_216 ( V_392 ) ;
V_396:
F_217 () ;
V_394:
#ifdef F_208
F_218 ( & V_3 , V_358 ) ;
#else
F_219 ( & V_3 ) ;
#endif
V_124:
return V_223 ;
}
static void T_7 F_220 ( void )
{
struct V_384 * V_399 = V_392 ;
V_392 = NULL ;
F_221 ( & V_398 ) ;
F_222 ( V_399 ) ;
F_217 () ;
#ifdef F_208
F_218 ( & V_3 , V_358 ) ;
#else
F_219 ( & V_3 ) ;
#endif
}
