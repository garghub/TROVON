static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
struct V_5 * V_6 = & V_2 -> V_6 ;
int V_7 ;
T_1 V_8 [] = { V_3 , V_4 } ;
struct V_9 V_10 = {
. V_11 = V_6 -> V_12 ,
. V_13 = 0 , . V_8 = V_8 , . V_14 = 2 } ;
F_2 ( 2 , L_1 , V_15 , V_3 , V_4 ) ;
V_7 = F_3 ( V_2 -> V_16 , & V_10 , 1 ) ;
if ( V_7 != 1 )
F_4 ( L_2 , V_15 , V_7 ) ;
return ( V_7 != 1 ) ? - 1 : 0 ;
}
static T_1 F_5 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_5 * V_6 = & V_2 -> V_6 ;
int V_7 ;
T_1 V_17 [] = { V_3 } ;
T_1 V_18 [] = { 0 } ;
struct V_9 V_10 [] = {
{ . V_11 = V_6 -> V_12 ,
. V_13 = 0 , . V_8 = V_17 , . V_14 = 1 } ,
{ . V_11 = V_6 -> V_12 ,
. V_13 = V_19 , . V_8 = V_18 , . V_14 = 1 } } ;
F_2 ( 2 , L_3 , V_15 , V_3 ) ;
V_7 = F_3 ( V_2 -> V_16 , V_10 , 2 ) ;
if ( V_7 != 2 )
F_4 ( V_20 L_4 ,
V_15 , V_7 ) ;
return V_18 [ 0 ] ;
}
static int F_6 ( struct V_1 * V_2 , T_1 V_3 ,
const T_1 * V_4 , T_2 V_14 )
{
struct V_5 * V_6 = & V_2 -> V_6 ;
int V_7 = - V_21 ;
struct V_9 V_10 ;
T_1 * V_8 ;
F_2 ( 2 , L_5 , V_15 , V_3 , V_14 ) ;
V_8 = F_7 ( V_14 + 1 , V_22 ) ;
if ( V_8 == NULL ) {
V_7 = - V_23 ;
goto error;
}
* V_8 = V_3 ;
memcpy ( V_8 + 1 , V_4 , V_14 ) ;
V_10 . V_11 = V_6 -> V_12 ;
V_10 . V_13 = 0 ;
V_10 . V_8 = V_8 ;
V_10 . V_14 = V_14 + 1 ;
F_2 ( 2 , L_6 ,
V_15 , V_10 . V_14 ) ;
V_7 = F_3 ( V_2 -> V_16 , & V_10 , 1 ) ;
if ( V_7 != 1 ) {
F_4 ( V_20 L_7 ,
V_15 , V_7 ) ;
V_7 = - V_21 ;
}
error:
F_8 ( V_8 ) ;
return V_7 ;
}
static int F_9 ( struct V_24 * V_25 , T_3 V_26 ,
T_3 V_27 )
{
struct V_1 * V_2 = V_25 -> V_28 ;
T_4 V_29 ;
F_2 ( 1 , L_8 , V_15 ) ;
if ( V_26 == 0 )
return - V_30 ;
if ( V_27 < ( V_26 / 2 ) ) {
V_29 = V_27 ;
V_29 *= 10 ;
V_29 *= 32768 ;
F_10 ( V_29 , V_26 ) ;
V_29 += 5 ;
F_10 ( V_29 , 10 ) ;
} else {
V_29 = V_26 - V_27 ;
V_29 *= 10 ;
V_29 *= 32768 ;
F_10 ( V_29 , V_26 ) ;
V_29 += 5 ;
F_10 ( V_29 , 10 ) ;
V_29 = ~ V_29 + 1 ;
}
F_1 ( V_2 , V_31 , ( T_1 ) V_29 ) ;
F_1 ( V_2 , V_32 , ( T_1 ) ( V_29 >> 8 ) ) ;
return 0 ;
}
static int F_11 ( struct V_24 * V_25 , T_3 V_26 ,
T_3 V_33 )
{
struct V_1 * V_2 = V_25 -> V_28 ;
T_4 V_29 , V_34 ;
T_3 V_35 = 8000000 ;
F_2 ( 1 , L_8 , V_15 ) ;
if ( V_26 == 0 )
return - V_30 ;
if ( V_33 == V_36 )
V_35 = 6000000 ;
else
if ( V_33 == V_37 )
V_35 = 7000000 ;
V_29 = V_35 * 10 ;
V_29 *= ( 2048 * 1024 ) ;
V_29 *= 1024 ;
V_34 = 7 * V_26 ;
F_10 ( V_29 , V_34 ) ;
V_29 += 5 ;
F_10 ( V_29 , 10 ) ;
F_1 ( V_2 , V_38 , ( T_1 ) V_29 ) ;
F_1 ( V_2 , V_39 , ( T_1 ) ( V_29 >> 8 ) ) ;
F_1 ( V_2 , V_40 , ( T_1 ) ( V_29 >> 16 ) ) ;
F_1 ( V_2 , V_41 , ( T_1 ) ( V_29 >> 24 ) ) ;
return 0 ;
}
static int F_12 ( struct V_24 * V_25 , T_3 V_26 ,
T_3 V_33 )
{
struct V_1 * V_2 = V_25 -> V_28 ;
T_4 V_29 ;
T_3 V_35 = 8000000 ;
F_2 ( 1 , L_8 , V_15 ) ;
if ( V_26 == 0 )
return - V_30 ;
if ( V_33 == V_36 )
V_35 = 6000000 ;
else
if ( V_33 == V_37 )
V_35 = 7000000 ;
V_29 = V_26 ;
V_29 *= 7 ;
V_29 *= 32 ;
V_29 *= 10 ;
F_10 ( V_29 , V_35 ) ;
V_29 += 5 ;
F_10 ( V_29 , 10 ) ;
F_1 ( V_2 , V_42 , ( T_1 ) V_29 ) ;
F_1 ( V_2 , V_43 , ( T_1 ) ( V_29 >> 8 ) ) ;
return 0 ;
}
static int F_13 ( struct V_24 * V_25 ,
enum V_44 V_33 )
{
struct V_1 * V_2 = V_25 -> V_28 ;
F_2 ( 1 , L_9 , V_15 , V_33 ) ;
switch ( V_33 ) {
case V_36 :
case V_37 :
case V_45 :
F_11 ( V_25 , V_2 -> V_46 , V_33 ) ;
F_12 ( V_25 , V_2 -> V_46 , V_33 ) ;
break;
default:
F_4 ( V_20 L_10 , V_15 ) ;
return - V_30 ;
}
V_2 -> V_47 = V_33 ;
return 0 ;
}
static int F_14 ( struct V_24 * V_25 , enum V_44 V_33 )
{
struct V_1 * V_2 = V_25 -> V_28 ;
struct V_5 * V_6 = & V_2 -> V_6 ;
int V_48 ;
T_3 V_49 ;
F_2 ( 1 , L_11 , V_15 , V_33 ) ;
switch ( V_33 ) {
case V_36 :
V_49 = V_6 -> V_50 ;
break;
case V_37 :
V_49 = V_6 -> V_51 ;
break;
case V_45 :
V_49 = V_6 -> V_52 ;
break;
default:
F_4 ( V_20 L_12 , V_15 ) ;
return - V_30 ;
}
for ( V_48 = 0 ; V_48 < F_15 ( V_53 ) ; V_48 ++ ) {
if ( ( V_53 [ V_48 ] . V_54 == V_6 -> V_54 ) &&
( V_53 [ V_48 ] . V_49 == V_49 ) ) {
V_2 -> V_55 = V_53 [ V_48 ] . V_49 * 1000 ;
V_2 -> V_56 = V_53 [ V_48 ] . V_54 * 1000 ;
break;
}
}
if ( V_48 == F_15 ( V_53 ) ) {
F_4 ( V_20 L_13 ,
V_15 ) ;
return - V_30 ;
}
F_2 ( 1 , L_14 , V_2 -> V_55 ) ;
F_2 ( 1 , L_15 , V_2 -> V_56 ) ;
F_2 ( 1 , L_16 , V_2 -> V_57 ) ;
F_2 ( 1 , L_17 , V_2 -> V_58 ) ;
F_2 ( 1 , L_18 , V_2 -> V_59 ) ;
V_2 -> V_46 = V_2 -> V_56 * ( V_2 -> V_57 + 45 ) ;
V_2 -> V_46 /= ( V_2 -> V_58 + 1 ) ;
V_2 -> V_46 /= ( V_2 -> V_59 + 4 ) ;
F_2 ( 1 , L_19 , V_2 -> V_46 ) ;
F_9 ( V_25 , V_2 -> V_46 , V_2 -> V_55 ) ;
return 0 ;
}
static int F_16 ( struct V_24 * V_25 )
{
struct V_1 * V_2 = V_25 -> V_28 ;
struct V_5 * V_6 = & V_2 -> V_6 ;
const struct V_60 * V_61 ;
int V_7 ;
int V_62 = 0 ;
int V_63 ;
T_1 V_64 = V_6 -> V_65 ;
if ( ( V_64 != V_66 ) && ( V_64 != V_67 ) )
V_64 = V_66 ;
F_4 ( V_68 L_20 ,
V_15 ,
V_69 ) ;
V_7 = F_17 ( & V_61 , V_69 ,
V_2 -> V_16 -> V_70 . V_71 ) ;
if ( V_7 ) {
F_4 ( V_20 L_21 ,
V_15 ) ;
return - V_72 ;
} else {
F_4 ( V_68 L_22 ,
V_15 ,
V_61 -> V_73 ) ;
V_7 = 0 ;
}
if ( V_61 -> V_73 != V_74 ) {
F_4 ( V_20 L_23 , V_15 ) ;
V_7 = - V_72 ;
} else {
F_4 ( V_68 L_24 , V_15 ) ;
F_1 ( V_2 , V_75 ,
F_5 ( V_2 , V_75 )
& 0xfe ) ;
F_1 ( V_2 , V_75 ,
F_5 ( V_2 , V_75 )
| 0x01 ) ;
F_1 ( V_2 , V_76 ,
F_5 ( V_2 , V_76 ) & 0xf9 ) ;
F_1 ( V_2 , V_76 ,
F_5 ( V_2 , V_76 ) | 0x08 ) ;
F_1 ( V_2 , V_77 , 0 ) ;
while ( V_62 < V_61 -> V_73 ) {
if ( ( V_61 -> V_73 - V_62 ) > V_64 )
V_63 = V_64 ;
else
V_63 = V_61 -> V_73 - V_62 ;
F_6 ( V_2 , V_78 ,
& V_61 -> V_4 [ V_62 ] , V_63 ) ;
V_62 += V_63 ;
}
V_7 = - V_72 ;
for ( V_63 = 0 ; V_63 < 250 ; V_63 += 10 ) {
F_18 ( 10 ) ;
if ( F_5 ( V_2 , V_79 )
& 0x40 ) {
V_7 = 0 ;
break;
}
}
}
F_19 ( V_61 ) ;
if ( V_7 == 0 ) {
F_4 ( V_68 L_25 , V_15 ) ;
V_2 -> V_80 = 1 ;
} else
F_4 ( V_20 L_26 , V_15 ) ;
return V_7 ;
}
static int F_20 ( struct V_24 * V_25 , int V_81 )
{
struct V_1 * V_2 = V_25 -> V_28 ;
F_2 ( 1 , L_27 , V_15 , V_81 ) ;
if ( V_81 == V_82 )
F_1 ( V_2 , V_83 ,
F_5 ( V_2 , V_83 ) | 0x20 ) ;
else
F_1 ( V_2 , V_83 ,
F_5 ( V_2 , V_83 ) & 0xdf ) ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 ,
struct V_84 * V_85 )
{
T_1 V_86 ;
if ( ! ( F_5 ( V_2 , V_87 ) & 0x01 ) )
return - V_88 ;
V_86 = F_5 ( V_2 , V_89 ) ;
switch ( ( V_86 & 0x60 ) >> 5 ) {
case 0 :
V_85 -> V_90 = V_91 ;
break;
case 1 :
V_85 -> V_90 = V_92 ;
break;
case 2 :
V_85 -> V_90 = V_93 ;
break;
}
switch ( ( V_86 & 0x18 ) >> 3 ) {
case 0 :
V_85 -> V_94 = V_95 ;
break;
case 1 :
V_85 -> V_94 = V_96 ;
break;
case 2 :
V_85 -> V_94 = V_97 ;
break;
case 3 :
V_85 -> V_94 = V_98 ;
break;
}
switch ( V_86 & 0x07 ) {
case 0 :
V_85 -> V_99 = V_100 ;
break;
case 1 :
V_85 -> V_99 = V_101 ;
break;
case 2 :
V_85 -> V_99 = V_102 ;
break;
case 3 :
V_85 -> V_99 = V_103 ;
break;
case 4 :
V_85 -> V_99 = V_104 ;
break;
}
V_86 = F_5 ( V_2 , V_105 ) ;
switch ( V_86 & 0x07 ) {
case 0 :
V_85 -> V_106 = V_100 ;
break;
case 1 :
V_85 -> V_106 = V_101 ;
break;
case 2 :
V_85 -> V_106 = V_102 ;
break;
case 3 :
V_85 -> V_106 = V_103 ;
break;
case 4 :
V_85 -> V_106 = V_104 ;
break;
}
V_86 = F_5 ( V_2 , V_107 ) ;
switch ( ( V_86 & 0x0c ) >> 2 ) {
case 0 :
V_85 -> V_108 = V_109 ;
break;
case 1 :
V_85 -> V_108 = V_110 ;
break;
case 2 :
V_85 -> V_108 = V_111 ;
break;
case 3 :
V_85 -> V_108 = V_112 ;
break;
}
switch ( V_86 & 0x03 ) {
case 0 :
V_85 -> V_113 = V_114 ;
break;
case 1 :
V_85 -> V_113 = V_115 ;
break;
}
return 0 ;
}
static int F_22 ( struct V_24 * V_25 , int V_116 )
{
struct V_1 * V_2 = V_25 -> V_28 ;
struct V_5 * V_6 = & V_2 -> V_6 ;
F_2 ( 1 , L_27 , V_15 , V_116 ) ;
if ( V_6 -> V_117 )
return 0 ;
if ( V_116 )
return F_1 ( V_2 , V_76 ,
F_5 ( V_2 , V_76 ) | 0x02 ) ;
else
return F_1 ( V_2 , V_76 ,
F_5 ( V_2 , V_76 ) & 0xfd ) ;
}
static int F_23 ( struct V_24 * V_25 , int V_118 )
{
struct V_1 * V_2 = V_25 -> V_28 ;
F_2 ( 1 , L_27 , V_15 , V_118 ) ;
F_1 ( V_2 , V_75 , 0x21 ) ;
F_1 ( V_2 , V_119 , 0x00 ) ;
if ( V_118 ) {
F_1 ( V_2 , V_120 , 0x80 | 0x20 ) ;
F_1 ( V_2 , V_121 , 0xc0 ) ;
} else {
F_1 ( V_2 , V_120 , 0x00 ) ;
F_1 ( V_2 , V_121 , 0x01 ) ;
}
return 0 ;
}
static int F_24 ( struct V_24 * V_25 ,
struct V_122 * V_85 )
{
struct V_1 * V_2 = V_25 -> V_28 ;
F_2 ( 1 , L_28 , V_15 , V_85 -> V_123 ) ;
if ( V_85 -> V_124 . V_125 . V_47 != V_2 -> V_47 ) {
F_14 ( V_25 , V_85 -> V_124 . V_125 . V_47 ) ;
F_13 ( V_25 , V_85 -> V_124 . V_125 . V_47 ) ;
}
if ( V_25 -> V_126 . V_127 . V_128 ) {
if ( V_25 -> V_126 . V_129 )
V_25 -> V_126 . V_129 ( V_25 , 1 ) ;
V_25 -> V_126 . V_127 . V_128 ( V_25 , V_85 ) ;
if ( V_25 -> V_126 . V_129 )
V_25 -> V_126 . V_129 ( V_25 , 0 ) ;
}
F_1 ( V_2 , V_87 , 0x57 ) ;
F_1 ( V_2 , V_130 , 0x3B ) ;
return 0 ;
}
static int F_25 ( struct V_24 * V_25 )
{
struct V_1 * V_2 = V_25 -> V_28 ;
struct V_5 * V_6 = & V_2 -> V_6 ;
int V_7 = 0 , V_48 ;
F_2 ( 1 , L_8 , V_15 ) ;
V_131 [ 4 ] . V_4 = ( T_1 ) ( V_2 -> V_57 ) ;
V_131 [ 5 ] . V_4 = ( T_1 ) ( V_2 -> V_58 ) | 0x40 ;
for ( V_48 = 0 ; V_48 < F_15 ( V_131 ) ; V_48 ++ )
F_1 ( V_2 , V_131 [ V_48 ] . V_3 , V_131 [ V_48 ] . V_4 ) ;
if ( V_2 -> V_80 == 0 )
V_7 = F_16 ( V_25 ) ;
F_23 ( V_25 , V_6 -> V_132 ) ;
F_20 ( V_25 , V_6 -> V_81 ) ;
F_14 ( V_25 , V_45 ) ;
F_13 ( V_25 , V_45 ) ;
F_22 ( V_25 , 0 ) ;
return V_7 ;
}
static int F_26 ( struct V_24 * V_25 , T_5 * V_133 )
{
struct V_1 * V_2 = V_25 -> V_28 ;
T_1 V_3 ;
* V_133 = 0 ;
V_3 = F_5 ( V_2 , V_79 ) ;
F_2 ( 1 , L_29 , V_15 , V_3 ) ;
if ( V_3 & 0x02 )
* V_133 |= V_134 ;
if ( V_3 & 0x04 )
* V_133 |= V_135 ;
if ( V_3 & 0x08 ) {
* V_133 |= V_136 ;
* V_133 |= V_137 ;
* V_133 |= V_138 ;
}
return 0 ;
}
static int F_27 ( struct V_24 * V_25 , T_3 * V_139 )
{
struct V_1 * V_2 = V_25 -> V_28 ;
static T_3 V_140 ;
T_3 V_141 ;
T_4 V_142 ;
F_2 ( 1 , L_8 , V_15 ) ;
if ( F_5 ( V_2 , V_143 ) & 0x01 ) {
V_142 = F_5 ( V_2 , V_144 ) << 8 |
F_5 ( V_2 , V_145 ) ;
V_141 = F_5 ( V_2 , V_146 ) << 8 |
F_5 ( V_2 , V_147 ) ;
V_142 *= 100000000 ;
V_142 *= 2 ;
V_142 = F_28 ( V_142 , ( V_141 * 32 ) + 1 ) ;
V_140 = ( T_3 ) V_142 ;
F_1 ( V_2 , V_130 , 0x39 ) ;
}
* V_139 = V_140 ;
return 0 ;
}
static int F_29 ( struct V_24 * V_25 ,
T_2 * V_148 )
{
struct V_1 * V_2 = V_25 -> V_28 ;
T_1 V_149 ;
F_2 ( 1 , L_8 , V_15 ) ;
* V_148 = 65535 ;
V_149 = F_5 ( V_2 , V_150 ) ;
if ( V_149 > 0 )
* V_148 -= ( V_149 << 8 ) | V_149 ;
return 0 ;
}
static int F_30 ( struct V_24 * V_25 , T_2 * V_151 )
{
struct V_1 * V_2 = V_25 -> V_28 ;
T_1 V_149 ;
int V_48 , V_7 = - V_30 ;
F_2 ( 1 , L_8 , V_15 ) ;
V_149 = F_5 ( V_2 , V_150 ) ;
for ( V_48 = 0 ; V_48 < F_15 ( V_152 ) ; V_48 ++ ) {
if ( V_149 <= V_152 [ V_48 ] . V_86 ) {
* V_151 = V_152 [ V_48 ] . V_4 ;
V_7 = 0 ;
break;
}
}
return V_7 ;
}
static int F_31 ( struct V_24 * V_25 , T_3 * V_153 )
{
struct V_1 * V_2 = V_25 -> V_28 ;
F_2 ( 1 , L_8 , V_15 ) ;
* V_153 = F_5 ( V_2 , V_154 ) << 8 |
F_5 ( V_2 , V_155 ) ;
if ( * V_153 == 0xFFFF )
F_1 ( V_2 , V_156 , 0x80 ) ;
return 0 ;
}
static int F_32 ( struct V_24 * V_25 ,
struct V_122 * V_85 )
{
struct V_1 * V_2 = V_25 -> V_28 ;
F_2 ( 1 , L_8 , V_15 ) ;
V_85 -> V_81 = F_5 ( V_2 , V_83 )
& 0x20 ? V_157 : V_158 ;
return F_21 ( V_2 , & V_85 -> V_124 . V_125 ) ;
}
static int F_33 ( struct V_24 * V_25 ,
struct V_159 * V_160 )
{
V_160 -> V_161 = 1000 ;
return 0 ;
}
static void F_34 ( struct V_24 * V_25 )
{
struct V_1 * V_2 = V_25 -> V_28 ;
F_2 ( 1 , L_8 , V_15 ) ;
F_8 ( V_2 ) ;
}
static void F_35 ( struct V_24 * V_25 )
{
struct V_1 * V_2 = V_25 -> V_28 ;
struct V_5 * V_6 = & V_2 -> V_6 ;
if ( V_6 -> V_50 == 0 ) {
V_6 -> V_50 = V_162 ;
F_4 ( V_163 L_30
L_31 ,
V_15 ,
V_6 -> V_50 ) ;
}
if ( V_6 -> V_51 == 0 ) {
V_6 -> V_51 = V_162 ;
F_4 ( V_163 L_32
L_31 ,
V_15 ,
V_6 -> V_51 ) ;
}
if ( V_6 -> V_52 == 0 ) {
V_6 -> V_52 = V_162 ;
F_4 ( V_163 L_33
L_31 ,
V_15 ,
V_6 -> V_52 ) ;
}
if ( V_6 -> V_54 == 0 ) {
V_6 -> V_54 = V_164 ;
F_4 ( V_163 L_34
L_31 ,
V_15 ,
V_6 -> V_54 ) ;
}
}
struct V_24 * F_36 ( const struct V_5 * V_6 ,
struct V_165 * V_16 )
{
struct V_1 * V_2 = NULL ;
F_2 ( 1 , L_8 , V_15 ) ;
V_2 = F_37 ( sizeof( struct V_1 ) , V_22 ) ;
if ( V_2 == NULL )
goto error;
memcpy ( & V_2 -> V_6 , V_6 , sizeof( * V_6 ) ) ;
V_2 -> V_16 = V_16 ;
V_2 -> V_80 = V_6 -> V_166 ;
V_2 -> V_47 = V_45 ;
if ( F_5 ( V_2 , V_167 ) != 0x048 )
goto error;
memcpy ( & V_2 -> V_168 . V_126 , & V_169 ,
sizeof( struct V_170 ) ) ;
V_2 -> V_168 . V_28 = V_2 ;
if ( V_6 -> V_171 ) {
V_2 -> V_57 = V_6 -> V_172 ;
V_2 -> V_58 = V_6 -> V_173 ;
V_2 -> V_59 = V_6 -> V_174 ;
} else {
V_2 -> V_57 = 10 ;
V_2 -> V_58 = 3 ;
V_2 -> V_59 = 0 ;
}
F_35 ( & V_2 -> V_168 ) ;
if ( F_14 ( & V_2 -> V_168 , V_45 ) != 0 )
goto error;
if ( F_13 ( & V_2 -> V_168 , V_45 ) != 0 )
goto error;
F_22 ( & V_2 -> V_168 , 0 ) ;
return & V_2 -> V_168 ;
error:
F_8 ( V_2 ) ;
return NULL ;
}
