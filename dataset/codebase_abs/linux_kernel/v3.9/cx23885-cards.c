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
int F_5 ( void * V_18 , int V_19 , int V_20 , int V_21 )
{
struct V_22 * V_23 = V_18 ;
struct V_1 * V_2 = V_23 -> V_2 ;
T_2 V_24 = 0 ;
if ( ( V_20 == V_25 ) || ( V_20 == V_26 ) )
return 0 ;
if ( V_20 != 0 ) {
F_2 ( V_27 L_15 ,
V_28 , V_20 ) ;
return - V_29 ;
}
switch ( V_2 -> V_30 ) {
case V_31 :
case V_32 :
case V_33 :
case V_34 :
case V_35 :
case V_36 :
case V_37 :
case V_38 :
V_24 = 0x04 ;
break;
case V_39 :
case V_40 :
if ( V_23 -> V_41 == 1 )
V_24 = 0x01 ;
else if ( V_23 -> V_41 == 2 )
V_24 = 0x04 ;
break;
case V_42 :
V_24 = 0x02 ;
break;
case V_43 :
F_6 ( V_2 , V_23 -> V_41 ) ;
break;
case V_44 :
V_24 = 1 << 2 ;
break;
}
if ( V_24 ) {
F_7 ( V_45 , V_24 ) ;
F_8 ( 200 ) ;
F_9 ( V_45 , V_24 ) ;
}
return 0 ;
}
void F_10 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_30 ) {
case V_46 :
F_9 ( V_45 , 0x00010001 ) ;
break;
case V_32 :
F_9 ( V_45 , 0x00050000 ) ;
F_7 ( V_45 , 0x00000005 ) ;
F_11 ( 5 ) ;
F_9 ( V_45 , 0x00050005 ) ;
break;
case V_33 :
F_9 ( V_45 , 0x00050005 ) ;
break;
case V_47 :
F_12 ( V_2 , V_48 | V_49 , 1 ) ;
F_13 ( V_2 , V_48 | V_49 ) ;
F_8 ( 100 ) ;
F_14 ( V_2 , V_48 | V_49 ) ;
F_8 ( 100 ) ;
F_15 ( V_2 , V_50 , 1 ) ;
F_16 ( V_2 , V_50 ) ;
F_8 ( 20 ) ;
F_17 ( V_2 , V_50 ) ;
F_8 ( 20 ) ;
F_16 ( V_2 , V_50 ) ;
F_8 ( 20 ) ;
break;
case V_51 :
F_9 ( V_45 , 0x00050000 ) ;
F_8 ( 20 ) ;
F_7 ( V_45 , 0x00000005 ) ;
F_8 ( 20 ) ;
F_9 ( V_45 , 0x00050005 ) ;
break;
case V_52 :
F_9 ( V_45 , 0x00050000 ) ;
F_8 ( 20 ) ;
F_7 ( V_45 , 0x00000005 ) ;
F_8 ( 20 ) ;
F_9 ( V_45 , 0x00050005 ) ;
break;
case V_31 :
F_9 ( V_45 , 0x00050000 ) ;
F_8 ( 20 ) ;
F_7 ( V_45 , 0x00000005 ) ;
F_8 ( 20 ) ;
F_9 ( V_45 , 0x00050005 ) ;
break;
case V_39 :
F_9 ( V_45 , 0x000f0000 ) ;
F_8 ( 20 ) ;
F_7 ( V_45 , 0x0000000f ) ;
F_8 ( 20 ) ;
F_9 ( V_45 , 0x000f000f ) ;
break;
case V_40 :
F_9 ( V_45 , 0x000f0000 ) ;
F_8 ( 20 ) ;
F_7 ( V_45 , 0x0000000f ) ;
F_8 ( 20 ) ;
F_9 ( V_45 , 0x000f000f ) ;
break;
case V_34 :
case V_35 :
case V_36 :
case V_37 :
case V_38 :
F_9 ( V_45 , 0x00040000 ) ;
F_8 ( 20 ) ;
F_7 ( V_45 , 0x00000004 ) ;
F_8 ( 20 ) ;
F_9 ( V_45 , 0x00040004 ) ;
break;
case V_53 :
case V_54 :
F_18 ( V_55 , 0x00000036 ) ;
F_18 ( V_56 , 0x00001000 ) ;
F_9 ( V_57 , 0x00000002 ) ;
F_8 ( 200 ) ;
F_7 ( V_57 , 0x00000800 ) ;
F_8 ( 200 ) ;
F_9 ( V_57 , 0x00000800 ) ;
F_8 ( 200 ) ;
break;
case V_58 :
F_9 ( V_45 , 0x00040000 ) ;
F_7 ( V_45 , 0x00030004 ) ;
F_8 ( 100 ) ;
F_9 ( V_45 , 0x00040004 ) ;
F_18 ( V_55 , 0x00000037 ) ;
F_18 ( V_56 , 0x00001000 ) ;
F_18 ( V_57 , 0x0000c300 ) ;
F_18 ( V_59 , 0x00000000 ) ;
break;
case V_60 :
case V_61 :
case V_62 :
case V_63 :
case V_64 :
F_15 ( V_2 , V_65 | V_66 | V_67 , 1 ) ;
F_16 ( V_2 , V_65 | V_66 | V_67 ) ;
F_17 ( V_2 , V_65 ) ;
F_8 ( 20 ) ;
F_16 ( V_2 , V_65 ) ;
break;
case V_68 :
case V_69 :
case V_70 :
F_15 ( V_2 , V_71 | V_72 | V_50 , 1 ) ;
F_17 ( V_2 , V_72 | V_50 ) ;
F_8 ( 100 ) ;
F_16 ( V_2 , V_71 | V_72 | V_50 ) ;
F_8 ( 100 ) ;
break;
case V_73 :
F_15 ( V_2 , V_71 | V_72 , 1 ) ;
F_17 ( V_2 , V_71 | V_72 ) ;
F_8 ( 100 ) ;
F_16 ( V_2 , V_71 | V_72 ) ;
F_8 ( 100 ) ;
break;
case V_74 :
case V_75 :
F_12 ( V_2 , V_49 | V_76 , 1 ) ;
F_13 ( V_2 , V_49 | V_76 ) ;
F_8 ( 100 ) ;
F_14 ( V_2 , V_49 ) ;
F_8 ( 100 ) ;
break;
case V_42 :
F_9 ( V_45 , 0x00010001 ) ;
break;
case V_43 :
F_9 ( V_45 , 0x00060000 ) ;
F_7 ( V_45 , 0x00010006 ) ;
F_8 ( 100 ) ;
F_9 ( V_45 , 0x00000004 ) ;
F_18 ( V_55 , 0x00000037 ) ;
F_18 ( V_56 , 0x00005000 ) ;
F_18 ( V_57 , 0x00000d00 ) ;
F_18 ( V_59 , 0x00000000 ) ;
break;
case V_77 :
F_15 ( V_2 , V_78 , 1 ) ;
F_17 ( V_2 , V_78 ) ;
F_8 ( 100 ) ;
F_16 ( V_2 , V_78 ) ;
F_8 ( 100 ) ;
break;
case V_44 :
F_7 ( V_55 , 1 ) ;
F_9 ( V_45 , 0x00070000 ) ;
F_8 ( 10 ) ;
F_9 ( V_45 , 0x00010001 ) ;
F_8 ( 10 ) ;
F_7 ( V_45 , 0x00010001 ) ;
F_8 ( 10 ) ;
F_9 ( V_45 , 0x00010001 ) ;
F_8 ( 10 ) ;
F_7 ( V_45 , 0x00030003 ) ;
F_8 ( 10 ) ;
F_9 ( V_45 , 0x00020002 ) ;
F_8 ( 10 ) ;
F_9 ( V_45 , 0x00010001 ) ;
F_8 ( 10 ) ;
F_7 ( V_45 , 0x00020002 ) ;
F_9 ( V_45 , 0x00040004 ) ;
F_7 ( V_45 , 0x00040004 ) ;
F_9 ( V_45 , 0x00040004 ) ;
F_8 ( 60 ) ;
break;
}
}
int F_19 ( struct V_1 * V_2 )
{
static struct V_79 V_80 [] = {
{
. V_81 = V_82 ,
. V_83 = V_84 ,
. V_85 = V_86 ,
. V_87 = 0 ,
. V_88 = V_89 ,
} , {
. V_81 = V_90 ,
. V_83 = V_91 ,
. V_85 = V_92 ,
. V_87 = 0 ,
. V_88 = V_89 ,
}
} ;
const T_3 V_93 = F_20 ( V_80 ) ;
static struct V_79 V_94 [] = {
{
. V_81 = V_82 ,
. V_83 = V_84 ,
. V_85 = V_86 ,
. V_87 = 0 ,
. V_88 = V_89 ,
}
} ;
const T_3 V_95 = F_20 ( V_94 ) ;
struct V_96 V_97 ;
int V_98 = 0 ;
switch ( V_2 -> V_30 ) {
case V_32 :
case V_33 :
case V_47 :
case V_51 :
case V_31 :
case V_61 :
case V_62 :
case V_63 :
case V_64 :
break;
case V_60 :
V_98 = F_21 ( V_2 ) ;
if ( V_98 )
break;
V_2 -> V_99 = F_22 ( V_2 , V_100 ) ;
F_23 ( V_2 -> V_101 , V_102 , V_103 ,
V_95 , V_94 ) ;
break;
case V_74 :
case V_75 :
V_98 = F_21 ( V_2 ) ;
if ( V_98 )
break;
V_2 -> V_99 = F_22 ( V_2 , V_100 ) ;
F_23 ( V_2 -> V_101 , V_102 , V_103 ,
V_93 , V_80 ) ;
F_23 ( V_2 -> V_99 , V_104 , V_105 , & V_97 ) ;
V_97 . V_106 = false ;
V_97 . V_107 = false ;
V_97 . V_108 = true ;
F_23 ( V_2 -> V_99 , V_104 , V_109 , & V_97 ) ;
V_97 . V_107 = true ;
F_23 ( V_2 -> V_99 , V_104 , V_109 , & V_97 ) ;
break;
case V_110 :
case V_111 :
case V_70 :
if ( ! V_112 )
break;
V_2 -> V_99 = F_22 ( V_2 , V_113 ) ;
if ( V_2 -> V_99 == NULL ) {
V_98 = - V_114 ;
break;
}
F_23 ( V_2 -> V_101 , V_102 , V_103 ,
V_95 , V_94 ) ;
break;
case V_46 :
if ( ! V_112 )
break;
V_2 -> V_99 = F_22 ( V_2 , V_113 ) ;
if ( V_2 -> V_99 == NULL ) {
V_98 = - V_114 ;
break;
}
F_23 ( V_2 -> V_101 , V_102 , V_103 ,
V_93 , V_80 ) ;
break;
case V_40 :
F_24 ( L_16 ) ;
break;
}
return V_98 ;
}
void F_25 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_30 ) {
case V_60 :
case V_74 :
case V_75 :
F_26 ( V_2 , V_115 ) ;
F_27 ( V_2 ) ;
V_2 -> V_99 = NULL ;
break;
case V_110 :
case V_111 :
case V_46 :
case V_70 :
F_26 ( V_2 , V_116 ) ;
V_2 -> V_99 = NULL ;
break;
}
}
static int F_28 ( void * V_117 , int V_118 , int V_119 , int V_120 )
{
int V_121 ;
int V_122 = 0 ;
struct V_1 * V_2 = (struct V_1 * ) V_117 ;
V_121 = ( ( F_29 ( V_45 ) ) & ( ~ 0x00000002 ) ) ;
V_121 |= ( V_118 ? 0x00020002 : 0x00020000 ) ;
F_18 ( V_45 , V_121 ) ;
V_121 = ( ( F_29 ( V_57 ) ) & ( ~ 0x0000a000 ) ) ;
V_121 |= ( V_119 ? 0x00008000 : 0 ) ;
F_18 ( V_57 , V_121 ) ;
if ( V_120 )
V_122 = ( V_121 & 0x00004000 ) ? 1 : 0 ;
F_18 ( V_57 , V_121 | 0x00002000 ) ;
F_30 ( 1 ) ;
F_18 ( V_57 , V_121 ) ;
return V_122 ;
}
void F_31 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_30 ) {
case V_60 :
case V_74 :
case V_75 :
if ( V_2 -> V_99 )
F_32 ( V_2 , V_115 ) ;
break;
case V_110 :
case V_111 :
case V_46 :
case V_70 :
if ( V_2 -> V_99 )
F_32 ( V_2 , V_116 ) ;
break;
}
}
void F_33 ( struct V_1 * V_2 )
{
struct V_22 * V_123 = & V_2 -> V_123 ;
struct V_22 * V_124 = & V_2 -> V_124 ;
static T_1 V_125 [ 256 ] ;
if ( V_2 -> V_14 [ 0 ] . V_126 == 0 ) {
V_2 -> V_14 [ 0 ] . V_15 . V_127 = 0xa0 >> 1 ;
F_34 ( & V_2 -> V_14 [ 0 ] . V_15 ,
V_125 , sizeof( V_125 ) ) ;
}
switch ( V_2 -> V_30 ) {
case V_46 :
if ( V_2 -> V_14 [ 0 ] . V_126 == 0 ) {
if ( V_125 [ 0x80 ] != 0x84 )
F_3 ( V_2 , V_125 + 0xc0 ) ;
else
F_3 ( V_2 , V_125 + 0x80 ) ;
}
break;
case V_32 :
case V_33 :
case V_31 :
if ( V_2 -> V_14 [ 0 ] . V_126 == 0 )
F_3 ( V_2 , V_125 + 0x80 ) ;
break;
case V_47 :
case V_128 :
case V_51 :
case V_52 :
case V_60 :
case V_61 :
case V_62 :
case V_63 :
case V_64 :
case V_74 :
case V_75 :
case V_77 :
if ( V_2 -> V_14 [ 0 ] . V_126 == 0 )
F_3 ( V_2 , V_125 + 0xc0 ) ;
break;
}
switch ( V_2 -> V_30 ) {
case V_44 :
V_123 -> V_129 = 0x4 ;
V_123 -> V_130 = 0x1 ;
V_123 -> V_131 = V_132 ;
V_124 -> V_129 = 0x10e ;
V_124 -> V_130 = 0x1 ;
V_124 -> V_131 = V_132 ;
break;
case V_39 :
case V_40 :
V_124 -> V_129 = 0xc ;
V_124 -> V_130 = 0x1 ;
V_124 -> V_131 = V_132 ;
case V_133 :
V_123 -> V_129 = 0xc ;
V_123 -> V_130 = 0x1 ;
V_123 -> V_131 = V_132 ;
break;
case V_74 :
case V_47 :
V_123 -> V_129 = 0x10e ;
V_123 -> V_130 = 0x1 ;
V_123 -> V_131 = V_132 ;
V_123 -> V_134 = 0x2000 ;
V_123 -> V_135 = ( 0x47 << 16 | 188 << 4 | 0xc ) ;
F_18 ( 0x130184 , 0xc ) ;
V_124 -> V_129 = 0xc ;
V_124 -> V_130 = 0x1 ;
V_124 -> V_131 = V_132 ;
break;
case V_53 :
V_123 -> V_129 = 0x4 ;
V_123 -> V_130 = 0x1 ;
V_123 -> V_131 = V_132 ;
break;
case V_111 :
case V_136 :
case V_137 :
case V_54 :
V_123 -> V_129 = 0x5 ;
V_123 -> V_130 = 0x1 ;
V_123 -> V_131 = V_132 ;
break;
case V_58 :
case V_43 :
case V_110 :
V_123 -> V_129 = 0xc ;
V_123 -> V_130 = 0x1 ;
V_123 -> V_131 = V_132 ;
V_124 -> V_129 = 0xc ;
V_124 -> V_130 = 0x1 ;
V_124 -> V_131 = V_132 ;
break;
case V_68 :
case V_69 :
V_123 -> V_129 = 0x5 ;
V_123 -> V_130 = 0x1 ;
V_123 -> V_131 = V_132 ;
break;
case V_73 :
V_123 -> V_129 = 0x5 ;
V_123 -> V_130 = 0x1 ;
V_123 -> V_131 = V_132 ;
V_124 -> V_129 = 0xc ;
V_124 -> V_130 = 0x1 ;
V_124 -> V_131 = V_132 ;
break;
case V_77 :
V_123 -> V_129 = 0xc ;
V_123 -> V_130 = 0x1 ;
V_123 -> V_131 = V_132 ;
break;
case V_46 :
case V_32 :
case V_33 :
case V_128 :
case V_51 :
case V_52 :
case V_31 :
case V_34 :
case V_35 :
case V_36 :
case V_60 :
case V_61 :
case V_62 :
case V_63 :
case V_64 :
case V_37 :
case V_75 :
case V_42 :
default:
V_124 -> V_129 = 0xc ;
V_124 -> V_130 = 0x1 ;
V_124 -> V_131 = V_132 ;
}
switch ( V_2 -> V_30 ) {
case V_111 :
if ( ! V_112 )
break;
case V_46 :
case V_47 :
case V_128 :
case V_52 :
case V_34 :
case V_35 :
case V_36 :
case V_58 :
case V_43 :
case V_37 :
case V_62 :
case V_63 :
case V_60 :
case V_74 :
case V_68 :
case V_69 :
case V_75 :
case V_38 :
case V_42 :
case V_32 :
case V_138 :
case V_70 :
case V_110 :
case V_44 :
V_2 -> V_101 = F_35 ( & V_2 -> V_139 ,
& V_2 -> V_14 [ 2 ] . V_140 ,
L_17 , 0x88 >> 1 , NULL ) ;
if ( V_2 -> V_101 ) {
V_2 -> V_101 -> V_141 = V_113 ;
F_23 ( V_2 -> V_101 , V_102 , V_142 ) ;
}
break;
}
switch ( V_2 -> V_30 ) {
case V_58 :
F_36 ( V_2 ) ;
break;
case V_43 : {
int V_98 ;
const struct V_143 * V_144 ;
const char * V_145 = L_18 ;
char * V_146 = L_19 ;
static struct V_147 V_148 ;
struct V_149 V_150 = {
. V_2 = V_2 ,
. V_146 = V_146 ,
. V_151 = F_28 ,
} ;
F_36 ( V_2 ) ;
F_37 ( & V_2 -> V_14 [ 0 ] . V_140 , & V_148 ) ;
if ( V_152 )
V_148 . V_153 = V_152 ;
switch ( V_148 . V_153 ) {
case 0x4 :
V_145 = L_20 ;
break;
default:
V_145 = L_18 ;
break;
}
F_2 ( V_7 L_21 ,
V_148 . V_153 , V_145 ) ;
V_98 = F_38 ( & V_144 , V_145 , & V_2 -> V_4 -> V_2 ) ;
if ( V_98 != 0 )
F_2 ( V_27 L_22
L_23
L_24 , V_145 ) ;
else
F_39 ( & V_150 , V_144 ) ;
F_40 ( V_144 ) ;
break;
}
}
}
