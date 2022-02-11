static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
const struct V_7 * V_8 )
{
int V_9 = F_2 ( V_4 -> V_10 ) -> V_11 ;
const struct V_7 * V_12 ;
int V_13 ;
for ( V_12 = V_8 -> V_14 ; V_12 -> V_15 >= 0 ; ++ V_12 ) {
V_4 = F_3 ( V_2 -> V_16 , V_12 -> V_15 ) ;
if ( ! V_4 )
continue;
if ( V_12 -> V_15 != V_9 &&
F_4 ( V_4 ) )
continue;
V_13 = F_5 ( V_2 , V_4 , V_6 , V_12 ) ;
if ( V_13 < 0 )
return V_13 ;
}
for ( V_12 = V_8 -> V_14 ; V_12 -> V_15 >= 0 ; ++ V_12 ) {
V_4 = F_3 ( V_2 -> V_16 , V_12 -> V_15 ) ;
if ( ! V_4 )
continue;
if ( V_12 -> V_15 != V_9 &&
! F_4 ( V_4 ) )
F_6 ( V_6 , V_4 , ( void * ) - 1L ) ;
}
return 0 ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
const struct V_7 * V_12 )
{
return 0 ;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
const struct V_7 * V_12 )
{
V_2 -> V_17 = 1 ;
return 1 ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_3 * V_18 ,
struct V_5 * V_6 ,
const struct V_7 * V_12 )
{
return F_10 ( V_2 -> V_19 , V_18 , & V_2 -> V_20 , V_12 ) ;
}
static int F_11 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
const struct V_7 * V_12 )
{
struct V_21 * V_22 ;
struct V_23 * V_24 ;
int V_13 ;
if ( V_2 -> V_25 == F_12 ( 0x1686 , 0x00dd ) )
V_2 -> V_26 = 1 ;
V_22 = & V_4 -> V_10 [ 0 ] ;
V_24 = F_2 ( V_22 ) ;
V_13 = F_13 ( V_2 , V_24 -> V_11 ) ;
if ( V_13 < 0 ) {
F_14 ( V_2 , L_1 ,
V_24 -> V_11 , V_13 ) ;
return V_13 ;
}
F_15 ( V_2 -> V_16 , V_24 -> V_11 , 0 ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
const struct V_7 * V_12 )
{
struct V_27 * V_28 ;
struct V_21 * V_22 ;
struct V_23 * V_24 ;
int V_29 , V_13 ;
unsigned * V_30 = NULL ;
V_28 = F_17 ( V_12 -> V_14 , sizeof( * V_28 ) , V_31 ) ;
if ( ! V_28 ) {
F_14 ( V_2 , L_2 ) ;
return - V_32 ;
}
F_18 ( & V_28 -> V_33 ) ;
if ( V_28 -> V_34 > V_35 ) {
F_19 ( V_28 ) ;
return - V_36 ;
}
if ( V_28 -> V_34 > 0 ) {
V_30 = F_17 ( V_28 -> V_30 ,
sizeof( int ) * V_28 -> V_34 , V_31 ) ;
if ( ! V_30 ) {
F_19 ( V_28 ) ;
return - V_32 ;
}
V_28 -> V_30 = V_30 ;
}
V_29 = ( V_28 -> V_37 & V_38 )
? V_39 : V_40 ;
V_13 = F_20 ( V_2 , V_29 , V_28 ) ;
if ( V_13 < 0 )
goto error;
if ( V_28 -> V_4 != F_2 ( & V_4 -> V_10 [ 0 ] ) -> V_11 ||
V_28 -> V_41 >= V_4 -> V_42 ) {
V_13 = - V_36 ;
goto error;
}
V_22 = & V_4 -> V_10 [ V_28 -> V_41 ] ;
V_24 = F_2 ( V_22 ) ;
if ( V_24 -> V_43 < 1 ) {
V_13 = - V_36 ;
goto error;
}
V_28 -> V_44 = V_24 -> V_45 ;
if ( V_28 -> V_46 == 0 )
V_28 -> V_46 = F_21 ( V_2 , V_22 ) ;
if ( V_28 -> V_47 == 0 )
V_28 -> V_47 = F_22 ( F_23 ( V_22 , 0 ) -> V_48 ) ;
F_15 ( V_2 -> V_16 , V_28 -> V_4 , 0 ) ;
F_24 ( V_2 , V_28 -> V_4 , V_22 , V_28 ) ;
F_25 ( V_2 , V_28 -> V_4 , V_22 , V_28 , V_28 -> V_49 ) ;
return 0 ;
error:
F_26 ( & V_28 -> V_33 ) ;
F_19 ( V_28 ) ;
F_19 ( V_30 ) ;
return V_13 ;
}
static int F_27 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_21 * V_22 ;
struct V_23 * V_24 ;
struct V_50 * V_51 ;
struct V_52 * V_53 ;
struct V_54 * V_55 ;
if ( V_4 -> V_42 < 2 )
return - V_56 ;
V_22 = & V_4 -> V_10 [ 1 ] ;
V_24 = F_2 ( V_22 ) ;
if ( V_24 -> V_43 < 1 )
return - V_56 ;
V_51 = F_23 ( V_22 , 0 ) ;
if ( ! F_28 ( V_51 ) )
return - V_56 ;
V_53 = F_29 ( V_22 -> V_57 , V_22 -> V_58 , NULL ,
V_59 ) ;
V_55 = F_29 ( V_22 -> V_57 , V_22 -> V_58 , NULL ,
V_60 ) ;
if ( ! V_53 || V_53 -> V_61 < 7 ||
! V_55 || V_55 -> V_61 < 8 )
return - V_56 ;
return F_11 ( V_2 , V_4 , V_6 , NULL ) ;
}
static int F_30 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
struct V_21 * V_22 )
{
static const struct V_7 V_62 = {
. type = V_63
} ;
struct V_64 * V_65 ;
struct V_66 * V_67 ;
V_65 = F_29 ( V_22 -> V_57 , V_22 -> V_58 ,
NULL , V_68 ) ;
V_67 = F_29 ( V_22 -> V_57 , V_22 -> V_58 ,
NULL , V_69 ) ;
if ( ! V_65 && ! V_67 )
return - V_56 ;
if ( V_65 && ( V_65 -> V_61 < 5 ||
( V_65 -> V_70 != V_71 &&
V_65 -> V_70 != V_72 ) ) )
return - V_56 ;
if ( V_67 && ( V_67 -> V_61 < 6 ||
( V_67 -> V_70 != V_71 &&
V_67 -> V_70 != V_72 ) ) )
return - V_56 ;
return F_9 ( V_2 , V_4 , V_6 , & V_62 ) ;
}
static int F_31 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
struct V_21 * V_22 )
{
static const struct V_7 V_73 = {
. type = V_74
} ;
T_1 * V_75 = NULL ;
for (; ; ) {
V_75 = F_29 ( V_22 -> V_57 ,
V_22 -> V_58 ,
V_75 , 0xf1 ) ;
if ( ! V_75 )
return - V_56 ;
if ( V_75 [ 0 ] < 6 || V_75 [ 3 ] != 2 )
continue;
return F_9 ( V_2 , V_4 , V_6 ,
& V_73 ) ;
}
}
static int F_32 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
struct V_21 * V_22 )
{
struct V_76 * V_77 ;
struct V_78 * V_79 ;
V_77 = (struct V_76 * ) V_22 -> V_57 ;
if ( V_22 -> V_58 < 7 ||
V_77 -> V_61 < 7 ||
V_77 -> V_80 != V_81 ||
V_77 -> V_82 != V_83 )
return - V_56 ;
V_79 = (struct V_78 * ) V_22 -> V_37 [ 0 ] . V_57 ;
if ( V_22 -> V_37 [ 0 ] . V_58 < 4 ||
V_79 -> V_61 < 4 ||
V_79 -> V_80 != V_84 ||
V_79 -> V_82 != V_85 ||
V_79 -> V_86 < 1 ||
V_79 -> V_86 > 16 )
return - V_56 ;
return F_9 ( V_2 , V_4 , V_6 , NULL ) ;
}
static int F_33 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_21 * V_22 ;
struct V_23 * V_24 ;
struct V_50 * V_51 ;
int V_13 ;
V_22 = & V_4 -> V_10 [ 0 ] ;
V_24 = F_2 ( V_22 ) ;
if ( V_24 -> V_43 < 1 )
return - V_56 ;
V_51 = F_23 ( V_22 , 0 ) ;
if ( ! F_34 ( V_51 ) &&
! F_35 ( V_51 ) )
return - V_56 ;
switch ( F_36 ( V_2 -> V_25 ) ) {
case 0x0499 :
V_13 = F_30 ( V_2 , V_4 , V_6 , V_22 ) ;
if ( V_13 != - V_56 )
return V_13 ;
break;
case 0x0582 :
V_13 = F_31 ( V_2 , V_4 , V_6 , V_22 ) ;
if ( V_13 != - V_56 )
return V_13 ;
break;
}
return F_32 ( V_2 , V_4 , V_6 , V_22 ) ;
}
static int F_37 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
int V_13 ;
V_13 = F_27 ( V_2 , V_4 , V_6 ) ;
if ( V_13 == - V_56 )
V_13 = F_33 ( V_2 , V_4 , V_6 ) ;
return V_13 ;
}
static int F_38 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
const struct V_7 * V_12 )
{
int V_9 = F_2 ( V_4 -> V_10 ) -> V_11 ;
int V_87 , V_15 , V_13 ;
V_13 = F_37 ( V_2 , V_4 , V_6 ) ;
if ( V_13 < 0 )
return V_13 ;
V_87 = V_2 -> V_16 -> V_88 -> V_89 . V_90 ;
for ( V_15 = 0 ; V_15 < V_87 ; V_15 ++ ) {
if ( V_15 == V_9 || V_12 -> V_15 >= 0 )
continue;
V_4 = F_3 ( V_2 -> V_16 , V_15 ) ;
if ( ! V_4 ||
F_4 ( V_4 ) ||
F_2 ( V_4 -> V_10 ) -> V_91 !=
V_92 )
continue;
V_13 = F_37 ( V_2 , V_4 , V_6 ) ;
if ( V_13 >= 0 )
F_6 ( V_6 , V_4 , ( void * ) - 1L ) ;
}
return 0 ;
}
static int F_39 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
const struct V_7 * V_12 )
{
static const struct V_27 V_93 = {
. V_94 = V_95 ,
. V_96 = 2 ,
. V_97 = V_98 ,
. V_10 = 1 ,
. V_41 = 1 ,
. V_99 = V_100 ,
} ;
struct V_21 * V_22 ;
struct V_23 * V_24 ;
struct V_27 * V_28 ;
int V_29 , V_13 ;
if ( V_4 -> V_42 < 2 )
return - V_101 ;
V_22 = & V_4 -> V_10 [ 1 ] ;
V_24 = F_2 ( V_22 ) ;
if ( V_24 -> V_43 == 2 ) {
static const struct V_102 V_103 = {
. V_104 = 0x0003 ,
. V_105 = 0x0003
} ;
static const struct V_7 V_106 = {
. type = V_107 ,
. V_14 = & V_103
} ;
static const struct V_102 V_108 = {
. V_104 = 0x0001 ,
. V_105 = 0x0001
} ;
static const struct V_7 V_109 = {
. type = V_107 ,
. V_14 = & V_108
} ;
const struct V_7 * V_12 =
V_2 -> V_25 == F_12 ( 0x0582 , 0x002b )
? & V_106 : & V_109 ;
return F_40 ( V_2 -> V_19 , V_4 ,
& V_2 -> V_20 , V_12 ,
V_2 -> V_25 ) ;
}
if ( V_24 -> V_43 != 1 )
return - V_101 ;
V_28 = F_17 ( & V_93 , sizeof( * V_28 ) , V_31 ) ;
if ( ! V_28 )
return - V_32 ;
V_28 -> V_4 = V_24 -> V_11 ;
V_28 -> V_37 = F_23 ( V_22 , 0 ) -> V_110 ;
V_28 -> V_111 = F_23 ( V_22 , 0 ) -> V_112 ;
V_28 -> V_46 = 0 ;
V_28 -> V_47 = F_22 ( F_23 ( V_22 , 0 ) -> V_48 ) ;
F_18 ( & V_28 -> V_33 ) ;
switch ( V_28 -> V_47 ) {
case 0x120 :
V_28 -> V_49 = V_28 -> V_113 = 44100 ;
break;
case 0x138 :
case 0x140 :
V_28 -> V_49 = V_28 -> V_113 = 48000 ;
break;
case 0x258 :
case 0x260 :
V_28 -> V_49 = V_28 -> V_113 = 96000 ;
break;
default:
F_14 ( V_2 , L_3 ) ;
F_19 ( V_28 ) ;
return - V_101 ;
}
V_29 = ( V_28 -> V_37 & V_38 )
? V_39 : V_40 ;
V_13 = F_20 ( V_2 , V_29 , V_28 ) ;
if ( V_13 < 0 ) {
F_26 ( & V_28 -> V_33 ) ;
F_19 ( V_28 ) ;
return V_13 ;
}
F_15 ( V_2 -> V_16 , V_28 -> V_4 , 0 ) ;
return 0 ;
}
static int F_41 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
const struct V_7 * V_12 )
{
if ( V_12 -> V_15 < 0 )
return 0 ;
return F_42 ( V_2 , V_12 -> V_15 , 0 ) ;
}
int F_5 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
const struct V_7 * V_12 )
{
typedef int (* F_43)( struct V_1 * ,
struct V_3 * ,
struct V_5 * ,
const struct V_7 * );
static const F_43 V_114 [] = {
[ V_115 ] = F_7 ,
[ V_116 ] = F_1 ,
[ V_117 ] = F_38 ,
[ V_118 ] = F_9 ,
[ V_107 ] = F_9 ,
[ V_63 ] = F_9 ,
[ V_74 ] = F_9 ,
[ V_119 ] = F_9 ,
[ V_120 ] = F_9 ,
[ V_121 ] = F_9 ,
[ V_122 ] = F_9 ,
[ V_123 ] = F_9 ,
[ V_124 ] = F_9 ,
[ V_125 ] = F_9 ,
[ V_126 ] = F_9 ,
[ V_127 ] = F_11 ,
[ V_128 ] = F_16 ,
[ V_129 ] = F_39 ,
[ V_130 ] = F_8 ,
[ V_131 ] = F_41 ,
} ;
if ( V_12 -> type < V_132 ) {
return V_114 [ V_12 -> type ] ( V_2 , V_4 , V_6 , V_12 ) ;
} else {
F_14 ( V_2 , L_4 , V_12 -> type ) ;
return - V_101 ;
}
}
static int F_44 ( struct V_133 * V_16 , struct V_3 * V_18 )
{
struct V_134 * V_135 = V_16 -> V_88 ;
int V_13 ;
if ( F_22 ( F_45 ( V_135 ) -> V_136 ) == V_137 ||
F_22 ( F_45 ( V_135 ) -> V_136 ) == V_138 ) {
F_46 ( & V_16 -> V_16 , L_5 ) ;
V_13 = F_47 ( V_16 , F_48 ( V_16 , 0 ) ,
0x10 , 0x43 , 0x0001 , 0x000a , NULL , 0 ) ;
if ( V_13 < 0 )
F_46 ( & V_16 -> V_16 , L_6 , V_13 ) ;
V_13 = F_49 ( V_16 , V_139 , 0 ,
& V_16 -> V_140 , sizeof( V_16 -> V_140 ) ) ;
V_135 = V_16 -> V_88 ;
if ( V_13 < 0 )
F_46 ( & V_16 -> V_16 , L_7 , V_13 ) ;
V_13 = F_50 ( V_16 ) ;
if ( V_13 < 0 )
F_46 ( & V_16 -> V_16 , L_8 , V_13 ) ;
F_46 ( & V_16 -> V_16 , L_9 ,
F_22 ( F_45 ( V_135 ) -> V_136 ) ) ;
return - V_56 ;
}
return 0 ;
}
static int F_51 ( struct V_133 * V_16 )
{
T_1 V_141 = 1 ;
F_47 ( V_16 , F_52 ( V_16 , 0 ) , 0x2a ,
V_38 | V_142 | V_143 ,
0 , 0 , & V_141 , 1 ) ;
if ( V_141 == 0 ) {
F_47 ( V_16 , F_48 ( V_16 , 0 ) , 0x29 ,
V_144 | V_142 | V_143 ,
1 , 2000 , NULL , 0 ) ;
return - V_56 ;
}
return 0 ;
}
static int F_53 ( struct V_133 * V_16 )
{
int V_13 ;
if ( V_16 -> V_88 -> V_89 . V_145 == 1 ) {
F_54 ( & V_16 -> V_16 ,
L_10 ) ;
V_13 = F_55 ( V_16 , 2 ) ;
if ( V_13 < 0 )
F_46 ( & V_16 -> V_16 ,
L_11 ,
V_13 ) ;
return - V_56 ;
} else
F_54 ( & V_16 -> V_16 , L_12 ) ;
return 0 ;
}
static int F_56 ( struct V_133 * V_16 , int V_146 , T_2 V_147 )
{
T_1 V_141 [ 4 ] ;
V_141 [ 0 ] = 0x20 ;
V_141 [ 1 ] = V_147 & 0xff ;
V_141 [ 2 ] = ( V_147 >> 8 ) & 0xff ;
V_141 [ 3 ] = V_146 ;
return F_47 ( V_16 , F_48 ( V_16 , 0 ) , V_148 ,
V_144 | V_149 | V_150 ,
0 , 0 , & V_141 , 4 ) ;
}
static int F_57 ( struct V_133 * V_16 )
{
return F_56 ( V_16 , 2 , 0x8004 ) ;
}
static int F_58 ( struct V_133 * V_16 )
{
int V_13 = 0 , V_146 ;
int V_151 [] = { 0x2004 , 0x3000 , 0xf800 , 0x143f , 0x0000 , 0x3000 } ;
for ( V_146 = 0 ; V_146 < F_59 ( V_151 ) ; V_146 ++ ) {
V_13 = F_56 ( V_16 , V_146 , V_151 [ V_146 ] ) ;
if ( V_13 < 0 )
return V_13 ;
}
return V_13 ;
}
static int F_60 ( struct V_133 * V_16 )
{
T_1 V_141 [ 2 ] = { 0x74 , 0xe3 } ;
return F_47 ( V_16 , F_48 ( V_16 , 0 ) , V_152 ,
V_153 | V_149 | V_144 ,
V_154 << 8 , 9 << 8 , V_141 , 2 ) ;
}
static int F_61 ( struct V_133 * V_16 )
{
F_15 ( V_16 , 0 , 1 ) ;
return 0 ;
}
static int F_62 ( struct V_133 * V_16 )
{
int V_13 , V_155 ;
static const T_1 V_156 [] = { 0x4e , 0x73 , 0x52 , 0x01 } ;
void * V_141 = F_17 ( V_156 , F_59 ( V_156 ) , V_31 ) ;
if ( ! V_141 )
return - V_32 ;
V_13 = F_63 ( V_16 , F_64 ( V_16 , 0x05 ) , V_141 ,
F_59 ( V_156 ) , & V_155 , 1000 ) ;
F_19 ( V_141 ) ;
if ( V_13 < 0 )
return V_13 ;
return 0 ;
}
static int F_65 ( struct V_133 * V_16 )
{
int V_157 = F_66 ( V_16 , F_48 ( V_16 , 0 ) ,
0xaf , V_142 | V_158 ,
1 , 0 , NULL , 0 , 1000 ) ;
if ( V_157 < 0 )
return V_157 ;
F_67 ( V_16 ) ;
return - V_159 ;
}
static void F_68 ( struct V_133 * V_16 )
{
T_1 V_160 [ 3 ] ;
T_1 V_161 [ 12 ] ;
V_160 [ 0 ] = 0x80 ;
V_160 [ 1 ] = 0xbb ;
V_160 [ 2 ] = 0x00 ;
F_47 ( V_16 , F_52 ( V_16 , 0 ) ,
0x01 , 0x22 , 0x0100 , 0x0085 , & V_161 , 0x0003 ) ;
F_47 ( V_16 , F_48 ( V_16 , 0 ) ,
0x81 , 0xa2 , 0x0100 , 0x0085 , & V_160 , 0x0003 ) ;
F_47 ( V_16 , F_48 ( V_16 , 0 ) ,
0x81 , 0xa2 , 0x0100 , 0x0086 , & V_160 , 0x0003 ) ;
F_47 ( V_16 , F_48 ( V_16 , 0 ) ,
0x81 , 0xa2 , 0x0100 , 0x0003 , & V_160 , 0x0003 ) ;
return;
}
static int F_69 ( struct V_133 * V_16 )
{
struct V_134 * V_135 = V_16 -> V_88 ;
int V_13 ;
T_1 V_162 [ 0x12 ] ;
int V_163 ;
int V_164 ;
V_163 = F_22 ( F_45 ( V_135 ) -> V_136 ) ;
if ( V_163 != V_165 ) {
F_70 ( & V_16 -> V_16 , L_13 , V_163 ) ;
return - V_56 ;
}
F_46 ( & V_16 -> V_16 , L_14 ) ;
V_164 = 0 ;
V_162 [ 0 ] = V_166 ;
while ( ( V_162 [ 0 ] == V_166 ) && ( V_164 < 10 ) ) {
F_71 ( 500 ) ;
F_47 ( V_16 , F_52 ( V_16 , 0 ) ,
0x85 , 0xc0 , 0x0001 , 0x0000 , & V_162 , 0x0012 ) ;
if ( V_162 [ 0 ] == V_167 )
break;
F_46 ( & V_16 -> V_16 , L_15 ) ;
V_164 ++ ;
}
if ( V_162 [ 0 ] != V_167 ) {
F_70 ( & V_16 -> V_16 , L_16 , V_162 [ 0 ] ) ;
return - V_56 ;
}
F_46 ( & V_16 -> V_16 , L_17 ) ;
V_13 = F_49 ( V_16 , V_139 , 0 ,
& V_16 -> V_140 , sizeof( V_16 -> V_140 ) ) ;
V_135 = V_16 -> V_88 ;
if ( V_13 < 0 )
F_46 ( & V_16 -> V_16 , L_7 , V_13 ) ;
V_13 = F_50 ( V_16 ) ;
if ( V_13 < 0 )
F_46 ( & V_16 -> V_16 , L_8 , V_13 ) ;
F_46 ( & V_16 -> V_16 , L_18 ,
F_22 ( F_45 ( V_135 ) -> V_136 ) ) ;
F_68 ( V_16 ) ;
F_54 ( & V_16 -> V_16 , L_19 ) ;
return 0 ;
}
static int F_72 ( struct V_1 * V_2 ,
int V_4 , int V_168 )
{
F_15 ( V_2 -> V_16 , V_4 , 0 ) ;
if ( V_2 -> V_169 & V_170 ) {
if ( V_2 -> V_169 & V_171 ) {
if ( V_4 != 1 && V_4 != 2 )
return 1 ;
} else {
unsigned int V_172 ;
if ( V_4 == 1 || V_4 == 2 )
return 1 ;
if ( ( V_2 -> V_169 & V_173 ) && V_168 != 1 )
return 1 ;
V_172 = V_2 -> V_169 & V_174 ;
if ( V_172 == V_175 && V_168 != 2 )
return 1 ;
if ( V_172 == V_176 && V_168 != 3 )
return 1 ;
if ( V_172 == V_177 && V_168 != 4 )
return 1 ;
}
}
F_73 ( V_2 ,
L_20 ,
V_168 , V_4 , V_2 -> V_169 ) ;
return 0 ;
}
static int F_74 ( struct V_1 * V_2 ,
int V_4 ,
int V_168 )
{
F_15 ( V_2 -> V_16 , V_4 , 0 ) ;
if ( V_2 -> V_169 & V_170 ) {
unsigned int V_172 ;
if ( ( V_2 -> V_169 & V_178 ) && V_168 != 6 )
return 1 ;
if ( ( V_2 -> V_169 & V_173 ) && V_168 != 1 )
return 1 ;
V_172 = V_2 -> V_169 & V_174 ;
if ( V_172 == V_175 && V_168 != 2 )
return 1 ;
if ( V_172 == V_176 && V_168 != 3 )
return 1 ;
if ( V_172 == V_179 && V_168 != 4 )
return 1 ;
if ( V_172 == V_177 && V_168 != 5 )
return 1 ;
}
return 0 ;
}
static int F_75 ( struct V_1 * V_2 ,
int V_4 , int V_168 )
{
F_15 ( V_2 -> V_16 , V_4 , 0 ) ;
if ( V_2 -> V_169 & ( V_170 | V_180 ) ) {
if ( V_2 -> V_169 & V_173 ) {
if ( V_168 != 3 && V_168 != 6 )
return 1 ;
} else if ( V_2 -> V_169 & V_181 ) {
if ( V_4 == 4 )
return 1 ;
if ( V_168 != 2 && V_168 != 5 )
return 1 ;
} else {
if ( V_4 == 5 )
return 1 ;
if ( V_168 != 2 && V_168 != 5 )
return 1 ;
}
} else {
if ( V_168 != 1 )
return 1 ;
}
F_73 ( V_2 ,
L_20 ,
V_168 , V_4 , V_2 -> V_169 ) ;
return 0 ;
}
int F_76 ( struct V_1 * V_2 ,
int V_4 ,
int V_168 )
{
if ( V_2 -> V_25 == F_12 ( 0x0763 , 0x2003 ) )
return F_74 ( V_2 , V_4 , V_168 ) ;
if ( V_2 -> V_25 == F_12 ( 0x0763 , 0x2001 ) )
return F_72 ( V_2 , V_4 , V_168 ) ;
if ( V_2 -> V_25 == F_12 ( 0x0763 , 0x2012 ) )
return F_75 ( V_2 , V_4 , V_168 ) ;
return 0 ;
}
int F_77 ( struct V_133 * V_16 ,
struct V_3 * V_18 ,
const struct V_7 * V_12 ,
unsigned int V_182 )
{
switch ( V_182 ) {
case F_12 ( 0x041e , 0x3000 ) :
return F_44 ( V_16 , V_18 ) ;
case F_12 ( 0x041e , 0x3020 ) :
return F_51 ( V_16 ) ;
case F_12 ( 0x10f5 , 0x0200 ) :
return F_57 ( V_16 ) ;
case F_12 ( 0x0d8c , 0x0102 ) :
case F_12 ( 0x0ccd , 0x00b1 ) :
return F_58 ( V_16 ) ;
case F_12 ( 0x0dba , 0x3000 ) :
return F_69 ( V_16 ) ;
case F_12 ( 0x1235 , 0x0010 ) :
case F_12 ( 0x1235 , 0x0018 ) :
return F_61 ( V_16 ) ;
case F_12 ( 0x133e , 0x0815 ) :
return F_62 ( V_16 ) ;
case F_12 ( 0x17cc , 0x1000 ) :
case F_12 ( 0x17cc , 0x1010 ) :
case F_12 ( 0x17cc , 0x1020 ) :
return F_65 ( V_16 ) ;
case F_12 ( 0x0763 , 0x2012 ) :
return F_53 ( V_16 ) ;
case F_12 ( 0x047f , 0xc010 ) :
return F_60 ( V_16 ) ;
}
return 0 ;
}
int F_78 ( struct V_1 * V_2 , struct V_27 * V_28 )
{
switch ( V_2 -> V_25 ) {
case F_12 ( 0x0763 , 0x2001 ) :
if ( V_28 -> V_10 == 2 || V_28 -> V_10 == 3 ||
V_28 -> V_10 == 5 || V_28 -> V_10 == 6 )
return 1 ;
break;
case F_12 ( 0x0763 , 0x2003 ) :
if ( V_2 -> V_169 == 0x00 ||
V_28 -> V_10 == 1 || V_28 -> V_10 == 2 ||
V_28 -> V_10 == 3 )
return 1 ;
break;
case F_12 ( 0x0763 , 0x2012 ) :
if ( V_28 -> V_10 == 2 || V_28 -> V_10 == 3 ||
V_28 -> V_10 == 5 || V_28 -> V_10 == 6 )
return 1 ;
break;
}
return 0 ;
}
static void F_79 ( struct V_183 * V_184 ,
struct V_27 * V_185 )
{
unsigned char V_186 = 0 ;
if ( V_184 -> V_187 == V_40 ) {
if ( V_184 -> V_29 -> V_188 [ V_39 ] . V_189 != - 1 )
return;
}
switch ( V_185 -> V_113 ) {
case 48000 :
V_186 = V_190 ;
break;
case 88200 :
V_186 = V_191 ;
break;
case 96000 :
V_186 = V_192 ;
break;
case 176400 :
V_186 = V_193 ;
break;
case 192000 :
V_186 = V_194 ;
break;
default:
V_186 = V_195 ;
break;
}
F_80 ( V_184 -> V_29 -> V_2 , V_186 ) ;
V_184 -> V_196 = ( V_186 >= V_193 ) ? 4 : 0 ;
}
void F_81 ( struct V_183 * V_184 ,
struct V_27 * V_185 )
{
switch ( V_184 -> V_29 -> V_2 -> V_25 ) {
case F_12 ( 0x041e , 0x3f02 ) :
case F_12 ( 0x041e , 0x3f04 ) :
case F_12 ( 0x041e , 0x3f0a ) :
case F_12 ( 0x041e , 0x3f19 ) :
F_79 ( V_184 , V_185 ) ;
break;
}
}
bool F_82 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_25 ) {
case F_12 ( 0x041E , 0x4080 ) :
case F_12 ( 0x045E , 0x075D ) :
case F_12 ( 0x045E , 0x076D ) :
case F_12 ( 0x045E , 0x076E ) :
case F_12 ( 0x045E , 0x076F ) :
case F_12 ( 0x045E , 0x0772 ) :
case F_12 ( 0x045E , 0x0779 ) :
case F_12 ( 0x047F , 0x02F7 ) :
case F_12 ( 0x047F , 0x0415 ) :
case F_12 ( 0x047F , 0xAA05 ) :
case F_12 ( 0x04D8 , 0xFEEA ) :
case F_12 ( 0x0556 , 0x0014 ) :
case F_12 ( 0x05A3 , 0x9420 ) :
case F_12 ( 0x074D , 0x3553 ) :
case F_12 ( 0x1395 , 0x740a ) :
case F_12 ( 0x1901 , 0x0191 ) :
case F_12 ( 0x1de7 , 0x0013 ) :
case F_12 ( 0x1de7 , 0x0014 ) :
case F_12 ( 0x1de7 , 0x0114 ) :
case F_12 ( 0x21B4 , 0x0081 ) :
return true ;
}
return false ;
}
static bool F_83 ( unsigned int V_182 )
{
switch ( V_182 ) {
case F_12 ( 0x154e , 0x1003 ) :
case F_12 ( 0x154e , 0x3005 ) :
case F_12 ( 0x154e , 0x3006 ) :
return true ;
}
return false ;
}
static bool F_84 ( unsigned int V_182 )
{
switch ( V_182 ) {
case F_12 ( 0x0644 , 0x8043 ) :
return true ;
}
return false ;
}
int F_85 ( struct V_183 * V_184 ,
struct V_27 * V_185 )
{
struct V_133 * V_16 = V_184 -> V_16 ;
int V_13 ;
if ( F_83 ( V_184 -> V_29 -> V_2 -> V_25 ) ) {
V_13 = F_15 ( V_16 , V_185 -> V_4 , 0 ) ;
if ( V_13 < 0 )
return V_13 ;
F_86 ( 20 ) ;
switch ( V_185 -> V_10 ) {
case 2 :
case 1 :
V_13 = F_47 ( V_16 , F_48 ( V_16 , 0 ) , 0 ,
V_144 | V_142 | V_153 ,
V_185 -> V_10 - 1 , 1 , NULL , 0 ) ;
if ( V_13 < 0 )
return V_13 ;
break;
}
F_86 ( 20 ) ;
} else if ( F_84 ( V_184 -> V_29 -> V_2 -> V_25 ) ) {
switch ( V_185 -> V_10 ) {
case 3 :
V_13 = F_47 ( V_16 , F_48 ( V_16 , 0 ) , 0 ,
V_144 | V_142 | V_153 ,
1 , 1 , NULL , 0 ) ;
if ( V_13 < 0 )
return V_13 ;
break;
case 2 :
case 1 :
V_13 = F_47 ( V_16 , F_48 ( V_16 , 0 ) , 0 ,
V_144 | V_142 | V_153 ,
0 , 1 , NULL , 0 ) ;
if ( V_13 < 0 )
return V_13 ;
break;
}
}
return 0 ;
}
void F_87 ( struct V_197 * V_198 )
{
if ( F_36 ( V_198 -> V_2 -> V_25 ) == 0x23ba &&
V_198 -> type == V_199 )
V_198 -> V_200 = 4 ;
if ( ( V_198 -> V_2 -> V_25 == F_12 ( 0x0763 , 0x2030 ) ||
V_198 -> V_2 -> V_25 == F_12 ( 0x0763 , 0x2031 ) ) &&
V_198 -> type == V_201 )
V_198 -> V_200 = 16 ;
if ( ( V_198 -> V_2 -> V_25 == F_12 ( 0x0644 , 0x8038 ) ||
V_198 -> V_2 -> V_25 == F_12 ( 0x1852 , 0x5034 ) ) &&
V_198 -> V_202 == 4 )
V_198 -> V_203 = 1 ;
}
void F_88 ( struct V_133 * V_16 )
{
struct V_1 * V_2 = F_89 ( & V_16 -> V_16 ) ;
if ( ! V_2 )
return;
switch ( F_36 ( V_2 -> V_25 ) ) {
case 0x23ba :
case 0x0644 :
F_86 ( 50 ) ;
break;
}
}
void F_90 ( struct V_133 * V_16 , unsigned int V_204 ,
T_3 V_205 , T_3 V_206 , T_4 V_147 ,
T_4 V_207 , void * V_14 , T_4 V_208 )
{
struct V_1 * V_2 = F_89 ( & V_16 -> V_16 ) ;
if ( ! V_2 )
return;
if ( F_36 ( V_2 -> V_25 ) == 0x23ba &&
( V_206 & V_209 ) == V_149 )
F_86 ( 20 ) ;
if ( F_36 ( V_2 -> V_25 ) == 0x0644 &&
( V_206 & V_209 ) == V_149 )
F_86 ( 20 ) ;
if ( F_83 ( V_2 -> V_25 )
&& ( V_206 & V_209 ) == V_149 )
F_86 ( 20 ) ;
if ( ( V_2 -> V_25 == F_12 ( 0x1686 , 0x00dd ) ||
V_2 -> V_25 == F_12 ( 0x046d , 0x0a46 ) ||
V_2 -> V_25 == F_12 ( 0x0b0e , 0x0349 ) ) &&
( V_206 & V_209 ) == V_149 )
F_86 ( 1 ) ;
}
T_5 F_91 ( struct V_1 * V_2 ,
struct V_27 * V_28 ,
unsigned int V_210 )
{
if ( F_36 ( V_2 -> V_25 ) == 0x23ba ) {
switch ( V_28 -> V_10 ) {
case 1 :
V_28 -> V_211 = true ;
return V_212 ;
case 2 :
V_28 -> V_213 = true ;
return V_214 ;
case 3 :
V_28 -> V_213 = true ;
return V_212 ;
}
}
switch ( V_2 -> V_25 ) {
case F_12 ( 0x20b1 , 0x3008 ) :
case F_12 ( 0x20b1 , 0x2008 ) :
case F_12 ( 0x20b1 , 0x300a ) :
case F_12 ( 0x22d9 , 0x0416 ) :
if ( V_28 -> V_10 == 2 )
return V_215 ;
break;
case F_12 ( 0x20b1 , 0x000a ) :
case F_12 ( 0x20b1 , 0x2009 ) :
case F_12 ( 0x20b1 , 0x2023 ) :
case F_12 ( 0x20b1 , 0x3023 ) :
case F_12 ( 0x2616 , 0x0106 ) :
if ( V_28 -> V_10 == 3 )
return V_215 ;
break;
case F_12 ( 0x16d0 , 0x071a ) :
if ( V_28 -> V_10 == 2 ) {
switch ( F_22 ( V_2 -> V_16 -> V_140 . V_216 ) ) {
case 0x199 :
return V_217 ;
case 0x19b :
return V_215 ;
default:
break;
}
}
break;
case F_12 ( 0x16d0 , 0x0a23 ) :
if ( V_28 -> V_10 == 2 )
return V_215 ;
break;
default:
break;
}
if ( F_83 ( V_2 -> V_25 ) ) {
if ( V_28 -> V_10 == 2 )
return V_215 ;
}
if ( F_84 ( V_2 -> V_25 ) ) {
if ( V_28 -> V_10 == 3 )
return V_215 ;
}
return 0 ;
}
