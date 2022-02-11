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
static void F_11 ( struct V_34 * V_35 )
{
struct V_23 * V_24 = F_12 ( V_35 , struct V_23 ,
V_36 . V_35 ) ;
struct V_11 * V_12 = V_24 -> V_12 ;
unsigned int V_37 , V_38 ;
V_38 = F_4 ( V_12 , V_39 ) ;
V_12 -> V_40 = 1 ;
V_37 = F_4 ( V_12 , V_39 ) ;
V_12 -> V_40 = 0 ;
if ( V_37 != V_38 ) {
V_12 -> V_31 = 1 ;
F_9 ( V_12 ) ;
}
if ( ! V_24 -> V_41 )
F_13 ( & V_24 -> V_36 ,
F_14 ( V_42 ) ) ;
}
static void F_15 ( struct V_23 * V_24 )
{
if ( V_24 -> V_43 -> V_44 ) {
V_24 -> V_41 = 0 ;
F_13 ( & V_24 -> V_36 ,
F_14 ( V_42 ) ) ;
}
}
static void F_16 ( struct V_23 * V_24 )
{
if ( V_24 -> V_43 -> V_44 ) {
V_24 -> V_41 = 1 ;
F_17 ( & V_24 -> V_36 ) ;
}
}
static int F_18 ( struct V_45 * V_46 ,
int V_47 , unsigned int V_48 , int V_49 )
{
struct V_11 * V_12 = V_46 -> V_12 ;
struct V_23 * V_24 = F_7 ( V_12 ) ;
int V_15 , V_50 , V_51 , V_52 ;
unsigned int V_53 = 0 ;
unsigned int V_54 = - 1 ;
unsigned int V_55 = 0 ;
F_19 ( L_1 , V_48 ) ;
V_24 -> V_56 = V_48 ;
if ( V_24 -> V_56 ) {
for ( V_15 = 0 ; V_15 < F_20 ( V_57 ) ; V_15 ++ ) {
V_51 = V_57 [ V_15 ] . V_51 ;
V_52 = V_57 [ V_15 ] . V_52 ;
for ( V_50 = 0 ; V_58 [ V_51 ] [ V_50 ] . V_59 ; V_50 ++ ) {
if ( V_58 [ V_51 ] [ V_50 ] . V_59 * V_52 == V_48 ) {
V_53 |= F_21 ( V_52 ) ;
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
F_22 ( V_12 -> V_61 , L_2 ) ;
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
static int F_23 ( struct V_45 * V_46 ,
unsigned int V_65 )
{
struct V_11 * V_12 = V_46 -> V_12 ;
struct V_23 * V_24 = F_7 ( V_12 ) ;
T_1 V_66 = F_4 ( V_12 , V_67 ) ;
F_19 ( L_3 ) ;
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
static int F_24 ( struct V_80 * V_81 ,
struct V_82 * V_83 ,
struct V_45 * V_84 )
{
struct V_85 * V_86 = V_81 -> V_87 ;
struct V_11 * V_12 = V_86 -> V_12 ;
struct V_23 * V_24 = F_7 ( V_12 ) ;
unsigned int V_88 ;
int V_15 , V_89 = - 1 , V_51 = - 1 ;
T_1 V_37 , V_66 ;
V_88 = F_25 ( V_83 ) ;
F_19 ( L_4 , V_88 ) ;
for ( V_15 = 0 ; V_15 < F_20 ( V_57 ) ; V_15 ++ )
if ( V_57 [ V_15 ] . V_52 == V_88 ) {
V_51 = V_57 [ V_15 ] . V_51 ;
break;
}
if ( V_51 < 0 )
return - V_18 ;
for ( V_15 = 0 ; V_58 [ V_51 ] [ V_15 ] . V_59 ; V_15 ++ )
if ( V_58 [ V_51 ] [ V_15 ] . V_59 * V_88 == V_24 -> V_56 ) {
V_89 = V_58 [ V_51 ] [ V_15 ] . V_89 ;
break;
}
if ( V_89 < 0 )
return - V_18 ;
V_37 = F_4 ( V_12 , V_39 ) ;
V_37 &= ~ ( V_90 | V_91 ) ;
V_37 |= ( V_51 << V_92 ) | ( V_89 << V_93 ) ;
V_66 = F_4 ( V_12 , V_67 ) ;
V_66 &= ~ ( V_94 | V_95 ) ;
switch ( F_26 ( V_83 ) ) {
case V_96 :
case V_97 :
case V_98 :
case V_99 :
F_19 ( L_5 ) ;
case V_100 :
case V_101 :
F_19 ( L_6 ) ;
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
case V_102 :
case V_103 :
F_19 ( L_7 ) ;
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
case V_104 :
case V_105 :
F_19 ( L_8 ) ;
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
case V_106 :
case V_107 :
F_19 ( L_9 ) ;
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
static int F_27 ( struct V_11 * V_12 ,
enum V_108 V_109 )
{
int V_110 ;
struct V_23 * V_24 = F_7 ( V_12 ) ;
F_19 ( L_10 , V_109 ) ;
switch ( V_109 ) {
case V_111 :
break;
case V_112 :
F_28 ( V_12 , V_113 ,
V_114 | V_115 ,
V_114 | V_115 ) ;
break;
case V_116 :
if ( V_12 -> V_117 . V_118 == V_119 ) {
V_110 = F_29 ( F_20 ( V_24 -> V_120 ) ,
V_24 -> V_120 ) ;
if ( V_110 != 0 ) {
F_22 ( V_12 -> V_61 ,
L_11 , V_110 ) ;
return V_110 ;
}
F_9 ( V_12 ) ;
F_15 ( V_24 ) ;
}
F_28 ( V_12 , V_113 ,
V_114 | V_115 ,
V_114 | V_115 ) ;
break;
case V_119 :
F_28 ( V_12 , V_113 ,
V_114 | V_115 ,
V_114 ) ;
F_30 ( 300 ) ;
F_16 ( V_24 ) ;
F_31 ( F_20 ( V_24 -> V_120 ) ,
V_24 -> V_120 ) ;
break;
}
V_12 -> V_117 . V_118 = V_109 ;
return 0 ;
}
static int F_32 ( struct V_11 * V_12 )
{
F_27 ( V_12 , V_119 ) ;
return 0 ;
}
static int F_33 ( struct V_11 * V_12 )
{
F_27 ( V_12 , V_116 ) ;
return 0 ;
}
static int F_34 ( struct V_11 * V_12 )
{
struct V_23 * V_24 = F_7 ( V_12 ) ;
int V_15 , V_110 = 0 , V_121 = 0 ;
V_24 -> V_12 = V_12 ;
V_24 -> V_43 = F_35 ( V_12 -> V_61 ) ;
for ( V_15 = 0 ; V_15 < F_20 ( V_24 -> V_120 ) ; V_15 ++ )
V_24 -> V_120 [ V_15 ] . V_122 = V_123 [ V_15 ] ;
V_110 = F_36 ( V_12 -> V_61 , F_20 ( V_24 -> V_120 ) ,
V_24 -> V_120 ) ;
if ( V_110 != 0 ) {
F_22 ( V_12 -> V_61 , L_12 , V_110 ) ;
goto V_124;
}
V_110 = F_29 ( F_20 ( V_24 -> V_120 ) ,
V_24 -> V_120 ) ;
if ( V_110 != 0 ) {
F_22 ( V_12 -> V_61 , L_11 , V_110 ) ;
goto V_125;
}
V_110 = F_37 ( V_12 , 8 , 8 , V_126 ) ;
if ( V_110 < 0 ) {
F_22 ( V_12 -> V_61 , L_13 , V_110 ) ;
return V_110 ;
}
F_38 ( V_12 , V_127 , 0xc2 ) ;
F_38 ( V_12 , V_128 , 0xc2 ) ;
F_38 ( V_12 , V_113 , 0x5c ) ;
F_38 ( V_12 , V_32 , 0x10 ) ;
F_38 ( V_12 , V_129 , 0x60 ) ;
F_38 ( V_12 , V_130 , 0x00 ) ;
F_38 ( V_12 , V_131 , 0x40 ) ;
if ( ! ( V_24 -> V_43 -> V_132 & V_133 ) )
V_121 |= V_134 ;
if ( ! ( V_24 -> V_43 -> V_132 & V_135 ) )
V_121 |= V_136 ;
F_28 ( V_12 , V_39 ,
V_134 | V_136 ,
V_121 ) ;
F_28 ( V_12 , V_113 ,
V_137 ,
V_24 -> V_43 -> V_138
<< V_139 ) ;
F_28 ( V_12 , V_140 ,
V_141 ,
V_24 -> V_43 -> V_142
<< V_143 ) ;
F_28 ( V_12 , V_144 ,
V_141 ,
V_24 -> V_43 -> V_145
<< V_143 ) ;
F_28 ( V_12 , V_131 ,
V_141 ,
V_24 -> V_43 -> V_146
<< V_143 ) ;
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
F_39 ( & V_24 -> V_36 , F_11 ) ;
F_27 ( V_12 , V_116 ) ;
F_31 ( F_20 ( V_24 -> V_120 ) , V_24 -> V_120 ) ;
return 0 ;
V_125:
F_40 ( F_20 ( V_24 -> V_120 ) , V_24 -> V_120 ) ;
V_124:
return V_110 ;
}
static int F_41 ( struct V_11 * V_12 )
{
struct V_23 * V_24 = F_7 ( V_12 ) ;
F_16 ( V_24 ) ;
F_27 ( V_12 , V_119 ) ;
F_31 ( F_20 ( V_24 -> V_120 ) , V_24 -> V_120 ) ;
F_40 ( F_20 ( V_24 -> V_120 ) , V_24 -> V_120 ) ;
return 0 ;
}
static int F_42 ( struct V_11 * V_12 ,
unsigned int V_147 )
{
switch ( V_147 ) {
case V_39 ... V_148 :
case V_149 ... V_150 :
return 0 ;
}
return 1 ;
}
static T_2 int F_43 ( struct V_151 * V_152 ,
const struct V_153 * V_154 )
{
struct V_23 * V_24 ;
int V_110 ;
V_24 = F_44 ( & V_152 -> V_61 , sizeof( struct V_23 ) ,
V_155 ) ;
if ( ! V_24 )
return - V_156 ;
F_45 ( V_152 , V_24 ) ;
V_110 = F_46 ( & V_152 -> V_61 , & V_157 , & V_158 , 1 ) ;
if ( V_110 != 0 )
F_22 ( & V_152 -> V_61 , L_14 , V_110 ) ;
return V_110 ;
}
static T_3 int F_47 ( struct V_151 * V_159 )
{
F_48 ( & V_159 -> V_61 ) ;
return 0 ;
}
static int T_4 F_49 ( void )
{
return F_50 ( & V_160 ) ;
}
static void T_5 F_51 ( void )
{
F_52 ( & V_160 ) ;
}
