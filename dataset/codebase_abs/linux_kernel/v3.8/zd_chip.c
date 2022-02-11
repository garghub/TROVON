void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
F_2 ( & V_2 -> V_7 ) ;
F_3 ( & V_2 -> V_8 , V_4 , V_6 ) ;
F_4 ( & V_2 -> V_9 ) ;
}
void F_5 ( struct V_1 * V_2 )
{
F_6 ( ! F_7 ( & V_2 -> V_7 ) ) ;
F_8 ( & V_2 -> V_8 ) ;
F_9 ( & V_2 -> V_9 ) ;
F_10 ( & V_2 -> V_7 ) ;
F_11 ( V_2 , sizeof( * V_2 ) ) ;
}
static int F_12 ( struct V_1 * V_2 , char * V_10 , T_1 V_11 )
{
T_2 * V_12 = F_13 ( F_14 ( V_2 ) ) ;
return F_15 ( V_10 , V_11 , L_1 ,
V_12 [ 0 ] , V_12 [ 1 ] , V_12 [ 2 ] ) ;
}
static int F_16 ( struct V_1 * V_2 , char * V_10 , T_1 V_11 )
{
int V_13 = 0 ;
V_13 = F_15 ( V_10 , V_11 , L_2 ,
F_17 ( V_2 ) ? L_3 : L_4 ) ;
V_13 += F_18 ( & V_2 -> V_8 , V_10 + V_13 , V_11 - V_13 ) ;
V_13 += F_15 ( V_10 + V_13 , V_11 - V_13 , L_5 ) ;
V_13 += F_12 ( V_2 , V_10 + V_13 , V_11 - V_13 ) ;
V_13 += F_15 ( V_10 + V_13 , V_11 - V_13 , L_5 ) ;
V_13 += F_19 ( & V_2 -> V_9 , V_10 + V_13 , V_11 - V_13 ) ;
V_13 += F_15 ( V_10 + V_13 , V_11 - V_13 , L_6 , V_2 -> V_14 ,
V_2 -> V_15 ? 'g' : '-' ,
V_2 -> V_16 ? '7' : '-' ,
V_2 -> V_17 ? '6' : '-' ,
V_2 -> V_18 ? 'N' : '-' ,
V_2 -> V_19 ? 'S' : '-' ) ;
return V_13 ;
}
static void F_20 ( struct V_1 * V_2 )
{
char V_10 [ 80 ] ;
F_16 ( V_2 , V_10 , sizeof( V_10 ) ) ;
V_10 [ sizeof( V_10 ) - 1 ] = 0 ;
F_21 ( F_22 ( V_2 ) , L_7 , V_10 ) ;
}
static T_3 F_23 ( T_3 V_12 )
{
T_4 V_20 = ( T_4 ) V_12 ;
if ( ( V_20 & 0xf000 ) == V_21 )
V_20 += 2 ;
else
V_20 += 1 ;
return ( T_3 ) V_20 ;
}
int F_24 ( struct V_1 * V_2 , T_5 * V_22 , const T_3 * V_12 ,
unsigned int V_23 )
{
int V_24 ;
int V_13 ;
T_3 V_25 [ V_26 * 2 ] ;
T_4 V_27 [ V_26 * 2 ] ;
unsigned int V_28 ;
if ( V_23 > V_26 )
return - V_29 ;
V_28 = 2 * V_23 ;
F_25 ( V_28 * sizeof( T_3 ) > sizeof( V_25 ) ) ;
F_25 ( V_28 * sizeof( T_4 ) > sizeof( V_27 ) ) ;
for ( V_13 = 0 ; V_13 < V_23 ; V_13 ++ ) {
int V_30 = 2 * V_13 ;
V_25 [ V_30 ] = F_23 ( V_12 [ V_13 ] ) ;
V_25 [ V_30 + 1 ] = V_12 [ V_13 ] ;
}
V_24 = F_26 ( V_2 , V_27 , V_25 , V_28 ) ;
if ( V_24 ) {
F_27 ( F_22 ( V_2 ) ,
L_8 , V_24 ) ;
return V_24 ;
}
for ( V_13 = 0 ; V_13 < V_23 ; V_13 ++ ) {
int V_30 = 2 * V_13 ;
V_22 [ V_13 ] = ( V_27 [ V_30 ] << 16 ) | V_27 [ V_30 + 1 ] ;
}
return 0 ;
}
static int F_28 ( struct V_1 * V_2 ,
const struct V_31 * V_32 ,
unsigned int V_23 )
{
int V_13 , V_30 , V_24 ;
struct V_33 V_34 [ V_35 * 2 ] ;
unsigned int V_28 ;
F_6 ( F_7 ( & V_2 -> V_7 ) ) ;
if ( V_23 == 0 )
return 0 ;
if ( V_23 > V_35 )
return - V_29 ;
V_28 = 2 * V_23 ;
F_25 ( V_28 * sizeof( struct V_33 ) > sizeof( V_34 ) ) ;
for ( V_13 = 0 ; V_13 < V_23 ; V_13 ++ ) {
V_30 = 2 * V_13 ;
V_34 [ V_30 ] . V_36 = V_32 [ V_13 ] . V_36 >> 16 ;
V_34 [ V_30 ] . V_12 = F_23 ( V_32 [ V_13 ] . V_12 ) ;
V_34 [ V_30 + 1 ] . V_36 = V_32 [ V_13 ] . V_36 ;
V_34 [ V_30 + 1 ] . V_12 = V_32 [ V_13 ] . V_12 ;
}
V_24 = F_29 ( & V_2 -> V_8 , V_34 , V_28 ) ;
#ifdef F_30
if ( V_24 ) {
F_27 ( F_22 ( V_2 ) ,
L_9 , V_24 ) ;
}
#endif
return V_24 ;
}
int F_31 ( struct V_1 * V_2 , const struct V_31 * V_32 ,
unsigned int V_23 )
{
int V_24 ;
F_32 ( & V_2 -> V_8 ) ;
V_24 = F_28 ( V_2 , V_32 , V_23 ) ;
if ( V_24 ) {
F_33 ( & V_2 -> V_8 , 0 ) ;
return V_24 ;
}
return F_33 ( & V_2 -> V_8 , 50 ) ;
}
int F_34 ( struct V_1 * V_2 ,
const struct V_33 * V_32 , unsigned int V_23 )
{
int V_24 ;
unsigned int V_13 , V_30 , V_37 , V_38 ;
F_6 ( F_7 ( & V_2 -> V_7 ) ) ;
F_32 ( & V_2 -> V_8 ) ;
for ( V_13 = 0 ; V_13 < V_23 ; V_13 += V_30 + V_37 ) {
V_37 = 0 ;
V_38 = V_23 - V_13 ;
if ( V_38 > V_39 )
V_38 = V_39 ;
for ( V_30 = 0 ; V_30 < V_38 ; V_30 ++ ) {
if ( ! V_32 [ V_13 + V_30 ] . V_12 ) {
V_37 = 1 ;
break;
}
}
V_24 = F_29 ( & V_2 -> V_8 , & V_32 [ V_13 ] , V_30 ) ;
if ( V_24 ) {
F_33 ( & V_2 -> V_8 , 0 ) ;
F_27 ( F_22 ( V_2 ) ,
L_10 ,
V_24 ) ;
return V_24 ;
}
}
return F_33 ( & V_2 -> V_8 , 50 ) ;
}
int F_35 ( struct V_1 * V_2 ,
const struct V_31 * V_32 , unsigned int V_23 )
{
int V_24 ;
unsigned int V_13 , V_30 , V_37 , V_38 ;
F_32 ( & V_2 -> V_8 ) ;
for ( V_13 = 0 ; V_13 < V_23 ; V_13 += V_30 + V_37 ) {
V_37 = 0 ;
V_38 = V_23 - V_13 ;
if ( V_38 > V_35 )
V_38 = V_35 ;
for ( V_30 = 0 ; V_30 < V_38 ; V_30 ++ ) {
if ( ! V_32 [ V_13 + V_30 ] . V_12 ) {
V_37 = 1 ;
break;
}
}
V_24 = F_28 ( V_2 , & V_32 [ V_13 ] , V_30 ) ;
if ( V_24 ) {
F_33 ( & V_2 -> V_8 , 0 ) ;
F_27 ( F_22 ( V_2 ) ,
L_11
L_12 , V_24 ) ;
return V_24 ;
}
}
return F_33 ( & V_2 -> V_8 , 50 ) ;
}
int F_36 ( struct V_1 * V_2 , T_3 V_12 , T_4 * V_36 )
{
int V_24 ;
F_37 ( & V_2 -> V_7 ) ;
V_24 = F_38 ( V_2 , V_36 , V_12 ) ;
F_39 ( & V_2 -> V_7 ) ;
return V_24 ;
}
int F_40 ( struct V_1 * V_2 , T_3 V_12 , T_5 * V_36 )
{
int V_24 ;
F_37 ( & V_2 -> V_7 ) ;
V_24 = F_41 ( V_2 , V_36 , V_12 ) ;
F_39 ( & V_2 -> V_7 ) ;
return V_24 ;
}
int F_42 ( struct V_1 * V_2 , T_3 V_12 , T_4 V_36 )
{
int V_24 ;
F_37 ( & V_2 -> V_7 ) ;
V_24 = F_43 ( V_2 , V_36 , V_12 ) ;
F_39 ( & V_2 -> V_7 ) ;
return V_24 ;
}
int F_44 ( struct V_1 * V_2 , T_3 V_12 , T_5 V_36 )
{
int V_24 ;
F_37 ( & V_2 -> V_7 ) ;
V_24 = F_45 ( V_2 , V_36 , V_12 ) ;
F_39 ( & V_2 -> V_7 ) ;
return V_24 ;
}
int F_46 ( struct V_1 * V_2 , const T_3 * V_40 ,
T_5 * V_22 , unsigned int V_23 )
{
int V_24 ;
F_37 ( & V_2 -> V_7 ) ;
V_24 = F_24 ( V_2 , V_22 , V_40 , V_23 ) ;
F_39 ( & V_2 -> V_7 ) ;
return V_24 ;
}
int F_47 ( struct V_1 * V_2 , const struct V_31 * V_32 ,
unsigned int V_23 )
{
int V_24 ;
F_37 ( & V_2 -> V_7 ) ;
V_24 = F_35 ( V_2 , V_32 , V_23 ) ;
F_39 ( & V_2 -> V_7 ) ;
return V_24 ;
}
static int F_48 ( struct V_1 * V_2 , T_2 * V_41 )
{
int V_24 ;
T_5 V_36 ;
F_6 ( F_7 ( & V_2 -> V_7 ) ) ;
V_24 = F_41 ( V_2 , & V_36 , V_42 ) ;
if ( V_24 )
goto error;
F_27 ( F_22 ( V_2 ) , L_13 , V_36 ) ;
* V_41 = V_36 & 0x0f ;
V_2 -> V_14 = ( V_36 >> 16 ) & 0x0f ;
V_2 -> V_15 = ( V_36 >> 8 ) & 0x1 ;
V_2 -> V_16 = ( V_36 >> 13 ) & 0x1 ;
V_2 -> V_17 = ( V_36 >> 21 ) & 0x1 ;
V_2 -> V_18 = ( V_36 >> 31 ) & 0x1 ;
V_2 -> V_19 = ( V_36 >> 7 ) & 0x1 ;
V_2 -> V_43 = ( ( V_36 >> 4 ) & 1 ) ? V_44 : V_45 ;
V_2 -> V_46 = 1 ;
if ( V_36 & ( 1 << 24 ) ) {
if ( V_36 & ( 1 << 29 ) )
V_2 -> V_46 = 0 ;
}
F_27 ( F_22 ( V_2 ) ,
L_14
L_15 ,
F_49 ( * V_41 ) , * V_41 ,
V_2 -> V_14 , V_2 -> V_15 ,
V_2 -> V_16 , V_2 -> V_17 ,
V_2 -> V_18 ,
V_2 -> V_43 == V_44 ? 1 : 2 ,
V_2 -> V_46 ) ;
return 0 ;
error:
* V_41 = 0 ;
V_2 -> V_14 = 0 ;
V_2 -> V_15 = 0 ;
V_2 -> V_16 = 0 ;
V_2 -> V_17 = 0 ;
V_2 -> V_18 = 0 ;
return V_24 ;
}
static int F_50 ( struct V_1 * V_2 , const T_2 * V_47 ,
const struct V_31 * V_48 ,
const char * type )
{
int V_24 ;
struct V_31 V_49 [ 2 ] = { V_48 [ 0 ] , V_48 [ 1 ] } ;
if ( V_47 ) {
V_49 [ 0 ] . V_36 = ( V_47 [ 3 ] << 24 )
| ( V_47 [ 2 ] << 16 )
| ( V_47 [ 1 ] << 8 )
| V_47 [ 0 ] ;
V_49 [ 1 ] . V_36 = ( V_47 [ 5 ] << 8 )
| V_47 [ 4 ] ;
F_27 ( F_22 ( V_2 ) , L_16 , type , V_47 ) ;
} else {
F_27 ( F_22 ( V_2 ) , L_17 , type ) ;
}
F_37 ( & V_2 -> V_7 ) ;
V_24 = F_35 ( V_2 , V_49 , F_51 ( V_49 ) ) ;
F_39 ( & V_2 -> V_7 ) ;
return V_24 ;
}
int F_52 ( struct V_1 * V_2 , const T_2 * V_47 )
{
static const struct V_31 V_49 [ 2 ] = {
[ 0 ] = { . V_12 = V_50 } ,
[ 1 ] = { . V_12 = V_51 } ,
} ;
return F_50 ( V_2 , V_47 , V_49 , L_18 ) ;
}
int F_53 ( struct V_1 * V_2 , const T_2 * V_52 )
{
static const struct V_31 V_49 [ 2 ] = {
[ 0 ] = { . V_12 = V_53 } ,
[ 1 ] = { . V_12 = V_54 } ,
} ;
return F_50 ( V_2 , V_52 , V_49 , L_19 ) ;
}
int F_54 ( struct V_1 * V_2 , T_2 * V_55 )
{
int V_24 ;
T_5 V_36 ;
F_37 ( & V_2 -> V_7 ) ;
V_24 = F_41 ( V_2 , & V_36 , V_56 ) ;
F_39 ( & V_2 -> V_7 ) ;
if ( V_24 )
return V_24 ;
* V_55 = V_36 >> 16 ;
F_27 ( F_22 ( V_2 ) , L_20 , * V_55 ) ;
return 0 ;
}
static int F_55 ( struct V_1 * V_2 , T_2 * V_22 , T_1 V_23 ,
T_3 V_57 , T_5 V_58 )
{
int V_24 ;
int V_13 ;
T_5 V_59 ;
F_6 ( F_7 ( & V_2 -> V_7 ) ) ;
for ( V_13 = 0 ; ; ) {
V_24 = F_41 ( V_2 , & V_59 ,
( T_3 ) ( ( T_4 ) V_57 + V_13 / 2 ) ) ;
if ( V_24 )
return V_24 ;
V_59 -= V_58 ;
if ( V_13 + 4 < V_23 ) {
V_22 [ V_13 ++ ] = V_59 ;
V_22 [ V_13 ++ ] = V_59 >> 8 ;
V_22 [ V_13 ++ ] = V_59 >> 16 ;
V_22 [ V_13 ++ ] = V_59 >> 24 ;
continue;
}
for (; V_13 < V_23 ; V_13 ++ )
V_22 [ V_13 ] = V_59 >> ( 8 * ( V_13 % 3 ) ) ;
return 0 ;
}
}
static int F_56 ( struct V_1 * V_2 )
{
return F_55 ( V_2 , V_2 -> V_60 ,
V_61 , V_62 ,
0 ) ;
}
static int F_57 ( struct V_1 * V_2 )
{
return F_55 ( V_2 , V_2 -> V_63 ,
V_61 , V_64 ,
V_65 ) ;
}
static int F_58 ( struct V_1 * V_2 )
{
int V_24 ;
int V_13 ;
static const T_3 V_40 [] = {
V_66 ,
V_67 ,
V_68 ,
} ;
for ( V_13 = 0 ; V_13 < 3 ; V_13 ++ ) {
V_24 = F_55 ( V_2 , V_2 -> V_69 [ V_13 ] ,
V_61 , V_40 [ V_13 ] , 0 ) ;
if ( V_24 )
return V_24 ;
}
return 0 ;
}
static int F_59 ( struct V_1 * V_2 )
{
int V_24 ;
V_24 = F_56 ( V_2 ) ;
if ( V_24 )
return V_24 ;
V_24 = F_57 ( V_2 ) ;
if ( V_24 )
return V_24 ;
V_24 = F_58 ( V_2 ) ;
if ( V_24 )
return V_24 ;
return 0 ;
}
int F_60 ( struct V_1 * V_2 )
{
int V_24 ;
T_5 V_70 ;
F_6 ( F_7 ( & V_2 -> V_7 ) ) ;
V_24 = F_41 ( V_2 , & V_70 , V_71 ) ;
if ( V_24 ) {
F_61 ( F_22 ( V_2 ) , L_21 , V_24 ) ;
return V_24 ;
}
V_70 &= ~ V_72 ;
V_24 = F_45 ( V_2 , V_70 , V_71 ) ;
if ( V_24 )
F_61 ( F_22 ( V_2 ) , L_22 , V_24 ) ;
return V_24 ;
}
int F_62 ( struct V_1 * V_2 )
{
int V_24 ;
T_5 V_70 ;
F_6 ( F_7 ( & V_2 -> V_7 ) ) ;
V_24 = F_41 ( V_2 , & V_70 , V_71 ) ;
if ( V_24 ) {
F_61 ( F_22 ( V_2 ) ,
L_21 , V_24 ) ;
return V_24 ;
}
V_70 |= V_72 ;
V_24 = F_45 ( V_2 , V_70 , V_71 ) ;
if ( V_24 )
F_61 ( F_22 ( V_2 ) , L_22 , V_24 ) ;
return V_24 ;
}
static int V_16 ( struct V_1 * V_2 )
{
int V_24 ;
T_4 V_36 ;
if ( ! V_2 -> V_16 )
return 0 ;
V_24 = F_38 ( V_2 , & V_36 , V_73 ) ;
if ( V_24 )
return V_24 ;
F_27 ( F_22 ( V_2 ) , L_23 , V_36 >> 8 ) ;
return F_45 ( V_2 , V_36 >> 8 , V_74 ) ;
}
static int V_17 ( struct V_1 * V_2 , T_2 V_75 )
{
F_6 ( F_7 ( & V_2 -> V_7 ) ) ;
if ( ! V_2 -> V_17 )
return 0 ;
return F_63 ( & V_2 -> V_9 , V_75 ) ;
}
int F_64 ( struct V_1 * V_2 , int V_75 )
{
struct V_33 V_32 [] = {
{ V_76 , 0x14 } , { V_77 , 0x12 } , { V_78 , 0x10 } ,
{ V_79 , 0x1e } ,
} ;
if ( V_75 == 1 || V_75 == 11 )
V_32 [ 0 ] . V_36 = 0x12 ;
F_27 ( F_22 ( V_2 ) , L_24 , V_75 ) ;
return F_34 ( V_2 , V_32 , F_51 ( V_32 ) ) ;
}
static int F_65 ( struct V_1 * V_2 )
{
static const struct V_33 V_32 [] = {
{ V_80 , 0x0a } , { V_81 , 0x06 } , { V_82 , 0x26 } ,
{ V_83 , 0x38 } , { V_84 , 0x80 } , { V_85 , 0xa0 } ,
{ V_86 , 0x81 } , { V_87 , 0x00 } , { V_88 , 0x7f } ,
{ V_89 , 0x8c } , { V_90 , 0x80 } , { V_91 , 0x3d } ,
{ V_92 , 0x20 } , { V_93 , 0x1e } , { V_94 , 0x0a } ,
{ V_95 , 0x48 } , { V_96 , 0x0c } , { V_97 , 0x0c } ,
{ V_98 , 0x23 } , { V_99 , 0x90 } , { V_100 , 0x14 } ,
{ V_101 , 0x40 } , { V_102 , 0x10 } , { V_103 , 0x19 } ,
{ V_104 , 0x7f } , { V_105 , 0x80 } , { V_106 , 0x4b } ,
{ V_107 , 0x60 } , { V_108 , 0x43 } , { V_109 , 0x08 } ,
{ V_110 , 0x06 } , { V_111 , 0x0a } , { V_112 , 0x00 } ,
{ V_113 , 0x00 } , { V_114 , 0x38 } , { V_115 , 0x0c } ,
{ V_116 , 0x84 } , { V_117 , 0x2a } , { V_118 , 0x80 } ,
{ V_119 , 0x10 } , { V_120 , 0x12 } , { V_121 , 0xff } ,
{ V_79 , 0x1E } , { V_122 , 0x26 } , { V_123 , 0x5b } ,
{ V_124 , 0xd0 } , { V_125 , 0x04 } , { V_126 , 0x58 } ,
{ V_127 , 0xc9 } , { V_128 , 0x88 } , { V_129 , 0x41 } ,
{ V_130 , 0x23 } , { V_131 , 0x10 } , { V_132 , 0xff } ,
{ V_133 , 0x32 } , { V_134 , 0x30 } , { V_135 , 0x65 } ,
{ V_136 , 0x41 } , { V_137 , 0x1b } , { V_138 , 0x30 } ,
{ V_139 , 0x68 } , { V_140 , 0x64 } , { V_141 , 0x64 } ,
{ V_142 , 0x00 } , { V_143 , 0x00 } , { V_144 , 0x00 } ,
{ V_145 , 0x02 } , { V_146 , 0x00 } , { V_147 , 0x00 } ,
{ V_148 , 0xff } , { V_149 , 0xfc } , { V_150 , 0x00 } ,
{ V_151 , 0x00 } , { V_152 , 0x00 } , { V_153 , 0x08 } ,
{ V_154 , 0x00 } , { V_155 , 0x00 } , { V_156 , 0xff } ,
{ V_157 , 0xe7 } , { V_158 , 0x00 } , { V_159 , 0x00 } ,
{ V_160 , 0x00 } , { V_161 , 0xae } , { V_162 , 0x02 } ,
{ V_163 , 0x00 } , { V_164 , 0x03 } , { V_165 , 0x65 } ,
{ V_166 , 0x04 } , { V_167 , 0x00 } , { V_168 , 0x0a } ,
{ V_169 , 0xaa } , { V_170 , 0xaa } , { V_171 , 0x25 } ,
{ V_172 , 0x25 } , { V_173 , 0x00 } , { V_174 , 0x1e } ,
{ V_175 , 0x90 } , { V_176 , 0x00 } , { V_177 , 0x00 } ,
{ } ,
{ V_178 , 0x00 } , { V_179 , 0x00 } , { V_180 , 0x00 } ,
{ V_181 , 0x00 } , { V_85 , 0x20 } , { V_88 , 0xf0 } ,
{ V_96 , 0x0e } , { V_97 , 0x0e } , { V_103 , 0x10 } ,
{ V_120 , 0x33 } , { V_79 , 0x1E } , { V_143 , 0x24 } ,
{ V_144 , 0x04 } , { V_145 , 0x00 } , { V_146 , 0x0C } ,
{ V_147 , 0x12 } , { V_148 , 0x0C } , { V_149 , 0x00 } ,
{ V_150 , 0x10 } , { V_151 , 0x08 } , { V_153 , 0x00 } ,
{ V_154 , 0x01 } , { V_155 , 0x00 } , { V_156 , 0x50 } ,
{ V_157 , 0x37 } , { V_158 , 0x35 } , { V_161 , 0x13 } ,
{ V_162 , 0x27 } , { V_163 , 0x27 } , { V_164 , 0x18 } ,
{ V_165 , 0x12 } , { V_169 , 0x27 } , { V_170 , 0x27 } ,
{ V_171 , 0x27 } , { V_172 , 0x27 } , { V_173 , 0x27 } ,
{ V_182 , 0x27 } , { V_183 , 0x26 } , { V_184 , 0x24 } ,
{ V_185 , 0xfc } , { V_186 , 0xfa } , { V_187 , 0x4f } ,
{ V_175 , 0xaa } , { V_177 , 0x03 } , { V_76 , 0x14 } ,
{ V_77 , 0x12 } , { V_78 , 0x10 } , { V_188 , 0x0C } ,
{ V_189 , 0xdf } , { V_190 , 0x40 } , { V_191 , 0xa0 } ,
{ V_192 , 0xb0 } , { V_193 , 0x99 } , { V_194 , 0x82 } ,
{ V_195 , 0x54 } , { V_196 , 0x1c } , { V_197 , 0x6c } ,
{ V_198 , 0x07 } , { V_199 , 0x4c } , { V_200 , 0x50 } ,
{ V_201 , 0x0e } , { V_202 , 0x18 } , { V_203 , 0xfe } ,
{ V_204 , 0xee } , { V_205 , 0xaa } , { V_206 , 0xfa } ,
{ V_207 , 0xfa } , { V_208 , 0xea } , { V_209 , 0xbe } ,
{ V_210 , 0xbe } , { V_211 , 0x6a } , { V_212 , 0xba } ,
{ V_213 , 0xba } , { V_214 , 0xba } ,
{ V_215 , 0x7d } ,
{ } ,
{ V_216 , 0x30 } ,
} ;
int V_24 , V_37 ;
F_27 ( F_22 ( V_2 ) , L_25 ) ;
V_24 = F_60 ( V_2 ) ;
if ( V_24 )
goto V_217;
V_24 = F_34 ( V_2 , V_32 , F_51 ( V_32 ) ) ;
if ( V_24 )
goto V_218;
V_24 = V_16 ( V_2 ) ;
V_218:
V_37 = F_62 ( V_2 ) ;
if ( V_37 && ! V_24 )
V_24 = V_37 ;
V_217:
return V_24 ;
}
static int F_66 ( struct V_1 * V_2 )
{
static const struct V_33 V_32 [] = {
{ V_80 , 0x14 } , { V_81 , 0x06 } , { V_82 , 0x26 } ,
{ V_83 , 0x38 } , { V_84 , 0x80 } , { V_85 , 0xe0 } ,
{ V_86 , 0x81 } ,
{ V_87 , 0x00 } ,
{ V_88 , 0xf0 } , { V_89 , 0x8c } , { V_90 , 0x80 } ,
{ V_91 , 0x3d } , { V_92 , 0x20 } , { V_93 , 0x1e } ,
{ V_94 , 0x0a } , { V_95 , 0x48 } ,
{ V_96 , 0x10 } ,
{ V_97 , 0x0e } , { V_98 , 0x23 } , { V_99 , 0x90 } ,
{ V_100 , 0x14 } , { V_101 , 0x40 } , { V_102 , 0x10 } ,
{ V_103 , 0x10 } , { V_104 , 0x7f } , { V_105 , 0x80 } ,
{ V_106 , 0x4b } ,
{ V_107 , 0x60 } , { V_108 , 0x43 } , { V_109 , 0x08 } ,
{ V_110 , 0x06 } , { V_111 , 0x0a } , { V_112 , 0x00 } ,
{ V_113 , 0x00 } , { V_114 , 0x38 } , { V_115 , 0x0c } ,
{ V_116 , 0x84 } , { V_117 , 0x2a } , { V_118 , 0x80 } ,
{ V_119 , 0x10 } , { V_120 , 0x33 } , { V_121 , 0xff } ,
{ V_79 , 0x1E } , { V_122 , 0x26 } , { V_123 , 0x5b } ,
{ V_124 , 0xd0 } , { V_125 , 0x04 } , { V_126 , 0x58 } ,
{ V_127 , 0xc9 } , { V_128 , 0x88 } , { V_129 , 0x41 } ,
{ V_130 , 0x23 } , { V_131 , 0x10 } , { V_132 , 0xff } ,
{ V_133 , 0x32 } , { V_134 , 0x30 } , { V_135 , 0x65 } ,
{ V_136 , 0x41 } , { V_137 , 0x1b } , { V_138 , 0x30 } ,
{ V_139 , 0xf0 } , { V_140 , 0x64 } , { V_141 , 0x64 } ,
{ V_142 , 0x00 } , { V_143 , 0x24 } , { V_144 , 0x04 } ,
{ V_145 , 0x00 } , { V_146 , 0x0c } , { V_147 , 0x12 } ,
{ V_148 , 0x0c } , { V_149 , 0x00 } , { V_150 , 0x58 } ,
{ V_151 , 0x04 } , { V_152 , 0x00 } , { V_153 , 0x00 } ,
{ V_154 , 0x01 } ,
{ V_155 , 0x20 } ,
{ V_156 , 0x50 } , { V_157 , 0x37 } , { V_158 , 0x35 } ,
{ V_159 , 0x00 } , { V_160 , 0x01 } , { V_161 , 0x13 } ,
{ V_162 , 0x27 } , { V_163 , 0x27 } , { V_164 , 0x18 } ,
{ V_165 , 0x12 } , { V_166 , 0x04 } , { V_167 , 0x00 } ,
{ V_168 , 0x0a } , { V_169 , 0x27 } , { V_170 , 0x27 } ,
{ V_171 , 0x27 } , { V_172 , 0x27 } , { V_173 , 0x27 } ,
{ V_182 , 0x27 } , { V_183 , 0x26 } , { V_184 , 0x24 } ,
{ V_185 , 0xfc } , { V_186 , 0xfa } , { V_174 , 0x1e } ,
{ V_175 , 0x90 } , { V_176 , 0x00 } , { V_177 , 0x00 } ,
{ V_76 , 0x14 } , { V_77 , 0x12 } , { V_78 , 0x10 } ,
{ V_188 , 0x0c } , { V_189 , 0xdf } , { V_190 , 0xa0 } ,
{ V_191 , 0xa8 } , { V_192 , 0xb4 } , { V_193 , 0x98 } ,
{ V_194 , 0x82 } , { V_195 , 0x53 } , { V_196 , 0x1c } ,
{ V_197 , 0x6c } , { V_198 , 0x07 } , { V_199 , 0x40 } ,
{ V_200 , 0x40 } ,
{ V_201 , 0x14 } ,
{ V_202 , 0x18 } , { V_219 , 0x70 } , { V_203 , 0xfe } ,
{ V_204 , 0xee } , { V_205 , 0xaa } , { V_206 , 0xfa } ,
{ V_207 , 0xfa } , { V_208 , 0xea } , { V_209 , 0xbe } ,
{ V_210 , 0xbe } , { V_211 , 0x6a } , { V_212 , 0xba } ,
{ V_213 , 0xba } , { V_214 , 0xba } ,
{ V_215 , 0x7d } ,
{} ,
{ V_216 , 0x30 } ,
} ;
int V_24 , V_37 ;
F_27 ( F_22 ( V_2 ) , L_25 ) ;
V_24 = F_60 ( V_2 ) ;
if ( V_24 )
goto V_217;
V_24 = F_34 ( V_2 , V_32 , F_51 ( V_32 ) ) ;
V_37 = F_62 ( V_2 ) ;
if ( V_37 && ! V_24 )
V_24 = V_37 ;
V_217:
return V_24 ;
}
static int F_67 ( struct V_1 * V_2 )
{
return F_17 ( V_2 ) ? F_66 ( V_2 ) :
F_65 ( V_2 ) ;
}
static int F_68 ( struct V_1 * V_2 )
{
static const struct V_31 V_32 [] = {
{ V_220 , V_221 } ,
{ V_222 , 0x000c0640 } ,
} ;
F_27 ( F_22 ( V_2 ) , L_25 ) ;
F_6 ( F_7 ( & V_2 -> V_7 ) ) ;
return F_35 ( V_2 , V_32 , F_51 ( V_32 ) ) ;
}
static int F_69 ( struct V_1 * V_2 )
{
static const struct V_31 V_32 [] = {
{ V_223 , V_224 } ,
{ V_225 , 0x007f003f } ,
{ V_226 , 0x007f003f } ,
{ V_227 , 0x003f001f } ,
{ V_228 , 0x001f000f } ,
{ V_229 , 0x00280028 } ,
{ V_230 , 0x008C003C } ,
{ V_231 , 0x01800824 } ,
{ V_222 , 0x000c0eff , } ,
} ;
F_27 ( F_22 ( V_2 ) , L_25 ) ;
F_6 ( F_7 ( & V_2 -> V_7 ) ) ;
return F_35 ( V_2 , V_32 , F_51 ( V_32 ) ) ;
}
static int F_70 ( struct V_1 * V_2 )
{
int V_24 ;
static const struct V_31 V_32 [] = {
{ V_232 , 0x20 } ,
{ V_233 , 0x30000808 } ,
{ V_234 , 0 } ,
{ V_235 , V_236 } ,
{ V_237 , 0x00 } ,
{ V_238 , 0x80000000 } ,
{ V_71 , 0xa4 } ,
{ V_239 , 0x7f } ,
{ V_240 , 0x00f00401 } ,
{ V_241 , 0x00 } ,
{ V_232 , 0x80 } ,
{ V_239 , 0x00 } ,
{ V_242 , 0x100 } ,
{ V_243 , 0x70 } ,
{ V_244 , 0x10000000 } ,
{ V_245 , 0x02030203 } ,
{ V_246 , 0x1 } ,
{ V_247 , 0x114 } ,
{ V_248 , V_249 } ,
{ V_250 , V_251 } ,
} ;
F_6 ( F_7 ( & V_2 -> V_7 ) ) ;
V_24 = F_35 ( V_2 , V_32 , F_51 ( V_32 ) ) ;
if ( V_24 )
return V_24 ;
return F_17 ( V_2 ) ?
F_69 ( V_2 ) : F_68 ( V_2 ) ;
}
static int F_71 ( struct V_1 * V_2 , struct V_252 * V_253 )
{
int V_24 ;
static const T_3 V_254 [] =
{ V_255 , V_256 , V_257 } ;
T_5 V_22 [ 3 ] ;
V_24 = F_24 ( V_2 , V_22 , ( const T_3 * ) V_254 ,
F_51 ( V_254 ) ) ;
if ( V_24 ) {
memset ( V_253 , 0 , sizeof( * V_253 ) ) ;
return V_24 ;
}
V_253 -> V_258 = V_22 [ 0 ] ;
V_253 -> V_259 = V_22 [ 1 ] ;
V_253 -> V_260 = V_22 [ 2 ] ;
return 0 ;
}
static int F_72 ( struct V_1 * V_2 , struct V_252 * V_253 )
{
struct V_31 V_49 [ 3 ] ;
T_4 V_261 = V_253 -> V_260 & 0xffff ;
if ( V_261 <= 5 )
V_261 = 5 ;
if ( V_253 -> V_259 < 4 || V_253 -> V_259 >= V_261 )
V_253 -> V_259 = V_261 - 1 ;
if ( V_253 -> V_258 >= V_253 -> V_259 )
V_253 -> V_258 = V_253 -> V_259 - 1 ;
V_49 [ 0 ] . V_12 = V_255 ;
V_49 [ 0 ] . V_36 = V_253 -> V_258 ;
V_49 [ 1 ] . V_12 = V_256 ;
V_49 [ 1 ] . V_36 = V_253 -> V_259 ;
V_49 [ 2 ] . V_12 = V_257 ;
V_49 [ 2 ] . V_36 = ( V_253 -> V_260 & ~ 0xffff ) | V_261 ;
return F_35 ( V_2 , V_49 , F_51 ( V_49 ) ) ;
}
static int F_73 ( struct V_1 * V_2 , T_4 V_262 ,
T_2 V_263 , int type )
{
int V_24 ;
struct V_252 V_253 ;
T_5 V_261 , V_264 ;
F_6 ( F_7 ( & V_2 -> V_7 ) ) ;
if ( V_262 > 0 ) {
switch ( type ) {
case V_265 :
case V_266 :
V_264 = V_267 ;
break;
case V_268 :
V_264 = V_269 ;
break;
default:
V_264 = 0 ;
break;
}
} else {
V_263 = 0 ;
V_264 = 0 ;
}
V_261 = V_264 | ( V_263 << 16 ) | V_262 ;
V_24 = F_45 ( V_2 , V_261 , V_257 ) ;
if ( V_24 )
return V_24 ;
V_24 = F_71 ( V_2 , & V_253 ) ;
if ( V_24 )
return V_24 ;
return F_72 ( V_2 , & V_253 ) ;
}
int F_74 ( struct V_1 * V_2 , T_4 V_262 , T_2 V_263 ,
int type )
{
int V_24 ;
F_37 ( & V_2 -> V_7 ) ;
V_24 = F_73 ( V_2 , V_262 , V_263 , type ) ;
F_39 ( & V_2 -> V_7 ) ;
return V_24 ;
}
static int F_75 ( struct V_1 * V_2 )
{
int V_24 ;
F_27 ( F_22 ( V_2 ) , L_25 ) ;
F_6 ( F_7 ( & V_2 -> V_7 ) ) ;
V_24 = F_67 ( V_2 ) ;
if ( V_24 )
return V_24 ;
V_24 = F_70 ( V_2 ) ;
if ( V_24 )
return V_24 ;
return F_73 ( V_2 , 100 , 0 , V_270 ) ;
}
static T_3 F_76 ( struct V_1 * V_2 , T_4 V_271 )
{
return ( T_3 ) ( ( T_4 ) V_2 -> V_272 + V_271 ) ;
}
static int F_77 ( struct V_1 * V_2 , const T_3 V_12 ,
const char * V_273 )
{
int V_24 ;
T_5 V_36 ;
V_24 = F_41 ( V_2 , & V_36 , V_12 ) ;
if ( V_24 ) {
F_27 ( F_22 ( V_2 ) ,
L_26 , V_273 , V_24 ) ;
return V_24 ;
}
F_27 ( F_22 ( V_2 ) , L_27 ,
V_273 , ( unsigned int ) V_36 ) ;
return 0 ;
}
static int F_78 ( struct V_1 * V_2 )
{
int V_24 ;
V_24 = F_77 ( V_2 , V_246 , L_28 ) ;
if ( V_24 )
return V_24 ;
V_24 = F_77 ( V_2 , V_274 , L_29 ) ;
if ( V_24 )
return V_24 ;
return F_77 ( V_2 , V_275 , L_30 ) ;
}
static void F_79 ( struct V_1 * V_2 )
{
const T_3 V_12 [ 4 ] = {
F_76 ( V_2 , V_276 ) ,
F_76 ( V_2 , V_277 ) ,
F_76 ( V_2 , V_278 ) ,
F_76 ( V_2 , V_279 ) ,
} ;
int V_24 ;
T_4 V_22 [ 4 ] ;
V_24 = F_26 ( V_2 , V_22 , ( const T_3 * ) V_12 ,
F_51 ( V_12 ) ) ;
if ( V_24 ) {
F_27 ( F_22 ( V_2 ) , L_31 ,
V_24 ) ;
return;
}
F_27 ( F_22 ( V_2 ) , L_32 , V_22 [ 0 ] ) ;
F_27 ( F_22 ( V_2 ) , L_33 , V_22 [ 1 ] ) ;
F_27 ( F_22 ( V_2 ) , L_34 , V_22 [ 2 ] ) ;
F_27 ( F_22 ( V_2 ) , L_35 , V_22 [ 3 ] ) ;
}
static int F_80 ( struct V_1 * V_2 )
{
struct V_280 * V_280 = F_14 ( V_2 ) -> V_4 -> V_280 ;
int V_24 ;
T_4 V_281 ;
V_24 = F_38 ( V_2 , & V_281 ,
F_76 ( V_2 , V_276 ) ) ;
if ( V_24 )
return V_24 ;
F_21 ( F_22 ( V_2 ) , L_36 , V_281 ) ;
snprintf ( V_280 -> V_282 , sizeof( V_280 -> V_282 ) ,
L_37 , V_281 ) ;
return 0 ;
}
static int F_81 ( struct V_1 * V_2 , int V_283 )
{
T_5 V_284 ;
F_6 ( F_7 ( & V_2 -> V_7 ) ) ;
if ( ! V_283 )
V_284 = V_285 | V_286 | V_287 | V_288 ;
else
V_284 = V_285 | V_286 | V_287 | V_288 |
V_289 | V_290 | V_291 ;
return F_45 ( V_2 , V_284 , V_292 ) ;
}
int F_82 ( struct V_1 * V_2 ,
int V_293 )
{
T_5 V_36 = 0 ;
F_27 ( F_22 ( V_2 ) , L_38 , V_293 ) ;
V_36 |= V_293 << V_294 ;
V_36 |= V_293 << V_295 ;
V_36 |= F_83 ( V_296 ) << V_297 ;
V_36 |= V_298 << V_299 ;
V_36 |= F_83 ( V_296 ) << V_300 ;
V_36 |= V_298 << V_301 ;
return F_45 ( V_2 , V_36 , V_245 ) ;
}
int F_84 ( struct V_1 * V_2 )
{
int V_24 ;
F_37 ( & V_2 -> V_7 ) ;
V_24 = F_45 ( V_2 , V_302 , V_275 ) ;
F_39 ( & V_2 -> V_7 ) ;
return V_24 ;
}
static int F_85 ( struct V_1 * V_2 )
{
return F_45 ( V_2 , V_303 , V_275 ) ;
}
int F_86 ( struct V_1 * V_2 )
{
int V_24 ;
F_37 ( & V_2 -> V_7 ) ;
V_24 = F_85 ( V_2 ) ;
F_39 ( & V_2 -> V_7 ) ;
return V_24 ;
}
static int F_87 ( struct V_1 * V_2 )
{
int V_24 ;
F_6 ( F_7 ( & V_2 -> V_7 ) ) ;
V_24 = F_38 ( V_2 , ( T_4 * ) & V_2 -> V_272 ,
V_304 ) ;
if ( V_24 )
return V_24 ;
F_27 ( F_22 ( V_2 ) , L_39 ,
( T_4 ) V_2 -> V_272 ) ;
return 0 ;
}
int F_88 ( struct V_1 * V_2 , T_2 * V_12 )
{
F_27 ( F_22 ( V_2 ) , L_25 ) ;
return F_89 ( & V_2 -> V_8 , V_305 , V_12 ,
V_306 ) ;
}
int F_90 ( struct V_1 * V_2 )
{
int V_24 ;
T_2 V_41 ;
F_27 ( F_22 ( V_2 ) , L_25 ) ;
F_37 ( & V_2 -> V_7 ) ;
#ifdef F_30
V_24 = F_78 ( V_2 ) ;
if ( V_24 )
goto V_217;
#endif
V_24 = F_45 ( V_2 , 1 , V_246 ) ;
if ( V_24 )
goto V_217;
V_24 = F_87 ( V_2 ) ;
if ( V_24 )
goto V_217;
V_24 = F_45 ( V_2 , 0 , V_274 ) ;
if ( V_24 )
goto V_217;
V_24 = F_45 ( V_2 , V_307 , V_308 ) ;
if ( V_24 )
goto V_217;
V_24 = F_81 ( V_2 , 1 ) ;
if ( V_24 )
goto V_217;
V_24 = F_85 ( V_2 ) ;
if ( V_24 )
goto V_217;
V_24 = F_48 ( V_2 , & V_41 ) ;
if ( V_24 )
goto V_217;
V_24 = F_75 ( V_2 ) ;
if ( V_24 )
goto V_217;
V_24 = F_91 ( & V_2 -> V_9 , V_41 ) ;
if ( V_24 )
goto V_217;
V_24 = F_80 ( V_2 ) ;
if ( V_24 )
goto V_217;
#ifdef F_30
F_79 ( V_2 ) ;
V_24 = F_78 ( V_2 ) ;
if ( V_24 )
goto V_217;
#endif
V_24 = F_59 ( V_2 ) ;
if ( V_24 )
goto V_217;
F_20 ( V_2 ) ;
V_217:
F_39 ( & V_2 -> V_7 ) ;
return V_24 ;
}
static int F_92 ( struct V_1 * V_2 , T_2 V_75 )
{
T_2 V_36 = V_2 -> V_63 [ V_75 - 1 ] ;
return F_43 ( V_2 , V_36 , V_107 ) ;
}
static int F_93 ( struct V_1 * V_2 , T_2 V_75 )
{
T_2 V_36 = V_2 -> V_60 [ V_75 - 1 ] ;
return F_43 ( V_2 , V_36 , V_128 ) ;
}
static int F_94 ( struct V_1 * V_2 , T_2 V_75 )
{
struct V_33 V_32 [ 3 ] ;
V_32 [ 0 ] . V_12 = V_127 ;
V_32 [ 0 ] . V_36 = V_2 -> V_69 [ V_309 ] [ V_75 - 1 ] ;
V_32 [ 1 ] . V_12 = V_126 ;
V_32 [ 1 ] . V_36 = V_2 -> V_69 [ V_310 ] [ V_75 - 1 ] ;
V_32 [ 2 ] . V_12 = V_125 ;
V_32 [ 2 ] . V_36 = V_2 -> V_69 [ V_311 ] [ V_75 - 1 ] ;
return F_34 ( V_2 , V_32 , F_51 ( V_32 ) ) ;
}
static int F_95 ( struct V_1 * V_2 ,
T_2 V_75 )
{
int V_24 ;
if ( ! F_96 ( & V_2 -> V_9 ) )
return 0 ;
V_24 = F_92 ( V_2 , V_75 ) ;
if ( V_24 )
return V_24 ;
if ( F_17 ( V_2 ) ) {
static const struct V_33 V_32 [] = {
{ V_129 , 0x28 } ,
{} ,
{ V_129 , 0x2a } ,
} ;
V_24 = F_94 ( V_2 , V_75 ) ;
if ( V_24 )
return V_24 ;
V_24 = F_93 ( V_2 , V_75 ) ;
if ( V_24 )
return V_24 ;
V_24 = F_34 ( V_2 , V_32 , F_51 ( V_32 ) ) ;
if ( V_24 )
return V_24 ;
}
return 0 ;
}
static int V_15 ( struct V_1 * V_2 )
{
int V_24 ;
T_5 V_36 ;
if ( ! V_2 -> V_15 || ! F_97 ( & V_2 -> V_9 ) )
return 0 ;
F_6 ( F_7 ( & V_2 -> V_7 ) ) ;
V_24 = F_41 ( V_2 , & V_36 , V_73 ) ;
if ( V_24 )
return V_24 ;
F_27 ( F_22 ( V_2 ) , L_23 , V_36 & 0xff ) ;
return F_43 ( V_2 , V_36 & 0xff , V_79 ) ;
}
int F_98 ( struct V_1 * V_2 , T_2 V_75 )
{
int V_24 , V_37 ;
F_37 ( & V_2 -> V_7 ) ;
V_24 = F_60 ( V_2 ) ;
if ( V_24 )
goto V_217;
V_24 = F_99 ( & V_2 -> V_9 , V_75 ) ;
if ( V_24 )
goto V_218;
V_24 = F_95 ( V_2 , V_75 ) ;
if ( V_24 )
goto V_218;
V_24 = V_15 ( V_2 ) ;
if ( V_24 )
goto V_218;
V_24 = V_17 ( V_2 , V_75 ) ;
if ( V_24 )
goto V_218;
V_24 = F_45 ( V_2 , 0 , V_312 ) ;
V_218:
V_37 = F_62 ( V_2 ) ;
if ( V_37 && ! V_24 )
V_24 = V_37 ;
V_217:
F_39 ( & V_2 -> V_7 ) ;
return V_24 ;
}
T_2 F_100 ( struct V_1 * V_2 )
{
T_2 V_75 ;
F_37 ( & V_2 -> V_7 ) ;
V_75 = V_2 -> V_9 . V_75 ;
F_39 ( & V_2 -> V_7 ) ;
return V_75 ;
}
int F_101 ( struct V_1 * V_2 , enum V_313 V_314 )
{
const T_3 V_20 [] = {
F_76 ( V_2 , V_279 ) ,
V_315 ,
} ;
int V_24 ;
T_4 V_59 [ F_51 ( V_20 ) ] ;
struct V_33 V_32 [ F_51 ( V_20 ) ] = {
[ 0 ] = { F_76 (chip, FW_REG_LED_LINK_STATUS) } ,
[ 1 ] = { V_315 } ,
} ;
T_4 V_316 ;
F_37 ( & V_2 -> V_7 ) ;
V_24 = F_26 ( V_2 , V_59 , ( const T_3 * ) V_20 , F_51 ( V_20 ) ) ;
if ( V_24 )
goto V_217;
V_316 = V_2 -> V_43 == V_44 ? V_45 : V_44 ;
switch ( V_314 ) {
case V_317 :
V_32 [ 0 ] . V_36 = V_318 ;
V_32 [ 1 ] . V_36 = V_59 [ 1 ] & ~ ( V_44 | V_45 ) ;
break;
case V_319 :
V_32 [ 0 ] . V_36 = V_318 ;
V_32 [ 1 ] . V_36 = V_59 [ 1 ] & ~ V_316 ;
if ( F_102 () % 3 == 0 ) {
V_32 [ 1 ] . V_36 &= ~ V_2 -> V_43 ;
} else {
V_32 [ 1 ] . V_36 |= V_2 -> V_43 ;
}
break;
case V_320 :
V_32 [ 0 ] . V_36 = V_321 ;
V_32 [ 1 ] . V_36 = V_59 [ 1 ] & ~ V_316 ;
V_32 [ 1 ] . V_36 |= V_2 -> V_43 ;
break;
default:
V_24 = - V_29 ;
goto V_217;
}
if ( V_59 [ 0 ] != V_32 [ 0 ] . V_36 || V_59 [ 1 ] != V_32 [ 1 ] . V_36 ) {
V_24 = F_34 ( V_2 , V_32 , F_51 ( V_32 ) ) ;
if ( V_24 )
goto V_217;
}
V_24 = 0 ;
V_217:
F_39 ( & V_2 -> V_7 ) ;
return V_24 ;
}
int F_103 ( struct V_1 * V_2 , T_4 V_322 )
{
int V_24 ;
if ( V_322 & ~ ( V_323 | V_324 ) )
return - V_29 ;
F_37 ( & V_2 -> V_7 ) ;
V_24 = F_45 ( V_2 , V_322 , V_325 ) ;
F_39 ( & V_2 -> V_7 ) ;
return V_24 ;
}
static inline T_2 F_104 ( const void * V_326 )
{
return V_327 | F_105 ( V_326 ) ;
}
T_2 F_106 ( const void * V_326 , const struct V_328 * V_314 )
{
T_2 V_329 ;
if ( V_314 -> V_330 & V_331 ) {
V_329 = F_104 ( V_326 ) ;
} else {
switch ( F_107 ( V_326 ) ) {
case V_332 :
V_329 = V_333 ;
break;
case V_334 :
V_329 = V_335 ;
break;
case V_336 :
V_329 = V_337 ;
break;
case V_338 :
V_329 = V_296 ;
break;
default:
V_329 = 0 ;
}
}
return V_329 ;
}
int F_108 ( struct V_1 * V_2 )
{
int V_24 ;
F_37 ( & V_2 -> V_7 ) ;
V_24 = F_109 ( & V_2 -> V_9 ) ;
F_39 ( & V_2 -> V_7 ) ;
return V_24 ;
}
int F_110 ( struct V_1 * V_2 )
{
int V_24 ;
F_37 ( & V_2 -> V_7 ) ;
V_24 = F_111 ( & V_2 -> V_9 ) ;
F_39 ( & V_2 -> V_7 ) ;
return V_24 ;
}
int F_112 ( struct V_1 * V_2 )
{
int V_24 ;
F_37 ( & V_2 -> V_7 ) ;
V_24 = F_113 ( & V_2 -> V_8 ) ;
F_39 ( & V_2 -> V_7 ) ;
return V_24 ;
}
void F_114 ( struct V_1 * V_2 )
{
F_37 ( & V_2 -> V_7 ) ;
F_115 ( & V_2 -> V_8 ) ;
F_39 ( & V_2 -> V_7 ) ;
F_116 ( & F_14 ( V_2 ) -> V_339 ) ;
}
int F_117 ( struct V_1 * V_2 )
{
int V_24 ;
F_37 ( & V_2 -> V_7 ) ;
F_118 ( & V_2 -> V_8 ) ;
V_24 = F_119 ( & V_2 -> V_8 ) ;
F_120 ( & V_2 -> V_8 ) ;
F_39 ( & V_2 -> V_7 ) ;
return V_24 ;
}
void F_121 ( struct V_1 * V_2 )
{
F_37 ( & V_2 -> V_7 ) ;
F_122 ( & V_2 -> V_8 ) ;
F_123 ( & V_2 -> V_8 ) ;
F_124 ( & V_2 -> V_8 ) ;
F_39 ( & V_2 -> V_7 ) ;
}
int F_125 ( struct V_1 * V_2 ,
const T_5 * V_22 , unsigned int V_23 , T_2 V_340 )
{
int V_24 ;
unsigned int V_13 ;
for ( V_13 = 0 ; V_13 < V_23 ; V_13 ++ ) {
V_24 = F_126 ( V_2 , V_22 [ V_13 ] , V_340 ) ;
if ( V_24 )
return V_24 ;
}
return 0 ;
}
int F_127 ( struct V_1 * V_2 , T_5 V_36 )
{
const struct V_33 V_32 [] = {
{ V_341 , ( V_36 >> 16 ) & 0xff } ,
{ V_342 , ( V_36 >> 8 ) & 0xff } ,
{ V_343 , V_36 & 0xff } ,
} ;
F_6 ( F_7 ( & V_2 -> V_7 ) ) ;
return F_34 ( V_2 , V_32 , F_51 ( V_32 ) ) ;
}
int F_128 ( struct V_1 * V_2 ,
const T_5 * V_22 , unsigned int V_23 )
{
int V_24 ;
unsigned int V_13 ;
for ( V_13 = 0 ; V_13 < V_23 ; V_13 ++ ) {
V_24 = F_127 ( V_2 , V_22 [ V_13 ] ) ;
if ( V_24 )
return V_24 ;
}
return 0 ;
}
int F_129 ( struct V_1 * V_2 ,
struct V_344 * V_345 )
{
const struct V_31 V_32 [] = {
{ V_237 , V_345 -> V_346 } ,
{ V_238 , V_345 -> V_347 } ,
} ;
return F_47 ( V_2 , V_32 , F_51 ( V_32 ) ) ;
}
T_6 F_130 ( struct V_1 * V_2 )
{
int V_24 ;
static const T_3 V_254 [] =
{ V_348 , V_349 } ;
T_5 V_22 [ 2 ] ;
T_6 V_350 ;
F_37 ( & V_2 -> V_7 ) ;
V_24 = F_24 ( V_2 , V_22 , ( const T_3 * ) V_254 ,
F_51 ( V_254 ) ) ;
F_39 ( & V_2 -> V_7 ) ;
if ( V_24 )
return 0 ;
V_350 = V_22 [ 1 ] ;
V_350 = ( V_350 << 32 ) | V_22 [ 0 ] ;
return V_350 ;
}
