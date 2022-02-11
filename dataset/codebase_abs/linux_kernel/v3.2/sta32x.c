static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_5 = V_2 -> V_6 >> 16 ;
V_4 -> type = V_7 ;
V_4 -> V_8 = 3 * V_5 ;
return 0 ;
}
static int F_2 ( struct V_1 * V_2 ,
struct V_9 * V_10 )
{
struct V_11 * V_12 = F_3 ( V_2 ) ;
int V_5 = V_2 -> V_6 >> 16 ;
int V_13 = V_2 -> V_6 & 0xffff ;
unsigned int V_14 ;
int V_15 ;
V_14 = F_4 ( V_12 , V_16 ) & 0xf0 ;
F_5 ( V_12 , V_16 , V_14 ) ;
F_5 ( V_12 , V_17 , V_13 ) ;
if ( V_5 == 1 )
F_5 ( V_12 , V_16 , V_14 | 0x04 ) ;
else if ( V_5 == 5 )
F_5 ( V_12 , V_16 , V_14 | 0x08 ) ;
else
return - V_18 ;
for ( V_15 = 0 ; V_15 < 3 * V_5 ; V_15 ++ )
V_10 -> V_19 . V_20 . V_21 [ V_15 ] =
F_4 ( V_12 , V_22 + V_15 ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_9 * V_10 )
{
struct V_11 * V_12 = F_3 ( V_2 ) ;
struct V_23 * V_24 = F_7 ( V_12 ) ;
int V_5 = V_2 -> V_6 >> 16 ;
int V_13 = V_2 -> V_6 & 0xffff ;
unsigned int V_14 ;
int V_15 ;
V_14 = F_4 ( V_12 , V_16 ) & 0xf0 ;
F_5 ( V_12 , V_16 , V_14 ) ;
F_5 ( V_12 , V_17 , V_13 ) ;
for ( V_15 = 0 ; V_15 < V_5 && ( V_13 + V_15 < V_25 ) ; V_15 ++ )
V_24 -> V_26 [ V_13 + V_15 ] =
( V_10 -> V_19 . V_20 . V_21 [ 3 * V_15 ] << 16 )
| ( V_10 -> V_19 . V_20 . V_21 [ 3 * V_15 + 1 ] << 8 )
| ( V_10 -> V_19 . V_20 . V_21 [ 3 * V_15 + 2 ] ) ;
for ( V_15 = 0 ; V_15 < 3 * V_5 ; V_15 ++ )
F_5 ( V_12 , V_22 + V_15 ,
V_10 -> V_19 . V_20 . V_21 [ V_15 ] ) ;
if ( V_5 == 1 )
F_5 ( V_12 , V_16 , V_14 | 0x01 ) ;
else if ( V_5 == 5 )
F_5 ( V_12 , V_16 , V_14 | 0x02 ) ;
else
return - V_18 ;
return 0 ;
}
int F_8 ( struct V_11 * V_12 )
{
struct V_23 * V_24 = F_7 ( V_12 ) ;
unsigned int V_14 ;
int V_15 ;
V_14 = F_4 ( V_12 , V_16 ) & 0xf0 ;
for ( V_15 = 0 ; V_15 < V_25 ; V_15 ++ ) {
F_5 ( V_12 , V_17 , V_15 ) ;
F_5 ( V_12 , V_22 ,
( V_24 -> V_26 [ V_15 ] >> 16 ) & 0xff ) ;
F_5 ( V_12 , V_27 ,
( V_24 -> V_26 [ V_15 ] >> 8 ) & 0xff ) ;
F_5 ( V_12 , V_28 ,
( V_24 -> V_26 [ V_15 ] ) & 0xff ) ;
F_5 ( V_12 , V_16 , V_14 ) ;
F_5 ( V_12 , V_16 , V_14 | 0x01 ) ;
}
return 0 ;
}
int F_9 ( struct V_11 * V_12 )
{
unsigned int V_29 ;
int V_30 ;
if ( ! V_12 -> V_31 )
return 0 ;
V_29 = F_4 ( V_12 , V_32 ) ;
F_5 ( V_12 , V_32 , V_29 | V_33 ) ;
F_8 ( V_12 ) ;
V_30 = F_10 ( V_12 ) ;
F_5 ( V_12 , V_32 , V_29 ) ;
return V_30 ;
}
static int F_11 ( struct V_34 * V_35 ,
int V_36 , unsigned int V_37 , int V_38 )
{
struct V_11 * V_12 = V_35 -> V_12 ;
struct V_23 * V_24 = F_7 ( V_12 ) ;
int V_15 , V_39 , V_40 , V_41 ;
unsigned int V_42 = 0 ;
unsigned int V_43 = - 1 ;
unsigned int V_44 = 0 ;
F_12 ( L_1 , V_37 ) ;
V_24 -> V_45 = V_37 ;
if ( V_24 -> V_45 ) {
for ( V_15 = 0 ; V_15 < F_13 ( V_46 ) ; V_15 ++ ) {
V_40 = V_46 [ V_15 ] . V_40 ;
V_41 = V_46 [ V_15 ] . V_41 ;
for ( V_39 = 0 ; V_47 [ V_40 ] [ V_39 ] . V_48 ; V_39 ++ ) {
if ( V_47 [ V_40 ] [ V_39 ] . V_48 * V_41 == V_37 ) {
V_42 |= F_14 ( V_41 ) ;
if ( V_41 < V_43 )
V_43 = V_41 ;
if ( V_41 > V_44 )
V_44 = V_41 ;
}
}
}
V_42 &= ~ V_49 ;
if ( ! V_42 ) {
F_15 ( V_12 -> V_50 , L_2 ) ;
return - V_18 ;
}
} else {
V_42 = V_51 ;
V_43 = 32000 ;
V_44 = 192000 ;
}
V_35 -> V_52 -> V_53 . V_42 = V_42 ;
V_35 -> V_52 -> V_53 . V_43 = V_43 ;
V_35 -> V_52 -> V_53 . V_44 = V_44 ;
return 0 ;
}
static int F_16 ( struct V_34 * V_35 ,
unsigned int V_54 )
{
struct V_11 * V_12 = V_35 -> V_12 ;
struct V_23 * V_24 = F_7 ( V_12 ) ;
T_1 V_55 = F_4 ( V_12 , V_56 ) ;
F_12 ( L_3 ) ;
V_55 &= ~ ( V_57 | V_58 ) ;
switch ( V_54 & V_59 ) {
case V_60 :
break;
default:
return - V_18 ;
}
switch ( V_54 & V_61 ) {
case V_62 :
case V_63 :
case V_64 :
V_24 -> V_65 = V_54 & V_61 ;
break;
default:
return - V_18 ;
}
switch ( V_54 & V_66 ) {
case V_67 :
V_55 |= V_58 ;
break;
case V_68 :
V_55 |= V_57 ;
break;
default:
return - V_18 ;
}
F_5 ( V_12 , V_56 , V_55 ) ;
return 0 ;
}
static int F_17 ( struct V_69 * V_70 ,
struct V_71 * V_72 ,
struct V_34 * V_73 )
{
struct V_74 * V_75 = V_70 -> V_76 ;
struct V_11 * V_12 = V_75 -> V_12 ;
struct V_23 * V_24 = F_7 ( V_12 ) ;
unsigned int V_77 ;
int V_15 , V_78 = - 1 , V_40 = - 1 ;
T_1 V_79 , V_55 ;
V_77 = F_18 ( V_72 ) ;
F_12 ( L_4 , V_77 ) ;
for ( V_15 = 0 ; V_15 < F_13 ( V_46 ) ; V_15 ++ )
if ( V_46 [ V_15 ] . V_41 == V_77 ) {
V_40 = V_46 [ V_15 ] . V_40 ;
break;
}
if ( V_40 < 0 )
return - V_18 ;
for ( V_15 = 0 ; V_47 [ V_40 ] [ V_15 ] . V_48 ; V_15 ++ )
if ( V_47 [ V_40 ] [ V_15 ] . V_48 * V_77 == V_24 -> V_45 ) {
V_78 = V_47 [ V_40 ] [ V_15 ] . V_78 ;
break;
}
if ( V_78 < 0 )
return - V_18 ;
V_79 = F_4 ( V_12 , V_80 ) ;
V_79 &= ~ ( V_81 | V_82 ) ;
V_79 |= ( V_40 << V_83 ) | ( V_78 << V_84 ) ;
V_55 = F_4 ( V_12 , V_56 ) ;
V_55 &= ~ ( V_85 | V_86 ) ;
switch ( F_19 ( V_72 ) ) {
case V_87 :
case V_88 :
case V_89 :
case V_90 :
F_12 ( L_5 ) ;
case V_91 :
case V_92 :
F_12 ( L_6 ) ;
switch ( V_24 -> V_65 ) {
case V_62 :
V_55 |= 0x0 ;
break;
case V_64 :
V_55 |= 0x1 ;
break;
case V_63 :
V_55 |= 0x2 ;
break;
}
break;
case V_93 :
case V_94 :
F_12 ( L_7 ) ;
switch ( V_24 -> V_65 ) {
case V_62 :
V_55 |= 0x4 ;
break;
case V_64 :
V_55 |= 0x5 ;
break;
case V_63 :
V_55 |= 0x6 ;
break;
}
break;
case V_95 :
case V_96 :
F_12 ( L_8 ) ;
switch ( V_24 -> V_65 ) {
case V_62 :
V_55 |= 0x8 ;
break;
case V_64 :
V_55 |= 0x9 ;
break;
case V_63 :
V_55 |= 0xa ;
break;
}
break;
case V_97 :
case V_98 :
F_12 ( L_9 ) ;
switch ( V_24 -> V_65 ) {
case V_62 :
V_55 |= 0x0 ;
break;
case V_64 :
V_55 |= 0xd ;
break;
case V_63 :
V_55 |= 0xe ;
break;
}
break;
default:
return - V_18 ;
}
F_5 ( V_12 , V_80 , V_79 ) ;
F_5 ( V_12 , V_56 , V_55 ) ;
return 0 ;
}
static int F_20 ( struct V_11 * V_12 ,
enum V_99 V_100 )
{
int V_101 ;
struct V_23 * V_24 = F_7 ( V_12 ) ;
F_12 ( L_10 , V_100 ) ;
switch ( V_100 ) {
case V_102 :
break;
case V_103 :
F_21 ( V_12 , V_104 ,
V_105 | V_106 ,
V_105 | V_106 ) ;
break;
case V_107 :
if ( V_12 -> V_108 . V_109 == V_110 ) {
V_101 = F_22 ( F_13 ( V_24 -> V_111 ) ,
V_24 -> V_111 ) ;
if ( V_101 != 0 ) {
F_15 ( V_12 -> V_50 ,
L_11 , V_101 ) ;
return V_101 ;
}
F_9 ( V_12 ) ;
}
F_21 ( V_12 , V_104 ,
V_105 | V_106 ,
V_105 | V_106 ) ;
break;
case V_110 :
F_21 ( V_12 , V_104 ,
V_105 | V_106 ,
V_105 ) ;
F_23 ( 300 ) ;
F_24 ( F_13 ( V_24 -> V_111 ) ,
V_24 -> V_111 ) ;
break;
}
V_12 -> V_108 . V_109 = V_100 ;
return 0 ;
}
static int F_25 ( struct V_11 * V_12 , T_2 V_112 )
{
F_20 ( V_12 , V_110 ) ;
return 0 ;
}
static int F_26 ( struct V_11 * V_12 )
{
F_20 ( V_12 , V_107 ) ;
return 0 ;
}
static int F_27 ( struct V_11 * V_12 )
{
struct V_23 * V_24 = F_7 ( V_12 ) ;
int V_15 , V_101 = 0 ;
V_24 -> V_12 = V_12 ;
for ( V_15 = 0 ; V_15 < F_13 ( V_24 -> V_111 ) ; V_15 ++ )
V_24 -> V_111 [ V_15 ] . V_113 = V_114 [ V_15 ] ;
V_101 = F_28 ( V_12 -> V_50 , F_13 ( V_24 -> V_111 ) ,
V_24 -> V_111 ) ;
if ( V_101 != 0 ) {
F_15 ( V_12 -> V_50 , L_12 , V_101 ) ;
goto V_115;
}
V_101 = F_22 ( F_13 ( V_24 -> V_111 ) ,
V_24 -> V_111 ) ;
if ( V_101 != 0 ) {
F_15 ( V_12 -> V_50 , L_11 , V_101 ) ;
goto V_116;
}
V_101 = F_29 ( V_12 , 8 , 8 , V_117 ) ;
if ( V_101 < 0 ) {
F_15 ( V_12 -> V_50 , L_13 , V_101 ) ;
return V_101 ;
}
F_30 ( V_12 , V_118 , 0xc2 ) ;
F_30 ( V_12 , V_119 , 0xc2 ) ;
F_30 ( V_12 , V_104 , 0x5c ) ;
F_30 ( V_12 , V_32 , 0x10 ) ;
F_30 ( V_12 , V_120 , 0x60 ) ;
F_30 ( V_12 , V_121 , 0x00 ) ;
F_30 ( V_12 , V_122 , 0x40 ) ;
F_21 ( V_12 , V_80 ,
V_123 | V_124 , 0 ) ;
F_21 ( V_12 , V_104 ,
V_125 ,
1 << V_126 ) ;
F_21 ( V_12 , V_127 ,
V_128 ,
0 << V_129 ) ;
F_21 ( V_12 , V_130 ,
V_128 ,
1 << V_129 ) ;
F_21 ( V_12 , V_122 ,
V_128 ,
2 << V_129 ) ;
for ( V_15 = 4 ; V_15 <= 49 ; V_15 += 5 )
V_24 -> V_26 [ V_15 ] = 0x400000 ;
for ( V_15 = 50 ; V_15 <= 54 ; V_15 ++ )
V_24 -> V_26 [ V_15 ] = 0x7fffff ;
V_24 -> V_26 [ 55 ] = 0x5a9df7 ;
V_24 -> V_26 [ 56 ] = 0x7fffff ;
V_24 -> V_26 [ 59 ] = 0x7fffff ;
V_24 -> V_26 [ 60 ] = 0x400000 ;
V_24 -> V_26 [ 61 ] = 0x400000 ;
F_20 ( V_12 , V_107 ) ;
F_24 ( F_13 ( V_24 -> V_111 ) , V_24 -> V_111 ) ;
return 0 ;
V_116:
F_31 ( F_13 ( V_24 -> V_111 ) , V_24 -> V_111 ) ;
V_115:
return V_101 ;
}
static int F_32 ( struct V_11 * V_12 )
{
struct V_23 * V_24 = F_7 ( V_12 ) ;
F_20 ( V_12 , V_110 ) ;
F_24 ( F_13 ( V_24 -> V_111 ) , V_24 -> V_111 ) ;
F_31 ( F_13 ( V_24 -> V_111 ) , V_24 -> V_111 ) ;
return 0 ;
}
static int F_33 ( struct V_11 * V_12 ,
unsigned int V_131 )
{
switch ( V_131 ) {
case V_80 ... V_132 :
case V_133 ... V_134 :
return 0 ;
}
return 1 ;
}
static T_3 int F_34 ( struct V_135 * V_136 ,
const struct V_137 * V_138 )
{
struct V_23 * V_24 ;
int V_101 ;
V_24 = F_35 ( sizeof( struct V_23 ) , V_139 ) ;
if ( ! V_24 )
return - V_140 ;
F_36 ( V_136 , V_24 ) ;
V_101 = F_37 ( & V_136 -> V_50 , & V_141 , & V_142 , 1 ) ;
if ( V_101 != 0 ) {
F_15 ( & V_136 -> V_50 , L_14 , V_101 ) ;
F_38 ( V_24 ) ;
return V_101 ;
}
return 0 ;
}
static T_4 int F_39 ( struct V_135 * V_143 )
{
struct V_23 * V_24 = F_40 ( V_143 ) ;
F_41 ( & V_143 -> V_50 ) ;
F_38 ( V_24 ) ;
return 0 ;
}
static int T_5 F_42 ( void )
{
return F_43 ( & V_144 ) ;
}
static void T_6 F_44 ( void )
{
F_45 ( & V_144 ) ;
}
