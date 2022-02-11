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
return F_15 ( V_53 , V_55 -> V_57 == V_55 -> V_58 ? 1 : 2 ,
V_55 -> V_37 , V_55 -> V_59 ) ;
}
static int F_16 ( struct V_50 * V_51 ,
struct V_60 * V_61 )
{
struct V_1 * V_2 = F_17 ( V_51 ) ;
struct V_54 * V_55 = (struct V_54 * ) V_51 -> V_56 ;
unsigned short V_62 , V_63 ;
for ( V_63 = 1 ; V_63 < V_55 -> V_37 ; V_63 <<= 1 )
;
V_62 = F_4 ( V_2 , V_55 -> V_3 ) ;
V_61 -> V_23 . V_64 . V_65 [ 0 ] = ( V_62 >> V_55 -> V_57 ) & ( V_63 - 1 ) ;
if ( V_55 -> V_57 != V_55 -> V_58 )
V_61 -> V_23 . V_64 . V_65 [ 1 ] = ( V_62 >> V_55 -> V_58 ) & ( V_63 - 1 ) ;
return 0 ;
}
static int F_18 ( struct V_50 * V_51 ,
struct V_60 * V_61 )
{
struct V_1 * V_2 = F_17 ( V_51 ) ;
struct V_54 * V_55 = (struct V_54 * ) V_51 -> V_56 ;
unsigned short V_62 ;
unsigned short V_37 , V_63 ;
for ( V_63 = 1 ; V_63 < V_55 -> V_37 ; V_63 <<= 1 )
;
if ( V_61 -> V_23 . V_64 . V_65 [ 0 ] > V_55 -> V_37 - 1 )
return - V_36 ;
V_62 = V_61 -> V_23 . V_64 . V_65 [ 0 ] << V_55 -> V_57 ;
V_37 = ( V_63 - 1 ) << V_55 -> V_57 ;
if ( V_55 -> V_57 != V_55 -> V_58 ) {
if ( V_61 -> V_23 . V_64 . V_65 [ 1 ] > V_55 -> V_37 - 1 )
return - V_36 ;
V_62 |= V_61 -> V_23 . V_64 . V_65 [ 1 ] << V_55 -> V_58 ;
V_37 |= ( V_63 - 1 ) << V_55 -> V_58 ;
}
return F_11 ( V_2 , V_55 -> V_3 , V_37 , V_62 ) ;
}
static int F_19 ( struct V_1 * V_2 , int V_3 , struct V_50 * V_51 )
{
int V_66 = - 1 ;
if ( ( V_51 -> V_56 & ( 1 << 25 ) ) &&
( V_2 -> V_67 & V_68 ) >= V_69 &&
( V_3 >= 0x60 && V_3 < 0x70 ) ) {
unsigned short V_70 = ( V_51 -> V_56 >> 26 ) & 0x0f ;
F_7 ( & V_2 -> V_42 ) ;
V_66 = F_3 ( V_2 , V_71 ) & V_72 ;
F_11 ( V_2 , V_71 , V_72 , V_70 ) ;
}
return V_66 ;
}
static void F_20 ( struct V_1 * V_2 , int V_66 )
{
if ( V_66 >= 0 ) {
F_11 ( V_2 , V_71 , V_72 , V_66 ) ;
F_9 ( & V_2 -> V_42 ) ;
}
}
static int F_21 ( struct V_50 * V_51 ,
struct V_52 * V_53 )
{
int V_37 = ( V_51 -> V_56 >> 16 ) & 0xff ;
int V_73 = ( V_51 -> V_56 >> 8 ) & 0x0f ;
int V_74 = ( V_51 -> V_56 >> 12 ) & 0x0f ;
V_53 -> type = V_37 == 1 ? V_75 : V_76 ;
V_53 -> V_77 = V_73 == V_74 ? 1 : 2 ;
V_53 -> V_23 . integer . V_78 = 0 ;
V_53 -> V_23 . integer . V_79 = V_37 ;
return 0 ;
}
static int F_22 ( struct V_50 * V_51 ,
struct V_60 * V_61 )
{
struct V_1 * V_2 = F_17 ( V_51 ) ;
int V_3 = V_51 -> V_56 & 0xff ;
int V_73 = ( V_51 -> V_56 >> 8 ) & 0x0f ;
int V_74 = ( V_51 -> V_56 >> 12 ) & 0x0f ;
int V_37 = ( V_51 -> V_56 >> 16 ) & 0xff ;
int V_80 = ( V_51 -> V_56 >> 24 ) & 0x01 ;
int V_66 ;
V_66 = F_19 ( V_2 , V_3 , V_51 ) ;
V_61 -> V_23 . integer . V_23 [ 0 ] = ( F_4 ( V_2 , V_3 ) >> V_73 ) & V_37 ;
if ( V_73 != V_74 )
V_61 -> V_23 . integer . V_23 [ 1 ] = ( F_4 ( V_2 , V_3 ) >> V_74 ) & V_37 ;
if ( V_80 ) {
V_61 -> V_23 . integer . V_23 [ 0 ] = V_37 - V_61 -> V_23 . integer . V_23 [ 0 ] ;
if ( V_73 != V_74 )
V_61 -> V_23 . integer . V_23 [ 1 ] = V_37 - V_61 -> V_23 . integer . V_23 [ 1 ] ;
}
F_20 ( V_2 , V_66 ) ;
return 0 ;
}
static int F_23 ( struct V_50 * V_51 ,
struct V_60 * V_61 )
{
struct V_1 * V_2 = F_17 ( V_51 ) ;
int V_3 = V_51 -> V_56 & 0xff ;
int V_73 = ( V_51 -> V_56 >> 8 ) & 0x0f ;
int V_74 = ( V_51 -> V_56 >> 12 ) & 0x0f ;
int V_37 = ( V_51 -> V_56 >> 16 ) & 0xff ;
int V_80 = ( V_51 -> V_56 >> 24 ) & 0x01 ;
int V_81 , V_66 ;
unsigned short V_62 , V_82 , V_83 ;
V_66 = F_19 ( V_2 , V_3 , V_51 ) ;
V_62 = ( V_61 -> V_23 . integer . V_23 [ 0 ] & V_37 ) ;
if ( V_80 )
V_62 = V_37 - V_62 ;
V_83 = V_37 << V_73 ;
V_62 = V_62 << V_73 ;
if ( V_73 != V_74 ) {
V_82 = ( V_61 -> V_23 . integer . V_23 [ 1 ] & V_37 ) ;
if ( V_80 )
V_82 = V_37 - V_82 ;
V_83 |= V_37 << V_74 ;
V_62 |= V_82 << V_74 ;
}
V_81 = F_11 ( V_2 , V_3 , V_83 , V_62 ) ;
F_20 ( V_2 , V_66 ) ;
#ifdef F_24
if ( ( V_83 & V_84 ) &&
( V_51 -> V_56 & ( 1 << 30 ) ) ) {
if ( V_62 & V_84 )
V_2 -> V_85 &= ~ ( 1 << ( V_3 >> 1 ) ) ;
else
V_2 -> V_85 |= 1 << ( V_3 >> 1 ) ;
F_25 ( V_2 ) ;
}
#endif
return V_81 ;
}
static void F_26 ( struct V_1 * V_2 , struct V_50 * V_86 )
{
V_86 -> V_56 = F_27 ( V_87 , 15 , 1 , 0 ) ;
F_11 ( V_2 , V_87 , ( 1 << 15 ) , ( 1 << 15 ) ) ;
V_2 -> V_88 |= V_89 ;
}
static int F_28 ( struct V_50 * V_51 , struct V_52 * V_53 )
{
V_53 -> type = V_90 ;
V_53 -> V_77 = 1 ;
return 0 ;
}
static int F_29 ( struct V_50 * V_51 , struct V_60 * V_61 )
{
V_61 -> V_23 . V_91 . V_92 [ 0 ] = V_93 |
V_94 |
V_95 |
V_96 ;
V_61 -> V_23 . V_91 . V_92 [ 1 ] = V_97 |
V_98 ;
V_61 -> V_23 . V_91 . V_92 [ 3 ] = V_99 ;
return 0 ;
}
static int F_30 ( struct V_50 * V_51 , struct V_60 * V_61 )
{
V_61 -> V_23 . V_91 . V_92 [ 0 ] = V_93 |
V_94 |
V_100 |
V_101 ;
return 0 ;
}
static int F_31 ( struct V_50 * V_51 , struct V_60 * V_61 )
{
struct V_1 * V_2 = F_17 ( V_51 ) ;
F_7 ( & V_2 -> V_34 ) ;
V_61 -> V_23 . V_91 . V_92 [ 0 ] = V_2 -> V_102 & 0xff ;
V_61 -> V_23 . V_91 . V_92 [ 1 ] = ( V_2 -> V_102 >> 8 ) & 0xff ;
V_61 -> V_23 . V_91 . V_92 [ 2 ] = ( V_2 -> V_102 >> 16 ) & 0xff ;
V_61 -> V_23 . V_91 . V_92 [ 3 ] = ( V_2 -> V_102 >> 24 ) & 0xff ;
F_9 ( & V_2 -> V_34 ) ;
return 0 ;
}
static int F_32 ( struct V_50 * V_51 , struct V_60 * V_61 )
{
struct V_1 * V_2 = F_17 ( V_51 ) ;
unsigned int V_39 = 0 ;
unsigned short V_62 = 0 ;
int V_35 ;
V_39 = V_62 = V_61 -> V_23 . V_91 . V_92 [ 0 ] & ( V_93 | V_94 ) ;
if ( V_61 -> V_23 . V_91 . V_92 [ 0 ] & V_93 ) {
V_39 |= V_61 -> V_23 . V_91 . V_92 [ 0 ] & ( V_100 | V_101 ) ;
switch ( V_39 & V_100 ) {
case V_103 : V_62 |= 0 << 12 ; break;
case V_104 : V_62 |= 2 << 12 ; break;
case V_105 : V_62 |= 3 << 12 ; break;
default: V_62 |= 1 << 12 ; break;
}
if ( ( V_39 & V_106 ) == V_101 )
V_62 |= 1 << 3 ;
} else {
V_39 |= V_61 -> V_23 . V_91 . V_92 [ 0 ] & ( V_95 | V_96 ) ;
V_39 |= ( ( V_61 -> V_23 . V_91 . V_92 [ 1 ] & ( V_97 | V_98 ) ) << 8 ) ;
V_39 |= ( ( V_61 -> V_23 . V_91 . V_92 [ 3 ] & V_99 ) << 24 ) ;
if ( ( V_39 & V_107 ) == V_95 )
V_62 |= 1 << 3 ;
if ( ! ( V_39 & V_96 ) )
V_62 |= 1 << 2 ;
V_62 |= ( ( V_39 >> 8 ) & 0xff ) << 4 ;
switch ( ( V_39 >> 24 ) & 0xff ) {
case V_108 : V_62 |= 0 << 12 ; break;
case V_109 : V_62 |= 2 << 12 ; break;
case V_110 : V_62 |= 3 << 12 ; break;
default: V_62 |= 1 << 12 ; break;
}
}
F_7 ( & V_2 -> V_34 ) ;
V_35 = V_2 -> V_102 != V_39 ;
V_2 -> V_102 = V_39 ;
if ( V_2 -> V_111 & V_112 ) {
int V_113 = ( V_62 >> 12 ) & 0x03 ;
switch ( V_113 ) {
case 0 : V_113 = 1 ; break;
case 2 : V_113 = 0 ; break;
default: V_113 = 0 ; break;
}
V_35 |= F_12 ( V_2 , V_114 , 0x3fff , ( ( V_62 & 0xcfff ) | ( V_113 << 12 ) ) ) ;
} else if ( V_2 -> V_111 & V_115 ) {
int V_116 ;
V_116 = V_39 & ( V_95 | V_96 ) ? 0 : V_117 ;
V_116 |= V_39 & V_94 ? V_118 : V_119 ;
V_35 |= F_12 ( V_2 , V_120 ,
V_121 | V_117 ,
V_116 ) ;
} else if ( V_2 -> V_4 == V_122 ) {
V_35 |= F_12 ( V_2 ,
V_123 ,
0xff38 ,
( ( V_62 << 4 ) & 0xff00 ) |
( ( V_62 << 2 ) & 0x0038 ) ) ;
} else {
unsigned short V_124 = F_4 ( V_2 , V_125 ) ;
F_12 ( V_2 , V_125 , V_126 , 0 ) ;
V_35 |= F_12 ( V_2 , V_127 , 0x3fff , V_62 ) ;
if ( V_124 & V_126 ) {
F_12 ( V_2 , V_125 , V_126 , V_126 ) ;
}
}
F_9 ( & V_2 -> V_34 ) ;
return V_35 ;
}
static int F_33 ( struct V_50 * V_51 , struct V_60 * V_61 )
{
struct V_1 * V_2 = F_17 ( V_51 ) ;
int V_3 = V_51 -> V_56 & 0xff ;
int V_73 = ( V_51 -> V_56 >> 8 ) & 0xff ;
int V_37 = ( V_51 -> V_56 >> 16 ) & 0xff ;
unsigned short V_23 , V_38 , V_39 ;
int V_35 ;
V_23 = ( V_61 -> V_23 . integer . V_23 [ 0 ] & V_37 ) ;
F_7 ( & V_2 -> V_34 ) ;
V_37 <<= V_73 ;
V_23 <<= V_73 ;
V_38 = F_4 ( V_2 , V_3 ) ;
V_39 = ( V_38 & ~ V_37 ) | V_23 ;
V_35 = V_38 != V_39 ;
if ( V_35 ) {
unsigned short V_124 = F_4 ( V_2 , V_125 ) ;
F_12 ( V_2 , V_125 , V_126 , 0 ) ;
V_35 = F_12 ( V_2 , V_3 , V_37 , V_23 ) ;
if ( V_124 & V_126 )
F_12 ( V_2 , V_125 , V_126 , V_126 ) ;
}
F_9 ( & V_2 -> V_34 ) ;
return V_35 ;
}
static int F_34 ( struct V_50 * V_51 , struct V_52 * V_53 )
{
struct V_1 * V_2 = F_17 ( V_51 ) ;
int V_37 = ( V_51 -> V_56 >> 16 ) & 0x0f ;
int V_128 = ( V_51 -> V_56 >> 8 ) & 0x0f ;
int V_74 = ( V_51 -> V_56 >> 12 ) & 0x0f ;
V_53 -> type = V_37 == 1 ? V_75 : V_76 ;
if ( V_128 != V_74 && ( V_2 -> V_111 & V_129 ) )
V_53 -> V_77 = 2 ;
else
V_53 -> V_77 = 1 ;
V_53 -> V_23 . integer . V_78 = 0 ;
V_53 -> V_23 . integer . V_79 = V_37 ;
return 0 ;
}
static int F_35 ( struct V_50 * V_51 , struct V_60 * V_61 )
{
struct V_1 * V_2 = F_17 ( V_51 ) ;
int V_40 = V_51 -> V_56 & 3 ;
int V_128 = ( V_51 -> V_56 >> 8 ) & 0x0f ;
int V_74 = ( V_51 -> V_56 >> 12 ) & 0x0f ;
int V_37 = ( V_51 -> V_56 >> 16 ) & 0xff ;
V_61 -> V_23 . integer . V_23 [ 0 ] = V_37 - ( ( V_2 -> V_43 . V_44 . V_45 [ V_40 ] >> V_128 ) & V_37 ) ;
if ( V_128 != V_74 && ( V_2 -> V_111 & V_129 ) )
V_61 -> V_23 . integer . V_23 [ 1 ] = V_37 - ( ( V_2 -> V_43 . V_44 . V_45 [ V_40 ] >> V_74 ) & V_37 ) ;
return 0 ;
}
static int F_36 ( struct V_50 * V_51 , struct V_60 * V_61 )
{
struct V_1 * V_2 = F_17 ( V_51 ) ;
int V_40 = V_51 -> V_56 & 3 ;
int V_128 = ( V_51 -> V_56 >> 8 ) & 0x0f ;
int V_74 = ( V_51 -> V_56 >> 12 ) & 0x0f ;
int V_37 = ( V_51 -> V_56 >> 16 ) & 0xff ;
unsigned short V_62 , V_130 ;
V_62 = ( V_37 - ( V_61 -> V_23 . integer . V_23 [ 0 ] & V_37 ) ) << V_128 ;
V_130 = V_37 << V_128 ;
if ( V_128 != V_74 && ( V_2 -> V_111 & V_129 ) ) {
V_62 |= ( V_37 - ( V_61 -> V_23 . integer . V_23 [ 1 ] & V_37 ) ) << V_74 ;
V_130 |= V_37 << V_74 ;
}
return F_13 ( V_2 , V_40 , V_130 , V_62 ) ;
}
static int F_37 ( struct V_50 * V_51 , struct V_52 * V_53 )
{
V_53 -> type = V_76 ;
V_53 -> V_77 = 2 ;
V_53 -> V_23 . integer . V_78 = 0 ;
V_53 -> V_23 . integer . V_79 = 31 ;
return 0 ;
}
static int F_38 ( struct V_50 * V_51 , struct V_60 * V_61 )
{
struct V_1 * V_2 = F_17 ( V_51 ) ;
int V_40 = V_51 -> V_56 & 3 ;
F_7 ( & V_2 -> V_42 ) ;
V_61 -> V_23 . integer . V_23 [ 0 ] = 31 - ( ( V_2 -> V_43 . V_44 . V_45 [ V_40 ] >> 0 ) & 31 ) ;
V_61 -> V_23 . integer . V_23 [ 1 ] = 31 - ( ( V_2 -> V_43 . V_44 . V_45 [ V_40 ] >> 8 ) & 31 ) ;
F_9 ( & V_2 -> V_42 ) ;
return 0 ;
}
static int F_39 ( struct V_50 * V_51 , struct V_60 * V_61 )
{
struct V_1 * V_2 = F_17 ( V_51 ) ;
int V_40 = V_51 -> V_56 & 3 ;
unsigned short V_131 , V_82 ;
V_131 = 31 - ( V_61 -> V_23 . integer . V_23 [ 0 ] & 31 ) ;
V_82 = 31 - ( V_61 -> V_23 . integer . V_23 [ 1 ] & 31 ) ;
return F_13 ( V_2 , V_40 , 0x1f1f , ( V_131 << 8 ) | V_82 ) ;
}
static int F_40 ( struct V_132 * V_27 )
{
if ( V_27 ) {
F_41 ( V_27 ) ;
F_42 ( V_27 -> V_133 ) ;
if ( V_27 -> V_134 )
V_27 -> V_134 ( V_27 ) ;
F_42 ( V_27 ) ;
}
return 0 ;
}
static int F_43 ( struct V_135 * V_136 )
{
struct V_132 * V_27 = V_136 -> V_137 ;
return F_40 ( V_27 ) ;
}
static int F_44 ( struct V_1 * V_2 )
{
if ( V_2 ) {
#ifdef F_24
F_45 ( & V_2 -> V_138 ) ;
#endif
F_46 ( V_2 ) ;
if ( V_2 -> V_27 )
V_2 -> V_27 -> V_40 [ V_2 -> V_139 ] = NULL ;
if ( V_2 -> V_134 )
V_2 -> V_134 ( V_2 ) ;
F_42 ( V_2 ) ;
}
return 0 ;
}
static int F_47 ( struct V_135 * V_136 )
{
struct V_1 * V_2 = V_136 -> V_137 ;
F_48 ( V_2 ) ;
return F_44 ( V_2 ) ;
}
static int F_49 ( struct V_1 * V_2 , int V_3 )
{
unsigned short V_62 , V_37 = V_140 ;
if ( ! F_1 ( V_2 , V_3 ) )
return 0 ;
switch ( V_3 ) {
case V_141 :
return V_2 -> V_142 & V_143 ? 1 : 0 ;
case V_26 :
return V_2 -> V_142 & V_144 ? 1 : 0 ;
case V_145 :
return V_2 -> V_142 & V_146 ? 1 : 0 ;
case V_147 :
if ( V_2 -> V_142 & V_148 ) {
V_62 = F_3 ( V_2 , V_3 ) ;
return V_62 == 0 ;
}
return 0 ;
case V_149 :
if ( ( V_2 -> V_67 & V_150 ) == 0 )
return 0 ;
break;
case V_149 + 1 :
if ( ( V_2 -> V_67 & V_151 ) == 0 )
return 0 ;
V_3 = V_149 ;
V_37 = 0x0080 ;
break;
case V_152 :
if ( ( V_2 -> V_67 & V_153 ) == 0 )
return 0 ;
break;
}
V_62 = F_3 ( V_2 , V_3 ) ;
if ( ! ( V_62 & V_37 ) ) {
F_6 ( V_2 , V_3 , V_62 | V_37 ) ;
V_62 = F_3 ( V_2 , V_3 ) ;
V_62 = F_3 ( V_2 , V_3 ) ;
if ( ! ( V_62 & V_37 ) )
return 0 ;
}
return 1 ;
}
static void F_50 ( struct V_1 * V_2 , int V_3 , unsigned char * V_154 , unsigned char * V_155 )
{
unsigned short V_156 [ 3 ] = { 0x20 , 0x10 , 0x01 } ;
unsigned char V_79 [ 3 ] = { 63 , 31 , 15 } ;
int V_157 ;
if ( V_2 -> V_158 ) {
const struct V_159 * V_160 ;
for ( V_160 = V_2 -> V_158 ; V_160 -> V_3 ; V_160 ++ ) {
if ( V_160 -> V_3 == V_3 ) {
* V_154 = V_160 -> V_161 & 0xff ;
* V_155 = ( V_160 -> V_161 >> 8 ) & 0xff ;
return;
}
}
}
* V_154 = * V_155 = 0 ;
for ( V_157 = 0 ; V_157 < F_51 ( V_156 ) ; V_157 ++ ) {
unsigned short V_62 ;
F_2 (
V_2 , V_3 ,
V_162 | V_156 [ V_157 ] | ( V_156 [ V_157 ] << 8 )
) ;
V_62 = F_3 ( V_2 , V_3 ) ;
V_62 = F_3 ( V_2 , V_3 ) ;
if ( ! * V_154 && ( V_62 & 0x7f ) == V_156 [ V_157 ] )
* V_154 = V_79 [ V_157 ] ;
if ( ! * V_155 && ( ( V_62 >> 8 ) & 0x7f ) == V_156 [ V_157 ] )
* V_155 = V_79 [ V_157 ] ;
if ( * V_154 && * V_155 )
break;
}
}
static int F_52 ( struct V_1 * V_2 , int V_3 , int V_163 )
{
unsigned short V_37 , V_62 , V_164 , V_165 ;
V_37 = 1 << V_163 ;
V_164 = F_3 ( V_2 , V_3 ) ;
V_62 = V_164 ^ V_37 ;
F_2 ( V_2 , V_3 , V_62 ) ;
V_165 = F_3 ( V_2 , V_3 ) ;
F_6 ( V_2 , V_3 , V_164 ) ;
return V_165 == V_62 ;
}
static void F_53 ( struct V_1 * V_2 , int V_3 , int V_73 , unsigned char * V_79 )
{
unsigned short V_62 , V_131 ;
* V_79 = 63 ;
V_62 = V_162 | ( 0x20 << V_73 ) ;
F_2 ( V_2 , V_3 , V_62 ) ;
V_131 = F_3 ( V_2 , V_3 ) ;
if ( V_62 != V_131 ) {
* V_79 = 31 ;
}
F_6 ( V_2 , V_3 , V_162 ) ;
}
static inline int F_54 ( unsigned int V_113 )
{
V_113 &= 0xff ;
if ( V_113 < ' ' || V_113 >= 0x71 ) {
if ( V_113 <= 0x89 )
return V_113 - 0x71 + 'A' ;
return '?' ;
}
return V_113 ;
}
static struct V_50 * F_55 ( const struct V_166 * V_167 ,
struct V_1 * V_2 )
{
struct V_166 V_168 ;
memcpy ( & V_168 , V_167 , sizeof( V_168 ) ) ;
V_168 . V_169 = V_2 -> V_139 ;
return F_56 ( & V_168 , V_2 ) ;
}
static int F_57 ( struct V_170 * V_171 , char * V_172 , int V_3 ,
int V_173 , int V_174 ,
struct V_1 * V_2 )
{
struct V_50 * V_86 ;
int V_81 ;
unsigned short V_62 , V_131 , V_175 ;
if ( ! F_1 ( V_2 , V_3 ) )
return 0 ;
V_175 = V_140 ;
V_62 = F_3 ( V_2 , V_3 ) ;
if ( V_173 || ( V_2 -> V_111 & V_129 ) ) {
V_131 = V_62 | V_162 ;
F_2 ( V_2 , V_3 , V_131 ) ;
if ( V_131 == F_3 ( V_2 , V_3 ) )
V_175 = V_162 ;
}
if ( V_175 == V_162 ) {
struct V_166 V_176 = F_58 ( V_172 , V_3 , 15 , 7 , 1 , 1 ) ;
if ( V_174 )
V_176 . V_56 |= ( 1 << 30 ) ;
V_176 . V_169 = V_2 -> V_139 ;
V_86 = F_56 ( & V_176 , V_2 ) ;
} else {
struct V_166 V_176 = F_59 ( V_172 , V_3 , 15 , 1 , 1 ) ;
if ( V_174 )
V_176 . V_56 |= ( 1 << 30 ) ;
V_176 . V_169 = V_2 -> V_139 ;
V_86 = F_56 ( & V_176 , V_2 ) ;
}
V_81 = F_60 ( V_171 , V_86 ) ;
if ( V_81 < 0 )
return V_81 ;
F_6 ( V_2 , V_3 , V_62 | V_175 ) ;
return 0 ;
}
static const unsigned int * F_61 ( unsigned int V_177 )
{
switch ( V_177 ) {
case 0x0f : return V_178 ;
case 0x1f : return V_179 ;
case 0x3f : return V_180 ;
}
return NULL ;
}
static void F_62 ( struct V_50 * V_86 , const unsigned int * V_181 )
{
V_86 -> V_181 . V_182 = V_181 ;
if ( V_181 )
V_86 -> V_183 [ 0 ] . V_184 |= V_185 ;
}
static int F_63 ( struct V_170 * V_171 , char * V_172 , int V_3 , unsigned int V_154 ,
unsigned int V_155 , struct V_1 * V_2 )
{
int V_81 ;
struct V_50 * V_86 ;
if ( ! F_1 ( V_2 , V_3 ) )
return 0 ;
if ( V_155 ) {
struct V_166 V_176 = F_58 ( V_172 , V_3 , 8 , 0 , V_154 , 1 ) ;
V_176 . V_169 = V_2 -> V_139 ;
V_86 = F_56 ( & V_176 , V_2 ) ;
} else {
struct V_166 V_176 = F_59 ( V_172 , V_3 , 0 , V_154 , 1 ) ;
V_176 . V_169 = V_2 -> V_139 ;
V_86 = F_56 ( & V_176 , V_2 ) ;
}
if ( ! V_86 )
return - V_186 ;
if ( V_3 >= V_187 && V_3 <= V_49 )
F_62 ( V_86 , V_188 ) ;
else
F_62 ( V_86 , F_61 ( V_154 ) ) ;
V_81 = F_60 ( V_171 , V_86 ) ;
if ( V_81 < 0 )
return V_81 ;
F_6 (
V_2 , V_3 ,
( F_3 ( V_2 , V_3 ) & V_162 )
| V_154 | ( V_155 << 8 )
) ;
return 0 ;
}
static int F_64 ( struct V_170 * V_171 , const char * V_189 ,
int V_3 , int V_173 , int V_174 ,
struct V_1 * V_2 )
{
int V_81 ;
char V_172 [ V_190 ] ;
unsigned char V_154 , V_155 ;
if ( ! F_1 ( V_2 , V_3 ) )
return 0 ;
if ( F_52 ( V_2 , V_3 , 15 ) ) {
sprintf ( V_172 , L_1 , V_189 ) ;
if ( ( V_81 = F_57 ( V_171 , V_172 , V_3 ,
V_173 , V_174 ,
V_2 ) ) < 0 )
return V_81 ;
}
F_50 ( V_2 , V_3 , & V_154 , & V_155 ) ;
if ( V_154 ) {
sprintf ( V_172 , L_2 , V_189 ) ;
if ( ( V_81 = F_63 ( V_171 , V_172 , V_3 , V_154 , V_155 , V_2 ) ) < 0 )
return V_81 ;
}
return 0 ;
}
static int F_65 ( struct V_1 * V_2 )
{
struct V_170 * V_171 = V_2 -> V_27 -> V_171 ;
struct V_50 * V_86 ;
int V_81 ;
unsigned int V_191 ;
unsigned char V_79 ;
if ( F_49 ( V_2 , V_25 ) ) {
if ( V_2 -> V_111 & V_192 )
V_81 = F_66 ( V_171 , L_3 ,
V_25 , 0 , V_2 ) ;
else
V_81 = F_67 ( V_171 , L_4 ,
V_25 , 0 , V_2 ) ;
if ( V_81 < 0 )
return V_81 ;
}
V_2 -> V_33 [ V_149 ] = V_162 ;
if ( ( F_49 ( V_2 , V_149 ) )
&& ! ( V_2 -> V_111 & V_193 ) ) {
if ( ( V_81 = F_60 ( V_171 , F_55 ( & V_194 [ 0 ] , V_2 ) ) ) < 0 )
return V_81 ;
if ( ( V_81 = F_60 ( V_171 , V_86 = F_55 ( & V_194 [ 1 ] , V_2 ) ) ) < 0 )
return V_81 ;
F_53 ( V_2 , V_149 , 0 , & V_79 ) ;
V_86 -> V_56 &= ~ ( 0xff << 16 ) ;
V_86 -> V_56 |= ( int ) V_79 << 16 ;
F_62 ( V_86 , F_61 ( V_79 ) ) ;
F_6 ( V_2 , V_149 , V_2 -> V_33 [ V_149 ] | V_79 ) ;
}
if ( ( F_49 ( V_2 , V_149 + 1 ) )
&& ! ( V_2 -> V_111 & V_193 ) ) {
if ( ( V_81 = F_60 ( V_171 , F_55 ( & V_195 [ 0 ] , V_2 ) ) ) < 0 )
return V_81 ;
if ( ( V_81 = F_60 ( V_171 , V_86 = F_55 ( & V_195 [ 1 ] , V_2 ) ) ) < 0 )
return V_81 ;
F_53 ( V_2 , V_149 , 8 , & V_79 ) ;
V_86 -> V_56 &= ~ ( 0xff << 16 ) ;
V_86 -> V_56 |= ( int ) V_79 << 16 ;
F_62 ( V_86 , F_61 ( V_79 ) ) ;
F_6 ( V_2 , V_149 , V_2 -> V_33 [ V_149 ] | V_79 << 8 ) ;
}
if ( ( F_49 ( V_2 , V_152 ) )
&& ! ( V_2 -> V_111 & V_193 ) ) {
if ( ( V_81 = F_64 ( V_171 , L_5 ,
V_152 , 1 , 0 ,
V_2 ) ) < 0 )
return V_81 ;
}
if ( F_49 ( V_2 , V_26 ) ) {
if ( ( V_81 = F_67 ( V_171 , L_6 ,
V_26 , 0 , V_2 ) ) < 0 )
return V_81 ;
}
if ( F_49 ( V_2 , V_196 ) ) {
if ( ( V_81 = F_67 ( V_171 , L_7 ,
V_196 , 0 , V_2 ) ) < 0 )
return V_81 ;
}
if ( ! ( V_2 -> V_111 & V_197 ) ) {
if ( F_49 ( V_2 , V_141 ) ) {
for ( V_191 = 0 ; V_191 < 2 ; V_191 ++ ) {
if ( ( V_81 = F_60 ( V_171 , V_86 = F_55 ( & V_198 [ V_191 ] , V_2 ) ) ) < 0 )
return V_81 ;
if ( V_2 -> V_4 == V_122 ||
V_2 -> V_4 == V_199 ) {
V_86 -> V_56 &= ~ ( 0xff << 16 ) ;
V_86 -> V_56 |= 7 << 16 ;
}
}
F_6 ( V_2 , V_141 , 0x0f0f ) ;
}
}
if ( ! ( V_2 -> V_111 & V_200 ) &&
( ( V_2 -> V_111 & V_201 ) ||
F_49 ( V_2 , V_202 ) ) ) {
for ( V_191 = 0 ; V_191 < 2 ; V_191 ++ )
if ( ( V_81 = F_60 ( V_171 , V_86 = F_55 ( & V_203 [ V_191 ] , V_2 ) ) ) < 0 )
return V_81 ;
F_62 ( V_86 , V_178 ) ;
F_6 (
V_2 ,
V_202 ,
( F_3 ( V_2 , V_202 )
| V_140 | 0x001e )
) ;
}
if ( ! ( V_2 -> V_111 & V_204 ) ) {
if ( F_49 ( V_2 , V_187 ) ) {
if ( ( V_81 = F_67 ( V_171 , L_8 ,
V_187 , 1 , V_2 ) ) < 0 )
return V_81 ;
}
}
if ( ! ( V_2 -> V_111 & V_205 ) ) {
if ( F_49 ( V_2 , V_206 ) ) {
if ( ( V_81 = F_67 ( V_171 , L_9 ,
V_206 , 1 , V_2 ) ) < 0 )
return V_81 ;
if ( ( V_81 = F_60 ( V_171 , F_55 ( & V_207 , V_2 ) ) ) < 0 )
return V_81 ;
}
}
if ( F_49 ( V_2 , V_208 ) ) {
if ( ( V_81 = F_67 ( V_171 , L_10 ,
V_208 , 1 , V_2 ) ) < 0 )
return V_81 ;
}
if ( ! ( V_2 -> V_111 & V_209 ) ) {
if ( F_49 ( V_2 , V_210 ) ) {
if ( ( V_81 = F_67 ( V_171 , L_11 ,
V_210 , 1 , V_2 ) ) < 0 )
return V_81 ;
}
}
if ( ! ( V_2 -> V_111 & V_211 ) ) {
if ( F_49 ( V_2 , V_212 ) ) {
if ( ( V_81 = F_67 ( V_171 , L_12 ,
V_212 , 1 , V_2 ) ) < 0 )
return V_81 ;
}
}
if ( ! ( V_2 -> V_111 & V_213 ) ) {
if ( F_49 ( V_2 , V_214 ) ) {
if ( ( V_81 = F_67 ( V_171 , L_13 ,
V_214 , 1 , V_2 ) ) < 0 )
return V_81 ;
}
}
if ( V_2 -> V_111 & V_193 ) {
unsigned short V_215 ;
if ( V_2 -> V_111 & V_129 )
V_215 = 0x9f9f ;
else
V_215 = 0x9f1f ;
for ( V_191 = 0 ; V_191 < 2 ; V_191 ++ )
if ( ( V_81 = F_60 ( V_171 , V_86 = F_55 ( & V_216 [ V_191 ] , V_2 ) ) ) < 0 )
return V_81 ;
F_62 ( V_86 , V_179 ) ;
V_2 -> V_43 . V_44 . V_45 [ 0 ] = V_215 ;
if ( V_2 -> V_88 & V_217 ) {
for ( V_191 = 0 ; V_191 < 2 ; V_191 ++ )
if ( ( V_81 = F_60 ( V_171 , V_86 = F_55 ( & V_218 [ V_191 ] , V_2 ) ) ) < 0 )
return V_81 ;
F_62 ( V_86 , V_179 ) ;
V_2 -> V_43 . V_44 . V_45 [ 1 ] = V_215 ;
}
if ( V_2 -> V_88 & V_219 ) {
for ( V_191 = 0 ; V_191 < 2 ; V_191 ++ )
if ( ( V_81 = F_60 ( V_171 , V_86 = F_55 ( & V_220 [ V_191 ] , V_2 ) ) ) < 0 )
return V_81 ;
F_62 ( V_86 , V_179 ) ;
for ( V_191 = 0 ; V_191 < 2 ; V_191 ++ )
if ( ( V_81 = F_60 ( V_171 , V_86 = F_55 ( & V_221 [ V_191 ] , V_2 ) ) ) < 0 )
return V_81 ;
F_62 ( V_86 , V_179 ) ;
V_2 -> V_43 . V_44 . V_45 [ 2 ] = V_215 ;
}
F_6 ( V_2 , V_49 , V_215 ) ;
} else {
if ( ! ( V_2 -> V_111 & V_222 ) ) {
if ( V_2 -> V_111 & V_223 )
V_81 = F_66 ( V_171 ,
L_14 ,
V_49 , 0 , V_2 ) ;
else
V_81 = F_67 ( V_171 , L_15 ,
V_49 , 0 , V_2 ) ;
if ( V_81 < 0 )
return V_81 ;
}
}
if ( ! ( V_2 -> V_111 & V_224 ) ) {
if ( ( V_81 = F_60 ( V_171 , F_55 ( & V_225 , V_2 ) ) ) < 0 )
return V_81 ;
if ( F_52 ( V_2 , V_226 , 15 ) ) {
V_81 = F_66 ( V_171 , L_16 ,
V_226 , 0 , V_2 ) ;
if ( V_81 < 0 )
return V_81 ;
}
if ( ( V_81 = F_60 ( V_171 , V_86 = F_55 ( & V_227 , V_2 ) ) ) < 0 )
return V_81 ;
F_62 ( V_86 , V_228 ) ;
F_6 ( V_2 , V_229 , 0x0000 ) ;
F_6 ( V_2 , V_226 , 0x0000 ) ;
}
if ( F_49 ( V_2 , V_145 ) ) {
for ( V_191 = 0 ; V_191 < 2 ; V_191 ++ )
if ( ( V_81 = F_60 ( V_171 , V_86 = F_55 ( & V_230 [ V_191 ] , V_2 ) ) ) < 0 )
return V_81 ;
F_62 ( V_86 , V_228 ) ;
F_6 ( V_2 , V_145 , 0x0000 ) ;
}
if ( F_52 ( V_2 , V_231 , 15 ) ) {
if ( ( V_81 = F_60 ( V_171 , F_55 ( & V_232 [ V_233 ] , V_2 ) ) ) < 0 )
return V_81 ;
}
if ( V_2 -> V_142 & V_234 ) {
if ( ( V_81 = F_60 ( V_171 , F_55 ( & V_232 [ V_235 ] , V_2 ) ) ) < 0 )
return V_81 ;
}
if ( F_52 ( V_2 , V_231 , 13 ) ) {
if ( ( V_81 = F_60 ( V_171 , F_55 ( & V_232 [ V_236 ] , V_2 ) ) ) < 0 )
return V_81 ;
}
if ( V_2 -> V_142 & V_237 ) {
if ( ( V_81 = F_60 ( V_171 , F_55 ( & V_232 [ V_238 ] , V_2 ) ) ) < 0 )
return V_81 ;
}
if ( F_52 ( V_2 , V_231 , 9 ) ) {
if ( ( V_81 = F_60 ( V_171 , F_55 ( & V_232 [ V_239 ] , V_2 ) ) ) < 0 )
return V_81 ;
}
if ( F_52 ( V_2 , V_231 , 8 ) ) {
if ( ( V_81 = F_60 ( V_171 , F_55 ( & V_232 [ V_240 ] , V_2 ) ) ) < 0 )
return V_81 ;
}
if ( V_241 && F_52 ( V_2 , V_231 , 7 ) ) {
if ( ( V_81 = F_60 ( V_171 , F_55 ( & V_232 [ V_242 ] , V_2 ) ) ) < 0 )
return V_81 ;
}
F_11 ( V_2 , V_231 , ~ V_243 , 0x0000 ) ;
if ( V_2 -> V_244 -> V_245 ) {
V_2 -> V_244 -> V_245 ( V_2 ) ;
} else {
if ( F_49 ( V_2 , V_147 ) ) {
unsigned short V_62 ;
V_62 = 0x0707 ;
F_2 ( V_2 , V_147 , V_62 ) ;
V_62 = F_3 ( V_2 , V_147 ) ;
V_62 = V_62 == 0x0606 ;
if ( ( V_81 = F_60 ( V_171 , V_86 = F_55 ( & V_246 [ 0 ] , V_2 ) ) ) < 0 )
return V_81 ;
if ( V_62 )
V_86 -> V_56 = V_147 | ( 9 << 8 ) | ( 7 << 16 ) ;
if ( ( V_81 = F_60 ( V_171 , V_86 = F_55 ( & V_246 [ 1 ] , V_2 ) ) ) < 0 )
return V_81 ;
if ( V_62 )
V_86 -> V_56 = V_147 | ( 1 << 8 ) | ( 7 << 16 ) ;
F_6 ( V_2 , V_147 , 0x0000 ) ;
}
}
if ( V_2 -> V_247 == 0x1043 &&
V_2 -> V_248 == 0x810f )
V_2 -> V_67 |= V_249 ;
if ( ( V_2 -> V_67 & V_249 ) && ! ( V_2 -> V_88 & V_250 ) ) {
if ( V_2 -> V_244 -> V_251 ) {
if ( ( V_81 = V_2 -> V_244 -> V_251 ( V_2 ) ) < 0 )
return V_81 ;
} else {
for ( V_191 = 0 ; V_191 < 5 ; V_191 ++ )
if ( ( V_81 = F_60 ( V_171 , F_55 ( & V_252 [ V_191 ] , V_2 ) ) ) < 0 )
return V_81 ;
if ( V_2 -> V_244 -> V_253 ) {
if ( ( V_81 = V_2 -> V_244 -> V_253 ( V_2 ) ) < 0 )
return V_81 ;
}
F_6 ( V_2 , V_127 , 0x2a20 ) ;
V_2 -> V_254 [ V_255 ] = F_68 ( V_2 ) ;
}
V_2 -> V_102 = V_256 ;
}
if ( V_2 -> V_244 -> V_257 )
if ( ( V_81 = V_2 -> V_244 -> V_257 ( V_2 ) ) < 0 )
return V_81 ;
if ( F_52 ( V_2 , V_87 , 15 ) ) {
V_86 = F_55 ( & V_258 , V_2 ) ;
if ( ! V_86 )
return - V_186 ;
if ( V_2 -> V_88 & V_89 )
F_26 ( V_2 , V_86 ) ;
if ( ( V_81 = F_60 ( V_171 , V_86 ) ) < 0 )
return V_81 ;
}
return 0 ;
}
static int F_69 ( struct V_170 * V_171 , struct V_1 * V_2 )
{
int V_81 , V_191 ;
F_2 ( V_2 , V_259 , 0xffff & ~ ( V_260 ) ) ;
F_2 ( V_2 , V_261 , 0xffff & ~ ( V_260 ) ) ;
F_2 ( V_2 , V_262 , 0xffff ) ;
F_2 ( V_2 , V_263 , 0x0 ) ;
F_2 ( V_2 , V_264 , 0x0 ) ;
for ( V_191 = 0 ; V_191 < F_51 ( V_265 ) ; V_191 ++ )
if ( ( V_81 = F_60 ( V_171 , F_56 ( & V_265 [ V_191 ] , V_2 ) ) ) < 0 )
return V_81 ;
if ( V_2 -> V_244 -> V_257 )
if ( ( V_81 = V_2 -> V_244 -> V_257 ( V_2 ) ) < 0 )
return V_81 ;
return 0 ;
}
static int F_70 ( struct V_1 * V_2 , int V_3 , int V_266 , int V_267 )
{
unsigned short V_62 ;
unsigned int V_176 ;
V_176 = ( ( unsigned int ) V_267 * V_2 -> V_27 -> clock ) / 48000 ;
F_6 ( V_2 , V_3 , V_176 & 0xffff ) ;
if ( V_266 )
F_6 ( V_2 , V_266 , V_176 & 0xffff ) ;
V_62 = F_3 ( V_2 , V_3 ) ;
return V_62 == ( V_176 & 0xffff ) ;
}
static void F_71 ( struct V_1 * V_2 , int V_3 , int V_266 , unsigned int * V_268 )
{
unsigned int V_269 = 0 ;
unsigned short V_270 ;
if ( V_2 -> V_27 -> V_271 ) {
* V_268 = V_272 ;
if ( ( V_2 -> V_111 & V_273 ) &&
V_3 == V_274 )
* V_268 |= V_275 ;
return;
}
V_270 = F_3 ( V_2 , V_3 ) ;
if ( ( V_2 -> V_67 & V_276 ) && V_3 == V_274 )
F_11 ( V_2 , V_125 ,
V_277 , 0 ) ;
if ( F_70 ( V_2 , V_3 , V_266 , 11000 ) )
V_269 |= V_278 ;
if ( F_70 ( V_2 , V_3 , V_266 , 8000 ) )
V_269 |= V_279 ;
if ( F_70 ( V_2 , V_3 , V_266 , 11025 ) )
V_269 |= V_280 ;
if ( F_70 ( V_2 , V_3 , V_266 , 16000 ) )
V_269 |= V_281 ;
if ( F_70 ( V_2 , V_3 , V_266 , 22050 ) )
V_269 |= V_282 ;
if ( F_70 ( V_2 , V_3 , V_266 , 32000 ) )
V_269 |= V_283 ;
if ( F_70 ( V_2 , V_3 , V_266 , 44100 ) )
V_269 |= V_284 ;
if ( F_70 ( V_2 , V_3 , V_266 , 48000 ) )
V_269 |= V_272 ;
if ( ( V_2 -> V_111 & V_273 ) &&
V_3 == V_274 ) {
F_11 ( V_2 , V_125 ,
V_277 , V_277 ) ;
if ( F_70 ( V_2 , V_3 , V_266 , 64000 / 2 ) )
V_269 |= V_285 ;
if ( F_70 ( V_2 , V_3 , V_266 , 88200 / 2 ) )
V_269 |= V_286 ;
if ( F_70 ( V_2 , V_3 , V_266 , 96000 / 2 ) )
V_269 |= V_275 ;
if ( ! F_70 ( V_2 , V_3 , V_266 , 76100 / 2 ) )
V_269 &= ~ V_278 ;
F_11 ( V_2 , V_125 ,
V_277 , 0 ) ;
}
F_6 ( V_2 , V_3 , V_270 ) ;
if ( V_266 )
F_6 ( V_2 , V_266 , V_270 ) ;
* V_268 = V_269 ;
}
static unsigned int F_68 ( struct V_1 * V_2 )
{
unsigned int V_269 = 0 ;
int V_157 ;
static unsigned short V_287 [] = {
V_288 , V_289 , V_290
} ;
static unsigned int V_291 [] = {
V_284 , V_283 , V_272
} ;
for ( V_157 = 0 ; V_157 < ( int ) F_51 ( V_287 ) ; V_157 ++ ) {
F_11 ( V_2 , V_127 , V_292 , V_287 [ V_157 ] ) ;
if ( ( F_3 ( V_2 , V_127 ) & V_292 ) == V_287 [ V_157 ] )
V_269 |= V_291 [ V_157 ] ;
}
return V_269 ;
}
static const struct V_293 * F_72 ( const struct V_293 * V_294 ,
unsigned int V_4 )
{
const struct V_293 * V_295 ;
for ( V_295 = V_294 ; V_295 -> V_4 ; V_295 ++ )
if ( V_295 -> V_4 == ( V_4 & V_295 -> V_37 ) )
return V_295 ;
return NULL ;
}
void F_73 ( struct V_1 * V_2 , unsigned int V_4 , char * V_172 , int V_296 )
{
const struct V_293 * V_295 ;
sprintf ( V_172 , L_17 , V_4 ,
F_54 ( V_4 >> 24 ) ,
F_54 ( V_4 >> 16 ) ,
F_54 ( V_4 >> 8 ) ) ;
V_295 = F_72 ( V_297 , V_4 ) ;
if ( ! V_295 )
return;
strcpy ( V_172 , V_295 -> V_172 ) ;
if ( V_2 && V_295 -> V_298 ) {
if ( ( V_296 && ( V_295 -> V_111 & V_299 ) ) ||
( ! V_296 && ! ( V_295 -> V_111 & V_299 ) ) )
V_295 -> V_298 ( V_2 ) ;
}
V_295 = F_72 ( V_300 , V_4 ) ;
if ( V_295 ) {
strcat ( V_172 , L_18 ) ;
strcat ( V_172 , V_295 -> V_172 ) ;
if ( V_295 -> V_37 != 0xffffffff )
sprintf ( V_172 + strlen ( V_172 ) , L_19 , V_4 & ~ V_295 -> V_37 ) ;
if ( V_2 && V_295 -> V_298 ) {
if ( ( V_296 && ( V_295 -> V_111 & V_299 ) ) ||
( ! V_296 && ! ( V_295 -> V_111 & V_299 ) ) )
V_295 -> V_298 ( V_2 ) ;
}
} else
sprintf ( V_172 + strlen ( V_172 ) , L_20 , V_4 & 0xff ) ;
}
const char * F_74 ( struct V_1 * V_2 )
{
const struct V_293 * V_295 ;
for ( V_295 = V_300 ; V_295 -> V_4 ; V_295 ++ )
if ( V_295 -> V_4 == ( V_2 -> V_4 & V_295 -> V_37 ) )
return V_295 -> V_172 ;
return L_21 ;
}
static int F_75 ( struct V_1 * V_2 , int V_301 , int V_302 )
{
unsigned long V_303 ;
unsigned short V_62 ;
V_303 = V_304 + V_301 ;
do {
F_3 ( V_2 , V_30 ) ;
F_3 ( V_2 , V_305 ) ;
F_3 ( V_2 , V_306 ) ;
if ( V_302 ) {
V_62 = F_3 ( V_2 , V_307 ) ;
if ( V_62 != 0xffff && ( V_62 & 1 ) != 0 )
return 0 ;
}
if ( V_2 -> V_88 & V_308 ) {
V_62 = F_3 ( V_2 , V_305 ) ;
if ( V_62 != 0 && V_62 != 0xffff )
return 0 ;
} else {
F_6 ( V_2 , V_226 , 0x8a05 ) ;
if ( ( F_3 ( V_2 , V_226 ) & 0x7fff ) == 0x0a05 )
return 0 ;
}
F_76 ( 1 ) ;
} while ( F_77 ( V_303 , V_304 ) );
return - V_309 ;
}
int V_132 ( struct V_170 * V_171 , int V_139 , struct V_310 * V_28 ,
void * V_311 , struct V_132 * * V_312 )
{
int V_81 ;
struct V_132 * V_27 ;
static struct V_313 V_314 = {
. V_315 = F_43 ,
} ;
if ( F_78 ( ! V_171 ) )
return - V_36 ;
V_27 = F_79 ( sizeof( * V_27 ) , V_316 ) ;
if ( V_27 == NULL )
return - V_186 ;
V_27 -> V_171 = V_171 ;
V_27 -> V_139 = V_139 ;
V_27 -> V_28 = V_28 ;
V_27 -> V_311 = V_311 ;
V_27 -> clock = 48000 ;
F_80 ( & V_27 -> V_317 ) ;
F_81 ( V_27 ) ;
if ( ( V_81 = F_82 ( V_171 , V_318 , V_27 , & V_314 ) ) < 0 ) {
F_40 ( V_27 ) ;
return V_81 ;
}
if ( V_312 )
* V_312 = V_27 ;
return 0 ;
}
static void F_83 ( struct V_136 * V_319 )
{
}
static int F_84 ( struct V_135 * V_136 )
{
struct V_1 * V_2 = V_136 -> V_137 ;
int V_81 ;
V_2 -> V_319 . V_27 = & V_320 ;
V_2 -> V_319 . V_321 = V_2 -> V_27 -> V_171 -> V_319 ;
V_2 -> V_319 . V_322 = F_83 ;
F_85 ( & V_2 -> V_319 , L_22 ,
V_2 -> V_27 -> V_171 -> V_323 , V_2 -> V_139 ,
F_74 ( V_2 ) ) ;
if ( ( V_81 = F_86 ( & V_2 -> V_319 ) ) < 0 ) {
F_87 ( V_2 , L_23 ) ;
V_2 -> V_319 . V_27 = NULL ;
return V_81 ;
}
return 0 ;
}
static int F_88 ( struct V_135 * V_136 )
{
struct V_1 * V_2 = V_136 -> V_137 ;
if ( V_2 -> V_319 . V_27 )
F_89 ( & V_2 -> V_319 ) ;
return 0 ;
}
static void F_90 ( struct V_324 * V_325 )
{
F_25 (
F_91 ( V_325 , struct V_1 , V_138 . V_325 ) ) ;
}
int F_92 ( struct V_132 * V_27 , struct V_326 * V_168 , struct V_1 * * V_327 )
{
int V_81 ;
struct V_1 * V_2 ;
struct V_170 * V_171 ;
char V_172 [ 64 ] ;
unsigned long V_303 ;
unsigned int V_3 ;
const struct V_293 * V_295 ;
static struct V_313 V_28 = {
. V_315 = F_47 ,
. V_328 = F_84 ,
. V_329 = F_88 ,
} ;
if ( V_327 )
* V_327 = NULL ;
if ( F_78 ( ! V_27 || ! V_168 ) )
return - V_36 ;
if ( F_78 ( V_168 -> V_139 >= 4 ) )
return - V_36 ;
if ( V_27 -> V_40 [ V_168 -> V_139 ] )
return - V_330 ;
V_171 = V_27 -> V_171 ;
V_2 = F_79 ( sizeof( * V_2 ) , V_316 ) ;
if ( V_2 == NULL )
return - V_186 ;
V_2 -> V_311 = V_168 -> V_311 ;
V_2 -> V_134 = V_168 -> V_134 ;
V_2 -> V_27 = V_27 ;
V_2 -> V_331 = V_168 -> V_331 ;
V_2 -> V_139 = V_168 -> V_139 ;
V_2 -> V_332 = V_168 -> V_332 ;
V_2 -> V_88 = V_168 -> V_88 ;
V_2 -> V_158 = V_168 -> V_158 ;
V_27 -> V_40 [ V_2 -> V_139 ] = V_2 ;
F_93 ( & V_2 -> V_34 ) ;
F_93 ( & V_2 -> V_42 ) ;
#ifdef F_24
F_94 ( & V_2 -> V_138 , F_90 ) ;
#endif
#ifdef F_95
if ( V_2 -> V_331 ) {
F_96 ( V_2 -> V_331 , V_333 , & V_2 -> V_247 ) ;
F_96 ( V_2 -> V_331 , V_334 , & V_2 -> V_248 ) ;
}
#endif
if ( V_27 -> V_28 -> V_335 ) {
V_27 -> V_28 -> V_335 ( V_2 ) ;
goto V_336;
}
V_2 -> V_4 = F_3 ( V_2 , V_305 ) << 16 ;
V_2 -> V_4 |= F_3 ( V_2 , V_306 ) ;
if ( V_2 -> V_4 && V_2 -> V_4 != ( unsigned int ) - 1 ) {
V_295 = F_72 ( V_300 , V_2 -> V_4 ) ;
if ( V_295 && ( V_295 -> V_111 & V_337 ) )
goto V_336;
}
if ( ! ( V_2 -> V_88 & V_338 ) )
F_2 ( V_2 , V_30 , 0 ) ;
if ( ! ( V_2 -> V_88 & V_339 ) )
F_2 ( V_2 , V_307 , 0 ) ;
if ( V_27 -> V_28 -> V_340 )
V_27 -> V_28 -> V_340 ( V_2 ) ;
else {
F_97 ( 50 ) ;
if ( V_2 -> V_88 & V_338 )
V_81 = F_75 ( V_2 , F_98 ( 500 ) , 1 ) ;
else {
V_81 = F_75 ( V_2 , F_98 ( 500 ) , 0 ) ;
if ( V_81 < 0 )
V_81 = F_75 ( V_2 ,
F_98 ( 500 ) , 1 ) ;
}
if ( V_81 < 0 ) {
F_99 ( V_2 , L_24 ,
V_2 -> V_139 ) ;
}
}
V_336:
V_2 -> V_4 = F_3 ( V_2 , V_305 ) << 16 ;
V_2 -> V_4 |= F_3 ( V_2 , V_306 ) ;
if ( ! ( V_2 -> V_88 & V_308 ) &&
( V_2 -> V_4 == 0x00000000 || V_2 -> V_4 == 0xffffffff ) ) {
F_87 ( V_2 ,
L_25 ,
V_2 -> V_139 , V_2 -> V_4 ) ;
F_44 ( V_2 ) ;
return - V_341 ;
}
V_295 = F_72 ( V_300 , V_2 -> V_4 ) ;
if ( V_295 )
V_2 -> V_111 |= V_295 -> V_111 ;
if ( ! ( V_2 -> V_88 & V_338 ) && ! ( V_2 -> V_88 & V_342 ) ) {
F_6 ( V_2 , V_226 , 0x8a06 ) ;
if ( ( ( V_81 = F_3 ( V_2 , V_226 ) ) & 0x7fff ) == 0x0a06 )
V_2 -> V_88 |= V_342 ;
}
if ( V_2 -> V_88 & V_342 ) {
V_2 -> V_142 = F_3 ( V_2 , V_30 ) ;
V_2 -> V_67 = F_3 ( V_2 , V_343 ) ;
if ( V_2 -> V_67 == 0xffff )
V_2 -> V_67 = 0 ;
}
if ( ! ( V_2 -> V_88 & V_339 ) && ! ( V_2 -> V_88 & V_344 ) ) {
V_2 -> V_345 = F_3 ( V_2 , V_307 ) ;
if ( V_2 -> V_345 == 0xffff )
V_2 -> V_345 = 0 ;
if ( V_2 -> V_345 & 1 )
V_2 -> V_88 |= V_344 ;
}
if ( ! F_100 ( V_2 ) && ! F_101 ( V_2 ) ) {
if ( ! ( V_2 -> V_88 & ( V_338 | V_339 ) ) )
F_87 ( V_2 ,
L_26 ,
V_2 -> V_139 ) ;
F_44 ( V_2 ) ;
return - V_346 ;
}
if ( V_27 -> V_28 -> V_335 )
goto V_347;
if ( F_100 ( V_2 ) ) {
F_6 ( V_2 , V_87 , 0 ) ;
if ( ! ( V_2 -> V_111 & V_337 ) ) {
F_6 ( V_2 , V_30 , 0 ) ;
F_97 ( 100 ) ;
F_6 ( V_2 , V_87 , 0 ) ;
}
F_6 ( V_2 , V_231 , 0 ) ;
V_303 = V_304 + F_98 ( 5000 ) ;
do {
if ( ( F_3 ( V_2 , V_87 ) & 0x0f ) == 0x0f )
goto V_347;
F_76 ( 1 ) ;
} while ( F_77 ( V_303 , V_304 ) );
F_99 ( V_2 ,
L_27 , V_2 -> V_139 ) ;
}
if ( F_101 ( V_2 ) ) {
unsigned char V_176 ;
V_176 = V_348 ;
if ( V_2 -> V_345 & V_349 ) {
F_6 ( V_2 , V_350 , 8000 ) ;
V_176 |= V_351 | V_352 ;
}
if ( V_2 -> V_345 & V_353 ) {
F_6 ( V_2 , V_354 , 8000 ) ;
V_176 |= V_355 | V_356 ;
}
if ( V_2 -> V_345 & V_357 ) {
F_6 ( V_2 , V_358 , 8000 ) ;
V_176 |= V_359 | V_360 ;
}
F_6 ( V_2 , V_361 , 0 ) ;
F_97 ( 100 ) ;
F_6 ( V_2 , V_361 , 0 ) ;
V_303 = V_304 + F_98 ( 100 ) ;
do {
if ( ( F_3 ( V_2 , V_361 ) & V_176 ) == V_176 )
goto V_347;
F_76 ( 1 ) ;
} while ( F_77 ( V_303 , V_304 ) );
F_99 ( V_2 ,
L_28 ,
V_2 -> V_139 ,
F_3 ( V_2 , V_361 ) ) ;
}
V_347:
if ( F_100 ( V_2 ) )
V_2 -> V_332 = ( V_2 -> V_67 & V_362 ) >> V_363 ;
else
V_2 -> V_332 = ( V_2 -> V_345 & V_364 ) >> V_365 ;
if ( V_2 -> V_67 & 0x01c9 ) {
V_3 = F_3 ( V_2 , V_125 ) ;
V_3 |= V_2 -> V_67 & 0x01c0 ;
if ( ! V_27 -> V_271 )
V_3 |= V_2 -> V_67 & 0x0009 ;
F_6 ( V_2 , V_125 , V_3 ) ;
}
if ( ( V_2 -> V_67 & V_276 ) && V_27 -> V_366 ) {
F_11 ( V_2 , V_231 , V_243 , V_367 ) ;
if ( ( F_3 ( V_2 , V_231 ) & V_243 ) == V_367 )
V_2 -> V_111 |= V_273 ;
F_11 ( V_2 , V_231 , V_243 , 0 ) ;
}
if ( V_2 -> V_67 & V_368 ) {
F_71 ( V_2 , V_274 , 0 , & V_2 -> V_254 [ V_369 ] ) ;
F_71 ( V_2 , V_370 , 0 , & V_2 -> V_254 [ V_371 ] ) ;
} else {
V_2 -> V_254 [ V_369 ] = V_272 ;
if ( V_2 -> V_111 & V_273 )
V_2 -> V_254 [ V_369 ] |= V_275 ;
V_2 -> V_254 [ V_371 ] = V_272 ;
}
if ( V_2 -> V_67 & V_249 ) {
V_2 -> V_254 [ V_255 ] = V_272 | V_284 | V_283 ;
}
if ( V_2 -> V_67 & V_372 ) {
F_71 ( V_2 , V_373 , 0 , & V_2 -> V_254 [ V_374 ] ) ;
} else {
V_2 -> V_254 [ V_374 ] = V_272 ;
}
if ( V_2 -> V_67 & V_153 ) {
F_71 ( V_2 , V_375 , V_274 , & V_2 -> V_254 [ V_376 ] ) ;
V_2 -> V_88 |= V_217 ;
}
if ( V_2 -> V_67 & V_151 ) {
F_71 ( V_2 , V_377 , V_274 , & V_2 -> V_254 [ V_378 ] ) ;
V_2 -> V_88 |= V_219 ;
}
if ( V_27 -> V_28 -> V_379 )
V_27 -> V_28 -> V_379 ( V_2 ) ;
F_73 ( V_2 , V_2 -> V_4 , V_172 , ! F_100 ( V_2 ) ) ;
F_73 ( NULL , V_2 -> V_4 , V_172 , ! F_100 ( V_2 ) ) ;
if ( ! V_2 -> V_244 )
V_2 -> V_244 = & V_380 ;
if ( F_100 ( V_2 ) ) {
char V_381 [ 16 ] ;
if ( V_171 -> V_382 [ 0 ] == '\0' ) {
strcpy ( V_171 -> V_382 , V_172 ) ;
} else {
if ( strlen ( V_171 -> V_382 ) + 1 + strlen ( V_172 ) + 1 <= sizeof( V_171 -> V_382 ) ) {
strcat ( V_171 -> V_382 , L_29 ) ;
strcat ( V_171 -> V_382 , V_172 ) ;
}
}
sprintf ( V_381 , L_30 , V_2 -> V_4 ) ;
if ( ( V_81 = F_102 ( V_171 , V_381 ) ) < 0 ) {
F_44 ( V_2 ) ;
return V_81 ;
}
if ( F_65 ( V_2 ) < 0 ) {
F_44 ( V_2 ) ;
return - V_186 ;
}
}
if ( F_101 ( V_2 ) ) {
char V_381 [ 16 ] ;
if ( V_171 -> V_382 [ 0 ] == '\0' ) {
strcpy ( V_171 -> V_382 , V_172 ) ;
} else {
if ( strlen ( V_171 -> V_382 ) + 1 + strlen ( V_172 ) + 1 <= sizeof( V_171 -> V_382 ) ) {
strcat ( V_171 -> V_382 , L_29 ) ;
strcat ( V_171 -> V_382 , V_172 ) ;
}
}
sprintf ( V_381 , L_31 , V_2 -> V_4 ) ;
if ( ( V_81 = F_102 ( V_171 , V_381 ) ) < 0 ) {
F_44 ( V_2 ) ;
return V_81 ;
}
if ( F_69 ( V_171 , V_2 ) < 0 ) {
F_44 ( V_2 ) ;
return - V_186 ;
}
}
if ( F_100 ( V_2 ) )
F_25 ( V_2 ) ;
F_103 ( V_2 ) ;
if ( ( V_81 = F_82 ( V_171 , V_383 , V_2 , & V_28 ) ) < 0 ) {
F_44 ( V_2 ) ;
return V_81 ;
}
* V_327 = V_2 ;
return 0 ;
}
static void F_48 ( struct V_1 * V_2 )
{
unsigned short V_384 ;
if ( F_100 ( V_2 ) ) {
F_2 ( V_2 , V_25 , 0x9f9f ) ;
F_2 ( V_2 , V_26 , 0x9f9f ) ;
}
V_384 = V_2 -> V_33 [ V_125 ] ;
if ( V_2 -> V_88 & V_217 )
V_384 |= V_385 ;
if ( V_2 -> V_88 & V_219 )
V_384 |= V_386 | V_387 ;
V_384 |= V_388 ;
F_2 ( V_2 , V_125 , V_384 ) ;
if ( V_2 -> V_88 & V_89 )
V_384 = V_2 -> V_33 [ V_87 ] & ~ V_84 ;
else if ( ! ( V_2 -> V_88 & V_389 ) )
V_384 = V_2 -> V_33 [ V_87 ] | V_84 ;
V_384 |= V_390 ;
V_384 |= V_391 | V_392 ;
F_2 ( V_2 , V_87 , V_384 ) ;
F_97 ( 100 ) ;
V_384 |= V_393 ;
F_2 ( V_2 , V_87 , V_384 ) ;
if ( F_104 ( V_2 ) ) {
V_384 |= V_394 ;
F_2 ( V_2 , V_87 , V_384 ) ;
F_97 ( 100 ) ;
V_384 |= V_395 | V_396 ;
F_2 ( V_2 , V_87 , V_384 ) ;
}
}
int F_105 ( struct V_1 * V_2 , int V_3 , int V_397 )
{
int V_157 ;
if ( ! V_2 )
return 0 ;
if ( V_3 ) {
if ( V_3 == V_127 )
V_3 = V_274 ;
for ( V_157 = 0 ; V_157 < V_398 ; V_157 ++ ) {
if ( V_399 [ V_157 ] . V_3 == V_3 ) {
if ( V_397 )
V_2 -> V_85 |= ( 1 << V_157 ) ;
else
V_2 -> V_85 &= ~ ( 1 << V_157 ) ;
break;
}
}
}
if ( F_104 ( V_2 ) && ! V_397 )
F_106 ( & V_2 -> V_138 ,
F_98 ( V_400 * 1000 ) ) ;
else {
F_107 ( & V_2 -> V_138 ) ;
F_25 ( V_2 ) ;
}
return 0 ;
}
static void F_25 ( struct V_1 * V_2 )
{
unsigned int V_85 , V_161 ;
int V_157 ;
V_85 = ( 1 << V_401 ) | ( 1 << V_402 ) ;
V_85 |= ( 1 << V_403 ) ;
if ( V_2 -> V_88 & V_217 )
V_85 |= ( 1 << V_404 ) ;
if ( V_2 -> V_88 & V_219 )
V_85 |= ( 1 << V_405 ) ;
#ifdef F_24
if ( F_104 ( V_2 ) )
V_85 = V_2 -> V_85 ;
#endif
if ( V_85 ) {
if ( V_2 -> V_33 [ V_87 ] & V_393 ) {
F_11 ( V_2 , V_87 ,
V_394 , 0 ) ;
F_108 ( 1 ) ;
F_11 ( V_2 , V_87 ,
V_393 , 0 ) ;
}
}
for ( V_157 = 0 ; V_157 < V_398 ; V_157 ++ ) {
if ( V_85 & ( 1 << V_157 ) )
V_161 = 0 ;
else
V_161 = V_399 [ V_157 ] . V_37 ;
F_11 ( V_2 , V_399 [ V_157 ] . V_406 ,
V_399 [ V_157 ] . V_37 , V_161 ) ;
}
if ( ! V_85 ) {
if ( ! ( V_2 -> V_33 [ V_87 ] & V_393 ) ) {
F_11 ( V_2 , V_87 ,
V_393 , V_393 ) ;
F_11 ( V_2 , V_87 ,
V_394 , V_394 ) ;
}
}
}
void F_109 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return;
if ( V_2 -> V_244 -> V_407 )
V_2 -> V_244 -> V_407 ( V_2 ) ;
#ifdef F_24
F_45 ( & V_2 -> V_138 ) ;
#endif
F_48 ( V_2 ) ;
}
static void F_110 ( struct V_1 * V_2 )
{
int V_157 ;
for ( V_157 = 2 ; V_157 < 0x7c ; V_157 += 2 ) {
if ( V_157 == V_87 || V_157 == V_343 )
continue;
if ( F_5 ( V_157 , V_2 -> V_32 ) ) {
F_2 ( V_2 , V_157 , V_2 -> V_33 [ V_157 ] ) ;
F_3 ( V_2 , V_157 ) ;
}
}
}
static void F_111 ( struct V_1 * V_2 )
{
if ( V_2 -> V_67 & V_249 ) {
if ( V_2 -> V_33 [ V_125 ] & V_126 ) {
F_11 ( V_2 , V_125 , V_126 , 0 ) ;
F_2 ( V_2 , V_125 , V_2 -> V_33 [ V_125 ] ) ;
if ( V_2 -> V_111 & V_112 )
F_2 ( V_2 , V_114 , V_2 -> V_33 [ V_114 ] ) ;
else
F_2 ( V_2 , V_127 , V_2 -> V_33 [ V_127 ] ) ;
F_11 ( V_2 , V_125 , V_126 , V_126 ) ;
}
}
}
void F_112 ( struct V_1 * V_2 )
{
unsigned long V_303 ;
if ( ! V_2 )
return;
if ( V_2 -> V_27 -> V_28 -> V_335 ) {
V_2 -> V_27 -> V_28 -> V_335 ( V_2 ) ;
goto V_408;
}
F_2 ( V_2 , V_87 , 0 ) ;
if ( ! ( V_2 -> V_111 & V_337 ) ) {
if ( ! ( V_2 -> V_88 & V_338 ) )
F_2 ( V_2 , V_30 , 0 ) ;
else if ( ! ( V_2 -> V_88 & V_339 ) )
F_2 ( V_2 , V_307 , 0 ) ;
F_97 ( 100 ) ;
F_2 ( V_2 , V_87 , 0 ) ;
}
F_2 ( V_2 , V_231 , 0 ) ;
F_2 ( V_2 , V_87 , V_2 -> V_33 [ V_87 ] ) ;
if ( F_100 ( V_2 ) ) {
V_2 -> V_27 -> V_28 -> V_29 ( V_2 , V_25 , 0x8101 ) ;
V_303 = V_304 + F_98 ( 100 ) ;
do {
if ( F_3 ( V_2 , V_25 ) == 0x8101 )
break;
F_76 ( 1 ) ;
} while ( F_77 ( V_303 , V_304 ) );
V_2 -> V_27 -> V_28 -> V_29 ( V_2 , V_25 , V_140 ) ;
if ( F_3 ( V_2 , V_25 ) != V_140 )
F_108 ( 250 ) ;
} else {
V_303 = V_304 + F_98 ( 100 ) ;
do {
unsigned short V_62 = F_3 ( V_2 , V_307 ) ;
if ( V_62 != 0xffff && ( V_62 & 1 ) != 0 )
break;
F_76 ( 1 ) ;
} while ( F_77 ( V_303 , V_304 ) );
}
V_408:
if ( V_2 -> V_27 -> V_28 -> V_379 )
V_2 -> V_27 -> V_28 -> V_379 ( V_2 ) ;
if ( V_2 -> V_244 -> V_409 )
V_2 -> V_244 -> V_409 ( V_2 ) ;
else {
F_110 ( V_2 ) ;
F_111 ( V_2 ) ;
}
}
static void F_113 ( char * V_410 , const char * V_411 , const char * V_412 )
{
if ( V_412 )
sprintf ( V_410 , L_32 , V_411 , V_412 ) ;
else
strcpy ( V_410 , V_411 ) ;
}
static int F_114 ( struct V_1 * V_2 , const char * V_172 ,
const char * V_412 )
{
struct V_413 V_4 ;
memset ( & V_4 , 0 , sizeof( V_4 ) ) ;
F_113 ( V_4 . V_172 , V_172 , V_412 ) ;
V_4 . V_414 = V_415 ;
return F_115 ( V_2 -> V_27 -> V_171 , & V_4 ) ;
}
static struct V_50 * F_116 ( struct V_1 * V_2 , const char * V_172 , const char * V_412 )
{
struct V_413 V_416 ;
memset ( & V_416 , 0 , sizeof( V_416 ) ) ;
F_113 ( V_416 . V_172 , V_172 , V_412 ) ;
V_416 . V_414 = V_415 ;
return F_117 ( V_2 -> V_27 -> V_171 , & V_416 ) ;
}
static int F_118 ( struct V_1 * V_2 , const char * V_411 ,
const char * V_410 , const char * V_412 )
{
struct V_50 * V_86 = F_116 ( V_2 , V_411 , V_412 ) ;
if ( V_86 ) {
F_113 ( V_86 -> V_4 . V_172 , V_410 , V_412 ) ;
return 0 ;
}
return - V_417 ;
}
static void F_119 ( struct V_1 * V_2 , const char * V_411 ,
const char * V_410 )
{
F_118 ( V_2 , V_411 , V_410 , L_33 ) ;
F_118 ( V_2 , V_411 , V_410 , L_34 ) ;
}
static int F_120 ( struct V_1 * V_2 , const char * V_418 ,
const char * V_419 , const char * V_412 )
{
struct V_50 * V_420 , * V_421 ;
V_420 = F_116 ( V_2 , V_418 , V_412 ) ;
V_421 = F_116 ( V_2 , V_419 , V_412 ) ;
if ( V_420 && V_421 ) {
F_113 ( V_420 -> V_4 . V_172 , V_419 , V_412 ) ;
F_113 ( V_421 -> V_4 . V_172 , V_418 , V_412 ) ;
return 0 ;
}
return - V_417 ;
}
static int F_121 ( struct V_50 * V_51 , struct V_60 * V_61 )
{
int V_81 = F_23 ( V_51 , V_61 ) ;
if ( V_81 > 0 ) {
unsigned long V_422 = V_51 -> V_56 ;
V_51 -> V_56 = ( V_51 -> V_56 & ~ 0xff ) | V_26 ;
F_23 ( V_51 , V_61 ) ;
V_51 -> V_56 = V_422 ;
}
return V_81 ;
}
static int F_122 ( struct V_1 * V_2 )
{
struct V_50 * V_423 = F_116 ( V_2 , L_3 , NULL ) ;
struct V_50 * V_424 = F_116 ( V_2 , L_35 , NULL ) ;
if ( ! V_423 || ! V_424 )
return - V_417 ;
V_423 -> V_425 = F_121 ;
V_424 -> V_425 = F_121 ;
F_114 ( V_2 , L_6 , L_33 ) ;
F_114 ( V_2 , L_6 , L_34 ) ;
return 0 ;
}
static int F_122 ( struct V_1 * V_2 )
{
if ( F_116 ( V_2 , L_36 , NULL ) == NULL )
return - V_417 ;
F_114 ( V_2 , L_4 , L_33 ) ;
F_114 ( V_2 , L_4 , L_34 ) ;
F_119 ( V_2 , L_6 , L_4 ) ;
return 0 ;
}
static int F_123 ( struct V_1 * V_2 )
{
if ( F_116 ( V_2 , L_36 , NULL ) == NULL )
return - V_417 ;
F_119 ( V_2 , L_4 , L_37 ) ;
F_119 ( V_2 , L_6 , L_4 ) ;
return 0 ;
}
static int F_124 ( struct V_1 * V_2 )
{
if ( F_120 ( V_2 , L_4 , L_5 , L_33 ) ||
F_120 ( V_2 , L_4 , L_5 , L_34 ) )
return - V_417 ;
return 0 ;
}
static int F_125 ( struct V_1 * V_2 )
{
unsigned short V_426 ;
if ( ( V_2 -> V_4 & 0xffffff00 ) != 0x41445300 ) {
F_87 ( V_2 , L_38 ) ;
return - V_36 ;
}
V_426 = F_3 ( V_2 , V_46 ) ;
F_6 ( V_2 , V_46 , V_426 | 0x0200 ) ;
return 0 ;
}
static int F_126 ( struct V_1 * V_2 )
{
if ( ( V_2 -> V_4 & 0xffffff00 ) != 0x414c4700 ) {
F_87 ( V_2 ,
L_39 ) ;
return - V_36 ;
}
F_11 ( V_2 , 0x7a , 0x20 , 0x20 ) ;
F_11 ( V_2 , 0x7a , 0x01 , 0x01 ) ;
if ( V_2 -> V_4 == V_427 )
F_11 ( V_2 , 0x74 , 0x0800 , 0x0800 ) ;
return F_60 ( V_2 -> V_27 -> V_171 , F_55 ( & V_428 , V_2 ) ) ;
}
static int F_127 ( struct V_1 * V_2 )
{
struct V_50 * V_86 = F_116 ( V_2 , L_40 , NULL ) ;
if ( ! V_86 )
return - V_417 ;
F_26 ( V_2 , V_86 ) ;
return 0 ;
}
static int F_128 ( struct V_50 * V_51 , struct V_60 * V_61 )
{
int V_81 = F_23 ( V_51 , V_61 ) ;
if ( V_81 > 0 ) {
struct V_1 * V_2 = F_17 ( V_51 ) ;
int V_73 = ( V_51 -> V_56 >> 8 ) & 0x0f ;
int V_74 = ( V_51 -> V_56 >> 12 ) & 0x0f ;
unsigned short V_37 ;
if ( V_73 != V_74 )
V_37 = V_162 ;
else
V_37 = V_140 ;
F_11 ( V_2 , V_87 , V_84 ,
( V_2 -> V_33 [ V_25 ] & V_37 ) == V_37 ?
V_84 : 0 ) ;
}
return V_81 ;
}
static int F_129 ( struct V_1 * V_2 )
{
struct V_50 * V_423 = F_116 ( V_2 , L_3 , NULL ) ;
if ( ! V_423 )
return - V_417 ;
V_423 -> V_425 = F_128 ;
F_114 ( V_2 , L_40 , NULL ) ;
F_11 (
V_2 , V_87 ,
V_84 , V_84
) ;
V_2 -> V_88 |= V_389 ;
return 0 ;
}
static int F_130 ( struct V_50 * V_51 ,
struct V_60 * V_61 )
{
int V_81 = F_121 ( V_51 , V_61 ) ;
if ( V_81 > 0 ) {
struct V_1 * V_2 = F_17 ( V_51 ) ;
int V_73 = ( V_51 -> V_56 >> 8 ) & 0x0f ;
int V_74 = ( V_51 -> V_56 >> 12 ) & 0x0f ;
unsigned short V_37 ;
if ( V_73 != V_74 )
V_37 = V_162 ;
else
V_37 = V_140 ;
F_11 ( V_2 , V_87 , V_84 ,
( V_2 -> V_33 [ V_25 ] & V_37 ) == V_37 ?
V_84 : 0 ) ;
}
return V_81 ;
}
static int F_131 ( struct V_1 * V_2 )
{
struct V_50 * V_423 = F_116 ( V_2 , L_3 , NULL ) ;
struct V_50 * V_424 = F_116 ( V_2 , L_35 , NULL ) ;
if ( ! V_423 || ! V_424 )
return - V_417 ;
V_423 -> V_425 = F_130 ;
V_424 -> V_425 = F_121 ;
F_114 ( V_2 , L_40 , NULL ) ;
F_114 ( V_2 , L_6 , L_33 ) ;
F_114 ( V_2 , L_6 , L_34 ) ;
F_11 (
V_2 , V_87 ,
V_84 , V_84
) ;
return 0 ;
}
static int F_132 ( struct V_1 * V_2 , int type )
{
if ( type <= 0 )
return 0 ;
else if ( type >= F_51 ( V_429 ) )
return - V_36 ;
if ( V_429 [ type ] . V_430 )
return V_429 [ type ] . V_430 ( V_2 ) ;
return 0 ;
}
static int F_133 ( struct V_1 * V_2 , const char * V_431 )
{
int V_157 ;
struct V_432 * V_433 ;
for ( V_157 = 0 ; V_157 < F_51 ( V_429 ) ; V_157 ++ ) {
V_433 = & V_429 [ V_157 ] ;
if ( V_433 -> V_172 && ! strcmp ( V_431 , V_433 -> V_172 ) )
return F_132 ( V_2 , V_157 ) ;
}
if ( * V_431 >= '0' && * V_431 <= '9' )
return F_132 ( V_2 , ( int ) F_134 ( V_431 , NULL , 10 ) ) ;
return - V_36 ;
}
int F_135 ( struct V_1 * V_2 ,
const struct V_434 * V_435 , const char * V_436 )
{
int V_269 ;
if ( V_436 && strcmp ( V_436 , L_41 ) && strcmp ( V_436 , L_42 ) ) {
V_269 = F_133 ( V_2 , V_436 ) ;
if ( V_269 < 0 )
F_87 ( V_2 , L_43 ,
V_436 , V_269 ) ;
return V_269 ;
}
if ( ! V_435 )
return - V_36 ;
for (; V_435 -> V_437 ; V_435 ++ ) {
if ( V_435 -> V_437 != V_2 -> V_247 )
continue;
if ( ( ! V_435 -> V_37 && V_435 -> V_438 == V_2 -> V_248 ) ||
V_435 -> V_438 == ( V_435 -> V_37 & V_2 -> V_248 ) ) {
if ( V_435 -> V_439 && V_435 -> V_439 != V_2 -> V_4 )
continue;
F_136 ( V_2 , L_44 ,
V_435 -> V_172 , V_2 -> V_247 ,
V_2 -> V_248 ) ;
V_269 = F_132 ( V_2 , V_435 -> type ) ;
if ( V_269 < 0 )
F_87 ( V_2 ,
L_45 ,
V_435 -> type , V_435 -> V_172 , V_269 ) ;
return V_269 ;
}
}
return 0 ;
}
static int T_1 F_137 ( void )
{
return 0 ;
}
static void T_2 F_138 ( void )
{
}
