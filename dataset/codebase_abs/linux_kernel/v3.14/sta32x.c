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
static int F_8 ( struct V_11 * V_12 )
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
static int F_9 ( struct V_11 * V_12 )
{
struct V_23 * V_24 = F_7 ( V_12 ) ;
unsigned int V_29 ;
int V_30 ;
V_29 = F_4 ( V_12 , V_31 ) ;
F_5 ( V_12 , V_31 , V_29 | V_32 ) ;
F_8 ( V_12 ) ;
V_30 = F_10 ( V_24 -> V_33 ) ;
F_5 ( V_12 , V_31 , V_29 ) ;
return V_30 ;
}
static void F_11 ( struct V_34 * V_35 )
{
struct V_23 * V_24 = F_12 ( V_35 , struct V_23 ,
V_36 . V_35 ) ;
struct V_11 * V_12 = V_24 -> V_12 ;
unsigned int V_37 , V_38 ;
V_38 = F_4 ( V_12 , V_39 ) ;
F_13 ( V_24 -> V_33 , true ) ;
V_37 = F_4 ( V_12 , V_39 ) ;
F_13 ( V_24 -> V_33 , false ) ;
if ( V_37 != V_38 ) {
F_14 ( V_24 -> V_33 ) ;
F_9 ( V_12 ) ;
}
if ( ! V_24 -> V_40 )
F_15 ( V_41 ,
& V_24 -> V_36 ,
F_16 ( V_42 ) ) ;
}
static void F_17 ( struct V_23 * V_24 )
{
if ( V_24 -> V_43 -> V_44 ) {
V_24 -> V_40 = 0 ;
F_15 ( V_41 ,
& V_24 -> V_36 ,
F_16 ( V_42 ) ) ;
}
}
static void F_18 ( struct V_23 * V_24 )
{
if ( V_24 -> V_43 -> V_44 ) {
V_24 -> V_40 = 1 ;
F_19 ( & V_24 -> V_36 ) ;
}
}
static int F_20 ( struct V_45 * V_46 ,
int V_47 , unsigned int V_48 , int V_49 )
{
struct V_11 * V_12 = V_46 -> V_12 ;
struct V_23 * V_24 = F_7 ( V_12 ) ;
int V_15 , V_50 , V_51 , V_52 ;
unsigned int V_53 = 0 ;
unsigned int V_54 = - 1 ;
unsigned int V_55 = 0 ;
F_21 ( L_1 , V_48 ) ;
V_24 -> V_56 = V_48 ;
if ( V_24 -> V_56 ) {
for ( V_15 = 0 ; V_15 < F_22 ( V_57 ) ; V_15 ++ ) {
V_51 = V_57 [ V_15 ] . V_51 ;
V_52 = V_57 [ V_15 ] . V_52 ;
for ( V_50 = 0 ; V_58 [ V_51 ] [ V_50 ] . V_59 ; V_50 ++ ) {
if ( V_58 [ V_51 ] [ V_50 ] . V_59 * V_52 == V_48 ) {
V_53 |= F_23 ( V_52 ) ;
if ( V_52 < V_54 )
V_54 = V_52 ;
if ( V_52 > V_55 )
V_55 = V_52 ;
break;
}
}
}
V_53 &= ~ V_60 ;
if ( ! V_53 ) {
F_24 ( V_12 -> V_61 , L_2 ) ;
return - V_18 ;
}
} else {
V_53 = V_62 ;
V_54 = 32000 ;
V_55 = 192000 ;
}
V_46 -> V_63 -> V_64 . V_53 = V_53 ;
V_46 -> V_63 -> V_64 . V_54 = V_54 ;
V_46 -> V_63 -> V_64 . V_55 = V_55 ;
return 0 ;
}
static int F_25 ( struct V_45 * V_46 ,
unsigned int V_65 )
{
struct V_11 * V_12 = V_46 -> V_12 ;
struct V_23 * V_24 = F_7 ( V_12 ) ;
T_1 V_66 = F_4 ( V_12 , V_67 ) ;
F_21 ( L_3 ) ;
V_66 &= ~ ( V_68 | V_69 ) ;
switch ( V_65 & V_70 ) {
case V_71 :
break;
default:
return - V_18 ;
}
switch ( V_65 & V_72 ) {
case V_73 :
case V_74 :
case V_75 :
V_24 -> V_76 = V_65 & V_72 ;
break;
default:
return - V_18 ;
}
switch ( V_65 & V_77 ) {
case V_78 :
V_66 |= V_69 ;
break;
case V_79 :
V_66 |= V_68 ;
break;
default:
return - V_18 ;
}
F_5 ( V_12 , V_67 , V_66 ) ;
return 0 ;
}
static int F_26 ( struct V_80 * V_81 ,
struct V_82 * V_83 ,
struct V_45 * V_84 )
{
struct V_11 * V_12 = V_84 -> V_12 ;
struct V_23 * V_24 = F_7 ( V_12 ) ;
unsigned int V_85 ;
int V_15 , V_86 = - 1 , V_51 = - 1 ;
T_1 V_37 , V_66 ;
V_85 = F_27 ( V_83 ) ;
F_21 ( L_4 , V_85 ) ;
for ( V_15 = 0 ; V_15 < F_22 ( V_57 ) ; V_15 ++ )
if ( V_57 [ V_15 ] . V_52 == V_85 ) {
V_51 = V_57 [ V_15 ] . V_51 ;
break;
}
if ( V_51 < 0 )
return - V_18 ;
for ( V_15 = 0 ; V_58 [ V_51 ] [ V_15 ] . V_59 ; V_15 ++ )
if ( V_58 [ V_51 ] [ V_15 ] . V_59 * V_85 == V_24 -> V_56 ) {
V_86 = V_58 [ V_51 ] [ V_15 ] . V_86 ;
break;
}
if ( V_86 < 0 )
return - V_18 ;
V_37 = F_4 ( V_12 , V_39 ) ;
V_37 &= ~ ( V_87 | V_88 ) ;
V_37 |= ( V_51 << V_89 ) | ( V_86 << V_90 ) ;
V_66 = F_4 ( V_12 , V_67 ) ;
V_66 &= ~ ( V_91 | V_92 ) ;
switch ( F_28 ( V_83 ) ) {
case V_93 :
case V_94 :
case V_95 :
case V_96 :
F_21 ( L_5 ) ;
case V_97 :
case V_98 :
F_21 ( L_6 ) ;
switch ( V_24 -> V_76 ) {
case V_73 :
V_66 |= 0x0 ;
break;
case V_75 :
V_66 |= 0x1 ;
break;
case V_74 :
V_66 |= 0x2 ;
break;
}
break;
case V_99 :
case V_100 :
F_21 ( L_7 ) ;
switch ( V_24 -> V_76 ) {
case V_73 :
V_66 |= 0x4 ;
break;
case V_75 :
V_66 |= 0x5 ;
break;
case V_74 :
V_66 |= 0x6 ;
break;
}
break;
case V_101 :
case V_102 :
F_21 ( L_8 ) ;
switch ( V_24 -> V_76 ) {
case V_73 :
V_66 |= 0x8 ;
break;
case V_75 :
V_66 |= 0x9 ;
break;
case V_74 :
V_66 |= 0xa ;
break;
}
break;
case V_103 :
case V_104 :
F_21 ( L_9 ) ;
switch ( V_24 -> V_76 ) {
case V_73 :
V_66 |= 0x0 ;
break;
case V_75 :
V_66 |= 0xd ;
break;
case V_74 :
V_66 |= 0xe ;
break;
}
break;
default:
return - V_18 ;
}
F_5 ( V_12 , V_39 , V_37 ) ;
F_5 ( V_12 , V_67 , V_66 ) ;
return 0 ;
}
static int F_29 ( struct V_11 * V_12 ,
enum V_105 V_106 )
{
int V_107 ;
struct V_23 * V_24 = F_7 ( V_12 ) ;
F_21 ( L_10 , V_106 ) ;
switch ( V_106 ) {
case V_108 :
break;
case V_109 :
F_30 ( V_12 , V_110 ,
V_111 | V_112 ,
V_111 | V_112 ) ;
break;
case V_113 :
if ( V_12 -> V_114 . V_115 == V_116 ) {
V_107 = F_31 ( F_22 ( V_24 -> V_117 ) ,
V_24 -> V_117 ) ;
if ( V_107 != 0 ) {
F_24 ( V_12 -> V_61 ,
L_11 , V_107 ) ;
return V_107 ;
}
F_9 ( V_12 ) ;
F_17 ( V_24 ) ;
}
F_30 ( V_12 , V_110 ,
V_111 | V_112 ,
V_111 | V_112 ) ;
break;
case V_116 :
F_30 ( V_12 , V_110 ,
V_111 | V_112 ,
V_111 ) ;
F_32 ( 300 ) ;
F_18 ( V_24 ) ;
F_33 ( F_22 ( V_24 -> V_117 ) ,
V_24 -> V_117 ) ;
break;
}
V_12 -> V_114 . V_115 = V_106 ;
return 0 ;
}
static int F_34 ( struct V_11 * V_12 )
{
F_29 ( V_12 , V_116 ) ;
return 0 ;
}
static int F_35 ( struct V_11 * V_12 )
{
F_29 ( V_12 , V_113 ) ;
return 0 ;
}
static int F_36 ( struct V_11 * V_12 )
{
struct V_23 * V_24 = F_7 ( V_12 ) ;
int V_15 , V_107 = 0 , V_118 = 0 ;
V_24 -> V_12 = V_12 ;
V_24 -> V_43 = F_37 ( V_12 -> V_61 ) ;
V_107 = F_31 ( F_22 ( V_24 -> V_117 ) ,
V_24 -> V_117 ) ;
if ( V_107 != 0 ) {
F_24 ( V_12 -> V_61 , L_11 , V_107 ) ;
return V_107 ;
}
V_12 -> V_119 = V_24 -> V_33 ;
V_107 = F_38 ( V_12 , 8 , 8 , V_120 ) ;
if ( V_107 < 0 ) {
F_24 ( V_12 -> V_61 , L_12 , V_107 ) ;
goto V_121;
}
F_39 ( V_24 -> V_33 , true ) ;
F_5 ( V_12 , V_122 , 0xc2 ) ;
F_5 ( V_12 , V_123 , 0xc2 ) ;
F_5 ( V_12 , V_110 , 0x5c ) ;
F_5 ( V_12 , V_31 , 0x10 ) ;
F_5 ( V_12 , V_124 , 0x60 ) ;
F_5 ( V_12 , V_125 , 0x00 ) ;
F_5 ( V_12 , V_126 , 0x40 ) ;
F_39 ( V_24 -> V_33 , false ) ;
if ( ! ( V_24 -> V_43 -> V_127 & V_128 ) )
V_118 |= V_129 ;
if ( ! ( V_24 -> V_43 -> V_127 & V_130 ) )
V_118 |= V_131 ;
F_30 ( V_12 , V_39 ,
V_129 | V_131 ,
V_118 ) ;
F_30 ( V_12 , V_110 ,
V_132 ,
V_24 -> V_43 -> V_133
<< V_134 ) ;
F_30 ( V_12 , V_135 ,
V_136 ,
V_24 -> V_43 -> V_137
<< V_138 ) ;
F_30 ( V_12 , V_139 ,
V_136 ,
V_24 -> V_43 -> V_140
<< V_138 ) ;
F_30 ( V_12 , V_126 ,
V_136 ,
V_24 -> V_43 -> V_141
<< V_138 ) ;
for ( V_15 = 4 ; V_15 <= 49 ; V_15 += 5 )
V_24 -> V_26 [ V_15 ] = 0x400000 ;
for ( V_15 = 50 ; V_15 <= 54 ; V_15 ++ )
V_24 -> V_26 [ V_15 ] = 0x7fffff ;
V_24 -> V_26 [ 55 ] = 0x5a9df7 ;
V_24 -> V_26 [ 56 ] = 0x7fffff ;
V_24 -> V_26 [ 59 ] = 0x7fffff ;
V_24 -> V_26 [ 60 ] = 0x400000 ;
V_24 -> V_26 [ 61 ] = 0x400000 ;
if ( V_24 -> V_43 -> V_44 )
F_40 ( & V_24 -> V_36 , F_11 ) ;
F_29 ( V_12 , V_113 ) ;
F_33 ( F_22 ( V_24 -> V_117 ) , V_24 -> V_117 ) ;
return 0 ;
V_121:
F_33 ( F_22 ( V_24 -> V_117 ) , V_24 -> V_117 ) ;
return V_107 ;
}
static int F_41 ( struct V_11 * V_12 )
{
struct V_23 * V_24 = F_7 ( V_12 ) ;
F_18 ( V_24 ) ;
F_29 ( V_12 , V_116 ) ;
F_33 ( F_22 ( V_24 -> V_117 ) , V_24 -> V_117 ) ;
return 0 ;
}
static bool F_42 ( struct V_142 * V_61 , unsigned int V_143 )
{
switch ( V_143 ) {
case V_39 ... V_144 :
case V_145 ... V_146 :
return 0 ;
}
return 1 ;
}
static int F_43 ( struct V_147 * V_148 ,
const struct V_149 * V_150 )
{
struct V_23 * V_24 ;
int V_107 , V_15 ;
V_24 = F_44 ( & V_148 -> V_61 , sizeof( struct V_23 ) ,
V_151 ) ;
if ( ! V_24 )
return - V_152 ;
for ( V_15 = 0 ; V_15 < F_22 ( V_24 -> V_117 ) ; V_15 ++ )
V_24 -> V_117 [ V_15 ] . V_153 = V_154 [ V_15 ] ;
V_107 = F_45 ( & V_148 -> V_61 , F_22 ( V_24 -> V_117 ) ,
V_24 -> V_117 ) ;
if ( V_107 != 0 ) {
F_24 ( & V_148 -> V_61 , L_13 , V_107 ) ;
return V_107 ;
}
V_24 -> V_33 = F_46 ( V_148 , & V_155 ) ;
if ( F_47 ( V_24 -> V_33 ) ) {
V_107 = F_48 ( V_24 -> V_33 ) ;
F_24 ( & V_148 -> V_61 , L_14 , V_107 ) ;
return V_107 ;
}
F_49 ( V_148 , V_24 ) ;
V_107 = F_50 ( & V_148 -> V_61 , & V_156 , & V_157 , 1 ) ;
if ( V_107 != 0 )
F_24 ( & V_148 -> V_61 , L_15 , V_107 ) ;
return V_107 ;
}
static int F_51 ( struct V_147 * V_158 )
{
F_52 ( & V_158 -> V_61 ) ;
return 0 ;
}
