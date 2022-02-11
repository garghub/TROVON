static int F_1 ( struct V_1 * V_2 )
{
return ( V_3 . V_4 - 64 ) + V_2 -> line ;
}
static inline int F_2 ( struct V_1 * V_5 , int V_6 )
{
if ( V_5 -> V_7 != V_8 )
return V_6 ;
return V_9 [ V_6 ] ;
}
static inline int F_3 ( struct V_1 * V_5 , int V_6 )
{
if ( V_5 -> V_7 != V_8 )
return V_6 ;
return V_10 [ V_6 ] ;
}
static inline int F_2 ( struct V_1 * V_5 , int V_6 )
{
if ( V_5 -> V_7 != V_11 )
return V_6 ;
return V_12 [ V_6 ] ;
}
static inline int F_3 ( struct V_1 * V_5 , int V_6 )
{
if ( V_5 -> V_7 != V_11 )
return V_6 ;
return V_13 [ V_6 ] ;
}
static unsigned int F_4 ( struct V_1 * V_5 , int V_6 )
{
V_6 = F_2 ( V_5 , V_6 ) << V_5 -> V_14 ;
F_5 ( V_5 -> V_15 - 1 + V_6 , V_5 -> V_16 ) ;
return F_6 ( V_5 -> V_16 + 1 ) ;
}
static void F_7 ( struct V_1 * V_5 , int V_6 , int V_17 )
{
V_6 = F_3 ( V_5 , V_6 ) << V_5 -> V_14 ;
F_5 ( V_5 -> V_15 - 1 + V_6 , V_5 -> V_16 ) ;
F_5 ( V_17 , V_5 -> V_16 + 1 ) ;
}
static unsigned int F_8 ( struct V_1 * V_5 , int V_6 )
{
V_6 = F_2 ( V_5 , V_6 ) << V_5 -> V_14 ;
return F_9 ( V_5 -> V_18 + V_6 ) ;
}
static void F_10 ( struct V_1 * V_5 , int V_6 , int V_17 )
{
V_6 = F_3 ( V_5 , V_6 ) << V_5 -> V_14 ;
F_11 ( V_17 , V_5 -> V_18 + V_6 ) ;
}
static void F_12 ( struct V_1 * V_5 , int V_6 , int V_17 )
{
V_6 = F_3 ( V_5 , V_6 ) << V_5 -> V_14 ;
F_13 ( V_17 , V_5 -> V_18 + V_6 ) ;
}
static unsigned int F_14 ( struct V_1 * V_5 , int V_6 )
{
V_6 = F_2 ( V_5 , V_6 ) << V_5 -> V_14 ;
return F_15 ( V_5 -> V_18 + V_6 ) ;
}
static unsigned int F_16 ( struct V_1 * V_5 , int V_6 )
{
V_6 = F_2 ( V_5 , V_6 ) << V_5 -> V_14 ;
return F_17 ( V_5 -> V_18 + V_6 ) ;
}
static void F_18 ( struct V_1 * V_5 , int V_6 , int V_17 )
{
V_6 = F_3 ( V_5 , V_6 ) << V_5 -> V_14 ;
F_19 ( V_17 , V_5 -> V_18 + V_6 ) ;
}
static unsigned int F_20 ( struct V_1 * V_5 , int V_6 )
{
V_6 = F_2 ( V_5 , V_6 ) << V_5 -> V_14 ;
return F_6 ( V_5 -> V_16 + V_6 ) ;
}
static void F_21 ( struct V_1 * V_5 , int V_6 , int V_17 )
{
V_6 = F_3 ( V_5 , V_6 ) << V_5 -> V_14 ;
F_5 ( V_17 , V_5 -> V_16 + V_6 ) ;
}
static void F_22 ( struct V_1 * V_5 )
{
struct V_19 * V_20 =
F_23 ( V_5 , struct V_19 , V_2 ) ;
switch ( V_5 -> V_7 ) {
case V_21 :
V_5 -> V_22 = F_4 ;
V_5 -> V_23 = F_7 ;
break;
case V_24 :
V_5 -> V_22 = F_8 ;
V_5 -> V_23 = F_10 ;
break;
case V_11 :
case V_25 :
V_5 -> V_22 = F_14 ;
V_5 -> V_23 = F_12 ;
break;
case V_8 :
V_5 -> V_22 = F_16 ;
V_5 -> V_23 = F_18 ;
break;
default:
V_5 -> V_22 = F_20 ;
V_5 -> V_23 = F_21 ;
break;
}
V_20 -> V_26 = V_5 -> V_7 ;
V_5 -> V_27 = V_28 ;
}
static void
F_24 ( struct V_1 * V_5 , int V_6 , int V_17 )
{
switch ( V_5 -> V_7 ) {
case V_24 :
case V_25 :
case V_8 :
V_5 -> V_23 ( V_5 , V_6 , V_17 ) ;
V_5 -> V_22 ( V_5 , V_29 ) ;
break;
default:
V_5 -> V_23 ( V_5 , V_6 , V_17 ) ;
}
}
static inline int F_25 ( struct V_19 * V_20 )
{
return V_22 ( V_20 , V_30 ) | V_22 ( V_20 , V_31 ) << 8 ;
}
static inline void F_26 ( struct V_19 * V_20 , int V_17 )
{
V_23 ( V_20 , V_30 , V_17 & 0xff ) ;
V_23 ( V_20 , V_31 , V_17 >> 8 & 0xff ) ;
}
static int F_27 ( struct V_19 * V_20 )
{
if ( V_20 -> V_2 . V_7 == V_8 )
return F_17 ( V_20 -> V_2 . V_18 + 0x28 ) ;
else
return F_25 ( V_20 ) ;
}
static void F_28 ( struct V_19 * V_20 , int V_17 )
{
if ( V_20 -> V_2 . V_7 == V_8 )
F_19 ( V_17 , V_20 -> V_2 . V_18 + 0x28 ) ;
else
F_26 ( V_20 , V_17 ) ;
}
static int F_27 ( struct V_19 * V_20 )
{
return ( V_20 -> V_2 . V_7 == V_11 ) ?
( ( ( F_17 ( V_20 -> V_2 . V_18 + 0x10 ) << 8 ) |
( F_17 ( V_20 -> V_2 . V_18 + 0x08 ) & 0xff ) ) & 0xffff ) :
F_25 ( V_20 ) ;
}
static void F_28 ( struct V_19 * V_20 , int V_17 )
{
if ( V_20 -> V_2 . V_7 == V_11 ) {
F_19 ( V_17 , V_20 -> V_2 . V_18 + 0x08 ) ;
F_19 ( V_17 >> 8 , V_20 -> V_2 . V_18 + 0x10 ) ;
} else {
F_26 ( V_20 , V_17 ) ;
}
}
static void F_29 ( struct V_19 * V_20 , int V_6 , int V_17 )
{
V_23 ( V_20 , V_32 , V_6 ) ;
V_23 ( V_20 , V_33 , V_17 ) ;
}
static unsigned int F_30 ( struct V_19 * V_20 , int V_6 )
{
unsigned int V_17 ;
F_29 ( V_20 , V_34 , V_20 -> V_35 | V_36 ) ;
V_23 ( V_20 , V_32 , V_6 ) ;
V_17 = V_22 ( V_20 , V_33 ) ;
F_29 ( V_20 , V_34 , V_20 -> V_35 ) ;
return V_17 ;
}
static void F_31 ( struct V_19 * V_5 )
{
if ( V_5 -> V_37 & V_38 ) {
V_23 ( V_5 , V_39 , V_40 ) ;
V_23 ( V_5 , V_39 , V_40 |
V_41 | V_42 ) ;
V_23 ( V_5 , V_39 , 0 ) ;
}
}
static void F_32 ( struct V_19 * V_5 , int V_43 )
{
if ( V_5 -> V_37 & V_44 ) {
if ( V_5 -> V_37 & V_45 ) {
V_23 ( V_5 , V_29 , V_46 ) ;
V_23 ( V_5 , V_47 , V_48 ) ;
V_23 ( V_5 , V_29 , 0 ) ;
}
V_23 ( V_5 , V_49 , V_43 ? V_50 : 0 ) ;
if ( V_5 -> V_37 & V_45 ) {
V_23 ( V_5 , V_29 , V_46 ) ;
V_23 ( V_5 , V_47 , 0 ) ;
V_23 ( V_5 , V_29 , 0 ) ;
}
}
}
static int F_33 ( struct V_19 * V_20 )
{
unsigned char V_51 ;
int V_52 ;
V_51 = V_22 ( V_20 , V_53 ) ;
V_52 = V_51 & V_54 ;
if ( ! V_52 ) {
V_23 ( V_20 , V_53 , V_51 | V_54 ) ;
V_51 = V_22 ( V_20 , V_53 ) ;
V_52 = V_51 & V_54 ;
}
if ( V_52 )
V_20 -> V_2 . V_55 = V_56 * 16 ;
return V_52 ;
}
static void F_34 ( struct V_19 * V_20 )
{
if ( V_20 -> V_2 . type == V_57 ) {
if ( V_20 -> V_2 . V_55 != V_56 * 16 ) {
F_35 ( & V_20 -> V_2 . V_58 ) ;
F_33 ( V_20 ) ;
F_36 ( & V_20 -> V_2 . V_58 ) ;
}
if ( V_20 -> V_2 . V_55 == V_56 * 16 )
V_23 ( V_20 , V_59 , 0 ) ;
}
}
static void F_37 ( struct V_19 * V_20 )
{
unsigned char V_51 ;
int V_52 ;
if ( V_20 -> V_2 . type == V_57 &&
V_20 -> V_2 . V_55 == V_56 * 16 ) {
F_35 ( & V_20 -> V_2 . V_58 ) ;
V_51 = V_22 ( V_20 , V_53 ) ;
V_52 = ! ( V_51 & V_54 ) ;
if ( ! V_52 ) {
V_23 ( V_20 , V_53 , V_51 & ~ V_54 ) ;
V_51 = V_22 ( V_20 , V_53 ) ;
V_52 = ! ( V_51 & V_54 ) ;
}
if ( V_52 )
V_20 -> V_2 . V_55 = V_60 * 16 ;
F_36 ( & V_20 -> V_2 . V_58 ) ;
}
}
static int F_38 ( struct V_19 * V_20 )
{
unsigned char V_61 , V_62 , V_63 ;
unsigned short V_64 ;
int V_65 ;
V_63 = V_22 ( V_20 , V_29 ) ;
V_23 ( V_20 , V_29 , 0 ) ;
V_61 = V_22 ( V_20 , V_39 ) ;
V_62 = V_22 ( V_20 , V_66 ) ;
V_23 ( V_20 , V_39 , V_40 |
V_41 | V_42 ) ;
V_23 ( V_20 , V_66 , V_67 ) ;
V_23 ( V_20 , V_29 , V_68 ) ;
V_64 = F_27 ( V_20 ) ;
F_28 ( V_20 , 0x0001 ) ;
V_23 ( V_20 , V_29 , 0x03 ) ;
for ( V_65 = 0 ; V_65 < 256 ; V_65 ++ )
V_23 ( V_20 , V_69 , V_65 ) ;
F_39 ( 20 ) ;
for ( V_65 = 0 ; ( V_22 ( V_20 , V_70 ) & V_71 ) &&
( V_65 < 256 ) ; V_65 ++ )
V_22 ( V_20 , V_72 ) ;
V_23 ( V_20 , V_39 , V_61 ) ;
V_23 ( V_20 , V_66 , V_62 ) ;
V_23 ( V_20 , V_29 , V_68 ) ;
F_28 ( V_20 , V_64 ) ;
V_23 ( V_20 , V_29 , V_63 ) ;
return V_65 ;
}
static unsigned int F_40 ( struct V_19 * V_5 )
{
unsigned char V_73 , V_74 , V_63 ;
unsigned int V_75 ;
V_63 = V_22 ( V_5 , V_29 ) ;
V_23 ( V_5 , V_29 , V_68 ) ;
V_73 = V_22 ( V_5 , V_30 ) ;
V_74 = V_22 ( V_5 , V_31 ) ;
V_23 ( V_5 , V_30 , 0 ) ;
V_23 ( V_5 , V_31 , 0 ) ;
V_75 = V_22 ( V_5 , V_30 ) | V_22 ( V_5 , V_31 ) << 8 ;
V_23 ( V_5 , V_30 , V_73 ) ;
V_23 ( V_5 , V_31 , V_74 ) ;
V_23 ( V_5 , V_29 , V_63 ) ;
return V_75 ;
}
static void F_41 ( struct V_19 * V_20 )
{
unsigned int V_76 , V_77 , V_78 , V_79 ;
V_20 -> V_37 |= V_45 | V_44 ;
V_20 -> V_35 = 0 ;
V_23 ( V_20 , V_29 , V_46 ) ;
V_23 ( V_20 , V_47 , V_48 ) ;
V_23 ( V_20 , V_29 , 0x00 ) ;
V_76 = F_30 ( V_20 , V_80 ) ;
V_77 = F_30 ( V_20 , V_81 ) ;
V_78 = F_30 ( V_20 , V_82 ) ;
V_79 = F_30 ( V_20 , V_83 ) ;
F_42 ( L_1 , V_76 , V_77 , V_78 , V_79 ) ;
if ( V_76 == 0x16 && V_77 == 0xC9 &&
( V_78 == 0x50 || V_78 == 0x52 || V_78 == 0x54 ) ) {
V_20 -> V_2 . type = V_84 ;
if ( V_78 == 0x52 && V_79 == 0x01 )
V_20 -> V_85 |= V_86 ;
return;
}
V_76 = F_40 ( V_20 ) ;
F_42 ( L_2 , V_76 ) ;
V_77 = V_76 >> 8 ;
if ( V_77 == 0x10 || V_77 == 0x12 || V_77 == 0x14 ) {
V_20 -> V_2 . type = V_87 ;
return;
}
if ( F_38 ( V_20 ) == 64 )
V_20 -> V_2 . type = V_88 ;
else
V_20 -> V_2 . type = V_89 ;
}
static void F_43 ( struct V_19 * V_20 )
{
unsigned char V_90 , V_91 , V_92 ;
V_20 -> V_2 . type = V_93 ;
V_90 = V_22 ( V_20 , V_32 ) ;
V_23 ( V_20 , V_32 , 0xa5 ) ;
V_91 = V_22 ( V_20 , V_32 ) ;
V_23 ( V_20 , V_32 , 0x5a ) ;
V_92 = V_22 ( V_20 , V_32 ) ;
V_23 ( V_20 , V_32 , V_90 ) ;
if ( V_91 == 0xa5 && V_92 == 0x5a )
V_20 -> V_2 . type = V_94 ;
}
static int F_44 ( struct V_19 * V_20 )
{
if ( F_40 ( V_20 ) == 0x0201 && F_38 ( V_20 ) == 16 )
return 1 ;
return 0 ;
}
static inline int F_45 ( struct V_19 * V_20 )
{
unsigned char V_95 ;
V_95 = V_22 ( V_20 , 0x04 ) ;
#define F_46 ( T_1 ) ((x) & 0x30)
if ( F_46 ( V_95 ) == 0x10 ) {
return 0 ;
} else {
V_95 &= ~ 0xB0 ;
V_95 |= 0x10 ;
V_23 ( V_20 , 0x04 , V_95 ) ;
}
return 1 ;
}
static void F_47 ( struct V_19 * V_20 )
{
unsigned char V_91 , V_92 ;
unsigned int V_96 ;
V_20 -> V_2 . type = V_97 ;
V_20 -> V_37 |= V_38 ;
V_23 ( V_20 , V_29 , V_68 ) ;
if ( V_22 ( V_20 , V_47 ) == 0 ) {
V_23 ( V_20 , V_47 , 0xA8 ) ;
if ( V_22 ( V_20 , V_47 ) != 0 ) {
F_42 ( L_3 ) ;
V_20 -> V_2 . type = V_98 ;
V_20 -> V_37 |= V_45 | V_44 ;
} else {
F_42 ( L_4 ) ;
}
V_23 ( V_20 , V_47 , 0 ) ;
return;
}
V_23 ( V_20 , V_29 , V_46 ) ;
if ( V_22 ( V_20 , V_47 ) == 0 && ! F_44 ( V_20 ) ) {
F_42 ( L_5 ) ;
F_41 ( V_20 ) ;
return;
}
V_23 ( V_20 , V_29 , 0 ) ;
V_91 = V_22 ( V_20 , V_66 ) ;
V_23 ( V_20 , V_29 , 0xE0 ) ;
V_92 = V_22 ( V_20 , 0x02 ) ;
if ( ! ( ( V_92 ^ V_91 ) & V_67 ) ) {
V_23 ( V_20 , V_29 , 0 ) ;
V_23 ( V_20 , V_66 , V_91 ^ V_67 ) ;
V_23 ( V_20 , V_29 , 0xE0 ) ;
V_92 = V_22 ( V_20 , 0x02 ) ;
V_23 ( V_20 , V_29 , 0 ) ;
V_23 ( V_20 , V_66 , V_91 ) ;
if ( ( V_92 ^ V_91 ) & V_67 ) {
unsigned short V_99 ;
V_23 ( V_20 , V_29 , 0xE0 ) ;
V_99 = F_27 ( V_20 ) ;
V_99 <<= 3 ;
if ( F_45 ( V_20 ) )
F_28 ( V_20 , V_99 ) ;
V_23 ( V_20 , V_29 , 0 ) ;
V_20 -> V_2 . V_55 = 921600 * 16 ;
V_20 -> V_2 . type = V_100 ;
V_20 -> V_37 |= V_101 ;
return;
}
}
V_23 ( V_20 , V_29 , 0 ) ;
V_23 ( V_20 , V_39 , V_40 | V_102 ) ;
V_91 = V_22 ( V_20 , V_103 ) >> 5 ;
V_23 ( V_20 , V_39 , V_40 ) ;
V_23 ( V_20 , V_29 , V_68 ) ;
V_23 ( V_20 , V_39 , V_40 | V_102 ) ;
V_92 = V_22 ( V_20 , V_103 ) >> 5 ;
V_23 ( V_20 , V_39 , V_40 ) ;
V_23 ( V_20 , V_29 , 0 ) ;
F_42 ( L_6 , V_91 , V_92 ) ;
if ( V_91 == 6 && V_92 == 7 ) {
V_20 -> V_2 . type = V_104 ;
V_20 -> V_37 |= V_105 | V_44 ;
return;
}
V_96 = V_22 ( V_20 , V_49 ) ;
V_23 ( V_20 , V_49 , V_96 & ~ V_106 ) ;
if ( ! ( V_22 ( V_20 , V_49 ) & V_106 ) ) {
V_23 ( V_20 , V_49 , V_96 | V_106 ) ;
if ( V_22 ( V_20 , V_49 ) & V_106 ) {
F_42 ( L_7 ) ;
V_20 -> V_2 . type = V_107 ;
V_20 -> V_37 |= V_108 | V_109 ;
return;
}
} else {
F_42 ( L_8 ) ;
}
V_23 ( V_20 , V_49 , V_96 ) ;
if ( V_20 -> V_2 . V_110 & V_111 ) {
V_20 -> V_2 . type = V_112 ;
V_20 -> V_37 |= V_105 | V_45 ;
}
if ( V_20 -> V_2 . type == V_97 && F_38 ( V_20 ) == 64 ) {
V_20 -> V_2 . type = V_113 ;
V_20 -> V_37 |= V_105 ;
}
}
static void F_48 ( struct V_19 * V_20 , unsigned int V_114 )
{
unsigned char V_91 , V_90 , V_115 , V_116 ;
unsigned char V_117 , V_118 ;
struct V_1 * V_2 = & V_20 -> V_2 ;
unsigned long V_110 ;
if ( ! V_2 -> V_16 && ! V_2 -> V_119 && ! V_2 -> V_18 )
return;
F_42 ( L_9 ,
F_1 ( V_2 ) , V_2 -> V_16 , V_2 -> V_18 ) ;
F_49 ( & V_2 -> V_58 , V_110 ) ;
V_20 -> V_37 = 0 ;
V_20 -> V_85 = 0 ;
if ( ! ( V_2 -> V_110 & V_120 ) ) {
V_90 = V_22 ( V_20 , V_49 ) ;
V_23 ( V_20 , V_49 , 0 ) ;
#ifdef F_50
F_5 ( 0xff , 0x080 ) ;
#endif
V_115 = V_22 ( V_20 , V_49 ) & 0x0f ;
V_23 ( V_20 , V_49 , 0x0F ) ;
#ifdef F_50
F_5 ( 0 , 0x080 ) ;
#endif
V_116 = V_22 ( V_20 , V_49 ) & 0x0f ;
V_23 ( V_20 , V_49 , V_90 ) ;
if ( V_115 != 0 || V_116 != 0x0F ) {
F_42 ( L_10 ,
V_115 , V_116 ) ;
goto V_121;
}
}
V_118 = V_22 ( V_20 , V_66 ) ;
V_117 = V_22 ( V_20 , V_29 ) ;
if ( ! ( V_2 -> V_110 & V_122 ) ) {
V_23 ( V_20 , V_66 , V_67 | 0x0A ) ;
V_91 = V_22 ( V_20 , V_123 ) & 0xF0 ;
V_23 ( V_20 , V_66 , V_118 ) ;
if ( V_91 != 0x90 ) {
F_42 ( L_11 ,
V_91 ) ;
goto V_121;
}
}
V_23 ( V_20 , V_29 , V_46 ) ;
V_23 ( V_20 , V_47 , 0 ) ;
V_23 ( V_20 , V_29 , 0 ) ;
V_23 ( V_20 , V_39 , V_40 ) ;
V_90 = V_22 ( V_20 , V_103 ) >> 6 ;
F_42 ( L_12 , V_90 ) ;
switch ( V_90 ) {
case 0 :
F_43 ( V_20 ) ;
break;
case 1 :
V_2 -> type = V_124 ;
break;
case 2 :
V_2 -> type = V_125 ;
break;
case 3 :
F_47 ( V_20 ) ;
break;
}
#ifdef F_51
if ( V_2 -> type == V_97 && V_114 & V_126 ) {
int V_127 ;
for ( V_127 = 0 ; V_127 < V_128 ; ++ V_127 ) {
if ( V_129 [ V_127 ] == V_2 -> V_16 && F_33 ( V_20 ) ) {
V_2 -> type = V_57 ;
break;
}
}
}
#endif
V_23 ( V_20 , V_29 , V_117 ) ;
if ( V_20 -> V_37 != V_130 [ V_2 -> type ] . V_110 ) {
F_52 ( V_131
L_13 ,
F_1 ( V_2 ) , V_20 -> V_37 ,
V_130 [ V_2 -> type ] . V_110 ) ;
}
V_2 -> V_132 = V_130 [ V_20 -> V_2 . type ] . V_133 ;
V_20 -> V_37 = V_130 [ V_2 -> type ] . V_110 ;
V_20 -> V_134 = V_130 [ V_2 -> type ] . V_134 ;
if ( V_2 -> type == V_124 )
goto V_121;
#ifdef F_51
if ( V_2 -> type == V_57 )
V_23 ( V_20 , V_59 , 0 ) ;
#endif
V_23 ( V_20 , V_66 , V_118 ) ;
F_31 ( V_20 ) ;
V_22 ( V_20 , V_72 ) ;
if ( V_20 -> V_37 & V_108 )
V_23 ( V_20 , V_49 , V_106 ) ;
else
V_23 ( V_20 , V_49 , 0 ) ;
V_121:
F_53 ( & V_2 -> V_58 , V_110 ) ;
F_42 ( L_14 , V_130 [ V_2 -> type ] . V_135 ) ;
}
static void F_54 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = & V_20 -> V_2 ;
unsigned char V_118 , V_136 ;
unsigned char V_137 = 0 ;
unsigned int V_138 = 0 ;
unsigned long V_139 ;
int V_140 ;
if ( V_2 -> V_110 & V_141 ) {
V_138 = ( V_2 -> V_16 & 0xfe0 ) | 0x1f ;
V_137 = F_55 ( V_138 ) ;
F_56 ( 0x80 , V_138 ) ;
F_55 ( V_138 ) ;
}
F_57 ( F_58 () ) ;
V_118 = V_22 ( V_20 , V_66 ) ;
V_136 = V_22 ( V_20 , V_49 ) ;
V_23 ( V_20 , V_66 , V_142 | V_143 ) ;
V_139 = F_58 () ;
V_23 ( V_20 , V_66 , 0 ) ;
F_59 ( 10 ) ;
if ( V_2 -> V_110 & V_141 ) {
V_23 ( V_20 , V_66 ,
V_144 | V_145 ) ;
} else {
V_23 ( V_20 , V_66 ,
V_144 | V_145 | V_143 ) ;
}
V_23 ( V_20 , V_49 , 0x0f ) ;
V_22 ( V_20 , V_70 ) ;
V_22 ( V_20 , V_72 ) ;
V_22 ( V_20 , V_103 ) ;
V_22 ( V_20 , V_123 ) ;
V_23 ( V_20 , V_69 , 0xFF ) ;
F_59 ( 20 ) ;
V_140 = F_57 ( V_139 ) ;
V_23 ( V_20 , V_66 , V_118 ) ;
V_23 ( V_20 , V_49 , V_136 ) ;
if ( V_2 -> V_110 & V_141 )
F_56 ( V_137 , V_138 ) ;
V_2 -> V_140 = ( V_140 > 0 ) ? V_140 : 0 ;
}
static inline void F_60 ( struct V_19 * V_5 )
{
if ( V_5 -> V_146 & V_147 ) {
V_5 -> V_146 &= ~ V_147 ;
V_23 ( V_5 , V_49 , V_5 -> V_146 ) ;
}
}
static void F_61 ( struct V_1 * V_2 )
{
struct V_19 * V_20 =
F_23 ( V_2 , struct V_19 , V_2 ) ;
F_60 ( V_20 ) ;
if ( V_2 -> type == V_84 ) {
V_20 -> V_35 |= V_148 ;
F_29 ( V_20 , V_34 , V_20 -> V_35 ) ;
}
}
static void F_62 ( struct V_1 * V_2 )
{
struct V_19 * V_20 =
F_23 ( V_2 , struct V_19 , V_2 ) ;
if ( ! ( V_20 -> V_146 & V_147 ) ) {
V_20 -> V_146 |= V_147 ;
F_63 ( V_2 , V_49 , V_20 -> V_146 ) ;
if ( V_20 -> V_85 & V_149 ) {
unsigned char V_150 ;
V_150 = V_22 ( V_20 , V_70 ) ;
V_20 -> V_151 |= V_150 & V_152 ;
if ( ( V_2 -> type == V_153 ) ?
( V_150 & V_154 ) :
( V_150 & V_155 ) )
F_64 ( V_20 ) ;
}
}
if ( V_2 -> type == V_84 && V_20 -> V_35 & V_148 ) {
V_20 -> V_35 &= ~ V_148 ;
F_29 ( V_20 , V_34 , V_20 -> V_35 ) ;
}
}
static void F_65 ( struct V_1 * V_2 )
{
struct V_19 * V_20 =
F_23 ( V_2 , struct V_19 , V_2 ) ;
V_20 -> V_146 &= ~ V_156 ;
V_20 -> V_2 . V_157 &= ~ V_71 ;
F_63 ( V_2 , V_49 , V_20 -> V_146 ) ;
}
static void F_66 ( struct V_1 * V_2 )
{
struct V_19 * V_20 =
F_23 ( V_2 , struct V_19 , V_2 ) ;
if ( V_20 -> V_85 & V_158 )
return;
V_20 -> V_146 |= V_159 ;
F_63 ( V_2 , V_49 , V_20 -> V_146 ) ;
}
static void F_67 ( struct V_19 * V_20 )
{
unsigned int V_95 , V_160 = 10000 ;
do {
V_95 = V_22 ( V_20 , V_70 ) ;
if ( V_95 & ( V_161 | V_162 ) )
V_95 = V_22 ( V_20 , V_72 ) ;
else
break;
if ( -- V_160 == 0 )
break;
F_59 ( 1 ) ;
} while ( 1 );
}
unsigned char
F_68 ( struct V_19 * V_20 , unsigned char V_150 )
{
struct V_1 * V_2 = & V_20 -> V_2 ;
struct V_163 * V_164 = V_2 -> V_165 -> V_2 . V_164 ;
unsigned char V_166 ;
int V_167 = 256 ;
char V_168 ;
do {
if ( F_69 ( V_150 & V_71 ) )
V_166 = V_22 ( V_20 , V_72 ) ;
else
V_166 = 0 ;
V_168 = V_169 ;
V_2 -> V_170 . V_171 ++ ;
V_150 |= V_20 -> V_151 ;
V_20 -> V_151 = 0 ;
if ( F_70 ( V_150 & V_162 ) ) {
if ( V_150 & V_172 ) {
V_150 &= ~ ( V_173 | V_174 ) ;
V_2 -> V_170 . V_175 ++ ;
if ( V_2 -> type == V_176 )
F_67 ( V_20 ) ;
if ( F_71 ( V_2 ) )
goto V_177;
} else if ( V_150 & V_174 )
V_2 -> V_170 . V_178 ++ ;
else if ( V_150 & V_173 )
V_2 -> V_170 . V_179 ++ ;
if ( V_150 & V_180 )
V_2 -> V_170 . V_181 ++ ;
V_150 &= V_2 -> V_157 ;
if ( V_150 & V_172 ) {
F_72 ( L_15 ) ;
V_168 = V_182 ;
} else if ( V_150 & V_174 )
V_168 = V_183 ;
else if ( V_150 & V_173 )
V_168 = V_184 ;
}
if ( F_73 ( V_2 , V_166 ) )
goto V_177;
F_74 ( V_2 , V_150 , V_180 , V_166 , V_168 ) ;
V_177:
V_150 = V_22 ( V_20 , V_70 ) ;
} while ( ( V_150 & ( V_71 | V_172 ) ) && ( V_167 -- > 0 ) );
F_75 ( & V_2 -> V_58 ) ;
F_76 ( V_164 ) ;
F_77 ( & V_2 -> V_58 ) ;
return V_150 ;
}
void F_64 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = & V_20 -> V_2 ;
struct V_185 * V_186 = & V_2 -> V_165 -> V_186 ;
int V_65 ;
if ( V_2 -> V_187 ) {
V_23 ( V_20 , V_69 , V_2 -> V_187 ) ;
V_2 -> V_170 . V_188 ++ ;
V_2 -> V_187 = 0 ;
return;
}
if ( F_78 ( V_2 ) ) {
F_61 ( V_2 ) ;
return;
}
if ( F_79 ( V_186 ) ) {
F_60 ( V_20 ) ;
return;
}
V_65 = V_20 -> V_134 ;
do {
V_23 ( V_20 , V_69 , V_186 -> V_189 [ V_186 -> V_190 ] ) ;
V_186 -> V_190 = ( V_186 -> V_190 + 1 ) & ( V_191 - 1 ) ;
V_2 -> V_170 . V_188 ++ ;
if ( F_79 ( V_186 ) )
break;
} while ( -- V_65 > 0 );
if ( F_80 ( V_186 ) < V_192 )
F_81 ( V_2 ) ;
F_72 ( L_16 ) ;
if ( F_79 ( V_186 ) )
F_60 ( V_20 ) ;
}
unsigned int F_82 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = & V_20 -> V_2 ;
unsigned int V_95 = V_22 ( V_20 , V_123 ) ;
V_95 |= V_20 -> V_193 ;
V_20 -> V_193 = 0 ;
if ( V_95 & V_194 && V_20 -> V_146 & V_159 &&
V_2 -> V_165 != NULL ) {
if ( V_95 & V_195 )
V_2 -> V_170 . V_196 ++ ;
if ( V_95 & V_197 )
V_2 -> V_170 . V_198 ++ ;
if ( V_95 & V_199 )
F_83 ( V_2 , V_95 & V_200 ) ;
if ( V_95 & V_201 )
F_84 ( V_2 , V_95 & V_202 ) ;
F_85 ( & V_2 -> V_165 -> V_2 . V_203 ) ;
}
return V_95 ;
}
int F_86 ( struct V_1 * V_2 , unsigned int V_204 )
{
unsigned char V_95 ;
unsigned long V_110 ;
struct V_19 * V_20 =
F_23 ( V_2 , struct V_19 , V_2 ) ;
if ( V_204 & V_205 )
return 0 ;
F_49 ( & V_2 -> V_58 , V_110 ) ;
V_95 = F_87 ( V_2 , V_70 ) ;
F_72 ( L_17 , V_95 ) ;
if ( V_95 & ( V_71 | V_172 ) )
V_95 = F_68 ( V_20 , V_95 ) ;
F_82 ( V_20 ) ;
if ( V_95 & V_154 )
F_64 ( V_20 ) ;
F_53 ( & V_2 -> V_58 , V_110 ) ;
return 1 ;
}
static int V_28 ( struct V_1 * V_2 )
{
unsigned int V_204 = F_87 ( V_2 , V_103 ) ;
return F_86 ( V_2 , V_204 ) ;
}
static T_2 F_88 ( int V_140 , void * V_206 )
{
struct V_207 * V_127 = V_206 ;
struct V_208 * V_209 , * V_210 = NULL ;
int V_211 = 0 , V_212 = 0 ;
F_72 ( L_18 , V_140 ) ;
F_77 ( & V_127 -> V_58 ) ;
V_209 = V_127 -> V_213 ;
do {
struct V_19 * V_20 ;
struct V_1 * V_2 ;
V_20 = F_89 ( V_209 , struct V_19 , V_214 ) ;
V_2 = & V_20 -> V_2 ;
if ( V_2 -> V_27 ( V_2 ) ) {
V_212 = 1 ;
V_210 = NULL ;
} else if ( V_210 == NULL )
V_210 = V_209 ;
V_209 = V_209 -> V_215 ;
if ( V_209 == V_127 -> V_213 && V_211 ++ > V_216 ) {
F_90 ( V_217
L_19 , V_140 ) ;
break;
}
} while ( V_209 != V_210 );
F_75 ( & V_127 -> V_58 ) ;
F_72 ( L_20 ) ;
return F_91 ( V_212 ) ;
}
static void F_92 ( struct V_207 * V_127 , struct V_19 * V_20 )
{
F_35 ( & V_127 -> V_58 ) ;
if ( ! F_93 ( V_127 -> V_213 ) ) {
if ( V_127 -> V_213 == & V_20 -> V_214 )
V_127 -> V_213 = V_127 -> V_213 -> V_215 ;
F_94 ( & V_20 -> V_214 ) ;
} else {
F_95 ( V_127 -> V_213 != & V_20 -> V_214 ) ;
V_127 -> V_213 = NULL ;
}
F_36 ( & V_127 -> V_58 ) ;
if ( V_127 -> V_213 == NULL ) {
F_96 ( & V_127 -> V_218 ) ;
F_97 ( V_127 ) ;
}
}
static int F_98 ( struct V_19 * V_20 )
{
struct V_219 * V_220 ;
struct V_221 * V_222 ;
struct V_207 * V_127 ;
int V_223 , V_224 = V_20 -> V_2 . V_110 & V_225 ? V_226 : 0 ;
F_99 ( & V_227 ) ;
V_220 = & V_228 [ V_20 -> V_2 . V_140 % V_229 ] ;
F_100 (n, h) {
V_127 = F_101 ( V_222 , struct V_207 , V_218 ) ;
if ( V_127 -> V_140 == V_20 -> V_2 . V_140 )
break;
}
if ( V_222 == NULL ) {
V_127 = F_102 ( sizeof( struct V_207 ) , V_230 ) ;
if ( V_127 == NULL ) {
F_103 ( & V_227 ) ;
return - V_231 ;
}
F_104 ( & V_127 -> V_58 ) ;
V_127 -> V_140 = V_20 -> V_2 . V_140 ;
F_105 ( & V_127 -> V_218 , V_220 ) ;
}
F_103 ( & V_227 ) ;
F_35 ( & V_127 -> V_58 ) ;
if ( V_127 -> V_213 ) {
F_106 ( & V_20 -> V_214 , V_127 -> V_213 ) ;
F_36 ( & V_127 -> V_58 ) ;
V_223 = 0 ;
} else {
F_107 ( & V_20 -> V_214 ) ;
V_127 -> V_213 = & V_20 -> V_214 ;
F_36 ( & V_127 -> V_58 ) ;
V_224 |= V_20 -> V_2 . V_232 ;
V_223 = F_108 ( V_20 -> V_2 . V_140 , F_88 ,
V_224 , L_21 , V_127 ) ;
if ( V_223 < 0 )
F_92 ( V_127 , V_20 ) ;
}
return V_223 ;
}
static void F_109 ( struct V_19 * V_20 )
{
struct V_207 * V_127 ;
struct V_221 * V_222 ;
struct V_219 * V_220 ;
F_99 ( & V_227 ) ;
V_220 = & V_228 [ V_20 -> V_2 . V_140 % V_229 ] ;
F_100 (n, h) {
V_127 = F_101 ( V_222 , struct V_207 , V_218 ) ;
if ( V_127 -> V_140 == V_20 -> V_2 . V_140 )
break;
}
F_95 ( V_222 == NULL ) ;
F_95 ( V_127 -> V_213 == NULL ) ;
if ( F_93 ( V_127 -> V_213 ) )
F_110 ( V_20 -> V_2 . V_140 , V_127 ) ;
F_92 ( V_127 , V_20 ) ;
F_103 ( & V_227 ) ;
}
static void F_111 ( unsigned long V_233 )
{
struct V_19 * V_20 = (struct V_19 * ) V_233 ;
V_20 -> V_2 . V_27 ( & V_20 -> V_2 ) ;
F_112 ( & V_20 -> V_234 , V_235 + F_113 ( & V_20 -> V_2 ) ) ;
}
static void F_114 ( unsigned long V_233 )
{
struct V_19 * V_20 = (struct V_19 * ) V_233 ;
unsigned int V_204 , V_146 = 0 , V_150 ;
unsigned long V_110 ;
F_49 ( & V_20 -> V_2 . V_58 , V_110 ) ;
if ( V_20 -> V_2 . V_140 ) {
V_146 = V_22 ( V_20 , V_49 ) ;
V_23 ( V_20 , V_49 , 0 ) ;
}
V_204 = V_22 ( V_20 , V_103 ) ;
V_150 = V_22 ( V_20 , V_70 ) ;
V_20 -> V_151 |= V_150 & V_152 ;
if ( ( V_204 & V_205 ) && ( V_20 -> V_146 & V_147 ) &&
( ! F_79 ( & V_20 -> V_2 . V_165 -> V_186 ) || V_20 -> V_2 . V_187 ) &&
( V_150 & V_154 ) ) {
V_204 &= ~ ( V_236 | V_205 ) ;
V_204 |= V_237 ;
}
if ( ! ( V_204 & V_205 ) )
F_64 ( V_20 ) ;
if ( V_20 -> V_2 . V_140 )
V_23 ( V_20 , V_49 , V_146 ) ;
F_53 ( & V_20 -> V_2 . V_58 , V_110 ) ;
F_112 ( & V_20 -> V_234 ,
V_235 + F_113 ( & V_20 -> V_2 ) + V_238 / 5 ) ;
}
static unsigned int F_115 ( struct V_1 * V_2 )
{
struct V_19 * V_20 =
F_23 ( V_2 , struct V_19 , V_2 ) ;
unsigned long V_110 ;
unsigned int V_150 ;
F_49 ( & V_2 -> V_58 , V_110 ) ;
V_150 = F_87 ( V_2 , V_70 ) ;
V_20 -> V_151 |= V_150 & V_152 ;
F_53 ( & V_2 -> V_58 , V_110 ) ;
return ( V_150 & V_239 ) == V_239 ? V_240 : 0 ;
}
static unsigned int F_116 ( struct V_1 * V_2 )
{
struct V_19 * V_20 =
F_23 ( V_2 , struct V_19 , V_2 ) ;
unsigned int V_95 ;
unsigned int V_223 ;
V_95 = F_82 ( V_20 ) ;
V_223 = 0 ;
if ( V_95 & V_200 )
V_223 |= V_241 ;
if ( V_95 & V_242 )
V_223 |= V_243 ;
if ( V_95 & V_244 )
V_223 |= V_245 ;
if ( V_95 & V_202 )
V_223 |= V_246 ;
return V_223 ;
}
static void F_117 ( struct V_1 * V_2 , unsigned int V_247 )
{
struct V_19 * V_20 =
F_23 ( V_2 , struct V_19 , V_2 ) ;
unsigned char V_248 = 0 ;
if ( V_247 & V_249 )
V_248 |= V_145 ;
if ( V_247 & V_250 )
V_248 |= V_144 ;
if ( V_247 & V_251 )
V_248 |= V_142 ;
if ( V_247 & V_252 )
V_248 |= V_143 ;
if ( V_247 & V_253 )
V_248 |= V_67 ;
V_248 = ( V_248 & V_20 -> V_254 ) | V_20 -> V_255 | V_20 -> V_248 ;
F_63 ( V_2 , V_66 , V_248 ) ;
}
static void F_118 ( struct V_1 * V_2 , int V_256 )
{
struct V_19 * V_20 =
F_23 ( V_2 , struct V_19 , V_2 ) ;
unsigned long V_110 ;
F_49 ( & V_2 -> V_58 , V_110 ) ;
if ( V_256 == - 1 )
V_20 -> V_257 |= V_258 ;
else
V_20 -> V_257 &= ~ V_258 ;
F_63 ( V_2 , V_29 , V_20 -> V_257 ) ;
F_53 ( & V_2 -> V_58 , V_110 ) ;
}
static void F_119 ( struct V_19 * V_20 , int V_259 )
{
unsigned int V_95 , V_160 = 10000 ;
for (; ; ) {
V_95 = V_22 ( V_20 , V_70 ) ;
V_20 -> V_151 |= V_95 & V_152 ;
if ( ( V_95 & V_259 ) == V_259 )
break;
if ( -- V_160 == 0 )
break;
F_59 ( 1 ) ;
}
if ( V_20 -> V_2 . V_110 & V_260 ) {
unsigned int V_160 ;
for ( V_160 = 1000000 ; V_160 ; V_160 -- ) {
unsigned int V_261 = V_22 ( V_20 , V_123 ) ;
V_20 -> V_193 |= V_261 & V_262 ;
if ( V_261 & V_202 )
break;
F_59 ( 1 ) ;
F_120 () ;
}
}
}
static int F_121 ( struct V_1 * V_2 )
{
unsigned char V_150 = F_87 ( V_2 , V_70 ) ;
if ( ! ( V_150 & V_71 ) )
return V_263 ;
return F_87 ( V_2 , V_72 ) ;
}
static void F_122 ( struct V_1 * V_2 ,
unsigned char V_264 )
{
unsigned int V_146 ;
struct V_19 * V_20 =
F_23 ( V_2 , struct V_19 , V_2 ) ;
V_146 = F_87 ( V_2 , V_49 ) ;
if ( V_20 -> V_37 & V_108 )
F_63 ( V_2 , V_49 , V_106 ) ;
else
F_63 ( V_2 , V_49 , 0 ) ;
F_119 ( V_20 , V_239 ) ;
F_63 ( V_2 , V_69 , V_264 ) ;
if ( V_264 == 10 ) {
F_119 ( V_20 , V_239 ) ;
F_63 ( V_2 , V_69 , 13 ) ;
}
F_119 ( V_20 , V_239 ) ;
F_63 ( V_2 , V_49 , V_146 ) ;
}
static int F_123 ( struct V_1 * V_2 )
{
struct V_19 * V_20 =
F_23 ( V_2 , struct V_19 , V_2 ) ;
unsigned long V_110 ;
unsigned char V_150 , V_204 ;
int V_265 ;
V_2 -> V_132 = V_130 [ V_20 -> V_2 . type ] . V_133 ;
V_20 -> V_134 = V_130 [ V_20 -> V_2 . type ] . V_134 ;
V_20 -> V_37 = V_130 [ V_20 -> V_2 . type ] . V_110 ;
V_20 -> V_248 = 0 ;
if ( V_2 -> V_7 != V_20 -> V_26 )
F_22 ( V_2 ) ;
if ( V_2 -> type == V_84 ) {
V_20 -> V_35 = 0 ;
F_63 ( V_2 , V_29 , V_46 ) ;
F_63 ( V_2 , V_47 , V_48 ) ;
F_63 ( V_2 , V_49 , 0 ) ;
F_63 ( V_2 , V_29 , 0 ) ;
F_29 ( V_20 , V_266 , 0 ) ;
F_63 ( V_2 , V_29 , V_46 ) ;
F_63 ( V_2 , V_47 , V_48 ) ;
F_63 ( V_2 , V_29 , 0 ) ;
}
#ifdef F_51
F_34 ( V_20 ) ;
#endif
F_31 ( V_20 ) ;
F_87 ( V_2 , V_70 ) ;
F_87 ( V_2 , V_72 ) ;
F_87 ( V_2 , V_103 ) ;
F_87 ( V_2 , V_123 ) ;
if ( ! ( V_2 -> V_110 & V_120 ) &&
( F_87 ( V_2 , V_70 ) == 0xff ) ) {
F_90 ( V_267 L_22 ,
F_1 ( V_2 ) ) ;
return - V_268 ;
}
if ( V_2 -> type == V_87 ) {
unsigned char V_269 ;
V_23 ( V_20 , V_29 , V_46 ) ;
V_269 = V_22 ( V_20 , V_270 ) & ~ ( V_271 | V_272 ) ;
F_63 ( V_2 , V_270 ,
V_269 | V_273 | V_271 ) ;
F_63 ( V_2 , V_274 , V_275 ) ;
F_63 ( V_2 , V_270 ,
V_269 | V_273 | V_272 ) ;
F_63 ( V_2 , V_274 , V_275 ) ;
F_63 ( V_2 , V_29 , 0 ) ;
}
if ( V_2 -> V_140 ) {
unsigned char V_276 ;
F_49 ( & V_2 -> V_58 , V_110 ) ;
if ( V_20 -> V_2 . V_232 & V_226 )
F_124 ( V_2 -> V_140 ) ;
F_119 ( V_20 , V_154 ) ;
F_24 ( V_2 , V_49 , V_147 ) ;
F_59 ( 1 ) ;
V_276 = F_87 ( V_2 , V_103 ) ;
F_63 ( V_2 , V_49 , 0 ) ;
F_24 ( V_2 , V_49 , V_147 ) ;
F_59 ( 1 ) ;
V_204 = F_87 ( V_2 , V_103 ) ;
F_63 ( V_2 , V_49 , 0 ) ;
if ( V_2 -> V_232 & V_226 )
F_125 ( V_2 -> V_140 ) ;
F_53 ( & V_2 -> V_58 , V_110 ) ;
if ( ( ! ( V_276 & V_205 ) && ( V_204 & V_205 ) ) ||
V_20 -> V_2 . V_110 & V_277 ) {
V_20 -> V_85 |= V_278 ;
F_126 ( L_23 ,
F_1 ( V_2 ) ) ;
}
}
if ( V_20 -> V_85 & V_278 ) {
V_20 -> V_234 . V_279 = F_114 ;
V_20 -> V_234 . V_233 = ( unsigned long ) V_20 ;
F_112 ( & V_20 -> V_234 , V_235 +
F_113 ( V_2 ) + V_238 / 5 ) ;
}
if ( ! V_2 -> V_140 ) {
V_20 -> V_234 . V_233 = ( unsigned long ) V_20 ;
F_112 ( & V_20 -> V_234 , V_235 + F_113 ( V_2 ) ) ;
} else {
V_265 = F_98 ( V_20 ) ;
if ( V_265 )
return V_265 ;
}
F_63 ( V_2 , V_29 , V_280 ) ;
F_49 ( & V_2 -> V_58 , V_110 ) ;
if ( V_20 -> V_2 . V_110 & V_141 ) {
if ( ! V_20 -> V_2 . V_140 )
V_20 -> V_2 . V_247 |= V_251 ;
} else
if ( V_2 -> V_140 )
V_20 -> V_2 . V_247 |= V_252 ;
F_117 ( V_2 , V_2 -> V_247 ) ;
if ( V_281 || V_20 -> V_2 . V_110 & V_282 )
goto V_283;
F_63 ( V_2 , V_49 , V_147 ) ;
V_150 = F_87 ( V_2 , V_70 ) ;
V_204 = F_87 ( V_2 , V_103 ) ;
F_63 ( V_2 , V_49 , 0 ) ;
if ( V_150 & V_155 && V_204 & V_205 ) {
if ( ! ( V_20 -> V_85 & V_149 ) ) {
V_20 -> V_85 |= V_149 ;
F_126 ( L_24 ,
F_1 ( V_2 ) ) ;
}
} else {
V_20 -> V_85 &= ~ V_149 ;
}
V_283:
F_53 ( & V_2 -> V_58 , V_110 ) ;
F_87 ( V_2 , V_70 ) ;
F_87 ( V_2 , V_72 ) ;
F_87 ( V_2 , V_103 ) ;
F_87 ( V_2 , V_123 ) ;
V_20 -> V_151 = 0 ;
V_20 -> V_193 = 0 ;
V_20 -> V_146 = V_156 | V_284 ;
F_63 ( V_2 , V_49 , V_20 -> V_146 ) ;
if ( V_2 -> V_110 & V_141 ) {
unsigned int V_285 ;
V_285 = ( V_2 -> V_16 & 0xfe0 ) | 0x01f ;
F_56 ( 0x80 , V_285 ) ;
F_55 ( V_285 ) ;
}
return 0 ;
}
static void F_127 ( struct V_1 * V_2 )
{
struct V_19 * V_20 =
F_23 ( V_2 , struct V_19 , V_2 ) ;
unsigned long V_110 ;
V_20 -> V_146 = 0 ;
F_63 ( V_2 , V_49 , 0 ) ;
F_49 ( & V_2 -> V_58 , V_110 ) ;
if ( V_2 -> V_110 & V_141 ) {
F_6 ( ( V_2 -> V_16 & 0xfe0 ) | 0x1f ) ;
V_2 -> V_247 |= V_251 ;
} else
V_2 -> V_247 &= ~ V_252 ;
F_117 ( V_2 , V_2 -> V_247 ) ;
F_53 ( & V_2 -> V_58 , V_110 ) ;
F_63 ( V_2 , V_29 ,
F_87 ( V_2 , V_29 ) & ~ V_258 ) ;
F_31 ( V_20 ) ;
#ifdef F_51
F_37 ( V_20 ) ;
#endif
F_87 ( V_2 , V_72 ) ;
F_128 ( & V_20 -> V_234 ) ;
V_20 -> V_234 . V_279 = F_111 ;
if ( V_2 -> V_140 )
F_109 ( V_20 ) ;
}
static unsigned int F_129 ( struct V_1 * V_2 , unsigned int V_286 )
{
unsigned int V_99 ;
if ( ( V_2 -> V_110 & V_287 ) &&
V_286 == ( V_2 -> V_55 / 4 ) )
V_99 = 0x8001 ;
else if ( ( V_2 -> V_110 & V_287 ) &&
V_286 == ( V_2 -> V_55 / 8 ) )
V_99 = 0x8002 ;
else
V_99 = F_130 ( V_2 , V_286 ) ;
return V_99 ;
}
void
F_131 ( struct V_1 * V_2 , struct V_288 * V_289 ,
struct V_288 * V_290 )
{
struct V_19 * V_20 =
F_23 ( V_2 , struct V_19 , V_2 ) ;
unsigned char V_291 , V_292 = 0 ;
unsigned long V_110 ;
unsigned int V_286 , V_99 ;
switch ( V_289 -> V_293 & V_294 ) {
case V_295 :
V_291 = V_296 ;
break;
case V_297 :
V_291 = V_298 ;
break;
case V_299 :
V_291 = V_300 ;
break;
default:
case V_301 :
V_291 = V_280 ;
break;
}
if ( V_289 -> V_293 & V_302 )
V_291 |= V_303 ;
if ( V_289 -> V_293 & V_304 )
V_291 |= V_305 ;
if ( ! ( V_289 -> V_293 & V_306 ) )
V_291 |= V_307 ;
#ifdef F_132
if ( V_289 -> V_293 & F_132 )
V_291 |= V_308 ;
#endif
V_286 = F_133 ( V_2 , V_289 , V_290 ,
V_2 -> V_55 / 16 / 0xffff ,
V_2 -> V_55 / 16 ) ;
V_99 = F_129 ( V_2 , V_286 ) ;
if ( V_20 -> V_85 & V_86 && ( V_99 & 0xff ) == 0 )
V_99 ++ ;
if ( V_20 -> V_37 & V_38 && V_2 -> V_132 > 1 ) {
if ( V_286 < 2400 )
V_292 = V_40 | V_309 ;
else
V_292 = V_130 [ V_2 -> type ] . V_292 ;
}
if ( V_20 -> V_37 & V_105 && V_2 -> V_132 >= 32 ) {
V_20 -> V_248 &= ~ V_310 ;
if ( V_289 -> V_293 & V_311 )
V_20 -> V_248 |= V_310 ;
}
F_49 ( & V_2 -> V_58 , V_110 ) ;
F_134 ( V_2 , V_289 -> V_293 , V_286 ) ;
V_2 -> V_157 = V_180 | V_154 | V_71 ;
if ( V_289 -> V_312 & V_313 )
V_2 -> V_157 |= V_173 | V_174 ;
if ( V_289 -> V_312 & ( V_314 | V_315 ) )
V_2 -> V_157 |= V_172 ;
V_2 -> V_316 = 0 ;
if ( V_289 -> V_312 & V_317 )
V_2 -> V_316 |= V_174 | V_173 ;
if ( V_289 -> V_312 & V_318 ) {
V_2 -> V_316 |= V_172 ;
if ( V_289 -> V_312 & V_317 )
V_2 -> V_316 |= V_180 ;
}
if ( ( V_289 -> V_293 & V_319 ) == 0 )
V_2 -> V_316 |= V_71 ;
V_20 -> V_146 &= ~ V_159 ;
if ( ! ( V_20 -> V_85 & V_158 ) &&
F_135 ( & V_20 -> V_2 , V_289 -> V_293 ) )
V_20 -> V_146 |= V_159 ;
if ( V_20 -> V_37 & V_108 )
V_20 -> V_146 |= V_106 ;
if ( V_20 -> V_37 & V_109 )
V_20 -> V_146 |= V_320 ;
F_63 ( V_2 , V_49 , V_20 -> V_146 ) ;
if ( V_20 -> V_37 & V_45 ) {
unsigned char V_321 = 0 ;
if ( V_289 -> V_293 & V_311 )
V_321 |= V_322 ;
F_63 ( V_2 , V_29 , V_46 ) ;
if ( V_2 -> V_110 & V_111 )
F_63 ( V_2 , V_323 , V_321 ) ;
else
F_63 ( V_2 , V_47 , V_321 ) ;
}
#ifdef F_136
if ( F_137 () && F_138 ( V_20 ) ) {
if ( V_286 == 115200 ) {
V_99 = 1 ;
F_63 ( V_2 , V_324 , 1 ) ;
} else
F_63 ( V_2 , V_324 , 0 ) ;
}
#endif
if ( V_20 -> V_37 & V_101 )
F_63 ( V_2 , V_29 , 0xe0 ) ;
else
F_63 ( V_2 , V_29 , V_291 | V_325 ) ;
F_28 ( V_20 , V_99 ) ;
if ( V_2 -> type == V_104 )
F_63 ( V_2 , V_39 , V_292 ) ;
F_63 ( V_2 , V_29 , V_291 ) ;
V_20 -> V_257 = V_291 ;
if ( V_2 -> type != V_104 ) {
if ( V_292 & V_40 )
F_63 ( V_2 , V_39 , V_40 ) ;
F_63 ( V_2 , V_39 , V_292 ) ;
}
F_117 ( V_2 , V_2 -> V_247 ) ;
F_53 ( & V_2 -> V_58 , V_110 ) ;
if ( F_139 ( V_289 ) )
F_140 ( V_289 , V_286 , V_286 ) ;
}
static void
F_141 ( struct V_1 * V_2 , struct V_288 * V_289 ,
struct V_288 * V_290 )
{
if ( V_2 -> V_326 )
V_2 -> V_326 ( V_2 , V_289 , V_290 ) ;
else
F_131 ( V_2 , V_289 , V_290 ) ;
}
static void
F_142 ( struct V_1 * V_2 , int V_327 )
{
if ( V_327 == V_328 ) {
V_2 -> V_110 |= V_329 ;
F_66 ( V_2 ) ;
} else
V_2 -> V_110 &= ~ V_329 ;
}
void F_143 ( struct V_1 * V_2 , unsigned int V_165 ,
unsigned int V_330 )
{
struct V_19 * V_5 =
F_23 ( V_2 , struct V_19 , V_2 ) ;
F_32 ( V_5 , V_165 != 0 ) ;
}
static void
F_144 ( struct V_1 * V_2 , unsigned int V_165 ,
unsigned int V_330 )
{
if ( V_2 -> V_331 )
V_2 -> V_331 ( V_2 , V_165 , V_330 ) ;
else
F_143 ( V_2 , V_165 , V_330 ) ;
}
static unsigned int F_145 ( struct V_19 * V_332 )
{
if ( V_332 -> V_2 . V_7 == V_8 )
return 0x1000 ;
#ifdef F_136
if ( F_138 ( V_332 ) )
return 0x16 << V_332 -> V_2 . V_14 ;
#endif
return 8 << V_332 -> V_2 . V_14 ;
}
static int F_146 ( struct V_19 * V_20 )
{
unsigned int V_333 = F_145 ( V_20 ) ;
struct V_1 * V_2 = & V_20 -> V_2 ;
int V_223 = 0 ;
switch ( V_2 -> V_7 ) {
case V_8 :
case V_334 :
case V_25 :
case V_24 :
if ( ! V_2 -> V_119 )
break;
if ( ! F_147 ( V_2 -> V_119 , V_333 , L_21 ) ) {
V_223 = - V_335 ;
break;
}
if ( V_2 -> V_110 & V_336 ) {
V_2 -> V_18 = F_148 ( V_2 -> V_119 , V_333 ) ;
if ( ! V_2 -> V_18 ) {
F_149 ( V_2 -> V_119 , V_333 ) ;
V_223 = - V_231 ;
}
}
break;
case V_21 :
case V_337 :
if ( ! F_150 ( V_2 -> V_16 , V_333 , L_21 ) )
V_223 = - V_335 ;
break;
}
return V_223 ;
}
static void F_151 ( struct V_19 * V_20 )
{
unsigned int V_333 = F_145 ( V_20 ) ;
struct V_1 * V_2 = & V_20 -> V_2 ;
switch ( V_2 -> V_7 ) {
case V_8 :
case V_334 :
case V_25 :
case V_24 :
if ( ! V_2 -> V_119 )
break;
if ( V_2 -> V_110 & V_336 ) {
F_152 ( V_2 -> V_18 ) ;
V_2 -> V_18 = NULL ;
}
F_149 ( V_2 -> V_119 , V_333 ) ;
break;
case V_21 :
case V_337 :
F_153 ( V_2 -> V_16 , V_333 ) ;
break;
}
}
static int F_154 ( struct V_19 * V_20 )
{
unsigned long V_338 = V_339 << V_20 -> V_2 . V_14 ;
unsigned int V_333 = 8 << V_20 -> V_2 . V_14 ;
struct V_1 * V_2 = & V_20 -> V_2 ;
int V_223 = - V_340 ;
switch ( V_2 -> V_7 ) {
case V_21 :
case V_337 :
V_338 += V_2 -> V_16 ;
if ( F_150 ( V_338 , V_333 , L_25 ) )
V_223 = 0 ;
else
V_223 = - V_335 ;
break;
}
return V_223 ;
}
static void F_155 ( struct V_19 * V_20 )
{
unsigned long V_6 = V_339 << V_20 -> V_2 . V_14 ;
unsigned int V_333 = 8 << V_20 -> V_2 . V_14 ;
struct V_1 * V_2 = & V_20 -> V_2 ;
switch ( V_2 -> V_7 ) {
case V_21 :
case V_337 :
F_153 ( V_2 -> V_16 + V_6 , V_333 ) ;
break;
}
}
static void F_156 ( struct V_1 * V_2 )
{
struct V_19 * V_20 =
F_23 ( V_2 , struct V_19 , V_2 ) ;
F_151 ( V_20 ) ;
if ( V_2 -> type == V_57 )
F_155 ( V_20 ) ;
}
static int F_157 ( struct V_1 * V_2 )
{
struct V_19 * V_20 =
F_23 ( V_2 , struct V_19 , V_2 ) ;
int V_223 = 0 ;
V_223 = F_146 ( V_20 ) ;
if ( V_223 == 0 && V_2 -> type == V_57 ) {
V_223 = F_154 ( V_20 ) ;
if ( V_223 < 0 )
F_151 ( V_20 ) ;
}
return V_223 ;
}
static void F_158 ( struct V_1 * V_2 , int V_110 )
{
struct V_19 * V_20 =
F_23 ( V_2 , struct V_19 , V_2 ) ;
int V_114 = V_341 ;
int V_223 ;
V_223 = F_146 ( V_20 ) ;
if ( V_223 < 0 )
return;
V_223 = F_154 ( V_20 ) ;
if ( V_223 < 0 )
V_114 &= ~ V_126 ;
if ( V_2 -> V_7 != V_20 -> V_26 )
F_22 ( V_2 ) ;
if ( V_110 & V_342 )
F_48 ( V_20 , V_114 ) ;
if ( V_2 -> type == V_97 && V_2 -> V_7 == V_8 )
V_20 -> V_85 |= V_158 ;
if ( V_2 -> type != V_124 && V_110 & V_343 )
F_54 ( V_20 ) ;
if ( V_2 -> type != V_57 && V_114 & V_126 )
F_155 ( V_20 ) ;
if ( V_2 -> type == V_124 )
F_151 ( V_20 ) ;
}
static int
F_159 ( struct V_1 * V_2 , struct V_344 * V_345 )
{
if ( V_345 -> V_140 >= V_346 || V_345 -> V_140 < 0 ||
V_345 -> V_347 < 9600 || V_345 -> type < V_124 ||
V_345 -> type >= F_160 ( V_130 ) || V_345 -> type == V_348 ||
V_345 -> type == V_349 )
return - V_340 ;
return 0 ;
}
static const char *
F_161 ( struct V_1 * V_2 )
{
int type = V_2 -> type ;
if ( type >= F_160 ( V_130 ) )
type = 0 ;
return V_130 [ type ] . V_135 ;
}
void F_162 (
void (* F_163)( int V_2 , struct V_1 * V_20 , unsigned short * V_37 ) )
{
V_350 = F_163 ;
}
static void T_3 F_164 ( void )
{
struct V_19 * V_20 ;
static int V_351 = 1 ;
int V_127 , V_352 = 0 ;
if ( ! V_351 )
return;
V_351 = 0 ;
for ( V_127 = 0 ; V_127 < V_353 ; V_127 ++ ) {
struct V_19 * V_20 = & V_354 [ V_127 ] ;
struct V_1 * V_2 = & V_20 -> V_2 ;
V_2 -> line = V_127 ;
F_104 ( & V_2 -> V_58 ) ;
F_165 ( & V_20 -> V_234 ) ;
V_20 -> V_234 . V_279 = F_111 ;
V_20 -> V_254 = ~ V_355 ;
V_20 -> V_255 = V_355 ;
V_2 -> V_356 = & V_357 ;
}
if ( V_358 )
V_352 = V_226 ;
for ( V_127 = 0 , V_20 = V_354 ;
V_127 < F_160 ( V_359 ) && V_127 < V_353 ;
V_127 ++ , V_20 ++ ) {
struct V_1 * V_2 = & V_20 -> V_2 ;
V_2 -> V_16 = V_359 [ V_127 ] . V_2 ;
V_2 -> V_140 = F_166 ( V_359 [ V_127 ] . V_140 ) ;
V_2 -> V_232 = V_359 [ V_127 ] . V_232 ;
V_2 -> V_55 = V_359 [ V_127 ] . V_347 * 16 ;
V_2 -> V_110 = V_359 [ V_127 ] . V_110 ;
V_2 -> V_15 = V_359 [ V_127 ] . V_15 ;
V_2 -> V_18 = V_359 [ V_127 ] . V_360 ;
V_2 -> V_7 = V_359 [ V_127 ] . V_361 ;
V_2 -> V_14 = V_359 [ V_127 ] . V_362 ;
F_22 ( V_2 ) ;
V_2 -> V_232 |= V_352 ;
if ( V_350 != NULL )
V_350 ( V_127 , & V_20 -> V_2 , & V_20 -> V_37 ) ;
}
}
static void
F_167 ( struct V_19 * V_20 , unsigned int type )
{
V_20 -> V_2 . type = type ;
V_20 -> V_2 . V_132 = V_130 [ type ] . V_133 ;
V_20 -> V_37 = V_130 [ type ] . V_110 ;
V_20 -> V_134 = V_130 [ type ] . V_134 ;
}
static void T_3
F_168 ( struct V_363 * V_364 , struct V_365 * V_366 )
{
int V_127 ;
for ( V_127 = 0 ; V_127 < V_353 ; V_127 ++ ) {
struct V_19 * V_20 = & V_354 [ V_127 ] ;
V_20 -> V_26 = 0xFF ;
}
F_164 () ;
for ( V_127 = 0 ; V_127 < V_353 ; V_127 ++ ) {
struct V_19 * V_20 = & V_354 [ V_127 ] ;
V_20 -> V_2 . V_366 = V_366 ;
if ( V_20 -> V_2 . V_110 & V_367 )
F_167 ( V_20 , V_20 -> V_2 . type ) ;
F_169 ( V_364 , & V_20 -> V_2 ) ;
}
}
static void F_170 ( struct V_1 * V_2 , int V_166 )
{
struct V_19 * V_20 =
F_23 ( V_2 , struct V_19 , V_2 ) ;
F_119 ( V_20 , V_154 ) ;
F_63 ( V_2 , V_69 , V_166 ) ;
}
static void
F_171 ( struct V_368 * V_369 , const char * V_370 , unsigned int V_65 )
{
struct V_19 * V_20 = & V_354 [ V_369 -> V_371 ] ;
struct V_1 * V_2 = & V_20 -> V_2 ;
unsigned long V_110 ;
unsigned int V_146 ;
int V_372 = 1 ;
F_120 () ;
F_172 ( V_110 ) ;
if ( V_2 -> V_373 ) {
V_372 = 0 ;
} else if ( V_374 ) {
V_372 = F_173 ( & V_2 -> V_58 ) ;
} else
F_77 ( & V_2 -> V_58 ) ;
V_146 = F_87 ( V_2 , V_49 ) ;
if ( V_20 -> V_37 & V_108 )
F_63 ( V_2 , V_49 , V_106 ) ;
else
F_63 ( V_2 , V_49 , 0 ) ;
F_174 ( V_2 , V_370 , V_65 , F_170 ) ;
F_119 ( V_20 , V_239 ) ;
F_63 ( V_2 , V_49 , V_146 ) ;
if ( V_20 -> V_193 )
F_82 ( V_20 ) ;
if ( V_372 )
F_75 ( & V_2 -> V_58 ) ;
F_175 ( V_110 ) ;
}
static int T_3 F_176 ( struct V_368 * V_369 , char * V_375 )
{
struct V_1 * V_2 ;
int V_286 = 9600 ;
int V_259 = 8 ;
int V_178 = 'n' ;
int V_376 = 'n' ;
if ( V_369 -> V_371 >= V_353 )
V_369 -> V_371 = 0 ;
V_2 = & V_354 [ V_369 -> V_371 ] . V_2 ;
if ( ! V_2 -> V_16 && ! V_2 -> V_18 )
return - V_268 ;
if ( V_375 )
F_177 ( V_375 , & V_286 , & V_178 , & V_259 , & V_376 ) ;
return F_178 ( V_2 , V_369 , V_286 , V_178 , V_259 , V_376 ) ;
}
static int F_179 ( void )
{
return F_180 () ;
}
static int T_3 F_181 ( void )
{
if ( V_353 > V_377 )
V_353 = V_377 ;
F_164 () ;
F_182 ( & V_378 ) ;
return 0 ;
}
int F_183 ( struct V_1 * V_5 )
{
int line ;
struct V_1 * V_2 ;
for ( line = 0 ; line < V_353 ; line ++ ) {
V_2 = & V_354 [ line ] . V_2 ;
if ( F_184 ( V_5 , V_2 ) )
return line ;
}
return - V_268 ;
}
int T_3 F_185 ( struct V_1 * V_2 )
{
struct V_1 * V_5 ;
if ( V_2 -> line >= F_160 ( V_354 ) )
return - V_268 ;
F_164 () ;
V_5 = & V_354 [ V_2 -> line ] . V_2 ;
V_5 -> V_16 = V_2 -> V_16 ;
V_5 -> V_18 = V_2 -> V_18 ;
V_5 -> V_140 = V_2 -> V_140 ;
V_5 -> V_232 = V_2 -> V_232 ;
V_5 -> V_55 = V_2 -> V_55 ;
V_5 -> V_132 = V_2 -> V_132 ;
V_5 -> V_14 = V_2 -> V_14 ;
V_5 -> V_7 = V_2 -> V_7 ;
V_5 -> V_110 = V_2 -> V_110 ;
V_5 -> V_119 = V_2 -> V_119 ;
V_5 -> V_379 = V_2 -> V_379 ;
V_5 -> type = V_2 -> type ;
V_5 -> line = V_2 -> line ;
F_22 ( V_5 ) ;
if ( V_2 -> V_22 )
V_5 -> V_22 = V_2 -> V_22 ;
if ( V_2 -> V_23 )
V_5 -> V_23 = V_2 -> V_23 ;
if ( V_2 -> V_27 )
V_5 -> V_27 = V_2 -> V_27 ;
else
V_5 -> V_27 = V_28 ;
return 0 ;
}
void F_186 ( int line )
{
F_187 ( & V_3 , & V_354 [ line ] . V_2 ) ;
}
void F_188 ( int line )
{
struct V_19 * V_20 = & V_354 [ line ] ;
struct V_1 * V_2 = & V_20 -> V_2 ;
if ( V_20 -> V_37 & V_101 ) {
F_63 ( V_2 , V_29 , 0xE0 ) ;
F_45 ( V_20 ) ;
F_63 ( V_2 , V_29 , 0 ) ;
V_2 -> V_55 = 921600 * 16 ;
}
F_189 ( & V_3 , V_2 ) ;
}
static int T_4 F_190 ( struct V_380 * V_366 )
{
struct V_381 * V_5 = V_366 -> V_366 . V_382 ;
struct V_1 V_2 ;
int V_223 , V_127 , V_352 = 0 ;
memset ( & V_2 , 0 , sizeof( struct V_1 ) ) ;
if ( V_358 )
V_352 = V_226 ;
for ( V_127 = 0 ; V_5 && V_5 -> V_110 != 0 ; V_5 ++ , V_127 ++ ) {
V_2 . V_16 = V_5 -> V_16 ;
V_2 . V_18 = V_5 -> V_18 ;
V_2 . V_140 = V_5 -> V_140 ;
V_2 . V_232 = V_5 -> V_232 ;
V_2 . V_55 = V_5 -> V_55 ;
V_2 . V_14 = V_5 -> V_14 ;
V_2 . V_7 = V_5 -> V_7 ;
V_2 . V_110 = V_5 -> V_110 ;
V_2 . V_119 = V_5 -> V_119 ;
V_2 . V_15 = V_5 -> V_15 ;
V_2 . V_379 = V_5 -> V_379 ;
V_2 . type = V_5 -> type ;
V_2 . V_22 = V_5 -> V_22 ;
V_2 . V_23 = V_5 -> V_23 ;
V_2 . V_27 = V_5 -> V_27 ;
V_2 . V_326 = V_5 -> V_326 ;
V_2 . V_331 = V_5 -> V_331 ;
V_2 . V_366 = & V_366 -> V_366 ;
V_2 . V_232 |= V_352 ;
V_223 = F_191 ( & V_2 ) ;
if ( V_223 < 0 ) {
F_192 ( & V_366 -> V_366 , L_26
L_27 , V_127 ,
V_5 -> V_16 , ( unsigned long long ) V_5 -> V_119 ,
V_5 -> V_140 , V_223 ) ;
}
}
return 0 ;
}
static int T_5 F_193 ( struct V_380 * V_366 )
{
int V_127 ;
for ( V_127 = 0 ; V_127 < V_353 ; V_127 ++ ) {
struct V_19 * V_20 = & V_354 [ V_127 ] ;
if ( V_20 -> V_2 . V_366 == & V_366 -> V_366 )
F_194 ( V_127 ) ;
}
return 0 ;
}
static int F_195 ( struct V_380 * V_366 , T_6 V_165 )
{
int V_127 ;
for ( V_127 = 0 ; V_127 < V_377 ; V_127 ++ ) {
struct V_19 * V_20 = & V_354 [ V_127 ] ;
if ( V_20 -> V_2 . type != V_124 && V_20 -> V_2 . V_366 == & V_366 -> V_366 )
F_187 ( & V_3 , & V_20 -> V_2 ) ;
}
return 0 ;
}
static int F_196 ( struct V_380 * V_366 )
{
int V_127 ;
for ( V_127 = 0 ; V_127 < V_377 ; V_127 ++ ) {
struct V_19 * V_20 = & V_354 [ V_127 ] ;
if ( V_20 -> V_2 . type != V_124 && V_20 -> V_2 . V_366 == & V_366 -> V_366 )
F_188 ( V_127 ) ;
}
return 0 ;
}
static struct V_19 * F_197 ( struct V_1 * V_2 )
{
int V_127 ;
for ( V_127 = 0 ; V_127 < V_353 ; V_127 ++ )
if ( F_184 ( & V_354 [ V_127 ] . V_2 , V_2 ) )
return & V_354 [ V_127 ] ;
for ( V_127 = 0 ; V_127 < V_353 ; V_127 ++ )
if ( V_354 [ V_127 ] . V_2 . type == V_124 &&
V_354 [ V_127 ] . V_2 . V_16 == 0 )
return & V_354 [ V_127 ] ;
for ( V_127 = 0 ; V_127 < V_353 ; V_127 ++ )
if ( V_354 [ V_127 ] . V_2 . type == V_124 )
return & V_354 [ V_127 ] ;
return NULL ;
}
int F_191 ( struct V_1 * V_2 )
{
struct V_19 * V_383 ;
int V_223 = - V_384 ;
if ( V_2 -> V_55 == 0 )
return - V_340 ;
F_99 ( & V_385 ) ;
V_383 = F_197 ( V_2 ) ;
if ( V_383 ) {
F_198 ( & V_3 , & V_383 -> V_2 ) ;
V_383 -> V_2 . V_16 = V_2 -> V_16 ;
V_383 -> V_2 . V_18 = V_2 -> V_18 ;
V_383 -> V_2 . V_140 = V_2 -> V_140 ;
V_383 -> V_2 . V_232 = V_2 -> V_232 ;
V_383 -> V_2 . V_55 = V_2 -> V_55 ;
V_383 -> V_2 . V_132 = V_2 -> V_132 ;
V_383 -> V_2 . V_14 = V_2 -> V_14 ;
V_383 -> V_2 . V_7 = V_2 -> V_7 ;
V_383 -> V_2 . V_110 = V_2 -> V_110 | V_386 ;
V_383 -> V_2 . V_119 = V_2 -> V_119 ;
V_383 -> V_2 . V_379 = V_2 -> V_379 ;
if ( V_2 -> V_366 )
V_383 -> V_2 . V_366 = V_2 -> V_366 ;
if ( V_2 -> V_110 & V_367 )
F_167 ( V_383 , V_2 -> type ) ;
F_22 ( & V_383 -> V_2 ) ;
if ( V_2 -> V_22 )
V_383 -> V_2 . V_22 = V_2 -> V_22 ;
if ( V_2 -> V_23 )
V_383 -> V_2 . V_23 = V_2 -> V_23 ;
if ( V_2 -> V_27 )
V_383 -> V_2 . V_27 = V_2 -> V_27 ;
if ( V_2 -> V_326 )
V_383 -> V_2 . V_326 = V_2 -> V_326 ;
if ( V_2 -> V_331 )
V_383 -> V_2 . V_331 = V_2 -> V_331 ;
if ( V_350 != NULL )
V_350 ( 0 , & V_383 -> V_2 ,
& V_383 -> V_37 ) ;
V_223 = F_169 ( & V_3 , & V_383 -> V_2 ) ;
if ( V_223 == 0 )
V_223 = V_383 -> V_2 . line ;
}
F_103 ( & V_385 ) ;
return V_223 ;
}
void F_194 ( int line )
{
struct V_19 * V_383 = & V_354 [ line ] ;
F_99 ( & V_385 ) ;
F_198 ( & V_3 , & V_383 -> V_2 ) ;
if ( V_387 ) {
V_383 -> V_2 . V_110 &= ~ V_386 ;
V_383 -> V_2 . type = V_124 ;
V_383 -> V_2 . V_366 = & V_387 -> V_366 ;
V_383 -> V_37 = V_130 [ V_383 -> V_2 . type ] . V_110 ;
F_169 ( & V_3 , & V_383 -> V_2 ) ;
} else {
V_383 -> V_2 . V_366 = NULL ;
}
F_103 ( & V_385 ) ;
}
static int T_3 F_199 ( void )
{
int V_223 ;
if ( V_353 > V_377 )
V_353 = V_377 ;
F_52 ( V_267 L_28
L_29 , V_353 ,
V_358 ? L_30 : L_31 ) ;
#ifdef F_200
V_223 = F_201 ( & V_3 , V_377 ) ;
#else
V_3 . V_388 = V_377 ;
V_223 = F_202 ( & V_3 ) ;
#endif
if ( V_223 )
goto V_121;
V_387 = F_203 ( L_32 ,
V_389 ) ;
if ( ! V_387 ) {
V_223 = - V_231 ;
goto V_390;
}
V_223 = F_204 ( V_387 ) ;
if ( V_223 )
goto V_391;
F_168 ( & V_3 , & V_387 -> V_366 ) ;
V_223 = F_205 ( & V_392 ) ;
if ( V_223 == 0 )
goto V_121;
F_206 ( V_387 ) ;
V_391:
F_207 ( V_387 ) ;
V_390:
#ifdef F_200
F_208 ( & V_3 , V_377 ) ;
#else
F_209 ( & V_3 ) ;
#endif
V_121:
return V_223 ;
}
static void T_7 F_210 ( void )
{
struct V_380 * V_393 = V_387 ;
V_387 = NULL ;
F_211 ( & V_392 ) ;
F_212 ( V_393 ) ;
#ifdef F_200
F_208 ( & V_3 , V_377 ) ;
#else
F_209 ( & V_3 ) ;
#endif
}
