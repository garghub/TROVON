static
int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_2 * V_4 , int V_5 )
{
T_2 V_6 [ V_7 ] ;
struct V_8 V_9 = {
. V_10 = V_2 -> V_11 -> V_12 ,
. V_13 = 0 ,
. V_6 = V_6 ,
. V_5 = V_5 + 2
} ;
int V_14 ;
if ( 2 + V_5 > sizeof( V_6 ) ) {
F_2 ( V_15
L_1 ,
V_16 , V_3 , V_5 ) ;
return - V_17 ;
}
V_6 [ 0 ] = F_3 ( V_3 ) ;
V_6 [ 1 ] = F_4 ( V_3 ) ;
memcpy ( V_6 + 2 , V_4 , V_5 ) ;
if ( V_18 )
F_2 ( V_19 L_2 , V_20 ,
V_2 -> V_11 -> V_12 , V_3 , V_6 [ 2 ] ) ;
V_14 = F_5 ( V_2 -> V_21 , & V_9 , 1 ) ;
if ( V_14 != 1 )
F_2 ( V_22 L_3 ,
V_20 , V_2 -> V_11 -> V_12 , V_3 , V_6 [ 2 ] ) ;
return ( V_14 != 1 ) ? - V_23 : 0 ;
}
static int F_6 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 )
{
return F_1 ( V_2 , V_3 , & V_4 , 1 ) ;
}
static T_2 F_7 ( struct V_1 * V_2 , T_1 V_3 )
{
T_2 V_24 [] = { 0 , 0 } ;
T_2 V_25 [] = { 0 } ;
struct V_8 V_9 [] = {
{
. V_10 = V_2 -> V_11 -> V_12 ,
. V_13 = 0 ,
. V_6 = V_24 ,
. V_5 = 2
} , {
. V_10 = V_2 -> V_11 -> V_12 ,
. V_13 = V_26 ,
. V_6 = V_25 ,
. V_5 = 1
}
} ;
int V_14 ;
V_24 [ 0 ] = F_3 ( V_3 ) ;
V_24 [ 1 ] = F_4 ( V_3 ) ;
V_14 = F_5 ( V_2 -> V_21 , V_9 , 2 ) ;
if ( V_14 != 2 )
F_2 ( V_22 L_4 ,
V_20 , V_2 -> V_11 -> V_12 , V_3 , V_25 [ 0 ] ) ;
if ( V_18 )
F_2 ( V_19 L_2 , V_20 ,
V_2 -> V_11 -> V_12 , V_3 , V_25 [ 0 ] ) ;
return V_25 [ 0 ] ;
}
static void F_8 ( T_3 V_27 , T_2 * V_28 , T_2 * V_29 )
{
T_2 V_30 = 0 , V_31 = 0 ;
( * V_28 ) = V_27 & 0xff ;
while ( ( V_30 == 0 ) && ( V_31 < 8 ) ) {
V_30 = ( ( * V_28 ) >> V_31 ) & 0x01 ;
V_31 ++ ;
}
( * V_29 ) = ( V_31 - 1 ) ;
}
static void F_9 ( struct V_1 * V_2 , T_3 V_27 , T_2 V_32 )
{
T_2 V_3 , V_28 , V_29 ;
V_3 = F_7 ( V_2 , ( V_27 >> 16 ) & 0xffff ) ;
F_8 ( V_27 , & V_28 , & V_29 ) ;
V_32 = V_28 & ( V_32 << V_29 ) ;
V_3 = ( V_3 & ( ~ V_28 ) ) | V_32 ;
F_6 ( V_2 , ( V_27 >> 16 ) & 0xffff , V_3 ) ;
}
static void F_10 ( T_2 * V_3 , T_3 V_27 , T_2 V_32 )
{
T_2 V_28 , V_29 ;
F_8 ( V_27 , & V_28 , & V_29 ) ;
V_32 = V_28 & ( V_32 << V_29 ) ;
( * V_3 ) = ( ( * V_3 ) & ( ~ V_28 ) ) | V_32 ;
}
static T_2 F_11 ( struct V_1 * V_2 , T_3 V_27 )
{
T_2 V_32 = 0xff ;
T_2 V_28 , V_29 ;
F_8 ( V_27 , & V_28 , & V_29 ) ;
V_32 = F_7 ( V_2 , V_27 >> 16 ) ;
V_32 = ( V_32 & V_28 ) >> V_29 ;
return V_32 ;
}
static void F_12 ( struct V_1 * V_2 ,
const struct V_33 * V_34 )
{
int V_31 = 0 ;
while ( 1 ) {
if ( ! V_34 [ V_31 ] . V_10 )
break;
F_6 ( V_2 , V_34 [ V_31 ] . V_10 , V_34 [ V_31 ] . V_35 ) ;
V_31 ++ ;
}
}
static void F_13 ( struct V_1 * V_2 ,
T_3 V_36 , T_3 V_37 )
{
switch ( V_36 ) {
case V_38 :
switch ( V_37 ) {
default:
case 27000000 :
F_14 ( L_5 ) ;
F_6 ( V_2 , V_39 , 0x1b ) ;
F_6 ( V_2 , V_40 , 0xe8 ) ;
break;
}
break;
default:
case V_41 :
switch ( V_37 ) {
case 16000000 :
F_6 ( V_2 , V_39 , 0x2 ) ;
F_6 ( V_2 , V_40 , 0x1b ) ;
break;
case 25000000 :
F_6 ( V_2 , V_39 , 0xa ) ;
F_6 ( V_2 , V_40 , 0x55 ) ;
break;
default:
case 27000000 :
F_14 ( L_6 ) ;
F_6 ( V_2 , V_39 , 0x1 ) ;
F_6 ( V_2 , V_40 , 0x8 ) ;
break;
case 30000000 :
F_6 ( V_2 , V_39 , 0xc ) ;
F_6 ( V_2 , V_40 , 0x55 ) ;
break;
}
}
F_6 ( V_2 , V_42 , 0x18 ) ;
}
static int F_15 ( struct V_1 * V_2 , T_3 * V_43 )
{
if ( V_2 -> V_44 && V_2 -> V_45 . V_46 . V_47 . V_48 ) {
V_2 -> V_45 . V_46 . V_47 . V_48 ( & V_2 -> V_45 , V_43 ) ;
* V_43 = * V_43 / 1000 ;
} else
* V_43 = V_2 -> V_11 -> V_49 ;
return 0 ;
}
static int F_16 ( struct V_50 * V_45 , int V_51 )
{
struct V_1 * V_2 = V_45 -> V_52 ;
T_2 V_53 = F_7 ( V_2 , V_54 ) ;
F_14 ( L_7 , V_20 ) ;
if ( V_51 ) {
F_10 ( & V_53 , V_55 , 0 ) ;
F_10 ( & V_53 , V_56 , 1 ) ;
} else {
F_10 ( & V_53 , V_55 , 1 ) ;
F_10 ( & V_53 , V_56 , 0 ) ;
}
F_6 ( V_2 , V_54 , V_53 ) ;
return 0 ;
}
static T_3 F_17 ( struct V_50 * V_45 )
{
struct V_57 * V_58 = & V_45 -> V_46 ;
struct V_59 * V_47 = & V_58 -> V_47 ;
T_3 V_60 = 0 ;
int V_61 = 0 ;
F_14 ( L_7 , V_20 ) ;
if ( V_47 -> V_62 ) {
V_61 = V_47 -> V_62 ( V_45 , & V_60 ) ;
if ( V_61 < 0 ) {
F_2 ( V_22 L_8 , V_20 ) ;
return V_61 ;
}
F_14 ( L_9 , V_20 , V_60 ) ;
} else
return - 1 ;
return V_60 ;
}
static T_3 F_18 ( struct V_1 * V_2 , T_3 V_63 )
{
T_3 V_64 = 0 ;
T_3 V_65 , V_66 , V_67 ;
F_14 ( L_7 , V_20 ) ;
if ( F_11 ( V_2 , V_68 ) == 0 ) {
V_66 = ( T_3 ) F_11 ( V_2 , V_69 ) ;
if ( V_66 == 0 )
V_66 = V_66 + 1 ;
V_65 = ( T_3 ) F_11 ( V_2 , V_70 ) ;
if ( V_65 == 0 )
V_65 = V_65 + 1 ;
V_67 = ( T_3 ) F_11 ( V_2 , V_71 ) ;
if ( V_67 > 5 )
V_67 = 5 ;
V_64 = ( ( V_63 / 2 ) * V_66 ) / ( V_65 * ( 1 << V_67 ) ) ;
F_14 ( L_10 ,
V_66 , V_65 , V_67 , V_64 , V_63 ) ;
} else
V_64 = V_63 ;
F_14 ( L_11 , V_20 , V_64 ) ;
return V_64 ;
}
static int F_19 ( struct V_1 * V_2 ,
T_1 V_72 [ 3 ] [ 6 ] [ 5 ] , T_3 V_73 )
{
int V_31 , V_74 , V_75 , V_60 ;
F_14 ( L_7 , V_20 ) ;
V_60 = F_18 ( V_2 , V_73 ) ;
if ( V_60 == 53125000 )
V_75 = 1 ;
else if ( V_60 == 54000000 )
V_75 = 0 ;
else if ( V_60 == 52500000 )
V_75 = 2 ;
else
return 0 ;
for ( V_31 = 1 ; V_31 <= 6 ; V_31 ++ ) {
F_9 ( V_2 , V_76 , V_31 - 1 ) ;
for ( V_74 = 1 ; V_74 <= 5 ; V_74 ++ ) {
F_6 ( V_2 ,
( V_77 + 2 * ( V_74 - 1 ) ) ,
F_3 ( V_72 [ V_75 ] [ V_31 - 1 ] [ V_74 - 1 ] ) ) ;
F_6 ( V_2 ,
( V_78 + 2 * ( V_74 - 1 ) ) ,
F_4 ( V_72 [ V_75 ] [ V_31 - 1 ] [ V_74 - 1 ] ) ) ;
}
}
return 1 ;
}
static void F_20 ( struct V_1 * V_2 )
{
F_14 ( L_7 , V_20 ) ;
F_9 ( V_2 , V_79 , 0x00 ) ;
F_9 ( V_2 , V_80 , 0x00 ) ;
F_9 ( V_2 , V_81 , 0x06 ) ;
F_9 ( V_2 , V_82 , 0x04 ) ;
F_9 ( V_2 , V_80 , 0x01 ) ;
F_9 ( V_2 , V_81 , 0x06 ) ;
F_9 ( V_2 , V_82 , 0x04 ) ;
F_9 ( V_2 , V_80 , 0x02 ) ;
F_9 ( V_2 , V_81 , 0x01 ) ;
F_9 ( V_2 , V_82 , 0x00 ) ;
F_9 ( V_2 , V_80 , 0x03 ) ;
F_9 ( V_2 , V_81 , 0x01 ) ;
F_9 ( V_2 , V_82 , 0x00 ) ;
}
static int F_21 ( struct V_1 * V_2 , T_2 V_83 ,
T_3 V_84 )
{
F_14 ( L_7 , V_20 ) ;
F_9 ( V_2 , V_85 , 0 ) ;
switch ( V_83 ) {
case 6 :
if ( ! F_19 ( V_2 ,
V_86 ,
V_84 ) )
return 0 ;
break;
case 7 :
if ( ! F_19 ( V_2 ,
V_87 ,
V_84 ) )
return 0 ;
break;
case 8 :
if ( ! F_19 ( V_2 ,
V_88 ,
V_84 ) )
return 0 ;
break;
default:
return 0 ;
}
F_9 ( V_2 , V_85 , 1 ) ;
return 1 ;
}
static void F_22 ( struct V_1 * V_2 )
{
T_2 V_89 ;
F_14 ( L_7 , V_20 ) ;
V_89 = F_11 ( V_2 , V_90 ) ;
F_9 ( V_2 , V_90 , 0x07 ) ;
F_9 ( V_2 , V_91 , 0x00 ) ;
F_9 ( V_2 , V_92 , 0x00 ) ;
F_9 ( V_2 , V_91 , 0x01 ) ;
F_9 ( V_2 , V_92 , 0x01 ) ;
F_9 ( V_2 , V_90 , V_89 ) ;
}
static int F_23 ( T_4 V_93 , int V_94 , int V_95 , int V_96 )
{
int V_97 = 0 ;
switch ( V_93 ) {
case 0 :
V_97 = V_94 ;
break;
case 1 :
V_97 = V_95 ;
break ;
case 2 :
V_97 = V_96 ;
break;
default:
break;
}
return V_97 ;
}
static enum
V_98 F_24 ( struct V_1 * V_2 )
{
int V_99 = 100 ;
unsigned short int V_100 ;
T_4 V_101 ;
F_14 ( L_7 , V_20 ) ;
V_100 = F_11 ( V_2 , V_102 ) ;
while ( ( ! V_100 ) && ( V_99 > 0 ) ) {
F_25 ( 2000 , 3000 ) ;
V_99 -= 2 ;
V_100 = F_11 ( V_2 , V_102 ) ;
}
if ( ! V_100 )
V_101 = V_103 ;
else
V_101 = V_104 ;
F_14 ( L_12 ,
V_100 == 0 ? L_13 : L_14 ) ;
return V_101 ;
}
static enum
V_98 F_26 ( struct V_1 * V_2 ,
T_4 V_105 )
{
T_4 V_106 = 0 , V_107 , V_108 ;
int V_99 = 0 ;
F_14 ( L_7 , V_20 ) ;
switch ( V_105 ) {
case 0 :
V_108 = 20 ;
V_99 = 10 ;
break;
case 1 :
V_108 = 80 ;
V_99 = 55 ;
break;
case 2 :
V_108 = 40 ;
V_99 = 30 ;
break;
default:
V_108 = 0xffff ;
break;
}
F_14 ( L_15 , V_20 , V_108 , V_99 ) ;
V_106 = F_11 ( V_2 , V_109 ) ;
while ( ( V_106 < V_108 ) && ( V_99 > 0 ) ) {
F_25 ( 1000 , 2000 ) ;
V_99 -= 1 ;
V_106 = F_11 ( V_2 , V_109 ) ;
}
F_14 ( L_16 , V_106 , V_99 ) ;
if ( V_106 < V_108 ) {
V_107 = V_110 ;
F_14 ( L_17 , V_20 ) ;
} else {
F_14 ( L_18 , V_20 ) ;
V_107 = V_111 ;
}
return V_107 ;
}
static enum V_98
F_27 ( struct V_1 * V_2 )
{
enum V_98 V_112 ;
short int V_99 , V_113 ;
T_2 V_114 , V_115 = 0 , V_116 = 0 , V_117 = 0 , V_118 = 0 , V_93 , V_119 ;
T_2 V_53 , V_120 ;
F_14 ( L_7 , V_20 ) ;
if ( V_2 == NULL )
return V_121 ;
V_114 = 0 ;
do {
V_112 = V_122 ;
F_9 ( V_2 , V_123 , 0 ) ;
if ( V_2 -> V_11 -> V_124 != 0 )
F_9 ( V_2 , V_90 , 0x07 ) ;
F_9 ( V_2 , V_125 , 3 ) ;
F_9 ( V_2 , V_126 , 0 ) ;
F_9 ( V_2 , V_127 , 0 ) ;
F_25 ( 5000 , 10000 ) ;
F_9 ( V_2 , V_123 , 1 ) ;
if ( F_24 ( V_2 ) == V_103 )
return V_103 ;
else {
V_93 = F_11 ( V_2 , V_128 ) ;
if ( F_26 ( V_2 , V_93 ) ==
V_110 ) {
if ( V_114 == 0 )
V_112 = V_110 ;
}
}
V_114 ++ ;
} while ( ( V_114 < 10 ) && ( V_112 != V_122 ) );
V_53 = F_7 ( V_2 , V_129 ) ;
V_120 = F_7 ( V_2 , V_130 ) ;
F_14 ( L_19 , V_2 ) ;
F_14 ( L_20 ,
V_93 , V_53 , V_120 ) ;
V_53 = F_7 ( V_2 , V_131 ) ;
V_120 = F_7 ( V_2 , V_54 ) ;
F_14 ( L_21 , V_53 , V_120 ) ;
V_53 = F_7 ( V_2 , V_132 ) ;
F_14 ( L_22 , V_53 ) ;
if ( ( V_93 != 0 ) && ( V_93 != 1 ) && ( V_93 != 2 ) )
return V_121 ;
#if 0
switch (guard) {
case 0:
case 1:
stv0367_writebits(state, F367TER_AUTO_LE_EN, 0);
stv0367_writereg(state, R367TER_CHC_CTL, 0x01);
break;
case 2:
case 3:
stv0367_writebits(state, F367TER_AUTO_LE_EN, 1);
stv0367_writereg(state, R367TER_CHC_CTL, 0x11);
break;
default:
return FE_TER_SWNOK;
}
#endif
F_9 ( V_2 , V_133 , 1 ) ;
F_9 ( V_2 , V_134 , 1 ) ;
F_25 ( 1000 , 2000 ) ;
F_9 ( V_2 , V_133 , 0 ) ;
F_9 ( V_2 , V_134 , 0 ) ;
V_115 = F_11 ( V_2 , V_135 ) ;
V_116 = F_11 ( V_2 , V_136 ) ;
V_117 = F_11 ( V_2 , V_137 ) ;
V_99 = F_23 ( V_93 , 125 , 500 , 250 ) ;
V_113 = F_23 ( V_93 , 4 , 16 , 8 ) ;
while ( ( ( ! V_115 ) || ( ! V_116 ) || ( ! V_117 ) ) && ( V_99 >= 0 ) ) {
F_25 ( 1000 * V_113 , 1000 * ( V_113 + 1 ) ) ;
V_99 -= V_113 ;
V_115 = F_11 ( V_2 , V_135 ) ;
V_116 = F_11 ( V_2 , V_136 ) ;
V_117 = F_11 ( V_2 , V_137 ) ;
}
if ( ! V_115 )
return V_138 ;
if ( ! V_116 )
return V_139 ;
if ( ! V_117 )
return V_140 ;
V_119 = F_11 ( V_2 , V_141 ) ;
F_6 ( V_2 , V_142 , 0x11 ) ;
switch ( V_119 ) {
case 0 :
case 1 :
F_9 ( V_2 , V_143 , 0 ) ;
F_9 ( V_2 , V_144 , 0 ) ;
break;
case 2 :
case 3 :
F_9 ( V_2 , V_143 , 1 ) ;
F_9 ( V_2 , V_144 , 1 ) ;
break;
default:
return V_121 ;
}
if ( ( F_11 ( V_2 , V_145 ) == 2 ) &&
( V_93 == 1 ) &&
( F_11 ( V_2 , V_146 ) != 0 ) ) {
F_6 ( V_2 , V_147 , 0xc0 ) ;
F_6 ( V_2 , V_148 , 0x60 ) ;
F_6 ( V_2 , V_149 , 0x0 ) ;
} else
F_6 ( V_2 , V_147 , 0x0 ) ;
V_99 = F_23 ( V_93 , 125 , 500 , 250 ) ;
V_118 = F_11 ( V_2 , V_150 ) ;
while ( ( ! V_118 ) && ( V_99 >= 0 ) ) {
F_25 ( 1000 * V_113 , 1000 * ( V_113 + 1 ) ) ;
V_99 -= V_113 ;
V_118 = F_11 ( V_2 , V_150 ) ;
}
if ( ! V_118 )
return V_138 ;
F_9 ( V_2 , V_127 , 1 ) ;
F_14 ( L_23 ) ;
return V_122 ;
}
static void F_28 ( struct V_1 * V_2 ,
enum V_151 V_152 )
{
F_14 ( L_7 , V_20 ) ;
if ( V_2 == NULL )
return;
F_9 ( V_2 , V_153 , 0 ) ;
switch ( V_152 ) {
default:
case V_154 :
F_9 ( V_2 , V_155 , 0 ) ;
F_9 ( V_2 , V_156 , 0 ) ;
break;
case V_157 :
F_9 ( V_2 , V_155 , 1 ) ;
F_9 ( V_2 , V_156 , 1 ) ;
break;
}
}
static void F_29 ( struct V_1 * V_2 ,
enum V_158 clock )
{
F_14 ( L_7 , V_20 ) ;
if ( V_2 == NULL )
return;
switch ( clock ) {
case V_159 :
F_9 ( V_2 , V_160 , 1 ) ;
break;
case V_161 :
F_9 ( V_2 , V_160 , 0 ) ;
break;
default:
F_9 ( V_2 , V_160 , 0 ) ;
break;
}
}
static int F_30 ( struct V_50 * V_45 , T_2 V_162 )
{
struct V_1 * V_2 = V_45 -> V_52 ;
F_14 ( L_7 , V_20 ) ;
if ( V_162 ) {
F_9 ( V_2 , V_163 , 1 ) ;
F_9 ( V_2 , V_164 , 1 ) ;
F_9 ( V_2 , V_165 , 1 ) ;
} else {
F_9 ( V_2 , V_163 , 0 ) ;
F_9 ( V_2 , V_164 , 0 ) ;
F_9 ( V_2 , V_165 , 0 ) ;
}
return 0 ;
}
static int F_31 ( struct V_50 * V_45 )
{
return F_30 ( V_45 , 1 ) ;
}
static int F_32 ( struct V_50 * V_45 )
{
struct V_1 * V_2 = V_45 -> V_52 ;
struct V_166 * V_167 = V_2 -> V_167 ;
F_14 ( L_7 , V_20 ) ;
V_167 -> V_168 = 0 ;
F_12 ( V_2 ,
V_169 [ V_2 -> V_170 ] [ V_171 ] ) ;
F_13 ( V_2 , V_41 , V_2 -> V_11 -> V_37 ) ;
F_6 ( V_2 , V_54 , 0xa0 ) ;
F_6 ( V_2 , V_172 , 0x00 ) ;
F_28 ( V_2 , V_2 -> V_11 -> V_173 ) ;
F_29 ( V_2 , V_2 -> V_11 -> V_174 ) ;
V_2 -> V_175 = F_7 ( V_2 , V_176 ) ;
V_167 -> V_177 = 0 ;
V_167 -> V_178 = 2 ;
return 0 ;
}
static int F_33 ( struct V_50 * V_45 )
{
struct V_179 * V_67 = & V_45 -> V_180 ;
struct V_1 * V_2 = V_45 -> V_52 ;
struct V_166 * V_167 = V_2 -> V_167 ;
int V_181 = 0 , V_113 = 0 ;
T_2 V_182 ;
T_2 V_183 ;
T_5 V_184 ;
T_4 V_185 = 0 ;
T_3 V_186 = 0 , V_187 = 0 , V_188 = 0 , V_43 = 0 ;
F_14 ( L_7 , V_20 ) ;
F_15 ( V_2 , & V_43 ) ;
V_167 -> V_189 = V_67 -> V_189 ;
V_167 -> V_190 = V_191
+ F_11 ( V_2 , V_192 ) * 2 ;
V_167 -> V_124 = V_2 -> V_11 -> V_124 ;
switch ( V_2 -> V_11 -> V_124 ) {
case V_193 :
F_14 ( L_24 ) ;
F_9 ( V_2 , V_194 , 0 ) ;
F_9 ( V_2 , V_195 , 0 ) ;
F_9 ( V_2 , V_196 , 0 ) ;
break;
case V_197 :
F_14 ( L_25 ) ;
F_9 ( V_2 , V_194 , 0 ) ;
F_9 ( V_2 , V_195 , 1 ) ;
F_9 ( V_2 , V_196 , 1 ) ;
break;
case V_198 :
F_14 ( L_26 ) ;
F_9 ( V_2 , V_194 , 1 ) ;
F_9 ( V_2 , V_199 , 0 ) ;
break;
default:
F_2 ( V_22 L_27 ) ;
return - V_17 ;
}
F_25 ( 5000 , 7000 ) ;
switch ( V_67 -> V_200 ) {
case V_201 :
default:
F_14 ( L_28 , V_20 ) ;
if ( V_167 -> V_124 == V_198 )
F_9 ( V_2 , V_202 ,
V_167 -> V_203 ) ;
else
F_9 ( V_2 , V_204 ,
V_167 -> V_203 ) ;
break;
case V_205 :
case V_206 :
if ( V_167 -> V_124 == V_198 )
F_9 ( V_2 , V_202 ,
V_67 -> V_200 ) ;
else
F_9 ( V_2 , V_204 ,
V_67 -> V_200 ) ;
break;
}
if ( ( V_167 -> V_124 != V_193 ) &&
( V_167 -> V_207 != V_167 -> V_208 ) ) {
F_20 ( V_2 ) ;
F_9 ( V_2 , V_209 , 1 ) ;
F_9 ( V_2 , V_210 , 0xB ) ;
F_9 ( V_2 , V_209 , 0 ) ;
F_9 ( V_2 , V_210 , 0xB ) ;
if ( ! F_21 ( V_2 , V_167 -> V_208 ,
V_2 -> V_11 -> V_37 ) )
return - V_17 ;
V_167 -> V_207 = V_167 -> V_208 ;
F_22 ( V_2 ) ;
}
if ( V_167 -> V_211 == V_212 )
F_9 ( V_2 , V_213 , 0x01 ) ;
else
F_9 ( V_2 , V_213 , 0x00 ) ;
V_187 = F_18 ( V_2 , V_2 -> V_11 -> V_37 ) / 1000 ;
V_188 = ( int )
( ( ( ( V_167 -> V_208 * 64 * ( 1 << 15 ) * 100 )
/ ( V_187 ) ) * 10 ) / 7 ) ;
F_9 ( V_2 , V_214 , V_188 % 2 ) ;
V_188 = V_188 / 2 ;
F_9 ( V_2 , V_215 , V_188 / 256 ) ;
F_9 ( V_2 , V_216 , V_188 % 256 ) ;
V_188 = F_11 ( V_2 , V_215 ) * 512 +
F_11 ( V_2 , V_216 ) * 2 +
F_11 ( V_2 , V_214 ) ;
V_188 = ( int ) ( ( ( 1 << 17 ) * V_167 -> V_208 * 1000 ) / ( 7 * ( V_187 ) ) ) ;
F_9 ( V_2 , V_217 , V_188 / 256 ) ;
F_9 ( V_2 , V_218 , V_188 % 256 ) ;
V_188 = F_11 ( V_2 , V_217 ) * 256 +
F_11 ( V_2 , V_218 ) ;
V_188 = ( int )
( ( V_187 - V_43 ) * ( 1 << 16 ) / ( V_187 ) ) ;
F_14 ( L_29 , V_188 ) ;
F_9 ( V_2 , V_219 , V_188 / 256 ) ;
F_9 ( V_2 , V_220 , V_188 % 256 ) ;
V_167 -> V_221 = 0 ;
V_167 -> V_222 = 0 ;
V_167 -> V_168 = 0 ;
F_9 ( V_2 , V_223 , V_167 -> V_221 ) ;
if ( F_27 ( V_2 ) != V_122 )
return 0 ;
V_167 -> V_2 = V_122 ;
V_167 -> V_93 = F_11 ( V_2 , V_128 ) ;
V_167 -> V_119 = F_11 ( V_2 , V_141 ) ;
V_167 -> V_177 = 1 ;
V_167 -> V_224 =
( F_11 ( V_2 , V_225 ) << 16 ) +
( F_11 ( V_2 , V_226 ) << 24 ) +
F_11 ( V_2 , V_227 ) +
( F_11 ( V_2 , V_228 ) << 8 ) ;
F_9 ( V_2 , V_229 , 1 ) ;
V_181 = ( F_11 ( V_2 , V_230 ) << 16 ) ;
V_181 += ( F_11 ( V_2 , V_231 ) << 8 ) ;
V_181 += ( F_11 ( V_2 , V_232 ) ) ;
F_9 ( V_2 , V_229 , 0 ) ;
if ( V_181 > 8388607 )
V_181 -= 16777216 ;
V_181 = V_181 * 2 / 16384 ;
if ( V_167 -> V_93 == V_233 )
V_181 = ( V_181 * 4464 ) / 1000 ;
else if ( V_167 -> V_93 == V_234 )
V_181 = ( V_181 * 223 ) / 100 ;
else if ( V_167 -> V_93 == V_235 )
V_181 = ( V_181 * 111 ) / 100 ;
if ( F_11 ( V_2 , V_199 ) == 1 ) {
if ( ( F_11 ( V_2 , V_204 ) ==
( F_11 ( V_2 ,
V_236 ) == 1 ) ) )
V_181 = V_181 * - 1 ;
}
if ( V_167 -> V_208 == 6 )
V_181 = ( V_181 * 6 ) / 8 ;
else if ( V_167 -> V_208 == 7 )
V_181 = ( V_181 * 7 ) / 8 ;
V_167 -> V_189 += V_181 ;
V_113 = 10 ;
while ( ( V_185 == 0 ) && ( V_113 > 0 ) ) {
F_25 ( 10000 , 20000 ) ;
V_185 = F_11 ( V_2 , V_237 )
+ 256 * F_11 ( V_2 ,
V_238 ) ;
if ( V_185 >= 32768 )
V_185 -= 65536 ;
V_186 = ( 512 * F_11 ( V_2 ,
V_215 )
+ F_11 ( V_2 , V_216 ) * 2
+ F_11 ( V_2 , V_214 ) ) ;
V_185 = ( ( signed ) ( 1000000 / V_186 ) *
V_185 ) / 2048 ;
V_113 -- ;
}
if ( V_185 <= 0 ) {
V_185 = ( V_185 - 11 ) / 22 ;
V_184 = - 1 ;
} else {
V_185 = ( V_185 + 11 ) / 22 ;
V_184 = 1 ;
}
for ( V_183 = 0 ; V_183 < abs ( V_185 ) ; V_183 ++ ) {
V_186 += V_184 ;
F_9 ( V_2 , V_214 ,
V_186 % 2 ) ;
F_9 ( V_2 , V_216 ,
V_186 / 2 ) ;
F_25 ( 1000 , 2000 ) ;
}
F_25 ( 5000 , 6000 ) ;
V_182 = F_11 ( V_2 , V_135 ) ;
if ( ! V_182 ) {
F_9 ( V_2 , V_123 , 0 ) ;
F_34 ( 20 ) ;
F_9 ( V_2 , V_123 , 1 ) ;
}
return 0 ;
}
static int F_35 ( struct V_50 * V_45 )
{
struct V_179 * V_67 = & V_45 -> V_180 ;
struct V_1 * V_2 = V_45 -> V_52 ;
struct V_166 * V_167 = V_2 -> V_167 ;
T_5 V_239 , V_240 ;
T_2 V_241 [] = { V_205 , V_206 } ;
if ( V_2 -> V_242 )
F_32 ( V_45 ) ;
if ( V_45 -> V_46 . V_47 . V_243 ) {
if ( V_2 -> V_244 && V_45 -> V_46 . V_245 )
V_45 -> V_46 . V_245 ( V_45 , 1 ) ;
V_45 -> V_46 . V_47 . V_243 ( V_45 ) ;
if ( V_2 -> V_244 && V_45 -> V_46 . V_245 )
V_45 -> V_46 . V_245 ( V_45 , 0 ) ;
}
switch ( V_67 -> V_246 ) {
default:
case V_247 :
case V_248 :
V_167 -> V_93 = V_233 ;
break;
case V_249 :
V_167 -> V_93 = V_235 ;
break;
}
switch ( V_67 -> V_250 ) {
default:
case V_251 :
case V_252 :
case V_253 :
case V_254 :
V_167 -> V_119 = V_67 -> V_250 ;
break;
case V_255 :
V_167 -> V_119 = V_251 ;
break;
}
switch ( V_67 -> V_256 ) {
case 6000000 :
V_167 -> V_208 = V_257 ;
break;
case 7000000 :
V_167 -> V_208 = V_258 ;
break;
case 8000000 :
default:
V_167 -> V_208 = V_259 ;
}
V_167 -> V_211 = V_260 ;
switch ( V_67 -> V_200 ) {
case V_206 :
case V_205 :
V_239 = 1 ;
break;
default:
V_239 = 2 ;
if ( V_167 -> V_177 )
V_239 = 1 ;
break;
}
V_167 -> V_2 = V_138 ;
V_240 = 0 ;
while ( ( ( V_240 ) < V_239 ) && ( V_167 -> V_2 != V_122 ) ) {
if ( ! V_167 -> V_177 ) {
if ( V_67 -> V_200 == V_201 )
V_167 -> V_203 = V_241 [ V_240 ] ;
}
F_33 ( V_45 ) ;
if ( ( V_167 -> V_2 == V_122 ) &&
( V_67 -> V_200 == V_201 ) &&
( V_240 == 1 ) ) {
V_241 [ V_240 ] = V_241 [ 0 ] ;
V_241 [ ( V_240 + 1 ) % 2 ] = ( V_241 [ 1 ] + 1 ) % 2 ;
}
V_240 ++ ;
}
return 0 ;
}
static int F_36 ( struct V_50 * V_45 , T_3 * V_222 )
{
struct V_1 * V_2 = V_45 -> V_52 ;
struct V_166 * V_167 = V_2 -> V_167 ;
T_3 V_261 = 0 ;
if ( F_11 ( V_2 , V_262 ) == 0 ) {
V_261 =
( ( T_3 ) F_11 ( V_2 , V_263 )
* ( 1 << 16 ) )
+ ( ( T_3 ) F_11 ( V_2 , V_264 )
* ( 1 << 8 ) )
+ ( ( T_3 ) F_11 ( V_2 , V_265 ) ) ;
V_167 -> V_222 = V_261 ;
}
( * V_222 ) = V_167 -> V_222 ;
return 0 ;
}
static int F_37 ( struct V_50 * V_45 ,
struct V_179 * V_67 )
{
struct V_1 * V_2 = V_45 -> V_52 ;
struct V_166 * V_167 = V_2 -> V_167 ;
enum V_266 V_93 ;
int V_267 = 0 , V_268 = 0 ;
V_67 -> V_189 = F_17 ( V_45 ) ;
if ( ( int ) V_67 -> V_189 < 0 )
V_67 -> V_189 = - V_67 -> V_189 ;
V_267 = F_11 ( V_2 , V_145 ) ;
if ( V_267 == 0 )
V_67 -> V_269 = V_270 ;
else if ( V_267 == 1 )
V_67 -> V_269 = V_271 ;
else
V_67 -> V_269 = V_272 ;
V_67 -> V_200 = F_11 ( V_2 , V_204 ) ;
V_268 = F_11 ( V_2 , V_273 ) ;
switch ( V_268 ) {
case 0 :
V_67 -> V_211 = V_274 ;
break;
case 1 :
V_67 -> V_211 = V_275 ;
break;
case 2 :
V_67 -> V_211 = V_276 ;
break;
case 3 :
V_67 -> V_211 = V_277 ;
break;
default:
V_67 -> V_211 = V_278 ;
break;
}
if ( V_167 -> V_211 == V_212 )
V_268 = F_11 ( V_2 , V_279 ) ;
else
V_268 = F_11 ( V_2 , V_146 ) ;
switch ( V_268 ) {
case 0 :
V_67 -> V_280 = V_281 ;
break;
case 1 :
V_67 -> V_280 = V_282 ;
break;
case 2 :
V_67 -> V_280 = V_283 ;
break;
case 3 :
V_67 -> V_280 = V_284 ;
break;
case 4 :
V_67 -> V_280 = V_285 ;
break;
default:
V_67 -> V_280 = V_286 ;
break;
}
V_93 = F_11 ( V_2 , V_128 ) ;
switch ( V_93 ) {
case V_233 :
V_67 -> V_246 = V_248 ;
break;
case V_235 :
V_67 -> V_246 = V_249 ;
break;
default:
V_67 -> V_246 = V_247 ;
}
V_67 -> V_250 = F_11 ( V_2 , V_141 ) ;
return 0 ;
}
static T_3 F_38 ( struct V_50 * V_45 )
{
struct V_1 * V_2 = V_45 -> V_52 ;
T_3 V_287 = 0 ;
int V_288 = 0 ;
T_2 V_289 = F_11 ( V_2 , V_290 ) ;
while ( V_288 < 10 ) {
F_25 ( 2000 , 3000 ) ;
if ( V_289 == 0x50 )
V_287 += F_11 ( V_2 , V_291 ) / 4 ;
else
V_287 += 125 * F_11 ( V_2 , V_291 ) ;
V_288 ++ ;
}
V_287 /= 10 ;
return V_287 ;
}
static int F_39 ( struct V_50 * V_45 , T_1 * V_292 )
{
T_3 V_293 = F_38 ( V_45 ) ;
* V_292 = V_293 / 1000 ;
return 0 ;
}
static int F_40 ( struct V_50 * V_45 ,
enum V_294 * V_295 )
{
struct V_1 * V_2 = V_45 -> V_52 ;
F_14 ( L_7 , V_20 ) ;
* V_295 = 0 ;
if ( F_11 ( V_2 , V_135 ) ) {
* V_295 = V_296 | V_297 | V_298
| V_299 | V_300 ;
F_14 ( L_30 , V_20 ) ;
}
return 0 ;
}
static int F_41 ( struct V_50 * V_45 , T_3 * V_301 )
{
struct V_1 * V_2 = V_45 -> V_52 ;
struct V_166 * V_167 = V_2 -> V_167 ;
T_3 V_302 = 0 , V_303 = 0 , V_304 = 0 ;
int V_305 = 0 , V_306 = 0 ;
if ( F_11 ( V_2 , V_262 ) == 0 )
V_302 = ( ( T_3 ) F_11 ( V_2 , V_307 )
* ( 1 << 16 ) )
+ ( ( T_3 ) F_11 ( V_2 , V_308 )
* ( 1 << 8 ) )
+ ( ( T_3 ) F_11 ( V_2 ,
V_309 ) ) ;
else {
V_303 = V_167 -> V_168 ;
return 0 ;
}
V_305 = F_11 ( V_2 , V_310 ) ;
V_306 = F_11 ( V_2 , V_311 ) ;
if ( V_302 == 0 ) {
V_303 = 0 ;
} else if ( V_305 == 0x7 ) {
if ( V_302 <= 4 ) {
V_304 = ( V_302 * 1000000000 ) / ( 8 * ( 1 << 14 ) ) ;
V_304 = V_304 ;
} else if ( V_302 <= 42 ) {
V_304 = ( V_302 * 100000000 ) / ( 8 * ( 1 << 14 ) ) ;
V_304 = V_304 * 10 ;
} else if ( V_302 <= 429 ) {
V_304 = ( V_302 * 10000000 ) / ( 8 * ( 1 << 14 ) ) ;
V_304 = V_304 * 100 ;
} else if ( V_302 <= 4294 ) {
V_304 = ( V_302 * 1000000 ) / ( 8 * ( 1 << 14 ) ) ;
V_304 = V_304 * 1000 ;
} else if ( V_302 <= 42949 ) {
V_304 = ( V_302 * 100000 ) / ( 8 * ( 1 << 14 ) ) ;
V_304 = V_304 * 10000 ;
} else if ( V_302 <= 429496 ) {
V_304 = ( V_302 * 10000 ) / ( 8 * ( 1 << 14 ) ) ;
V_304 = V_304 * 100000 ;
} else {
V_304 = ( V_302 * 1000 ) / ( 8 * ( 1 << 14 ) ) ;
V_304 = V_304 * 100000 ;
}
if ( V_306 == 2 )
V_303 = V_304 ;
else if ( V_306 == 3 )
V_303 = V_304 / 4 ;
else if ( V_306 == 4 )
V_303 = V_304 / 16 ;
else if ( V_306 == 5 )
V_303 = V_304 / 64 ;
else if ( V_306 == 6 )
V_303 = V_304 / 256 ;
else
V_303 = 0 ;
if ( ( V_302 < 4294967 ) && ( V_302 > 429496 ) )
V_303 *= 10 ;
}
V_167 -> V_168 = V_303 ;
( * V_301 ) = V_303 ;
return 0 ;
}
static int F_42 ( struct V_50 * V_45 ,
struct V_312
* V_313 )
{
V_313 -> V_314 = 1000 ;
V_313 -> V_315 = 0 ;
V_313 -> V_316 = 0 ;
return 0 ;
}
static void F_43 ( struct V_50 * V_45 )
{
struct V_1 * V_2 = V_45 -> V_52 ;
F_44 ( V_2 -> V_167 ) ;
F_44 ( V_2 -> V_317 ) ;
F_44 ( V_2 ) ;
}
struct V_50 * F_45 ( const struct V_318 * V_11 ,
struct V_319 * V_21 )
{
struct V_1 * V_2 = NULL ;
struct V_166 * V_167 = NULL ;
V_2 = F_46 ( sizeof( struct V_1 ) , V_320 ) ;
if ( V_2 == NULL )
goto error;
V_167 = F_46 ( sizeof( struct V_166 ) , V_320 ) ;
if ( V_167 == NULL )
goto error;
V_2 -> V_21 = V_21 ;
V_2 -> V_11 = V_11 ;
V_2 -> V_167 = V_167 ;
V_2 -> V_45 . V_46 = V_321 ;
V_2 -> V_45 . V_52 = V_2 ;
V_2 -> V_175 = F_7 ( V_2 , 0xf000 ) ;
V_2 -> V_244 = 1 ;
V_2 -> V_170 = V_322 ;
V_2 -> V_242 = 1 ;
V_2 -> V_44 = 0 ;
F_14 ( L_31 , V_20 , V_2 -> V_175 ) ;
if ( ( V_2 -> V_175 != 0x50 ) && ( V_2 -> V_175 != 0x60 ) )
goto error;
return & V_2 -> V_45 ;
error:
F_44 ( V_167 ) ;
F_44 ( V_2 ) ;
return NULL ;
}
static int F_47 ( struct V_50 * V_45 , int V_51 )
{
struct V_1 * V_2 = V_45 -> V_52 ;
F_14 ( L_7 , V_20 ) ;
F_9 ( V_2 , V_323 , ( V_51 > 0 ) ? 1 : 0 ) ;
return 0 ;
}
static T_3 F_48 ( struct V_50 * V_45 , T_3 V_63 )
{
struct V_1 * V_2 = V_45 -> V_52 ;
T_3 V_64 = 0 ;
T_3 V_324 , V_325 , V_326 ;
if ( F_11 ( V_2 , V_327 ) == 0 ) {
V_325 = ( T_3 ) F_11 ( V_2 , V_328 ) ;
if ( V_325 == 0 )
V_325 = V_325 + 1 ;
V_324 = ( T_3 ) F_11 ( V_2 , V_329 ) ;
if ( V_324 == 0 )
V_324 = V_324 + 1 ;
V_326 = ( T_3 ) F_11 ( V_2 , V_330 ) ;
if ( V_326 > 5 )
V_326 = 5 ;
V_64 = ( ( V_63 / 2 ) * V_325 ) / ( V_324 * ( 1 << V_326 ) ) ;
F_14 ( L_32 ,
V_64 ) ;
} else
V_64 = V_63 ;
F_14 ( L_33 , V_64 ) ;
return V_64 ;
}
static T_3 F_49 ( struct V_50 * V_45 , T_3 V_63 )
{
T_3 V_331 = V_63 ;
V_331 = F_48 ( V_45 , V_63 ) ;
return V_331 ;
}
static enum V_332 F_50 ( struct V_1 * V_2 ,
T_3 V_333 ,
enum V_332 V_334 )
{
F_9 ( V_2 , V_335 , V_334 ) ;
switch ( V_334 ) {
case V_336 :
F_6 ( V_2 , V_337 , 0x00 ) ;
break;
case V_338 :
F_6 ( V_2 , V_339 , 0x64 ) ;
F_6 ( V_2 , V_337 , 0x00 ) ;
F_6 ( V_2 , V_340 , 0x90 ) ;
F_6 ( V_2 , V_341 , 0xc1 ) ;
F_6 ( V_2 , V_342 , 0xa7 ) ;
F_6 ( V_2 , V_343 , 0x95 ) ;
F_6 ( V_2 , V_344 , 0x40 ) ;
F_6 ( V_2 , V_345 , 0x8a ) ;
break;
case V_346 :
F_6 ( V_2 , V_337 , 0x00 ) ;
F_6 ( V_2 , V_339 , 0x6e ) ;
F_6 ( V_2 , V_340 , 0xb0 ) ;
F_6 ( V_2 , V_341 , 0xc1 ) ;
F_6 ( V_2 , V_342 , 0xb7 ) ;
F_6 ( V_2 , V_343 , 0x9d ) ;
F_6 ( V_2 , V_344 , 0x7f ) ;
F_6 ( V_2 , V_345 , 0xa7 ) ;
break;
case V_347 :
F_6 ( V_2 , V_337 , 0x82 ) ;
F_6 ( V_2 , V_339 , 0x5a ) ;
if ( V_333 > 4500000 ) {
F_6 ( V_2 , V_340 , 0xb0 ) ;
F_6 ( V_2 , V_341 , 0xc1 ) ;
F_6 ( V_2 , V_342 , 0xa5 ) ;
} else if ( V_333 > 2500000 ) {
F_6 ( V_2 , V_340 , 0xa0 ) ;
F_6 ( V_2 , V_341 , 0xc1 ) ;
F_6 ( V_2 , V_342 , 0xa6 ) ;
} else {
F_6 ( V_2 , V_340 , 0xa0 ) ;
F_6 ( V_2 , V_341 , 0xd1 ) ;
F_6 ( V_2 , V_342 , 0xa7 ) ;
}
F_6 ( V_2 , V_343 , 0x95 ) ;
F_6 ( V_2 , V_344 , 0x40 ) ;
F_6 ( V_2 , V_345 , 0x99 ) ;
break;
case V_348 :
F_6 ( V_2 , V_337 , 0x00 ) ;
F_6 ( V_2 , V_339 , 0x76 ) ;
F_6 ( V_2 , V_340 , 0x90 ) ;
F_6 ( V_2 , V_341 , 0xb1 ) ;
if ( V_333 > 4500000 )
F_6 ( V_2 , V_342 , 0xa7 ) ;
else if ( V_333 > 2500000 )
F_6 ( V_2 , V_342 , 0xa6 ) ;
else
F_6 ( V_2 , V_342 , 0x97 ) ;
F_6 ( V_2 , V_343 , 0x8e ) ;
F_6 ( V_2 , V_344 , 0x7f ) ;
F_6 ( V_2 , V_345 , 0xa7 ) ;
break;
case V_349 :
F_6 ( V_2 , V_337 , 0x94 ) ;
F_6 ( V_2 , V_339 , 0x5a ) ;
F_6 ( V_2 , V_340 , 0xa0 ) ;
if ( V_333 > 4500000 )
F_6 ( V_2 , V_341 , 0xc1 ) ;
else if ( V_333 > 2500000 )
F_6 ( V_2 , V_341 , 0xc1 ) ;
else
F_6 ( V_2 , V_341 , 0xd1 ) ;
F_6 ( V_2 , V_342 , 0xa7 ) ;
F_6 ( V_2 , V_343 , 0x85 ) ;
F_6 ( V_2 , V_344 , 0x40 ) ;
F_6 ( V_2 , V_345 , 0xa7 ) ;
break;
case V_350 :
F_6 ( V_2 , V_337 , 0x00 ) ;
break;
case V_351 :
F_6 ( V_2 , V_337 , 0x00 ) ;
break;
default:
break;
}
return V_334 ;
}
static T_3 F_51 ( struct V_1 * V_2 ,
T_3 V_352 , T_4 V_353 )
{
T_3 V_354 = 0 ;
T_3 V_355 ;
V_355 = V_352 / 1000 ;
F_14 ( L_34 , V_20 , V_352 , V_353 ) ;
if ( V_355 != 0 ) {
if ( V_353 < 1000000 )
V_353 = V_352 / 4 ;
if ( V_353 > V_352 )
V_353 = V_353 - V_352 ;
V_354 = ( T_3 ) V_353 / 1000 ;
V_354 *= 32768 ;
V_354 /= V_355 ;
V_354 *= 256 ;
}
if ( V_354 > 8388607 )
V_354 = 8388607 ;
F_14 ( L_35 , V_20 , V_354 ) ;
F_6 ( V_2 , V_356 , V_354 ) ;
F_6 ( V_2 , V_357 , ( V_354 >> 8 ) ) ;
F_9 ( V_2 , V_358 , ( V_354 >> 16 ) ) ;
return V_353 ;
}
static T_3 F_52 ( struct V_1 * V_2 , T_3 V_352 )
{
T_3 V_354 ;
V_354 = F_11 ( V_2 , V_359 ) +
( F_11 ( V_2 , V_360 ) << 8 ) +
( F_11 ( V_2 , V_358 ) << 16 ) ;
V_354 /= 256 ;
V_354 *= ( V_352 / 1000 ) ;
V_354 += 1 ;
V_354 /= 32768 ;
return V_354 ;
}
static T_3 F_53 ( struct V_1 * V_2 , T_3 V_352 ,
T_3 V_361 , T_3 V_333 ,
enum V_332 V_334 )
{
T_3 V_362 = 0 ;
T_3 V_363 = 0 , V_364 = 0 ;
T_3 V_365 ;
F_14 ( L_7 , V_20 ) ;
switch ( V_334 ) {
case V_336 :
V_362 = 1110 ;
break;
case V_338 :
V_362 = 1032 ;
break;
case V_346 :
V_362 = 954 ;
break;
case V_347 :
V_362 = 983 ;
break;
case V_348 :
V_362 = 957 ;
break;
case V_349 :
V_362 = 948 ;
break;
case V_350 :
V_362 = 0 ;
break;
case V_351 :
V_362 = 944 ;
break;
default:
break;
}
if ( V_352 != 0 ) {
V_363 = 256 * V_333 ;
V_363 = V_363 / V_352 ;
}
F_6 ( V_2 , V_366 , ( T_2 ) V_363 ) ;
V_365 = ( V_361 >> 1 ) / 1000 ;
if ( V_365 != 0 ) {
V_363 = V_333 ;
V_364 = V_333 ;
if ( V_363 < 2097152 ) {
V_363 *= 2048 ;
V_363 = V_363 / V_365 ;
V_363 = V_363 * 16384 ;
V_363 /= 125 ;
V_363 = V_363 * 8 ;
V_364 *= 2048 ;
V_364 /= 439 ;
V_364 *= 256 ;
V_364 = V_364 / V_365 ;
V_364 *= V_362 * 9 ;
V_364 = V_364 / 10000000 ;
} else if ( V_363 < 4194304 ) {
V_363 *= 1024 ;
V_363 = V_363 / V_365 ;
V_363 = V_363 * 16384 ;
V_363 /= 125 ;
V_363 = V_363 * 16 ;
V_364 *= 1024 ;
V_364 /= 439 ;
V_364 *= 256 ;
V_364 = V_364 / V_365 ;
V_364 *= V_362 * 9 ;
V_364 = V_364 / 5000000 ;
} else if ( V_363 < 8388607 ) {
V_363 *= 512 ;
V_363 = V_363 / V_365 ;
V_363 = V_363 * 16384 ;
V_363 /= 125 ;
V_363 = V_363 * 32 ;
V_364 *= 512 ;
V_364 /= 439 ;
V_364 *= 256 ;
V_364 = V_364 / V_365 ;
V_364 *= V_362 * 9 ;
V_364 = V_364 / 2500000 ;
} else {
V_363 *= 256 ;
V_363 = V_363 / V_365 ;
V_363 = V_363 * 16384 ;
V_363 /= 125 ;
V_363 = V_363 * 64 ;
V_364 *= 256 ;
V_364 /= 439 ;
V_364 *= 256 ;
V_364 = V_364 / V_365 ;
V_364 *= V_362 * 9 ;
V_364 = V_364 / 1250000 ;
}
}
#if 0
if (stv0367_readbits(state, F367CAB_ADJ_EN)) {
stv0367cab_SetIirAdjacentcoefficient(state, mclk_hz,
SymbolRate);
stv0367_writebits(state, F367CAB_ALLPASSFILT_EN, 1);
stv0367cab_SetAllPasscoefficient(state, mclk_hz, SymbolRate);
} else
#endif
F_9 ( V_2 , V_367 , 0 ) ;
F_6 ( V_2 , V_368 , V_363 ) ;
F_6 ( V_2 , V_369 , ( V_363 >> 8 ) ) ;
F_6 ( V_2 , V_370 , ( V_363 >> 16 ) ) ;
F_6 ( V_2 , V_371 , ( V_363 >> 24 ) ) ;
F_6 ( V_2 , V_372 , V_364 & 0x00ff ) ;
F_9 ( V_2 , V_373 , ( V_364 >> 8 ) & 0x00ff ) ;
return V_333 ;
}
static T_3 F_54 ( struct V_1 * V_2 , T_3 V_361 )
{
T_3 V_374 ;
T_3 V_365 ;
V_374 = F_7 ( V_2 , V_368 ) +
( F_7 ( V_2 , V_369 ) << 8 ) +
( F_7 ( V_2 , V_370 ) << 16 ) +
( F_7 ( V_2 , V_371 ) << 24 ) ;
V_365 = ( V_361 >> 1 ) / 1000 ;
if ( V_374 < 134217728 ) {
V_374 = V_374 * 32 ;
V_374 = V_374 / 32768 ;
V_374 = V_365 * V_374 ;
V_374 = V_374 / 128 ;
V_374 *= 125 ;
V_374 /= 2048 ;
} else if ( V_374 < 268435456 ) {
V_374 = V_374 * 16 ;
V_374 = V_374 / 32768 ;
V_374 = V_365 * V_374 ;
V_374 = V_374 / 128 ;
V_374 *= 125 ;
V_374 /= 1024 ;
} else if ( V_374 < 536870912 ) {
V_374 = V_374 * 8 ;
V_374 = V_374 / 32768 ;
V_374 = V_365 * V_374 ;
V_374 = V_374 / 128 ;
V_374 *= 125 ;
V_374 /= 512 ;
} else {
V_374 = V_374 * 4 ;
V_374 = V_374 / 32768 ;
V_374 = V_365 * V_374 ;
V_374 = V_374 / 128 ;
V_374 *= 125 ;
V_374 /= 256 ;
}
return V_374 ;
}
static int F_55 ( struct V_50 * V_45 ,
enum V_294 * V_295 )
{
struct V_1 * V_2 = V_45 -> V_52 ;
F_14 ( L_7 , V_20 ) ;
* V_295 = 0 ;
if ( V_2 -> V_317 -> V_2 > V_375 )
* V_295 |= V_296 ;
if ( V_2 -> V_317 -> V_2 > V_376 )
* V_295 |= V_297 ;
if ( V_2 -> V_317 -> V_2 >= V_377 )
* V_295 |= V_298 ;
if ( V_2 -> V_317 -> V_2 >= V_378 )
* V_295 |= V_299 ;
if ( F_11 ( V_2 , ( V_2 -> V_317 -> V_379 ?
V_2 -> V_317 -> V_379 : V_380 ) ) ) {
* V_295 |= V_300 ;
F_14 ( L_30 , V_20 ) ;
}
return 0 ;
}
static int F_56 ( struct V_50 * V_45 , T_2 V_162 )
{
struct V_1 * V_2 = V_45 -> V_52 ;
F_14 ( L_7 , V_20 ) ;
if ( V_162 ) {
F_9 ( V_2 , V_327 , 0x03 ) ;
F_9 ( V_2 , V_381 , 0x01 ) ;
F_9 ( V_2 , V_382 , 1 ) ;
F_9 ( V_2 , V_383 , 1 ) ;
F_9 ( V_2 , V_384 , 0 ) ;
F_9 ( V_2 , V_385 , 0 ) ;
F_9 ( V_2 , V_386 , 1 ) ;
F_9 ( V_2 , V_387 , 1 ) ;
} else {
F_9 ( V_2 , V_381 , 0x00 ) ;
F_9 ( V_2 , V_327 , 0x00 ) ;
F_9 ( V_2 , V_382 , 0 ) ;
F_9 ( V_2 , V_383 , 0 ) ;
F_9 ( V_2 , V_384 , 1 ) ;
F_9 ( V_2 , V_385 , 1 ) ;
F_9 ( V_2 , V_386 , 0 ) ;
F_9 ( V_2 , V_387 , 0 ) ;
}
return 0 ;
}
static int F_57 ( struct V_50 * V_45 )
{
return F_56 ( V_45 , 1 ) ;
}
static int F_58 ( struct V_50 * V_45 )
{
struct V_1 * V_2 = V_45 -> V_52 ;
struct V_388 * V_317 = V_2 -> V_317 ;
F_14 ( L_7 , V_20 ) ;
F_12 ( V_2 ,
V_169 [ V_2 -> V_170 ] [ V_389 ] ) ;
switch ( V_2 -> V_11 -> V_173 ) {
case V_390 :
F_14 ( L_36 ) ;
F_9 ( V_2 , V_391 , 0x03 ) ;
break;
case V_157 :
case V_392 :
F_9 ( V_2 , V_391 , 0x01 ) ;
break;
case V_154 :
case V_393 :
F_9 ( V_2 , V_391 , 0x00 ) ;
break;
}
switch ( V_2 -> V_11 -> V_174 ) {
case V_159 :
F_9 ( V_2 , V_394 , 0x00 ) ;
break;
case V_161 :
case V_395 :
F_9 ( V_2 , V_394 , 0x01 ) ;
break;
}
F_9 ( V_2 , V_396 , 0x00 ) ;
F_9 ( V_2 , V_397 , 0x01 ) ;
F_9 ( V_2 , V_398 , 0x01 ) ;
F_9 ( V_2 , V_399 , 0x00 ) ;
F_6 ( V_2 , V_400 , 0x00 ) ;
V_317 -> V_401 = F_48 ( V_45 , V_2 -> V_11 -> V_37 ) ;
V_317 -> V_402 = F_49 ( V_45 , V_2 -> V_11 -> V_37 ) ;
return 0 ;
}
static
enum V_403 F_59 ( struct V_1 * V_2 ,
struct V_179 * V_67 )
{
struct V_388 * V_317 = V_2 -> V_317 ;
enum V_403 V_404 = V_405 ;
T_3 V_406 , V_407 , V_363 , V_43 ,
V_408 , V_409 , V_410 , V_411 ,
V_412 , V_413 , V_414 , V_415 ;
T_2 V_416 ;
T_4 V_53 ;
F_14 ( L_7 , V_20 ) ;
F_15 ( V_2 , & V_43 ) ;
V_410 = 25 ;
V_409 = 100000000 / V_67 -> V_417 ;
switch ( V_67 -> V_269 ) {
case V_271 :
V_411 = 150000 ;
V_413 = 100 ;
break;
case V_418 :
V_411 = 250000 ;
V_413 = 100 ;
break;
case V_272 :
V_411 = 200000 ;
V_413 = 100 ;
break;
case V_419 :
V_411 = 250000 ;
V_413 = 100 ;
break;
case V_420 :
V_411 = 250000 ;
V_413 = 100 ;
break;
default:
V_411 = 200000 ;
V_413 = 100 ;
break;
}
#if 0
if (pIntParams->search_range < 0) {
CRLTimeOut = (25 * CRLSymbols *
(-pIntParams->search_range / 1000)) /
(pIntParams->symbol_rate / 1000);
} else
#endif
V_412 = ( 25 * V_411 * ( V_317 -> V_421 / 1000 ) ) /
( V_67 -> V_417 / 1000 ) ;
V_412 = ( 1000 * V_412 ) / V_67 -> V_417 ;
if ( V_412 < 50 )
V_412 = 50 ;
V_415 = 20 ;
V_414 = V_410 + V_409 + V_412 + V_413 ;
F_14 ( L_37 , V_20 , V_414 ) ;
F_6 ( V_2 , V_422 , 0x04 ) ;
V_416 = F_11 ( V_2 , V_423 ) ;
F_9 ( V_2 , V_423 , 0x0 ) ;
F_9 ( V_2 , V_424 , 0 ) ;
F_9 ( V_2 , V_425 , 0 ) ;
F_51 ( V_2 , V_317 -> V_402 ,
( 1000 * ( T_4 ) V_43 + V_317 -> V_426 ) ) ;
if ( ( V_67 -> V_417 > 10800000 ) | ( V_67 -> V_417 < 1800000 ) ) {
F_9 ( V_2 , V_427 , 0 ) ;
F_9 ( V_2 , V_367 , 0 ) ;
}
#if 0
tuner_lock = stv0367cab_tuner_get_status(fe);
if (tuner_lock == 0)
return FE_367CAB_NOTUNER;
#endif
V_408 = 0 ;
F_6 ( V_2 , V_422 , 0x00 ) ;
do {
V_407 = F_11 ( V_2 , V_428 ) ;
if ( ( V_408 >= ( V_414 - V_413 ) ) &&
( V_407 == 0x04 ) )
V_408 = V_414 ;
else if ( ( V_408 >= ( V_410 + V_409 ) ) &&
( V_407 == 0x02 ) )
{
V_408 = V_414 ;
V_363 = F_11 ( V_2 ,
V_429 ) +
( F_11 ( V_2 ,
V_430 ) << 8 ) +
( F_11 ( V_2 ,
V_431 ) << 16 ) ;
if ( V_363 >= 131072 )
V_363 = 262144 - V_363 ;
V_363 = V_363 / ( 1 << ( 11 - F_11 ( V_2 ,
V_432 ) ) ) ;
if ( V_363 < F_11 ( V_2 ,
V_433 ) +
256 * F_11 ( V_2 ,
V_434 ) - 10 )
V_407 = 0x0f ;
} else {
F_25 ( 10000 , 20000 ) ;
V_408 += 10 ;
}
F_14 ( L_38 , V_407 , V_408 ) ;
V_53 = F_7 ( V_2 , V_435 ) ;
F_14 ( L_39 , V_53 ) ;
} while ( ( ( V_407 != 0x0c ) && ( V_407 != 0x0b ) ) &&
( V_408 < V_414 ) );
F_14 ( L_40 , V_407 ) ;
V_53 = F_7 ( V_2 , V_435 ) ;
F_14 ( L_39 , V_53 ) ;
V_53 = F_7 ( V_2 , V_436 ) ;
F_14 ( L_41 , V_53 ) ;
V_53 = F_52 ( V_2 , V_317 -> V_402 ) ;
F_14 ( L_42 , V_53 ) ;
if ( ( V_407 == 0x0c ) || ( V_407 == 0x0b ) ) {
V_408 = 0 ;
do {
F_25 ( 5000 , 7000 ) ;
V_408 += 5 ;
V_406 = F_11 ( V_2 ,
( V_2 -> V_317 -> V_379 ?
V_2 -> V_317 -> V_379 :
V_380 ) ) ;
} while ( ! V_406 && ( V_408 < V_415 ) );
} else
V_406 = 0 ;
if ( V_406 ) {
V_404 = V_378 ;
V_317 -> V_437 = F_11 ( V_2 ,
V_438 ) ;
#if 0
if (ifkhz != 0) {
if (ifkhz > cab_state->adc_clk / 1000) {
cab_state->freq_khz =
FE_Cab_TunerGetFrequency(pIntParams->hTuner)
- stv0367cab_get_derot_freq(state, cab_state->adc_clk)
- cab_state->adc_clk / 1000 + ifkhz;
} else {
cab_state->freq_khz =
FE_Cab_TunerGetFrequency(pIntParams->hTuner)
- stv0367cab_get_derot_freq(state, cab_state->adc_clk)
+ ifkhz;
}
} else {
cab_state->freq_khz =
FE_Cab_TunerGetFrequency(pIntParams->hTuner) +
stv0367cab_get_derot_freq(state,
cab_state->adc_clk) -
cab_state->adc_clk / 4000;
}
#endif
V_317 -> V_417 = F_54 ( V_2 ,
V_317 -> V_401 ) ;
V_317 -> V_439 = 1 ;
} else {
switch ( V_407 ) {
case 1 :
V_404 = V_405 ;
break;
case 2 :
V_404 = V_440 ;
break;
case 3 :
V_404 = V_441 ;
break;
case 4 :
V_404 = V_376 ;
break;
case 5 :
V_404 = V_442 ;
break;
case 7 :
V_404 = V_443 ;
break;
case 8 :
V_404 = V_444 ;
break;
case 10 :
V_404 = V_445 ;
break;
case 11 :
V_404 = V_377 ;
break;
case 12 :
V_404 = V_377 ;
break;
case 13 :
V_404 = V_445 ;
break;
case 14 :
V_404 = V_443 ;
break;
case 15 :
V_404 = V_375 ;
break;
default:
break;
}
}
F_9 ( V_2 , V_423 , V_416 ) ;
return V_404 ;
}
static int F_60 ( struct V_50 * V_45 )
{
struct V_179 * V_67 = & V_45 -> V_180 ;
struct V_1 * V_2 = V_45 -> V_52 ;
struct V_388 * V_317 = V_2 -> V_317 ;
enum V_332 V_334 = 0 ;
F_14 ( L_43 , V_20 ,
V_67 -> V_189 , V_67 -> V_417 ) ;
V_317 -> V_426 = 0 ;
switch ( V_67 -> V_269 ) {
case V_271 :
V_334 = V_338 ;
break;
case V_418 :
V_334 = V_346 ;
break;
case V_272 :
V_334 = V_347 ;
break;
case V_419 :
V_334 = V_348 ;
break;
case V_420 :
V_334 = V_349 ;
break;
default:
break;
}
if ( V_2 -> V_242 )
F_58 ( V_45 ) ;
if ( V_45 -> V_46 . V_47 . V_243 ) {
if ( V_2 -> V_244 && V_45 -> V_46 . V_245 )
V_45 -> V_46 . V_245 ( V_45 , 1 ) ;
V_45 -> V_46 . V_47 . V_243 ( V_45 ) ;
if ( V_2 -> V_244 && V_45 -> V_46 . V_245 )
V_45 -> V_46 . V_245 ( V_45 , 0 ) ;
}
F_50 (
V_2 ,
V_67 -> V_417 ,
V_334 ) ;
F_53 ( V_2 ,
V_317 -> V_402 ,
V_317 -> V_401 ,
V_67 -> V_417 ,
V_334 ) ;
V_317 -> V_2 = F_59 ( V_2 , V_67 ) ;
return 0 ;
}
static int F_61 ( struct V_50 * V_45 ,
struct V_179 * V_67 )
{
struct V_1 * V_2 = V_45 -> V_52 ;
struct V_388 * V_317 = V_2 -> V_317 ;
T_3 V_43 = 0 ;
enum V_332 V_334 ;
F_14 ( L_7 , V_20 ) ;
F_15 ( V_2 , & V_43 ) ;
V_67 -> V_417 = F_54 ( V_2 , V_317 -> V_401 ) ;
V_334 = F_11 ( V_2 , V_335 ) ;
switch ( V_334 ) {
case V_338 :
V_67 -> V_269 = V_271 ;
break;
case V_346 :
V_67 -> V_269 = V_418 ;
break;
case V_347 :
V_67 -> V_269 = V_272 ;
break;
case V_348 :
V_67 -> V_269 = V_419 ;
break;
case V_349 :
V_67 -> V_269 = V_420 ;
break;
default:
break;
}
V_67 -> V_189 = F_17 ( V_45 ) ;
F_14 ( L_44 , V_20 , V_67 -> V_189 ) ;
if ( V_43 == 0 ) {
V_67 -> V_189 +=
( F_52 ( V_2 , V_317 -> V_402 ) -
V_317 -> V_402 / 4000 ) ;
return 0 ;
}
if ( V_43 > V_317 -> V_402 / 1000 )
V_67 -> V_189 += ( V_43
- F_52 ( V_2 , V_317 -> V_402 )
- V_317 -> V_402 / 1000 ) ;
else
V_67 -> V_189 += ( V_43
- F_52 ( V_2 , V_317 -> V_402 ) ) ;
return 0 ;
}
static T_4 F_62 ( struct V_1 * V_2 )
{
T_4 V_446 = 0 ;
T_4 V_447 = 0 , V_448 = 0 ;
T_2 V_31 ;
F_9 ( V_2 , V_449 , 0x0 ) ;
V_447 =
( F_11 ( V_2 , V_450 ) & 0x03 ) +
( F_11 ( V_2 , V_451 ) << 2 ) ;
V_447 = 100 * V_447 / 1023 ;
V_448 =
F_11 ( V_2 , V_452 ) +
( F_11 ( V_2 , V_453 ) << 8 ) ;
if ( V_448 >= 2048 )
V_448 -= 2048 ;
else
V_448 += 2048 ;
V_448 = 100 * V_448 / 4095 ;
if ( V_447 < 90 && V_448 < 28 ) {
for ( V_31 = 0 ; V_31 < V_454 ; V_31 ++ ) {
if ( V_447 <= V_455 [ 0 ] [ V_31 ] ) {
V_446 = ( - 1 ) * V_455 [ 1 ] [ V_31 ] ;
break;
}
}
if ( V_31 == V_454 )
V_446 = - 56 ;
} else {
for ( V_31 = 0 ; V_31 < V_456 ; V_31 ++ ) {
if ( V_448 <= V_457 [ 0 ] [ V_31 ] ) {
V_446 = ( - 1 ) * V_457 [ 1 ] [ V_31 ] ;
break;
}
}
if ( V_31 == V_456 )
V_446 = - 72 ;
}
return V_446 ;
}
static int F_63 ( struct V_50 * V_45 , T_1 * V_458 )
{
struct V_1 * V_2 = V_45 -> V_52 ;
T_4 signal = F_62 ( V_2 ) ;
F_14 ( L_45 , V_20 , signal ) ;
if ( signal <= - 72 )
* V_458 = 65535 ;
else
* V_458 = ( 22 + signal ) * ( - 1311 ) ;
F_14 ( L_46 , V_20 , ( * V_458 ) ) ;
return 0 ;
}
static int F_64 ( struct V_50 * V_45 )
{
struct V_1 * V_2 = V_45 -> V_52 ;
enum V_332 V_334 ;
V_334 = F_11 ( V_2 , V_335 ) ;
switch ( V_334 ) {
case V_336 :
return 21904 ;
case V_338 :
return 20480 ;
case V_346 :
return 23040 ;
case V_347 :
return 21504 ;
case V_348 :
return 23616 ;
case V_349 :
return 21760 ;
case V_351 :
return 21280 ;
default:
break;
}
return 1 ;
}
static int F_65 ( struct V_50 * V_45 , int V_459 )
{
struct V_1 * V_2 = V_45 -> V_52 ;
T_3 V_460 = 0 ;
int V_31 ;
for ( V_31 = 0 ; V_31 < 10 ; V_31 ++ ) {
V_460 += ( F_11 ( V_2 , V_461 )
+ 256 * F_11 ( V_2 , V_462 ) ) ;
}
if ( V_459 )
V_460 /= 10 ;
return V_460 ;
}
static int F_66 ( struct V_50 * V_45 , T_1 * V_292 )
{
struct V_1 * V_2 = V_45 -> V_52 ;
T_3 V_463 ;
T_3 V_460 = 0 , V_188 = 0 ;
int V_464 ;
V_464 = F_64 ( V_45 ) ;
V_460 = F_65 ( V_45 , 1 ) ;
if ( V_460 != 0 ) {
V_188 = V_464
* ( 1 << ( 3 + F_11 ( V_2 , V_465 ) ) ) ;
V_188 /= V_460 ;
}
if ( V_188 >= 5012 )
V_463 = 100 ;
else if ( V_188 >= 3981 )
V_463 = 93 ;
else if ( V_188 >= 3162 )
V_463 = 86 ;
else if ( V_188 >= 2512 )
V_463 = 79 ;
else if ( V_188 >= 1995 )
V_463 = 72 ;
else if ( V_188 >= 1585 )
V_463 = 65 ;
else if ( V_188 >= 1259 )
V_463 = 58 ;
else if ( V_188 >= 1000 )
V_463 = 50 ;
else if ( V_188 >= 794 )
V_463 = 43 ;
else if ( V_188 >= 501 )
V_463 = 36 ;
else if ( V_188 >= 316 )
V_463 = 29 ;
else if ( V_188 >= 200 )
V_463 = 22 ;
else if ( V_188 >= 158 )
V_463 = 14 ;
else if ( V_188 >= 126 )
V_463 = 7 ;
else
V_463 = 0 ;
F_14 ( L_47 , V_20 , V_463 ) ;
* V_292 = ( V_463 * 65535 ) / 100 ;
return 0 ;
}
static int F_67 ( struct V_50 * V_45 , T_3 * V_222 )
{
struct V_1 * V_2 = V_45 -> V_52 ;
int V_466 , V_467 ;
* V_222 = ( F_7 ( V_2 , V_468 ) << 8 )
| F_7 ( V_2 , V_469 ) ;
V_466 = ( F_7 ( V_2 , V_470 ) << 8 )
| F_7 ( V_2 , V_471 ) ;
V_467 = ( F_7 ( V_2 , V_471 ) << 8 )
| F_7 ( V_2 , V_472 ) ;
F_14 ( L_48 ,
V_20 , * V_222 , V_466 , V_467 ) ;
return 0 ;
}
struct V_50 * F_68 ( const struct V_318 * V_11 ,
struct V_319 * V_21 )
{
struct V_1 * V_2 = NULL ;
struct V_388 * V_317 = NULL ;
V_2 = F_46 ( sizeof( struct V_1 ) , V_320 ) ;
if ( V_2 == NULL )
goto error;
V_317 = F_46 ( sizeof( struct V_388 ) , V_320 ) ;
if ( V_317 == NULL )
goto error;
V_2 -> V_21 = V_21 ;
V_2 -> V_11 = V_11 ;
V_317 -> V_421 = 280000 ;
V_317 -> V_379 = V_380 ;
V_2 -> V_317 = V_317 ;
V_2 -> V_45 . V_46 = V_473 ;
V_2 -> V_45 . V_52 = V_2 ;
V_2 -> V_175 = F_7 ( V_2 , 0xf000 ) ;
V_2 -> V_244 = 1 ;
V_2 -> V_170 = V_322 ;
V_2 -> V_242 = 1 ;
V_2 -> V_44 = 0 ;
F_14 ( L_31 , V_20 , V_2 -> V_175 ) ;
if ( ( V_2 -> V_175 != 0x50 ) && ( V_2 -> V_175 != 0x60 ) )
goto error;
return & V_2 -> V_45 ;
error:
F_44 ( V_317 ) ;
F_44 ( V_2 ) ;
return NULL ;
}
static void F_69 ( struct V_1 * V_2 )
{
F_6 ( V_2 , V_474 , 0x00 ) ;
F_6 ( V_2 , V_475 , 0x00 ) ;
F_6 ( V_2 , V_476 , 0x00 ) ;
F_6 ( V_2 , V_477 , 0x00 ) ;
F_6 ( V_2 , V_478 , 0x00 ) ;
F_6 ( V_2 , V_479 , 0x00 ) ;
F_6 ( V_2 , V_480 , 0x89 ) ;
F_6 ( V_2 , V_481 , 0x04 ) ;
F_6 ( V_2 , V_172 , 0x0D ) ;
F_6 ( V_2 , V_482 , 0x00 ) ;
F_13 ( V_2 , V_41 , V_2 -> V_11 -> V_37 ) ;
F_34 ( 50 ) ;
F_6 ( V_2 , V_172 , 0x00 ) ;
V_2 -> V_483 = V_484 ;
}
static void F_70 ( struct V_1 * V_2 )
{
F_6 ( V_2 , V_474 , 0x00 ) ;
F_6 ( V_2 , V_475 , 0x01 ) ;
F_6 ( V_2 , V_476 , 0x06 ) ;
F_6 ( V_2 , V_477 , 0x03 ) ;
F_6 ( V_2 , V_478 , 0x00 ) ;
F_6 ( V_2 , V_479 , 0x00 ) ;
F_6 ( V_2 , V_480 , 0x8B ) ;
F_6 ( V_2 , V_481 , 0x04 ) ;
F_6 ( V_2 , V_172 , 0x0D ) ;
F_6 ( V_2 , V_482 , 0x10 ) ;
F_13 ( V_2 , V_38 , V_2 -> V_11 -> V_37 ) ;
F_34 ( 50 ) ;
F_6 ( V_2 , V_172 , 0x00 ) ;
V_2 -> V_317 -> V_401 = F_48 ( & V_2 -> V_45 ,
V_2 -> V_11 -> V_37 ) ;
V_2 -> V_317 -> V_402 = F_49 ( & V_2 -> V_45 ,
V_2 -> V_11 -> V_37 ) ;
V_2 -> V_483 = V_485 ;
}
static int F_71 ( struct V_50 * V_45 )
{
struct V_1 * V_2 = V_45 -> V_52 ;
switch ( V_45 -> V_180 . V_486 ) {
case V_487 :
if ( V_2 -> V_483 != V_484 )
F_69 ( V_2 ) ;
return F_35 ( V_45 ) ;
case V_488 :
if ( V_2 -> V_483 != V_485 )
F_70 ( V_2 ) ;
if ( V_45 -> V_180 . V_417 == 0 ) {
F_2 ( V_22 L_49 ) ;
return - V_17 ;
}
return F_60 ( V_45 ) ;
default:
break;
}
return - V_17 ;
}
static void F_72 ( struct V_50 * V_45 )
{
struct V_1 * V_2 = V_45 -> V_52 ;
struct V_179 * V_67 = & V_45 -> V_180 ;
T_4 V_489 ;
switch ( V_2 -> V_483 ) {
case V_485 :
V_489 = F_62 ( V_2 ) * 1000 ;
break;
default:
V_67 -> V_458 . V_490 [ 0 ] . V_491 = V_492 ;
return;
}
V_67 -> V_458 . V_490 [ 0 ] . V_491 = V_493 ;
V_67 -> V_458 . V_490 [ 0 ] . V_494 = V_489 ;
}
static void F_73 ( struct V_50 * V_45 )
{
struct V_1 * V_2 = V_45 -> V_52 ;
struct V_179 * V_67 = & V_45 -> V_180 ;
int V_495 ;
T_3 V_460 , V_496 , V_293 = 0 ;
switch ( V_2 -> V_483 ) {
case V_484 :
V_293 = F_38 ( V_45 ) ;
break;
case V_485 :
V_495 = F_64 ( V_45 ) ;
V_460 = F_65 ( V_45 , 0 ) ;
if ( ! V_460 ) {
V_293 = 0 ;
break;
}
V_496 = ( V_495 * 320 ) / V_460 ;
V_293 = ( ( V_496 != 0 ) ? ( F_74 ( V_496 ) / 5581 ) : 0 ) ;
break;
default:
V_67 -> V_497 . V_490 [ 0 ] . V_491 = V_492 ;
return;
}
V_67 -> V_497 . V_490 [ 0 ] . V_491 = V_493 ;
V_67 -> V_497 . V_490 [ 0 ] . V_494 = V_293 ;
}
static void F_75 ( struct V_50 * V_45 )
{
struct V_1 * V_2 = V_45 -> V_52 ;
struct V_179 * V_67 = & V_45 -> V_180 ;
T_3 V_222 = 0 ;
switch ( V_2 -> V_483 ) {
case V_484 :
F_36 ( V_45 , & V_222 ) ;
break;
case V_485 :
F_67 ( V_45 , & V_222 ) ;
break;
default:
V_67 -> V_498 . V_490 [ 0 ] . V_491 = V_492 ;
return;
}
V_67 -> V_498 . V_490 [ 0 ] . V_491 = V_499 ;
V_67 -> V_498 . V_490 [ 0 ] . V_494 = V_222 ;
}
static int F_76 ( struct V_50 * V_45 ,
enum V_294 * V_295 )
{
struct V_1 * V_2 = V_45 -> V_52 ;
struct V_179 * V_67 = & V_45 -> V_180 ;
int V_14 ;
switch ( V_2 -> V_483 ) {
case V_484 :
V_14 = F_40 ( V_45 , V_295 ) ;
break;
case V_485 :
V_14 = F_55 ( V_45 , V_295 ) ;
break;
default:
return 0 ;
}
if ( V_14 )
return V_14 ;
F_72 ( V_45 ) ;
if ( * V_295 & V_297 )
F_73 ( V_45 ) ;
else
V_67 -> V_497 . V_490 [ 0 ] . V_491 = V_492 ;
if ( * V_295 & V_300 )
F_75 ( V_45 ) ;
else
V_67 -> V_498 . V_490 [ 0 ] . V_491 = V_492 ;
return 0 ;
}
static int F_77 ( struct V_50 * V_45 ,
struct V_179 * V_67 )
{
struct V_1 * V_2 = V_45 -> V_52 ;
switch ( V_2 -> V_483 ) {
case V_484 :
return F_37 ( V_45 , V_67 ) ;
case V_485 :
return F_61 ( V_45 , V_67 ) ;
default:
break;
}
return - V_17 ;
}
static int F_78 ( struct V_50 * V_45 )
{
struct V_1 * V_2 = V_45 -> V_52 ;
switch ( V_2 -> V_483 ) {
case V_484 :
V_2 -> V_483 = V_500 ;
return F_31 ( V_45 ) ;
case V_485 :
V_2 -> V_483 = V_500 ;
return F_57 ( V_45 ) ;
default:
break;
}
return - V_17 ;
}
static int F_79 ( struct V_1 * V_2 )
{
struct V_166 * V_167 = V_2 -> V_167 ;
struct V_179 * V_67 = & V_2 -> V_45 . V_180 ;
F_6 ( V_2 , V_482 , 0x10 ) ;
if ( V_169 [ V_2 -> V_170 ] [ V_501 ] )
F_12 ( V_2 ,
V_169 [ V_2 -> V_170 ] [ V_501 ] ) ;
F_12 ( V_2 ,
V_169 [ V_2 -> V_170 ] [ V_389 ] ) ;
F_6 ( V_2 , V_482 , 0x00 ) ;
F_12 ( V_2 ,
V_169 [ V_2 -> V_170 ] [ V_171 ] ) ;
F_6 ( V_2 , V_132 , 0x2A ) ;
F_6 ( V_2 , V_502 , 0xD6 ) ;
F_6 ( V_2 , V_503 , 0x55 ) ;
F_6 ( V_2 , V_504 , 0x55 ) ;
F_6 ( V_2 , V_505 , 0x14 ) ;
F_6 ( V_2 , V_506 , 0xAE ) ;
F_6 ( V_2 , V_507 , 0x56 ) ;
F_6 ( V_2 , V_508 , 0x0 ) ;
F_6 ( V_2 , V_509 , 0x70 ) ;
F_6 ( V_2 , V_510 , 0xC0 ) ;
F_6 ( V_2 , V_511 , 0x20 ) ;
F_6 ( V_2 , V_512 , 0x40 ) ;
F_6 ( V_2 , V_509 , 0x71 ) ;
F_6 ( V_2 , V_509 , 0x70 ) ;
F_6 ( V_2 , V_482 , 0x10 ) ;
F_6 ( V_2 , V_513 , 0x01 ) ;
F_6 ( V_2 , V_514 , 0x8A ) ;
F_6 ( V_2 , V_515 , 0x85 ) ;
F_6 ( V_2 , V_172 , 0x0D ) ;
F_13 ( V_2 , V_38 , V_2 -> V_11 -> V_37 ) ;
F_6 ( V_2 , V_480 , 0x8b ) ;
F_6 ( V_2 , V_481 , 0x04 ) ;
F_6 ( V_2 , V_516 , 0x23 ) ;
F_6 ( V_2 , V_517 , 0x01 ) ;
F_6 ( V_2 , V_518 , 0x83 ) ;
F_6 ( V_2 , V_519 , 0x05 ) ;
F_6 ( V_2 , V_172 , 0x00 ) ;
F_6 ( V_2 , V_54 , ( 0x08 | ( ( 5 & 0x07 ) << 4 ) ) ) ;
V_167 -> V_168 = 0 ;
V_167 -> V_177 = 0 ;
V_167 -> V_178 = 2 ;
V_67 -> V_458 . V_5 = 1 ;
V_67 -> V_458 . V_490 [ 0 ] . V_491 = V_492 ;
V_67 -> V_497 . V_5 = 1 ;
V_67 -> V_497 . V_490 [ 0 ] . V_491 = V_492 ;
V_67 -> V_498 . V_5 = 1 ;
V_67 -> V_498 . V_490 [ 0 ] . V_491 = V_492 ;
return 0 ;
}
struct V_50 * F_80 ( const struct V_318 * V_11 ,
struct V_319 * V_21 )
{
struct V_1 * V_2 = NULL ;
struct V_166 * V_167 = NULL ;
struct V_388 * V_317 = NULL ;
V_2 = F_46 ( sizeof( struct V_1 ) , V_320 ) ;
if ( V_2 == NULL )
goto error;
V_167 = F_46 ( sizeof( struct V_166 ) , V_320 ) ;
if ( V_167 == NULL )
goto error;
V_317 = F_46 ( sizeof( struct V_388 ) , V_320 ) ;
if ( V_317 == NULL )
goto error;
V_2 -> V_21 = V_21 ;
V_2 -> V_11 = V_11 ;
V_2 -> V_167 = V_167 ;
V_317 -> V_421 = 280000 ;
V_317 -> V_379 = V_520 ;
V_2 -> V_317 = V_317 ;
V_2 -> V_45 . V_46 = V_521 ;
V_2 -> V_45 . V_52 = V_2 ;
V_2 -> V_175 = F_7 ( V_2 , V_176 ) ;
V_2 -> V_244 = 0 ;
V_2 -> V_170 = V_522 ;
V_2 -> V_242 = 0 ;
V_2 -> V_44 = 1 ;
V_2 -> V_483 = V_500 ;
F_14 ( L_31 , V_20 , V_2 -> V_175 ) ;
if ( ( V_2 -> V_175 != 0x50 ) && ( V_2 -> V_175 != 0x60 ) )
goto error;
F_81 ( & V_21 -> V_523 , L_50 ,
V_2 -> V_45 . V_46 . V_524 . V_525 , V_2 -> V_175 ,
V_11 -> V_12 ) ;
F_79 ( V_2 ) ;
return & V_2 -> V_45 ;
error:
F_44 ( V_317 ) ;
F_44 ( V_167 ) ;
F_44 ( V_2 ) ;
return NULL ;
}
