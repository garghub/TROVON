void F_1 ( struct V_1 * V_2 )
{
int V_3 ;
if ( 0 == V_2 -> V_4 -> V_5 &&
0 == V_2 -> V_4 -> V_6 ) {
F_2 ( L_1
L_2
L_3
L_4
L_5 ,
V_2 -> V_7 , V_2 -> V_7 , V_2 -> V_7 , V_2 -> V_7 , V_2 -> V_7 ) ;
} else {
F_2 ( L_6
L_7
L_8
L_9 ,
V_2 -> V_7 , V_2 -> V_7 , V_2 -> V_7 , V_2 -> V_7 ) ;
}
F_2 ( L_10 ,
V_2 -> V_7 ) ;
for ( V_3 = 0 ; V_3 < V_8 ; V_3 ++ )
F_2 ( L_11 ,
V_2 -> V_7 , V_3 , V_9 [ V_3 ] . V_7 ) ;
}
static void F_3 ( struct V_1 * V_2 , T_1 * V_10 )
{
T_2 V_11 ;
if ( * ( V_10 + 0x00 ) != 0x59 ) {
F_2 ( L_12 ,
V_12 ) ;
return;
}
V_11 = ( * ( V_10 + 0x06 ) << 24 ) |
( * ( V_10 + 0x05 ) << 16 ) |
( * ( V_10 + 0x04 ) << 8 ) |
( * ( V_10 + 0x03 ) ) ;
F_2 ( L_13 ,
V_2 -> V_7 ,
V_9 [ V_2 -> V_13 ] . V_7 ,
V_11 ) ;
}
static void F_4 ( struct V_1 * V_2 , T_1 * V_10 )
{
struct V_14 V_15 ;
F_5 ( & V_2 -> V_16 [ 0 ] . V_17 , & V_15 ,
V_10 ) ;
switch ( V_15 . V_18 ) {
case 22001 :
case 22009 :
case 22011 :
case 22019 :
case 22021 :
case 22029 :
case 22101 :
case 22109 :
case 22111 :
case 22119 :
case 22121 :
case 22129 :
case 71009 :
case 71100 :
case 71359 :
case 71439 :
case 71449 :
case 71939 :
case 71949 :
case 71959 :
case 71979 :
case 71999 :
case 76601 :
case 77001 :
case 77011 :
case 77041 :
case 77051 :
case 78011 :
case 78501 :
case 78521 :
case 78531 :
case 78631 :
case 79001 :
case 79101 :
case 79501 :
case 79561 :
case 79571 :
case 79671 :
case 80019 :
case 81509 :
case 81519 :
break;
case 85021 :
break;
case 85721 :
case 150329 :
break;
case 166100 :
break;
case 166101 :
break;
case 165100 :
break;
case 165101 :
break;
default:
F_6 ( L_14 ,
V_2 -> V_7 , V_15 . V_18 ) ;
break;
}
F_2 ( L_15 ,
V_2 -> V_7 , V_15 . V_18 ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
int V_3 ;
const T_1 V_19 [] = {
0xe0 , 0x06 , 0x66 , 0x33 , 0x65 ,
0x01 , 0x17 , 0x06 , 0xde } ;
switch ( V_2 -> V_13 ) {
case V_20 :
case V_21 :
F_8 ( V_22 , 0x00070007 ) ;
F_9 ( 1000 , 10000 ) ;
F_10 ( V_22 , 2 ) ;
F_9 ( 1000 , 10000 ) ;
for ( V_3 = 0 ; V_3 < 9 * 8 ; V_3 ++ ) {
F_10 ( V_22 , 7 ) ;
F_9 ( 1000 , 10000 ) ;
F_8 ( V_22 ,
( ( V_19 [ V_3 >> 3 ] >> ( 7 - ( V_3 & 7 ) ) ) & 1 ) | 4 ) ;
F_9 ( 1000 , 10000 ) ;
}
F_8 ( V_22 , 7 ) ;
break;
}
}
int F_11 ( void * V_23 , int V_24 , int V_25 , int V_26 )
{
struct V_27 * V_28 = V_23 ;
struct V_1 * V_2 = V_28 -> V_2 ;
T_2 V_29 = 0 ;
if ( ( V_25 == V_30 ) || ( V_25 == V_31 ) )
return 0 ;
if ( V_25 != 0 ) {
F_12 ( L_16 ,
V_12 , V_25 ) ;
return - V_32 ;
}
switch ( V_2 -> V_13 ) {
case V_33 :
case V_34 :
case V_35 :
case V_36 :
case V_37 :
case V_38 :
case V_39 :
case V_40 :
case V_41 :
V_29 = 0x04 ;
break;
case V_42 :
case V_43 :
case V_44 :
if ( V_28 -> V_45 == 1 )
V_29 = 0x01 ;
else if ( V_28 -> V_45 == 2 )
V_29 = 0x04 ;
break;
case V_46 :
V_29 = 0x02 ;
break;
case V_47 :
F_13 ( V_2 , V_28 -> V_45 ) ;
break;
case V_48 :
V_29 = 1 << 2 ;
break;
}
if ( V_29 ) {
F_10 ( V_22 , V_29 ) ;
F_14 ( 200 ) ;
F_8 ( V_22 , V_29 ) ;
}
return 0 ;
}
void F_15 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_13 ) {
case V_49 :
F_8 ( V_22 , 0x00010001 ) ;
break;
case V_34 :
F_8 ( V_22 , 0x00050000 ) ;
F_10 ( V_22 , 0x00000005 ) ;
F_16 ( 5 ) ;
F_8 ( V_22 , 0x00050005 ) ;
break;
case V_35 :
F_8 ( V_22 , 0x00050005 ) ;
break;
case V_50 :
F_17 ( V_2 , V_51 | V_52 , 1 ) ;
F_18 ( V_2 , V_51 | V_52 ) ;
F_14 ( 100 ) ;
F_19 ( V_2 , V_51 | V_52 ) ;
F_14 ( 100 ) ;
F_20 ( V_2 , V_53 , 1 ) ;
F_21 ( V_2 , V_53 ) ;
F_14 ( 20 ) ;
F_22 ( V_2 , V_53 ) ;
F_14 ( 20 ) ;
F_21 ( V_2 , V_53 ) ;
F_14 ( 20 ) ;
break;
case V_54 :
F_8 ( V_22 , 0x00050000 ) ;
F_14 ( 20 ) ;
F_10 ( V_22 , 0x00000005 ) ;
F_14 ( 20 ) ;
F_8 ( V_22 , 0x00050005 ) ;
break;
case V_55 :
F_8 ( V_22 , 0x00050000 ) ;
F_14 ( 20 ) ;
F_10 ( V_22 , 0x00000005 ) ;
F_14 ( 20 ) ;
F_8 ( V_22 , 0x00050005 ) ;
break;
case V_33 :
F_8 ( V_22 , 0x00050000 ) ;
F_14 ( 20 ) ;
F_10 ( V_22 , 0x00000005 ) ;
F_14 ( 20 ) ;
F_8 ( V_22 , 0x00050005 ) ;
break;
case V_42 :
F_8 ( V_22 , 0x000f0000 ) ;
F_14 ( 20 ) ;
F_10 ( V_22 , 0x0000000f ) ;
F_14 ( 20 ) ;
F_8 ( V_22 , 0x000f000f ) ;
break;
case V_43 :
case V_44 :
F_8 ( V_22 , 0x000f0000 ) ;
F_14 ( 20 ) ;
F_10 ( V_22 , 0x0000000f ) ;
F_14 ( 20 ) ;
F_8 ( V_22 , 0x000f000f ) ;
break;
case V_36 :
case V_37 :
case V_38 :
case V_39 :
case V_40 :
case V_41 :
F_8 ( V_22 , 0x00040000 ) ;
F_14 ( 20 ) ;
F_10 ( V_22 , 0x00000004 ) ;
F_14 ( 20 ) ;
F_8 ( V_22 , 0x00040004 ) ;
break;
case V_56 :
case V_20 :
case V_21 :
case V_57 :
F_23 ( V_58 , 0x00000036 ) ;
F_23 ( V_59 , 0x00001000 ) ;
F_8 ( V_60 , 0x00000002 ) ;
F_14 ( 200 ) ;
F_10 ( V_60 , 0x00000800 ) ;
F_14 ( 200 ) ;
F_8 ( V_60 , 0x00000800 ) ;
F_14 ( 200 ) ;
break;
case V_61 :
F_8 ( V_22 , 0x00040000 ) ;
F_10 ( V_22 , 0x00030004 ) ;
F_14 ( 100 ) ;
F_8 ( V_22 , 0x00040004 ) ;
F_23 ( V_58 , 0x00000037 ) ;
F_23 ( V_59 , 0x00001000 ) ;
F_23 ( V_60 , 0x0000c300 ) ;
F_23 ( V_62 , 0x00000000 ) ;
break;
case V_63 :
case V_64 :
case V_65 :
case V_66 :
case V_67 :
F_20 ( V_2 , V_68 | V_69 | V_70 , 1 ) ;
F_21 ( V_2 , V_68 | V_69 | V_70 ) ;
F_22 ( V_2 , V_68 ) ;
F_14 ( 20 ) ;
F_21 ( V_2 , V_68 ) ;
break;
case V_71 :
case V_72 :
case V_73 :
F_20 ( V_2 , V_74 | V_75 | V_53 , 1 ) ;
F_22 ( V_2 , V_75 | V_53 ) ;
F_14 ( 100 ) ;
F_21 ( V_2 , V_74 | V_75 | V_53 ) ;
F_14 ( 100 ) ;
break;
case V_76 :
F_20 ( V_2 , V_74 | V_75 , 1 ) ;
F_22 ( V_2 , V_74 | V_75 ) ;
F_14 ( 100 ) ;
F_21 ( V_2 , V_74 | V_75 ) ;
F_14 ( 100 ) ;
break;
case V_77 :
case V_78 :
F_17 ( V_2 , V_52 | V_79 , 1 ) ;
F_18 ( V_2 , V_52 | V_79 ) ;
F_14 ( 100 ) ;
F_19 ( V_2 , V_52 ) ;
F_14 ( 100 ) ;
break;
case V_46 :
F_8 ( V_22 , 0x00010001 ) ;
break;
case V_47 :
F_8 ( V_22 , 0x00060000 ) ;
F_10 ( V_22 , 0x00010006 ) ;
F_14 ( 100 ) ;
F_8 ( V_22 , 0x00000004 ) ;
F_23 ( V_58 , 0x00000037 ) ;
F_23 ( V_59 , 0x00005000 ) ;
F_23 ( V_60 , 0x00000d00 ) ;
F_23 ( V_62 , 0x00000000 ) ;
break;
case V_80 :
case V_81 :
F_20 ( V_2 , V_82 | V_68 , 1 ) ;
F_22 ( V_2 , V_82 | V_68 ) ;
F_14 ( 100 ) ;
F_21 ( V_2 , V_82 | V_68 ) ;
F_14 ( 100 ) ;
break;
case V_48 :
F_10 ( V_58 , 1 ) ;
F_8 ( V_22 , 0x00070000 ) ;
F_14 ( 10 ) ;
F_8 ( V_22 , 0x00010001 ) ;
F_14 ( 10 ) ;
F_10 ( V_22 , 0x00010001 ) ;
F_14 ( 10 ) ;
F_8 ( V_22 , 0x00010001 ) ;
F_14 ( 10 ) ;
F_10 ( V_22 , 0x00030003 ) ;
F_14 ( 10 ) ;
F_8 ( V_22 , 0x00020002 ) ;
F_14 ( 10 ) ;
F_8 ( V_22 , 0x00010001 ) ;
F_14 ( 10 ) ;
F_10 ( V_22 , 0x00020002 ) ;
F_8 ( V_22 , 0x00040004 ) ;
F_10 ( V_22 , 0x00040004 ) ;
F_8 ( V_22 , 0x00040004 ) ;
F_14 ( 60 ) ;
break;
case V_83 :
case V_84 :
case V_85 :
F_23 ( V_58 , 0x00000037 ) ;
F_20 ( V_2 , V_53 | V_86 , 1 ) ;
F_22 ( V_2 , V_53 | V_86 ) ;
F_14 ( 100 ) ;
F_21 ( V_2 , V_53 | V_86 ) ;
break;
case V_87 :
case V_88 :
case V_89 :
F_8 ( V_22 , 0x00060002 ) ;
F_10 ( V_22 , 0x00010004 ) ;
F_14 ( 100 ) ;
F_8 ( V_22 , 0x00060004 ) ;
F_10 ( V_22 , 0x00010002 ) ;
F_23 ( V_58 , 0x00000037 ) ;
F_23 ( V_59 , 0x00001000 ) ;
F_23 ( V_60 , 0x0000c300 ) ;
F_23 ( V_62 , 0x00000000 ) ;
break;
case V_90 :
F_20 ( V_2 , V_53 , 1 ) ;
F_22 ( V_2 , V_53 ) ;
F_16 ( 100 ) ;
F_21 ( V_2 , V_53 ) ;
break;
case V_91 :
case V_92 :
case V_93 :
F_20 ( V_2 , V_82 | V_68 , 1 ) ;
F_22 ( V_2 , V_82 | V_68 ) ;
F_16 ( 100 ) ;
F_21 ( V_2 , V_82 | V_68 ) ;
F_16 ( 100 ) ;
break;
case V_94 :
case V_95 :
break;
}
}
int F_24 ( struct V_1 * V_2 )
{
static struct V_96 V_97 [] = {
{
. V_98 = V_99 ,
. V_100 = V_101 ,
. V_102 = V_103 ,
. V_104 = 0 ,
. V_105 = V_106 ,
} , {
. V_98 = V_107 ,
. V_100 = V_108 ,
. V_102 = V_109 ,
. V_104 = 0 ,
. V_105 = V_106 ,
}
} ;
const T_3 V_110 = F_25 ( V_97 ) ;
static struct V_96 V_111 [] = {
{
. V_98 = V_99 ,
. V_100 = V_101 ,
. V_102 = V_103 ,
. V_104 = 0 ,
. V_105 = V_106 ,
}
} ;
const T_3 V_112 = F_25 ( V_111 ) ;
struct V_113 V_114 ;
int V_115 = 0 ;
switch ( V_2 -> V_13 ) {
case V_34 :
case V_35 :
case V_50 :
case V_54 :
case V_33 :
case V_64 :
case V_65 :
case V_66 :
case V_67 :
case V_92 :
case V_93 :
break;
case V_63 :
V_115 = F_26 ( V_2 ) ;
if ( V_115 )
break;
V_2 -> V_116 = F_27 ( V_2 , V_117 ) ;
F_28 ( V_2 -> V_118 , V_119 , V_120 ,
V_112 , V_111 ) ;
break;
case V_77 :
case V_78 :
V_115 = F_26 ( V_2 ) ;
if ( V_115 )
break;
V_2 -> V_116 = F_27 ( V_2 , V_117 ) ;
F_28 ( V_2 -> V_118 , V_119 , V_120 ,
V_110 , V_97 ) ;
F_28 ( V_2 -> V_116 , V_121 , V_122 , & V_114 ) ;
V_114 . V_123 = false ;
V_114 . V_124 = false ;
V_114 . V_125 = true ;
F_28 ( V_2 -> V_116 , V_121 , V_126 , & V_114 ) ;
V_114 . V_124 = true ;
F_28 ( V_2 -> V_116 , V_121 , V_126 , & V_114 ) ;
break;
case V_127 :
case V_128 :
case V_73 :
case V_20 :
case V_21 :
case V_83 :
case V_87 :
case V_88 :
case V_89 :
case V_90 :
case V_84 :
case V_85 :
if ( ! V_129 )
break;
V_2 -> V_116 = F_27 ( V_2 , V_130 ) ;
if ( V_2 -> V_116 == NULL ) {
V_115 = - V_131 ;
break;
}
F_28 ( V_2 -> V_118 , V_119 , V_120 ,
V_112 , V_111 ) ;
break;
case V_49 :
if ( ! V_129 )
break;
V_2 -> V_116 = F_27 ( V_2 , V_130 ) ;
if ( V_2 -> V_116 == NULL ) {
V_115 = - V_131 ;
break;
}
F_28 ( V_2 -> V_118 , V_119 , V_120 ,
V_110 , V_97 ) ;
break;
case V_43 :
case V_44 :
F_29 ( L_17 ) ;
break;
}
return V_115 ;
}
void F_30 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_13 ) {
case V_63 :
case V_77 :
case V_78 :
F_31 ( V_2 , V_132 ) ;
F_32 ( V_2 ) ;
V_2 -> V_116 = NULL ;
break;
case V_127 :
case V_128 :
case V_49 :
case V_73 :
case V_20 :
case V_21 :
case V_83 :
case V_87 :
case V_88 :
case V_89 :
case V_90 :
case V_84 :
case V_85 :
F_31 ( V_2 , V_133 ) ;
V_2 -> V_116 = NULL ;
break;
}
}
static int F_33 ( void * V_134 , int V_135 , int V_136 , int V_137 )
{
int V_138 ;
int V_139 = 0 ;
struct V_1 * V_2 = (struct V_1 * ) V_134 ;
V_138 = ( ( F_34 ( V_22 ) ) & ( ~ 0x00000002 ) ) ;
V_138 |= ( V_135 ? 0x00020002 : 0x00020000 ) ;
F_23 ( V_22 , V_138 ) ;
V_138 = ( ( F_34 ( V_60 ) ) & ( ~ 0x0000a000 ) ) ;
V_138 |= ( V_136 ? 0x00008000 : 0 ) ;
F_23 ( V_60 , V_138 ) ;
if ( V_137 )
V_139 = ( V_138 & 0x00004000 ) ? 1 : 0 ;
F_23 ( V_60 , V_138 | 0x00002000 ) ;
F_35 ( 1 ) ;
F_23 ( V_60 , V_138 ) ;
return V_139 ;
}
void F_36 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_13 ) {
case V_63 :
case V_77 :
case V_78 :
if ( V_2 -> V_116 )
F_37 ( V_2 , V_132 ) ;
break;
case V_127 :
case V_128 :
case V_49 :
case V_73 :
case V_20 :
case V_21 :
case V_83 :
case V_87 :
case V_88 :
case V_89 :
case V_90 :
case V_84 :
case V_85 :
if ( V_2 -> V_116 )
F_37 ( V_2 , V_133 ) ;
break;
}
}
void F_38 ( struct V_1 * V_2 )
{
struct V_27 * V_140 = & V_2 -> V_140 ;
struct V_27 * V_141 = & V_2 -> V_141 ;
static T_1 V_142 [ 256 ] ;
if ( V_2 -> V_16 [ 0 ] . V_143 == 0 ) {
V_2 -> V_16 [ 0 ] . V_17 . V_144 = 0xa0 >> 1 ;
F_39 ( & V_2 -> V_16 [ 0 ] . V_17 ,
V_142 , sizeof( V_142 ) ) ;
}
switch ( V_2 -> V_13 ) {
case V_49 :
if ( V_2 -> V_16 [ 0 ] . V_143 == 0 ) {
if ( V_142 [ 0x80 ] != 0x84 )
F_4 ( V_2 , V_142 + 0xc0 ) ;
else
F_4 ( V_2 , V_142 + 0x80 ) ;
}
break;
case V_34 :
case V_35 :
case V_33 :
if ( V_2 -> V_16 [ 0 ] . V_143 == 0 )
F_4 ( V_2 , V_142 + 0x80 ) ;
break;
case V_50 :
case V_145 :
case V_54 :
case V_55 :
case V_63 :
case V_64 :
case V_65 :
case V_66 :
case V_67 :
case V_77 :
case V_78 :
case V_80 :
case V_81 :
case V_146 :
case V_91 :
case V_92 :
case V_93 :
if ( V_2 -> V_16 [ 0 ] . V_143 == 0 )
F_4 ( V_2 , V_142 + 0xc0 ) ;
break;
case V_94 :
case V_95 :
V_2 -> V_16 [ 1 ] . V_17 . V_144 = 0xa0 >> 1 ;
F_39 ( & V_2 -> V_16 [ 1 ] . V_17 ,
V_142 , sizeof( V_142 ) ) ;
if ( V_2 -> V_16 [ 0 ] . V_143 == 0 )
F_3 ( V_2 , V_142 ) ;
break;
}
switch ( V_2 -> V_13 ) {
case V_48 :
V_140 -> V_147 = 0x4 ;
V_140 -> V_148 = 0x1 ;
V_140 -> V_149 = V_150 ;
V_141 -> V_147 = 0x10e ;
V_141 -> V_148 = 0x1 ;
V_141 -> V_149 = V_150 ;
break;
case V_42 :
case V_43 :
case V_44 :
V_141 -> V_147 = 0xc ;
V_141 -> V_148 = 0x1 ;
V_141 -> V_149 = V_150 ;
case V_151 :
V_140 -> V_147 = 0xc ;
V_140 -> V_148 = 0x1 ;
V_140 -> V_149 = V_150 ;
break;
case V_77 :
case V_50 :
V_140 -> V_147 = 0x10e ;
V_140 -> V_148 = 0x1 ;
V_140 -> V_149 = V_150 ;
V_140 -> V_152 = 0x2000 ;
V_140 -> V_153 = ( 0x47 << 16 | 188 << 4 | 0xc ) ;
F_23 ( 0x130184 , 0xc ) ;
V_141 -> V_147 = 0xc ;
V_141 -> V_148 = 0x1 ;
V_141 -> V_149 = V_150 ;
break;
case V_56 :
V_140 -> V_147 = 0x4 ;
V_140 -> V_148 = 0x1 ;
V_140 -> V_149 = V_150 ;
break;
case V_128 :
case V_154 :
case V_155 :
case V_57 :
case V_87 :
case V_88 :
case V_89 :
case V_90 :
V_140 -> V_147 = 0x5 ;
V_140 -> V_148 = 0x1 ;
V_140 -> V_149 = V_150 ;
break;
case V_61 :
case V_47 :
case V_127 :
V_140 -> V_147 = 0xc ;
V_140 -> V_148 = 0x1 ;
V_140 -> V_149 = V_150 ;
V_141 -> V_147 = 0xc ;
V_141 -> V_148 = 0x1 ;
V_141 -> V_149 = V_150 ;
break;
case V_20 :
case V_21 :
V_140 -> V_147 = 0xc ;
V_140 -> V_148 = 0x1 ;
V_140 -> V_149 = V_150 ;
V_141 -> V_147 = 0xc ;
V_141 -> V_148 = 0x1 ;
V_141 -> V_149 = V_150 ;
F_7 ( V_2 ) ;
break;
case V_71 :
case V_72 :
case V_73 :
V_140 -> V_147 = 0x5 ;
V_140 -> V_148 = 0x1 ;
V_140 -> V_149 = V_150 ;
break;
case V_76 :
V_140 -> V_147 = 0x5 ;
V_140 -> V_148 = 0x1 ;
V_140 -> V_149 = V_150 ;
V_141 -> V_147 = 0xc ;
V_141 -> V_148 = 0x1 ;
V_141 -> V_149 = V_150 ;
break;
case V_80 :
V_140 -> V_147 = 0xc ;
V_140 -> V_148 = 0x1 ;
V_140 -> V_149 = V_150 ;
V_141 -> V_147 = 0xc ;
V_141 -> V_148 = 0x1 ;
V_141 -> V_149 = V_150 ;
break;
case V_81 :
V_140 -> V_147 = 0xc ;
V_140 -> V_148 = 0x1 ;
V_140 -> V_149 = V_150 ;
break;
case V_83 :
case V_85 :
V_140 -> V_147 = 0x5 ;
V_140 -> V_148 = 0x1 ;
V_140 -> V_149 = V_150 ;
V_141 -> V_147 = 0x8 ;
V_141 -> V_148 = 0x1 ;
V_141 -> V_149 = V_150 ;
break;
case V_84 :
V_140 -> V_147 = 0x5 ;
V_140 -> V_148 = 0x1 ;
V_140 -> V_149 = V_150 ;
V_141 -> V_147 = 0xe ;
V_141 -> V_148 = 0x1 ;
V_141 -> V_149 = V_150 ;
break;
case V_91 :
V_140 -> V_147 = 0x5 ;
V_140 -> V_148 = 0x1 ;
V_140 -> V_149 = V_150 ;
V_141 -> V_147 = 0xc ;
V_141 -> V_148 = 0x1 ;
V_141 -> V_149 = V_150 ;
break;
case V_92 :
case V_93 :
V_140 -> V_147 = 0xc ;
V_140 -> V_148 = 0x1 ;
V_140 -> V_149 = V_150 ;
V_141 -> V_147 = 0xc ;
V_141 -> V_148 = 0x1 ;
V_141 -> V_149 = V_150 ;
break;
case V_49 :
case V_34 :
case V_35 :
case V_145 :
case V_54 :
case V_55 :
case V_33 :
case V_146 :
case V_36 :
case V_37 :
case V_38 :
case V_39 :
case V_63 :
case V_64 :
case V_65 :
case V_66 :
case V_67 :
case V_40 :
case V_78 :
case V_46 :
default:
V_141 -> V_147 = 0xc ;
V_141 -> V_148 = 0x1 ;
V_141 -> V_149 = V_150 ;
}
switch ( V_2 -> V_13 ) {
case V_128 :
if ( ! V_129 )
break;
case V_49 :
case V_50 :
case V_146 :
case V_145 :
case V_55 :
case V_36 :
case V_37 :
case V_38 :
case V_39 :
case V_61 :
case V_47 :
case V_40 :
case V_65 :
case V_66 :
case V_63 :
case V_77 :
case V_71 :
case V_72 :
case V_78 :
case V_41 :
case V_46 :
case V_34 :
case V_156 :
case V_73 :
case V_127 :
case V_48 :
case V_20 :
case V_21 :
case V_83 :
case V_87 :
case V_88 :
case V_89 :
case V_90 :
case V_84 :
case V_85 :
case V_94 :
case V_95 :
V_2 -> V_118 = F_40 ( & V_2 -> V_157 ,
& V_2 -> V_16 [ 2 ] . V_158 ,
L_18 , 0x88 >> 1 , NULL ) ;
if ( V_2 -> V_118 ) {
V_2 -> V_118 -> V_159 = V_130 ;
F_28 ( V_2 -> V_118 , V_119 , V_160 ) ;
}
break;
}
switch ( V_2 -> V_13 ) {
case V_94 :
F_40 ( & V_2 -> V_157 ,
& V_2 -> V_16 [ 0 ] . V_158 ,
L_19 , 0x82 >> 1 , NULL ) ;
break;
case V_95 :
F_40 ( & V_2 -> V_157 ,
& V_2 -> V_16 [ 0 ] . V_158 ,
L_19 , 0x80 >> 1 , NULL ) ;
F_40 ( & V_2 -> V_157 ,
& V_2 -> V_16 [ 0 ] . V_158 ,
L_19 , 0x82 >> 1 , NULL ) ;
break;
}
switch ( V_2 -> V_13 ) {
case V_61 :
F_41 ( V_2 ) ;
break;
case V_47 : {
int V_115 ;
const struct V_161 * V_162 ;
const char * V_163 = L_20 ;
char * V_164 = L_21 ;
static struct V_165 V_166 ;
struct V_167 V_168 = {
. V_2 = V_2 ,
. V_164 = V_164 ,
. V_169 = F_33 ,
} ;
F_41 ( V_2 ) ;
F_42 ( & V_2 -> V_16 [ 0 ] . V_158 , & V_166 ) ;
if ( V_170 )
V_166 . V_171 = V_170 ;
switch ( V_166 . V_171 ) {
case 0x4 :
V_163 = L_22 ;
break;
default:
V_163 = L_20 ;
break;
}
F_2 ( L_23 ,
V_166 . V_171 , V_163 ) ;
V_115 = F_43 ( & V_162 , V_163 , & V_2 -> V_4 -> V_2 ) ;
if ( V_115 != 0 )
F_12 ( L_24 ,
V_163 ) ;
else
F_44 ( & V_168 , V_162 ) ;
F_45 ( V_162 ) ;
break;
}
}
}
