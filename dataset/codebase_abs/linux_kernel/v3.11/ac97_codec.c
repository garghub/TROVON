static int F_1 ( struct V_1 * V_2 , unsigned short V_3 )
{
switch ( V_2 -> V_4 ) {
case V_5 :
if ( V_3 == 0x08 )
return 0 ;
case V_6 :
if ( V_3 == 0x22 || V_3 == 0x7a )
return 1 ;
case V_7 :
case V_8 :
if ( V_3 <= 0x1c || V_3 == 0x20 || V_3 == 0x26 || V_3 >= 0x7c )
return 1 ;
return 0 ;
case V_9 :
case V_10 :
case V_11 :
if ( V_3 >= 0x3a && V_3 <= 0x6e )
return 0 ;
return 1 ;
case V_12 :
case V_13 :
case V_14 :
case V_15 :
if ( V_3 == 0x5a )
return 1 ;
if ( V_3 >= 0x3c && V_3 <= 0x6e )
return 0 ;
return 1 ;
case V_16 :
case V_17 :
case V_18 :
case V_19 :
case V_20 :
case V_21 :
case V_22 :
if ( V_3 <= 0x3a || V_3 >= 0x5a )
return 1 ;
return 0 ;
}
return 1 ;
}
void F_2 ( struct V_1 * V_2 , unsigned short V_3 , unsigned short V_23 )
{
if ( ! F_1 ( V_2 , V_3 ) )
return;
if ( ( V_2 -> V_4 & 0xffffff00 ) == V_24 ) {
if ( V_3 == V_25 || V_3 == V_26 )
V_2 -> V_27 -> V_28 -> V_29 ( V_2 , V_30 , 0 ) ;
}
V_2 -> V_27 -> V_28 -> V_29 ( V_2 , V_3 , V_23 ) ;
}
unsigned short F_3 ( struct V_1 * V_2 , unsigned short V_3 )
{
if ( ! F_1 ( V_2 , V_3 ) )
return 0 ;
return V_2 -> V_27 -> V_28 -> V_31 ( V_2 , V_3 ) ;
}
static inline unsigned short F_4 ( struct V_1 * V_2 , unsigned short V_3 )
{
if ( ! F_5 ( V_3 , V_2 -> V_32 ) ) {
V_2 -> V_33 [ V_3 ] = V_2 -> V_27 -> V_28 -> V_31 ( V_2 , V_3 ) ;
}
return V_2 -> V_33 [ V_3 ] ;
}
void F_6 ( struct V_1 * V_2 , unsigned short V_3 , unsigned short V_23 )
{
if ( ! F_1 ( V_2 , V_3 ) )
return;
F_7 ( & V_2 -> V_34 ) ;
V_2 -> V_33 [ V_3 ] = V_23 ;
V_2 -> V_27 -> V_28 -> V_29 ( V_2 , V_3 , V_23 ) ;
F_8 ( V_3 , V_2 -> V_32 ) ;
F_9 ( & V_2 -> V_34 ) ;
}
int F_10 ( struct V_1 * V_2 , unsigned short V_3 , unsigned short V_23 )
{
int V_35 ;
if ( ! F_1 ( V_2 , V_3 ) )
return - V_36 ;
F_7 ( & V_2 -> V_34 ) ;
V_35 = V_2 -> V_33 [ V_3 ] != V_23 ;
if ( V_35 ) {
V_2 -> V_33 [ V_3 ] = V_23 ;
V_2 -> V_27 -> V_28 -> V_29 ( V_2 , V_3 , V_23 ) ;
}
F_8 ( V_3 , V_2 -> V_32 ) ;
F_9 ( & V_2 -> V_34 ) ;
return V_35 ;
}
int F_11 ( struct V_1 * V_2 , unsigned short V_3 , unsigned short V_37 , unsigned short V_23 )
{
int V_35 ;
if ( ! F_1 ( V_2 , V_3 ) )
return - V_36 ;
F_7 ( & V_2 -> V_34 ) ;
V_35 = F_12 ( V_2 , V_3 , V_37 , V_23 ) ;
F_9 ( & V_2 -> V_34 ) ;
return V_35 ;
}
int F_12 ( struct V_1 * V_2 , unsigned short V_3 ,
unsigned short V_37 , unsigned short V_23 )
{
int V_35 ;
unsigned short V_38 , V_39 ;
V_38 = F_4 ( V_2 , V_3 ) ;
V_39 = ( V_38 & ~ V_37 ) | ( V_23 & V_37 ) ;
V_35 = V_38 != V_39 ;
if ( V_35 ) {
V_2 -> V_33 [ V_3 ] = V_39 ;
V_2 -> V_27 -> V_28 -> V_29 ( V_2 , V_3 , V_39 ) ;
}
F_8 ( V_3 , V_2 -> V_32 ) ;
return V_35 ;
}
static int F_13 ( struct V_1 * V_2 , int V_40 , unsigned short V_37 , unsigned short V_23 )
{
int V_35 ;
unsigned short V_38 , V_39 , V_41 ;
F_7 ( & V_2 -> V_42 ) ;
V_38 = V_2 -> V_43 . V_44 . V_45 [ V_40 ] ;
V_39 = ( V_38 & ~ V_37 ) | ( V_23 & V_37 ) ;
V_35 = V_38 != V_39 ;
if ( V_35 ) {
F_7 ( & V_2 -> V_34 ) ;
V_41 = F_4 ( V_2 , V_46 ) ;
V_2 -> V_43 . V_44 . V_45 [ V_40 ] = V_39 ;
V_2 -> V_27 -> V_28 -> V_29 ( V_2 , V_46 ,
( V_41 & ~ 0x7000 ) |
V_2 -> V_43 . V_44 . V_47 [ V_40 ] | V_2 -> V_43 . V_44 . V_48 [ V_40 ] ) ;
V_2 -> V_27 -> V_28 -> V_29 ( V_2 , V_49 , V_39 ) ;
V_2 -> V_27 -> V_28 -> V_29 ( V_2 , V_46 ,
V_41 | 0x7000 ) ;
F_9 ( & V_2 -> V_34 ) ;
}
F_9 ( & V_2 -> V_42 ) ;
return V_35 ;
}
static int F_14 ( struct V_50 * V_51 ,
struct V_52 * V_53 )
{
struct V_54 * V_55 = (struct V_54 * ) V_51 -> V_56 ;
V_53 -> type = V_57 ;
V_53 -> V_58 = V_55 -> V_59 == V_55 -> V_60 ? 1 : 2 ;
V_53 -> V_23 . V_61 . V_62 = V_55 -> V_37 ;
if ( V_53 -> V_23 . V_61 . V_63 > V_55 -> V_37 - 1 )
V_53 -> V_23 . V_61 . V_63 = V_55 -> V_37 - 1 ;
strcpy ( V_53 -> V_23 . V_61 . V_64 , V_55 -> V_65 [ V_53 -> V_23 . V_61 . V_63 ] ) ;
return 0 ;
}
static int F_15 ( struct V_50 * V_51 ,
struct V_66 * V_67 )
{
struct V_1 * V_2 = F_16 ( V_51 ) ;
struct V_54 * V_55 = (struct V_54 * ) V_51 -> V_56 ;
unsigned short V_68 , V_69 ;
for ( V_69 = 1 ; V_69 < V_55 -> V_37 ; V_69 <<= 1 )
;
V_68 = F_4 ( V_2 , V_55 -> V_3 ) ;
V_67 -> V_23 . V_61 . V_63 [ 0 ] = ( V_68 >> V_55 -> V_59 ) & ( V_69 - 1 ) ;
if ( V_55 -> V_59 != V_55 -> V_60 )
V_67 -> V_23 . V_61 . V_63 [ 1 ] = ( V_68 >> V_55 -> V_60 ) & ( V_69 - 1 ) ;
return 0 ;
}
static int F_17 ( struct V_50 * V_51 ,
struct V_66 * V_67 )
{
struct V_1 * V_2 = F_16 ( V_51 ) ;
struct V_54 * V_55 = (struct V_54 * ) V_51 -> V_56 ;
unsigned short V_68 ;
unsigned short V_37 , V_69 ;
for ( V_69 = 1 ; V_69 < V_55 -> V_37 ; V_69 <<= 1 )
;
if ( V_67 -> V_23 . V_61 . V_63 [ 0 ] > V_55 -> V_37 - 1 )
return - V_36 ;
V_68 = V_67 -> V_23 . V_61 . V_63 [ 0 ] << V_55 -> V_59 ;
V_37 = ( V_69 - 1 ) << V_55 -> V_59 ;
if ( V_55 -> V_59 != V_55 -> V_60 ) {
if ( V_67 -> V_23 . V_61 . V_63 [ 1 ] > V_55 -> V_37 - 1 )
return - V_36 ;
V_68 |= V_67 -> V_23 . V_61 . V_63 [ 1 ] << V_55 -> V_60 ;
V_37 |= ( V_69 - 1 ) << V_55 -> V_60 ;
}
return F_11 ( V_2 , V_55 -> V_3 , V_37 , V_68 ) ;
}
static int F_18 ( struct V_1 * V_2 , int V_3 , struct V_50 * V_51 )
{
int V_70 = - 1 ;
if ( ( V_51 -> V_56 & ( 1 << 25 ) ) &&
( V_2 -> V_71 & V_72 ) >= V_73 &&
( V_3 >= 0x60 && V_3 < 0x70 ) ) {
unsigned short V_74 = ( V_51 -> V_56 >> 26 ) & 0x0f ;
F_7 ( & V_2 -> V_42 ) ;
V_70 = F_3 ( V_2 , V_75 ) & V_76 ;
F_11 ( V_2 , V_75 , V_76 , V_74 ) ;
}
return V_70 ;
}
static void F_19 ( struct V_1 * V_2 , int V_70 )
{
if ( V_70 >= 0 ) {
F_11 ( V_2 , V_75 , V_76 , V_70 ) ;
F_9 ( & V_2 -> V_42 ) ;
}
}
static int F_20 ( struct V_50 * V_51 ,
struct V_52 * V_53 )
{
int V_37 = ( V_51 -> V_56 >> 16 ) & 0xff ;
int V_77 = ( V_51 -> V_56 >> 8 ) & 0x0f ;
int V_78 = ( V_51 -> V_56 >> 12 ) & 0x0f ;
V_53 -> type = V_37 == 1 ? V_79 : V_80 ;
V_53 -> V_58 = V_77 == V_78 ? 1 : 2 ;
V_53 -> V_23 . integer . V_81 = 0 ;
V_53 -> V_23 . integer . V_82 = V_37 ;
return 0 ;
}
static int F_21 ( struct V_50 * V_51 ,
struct V_66 * V_67 )
{
struct V_1 * V_2 = F_16 ( V_51 ) ;
int V_3 = V_51 -> V_56 & 0xff ;
int V_77 = ( V_51 -> V_56 >> 8 ) & 0x0f ;
int V_78 = ( V_51 -> V_56 >> 12 ) & 0x0f ;
int V_37 = ( V_51 -> V_56 >> 16 ) & 0xff ;
int V_83 = ( V_51 -> V_56 >> 24 ) & 0x01 ;
int V_70 ;
V_70 = F_18 ( V_2 , V_3 , V_51 ) ;
V_67 -> V_23 . integer . V_23 [ 0 ] = ( F_4 ( V_2 , V_3 ) >> V_77 ) & V_37 ;
if ( V_77 != V_78 )
V_67 -> V_23 . integer . V_23 [ 1 ] = ( F_4 ( V_2 , V_3 ) >> V_78 ) & V_37 ;
if ( V_83 ) {
V_67 -> V_23 . integer . V_23 [ 0 ] = V_37 - V_67 -> V_23 . integer . V_23 [ 0 ] ;
if ( V_77 != V_78 )
V_67 -> V_23 . integer . V_23 [ 1 ] = V_37 - V_67 -> V_23 . integer . V_23 [ 1 ] ;
}
F_19 ( V_2 , V_70 ) ;
return 0 ;
}
static int F_22 ( struct V_50 * V_51 ,
struct V_66 * V_67 )
{
struct V_1 * V_2 = F_16 ( V_51 ) ;
int V_3 = V_51 -> V_56 & 0xff ;
int V_77 = ( V_51 -> V_56 >> 8 ) & 0x0f ;
int V_78 = ( V_51 -> V_56 >> 12 ) & 0x0f ;
int V_37 = ( V_51 -> V_56 >> 16 ) & 0xff ;
int V_83 = ( V_51 -> V_56 >> 24 ) & 0x01 ;
int V_84 , V_70 ;
unsigned short V_68 , V_85 , V_86 ;
V_70 = F_18 ( V_2 , V_3 , V_51 ) ;
V_68 = ( V_67 -> V_23 . integer . V_23 [ 0 ] & V_37 ) ;
if ( V_83 )
V_68 = V_37 - V_68 ;
V_86 = V_37 << V_77 ;
V_68 = V_68 << V_77 ;
if ( V_77 != V_78 ) {
V_85 = ( V_67 -> V_23 . integer . V_23 [ 1 ] & V_37 ) ;
if ( V_83 )
V_85 = V_37 - V_85 ;
V_86 |= V_37 << V_78 ;
V_68 |= V_85 << V_78 ;
}
V_84 = F_11 ( V_2 , V_3 , V_86 , V_68 ) ;
F_19 ( V_2 , V_70 ) ;
#ifdef F_23
if ( ( V_86 & V_87 ) &&
( V_51 -> V_56 & ( 1 << 30 ) ) ) {
if ( V_68 & V_87 )
V_2 -> V_88 &= ~ ( 1 << ( V_3 >> 1 ) ) ;
else
V_2 -> V_88 |= 1 << ( V_3 >> 1 ) ;
F_24 ( V_2 ) ;
}
#endif
return V_84 ;
}
static void F_25 ( struct V_1 * V_2 , struct V_50 * V_89 )
{
V_89 -> V_56 = F_26 ( V_90 , 15 , 1 , 0 ) ;
F_11 ( V_2 , V_90 , ( 1 << 15 ) , ( 1 << 15 ) ) ;
V_2 -> V_91 |= V_92 ;
}
static int F_27 ( struct V_50 * V_51 , struct V_52 * V_53 )
{
V_53 -> type = V_93 ;
V_53 -> V_58 = 1 ;
return 0 ;
}
static int F_28 ( struct V_50 * V_51 , struct V_66 * V_67 )
{
V_67 -> V_23 . V_94 . V_95 [ 0 ] = V_96 |
V_97 |
V_98 |
V_99 ;
V_67 -> V_23 . V_94 . V_95 [ 1 ] = V_100 |
V_101 ;
V_67 -> V_23 . V_94 . V_95 [ 3 ] = V_102 ;
return 0 ;
}
static int F_29 ( struct V_50 * V_51 , struct V_66 * V_67 )
{
V_67 -> V_23 . V_94 . V_95 [ 0 ] = V_96 |
V_97 |
V_103 |
V_104 ;
return 0 ;
}
static int F_30 ( struct V_50 * V_51 , struct V_66 * V_67 )
{
struct V_1 * V_2 = F_16 ( V_51 ) ;
F_7 ( & V_2 -> V_34 ) ;
V_67 -> V_23 . V_94 . V_95 [ 0 ] = V_2 -> V_105 & 0xff ;
V_67 -> V_23 . V_94 . V_95 [ 1 ] = ( V_2 -> V_105 >> 8 ) & 0xff ;
V_67 -> V_23 . V_94 . V_95 [ 2 ] = ( V_2 -> V_105 >> 16 ) & 0xff ;
V_67 -> V_23 . V_94 . V_95 [ 3 ] = ( V_2 -> V_105 >> 24 ) & 0xff ;
F_9 ( & V_2 -> V_34 ) ;
return 0 ;
}
static int F_31 ( struct V_50 * V_51 , struct V_66 * V_67 )
{
struct V_1 * V_2 = F_16 ( V_51 ) ;
unsigned int V_39 = 0 ;
unsigned short V_68 = 0 ;
int V_35 ;
V_39 = V_68 = V_67 -> V_23 . V_94 . V_95 [ 0 ] & ( V_96 | V_97 ) ;
if ( V_67 -> V_23 . V_94 . V_95 [ 0 ] & V_96 ) {
V_39 |= V_67 -> V_23 . V_94 . V_95 [ 0 ] & ( V_103 | V_104 ) ;
switch ( V_39 & V_103 ) {
case V_106 : V_68 |= 0 << 12 ; break;
case V_107 : V_68 |= 2 << 12 ; break;
case V_108 : V_68 |= 3 << 12 ; break;
default: V_68 |= 1 << 12 ; break;
}
if ( ( V_39 & V_109 ) == V_104 )
V_68 |= 1 << 3 ;
} else {
V_39 |= V_67 -> V_23 . V_94 . V_95 [ 0 ] & ( V_98 | V_99 ) ;
V_39 |= ( ( V_67 -> V_23 . V_94 . V_95 [ 1 ] & ( V_100 | V_101 ) ) << 8 ) ;
V_39 |= ( ( V_67 -> V_23 . V_94 . V_95 [ 3 ] & V_102 ) << 24 ) ;
if ( ( V_39 & V_110 ) == V_98 )
V_68 |= 1 << 3 ;
if ( ! ( V_39 & V_99 ) )
V_68 |= 1 << 2 ;
V_68 |= ( ( V_39 >> 8 ) & 0xff ) << 4 ;
switch ( ( V_39 >> 24 ) & 0xff ) {
case V_111 : V_68 |= 0 << 12 ; break;
case V_112 : V_68 |= 2 << 12 ; break;
case V_113 : V_68 |= 3 << 12 ; break;
default: V_68 |= 1 << 12 ; break;
}
}
F_7 ( & V_2 -> V_34 ) ;
V_35 = V_2 -> V_105 != V_39 ;
V_2 -> V_105 = V_39 ;
if ( V_2 -> V_114 & V_115 ) {
int V_116 = ( V_68 >> 12 ) & 0x03 ;
switch ( V_116 ) {
case 0 : V_116 = 1 ; break;
case 2 : V_116 = 0 ; break;
default: V_116 = 0 ; break;
}
V_35 |= F_12 ( V_2 , V_117 , 0x3fff , ( ( V_68 & 0xcfff ) | ( V_116 << 12 ) ) ) ;
} else if ( V_2 -> V_114 & V_118 ) {
int V_119 ;
V_119 = V_39 & ( V_98 | V_99 ) ? 0 : V_120 ;
V_119 |= V_39 & V_97 ? V_121 : V_122 ;
V_35 |= F_12 ( V_2 , V_123 ,
V_124 | V_120 ,
V_119 ) ;
} else if ( V_2 -> V_4 == V_125 ) {
V_35 |= F_12 ( V_2 ,
V_126 ,
0xff38 ,
( ( V_68 << 4 ) & 0xff00 ) |
( ( V_68 << 2 ) & 0x0038 ) ) ;
} else {
unsigned short V_127 = F_4 ( V_2 , V_128 ) ;
F_12 ( V_2 , V_128 , V_129 , 0 ) ;
V_35 |= F_12 ( V_2 , V_130 , 0x3fff , V_68 ) ;
if ( V_127 & V_129 ) {
F_12 ( V_2 , V_128 , V_129 , V_129 ) ;
}
}
F_9 ( & V_2 -> V_34 ) ;
return V_35 ;
}
static int F_32 ( struct V_50 * V_51 , struct V_66 * V_67 )
{
struct V_1 * V_2 = F_16 ( V_51 ) ;
int V_3 = V_51 -> V_56 & 0xff ;
int V_77 = ( V_51 -> V_56 >> 8 ) & 0xff ;
int V_37 = ( V_51 -> V_56 >> 16 ) & 0xff ;
unsigned short V_23 , V_38 , V_39 ;
int V_35 ;
V_23 = ( V_67 -> V_23 . integer . V_23 [ 0 ] & V_37 ) ;
F_7 ( & V_2 -> V_34 ) ;
V_37 <<= V_77 ;
V_23 <<= V_77 ;
V_38 = F_4 ( V_2 , V_3 ) ;
V_39 = ( V_38 & ~ V_37 ) | V_23 ;
V_35 = V_38 != V_39 ;
if ( V_35 ) {
unsigned short V_127 = F_4 ( V_2 , V_128 ) ;
F_12 ( V_2 , V_128 , V_129 , 0 ) ;
V_35 = F_12 ( V_2 , V_3 , V_37 , V_23 ) ;
if ( V_127 & V_129 )
F_12 ( V_2 , V_128 , V_129 , V_129 ) ;
}
F_9 ( & V_2 -> V_34 ) ;
return V_35 ;
}
static int F_33 ( struct V_50 * V_51 , struct V_52 * V_53 )
{
struct V_1 * V_2 = F_16 ( V_51 ) ;
int V_37 = ( V_51 -> V_56 >> 16 ) & 0x0f ;
int V_131 = ( V_51 -> V_56 >> 8 ) & 0x0f ;
int V_78 = ( V_51 -> V_56 >> 12 ) & 0x0f ;
V_53 -> type = V_37 == 1 ? V_79 : V_80 ;
if ( V_131 != V_78 && ( V_2 -> V_114 & V_132 ) )
V_53 -> V_58 = 2 ;
else
V_53 -> V_58 = 1 ;
V_53 -> V_23 . integer . V_81 = 0 ;
V_53 -> V_23 . integer . V_82 = V_37 ;
return 0 ;
}
static int F_34 ( struct V_50 * V_51 , struct V_66 * V_67 )
{
struct V_1 * V_2 = F_16 ( V_51 ) ;
int V_40 = V_51 -> V_56 & 3 ;
int V_131 = ( V_51 -> V_56 >> 8 ) & 0x0f ;
int V_78 = ( V_51 -> V_56 >> 12 ) & 0x0f ;
int V_37 = ( V_51 -> V_56 >> 16 ) & 0xff ;
V_67 -> V_23 . integer . V_23 [ 0 ] = V_37 - ( ( V_2 -> V_43 . V_44 . V_45 [ V_40 ] >> V_131 ) & V_37 ) ;
if ( V_131 != V_78 && ( V_2 -> V_114 & V_132 ) )
V_67 -> V_23 . integer . V_23 [ 1 ] = V_37 - ( ( V_2 -> V_43 . V_44 . V_45 [ V_40 ] >> V_78 ) & V_37 ) ;
return 0 ;
}
static int F_35 ( struct V_50 * V_51 , struct V_66 * V_67 )
{
struct V_1 * V_2 = F_16 ( V_51 ) ;
int V_40 = V_51 -> V_56 & 3 ;
int V_131 = ( V_51 -> V_56 >> 8 ) & 0x0f ;
int V_78 = ( V_51 -> V_56 >> 12 ) & 0x0f ;
int V_37 = ( V_51 -> V_56 >> 16 ) & 0xff ;
unsigned short V_68 , V_133 ;
V_68 = ( V_37 - ( V_67 -> V_23 . integer . V_23 [ 0 ] & V_37 ) ) << V_131 ;
V_133 = V_37 << V_131 ;
if ( V_131 != V_78 && ( V_2 -> V_114 & V_132 ) ) {
V_68 |= ( V_37 - ( V_67 -> V_23 . integer . V_23 [ 1 ] & V_37 ) ) << V_78 ;
V_133 |= V_37 << V_78 ;
}
return F_13 ( V_2 , V_40 , V_133 , V_68 ) ;
}
static int F_36 ( struct V_50 * V_51 , struct V_52 * V_53 )
{
V_53 -> type = V_80 ;
V_53 -> V_58 = 2 ;
V_53 -> V_23 . integer . V_81 = 0 ;
V_53 -> V_23 . integer . V_82 = 31 ;
return 0 ;
}
static int F_37 ( struct V_50 * V_51 , struct V_66 * V_67 )
{
struct V_1 * V_2 = F_16 ( V_51 ) ;
int V_40 = V_51 -> V_56 & 3 ;
F_7 ( & V_2 -> V_42 ) ;
V_67 -> V_23 . integer . V_23 [ 0 ] = 31 - ( ( V_2 -> V_43 . V_44 . V_45 [ V_40 ] >> 0 ) & 31 ) ;
V_67 -> V_23 . integer . V_23 [ 1 ] = 31 - ( ( V_2 -> V_43 . V_44 . V_45 [ V_40 ] >> 8 ) & 31 ) ;
F_9 ( & V_2 -> V_42 ) ;
return 0 ;
}
static int F_38 ( struct V_50 * V_51 , struct V_66 * V_67 )
{
struct V_1 * V_2 = F_16 ( V_51 ) ;
int V_40 = V_51 -> V_56 & 3 ;
unsigned short V_134 , V_85 ;
V_134 = 31 - ( V_67 -> V_23 . integer . V_23 [ 0 ] & 31 ) ;
V_85 = 31 - ( V_67 -> V_23 . integer . V_23 [ 1 ] & 31 ) ;
return F_13 ( V_2 , V_40 , 0x1f1f , ( V_134 << 8 ) | V_85 ) ;
}
static int F_39 ( struct V_135 * V_27 )
{
if ( V_27 ) {
F_40 ( V_27 ) ;
F_41 ( V_27 -> V_136 ) ;
if ( V_27 -> V_137 )
V_27 -> V_137 ( V_27 ) ;
F_41 ( V_27 ) ;
}
return 0 ;
}
static int F_42 ( struct V_138 * V_139 )
{
struct V_135 * V_27 = V_139 -> V_140 ;
return F_39 ( V_27 ) ;
}
static int F_43 ( struct V_1 * V_2 )
{
if ( V_2 ) {
#ifdef F_23
F_44 ( & V_2 -> V_141 ) ;
#endif
F_45 ( V_2 ) ;
if ( V_2 -> V_27 )
V_2 -> V_27 -> V_40 [ V_2 -> V_142 ] = NULL ;
if ( V_2 -> V_137 )
V_2 -> V_137 ( V_2 ) ;
F_41 ( V_2 ) ;
}
return 0 ;
}
static int F_46 ( struct V_138 * V_139 )
{
struct V_1 * V_2 = V_139 -> V_140 ;
F_47 ( V_2 ) ;
return F_43 ( V_2 ) ;
}
static int F_48 ( struct V_1 * V_2 , int V_3 )
{
unsigned short V_68 , V_37 = V_143 ;
if ( ! F_1 ( V_2 , V_3 ) )
return 0 ;
switch ( V_3 ) {
case V_144 :
return V_2 -> V_145 & V_146 ? 1 : 0 ;
case V_26 :
return V_2 -> V_145 & V_147 ? 1 : 0 ;
case V_148 :
return V_2 -> V_145 & V_149 ? 1 : 0 ;
case V_150 :
if ( V_2 -> V_145 & V_151 ) {
V_68 = F_3 ( V_2 , V_3 ) ;
return V_68 == 0 ;
}
return 0 ;
case V_152 :
if ( ( V_2 -> V_71 & V_153 ) == 0 )
return 0 ;
break;
case V_152 + 1 :
if ( ( V_2 -> V_71 & V_154 ) == 0 )
return 0 ;
V_3 = V_152 ;
V_37 = 0x0080 ;
break;
case V_155 :
if ( ( V_2 -> V_71 & V_156 ) == 0 )
return 0 ;
break;
}
V_68 = F_3 ( V_2 , V_3 ) ;
if ( ! ( V_68 & V_37 ) ) {
F_6 ( V_2 , V_3 , V_68 | V_37 ) ;
V_68 = F_3 ( V_2 , V_3 ) ;
V_68 = F_3 ( V_2 , V_3 ) ;
if ( ! ( V_68 & V_37 ) )
return 0 ;
}
return 1 ;
}
static void F_49 ( struct V_1 * V_2 , int V_3 , unsigned char * V_157 , unsigned char * V_158 )
{
unsigned short V_159 [ 3 ] = { 0x20 , 0x10 , 0x01 } ;
unsigned char V_82 [ 3 ] = { 63 , 31 , 15 } ;
int V_160 ;
if ( V_2 -> V_161 ) {
const struct V_162 * V_163 ;
for ( V_163 = V_2 -> V_161 ; V_163 -> V_3 ; V_163 ++ ) {
if ( V_163 -> V_3 == V_3 ) {
* V_157 = V_163 -> V_164 & 0xff ;
* V_158 = ( V_163 -> V_164 >> 8 ) & 0xff ;
return;
}
}
}
* V_157 = * V_158 = 0 ;
for ( V_160 = 0 ; V_160 < F_50 ( V_159 ) ; V_160 ++ ) {
unsigned short V_68 ;
F_2 (
V_2 , V_3 ,
V_165 | V_159 [ V_160 ] | ( V_159 [ V_160 ] << 8 )
) ;
V_68 = F_3 ( V_2 , V_3 ) ;
V_68 = F_3 ( V_2 , V_3 ) ;
if ( ! * V_157 && ( V_68 & 0x7f ) == V_159 [ V_160 ] )
* V_157 = V_82 [ V_160 ] ;
if ( ! * V_158 && ( ( V_68 >> 8 ) & 0x7f ) == V_159 [ V_160 ] )
* V_158 = V_82 [ V_160 ] ;
if ( * V_157 && * V_158 )
break;
}
}
static int F_51 ( struct V_1 * V_2 , int V_3 , int V_166 )
{
unsigned short V_37 , V_68 , V_167 , V_168 ;
V_37 = 1 << V_166 ;
V_167 = F_3 ( V_2 , V_3 ) ;
V_68 = V_167 ^ V_37 ;
F_2 ( V_2 , V_3 , V_68 ) ;
V_168 = F_3 ( V_2 , V_3 ) ;
F_6 ( V_2 , V_3 , V_167 ) ;
return V_168 == V_68 ;
}
static void F_52 ( struct V_1 * V_2 , int V_3 , int V_77 , unsigned char * V_82 )
{
unsigned short V_68 , V_134 ;
* V_82 = 63 ;
V_68 = V_165 | ( 0x20 << V_77 ) ;
F_2 ( V_2 , V_3 , V_68 ) ;
V_134 = F_3 ( V_2 , V_3 ) ;
if ( V_68 != V_134 ) {
* V_82 = 31 ;
}
F_6 ( V_2 , V_3 , V_165 ) ;
}
static inline int F_53 ( unsigned int V_116 )
{
V_116 &= 0xff ;
if ( V_116 < ' ' || V_116 >= 0x71 ) {
if ( V_116 <= 0x89 )
return V_116 - 0x71 + 'A' ;
return '?' ;
}
return V_116 ;
}
static struct V_50 * F_54 ( const struct V_169 * V_170 ,
struct V_1 * V_2 )
{
struct V_169 V_171 ;
memcpy ( & V_171 , V_170 , sizeof( V_171 ) ) ;
V_171 . V_172 = V_2 -> V_142 ;
return F_55 ( & V_171 , V_2 ) ;
}
static int F_56 ( struct V_173 * V_174 , char * V_64 , int V_3 ,
int V_175 , int V_176 ,
struct V_1 * V_2 )
{
struct V_50 * V_89 ;
int V_84 ;
unsigned short V_68 , V_134 , V_177 ;
if ( ! F_1 ( V_2 , V_3 ) )
return 0 ;
V_177 = V_143 ;
V_68 = F_3 ( V_2 , V_3 ) ;
if ( V_175 || ( V_2 -> V_114 & V_132 ) ) {
V_134 = V_68 | V_165 ;
F_2 ( V_2 , V_3 , V_134 ) ;
if ( V_134 == F_3 ( V_2 , V_3 ) )
V_177 = V_165 ;
}
if ( V_177 == V_165 ) {
struct V_169 V_178 = F_57 ( V_64 , V_3 , 15 , 7 , 1 , 1 ) ;
if ( V_176 )
V_178 . V_56 |= ( 1 << 30 ) ;
V_178 . V_172 = V_2 -> V_142 ;
V_89 = F_55 ( & V_178 , V_2 ) ;
} else {
struct V_169 V_178 = F_58 ( V_64 , V_3 , 15 , 1 , 1 ) ;
if ( V_176 )
V_178 . V_56 |= ( 1 << 30 ) ;
V_178 . V_172 = V_2 -> V_142 ;
V_89 = F_55 ( & V_178 , V_2 ) ;
}
V_84 = F_59 ( V_174 , V_89 ) ;
if ( V_84 < 0 )
return V_84 ;
F_6 ( V_2 , V_3 , V_68 | V_177 ) ;
return 0 ;
}
static const unsigned int * F_60 ( unsigned int V_179 )
{
switch ( V_179 ) {
case 0x0f : return V_180 ;
case 0x1f : return V_181 ;
case 0x3f : return V_182 ;
}
return NULL ;
}
static void F_61 ( struct V_50 * V_89 , const unsigned int * V_183 )
{
V_89 -> V_183 . V_184 = V_183 ;
if ( V_183 )
V_89 -> V_185 [ 0 ] . V_186 |= V_187 ;
}
static int F_62 ( struct V_173 * V_174 , char * V_64 , int V_3 , unsigned int V_157 ,
unsigned int V_158 , struct V_1 * V_2 )
{
int V_84 ;
struct V_50 * V_89 ;
if ( ! F_1 ( V_2 , V_3 ) )
return 0 ;
if ( V_158 ) {
struct V_169 V_178 = F_57 ( V_64 , V_3 , 8 , 0 , V_157 , 1 ) ;
V_178 . V_172 = V_2 -> V_142 ;
V_89 = F_55 ( & V_178 , V_2 ) ;
} else {
struct V_169 V_178 = F_58 ( V_64 , V_3 , 0 , V_157 , 1 ) ;
V_178 . V_172 = V_2 -> V_142 ;
V_89 = F_55 ( & V_178 , V_2 ) ;
}
if ( ! V_89 )
return - V_188 ;
if ( V_3 >= V_189 && V_3 <= V_49 )
F_61 ( V_89 , V_190 ) ;
else
F_61 ( V_89 , F_60 ( V_157 ) ) ;
V_84 = F_59 ( V_174 , V_89 ) ;
if ( V_84 < 0 )
return V_84 ;
F_6 (
V_2 , V_3 ,
( F_3 ( V_2 , V_3 ) & V_165 )
| V_157 | ( V_158 << 8 )
) ;
return 0 ;
}
static int F_63 ( struct V_173 * V_174 , const char * V_191 ,
int V_3 , int V_175 , int V_176 ,
struct V_1 * V_2 )
{
int V_84 ;
char V_64 [ V_192 ] ;
unsigned char V_157 , V_158 ;
if ( ! F_1 ( V_2 , V_3 ) )
return 0 ;
if ( F_51 ( V_2 , V_3 , 15 ) ) {
sprintf ( V_64 , L_1 , V_191 ) ;
if ( ( V_84 = F_56 ( V_174 , V_64 , V_3 ,
V_175 , V_176 ,
V_2 ) ) < 0 )
return V_84 ;
}
F_49 ( V_2 , V_3 , & V_157 , & V_158 ) ;
if ( V_157 ) {
sprintf ( V_64 , L_2 , V_191 ) ;
if ( ( V_84 = F_62 ( V_174 , V_64 , V_3 , V_157 , V_158 , V_2 ) ) < 0 )
return V_84 ;
}
return 0 ;
}
static int F_64 ( struct V_1 * V_2 )
{
struct V_173 * V_174 = V_2 -> V_27 -> V_174 ;
struct V_50 * V_89 ;
int V_84 ;
unsigned int V_193 ;
unsigned char V_82 ;
if ( F_48 ( V_2 , V_25 ) ) {
if ( V_2 -> V_114 & V_194 )
V_84 = F_65 ( V_174 , L_3 ,
V_25 , 0 , V_2 ) ;
else
V_84 = F_66 ( V_174 , L_4 ,
V_25 , 0 , V_2 ) ;
if ( V_84 < 0 )
return V_84 ;
}
V_2 -> V_33 [ V_152 ] = V_165 ;
if ( ( F_48 ( V_2 , V_152 ) )
&& ! ( V_2 -> V_114 & V_195 ) ) {
if ( ( V_84 = F_59 ( V_174 , F_54 ( & V_196 [ 0 ] , V_2 ) ) ) < 0 )
return V_84 ;
if ( ( V_84 = F_59 ( V_174 , V_89 = F_54 ( & V_196 [ 1 ] , V_2 ) ) ) < 0 )
return V_84 ;
F_52 ( V_2 , V_152 , 0 , & V_82 ) ;
V_89 -> V_56 &= ~ ( 0xff << 16 ) ;
V_89 -> V_56 |= ( int ) V_82 << 16 ;
F_61 ( V_89 , F_60 ( V_82 ) ) ;
F_6 ( V_2 , V_152 , V_2 -> V_33 [ V_152 ] | V_82 ) ;
}
if ( ( F_48 ( V_2 , V_152 + 1 ) )
&& ! ( V_2 -> V_114 & V_195 ) ) {
if ( ( V_84 = F_59 ( V_174 , F_54 ( & V_197 [ 0 ] , V_2 ) ) ) < 0 )
return V_84 ;
if ( ( V_84 = F_59 ( V_174 , V_89 = F_54 ( & V_197 [ 1 ] , V_2 ) ) ) < 0 )
return V_84 ;
F_52 ( V_2 , V_152 , 8 , & V_82 ) ;
V_89 -> V_56 &= ~ ( 0xff << 16 ) ;
V_89 -> V_56 |= ( int ) V_82 << 16 ;
F_61 ( V_89 , F_60 ( V_82 ) ) ;
F_6 ( V_2 , V_152 , V_2 -> V_33 [ V_152 ] | V_82 << 8 ) ;
}
if ( ( F_48 ( V_2 , V_155 ) )
&& ! ( V_2 -> V_114 & V_195 ) ) {
if ( ( V_84 = F_63 ( V_174 , L_5 ,
V_155 , 1 , 0 ,
V_2 ) ) < 0 )
return V_84 ;
}
if ( F_48 ( V_2 , V_26 ) ) {
if ( ( V_84 = F_66 ( V_174 , L_6 ,
V_26 , 0 , V_2 ) ) < 0 )
return V_84 ;
}
if ( F_48 ( V_2 , V_198 ) ) {
if ( ( V_84 = F_66 ( V_174 , L_7 ,
V_198 , 0 , V_2 ) ) < 0 )
return V_84 ;
}
if ( ! ( V_2 -> V_114 & V_199 ) ) {
if ( F_48 ( V_2 , V_144 ) ) {
for ( V_193 = 0 ; V_193 < 2 ; V_193 ++ ) {
if ( ( V_84 = F_59 ( V_174 , V_89 = F_54 ( & V_200 [ V_193 ] , V_2 ) ) ) < 0 )
return V_84 ;
if ( V_2 -> V_4 == V_125 ||
V_2 -> V_4 == V_201 ) {
V_89 -> V_56 &= ~ ( 0xff << 16 ) ;
V_89 -> V_56 |= 7 << 16 ;
}
}
F_6 ( V_2 , V_144 , 0x0f0f ) ;
}
}
if ( ! ( V_2 -> V_114 & V_202 ) &&
( ( V_2 -> V_114 & V_203 ) ||
F_48 ( V_2 , V_204 ) ) ) {
for ( V_193 = 0 ; V_193 < 2 ; V_193 ++ )
if ( ( V_84 = F_59 ( V_174 , V_89 = F_54 ( & V_205 [ V_193 ] , V_2 ) ) ) < 0 )
return V_84 ;
F_61 ( V_89 , V_180 ) ;
F_6 (
V_2 ,
V_204 ,
( F_3 ( V_2 , V_204 )
| V_143 | 0x001e )
) ;
}
if ( ! ( V_2 -> V_114 & V_206 ) ) {
if ( F_48 ( V_2 , V_189 ) ) {
if ( ( V_84 = F_66 ( V_174 , L_8 ,
V_189 , 1 , V_2 ) ) < 0 )
return V_84 ;
}
}
if ( ! ( V_2 -> V_114 & V_207 ) ) {
if ( F_48 ( V_2 , V_208 ) ) {
if ( ( V_84 = F_66 ( V_174 , L_9 ,
V_208 , 1 , V_2 ) ) < 0 )
return V_84 ;
if ( ( V_84 = F_59 ( V_174 , F_54 ( & V_209 , V_2 ) ) ) < 0 )
return V_84 ;
}
}
if ( F_48 ( V_2 , V_210 ) ) {
if ( ( V_84 = F_66 ( V_174 , L_10 ,
V_210 , 1 , V_2 ) ) < 0 )
return V_84 ;
}
if ( ! ( V_2 -> V_114 & V_211 ) ) {
if ( F_48 ( V_2 , V_212 ) ) {
if ( ( V_84 = F_66 ( V_174 , L_11 ,
V_212 , 1 , V_2 ) ) < 0 )
return V_84 ;
}
}
if ( ! ( V_2 -> V_114 & V_213 ) ) {
if ( F_48 ( V_2 , V_214 ) ) {
if ( ( V_84 = F_66 ( V_174 , L_12 ,
V_214 , 1 , V_2 ) ) < 0 )
return V_84 ;
}
}
if ( ! ( V_2 -> V_114 & V_215 ) ) {
if ( F_48 ( V_2 , V_216 ) ) {
if ( ( V_84 = F_66 ( V_174 , L_13 ,
V_216 , 1 , V_2 ) ) < 0 )
return V_84 ;
}
}
if ( V_2 -> V_114 & V_195 ) {
unsigned short V_217 ;
if ( V_2 -> V_114 & V_132 )
V_217 = 0x9f9f ;
else
V_217 = 0x9f1f ;
for ( V_193 = 0 ; V_193 < 2 ; V_193 ++ )
if ( ( V_84 = F_59 ( V_174 , V_89 = F_54 ( & V_218 [ V_193 ] , V_2 ) ) ) < 0 )
return V_84 ;
F_61 ( V_89 , V_181 ) ;
V_2 -> V_43 . V_44 . V_45 [ 0 ] = V_217 ;
if ( V_2 -> V_91 & V_219 ) {
for ( V_193 = 0 ; V_193 < 2 ; V_193 ++ )
if ( ( V_84 = F_59 ( V_174 , V_89 = F_54 ( & V_220 [ V_193 ] , V_2 ) ) ) < 0 )
return V_84 ;
F_61 ( V_89 , V_181 ) ;
V_2 -> V_43 . V_44 . V_45 [ 1 ] = V_217 ;
}
if ( V_2 -> V_91 & V_221 ) {
for ( V_193 = 0 ; V_193 < 2 ; V_193 ++ )
if ( ( V_84 = F_59 ( V_174 , V_89 = F_54 ( & V_222 [ V_193 ] , V_2 ) ) ) < 0 )
return V_84 ;
F_61 ( V_89 , V_181 ) ;
for ( V_193 = 0 ; V_193 < 2 ; V_193 ++ )
if ( ( V_84 = F_59 ( V_174 , V_89 = F_54 ( & V_223 [ V_193 ] , V_2 ) ) ) < 0 )
return V_84 ;
F_61 ( V_89 , V_181 ) ;
V_2 -> V_43 . V_44 . V_45 [ 2 ] = V_217 ;
}
F_6 ( V_2 , V_49 , V_217 ) ;
} else {
if ( ! ( V_2 -> V_114 & V_224 ) ) {
if ( V_2 -> V_114 & V_225 )
V_84 = F_65 ( V_174 ,
L_14 ,
V_49 , 0 , V_2 ) ;
else
V_84 = F_66 ( V_174 , L_15 ,
V_49 , 0 , V_2 ) ;
if ( V_84 < 0 )
return V_84 ;
}
}
if ( ! ( V_2 -> V_114 & V_226 ) ) {
if ( ( V_84 = F_59 ( V_174 , F_54 ( & V_227 , V_2 ) ) ) < 0 )
return V_84 ;
if ( F_51 ( V_2 , V_228 , 15 ) ) {
V_84 = F_65 ( V_174 , L_16 ,
V_228 , 0 , V_2 ) ;
if ( V_84 < 0 )
return V_84 ;
}
if ( ( V_84 = F_59 ( V_174 , V_89 = F_54 ( & V_229 , V_2 ) ) ) < 0 )
return V_84 ;
F_61 ( V_89 , V_230 ) ;
F_6 ( V_2 , V_231 , 0x0000 ) ;
F_6 ( V_2 , V_228 , 0x0000 ) ;
}
if ( F_48 ( V_2 , V_148 ) ) {
for ( V_193 = 0 ; V_193 < 2 ; V_193 ++ )
if ( ( V_84 = F_59 ( V_174 , V_89 = F_54 ( & V_232 [ V_193 ] , V_2 ) ) ) < 0 )
return V_84 ;
F_61 ( V_89 , V_230 ) ;
F_6 ( V_2 , V_148 , 0x0000 ) ;
}
if ( F_51 ( V_2 , V_233 , 15 ) ) {
if ( ( V_84 = F_59 ( V_174 , F_54 ( & V_234 [ V_235 ] , V_2 ) ) ) < 0 )
return V_84 ;
}
if ( V_2 -> V_145 & V_236 ) {
if ( ( V_84 = F_59 ( V_174 , F_54 ( & V_234 [ V_237 ] , V_2 ) ) ) < 0 )
return V_84 ;
}
if ( F_51 ( V_2 , V_233 , 13 ) ) {
if ( ( V_84 = F_59 ( V_174 , F_54 ( & V_234 [ V_238 ] , V_2 ) ) ) < 0 )
return V_84 ;
}
if ( V_2 -> V_145 & V_239 ) {
if ( ( V_84 = F_59 ( V_174 , F_54 ( & V_234 [ V_240 ] , V_2 ) ) ) < 0 )
return V_84 ;
}
if ( F_51 ( V_2 , V_233 , 9 ) ) {
if ( ( V_84 = F_59 ( V_174 , F_54 ( & V_234 [ V_241 ] , V_2 ) ) ) < 0 )
return V_84 ;
}
if ( F_51 ( V_2 , V_233 , 8 ) ) {
if ( ( V_84 = F_59 ( V_174 , F_54 ( & V_234 [ V_242 ] , V_2 ) ) ) < 0 )
return V_84 ;
}
if ( V_243 && F_51 ( V_2 , V_233 , 7 ) ) {
if ( ( V_84 = F_59 ( V_174 , F_54 ( & V_234 [ V_244 ] , V_2 ) ) ) < 0 )
return V_84 ;
}
F_11 ( V_2 , V_233 , ~ V_245 , 0x0000 ) ;
if ( V_2 -> V_246 -> V_247 ) {
V_2 -> V_246 -> V_247 ( V_2 ) ;
} else {
if ( F_48 ( V_2 , V_150 ) ) {
unsigned short V_68 ;
V_68 = 0x0707 ;
F_2 ( V_2 , V_150 , V_68 ) ;
V_68 = F_3 ( V_2 , V_150 ) ;
V_68 = V_68 == 0x0606 ;
if ( ( V_84 = F_59 ( V_174 , V_89 = F_54 ( & V_248 [ 0 ] , V_2 ) ) ) < 0 )
return V_84 ;
if ( V_68 )
V_89 -> V_56 = V_150 | ( 9 << 8 ) | ( 7 << 16 ) ;
if ( ( V_84 = F_59 ( V_174 , V_89 = F_54 ( & V_248 [ 1 ] , V_2 ) ) ) < 0 )
return V_84 ;
if ( V_68 )
V_89 -> V_56 = V_150 | ( 1 << 8 ) | ( 7 << 16 ) ;
F_6 ( V_2 , V_150 , 0x0000 ) ;
}
}
if ( V_2 -> V_249 == 0x1043 &&
V_2 -> V_250 == 0x810f )
V_2 -> V_71 |= V_251 ;
if ( ( V_2 -> V_71 & V_251 ) && ! ( V_2 -> V_91 & V_252 ) ) {
if ( V_2 -> V_246 -> V_253 ) {
if ( ( V_84 = V_2 -> V_246 -> V_253 ( V_2 ) ) < 0 )
return V_84 ;
} else {
for ( V_193 = 0 ; V_193 < 5 ; V_193 ++ )
if ( ( V_84 = F_59 ( V_174 , F_54 ( & V_254 [ V_193 ] , V_2 ) ) ) < 0 )
return V_84 ;
if ( V_2 -> V_246 -> V_255 ) {
if ( ( V_84 = V_2 -> V_246 -> V_255 ( V_2 ) ) < 0 )
return V_84 ;
}
F_6 ( V_2 , V_130 , 0x2a20 ) ;
V_2 -> V_256 [ V_257 ] = F_67 ( V_2 ) ;
}
V_2 -> V_105 = V_258 ;
}
if ( V_2 -> V_246 -> V_259 )
if ( ( V_84 = V_2 -> V_246 -> V_259 ( V_2 ) ) < 0 )
return V_84 ;
if ( F_51 ( V_2 , V_90 , 15 ) ) {
V_89 = F_54 ( & V_260 , V_2 ) ;
if ( ! V_89 )
return - V_188 ;
if ( V_2 -> V_91 & V_92 )
F_25 ( V_2 , V_89 ) ;
if ( ( V_84 = F_59 ( V_174 , V_89 ) ) < 0 )
return V_84 ;
}
return 0 ;
}
static int F_68 ( struct V_173 * V_174 , struct V_1 * V_2 )
{
int V_84 , V_193 ;
F_2 ( V_2 , V_261 , 0xffff & ~ ( V_262 ) ) ;
F_2 ( V_2 , V_263 , 0xffff & ~ ( V_262 ) ) ;
F_2 ( V_2 , V_264 , 0xffff ) ;
F_2 ( V_2 , V_265 , 0x0 ) ;
F_2 ( V_2 , V_266 , 0x0 ) ;
for ( V_193 = 0 ; V_193 < F_50 ( V_267 ) ; V_193 ++ )
if ( ( V_84 = F_59 ( V_174 , F_55 ( & V_267 [ V_193 ] , V_2 ) ) ) < 0 )
return V_84 ;
if ( V_2 -> V_246 -> V_259 )
if ( ( V_84 = V_2 -> V_246 -> V_259 ( V_2 ) ) < 0 )
return V_84 ;
return 0 ;
}
static int F_69 ( struct V_1 * V_2 , int V_3 , int V_268 , int V_269 )
{
unsigned short V_68 ;
unsigned int V_178 ;
V_178 = ( ( unsigned int ) V_269 * V_2 -> V_27 -> clock ) / 48000 ;
F_6 ( V_2 , V_3 , V_178 & 0xffff ) ;
if ( V_268 )
F_6 ( V_2 , V_268 , V_178 & 0xffff ) ;
V_68 = F_3 ( V_2 , V_3 ) ;
return V_68 == ( V_178 & 0xffff ) ;
}
static void F_70 ( struct V_1 * V_2 , int V_3 , int V_268 , unsigned int * V_270 )
{
unsigned int V_271 = 0 ;
unsigned short V_272 ;
if ( V_2 -> V_27 -> V_273 ) {
* V_270 = V_274 ;
if ( ( V_2 -> V_114 & V_275 ) &&
V_3 == V_276 )
* V_270 |= V_277 ;
return;
}
V_272 = F_3 ( V_2 , V_3 ) ;
if ( ( V_2 -> V_71 & V_278 ) && V_3 == V_276 )
F_11 ( V_2 , V_128 ,
V_279 , 0 ) ;
if ( F_69 ( V_2 , V_3 , V_268 , 11000 ) )
V_271 |= V_280 ;
if ( F_69 ( V_2 , V_3 , V_268 , 8000 ) )
V_271 |= V_281 ;
if ( F_69 ( V_2 , V_3 , V_268 , 11025 ) )
V_271 |= V_282 ;
if ( F_69 ( V_2 , V_3 , V_268 , 16000 ) )
V_271 |= V_283 ;
if ( F_69 ( V_2 , V_3 , V_268 , 22050 ) )
V_271 |= V_284 ;
if ( F_69 ( V_2 , V_3 , V_268 , 32000 ) )
V_271 |= V_285 ;
if ( F_69 ( V_2 , V_3 , V_268 , 44100 ) )
V_271 |= V_286 ;
if ( F_69 ( V_2 , V_3 , V_268 , 48000 ) )
V_271 |= V_274 ;
if ( ( V_2 -> V_114 & V_275 ) &&
V_3 == V_276 ) {
F_11 ( V_2 , V_128 ,
V_279 , V_279 ) ;
if ( F_69 ( V_2 , V_3 , V_268 , 64000 / 2 ) )
V_271 |= V_287 ;
if ( F_69 ( V_2 , V_3 , V_268 , 88200 / 2 ) )
V_271 |= V_288 ;
if ( F_69 ( V_2 , V_3 , V_268 , 96000 / 2 ) )
V_271 |= V_277 ;
if ( ! F_69 ( V_2 , V_3 , V_268 , 76100 / 2 ) )
V_271 &= ~ V_280 ;
F_11 ( V_2 , V_128 ,
V_279 , 0 ) ;
}
F_6 ( V_2 , V_3 , V_272 ) ;
if ( V_268 )
F_6 ( V_2 , V_268 , V_272 ) ;
* V_270 = V_271 ;
}
static unsigned int F_67 ( struct V_1 * V_2 )
{
unsigned int V_271 = 0 ;
int V_160 ;
static unsigned short V_289 [] = {
V_290 , V_291 , V_292
} ;
static unsigned int V_293 [] = {
V_286 , V_285 , V_274
} ;
for ( V_160 = 0 ; V_160 < ( int ) F_50 ( V_289 ) ; V_160 ++ ) {
F_11 ( V_2 , V_130 , V_294 , V_289 [ V_160 ] ) ;
if ( ( F_3 ( V_2 , V_130 ) & V_294 ) == V_289 [ V_160 ] )
V_271 |= V_293 [ V_160 ] ;
}
return V_271 ;
}
static const struct V_295 * F_71 ( const struct V_295 * V_296 ,
unsigned int V_4 )
{
const struct V_295 * V_297 ;
for ( V_297 = V_296 ; V_297 -> V_4 ; V_297 ++ )
if ( V_297 -> V_4 == ( V_4 & V_297 -> V_37 ) )
return V_297 ;
return NULL ;
}
void F_72 ( struct V_1 * V_2 , unsigned int V_4 , char * V_64 , int V_298 )
{
const struct V_295 * V_297 ;
sprintf ( V_64 , L_17 , V_4 ,
F_53 ( V_4 >> 24 ) ,
F_53 ( V_4 >> 16 ) ,
F_53 ( V_4 >> 8 ) ) ;
V_297 = F_71 ( V_299 , V_4 ) ;
if ( ! V_297 )
return;
strcpy ( V_64 , V_297 -> V_64 ) ;
if ( V_2 && V_297 -> V_300 ) {
if ( ( V_298 && ( V_297 -> V_114 & V_301 ) ) ||
( ! V_298 && ! ( V_297 -> V_114 & V_301 ) ) )
V_297 -> V_300 ( V_2 ) ;
}
V_297 = F_71 ( V_302 , V_4 ) ;
if ( V_297 ) {
strcat ( V_64 , L_18 ) ;
strcat ( V_64 , V_297 -> V_64 ) ;
if ( V_297 -> V_37 != 0xffffffff )
sprintf ( V_64 + strlen ( V_64 ) , L_19 , V_4 & ~ V_297 -> V_37 ) ;
if ( V_2 && V_297 -> V_300 ) {
if ( ( V_298 && ( V_297 -> V_114 & V_301 ) ) ||
( ! V_298 && ! ( V_297 -> V_114 & V_301 ) ) )
V_297 -> V_300 ( V_2 ) ;
}
} else
sprintf ( V_64 + strlen ( V_64 ) , L_20 , V_4 & 0xff ) ;
}
const char * F_73 ( struct V_1 * V_2 )
{
const struct V_295 * V_297 ;
for ( V_297 = V_302 ; V_297 -> V_4 ; V_297 ++ )
if ( V_297 -> V_4 == ( V_2 -> V_4 & V_297 -> V_37 ) )
return V_297 -> V_64 ;
return L_21 ;
}
static int F_74 ( struct V_1 * V_2 , int V_303 , int V_304 )
{
unsigned long V_305 ;
unsigned short V_68 ;
V_305 = V_306 + V_303 ;
do {
F_3 ( V_2 , V_30 ) ;
F_3 ( V_2 , V_307 ) ;
F_3 ( V_2 , V_308 ) ;
if ( V_304 ) {
V_68 = F_3 ( V_2 , V_309 ) ;
if ( V_68 != 0xffff && ( V_68 & 1 ) != 0 )
return 0 ;
}
if ( V_2 -> V_91 & V_310 ) {
V_68 = F_3 ( V_2 , V_307 ) ;
if ( V_68 != 0 && V_68 != 0xffff )
return 0 ;
} else {
F_6 ( V_2 , V_228 , 0x8a05 ) ;
if ( ( F_3 ( V_2 , V_228 ) & 0x7fff ) == 0x0a05 )
return 0 ;
}
F_75 ( 1 ) ;
} while ( F_76 ( V_305 , V_306 ) );
return - V_311 ;
}
int V_135 ( struct V_173 * V_174 , int V_142 , struct V_312 * V_28 ,
void * V_313 , struct V_135 * * V_314 )
{
int V_84 ;
struct V_135 * V_27 ;
static struct V_315 V_316 = {
. V_317 = F_42 ,
} ;
if ( F_77 ( ! V_174 ) )
return - V_36 ;
V_27 = F_78 ( sizeof( * V_27 ) , V_318 ) ;
if ( V_27 == NULL )
return - V_188 ;
V_27 -> V_174 = V_174 ;
V_27 -> V_142 = V_142 ;
V_27 -> V_28 = V_28 ;
V_27 -> V_313 = V_313 ;
V_27 -> clock = 48000 ;
F_79 ( & V_27 -> V_319 ) ;
F_80 ( V_27 ) ;
if ( ( V_84 = F_81 ( V_174 , V_320 , V_27 , & V_316 ) ) < 0 ) {
F_39 ( V_27 ) ;
return V_84 ;
}
if ( V_314 )
* V_314 = V_27 ;
return 0 ;
}
static void F_82 ( struct V_139 * V_321 )
{
}
static int F_83 ( struct V_138 * V_139 )
{
struct V_1 * V_2 = V_139 -> V_140 ;
int V_84 ;
V_2 -> V_321 . V_27 = & V_322 ;
V_2 -> V_321 . V_323 = V_2 -> V_27 -> V_174 -> V_321 ;
V_2 -> V_321 . V_324 = F_82 ;
F_84 ( & V_2 -> V_321 , L_22 ,
V_2 -> V_27 -> V_174 -> V_325 , V_2 -> V_142 ,
F_73 ( V_2 ) ) ;
if ( ( V_84 = F_85 ( & V_2 -> V_321 ) ) < 0 ) {
F_86 ( V_326 L_23 ) ;
V_2 -> V_321 . V_27 = NULL ;
return V_84 ;
}
return 0 ;
}
static int F_87 ( struct V_138 * V_139 )
{
struct V_1 * V_2 = V_139 -> V_140 ;
if ( V_2 -> V_321 . V_27 )
F_88 ( & V_2 -> V_321 ) ;
return 0 ;
}
static void F_89 ( struct V_327 * V_328 )
{
F_24 (
F_90 ( V_328 , struct V_1 , V_141 . V_328 ) ) ;
}
int F_91 ( struct V_135 * V_27 , struct V_329 * V_171 , struct V_1 * * V_330 )
{
int V_84 ;
struct V_1 * V_2 ;
struct V_173 * V_174 ;
char V_64 [ 64 ] ;
unsigned long V_305 ;
unsigned int V_3 ;
const struct V_295 * V_297 ;
static struct V_315 V_28 = {
. V_317 = F_46 ,
. V_331 = F_83 ,
. V_332 = F_87 ,
} ;
if ( V_330 )
* V_330 = NULL ;
if ( F_77 ( ! V_27 || ! V_171 ) )
return - V_36 ;
if ( F_77 ( V_171 -> V_142 >= 4 ) )
return - V_36 ;
if ( V_27 -> V_40 [ V_171 -> V_142 ] )
return - V_333 ;
V_174 = V_27 -> V_174 ;
V_2 = F_78 ( sizeof( * V_2 ) , V_318 ) ;
if ( V_2 == NULL )
return - V_188 ;
V_2 -> V_313 = V_171 -> V_313 ;
V_2 -> V_137 = V_171 -> V_137 ;
V_2 -> V_27 = V_27 ;
V_2 -> V_334 = V_171 -> V_334 ;
V_2 -> V_142 = V_171 -> V_142 ;
V_2 -> V_335 = V_171 -> V_335 ;
V_2 -> V_91 = V_171 -> V_91 ;
V_2 -> V_161 = V_171 -> V_161 ;
V_27 -> V_40 [ V_2 -> V_142 ] = V_2 ;
F_92 ( & V_2 -> V_34 ) ;
F_92 ( & V_2 -> V_42 ) ;
#ifdef F_23
F_93 ( & V_2 -> V_141 , F_89 ) ;
#endif
#ifdef F_94
if ( V_2 -> V_334 ) {
F_95 ( V_2 -> V_334 , V_336 , & V_2 -> V_249 ) ;
F_95 ( V_2 -> V_334 , V_337 , & V_2 -> V_250 ) ;
}
#endif
if ( V_27 -> V_28 -> V_338 ) {
V_27 -> V_28 -> V_338 ( V_2 ) ;
goto V_339;
}
V_2 -> V_4 = F_3 ( V_2 , V_307 ) << 16 ;
V_2 -> V_4 |= F_3 ( V_2 , V_308 ) ;
if ( V_2 -> V_4 && V_2 -> V_4 != ( unsigned int ) - 1 ) {
V_297 = F_71 ( V_302 , V_2 -> V_4 ) ;
if ( V_297 && ( V_297 -> V_114 & V_340 ) )
goto V_339;
}
if ( ! ( V_2 -> V_91 & V_341 ) )
F_2 ( V_2 , V_30 , 0 ) ;
if ( ! ( V_2 -> V_91 & V_342 ) )
F_2 ( V_2 , V_309 , 0 ) ;
if ( V_27 -> V_28 -> V_343 )
V_27 -> V_28 -> V_343 ( V_2 ) ;
else {
F_96 ( 50 ) ;
if ( V_2 -> V_91 & V_341 )
V_84 = F_74 ( V_2 , F_97 ( 500 ) , 1 ) ;
else {
V_84 = F_74 ( V_2 , F_97 ( 500 ) , 0 ) ;
if ( V_84 < 0 )
V_84 = F_74 ( V_2 ,
F_97 ( 500 ) , 1 ) ;
}
if ( V_84 < 0 ) {
F_86 ( V_344 L_24 , V_2 -> V_142 ) ;
}
}
V_339:
V_2 -> V_4 = F_3 ( V_2 , V_307 ) << 16 ;
V_2 -> V_4 |= F_3 ( V_2 , V_308 ) ;
if ( ! ( V_2 -> V_91 & V_310 ) &&
( V_2 -> V_4 == 0x00000000 || V_2 -> V_4 == 0xffffffff ) ) {
F_86 ( V_326 L_25 , V_2 -> V_142 , V_2 -> V_4 ) ;
F_43 ( V_2 ) ;
return - V_345 ;
}
V_297 = F_71 ( V_302 , V_2 -> V_4 ) ;
if ( V_297 )
V_2 -> V_114 |= V_297 -> V_114 ;
if ( ! ( V_2 -> V_91 & V_341 ) && ! ( V_2 -> V_91 & V_346 ) ) {
F_6 ( V_2 , V_228 , 0x8a06 ) ;
if ( ( ( V_84 = F_3 ( V_2 , V_228 ) ) & 0x7fff ) == 0x0a06 )
V_2 -> V_91 |= V_346 ;
}
if ( V_2 -> V_91 & V_346 ) {
V_2 -> V_145 = F_3 ( V_2 , V_30 ) ;
V_2 -> V_71 = F_3 ( V_2 , V_347 ) ;
if ( V_2 -> V_71 == 0xffff )
V_2 -> V_71 = 0 ;
}
if ( ! ( V_2 -> V_91 & V_342 ) && ! ( V_2 -> V_91 & V_348 ) ) {
V_2 -> V_349 = F_3 ( V_2 , V_309 ) ;
if ( V_2 -> V_349 == 0xffff )
V_2 -> V_349 = 0 ;
if ( V_2 -> V_349 & 1 )
V_2 -> V_91 |= V_348 ;
}
if ( ! F_98 ( V_2 ) && ! F_99 ( V_2 ) ) {
if ( ! ( V_2 -> V_91 & ( V_341 | V_342 ) ) )
F_86 ( V_326 L_26 , V_2 -> V_142 ) ;
F_43 ( V_2 ) ;
return - V_350 ;
}
if ( V_27 -> V_28 -> V_338 )
goto V_351;
if ( F_98 ( V_2 ) ) {
F_6 ( V_2 , V_90 , 0 ) ;
if ( ! ( V_2 -> V_114 & V_340 ) ) {
F_6 ( V_2 , V_30 , 0 ) ;
F_96 ( 100 ) ;
F_6 ( V_2 , V_90 , 0 ) ;
}
F_6 ( V_2 , V_233 , 0 ) ;
V_305 = V_306 + F_97 ( 5000 ) ;
do {
if ( ( F_3 ( V_2 , V_90 ) & 0x0f ) == 0x0f )
goto V_351;
F_75 ( 1 ) ;
} while ( F_76 ( V_305 , V_306 ) );
F_86 ( V_344 L_27 , V_2 -> V_142 ) ;
}
if ( F_99 ( V_2 ) ) {
unsigned char V_178 ;
V_178 = V_352 ;
if ( V_2 -> V_349 & V_353 ) {
F_6 ( V_2 , V_354 , 8000 ) ;
V_178 |= V_355 | V_356 ;
}
if ( V_2 -> V_349 & V_357 ) {
F_6 ( V_2 , V_358 , 8000 ) ;
V_178 |= V_359 | V_360 ;
}
if ( V_2 -> V_349 & V_361 ) {
F_6 ( V_2 , V_362 , 8000 ) ;
V_178 |= V_363 | V_364 ;
}
F_6 ( V_2 , V_365 , 0 ) ;
F_96 ( 100 ) ;
F_6 ( V_2 , V_365 , 0 ) ;
V_305 = V_306 + F_97 ( 100 ) ;
do {
if ( ( F_3 ( V_2 , V_365 ) & V_178 ) == V_178 )
goto V_351;
F_75 ( 1 ) ;
} while ( F_76 ( V_305 , V_306 ) );
F_86 ( V_344 L_28 , V_2 -> V_142 , F_3 ( V_2 , V_365 ) ) ;
}
V_351:
if ( F_98 ( V_2 ) )
V_2 -> V_335 = ( V_2 -> V_71 & V_366 ) >> V_367 ;
else
V_2 -> V_335 = ( V_2 -> V_349 & V_368 ) >> V_369 ;
if ( V_2 -> V_71 & 0x01c9 ) {
V_3 = F_3 ( V_2 , V_128 ) ;
V_3 |= V_2 -> V_71 & 0x01c0 ;
if ( ! V_27 -> V_273 )
V_3 |= V_2 -> V_71 & 0x0009 ;
F_6 ( V_2 , V_128 , V_3 ) ;
}
if ( ( V_2 -> V_71 & V_278 ) && V_27 -> V_370 ) {
F_11 ( V_2 , V_233 , V_245 , V_371 ) ;
if ( ( F_3 ( V_2 , V_233 ) & V_245 ) == V_371 )
V_2 -> V_114 |= V_275 ;
F_11 ( V_2 , V_233 , V_245 , 0 ) ;
}
if ( V_2 -> V_71 & V_372 ) {
F_70 ( V_2 , V_276 , 0 , & V_2 -> V_256 [ V_373 ] ) ;
F_70 ( V_2 , V_374 , 0 , & V_2 -> V_256 [ V_375 ] ) ;
} else {
V_2 -> V_256 [ V_373 ] = V_274 ;
if ( V_2 -> V_114 & V_275 )
V_2 -> V_256 [ V_373 ] |= V_277 ;
V_2 -> V_256 [ V_375 ] = V_274 ;
}
if ( V_2 -> V_71 & V_251 ) {
V_2 -> V_256 [ V_257 ] = V_274 | V_286 | V_285 ;
}
if ( V_2 -> V_71 & V_376 ) {
F_70 ( V_2 , V_377 , 0 , & V_2 -> V_256 [ V_378 ] ) ;
} else {
V_2 -> V_256 [ V_378 ] = V_274 ;
}
if ( V_2 -> V_71 & V_156 ) {
F_70 ( V_2 , V_379 , V_276 , & V_2 -> V_256 [ V_380 ] ) ;
V_2 -> V_91 |= V_219 ;
}
if ( V_2 -> V_71 & V_154 ) {
F_70 ( V_2 , V_381 , V_276 , & V_2 -> V_256 [ V_382 ] ) ;
V_2 -> V_91 |= V_221 ;
}
if ( V_27 -> V_28 -> V_383 )
V_27 -> V_28 -> V_383 ( V_2 ) ;
F_72 ( V_2 , V_2 -> V_4 , V_64 , ! F_98 ( V_2 ) ) ;
F_72 ( NULL , V_2 -> V_4 , V_64 , ! F_98 ( V_2 ) ) ;
if ( ! V_2 -> V_246 )
V_2 -> V_246 = & V_384 ;
if ( F_98 ( V_2 ) ) {
char V_385 [ 16 ] ;
if ( V_174 -> V_386 [ 0 ] == '\0' ) {
strcpy ( V_174 -> V_386 , V_64 ) ;
} else {
if ( strlen ( V_174 -> V_386 ) + 1 + strlen ( V_64 ) + 1 <= sizeof( V_174 -> V_386 ) ) {
strcat ( V_174 -> V_386 , L_29 ) ;
strcat ( V_174 -> V_386 , V_64 ) ;
}
}
sprintf ( V_385 , L_30 , V_2 -> V_4 ) ;
if ( ( V_84 = F_100 ( V_174 , V_385 ) ) < 0 ) {
F_43 ( V_2 ) ;
return V_84 ;
}
if ( F_64 ( V_2 ) < 0 ) {
F_43 ( V_2 ) ;
return - V_188 ;
}
}
if ( F_99 ( V_2 ) ) {
char V_385 [ 16 ] ;
if ( V_174 -> V_386 [ 0 ] == '\0' ) {
strcpy ( V_174 -> V_386 , V_64 ) ;
} else {
if ( strlen ( V_174 -> V_386 ) + 1 + strlen ( V_64 ) + 1 <= sizeof( V_174 -> V_386 ) ) {
strcat ( V_174 -> V_386 , L_29 ) ;
strcat ( V_174 -> V_386 , V_64 ) ;
}
}
sprintf ( V_385 , L_31 , V_2 -> V_4 ) ;
if ( ( V_84 = F_100 ( V_174 , V_385 ) ) < 0 ) {
F_43 ( V_2 ) ;
return V_84 ;
}
if ( F_68 ( V_174 , V_2 ) < 0 ) {
F_43 ( V_2 ) ;
return - V_188 ;
}
}
if ( F_98 ( V_2 ) )
F_24 ( V_2 ) ;
F_101 ( V_2 ) ;
if ( ( V_84 = F_81 ( V_174 , V_387 , V_2 , & V_28 ) ) < 0 ) {
F_43 ( V_2 ) ;
return V_84 ;
}
* V_330 = V_2 ;
return 0 ;
}
static void F_47 ( struct V_1 * V_2 )
{
unsigned short V_388 ;
if ( F_98 ( V_2 ) ) {
F_2 ( V_2 , V_25 , 0x9f9f ) ;
F_2 ( V_2 , V_26 , 0x9f9f ) ;
}
V_388 = V_2 -> V_33 [ V_128 ] ;
if ( V_2 -> V_91 & V_219 )
V_388 |= V_389 ;
if ( V_2 -> V_91 & V_221 )
V_388 |= V_390 | V_391 ;
V_388 |= V_392 ;
F_2 ( V_2 , V_128 , V_388 ) ;
if ( V_2 -> V_91 & V_92 )
V_388 = V_2 -> V_33 [ V_90 ] & ~ V_87 ;
else if ( ! ( V_2 -> V_91 & V_393 ) )
V_388 = V_2 -> V_33 [ V_90 ] | V_87 ;
V_388 |= V_394 ;
V_388 |= V_395 | V_396 ;
F_2 ( V_2 , V_90 , V_388 ) ;
F_96 ( 100 ) ;
V_388 |= V_397 ;
F_2 ( V_2 , V_90 , V_388 ) ;
if ( F_102 ( V_2 ) ) {
V_388 |= V_398 ;
F_2 ( V_2 , V_90 , V_388 ) ;
F_96 ( 100 ) ;
V_388 |= V_399 | V_400 ;
F_2 ( V_2 , V_90 , V_388 ) ;
}
}
int F_103 ( struct V_1 * V_2 , int V_3 , int V_401 )
{
int V_160 ;
if ( ! V_2 )
return 0 ;
if ( V_3 ) {
if ( V_3 == V_130 )
V_3 = V_276 ;
for ( V_160 = 0 ; V_160 < V_402 ; V_160 ++ ) {
if ( V_403 [ V_160 ] . V_3 == V_3 ) {
if ( V_401 )
V_2 -> V_88 |= ( 1 << V_160 ) ;
else
V_2 -> V_88 &= ~ ( 1 << V_160 ) ;
break;
}
}
}
if ( F_102 ( V_2 ) && ! V_401 )
F_104 ( & V_2 -> V_141 ,
F_97 ( V_404 * 1000 ) ) ;
else {
F_105 ( & V_2 -> V_141 ) ;
F_24 ( V_2 ) ;
}
return 0 ;
}
static void F_24 ( struct V_1 * V_2 )
{
unsigned int V_88 , V_164 ;
int V_160 ;
V_88 = ( 1 << V_405 ) | ( 1 << V_406 ) ;
V_88 |= ( 1 << V_407 ) ;
if ( V_2 -> V_91 & V_219 )
V_88 |= ( 1 << V_408 ) ;
if ( V_2 -> V_91 & V_221 )
V_88 |= ( 1 << V_409 ) ;
#ifdef F_23
if ( F_102 ( V_2 ) )
V_88 = V_2 -> V_88 ;
#endif
if ( V_88 ) {
if ( V_2 -> V_33 [ V_90 ] & V_397 ) {
F_11 ( V_2 , V_90 ,
V_398 , 0 ) ;
F_106 ( 1 ) ;
F_11 ( V_2 , V_90 ,
V_397 , 0 ) ;
}
}
for ( V_160 = 0 ; V_160 < V_402 ; V_160 ++ ) {
if ( V_88 & ( 1 << V_160 ) )
V_164 = 0 ;
else
V_164 = V_403 [ V_160 ] . V_37 ;
F_11 ( V_2 , V_403 [ V_160 ] . V_410 ,
V_403 [ V_160 ] . V_37 , V_164 ) ;
}
if ( ! V_88 ) {
if ( ! ( V_2 -> V_33 [ V_90 ] & V_397 ) ) {
F_11 ( V_2 , V_90 ,
V_397 , V_397 ) ;
F_11 ( V_2 , V_90 ,
V_398 , V_398 ) ;
}
}
}
void F_107 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return;
if ( V_2 -> V_246 -> V_411 )
V_2 -> V_246 -> V_411 ( V_2 ) ;
#ifdef F_23
F_44 ( & V_2 -> V_141 ) ;
#endif
F_47 ( V_2 ) ;
}
static void F_108 ( struct V_1 * V_2 )
{
int V_160 ;
for ( V_160 = 2 ; V_160 < 0x7c ; V_160 += 2 ) {
if ( V_160 == V_90 || V_160 == V_347 )
continue;
if ( F_5 ( V_160 , V_2 -> V_32 ) ) {
F_2 ( V_2 , V_160 , V_2 -> V_33 [ V_160 ] ) ;
F_3 ( V_2 , V_160 ) ;
}
}
}
static void F_109 ( struct V_1 * V_2 )
{
if ( V_2 -> V_71 & V_251 ) {
if ( V_2 -> V_33 [ V_128 ] & V_129 ) {
F_11 ( V_2 , V_128 , V_129 , 0 ) ;
F_2 ( V_2 , V_128 , V_2 -> V_33 [ V_128 ] ) ;
if ( V_2 -> V_114 & V_115 )
F_2 ( V_2 , V_117 , V_2 -> V_33 [ V_117 ] ) ;
else
F_2 ( V_2 , V_130 , V_2 -> V_33 [ V_130 ] ) ;
F_11 ( V_2 , V_128 , V_129 , V_129 ) ;
}
}
}
void F_110 ( struct V_1 * V_2 )
{
unsigned long V_305 ;
if ( ! V_2 )
return;
if ( V_2 -> V_27 -> V_28 -> V_338 ) {
V_2 -> V_27 -> V_28 -> V_338 ( V_2 ) ;
goto V_412;
}
F_2 ( V_2 , V_90 , 0 ) ;
if ( ! ( V_2 -> V_114 & V_340 ) ) {
if ( ! ( V_2 -> V_91 & V_341 ) )
F_2 ( V_2 , V_30 , 0 ) ;
else if ( ! ( V_2 -> V_91 & V_342 ) )
F_2 ( V_2 , V_309 , 0 ) ;
F_96 ( 100 ) ;
F_2 ( V_2 , V_90 , 0 ) ;
}
F_2 ( V_2 , V_233 , 0 ) ;
F_2 ( V_2 , V_90 , V_2 -> V_33 [ V_90 ] ) ;
if ( F_98 ( V_2 ) ) {
V_2 -> V_27 -> V_28 -> V_29 ( V_2 , V_25 , 0x8101 ) ;
V_305 = V_306 + F_97 ( 100 ) ;
do {
if ( F_3 ( V_2 , V_25 ) == 0x8101 )
break;
F_75 ( 1 ) ;
} while ( F_76 ( V_305 , V_306 ) );
V_2 -> V_27 -> V_28 -> V_29 ( V_2 , V_25 , V_143 ) ;
if ( F_3 ( V_2 , V_25 ) != V_143 )
F_106 ( 250 ) ;
} else {
V_305 = V_306 + F_97 ( 100 ) ;
do {
unsigned short V_68 = F_3 ( V_2 , V_309 ) ;
if ( V_68 != 0xffff && ( V_68 & 1 ) != 0 )
break;
F_75 ( 1 ) ;
} while ( F_76 ( V_305 , V_306 ) );
}
V_412:
if ( V_2 -> V_27 -> V_28 -> V_383 )
V_2 -> V_27 -> V_28 -> V_383 ( V_2 ) ;
if ( V_2 -> V_246 -> V_413 )
V_2 -> V_246 -> V_413 ( V_2 ) ;
else {
F_108 ( V_2 ) ;
F_109 ( V_2 ) ;
}
}
static void F_111 ( char * V_414 , const char * V_415 , const char * V_416 )
{
if ( V_416 )
sprintf ( V_414 , L_32 , V_415 , V_416 ) ;
else
strcpy ( V_414 , V_415 ) ;
}
static int F_112 ( struct V_1 * V_2 , const char * V_64 ,
const char * V_416 )
{
struct V_417 V_4 ;
memset ( & V_4 , 0 , sizeof( V_4 ) ) ;
F_111 ( V_4 . V_64 , V_64 , V_416 ) ;
V_4 . V_418 = V_419 ;
return F_113 ( V_2 -> V_27 -> V_174 , & V_4 ) ;
}
static struct V_50 * F_114 ( struct V_1 * V_2 , const char * V_64 , const char * V_416 )
{
struct V_417 V_420 ;
memset ( & V_420 , 0 , sizeof( V_420 ) ) ;
F_111 ( V_420 . V_64 , V_64 , V_416 ) ;
V_420 . V_418 = V_419 ;
return F_115 ( V_2 -> V_27 -> V_174 , & V_420 ) ;
}
static int F_116 ( struct V_1 * V_2 , const char * V_415 ,
const char * V_414 , const char * V_416 )
{
struct V_50 * V_89 = F_114 ( V_2 , V_415 , V_416 ) ;
if ( V_89 ) {
F_111 ( V_89 -> V_4 . V_64 , V_414 , V_416 ) ;
return 0 ;
}
return - V_421 ;
}
static void F_117 ( struct V_1 * V_2 , const char * V_415 ,
const char * V_414 )
{
F_116 ( V_2 , V_415 , V_414 , L_33 ) ;
F_116 ( V_2 , V_415 , V_414 , L_34 ) ;
}
static int F_118 ( struct V_1 * V_2 , const char * V_422 ,
const char * V_423 , const char * V_416 )
{
struct V_50 * V_424 , * V_425 ;
V_424 = F_114 ( V_2 , V_422 , V_416 ) ;
V_425 = F_114 ( V_2 , V_423 , V_416 ) ;
if ( V_424 && V_425 ) {
F_111 ( V_424 -> V_4 . V_64 , V_423 , V_416 ) ;
F_111 ( V_425 -> V_4 . V_64 , V_422 , V_416 ) ;
return 0 ;
}
return - V_421 ;
}
static int F_119 ( struct V_50 * V_51 , struct V_66 * V_67 )
{
int V_84 = F_22 ( V_51 , V_67 ) ;
if ( V_84 > 0 ) {
unsigned long V_426 = V_51 -> V_56 ;
V_51 -> V_56 = ( V_51 -> V_56 & ~ 0xff ) | V_26 ;
F_22 ( V_51 , V_67 ) ;
V_51 -> V_56 = V_426 ;
}
return V_84 ;
}
static int F_120 ( struct V_1 * V_2 )
{
struct V_50 * V_427 = F_114 ( V_2 , L_3 , NULL ) ;
struct V_50 * V_428 = F_114 ( V_2 , L_35 , NULL ) ;
if ( ! V_427 || ! V_428 )
return - V_421 ;
V_427 -> V_429 = F_119 ;
V_428 -> V_429 = F_119 ;
F_112 ( V_2 , L_6 , L_33 ) ;
F_112 ( V_2 , L_6 , L_34 ) ;
return 0 ;
}
static int F_120 ( struct V_1 * V_2 )
{
if ( F_114 ( V_2 , L_36 , NULL ) == NULL )
return - V_421 ;
F_112 ( V_2 , L_4 , L_33 ) ;
F_112 ( V_2 , L_4 , L_34 ) ;
F_117 ( V_2 , L_6 , L_4 ) ;
return 0 ;
}
static int F_121 ( struct V_1 * V_2 )
{
if ( F_114 ( V_2 , L_36 , NULL ) == NULL )
return - V_421 ;
F_117 ( V_2 , L_4 , L_37 ) ;
F_117 ( V_2 , L_6 , L_4 ) ;
return 0 ;
}
static int F_122 ( struct V_1 * V_2 )
{
if ( F_118 ( V_2 , L_4 , L_5 , L_33 ) ||
F_118 ( V_2 , L_4 , L_5 , L_34 ) )
return - V_421 ;
return 0 ;
}
static int F_123 ( struct V_1 * V_2 )
{
unsigned short V_430 ;
if ( ( V_2 -> V_4 & 0xffffff00 ) != 0x41445300 ) {
F_86 ( V_326 L_38 ) ;
return - V_36 ;
}
V_430 = F_3 ( V_2 , V_46 ) ;
F_6 ( V_2 , V_46 , V_430 | 0x0200 ) ;
return 0 ;
}
static int F_124 ( struct V_1 * V_2 )
{
if ( ( V_2 -> V_4 & 0xffffff00 ) != 0x414c4700 ) {
F_86 ( V_326 L_39 ) ;
return - V_36 ;
}
F_11 ( V_2 , 0x7a , 0x20 , 0x20 ) ;
F_11 ( V_2 , 0x7a , 0x01 , 0x01 ) ;
if ( V_2 -> V_4 == V_431 )
F_11 ( V_2 , 0x74 , 0x0800 , 0x0800 ) ;
return F_59 ( V_2 -> V_27 -> V_174 , F_54 ( & V_432 , V_2 ) ) ;
}
static int F_125 ( struct V_1 * V_2 )
{
struct V_50 * V_89 = F_114 ( V_2 , L_40 , NULL ) ;
if ( ! V_89 )
return - V_421 ;
F_25 ( V_2 , V_89 ) ;
return 0 ;
}
static int F_126 ( struct V_50 * V_51 , struct V_66 * V_67 )
{
int V_84 = F_22 ( V_51 , V_67 ) ;
if ( V_84 > 0 ) {
struct V_1 * V_2 = F_16 ( V_51 ) ;
int V_77 = ( V_51 -> V_56 >> 8 ) & 0x0f ;
int V_78 = ( V_51 -> V_56 >> 12 ) & 0x0f ;
unsigned short V_37 ;
if ( V_77 != V_78 )
V_37 = V_165 ;
else
V_37 = V_143 ;
F_11 ( V_2 , V_90 , V_87 ,
( V_2 -> V_33 [ V_25 ] & V_37 ) == V_37 ?
V_87 : 0 ) ;
}
return V_84 ;
}
static int F_127 ( struct V_1 * V_2 )
{
struct V_50 * V_427 = F_114 ( V_2 , L_3 , NULL ) ;
if ( ! V_427 )
return - V_421 ;
V_427 -> V_429 = F_126 ;
F_112 ( V_2 , L_40 , NULL ) ;
F_11 (
V_2 , V_90 ,
V_87 , V_87
) ;
V_2 -> V_91 |= V_393 ;
return 0 ;
}
static int F_128 ( struct V_50 * V_51 ,
struct V_66 * V_67 )
{
int V_84 = F_119 ( V_51 , V_67 ) ;
if ( V_84 > 0 ) {
struct V_1 * V_2 = F_16 ( V_51 ) ;
int V_77 = ( V_51 -> V_56 >> 8 ) & 0x0f ;
int V_78 = ( V_51 -> V_56 >> 12 ) & 0x0f ;
unsigned short V_37 ;
if ( V_77 != V_78 )
V_37 = V_165 ;
else
V_37 = V_143 ;
F_11 ( V_2 , V_90 , V_87 ,
( V_2 -> V_33 [ V_25 ] & V_37 ) == V_37 ?
V_87 : 0 ) ;
}
return V_84 ;
}
static int F_129 ( struct V_1 * V_2 )
{
struct V_50 * V_427 = F_114 ( V_2 , L_3 , NULL ) ;
struct V_50 * V_428 = F_114 ( V_2 , L_35 , NULL ) ;
if ( ! V_427 || ! V_428 )
return - V_421 ;
V_427 -> V_429 = F_128 ;
V_428 -> V_429 = F_119 ;
F_112 ( V_2 , L_40 , NULL ) ;
F_112 ( V_2 , L_6 , L_33 ) ;
F_112 ( V_2 , L_6 , L_34 ) ;
F_11 (
V_2 , V_90 ,
V_87 , V_87
) ;
return 0 ;
}
static int F_130 ( struct V_1 * V_2 , int type )
{
if ( type <= 0 )
return 0 ;
else if ( type >= F_50 ( V_433 ) )
return - V_36 ;
if ( V_433 [ type ] . V_434 )
return V_433 [ type ] . V_434 ( V_2 ) ;
return 0 ;
}
static int F_131 ( struct V_1 * V_2 , const char * V_435 )
{
int V_160 ;
struct V_436 * V_437 ;
for ( V_160 = 0 ; V_160 < F_50 ( V_433 ) ; V_160 ++ ) {
V_437 = & V_433 [ V_160 ] ;
if ( V_437 -> V_64 && ! strcmp ( V_435 , V_437 -> V_64 ) )
return F_130 ( V_2 , V_160 ) ;
}
if ( * V_435 >= '0' && * V_435 <= '9' )
return F_130 ( V_2 , ( int ) F_132 ( V_435 , NULL , 10 ) ) ;
return - V_36 ;
}
int F_133 ( struct V_1 * V_2 , struct V_438 * V_439 , const char * V_440 )
{
int V_271 ;
if ( V_440 && strcmp ( V_440 , L_41 ) && strcmp ( V_440 , L_42 ) ) {
V_271 = F_131 ( V_2 , V_440 ) ;
if ( V_271 < 0 )
F_86 ( V_326 L_43 , V_440 , V_271 ) ;
return V_271 ;
}
if ( ! V_439 )
return - V_36 ;
for (; V_439 -> V_441 ; V_439 ++ ) {
if ( V_439 -> V_441 != V_2 -> V_249 )
continue;
if ( ( ! V_439 -> V_37 && V_439 -> V_442 == V_2 -> V_250 ) ||
V_439 -> V_442 == ( V_439 -> V_37 & V_2 -> V_250 ) ) {
if ( V_439 -> V_443 && V_439 -> V_443 != V_2 -> V_4 )
continue;
F_134 ( L_44 , V_439 -> V_64 , V_2 -> V_249 , V_2 -> V_250 ) ;
V_271 = F_130 ( V_2 , V_439 -> type ) ;
if ( V_271 < 0 )
F_86 ( V_326 L_45 , V_439 -> type , V_439 -> V_64 , V_271 ) ;
return V_271 ;
}
}
return 0 ;
}
static int T_1 F_135 ( void )
{
return 0 ;
}
static void T_2 F_136 ( void )
{
}
