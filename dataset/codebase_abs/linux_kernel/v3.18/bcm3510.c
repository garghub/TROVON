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
T_1 V_40 [ V_41 ] , V_42 [ V_41 ] ;
int V_21 = 0 ;
if ( V_39 + 2 > sizeof( V_42 ) ) {
F_14 ( L_9 , V_39 ) ;
return - V_43 ;
}
if ( V_37 + 2 > sizeof( V_40 ) ) {
F_14 ( L_10 , V_37 ) ;
return - V_43 ;
}
V_40 [ 0 ] = V_34 ;
V_40 [ 1 ] = V_35 ;
memcpy ( & V_40 [ 2 ] , V_36 , V_37 ) ;
F_14 ( L_11 ) ;
F_3 ( V_40 , V_37 + 2 , F_14 ) ;
F_14 ( L_2 ) ;
if ( F_15 ( & V_20 -> V_44 ) < 0 )
return - V_45 ;
if ( ( V_21 = F_10 ( V_20 , V_40 , V_37 + 2 ) ) < 0 ||
( V_21 = F_9 ( V_20 , V_42 , V_39 + 2 ) ) < 0 )
goto error;
F_14 ( L_12 ) ;
F_3 ( V_42 , V_39 + 2 , F_14 ) ;
F_14 ( L_2 ) ;
memcpy ( V_38 , & V_42 [ 2 ] , V_39 ) ;
error:
F_16 ( & V_20 -> V_44 ) ;
return V_21 ;
}
static int F_17 ( struct V_1 * V_20 )
{
T_2 V_6 ;
int V_21 ;
if ( ( V_21 = F_8 ( V_20 , 0xfa , & V_6 ) ) < 0 )
return V_21 ;
V_6 . V_46 . V_47 = 0 ; F_7 ( V_20 , 0xfa , V_6 ) ;
V_6 . V_46 . V_47 = 1 ; F_7 ( V_20 , 0xfa , V_6 ) ;
V_6 . V_46 . V_47 = 0 ; F_7 ( V_20 , 0xfa , V_6 ) ;
V_6 . V_46 . V_48 = 1 ; V_6 . V_46 . V_49 = 1 ; F_7 ( V_20 , 0xfa , V_6 ) ;
return 0 ;
}
static int F_18 ( struct V_1 * V_20 )
{
if ( F_19 ( V_31 , V_20 -> V_50 ) ) {
F_13 ( V_20 , V_51 , V_52 , NULL , 0 , ( T_1 * ) & V_20 -> V_53 , sizeof( V_20 -> V_53 ) ) ;
F_13 ( V_20 , V_51 , V_54 , NULL , 0 , ( T_1 * ) & V_20 -> V_55 , sizeof( V_20 -> V_55 ) ) ;
V_20 -> V_50 = V_31 + ( V_20 -> V_56 * V_32 ) / 1000 ;
}
return 0 ;
}
static int F_20 ( struct V_57 * V_58 , T_3 * V_59 )
{
struct V_1 * V_20 = V_58 -> V_60 ;
F_18 ( V_20 ) ;
* V_59 = 0 ;
if ( V_20 -> V_53 . V_61 . V_62 )
* V_59 |= V_63 | V_64 ;
if ( V_20 -> V_53 . V_61 . V_65 )
* V_59 |= V_66 ;
if ( V_20 -> V_53 . V_61 . V_67 )
* V_59 |= V_68 | V_69 ;
if ( * V_59 & V_63 )
V_20 -> V_56 = 1500 ;
else
V_20 -> V_56 = 500 ;
F_5 ( L_13 , * V_59 ) ;
return 0 ;
}
static int F_21 ( struct V_57 * V_58 , T_4 * V_70 )
{
struct V_1 * V_20 = V_58 -> V_60 ;
F_18 ( V_20 ) ;
* V_70 = ( V_20 -> V_55 . V_71 << 16 ) | ( V_20 -> V_55 . V_72 << 8 ) | V_20 -> V_55 . V_73 ;
return 0 ;
}
static int F_22 ( struct V_57 * V_58 , T_4 * V_74 )
{
struct V_1 * V_20 = V_58 -> V_60 ;
F_18 ( V_20 ) ;
* V_74 = ( V_20 -> V_55 . V_75 << 8 ) | V_20 -> V_55 . V_76 ;
return 0 ;
}
static int F_23 ( struct V_57 * V_58 , T_5 * V_77 )
{
struct V_1 * V_20 = V_58 -> V_60 ;
T_6 V_27 ;
F_18 ( V_20 ) ;
V_27 = V_20 -> V_55 . SIGNAL ;
if ( V_27 > 190 )
V_27 = 190 ;
if ( V_27 < 90 )
V_27 = 90 ;
V_27 -= 90 ;
V_27 = V_27 * 0xff / 100 ;
* V_77 = ( V_27 << 8 ) | V_27 ;
return 0 ;
}
static int F_24 ( struct V_57 * V_58 , T_5 * V_78 )
{
struct V_1 * V_20 = V_58 -> V_60 ;
F_18 ( V_20 ) ;
* V_78 = V_20 -> V_53 . V_79 * 1000 + ( ( V_20 -> V_53 . V_80 * 1000 ) >> 8 ) ;
return 0 ;
}
static int F_25 ( struct V_1 * V_20 , T_1 V_81 , T_5 V_82 , T_1 V_83 )
{
struct V_84 V_85 ;
memset ( & V_85 , 0 , sizeof( struct V_84 ) ) ;
V_85 . V_86 = 0x10 ;
V_85 . V_87 = 0 ;
V_85 . V_88 = 0x10 ;
V_85 . V_89 = 0x40 ;
V_85 . V_90 [ 0 ] . V_91 . V_92 = V_93 ;
V_85 . V_90 [ 0 ] . V_94 = 0x80 | V_81 ;
V_85 . V_90 [ 1 ] . V_91 . V_92 = V_93 ;
V_85 . V_90 [ 1 ] . V_94 = 4 ;
V_85 . V_90 [ 2 ] . V_91 . V_92 = V_95 ;
V_85 . V_90 [ 2 ] . V_94 = 0x20 ;
V_85 . V_90 [ 3 ] . V_91 . V_92 = V_95 ;
V_85 . V_90 [ 3 ] . V_91 . V_96 = 1 ;
V_85 . V_90 [ 3 ] . V_91 . V_97 = 1 ;
V_85 . V_90 [ 3 ] . V_94 = 0x40 ;
V_85 . V_90 [ 4 ] . V_91 . V_92 = V_93 ;
V_85 . V_90 [ 4 ] . V_94 = V_82 >> 3 ;
V_85 . V_90 [ 5 ] . V_91 . V_92 = V_93 ;
V_85 . V_90 [ 5 ] . V_94 = ( ( V_82 & 0x7 ) << 5 ) | ( V_83 >> 2 ) ;
V_85 . V_90 [ 6 ] . V_91 . V_92 = V_95 ;
V_85 . V_90 [ 6 ] . V_94 = ( V_83 << 6 ) & 0xdf ;
V_85 . V_90 [ 7 ] . V_91 . V_92 = V_95 ;
V_85 . V_90 [ 7 ] . V_91 . V_96 = 1 ;
V_85 . V_90 [ 7 ] . V_91 . V_97 = 1 ;
V_85 . V_90 [ 7 ] . V_94 = 0x40 ;
V_85 . V_90 [ 8 ] . V_91 . V_92 = V_93 ;
V_85 . V_90 [ 8 ] . V_94 = 0x80 ;
V_85 . V_90 [ 9 ] . V_91 . V_92 = V_93 ;
V_85 . V_90 [ 9 ] . V_94 = 0x10 ;
V_85 . V_90 [ 10 ] . V_91 . V_92 = V_95 ;
V_85 . V_90 [ 10 ] . V_94 = 0x20 ;
V_85 . V_90 [ 11 ] . V_91 . V_92 = V_95 ;
V_85 . V_90 [ 11 ] . V_91 . V_96 = 1 ;
V_85 . V_90 [ 11 ] . V_91 . V_98 = 1 ;
V_85 . V_90 [ 11 ] . V_94 = 0x40 ;
V_85 . V_90 [ 12 ] . V_91 . V_92 = V_93 ;
V_85 . V_90 [ 12 ] . V_94 = 0x2a ;
V_85 . V_90 [ 13 ] . V_91 . V_92 = V_93 ;
V_85 . V_90 [ 13 ] . V_94 = 0x8e ;
V_85 . V_90 [ 14 ] . V_91 . V_92 = V_95 ;
V_85 . V_90 [ 14 ] . V_94 = 0 ;
V_85 . V_90 [ 15 ] . V_91 . V_92 = V_95 ;
V_85 . V_90 [ 15 ] . V_91 . V_96 = 1 ;
V_85 . V_90 [ 15 ] . V_91 . V_98 = 1 ;
V_85 . V_90 [ 15 ] . V_94 = 0x40 ;
return F_13 ( V_20 , V_99 , V_100 , ( T_1 * ) & V_85 , sizeof( V_85 ) , NULL , 0 ) ;
}
static int F_26 ( struct V_1 * V_20 , T_4 V_101 )
{
T_1 V_81 , V_83 ;
T_5 V_82 ;
T_6 V_102 , V_103 ;
V_101 /= 1000 ;
F_5 ( L_14 , V_101 ) ;
if ( V_101 <= 168000 )
V_81 = 0x1c ;
else if ( V_101 <= 378000 )
V_81 = 0x2c ;
else
V_81 = 0x30 ;
if ( V_101 >= 470000 ) {
V_101 -= 470001 ;
V_102 = 18805 ;
} else if ( V_101 >= 90000 ) {
V_101 -= 90001 ;
V_102 = 15005 ;
} else if ( V_101 >= 76000 ) {
V_101 -= 76001 ;
V_102 = 14865 ;
} else {
V_101 -= 54001 ;
V_102 = 14645 ;
}
V_103 = ( ( ( V_101 / 6000 ) * 60 + V_102 ) * 4 ) / 10 ;
V_82 = V_103 >> 6 ;
V_83 = V_103 & 0x3f ;
F_5 ( L_15 , V_81 , V_82 , V_83 ) ;
if ( V_82 >= 16 && V_82 <= 2047 )
return F_25 ( V_20 , V_81 , V_82 , V_83 ) ;
return - V_43 ;
}
static int F_27 ( struct V_57 * V_58 )
{
struct V_104 * V_85 = & V_58 -> V_105 ;
struct V_1 * V_20 = V_58 -> V_60 ;
struct V_106 V_34 ;
struct V_107 V_108 ;
int V_21 ;
memset ( & V_34 , 0 , sizeof( V_34 ) ) ;
switch ( V_85 -> V_109 ) {
case V_110 :
V_34 . V_111 . V_112 = 0x1 ;
V_34 . V_113 . V_114 = 0x1 ;
V_34 . V_113 . V_115 = 0x1 ;
break;
case V_116 :
V_34 . V_111 . V_112 = 0x2 ;
V_34 . V_113 . V_114 = 0x2 ;
V_34 . V_113 . V_115 = 0x1 ;
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
case V_117 :
V_34 . V_111 . V_112 = 0x8 ;
V_34 . V_113 . V_114 = 0x0 ;
V_34 . V_113 . V_115 = 0x0 ;
break;
case V_118 :
V_34 . V_111 . V_112 = 0x9 ;
V_34 . V_113 . V_114 = 0x0 ;
V_34 . V_113 . V_115 = 0x0 ;
default:
return - V_43 ;
}
V_34 . V_111 . V_119 = 0 ;
V_34 . V_111 . V_120 = 1 ;
V_34 . V_111 . V_121 = 1 ;
V_34 . V_111 . V_122 = 0 ;
F_13 ( V_20 , V_123 , V_124 , ( T_1 * ) & V_34 , sizeof( V_34 ) , NULL , 0 ) ;
V_108 . V_125 = 0 ;
V_108 . V_126 = 0 ;
F_13 ( V_20 , V_127 , V_128 , ( T_1 * ) & V_108 , sizeof( V_108 ) , NULL , 0 ) ;
F_13 ( V_20 , V_127 , V_129 , ( T_1 * ) & V_108 , sizeof( V_108 ) , NULL , 0 ) ;
F_17 ( V_20 ) ;
V_21 = F_26 ( V_20 , V_85 -> V_130 ) ;
if ( V_21 < 0 )
return V_21 ;
memset ( & V_20 -> V_53 , 0 , sizeof( V_20 -> V_53 ) ) ;
memset ( & V_20 -> V_55 , 0 , sizeof( V_20 -> V_55 ) ) ;
V_20 -> V_56 = 500 ;
F_12 ( 200 ) ;
return 0 ;
}
static int F_28 ( struct V_57 * V_58 )
{
return 0 ;
}
static int F_29 ( struct V_57 * V_58 , struct V_131 * V_132 )
{
V_132 -> V_133 = 1000 ;
V_132 -> V_134 = 0 ;
V_132 -> V_135 = 0 ;
return 0 ;
}
static void F_30 ( struct V_57 * V_58 )
{
struct V_1 * V_2 = V_58 -> V_60 ;
F_31 ( V_2 ) ;
}
static int F_32 ( struct V_1 * V_20 , T_5 V_10 , const T_1 * V_6 ,
T_5 V_5 )
{
int V_21 = 0 , V_22 ;
T_2 V_136 , V_137 , V_138 ;
V_136 . V_139 = V_10 >> 8 ;
V_137 . V_140 = V_10 ;
if ( ( V_21 = F_7 ( V_20 , 0xa9 , V_136 ) ) < 0 ) return V_21 ;
if ( ( V_21 = F_7 ( V_20 , 0xaa , V_137 ) ) < 0 ) return V_21 ;
for ( V_22 = 0 ; V_22 < V_5 ; V_22 ++ ) {
V_138 . V_141 = V_6 [ V_22 ] ;
if ( ( V_21 = F_7 ( V_20 , 0xab , V_138 ) ) < 0 )
return V_21 ;
}
return 0 ;
}
static int F_33 ( struct V_57 * V_58 )
{
struct V_1 * V_20 = V_58 -> V_60 ;
const struct V_142 * V_143 ;
T_5 V_10 , V_5 ;
const T_1 * V_6 ;
int V_21 , V_22 ;
F_5 ( L_16 ) ;
if ( ( V_21 = V_20 -> V_11 -> V_144 ( V_58 , & V_143 , V_145 ) ) < 0 ) {
V_7 ( L_17 , V_145 , V_21 ) ;
return V_21 ;
}
F_5 ( L_18 , V_143 -> V_92 ) ;
V_6 = V_143 -> V_94 ;
for ( V_22 = 0 ; V_22 < V_143 -> V_92 ; ) {
V_10 = F_34 ( * ( ( V_146 * ) & V_6 [ V_22 ] ) ) ;
V_5 = F_34 ( * ( ( V_146 * ) & V_6 [ V_22 + 2 ] ) ) ;
F_5 ( L_19 , V_10 , V_5 , V_143 -> V_92 ) ;
if ( ( V_21 = F_32 ( V_20 , V_10 , & V_6 [ V_22 + 4 ] , V_5 ) ) < 0 ) {
V_7 ( L_20 , V_21 ) ;
return V_21 ;
}
V_22 += 4 + V_5 ;
}
F_35 ( V_143 ) ;
F_5 ( L_21 ) ;
return 0 ;
}
static int F_36 ( struct V_1 * V_20 )
{
struct V_147 V_148 ;
F_13 ( V_20 , V_149 , V_150 , NULL , 0 , ( T_1 * ) & V_148 , sizeof( V_148 ) ) ;
F_5 ( L_22 ,
V_148 . V_151 , V_148 . V_152 , V_148 . V_153 , V_148 . V_154 ) ;
if ( V_148 . V_152 == V_155 &&
V_148 . V_153 == V_156 &&
V_148 . V_154 == V_157 )
return 0 ;
F_5 ( L_23 ) ;
return - V_158 ;
}
static int F_37 ( struct V_1 * V_20 )
{
int V_21 ;
unsigned long V_27 ;
T_2 V_18 ;
F_8 ( V_20 , 0xa0 , & V_18 ) ; V_18 . V_159 . V_160 = 1 ;
if ( ( V_21 = F_7 ( V_20 , 0xa0 , V_18 ) ) < 0 )
return V_21 ;
V_27 = V_31 + 3 * V_32 ;
while ( F_11 ( V_31 , V_27 ) ) {
F_12 ( 10 ) ;
if ( ( V_21 = F_8 ( V_20 , 0xa2 , & V_18 ) ) < 0 )
return V_21 ;
if ( V_18 . V_161 . V_160 )
return 0 ;
}
F_5 ( L_24 ) ;
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
if ( ! V_18 . V_161 . V_160 )
return 0 ;
}
F_5 ( L_25 ) ;
return - V_33 ;
}
static int F_39 ( struct V_1 * V_20 )
{
int V_21 ;
T_2 V_18 ;
if ( ( V_21 = F_8 ( V_20 , 0xa2 , & V_18 ) ) < 0 )
return V_21 ;
if ( V_18 . V_161 . V_162 ) {
F_5 ( L_26 ) ;
return 0 ;
}
F_5 ( L_27 ) ;
if ( ( V_21 = F_37 ( V_20 ) ) < 0 )
return V_21 ;
F_5 ( L_28 ) ;
V_18 . V_163 . V_164 = 0 ;
if ( ( V_21 = F_7 ( V_20 , 0x2e , V_18 ) ) < 0 )
return V_21 ;
F_5 ( L_29 ) ;
if ( ( V_21 = F_33 ( & V_20 -> V_165 ) ) < 0 ||
( V_21 = F_38 ( V_20 ) ) < 0 )
return V_21 ;
return 0 ;
}
static int F_40 ( struct V_57 * V_58 )
{
struct V_1 * V_20 = V_58 -> V_60 ;
T_2 V_166 ;
struct V_167 V_85 ;
int V_21 ;
if ( ( V_21 = F_8 ( V_20 , 0xca , & V_166 ) ) < 0 )
return V_21 ;
F_5 ( L_30 , V_166 . V_19 ) ;
switch ( V_166 . V_168 . V_169 ) {
case V_170 :
F_5 ( L_31 ) ;
if ( ( V_21 = F_39 ( V_20 ) ) < 0 )
return V_21 ;
case V_171 :
F_5 ( L_32 ) ;
F_36 ( V_20 ) ;
break;
default:
return - V_158 ;
}
memset ( & V_85 , 0 , 1 ) ;
V_85 . V_172 = 1 ;
F_13 ( V_20 , V_173 , V_174 , ( T_1 * ) & V_85 , sizeof( V_85 ) , NULL , 0 ) ;
return 0 ;
}
struct V_57 * F_41 ( const struct V_175 * V_11 ,
struct V_176 * V_14 )
{
struct V_1 * V_2 = NULL ;
int V_21 ;
T_2 V_18 ;
V_2 = F_42 ( sizeof( struct V_1 ) , V_177 ) ;
if ( V_2 == NULL )
goto error;
V_2 -> V_11 = V_11 ;
V_2 -> V_14 = V_14 ;
memcpy ( & V_2 -> V_165 . V_178 , & V_179 , sizeof( struct V_180 ) ) ;
V_2 -> V_165 . V_60 = V_2 ;
F_43 ( & V_2 -> V_44 ) ;
if ( ( V_21 = F_8 ( V_2 , 0xe0 , & V_18 ) ) < 0 )
goto error;
F_5 ( L_33 , V_18 . V_181 . V_182 , V_18 . V_181 . V_183 ) ;
if ( ( V_18 . V_181 . V_182 != 0x1 && V_18 . V_181 . V_183 != 0xb ) &&
( V_18 . V_181 . V_182 != 0x8 && V_18 . V_181 . V_183 != 0x0 ) )
goto error;
F_44 ( L_34 , V_18 . V_181 . V_182 , V_18 . V_181 . V_183 ) ;
F_37 ( V_2 ) ;
return & V_2 -> V_165 ;
error:
F_31 ( V_2 ) ;
return NULL ;
}
