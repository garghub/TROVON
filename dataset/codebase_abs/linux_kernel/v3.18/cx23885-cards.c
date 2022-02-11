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
case V_46 :
if ( V_28 -> V_47 == 1 )
V_29 = 0x01 ;
else if ( V_28 -> V_47 == 2 )
V_29 = 0x04 ;
break;
case V_48 :
V_29 = 0x02 ;
break;
case V_49 :
F_10 ( V_2 , V_28 -> V_47 ) ;
break;
case V_50 :
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
case V_51 :
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
case V_52 :
F_14 ( V_2 , V_53 | V_54 , 1 ) ;
F_15 ( V_2 , V_53 | V_54 ) ;
F_11 ( 100 ) ;
F_16 ( V_2 , V_53 | V_54 ) ;
F_11 ( 100 ) ;
F_17 ( V_2 , V_55 , 1 ) ;
F_18 ( V_2 , V_55 ) ;
F_11 ( 20 ) ;
F_19 ( V_2 , V_55 ) ;
F_11 ( 20 ) ;
F_18 ( V_2 , V_55 ) ;
F_11 ( 20 ) ;
break;
case V_56 :
F_6 ( V_22 , 0x00050000 ) ;
F_11 ( 20 ) ;
F_8 ( V_22 , 0x00000005 ) ;
F_11 ( 20 ) ;
F_6 ( V_22 , 0x00050005 ) ;
break;
case V_57 :
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
case V_46 :
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
case V_58 :
case V_20 :
case V_21 :
case V_59 :
F_20 ( V_60 , 0x00000036 ) ;
F_20 ( V_61 , 0x00001000 ) ;
F_6 ( V_62 , 0x00000002 ) ;
F_11 ( 200 ) ;
F_8 ( V_62 , 0x00000800 ) ;
F_11 ( 200 ) ;
F_6 ( V_62 , 0x00000800 ) ;
F_11 ( 200 ) ;
break;
case V_63 :
F_6 ( V_22 , 0x00040000 ) ;
F_8 ( V_22 , 0x00030004 ) ;
F_11 ( 100 ) ;
F_6 ( V_22 , 0x00040004 ) ;
F_20 ( V_60 , 0x00000037 ) ;
F_20 ( V_61 , 0x00001000 ) ;
F_20 ( V_62 , 0x0000c300 ) ;
F_20 ( V_64 , 0x00000000 ) ;
break;
case V_65 :
case V_66 :
case V_67 :
case V_68 :
case V_69 :
F_17 ( V_2 , V_70 | V_71 | V_72 , 1 ) ;
F_18 ( V_2 , V_70 | V_71 | V_72 ) ;
F_19 ( V_2 , V_70 ) ;
F_11 ( 20 ) ;
F_18 ( V_2 , V_70 ) ;
break;
case V_73 :
case V_74 :
case V_75 :
F_17 ( V_2 , V_76 | V_77 | V_55 , 1 ) ;
F_19 ( V_2 , V_77 | V_55 ) ;
F_11 ( 100 ) ;
F_18 ( V_2 , V_76 | V_77 | V_55 ) ;
F_11 ( 100 ) ;
break;
case V_78 :
F_17 ( V_2 , V_76 | V_77 , 1 ) ;
F_19 ( V_2 , V_76 | V_77 ) ;
F_11 ( 100 ) ;
F_18 ( V_2 , V_76 | V_77 ) ;
F_11 ( 100 ) ;
break;
case V_79 :
case V_80 :
F_14 ( V_2 , V_54 | V_81 , 1 ) ;
F_15 ( V_2 , V_54 | V_81 ) ;
F_11 ( 100 ) ;
F_16 ( V_2 , V_54 ) ;
F_11 ( 100 ) ;
break;
case V_48 :
F_6 ( V_22 , 0x00010001 ) ;
break;
case V_49 :
F_6 ( V_22 , 0x00060000 ) ;
F_8 ( V_22 , 0x00010006 ) ;
F_11 ( 100 ) ;
F_6 ( V_22 , 0x00000004 ) ;
F_20 ( V_60 , 0x00000037 ) ;
F_20 ( V_61 , 0x00005000 ) ;
F_20 ( V_62 , 0x00000d00 ) ;
F_20 ( V_64 , 0x00000000 ) ;
break;
case V_82 :
F_17 ( V_2 , V_83 | V_70 , 1 ) ;
F_19 ( V_2 , V_83 | V_70 ) ;
F_11 ( 100 ) ;
F_18 ( V_2 , V_83 | V_70 ) ;
F_11 ( 100 ) ;
break;
case V_50 :
F_8 ( V_60 , 1 ) ;
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
case V_84 :
F_20 ( V_60 , 0x00000037 ) ;
F_17 ( V_2 , V_55 | V_85 , 1 ) ;
F_19 ( V_2 , V_55 | V_85 ) ;
F_11 ( 100 ) ;
F_18 ( V_2 , V_55 | V_85 ) ;
break;
}
}
int F_21 ( struct V_1 * V_2 )
{
static struct V_86 V_87 [] = {
{
. V_88 = V_89 ,
. V_90 = V_91 ,
. V_92 = V_93 ,
. V_94 = 0 ,
. V_95 = V_96 ,
} , {
. V_88 = V_97 ,
. V_90 = V_98 ,
. V_92 = V_99 ,
. V_94 = 0 ,
. V_95 = V_96 ,
}
} ;
const T_3 V_100 = F_22 ( V_87 ) ;
static struct V_86 V_101 [] = {
{
. V_88 = V_89 ,
. V_90 = V_91 ,
. V_92 = V_93 ,
. V_94 = 0 ,
. V_95 = V_96 ,
}
} ;
const T_3 V_102 = F_22 ( V_101 ) ;
struct V_103 V_104 ;
int V_105 = 0 ;
switch ( V_2 -> V_19 ) {
case V_36 :
case V_37 :
case V_52 :
case V_56 :
case V_35 :
case V_66 :
case V_67 :
case V_68 :
case V_69 :
break;
case V_65 :
V_105 = F_23 ( V_2 ) ;
if ( V_105 )
break;
V_2 -> V_106 = F_24 ( V_2 , V_107 ) ;
F_25 ( V_2 -> V_108 , V_109 , V_110 ,
V_102 , V_101 ) ;
break;
case V_79 :
case V_80 :
V_105 = F_23 ( V_2 ) ;
if ( V_105 )
break;
V_2 -> V_106 = F_24 ( V_2 , V_107 ) ;
F_25 ( V_2 -> V_108 , V_109 , V_110 ,
V_100 , V_87 ) ;
F_25 ( V_2 -> V_106 , V_111 , V_112 , & V_104 ) ;
V_104 . V_113 = false ;
V_104 . V_114 = false ;
V_104 . V_115 = true ;
F_25 ( V_2 -> V_106 , V_111 , V_116 , & V_104 ) ;
V_104 . V_114 = true ;
F_25 ( V_2 -> V_106 , V_111 , V_116 , & V_104 ) ;
break;
case V_117 :
case V_118 :
case V_75 :
case V_20 :
case V_21 :
if ( ! V_119 )
break;
V_2 -> V_106 = F_24 ( V_2 , V_120 ) ;
if ( V_2 -> V_106 == NULL ) {
V_105 = - V_121 ;
break;
}
F_25 ( V_2 -> V_108 , V_109 , V_110 ,
V_102 , V_101 ) ;
break;
case V_51 :
if ( ! V_119 )
break;
V_2 -> V_106 = F_24 ( V_2 , V_120 ) ;
if ( V_2 -> V_106 == NULL ) {
V_105 = - V_121 ;
break;
}
F_25 ( V_2 -> V_108 , V_109 , V_110 ,
V_100 , V_87 ) ;
break;
case V_45 :
case V_46 :
F_26 ( L_16 ) ;
break;
}
return V_105 ;
}
void F_27 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_19 ) {
case V_65 :
case V_79 :
case V_80 :
F_28 ( V_2 , V_122 ) ;
F_29 ( V_2 ) ;
V_2 -> V_106 = NULL ;
break;
case V_117 :
case V_118 :
case V_51 :
case V_75 :
case V_20 :
case V_21 :
F_28 ( V_2 , V_123 ) ;
V_2 -> V_106 = NULL ;
break;
}
}
static int F_30 ( void * V_124 , int V_125 , int V_126 , int V_127 )
{
int V_128 ;
int V_129 = 0 ;
struct V_1 * V_2 = (struct V_1 * ) V_124 ;
V_128 = ( ( F_31 ( V_22 ) ) & ( ~ 0x00000002 ) ) ;
V_128 |= ( V_125 ? 0x00020002 : 0x00020000 ) ;
F_20 ( V_22 , V_128 ) ;
V_128 = ( ( F_31 ( V_62 ) ) & ( ~ 0x0000a000 ) ) ;
V_128 |= ( V_126 ? 0x00008000 : 0 ) ;
F_20 ( V_62 , V_128 ) ;
if ( V_127 )
V_129 = ( V_128 & 0x00004000 ) ? 1 : 0 ;
F_20 ( V_62 , V_128 | 0x00002000 ) ;
F_32 ( 1 ) ;
F_20 ( V_62 , V_128 ) ;
return V_129 ;
}
void F_33 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_19 ) {
case V_65 :
case V_79 :
case V_80 :
if ( V_2 -> V_106 )
F_34 ( V_2 , V_122 ) ;
break;
case V_117 :
case V_118 :
case V_51 :
case V_75 :
case V_20 :
case V_21 :
if ( V_2 -> V_106 )
F_34 ( V_2 , V_123 ) ;
break;
}
}
void F_35 ( struct V_1 * V_2 )
{
struct V_27 * V_130 = & V_2 -> V_130 ;
struct V_27 * V_131 = & V_2 -> V_131 ;
static T_1 V_132 [ 256 ] ;
if ( V_2 -> V_14 [ 0 ] . V_133 == 0 ) {
V_2 -> V_14 [ 0 ] . V_15 . V_134 = 0xa0 >> 1 ;
F_36 ( & V_2 -> V_14 [ 0 ] . V_15 ,
V_132 , sizeof( V_132 ) ) ;
}
switch ( V_2 -> V_19 ) {
case V_51 :
if ( V_2 -> V_14 [ 0 ] . V_133 == 0 ) {
if ( V_132 [ 0x80 ] != 0x84 )
F_3 ( V_2 , V_132 + 0xc0 ) ;
else
F_3 ( V_2 , V_132 + 0x80 ) ;
}
break;
case V_36 :
case V_37 :
case V_35 :
if ( V_2 -> V_14 [ 0 ] . V_133 == 0 )
F_3 ( V_2 , V_132 + 0x80 ) ;
break;
case V_52 :
case V_135 :
case V_56 :
case V_57 :
case V_65 :
case V_66 :
case V_67 :
case V_68 :
case V_69 :
case V_79 :
case V_80 :
case V_82 :
case V_136 :
if ( V_2 -> V_14 [ 0 ] . V_133 == 0 )
F_3 ( V_2 , V_132 + 0xc0 ) ;
break;
}
switch ( V_2 -> V_19 ) {
case V_50 :
V_130 -> V_137 = 0x4 ;
V_130 -> V_138 = 0x1 ;
V_130 -> V_139 = V_140 ;
V_131 -> V_137 = 0x10e ;
V_131 -> V_138 = 0x1 ;
V_131 -> V_139 = V_140 ;
break;
case V_44 :
case V_45 :
case V_46 :
V_131 -> V_137 = 0xc ;
V_131 -> V_138 = 0x1 ;
V_131 -> V_139 = V_140 ;
case V_141 :
V_130 -> V_137 = 0xc ;
V_130 -> V_138 = 0x1 ;
V_130 -> V_139 = V_140 ;
break;
case V_79 :
case V_52 :
V_130 -> V_137 = 0x10e ;
V_130 -> V_138 = 0x1 ;
V_130 -> V_139 = V_140 ;
V_130 -> V_142 = 0x2000 ;
V_130 -> V_143 = ( 0x47 << 16 | 188 << 4 | 0xc ) ;
F_20 ( 0x130184 , 0xc ) ;
V_131 -> V_137 = 0xc ;
V_131 -> V_138 = 0x1 ;
V_131 -> V_139 = V_140 ;
break;
case V_58 :
V_130 -> V_137 = 0x4 ;
V_130 -> V_138 = 0x1 ;
V_130 -> V_139 = V_140 ;
break;
case V_118 :
case V_144 :
case V_145 :
case V_59 :
V_130 -> V_137 = 0x5 ;
V_130 -> V_138 = 0x1 ;
V_130 -> V_139 = V_140 ;
break;
case V_63 :
case V_49 :
case V_117 :
V_130 -> V_137 = 0xc ;
V_130 -> V_138 = 0x1 ;
V_130 -> V_139 = V_140 ;
V_131 -> V_137 = 0xc ;
V_131 -> V_138 = 0x1 ;
V_131 -> V_139 = V_140 ;
break;
case V_20 :
case V_21 :
V_130 -> V_137 = 0xc ;
V_130 -> V_138 = 0x1 ;
V_130 -> V_139 = V_140 ;
V_131 -> V_137 = 0xc ;
V_131 -> V_138 = 0x1 ;
V_131 -> V_139 = V_140 ;
F_5 ( V_2 ) ;
break;
case V_73 :
case V_74 :
case V_75 :
V_130 -> V_137 = 0x5 ;
V_130 -> V_138 = 0x1 ;
V_130 -> V_139 = V_140 ;
break;
case V_78 :
V_130 -> V_137 = 0x5 ;
V_130 -> V_138 = 0x1 ;
V_130 -> V_139 = V_140 ;
V_131 -> V_137 = 0xc ;
V_131 -> V_138 = 0x1 ;
V_131 -> V_139 = V_140 ;
break;
case V_82 :
V_130 -> V_137 = 0xc ;
V_130 -> V_138 = 0x1 ;
V_130 -> V_139 = V_140 ;
V_131 -> V_137 = 0xc ;
V_131 -> V_138 = 0x1 ;
V_131 -> V_139 = V_140 ;
break;
case V_84 :
V_130 -> V_137 = 0x5 ;
V_130 -> V_138 = 0x1 ;
V_130 -> V_139 = V_140 ;
V_131 -> V_137 = 0x8 ;
V_131 -> V_138 = 0x1 ;
V_131 -> V_139 = V_140 ;
break;
case V_51 :
case V_36 :
case V_37 :
case V_135 :
case V_56 :
case V_57 :
case V_35 :
case V_136 :
case V_38 :
case V_39 :
case V_40 :
case V_41 :
case V_65 :
case V_66 :
case V_67 :
case V_68 :
case V_69 :
case V_42 :
case V_80 :
case V_48 :
default:
V_131 -> V_137 = 0xc ;
V_131 -> V_138 = 0x1 ;
V_131 -> V_139 = V_140 ;
}
switch ( V_2 -> V_19 ) {
case V_118 :
if ( ! V_119 )
break;
case V_51 :
case V_52 :
case V_136 :
case V_135 :
case V_57 :
case V_38 :
case V_39 :
case V_40 :
case V_41 :
case V_63 :
case V_49 :
case V_42 :
case V_67 :
case V_68 :
case V_65 :
case V_79 :
case V_73 :
case V_74 :
case V_80 :
case V_43 :
case V_48 :
case V_36 :
case V_146 :
case V_75 :
case V_117 :
case V_50 :
case V_20 :
case V_21 :
case V_84 :
V_2 -> V_108 = F_37 ( & V_2 -> V_147 ,
& V_2 -> V_14 [ 2 ] . V_148 ,
L_17 , 0x88 >> 1 , NULL ) ;
if ( V_2 -> V_108 ) {
V_2 -> V_108 -> V_149 = V_120 ;
F_25 ( V_2 -> V_108 , V_109 , V_150 ) ;
}
break;
}
switch ( V_2 -> V_19 ) {
case V_63 :
F_38 ( V_2 ) ;
break;
case V_49 : {
int V_105 ;
const struct V_151 * V_152 ;
const char * V_153 = L_18 ;
char * V_154 = L_19 ;
static struct V_155 V_156 ;
struct V_157 V_158 = {
. V_2 = V_2 ,
. V_154 = V_154 ,
. V_159 = F_30 ,
} ;
F_38 ( V_2 ) ;
F_39 ( & V_2 -> V_14 [ 0 ] . V_148 , & V_156 ) ;
if ( V_160 )
V_156 . V_161 = V_160 ;
switch ( V_156 . V_161 ) {
case 0x4 :
V_153 = L_20 ;
break;
default:
V_153 = L_18 ;
break;
}
F_2 ( V_7 L_21 ,
V_156 . V_161 , V_153 ) ;
V_105 = F_40 ( & V_152 , V_153 , & V_2 -> V_4 -> V_2 ) ;
if ( V_105 != 0 )
F_2 ( V_32 L_22
L_23
L_24 , V_153 ) ;
else
F_41 ( & V_158 , V_152 ) ;
F_42 ( V_152 ) ;
break;
}
}
}
