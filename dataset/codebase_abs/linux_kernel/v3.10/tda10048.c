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
F_2 ( 1 , L_8 , V_15 ) ;
if ( V_26 == 0 )
return - V_30 ;
V_29 = V_33 * 10 ;
V_29 *= ( 2048 * 1024 ) ;
V_29 *= 1024 ;
V_34 = 7 * V_26 ;
F_10 ( V_29 , V_34 ) ;
V_29 += 5 ;
F_10 ( V_29 , 10 ) ;
F_1 ( V_2 , V_35 , ( T_1 ) V_29 ) ;
F_1 ( V_2 , V_36 , ( T_1 ) ( V_29 >> 8 ) ) ;
F_1 ( V_2 , V_37 , ( T_1 ) ( V_29 >> 16 ) ) ;
F_1 ( V_2 , V_38 , ( T_1 ) ( V_29 >> 24 ) ) ;
return 0 ;
}
static int F_12 ( struct V_24 * V_25 , T_3 V_26 ,
T_3 V_33 )
{
struct V_1 * V_2 = V_25 -> V_28 ;
T_4 V_29 ;
F_2 ( 1 , L_8 , V_15 ) ;
if ( V_26 == 0 )
return - V_30 ;
V_29 = V_26 ;
V_29 *= 7 ;
V_29 *= 32 ;
V_29 *= 10 ;
F_10 ( V_29 , V_33 ) ;
V_29 += 5 ;
F_10 ( V_29 , 10 ) ;
F_1 ( V_2 , V_39 , ( T_1 ) V_29 ) ;
F_1 ( V_2 , V_40 , ( T_1 ) ( V_29 >> 8 ) ) ;
return 0 ;
}
static int F_13 ( struct V_24 * V_25 ,
T_3 V_33 )
{
struct V_1 * V_2 = V_25 -> V_28 ;
F_2 ( 1 , L_9 , V_15 , V_33 ) ;
switch ( V_33 ) {
case 6000000 :
case 7000000 :
case 8000000 :
F_11 ( V_25 , V_2 -> V_41 , V_33 ) ;
F_12 ( V_25 , V_2 -> V_41 , V_33 ) ;
break;
default:
F_4 ( V_20 L_10 , V_15 ) ;
return - V_30 ;
}
V_2 -> V_42 = V_33 ;
return 0 ;
}
static int F_14 ( struct V_24 * V_25 , T_3 V_33 )
{
struct V_1 * V_2 = V_25 -> V_28 ;
struct V_5 * V_6 = & V_2 -> V_6 ;
int V_43 ;
T_3 V_44 ;
F_2 ( 1 , L_11 , V_15 , V_33 ) ;
switch ( V_33 ) {
case 6000000 :
V_44 = V_6 -> V_45 ;
break;
case 7000000 :
V_44 = V_6 -> V_46 ;
break;
case 8000000 :
V_44 = V_6 -> V_47 ;
break;
default:
F_4 ( V_20 L_12 , V_15 ) ;
return - V_30 ;
}
for ( V_43 = 0 ; V_43 < F_15 ( V_48 ) ; V_43 ++ ) {
if ( ( V_48 [ V_43 ] . V_49 == V_6 -> V_49 ) &&
( V_48 [ V_43 ] . V_44 == V_44 ) ) {
V_2 -> V_50 = V_48 [ V_43 ] . V_44 * 1000 ;
V_2 -> V_51 = V_48 [ V_43 ] . V_49 * 1000 ;
break;
}
}
if ( V_43 == F_15 ( V_48 ) ) {
F_4 ( V_20 L_13 ,
V_15 ) ;
return - V_30 ;
}
F_2 ( 1 , L_14 , V_2 -> V_50 ) ;
F_2 ( 1 , L_15 , V_2 -> V_51 ) ;
F_2 ( 1 , L_16 , V_2 -> V_52 ) ;
F_2 ( 1 , L_17 , V_2 -> V_53 ) ;
F_2 ( 1 , L_18 , V_2 -> V_54 ) ;
V_2 -> V_41 = V_2 -> V_51 * ( V_2 -> V_52 + 45 ) ;
V_2 -> V_41 /= ( V_2 -> V_53 + 1 ) ;
V_2 -> V_41 /= ( V_2 -> V_54 + 4 ) ;
F_2 ( 1 , L_19 , V_2 -> V_41 ) ;
F_9 ( V_25 , V_2 -> V_41 , V_2 -> V_50 ) ;
return 0 ;
}
static int F_16 ( struct V_24 * V_25 )
{
struct V_1 * V_2 = V_25 -> V_28 ;
struct V_5 * V_6 = & V_2 -> V_6 ;
const struct V_55 * V_56 ;
int V_7 ;
int V_57 = 0 ;
int V_58 ;
T_1 V_59 = V_6 -> V_60 ;
if ( ( V_59 != V_61 ) && ( V_59 != V_62 ) )
V_59 = V_61 ;
F_4 ( V_63 L_20 ,
V_15 ,
V_64 ) ;
V_7 = F_17 ( & V_56 , V_64 ,
V_2 -> V_16 -> V_65 . V_66 ) ;
if ( V_7 ) {
F_4 ( V_20 L_21 ,
V_15 ) ;
return - V_67 ;
} else {
F_4 ( V_63 L_22 ,
V_15 ,
V_56 -> V_68 ) ;
V_7 = 0 ;
}
if ( V_56 -> V_68 != V_69 ) {
F_4 ( V_20 L_23 , V_15 ) ;
V_7 = - V_67 ;
} else {
F_4 ( V_63 L_24 , V_15 ) ;
F_1 ( V_2 , V_70 ,
F_5 ( V_2 , V_70 )
& 0xfe ) ;
F_1 ( V_2 , V_70 ,
F_5 ( V_2 , V_70 )
| 0x01 ) ;
F_1 ( V_2 , V_71 ,
F_5 ( V_2 , V_71 ) & 0xf9 ) ;
F_1 ( V_2 , V_71 ,
F_5 ( V_2 , V_71 ) | 0x08 ) ;
F_1 ( V_2 , V_72 , 0 ) ;
while ( V_57 < V_56 -> V_68 ) {
if ( ( V_56 -> V_68 - V_57 ) > V_59 )
V_58 = V_59 ;
else
V_58 = V_56 -> V_68 - V_57 ;
F_6 ( V_2 , V_73 ,
& V_56 -> V_4 [ V_57 ] , V_58 ) ;
V_57 += V_58 ;
}
V_7 = - V_67 ;
for ( V_58 = 0 ; V_58 < 250 ; V_58 += 10 ) {
F_18 ( 10 ) ;
if ( F_5 ( V_2 , V_74 )
& 0x40 ) {
V_7 = 0 ;
break;
}
}
}
F_19 ( V_56 ) ;
if ( V_7 == 0 ) {
F_4 ( V_63 L_25 , V_15 ) ;
V_2 -> V_75 = 1 ;
} else
F_4 ( V_20 L_26 , V_15 ) ;
return V_7 ;
}
static int F_20 ( struct V_24 * V_25 , int V_76 )
{
struct V_1 * V_2 = V_25 -> V_28 ;
F_2 ( 1 , L_27 , V_15 , V_76 ) ;
if ( V_76 == V_77 )
F_1 ( V_2 , V_78 ,
F_5 ( V_2 , V_78 ) | 0x20 ) ;
else
F_1 ( V_2 , V_78 ,
F_5 ( V_2 , V_78 ) & 0xdf ) ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 ,
struct V_79 * V_80 )
{
T_1 V_81 ;
if ( ! ( F_5 ( V_2 , V_82 ) & 0x01 ) )
return - V_83 ;
V_81 = F_5 ( V_2 , V_84 ) ;
switch ( ( V_81 & 0x60 ) >> 5 ) {
case 0 :
V_80 -> V_85 = V_86 ;
break;
case 1 :
V_80 -> V_85 = V_87 ;
break;
case 2 :
V_80 -> V_85 = V_88 ;
break;
}
switch ( ( V_81 & 0x18 ) >> 3 ) {
case 0 :
V_80 -> V_89 = V_90 ;
break;
case 1 :
V_80 -> V_89 = V_91 ;
break;
case 2 :
V_80 -> V_89 = V_92 ;
break;
case 3 :
V_80 -> V_89 = V_93 ;
break;
}
switch ( V_81 & 0x07 ) {
case 0 :
V_80 -> V_94 = V_95 ;
break;
case 1 :
V_80 -> V_94 = V_96 ;
break;
case 2 :
V_80 -> V_94 = V_97 ;
break;
case 3 :
V_80 -> V_94 = V_98 ;
break;
case 4 :
V_80 -> V_94 = V_99 ;
break;
}
V_81 = F_5 ( V_2 , V_100 ) ;
switch ( V_81 & 0x07 ) {
case 0 :
V_80 -> V_101 = V_95 ;
break;
case 1 :
V_80 -> V_101 = V_96 ;
break;
case 2 :
V_80 -> V_101 = V_97 ;
break;
case 3 :
V_80 -> V_101 = V_98 ;
break;
case 4 :
V_80 -> V_101 = V_99 ;
break;
}
V_81 = F_5 ( V_2 , V_102 ) ;
switch ( ( V_81 & 0x0c ) >> 2 ) {
case 0 :
V_80 -> V_103 = V_104 ;
break;
case 1 :
V_80 -> V_103 = V_105 ;
break;
case 2 :
V_80 -> V_103 = V_106 ;
break;
case 3 :
V_80 -> V_103 = V_107 ;
break;
}
switch ( V_81 & 0x03 ) {
case 0 :
V_80 -> V_108 = V_109 ;
break;
case 1 :
V_80 -> V_108 = V_110 ;
break;
}
return 0 ;
}
static int F_22 ( struct V_24 * V_25 , int V_111 )
{
struct V_1 * V_2 = V_25 -> V_28 ;
struct V_5 * V_6 = & V_2 -> V_6 ;
F_2 ( 1 , L_27 , V_15 , V_111 ) ;
if ( V_6 -> V_112 )
return 0 ;
if ( V_111 )
return F_1 ( V_2 , V_71 ,
F_5 ( V_2 , V_71 ) | 0x02 ) ;
else
return F_1 ( V_2 , V_71 ,
F_5 ( V_2 , V_71 ) & 0xfd ) ;
}
static int F_23 ( struct V_24 * V_25 , int V_113 )
{
struct V_1 * V_2 = V_25 -> V_28 ;
F_2 ( 1 , L_27 , V_15 , V_113 ) ;
F_1 ( V_2 , V_70 , 0x21 ) ;
F_1 ( V_2 , V_114 , 0x00 ) ;
if ( V_113 ) {
F_1 ( V_2 , V_115 , 0x80 | 0x20 ) ;
F_1 ( V_2 , V_116 , 0xc0 ) ;
} else {
F_1 ( V_2 , V_115 , 0x00 ) ;
F_1 ( V_2 , V_116 , 0x01 ) ;
}
return 0 ;
}
static int F_24 ( struct V_24 * V_25 )
{
struct V_79 * V_80 = & V_25 -> V_117 ;
struct V_1 * V_2 = V_25 -> V_28 ;
F_2 ( 1 , L_28 , V_15 , V_80 -> V_118 ) ;
if ( V_80 -> V_119 != V_2 -> V_42 ) {
F_14 ( V_25 , V_80 -> V_119 ) ;
F_13 ( V_25 , V_80 -> V_119 ) ;
}
if ( V_25 -> V_120 . V_121 . V_122 ) {
if ( V_25 -> V_120 . V_123 )
V_25 -> V_120 . V_123 ( V_25 , 1 ) ;
V_25 -> V_120 . V_121 . V_122 ( V_25 ) ;
if ( V_25 -> V_120 . V_123 )
V_25 -> V_120 . V_123 ( V_25 , 0 ) ;
}
F_1 ( V_2 , V_82 , 0x57 ) ;
F_1 ( V_2 , V_124 , 0x3B ) ;
return 0 ;
}
static int F_25 ( struct V_24 * V_25 )
{
struct V_1 * V_2 = V_25 -> V_28 ;
struct V_5 * V_6 = & V_2 -> V_6 ;
int V_7 = 0 , V_43 ;
F_2 ( 1 , L_8 , V_15 ) ;
V_125 [ 4 ] . V_4 = ( T_1 ) ( V_2 -> V_52 ) ;
V_125 [ 5 ] . V_4 = ( T_1 ) ( V_2 -> V_53 ) | 0x40 ;
for ( V_43 = 0 ; V_43 < F_15 ( V_125 ) ; V_43 ++ )
F_1 ( V_2 , V_125 [ V_43 ] . V_3 , V_125 [ V_43 ] . V_4 ) ;
if ( V_2 -> V_75 == 0 )
V_7 = F_16 ( V_25 ) ;
F_23 ( V_25 , V_6 -> V_126 ) ;
F_20 ( V_25 , V_6 -> V_76 ) ;
F_14 ( V_25 , 8000000 ) ;
F_13 ( V_25 , 8000000 ) ;
F_22 ( V_25 , 0 ) ;
return V_7 ;
}
static int F_26 ( struct V_24 * V_25 , T_5 * V_127 )
{
struct V_1 * V_2 = V_25 -> V_28 ;
T_1 V_3 ;
* V_127 = 0 ;
V_3 = F_5 ( V_2 , V_74 ) ;
F_2 ( 1 , L_29 , V_15 , V_3 ) ;
if ( V_3 & 0x02 )
* V_127 |= V_128 ;
if ( V_3 & 0x04 )
* V_127 |= V_129 ;
if ( V_3 & 0x08 ) {
* V_127 |= V_130 ;
* V_127 |= V_131 ;
* V_127 |= V_132 ;
}
return 0 ;
}
static int F_27 ( struct V_24 * V_25 , T_3 * V_133 )
{
struct V_1 * V_2 = V_25 -> V_28 ;
static T_3 V_134 ;
T_3 V_135 ;
T_4 V_136 ;
F_2 ( 1 , L_8 , V_15 ) ;
if ( F_5 ( V_2 , V_137 ) & 0x01 ) {
V_136 = F_5 ( V_2 , V_138 ) << 8 |
F_5 ( V_2 , V_139 ) ;
V_135 = F_5 ( V_2 , V_140 ) << 8 |
F_5 ( V_2 , V_141 ) ;
V_136 *= 100000000 ;
V_136 *= 2 ;
V_136 = F_28 ( V_136 , ( V_135 * 32 ) + 1 ) ;
V_134 = ( T_3 ) V_136 ;
F_1 ( V_2 , V_124 , 0x39 ) ;
}
* V_133 = V_134 ;
return 0 ;
}
static int F_29 ( struct V_24 * V_25 ,
T_2 * V_142 )
{
struct V_1 * V_2 = V_25 -> V_28 ;
T_1 V_143 ;
F_2 ( 1 , L_8 , V_15 ) ;
* V_142 = 65535 ;
V_143 = F_5 ( V_2 , V_144 ) ;
if ( V_143 > 0 )
* V_142 -= ( V_143 << 8 ) | V_143 ;
return 0 ;
}
static int F_30 ( struct V_24 * V_25 , T_2 * V_145 )
{
struct V_1 * V_2 = V_25 -> V_28 ;
T_1 V_143 ;
int V_43 , V_7 = - V_30 ;
F_2 ( 1 , L_8 , V_15 ) ;
V_143 = F_5 ( V_2 , V_144 ) ;
for ( V_43 = 0 ; V_43 < F_15 ( V_146 ) ; V_43 ++ ) {
if ( V_143 <= V_146 [ V_43 ] . V_81 ) {
* V_145 = V_146 [ V_43 ] . V_4 ;
V_7 = 0 ;
break;
}
}
return V_7 ;
}
static int F_31 ( struct V_24 * V_25 , T_3 * V_147 )
{
struct V_1 * V_2 = V_25 -> V_28 ;
F_2 ( 1 , L_8 , V_15 ) ;
* V_147 = F_5 ( V_2 , V_148 ) << 8 |
F_5 ( V_2 , V_149 ) ;
if ( * V_147 == 0xFFFF )
F_1 ( V_2 , V_150 , 0x80 ) ;
return 0 ;
}
static int F_32 ( struct V_24 * V_25 )
{
struct V_79 * V_80 = & V_25 -> V_117 ;
struct V_1 * V_2 = V_25 -> V_28 ;
F_2 ( 1 , L_8 , V_15 ) ;
V_80 -> V_76 = F_5 ( V_2 , V_78 )
& 0x20 ? V_151 : V_152 ;
return F_21 ( V_2 , V_80 ) ;
}
static int F_33 ( struct V_24 * V_25 ,
struct V_153 * V_154 )
{
V_154 -> V_155 = 1000 ;
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
if ( V_6 -> V_45 == 0 ) {
V_6 -> V_45 = V_156 ;
F_4 ( V_157 L_30
L_31 ,
V_15 ,
V_6 -> V_45 ) ;
}
if ( V_6 -> V_46 == 0 ) {
V_6 -> V_46 = V_156 ;
F_4 ( V_157 L_32
L_31 ,
V_15 ,
V_6 -> V_46 ) ;
}
if ( V_6 -> V_47 == 0 ) {
V_6 -> V_47 = V_156 ;
F_4 ( V_157 L_33
L_31 ,
V_15 ,
V_6 -> V_47 ) ;
}
if ( V_6 -> V_49 == 0 ) {
V_6 -> V_49 = V_158 ;
F_4 ( V_157 L_34
L_31 ,
V_15 ,
V_6 -> V_49 ) ;
}
}
struct V_24 * F_36 ( const struct V_5 * V_6 ,
struct V_159 * V_16 )
{
struct V_1 * V_2 = NULL ;
F_2 ( 1 , L_8 , V_15 ) ;
V_2 = F_37 ( sizeof( struct V_1 ) , V_22 ) ;
if ( V_2 == NULL )
goto error;
memcpy ( & V_2 -> V_6 , V_6 , sizeof( * V_6 ) ) ;
V_2 -> V_16 = V_16 ;
V_2 -> V_75 = V_6 -> V_160 ;
V_2 -> V_42 = 8000000 ;
if ( F_5 ( V_2 , V_161 ) != 0x048 )
goto error;
memcpy ( & V_2 -> V_162 . V_120 , & V_163 ,
sizeof( struct V_164 ) ) ;
V_2 -> V_162 . V_28 = V_2 ;
if ( V_6 -> V_165 ) {
V_2 -> V_52 = V_6 -> V_166 ;
V_2 -> V_53 = V_6 -> V_167 ;
V_2 -> V_54 = V_6 -> V_168 ;
} else {
V_2 -> V_52 = 10 ;
V_2 -> V_53 = 3 ;
V_2 -> V_54 = 0 ;
}
F_35 ( & V_2 -> V_162 ) ;
if ( F_14 ( & V_2 -> V_162 , 8000000 ) != 0 )
goto error;
if ( F_13 ( & V_2 -> V_162 , 8000000 ) != 0 )
goto error;
F_22 ( & V_2 -> V_162 , 0 ) ;
return & V_2 -> V_162 ;
error:
F_8 ( V_2 ) ;
return NULL ;
}
