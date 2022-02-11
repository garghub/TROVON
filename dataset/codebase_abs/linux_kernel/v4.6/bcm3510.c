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
static int F_20 ( struct V_57 * V_58 , enum V_59 * V_60 )
{
struct V_1 * V_20 = V_58 -> V_61 ;
F_18 ( V_20 ) ;
* V_60 = 0 ;
if ( V_20 -> V_53 . V_62 . V_63 )
* V_60 |= V_64 | V_65 ;
if ( V_20 -> V_53 . V_62 . V_66 )
* V_60 |= V_67 ;
if ( V_20 -> V_53 . V_62 . V_68 )
* V_60 |= V_69 | V_70 ;
if ( * V_60 & V_64 )
V_20 -> V_56 = 1500 ;
else
V_20 -> V_56 = 500 ;
F_5 ( L_13 , * V_60 ) ;
return 0 ;
}
static int F_21 ( struct V_57 * V_58 , T_3 * V_71 )
{
struct V_1 * V_20 = V_58 -> V_61 ;
F_18 ( V_20 ) ;
* V_71 = ( V_20 -> V_55 . V_72 << 16 ) | ( V_20 -> V_55 . V_73 << 8 ) | V_20 -> V_55 . V_74 ;
return 0 ;
}
static int F_22 ( struct V_57 * V_58 , T_3 * V_75 )
{
struct V_1 * V_20 = V_58 -> V_61 ;
F_18 ( V_20 ) ;
* V_75 = ( V_20 -> V_55 . V_76 << 8 ) | V_20 -> V_55 . V_77 ;
return 0 ;
}
static int F_23 ( struct V_57 * V_58 , T_4 * V_78 )
{
struct V_1 * V_20 = V_58 -> V_61 ;
T_5 V_27 ;
F_18 ( V_20 ) ;
V_27 = V_20 -> V_55 . SIGNAL ;
if ( V_27 > 190 )
V_27 = 190 ;
if ( V_27 < 90 )
V_27 = 90 ;
V_27 -= 90 ;
V_27 = V_27 * 0xff / 100 ;
* V_78 = ( V_27 << 8 ) | V_27 ;
return 0 ;
}
static int F_24 ( struct V_57 * V_58 , T_4 * V_79 )
{
struct V_1 * V_20 = V_58 -> V_61 ;
F_18 ( V_20 ) ;
* V_79 = V_20 -> V_53 . V_80 * 1000 + ( ( V_20 -> V_53 . V_81 * 1000 ) >> 8 ) ;
return 0 ;
}
static int F_25 ( struct V_1 * V_20 , T_1 V_82 , T_4 V_83 , T_1 V_84 )
{
struct V_85 V_86 ;
memset ( & V_86 , 0 , sizeof( struct V_85 ) ) ;
V_86 . V_87 = 0x10 ;
V_86 . V_88 = 0 ;
V_86 . V_89 = 0x10 ;
V_86 . V_90 = 0x40 ;
V_86 . V_91 [ 0 ] . V_92 . V_93 = V_94 ;
V_86 . V_91 [ 0 ] . V_95 = 0x80 | V_82 ;
V_86 . V_91 [ 1 ] . V_92 . V_93 = V_94 ;
V_86 . V_91 [ 1 ] . V_95 = 4 ;
V_86 . V_91 [ 2 ] . V_92 . V_93 = V_96 ;
V_86 . V_91 [ 2 ] . V_95 = 0x20 ;
V_86 . V_91 [ 3 ] . V_92 . V_93 = V_96 ;
V_86 . V_91 [ 3 ] . V_92 . V_97 = 1 ;
V_86 . V_91 [ 3 ] . V_92 . V_98 = 1 ;
V_86 . V_91 [ 3 ] . V_95 = 0x40 ;
V_86 . V_91 [ 4 ] . V_92 . V_93 = V_94 ;
V_86 . V_91 [ 4 ] . V_95 = V_83 >> 3 ;
V_86 . V_91 [ 5 ] . V_92 . V_93 = V_94 ;
V_86 . V_91 [ 5 ] . V_95 = ( ( V_83 & 0x7 ) << 5 ) | ( V_84 >> 2 ) ;
V_86 . V_91 [ 6 ] . V_92 . V_93 = V_96 ;
V_86 . V_91 [ 6 ] . V_95 = ( V_84 << 6 ) & 0xdf ;
V_86 . V_91 [ 7 ] . V_92 . V_93 = V_96 ;
V_86 . V_91 [ 7 ] . V_92 . V_97 = 1 ;
V_86 . V_91 [ 7 ] . V_92 . V_98 = 1 ;
V_86 . V_91 [ 7 ] . V_95 = 0x40 ;
V_86 . V_91 [ 8 ] . V_92 . V_93 = V_94 ;
V_86 . V_91 [ 8 ] . V_95 = 0x80 ;
V_86 . V_91 [ 9 ] . V_92 . V_93 = V_94 ;
V_86 . V_91 [ 9 ] . V_95 = 0x10 ;
V_86 . V_91 [ 10 ] . V_92 . V_93 = V_96 ;
V_86 . V_91 [ 10 ] . V_95 = 0x20 ;
V_86 . V_91 [ 11 ] . V_92 . V_93 = V_96 ;
V_86 . V_91 [ 11 ] . V_92 . V_97 = 1 ;
V_86 . V_91 [ 11 ] . V_92 . V_99 = 1 ;
V_86 . V_91 [ 11 ] . V_95 = 0x40 ;
V_86 . V_91 [ 12 ] . V_92 . V_93 = V_94 ;
V_86 . V_91 [ 12 ] . V_95 = 0x2a ;
V_86 . V_91 [ 13 ] . V_92 . V_93 = V_94 ;
V_86 . V_91 [ 13 ] . V_95 = 0x8e ;
V_86 . V_91 [ 14 ] . V_92 . V_93 = V_96 ;
V_86 . V_91 [ 14 ] . V_95 = 0 ;
V_86 . V_91 [ 15 ] . V_92 . V_93 = V_96 ;
V_86 . V_91 [ 15 ] . V_92 . V_97 = 1 ;
V_86 . V_91 [ 15 ] . V_92 . V_99 = 1 ;
V_86 . V_91 [ 15 ] . V_95 = 0x40 ;
return F_13 ( V_20 , V_100 , V_101 , ( T_1 * ) & V_86 , sizeof( V_86 ) , NULL , 0 ) ;
}
static int F_26 ( struct V_1 * V_20 , T_3 V_102 )
{
T_1 V_82 , V_84 ;
T_4 V_83 ;
T_5 V_103 , V_104 ;
V_102 /= 1000 ;
F_5 ( L_14 , V_102 ) ;
if ( V_102 <= 168000 )
V_82 = 0x1c ;
else if ( V_102 <= 378000 )
V_82 = 0x2c ;
else
V_82 = 0x30 ;
if ( V_102 >= 470000 ) {
V_102 -= 470001 ;
V_103 = 18805 ;
} else if ( V_102 >= 90000 ) {
V_102 -= 90001 ;
V_103 = 15005 ;
} else if ( V_102 >= 76000 ) {
V_102 -= 76001 ;
V_103 = 14865 ;
} else {
V_102 -= 54001 ;
V_103 = 14645 ;
}
V_104 = ( ( ( V_102 / 6000 ) * 60 + V_103 ) * 4 ) / 10 ;
V_83 = V_104 >> 6 ;
V_84 = V_104 & 0x3f ;
F_5 ( L_15 , V_82 , V_83 , V_84 ) ;
if ( V_83 >= 16 && V_83 <= 2047 )
return F_25 ( V_20 , V_82 , V_83 , V_84 ) ;
return - V_43 ;
}
static int F_27 ( struct V_57 * V_58 )
{
struct V_105 * V_86 = & V_58 -> V_106 ;
struct V_1 * V_20 = V_58 -> V_61 ;
struct V_107 V_34 ;
struct V_108 V_109 ;
int V_21 ;
memset ( & V_34 , 0 , sizeof( V_34 ) ) ;
switch ( V_86 -> V_110 ) {
case V_111 :
V_34 . V_112 . V_113 = 0x1 ;
V_34 . V_114 . V_115 = 0x1 ;
V_34 . V_114 . V_116 = 0x1 ;
break;
case V_117 :
V_34 . V_112 . V_113 = 0x2 ;
V_34 . V_114 . V_115 = 0x2 ;
V_34 . V_114 . V_116 = 0x1 ;
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
case V_118 :
V_34 . V_112 . V_113 = 0x8 ;
V_34 . V_114 . V_115 = 0x0 ;
V_34 . V_114 . V_116 = 0x0 ;
break;
case V_119 :
V_34 . V_112 . V_113 = 0x9 ;
V_34 . V_114 . V_115 = 0x0 ;
V_34 . V_114 . V_116 = 0x0 ;
default:
return - V_43 ;
}
V_34 . V_112 . V_120 = 0 ;
V_34 . V_112 . V_121 = 1 ;
V_34 . V_112 . V_122 = 1 ;
V_34 . V_112 . V_123 = 0 ;
F_13 ( V_20 , V_124 , V_125 , ( T_1 * ) & V_34 , sizeof( V_34 ) , NULL , 0 ) ;
V_109 . V_126 = 0 ;
V_109 . V_127 = 0 ;
F_13 ( V_20 , V_128 , V_129 , ( T_1 * ) & V_109 , sizeof( V_109 ) , NULL , 0 ) ;
F_13 ( V_20 , V_128 , V_130 , ( T_1 * ) & V_109 , sizeof( V_109 ) , NULL , 0 ) ;
F_17 ( V_20 ) ;
V_21 = F_26 ( V_20 , V_86 -> V_131 ) ;
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
static int F_29 ( struct V_57 * V_58 , struct V_132 * V_133 )
{
V_133 -> V_134 = 1000 ;
V_133 -> V_135 = 0 ;
V_133 -> V_136 = 0 ;
return 0 ;
}
static void F_30 ( struct V_57 * V_58 )
{
struct V_1 * V_2 = V_58 -> V_61 ;
F_31 ( V_2 ) ;
}
static int F_32 ( struct V_1 * V_20 , T_4 V_10 , const T_1 * V_6 ,
T_4 V_5 )
{
int V_21 = 0 , V_22 ;
T_2 V_137 , V_138 , V_139 ;
V_137 . V_140 = V_10 >> 8 ;
V_138 . V_141 = V_10 ;
if ( ( V_21 = F_7 ( V_20 , 0xa9 , V_137 ) ) < 0 ) return V_21 ;
if ( ( V_21 = F_7 ( V_20 , 0xaa , V_138 ) ) < 0 ) return V_21 ;
for ( V_22 = 0 ; V_22 < V_5 ; V_22 ++ ) {
V_139 . V_142 = V_6 [ V_22 ] ;
if ( ( V_21 = F_7 ( V_20 , 0xab , V_139 ) ) < 0 )
return V_21 ;
}
return 0 ;
}
static int F_33 ( struct V_57 * V_58 )
{
struct V_1 * V_20 = V_58 -> V_61 ;
const struct V_143 * V_144 ;
T_4 V_10 , V_5 ;
const T_1 * V_6 ;
int V_21 , V_22 ;
F_5 ( L_16 ) ;
if ( ( V_21 = V_20 -> V_11 -> V_145 ( V_58 , & V_144 , V_146 ) ) < 0 ) {
V_7 ( L_17 , V_146 , V_21 ) ;
return V_21 ;
}
F_5 ( L_18 , V_144 -> V_93 ) ;
V_6 = V_144 -> V_95 ;
for ( V_22 = 0 ; V_22 < V_144 -> V_93 ; ) {
V_10 = F_34 ( * ( ( V_147 * ) & V_6 [ V_22 ] ) ) ;
V_5 = F_34 ( * ( ( V_147 * ) & V_6 [ V_22 + 2 ] ) ) ;
F_5 ( L_19 , V_10 , V_5 , V_144 -> V_93 ) ;
if ( ( V_21 = F_32 ( V_20 , V_10 , & V_6 [ V_22 + 4 ] , V_5 ) ) < 0 ) {
V_7 ( L_20 , V_21 ) ;
return V_21 ;
}
V_22 += 4 + V_5 ;
}
F_35 ( V_144 ) ;
F_5 ( L_21 ) ;
return 0 ;
}
static int F_36 ( struct V_1 * V_20 )
{
struct V_148 V_149 ;
F_13 ( V_20 , V_150 , V_151 , NULL , 0 , ( T_1 * ) & V_149 , sizeof( V_149 ) ) ;
F_5 ( L_22 ,
V_149 . V_152 , V_149 . V_153 , V_149 . V_154 , V_149 . V_155 ) ;
if ( V_149 . V_153 == V_156 &&
V_149 . V_154 == V_157 &&
V_149 . V_155 == V_158 )
return 0 ;
F_5 ( L_23 ) ;
return - V_159 ;
}
static int F_37 ( struct V_1 * V_20 )
{
int V_21 ;
unsigned long V_27 ;
T_2 V_18 ;
F_8 ( V_20 , 0xa0 , & V_18 ) ; V_18 . V_160 . V_161 = 1 ;
if ( ( V_21 = F_7 ( V_20 , 0xa0 , V_18 ) ) < 0 )
return V_21 ;
V_27 = V_31 + 3 * V_32 ;
while ( F_11 ( V_31 , V_27 ) ) {
F_12 ( 10 ) ;
if ( ( V_21 = F_8 ( V_20 , 0xa2 , & V_18 ) ) < 0 )
return V_21 ;
if ( V_18 . V_162 . V_161 )
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
if ( ! V_18 . V_162 . V_161 )
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
if ( V_18 . V_162 . V_163 ) {
F_5 ( L_26 ) ;
return 0 ;
}
F_5 ( L_27 ) ;
if ( ( V_21 = F_37 ( V_20 ) ) < 0 )
return V_21 ;
F_5 ( L_28 ) ;
V_18 . V_164 . V_165 = 0 ;
if ( ( V_21 = F_7 ( V_20 , 0x2e , V_18 ) ) < 0 )
return V_21 ;
F_5 ( L_29 ) ;
if ( ( V_21 = F_33 ( & V_20 -> V_166 ) ) < 0 ||
( V_21 = F_38 ( V_20 ) ) < 0 )
return V_21 ;
return 0 ;
}
static int F_40 ( struct V_57 * V_58 )
{
struct V_1 * V_20 = V_58 -> V_61 ;
T_2 V_167 ;
struct V_168 V_86 ;
int V_21 ;
if ( ( V_21 = F_8 ( V_20 , 0xca , & V_167 ) ) < 0 )
return V_21 ;
F_5 ( L_30 , V_167 . V_19 ) ;
switch ( V_167 . V_169 . V_170 ) {
case V_171 :
F_5 ( L_31 ) ;
if ( ( V_21 = F_39 ( V_20 ) ) < 0 )
return V_21 ;
case V_172 :
F_5 ( L_32 ) ;
F_36 ( V_20 ) ;
break;
default:
return - V_159 ;
}
memset ( & V_86 , 0 , 1 ) ;
V_86 . V_173 = 1 ;
F_13 ( V_20 , V_174 , V_175 , ( T_1 * ) & V_86 , sizeof( V_86 ) , NULL , 0 ) ;
return 0 ;
}
struct V_57 * F_41 ( const struct V_176 * V_11 ,
struct V_177 * V_14 )
{
struct V_1 * V_2 = NULL ;
int V_21 ;
T_2 V_18 ;
V_2 = F_42 ( sizeof( struct V_1 ) , V_178 ) ;
if ( V_2 == NULL )
goto error;
V_2 -> V_11 = V_11 ;
V_2 -> V_14 = V_14 ;
memcpy ( & V_2 -> V_166 . V_179 , & V_180 , sizeof( struct V_181 ) ) ;
V_2 -> V_166 . V_61 = V_2 ;
F_43 ( & V_2 -> V_44 ) ;
if ( ( V_21 = F_8 ( V_2 , 0xe0 , & V_18 ) ) < 0 )
goto error;
F_5 ( L_33 , V_18 . V_182 . V_183 , V_18 . V_182 . V_184 ) ;
if ( ( V_18 . V_182 . V_183 != 0x1 && V_18 . V_182 . V_184 != 0xb ) &&
( V_18 . V_182 . V_183 != 0x8 && V_18 . V_182 . V_184 != 0x0 ) )
goto error;
F_44 ( L_34 , V_18 . V_182 . V_183 , V_18 . V_182 . V_184 ) ;
F_37 ( V_2 ) ;
return & V_2 -> V_166 ;
error:
F_31 ( V_2 ) ;
return NULL ;
}
