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
struct V_23 * V_24 = V_12 -> V_29 ;
unsigned int V_30 ;
int V_31 ;
V_30 = F_4 ( V_12 , V_32 ) ;
F_5 ( V_12 , V_32 , V_30 | V_33 ) ;
F_8 ( V_12 ) ;
V_31 = F_10 ( V_24 -> V_34 ) ;
F_5 ( V_12 , V_32 , V_30 ) ;
return V_31 ;
}
static void F_11 ( struct V_35 * V_36 )
{
struct V_23 * V_24 = F_12 ( V_36 , struct V_23 ,
V_37 . V_36 ) ;
struct V_11 * V_12 = V_24 -> V_12 ;
unsigned int V_38 , V_39 ;
V_39 = F_4 ( V_12 , V_40 ) ;
F_13 ( V_24 -> V_34 , true ) ;
V_38 = F_4 ( V_12 , V_40 ) ;
F_13 ( V_24 -> V_34 , false ) ;
if ( V_38 != V_39 ) {
F_14 ( V_24 -> V_34 ) ;
F_9 ( V_12 ) ;
}
if ( ! V_24 -> V_41 )
F_15 ( V_42 ,
& V_24 -> V_37 ,
F_16 ( V_43 ) ) ;
}
static void F_17 ( struct V_23 * V_24 )
{
if ( V_24 -> V_44 -> V_45 ) {
V_24 -> V_41 = 0 ;
F_15 ( V_42 ,
& V_24 -> V_37 ,
F_16 ( V_43 ) ) ;
}
}
static void F_18 ( struct V_23 * V_24 )
{
if ( V_24 -> V_44 -> V_45 ) {
V_24 -> V_41 = 1 ;
F_19 ( & V_24 -> V_37 ) ;
}
}
static int F_20 ( struct V_46 * V_47 ,
int V_48 , unsigned int V_49 , int V_50 )
{
struct V_11 * V_12 = V_47 -> V_12 ;
struct V_23 * V_24 = F_7 ( V_12 ) ;
int V_15 , V_51 , V_52 , V_53 ;
unsigned int V_54 = 0 ;
unsigned int V_55 = - 1 ;
unsigned int V_56 = 0 ;
F_21 ( L_1 , V_49 ) ;
V_24 -> V_57 = V_49 ;
if ( V_24 -> V_57 ) {
for ( V_15 = 0 ; V_15 < F_22 ( V_58 ) ; V_15 ++ ) {
V_52 = V_58 [ V_15 ] . V_52 ;
V_53 = V_58 [ V_15 ] . V_53 ;
for ( V_51 = 0 ; V_59 [ V_52 ] [ V_51 ] . V_60 ; V_51 ++ ) {
if ( V_59 [ V_52 ] [ V_51 ] . V_60 * V_53 == V_49 ) {
V_54 |= F_23 ( V_53 ) ;
if ( V_53 < V_55 )
V_55 = V_53 ;
if ( V_53 > V_56 )
V_56 = V_53 ;
break;
}
}
}
V_54 &= ~ V_61 ;
if ( ! V_54 ) {
F_24 ( V_12 -> V_62 , L_2 ) ;
return - V_18 ;
}
} else {
V_54 = V_63 ;
V_55 = 32000 ;
V_56 = 192000 ;
}
V_47 -> V_64 -> V_65 . V_54 = V_54 ;
V_47 -> V_64 -> V_65 . V_55 = V_55 ;
V_47 -> V_64 -> V_65 . V_56 = V_56 ;
return 0 ;
}
static int F_25 ( struct V_46 * V_47 ,
unsigned int V_66 )
{
struct V_11 * V_12 = V_47 -> V_12 ;
struct V_23 * V_24 = F_7 ( V_12 ) ;
T_1 V_67 = F_4 ( V_12 , V_68 ) ;
F_21 ( L_3 ) ;
V_67 &= ~ ( V_69 | V_70 ) ;
switch ( V_66 & V_71 ) {
case V_72 :
break;
default:
return - V_18 ;
}
switch ( V_66 & V_73 ) {
case V_74 :
case V_75 :
case V_76 :
V_24 -> V_77 = V_66 & V_73 ;
break;
default:
return - V_18 ;
}
switch ( V_66 & V_78 ) {
case V_79 :
V_67 |= V_70 ;
break;
case V_80 :
V_67 |= V_69 ;
break;
default:
return - V_18 ;
}
F_5 ( V_12 , V_68 , V_67 ) ;
return 0 ;
}
static int F_26 ( struct V_81 * V_82 ,
struct V_83 * V_84 ,
struct V_46 * V_85 )
{
struct V_11 * V_12 = V_85 -> V_12 ;
struct V_23 * V_24 = F_7 ( V_12 ) ;
unsigned int V_86 ;
int V_15 , V_87 = - 1 , V_52 = - 1 ;
T_1 V_38 , V_67 ;
V_86 = F_27 ( V_84 ) ;
F_21 ( L_4 , V_86 ) ;
for ( V_15 = 0 ; V_15 < F_22 ( V_58 ) ; V_15 ++ )
if ( V_58 [ V_15 ] . V_53 == V_86 ) {
V_52 = V_58 [ V_15 ] . V_52 ;
break;
}
if ( V_52 < 0 )
return - V_18 ;
for ( V_15 = 0 ; V_59 [ V_52 ] [ V_15 ] . V_60 ; V_15 ++ )
if ( V_59 [ V_52 ] [ V_15 ] . V_60 * V_86 == V_24 -> V_57 ) {
V_87 = V_59 [ V_52 ] [ V_15 ] . V_87 ;
break;
}
if ( V_87 < 0 )
return - V_18 ;
V_38 = F_4 ( V_12 , V_40 ) ;
V_38 &= ~ ( V_88 | V_89 ) ;
V_38 |= ( V_52 << V_90 ) | ( V_87 << V_91 ) ;
V_67 = F_4 ( V_12 , V_68 ) ;
V_67 &= ~ ( V_92 | V_93 ) ;
switch ( F_28 ( V_84 ) ) {
case V_94 :
case V_95 :
case V_96 :
case V_97 :
F_21 ( L_5 ) ;
case V_98 :
case V_99 :
F_21 ( L_6 ) ;
switch ( V_24 -> V_77 ) {
case V_74 :
V_67 |= 0x0 ;
break;
case V_76 :
V_67 |= 0x1 ;
break;
case V_75 :
V_67 |= 0x2 ;
break;
}
break;
case V_100 :
case V_101 :
F_21 ( L_7 ) ;
switch ( V_24 -> V_77 ) {
case V_74 :
V_67 |= 0x4 ;
break;
case V_76 :
V_67 |= 0x5 ;
break;
case V_75 :
V_67 |= 0x6 ;
break;
}
break;
case V_102 :
case V_103 :
F_21 ( L_8 ) ;
switch ( V_24 -> V_77 ) {
case V_74 :
V_67 |= 0x8 ;
break;
case V_76 :
V_67 |= 0x9 ;
break;
case V_75 :
V_67 |= 0xa ;
break;
}
break;
case V_104 :
case V_105 :
F_21 ( L_9 ) ;
switch ( V_24 -> V_77 ) {
case V_74 :
V_67 |= 0x0 ;
break;
case V_76 :
V_67 |= 0xd ;
break;
case V_75 :
V_67 |= 0xe ;
break;
}
break;
default:
return - V_18 ;
}
F_5 ( V_12 , V_40 , V_38 ) ;
F_5 ( V_12 , V_68 , V_67 ) ;
return 0 ;
}
static int F_29 ( struct V_11 * V_12 ,
enum V_106 V_107 )
{
int V_108 ;
struct V_23 * V_24 = F_7 ( V_12 ) ;
F_21 ( L_10 , V_107 ) ;
switch ( V_107 ) {
case V_109 :
break;
case V_110 :
F_30 ( V_12 , V_111 ,
V_112 | V_113 ,
V_112 | V_113 ) ;
break;
case V_114 :
if ( V_12 -> V_115 . V_116 == V_117 ) {
V_108 = F_31 ( F_22 ( V_24 -> V_118 ) ,
V_24 -> V_118 ) ;
if ( V_108 != 0 ) {
F_24 ( V_12 -> V_62 ,
L_11 , V_108 ) ;
return V_108 ;
}
F_9 ( V_12 ) ;
F_17 ( V_24 ) ;
}
F_30 ( V_12 , V_111 ,
V_112 | V_113 ,
V_112 | V_113 ) ;
break;
case V_117 :
F_30 ( V_12 , V_111 ,
V_112 | V_113 ,
V_112 ) ;
F_32 ( 300 ) ;
F_18 ( V_24 ) ;
F_33 ( F_22 ( V_24 -> V_118 ) ,
V_24 -> V_118 ) ;
break;
}
V_12 -> V_115 . V_116 = V_107 ;
return 0 ;
}
static int F_34 ( struct V_11 * V_12 )
{
F_29 ( V_12 , V_117 ) ;
return 0 ;
}
static int F_35 ( struct V_11 * V_12 )
{
F_29 ( V_12 , V_114 ) ;
return 0 ;
}
static int F_36 ( struct V_11 * V_12 )
{
struct V_23 * V_24 = F_7 ( V_12 ) ;
int V_15 , V_108 = 0 , V_119 = 0 ;
V_24 -> V_12 = V_12 ;
V_24 -> V_44 = F_37 ( V_12 -> V_62 ) ;
V_108 = F_31 ( F_22 ( V_24 -> V_118 ) ,
V_24 -> V_118 ) ;
if ( V_108 != 0 ) {
F_24 ( V_12 -> V_62 , L_11 , V_108 ) ;
return V_108 ;
}
V_12 -> V_29 = V_24 -> V_34 ;
V_108 = F_38 ( V_12 , 8 , 8 , V_120 ) ;
if ( V_108 < 0 ) {
F_24 ( V_12 -> V_62 , L_12 , V_108 ) ;
goto V_121;
}
F_39 ( V_24 -> V_34 , true ) ;
F_5 ( V_12 , V_122 , 0xc2 ) ;
F_5 ( V_12 , V_123 , 0xc2 ) ;
F_5 ( V_12 , V_111 , 0x5c ) ;
F_5 ( V_12 , V_32 , 0x10 ) ;
F_5 ( V_12 , V_124 , 0x60 ) ;
F_5 ( V_12 , V_125 , 0x00 ) ;
F_5 ( V_12 , V_126 , 0x40 ) ;
F_39 ( V_24 -> V_34 , false ) ;
if ( ! ( V_24 -> V_44 -> V_127 & V_128 ) )
V_119 |= V_129 ;
if ( ! ( V_24 -> V_44 -> V_127 & V_130 ) )
V_119 |= V_131 ;
F_30 ( V_12 , V_40 ,
V_129 | V_131 ,
V_119 ) ;
F_30 ( V_12 , V_111 ,
V_132 ,
V_24 -> V_44 -> V_133
<< V_134 ) ;
F_30 ( V_12 , V_135 ,
V_136 ,
V_24 -> V_44 -> V_137
<< V_138 ) ;
F_30 ( V_12 , V_139 ,
V_136 ,
V_24 -> V_44 -> V_140
<< V_138 ) ;
F_30 ( V_12 , V_126 ,
V_136 ,
V_24 -> V_44 -> V_141
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
if ( V_24 -> V_44 -> V_45 )
F_40 ( & V_24 -> V_37 , F_11 ) ;
F_29 ( V_12 , V_114 ) ;
F_33 ( F_22 ( V_24 -> V_118 ) , V_24 -> V_118 ) ;
return 0 ;
V_121:
F_33 ( F_22 ( V_24 -> V_118 ) , V_24 -> V_118 ) ;
return V_108 ;
}
static int F_41 ( struct V_11 * V_12 )
{
struct V_23 * V_24 = F_7 ( V_12 ) ;
F_18 ( V_24 ) ;
F_29 ( V_12 , V_117 ) ;
F_33 ( F_22 ( V_24 -> V_118 ) , V_24 -> V_118 ) ;
return 0 ;
}
static bool F_42 ( struct V_142 * V_62 , unsigned int V_143 )
{
switch ( V_143 ) {
case V_40 ... V_144 :
case V_145 ... V_146 :
return 0 ;
}
return 1 ;
}
static int F_43 ( struct V_147 * V_148 ,
const struct V_149 * V_150 )
{
struct V_23 * V_24 ;
int V_108 , V_15 ;
V_24 = F_44 ( & V_148 -> V_62 , sizeof( struct V_23 ) ,
V_151 ) ;
if ( ! V_24 )
return - V_152 ;
for ( V_15 = 0 ; V_15 < F_22 ( V_24 -> V_118 ) ; V_15 ++ )
V_24 -> V_118 [ V_15 ] . V_153 = V_154 [ V_15 ] ;
V_108 = F_45 ( & V_148 -> V_62 , F_22 ( V_24 -> V_118 ) ,
V_24 -> V_118 ) ;
if ( V_108 != 0 ) {
F_24 ( & V_148 -> V_62 , L_13 , V_108 ) ;
return V_108 ;
}
V_24 -> V_34 = F_46 ( V_148 , & V_155 ) ;
if ( F_47 ( V_24 -> V_34 ) ) {
V_108 = F_48 ( V_24 -> V_34 ) ;
F_24 ( & V_148 -> V_62 , L_14 , V_108 ) ;
return V_108 ;
}
F_49 ( V_148 , V_24 ) ;
V_108 = F_50 ( & V_148 -> V_62 , & V_156 , & V_157 , 1 ) ;
if ( V_108 != 0 )
F_24 ( & V_148 -> V_62 , L_15 , V_108 ) ;
return V_108 ;
}
static int F_51 ( struct V_147 * V_158 )
{
F_52 ( & V_158 -> V_62 ) ;
return 0 ;
}
