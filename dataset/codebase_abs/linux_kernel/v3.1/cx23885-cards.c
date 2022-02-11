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
if ( V_20 == V_25 )
return 0 ;
if ( V_20 != 0 ) {
F_2 ( V_26 L_15 ,
V_27 , V_20 ) ;
return - V_28 ;
}
switch ( V_2 -> V_29 ) {
case V_30 :
case V_31 :
case V_32 :
case V_33 :
case V_34 :
case V_35 :
case V_36 :
case V_37 :
V_24 = 0x04 ;
break;
case V_38 :
case V_39 :
if ( V_23 -> V_40 == 1 )
V_24 = 0x01 ;
else if ( V_23 -> V_40 == 2 )
V_24 = 0x04 ;
break;
case V_41 :
V_24 = 0x02 ;
break;
case V_42 :
F_6 ( V_2 , V_23 -> V_40 ) ;
break;
}
if ( V_24 ) {
F_7 ( V_43 , V_24 ) ;
F_8 ( 200 ) ;
F_9 ( V_43 , V_24 ) ;
}
return 0 ;
}
void F_10 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_29 ) {
case V_44 :
F_9 ( V_43 , 0x00010001 ) ;
break;
case V_31 :
F_9 ( V_43 , 0x00050000 ) ;
F_7 ( V_43 , 0x00000005 ) ;
F_11 ( 5 ) ;
F_9 ( V_43 , 0x00050005 ) ;
break;
case V_32 :
F_9 ( V_43 , 0x00050005 ) ;
break;
case V_45 :
F_12 ( V_2 , V_46 | V_47 , 1 ) ;
F_13 ( V_2 , V_46 | V_47 ) ;
F_8 ( 100 ) ;
F_14 ( V_2 , V_46 | V_47 ) ;
F_8 ( 100 ) ;
F_15 ( V_2 , V_48 , 1 ) ;
F_16 ( V_2 , V_48 ) ;
F_8 ( 20 ) ;
F_17 ( V_2 , V_48 ) ;
F_8 ( 20 ) ;
F_16 ( V_2 , V_48 ) ;
F_8 ( 20 ) ;
break;
case V_49 :
F_9 ( V_43 , 0x00050000 ) ;
F_8 ( 20 ) ;
F_7 ( V_43 , 0x00000005 ) ;
F_8 ( 20 ) ;
F_9 ( V_43 , 0x00050005 ) ;
break;
case V_50 :
F_9 ( V_43 , 0x00050000 ) ;
F_8 ( 20 ) ;
F_7 ( V_43 , 0x00000005 ) ;
F_8 ( 20 ) ;
F_9 ( V_43 , 0x00050005 ) ;
break;
case V_30 :
F_9 ( V_43 , 0x00050000 ) ;
F_8 ( 20 ) ;
F_7 ( V_43 , 0x00000005 ) ;
F_8 ( 20 ) ;
F_9 ( V_43 , 0x00050005 ) ;
break;
case V_38 :
F_9 ( V_43 , 0x000f0000 ) ;
F_8 ( 20 ) ;
F_7 ( V_43 , 0x0000000f ) ;
F_8 ( 20 ) ;
F_9 ( V_43 , 0x000f000f ) ;
break;
case V_39 :
F_9 ( V_43 , 0x000f0000 ) ;
F_8 ( 20 ) ;
F_7 ( V_43 , 0x0000000f ) ;
F_8 ( 20 ) ;
F_9 ( V_43 , 0x000f000f ) ;
break;
case V_33 :
case V_34 :
case V_35 :
case V_36 :
case V_37 :
F_9 ( V_43 , 0x00040000 ) ;
F_8 ( 20 ) ;
F_7 ( V_43 , 0x00000004 ) ;
F_8 ( 20 ) ;
F_9 ( V_43 , 0x00040004 ) ;
break;
case V_51 :
F_18 ( V_52 , 0x00000036 ) ;
F_18 ( V_53 , 0x00001000 ) ;
F_9 ( V_54 , 0x00000002 ) ;
F_8 ( 200 ) ;
F_7 ( V_54 , 0x00000800 ) ;
F_8 ( 200 ) ;
F_9 ( V_54 , 0x00000800 ) ;
F_8 ( 200 ) ;
break;
case V_55 :
F_9 ( V_43 , 0x00040000 ) ;
F_7 ( V_43 , 0x00030004 ) ;
F_8 ( 100 ) ;
F_9 ( V_43 , 0x00040004 ) ;
F_18 ( V_52 , 0x00000037 ) ;
F_18 ( V_53 , 0x00001000 ) ;
F_18 ( V_54 , 0x0000c300 ) ;
F_18 ( V_56 , 0x00000000 ) ;
break;
case V_57 :
case V_58 :
case V_59 :
case V_60 :
F_15 ( V_2 , V_61 | V_62 | V_63 , 1 ) ;
F_16 ( V_2 , V_61 | V_62 | V_63 ) ;
F_17 ( V_2 , V_61 ) ;
F_8 ( 20 ) ;
F_16 ( V_2 , V_61 ) ;
break;
case V_64 :
case V_65 :
F_15 ( V_2 , V_66 | V_67 | V_48 , 1 ) ;
F_17 ( V_2 , V_67 | V_48 ) ;
F_8 ( 100 ) ;
F_16 ( V_2 , V_66 | V_67 | V_48 ) ;
F_8 ( 100 ) ;
break;
case V_68 :
F_15 ( V_2 , V_66 | V_67 , 1 ) ;
F_17 ( V_2 , V_66 | V_67 ) ;
F_8 ( 100 ) ;
F_16 ( V_2 , V_66 | V_67 ) ;
F_8 ( 100 ) ;
break;
case V_69 :
case V_70 :
F_12 ( V_2 , V_47 | V_71 , 1 ) ;
F_13 ( V_2 , V_47 | V_71 ) ;
F_8 ( 100 ) ;
F_14 ( V_2 , V_47 ) ;
F_8 ( 100 ) ;
break;
case V_41 :
F_9 ( V_43 , 0x00010001 ) ;
break;
case V_42 :
F_9 ( V_43 , 0x00060000 ) ;
F_7 ( V_43 , 0x00010006 ) ;
F_8 ( 100 ) ;
F_9 ( V_43 , 0x00000004 ) ;
F_18 ( V_52 , 0x00000037 ) ;
F_18 ( V_53 , 0x00005000 ) ;
F_18 ( V_54 , 0x00000d00 ) ;
F_18 ( V_56 , 0x00000000 ) ;
break;
}
}
int F_19 ( struct V_1 * V_2 )
{
static struct V_72 V_73 [] = {
{
. V_74 = V_75 ,
. V_76 = V_77 ,
. V_78 = V_79 ,
. V_80 = 0 ,
. V_81 = V_82 ,
} , {
. V_74 = V_83 ,
. V_76 = V_84 ,
. V_78 = V_85 ,
. V_80 = 0 ,
. V_81 = V_82 ,
}
} ;
const T_3 V_86 = F_20 ( V_73 ) ;
static struct V_72 V_87 [] = {
{
. V_74 = V_75 ,
. V_76 = V_77 ,
. V_78 = V_79 ,
. V_80 = 0 ,
. V_81 = V_82 ,
}
} ;
const T_3 V_88 = F_20 ( V_87 ) ;
struct V_89 V_90 ;
int V_91 = 0 ;
switch ( V_2 -> V_29 ) {
case V_31 :
case V_32 :
case V_45 :
case V_49 :
case V_30 :
case V_58 :
case V_59 :
case V_60 :
break;
case V_57 :
V_91 = F_21 ( V_2 ) ;
if ( V_91 )
break;
V_2 -> V_92 = F_22 ( V_2 , V_93 ) ;
F_23 ( V_2 -> V_94 , V_95 , V_96 ,
V_88 , V_87 ) ;
break;
case V_69 :
case V_70 :
V_91 = F_21 ( V_2 ) ;
if ( V_91 )
break;
V_2 -> V_92 = F_22 ( V_2 , V_93 ) ;
F_23 ( V_2 -> V_94 , V_95 , V_96 ,
V_86 , V_73 ) ;
F_23 ( V_2 -> V_92 , V_97 , V_98 , & V_90 ) ;
V_90 . V_99 = false ;
V_90 . V_100 = false ;
V_90 . V_101 = true ;
F_23 ( V_2 -> V_92 , V_97 , V_102 , & V_90 ) ;
V_90 . V_100 = true ;
F_23 ( V_2 -> V_92 , V_97 , V_102 , & V_90 ) ;
break;
case V_103 :
if ( ! V_104 )
break;
V_2 -> V_92 = F_22 ( V_2 , V_105 ) ;
if ( V_2 -> V_92 == NULL ) {
V_91 = - V_106 ;
break;
}
F_23 ( V_2 -> V_94 , V_95 , V_96 ,
V_88 , V_87 ) ;
break;
case V_44 :
if ( ! V_104 )
break;
V_2 -> V_92 = F_22 ( V_2 , V_105 ) ;
if ( V_2 -> V_92 == NULL ) {
V_91 = - V_106 ;
break;
}
F_23 ( V_2 -> V_94 , V_95 , V_96 ,
V_86 , V_73 ) ;
break;
case V_39 :
F_24 ( L_16 ) ;
break;
}
return V_91 ;
}
void F_25 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_29 ) {
case V_57 :
case V_69 :
case V_70 :
F_26 ( V_2 , V_107 ) ;
F_27 ( V_2 ) ;
V_2 -> V_92 = NULL ;
break;
case V_103 :
case V_44 :
F_26 ( V_2 , V_108 ) ;
V_2 -> V_92 = NULL ;
break;
}
}
int F_28 ( void * V_109 , int V_110 , int V_111 , int V_112 )
{
int V_113 ;
int V_114 = 0 ;
struct V_1 * V_2 = (struct V_1 * ) V_109 ;
V_113 = ( ( F_29 ( V_43 ) ) & ( ~ 0x00000002 ) ) ;
V_113 |= ( V_110 ? 0x00020002 : 0x00020000 ) ;
F_18 ( V_43 , V_113 ) ;
V_113 = ( ( F_29 ( V_54 ) ) & ( ~ 0x0000a000 ) ) ;
V_113 |= ( V_111 ? 0x00008000 : 0 ) ;
F_18 ( V_54 , V_113 ) ;
if ( V_112 )
V_114 = ( V_113 & 0x00004000 ) ? 1 : 0 ;
F_18 ( V_54 , V_113 | 0x00002000 ) ;
F_30 ( 1 ) ;
F_18 ( V_54 , V_113 ) ;
return V_114 ;
}
void F_31 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_29 ) {
case V_57 :
case V_69 :
case V_70 :
if ( V_2 -> V_92 )
F_32 ( V_2 , V_107 ) ;
break;
case V_103 :
case V_44 :
if ( V_2 -> V_92 )
F_32 ( V_2 , V_108 ) ;
break;
}
}
void F_33 ( struct V_1 * V_2 )
{
struct V_22 * V_115 = & V_2 -> V_115 ;
struct V_22 * V_116 = & V_2 -> V_116 ;
static T_1 V_117 [ 256 ] ;
if ( V_2 -> V_14 [ 0 ] . V_118 == 0 ) {
V_2 -> V_14 [ 0 ] . V_15 . V_119 = 0xa0 >> 1 ;
F_34 ( & V_2 -> V_14 [ 0 ] . V_15 ,
V_117 , sizeof( V_117 ) ) ;
}
switch ( V_2 -> V_29 ) {
case V_44 :
if ( V_2 -> V_14 [ 0 ] . V_118 == 0 ) {
if ( V_117 [ 0x80 ] != 0x84 )
F_3 ( V_2 , V_117 + 0xc0 ) ;
else
F_3 ( V_2 , V_117 + 0x80 ) ;
}
break;
case V_31 :
case V_32 :
case V_30 :
if ( V_2 -> V_14 [ 0 ] . V_118 == 0 )
F_3 ( V_2 , V_117 + 0x80 ) ;
break;
case V_45 :
case V_120 :
case V_49 :
case V_50 :
case V_57 :
case V_58 :
case V_59 :
case V_60 :
case V_69 :
case V_70 :
if ( V_2 -> V_14 [ 0 ] . V_118 == 0 )
F_3 ( V_2 , V_117 + 0xc0 ) ;
break;
}
switch ( V_2 -> V_29 ) {
case V_38 :
case V_39 :
V_116 -> V_121 = 0xc ;
V_116 -> V_122 = 0x1 ;
V_116 -> V_123 = V_124 ;
case V_125 :
V_115 -> V_121 = 0xc ;
V_115 -> V_122 = 0x1 ;
V_115 -> V_123 = V_124 ;
break;
case V_45 :
V_115 -> V_121 = 0x10e ;
V_115 -> V_122 = 0x1 ;
V_115 -> V_123 = V_124 ;
V_115 -> V_126 = 0x2000 ;
V_115 -> V_127 = ( 0x47 << 16 | 188 << 4 | 0xc ) ;
V_116 -> V_121 = 0xc ;
V_116 -> V_122 = 0x1 ;
V_116 -> V_123 = V_124 ;
break;
case V_51 :
V_115 -> V_121 = 0x4 ;
V_115 -> V_122 = 0x1 ;
V_115 -> V_123 = V_124 ;
break;
case V_103 :
case V_128 :
V_115 -> V_121 = 0x5 ;
V_115 -> V_122 = 0x1 ;
V_115 -> V_123 = V_124 ;
break;
case V_55 :
case V_42 :
V_115 -> V_121 = 0xc ;
V_115 -> V_122 = 0x1 ;
V_115 -> V_123 = V_124 ;
V_116 -> V_121 = 0xc ;
V_116 -> V_122 = 0x1 ;
V_116 -> V_123 = V_124 ;
break;
case V_64 :
case V_65 :
V_115 -> V_121 = 0x5 ;
V_115 -> V_122 = 0x1 ;
V_115 -> V_123 = V_124 ;
break;
case V_68 :
V_115 -> V_121 = 0x5 ;
V_115 -> V_122 = 0x1 ;
V_115 -> V_123 = V_124 ;
V_116 -> V_121 = 0xc ;
V_116 -> V_122 = 0x1 ;
V_116 -> V_123 = V_124 ;
break;
case V_44 :
case V_31 :
case V_32 :
case V_120 :
case V_49 :
case V_50 :
case V_30 :
case V_33 :
case V_34 :
case V_35 :
case V_57 :
case V_58 :
case V_59 :
case V_60 :
case V_69 :
case V_36 :
case V_70 :
case V_41 :
default:
V_116 -> V_121 = 0xc ;
V_116 -> V_122 = 0x1 ;
V_116 -> V_123 = V_124 ;
}
switch ( V_2 -> V_29 ) {
case V_103 :
case V_44 :
if ( ! V_104 )
break;
case V_45 :
case V_120 :
case V_50 :
case V_33 :
case V_34 :
case V_35 :
case V_55 :
case V_42 :
case V_36 :
case V_57 :
case V_69 :
case V_64 :
case V_65 :
case V_70 :
case V_37 :
case V_41 :
V_2 -> V_94 = F_35 ( & V_2 -> V_129 ,
& V_2 -> V_14 [ 2 ] . V_130 ,
L_17 , 0x88 >> 1 , NULL ) ;
if ( V_2 -> V_94 ) {
V_2 -> V_94 -> V_131 = V_105 ;
F_23 ( V_2 -> V_94 , V_95 , V_132 ) ;
}
break;
}
switch ( V_2 -> V_29 ) {
case V_55 :
F_36 ( V_2 ) ;
break;
case V_42 : {
int V_91 ;
const struct V_133 * V_134 ;
const char * V_135 = L_18 ;
char * V_136 = L_19 ;
static struct V_137 V_138 ;
struct V_139 V_140 = {
. V_2 = V_2 ,
. V_136 = V_136 ,
. V_141 = F_28 ,
} ;
F_36 ( V_2 ) ;
F_37 ( & V_2 -> V_14 [ 0 ] . V_130 , & V_138 ) ;
if ( V_142 )
V_138 . V_143 = V_142 ;
switch ( V_138 . V_143 ) {
case 0x4 :
V_135 = L_20 ;
break;
default:
V_135 = L_18 ;
break;
}
F_2 ( V_7 L_21 ,
V_138 . V_143 , V_135 ) ;
V_91 = F_38 ( & V_134 , V_135 , & V_2 -> V_4 -> V_2 ) ;
if ( V_91 != 0 )
F_2 ( V_26 L_22
L_23
L_24 , V_135 ) ;
else
F_39 ( & V_140 , V_134 ) ;
F_40 ( V_134 ) ;
break;
}
}
}
