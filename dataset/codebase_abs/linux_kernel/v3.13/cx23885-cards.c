void F_1 ( struct V_1 * V_2 )
{
int V_3 ;
if ( 0 == V_2 -> V_4 -> V_5 &&
0 == V_2 -> V_4 -> V_6 ) {
F_2 ( V_7
L_1
L_2
L_3
L_4
L_5 ,
V_2 -> V_8 , V_2 -> V_8 , V_2 -> V_8 , V_2 -> V_8 , V_2 -> V_8 ) ;
} else {
F_2 ( V_7
L_6
L_7
L_8
L_9 ,
V_2 -> V_8 , V_2 -> V_8 , V_2 -> V_8 , V_2 -> V_8 ) ;
}
F_2 ( V_7 L_10 ,
V_2 -> V_8 ) ;
for ( V_3 = 0 ; V_3 < V_9 ; V_3 ++ )
F_2 ( V_7 L_11 ,
V_2 -> V_8 , V_3 , V_10 [ V_3 ] . V_8 ) ;
}
static void F_3 ( struct V_1 * V_2 , T_1 * V_11 )
{
struct V_12 V_13 ;
F_4 ( & V_2 -> V_14 [ 0 ] . V_15 , & V_13 ,
V_11 ) ;
switch ( V_13 . V_16 ) {
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
break;
default:
F_2 ( V_17 L_12
L_13 ,
V_2 -> V_8 , V_13 . V_16 ) ;
break;
}
F_2 ( V_7 L_14 ,
V_2 -> V_8 , V_13 . V_16 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
int V_3 ;
const T_1 V_18 [] = {
0xe0 , 0x06 , 0x66 , 0x33 , 0x65 ,
0x01 , 0x17 , 0x06 , 0xde } ;
switch ( V_2 -> V_19 ) {
case V_20 :
case V_21 :
F_6 ( V_22 , 0x00070007 ) ;
F_7 ( 1000 , 10000 ) ;
F_8 ( V_22 , 2 ) ;
F_7 ( 1000 , 10000 ) ;
for ( V_3 = 0 ; V_3 < 9 * 8 ; V_3 ++ ) {
F_8 ( V_22 , 7 ) ;
F_7 ( 1000 , 10000 ) ;
F_6 ( V_22 ,
( ( V_18 [ V_3 >> 3 ] >> ( 7 - ( V_3 & 7 ) ) ) & 1 ) | 4 ) ;
F_7 ( 1000 , 10000 ) ;
}
F_6 ( V_22 , 7 ) ;
break;
}
}
int F_9 ( void * V_23 , int V_24 , int V_25 , int V_26 )
{
struct V_27 * V_28 = V_23 ;
struct V_1 * V_2 = V_28 -> V_2 ;
T_2 V_29 = 0 ;
if ( ( V_25 == V_30 ) || ( V_25 == V_31 ) )
return 0 ;
if ( V_25 != 0 ) {
F_2 ( V_32 L_15 ,
V_33 , V_25 ) ;
return - V_34 ;
}
switch ( V_2 -> V_19 ) {
case V_35 :
case V_36 :
case V_37 :
case V_38 :
case V_39 :
case V_40 :
case V_41 :
case V_42 :
case V_43 :
V_29 = 0x04 ;
break;
case V_44 :
case V_45 :
if ( V_28 -> V_46 == 1 )
V_29 = 0x01 ;
else if ( V_28 -> V_46 == 2 )
V_29 = 0x04 ;
break;
case V_47 :
V_29 = 0x02 ;
break;
case V_48 :
F_10 ( V_2 , V_28 -> V_46 ) ;
break;
case V_49 :
V_29 = 1 << 2 ;
break;
}
if ( V_29 ) {
F_8 ( V_22 , V_29 ) ;
F_11 ( 200 ) ;
F_6 ( V_22 , V_29 ) ;
}
return 0 ;
}
void F_12 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_19 ) {
case V_50 :
F_6 ( V_22 , 0x00010001 ) ;
break;
case V_36 :
F_6 ( V_22 , 0x00050000 ) ;
F_8 ( V_22 , 0x00000005 ) ;
F_13 ( 5 ) ;
F_6 ( V_22 , 0x00050005 ) ;
break;
case V_37 :
F_6 ( V_22 , 0x00050005 ) ;
break;
case V_51 :
F_14 ( V_2 , V_52 | V_53 , 1 ) ;
F_15 ( V_2 , V_52 | V_53 ) ;
F_11 ( 100 ) ;
F_16 ( V_2 , V_52 | V_53 ) ;
F_11 ( 100 ) ;
F_17 ( V_2 , V_54 , 1 ) ;
F_18 ( V_2 , V_54 ) ;
F_11 ( 20 ) ;
F_19 ( V_2 , V_54 ) ;
F_11 ( 20 ) ;
F_18 ( V_2 , V_54 ) ;
F_11 ( 20 ) ;
break;
case V_55 :
F_6 ( V_22 , 0x00050000 ) ;
F_11 ( 20 ) ;
F_8 ( V_22 , 0x00000005 ) ;
F_11 ( 20 ) ;
F_6 ( V_22 , 0x00050005 ) ;
break;
case V_56 :
F_6 ( V_22 , 0x00050000 ) ;
F_11 ( 20 ) ;
F_8 ( V_22 , 0x00000005 ) ;
F_11 ( 20 ) ;
F_6 ( V_22 , 0x00050005 ) ;
break;
case V_35 :
F_6 ( V_22 , 0x00050000 ) ;
F_11 ( 20 ) ;
F_8 ( V_22 , 0x00000005 ) ;
F_11 ( 20 ) ;
F_6 ( V_22 , 0x00050005 ) ;
break;
case V_44 :
F_6 ( V_22 , 0x000f0000 ) ;
F_11 ( 20 ) ;
F_8 ( V_22 , 0x0000000f ) ;
F_11 ( 20 ) ;
F_6 ( V_22 , 0x000f000f ) ;
break;
case V_45 :
F_6 ( V_22 , 0x000f0000 ) ;
F_11 ( 20 ) ;
F_8 ( V_22 , 0x0000000f ) ;
F_11 ( 20 ) ;
F_6 ( V_22 , 0x000f000f ) ;
break;
case V_38 :
case V_39 :
case V_40 :
case V_41 :
case V_42 :
case V_43 :
F_6 ( V_22 , 0x00040000 ) ;
F_11 ( 20 ) ;
F_8 ( V_22 , 0x00000004 ) ;
F_11 ( 20 ) ;
F_6 ( V_22 , 0x00040004 ) ;
break;
case V_57 :
case V_20 :
case V_21 :
case V_58 :
F_20 ( V_59 , 0x00000036 ) ;
F_20 ( V_60 , 0x00001000 ) ;
F_6 ( V_61 , 0x00000002 ) ;
F_11 ( 200 ) ;
F_8 ( V_61 , 0x00000800 ) ;
F_11 ( 200 ) ;
F_6 ( V_61 , 0x00000800 ) ;
F_11 ( 200 ) ;
break;
case V_62 :
F_6 ( V_22 , 0x00040000 ) ;
F_8 ( V_22 , 0x00030004 ) ;
F_11 ( 100 ) ;
F_6 ( V_22 , 0x00040004 ) ;
F_20 ( V_59 , 0x00000037 ) ;
F_20 ( V_60 , 0x00001000 ) ;
F_20 ( V_61 , 0x0000c300 ) ;
F_20 ( V_63 , 0x00000000 ) ;
break;
case V_64 :
case V_65 :
case V_66 :
case V_67 :
case V_68 :
F_17 ( V_2 , V_69 | V_70 | V_71 , 1 ) ;
F_18 ( V_2 , V_69 | V_70 | V_71 ) ;
F_19 ( V_2 , V_69 ) ;
F_11 ( 20 ) ;
F_18 ( V_2 , V_69 ) ;
break;
case V_72 :
case V_73 :
case V_74 :
F_17 ( V_2 , V_75 | V_76 | V_54 , 1 ) ;
F_19 ( V_2 , V_76 | V_54 ) ;
F_11 ( 100 ) ;
F_18 ( V_2 , V_75 | V_76 | V_54 ) ;
F_11 ( 100 ) ;
break;
case V_77 :
F_17 ( V_2 , V_75 | V_76 , 1 ) ;
F_19 ( V_2 , V_75 | V_76 ) ;
F_11 ( 100 ) ;
F_18 ( V_2 , V_75 | V_76 ) ;
F_11 ( 100 ) ;
break;
case V_78 :
case V_79 :
F_14 ( V_2 , V_53 | V_80 , 1 ) ;
F_15 ( V_2 , V_53 | V_80 ) ;
F_11 ( 100 ) ;
F_16 ( V_2 , V_53 ) ;
F_11 ( 100 ) ;
break;
case V_47 :
F_6 ( V_22 , 0x00010001 ) ;
break;
case V_48 :
F_6 ( V_22 , 0x00060000 ) ;
F_8 ( V_22 , 0x00010006 ) ;
F_11 ( 100 ) ;
F_6 ( V_22 , 0x00000004 ) ;
F_20 ( V_59 , 0x00000037 ) ;
F_20 ( V_60 , 0x00005000 ) ;
F_20 ( V_61 , 0x00000d00 ) ;
F_20 ( V_63 , 0x00000000 ) ;
break;
case V_81 :
F_17 ( V_2 , V_82 , 1 ) ;
F_19 ( V_2 , V_82 ) ;
F_11 ( 100 ) ;
F_18 ( V_2 , V_82 ) ;
F_11 ( 100 ) ;
break;
case V_49 :
F_8 ( V_59 , 1 ) ;
F_6 ( V_22 , 0x00070000 ) ;
F_11 ( 10 ) ;
F_6 ( V_22 , 0x00010001 ) ;
F_11 ( 10 ) ;
F_8 ( V_22 , 0x00010001 ) ;
F_11 ( 10 ) ;
F_6 ( V_22 , 0x00010001 ) ;
F_11 ( 10 ) ;
F_8 ( V_22 , 0x00030003 ) ;
F_11 ( 10 ) ;
F_6 ( V_22 , 0x00020002 ) ;
F_11 ( 10 ) ;
F_6 ( V_22 , 0x00010001 ) ;
F_11 ( 10 ) ;
F_8 ( V_22 , 0x00020002 ) ;
F_6 ( V_22 , 0x00040004 ) ;
F_8 ( V_22 , 0x00040004 ) ;
F_6 ( V_22 , 0x00040004 ) ;
F_11 ( 60 ) ;
break;
}
}
int F_21 ( struct V_1 * V_2 )
{
static struct V_83 V_84 [] = {
{
. V_85 = V_86 ,
. V_87 = V_88 ,
. V_89 = V_90 ,
. V_91 = 0 ,
. V_92 = V_93 ,
} , {
. V_85 = V_94 ,
. V_87 = V_95 ,
. V_89 = V_96 ,
. V_91 = 0 ,
. V_92 = V_93 ,
}
} ;
const T_3 V_97 = F_22 ( V_84 ) ;
static struct V_83 V_98 [] = {
{
. V_85 = V_86 ,
. V_87 = V_88 ,
. V_89 = V_90 ,
. V_91 = 0 ,
. V_92 = V_93 ,
}
} ;
const T_3 V_99 = F_22 ( V_98 ) ;
struct V_100 V_101 ;
int V_102 = 0 ;
switch ( V_2 -> V_19 ) {
case V_36 :
case V_37 :
case V_51 :
case V_55 :
case V_35 :
case V_65 :
case V_66 :
case V_67 :
case V_68 :
break;
case V_64 :
V_102 = F_23 ( V_2 ) ;
if ( V_102 )
break;
V_2 -> V_103 = F_24 ( V_2 , V_104 ) ;
F_25 ( V_2 -> V_105 , V_106 , V_107 ,
V_99 , V_98 ) ;
break;
case V_78 :
case V_79 :
V_102 = F_23 ( V_2 ) ;
if ( V_102 )
break;
V_2 -> V_103 = F_24 ( V_2 , V_104 ) ;
F_25 ( V_2 -> V_105 , V_106 , V_107 ,
V_97 , V_84 ) ;
F_25 ( V_2 -> V_103 , V_108 , V_109 , & V_101 ) ;
V_101 . V_110 = false ;
V_101 . V_111 = false ;
V_101 . V_112 = true ;
F_25 ( V_2 -> V_103 , V_108 , V_113 , & V_101 ) ;
V_101 . V_111 = true ;
F_25 ( V_2 -> V_103 , V_108 , V_113 , & V_101 ) ;
break;
case V_114 :
case V_115 :
case V_74 :
case V_20 :
case V_21 :
if ( ! V_116 )
break;
V_2 -> V_103 = F_24 ( V_2 , V_117 ) ;
if ( V_2 -> V_103 == NULL ) {
V_102 = - V_118 ;
break;
}
F_25 ( V_2 -> V_105 , V_106 , V_107 ,
V_99 , V_98 ) ;
break;
case V_50 :
if ( ! V_116 )
break;
V_2 -> V_103 = F_24 ( V_2 , V_117 ) ;
if ( V_2 -> V_103 == NULL ) {
V_102 = - V_118 ;
break;
}
F_25 ( V_2 -> V_105 , V_106 , V_107 ,
V_97 , V_84 ) ;
break;
case V_45 :
F_26 ( L_16 ) ;
break;
}
return V_102 ;
}
void F_27 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_19 ) {
case V_64 :
case V_78 :
case V_79 :
F_28 ( V_2 , V_119 ) ;
F_29 ( V_2 ) ;
V_2 -> V_103 = NULL ;
break;
case V_114 :
case V_115 :
case V_50 :
case V_74 :
case V_20 :
case V_21 :
F_28 ( V_2 , V_120 ) ;
V_2 -> V_103 = NULL ;
break;
}
}
static int F_30 ( void * V_121 , int V_122 , int V_123 , int V_124 )
{
int V_125 ;
int V_126 = 0 ;
struct V_1 * V_2 = (struct V_1 * ) V_121 ;
V_125 = ( ( F_31 ( V_22 ) ) & ( ~ 0x00000002 ) ) ;
V_125 |= ( V_122 ? 0x00020002 : 0x00020000 ) ;
F_20 ( V_22 , V_125 ) ;
V_125 = ( ( F_31 ( V_61 ) ) & ( ~ 0x0000a000 ) ) ;
V_125 |= ( V_123 ? 0x00008000 : 0 ) ;
F_20 ( V_61 , V_125 ) ;
if ( V_124 )
V_126 = ( V_125 & 0x00004000 ) ? 1 : 0 ;
F_20 ( V_61 , V_125 | 0x00002000 ) ;
F_32 ( 1 ) ;
F_20 ( V_61 , V_125 ) ;
return V_126 ;
}
void F_33 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_19 ) {
case V_64 :
case V_78 :
case V_79 :
if ( V_2 -> V_103 )
F_34 ( V_2 , V_119 ) ;
break;
case V_114 :
case V_115 :
case V_50 :
case V_74 :
case V_20 :
case V_21 :
if ( V_2 -> V_103 )
F_34 ( V_2 , V_120 ) ;
break;
}
}
void F_35 ( struct V_1 * V_2 )
{
struct V_27 * V_127 = & V_2 -> V_127 ;
struct V_27 * V_128 = & V_2 -> V_128 ;
static T_1 V_129 [ 256 ] ;
if ( V_2 -> V_14 [ 0 ] . V_130 == 0 ) {
V_2 -> V_14 [ 0 ] . V_15 . V_131 = 0xa0 >> 1 ;
F_36 ( & V_2 -> V_14 [ 0 ] . V_15 ,
V_129 , sizeof( V_129 ) ) ;
}
switch ( V_2 -> V_19 ) {
case V_50 :
if ( V_2 -> V_14 [ 0 ] . V_130 == 0 ) {
if ( V_129 [ 0x80 ] != 0x84 )
F_3 ( V_2 , V_129 + 0xc0 ) ;
else
F_3 ( V_2 , V_129 + 0x80 ) ;
}
break;
case V_36 :
case V_37 :
case V_35 :
if ( V_2 -> V_14 [ 0 ] . V_130 == 0 )
F_3 ( V_2 , V_129 + 0x80 ) ;
break;
case V_51 :
case V_132 :
case V_55 :
case V_56 :
case V_64 :
case V_65 :
case V_66 :
case V_67 :
case V_68 :
case V_78 :
case V_79 :
case V_81 :
if ( V_2 -> V_14 [ 0 ] . V_130 == 0 )
F_3 ( V_2 , V_129 + 0xc0 ) ;
break;
}
switch ( V_2 -> V_19 ) {
case V_49 :
V_127 -> V_133 = 0x4 ;
V_127 -> V_134 = 0x1 ;
V_127 -> V_135 = V_136 ;
V_128 -> V_133 = 0x10e ;
V_128 -> V_134 = 0x1 ;
V_128 -> V_135 = V_136 ;
break;
case V_44 :
case V_45 :
V_128 -> V_133 = 0xc ;
V_128 -> V_134 = 0x1 ;
V_128 -> V_135 = V_136 ;
case V_137 :
V_127 -> V_133 = 0xc ;
V_127 -> V_134 = 0x1 ;
V_127 -> V_135 = V_136 ;
break;
case V_78 :
case V_51 :
V_127 -> V_133 = 0x10e ;
V_127 -> V_134 = 0x1 ;
V_127 -> V_135 = V_136 ;
V_127 -> V_138 = 0x2000 ;
V_127 -> V_139 = ( 0x47 << 16 | 188 << 4 | 0xc ) ;
F_20 ( 0x130184 , 0xc ) ;
V_128 -> V_133 = 0xc ;
V_128 -> V_134 = 0x1 ;
V_128 -> V_135 = V_136 ;
break;
case V_57 :
V_127 -> V_133 = 0x4 ;
V_127 -> V_134 = 0x1 ;
V_127 -> V_135 = V_136 ;
break;
case V_115 :
case V_140 :
case V_141 :
case V_58 :
V_127 -> V_133 = 0x5 ;
V_127 -> V_134 = 0x1 ;
V_127 -> V_135 = V_136 ;
break;
case V_62 :
case V_48 :
case V_114 :
V_127 -> V_133 = 0xc ;
V_127 -> V_134 = 0x1 ;
V_127 -> V_135 = V_136 ;
V_128 -> V_133 = 0xc ;
V_128 -> V_134 = 0x1 ;
V_128 -> V_135 = V_136 ;
break;
case V_20 :
case V_21 :
V_127 -> V_133 = 0xc ;
V_127 -> V_134 = 0x1 ;
V_127 -> V_135 = V_136 ;
V_128 -> V_133 = 0xc ;
V_128 -> V_134 = 0x1 ;
V_128 -> V_135 = V_136 ;
F_5 ( V_2 ) ;
break;
case V_72 :
case V_73 :
case V_74 :
V_127 -> V_133 = 0x5 ;
V_127 -> V_134 = 0x1 ;
V_127 -> V_135 = V_136 ;
break;
case V_77 :
V_127 -> V_133 = 0x5 ;
V_127 -> V_134 = 0x1 ;
V_127 -> V_135 = V_136 ;
V_128 -> V_133 = 0xc ;
V_128 -> V_134 = 0x1 ;
V_128 -> V_135 = V_136 ;
break;
case V_81 :
V_127 -> V_133 = 0xc ;
V_127 -> V_134 = 0x1 ;
V_127 -> V_135 = V_136 ;
break;
case V_50 :
case V_36 :
case V_37 :
case V_132 :
case V_55 :
case V_56 :
case V_35 :
case V_38 :
case V_39 :
case V_40 :
case V_41 :
case V_64 :
case V_65 :
case V_66 :
case V_67 :
case V_68 :
case V_42 :
case V_79 :
case V_47 :
default:
V_128 -> V_133 = 0xc ;
V_128 -> V_134 = 0x1 ;
V_128 -> V_135 = V_136 ;
}
switch ( V_2 -> V_19 ) {
case V_115 :
if ( ! V_116 )
break;
case V_50 :
case V_51 :
case V_132 :
case V_56 :
case V_38 :
case V_39 :
case V_40 :
case V_41 :
case V_62 :
case V_48 :
case V_42 :
case V_66 :
case V_67 :
case V_64 :
case V_78 :
case V_72 :
case V_73 :
case V_79 :
case V_43 :
case V_47 :
case V_36 :
case V_142 :
case V_74 :
case V_114 :
case V_49 :
case V_20 :
case V_21 :
V_2 -> V_105 = F_37 ( & V_2 -> V_143 ,
& V_2 -> V_14 [ 2 ] . V_144 ,
L_17 , 0x88 >> 1 , NULL ) ;
if ( V_2 -> V_105 ) {
V_2 -> V_105 -> V_145 = V_117 ;
F_25 ( V_2 -> V_105 , V_106 , V_146 ) ;
}
break;
}
switch ( V_2 -> V_19 ) {
case V_62 :
F_38 ( V_2 ) ;
break;
case V_48 : {
int V_102 ;
const struct V_147 * V_148 ;
const char * V_149 = L_18 ;
char * V_150 = L_19 ;
static struct V_151 V_152 ;
struct V_153 V_154 = {
. V_2 = V_2 ,
. V_150 = V_150 ,
. V_155 = F_30 ,
} ;
F_38 ( V_2 ) ;
F_39 ( & V_2 -> V_14 [ 0 ] . V_144 , & V_152 ) ;
if ( V_156 )
V_152 . V_157 = V_156 ;
switch ( V_152 . V_157 ) {
case 0x4 :
V_149 = L_20 ;
break;
default:
V_149 = L_18 ;
break;
}
F_2 ( V_7 L_21 ,
V_152 . V_157 , V_149 ) ;
V_102 = F_40 ( & V_148 , V_149 , & V_2 -> V_4 -> V_2 ) ;
if ( V_102 != 0 )
F_2 ( V_32 L_22
L_23
L_24 , V_149 ) ;
else
F_41 ( & V_154 , V_148 ) ;
F_42 ( V_148 ) ;
break;
}
}
}
