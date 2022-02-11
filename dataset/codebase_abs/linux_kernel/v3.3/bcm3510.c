static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 * V_4 , T_1 V_5 )
{
T_1 V_6 [ 256 ] ;
int V_7 ;
struct V_8 V_9 = { . V_10 = V_2 -> V_11 -> V_12 , . V_13 = 0 , . V_4 = V_6 , . V_5 = V_5 + 1 } ;
V_6 [ 0 ] = V_3 ;
memcpy ( & V_6 [ 1 ] , V_4 , V_5 ) ;
F_2 ( L_1 , V_3 ) ;
F_3 ( V_4 , V_5 , F_2 ) ;
F_2 ( L_2 ) ;
if ( ( V_7 = F_4 ( V_2 -> V_14 , & V_9 , 1 ) ) != 1 ) {
F_5 ( L_3 ,
V_15 , V_2 -> V_11 -> V_12 , V_3 , V_7 ) ;
return - V_16 ;
}
return 0 ;
}
static int F_6 ( struct V_1 * V_2 , T_1 V_3 , T_1 * V_4 , T_1 V_5 )
{
struct V_8 V_9 [] = {
{ . V_10 = V_2 -> V_11 -> V_12 , . V_13 = 0 , . V_4 = & V_3 , . V_5 = 1 } ,
{ . V_10 = V_2 -> V_11 -> V_12 , . V_13 = V_17 , . V_4 = V_4 , . V_5 = V_5 }
} ;
int V_7 ;
memset ( V_4 , 0 , V_5 ) ;
if ( ( V_7 = F_4 ( V_2 -> V_14 , V_9 , 2 ) ) != 2 ) {
F_5 ( L_4 ,
V_15 , V_2 -> V_11 -> V_12 , V_3 , V_7 ) ;
return - V_16 ;
}
F_2 ( L_5 , V_3 ) ;
F_3 ( V_4 , V_5 , F_2 ) ;
F_2 ( L_2 ) ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_18 )
{
return F_1 ( V_2 , V_3 , & V_18 . V_19 , 1 ) ;
}
static int F_8 ( struct V_1 * V_2 , T_1 V_3 , T_2 * V_18 )
{
return F_6 ( V_2 , V_3 , & V_18 -> V_19 , 1 ) ;
}
static int F_9 ( struct V_1 * V_20 , T_1 * V_4 , int V_5 )
{
T_2 V_18 ;
int V_21 , V_22 ;
V_18 . V_23 . V_24 = 0 ;
if ( ( V_21 = F_7 ( V_20 , 0xa6 , V_18 ) ) < 0 )
return V_21 ;
for ( V_22 = 0 ; V_22 < V_5 ; V_22 ++ ) {
if ( ( V_21 = F_8 ( V_20 , 0xa7 , & V_18 ) ) < 0 )
return V_21 ;
V_4 [ V_22 ] = V_18 . V_25 ;
}
return 0 ;
}
static int F_10 ( struct V_1 * V_20 , T_1 * V_4 , int V_5 )
{
T_2 V_18 , V_26 ;
int V_21 , V_22 ;
unsigned long V_27 ;
if ( ( V_21 = F_8 ( V_20 , 0xa8 , & V_18 ) ) < 0 )
return V_21 ;
if ( V_18 . V_28 . V_29 ) {
F_5 ( L_6 ) ;
V_18 . V_28 . V_29 = 0 ;
F_7 ( V_20 , 0xa8 , V_18 ) ;
}
V_26 . V_23 . V_24 = 0 ;
if ( ( V_21 = F_7 ( V_20 , 0xa6 , V_26 ) ) < 0 )
return V_21 ;
for ( V_22 = 0 ; V_22 < V_5 ; V_22 ++ ) {
V_26 . V_25 = V_4 [ V_22 ] ;
if ( ( V_21 = F_7 ( V_20 , 0xa7 , V_26 ) ) < 0 )
return V_21 ;
}
V_18 . V_19 = 0 ; V_18 . V_28 . V_29 = 1 ; V_18 . V_28 . V_30 = 1 ;
if ( ( V_21 = F_7 ( V_20 , 0xa8 , V_18 ) ) < 0 )
return V_21 ;
V_27 = V_31 + 1 * V_32 ;
while ( F_11 ( V_31 , V_27 ) ) {
F_5 ( L_7 ) ;
F_12 ( 10 ) ;
if ( ( V_21 = F_8 ( V_20 , 0xa8 , & V_18 ) ) < 0 )
return V_21 ;
if ( ! V_18 . V_28 . V_29 )
return 0 ;
}
F_5 ( L_8 ) ;
return - V_33 ;
}
static int F_13 ( struct V_1 * V_20 , T_1 V_34 , T_1 V_35 , T_1 * V_36 , T_1 V_37 , T_1 * V_38 , T_1 V_39 )
{
T_1 V_40 [ V_37 + 2 ] , V_41 [ V_39 + 2 ] ;
int V_21 = 0 ;
V_40 [ 0 ] = V_34 ;
V_40 [ 1 ] = V_35 ;
memcpy ( & V_40 [ 2 ] , V_36 , V_37 ) ;
F_14 ( L_9 ) ;
F_3 ( V_40 , V_37 + 2 , F_14 ) ;
F_14 ( L_2 ) ;
if ( F_15 ( & V_20 -> V_42 ) < 0 )
return - V_43 ;
if ( ( V_21 = F_10 ( V_20 , V_40 , V_37 + 2 ) ) < 0 ||
( V_21 = F_9 ( V_20 , V_41 , V_39 + 2 ) ) < 0 )
goto error;
F_14 ( L_10 ) ;
F_3 ( V_41 , V_39 + 2 , F_14 ) ;
F_14 ( L_2 ) ;
memcpy ( V_38 , & V_41 [ 2 ] , V_39 ) ;
error:
F_16 ( & V_20 -> V_42 ) ;
return V_21 ;
}
static int F_17 ( struct V_1 * V_20 )
{
T_2 V_6 ;
int V_21 ;
if ( ( V_21 = F_8 ( V_20 , 0xfa , & V_6 ) ) < 0 )
return V_21 ;
V_6 . V_44 . V_45 = 0 ; F_7 ( V_20 , 0xfa , V_6 ) ;
V_6 . V_44 . V_45 = 1 ; F_7 ( V_20 , 0xfa , V_6 ) ;
V_6 . V_44 . V_45 = 0 ; F_7 ( V_20 , 0xfa , V_6 ) ;
V_6 . V_44 . V_46 = 1 ; V_6 . V_44 . V_47 = 1 ; F_7 ( V_20 , 0xfa , V_6 ) ;
return 0 ;
}
static int F_18 ( struct V_1 * V_20 )
{
if ( F_19 ( V_31 , V_20 -> V_48 ) ) {
F_13 ( V_20 , V_49 , V_50 , NULL , 0 , ( T_1 * ) & V_20 -> V_51 , sizeof( V_20 -> V_51 ) ) ;
F_13 ( V_20 , V_49 , V_52 , NULL , 0 , ( T_1 * ) & V_20 -> V_53 , sizeof( V_20 -> V_53 ) ) ;
V_20 -> V_48 = V_31 + ( V_20 -> V_54 * V_32 ) / 1000 ;
}
return 0 ;
}
static int F_20 ( struct V_55 * V_56 , T_3 * V_57 )
{
struct V_1 * V_20 = V_56 -> V_58 ;
F_18 ( V_20 ) ;
* V_57 = 0 ;
if ( V_20 -> V_51 . V_59 . V_60 )
* V_57 |= V_61 | V_62 ;
if ( V_20 -> V_51 . V_59 . V_63 )
* V_57 |= V_64 ;
if ( V_20 -> V_51 . V_59 . V_65 )
* V_57 |= V_66 | V_67 ;
if ( * V_57 & V_61 )
V_20 -> V_54 = 1500 ;
else
V_20 -> V_54 = 500 ;
F_5 ( L_11 , * V_57 ) ;
return 0 ;
}
static int F_21 ( struct V_55 * V_56 , T_4 * V_68 )
{
struct V_1 * V_20 = V_56 -> V_58 ;
F_18 ( V_20 ) ;
* V_68 = ( V_20 -> V_53 . V_69 << 16 ) | ( V_20 -> V_53 . V_70 << 8 ) | V_20 -> V_53 . V_71 ;
return 0 ;
}
static int F_22 ( struct V_55 * V_56 , T_4 * V_72 )
{
struct V_1 * V_20 = V_56 -> V_58 ;
F_18 ( V_20 ) ;
* V_72 = ( V_20 -> V_53 . V_73 << 8 ) | V_20 -> V_53 . V_74 ;
return 0 ;
}
static int F_23 ( struct V_55 * V_56 , T_5 * V_75 )
{
struct V_1 * V_20 = V_56 -> V_58 ;
T_6 V_27 ;
F_18 ( V_20 ) ;
V_27 = V_20 -> V_53 . SIGNAL ;
if ( V_27 > 190 )
V_27 = 190 ;
if ( V_27 < 90 )
V_27 = 90 ;
V_27 -= 90 ;
V_27 = V_27 * 0xff / 100 ;
* V_75 = ( V_27 << 8 ) | V_27 ;
return 0 ;
}
static int F_24 ( struct V_55 * V_56 , T_5 * V_76 )
{
struct V_1 * V_20 = V_56 -> V_58 ;
F_18 ( V_20 ) ;
* V_76 = V_20 -> V_51 . V_77 * 1000 + ( ( V_20 -> V_51 . V_78 * 1000 ) >> 8 ) ;
return 0 ;
}
static int F_25 ( struct V_1 * V_20 , T_1 V_79 , T_5 V_80 , T_1 V_81 )
{
struct V_82 V_83 ;
memset ( & V_83 , 0 , sizeof( struct V_82 ) ) ;
V_83 . V_84 = 0x10 ;
V_83 . V_85 = 0 ;
V_83 . V_86 = 0x10 ;
V_83 . V_87 = 0x40 ;
V_83 . V_88 [ 0 ] . V_89 . V_90 = V_91 ;
V_83 . V_88 [ 0 ] . V_92 = 0x80 | V_79 ;
V_83 . V_88 [ 1 ] . V_89 . V_90 = V_91 ;
V_83 . V_88 [ 1 ] . V_92 = 4 ;
V_83 . V_88 [ 2 ] . V_89 . V_90 = V_93 ;
V_83 . V_88 [ 2 ] . V_92 = 0x20 ;
V_83 . V_88 [ 3 ] . V_89 . V_90 = V_93 ;
V_83 . V_88 [ 3 ] . V_89 . V_94 = 1 ;
V_83 . V_88 [ 3 ] . V_89 . V_95 = 1 ;
V_83 . V_88 [ 3 ] . V_92 = 0x40 ;
V_83 . V_88 [ 4 ] . V_89 . V_90 = V_91 ;
V_83 . V_88 [ 4 ] . V_92 = V_80 >> 3 ;
V_83 . V_88 [ 5 ] . V_89 . V_90 = V_91 ;
V_83 . V_88 [ 5 ] . V_92 = ( ( V_80 & 0x7 ) << 5 ) | ( V_81 >> 2 ) ;
V_83 . V_88 [ 6 ] . V_89 . V_90 = V_93 ;
V_83 . V_88 [ 6 ] . V_92 = ( V_81 << 6 ) & 0xdf ;
V_83 . V_88 [ 7 ] . V_89 . V_90 = V_93 ;
V_83 . V_88 [ 7 ] . V_89 . V_94 = 1 ;
V_83 . V_88 [ 7 ] . V_89 . V_95 = 1 ;
V_83 . V_88 [ 7 ] . V_92 = 0x40 ;
V_83 . V_88 [ 8 ] . V_89 . V_90 = V_91 ;
V_83 . V_88 [ 8 ] . V_92 = 0x80 ;
V_83 . V_88 [ 9 ] . V_89 . V_90 = V_91 ;
V_83 . V_88 [ 9 ] . V_92 = 0x10 ;
V_83 . V_88 [ 10 ] . V_89 . V_90 = V_93 ;
V_83 . V_88 [ 10 ] . V_92 = 0x20 ;
V_83 . V_88 [ 11 ] . V_89 . V_90 = V_93 ;
V_83 . V_88 [ 11 ] . V_89 . V_94 = 1 ;
V_83 . V_88 [ 11 ] . V_89 . V_96 = 1 ;
V_83 . V_88 [ 11 ] . V_92 = 0x40 ;
V_83 . V_88 [ 12 ] . V_89 . V_90 = V_91 ;
V_83 . V_88 [ 12 ] . V_92 = 0x2a ;
V_83 . V_88 [ 13 ] . V_89 . V_90 = V_91 ;
V_83 . V_88 [ 13 ] . V_92 = 0x8e ;
V_83 . V_88 [ 14 ] . V_89 . V_90 = V_93 ;
V_83 . V_88 [ 14 ] . V_92 = 0 ;
V_83 . V_88 [ 15 ] . V_89 . V_90 = V_93 ;
V_83 . V_88 [ 15 ] . V_89 . V_94 = 1 ;
V_83 . V_88 [ 15 ] . V_89 . V_96 = 1 ;
V_83 . V_88 [ 15 ] . V_92 = 0x40 ;
return F_13 ( V_20 , V_97 , V_98 , ( T_1 * ) & V_83 , sizeof( V_83 ) , NULL , 0 ) ;
}
static int F_26 ( struct V_1 * V_20 , T_4 V_99 )
{
T_1 V_79 , V_81 ;
T_5 V_80 ;
T_6 V_100 , V_101 ;
V_99 /= 1000 ;
F_5 ( L_12 , V_99 ) ;
if ( V_99 <= 168000 )
V_79 = 0x1c ;
else if ( V_99 <= 378000 )
V_79 = 0x2c ;
else
V_79 = 0x30 ;
if ( V_99 >= 470000 ) {
V_99 -= 470001 ;
V_100 = 18805 ;
} else if ( V_99 >= 90000 ) {
V_99 -= 90001 ;
V_100 = 15005 ;
} else if ( V_99 >= 76000 ) {
V_99 -= 76001 ;
V_100 = 14865 ;
} else {
V_99 -= 54001 ;
V_100 = 14645 ;
}
V_101 = ( ( ( V_99 / 6000 ) * 60 + V_100 ) * 4 ) / 10 ;
V_80 = V_101 >> 6 ;
V_81 = V_101 & 0x3f ;
F_5 ( L_13 , V_79 , V_80 , V_81 ) ;
if ( V_80 >= 16 && V_80 <= 2047 )
return F_25 ( V_20 , V_79 , V_80 , V_81 ) ;
return - V_102 ;
}
static int F_27 ( struct V_55 * V_56 )
{
struct V_103 * V_83 = & V_56 -> V_104 ;
struct V_1 * V_20 = V_56 -> V_58 ;
struct V_105 V_34 ;
struct V_106 V_107 ;
int V_21 ;
memset ( & V_34 , 0 , sizeof( V_34 ) ) ;
switch ( V_83 -> V_108 ) {
case V_109 :
V_34 . V_110 . V_111 = 0x1 ;
V_34 . V_112 . V_113 = 0x1 ;
V_34 . V_112 . V_114 = 0x1 ;
break;
case V_115 :
V_34 . V_110 . V_111 = 0x2 ;
V_34 . V_112 . V_113 = 0x2 ;
V_34 . V_112 . V_114 = 0x1 ;
break;
#if 0
case QAM_256:
cmd.ACQUIRE0.MODE = 0x3;
break;
case QAM_128:
cmd.ACQUIRE0.MODE = 0x4;
break;
case QAM_64:
cmd.ACQUIRE0.MODE = 0x5;
break;
case QAM_32:
cmd.ACQUIRE0.MODE = 0x6;
break;
case QAM_16:
cmd.ACQUIRE0.MODE = 0x7;
break;
#endif
case V_116 :
V_34 . V_110 . V_111 = 0x8 ;
V_34 . V_112 . V_113 = 0x0 ;
V_34 . V_112 . V_114 = 0x0 ;
break;
case V_117 :
V_34 . V_110 . V_111 = 0x9 ;
V_34 . V_112 . V_113 = 0x0 ;
V_34 . V_112 . V_114 = 0x0 ;
default:
return - V_102 ;
} ;
V_34 . V_110 . V_118 = 0 ;
V_34 . V_110 . V_119 = 1 ;
V_34 . V_110 . V_120 = 1 ;
V_34 . V_110 . V_121 = 0 ;
F_13 ( V_20 , V_122 , V_123 , ( T_1 * ) & V_34 , sizeof( V_34 ) , NULL , 0 ) ;
V_107 . V_124 = 0 ;
V_107 . V_125 = 0 ;
F_13 ( V_20 , V_126 , V_127 , ( T_1 * ) & V_107 , sizeof( V_107 ) , NULL , 0 ) ;
F_13 ( V_20 , V_126 , V_128 , ( T_1 * ) & V_107 , sizeof( V_107 ) , NULL , 0 ) ;
F_17 ( V_20 ) ;
V_21 = F_26 ( V_20 , V_83 -> V_129 ) ;
if ( V_21 < 0 )
return V_21 ;
memset ( & V_20 -> V_51 , 0 , sizeof( V_20 -> V_51 ) ) ;
memset ( & V_20 -> V_53 , 0 , sizeof( V_20 -> V_53 ) ) ;
V_20 -> V_54 = 500 ;
F_12 ( 200 ) ;
return 0 ;
}
static int F_28 ( struct V_55 * V_56 )
{
return 0 ;
}
static int F_29 ( struct V_55 * V_56 , struct V_130 * V_131 )
{
V_131 -> V_132 = 1000 ;
V_131 -> V_133 = 0 ;
V_131 -> V_134 = 0 ;
return 0 ;
}
static void F_30 ( struct V_55 * V_56 )
{
struct V_1 * V_2 = V_56 -> V_58 ;
F_31 ( V_2 ) ;
}
static int F_32 ( struct V_1 * V_20 , T_5 V_10 , const T_1 * V_6 ,
T_5 V_5 )
{
int V_21 = 0 , V_22 ;
T_2 V_135 , V_136 , V_137 ;
V_135 . V_138 = V_10 >> 8 ;
V_136 . V_139 = V_10 ;
if ( ( V_21 = F_7 ( V_20 , 0xa9 , V_135 ) ) < 0 ) return V_21 ;
if ( ( V_21 = F_7 ( V_20 , 0xaa , V_136 ) ) < 0 ) return V_21 ;
for ( V_22 = 0 ; V_22 < V_5 ; V_22 ++ ) {
V_137 . V_140 = V_6 [ V_22 ] ;
if ( ( V_21 = F_7 ( V_20 , 0xab , V_137 ) ) < 0 )
return V_21 ;
}
return 0 ;
}
static int F_33 ( struct V_55 * V_56 )
{
struct V_1 * V_20 = V_56 -> V_58 ;
const struct V_141 * V_142 ;
T_5 V_10 , V_5 ;
const T_1 * V_6 ;
int V_21 , V_22 ;
F_5 ( L_14 ) ;
if ( ( V_21 = V_20 -> V_11 -> V_143 ( V_56 , & V_142 , V_144 ) ) < 0 ) {
V_7 ( L_15 , V_144 , V_21 ) ;
return V_21 ;
}
F_5 ( L_16 , V_142 -> V_90 ) ;
V_6 = V_142 -> V_92 ;
for ( V_22 = 0 ; V_22 < V_142 -> V_90 ; ) {
V_10 = F_34 ( * ( ( T_5 * ) & V_6 [ V_22 ] ) ) ;
V_5 = F_34 ( * ( ( T_5 * ) & V_6 [ V_22 + 2 ] ) ) ;
F_5 ( L_17 , V_10 , V_5 , V_142 -> V_90 ) ;
if ( ( V_21 = F_32 ( V_20 , V_10 , & V_6 [ V_22 + 4 ] , V_5 ) ) < 0 ) {
V_7 ( L_18 , V_21 ) ;
return V_21 ;
}
V_22 += 4 + V_5 ;
}
F_35 ( V_142 ) ;
F_5 ( L_19 ) ;
return 0 ;
}
static int F_36 ( struct V_1 * V_20 )
{
struct V_145 V_146 ;
F_13 ( V_20 , V_147 , V_148 , NULL , 0 , ( T_1 * ) & V_146 , sizeof( V_146 ) ) ;
F_5 ( L_20 ,
V_146 . V_149 , V_146 . V_150 , V_146 . V_151 , V_146 . V_152 ) ;
if ( V_146 . V_150 == V_153 &&
V_146 . V_151 == V_154 &&
V_146 . V_152 == V_155 )
return 0 ;
F_5 ( L_21 ) ;
return - V_156 ;
}
static int F_37 ( struct V_1 * V_20 )
{
int V_21 ;
unsigned long V_27 ;
T_2 V_18 ;
F_8 ( V_20 , 0xa0 , & V_18 ) ; V_18 . V_157 . V_158 = 1 ;
if ( ( V_21 = F_7 ( V_20 , 0xa0 , V_18 ) ) < 0 )
return V_21 ;
V_27 = V_31 + 3 * V_32 ;
while ( F_11 ( V_31 , V_27 ) ) {
F_12 ( 10 ) ;
if ( ( V_21 = F_8 ( V_20 , 0xa2 , & V_18 ) ) < 0 )
return V_21 ;
if ( V_18 . V_159 . V_158 )
return 0 ;
}
F_5 ( L_22 ) ;
return - V_33 ;
}
static int F_38 ( struct V_1 * V_20 )
{
T_2 V_18 ;
int V_21 ;
unsigned long V_27 ;
V_18 . V_19 = 0 ;
if ( ( V_21 = F_7 ( V_20 , 0xa0 , V_18 ) ) < 0 )
return V_21 ;
V_27 = V_31 + 3 * V_32 ;
while ( F_11 ( V_31 , V_27 ) ) {
F_12 ( 10 ) ;
if ( ( V_21 = F_8 ( V_20 , 0xa2 , & V_18 ) ) < 0 )
return V_21 ;
if ( ! V_18 . V_159 . V_158 )
return 0 ;
}
F_5 ( L_23 ) ;
return - V_33 ;
}
static int F_39 ( struct V_1 * V_20 )
{
int V_21 ;
T_2 V_18 ;
if ( ( V_21 = F_8 ( V_20 , 0xa2 , & V_18 ) ) < 0 )
return V_21 ;
if ( V_18 . V_159 . V_160 ) {
F_5 ( L_24 ) ;
return 0 ;
}
F_5 ( L_25 ) ;
if ( ( V_21 = F_37 ( V_20 ) ) < 0 )
return V_21 ;
F_5 ( L_26 ) ;
V_18 . V_161 . V_162 = 0 ;
if ( ( V_21 = F_7 ( V_20 , 0x2e , V_18 ) ) < 0 )
return V_21 ;
F_5 ( L_27 ) ;
if ( ( V_21 = F_33 ( & V_20 -> V_163 ) ) < 0 ||
( V_21 = F_38 ( V_20 ) ) < 0 )
return V_21 ;
return 0 ;
}
static int F_40 ( struct V_55 * V_56 )
{
struct V_1 * V_20 = V_56 -> V_58 ;
T_2 V_164 ;
struct V_165 V_83 ;
int V_21 ;
if ( ( V_21 = F_8 ( V_20 , 0xca , & V_164 ) ) < 0 )
return V_21 ;
F_5 ( L_28 , V_164 . V_19 ) ;
switch ( V_164 . V_166 . V_167 ) {
case V_168 :
F_5 ( L_29 ) ;
if ( ( V_21 = F_39 ( V_20 ) ) < 0 )
return V_21 ;
case V_169 :
F_5 ( L_30 ) ;
F_36 ( V_20 ) ;
break;
default:
return - V_156 ;
}
memset ( & V_83 , 0 , 1 ) ;
V_83 . V_170 = 1 ;
F_13 ( V_20 , V_171 , V_172 , ( T_1 * ) & V_83 , sizeof( V_83 ) , NULL , 0 ) ;
return 0 ;
}
struct V_55 * F_41 ( const struct V_173 * V_11 ,
struct V_174 * V_14 )
{
struct V_1 * V_2 = NULL ;
int V_21 ;
T_2 V_18 ;
V_2 = F_42 ( sizeof( struct V_1 ) , V_175 ) ;
if ( V_2 == NULL )
goto error;
V_2 -> V_11 = V_11 ;
V_2 -> V_14 = V_14 ;
memcpy ( & V_2 -> V_163 . V_176 , & V_177 , sizeof( struct V_178 ) ) ;
V_2 -> V_163 . V_58 = V_2 ;
F_43 ( & V_2 -> V_42 ) ;
if ( ( V_21 = F_8 ( V_2 , 0xe0 , & V_18 ) ) < 0 )
goto error;
F_5 ( L_31 , V_18 . V_179 . V_180 , V_18 . V_179 . V_181 ) ;
if ( ( V_18 . V_179 . V_180 != 0x1 && V_18 . V_179 . V_181 != 0xb ) &&
( V_18 . V_179 . V_180 != 0x8 && V_18 . V_179 . V_181 != 0x0 ) )
goto error;
F_44 ( L_32 , V_18 . V_179 . V_180 , V_18 . V_179 . V_181 ) ;
F_37 ( V_2 ) ;
return & V_2 -> V_163 ;
error:
F_31 ( V_2 ) ;
return NULL ;
}
