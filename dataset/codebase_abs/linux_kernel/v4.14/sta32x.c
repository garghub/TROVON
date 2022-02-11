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
struct V_13 * V_14 = F_4 ( V_12 ) ;
int V_5 = V_2 -> V_6 >> 16 ;
int V_15 = V_2 -> V_6 & 0xffff ;
unsigned int V_16 , V_17 ;
int V_18 , V_19 = 0 ;
F_5 ( & V_14 -> V_20 ) ;
F_6 ( V_14 -> V_21 , V_22 , & V_16 ) ;
V_16 &= 0xf0 ;
F_7 ( V_14 -> V_21 , V_22 , V_16 ) ;
F_7 ( V_14 -> V_21 , V_23 , V_15 ) ;
if ( V_5 == 1 ) {
F_7 ( V_14 -> V_21 , V_22 , V_16 | 0x04 ) ;
} else if ( V_5 == 5 ) {
F_7 ( V_14 -> V_21 , V_22 , V_16 | 0x08 ) ;
} else {
V_19 = - V_24 ;
goto V_25;
}
for ( V_18 = 0 ; V_18 < 3 * V_5 ; V_18 ++ ) {
F_6 ( V_14 -> V_21 , V_26 + V_18 , & V_17 ) ;
V_10 -> V_27 . V_28 . V_29 [ V_18 ] = V_17 ;
}
V_25:
F_8 ( & V_14 -> V_20 ) ;
return V_19 ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_9 * V_10 )
{
struct V_11 * V_12 = F_3 ( V_2 ) ;
struct V_13 * V_14 = F_4 ( V_12 ) ;
int V_5 = V_2 -> V_6 >> 16 ;
int V_15 = V_2 -> V_6 & 0xffff ;
unsigned int V_16 ;
int V_18 ;
F_6 ( V_14 -> V_21 , V_22 , & V_16 ) ;
V_16 &= 0xf0 ;
F_7 ( V_14 -> V_21 , V_22 , V_16 ) ;
F_7 ( V_14 -> V_21 , V_23 , V_15 ) ;
for ( V_18 = 0 ; V_18 < V_5 && ( V_15 + V_18 < V_30 ) ; V_18 ++ )
V_14 -> V_31 [ V_15 + V_18 ] =
( V_10 -> V_27 . V_28 . V_29 [ 3 * V_18 ] << 16 )
| ( V_10 -> V_27 . V_28 . V_29 [ 3 * V_18 + 1 ] << 8 )
| ( V_10 -> V_27 . V_28 . V_29 [ 3 * V_18 + 2 ] ) ;
for ( V_18 = 0 ; V_18 < 3 * V_5 ; V_18 ++ )
F_7 ( V_14 -> V_21 , V_26 + V_18 ,
V_10 -> V_27 . V_28 . V_29 [ V_18 ] ) ;
if ( V_5 == 1 )
F_7 ( V_14 -> V_21 , V_22 , V_16 | 0x01 ) ;
else if ( V_5 == 5 )
F_7 ( V_14 -> V_21 , V_22 , V_16 | 0x02 ) ;
else
return - V_24 ;
return 0 ;
}
static int F_10 ( struct V_11 * V_12 )
{
struct V_13 * V_14 = F_4 ( V_12 ) ;
unsigned int V_16 ;
int V_18 ;
F_6 ( V_14 -> V_21 , V_22 , & V_16 ) ;
V_16 &= 0xf0 ;
for ( V_18 = 0 ; V_18 < V_30 ; V_18 ++ ) {
F_7 ( V_14 -> V_21 , V_23 , V_18 ) ;
F_7 ( V_14 -> V_21 , V_26 ,
( V_14 -> V_31 [ V_18 ] >> 16 ) & 0xff ) ;
F_7 ( V_14 -> V_21 , V_32 ,
( V_14 -> V_31 [ V_18 ] >> 8 ) & 0xff ) ;
F_7 ( V_14 -> V_21 , V_33 ,
( V_14 -> V_31 [ V_18 ] ) & 0xff ) ;
F_7 ( V_14 -> V_21 , V_22 , V_16 ) ;
F_7 ( V_14 -> V_21 , V_22 , V_16 | 0x01 ) ;
}
return 0 ;
}
static int F_11 ( struct V_11 * V_12 )
{
struct V_13 * V_14 = F_4 ( V_12 ) ;
unsigned int V_34 ;
int V_35 ;
F_6 ( V_14 -> V_21 , V_36 , & V_34 ) ;
F_7 ( V_14 -> V_21 , V_36 , V_34 | V_37 ) ;
F_10 ( V_12 ) ;
V_35 = F_12 ( V_14 -> V_21 ) ;
F_7 ( V_14 -> V_21 , V_36 , V_34 ) ;
return V_35 ;
}
static void F_13 ( struct V_38 * V_39 )
{
struct V_13 * V_14 = F_14 ( V_39 , struct V_13 ,
V_40 . V_39 ) ;
struct V_11 * V_12 = V_14 -> V_12 ;
unsigned int V_41 , V_42 ;
V_42 = F_15 ( V_12 , V_43 ) ;
F_16 ( V_14 -> V_21 , true ) ;
V_41 = F_15 ( V_12 , V_43 ) ;
F_16 ( V_14 -> V_21 , false ) ;
if ( V_41 != V_42 ) {
F_17 ( V_14 -> V_21 ) ;
F_11 ( V_12 ) ;
}
if ( ! V_14 -> V_44 )
F_18 ( V_45 ,
& V_14 -> V_40 ,
F_19 ( V_46 ) ) ;
}
static void F_20 ( struct V_13 * V_14 )
{
if ( V_14 -> V_47 -> V_48 ) {
V_14 -> V_44 = 0 ;
F_18 ( V_45 ,
& V_14 -> V_40 ,
F_19 ( V_46 ) ) ;
}
}
static void F_21 ( struct V_13 * V_14 )
{
if ( V_14 -> V_47 -> V_48 ) {
V_14 -> V_44 = 1 ;
F_22 ( & V_14 -> V_40 ) ;
}
}
static int F_23 ( struct V_49 * V_50 ,
int V_51 , unsigned int V_52 , int V_53 )
{
struct V_11 * V_12 = V_50 -> V_12 ;
struct V_13 * V_14 = F_4 ( V_12 ) ;
F_24 ( V_12 -> V_54 , L_1 , V_52 ) ;
V_14 -> V_55 = V_52 ;
return 0 ;
}
static int F_25 ( struct V_49 * V_50 ,
unsigned int V_56 )
{
struct V_11 * V_12 = V_50 -> V_12 ;
struct V_13 * V_14 = F_4 ( V_12 ) ;
T_1 V_57 = 0 ;
switch ( V_56 & V_58 ) {
case V_59 :
break;
default:
return - V_24 ;
}
switch ( V_56 & V_60 ) {
case V_61 :
case V_62 :
case V_63 :
V_14 -> V_64 = V_56 & V_60 ;
break;
default:
return - V_24 ;
}
switch ( V_56 & V_65 ) {
case V_66 :
V_57 |= V_67 ;
break;
case V_68 :
V_57 |= V_69 ;
break;
default:
return - V_24 ;
}
return F_26 ( V_14 -> V_21 , V_70 ,
V_69 | V_67 , V_57 ) ;
}
static int F_27 ( struct V_71 * V_72 ,
struct V_73 * V_74 ,
struct V_49 * V_75 )
{
struct V_11 * V_12 = V_75 -> V_12 ;
struct V_13 * V_14 = F_4 ( V_12 ) ;
int V_18 , V_76 = - V_24 , V_77 = - V_24 ;
unsigned int V_41 , V_57 ;
unsigned int V_78 , V_79 ;
int V_19 ;
if ( ! V_14 -> V_55 ) {
F_28 ( V_12 -> V_54 ,
L_2 ) ;
return - V_80 ;
}
V_78 = F_29 ( V_74 ) ;
V_79 = V_14 -> V_55 / V_78 ;
F_24 ( V_12 -> V_54 , L_3 , V_78 , V_79 ) ;
for ( V_18 = 0 ; V_18 < F_30 ( V_81 ) ; V_18 ++ ) {
if ( V_81 [ V_18 ] . V_82 == V_78 ) {
V_77 = V_81 [ V_18 ] . V_77 ;
break;
}
}
if ( V_77 < 0 ) {
F_28 ( V_12 -> V_54 , L_4 , V_78 ) ;
return - V_24 ;
}
for ( V_18 = 0 ; V_18 < 6 ; V_18 ++ ) {
if ( V_83 [ V_77 ] [ V_18 ] == V_79 ) {
V_76 = V_18 ;
break;
}
}
if ( V_76 < 0 ) {
F_28 ( V_12 -> V_54 , L_5 , V_79 ) ;
return - V_24 ;
}
V_41 = ( V_77 << V_84 ) |
( V_76 << V_85 ) ;
V_57 = 0 ;
switch ( F_31 ( V_74 ) ) {
case 24 :
F_24 ( V_12 -> V_54 , L_6 ) ;
case 32 :
F_24 ( V_12 -> V_54 , L_7 ) ;
switch ( V_14 -> V_64 ) {
case V_61 :
V_57 |= 0x0 ;
break;
case V_63 :
V_57 |= 0x1 ;
break;
case V_62 :
V_57 |= 0x2 ;
break;
}
break;
case 20 :
F_24 ( V_12 -> V_54 , L_8 ) ;
switch ( V_14 -> V_64 ) {
case V_61 :
V_57 |= 0x4 ;
break;
case V_63 :
V_57 |= 0x5 ;
break;
case V_62 :
V_57 |= 0x6 ;
break;
}
break;
case 18 :
F_24 ( V_12 -> V_54 , L_9 ) ;
switch ( V_14 -> V_64 ) {
case V_61 :
V_57 |= 0x8 ;
break;
case V_63 :
V_57 |= 0x9 ;
break;
case V_62 :
V_57 |= 0xa ;
break;
}
break;
case 16 :
F_24 ( V_12 -> V_54 , L_10 ) ;
switch ( V_14 -> V_64 ) {
case V_61 :
V_57 |= 0x0 ;
break;
case V_63 :
V_57 |= 0xd ;
break;
case V_62 :
V_57 |= 0xe ;
break;
}
break;
default:
return - V_24 ;
}
V_19 = F_26 ( V_14 -> V_21 , V_43 ,
V_86 | V_87 ,
V_41 ) ;
if ( V_19 < 0 )
return V_19 ;
V_19 = F_26 ( V_14 -> V_21 , V_70 ,
V_88 | V_89 ,
V_57 ) ;
if ( V_19 < 0 )
return V_19 ;
return 0 ;
}
static int F_32 ( struct V_13 * V_14 )
{
if ( V_14 -> V_90 ) {
F_33 ( V_14 -> V_90 , 0 ) ;
F_34 ( 1 ) ;
F_33 ( V_14 -> V_90 , 1 ) ;
F_34 ( 1 ) ;
}
return 0 ;
}
static int F_35 ( struct V_11 * V_12 ,
enum V_91 V_92 )
{
int V_19 ;
struct V_13 * V_14 = F_4 ( V_12 ) ;
F_24 ( V_12 -> V_54 , L_11 , V_92 ) ;
switch ( V_92 ) {
case V_93 :
break;
case V_94 :
F_26 ( V_14 -> V_21 , V_95 ,
V_96 | V_97 ,
V_96 | V_97 ) ;
break;
case V_98 :
if ( F_36 ( V_12 ) == V_99 ) {
V_19 = F_37 ( F_30 ( V_14 -> V_100 ) ,
V_14 -> V_100 ) ;
if ( V_19 != 0 ) {
F_28 ( V_12 -> V_54 ,
L_12 , V_19 ) ;
return V_19 ;
}
F_32 ( V_14 ) ;
F_11 ( V_12 ) ;
F_20 ( V_14 ) ;
}
F_26 ( V_14 -> V_21 , V_95 ,
V_96 | V_97 ,
0 ) ;
break;
case V_99 :
F_26 ( V_14 -> V_21 , V_95 ,
V_96 | V_97 , 0 ) ;
F_38 ( 300 ) ;
F_21 ( V_14 ) ;
F_33 ( V_14 -> V_90 , 0 ) ;
F_39 ( F_30 ( V_14 -> V_100 ) ,
V_14 -> V_100 ) ;
break;
}
return 0 ;
}
static int F_40 ( struct V_11 * V_12 )
{
struct V_13 * V_14 = F_4 ( V_12 ) ;
struct V_101 * V_47 = V_14 -> V_47 ;
int V_18 , V_19 = 0 , V_102 = 0 ;
V_19 = F_37 ( F_30 ( V_14 -> V_100 ) ,
V_14 -> V_100 ) ;
if ( V_19 != 0 ) {
F_28 ( V_12 -> V_54 , L_12 , V_19 ) ;
return V_19 ;
}
V_19 = F_32 ( V_14 ) ;
if ( V_19 < 0 ) {
F_28 ( V_12 -> V_54 , L_13 ) ;
return V_19 ;
}
if ( ! V_47 -> V_103 )
V_102 |= V_104 ;
if ( ! V_47 -> V_105 )
V_102 |= V_106 ;
if ( ! V_47 -> V_107 )
V_102 |= V_108 ;
F_26 ( V_14 -> V_21 , V_43 ,
V_104 | V_106 |
V_108 ,
V_102 ) ;
F_26 ( V_14 -> V_21 , V_109 ,
V_110 ,
V_47 -> V_111
<< V_112 ) ;
F_26 ( V_14 -> V_21 , V_113 ,
V_114 ,
V_47 -> V_115 ?
V_114 : 0 ) ;
F_26 ( V_14 -> V_21 , V_113 ,
V_116 ,
V_47 -> V_117 ?
V_116 : 0 ) ;
F_26 ( V_14 -> V_21 , V_113 ,
V_118 ,
V_47 -> V_119 ?
V_118 : 0 ) ;
F_26 ( V_14 -> V_21 , V_113 ,
V_120 ,
V_47 -> V_121 ?
V_120 : 0 ) ;
F_26 ( V_14 -> V_21 , V_95 ,
V_122 ,
V_47 -> V_123 ?
V_122 : 0 ) ;
F_26 ( V_14 -> V_21 , V_95 ,
V_124 ,
V_47 -> V_125
<< V_126 ) ;
F_26 ( V_14 -> V_21 , V_127 ,
V_128 ,
V_47 -> V_129
<< V_130 ) ;
F_26 ( V_14 -> V_21 , V_131 ,
V_128 ,
V_47 -> V_132
<< V_130 ) ;
F_26 ( V_14 -> V_21 , V_133 ,
V_128 ,
V_47 -> V_134
<< V_130 ) ;
for ( V_18 = 4 ; V_18 <= 49 ; V_18 += 5 )
V_14 -> V_31 [ V_18 ] = 0x400000 ;
for ( V_18 = 50 ; V_18 <= 54 ; V_18 ++ )
V_14 -> V_31 [ V_18 ] = 0x7fffff ;
V_14 -> V_31 [ 55 ] = 0x5a9df7 ;
V_14 -> V_31 [ 56 ] = 0x7fffff ;
V_14 -> V_31 [ 59 ] = 0x7fffff ;
V_14 -> V_31 [ 60 ] = 0x400000 ;
V_14 -> V_31 [ 61 ] = 0x400000 ;
if ( V_14 -> V_47 -> V_48 )
F_41 ( & V_14 -> V_40 , F_13 ) ;
F_42 ( V_12 , V_98 ) ;
F_39 ( F_30 ( V_14 -> V_100 ) , V_14 -> V_100 ) ;
return 0 ;
}
static int F_43 ( struct V_11 * V_12 )
{
struct V_13 * V_14 = F_4 ( V_12 ) ;
F_21 ( V_14 ) ;
F_39 ( F_30 ( V_14 -> V_100 ) , V_14 -> V_100 ) ;
return 0 ;
}
static int F_44 ( struct V_135 * V_54 , struct V_13 * V_14 )
{
struct V_136 * V_137 = V_54 -> V_138 ;
struct V_101 * V_47 ;
T_2 V_139 ;
V_47 = F_45 ( V_54 , sizeof( * V_47 ) , V_140 ) ;
if ( ! V_47 )
return - V_141 ;
F_46 ( V_137 , L_14 ,
& V_47 -> V_125 ) ;
F_46 ( V_137 , L_15 ,
& V_47 -> V_129 ) ;
F_46 ( V_137 , L_16 ,
& V_47 -> V_132 ) ;
F_46 ( V_137 , L_17 ,
& V_47 -> V_134 ) ;
if ( F_47 ( V_137 , L_18 , NULL ) )
V_47 -> V_103 = 1 ;
if ( F_47 ( V_137 , L_19 , NULL ) )
V_47 -> V_105 = 1 ;
if ( F_47 ( V_137 , L_20 , NULL ) )
V_47 -> V_48 = 1 ;
V_139 = 140 ;
F_48 ( V_137 , L_21 , & V_139 ) ;
V_47 -> V_111 = F_49 ( T_2 , V_139 , 0 , 300 ) / 20 ;
if ( F_47 ( V_137 , L_22 , NULL ) )
V_47 -> V_115 = 1 ;
if ( F_47 ( V_137 , L_23 , NULL ) )
V_47 -> V_117 = 1 ;
if ( F_47 ( V_137 , L_24 , NULL ) )
V_47 -> V_119 = 1 ;
if ( F_47 ( V_137 , L_25 , NULL ) )
V_47 -> V_121 = 1 ;
if ( F_47 ( V_137 , L_26 , NULL ) )
V_47 -> V_123 = 1 ;
V_14 -> V_47 = V_47 ;
return 0 ;
}
static int F_50 ( struct V_142 * V_143 ,
const struct V_144 * V_145 )
{
struct V_135 * V_54 = & V_143 -> V_54 ;
struct V_13 * V_14 ;
int V_19 , V_18 ;
V_14 = F_45 ( & V_143 -> V_54 , sizeof( struct V_13 ) ,
V_140 ) ;
if ( ! V_14 )
return - V_141 ;
F_51 ( & V_14 -> V_20 ) ;
V_14 -> V_47 = F_52 ( V_54 ) ;
#ifdef F_53
if ( V_54 -> V_138 ) {
V_19 = F_44 ( V_54 , V_14 ) ;
if ( V_19 < 0 )
return V_19 ;
}
#endif
V_14 -> V_90 = F_54 ( V_54 , L_27 ,
V_146 ) ;
if ( F_55 ( V_14 -> V_90 ) )
return F_56 ( V_14 -> V_90 ) ;
for ( V_18 = 0 ; V_18 < F_30 ( V_14 -> V_100 ) ; V_18 ++ )
V_14 -> V_100 [ V_18 ] . V_147 = V_148 [ V_18 ] ;
V_19 = F_57 ( & V_143 -> V_54 , F_30 ( V_14 -> V_100 ) ,
V_14 -> V_100 ) ;
if ( V_19 != 0 ) {
F_28 ( & V_143 -> V_54 , L_28 , V_19 ) ;
return V_19 ;
}
V_14 -> V_21 = F_58 ( V_143 , & V_149 ) ;
if ( F_55 ( V_14 -> V_21 ) ) {
V_19 = F_56 ( V_14 -> V_21 ) ;
F_28 ( V_54 , L_29 , V_19 ) ;
return V_19 ;
}
F_59 ( V_143 , V_14 ) ;
V_19 = F_60 ( V_54 , & V_150 , & V_151 , 1 ) ;
if ( V_19 < 0 )
F_28 ( V_54 , L_30 , V_19 ) ;
return V_19 ;
}
static int F_61 ( struct V_142 * V_152 )
{
F_62 ( & V_152 -> V_54 ) ;
return 0 ;
}
