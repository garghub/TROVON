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
F_24 ( struct V_19 * V_20 , int V_6 , int V_17 )
{
struct V_1 * V_5 = & V_20 -> V_2 ;
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
return F_26 ( V_20 , V_30 ) | F_26 ( V_20 , V_31 ) << 8 ;
}
static inline void F_27 ( struct V_19 * V_20 , int V_17 )
{
F_28 ( V_20 , V_30 , V_17 & 0xff ) ;
F_28 ( V_20 , V_31 , V_17 >> 8 & 0xff ) ;
}
static int F_29 ( struct V_19 * V_20 )
{
if ( V_20 -> V_2 . V_7 == V_8 )
return F_17 ( V_20 -> V_2 . V_18 + 0x28 ) ;
else
return F_25 ( V_20 ) ;
}
static void F_30 ( struct V_19 * V_20 , int V_17 )
{
if ( V_20 -> V_2 . V_7 == V_8 )
F_19 ( V_17 , V_20 -> V_2 . V_18 + 0x28 ) ;
else
F_27 ( V_20 , V_17 ) ;
}
static int F_29 ( struct V_19 * V_20 )
{
return ( V_20 -> V_2 . V_7 == V_11 ) ?
( ( ( F_17 ( V_20 -> V_2 . V_18 + 0x10 ) << 8 ) |
( F_17 ( V_20 -> V_2 . V_18 + 0x08 ) & 0xff ) ) & 0xffff ) :
F_25 ( V_20 ) ;
}
static void F_30 ( struct V_19 * V_20 , int V_17 )
{
if ( V_20 -> V_2 . V_7 == V_11 ) {
F_19 ( V_17 , V_20 -> V_2 . V_18 + 0x08 ) ;
F_19 ( V_17 >> 8 , V_20 -> V_2 . V_18 + 0x10 ) ;
} else {
F_27 ( V_20 , V_17 ) ;
}
}
static void F_31 ( struct V_19 * V_20 , int V_6 , int V_17 )
{
V_23 ( V_20 , V_32 , V_6 ) ;
V_23 ( V_20 , V_33 , V_17 ) ;
}
static unsigned int F_32 ( struct V_19 * V_20 , int V_6 )
{
unsigned int V_17 ;
F_31 ( V_20 , V_34 , V_20 -> V_35 | V_36 ) ;
V_23 ( V_20 , V_32 , V_6 ) ;
V_17 = V_22 ( V_20 , V_33 ) ;
F_31 ( V_20 , V_34 , V_20 -> V_35 ) ;
return V_17 ;
}
static void F_33 ( struct V_19 * V_5 )
{
if ( V_5 -> V_37 & V_38 ) {
F_28 ( V_5 , V_39 , V_40 ) ;
F_28 ( V_5 , V_39 , V_40 |
V_41 | V_42 ) ;
F_28 ( V_5 , V_39 , 0 ) ;
}
}
static void F_34 ( struct V_19 * V_5 , int V_43 )
{
if ( V_5 -> V_37 & V_44 ) {
if ( V_5 -> V_37 & V_45 ) {
F_28 ( V_5 , V_29 , V_46 ) ;
F_28 ( V_5 , V_47 , V_48 ) ;
F_28 ( V_5 , V_29 , 0 ) ;
}
F_28 ( V_5 , V_49 , V_43 ? V_50 : 0 ) ;
if ( V_5 -> V_37 & V_45 ) {
F_28 ( V_5 , V_29 , V_46 ) ;
F_28 ( V_5 , V_47 , 0 ) ;
F_28 ( V_5 , V_29 , 0 ) ;
}
}
}
static int F_35 ( struct V_19 * V_20 )
{
unsigned char V_51 ;
int V_52 ;
V_51 = F_26 ( V_20 , V_53 ) ;
V_52 = V_51 & V_54 ;
if ( ! V_52 ) {
F_28 ( V_20 , V_53 , V_51 | V_54 ) ;
V_51 = F_26 ( V_20 , V_53 ) ;
V_52 = V_51 & V_54 ;
}
if ( V_52 )
V_20 -> V_2 . V_55 = V_56 * 16 ;
return V_52 ;
}
static void F_36 ( struct V_19 * V_20 )
{
if ( V_20 -> V_2 . type == V_57 ) {
if ( V_20 -> V_2 . V_55 != V_56 * 16 ) {
F_37 ( & V_20 -> V_2 . V_58 ) ;
F_35 ( V_20 ) ;
F_38 ( & V_20 -> V_2 . V_58 ) ;
}
if ( V_20 -> V_2 . V_55 == V_56 * 16 )
F_28 ( V_20 , V_59 , 0 ) ;
}
}
static void F_39 ( struct V_19 * V_20 )
{
unsigned char V_51 ;
int V_52 ;
if ( V_20 -> V_2 . type == V_57 &&
V_20 -> V_2 . V_55 == V_56 * 16 ) {
F_37 ( & V_20 -> V_2 . V_58 ) ;
V_51 = F_26 ( V_20 , V_53 ) ;
V_52 = ! ( V_51 & V_54 ) ;
if ( ! V_52 ) {
F_28 ( V_20 , V_53 , V_51 & ~ V_54 ) ;
V_51 = F_26 ( V_20 , V_53 ) ;
V_52 = ! ( V_51 & V_54 ) ;
}
if ( V_52 )
V_20 -> V_2 . V_55 = V_60 * 16 ;
F_38 ( & V_20 -> V_2 . V_58 ) ;
}
}
static int F_40 ( struct V_19 * V_20 )
{
unsigned char V_61 , V_62 , V_63 ;
unsigned short V_64 ;
int V_65 ;
V_63 = F_26 ( V_20 , V_29 ) ;
F_28 ( V_20 , V_29 , 0 ) ;
V_61 = F_26 ( V_20 , V_39 ) ;
V_62 = F_26 ( V_20 , V_66 ) ;
F_28 ( V_20 , V_39 , V_40 |
V_41 | V_42 ) ;
F_28 ( V_20 , V_66 , V_67 ) ;
F_28 ( V_20 , V_29 , V_68 ) ;
V_64 = F_29 ( V_20 ) ;
F_30 ( V_20 , 0x0001 ) ;
F_28 ( V_20 , V_29 , 0x03 ) ;
for ( V_65 = 0 ; V_65 < 256 ; V_65 ++ )
F_28 ( V_20 , V_69 , V_65 ) ;
F_41 ( 20 ) ;
for ( V_65 = 0 ; ( F_26 ( V_20 , V_70 ) & V_71 ) &&
( V_65 < 256 ) ; V_65 ++ )
F_26 ( V_20 , V_72 ) ;
F_28 ( V_20 , V_39 , V_61 ) ;
F_28 ( V_20 , V_66 , V_62 ) ;
F_28 ( V_20 , V_29 , V_68 ) ;
F_30 ( V_20 , V_64 ) ;
F_28 ( V_20 , V_29 , V_63 ) ;
return V_65 ;
}
static unsigned int F_42 ( struct V_19 * V_5 )
{
unsigned char V_73 , V_74 , V_63 ;
unsigned int V_75 ;
V_63 = F_26 ( V_5 , V_29 ) ;
F_28 ( V_5 , V_29 , V_68 ) ;
V_73 = F_26 ( V_5 , V_30 ) ;
V_74 = F_26 ( V_5 , V_31 ) ;
F_28 ( V_5 , V_30 , 0 ) ;
F_28 ( V_5 , V_31 , 0 ) ;
V_75 = F_26 ( V_5 , V_30 ) | F_26 ( V_5 , V_31 ) << 8 ;
F_28 ( V_5 , V_30 , V_73 ) ;
F_28 ( V_5 , V_31 , V_74 ) ;
F_28 ( V_5 , V_29 , V_63 ) ;
return V_75 ;
}
static void F_43 ( struct V_19 * V_20 )
{
unsigned int V_76 , V_77 , V_78 , V_79 ;
V_20 -> V_37 |= V_45 | V_44 ;
V_20 -> V_35 = 0 ;
V_23 ( V_20 , V_29 , V_46 ) ;
V_23 ( V_20 , V_47 , V_48 ) ;
V_23 ( V_20 , V_29 , 0x00 ) ;
V_76 = F_32 ( V_20 , V_80 ) ;
V_77 = F_32 ( V_20 , V_81 ) ;
V_78 = F_32 ( V_20 , V_82 ) ;
V_79 = F_32 ( V_20 , V_83 ) ;
F_44 ( L_1 , V_76 , V_77 , V_78 , V_79 ) ;
if ( V_76 == 0x16 && V_77 == 0xC9 &&
( V_78 == 0x50 || V_78 == 0x52 || V_78 == 0x54 ) ) {
V_20 -> V_2 . type = V_84 ;
if ( V_78 == 0x52 && V_79 == 0x01 )
V_20 -> V_85 |= V_86 ;
return;
}
V_76 = F_42 ( V_20 ) ;
F_44 ( L_2 , V_76 ) ;
V_77 = V_76 >> 8 ;
if ( V_77 == 0x10 || V_77 == 0x12 || V_77 == 0x14 ) {
V_20 -> V_2 . type = V_87 ;
return;
}
if ( F_40 ( V_20 ) == 64 )
V_20 -> V_2 . type = V_88 ;
else
V_20 -> V_2 . type = V_89 ;
}
static void F_45 ( struct V_19 * V_20 )
{
unsigned char V_90 , V_91 , V_92 ;
V_20 -> V_2 . type = V_93 ;
V_90 = V_22 ( V_20 , V_32 ) ;
F_28 ( V_20 , V_32 , 0xa5 ) ;
V_91 = V_22 ( V_20 , V_32 ) ;
F_28 ( V_20 , V_32 , 0x5a ) ;
V_92 = V_22 ( V_20 , V_32 ) ;
F_28 ( V_20 , V_32 , V_90 ) ;
if ( V_91 == 0xa5 && V_92 == 0x5a )
V_20 -> V_2 . type = V_94 ;
}
static int F_46 ( struct V_19 * V_20 )
{
if ( F_42 ( V_20 ) == 0x0201 && F_40 ( V_20 ) == 16 )
return 1 ;
return 0 ;
}
static inline int F_47 ( struct V_19 * V_20 )
{
unsigned char V_95 ;
V_95 = V_22 ( V_20 , 0x04 ) ;
#define F_48 ( T_1 ) ((x) & 0x30)
if ( F_48 ( V_95 ) == 0x10 ) {
return 0 ;
} else {
V_95 &= ~ 0xB0 ;
V_95 |= 0x10 ;
F_28 ( V_20 , 0x04 , V_95 ) ;
}
return 1 ;
}
static void F_49 ( struct V_19 * V_20 )
{
unsigned char V_91 , V_92 ;
unsigned int V_96 ;
V_20 -> V_2 . type = V_97 ;
V_20 -> V_37 |= V_38 ;
F_28 ( V_20 , V_29 , V_68 ) ;
if ( V_22 ( V_20 , V_47 ) == 0 ) {
F_28 ( V_20 , V_47 , 0xA8 ) ;
if ( V_22 ( V_20 , V_47 ) != 0 ) {
F_44 ( L_3 ) ;
V_20 -> V_2 . type = V_98 ;
V_20 -> V_37 |= V_45 | V_44 ;
} else {
F_44 ( L_4 ) ;
}
F_28 ( V_20 , V_47 , 0 ) ;
return;
}
F_28 ( V_20 , V_29 , V_46 ) ;
if ( V_22 ( V_20 , V_47 ) == 0 && ! F_46 ( V_20 ) ) {
F_44 ( L_5 ) ;
F_43 ( V_20 ) ;
return;
}
F_28 ( V_20 , V_29 , 0 ) ;
V_91 = V_22 ( V_20 , V_66 ) ;
F_28 ( V_20 , V_29 , 0xE0 ) ;
V_92 = V_22 ( V_20 , 0x02 ) ;
if ( ! ( ( V_92 ^ V_91 ) & V_67 ) ) {
F_28 ( V_20 , V_29 , 0 ) ;
F_28 ( V_20 , V_66 , V_91 ^ V_67 ) ;
F_28 ( V_20 , V_29 , 0xE0 ) ;
V_92 = V_22 ( V_20 , 0x02 ) ;
F_28 ( V_20 , V_29 , 0 ) ;
F_28 ( V_20 , V_66 , V_91 ) ;
if ( ( V_92 ^ V_91 ) & V_67 ) {
unsigned short V_99 ;
F_28 ( V_20 , V_29 , 0xE0 ) ;
V_99 = F_29 ( V_20 ) ;
V_99 <<= 3 ;
if ( F_47 ( V_20 ) )
F_30 ( V_20 , V_99 ) ;
F_28 ( V_20 , V_29 , 0 ) ;
V_20 -> V_2 . V_55 = 921600 * 16 ;
V_20 -> V_2 . type = V_100 ;
V_20 -> V_37 |= V_101 ;
return;
}
}
F_28 ( V_20 , V_29 , 0 ) ;
F_28 ( V_20 , V_39 , V_40 | V_102 ) ;
V_91 = V_22 ( V_20 , V_103 ) >> 5 ;
F_28 ( V_20 , V_39 , V_40 ) ;
F_28 ( V_20 , V_29 , V_68 ) ;
F_28 ( V_20 , V_39 , V_40 | V_102 ) ;
V_92 = V_22 ( V_20 , V_103 ) >> 5 ;
F_28 ( V_20 , V_39 , V_40 ) ;
F_28 ( V_20 , V_29 , 0 ) ;
F_44 ( L_6 , V_91 , V_92 ) ;
if ( V_91 == 6 && V_92 == 7 ) {
V_20 -> V_2 . type = V_104 ;
V_20 -> V_37 |= V_105 | V_44 ;
return;
}
V_96 = V_22 ( V_20 , V_49 ) ;
F_28 ( V_20 , V_49 , V_96 & ~ V_106 ) ;
if ( ! ( V_22 ( V_20 , V_49 ) & V_106 ) ) {
F_28 ( V_20 , V_49 , V_96 | V_106 ) ;
if ( V_22 ( V_20 , V_49 ) & V_106 ) {
F_44 ( L_7 ) ;
V_20 -> V_2 . type = V_107 ;
V_20 -> V_37 |= V_108 | V_109 ;
return;
}
} else {
F_44 ( L_8 ) ;
}
F_28 ( V_20 , V_49 , V_96 ) ;
if ( V_20 -> V_2 . V_110 & V_111 ) {
V_20 -> V_2 . type = V_112 ;
V_20 -> V_37 |= V_105 | V_45 ;
}
if ( V_20 -> V_2 . type == V_97 && F_40 ( V_20 ) == 64 ) {
V_20 -> V_2 . type = V_113 ;
V_20 -> V_37 |= V_105 ;
}
}
static void F_50 ( struct V_19 * V_20 , unsigned int V_114 )
{
unsigned char V_91 , V_90 , V_115 , V_116 ;
unsigned char V_117 , V_118 ;
unsigned long V_110 ;
if ( ! V_20 -> V_2 . V_16 && ! V_20 -> V_2 . V_119 && ! V_20 -> V_2 . V_18 )
return;
F_44 ( L_9 ,
F_1 ( & V_20 -> V_2 ) , V_20 -> V_2 . V_16 , V_20 -> V_2 . V_18 ) ;
F_51 ( & V_20 -> V_2 . V_58 , V_110 ) ;
V_20 -> V_37 = 0 ;
V_20 -> V_85 = 0 ;
if ( ! ( V_20 -> V_2 . V_110 & V_120 ) ) {
V_90 = F_26 ( V_20 , V_49 ) ;
F_28 ( V_20 , V_49 , 0 ) ;
#ifdef F_52
F_5 ( 0xff , 0x080 ) ;
#endif
V_115 = F_26 ( V_20 , V_49 ) & 0x0f ;
F_28 ( V_20 , V_49 , 0x0F ) ;
#ifdef F_52
F_5 ( 0 , 0x080 ) ;
#endif
V_116 = F_26 ( V_20 , V_49 ) & 0x0f ;
F_28 ( V_20 , V_49 , V_90 ) ;
if ( V_115 != 0 || V_116 != 0x0F ) {
F_44 ( L_10 ,
V_115 , V_116 ) ;
goto V_121;
}
}
V_118 = V_22 ( V_20 , V_66 ) ;
V_117 = V_22 ( V_20 , V_29 ) ;
if ( ! ( V_20 -> V_2 . V_110 & V_122 ) ) {
F_28 ( V_20 , V_66 , V_67 | 0x0A ) ;
V_91 = F_26 ( V_20 , V_123 ) & 0xF0 ;
F_28 ( V_20 , V_66 , V_118 ) ;
if ( V_91 != 0x90 ) {
F_44 ( L_11 ,
V_91 ) ;
goto V_121;
}
}
F_28 ( V_20 , V_29 , V_46 ) ;
F_28 ( V_20 , V_47 , 0 ) ;
F_28 ( V_20 , V_29 , 0 ) ;
F_28 ( V_20 , V_39 , V_40 ) ;
V_90 = V_22 ( V_20 , V_103 ) >> 6 ;
F_44 ( L_12 , V_90 ) ;
switch ( V_90 ) {
case 0 :
F_45 ( V_20 ) ;
break;
case 1 :
V_20 -> V_2 . type = V_124 ;
break;
case 2 :
V_20 -> V_2 . type = V_125 ;
break;
case 3 :
F_49 ( V_20 ) ;
break;
}
#ifdef F_53
if ( V_20 -> V_2 . type == V_97 && V_114 & V_126 ) {
int V_127 ;
for ( V_127 = 0 ; V_127 < V_128 ; ++ V_127 ) {
if ( V_129 [ V_127 ] == V_20 -> V_2 . V_16 &&
F_35 ( V_20 ) ) {
V_20 -> V_2 . type = V_57 ;
break;
}
}
}
#endif
F_28 ( V_20 , V_29 , V_117 ) ;
if ( V_20 -> V_37 != V_130 [ V_20 -> V_2 . type ] . V_110 ) {
F_54 ( V_131
L_13 ,
F_1 ( & V_20 -> V_2 ) , V_20 -> V_37 ,
V_130 [ V_20 -> V_2 . type ] . V_110 ) ;
}
V_20 -> V_2 . V_132 = V_130 [ V_20 -> V_2 . type ] . V_133 ;
V_20 -> V_37 = V_130 [ V_20 -> V_2 . type ] . V_110 ;
V_20 -> V_134 = V_130 [ V_20 -> V_2 . type ] . V_134 ;
if ( V_20 -> V_2 . type == V_124 )
goto V_121;
#ifdef F_53
if ( V_20 -> V_2 . type == V_57 )
F_28 ( V_20 , V_59 , 0 ) ;
#endif
F_28 ( V_20 , V_66 , V_118 ) ;
F_33 ( V_20 ) ;
V_22 ( V_20 , V_72 ) ;
if ( V_20 -> V_37 & V_108 )
F_28 ( V_20 , V_49 , V_106 ) ;
else
F_28 ( V_20 , V_49 , 0 ) ;
V_121:
F_55 ( & V_20 -> V_2 . V_58 , V_110 ) ;
F_44 ( L_14 , V_130 [ V_20 -> V_2 . type ] . V_135 ) ;
}
static void F_56 ( struct V_19 * V_20 )
{
unsigned char V_118 , V_136 ;
unsigned char V_137 = 0 ;
unsigned int V_138 = 0 ;
unsigned long V_139 ;
int V_140 ;
if ( V_20 -> V_2 . V_110 & V_141 ) {
V_138 = ( V_20 -> V_2 . V_16 & 0xfe0 ) | 0x1f ;
V_137 = F_57 ( V_138 ) ;
F_58 ( 0x80 , V_138 ) ;
( void ) F_57 ( V_138 ) ;
}
F_59 ( F_60 () ) ;
V_118 = F_26 ( V_20 , V_66 ) ;
V_136 = F_26 ( V_20 , V_49 ) ;
F_28 ( V_20 , V_66 , V_142 | V_143 ) ;
V_139 = F_60 () ;
F_28 ( V_20 , V_66 , 0 ) ;
F_61 ( 10 ) ;
if ( V_20 -> V_2 . V_110 & V_141 ) {
F_28 ( V_20 , V_66 ,
V_144 | V_145 ) ;
} else {
F_28 ( V_20 , V_66 ,
V_144 | V_145 | V_143 ) ;
}
F_28 ( V_20 , V_49 , 0x0f ) ;
( void ) F_26 ( V_20 , V_70 ) ;
( void ) F_26 ( V_20 , V_72 ) ;
( void ) F_26 ( V_20 , V_103 ) ;
( void ) F_26 ( V_20 , V_123 ) ;
F_28 ( V_20 , V_69 , 0xFF ) ;
F_61 ( 20 ) ;
V_140 = F_59 ( V_139 ) ;
F_28 ( V_20 , V_66 , V_118 ) ;
F_28 ( V_20 , V_49 , V_136 ) ;
if ( V_20 -> V_2 . V_110 & V_141 )
F_58 ( V_137 , V_138 ) ;
V_20 -> V_2 . V_140 = ( V_140 > 0 ) ? V_140 : 0 ;
}
static inline void F_62 ( struct V_19 * V_5 )
{
if ( V_5 -> V_146 & V_147 ) {
V_5 -> V_146 &= ~ V_147 ;
V_23 ( V_5 , V_49 , V_5 -> V_146 ) ;
}
}
static void F_63 ( struct V_1 * V_2 )
{
struct V_19 * V_20 =
F_23 ( V_2 , struct V_19 , V_2 ) ;
F_62 ( V_20 ) ;
if ( V_20 -> V_2 . type == V_84 ) {
V_20 -> V_35 |= V_148 ;
F_31 ( V_20 , V_34 , V_20 -> V_35 ) ;
}
}
static void F_64 ( struct V_1 * V_2 )
{
struct V_19 * V_20 =
F_23 ( V_2 , struct V_19 , V_2 ) ;
if ( ! ( V_20 -> V_146 & V_147 ) ) {
V_20 -> V_146 |= V_147 ;
V_23 ( V_20 , V_49 , V_20 -> V_146 ) ;
if ( V_20 -> V_85 & V_149 ) {
unsigned char V_150 ;
V_150 = V_22 ( V_20 , V_70 ) ;
V_20 -> V_151 |= V_150 & V_152 ;
if ( ( V_20 -> V_2 . type == V_153 ) ?
( V_150 & V_154 ) :
( V_150 & V_155 ) )
F_65 ( V_20 ) ;
}
}
if ( V_20 -> V_2 . type == V_84 && V_20 -> V_35 & V_148 ) {
V_20 -> V_35 &= ~ V_148 ;
F_31 ( V_20 , V_34 , V_20 -> V_35 ) ;
}
}
static void F_66 ( struct V_1 * V_2 )
{
struct V_19 * V_20 =
F_23 ( V_2 , struct V_19 , V_2 ) ;
V_20 -> V_146 &= ~ V_156 ;
V_20 -> V_2 . V_157 &= ~ V_71 ;
V_23 ( V_20 , V_49 , V_20 -> V_146 ) ;
}
static void F_67 ( struct V_1 * V_2 )
{
struct V_19 * V_20 =
F_23 ( V_2 , struct V_19 , V_2 ) ;
if ( V_20 -> V_85 & V_158 )
return;
V_20 -> V_146 |= V_159 ;
V_23 ( V_20 , V_49 , V_20 -> V_146 ) ;
}
static void F_68 ( struct V_19 * V_20 )
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
F_61 ( 1 ) ;
} while ( 1 );
}
unsigned char
F_69 ( struct V_19 * V_20 , unsigned char V_150 )
{
struct V_163 * V_164 = V_20 -> V_2 . V_165 -> V_2 . V_164 ;
unsigned char V_166 ;
int V_167 = 256 ;
char V_168 ;
do {
if ( F_70 ( V_150 & V_71 ) )
V_166 = F_26 ( V_20 , V_72 ) ;
else
V_166 = 0 ;
V_168 = V_169 ;
V_20 -> V_2 . V_170 . V_171 ++ ;
V_150 |= V_20 -> V_151 ;
V_20 -> V_151 = 0 ;
if ( F_71 ( V_150 & V_162 ) ) {
if ( V_150 & V_172 ) {
V_150 &= ~ ( V_173 | V_174 ) ;
V_20 -> V_2 . V_170 . V_175 ++ ;
if ( V_20 -> V_2 . type == V_176 )
F_68 ( V_20 ) ;
if ( F_72 ( & V_20 -> V_2 ) )
goto V_177;
} else if ( V_150 & V_174 )
V_20 -> V_2 . V_170 . V_178 ++ ;
else if ( V_150 & V_173 )
V_20 -> V_2 . V_170 . V_179 ++ ;
if ( V_150 & V_180 )
V_20 -> V_2 . V_170 . V_181 ++ ;
V_150 &= V_20 -> V_2 . V_157 ;
if ( V_150 & V_172 ) {
F_73 ( L_15 ) ;
V_168 = V_182 ;
} else if ( V_150 & V_174 )
V_168 = V_183 ;
else if ( V_150 & V_173 )
V_168 = V_184 ;
}
if ( F_74 ( & V_20 -> V_2 , V_166 ) )
goto V_177;
F_75 ( & V_20 -> V_2 , V_150 , V_180 , V_166 , V_168 ) ;
V_177:
V_150 = F_26 ( V_20 , V_70 ) ;
} while ( ( V_150 & ( V_71 | V_172 ) ) && ( V_167 -- > 0 ) );
F_76 ( & V_20 -> V_2 . V_58 ) ;
F_77 ( V_164 ) ;
F_78 ( & V_20 -> V_2 . V_58 ) ;
return V_150 ;
}
void F_65 ( struct V_19 * V_20 )
{
struct V_185 * V_186 = & V_20 -> V_2 . V_165 -> V_186 ;
int V_65 ;
if ( V_20 -> V_2 . V_187 ) {
F_28 ( V_20 , V_69 , V_20 -> V_2 . V_187 ) ;
V_20 -> V_2 . V_170 . V_188 ++ ;
V_20 -> V_2 . V_187 = 0 ;
return;
}
if ( F_79 ( & V_20 -> V_2 ) ) {
F_63 ( & V_20 -> V_2 ) ;
return;
}
if ( F_80 ( V_186 ) ) {
F_62 ( V_20 ) ;
return;
}
V_65 = V_20 -> V_134 ;
do {
V_23 ( V_20 , V_69 , V_186 -> V_189 [ V_186 -> V_190 ] ) ;
V_186 -> V_190 = ( V_186 -> V_190 + 1 ) & ( V_191 - 1 ) ;
V_20 -> V_2 . V_170 . V_188 ++ ;
if ( F_80 ( V_186 ) )
break;
} while ( -- V_65 > 0 );
if ( F_81 ( V_186 ) < V_192 )
F_82 ( & V_20 -> V_2 ) ;
F_73 ( L_16 ) ;
if ( F_80 ( V_186 ) )
F_62 ( V_20 ) ;
}
unsigned int F_83 ( struct V_19 * V_20 )
{
unsigned int V_95 = V_22 ( V_20 , V_123 ) ;
V_95 |= V_20 -> V_193 ;
V_20 -> V_193 = 0 ;
if ( V_95 & V_194 && V_20 -> V_146 & V_159 &&
V_20 -> V_2 . V_165 != NULL ) {
if ( V_95 & V_195 )
V_20 -> V_2 . V_170 . V_196 ++ ;
if ( V_95 & V_197 )
V_20 -> V_2 . V_170 . V_198 ++ ;
if ( V_95 & V_199 )
F_84 ( & V_20 -> V_2 , V_95 & V_200 ) ;
if ( V_95 & V_201 )
F_85 ( & V_20 -> V_2 , V_95 & V_202 ) ;
F_86 ( & V_20 -> V_2 . V_165 -> V_2 . V_203 ) ;
}
return V_95 ;
}
int F_87 ( struct V_1 * V_2 , unsigned int V_204 )
{
unsigned char V_95 ;
unsigned long V_110 ;
struct V_19 * V_20 =
F_23 ( V_2 , struct V_19 , V_2 ) ;
if ( V_204 & V_205 )
return 0 ;
F_51 ( & V_20 -> V_2 . V_58 , V_110 ) ;
V_95 = F_26 ( V_20 , V_70 ) ;
F_73 ( L_17 , V_95 ) ;
if ( V_95 & ( V_71 | V_172 ) )
V_95 = F_69 ( V_20 , V_95 ) ;
F_83 ( V_20 ) ;
if ( V_95 & V_154 )
F_65 ( V_20 ) ;
F_55 ( & V_20 -> V_2 . V_58 , V_110 ) ;
return 1 ;
}
static int V_28 ( struct V_1 * V_2 )
{
struct V_19 * V_20 =
F_23 ( V_2 , struct V_19 , V_2 ) ;
unsigned int V_204 = V_22 ( V_20 , V_103 ) ;
return F_87 ( V_2 , V_204 ) ;
}
static T_2 F_88 ( int V_140 , void * V_206 )
{
struct V_207 * V_127 = V_206 ;
struct V_208 * V_209 , * V_210 = NULL ;
int V_211 = 0 , V_212 = 0 ;
F_73 ( L_18 , V_140 ) ;
F_78 ( & V_127 -> V_58 ) ;
V_209 = V_127 -> V_213 ;
do {
struct V_19 * V_20 ;
struct V_1 * V_2 ;
bool V_214 ;
V_20 = F_89 ( V_209 , struct V_19 , V_215 ) ;
V_2 = & V_20 -> V_2 ;
V_214 = V_211 && V_20 -> V_2 . V_110 & V_216 ;
if ( ! V_214 && V_2 -> V_27 ( V_2 ) ) {
V_212 = 1 ;
V_210 = NULL ;
} else if ( V_210 == NULL )
V_210 = V_209 ;
V_209 = V_209 -> V_217 ;
if ( V_209 == V_127 -> V_213 && V_211 ++ > V_218 ) {
F_90 ( V_219
L_19 , V_140 ) ;
break;
}
} while ( V_209 != V_210 );
F_76 ( & V_127 -> V_58 ) ;
F_73 ( L_20 ) ;
return F_91 ( V_212 ) ;
}
static void F_92 ( struct V_207 * V_127 , struct V_19 * V_20 )
{
F_37 ( & V_127 -> V_58 ) ;
if ( ! F_93 ( V_127 -> V_213 ) ) {
if ( V_127 -> V_213 == & V_20 -> V_215 )
V_127 -> V_213 = V_127 -> V_213 -> V_217 ;
F_94 ( & V_20 -> V_215 ) ;
} else {
F_95 ( V_127 -> V_213 != & V_20 -> V_215 ) ;
V_127 -> V_213 = NULL ;
}
F_38 ( & V_127 -> V_58 ) ;
if ( V_127 -> V_213 == NULL ) {
F_96 ( & V_127 -> V_220 ) ;
F_97 ( V_127 ) ;
}
}
static int F_98 ( struct V_19 * V_20 )
{
struct V_221 * V_222 ;
struct V_223 * V_224 ;
struct V_207 * V_127 ;
int V_225 , V_226 = V_20 -> V_2 . V_110 & V_227 ? V_228 : 0 ;
F_99 ( & V_229 ) ;
V_222 = & V_230 [ V_20 -> V_2 . V_140 % V_231 ] ;
F_100 (n, h) {
V_127 = F_101 ( V_224 , struct V_207 , V_220 ) ;
if ( V_127 -> V_140 == V_20 -> V_2 . V_140 )
break;
}
if ( V_224 == NULL ) {
V_127 = F_102 ( sizeof( struct V_207 ) , V_232 ) ;
if ( V_127 == NULL ) {
F_103 ( & V_229 ) ;
return - V_233 ;
}
F_104 ( & V_127 -> V_58 ) ;
V_127 -> V_140 = V_20 -> V_2 . V_140 ;
F_105 ( & V_127 -> V_220 , V_222 ) ;
}
F_103 ( & V_229 ) ;
F_37 ( & V_127 -> V_58 ) ;
if ( V_127 -> V_213 ) {
F_106 ( & V_20 -> V_215 , V_127 -> V_213 ) ;
F_38 ( & V_127 -> V_58 ) ;
V_225 = 0 ;
} else {
F_107 ( & V_20 -> V_215 ) ;
V_127 -> V_213 = & V_20 -> V_215 ;
F_38 ( & V_127 -> V_58 ) ;
V_226 |= V_20 -> V_2 . V_234 ;
V_225 = F_108 ( V_20 -> V_2 . V_140 , F_88 ,
V_226 , L_21 , V_127 ) ;
if ( V_225 < 0 )
F_92 ( V_127 , V_20 ) ;
}
return V_225 ;
}
static void F_109 ( struct V_19 * V_20 )
{
struct V_207 * V_127 ;
struct V_223 * V_224 ;
struct V_221 * V_222 ;
F_99 ( & V_229 ) ;
V_222 = & V_230 [ V_20 -> V_2 . V_140 % V_231 ] ;
F_100 (n, h) {
V_127 = F_101 ( V_224 , struct V_207 , V_220 ) ;
if ( V_127 -> V_140 == V_20 -> V_2 . V_140 )
break;
}
F_95 ( V_224 == NULL ) ;
F_95 ( V_127 -> V_213 == NULL ) ;
if ( F_93 ( V_127 -> V_213 ) )
F_110 ( V_20 -> V_2 . V_140 , V_127 ) ;
F_92 ( V_127 , V_20 ) ;
F_103 ( & V_229 ) ;
}
static void F_111 ( unsigned long V_235 )
{
struct V_19 * V_20 = (struct V_19 * ) V_235 ;
V_20 -> V_2 . V_27 ( & V_20 -> V_2 ) ;
F_112 ( & V_20 -> V_236 , V_237 + F_113 ( & V_20 -> V_2 ) ) ;
}
static void F_114 ( unsigned long V_235 )
{
struct V_19 * V_20 = (struct V_19 * ) V_235 ;
unsigned int V_204 , V_146 = 0 , V_150 ;
unsigned long V_110 ;
F_51 ( & V_20 -> V_2 . V_58 , V_110 ) ;
if ( F_115 ( V_20 -> V_2 . V_140 ) ) {
V_146 = V_22 ( V_20 , V_49 ) ;
V_23 ( V_20 , V_49 , 0 ) ;
}
V_204 = V_22 ( V_20 , V_103 ) ;
V_150 = V_22 ( V_20 , V_70 ) ;
V_20 -> V_151 |= V_150 & V_152 ;
if ( ( V_204 & V_205 ) && ( V_20 -> V_146 & V_147 ) &&
( ! F_80 ( & V_20 -> V_2 . V_165 -> V_186 ) || V_20 -> V_2 . V_187 ) &&
( V_150 & V_154 ) ) {
V_204 &= ~ ( V_238 | V_205 ) ;
V_204 |= V_239 ;
}
if ( ! ( V_204 & V_205 ) )
F_65 ( V_20 ) ;
if ( F_115 ( V_20 -> V_2 . V_140 ) )
V_23 ( V_20 , V_49 , V_146 ) ;
F_55 ( & V_20 -> V_2 . V_58 , V_110 ) ;
F_112 ( & V_20 -> V_236 ,
V_237 + F_113 ( & V_20 -> V_2 ) + V_240 / 5 ) ;
}
static unsigned int F_116 ( struct V_1 * V_2 )
{
struct V_19 * V_20 =
F_23 ( V_2 , struct V_19 , V_2 ) ;
unsigned long V_110 ;
unsigned int V_150 ;
F_51 ( & V_20 -> V_2 . V_58 , V_110 ) ;
V_150 = V_22 ( V_20 , V_70 ) ;
V_20 -> V_151 |= V_150 & V_152 ;
F_55 ( & V_20 -> V_2 . V_58 , V_110 ) ;
return ( V_150 & V_241 ) == V_241 ? V_242 : 0 ;
}
static unsigned int F_117 ( struct V_1 * V_2 )
{
struct V_19 * V_20 =
F_23 ( V_2 , struct V_19 , V_2 ) ;
unsigned int V_95 ;
unsigned int V_225 ;
V_95 = F_83 ( V_20 ) ;
V_225 = 0 ;
if ( V_95 & V_200 )
V_225 |= V_243 ;
if ( V_95 & V_244 )
V_225 |= V_245 ;
if ( V_95 & V_246 )
V_225 |= V_247 ;
if ( V_95 & V_202 )
V_225 |= V_248 ;
return V_225 ;
}
static void F_118 ( struct V_1 * V_2 , unsigned int V_249 )
{
struct V_19 * V_20 =
F_23 ( V_2 , struct V_19 , V_2 ) ;
unsigned char V_250 = 0 ;
if ( V_249 & V_251 )
V_250 |= V_145 ;
if ( V_249 & V_252 )
V_250 |= V_144 ;
if ( V_249 & V_253 )
V_250 |= V_142 ;
if ( V_249 & V_254 )
V_250 |= V_143 ;
if ( V_249 & V_255 )
V_250 |= V_67 ;
V_250 = ( V_250 & V_20 -> V_256 ) | V_20 -> V_257 | V_20 -> V_250 ;
V_23 ( V_20 , V_66 , V_250 ) ;
}
static void F_119 ( struct V_1 * V_2 , int V_258 )
{
struct V_19 * V_20 =
F_23 ( V_2 , struct V_19 , V_2 ) ;
unsigned long V_110 ;
F_51 ( & V_20 -> V_2 . V_58 , V_110 ) ;
if ( V_258 == - 1 )
V_20 -> V_259 |= V_260 ;
else
V_20 -> V_259 &= ~ V_260 ;
V_23 ( V_20 , V_29 , V_20 -> V_259 ) ;
F_55 ( & V_20 -> V_2 . V_58 , V_110 ) ;
}
static void F_120 ( struct V_19 * V_20 , int V_261 )
{
unsigned int V_95 , V_160 = 10000 ;
for (; ; ) {
V_95 = V_22 ( V_20 , V_70 ) ;
V_20 -> V_151 |= V_95 & V_152 ;
if ( ( V_95 & V_261 ) == V_261 )
break;
if ( -- V_160 == 0 )
break;
F_61 ( 1 ) ;
}
if ( V_20 -> V_2 . V_110 & V_262 ) {
unsigned int V_160 ;
for ( V_160 = 1000000 ; V_160 ; V_160 -- ) {
unsigned int V_263 = V_22 ( V_20 , V_123 ) ;
V_20 -> V_193 |= V_263 & V_264 ;
if ( V_263 & V_202 )
break;
F_61 ( 1 ) ;
F_121 () ;
}
}
}
static int F_122 ( struct V_1 * V_2 )
{
struct V_19 * V_20 =
F_23 ( V_2 , struct V_19 , V_2 ) ;
unsigned char V_150 = F_26 ( V_20 , V_70 ) ;
if ( ! ( V_150 & V_71 ) )
return V_265 ;
return F_26 ( V_20 , V_72 ) ;
}
static void F_123 ( struct V_1 * V_2 ,
unsigned char V_266 )
{
unsigned int V_146 ;
struct V_19 * V_20 =
F_23 ( V_2 , struct V_19 , V_2 ) ;
V_146 = V_22 ( V_20 , V_49 ) ;
if ( V_20 -> V_37 & V_108 )
V_23 ( V_20 , V_49 , V_106 ) ;
else
V_23 ( V_20 , V_49 , 0 ) ;
F_120 ( V_20 , V_241 ) ;
V_23 ( V_20 , V_69 , V_266 ) ;
if ( V_266 == 10 ) {
F_120 ( V_20 , V_241 ) ;
V_23 ( V_20 , V_69 , 13 ) ;
}
F_120 ( V_20 , V_241 ) ;
V_23 ( V_20 , V_49 , V_146 ) ;
}
static int F_124 ( struct V_1 * V_2 )
{
struct V_19 * V_20 =
F_23 ( V_2 , struct V_19 , V_2 ) ;
unsigned long V_110 ;
unsigned char V_150 , V_204 ;
int V_267 ;
V_20 -> V_2 . V_132 = V_130 [ V_20 -> V_2 . type ] . V_133 ;
V_20 -> V_134 = V_130 [ V_20 -> V_2 . type ] . V_134 ;
V_20 -> V_37 = V_130 [ V_20 -> V_2 . type ] . V_110 ;
V_20 -> V_250 = 0 ;
if ( V_20 -> V_2 . V_7 != V_20 -> V_26 )
F_22 ( V_2 ) ;
if ( V_20 -> V_2 . type == V_84 ) {
V_20 -> V_35 = 0 ;
F_28 ( V_20 , V_29 , V_46 ) ;
F_28 ( V_20 , V_47 , V_48 ) ;
F_28 ( V_20 , V_49 , 0 ) ;
F_28 ( V_20 , V_29 , 0 ) ;
F_31 ( V_20 , V_268 , 0 ) ;
F_28 ( V_20 , V_29 , V_46 ) ;
F_28 ( V_20 , V_47 , V_48 ) ;
F_28 ( V_20 , V_29 , 0 ) ;
}
#ifdef F_53
F_36 ( V_20 ) ;
#endif
F_33 ( V_20 ) ;
( void ) F_26 ( V_20 , V_70 ) ;
( void ) F_26 ( V_20 , V_72 ) ;
( void ) F_26 ( V_20 , V_103 ) ;
( void ) F_26 ( V_20 , V_123 ) ;
if ( ! ( V_20 -> V_2 . V_110 & V_120 ) &&
( F_26 ( V_20 , V_70 ) == 0xff ) ) {
F_90 ( V_269 L_22 ,
F_1 ( & V_20 -> V_2 ) ) ;
return - V_270 ;
}
if ( V_20 -> V_2 . type == V_87 ) {
unsigned char V_271 ;
F_28 ( V_20 , V_29 , V_46 ) ;
V_271 = F_26 ( V_20 , V_272 ) & ~ ( V_273 | V_274 ) ;
F_28 ( V_20 , V_272 , V_271 | V_275 | V_273 ) ;
F_28 ( V_20 , V_276 , V_277 ) ;
F_28 ( V_20 , V_272 , V_271 | V_275 | V_274 ) ;
F_28 ( V_20 , V_276 , V_277 ) ;
F_28 ( V_20 , V_29 , 0 ) ;
}
if ( F_115 ( V_20 -> V_2 . V_140 ) ) {
unsigned char V_278 ;
F_51 ( & V_20 -> V_2 . V_58 , V_110 ) ;
if ( V_20 -> V_2 . V_234 & V_228 )
F_125 ( V_20 -> V_2 . V_140 ) ;
F_120 ( V_20 , V_154 ) ;
F_24 ( V_20 , V_49 , V_147 ) ;
F_61 ( 1 ) ;
V_278 = V_22 ( V_20 , V_103 ) ;
V_23 ( V_20 , V_49 , 0 ) ;
F_24 ( V_20 , V_49 , V_147 ) ;
F_61 ( 1 ) ;
V_204 = V_22 ( V_20 , V_103 ) ;
V_23 ( V_20 , V_49 , 0 ) ;
if ( V_20 -> V_2 . V_234 & V_228 )
F_126 ( V_20 -> V_2 . V_140 ) ;
F_55 ( & V_20 -> V_2 . V_58 , V_110 ) ;
if ( ! ( V_278 & V_205 ) && ( V_204 & V_205 ) ) {
V_20 -> V_85 |= V_279 ;
F_127 ( L_23 ,
F_1 ( V_2 ) ) ;
}
}
if ( V_20 -> V_85 & V_279 ) {
V_20 -> V_236 . V_280 = F_114 ;
V_20 -> V_236 . V_235 = ( unsigned long ) V_20 ;
F_112 ( & V_20 -> V_236 , V_237 +
F_113 ( V_2 ) + V_240 / 5 ) ;
}
if ( ! F_115 ( V_20 -> V_2 . V_140 ) ) {
V_20 -> V_236 . V_235 = ( unsigned long ) V_20 ;
F_112 ( & V_20 -> V_236 , V_237 + F_113 ( V_2 ) ) ;
} else {
V_267 = F_98 ( V_20 ) ;
if ( V_267 )
return V_267 ;
}
F_28 ( V_20 , V_29 , V_281 ) ;
F_51 ( & V_20 -> V_2 . V_58 , V_110 ) ;
if ( V_20 -> V_2 . V_110 & V_141 ) {
if ( ! F_115 ( V_20 -> V_2 . V_140 ) )
V_20 -> V_2 . V_249 |= V_253 ;
} else
if ( F_115 ( V_20 -> V_2 . V_140 ) )
V_20 -> V_2 . V_249 |= V_254 ;
F_118 ( & V_20 -> V_2 , V_20 -> V_2 . V_249 ) ;
if ( V_282 || V_20 -> V_2 . V_110 & V_283 )
goto V_284;
F_28 ( V_20 , V_49 , V_147 ) ;
V_150 = V_22 ( V_20 , V_70 ) ;
V_204 = V_22 ( V_20 , V_103 ) ;
F_28 ( V_20 , V_49 , 0 ) ;
if ( V_150 & V_155 && V_204 & V_205 ) {
if ( ! ( V_20 -> V_85 & V_149 ) ) {
V_20 -> V_85 |= V_149 ;
F_127 ( L_24 ,
F_1 ( V_2 ) ) ;
}
} else {
V_20 -> V_85 &= ~ V_149 ;
}
V_284:
F_55 ( & V_20 -> V_2 . V_58 , V_110 ) ;
F_26 ( V_20 , V_70 ) ;
F_26 ( V_20 , V_72 ) ;
F_26 ( V_20 , V_103 ) ;
F_26 ( V_20 , V_123 ) ;
V_20 -> V_151 = 0 ;
V_20 -> V_193 = 0 ;
V_20 -> V_146 = V_156 | V_285 ;
F_28 ( V_20 , V_49 , V_20 -> V_146 ) ;
if ( V_20 -> V_2 . V_110 & V_141 ) {
unsigned int V_286 ;
V_286 = ( V_20 -> V_2 . V_16 & 0xfe0 ) | 0x01f ;
F_58 ( 0x80 , V_286 ) ;
( void ) F_57 ( V_286 ) ;
}
return 0 ;
}
static void F_128 ( struct V_1 * V_2 )
{
struct V_19 * V_20 =
F_23 ( V_2 , struct V_19 , V_2 ) ;
unsigned long V_110 ;
V_20 -> V_146 = 0 ;
F_28 ( V_20 , V_49 , 0 ) ;
F_51 ( & V_20 -> V_2 . V_58 , V_110 ) ;
if ( V_20 -> V_2 . V_110 & V_141 ) {
F_6 ( ( V_20 -> V_2 . V_16 & 0xfe0 ) | 0x1f ) ;
V_20 -> V_2 . V_249 |= V_253 ;
} else
V_20 -> V_2 . V_249 &= ~ V_254 ;
F_118 ( & V_20 -> V_2 , V_20 -> V_2 . V_249 ) ;
F_55 ( & V_20 -> V_2 . V_58 , V_110 ) ;
V_23 ( V_20 , V_29 , F_26 ( V_20 , V_29 ) & ~ V_260 ) ;
F_33 ( V_20 ) ;
#ifdef F_53
F_39 ( V_20 ) ;
#endif
( void ) V_22 ( V_20 , V_72 ) ;
F_129 ( & V_20 -> V_236 ) ;
V_20 -> V_236 . V_280 = F_111 ;
if ( F_115 ( V_20 -> V_2 . V_140 ) )
F_109 ( V_20 ) ;
}
static unsigned int F_130 ( struct V_1 * V_2 , unsigned int V_287 )
{
unsigned int V_99 ;
if ( ( V_2 -> V_110 & V_288 ) &&
V_287 == ( V_2 -> V_55 / 4 ) )
V_99 = 0x8001 ;
else if ( ( V_2 -> V_110 & V_288 ) &&
V_287 == ( V_2 -> V_55 / 8 ) )
V_99 = 0x8002 ;
else
V_99 = F_131 ( V_2 , V_287 ) ;
return V_99 ;
}
void
F_132 ( struct V_1 * V_2 , struct V_289 * V_290 ,
struct V_289 * V_291 )
{
struct V_19 * V_20 =
F_23 ( V_2 , struct V_19 , V_2 ) ;
unsigned char V_292 , V_293 = 0 ;
unsigned long V_110 ;
unsigned int V_287 , V_99 ;
switch ( V_290 -> V_294 & V_295 ) {
case V_296 :
V_292 = V_297 ;
break;
case V_298 :
V_292 = V_299 ;
break;
case V_300 :
V_292 = V_301 ;
break;
default:
case V_302 :
V_292 = V_281 ;
break;
}
if ( V_290 -> V_294 & V_303 )
V_292 |= V_304 ;
if ( V_290 -> V_294 & V_305 )
V_292 |= V_306 ;
if ( ! ( V_290 -> V_294 & V_307 ) )
V_292 |= V_308 ;
#ifdef F_133
if ( V_290 -> V_294 & F_133 )
V_292 |= V_309 ;
#endif
V_287 = F_134 ( V_2 , V_290 , V_291 ,
V_2 -> V_55 / 16 / 0xffff ,
V_2 -> V_55 / 16 ) ;
V_99 = F_130 ( V_2 , V_287 ) ;
if ( V_20 -> V_85 & V_86 && ( V_99 & 0xff ) == 0 )
V_99 ++ ;
if ( V_20 -> V_37 & V_38 && V_20 -> V_2 . V_132 > 1 ) {
if ( V_287 < 2400 )
V_293 = V_40 | V_310 ;
else
V_293 = V_130 [ V_20 -> V_2 . type ] . V_293 ;
}
if ( V_20 -> V_37 & V_105 && V_20 -> V_2 . V_132 >= 32 ) {
V_20 -> V_250 &= ~ V_311 ;
if ( V_290 -> V_294 & V_312 )
V_20 -> V_250 |= V_311 ;
}
F_51 ( & V_20 -> V_2 . V_58 , V_110 ) ;
F_135 ( V_2 , V_290 -> V_294 , V_287 ) ;
V_20 -> V_2 . V_157 = V_180 | V_154 | V_71 ;
if ( V_290 -> V_313 & V_314 )
V_20 -> V_2 . V_157 |= V_173 | V_174 ;
if ( V_290 -> V_313 & ( V_315 | V_316 ) )
V_20 -> V_2 . V_157 |= V_172 ;
V_20 -> V_2 . V_317 = 0 ;
if ( V_290 -> V_313 & V_318 )
V_20 -> V_2 . V_317 |= V_174 | V_173 ;
if ( V_290 -> V_313 & V_319 ) {
V_20 -> V_2 . V_317 |= V_172 ;
if ( V_290 -> V_313 & V_318 )
V_20 -> V_2 . V_317 |= V_180 ;
}
if ( ( V_290 -> V_294 & V_320 ) == 0 )
V_20 -> V_2 . V_317 |= V_71 ;
V_20 -> V_146 &= ~ V_159 ;
if ( ! ( V_20 -> V_85 & V_158 ) &&
F_136 ( & V_20 -> V_2 , V_290 -> V_294 ) )
V_20 -> V_146 |= V_159 ;
if ( V_20 -> V_37 & V_108 )
V_20 -> V_146 |= V_106 ;
if ( V_20 -> V_37 & V_109 )
V_20 -> V_146 |= V_321 ;
V_23 ( V_20 , V_49 , V_20 -> V_146 ) ;
if ( V_20 -> V_37 & V_45 ) {
unsigned char V_322 = 0 ;
if ( V_290 -> V_294 & V_312 )
V_322 |= V_323 ;
F_28 ( V_20 , V_29 , V_46 ) ;
if ( V_20 -> V_2 . V_110 & V_111 )
F_28 ( V_20 , V_324 , V_322 ) ;
else
F_28 ( V_20 , V_47 , V_322 ) ;
}
#ifdef F_137
if ( F_138 () && F_139 ( V_20 ) ) {
if ( V_287 == 115200 ) {
V_99 = 1 ;
V_23 ( V_20 , V_325 , 1 ) ;
} else
V_23 ( V_20 , V_325 , 0 ) ;
}
#endif
if ( V_20 -> V_37 & V_101 ) {
F_28 ( V_20 , V_29 , 0xe0 ) ;
} else {
F_28 ( V_20 , V_29 , V_292 | V_326 ) ;
}
F_30 ( V_20 , V_99 ) ;
if ( V_20 -> V_2 . type == V_104 )
F_28 ( V_20 , V_39 , V_293 ) ;
F_28 ( V_20 , V_29 , V_292 ) ;
V_20 -> V_259 = V_292 ;
if ( V_20 -> V_2 . type != V_104 ) {
if ( V_293 & V_40 ) {
F_28 ( V_20 , V_39 , V_40 ) ;
}
F_28 ( V_20 , V_39 , V_293 ) ;
}
F_118 ( & V_20 -> V_2 , V_20 -> V_2 . V_249 ) ;
F_55 ( & V_20 -> V_2 . V_58 , V_110 ) ;
if ( F_140 ( V_290 ) )
F_141 ( V_290 , V_287 , V_287 ) ;
}
static void
F_142 ( struct V_1 * V_2 , struct V_289 * V_290 ,
struct V_289 * V_291 )
{
if ( V_2 -> V_327 )
V_2 -> V_327 ( V_2 , V_290 , V_291 ) ;
else
F_132 ( V_2 , V_290 , V_291 ) ;
}
static void
F_143 ( struct V_1 * V_2 , int V_328 )
{
if ( V_328 == V_329 ) {
V_2 -> V_110 |= V_330 ;
F_67 ( V_2 ) ;
} else
V_2 -> V_110 &= ~ V_330 ;
}
void F_144 ( struct V_1 * V_2 , unsigned int V_165 ,
unsigned int V_331 )
{
struct V_19 * V_5 =
F_23 ( V_2 , struct V_19 , V_2 ) ;
F_34 ( V_5 , V_165 != 0 ) ;
}
static void
F_145 ( struct V_1 * V_2 , unsigned int V_165 ,
unsigned int V_331 )
{
if ( V_2 -> V_332 )
V_2 -> V_332 ( V_2 , V_165 , V_331 ) ;
else
F_144 ( V_2 , V_165 , V_331 ) ;
}
static unsigned int F_146 ( struct V_19 * V_333 )
{
if ( V_333 -> V_2 . V_7 == V_8 )
return 0x1000 ;
#ifdef F_137
if ( F_139 ( V_333 ) )
return 0x16 << V_333 -> V_2 . V_14 ;
#endif
return 8 << V_333 -> V_2 . V_14 ;
}
static int F_147 ( struct V_19 * V_20 )
{
unsigned int V_334 = F_146 ( V_20 ) ;
int V_225 = 0 ;
switch ( V_20 -> V_2 . V_7 ) {
case V_8 :
case V_335 :
case V_25 :
case V_24 :
if ( ! V_20 -> V_2 . V_119 )
break;
if ( ! F_148 ( V_20 -> V_2 . V_119 , V_334 , L_21 ) ) {
V_225 = - V_336 ;
break;
}
if ( V_20 -> V_2 . V_110 & V_337 ) {
V_20 -> V_2 . V_18 = F_149 ( V_20 -> V_2 . V_119 ,
V_334 ) ;
if ( ! V_20 -> V_2 . V_18 ) {
F_150 ( V_20 -> V_2 . V_119 , V_334 ) ;
V_225 = - V_233 ;
}
}
break;
case V_21 :
case V_338 :
if ( ! F_151 ( V_20 -> V_2 . V_16 , V_334 , L_21 ) )
V_225 = - V_336 ;
break;
}
return V_225 ;
}
static void F_152 ( struct V_19 * V_20 )
{
unsigned int V_334 = F_146 ( V_20 ) ;
switch ( V_20 -> V_2 . V_7 ) {
case V_8 :
case V_335 :
case V_25 :
case V_24 :
if ( ! V_20 -> V_2 . V_119 )
break;
if ( V_20 -> V_2 . V_110 & V_337 ) {
F_153 ( V_20 -> V_2 . V_18 ) ;
V_20 -> V_2 . V_18 = NULL ;
}
F_150 ( V_20 -> V_2 . V_119 , V_334 ) ;
break;
case V_21 :
case V_338 :
F_154 ( V_20 -> V_2 . V_16 , V_334 ) ;
break;
}
}
static int F_155 ( struct V_19 * V_20 )
{
unsigned long V_339 = V_340 << V_20 -> V_2 . V_14 ;
unsigned int V_334 = 8 << V_20 -> V_2 . V_14 ;
int V_225 = - V_341 ;
switch ( V_20 -> V_2 . V_7 ) {
case V_21 :
case V_338 :
V_339 += V_20 -> V_2 . V_16 ;
if ( F_151 ( V_339 , V_334 , L_25 ) )
V_225 = 0 ;
else
V_225 = - V_336 ;
break;
}
return V_225 ;
}
static void F_156 ( struct V_19 * V_20 )
{
unsigned long V_6 = V_340 << V_20 -> V_2 . V_14 ;
unsigned int V_334 = 8 << V_20 -> V_2 . V_14 ;
switch ( V_20 -> V_2 . V_7 ) {
case V_21 :
case V_338 :
F_154 ( V_20 -> V_2 . V_16 + V_6 , V_334 ) ;
break;
}
}
static void F_157 ( struct V_1 * V_2 )
{
struct V_19 * V_20 =
F_23 ( V_2 , struct V_19 , V_2 ) ;
F_152 ( V_20 ) ;
if ( V_20 -> V_2 . type == V_57 )
F_156 ( V_20 ) ;
}
static int F_158 ( struct V_1 * V_2 )
{
struct V_19 * V_20 =
F_23 ( V_2 , struct V_19 , V_2 ) ;
int V_225 = 0 ;
V_225 = F_147 ( V_20 ) ;
if ( V_225 == 0 && V_20 -> V_2 . type == V_57 ) {
V_225 = F_155 ( V_20 ) ;
if ( V_225 < 0 )
F_152 ( V_20 ) ;
}
return V_225 ;
}
static void F_159 ( struct V_1 * V_2 , int V_110 )
{
struct V_19 * V_20 =
F_23 ( V_2 , struct V_19 , V_2 ) ;
int V_114 = V_342 ;
int V_225 ;
V_225 = F_147 ( V_20 ) ;
if ( V_225 < 0 )
return;
V_225 = F_155 ( V_20 ) ;
if ( V_225 < 0 )
V_114 &= ~ V_126 ;
if ( V_20 -> V_2 . V_7 != V_20 -> V_26 )
F_22 ( V_2 ) ;
if ( V_110 & V_343 )
F_50 ( V_20 , V_114 ) ;
if ( V_20 -> V_2 . type == V_97 && V_20 -> V_2 . V_7 == V_8 )
V_20 -> V_85 |= V_158 ;
if ( V_20 -> V_2 . type != V_124 && V_110 & V_344 )
F_56 ( V_20 ) ;
if ( V_20 -> V_2 . type != V_57 && V_114 & V_126 )
F_156 ( V_20 ) ;
if ( V_20 -> V_2 . type == V_124 )
F_152 ( V_20 ) ;
}
static int
F_160 ( struct V_1 * V_2 , struct V_345 * V_346 )
{
if ( V_346 -> V_140 >= V_347 || V_346 -> V_140 < 0 ||
V_346 -> V_348 < 9600 || V_346 -> type < V_124 ||
V_346 -> type >= F_161 ( V_130 ) || V_346 -> type == V_349 ||
V_346 -> type == V_350 )
return - V_341 ;
return 0 ;
}
static const char *
F_162 ( struct V_1 * V_2 )
{
int type = V_2 -> type ;
if ( type >= F_161 ( V_130 ) )
type = 0 ;
return V_130 [ type ] . V_135 ;
}
void F_163 (
void (* F_164)( int V_2 , struct V_1 * V_20 , unsigned short * V_37 ) )
{
V_351 = F_164 ;
}
static void T_3 F_165 ( void )
{
struct V_19 * V_20 ;
static int V_352 = 1 ;
int V_127 , V_353 = 0 ;
if ( ! V_352 )
return;
V_352 = 0 ;
for ( V_127 = 0 ; V_127 < V_354 ; V_127 ++ ) {
struct V_19 * V_20 = & V_355 [ V_127 ] ;
V_20 -> V_2 . line = V_127 ;
F_104 ( & V_20 -> V_2 . V_58 ) ;
F_166 ( & V_20 -> V_236 ) ;
V_20 -> V_236 . V_280 = F_111 ;
V_20 -> V_256 = ~ V_356 ;
V_20 -> V_257 = V_356 ;
V_20 -> V_2 . V_357 = & V_358 ;
}
if ( V_359 )
V_353 = V_228 ;
for ( V_127 = 0 , V_20 = V_355 ;
V_127 < F_161 ( V_360 ) && V_127 < V_354 ;
V_127 ++ , V_20 ++ ) {
V_20 -> V_2 . V_16 = V_360 [ V_127 ] . V_2 ;
V_20 -> V_2 . V_140 = F_167 ( V_360 [ V_127 ] . V_140 ) ;
V_20 -> V_2 . V_234 = V_360 [ V_127 ] . V_234 ;
V_20 -> V_2 . V_55 = V_360 [ V_127 ] . V_348 * 16 ;
V_20 -> V_2 . V_110 = V_360 [ V_127 ] . V_110 ;
V_20 -> V_2 . V_15 = V_360 [ V_127 ] . V_15 ;
V_20 -> V_2 . V_18 = V_360 [ V_127 ] . V_361 ;
V_20 -> V_2 . V_7 = V_360 [ V_127 ] . V_362 ;
V_20 -> V_2 . V_14 = V_360 [ V_127 ] . V_363 ;
F_22 ( & V_20 -> V_2 ) ;
V_20 -> V_2 . V_234 |= V_353 ;
if ( V_351 != NULL )
V_351 ( V_127 , & V_20 -> V_2 , & V_20 -> V_37 ) ;
}
}
static void
F_168 ( struct V_19 * V_20 , unsigned int type )
{
V_20 -> V_2 . type = type ;
V_20 -> V_2 . V_132 = V_130 [ type ] . V_133 ;
V_20 -> V_37 = V_130 [ type ] . V_110 ;
V_20 -> V_134 = V_130 [ type ] . V_134 ;
}
static void T_3
F_169 ( struct V_364 * V_365 , struct V_366 * V_367 )
{
int V_127 ;
for ( V_127 = 0 ; V_127 < V_354 ; V_127 ++ ) {
struct V_19 * V_20 = & V_355 [ V_127 ] ;
V_20 -> V_26 = 0xFF ;
}
F_165 () ;
for ( V_127 = 0 ; V_127 < V_354 ; V_127 ++ ) {
struct V_19 * V_20 = & V_355 [ V_127 ] ;
V_20 -> V_2 . V_367 = V_367 ;
if ( V_20 -> V_2 . V_110 & V_368 )
F_168 ( V_20 , V_20 -> V_2 . type ) ;
F_170 ( V_365 , & V_20 -> V_2 ) ;
}
}
static void F_171 ( struct V_1 * V_2 , int V_166 )
{
struct V_19 * V_20 =
F_23 ( V_2 , struct V_19 , V_2 ) ;
F_120 ( V_20 , V_154 ) ;
V_23 ( V_20 , V_69 , V_166 ) ;
}
static void
F_172 ( struct V_369 * V_370 , const char * V_371 , unsigned int V_65 )
{
struct V_19 * V_20 = & V_355 [ V_370 -> V_372 ] ;
unsigned long V_110 ;
unsigned int V_146 ;
int V_373 = 1 ;
F_121 () ;
F_173 ( V_110 ) ;
if ( V_20 -> V_2 . V_374 ) {
V_373 = 0 ;
} else if ( V_375 ) {
V_373 = F_174 ( & V_20 -> V_2 . V_58 ) ;
} else
F_78 ( & V_20 -> V_2 . V_58 ) ;
V_146 = V_22 ( V_20 , V_49 ) ;
if ( V_20 -> V_37 & V_108 )
V_23 ( V_20 , V_49 , V_106 ) ;
else
V_23 ( V_20 , V_49 , 0 ) ;
F_175 ( & V_20 -> V_2 , V_371 , V_65 , F_171 ) ;
F_120 ( V_20 , V_241 ) ;
V_23 ( V_20 , V_49 , V_146 ) ;
if ( V_20 -> V_193 )
F_83 ( V_20 ) ;
if ( V_373 )
F_76 ( & V_20 -> V_2 . V_58 ) ;
F_176 ( V_110 ) ;
}
static int T_3 F_177 ( struct V_369 * V_370 , char * V_376 )
{
struct V_1 * V_2 ;
int V_287 = 9600 ;
int V_261 = 8 ;
int V_178 = 'n' ;
int V_377 = 'n' ;
if ( V_370 -> V_372 >= V_354 )
V_370 -> V_372 = 0 ;
V_2 = & V_355 [ V_370 -> V_372 ] . V_2 ;
if ( ! V_2 -> V_16 && ! V_2 -> V_18 )
return - V_270 ;
if ( V_376 )
F_178 ( V_376 , & V_287 , & V_178 , & V_261 , & V_377 ) ;
return F_179 ( V_2 , V_370 , V_287 , V_178 , V_261 , V_377 ) ;
}
static int F_180 ( void )
{
return F_181 () ;
}
static int T_3 F_182 ( void )
{
if ( V_354 > V_378 )
V_354 = V_378 ;
F_165 () ;
F_183 ( & V_379 ) ;
return 0 ;
}
int F_184 ( struct V_1 * V_5 )
{
int line ;
struct V_1 * V_2 ;
for ( line = 0 ; line < V_354 ; line ++ ) {
V_2 = & V_355 [ line ] . V_2 ;
if ( F_185 ( V_5 , V_2 ) )
return line ;
}
return - V_270 ;
}
int T_3 F_186 ( struct V_1 * V_2 )
{
struct V_1 * V_5 ;
if ( V_2 -> line >= F_161 ( V_355 ) )
return - V_270 ;
F_165 () ;
V_5 = & V_355 [ V_2 -> line ] . V_2 ;
V_5 -> V_16 = V_2 -> V_16 ;
V_5 -> V_18 = V_2 -> V_18 ;
V_5 -> V_140 = V_2 -> V_140 ;
V_5 -> V_234 = V_2 -> V_234 ;
V_5 -> V_55 = V_2 -> V_55 ;
V_5 -> V_132 = V_2 -> V_132 ;
V_5 -> V_14 = V_2 -> V_14 ;
V_5 -> V_7 = V_2 -> V_7 ;
V_5 -> V_110 = V_2 -> V_110 ;
V_5 -> V_119 = V_2 -> V_119 ;
V_5 -> V_380 = V_2 -> V_380 ;
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
void F_187 ( int line )
{
F_188 ( & V_3 , & V_355 [ line ] . V_2 ) ;
}
void F_189 ( int line )
{
struct V_19 * V_20 = & V_355 [ line ] ;
if ( V_20 -> V_37 & V_101 ) {
F_28 ( V_20 , V_29 , 0xE0 ) ;
F_47 ( V_20 ) ;
F_28 ( V_20 , V_29 , 0 ) ;
V_20 -> V_2 . V_55 = 921600 * 16 ;
}
F_190 ( & V_3 , & V_20 -> V_2 ) ;
}
static int T_4 F_191 ( struct V_381 * V_367 )
{
struct V_382 * V_5 = V_367 -> V_367 . V_383 ;
struct V_1 V_2 ;
int V_225 , V_127 , V_353 = 0 ;
memset ( & V_2 , 0 , sizeof( struct V_1 ) ) ;
if ( V_359 )
V_353 = V_228 ;
for ( V_127 = 0 ; V_5 && V_5 -> V_110 != 0 ; V_5 ++ , V_127 ++ ) {
V_2 . V_16 = V_5 -> V_16 ;
V_2 . V_18 = V_5 -> V_18 ;
V_2 . V_140 = V_5 -> V_140 ;
V_2 . V_234 = V_5 -> V_234 ;
V_2 . V_55 = V_5 -> V_55 ;
V_2 . V_14 = V_5 -> V_14 ;
V_2 . V_7 = V_5 -> V_7 ;
V_2 . V_110 = V_5 -> V_110 ;
V_2 . V_119 = V_5 -> V_119 ;
V_2 . V_15 = V_5 -> V_15 ;
V_2 . V_380 = V_5 -> V_380 ;
V_2 . type = V_5 -> type ;
V_2 . V_22 = V_5 -> V_22 ;
V_2 . V_23 = V_5 -> V_23 ;
V_2 . V_27 = V_5 -> V_27 ;
V_2 . V_327 = V_5 -> V_327 ;
V_2 . V_332 = V_5 -> V_332 ;
V_2 . V_367 = & V_367 -> V_367 ;
V_2 . V_234 |= V_353 ;
V_225 = F_192 ( & V_2 ) ;
if ( V_225 < 0 ) {
F_193 ( & V_367 -> V_367 , L_26
L_27 , V_127 ,
V_5 -> V_16 , ( unsigned long long ) V_5 -> V_119 ,
V_5 -> V_140 , V_225 ) ;
}
}
return 0 ;
}
static int T_5 F_194 ( struct V_381 * V_367 )
{
int V_127 ;
for ( V_127 = 0 ; V_127 < V_354 ; V_127 ++ ) {
struct V_19 * V_20 = & V_355 [ V_127 ] ;
if ( V_20 -> V_2 . V_367 == & V_367 -> V_367 )
F_195 ( V_127 ) ;
}
return 0 ;
}
static int F_196 ( struct V_381 * V_367 , T_6 V_165 )
{
int V_127 ;
for ( V_127 = 0 ; V_127 < V_378 ; V_127 ++ ) {
struct V_19 * V_20 = & V_355 [ V_127 ] ;
if ( V_20 -> V_2 . type != V_124 && V_20 -> V_2 . V_367 == & V_367 -> V_367 )
F_188 ( & V_3 , & V_20 -> V_2 ) ;
}
return 0 ;
}
static int F_197 ( struct V_381 * V_367 )
{
int V_127 ;
for ( V_127 = 0 ; V_127 < V_378 ; V_127 ++ ) {
struct V_19 * V_20 = & V_355 [ V_127 ] ;
if ( V_20 -> V_2 . type != V_124 && V_20 -> V_2 . V_367 == & V_367 -> V_367 )
F_189 ( V_127 ) ;
}
return 0 ;
}
static struct V_19 * F_198 ( struct V_1 * V_2 )
{
int V_127 ;
for ( V_127 = 0 ; V_127 < V_354 ; V_127 ++ )
if ( F_185 ( & V_355 [ V_127 ] . V_2 , V_2 ) )
return & V_355 [ V_127 ] ;
for ( V_127 = 0 ; V_127 < V_354 ; V_127 ++ )
if ( V_355 [ V_127 ] . V_2 . type == V_124 &&
V_355 [ V_127 ] . V_2 . V_16 == 0 )
return & V_355 [ V_127 ] ;
for ( V_127 = 0 ; V_127 < V_354 ; V_127 ++ )
if ( V_355 [ V_127 ] . V_2 . type == V_124 )
return & V_355 [ V_127 ] ;
return NULL ;
}
int F_192 ( struct V_1 * V_2 )
{
struct V_19 * V_384 ;
int V_225 = - V_385 ;
if ( V_2 -> V_55 == 0 )
return - V_341 ;
F_99 ( & V_386 ) ;
V_384 = F_198 ( V_2 ) ;
if ( V_384 ) {
F_199 ( & V_3 , & V_384 -> V_2 ) ;
V_384 -> V_2 . V_16 = V_2 -> V_16 ;
V_384 -> V_2 . V_18 = V_2 -> V_18 ;
V_384 -> V_2 . V_140 = V_2 -> V_140 ;
V_384 -> V_2 . V_234 = V_2 -> V_234 ;
V_384 -> V_2 . V_55 = V_2 -> V_55 ;
V_384 -> V_2 . V_132 = V_2 -> V_132 ;
V_384 -> V_2 . V_14 = V_2 -> V_14 ;
V_384 -> V_2 . V_7 = V_2 -> V_7 ;
V_384 -> V_2 . V_110 = V_2 -> V_110 | V_387 ;
V_384 -> V_2 . V_119 = V_2 -> V_119 ;
V_384 -> V_2 . V_380 = V_2 -> V_380 ;
if ( V_2 -> V_367 )
V_384 -> V_2 . V_367 = V_2 -> V_367 ;
if ( V_2 -> V_110 & V_368 )
F_168 ( V_384 , V_2 -> type ) ;
F_22 ( & V_384 -> V_2 ) ;
if ( V_2 -> V_22 )
V_384 -> V_2 . V_22 = V_2 -> V_22 ;
if ( V_2 -> V_23 )
V_384 -> V_2 . V_23 = V_2 -> V_23 ;
if ( V_2 -> V_27 )
V_384 -> V_2 . V_27 = V_2 -> V_27 ;
if ( V_2 -> V_327 )
V_384 -> V_2 . V_327 = V_2 -> V_327 ;
if ( V_2 -> V_332 )
V_384 -> V_2 . V_332 = V_2 -> V_332 ;
if ( V_351 != NULL )
V_351 ( 0 , & V_384 -> V_2 ,
& V_384 -> V_37 ) ;
V_225 = F_170 ( & V_3 , & V_384 -> V_2 ) ;
if ( V_225 == 0 )
V_225 = V_384 -> V_2 . line ;
}
F_103 ( & V_386 ) ;
return V_225 ;
}
void F_195 ( int line )
{
struct V_19 * V_384 = & V_355 [ line ] ;
F_99 ( & V_386 ) ;
F_199 ( & V_3 , & V_384 -> V_2 ) ;
if ( V_388 ) {
V_384 -> V_2 . V_110 &= ~ V_387 ;
V_384 -> V_2 . type = V_124 ;
V_384 -> V_2 . V_367 = & V_388 -> V_367 ;
V_384 -> V_37 = V_130 [ V_384 -> V_2 . type ] . V_110 ;
F_170 ( & V_3 , & V_384 -> V_2 ) ;
} else {
V_384 -> V_2 . V_367 = NULL ;
}
F_103 ( & V_386 ) ;
}
static int T_3 F_200 ( void )
{
int V_225 ;
if ( V_354 > V_378 )
V_354 = V_378 ;
F_54 ( V_269 L_28
L_29 , V_354 ,
V_359 ? L_30 : L_31 ) ;
#ifdef F_201
V_225 = F_202 ( & V_3 , V_378 ) ;
#else
V_3 . V_389 = V_378 ;
V_225 = F_203 ( & V_3 ) ;
#endif
if ( V_225 )
goto V_121;
V_388 = F_204 ( L_32 ,
V_390 ) ;
if ( ! V_388 ) {
V_225 = - V_233 ;
goto V_391;
}
V_225 = F_205 ( V_388 ) ;
if ( V_225 )
goto V_392;
F_169 ( & V_3 , & V_388 -> V_367 ) ;
V_225 = F_206 ( & V_393 ) ;
if ( V_225 == 0 )
goto V_121;
F_207 ( V_388 ) ;
V_392:
F_208 ( V_388 ) ;
V_391:
#ifdef F_201
F_209 ( & V_3 , V_378 ) ;
#else
F_210 ( & V_3 ) ;
#endif
V_121:
return V_225 ;
}
static void T_7 F_211 ( void )
{
struct V_381 * V_394 = V_388 ;
V_388 = NULL ;
F_212 ( & V_393 ) ;
F_213 ( V_394 ) ;
#ifdef F_201
F_209 ( & V_3 , V_378 ) ;
#else
F_210 ( & V_3 ) ;
#endif
}
