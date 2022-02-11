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
unsigned int V_19 ;
V_6 = F_2 ( V_5 , V_6 ) << V_5 -> V_14 ;
if ( V_6 == V_20 ) {
V_19 = F_15 ( V_5 -> V_18 + ( V_20 & ~ 3 ) ) ;
return ( V_19 >> 16 ) & 0xff ;
} else
return F_9 ( V_5 -> V_18 + V_6 ) ;
}
static void F_21 ( struct V_1 * V_5 , int V_6 , int V_17 )
{
V_6 = F_3 ( V_5 , V_6 ) << V_5 -> V_14 ;
if ( ! ( ( V_6 == V_21 ) && ( V_17 & V_22 ) ) )
F_11 ( V_17 , V_5 -> V_18 + V_6 ) ;
}
static inline void F_22 ( struct V_1 * V_5 , int V_6 ,
int V_17 )
{
struct V_23 * V_24 =
F_23 ( V_5 , struct V_23 , V_2 ) ;
if ( V_6 == V_25 )
V_24 -> V_26 = V_17 ;
}
static inline void F_24 ( struct V_1 * V_5 , int V_6 )
{
if ( V_6 == V_27 || V_6 == V_21 )
V_5 -> V_28 ( V_5 , V_21 ) ;
}
static void F_25 ( struct V_1 * V_5 , int V_6 , int V_17 )
{
int V_29 = V_6 ;
V_6 = F_3 ( V_5 , V_6 ) << V_5 -> V_14 ;
F_22 ( V_5 , V_29 , V_17 ) ;
F_11 ( V_17 , V_5 -> V_18 + V_6 ) ;
F_24 ( V_5 , V_29 ) ;
}
static void F_26 ( struct V_1 * V_5 , int V_6 , int V_17 )
{
int V_29 = V_6 ;
V_6 = F_3 ( V_5 , V_6 ) << V_5 -> V_14 ;
F_22 ( V_5 , V_29 , V_17 ) ;
F_13 ( V_17 , V_5 -> V_18 + V_6 ) ;
F_24 ( V_5 , V_29 ) ;
}
static unsigned int F_27 ( struct V_1 * V_5 , int V_6 )
{
V_6 = F_2 ( V_5 , V_6 ) << V_5 -> V_14 ;
return F_6 ( V_5 -> V_16 + V_6 ) ;
}
static void F_28 ( struct V_1 * V_5 , int V_6 , int V_17 )
{
V_6 = F_3 ( V_5 , V_6 ) << V_5 -> V_14 ;
F_5 ( V_17 , V_5 -> V_16 + V_6 ) ;
}
static void F_29 ( struct V_1 * V_5 )
{
struct V_23 * V_24 =
F_23 ( V_5 , struct V_23 , V_2 ) ;
switch ( V_5 -> V_7 ) {
case V_30 :
V_5 -> V_28 = F_4 ;
V_5 -> V_31 = F_7 ;
break;
case V_32 :
V_5 -> V_28 = F_8 ;
V_5 -> V_31 = F_10 ;
break;
case V_11 :
case V_33 :
V_5 -> V_28 = F_14 ;
V_5 -> V_31 = F_12 ;
break;
case V_8 :
V_5 -> V_28 = F_16 ;
V_5 -> V_31 = F_18 ;
break;
case V_34 :
V_5 -> V_28 = F_20 ;
V_5 -> V_31 = F_21 ;
break;
case V_35 :
V_5 -> V_28 = F_8 ;
V_5 -> V_31 = F_25 ;
break;
case V_36 :
V_5 -> V_28 = F_14 ;
V_5 -> V_31 = F_26 ;
break;
default:
V_5 -> V_28 = F_27 ;
V_5 -> V_31 = F_28 ;
break;
}
V_24 -> V_37 = V_5 -> V_7 ;
}
static void
F_30 ( struct V_23 * V_24 , int V_6 , int V_17 )
{
struct V_1 * V_5 = & V_24 -> V_2 ;
switch ( V_5 -> V_7 ) {
case V_32 :
case V_33 :
case V_8 :
case V_35 :
case V_36 :
V_5 -> V_31 ( V_5 , V_6 , V_17 ) ;
V_5 -> V_28 ( V_5 , V_25 ) ;
break;
default:
V_5 -> V_31 ( V_5 , V_6 , V_17 ) ;
}
}
static inline int F_31 ( struct V_23 * V_24 )
{
return F_32 ( V_24 , V_38 ) | F_32 ( V_24 , V_39 ) << 8 ;
}
static inline void F_33 ( struct V_23 * V_24 , int V_17 )
{
F_34 ( V_24 , V_38 , V_17 & 0xff ) ;
F_34 ( V_24 , V_39 , V_17 >> 8 & 0xff ) ;
}
static int F_35 ( struct V_23 * V_24 )
{
if ( V_24 -> V_2 . V_7 == V_8 )
return F_17 ( V_24 -> V_2 . V_18 + 0x28 ) ;
else
return F_31 ( V_24 ) ;
}
static void F_36 ( struct V_23 * V_24 , int V_17 )
{
if ( V_24 -> V_2 . V_7 == V_8 )
F_19 ( V_17 , V_24 -> V_2 . V_18 + 0x28 ) ;
else
F_33 ( V_24 , V_17 ) ;
}
static int F_35 ( struct V_23 * V_24 )
{
return ( V_24 -> V_2 . V_7 == V_11 ) ?
( ( ( F_17 ( V_24 -> V_2 . V_18 + 0x10 ) << 8 ) |
( F_17 ( V_24 -> V_2 . V_18 + 0x08 ) & 0xff ) ) & 0xffff ) :
F_31 ( V_24 ) ;
}
static void F_36 ( struct V_23 * V_24 , int V_17 )
{
if ( V_24 -> V_2 . V_7 == V_11 ) {
F_19 ( V_17 , V_24 -> V_2 . V_18 + 0x08 ) ;
F_19 ( V_17 >> 8 , V_24 -> V_2 . V_18 + 0x10 ) ;
} else {
F_33 ( V_24 , V_17 ) ;
}
}
static void F_37 ( struct V_23 * V_24 , int V_6 , int V_17 )
{
V_31 ( V_24 , V_40 , V_6 ) ;
V_31 ( V_24 , V_41 , V_17 ) ;
}
static unsigned int F_38 ( struct V_23 * V_24 , int V_6 )
{
unsigned int V_17 ;
F_37 ( V_24 , V_42 , V_24 -> V_43 | V_44 ) ;
V_31 ( V_24 , V_40 , V_6 ) ;
V_17 = V_28 ( V_24 , V_41 ) ;
F_37 ( V_24 , V_42 , V_24 -> V_43 ) ;
return V_17 ;
}
static void F_39 ( struct V_23 * V_5 )
{
if ( V_5 -> V_45 & V_46 ) {
F_34 ( V_5 , V_47 , V_48 ) ;
F_34 ( V_5 , V_47 , V_48 |
V_49 | V_50 ) ;
F_34 ( V_5 , V_47 , 0 ) ;
}
}
static void F_40 ( struct V_23 * V_5 , int V_51 )
{
if ( V_5 -> V_45 & V_52 ) {
if ( V_5 -> V_45 & V_53 ) {
F_34 ( V_5 , V_25 , V_54 ) ;
F_34 ( V_5 , V_55 , V_56 ) ;
F_34 ( V_5 , V_25 , 0 ) ;
}
F_34 ( V_5 , V_21 , V_51 ? V_57 : 0 ) ;
if ( V_5 -> V_45 & V_53 ) {
F_34 ( V_5 , V_25 , V_54 ) ;
F_34 ( V_5 , V_55 , 0 ) ;
F_34 ( V_5 , V_25 , 0 ) ;
}
}
}
static int F_41 ( struct V_23 * V_24 )
{
unsigned char V_58 ;
int V_59 ;
V_58 = F_32 ( V_24 , V_60 ) ;
V_59 = V_58 & V_61 ;
if ( ! V_59 ) {
F_34 ( V_24 , V_60 , V_58 | V_61 ) ;
V_58 = F_32 ( V_24 , V_60 ) ;
V_59 = V_58 & V_61 ;
}
if ( V_59 )
V_24 -> V_2 . V_62 = V_63 * 16 ;
return V_59 ;
}
static void F_42 ( struct V_23 * V_24 )
{
if ( V_24 -> V_2 . type == V_64 ) {
if ( V_24 -> V_2 . V_62 != V_63 * 16 ) {
F_43 ( & V_24 -> V_2 . V_65 ) ;
F_41 ( V_24 ) ;
F_44 ( & V_24 -> V_2 . V_65 ) ;
}
if ( V_24 -> V_2 . V_62 == V_63 * 16 )
F_34 ( V_24 , V_66 , 0 ) ;
}
}
static void F_45 ( struct V_23 * V_24 )
{
unsigned char V_58 ;
int V_59 ;
if ( V_24 -> V_2 . type == V_64 &&
V_24 -> V_2 . V_62 == V_63 * 16 ) {
F_43 ( & V_24 -> V_2 . V_65 ) ;
V_58 = F_32 ( V_24 , V_60 ) ;
V_59 = ! ( V_58 & V_61 ) ;
if ( ! V_59 ) {
F_34 ( V_24 , V_60 , V_58 & ~ V_61 ) ;
V_58 = F_32 ( V_24 , V_60 ) ;
V_59 = ! ( V_58 & V_61 ) ;
}
if ( V_59 )
V_24 -> V_2 . V_62 = V_67 * 16 ;
F_44 ( & V_24 -> V_2 . V_65 ) ;
}
}
static int F_46 ( struct V_23 * V_24 )
{
unsigned char V_68 , V_69 , V_70 ;
unsigned short V_71 ;
int V_72 ;
V_70 = F_32 ( V_24 , V_25 ) ;
F_34 ( V_24 , V_25 , 0 ) ;
V_68 = F_32 ( V_24 , V_47 ) ;
V_69 = F_32 ( V_24 , V_73 ) ;
F_34 ( V_24 , V_47 , V_48 |
V_49 | V_50 ) ;
F_34 ( V_24 , V_73 , V_74 ) ;
F_34 ( V_24 , V_25 , V_75 ) ;
V_71 = F_35 ( V_24 ) ;
F_36 ( V_24 , 0x0001 ) ;
F_34 ( V_24 , V_25 , 0x03 ) ;
for ( V_72 = 0 ; V_72 < 256 ; V_72 ++ )
F_34 ( V_24 , V_27 , V_72 ) ;
F_47 ( 20 ) ;
for ( V_72 = 0 ; ( F_32 ( V_24 , V_76 ) & V_77 ) &&
( V_72 < 256 ) ; V_72 ++ )
F_32 ( V_24 , V_78 ) ;
F_34 ( V_24 , V_47 , V_68 ) ;
F_34 ( V_24 , V_73 , V_69 ) ;
F_34 ( V_24 , V_25 , V_75 ) ;
F_36 ( V_24 , V_71 ) ;
F_34 ( V_24 , V_25 , V_70 ) ;
return V_72 ;
}
static unsigned int F_48 ( struct V_23 * V_5 )
{
unsigned char V_79 , V_80 , V_70 ;
unsigned int V_81 ;
V_70 = F_32 ( V_5 , V_25 ) ;
F_34 ( V_5 , V_25 , V_75 ) ;
V_79 = F_32 ( V_5 , V_38 ) ;
V_80 = F_32 ( V_5 , V_39 ) ;
F_34 ( V_5 , V_38 , 0 ) ;
F_34 ( V_5 , V_39 , 0 ) ;
V_81 = F_32 ( V_5 , V_38 ) | F_32 ( V_5 , V_39 ) << 8 ;
F_34 ( V_5 , V_38 , V_79 ) ;
F_34 ( V_5 , V_39 , V_80 ) ;
F_34 ( V_5 , V_25 , V_70 ) ;
return V_81 ;
}
static void F_49 ( struct V_23 * V_24 )
{
unsigned int V_82 , V_83 , V_84 , V_85 ;
V_24 -> V_45 |= V_53 | V_52 ;
V_24 -> V_43 = 0 ;
V_31 ( V_24 , V_25 , V_54 ) ;
V_31 ( V_24 , V_55 , V_56 ) ;
V_31 ( V_24 , V_25 , 0x00 ) ;
V_82 = F_38 ( V_24 , V_86 ) ;
V_83 = F_38 ( V_24 , V_87 ) ;
V_84 = F_38 ( V_24 , V_88 ) ;
V_85 = F_38 ( V_24 , V_89 ) ;
F_50 ( L_1 , V_82 , V_83 , V_84 , V_85 ) ;
if ( V_82 == 0x16 && V_83 == 0xC9 &&
( V_84 == 0x50 || V_84 == 0x52 || V_84 == 0x54 ) ) {
V_24 -> V_2 . type = V_90 ;
if ( V_84 == 0x52 && V_85 == 0x01 )
V_24 -> V_91 |= V_92 ;
return;
}
V_82 = F_48 ( V_24 ) ;
F_50 ( L_2 , V_82 ) ;
V_83 = V_82 >> 8 ;
if ( V_83 == 0x10 || V_83 == 0x12 || V_83 == 0x14 ) {
V_24 -> V_2 . type = V_93 ;
return;
}
if ( F_46 ( V_24 ) == 64 )
V_24 -> V_2 . type = V_94 ;
else
V_24 -> V_2 . type = V_95 ;
}
static void F_51 ( struct V_23 * V_24 )
{
unsigned char V_96 , V_97 , V_98 ;
V_24 -> V_2 . type = V_99 ;
V_96 = V_28 ( V_24 , V_40 ) ;
F_34 ( V_24 , V_40 , 0xa5 ) ;
V_97 = V_28 ( V_24 , V_40 ) ;
F_34 ( V_24 , V_40 , 0x5a ) ;
V_98 = V_28 ( V_24 , V_40 ) ;
F_34 ( V_24 , V_40 , V_96 ) ;
if ( V_97 == 0xa5 && V_98 == 0x5a )
V_24 -> V_2 . type = V_100 ;
}
static int F_52 ( struct V_23 * V_24 )
{
if ( F_48 ( V_24 ) == 0x0201 && F_46 ( V_24 ) == 16 )
return 1 ;
return 0 ;
}
static inline int F_53 ( struct V_23 * V_24 )
{
unsigned char V_101 ;
V_101 = V_28 ( V_24 , 0x04 ) ;
#define F_54 ( T_1 ) ((x) & 0x30)
if ( F_54 ( V_101 ) == 0x10 ) {
return 0 ;
} else {
V_101 &= ~ 0xB0 ;
V_101 |= 0x10 ;
F_34 ( V_24 , 0x04 , V_101 ) ;
}
return 1 ;
}
static void F_55 ( struct V_23 * V_24 )
{
unsigned char V_97 , V_98 ;
unsigned int V_102 ;
V_24 -> V_2 . type = V_103 ;
V_24 -> V_45 |= V_46 ;
F_34 ( V_24 , V_25 , V_75 ) ;
if ( V_28 ( V_24 , V_55 ) == 0 ) {
F_34 ( V_24 , V_55 , 0xA8 ) ;
if ( V_28 ( V_24 , V_55 ) != 0 ) {
F_50 ( L_3 ) ;
V_24 -> V_2 . type = V_104 ;
V_24 -> V_45 |= V_53 | V_52 ;
} else {
F_50 ( L_4 ) ;
}
F_34 ( V_24 , V_55 , 0 ) ;
return;
}
F_34 ( V_24 , V_25 , V_54 ) ;
if ( V_28 ( V_24 , V_55 ) == 0 && ! F_52 ( V_24 ) ) {
F_50 ( L_5 ) ;
F_49 ( V_24 ) ;
return;
}
F_34 ( V_24 , V_25 , 0 ) ;
V_97 = V_28 ( V_24 , V_73 ) ;
F_34 ( V_24 , V_25 , 0xE0 ) ;
V_98 = V_28 ( V_24 , 0x02 ) ;
if ( ! ( ( V_98 ^ V_97 ) & V_74 ) ) {
F_34 ( V_24 , V_25 , 0 ) ;
F_34 ( V_24 , V_73 , V_97 ^ V_74 ) ;
F_34 ( V_24 , V_25 , 0xE0 ) ;
V_98 = V_28 ( V_24 , 0x02 ) ;
F_34 ( V_24 , V_25 , 0 ) ;
F_34 ( V_24 , V_73 , V_97 ) ;
if ( ( V_98 ^ V_97 ) & V_74 ) {
unsigned short V_105 ;
F_34 ( V_24 , V_25 , 0xE0 ) ;
V_105 = F_35 ( V_24 ) ;
V_105 <<= 3 ;
if ( F_53 ( V_24 ) )
F_36 ( V_24 , V_105 ) ;
F_34 ( V_24 , V_25 , 0 ) ;
V_24 -> V_2 . V_62 = 921600 * 16 ;
V_24 -> V_2 . type = V_106 ;
V_24 -> V_45 |= V_107 ;
return;
}
}
F_34 ( V_24 , V_25 , 0 ) ;
F_34 ( V_24 , V_47 , V_48 | V_108 ) ;
V_97 = V_28 ( V_24 , V_20 ) >> 5 ;
F_34 ( V_24 , V_47 , V_48 ) ;
F_34 ( V_24 , V_25 , V_75 ) ;
F_34 ( V_24 , V_47 , V_48 | V_108 ) ;
V_98 = V_28 ( V_24 , V_20 ) >> 5 ;
F_34 ( V_24 , V_47 , V_48 ) ;
F_34 ( V_24 , V_25 , 0 ) ;
F_50 ( L_6 , V_97 , V_98 ) ;
if ( V_97 == 6 && V_98 == 7 ) {
V_24 -> V_2 . type = V_109 ;
V_24 -> V_45 |= V_110 | V_52 ;
return;
}
V_102 = V_28 ( V_24 , V_21 ) ;
F_34 ( V_24 , V_21 , V_102 & ~ V_22 ) ;
if ( ! ( V_28 ( V_24 , V_21 ) & V_22 ) ) {
F_34 ( V_24 , V_21 , V_102 | V_22 ) ;
if ( V_28 ( V_24 , V_21 ) & V_22 ) {
F_50 ( L_7 ) ;
V_24 -> V_2 . type = V_111 ;
V_24 -> V_45 |= V_112 | V_113 ;
return;
}
} else {
F_50 ( L_8 ) ;
}
F_34 ( V_24 , V_21 , V_102 ) ;
if ( V_24 -> V_2 . type == V_103 && F_46 ( V_24 ) == 64 ) {
V_24 -> V_2 . type = V_114 ;
V_24 -> V_45 |= V_110 ;
}
}
static void F_56 ( struct V_23 * V_24 , unsigned int V_115 )
{
unsigned char V_97 , V_96 , V_116 , V_117 ;
unsigned char V_118 , V_119 ;
unsigned long V_120 ;
if ( ! V_24 -> V_2 . V_16 && ! V_24 -> V_2 . V_121 && ! V_24 -> V_2 . V_18 )
return;
F_50 ( L_9 ,
F_1 ( & V_24 -> V_2 ) , V_24 -> V_2 . V_16 , V_24 -> V_2 . V_18 ) ;
F_57 ( & V_24 -> V_2 . V_65 , V_120 ) ;
V_24 -> V_45 = 0 ;
V_24 -> V_91 = 0 ;
if ( ! ( V_24 -> V_2 . V_120 & V_122 ) ) {
V_96 = F_32 ( V_24 , V_21 ) ;
F_34 ( V_24 , V_21 , 0 ) ;
#ifdef F_58
F_5 ( 0xff , 0x080 ) ;
#endif
V_116 = F_32 ( V_24 , V_21 ) & 0x0f ;
F_34 ( V_24 , V_21 , 0x0F ) ;
#ifdef F_58
F_5 ( 0 , 0x080 ) ;
#endif
V_117 = F_32 ( V_24 , V_21 ) & 0x0f ;
F_34 ( V_24 , V_21 , V_96 ) ;
if ( V_116 != 0 || V_117 != 0x0F ) {
F_50 ( L_10 ,
V_116 , V_117 ) ;
goto V_123;
}
}
V_119 = V_28 ( V_24 , V_73 ) ;
V_118 = V_28 ( V_24 , V_25 ) ;
if ( ! ( V_24 -> V_2 . V_120 & V_124 ) ) {
F_34 ( V_24 , V_73 , V_74 | 0x0A ) ;
V_97 = F_32 ( V_24 , V_125 ) & 0xF0 ;
F_34 ( V_24 , V_73 , V_119 ) ;
if ( V_97 != 0x90 ) {
F_50 ( L_11 ,
V_97 ) ;
goto V_123;
}
}
F_34 ( V_24 , V_25 , V_54 ) ;
F_34 ( V_24 , V_55 , 0 ) ;
F_34 ( V_24 , V_25 , 0 ) ;
F_34 ( V_24 , V_47 , V_48 ) ;
V_96 = V_28 ( V_24 , V_20 ) >> 6 ;
F_50 ( L_12 , V_96 ) ;
switch ( V_96 ) {
case 0 :
F_51 ( V_24 ) ;
break;
case 1 :
V_24 -> V_2 . type = V_126 ;
break;
case 2 :
V_24 -> V_2 . type = V_127 ;
break;
case 3 :
F_55 ( V_24 ) ;
break;
}
#ifdef F_59
if ( V_24 -> V_2 . type == V_103 && V_115 & V_128 ) {
int V_129 ;
for ( V_129 = 0 ; V_129 < V_130 ; ++ V_129 ) {
if ( V_131 [ V_129 ] == V_24 -> V_2 . V_16 &&
F_41 ( V_24 ) ) {
V_24 -> V_2 . type = V_64 ;
break;
}
}
}
#endif
F_34 ( V_24 , V_25 , V_118 ) ;
if ( V_24 -> V_45 != V_132 [ V_24 -> V_2 . type ] . V_120 ) {
F_60 ( V_133
L_13 ,
F_1 ( & V_24 -> V_2 ) , V_24 -> V_45 ,
V_132 [ V_24 -> V_2 . type ] . V_120 ) ;
}
V_24 -> V_2 . V_134 = V_132 [ V_24 -> V_2 . type ] . V_135 ;
V_24 -> V_45 = V_132 [ V_24 -> V_2 . type ] . V_120 ;
V_24 -> V_136 = V_132 [ V_24 -> V_2 . type ] . V_136 ;
if ( V_24 -> V_2 . type == V_126 )
goto V_123;
#ifdef F_59
if ( V_24 -> V_2 . type == V_64 )
F_34 ( V_24 , V_66 , 0 ) ;
#endif
F_34 ( V_24 , V_73 , V_119 ) ;
F_39 ( V_24 ) ;
V_28 ( V_24 , V_78 ) ;
if ( V_24 -> V_45 & V_112 )
F_34 ( V_24 , V_21 , V_22 ) ;
else
F_34 ( V_24 , V_21 , 0 ) ;
V_123:
F_61 ( & V_24 -> V_2 . V_65 , V_120 ) ;
F_50 ( L_14 , V_132 [ V_24 -> V_2 . type ] . V_137 ) ;
}
static void F_62 ( struct V_23 * V_24 )
{
unsigned char V_119 , V_138 ;
unsigned char V_139 = 0 ;
unsigned int V_140 = 0 ;
unsigned long V_141 ;
int V_142 ;
if ( V_24 -> V_2 . V_120 & V_143 ) {
V_140 = ( V_24 -> V_2 . V_16 & 0xfe0 ) | 0x1f ;
V_139 = F_63 ( V_140 ) ;
F_64 ( 0x80 , V_140 ) ;
( void ) F_63 ( V_140 ) ;
}
F_65 ( F_66 () ) ;
V_119 = F_32 ( V_24 , V_73 ) ;
V_138 = F_32 ( V_24 , V_21 ) ;
F_34 ( V_24 , V_73 , V_144 | V_145 ) ;
V_141 = F_66 () ;
F_34 ( V_24 , V_73 , 0 ) ;
F_67 ( 10 ) ;
if ( V_24 -> V_2 . V_120 & V_143 ) {
F_34 ( V_24 , V_73 ,
V_146 | V_147 ) ;
} else {
F_34 ( V_24 , V_73 ,
V_146 | V_147 | V_145 ) ;
}
F_34 ( V_24 , V_21 , 0x0f ) ;
( void ) F_32 ( V_24 , V_76 ) ;
( void ) F_32 ( V_24 , V_78 ) ;
( void ) F_32 ( V_24 , V_20 ) ;
( void ) F_32 ( V_24 , V_125 ) ;
F_34 ( V_24 , V_27 , 0xFF ) ;
F_67 ( 20 ) ;
V_142 = F_65 ( V_141 ) ;
F_34 ( V_24 , V_73 , V_119 ) ;
F_34 ( V_24 , V_21 , V_138 ) ;
if ( V_24 -> V_2 . V_120 & V_143 )
F_64 ( V_139 , V_140 ) ;
V_24 -> V_2 . V_142 = ( V_142 > 0 ) ? V_142 : 0 ;
}
static inline void F_68 ( struct V_23 * V_5 )
{
if ( V_5 -> V_148 & V_149 ) {
V_5 -> V_148 &= ~ V_149 ;
V_31 ( V_5 , V_21 , V_5 -> V_148 ) ;
}
}
static void F_69 ( struct V_1 * V_2 )
{
struct V_23 * V_24 =
F_23 ( V_2 , struct V_23 , V_2 ) ;
F_68 ( V_24 ) ;
if ( V_24 -> V_2 . type == V_90 ) {
V_24 -> V_43 |= V_150 ;
F_37 ( V_24 , V_42 , V_24 -> V_43 ) ;
}
}
static void F_70 ( struct V_1 * V_2 )
{
struct V_23 * V_24 =
F_23 ( V_2 , struct V_23 , V_2 ) ;
if ( ! ( V_24 -> V_148 & V_149 ) ) {
V_24 -> V_148 |= V_149 ;
V_31 ( V_24 , V_21 , V_24 -> V_148 ) ;
if ( V_24 -> V_91 & V_151 ) {
unsigned char V_152 ;
V_152 = V_28 ( V_24 , V_76 ) ;
V_24 -> V_153 |= V_152 & V_154 ;
if ( ( V_24 -> V_2 . type == V_155 ) ?
( V_152 & V_156 ) :
( V_152 & V_157 ) )
F_71 ( V_24 ) ;
}
}
if ( V_24 -> V_2 . type == V_90 && V_24 -> V_43 & V_150 ) {
V_24 -> V_43 &= ~ V_150 ;
F_37 ( V_24 , V_42 , V_24 -> V_43 ) ;
}
}
static void F_72 ( struct V_1 * V_2 )
{
struct V_23 * V_24 =
F_23 ( V_2 , struct V_23 , V_2 ) ;
V_24 -> V_148 &= ~ V_158 ;
V_24 -> V_2 . V_159 &= ~ V_77 ;
V_31 ( V_24 , V_21 , V_24 -> V_148 ) ;
}
static void F_73 ( struct V_1 * V_2 )
{
struct V_23 * V_24 =
F_23 ( V_2 , struct V_23 , V_2 ) ;
if ( V_24 -> V_91 & V_160 )
return;
V_24 -> V_148 |= V_161 ;
V_31 ( V_24 , V_21 , V_24 -> V_148 ) ;
}
static void F_74 ( struct V_23 * V_24 )
{
unsigned int V_101 , V_162 = 10000 ;
do {
V_101 = V_28 ( V_24 , V_76 ) ;
if ( V_101 & ( V_163 | V_164 ) )
V_101 = V_28 ( V_24 , V_78 ) ;
else
break;
if ( -- V_162 == 0 )
break;
F_67 ( 1 ) ;
} while ( 1 );
}
static void
F_75 ( struct V_23 * V_24 , unsigned int * V_101 )
{
struct V_165 * V_166 = V_24 -> V_2 . V_167 -> V_2 . V_166 ;
unsigned char V_168 , V_152 = * V_101 ;
int V_169 = 256 ;
char V_170 ;
do {
if ( F_76 ( V_152 & V_77 ) )
V_168 = F_32 ( V_24 , V_78 ) ;
else
V_168 = 0 ;
V_170 = V_171 ;
V_24 -> V_2 . V_172 . V_173 ++ ;
V_152 |= V_24 -> V_153 ;
V_24 -> V_153 = 0 ;
if ( F_77 ( V_152 & V_164 ) ) {
if ( V_152 & V_174 ) {
V_152 &= ~ ( V_175 | V_176 ) ;
V_24 -> V_2 . V_172 . V_177 ++ ;
if ( V_24 -> V_2 . type == V_178 )
F_74 ( V_24 ) ;
if ( F_78 ( & V_24 -> V_2 ) )
goto V_179;
} else if ( V_152 & V_176 )
V_24 -> V_2 . V_172 . V_180 ++ ;
else if ( V_152 & V_175 )
V_24 -> V_2 . V_172 . V_181 ++ ;
if ( V_152 & V_182 )
V_24 -> V_2 . V_172 . V_183 ++ ;
V_152 &= V_24 -> V_2 . V_159 ;
if ( V_152 & V_174 ) {
F_79 ( L_15 ) ;
V_170 = V_184 ;
} else if ( V_152 & V_176 )
V_170 = V_185 ;
else if ( V_152 & V_175 )
V_170 = V_186 ;
}
if ( F_80 ( & V_24 -> V_2 , V_168 ) )
goto V_179;
F_81 ( & V_24 -> V_2 , V_152 , V_182 , V_168 , V_170 ) ;
V_179:
V_152 = F_32 ( V_24 , V_76 ) ;
} while ( ( V_152 & ( V_77 | V_174 ) ) && ( V_169 -- > 0 ) );
F_82 ( & V_24 -> V_2 . V_65 ) ;
F_83 ( V_166 ) ;
F_84 ( & V_24 -> V_2 . V_65 ) ;
* V_101 = V_152 ;
}
static void F_71 ( struct V_23 * V_24 )
{
struct V_187 * V_188 = & V_24 -> V_2 . V_167 -> V_188 ;
int V_72 ;
if ( V_24 -> V_2 . V_189 ) {
F_34 ( V_24 , V_27 , V_24 -> V_2 . V_189 ) ;
V_24 -> V_2 . V_172 . V_190 ++ ;
V_24 -> V_2 . V_189 = 0 ;
return;
}
if ( F_85 ( & V_24 -> V_2 ) ) {
F_69 ( & V_24 -> V_2 ) ;
return;
}
if ( F_86 ( V_188 ) ) {
F_68 ( V_24 ) ;
return;
}
V_72 = V_24 -> V_136 ;
do {
V_31 ( V_24 , V_27 , V_188 -> V_191 [ V_188 -> V_192 ] ) ;
V_188 -> V_192 = ( V_188 -> V_192 + 1 ) & ( V_193 - 1 ) ;
V_24 -> V_2 . V_172 . V_190 ++ ;
if ( F_86 ( V_188 ) )
break;
} while ( -- V_72 > 0 );
if ( F_87 ( V_188 ) < V_194 )
F_88 ( & V_24 -> V_2 ) ;
F_79 ( L_16 ) ;
if ( F_86 ( V_188 ) )
F_68 ( V_24 ) ;
}
static unsigned int F_89 ( struct V_23 * V_24 )
{
unsigned int V_101 = V_28 ( V_24 , V_125 ) ;
V_101 |= V_24 -> V_195 ;
V_24 -> V_195 = 0 ;
if ( V_101 & V_196 && V_24 -> V_148 & V_161 &&
V_24 -> V_2 . V_167 != NULL ) {
if ( V_101 & V_197 )
V_24 -> V_2 . V_172 . V_198 ++ ;
if ( V_101 & V_199 )
V_24 -> V_2 . V_172 . V_200 ++ ;
if ( V_101 & V_201 )
F_90 ( & V_24 -> V_2 , V_101 & V_202 ) ;
if ( V_101 & V_203 )
F_91 ( & V_24 -> V_2 , V_101 & V_204 ) ;
F_92 ( & V_24 -> V_2 . V_167 -> V_2 . V_205 ) ;
}
return V_101 ;
}
static void F_93 ( struct V_23 * V_24 )
{
unsigned int V_101 ;
unsigned long V_120 ;
F_57 ( & V_24 -> V_2 . V_65 , V_120 ) ;
V_101 = F_32 ( V_24 , V_76 ) ;
F_79 ( L_17 , V_101 ) ;
if ( V_101 & ( V_77 | V_174 ) )
F_75 ( V_24 , & V_101 ) ;
F_89 ( V_24 ) ;
if ( V_101 & V_156 )
F_71 ( V_24 ) ;
F_61 ( & V_24 -> V_2 . V_65 , V_120 ) ;
}
static T_2 F_94 ( int V_142 , void * V_206 )
{
struct V_207 * V_129 = V_206 ;
struct V_208 * V_209 , * V_210 = NULL ;
int V_211 = 0 , V_212 = 0 ;
F_79 ( L_18 , V_142 ) ;
F_84 ( & V_129 -> V_65 ) ;
V_209 = V_129 -> V_213 ;
do {
struct V_23 * V_24 ;
unsigned int V_214 ;
V_24 = F_95 ( V_209 , struct V_23 , V_215 ) ;
V_214 = V_28 ( V_24 , V_20 ) ;
if ( ! ( V_214 & V_216 ) ) {
F_93 ( V_24 ) ;
V_212 = 1 ;
V_210 = NULL ;
} else if ( ( V_24 -> V_2 . V_7 == V_35 ||
V_24 -> V_2 . V_7 == V_36 ) &&
( V_214 & V_217 ) == V_217 ) {
unsigned int V_101 ;
V_101 = * ( volatile V_218 * ) V_24 -> V_2 . V_219 ;
V_31 ( V_24 , V_25 , V_24 -> V_26 ) ;
V_212 = 1 ;
V_210 = NULL ;
} else if ( V_210 == NULL )
V_210 = V_209 ;
V_209 = V_209 -> V_220 ;
if ( V_209 == V_129 -> V_213 && V_211 ++ > V_221 ) {
F_96 ( V_222
L_19 , V_142 ) ;
break;
}
} while ( V_209 != V_210 );
F_82 ( & V_129 -> V_65 ) ;
F_79 ( L_20 ) ;
return F_97 ( V_212 ) ;
}
static void F_98 ( struct V_207 * V_129 , struct V_23 * V_24 )
{
F_43 ( & V_129 -> V_65 ) ;
if ( ! F_99 ( V_129 -> V_213 ) ) {
if ( V_129 -> V_213 == & V_24 -> V_215 )
V_129 -> V_213 = V_129 -> V_213 -> V_220 ;
F_100 ( & V_24 -> V_215 ) ;
} else {
F_101 ( V_129 -> V_213 != & V_24 -> V_215 ) ;
V_129 -> V_213 = NULL ;
}
F_44 ( & V_129 -> V_65 ) ;
if ( V_129 -> V_213 == NULL ) {
F_102 ( & V_129 -> V_223 ) ;
F_103 ( V_129 ) ;
}
}
static int F_104 ( struct V_23 * V_24 )
{
struct V_224 * V_225 ;
struct V_226 * V_227 ;
struct V_207 * V_129 ;
int V_228 , V_229 = V_24 -> V_2 . V_120 & V_230 ? V_231 : 0 ;
F_105 ( & V_232 ) ;
V_225 = & V_233 [ V_24 -> V_2 . V_142 % V_234 ] ;
F_106 (n, h) {
V_129 = F_107 ( V_227 , struct V_207 , V_223 ) ;
if ( V_129 -> V_142 == V_24 -> V_2 . V_142 )
break;
}
if ( V_227 == NULL ) {
V_129 = F_108 ( sizeof( struct V_207 ) , V_235 ) ;
if ( V_129 == NULL ) {
F_109 ( & V_232 ) ;
return - V_236 ;
}
F_110 ( & V_129 -> V_65 ) ;
V_129 -> V_142 = V_24 -> V_2 . V_142 ;
F_111 ( & V_129 -> V_223 , V_225 ) ;
}
F_109 ( & V_232 ) ;
F_43 ( & V_129 -> V_65 ) ;
if ( V_129 -> V_213 ) {
F_112 ( & V_24 -> V_215 , V_129 -> V_213 ) ;
F_44 ( & V_129 -> V_65 ) ;
V_228 = 0 ;
} else {
F_113 ( & V_24 -> V_215 ) ;
V_129 -> V_213 = & V_24 -> V_215 ;
F_44 ( & V_129 -> V_65 ) ;
V_229 |= V_24 -> V_2 . V_237 ;
V_228 = F_114 ( V_24 -> V_2 . V_142 , F_94 ,
V_229 , L_21 , V_129 ) ;
if ( V_228 < 0 )
F_98 ( V_129 , V_24 ) ;
}
return V_228 ;
}
static void F_115 ( struct V_23 * V_24 )
{
struct V_207 * V_129 ;
struct V_226 * V_227 ;
struct V_224 * V_225 ;
F_105 ( & V_232 ) ;
V_225 = & V_233 [ V_24 -> V_2 . V_142 % V_234 ] ;
F_106 (n, h) {
V_129 = F_107 ( V_227 , struct V_207 , V_223 ) ;
if ( V_129 -> V_142 == V_24 -> V_2 . V_142 )
break;
}
F_101 ( V_227 == NULL ) ;
F_101 ( V_129 -> V_213 == NULL ) ;
if ( F_99 ( V_129 -> V_213 ) )
F_116 ( V_24 -> V_2 . V_142 , V_129 ) ;
F_98 ( V_129 , V_24 ) ;
F_109 ( & V_232 ) ;
}
static void F_117 ( unsigned long V_238 )
{
struct V_23 * V_24 = (struct V_23 * ) V_238 ;
unsigned int V_214 ;
V_214 = V_28 ( V_24 , V_20 ) ;
if ( ! ( V_214 & V_216 ) )
F_93 ( V_24 ) ;
F_118 ( & V_24 -> V_239 , V_240 + F_119 ( & V_24 -> V_2 ) ) ;
}
static void F_120 ( unsigned long V_238 )
{
struct V_23 * V_24 = (struct V_23 * ) V_238 ;
unsigned int V_214 , V_148 = 0 , V_152 ;
unsigned long V_120 ;
F_57 ( & V_24 -> V_2 . V_65 , V_120 ) ;
if ( F_121 ( V_24 -> V_2 . V_142 ) ) {
V_148 = V_28 ( V_24 , V_21 ) ;
V_31 ( V_24 , V_21 , 0 ) ;
}
V_214 = V_28 ( V_24 , V_20 ) ;
V_152 = V_28 ( V_24 , V_76 ) ;
V_24 -> V_153 |= V_152 & V_154 ;
if ( ( V_214 & V_216 ) && ( V_24 -> V_148 & V_149 ) &&
( ! F_86 ( & V_24 -> V_2 . V_167 -> V_188 ) || V_24 -> V_2 . V_189 ) &&
( V_152 & V_156 ) ) {
V_214 &= ~ ( V_241 | V_216 ) ;
V_214 |= V_242 ;
}
if ( ! ( V_214 & V_216 ) )
F_71 ( V_24 ) ;
if ( F_121 ( V_24 -> V_2 . V_142 ) )
V_31 ( V_24 , V_21 , V_148 ) ;
F_61 ( & V_24 -> V_2 . V_65 , V_120 ) ;
F_118 ( & V_24 -> V_239 ,
V_240 + F_119 ( & V_24 -> V_2 ) + V_243 / 5 ) ;
}
static unsigned int F_122 ( struct V_1 * V_2 )
{
struct V_23 * V_24 =
F_23 ( V_2 , struct V_23 , V_2 ) ;
unsigned long V_120 ;
unsigned int V_152 ;
F_57 ( & V_24 -> V_2 . V_65 , V_120 ) ;
V_152 = V_28 ( V_24 , V_76 ) ;
V_24 -> V_153 |= V_152 & V_154 ;
F_61 ( & V_24 -> V_2 . V_65 , V_120 ) ;
return ( V_152 & V_244 ) == V_244 ? V_245 : 0 ;
}
static unsigned int F_123 ( struct V_1 * V_2 )
{
struct V_23 * V_24 =
F_23 ( V_2 , struct V_23 , V_2 ) ;
unsigned int V_101 ;
unsigned int V_228 ;
V_101 = F_89 ( V_24 ) ;
V_228 = 0 ;
if ( V_101 & V_202 )
V_228 |= V_246 ;
if ( V_101 & V_247 )
V_228 |= V_248 ;
if ( V_101 & V_249 )
V_228 |= V_250 ;
if ( V_101 & V_204 )
V_228 |= V_251 ;
return V_228 ;
}
static void F_124 ( struct V_1 * V_2 , unsigned int V_252 )
{
struct V_23 * V_24 =
F_23 ( V_2 , struct V_23 , V_2 ) ;
unsigned char V_253 = 0 ;
if ( V_252 & V_254 )
V_253 |= V_147 ;
if ( V_252 & V_255 )
V_253 |= V_146 ;
if ( V_252 & V_256 )
V_253 |= V_144 ;
if ( V_252 & V_257 )
V_253 |= V_145 ;
if ( V_252 & V_258 )
V_253 |= V_74 ;
V_253 = ( V_253 & V_24 -> V_259 ) | V_24 -> V_260 | V_24 -> V_253 ;
V_31 ( V_24 , V_73 , V_253 ) ;
}
static void F_125 ( struct V_1 * V_2 , int V_261 )
{
struct V_23 * V_24 =
F_23 ( V_2 , struct V_23 , V_2 ) ;
unsigned long V_120 ;
F_57 ( & V_24 -> V_2 . V_65 , V_120 ) ;
if ( V_261 == - 1 )
V_24 -> V_26 |= V_262 ;
else
V_24 -> V_26 &= ~ V_262 ;
V_31 ( V_24 , V_25 , V_24 -> V_26 ) ;
F_61 ( & V_24 -> V_2 . V_65 , V_120 ) ;
}
static void F_126 ( struct V_23 * V_24 , int V_263 )
{
unsigned int V_101 , V_162 = 10000 ;
for (; ; ) {
V_101 = V_28 ( V_24 , V_76 ) ;
V_24 -> V_153 |= V_101 & V_154 ;
if ( ( V_101 & V_263 ) == V_263 )
break;
if ( -- V_162 == 0 )
break;
F_67 ( 1 ) ;
}
if ( V_24 -> V_2 . V_120 & V_264 ) {
unsigned int V_162 ;
for ( V_162 = 1000000 ; V_162 ; V_162 -- ) {
unsigned int V_265 = V_28 ( V_24 , V_125 ) ;
V_24 -> V_195 |= V_265 & V_266 ;
if ( V_265 & V_204 )
break;
F_67 ( 1 ) ;
F_127 () ;
}
}
}
static int F_128 ( struct V_1 * V_2 )
{
struct V_23 * V_24 =
F_23 ( V_2 , struct V_23 , V_2 ) ;
unsigned char V_152 = F_32 ( V_24 , V_76 ) ;
if ( ! ( V_152 & V_77 ) )
return V_267 ;
return F_32 ( V_24 , V_78 ) ;
}
static void F_129 ( struct V_1 * V_2 ,
unsigned char V_268 )
{
unsigned int V_148 ;
struct V_23 * V_24 =
F_23 ( V_2 , struct V_23 , V_2 ) ;
V_148 = V_28 ( V_24 , V_21 ) ;
if ( V_24 -> V_45 & V_112 )
V_31 ( V_24 , V_21 , V_22 ) ;
else
V_31 ( V_24 , V_21 , 0 ) ;
F_126 ( V_24 , V_244 ) ;
V_31 ( V_24 , V_27 , V_268 ) ;
if ( V_268 == 10 ) {
F_126 ( V_24 , V_244 ) ;
V_31 ( V_24 , V_27 , 13 ) ;
}
F_126 ( V_24 , V_244 ) ;
V_31 ( V_24 , V_21 , V_148 ) ;
}
static int F_130 ( struct V_1 * V_2 )
{
struct V_23 * V_24 =
F_23 ( V_2 , struct V_23 , V_2 ) ;
unsigned long V_120 ;
unsigned char V_152 , V_214 ;
int V_269 ;
V_24 -> V_2 . V_134 = V_132 [ V_24 -> V_2 . type ] . V_135 ;
V_24 -> V_136 = V_132 [ V_24 -> V_2 . type ] . V_136 ;
V_24 -> V_45 = V_132 [ V_24 -> V_2 . type ] . V_120 ;
V_24 -> V_253 = 0 ;
if ( V_24 -> V_2 . V_7 != V_24 -> V_37 )
F_29 ( V_2 ) ;
if ( V_24 -> V_2 . type == V_90 ) {
V_24 -> V_43 = 0 ;
F_34 ( V_24 , V_25 , V_54 ) ;
F_34 ( V_24 , V_55 , V_56 ) ;
F_34 ( V_24 , V_21 , 0 ) ;
F_34 ( V_24 , V_25 , 0 ) ;
F_37 ( V_24 , V_270 , 0 ) ;
F_34 ( V_24 , V_25 , 0xBF ) ;
F_34 ( V_24 , V_55 , V_56 ) ;
F_34 ( V_24 , V_25 , 0 ) ;
}
#ifdef F_59
F_42 ( V_24 ) ;
#endif
F_39 ( V_24 ) ;
( void ) F_32 ( V_24 , V_76 ) ;
( void ) F_32 ( V_24 , V_78 ) ;
( void ) F_32 ( V_24 , V_20 ) ;
( void ) F_32 ( V_24 , V_125 ) ;
if ( ! ( V_24 -> V_2 . V_120 & V_122 ) &&
( F_32 ( V_24 , V_76 ) == 0xff ) ) {
F_60 ( V_271 L_22 ,
F_1 ( & V_24 -> V_2 ) ) ;
return - V_272 ;
}
if ( V_24 -> V_2 . type == V_93 ) {
unsigned char V_273 ;
F_34 ( V_24 , V_25 , V_54 ) ;
V_273 = F_32 ( V_24 , V_274 ) & ~ ( V_275 | V_276 ) ;
F_34 ( V_24 , V_274 , V_273 | V_277 | V_275 ) ;
F_34 ( V_24 , V_278 , V_279 ) ;
F_34 ( V_24 , V_274 , V_273 | V_277 | V_276 ) ;
F_34 ( V_24 , V_278 , V_279 ) ;
F_34 ( V_24 , V_25 , 0 ) ;
}
if ( F_121 ( V_24 -> V_2 . V_142 ) ) {
unsigned char V_280 ;
F_57 ( & V_24 -> V_2 . V_65 , V_120 ) ;
if ( V_24 -> V_2 . V_237 & V_231 )
F_131 ( V_24 -> V_2 . V_142 ) ;
F_126 ( V_24 , V_156 ) ;
F_30 ( V_24 , V_21 , V_149 ) ;
F_67 ( 1 ) ;
V_280 = V_28 ( V_24 , V_20 ) ;
V_31 ( V_24 , V_21 , 0 ) ;
F_30 ( V_24 , V_21 , V_149 ) ;
F_67 ( 1 ) ;
V_214 = V_28 ( V_24 , V_20 ) ;
V_31 ( V_24 , V_21 , 0 ) ;
if ( V_24 -> V_2 . V_237 & V_231 )
F_132 ( V_24 -> V_2 . V_142 ) ;
F_61 ( & V_24 -> V_2 . V_65 , V_120 ) ;
if ( ! ( V_280 & V_216 ) && ( V_214 & V_216 ) ) {
V_24 -> V_91 |= V_281 ;
F_133 ( L_23 ,
F_1 ( V_2 ) ) ;
}
}
if ( V_24 -> V_91 & V_281 ) {
V_24 -> V_239 . V_282 = F_120 ;
V_24 -> V_239 . V_238 = ( unsigned long ) V_24 ;
F_118 ( & V_24 -> V_239 , V_240 +
F_119 ( V_2 ) + V_243 / 5 ) ;
}
if ( ! F_121 ( V_24 -> V_2 . V_142 ) ) {
V_24 -> V_239 . V_238 = ( unsigned long ) V_24 ;
F_118 ( & V_24 -> V_239 , V_240 + F_119 ( V_2 ) ) ;
} else {
V_269 = F_104 ( V_24 ) ;
if ( V_269 )
return V_269 ;
}
F_34 ( V_24 , V_25 , V_283 ) ;
F_57 ( & V_24 -> V_2 . V_65 , V_120 ) ;
if ( V_24 -> V_2 . V_120 & V_143 ) {
if ( ! F_121 ( V_24 -> V_2 . V_142 ) )
V_24 -> V_2 . V_252 |= V_256 ;
} else
if ( F_121 ( V_24 -> V_2 . V_142 ) )
V_24 -> V_2 . V_252 |= V_257 ;
F_124 ( & V_24 -> V_2 , V_24 -> V_2 . V_252 ) ;
if ( V_284 || V_24 -> V_2 . V_120 & V_285 )
goto V_286;
F_34 ( V_24 , V_21 , V_149 ) ;
V_152 = V_28 ( V_24 , V_76 ) ;
V_214 = V_28 ( V_24 , V_20 ) ;
F_34 ( V_24 , V_21 , 0 ) ;
if ( V_152 & V_157 && V_214 & V_216 ) {
if ( ! ( V_24 -> V_91 & V_151 ) ) {
V_24 -> V_91 |= V_151 ;
F_133 ( L_24 ,
F_1 ( V_2 ) ) ;
}
} else {
V_24 -> V_91 &= ~ V_151 ;
}
V_286:
F_61 ( & V_24 -> V_2 . V_65 , V_120 ) ;
F_32 ( V_24 , V_76 ) ;
F_32 ( V_24 , V_78 ) ;
F_32 ( V_24 , V_20 ) ;
F_32 ( V_24 , V_125 ) ;
V_24 -> V_153 = 0 ;
V_24 -> V_195 = 0 ;
V_24 -> V_148 = V_158 | V_287 ;
F_34 ( V_24 , V_21 , V_24 -> V_148 ) ;
if ( V_24 -> V_2 . V_120 & V_143 ) {
unsigned int V_288 ;
V_288 = ( V_24 -> V_2 . V_16 & 0xfe0 ) | 0x01f ;
F_64 ( 0x80 , V_288 ) ;
( void ) F_63 ( V_288 ) ;
}
return 0 ;
}
static void F_134 ( struct V_1 * V_2 )
{
struct V_23 * V_24 =
F_23 ( V_2 , struct V_23 , V_2 ) ;
unsigned long V_120 ;
V_24 -> V_148 = 0 ;
F_34 ( V_24 , V_21 , 0 ) ;
F_57 ( & V_24 -> V_2 . V_65 , V_120 ) ;
if ( V_24 -> V_2 . V_120 & V_143 ) {
F_6 ( ( V_24 -> V_2 . V_16 & 0xfe0 ) | 0x1f ) ;
V_24 -> V_2 . V_252 |= V_256 ;
} else
V_24 -> V_2 . V_252 &= ~ V_257 ;
F_124 ( & V_24 -> V_2 , V_24 -> V_2 . V_252 ) ;
F_61 ( & V_24 -> V_2 . V_65 , V_120 ) ;
V_31 ( V_24 , V_25 , F_32 ( V_24 , V_25 ) & ~ V_262 ) ;
F_39 ( V_24 ) ;
#ifdef F_59
F_45 ( V_24 ) ;
#endif
( void ) V_28 ( V_24 , V_78 ) ;
F_135 ( & V_24 -> V_239 ) ;
V_24 -> V_239 . V_282 = F_117 ;
if ( F_121 ( V_24 -> V_2 . V_142 ) )
F_115 ( V_24 ) ;
}
static unsigned int F_136 ( struct V_1 * V_2 , unsigned int V_289 )
{
unsigned int V_105 ;
if ( ( V_2 -> V_120 & V_290 ) &&
V_289 == ( V_2 -> V_62 / 4 ) )
V_105 = 0x8001 ;
else if ( ( V_2 -> V_120 & V_290 ) &&
V_289 == ( V_2 -> V_62 / 8 ) )
V_105 = 0x8002 ;
else
V_105 = F_137 ( V_2 , V_289 ) ;
return V_105 ;
}
void
F_138 ( struct V_1 * V_2 , struct V_291 * V_292 ,
struct V_291 * V_293 )
{
struct V_23 * V_24 =
F_23 ( V_2 , struct V_23 , V_2 ) ;
unsigned char V_294 , V_295 = 0 ;
unsigned long V_120 ;
unsigned int V_289 , V_105 ;
switch ( V_292 -> V_296 & V_297 ) {
case V_298 :
V_294 = V_299 ;
break;
case V_300 :
V_294 = V_301 ;
break;
case V_302 :
V_294 = V_303 ;
break;
default:
case V_304 :
V_294 = V_283 ;
break;
}
if ( V_292 -> V_296 & V_305 )
V_294 |= V_306 ;
if ( V_292 -> V_296 & V_307 )
V_294 |= V_308 ;
if ( ! ( V_292 -> V_296 & V_309 ) )
V_294 |= V_310 ;
#ifdef F_139
if ( V_292 -> V_296 & F_139 )
V_294 |= V_311 ;
#endif
V_289 = F_140 ( V_2 , V_292 , V_293 ,
V_2 -> V_62 / 16 / 0xffff ,
V_2 -> V_62 / 16 ) ;
V_105 = F_136 ( V_2 , V_289 ) ;
if ( V_24 -> V_91 & V_92 && ( V_105 & 0xff ) == 0 )
V_105 ++ ;
if ( V_24 -> V_45 & V_46 && V_24 -> V_2 . V_134 > 1 ) {
if ( V_289 < 2400 )
V_295 = V_48 | V_312 ;
else
V_295 = V_132 [ V_24 -> V_2 . type ] . V_295 ;
}
if ( V_24 -> V_45 & V_110 && V_24 -> V_2 . V_134 >= 32 ) {
V_24 -> V_253 &= ~ V_313 ;
if ( V_292 -> V_296 & V_314 )
V_24 -> V_253 |= V_313 ;
}
F_57 ( & V_24 -> V_2 . V_65 , V_120 ) ;
F_141 ( V_2 , V_292 -> V_296 , V_289 ) ;
V_24 -> V_2 . V_159 = V_182 | V_156 | V_77 ;
if ( V_292 -> V_315 & V_316 )
V_24 -> V_2 . V_159 |= V_175 | V_176 ;
if ( V_292 -> V_315 & ( V_317 | V_318 ) )
V_24 -> V_2 . V_159 |= V_174 ;
V_24 -> V_2 . V_319 = 0 ;
if ( V_292 -> V_315 & V_320 )
V_24 -> V_2 . V_319 |= V_176 | V_175 ;
if ( V_292 -> V_315 & V_321 ) {
V_24 -> V_2 . V_319 |= V_174 ;
if ( V_292 -> V_315 & V_320 )
V_24 -> V_2 . V_319 |= V_182 ;
}
if ( ( V_292 -> V_296 & V_322 ) == 0 )
V_24 -> V_2 . V_319 |= V_77 ;
V_24 -> V_148 &= ~ V_161 ;
if ( ! ( V_24 -> V_91 & V_160 ) &&
F_142 ( & V_24 -> V_2 , V_292 -> V_296 ) )
V_24 -> V_148 |= V_161 ;
if ( V_24 -> V_45 & V_112 )
V_24 -> V_148 |= V_22 ;
if ( V_24 -> V_45 & V_113 )
V_24 -> V_148 |= V_323 ;
V_31 ( V_24 , V_21 , V_24 -> V_148 ) ;
if ( V_24 -> V_45 & V_53 ) {
unsigned char V_324 = 0 ;
if ( V_292 -> V_296 & V_314 )
V_324 |= V_325 ;
F_34 ( V_24 , V_25 , V_54 ) ;
F_34 ( V_24 , V_55 , V_324 ) ;
}
#ifdef F_143
if ( F_144 () && F_145 ( V_24 ) ) {
if ( V_289 == 115200 ) {
V_105 = 1 ;
V_31 ( V_24 , V_326 , 1 ) ;
} else
V_31 ( V_24 , V_326 , 0 ) ;
}
#endif
if ( V_24 -> V_45 & V_107 ) {
F_34 ( V_24 , V_25 , 0xe0 ) ;
} else {
F_34 ( V_24 , V_25 , V_294 | V_327 ) ;
}
F_36 ( V_24 , V_105 ) ;
if ( V_24 -> V_2 . type == V_109 )
F_34 ( V_24 , V_47 , V_295 ) ;
F_34 ( V_24 , V_25 , V_294 ) ;
V_24 -> V_26 = V_294 ;
if ( V_24 -> V_2 . type != V_109 ) {
if ( V_295 & V_48 ) {
F_34 ( V_24 , V_47 , V_48 ) ;
}
F_34 ( V_24 , V_47 , V_295 ) ;
}
F_124 ( & V_24 -> V_2 , V_24 -> V_2 . V_252 ) ;
F_61 ( & V_24 -> V_2 . V_65 , V_120 ) ;
if ( F_146 ( V_292 ) )
F_147 ( V_292 , V_289 , V_289 ) ;
}
static void
F_148 ( struct V_1 * V_2 , struct V_291 * V_292 ,
struct V_291 * V_293 )
{
if ( V_2 -> V_328 )
V_2 -> V_328 ( V_2 , V_292 , V_293 ) ;
else
F_138 ( V_2 , V_292 , V_293 ) ;
}
static void
F_149 ( struct V_1 * V_2 , int V_329 )
{
if ( V_329 == V_330 ) {
V_2 -> V_120 |= V_331 ;
F_73 ( V_2 ) ;
} else
V_2 -> V_120 &= ~ V_331 ;
}
void F_150 ( struct V_1 * V_2 , unsigned int V_167 ,
unsigned int V_332 )
{
struct V_23 * V_5 =
F_23 ( V_2 , struct V_23 , V_2 ) ;
F_40 ( V_5 , V_167 != 0 ) ;
}
static void
F_151 ( struct V_1 * V_2 , unsigned int V_167 ,
unsigned int V_332 )
{
if ( V_2 -> V_333 )
V_2 -> V_333 ( V_2 , V_167 , V_332 ) ;
else
F_150 ( V_2 , V_167 , V_332 ) ;
}
static unsigned int F_152 ( struct V_23 * V_334 )
{
if ( V_334 -> V_2 . V_7 == V_8 )
return 0x1000 ;
#ifdef F_143
if ( F_145 ( V_334 ) )
return 0x16 << V_334 -> V_2 . V_14 ;
#endif
return 8 << V_334 -> V_2 . V_14 ;
}
static int F_153 ( struct V_23 * V_24 )
{
unsigned int V_335 = F_152 ( V_24 ) ;
int V_228 = 0 ;
switch ( V_24 -> V_2 . V_7 ) {
case V_8 :
case V_34 :
case V_33 :
case V_32 :
case V_35 :
case V_36 :
if ( ! V_24 -> V_2 . V_121 )
break;
if ( ! F_154 ( V_24 -> V_2 . V_121 , V_335 , L_21 ) ) {
V_228 = - V_336 ;
break;
}
if ( V_24 -> V_2 . V_120 & V_337 ) {
V_24 -> V_2 . V_18 = F_155 ( V_24 -> V_2 . V_121 ,
V_335 ) ;
if ( ! V_24 -> V_2 . V_18 ) {
F_156 ( V_24 -> V_2 . V_121 , V_335 ) ;
V_228 = - V_236 ;
}
}
break;
case V_30 :
case V_338 :
if ( ! F_157 ( V_24 -> V_2 . V_16 , V_335 , L_21 ) )
V_228 = - V_336 ;
break;
}
return V_228 ;
}
static void F_158 ( struct V_23 * V_24 )
{
unsigned int V_335 = F_152 ( V_24 ) ;
switch ( V_24 -> V_2 . V_7 ) {
case V_8 :
case V_34 :
case V_33 :
case V_32 :
case V_35 :
case V_36 :
if ( ! V_24 -> V_2 . V_121 )
break;
if ( V_24 -> V_2 . V_120 & V_337 ) {
F_159 ( V_24 -> V_2 . V_18 ) ;
V_24 -> V_2 . V_18 = NULL ;
}
F_156 ( V_24 -> V_2 . V_121 , V_335 ) ;
break;
case V_30 :
case V_338 :
F_160 ( V_24 -> V_2 . V_16 , V_335 ) ;
break;
}
}
static int F_161 ( struct V_23 * V_24 )
{
unsigned long V_339 = V_340 << V_24 -> V_2 . V_14 ;
unsigned int V_335 = 8 << V_24 -> V_2 . V_14 ;
int V_228 = - V_341 ;
switch ( V_24 -> V_2 . V_7 ) {
case V_30 :
case V_338 :
V_339 += V_24 -> V_2 . V_16 ;
if ( F_157 ( V_339 , V_335 , L_25 ) )
V_228 = 0 ;
else
V_228 = - V_336 ;
break;
}
return V_228 ;
}
static void F_162 ( struct V_23 * V_24 )
{
unsigned long V_6 = V_340 << V_24 -> V_2 . V_14 ;
unsigned int V_335 = 8 << V_24 -> V_2 . V_14 ;
switch ( V_24 -> V_2 . V_7 ) {
case V_30 :
case V_338 :
F_160 ( V_24 -> V_2 . V_16 + V_6 , V_335 ) ;
break;
}
}
static void F_163 ( struct V_1 * V_2 )
{
struct V_23 * V_24 =
F_23 ( V_2 , struct V_23 , V_2 ) ;
F_158 ( V_24 ) ;
if ( V_24 -> V_2 . type == V_64 )
F_162 ( V_24 ) ;
}
static int F_164 ( struct V_1 * V_2 )
{
struct V_23 * V_24 =
F_23 ( V_2 , struct V_23 , V_2 ) ;
int V_228 = 0 ;
V_228 = F_153 ( V_24 ) ;
if ( V_228 == 0 && V_24 -> V_2 . type == V_64 ) {
V_228 = F_161 ( V_24 ) ;
if ( V_228 < 0 )
F_158 ( V_24 ) ;
}
return V_228 ;
}
static void F_165 ( struct V_1 * V_2 , int V_120 )
{
struct V_23 * V_24 =
F_23 ( V_2 , struct V_23 , V_2 ) ;
int V_115 = V_342 ;
int V_228 ;
V_228 = F_153 ( V_24 ) ;
if ( V_228 < 0 )
return;
V_228 = F_161 ( V_24 ) ;
if ( V_228 < 0 )
V_115 &= ~ V_128 ;
if ( V_24 -> V_2 . V_7 != V_24 -> V_37 )
F_29 ( V_2 ) ;
if ( V_120 & V_343 )
F_56 ( V_24 , V_115 ) ;
if ( V_24 -> V_2 . type == V_103 && V_24 -> V_2 . V_7 == V_8 )
V_24 -> V_91 |= V_160 ;
if ( V_24 -> V_2 . type != V_126 && V_120 & V_344 )
F_62 ( V_24 ) ;
if ( V_24 -> V_2 . type != V_64 && V_115 & V_128 )
F_162 ( V_24 ) ;
if ( V_24 -> V_2 . type == V_126 )
F_158 ( V_24 ) ;
}
static int
F_166 ( struct V_1 * V_2 , struct V_345 * V_346 )
{
if ( V_346 -> V_142 >= V_347 || V_346 -> V_142 < 0 ||
V_346 -> V_348 < 9600 || V_346 -> type < V_126 ||
V_346 -> type >= F_167 ( V_132 ) || V_346 -> type == V_349 ||
V_346 -> type == V_350 )
return - V_341 ;
return 0 ;
}
static const char *
F_168 ( struct V_1 * V_2 )
{
int type = V_2 -> type ;
if ( type >= F_167 ( V_132 ) )
type = 0 ;
return V_132 [ type ] . V_137 ;
}
void F_169 (
void (* F_170)( int V_2 , struct V_1 * V_24 , unsigned short * V_45 ) )
{
V_351 = F_170 ;
}
static void T_3 F_171 ( void )
{
struct V_23 * V_24 ;
static int V_352 = 1 ;
int V_129 , V_353 = 0 ;
if ( ! V_352 )
return;
V_352 = 0 ;
for ( V_129 = 0 ; V_129 < V_354 ; V_129 ++ ) {
struct V_23 * V_24 = & V_355 [ V_129 ] ;
V_24 -> V_2 . line = V_129 ;
F_110 ( & V_24 -> V_2 . V_65 ) ;
F_172 ( & V_24 -> V_239 ) ;
V_24 -> V_239 . V_282 = F_117 ;
V_24 -> V_259 = ~ V_356 ;
V_24 -> V_260 = V_356 ;
V_24 -> V_2 . V_357 = & V_358 ;
}
if ( V_359 )
V_353 = V_231 ;
for ( V_129 = 0 , V_24 = V_355 ;
V_129 < F_167 ( V_360 ) && V_129 < V_354 ;
V_129 ++ , V_24 ++ ) {
V_24 -> V_2 . V_16 = V_360 [ V_129 ] . V_2 ;
V_24 -> V_2 . V_142 = F_173 ( V_360 [ V_129 ] . V_142 ) ;
V_24 -> V_2 . V_237 = V_360 [ V_129 ] . V_237 ;
V_24 -> V_2 . V_62 = V_360 [ V_129 ] . V_348 * 16 ;
V_24 -> V_2 . V_120 = V_360 [ V_129 ] . V_120 ;
V_24 -> V_2 . V_15 = V_360 [ V_129 ] . V_15 ;
V_24 -> V_2 . V_18 = V_360 [ V_129 ] . V_361 ;
V_24 -> V_2 . V_7 = V_360 [ V_129 ] . V_362 ;
V_24 -> V_2 . V_14 = V_360 [ V_129 ] . V_363 ;
F_29 ( & V_24 -> V_2 ) ;
V_24 -> V_2 . V_237 |= V_353 ;
if ( V_351 != NULL )
V_351 ( V_129 , & V_24 -> V_2 , & V_24 -> V_45 ) ;
}
}
static void
F_174 ( struct V_23 * V_24 , unsigned int type )
{
V_24 -> V_2 . type = type ;
V_24 -> V_2 . V_134 = V_132 [ type ] . V_135 ;
V_24 -> V_45 = V_132 [ type ] . V_120 ;
V_24 -> V_136 = V_132 [ type ] . V_136 ;
}
static void T_3
F_175 ( struct V_364 * V_365 , struct V_366 * V_367 )
{
int V_129 ;
for ( V_129 = 0 ; V_129 < V_354 ; V_129 ++ ) {
struct V_23 * V_24 = & V_355 [ V_129 ] ;
V_24 -> V_37 = 0xFF ;
}
F_171 () ;
for ( V_129 = 0 ; V_129 < V_354 ; V_129 ++ ) {
struct V_23 * V_24 = & V_355 [ V_129 ] ;
V_24 -> V_2 . V_367 = V_367 ;
if ( V_24 -> V_2 . V_120 & V_368 )
F_174 ( V_24 , V_24 -> V_2 . type ) ;
F_176 ( V_365 , & V_24 -> V_2 ) ;
}
}
static void F_177 ( struct V_1 * V_2 , int V_168 )
{
struct V_23 * V_24 =
F_23 ( V_2 , struct V_23 , V_2 ) ;
F_126 ( V_24 , V_156 ) ;
V_31 ( V_24 , V_27 , V_168 ) ;
}
static void
F_178 ( struct V_369 * V_370 , const char * V_371 , unsigned int V_72 )
{
struct V_23 * V_24 = & V_355 [ V_370 -> V_372 ] ;
unsigned long V_120 ;
unsigned int V_148 ;
int V_373 = 1 ;
F_127 () ;
F_179 ( V_120 ) ;
if ( V_24 -> V_2 . V_374 ) {
V_373 = 0 ;
} else if ( V_375 ) {
V_373 = F_180 ( & V_24 -> V_2 . V_65 ) ;
} else
F_84 ( & V_24 -> V_2 . V_65 ) ;
V_148 = V_28 ( V_24 , V_21 ) ;
if ( V_24 -> V_45 & V_112 )
V_31 ( V_24 , V_21 , V_22 ) ;
else
V_31 ( V_24 , V_21 , 0 ) ;
F_181 ( & V_24 -> V_2 , V_371 , V_72 , F_177 ) ;
F_126 ( V_24 , V_244 ) ;
V_31 ( V_24 , V_21 , V_148 ) ;
if ( V_24 -> V_195 )
F_89 ( V_24 ) ;
if ( V_373 )
F_82 ( & V_24 -> V_2 . V_65 ) ;
F_182 ( V_120 ) ;
}
static int T_3 F_183 ( struct V_369 * V_370 , char * V_376 )
{
struct V_1 * V_2 ;
int V_289 = 9600 ;
int V_263 = 8 ;
int V_180 = 'n' ;
int V_377 = 'n' ;
if ( V_370 -> V_372 >= V_354 )
V_370 -> V_372 = 0 ;
V_2 = & V_355 [ V_370 -> V_372 ] . V_2 ;
if ( ! V_2 -> V_16 && ! V_2 -> V_18 )
return - V_272 ;
if ( V_376 )
F_184 ( V_376 , & V_289 , & V_180 , & V_263 , & V_377 ) ;
return F_185 ( V_2 , V_370 , V_289 , V_180 , V_263 , V_377 ) ;
}
static int F_186 ( void )
{
return F_187 () ;
}
static int T_3 F_188 ( void )
{
if ( V_354 > V_378 )
V_354 = V_378 ;
F_171 () ;
F_189 ( & V_379 ) ;
return 0 ;
}
int F_190 ( struct V_1 * V_5 )
{
int line ;
struct V_1 * V_2 ;
for ( line = 0 ; line < V_354 ; line ++ ) {
V_2 = & V_355 [ line ] . V_2 ;
if ( F_191 ( V_5 , V_2 ) )
return line ;
}
return - V_272 ;
}
int T_3 F_192 ( struct V_1 * V_2 )
{
struct V_1 * V_5 ;
if ( V_2 -> line >= F_167 ( V_355 ) )
return - V_272 ;
F_171 () ;
V_5 = & V_355 [ V_2 -> line ] . V_2 ;
V_5 -> V_16 = V_2 -> V_16 ;
V_5 -> V_18 = V_2 -> V_18 ;
V_5 -> V_142 = V_2 -> V_142 ;
V_5 -> V_237 = V_2 -> V_237 ;
V_5 -> V_62 = V_2 -> V_62 ;
V_5 -> V_134 = V_2 -> V_134 ;
V_5 -> V_14 = V_2 -> V_14 ;
V_5 -> V_7 = V_2 -> V_7 ;
V_5 -> V_120 = V_2 -> V_120 ;
V_5 -> V_121 = V_2 -> V_121 ;
V_5 -> V_219 = V_2 -> V_219 ;
V_5 -> type = V_2 -> type ;
V_5 -> line = V_2 -> line ;
F_29 ( V_5 ) ;
if ( V_2 -> V_28 )
V_5 -> V_28 = V_2 -> V_28 ;
if ( V_2 -> V_31 )
V_5 -> V_31 = V_2 -> V_31 ;
return 0 ;
}
void F_193 ( int line )
{
F_194 ( & V_3 , & V_355 [ line ] . V_2 ) ;
}
void F_195 ( int line )
{
struct V_23 * V_24 = & V_355 [ line ] ;
if ( V_24 -> V_45 & V_107 ) {
F_34 ( V_24 , V_25 , 0xE0 ) ;
F_53 ( V_24 ) ;
F_34 ( V_24 , V_25 , 0 ) ;
V_24 -> V_2 . V_62 = 921600 * 16 ;
}
F_196 ( & V_3 , & V_24 -> V_2 ) ;
}
static int T_4 F_197 ( struct V_380 * V_367 )
{
struct V_381 * V_5 = V_367 -> V_367 . V_382 ;
struct V_1 V_2 ;
int V_228 , V_129 , V_353 = 0 ;
memset ( & V_2 , 0 , sizeof( struct V_1 ) ) ;
if ( V_359 )
V_353 = V_231 ;
for ( V_129 = 0 ; V_5 && V_5 -> V_120 != 0 ; V_5 ++ , V_129 ++ ) {
V_2 . V_16 = V_5 -> V_16 ;
V_2 . V_18 = V_5 -> V_18 ;
V_2 . V_142 = V_5 -> V_142 ;
V_2 . V_237 = V_5 -> V_237 ;
V_2 . V_62 = V_5 -> V_62 ;
V_2 . V_14 = V_5 -> V_14 ;
V_2 . V_7 = V_5 -> V_7 ;
V_2 . V_120 = V_5 -> V_120 ;
V_2 . V_121 = V_5 -> V_121 ;
V_2 . V_15 = V_5 -> V_15 ;
V_2 . V_219 = V_5 -> V_219 ;
V_2 . type = V_5 -> type ;
V_2 . V_28 = V_5 -> V_28 ;
V_2 . V_31 = V_5 -> V_31 ;
V_2 . V_328 = V_5 -> V_328 ;
V_2 . V_333 = V_5 -> V_333 ;
V_2 . V_367 = & V_367 -> V_367 ;
V_2 . V_237 |= V_353 ;
V_228 = F_198 ( & V_2 ) ;
if ( V_228 < 0 ) {
F_199 ( & V_367 -> V_367 , L_26
L_27 , V_129 ,
V_5 -> V_16 , ( unsigned long long ) V_5 -> V_121 ,
V_5 -> V_142 , V_228 ) ;
}
}
return 0 ;
}
static int T_5 F_200 ( struct V_380 * V_367 )
{
int V_129 ;
for ( V_129 = 0 ; V_129 < V_354 ; V_129 ++ ) {
struct V_23 * V_24 = & V_355 [ V_129 ] ;
if ( V_24 -> V_2 . V_367 == & V_367 -> V_367 )
F_201 ( V_129 ) ;
}
return 0 ;
}
static int F_202 ( struct V_380 * V_367 , T_6 V_167 )
{
int V_129 ;
for ( V_129 = 0 ; V_129 < V_378 ; V_129 ++ ) {
struct V_23 * V_24 = & V_355 [ V_129 ] ;
if ( V_24 -> V_2 . type != V_126 && V_24 -> V_2 . V_367 == & V_367 -> V_367 )
F_194 ( & V_3 , & V_24 -> V_2 ) ;
}
return 0 ;
}
static int F_203 ( struct V_380 * V_367 )
{
int V_129 ;
for ( V_129 = 0 ; V_129 < V_378 ; V_129 ++ ) {
struct V_23 * V_24 = & V_355 [ V_129 ] ;
if ( V_24 -> V_2 . type != V_126 && V_24 -> V_2 . V_367 == & V_367 -> V_367 )
F_195 ( V_129 ) ;
}
return 0 ;
}
static struct V_23 * F_204 ( struct V_1 * V_2 )
{
int V_129 ;
for ( V_129 = 0 ; V_129 < V_354 ; V_129 ++ )
if ( F_191 ( & V_355 [ V_129 ] . V_2 , V_2 ) )
return & V_355 [ V_129 ] ;
for ( V_129 = 0 ; V_129 < V_354 ; V_129 ++ )
if ( V_355 [ V_129 ] . V_2 . type == V_126 &&
V_355 [ V_129 ] . V_2 . V_16 == 0 )
return & V_355 [ V_129 ] ;
for ( V_129 = 0 ; V_129 < V_354 ; V_129 ++ )
if ( V_355 [ V_129 ] . V_2 . type == V_126 )
return & V_355 [ V_129 ] ;
return NULL ;
}
int F_198 ( struct V_1 * V_2 )
{
struct V_23 * V_383 ;
int V_228 = - V_384 ;
if ( V_2 -> V_62 == 0 )
return - V_341 ;
F_105 ( & V_385 ) ;
V_383 = F_204 ( V_2 ) ;
if ( V_383 ) {
F_205 ( & V_3 , & V_383 -> V_2 ) ;
V_383 -> V_2 . V_16 = V_2 -> V_16 ;
V_383 -> V_2 . V_18 = V_2 -> V_18 ;
V_383 -> V_2 . V_142 = V_2 -> V_142 ;
V_383 -> V_2 . V_237 = V_2 -> V_237 ;
V_383 -> V_2 . V_62 = V_2 -> V_62 ;
V_383 -> V_2 . V_134 = V_2 -> V_134 ;
V_383 -> V_2 . V_14 = V_2 -> V_14 ;
V_383 -> V_2 . V_7 = V_2 -> V_7 ;
V_383 -> V_2 . V_120 = V_2 -> V_120 | V_386 ;
V_383 -> V_2 . V_121 = V_2 -> V_121 ;
V_383 -> V_2 . V_219 = V_2 -> V_219 ;
if ( V_2 -> V_367 )
V_383 -> V_2 . V_367 = V_2 -> V_367 ;
if ( V_2 -> V_120 & V_368 )
F_174 ( V_383 , V_2 -> type ) ;
F_29 ( & V_383 -> V_2 ) ;
if ( V_2 -> V_28 )
V_383 -> V_2 . V_28 = V_2 -> V_28 ;
if ( V_2 -> V_31 )
V_383 -> V_2 . V_31 = V_2 -> V_31 ;
if ( V_2 -> V_328 )
V_383 -> V_2 . V_328 = V_2 -> V_328 ;
if ( V_2 -> V_333 )
V_383 -> V_2 . V_333 = V_2 -> V_333 ;
if ( V_351 != NULL )
V_351 ( 0 , & V_383 -> V_2 ,
& V_383 -> V_45 ) ;
V_228 = F_176 ( & V_3 , & V_383 -> V_2 ) ;
if ( V_228 == 0 )
V_228 = V_383 -> V_2 . line ;
}
F_109 ( & V_385 ) ;
return V_228 ;
}
void F_201 ( int line )
{
struct V_23 * V_383 = & V_355 [ line ] ;
F_105 ( & V_385 ) ;
F_205 ( & V_3 , & V_383 -> V_2 ) ;
if ( V_387 ) {
V_383 -> V_2 . V_120 &= ~ V_386 ;
V_383 -> V_2 . type = V_126 ;
V_383 -> V_2 . V_367 = & V_387 -> V_367 ;
V_383 -> V_45 = V_132 [ V_383 -> V_2 . type ] . V_120 ;
F_176 ( & V_3 , & V_383 -> V_2 ) ;
} else {
V_383 -> V_2 . V_367 = NULL ;
}
F_109 ( & V_385 ) ;
}
static int T_3 F_206 ( void )
{
int V_228 ;
if ( V_354 > V_378 )
V_354 = V_378 ;
F_60 ( V_271 L_28
L_29 , V_354 ,
V_359 ? L_30 : L_31 ) ;
#ifdef F_207
V_228 = F_208 ( & V_3 , V_378 ) ;
#else
V_3 . V_388 = V_378 ;
V_228 = F_209 ( & V_3 ) ;
#endif
if ( V_228 )
goto V_123;
V_387 = F_210 ( L_32 ,
V_389 ) ;
if ( ! V_387 ) {
V_228 = - V_236 ;
goto V_390;
}
V_228 = F_211 ( V_387 ) ;
if ( V_228 )
goto V_391;
F_175 ( & V_3 , & V_387 -> V_367 ) ;
V_228 = F_212 ( & V_392 ) ;
if ( V_228 == 0 )
goto V_123;
F_213 ( V_387 ) ;
V_391:
F_214 ( V_387 ) ;
V_390:
#ifdef F_207
F_215 ( & V_3 , V_378 ) ;
#else
F_216 ( & V_3 ) ;
#endif
V_123:
return V_228 ;
}
static void T_7 F_217 ( void )
{
struct V_380 * V_393 = V_387 ;
V_387 = NULL ;
F_218 ( & V_392 ) ;
F_219 ( V_393 ) ;
#ifdef F_207
F_215 ( & V_3 , V_378 ) ;
#else
F_216 ( & V_3 ) ;
#endif
}
