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
V_11 = V_11 << V_10 -> V_13 ;
F_13 ( V_10 -> V_16 - 1 + V_11 , V_10 -> V_17 ) ;
return F_14 ( V_10 -> V_17 + 1 ) ;
}
static void F_15 ( struct V_1 * V_10 , int V_11 , int V_9 )
{
V_11 = V_11 << V_10 -> V_13 ;
F_13 ( V_10 -> V_16 - 1 + V_11 , V_10 -> V_17 ) ;
F_13 ( V_9 , V_10 -> V_17 + 1 ) ;
}
static unsigned int F_16 ( struct V_1 * V_10 , int V_11 )
{
V_11 = V_11 << V_10 -> V_13 ;
return F_17 ( V_10 -> V_14 + V_11 ) ;
}
static void F_18 ( struct V_1 * V_10 , int V_11 , int V_9 )
{
V_11 = V_11 << V_10 -> V_13 ;
F_19 ( V_9 , V_10 -> V_14 + V_11 ) ;
}
static void F_20 ( struct V_1 * V_10 , int V_11 , int V_9 )
{
V_11 = V_11 << V_10 -> V_13 ;
F_21 ( V_9 , V_10 -> V_14 + V_11 ) ;
}
static unsigned int F_22 ( struct V_1 * V_10 , int V_11 )
{
V_11 = V_11 << V_10 -> V_13 ;
return F_23 ( V_10 -> V_14 + V_11 ) ;
}
static unsigned int F_24 ( struct V_1 * V_10 , int V_11 )
{
V_11 = V_11 << V_10 -> V_13 ;
return F_14 ( V_10 -> V_17 + V_11 ) ;
}
static void F_25 ( struct V_1 * V_10 , int V_11 , int V_9 )
{
V_11 = V_11 << V_10 -> V_13 ;
F_13 ( V_9 , V_10 -> V_17 + V_11 ) ;
}
static void F_26 ( struct V_1 * V_10 )
{
struct V_5 * V_6 =
F_27 ( V_10 , struct V_5 , V_2 ) ;
V_6 -> V_18 = F_2 ;
V_6 -> V_19 = F_4 ;
switch ( V_10 -> V_20 ) {
case V_21 :
V_10 -> F_3 = F_12 ;
V_10 -> F_5 = F_15 ;
break;
case V_22 :
V_10 -> F_3 = F_16 ;
V_10 -> F_5 = F_18 ;
break;
case V_23 :
V_10 -> F_3 = F_22 ;
V_10 -> F_5 = F_20 ;
break;
#if F_28 ( V_24 ) || F_28 ( V_25 )
case V_26 :
V_10 -> F_3 = F_6 ;
V_10 -> F_5 = F_8 ;
V_6 -> V_18 = F_10 ;
V_6 -> V_19 = F_11 ;
break;
#endif
default:
V_10 -> F_3 = F_24 ;
V_10 -> F_5 = F_25 ;
break;
}
V_6 -> V_27 = V_10 -> V_20 ;
V_10 -> V_28 = V_29 ;
}
static void
F_29 ( struct V_1 * V_10 , int V_11 , int V_9 )
{
switch ( V_10 -> V_20 ) {
case V_22 :
case V_23 :
case V_26 :
V_10 -> F_5 ( V_10 , V_11 , V_9 ) ;
V_10 -> F_3 ( V_10 , V_30 ) ;
break;
default:
V_10 -> F_5 ( V_10 , V_11 , V_9 ) ;
}
}
static void F_30 ( struct V_5 * V_6 , int V_11 , int V_9 )
{
F_5 ( V_6 , V_31 , V_11 ) ;
F_5 ( V_6 , V_32 , V_9 ) ;
}
static unsigned int F_31 ( struct V_5 * V_6 , int V_11 )
{
unsigned int V_9 ;
F_30 ( V_6 , V_33 , V_6 -> V_34 | V_35 ) ;
F_5 ( V_6 , V_31 , V_11 ) ;
V_9 = F_3 ( V_6 , V_32 ) ;
F_30 ( V_6 , V_33 , V_6 -> V_34 ) ;
return V_9 ;
}
static void F_32 ( struct V_5 * V_10 )
{
if ( V_10 -> V_36 & V_37 ) {
F_5 ( V_10 , V_38 , V_39 ) ;
F_5 ( V_10 , V_38 , V_39 |
V_40 | V_41 ) ;
F_5 ( V_10 , V_38 , 0 ) ;
}
}
void F_33 ( struct V_5 * V_10 )
{
unsigned char V_42 ;
F_32 ( V_10 ) ;
V_42 = V_43 [ V_10 -> V_2 . type ] . V_42 ;
F_5 ( V_10 , V_38 , V_42 ) ;
}
static void F_34 ( struct V_5 * V_10 , int V_44 )
{
if ( ( V_10 -> V_2 . type == V_45 ) ||
( V_10 -> V_2 . type == V_46 ) ) {
F_5 ( V_10 , V_47 , 0xff ) ;
return;
}
if ( V_10 -> V_36 & V_48 ) {
if ( V_10 -> V_36 & V_49 ) {
F_5 ( V_10 , V_30 , V_50 ) ;
F_5 ( V_10 , V_51 , V_52 ) ;
F_5 ( V_10 , V_30 , 0 ) ;
}
F_5 ( V_10 , V_53 , V_44 ? V_54 : 0 ) ;
if ( V_10 -> V_36 & V_49 ) {
F_5 ( V_10 , V_30 , V_50 ) ;
F_5 ( V_10 , V_51 , 0 ) ;
F_5 ( V_10 , V_30 , 0 ) ;
}
}
}
static int F_35 ( struct V_5 * V_6 )
{
unsigned char V_55 ;
int V_56 ;
V_55 = F_3 ( V_6 , V_57 ) ;
V_56 = V_55 & V_58 ;
if ( ! V_56 ) {
F_5 ( V_6 , V_57 , V_55 | V_58 ) ;
V_55 = F_3 ( V_6 , V_57 ) ;
V_56 = V_55 & V_58 ;
}
if ( V_56 )
V_6 -> V_2 . V_59 = V_60 * 16 ;
return V_56 ;
}
static void F_36 ( struct V_5 * V_6 )
{
if ( V_6 -> V_2 . type == V_61 ) {
if ( V_6 -> V_2 . V_59 != V_60 * 16 ) {
F_37 ( & V_6 -> V_2 . V_62 ) ;
F_35 ( V_6 ) ;
F_38 ( & V_6 -> V_2 . V_62 ) ;
}
if ( V_6 -> V_2 . V_59 == V_60 * 16 )
F_5 ( V_6 , V_63 , 0 ) ;
}
}
static void F_39 ( struct V_5 * V_6 )
{
unsigned char V_55 ;
int V_56 ;
if ( V_6 -> V_2 . type == V_61 &&
V_6 -> V_2 . V_59 == V_60 * 16 ) {
F_37 ( & V_6 -> V_2 . V_62 ) ;
V_55 = F_3 ( V_6 , V_57 ) ;
V_56 = ! ( V_55 & V_58 ) ;
if ( ! V_56 ) {
F_5 ( V_6 , V_57 , V_55 & ~ V_58 ) ;
V_55 = F_3 ( V_6 , V_57 ) ;
V_56 = ! ( V_55 & V_58 ) ;
}
if ( V_56 )
V_6 -> V_2 . V_59 = V_64 * 16 ;
F_38 ( & V_6 -> V_2 . V_62 ) ;
}
}
static int F_40 ( struct V_5 * V_6 )
{
unsigned char V_65 , V_66 , V_67 ;
unsigned short V_68 ;
int V_69 ;
V_67 = F_3 ( V_6 , V_30 ) ;
F_5 ( V_6 , V_30 , 0 ) ;
V_65 = F_3 ( V_6 , V_38 ) ;
V_66 = F_3 ( V_6 , V_70 ) ;
F_5 ( V_6 , V_38 , V_39 |
V_40 | V_41 ) ;
F_5 ( V_6 , V_70 , V_71 ) ;
F_5 ( V_6 , V_30 , V_72 ) ;
V_68 = F_41 ( V_6 ) ;
F_42 ( V_6 , 0x0001 ) ;
F_5 ( V_6 , V_30 , 0x03 ) ;
for ( V_69 = 0 ; V_69 < 256 ; V_69 ++ )
F_5 ( V_6 , V_73 , V_69 ) ;
F_43 ( 20 ) ;
for ( V_69 = 0 ; ( F_3 ( V_6 , V_74 ) & V_75 ) &&
( V_69 < 256 ) ; V_69 ++ )
F_3 ( V_6 , V_76 ) ;
F_5 ( V_6 , V_38 , V_65 ) ;
F_5 ( V_6 , V_70 , V_66 ) ;
F_5 ( V_6 , V_30 , V_72 ) ;
F_42 ( V_6 , V_68 ) ;
F_5 ( V_6 , V_30 , V_67 ) ;
return V_69 ;
}
static unsigned int F_44 ( struct V_5 * V_10 )
{
unsigned char V_77 , V_78 , V_67 ;
unsigned int V_79 ;
V_67 = F_3 ( V_10 , V_30 ) ;
F_5 ( V_10 , V_30 , V_72 ) ;
V_77 = F_3 ( V_10 , V_7 ) ;
V_78 = F_3 ( V_10 , V_8 ) ;
F_5 ( V_10 , V_7 , 0 ) ;
F_5 ( V_10 , V_8 , 0 ) ;
V_79 = F_3 ( V_10 , V_7 ) | F_3 ( V_10 , V_8 ) << 8 ;
F_5 ( V_10 , V_7 , V_77 ) ;
F_5 ( V_10 , V_8 , V_78 ) ;
F_5 ( V_10 , V_30 , V_67 ) ;
return V_79 ;
}
static void F_45 ( struct V_5 * V_6 )
{
unsigned int V_80 , V_81 , V_82 , V_83 ;
V_6 -> V_36 |= V_49 | V_48 ;
V_6 -> V_34 = 0 ;
F_5 ( V_6 , V_30 , V_50 ) ;
F_5 ( V_6 , V_51 , V_52 ) ;
F_5 ( V_6 , V_30 , 0x00 ) ;
V_80 = F_31 ( V_6 , V_84 ) ;
V_81 = F_31 ( V_6 , V_85 ) ;
V_82 = F_31 ( V_6 , V_86 ) ;
V_83 = F_31 ( V_6 , V_87 ) ;
F_46 ( L_1 , V_80 , V_81 , V_82 , V_83 ) ;
if ( V_80 == 0x16 && V_81 == 0xC9 &&
( V_82 == 0x50 || V_82 == 0x52 || V_82 == 0x54 ) ) {
V_6 -> V_2 . type = V_88 ;
if ( V_82 == 0x52 && V_83 == 0x01 )
V_6 -> V_89 |= V_90 ;
return;
}
V_80 = F_44 ( V_6 ) ;
F_46 ( L_2 , V_80 ) ;
V_81 = V_80 >> 8 ;
if ( V_81 == 0x10 || V_81 == 0x12 || V_81 == 0x14 ) {
V_6 -> V_2 . type = V_91 ;
return;
}
if ( F_40 ( V_6 ) == 64 )
V_6 -> V_2 . type = V_92 ;
else
V_6 -> V_2 . type = V_93 ;
}
static void F_47 ( struct V_5 * V_6 )
{
unsigned char V_94 , V_95 , V_96 ;
V_6 -> V_2 . type = V_97 ;
V_94 = F_3 ( V_6 , V_31 ) ;
F_5 ( V_6 , V_31 , 0xa5 ) ;
V_95 = F_3 ( V_6 , V_31 ) ;
F_5 ( V_6 , V_31 , 0x5a ) ;
V_96 = F_3 ( V_6 , V_31 ) ;
F_5 ( V_6 , V_31 , V_94 ) ;
if ( V_95 == 0xa5 && V_96 == 0x5a )
V_6 -> V_2 . type = V_98 ;
}
static int F_48 ( struct V_5 * V_6 )
{
if ( F_44 ( V_6 ) == 0x0201 && F_40 ( V_6 ) == 16 )
return 1 ;
return 0 ;
}
static inline int F_49 ( struct V_5 * V_6 )
{
unsigned char V_99 ;
V_99 = F_3 ( V_6 , 0x04 ) ;
#define F_50 ( T_1 ) ((x) & 0x30)
if ( F_50 ( V_99 ) == 0x10 ) {
return 0 ;
} else {
V_99 &= ~ 0xB0 ;
V_99 |= 0x10 ;
F_5 ( V_6 , 0x04 , V_99 ) ;
}
return 1 ;
}
static void F_51 ( struct V_5 * V_6 )
{
unsigned char V_95 , V_96 ;
unsigned int V_100 ;
V_6 -> V_2 . type = V_101 ;
V_6 -> V_36 |= V_37 ;
if ( V_6 -> V_2 . V_102 & V_103 ) {
V_95 = F_3 ( V_6 , V_104 ) ;
if ( V_95 == 0x82 || V_95 == 0x84 || V_95 == 0x88 ) {
F_46 ( L_3 ) ;
V_6 -> V_2 . type = V_45 ;
V_6 -> V_36 |= V_105 | V_49 |
V_48 ;
return;
}
}
F_5 ( V_6 , V_30 , V_72 ) ;
if ( F_3 ( V_6 , V_51 ) == 0 ) {
F_5 ( V_6 , V_51 , 0xA8 ) ;
if ( F_3 ( V_6 , V_51 ) != 0 ) {
F_46 ( L_4 ) ;
V_6 -> V_2 . type = V_106 ;
V_6 -> V_36 |= V_49 | V_48 ;
} else {
F_46 ( L_5 ) ;
}
F_5 ( V_6 , V_51 , 0 ) ;
return;
}
F_5 ( V_6 , V_30 , V_50 ) ;
if ( F_3 ( V_6 , V_51 ) == 0 && ! F_48 ( V_6 ) ) {
F_46 ( L_6 ) ;
F_45 ( V_6 ) ;
return;
}
F_5 ( V_6 , V_30 , 0 ) ;
V_95 = F_3 ( V_6 , V_70 ) ;
F_5 ( V_6 , V_30 , 0xE0 ) ;
V_96 = F_3 ( V_6 , 0x02 ) ;
if ( ! ( ( V_96 ^ V_95 ) & V_71 ) ) {
F_5 ( V_6 , V_30 , 0 ) ;
F_5 ( V_6 , V_70 , V_95 ^ V_71 ) ;
F_5 ( V_6 , V_30 , 0xE0 ) ;
V_96 = F_3 ( V_6 , 0x02 ) ;
F_5 ( V_6 , V_30 , 0 ) ;
F_5 ( V_6 , V_70 , V_95 ) ;
if ( ( V_96 ^ V_95 ) & V_71 ) {
unsigned short V_107 ;
F_5 ( V_6 , V_30 , 0xE0 ) ;
V_107 = F_41 ( V_6 ) ;
V_107 <<= 3 ;
if ( F_49 ( V_6 ) )
F_42 ( V_6 , V_107 ) ;
F_5 ( V_6 , V_30 , 0 ) ;
V_6 -> V_2 . V_59 = 921600 * 16 ;
V_6 -> V_2 . type = V_108 ;
V_6 -> V_36 |= V_109 ;
return;
}
}
F_5 ( V_6 , V_30 , 0 ) ;
F_5 ( V_6 , V_38 , V_39 | V_110 ) ;
V_95 = F_3 ( V_6 , V_111 ) >> 5 ;
F_5 ( V_6 , V_38 , V_39 ) ;
F_5 ( V_6 , V_30 , V_72 ) ;
F_5 ( V_6 , V_38 , V_39 | V_110 ) ;
V_96 = F_3 ( V_6 , V_111 ) >> 5 ;
F_5 ( V_6 , V_38 , V_39 ) ;
F_5 ( V_6 , V_30 , 0 ) ;
F_46 ( L_7 , V_95 , V_96 ) ;
if ( V_95 == 6 && V_96 == 7 ) {
V_6 -> V_2 . type = V_112 ;
V_6 -> V_36 |= V_105 | V_48 ;
return;
}
V_100 = F_3 ( V_6 , V_53 ) ;
F_5 ( V_6 , V_53 , V_100 & ~ V_113 ) ;
if ( ! ( F_3 ( V_6 , V_53 ) & V_113 ) ) {
F_5 ( V_6 , V_53 , V_100 | V_113 ) ;
if ( F_3 ( V_6 , V_53 ) & V_113 ) {
F_46 ( L_8 ) ;
V_6 -> V_2 . type = V_114 ;
V_6 -> V_36 |= V_115 | V_116 ;
return;
}
} else {
F_46 ( L_9 ) ;
}
F_5 ( V_6 , V_53 , V_100 ) ;
if ( V_6 -> V_2 . V_102 & V_103 ) {
F_46 ( L_10 ) ;
V_6 -> V_2 . type = V_46 ;
V_6 -> V_36 |= V_105 | V_49 |
V_48 ;
return;
}
if ( V_6 -> V_2 . type == V_101 && F_40 ( V_6 ) == 64 ) {
V_6 -> V_2 . type = V_117 ;
V_6 -> V_36 |= V_105 ;
}
}
static void F_52 ( struct V_5 * V_6 , unsigned int V_118 )
{
unsigned char V_95 , V_94 , V_119 , V_120 ;
unsigned char V_121 , V_122 ;
struct V_1 * V_2 = & V_6 -> V_2 ;
unsigned long V_102 ;
unsigned int V_123 ;
if ( ! V_2 -> V_17 && ! V_2 -> V_124 && ! V_2 -> V_14 )
return;
F_46 ( L_11 ,
F_1 ( V_2 ) , V_2 -> V_17 , V_2 -> V_14 ) ;
F_53 ( & V_2 -> V_62 , V_102 ) ;
V_6 -> V_36 = 0 ;
V_6 -> V_89 = 0 ;
if ( ! ( V_2 -> V_102 & V_125 ) ) {
V_94 = F_3 ( V_6 , V_53 ) ;
F_5 ( V_6 , V_53 , 0 ) ;
#ifdef F_54
F_13 ( 0xff , 0x080 ) ;
#endif
V_119 = F_3 ( V_6 , V_53 ) & 0x0f ;
F_5 ( V_6 , V_53 , 0x0F ) ;
#ifdef F_54
F_13 ( 0 , 0x080 ) ;
#endif
V_120 = F_3 ( V_6 , V_53 ) & 0x0f ;
F_5 ( V_6 , V_53 , V_94 ) ;
if ( V_119 != 0 || V_120 != 0x0F ) {
F_55 ( & V_2 -> V_62 , V_102 ) ;
F_46 ( L_12 ,
V_119 , V_120 ) ;
goto V_126;
}
}
V_122 = F_3 ( V_6 , V_70 ) ;
V_121 = F_3 ( V_6 , V_30 ) ;
if ( ! ( V_2 -> V_102 & V_127 ) ) {
F_5 ( V_6 , V_70 , V_71 | 0x0A ) ;
V_95 = F_3 ( V_6 , V_128 ) & 0xF0 ;
F_5 ( V_6 , V_70 , V_122 ) ;
if ( V_95 != 0x90 ) {
F_55 ( & V_2 -> V_62 , V_102 ) ;
F_46 ( L_13 ,
V_95 ) ;
goto V_126;
}
}
F_5 ( V_6 , V_30 , V_50 ) ;
F_5 ( V_6 , V_51 , 0 ) ;
F_5 ( V_6 , V_30 , 0 ) ;
F_5 ( V_6 , V_38 , V_39 ) ;
V_94 = F_3 ( V_6 , V_111 ) >> 6 ;
switch ( V_94 ) {
case 0 :
F_47 ( V_6 ) ;
break;
case 1 :
V_2 -> type = V_129 ;
break;
case 2 :
V_2 -> type = V_130 ;
break;
case 3 :
F_51 ( V_6 ) ;
break;
}
#ifdef F_56
if ( V_2 -> type == V_101 && V_118 & V_131 ) {
int V_132 ;
for ( V_132 = 0 ; V_132 < V_133 ; ++ V_132 ) {
if ( V_134 [ V_132 ] == V_2 -> V_17 && F_35 ( V_6 ) ) {
V_2 -> type = V_61 ;
break;
}
}
}
#endif
F_5 ( V_6 , V_30 , V_121 ) ;
V_2 -> V_135 = V_43 [ V_6 -> V_2 . type ] . V_136 ;
V_123 = V_6 -> V_36 ;
V_6 -> V_36 = V_43 [ V_2 -> type ] . V_102 ;
V_6 -> V_137 = V_43 [ V_2 -> type ] . V_137 ;
if ( V_2 -> type == V_129 )
goto V_138;
#ifdef F_56
if ( V_2 -> type == V_61 )
F_5 ( V_6 , V_63 , 0 ) ;
#endif
F_5 ( V_6 , V_70 , V_122 ) ;
F_32 ( V_6 ) ;
F_3 ( V_6 , V_76 ) ;
if ( V_6 -> V_36 & V_115 )
F_5 ( V_6 , V_53 , V_113 ) ;
else
F_5 ( V_6 , V_53 , 0 ) ;
V_138:
F_55 ( & V_2 -> V_62 , V_102 ) ;
if ( V_6 -> V_36 != V_123 ) {
F_57 ( V_139
L_14 ,
F_1 ( V_2 ) , V_123 ,
V_6 -> V_36 ) ;
}
V_126:
F_46 ( L_15 , V_94 ) ;
F_46 ( L_16 , V_43 [ V_2 -> type ] . V_140 ) ;
}
static void F_58 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = & V_6 -> V_2 ;
unsigned char V_122 , V_141 ;
unsigned char V_142 = 0 ;
unsigned int V_143 = 0 ;
unsigned long V_144 ;
int V_145 ;
if ( V_2 -> V_102 & V_146 ) {
V_143 = ( V_2 -> V_17 & 0xfe0 ) | 0x1f ;
V_142 = F_59 ( V_143 ) ;
F_60 ( 0x80 , V_143 ) ;
F_59 ( V_143 ) ;
}
F_61 ( F_62 () ) ;
V_122 = F_3 ( V_6 , V_70 ) ;
V_141 = F_3 ( V_6 , V_53 ) ;
F_5 ( V_6 , V_70 , V_147 | V_148 ) ;
V_144 = F_62 () ;
F_5 ( V_6 , V_70 , 0 ) ;
F_63 ( 10 ) ;
if ( V_2 -> V_102 & V_146 ) {
F_5 ( V_6 , V_70 ,
V_149 | V_150 ) ;
} else {
F_5 ( V_6 , V_70 ,
V_149 | V_150 | V_148 ) ;
}
F_5 ( V_6 , V_53 , 0x0f ) ;
F_3 ( V_6 , V_74 ) ;
F_3 ( V_6 , V_76 ) ;
F_3 ( V_6 , V_111 ) ;
F_3 ( V_6 , V_128 ) ;
F_5 ( V_6 , V_73 , 0xFF ) ;
F_63 ( 20 ) ;
V_145 = F_61 ( V_144 ) ;
F_5 ( V_6 , V_70 , V_122 ) ;
F_5 ( V_6 , V_53 , V_141 ) ;
if ( V_2 -> V_102 & V_146 )
F_60 ( V_142 , V_143 ) ;
V_2 -> V_145 = ( V_145 > 0 ) ? V_145 : 0 ;
}
static inline void F_64 ( struct V_5 * V_10 )
{
if ( V_10 -> V_151 & V_152 ) {
V_10 -> V_151 &= ~ V_152 ;
F_5 ( V_10 , V_53 , V_10 -> V_151 ) ;
}
}
static void F_65 ( struct V_1 * V_2 )
{
struct V_5 * V_6 =
F_27 ( V_2 , struct V_5 , V_2 ) ;
F_64 ( V_6 ) ;
if ( V_2 -> type == V_88 ) {
V_6 -> V_34 |= V_153 ;
F_30 ( V_6 , V_33 , V_6 -> V_34 ) ;
}
}
static void F_66 ( struct V_1 * V_2 )
{
struct V_5 * V_6 =
F_27 ( V_2 , struct V_5 , V_2 ) ;
if ( V_6 -> V_154 && ! F_67 ( V_6 ) ) {
return;
} else if ( ! ( V_6 -> V_151 & V_152 ) ) {
V_6 -> V_151 |= V_152 ;
F_68 ( V_2 , V_53 , V_6 -> V_151 ) ;
if ( V_6 -> V_89 & V_155 ) {
unsigned char V_156 ;
V_156 = F_3 ( V_6 , V_74 ) ;
V_6 -> V_157 |= V_156 & V_158 ;
if ( V_156 & V_159 )
F_69 ( V_6 ) ;
}
}
if ( V_2 -> type == V_88 && V_6 -> V_34 & V_153 ) {
V_6 -> V_34 &= ~ V_153 ;
F_30 ( V_6 , V_33 , V_6 -> V_34 ) ;
}
}
static void F_70 ( struct V_1 * V_2 )
{
struct V_5 * V_6 =
F_27 ( V_2 , struct V_5 , V_2 ) ;
V_6 -> V_151 &= ~ V_160 ;
V_6 -> V_2 . V_161 &= ~ V_75 ;
F_68 ( V_2 , V_53 , V_6 -> V_151 ) ;
}
static void F_71 ( struct V_1 * V_2 )
{
struct V_5 * V_6 =
F_27 ( V_2 , struct V_5 , V_2 ) ;
if ( V_6 -> V_89 & V_162 )
return;
V_6 -> V_151 |= V_163 ;
F_68 ( V_2 , V_53 , V_6 -> V_151 ) ;
}
unsigned char
F_72 ( struct V_5 * V_6 , unsigned char V_156 )
{
struct V_1 * V_2 = & V_6 -> V_2 ;
unsigned char V_164 ;
int V_165 = 256 ;
char V_166 ;
do {
if ( F_73 ( V_156 & V_75 ) )
V_164 = F_3 ( V_6 , V_76 ) ;
else
V_164 = 0 ;
V_166 = V_167 ;
V_2 -> V_168 . V_169 ++ ;
V_156 |= V_6 -> V_157 ;
V_6 -> V_157 = 0 ;
if ( F_74 ( V_156 & V_170 ) ) {
if ( V_156 & V_171 ) {
V_156 &= ~ ( V_172 | V_173 ) ;
V_2 -> V_168 . V_174 ++ ;
if ( F_75 ( V_2 ) )
goto V_175;
} else if ( V_156 & V_173 )
V_2 -> V_168 . V_176 ++ ;
else if ( V_156 & V_172 )
V_2 -> V_168 . V_177 ++ ;
if ( V_156 & V_178 )
V_2 -> V_168 . V_179 ++ ;
V_156 &= V_2 -> V_161 ;
if ( V_156 & V_171 ) {
F_76 ( L_17 ) ;
V_166 = V_180 ;
} else if ( V_156 & V_173 )
V_166 = V_181 ;
else if ( V_156 & V_172 )
V_166 = V_182 ;
}
if ( F_77 ( V_2 , V_164 ) )
goto V_175;
F_78 ( V_2 , V_156 , V_178 , V_164 , V_166 ) ;
V_175:
V_156 = F_3 ( V_6 , V_74 ) ;
} while ( ( V_156 & ( V_75 | V_171 ) ) && ( V_165 -- > 0 ) );
F_79 ( & V_2 -> V_62 ) ;
F_80 ( & V_2 -> V_183 -> V_2 ) ;
F_81 ( & V_2 -> V_62 ) ;
return V_156 ;
}
void F_69 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = & V_6 -> V_2 ;
struct V_184 * V_185 = & V_2 -> V_183 -> V_185 ;
int V_69 ;
if ( V_2 -> V_186 ) {
F_5 ( V_6 , V_73 , V_2 -> V_186 ) ;
V_2 -> V_168 . V_187 ++ ;
V_2 -> V_186 = 0 ;
return;
}
if ( F_82 ( V_2 ) ) {
F_65 ( V_2 ) ;
return;
}
if ( F_83 ( V_185 ) ) {
F_64 ( V_6 ) ;
return;
}
V_69 = V_6 -> V_137 ;
do {
F_5 ( V_6 , V_73 , V_185 -> V_188 [ V_185 -> V_189 ] ) ;
V_185 -> V_189 = ( V_185 -> V_189 + 1 ) & ( V_190 - 1 ) ;
V_2 -> V_168 . V_187 ++ ;
if ( F_83 ( V_185 ) )
break;
if ( V_6 -> V_36 & V_191 ) {
if ( ( F_84 ( V_2 , V_74 ) & V_192 ) !=
V_192 )
break;
}
} while ( -- V_69 > 0 );
if ( F_85 ( V_185 ) < V_193 )
F_86 ( V_2 ) ;
F_76 ( L_18 ) ;
if ( F_83 ( V_185 ) )
F_64 ( V_6 ) ;
}
unsigned int F_87 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = & V_6 -> V_2 ;
unsigned int V_99 = F_3 ( V_6 , V_128 ) ;
V_99 |= V_6 -> V_194 ;
V_6 -> V_194 = 0 ;
if ( V_99 & V_195 && V_6 -> V_151 & V_163 &&
V_2 -> V_183 != NULL ) {
if ( V_99 & V_196 )
V_2 -> V_168 . V_197 ++ ;
if ( V_99 & V_198 )
V_2 -> V_168 . V_199 ++ ;
if ( V_99 & V_200 )
F_88 ( V_2 , V_99 & V_201 ) ;
if ( V_99 & V_202 )
F_89 ( V_2 , V_99 & V_203 ) ;
F_90 ( & V_2 -> V_183 -> V_2 . V_204 ) ;
}
return V_99 ;
}
int F_91 ( struct V_1 * V_2 , unsigned int V_205 )
{
unsigned char V_99 ;
unsigned long V_102 ;
struct V_5 * V_6 =
F_27 ( V_2 , struct V_5 , V_2 ) ;
int V_206 = 0 ;
if ( V_205 & V_207 )
return 0 ;
F_53 ( & V_2 -> V_62 , V_102 ) ;
V_99 = F_84 ( V_2 , V_74 ) ;
F_76 ( L_19 , V_99 ) ;
if ( V_99 & ( V_75 | V_171 ) ) {
if ( V_6 -> V_154 )
V_206 = F_92 ( V_6 , V_205 ) ;
if ( ! V_6 -> V_154 || V_206 )
V_99 = F_72 ( V_6 , V_99 ) ;
}
F_87 ( V_6 ) ;
if ( V_99 & V_208 )
F_69 ( V_6 ) ;
F_55 ( & V_2 -> V_62 , V_102 ) ;
return 1 ;
}
static int V_29 ( struct V_1 * V_2 )
{
unsigned int V_205 = F_84 ( V_2 , V_111 ) ;
return F_91 ( V_2 , V_205 ) ;
}
static int F_93 ( struct V_1 * V_2 )
{
unsigned char V_209 , V_210 , V_211 , V_212 ;
unsigned int V_205 = F_84 ( V_2 , V_111 ) ;
int V_213 ;
V_213 = F_91 ( V_2 , V_205 ) ;
if ( ( V_2 -> type == V_45 ) ||
( V_2 -> type == V_46 ) ) {
V_209 = F_84 ( V_2 , 0x80 ) ;
V_210 = F_84 ( V_2 , 0x81 ) ;
V_211 = F_84 ( V_2 , 0x82 ) ;
V_212 = F_84 ( V_2 , 0x83 ) ;
}
return V_213 ;
}
static T_2 F_94 ( int V_145 , void * V_214 )
{
struct V_215 * V_132 = V_214 ;
struct V_216 * V_217 , * V_218 = NULL ;
int V_219 = 0 , V_220 = 0 ;
F_76 ( L_20 , V_145 ) ;
F_81 ( & V_132 -> V_62 ) ;
V_217 = V_132 -> V_221 ;
do {
struct V_5 * V_6 ;
struct V_1 * V_2 ;
V_6 = F_95 ( V_217 , struct V_5 , V_222 ) ;
V_2 = & V_6 -> V_2 ;
if ( V_2 -> V_28 ( V_2 ) ) {
V_220 = 1 ;
V_218 = NULL ;
} else if ( V_218 == NULL )
V_218 = V_217 ;
V_217 = V_217 -> V_223 ;
if ( V_217 == V_132 -> V_221 && V_219 ++ > V_224 ) {
F_96 ( V_225
L_21 , V_145 ) ;
break;
}
} while ( V_217 != V_218 );
F_79 ( & V_132 -> V_62 ) ;
F_76 ( L_22 ) ;
return F_97 ( V_220 ) ;
}
static void F_98 ( struct V_215 * V_132 , struct V_5 * V_6 )
{
F_37 ( & V_132 -> V_62 ) ;
if ( ! F_99 ( V_132 -> V_221 ) ) {
if ( V_132 -> V_221 == & V_6 -> V_222 )
V_132 -> V_221 = V_132 -> V_221 -> V_223 ;
F_100 ( & V_6 -> V_222 ) ;
} else {
F_101 ( V_132 -> V_221 != & V_6 -> V_222 ) ;
V_132 -> V_221 = NULL ;
}
F_38 ( & V_132 -> V_62 ) ;
if ( V_132 -> V_221 == NULL ) {
F_102 ( & V_132 -> V_226 ) ;
F_103 ( V_132 ) ;
}
}
static int F_104 ( struct V_5 * V_6 )
{
struct V_227 * V_228 ;
struct V_229 * V_230 ;
struct V_215 * V_132 ;
int V_213 , V_231 = V_6 -> V_2 . V_102 & V_232 ? V_233 : 0 ;
F_105 ( & V_234 ) ;
V_228 = & V_235 [ V_6 -> V_2 . V_145 % V_236 ] ;
F_106 (n, h) {
V_132 = F_107 ( V_230 , struct V_215 , V_226 ) ;
if ( V_132 -> V_145 == V_6 -> V_2 . V_145 )
break;
}
if ( V_230 == NULL ) {
V_132 = F_108 ( sizeof( struct V_215 ) , V_237 ) ;
if ( V_132 == NULL ) {
F_109 ( & V_234 ) ;
return - V_238 ;
}
F_110 ( & V_132 -> V_62 ) ;
V_132 -> V_145 = V_6 -> V_2 . V_145 ;
F_111 ( & V_132 -> V_226 , V_228 ) ;
}
F_109 ( & V_234 ) ;
F_37 ( & V_132 -> V_62 ) ;
if ( V_132 -> V_221 ) {
F_112 ( & V_6 -> V_222 , V_132 -> V_221 ) ;
F_38 ( & V_132 -> V_62 ) ;
V_213 = 0 ;
} else {
F_113 ( & V_6 -> V_222 ) ;
V_132 -> V_221 = & V_6 -> V_222 ;
F_38 ( & V_132 -> V_62 ) ;
V_231 |= V_6 -> V_2 . V_239 ;
V_213 = F_114 ( V_6 -> V_2 . V_145 , F_94 ,
V_231 , L_23 , V_132 ) ;
if ( V_213 < 0 )
F_98 ( V_132 , V_6 ) ;
}
return V_213 ;
}
static void F_115 ( struct V_5 * V_6 )
{
struct V_215 * V_132 ;
struct V_229 * V_230 ;
struct V_227 * V_228 ;
F_105 ( & V_234 ) ;
V_228 = & V_235 [ V_6 -> V_2 . V_145 % V_236 ] ;
F_106 (n, h) {
V_132 = F_107 ( V_230 , struct V_215 , V_226 ) ;
if ( V_132 -> V_145 == V_6 -> V_2 . V_145 )
break;
}
F_101 ( V_230 == NULL ) ;
F_101 ( V_132 -> V_221 == NULL ) ;
if ( F_99 ( V_132 -> V_221 ) )
F_116 ( V_6 -> V_2 . V_145 , V_132 ) ;
F_98 ( V_132 , V_6 ) ;
F_109 ( & V_234 ) ;
}
static void F_117 ( unsigned long V_240 )
{
struct V_5 * V_6 = (struct V_5 * ) V_240 ;
V_6 -> V_2 . V_28 ( & V_6 -> V_2 ) ;
F_118 ( & V_6 -> V_241 , V_242 + F_119 ( & V_6 -> V_2 ) ) ;
}
static void F_120 ( unsigned long V_240 )
{
struct V_5 * V_6 = (struct V_5 * ) V_240 ;
unsigned int V_205 , V_151 = 0 , V_156 ;
unsigned long V_102 ;
F_53 ( & V_6 -> V_2 . V_62 , V_102 ) ;
if ( V_6 -> V_2 . V_145 ) {
V_151 = F_3 ( V_6 , V_53 ) ;
F_5 ( V_6 , V_53 , 0 ) ;
}
V_205 = F_3 ( V_6 , V_111 ) ;
V_156 = F_3 ( V_6 , V_74 ) ;
V_6 -> V_157 |= V_156 & V_158 ;
if ( ( V_205 & V_207 ) && ( V_6 -> V_151 & V_152 ) &&
( ! F_83 ( & V_6 -> V_2 . V_183 -> V_185 ) || V_6 -> V_2 . V_186 ) &&
( V_156 & V_208 ) ) {
V_205 &= ~ ( V_243 | V_207 ) ;
V_205 |= V_244 ;
}
if ( ! ( V_205 & V_207 ) )
F_69 ( V_6 ) ;
if ( V_6 -> V_2 . V_145 )
F_5 ( V_6 , V_53 , V_151 ) ;
F_55 ( & V_6 -> V_2 . V_62 , V_102 ) ;
F_118 ( & V_6 -> V_241 ,
V_242 + F_119 ( & V_6 -> V_2 ) + V_245 / 5 ) ;
}
static unsigned int F_121 ( struct V_1 * V_2 )
{
struct V_5 * V_6 =
F_27 ( V_2 , struct V_5 , V_2 ) ;
unsigned long V_102 ;
unsigned int V_156 ;
F_53 ( & V_2 -> V_62 , V_102 ) ;
V_156 = F_84 ( V_2 , V_74 ) ;
V_6 -> V_157 |= V_156 & V_158 ;
F_55 ( & V_2 -> V_62 , V_102 ) ;
return ( V_156 & V_192 ) == V_192 ? V_246 : 0 ;
}
static unsigned int F_122 ( struct V_1 * V_2 )
{
struct V_5 * V_6 =
F_27 ( V_2 , struct V_5 , V_2 ) ;
unsigned int V_99 ;
unsigned int V_213 ;
V_99 = F_87 ( V_6 ) ;
V_213 = 0 ;
if ( V_99 & V_201 )
V_213 |= V_247 ;
if ( V_99 & V_248 )
V_213 |= V_249 ;
if ( V_99 & V_250 )
V_213 |= V_251 ;
if ( V_99 & V_203 )
V_213 |= V_252 ;
return V_213 ;
}
static void F_123 ( struct V_1 * V_2 , unsigned int V_253 )
{
struct V_5 * V_6 =
F_27 ( V_2 , struct V_5 , V_2 ) ;
unsigned char V_254 = 0 ;
if ( V_253 & V_255 )
V_254 |= V_150 ;
if ( V_253 & V_256 )
V_254 |= V_149 ;
if ( V_253 & V_257 )
V_254 |= V_147 ;
if ( V_253 & V_258 )
V_254 |= V_148 ;
if ( V_253 & V_259 )
V_254 |= V_71 ;
V_254 = ( V_254 & V_6 -> V_260 ) | V_6 -> V_261 | V_6 -> V_254 ;
F_68 ( V_2 , V_70 , V_254 ) ;
}
static void F_124 ( struct V_1 * V_2 , int V_262 )
{
struct V_5 * V_6 =
F_27 ( V_2 , struct V_5 , V_2 ) ;
unsigned long V_102 ;
F_53 ( & V_2 -> V_62 , V_102 ) ;
if ( V_262 == - 1 )
V_6 -> V_263 |= V_264 ;
else
V_6 -> V_263 &= ~ V_264 ;
F_68 ( V_2 , V_30 , V_6 -> V_263 ) ;
F_55 ( & V_2 -> V_62 , V_102 ) ;
}
static void F_125 ( struct V_5 * V_6 , int V_265 )
{
unsigned int V_99 , V_266 = 10000 ;
for (; ; ) {
V_99 = F_3 ( V_6 , V_74 ) ;
V_6 -> V_157 |= V_99 & V_158 ;
if ( ( V_99 & V_265 ) == V_265 )
break;
if ( -- V_266 == 0 )
break;
F_63 ( 1 ) ;
}
if ( V_6 -> V_2 . V_102 & V_267 ) {
unsigned int V_266 ;
for ( V_266 = 1000000 ; V_266 ; V_266 -- ) {
unsigned int V_268 = F_3 ( V_6 , V_128 ) ;
V_6 -> V_194 |= V_268 & V_269 ;
if ( V_268 & V_203 )
break;
F_63 ( 1 ) ;
F_126 () ;
}
}
}
static int F_127 ( struct V_1 * V_2 )
{
unsigned char V_156 = F_84 ( V_2 , V_74 ) ;
if ( ! ( V_156 & V_75 ) )
return V_270 ;
return F_84 ( V_2 , V_76 ) ;
}
static void F_128 ( struct V_1 * V_2 ,
unsigned char V_271 )
{
unsigned int V_151 ;
struct V_5 * V_6 =
F_27 ( V_2 , struct V_5 , V_2 ) ;
V_151 = F_84 ( V_2 , V_53 ) ;
if ( V_6 -> V_36 & V_115 )
F_68 ( V_2 , V_53 , V_113 ) ;
else
F_68 ( V_2 , V_53 , 0 ) ;
F_125 ( V_6 , V_192 ) ;
F_68 ( V_2 , V_73 , V_271 ) ;
if ( V_271 == 10 ) {
F_125 ( V_6 , V_192 ) ;
F_68 ( V_2 , V_73 , 13 ) ;
}
F_125 ( V_6 , V_192 ) ;
F_68 ( V_2 , V_53 , V_151 ) ;
}
static int F_129 ( struct V_1 * V_2 )
{
struct V_5 * V_6 =
F_27 ( V_2 , struct V_5 , V_2 ) ;
unsigned long V_102 ;
unsigned char V_156 , V_205 ;
int V_272 ;
if ( V_2 -> type == V_273 )
return - V_274 ;
if ( ! V_2 -> V_135 )
V_2 -> V_135 = V_43 [ V_2 -> type ] . V_136 ;
if ( ! V_6 -> V_137 )
V_6 -> V_137 = V_43 [ V_2 -> type ] . V_137 ;
if ( ! V_6 -> V_36 )
V_6 -> V_36 = V_43 [ V_2 -> type ] . V_102 ;
V_6 -> V_254 = 0 ;
if ( V_2 -> V_20 != V_6 -> V_27 )
F_26 ( V_2 ) ;
if ( V_2 -> type == V_88 ) {
V_6 -> V_34 = 0 ;
F_68 ( V_2 , V_30 , V_50 ) ;
F_68 ( V_2 , V_51 , V_52 ) ;
F_68 ( V_2 , V_53 , 0 ) ;
F_68 ( V_2 , V_30 , 0 ) ;
F_30 ( V_6 , V_275 , 0 ) ;
F_68 ( V_2 , V_30 , V_50 ) ;
F_68 ( V_2 , V_51 , V_52 ) ;
F_68 ( V_2 , V_30 , 0 ) ;
}
#ifdef F_56
F_36 ( V_6 ) ;
#endif
F_32 ( V_6 ) ;
F_84 ( V_2 , V_74 ) ;
F_84 ( V_2 , V_76 ) ;
F_84 ( V_2 , V_111 ) ;
F_84 ( V_2 , V_128 ) ;
if ( ! ( V_2 -> V_102 & V_125 ) &&
( F_84 ( V_2 , V_74 ) == 0xff ) ) {
F_96 ( V_276 L_24 ,
F_1 ( V_2 ) ) ;
return - V_274 ;
}
if ( V_2 -> type == V_91 ) {
unsigned char V_277 ;
F_5 ( V_6 , V_30 , V_50 ) ;
V_277 = F_3 ( V_6 , V_278 ) & ~ ( V_279 | V_280 ) ;
F_68 ( V_2 , V_278 ,
V_277 | V_281 | V_279 ) ;
F_68 ( V_2 , V_282 , V_283 ) ;
F_68 ( V_2 , V_278 ,
V_277 | V_281 | V_280 ) ;
F_68 ( V_2 , V_282 , V_283 ) ;
F_68 ( V_2 , V_30 , 0 ) ;
}
if ( V_2 -> V_145 ) {
unsigned char V_284 ;
F_53 ( & V_2 -> V_62 , V_102 ) ;
if ( V_6 -> V_2 . V_239 & V_233 )
F_130 ( V_2 -> V_145 ) ;
F_125 ( V_6 , V_208 ) ;
F_29 ( V_2 , V_53 , V_152 ) ;
F_63 ( 1 ) ;
V_284 = F_84 ( V_2 , V_111 ) ;
F_68 ( V_2 , V_53 , 0 ) ;
F_29 ( V_2 , V_53 , V_152 ) ;
F_63 ( 1 ) ;
V_205 = F_84 ( V_2 , V_111 ) ;
F_68 ( V_2 , V_53 , 0 ) ;
if ( V_2 -> V_239 & V_233 )
F_131 ( V_2 -> V_145 ) ;
F_55 ( & V_2 -> V_62 , V_102 ) ;
if ( ( ! ( V_284 & V_207 ) && ( V_205 & V_207 ) ) ||
V_6 -> V_2 . V_102 & V_285 ) {
V_6 -> V_89 |= V_286 ;
F_132 ( L_25 ,
F_1 ( V_2 ) ) ;
}
}
if ( V_6 -> V_89 & V_286 ) {
V_6 -> V_241 . V_287 = F_120 ;
V_6 -> V_241 . V_240 = ( unsigned long ) V_6 ;
F_118 ( & V_6 -> V_241 , V_242 +
F_119 ( V_2 ) + V_245 / 5 ) ;
}
if ( ! V_2 -> V_145 ) {
V_6 -> V_241 . V_240 = ( unsigned long ) V_6 ;
F_118 ( & V_6 -> V_241 , V_242 + F_119 ( V_2 ) ) ;
} else {
V_272 = F_104 ( V_6 ) ;
if ( V_272 )
return V_272 ;
}
F_68 ( V_2 , V_30 , V_288 ) ;
F_53 ( & V_2 -> V_62 , V_102 ) ;
if ( V_6 -> V_2 . V_102 & V_146 ) {
if ( ! V_6 -> V_2 . V_145 )
V_6 -> V_2 . V_253 |= V_257 ;
} else
if ( V_2 -> V_145 )
V_6 -> V_2 . V_253 |= V_258 ;
F_123 ( V_2 , V_2 -> V_253 ) ;
if ( V_289 || V_6 -> V_2 . V_102 & V_290 )
goto V_291;
F_68 ( V_2 , V_53 , V_152 ) ;
V_156 = F_84 ( V_2 , V_74 ) ;
V_205 = F_84 ( V_2 , V_111 ) ;
F_68 ( V_2 , V_53 , 0 ) ;
if ( V_156 & V_159 && V_205 & V_207 ) {
if ( ! ( V_6 -> V_89 & V_155 ) ) {
V_6 -> V_89 |= V_155 ;
F_132 ( L_26 ,
F_1 ( V_2 ) ) ;
}
} else {
V_6 -> V_89 &= ~ V_155 ;
}
V_291:
F_55 ( & V_2 -> V_62 , V_102 ) ;
F_84 ( V_2 , V_74 ) ;
F_84 ( V_2 , V_76 ) ;
F_84 ( V_2 , V_111 ) ;
F_84 ( V_2 , V_128 ) ;
V_6 -> V_157 = 0 ;
V_6 -> V_194 = 0 ;
if ( V_6 -> V_154 ) {
V_272 = F_133 ( V_6 ) ;
if ( V_272 ) {
F_134 ( L_27 ,
F_1 ( V_2 ) ) ;
V_6 -> V_154 = NULL ;
}
}
V_6 -> V_151 = V_160 | V_292 ;
F_68 ( V_2 , V_53 , V_6 -> V_151 ) ;
if ( V_2 -> V_102 & V_146 ) {
unsigned int V_293 ;
V_293 = ( V_2 -> V_17 & 0xfe0 ) | 0x01f ;
F_60 ( 0x80 , V_293 ) ;
F_59 ( V_293 ) ;
}
return 0 ;
}
static void F_135 ( struct V_1 * V_2 )
{
struct V_5 * V_6 =
F_27 ( V_2 , struct V_5 , V_2 ) ;
unsigned long V_102 ;
V_6 -> V_151 = 0 ;
F_68 ( V_2 , V_53 , 0 ) ;
if ( V_6 -> V_154 )
F_136 ( V_6 ) ;
F_53 ( & V_2 -> V_62 , V_102 ) ;
if ( V_2 -> V_102 & V_146 ) {
F_14 ( ( V_2 -> V_17 & 0xfe0 ) | 0x1f ) ;
V_2 -> V_253 |= V_257 ;
} else
V_2 -> V_253 &= ~ V_258 ;
F_123 ( V_2 , V_2 -> V_253 ) ;
F_55 ( & V_2 -> V_62 , V_102 ) ;
F_68 ( V_2 , V_30 ,
F_84 ( V_2 , V_30 ) & ~ V_264 ) ;
F_32 ( V_6 ) ;
#ifdef F_56
F_39 ( V_6 ) ;
#endif
F_84 ( V_2 , V_76 ) ;
F_137 ( & V_6 -> V_241 ) ;
V_6 -> V_241 . V_287 = F_117 ;
if ( V_2 -> V_145 )
F_115 ( V_6 ) ;
}
static unsigned int F_138 ( struct V_1 * V_2 , unsigned int V_294 )
{
unsigned int V_107 ;
if ( ( V_2 -> V_102 & V_295 ) &&
V_294 == ( V_2 -> V_59 / 4 ) )
V_107 = 0x8001 ;
else if ( ( V_2 -> V_102 & V_295 ) &&
V_294 == ( V_2 -> V_59 / 8 ) )
V_107 = 0x8002 ;
else
V_107 = F_139 ( V_2 , V_294 ) ;
return V_107 ;
}
void
F_140 ( struct V_1 * V_2 , struct V_296 * V_297 ,
struct V_296 * V_298 )
{
struct V_5 * V_6 =
F_27 ( V_2 , struct V_5 , V_2 ) ;
unsigned char V_299 , V_42 = 0 ;
unsigned long V_102 ;
unsigned int V_294 , V_107 ;
int V_300 = 0 ;
switch ( V_297 -> V_301 & V_302 ) {
case V_303 :
V_299 = V_304 ;
break;
case V_305 :
V_299 = V_306 ;
break;
case V_307 :
V_299 = V_308 ;
break;
default:
case V_309 :
V_299 = V_288 ;
break;
}
if ( V_297 -> V_301 & V_310 )
V_299 |= V_311 ;
if ( V_297 -> V_301 & V_312 ) {
V_299 |= V_313 ;
if ( V_6 -> V_89 & V_314 )
V_300 = 1 ;
}
if ( ! ( V_297 -> V_301 & V_315 ) )
V_299 |= V_316 ;
#ifdef F_141
if ( V_297 -> V_301 & F_141 )
V_299 |= V_317 ;
#endif
V_294 = F_142 ( V_2 , V_297 , V_298 ,
V_2 -> V_59 / 16 / 0xffff ,
V_2 -> V_59 / 16 ) ;
V_107 = F_138 ( V_2 , V_294 ) ;
if ( V_6 -> V_89 & V_90 && ( V_107 & 0xff ) == 0 )
V_107 ++ ;
if ( V_6 -> V_36 & V_37 && V_2 -> V_135 > 1 ) {
V_42 = V_43 [ V_2 -> type ] . V_42 ;
if ( V_294 < 2400 || V_300 ) {
V_42 &= ~ V_318 ;
V_42 |= V_319 ;
}
}
if ( V_6 -> V_36 & V_105 && V_2 -> V_135 >= 32 ) {
V_6 -> V_254 &= ~ V_320 ;
if ( V_297 -> V_301 & V_321 )
V_6 -> V_254 |= V_320 ;
}
F_53 ( & V_2 -> V_62 , V_102 ) ;
F_143 ( V_2 , V_297 -> V_301 , V_294 ) ;
V_2 -> V_161 = V_178 | V_208 | V_75 ;
if ( V_297 -> V_322 & V_323 )
V_2 -> V_161 |= V_172 | V_173 ;
if ( V_297 -> V_322 & ( V_324 | V_325 ) )
V_2 -> V_161 |= V_171 ;
V_2 -> V_326 = 0 ;
if ( V_297 -> V_322 & V_327 )
V_2 -> V_326 |= V_173 | V_172 ;
if ( V_297 -> V_322 & V_328 ) {
V_2 -> V_326 |= V_171 ;
if ( V_297 -> V_322 & V_327 )
V_2 -> V_326 |= V_178 ;
}
if ( ( V_297 -> V_301 & V_329 ) == 0 )
V_2 -> V_326 |= V_75 ;
V_6 -> V_151 &= ~ V_163 ;
if ( ! ( V_6 -> V_89 & V_162 ) &&
F_144 ( & V_6 -> V_2 , V_297 -> V_301 ) )
V_6 -> V_151 |= V_163 ;
if ( V_6 -> V_36 & V_115 )
V_6 -> V_151 |= V_113 ;
if ( V_6 -> V_36 & V_116 )
V_6 -> V_151 |= V_330 ;
F_68 ( V_2 , V_53 , V_6 -> V_151 ) ;
if ( V_6 -> V_36 & V_49 ) {
unsigned char V_331 = 0 ;
if ( V_297 -> V_301 & V_321 )
V_331 |= V_332 ;
F_68 ( V_2 , V_30 , V_50 ) ;
if ( V_2 -> V_102 & V_103 )
F_68 ( V_2 , V_333 , V_331 ) ;
else
F_68 ( V_2 , V_51 , V_331 ) ;
}
if ( F_145 ( V_6 ) ) {
if ( V_294 == 115200 ) {
V_107 = 1 ;
F_68 ( V_2 , V_334 , 1 ) ;
} else
F_68 ( V_2 , V_334 , 0 ) ;
}
if ( V_6 -> V_36 & V_109 )
F_68 ( V_2 , V_30 , 0xe0 ) ;
else
F_68 ( V_2 , V_30 , V_299 | V_335 ) ;
F_42 ( V_6 , V_107 ) ;
if ( V_2 -> type == V_112 )
F_68 ( V_2 , V_38 , V_42 ) ;
F_68 ( V_2 , V_30 , V_299 ) ;
V_6 -> V_263 = V_299 ;
if ( V_2 -> type != V_112 ) {
if ( V_42 & V_39 )
F_68 ( V_2 , V_38 , V_39 ) ;
F_68 ( V_2 , V_38 , V_42 ) ;
}
F_123 ( V_2 , V_2 -> V_253 ) ;
F_55 ( & V_2 -> V_62 , V_102 ) ;
if ( F_146 ( V_297 ) )
F_147 ( V_297 , V_294 , V_294 ) ;
}
static void
F_148 ( struct V_1 * V_2 , struct V_296 * V_297 ,
struct V_296 * V_298 )
{
if ( V_2 -> V_336 )
V_2 -> V_336 ( V_2 , V_297 , V_298 ) ;
else
F_140 ( V_2 , V_297 , V_298 ) ;
}
static void
F_149 ( struct V_1 * V_2 , int V_337 )
{
if ( V_337 == V_338 ) {
V_2 -> V_102 |= V_339 ;
F_71 ( V_2 ) ;
} else
V_2 -> V_102 &= ~ V_339 ;
}
void F_150 ( struct V_1 * V_2 , unsigned int V_183 ,
unsigned int V_340 )
{
struct V_5 * V_10 =
F_27 ( V_2 , struct V_5 , V_2 ) ;
F_34 ( V_10 , V_183 != 0 ) ;
}
static void
F_151 ( struct V_1 * V_2 , unsigned int V_183 ,
unsigned int V_340 )
{
if ( V_2 -> V_341 )
V_2 -> V_341 ( V_2 , V_183 , V_340 ) ;
else
F_150 ( V_2 , V_183 , V_340 ) ;
}
static unsigned int F_152 ( struct V_5 * V_342 )
{
if ( V_342 -> V_2 . V_20 == V_26 )
return 0x1000 ;
if ( F_153 ( V_342 ) )
return 0x16 << V_342 -> V_2 . V_13 ;
return 8 << V_342 -> V_2 . V_13 ;
}
static int F_154 ( struct V_5 * V_6 )
{
unsigned int V_343 = F_152 ( V_6 ) ;
struct V_1 * V_2 = & V_6 -> V_2 ;
int V_213 = 0 ;
switch ( V_2 -> V_20 ) {
case V_26 :
case V_344 :
case V_23 :
case V_22 :
if ( ! V_2 -> V_124 )
break;
if ( ! F_155 ( V_2 -> V_124 , V_343 , L_23 ) ) {
V_213 = - V_345 ;
break;
}
if ( V_2 -> V_102 & V_346 ) {
V_2 -> V_14 = F_156 ( V_2 -> V_124 , V_343 ) ;
if ( ! V_2 -> V_14 ) {
F_157 ( V_2 -> V_124 , V_343 ) ;
V_213 = - V_238 ;
}
}
break;
case V_21 :
case V_347 :
if ( ! F_158 ( V_2 -> V_17 , V_343 , L_23 ) )
V_213 = - V_345 ;
break;
}
return V_213 ;
}
static void F_159 ( struct V_5 * V_6 )
{
unsigned int V_343 = F_152 ( V_6 ) ;
struct V_1 * V_2 = & V_6 -> V_2 ;
switch ( V_2 -> V_20 ) {
case V_26 :
case V_344 :
case V_23 :
case V_22 :
if ( ! V_2 -> V_124 )
break;
if ( V_2 -> V_102 & V_346 ) {
F_160 ( V_2 -> V_14 ) ;
V_2 -> V_14 = NULL ;
}
F_157 ( V_2 -> V_124 , V_343 ) ;
break;
case V_21 :
case V_347 :
F_161 ( V_2 -> V_17 , V_343 ) ;
break;
}
}
static int F_162 ( struct V_5 * V_6 )
{
unsigned long V_348 = V_349 << V_6 -> V_2 . V_13 ;
unsigned int V_343 = 8 << V_6 -> V_2 . V_13 ;
struct V_1 * V_2 = & V_6 -> V_2 ;
int V_213 = - V_350 ;
switch ( V_2 -> V_20 ) {
case V_21 :
case V_347 :
V_348 += V_2 -> V_17 ;
if ( F_158 ( V_348 , V_343 , L_28 ) )
V_213 = 0 ;
else
V_213 = - V_345 ;
break;
}
return V_213 ;
}
static void F_163 ( struct V_5 * V_6 )
{
unsigned long V_11 = V_349 << V_6 -> V_2 . V_13 ;
unsigned int V_343 = 8 << V_6 -> V_2 . V_13 ;
struct V_1 * V_2 = & V_6 -> V_2 ;
switch ( V_2 -> V_20 ) {
case V_21 :
case V_347 :
F_161 ( V_2 -> V_17 + V_11 , V_343 ) ;
break;
}
}
static void F_164 ( struct V_1 * V_2 )
{
struct V_5 * V_6 =
F_27 ( V_2 , struct V_5 , V_2 ) ;
F_159 ( V_6 ) ;
if ( V_2 -> type == V_61 )
F_163 ( V_6 ) ;
}
static int F_165 ( struct V_1 * V_2 )
{
struct V_5 * V_6 =
F_27 ( V_2 , struct V_5 , V_2 ) ;
int V_213 ;
if ( V_2 -> type == V_273 )
return - V_274 ;
V_213 = F_154 ( V_6 ) ;
if ( V_213 == 0 && V_2 -> type == V_61 ) {
V_213 = F_162 ( V_6 ) ;
if ( V_213 < 0 )
F_159 ( V_6 ) ;
}
return V_213 ;
}
static void F_166 ( struct V_1 * V_2 , int V_102 )
{
struct V_5 * V_6 =
F_27 ( V_2 , struct V_5 , V_2 ) ;
int V_118 = V_351 ;
int V_213 ;
if ( V_2 -> type == V_273 )
return;
V_213 = F_154 ( V_6 ) ;
if ( V_213 < 0 )
return;
V_213 = F_162 ( V_6 ) ;
if ( V_213 < 0 )
V_118 &= ~ V_131 ;
if ( V_2 -> V_20 != V_6 -> V_27 )
F_26 ( V_2 ) ;
if ( V_102 & V_352 )
F_52 ( V_6 , V_118 ) ;
if ( V_2 -> type == V_101 && V_2 -> V_20 == V_26 )
V_6 -> V_89 |= V_162 ;
if ( V_2 -> type != V_129 && V_102 & V_353 )
F_58 ( V_6 ) ;
if ( V_2 -> type != V_61 && V_118 & V_131 )
F_163 ( V_6 ) ;
if ( V_2 -> type == V_129 )
F_159 ( V_6 ) ;
if ( ( V_2 -> type == V_45 ) ||
( V_2 -> type == V_46 ) )
V_2 -> V_28 = F_93 ;
}
static int
F_167 ( struct V_1 * V_2 , struct V_354 * V_355 )
{
if ( V_355 -> V_145 >= V_356 || V_355 -> V_145 < 0 ||
V_355 -> V_357 < 9600 || V_355 -> type < V_129 ||
V_355 -> type >= F_168 ( V_43 ) || V_355 -> type == V_358 ||
V_355 -> type == V_359 )
return - V_350 ;
return 0 ;
}
static const char *
F_169 ( struct V_1 * V_2 )
{
int type = V_2 -> type ;
if ( type >= F_168 ( V_43 ) )
type = 0 ;
return V_43 [ type ] . V_140 ;
}
void F_170 (
void (* F_171)( int V_2 , struct V_1 * V_6 , unsigned short * V_36 ) )
{
V_360 = F_171 ;
}
static void T_3 F_172 ( void )
{
struct V_5 * V_6 ;
static int V_361 = 1 ;
int V_132 , V_362 = 0 ;
if ( ! V_361 )
return;
V_361 = 0 ;
if ( V_363 > V_364 )
V_363 = V_364 ;
for ( V_132 = 0 ; V_132 < V_363 ; V_132 ++ ) {
struct V_5 * V_6 = & V_365 [ V_132 ] ;
struct V_1 * V_2 = & V_6 -> V_2 ;
V_2 -> line = V_132 ;
F_110 ( & V_2 -> V_62 ) ;
F_173 ( & V_6 -> V_241 ) ;
V_6 -> V_241 . V_287 = F_117 ;
V_6 -> V_27 = 0xFF ;
V_6 -> V_260 = ~ V_366 ;
V_6 -> V_261 = V_366 ;
V_2 -> V_367 = & V_368 ;
}
if ( V_369 )
V_362 = V_233 ;
for ( V_132 = 0 , V_6 = V_365 ;
V_132 < F_168 ( V_370 ) && V_132 < V_363 ;
V_132 ++ , V_6 ++ ) {
struct V_1 * V_2 = & V_6 -> V_2 ;
V_2 -> V_17 = V_370 [ V_132 ] . V_2 ;
V_2 -> V_145 = F_174 ( V_370 [ V_132 ] . V_145 ) ;
V_2 -> V_239 = V_370 [ V_132 ] . V_239 ;
V_2 -> V_59 = V_370 [ V_132 ] . V_357 * 16 ;
V_2 -> V_102 = V_370 [ V_132 ] . V_102 ;
V_2 -> V_16 = V_370 [ V_132 ] . V_16 ;
V_2 -> V_14 = V_370 [ V_132 ] . V_371 ;
V_2 -> V_20 = V_370 [ V_132 ] . V_372 ;
V_2 -> V_13 = V_370 [ V_132 ] . V_373 ;
F_26 ( V_2 ) ;
V_2 -> V_239 |= V_362 ;
if ( V_360 != NULL )
V_360 ( V_132 , & V_6 -> V_2 , & V_6 -> V_36 ) ;
}
}
static void
F_175 ( struct V_5 * V_6 , unsigned int type )
{
V_6 -> V_2 . type = type ;
if ( ! V_6 -> V_2 . V_135 )
V_6 -> V_2 . V_135 = V_43 [ type ] . V_136 ;
if ( ! V_6 -> V_137 )
V_6 -> V_137 = V_43 [ type ] . V_137 ;
if ( ! V_6 -> V_36 )
V_6 -> V_36 = V_43 [ type ] . V_102 ;
}
static void T_3
F_176 ( struct V_374 * V_375 , struct V_376 * V_377 )
{
int V_132 ;
for ( V_132 = 0 ; V_132 < V_363 ; V_132 ++ ) {
struct V_5 * V_6 = & V_365 [ V_132 ] ;
if ( V_6 -> V_2 . V_377 )
continue;
V_6 -> V_2 . V_377 = V_377 ;
if ( V_6 -> V_2 . V_102 & V_378 )
F_175 ( V_6 , V_6 -> V_2 . type ) ;
F_177 ( V_375 , & V_6 -> V_2 ) ;
}
}
static void F_178 ( struct V_1 * V_2 , int V_164 )
{
struct V_5 * V_6 =
F_27 ( V_2 , struct V_5 , V_2 ) ;
F_125 ( V_6 , V_208 ) ;
F_68 ( V_2 , V_73 , V_164 ) ;
}
static void
F_179 ( struct V_379 * V_380 , const char * V_381 , unsigned int V_69 )
{
struct V_5 * V_6 = & V_365 [ V_380 -> V_382 ] ;
struct V_1 * V_2 = & V_6 -> V_2 ;
unsigned long V_102 ;
unsigned int V_151 ;
int V_383 = 1 ;
F_126 () ;
F_180 ( V_102 ) ;
if ( V_2 -> V_384 ) {
V_383 = 0 ;
} else if ( V_385 ) {
V_383 = F_181 ( & V_2 -> V_62 ) ;
} else
F_81 ( & V_2 -> V_62 ) ;
V_151 = F_84 ( V_2 , V_53 ) ;
if ( V_6 -> V_36 & V_115 )
F_68 ( V_2 , V_53 , V_113 ) ;
else
F_68 ( V_2 , V_53 , 0 ) ;
F_182 ( V_2 , V_381 , V_69 , F_178 ) ;
F_125 ( V_6 , V_192 ) ;
F_68 ( V_2 , V_53 , V_151 ) ;
if ( V_6 -> V_194 )
F_87 ( V_6 ) ;
if ( V_383 )
F_79 ( & V_2 -> V_62 ) ;
F_183 ( V_102 ) ;
}
static int T_3 F_184 ( struct V_379 * V_380 , char * V_386 )
{
struct V_1 * V_2 ;
int V_294 = 9600 ;
int V_265 = 8 ;
int V_176 = 'n' ;
int V_387 = 'n' ;
if ( V_380 -> V_382 >= V_363 )
V_380 -> V_382 = 0 ;
V_2 = & V_365 [ V_380 -> V_382 ] . V_2 ;
if ( ! V_2 -> V_17 && ! V_2 -> V_14 )
return - V_274 ;
if ( V_386 )
F_185 ( V_386 , & V_294 , & V_176 , & V_265 , & V_387 ) ;
return F_186 ( V_2 , V_380 , V_294 , V_176 , V_265 , V_387 ) ;
}
static int F_187 ( void )
{
return F_188 () ;
}
static int T_3 F_189 ( void )
{
F_172 () ;
F_190 ( & V_388 ) ;
return 0 ;
}
int F_191 ( struct V_1 * V_10 )
{
int line ;
struct V_1 * V_2 ;
for ( line = 0 ; line < V_363 ; line ++ ) {
V_2 = & V_365 [ line ] . V_2 ;
if ( F_192 ( V_10 , V_2 ) )
return line ;
}
return - V_274 ;
}
int T_3 F_193 ( struct V_1 * V_2 )
{
struct V_1 * V_10 ;
if ( V_2 -> line >= F_168 ( V_365 ) )
return - V_274 ;
F_172 () ;
V_10 = & V_365 [ V_2 -> line ] . V_2 ;
V_10 -> V_17 = V_2 -> V_17 ;
V_10 -> V_14 = V_2 -> V_14 ;
V_10 -> V_145 = V_2 -> V_145 ;
V_10 -> V_239 = V_2 -> V_239 ;
V_10 -> V_59 = V_2 -> V_59 ;
V_10 -> V_135 = V_2 -> V_135 ;
V_10 -> V_13 = V_2 -> V_13 ;
V_10 -> V_20 = V_2 -> V_20 ;
V_10 -> V_102 = V_2 -> V_102 ;
V_10 -> V_124 = V_2 -> V_124 ;
V_10 -> V_389 = V_2 -> V_389 ;
V_10 -> type = V_2 -> type ;
V_10 -> line = V_2 -> line ;
F_26 ( V_10 ) ;
if ( V_2 -> F_3 )
V_10 -> F_3 = V_2 -> F_3 ;
if ( V_2 -> F_5 )
V_10 -> F_5 = V_2 -> F_5 ;
if ( V_2 -> V_28 )
V_10 -> V_28 = V_2 -> V_28 ;
else
V_10 -> V_28 = V_29 ;
return 0 ;
}
void F_194 ( int line )
{
F_195 ( & V_3 , & V_365 [ line ] . V_2 ) ;
}
void F_196 ( int line )
{
struct V_5 * V_6 = & V_365 [ line ] ;
struct V_1 * V_2 = & V_6 -> V_2 ;
if ( V_6 -> V_36 & V_109 ) {
F_68 ( V_2 , V_30 , 0xE0 ) ;
F_49 ( V_6 ) ;
F_68 ( V_2 , V_30 , 0 ) ;
V_2 -> V_59 = 921600 * 16 ;
}
F_197 ( & V_3 , V_2 ) ;
}
static int F_198 ( struct V_390 * V_377 )
{
struct V_391 * V_10 = V_377 -> V_377 . V_392 ;
struct V_5 V_393 ;
int V_213 , V_132 , V_362 = 0 ;
memset ( & V_393 , 0 , sizeof( V_393 ) ) ;
if ( V_369 )
V_362 = V_233 ;
for ( V_132 = 0 ; V_10 && V_10 -> V_102 != 0 ; V_10 ++ , V_132 ++ ) {
V_393 . V_2 . V_17 = V_10 -> V_17 ;
V_393 . V_2 . V_14 = V_10 -> V_14 ;
V_393 . V_2 . V_145 = V_10 -> V_145 ;
V_393 . V_2 . V_239 = V_10 -> V_239 ;
V_393 . V_2 . V_59 = V_10 -> V_59 ;
V_393 . V_2 . V_13 = V_10 -> V_13 ;
V_393 . V_2 . V_20 = V_10 -> V_20 ;
V_393 . V_2 . V_102 = V_10 -> V_102 ;
V_393 . V_2 . V_124 = V_10 -> V_124 ;
V_393 . V_2 . V_16 = V_10 -> V_16 ;
V_393 . V_2 . V_389 = V_10 -> V_389 ;
V_393 . V_2 . type = V_10 -> type ;
V_393 . V_2 . F_3 = V_10 -> F_3 ;
V_393 . V_2 . F_5 = V_10 -> F_5 ;
V_393 . V_2 . V_28 = V_10 -> V_28 ;
V_393 . V_2 . V_394 = V_10 -> V_394 ;
V_393 . V_2 . V_336 = V_10 -> V_336 ;
V_393 . V_2 . V_341 = V_10 -> V_341 ;
V_393 . V_2 . V_377 = & V_377 -> V_377 ;
V_393 . V_2 . V_239 |= V_362 ;
V_213 = F_199 ( & V_393 ) ;
if ( V_213 < 0 ) {
F_200 ( & V_377 -> V_377 , L_29
L_30 , V_132 ,
V_10 -> V_17 , ( unsigned long long ) V_10 -> V_124 ,
V_10 -> V_145 , V_213 ) ;
}
}
return 0 ;
}
static int F_201 ( struct V_390 * V_377 )
{
int V_132 ;
for ( V_132 = 0 ; V_132 < V_363 ; V_132 ++ ) {
struct V_5 * V_6 = & V_365 [ V_132 ] ;
if ( V_6 -> V_2 . V_377 == & V_377 -> V_377 )
F_202 ( V_132 ) ;
}
return 0 ;
}
static int F_203 ( struct V_390 * V_377 , T_4 V_183 )
{
int V_132 ;
for ( V_132 = 0 ; V_132 < V_364 ; V_132 ++ ) {
struct V_5 * V_6 = & V_365 [ V_132 ] ;
if ( V_6 -> V_2 . type != V_129 && V_6 -> V_2 . V_377 == & V_377 -> V_377 )
F_195 ( & V_3 , & V_6 -> V_2 ) ;
}
return 0 ;
}
static int F_204 ( struct V_390 * V_377 )
{
int V_132 ;
for ( V_132 = 0 ; V_132 < V_364 ; V_132 ++ ) {
struct V_5 * V_6 = & V_365 [ V_132 ] ;
if ( V_6 -> V_2 . type != V_129 && V_6 -> V_2 . V_377 == & V_377 -> V_377 )
F_196 ( V_132 ) ;
}
return 0 ;
}
static struct V_5 * F_205 ( struct V_1 * V_2 )
{
int V_132 ;
for ( V_132 = 0 ; V_132 < V_363 ; V_132 ++ )
if ( F_192 ( & V_365 [ V_132 ] . V_2 , V_2 ) )
return & V_365 [ V_132 ] ;
for ( V_132 = 0 ; V_132 < V_363 ; V_132 ++ )
if ( V_365 [ V_132 ] . V_2 . type == V_129 &&
V_365 [ V_132 ] . V_2 . V_17 == 0 )
return & V_365 [ V_132 ] ;
for ( V_132 = 0 ; V_132 < V_363 ; V_132 ++ )
if ( V_365 [ V_132 ] . V_2 . type == V_129 )
return & V_365 [ V_132 ] ;
return NULL ;
}
int F_199 ( struct V_5 * V_6 )
{
struct V_5 * V_393 ;
int V_213 = - V_395 ;
if ( V_6 -> V_2 . V_59 == 0 )
return - V_350 ;
F_105 ( & V_396 ) ;
V_393 = F_205 ( & V_6 -> V_2 ) ;
if ( V_393 && V_393 -> V_2 . type != V_273 ) {
if ( V_393 -> V_2 . V_377 )
F_206 ( & V_3 , & V_393 -> V_2 ) ;
V_393 -> V_2 . V_17 = V_6 -> V_2 . V_17 ;
V_393 -> V_2 . V_14 = V_6 -> V_2 . V_14 ;
V_393 -> V_2 . V_145 = V_6 -> V_2 . V_145 ;
V_393 -> V_2 . V_239 = V_6 -> V_2 . V_239 ;
V_393 -> V_2 . V_59 = V_6 -> V_2 . V_59 ;
V_393 -> V_2 . V_135 = V_6 -> V_2 . V_135 ;
V_393 -> V_2 . V_13 = V_6 -> V_2 . V_13 ;
V_393 -> V_2 . V_20 = V_6 -> V_2 . V_20 ;
V_393 -> V_2 . V_102 = V_6 -> V_2 . V_102 | V_397 ;
V_393 -> V_89 = V_6 -> V_89 ;
V_393 -> V_2 . V_124 = V_6 -> V_2 . V_124 ;
V_393 -> V_2 . V_389 = V_6 -> V_2 . V_389 ;
V_393 -> V_2 . V_135 = V_6 -> V_2 . V_135 ;
V_393 -> V_137 = V_6 -> V_137 ;
V_393 -> V_36 = V_6 -> V_36 ;
if ( V_6 -> V_2 . V_377 )
V_393 -> V_2 . V_377 = V_6 -> V_2 . V_377 ;
if ( V_6 -> V_2 . V_102 & V_378 )
F_175 ( V_393 , V_6 -> V_2 . type ) ;
F_26 ( & V_393 -> V_2 ) ;
if ( V_6 -> V_2 . F_3 )
V_393 -> V_2 . F_3 = V_6 -> V_2 . F_3 ;
if ( V_6 -> V_2 . F_5 )
V_393 -> V_2 . F_5 = V_6 -> V_2 . F_5 ;
if ( V_6 -> V_2 . V_28 )
V_393 -> V_2 . V_28 = V_6 -> V_2 . V_28 ;
if ( V_6 -> V_2 . V_336 )
V_393 -> V_2 . V_336 = V_6 -> V_2 . V_336 ;
if ( V_6 -> V_2 . V_341 )
V_393 -> V_2 . V_341 = V_6 -> V_2 . V_341 ;
if ( V_6 -> V_2 . V_394 )
V_393 -> V_2 . V_394 = V_6 -> V_2 . V_394 ;
if ( V_6 -> V_18 )
V_393 -> V_18 = V_6 -> V_18 ;
if ( V_6 -> V_19 )
V_393 -> V_19 = V_6 -> V_19 ;
if ( V_6 -> V_154 )
V_393 -> V_154 = V_6 -> V_154 ;
if ( V_360 != NULL )
V_360 ( 0 , & V_393 -> V_2 ,
& V_393 -> V_36 ) ;
V_213 = F_177 ( & V_3 , & V_393 -> V_2 ) ;
if ( V_213 == 0 )
V_213 = V_393 -> V_2 . line ;
}
F_109 ( & V_396 ) ;
return V_213 ;
}
void F_202 ( int line )
{
struct V_5 * V_393 = & V_365 [ line ] ;
F_105 ( & V_396 ) ;
F_206 ( & V_3 , & V_393 -> V_2 ) ;
if ( V_398 ) {
V_393 -> V_2 . V_102 &= ~ V_397 ;
V_393 -> V_2 . type = V_129 ;
V_393 -> V_2 . V_377 = & V_398 -> V_377 ;
V_393 -> V_36 = V_43 [ V_393 -> V_2 . type ] . V_102 ;
F_177 ( & V_3 , & V_393 -> V_2 ) ;
} else {
V_393 -> V_2 . V_377 = NULL ;
}
F_109 ( & V_396 ) ;
}
static int T_3 F_207 ( void )
{
int V_213 ;
F_172 () ;
F_57 ( V_276 L_31
L_32 , V_363 ,
V_369 ? L_33 : L_34 ) ;
#ifdef F_208
V_213 = F_209 ( & V_3 , V_364 ) ;
#else
V_3 . V_399 = V_364 ;
V_213 = F_210 ( & V_3 ) ;
#endif
if ( V_213 )
goto V_126;
V_213 = F_211 () ;
if ( V_213 )
goto V_400;
V_398 = F_212 ( L_35 ,
V_401 ) ;
if ( ! V_398 ) {
V_213 = - V_238 ;
goto V_402;
}
V_213 = F_213 ( V_398 ) ;
if ( V_213 )
goto V_403;
F_176 ( & V_3 , & V_398 -> V_377 ) ;
V_213 = F_214 ( & V_404 ) ;
if ( V_213 == 0 )
goto V_126;
F_215 ( V_398 ) ;
V_403:
F_216 ( V_398 ) ;
V_402:
F_217 () ;
V_400:
#ifdef F_208
F_218 ( & V_3 , V_364 ) ;
#else
F_219 ( & V_3 ) ;
#endif
V_126:
return V_213 ;
}
static void T_5 F_220 ( void )
{
struct V_390 * V_405 = V_398 ;
V_398 = NULL ;
F_221 ( & V_404 ) ;
F_222 ( V_405 ) ;
F_217 () ;
#ifdef F_208
F_218 ( & V_3 , V_364 ) ;
#else
F_219 ( & V_3 ) ;
#endif
}
static void T_6 F_223 ( void )
{
#undef V_406
#define V_406 "8250_core."
F_224 ( V_369 , & V_407 , & V_369 , 0644 ) ;
F_224 ( V_363 , & V_407 , & V_363 , 0644 ) ;
F_224 ( V_289 , & V_407 , & V_289 , 0644 ) ;
#ifdef F_56
F_225 ( V_406 , V_134 ,
& V_408 , . V_409 = & V_410 ,
0444 , - 1 ) ;
#endif
}
