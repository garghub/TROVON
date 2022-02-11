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
if ( F_8 ( V_12 ) ) {
F_9 ( V_1 -> V_17 , V_8 ) ;
F_10 ( V_1 -> V_17 ) ;
if ( F_11 ( V_10 ) ) {
F_9 ( V_1 -> V_17 , V_8 ) ;
F_10 ( V_1 -> V_17 ) ;
}
return;
}
if ( V_1 -> V_18 == V_19 )
V_15 = F_12 ( V_20 ) ;
else
V_14 = F_12 ( V_21 ) ;
for ( V_16 = 0 ; V_16 < 2 ; V_16 ++ )
{
F_9 ( V_21 , V_14 ) ;
F_10 ( V_21 ) ;
F_9 ( V_20 , V_15 ) ;
F_10 ( V_20 ) ;
}
}
static bool F_13 ( struct V_1 * V_1 , T_2 V_22 , T_2 * V_23 )
{
struct V_24 V_25 [] = {
{
. V_22 = V_1 -> V_26 ,
. V_27 = 0 ,
. V_28 = 1 ,
. V_29 = & V_22 ,
} ,
{
. V_22 = V_1 -> V_26 ,
. V_27 = V_30 ,
. V_28 = 1 ,
. V_29 = V_23 ,
}
} ;
int V_31 ;
if ( ( V_31 = F_14 ( V_1 -> V_32 , V_25 , 2 ) ) == 2 )
return true ;
F_15 ( L_1 , V_31 ) ;
return false ;
}
static void F_16 ( struct V_1 * V_1 , T_2 V_33 ,
const void * args , int V_34 )
{
int V_16 , V_35 = 0 ;
#define F_17 256
char V_36 [ F_17 ] ;
#define F_18 ( args ... ) \
pos += snprintf(buffer + pos, max_t(int, BUF_LEN - pos, 0), args)
for ( V_16 = 0 ; V_16 < V_34 ; V_16 ++ ) {
F_18 ( L_2 , ( ( T_2 * ) args ) [ V_16 ] ) ;
}
for (; V_16 < 8 ; V_16 ++ ) {
F_18 ( L_3 ) ;
}
for ( V_16 = 0 ; V_16 < F_19 ( V_37 ) ; V_16 ++ ) {
if ( V_33 == V_37 [ V_16 ] . V_33 ) {
F_18 ( L_4 , V_37 [ V_16 ] . V_38 ) ;
break;
}
}
if ( V_16 == F_19 ( V_37 ) ) {
F_18 ( L_5 , V_33 ) ;
}
F_20 ( V_35 >= F_17 - 1 ) ;
#undef F_18
#undef F_17
F_15 ( L_6 , F_21 ( V_1 ) , V_33 , V_36 ) ;
}
static bool F_22 ( struct V_1 * V_1 , T_2 V_33 ,
const void * args , int V_34 )
{
T_2 * V_29 , V_39 ;
struct V_24 * V_25 ;
int V_16 , V_31 = true ;
V_29 = F_23 ( V_34 * 2 + 2 , V_40 ) ;
if ( ! V_29 )
return false ;
V_25 = F_24 ( V_34 + 3 , sizeof( * V_25 ) , V_40 ) ;
if ( ! V_25 ) {
F_25 ( V_29 ) ;
return false ;
}
F_16 ( V_1 , V_33 , args , V_34 ) ;
for ( V_16 = 0 ; V_16 < V_34 ; V_16 ++ ) {
V_25 [ V_16 ] . V_22 = V_1 -> V_26 ;
V_25 [ V_16 ] . V_27 = 0 ;
V_25 [ V_16 ] . V_28 = 2 ;
V_25 [ V_16 ] . V_29 = V_29 + 2 * V_16 ;
V_29 [ 2 * V_16 + 0 ] = V_41 - V_16 ;
V_29 [ 2 * V_16 + 1 ] = ( ( T_2 * ) args ) [ V_16 ] ;
}
V_25 [ V_16 ] . V_22 = V_1 -> V_26 ;
V_25 [ V_16 ] . V_27 = 0 ;
V_25 [ V_16 ] . V_28 = 2 ;
V_25 [ V_16 ] . V_29 = V_29 + 2 * V_16 ;
V_29 [ 2 * V_16 + 0 ] = V_42 ;
V_29 [ 2 * V_16 + 1 ] = V_33 ;
V_39 = V_43 ;
V_25 [ V_16 + 1 ] . V_22 = V_1 -> V_26 ;
V_25 [ V_16 + 1 ] . V_27 = 0 ;
V_25 [ V_16 + 1 ] . V_28 = 1 ;
V_25 [ V_16 + 1 ] . V_29 = & V_39 ;
V_25 [ V_16 + 2 ] . V_22 = V_1 -> V_26 ;
V_25 [ V_16 + 2 ] . V_27 = V_30 ;
V_25 [ V_16 + 2 ] . V_28 = 1 ;
V_25 [ V_16 + 2 ] . V_29 = & V_39 ;
V_31 = F_14 ( V_1 -> V_32 , V_25 , V_16 + 3 ) ;
if ( V_31 < 0 ) {
F_15 ( L_7 , V_31 ) ;
V_31 = false ;
goto V_44;
}
if ( V_31 != V_16 + 3 ) {
F_15 ( L_8 , V_31 , V_16 + 3 ) ;
V_31 = false ;
}
V_44:
F_25 ( V_25 ) ;
F_25 ( V_29 ) ;
return V_31 ;
}
static bool F_26 ( struct V_1 * V_1 ,
void * V_45 , int V_46 )
{
T_2 V_47 = 15 ;
T_2 V_39 ;
int V_16 , V_35 = 0 ;
#define F_17 256
char V_36 [ F_17 ] ;
if ( ! F_13 ( V_1 ,
V_43 ,
& V_39 ) )
goto V_48;
while ( ( V_39 == V_49 ||
V_39 == V_50 ) && -- V_47 ) {
if ( V_47 < 10 )
F_27 ( 15 ) ;
else
F_28 ( 15 ) ;
if ( ! F_13 ( V_1 ,
V_43 ,
& V_39 ) )
goto V_48;
}
#define F_18 ( args ... ) \
pos += snprintf(buffer + pos, max_t(int, BUF_LEN - pos, 0), args)
if ( V_39 <= V_51 )
F_18 ( L_4 , V_52 [ V_39 ] ) ;
else
F_18 ( L_9 , V_39 ) ;
if ( V_39 != V_53 )
goto V_48;
for ( V_16 = 0 ; V_16 < V_46 ; V_16 ++ ) {
if ( ! F_13 ( V_1 ,
V_54 + V_16 ,
& ( ( T_2 * ) V_45 ) [ V_16 ] ) )
goto V_48;
F_18 ( L_10 , ( ( T_2 * ) V_45 ) [ V_16 ] ) ;
}
F_20 ( V_35 >= F_17 - 1 ) ;
#undef F_18
#undef F_17
F_15 ( L_11 , F_21 ( V_1 ) , V_36 ) ;
return true ;
V_48:
F_15 ( L_12 , F_21 ( V_1 ) ) ;
return false ;
}
static int F_29 ( const struct V_55 * V_56 )
{
if ( V_56 -> V_57 >= 100000 )
return 1 ;
else if ( V_56 -> V_57 >= 50000 )
return 2 ;
else
return 4 ;
}
static bool F_30 ( struct V_1 * V_1 ,
T_2 V_58 )
{
return F_22 ( V_1 ,
V_59 ,
& V_58 , 1 ) ;
}
static bool F_31 ( struct V_1 * V_1 , T_2 V_33 , const void * V_60 , int V_28 )
{
if ( ! F_22 ( V_1 , V_33 , V_60 , V_28 ) )
return false ;
return F_26 ( V_1 , NULL , 0 ) ;
}
static bool
F_32 ( struct V_1 * V_1 , T_2 V_33 , void * V_61 , int V_28 )
{
if ( ! F_22 ( V_1 , V_33 , NULL , 0 ) )
return false ;
return F_26 ( V_1 , V_61 , V_28 ) ;
}
static bool F_33 ( struct V_1 * V_1 )
{
struct V_62 V_63 = { 0 } ;
return F_31 ( V_1 ,
V_64 ,
& V_63 , sizeof( V_63 ) ) ;
}
static bool F_34 ( struct V_1 * V_1 , bool * V_65 , bool * V_66 )
{
struct V_67 V_45 ;
F_35 ( sizeof( V_45 ) != 1 ) ;
if ( ! F_32 ( V_1 , V_68 ,
& V_45 , sizeof( V_45 ) ) )
return false ;
* V_65 = V_45 . V_69 ;
* V_66 = V_45 . V_70 ;
return true ;
}
static bool F_36 ( struct V_1 * V_1 ,
T_3 V_71 )
{
return F_31 ( V_1 ,
V_72 ,
& V_71 , sizeof( V_71 ) ) ;
}
static bool F_37 ( struct V_1 * V_1 ,
T_3 * V_71 )
{
return F_32 ( V_1 ,
V_73 ,
V_71 , sizeof( * V_71 ) ) ;
}
static bool F_38 ( struct V_1 * V_1 ,
int V_74 )
{
T_2 V_75 = V_76 ;
switch ( V_74 ) {
case V_77 :
V_75 = V_76 ;
break;
case V_78 :
V_75 = V_79 ;
break;
case V_80 :
V_75 = V_81 ;
break;
case V_82 :
V_75 = V_83 ;
break;
}
return F_31 ( V_1 ,
V_84 , & V_75 , sizeof( V_75 ) ) ;
}
static bool F_39 ( struct V_1 * V_1 ,
int * V_85 ,
int * V_86 )
{
struct V_87 V_88 ;
F_35 ( sizeof( V_88 ) != 4 ) ;
if ( ! F_32 ( V_1 ,
V_89 ,
& V_88 , sizeof( V_88 ) ) )
return false ;
* V_85 = V_88 . V_90 * 10 ;
* V_86 = V_88 . V_91 * 10 ;
return true ;
}
static bool F_40 ( struct V_1 * V_1 ,
T_3 V_71 )
{
return F_31 ( V_1 ,
V_92 ,
& V_71 , sizeof( V_71 ) ) ;
}
static bool F_41 ( struct V_1 * V_1 , T_2 V_33 ,
struct V_93 * V_94 )
{
return F_31 ( V_1 , V_33 , & V_94 -> V_95 , sizeof( V_94 -> V_95 ) ) &&
F_31 ( V_1 , V_33 + 1 , & V_94 -> V_96 , sizeof( V_94 -> V_96 ) ) ;
}
static bool F_42 ( struct V_1 * V_1 , T_2 V_33 ,
struct V_93 * V_94 )
{
return F_32 ( V_1 , V_33 , & V_94 -> V_95 , sizeof( V_94 -> V_95 ) ) &&
F_32 ( V_1 , V_33 + 1 , & V_94 -> V_96 , sizeof( V_94 -> V_96 ) ) ;
}
static bool F_43 ( struct V_1 * V_1 ,
struct V_93 * V_94 )
{
return F_41 ( V_1 ,
V_97 , V_94 ) ;
}
static bool F_44 ( struct V_1 * V_1 ,
struct V_93 * V_94 )
{
return F_41 ( V_1 ,
V_98 , V_94 ) ;
}
static bool F_45 ( struct V_1 * V_1 ,
struct V_93 * V_94 )
{
return F_42 ( V_1 ,
V_99 , V_94 ) ;
}
static bool
F_46 ( struct V_1 * V_1 ,
T_4 clock ,
T_4 V_100 ,
T_4 V_101 )
{
struct V_102 args ;
memset ( & args , 0 , sizeof( args ) ) ;
args . clock = clock ;
args . V_100 = V_100 ;
args . V_101 = V_101 ;
args . V_103 = 0 ;
if ( V_1 -> V_104 &&
( V_1 -> V_105 -> V_106 != V_100 ||
V_1 -> V_105 -> V_107 != V_101 ) )
args . V_108 = 1 ;
return F_31 ( V_1 ,
V_109 ,
& args , sizeof( args ) ) ;
}
static bool F_47 ( struct V_1 * V_1 ,
struct V_93 * V_94 )
{
F_35 ( sizeof( V_94 -> V_95 ) != 8 ) ;
F_35 ( sizeof( V_94 -> V_96 ) != 8 ) ;
return F_32 ( V_1 , V_110 ,
& V_94 -> V_95 , sizeof( V_94 -> V_95 ) ) &&
F_32 ( V_1 , V_111 ,
& V_94 -> V_96 , sizeof( V_94 -> V_96 ) ) ;
}
static bool F_48 ( struct V_1 * V_1 , T_2 V_8 )
{
return F_31 ( V_1 , V_112 , & V_8 , 1 ) ;
}
static void F_49 ( struct V_93 * V_94 ,
const struct V_55 * V_74 )
{
T_4 V_100 , V_101 ;
T_4 V_113 , V_114 , V_115 , V_116 ;
T_4 V_117 , V_118 ;
int V_119 ;
memset ( V_94 , 0 , sizeof( * V_94 ) ) ;
V_100 = V_74 -> V_106 ;
V_101 = V_74 -> V_107 ;
V_113 = V_74 -> V_120 - V_74 -> V_106 ;
V_114 = V_74 -> V_121 - V_74 -> V_122 ;
V_115 = V_74 -> V_123 - V_74 -> V_107 ;
V_116 = V_74 -> V_124 - V_74 -> V_125 ;
V_117 = V_74 -> V_122 - V_74 -> V_106 ;
V_118 = V_74 -> V_125 - V_74 -> V_107 ;
V_119 = V_74 -> clock ;
V_119 /= 10 ;
V_94 -> V_95 . clock = V_119 ;
V_94 -> V_95 . V_126 = V_100 & 0xff ;
V_94 -> V_95 . V_127 = V_113 & 0xff ;
V_94 -> V_95 . V_128 = ( ( ( V_100 >> 8 ) & 0xf ) << 4 ) |
( ( V_113 >> 8 ) & 0xf ) ;
V_94 -> V_95 . V_129 = V_101 & 0xff ;
V_94 -> V_95 . V_130 = V_115 & 0xff ;
V_94 -> V_95 . V_131 = ( ( ( V_101 >> 8 ) & 0xf ) << 4 ) |
( ( V_115 >> 8 ) & 0xf ) ;
V_94 -> V_96 . V_132 = V_117 & 0xff ;
V_94 -> V_96 . V_133 = V_114 & 0xff ;
V_94 -> V_96 . V_134 = ( V_118 & 0xf ) << 4 |
( V_116 & 0xf ) ;
V_94 -> V_96 . V_135 = ( ( V_117 & 0x300 ) >> 2 ) |
( ( V_114 & 0x300 ) >> 4 ) | ( ( V_118 & 0x30 ) >> 2 ) |
( ( V_116 & 0x30 ) >> 4 ) ;
V_94 -> V_96 . V_136 = 0x18 ;
if ( V_74 -> V_27 & V_137 )
V_94 -> V_96 . V_136 |= V_138 ;
if ( V_74 -> V_27 & V_139 )
V_94 -> V_96 . V_136 |= V_140 ;
if ( V_74 -> V_27 & V_141 )
V_94 -> V_96 . V_136 |= V_142 ;
V_94 -> V_96 . V_143 = V_118 & 0xc0 ;
}
static void F_50 ( struct V_55 * V_144 ,
const struct V_93 * V_94 )
{
struct V_55 V_74 = {} ;
V_74 . V_106 = V_94 -> V_95 . V_126 ;
V_74 . V_106 += ( ( V_94 -> V_95 . V_128 >> 4 ) & 0x0f ) << 8 ;
V_74 . V_122 = V_74 . V_106 + V_94 -> V_96 . V_132 ;
V_74 . V_122 += ( V_94 -> V_96 . V_135 & 0xc0 ) << 2 ;
V_74 . V_121 = V_74 . V_122 + V_94 -> V_96 . V_133 ;
V_74 . V_121 += ( V_94 -> V_96 . V_135 & 0x30 ) << 4 ;
V_74 . V_120 = V_74 . V_106 + V_94 -> V_95 . V_127 ;
V_74 . V_120 += ( V_94 -> V_95 . V_128 & 0xf ) << 8 ;
V_74 . V_107 = V_94 -> V_95 . V_129 ;
V_74 . V_107 += ( ( V_94 -> V_95 . V_131 >> 4 ) & 0x0f ) << 8 ;
V_74 . V_125 = V_74 . V_107 ;
V_74 . V_125 += ( V_94 -> V_96 . V_134 >> 4 ) & 0xf ;
V_74 . V_125 += ( V_94 -> V_96 . V_135 & 0x0c ) << 2 ;
V_74 . V_125 += V_94 -> V_96 . V_143 & 0xc0 ;
V_74 . V_124 = V_74 . V_125 +
( V_94 -> V_96 . V_134 & 0xf ) ;
V_74 . V_124 += ( V_94 -> V_96 . V_135 & 0x3 ) << 4 ;
V_74 . V_123 = V_74 . V_107 + V_94 -> V_95 . V_130 ;
V_74 . V_123 += ( V_94 -> V_95 . V_131 & 0xf ) << 8 ;
V_74 . clock = V_94 -> V_95 . clock * 10 ;
if ( V_94 -> V_96 . V_136 & V_138 )
V_74 . V_27 |= V_137 ;
if ( V_94 -> V_96 . V_136 & V_140 )
V_74 . V_27 |= V_139 ;
else
V_74 . V_27 |= V_145 ;
if ( V_94 -> V_96 . V_136 & V_142 )
V_74 . V_27 |= V_141 ;
else
V_74 . V_27 |= V_146 ;
F_51 ( & V_74 , 0 ) ;
F_52 ( V_144 , & V_74 ) ;
}
static bool F_53 ( struct V_1 * V_1 )
{
struct V_147 V_148 ;
F_35 ( sizeof( V_148 ) != 2 ) ;
return F_32 ( V_1 ,
V_149 ,
& V_148 , sizeof( V_148 ) ) ;
}
static bool F_54 ( struct V_1 * V_1 ,
T_5 V_74 )
{
return F_31 ( V_1 , V_150 , & V_74 , 1 ) ;
}
static bool F_55 ( struct V_1 * V_1 ,
T_5 V_74 )
{
return F_31 ( V_1 , V_151 , & V_74 , 1 ) ;
}
static bool F_56 ( struct V_1 * V_1 ,
unsigned V_152 , T_5 V_153 ,
const T_5 * V_60 , unsigned V_154 )
{
T_5 V_155 [ 2 ] = { V_152 , 0 } ;
T_5 V_156 , V_157 [ 8 ] ;
int V_16 ;
if ( ! F_31 ( V_1 ,
V_158 ,
V_155 , 2 ) )
return false ;
if ( ! F_32 ( V_1 , V_159 ,
& V_156 , 1 ) )
return false ;
V_156 ++ ;
F_15 ( L_13 ,
V_152 , V_154 , V_156 ) ;
for ( V_16 = 0 ; V_16 < V_156 ; V_16 += 8 ) {
memset ( V_157 , 0 , 8 ) ;
if ( V_16 < V_154 )
memcpy ( V_157 , V_60 + V_16 , F_57 ( unsigned , 8 , V_154 - V_16 ) ) ;
if ( ! F_31 ( V_1 ,
V_160 ,
V_157 , 8 ) )
return false ;
}
return F_31 ( V_1 ,
V_161 ,
& V_153 , 1 ) ;
}
static bool F_58 ( struct V_1 * V_1 ,
const struct V_55 * V_56 )
{
T_5 V_162 [ F_59 ( V_163 ) ] ;
struct V_164 * V_165 = V_1 -> V_4 . V_4 . V_165 ;
struct V_166 * V_166 = F_60 ( V_165 ) ;
union V_167 V_168 ;
int V_31 ;
T_6 V_28 ;
V_31 = F_61 ( & V_168 . V_169 ,
V_56 ) ;
if ( V_31 < 0 ) {
F_62 ( L_14 ) ;
return false ;
}
if ( V_1 -> V_170 ) {
if ( V_166 -> V_171 -> V_172 )
V_168 . V_169 . V_173 =
V_174 ;
else
V_168 . V_169 . V_173 =
V_175 ;
}
V_28 = F_63 ( & V_168 , V_162 , sizeof( V_162 ) ) ;
if ( V_28 < 0 )
return false ;
return F_56 ( V_1 , V_176 ,
V_177 ,
V_162 , sizeof( V_162 ) ) ;
}
static bool F_64 ( struct V_1 * V_1 )
{
struct V_178 V_179 ;
T_7 V_180 ;
V_180 = 1 << V_1 -> V_181 ;
memset ( & V_179 , 0 , sizeof( V_179 ) ) ;
memcpy ( & V_179 , & V_180 , V_90 ( sizeof( V_179 ) , sizeof( V_180 ) ) ) ;
F_35 ( sizeof( V_179 ) != 6 ) ;
return F_31 ( V_1 ,
V_182 ,
& V_179 , sizeof( V_179 ) ) ;
}
static bool
F_65 ( struct V_1 * V_1 ,
const struct V_55 * V_74 )
{
struct V_93 V_183 ;
if ( ! F_40 ( V_1 ,
V_1 -> V_184 ) )
return false ;
F_49 ( & V_183 , V_74 ) ;
if ( ! F_44 ( V_1 , & V_183 ) )
return false ;
return true ;
}
static bool
F_66 ( struct V_1 * V_1 ,
const struct V_55 * V_74 ,
struct V_55 * V_56 )
{
struct V_93 V_185 ;
if ( ! F_33 ( V_1 ) )
return false ;
if ( ! F_46 ( V_1 ,
V_74 -> clock / 10 ,
V_74 -> V_106 ,
V_74 -> V_107 ) )
return false ;
if ( ! F_47 ( V_1 ,
& V_185 ) )
return false ;
F_50 ( V_56 , & V_185 ) ;
V_1 -> V_186 = V_185 . V_96 . V_187 ;
return true ;
}
static void F_67 ( struct V_188 * V_189 )
{
unsigned V_190 = V_189 -> V_191 ;
struct V_192 * clock = & V_189 -> V_192 ;
if ( V_190 >= 100000 && V_190 < 140500 ) {
clock -> V_193 = 2 ;
clock -> V_194 = 10 ;
clock -> V_195 = 3 ;
clock -> V_196 = 16 ;
clock -> V_197 = 8 ;
} else if ( V_190 >= 140500 && V_190 <= 200000 ) {
clock -> V_193 = 1 ;
clock -> V_194 = 10 ;
clock -> V_195 = 6 ;
clock -> V_196 = 12 ;
clock -> V_197 = 8 ;
} else {
F_68 ( 1 , L_15 , V_190 ) ;
}
V_189 -> V_198 = true ;
}
static bool F_69 ( struct V_2 * V_3 ,
struct V_188 * V_189 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_55 * V_56 = & V_189 -> V_4 . V_56 ;
struct V_55 * V_74 = & V_189 -> V_4 . V_74 ;
F_15 ( L_16 ) ;
V_189 -> V_199 = 8 * 3 ;
if ( F_8 ( V_3 -> V_4 . V_10 ) )
V_189 -> V_200 = true ;
if ( V_1 -> V_201 ) {
if ( ! F_65 ( V_1 , V_74 ) )
return false ;
( void ) F_66 ( V_1 ,
V_74 ,
V_56 ) ;
V_189 -> V_202 = true ;
} else if ( V_1 -> V_104 ) {
if ( ! F_65 ( V_1 ,
V_1 -> V_105 ) )
return false ;
( void ) F_66 ( V_1 ,
V_74 ,
V_56 ) ;
}
V_189 -> V_203 =
F_29 ( V_56 ) ;
V_189 -> V_204 = V_1 -> V_205 ;
if ( V_1 -> V_206 ) {
if ( V_189 -> V_204 &&
F_70 ( V_56 ) > 1 )
V_189 -> V_172 = true ;
} else {
if ( V_189 -> V_204 &&
V_1 -> V_207 == V_208 )
V_189 -> V_172 = true ;
}
if ( V_1 -> V_201 )
F_67 ( V_189 ) ;
if ( V_1 -> V_209 )
V_56 -> V_210 = V_1 -> V_211 ;
return true ;
}
static void F_71 ( struct V_2 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_4 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_166 * V_165 = F_60 ( V_2 -> V_4 . V_165 ) ;
const struct V_55 * V_56 = & V_165 -> V_171 -> V_4 . V_56 ;
struct V_55 * V_74 = & V_165 -> V_171 -> V_4 . V_74 ;
struct V_1 * V_1 = F_1 ( V_2 ) ;
T_1 V_212 ;
struct V_213 V_214 ;
struct V_93 V_185 , V_183 ;
int V_215 ;
if ( ! V_74 )
return;
V_214 . V_216 = V_1 -> V_184 ;
V_214 . V_217 = 0 ;
F_31 ( V_1 ,
V_218 ,
& V_214 , sizeof( V_214 ) ) ;
if ( ! F_40 ( V_1 ,
V_1 -> V_184 ) )
return;
if ( V_1 -> V_104 )
F_49 ( & V_183 ,
V_1 -> V_105 ) ;
else
F_49 ( & V_183 , V_74 ) ;
if ( ! F_44 ( V_1 , & V_183 ) )
F_72 ( L_17 ,
F_21 ( V_1 ) ) ;
if ( ! F_33 ( V_1 ) )
return;
if ( V_165 -> V_171 -> V_204 ) {
F_54 ( V_1 , V_219 ) ;
F_55 ( V_1 ,
V_220 ) ;
F_58 ( V_1 , V_56 ) ;
} else
F_54 ( V_1 , V_221 ) ;
if ( V_1 -> V_201 &&
! F_64 ( V_1 ) )
return;
F_49 ( & V_185 , V_56 ) ;
if ( V_1 -> V_201 || V_1 -> V_104 )
V_185 . V_96 . V_187 = V_1 -> V_186 ;
if ( ! F_43 ( V_1 , & V_185 ) )
F_72 ( L_18 ,
F_21 ( V_1 ) ) ;
switch ( V_165 -> V_171 -> V_203 ) {
default:
F_68 ( 1 , L_19 ) ;
case 1 : V_215 = V_222 ; break;
case 2 : V_215 = V_223 ; break;
case 4 : V_215 = V_224 ; break;
}
if ( ! F_48 ( V_1 , V_215 ) )
return;
if ( F_73 ( V_10 ) -> V_225 >= 4 ) {
V_212 = V_226 | V_227 ;
if ( ! F_8 ( V_10 ) && V_165 -> V_171 -> V_172 )
V_212 |= V_208 ;
if ( F_73 ( V_10 ) -> V_225 < 5 )
V_212 |= V_228 ;
} else {
V_212 = F_12 ( V_1 -> V_17 ) ;
if ( V_1 -> V_18 == V_19 )
V_212 &= V_229 ;
else
V_212 &= V_230 ;
V_212 |= ( 9 << 19 ) | V_228 ;
}
if ( F_74 ( V_10 ) >= V_231 )
V_212 |= F_75 ( V_165 -> V_232 ) ;
else
V_212 |= F_76 ( V_165 -> V_232 ) ;
if ( V_1 -> V_233 )
V_212 |= V_234 ;
if ( F_73 ( V_10 ) -> V_225 >= 4 ) {
} else if ( F_77 ( V_10 ) || F_78 ( V_10 ) || F_79 ( V_10 ) ) {
} else {
V_212 |= ( V_165 -> V_171 -> V_203 - 1 )
<< V_235 ;
}
if ( V_185 . V_96 . V_187 & V_236 &&
F_73 ( V_10 ) -> V_225 < 5 )
V_212 |= V_237 ;
F_7 ( V_1 , V_212 ) ;
}
static bool F_80 ( struct V_238 * V_6 )
{
struct V_7 * V_7 =
F_5 ( & V_6 -> V_4 ) ;
struct V_1 * V_1 = F_3 ( & V_6 -> V_4 ) ;
T_3 V_239 = 0 ;
F_37 ( V_1 , & V_239 ) ;
if ( V_239 & V_7 -> V_240 )
return true ;
else
return false ;
}
static bool F_81 ( struct V_2 * V_3 ,
enum V_232 * V_232 )
{
struct V_9 * V_10 = V_3 -> V_4 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
T_3 V_239 = 0 ;
T_1 V_157 ;
V_157 = F_12 ( V_1 -> V_17 ) ;
F_37 ( V_1 , & V_239 ) ;
if ( ! ( V_157 & V_241 ) && ( V_239 == 0 ) )
return false ;
if ( F_82 ( V_10 ) )
* V_232 = F_83 ( V_157 ) ;
else
* V_232 = F_84 ( V_157 ) ;
return true ;
}
static void F_85 ( struct V_2 * V_3 ,
struct V_188 * V_189 )
{
struct V_9 * V_10 = V_3 -> V_4 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_93 V_94 ;
int V_242 = 0 ;
int V_190 ;
T_1 V_27 = 0 , V_212 ;
T_2 V_8 ;
bool V_31 ;
V_212 = F_12 ( V_1 -> V_17 ) ;
V_31 = F_45 ( V_1 , & V_94 ) ;
if ( ! V_31 ) {
F_86 ( L_20 ) ;
V_189 -> V_243 |= V_244 ;
} else {
if ( V_94 . V_96 . V_136 & V_140 )
V_27 |= V_139 ;
else
V_27 |= V_145 ;
if ( V_94 . V_96 . V_136 & V_142 )
V_27 |= V_141 ;
else
V_27 |= V_146 ;
}
V_189 -> V_4 . V_56 . V_27 |= V_27 ;
if ( F_87 ( V_10 ) || F_88 ( V_10 ) ) {
V_189 -> V_203 =
( ( V_212 & V_245 )
>> V_235 ) + 1 ;
}
V_190 = V_189 -> V_191 ;
if ( V_189 -> V_203 )
V_190 /= V_189 -> V_203 ;
if ( F_8 ( V_10 ) )
F_89 ( V_189 , V_190 ) ;
V_189 -> V_4 . V_56 . V_57 = V_190 ;
if ( F_32 ( V_1 , V_246 ,
& V_8 , 1 ) ) {
switch ( V_8 ) {
case V_222 :
V_242 = 1 ;
break;
case V_223 :
V_242 = 2 ;
break;
case V_224 :
V_242 = 4 ;
break;
}
}
if ( V_212 & V_208 )
V_189 -> V_172 = true ;
if ( F_32 ( V_1 , V_247 ,
& V_8 , 1 ) ) {
if ( V_8 == V_219 )
V_189 -> V_204 = true ;
}
F_68 ( V_242 != V_189 -> V_203 ,
L_21 ,
V_189 -> V_203 , V_242 ) ;
}
static void F_90 ( struct V_2 * V_3 )
{
struct V_11 * V_12 = V_3 -> V_4 . V_10 -> V_13 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_166 * V_165 = F_60 ( V_3 -> V_4 . V_165 ) ;
T_1 V_248 ;
F_36 ( V_1 , 0 ) ;
if ( 0 )
F_38 ( V_1 ,
V_82 ) ;
V_248 = F_12 ( V_1 -> V_17 ) ;
V_248 &= ~ V_241 ;
F_7 ( V_1 , V_248 ) ;
if ( F_11 ( V_12 ) && V_165 -> V_232 == V_249 ) {
F_91 ( V_12 , V_250 , false ) ;
F_92 ( V_12 , V_250 , false ) ;
V_248 &= ~ V_251 ;
V_248 |= V_241 ;
F_7 ( V_1 , V_248 ) ;
V_248 &= ~ V_241 ;
F_7 ( V_1 , V_248 ) ;
F_93 ( V_12 -> V_10 , V_250 ) ;
F_91 ( V_12 , V_250 , true ) ;
F_92 ( V_12 , V_250 , true ) ;
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
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_166 * V_166 = F_60 ( V_3 -> V_4 . V_165 ) ;
T_1 V_248 ;
bool V_252 , V_253 ;
int V_16 ;
bool V_254 ;
V_248 = F_12 ( V_1 -> V_17 ) ;
V_248 |= V_241 ;
F_7 ( V_1 , V_248 ) ;
for ( V_16 = 0 ; V_16 < 2 ; V_16 ++ )
F_97 ( V_10 , V_166 -> V_232 ) ;
V_254 = F_34 ( V_1 , & V_252 , & V_253 ) ;
if ( V_254 && ! V_252 ) {
F_15 ( L_22
L_23 , F_21 ( V_1 ) ) ;
}
if ( 0 )
F_38 ( V_1 ,
V_77 ) ;
F_36 ( V_1 , V_1 -> V_184 ) ;
}
static enum V_255
F_98 ( struct V_5 * V_6 ,
struct V_55 * V_74 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
if ( V_74 -> V_27 & V_256 )
return V_257 ;
if ( V_1 -> V_258 > V_74 -> clock )
return V_259 ;
if ( V_1 -> V_260 < V_74 -> clock )
return V_261 ;
if ( V_1 -> V_104 ) {
if ( V_74 -> V_106 > V_1 -> V_105 -> V_106 )
return V_262 ;
if ( V_74 -> V_107 > V_1 -> V_105 -> V_107 )
return V_262 ;
}
return V_263 ;
}
static bool F_99 ( struct V_1 * V_1 , struct V_264 * V_265 )
{
F_35 ( sizeof( * V_265 ) != 8 ) ;
if ( ! F_32 ( V_1 ,
V_266 ,
V_265 , sizeof( * V_265 ) ) )
return false ;
F_15 ( L_24
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
V_265 -> V_267 ,
V_265 -> V_268 ,
V_265 -> V_269 ,
V_265 -> V_270 ,
V_265 -> V_271 ,
V_265 -> V_272 ,
V_265 -> V_273 ,
V_265 -> V_274 ,
V_265 -> V_275 ,
V_265 -> V_276 ,
V_265 -> V_277 ,
V_265 -> V_278 ) ;
return true ;
}
static T_4 F_100 ( struct V_1 * V_1 )
{
struct V_9 * V_10 = V_1 -> V_4 . V_4 . V_10 ;
T_4 V_279 ;
if ( ! F_101 ( V_10 ) )
return 0 ;
if ( F_77 ( V_10 ) || F_78 ( V_10 ) )
return 0 ;
if ( ! F_32 ( V_1 , V_280 ,
& V_279 , sizeof( V_279 ) ) )
return 0 ;
return V_279 ;
}
static void F_102 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
F_22 ( V_1 , V_281 ,
& V_1 -> V_282 , 2 ) ;
}
static bool
F_103 ( struct V_1 * V_1 )
{
return F_104 ( V_1 -> V_265 . V_278 ) > 1 ;
}
static struct V_283 *
F_105 ( struct V_5 * V_6 )
{
struct V_1 * V_284 = F_3 ( V_6 ) ;
return F_106 ( V_6 , & V_284 -> V_285 ) ;
}
static struct V_283 *
F_107 ( struct V_5 * V_6 )
{
struct V_11 * V_12 = V_6 -> V_10 -> V_13 ;
return F_106 ( V_6 ,
F_108 ( V_12 ,
V_12 -> V_286 . V_287 ) ) ;
}
static enum V_288
F_109 ( struct V_5 * V_6 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
enum V_288 V_39 ;
struct V_283 * V_283 ;
V_283 = F_105 ( V_6 ) ;
if ( V_283 == NULL && F_103 ( V_1 ) ) {
T_2 V_285 , V_289 = V_1 -> V_58 ;
for ( V_285 = V_1 -> V_58 >> 1 ; V_285 > 1 ; V_285 >>= 1 ) {
V_1 -> V_58 = V_285 ;
V_283 = F_105 ( V_6 ) ;
if ( V_283 )
break;
}
if ( V_283 == NULL )
V_1 -> V_58 = V_289 ;
}
if ( V_283 == NULL )
V_283 = F_107 ( V_6 ) ;
V_39 = V_290 ;
if ( V_283 != NULL ) {
if ( V_283 -> V_291 & V_292 ) {
V_39 = V_293 ;
if ( V_1 -> V_209 ) {
V_1 -> V_205 = F_110 ( V_283 ) ;
V_1 -> V_233 = F_111 ( V_283 ) ;
V_1 -> V_170 =
F_112 ( V_283 ) ;
}
} else
V_39 = V_294 ;
F_25 ( V_283 ) ;
}
if ( V_39 == V_293 ) {
struct V_7 * V_7 = F_5 ( V_6 ) ;
if ( V_7 -> V_295 != V_296 )
V_1 -> V_233 = ( V_7 -> V_295 == V_297 ) ;
}
return V_39 ;
}
static bool
F_113 ( struct V_7 * V_284 ,
struct V_283 * V_283 )
{
bool V_298 = ! ! ( V_283 -> V_291 & V_292 ) ;
bool V_299 = ! ! F_114 ( V_284 ) ;
F_15 ( L_37 ,
V_299 , V_298 ) ;
return V_299 == V_298 ;
}
static enum V_288
F_115 ( struct V_5 * V_6 , bool V_300 )
{
T_4 V_45 ;
struct V_1 * V_1 = F_3 ( V_6 ) ;
struct V_7 * V_7 = F_5 ( V_6 ) ;
enum V_288 V_31 ;
F_15 ( L_38 ,
V_6 -> V_4 . V_301 , V_6 -> V_38 ) ;
if ( ! F_32 ( V_1 ,
V_302 ,
& V_45 , 2 ) )
return V_290 ;
F_15 ( L_39 ,
V_45 & 0xff , V_45 >> 8 ,
V_7 -> V_240 ) ;
if ( V_45 == 0 )
return V_294 ;
V_1 -> V_184 = V_45 ;
V_1 -> V_205 = false ;
V_1 -> V_233 = false ;
V_1 -> V_170 = false ;
if ( ( V_7 -> V_240 & V_45 ) == 0 )
V_31 = V_294 ;
else if ( F_116 ( V_7 ) )
V_31 = F_109 ( V_6 ) ;
else {
struct V_283 * V_283 ;
V_283 = F_105 ( V_6 ) ;
if ( V_283 == NULL )
V_283 = F_107 ( V_6 ) ;
if ( V_283 != NULL ) {
if ( F_113 ( V_7 ,
V_283 ) )
V_31 = V_293 ;
else
V_31 = V_294 ;
F_25 ( V_283 ) ;
} else
V_31 = V_293 ;
}
if ( V_31 == V_293 ) {
V_1 -> V_201 = false ;
V_1 -> V_104 = false ;
if ( V_45 & V_303 )
V_1 -> V_201 = true ;
if ( V_45 & V_304 )
V_1 -> V_104 = V_1 -> V_105 != NULL ;
}
return V_31 ;
}
static void F_117 ( struct V_5 * V_6 )
{
struct V_283 * V_283 ;
F_15 ( L_38 ,
V_6 -> V_4 . V_301 , V_6 -> V_38 ) ;
V_283 = F_105 ( V_6 ) ;
if ( V_283 == NULL )
V_283 = F_107 ( V_6 ) ;
if ( V_283 != NULL ) {
if ( F_113 ( F_5 ( V_6 ) ,
V_283 ) ) {
F_118 ( V_6 , V_283 ) ;
F_119 ( V_6 , V_283 ) ;
}
F_25 ( V_283 ) ;
}
}
static void F_120 ( struct V_5 * V_6 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
struct V_305 V_306 ;
T_7 V_307 = 0 , V_180 = 0 ;
int V_16 ;
F_15 ( L_38 ,
V_6 -> V_4 . V_301 , V_6 -> V_38 ) ;
V_180 = 1 << V_1 -> V_181 ;
memcpy ( & V_306 , & V_180 ,
V_90 ( sizeof( V_180 ) , sizeof( struct V_305 ) ) ) ;
if ( ! F_40 ( V_1 , V_1 -> V_184 ) )
return;
F_35 ( sizeof( V_306 ) != 3 ) ;
if ( ! F_22 ( V_1 ,
V_308 ,
& V_306 , sizeof( V_306 ) ) )
return;
if ( ! F_26 ( V_1 , & V_307 , 3 ) )
return;
for ( V_16 = 0 ; V_16 < F_19 ( V_309 ) ; V_16 ++ )
if ( V_307 & ( 1 << V_16 ) ) {
struct V_55 * V_310 ;
V_310 = F_121 ( V_6 -> V_10 ,
& V_309 [ V_16 ] ) ;
if ( V_310 )
F_122 ( V_6 , V_310 ) ;
}
}
static void F_123 ( struct V_5 * V_6 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
struct V_11 * V_12 = V_6 -> V_10 -> V_13 ;
struct V_55 * V_311 ;
F_15 ( L_38 ,
V_6 -> V_4 . V_301 , V_6 -> V_38 ) ;
if ( V_12 -> V_286 . V_312 != NULL ) {
V_311 = F_121 ( V_6 -> V_10 ,
V_12 -> V_286 . V_312 ) ;
if ( V_311 != NULL ) {
V_311 -> type = ( V_313 |
V_314 ) ;
F_122 ( V_6 , V_311 ) ;
}
}
F_124 ( V_6 , & V_1 -> V_285 ) ;
F_125 (newmode, &connector->probed_modes, head) {
if ( V_311 -> type & V_313 ) {
V_1 -> V_105 =
F_121 ( V_6 -> V_10 , V_311 ) ;
V_1 -> V_104 = true ;
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
return ! F_129 ( & V_6 -> V_315 ) ;
}
static void F_130 ( struct V_5 * V_6 )
{
struct V_7 * V_7 = F_5 ( V_6 ) ;
F_131 ( V_6 ) ;
F_25 ( V_7 ) ;
}
static bool F_132 ( struct V_5 * V_6 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
struct V_283 * V_283 ;
bool V_316 = false ;
if ( ! V_1 -> V_209 )
return false ;
V_283 = F_105 ( V_6 ) ;
if ( V_283 != NULL && V_283 -> V_291 & V_292 )
V_316 = F_111 ( V_283 ) ;
F_25 ( V_283 ) ;
return V_316 ;
}
static int
F_133 ( struct V_5 * V_6 ,
struct V_317 * V_318 ,
T_8 V_8 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
struct V_7 * V_7 = F_5 ( V_6 ) ;
struct V_11 * V_12 = V_6 -> V_10 -> V_13 ;
T_4 V_319 ;
T_5 V_33 ;
int V_31 ;
V_31 = F_134 ( & V_6 -> V_4 , V_318 , V_8 ) ;
if ( V_31 )
return V_31 ;
if ( V_318 == V_12 -> V_320 ) {
int V_16 = V_8 ;
bool V_316 ;
if ( V_16 == V_7 -> V_295 )
return 0 ;
V_7 -> V_295 = V_16 ;
if ( V_16 == V_296 )
V_316 = F_132 ( V_6 ) ;
else
V_316 = ( V_16 == V_297 ) ;
if ( V_316 == V_1 -> V_233 )
return 0 ;
V_1 -> V_233 = V_316 ;
goto V_321;
}
if ( V_318 == V_12 -> V_322 ) {
bool V_323 = V_1 -> V_206 ;
T_7 V_324 = V_1 -> V_207 ;
switch ( V_8 ) {
case V_325 :
V_1 -> V_206 = true ;
break;
case V_326 :
V_1 -> V_206 = false ;
V_1 -> V_207 = 0 ;
break;
case V_327 :
V_1 -> V_206 = false ;
V_1 -> V_207 = V_208 ;
break;
default:
return - V_328 ;
}
if ( V_323 == V_1 -> V_206 &&
V_324 == V_1 -> V_207 )
return 0 ;
goto V_321;
}
if ( V_318 == V_6 -> V_10 -> V_329 . V_330 ) {
switch ( V_8 ) {
case V_331 :
V_1 -> V_211 = V_332 ;
break;
case V_333 :
V_1 -> V_211 = V_334 ;
break;
case V_335 :
V_1 -> V_211 = V_336 ;
break;
default:
return - V_328 ;
}
goto V_321;
}
#define F_135 ( V_38 , T_9 ) \
if (intel_sdvo_connector->name == property) { \
if (intel_sdvo_connector->cur_##name == temp_value) return 0; \
if (intel_sdvo_connector->max_##name < temp_value) return -EINVAL; \
cmd = SDVO_CMD_SET_##NAME; \
intel_sdvo_connector->cur_##name = temp_value; \
goto set_value; \
}
if ( V_318 == V_7 -> V_337 ) {
if ( V_8 >= V_338 )
return - V_328 ;
if ( V_1 -> V_181 ==
V_7 -> V_339 [ V_8 ] )
return 0 ;
V_1 -> V_181 = V_7 -> V_339 [ V_8 ] ;
goto V_321;
} else if ( F_136 ( V_7 ) ) {
V_319 = V_8 ;
if ( V_7 -> V_340 == V_318 ) {
F_134 ( & V_6 -> V_4 ,
V_7 -> V_341 , V_8 ) ;
if ( V_7 -> V_342 == V_319 )
return 0 ;
V_7 -> V_342 = V_319 ;
V_7 -> V_343 = V_319 ;
V_319 = V_7 -> V_344 -
V_7 -> V_342 ;
V_33 = V_345 ;
goto V_346;
} else if ( V_7 -> V_341 == V_318 ) {
F_134 ( & V_6 -> V_4 ,
V_7 -> V_340 , V_8 ) ;
if ( V_7 -> V_343 == V_319 )
return 0 ;
V_7 -> V_342 = V_319 ;
V_7 -> V_343 = V_319 ;
V_319 = V_7 -> V_344 -
V_7 -> V_342 ;
V_33 = V_345 ;
goto V_346;
} else if ( V_7 -> V_347 == V_318 ) {
F_134 ( & V_6 -> V_4 ,
V_7 -> V_348 , V_8 ) ;
if ( V_7 -> V_349 == V_319 )
return 0 ;
V_7 -> V_349 = V_319 ;
V_7 -> V_350 = V_319 ;
V_319 = V_7 -> V_351 -
V_7 -> V_349 ;
V_33 = V_352 ;
goto V_346;
} else if ( V_7 -> V_348 == V_318 ) {
F_134 ( & V_6 -> V_4 ,
V_7 -> V_347 , V_8 ) ;
if ( V_7 -> V_350 == V_319 )
return 0 ;
V_7 -> V_349 = V_319 ;
V_7 -> V_350 = V_319 ;
V_319 = V_7 -> V_351 -
V_7 -> V_349 ;
V_33 = V_352 ;
goto V_346;
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
return - V_328 ;
V_346:
if ( ! F_31 ( V_1 , V_33 , & V_319 , 2 ) )
return - V_353 ;
V_321:
if ( V_1 -> V_4 . V_4 . V_165 )
F_137 ( V_1 -> V_4 . V_4 . V_165 ) ;
return 0 ;
#undef F_135
}
static void F_138 ( struct V_354 * V_3 )
{
struct V_1 * V_1 = F_1 ( F_139 ( V_3 ) ) ;
if ( V_1 -> V_105 != NULL )
F_140 ( V_3 -> V_10 ,
V_1 -> V_105 ) ;
F_141 ( & V_1 -> V_285 ) ;
F_142 ( V_3 ) ;
}
static void
F_143 ( struct V_1 * V_284 )
{
T_4 V_355 = 0 ;
unsigned int V_356 ;
switch ( V_284 -> V_357 ) {
case V_358 :
V_355 |= V_358 ;
case V_359 :
V_355 |= V_359 ;
case V_360 :
V_355 |= V_360 ;
case V_361 :
V_355 |= V_361 ;
case V_362 :
V_355 |= V_362 ;
case V_363 :
V_355 |= V_363 ;
break;
}
V_355 &= V_284 -> V_265 . V_278 ;
V_356 = F_104 ( V_355 ) ;
if ( V_356 > 3 )
V_356 = 3 ;
V_284 -> V_58 = 1 << V_356 ;
}
static void
F_144 ( struct V_11 * V_12 ,
struct V_1 * V_284 )
{
struct V_364 * V_365 ;
if ( V_284 -> V_18 == V_19 )
V_365 = & ( V_12 -> V_366 [ 0 ] ) ;
else
V_365 = & ( V_12 -> V_366 [ 1 ] ) ;
if ( V_365 -> V_367 )
V_284 -> V_58 = 1 << ( ( V_365 -> V_368 & 0xf0 ) >> 4 ) ;
else
F_143 ( V_284 ) ;
}
static void
F_145 ( struct V_11 * V_12 ,
struct V_1 * V_284 )
{
struct V_364 * V_365 ;
T_2 V_369 ;
if ( V_284 -> V_18 == V_19 )
V_365 = & V_12 -> V_366 [ 0 ] ;
else
V_365 = & V_12 -> V_366 [ 1 ] ;
if ( V_365 -> V_367 &&
F_146 ( V_12 , V_365 -> V_370 ) )
V_369 = V_365 -> V_370 ;
else
V_369 = V_371 ;
V_284 -> V_32 = F_108 ( V_12 , V_369 ) ;
F_147 ( V_284 -> V_32 , true ) ;
}
static void
F_148 ( struct V_1 * V_284 )
{
F_147 ( V_284 -> V_32 , false ) ;
}
static bool
F_149 ( struct V_1 * V_1 , int V_372 )
{
return F_53 ( V_1 ) ;
}
static T_2
F_150 ( struct V_9 * V_10 , struct V_1 * V_284 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_364 * V_373 , * V_374 ;
if ( V_284 -> V_18 == V_19 ) {
V_373 = & V_12 -> V_366 [ 0 ] ;
V_374 = & V_12 -> V_366 [ 1 ] ;
} else {
V_373 = & V_12 -> V_366 [ 1 ] ;
V_374 = & V_12 -> V_366 [ 0 ] ;
}
if ( V_373 -> V_26 )
return V_373 -> V_26 ;
if ( V_374 -> V_26 ) {
if ( V_374 -> V_26 == 0x70 )
return 0x72 ;
else
return 0x70 ;
}
if ( V_284 -> V_18 == V_19 )
return 0x70 ;
else
return 0x72 ;
}
static void
F_151 ( struct V_238 * V_238 )
{
struct V_5 * V_5 ;
struct V_1 * V_375 ;
V_5 = & V_238 -> V_4 ;
V_375 = F_3 ( & V_238 -> V_4 ) ;
F_152 ( & V_5 -> V_376 -> V_377 ,
V_375 -> V_285 . V_10 . V_377 . V_38 ) ;
F_153 ( V_238 ) ;
}
static int
F_154 ( struct V_7 * V_6 ,
struct V_1 * V_3 )
{
struct V_5 * V_5 ;
int V_31 ;
V_5 = & V_6 -> V_4 . V_4 ;
V_31 = F_155 ( V_3 -> V_4 . V_4 . V_10 ,
V_5 ,
& V_378 ,
V_6 -> V_4 . V_4 . V_379 ) ;
if ( V_31 < 0 )
return V_31 ;
F_156 ( V_5 ,
& V_380 ) ;
V_6 -> V_4 . V_4 . V_381 = 1 ;
V_6 -> V_4 . V_4 . V_382 = 0 ;
V_6 -> V_4 . V_4 . V_383 . V_384 = V_385 ;
V_6 -> V_4 . V_386 = F_80 ;
V_6 -> V_4 . V_387 = F_151 ;
F_157 ( & V_6 -> V_4 , & V_3 -> V_4 ) ;
V_31 = F_158 ( V_5 ) ;
if ( V_31 < 0 )
goto V_388;
V_31 = F_159 ( & V_5 -> V_376 -> V_377 ,
& V_3 -> V_285 . V_10 . V_377 ,
V_3 -> V_285 . V_10 . V_377 . V_38 ) ;
if ( V_31 < 0 )
goto V_389;
return 0 ;
V_389:
F_160 ( V_5 ) ;
V_388:
F_131 ( V_5 ) ;
return V_31 ;
}
static void
F_161 ( struct V_1 * V_1 ,
struct V_7 * V_6 )
{
struct V_9 * V_10 = V_6 -> V_4 . V_4 . V_10 ;
F_162 ( & V_6 -> V_4 . V_4 ) ;
if ( F_73 ( V_10 ) -> V_225 >= 4 && F_163 ( V_10 ) ) {
F_164 ( & V_6 -> V_4 . V_4 ) ;
V_1 -> V_206 = true ;
}
F_165 ( & V_6 -> V_4 . V_4 ) ;
V_1 -> V_211 = V_332 ;
}
static struct V_7 * F_166 ( void )
{
struct V_7 * V_390 ;
V_390 = F_23 ( sizeof( * V_390 ) , V_40 ) ;
if ( ! V_390 )
return NULL ;
if ( F_167 ( & V_390 -> V_4 ) < 0 ) {
F_25 ( V_390 ) ;
return NULL ;
}
return V_390 ;
}
static bool
F_168 ( struct V_1 * V_1 , int V_372 )
{
struct V_354 * V_3 = & V_1 -> V_4 . V_4 ;
struct V_5 * V_6 ;
struct V_2 * V_2 = F_139 ( V_3 ) ;
struct V_238 * V_238 ;
struct V_7 * V_7 ;
F_15 ( L_40 , V_372 ) ;
V_7 = F_166 () ;
if ( ! V_7 )
return false ;
if ( V_372 == 0 ) {
V_1 -> V_357 |= V_361 ;
V_7 -> V_240 = V_361 ;
} else if ( V_372 == 1 ) {
V_1 -> V_357 |= V_360 ;
V_7 -> V_240 = V_360 ;
}
V_238 = & V_7 -> V_4 ;
V_6 = & V_238 -> V_4 ;
if ( F_100 ( V_1 ) &
V_7 -> V_240 ) {
V_1 -> V_282 |= V_7 -> V_240 ;
V_2 -> V_391 = F_102 ;
F_102 ( V_2 ) ;
} else {
V_238 -> V_392 = V_393 | V_394 ;
}
V_3 -> V_395 = V_396 ;
V_6 -> V_379 = V_397 ;
if ( F_149 ( V_1 , V_372 ) ) {
V_6 -> V_379 = V_398 ;
V_1 -> V_209 = true ;
}
if ( F_154 ( V_7 , V_1 ) < 0 ) {
F_25 ( V_7 ) ;
return false ;
}
if ( V_1 -> V_209 )
F_161 ( V_1 , V_7 ) ;
return true ;
}
static bool
F_169 ( struct V_1 * V_1 , int type )
{
struct V_354 * V_3 = & V_1 -> V_4 . V_4 ;
struct V_5 * V_6 ;
struct V_238 * V_238 ;
struct V_7 * V_7 ;
F_15 ( L_41 , type ) ;
V_7 = F_166 () ;
if ( ! V_7 )
return false ;
V_238 = & V_7 -> V_4 ;
V_6 = & V_238 -> V_4 ;
V_3 -> V_395 = V_399 ;
V_6 -> V_379 = V_400 ;
V_1 -> V_357 |= type ;
V_7 -> V_240 = type ;
V_1 -> V_201 = true ;
if ( F_154 ( V_7 , V_1 ) < 0 ) {
F_25 ( V_7 ) ;
return false ;
}
if ( ! F_170 ( V_1 , V_7 , type ) )
goto V_401;
if ( ! F_171 ( V_1 , V_7 ) )
goto V_401;
return true ;
V_401:
F_160 ( V_6 ) ;
F_130 ( V_6 ) ;
return false ;
}
static bool
F_172 ( struct V_1 * V_1 , int V_372 )
{
struct V_354 * V_3 = & V_1 -> V_4 . V_4 ;
struct V_5 * V_6 ;
struct V_238 * V_238 ;
struct V_7 * V_7 ;
F_15 ( L_42 , V_372 ) ;
V_7 = F_166 () ;
if ( ! V_7 )
return false ;
V_238 = & V_7 -> V_4 ;
V_6 = & V_238 -> V_4 ;
V_238 -> V_392 = V_393 ;
V_3 -> V_395 = V_402 ;
V_6 -> V_379 = V_403 ;
if ( V_372 == 0 ) {
V_1 -> V_357 |= V_363 ;
V_7 -> V_240 = V_363 ;
} else if ( V_372 == 1 ) {
V_1 -> V_357 |= V_362 ;
V_7 -> V_240 = V_362 ;
}
if ( F_154 ( V_7 , V_1 ) < 0 ) {
F_25 ( V_7 ) ;
return false ;
}
return true ;
}
static bool
F_173 ( struct V_1 * V_1 , int V_372 )
{
struct V_354 * V_3 = & V_1 -> V_4 . V_4 ;
struct V_5 * V_6 ;
struct V_238 * V_238 ;
struct V_7 * V_7 ;
F_15 ( L_43 , V_372 ) ;
V_7 = F_166 () ;
if ( ! V_7 )
return false ;
V_238 = & V_7 -> V_4 ;
V_6 = & V_238 -> V_4 ;
V_3 -> V_395 = V_404 ;
V_6 -> V_379 = V_405 ;
if ( V_372 == 0 ) {
V_1 -> V_357 |= V_359 ;
V_7 -> V_240 = V_359 ;
} else if ( V_372 == 1 ) {
V_1 -> V_357 |= V_358 ;
V_7 -> V_240 = V_358 ;
}
if ( F_154 ( V_7 , V_1 ) < 0 ) {
F_25 ( V_7 ) ;
return false ;
}
if ( ! F_171 ( V_1 , V_7 ) )
goto V_401;
return true ;
V_401:
F_160 ( V_6 ) ;
F_130 ( V_6 ) ;
return false ;
}
static bool
F_174 ( struct V_1 * V_1 , T_4 V_27 )
{
V_1 -> V_201 = false ;
V_1 -> V_104 = false ;
if ( V_27 & V_361 )
if ( ! F_168 ( V_1 , 0 ) )
return false ;
if ( ( V_27 & V_406 ) == V_406 )
if ( ! F_168 ( V_1 , 1 ) )
return false ;
if ( V_27 & V_407 )
if ( ! F_169 ( V_1 , V_407 ) )
return false ;
if ( V_27 & V_408 )
if ( ! F_169 ( V_1 , V_408 ) )
return false ;
if ( V_27 & V_409 )
if ( ! F_169 ( V_1 , V_409 ) )
return false ;
if ( V_27 & V_363 )
if ( ! F_172 ( V_1 , 0 ) )
return false ;
if ( ( V_27 & V_410 ) == V_410 )
if ( ! F_172 ( V_1 , 1 ) )
return false ;
if ( V_27 & V_359 )
if ( ! F_173 ( V_1 , 0 ) )
return false ;
if ( ( V_27 & V_304 ) == V_304 )
if ( ! F_173 ( V_1 , 1 ) )
return false ;
if ( ( V_27 & V_411 ) == 0 ) {
unsigned char V_412 [ 2 ] ;
V_1 -> V_357 = 0 ;
memcpy ( V_412 , & V_1 -> V_265 . V_278 , 2 ) ;
F_15 ( L_44 ,
F_21 ( V_1 ) ,
V_412 [ 0 ] , V_412 [ 1 ] ) ;
return false ;
}
V_1 -> V_4 . V_413 = ( 1 << 0 ) | ( 1 << 1 ) | ( 1 << 2 ) ;
return true ;
}
static void F_175 ( struct V_1 * V_1 )
{
struct V_9 * V_10 = V_1 -> V_4 . V_4 . V_10 ;
struct V_5 * V_6 , * V_157 ;
F_176 (connector, tmp,
&dev->mode_config.connector_list, head) {
if ( F_4 ( V_6 ) == & V_1 -> V_4 ) {
F_160 ( V_6 ) ;
F_130 ( V_6 ) ;
}
}
}
static bool F_170 ( struct V_1 * V_1 ,
struct V_7 * V_7 ,
int type )
{
struct V_9 * V_10 = V_1 -> V_4 . V_4 . V_10 ;
struct V_178 V_179 ;
T_7 V_180 , V_16 ;
if ( ! F_40 ( V_1 , type ) )
return false ;
F_35 ( sizeof( V_179 ) != 6 ) ;
if ( ! F_32 ( V_1 ,
V_414 ,
& V_179 , sizeof( V_179 ) ) )
return false ;
memcpy ( & V_180 , & V_179 , V_90 ( sizeof( V_180 ) , sizeof( V_179 ) ) ) ;
if ( V_180 == 0 )
return false ;
V_7 -> V_415 = 0 ;
for ( V_16 = 0 ; V_16 < V_338 ; V_16 ++ )
if ( V_180 & ( 1 << V_16 ) )
V_7 -> V_339 [ V_7 -> V_415 ++ ] = V_16 ;
V_7 -> V_337 =
F_177 ( V_10 , V_416 ,
L_45 , V_7 -> V_415 ) ;
if ( ! V_7 -> V_337 )
return false ;
for ( V_16 = 0 ; V_16 < V_7 -> V_415 ; V_16 ++ )
F_178 (
V_7 -> V_337 , V_16 ,
V_16 , V_417 [ V_7 -> V_339 [ V_16 ] ] ) ;
V_1 -> V_181 = V_7 -> V_339 [ 0 ] ;
F_179 ( & V_7 -> V_4 . V_4 . V_4 ,
V_7 -> V_337 , 0 ) ;
return true ;
}
static bool
F_180 ( struct V_1 * V_1 ,
struct V_7 * V_7 ,
struct V_418 V_419 )
{
struct V_9 * V_10 = V_1 -> V_4 . V_4 . V_10 ;
struct V_5 * V_6 = & V_7 -> V_4 . V_4 ;
T_4 V_45 , V_420 [ 2 ] ;
if ( V_419 . V_421 ) {
if ( ! F_32 ( V_1 ,
V_422 ,
& V_420 , 4 ) )
return false ;
if ( ! F_32 ( V_1 ,
V_423 ,
& V_45 , 2 ) )
return false ;
V_7 -> V_344 = V_420 [ 0 ] ;
V_7 -> V_342 = V_420 [ 0 ] - V_45 ;
V_7 -> V_343 = V_7 -> V_342 ;
V_7 -> V_340 =
F_181 ( V_10 , 0 , L_46 , 0 , V_420 [ 0 ] ) ;
if ( ! V_7 -> V_340 )
return false ;
F_179 ( & V_6 -> V_4 ,
V_7 -> V_340 ,
V_7 -> V_342 ) ;
V_7 -> V_341 =
F_181 ( V_10 , 0 , L_47 , 0 , V_420 [ 0 ] ) ;
if ( ! V_7 -> V_341 )
return false ;
F_179 ( & V_6 -> V_4 ,
V_7 -> V_341 ,
V_7 -> V_343 ) ;
F_15 ( L_48
L_49 ,
V_420 [ 0 ] , V_420 [ 1 ] , V_45 ) ;
}
if ( V_419 . V_424 ) {
if ( ! F_32 ( V_1 ,
V_425 ,
& V_420 , 4 ) )
return false ;
if ( ! F_32 ( V_1 ,
V_426 ,
& V_45 , 2 ) )
return false ;
V_7 -> V_351 = V_420 [ 0 ] ;
V_7 -> V_349 = V_420 [ 0 ] - V_45 ;
V_7 -> V_350 = V_7 -> V_349 ;
V_7 -> V_347 =
F_181 ( V_10 , 0 ,
L_50 , 0 , V_420 [ 0 ] ) ;
if ( ! V_7 -> V_347 )
return false ;
F_179 ( & V_6 -> V_4 ,
V_7 -> V_347 ,
V_7 -> V_349 ) ;
V_7 -> V_348 =
F_181 ( V_10 , 0 ,
L_51 , 0 , V_420 [ 0 ] ) ;
if ( ! V_7 -> V_348 )
return false ;
F_179 ( & V_6 -> V_4 ,
V_7 -> V_348 ,
V_7 -> V_350 ) ;
F_15 ( L_52
L_49 ,
V_420 [ 0 ] , V_420 [ 1 ] , V_45 ) ;
}
F_182 ( V_427 , V_428 ) ;
F_182 ( V_429 , V_430 ) ;
F_182 ( V_431 , V_432 ) ;
F_182 ( V_433 , V_434 ) ;
F_182 ( V_435 , V_436 ) ;
F_182 ( V_437 , V_438 ) ;
F_182 ( V_439 , V_440 ) ;
F_182 ( V_441 , V_442 ) ;
F_182 ( V_443 , V_444 ) ;
F_182 ( V_445 , V_446 ) ;
F_182 ( V_447 , V_448 ) ;
F_182 ( V_449 , V_450 ) ;
if ( V_419 . V_451 ) {
if ( ! F_32 ( V_1 , V_452 , & V_45 , 2 ) )
return false ;
V_7 -> V_453 = 1 ;
V_7 -> V_454 = V_45 & 0x1 ;
V_7 -> V_451 =
F_181 ( V_10 , 0 , L_53 , 0 , 1 ) ;
if ( ! V_7 -> V_451 )
return false ;
F_179 ( & V_6 -> V_4 ,
V_7 -> V_451 ,
V_7 -> V_454 ) ;
F_15 ( L_54 , V_45 ) ;
}
return true ;
}
static bool
F_183 ( struct V_1 * V_1 ,
struct V_7 * V_7 ,
struct V_418 V_419 )
{
struct V_9 * V_10 = V_1 -> V_4 . V_4 . V_10 ;
struct V_5 * V_6 = & V_7 -> V_4 . V_4 ;
T_4 V_45 , V_420 [ 2 ] ;
F_182 ( V_439 , V_440 ) ;
return true ;
}
static bool F_171 ( struct V_1 * V_1 ,
struct V_7 * V_7 )
{
union {
struct V_418 V_307 ;
T_4 V_45 ;
} V_419 ;
F_35 ( sizeof( V_419 ) != 2 ) ;
V_419 . V_45 = 0 ;
F_32 ( V_1 ,
V_455 ,
& V_419 , sizeof( V_419 ) ) ;
if ( V_419 . V_45 == 0 ) {
F_15 ( L_55 ) ;
return true ;
}
if ( F_127 ( V_7 ) )
return F_180 ( V_1 , V_7 , V_419 . V_307 ) ;
else if ( F_128 ( V_7 ) )
return F_183 ( V_1 , V_7 , V_419 . V_307 ) ;
else
return true ;
}
static int F_184 ( struct V_456 * V_457 ,
struct V_24 * V_25 ,
int V_458 )
{
struct V_1 * V_284 = V_457 -> V_459 ;
if ( ! F_30 ( V_284 , V_284 -> V_58 ) )
return - V_353 ;
return V_284 -> V_32 -> V_460 -> V_461 ( V_284 -> V_32 , V_25 , V_458 ) ;
}
static T_1 F_185 ( struct V_456 * V_457 )
{
struct V_1 * V_284 = V_457 -> V_459 ;
return V_284 -> V_32 -> V_460 -> V_462 ( V_284 -> V_32 ) ;
}
static bool
F_186 ( struct V_1 * V_284 ,
struct V_9 * V_10 )
{
V_284 -> V_285 . V_463 = V_464 ;
V_284 -> V_285 . V_465 = V_466 ;
snprintf ( V_284 -> V_285 . V_38 , V_467 , L_56 ) ;
V_284 -> V_285 . V_10 . V_468 = & V_10 -> V_469 -> V_10 ;
V_284 -> V_285 . V_459 = V_284 ;
V_284 -> V_285 . V_460 = & V_470 ;
return F_187 ( & V_284 -> V_285 ) == 0 ;
}
static void F_188 ( const struct V_11 * V_12 ,
enum V_18 V_18 )
{
if ( F_8 ( V_12 ) )
F_189 ( V_18 != V_19 ) ;
else
F_189 ( V_18 != V_19 && V_18 != V_471 ) ;
}
bool F_190 ( struct V_9 * V_10 ,
T_10 V_17 , enum V_18 V_18 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_2 * V_2 ;
struct V_1 * V_1 ;
int V_16 ;
F_188 ( V_12 , V_18 ) ;
V_1 = F_23 ( sizeof( * V_1 ) , V_40 ) ;
if ( ! V_1 )
return false ;
V_1 -> V_17 = V_17 ;
V_1 -> V_18 = V_18 ;
V_1 -> V_26 = F_150 ( V_10 , V_1 ) >> 1 ;
F_145 ( V_12 , V_1 ) ;
if ( ! F_186 ( V_1 , V_10 ) )
goto V_472;
V_2 = & V_1 -> V_4 ;
V_2 -> type = V_473 ;
F_191 ( V_10 , & V_2 -> V_4 , & V_474 , 0 ,
NULL ) ;
for ( V_16 = 0 ; V_16 < 0x40 ; V_16 ++ ) {
T_2 V_475 ;
if ( ! F_13 ( V_1 , V_16 , & V_475 ) ) {
F_15 ( L_57 ,
F_21 ( V_1 ) ) ;
goto V_401;
}
}
V_2 -> V_476 = F_69 ;
if ( F_8 ( V_10 ) ) {
V_2 -> V_477 = F_94 ;
V_2 -> V_478 = F_95 ;
} else {
V_2 -> V_477 = F_90 ;
}
V_2 -> V_479 = F_71 ;
V_2 -> V_480 = F_96 ;
V_2 -> V_386 = F_81 ;
V_2 -> V_481 = F_85 ;
if ( ! F_99 ( V_1 , & V_1 -> V_265 ) )
goto V_401;
if ( F_174 ( V_1 ,
V_1 -> V_265 . V_278 ) != true ) {
F_15 ( L_58 ,
F_21 ( V_1 ) ) ;
goto V_482;
}
if ( V_1 -> V_282 ) {
if ( V_1 -> V_18 == V_19 )
V_2 -> V_483 = V_484 ;
else
V_2 -> V_483 = V_485 ;
}
V_1 -> V_4 . V_486 = 0 ;
F_144 ( V_12 , V_1 ) ;
if ( ! F_33 ( V_1 ) )
goto V_482;
if ( ! F_39 ( V_1 ,
& V_1 -> V_258 ,
& V_1 -> V_260 ) )
goto V_482;
F_15 ( L_59
L_60
L_61
L_62 ,
F_21 ( V_1 ) ,
V_1 -> V_265 . V_267 , V_1 -> V_265 . V_268 ,
V_1 -> V_265 . V_269 ,
V_1 -> V_258 / 1000 ,
V_1 -> V_260 / 1000 ,
( V_1 -> V_265 . V_272 & 0x1 ) ? 'Y' : 'N' ,
( V_1 -> V_265 . V_272 & 0x2 ) ? 'Y' : 'N' ,
V_1 -> V_265 . V_278 &
( V_361 | V_363 ) ? 'Y' : 'N' ,
V_1 -> V_265 . V_278 &
( V_360 | V_362 ) ? 'Y' : 'N' ) ;
return true ;
V_482:
F_175 ( V_1 ) ;
V_401:
F_192 ( & V_2 -> V_4 ) ;
F_141 ( & V_1 -> V_285 ) ;
V_472:
F_148 ( V_1 ) ;
F_25 ( V_1 ) ;
return false ;
}
