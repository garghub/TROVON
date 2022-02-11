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
V_24 = 0x04 ;
break;
case V_37 :
case V_38 :
if ( V_23 -> V_39 == 1 )
V_24 = 0x01 ;
else if ( V_23 -> V_39 == 2 )
V_24 = 0x04 ;
break;
case V_40 :
V_24 = 0x02 ;
break;
case V_41 :
F_6 ( V_2 , V_23 -> V_39 ) ;
break;
}
if ( V_24 ) {
F_7 ( V_42 , V_24 ) ;
F_8 ( 200 ) ;
F_9 ( V_42 , V_24 ) ;
}
return 0 ;
}
void F_10 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_29 ) {
case V_43 :
F_9 ( V_42 , 0x00010001 ) ;
break;
case V_31 :
F_9 ( V_42 , 0x00050000 ) ;
F_7 ( V_42 , 0x00000005 ) ;
F_11 ( 5 ) ;
F_9 ( V_42 , 0x00050005 ) ;
break;
case V_32 :
F_9 ( V_42 , 0x00050005 ) ;
break;
case V_44 :
F_12 ( V_2 , V_45 | V_46 , 1 ) ;
F_13 ( V_2 , V_45 | V_46 ) ;
F_8 ( 100 ) ;
F_14 ( V_2 , V_45 | V_46 ) ;
F_8 ( 100 ) ;
F_15 ( V_2 , V_47 , 1 ) ;
F_16 ( V_2 , V_47 ) ;
F_8 ( 20 ) ;
F_17 ( V_2 , V_47 ) ;
F_8 ( 20 ) ;
F_16 ( V_2 , V_47 ) ;
F_8 ( 20 ) ;
break;
case V_48 :
F_9 ( V_42 , 0x00050000 ) ;
F_8 ( 20 ) ;
F_7 ( V_42 , 0x00000005 ) ;
F_8 ( 20 ) ;
F_9 ( V_42 , 0x00050005 ) ;
break;
case V_49 :
F_9 ( V_42 , 0x00050000 ) ;
F_8 ( 20 ) ;
F_7 ( V_42 , 0x00000005 ) ;
F_8 ( 20 ) ;
F_9 ( V_42 , 0x00050005 ) ;
break;
case V_30 :
F_9 ( V_42 , 0x00050000 ) ;
F_8 ( 20 ) ;
F_7 ( V_42 , 0x00000005 ) ;
F_8 ( 20 ) ;
F_9 ( V_42 , 0x00050005 ) ;
break;
case V_37 :
F_9 ( V_42 , 0x000f0000 ) ;
F_8 ( 20 ) ;
F_7 ( V_42 , 0x0000000f ) ;
F_8 ( 20 ) ;
F_9 ( V_42 , 0x000f000f ) ;
break;
case V_38 :
F_9 ( V_42 , 0x000f0000 ) ;
F_8 ( 20 ) ;
F_7 ( V_42 , 0x0000000f ) ;
F_8 ( 20 ) ;
F_9 ( V_42 , 0x000f000f ) ;
break;
case V_33 :
case V_34 :
case V_35 :
case V_36 :
F_9 ( V_42 , 0x00040000 ) ;
F_8 ( 20 ) ;
F_7 ( V_42 , 0x00000004 ) ;
F_8 ( 20 ) ;
F_9 ( V_42 , 0x00040004 ) ;
break;
case V_50 :
F_18 ( V_51 , 0x00000036 ) ;
F_18 ( V_52 , 0x00001000 ) ;
F_9 ( V_53 , 0x00000002 ) ;
F_8 ( 200 ) ;
F_7 ( V_53 , 0x00000800 ) ;
F_8 ( 200 ) ;
F_9 ( V_53 , 0x00000800 ) ;
F_8 ( 200 ) ;
break;
case V_54 :
F_9 ( V_42 , 0x00040000 ) ;
F_7 ( V_42 , 0x00030004 ) ;
F_8 ( 100 ) ;
F_9 ( V_42 , 0x00040004 ) ;
F_18 ( V_51 , 0x00000037 ) ;
F_18 ( V_52 , 0x00001000 ) ;
F_18 ( V_53 , 0x0000c300 ) ;
F_18 ( V_55 , 0x00000000 ) ;
break;
case V_56 :
case V_57 :
case V_58 :
case V_59 :
F_15 ( V_2 , V_60 | V_61 | V_62 , 1 ) ;
F_16 ( V_2 , V_60 | V_61 | V_62 ) ;
F_17 ( V_2 , V_60 ) ;
F_8 ( 20 ) ;
F_16 ( V_2 , V_60 ) ;
break;
case V_63 :
case V_64 :
F_15 ( V_2 , V_65 | V_66 | V_47 , 1 ) ;
F_17 ( V_2 , V_66 | V_47 ) ;
F_8 ( 100 ) ;
F_16 ( V_2 , V_65 | V_66 | V_47 ) ;
F_8 ( 100 ) ;
break;
case V_67 :
F_15 ( V_2 , V_65 | V_66 , 1 ) ;
F_17 ( V_2 , V_65 | V_66 ) ;
F_8 ( 100 ) ;
F_16 ( V_2 , V_65 | V_66 ) ;
F_8 ( 100 ) ;
break;
case V_68 :
case V_69 :
F_12 ( V_2 , V_46 | V_70 , 1 ) ;
F_13 ( V_2 , V_46 | V_70 ) ;
F_8 ( 100 ) ;
F_14 ( V_2 , V_46 ) ;
F_8 ( 100 ) ;
break;
case V_40 :
F_9 ( V_42 , 0x00010001 ) ;
break;
case V_41 :
F_9 ( V_42 , 0x00060000 ) ;
F_7 ( V_42 , 0x00010006 ) ;
F_8 ( 100 ) ;
F_9 ( V_42 , 0x00000004 ) ;
F_18 ( V_51 , 0x00000037 ) ;
F_18 ( V_52 , 0x00005000 ) ;
F_18 ( V_53 , 0x00000d00 ) ;
F_18 ( V_55 , 0x00000000 ) ;
break;
}
}
int F_19 ( struct V_1 * V_2 )
{
static struct V_71 V_72 [] = {
{
. V_73 = V_74 ,
. V_75 = V_76 ,
. V_77 = V_78 ,
. V_79 = 0 ,
. V_80 = V_81 ,
} , {
. V_73 = V_82 ,
. V_75 = V_83 ,
. V_77 = V_84 ,
. V_79 = 0 ,
. V_80 = V_81 ,
}
} ;
const T_3 V_85 = F_20 ( V_72 ) ;
static struct V_71 V_86 [] = {
{
. V_73 = V_74 ,
. V_75 = V_76 ,
. V_77 = V_78 ,
. V_79 = 0 ,
. V_80 = V_81 ,
}
} ;
const T_3 V_87 = F_20 ( V_86 ) ;
struct V_88 V_89 ;
int V_90 = 0 ;
switch ( V_2 -> V_29 ) {
case V_31 :
case V_32 :
case V_44 :
case V_48 :
case V_30 :
case V_56 :
case V_57 :
case V_58 :
case V_59 :
break;
case V_68 :
case V_69 :
V_90 = F_21 ( V_2 ) ;
if ( V_90 )
break;
V_2 -> V_91 = F_22 ( V_2 , V_92 ) ;
F_23 ( V_2 -> V_93 , V_94 , V_95 ,
V_85 , V_72 ) ;
F_23 ( V_2 -> V_91 , V_96 , V_97 , & V_89 ) ;
V_89 . V_98 = false ;
V_89 . V_99 = false ;
V_89 . V_100 = true ;
F_23 ( V_2 -> V_91 , V_96 , V_101 , & V_89 ) ;
V_89 . V_99 = true ;
F_23 ( V_2 -> V_91 , V_96 , V_101 , & V_89 ) ;
break;
case V_102 :
if ( ! V_103 )
break;
V_2 -> V_91 = F_22 ( V_2 , V_104 ) ;
if ( V_2 -> V_91 == NULL ) {
V_90 = - V_105 ;
break;
}
F_23 ( V_2 -> V_93 , V_94 , V_95 ,
V_87 , V_86 ) ;
break;
case V_43 :
if ( ! V_103 )
break;
V_2 -> V_91 = F_22 ( V_2 , V_104 ) ;
if ( V_2 -> V_91 == NULL ) {
V_90 = - V_105 ;
break;
}
F_23 ( V_2 -> V_93 , V_94 , V_95 ,
V_85 , V_72 ) ;
break;
case V_38 :
F_24 ( L_16 ) ;
break;
}
return V_90 ;
}
void F_25 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_29 ) {
case V_68 :
case V_69 :
F_26 ( V_2 , V_106 ) ;
F_27 ( V_2 ) ;
V_2 -> V_91 = NULL ;
break;
case V_102 :
case V_43 :
F_26 ( V_2 , V_107 ) ;
V_2 -> V_91 = NULL ;
break;
}
}
int F_28 ( void * V_108 , int V_109 , int V_110 , int V_111 )
{
int V_112 ;
int V_113 = 0 ;
struct V_1 * V_2 = (struct V_1 * ) V_108 ;
V_112 = ( ( F_29 ( V_42 ) ) & ( ~ 0x00000002 ) ) ;
V_112 |= ( V_109 ? 0x00020002 : 0x00020000 ) ;
F_18 ( V_42 , V_112 ) ;
V_112 = ( ( F_29 ( V_53 ) ) & ( ~ 0x0000a000 ) ) ;
V_112 |= ( V_110 ? 0x00008000 : 0 ) ;
F_18 ( V_53 , V_112 ) ;
if ( V_111 )
V_113 = ( V_112 & 0x00004000 ) ? 1 : 0 ;
F_18 ( V_53 , V_112 | 0x00002000 ) ;
F_30 ( 1 ) ;
F_18 ( V_53 , V_112 ) ;
return V_113 ;
}
void F_31 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_29 ) {
case V_68 :
case V_69 :
if ( V_2 -> V_91 )
F_32 ( V_2 , V_106 ) ;
break;
case V_102 :
case V_43 :
if ( V_2 -> V_91 )
F_32 ( V_2 , V_107 ) ;
break;
}
}
void F_33 ( struct V_1 * V_2 )
{
struct V_22 * V_114 = & V_2 -> V_114 ;
struct V_22 * V_115 = & V_2 -> V_115 ;
static T_1 V_116 [ 256 ] ;
if ( V_2 -> V_14 [ 0 ] . V_117 == 0 ) {
V_2 -> V_14 [ 0 ] . V_15 . V_118 = 0xa0 >> 1 ;
F_34 ( & V_2 -> V_14 [ 0 ] . V_15 ,
V_116 , sizeof( V_116 ) ) ;
}
switch ( V_2 -> V_29 ) {
case V_43 :
if ( V_2 -> V_14 [ 0 ] . V_117 == 0 ) {
if ( V_116 [ 0x80 ] != 0x84 )
F_3 ( V_2 , V_116 + 0xc0 ) ;
else
F_3 ( V_2 , V_116 + 0x80 ) ;
}
break;
case V_31 :
case V_32 :
case V_30 :
if ( V_2 -> V_14 [ 0 ] . V_117 == 0 )
F_3 ( V_2 , V_116 + 0x80 ) ;
break;
case V_44 :
case V_119 :
case V_48 :
case V_49 :
case V_56 :
case V_57 :
case V_58 :
case V_59 :
case V_68 :
case V_69 :
if ( V_2 -> V_14 [ 0 ] . V_117 == 0 )
F_3 ( V_2 , V_116 + 0xc0 ) ;
break;
}
switch ( V_2 -> V_29 ) {
case V_37 :
case V_38 :
V_115 -> V_120 = 0xc ;
V_115 -> V_121 = 0x1 ;
V_115 -> V_122 = V_123 ;
case V_124 :
V_114 -> V_120 = 0xc ;
V_114 -> V_121 = 0x1 ;
V_114 -> V_122 = V_123 ;
break;
case V_44 :
V_114 -> V_120 = 0x10e ;
V_114 -> V_121 = 0x1 ;
V_114 -> V_122 = V_123 ;
V_114 -> V_125 = 0x2000 ;
V_114 -> V_126 = ( 0x47 << 16 | 188 << 4 | 0xc ) ;
V_115 -> V_120 = 0xc ;
V_115 -> V_121 = 0x1 ;
V_115 -> V_122 = V_123 ;
break;
case V_50 :
V_114 -> V_120 = 0x4 ;
V_114 -> V_121 = 0x1 ;
V_114 -> V_122 = V_123 ;
break;
case V_102 :
case V_127 :
V_114 -> V_120 = 0x5 ;
V_114 -> V_121 = 0x1 ;
V_114 -> V_122 = V_123 ;
break;
case V_54 :
case V_41 :
V_114 -> V_120 = 0xc ;
V_114 -> V_121 = 0x1 ;
V_114 -> V_122 = V_123 ;
V_115 -> V_120 = 0xc ;
V_115 -> V_121 = 0x1 ;
V_115 -> V_122 = V_123 ;
break;
case V_63 :
case V_64 :
V_114 -> V_120 = 0x5 ;
V_114 -> V_121 = 0x1 ;
V_114 -> V_122 = V_123 ;
break;
case V_67 :
V_114 -> V_120 = 0x5 ;
V_114 -> V_121 = 0x1 ;
V_114 -> V_122 = V_123 ;
V_115 -> V_120 = 0xc ;
V_115 -> V_121 = 0x1 ;
V_115 -> V_122 = V_123 ;
break;
case V_43 :
case V_31 :
case V_32 :
case V_119 :
case V_48 :
case V_49 :
case V_30 :
case V_33 :
case V_34 :
case V_56 :
case V_57 :
case V_58 :
case V_59 :
case V_68 :
case V_35 :
case V_69 :
case V_40 :
default:
V_115 -> V_120 = 0xc ;
V_115 -> V_121 = 0x1 ;
V_115 -> V_122 = V_123 ;
}
switch ( V_2 -> V_29 ) {
case V_102 :
case V_43 :
if ( ! V_103 )
break;
case V_44 :
case V_119 :
case V_49 :
case V_33 :
case V_34 :
case V_54 :
case V_41 :
case V_35 :
case V_68 :
case V_63 :
case V_64 :
case V_69 :
case V_36 :
case V_40 :
V_2 -> V_93 = F_35 ( & V_2 -> V_128 ,
& V_2 -> V_14 [ 2 ] . V_129 ,
L_17 , 0x88 >> 1 , NULL ) ;
if ( V_2 -> V_93 ) {
V_2 -> V_93 -> V_130 = V_104 ;
F_23 ( V_2 -> V_93 , V_94 , V_131 ) ;
}
break;
}
switch ( V_2 -> V_29 ) {
case V_54 :
F_36 ( V_2 ) ;
break;
case V_41 : {
int V_90 ;
const struct V_132 * V_133 ;
const char * V_134 = L_18 ;
char * V_135 = L_19 ;
struct V_136 V_137 = {
. V_2 = V_2 ,
. V_135 = V_135 ,
. V_138 = F_28 ,
} ;
F_36 ( V_2 ) ;
V_90 = F_37 ( & V_133 , V_134 , & V_2 -> V_4 -> V_2 ) ;
if ( V_90 != 0 )
F_2 ( V_26 L_20
L_21
L_22 , V_134 ) ;
else
F_38 ( & V_137 , V_133 ) ;
F_39 ( V_133 ) ;
break;
}
}
}
