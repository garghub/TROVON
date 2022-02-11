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
if ( F_12 ( V_12 ) ) {
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
struct V_161 * V_162 )
{
T_5 V_163 [ F_60 ( V_164 ) ] ;
union V_165 V_166 ;
int V_30 ;
T_6 V_27 ;
V_30 = F_61 ( & V_166 . V_167 ,
& V_162 -> V_4 . V_55 ) ;
if ( V_30 < 0 ) {
F_62 ( L_14 ) ;
return false ;
}
if ( V_1 -> V_168 ) {
if ( V_162 -> V_169 )
V_166 . V_167 . V_170 =
V_171 ;
else
V_166 . V_167 . V_170 =
V_172 ;
}
V_27 = F_63 ( & V_166 , V_163 , sizeof( V_163 ) ) ;
if ( V_27 < 0 )
return false ;
return F_57 ( V_1 , V_173 ,
V_174 ,
V_163 , sizeof( V_163 ) ) ;
}
static bool F_64 ( struct V_1 * V_1 )
{
struct V_175 V_176 ;
T_7 V_177 ;
V_177 = 1 << V_1 -> V_178 ;
memset ( & V_176 , 0 , sizeof( V_176 ) ) ;
memcpy ( & V_176 , & V_177 , V_89 ( sizeof( V_176 ) , sizeof( V_177 ) ) ) ;
F_36 ( sizeof( V_176 ) != 6 ) ;
return F_32 ( V_1 ,
V_179 ,
& V_176 , sizeof( V_176 ) ) ;
}
static bool
F_65 ( struct V_1 * V_1 ,
const struct V_54 * V_73 )
{
struct V_92 V_180 ;
if ( ! F_41 ( V_1 ,
V_1 -> V_181 ) )
return false ;
F_50 ( & V_180 , V_73 ) ;
if ( ! F_45 ( V_1 , & V_180 ) )
return false ;
return true ;
}
static bool
F_66 ( struct V_1 * V_1 ,
const struct V_54 * V_73 ,
struct V_54 * V_55 )
{
struct V_92 V_182 ;
if ( ! F_34 ( V_1 ) )
return false ;
if ( ! F_47 ( V_1 ,
V_73 -> clock / 10 ,
V_73 -> V_105 ,
V_73 -> V_106 ) )
return false ;
if ( ! F_48 ( V_1 ,
& V_182 ) )
return false ;
F_51 ( V_55 , & V_182 ) ;
V_1 -> V_183 = V_182 . V_95 . V_184 ;
return true ;
}
static void F_67 ( struct V_161 * V_162 )
{
unsigned V_185 = V_162 -> V_186 ;
struct V_187 * clock = & V_162 -> V_187 ;
if ( V_185 >= 100000 && V_185 < 140500 ) {
clock -> V_188 = 2 ;
clock -> V_189 = 10 ;
clock -> V_190 = 3 ;
clock -> V_191 = 16 ;
clock -> V_192 = 8 ;
} else if ( V_185 >= 140500 && V_185 <= 200000 ) {
clock -> V_188 = 1 ;
clock -> V_189 = 10 ;
clock -> V_190 = 6 ;
clock -> V_191 = 12 ;
clock -> V_192 = 8 ;
} else {
F_68 ( 1 , L_15 , V_185 ) ;
}
V_162 -> V_193 = true ;
}
static bool F_69 ( struct V_2 * V_3 ,
struct V_161 * V_162 ,
struct V_194 * V_195 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_54 * V_55 = & V_162 -> V_4 . V_55 ;
struct V_54 * V_73 = & V_162 -> V_4 . V_73 ;
F_16 ( L_16 ) ;
V_162 -> V_196 = 8 * 3 ;
if ( F_9 ( F_8 ( V_3 -> V_4 . V_10 ) ) )
V_162 -> V_197 = true ;
if ( V_1 -> V_198 ) {
if ( ! F_65 ( V_1 , V_73 ) )
return false ;
( void ) F_66 ( V_1 ,
V_73 ,
V_55 ) ;
V_162 -> V_199 = true ;
} else if ( V_1 -> V_103 ) {
if ( ! F_65 ( V_1 ,
V_1 -> V_104 ) )
return false ;
( void ) F_66 ( V_1 ,
V_73 ,
V_55 ) ;
}
V_162 -> V_200 =
F_30 ( V_55 ) ;
V_162 -> V_201 = V_1 -> V_202 ;
if ( V_1 -> V_203 ) {
if ( V_162 -> V_201 &&
F_70 ( V_55 ) > 1 )
V_162 -> V_169 = true ;
} else {
if ( V_162 -> V_201 &&
V_1 -> V_204 == V_205 )
V_162 -> V_169 = true ;
}
if ( V_1 -> V_198 )
F_67 ( V_162 ) ;
if ( V_1 -> V_206 )
V_55 -> V_207 = V_1 -> V_208 ;
return true ;
}
static void F_71 ( struct V_2 * V_2 ,
struct V_161 * V_209 ,
struct V_194 * V_195 )
{
struct V_11 * V_12 = F_8 ( V_2 -> V_4 . V_10 ) ;
struct V_210 * V_211 = F_72 ( V_209 -> V_4 . V_211 ) ;
const struct V_54 * V_55 = & V_209 -> V_4 . V_55 ;
struct V_54 * V_73 = & V_209 -> V_4 . V_73 ;
struct V_1 * V_1 = F_1 ( V_2 ) ;
T_1 V_212 ;
struct V_213 V_214 ;
struct V_92 V_182 , V_180 ;
int V_215 ;
V_214 . V_216 = V_1 -> V_181 ;
V_214 . V_217 = 0 ;
F_32 ( V_1 ,
V_218 ,
& V_214 , sizeof( V_214 ) ) ;
if ( ! F_41 ( V_1 ,
V_1 -> V_181 ) )
return;
if ( V_1 -> V_103 )
F_50 ( & V_180 ,
V_1 -> V_104 ) ;
else
F_50 ( & V_180 , V_73 ) ;
if ( ! F_45 ( V_1 , & V_180 ) )
F_73 ( L_17 ,
F_22 ( V_1 ) ) ;
if ( ! F_34 ( V_1 ) )
return;
if ( V_209 -> V_201 ) {
F_55 ( V_1 , V_219 ) ;
F_56 ( V_1 ,
V_220 ) ;
F_59 ( V_1 , V_209 ) ;
} else
F_55 ( V_1 , V_221 ) ;
if ( V_1 -> V_198 &&
! F_64 ( V_1 ) )
return;
F_50 ( & V_182 , V_55 ) ;
if ( V_1 -> V_198 || V_1 -> V_103 )
V_182 . V_95 . V_184 = V_1 -> V_183 ;
if ( ! F_44 ( V_1 , & V_182 ) )
F_73 ( L_18 ,
F_22 ( V_1 ) ) ;
switch ( V_209 -> V_200 ) {
default:
F_68 ( 1 , L_19 ) ;
case 1 : V_215 = V_222 ; break;
case 2 : V_215 = V_223 ; break;
case 4 : V_215 = V_224 ; break;
}
if ( ! F_49 ( V_1 , V_215 ) )
return;
if ( F_74 ( V_12 ) >= 4 ) {
V_212 = V_225 | V_226 ;
if ( ! F_9 ( V_12 ) && V_209 -> V_169 )
V_212 |= V_205 ;
if ( F_74 ( V_12 ) < 5 )
V_212 |= V_227 ;
} else {
V_212 = F_13 ( V_1 -> V_16 ) ;
if ( V_1 -> V_17 == V_18 )
V_212 &= V_228 ;
else
V_212 &= V_229 ;
V_212 |= ( 9 << 19 ) | V_227 ;
}
if ( F_75 ( V_12 ) >= V_230 )
V_212 |= F_76 ( V_211 -> V_231 ) ;
else
V_212 |= F_77 ( V_211 -> V_231 ) ;
if ( V_1 -> V_232 )
V_212 |= V_233 ;
if ( F_74 ( V_12 ) >= 4 ) {
} else if ( F_78 ( V_12 ) || F_79 ( V_12 ) ||
F_80 ( V_12 ) || F_81 ( V_12 ) ) {
} else {
V_212 |= ( V_209 -> V_200 - 1 )
<< V_234 ;
}
if ( V_182 . V_95 . V_184 & V_235 &&
F_74 ( V_12 ) < 5 )
V_212 |= V_236 ;
F_7 ( V_1 , V_212 ) ;
}
static bool F_82 ( struct V_237 * V_6 )
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
static bool F_83 ( struct V_2 * V_3 ,
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
if ( F_84 ( V_12 ) )
* V_231 = F_85 ( V_156 ) ;
else
* V_231 = F_86 ( V_156 ) ;
return true ;
}
static void F_87 ( struct V_2 * V_3 ,
struct V_161 * V_162 )
{
struct V_9 * V_10 = V_3 -> V_4 . V_10 ;
struct V_11 * V_12 = F_8 ( V_10 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_92 V_93 ;
int V_241 = 0 ;
int V_185 ;
T_1 V_26 = 0 , V_212 ;
T_2 V_8 ;
bool V_30 ;
V_212 = F_13 ( V_1 -> V_16 ) ;
V_30 = F_46 ( V_1 , & V_93 ) ;
if ( ! V_30 ) {
F_88 ( L_20 ) ;
V_162 -> V_242 |= V_243 ;
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
V_162 -> V_4 . V_55 . V_26 |= V_26 ;
if ( F_89 ( V_12 ) || F_90 ( V_12 ) ) {
V_162 -> V_200 =
( ( V_212 & V_244 )
>> V_234 ) + 1 ;
}
V_185 = V_162 -> V_186 ;
if ( V_162 -> V_200 )
V_185 /= V_162 -> V_200 ;
V_162 -> V_4 . V_55 . V_56 = V_185 ;
if ( F_33 ( V_1 , V_245 ,
& V_8 , 1 ) ) {
switch ( V_8 ) {
case V_222 :
V_241 = 1 ;
break;
case V_223 :
V_241 = 2 ;
break;
case V_224 :
V_241 = 4 ;
break;
}
}
if ( V_212 & V_205 )
V_162 -> V_169 = true ;
if ( F_33 ( V_1 , V_246 ,
& V_8 , 1 ) ) {
if ( V_8 == V_219 )
V_162 -> V_201 = true ;
}
F_68 ( V_241 != V_162 -> V_200 ,
L_21 ,
V_162 -> V_200 , V_241 ) ;
}
static void F_91 ( struct V_2 * V_3 ,
struct V_161 * V_247 ,
struct V_194 * V_195 )
{
struct V_11 * V_12 = F_8 ( V_3 -> V_4 . V_10 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_210 * V_211 = F_72 ( V_3 -> V_4 . V_211 ) ;
T_1 V_248 ;
F_37 ( V_1 , 0 ) ;
if ( 0 )
F_39 ( V_1 ,
V_81 ) ;
V_248 = F_13 ( V_1 -> V_16 ) ;
V_248 &= ~ V_240 ;
F_7 ( V_1 , V_248 ) ;
if ( F_12 ( V_12 ) && V_211 -> V_231 == V_249 ) {
F_92 ( V_12 , V_250 , false ) ;
F_93 ( V_12 , V_250 , false ) ;
V_248 &= ~ V_251 ;
V_248 |= V_240 ;
F_7 ( V_1 , V_248 ) ;
V_248 &= ~ V_240 ;
F_7 ( V_1 , V_248 ) ;
F_94 ( V_12 , V_250 ) ;
F_92 ( V_12 , V_250 , true ) ;
F_93 ( V_12 , V_250 , true ) ;
}
}
static void F_95 ( struct V_2 * V_3 ,
struct V_161 * V_247 ,
struct V_194 * V_252 )
{
}
static void F_96 ( struct V_2 * V_3 ,
struct V_161 * V_247 ,
struct V_194 * V_252 )
{
F_91 ( V_3 , V_247 , V_252 ) ;
}
static void F_97 ( struct V_2 * V_3 ,
struct V_161 * V_162 ,
struct V_194 * V_195 )
{
struct V_9 * V_10 = V_3 -> V_4 . V_10 ;
struct V_11 * V_12 = F_8 ( V_10 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_210 * V_210 = F_72 ( V_3 -> V_4 . V_211 ) ;
T_1 V_248 ;
bool V_253 , V_254 ;
int V_15 ;
bool V_255 ;
V_248 = F_13 ( V_1 -> V_16 ) ;
V_248 |= V_240 ;
F_7 ( V_1 , V_248 ) ;
for ( V_15 = 0 ; V_15 < 2 ; V_15 ++ )
F_98 ( V_12 , V_210 -> V_231 ) ;
V_255 = F_35 ( V_1 , & V_253 , & V_254 ) ;
if ( V_255 && ! V_253 ) {
F_16 ( L_22
L_23 , F_22 ( V_1 ) ) ;
}
if ( 0 )
F_39 ( V_1 ,
V_76 ) ;
F_37 ( V_1 , V_1 -> V_181 ) ;
}
static enum V_256
F_99 ( struct V_5 * V_6 ,
struct V_54 * V_73 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
int V_257 = F_8 ( V_6 -> V_10 ) -> V_258 ;
if ( V_73 -> V_26 & V_259 )
return V_260 ;
if ( V_1 -> V_261 > V_73 -> clock )
return V_262 ;
if ( V_1 -> V_263 < V_73 -> clock )
return V_264 ;
if ( V_73 -> clock > V_257 )
return V_264 ;
if ( V_1 -> V_103 ) {
if ( V_73 -> V_105 > V_1 -> V_104 -> V_105 )
return V_265 ;
if ( V_73 -> V_106 > V_1 -> V_104 -> V_106 )
return V_265 ;
}
return V_266 ;
}
static bool F_100 ( struct V_1 * V_1 , struct V_267 * V_268 )
{
F_36 ( sizeof( * V_268 ) != 8 ) ;
if ( ! F_33 ( V_1 ,
V_269 ,
V_268 , sizeof( * V_268 ) ) )
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
V_268 -> V_270 ,
V_268 -> V_271 ,
V_268 -> V_272 ,
V_268 -> V_273 ,
V_268 -> V_274 ,
V_268 -> V_275 ,
V_268 -> V_276 ,
V_268 -> V_277 ,
V_268 -> V_278 ,
V_268 -> V_279 ,
V_268 -> V_280 ,
V_268 -> V_281 ) ;
return true ;
}
static T_4 F_101 ( struct V_1 * V_1 )
{
struct V_11 * V_12 = F_8 ( V_1 -> V_4 . V_4 . V_10 ) ;
T_4 V_282 ;
if ( ! F_102 ( V_12 ) )
return 0 ;
if ( F_78 ( V_12 ) || F_79 ( V_12 ) )
return 0 ;
if ( ! F_33 ( V_1 , V_283 ,
& V_282 , sizeof( V_282 ) ) )
return 0 ;
return V_282 ;
}
static void F_103 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
F_23 ( V_1 , V_284 ,
& V_1 -> V_285 , 2 ) ;
}
static bool
F_104 ( struct V_1 * V_1 )
{
return F_105 ( V_1 -> V_268 . V_281 ) > 1 ;
}
static struct V_286 *
F_106 ( struct V_5 * V_6 )
{
struct V_1 * V_287 = F_3 ( V_6 ) ;
return F_107 ( V_6 , & V_287 -> V_288 ) ;
}
static struct V_286 *
F_108 ( struct V_5 * V_6 )
{
struct V_11 * V_12 = F_8 ( V_6 -> V_10 ) ;
return F_107 ( V_6 ,
F_109 ( V_12 ,
V_12 -> V_289 . V_290 ) ) ;
}
static enum V_291
F_110 ( struct V_5 * V_6 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
enum V_291 V_38 ;
struct V_286 * V_286 ;
V_286 = F_106 ( V_6 ) ;
if ( V_286 == NULL && F_104 ( V_1 ) ) {
T_2 V_288 , V_292 = V_1 -> V_57 ;
for ( V_288 = V_1 -> V_57 >> 1 ; V_288 > 1 ; V_288 >>= 1 ) {
V_1 -> V_57 = V_288 ;
V_286 = F_106 ( V_6 ) ;
if ( V_286 )
break;
}
if ( V_286 == NULL )
V_1 -> V_57 = V_292 ;
}
if ( V_286 == NULL )
V_286 = F_108 ( V_6 ) ;
V_38 = V_293 ;
if ( V_286 != NULL ) {
if ( V_286 -> V_294 & V_295 ) {
V_38 = V_296 ;
if ( V_1 -> V_206 ) {
V_1 -> V_202 = F_111 ( V_286 ) ;
V_1 -> V_232 = F_112 ( V_286 ) ;
V_1 -> V_168 =
F_113 ( V_286 ) ;
}
} else
V_38 = V_297 ;
F_26 ( V_286 ) ;
}
if ( V_38 == V_296 ) {
struct V_7 * V_7 = F_5 ( V_6 ) ;
if ( V_7 -> V_298 != V_299 )
V_1 -> V_232 = ( V_7 -> V_298 == V_300 ) ;
}
return V_38 ;
}
static bool
F_114 ( struct V_7 * V_287 ,
struct V_286 * V_286 )
{
bool V_301 = ! ! ( V_286 -> V_294 & V_295 ) ;
bool V_302 = ! ! F_115 ( V_287 ) ;
F_16 ( L_37 ,
V_302 , V_301 ) ;
return V_302 == V_301 ;
}
static enum V_291
F_116 ( struct V_5 * V_6 , bool V_303 )
{
T_4 V_44 ;
struct V_1 * V_1 = F_3 ( V_6 ) ;
struct V_7 * V_7 = F_5 ( V_6 ) ;
enum V_291 V_30 ;
F_16 ( L_38 ,
V_6 -> V_4 . V_304 , V_6 -> V_37 ) ;
if ( ! F_33 ( V_1 ,
V_305 ,
& V_44 , 2 ) )
return V_293 ;
F_16 ( L_39 ,
V_44 & 0xff , V_44 >> 8 ,
V_7 -> V_239 ) ;
if ( V_44 == 0 )
return V_297 ;
V_1 -> V_181 = V_44 ;
V_1 -> V_202 = false ;
V_1 -> V_232 = false ;
V_1 -> V_168 = false ;
if ( ( V_7 -> V_239 & V_44 ) == 0 )
V_30 = V_297 ;
else if ( F_117 ( V_7 ) )
V_30 = F_110 ( V_6 ) ;
else {
struct V_286 * V_286 ;
V_286 = F_106 ( V_6 ) ;
if ( V_286 == NULL )
V_286 = F_108 ( V_6 ) ;
if ( V_286 != NULL ) {
if ( F_114 ( V_7 ,
V_286 ) )
V_30 = V_296 ;
else
V_30 = V_297 ;
F_26 ( V_286 ) ;
} else
V_30 = V_296 ;
}
if ( V_30 == V_296 ) {
V_1 -> V_198 = false ;
V_1 -> V_103 = false ;
if ( V_44 & V_306 )
V_1 -> V_198 = true ;
if ( V_44 & V_307 )
V_1 -> V_103 = V_1 -> V_104 != NULL ;
}
return V_30 ;
}
static void F_118 ( struct V_5 * V_6 )
{
struct V_286 * V_286 ;
F_16 ( L_38 ,
V_6 -> V_4 . V_304 , V_6 -> V_37 ) ;
V_286 = F_106 ( V_6 ) ;
if ( V_286 == NULL )
V_286 = F_108 ( V_6 ) ;
if ( V_286 != NULL ) {
if ( F_114 ( F_5 ( V_6 ) ,
V_286 ) ) {
F_119 ( V_6 , V_286 ) ;
F_120 ( V_6 , V_286 ) ;
}
F_26 ( V_286 ) ;
}
}
static void F_121 ( struct V_5 * V_6 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
struct V_308 V_309 ;
T_7 V_310 = 0 , V_177 = 0 ;
int V_15 ;
F_16 ( L_38 ,
V_6 -> V_4 . V_304 , V_6 -> V_37 ) ;
V_177 = 1 << V_1 -> V_178 ;
memcpy ( & V_309 , & V_177 ,
V_89 ( sizeof( V_177 ) , sizeof( struct V_308 ) ) ) ;
if ( ! F_41 ( V_1 , V_1 -> V_181 ) )
return;
F_36 ( sizeof( V_309 ) != 3 ) ;
if ( ! F_23 ( V_1 ,
V_311 ,
& V_309 , sizeof( V_309 ) ) )
return;
if ( ! F_27 ( V_1 , & V_310 , 3 ) )
return;
for ( V_15 = 0 ; V_15 < F_20 ( V_312 ) ; V_15 ++ )
if ( V_310 & ( 1 << V_15 ) ) {
struct V_54 * V_313 ;
V_313 = F_122 ( V_6 -> V_10 ,
& V_312 [ V_15 ] ) ;
if ( V_313 )
F_123 ( V_6 , V_313 ) ;
}
}
static void F_124 ( struct V_5 * V_6 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
struct V_11 * V_12 = F_8 ( V_6 -> V_10 ) ;
struct V_54 * V_314 ;
F_16 ( L_38 ,
V_6 -> V_4 . V_304 , V_6 -> V_37 ) ;
if ( V_12 -> V_289 . V_315 != NULL ) {
V_314 = F_122 ( V_6 -> V_10 ,
V_12 -> V_289 . V_315 ) ;
if ( V_314 != NULL ) {
V_314 -> type = ( V_316 |
V_317 ) ;
F_123 ( V_6 , V_314 ) ;
}
}
F_125 ( V_6 , & V_1 -> V_288 ) ;
F_126 (newmode, &connector->probed_modes, head) {
if ( V_314 -> type & V_316 ) {
V_1 -> V_104 =
F_122 ( V_6 -> V_10 , V_314 ) ;
V_1 -> V_103 = true ;
break;
}
}
}
static int F_127 ( struct V_5 * V_6 )
{
struct V_7 * V_7 = F_5 ( V_6 ) ;
if ( F_128 ( V_7 ) )
F_121 ( V_6 ) ;
else if ( F_129 ( V_7 ) )
F_124 ( V_6 ) ;
else
F_118 ( V_6 ) ;
return ! F_130 ( & V_6 -> V_318 ) ;
}
static void F_131 ( struct V_5 * V_6 )
{
struct V_7 * V_7 = F_5 ( V_6 ) ;
F_132 ( V_6 ) ;
F_26 ( V_7 ) ;
}
static bool F_133 ( struct V_5 * V_6 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
struct V_286 * V_286 ;
bool V_319 = false ;
if ( ! V_1 -> V_206 )
return false ;
V_286 = F_106 ( V_6 ) ;
if ( V_286 != NULL && V_286 -> V_294 & V_295 )
V_319 = F_112 ( V_286 ) ;
F_26 ( V_286 ) ;
return V_319 ;
}
static int
F_134 ( struct V_5 * V_6 ,
struct V_320 * V_321 ,
T_8 V_8 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
struct V_7 * V_7 = F_5 ( V_6 ) ;
struct V_11 * V_12 = F_8 ( V_6 -> V_10 ) ;
T_4 V_322 ;
T_5 V_32 ;
int V_30 ;
V_30 = F_135 ( & V_6 -> V_4 , V_321 , V_8 ) ;
if ( V_30 )
return V_30 ;
if ( V_321 == V_12 -> V_323 ) {
int V_15 = V_8 ;
bool V_319 ;
if ( V_15 == V_7 -> V_298 )
return 0 ;
V_7 -> V_298 = V_15 ;
if ( V_15 == V_299 )
V_319 = F_133 ( V_6 ) ;
else
V_319 = ( V_15 == V_300 ) ;
if ( V_319 == V_1 -> V_232 )
return 0 ;
V_1 -> V_232 = V_319 ;
goto V_324;
}
if ( V_321 == V_12 -> V_325 ) {
bool V_326 = V_1 -> V_203 ;
T_7 V_327 = V_1 -> V_204 ;
switch ( V_8 ) {
case V_328 :
V_1 -> V_203 = true ;
break;
case V_329 :
V_1 -> V_203 = false ;
V_1 -> V_204 = 0 ;
break;
case V_330 :
V_1 -> V_203 = false ;
V_1 -> V_204 = V_205 ;
break;
default:
return - V_331 ;
}
if ( V_326 == V_1 -> V_203 &&
V_327 == V_1 -> V_204 )
return 0 ;
goto V_324;
}
if ( V_321 == V_6 -> V_10 -> V_332 . V_333 ) {
switch ( V_8 ) {
case V_334 :
V_1 -> V_208 = V_335 ;
break;
case V_336 :
V_1 -> V_208 = V_337 ;
break;
case V_338 :
V_1 -> V_208 = V_339 ;
break;
default:
return - V_331 ;
}
goto V_324;
}
#define F_136 ( V_37 , T_9 ) \
if (intel_sdvo_connector->name == property) { \
if (intel_sdvo_connector->cur_##name == temp_value) return 0; \
if (intel_sdvo_connector->max_##name < temp_value) return -EINVAL; \
cmd = SDVO_CMD_SET_##NAME; \
intel_sdvo_connector->cur_##name = temp_value; \
goto set_value; \
}
if ( V_321 == V_7 -> V_340 ) {
if ( V_8 >= V_341 )
return - V_331 ;
if ( V_1 -> V_178 ==
V_7 -> V_342 [ V_8 ] )
return 0 ;
V_1 -> V_178 = V_7 -> V_342 [ V_8 ] ;
goto V_324;
} else if ( F_137 ( V_7 ) ) {
V_322 = V_8 ;
if ( V_7 -> V_343 == V_321 ) {
F_135 ( & V_6 -> V_4 ,
V_7 -> V_344 , V_8 ) ;
if ( V_7 -> V_345 == V_322 )
return 0 ;
V_7 -> V_345 = V_322 ;
V_7 -> V_346 = V_322 ;
V_322 = V_7 -> V_347 -
V_7 -> V_345 ;
V_32 = V_348 ;
goto V_349;
} else if ( V_7 -> V_344 == V_321 ) {
F_135 ( & V_6 -> V_4 ,
V_7 -> V_343 , V_8 ) ;
if ( V_7 -> V_346 == V_322 )
return 0 ;
V_7 -> V_345 = V_322 ;
V_7 -> V_346 = V_322 ;
V_322 = V_7 -> V_347 -
V_7 -> V_345 ;
V_32 = V_348 ;
goto V_349;
} else if ( V_7 -> V_350 == V_321 ) {
F_135 ( & V_6 -> V_4 ,
V_7 -> V_351 , V_8 ) ;
if ( V_7 -> V_352 == V_322 )
return 0 ;
V_7 -> V_352 = V_322 ;
V_7 -> V_353 = V_322 ;
V_322 = V_7 -> V_354 -
V_7 -> V_352 ;
V_32 = V_355 ;
goto V_349;
} else if ( V_7 -> V_351 == V_321 ) {
F_135 ( & V_6 -> V_4 ,
V_7 -> V_350 , V_8 ) ;
if ( V_7 -> V_353 == V_322 )
return 0 ;
V_7 -> V_352 = V_322 ;
V_7 -> V_353 = V_322 ;
V_322 = V_7 -> V_354 -
V_7 -> V_352 ;
V_32 = V_355 ;
goto V_349;
}
F_136 (hpos, HPOS)
F_136 (vpos, VPOS)
F_136 (saturation, SATURATION)
F_136 (contrast, CONTRAST)
F_136 (hue, HUE)
F_136 (brightness, BRIGHTNESS)
F_136 (sharpness, SHARPNESS)
F_136 (flicker_filter, FLICKER_FILTER)
F_136 (flicker_filter_2d, FLICKER_FILTER_2D)
F_136 (flicker_filter_adaptive, FLICKER_FILTER_ADAPTIVE)
F_136 (tv_chroma_filter, TV_CHROMA_FILTER)
F_136 (tv_luma_filter, TV_LUMA_FILTER)
F_136 (dot_crawl, DOT_CRAWL)
}
return - V_331 ;
V_349:
if ( ! F_32 ( V_1 , V_32 , & V_322 , 2 ) )
return - V_356 ;
V_324:
if ( V_1 -> V_4 . V_4 . V_211 )
F_138 ( V_1 -> V_4 . V_4 . V_211 ) ;
return 0 ;
#undef F_136
}
static int
F_139 ( struct V_5 * V_6 )
{
struct V_1 * V_287 = F_3 ( V_6 ) ;
int V_30 ;
V_30 = F_140 ( V_6 ) ;
if ( V_30 )
return V_30 ;
return F_141 ( & V_6 -> V_357 -> V_358 ,
& V_287 -> V_288 . V_10 . V_358 ,
V_287 -> V_288 . V_10 . V_358 . V_37 ) ;
}
static void
F_142 ( struct V_5 * V_6 )
{
struct V_1 * V_287 = F_3 ( V_6 ) ;
F_143 ( & V_6 -> V_357 -> V_358 ,
V_287 -> V_288 . V_10 . V_358 . V_37 ) ;
F_144 ( V_6 ) ;
}
static void F_145 ( struct V_359 * V_3 )
{
struct V_1 * V_1 = F_1 ( F_146 ( V_3 ) ) ;
if ( V_1 -> V_104 != NULL )
F_147 ( V_3 -> V_10 ,
V_1 -> V_104 ) ;
F_148 ( & V_1 -> V_288 ) ;
F_149 ( V_3 ) ;
}
static void
F_150 ( struct V_1 * V_287 )
{
T_4 V_360 = 0 ;
unsigned int V_361 ;
switch ( V_287 -> V_362 ) {
case V_363 :
V_360 |= V_363 ;
case V_364 :
V_360 |= V_364 ;
case V_365 :
V_360 |= V_365 ;
case V_366 :
V_360 |= V_366 ;
case V_367 :
V_360 |= V_367 ;
case V_368 :
V_360 |= V_368 ;
break;
}
V_360 &= V_287 -> V_268 . V_281 ;
V_361 = F_105 ( V_360 ) ;
if ( V_361 > 3 )
V_361 = 3 ;
V_287 -> V_57 = 1 << V_361 ;
}
static void
F_151 ( struct V_11 * V_12 ,
struct V_1 * V_287 )
{
struct V_369 * V_370 ;
if ( V_287 -> V_17 == V_18 )
V_370 = & V_12 -> V_289 . V_371 [ 0 ] ;
else
V_370 = & V_12 -> V_289 . V_371 [ 1 ] ;
if ( V_370 -> V_372 )
V_287 -> V_57 = 1 << ( ( V_370 -> V_373 & 0xf0 ) >> 4 ) ;
else
F_150 ( V_287 ) ;
}
static void
F_152 ( struct V_11 * V_12 ,
struct V_1 * V_287 )
{
struct V_369 * V_370 ;
T_2 V_374 ;
if ( V_287 -> V_17 == V_18 )
V_370 = & V_12 -> V_289 . V_371 [ 0 ] ;
else
V_370 = & V_12 -> V_289 . V_371 [ 1 ] ;
if ( V_370 -> V_372 &&
F_153 ( V_12 , V_370 -> V_375 ) )
V_374 = V_370 -> V_375 ;
else
V_374 = V_376 ;
V_287 -> V_31 = F_109 ( V_12 , V_374 ) ;
F_154 ( V_287 -> V_31 , true ) ;
}
static void
F_155 ( struct V_1 * V_287 )
{
F_154 ( V_287 -> V_31 , false ) ;
}
static bool
F_156 ( struct V_1 * V_1 , int V_377 )
{
return F_54 ( V_1 ) ;
}
static T_2
F_157 ( struct V_11 * V_12 ,
struct V_1 * V_287 )
{
struct V_369 * V_378 , * V_379 ;
if ( V_287 -> V_17 == V_18 ) {
V_378 = & V_12 -> V_289 . V_371 [ 0 ] ;
V_379 = & V_12 -> V_289 . V_371 [ 1 ] ;
} else {
V_378 = & V_12 -> V_289 . V_371 [ 1 ] ;
V_379 = & V_12 -> V_289 . V_371 [ 0 ] ;
}
if ( V_378 -> V_25 )
return V_378 -> V_25 ;
if ( V_379 -> V_25 ) {
if ( V_379 -> V_25 == 0x70 )
return 0x72 ;
else
return 0x70 ;
}
if ( V_287 -> V_17 == V_18 )
return 0x70 ;
else
return 0x72 ;
}
static int
F_158 ( struct V_7 * V_6 ,
struct V_1 * V_3 )
{
struct V_5 * V_5 ;
int V_30 ;
V_5 = & V_6 -> V_4 . V_4 ;
V_30 = F_159 ( V_3 -> V_4 . V_4 . V_10 ,
V_5 ,
& V_380 ,
V_6 -> V_4 . V_4 . V_381 ) ;
if ( V_30 < 0 )
return V_30 ;
F_160 ( V_5 ,
& V_382 ) ;
V_6 -> V_4 . V_4 . V_383 = 1 ;
V_6 -> V_4 . V_4 . V_384 = 0 ;
V_6 -> V_4 . V_4 . V_385 . V_386 = V_387 ;
V_6 -> V_4 . V_388 = F_82 ;
F_161 ( & V_6 -> V_4 , & V_3 -> V_4 ) ;
return 0 ;
}
static void
F_162 ( struct V_1 * V_1 ,
struct V_7 * V_6 )
{
struct V_11 * V_12 = F_8 ( V_6 -> V_4 . V_4 . V_10 ) ;
F_163 ( & V_6 -> V_4 . V_4 ) ;
if ( F_74 ( V_12 ) >= 4 && F_164 ( V_12 ) ) {
F_165 ( & V_6 -> V_4 . V_4 ) ;
V_1 -> V_203 = true ;
}
F_166 ( & V_6 -> V_4 . V_4 ) ;
V_1 -> V_208 = V_335 ;
}
static struct V_7 * F_167 ( void )
{
struct V_7 * V_389 ;
V_389 = F_24 ( sizeof( * V_389 ) , V_39 ) ;
if ( ! V_389 )
return NULL ;
if ( F_168 ( & V_389 -> V_4 ) < 0 ) {
F_26 ( V_389 ) ;
return NULL ;
}
return V_389 ;
}
static bool
F_169 ( struct V_1 * V_1 , int V_377 )
{
struct V_359 * V_3 = & V_1 -> V_4 . V_4 ;
struct V_5 * V_6 ;
struct V_2 * V_2 = F_146 ( V_3 ) ;
struct V_237 * V_237 ;
struct V_7 * V_7 ;
F_16 ( L_40 , V_377 ) ;
V_7 = F_167 () ;
if ( ! V_7 )
return false ;
if ( V_377 == 0 ) {
V_1 -> V_362 |= V_366 ;
V_7 -> V_239 = V_366 ;
} else if ( V_377 == 1 ) {
V_1 -> V_362 |= V_365 ;
V_7 -> V_239 = V_365 ;
}
V_237 = & V_7 -> V_4 ;
V_6 = & V_237 -> V_4 ;
if ( F_101 ( V_1 ) &
V_7 -> V_239 ) {
V_1 -> V_285 |= V_7 -> V_239 ;
V_2 -> V_390 = F_103 ;
F_103 ( V_2 ) ;
} else {
V_237 -> V_391 = V_392 | V_393 ;
}
V_3 -> V_394 = V_395 ;
V_6 -> V_381 = V_396 ;
if ( F_156 ( V_1 , V_377 ) ) {
V_6 -> V_381 = V_397 ;
V_1 -> V_206 = true ;
}
if ( F_158 ( V_7 , V_1 ) < 0 ) {
F_26 ( V_7 ) ;
return false ;
}
if ( V_1 -> V_206 )
F_162 ( V_1 , V_7 ) ;
return true ;
}
static bool
F_170 ( struct V_1 * V_1 , int type )
{
struct V_359 * V_3 = & V_1 -> V_4 . V_4 ;
struct V_5 * V_6 ;
struct V_237 * V_237 ;
struct V_7 * V_7 ;
F_16 ( L_41 , type ) ;
V_7 = F_167 () ;
if ( ! V_7 )
return false ;
V_237 = & V_7 -> V_4 ;
V_6 = & V_237 -> V_4 ;
V_3 -> V_394 = V_398 ;
V_6 -> V_381 = V_399 ;
V_1 -> V_362 |= type ;
V_7 -> V_239 = type ;
V_1 -> V_198 = true ;
if ( F_158 ( V_7 , V_1 ) < 0 ) {
F_26 ( V_7 ) ;
return false ;
}
if ( ! F_171 ( V_1 , V_7 , type ) )
goto V_400;
if ( ! F_172 ( V_1 , V_7 ) )
goto V_400;
return true ;
V_400:
F_131 ( V_6 ) ;
return false ;
}
static bool
F_173 ( struct V_1 * V_1 , int V_377 )
{
struct V_359 * V_3 = & V_1 -> V_4 . V_4 ;
struct V_5 * V_6 ;
struct V_237 * V_237 ;
struct V_7 * V_7 ;
F_16 ( L_42 , V_377 ) ;
V_7 = F_167 () ;
if ( ! V_7 )
return false ;
V_237 = & V_7 -> V_4 ;
V_6 = & V_237 -> V_4 ;
V_237 -> V_391 = V_392 ;
V_3 -> V_394 = V_401 ;
V_6 -> V_381 = V_402 ;
if ( V_377 == 0 ) {
V_1 -> V_362 |= V_368 ;
V_7 -> V_239 = V_368 ;
} else if ( V_377 == 1 ) {
V_1 -> V_362 |= V_367 ;
V_7 -> V_239 = V_367 ;
}
if ( F_158 ( V_7 , V_1 ) < 0 ) {
F_26 ( V_7 ) ;
return false ;
}
return true ;
}
static bool
F_174 ( struct V_1 * V_1 , int V_377 )
{
struct V_359 * V_3 = & V_1 -> V_4 . V_4 ;
struct V_5 * V_6 ;
struct V_237 * V_237 ;
struct V_7 * V_7 ;
F_16 ( L_43 , V_377 ) ;
V_7 = F_167 () ;
if ( ! V_7 )
return false ;
V_237 = & V_7 -> V_4 ;
V_6 = & V_237 -> V_4 ;
V_3 -> V_394 = V_403 ;
V_6 -> V_381 = V_404 ;
if ( V_377 == 0 ) {
V_1 -> V_362 |= V_364 ;
V_7 -> V_239 = V_364 ;
} else if ( V_377 == 1 ) {
V_1 -> V_362 |= V_363 ;
V_7 -> V_239 = V_363 ;
}
if ( F_158 ( V_7 , V_1 ) < 0 ) {
F_26 ( V_7 ) ;
return false ;
}
if ( ! F_172 ( V_1 , V_7 ) )
goto V_400;
return true ;
V_400:
F_131 ( V_6 ) ;
return false ;
}
static bool
F_175 ( struct V_1 * V_1 , T_4 V_26 )
{
V_1 -> V_198 = false ;
V_1 -> V_103 = false ;
if ( V_26 & V_366 )
if ( ! F_169 ( V_1 , 0 ) )
return false ;
if ( ( V_26 & V_405 ) == V_405 )
if ( ! F_169 ( V_1 , 1 ) )
return false ;
if ( V_26 & V_406 )
if ( ! F_170 ( V_1 , V_406 ) )
return false ;
if ( V_26 & V_407 )
if ( ! F_170 ( V_1 , V_407 ) )
return false ;
if ( V_26 & V_408 )
if ( ! F_170 ( V_1 , V_408 ) )
return false ;
if ( V_26 & V_368 )
if ( ! F_173 ( V_1 , 0 ) )
return false ;
if ( ( V_26 & V_409 ) == V_409 )
if ( ! F_173 ( V_1 , 1 ) )
return false ;
if ( V_26 & V_364 )
if ( ! F_174 ( V_1 , 0 ) )
return false ;
if ( ( V_26 & V_307 ) == V_307 )
if ( ! F_174 ( V_1 , 1 ) )
return false ;
if ( ( V_26 & V_410 ) == 0 ) {
unsigned char V_411 [ 2 ] ;
V_1 -> V_362 = 0 ;
memcpy ( V_411 , & V_1 -> V_268 . V_281 , 2 ) ;
F_16 ( L_44 ,
F_22 ( V_1 ) ,
V_411 [ 0 ] , V_411 [ 1 ] ) ;
return false ;
}
V_1 -> V_4 . V_412 = ( 1 << 0 ) | ( 1 << 1 ) | ( 1 << 2 ) ;
return true ;
}
static void F_176 ( struct V_1 * V_1 )
{
struct V_9 * V_10 = V_1 -> V_4 . V_4 . V_10 ;
struct V_5 * V_6 , * V_156 ;
F_177 (connector, tmp,
&dev->mode_config.connector_list, head) {
if ( F_4 ( V_6 ) == & V_1 -> V_4 ) {
F_178 ( V_6 ) ;
F_131 ( V_6 ) ;
}
}
}
static bool F_171 ( struct V_1 * V_1 ,
struct V_7 * V_7 ,
int type )
{
struct V_9 * V_10 = V_1 -> V_4 . V_4 . V_10 ;
struct V_175 V_176 ;
T_7 V_177 , V_15 ;
if ( ! F_41 ( V_1 , type ) )
return false ;
F_36 ( sizeof( V_176 ) != 6 ) ;
if ( ! F_33 ( V_1 ,
V_413 ,
& V_176 , sizeof( V_176 ) ) )
return false ;
memcpy ( & V_177 , & V_176 , V_89 ( sizeof( V_177 ) , sizeof( V_176 ) ) ) ;
if ( V_177 == 0 )
return false ;
V_7 -> V_414 = 0 ;
for ( V_15 = 0 ; V_15 < V_341 ; V_15 ++ )
if ( V_177 & ( 1 << V_15 ) )
V_7 -> V_342 [ V_7 -> V_414 ++ ] = V_15 ;
V_7 -> V_340 =
F_179 ( V_10 , V_415 ,
L_45 , V_7 -> V_414 ) ;
if ( ! V_7 -> V_340 )
return false ;
for ( V_15 = 0 ; V_15 < V_7 -> V_414 ; V_15 ++ )
F_180 (
V_7 -> V_340 , V_15 ,
V_15 , V_416 [ V_7 -> V_342 [ V_15 ] ] ) ;
V_1 -> V_178 = V_7 -> V_342 [ 0 ] ;
F_181 ( & V_7 -> V_4 . V_4 . V_4 ,
V_7 -> V_340 , 0 ) ;
return true ;
}
static bool
F_182 ( struct V_1 * V_1 ,
struct V_7 * V_7 ,
struct V_417 V_418 )
{
struct V_9 * V_10 = V_1 -> V_4 . V_4 . V_10 ;
struct V_5 * V_6 = & V_7 -> V_4 . V_4 ;
T_4 V_44 , V_419 [ 2 ] ;
if ( V_418 . V_420 ) {
if ( ! F_33 ( V_1 ,
V_421 ,
& V_419 , 4 ) )
return false ;
if ( ! F_33 ( V_1 ,
V_422 ,
& V_44 , 2 ) )
return false ;
V_7 -> V_347 = V_419 [ 0 ] ;
V_7 -> V_345 = V_419 [ 0 ] - V_44 ;
V_7 -> V_346 = V_7 -> V_345 ;
V_7 -> V_343 =
F_183 ( V_10 , 0 , L_46 , 0 , V_419 [ 0 ] ) ;
if ( ! V_7 -> V_343 )
return false ;
F_181 ( & V_6 -> V_4 ,
V_7 -> V_343 ,
V_7 -> V_345 ) ;
V_7 -> V_344 =
F_183 ( V_10 , 0 , L_47 , 0 , V_419 [ 0 ] ) ;
if ( ! V_7 -> V_344 )
return false ;
F_181 ( & V_6 -> V_4 ,
V_7 -> V_344 ,
V_7 -> V_346 ) ;
F_16 ( L_48
L_49 ,
V_419 [ 0 ] , V_419 [ 1 ] , V_44 ) ;
}
if ( V_418 . V_423 ) {
if ( ! F_33 ( V_1 ,
V_424 ,
& V_419 , 4 ) )
return false ;
if ( ! F_33 ( V_1 ,
V_425 ,
& V_44 , 2 ) )
return false ;
V_7 -> V_354 = V_419 [ 0 ] ;
V_7 -> V_352 = V_419 [ 0 ] - V_44 ;
V_7 -> V_353 = V_7 -> V_352 ;
V_7 -> V_350 =
F_183 ( V_10 , 0 ,
L_50 , 0 , V_419 [ 0 ] ) ;
if ( ! V_7 -> V_350 )
return false ;
F_181 ( & V_6 -> V_4 ,
V_7 -> V_350 ,
V_7 -> V_352 ) ;
V_7 -> V_351 =
F_183 ( V_10 , 0 ,
L_51 , 0 , V_419 [ 0 ] ) ;
if ( ! V_7 -> V_351 )
return false ;
F_181 ( & V_6 -> V_4 ,
V_7 -> V_351 ,
V_7 -> V_353 ) ;
F_16 ( L_52
L_49 ,
V_419 [ 0 ] , V_419 [ 1 ] , V_44 ) ;
}
F_184 ( V_426 , V_427 ) ;
F_184 ( V_428 , V_429 ) ;
F_184 ( V_430 , V_431 ) ;
F_184 ( V_432 , V_433 ) ;
F_184 ( V_434 , V_435 ) ;
F_184 ( V_436 , V_437 ) ;
F_184 ( V_438 , V_439 ) ;
F_184 ( V_440 , V_441 ) ;
F_184 ( V_442 , V_443 ) ;
F_184 ( V_444 , V_445 ) ;
F_184 ( V_446 , V_447 ) ;
F_184 ( V_448 , V_449 ) ;
if ( V_418 . V_450 ) {
if ( ! F_33 ( V_1 , V_451 , & V_44 , 2 ) )
return false ;
V_7 -> V_452 = 1 ;
V_7 -> V_453 = V_44 & 0x1 ;
V_7 -> V_450 =
F_183 ( V_10 , 0 , L_53 , 0 , 1 ) ;
if ( ! V_7 -> V_450 )
return false ;
F_181 ( & V_6 -> V_4 ,
V_7 -> V_450 ,
V_7 -> V_453 ) ;
F_16 ( L_54 , V_44 ) ;
}
return true ;
}
static bool
F_185 ( struct V_1 * V_1 ,
struct V_7 * V_7 ,
struct V_417 V_418 )
{
struct V_9 * V_10 = V_1 -> V_4 . V_4 . V_10 ;
struct V_5 * V_6 = & V_7 -> V_4 . V_4 ;
T_4 V_44 , V_419 [ 2 ] ;
F_184 ( V_438 , V_439 ) ;
return true ;
}
static bool F_172 ( struct V_1 * V_1 ,
struct V_7 * V_7 )
{
union {
struct V_417 V_310 ;
T_4 V_44 ;
} V_418 ;
F_36 ( sizeof( V_418 ) != 2 ) ;
V_418 . V_44 = 0 ;
F_33 ( V_1 ,
V_454 ,
& V_418 , sizeof( V_418 ) ) ;
if ( V_418 . V_44 == 0 ) {
F_16 ( L_55 ) ;
return true ;
}
if ( F_128 ( V_7 ) )
return F_182 ( V_1 , V_7 , V_418 . V_310 ) ;
else if ( F_129 ( V_7 ) )
return F_185 ( V_1 , V_7 , V_418 . V_310 ) ;
else
return true ;
}
static int F_186 ( struct V_455 * V_456 ,
struct V_23 * V_24 ,
int V_457 )
{
struct V_1 * V_287 = V_456 -> V_458 ;
if ( ! F_31 ( V_287 , V_287 -> V_57 ) )
return - V_356 ;
return V_287 -> V_31 -> V_459 -> V_460 ( V_287 -> V_31 , V_24 , V_457 ) ;
}
static T_1 F_187 ( struct V_455 * V_456 )
{
struct V_1 * V_287 = V_456 -> V_458 ;
return V_287 -> V_31 -> V_459 -> V_461 ( V_287 -> V_31 ) ;
}
static bool
F_188 ( struct V_1 * V_287 ,
struct V_11 * V_12 )
{
struct V_462 * V_463 = V_12 -> V_464 . V_463 ;
V_287 -> V_288 . V_465 = V_466 ;
V_287 -> V_288 . V_467 = V_468 ;
snprintf ( V_287 -> V_288 . V_37 , V_469 , L_56 ) ;
V_287 -> V_288 . V_10 . V_470 = & V_463 -> V_10 ;
V_287 -> V_288 . V_458 = V_287 ;
V_287 -> V_288 . V_459 = & V_471 ;
return F_189 ( & V_287 -> V_288 ) == 0 ;
}
static void F_190 ( const struct V_11 * V_12 ,
enum V_17 V_17 )
{
if ( F_9 ( V_12 ) )
F_191 ( V_17 != V_18 ) ;
else
F_191 ( V_17 != V_18 && V_17 != V_472 ) ;
}
bool F_192 ( struct V_11 * V_12 ,
T_10 V_16 , enum V_17 V_17 )
{
struct V_2 * V_2 ;
struct V_1 * V_1 ;
int V_15 ;
F_190 ( V_12 , V_17 ) ;
V_1 = F_24 ( sizeof( * V_1 ) , V_39 ) ;
if ( ! V_1 )
return false ;
V_1 -> V_16 = V_16 ;
V_1 -> V_17 = V_17 ;
V_1 -> V_25 =
F_157 ( V_12 , V_1 ) >> 1 ;
F_152 ( V_12 , V_1 ) ;
if ( ! F_188 ( V_1 , V_12 ) )
goto V_473;
V_2 = & V_1 -> V_4 ;
V_2 -> type = V_474 ;
V_2 -> V_475 = V_476 ;
V_2 -> V_17 = V_17 ;
F_193 ( & V_12 -> V_464 , & V_2 -> V_4 ,
& V_477 , 0 ,
L_57 , F_194 ( V_17 ) ) ;
for ( V_15 = 0 ; V_15 < 0x40 ; V_15 ++ ) {
T_2 V_478 ;
if ( ! F_14 ( V_1 , V_15 , & V_478 ) ) {
F_16 ( L_58 ,
F_22 ( V_1 ) ) ;
goto V_400;
}
}
V_2 -> V_479 = F_69 ;
if ( F_9 ( V_12 ) ) {
V_2 -> V_480 = F_95 ;
V_2 -> V_481 = F_96 ;
} else {
V_2 -> V_480 = F_91 ;
}
V_2 -> V_482 = F_71 ;
V_2 -> V_483 = F_97 ;
V_2 -> V_388 = F_83 ;
V_2 -> V_484 = F_87 ;
if ( ! F_100 ( V_1 , & V_1 -> V_268 ) )
goto V_400;
if ( F_175 ( V_1 ,
V_1 -> V_268 . V_281 ) != true ) {
F_16 ( L_59 ,
F_22 ( V_1 ) ) ;
goto V_485;
}
if ( V_1 -> V_285 ) {
if ( V_1 -> V_17 == V_18 )
V_2 -> V_486 = V_487 ;
else
V_2 -> V_486 = V_488 ;
}
V_1 -> V_4 . V_489 = 0 ;
F_151 ( V_12 , V_1 ) ;
if ( ! F_34 ( V_1 ) )
goto V_485;
if ( ! F_40 ( V_1 ,
& V_1 -> V_261 ,
& V_1 -> V_263 ) )
goto V_485;
F_16 ( L_60
L_61
L_62
L_63 ,
F_22 ( V_1 ) ,
V_1 -> V_268 . V_270 , V_1 -> V_268 . V_271 ,
V_1 -> V_268 . V_272 ,
V_1 -> V_261 / 1000 ,
V_1 -> V_263 / 1000 ,
( V_1 -> V_268 . V_275 & 0x1 ) ? 'Y' : 'N' ,
( V_1 -> V_268 . V_275 & 0x2 ) ? 'Y' : 'N' ,
V_1 -> V_268 . V_281 &
( V_366 | V_368 ) ? 'Y' : 'N' ,
V_1 -> V_268 . V_281 &
( V_365 | V_367 ) ? 'Y' : 'N' ) ;
return true ;
V_485:
F_176 ( V_1 ) ;
V_400:
F_195 ( & V_2 -> V_4 ) ;
F_148 ( & V_1 -> V_288 ) ;
V_473:
F_155 ( V_1 ) ;
F_26 ( V_1 ) ;
return false ;
}
