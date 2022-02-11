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
if ( ! V_2 -> V_19 && ! V_2 -> V_121 && ! V_2 -> V_14 )
return;
F_51 ( L_9 ,
F_1 ( V_2 ) , V_2 -> V_19 , V_2 -> V_14 ) ;
F_58 ( & V_2 -> V_60 , V_112 ) ;
V_6 -> V_37 = 0 ;
V_6 -> V_87 = 0 ;
if ( ! ( V_2 -> V_112 & V_122 ) ) {
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
F_51 ( L_10 ,
V_117 , V_118 ) ;
goto V_123;
}
}
V_120 = F_3 ( V_6 , V_68 ) ;
V_119 = F_3 ( V_6 , V_31 ) ;
if ( ! ( V_2 -> V_112 & V_124 ) ) {
F_5 ( V_6 , V_68 , V_69 | 0x0A ) ;
V_93 = F_3 ( V_6 , V_125 ) & 0xF0 ;
F_5 ( V_6 , V_68 , V_120 ) ;
if ( V_93 != 0x90 ) {
F_51 ( L_11 ,
V_93 ) ;
goto V_123;
}
}
F_5 ( V_6 , V_31 , V_48 ) ;
F_5 ( V_6 , V_49 , 0 ) ;
F_5 ( V_6 , V_31 , 0 ) ;
F_5 ( V_6 , V_39 , V_40 ) ;
V_92 = F_3 ( V_6 , V_105 ) >> 6 ;
F_51 ( L_12 , V_92 ) ;
switch ( V_92 ) {
case 0 :
F_52 ( V_6 ) ;
break;
case 1 :
V_2 -> type = V_126 ;
break;
case 2 :
V_2 -> type = V_127 ;
break;
case 3 :
F_56 ( V_6 ) ;
break;
}
#ifdef F_60
if ( V_2 -> type == V_99 && V_116 & V_128 ) {
int V_129 ;
for ( V_129 = 0 ; V_129 < V_130 ; ++ V_129 ) {
if ( V_131 [ V_129 ] == V_2 -> V_19 && F_40 ( V_6 ) ) {
V_2 -> type = V_59 ;
break;
}
}
}
#endif
F_5 ( V_6 , V_31 , V_119 ) ;
if ( V_6 -> V_37 != V_44 [ V_2 -> type ] . V_112 ) {
F_61 ( V_132
L_13 ,
F_1 ( V_2 ) , V_6 -> V_37 ,
V_44 [ V_2 -> type ] . V_112 ) ;
}
V_2 -> V_133 = V_44 [ V_6 -> V_2 . type ] . V_134 ;
V_6 -> V_37 = V_44 [ V_2 -> type ] . V_112 ;
V_6 -> V_135 = V_44 [ V_2 -> type ] . V_135 ;
if ( V_2 -> type == V_126 )
goto V_123;
#ifdef F_60
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
V_123:
F_62 ( & V_2 -> V_60 , V_112 ) ;
F_51 ( L_14 , V_44 [ V_2 -> type ] . V_136 ) ;
}
static void F_63 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = & V_6 -> V_2 ;
unsigned char V_120 , V_137 ;
unsigned char V_138 = 0 ;
unsigned int V_139 = 0 ;
unsigned long V_140 ;
int V_141 ;
if ( V_2 -> V_112 & V_142 ) {
V_139 = ( V_2 -> V_19 & 0xfe0 ) | 0x1f ;
V_138 = F_64 ( V_139 ) ;
F_65 ( 0x80 , V_139 ) ;
F_64 ( V_139 ) ;
}
F_66 ( F_67 () ) ;
V_120 = F_3 ( V_6 , V_68 ) ;
V_137 = F_3 ( V_6 , V_51 ) ;
F_5 ( V_6 , V_68 , V_143 | V_144 ) ;
V_140 = F_67 () ;
F_5 ( V_6 , V_68 , 0 ) ;
F_68 ( 10 ) ;
if ( V_2 -> V_112 & V_142 ) {
F_5 ( V_6 , V_68 ,
V_145 | V_146 ) ;
} else {
F_5 ( V_6 , V_68 ,
V_145 | V_146 | V_144 ) ;
}
F_5 ( V_6 , V_51 , 0x0f ) ;
F_3 ( V_6 , V_72 ) ;
F_3 ( V_6 , V_74 ) ;
F_3 ( V_6 , V_105 ) ;
F_3 ( V_6 , V_125 ) ;
F_5 ( V_6 , V_71 , 0xFF ) ;
F_68 ( 20 ) ;
V_141 = F_66 ( V_140 ) ;
F_5 ( V_6 , V_68 , V_120 ) ;
F_5 ( V_6 , V_51 , V_137 ) ;
if ( V_2 -> V_112 & V_142 )
F_65 ( V_138 , V_139 ) ;
V_2 -> V_141 = ( V_141 > 0 ) ? V_141 : 0 ;
}
static inline void F_69 ( struct V_5 * V_10 )
{
if ( V_10 -> V_147 & V_148 ) {
V_10 -> V_147 &= ~ V_148 ;
F_5 ( V_10 , V_51 , V_10 -> V_147 ) ;
}
}
static void F_70 ( struct V_1 * V_2 )
{
struct V_5 * V_6 =
F_31 ( V_2 , struct V_5 , V_2 ) ;
F_69 ( V_6 ) ;
if ( V_2 -> type == V_86 ) {
V_6 -> V_35 |= V_149 ;
F_35 ( V_6 , V_34 , V_6 -> V_35 ) ;
}
}
static void F_71 ( struct V_1 * V_2 )
{
struct V_5 * V_6 =
F_31 ( V_2 , struct V_5 , V_2 ) ;
if ( ! ( V_6 -> V_147 & V_148 ) ) {
V_6 -> V_147 |= V_148 ;
F_72 ( V_2 , V_51 , V_6 -> V_147 ) ;
if ( V_6 -> V_87 & V_150 ) {
unsigned char V_151 ;
V_151 = F_3 ( V_6 , V_72 ) ;
V_6 -> V_152 |= V_151 & V_153 ;
if ( ( V_2 -> type == V_154 ) ?
( V_151 & V_155 ) :
( V_151 & V_156 ) )
F_73 ( V_6 ) ;
}
}
if ( V_2 -> type == V_86 && V_6 -> V_35 & V_149 ) {
V_6 -> V_35 &= ~ V_149 ;
F_35 ( V_6 , V_34 , V_6 -> V_35 ) ;
}
}
static void F_74 ( struct V_1 * V_2 )
{
struct V_5 * V_6 =
F_31 ( V_2 , struct V_5 , V_2 ) ;
V_6 -> V_147 &= ~ V_157 ;
V_6 -> V_2 . V_158 &= ~ V_73 ;
F_72 ( V_2 , V_51 , V_6 -> V_147 ) ;
}
static void F_75 ( struct V_1 * V_2 )
{
struct V_5 * V_6 =
F_31 ( V_2 , struct V_5 , V_2 ) ;
if ( V_6 -> V_87 & V_159 )
return;
V_6 -> V_147 |= V_160 ;
F_72 ( V_2 , V_51 , V_6 -> V_147 ) ;
}
unsigned char
F_76 ( struct V_5 * V_6 , unsigned char V_151 )
{
struct V_1 * V_2 = & V_6 -> V_2 ;
struct V_161 * V_162 = V_2 -> V_163 -> V_2 . V_162 ;
unsigned char V_164 ;
int V_165 = 256 ;
char V_166 ;
do {
if ( F_77 ( V_151 & V_73 ) )
V_164 = F_3 ( V_6 , V_74 ) ;
else
V_164 = 0 ;
V_166 = V_167 ;
V_2 -> V_168 . V_169 ++ ;
V_151 |= V_6 -> V_152 ;
V_6 -> V_152 = 0 ;
if ( F_78 ( V_151 & V_170 ) ) {
if ( V_151 & V_171 ) {
V_151 &= ~ ( V_172 | V_173 ) ;
V_2 -> V_168 . V_174 ++ ;
if ( F_79 ( V_2 ) )
goto V_175;
} else if ( V_151 & V_173 )
V_2 -> V_168 . V_176 ++ ;
else if ( V_151 & V_172 )
V_2 -> V_168 . V_177 ++ ;
if ( V_151 & V_178 )
V_2 -> V_168 . V_179 ++ ;
V_151 &= V_2 -> V_158 ;
if ( V_151 & V_171 ) {
F_80 ( L_15 ) ;
V_166 = V_180 ;
} else if ( V_151 & V_173 )
V_166 = V_181 ;
else if ( V_151 & V_172 )
V_166 = V_182 ;
}
if ( F_81 ( V_2 , V_164 ) )
goto V_175;
F_82 ( V_2 , V_151 , V_178 , V_164 , V_166 ) ;
V_175:
V_151 = F_3 ( V_6 , V_72 ) ;
} while ( ( V_151 & ( V_73 | V_171 ) ) && ( V_165 -- > 0 ) );
F_83 ( & V_2 -> V_60 ) ;
F_84 ( V_162 ) ;
F_85 ( & V_2 -> V_60 ) ;
return V_151 ;
}
void F_73 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = & V_6 -> V_2 ;
struct V_183 * V_184 = & V_2 -> V_163 -> V_184 ;
int V_67 ;
if ( V_2 -> V_185 ) {
F_5 ( V_6 , V_71 , V_2 -> V_185 ) ;
V_2 -> V_168 . V_186 ++ ;
V_2 -> V_185 = 0 ;
return;
}
if ( F_86 ( V_2 ) ) {
F_70 ( V_2 ) ;
return;
}
if ( F_87 ( V_184 ) ) {
F_69 ( V_6 ) ;
return;
}
V_67 = V_6 -> V_135 ;
do {
F_5 ( V_6 , V_71 , V_184 -> V_187 [ V_184 -> V_188 ] ) ;
V_184 -> V_188 = ( V_184 -> V_188 + 1 ) & ( V_189 - 1 ) ;
V_2 -> V_168 . V_186 ++ ;
if ( F_87 ( V_184 ) )
break;
} while ( -- V_67 > 0 );
if ( F_88 ( V_184 ) < V_190 )
F_89 ( V_2 ) ;
F_80 ( L_16 ) ;
if ( F_87 ( V_184 ) )
F_69 ( V_6 ) ;
}
unsigned int F_90 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = & V_6 -> V_2 ;
unsigned int V_97 = F_3 ( V_6 , V_125 ) ;
V_97 |= V_6 -> V_191 ;
V_6 -> V_191 = 0 ;
if ( V_97 & V_192 && V_6 -> V_147 & V_160 &&
V_2 -> V_163 != NULL ) {
if ( V_97 & V_193 )
V_2 -> V_168 . V_194 ++ ;
if ( V_97 & V_195 )
V_2 -> V_168 . V_196 ++ ;
if ( V_97 & V_197 )
F_91 ( V_2 , V_97 & V_198 ) ;
if ( V_97 & V_199 )
F_92 ( V_2 , V_97 & V_200 ) ;
F_93 ( & V_2 -> V_163 -> V_2 . V_201 ) ;
}
return V_97 ;
}
int F_94 ( struct V_1 * V_2 , unsigned int V_202 )
{
unsigned char V_97 ;
unsigned long V_112 ;
struct V_5 * V_6 =
F_31 ( V_2 , struct V_5 , V_2 ) ;
if ( V_202 & V_203 )
return 0 ;
F_58 ( & V_2 -> V_60 , V_112 ) ;
V_97 = F_95 ( V_2 , V_72 ) ;
F_80 ( L_17 , V_97 ) ;
if ( V_97 & ( V_73 | V_171 ) )
V_97 = F_76 ( V_6 , V_97 ) ;
F_90 ( V_6 ) ;
if ( V_97 & V_155 )
F_73 ( V_6 ) ;
F_62 ( & V_2 -> V_60 , V_112 ) ;
return 1 ;
}
static int V_30 ( struct V_1 * V_2 )
{
unsigned int V_202 = F_95 ( V_2 , V_105 ) ;
return F_94 ( V_2 , V_202 ) ;
}
static T_2 F_96 ( int V_141 , void * V_204 )
{
struct V_205 * V_129 = V_204 ;
struct V_206 * V_207 , * V_208 = NULL ;
int V_209 = 0 , V_210 = 0 ;
F_80 ( L_18 , V_141 ) ;
F_85 ( & V_129 -> V_60 ) ;
V_207 = V_129 -> V_211 ;
do {
struct V_5 * V_6 ;
struct V_1 * V_2 ;
V_6 = F_97 ( V_207 , struct V_5 , V_212 ) ;
V_2 = & V_6 -> V_2 ;
if ( V_2 -> V_29 ( V_2 ) ) {
V_210 = 1 ;
V_208 = NULL ;
} else if ( V_208 == NULL )
V_208 = V_207 ;
V_207 = V_207 -> V_213 ;
if ( V_207 == V_129 -> V_211 && V_209 ++ > V_214 ) {
F_98 ( V_215
L_19 , V_141 ) ;
break;
}
} while ( V_207 != V_208 );
F_83 ( & V_129 -> V_60 ) ;
F_80 ( L_20 ) ;
return F_99 ( V_210 ) ;
}
static void F_100 ( struct V_205 * V_129 , struct V_5 * V_6 )
{
F_42 ( & V_129 -> V_60 ) ;
if ( ! F_101 ( V_129 -> V_211 ) ) {
if ( V_129 -> V_211 == & V_6 -> V_212 )
V_129 -> V_211 = V_129 -> V_211 -> V_213 ;
F_102 ( & V_6 -> V_212 ) ;
} else {
F_103 ( V_129 -> V_211 != & V_6 -> V_212 ) ;
V_129 -> V_211 = NULL ;
}
F_43 ( & V_129 -> V_60 ) ;
if ( V_129 -> V_211 == NULL ) {
F_104 ( & V_129 -> V_216 ) ;
F_105 ( V_129 ) ;
}
}
static int F_106 ( struct V_5 * V_6 )
{
struct V_217 * V_218 ;
struct V_219 * V_220 ;
struct V_205 * V_129 ;
int V_221 , V_222 = V_6 -> V_2 . V_112 & V_223 ? V_224 : 0 ;
F_107 ( & V_225 ) ;
V_218 = & V_226 [ V_6 -> V_2 . V_141 % V_227 ] ;
F_108 (n, h) {
V_129 = F_109 ( V_220 , struct V_205 , V_216 ) ;
if ( V_129 -> V_141 == V_6 -> V_2 . V_141 )
break;
}
if ( V_220 == NULL ) {
V_129 = F_110 ( sizeof( struct V_205 ) , V_228 ) ;
if ( V_129 == NULL ) {
F_111 ( & V_225 ) ;
return - V_229 ;
}
F_112 ( & V_129 -> V_60 ) ;
V_129 -> V_141 = V_6 -> V_2 . V_141 ;
F_113 ( & V_129 -> V_216 , V_218 ) ;
}
F_111 ( & V_225 ) ;
F_42 ( & V_129 -> V_60 ) ;
if ( V_129 -> V_211 ) {
F_114 ( & V_6 -> V_212 , V_129 -> V_211 ) ;
F_43 ( & V_129 -> V_60 ) ;
V_221 = 0 ;
} else {
F_115 ( & V_6 -> V_212 ) ;
V_129 -> V_211 = & V_6 -> V_212 ;
F_43 ( & V_129 -> V_60 ) ;
V_222 |= V_6 -> V_2 . V_230 ;
V_221 = F_116 ( V_6 -> V_2 . V_141 , F_96 ,
V_222 , L_21 , V_129 ) ;
if ( V_221 < 0 )
F_100 ( V_129 , V_6 ) ;
}
return V_221 ;
}
static void F_117 ( struct V_5 * V_6 )
{
struct V_205 * V_129 ;
struct V_219 * V_220 ;
struct V_217 * V_218 ;
F_107 ( & V_225 ) ;
V_218 = & V_226 [ V_6 -> V_2 . V_141 % V_227 ] ;
F_108 (n, h) {
V_129 = F_109 ( V_220 , struct V_205 , V_216 ) ;
if ( V_129 -> V_141 == V_6 -> V_2 . V_141 )
break;
}
F_103 ( V_220 == NULL ) ;
F_103 ( V_129 -> V_211 == NULL ) ;
if ( F_101 ( V_129 -> V_211 ) )
F_118 ( V_6 -> V_2 . V_141 , V_129 ) ;
F_100 ( V_129 , V_6 ) ;
F_111 ( & V_225 ) ;
}
static void F_119 ( unsigned long V_231 )
{
struct V_5 * V_6 = (struct V_5 * ) V_231 ;
V_6 -> V_2 . V_29 ( & V_6 -> V_2 ) ;
F_120 ( & V_6 -> V_232 , V_233 + F_121 ( & V_6 -> V_2 ) ) ;
}
static void F_122 ( unsigned long V_231 )
{
struct V_5 * V_6 = (struct V_5 * ) V_231 ;
unsigned int V_202 , V_147 = 0 , V_151 ;
unsigned long V_112 ;
F_58 ( & V_6 -> V_2 . V_60 , V_112 ) ;
if ( V_6 -> V_2 . V_141 ) {
V_147 = F_3 ( V_6 , V_51 ) ;
F_5 ( V_6 , V_51 , 0 ) ;
}
V_202 = F_3 ( V_6 , V_105 ) ;
V_151 = F_3 ( V_6 , V_72 ) ;
V_6 -> V_152 |= V_151 & V_153 ;
if ( ( V_202 & V_203 ) && ( V_6 -> V_147 & V_148 ) &&
( ! F_87 ( & V_6 -> V_2 . V_163 -> V_184 ) || V_6 -> V_2 . V_185 ) &&
( V_151 & V_155 ) ) {
V_202 &= ~ ( V_234 | V_203 ) ;
V_202 |= V_235 ;
}
if ( ! ( V_202 & V_203 ) )
F_73 ( V_6 ) ;
if ( V_6 -> V_2 . V_141 )
F_5 ( V_6 , V_51 , V_147 ) ;
F_62 ( & V_6 -> V_2 . V_60 , V_112 ) ;
F_120 ( & V_6 -> V_232 ,
V_233 + F_121 ( & V_6 -> V_2 ) + V_236 / 5 ) ;
}
static unsigned int F_123 ( struct V_1 * V_2 )
{
struct V_5 * V_6 =
F_31 ( V_2 , struct V_5 , V_2 ) ;
unsigned long V_112 ;
unsigned int V_151 ;
F_58 ( & V_2 -> V_60 , V_112 ) ;
V_151 = F_95 ( V_2 , V_72 ) ;
V_6 -> V_152 |= V_151 & V_153 ;
F_62 ( & V_2 -> V_60 , V_112 ) ;
return ( V_151 & V_237 ) == V_237 ? V_238 : 0 ;
}
static unsigned int F_124 ( struct V_1 * V_2 )
{
struct V_5 * V_6 =
F_31 ( V_2 , struct V_5 , V_2 ) ;
unsigned int V_97 ;
unsigned int V_221 ;
V_97 = F_90 ( V_6 ) ;
V_221 = 0 ;
if ( V_97 & V_198 )
V_221 |= V_239 ;
if ( V_97 & V_240 )
V_221 |= V_241 ;
if ( V_97 & V_242 )
V_221 |= V_243 ;
if ( V_97 & V_200 )
V_221 |= V_244 ;
return V_221 ;
}
static void F_125 ( struct V_1 * V_2 , unsigned int V_245 )
{
struct V_5 * V_6 =
F_31 ( V_2 , struct V_5 , V_2 ) ;
unsigned char V_246 = 0 ;
if ( V_245 & V_247 )
V_246 |= V_146 ;
if ( V_245 & V_248 )
V_246 |= V_145 ;
if ( V_245 & V_249 )
V_246 |= V_143 ;
if ( V_245 & V_250 )
V_246 |= V_144 ;
if ( V_245 & V_251 )
V_246 |= V_69 ;
V_246 = ( V_246 & V_6 -> V_252 ) | V_6 -> V_253 | V_6 -> V_246 ;
F_72 ( V_2 , V_68 , V_246 ) ;
}
static void F_126 ( struct V_1 * V_2 , int V_254 )
{
struct V_5 * V_6 =
F_31 ( V_2 , struct V_5 , V_2 ) ;
unsigned long V_112 ;
F_58 ( & V_2 -> V_60 , V_112 ) ;
if ( V_254 == - 1 )
V_6 -> V_255 |= V_256 ;
else
V_6 -> V_255 &= ~ V_256 ;
F_72 ( V_2 , V_31 , V_6 -> V_255 ) ;
F_62 ( & V_2 -> V_60 , V_112 ) ;
}
static void F_127 ( struct V_5 * V_6 , int V_257 )
{
unsigned int V_97 , V_258 = 10000 ;
for (; ; ) {
V_97 = F_3 ( V_6 , V_72 ) ;
V_6 -> V_152 |= V_97 & V_153 ;
if ( ( V_97 & V_257 ) == V_257 )
break;
if ( -- V_258 == 0 )
break;
F_68 ( 1 ) ;
}
if ( V_6 -> V_2 . V_112 & V_259 ) {
unsigned int V_258 ;
for ( V_258 = 1000000 ; V_258 ; V_258 -- ) {
unsigned int V_260 = F_3 ( V_6 , V_125 ) ;
V_6 -> V_191 |= V_260 & V_261 ;
if ( V_260 & V_200 )
break;
F_68 ( 1 ) ;
F_128 () ;
}
}
}
static int F_129 ( struct V_1 * V_2 )
{
unsigned char V_151 = F_95 ( V_2 , V_72 ) ;
if ( ! ( V_151 & V_73 ) )
return V_262 ;
return F_95 ( V_2 , V_74 ) ;
}
static void F_130 ( struct V_1 * V_2 ,
unsigned char V_263 )
{
unsigned int V_147 ;
struct V_5 * V_6 =
F_31 ( V_2 , struct V_5 , V_2 ) ;
V_147 = F_95 ( V_2 , V_51 ) ;
if ( V_6 -> V_37 & V_110 )
F_72 ( V_2 , V_51 , V_108 ) ;
else
F_72 ( V_2 , V_51 , 0 ) ;
F_127 ( V_6 , V_237 ) ;
F_72 ( V_2 , V_71 , V_263 ) ;
if ( V_263 == 10 ) {
F_127 ( V_6 , V_237 ) ;
F_72 ( V_2 , V_71 , 13 ) ;
}
F_127 ( V_6 , V_237 ) ;
F_72 ( V_2 , V_51 , V_147 ) ;
}
static int F_131 ( struct V_1 * V_2 )
{
struct V_5 * V_6 =
F_31 ( V_2 , struct V_5 , V_2 ) ;
unsigned long V_112 ;
unsigned char V_151 , V_202 ;
int V_264 ;
V_2 -> V_133 = V_44 [ V_6 -> V_2 . type ] . V_134 ;
V_6 -> V_135 = V_44 [ V_6 -> V_2 . type ] . V_135 ;
V_6 -> V_37 = V_44 [ V_6 -> V_2 . type ] . V_112 ;
V_6 -> V_246 = 0 ;
if ( V_2 -> V_22 != V_6 -> V_28 )
F_30 ( V_2 ) ;
if ( V_2 -> type == V_86 ) {
V_6 -> V_35 = 0 ;
F_72 ( V_2 , V_31 , V_48 ) ;
F_72 ( V_2 , V_49 , V_50 ) ;
F_72 ( V_2 , V_51 , 0 ) ;
F_72 ( V_2 , V_31 , 0 ) ;
F_35 ( V_6 , V_265 , 0 ) ;
F_72 ( V_2 , V_31 , V_48 ) ;
F_72 ( V_2 , V_49 , V_50 ) ;
F_72 ( V_2 , V_31 , 0 ) ;
}
#ifdef F_60
F_41 ( V_6 ) ;
#endif
F_37 ( V_6 ) ;
F_95 ( V_2 , V_72 ) ;
F_95 ( V_2 , V_74 ) ;
F_95 ( V_2 , V_105 ) ;
F_95 ( V_2 , V_125 ) ;
if ( ! ( V_2 -> V_112 & V_122 ) &&
( F_95 ( V_2 , V_72 ) == 0xff ) ) {
F_98 ( V_266 L_22 ,
F_1 ( V_2 ) ) ;
return - V_267 ;
}
if ( V_2 -> type == V_89 ) {
unsigned char V_268 ;
F_5 ( V_6 , V_31 , V_48 ) ;
V_268 = F_3 ( V_6 , V_269 ) & ~ ( V_270 | V_271 ) ;
F_72 ( V_2 , V_269 ,
V_268 | V_272 | V_270 ) ;
F_72 ( V_2 , V_273 , V_274 ) ;
F_72 ( V_2 , V_269 ,
V_268 | V_272 | V_271 ) ;
F_72 ( V_2 , V_273 , V_274 ) ;
F_72 ( V_2 , V_31 , 0 ) ;
}
if ( V_2 -> V_141 ) {
unsigned char V_275 ;
F_58 ( & V_2 -> V_60 , V_112 ) ;
if ( V_6 -> V_2 . V_230 & V_224 )
F_132 ( V_2 -> V_141 ) ;
F_127 ( V_6 , V_155 ) ;
F_34 ( V_2 , V_51 , V_148 ) ;
F_68 ( 1 ) ;
V_275 = F_95 ( V_2 , V_105 ) ;
F_72 ( V_2 , V_51 , 0 ) ;
F_34 ( V_2 , V_51 , V_148 ) ;
F_68 ( 1 ) ;
V_202 = F_95 ( V_2 , V_105 ) ;
F_72 ( V_2 , V_51 , 0 ) ;
if ( V_2 -> V_230 & V_224 )
F_133 ( V_2 -> V_141 ) ;
F_62 ( & V_2 -> V_60 , V_112 ) ;
if ( ( ! ( V_275 & V_203 ) && ( V_202 & V_203 ) ) ||
V_6 -> V_2 . V_112 & V_276 ) {
V_6 -> V_87 |= V_277 ;
F_134 ( L_23 ,
F_1 ( V_2 ) ) ;
}
}
if ( V_6 -> V_87 & V_277 ) {
V_6 -> V_232 . V_278 = F_122 ;
V_6 -> V_232 . V_231 = ( unsigned long ) V_6 ;
F_120 ( & V_6 -> V_232 , V_233 +
F_121 ( V_2 ) + V_236 / 5 ) ;
}
if ( ! V_2 -> V_141 ) {
V_6 -> V_232 . V_231 = ( unsigned long ) V_6 ;
F_120 ( & V_6 -> V_232 , V_233 + F_121 ( V_2 ) ) ;
} else {
V_264 = F_106 ( V_6 ) ;
if ( V_264 )
return V_264 ;
}
F_72 ( V_2 , V_31 , V_279 ) ;
F_58 ( & V_2 -> V_60 , V_112 ) ;
if ( V_6 -> V_2 . V_112 & V_142 ) {
if ( ! V_6 -> V_2 . V_141 )
V_6 -> V_2 . V_245 |= V_249 ;
} else
if ( V_2 -> V_141 )
V_6 -> V_2 . V_245 |= V_250 ;
F_125 ( V_2 , V_2 -> V_245 ) ;
if ( V_280 || V_6 -> V_2 . V_112 & V_281 )
goto V_282;
F_72 ( V_2 , V_51 , V_148 ) ;
V_151 = F_95 ( V_2 , V_72 ) ;
V_202 = F_95 ( V_2 , V_105 ) ;
F_72 ( V_2 , V_51 , 0 ) ;
if ( V_151 & V_156 && V_202 & V_203 ) {
if ( ! ( V_6 -> V_87 & V_150 ) ) {
V_6 -> V_87 |= V_150 ;
F_134 ( L_24 ,
F_1 ( V_2 ) ) ;
}
} else {
V_6 -> V_87 &= ~ V_150 ;
}
V_282:
F_62 ( & V_2 -> V_60 , V_112 ) ;
F_95 ( V_2 , V_72 ) ;
F_95 ( V_2 , V_74 ) ;
F_95 ( V_2 , V_105 ) ;
F_95 ( V_2 , V_125 ) ;
V_6 -> V_152 = 0 ;
V_6 -> V_191 = 0 ;
V_6 -> V_147 = V_157 | V_283 ;
F_72 ( V_2 , V_51 , V_6 -> V_147 ) ;
if ( V_2 -> V_112 & V_142 ) {
unsigned int V_284 ;
V_284 = ( V_2 -> V_19 & 0xfe0 ) | 0x01f ;
F_65 ( 0x80 , V_284 ) ;
F_64 ( V_284 ) ;
}
return 0 ;
}
static void F_135 ( struct V_1 * V_2 )
{
struct V_5 * V_6 =
F_31 ( V_2 , struct V_5 , V_2 ) ;
unsigned long V_112 ;
V_6 -> V_147 = 0 ;
F_72 ( V_2 , V_51 , 0 ) ;
F_58 ( & V_2 -> V_60 , V_112 ) ;
if ( V_2 -> V_112 & V_142 ) {
F_20 ( ( V_2 -> V_19 & 0xfe0 ) | 0x1f ) ;
V_2 -> V_245 |= V_249 ;
} else
V_2 -> V_245 &= ~ V_250 ;
F_125 ( V_2 , V_2 -> V_245 ) ;
F_62 ( & V_2 -> V_60 , V_112 ) ;
F_72 ( V_2 , V_31 ,
F_95 ( V_2 , V_31 ) & ~ V_256 ) ;
F_37 ( V_6 ) ;
#ifdef F_60
F_44 ( V_6 ) ;
#endif
F_95 ( V_2 , V_74 ) ;
F_136 ( & V_6 -> V_232 ) ;
V_6 -> V_232 . V_278 = F_119 ;
if ( V_2 -> V_141 )
F_117 ( V_6 ) ;
}
static unsigned int F_137 ( struct V_1 * V_2 , unsigned int V_285 )
{
unsigned int V_101 ;
if ( ( V_2 -> V_112 & V_286 ) &&
V_285 == ( V_2 -> V_57 / 4 ) )
V_101 = 0x8001 ;
else if ( ( V_2 -> V_112 & V_286 ) &&
V_285 == ( V_2 -> V_57 / 8 ) )
V_101 = 0x8002 ;
else
V_101 = F_138 ( V_2 , V_285 ) ;
return V_101 ;
}
void
F_139 ( struct V_1 * V_2 , struct V_287 * V_288 ,
struct V_287 * V_289 )
{
struct V_5 * V_6 =
F_31 ( V_2 , struct V_5 , V_2 ) ;
unsigned char V_290 , V_43 = 0 ;
unsigned long V_112 ;
unsigned int V_285 , V_101 ;
switch ( V_288 -> V_291 & V_292 ) {
case V_293 :
V_290 = V_294 ;
break;
case V_295 :
V_290 = V_296 ;
break;
case V_297 :
V_290 = V_298 ;
break;
default:
case V_299 :
V_290 = V_279 ;
break;
}
if ( V_288 -> V_291 & V_300 )
V_290 |= V_301 ;
if ( V_288 -> V_291 & V_302 )
V_290 |= V_303 ;
if ( ! ( V_288 -> V_291 & V_304 ) )
V_290 |= V_305 ;
#ifdef F_140
if ( V_288 -> V_291 & F_140 )
V_290 |= V_306 ;
#endif
V_285 = F_141 ( V_2 , V_288 , V_289 ,
V_2 -> V_57 / 16 / 0xffff ,
V_2 -> V_57 / 16 ) ;
V_101 = F_137 ( V_2 , V_285 ) ;
if ( V_6 -> V_87 & V_88 && ( V_101 & 0xff ) == 0 )
V_101 ++ ;
if ( V_6 -> V_37 & V_38 && V_2 -> V_133 > 1 ) {
V_43 = V_44 [ V_2 -> type ] . V_43 ;
if ( V_285 < 2400 ) {
V_43 &= ~ V_307 ;
V_43 |= V_308 ;
}
}
if ( V_6 -> V_37 & V_107 && V_2 -> V_133 >= 32 ) {
V_6 -> V_246 &= ~ V_309 ;
if ( V_288 -> V_291 & V_310 )
V_6 -> V_246 |= V_309 ;
}
F_58 ( & V_2 -> V_60 , V_112 ) ;
F_142 ( V_2 , V_288 -> V_291 , V_285 ) ;
V_2 -> V_158 = V_178 | V_155 | V_73 ;
if ( V_288 -> V_311 & V_312 )
V_2 -> V_158 |= V_172 | V_173 ;
if ( V_288 -> V_311 & ( V_313 | V_314 ) )
V_2 -> V_158 |= V_171 ;
V_2 -> V_315 = 0 ;
if ( V_288 -> V_311 & V_316 )
V_2 -> V_315 |= V_173 | V_172 ;
if ( V_288 -> V_311 & V_317 ) {
V_2 -> V_315 |= V_171 ;
if ( V_288 -> V_311 & V_316 )
V_2 -> V_315 |= V_178 ;
}
if ( ( V_288 -> V_291 & V_318 ) == 0 )
V_2 -> V_315 |= V_73 ;
V_6 -> V_147 &= ~ V_160 ;
if ( ! ( V_6 -> V_87 & V_159 ) &&
F_143 ( & V_6 -> V_2 , V_288 -> V_291 ) )
V_6 -> V_147 |= V_160 ;
if ( V_6 -> V_37 & V_110 )
V_6 -> V_147 |= V_108 ;
if ( V_6 -> V_37 & V_111 )
V_6 -> V_147 |= V_319 ;
F_72 ( V_2 , V_51 , V_6 -> V_147 ) ;
if ( V_6 -> V_37 & V_47 ) {
unsigned char V_320 = 0 ;
if ( V_288 -> V_291 & V_310 )
V_320 |= V_321 ;
F_72 ( V_2 , V_31 , V_48 ) ;
if ( V_2 -> V_112 & V_113 )
F_72 ( V_2 , V_322 , V_320 ) ;
else
F_72 ( V_2 , V_49 , V_320 ) ;
}
#ifdef F_144
if ( F_145 () && F_146 ( V_6 ) ) {
if ( V_285 == 115200 ) {
V_101 = 1 ;
F_72 ( V_2 , V_323 , 1 ) ;
} else
F_72 ( V_2 , V_323 , 0 ) ;
}
#endif
if ( V_6 -> V_37 & V_103 )
F_72 ( V_2 , V_31 , 0xe0 ) ;
else
F_72 ( V_2 , V_31 , V_290 | V_324 ) ;
F_47 ( V_6 , V_101 ) ;
if ( V_2 -> type == V_106 )
F_72 ( V_2 , V_39 , V_43 ) ;
F_72 ( V_2 , V_31 , V_290 ) ;
V_6 -> V_255 = V_290 ;
if ( V_2 -> type != V_106 ) {
if ( V_43 & V_40 )
F_72 ( V_2 , V_39 , V_40 ) ;
F_72 ( V_2 , V_39 , V_43 ) ;
}
F_125 ( V_2 , V_2 -> V_245 ) ;
F_62 ( & V_2 -> V_60 , V_112 ) ;
if ( F_147 ( V_288 ) )
F_148 ( V_288 , V_285 , V_285 ) ;
}
static void
F_149 ( struct V_1 * V_2 , struct V_287 * V_288 ,
struct V_287 * V_289 )
{
if ( V_2 -> V_325 )
V_2 -> V_325 ( V_2 , V_288 , V_289 ) ;
else
F_139 ( V_2 , V_288 , V_289 ) ;
}
static void
F_150 ( struct V_1 * V_2 , int V_326 )
{
if ( V_326 == V_327 ) {
V_2 -> V_112 |= V_328 ;
F_75 ( V_2 ) ;
} else
V_2 -> V_112 &= ~ V_328 ;
}
void F_151 ( struct V_1 * V_2 , unsigned int V_163 ,
unsigned int V_329 )
{
struct V_5 * V_10 =
F_31 ( V_2 , struct V_5 , V_2 ) ;
F_39 ( V_10 , V_163 != 0 ) ;
}
static void
F_152 ( struct V_1 * V_2 , unsigned int V_163 ,
unsigned int V_329 )
{
if ( V_2 -> V_330 )
V_2 -> V_330 ( V_2 , V_163 , V_329 ) ;
else
F_151 ( V_2 , V_163 , V_329 ) ;
}
static unsigned int F_153 ( struct V_5 * V_331 )
{
if ( V_331 -> V_2 . V_22 == V_27 )
return 0x1000 ;
#ifdef F_144
if ( F_146 ( V_331 ) )
return 0x16 << V_331 -> V_2 . V_13 ;
#endif
return 8 << V_331 -> V_2 . V_13 ;
}
static int F_154 ( struct V_5 * V_6 )
{
unsigned int V_332 = F_153 ( V_6 ) ;
struct V_1 * V_2 = & V_6 -> V_2 ;
int V_221 = 0 ;
switch ( V_2 -> V_22 ) {
case V_27 :
case V_333 :
case V_25 :
case V_24 :
if ( ! V_2 -> V_121 )
break;
if ( ! F_155 ( V_2 -> V_121 , V_332 , L_21 ) ) {
V_221 = - V_334 ;
break;
}
if ( V_2 -> V_112 & V_335 ) {
V_2 -> V_14 = F_156 ( V_2 -> V_121 , V_332 ) ;
if ( ! V_2 -> V_14 ) {
F_157 ( V_2 -> V_121 , V_332 ) ;
V_221 = - V_229 ;
}
}
break;
case V_23 :
case V_336 :
if ( ! F_158 ( V_2 -> V_19 , V_332 , L_21 ) )
V_221 = - V_334 ;
break;
}
return V_221 ;
}
static void F_159 ( struct V_5 * V_6 )
{
unsigned int V_332 = F_153 ( V_6 ) ;
struct V_1 * V_2 = & V_6 -> V_2 ;
switch ( V_2 -> V_22 ) {
case V_27 :
case V_333 :
case V_25 :
case V_24 :
if ( ! V_2 -> V_121 )
break;
if ( V_2 -> V_112 & V_335 ) {
F_160 ( V_2 -> V_14 ) ;
V_2 -> V_14 = NULL ;
}
F_157 ( V_2 -> V_121 , V_332 ) ;
break;
case V_23 :
case V_336 :
F_161 ( V_2 -> V_19 , V_332 ) ;
break;
}
}
static int F_162 ( struct V_5 * V_6 )
{
unsigned long V_337 = V_338 << V_6 -> V_2 . V_13 ;
unsigned int V_332 = 8 << V_6 -> V_2 . V_13 ;
struct V_1 * V_2 = & V_6 -> V_2 ;
int V_221 = - V_339 ;
switch ( V_2 -> V_22 ) {
case V_23 :
case V_336 :
V_337 += V_2 -> V_19 ;
if ( F_158 ( V_337 , V_332 , L_25 ) )
V_221 = 0 ;
else
V_221 = - V_334 ;
break;
}
return V_221 ;
}
static void F_163 ( struct V_5 * V_6 )
{
unsigned long V_11 = V_338 << V_6 -> V_2 . V_13 ;
unsigned int V_332 = 8 << V_6 -> V_2 . V_13 ;
struct V_1 * V_2 = & V_6 -> V_2 ;
switch ( V_2 -> V_22 ) {
case V_23 :
case V_336 :
F_161 ( V_2 -> V_19 + V_11 , V_332 ) ;
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
int V_221 = 0 ;
V_221 = F_154 ( V_6 ) ;
if ( V_221 == 0 && V_2 -> type == V_59 ) {
V_221 = F_162 ( V_6 ) ;
if ( V_221 < 0 )
F_159 ( V_6 ) ;
}
return V_221 ;
}
static void F_166 ( struct V_1 * V_2 , int V_112 )
{
struct V_5 * V_6 =
F_31 ( V_2 , struct V_5 , V_2 ) ;
int V_116 = V_340 ;
int V_221 ;
V_221 = F_154 ( V_6 ) ;
if ( V_221 < 0 )
return;
V_221 = F_162 ( V_6 ) ;
if ( V_221 < 0 )
V_116 &= ~ V_128 ;
if ( V_2 -> V_22 != V_6 -> V_28 )
F_30 ( V_2 ) ;
if ( V_112 & V_341 )
F_57 ( V_6 , V_116 ) ;
if ( V_2 -> type == V_99 && V_2 -> V_22 == V_27 )
V_6 -> V_87 |= V_159 ;
if ( V_2 -> type != V_126 && V_112 & V_342 )
F_63 ( V_6 ) ;
if ( V_2 -> type != V_59 && V_116 & V_128 )
F_163 ( V_6 ) ;
if ( V_2 -> type == V_126 )
F_159 ( V_6 ) ;
}
static int
F_167 ( struct V_1 * V_2 , struct V_343 * V_344 )
{
if ( V_344 -> V_141 >= V_345 || V_344 -> V_141 < 0 ||
V_344 -> V_346 < 9600 || V_344 -> type < V_126 ||
V_344 -> type >= F_168 ( V_44 ) || V_344 -> type == V_347 ||
V_344 -> type == V_348 )
return - V_339 ;
return 0 ;
}
static const char *
F_169 ( struct V_1 * V_2 )
{
int type = V_2 -> type ;
if ( type >= F_168 ( V_44 ) )
type = 0 ;
return V_44 [ type ] . V_136 ;
}
void F_170 (
void (* F_171)( int V_2 , struct V_1 * V_6 , unsigned short * V_37 ) )
{
V_349 = F_171 ;
}
static void T_3 F_172 ( void )
{
struct V_5 * V_6 ;
static int V_350 = 1 ;
int V_129 , V_351 = 0 ;
if ( ! V_350 )
return;
V_350 = 0 ;
for ( V_129 = 0 ; V_129 < V_352 ; V_129 ++ ) {
struct V_5 * V_6 = & V_353 [ V_129 ] ;
struct V_1 * V_2 = & V_6 -> V_2 ;
V_2 -> line = V_129 ;
F_112 ( & V_2 -> V_60 ) ;
F_173 ( & V_6 -> V_232 ) ;
V_6 -> V_232 . V_278 = F_119 ;
V_6 -> V_252 = ~ V_354 ;
V_6 -> V_253 = V_354 ;
V_2 -> V_355 = & V_356 ;
}
if ( V_357 )
V_351 = V_224 ;
for ( V_129 = 0 , V_6 = V_353 ;
V_129 < F_168 ( V_358 ) && V_129 < V_352 ;
V_129 ++ , V_6 ++ ) {
struct V_1 * V_2 = & V_6 -> V_2 ;
V_2 -> V_19 = V_358 [ V_129 ] . V_2 ;
V_2 -> V_141 = F_174 ( V_358 [ V_129 ] . V_141 ) ;
V_2 -> V_230 = V_358 [ V_129 ] . V_230 ;
V_2 -> V_57 = V_358 [ V_129 ] . V_346 * 16 ;
V_2 -> V_112 = V_358 [ V_129 ] . V_112 ;
V_2 -> V_18 = V_358 [ V_129 ] . V_18 ;
V_2 -> V_14 = V_358 [ V_129 ] . V_359 ;
V_2 -> V_22 = V_358 [ V_129 ] . V_360 ;
V_2 -> V_13 = V_358 [ V_129 ] . V_361 ;
F_30 ( V_2 ) ;
V_2 -> V_230 |= V_351 ;
if ( V_349 != NULL )
V_349 ( V_129 , & V_6 -> V_2 , & V_6 -> V_37 ) ;
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
F_176 ( struct V_362 * V_363 , struct V_364 * V_365 )
{
int V_129 ;
for ( V_129 = 0 ; V_129 < V_352 ; V_129 ++ ) {
struct V_5 * V_6 = & V_353 [ V_129 ] ;
V_6 -> V_28 = 0xFF ;
}
F_172 () ;
for ( V_129 = 0 ; V_129 < V_352 ; V_129 ++ ) {
struct V_5 * V_6 = & V_353 [ V_129 ] ;
V_6 -> V_2 . V_365 = V_365 ;
if ( V_6 -> V_2 . V_112 & V_366 )
F_175 ( V_6 , V_6 -> V_2 . type ) ;
F_177 ( V_363 , & V_6 -> V_2 ) ;
}
}
static void F_178 ( struct V_1 * V_2 , int V_164 )
{
struct V_5 * V_6 =
F_31 ( V_2 , struct V_5 , V_2 ) ;
F_127 ( V_6 , V_155 ) ;
F_72 ( V_2 , V_71 , V_164 ) ;
}
static void
F_179 ( struct V_367 * V_368 , const char * V_369 , unsigned int V_67 )
{
struct V_5 * V_6 = & V_353 [ V_368 -> V_370 ] ;
struct V_1 * V_2 = & V_6 -> V_2 ;
unsigned long V_112 ;
unsigned int V_147 ;
int V_371 = 1 ;
F_128 () ;
F_180 ( V_112 ) ;
if ( V_2 -> V_372 ) {
V_371 = 0 ;
} else if ( V_373 ) {
V_371 = F_181 ( & V_2 -> V_60 ) ;
} else
F_85 ( & V_2 -> V_60 ) ;
V_147 = F_95 ( V_2 , V_51 ) ;
if ( V_6 -> V_37 & V_110 )
F_72 ( V_2 , V_51 , V_108 ) ;
else
F_72 ( V_2 , V_51 , 0 ) ;
F_182 ( V_2 , V_369 , V_67 , F_178 ) ;
F_127 ( V_6 , V_237 ) ;
F_72 ( V_2 , V_51 , V_147 ) ;
if ( V_6 -> V_191 )
F_90 ( V_6 ) ;
if ( V_371 )
F_83 ( & V_2 -> V_60 ) ;
F_183 ( V_112 ) ;
}
static int T_3 F_184 ( struct V_367 * V_368 , char * V_374 )
{
struct V_1 * V_2 ;
int V_285 = 9600 ;
int V_257 = 8 ;
int V_176 = 'n' ;
int V_375 = 'n' ;
if ( V_368 -> V_370 >= V_352 )
V_368 -> V_370 = 0 ;
V_2 = & V_353 [ V_368 -> V_370 ] . V_2 ;
if ( ! V_2 -> V_19 && ! V_2 -> V_14 )
return - V_267 ;
if ( V_374 )
F_185 ( V_374 , & V_285 , & V_176 , & V_257 , & V_375 ) ;
return F_186 ( V_2 , V_368 , V_285 , V_176 , V_257 , V_375 ) ;
}
static int F_187 ( void )
{
return F_188 () ;
}
static int T_3 F_189 ( void )
{
if ( V_352 > V_376 )
V_352 = V_376 ;
F_172 () ;
F_190 ( & V_377 ) ;
return 0 ;
}
int F_191 ( struct V_1 * V_10 )
{
int line ;
struct V_1 * V_2 ;
for ( line = 0 ; line < V_352 ; line ++ ) {
V_2 = & V_353 [ line ] . V_2 ;
if ( F_192 ( V_10 , V_2 ) )
return line ;
}
return - V_267 ;
}
int T_3 F_193 ( struct V_1 * V_2 )
{
struct V_1 * V_10 ;
if ( V_2 -> line >= F_168 ( V_353 ) )
return - V_267 ;
F_172 () ;
V_10 = & V_353 [ V_2 -> line ] . V_2 ;
V_10 -> V_19 = V_2 -> V_19 ;
V_10 -> V_14 = V_2 -> V_14 ;
V_10 -> V_141 = V_2 -> V_141 ;
V_10 -> V_230 = V_2 -> V_230 ;
V_10 -> V_57 = V_2 -> V_57 ;
V_10 -> V_133 = V_2 -> V_133 ;
V_10 -> V_13 = V_2 -> V_13 ;
V_10 -> V_22 = V_2 -> V_22 ;
V_10 -> V_112 = V_2 -> V_112 ;
V_10 -> V_121 = V_2 -> V_121 ;
V_10 -> V_378 = V_2 -> V_378 ;
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
F_195 ( & V_3 , & V_353 [ line ] . V_2 ) ;
}
void F_196 ( int line )
{
struct V_5 * V_6 = & V_353 [ line ] ;
struct V_1 * V_2 = & V_6 -> V_2 ;
if ( V_6 -> V_37 & V_103 ) {
F_72 ( V_2 , V_31 , 0xE0 ) ;
F_54 ( V_6 ) ;
F_72 ( V_2 , V_31 , 0 ) ;
V_2 -> V_57 = 921600 * 16 ;
}
F_197 ( & V_3 , V_2 ) ;
}
static int T_4 F_198 ( struct V_379 * V_365 )
{
struct V_380 * V_10 = V_365 -> V_365 . V_381 ;
struct V_1 V_2 ;
int V_221 , V_129 , V_351 = 0 ;
memset ( & V_2 , 0 , sizeof( struct V_1 ) ) ;
if ( V_357 )
V_351 = V_224 ;
for ( V_129 = 0 ; V_10 && V_10 -> V_112 != 0 ; V_10 ++ , V_129 ++ ) {
V_2 . V_19 = V_10 -> V_19 ;
V_2 . V_14 = V_10 -> V_14 ;
V_2 . V_141 = V_10 -> V_141 ;
V_2 . V_230 = V_10 -> V_230 ;
V_2 . V_57 = V_10 -> V_57 ;
V_2 . V_13 = V_10 -> V_13 ;
V_2 . V_22 = V_10 -> V_22 ;
V_2 . V_112 = V_10 -> V_112 ;
V_2 . V_121 = V_10 -> V_121 ;
V_2 . V_18 = V_10 -> V_18 ;
V_2 . V_378 = V_10 -> V_378 ;
V_2 . type = V_10 -> type ;
V_2 . F_3 = V_10 -> F_3 ;
V_2 . F_5 = V_10 -> F_5 ;
V_2 . V_29 = V_10 -> V_29 ;
V_2 . V_382 = V_10 -> V_382 ;
V_2 . V_325 = V_10 -> V_325 ;
V_2 . V_330 = V_10 -> V_330 ;
V_2 . V_365 = & V_365 -> V_365 ;
V_2 . V_230 |= V_351 ;
V_221 = F_199 ( & V_2 ) ;
if ( V_221 < 0 ) {
F_200 ( & V_365 -> V_365 , L_26
L_27 , V_129 ,
V_10 -> V_19 , ( unsigned long long ) V_10 -> V_121 ,
V_10 -> V_141 , V_221 ) ;
}
}
return 0 ;
}
static int T_5 F_201 ( struct V_379 * V_365 )
{
int V_129 ;
for ( V_129 = 0 ; V_129 < V_352 ; V_129 ++ ) {
struct V_5 * V_6 = & V_353 [ V_129 ] ;
if ( V_6 -> V_2 . V_365 == & V_365 -> V_365 )
F_202 ( V_129 ) ;
}
return 0 ;
}
static int F_203 ( struct V_379 * V_365 , T_6 V_163 )
{
int V_129 ;
for ( V_129 = 0 ; V_129 < V_376 ; V_129 ++ ) {
struct V_5 * V_6 = & V_353 [ V_129 ] ;
if ( V_6 -> V_2 . type != V_126 && V_6 -> V_2 . V_365 == & V_365 -> V_365 )
F_195 ( & V_3 , & V_6 -> V_2 ) ;
}
return 0 ;
}
static int F_204 ( struct V_379 * V_365 )
{
int V_129 ;
for ( V_129 = 0 ; V_129 < V_376 ; V_129 ++ ) {
struct V_5 * V_6 = & V_353 [ V_129 ] ;
if ( V_6 -> V_2 . type != V_126 && V_6 -> V_2 . V_365 == & V_365 -> V_365 )
F_196 ( V_129 ) ;
}
return 0 ;
}
static struct V_5 * F_205 ( struct V_1 * V_2 )
{
int V_129 ;
for ( V_129 = 0 ; V_129 < V_352 ; V_129 ++ )
if ( F_192 ( & V_353 [ V_129 ] . V_2 , V_2 ) )
return & V_353 [ V_129 ] ;
for ( V_129 = 0 ; V_129 < V_352 ; V_129 ++ )
if ( V_353 [ V_129 ] . V_2 . type == V_126 &&
V_353 [ V_129 ] . V_2 . V_19 == 0 )
return & V_353 [ V_129 ] ;
for ( V_129 = 0 ; V_129 < V_352 ; V_129 ++ )
if ( V_353 [ V_129 ] . V_2 . type == V_126 )
return & V_353 [ V_129 ] ;
return NULL ;
}
int F_206 ( struct V_5 * V_6 )
{
struct V_5 * V_383 ;
int V_221 = - V_384 ;
if ( V_6 -> V_2 . V_57 == 0 )
return - V_339 ;
F_107 ( & V_385 ) ;
V_383 = F_205 ( & V_6 -> V_2 ) ;
if ( V_383 ) {
F_207 ( & V_3 , & V_383 -> V_2 ) ;
V_383 -> V_2 . V_19 = V_6 -> V_2 . V_19 ;
V_383 -> V_2 . V_14 = V_6 -> V_2 . V_14 ;
V_383 -> V_2 . V_141 = V_6 -> V_2 . V_141 ;
V_383 -> V_2 . V_230 = V_6 -> V_2 . V_230 ;
V_383 -> V_2 . V_57 = V_6 -> V_2 . V_57 ;
V_383 -> V_2 . V_133 = V_6 -> V_2 . V_133 ;
V_383 -> V_2 . V_13 = V_6 -> V_2 . V_13 ;
V_383 -> V_2 . V_22 = V_6 -> V_2 . V_22 ;
V_383 -> V_2 . V_112 = V_6 -> V_2 . V_112 | V_386 ;
V_383 -> V_2 . V_121 = V_6 -> V_2 . V_121 ;
V_383 -> V_2 . V_378 = V_6 -> V_2 . V_378 ;
if ( V_6 -> V_2 . V_365 )
V_383 -> V_2 . V_365 = V_6 -> V_2 . V_365 ;
if ( V_6 -> V_2 . V_112 & V_366 )
F_175 ( V_383 , V_6 -> V_2 . type ) ;
F_30 ( & V_383 -> V_2 ) ;
if ( V_6 -> V_2 . F_3 )
V_383 -> V_2 . F_3 = V_6 -> V_2 . F_3 ;
if ( V_6 -> V_2 . F_5 )
V_383 -> V_2 . F_5 = V_6 -> V_2 . F_5 ;
if ( V_6 -> V_2 . V_29 )
V_383 -> V_2 . V_29 = V_6 -> V_2 . V_29 ;
if ( V_6 -> V_2 . V_325 )
V_383 -> V_2 . V_325 = V_6 -> V_2 . V_325 ;
if ( V_6 -> V_2 . V_330 )
V_383 -> V_2 . V_330 = V_6 -> V_2 . V_330 ;
if ( V_6 -> V_2 . V_382 )
V_383 -> V_2 . V_382 = V_6 -> V_2 . V_382 ;
if ( V_6 -> V_20 )
V_383 -> V_20 = V_6 -> V_20 ;
if ( V_6 -> V_21 )
V_383 -> V_21 = V_6 -> V_21 ;
if ( V_349 != NULL )
V_349 ( 0 , & V_383 -> V_2 ,
& V_383 -> V_37 ) ;
V_221 = F_177 ( & V_3 , & V_383 -> V_2 ) ;
if ( V_221 == 0 )
V_221 = V_383 -> V_2 . line ;
}
F_111 ( & V_385 ) ;
return V_221 ;
}
int F_199 ( struct V_1 * V_2 )
{
struct V_5 V_6 ;
memset ( & V_6 , 0 , sizeof( V_6 ) ) ;
memcpy ( & V_6 . V_2 , V_2 , sizeof( * V_2 ) ) ;
return F_206 ( & V_6 ) ;
}
void F_202 ( int line )
{
struct V_5 * V_383 = & V_353 [ line ] ;
F_107 ( & V_385 ) ;
F_207 ( & V_3 , & V_383 -> V_2 ) ;
if ( V_387 ) {
V_383 -> V_2 . V_112 &= ~ V_386 ;
V_383 -> V_2 . type = V_126 ;
V_383 -> V_2 . V_365 = & V_387 -> V_365 ;
V_383 -> V_37 = V_44 [ V_383 -> V_2 . type ] . V_112 ;
F_177 ( & V_3 , & V_383 -> V_2 ) ;
} else {
V_383 -> V_2 . V_365 = NULL ;
}
F_111 ( & V_385 ) ;
}
static int T_3 F_208 ( void )
{
int V_221 ;
if ( V_352 > V_376 )
V_352 = V_376 ;
F_61 ( V_266 L_28
L_29 , V_352 ,
V_357 ? L_30 : L_31 ) ;
#ifdef F_209
V_221 = F_210 ( & V_3 , V_376 ) ;
#else
V_3 . V_388 = V_376 ;
V_221 = F_211 ( & V_3 ) ;
#endif
if ( V_221 )
goto V_123;
V_387 = F_212 ( L_32 ,
V_389 ) ;
if ( ! V_387 ) {
V_221 = - V_229 ;
goto V_390;
}
V_221 = F_213 ( V_387 ) ;
if ( V_221 )
goto V_391;
F_176 ( & V_3 , & V_387 -> V_365 ) ;
V_221 = F_214 ( & V_392 ) ;
if ( V_221 == 0 )
goto V_123;
F_215 ( V_387 ) ;
V_391:
F_216 ( V_387 ) ;
V_390:
#ifdef F_209
F_217 ( & V_3 , V_376 ) ;
#else
F_218 ( & V_3 ) ;
#endif
V_123:
return V_221 ;
}
static void T_7 F_219 ( void )
{
struct V_379 * V_393 = V_387 ;
V_387 = NULL ;
F_220 ( & V_392 ) ;
F_221 ( V_393 ) ;
#ifdef F_209
F_217 ( & V_3 , V_376 ) ;
#else
F_218 ( & V_3 ) ;
#endif
}
