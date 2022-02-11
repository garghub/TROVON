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
L_8 , V_31 , V_24 ) ;
return V_24 ;
}
for ( V_13 = 0 ; V_13 < V_23 ; V_13 ++ ) {
int V_30 = 2 * V_13 ;
V_22 [ V_13 ] = ( V_27 [ V_30 ] << 16 ) | V_27 [ V_30 + 1 ] ;
}
return 0 ;
}
static int F_28 ( struct V_1 * V_2 ,
const struct V_32 * V_33 ,
unsigned int V_23 )
{
int V_13 , V_30 , V_24 ;
struct V_34 V_35 [ V_36 * 2 ] ;
unsigned int V_28 ;
F_6 ( F_7 ( & V_2 -> V_7 ) ) ;
if ( V_23 == 0 )
return 0 ;
if ( V_23 > V_36 )
return - V_29 ;
V_28 = 2 * V_23 ;
F_25 ( V_28 * sizeof( struct V_34 ) > sizeof( V_35 ) ) ;
for ( V_13 = 0 ; V_13 < V_23 ; V_13 ++ ) {
V_30 = 2 * V_13 ;
V_35 [ V_30 ] . V_37 = V_33 [ V_13 ] . V_37 >> 16 ;
V_35 [ V_30 ] . V_12 = F_23 ( V_33 [ V_13 ] . V_12 ) ;
V_35 [ V_30 + 1 ] . V_37 = V_33 [ V_13 ] . V_37 ;
V_35 [ V_30 + 1 ] . V_12 = V_33 [ V_13 ] . V_12 ;
}
V_24 = F_29 ( & V_2 -> V_8 , V_35 , V_28 ) ;
#ifdef F_30
if ( V_24 ) {
F_27 ( F_22 ( V_2 ) ,
L_9 , V_24 ) ;
}
#endif
return V_24 ;
}
int F_31 ( struct V_1 * V_2 , const struct V_32 * V_33 ,
unsigned int V_23 )
{
int V_24 ;
F_32 ( & V_2 -> V_8 ) ;
V_24 = F_28 ( V_2 , V_33 , V_23 ) ;
if ( V_24 ) {
F_33 ( & V_2 -> V_8 , 0 ) ;
return V_24 ;
}
return F_33 ( & V_2 -> V_8 , 50 ) ;
}
int F_34 ( struct V_1 * V_2 ,
const struct V_34 * V_33 , unsigned int V_23 )
{
int V_24 ;
unsigned int V_13 , V_30 , V_38 , V_39 ;
F_6 ( F_7 ( & V_2 -> V_7 ) ) ;
F_32 ( & V_2 -> V_8 ) ;
for ( V_13 = 0 ; V_13 < V_23 ; V_13 += V_30 + V_38 ) {
V_38 = 0 ;
V_39 = V_23 - V_13 ;
if ( V_39 > V_40 )
V_39 = V_40 ;
for ( V_30 = 0 ; V_30 < V_39 ; V_30 ++ ) {
if ( ! V_33 [ V_13 + V_30 ] . V_12 ) {
V_38 = 1 ;
break;
}
}
V_24 = F_29 ( & V_2 -> V_8 , & V_33 [ V_13 ] , V_30 ) ;
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
const struct V_32 * V_33 , unsigned int V_23 )
{
int V_24 ;
unsigned int V_13 , V_30 , V_38 , V_39 ;
F_32 ( & V_2 -> V_8 ) ;
for ( V_13 = 0 ; V_13 < V_23 ; V_13 += V_30 + V_38 ) {
V_38 = 0 ;
V_39 = V_23 - V_13 ;
if ( V_39 > V_36 )
V_39 = V_36 ;
for ( V_30 = 0 ; V_30 < V_39 ; V_30 ++ ) {
if ( ! V_33 [ V_13 + V_30 ] . V_12 ) {
V_38 = 1 ;
break;
}
}
V_24 = F_28 ( V_2 , & V_33 [ V_13 ] , V_30 ) ;
if ( V_24 ) {
F_33 ( & V_2 -> V_8 , 0 ) ;
F_27 ( F_22 ( V_2 ) ,
L_11 , V_31 ,
V_24 ) ;
return V_24 ;
}
}
return F_33 ( & V_2 -> V_8 , 50 ) ;
}
int F_36 ( struct V_1 * V_2 , T_3 V_12 , T_4 * V_37 )
{
int V_24 ;
F_37 ( & V_2 -> V_7 ) ;
V_24 = F_38 ( V_2 , V_37 , V_12 ) ;
F_39 ( & V_2 -> V_7 ) ;
return V_24 ;
}
int F_40 ( struct V_1 * V_2 , T_3 V_12 , T_5 * V_37 )
{
int V_24 ;
F_37 ( & V_2 -> V_7 ) ;
V_24 = F_41 ( V_2 , V_37 , V_12 ) ;
F_39 ( & V_2 -> V_7 ) ;
return V_24 ;
}
int F_42 ( struct V_1 * V_2 , T_3 V_12 , T_4 V_37 )
{
int V_24 ;
F_37 ( & V_2 -> V_7 ) ;
V_24 = F_43 ( V_2 , V_37 , V_12 ) ;
F_39 ( & V_2 -> V_7 ) ;
return V_24 ;
}
int F_44 ( struct V_1 * V_2 , T_3 V_12 , T_5 V_37 )
{
int V_24 ;
F_37 ( & V_2 -> V_7 ) ;
V_24 = F_45 ( V_2 , V_37 , V_12 ) ;
F_39 ( & V_2 -> V_7 ) ;
return V_24 ;
}
int F_46 ( struct V_1 * V_2 , const T_3 * V_41 ,
T_5 * V_22 , unsigned int V_23 )
{
int V_24 ;
F_37 ( & V_2 -> V_7 ) ;
V_24 = F_24 ( V_2 , V_22 , V_41 , V_23 ) ;
F_39 ( & V_2 -> V_7 ) ;
return V_24 ;
}
int F_47 ( struct V_1 * V_2 , const struct V_32 * V_33 ,
unsigned int V_23 )
{
int V_24 ;
F_37 ( & V_2 -> V_7 ) ;
V_24 = F_35 ( V_2 , V_33 , V_23 ) ;
F_39 ( & V_2 -> V_7 ) ;
return V_24 ;
}
static int F_48 ( struct V_1 * V_2 , T_2 * V_42 )
{
int V_24 ;
T_5 V_37 ;
F_6 ( F_7 ( & V_2 -> V_7 ) ) ;
V_24 = F_41 ( V_2 , & V_37 , V_43 ) ;
if ( V_24 )
goto error;
F_27 ( F_22 ( V_2 ) , L_12 , V_37 ) ;
* V_42 = V_37 & 0x0f ;
V_2 -> V_14 = ( V_37 >> 16 ) & 0x0f ;
V_2 -> V_15 = ( V_37 >> 8 ) & 0x1 ;
V_2 -> V_16 = ( V_37 >> 13 ) & 0x1 ;
V_2 -> V_17 = ( V_37 >> 21 ) & 0x1 ;
V_2 -> V_18 = ( V_37 >> 31 ) & 0x1 ;
V_2 -> V_19 = ( V_37 >> 7 ) & 0x1 ;
V_2 -> V_44 = ( ( V_37 >> 4 ) & 1 ) ? V_45 : V_46 ;
V_2 -> V_47 = 1 ;
if ( V_37 & ( 1 << 24 ) ) {
if ( V_37 & ( 1 << 29 ) )
V_2 -> V_47 = 0 ;
}
F_27 ( F_22 ( V_2 ) ,
L_13
L_14 ,
F_49 ( * V_42 ) , * V_42 ,
V_2 -> V_14 , V_2 -> V_15 ,
V_2 -> V_16 , V_2 -> V_17 ,
V_2 -> V_18 ,
V_2 -> V_44 == V_45 ? 1 : 2 ,
V_2 -> V_47 ) ;
return 0 ;
error:
* V_42 = 0 ;
V_2 -> V_14 = 0 ;
V_2 -> V_15 = 0 ;
V_2 -> V_16 = 0 ;
V_2 -> V_17 = 0 ;
V_2 -> V_18 = 0 ;
return V_24 ;
}
static int F_50 ( struct V_1 * V_2 , const T_2 * V_48 ,
const struct V_32 * V_49 ,
const char * type )
{
int V_24 ;
struct V_32 V_50 [ 2 ] = { V_49 [ 0 ] , V_49 [ 1 ] } ;
if ( V_48 ) {
V_50 [ 0 ] . V_37 = ( V_48 [ 3 ] << 24 )
| ( V_48 [ 2 ] << 16 )
| ( V_48 [ 1 ] << 8 )
| V_48 [ 0 ] ;
V_50 [ 1 ] . V_37 = ( V_48 [ 5 ] << 8 )
| V_48 [ 4 ] ;
F_27 ( F_22 ( V_2 ) , L_15 , type , V_48 ) ;
} else {
F_27 ( F_22 ( V_2 ) , L_16 , type ) ;
}
F_37 ( & V_2 -> V_7 ) ;
V_24 = F_35 ( V_2 , V_50 , F_51 ( V_50 ) ) ;
F_39 ( & V_2 -> V_7 ) ;
return V_24 ;
}
int F_52 ( struct V_1 * V_2 , const T_2 * V_48 )
{
static const struct V_32 V_50 [ 2 ] = {
[ 0 ] = { . V_12 = V_51 } ,
[ 1 ] = { . V_12 = V_52 } ,
} ;
return F_50 ( V_2 , V_48 , V_50 , L_17 ) ;
}
int F_53 ( struct V_1 * V_2 , const T_2 * V_53 )
{
static const struct V_32 V_50 [ 2 ] = {
[ 0 ] = { . V_12 = V_54 } ,
[ 1 ] = { . V_12 = V_55 } ,
} ;
return F_50 ( V_2 , V_53 , V_50 , L_18 ) ;
}
int F_54 ( struct V_1 * V_2 , T_2 * V_56 )
{
int V_24 ;
T_5 V_37 ;
F_37 ( & V_2 -> V_7 ) ;
V_24 = F_41 ( V_2 , & V_37 , V_57 ) ;
F_39 ( & V_2 -> V_7 ) ;
if ( V_24 )
return V_24 ;
* V_56 = V_37 >> 16 ;
F_27 ( F_22 ( V_2 ) , L_19 , * V_56 ) ;
return 0 ;
}
static int F_55 ( struct V_1 * V_2 , T_2 * V_22 , T_1 V_23 ,
T_3 V_58 , T_5 V_59 )
{
int V_24 ;
int V_13 ;
T_5 V_60 ;
F_6 ( F_7 ( & V_2 -> V_7 ) ) ;
for ( V_13 = 0 ; ; ) {
V_24 = F_41 ( V_2 , & V_60 ,
( T_3 ) ( ( T_4 ) V_58 + V_13 / 2 ) ) ;
if ( V_24 )
return V_24 ;
V_60 -= V_59 ;
if ( V_13 + 4 < V_23 ) {
V_22 [ V_13 ++ ] = V_60 ;
V_22 [ V_13 ++ ] = V_60 >> 8 ;
V_22 [ V_13 ++ ] = V_60 >> 16 ;
V_22 [ V_13 ++ ] = V_60 >> 24 ;
continue;
}
for (; V_13 < V_23 ; V_13 ++ )
V_22 [ V_13 ] = V_60 >> ( 8 * ( V_13 % 3 ) ) ;
return 0 ;
}
}
static int F_56 ( struct V_1 * V_2 )
{
return F_55 ( V_2 , V_2 -> V_61 ,
V_62 , V_63 ,
0 ) ;
}
static int F_57 ( struct V_1 * V_2 )
{
return F_55 ( V_2 , V_2 -> V_64 ,
V_62 , V_65 ,
V_66 ) ;
}
static int F_58 ( struct V_1 * V_2 )
{
int V_24 ;
int V_13 ;
static const T_3 V_41 [] = {
V_67 ,
V_68 ,
V_69 ,
} ;
for ( V_13 = 0 ; V_13 < 3 ; V_13 ++ ) {
V_24 = F_55 ( V_2 , V_2 -> V_70 [ V_13 ] ,
V_62 , V_41 [ V_13 ] , 0 ) ;
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
T_5 V_71 ;
F_6 ( F_7 ( & V_2 -> V_7 ) ) ;
V_24 = F_41 ( V_2 , & V_71 , V_72 ) ;
if ( V_24 ) {
F_61 ( F_22 ( V_2 ) , L_20 , V_24 ) ;
return V_24 ;
}
V_71 &= ~ V_73 ;
V_24 = F_45 ( V_2 , V_71 , V_72 ) ;
if ( V_24 )
F_61 ( F_22 ( V_2 ) , L_21 , V_24 ) ;
return V_24 ;
}
int F_62 ( struct V_1 * V_2 )
{
int V_24 ;
T_5 V_71 ;
F_6 ( F_7 ( & V_2 -> V_7 ) ) ;
V_24 = F_41 ( V_2 , & V_71 , V_72 ) ;
if ( V_24 ) {
F_61 ( F_22 ( V_2 ) ,
L_20 , V_24 ) ;
return V_24 ;
}
V_71 |= V_73 ;
V_24 = F_45 ( V_2 , V_71 , V_72 ) ;
if ( V_24 )
F_61 ( F_22 ( V_2 ) , L_21 , V_24 ) ;
return V_24 ;
}
static int V_16 ( struct V_1 * V_2 )
{
int V_24 ;
T_4 V_37 ;
if ( ! V_2 -> V_16 )
return 0 ;
V_24 = F_38 ( V_2 , & V_37 , V_74 ) ;
if ( V_24 )
return V_24 ;
F_27 ( F_22 ( V_2 ) , L_22 , V_37 >> 8 ) ;
return F_45 ( V_2 , V_37 >> 8 , V_75 ) ;
}
static int V_17 ( struct V_1 * V_2 , T_2 V_76 )
{
F_6 ( F_7 ( & V_2 -> V_7 ) ) ;
if ( ! V_2 -> V_17 )
return 0 ;
return F_63 ( & V_2 -> V_9 , V_76 ) ;
}
int F_64 ( struct V_1 * V_2 , int V_76 )
{
struct V_34 V_33 [] = {
{ V_77 , 0x14 } , { V_78 , 0x12 } , { V_79 , 0x10 } ,
{ V_80 , 0x1e } ,
} ;
if ( V_76 == 1 || V_76 == 11 )
V_33 [ 0 ] . V_37 = 0x12 ;
F_27 ( F_22 ( V_2 ) , L_23 , V_76 ) ;
return F_34 ( V_2 , V_33 , F_51 ( V_33 ) ) ;
}
static int F_65 ( struct V_1 * V_2 )
{
static const struct V_34 V_33 [] = {
{ V_81 , 0x0a } , { V_82 , 0x06 } , { V_83 , 0x26 } ,
{ V_84 , 0x38 } , { V_85 , 0x80 } , { V_86 , 0xa0 } ,
{ V_87 , 0x81 } , { V_88 , 0x00 } , { V_89 , 0x7f } ,
{ V_90 , 0x8c } , { V_91 , 0x80 } , { V_92 , 0x3d } ,
{ V_93 , 0x20 } , { V_94 , 0x1e } , { V_95 , 0x0a } ,
{ V_96 , 0x48 } , { V_97 , 0x0c } , { V_98 , 0x0c } ,
{ V_99 , 0x23 } , { V_100 , 0x90 } , { V_101 , 0x14 } ,
{ V_102 , 0x40 } , { V_103 , 0x10 } , { V_104 , 0x19 } ,
{ V_105 , 0x7f } , { V_106 , 0x80 } , { V_107 , 0x4b } ,
{ V_108 , 0x60 } , { V_109 , 0x43 } , { V_110 , 0x08 } ,
{ V_111 , 0x06 } , { V_112 , 0x0a } , { V_113 , 0x00 } ,
{ V_114 , 0x00 } , { V_115 , 0x38 } , { V_116 , 0x0c } ,
{ V_117 , 0x84 } , { V_118 , 0x2a } , { V_119 , 0x80 } ,
{ V_120 , 0x10 } , { V_121 , 0x12 } , { V_122 , 0xff } ,
{ V_80 , 0x1E } , { V_123 , 0x26 } , { V_124 , 0x5b } ,
{ V_125 , 0xd0 } , { V_126 , 0x04 } , { V_127 , 0x58 } ,
{ V_128 , 0xc9 } , { V_129 , 0x88 } , { V_130 , 0x41 } ,
{ V_131 , 0x23 } , { V_132 , 0x10 } , { V_133 , 0xff } ,
{ V_134 , 0x32 } , { V_135 , 0x30 } , { V_136 , 0x65 } ,
{ V_137 , 0x41 } , { V_138 , 0x1b } , { V_139 , 0x30 } ,
{ V_140 , 0x68 } , { V_141 , 0x64 } , { V_142 , 0x64 } ,
{ V_143 , 0x00 } , { V_144 , 0x00 } , { V_145 , 0x00 } ,
{ V_146 , 0x02 } , { V_147 , 0x00 } , { V_148 , 0x00 } ,
{ V_149 , 0xff } , { V_150 , 0xfc } , { V_151 , 0x00 } ,
{ V_152 , 0x00 } , { V_153 , 0x00 } , { V_154 , 0x08 } ,
{ V_155 , 0x00 } , { V_156 , 0x00 } , { V_157 , 0xff } ,
{ V_158 , 0xe7 } , { V_159 , 0x00 } , { V_160 , 0x00 } ,
{ V_161 , 0x00 } , { V_162 , 0xae } , { V_163 , 0x02 } ,
{ V_164 , 0x00 } , { V_165 , 0x03 } , { V_166 , 0x65 } ,
{ V_167 , 0x04 } , { V_168 , 0x00 } , { V_169 , 0x0a } ,
{ V_170 , 0xaa } , { V_171 , 0xaa } , { V_172 , 0x25 } ,
{ V_173 , 0x25 } , { V_174 , 0x00 } , { V_175 , 0x1e } ,
{ V_176 , 0x90 } , { V_177 , 0x00 } , { V_178 , 0x00 } ,
{ } ,
{ V_179 , 0x00 } , { V_180 , 0x00 } , { V_181 , 0x00 } ,
{ V_182 , 0x00 } , { V_86 , 0x20 } , { V_89 , 0xf0 } ,
{ V_97 , 0x0e } , { V_98 , 0x0e } , { V_104 , 0x10 } ,
{ V_121 , 0x33 } , { V_80 , 0x1E } , { V_144 , 0x24 } ,
{ V_145 , 0x04 } , { V_146 , 0x00 } , { V_147 , 0x0C } ,
{ V_148 , 0x12 } , { V_149 , 0x0C } , { V_150 , 0x00 } ,
{ V_151 , 0x10 } , { V_152 , 0x08 } , { V_154 , 0x00 } ,
{ V_155 , 0x01 } , { V_156 , 0x00 } , { V_157 , 0x50 } ,
{ V_158 , 0x37 } , { V_159 , 0x35 } , { V_162 , 0x13 } ,
{ V_163 , 0x27 } , { V_164 , 0x27 } , { V_165 , 0x18 } ,
{ V_166 , 0x12 } , { V_170 , 0x27 } , { V_171 , 0x27 } ,
{ V_172 , 0x27 } , { V_173 , 0x27 } , { V_174 , 0x27 } ,
{ V_183 , 0x27 } , { V_184 , 0x26 } , { V_185 , 0x24 } ,
{ V_186 , 0xfc } , { V_187 , 0xfa } , { V_188 , 0x4f } ,
{ V_176 , 0xaa } , { V_178 , 0x03 } , { V_77 , 0x14 } ,
{ V_78 , 0x12 } , { V_79 , 0x10 } , { V_189 , 0x0C } ,
{ V_190 , 0xdf } , { V_191 , 0x40 } , { V_192 , 0xa0 } ,
{ V_193 , 0xb0 } , { V_194 , 0x99 } , { V_195 , 0x82 } ,
{ V_196 , 0x54 } , { V_197 , 0x1c } , { V_198 , 0x6c } ,
{ V_199 , 0x07 } , { V_200 , 0x4c } , { V_201 , 0x50 } ,
{ V_202 , 0x0e } , { V_203 , 0x18 } , { V_204 , 0xfe } ,
{ V_205 , 0xee } , { V_206 , 0xaa } , { V_207 , 0xfa } ,
{ V_208 , 0xfa } , { V_209 , 0xea } , { V_210 , 0xbe } ,
{ V_211 , 0xbe } , { V_212 , 0x6a } , { V_213 , 0xba } ,
{ V_214 , 0xba } , { V_215 , 0xba } ,
{ V_216 , 0x7d } ,
{ } ,
{ V_217 , 0x30 } ,
} ;
int V_24 , V_38 ;
F_27 ( F_22 ( V_2 ) , L_24 ) ;
V_24 = F_60 ( V_2 ) ;
if ( V_24 )
goto V_218;
V_24 = F_34 ( V_2 , V_33 , F_51 ( V_33 ) ) ;
if ( V_24 )
goto V_219;
V_24 = V_16 ( V_2 ) ;
V_219:
V_38 = F_62 ( V_2 ) ;
if ( V_38 && ! V_24 )
V_24 = V_38 ;
V_218:
return V_24 ;
}
static int F_66 ( struct V_1 * V_2 )
{
static const struct V_34 V_33 [] = {
{ V_81 , 0x14 } , { V_82 , 0x06 } , { V_83 , 0x26 } ,
{ V_84 , 0x38 } , { V_85 , 0x80 } , { V_86 , 0xe0 } ,
{ V_87 , 0x81 } ,
{ V_88 , 0x00 } ,
{ V_89 , 0xf0 } , { V_90 , 0x8c } , { V_91 , 0x80 } ,
{ V_92 , 0x3d } , { V_93 , 0x20 } , { V_94 , 0x1e } ,
{ V_95 , 0x0a } , { V_96 , 0x48 } ,
{ V_97 , 0x10 } ,
{ V_98 , 0x0e } , { V_99 , 0x23 } , { V_100 , 0x90 } ,
{ V_101 , 0x14 } , { V_102 , 0x40 } , { V_103 , 0x10 } ,
{ V_104 , 0x10 } , { V_105 , 0x7f } , { V_106 , 0x80 } ,
{ V_107 , 0x4b } ,
{ V_108 , 0x60 } , { V_109 , 0x43 } , { V_110 , 0x08 } ,
{ V_111 , 0x06 } , { V_112 , 0x0a } , { V_113 , 0x00 } ,
{ V_114 , 0x00 } , { V_115 , 0x38 } , { V_116 , 0x0c } ,
{ V_117 , 0x84 } , { V_118 , 0x2a } , { V_119 , 0x80 } ,
{ V_120 , 0x10 } , { V_121 , 0x33 } , { V_122 , 0xff } ,
{ V_80 , 0x1E } , { V_123 , 0x26 } , { V_124 , 0x5b } ,
{ V_125 , 0xd0 } , { V_126 , 0x04 } , { V_127 , 0x58 } ,
{ V_128 , 0xc9 } , { V_129 , 0x88 } , { V_130 , 0x41 } ,
{ V_131 , 0x23 } , { V_132 , 0x10 } , { V_133 , 0xff } ,
{ V_134 , 0x32 } , { V_135 , 0x30 } , { V_136 , 0x65 } ,
{ V_137 , 0x41 } , { V_138 , 0x1b } , { V_139 , 0x30 } ,
{ V_140 , 0xf0 } , { V_141 , 0x64 } , { V_142 , 0x64 } ,
{ V_143 , 0x00 } , { V_144 , 0x24 } , { V_145 , 0x04 } ,
{ V_146 , 0x00 } , { V_147 , 0x0c } , { V_148 , 0x12 } ,
{ V_149 , 0x0c } , { V_150 , 0x00 } , { V_151 , 0x58 } ,
{ V_152 , 0x04 } , { V_153 , 0x00 } , { V_154 , 0x00 } ,
{ V_155 , 0x01 } ,
{ V_156 , 0x20 } ,
{ V_157 , 0x50 } , { V_158 , 0x37 } , { V_159 , 0x35 } ,
{ V_160 , 0x00 } , { V_161 , 0x01 } , { V_162 , 0x13 } ,
{ V_163 , 0x27 } , { V_164 , 0x27 } , { V_165 , 0x18 } ,
{ V_166 , 0x12 } , { V_167 , 0x04 } , { V_168 , 0x00 } ,
{ V_169 , 0x0a } , { V_170 , 0x27 } , { V_171 , 0x27 } ,
{ V_172 , 0x27 } , { V_173 , 0x27 } , { V_174 , 0x27 } ,
{ V_183 , 0x27 } , { V_184 , 0x26 } , { V_185 , 0x24 } ,
{ V_186 , 0xfc } , { V_187 , 0xfa } , { V_175 , 0x1e } ,
{ V_176 , 0x90 } , { V_177 , 0x00 } , { V_178 , 0x00 } ,
{ V_77 , 0x14 } , { V_78 , 0x12 } , { V_79 , 0x10 } ,
{ V_189 , 0x0c } , { V_190 , 0xdf } , { V_191 , 0xa0 } ,
{ V_192 , 0xa8 } , { V_193 , 0xb4 } , { V_194 , 0x98 } ,
{ V_195 , 0x82 } , { V_196 , 0x53 } , { V_197 , 0x1c } ,
{ V_198 , 0x6c } , { V_199 , 0x07 } , { V_200 , 0x40 } ,
{ V_201 , 0x40 } ,
{ V_202 , 0x14 } ,
{ V_203 , 0x18 } , { V_220 , 0x70 } , { V_204 , 0xfe } ,
{ V_205 , 0xee } , { V_206 , 0xaa } , { V_207 , 0xfa } ,
{ V_208 , 0xfa } , { V_209 , 0xea } , { V_210 , 0xbe } ,
{ V_211 , 0xbe } , { V_212 , 0x6a } , { V_213 , 0xba } ,
{ V_214 , 0xba } , { V_215 , 0xba } ,
{ V_216 , 0x7d } ,
{} ,
{ V_217 , 0x30 } ,
} ;
int V_24 , V_38 ;
F_27 ( F_22 ( V_2 ) , L_24 ) ;
V_24 = F_60 ( V_2 ) ;
if ( V_24 )
goto V_218;
V_24 = F_34 ( V_2 , V_33 , F_51 ( V_33 ) ) ;
V_38 = F_62 ( V_2 ) ;
if ( V_38 && ! V_24 )
V_24 = V_38 ;
V_218:
return V_24 ;
}
static int F_67 ( struct V_1 * V_2 )
{
return F_17 ( V_2 ) ? F_66 ( V_2 ) :
F_65 ( V_2 ) ;
}
static int F_68 ( struct V_1 * V_2 )
{
static const struct V_32 V_33 [] = {
{ V_221 , V_222 } ,
{ V_223 , 0x000c0640 } ,
} ;
F_27 ( F_22 ( V_2 ) , L_24 ) ;
F_6 ( F_7 ( & V_2 -> V_7 ) ) ;
return F_35 ( V_2 , V_33 , F_51 ( V_33 ) ) ;
}
static int F_69 ( struct V_1 * V_2 )
{
static const struct V_32 V_33 [] = {
{ V_224 , V_225 } ,
{ V_226 , 0x007f003f } ,
{ V_227 , 0x007f003f } ,
{ V_228 , 0x003f001f } ,
{ V_229 , 0x001f000f } ,
{ V_230 , 0x00280028 } ,
{ V_231 , 0x008C003C } ,
{ V_232 , 0x01800824 } ,
{ V_223 , 0x000c0eff , } ,
} ;
F_27 ( F_22 ( V_2 ) , L_24 ) ;
F_6 ( F_7 ( & V_2 -> V_7 ) ) ;
return F_35 ( V_2 , V_33 , F_51 ( V_33 ) ) ;
}
static int F_70 ( struct V_1 * V_2 )
{
int V_24 ;
static const struct V_32 V_33 [] = {
{ V_233 , 0x20 } ,
{ V_234 , 0x30000808 } ,
{ V_235 , 0 } ,
{ V_236 , V_237 } ,
{ V_238 , 0x00 } ,
{ V_239 , 0x80000000 } ,
{ V_72 , 0xa4 } ,
{ V_240 , 0x7f } ,
{ V_241 , 0x00f00401 } ,
{ V_242 , 0x00 } ,
{ V_233 , 0x80 } ,
{ V_240 , 0x00 } ,
{ V_243 , 0x100 } ,
{ V_244 , 0x70 } ,
{ V_245 , 0x10000000 } ,
{ V_246 , 0x02030203 } ,
{ V_247 , 0x1 } ,
{ V_248 , 0x114 } ,
{ V_249 , V_250 } ,
{ V_251 , V_252 } ,
} ;
F_6 ( F_7 ( & V_2 -> V_7 ) ) ;
V_24 = F_35 ( V_2 , V_33 , F_51 ( V_33 ) ) ;
if ( V_24 )
return V_24 ;
return F_17 ( V_2 ) ?
F_69 ( V_2 ) : F_68 ( V_2 ) ;
}
static int F_71 ( struct V_1 * V_2 , struct V_253 * V_254 )
{
int V_24 ;
static const T_3 V_255 [] =
{ V_256 , V_257 , V_258 } ;
T_5 V_22 [ 3 ] ;
V_24 = F_24 ( V_2 , V_22 , ( const T_3 * ) V_255 ,
F_51 ( V_255 ) ) ;
if ( V_24 ) {
memset ( V_254 , 0 , sizeof( * V_254 ) ) ;
return V_24 ;
}
V_254 -> V_259 = V_22 [ 0 ] ;
V_254 -> V_260 = V_22 [ 1 ] ;
V_254 -> V_261 = V_22 [ 2 ] ;
return 0 ;
}
static int F_72 ( struct V_1 * V_2 , struct V_253 * V_254 )
{
struct V_32 V_50 [ 3 ] ;
T_4 V_262 = V_254 -> V_261 & 0xffff ;
if ( V_262 <= 5 )
V_262 = 5 ;
if ( V_254 -> V_260 < 4 || V_254 -> V_260 >= V_262 )
V_254 -> V_260 = V_262 - 1 ;
if ( V_254 -> V_259 >= V_254 -> V_260 )
V_254 -> V_259 = V_254 -> V_260 - 1 ;
V_50 [ 0 ] . V_12 = V_256 ;
V_50 [ 0 ] . V_37 = V_254 -> V_259 ;
V_50 [ 1 ] . V_12 = V_257 ;
V_50 [ 1 ] . V_37 = V_254 -> V_260 ;
V_50 [ 2 ] . V_12 = V_258 ;
V_50 [ 2 ] . V_37 = ( V_254 -> V_261 & ~ 0xffff ) | V_262 ;
return F_35 ( V_2 , V_50 , F_51 ( V_50 ) ) ;
}
static int F_73 ( struct V_1 * V_2 , T_4 V_263 ,
T_2 V_264 , int type )
{
int V_24 ;
struct V_253 V_254 ;
T_5 V_262 , V_265 ;
F_6 ( F_7 ( & V_2 -> V_7 ) ) ;
if ( V_263 > 0 ) {
switch ( type ) {
case V_266 :
case V_267 :
V_265 = V_268 ;
break;
case V_269 :
V_265 = V_270 ;
break;
default:
V_265 = 0 ;
break;
}
} else {
V_264 = 0 ;
V_265 = 0 ;
}
V_262 = V_265 | ( V_264 << 16 ) | V_263 ;
V_24 = F_45 ( V_2 , V_262 , V_258 ) ;
if ( V_24 )
return V_24 ;
V_24 = F_71 ( V_2 , & V_254 ) ;
if ( V_24 )
return V_24 ;
return F_72 ( V_2 , & V_254 ) ;
}
int F_74 ( struct V_1 * V_2 , T_4 V_263 , T_2 V_264 ,
int type )
{
int V_24 ;
F_37 ( & V_2 -> V_7 ) ;
V_24 = F_73 ( V_2 , V_263 , V_264 , type ) ;
F_39 ( & V_2 -> V_7 ) ;
return V_24 ;
}
static int F_75 ( struct V_1 * V_2 )
{
int V_24 ;
F_27 ( F_22 ( V_2 ) , L_24 ) ;
F_6 ( F_7 ( & V_2 -> V_7 ) ) ;
V_24 = F_67 ( V_2 ) ;
if ( V_24 )
return V_24 ;
V_24 = F_70 ( V_2 ) ;
if ( V_24 )
return V_24 ;
return F_73 ( V_2 , 100 , 0 , V_271 ) ;
}
static T_3 F_76 ( struct V_1 * V_2 , T_4 V_272 )
{
return ( T_3 ) ( ( T_4 ) V_2 -> V_273 + V_272 ) ;
}
static int F_77 ( struct V_1 * V_2 , const T_3 V_12 ,
const char * V_274 )
{
int V_24 ;
T_5 V_37 ;
V_24 = F_41 ( V_2 , & V_37 , V_12 ) ;
if ( V_24 ) {
F_27 ( F_22 ( V_2 ) ,
L_25 , V_274 , V_24 ) ;
return V_24 ;
}
F_27 ( F_22 ( V_2 ) , L_26 ,
V_274 , ( unsigned int ) V_37 ) ;
return 0 ;
}
static int F_78 ( struct V_1 * V_2 )
{
int V_24 ;
V_24 = F_77 ( V_2 , V_247 , L_27 ) ;
if ( V_24 )
return V_24 ;
V_24 = F_77 ( V_2 , V_275 , L_28 ) ;
if ( V_24 )
return V_24 ;
return F_77 ( V_2 , V_276 , L_29 ) ;
}
static void F_79 ( struct V_1 * V_2 )
{
const T_3 V_12 [ 4 ] = {
F_76 ( V_2 , V_277 ) ,
F_76 ( V_2 , V_278 ) ,
F_76 ( V_2 , V_279 ) ,
F_76 ( V_2 , V_280 ) ,
} ;
int V_24 ;
T_4 V_22 [ 4 ] ;
V_24 = F_26 ( V_2 , V_22 , ( const T_3 * ) V_12 ,
F_51 ( V_12 ) ) ;
if ( V_24 ) {
F_27 ( F_22 ( V_2 ) , L_30 ,
V_24 ) ;
return;
}
F_27 ( F_22 ( V_2 ) , L_31 , V_22 [ 0 ] ) ;
F_27 ( F_22 ( V_2 ) , L_32 , V_22 [ 1 ] ) ;
F_27 ( F_22 ( V_2 ) , L_33 , V_22 [ 2 ] ) ;
F_27 ( F_22 ( V_2 ) , L_34 , V_22 [ 3 ] ) ;
}
static int F_80 ( struct V_1 * V_2 )
{
struct V_281 * V_281 = F_14 ( V_2 ) -> V_4 -> V_281 ;
int V_24 ;
T_4 V_282 ;
V_24 = F_38 ( V_2 , & V_282 ,
F_76 ( V_2 , V_277 ) ) ;
if ( V_24 )
return V_24 ;
F_21 ( F_22 ( V_2 ) , L_35 , V_282 ) ;
snprintf ( V_281 -> V_283 , sizeof( V_281 -> V_283 ) ,
L_36 , V_282 ) ;
return 0 ;
}
static int F_81 ( struct V_1 * V_2 , int V_284 )
{
T_5 V_285 ;
F_6 ( F_7 ( & V_2 -> V_7 ) ) ;
if ( ! V_284 )
V_285 = V_286 | V_287 | V_288 | V_289 ;
else
V_285 = V_286 | V_287 | V_288 | V_289 |
V_290 | V_291 | V_292 ;
return F_45 ( V_2 , V_285 , V_293 ) ;
}
int F_82 ( struct V_1 * V_2 ,
int V_294 )
{
T_5 V_37 = 0 ;
F_27 ( F_22 ( V_2 ) , L_37 , V_294 ) ;
V_37 |= V_294 << V_295 ;
V_37 |= V_294 << V_296 ;
V_37 |= F_83 ( V_297 ) << V_298 ;
V_37 |= V_299 << V_300 ;
V_37 |= F_83 ( V_297 ) << V_301 ;
V_37 |= V_299 << V_302 ;
return F_45 ( V_2 , V_37 , V_246 ) ;
}
int F_84 ( struct V_1 * V_2 )
{
int V_24 ;
F_37 ( & V_2 -> V_7 ) ;
V_24 = F_45 ( V_2 , V_303 , V_276 ) ;
F_39 ( & V_2 -> V_7 ) ;
return V_24 ;
}
static int F_85 ( struct V_1 * V_2 )
{
return F_45 ( V_2 , V_304 , V_276 ) ;
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
V_24 = F_38 ( V_2 , ( T_4 * ) & V_2 -> V_273 ,
V_305 ) ;
if ( V_24 )
return V_24 ;
F_27 ( F_22 ( V_2 ) , L_38 ,
( T_4 ) V_2 -> V_273 ) ;
return 0 ;
}
int F_88 ( struct V_1 * V_2 , T_2 * V_12 )
{
F_27 ( F_22 ( V_2 ) , L_24 ) ;
return F_89 ( & V_2 -> V_8 , V_306 , V_12 ,
V_307 ) ;
}
int F_90 ( struct V_1 * V_2 )
{
int V_24 ;
T_2 V_42 ;
F_27 ( F_22 ( V_2 ) , L_24 ) ;
F_37 ( & V_2 -> V_7 ) ;
#ifdef F_30
V_24 = F_78 ( V_2 ) ;
if ( V_24 )
goto V_218;
#endif
V_24 = F_45 ( V_2 , 1 , V_247 ) ;
if ( V_24 )
goto V_218;
V_24 = F_87 ( V_2 ) ;
if ( V_24 )
goto V_218;
V_24 = F_45 ( V_2 , 0 , V_275 ) ;
if ( V_24 )
goto V_218;
V_24 = F_45 ( V_2 , V_308 , V_309 ) ;
if ( V_24 )
goto V_218;
V_24 = F_81 ( V_2 , 1 ) ;
if ( V_24 )
goto V_218;
V_24 = F_85 ( V_2 ) ;
if ( V_24 )
goto V_218;
V_24 = F_48 ( V_2 , & V_42 ) ;
if ( V_24 )
goto V_218;
V_24 = F_75 ( V_2 ) ;
if ( V_24 )
goto V_218;
V_24 = F_91 ( & V_2 -> V_9 , V_42 ) ;
if ( V_24 )
goto V_218;
V_24 = F_80 ( V_2 ) ;
if ( V_24 )
goto V_218;
#ifdef F_30
F_79 ( V_2 ) ;
V_24 = F_78 ( V_2 ) ;
if ( V_24 )
goto V_218;
#endif
V_24 = F_59 ( V_2 ) ;
if ( V_24 )
goto V_218;
F_20 ( V_2 ) ;
V_218:
F_39 ( & V_2 -> V_7 ) ;
return V_24 ;
}
static int F_92 ( struct V_1 * V_2 , T_2 V_76 )
{
T_2 V_37 = V_2 -> V_64 [ V_76 - 1 ] ;
return F_43 ( V_2 , V_37 , V_108 ) ;
}
static int F_93 ( struct V_1 * V_2 , T_2 V_76 )
{
T_2 V_37 = V_2 -> V_61 [ V_76 - 1 ] ;
return F_43 ( V_2 , V_37 , V_129 ) ;
}
static int F_94 ( struct V_1 * V_2 , T_2 V_76 )
{
struct V_34 V_33 [ 3 ] ;
V_33 [ 0 ] . V_12 = V_128 ;
V_33 [ 0 ] . V_37 = V_2 -> V_70 [ V_310 ] [ V_76 - 1 ] ;
V_33 [ 1 ] . V_12 = V_127 ;
V_33 [ 1 ] . V_37 = V_2 -> V_70 [ V_311 ] [ V_76 - 1 ] ;
V_33 [ 2 ] . V_12 = V_126 ;
V_33 [ 2 ] . V_37 = V_2 -> V_70 [ V_312 ] [ V_76 - 1 ] ;
return F_34 ( V_2 , V_33 , F_51 ( V_33 ) ) ;
}
static int F_95 ( struct V_1 * V_2 ,
T_2 V_76 )
{
int V_24 ;
if ( ! F_96 ( & V_2 -> V_9 ) )
return 0 ;
V_24 = F_92 ( V_2 , V_76 ) ;
if ( V_24 )
return V_24 ;
if ( F_17 ( V_2 ) ) {
static const struct V_34 V_33 [] = {
{ V_130 , 0x28 } ,
{} ,
{ V_130 , 0x2a } ,
} ;
V_24 = F_94 ( V_2 , V_76 ) ;
if ( V_24 )
return V_24 ;
V_24 = F_93 ( V_2 , V_76 ) ;
if ( V_24 )
return V_24 ;
V_24 = F_34 ( V_2 , V_33 , F_51 ( V_33 ) ) ;
if ( V_24 )
return V_24 ;
}
return 0 ;
}
static int V_15 ( struct V_1 * V_2 )
{
int V_24 ;
T_5 V_37 ;
if ( ! V_2 -> V_15 || ! F_97 ( & V_2 -> V_9 ) )
return 0 ;
F_6 ( F_7 ( & V_2 -> V_7 ) ) ;
V_24 = F_41 ( V_2 , & V_37 , V_74 ) ;
if ( V_24 )
return V_24 ;
F_27 ( F_22 ( V_2 ) , L_22 , V_37 & 0xff ) ;
return F_43 ( V_2 , V_37 & 0xff , V_80 ) ;
}
int F_98 ( struct V_1 * V_2 , T_2 V_76 )
{
int V_24 , V_38 ;
F_37 ( & V_2 -> V_7 ) ;
V_24 = F_60 ( V_2 ) ;
if ( V_24 )
goto V_218;
V_24 = F_99 ( & V_2 -> V_9 , V_76 ) ;
if ( V_24 )
goto V_219;
V_24 = F_95 ( V_2 , V_76 ) ;
if ( V_24 )
goto V_219;
V_24 = V_15 ( V_2 ) ;
if ( V_24 )
goto V_219;
V_24 = V_17 ( V_2 , V_76 ) ;
if ( V_24 )
goto V_219;
V_24 = F_45 ( V_2 , 0 , V_313 ) ;
V_219:
V_38 = F_62 ( V_2 ) ;
if ( V_38 && ! V_24 )
V_24 = V_38 ;
V_218:
F_39 ( & V_2 -> V_7 ) ;
return V_24 ;
}
T_2 F_100 ( struct V_1 * V_2 )
{
T_2 V_76 ;
F_37 ( & V_2 -> V_7 ) ;
V_76 = V_2 -> V_9 . V_76 ;
F_39 ( & V_2 -> V_7 ) ;
return V_76 ;
}
int F_101 ( struct V_1 * V_2 , enum V_314 V_315 )
{
const T_3 V_20 [] = {
F_76 ( V_2 , V_280 ) ,
V_316 ,
} ;
int V_24 ;
T_4 V_60 [ F_51 ( V_20 ) ] ;
struct V_34 V_33 [ F_51 ( V_20 ) ] = {
[ 0 ] = { F_76 (chip, FW_REG_LED_LINK_STATUS) } ,
[ 1 ] = { V_316 } ,
} ;
T_4 V_317 ;
F_37 ( & V_2 -> V_7 ) ;
V_24 = F_26 ( V_2 , V_60 , ( const T_3 * ) V_20 , F_51 ( V_20 ) ) ;
if ( V_24 )
goto V_218;
V_317 = V_2 -> V_44 == V_45 ? V_46 : V_45 ;
switch ( V_315 ) {
case V_318 :
V_33 [ 0 ] . V_37 = V_319 ;
V_33 [ 1 ] . V_37 = V_60 [ 1 ] & ~ ( V_45 | V_46 ) ;
break;
case V_320 :
V_33 [ 0 ] . V_37 = V_319 ;
V_33 [ 1 ] . V_37 = V_60 [ 1 ] & ~ V_317 ;
if ( F_102 () % 3 == 0 ) {
V_33 [ 1 ] . V_37 &= ~ V_2 -> V_44 ;
} else {
V_33 [ 1 ] . V_37 |= V_2 -> V_44 ;
}
break;
case V_321 :
V_33 [ 0 ] . V_37 = V_322 ;
V_33 [ 1 ] . V_37 = V_60 [ 1 ] & ~ V_317 ;
V_33 [ 1 ] . V_37 |= V_2 -> V_44 ;
break;
default:
V_24 = - V_29 ;
goto V_218;
}
if ( V_60 [ 0 ] != V_33 [ 0 ] . V_37 || V_60 [ 1 ] != V_33 [ 1 ] . V_37 ) {
V_24 = F_34 ( V_2 , V_33 , F_51 ( V_33 ) ) ;
if ( V_24 )
goto V_218;
}
V_24 = 0 ;
V_218:
F_39 ( & V_2 -> V_7 ) ;
return V_24 ;
}
int F_103 ( struct V_1 * V_2 , T_4 V_323 )
{
int V_24 ;
if ( V_323 & ~ ( V_324 | V_325 ) )
return - V_29 ;
F_37 ( & V_2 -> V_7 ) ;
V_24 = F_45 ( V_2 , V_323 , V_326 ) ;
F_39 ( & V_2 -> V_7 ) ;
return V_24 ;
}
static inline T_2 F_104 ( const void * V_327 )
{
return V_328 | F_105 ( V_327 ) ;
}
T_2 F_106 ( const void * V_327 , const struct V_329 * V_315 )
{
T_2 V_330 ;
if ( V_315 -> V_331 & V_332 ) {
V_330 = F_104 ( V_327 ) ;
} else {
switch ( F_107 ( V_327 ) ) {
case V_333 :
V_330 = V_334 ;
break;
case V_335 :
V_330 = V_336 ;
break;
case V_337 :
V_330 = V_338 ;
break;
case V_339 :
V_330 = V_297 ;
break;
default:
V_330 = 0 ;
}
}
return V_330 ;
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
F_116 ( & F_14 ( V_2 ) -> V_340 ) ;
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
const T_5 * V_22 , unsigned int V_23 , T_2 V_341 )
{
int V_24 ;
unsigned int V_13 ;
for ( V_13 = 0 ; V_13 < V_23 ; V_13 ++ ) {
V_24 = F_126 ( V_2 , V_22 [ V_13 ] , V_341 ) ;
if ( V_24 )
return V_24 ;
}
return 0 ;
}
int F_127 ( struct V_1 * V_2 , T_5 V_37 )
{
const struct V_34 V_33 [] = {
{ V_342 , ( V_37 >> 16 ) & 0xff } ,
{ V_343 , ( V_37 >> 8 ) & 0xff } ,
{ V_344 , V_37 & 0xff } ,
} ;
F_6 ( F_7 ( & V_2 -> V_7 ) ) ;
return F_34 ( V_2 , V_33 , F_51 ( V_33 ) ) ;
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
struct V_345 * V_346 )
{
const struct V_32 V_33 [] = {
{ V_238 , V_346 -> V_347 } ,
{ V_239 , V_346 -> V_348 } ,
} ;
return F_47 ( V_2 , V_33 , F_51 ( V_33 ) ) ;
}
T_6 F_130 ( struct V_1 * V_2 )
{
int V_24 ;
static const T_3 V_255 [] =
{ V_349 , V_350 } ;
T_5 V_22 [ 2 ] ;
T_6 V_351 ;
F_37 ( & V_2 -> V_7 ) ;
V_24 = F_24 ( V_2 , V_22 , ( const T_3 * ) V_255 ,
F_51 ( V_255 ) ) ;
F_39 ( & V_2 -> V_7 ) ;
if ( V_24 )
return 0 ;
V_351 = V_22 [ 1 ] ;
V_351 = ( V_351 << 32 ) | V_22 [ 0 ] ;
return V_351 ;
}
