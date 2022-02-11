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
}
if ( V_24 ) {
F_7 ( V_44 , V_24 ) ;
F_8 ( 200 ) ;
F_9 ( V_44 , V_24 ) ;
}
return 0 ;
}
void F_10 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_30 ) {
case V_45 :
F_9 ( V_44 , 0x00010001 ) ;
break;
case V_32 :
F_9 ( V_44 , 0x00050000 ) ;
F_7 ( V_44 , 0x00000005 ) ;
F_11 ( 5 ) ;
F_9 ( V_44 , 0x00050005 ) ;
break;
case V_33 :
F_9 ( V_44 , 0x00050005 ) ;
break;
case V_46 :
F_12 ( V_2 , V_47 | V_48 , 1 ) ;
F_13 ( V_2 , V_47 | V_48 ) ;
F_8 ( 100 ) ;
F_14 ( V_2 , V_47 | V_48 ) ;
F_8 ( 100 ) ;
F_15 ( V_2 , V_49 , 1 ) ;
F_16 ( V_2 , V_49 ) ;
F_8 ( 20 ) ;
F_17 ( V_2 , V_49 ) ;
F_8 ( 20 ) ;
F_16 ( V_2 , V_49 ) ;
F_8 ( 20 ) ;
break;
case V_50 :
F_9 ( V_44 , 0x00050000 ) ;
F_8 ( 20 ) ;
F_7 ( V_44 , 0x00000005 ) ;
F_8 ( 20 ) ;
F_9 ( V_44 , 0x00050005 ) ;
break;
case V_51 :
F_9 ( V_44 , 0x00050000 ) ;
F_8 ( 20 ) ;
F_7 ( V_44 , 0x00000005 ) ;
F_8 ( 20 ) ;
F_9 ( V_44 , 0x00050005 ) ;
break;
case V_31 :
F_9 ( V_44 , 0x00050000 ) ;
F_8 ( 20 ) ;
F_7 ( V_44 , 0x00000005 ) ;
F_8 ( 20 ) ;
F_9 ( V_44 , 0x00050005 ) ;
break;
case V_39 :
F_9 ( V_44 , 0x000f0000 ) ;
F_8 ( 20 ) ;
F_7 ( V_44 , 0x0000000f ) ;
F_8 ( 20 ) ;
F_9 ( V_44 , 0x000f000f ) ;
break;
case V_40 :
F_9 ( V_44 , 0x000f0000 ) ;
F_8 ( 20 ) ;
F_7 ( V_44 , 0x0000000f ) ;
F_8 ( 20 ) ;
F_9 ( V_44 , 0x000f000f ) ;
break;
case V_34 :
case V_35 :
case V_36 :
case V_37 :
case V_38 :
F_9 ( V_44 , 0x00040000 ) ;
F_8 ( 20 ) ;
F_7 ( V_44 , 0x00000004 ) ;
F_8 ( 20 ) ;
F_9 ( V_44 , 0x00040004 ) ;
break;
case V_52 :
case V_53 :
F_18 ( V_54 , 0x00000036 ) ;
F_18 ( V_55 , 0x00001000 ) ;
F_9 ( V_56 , 0x00000002 ) ;
F_8 ( 200 ) ;
F_7 ( V_56 , 0x00000800 ) ;
F_8 ( 200 ) ;
F_9 ( V_56 , 0x00000800 ) ;
F_8 ( 200 ) ;
break;
case V_57 :
F_9 ( V_44 , 0x00040000 ) ;
F_7 ( V_44 , 0x00030004 ) ;
F_8 ( 100 ) ;
F_9 ( V_44 , 0x00040004 ) ;
F_18 ( V_54 , 0x00000037 ) ;
F_18 ( V_55 , 0x00001000 ) ;
F_18 ( V_56 , 0x0000c300 ) ;
F_18 ( V_58 , 0x00000000 ) ;
break;
case V_59 :
case V_60 :
case V_61 :
case V_62 :
case V_63 :
F_15 ( V_2 , V_64 | V_65 | V_66 , 1 ) ;
F_16 ( V_2 , V_64 | V_65 | V_66 ) ;
F_17 ( V_2 , V_64 ) ;
F_8 ( 20 ) ;
F_16 ( V_2 , V_64 ) ;
break;
case V_67 :
case V_68 :
case V_69 :
F_15 ( V_2 , V_70 | V_71 | V_49 , 1 ) ;
F_17 ( V_2 , V_71 | V_49 ) ;
F_8 ( 100 ) ;
F_16 ( V_2 , V_70 | V_71 | V_49 ) ;
F_8 ( 100 ) ;
break;
case V_72 :
F_15 ( V_2 , V_70 | V_71 , 1 ) ;
F_17 ( V_2 , V_70 | V_71 ) ;
F_8 ( 100 ) ;
F_16 ( V_2 , V_70 | V_71 ) ;
F_8 ( 100 ) ;
break;
case V_73 :
case V_74 :
F_12 ( V_2 , V_48 | V_75 , 1 ) ;
F_13 ( V_2 , V_48 | V_75 ) ;
F_8 ( 100 ) ;
F_14 ( V_2 , V_48 ) ;
F_8 ( 100 ) ;
break;
case V_42 :
F_9 ( V_44 , 0x00010001 ) ;
break;
case V_43 :
F_9 ( V_44 , 0x00060000 ) ;
F_7 ( V_44 , 0x00010006 ) ;
F_8 ( 100 ) ;
F_9 ( V_44 , 0x00000004 ) ;
F_18 ( V_54 , 0x00000037 ) ;
F_18 ( V_55 , 0x00005000 ) ;
F_18 ( V_56 , 0x00000d00 ) ;
F_18 ( V_58 , 0x00000000 ) ;
break;
}
}
int F_19 ( struct V_1 * V_2 )
{
static struct V_76 V_77 [] = {
{
. V_78 = V_79 ,
. V_80 = V_81 ,
. V_82 = V_83 ,
. V_84 = 0 ,
. V_85 = V_86 ,
} , {
. V_78 = V_87 ,
. V_80 = V_88 ,
. V_82 = V_89 ,
. V_84 = 0 ,
. V_85 = V_86 ,
}
} ;
const T_3 V_90 = F_20 ( V_77 ) ;
static struct V_76 V_91 [] = {
{
. V_78 = V_79 ,
. V_80 = V_81 ,
. V_82 = V_83 ,
. V_84 = 0 ,
. V_85 = V_86 ,
}
} ;
const T_3 V_92 = F_20 ( V_91 ) ;
struct V_93 V_94 ;
int V_95 = 0 ;
switch ( V_2 -> V_30 ) {
case V_32 :
case V_33 :
case V_46 :
case V_50 :
case V_31 :
case V_60 :
case V_61 :
case V_62 :
case V_63 :
break;
case V_59 :
V_95 = F_21 ( V_2 ) ;
if ( V_95 )
break;
V_2 -> V_96 = F_22 ( V_2 , V_97 ) ;
F_23 ( V_2 -> V_98 , V_99 , V_100 ,
V_92 , V_91 ) ;
break;
case V_73 :
case V_74 :
V_95 = F_21 ( V_2 ) ;
if ( V_95 )
break;
V_2 -> V_96 = F_22 ( V_2 , V_97 ) ;
F_23 ( V_2 -> V_98 , V_99 , V_100 ,
V_90 , V_77 ) ;
F_23 ( V_2 -> V_96 , V_101 , V_102 , & V_94 ) ;
V_94 . V_103 = false ;
V_94 . V_104 = false ;
V_94 . V_105 = true ;
F_23 ( V_2 -> V_96 , V_101 , V_106 , & V_94 ) ;
V_94 . V_104 = true ;
F_23 ( V_2 -> V_96 , V_101 , V_106 , & V_94 ) ;
break;
case V_107 :
case V_108 :
if ( ! V_109 )
break;
V_2 -> V_96 = F_22 ( V_2 , V_110 ) ;
if ( V_2 -> V_96 == NULL ) {
V_95 = - V_111 ;
break;
}
F_23 ( V_2 -> V_98 , V_99 , V_100 ,
V_92 , V_91 ) ;
break;
case V_45 :
if ( ! V_109 )
break;
V_2 -> V_96 = F_22 ( V_2 , V_110 ) ;
if ( V_2 -> V_96 == NULL ) {
V_95 = - V_111 ;
break;
}
F_23 ( V_2 -> V_98 , V_99 , V_100 ,
V_90 , V_77 ) ;
break;
case V_40 :
F_24 ( L_16 ) ;
break;
}
return V_95 ;
}
void F_25 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_30 ) {
case V_59 :
case V_73 :
case V_74 :
F_26 ( V_2 , V_112 ) ;
F_27 ( V_2 ) ;
V_2 -> V_96 = NULL ;
break;
case V_107 :
case V_108 :
case V_45 :
F_26 ( V_2 , V_113 ) ;
V_2 -> V_96 = NULL ;
break;
}
}
static int F_28 ( void * V_114 , int V_115 , int V_116 , int V_117 )
{
int V_118 ;
int V_119 = 0 ;
struct V_1 * V_2 = (struct V_1 * ) V_114 ;
V_118 = ( ( F_29 ( V_44 ) ) & ( ~ 0x00000002 ) ) ;
V_118 |= ( V_115 ? 0x00020002 : 0x00020000 ) ;
F_18 ( V_44 , V_118 ) ;
V_118 = ( ( F_29 ( V_56 ) ) & ( ~ 0x0000a000 ) ) ;
V_118 |= ( V_116 ? 0x00008000 : 0 ) ;
F_18 ( V_56 , V_118 ) ;
if ( V_117 )
V_119 = ( V_118 & 0x00004000 ) ? 1 : 0 ;
F_18 ( V_56 , V_118 | 0x00002000 ) ;
F_30 ( 1 ) ;
F_18 ( V_56 , V_118 ) ;
return V_119 ;
}
void F_31 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_30 ) {
case V_59 :
case V_73 :
case V_74 :
if ( V_2 -> V_96 )
F_32 ( V_2 , V_112 ) ;
break;
case V_107 :
case V_108 :
case V_45 :
if ( V_2 -> V_96 )
F_32 ( V_2 , V_113 ) ;
break;
}
}
void F_33 ( struct V_1 * V_2 )
{
struct V_22 * V_120 = & V_2 -> V_120 ;
struct V_22 * V_121 = & V_2 -> V_121 ;
static T_1 V_122 [ 256 ] ;
if ( V_2 -> V_14 [ 0 ] . V_123 == 0 ) {
V_2 -> V_14 [ 0 ] . V_15 . V_124 = 0xa0 >> 1 ;
F_34 ( & V_2 -> V_14 [ 0 ] . V_15 ,
V_122 , sizeof( V_122 ) ) ;
}
switch ( V_2 -> V_30 ) {
case V_45 :
if ( V_2 -> V_14 [ 0 ] . V_123 == 0 ) {
if ( V_122 [ 0x80 ] != 0x84 )
F_3 ( V_2 , V_122 + 0xc0 ) ;
else
F_3 ( V_2 , V_122 + 0x80 ) ;
}
break;
case V_32 :
case V_33 :
case V_31 :
if ( V_2 -> V_14 [ 0 ] . V_123 == 0 )
F_3 ( V_2 , V_122 + 0x80 ) ;
break;
case V_46 :
case V_125 :
case V_50 :
case V_51 :
case V_59 :
case V_60 :
case V_61 :
case V_62 :
case V_63 :
case V_73 :
case V_74 :
if ( V_2 -> V_14 [ 0 ] . V_123 == 0 )
F_3 ( V_2 , V_122 + 0xc0 ) ;
break;
}
switch ( V_2 -> V_30 ) {
case V_39 :
case V_40 :
V_121 -> V_126 = 0xc ;
V_121 -> V_127 = 0x1 ;
V_121 -> V_128 = V_129 ;
case V_130 :
V_120 -> V_126 = 0xc ;
V_120 -> V_127 = 0x1 ;
V_120 -> V_128 = V_129 ;
break;
case V_73 :
case V_46 :
V_120 -> V_126 = 0x10e ;
V_120 -> V_127 = 0x1 ;
V_120 -> V_128 = V_129 ;
V_120 -> V_131 = 0x2000 ;
V_120 -> V_132 = ( 0x47 << 16 | 188 << 4 | 0xc ) ;
F_18 ( 0x130184 , 0xc ) ;
V_121 -> V_126 = 0xc ;
V_121 -> V_127 = 0x1 ;
V_121 -> V_128 = V_129 ;
break;
case V_52 :
V_120 -> V_126 = 0x4 ;
V_120 -> V_127 = 0x1 ;
V_120 -> V_128 = V_129 ;
break;
case V_108 :
case V_133 :
case V_134 :
case V_53 :
V_120 -> V_126 = 0x5 ;
V_120 -> V_127 = 0x1 ;
V_120 -> V_128 = V_129 ;
break;
case V_57 :
case V_43 :
case V_107 :
V_120 -> V_126 = 0xc ;
V_120 -> V_127 = 0x1 ;
V_120 -> V_128 = V_129 ;
V_121 -> V_126 = 0xc ;
V_121 -> V_127 = 0x1 ;
V_121 -> V_128 = V_129 ;
break;
case V_67 :
case V_68 :
V_120 -> V_126 = 0x5 ;
V_120 -> V_127 = 0x1 ;
V_120 -> V_128 = V_129 ;
break;
case V_72 :
V_120 -> V_126 = 0x5 ;
V_120 -> V_127 = 0x1 ;
V_120 -> V_128 = V_129 ;
V_121 -> V_126 = 0xc ;
V_121 -> V_127 = 0x1 ;
V_121 -> V_128 = V_129 ;
break;
case V_45 :
case V_32 :
case V_33 :
case V_125 :
case V_50 :
case V_51 :
case V_31 :
case V_34 :
case V_35 :
case V_36 :
case V_59 :
case V_60 :
case V_61 :
case V_62 :
case V_63 :
case V_37 :
case V_74 :
case V_42 :
default:
V_121 -> V_126 = 0xc ;
V_121 -> V_127 = 0x1 ;
V_121 -> V_128 = V_129 ;
}
switch ( V_2 -> V_30 ) {
case V_108 :
if ( ! V_109 )
break;
case V_45 :
case V_46 :
case V_125 :
case V_51 :
case V_34 :
case V_35 :
case V_36 :
case V_57 :
case V_43 :
case V_37 :
case V_61 :
case V_62 :
case V_59 :
case V_73 :
case V_67 :
case V_68 :
case V_74 :
case V_38 :
case V_42 :
case V_32 :
case V_135 :
case V_69 :
case V_107 :
V_2 -> V_98 = F_35 ( & V_2 -> V_136 ,
& V_2 -> V_14 [ 2 ] . V_137 ,
L_17 , 0x88 >> 1 , NULL ) ;
if ( V_2 -> V_98 ) {
V_2 -> V_98 -> V_138 = V_110 ;
F_23 ( V_2 -> V_98 , V_99 , V_139 ) ;
}
break;
}
switch ( V_2 -> V_30 ) {
case V_57 :
F_36 ( V_2 ) ;
break;
case V_43 : {
int V_95 ;
const struct V_140 * V_141 ;
const char * V_142 = L_18 ;
char * V_143 = L_19 ;
static struct V_144 V_145 ;
struct V_146 V_147 = {
. V_2 = V_2 ,
. V_143 = V_143 ,
. V_148 = F_28 ,
} ;
F_36 ( V_2 ) ;
F_37 ( & V_2 -> V_14 [ 0 ] . V_137 , & V_145 ) ;
if ( V_149 )
V_145 . V_150 = V_149 ;
switch ( V_145 . V_150 ) {
case 0x4 :
V_142 = L_20 ;
break;
default:
V_142 = L_18 ;
break;
}
F_2 ( V_7 L_21 ,
V_145 . V_150 , V_142 ) ;
V_95 = F_38 ( & V_141 , V_142 , & V_2 -> V_4 -> V_2 ) ;
if ( V_95 != 0 )
F_2 ( V_27 L_22
L_23
L_24 , V_142 ) ;
else
F_39 ( & V_147 , V_141 ) ;
F_40 ( V_141 ) ;
break;
}
}
}
