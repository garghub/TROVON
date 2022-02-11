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
unsigned V_186 = V_185 -> V_157 . clock ;
struct V_187 * clock = & V_185 -> V_187 ;
if ( V_186 >= 100000 && V_186 < 140500 ) {
clock -> V_188 = 2 ;
clock -> V_189 = 10 ;
clock -> V_190 = 3 ;
clock -> V_191 = 16 ;
clock -> V_192 = 8 ;
} else if ( V_186 >= 140500 && V_186 <= 200000 ) {
clock -> V_188 = 1 ;
clock -> V_189 = 10 ;
clock -> V_190 = 6 ;
clock -> V_191 = 12 ;
clock -> V_192 = 8 ;
} else {
F_63 ( 1 , L_16 , V_186 ) ;
}
V_185 -> V_193 = true ;
}
static bool F_64 ( struct V_2 * V_3 ,
struct V_184 * V_185 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_52 * V_157 = & V_185 -> V_157 ;
struct V_52 * V_53 = & V_185 -> V_194 ;
F_12 ( L_17 ) ;
V_185 -> V_195 = 8 * 3 ;
if ( F_65 ( V_3 -> V_4 . V_10 ) )
V_185 -> V_196 = true ;
if ( V_1 -> V_197 ) {
if ( ! F_60 ( V_1 , V_53 ) )
return false ;
( void ) F_61 ( V_1 ,
V_53 ,
V_157 ) ;
V_185 -> V_198 = true ;
} else if ( V_1 -> V_99 ) {
if ( ! F_60 ( V_1 ,
V_1 -> V_100 ) )
return false ;
( void ) F_61 ( V_1 ,
V_53 ,
V_157 ) ;
}
V_185 -> V_199 =
F_24 ( V_157 ) ;
V_157 -> clock *= V_185 -> V_199 ;
if ( V_1 -> V_200 ) {
if ( V_1 -> V_201 &&
F_66 ( V_157 ) > 1 )
V_1 -> V_202 = V_203 ;
else
V_1 -> V_202 = 0 ;
}
if ( V_1 -> V_202 )
V_185 -> V_168 = true ;
if ( V_1 -> V_197 )
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
struct V_52 * V_53 = & V_161 -> V_167 . V_194 ;
struct V_1 * V_1 = F_1 ( V_2 ) ;
T_1 V_204 ;
struct V_205 V_206 ;
struct V_88 V_181 , V_179 ;
int V_207 ;
if ( ! V_53 )
return;
V_206 . V_208 = V_1 -> V_180 ;
V_206 . V_209 = 0 ;
F_26 ( V_1 ,
V_210 ,
& V_206 , sizeof( V_206 ) ) ;
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
if ( V_1 -> V_201 ) {
F_49 ( V_1 , V_211 ) ;
F_50 ( V_1 ,
V_212 ) ;
F_53 ( V_1 , V_157 ) ;
} else
F_49 ( V_1 , V_213 ) ;
if ( V_1 -> V_197 &&
! F_59 ( V_1 ) )
return;
F_44 ( & V_181 , V_157 ) ;
V_181 . V_90 . clock /= V_161 -> V_167 . V_199 ;
if ( V_1 -> V_197 || V_1 -> V_99 )
V_181 . V_91 . V_183 = V_1 -> V_182 ;
if ( ! F_38 ( V_1 , & V_181 ) )
F_68 ( L_19 ,
F_14 ( V_1 ) ) ;
switch ( V_161 -> V_167 . V_199 ) {
default:
F_63 ( 1 , L_20 ) ;
case 1 : V_207 = V_214 ; break;
case 2 : V_207 = V_215 ; break;
case 4 : V_207 = V_216 ; break;
}
if ( ! F_43 ( V_1 , V_207 ) )
return;
if ( F_69 ( V_10 ) -> V_217 >= 4 ) {
V_204 = V_218 | V_219 ;
if ( ! F_65 ( V_10 ) && V_1 -> V_220 )
V_204 |= V_1 -> V_202 ;
if ( F_69 ( V_10 ) -> V_217 < 5 )
V_204 |= V_221 ;
} else {
V_204 = F_9 ( V_1 -> V_17 ) ;
switch ( V_1 -> V_17 ) {
case V_19 :
V_204 &= V_222 ;
break;
case V_20 :
V_204 &= V_223 ;
break;
}
V_204 |= ( 9 << 19 ) | V_221 ;
}
if ( F_70 ( V_10 ) >= V_224 )
V_204 |= F_71 ( V_161 -> V_225 ) ;
else
V_204 |= F_72 ( V_161 -> V_225 ) ;
if ( V_1 -> V_226 )
V_204 |= V_227 ;
if ( F_69 ( V_10 ) -> V_217 >= 4 ) {
} else if ( F_73 ( V_10 ) || F_74 ( V_10 ) || F_75 ( V_10 ) ) {
} else {
V_204 |= ( V_161 -> V_167 . V_199 - 1 )
<< V_228 ;
}
if ( V_181 . V_91 . V_183 & V_229 &&
F_69 ( V_10 ) -> V_217 < 5 )
V_204 |= V_230 ;
F_7 ( V_1 , V_204 ) ;
}
static bool F_76 ( struct V_231 * V_6 )
{
struct V_7 * V_7 =
F_5 ( & V_6 -> V_4 ) ;
struct V_1 * V_1 = F_3 ( & V_6 -> V_4 ) ;
T_3 V_232 = 0 ;
F_32 ( V_1 , & V_232 ) ;
if ( V_232 & V_7 -> V_233 )
return true ;
else
return false ;
}
static bool F_77 ( struct V_2 * V_3 ,
enum V_225 * V_225 )
{
struct V_9 * V_10 = V_3 -> V_4 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
T_3 V_232 = 0 ;
T_1 V_152 ;
V_152 = F_9 ( V_1 -> V_17 ) ;
F_32 ( V_1 , & V_232 ) ;
if ( ! ( V_152 & V_234 ) && ( V_232 == 0 ) )
return false ;
if ( F_78 ( V_10 ) )
* V_225 = F_79 ( V_152 ) ;
else
* V_225 = F_80 ( V_152 ) ;
return true ;
}
static void F_81 ( struct V_2 * V_3 ,
struct V_184 * V_185 )
{
struct V_9 * V_10 = V_3 -> V_4 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_88 V_89 ;
int V_235 = 0 ;
T_1 V_26 = 0 , V_204 ;
T_2 V_8 ;
bool V_30 ;
V_30 = F_40 ( V_1 , & V_89 ) ;
if ( ! V_30 ) {
F_82 ( L_21 ) ;
V_185 -> V_236 |= V_237 ;
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
V_204 = F_9 ( V_1 -> V_17 ) ;
V_185 -> V_199 =
( ( V_204 & V_238 )
>> V_228 ) + 1 ;
}
if ( F_27 ( V_1 , V_239 ,
& V_8 , 1 ) ) {
switch ( V_8 ) {
case V_214 :
V_235 = 1 ;
break;
case V_215 :
V_235 = 2 ;
break;
case V_216 :
V_235 = 4 ;
break;
}
}
F_63 ( V_235 != V_185 -> V_199 ,
L_22 ,
V_185 -> V_199 , V_235 ) ;
}
static void F_85 ( struct V_2 * V_3 )
{
struct V_11 * V_12 = V_3 -> V_4 . V_10 -> V_13 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
T_1 V_240 ;
F_31 ( V_1 , 0 ) ;
if ( 0 )
F_33 ( V_1 ,
V_77 ) ;
V_240 = F_9 ( V_1 -> V_17 ) ;
if ( ( V_240 & V_234 ) != 0 ) {
if ( F_86 ( V_3 -> V_4 . V_10 ) ) {
struct V_160 * V_161 = V_3 -> V_4 . V_161 ;
int V_225 = V_161 ? F_55 ( V_161 ) -> V_225 : - 1 ;
if ( V_240 & V_241 ) {
V_240 &= ~ V_241 ;
F_8 ( V_1 -> V_17 , V_240 ) ;
F_87 ( V_1 -> V_17 ) ;
F_8 ( V_1 -> V_17 , V_240 ) ;
F_87 ( V_1 -> V_17 ) ;
if ( V_161 )
F_88 ( V_3 -> V_4 . V_10 , V_225 ) ;
else
F_22 ( 50 ) ;
}
}
F_7 ( V_1 , V_240 & ~ V_234 ) ;
}
}
static void F_89 ( struct V_2 * V_3 )
{
struct V_9 * V_10 = V_3 -> V_4 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_162 * V_162 = F_55 ( V_3 -> V_4 . V_161 ) ;
T_1 V_240 ;
bool V_242 , V_243 ;
int V_16 ;
T_2 V_36 ;
V_240 = F_9 ( V_1 -> V_17 ) ;
if ( ( V_240 & V_234 ) == 0 ) {
if ( F_86 ( V_10 ) )
V_240 |= F_72 ( V_162 -> V_225 ) ;
F_7 ( V_1 , V_240 | V_234 ) ;
}
for ( V_16 = 0 ; V_16 < 2 ; V_16 ++ )
F_88 ( V_10 , V_162 -> V_225 ) ;
V_36 = F_29 ( V_1 , & V_242 , & V_243 ) ;
if ( V_36 == V_50 && ! V_242 ) {
F_12 ( L_23
L_24 , F_14 ( V_1 ) ) ;
}
if ( 0 )
F_33 ( V_1 ,
V_72 ) ;
F_31 ( V_1 , V_1 -> V_180 ) ;
}
static void F_90 ( struct V_5 * V_6 , int V_53 )
{
struct V_160 * V_161 ;
struct V_1 * V_1 = F_3 ( V_6 ) ;
if ( V_53 != V_72 )
V_53 = V_77 ;
if ( V_53 == V_6 -> V_244 )
return;
V_6 -> V_244 = V_53 ;
V_161 = V_1 -> V_4 . V_4 . V_161 ;
if ( ! V_161 ) {
V_1 -> V_4 . V_245 = false ;
return;
}
if ( V_53 != V_72 ) {
F_31 ( V_1 , 0 ) ;
if ( 0 )
F_33 ( V_1 , V_53 ) ;
V_1 -> V_4 . V_245 = false ;
F_91 ( V_161 ) ;
} else {
V_1 -> V_4 . V_245 = true ;
F_91 ( V_161 ) ;
if ( 0 )
F_33 ( V_1 , V_53 ) ;
F_31 ( V_1 , V_1 -> V_180 ) ;
}
F_92 ( V_6 -> V_10 ) ;
}
static int F_93 ( struct V_5 * V_6 ,
struct V_52 * V_53 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
if ( V_53 -> V_26 & V_246 )
return V_247 ;
if ( V_1 -> V_248 > V_53 -> clock )
return V_249 ;
if ( V_1 -> V_250 < V_53 -> clock )
return V_251 ;
if ( V_1 -> V_99 ) {
if ( V_53 -> V_101 > V_1 -> V_100 -> V_101 )
return V_252 ;
if ( V_53 -> V_102 > V_1 -> V_100 -> V_102 )
return V_252 ;
}
return V_253 ;
}
static bool F_94 ( struct V_1 * V_1 , struct V_254 * V_255 )
{
F_30 ( sizeof( * V_255 ) != 8 ) ;
if ( ! F_27 ( V_1 ,
V_256 ,
V_255 , sizeof( * V_255 ) ) )
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
V_255 -> V_257 ,
V_255 -> V_258 ,
V_255 -> V_259 ,
V_255 -> V_260 ,
V_255 -> V_261 ,
V_255 -> V_262 ,
V_255 -> V_263 ,
V_255 -> V_264 ,
V_255 -> V_265 ,
V_255 -> V_266 ,
V_255 -> V_267 ,
V_255 -> V_268 ) ;
return true ;
}
static T_4 F_95 ( struct V_1 * V_1 )
{
struct V_9 * V_10 = V_1 -> V_4 . V_4 . V_10 ;
T_4 V_269 ;
if ( F_73 ( V_10 ) || F_74 ( V_10 ) )
return 0 ;
if ( ! F_27 ( V_1 , V_270 ,
& V_269 , sizeof( V_269 ) ) )
return 0 ;
return V_269 ;
}
static void F_96 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
F_17 ( V_1 , V_271 ,
& V_1 -> V_272 , 2 ) ;
}
static bool
F_97 ( struct V_1 * V_1 )
{
return F_98 ( V_1 -> V_255 . V_268 ) > 1 ;
}
static struct V_273 *
F_99 ( struct V_5 * V_6 )
{
struct V_1 * V_274 = F_3 ( V_6 ) ;
return F_100 ( V_6 , & V_274 -> V_275 ) ;
}
static struct V_273 *
F_101 ( struct V_5 * V_6 )
{
struct V_11 * V_12 = V_6 -> V_10 -> V_13 ;
return F_100 ( V_6 ,
F_102 ( V_12 ,
V_12 -> V_276 . V_277 ) ) ;
}
static enum V_278
F_103 ( struct V_5 * V_6 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
enum V_278 V_36 ;
struct V_273 * V_273 ;
V_273 = F_99 ( V_6 ) ;
if ( V_273 == NULL && F_97 ( V_1 ) ) {
T_2 V_275 , V_279 = V_1 -> V_54 ;
for ( V_275 = V_1 -> V_54 >> 1 ; V_275 > 1 ; V_275 >>= 1 ) {
V_1 -> V_54 = V_275 ;
V_273 = F_99 ( V_6 ) ;
if ( V_273 )
break;
}
if ( V_273 == NULL )
V_1 -> V_54 = V_279 ;
}
if ( V_273 == NULL )
V_273 = F_101 ( V_6 ) ;
V_36 = V_280 ;
if ( V_273 != NULL ) {
if ( V_273 -> V_281 & V_282 ) {
V_36 = V_283 ;
if ( V_1 -> V_220 ) {
V_1 -> V_201 = F_104 ( V_273 ) ;
V_1 -> V_226 = F_105 ( V_273 ) ;
V_1 -> V_166 =
F_106 ( V_273 ) ;
}
} else
V_36 = V_284 ;
F_20 ( V_273 ) ;
}
if ( V_36 == V_283 ) {
struct V_7 * V_7 = F_5 ( V_6 ) ;
if ( V_7 -> V_285 != V_286 )
V_1 -> V_226 = ( V_7 -> V_285 == V_287 ) ;
}
return V_36 ;
}
static bool
F_107 ( struct V_7 * V_274 ,
struct V_273 * V_273 )
{
bool V_288 = ! ! ( V_273 -> V_281 & V_282 ) ;
bool V_289 = ! ! F_108 ( V_274 ) ;
F_12 ( L_38 ,
V_289 , V_288 ) ;
return V_289 == V_288 ;
}
static enum V_278
F_109 ( struct V_5 * V_6 , bool V_290 )
{
T_4 V_42 ;
struct V_1 * V_1 = F_3 ( V_6 ) ;
struct V_7 * V_7 = F_5 ( V_6 ) ;
enum V_278 V_30 ;
F_12 ( L_39 ,
V_6 -> V_4 . V_291 , F_110 ( V_6 ) ) ;
if ( ! F_27 ( V_1 ,
V_292 ,
& V_42 , 2 ) )
return V_280 ;
F_12 ( L_40 ,
V_42 & 0xff , V_42 >> 8 ,
V_7 -> V_233 ) ;
if ( V_42 == 0 )
return V_284 ;
V_1 -> V_180 = V_42 ;
V_1 -> V_201 = false ;
V_1 -> V_226 = false ;
V_1 -> V_166 = false ;
if ( ( V_7 -> V_233 & V_42 ) == 0 )
V_30 = V_284 ;
else if ( F_111 ( V_7 ) )
V_30 = F_103 ( V_6 ) ;
else {
struct V_273 * V_273 ;
V_273 = F_99 ( V_6 ) ;
if ( V_273 == NULL )
V_273 = F_101 ( V_6 ) ;
if ( V_273 != NULL ) {
if ( F_107 ( V_7 ,
V_273 ) )
V_30 = V_283 ;
else
V_30 = V_284 ;
F_20 ( V_273 ) ;
} else
V_30 = V_283 ;
}
if ( V_30 == V_283 ) {
V_1 -> V_197 = false ;
V_1 -> V_99 = false ;
if ( V_42 & V_293 )
V_1 -> V_197 = true ;
if ( V_42 & V_294 )
V_1 -> V_99 = V_1 -> V_100 != NULL ;
}
return V_30 ;
}
static void F_112 ( struct V_5 * V_6 )
{
struct V_273 * V_273 ;
V_273 = F_99 ( V_6 ) ;
if ( V_273 == NULL )
V_273 = F_101 ( V_6 ) ;
if ( V_273 != NULL ) {
if ( F_107 ( F_5 ( V_6 ) ,
V_273 ) ) {
F_113 ( V_6 , V_273 ) ;
F_114 ( V_6 , V_273 ) ;
}
F_20 ( V_273 ) ;
}
}
static void F_115 ( struct V_5 * V_6 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
struct V_295 V_296 ;
T_7 V_297 = 0 , V_176 = 0 ;
int V_16 ;
V_176 = 1 << V_1 -> V_177 ;
memcpy ( & V_296 , & V_176 ,
V_85 ( sizeof( V_176 ) , sizeof( struct V_295 ) ) ) ;
if ( ! F_35 ( V_1 , V_1 -> V_180 ) )
return;
F_30 ( sizeof( V_296 ) != 3 ) ;
if ( ! F_17 ( V_1 ,
V_298 ,
& V_296 , sizeof( V_296 ) ) )
return;
if ( ! F_21 ( V_1 , & V_297 , 3 ) )
return;
for ( V_16 = 0 ; V_16 < F_16 ( V_299 ) ; V_16 ++ )
if ( V_297 & ( 1 << V_16 ) ) {
struct V_52 * V_300 ;
V_300 = F_116 ( V_6 -> V_10 ,
& V_299 [ V_16 ] ) ;
if ( V_300 )
F_117 ( V_6 , V_300 ) ;
}
}
static void F_118 ( struct V_5 * V_6 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
struct V_11 * V_12 = V_6 -> V_10 -> V_13 ;
struct V_52 * V_301 ;
if ( V_12 -> V_276 . V_302 != NULL ) {
V_301 = F_116 ( V_6 -> V_10 ,
V_12 -> V_276 . V_302 ) ;
if ( V_301 != NULL ) {
V_301 -> type = ( V_303 |
V_304 ) ;
F_117 ( V_6 , V_301 ) ;
}
}
F_119 ( V_6 , & V_1 -> V_275 ) ;
F_120 (newmode, &connector->probed_modes, head) {
if ( V_301 -> type & V_303 ) {
V_1 -> V_100 =
F_116 ( V_6 -> V_10 , V_301 ) ;
V_1 -> V_99 = true ;
break;
}
}
}
static int F_121 ( struct V_5 * V_6 )
{
struct V_7 * V_7 = F_5 ( V_6 ) ;
if ( F_122 ( V_7 ) )
F_115 ( V_6 ) ;
else if ( F_123 ( V_7 ) )
F_118 ( V_6 ) ;
else
F_112 ( V_6 ) ;
return ! F_124 ( & V_6 -> V_305 ) ;
}
static void
F_125 ( struct V_5 * V_6 )
{
struct V_7 * V_7 = F_5 ( V_6 ) ;
struct V_9 * V_10 = V_6 -> V_10 ;
if ( V_7 -> V_306 )
F_126 ( V_10 , V_7 -> V_306 ) ;
if ( V_7 -> V_307 )
F_126 ( V_10 , V_7 -> V_307 ) ;
if ( V_7 -> V_308 )
F_126 ( V_10 , V_7 -> V_308 ) ;
if ( V_7 -> V_309 )
F_126 ( V_10 , V_7 -> V_309 ) ;
if ( V_7 -> V_310 )
F_126 ( V_10 , V_7 -> V_310 ) ;
if ( V_7 -> V_311 )
F_126 ( V_10 , V_7 -> V_311 ) ;
if ( V_7 -> V_312 )
F_126 ( V_10 , V_7 -> V_312 ) ;
if ( V_7 -> V_313 )
F_126 ( V_10 , V_7 -> V_313 ) ;
if ( V_7 -> V_314 )
F_126 ( V_10 , V_7 -> V_314 ) ;
if ( V_7 -> V_315 )
F_126 ( V_10 , V_7 -> V_315 ) ;
if ( V_7 -> V_316 )
F_126 ( V_10 , V_7 -> V_316 ) ;
if ( V_7 -> V_317 )
F_126 ( V_10 , V_7 -> V_317 ) ;
if ( V_7 -> V_318 )
F_126 ( V_10 , V_7 -> V_318 ) ;
if ( V_7 -> V_319 )
F_126 ( V_10 , V_7 -> V_319 ) ;
if ( V_7 -> V_320 )
F_126 ( V_10 , V_7 -> V_320 ) ;
if ( V_7 -> V_321 )
F_126 ( V_10 , V_7 -> V_321 ) ;
if ( V_7 -> V_322 )
F_126 ( V_10 , V_7 -> V_322 ) ;
}
static void F_127 ( struct V_5 * V_6 )
{
struct V_7 * V_7 = F_5 ( V_6 ) ;
if ( V_7 -> V_323 )
F_126 ( V_6 -> V_10 ,
V_7 -> V_323 ) ;
F_125 ( V_6 ) ;
F_128 ( V_6 ) ;
F_129 ( V_6 ) ;
F_20 ( V_7 ) ;
}
static bool F_130 ( struct V_5 * V_6 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
struct V_273 * V_273 ;
bool V_324 = false ;
if ( ! V_1 -> V_220 )
return false ;
V_273 = F_99 ( V_6 ) ;
if ( V_273 != NULL && V_273 -> V_281 & V_282 )
V_324 = F_105 ( V_273 ) ;
F_20 ( V_273 ) ;
return V_324 ;
}
static int
F_131 ( struct V_5 * V_6 ,
struct V_325 * V_326 ,
T_8 V_8 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
struct V_7 * V_7 = F_5 ( V_6 ) ;
struct V_11 * V_12 = V_6 -> V_10 -> V_13 ;
T_4 V_327 ;
T_5 V_32 ;
int V_30 ;
V_30 = F_132 ( & V_6 -> V_4 , V_326 , V_8 ) ;
if ( V_30 )
return V_30 ;
if ( V_326 == V_12 -> V_328 ) {
int V_16 = V_8 ;
bool V_324 ;
if ( V_16 == V_7 -> V_285 )
return 0 ;
V_7 -> V_285 = V_16 ;
if ( V_16 == V_286 )
V_324 = F_130 ( V_6 ) ;
else
V_324 = ( V_16 == V_287 ) ;
if ( V_324 == V_1 -> V_226 )
return 0 ;
V_1 -> V_226 = V_324 ;
goto V_329;
}
if ( V_326 == V_12 -> V_330 ) {
bool V_331 = V_1 -> V_200 ;
T_7 V_332 = V_1 -> V_202 ;
switch ( V_8 ) {
case V_333 :
V_1 -> V_200 = true ;
break;
case V_334 :
V_1 -> V_200 = false ;
V_1 -> V_202 = 0 ;
break;
case V_335 :
V_1 -> V_200 = false ;
V_1 -> V_202 = V_203 ;
break;
default:
return - V_336 ;
}
if ( V_331 == V_1 -> V_200 &&
V_332 == V_1 -> V_202 )
return 0 ;
goto V_329;
}
#define F_133 ( V_35 , T_9 ) \
if (intel_sdvo_connector->name == property) { \
if (intel_sdvo_connector->cur_##name == temp_value) return 0; \
if (intel_sdvo_connector->max_##name < temp_value) return -EINVAL; \
cmd = SDVO_CMD_SET_##NAME; \
intel_sdvo_connector->cur_##name = temp_value; \
goto set_value; \
}
if ( V_326 == V_7 -> V_323 ) {
if ( V_8 >= V_337 )
return - V_336 ;
if ( V_1 -> V_177 ==
V_7 -> V_338 [ V_8 ] )
return 0 ;
V_1 -> V_177 = V_7 -> V_338 [ V_8 ] ;
goto V_329;
} else if ( F_134 ( V_7 ) ) {
V_327 = V_8 ;
if ( V_7 -> V_306 == V_326 ) {
F_132 ( & V_6 -> V_4 ,
V_7 -> V_307 , V_8 ) ;
if ( V_7 -> V_339 == V_327 )
return 0 ;
V_7 -> V_339 = V_327 ;
V_7 -> V_340 = V_327 ;
V_327 = V_7 -> V_341 -
V_7 -> V_339 ;
V_32 = V_342 ;
goto V_343;
} else if ( V_7 -> V_307 == V_326 ) {
F_132 ( & V_6 -> V_4 ,
V_7 -> V_306 , V_8 ) ;
if ( V_7 -> V_340 == V_327 )
return 0 ;
V_7 -> V_339 = V_327 ;
V_7 -> V_340 = V_327 ;
V_327 = V_7 -> V_341 -
V_7 -> V_339 ;
V_32 = V_342 ;
goto V_343;
} else if ( V_7 -> V_308 == V_326 ) {
F_132 ( & V_6 -> V_4 ,
V_7 -> V_309 , V_8 ) ;
if ( V_7 -> V_344 == V_327 )
return 0 ;
V_7 -> V_344 = V_327 ;
V_7 -> V_345 = V_327 ;
V_327 = V_7 -> V_346 -
V_7 -> V_344 ;
V_32 = V_347 ;
goto V_343;
} else if ( V_7 -> V_309 == V_326 ) {
F_132 ( & V_6 -> V_4 ,
V_7 -> V_308 , V_8 ) ;
if ( V_7 -> V_345 == V_327 )
return 0 ;
V_7 -> V_344 = V_327 ;
V_7 -> V_345 = V_327 ;
V_327 = V_7 -> V_346 -
V_7 -> V_344 ;
V_32 = V_347 ;
goto V_343;
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
return - V_336 ;
V_343:
if ( ! F_26 ( V_1 , V_32 , & V_327 , 2 ) )
return - V_348 ;
V_329:
if ( V_1 -> V_4 . V_4 . V_161 )
F_135 ( V_1 -> V_4 . V_4 . V_161 ) ;
return 0 ;
#undef F_133
}
static void F_136 ( struct V_349 * V_3 )
{
struct V_1 * V_1 = F_1 ( F_137 ( V_3 ) ) ;
if ( V_1 -> V_100 != NULL )
F_138 ( V_3 -> V_10 ,
V_1 -> V_100 ) ;
F_139 ( & V_1 -> V_275 ) ;
F_140 ( V_3 ) ;
}
static void
F_141 ( struct V_1 * V_274 )
{
T_4 V_350 = 0 ;
unsigned int V_351 ;
switch ( V_274 -> V_352 ) {
case V_353 :
V_350 |= V_353 ;
case V_354 :
V_350 |= V_354 ;
case V_355 :
V_350 |= V_355 ;
case V_356 :
V_350 |= V_356 ;
case V_357 :
V_350 |= V_357 ;
case V_358 :
V_350 |= V_358 ;
break;
}
V_350 &= V_274 -> V_255 . V_268 ;
V_351 = F_98 ( V_350 ) ;
if ( V_351 > 3 )
V_351 = 3 ;
V_274 -> V_54 = 1 << V_351 ;
}
static void
F_142 ( struct V_11 * V_12 ,
struct V_1 * V_274 , T_1 V_359 )
{
struct V_360 * V_361 ;
if ( V_274 -> V_362 )
V_361 = & ( V_12 -> V_363 [ 0 ] ) ;
else
V_361 = & ( V_12 -> V_363 [ 1 ] ) ;
if ( V_361 -> V_364 )
V_274 -> V_54 = 1 << ( ( V_361 -> V_365 & 0xf0 ) >> 4 ) ;
else
F_141 ( V_274 ) ;
}
static void
F_143 ( struct V_11 * V_12 ,
struct V_1 * V_274 , T_1 V_359 )
{
struct V_360 * V_361 ;
T_2 V_366 ;
if ( V_274 -> V_362 )
V_361 = & V_12 -> V_363 [ 0 ] ;
else
V_361 = & V_12 -> V_363 [ 1 ] ;
if ( V_361 -> V_364 && F_144 ( V_361 -> V_367 ) )
V_366 = V_361 -> V_367 ;
else
V_366 = V_368 ;
V_274 -> V_31 = F_102 ( V_12 , V_366 ) ;
F_145 ( V_274 -> V_31 , true ) ;
}
static void
F_146 ( struct V_1 * V_274 )
{
F_145 ( V_274 -> V_31 , false ) ;
}
static bool
F_147 ( struct V_1 * V_1 , int V_369 )
{
return F_48 ( V_1 ) ;
}
static T_2
F_148 ( struct V_9 * V_10 , struct V_1 * V_274 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_360 * V_370 , * V_371 ;
if ( V_274 -> V_362 ) {
V_370 = & V_12 -> V_363 [ 0 ] ;
V_371 = & V_12 -> V_363 [ 1 ] ;
} else {
V_370 = & V_12 -> V_363 [ 1 ] ;
V_371 = & V_12 -> V_363 [ 0 ] ;
}
if ( V_370 -> V_25 )
return V_370 -> V_25 ;
if ( V_371 -> V_25 ) {
if ( V_371 -> V_25 == 0x70 )
return 0x72 ;
else
return 0x70 ;
}
if ( V_274 -> V_362 )
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
& V_372 ,
V_6 -> V_4 . V_4 . V_373 ) ;
F_151 ( & V_6 -> V_4 . V_4 ,
& V_374 ) ;
V_6 -> V_4 . V_4 . V_375 = 1 ;
V_6 -> V_4 . V_4 . V_376 = 0 ;
V_6 -> V_4 . V_4 . V_377 . V_378 = V_379 ;
V_6 -> V_4 . V_380 = F_76 ;
F_152 ( & V_6 -> V_4 , & V_3 -> V_4 ) ;
F_153 ( & V_6 -> V_4 . V_4 ) ;
}
static void
F_154 ( struct V_1 * V_1 ,
struct V_7 * V_6 )
{
struct V_9 * V_10 = V_6 -> V_4 . V_4 . V_10 ;
F_155 ( & V_6 -> V_4 . V_4 ) ;
if ( F_69 ( V_10 ) -> V_217 >= 4 && F_156 ( V_10 ) ) {
F_157 ( & V_6 -> V_4 . V_4 ) ;
V_1 -> V_200 = true ;
}
}
static bool
F_158 ( struct V_1 * V_1 , int V_369 )
{
struct V_349 * V_3 = & V_1 -> V_4 . V_4 ;
struct V_5 * V_6 ;
struct V_2 * V_2 = F_137 ( V_3 ) ;
struct V_231 * V_231 ;
struct V_7 * V_7 ;
V_7 = F_18 ( sizeof( struct V_7 ) , V_37 ) ;
if ( ! V_7 )
return false ;
if ( V_369 == 0 ) {
V_1 -> V_352 |= V_356 ;
V_7 -> V_233 = V_356 ;
} else if ( V_369 == 1 ) {
V_1 -> V_352 |= V_355 ;
V_7 -> V_233 = V_355 ;
}
V_231 = & V_7 -> V_4 ;
V_6 = & V_231 -> V_4 ;
if ( F_95 ( V_1 ) &
V_7 -> V_233 ) {
V_1 -> V_272 |= V_7 -> V_233 ;
V_2 -> V_381 = F_96 ;
F_96 ( V_2 ) ;
} else {
V_231 -> V_382 = V_383 | V_384 ;
}
V_3 -> V_385 = V_386 ;
V_6 -> V_373 = V_387 ;
if ( F_147 ( V_1 , V_369 ) ) {
V_6 -> V_373 = V_388 ;
V_1 -> V_220 = true ;
}
F_149 ( V_7 , V_1 ) ;
if ( V_1 -> V_220 )
F_154 ( V_1 , V_7 ) ;
return true ;
}
static bool
F_159 ( struct V_1 * V_1 , int type )
{
struct V_349 * V_3 = & V_1 -> V_4 . V_4 ;
struct V_5 * V_6 ;
struct V_231 * V_231 ;
struct V_7 * V_7 ;
V_7 = F_18 ( sizeof( struct V_7 ) , V_37 ) ;
if ( ! V_7 )
return false ;
V_231 = & V_7 -> V_4 ;
V_6 = & V_231 -> V_4 ;
V_3 -> V_385 = V_389 ;
V_6 -> V_373 = V_390 ;
V_1 -> V_352 |= type ;
V_7 -> V_233 = type ;
V_1 -> V_197 = true ;
F_149 ( V_7 , V_1 ) ;
if ( ! F_160 ( V_1 , V_7 , type ) )
goto V_391;
if ( ! F_161 ( V_1 , V_7 ) )
goto V_391;
return true ;
V_391:
F_127 ( V_6 ) ;
return false ;
}
static bool
F_162 ( struct V_1 * V_1 , int V_369 )
{
struct V_349 * V_3 = & V_1 -> V_4 . V_4 ;
struct V_5 * V_6 ;
struct V_231 * V_231 ;
struct V_7 * V_7 ;
V_7 = F_18 ( sizeof( struct V_7 ) , V_37 ) ;
if ( ! V_7 )
return false ;
V_231 = & V_7 -> V_4 ;
V_6 = & V_231 -> V_4 ;
V_231 -> V_382 = V_383 ;
V_3 -> V_385 = V_392 ;
V_6 -> V_373 = V_393 ;
if ( V_369 == 0 ) {
V_1 -> V_352 |= V_358 ;
V_7 -> V_233 = V_358 ;
} else if ( V_369 == 1 ) {
V_1 -> V_352 |= V_357 ;
V_7 -> V_233 = V_357 ;
}
F_149 ( V_7 ,
V_1 ) ;
return true ;
}
static bool
F_163 ( struct V_1 * V_1 , int V_369 )
{
struct V_349 * V_3 = & V_1 -> V_4 . V_4 ;
struct V_5 * V_6 ;
struct V_231 * V_231 ;
struct V_7 * V_7 ;
V_7 = F_18 ( sizeof( struct V_7 ) , V_37 ) ;
if ( ! V_7 )
return false ;
V_231 = & V_7 -> V_4 ;
V_6 = & V_231 -> V_4 ;
V_3 -> V_385 = V_394 ;
V_6 -> V_373 = V_395 ;
if ( V_369 == 0 ) {
V_1 -> V_352 |= V_354 ;
V_7 -> V_233 = V_354 ;
} else if ( V_369 == 1 ) {
V_1 -> V_352 |= V_353 ;
V_7 -> V_233 = V_353 ;
}
F_149 ( V_7 , V_1 ) ;
if ( ! F_161 ( V_1 , V_7 ) )
goto V_391;
return true ;
V_391:
F_127 ( V_6 ) ;
return false ;
}
static bool
F_164 ( struct V_1 * V_1 , T_4 V_26 )
{
V_1 -> V_197 = false ;
V_1 -> V_99 = false ;
if ( V_26 & V_356 )
if ( ! F_158 ( V_1 , 0 ) )
return false ;
if ( ( V_26 & V_396 ) == V_396 )
if ( ! F_158 ( V_1 , 1 ) )
return false ;
if ( V_26 & V_397 )
if ( ! F_159 ( V_1 , V_397 ) )
return false ;
if ( V_26 & V_398 )
if ( ! F_159 ( V_1 , V_398 ) )
return false ;
if ( V_26 & V_399 )
if ( ! F_159 ( V_1 , V_399 ) )
return false ;
if ( V_26 & V_358 )
if ( ! F_162 ( V_1 , 0 ) )
return false ;
if ( ( V_26 & V_400 ) == V_400 )
if ( ! F_162 ( V_1 , 1 ) )
return false ;
if ( V_26 & V_354 )
if ( ! F_163 ( V_1 , 0 ) )
return false ;
if ( ( V_26 & V_294 ) == V_294 )
if ( ! F_163 ( V_1 , 1 ) )
return false ;
if ( ( V_26 & V_401 ) == 0 ) {
unsigned char V_402 [ 2 ] ;
V_1 -> V_352 = 0 ;
memcpy ( V_402 , & V_1 -> V_255 . V_268 , 2 ) ;
F_12 ( L_41 ,
F_14 ( V_1 ) ,
V_402 [ 0 ] , V_402 [ 1 ] ) ;
return false ;
}
V_1 -> V_4 . V_403 = ( 1 << 0 ) | ( 1 << 1 ) | ( 1 << 2 ) ;
return true ;
}
static void F_165 ( struct V_1 * V_1 )
{
struct V_9 * V_10 = V_1 -> V_4 . V_4 . V_10 ;
struct V_5 * V_6 , * V_152 ;
F_166 (connector, tmp,
&dev->mode_config.connector_list, head) {
if ( F_4 ( V_6 ) == & V_1 -> V_4 )
F_127 ( V_6 ) ;
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
V_404 ,
& V_175 , sizeof( V_175 ) ) )
return false ;
memcpy ( & V_176 , & V_175 , V_85 ( sizeof( V_176 ) , sizeof( V_175 ) ) ) ;
if ( V_176 == 0 )
return false ;
V_7 -> V_405 = 0 ;
for ( V_16 = 0 ; V_16 < V_337 ; V_16 ++ )
if ( V_176 & ( 1 << V_16 ) )
V_7 -> V_338 [ V_7 -> V_405 ++ ] = V_16 ;
V_7 -> V_323 =
F_167 ( V_10 , V_406 ,
L_42 , V_7 -> V_405 ) ;
if ( ! V_7 -> V_323 )
return false ;
for ( V_16 = 0 ; V_16 < V_7 -> V_405 ; V_16 ++ )
F_168 (
V_7 -> V_323 , V_16 ,
V_16 , V_407 [ V_7 -> V_338 [ V_16 ] ] ) ;
V_1 -> V_177 = V_7 -> V_338 [ 0 ] ;
F_169 ( & V_7 -> V_4 . V_4 . V_4 ,
V_7 -> V_323 , 0 ) ;
return true ;
}
static bool
F_170 ( struct V_1 * V_1 ,
struct V_7 * V_7 ,
struct V_408 V_409 )
{
struct V_9 * V_10 = V_1 -> V_4 . V_4 . V_10 ;
struct V_5 * V_6 = & V_7 -> V_4 . V_4 ;
T_4 V_42 , V_410 [ 2 ] ;
if ( V_409 . V_411 ) {
if ( ! F_27 ( V_1 ,
V_412 ,
& V_410 , 4 ) )
return false ;
if ( ! F_27 ( V_1 ,
V_413 ,
& V_42 , 2 ) )
return false ;
V_7 -> V_341 = V_410 [ 0 ] ;
V_7 -> V_339 = V_410 [ 0 ] - V_42 ;
V_7 -> V_340 = V_7 -> V_339 ;
V_7 -> V_306 =
F_171 ( V_10 , 0 , L_43 , 0 , V_410 [ 0 ] ) ;
if ( ! V_7 -> V_306 )
return false ;
F_169 ( & V_6 -> V_4 ,
V_7 -> V_306 ,
V_7 -> V_339 ) ;
V_7 -> V_307 =
F_171 ( V_10 , 0 , L_44 , 0 , V_410 [ 0 ] ) ;
if ( ! V_7 -> V_307 )
return false ;
F_169 ( & V_6 -> V_4 ,
V_7 -> V_307 ,
V_7 -> V_340 ) ;
F_12 ( L_45
L_46 ,
V_410 [ 0 ] , V_410 [ 1 ] , V_42 ) ;
}
if ( V_409 . V_414 ) {
if ( ! F_27 ( V_1 ,
V_415 ,
& V_410 , 4 ) )
return false ;
if ( ! F_27 ( V_1 ,
V_416 ,
& V_42 , 2 ) )
return false ;
V_7 -> V_346 = V_410 [ 0 ] ;
V_7 -> V_344 = V_410 [ 0 ] - V_42 ;
V_7 -> V_345 = V_7 -> V_344 ;
V_7 -> V_308 =
F_171 ( V_10 , 0 ,
L_47 , 0 , V_410 [ 0 ] ) ;
if ( ! V_7 -> V_308 )
return false ;
F_169 ( & V_6 -> V_4 ,
V_7 -> V_308 ,
V_7 -> V_344 ) ;
V_7 -> V_309 =
F_171 ( V_10 , 0 ,
L_48 , 0 , V_410 [ 0 ] ) ;
if ( ! V_7 -> V_309 )
return false ;
F_169 ( & V_6 -> V_4 ,
V_7 -> V_309 ,
V_7 -> V_345 ) ;
F_12 ( L_49
L_46 ,
V_410 [ 0 ] , V_410 [ 1 ] , V_42 ) ;
}
F_172 ( V_310 , V_417 ) ;
F_172 ( V_311 , V_418 ) ;
F_172 ( V_312 , V_419 ) ;
F_172 ( V_313 , V_420 ) ;
F_172 ( V_314 , V_421 ) ;
F_172 ( V_315 , V_422 ) ;
F_172 ( V_322 , V_423 ) ;
F_172 ( V_316 , V_424 ) ;
F_172 ( V_318 , V_425 ) ;
F_172 ( V_317 , V_426 ) ;
F_172 ( V_320 , V_427 ) ;
F_172 ( V_319 , V_428 ) ;
if ( V_409 . V_321 ) {
if ( ! F_27 ( V_1 , V_429 , & V_42 , 2 ) )
return false ;
V_7 -> V_430 = 1 ;
V_7 -> V_431 = V_42 & 0x1 ;
V_7 -> V_321 =
F_171 ( V_10 , 0 , L_50 , 0 , 1 ) ;
if ( ! V_7 -> V_321 )
return false ;
F_169 ( & V_6 -> V_4 ,
V_7 -> V_321 ,
V_7 -> V_431 ) ;
F_12 ( L_51 , V_42 ) ;
}
return true ;
}
static bool
F_173 ( struct V_1 * V_1 ,
struct V_7 * V_7 ,
struct V_408 V_409 )
{
struct V_9 * V_10 = V_1 -> V_4 . V_4 . V_10 ;
struct V_5 * V_6 = & V_7 -> V_4 . V_4 ;
T_4 V_42 , V_410 [ 2 ] ;
F_172 ( V_322 , V_423 ) ;
return true ;
}
static bool F_161 ( struct V_1 * V_1 ,
struct V_7 * V_7 )
{
union {
struct V_408 V_297 ;
T_4 V_42 ;
} V_409 ;
F_30 ( sizeof( V_409 ) != 2 ) ;
V_409 . V_42 = 0 ;
F_27 ( V_1 ,
V_432 ,
& V_409 , sizeof( V_409 ) ) ;
if ( V_409 . V_42 == 0 ) {
F_12 ( L_52 ) ;
return true ;
}
if ( F_122 ( V_7 ) )
return F_170 ( V_1 , V_7 , V_409 . V_297 ) ;
else if ( F_123 ( V_7 ) )
return F_173 ( V_1 , V_7 , V_409 . V_297 ) ;
else
return true ;
}
static int F_174 ( struct V_433 * V_434 ,
struct V_23 * V_24 ,
int V_435 )
{
struct V_1 * V_274 = V_434 -> V_436 ;
if ( ! F_25 ( V_274 , V_274 -> V_54 ) )
return - V_348 ;
return V_274 -> V_31 -> V_437 -> V_438 ( V_274 -> V_31 , V_24 , V_435 ) ;
}
static T_1 F_175 ( struct V_433 * V_434 )
{
struct V_1 * V_274 = V_434 -> V_436 ;
return V_274 -> V_31 -> V_437 -> V_439 ( V_274 -> V_31 ) ;
}
static bool
F_176 ( struct V_1 * V_274 ,
struct V_9 * V_10 )
{
V_274 -> V_275 . V_440 = V_441 ;
V_274 -> V_275 . V_442 = V_443 ;
snprintf ( V_274 -> V_275 . V_35 , V_444 , L_53 ) ;
V_274 -> V_275 . V_10 . V_445 = & V_10 -> V_446 -> V_10 ;
V_274 -> V_275 . V_436 = V_274 ;
V_274 -> V_275 . V_437 = & V_447 ;
return F_177 ( & V_274 -> V_275 ) == 0 ;
}
bool F_178 ( struct V_9 * V_10 , T_7 V_17 , bool V_362 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_2 * V_2 ;
struct V_1 * V_1 ;
int V_16 ;
V_1 = F_18 ( sizeof( struct V_1 ) , V_37 ) ;
if ( ! V_1 )
return false ;
V_1 -> V_17 = V_17 ;
V_1 -> V_362 = V_362 ;
V_1 -> V_25 = F_148 ( V_10 , V_1 ) >> 1 ;
F_143 ( V_12 , V_1 , V_17 ) ;
if ( ! F_176 ( V_1 , V_10 ) )
goto V_448;
V_2 = & V_1 -> V_4 ;
V_2 -> type = V_449 ;
F_179 ( V_10 , & V_2 -> V_4 , & V_450 , 0 ) ;
for ( V_16 = 0 ; V_16 < 0x40 ; V_16 ++ ) {
T_2 V_451 ;
if ( ! F_10 ( V_1 , V_16 , & V_451 ) ) {
F_12 ( L_54 ,
F_14 ( V_1 ) ) ;
goto V_391;
}
}
V_2 -> V_452 = F_64 ;
V_2 -> V_453 = F_85 ;
V_2 -> V_454 = F_67 ;
V_2 -> V_455 = F_89 ;
V_2 -> V_380 = F_77 ;
V_2 -> V_456 = F_81 ;
if ( ! F_94 ( V_1 , & V_1 -> V_255 ) )
goto V_391;
if ( F_164 ( V_1 ,
V_1 -> V_255 . V_268 ) != true ) {
F_12 ( L_55 ,
F_14 ( V_1 ) ) ;
goto V_457;
}
if ( V_1 -> V_272 ) {
V_2 -> V_458 =
V_1 -> V_362 ? V_459 : V_460 ;
}
V_1 -> V_4 . V_461 = false ;
F_142 ( V_12 , V_1 , V_17 ) ;
if ( ! F_28 ( V_1 ) )
goto V_457;
if ( ! F_34 ( V_1 ,
& V_1 -> V_248 ,
& V_1 -> V_250 ) )
goto V_457;
F_12 ( L_56
L_57
L_58
L_59 ,
F_14 ( V_1 ) ,
V_1 -> V_255 . V_257 , V_1 -> V_255 . V_258 ,
V_1 -> V_255 . V_259 ,
V_1 -> V_248 / 1000 ,
V_1 -> V_250 / 1000 ,
( V_1 -> V_255 . V_262 & 0x1 ) ? 'Y' : 'N' ,
( V_1 -> V_255 . V_262 & 0x2 ) ? 'Y' : 'N' ,
V_1 -> V_255 . V_268 &
( V_356 | V_358 ) ? 'Y' : 'N' ,
V_1 -> V_255 . V_268 &
( V_355 | V_357 ) ? 'Y' : 'N' ) ;
return true ;
V_457:
F_165 ( V_1 ) ;
V_391:
F_180 ( & V_2 -> V_4 ) ;
F_139 ( & V_1 -> V_275 ) ;
V_448:
F_146 ( V_1 ) ;
F_20 ( V_1 ) ;
return false ;
}
