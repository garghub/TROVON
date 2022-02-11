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
struct V_11 * V_12 = F_8 ( V_10 ) ;
T_1 V_13 = V_8 , V_14 = V_8 ;
int V_15 ;
if ( F_9 ( V_12 ) ) {
F_10 ( V_1 -> V_16 , V_8 ) ;
F_11 ( V_1 -> V_16 ) ;
if ( F_12 ( V_10 ) ) {
F_10 ( V_1 -> V_16 , V_8 ) ;
F_11 ( V_1 -> V_16 ) ;
}
return;
}
if ( V_1 -> V_17 == V_18 )
V_14 = F_13 ( V_19 ) ;
else
V_13 = F_13 ( V_20 ) ;
for ( V_15 = 0 ; V_15 < 2 ; V_15 ++ )
{
F_10 ( V_20 , V_13 ) ;
F_11 ( V_20 ) ;
F_10 ( V_19 , V_14 ) ;
F_11 ( V_19 ) ;
}
}
static bool F_14 ( struct V_1 * V_1 , T_2 V_21 , T_2 * V_22 )
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
if ( ( V_30 = F_15 ( V_1 -> V_31 , V_24 , 2 ) ) == 2 )
return true ;
F_16 ( L_1 , V_30 ) ;
return false ;
}
static void F_17 ( struct V_1 * V_1 , T_2 V_32 ,
const void * args , int V_33 )
{
int V_15 , V_34 = 0 ;
#define F_18 256
char V_35 [ F_18 ] ;
#define F_19 ( args ... ) \
pos += snprintf(buffer + pos, max_t(int, BUF_LEN - pos, 0), args)
for ( V_15 = 0 ; V_15 < V_33 ; V_15 ++ ) {
F_19 ( L_2 , ( ( T_2 * ) args ) [ V_15 ] ) ;
}
for (; V_15 < 8 ; V_15 ++ ) {
F_19 ( L_3 ) ;
}
for ( V_15 = 0 ; V_15 < F_20 ( V_36 ) ; V_15 ++ ) {
if ( V_32 == V_36 [ V_15 ] . V_32 ) {
F_19 ( L_4 , V_36 [ V_15 ] . V_37 ) ;
break;
}
}
if ( V_15 == F_20 ( V_36 ) ) {
F_19 ( L_5 , V_32 ) ;
}
F_21 ( V_34 >= F_18 - 1 ) ;
#undef F_19
#undef F_18
F_16 ( L_6 , F_22 ( V_1 ) , V_32 , V_35 ) ;
}
static bool F_23 ( struct V_1 * V_1 , T_2 V_32 ,
const void * args , int V_33 )
{
T_2 * V_28 , V_38 ;
struct V_23 * V_24 ;
int V_15 , V_30 = true ;
V_28 = F_24 ( V_33 * 2 + 2 , V_39 ) ;
if ( ! V_28 )
return false ;
V_24 = F_25 ( V_33 + 3 , sizeof( * V_24 ) , V_39 ) ;
if ( ! V_24 ) {
F_26 ( V_28 ) ;
return false ;
}
F_17 ( V_1 , V_32 , args , V_33 ) ;
for ( V_15 = 0 ; V_15 < V_33 ; V_15 ++ ) {
V_24 [ V_15 ] . V_21 = V_1 -> V_25 ;
V_24 [ V_15 ] . V_26 = 0 ;
V_24 [ V_15 ] . V_27 = 2 ;
V_24 [ V_15 ] . V_28 = V_28 + 2 * V_15 ;
V_28 [ 2 * V_15 + 0 ] = V_40 - V_15 ;
V_28 [ 2 * V_15 + 1 ] = ( ( T_2 * ) args ) [ V_15 ] ;
}
V_24 [ V_15 ] . V_21 = V_1 -> V_25 ;
V_24 [ V_15 ] . V_26 = 0 ;
V_24 [ V_15 ] . V_27 = 2 ;
V_24 [ V_15 ] . V_28 = V_28 + 2 * V_15 ;
V_28 [ 2 * V_15 + 0 ] = V_41 ;
V_28 [ 2 * V_15 + 1 ] = V_32 ;
V_38 = V_42 ;
V_24 [ V_15 + 1 ] . V_21 = V_1 -> V_25 ;
V_24 [ V_15 + 1 ] . V_26 = 0 ;
V_24 [ V_15 + 1 ] . V_27 = 1 ;
V_24 [ V_15 + 1 ] . V_28 = & V_38 ;
V_24 [ V_15 + 2 ] . V_21 = V_1 -> V_25 ;
V_24 [ V_15 + 2 ] . V_26 = V_29 ;
V_24 [ V_15 + 2 ] . V_27 = 1 ;
V_24 [ V_15 + 2 ] . V_28 = & V_38 ;
V_30 = F_15 ( V_1 -> V_31 , V_24 , V_15 + 3 ) ;
if ( V_30 < 0 ) {
F_16 ( L_7 , V_30 ) ;
V_30 = false ;
goto V_43;
}
if ( V_30 != V_15 + 3 ) {
F_16 ( L_8 , V_30 , V_15 + 3 ) ;
V_30 = false ;
}
V_43:
F_26 ( V_24 ) ;
F_26 ( V_28 ) ;
return V_30 ;
}
static bool F_27 ( struct V_1 * V_1 ,
void * V_44 , int V_45 )
{
T_2 V_46 = 15 ;
T_2 V_38 ;
int V_15 , V_34 = 0 ;
#define F_18 256
char V_35 [ F_18 ] ;
if ( ! F_14 ( V_1 ,
V_42 ,
& V_38 ) )
goto V_47;
while ( ( V_38 == V_48 ||
V_38 == V_49 ) && -- V_46 ) {
if ( V_46 < 10 )
F_28 ( 15 ) ;
else
F_29 ( 15 ) ;
if ( ! F_14 ( V_1 ,
V_42 ,
& V_38 ) )
goto V_47;
}
#define F_19 ( args ... ) \
pos += snprintf(buffer + pos, max_t(int, BUF_LEN - pos, 0), args)
if ( V_38 <= V_50 )
F_19 ( L_4 , V_51 [ V_38 ] ) ;
else
F_19 ( L_9 , V_38 ) ;
if ( V_38 != V_52 )
goto V_47;
for ( V_15 = 0 ; V_15 < V_45 ; V_15 ++ ) {
if ( ! F_14 ( V_1 ,
V_53 + V_15 ,
& ( ( T_2 * ) V_44 ) [ V_15 ] ) )
goto V_47;
F_19 ( L_10 , ( ( T_2 * ) V_44 ) [ V_15 ] ) ;
}
F_21 ( V_34 >= F_18 - 1 ) ;
#undef F_19
#undef F_18
F_16 ( L_11 , F_22 ( V_1 ) , V_35 ) ;
return true ;
V_47:
F_16 ( L_12 , F_22 ( V_1 ) ) ;
return false ;
}
static int F_30 ( const struct V_54 * V_55 )
{
if ( V_55 -> V_56 >= 100000 )
return 1 ;
else if ( V_55 -> V_56 >= 50000 )
return 2 ;
else
return 4 ;
}
static bool F_31 ( struct V_1 * V_1 ,
T_2 V_57 )
{
return F_23 ( V_1 ,
V_58 ,
& V_57 , 1 ) ;
}
static bool F_32 ( struct V_1 * V_1 , T_2 V_32 , const void * V_59 , int V_27 )
{
if ( ! F_23 ( V_1 , V_32 , V_59 , V_27 ) )
return false ;
return F_27 ( V_1 , NULL , 0 ) ;
}
static bool
F_33 ( struct V_1 * V_1 , T_2 V_32 , void * V_60 , int V_27 )
{
if ( ! F_23 ( V_1 , V_32 , NULL , 0 ) )
return false ;
return F_27 ( V_1 , V_60 , V_27 ) ;
}
static bool F_34 ( struct V_1 * V_1 )
{
struct V_61 V_62 = { 0 } ;
return F_32 ( V_1 ,
V_63 ,
& V_62 , sizeof( V_62 ) ) ;
}
static bool F_35 ( struct V_1 * V_1 , bool * V_64 , bool * V_65 )
{
struct V_66 V_44 ;
F_36 ( sizeof( V_44 ) != 1 ) ;
if ( ! F_33 ( V_1 , V_67 ,
& V_44 , sizeof( V_44 ) ) )
return false ;
* V_64 = V_44 . V_68 ;
* V_65 = V_44 . V_69 ;
return true ;
}
static bool F_37 ( struct V_1 * V_1 ,
T_3 V_70 )
{
return F_32 ( V_1 ,
V_71 ,
& V_70 , sizeof( V_70 ) ) ;
}
static bool F_38 ( struct V_1 * V_1 ,
T_3 * V_70 )
{
return F_33 ( V_1 ,
V_72 ,
V_70 , sizeof( * V_70 ) ) ;
}
static bool F_39 ( struct V_1 * V_1 ,
int V_73 )
{
T_2 V_74 = V_75 ;
switch ( V_73 ) {
case V_76 :
V_74 = V_75 ;
break;
case V_77 :
V_74 = V_78 ;
break;
case V_79 :
V_74 = V_80 ;
break;
case V_81 :
V_74 = V_82 ;
break;
}
return F_32 ( V_1 ,
V_83 , & V_74 , sizeof( V_74 ) ) ;
}
static bool F_40 ( struct V_1 * V_1 ,
int * V_84 ,
int * V_85 )
{
struct V_86 V_87 ;
F_36 ( sizeof( V_87 ) != 4 ) ;
if ( ! F_33 ( V_1 ,
V_88 ,
& V_87 , sizeof( V_87 ) ) )
return false ;
* V_84 = V_87 . V_89 * 10 ;
* V_85 = V_87 . V_90 * 10 ;
return true ;
}
static bool F_41 ( struct V_1 * V_1 ,
T_3 V_70 )
{
return F_32 ( V_1 ,
V_91 ,
& V_70 , sizeof( V_70 ) ) ;
}
static bool F_42 ( struct V_1 * V_1 , T_2 V_32 ,
struct V_92 * V_93 )
{
return F_32 ( V_1 , V_32 , & V_93 -> V_94 , sizeof( V_93 -> V_94 ) ) &&
F_32 ( V_1 , V_32 + 1 , & V_93 -> V_95 , sizeof( V_93 -> V_95 ) ) ;
}
static bool F_43 ( struct V_1 * V_1 , T_2 V_32 ,
struct V_92 * V_93 )
{
return F_33 ( V_1 , V_32 , & V_93 -> V_94 , sizeof( V_93 -> V_94 ) ) &&
F_33 ( V_1 , V_32 + 1 , & V_93 -> V_95 , sizeof( V_93 -> V_95 ) ) ;
}
static bool F_44 ( struct V_1 * V_1 ,
struct V_92 * V_93 )
{
return F_42 ( V_1 ,
V_96 , V_93 ) ;
}
static bool F_45 ( struct V_1 * V_1 ,
struct V_92 * V_93 )
{
return F_42 ( V_1 ,
V_97 , V_93 ) ;
}
static bool F_46 ( struct V_1 * V_1 ,
struct V_92 * V_93 )
{
return F_43 ( V_1 ,
V_98 , V_93 ) ;
}
static bool
F_47 ( struct V_1 * V_1 ,
T_4 clock ,
T_4 V_99 ,
T_4 V_100 )
{
struct V_101 args ;
memset ( & args , 0 , sizeof( args ) ) ;
args . clock = clock ;
args . V_99 = V_99 ;
args . V_100 = V_100 ;
args . V_102 = 0 ;
if ( V_1 -> V_103 &&
( V_1 -> V_104 -> V_105 != V_99 ||
V_1 -> V_104 -> V_106 != V_100 ) )
args . V_107 = 1 ;
return F_32 ( V_1 ,
V_108 ,
& args , sizeof( args ) ) ;
}
static bool F_48 ( struct V_1 * V_1 ,
struct V_92 * V_93 )
{
F_36 ( sizeof( V_93 -> V_94 ) != 8 ) ;
F_36 ( sizeof( V_93 -> V_95 ) != 8 ) ;
return F_33 ( V_1 , V_109 ,
& V_93 -> V_94 , sizeof( V_93 -> V_94 ) ) &&
F_33 ( V_1 , V_110 ,
& V_93 -> V_95 , sizeof( V_93 -> V_95 ) ) ;
}
static bool F_49 ( struct V_1 * V_1 , T_2 V_8 )
{
return F_32 ( V_1 , V_111 , & V_8 , 1 ) ;
}
static void F_50 ( struct V_92 * V_93 ,
const struct V_54 * V_73 )
{
T_4 V_99 , V_100 ;
T_4 V_112 , V_113 , V_114 , V_115 ;
T_4 V_116 , V_117 ;
int V_118 ;
memset ( V_93 , 0 , sizeof( * V_93 ) ) ;
V_99 = V_73 -> V_105 ;
V_100 = V_73 -> V_106 ;
V_112 = V_73 -> V_119 - V_73 -> V_105 ;
V_113 = V_73 -> V_120 - V_73 -> V_121 ;
V_114 = V_73 -> V_122 - V_73 -> V_106 ;
V_115 = V_73 -> V_123 - V_73 -> V_124 ;
V_116 = V_73 -> V_121 - V_73 -> V_105 ;
V_117 = V_73 -> V_124 - V_73 -> V_106 ;
V_118 = V_73 -> clock ;
V_118 /= 10 ;
V_93 -> V_94 . clock = V_118 ;
V_93 -> V_94 . V_125 = V_99 & 0xff ;
V_93 -> V_94 . V_126 = V_112 & 0xff ;
V_93 -> V_94 . V_127 = ( ( ( V_99 >> 8 ) & 0xf ) << 4 ) |
( ( V_112 >> 8 ) & 0xf ) ;
V_93 -> V_94 . V_128 = V_100 & 0xff ;
V_93 -> V_94 . V_129 = V_114 & 0xff ;
V_93 -> V_94 . V_130 = ( ( ( V_100 >> 8 ) & 0xf ) << 4 ) |
( ( V_114 >> 8 ) & 0xf ) ;
V_93 -> V_95 . V_131 = V_116 & 0xff ;
V_93 -> V_95 . V_132 = V_113 & 0xff ;
V_93 -> V_95 . V_133 = ( V_117 & 0xf ) << 4 |
( V_115 & 0xf ) ;
V_93 -> V_95 . V_134 = ( ( V_116 & 0x300 ) >> 2 ) |
( ( V_113 & 0x300 ) >> 4 ) | ( ( V_117 & 0x30 ) >> 2 ) |
( ( V_115 & 0x30 ) >> 4 ) ;
V_93 -> V_95 . V_135 = 0x18 ;
if ( V_73 -> V_26 & V_136 )
V_93 -> V_95 . V_135 |= V_137 ;
if ( V_73 -> V_26 & V_138 )
V_93 -> V_95 . V_135 |= V_139 ;
if ( V_73 -> V_26 & V_140 )
V_93 -> V_95 . V_135 |= V_141 ;
V_93 -> V_95 . V_142 = V_117 & 0xc0 ;
}
static void F_51 ( struct V_54 * V_143 ,
const struct V_92 * V_93 )
{
struct V_54 V_73 = {} ;
V_73 . V_105 = V_93 -> V_94 . V_125 ;
V_73 . V_105 += ( ( V_93 -> V_94 . V_127 >> 4 ) & 0x0f ) << 8 ;
V_73 . V_121 = V_73 . V_105 + V_93 -> V_95 . V_131 ;
V_73 . V_121 += ( V_93 -> V_95 . V_134 & 0xc0 ) << 2 ;
V_73 . V_120 = V_73 . V_121 + V_93 -> V_95 . V_132 ;
V_73 . V_120 += ( V_93 -> V_95 . V_134 & 0x30 ) << 4 ;
V_73 . V_119 = V_73 . V_105 + V_93 -> V_94 . V_126 ;
V_73 . V_119 += ( V_93 -> V_94 . V_127 & 0xf ) << 8 ;
V_73 . V_106 = V_93 -> V_94 . V_128 ;
V_73 . V_106 += ( ( V_93 -> V_94 . V_130 >> 4 ) & 0x0f ) << 8 ;
V_73 . V_124 = V_73 . V_106 ;
V_73 . V_124 += ( V_93 -> V_95 . V_133 >> 4 ) & 0xf ;
V_73 . V_124 += ( V_93 -> V_95 . V_134 & 0x0c ) << 2 ;
V_73 . V_124 += V_93 -> V_95 . V_142 & 0xc0 ;
V_73 . V_123 = V_73 . V_124 +
( V_93 -> V_95 . V_133 & 0xf ) ;
V_73 . V_123 += ( V_93 -> V_95 . V_134 & 0x3 ) << 4 ;
V_73 . V_122 = V_73 . V_106 + V_93 -> V_94 . V_129 ;
V_73 . V_122 += ( V_93 -> V_94 . V_130 & 0xf ) << 8 ;
V_73 . clock = V_93 -> V_94 . clock * 10 ;
if ( V_93 -> V_95 . V_135 & V_137 )
V_73 . V_26 |= V_136 ;
if ( V_93 -> V_95 . V_135 & V_139 )
V_73 . V_26 |= V_138 ;
else
V_73 . V_26 |= V_144 ;
if ( V_93 -> V_95 . V_135 & V_141 )
V_73 . V_26 |= V_140 ;
else
V_73 . V_26 |= V_145 ;
F_52 ( & V_73 , 0 ) ;
F_53 ( V_143 , & V_73 ) ;
}
static bool F_54 ( struct V_1 * V_1 )
{
struct V_146 V_147 ;
F_36 ( sizeof( V_147 ) != 2 ) ;
return F_33 ( V_1 ,
V_148 ,
& V_147 , sizeof( V_147 ) ) ;
}
static bool F_55 ( struct V_1 * V_1 ,
T_5 V_73 )
{
return F_32 ( V_1 , V_149 , & V_73 , 1 ) ;
}
static bool F_56 ( struct V_1 * V_1 ,
T_5 V_73 )
{
return F_32 ( V_1 , V_150 , & V_73 , 1 ) ;
}
static bool F_57 ( struct V_1 * V_1 ,
unsigned V_151 , T_5 V_152 ,
const T_5 * V_59 , unsigned V_153 )
{
T_5 V_154 [ 2 ] = { V_151 , 0 } ;
T_5 V_155 , V_156 [ 8 ] ;
int V_15 ;
if ( ! F_32 ( V_1 ,
V_157 ,
V_154 , 2 ) )
return false ;
if ( ! F_33 ( V_1 , V_158 ,
& V_155 , 1 ) )
return false ;
V_155 ++ ;
F_16 ( L_13 ,
V_151 , V_153 , V_155 ) ;
for ( V_15 = 0 ; V_15 < V_155 ; V_15 += 8 ) {
memset ( V_156 , 0 , 8 ) ;
if ( V_15 < V_153 )
memcpy ( V_156 , V_59 + V_15 , F_58 ( unsigned , 8 , V_153 - V_15 ) ) ;
if ( ! F_32 ( V_1 ,
V_159 ,
V_156 , 8 ) )
return false ;
}
return F_32 ( V_1 ,
V_160 ,
& V_152 , 1 ) ;
}
static bool F_59 ( struct V_1 * V_1 ,
const struct V_54 * V_55 )
{
T_5 V_161 [ F_60 ( V_162 ) ] ;
struct V_163 * V_164 = V_1 -> V_4 . V_4 . V_164 ;
struct V_165 * V_165 = F_61 ( V_164 ) ;
union V_166 V_167 ;
int V_30 ;
T_6 V_27 ;
V_30 = F_62 ( & V_167 . V_168 ,
V_55 ) ;
if ( V_30 < 0 ) {
F_63 ( L_14 ) ;
return false ;
}
if ( V_1 -> V_169 ) {
if ( V_165 -> V_170 -> V_171 )
V_167 . V_168 . V_172 =
V_173 ;
else
V_167 . V_168 . V_172 =
V_174 ;
}
V_27 = F_64 ( & V_167 , V_161 , sizeof( V_161 ) ) ;
if ( V_27 < 0 )
return false ;
return F_57 ( V_1 , V_175 ,
V_176 ,
V_161 , sizeof( V_161 ) ) ;
}
static bool F_65 ( struct V_1 * V_1 )
{
struct V_177 V_178 ;
T_7 V_179 ;
V_179 = 1 << V_1 -> V_180 ;
memset ( & V_178 , 0 , sizeof( V_178 ) ) ;
memcpy ( & V_178 , & V_179 , V_89 ( sizeof( V_178 ) , sizeof( V_179 ) ) ) ;
F_36 ( sizeof( V_178 ) != 6 ) ;
return F_32 ( V_1 ,
V_181 ,
& V_178 , sizeof( V_178 ) ) ;
}
static bool
F_66 ( struct V_1 * V_1 ,
const struct V_54 * V_73 )
{
struct V_92 V_182 ;
if ( ! F_41 ( V_1 ,
V_1 -> V_183 ) )
return false ;
F_50 ( & V_182 , V_73 ) ;
if ( ! F_45 ( V_1 , & V_182 ) )
return false ;
return true ;
}
static bool
F_67 ( struct V_1 * V_1 ,
const struct V_54 * V_73 ,
struct V_54 * V_55 )
{
struct V_92 V_184 ;
if ( ! F_34 ( V_1 ) )
return false ;
if ( ! F_47 ( V_1 ,
V_73 -> clock / 10 ,
V_73 -> V_105 ,
V_73 -> V_106 ) )
return false ;
if ( ! F_48 ( V_1 ,
& V_184 ) )
return false ;
F_51 ( V_55 , & V_184 ) ;
V_1 -> V_185 = V_184 . V_95 . V_186 ;
return true ;
}
static void F_68 ( struct V_187 * V_188 )
{
unsigned V_189 = V_188 -> V_190 ;
struct V_191 * clock = & V_188 -> V_191 ;
if ( V_189 >= 100000 && V_189 < 140500 ) {
clock -> V_192 = 2 ;
clock -> V_193 = 10 ;
clock -> V_194 = 3 ;
clock -> V_195 = 16 ;
clock -> V_196 = 8 ;
} else if ( V_189 >= 140500 && V_189 <= 200000 ) {
clock -> V_192 = 1 ;
clock -> V_193 = 10 ;
clock -> V_194 = 6 ;
clock -> V_195 = 12 ;
clock -> V_196 = 8 ;
} else {
F_69 ( 1 , L_15 , V_189 ) ;
}
V_188 -> V_197 = true ;
}
static bool F_70 ( struct V_2 * V_3 ,
struct V_187 * V_188 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_54 * V_55 = & V_188 -> V_4 . V_55 ;
struct V_54 * V_73 = & V_188 -> V_4 . V_73 ;
F_16 ( L_16 ) ;
V_188 -> V_198 = 8 * 3 ;
if ( F_9 ( V_3 -> V_4 . V_10 ) )
V_188 -> V_199 = true ;
if ( V_1 -> V_200 ) {
if ( ! F_66 ( V_1 , V_73 ) )
return false ;
( void ) F_67 ( V_1 ,
V_73 ,
V_55 ) ;
V_188 -> V_201 = true ;
} else if ( V_1 -> V_103 ) {
if ( ! F_66 ( V_1 ,
V_1 -> V_104 ) )
return false ;
( void ) F_67 ( V_1 ,
V_73 ,
V_55 ) ;
}
V_188 -> V_202 =
F_30 ( V_55 ) ;
V_188 -> V_203 = V_1 -> V_204 ;
if ( V_1 -> V_205 ) {
if ( V_188 -> V_203 &&
F_71 ( V_55 ) > 1 )
V_188 -> V_171 = true ;
} else {
if ( V_188 -> V_203 &&
V_1 -> V_206 == V_207 )
V_188 -> V_171 = true ;
}
if ( V_1 -> V_200 )
F_68 ( V_188 ) ;
if ( V_1 -> V_208 )
V_55 -> V_209 = V_1 -> V_210 ;
return true ;
}
static void F_72 ( struct V_2 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_4 . V_10 ;
struct V_11 * V_12 = F_8 ( V_10 ) ;
struct V_165 * V_164 = F_61 ( V_2 -> V_4 . V_164 ) ;
const struct V_54 * V_55 = & V_164 -> V_170 -> V_4 . V_55 ;
struct V_54 * V_73 = & V_164 -> V_170 -> V_4 . V_73 ;
struct V_1 * V_1 = F_1 ( V_2 ) ;
T_1 V_211 ;
struct V_212 V_213 ;
struct V_92 V_184 , V_182 ;
int V_214 ;
if ( ! V_73 )
return;
V_213 . V_215 = V_1 -> V_183 ;
V_213 . V_216 = 0 ;
F_32 ( V_1 ,
V_217 ,
& V_213 , sizeof( V_213 ) ) ;
if ( ! F_41 ( V_1 ,
V_1 -> V_183 ) )
return;
if ( V_1 -> V_103 )
F_50 ( & V_182 ,
V_1 -> V_104 ) ;
else
F_50 ( & V_182 , V_73 ) ;
if ( ! F_45 ( V_1 , & V_182 ) )
F_73 ( L_17 ,
F_22 ( V_1 ) ) ;
if ( ! F_34 ( V_1 ) )
return;
if ( V_164 -> V_170 -> V_203 ) {
F_55 ( V_1 , V_218 ) ;
F_56 ( V_1 ,
V_219 ) ;
F_59 ( V_1 , V_55 ) ;
} else
F_55 ( V_1 , V_220 ) ;
if ( V_1 -> V_200 &&
! F_65 ( V_1 ) )
return;
F_50 ( & V_184 , V_55 ) ;
if ( V_1 -> V_200 || V_1 -> V_103 )
V_184 . V_95 . V_186 = V_1 -> V_185 ;
if ( ! F_44 ( V_1 , & V_184 ) )
F_73 ( L_18 ,
F_22 ( V_1 ) ) ;
switch ( V_164 -> V_170 -> V_202 ) {
default:
F_69 ( 1 , L_19 ) ;
case 1 : V_214 = V_221 ; break;
case 2 : V_214 = V_222 ; break;
case 4 : V_214 = V_223 ; break;
}
if ( ! F_49 ( V_1 , V_214 ) )
return;
if ( F_74 ( V_10 ) -> V_224 >= 4 ) {
V_211 = V_225 | V_226 ;
if ( ! F_9 ( V_10 ) && V_164 -> V_170 -> V_171 )
V_211 |= V_207 ;
if ( F_74 ( V_10 ) -> V_224 < 5 )
V_211 |= V_227 ;
} else {
V_211 = F_13 ( V_1 -> V_16 ) ;
if ( V_1 -> V_17 == V_18 )
V_211 &= V_228 ;
else
V_211 &= V_229 ;
V_211 |= ( 9 << 19 ) | V_227 ;
}
if ( F_75 ( V_10 ) >= V_230 )
V_211 |= F_76 ( V_164 -> V_231 ) ;
else
V_211 |= F_77 ( V_164 -> V_231 ) ;
if ( V_1 -> V_232 )
V_211 |= V_233 ;
if ( F_74 ( V_10 ) -> V_224 >= 4 ) {
} else if ( F_78 ( V_10 ) || F_79 ( V_10 ) || F_80 ( V_10 ) ) {
} else {
V_211 |= ( V_164 -> V_170 -> V_202 - 1 )
<< V_234 ;
}
if ( V_184 . V_95 . V_186 & V_235 &&
F_74 ( V_10 ) -> V_224 < 5 )
V_211 |= V_236 ;
F_7 ( V_1 , V_211 ) ;
}
static bool F_81 ( struct V_237 * V_6 )
{
struct V_7 * V_7 =
F_5 ( & V_6 -> V_4 ) ;
struct V_1 * V_1 = F_3 ( & V_6 -> V_4 ) ;
T_3 V_238 = 0 ;
F_38 ( V_1 , & V_238 ) ;
if ( V_238 & V_7 -> V_239 )
return true ;
else
return false ;
}
static bool F_82 ( struct V_2 * V_3 ,
enum V_231 * V_231 )
{
struct V_9 * V_10 = V_3 -> V_4 . V_10 ;
struct V_11 * V_12 = F_8 ( V_10 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
T_3 V_238 = 0 ;
T_1 V_156 ;
V_156 = F_13 ( V_1 -> V_16 ) ;
F_38 ( V_1 , & V_238 ) ;
if ( ! ( V_156 & V_240 ) && ( V_238 == 0 ) )
return false ;
if ( F_83 ( V_10 ) )
* V_231 = F_84 ( V_156 ) ;
else
* V_231 = F_85 ( V_156 ) ;
return true ;
}
static void F_86 ( struct V_2 * V_3 ,
struct V_187 * V_188 )
{
struct V_9 * V_10 = V_3 -> V_4 . V_10 ;
struct V_11 * V_12 = F_8 ( V_10 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_92 V_93 ;
int V_241 = 0 ;
int V_189 ;
T_1 V_26 = 0 , V_211 ;
T_2 V_8 ;
bool V_30 ;
V_211 = F_13 ( V_1 -> V_16 ) ;
V_30 = F_46 ( V_1 , & V_93 ) ;
if ( ! V_30 ) {
F_87 ( L_20 ) ;
V_188 -> V_242 |= V_243 ;
} else {
if ( V_93 . V_95 . V_135 & V_139 )
V_26 |= V_138 ;
else
V_26 |= V_144 ;
if ( V_93 . V_95 . V_135 & V_141 )
V_26 |= V_140 ;
else
V_26 |= V_145 ;
}
V_188 -> V_4 . V_55 . V_26 |= V_26 ;
if ( F_88 ( V_10 ) || F_89 ( V_10 ) ) {
V_188 -> V_202 =
( ( V_211 & V_244 )
>> V_234 ) + 1 ;
}
V_189 = V_188 -> V_190 ;
if ( V_188 -> V_202 )
V_189 /= V_188 -> V_202 ;
V_188 -> V_4 . V_55 . V_56 = V_189 ;
if ( F_33 ( V_1 , V_245 ,
& V_8 , 1 ) ) {
switch ( V_8 ) {
case V_221 :
V_241 = 1 ;
break;
case V_222 :
V_241 = 2 ;
break;
case V_223 :
V_241 = 4 ;
break;
}
}
if ( V_211 & V_207 )
V_188 -> V_171 = true ;
if ( F_33 ( V_1 , V_246 ,
& V_8 , 1 ) ) {
if ( V_8 == V_218 )
V_188 -> V_203 = true ;
}
F_69 ( V_241 != V_188 -> V_202 ,
L_21 ,
V_188 -> V_202 , V_241 ) ;
}
static void F_90 ( struct V_2 * V_3 )
{
struct V_11 * V_12 = F_8 ( V_3 -> V_4 . V_10 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_165 * V_164 = F_61 ( V_3 -> V_4 . V_164 ) ;
T_1 V_247 ;
F_37 ( V_1 , 0 ) ;
if ( 0 )
F_39 ( V_1 ,
V_81 ) ;
V_247 = F_13 ( V_1 -> V_16 ) ;
V_247 &= ~ V_240 ;
F_7 ( V_1 , V_247 ) ;
if ( F_12 ( V_12 ) && V_164 -> V_231 == V_248 ) {
F_91 ( V_12 , V_249 , false ) ;
F_92 ( V_12 , V_249 , false ) ;
V_247 &= ~ V_250 ;
V_247 |= V_240 ;
F_7 ( V_1 , V_247 ) ;
V_247 &= ~ V_240 ;
F_7 ( V_1 , V_247 ) ;
F_93 ( & V_12 -> V_251 , V_249 ) ;
F_91 ( V_12 , V_249 , true ) ;
F_92 ( V_12 , V_249 , true ) ;
}
}
static void F_94 ( struct V_2 * V_3 )
{
}
static void F_95 ( struct V_2 * V_3 )
{
F_90 ( V_3 ) ;
}
static void F_96 ( struct V_2 * V_3 )
{
struct V_9 * V_10 = V_3 -> V_4 . V_10 ;
struct V_11 * V_12 = F_8 ( V_10 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_165 * V_165 = F_61 ( V_3 -> V_4 . V_164 ) ;
T_1 V_247 ;
bool V_252 , V_253 ;
int V_15 ;
bool V_254 ;
V_247 = F_13 ( V_1 -> V_16 ) ;
V_247 |= V_240 ;
F_7 ( V_1 , V_247 ) ;
for ( V_15 = 0 ; V_15 < 2 ; V_15 ++ )
F_97 ( V_10 , V_165 -> V_231 ) ;
V_254 = F_35 ( V_1 , & V_252 , & V_253 ) ;
if ( V_254 && ! V_252 ) {
F_16 ( L_22
L_23 , F_22 ( V_1 ) ) ;
}
if ( 0 )
F_39 ( V_1 ,
V_76 ) ;
F_37 ( V_1 , V_1 -> V_183 ) ;
}
static enum V_255
F_98 ( struct V_5 * V_6 ,
struct V_54 * V_73 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
int V_256 = F_8 ( V_6 -> V_10 ) -> V_257 ;
if ( V_73 -> V_26 & V_258 )
return V_259 ;
if ( V_1 -> V_260 > V_73 -> clock )
return V_261 ;
if ( V_1 -> V_262 < V_73 -> clock )
return V_263 ;
if ( V_73 -> clock > V_256 )
return V_263 ;
if ( V_1 -> V_103 ) {
if ( V_73 -> V_105 > V_1 -> V_104 -> V_105 )
return V_264 ;
if ( V_73 -> V_106 > V_1 -> V_104 -> V_106 )
return V_264 ;
}
return V_265 ;
}
static bool F_99 ( struct V_1 * V_1 , struct V_266 * V_267 )
{
F_36 ( sizeof( * V_267 ) != 8 ) ;
if ( ! F_33 ( V_1 ,
V_268 ,
V_267 , sizeof( * V_267 ) ) )
return false ;
F_16 ( L_24
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
V_267 -> V_269 ,
V_267 -> V_270 ,
V_267 -> V_271 ,
V_267 -> V_272 ,
V_267 -> V_273 ,
V_267 -> V_274 ,
V_267 -> V_275 ,
V_267 -> V_276 ,
V_267 -> V_277 ,
V_267 -> V_278 ,
V_267 -> V_279 ,
V_267 -> V_280 ) ;
return true ;
}
static T_4 F_100 ( struct V_1 * V_1 )
{
struct V_9 * V_10 = V_1 -> V_4 . V_4 . V_10 ;
T_4 V_281 ;
if ( ! F_101 ( V_10 ) )
return 0 ;
if ( F_78 ( V_10 ) || F_79 ( V_10 ) )
return 0 ;
if ( ! F_33 ( V_1 , V_282 ,
& V_281 , sizeof( V_281 ) ) )
return 0 ;
return V_281 ;
}
static void F_102 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
F_23 ( V_1 , V_283 ,
& V_1 -> V_284 , 2 ) ;
}
static bool
F_103 ( struct V_1 * V_1 )
{
return F_104 ( V_1 -> V_267 . V_280 ) > 1 ;
}
static struct V_285 *
F_105 ( struct V_5 * V_6 )
{
struct V_1 * V_286 = F_3 ( V_6 ) ;
return F_106 ( V_6 , & V_286 -> V_287 ) ;
}
static struct V_285 *
F_107 ( struct V_5 * V_6 )
{
struct V_11 * V_12 = F_8 ( V_6 -> V_10 ) ;
return F_106 ( V_6 ,
F_108 ( V_12 ,
V_12 -> V_288 . V_289 ) ) ;
}
static enum V_290
F_109 ( struct V_5 * V_6 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
enum V_290 V_38 ;
struct V_285 * V_285 ;
V_285 = F_105 ( V_6 ) ;
if ( V_285 == NULL && F_103 ( V_1 ) ) {
T_2 V_287 , V_291 = V_1 -> V_57 ;
for ( V_287 = V_1 -> V_57 >> 1 ; V_287 > 1 ; V_287 >>= 1 ) {
V_1 -> V_57 = V_287 ;
V_285 = F_105 ( V_6 ) ;
if ( V_285 )
break;
}
if ( V_285 == NULL )
V_1 -> V_57 = V_291 ;
}
if ( V_285 == NULL )
V_285 = F_107 ( V_6 ) ;
V_38 = V_292 ;
if ( V_285 != NULL ) {
if ( V_285 -> V_293 & V_294 ) {
V_38 = V_295 ;
if ( V_1 -> V_208 ) {
V_1 -> V_204 = F_110 ( V_285 ) ;
V_1 -> V_232 = F_111 ( V_285 ) ;
V_1 -> V_169 =
F_112 ( V_285 ) ;
}
} else
V_38 = V_296 ;
F_26 ( V_285 ) ;
}
if ( V_38 == V_295 ) {
struct V_7 * V_7 = F_5 ( V_6 ) ;
if ( V_7 -> V_297 != V_298 )
V_1 -> V_232 = ( V_7 -> V_297 == V_299 ) ;
}
return V_38 ;
}
static bool
F_113 ( struct V_7 * V_286 ,
struct V_285 * V_285 )
{
bool V_300 = ! ! ( V_285 -> V_293 & V_294 ) ;
bool V_301 = ! ! F_114 ( V_286 ) ;
F_16 ( L_37 ,
V_301 , V_300 ) ;
return V_301 == V_300 ;
}
static enum V_290
F_115 ( struct V_5 * V_6 , bool V_302 )
{
T_4 V_44 ;
struct V_1 * V_1 = F_3 ( V_6 ) ;
struct V_7 * V_7 = F_5 ( V_6 ) ;
enum V_290 V_30 ;
F_16 ( L_38 ,
V_6 -> V_4 . V_303 , V_6 -> V_37 ) ;
if ( ! F_33 ( V_1 ,
V_304 ,
& V_44 , 2 ) )
return V_292 ;
F_16 ( L_39 ,
V_44 & 0xff , V_44 >> 8 ,
V_7 -> V_239 ) ;
if ( V_44 == 0 )
return V_296 ;
V_1 -> V_183 = V_44 ;
V_1 -> V_204 = false ;
V_1 -> V_232 = false ;
V_1 -> V_169 = false ;
if ( ( V_7 -> V_239 & V_44 ) == 0 )
V_30 = V_296 ;
else if ( F_116 ( V_7 ) )
V_30 = F_109 ( V_6 ) ;
else {
struct V_285 * V_285 ;
V_285 = F_105 ( V_6 ) ;
if ( V_285 == NULL )
V_285 = F_107 ( V_6 ) ;
if ( V_285 != NULL ) {
if ( F_113 ( V_7 ,
V_285 ) )
V_30 = V_295 ;
else
V_30 = V_296 ;
F_26 ( V_285 ) ;
} else
V_30 = V_295 ;
}
if ( V_30 == V_295 ) {
V_1 -> V_200 = false ;
V_1 -> V_103 = false ;
if ( V_44 & V_305 )
V_1 -> V_200 = true ;
if ( V_44 & V_306 )
V_1 -> V_103 = V_1 -> V_104 != NULL ;
}
return V_30 ;
}
static void F_117 ( struct V_5 * V_6 )
{
struct V_285 * V_285 ;
F_16 ( L_38 ,
V_6 -> V_4 . V_303 , V_6 -> V_37 ) ;
V_285 = F_105 ( V_6 ) ;
if ( V_285 == NULL )
V_285 = F_107 ( V_6 ) ;
if ( V_285 != NULL ) {
if ( F_113 ( F_5 ( V_6 ) ,
V_285 ) ) {
F_118 ( V_6 , V_285 ) ;
F_119 ( V_6 , V_285 ) ;
}
F_26 ( V_285 ) ;
}
}
static void F_120 ( struct V_5 * V_6 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
struct V_307 V_308 ;
T_7 V_309 = 0 , V_179 = 0 ;
int V_15 ;
F_16 ( L_38 ,
V_6 -> V_4 . V_303 , V_6 -> V_37 ) ;
V_179 = 1 << V_1 -> V_180 ;
memcpy ( & V_308 , & V_179 ,
V_89 ( sizeof( V_179 ) , sizeof( struct V_307 ) ) ) ;
if ( ! F_41 ( V_1 , V_1 -> V_183 ) )
return;
F_36 ( sizeof( V_308 ) != 3 ) ;
if ( ! F_23 ( V_1 ,
V_310 ,
& V_308 , sizeof( V_308 ) ) )
return;
if ( ! F_27 ( V_1 , & V_309 , 3 ) )
return;
for ( V_15 = 0 ; V_15 < F_20 ( V_311 ) ; V_15 ++ )
if ( V_309 & ( 1 << V_15 ) ) {
struct V_54 * V_312 ;
V_312 = F_121 ( V_6 -> V_10 ,
& V_311 [ V_15 ] ) ;
if ( V_312 )
F_122 ( V_6 , V_312 ) ;
}
}
static void F_123 ( struct V_5 * V_6 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
struct V_11 * V_12 = F_8 ( V_6 -> V_10 ) ;
struct V_54 * V_313 ;
F_16 ( L_38 ,
V_6 -> V_4 . V_303 , V_6 -> V_37 ) ;
if ( V_12 -> V_288 . V_314 != NULL ) {
V_313 = F_121 ( V_6 -> V_10 ,
V_12 -> V_288 . V_314 ) ;
if ( V_313 != NULL ) {
V_313 -> type = ( V_315 |
V_316 ) ;
F_122 ( V_6 , V_313 ) ;
}
}
F_124 ( V_6 , & V_1 -> V_287 ) ;
F_125 (newmode, &connector->probed_modes, head) {
if ( V_313 -> type & V_315 ) {
V_1 -> V_104 =
F_121 ( V_6 -> V_10 , V_313 ) ;
V_1 -> V_103 = true ;
break;
}
}
}
static int F_126 ( struct V_5 * V_6 )
{
struct V_7 * V_7 = F_5 ( V_6 ) ;
if ( F_127 ( V_7 ) )
F_120 ( V_6 ) ;
else if ( F_128 ( V_7 ) )
F_123 ( V_6 ) ;
else
F_117 ( V_6 ) ;
return ! F_129 ( & V_6 -> V_317 ) ;
}
static void F_130 ( struct V_5 * V_6 )
{
struct V_7 * V_7 = F_5 ( V_6 ) ;
F_131 ( V_6 ) ;
F_26 ( V_7 ) ;
}
static bool F_132 ( struct V_5 * V_6 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
struct V_285 * V_285 ;
bool V_318 = false ;
if ( ! V_1 -> V_208 )
return false ;
V_285 = F_105 ( V_6 ) ;
if ( V_285 != NULL && V_285 -> V_293 & V_294 )
V_318 = F_111 ( V_285 ) ;
F_26 ( V_285 ) ;
return V_318 ;
}
static int
F_133 ( struct V_5 * V_6 ,
struct V_319 * V_320 ,
T_8 V_8 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
struct V_7 * V_7 = F_5 ( V_6 ) ;
struct V_11 * V_12 = F_8 ( V_6 -> V_10 ) ;
T_4 V_321 ;
T_5 V_32 ;
int V_30 ;
V_30 = F_134 ( & V_6 -> V_4 , V_320 , V_8 ) ;
if ( V_30 )
return V_30 ;
if ( V_320 == V_12 -> V_322 ) {
int V_15 = V_8 ;
bool V_318 ;
if ( V_15 == V_7 -> V_297 )
return 0 ;
V_7 -> V_297 = V_15 ;
if ( V_15 == V_298 )
V_318 = F_132 ( V_6 ) ;
else
V_318 = ( V_15 == V_299 ) ;
if ( V_318 == V_1 -> V_232 )
return 0 ;
V_1 -> V_232 = V_318 ;
goto V_323;
}
if ( V_320 == V_12 -> V_324 ) {
bool V_325 = V_1 -> V_205 ;
T_7 V_326 = V_1 -> V_206 ;
switch ( V_8 ) {
case V_327 :
V_1 -> V_205 = true ;
break;
case V_328 :
V_1 -> V_205 = false ;
V_1 -> V_206 = 0 ;
break;
case V_329 :
V_1 -> V_205 = false ;
V_1 -> V_206 = V_207 ;
break;
default:
return - V_330 ;
}
if ( V_325 == V_1 -> V_205 &&
V_326 == V_1 -> V_206 )
return 0 ;
goto V_323;
}
if ( V_320 == V_6 -> V_10 -> V_331 . V_332 ) {
switch ( V_8 ) {
case V_333 :
V_1 -> V_210 = V_334 ;
break;
case V_335 :
V_1 -> V_210 = V_336 ;
break;
case V_337 :
V_1 -> V_210 = V_338 ;
break;
default:
return - V_330 ;
}
goto V_323;
}
#define F_135 ( V_37 , T_9 ) \
if (intel_sdvo_connector->name == property) { \
if (intel_sdvo_connector->cur_##name == temp_value) return 0; \
if (intel_sdvo_connector->max_##name < temp_value) return -EINVAL; \
cmd = SDVO_CMD_SET_##NAME; \
intel_sdvo_connector->cur_##name = temp_value; \
goto set_value; \
}
if ( V_320 == V_7 -> V_339 ) {
if ( V_8 >= V_340 )
return - V_330 ;
if ( V_1 -> V_180 ==
V_7 -> V_341 [ V_8 ] )
return 0 ;
V_1 -> V_180 = V_7 -> V_341 [ V_8 ] ;
goto V_323;
} else if ( F_136 ( V_7 ) ) {
V_321 = V_8 ;
if ( V_7 -> V_342 == V_320 ) {
F_134 ( & V_6 -> V_4 ,
V_7 -> V_343 , V_8 ) ;
if ( V_7 -> V_344 == V_321 )
return 0 ;
V_7 -> V_344 = V_321 ;
V_7 -> V_345 = V_321 ;
V_321 = V_7 -> V_346 -
V_7 -> V_344 ;
V_32 = V_347 ;
goto V_348;
} else if ( V_7 -> V_343 == V_320 ) {
F_134 ( & V_6 -> V_4 ,
V_7 -> V_342 , V_8 ) ;
if ( V_7 -> V_345 == V_321 )
return 0 ;
V_7 -> V_344 = V_321 ;
V_7 -> V_345 = V_321 ;
V_321 = V_7 -> V_346 -
V_7 -> V_344 ;
V_32 = V_347 ;
goto V_348;
} else if ( V_7 -> V_349 == V_320 ) {
F_134 ( & V_6 -> V_4 ,
V_7 -> V_350 , V_8 ) ;
if ( V_7 -> V_351 == V_321 )
return 0 ;
V_7 -> V_351 = V_321 ;
V_7 -> V_352 = V_321 ;
V_321 = V_7 -> V_353 -
V_7 -> V_351 ;
V_32 = V_354 ;
goto V_348;
} else if ( V_7 -> V_350 == V_320 ) {
F_134 ( & V_6 -> V_4 ,
V_7 -> V_349 , V_8 ) ;
if ( V_7 -> V_352 == V_321 )
return 0 ;
V_7 -> V_351 = V_321 ;
V_7 -> V_352 = V_321 ;
V_321 = V_7 -> V_353 -
V_7 -> V_351 ;
V_32 = V_354 ;
goto V_348;
}
F_135 (hpos, HPOS)
F_135 (vpos, VPOS)
F_135 (saturation, SATURATION)
F_135 (contrast, CONTRAST)
F_135 (hue, HUE)
F_135 (brightness, BRIGHTNESS)
F_135 (sharpness, SHARPNESS)
F_135 (flicker_filter, FLICKER_FILTER)
F_135 (flicker_filter_2d, FLICKER_FILTER_2D)
F_135 (flicker_filter_adaptive, FLICKER_FILTER_ADAPTIVE)
F_135 (tv_chroma_filter, TV_CHROMA_FILTER)
F_135 (tv_luma_filter, TV_LUMA_FILTER)
F_135 (dot_crawl, DOT_CRAWL)
}
return - V_330 ;
V_348:
if ( ! F_32 ( V_1 , V_32 , & V_321 , 2 ) )
return - V_355 ;
V_323:
if ( V_1 -> V_4 . V_4 . V_164 )
F_137 ( V_1 -> V_4 . V_4 . V_164 ) ;
return 0 ;
#undef F_135
}
static int
F_138 ( struct V_5 * V_6 )
{
struct V_1 * V_286 = F_3 ( V_6 ) ;
int V_30 ;
V_30 = F_139 ( V_6 ) ;
if ( V_30 )
return V_30 ;
return F_140 ( & V_6 -> V_356 -> V_357 ,
& V_286 -> V_287 . V_10 . V_357 ,
V_286 -> V_287 . V_10 . V_357 . V_37 ) ;
}
static void
F_141 ( struct V_5 * V_6 )
{
struct V_1 * V_286 = F_3 ( V_6 ) ;
F_142 ( & V_6 -> V_356 -> V_357 ,
V_286 -> V_287 . V_10 . V_357 . V_37 ) ;
F_143 ( V_6 ) ;
}
static void F_144 ( struct V_358 * V_3 )
{
struct V_1 * V_1 = F_1 ( F_145 ( V_3 ) ) ;
if ( V_1 -> V_104 != NULL )
F_146 ( V_3 -> V_10 ,
V_1 -> V_104 ) ;
F_147 ( & V_1 -> V_287 ) ;
F_148 ( V_3 ) ;
}
static void
F_149 ( struct V_1 * V_286 )
{
T_4 V_359 = 0 ;
unsigned int V_360 ;
switch ( V_286 -> V_361 ) {
case V_362 :
V_359 |= V_362 ;
case V_363 :
V_359 |= V_363 ;
case V_364 :
V_359 |= V_364 ;
case V_365 :
V_359 |= V_365 ;
case V_366 :
V_359 |= V_366 ;
case V_367 :
V_359 |= V_367 ;
break;
}
V_359 &= V_286 -> V_267 . V_280 ;
V_360 = F_104 ( V_359 ) ;
if ( V_360 > 3 )
V_360 = 3 ;
V_286 -> V_57 = 1 << V_360 ;
}
static void
F_150 ( struct V_11 * V_12 ,
struct V_1 * V_286 )
{
struct V_368 * V_369 ;
if ( V_286 -> V_17 == V_18 )
V_369 = & V_12 -> V_288 . V_370 [ 0 ] ;
else
V_369 = & V_12 -> V_288 . V_370 [ 1 ] ;
if ( V_369 -> V_371 )
V_286 -> V_57 = 1 << ( ( V_369 -> V_372 & 0xf0 ) >> 4 ) ;
else
F_149 ( V_286 ) ;
}
static void
F_151 ( struct V_11 * V_12 ,
struct V_1 * V_286 )
{
struct V_368 * V_369 ;
T_2 V_373 ;
if ( V_286 -> V_17 == V_18 )
V_369 = & V_12 -> V_288 . V_370 [ 0 ] ;
else
V_369 = & V_12 -> V_288 . V_370 [ 1 ] ;
if ( V_369 -> V_371 &&
F_152 ( V_12 , V_369 -> V_374 ) )
V_373 = V_369 -> V_374 ;
else
V_373 = V_375 ;
V_286 -> V_31 = F_108 ( V_12 , V_373 ) ;
F_153 ( V_286 -> V_31 , true ) ;
}
static void
F_154 ( struct V_1 * V_286 )
{
F_153 ( V_286 -> V_31 , false ) ;
}
static bool
F_155 ( struct V_1 * V_1 , int V_376 )
{
return F_54 ( V_1 ) ;
}
static T_2
F_156 ( struct V_9 * V_10 , struct V_1 * V_286 )
{
struct V_11 * V_12 = F_8 ( V_10 ) ;
struct V_368 * V_377 , * V_378 ;
if ( V_286 -> V_17 == V_18 ) {
V_377 = & V_12 -> V_288 . V_370 [ 0 ] ;
V_378 = & V_12 -> V_288 . V_370 [ 1 ] ;
} else {
V_377 = & V_12 -> V_288 . V_370 [ 1 ] ;
V_378 = & V_12 -> V_288 . V_370 [ 0 ] ;
}
if ( V_377 -> V_25 )
return V_377 -> V_25 ;
if ( V_378 -> V_25 ) {
if ( V_378 -> V_25 == 0x70 )
return 0x72 ;
else
return 0x70 ;
}
if ( V_286 -> V_17 == V_18 )
return 0x70 ;
else
return 0x72 ;
}
static int
F_157 ( struct V_7 * V_6 ,
struct V_1 * V_3 )
{
struct V_5 * V_5 ;
int V_30 ;
V_5 = & V_6 -> V_4 . V_4 ;
V_30 = F_158 ( V_3 -> V_4 . V_4 . V_10 ,
V_5 ,
& V_379 ,
V_6 -> V_4 . V_4 . V_380 ) ;
if ( V_30 < 0 )
return V_30 ;
F_159 ( V_5 ,
& V_381 ) ;
V_6 -> V_4 . V_4 . V_382 = 1 ;
V_6 -> V_4 . V_4 . V_383 = 0 ;
V_6 -> V_4 . V_4 . V_384 . V_385 = V_386 ;
V_6 -> V_4 . V_387 = F_81 ;
F_160 ( & V_6 -> V_4 , & V_3 -> V_4 ) ;
return 0 ;
}
static void
F_161 ( struct V_1 * V_1 ,
struct V_7 * V_6 )
{
struct V_9 * V_10 = V_6 -> V_4 . V_4 . V_10 ;
F_162 ( & V_6 -> V_4 . V_4 ) ;
if ( F_74 ( V_10 ) -> V_224 >= 4 && F_163 ( V_10 ) ) {
F_164 ( & V_6 -> V_4 . V_4 ) ;
V_1 -> V_205 = true ;
}
F_165 ( & V_6 -> V_4 . V_4 ) ;
V_1 -> V_210 = V_334 ;
}
static struct V_7 * F_166 ( void )
{
struct V_7 * V_388 ;
V_388 = F_24 ( sizeof( * V_388 ) , V_39 ) ;
if ( ! V_388 )
return NULL ;
if ( F_167 ( & V_388 -> V_4 ) < 0 ) {
F_26 ( V_388 ) ;
return NULL ;
}
return V_388 ;
}
static bool
F_168 ( struct V_1 * V_1 , int V_376 )
{
struct V_358 * V_3 = & V_1 -> V_4 . V_4 ;
struct V_5 * V_6 ;
struct V_2 * V_2 = F_145 ( V_3 ) ;
struct V_237 * V_237 ;
struct V_7 * V_7 ;
F_16 ( L_40 , V_376 ) ;
V_7 = F_166 () ;
if ( ! V_7 )
return false ;
if ( V_376 == 0 ) {
V_1 -> V_361 |= V_365 ;
V_7 -> V_239 = V_365 ;
} else if ( V_376 == 1 ) {
V_1 -> V_361 |= V_364 ;
V_7 -> V_239 = V_364 ;
}
V_237 = & V_7 -> V_4 ;
V_6 = & V_237 -> V_4 ;
if ( F_100 ( V_1 ) &
V_7 -> V_239 ) {
V_1 -> V_284 |= V_7 -> V_239 ;
V_2 -> V_389 = F_102 ;
F_102 ( V_2 ) ;
} else {
V_237 -> V_390 = V_391 | V_392 ;
}
V_3 -> V_393 = V_394 ;
V_6 -> V_380 = V_395 ;
if ( F_155 ( V_1 , V_376 ) ) {
V_6 -> V_380 = V_396 ;
V_1 -> V_208 = true ;
}
if ( F_157 ( V_7 , V_1 ) < 0 ) {
F_26 ( V_7 ) ;
return false ;
}
if ( V_1 -> V_208 )
F_161 ( V_1 , V_7 ) ;
return true ;
}
static bool
F_169 ( struct V_1 * V_1 , int type )
{
struct V_358 * V_3 = & V_1 -> V_4 . V_4 ;
struct V_5 * V_6 ;
struct V_237 * V_237 ;
struct V_7 * V_7 ;
F_16 ( L_41 , type ) ;
V_7 = F_166 () ;
if ( ! V_7 )
return false ;
V_237 = & V_7 -> V_4 ;
V_6 = & V_237 -> V_4 ;
V_3 -> V_393 = V_397 ;
V_6 -> V_380 = V_398 ;
V_1 -> V_361 |= type ;
V_7 -> V_239 = type ;
V_1 -> V_200 = true ;
if ( F_157 ( V_7 , V_1 ) < 0 ) {
F_26 ( V_7 ) ;
return false ;
}
if ( ! F_170 ( V_1 , V_7 , type ) )
goto V_399;
if ( ! F_171 ( V_1 , V_7 ) )
goto V_399;
return true ;
V_399:
F_130 ( V_6 ) ;
return false ;
}
static bool
F_172 ( struct V_1 * V_1 , int V_376 )
{
struct V_358 * V_3 = & V_1 -> V_4 . V_4 ;
struct V_5 * V_6 ;
struct V_237 * V_237 ;
struct V_7 * V_7 ;
F_16 ( L_42 , V_376 ) ;
V_7 = F_166 () ;
if ( ! V_7 )
return false ;
V_237 = & V_7 -> V_4 ;
V_6 = & V_237 -> V_4 ;
V_237 -> V_390 = V_391 ;
V_3 -> V_393 = V_400 ;
V_6 -> V_380 = V_401 ;
if ( V_376 == 0 ) {
V_1 -> V_361 |= V_367 ;
V_7 -> V_239 = V_367 ;
} else if ( V_376 == 1 ) {
V_1 -> V_361 |= V_366 ;
V_7 -> V_239 = V_366 ;
}
if ( F_157 ( V_7 , V_1 ) < 0 ) {
F_26 ( V_7 ) ;
return false ;
}
return true ;
}
static bool
F_173 ( struct V_1 * V_1 , int V_376 )
{
struct V_358 * V_3 = & V_1 -> V_4 . V_4 ;
struct V_5 * V_6 ;
struct V_237 * V_237 ;
struct V_7 * V_7 ;
F_16 ( L_43 , V_376 ) ;
V_7 = F_166 () ;
if ( ! V_7 )
return false ;
V_237 = & V_7 -> V_4 ;
V_6 = & V_237 -> V_4 ;
V_3 -> V_393 = V_402 ;
V_6 -> V_380 = V_403 ;
if ( V_376 == 0 ) {
V_1 -> V_361 |= V_363 ;
V_7 -> V_239 = V_363 ;
} else if ( V_376 == 1 ) {
V_1 -> V_361 |= V_362 ;
V_7 -> V_239 = V_362 ;
}
if ( F_157 ( V_7 , V_1 ) < 0 ) {
F_26 ( V_7 ) ;
return false ;
}
if ( ! F_171 ( V_1 , V_7 ) )
goto V_399;
return true ;
V_399:
F_130 ( V_6 ) ;
return false ;
}
static bool
F_174 ( struct V_1 * V_1 , T_4 V_26 )
{
V_1 -> V_200 = false ;
V_1 -> V_103 = false ;
if ( V_26 & V_365 )
if ( ! F_168 ( V_1 , 0 ) )
return false ;
if ( ( V_26 & V_404 ) == V_404 )
if ( ! F_168 ( V_1 , 1 ) )
return false ;
if ( V_26 & V_405 )
if ( ! F_169 ( V_1 , V_405 ) )
return false ;
if ( V_26 & V_406 )
if ( ! F_169 ( V_1 , V_406 ) )
return false ;
if ( V_26 & V_407 )
if ( ! F_169 ( V_1 , V_407 ) )
return false ;
if ( V_26 & V_367 )
if ( ! F_172 ( V_1 , 0 ) )
return false ;
if ( ( V_26 & V_408 ) == V_408 )
if ( ! F_172 ( V_1 , 1 ) )
return false ;
if ( V_26 & V_363 )
if ( ! F_173 ( V_1 , 0 ) )
return false ;
if ( ( V_26 & V_306 ) == V_306 )
if ( ! F_173 ( V_1 , 1 ) )
return false ;
if ( ( V_26 & V_409 ) == 0 ) {
unsigned char V_410 [ 2 ] ;
V_1 -> V_361 = 0 ;
memcpy ( V_410 , & V_1 -> V_267 . V_280 , 2 ) ;
F_16 ( L_44 ,
F_22 ( V_1 ) ,
V_410 [ 0 ] , V_410 [ 1 ] ) ;
return false ;
}
V_1 -> V_4 . V_411 = ( 1 << 0 ) | ( 1 << 1 ) | ( 1 << 2 ) ;
return true ;
}
static void F_175 ( struct V_1 * V_1 )
{
struct V_9 * V_10 = V_1 -> V_4 . V_4 . V_10 ;
struct V_5 * V_6 , * V_156 ;
F_176 (connector, tmp,
&dev->mode_config.connector_list, head) {
if ( F_4 ( V_6 ) == & V_1 -> V_4 ) {
F_177 ( V_6 ) ;
F_130 ( V_6 ) ;
}
}
}
static bool F_170 ( struct V_1 * V_1 ,
struct V_7 * V_7 ,
int type )
{
struct V_9 * V_10 = V_1 -> V_4 . V_4 . V_10 ;
struct V_177 V_178 ;
T_7 V_179 , V_15 ;
if ( ! F_41 ( V_1 , type ) )
return false ;
F_36 ( sizeof( V_178 ) != 6 ) ;
if ( ! F_33 ( V_1 ,
V_412 ,
& V_178 , sizeof( V_178 ) ) )
return false ;
memcpy ( & V_179 , & V_178 , V_89 ( sizeof( V_179 ) , sizeof( V_178 ) ) ) ;
if ( V_179 == 0 )
return false ;
V_7 -> V_413 = 0 ;
for ( V_15 = 0 ; V_15 < V_340 ; V_15 ++ )
if ( V_179 & ( 1 << V_15 ) )
V_7 -> V_341 [ V_7 -> V_413 ++ ] = V_15 ;
V_7 -> V_339 =
F_178 ( V_10 , V_414 ,
L_45 , V_7 -> V_413 ) ;
if ( ! V_7 -> V_339 )
return false ;
for ( V_15 = 0 ; V_15 < V_7 -> V_413 ; V_15 ++ )
F_179 (
V_7 -> V_339 , V_15 ,
V_15 , V_415 [ V_7 -> V_341 [ V_15 ] ] ) ;
V_1 -> V_180 = V_7 -> V_341 [ 0 ] ;
F_180 ( & V_7 -> V_4 . V_4 . V_4 ,
V_7 -> V_339 , 0 ) ;
return true ;
}
static bool
F_181 ( struct V_1 * V_1 ,
struct V_7 * V_7 ,
struct V_416 V_417 )
{
struct V_9 * V_10 = V_1 -> V_4 . V_4 . V_10 ;
struct V_5 * V_6 = & V_7 -> V_4 . V_4 ;
T_4 V_44 , V_418 [ 2 ] ;
if ( V_417 . V_419 ) {
if ( ! F_33 ( V_1 ,
V_420 ,
& V_418 , 4 ) )
return false ;
if ( ! F_33 ( V_1 ,
V_421 ,
& V_44 , 2 ) )
return false ;
V_7 -> V_346 = V_418 [ 0 ] ;
V_7 -> V_344 = V_418 [ 0 ] - V_44 ;
V_7 -> V_345 = V_7 -> V_344 ;
V_7 -> V_342 =
F_182 ( V_10 , 0 , L_46 , 0 , V_418 [ 0 ] ) ;
if ( ! V_7 -> V_342 )
return false ;
F_180 ( & V_6 -> V_4 ,
V_7 -> V_342 ,
V_7 -> V_344 ) ;
V_7 -> V_343 =
F_182 ( V_10 , 0 , L_47 , 0 , V_418 [ 0 ] ) ;
if ( ! V_7 -> V_343 )
return false ;
F_180 ( & V_6 -> V_4 ,
V_7 -> V_343 ,
V_7 -> V_345 ) ;
F_16 ( L_48
L_49 ,
V_418 [ 0 ] , V_418 [ 1 ] , V_44 ) ;
}
if ( V_417 . V_422 ) {
if ( ! F_33 ( V_1 ,
V_423 ,
& V_418 , 4 ) )
return false ;
if ( ! F_33 ( V_1 ,
V_424 ,
& V_44 , 2 ) )
return false ;
V_7 -> V_353 = V_418 [ 0 ] ;
V_7 -> V_351 = V_418 [ 0 ] - V_44 ;
V_7 -> V_352 = V_7 -> V_351 ;
V_7 -> V_349 =
F_182 ( V_10 , 0 ,
L_50 , 0 , V_418 [ 0 ] ) ;
if ( ! V_7 -> V_349 )
return false ;
F_180 ( & V_6 -> V_4 ,
V_7 -> V_349 ,
V_7 -> V_351 ) ;
V_7 -> V_350 =
F_182 ( V_10 , 0 ,
L_51 , 0 , V_418 [ 0 ] ) ;
if ( ! V_7 -> V_350 )
return false ;
F_180 ( & V_6 -> V_4 ,
V_7 -> V_350 ,
V_7 -> V_352 ) ;
F_16 ( L_52
L_49 ,
V_418 [ 0 ] , V_418 [ 1 ] , V_44 ) ;
}
F_183 ( V_425 , V_426 ) ;
F_183 ( V_427 , V_428 ) ;
F_183 ( V_429 , V_430 ) ;
F_183 ( V_431 , V_432 ) ;
F_183 ( V_433 , V_434 ) ;
F_183 ( V_435 , V_436 ) ;
F_183 ( V_437 , V_438 ) ;
F_183 ( V_439 , V_440 ) ;
F_183 ( V_441 , V_442 ) ;
F_183 ( V_443 , V_444 ) ;
F_183 ( V_445 , V_446 ) ;
F_183 ( V_447 , V_448 ) ;
if ( V_417 . V_449 ) {
if ( ! F_33 ( V_1 , V_450 , & V_44 , 2 ) )
return false ;
V_7 -> V_451 = 1 ;
V_7 -> V_452 = V_44 & 0x1 ;
V_7 -> V_449 =
F_182 ( V_10 , 0 , L_53 , 0 , 1 ) ;
if ( ! V_7 -> V_449 )
return false ;
F_180 ( & V_6 -> V_4 ,
V_7 -> V_449 ,
V_7 -> V_452 ) ;
F_16 ( L_54 , V_44 ) ;
}
return true ;
}
static bool
F_184 ( struct V_1 * V_1 ,
struct V_7 * V_7 ,
struct V_416 V_417 )
{
struct V_9 * V_10 = V_1 -> V_4 . V_4 . V_10 ;
struct V_5 * V_6 = & V_7 -> V_4 . V_4 ;
T_4 V_44 , V_418 [ 2 ] ;
F_183 ( V_437 , V_438 ) ;
return true ;
}
static bool F_171 ( struct V_1 * V_1 ,
struct V_7 * V_7 )
{
union {
struct V_416 V_309 ;
T_4 V_44 ;
} V_417 ;
F_36 ( sizeof( V_417 ) != 2 ) ;
V_417 . V_44 = 0 ;
F_33 ( V_1 ,
V_453 ,
& V_417 , sizeof( V_417 ) ) ;
if ( V_417 . V_44 == 0 ) {
F_16 ( L_55 ) ;
return true ;
}
if ( F_127 ( V_7 ) )
return F_181 ( V_1 , V_7 , V_417 . V_309 ) ;
else if ( F_128 ( V_7 ) )
return F_184 ( V_1 , V_7 , V_417 . V_309 ) ;
else
return true ;
}
static int F_185 ( struct V_454 * V_455 ,
struct V_23 * V_24 ,
int V_456 )
{
struct V_1 * V_286 = V_455 -> V_457 ;
if ( ! F_31 ( V_286 , V_286 -> V_57 ) )
return - V_355 ;
return V_286 -> V_31 -> V_458 -> V_459 ( V_286 -> V_31 , V_24 , V_456 ) ;
}
static T_1 F_186 ( struct V_454 * V_455 )
{
struct V_1 * V_286 = V_455 -> V_457 ;
return V_286 -> V_31 -> V_458 -> V_460 ( V_286 -> V_31 ) ;
}
static bool
F_187 ( struct V_1 * V_286 ,
struct V_9 * V_10 )
{
V_286 -> V_287 . V_461 = V_462 ;
V_286 -> V_287 . V_463 = V_464 ;
snprintf ( V_286 -> V_287 . V_37 , V_465 , L_56 ) ;
V_286 -> V_287 . V_10 . V_466 = & V_10 -> V_467 -> V_10 ;
V_286 -> V_287 . V_457 = V_286 ;
V_286 -> V_287 . V_458 = & V_468 ;
return F_188 ( & V_286 -> V_287 ) == 0 ;
}
static void F_189 ( const struct V_11 * V_12 ,
enum V_17 V_17 )
{
if ( F_9 ( V_12 ) )
F_190 ( V_17 != V_18 ) ;
else
F_190 ( V_17 != V_18 && V_17 != V_469 ) ;
}
bool F_191 ( struct V_9 * V_10 ,
T_10 V_16 , enum V_17 V_17 )
{
struct V_11 * V_12 = F_8 ( V_10 ) ;
struct V_2 * V_2 ;
struct V_1 * V_1 ;
int V_15 ;
F_189 ( V_12 , V_17 ) ;
V_1 = F_24 ( sizeof( * V_1 ) , V_39 ) ;
if ( ! V_1 )
return false ;
V_1 -> V_16 = V_16 ;
V_1 -> V_17 = V_17 ;
V_1 -> V_25 = F_156 ( V_10 , V_1 ) >> 1 ;
F_151 ( V_12 , V_1 ) ;
if ( ! F_187 ( V_1 , V_10 ) )
goto V_470;
V_2 = & V_1 -> V_4 ;
V_2 -> type = V_471 ;
F_192 ( V_10 , & V_2 -> V_4 , & V_472 , 0 ,
L_57 , F_193 ( V_17 ) ) ;
for ( V_15 = 0 ; V_15 < 0x40 ; V_15 ++ ) {
T_2 V_473 ;
if ( ! F_14 ( V_1 , V_15 , & V_473 ) ) {
F_16 ( L_58 ,
F_22 ( V_1 ) ) ;
goto V_399;
}
}
V_2 -> V_474 = F_70 ;
if ( F_9 ( V_10 ) ) {
V_2 -> V_475 = F_94 ;
V_2 -> V_476 = F_95 ;
} else {
V_2 -> V_475 = F_90 ;
}
V_2 -> V_477 = F_72 ;
V_2 -> V_478 = F_96 ;
V_2 -> V_387 = F_82 ;
V_2 -> V_479 = F_86 ;
if ( ! F_99 ( V_1 , & V_1 -> V_267 ) )
goto V_399;
if ( F_174 ( V_1 ,
V_1 -> V_267 . V_280 ) != true ) {
F_16 ( L_59 ,
F_22 ( V_1 ) ) ;
goto V_480;
}
if ( V_1 -> V_284 ) {
if ( V_1 -> V_17 == V_18 )
V_2 -> V_481 = V_482 ;
else
V_2 -> V_481 = V_483 ;
}
V_1 -> V_4 . V_484 = 0 ;
F_150 ( V_12 , V_1 ) ;
if ( ! F_34 ( V_1 ) )
goto V_480;
if ( ! F_40 ( V_1 ,
& V_1 -> V_260 ,
& V_1 -> V_262 ) )
goto V_480;
F_16 ( L_60
L_61
L_62
L_63 ,
F_22 ( V_1 ) ,
V_1 -> V_267 . V_269 , V_1 -> V_267 . V_270 ,
V_1 -> V_267 . V_271 ,
V_1 -> V_260 / 1000 ,
V_1 -> V_262 / 1000 ,
( V_1 -> V_267 . V_274 & 0x1 ) ? 'Y' : 'N' ,
( V_1 -> V_267 . V_274 & 0x2 ) ? 'Y' : 'N' ,
V_1 -> V_267 . V_280 &
( V_365 | V_367 ) ? 'Y' : 'N' ,
V_1 -> V_267 . V_280 &
( V_364 | V_366 ) ? 'Y' : 'N' ) ;
return true ;
V_480:
F_175 ( V_1 ) ;
V_399:
F_194 ( & V_2 -> V_4 ) ;
F_147 ( & V_1 -> V_287 ) ;
V_470:
F_154 ( V_1 ) ;
F_26 ( V_1 ) ;
return false ;
}
