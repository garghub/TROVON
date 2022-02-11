static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static struct V_1 * F_3 ( struct V_5 * V_6 )
{
return F_1 ( F_4 ( V_6 ) ) ;
}
static struct V_7 * F_5 ( struct V_5 * V_6 )
{
return F_2 ( F_6 ( V_6 ) , struct V_7 , V_4 ) ;
}
static void F_7 ( struct V_1 * V_1 , T_1 V_8 )
{
struct V_9 * V_10 = V_1 -> V_4 . V_4 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
T_1 V_14 = V_8 , V_15 = V_8 ;
int V_16 ;
if ( V_1 -> V_17 == V_18 ) {
F_8 ( V_1 -> V_17 , V_8 ) ;
F_9 ( V_1 -> V_17 ) ;
return;
}
if ( V_1 -> V_17 == V_19 )
V_15 = F_9 ( V_20 ) ;
else
V_14 = F_9 ( V_19 ) ;
for ( V_16 = 0 ; V_16 < 2 ; V_16 ++ )
{
F_8 ( V_19 , V_14 ) ;
F_9 ( V_19 ) ;
F_8 ( V_20 , V_15 ) ;
F_9 ( V_20 ) ;
}
}
static bool F_10 ( struct V_1 * V_1 , T_2 V_21 , T_2 * V_22 )
{
struct V_23 V_24 [] = {
{
. V_21 = V_1 -> V_25 ,
. V_26 = 0 ,
. V_27 = 1 ,
. V_28 = & V_21 ,
} ,
{
. V_21 = V_1 -> V_25 ,
. V_26 = V_29 ,
. V_27 = 1 ,
. V_28 = V_22 ,
}
} ;
int V_30 ;
if ( ( V_30 = F_11 ( V_1 -> V_31 , V_24 , 2 ) ) == 2 )
return true ;
F_12 ( L_1 , V_30 ) ;
return false ;
}
static void F_13 ( struct V_1 * V_1 , T_2 V_32 ,
const void * args , int V_33 )
{
int V_16 ;
F_12 ( L_2 ,
F_14 ( V_1 ) , V_32 ) ;
for ( V_16 = 0 ; V_16 < V_33 ; V_16 ++ )
F_15 ( L_3 , ( ( T_2 * ) args ) [ V_16 ] ) ;
for (; V_16 < 8 ; V_16 ++ )
F_15 ( L_4 ) ;
for ( V_16 = 0 ; V_16 < F_16 ( V_34 ) ; V_16 ++ ) {
if ( V_32 == V_34 [ V_16 ] . V_32 ) {
F_15 ( L_5 , V_34 [ V_16 ] . V_35 ) ;
break;
}
}
if ( V_16 == F_16 ( V_34 ) )
F_15 ( L_6 , V_32 ) ;
F_15 ( L_7 ) ;
}
static bool F_17 ( struct V_1 * V_1 , T_2 V_32 ,
const void * args , int V_33 )
{
T_2 * V_28 , V_36 ;
struct V_23 * V_24 ;
int V_16 , V_30 = true ;
V_28 = F_18 ( V_33 * 2 + 2 , V_37 ) ;
if ( ! V_28 )
return false ;
V_24 = F_19 ( V_33 + 3 , sizeof( * V_24 ) , V_37 ) ;
if ( ! V_24 ) {
F_20 ( V_28 ) ;
return false ;
}
F_13 ( V_1 , V_32 , args , V_33 ) ;
for ( V_16 = 0 ; V_16 < V_33 ; V_16 ++ ) {
V_24 [ V_16 ] . V_21 = V_1 -> V_25 ;
V_24 [ V_16 ] . V_26 = 0 ;
V_24 [ V_16 ] . V_27 = 2 ;
V_24 [ V_16 ] . V_28 = V_28 + 2 * V_16 ;
V_28 [ 2 * V_16 + 0 ] = V_38 - V_16 ;
V_28 [ 2 * V_16 + 1 ] = ( ( T_2 * ) args ) [ V_16 ] ;
}
V_24 [ V_16 ] . V_21 = V_1 -> V_25 ;
V_24 [ V_16 ] . V_26 = 0 ;
V_24 [ V_16 ] . V_27 = 2 ;
V_24 [ V_16 ] . V_28 = V_28 + 2 * V_16 ;
V_28 [ 2 * V_16 + 0 ] = V_39 ;
V_28 [ 2 * V_16 + 1 ] = V_32 ;
V_36 = V_40 ;
V_24 [ V_16 + 1 ] . V_21 = V_1 -> V_25 ;
V_24 [ V_16 + 1 ] . V_26 = 0 ;
V_24 [ V_16 + 1 ] . V_27 = 1 ;
V_24 [ V_16 + 1 ] . V_28 = & V_36 ;
V_24 [ V_16 + 2 ] . V_21 = V_1 -> V_25 ;
V_24 [ V_16 + 2 ] . V_26 = V_29 ;
V_24 [ V_16 + 2 ] . V_27 = 1 ;
V_24 [ V_16 + 2 ] . V_28 = & V_36 ;
V_30 = F_11 ( V_1 -> V_31 , V_24 , V_16 + 3 ) ;
if ( V_30 < 0 ) {
F_12 ( L_8 , V_30 ) ;
V_30 = false ;
goto V_41;
}
if ( V_30 != V_16 + 3 ) {
F_12 ( L_9 , V_30 , V_16 + 3 ) ;
V_30 = false ;
}
V_41:
F_20 ( V_24 ) ;
F_20 ( V_28 ) ;
return V_30 ;
}
static bool F_21 ( struct V_1 * V_1 ,
void * V_42 , int V_43 )
{
T_2 V_44 = 15 ;
T_2 V_36 ;
int V_16 ;
F_12 ( L_10 , F_14 ( V_1 ) ) ;
if ( ! F_10 ( V_1 ,
V_40 ,
& V_36 ) )
goto V_45;
while ( ( V_36 == V_46 ||
V_36 == V_47 ) && -- V_44 ) {
if ( V_44 < 10 )
F_22 ( 15 ) ;
else
F_23 ( 15 ) ;
if ( ! F_10 ( V_1 ,
V_40 ,
& V_36 ) )
goto V_45;
}
if ( V_36 <= V_48 )
F_15 ( L_5 , V_49 [ V_36 ] ) ;
else
F_15 ( L_11 , V_36 ) ;
if ( V_36 != V_50 )
goto V_45;
for ( V_16 = 0 ; V_16 < V_43 ; V_16 ++ ) {
if ( ! F_10 ( V_1 ,
V_51 + V_16 ,
& ( ( T_2 * ) V_42 ) [ V_16 ] ) )
goto V_45;
F_15 ( L_12 , ( ( T_2 * ) V_42 ) [ V_16 ] ) ;
}
F_15 ( L_7 ) ;
return true ;
V_45:
F_15 ( L_13 ) ;
return false ;
}
static int F_24 ( struct V_52 * V_53 )
{
if ( V_53 -> clock >= 100000 )
return 1 ;
else if ( V_53 -> clock >= 50000 )
return 2 ;
else
return 4 ;
}
static bool F_25 ( struct V_1 * V_1 ,
T_2 V_54 )
{
return F_17 ( V_1 ,
V_55 ,
& V_54 , 1 ) ;
}
static bool F_26 ( struct V_1 * V_1 , T_2 V_32 , const void * V_56 , int V_27 )
{
if ( ! F_17 ( V_1 , V_32 , V_56 , V_27 ) )
return false ;
return F_21 ( V_1 , NULL , 0 ) ;
}
static bool
F_27 ( struct V_1 * V_1 , T_2 V_32 , void * V_57 , int V_27 )
{
if ( ! F_17 ( V_1 , V_32 , NULL , 0 ) )
return false ;
return F_21 ( V_1 , V_57 , V_27 ) ;
}
static bool F_28 ( struct V_1 * V_1 )
{
struct V_58 V_59 = { 0 } ;
return F_26 ( V_1 ,
V_60 ,
& V_59 , sizeof( V_59 ) ) ;
}
static bool F_29 ( struct V_1 * V_1 , bool * V_61 , bool * V_62 )
{
struct V_63 V_42 ;
F_30 ( sizeof( V_42 ) != 1 ) ;
if ( ! F_27 ( V_1 , V_64 ,
& V_42 , sizeof( V_42 ) ) )
return false ;
* V_61 = V_42 . V_65 ;
* V_62 = V_42 . V_66 ;
return true ;
}
static bool F_31 ( struct V_1 * V_1 ,
T_3 V_67 )
{
return F_26 ( V_1 ,
V_68 ,
& V_67 , sizeof( V_67 ) ) ;
}
static bool F_32 ( struct V_1 * V_1 ,
T_3 * V_67 )
{
return F_27 ( V_1 ,
V_69 ,
V_67 , sizeof( * V_67 ) ) ;
}
static bool F_33 ( struct V_1 * V_1 ,
int V_53 )
{
T_2 V_70 = V_71 ;
switch ( V_53 ) {
case V_72 :
V_70 = V_71 ;
break;
case V_73 :
V_70 = V_74 ;
break;
case V_75 :
V_70 = V_76 ;
break;
case V_77 :
V_70 = V_78 ;
break;
}
return F_26 ( V_1 ,
V_79 , & V_70 , sizeof( V_70 ) ) ;
}
static bool F_34 ( struct V_1 * V_1 ,
int * V_80 ,
int * V_81 )
{
struct V_82 V_83 ;
F_30 ( sizeof( V_83 ) != 4 ) ;
if ( ! F_27 ( V_1 ,
V_84 ,
& V_83 , sizeof( V_83 ) ) )
return false ;
* V_80 = V_83 . V_85 * 10 ;
* V_81 = V_83 . V_86 * 10 ;
return true ;
}
static bool F_35 ( struct V_1 * V_1 ,
T_3 V_67 )
{
return F_26 ( V_1 ,
V_87 ,
& V_67 , sizeof( V_67 ) ) ;
}
static bool F_36 ( struct V_1 * V_1 , T_2 V_32 ,
struct V_88 * V_89 )
{
return F_26 ( V_1 , V_32 , & V_89 -> V_90 , sizeof( V_89 -> V_90 ) ) &&
F_26 ( V_1 , V_32 + 1 , & V_89 -> V_91 , sizeof( V_89 -> V_91 ) ) ;
}
static bool F_37 ( struct V_1 * V_1 , T_2 V_32 ,
struct V_88 * V_89 )
{
return F_27 ( V_1 , V_32 , & V_89 -> V_90 , sizeof( V_89 -> V_90 ) ) &&
F_27 ( V_1 , V_32 + 1 , & V_89 -> V_91 , sizeof( V_89 -> V_91 ) ) ;
}
static bool F_38 ( struct V_1 * V_1 ,
struct V_88 * V_89 )
{
return F_36 ( V_1 ,
V_92 , V_89 ) ;
}
static bool F_39 ( struct V_1 * V_1 ,
struct V_88 * V_89 )
{
return F_36 ( V_1 ,
V_93 , V_89 ) ;
}
static bool F_40 ( struct V_1 * V_1 ,
struct V_88 * V_89 )
{
return F_37 ( V_1 ,
V_94 , V_89 ) ;
}
static bool
F_41 ( struct V_1 * V_1 ,
T_4 clock ,
T_4 V_95 ,
T_4 V_96 )
{
struct V_97 args ;
memset ( & args , 0 , sizeof( args ) ) ;
args . clock = clock ;
args . V_95 = V_95 ;
args . V_96 = V_96 ;
args . V_98 = 0 ;
if ( V_1 -> V_99 &&
( V_1 -> V_100 -> V_101 != V_95 ||
V_1 -> V_100 -> V_102 != V_96 ) )
args . V_103 = 1 ;
return F_26 ( V_1 ,
V_104 ,
& args , sizeof( args ) ) ;
}
static bool F_42 ( struct V_1 * V_1 ,
struct V_88 * V_89 )
{
F_30 ( sizeof( V_89 -> V_90 ) != 8 ) ;
F_30 ( sizeof( V_89 -> V_91 ) != 8 ) ;
return F_27 ( V_1 , V_105 ,
& V_89 -> V_90 , sizeof( V_89 -> V_90 ) ) &&
F_27 ( V_1 , V_106 ,
& V_89 -> V_91 , sizeof( V_89 -> V_91 ) ) ;
}
static bool F_43 ( struct V_1 * V_1 , T_2 V_8 )
{
return F_26 ( V_1 , V_107 , & V_8 , 1 ) ;
}
static void F_44 ( struct V_88 * V_89 ,
const struct V_52 * V_53 )
{
T_4 V_95 , V_96 ;
T_4 V_108 , V_109 , V_110 , V_111 ;
T_4 V_112 , V_113 ;
int V_114 ;
memset ( V_89 , 0 , sizeof( * V_89 ) ) ;
V_95 = V_53 -> V_101 ;
V_96 = V_53 -> V_102 ;
V_108 = V_53 -> V_115 - V_53 -> V_101 ;
V_109 = V_53 -> V_116 - V_53 -> V_117 ;
V_110 = V_53 -> V_118 - V_53 -> V_102 ;
V_111 = V_53 -> V_119 - V_53 -> V_120 ;
V_112 = V_53 -> V_117 - V_53 -> V_101 ;
V_113 = V_53 -> V_120 - V_53 -> V_102 ;
V_114 = V_53 -> clock ;
V_114 /= 10 ;
V_89 -> V_90 . clock = V_114 ;
V_89 -> V_90 . V_121 = V_95 & 0xff ;
V_89 -> V_90 . V_122 = V_108 & 0xff ;
V_89 -> V_90 . V_123 = ( ( ( V_95 >> 8 ) & 0xf ) << 4 ) |
( ( V_108 >> 8 ) & 0xf ) ;
V_89 -> V_90 . V_124 = V_96 & 0xff ;
V_89 -> V_90 . V_125 = V_110 & 0xff ;
V_89 -> V_90 . V_126 = ( ( ( V_96 >> 8 ) & 0xf ) << 4 ) |
( ( V_110 >> 8 ) & 0xf ) ;
V_89 -> V_91 . V_127 = V_112 & 0xff ;
V_89 -> V_91 . V_128 = V_109 & 0xff ;
V_89 -> V_91 . V_129 = ( V_113 & 0xf ) << 4 |
( V_111 & 0xf ) ;
V_89 -> V_91 . V_130 = ( ( V_112 & 0x300 ) >> 2 ) |
( ( V_109 & 0x300 ) >> 4 ) | ( ( V_113 & 0x30 ) >> 2 ) |
( ( V_111 & 0x30 ) >> 4 ) ;
V_89 -> V_91 . V_131 = 0x18 ;
if ( V_53 -> V_26 & V_132 )
V_89 -> V_91 . V_131 |= V_133 ;
if ( V_53 -> V_26 & V_134 )
V_89 -> V_91 . V_131 |= V_135 ;
if ( V_53 -> V_26 & V_136 )
V_89 -> V_91 . V_131 |= V_137 ;
V_89 -> V_91 . V_138 = V_113 & 0xc0 ;
}
static void F_45 ( struct V_52 * V_139 ,
const struct V_88 * V_89 )
{
struct V_52 V_53 = {} ;
V_53 . V_101 = V_89 -> V_90 . V_121 ;
V_53 . V_101 += ( ( V_89 -> V_90 . V_123 >> 4 ) & 0x0f ) << 8 ;
V_53 . V_117 = V_53 . V_101 + V_89 -> V_91 . V_127 ;
V_53 . V_117 += ( V_89 -> V_91 . V_130 & 0xc0 ) << 2 ;
V_53 . V_116 = V_53 . V_117 + V_89 -> V_91 . V_128 ;
V_53 . V_116 += ( V_89 -> V_91 . V_130 & 0x30 ) << 4 ;
V_53 . V_115 = V_53 . V_101 + V_89 -> V_90 . V_122 ;
V_53 . V_115 += ( V_89 -> V_90 . V_123 & 0xf ) << 8 ;
V_53 . V_102 = V_89 -> V_90 . V_124 ;
V_53 . V_102 += ( ( V_89 -> V_90 . V_126 >> 4 ) & 0x0f ) << 8 ;
V_53 . V_120 = V_53 . V_102 ;
V_53 . V_120 += ( V_89 -> V_91 . V_129 >> 4 ) & 0xf ;
V_53 . V_120 += ( V_89 -> V_91 . V_130 & 0x0c ) << 2 ;
V_53 . V_120 += V_89 -> V_91 . V_138 & 0xc0 ;
V_53 . V_119 = V_53 . V_120 +
( V_89 -> V_91 . V_129 & 0xf ) ;
V_53 . V_119 += ( V_89 -> V_91 . V_130 & 0x3 ) << 4 ;
V_53 . V_118 = V_53 . V_102 + V_89 -> V_90 . V_125 ;
V_53 . V_118 += ( V_89 -> V_90 . V_126 & 0xf ) << 8 ;
V_53 . clock = V_89 -> V_90 . clock * 10 ;
if ( V_89 -> V_91 . V_131 & V_133 )
V_53 . V_26 |= V_132 ;
if ( V_89 -> V_91 . V_131 & V_135 )
V_53 . V_26 |= V_134 ;
else
V_53 . V_26 |= V_140 ;
if ( V_89 -> V_91 . V_131 & V_137 )
V_53 . V_26 |= V_136 ;
else
V_53 . V_26 |= V_141 ;
F_46 ( & V_53 , 0 ) ;
F_47 ( V_139 , & V_53 ) ;
}
static bool F_48 ( struct V_1 * V_1 )
{
struct V_142 V_143 ;
F_30 ( sizeof( V_143 ) != 2 ) ;
return F_27 ( V_1 ,
V_144 ,
& V_143 , sizeof( V_143 ) ) ;
}
static bool F_49 ( struct V_1 * V_1 ,
T_5 V_53 )
{
return F_26 ( V_1 , V_145 , & V_53 , 1 ) ;
}
static bool F_50 ( struct V_1 * V_1 ,
T_5 V_53 )
{
return F_26 ( V_1 , V_146 , & V_53 , 1 ) ;
}
static bool F_51 ( struct V_1 * V_1 ,
unsigned V_147 , T_5 V_148 ,
T_5 * V_56 , unsigned V_149 )
{
T_5 V_150 [ 2 ] = { V_147 , 0 } ;
T_5 V_151 , V_152 [ 8 ] ;
int V_16 ;
if ( ! F_26 ( V_1 ,
V_153 ,
V_150 , 2 ) )
return false ;
if ( ! F_27 ( V_1 , V_154 ,
& V_151 , 1 ) )
return false ;
V_151 ++ ;
F_12 ( L_14 ,
V_147 , V_149 , V_151 ) ;
for ( V_16 = 0 ; V_16 < V_151 ; V_16 += 8 ) {
memset ( V_152 , 0 , 8 ) ;
if ( V_16 < V_149 )
memcpy ( V_152 , V_56 + V_16 , F_52 ( unsigned , 8 , V_149 - V_16 ) ) ;
if ( ! F_26 ( V_1 ,
V_155 ,
V_152 , 8 ) )
return false ;
}
return F_26 ( V_1 ,
V_156 ,
& V_148 , 1 ) ;
}
static bool F_53 ( struct V_1 * V_1 ,
const struct V_52 * V_157 )
{
T_5 V_158 [ F_54 ( V_159 ) ] ;
struct V_160 * V_161 = V_1 -> V_4 . V_4 . V_161 ;
struct V_162 * V_162 = F_55 ( V_161 ) ;
union V_163 V_164 ;
int V_30 ;
T_6 V_27 ;
V_30 = F_56 ( & V_164 . V_165 ,
V_157 ) ;
if ( V_30 < 0 ) {
F_57 ( L_15 ) ;
return false ;
}
if ( V_1 -> V_166 ) {
if ( V_162 -> V_167 . V_168 )
V_164 . V_165 . V_169 =
V_170 ;
else
V_164 . V_165 . V_169 =
V_171 ;
}
V_27 = F_58 ( & V_164 , V_158 , sizeof( V_158 ) ) ;
if ( V_27 < 0 )
return false ;
return F_51 ( V_1 , V_172 ,
V_173 ,
V_158 , sizeof( V_158 ) ) ;
}
static bool F_59 ( struct V_1 * V_1 )
{
struct V_174 V_175 ;
T_7 V_176 ;
V_176 = 1 << V_1 -> V_177 ;
memset ( & V_175 , 0 , sizeof( V_175 ) ) ;
memcpy ( & V_175 , & V_176 , V_85 ( sizeof( V_175 ) , sizeof( V_176 ) ) ) ;
F_30 ( sizeof( V_175 ) != 6 ) ;
return F_26 ( V_1 ,
V_178 ,
& V_175 , sizeof( V_175 ) ) ;
}
static bool
F_60 ( struct V_1 * V_1 ,
const struct V_52 * V_53 )
{
struct V_88 V_179 ;
if ( ! F_35 ( V_1 ,
V_1 -> V_180 ) )
return false ;
F_44 ( & V_179 , V_53 ) ;
if ( ! F_39 ( V_1 , & V_179 ) )
return false ;
return true ;
}
static bool
F_61 ( struct V_1 * V_1 ,
const struct V_52 * V_53 ,
struct V_52 * V_157 )
{
struct V_88 V_181 ;
if ( ! F_28 ( V_1 ) )
return false ;
if ( ! F_41 ( V_1 ,
V_53 -> clock / 10 ,
V_53 -> V_101 ,
V_53 -> V_102 ) )
return false ;
if ( ! F_42 ( V_1 ,
& V_181 ) )
return false ;
F_45 ( V_157 , & V_181 ) ;
V_1 -> V_182 = V_181 . V_91 . V_183 ;
return true ;
}
static void F_62 ( struct V_184 * V_185 )
{
unsigned V_186 = V_185 -> V_187 ;
struct V_188 * clock = & V_185 -> V_188 ;
if ( V_186 >= 100000 && V_186 < 140500 ) {
clock -> V_189 = 2 ;
clock -> V_190 = 10 ;
clock -> V_191 = 3 ;
clock -> V_192 = 16 ;
clock -> V_193 = 8 ;
} else if ( V_186 >= 140500 && V_186 <= 200000 ) {
clock -> V_189 = 1 ;
clock -> V_190 = 10 ;
clock -> V_191 = 6 ;
clock -> V_192 = 12 ;
clock -> V_193 = 8 ;
} else {
F_63 ( 1 , L_16 , V_186 ) ;
}
V_185 -> V_194 = true ;
}
static bool F_64 ( struct V_2 * V_3 ,
struct V_184 * V_185 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_52 * V_157 = & V_185 -> V_157 ;
struct V_52 * V_53 = & V_185 -> V_195 ;
F_12 ( L_17 ) ;
V_185 -> V_196 = 8 * 3 ;
if ( F_65 ( V_3 -> V_4 . V_10 ) )
V_185 -> V_197 = true ;
if ( V_1 -> V_198 ) {
if ( ! F_60 ( V_1 , V_53 ) )
return false ;
( void ) F_61 ( V_1 ,
V_53 ,
V_157 ) ;
V_185 -> V_199 = true ;
} else if ( V_1 -> V_99 ) {
if ( ! F_60 ( V_1 ,
V_1 -> V_100 ) )
return false ;
( void ) F_61 ( V_1 ,
V_53 ,
V_157 ) ;
}
V_185 -> V_200 =
F_24 ( V_157 ) ;
if ( V_1 -> V_201 ) {
if ( V_1 -> V_202 &&
F_66 ( V_157 ) > 1 )
V_1 -> V_203 = V_204 ;
else
V_1 -> V_203 = 0 ;
}
if ( V_1 -> V_203 )
V_185 -> V_168 = true ;
if ( V_1 -> V_198 )
F_62 ( V_185 ) ;
return true ;
}
static void F_67 ( struct V_2 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_4 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_162 * V_161 = F_55 ( V_2 -> V_4 . V_161 ) ;
struct V_52 * V_157 =
& V_161 -> V_167 . V_157 ;
struct V_52 * V_53 = & V_161 -> V_167 . V_195 ;
struct V_1 * V_1 = F_1 ( V_2 ) ;
T_1 V_205 ;
struct V_206 V_207 ;
struct V_88 V_181 , V_179 ;
int V_208 ;
if ( ! V_53 )
return;
V_207 . V_209 = V_1 -> V_180 ;
V_207 . V_210 = 0 ;
F_26 ( V_1 ,
V_211 ,
& V_207 , sizeof( V_207 ) ) ;
if ( ! F_35 ( V_1 ,
V_1 -> V_180 ) )
return;
if ( V_1 -> V_99 )
F_44 ( & V_179 ,
V_1 -> V_100 ) ;
else
F_44 ( & V_179 , V_53 ) ;
if ( ! F_39 ( V_1 , & V_179 ) )
F_68 ( L_18 ,
F_14 ( V_1 ) ) ;
if ( ! F_28 ( V_1 ) )
return;
if ( V_1 -> V_202 ) {
F_49 ( V_1 , V_212 ) ;
F_50 ( V_1 ,
V_213 ) ;
F_53 ( V_1 , V_157 ) ;
} else
F_49 ( V_1 , V_214 ) ;
if ( V_1 -> V_198 &&
! F_59 ( V_1 ) )
return;
F_44 ( & V_181 , V_157 ) ;
if ( V_1 -> V_198 || V_1 -> V_99 )
V_181 . V_91 . V_183 = V_1 -> V_182 ;
if ( ! F_38 ( V_1 , & V_181 ) )
F_68 ( L_19 ,
F_14 ( V_1 ) ) ;
switch ( V_161 -> V_167 . V_200 ) {
default:
F_63 ( 1 , L_20 ) ;
case 1 : V_208 = V_215 ; break;
case 2 : V_208 = V_216 ; break;
case 4 : V_208 = V_217 ; break;
}
if ( ! F_43 ( V_1 , V_208 ) )
return;
if ( F_69 ( V_10 ) -> V_218 >= 4 ) {
V_205 = V_219 | V_220 ;
if ( ! F_65 ( V_10 ) && V_1 -> V_221 )
V_205 |= V_1 -> V_203 ;
if ( F_69 ( V_10 ) -> V_218 < 5 )
V_205 |= V_222 ;
} else {
V_205 = F_9 ( V_1 -> V_17 ) ;
switch ( V_1 -> V_17 ) {
case V_19 :
V_205 &= V_223 ;
break;
case V_20 :
V_205 &= V_224 ;
break;
}
V_205 |= ( 9 << 19 ) | V_222 ;
}
if ( F_70 ( V_10 ) >= V_225 )
V_205 |= F_71 ( V_161 -> V_226 ) ;
else
V_205 |= F_72 ( V_161 -> V_226 ) ;
if ( V_1 -> V_227 )
V_205 |= V_228 ;
if ( F_69 ( V_10 ) -> V_218 >= 4 ) {
} else if ( F_73 ( V_10 ) || F_74 ( V_10 ) || F_75 ( V_10 ) ) {
} else {
V_205 |= ( V_161 -> V_167 . V_200 - 1 )
<< V_229 ;
}
if ( V_181 . V_91 . V_183 & V_230 &&
F_69 ( V_10 ) -> V_218 < 5 )
V_205 |= V_231 ;
F_7 ( V_1 , V_205 ) ;
}
static bool F_76 ( struct V_232 * V_6 )
{
struct V_7 * V_7 =
F_5 ( & V_6 -> V_4 ) ;
struct V_1 * V_1 = F_3 ( & V_6 -> V_4 ) ;
T_3 V_233 = 0 ;
F_32 ( V_1 , & V_233 ) ;
if ( V_233 & V_7 -> V_234 )
return true ;
else
return false ;
}
static bool F_77 ( struct V_2 * V_3 ,
enum V_226 * V_226 )
{
struct V_9 * V_10 = V_3 -> V_4 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
T_3 V_233 = 0 ;
T_1 V_152 ;
V_152 = F_9 ( V_1 -> V_17 ) ;
F_32 ( V_1 , & V_233 ) ;
if ( ! ( V_152 & V_235 ) && ( V_233 == 0 ) )
return false ;
if ( F_78 ( V_10 ) )
* V_226 = F_79 ( V_152 ) ;
else
* V_226 = F_80 ( V_152 ) ;
return true ;
}
static void F_81 ( struct V_2 * V_3 ,
struct V_184 * V_185 )
{
struct V_9 * V_10 = V_3 -> V_4 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_88 V_89 ;
int V_236 = 0 ;
int V_186 ;
T_1 V_26 = 0 , V_205 ;
T_2 V_8 ;
bool V_30 ;
V_30 = F_40 ( V_1 , & V_89 ) ;
if ( ! V_30 ) {
F_82 ( L_21 ) ;
V_185 -> V_237 |= V_238 ;
} else {
if ( V_89 . V_91 . V_131 & V_135 )
V_26 |= V_134 ;
else
V_26 |= V_140 ;
if ( V_89 . V_91 . V_131 & V_137 )
V_26 |= V_136 ;
else
V_26 |= V_141 ;
}
V_185 -> V_157 . V_26 |= V_26 ;
if ( F_83 ( V_10 ) || F_84 ( V_10 ) ) {
V_205 = F_9 ( V_1 -> V_17 ) ;
V_185 -> V_200 =
( ( V_205 & V_239 )
>> V_229 ) + 1 ;
}
V_186 = V_185 -> V_187 / V_185 -> V_200 ;
if ( F_65 ( V_10 ) )
F_85 ( V_185 , V_186 ) ;
V_185 -> V_157 . V_240 = V_186 ;
if ( F_27 ( V_1 , V_241 ,
& V_8 , 1 ) ) {
switch ( V_8 ) {
case V_215 :
V_236 = 1 ;
break;
case V_216 :
V_236 = 2 ;
break;
case V_217 :
V_236 = 4 ;
break;
}
}
F_63 ( V_236 != V_185 -> V_200 ,
L_22 ,
V_185 -> V_200 , V_236 ) ;
}
static void F_86 ( struct V_2 * V_3 )
{
struct V_11 * V_12 = V_3 -> V_4 . V_10 -> V_13 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
T_1 V_242 ;
F_31 ( V_1 , 0 ) ;
if ( 0 )
F_33 ( V_1 ,
V_77 ) ;
V_242 = F_9 ( V_1 -> V_17 ) ;
if ( ( V_242 & V_235 ) != 0 ) {
if ( F_87 ( V_3 -> V_4 . V_10 ) ) {
struct V_160 * V_161 = V_3 -> V_4 . V_161 ;
int V_226 = V_161 ? F_55 ( V_161 ) -> V_226 : - 1 ;
if ( V_242 & V_243 ) {
V_242 &= ~ V_243 ;
F_8 ( V_1 -> V_17 , V_242 ) ;
F_88 ( V_1 -> V_17 ) ;
F_8 ( V_1 -> V_17 , V_242 ) ;
F_88 ( V_1 -> V_17 ) ;
if ( V_161 )
F_89 ( V_3 -> V_4 . V_10 , V_226 ) ;
else
F_22 ( 50 ) ;
}
}
F_7 ( V_1 , V_242 & ~ V_235 ) ;
}
}
static void F_90 ( struct V_2 * V_3 )
{
struct V_9 * V_10 = V_3 -> V_4 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_162 * V_162 = F_55 ( V_3 -> V_4 . V_161 ) ;
T_1 V_242 ;
bool V_244 , V_245 ;
int V_16 ;
T_2 V_36 ;
V_242 = F_9 ( V_1 -> V_17 ) ;
if ( ( V_242 & V_235 ) == 0 ) {
if ( F_87 ( V_10 ) )
V_242 |= F_72 ( V_162 -> V_226 ) ;
F_7 ( V_1 , V_242 | V_235 ) ;
}
for ( V_16 = 0 ; V_16 < 2 ; V_16 ++ )
F_89 ( V_10 , V_162 -> V_226 ) ;
V_36 = F_29 ( V_1 , & V_244 , & V_245 ) ;
if ( V_36 == V_50 && ! V_244 ) {
F_12 ( L_23
L_24 , F_14 ( V_1 ) ) ;
}
if ( 0 )
F_33 ( V_1 ,
V_72 ) ;
F_31 ( V_1 , V_1 -> V_180 ) ;
}
static void F_91 ( struct V_5 * V_6 , int V_53 )
{
struct V_160 * V_161 ;
struct V_1 * V_1 = F_3 ( V_6 ) ;
if ( V_53 != V_72 )
V_53 = V_77 ;
if ( V_53 == V_6 -> V_246 )
return;
V_6 -> V_246 = V_53 ;
V_161 = V_1 -> V_4 . V_4 . V_161 ;
if ( ! V_161 ) {
V_1 -> V_4 . V_247 = false ;
return;
}
if ( V_53 != V_72 ) {
F_31 ( V_1 , 0 ) ;
if ( 0 )
F_33 ( V_1 , V_53 ) ;
V_1 -> V_4 . V_247 = false ;
F_92 ( V_161 ) ;
} else {
V_1 -> V_4 . V_247 = true ;
F_92 ( V_161 ) ;
if ( 0 )
F_33 ( V_1 , V_53 ) ;
F_31 ( V_1 , V_1 -> V_180 ) ;
}
F_93 ( V_6 -> V_10 ) ;
}
static int F_94 ( struct V_5 * V_6 ,
struct V_52 * V_53 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
if ( V_53 -> V_26 & V_248 )
return V_249 ;
if ( V_1 -> V_250 > V_53 -> clock )
return V_251 ;
if ( V_1 -> V_252 < V_53 -> clock )
return V_253 ;
if ( V_1 -> V_99 ) {
if ( V_53 -> V_101 > V_1 -> V_100 -> V_101 )
return V_254 ;
if ( V_53 -> V_102 > V_1 -> V_100 -> V_102 )
return V_254 ;
}
return V_255 ;
}
static bool F_95 ( struct V_1 * V_1 , struct V_256 * V_257 )
{
F_30 ( sizeof( * V_257 ) != 8 ) ;
if ( ! F_27 ( V_1 ,
V_258 ,
V_257 , sizeof( * V_257 ) ) )
return false ;
F_12 ( L_25
L_26
L_27
L_28
L_29
L_30
L_31
L_32
L_33
L_34
L_35
L_36
L_37 ,
V_257 -> V_259 ,
V_257 -> V_260 ,
V_257 -> V_261 ,
V_257 -> V_262 ,
V_257 -> V_263 ,
V_257 -> V_264 ,
V_257 -> V_265 ,
V_257 -> V_266 ,
V_257 -> V_267 ,
V_257 -> V_268 ,
V_257 -> V_269 ,
V_257 -> V_270 ) ;
return true ;
}
static T_4 F_96 ( struct V_1 * V_1 )
{
struct V_9 * V_10 = V_1 -> V_4 . V_4 . V_10 ;
T_4 V_271 ;
if ( F_73 ( V_10 ) || F_74 ( V_10 ) )
return 0 ;
if ( ! F_27 ( V_1 , V_272 ,
& V_271 , sizeof( V_271 ) ) )
return 0 ;
return V_271 ;
}
static void F_97 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
F_17 ( V_1 , V_273 ,
& V_1 -> V_274 , 2 ) ;
}
static bool
F_98 ( struct V_1 * V_1 )
{
return F_99 ( V_1 -> V_257 . V_270 ) > 1 ;
}
static struct V_275 *
F_100 ( struct V_5 * V_6 )
{
struct V_1 * V_276 = F_3 ( V_6 ) ;
return F_101 ( V_6 , & V_276 -> V_277 ) ;
}
static struct V_275 *
F_102 ( struct V_5 * V_6 )
{
struct V_11 * V_12 = V_6 -> V_10 -> V_13 ;
return F_101 ( V_6 ,
F_103 ( V_12 ,
V_12 -> V_278 . V_279 ) ) ;
}
static enum V_280
F_104 ( struct V_5 * V_6 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
enum V_280 V_36 ;
struct V_275 * V_275 ;
V_275 = F_100 ( V_6 ) ;
if ( V_275 == NULL && F_98 ( V_1 ) ) {
T_2 V_277 , V_281 = V_1 -> V_54 ;
for ( V_277 = V_1 -> V_54 >> 1 ; V_277 > 1 ; V_277 >>= 1 ) {
V_1 -> V_54 = V_277 ;
V_275 = F_100 ( V_6 ) ;
if ( V_275 )
break;
}
if ( V_275 == NULL )
V_1 -> V_54 = V_281 ;
}
if ( V_275 == NULL )
V_275 = F_102 ( V_6 ) ;
V_36 = V_282 ;
if ( V_275 != NULL ) {
if ( V_275 -> V_283 & V_284 ) {
V_36 = V_285 ;
if ( V_1 -> V_221 ) {
V_1 -> V_202 = F_105 ( V_275 ) ;
V_1 -> V_227 = F_106 ( V_275 ) ;
V_1 -> V_166 =
F_107 ( V_275 ) ;
}
} else
V_36 = V_286 ;
F_20 ( V_275 ) ;
}
if ( V_36 == V_285 ) {
struct V_7 * V_7 = F_5 ( V_6 ) ;
if ( V_7 -> V_287 != V_288 )
V_1 -> V_227 = ( V_7 -> V_287 == V_289 ) ;
}
return V_36 ;
}
static bool
F_108 ( struct V_7 * V_276 ,
struct V_275 * V_275 )
{
bool V_290 = ! ! ( V_275 -> V_283 & V_284 ) ;
bool V_291 = ! ! F_109 ( V_276 ) ;
F_12 ( L_38 ,
V_291 , V_290 ) ;
return V_291 == V_290 ;
}
static enum V_280
F_110 ( struct V_5 * V_6 , bool V_292 )
{
T_4 V_42 ;
struct V_1 * V_1 = F_3 ( V_6 ) ;
struct V_7 * V_7 = F_5 ( V_6 ) ;
enum V_280 V_30 ;
F_12 ( L_39 ,
V_6 -> V_4 . V_293 , F_111 ( V_6 ) ) ;
if ( ! F_27 ( V_1 ,
V_294 ,
& V_42 , 2 ) )
return V_282 ;
F_12 ( L_40 ,
V_42 & 0xff , V_42 >> 8 ,
V_7 -> V_234 ) ;
if ( V_42 == 0 )
return V_286 ;
V_1 -> V_180 = V_42 ;
V_1 -> V_202 = false ;
V_1 -> V_227 = false ;
V_1 -> V_166 = false ;
if ( ( V_7 -> V_234 & V_42 ) == 0 )
V_30 = V_286 ;
else if ( F_112 ( V_7 ) )
V_30 = F_104 ( V_6 ) ;
else {
struct V_275 * V_275 ;
V_275 = F_100 ( V_6 ) ;
if ( V_275 == NULL )
V_275 = F_102 ( V_6 ) ;
if ( V_275 != NULL ) {
if ( F_108 ( V_7 ,
V_275 ) )
V_30 = V_285 ;
else
V_30 = V_286 ;
F_20 ( V_275 ) ;
} else
V_30 = V_285 ;
}
if ( V_30 == V_285 ) {
V_1 -> V_198 = false ;
V_1 -> V_99 = false ;
if ( V_42 & V_295 )
V_1 -> V_198 = true ;
if ( V_42 & V_296 )
V_1 -> V_99 = V_1 -> V_100 != NULL ;
}
return V_30 ;
}
static void F_113 ( struct V_5 * V_6 )
{
struct V_275 * V_275 ;
F_12 ( L_39 ,
V_6 -> V_4 . V_293 , F_111 ( V_6 ) ) ;
V_275 = F_100 ( V_6 ) ;
if ( V_275 == NULL )
V_275 = F_102 ( V_6 ) ;
if ( V_275 != NULL ) {
if ( F_108 ( F_5 ( V_6 ) ,
V_275 ) ) {
F_114 ( V_6 , V_275 ) ;
F_115 ( V_6 , V_275 ) ;
}
F_20 ( V_275 ) ;
}
}
static void F_116 ( struct V_5 * V_6 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
struct V_297 V_298 ;
T_7 V_299 = 0 , V_176 = 0 ;
int V_16 ;
F_12 ( L_39 ,
V_6 -> V_4 . V_293 , F_111 ( V_6 ) ) ;
V_176 = 1 << V_1 -> V_177 ;
memcpy ( & V_298 , & V_176 ,
V_85 ( sizeof( V_176 ) , sizeof( struct V_297 ) ) ) ;
if ( ! F_35 ( V_1 , V_1 -> V_180 ) )
return;
F_30 ( sizeof( V_298 ) != 3 ) ;
if ( ! F_17 ( V_1 ,
V_300 ,
& V_298 , sizeof( V_298 ) ) )
return;
if ( ! F_21 ( V_1 , & V_299 , 3 ) )
return;
for ( V_16 = 0 ; V_16 < F_16 ( V_301 ) ; V_16 ++ )
if ( V_299 & ( 1 << V_16 ) ) {
struct V_52 * V_302 ;
V_302 = F_117 ( V_6 -> V_10 ,
& V_301 [ V_16 ] ) ;
if ( V_302 )
F_118 ( V_6 , V_302 ) ;
}
}
static void F_119 ( struct V_5 * V_6 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
struct V_11 * V_12 = V_6 -> V_10 -> V_13 ;
struct V_52 * V_303 ;
F_12 ( L_39 ,
V_6 -> V_4 . V_293 , F_111 ( V_6 ) ) ;
if ( V_12 -> V_278 . V_304 != NULL ) {
V_303 = F_117 ( V_6 -> V_10 ,
V_12 -> V_278 . V_304 ) ;
if ( V_303 != NULL ) {
V_303 -> type = ( V_305 |
V_306 ) ;
F_118 ( V_6 , V_303 ) ;
}
}
F_120 ( V_6 , & V_1 -> V_277 ) ;
F_121 (newmode, &connector->probed_modes, head) {
if ( V_303 -> type & V_305 ) {
V_1 -> V_100 =
F_117 ( V_6 -> V_10 , V_303 ) ;
V_1 -> V_99 = true ;
break;
}
}
}
static int F_122 ( struct V_5 * V_6 )
{
struct V_7 * V_7 = F_5 ( V_6 ) ;
if ( F_123 ( V_7 ) )
F_116 ( V_6 ) ;
else if ( F_124 ( V_7 ) )
F_119 ( V_6 ) ;
else
F_113 ( V_6 ) ;
return ! F_125 ( & V_6 -> V_307 ) ;
}
static void
F_126 ( struct V_5 * V_6 )
{
struct V_7 * V_7 = F_5 ( V_6 ) ;
struct V_9 * V_10 = V_6 -> V_10 ;
if ( V_7 -> V_308 )
F_127 ( V_10 , V_7 -> V_308 ) ;
if ( V_7 -> V_309 )
F_127 ( V_10 , V_7 -> V_309 ) ;
if ( V_7 -> V_310 )
F_127 ( V_10 , V_7 -> V_310 ) ;
if ( V_7 -> V_311 )
F_127 ( V_10 , V_7 -> V_311 ) ;
if ( V_7 -> V_312 )
F_127 ( V_10 , V_7 -> V_312 ) ;
if ( V_7 -> V_313 )
F_127 ( V_10 , V_7 -> V_313 ) ;
if ( V_7 -> V_314 )
F_127 ( V_10 , V_7 -> V_314 ) ;
if ( V_7 -> V_315 )
F_127 ( V_10 , V_7 -> V_315 ) ;
if ( V_7 -> V_316 )
F_127 ( V_10 , V_7 -> V_316 ) ;
if ( V_7 -> V_317 )
F_127 ( V_10 , V_7 -> V_317 ) ;
if ( V_7 -> V_318 )
F_127 ( V_10 , V_7 -> V_318 ) ;
if ( V_7 -> V_319 )
F_127 ( V_10 , V_7 -> V_319 ) ;
if ( V_7 -> V_320 )
F_127 ( V_10 , V_7 -> V_320 ) ;
if ( V_7 -> V_321 )
F_127 ( V_10 , V_7 -> V_321 ) ;
if ( V_7 -> V_322 )
F_127 ( V_10 , V_7 -> V_322 ) ;
if ( V_7 -> V_323 )
F_127 ( V_10 , V_7 -> V_323 ) ;
if ( V_7 -> V_324 )
F_127 ( V_10 , V_7 -> V_324 ) ;
}
static void F_128 ( struct V_5 * V_6 )
{
struct V_7 * V_7 = F_5 ( V_6 ) ;
if ( V_7 -> V_325 )
F_127 ( V_6 -> V_10 ,
V_7 -> V_325 ) ;
F_126 ( V_6 ) ;
F_129 ( V_6 ) ;
F_20 ( V_7 ) ;
}
static bool F_130 ( struct V_5 * V_6 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
struct V_275 * V_275 ;
bool V_326 = false ;
if ( ! V_1 -> V_221 )
return false ;
V_275 = F_100 ( V_6 ) ;
if ( V_275 != NULL && V_275 -> V_283 & V_284 )
V_326 = F_106 ( V_275 ) ;
F_20 ( V_275 ) ;
return V_326 ;
}
static int
F_131 ( struct V_5 * V_6 ,
struct V_327 * V_328 ,
T_8 V_8 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
struct V_7 * V_7 = F_5 ( V_6 ) ;
struct V_11 * V_12 = V_6 -> V_10 -> V_13 ;
T_4 V_329 ;
T_5 V_32 ;
int V_30 ;
V_30 = F_132 ( & V_6 -> V_4 , V_328 , V_8 ) ;
if ( V_30 )
return V_30 ;
if ( V_328 == V_12 -> V_330 ) {
int V_16 = V_8 ;
bool V_326 ;
if ( V_16 == V_7 -> V_287 )
return 0 ;
V_7 -> V_287 = V_16 ;
if ( V_16 == V_288 )
V_326 = F_130 ( V_6 ) ;
else
V_326 = ( V_16 == V_289 ) ;
if ( V_326 == V_1 -> V_227 )
return 0 ;
V_1 -> V_227 = V_326 ;
goto V_331;
}
if ( V_328 == V_12 -> V_332 ) {
bool V_333 = V_1 -> V_201 ;
T_7 V_334 = V_1 -> V_203 ;
switch ( V_8 ) {
case V_335 :
V_1 -> V_201 = true ;
break;
case V_336 :
V_1 -> V_201 = false ;
V_1 -> V_203 = 0 ;
break;
case V_337 :
V_1 -> V_201 = false ;
V_1 -> V_203 = V_204 ;
break;
default:
return - V_338 ;
}
if ( V_333 == V_1 -> V_201 &&
V_334 == V_1 -> V_203 )
return 0 ;
goto V_331;
}
#define F_133 ( V_35 , T_9 ) \
if (intel_sdvo_connector->name == property) { \
if (intel_sdvo_connector->cur_##name == temp_value) return 0; \
if (intel_sdvo_connector->max_##name < temp_value) return -EINVAL; \
cmd = SDVO_CMD_SET_##NAME; \
intel_sdvo_connector->cur_##name = temp_value; \
goto set_value; \
}
if ( V_328 == V_7 -> V_325 ) {
if ( V_8 >= V_339 )
return - V_338 ;
if ( V_1 -> V_177 ==
V_7 -> V_340 [ V_8 ] )
return 0 ;
V_1 -> V_177 = V_7 -> V_340 [ V_8 ] ;
goto V_331;
} else if ( F_134 ( V_7 ) ) {
V_329 = V_8 ;
if ( V_7 -> V_308 == V_328 ) {
F_132 ( & V_6 -> V_4 ,
V_7 -> V_309 , V_8 ) ;
if ( V_7 -> V_341 == V_329 )
return 0 ;
V_7 -> V_341 = V_329 ;
V_7 -> V_342 = V_329 ;
V_329 = V_7 -> V_343 -
V_7 -> V_341 ;
V_32 = V_344 ;
goto V_345;
} else if ( V_7 -> V_309 == V_328 ) {
F_132 ( & V_6 -> V_4 ,
V_7 -> V_308 , V_8 ) ;
if ( V_7 -> V_342 == V_329 )
return 0 ;
V_7 -> V_341 = V_329 ;
V_7 -> V_342 = V_329 ;
V_329 = V_7 -> V_343 -
V_7 -> V_341 ;
V_32 = V_344 ;
goto V_345;
} else if ( V_7 -> V_310 == V_328 ) {
F_132 ( & V_6 -> V_4 ,
V_7 -> V_311 , V_8 ) ;
if ( V_7 -> V_346 == V_329 )
return 0 ;
V_7 -> V_346 = V_329 ;
V_7 -> V_347 = V_329 ;
V_329 = V_7 -> V_348 -
V_7 -> V_346 ;
V_32 = V_349 ;
goto V_345;
} else if ( V_7 -> V_311 == V_328 ) {
F_132 ( & V_6 -> V_4 ,
V_7 -> V_310 , V_8 ) ;
if ( V_7 -> V_347 == V_329 )
return 0 ;
V_7 -> V_346 = V_329 ;
V_7 -> V_347 = V_329 ;
V_329 = V_7 -> V_348 -
V_7 -> V_346 ;
V_32 = V_349 ;
goto V_345;
}
F_133 (hpos, HPOS)
F_133 (vpos, VPOS)
F_133 (saturation, SATURATION)
F_133 (contrast, CONTRAST)
F_133 (hue, HUE)
F_133 (brightness, BRIGHTNESS)
F_133 (sharpness, SHARPNESS)
F_133 (flicker_filter, FLICKER_FILTER)
F_133 (flicker_filter_2d, FLICKER_FILTER_2D)
F_133 (flicker_filter_adaptive, FLICKER_FILTER_ADAPTIVE)
F_133 (tv_chroma_filter, TV_CHROMA_FILTER)
F_133 (tv_luma_filter, TV_LUMA_FILTER)
F_133 (dot_crawl, DOT_CRAWL)
}
return - V_338 ;
V_345:
if ( ! F_26 ( V_1 , V_32 , & V_329 , 2 ) )
return - V_350 ;
V_331:
if ( V_1 -> V_4 . V_4 . V_161 )
F_135 ( V_1 -> V_4 . V_4 . V_161 ) ;
return 0 ;
#undef F_133
}
static void F_136 ( struct V_351 * V_3 )
{
struct V_1 * V_1 = F_1 ( F_137 ( V_3 ) ) ;
if ( V_1 -> V_100 != NULL )
F_138 ( V_3 -> V_10 ,
V_1 -> V_100 ) ;
F_139 ( & V_1 -> V_277 ) ;
F_140 ( V_3 ) ;
}
static void
F_141 ( struct V_1 * V_276 )
{
T_4 V_352 = 0 ;
unsigned int V_353 ;
switch ( V_276 -> V_354 ) {
case V_355 :
V_352 |= V_355 ;
case V_356 :
V_352 |= V_356 ;
case V_357 :
V_352 |= V_357 ;
case V_358 :
V_352 |= V_358 ;
case V_359 :
V_352 |= V_359 ;
case V_360 :
V_352 |= V_360 ;
break;
}
V_352 &= V_276 -> V_257 . V_270 ;
V_353 = F_99 ( V_352 ) ;
if ( V_353 > 3 )
V_353 = 3 ;
V_276 -> V_54 = 1 << V_353 ;
}
static void
F_142 ( struct V_11 * V_12 ,
struct V_1 * V_276 , T_1 V_361 )
{
struct V_362 * V_363 ;
if ( V_276 -> V_364 )
V_363 = & ( V_12 -> V_365 [ 0 ] ) ;
else
V_363 = & ( V_12 -> V_365 [ 1 ] ) ;
if ( V_363 -> V_366 )
V_276 -> V_54 = 1 << ( ( V_363 -> V_367 & 0xf0 ) >> 4 ) ;
else
F_141 ( V_276 ) ;
}
static void
F_143 ( struct V_11 * V_12 ,
struct V_1 * V_276 , T_1 V_361 )
{
struct V_362 * V_363 ;
T_2 V_368 ;
if ( V_276 -> V_364 )
V_363 = & V_12 -> V_365 [ 0 ] ;
else
V_363 = & V_12 -> V_365 [ 1 ] ;
if ( V_363 -> V_366 && F_144 ( V_363 -> V_369 ) )
V_368 = V_363 -> V_369 ;
else
V_368 = V_370 ;
V_276 -> V_31 = F_103 ( V_12 , V_368 ) ;
F_145 ( V_276 -> V_31 , true ) ;
}
static void
F_146 ( struct V_1 * V_276 )
{
F_145 ( V_276 -> V_31 , false ) ;
}
static bool
F_147 ( struct V_1 * V_1 , int V_371 )
{
return F_48 ( V_1 ) ;
}
static T_2
F_148 ( struct V_9 * V_10 , struct V_1 * V_276 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_362 * V_372 , * V_373 ;
if ( V_276 -> V_364 ) {
V_372 = & V_12 -> V_365 [ 0 ] ;
V_373 = & V_12 -> V_365 [ 1 ] ;
} else {
V_372 = & V_12 -> V_365 [ 1 ] ;
V_373 = & V_12 -> V_365 [ 0 ] ;
}
if ( V_372 -> V_25 )
return V_372 -> V_25 ;
if ( V_373 -> V_25 ) {
if ( V_373 -> V_25 == 0x70 )
return 0x72 ;
else
return 0x70 ;
}
if ( V_276 -> V_364 )
return 0x70 ;
else
return 0x72 ;
}
static void
F_149 ( struct V_7 * V_6 ,
struct V_1 * V_3 )
{
F_150 ( V_3 -> V_4 . V_4 . V_10 ,
& V_6 -> V_4 . V_4 ,
& V_374 ,
V_6 -> V_4 . V_4 . V_375 ) ;
F_151 ( & V_6 -> V_4 . V_4 ,
& V_376 ) ;
V_6 -> V_4 . V_4 . V_377 = 1 ;
V_6 -> V_4 . V_4 . V_378 = 0 ;
V_6 -> V_4 . V_4 . V_379 . V_380 = V_381 ;
V_6 -> V_4 . V_382 = F_76 ;
F_152 ( & V_6 -> V_4 , & V_3 -> V_4 ) ;
F_153 ( & V_6 -> V_4 . V_4 ) ;
}
static void
F_154 ( struct V_1 * V_1 ,
struct V_7 * V_6 )
{
struct V_9 * V_10 = V_6 -> V_4 . V_4 . V_10 ;
F_155 ( & V_6 -> V_4 . V_4 ) ;
if ( F_69 ( V_10 ) -> V_218 >= 4 && F_156 ( V_10 ) ) {
F_157 ( & V_6 -> V_4 . V_4 ) ;
V_1 -> V_201 = true ;
}
}
static bool
F_158 ( struct V_1 * V_1 , int V_371 )
{
struct V_351 * V_3 = & V_1 -> V_4 . V_4 ;
struct V_5 * V_6 ;
struct V_2 * V_2 = F_137 ( V_3 ) ;
struct V_232 * V_232 ;
struct V_7 * V_7 ;
F_12 ( L_41 , V_371 ) ;
V_7 = F_18 ( sizeof( * V_7 ) , V_37 ) ;
if ( ! V_7 )
return false ;
if ( V_371 == 0 ) {
V_1 -> V_354 |= V_358 ;
V_7 -> V_234 = V_358 ;
} else if ( V_371 == 1 ) {
V_1 -> V_354 |= V_357 ;
V_7 -> V_234 = V_357 ;
}
V_232 = & V_7 -> V_4 ;
V_6 = & V_232 -> V_4 ;
if ( F_96 ( V_1 ) &
V_7 -> V_234 ) {
V_1 -> V_274 |= V_7 -> V_234 ;
V_2 -> V_383 = F_97 ;
F_97 ( V_2 ) ;
} else {
V_232 -> V_384 = V_385 | V_386 ;
}
V_3 -> V_387 = V_388 ;
V_6 -> V_375 = V_389 ;
if ( F_147 ( V_1 , V_371 ) ) {
V_6 -> V_375 = V_390 ;
V_1 -> V_221 = true ;
}
F_149 ( V_7 , V_1 ) ;
if ( V_1 -> V_221 )
F_154 ( V_1 , V_7 ) ;
return true ;
}
static bool
F_159 ( struct V_1 * V_1 , int type )
{
struct V_351 * V_3 = & V_1 -> V_4 . V_4 ;
struct V_5 * V_6 ;
struct V_232 * V_232 ;
struct V_7 * V_7 ;
F_12 ( L_42 , type ) ;
V_7 = F_18 ( sizeof( * V_7 ) , V_37 ) ;
if ( ! V_7 )
return false ;
V_232 = & V_7 -> V_4 ;
V_6 = & V_232 -> V_4 ;
V_3 -> V_387 = V_391 ;
V_6 -> V_375 = V_392 ;
V_1 -> V_354 |= type ;
V_7 -> V_234 = type ;
V_1 -> V_198 = true ;
F_149 ( V_7 , V_1 ) ;
if ( ! F_160 ( V_1 , V_7 , type ) )
goto V_393;
if ( ! F_161 ( V_1 , V_7 ) )
goto V_393;
return true ;
V_393:
F_162 ( V_6 ) ;
F_128 ( V_6 ) ;
return false ;
}
static bool
F_163 ( struct V_1 * V_1 , int V_371 )
{
struct V_351 * V_3 = & V_1 -> V_4 . V_4 ;
struct V_5 * V_6 ;
struct V_232 * V_232 ;
struct V_7 * V_7 ;
F_12 ( L_43 , V_371 ) ;
V_7 = F_18 ( sizeof( * V_7 ) , V_37 ) ;
if ( ! V_7 )
return false ;
V_232 = & V_7 -> V_4 ;
V_6 = & V_232 -> V_4 ;
V_232 -> V_384 = V_385 ;
V_3 -> V_387 = V_394 ;
V_6 -> V_375 = V_395 ;
if ( V_371 == 0 ) {
V_1 -> V_354 |= V_360 ;
V_7 -> V_234 = V_360 ;
} else if ( V_371 == 1 ) {
V_1 -> V_354 |= V_359 ;
V_7 -> V_234 = V_359 ;
}
F_149 ( V_7 ,
V_1 ) ;
return true ;
}
static bool
F_164 ( struct V_1 * V_1 , int V_371 )
{
struct V_351 * V_3 = & V_1 -> V_4 . V_4 ;
struct V_5 * V_6 ;
struct V_232 * V_232 ;
struct V_7 * V_7 ;
F_12 ( L_44 , V_371 ) ;
V_7 = F_18 ( sizeof( * V_7 ) , V_37 ) ;
if ( ! V_7 )
return false ;
V_232 = & V_7 -> V_4 ;
V_6 = & V_232 -> V_4 ;
V_3 -> V_387 = V_396 ;
V_6 -> V_375 = V_397 ;
if ( V_371 == 0 ) {
V_1 -> V_354 |= V_356 ;
V_7 -> V_234 = V_356 ;
} else if ( V_371 == 1 ) {
V_1 -> V_354 |= V_355 ;
V_7 -> V_234 = V_355 ;
}
F_149 ( V_7 , V_1 ) ;
if ( ! F_161 ( V_1 , V_7 ) )
goto V_393;
return true ;
V_393:
F_162 ( V_6 ) ;
F_128 ( V_6 ) ;
return false ;
}
static bool
F_165 ( struct V_1 * V_1 , T_4 V_26 )
{
V_1 -> V_198 = false ;
V_1 -> V_99 = false ;
if ( V_26 & V_358 )
if ( ! F_158 ( V_1 , 0 ) )
return false ;
if ( ( V_26 & V_398 ) == V_398 )
if ( ! F_158 ( V_1 , 1 ) )
return false ;
if ( V_26 & V_399 )
if ( ! F_159 ( V_1 , V_399 ) )
return false ;
if ( V_26 & V_400 )
if ( ! F_159 ( V_1 , V_400 ) )
return false ;
if ( V_26 & V_401 )
if ( ! F_159 ( V_1 , V_401 ) )
return false ;
if ( V_26 & V_360 )
if ( ! F_163 ( V_1 , 0 ) )
return false ;
if ( ( V_26 & V_402 ) == V_402 )
if ( ! F_163 ( V_1 , 1 ) )
return false ;
if ( V_26 & V_356 )
if ( ! F_164 ( V_1 , 0 ) )
return false ;
if ( ( V_26 & V_296 ) == V_296 )
if ( ! F_164 ( V_1 , 1 ) )
return false ;
if ( ( V_26 & V_403 ) == 0 ) {
unsigned char V_404 [ 2 ] ;
V_1 -> V_354 = 0 ;
memcpy ( V_404 , & V_1 -> V_257 . V_270 , 2 ) ;
F_12 ( L_45 ,
F_14 ( V_1 ) ,
V_404 [ 0 ] , V_404 [ 1 ] ) ;
return false ;
}
V_1 -> V_4 . V_405 = ( 1 << 0 ) | ( 1 << 1 ) | ( 1 << 2 ) ;
return true ;
}
static void F_166 ( struct V_1 * V_1 )
{
struct V_9 * V_10 = V_1 -> V_4 . V_4 . V_10 ;
struct V_5 * V_6 , * V_152 ;
F_167 (connector, tmp,
&dev->mode_config.connector_list, head) {
if ( F_4 ( V_6 ) == & V_1 -> V_4 ) {
F_162 ( V_6 ) ;
F_128 ( V_6 ) ;
}
}
}
static bool F_160 ( struct V_1 * V_1 ,
struct V_7 * V_7 ,
int type )
{
struct V_9 * V_10 = V_1 -> V_4 . V_4 . V_10 ;
struct V_174 V_175 ;
T_7 V_176 , V_16 ;
if ( ! F_35 ( V_1 , type ) )
return false ;
F_30 ( sizeof( V_175 ) != 6 ) ;
if ( ! F_27 ( V_1 ,
V_406 ,
& V_175 , sizeof( V_175 ) ) )
return false ;
memcpy ( & V_176 , & V_175 , V_85 ( sizeof( V_176 ) , sizeof( V_175 ) ) ) ;
if ( V_176 == 0 )
return false ;
V_7 -> V_407 = 0 ;
for ( V_16 = 0 ; V_16 < V_339 ; V_16 ++ )
if ( V_176 & ( 1 << V_16 ) )
V_7 -> V_340 [ V_7 -> V_407 ++ ] = V_16 ;
V_7 -> V_325 =
F_168 ( V_10 , V_408 ,
L_46 , V_7 -> V_407 ) ;
if ( ! V_7 -> V_325 )
return false ;
for ( V_16 = 0 ; V_16 < V_7 -> V_407 ; V_16 ++ )
F_169 (
V_7 -> V_325 , V_16 ,
V_16 , V_409 [ V_7 -> V_340 [ V_16 ] ] ) ;
V_1 -> V_177 = V_7 -> V_340 [ 0 ] ;
F_170 ( & V_7 -> V_4 . V_4 . V_4 ,
V_7 -> V_325 , 0 ) ;
return true ;
}
static bool
F_171 ( struct V_1 * V_1 ,
struct V_7 * V_7 ,
struct V_410 V_411 )
{
struct V_9 * V_10 = V_1 -> V_4 . V_4 . V_10 ;
struct V_5 * V_6 = & V_7 -> V_4 . V_4 ;
T_4 V_42 , V_412 [ 2 ] ;
if ( V_411 . V_413 ) {
if ( ! F_27 ( V_1 ,
V_414 ,
& V_412 , 4 ) )
return false ;
if ( ! F_27 ( V_1 ,
V_415 ,
& V_42 , 2 ) )
return false ;
V_7 -> V_343 = V_412 [ 0 ] ;
V_7 -> V_341 = V_412 [ 0 ] - V_42 ;
V_7 -> V_342 = V_7 -> V_341 ;
V_7 -> V_308 =
F_172 ( V_10 , 0 , L_47 , 0 , V_412 [ 0 ] ) ;
if ( ! V_7 -> V_308 )
return false ;
F_170 ( & V_6 -> V_4 ,
V_7 -> V_308 ,
V_7 -> V_341 ) ;
V_7 -> V_309 =
F_172 ( V_10 , 0 , L_48 , 0 , V_412 [ 0 ] ) ;
if ( ! V_7 -> V_309 )
return false ;
F_170 ( & V_6 -> V_4 ,
V_7 -> V_309 ,
V_7 -> V_342 ) ;
F_12 ( L_49
L_50 ,
V_412 [ 0 ] , V_412 [ 1 ] , V_42 ) ;
}
if ( V_411 . V_416 ) {
if ( ! F_27 ( V_1 ,
V_417 ,
& V_412 , 4 ) )
return false ;
if ( ! F_27 ( V_1 ,
V_418 ,
& V_42 , 2 ) )
return false ;
V_7 -> V_348 = V_412 [ 0 ] ;
V_7 -> V_346 = V_412 [ 0 ] - V_42 ;
V_7 -> V_347 = V_7 -> V_346 ;
V_7 -> V_310 =
F_172 ( V_10 , 0 ,
L_51 , 0 , V_412 [ 0 ] ) ;
if ( ! V_7 -> V_310 )
return false ;
F_170 ( & V_6 -> V_4 ,
V_7 -> V_310 ,
V_7 -> V_346 ) ;
V_7 -> V_311 =
F_172 ( V_10 , 0 ,
L_52 , 0 , V_412 [ 0 ] ) ;
if ( ! V_7 -> V_311 )
return false ;
F_170 ( & V_6 -> V_4 ,
V_7 -> V_311 ,
V_7 -> V_347 ) ;
F_12 ( L_53
L_50 ,
V_412 [ 0 ] , V_412 [ 1 ] , V_42 ) ;
}
F_173 ( V_312 , V_419 ) ;
F_173 ( V_313 , V_420 ) ;
F_173 ( V_314 , V_421 ) ;
F_173 ( V_315 , V_422 ) ;
F_173 ( V_316 , V_423 ) ;
F_173 ( V_317 , V_424 ) ;
F_173 ( V_324 , V_425 ) ;
F_173 ( V_318 , V_426 ) ;
F_173 ( V_320 , V_427 ) ;
F_173 ( V_319 , V_428 ) ;
F_173 ( V_322 , V_429 ) ;
F_173 ( V_321 , V_430 ) ;
if ( V_411 . V_323 ) {
if ( ! F_27 ( V_1 , V_431 , & V_42 , 2 ) )
return false ;
V_7 -> V_432 = 1 ;
V_7 -> V_433 = V_42 & 0x1 ;
V_7 -> V_323 =
F_172 ( V_10 , 0 , L_54 , 0 , 1 ) ;
if ( ! V_7 -> V_323 )
return false ;
F_170 ( & V_6 -> V_4 ,
V_7 -> V_323 ,
V_7 -> V_433 ) ;
F_12 ( L_55 , V_42 ) ;
}
return true ;
}
static bool
F_174 ( struct V_1 * V_1 ,
struct V_7 * V_7 ,
struct V_410 V_411 )
{
struct V_9 * V_10 = V_1 -> V_4 . V_4 . V_10 ;
struct V_5 * V_6 = & V_7 -> V_4 . V_4 ;
T_4 V_42 , V_412 [ 2 ] ;
F_173 ( V_324 , V_425 ) ;
return true ;
}
static bool F_161 ( struct V_1 * V_1 ,
struct V_7 * V_7 )
{
union {
struct V_410 V_299 ;
T_4 V_42 ;
} V_411 ;
F_30 ( sizeof( V_411 ) != 2 ) ;
V_411 . V_42 = 0 ;
F_27 ( V_1 ,
V_434 ,
& V_411 , sizeof( V_411 ) ) ;
if ( V_411 . V_42 == 0 ) {
F_12 ( L_56 ) ;
return true ;
}
if ( F_123 ( V_7 ) )
return F_171 ( V_1 , V_7 , V_411 . V_299 ) ;
else if ( F_124 ( V_7 ) )
return F_174 ( V_1 , V_7 , V_411 . V_299 ) ;
else
return true ;
}
static int F_175 ( struct V_435 * V_436 ,
struct V_23 * V_24 ,
int V_437 )
{
struct V_1 * V_276 = V_436 -> V_438 ;
if ( ! F_25 ( V_276 , V_276 -> V_54 ) )
return - V_350 ;
return V_276 -> V_31 -> V_439 -> V_440 ( V_276 -> V_31 , V_24 , V_437 ) ;
}
static T_1 F_176 ( struct V_435 * V_436 )
{
struct V_1 * V_276 = V_436 -> V_438 ;
return V_276 -> V_31 -> V_439 -> V_441 ( V_276 -> V_31 ) ;
}
static bool
F_177 ( struct V_1 * V_276 ,
struct V_9 * V_10 )
{
V_276 -> V_277 . V_442 = V_443 ;
V_276 -> V_277 . V_444 = V_445 ;
snprintf ( V_276 -> V_277 . V_35 , V_446 , L_57 ) ;
V_276 -> V_277 . V_10 . V_447 = & V_10 -> V_448 -> V_10 ;
V_276 -> V_277 . V_438 = V_276 ;
V_276 -> V_277 . V_439 = & V_449 ;
return F_178 ( & V_276 -> V_277 ) == 0 ;
}
bool F_179 ( struct V_9 * V_10 , T_7 V_17 , bool V_364 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_2 * V_2 ;
struct V_1 * V_1 ;
int V_16 ;
V_1 = F_18 ( sizeof( * V_1 ) , V_37 ) ;
if ( ! V_1 )
return false ;
V_1 -> V_17 = V_17 ;
V_1 -> V_364 = V_364 ;
V_1 -> V_25 = F_148 ( V_10 , V_1 ) >> 1 ;
F_143 ( V_12 , V_1 , V_17 ) ;
if ( ! F_177 ( V_1 , V_10 ) )
goto V_450;
V_2 = & V_1 -> V_4 ;
V_2 -> type = V_451 ;
F_180 ( V_10 , & V_2 -> V_4 , & V_452 , 0 ) ;
for ( V_16 = 0 ; V_16 < 0x40 ; V_16 ++ ) {
T_2 V_453 ;
if ( ! F_10 ( V_1 , V_16 , & V_453 ) ) {
F_12 ( L_58 ,
F_14 ( V_1 ) ) ;
goto V_393;
}
}
V_2 -> V_454 = F_64 ;
V_2 -> V_455 = F_86 ;
V_2 -> V_456 = F_67 ;
V_2 -> V_457 = F_90 ;
V_2 -> V_382 = F_77 ;
V_2 -> V_458 = F_81 ;
if ( ! F_95 ( V_1 , & V_1 -> V_257 ) )
goto V_393;
if ( F_165 ( V_1 ,
V_1 -> V_257 . V_270 ) != true ) {
F_12 ( L_59 ,
F_14 ( V_1 ) ) ;
goto V_459;
}
if ( V_1 -> V_274 ) {
V_2 -> V_460 =
V_1 -> V_364 ? V_461 : V_462 ;
}
V_1 -> V_4 . V_463 = false ;
F_142 ( V_12 , V_1 , V_17 ) ;
if ( ! F_28 ( V_1 ) )
goto V_459;
if ( ! F_34 ( V_1 ,
& V_1 -> V_250 ,
& V_1 -> V_252 ) )
goto V_459;
F_12 ( L_60
L_61
L_62
L_63 ,
F_14 ( V_1 ) ,
V_1 -> V_257 . V_259 , V_1 -> V_257 . V_260 ,
V_1 -> V_257 . V_261 ,
V_1 -> V_250 / 1000 ,
V_1 -> V_252 / 1000 ,
( V_1 -> V_257 . V_264 & 0x1 ) ? 'Y' : 'N' ,
( V_1 -> V_257 . V_264 & 0x2 ) ? 'Y' : 'N' ,
V_1 -> V_257 . V_270 &
( V_358 | V_360 ) ? 'Y' : 'N' ,
V_1 -> V_257 . V_270 &
( V_357 | V_359 ) ? 'Y' : 'N' ) ;
return true ;
V_459:
F_166 ( V_1 ) ;
V_393:
F_181 ( & V_2 -> V_4 ) ;
F_139 ( & V_1 -> V_277 ) ;
V_450:
F_146 ( V_1 ) ;
F_20 ( V_1 ) ;
return false ;
}
