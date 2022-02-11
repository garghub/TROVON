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
if ( F_10 ( V_10 ) ) {
F_8 ( V_1 -> V_17 , V_8 ) ;
F_9 ( V_1 -> V_17 ) ;
}
return;
}
if ( V_1 -> V_17 == V_19 )
V_15 = F_11 ( V_20 ) ;
else
V_14 = F_11 ( V_19 ) ;
for ( V_16 = 0 ; V_16 < 2 ; V_16 ++ )
{
F_8 ( V_19 , V_14 ) ;
F_9 ( V_19 ) ;
F_8 ( V_20 , V_15 ) ;
F_9 ( V_20 ) ;
}
}
static bool F_12 ( struct V_1 * V_1 , T_2 V_21 , T_2 * V_22 )
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
if ( ( V_30 = F_13 ( V_1 -> V_31 , V_24 , 2 ) ) == 2 )
return true ;
F_14 ( L_1 , V_30 ) ;
return false ;
}
static void F_15 ( struct V_1 * V_1 , T_2 V_32 ,
const void * args , int V_33 )
{
int V_16 , V_34 = 0 ;
#define F_16 256
char V_35 [ F_16 ] ;
#define F_17 ( args ... ) \
pos += snprintf(buffer + pos, max_t(int, BUF_LEN - pos, 0), args)
for ( V_16 = 0 ; V_16 < V_33 ; V_16 ++ ) {
F_17 ( L_2 , ( ( T_2 * ) args ) [ V_16 ] ) ;
}
for (; V_16 < 8 ; V_16 ++ ) {
F_17 ( L_3 ) ;
}
for ( V_16 = 0 ; V_16 < F_18 ( V_36 ) ; V_16 ++ ) {
if ( V_32 == V_36 [ V_16 ] . V_32 ) {
F_17 ( L_4 , V_36 [ V_16 ] . V_37 ) ;
break;
}
}
if ( V_16 == F_18 ( V_36 ) ) {
F_17 ( L_5 , V_32 ) ;
}
F_19 ( V_34 >= F_16 - 1 ) ;
#undef F_17
#undef F_16
F_14 ( L_6 , F_20 ( V_1 ) , V_32 , V_35 ) ;
}
static bool F_21 ( struct V_1 * V_1 , T_2 V_32 ,
const void * args , int V_33 )
{
T_2 * V_28 , V_38 ;
struct V_23 * V_24 ;
int V_16 , V_30 = true ;
V_28 = F_22 ( V_33 * 2 + 2 , V_39 ) ;
if ( ! V_28 )
return false ;
V_24 = F_23 ( V_33 + 3 , sizeof( * V_24 ) , V_39 ) ;
if ( ! V_24 ) {
F_24 ( V_28 ) ;
return false ;
}
F_15 ( V_1 , V_32 , args , V_33 ) ;
for ( V_16 = 0 ; V_16 < V_33 ; V_16 ++ ) {
V_24 [ V_16 ] . V_21 = V_1 -> V_25 ;
V_24 [ V_16 ] . V_26 = 0 ;
V_24 [ V_16 ] . V_27 = 2 ;
V_24 [ V_16 ] . V_28 = V_28 + 2 * V_16 ;
V_28 [ 2 * V_16 + 0 ] = V_40 - V_16 ;
V_28 [ 2 * V_16 + 1 ] = ( ( T_2 * ) args ) [ V_16 ] ;
}
V_24 [ V_16 ] . V_21 = V_1 -> V_25 ;
V_24 [ V_16 ] . V_26 = 0 ;
V_24 [ V_16 ] . V_27 = 2 ;
V_24 [ V_16 ] . V_28 = V_28 + 2 * V_16 ;
V_28 [ 2 * V_16 + 0 ] = V_41 ;
V_28 [ 2 * V_16 + 1 ] = V_32 ;
V_38 = V_42 ;
V_24 [ V_16 + 1 ] . V_21 = V_1 -> V_25 ;
V_24 [ V_16 + 1 ] . V_26 = 0 ;
V_24 [ V_16 + 1 ] . V_27 = 1 ;
V_24 [ V_16 + 1 ] . V_28 = & V_38 ;
V_24 [ V_16 + 2 ] . V_21 = V_1 -> V_25 ;
V_24 [ V_16 + 2 ] . V_26 = V_29 ;
V_24 [ V_16 + 2 ] . V_27 = 1 ;
V_24 [ V_16 + 2 ] . V_28 = & V_38 ;
V_30 = F_13 ( V_1 -> V_31 , V_24 , V_16 + 3 ) ;
if ( V_30 < 0 ) {
F_14 ( L_7 , V_30 ) ;
V_30 = false ;
goto V_43;
}
if ( V_30 != V_16 + 3 ) {
F_14 ( L_8 , V_30 , V_16 + 3 ) ;
V_30 = false ;
}
V_43:
F_24 ( V_24 ) ;
F_24 ( V_28 ) ;
return V_30 ;
}
static bool F_25 ( struct V_1 * V_1 ,
void * V_44 , int V_45 )
{
T_2 V_46 = 15 ;
T_2 V_38 ;
int V_16 , V_34 = 0 ;
#define F_16 256
char V_35 [ F_16 ] ;
if ( ! F_12 ( V_1 ,
V_42 ,
& V_38 ) )
goto V_47;
while ( ( V_38 == V_48 ||
V_38 == V_49 ) && -- V_46 ) {
if ( V_46 < 10 )
F_26 ( 15 ) ;
else
F_27 ( 15 ) ;
if ( ! F_12 ( V_1 ,
V_42 ,
& V_38 ) )
goto V_47;
}
#define F_17 ( args ... ) \
pos += snprintf(buffer + pos, max_t(int, BUF_LEN - pos, 0), args)
if ( V_38 <= V_50 )
F_17 ( L_4 , V_51 [ V_38 ] ) ;
else
F_17 ( L_9 , V_38 ) ;
if ( V_38 != V_52 )
goto V_47;
for ( V_16 = 0 ; V_16 < V_45 ; V_16 ++ ) {
if ( ! F_12 ( V_1 ,
V_53 + V_16 ,
& ( ( T_2 * ) V_44 ) [ V_16 ] ) )
goto V_47;
F_17 ( L_10 , ( ( T_2 * ) V_44 ) [ V_16 ] ) ;
}
F_19 ( V_34 >= F_16 - 1 ) ;
#undef F_17
#undef F_16
F_14 ( L_11 , F_20 ( V_1 ) , V_35 ) ;
return true ;
V_47:
F_14 ( L_12 , F_20 ( V_1 ) ) ;
return false ;
}
static int F_28 ( struct V_54 * V_55 )
{
if ( V_55 -> clock >= 100000 )
return 1 ;
else if ( V_55 -> clock >= 50000 )
return 2 ;
else
return 4 ;
}
static bool F_29 ( struct V_1 * V_1 ,
T_2 V_56 )
{
return F_21 ( V_1 ,
V_57 ,
& V_56 , 1 ) ;
}
static bool F_30 ( struct V_1 * V_1 , T_2 V_32 , const void * V_58 , int V_27 )
{
if ( ! F_21 ( V_1 , V_32 , V_58 , V_27 ) )
return false ;
return F_25 ( V_1 , NULL , 0 ) ;
}
static bool
F_31 ( struct V_1 * V_1 , T_2 V_32 , void * V_59 , int V_27 )
{
if ( ! F_21 ( V_1 , V_32 , NULL , 0 ) )
return false ;
return F_25 ( V_1 , V_59 , V_27 ) ;
}
static bool F_32 ( struct V_1 * V_1 )
{
struct V_60 V_61 = { 0 } ;
return F_30 ( V_1 ,
V_62 ,
& V_61 , sizeof( V_61 ) ) ;
}
static bool F_33 ( struct V_1 * V_1 , bool * V_63 , bool * V_64 )
{
struct V_65 V_44 ;
F_34 ( sizeof( V_44 ) != 1 ) ;
if ( ! F_31 ( V_1 , V_66 ,
& V_44 , sizeof( V_44 ) ) )
return false ;
* V_63 = V_44 . V_67 ;
* V_64 = V_44 . V_68 ;
return true ;
}
static bool F_35 ( struct V_1 * V_1 ,
T_3 V_69 )
{
return F_30 ( V_1 ,
V_70 ,
& V_69 , sizeof( V_69 ) ) ;
}
static bool F_36 ( struct V_1 * V_1 ,
T_3 * V_69 )
{
return F_31 ( V_1 ,
V_71 ,
V_69 , sizeof( * V_69 ) ) ;
}
static bool F_37 ( struct V_1 * V_1 ,
int V_55 )
{
T_2 V_72 = V_73 ;
switch ( V_55 ) {
case V_74 :
V_72 = V_73 ;
break;
case V_75 :
V_72 = V_76 ;
break;
case V_77 :
V_72 = V_78 ;
break;
case V_79 :
V_72 = V_80 ;
break;
}
return F_30 ( V_1 ,
V_81 , & V_72 , sizeof( V_72 ) ) ;
}
static bool F_38 ( struct V_1 * V_1 ,
int * V_82 ,
int * V_83 )
{
struct V_84 V_85 ;
F_34 ( sizeof( V_85 ) != 4 ) ;
if ( ! F_31 ( V_1 ,
V_86 ,
& V_85 , sizeof( V_85 ) ) )
return false ;
* V_82 = V_85 . V_87 * 10 ;
* V_83 = V_85 . V_88 * 10 ;
return true ;
}
static bool F_39 ( struct V_1 * V_1 ,
T_3 V_69 )
{
return F_30 ( V_1 ,
V_89 ,
& V_69 , sizeof( V_69 ) ) ;
}
static bool F_40 ( struct V_1 * V_1 , T_2 V_32 ,
struct V_90 * V_91 )
{
return F_30 ( V_1 , V_32 , & V_91 -> V_92 , sizeof( V_91 -> V_92 ) ) &&
F_30 ( V_1 , V_32 + 1 , & V_91 -> V_93 , sizeof( V_91 -> V_93 ) ) ;
}
static bool F_41 ( struct V_1 * V_1 , T_2 V_32 ,
struct V_90 * V_91 )
{
return F_31 ( V_1 , V_32 , & V_91 -> V_92 , sizeof( V_91 -> V_92 ) ) &&
F_31 ( V_1 , V_32 + 1 , & V_91 -> V_93 , sizeof( V_91 -> V_93 ) ) ;
}
static bool F_42 ( struct V_1 * V_1 ,
struct V_90 * V_91 )
{
return F_40 ( V_1 ,
V_94 , V_91 ) ;
}
static bool F_43 ( struct V_1 * V_1 ,
struct V_90 * V_91 )
{
return F_40 ( V_1 ,
V_95 , V_91 ) ;
}
static bool F_44 ( struct V_1 * V_1 ,
struct V_90 * V_91 )
{
return F_41 ( V_1 ,
V_96 , V_91 ) ;
}
static bool
F_45 ( struct V_1 * V_1 ,
T_4 clock ,
T_4 V_97 ,
T_4 V_98 )
{
struct V_99 args ;
memset ( & args , 0 , sizeof( args ) ) ;
args . clock = clock ;
args . V_97 = V_97 ;
args . V_98 = V_98 ;
args . V_100 = 0 ;
if ( V_1 -> V_101 &&
( V_1 -> V_102 -> V_103 != V_97 ||
V_1 -> V_102 -> V_104 != V_98 ) )
args . V_105 = 1 ;
return F_30 ( V_1 ,
V_106 ,
& args , sizeof( args ) ) ;
}
static bool F_46 ( struct V_1 * V_1 ,
struct V_90 * V_91 )
{
F_34 ( sizeof( V_91 -> V_92 ) != 8 ) ;
F_34 ( sizeof( V_91 -> V_93 ) != 8 ) ;
return F_31 ( V_1 , V_107 ,
& V_91 -> V_92 , sizeof( V_91 -> V_92 ) ) &&
F_31 ( V_1 , V_108 ,
& V_91 -> V_93 , sizeof( V_91 -> V_93 ) ) ;
}
static bool F_47 ( struct V_1 * V_1 , T_2 V_8 )
{
return F_30 ( V_1 , V_109 , & V_8 , 1 ) ;
}
static void F_48 ( struct V_90 * V_91 ,
const struct V_54 * V_55 )
{
T_4 V_97 , V_98 ;
T_4 V_110 , V_111 , V_112 , V_113 ;
T_4 V_114 , V_115 ;
int V_116 ;
memset ( V_91 , 0 , sizeof( * V_91 ) ) ;
V_97 = V_55 -> V_103 ;
V_98 = V_55 -> V_104 ;
V_110 = V_55 -> V_117 - V_55 -> V_103 ;
V_111 = V_55 -> V_118 - V_55 -> V_119 ;
V_112 = V_55 -> V_120 - V_55 -> V_104 ;
V_113 = V_55 -> V_121 - V_55 -> V_122 ;
V_114 = V_55 -> V_119 - V_55 -> V_103 ;
V_115 = V_55 -> V_122 - V_55 -> V_104 ;
V_116 = V_55 -> clock ;
V_116 /= 10 ;
V_91 -> V_92 . clock = V_116 ;
V_91 -> V_92 . V_123 = V_97 & 0xff ;
V_91 -> V_92 . V_124 = V_110 & 0xff ;
V_91 -> V_92 . V_125 = ( ( ( V_97 >> 8 ) & 0xf ) << 4 ) |
( ( V_110 >> 8 ) & 0xf ) ;
V_91 -> V_92 . V_126 = V_98 & 0xff ;
V_91 -> V_92 . V_127 = V_112 & 0xff ;
V_91 -> V_92 . V_128 = ( ( ( V_98 >> 8 ) & 0xf ) << 4 ) |
( ( V_112 >> 8 ) & 0xf ) ;
V_91 -> V_93 . V_129 = V_114 & 0xff ;
V_91 -> V_93 . V_130 = V_111 & 0xff ;
V_91 -> V_93 . V_131 = ( V_115 & 0xf ) << 4 |
( V_113 & 0xf ) ;
V_91 -> V_93 . V_132 = ( ( V_114 & 0x300 ) >> 2 ) |
( ( V_111 & 0x300 ) >> 4 ) | ( ( V_115 & 0x30 ) >> 2 ) |
( ( V_113 & 0x30 ) >> 4 ) ;
V_91 -> V_93 . V_133 = 0x18 ;
if ( V_55 -> V_26 & V_134 )
V_91 -> V_93 . V_133 |= V_135 ;
if ( V_55 -> V_26 & V_136 )
V_91 -> V_93 . V_133 |= V_137 ;
if ( V_55 -> V_26 & V_138 )
V_91 -> V_93 . V_133 |= V_139 ;
V_91 -> V_93 . V_140 = V_115 & 0xc0 ;
}
static void F_49 ( struct V_54 * V_141 ,
const struct V_90 * V_91 )
{
struct V_54 V_55 = {} ;
V_55 . V_103 = V_91 -> V_92 . V_123 ;
V_55 . V_103 += ( ( V_91 -> V_92 . V_125 >> 4 ) & 0x0f ) << 8 ;
V_55 . V_119 = V_55 . V_103 + V_91 -> V_93 . V_129 ;
V_55 . V_119 += ( V_91 -> V_93 . V_132 & 0xc0 ) << 2 ;
V_55 . V_118 = V_55 . V_119 + V_91 -> V_93 . V_130 ;
V_55 . V_118 += ( V_91 -> V_93 . V_132 & 0x30 ) << 4 ;
V_55 . V_117 = V_55 . V_103 + V_91 -> V_92 . V_124 ;
V_55 . V_117 += ( V_91 -> V_92 . V_125 & 0xf ) << 8 ;
V_55 . V_104 = V_91 -> V_92 . V_126 ;
V_55 . V_104 += ( ( V_91 -> V_92 . V_128 >> 4 ) & 0x0f ) << 8 ;
V_55 . V_122 = V_55 . V_104 ;
V_55 . V_122 += ( V_91 -> V_93 . V_131 >> 4 ) & 0xf ;
V_55 . V_122 += ( V_91 -> V_93 . V_132 & 0x0c ) << 2 ;
V_55 . V_122 += V_91 -> V_93 . V_140 & 0xc0 ;
V_55 . V_121 = V_55 . V_122 +
( V_91 -> V_93 . V_131 & 0xf ) ;
V_55 . V_121 += ( V_91 -> V_93 . V_132 & 0x3 ) << 4 ;
V_55 . V_120 = V_55 . V_104 + V_91 -> V_92 . V_127 ;
V_55 . V_120 += ( V_91 -> V_92 . V_128 & 0xf ) << 8 ;
V_55 . clock = V_91 -> V_92 . clock * 10 ;
if ( V_91 -> V_93 . V_133 & V_135 )
V_55 . V_26 |= V_134 ;
if ( V_91 -> V_93 . V_133 & V_137 )
V_55 . V_26 |= V_136 ;
else
V_55 . V_26 |= V_142 ;
if ( V_91 -> V_93 . V_133 & V_139 )
V_55 . V_26 |= V_138 ;
else
V_55 . V_26 |= V_143 ;
F_50 ( & V_55 , 0 ) ;
F_51 ( V_141 , & V_55 ) ;
}
static bool F_52 ( struct V_1 * V_1 )
{
struct V_144 V_145 ;
F_34 ( sizeof( V_145 ) != 2 ) ;
return F_31 ( V_1 ,
V_146 ,
& V_145 , sizeof( V_145 ) ) ;
}
static bool F_53 ( struct V_1 * V_1 ,
T_5 V_55 )
{
return F_30 ( V_1 , V_147 , & V_55 , 1 ) ;
}
static bool F_54 ( struct V_1 * V_1 ,
T_5 V_55 )
{
return F_30 ( V_1 , V_148 , & V_55 , 1 ) ;
}
static bool F_55 ( struct V_1 * V_1 ,
unsigned V_149 , T_5 V_150 ,
const T_5 * V_58 , unsigned V_151 )
{
T_5 V_152 [ 2 ] = { V_149 , 0 } ;
T_5 V_153 , V_154 [ 8 ] ;
int V_16 ;
if ( ! F_30 ( V_1 ,
V_155 ,
V_152 , 2 ) )
return false ;
if ( ! F_31 ( V_1 , V_156 ,
& V_153 , 1 ) )
return false ;
V_153 ++ ;
F_14 ( L_13 ,
V_149 , V_151 , V_153 ) ;
for ( V_16 = 0 ; V_16 < V_153 ; V_16 += 8 ) {
memset ( V_154 , 0 , 8 ) ;
if ( V_16 < V_151 )
memcpy ( V_154 , V_58 + V_16 , F_56 ( unsigned , 8 , V_151 - V_16 ) ) ;
if ( ! F_30 ( V_1 ,
V_157 ,
V_154 , 8 ) )
return false ;
}
return F_30 ( V_1 ,
V_158 ,
& V_150 , 1 ) ;
}
static bool F_57 ( struct V_1 * V_1 ,
const struct V_54 * V_159 )
{
T_5 V_160 [ F_58 ( V_161 ) ] ;
struct V_162 * V_163 = V_1 -> V_4 . V_4 . V_163 ;
struct V_164 * V_164 = F_59 ( V_163 ) ;
union V_165 V_166 ;
int V_30 ;
T_6 V_27 ;
V_30 = F_60 ( & V_166 . V_167 ,
V_159 ) ;
if ( V_30 < 0 ) {
F_61 ( L_14 ) ;
return false ;
}
if ( V_1 -> V_168 ) {
if ( V_164 -> V_169 -> V_170 )
V_166 . V_167 . V_171 =
V_172 ;
else
V_166 . V_167 . V_171 =
V_173 ;
}
V_27 = F_62 ( & V_166 , V_160 , sizeof( V_160 ) ) ;
if ( V_27 < 0 )
return false ;
return F_55 ( V_1 , V_174 ,
V_175 ,
V_160 , sizeof( V_160 ) ) ;
}
static bool F_63 ( struct V_1 * V_1 )
{
struct V_176 V_177 ;
T_7 V_178 ;
V_178 = 1 << V_1 -> V_179 ;
memset ( & V_177 , 0 , sizeof( V_177 ) ) ;
memcpy ( & V_177 , & V_178 , V_87 ( sizeof( V_177 ) , sizeof( V_178 ) ) ) ;
F_34 ( sizeof( V_177 ) != 6 ) ;
return F_30 ( V_1 ,
V_180 ,
& V_177 , sizeof( V_177 ) ) ;
}
static bool
F_64 ( struct V_1 * V_1 ,
const struct V_54 * V_55 )
{
struct V_90 V_181 ;
if ( ! F_39 ( V_1 ,
V_1 -> V_182 ) )
return false ;
F_48 ( & V_181 , V_55 ) ;
if ( ! F_43 ( V_1 , & V_181 ) )
return false ;
return true ;
}
static bool
F_65 ( struct V_1 * V_1 ,
const struct V_54 * V_55 ,
struct V_54 * V_159 )
{
struct V_90 V_183 ;
if ( ! F_32 ( V_1 ) )
return false ;
if ( ! F_45 ( V_1 ,
V_55 -> clock / 10 ,
V_55 -> V_103 ,
V_55 -> V_104 ) )
return false ;
if ( ! F_46 ( V_1 ,
& V_183 ) )
return false ;
F_49 ( V_159 , & V_183 ) ;
V_1 -> V_184 = V_183 . V_93 . V_185 ;
return true ;
}
static void F_66 ( struct V_186 * V_187 )
{
unsigned V_188 = V_187 -> V_189 ;
struct V_190 * clock = & V_187 -> V_190 ;
if ( V_188 >= 100000 && V_188 < 140500 ) {
clock -> V_191 = 2 ;
clock -> V_192 = 10 ;
clock -> V_193 = 3 ;
clock -> V_194 = 16 ;
clock -> V_195 = 8 ;
} else if ( V_188 >= 140500 && V_188 <= 200000 ) {
clock -> V_191 = 1 ;
clock -> V_192 = 10 ;
clock -> V_193 = 6 ;
clock -> V_194 = 12 ;
clock -> V_195 = 8 ;
} else {
F_67 ( 1 , L_15 , V_188 ) ;
}
V_187 -> V_196 = true ;
}
static bool F_68 ( struct V_2 * V_3 ,
struct V_186 * V_187 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_54 * V_159 = & V_187 -> V_4 . V_159 ;
struct V_54 * V_55 = & V_187 -> V_4 . V_55 ;
F_14 ( L_16 ) ;
V_187 -> V_197 = 8 * 3 ;
if ( F_69 ( V_3 -> V_4 . V_10 ) )
V_187 -> V_198 = true ;
if ( V_1 -> V_199 ) {
if ( ! F_64 ( V_1 , V_55 ) )
return false ;
( void ) F_65 ( V_1 ,
V_55 ,
V_159 ) ;
V_187 -> V_200 = true ;
} else if ( V_1 -> V_101 ) {
if ( ! F_64 ( V_1 ,
V_1 -> V_102 ) )
return false ;
( void ) F_65 ( V_1 ,
V_55 ,
V_159 ) ;
}
V_187 -> V_201 =
F_28 ( V_159 ) ;
V_187 -> V_202 = V_1 -> V_203 ;
if ( V_1 -> V_204 ) {
if ( V_187 -> V_202 &&
F_70 ( V_159 ) > 1 )
V_187 -> V_170 = true ;
} else {
if ( V_187 -> V_202 &&
V_1 -> V_205 == V_206 )
V_187 -> V_170 = true ;
}
if ( V_1 -> V_199 )
F_66 ( V_187 ) ;
return true ;
}
static void F_71 ( struct V_2 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_4 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_164 * V_163 = F_59 ( V_2 -> V_4 . V_163 ) ;
struct V_54 * V_159 =
& V_163 -> V_169 -> V_4 . V_159 ;
struct V_54 * V_55 = & V_163 -> V_169 -> V_4 . V_55 ;
struct V_1 * V_1 = F_1 ( V_2 ) ;
T_1 V_207 ;
struct V_208 V_209 ;
struct V_90 V_183 , V_181 ;
int V_210 ;
if ( ! V_55 )
return;
V_209 . V_211 = V_1 -> V_182 ;
V_209 . V_212 = 0 ;
F_30 ( V_1 ,
V_213 ,
& V_209 , sizeof( V_209 ) ) ;
if ( ! F_39 ( V_1 ,
V_1 -> V_182 ) )
return;
if ( V_1 -> V_101 )
F_48 ( & V_181 ,
V_1 -> V_102 ) ;
else
F_48 ( & V_181 , V_55 ) ;
if ( ! F_43 ( V_1 , & V_181 ) )
F_72 ( L_17 ,
F_20 ( V_1 ) ) ;
if ( ! F_32 ( V_1 ) )
return;
if ( V_163 -> V_169 -> V_202 ) {
F_53 ( V_1 , V_214 ) ;
F_54 ( V_1 ,
V_215 ) ;
F_57 ( V_1 , V_159 ) ;
} else
F_53 ( V_1 , V_216 ) ;
if ( V_1 -> V_199 &&
! F_63 ( V_1 ) )
return;
F_48 ( & V_183 , V_159 ) ;
if ( V_1 -> V_199 || V_1 -> V_101 )
V_183 . V_93 . V_185 = V_1 -> V_184 ;
if ( ! F_42 ( V_1 , & V_183 ) )
F_72 ( L_18 ,
F_20 ( V_1 ) ) ;
switch ( V_163 -> V_169 -> V_201 ) {
default:
F_67 ( 1 , L_19 ) ;
case 1 : V_210 = V_217 ; break;
case 2 : V_210 = V_218 ; break;
case 4 : V_210 = V_219 ; break;
}
if ( ! F_47 ( V_1 , V_210 ) )
return;
if ( F_73 ( V_10 ) -> V_220 >= 4 ) {
V_207 = V_221 | V_222 ;
if ( ! F_69 ( V_10 ) && V_163 -> V_169 -> V_170 )
V_207 |= V_206 ;
if ( F_73 ( V_10 ) -> V_220 < 5 )
V_207 |= V_223 ;
} else {
V_207 = F_11 ( V_1 -> V_17 ) ;
switch ( V_1 -> V_17 ) {
case V_19 :
V_207 &= V_224 ;
break;
case V_20 :
V_207 &= V_225 ;
break;
}
V_207 |= ( 9 << 19 ) | V_223 ;
}
if ( F_74 ( V_10 ) >= V_226 )
V_207 |= F_75 ( V_163 -> V_227 ) ;
else
V_207 |= F_76 ( V_163 -> V_227 ) ;
if ( V_1 -> V_228 )
V_207 |= V_229 ;
if ( F_73 ( V_10 ) -> V_220 >= 4 ) {
} else if ( F_77 ( V_10 ) || F_78 ( V_10 ) || F_79 ( V_10 ) ) {
} else {
V_207 |= ( V_163 -> V_169 -> V_201 - 1 )
<< V_230 ;
}
if ( V_183 . V_93 . V_185 & V_231 &&
F_73 ( V_10 ) -> V_220 < 5 )
V_207 |= V_232 ;
F_7 ( V_1 , V_207 ) ;
}
static bool F_80 ( struct V_233 * V_6 )
{
struct V_7 * V_7 =
F_5 ( & V_6 -> V_4 ) ;
struct V_1 * V_1 = F_3 ( & V_6 -> V_4 ) ;
T_3 V_234 = 0 ;
F_36 ( V_1 , & V_234 ) ;
if ( V_234 & V_7 -> V_235 )
return true ;
else
return false ;
}
static bool F_81 ( struct V_2 * V_3 ,
enum V_227 * V_227 )
{
struct V_9 * V_10 = V_3 -> V_4 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
T_3 V_234 = 0 ;
T_1 V_154 ;
V_154 = F_11 ( V_1 -> V_17 ) ;
F_36 ( V_1 , & V_234 ) ;
if ( ! ( V_154 & V_236 ) && ( V_234 == 0 ) )
return false ;
if ( F_82 ( V_10 ) )
* V_227 = F_83 ( V_154 ) ;
else
* V_227 = F_84 ( V_154 ) ;
return true ;
}
static void F_85 ( struct V_2 * V_3 ,
struct V_186 * V_187 )
{
struct V_9 * V_10 = V_3 -> V_4 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_90 V_91 ;
int V_237 = 0 ;
int V_188 ;
T_1 V_26 = 0 , V_207 ;
T_2 V_8 ;
bool V_30 ;
V_207 = F_11 ( V_1 -> V_17 ) ;
V_30 = F_44 ( V_1 , & V_91 ) ;
if ( ! V_30 ) {
F_86 ( L_20 ) ;
V_187 -> V_238 |= V_239 ;
} else {
if ( V_91 . V_93 . V_133 & V_137 )
V_26 |= V_136 ;
else
V_26 |= V_142 ;
if ( V_91 . V_93 . V_133 & V_139 )
V_26 |= V_138 ;
else
V_26 |= V_143 ;
}
V_187 -> V_4 . V_159 . V_26 |= V_26 ;
if ( F_87 ( V_10 ) || F_88 ( V_10 ) ) {
V_187 -> V_201 =
( ( V_207 & V_240 )
>> V_230 ) + 1 ;
}
V_188 = V_187 -> V_189 ;
if ( V_187 -> V_201 )
V_188 /= V_187 -> V_201 ;
if ( F_69 ( V_10 ) )
F_89 ( V_187 , V_188 ) ;
V_187 -> V_4 . V_159 . V_241 = V_188 ;
if ( F_31 ( V_1 , V_242 ,
& V_8 , 1 ) ) {
switch ( V_8 ) {
case V_217 :
V_237 = 1 ;
break;
case V_218 :
V_237 = 2 ;
break;
case V_219 :
V_237 = 4 ;
break;
}
}
if ( V_207 & V_206 )
V_187 -> V_170 = true ;
if ( F_31 ( V_1 , V_243 ,
& V_8 , 1 ) ) {
if ( V_8 == V_214 )
V_187 -> V_202 = true ;
}
F_67 ( V_237 != V_187 -> V_201 ,
L_21 ,
V_187 -> V_201 , V_237 ) ;
}
static void F_90 ( struct V_2 * V_3 )
{
struct V_11 * V_12 = V_3 -> V_4 . V_10 -> V_13 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_164 * V_163 = F_59 ( V_3 -> V_4 . V_163 ) ;
T_1 V_244 ;
F_35 ( V_1 , 0 ) ;
if ( 0 )
F_37 ( V_1 ,
V_79 ) ;
V_244 = F_11 ( V_1 -> V_17 ) ;
V_244 &= ~ V_236 ;
F_7 ( V_1 , V_244 ) ;
if ( F_10 ( V_12 ) && V_163 -> V_227 == V_245 ) {
V_244 &= ~ V_246 ;
V_244 |= V_236 ;
F_7 ( V_1 , V_244 ) ;
V_244 &= ~ V_236 ;
F_7 ( V_1 , V_244 ) ;
}
}
static void F_91 ( struct V_2 * V_3 )
{
}
static void F_92 ( struct V_2 * V_3 )
{
F_90 ( V_3 ) ;
}
static void F_93 ( struct V_2 * V_3 )
{
struct V_9 * V_10 = V_3 -> V_4 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_164 * V_164 = F_59 ( V_3 -> V_4 . V_163 ) ;
T_1 V_244 ;
bool V_247 , V_248 ;
int V_16 ;
bool V_249 ;
V_244 = F_11 ( V_1 -> V_17 ) ;
V_244 |= V_236 ;
F_7 ( V_1 , V_244 ) ;
for ( V_16 = 0 ; V_16 < 2 ; V_16 ++ )
F_94 ( V_10 , V_164 -> V_227 ) ;
V_249 = F_33 ( V_1 , & V_247 , & V_248 ) ;
if ( V_249 && ! V_247 ) {
F_14 ( L_22
L_23 , F_20 ( V_1 ) ) ;
}
if ( 0 )
F_37 ( V_1 ,
V_74 ) ;
F_35 ( V_1 , V_1 -> V_182 ) ;
}
static enum V_250
F_95 ( struct V_5 * V_6 ,
struct V_54 * V_55 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
if ( V_55 -> V_26 & V_251 )
return V_252 ;
if ( V_1 -> V_253 > V_55 -> clock )
return V_254 ;
if ( V_1 -> V_255 < V_55 -> clock )
return V_256 ;
if ( V_1 -> V_101 ) {
if ( V_55 -> V_103 > V_1 -> V_102 -> V_103 )
return V_257 ;
if ( V_55 -> V_104 > V_1 -> V_102 -> V_104 )
return V_257 ;
}
return V_258 ;
}
static bool F_96 ( struct V_1 * V_1 , struct V_259 * V_260 )
{
F_34 ( sizeof( * V_260 ) != 8 ) ;
if ( ! F_31 ( V_1 ,
V_261 ,
V_260 , sizeof( * V_260 ) ) )
return false ;
F_14 ( L_24
L_25
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
L_36 ,
V_260 -> V_262 ,
V_260 -> V_263 ,
V_260 -> V_264 ,
V_260 -> V_265 ,
V_260 -> V_266 ,
V_260 -> V_267 ,
V_260 -> V_268 ,
V_260 -> V_269 ,
V_260 -> V_270 ,
V_260 -> V_271 ,
V_260 -> V_272 ,
V_260 -> V_273 ) ;
return true ;
}
static T_4 F_97 ( struct V_1 * V_1 )
{
struct V_9 * V_10 = V_1 -> V_4 . V_4 . V_10 ;
T_4 V_274 ;
if ( ! F_98 ( V_10 ) )
return 0 ;
if ( F_77 ( V_10 ) || F_78 ( V_10 ) )
return 0 ;
if ( ! F_31 ( V_1 , V_275 ,
& V_274 , sizeof( V_274 ) ) )
return 0 ;
return V_274 ;
}
static void F_99 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
F_21 ( V_1 , V_276 ,
& V_1 -> V_277 , 2 ) ;
}
static bool
F_100 ( struct V_1 * V_1 )
{
return F_101 ( V_1 -> V_260 . V_273 ) > 1 ;
}
static struct V_278 *
F_102 ( struct V_5 * V_6 )
{
struct V_1 * V_279 = F_3 ( V_6 ) ;
return F_103 ( V_6 , & V_279 -> V_280 ) ;
}
static struct V_278 *
F_104 ( struct V_5 * V_6 )
{
struct V_11 * V_12 = V_6 -> V_10 -> V_13 ;
return F_103 ( V_6 ,
F_105 ( V_12 ,
V_12 -> V_281 . V_282 ) ) ;
}
static enum V_283
F_106 ( struct V_5 * V_6 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
enum V_283 V_38 ;
struct V_278 * V_278 ;
V_278 = F_102 ( V_6 ) ;
if ( V_278 == NULL && F_100 ( V_1 ) ) {
T_2 V_280 , V_284 = V_1 -> V_56 ;
for ( V_280 = V_1 -> V_56 >> 1 ; V_280 > 1 ; V_280 >>= 1 ) {
V_1 -> V_56 = V_280 ;
V_278 = F_102 ( V_6 ) ;
if ( V_278 )
break;
}
if ( V_278 == NULL )
V_1 -> V_56 = V_284 ;
}
if ( V_278 == NULL )
V_278 = F_104 ( V_6 ) ;
V_38 = V_285 ;
if ( V_278 != NULL ) {
if ( V_278 -> V_286 & V_287 ) {
V_38 = V_288 ;
if ( V_1 -> V_289 ) {
V_1 -> V_203 = F_107 ( V_278 ) ;
V_1 -> V_228 = F_108 ( V_278 ) ;
V_1 -> V_168 =
F_109 ( V_278 ) ;
}
} else
V_38 = V_290 ;
F_24 ( V_278 ) ;
}
if ( V_38 == V_288 ) {
struct V_7 * V_7 = F_5 ( V_6 ) ;
if ( V_7 -> V_291 != V_292 )
V_1 -> V_228 = ( V_7 -> V_291 == V_293 ) ;
}
return V_38 ;
}
static bool
F_110 ( struct V_7 * V_279 ,
struct V_278 * V_278 )
{
bool V_294 = ! ! ( V_278 -> V_286 & V_287 ) ;
bool V_295 = ! ! F_111 ( V_279 ) ;
F_14 ( L_37 ,
V_295 , V_294 ) ;
return V_295 == V_294 ;
}
static enum V_283
F_112 ( struct V_5 * V_6 , bool V_296 )
{
T_4 V_44 ;
struct V_1 * V_1 = F_3 ( V_6 ) ;
struct V_7 * V_7 = F_5 ( V_6 ) ;
enum V_283 V_30 ;
F_14 ( L_38 ,
V_6 -> V_4 . V_297 , V_6 -> V_37 ) ;
if ( ! F_31 ( V_1 ,
V_298 ,
& V_44 , 2 ) )
return V_285 ;
F_14 ( L_39 ,
V_44 & 0xff , V_44 >> 8 ,
V_7 -> V_235 ) ;
if ( V_44 == 0 )
return V_290 ;
V_1 -> V_182 = V_44 ;
V_1 -> V_203 = false ;
V_1 -> V_228 = false ;
V_1 -> V_168 = false ;
if ( ( V_7 -> V_235 & V_44 ) == 0 )
V_30 = V_290 ;
else if ( F_113 ( V_7 ) )
V_30 = F_106 ( V_6 ) ;
else {
struct V_278 * V_278 ;
V_278 = F_102 ( V_6 ) ;
if ( V_278 == NULL )
V_278 = F_104 ( V_6 ) ;
if ( V_278 != NULL ) {
if ( F_110 ( V_7 ,
V_278 ) )
V_30 = V_288 ;
else
V_30 = V_290 ;
F_24 ( V_278 ) ;
} else
V_30 = V_288 ;
}
if ( V_30 == V_288 ) {
V_1 -> V_199 = false ;
V_1 -> V_101 = false ;
if ( V_44 & V_299 )
V_1 -> V_199 = true ;
if ( V_44 & V_300 )
V_1 -> V_101 = V_1 -> V_102 != NULL ;
}
return V_30 ;
}
static void F_114 ( struct V_5 * V_6 )
{
struct V_278 * V_278 ;
F_14 ( L_38 ,
V_6 -> V_4 . V_297 , V_6 -> V_37 ) ;
V_278 = F_102 ( V_6 ) ;
if ( V_278 == NULL )
V_278 = F_104 ( V_6 ) ;
if ( V_278 != NULL ) {
if ( F_110 ( F_5 ( V_6 ) ,
V_278 ) ) {
F_115 ( V_6 , V_278 ) ;
F_116 ( V_6 , V_278 ) ;
}
F_24 ( V_278 ) ;
}
}
static void F_117 ( struct V_5 * V_6 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
struct V_301 V_302 ;
T_7 V_303 = 0 , V_178 = 0 ;
int V_16 ;
F_14 ( L_38 ,
V_6 -> V_4 . V_297 , V_6 -> V_37 ) ;
V_178 = 1 << V_1 -> V_179 ;
memcpy ( & V_302 , & V_178 ,
V_87 ( sizeof( V_178 ) , sizeof( struct V_301 ) ) ) ;
if ( ! F_39 ( V_1 , V_1 -> V_182 ) )
return;
F_34 ( sizeof( V_302 ) != 3 ) ;
if ( ! F_21 ( V_1 ,
V_304 ,
& V_302 , sizeof( V_302 ) ) )
return;
if ( ! F_25 ( V_1 , & V_303 , 3 ) )
return;
for ( V_16 = 0 ; V_16 < F_18 ( V_305 ) ; V_16 ++ )
if ( V_303 & ( 1 << V_16 ) ) {
struct V_54 * V_306 ;
V_306 = F_118 ( V_6 -> V_10 ,
& V_305 [ V_16 ] ) ;
if ( V_306 )
F_119 ( V_6 , V_306 ) ;
}
}
static void F_120 ( struct V_5 * V_6 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
struct V_11 * V_12 = V_6 -> V_10 -> V_13 ;
struct V_54 * V_307 ;
F_14 ( L_38 ,
V_6 -> V_4 . V_297 , V_6 -> V_37 ) ;
if ( V_12 -> V_281 . V_308 != NULL ) {
V_307 = F_118 ( V_6 -> V_10 ,
V_12 -> V_281 . V_308 ) ;
if ( V_307 != NULL ) {
V_307 -> type = ( V_309 |
V_310 ) ;
F_119 ( V_6 , V_307 ) ;
}
}
F_121 ( V_6 , & V_1 -> V_280 ) ;
F_122 (newmode, &connector->probed_modes, head) {
if ( V_307 -> type & V_309 ) {
V_1 -> V_102 =
F_118 ( V_6 -> V_10 , V_307 ) ;
V_1 -> V_101 = true ;
break;
}
}
}
static int F_123 ( struct V_5 * V_6 )
{
struct V_7 * V_7 = F_5 ( V_6 ) ;
if ( F_124 ( V_7 ) )
F_117 ( V_6 ) ;
else if ( F_125 ( V_7 ) )
F_120 ( V_6 ) ;
else
F_114 ( V_6 ) ;
return ! F_126 ( & V_6 -> V_311 ) ;
}
static void F_127 ( struct V_5 * V_6 )
{
struct V_7 * V_7 = F_5 ( V_6 ) ;
F_128 ( V_6 ) ;
F_24 ( V_7 ) ;
}
static bool F_129 ( struct V_5 * V_6 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
struct V_278 * V_278 ;
bool V_312 = false ;
if ( ! V_1 -> V_289 )
return false ;
V_278 = F_102 ( V_6 ) ;
if ( V_278 != NULL && V_278 -> V_286 & V_287 )
V_312 = F_108 ( V_278 ) ;
F_24 ( V_278 ) ;
return V_312 ;
}
static int
F_130 ( struct V_5 * V_6 ,
struct V_313 * V_314 ,
T_8 V_8 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
struct V_7 * V_7 = F_5 ( V_6 ) ;
struct V_11 * V_12 = V_6 -> V_10 -> V_13 ;
T_4 V_315 ;
T_5 V_32 ;
int V_30 ;
V_30 = F_131 ( & V_6 -> V_4 , V_314 , V_8 ) ;
if ( V_30 )
return V_30 ;
if ( V_314 == V_12 -> V_316 ) {
int V_16 = V_8 ;
bool V_312 ;
if ( V_16 == V_7 -> V_291 )
return 0 ;
V_7 -> V_291 = V_16 ;
if ( V_16 == V_292 )
V_312 = F_129 ( V_6 ) ;
else
V_312 = ( V_16 == V_293 ) ;
if ( V_312 == V_1 -> V_228 )
return 0 ;
V_1 -> V_228 = V_312 ;
goto V_317;
}
if ( V_314 == V_12 -> V_318 ) {
bool V_319 = V_1 -> V_204 ;
T_7 V_320 = V_1 -> V_205 ;
switch ( V_8 ) {
case V_321 :
V_1 -> V_204 = true ;
break;
case V_322 :
V_1 -> V_204 = false ;
V_1 -> V_205 = 0 ;
break;
case V_323 :
V_1 -> V_204 = false ;
V_1 -> V_205 = V_206 ;
break;
default:
return - V_324 ;
}
if ( V_319 == V_1 -> V_204 &&
V_320 == V_1 -> V_205 )
return 0 ;
goto V_317;
}
#define F_132 ( V_37 , T_9 ) \
if (intel_sdvo_connector->name == property) { \
if (intel_sdvo_connector->cur_##name == temp_value) return 0; \
if (intel_sdvo_connector->max_##name < temp_value) return -EINVAL; \
cmd = SDVO_CMD_SET_##NAME; \
intel_sdvo_connector->cur_##name = temp_value; \
goto set_value; \
}
if ( V_314 == V_7 -> V_325 ) {
if ( V_8 >= V_326 )
return - V_324 ;
if ( V_1 -> V_179 ==
V_7 -> V_327 [ V_8 ] )
return 0 ;
V_1 -> V_179 = V_7 -> V_327 [ V_8 ] ;
goto V_317;
} else if ( F_133 ( V_7 ) ) {
V_315 = V_8 ;
if ( V_7 -> V_328 == V_314 ) {
F_131 ( & V_6 -> V_4 ,
V_7 -> V_329 , V_8 ) ;
if ( V_7 -> V_330 == V_315 )
return 0 ;
V_7 -> V_330 = V_315 ;
V_7 -> V_331 = V_315 ;
V_315 = V_7 -> V_332 -
V_7 -> V_330 ;
V_32 = V_333 ;
goto V_334;
} else if ( V_7 -> V_329 == V_314 ) {
F_131 ( & V_6 -> V_4 ,
V_7 -> V_328 , V_8 ) ;
if ( V_7 -> V_331 == V_315 )
return 0 ;
V_7 -> V_330 = V_315 ;
V_7 -> V_331 = V_315 ;
V_315 = V_7 -> V_332 -
V_7 -> V_330 ;
V_32 = V_333 ;
goto V_334;
} else if ( V_7 -> V_335 == V_314 ) {
F_131 ( & V_6 -> V_4 ,
V_7 -> V_336 , V_8 ) ;
if ( V_7 -> V_337 == V_315 )
return 0 ;
V_7 -> V_337 = V_315 ;
V_7 -> V_338 = V_315 ;
V_315 = V_7 -> V_339 -
V_7 -> V_337 ;
V_32 = V_340 ;
goto V_334;
} else if ( V_7 -> V_336 == V_314 ) {
F_131 ( & V_6 -> V_4 ,
V_7 -> V_335 , V_8 ) ;
if ( V_7 -> V_338 == V_315 )
return 0 ;
V_7 -> V_337 = V_315 ;
V_7 -> V_338 = V_315 ;
V_315 = V_7 -> V_339 -
V_7 -> V_337 ;
V_32 = V_340 ;
goto V_334;
}
F_132 (hpos, HPOS)
F_132 (vpos, VPOS)
F_132 (saturation, SATURATION)
F_132 (contrast, CONTRAST)
F_132 (hue, HUE)
F_132 (brightness, BRIGHTNESS)
F_132 (sharpness, SHARPNESS)
F_132 (flicker_filter, FLICKER_FILTER)
F_132 (flicker_filter_2d, FLICKER_FILTER_2D)
F_132 (flicker_filter_adaptive, FLICKER_FILTER_ADAPTIVE)
F_132 (tv_chroma_filter, TV_CHROMA_FILTER)
F_132 (tv_luma_filter, TV_LUMA_FILTER)
F_132 (dot_crawl, DOT_CRAWL)
}
return - V_324 ;
V_334:
if ( ! F_30 ( V_1 , V_32 , & V_315 , 2 ) )
return - V_341 ;
V_317:
if ( V_1 -> V_4 . V_4 . V_163 )
F_134 ( V_1 -> V_4 . V_4 . V_163 ) ;
return 0 ;
#undef F_132
}
static void F_135 ( struct V_342 * V_3 )
{
struct V_1 * V_1 = F_1 ( F_136 ( V_3 ) ) ;
if ( V_1 -> V_102 != NULL )
F_137 ( V_3 -> V_10 ,
V_1 -> V_102 ) ;
F_138 ( & V_1 -> V_280 ) ;
F_139 ( V_3 ) ;
}
static void
F_140 ( struct V_1 * V_279 )
{
T_4 V_343 = 0 ;
unsigned int V_344 ;
switch ( V_279 -> V_345 ) {
case V_346 :
V_343 |= V_346 ;
case V_347 :
V_343 |= V_347 ;
case V_348 :
V_343 |= V_348 ;
case V_349 :
V_343 |= V_349 ;
case V_350 :
V_343 |= V_350 ;
case V_351 :
V_343 |= V_351 ;
break;
}
V_343 &= V_279 -> V_260 . V_273 ;
V_344 = F_101 ( V_343 ) ;
if ( V_344 > 3 )
V_344 = 3 ;
V_279 -> V_56 = 1 << V_344 ;
}
static void
F_141 ( struct V_11 * V_12 ,
struct V_1 * V_279 , T_1 V_352 )
{
struct V_353 * V_354 ;
if ( V_279 -> V_355 )
V_354 = & ( V_12 -> V_356 [ 0 ] ) ;
else
V_354 = & ( V_12 -> V_356 [ 1 ] ) ;
if ( V_354 -> V_357 )
V_279 -> V_56 = 1 << ( ( V_354 -> V_358 & 0xf0 ) >> 4 ) ;
else
F_140 ( V_279 ) ;
}
static void
F_142 ( struct V_11 * V_12 ,
struct V_1 * V_279 , T_1 V_352 )
{
struct V_353 * V_354 ;
T_2 V_359 ;
if ( V_279 -> V_355 )
V_354 = & V_12 -> V_356 [ 0 ] ;
else
V_354 = & V_12 -> V_356 [ 1 ] ;
if ( V_354 -> V_357 &&
F_143 ( V_12 , V_354 -> V_360 ) )
V_359 = V_354 -> V_360 ;
else
V_359 = V_361 ;
V_279 -> V_31 = F_105 ( V_12 , V_359 ) ;
F_144 ( V_279 -> V_31 , true ) ;
}
static void
F_145 ( struct V_1 * V_279 )
{
F_144 ( V_279 -> V_31 , false ) ;
}
static bool
F_146 ( struct V_1 * V_1 , int V_362 )
{
return F_52 ( V_1 ) ;
}
static T_2
F_147 ( struct V_9 * V_10 , struct V_1 * V_279 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_353 * V_363 , * V_364 ;
if ( V_279 -> V_355 ) {
V_363 = & V_12 -> V_356 [ 0 ] ;
V_364 = & V_12 -> V_356 [ 1 ] ;
} else {
V_363 = & V_12 -> V_356 [ 1 ] ;
V_364 = & V_12 -> V_356 [ 0 ] ;
}
if ( V_363 -> V_25 )
return V_363 -> V_25 ;
if ( V_364 -> V_25 ) {
if ( V_364 -> V_25 == 0x70 )
return 0x72 ;
else
return 0x70 ;
}
if ( V_279 -> V_355 )
return 0x70 ;
else
return 0x72 ;
}
static void
F_148 ( struct V_233 * V_233 )
{
struct V_5 * V_5 ;
struct V_1 * V_365 ;
V_5 = & V_233 -> V_4 ;
V_365 = F_3 ( & V_233 -> V_4 ) ;
F_149 ( & V_5 -> V_366 -> V_367 ,
V_365 -> V_280 . V_10 . V_367 . V_37 ) ;
F_150 ( V_233 ) ;
}
static int
F_151 ( struct V_7 * V_6 ,
struct V_1 * V_3 )
{
struct V_5 * V_5 ;
int V_30 ;
V_5 = & V_6 -> V_4 . V_4 ;
V_30 = F_152 ( V_3 -> V_4 . V_4 . V_10 ,
V_5 ,
& V_368 ,
V_6 -> V_4 . V_4 . V_369 ) ;
if ( V_30 < 0 )
return V_30 ;
F_153 ( V_5 ,
& V_370 ) ;
V_6 -> V_4 . V_4 . V_371 = 1 ;
V_6 -> V_4 . V_4 . V_372 = 0 ;
V_6 -> V_4 . V_4 . V_373 . V_374 = V_375 ;
V_6 -> V_4 . V_376 = F_80 ;
V_6 -> V_4 . V_377 = F_148 ;
F_154 ( & V_6 -> V_4 , & V_3 -> V_4 ) ;
V_30 = F_155 ( V_5 ) ;
if ( V_30 < 0 )
goto V_378;
V_30 = F_156 ( & V_5 -> V_366 -> V_367 ,
& V_3 -> V_280 . V_10 . V_367 ,
V_3 -> V_280 . V_10 . V_367 . V_37 ) ;
if ( V_30 < 0 )
goto V_379;
return 0 ;
V_379:
F_157 ( V_5 ) ;
V_378:
F_128 ( V_5 ) ;
return V_30 ;
}
static void
F_158 ( struct V_1 * V_1 ,
struct V_7 * V_6 )
{
struct V_9 * V_10 = V_6 -> V_4 . V_4 . V_10 ;
F_159 ( & V_6 -> V_4 . V_4 ) ;
if ( F_73 ( V_10 ) -> V_220 >= 4 && F_160 ( V_10 ) ) {
F_161 ( & V_6 -> V_4 . V_4 ) ;
V_1 -> V_204 = true ;
}
}
static struct V_7 * F_162 ( void )
{
struct V_7 * V_380 ;
V_380 = F_22 ( sizeof( * V_380 ) , V_39 ) ;
if ( ! V_380 )
return NULL ;
if ( F_163 ( & V_380 -> V_4 ) < 0 ) {
F_24 ( V_380 ) ;
return NULL ;
}
return V_380 ;
}
static bool
F_164 ( struct V_1 * V_1 , int V_362 )
{
struct V_342 * V_3 = & V_1 -> V_4 . V_4 ;
struct V_5 * V_6 ;
struct V_2 * V_2 = F_136 ( V_3 ) ;
struct V_233 * V_233 ;
struct V_7 * V_7 ;
F_14 ( L_40 , V_362 ) ;
V_7 = F_162 () ;
if ( ! V_7 )
return false ;
if ( V_362 == 0 ) {
V_1 -> V_345 |= V_349 ;
V_7 -> V_235 = V_349 ;
} else if ( V_362 == 1 ) {
V_1 -> V_345 |= V_348 ;
V_7 -> V_235 = V_348 ;
}
V_233 = & V_7 -> V_4 ;
V_6 = & V_233 -> V_4 ;
if ( F_97 ( V_1 ) &
V_7 -> V_235 ) {
V_1 -> V_277 |= V_7 -> V_235 ;
V_2 -> V_381 = F_99 ;
F_99 ( V_2 ) ;
} else {
V_233 -> V_382 = V_383 | V_384 ;
}
V_3 -> V_385 = V_386 ;
V_6 -> V_369 = V_387 ;
if ( F_146 ( V_1 , V_362 ) ) {
V_6 -> V_369 = V_388 ;
V_1 -> V_289 = true ;
}
if ( F_151 ( V_7 , V_1 ) < 0 ) {
F_24 ( V_7 ) ;
return false ;
}
if ( V_1 -> V_289 )
F_158 ( V_1 , V_7 ) ;
return true ;
}
static bool
F_165 ( struct V_1 * V_1 , int type )
{
struct V_342 * V_3 = & V_1 -> V_4 . V_4 ;
struct V_5 * V_6 ;
struct V_233 * V_233 ;
struct V_7 * V_7 ;
F_14 ( L_41 , type ) ;
V_7 = F_162 () ;
if ( ! V_7 )
return false ;
V_233 = & V_7 -> V_4 ;
V_6 = & V_233 -> V_4 ;
V_3 -> V_385 = V_389 ;
V_6 -> V_369 = V_390 ;
V_1 -> V_345 |= type ;
V_7 -> V_235 = type ;
V_1 -> V_199 = true ;
if ( F_151 ( V_7 , V_1 ) < 0 ) {
F_24 ( V_7 ) ;
return false ;
}
if ( ! F_166 ( V_1 , V_7 , type ) )
goto V_391;
if ( ! F_167 ( V_1 , V_7 ) )
goto V_391;
return true ;
V_391:
F_157 ( V_6 ) ;
F_127 ( V_6 ) ;
return false ;
}
static bool
F_168 ( struct V_1 * V_1 , int V_362 )
{
struct V_342 * V_3 = & V_1 -> V_4 . V_4 ;
struct V_5 * V_6 ;
struct V_233 * V_233 ;
struct V_7 * V_7 ;
F_14 ( L_42 , V_362 ) ;
V_7 = F_162 () ;
if ( ! V_7 )
return false ;
V_233 = & V_7 -> V_4 ;
V_6 = & V_233 -> V_4 ;
V_233 -> V_382 = V_383 ;
V_3 -> V_385 = V_392 ;
V_6 -> V_369 = V_393 ;
if ( V_362 == 0 ) {
V_1 -> V_345 |= V_351 ;
V_7 -> V_235 = V_351 ;
} else if ( V_362 == 1 ) {
V_1 -> V_345 |= V_350 ;
V_7 -> V_235 = V_350 ;
}
if ( F_151 ( V_7 , V_1 ) < 0 ) {
F_24 ( V_7 ) ;
return false ;
}
return true ;
}
static bool
F_169 ( struct V_1 * V_1 , int V_362 )
{
struct V_342 * V_3 = & V_1 -> V_4 . V_4 ;
struct V_5 * V_6 ;
struct V_233 * V_233 ;
struct V_7 * V_7 ;
F_14 ( L_43 , V_362 ) ;
V_7 = F_162 () ;
if ( ! V_7 )
return false ;
V_233 = & V_7 -> V_4 ;
V_6 = & V_233 -> V_4 ;
V_3 -> V_385 = V_394 ;
V_6 -> V_369 = V_395 ;
if ( V_362 == 0 ) {
V_1 -> V_345 |= V_347 ;
V_7 -> V_235 = V_347 ;
} else if ( V_362 == 1 ) {
V_1 -> V_345 |= V_346 ;
V_7 -> V_235 = V_346 ;
}
if ( F_151 ( V_7 , V_1 ) < 0 ) {
F_24 ( V_7 ) ;
return false ;
}
if ( ! F_167 ( V_1 , V_7 ) )
goto V_391;
return true ;
V_391:
F_157 ( V_6 ) ;
F_127 ( V_6 ) ;
return false ;
}
static bool
F_170 ( struct V_1 * V_1 , T_4 V_26 )
{
V_1 -> V_199 = false ;
V_1 -> V_101 = false ;
if ( V_26 & V_349 )
if ( ! F_164 ( V_1 , 0 ) )
return false ;
if ( ( V_26 & V_396 ) == V_396 )
if ( ! F_164 ( V_1 , 1 ) )
return false ;
if ( V_26 & V_397 )
if ( ! F_165 ( V_1 , V_397 ) )
return false ;
if ( V_26 & V_398 )
if ( ! F_165 ( V_1 , V_398 ) )
return false ;
if ( V_26 & V_399 )
if ( ! F_165 ( V_1 , V_399 ) )
return false ;
if ( V_26 & V_351 )
if ( ! F_168 ( V_1 , 0 ) )
return false ;
if ( ( V_26 & V_400 ) == V_400 )
if ( ! F_168 ( V_1 , 1 ) )
return false ;
if ( V_26 & V_347 )
if ( ! F_169 ( V_1 , 0 ) )
return false ;
if ( ( V_26 & V_300 ) == V_300 )
if ( ! F_169 ( V_1 , 1 ) )
return false ;
if ( ( V_26 & V_401 ) == 0 ) {
unsigned char V_402 [ 2 ] ;
V_1 -> V_345 = 0 ;
memcpy ( V_402 , & V_1 -> V_260 . V_273 , 2 ) ;
F_14 ( L_44 ,
F_20 ( V_1 ) ,
V_402 [ 0 ] , V_402 [ 1 ] ) ;
return false ;
}
V_1 -> V_4 . V_403 = ( 1 << 0 ) | ( 1 << 1 ) | ( 1 << 2 ) ;
return true ;
}
static void F_171 ( struct V_1 * V_1 )
{
struct V_9 * V_10 = V_1 -> V_4 . V_4 . V_10 ;
struct V_5 * V_6 , * V_154 ;
F_172 (connector, tmp,
&dev->mode_config.connector_list, head) {
if ( F_4 ( V_6 ) == & V_1 -> V_4 ) {
F_157 ( V_6 ) ;
F_127 ( V_6 ) ;
}
}
}
static bool F_166 ( struct V_1 * V_1 ,
struct V_7 * V_7 ,
int type )
{
struct V_9 * V_10 = V_1 -> V_4 . V_4 . V_10 ;
struct V_176 V_177 ;
T_7 V_178 , V_16 ;
if ( ! F_39 ( V_1 , type ) )
return false ;
F_34 ( sizeof( V_177 ) != 6 ) ;
if ( ! F_31 ( V_1 ,
V_404 ,
& V_177 , sizeof( V_177 ) ) )
return false ;
memcpy ( & V_178 , & V_177 , V_87 ( sizeof( V_178 ) , sizeof( V_177 ) ) ) ;
if ( V_178 == 0 )
return false ;
V_7 -> V_405 = 0 ;
for ( V_16 = 0 ; V_16 < V_326 ; V_16 ++ )
if ( V_178 & ( 1 << V_16 ) )
V_7 -> V_327 [ V_7 -> V_405 ++ ] = V_16 ;
V_7 -> V_325 =
F_173 ( V_10 , V_406 ,
L_45 , V_7 -> V_405 ) ;
if ( ! V_7 -> V_325 )
return false ;
for ( V_16 = 0 ; V_16 < V_7 -> V_405 ; V_16 ++ )
F_174 (
V_7 -> V_325 , V_16 ,
V_16 , V_407 [ V_7 -> V_327 [ V_16 ] ] ) ;
V_1 -> V_179 = V_7 -> V_327 [ 0 ] ;
F_175 ( & V_7 -> V_4 . V_4 . V_4 ,
V_7 -> V_325 , 0 ) ;
return true ;
}
static bool
F_176 ( struct V_1 * V_1 ,
struct V_7 * V_7 ,
struct V_408 V_409 )
{
struct V_9 * V_10 = V_1 -> V_4 . V_4 . V_10 ;
struct V_5 * V_6 = & V_7 -> V_4 . V_4 ;
T_4 V_44 , V_410 [ 2 ] ;
if ( V_409 . V_411 ) {
if ( ! F_31 ( V_1 ,
V_412 ,
& V_410 , 4 ) )
return false ;
if ( ! F_31 ( V_1 ,
V_413 ,
& V_44 , 2 ) )
return false ;
V_7 -> V_332 = V_410 [ 0 ] ;
V_7 -> V_330 = V_410 [ 0 ] - V_44 ;
V_7 -> V_331 = V_7 -> V_330 ;
V_7 -> V_328 =
F_177 ( V_10 , 0 , L_46 , 0 , V_410 [ 0 ] ) ;
if ( ! V_7 -> V_328 )
return false ;
F_175 ( & V_6 -> V_4 ,
V_7 -> V_328 ,
V_7 -> V_330 ) ;
V_7 -> V_329 =
F_177 ( V_10 , 0 , L_47 , 0 , V_410 [ 0 ] ) ;
if ( ! V_7 -> V_329 )
return false ;
F_175 ( & V_6 -> V_4 ,
V_7 -> V_329 ,
V_7 -> V_331 ) ;
F_14 ( L_48
L_49 ,
V_410 [ 0 ] , V_410 [ 1 ] , V_44 ) ;
}
if ( V_409 . V_414 ) {
if ( ! F_31 ( V_1 ,
V_415 ,
& V_410 , 4 ) )
return false ;
if ( ! F_31 ( V_1 ,
V_416 ,
& V_44 , 2 ) )
return false ;
V_7 -> V_339 = V_410 [ 0 ] ;
V_7 -> V_337 = V_410 [ 0 ] - V_44 ;
V_7 -> V_338 = V_7 -> V_337 ;
V_7 -> V_335 =
F_177 ( V_10 , 0 ,
L_50 , 0 , V_410 [ 0 ] ) ;
if ( ! V_7 -> V_335 )
return false ;
F_175 ( & V_6 -> V_4 ,
V_7 -> V_335 ,
V_7 -> V_337 ) ;
V_7 -> V_336 =
F_177 ( V_10 , 0 ,
L_51 , 0 , V_410 [ 0 ] ) ;
if ( ! V_7 -> V_336 )
return false ;
F_175 ( & V_6 -> V_4 ,
V_7 -> V_336 ,
V_7 -> V_338 ) ;
F_14 ( L_52
L_49 ,
V_410 [ 0 ] , V_410 [ 1 ] , V_44 ) ;
}
F_178 ( V_417 , V_418 ) ;
F_178 ( V_419 , V_420 ) ;
F_178 ( V_421 , V_422 ) ;
F_178 ( V_423 , V_424 ) ;
F_178 ( V_425 , V_426 ) ;
F_178 ( V_427 , V_428 ) ;
F_178 ( V_429 , V_430 ) ;
F_178 ( V_431 , V_432 ) ;
F_178 ( V_433 , V_434 ) ;
F_178 ( V_435 , V_436 ) ;
F_178 ( V_437 , V_438 ) ;
F_178 ( V_439 , V_440 ) ;
if ( V_409 . V_441 ) {
if ( ! F_31 ( V_1 , V_442 , & V_44 , 2 ) )
return false ;
V_7 -> V_443 = 1 ;
V_7 -> V_444 = V_44 & 0x1 ;
V_7 -> V_441 =
F_177 ( V_10 , 0 , L_53 , 0 , 1 ) ;
if ( ! V_7 -> V_441 )
return false ;
F_175 ( & V_6 -> V_4 ,
V_7 -> V_441 ,
V_7 -> V_444 ) ;
F_14 ( L_54 , V_44 ) ;
}
return true ;
}
static bool
F_179 ( struct V_1 * V_1 ,
struct V_7 * V_7 ,
struct V_408 V_409 )
{
struct V_9 * V_10 = V_1 -> V_4 . V_4 . V_10 ;
struct V_5 * V_6 = & V_7 -> V_4 . V_4 ;
T_4 V_44 , V_410 [ 2 ] ;
F_178 ( V_429 , V_430 ) ;
return true ;
}
static bool F_167 ( struct V_1 * V_1 ,
struct V_7 * V_7 )
{
union {
struct V_408 V_303 ;
T_4 V_44 ;
} V_409 ;
F_34 ( sizeof( V_409 ) != 2 ) ;
V_409 . V_44 = 0 ;
F_31 ( V_1 ,
V_445 ,
& V_409 , sizeof( V_409 ) ) ;
if ( V_409 . V_44 == 0 ) {
F_14 ( L_55 ) ;
return true ;
}
if ( F_124 ( V_7 ) )
return F_176 ( V_1 , V_7 , V_409 . V_303 ) ;
else if ( F_125 ( V_7 ) )
return F_179 ( V_1 , V_7 , V_409 . V_303 ) ;
else
return true ;
}
static int F_180 ( struct V_446 * V_447 ,
struct V_23 * V_24 ,
int V_448 )
{
struct V_1 * V_279 = V_447 -> V_449 ;
if ( ! F_29 ( V_279 , V_279 -> V_56 ) )
return - V_341 ;
return V_279 -> V_31 -> V_450 -> V_451 ( V_279 -> V_31 , V_24 , V_448 ) ;
}
static T_1 F_181 ( struct V_446 * V_447 )
{
struct V_1 * V_279 = V_447 -> V_449 ;
return V_279 -> V_31 -> V_450 -> V_452 ( V_279 -> V_31 ) ;
}
static bool
F_182 ( struct V_1 * V_279 ,
struct V_9 * V_10 )
{
V_279 -> V_280 . V_453 = V_454 ;
V_279 -> V_280 . V_455 = V_456 ;
snprintf ( V_279 -> V_280 . V_37 , V_457 , L_56 ) ;
V_279 -> V_280 . V_10 . V_458 = & V_10 -> V_459 -> V_10 ;
V_279 -> V_280 . V_449 = V_279 ;
V_279 -> V_280 . V_450 = & V_460 ;
return F_183 ( & V_279 -> V_280 ) == 0 ;
}
bool F_184 ( struct V_9 * V_10 , T_7 V_17 , bool V_355 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_2 * V_2 ;
struct V_1 * V_1 ;
int V_16 ;
V_1 = F_22 ( sizeof( * V_1 ) , V_39 ) ;
if ( ! V_1 )
return false ;
V_1 -> V_17 = V_17 ;
V_1 -> V_355 = V_355 ;
V_1 -> V_25 = F_147 ( V_10 , V_1 ) >> 1 ;
F_142 ( V_12 , V_1 , V_17 ) ;
if ( ! F_182 ( V_1 , V_10 ) )
goto V_461;
V_2 = & V_1 -> V_4 ;
V_2 -> type = V_462 ;
F_185 ( V_10 , & V_2 -> V_4 , & V_463 , 0 ) ;
for ( V_16 = 0 ; V_16 < 0x40 ; V_16 ++ ) {
T_2 V_464 ;
if ( ! F_12 ( V_1 , V_16 , & V_464 ) ) {
F_14 ( L_57 ,
F_20 ( V_1 ) ) ;
goto V_391;
}
}
V_2 -> V_465 = F_68 ;
if ( F_69 ( V_10 ) ) {
V_2 -> V_466 = F_91 ;
V_2 -> V_467 = F_92 ;
} else {
V_2 -> V_466 = F_90 ;
}
V_2 -> V_468 = F_71 ;
V_2 -> V_469 = F_93 ;
V_2 -> V_376 = F_81 ;
V_2 -> V_470 = F_85 ;
if ( ! F_96 ( V_1 , & V_1 -> V_260 ) )
goto V_391;
if ( F_170 ( V_1 ,
V_1 -> V_260 . V_273 ) != true ) {
F_14 ( L_58 ,
F_20 ( V_1 ) ) ;
goto V_471;
}
if ( V_1 -> V_277 ) {
V_2 -> V_472 =
V_1 -> V_355 ? V_473 : V_474 ;
}
V_1 -> V_4 . V_475 = 0 ;
F_141 ( V_12 , V_1 , V_17 ) ;
if ( ! F_32 ( V_1 ) )
goto V_471;
if ( ! F_38 ( V_1 ,
& V_1 -> V_253 ,
& V_1 -> V_255 ) )
goto V_471;
F_14 ( L_59
L_60
L_61
L_62 ,
F_20 ( V_1 ) ,
V_1 -> V_260 . V_262 , V_1 -> V_260 . V_263 ,
V_1 -> V_260 . V_264 ,
V_1 -> V_253 / 1000 ,
V_1 -> V_255 / 1000 ,
( V_1 -> V_260 . V_267 & 0x1 ) ? 'Y' : 'N' ,
( V_1 -> V_260 . V_267 & 0x2 ) ? 'Y' : 'N' ,
V_1 -> V_260 . V_273 &
( V_349 | V_351 ) ? 'Y' : 'N' ,
V_1 -> V_260 . V_273 &
( V_348 | V_350 ) ? 'Y' : 'N' ) ;
return true ;
V_471:
F_171 ( V_1 ) ;
V_391:
F_186 ( & V_2 -> V_4 ) ;
F_138 ( & V_1 -> V_280 ) ;
V_461:
F_145 ( V_1 ) ;
F_24 ( V_1 ) ;
return false ;
}
