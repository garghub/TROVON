static
int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_2 * V_4 , int V_5 )
{
T_2 V_6 [ V_5 + 2 ] ;
struct V_7 V_8 = {
. V_9 = V_2 -> V_10 -> V_11 ,
. V_12 = 0 ,
. V_6 = V_6 ,
. V_5 = V_5 + 2
} ;
int V_13 ;
V_6 [ 0 ] = F_2 ( V_3 ) ;
V_6 [ 1 ] = F_3 ( V_3 ) ;
memcpy ( V_6 + 2 , V_4 , V_5 ) ;
if ( V_14 )
F_4 ( V_15 L_1 , V_16 , V_3 , V_6 [ 2 ] ) ;
V_13 = F_5 ( V_2 -> V_17 , & V_8 , 1 ) ;
if ( V_13 != 1 )
F_4 ( V_18 L_2 , V_16 ) ;
return ( V_13 != 1 ) ? - V_19 : 0 ;
}
static int F_6 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 )
{
return F_1 ( V_2 , V_3 , & V_4 , 1 ) ;
}
static T_2 F_7 ( struct V_1 * V_2 , T_1 V_3 )
{
T_2 V_20 [] = { 0 , 0 } ;
T_2 V_21 [] = { 0 } ;
struct V_7 V_8 [] = {
{
. V_9 = V_2 -> V_10 -> V_11 ,
. V_12 = 0 ,
. V_6 = V_20 ,
. V_5 = 2
} , {
. V_9 = V_2 -> V_10 -> V_11 ,
. V_12 = V_22 ,
. V_6 = V_21 ,
. V_5 = 1
}
} ;
int V_13 ;
V_20 [ 0 ] = F_2 ( V_3 ) ;
V_20 [ 1 ] = F_3 ( V_3 ) ;
V_13 = F_5 ( V_2 -> V_17 , V_8 , 2 ) ;
if ( V_13 != 2 )
F_4 ( V_18 L_3 , V_16 ) ;
if ( V_14 )
F_4 ( V_15 L_1 , V_16 , V_3 , V_21 [ 0 ] ) ;
return V_21 [ 0 ] ;
}
static void F_8 ( T_3 V_23 , T_2 * V_24 , T_2 * V_25 )
{
T_2 V_26 = 0 , V_27 = 0 ;
( * V_24 ) = V_23 & 0xff ;
while ( ( V_26 == 0 ) && ( V_27 < 8 ) ) {
V_26 = ( ( * V_24 ) >> V_27 ) & 0x01 ;
V_27 ++ ;
}
( * V_25 ) = ( V_27 - 1 ) ;
}
static void F_9 ( struct V_1 * V_2 , T_3 V_23 , T_2 V_28 )
{
T_2 V_3 , V_24 , V_25 ;
V_3 = F_7 ( V_2 , ( V_23 >> 16 ) & 0xffff ) ;
F_8 ( V_23 , & V_24 , & V_25 ) ;
V_28 = V_24 & ( V_28 << V_25 ) ;
V_3 = ( V_3 & ( ~ V_24 ) ) | V_28 ;
F_6 ( V_2 , ( V_23 >> 16 ) & 0xffff , V_3 ) ;
}
static void F_10 ( T_2 * V_3 , T_3 V_23 , T_2 V_28 )
{
T_2 V_24 , V_25 ;
F_8 ( V_23 , & V_24 , & V_25 ) ;
V_28 = V_24 & ( V_28 << V_25 ) ;
( * V_3 ) = ( ( * V_3 ) & ( ~ V_24 ) ) | V_28 ;
}
static T_2 F_11 ( struct V_1 * V_2 , T_3 V_23 )
{
T_2 V_28 = 0xff ;
T_2 V_24 , V_25 ;
F_8 ( V_23 , & V_24 , & V_25 ) ;
V_28 = F_7 ( V_2 , V_23 >> 16 ) ;
V_28 = ( V_28 & V_24 ) >> V_25 ;
return V_28 ;
}
T_2 F_12 ( T_2 V_3 , T_3 V_23 )
{
T_2 V_24 , V_25 ;
F_8 ( V_23 , & V_24 , & V_25 ) ;
return ( V_3 & V_24 ) >> V_25 ;
}
static int F_13 ( struct V_29 * V_30 , int V_31 )
{
struct V_1 * V_2 = V_30 -> V_32 ;
T_2 V_33 = F_7 ( V_2 , V_34 ) ;
F_14 ( L_4 , V_16 ) ;
if ( V_31 ) {
F_10 ( & V_33 , V_35 , 0 ) ;
F_10 ( & V_33 , V_36 , 1 ) ;
} else {
F_10 ( & V_33 , V_35 , 1 ) ;
F_10 ( & V_33 , V_36 , 0 ) ;
}
F_6 ( V_2 , V_34 , V_33 ) ;
return 0 ;
}
static T_3 F_15 ( struct V_29 * V_30 )
{
struct V_37 * V_38 = NULL ;
struct V_39 * V_40 = NULL ;
T_3 V_41 = 0 ;
int V_42 = 0 ;
F_14 ( L_4 , V_16 ) ;
if ( & V_30 -> V_43 )
V_38 = & V_30 -> V_43 ;
if ( & V_38 -> V_40 )
V_40 = & V_38 -> V_40 ;
if ( V_40 -> V_44 ) {
V_42 = V_40 -> V_44 ( V_30 , & V_41 ) ;
if ( V_42 < 0 ) {
F_4 ( V_18 L_5 , V_16 ) ;
return V_42 ;
}
F_14 ( L_6 , V_16 , V_41 ) ;
} else
return - 1 ;
return V_41 ;
}
static T_3 F_16 ( struct V_1 * V_2 , T_3 V_45 )
{
T_3 V_46 = 0 ;
T_3 V_47 , V_48 , V_49 ;
F_14 ( L_4 , V_16 ) ;
if ( F_11 ( V_2 , V_50 ) == 0 ) {
V_48 = ( T_3 ) F_11 ( V_2 , V_51 ) ;
if ( V_48 == 0 )
V_48 = V_48 + 1 ;
V_47 = ( T_3 ) F_11 ( V_2 , V_52 ) ;
if ( V_47 == 0 )
V_47 = V_47 + 1 ;
V_49 = ( T_3 ) F_11 ( V_2 , V_53 ) ;
if ( V_49 > 5 )
V_49 = 5 ;
V_46 = ( ( V_45 / 2 ) * V_48 ) / ( V_47 * ( 1 << V_49 ) ) ;
F_14 ( L_7 ,
V_48 , V_47 , V_49 , V_46 , V_45 ) ;
} else
V_46 = V_45 ;
F_14 ( L_8 , V_16 , V_46 ) ;
return V_46 ;
}
static int F_17 ( struct V_1 * V_2 ,
T_1 V_54 [ 3 ] [ 6 ] [ 5 ] , T_3 V_55 )
{
int V_27 , V_56 , V_57 , V_41 ;
F_14 ( L_4 , V_16 ) ;
V_41 = F_16 ( V_2 , V_55 ) ;
if ( V_41 == 53125000 )
V_57 = 1 ;
else if ( V_41 == 54000000 )
V_57 = 0 ;
else if ( V_41 == 52500000 )
V_57 = 2 ;
else
return 0 ;
for ( V_27 = 1 ; V_27 <= 6 ; V_27 ++ ) {
F_9 ( V_2 , V_58 , V_27 - 1 ) ;
for ( V_56 = 1 ; V_56 <= 5 ; V_56 ++ ) {
F_6 ( V_2 ,
( V_59 + 2 * ( V_56 - 1 ) ) ,
F_2 ( V_54 [ V_57 ] [ V_27 - 1 ] [ V_56 - 1 ] ) ) ;
F_6 ( V_2 ,
( V_60 + 2 * ( V_56 - 1 ) ) ,
F_3 ( V_54 [ V_57 ] [ V_27 - 1 ] [ V_56 - 1 ] ) ) ;
}
}
return 1 ;
}
static void F_18 ( struct V_1 * V_2 )
{
F_14 ( L_4 , V_16 ) ;
F_9 ( V_2 , V_61 , 0x00 ) ;
F_9 ( V_2 , V_62 , 0x00 ) ;
F_9 ( V_2 , V_63 , 0x06 ) ;
F_9 ( V_2 , V_64 , 0x04 ) ;
F_9 ( V_2 , V_62 , 0x01 ) ;
F_9 ( V_2 , V_63 , 0x06 ) ;
F_9 ( V_2 , V_64 , 0x04 ) ;
F_9 ( V_2 , V_62 , 0x02 ) ;
F_9 ( V_2 , V_63 , 0x01 ) ;
F_9 ( V_2 , V_64 , 0x00 ) ;
F_9 ( V_2 , V_62 , 0x03 ) ;
F_9 ( V_2 , V_63 , 0x01 ) ;
F_9 ( V_2 , V_64 , 0x00 ) ;
}
static int F_19 ( struct V_1 * V_2 , T_2 V_65 ,
T_3 V_66 )
{
F_14 ( L_4 , V_16 ) ;
F_9 ( V_2 , V_67 , 0 ) ;
switch ( V_65 ) {
case 6 :
if ( ! F_17 ( V_2 ,
V_68 ,
V_66 ) )
return 0 ;
break;
case 7 :
if ( ! F_17 ( V_2 ,
V_69 ,
V_66 ) )
return 0 ;
break;
case 8 :
if ( ! F_17 ( V_2 ,
V_70 ,
V_66 ) )
return 0 ;
break;
default:
return 0 ;
}
F_9 ( V_2 , V_67 , 1 ) ;
return 1 ;
}
static void F_20 ( struct V_1 * V_2 )
{
T_2 V_71 ;
F_14 ( L_4 , V_16 ) ;
V_71 = F_11 ( V_2 , V_72 ) ;
F_9 ( V_2 , V_72 , 0x07 ) ;
F_9 ( V_2 , V_73 , 0x00 ) ;
F_9 ( V_2 , V_74 , 0x00 ) ;
F_9 ( V_2 , V_73 , 0x01 ) ;
F_9 ( V_2 , V_74 , 0x01 ) ;
F_9 ( V_2 , V_72 , V_71 ) ;
}
static int F_21 ( T_4 V_75 , int V_76 , int V_77 , int V_78 )
{
int V_79 = 0 ;
switch ( V_75 ) {
case 0 :
V_79 = V_76 ;
break;
case 1 :
V_79 = V_77 ;
break ;
case 2 :
V_79 = V_78 ;
break;
default:
break;
}
return V_79 ;
}
static enum
V_80 F_22 ( struct V_1 * V_2 )
{
int V_81 = 100 ;
unsigned short int V_82 ;
T_4 V_83 ;
F_14 ( L_4 , V_16 ) ;
V_82 = F_11 ( V_2 , V_84 ) ;
while ( ( ! V_82 ) && ( V_81 > 0 ) ) {
F_23 ( 2000 , 3000 ) ;
V_81 -= 2 ;
V_82 = F_11 ( V_2 , V_84 ) ;
}
if ( ! V_82 )
V_83 = V_85 ;
else
V_83 = V_86 ;
F_14 ( L_9 ,
V_82 == 0 ? L_10 : L_11 ) ;
return V_83 ;
}
static enum
V_80 F_24 ( struct V_1 * V_2 ,
T_4 V_87 )
{
T_4 V_88 = 0 , V_89 , V_90 ;
int V_81 = 0 ;
F_14 ( L_4 , V_16 ) ;
switch ( V_87 ) {
case 0 :
V_90 = 20 ;
V_81 = 10 ;
break;
case 1 :
V_90 = 80 ;
V_81 = 55 ;
break;
case 2 :
V_90 = 40 ;
V_81 = 30 ;
break;
default:
V_90 = 0xffff ;
break;
}
F_14 ( L_12 , V_16 , V_90 , V_81 ) ;
V_88 = F_11 ( V_2 , V_91 ) ;
while ( ( V_88 < V_90 ) && ( V_81 > 0 ) ) {
F_23 ( 1000 , 2000 ) ;
V_81 -= 1 ;
V_88 = F_11 ( V_2 , V_91 ) ;
}
F_14 ( L_13 , V_88 , V_81 ) ;
if ( V_88 < V_90 ) {
V_89 = V_92 ;
F_4 ( V_18 L_14 ) ;
} else {
F_4 ( V_18 L_15 ) ;
V_89 = V_93 ;
}
return V_89 ;
}
enum
V_80 F_25 ( struct V_1 * V_2 )
{
enum V_80 V_94 ;
short int V_81 , V_95 ;
T_2 V_96 , V_97 = 0 , V_98 = 0 , V_99 = 0 , V_100 = 0 , V_75 , V_101 ;
T_2 V_33 , V_102 ;
F_14 ( L_4 , V_16 ) ;
if ( V_2 == NULL )
return V_103 ;
V_96 = 0 ;
do {
V_94 = V_104 ;
F_9 ( V_2 , V_105 , 0 ) ;
if ( V_2 -> V_10 -> V_106 != 0 )
F_9 ( V_2 , V_72 , 0x07 ) ;
F_9 ( V_2 , V_107 , 3 ) ;
F_9 ( V_2 , V_108 , 0 ) ;
F_9 ( V_2 , V_109 , 0 ) ;
F_23 ( 5000 , 10000 ) ;
F_9 ( V_2 , V_105 , 1 ) ;
if ( F_22 ( V_2 ) == V_85 )
return V_85 ;
else {
V_75 = F_11 ( V_2 , V_110 ) ;
if ( F_24 ( V_2 , V_75 ) ==
V_92 ) {
if ( V_96 == 0 )
V_94 = V_92 ;
}
}
V_96 ++ ;
} while ( ( V_96 < 10 ) && ( V_94 != V_104 ) );
V_33 = F_7 ( V_2 , V_111 ) ;
V_102 = F_7 ( V_2 , V_112 ) ;
F_14 ( L_16 , V_2 ) ;
F_14 ( L_17 ,
V_75 , V_33 , V_102 ) ;
V_33 = F_7 ( V_2 , V_113 ) ;
V_102 = F_7 ( V_2 , V_34 ) ;
F_14 ( L_18 , V_33 , V_102 ) ;
V_33 = F_7 ( V_2 , V_114 ) ;
F_14 ( L_19 , V_33 ) ;
if ( ( V_75 != 0 ) && ( V_75 != 1 ) && ( V_75 != 2 ) )
return V_103 ;
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
F_9 ( V_2 , V_115 , 1 ) ;
F_9 ( V_2 , V_116 , 1 ) ;
F_23 ( 1000 , 2000 ) ;
F_9 ( V_2 , V_115 , 0 ) ;
F_9 ( V_2 , V_116 , 0 ) ;
V_97 = F_11 ( V_2 , V_117 ) ;
V_98 = F_11 ( V_2 , V_118 ) ;
V_99 = F_11 ( V_2 , V_119 ) ;
V_81 = F_21 ( V_75 , 125 , 500 , 250 ) ;
V_95 = F_21 ( V_75 , 4 , 16 , 8 ) ;
while ( ( ( ! V_97 ) || ( ! V_98 ) || ( ! V_99 ) ) && ( V_81 >= 0 ) ) {
F_23 ( 1000 * V_95 , 1000 * ( V_95 + 1 ) ) ;
V_81 -= V_95 ;
V_97 = F_11 ( V_2 , V_117 ) ;
V_98 = F_11 ( V_2 , V_118 ) ;
V_99 = F_11 ( V_2 , V_119 ) ;
}
if ( ! V_97 )
return V_120 ;
if ( ! V_98 )
return V_121 ;
if ( ! V_99 )
return V_122 ;
V_101 = F_11 ( V_2 , V_123 ) ;
F_6 ( V_2 , V_124 , 0x11 ) ;
switch ( V_101 ) {
case 0 :
case 1 :
F_9 ( V_2 , V_125 , 0 ) ;
F_9 ( V_2 , V_126 , 0 ) ;
break;
case 2 :
case 3 :
F_9 ( V_2 , V_125 , 1 ) ;
F_9 ( V_2 , V_126 , 1 ) ;
break;
default:
return V_103 ;
}
if ( ( F_11 ( V_2 , V_127 ) == 2 ) &&
( V_75 == 1 ) &&
( F_11 ( V_2 , V_128 ) != 0 ) ) {
F_6 ( V_2 , V_129 , 0xc0 ) ;
F_6 ( V_2 , V_130 , 0x60 ) ;
F_6 ( V_2 , V_131 , 0x0 ) ;
} else
F_6 ( V_2 , V_129 , 0x0 ) ;
V_81 = F_21 ( V_75 , 125 , 500 , 250 ) ;
V_100 = F_11 ( V_2 , V_132 ) ;
while ( ( ! V_100 ) && ( V_81 >= 0 ) ) {
F_23 ( 1000 * V_95 , 1000 * ( V_95 + 1 ) ) ;
V_81 -= V_95 ;
V_100 = F_11 ( V_2 , V_132 ) ;
}
if ( ! V_100 )
return V_120 ;
F_9 ( V_2 , V_109 , 1 ) ;
F_14 ( L_20 ) ;
return V_104 ;
}
static void F_26 ( struct V_1 * V_2 ,
enum V_133 V_134 )
{
F_14 ( L_4 , V_16 ) ;
if ( V_2 == NULL )
return;
F_9 ( V_2 , V_135 , 0 ) ;
switch ( V_134 ) {
default:
case V_136 :
F_9 ( V_2 , V_137 , 0 ) ;
F_9 ( V_2 , V_138 , 0 ) ;
break;
case V_139 :
F_9 ( V_2 , V_137 , 1 ) ;
F_9 ( V_2 , V_138 , 1 ) ;
break;
}
}
static void F_27 ( struct V_1 * V_2 ,
enum V_140 clock )
{
F_14 ( L_4 , V_16 ) ;
if ( V_2 == NULL )
return;
switch ( clock ) {
case V_141 :
F_9 ( V_2 , V_142 , 1 ) ;
break;
case V_143 :
F_9 ( V_2 , V_142 , 0 ) ;
break;
default:
F_9 ( V_2 , V_142 , 0 ) ;
break;
}
}
static int F_28 ( struct V_29 * V_30 , T_2 V_144 )
{
struct V_1 * V_2 = V_30 -> V_32 ;
F_14 ( L_4 , V_16 ) ;
if ( V_144 ) {
F_9 ( V_2 , V_145 , 1 ) ;
F_9 ( V_2 , V_146 , 1 ) ;
F_9 ( V_2 , V_147 , 1 ) ;
} else {
F_9 ( V_2 , V_145 , 0 ) ;
F_9 ( V_2 , V_146 , 0 ) ;
F_9 ( V_2 , V_147 , 0 ) ;
}
return 0 ;
}
static int F_29 ( struct V_29 * V_30 )
{
return F_28 ( V_30 , 1 ) ;
}
int F_30 ( struct V_29 * V_30 )
{
struct V_1 * V_2 = V_30 -> V_32 ;
struct V_148 * V_149 = V_2 -> V_149 ;
int V_27 ;
F_14 ( L_4 , V_16 ) ;
V_149 -> V_150 = 0 ;
for ( V_27 = 0 ; V_27 < V_151 ; V_27 ++ )
F_6 ( V_2 , V_152 [ V_27 ] . V_9 ,
V_152 [ V_27 ] . V_153 ) ;
switch ( V_2 -> V_10 -> V_154 ) {
case 25000000 :
F_6 ( V_2 , V_155 , 0xa ) ;
F_6 ( V_2 , V_156 , 0x55 ) ;
F_6 ( V_2 , V_157 , 0x18 ) ;
break;
default:
case 27000000 :
F_14 ( L_21 ) ;
F_6 ( V_2 , V_155 , 0x1 ) ;
F_6 ( V_2 , V_156 , 0x8 ) ;
F_6 ( V_2 , V_157 , 0x18 ) ;
break;
case 30000000 :
F_6 ( V_2 , V_155 , 0xc ) ;
F_6 ( V_2 , V_156 , 0x55 ) ;
F_6 ( V_2 , V_157 , 0x18 ) ;
break;
}
F_6 ( V_2 , V_34 , 0xa0 ) ;
F_6 ( V_2 , V_158 , 0x00 ) ;
F_26 ( V_2 , V_2 -> V_10 -> V_159 ) ;
F_27 ( V_2 , V_2 -> V_10 -> V_160 ) ;
V_2 -> V_161 = F_7 ( V_2 , V_162 ) ;
V_149 -> V_163 = 0 ;
V_149 -> V_164 = 2 ;
return 0 ;
}
static int F_31 ( struct V_29 * V_30 )
{
struct V_165 * V_49 = & V_30 -> V_166 ;
struct V_1 * V_2 = V_30 -> V_32 ;
struct V_148 * V_149 = V_2 -> V_149 ;
int V_167 = 0 , V_95 = 0 ;
T_2 V_168 ;
T_2 V_169 , V_170 [ 2 ] ;
T_5 V_171 ;
T_4 V_172 = 0 ;
T_3 V_173 = 0 , V_174 = 0 , V_175 = 0 ;
F_14 ( L_4 , V_16 ) ;
V_149 -> V_176 = V_49 -> V_176 ;
V_149 -> V_177 = V_178
+ F_11 ( V_2 , V_179 ) * 2 ;
V_149 -> V_106 = V_2 -> V_10 -> V_106 ;
switch ( V_2 -> V_10 -> V_106 ) {
case V_180 :
F_14 ( L_22 ) ;
F_9 ( V_2 , V_181 , 0 ) ;
F_9 ( V_2 , V_182 , 0 ) ;
F_9 ( V_2 , V_183 , 0 ) ;
break;
case V_184 :
F_14 ( L_23 ) ;
F_9 ( V_2 , V_181 , 0 ) ;
F_9 ( V_2 , V_182 , 1 ) ;
F_9 ( V_2 , V_183 , 1 ) ;
break;
case V_185 :
F_14 ( L_24 ) ;
F_9 ( V_2 , V_181 , 1 ) ;
F_9 ( V_2 , V_186 , 0 ) ;
break;
default:
F_4 ( V_18 L_25 ) ;
return - V_187 ;
}
F_23 ( 5000 , 7000 ) ;
switch ( V_49 -> V_188 ) {
case V_189 :
default:
F_14 ( L_26 , V_16 ) ;
if ( V_149 -> V_106 == V_185 )
F_9 ( V_2 , V_190 ,
V_149 -> V_191 ) ;
else
F_9 ( V_2 , V_192 ,
V_149 -> V_191 ) ;
break;
case V_193 :
case V_194 :
if ( V_149 -> V_106 == V_185 )
F_9 ( V_2 , V_190 ,
V_49 -> V_188 ) ;
else
F_9 ( V_2 , V_192 ,
V_49 -> V_188 ) ;
break;
}
if ( ( V_149 -> V_106 != V_180 ) &&
( V_149 -> V_195 != V_149 -> V_196 ) ) {
F_18 ( V_2 ) ;
F_9 ( V_2 , V_197 , 1 ) ;
F_9 ( V_2 , V_198 , 0xB ) ;
F_9 ( V_2 , V_197 , 0 ) ;
F_9 ( V_2 , V_198 , 0xB ) ;
if ( ! F_19 ( V_2 , V_149 -> V_196 ,
V_2 -> V_10 -> V_154 ) )
return - V_187 ;
V_149 -> V_195 = V_149 -> V_196 ;
F_20 ( V_2 ) ;
}
if ( V_149 -> V_199 == V_200 )
F_9 ( V_2 , V_201 , 0x01 ) ;
else
F_9 ( V_2 , V_201 , 0x00 ) ;
V_174 = F_16 ( V_2 , V_2 -> V_10 -> V_154 ) / 1000 ;
V_175 = ( int )
( ( ( ( V_149 -> V_196 * 64 * ( 1 << 15 ) * 100 )
/ ( V_174 ) ) * 10 ) / 7 ) ;
F_9 ( V_2 , V_202 , V_175 % 2 ) ;
V_175 = V_175 / 2 ;
F_9 ( V_2 , V_203 , V_175 / 256 ) ;
F_9 ( V_2 , V_204 , V_175 % 256 ) ;
V_175 = F_11 ( V_2 , V_203 ) * 512 +
F_11 ( V_2 , V_204 ) * 2 +
F_11 ( V_2 , V_202 ) ;
V_175 = ( int ) ( ( ( 1 << 17 ) * V_149 -> V_196 * 1000 ) / ( 7 * ( V_174 ) ) ) ;
F_9 ( V_2 , V_205 , V_175 / 256 ) ;
F_9 ( V_2 , V_206 , V_175 % 256 ) ;
V_175 = F_11 ( V_2 , V_205 ) * 256 +
F_11 ( V_2 , V_206 ) ;
V_175 = ( int )
( ( V_174 - V_2 -> V_10 -> V_207 ) * ( 1 << 16 )
/ ( V_174 ) ) ;
F_14 ( L_27 , V_175 ) ;
F_9 ( V_2 , V_208 , V_175 / 256 ) ;
F_9 ( V_2 , V_209 , V_175 % 256 ) ;
V_149 -> V_210 = 0 ;
V_149 -> V_211 = 0 ;
V_149 -> V_150 = 0 ;
F_9 ( V_2 , V_212 , V_149 -> V_210 ) ;
if ( F_25 ( V_2 ) != V_104 )
return 0 ;
V_149 -> V_2 = V_104 ;
V_170 [ 0 ] = F_7 ( V_2 , V_213 ) ;
V_170 [ 1 ] = F_7 ( V_2 , V_214 ) ;
V_149 -> V_75 = F_11 ( V_2 , V_110 ) ;
V_149 -> V_101 = F_11 ( V_2 , V_123 ) ;
V_149 -> V_163 = 1 ;
V_149 -> V_215 =
( F_11 ( V_2 , V_216 ) << 16 ) +
( F_11 ( V_2 , V_217 ) << 24 ) +
F_11 ( V_2 , V_218 ) +
( F_11 ( V_2 , V_219 ) << 8 ) ;
F_9 ( V_2 , V_220 , 1 ) ;
V_167 = ( F_11 ( V_2 , V_221 ) << 16 ) ;
V_167 += ( F_11 ( V_2 , V_222 ) << 8 ) ;
V_167 += ( F_11 ( V_2 , V_223 ) ) ;
F_9 ( V_2 , V_220 , 0 ) ;
if ( V_167 > 8388607 )
V_167 -= 16777216 ;
V_167 = V_167 * 2 / 16384 ;
if ( V_149 -> V_75 == V_224 )
V_167 = ( V_167 * 4464 ) / 1000 ;
else if ( V_149 -> V_75 == V_225 )
V_167 = ( V_167 * 223 ) / 100 ;
else if ( V_149 -> V_75 == V_226 )
V_167 = ( V_167 * 111 ) / 100 ;
if ( F_11 ( V_2 , V_186 ) == 1 ) {
if ( ( F_11 ( V_2 , V_192 ) ==
( F_11 ( V_2 ,
V_227 ) == 1 ) ) )
V_167 = V_167 * - 1 ;
}
if ( V_149 -> V_196 == 6 )
V_167 = ( V_167 * 6 ) / 8 ;
else if ( V_149 -> V_196 == 7 )
V_167 = ( V_167 * 7 ) / 8 ;
V_149 -> V_176 += V_167 ;
V_95 = 10 ;
while ( ( V_172 == 0 ) && ( V_95 > 0 ) ) {
F_23 ( 10000 , 20000 ) ;
V_172 = F_11 ( V_2 , V_228 )
+ 256 * F_11 ( V_2 ,
V_229 ) ;
if ( V_172 >= 32768 )
V_172 -= 65536 ;
V_173 = ( 512 * F_11 ( V_2 ,
V_203 )
+ F_11 ( V_2 , V_204 ) * 2
+ F_11 ( V_2 , V_202 ) ) ;
V_172 = ( ( signed ) ( 1000000 / V_173 ) *
V_172 ) / 2048 ;
V_95 -- ;
}
if ( V_172 <= 0 ) {
V_172 = ( V_172 - 11 ) / 22 ;
V_171 = - 1 ;
} else {
V_172 = ( V_172 + 11 ) / 22 ;
V_171 = 1 ;
}
for ( V_169 = 0 ; V_169 < abs ( V_172 ) ; V_169 ++ ) {
V_173 += V_171 ;
F_9 ( V_2 , V_202 ,
V_173 % 2 ) ;
F_9 ( V_2 , V_204 ,
V_173 / 2 ) ;
F_23 ( 1000 , 2000 ) ;
}
F_23 ( 5000 , 6000 ) ;
V_168 = F_11 ( V_2 , V_117 ) ;
if ( ! V_168 ) {
F_9 ( V_2 , V_105 , 0 ) ;
F_32 ( 20 ) ;
F_9 ( V_2 , V_105 , 1 ) ;
}
return 0 ;
}
static int F_33 ( struct V_29 * V_30 )
{
struct V_165 * V_49 = & V_30 -> V_166 ;
struct V_1 * V_2 = V_30 -> V_32 ;
struct V_148 * V_149 = V_2 -> V_149 ;
T_5 V_230 , V_231 ;
T_2 V_232 [] = { V_193 , V_194 } ;
F_30 ( V_30 ) ;
if ( V_30 -> V_43 . V_40 . V_233 ) {
if ( V_30 -> V_43 . V_234 )
V_30 -> V_43 . V_234 ( V_30 , 1 ) ;
V_30 -> V_43 . V_40 . V_233 ( V_30 ) ;
if ( V_30 -> V_43 . V_234 )
V_30 -> V_43 . V_234 ( V_30 , 0 ) ;
}
switch ( V_49 -> V_235 ) {
default:
case V_236 :
case V_237 :
V_149 -> V_75 = V_224 ;
break;
case V_238 :
V_149 -> V_75 = V_226 ;
break;
}
switch ( V_49 -> V_239 ) {
default:
case V_240 :
case V_241 :
case V_242 :
case V_243 :
V_149 -> V_101 = V_49 -> V_239 ;
break;
case V_244 :
V_149 -> V_101 = V_240 ;
break;
}
switch ( V_49 -> V_245 ) {
case 6000000 :
V_149 -> V_196 = V_246 ;
break;
case 7000000 :
V_149 -> V_196 = V_247 ;
break;
case 8000000 :
default:
V_149 -> V_196 = V_248 ;
}
V_149 -> V_199 = V_249 ;
switch ( V_49 -> V_188 ) {
case V_194 :
case V_193 :
V_230 = 1 ;
break;
default:
V_230 = 2 ;
if ( V_149 -> V_163 )
V_230 = 1 ;
break;
}
V_149 -> V_2 = V_120 ;
V_231 = 0 ;
while ( ( ( V_231 ) < V_230 ) && ( V_149 -> V_2 != V_104 ) ) {
if ( ! V_149 -> V_163 ) {
if ( V_49 -> V_188 == V_189 )
V_149 -> V_191 = V_232 [ V_231 ] ;
}
F_31 ( V_30 ) ;
if ( ( V_149 -> V_2 == V_104 ) &&
( V_49 -> V_188 == V_189 ) &&
( V_231 == 1 ) ) {
V_232 [ V_231 ] = V_232 [ 0 ] ;
V_232 [ ( V_231 + 1 ) % 2 ] = ( V_232 [ 1 ] + 1 ) % 2 ;
}
V_231 ++ ;
}
return 0 ;
}
static int F_34 ( struct V_29 * V_30 , T_3 * V_211 )
{
struct V_1 * V_2 = V_30 -> V_32 ;
struct V_148 * V_149 = V_2 -> V_149 ;
T_3 V_250 = 0 ;
if ( F_11 ( V_2 , V_251 ) == 0 ) {
V_250 =
( ( T_3 ) F_11 ( V_2 , V_252 )
* ( 1 << 16 ) )
+ ( ( T_3 ) F_11 ( V_2 , V_253 )
* ( 1 << 8 ) )
+ ( ( T_3 ) F_11 ( V_2 , V_254 ) ) ;
V_149 -> V_211 = V_250 ;
}
( * V_211 ) = V_149 -> V_211 ;
return 0 ;
}
static int F_35 ( struct V_29 * V_30 )
{
struct V_165 * V_49 = & V_30 -> V_166 ;
struct V_1 * V_2 = V_30 -> V_32 ;
struct V_148 * V_149 = V_2 -> V_149 ;
int error = 0 ;
enum V_255 V_75 ;
int V_256 = 0 , V_257 = 0 ;
V_49 -> V_176 = F_15 ( V_30 ) ;
if ( ( int ) V_49 -> V_176 < 0 )
V_49 -> V_176 = - V_49 -> V_176 ;
V_256 = F_11 ( V_2 , V_127 ) ;
if ( V_256 == 0 )
V_49 -> V_258 = V_259 ;
else if ( V_256 == 1 )
V_49 -> V_258 = V_260 ;
else
V_49 -> V_258 = V_261 ;
V_49 -> V_188 = F_11 ( V_2 , V_192 ) ;
V_257 = F_11 ( V_2 , V_262 ) ;
switch ( V_257 ) {
case 0 :
V_49 -> V_199 = V_263 ;
break;
case 1 :
V_49 -> V_199 = V_264 ;
break;
case 2 :
V_49 -> V_199 = V_265 ;
break;
case 3 :
V_49 -> V_199 = V_266 ;
break;
default:
V_49 -> V_199 = V_267 ;
break;
}
if ( V_149 -> V_199 == V_200 )
V_257 = F_11 ( V_2 , V_268 ) ;
else
V_257 = F_11 ( V_2 , V_128 ) ;
switch ( V_257 ) {
case 0 :
V_49 -> V_269 = V_270 ;
break;
case 1 :
V_49 -> V_269 = V_271 ;
break;
case 2 :
V_49 -> V_269 = V_272 ;
break;
case 3 :
V_49 -> V_269 = V_273 ;
break;
case 4 :
V_49 -> V_269 = V_274 ;
break;
default:
V_49 -> V_269 = V_275 ;
break;
}
V_75 = F_11 ( V_2 , V_110 ) ;
switch ( V_75 ) {
case V_224 :
V_49 -> V_235 = V_237 ;
break;
case V_226 :
V_49 -> V_235 = V_238 ;
break;
default:
V_49 -> V_235 = V_236 ;
}
V_49 -> V_239 = F_11 ( V_2 , V_123 ) ;
return error ;
}
static int F_36 ( struct V_29 * V_30 , T_1 * V_276 )
{
struct V_1 * V_2 = V_30 -> V_32 ;
T_3 V_277 = 0 ;
int V_278 = 0 ;
T_2 V_279 = F_11 ( V_2 , V_280 ) ;
while ( V_278 < 10 ) {
F_23 ( 2000 , 3000 ) ;
if ( V_279 == 0x50 )
V_277 += F_11 ( V_2 , V_281 ) / 4 ;
else
V_277 += 125 * F_11 ( V_2 , V_281 ) ;
V_278 ++ ;
}
V_277 /= 10 ;
* V_276 = V_277 / 1000 ;
return 0 ;
}
static int F_37 ( struct V_29 * V_30 , T_6 * V_282 )
{
struct V_1 * V_2 = V_30 -> V_32 ;
F_14 ( L_4 , V_16 ) ;
* V_282 = 0 ;
if ( F_11 ( V_2 , V_117 ) ) {
* V_282 |= V_283 ;
F_14 ( L_28 , V_16 ) ;
}
return 0 ;
}
static int F_38 ( struct V_29 * V_30 , T_3 * V_284 )
{
struct V_1 * V_2 = V_30 -> V_32 ;
struct V_148 * V_149 = V_2 -> V_149 ;
T_3 V_285 = 0 , V_286 = 0 , V_287 = 0 ;
int V_288 = 0 , V_289 = 0 ;
if ( F_11 ( V_2 , V_251 ) == 0 )
V_285 = ( ( T_3 ) F_11 ( V_2 , V_290 )
* ( 1 << 16 ) )
+ ( ( T_3 ) F_11 ( V_2 , V_291 )
* ( 1 << 8 ) )
+ ( ( T_3 ) F_11 ( V_2 ,
V_292 ) ) ;
else {
V_286 = V_149 -> V_150 ;
return 0 ;
}
V_288 = F_11 ( V_2 , V_293 ) ;
V_289 = F_11 ( V_2 , V_294 ) ;
if ( V_285 == 0 ) {
V_286 = 0 ;
} else if ( V_288 == 0x7 ) {
if ( V_285 <= 4 ) {
V_287 = ( V_285 * 1000000000 ) / ( 8 * ( 1 << 14 ) ) ;
V_287 = V_287 ;
} else if ( V_285 <= 42 ) {
V_287 = ( V_285 * 100000000 ) / ( 8 * ( 1 << 14 ) ) ;
V_287 = V_287 * 10 ;
} else if ( V_285 <= 429 ) {
V_287 = ( V_285 * 10000000 ) / ( 8 * ( 1 << 14 ) ) ;
V_287 = V_287 * 100 ;
} else if ( V_285 <= 4294 ) {
V_287 = ( V_285 * 1000000 ) / ( 8 * ( 1 << 14 ) ) ;
V_287 = V_287 * 1000 ;
} else if ( V_285 <= 42949 ) {
V_287 = ( V_285 * 100000 ) / ( 8 * ( 1 << 14 ) ) ;
V_287 = V_287 * 10000 ;
} else if ( V_285 <= 429496 ) {
V_287 = ( V_285 * 10000 ) / ( 8 * ( 1 << 14 ) ) ;
V_287 = V_287 * 100000 ;
} else {
V_287 = ( V_285 * 1000 ) / ( 8 * ( 1 << 14 ) ) ;
V_287 = V_287 * 100000 ;
}
if ( V_289 == 2 )
V_286 = V_287 ;
else if ( V_289 == 3 )
V_286 = V_287 / 4 ;
else if ( V_289 == 4 )
V_286 = V_287 / 16 ;
else if ( V_289 == 5 )
V_286 = V_287 / 64 ;
else if ( V_289 == 6 )
V_286 = V_287 / 256 ;
else
V_286 = 0 ;
if ( ( V_285 < 4294967 ) && ( V_285 > 429496 ) )
V_286 *= 10 ;
}
V_149 -> V_150 = V_286 ;
( * V_284 ) = V_286 ;
return 0 ;
}
static int F_39 ( struct V_29 * V_30 ,
struct V_295
* V_296 )
{
V_296 -> V_297 = 1000 ;
V_296 -> V_298 = 0 ;
V_296 -> V_299 = 0 ;
return 0 ;
}
static void F_40 ( struct V_29 * V_30 )
{
struct V_1 * V_2 = V_30 -> V_32 ;
F_41 ( V_2 -> V_149 ) ;
F_41 ( V_2 -> V_300 ) ;
F_41 ( V_2 ) ;
}
struct V_29 * F_42 ( const struct V_301 * V_10 ,
struct V_302 * V_17 )
{
struct V_1 * V_2 = NULL ;
struct V_148 * V_149 = NULL ;
V_2 = F_43 ( sizeof( struct V_1 ) , V_303 ) ;
if ( V_2 == NULL )
goto error;
V_149 = F_43 ( sizeof( struct V_148 ) , V_303 ) ;
if ( V_149 == NULL )
goto error;
V_2 -> V_17 = V_17 ;
V_2 -> V_10 = V_10 ;
V_2 -> V_149 = V_149 ;
V_2 -> V_30 . V_43 = V_304 ;
V_2 -> V_30 . V_32 = V_2 ;
V_2 -> V_161 = F_7 ( V_2 , 0xf000 ) ;
F_14 ( L_29 , V_16 , V_2 -> V_161 ) ;
if ( ( V_2 -> V_161 != 0x50 ) && ( V_2 -> V_161 != 0x60 ) )
goto error;
return & V_2 -> V_30 ;
error:
F_41 ( V_149 ) ;
F_41 ( V_2 ) ;
return NULL ;
}
static int F_44 ( struct V_29 * V_30 , int V_31 )
{
struct V_1 * V_2 = V_30 -> V_32 ;
F_14 ( L_4 , V_16 ) ;
F_9 ( V_2 , V_305 , ( V_31 > 0 ) ? 1 : 0 ) ;
return 0 ;
}
static T_3 F_45 ( struct V_29 * V_30 , T_3 V_45 )
{
struct V_1 * V_2 = V_30 -> V_32 ;
T_3 V_46 = 0 ;
T_3 V_306 , V_307 , V_308 ;
if ( F_11 ( V_2 , V_309 ) == 0 ) {
V_307 = ( T_3 ) F_11 ( V_2 , V_310 ) ;
if ( V_307 == 0 )
V_307 = V_307 + 1 ;
V_306 = ( T_3 ) F_11 ( V_2 , V_311 ) ;
if ( V_306 == 0 )
V_306 = V_306 + 1 ;
V_308 = ( T_3 ) F_11 ( V_2 , V_312 ) ;
if ( V_308 > 5 )
V_308 = 5 ;
V_46 = ( ( V_45 / 2 ) * V_307 ) / ( V_306 * ( 1 << V_308 ) ) ;
F_14 ( L_30 ,
V_46 ) ;
} else
V_46 = V_45 ;
F_14 ( L_31 , V_46 ) ;
return V_46 ;
}
static T_3 F_46 ( struct V_29 * V_30 , T_3 V_45 )
{
T_3 V_313 = V_45 ;
V_313 = F_45 ( V_30 , V_45 ) ;
return V_313 ;
}
enum V_314 F_47 ( struct V_1 * V_2 ,
T_3 V_315 ,
enum V_314 V_316 )
{
F_9 ( V_2 , V_317 , V_316 ) ;
switch ( V_316 ) {
case V_318 :
F_6 ( V_2 , V_319 , 0x00 ) ;
break;
case V_320 :
F_6 ( V_2 , V_321 , 0x64 ) ;
F_6 ( V_2 , V_319 , 0x00 ) ;
F_6 ( V_2 , V_322 , 0x90 ) ;
F_6 ( V_2 , V_323 , 0xc1 ) ;
F_6 ( V_2 , V_324 , 0xa7 ) ;
F_6 ( V_2 , V_325 , 0x95 ) ;
F_6 ( V_2 , V_326 , 0x40 ) ;
F_6 ( V_2 , V_327 , 0x8a ) ;
break;
case V_328 :
F_6 ( V_2 , V_319 , 0x00 ) ;
F_6 ( V_2 , V_321 , 0x6e ) ;
F_6 ( V_2 , V_322 , 0xb0 ) ;
F_6 ( V_2 , V_323 , 0xc1 ) ;
F_6 ( V_2 , V_324 , 0xb7 ) ;
F_6 ( V_2 , V_325 , 0x9d ) ;
F_6 ( V_2 , V_326 , 0x7f ) ;
F_6 ( V_2 , V_327 , 0xa7 ) ;
break;
case V_329 :
F_6 ( V_2 , V_319 , 0x82 ) ;
F_6 ( V_2 , V_321 , 0x5a ) ;
if ( V_315 > 45000000 ) {
F_6 ( V_2 , V_322 , 0xb0 ) ;
F_6 ( V_2 , V_323 , 0xc1 ) ;
F_6 ( V_2 , V_324 , 0xa5 ) ;
} else if ( V_315 > 25000000 ) {
F_6 ( V_2 , V_322 , 0xa0 ) ;
F_6 ( V_2 , V_323 , 0xc1 ) ;
F_6 ( V_2 , V_324 , 0xa6 ) ;
} else {
F_6 ( V_2 , V_322 , 0xa0 ) ;
F_6 ( V_2 , V_323 , 0xd1 ) ;
F_6 ( V_2 , V_324 , 0xa7 ) ;
}
F_6 ( V_2 , V_325 , 0x95 ) ;
F_6 ( V_2 , V_326 , 0x40 ) ;
F_6 ( V_2 , V_327 , 0x99 ) ;
break;
case V_330 :
F_6 ( V_2 , V_319 , 0x00 ) ;
F_6 ( V_2 , V_321 , 0x76 ) ;
F_6 ( V_2 , V_322 , 0x90 ) ;
F_6 ( V_2 , V_323 , 0xb1 ) ;
if ( V_315 > 45000000 )
F_6 ( V_2 , V_324 , 0xa7 ) ;
else if ( V_315 > 25000000 )
F_6 ( V_2 , V_324 , 0xa6 ) ;
else
F_6 ( V_2 , V_324 , 0x97 ) ;
F_6 ( V_2 , V_325 , 0x8e ) ;
F_6 ( V_2 , V_326 , 0x7f ) ;
F_6 ( V_2 , V_327 , 0xa7 ) ;
break;
case V_331 :
F_6 ( V_2 , V_319 , 0x94 ) ;
F_6 ( V_2 , V_321 , 0x5a ) ;
F_6 ( V_2 , V_322 , 0xa0 ) ;
if ( V_315 > 45000000 )
F_6 ( V_2 , V_323 , 0xc1 ) ;
else if ( V_315 > 25000000 )
F_6 ( V_2 , V_323 , 0xc1 ) ;
else
F_6 ( V_2 , V_323 , 0xd1 ) ;
F_6 ( V_2 , V_324 , 0xa7 ) ;
F_6 ( V_2 , V_325 , 0x85 ) ;
F_6 ( V_2 , V_326 , 0x40 ) ;
F_6 ( V_2 , V_327 , 0xa7 ) ;
break;
case V_332 :
F_6 ( V_2 , V_319 , 0x00 ) ;
break;
case V_333 :
F_6 ( V_2 , V_319 , 0x00 ) ;
break;
default:
break;
}
return V_316 ;
}
static T_3 F_48 ( struct V_1 * V_2 ,
T_3 V_334 , T_4 V_335 )
{
T_3 V_336 = 0 ;
T_3 V_337 ;
V_337 = V_334 / 1000 ;
F_14 ( L_32 , V_16 , V_334 , V_335 ) ;
if ( V_337 != 0 ) {
if ( V_335 < 1000000 )
V_335 = V_334 / 4 ;
if ( V_335 > V_334 )
V_335 = V_335 - V_334 ;
V_336 = ( T_3 ) V_335 / 1000 ;
V_336 *= 32768 ;
V_336 /= V_337 ;
V_336 *= 256 ;
}
if ( V_336 > 8388607 )
V_336 = 8388607 ;
F_14 ( L_33 , V_16 , V_336 ) ;
F_6 ( V_2 , V_338 , V_336 ) ;
F_6 ( V_2 , V_339 , ( V_336 >> 8 ) ) ;
F_9 ( V_2 , V_340 , ( V_336 >> 16 ) ) ;
return V_335 ;
}
static T_3 F_49 ( struct V_1 * V_2 , T_3 V_334 )
{
T_3 V_336 ;
V_336 = F_11 ( V_2 , V_341 ) +
( F_11 ( V_2 , V_342 ) << 8 ) +
( F_11 ( V_2 , V_340 ) << 16 ) ;
V_336 /= 256 ;
V_336 *= ( V_334 / 1000 ) ;
V_336 += 1 ;
V_336 /= 32768 ;
return V_336 ;
}
static T_3 F_50 ( struct V_1 * V_2 , T_3 V_334 ,
T_3 V_343 , T_3 V_315 ,
enum V_314 V_316 )
{
T_3 V_344 = 0 ;
T_3 V_345 = 0 , V_346 = 0 ;
T_3 V_347 ;
F_14 ( L_4 , V_16 ) ;
switch ( V_316 ) {
case V_318 :
V_344 = 1110 ;
break;
case V_320 :
V_344 = 1032 ;
break;
case V_328 :
V_344 = 954 ;
break;
case V_329 :
V_344 = 983 ;
break;
case V_330 :
V_344 = 957 ;
break;
case V_331 :
V_344 = 948 ;
break;
case V_332 :
V_344 = 0 ;
break;
case V_333 :
V_344 = 944 ;
break;
default:
break;
}
if ( V_334 != 0 ) {
V_345 = 256 * V_315 ;
V_345 = V_345 / V_334 ;
}
F_6 ( V_2 , V_348 , ( T_2 ) V_345 ) ;
V_347 = ( V_343 >> 1 ) / 1000 ;
if ( V_347 != 0 ) {
V_345 = V_315 ;
V_346 = V_315 ;
if ( V_345 < 2097152 ) {
V_345 *= 2048 ;
V_345 = V_345 / V_347 ;
V_345 = V_345 * 16384 ;
V_345 /= 125 ;
V_345 = V_345 * 8 ;
V_346 *= 2048 ;
V_346 /= 439 ;
V_346 *= 256 ;
V_346 = V_346 / V_347 ;
V_346 *= V_344 * 9 ;
V_346 = V_346 / 10000000 ;
} else if ( V_345 < 4194304 ) {
V_345 *= 1024 ;
V_345 = V_345 / V_347 ;
V_345 = V_345 * 16384 ;
V_345 /= 125 ;
V_345 = V_345 * 16 ;
V_346 *= 1024 ;
V_346 /= 439 ;
V_346 *= 256 ;
V_346 = V_346 / V_347 ;
V_346 *= V_344 * 9 ;
V_346 = V_346 / 5000000 ;
} else if ( V_345 < 8388607 ) {
V_345 *= 512 ;
V_345 = V_345 / V_347 ;
V_345 = V_345 * 16384 ;
V_345 /= 125 ;
V_345 = V_345 * 32 ;
V_346 *= 512 ;
V_346 /= 439 ;
V_346 *= 256 ;
V_346 = V_346 / V_347 ;
V_346 *= V_344 * 9 ;
V_346 = V_346 / 2500000 ;
} else {
V_345 *= 256 ;
V_345 = V_345 / V_347 ;
V_345 = V_345 * 16384 ;
V_345 /= 125 ;
V_345 = V_345 * 64 ;
V_346 *= 256 ;
V_346 /= 439 ;
V_346 *= 256 ;
V_346 = V_346 / V_347 ;
V_346 *= V_344 * 9 ;
V_346 = V_346 / 1250000 ;
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
F_9 ( V_2 , V_349 , 0 ) ;
F_6 ( V_2 , V_350 , V_345 ) ;
F_6 ( V_2 , V_351 , ( V_345 >> 8 ) ) ;
F_6 ( V_2 , V_352 , ( V_345 >> 16 ) ) ;
F_6 ( V_2 , V_353 , ( V_345 >> 24 ) ) ;
F_6 ( V_2 , V_354 , V_346 & 0x00ff ) ;
F_9 ( V_2 , V_355 , ( V_346 >> 8 ) & 0x00ff ) ;
return V_315 ;
}
static T_3 F_51 ( struct V_1 * V_2 , T_3 V_343 )
{
T_3 V_356 ;
T_3 V_347 ;
V_356 = F_7 ( V_2 , V_350 ) +
( F_7 ( V_2 , V_351 ) << 8 ) +
( F_7 ( V_2 , V_352 ) << 16 ) +
( F_7 ( V_2 , V_353 ) << 24 ) ;
V_347 = ( V_343 >> 1 ) / 1000 ;
if ( V_356 < 134217728 ) {
V_356 = V_356 * 32 ;
V_356 = V_356 / 32768 ;
V_356 = V_347 * V_356 ;
V_356 = V_356 / 128 ;
V_356 *= 125 ;
V_356 /= 2048 ;
} else if ( V_356 < 268435456 ) {
V_356 = V_356 * 16 ;
V_356 = V_356 / 32768 ;
V_356 = V_347 * V_356 ;
V_356 = V_356 / 128 ;
V_356 *= 125 ;
V_356 /= 1024 ;
} else if ( V_356 < 536870912 ) {
V_356 = V_356 * 8 ;
V_356 = V_356 / 32768 ;
V_356 = V_347 * V_356 ;
V_356 = V_356 / 128 ;
V_356 *= 125 ;
V_356 /= 512 ;
} else {
V_356 = V_356 * 4 ;
V_356 = V_356 / 32768 ;
V_356 = V_347 * V_356 ;
V_356 = V_356 / 128 ;
V_356 *= 125 ;
V_356 /= 256 ;
}
return V_356 ;
}
static int F_52 ( struct V_29 * V_30 , T_6 * V_282 )
{
struct V_1 * V_2 = V_30 -> V_32 ;
F_14 ( L_4 , V_16 ) ;
* V_282 = 0 ;
if ( F_11 ( V_2 , V_357 ) ) {
* V_282 |= V_283 ;
F_14 ( L_28 , V_16 ) ;
}
return 0 ;
}
static int F_53 ( struct V_29 * V_30 , T_2 V_144 )
{
struct V_1 * V_2 = V_30 -> V_32 ;
F_14 ( L_4 , V_16 ) ;
if ( V_144 ) {
F_9 ( V_2 , V_309 , 0x03 ) ;
F_9 ( V_2 , V_358 , 0x01 ) ;
F_9 ( V_2 , V_359 , 1 ) ;
F_9 ( V_2 , V_360 , 1 ) ;
F_9 ( V_2 , V_361 , 0 ) ;
F_9 ( V_2 , V_362 , 0 ) ;
F_9 ( V_2 , V_363 , 1 ) ;
F_9 ( V_2 , V_364 , 1 ) ;
} else {
F_9 ( V_2 , V_358 , 0x00 ) ;
F_9 ( V_2 , V_309 , 0x00 ) ;
F_9 ( V_2 , V_359 , 0 ) ;
F_9 ( V_2 , V_360 , 0 ) ;
F_9 ( V_2 , V_361 , 1 ) ;
F_9 ( V_2 , V_362 , 1 ) ;
F_9 ( V_2 , V_363 , 0 ) ;
F_9 ( V_2 , V_364 , 0 ) ;
}
return 0 ;
}
static int F_54 ( struct V_29 * V_30 )
{
return F_53 ( V_30 , 1 ) ;
}
int F_55 ( struct V_29 * V_30 )
{
struct V_1 * V_2 = V_30 -> V_32 ;
struct V_365 * V_300 = V_2 -> V_300 ;
int V_27 ;
F_14 ( L_4 , V_16 ) ;
for ( V_27 = 0 ; V_27 < V_366 ; V_27 ++ )
F_6 ( V_2 , V_367 [ V_27 ] . V_9 ,
V_367 [ V_27 ] . V_153 ) ;
switch ( V_2 -> V_10 -> V_159 ) {
case V_368 :
F_14 ( L_34 ) ;
F_9 ( V_2 , V_369 , 0x03 ) ;
break;
case V_139 :
case V_370 :
F_9 ( V_2 , V_369 , 0x01 ) ;
break;
case V_136 :
case V_371 :
F_9 ( V_2 , V_369 , 0x00 ) ;
break;
}
switch ( V_2 -> V_10 -> V_160 ) {
case V_141 :
F_9 ( V_2 , V_372 , 0x00 ) ;
break;
case V_143 :
case V_373 :
F_9 ( V_2 , V_372 , 0x01 ) ;
break;
}
F_9 ( V_2 , V_374 , 0x00 ) ;
F_9 ( V_2 , V_375 , 0x01 ) ;
F_9 ( V_2 , V_376 , 0x01 ) ;
F_9 ( V_2 , V_377 , 0x00 ) ;
F_6 ( V_2 , V_378 , 0x00 ) ;
V_300 -> V_379 = F_45 ( V_30 , V_2 -> V_10 -> V_154 ) ;
V_300 -> V_380 = F_46 ( V_30 , V_2 -> V_10 -> V_154 ) ;
return 0 ;
}
static
enum V_381 F_56 ( struct V_1 * V_2 ,
struct V_165 * V_49 )
{
struct V_365 * V_300 = V_2 -> V_300 ;
enum V_381 V_382 = V_383 ;
T_3 V_384 , V_385 , V_345 ,
V_386 , V_387 , V_388 , V_389 ,
V_390 , V_391 , V_392 , V_393 ;
T_2 V_394 ;
T_4 V_33 ;
F_14 ( L_4 , V_16 ) ;
V_388 = 25 ;
V_387 = 100000000 / V_49 -> V_395 ;
switch ( V_49 -> V_258 ) {
case V_260 :
V_389 = 150000 ;
V_391 = 100 ;
break;
case V_396 :
V_389 = 250000 ;
V_391 = 100 ;
break;
case V_261 :
V_389 = 200000 ;
V_391 = 100 ;
break;
case V_397 :
V_389 = 250000 ;
V_391 = 100 ;
break;
case V_398 :
V_389 = 250000 ;
V_391 = 100 ;
break;
default:
V_389 = 200000 ;
V_391 = 100 ;
break;
}
#if 0
if (pIntParams->search_range < 0) {
CRLTimeOut = (25 * CRLSymbols *
(-pIntParams->search_range / 1000)) /
(pIntParams->symbol_rate / 1000);
} else
#endif
V_390 = ( 25 * V_389 * ( V_300 -> V_399 / 1000 ) ) /
( V_49 -> V_395 / 1000 ) ;
V_390 = ( 1000 * V_390 ) / V_49 -> V_395 ;
if ( V_390 < 50 )
V_390 = 50 ;
V_393 = 20 ;
V_392 = V_388 + V_387 + V_390 + V_391 ;
F_14 ( L_35 , V_16 , V_392 ) ;
F_6 ( V_2 , V_400 , 0x04 ) ;
V_394 = F_11 ( V_2 , V_401 ) ;
F_9 ( V_2 , V_401 , 0x0 ) ;
F_9 ( V_2 , V_402 , 0 ) ;
F_9 ( V_2 , V_403 , 0 ) ;
F_48 ( V_2 , V_300 -> V_380 ,
( 1000 * ( T_4 ) V_2 -> V_10 -> V_207 + V_300 -> V_404 ) ) ;
if ( ( V_49 -> V_395 > 10800000 ) | ( V_49 -> V_395 < 1800000 ) ) {
F_9 ( V_2 , V_405 , 0 ) ;
F_9 ( V_2 , V_349 , 0 ) ;
}
#if 0
tuner_lock = stv0367cab_tuner_get_status(fe);
if (tuner_lock == 0)
return FE_367CAB_NOTUNER;
#endif
V_386 = 0 ;
F_6 ( V_2 , V_400 , 0x00 ) ;
do {
V_385 = F_11 ( V_2 , V_406 ) ;
if ( ( V_386 >= ( V_392 - V_391 ) ) &&
( V_385 == 0x04 ) )
V_386 = V_392 ;
else if ( ( V_386 >= ( V_388 + V_387 ) ) &&
( V_385 == 0x02 ) )
{
V_386 = V_392 ;
V_345 = F_11 ( V_2 ,
V_407 ) +
( F_11 ( V_2 ,
V_408 ) << 8 ) +
( F_11 ( V_2 ,
V_409 ) << 16 ) ;
if ( V_345 >= 131072 )
V_345 = 262144 - V_345 ;
V_345 = V_345 / ( 1 << ( 11 - F_11 ( V_2 ,
V_410 ) ) ) ;
if ( V_345 < F_11 ( V_2 ,
V_411 ) +
256 * F_11 ( V_2 ,
V_412 ) - 10 )
V_385 = 0x0f ;
} else {
F_23 ( 10000 , 20000 ) ;
V_386 += 10 ;
}
F_14 ( L_36 , V_385 , V_386 ) ;
V_33 = F_7 ( V_2 , V_413 ) ;
F_14 ( L_37 , V_33 ) ;
} while ( ( ( V_385 != 0x0c ) && ( V_385 != 0x0b ) ) &&
( V_386 < V_392 ) );
F_14 ( L_38 , V_385 ) ;
V_33 = F_7 ( V_2 , V_413 ) ;
F_14 ( L_37 , V_33 ) ;
V_33 = F_7 ( V_2 , V_414 ) ;
F_14 ( L_39 , V_33 ) ;
V_33 = F_49 ( V_2 , V_300 -> V_380 ) ;
F_14 ( L_40 , V_33 ) ;
if ( ( V_385 == 0x0c ) || ( V_385 == 0x0b ) ) {
V_386 = 0 ;
do {
F_23 ( 5000 , 7000 ) ;
V_386 += 5 ;
V_384 = F_11 ( V_2 ,
V_357 ) ;
} while ( ! V_384 && ( V_386 < V_393 ) );
} else
V_384 = 0 ;
if ( V_384 ) {
V_382 = V_415 ;
V_300 -> V_258 = V_49 -> V_258 ;
V_300 -> V_416 = F_11 ( V_2 ,
V_417 ) ;
#if 0
if (state->config->if_khz != 0) {
if (state->config->if_khz > cab_state->adc_clk / 1000) {
cab_state->freq_khz =
FE_Cab_TunerGetFrequency(pIntParams->hTuner)
- stv0367cab_get_derot_freq(state, cab_state->adc_clk)
- cab_state->adc_clk / 1000 + state->config->if_khz;
} else {
cab_state->freq_khz =
FE_Cab_TunerGetFrequency(pIntParams->hTuner)
- stv0367cab_get_derot_freq(state, cab_state->adc_clk)
+ state->config->if_khz;
}
} else {
cab_state->freq_khz =
FE_Cab_TunerGetFrequency(pIntParams->hTuner) +
stv0367cab_get_derot_freq(state,
cab_state->adc_clk) -
cab_state->adc_clk / 4000;
}
#endif
V_300 -> V_395 = F_51 ( V_2 ,
V_300 -> V_379 ) ;
V_300 -> V_418 = 1 ;
} else {
switch ( V_385 ) {
case 1 :
V_382 = V_383 ;
break;
case 2 :
V_382 = V_419 ;
break;
case 3 :
V_382 = V_420 ;
break;
case 4 :
V_382 = V_421 ;
break;
case 5 :
V_382 = V_422 ;
break;
case 7 :
V_382 = V_423 ;
break;
case 8 :
V_382 = V_424 ;
break;
case 10 :
V_382 = V_425 ;
break;
case 11 :
V_382 = V_426 ;
break;
case 12 :
V_382 = V_426 ;
break;
case 13 :
V_382 = V_425 ;
break;
case 14 :
V_382 = V_423 ;
break;
case 15 :
V_382 = V_427 ;
break;
default:
break;
}
}
F_9 ( V_2 , V_401 , V_394 ) ;
return V_382 ;
}
static int F_57 ( struct V_29 * V_30 )
{
struct V_165 * V_49 = & V_30 -> V_166 ;
struct V_1 * V_2 = V_30 -> V_32 ;
struct V_365 * V_300 = V_2 -> V_300 ;
enum V_314 V_316 = 0 ;
F_14 ( L_41 , V_16 ,
V_49 -> V_176 , V_49 -> V_395 ) ;
V_300 -> V_404 = 0 ;
switch ( V_49 -> V_258 ) {
case V_260 :
V_316 = V_320 ;
break;
case V_396 :
V_316 = V_328 ;
break;
case V_261 :
V_316 = V_329 ;
break;
case V_397 :
V_316 = V_330 ;
break;
case V_398 :
V_316 = V_331 ;
break;
default:
break;
}
F_55 ( V_30 ) ;
if ( V_30 -> V_43 . V_40 . V_233 ) {
if ( V_30 -> V_43 . V_234 )
V_30 -> V_43 . V_234 ( V_30 , 1 ) ;
V_30 -> V_43 . V_40 . V_233 ( V_30 ) ;
if ( V_30 -> V_43 . V_234 )
V_30 -> V_43 . V_234 ( V_30 , 0 ) ;
}
F_47 (
V_2 ,
V_49 -> V_395 ,
V_316 ) ;
F_50 ( V_2 ,
V_300 -> V_380 ,
V_300 -> V_379 ,
V_49 -> V_395 ,
V_316 ) ;
V_300 -> V_2 = F_56 ( V_2 , V_49 ) ;
return 0 ;
}
static int F_58 ( struct V_29 * V_30 )
{
struct V_165 * V_49 = & V_30 -> V_166 ;
struct V_1 * V_2 = V_30 -> V_32 ;
struct V_365 * V_300 = V_2 -> V_300 ;
enum V_314 V_316 ;
F_14 ( L_4 , V_16 ) ;
V_49 -> V_395 = F_51 ( V_2 , V_300 -> V_379 ) ;
V_316 = F_11 ( V_2 , V_317 ) ;
switch ( V_316 ) {
case V_320 :
V_49 -> V_258 = V_260 ;
break;
case V_328 :
V_49 -> V_258 = V_396 ;
break;
case V_329 :
V_49 -> V_258 = V_261 ;
break;
case V_330 :
V_49 -> V_258 = V_397 ;
break;
case V_398 :
V_49 -> V_258 = V_398 ;
break;
default:
break;
}
V_49 -> V_176 = F_15 ( V_30 ) ;
F_14 ( L_42 , V_16 , V_49 -> V_176 ) ;
if ( V_2 -> V_10 -> V_207 == 0 ) {
V_49 -> V_176 +=
( F_49 ( V_2 , V_300 -> V_380 ) -
V_300 -> V_380 / 4000 ) ;
return 0 ;
}
if ( V_2 -> V_10 -> V_207 > V_300 -> V_380 / 1000 )
V_49 -> V_176 += ( V_2 -> V_10 -> V_207
- F_49 ( V_2 , V_300 -> V_380 )
- V_300 -> V_380 / 1000 ) ;
else
V_49 -> V_176 += ( V_2 -> V_10 -> V_207
- F_49 ( V_2 , V_300 -> V_380 ) ) ;
return 0 ;
}
static T_4 F_59 ( struct V_1 * V_2 )
{
T_4 V_428 = 0 ;
T_4 V_429 = 0 , V_430 = 0 ;
T_2 V_27 ;
F_9 ( V_2 , V_431 , 0x0 ) ;
V_429 =
( F_11 ( V_2 , V_432 ) & 0x03 ) +
( F_11 ( V_2 , V_433 ) << 2 ) ;
V_429 = 100 * V_429 / 1023 ;
V_430 =
F_11 ( V_2 , V_434 ) +
( F_11 ( V_2 , V_435 ) << 8 ) ;
if ( V_430 >= 2048 )
V_430 -= 2048 ;
else
V_430 += 2048 ;
V_430 = 100 * V_430 / 4095 ;
if ( V_429 < 90 && V_430 < 28 ) {
for ( V_27 = 0 ; V_27 < V_436 ; V_27 ++ ) {
if ( V_429 <= V_437 [ 0 ] [ V_27 ] ) {
V_428 = ( - 1 ) * V_437 [ 1 ] [ V_27 ] ;
break;
}
}
if ( V_27 == V_436 )
V_428 = - 56 ;
} else {
for ( V_27 = 0 ; V_27 < V_438 ; V_27 ++ ) {
if ( V_430 <= V_439 [ 0 ] [ V_27 ] ) {
V_428 = ( - 1 ) * V_439 [ 1 ] [ V_27 ] ;
break;
}
}
if ( V_27 == V_438 )
V_428 = - 72 ;
}
return V_428 ;
}
static int F_60 ( struct V_29 * V_30 , T_1 * V_440 )
{
struct V_1 * V_2 = V_30 -> V_32 ;
T_4 signal = F_59 ( V_2 ) ;
F_14 ( L_43 , V_16 , signal ) ;
if ( signal <= - 72 )
* V_440 = 65535 ;
else
* V_440 = ( 22 + signal ) * ( - 1311 ) ;
F_14 ( L_44 , V_16 , ( * V_440 ) ) ;
return 0 ;
}
static int F_61 ( struct V_29 * V_30 , T_1 * V_276 )
{
struct V_1 * V_2 = V_30 -> V_32 ;
T_3 V_441 ;
enum V_314 V_316 ;
T_3 V_442 = 0 , V_175 = 0 ;
int V_443 , V_27 ;
V_316 = F_11 ( V_2 , V_317 ) ;
switch ( V_316 ) {
case V_318 :
V_443 = 21904 ;
break;
case V_320 :
V_443 = 20480 ;
break;
case V_328 :
V_443 = 23040 ;
break;
case V_329 :
V_443 = 21504 ;
break;
case V_330 :
V_443 = 23616 ;
break;
case V_331 :
V_443 = 21760 ;
break;
case V_332 :
V_443 = 1 ;
break;
case V_333 :
V_443 = 21280 ;
break;
default:
V_443 = 1 ;
break;
}
for ( V_27 = 0 ; V_27 < 10 ; V_27 ++ ) {
V_442 += ( F_11 ( V_2 , V_444 )
+ 256 * F_11 ( V_2 , V_445 ) ) ;
}
V_442 /= 10 ;
if ( V_442 != 0 ) {
V_175 = V_443
* ( 1 << ( 3 + F_11 ( V_2 , V_446 ) ) ) ;
V_175 /= V_442 ;
}
if ( V_175 >= 5012 )
V_441 = 100 ;
else if ( V_175 >= 3981 )
V_441 = 93 ;
else if ( V_175 >= 3162 )
V_441 = 86 ;
else if ( V_175 >= 2512 )
V_441 = 79 ;
else if ( V_175 >= 1995 )
V_441 = 72 ;
else if ( V_175 >= 1585 )
V_441 = 65 ;
else if ( V_175 >= 1259 )
V_441 = 58 ;
else if ( V_175 >= 1000 )
V_441 = 50 ;
else if ( V_175 >= 794 )
V_441 = 43 ;
else if ( V_175 >= 501 )
V_441 = 36 ;
else if ( V_175 >= 316 )
V_441 = 29 ;
else if ( V_175 >= 200 )
V_441 = 22 ;
else if ( V_175 >= 158 )
V_441 = 14 ;
else if ( V_175 >= 126 )
V_441 = 7 ;
else
V_441 = 0 ;
F_14 ( L_45 , V_16 , V_441 ) ;
* V_276 = ( V_441 * 65535 ) / 100 ;
return 0 ;
}
static int F_62 ( struct V_29 * V_30 , T_3 * V_211 )
{
struct V_1 * V_2 = V_30 -> V_32 ;
int V_447 , V_448 ;
* V_211 = ( F_7 ( V_2 , V_449 ) << 8 )
| F_7 ( V_2 , V_450 ) ;
V_447 = ( F_7 ( V_2 , V_451 ) << 8 )
| F_7 ( V_2 , V_452 ) ;
V_448 = ( F_7 ( V_2 , V_452 ) << 8 )
| F_7 ( V_2 , V_453 ) ;
F_14 ( L_46 ,
V_16 , * V_211 , V_447 , V_448 ) ;
return 0 ;
}
struct V_29 * F_63 ( const struct V_301 * V_10 ,
struct V_302 * V_17 )
{
struct V_1 * V_2 = NULL ;
struct V_365 * V_300 = NULL ;
V_2 = F_43 ( sizeof( struct V_1 ) , V_303 ) ;
if ( V_2 == NULL )
goto error;
V_300 = F_43 ( sizeof( struct V_365 ) , V_303 ) ;
if ( V_300 == NULL )
goto error;
V_2 -> V_17 = V_17 ;
V_2 -> V_10 = V_10 ;
V_300 -> V_399 = 280000 ;
V_2 -> V_300 = V_300 ;
V_2 -> V_30 . V_43 = V_454 ;
V_2 -> V_30 . V_32 = V_2 ;
V_2 -> V_161 = F_7 ( V_2 , 0xf000 ) ;
F_14 ( L_29 , V_16 , V_2 -> V_161 ) ;
if ( ( V_2 -> V_161 != 0x50 ) && ( V_2 -> V_161 != 0x60 ) )
goto error;
return & V_2 -> V_30 ;
error:
F_41 ( V_300 ) ;
F_41 ( V_2 ) ;
return NULL ;
}
