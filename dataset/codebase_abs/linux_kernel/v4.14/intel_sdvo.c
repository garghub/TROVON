static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static struct V_1 * F_3 ( struct V_5 * V_6 )
{
return F_1 ( F_4 ( V_6 ) ) ;
}
static struct V_7 *
F_5 ( struct V_5 * V_6 )
{
return F_2 ( V_6 , struct V_7 , V_4 . V_4 ) ;
}
static struct V_8 *
F_6 ( struct V_9 * V_10 )
{
return F_2 ( V_10 , struct V_8 , V_4 . V_4 ) ;
}
static void F_7 ( struct V_1 * V_1 , T_1 V_11 )
{
struct V_12 * V_13 = V_1 -> V_4 . V_4 . V_13 ;
struct V_14 * V_15 = F_8 ( V_13 ) ;
T_1 V_16 = V_11 , V_17 = V_11 ;
int V_18 ;
if ( F_9 ( V_15 ) ) {
F_10 ( V_1 -> V_19 , V_11 ) ;
F_11 ( V_1 -> V_19 ) ;
if ( F_12 ( V_15 ) ) {
F_10 ( V_1 -> V_19 , V_11 ) ;
F_11 ( V_1 -> V_19 ) ;
}
return;
}
if ( V_1 -> V_20 == V_21 )
V_17 = F_13 ( V_22 ) ;
else
V_16 = F_13 ( V_23 ) ;
for ( V_18 = 0 ; V_18 < 2 ; V_18 ++ )
{
F_10 ( V_23 , V_16 ) ;
F_11 ( V_23 ) ;
F_10 ( V_22 , V_17 ) ;
F_11 ( V_22 ) ;
}
}
static bool F_14 ( struct V_1 * V_1 , T_2 V_24 , T_2 * V_25 )
{
struct V_26 V_27 [] = {
{
. V_24 = V_1 -> V_28 ,
. V_29 = 0 ,
. V_30 = 1 ,
. V_31 = & V_24 ,
} ,
{
. V_24 = V_1 -> V_28 ,
. V_29 = V_32 ,
. V_30 = 1 ,
. V_31 = V_25 ,
}
} ;
int V_33 ;
if ( ( V_33 = F_15 ( V_1 -> V_34 , V_27 , 2 ) ) == 2 )
return true ;
F_16 ( L_1 , V_33 ) ;
return false ;
}
static void F_17 ( struct V_1 * V_1 , T_2 V_35 ,
const void * args , int V_36 )
{
int V_18 , V_37 = 0 ;
#define F_18 256
char V_38 [ F_18 ] ;
#define F_19 ( args ... ) \
pos += snprintf(buffer + pos, max_t(int, BUF_LEN - pos, 0), args)
for ( V_18 = 0 ; V_18 < V_36 ; V_18 ++ ) {
F_19 ( L_2 , ( ( T_2 * ) args ) [ V_18 ] ) ;
}
for (; V_18 < 8 ; V_18 ++ ) {
F_19 ( L_3 ) ;
}
for ( V_18 = 0 ; V_18 < F_20 ( V_39 ) ; V_18 ++ ) {
if ( V_35 == V_39 [ V_18 ] . V_35 ) {
F_19 ( L_4 , V_39 [ V_18 ] . V_40 ) ;
break;
}
}
if ( V_18 == F_20 ( V_39 ) ) {
F_19 ( L_5 , V_35 ) ;
}
F_21 ( V_37 >= F_18 - 1 ) ;
#undef F_19
#undef F_18
F_16 ( L_6 , F_22 ( V_1 ) , V_35 , V_38 ) ;
}
static bool F_23 ( struct V_1 * V_1 , T_2 V_35 ,
const void * args , int V_36 ,
bool V_41 )
{
T_2 * V_31 , V_42 ;
struct V_26 * V_27 ;
int V_18 , V_33 = true ;
V_31 = F_24 ( V_36 * 2 + 2 , V_43 ) ;
if ( ! V_31 )
return false ;
V_27 = F_25 ( V_36 + 3 , sizeof( * V_27 ) , V_43 ) ;
if ( ! V_27 ) {
F_26 ( V_31 ) ;
return false ;
}
F_17 ( V_1 , V_35 , args , V_36 ) ;
for ( V_18 = 0 ; V_18 < V_36 ; V_18 ++ ) {
V_27 [ V_18 ] . V_24 = V_1 -> V_28 ;
V_27 [ V_18 ] . V_29 = 0 ;
V_27 [ V_18 ] . V_30 = 2 ;
V_27 [ V_18 ] . V_31 = V_31 + 2 * V_18 ;
V_31 [ 2 * V_18 + 0 ] = V_44 - V_18 ;
V_31 [ 2 * V_18 + 1 ] = ( ( T_2 * ) args ) [ V_18 ] ;
}
V_27 [ V_18 ] . V_24 = V_1 -> V_28 ;
V_27 [ V_18 ] . V_29 = 0 ;
V_27 [ V_18 ] . V_30 = 2 ;
V_27 [ V_18 ] . V_31 = V_31 + 2 * V_18 ;
V_31 [ 2 * V_18 + 0 ] = V_45 ;
V_31 [ 2 * V_18 + 1 ] = V_35 ;
V_42 = V_46 ;
V_27 [ V_18 + 1 ] . V_24 = V_1 -> V_28 ;
V_27 [ V_18 + 1 ] . V_29 = 0 ;
V_27 [ V_18 + 1 ] . V_30 = 1 ;
V_27 [ V_18 + 1 ] . V_31 = & V_42 ;
V_27 [ V_18 + 2 ] . V_24 = V_1 -> V_28 ;
V_27 [ V_18 + 2 ] . V_29 = V_32 ;
V_27 [ V_18 + 2 ] . V_30 = 1 ;
V_27 [ V_18 + 2 ] . V_31 = & V_42 ;
if ( V_41 )
V_33 = F_15 ( V_1 -> V_34 , V_27 , V_18 + 3 ) ;
else
V_33 = F_27 ( V_1 -> V_34 , V_27 , V_18 + 3 ) ;
if ( V_33 < 0 ) {
F_16 ( L_7 , V_33 ) ;
V_33 = false ;
goto V_47;
}
if ( V_33 != V_18 + 3 ) {
F_16 ( L_8 , V_33 , V_18 + 3 ) ;
V_33 = false ;
}
V_47:
F_26 ( V_27 ) ;
F_26 ( V_31 ) ;
return V_33 ;
}
static bool F_28 ( struct V_1 * V_1 , T_2 V_35 ,
const void * args , int V_36 )
{
return F_23 ( V_1 , V_35 , args , V_36 , true ) ;
}
static bool F_29 ( struct V_1 * V_1 ,
void * V_48 , int V_49 )
{
T_2 V_50 = 15 ;
T_2 V_42 ;
int V_18 , V_37 = 0 ;
#define F_18 256
char V_38 [ F_18 ] ;
if ( ! F_14 ( V_1 ,
V_46 ,
& V_42 ) )
goto V_51;
while ( ( V_42 == V_52 ||
V_42 == V_53 ) && -- V_50 ) {
if ( V_50 < 10 )
F_30 ( 15 ) ;
else
F_31 ( 15 ) ;
if ( ! F_14 ( V_1 ,
V_46 ,
& V_42 ) )
goto V_51;
}
#define F_19 ( args ... ) \
pos += snprintf(buffer + pos, max_t(int, BUF_LEN - pos, 0), args)
if ( V_42 <= V_54 )
F_19 ( L_4 , V_55 [ V_42 ] ) ;
else
F_19 ( L_9 , V_42 ) ;
if ( V_42 != V_56 )
goto V_51;
for ( V_18 = 0 ; V_18 < V_49 ; V_18 ++ ) {
if ( ! F_14 ( V_1 ,
V_57 + V_18 ,
& ( ( T_2 * ) V_48 ) [ V_18 ] ) )
goto V_51;
F_19 ( L_10 , ( ( T_2 * ) V_48 ) [ V_18 ] ) ;
}
F_21 ( V_37 >= F_18 - 1 ) ;
#undef F_19
#undef F_18
F_16 ( L_11 , F_22 ( V_1 ) , V_38 ) ;
return true ;
V_51:
F_16 ( L_12 , F_22 ( V_1 ) ) ;
return false ;
}
static int F_32 ( const struct V_58 * V_59 )
{
if ( V_59 -> V_60 >= 100000 )
return 1 ;
else if ( V_59 -> V_60 >= 50000 )
return 2 ;
else
return 4 ;
}
static bool F_33 ( struct V_1 * V_1 ,
T_2 V_61 )
{
return F_23 ( V_1 ,
V_62 ,
& V_61 , 1 , false ) ;
}
static bool F_34 ( struct V_1 * V_1 , T_2 V_35 , const void * V_63 , int V_30 )
{
if ( ! F_28 ( V_1 , V_35 , V_63 , V_30 ) )
return false ;
return F_29 ( V_1 , NULL , 0 ) ;
}
static bool
F_35 ( struct V_1 * V_1 , T_2 V_35 , void * V_64 , int V_30 )
{
if ( ! F_28 ( V_1 , V_35 , NULL , 0 ) )
return false ;
return F_29 ( V_1 , V_64 , V_30 ) ;
}
static bool F_36 ( struct V_1 * V_1 )
{
struct V_65 V_66 = { 0 } ;
return F_34 ( V_1 ,
V_67 ,
& V_66 , sizeof( V_66 ) ) ;
}
static bool F_37 ( struct V_1 * V_1 , bool * V_68 , bool * V_69 )
{
struct V_70 V_48 ;
F_38 ( sizeof( V_48 ) != 1 ) ;
if ( ! F_35 ( V_1 , V_71 ,
& V_48 , sizeof( V_48 ) ) )
return false ;
* V_68 = V_48 . V_72 ;
* V_69 = V_48 . V_73 ;
return true ;
}
static bool F_39 ( struct V_1 * V_1 ,
T_3 V_74 )
{
return F_34 ( V_1 ,
V_75 ,
& V_74 , sizeof( V_74 ) ) ;
}
static bool F_40 ( struct V_1 * V_1 ,
T_3 * V_74 )
{
return F_35 ( V_1 ,
V_76 ,
V_74 , sizeof( * V_74 ) ) ;
}
static bool F_41 ( struct V_1 * V_1 ,
int V_77 )
{
T_2 V_78 = V_79 ;
switch ( V_77 ) {
case V_80 :
V_78 = V_79 ;
break;
case V_81 :
V_78 = V_82 ;
break;
case V_83 :
V_78 = V_84 ;
break;
case V_85 :
V_78 = V_86 ;
break;
}
return F_34 ( V_1 ,
V_87 , & V_78 , sizeof( V_78 ) ) ;
}
static bool F_42 ( struct V_1 * V_1 ,
int * V_88 ,
int * V_89 )
{
struct V_90 V_91 ;
F_38 ( sizeof( V_91 ) != 4 ) ;
if ( ! F_35 ( V_1 ,
V_92 ,
& V_91 , sizeof( V_91 ) ) )
return false ;
* V_88 = V_91 . V_93 * 10 ;
* V_89 = V_91 . V_94 * 10 ;
return true ;
}
static bool F_43 ( struct V_1 * V_1 ,
T_3 V_74 )
{
return F_34 ( V_1 ,
V_95 ,
& V_74 , sizeof( V_74 ) ) ;
}
static bool F_44 ( struct V_1 * V_1 , T_2 V_35 ,
struct V_96 * V_97 )
{
return F_34 ( V_1 , V_35 , & V_97 -> V_98 , sizeof( V_97 -> V_98 ) ) &&
F_34 ( V_1 , V_35 + 1 , & V_97 -> V_99 , sizeof( V_97 -> V_99 ) ) ;
}
static bool F_45 ( struct V_1 * V_1 , T_2 V_35 ,
struct V_96 * V_97 )
{
return F_35 ( V_1 , V_35 , & V_97 -> V_98 , sizeof( V_97 -> V_98 ) ) &&
F_35 ( V_1 , V_35 + 1 , & V_97 -> V_99 , sizeof( V_97 -> V_99 ) ) ;
}
static bool F_46 ( struct V_1 * V_1 ,
struct V_96 * V_97 )
{
return F_44 ( V_1 ,
V_100 , V_97 ) ;
}
static bool F_47 ( struct V_1 * V_1 ,
struct V_96 * V_97 )
{
return F_44 ( V_1 ,
V_101 , V_97 ) ;
}
static bool F_48 ( struct V_1 * V_1 ,
struct V_96 * V_97 )
{
return F_45 ( V_1 ,
V_102 , V_97 ) ;
}
static bool
F_49 ( struct V_1 * V_1 ,
T_4 clock ,
T_4 V_103 ,
T_4 V_104 )
{
struct V_105 args ;
memset ( & args , 0 , sizeof( args ) ) ;
args . clock = clock ;
args . V_103 = V_103 ;
args . V_104 = V_104 ;
args . V_106 = 0 ;
if ( V_1 -> V_107 &&
( V_1 -> V_108 -> V_109 != V_103 ||
V_1 -> V_108 -> V_110 != V_104 ) )
args . V_111 = 1 ;
return F_34 ( V_1 ,
V_112 ,
& args , sizeof( args ) ) ;
}
static bool F_50 ( struct V_1 * V_1 ,
struct V_96 * V_97 )
{
F_38 ( sizeof( V_97 -> V_98 ) != 8 ) ;
F_38 ( sizeof( V_97 -> V_99 ) != 8 ) ;
return F_35 ( V_1 , V_113 ,
& V_97 -> V_98 , sizeof( V_97 -> V_98 ) ) &&
F_35 ( V_1 , V_114 ,
& V_97 -> V_99 , sizeof( V_97 -> V_99 ) ) ;
}
static bool F_51 ( struct V_1 * V_1 , T_2 V_11 )
{
return F_34 ( V_1 , V_115 , & V_11 , 1 ) ;
}
static void F_52 ( struct V_96 * V_97 ,
const struct V_58 * V_77 )
{
T_4 V_103 , V_104 ;
T_4 V_116 , V_117 , V_118 , V_119 ;
T_4 V_120 , V_121 ;
int V_122 ;
memset ( V_97 , 0 , sizeof( * V_97 ) ) ;
V_103 = V_77 -> V_109 ;
V_104 = V_77 -> V_110 ;
V_116 = V_77 -> V_123 - V_77 -> V_109 ;
V_117 = V_77 -> V_124 - V_77 -> V_125 ;
V_118 = V_77 -> V_126 - V_77 -> V_110 ;
V_119 = V_77 -> V_127 - V_77 -> V_128 ;
V_120 = V_77 -> V_125 - V_77 -> V_109 ;
V_121 = V_77 -> V_128 - V_77 -> V_110 ;
V_122 = V_77 -> clock ;
V_122 /= 10 ;
V_97 -> V_98 . clock = V_122 ;
V_97 -> V_98 . V_129 = V_103 & 0xff ;
V_97 -> V_98 . V_130 = V_116 & 0xff ;
V_97 -> V_98 . V_131 = ( ( ( V_103 >> 8 ) & 0xf ) << 4 ) |
( ( V_116 >> 8 ) & 0xf ) ;
V_97 -> V_98 . V_132 = V_104 & 0xff ;
V_97 -> V_98 . V_133 = V_118 & 0xff ;
V_97 -> V_98 . V_134 = ( ( ( V_104 >> 8 ) & 0xf ) << 4 ) |
( ( V_118 >> 8 ) & 0xf ) ;
V_97 -> V_99 . V_135 = V_120 & 0xff ;
V_97 -> V_99 . V_136 = V_117 & 0xff ;
V_97 -> V_99 . V_137 = ( V_121 & 0xf ) << 4 |
( V_119 & 0xf ) ;
V_97 -> V_99 . V_138 = ( ( V_120 & 0x300 ) >> 2 ) |
( ( V_117 & 0x300 ) >> 4 ) | ( ( V_121 & 0x30 ) >> 2 ) |
( ( V_119 & 0x30 ) >> 4 ) ;
V_97 -> V_99 . V_139 = 0x18 ;
if ( V_77 -> V_29 & V_140 )
V_97 -> V_99 . V_139 |= V_141 ;
if ( V_77 -> V_29 & V_142 )
V_97 -> V_99 . V_139 |= V_143 ;
if ( V_77 -> V_29 & V_144 )
V_97 -> V_99 . V_139 |= V_145 ;
V_97 -> V_99 . V_146 = V_121 & 0xc0 ;
}
static void F_53 ( struct V_58 * V_147 ,
const struct V_96 * V_97 )
{
struct V_58 V_77 = {} ;
V_77 . V_109 = V_97 -> V_98 . V_129 ;
V_77 . V_109 += ( ( V_97 -> V_98 . V_131 >> 4 ) & 0x0f ) << 8 ;
V_77 . V_125 = V_77 . V_109 + V_97 -> V_99 . V_135 ;
V_77 . V_125 += ( V_97 -> V_99 . V_138 & 0xc0 ) << 2 ;
V_77 . V_124 = V_77 . V_125 + V_97 -> V_99 . V_136 ;
V_77 . V_124 += ( V_97 -> V_99 . V_138 & 0x30 ) << 4 ;
V_77 . V_123 = V_77 . V_109 + V_97 -> V_98 . V_130 ;
V_77 . V_123 += ( V_97 -> V_98 . V_131 & 0xf ) << 8 ;
V_77 . V_110 = V_97 -> V_98 . V_132 ;
V_77 . V_110 += ( ( V_97 -> V_98 . V_134 >> 4 ) & 0x0f ) << 8 ;
V_77 . V_128 = V_77 . V_110 ;
V_77 . V_128 += ( V_97 -> V_99 . V_137 >> 4 ) & 0xf ;
V_77 . V_128 += ( V_97 -> V_99 . V_138 & 0x0c ) << 2 ;
V_77 . V_128 += V_97 -> V_99 . V_146 & 0xc0 ;
V_77 . V_127 = V_77 . V_128 +
( V_97 -> V_99 . V_137 & 0xf ) ;
V_77 . V_127 += ( V_97 -> V_99 . V_138 & 0x3 ) << 4 ;
V_77 . V_126 = V_77 . V_110 + V_97 -> V_98 . V_133 ;
V_77 . V_126 += ( V_97 -> V_98 . V_134 & 0xf ) << 8 ;
V_77 . clock = V_97 -> V_98 . clock * 10 ;
if ( V_97 -> V_99 . V_139 & V_141 )
V_77 . V_29 |= V_140 ;
if ( V_97 -> V_99 . V_139 & V_143 )
V_77 . V_29 |= V_142 ;
else
V_77 . V_29 |= V_148 ;
if ( V_97 -> V_99 . V_139 & V_145 )
V_77 . V_29 |= V_144 ;
else
V_77 . V_29 |= V_149 ;
F_54 ( & V_77 , 0 ) ;
F_55 ( V_147 , & V_77 ) ;
}
static bool F_56 ( struct V_1 * V_1 )
{
struct V_150 V_151 ;
F_38 ( sizeof( V_151 ) != 2 ) ;
return F_35 ( V_1 ,
V_152 ,
& V_151 , sizeof( V_151 ) ) ;
}
static bool F_57 ( struct V_1 * V_1 ,
T_5 V_77 )
{
return F_34 ( V_1 , V_153 , & V_77 , 1 ) ;
}
static bool F_58 ( struct V_1 * V_1 ,
T_5 V_77 )
{
return F_34 ( V_1 , V_154 , & V_77 , 1 ) ;
}
static bool F_59 ( struct V_1 * V_1 ,
unsigned V_155 , T_5 V_156 ,
const T_5 * V_63 , unsigned V_157 )
{
T_5 V_158 [ 2 ] = { V_155 , 0 } ;
T_5 V_159 , V_160 [ 8 ] ;
int V_18 ;
if ( ! F_34 ( V_1 ,
V_161 ,
V_158 , 2 ) )
return false ;
if ( ! F_35 ( V_1 , V_162 ,
& V_159 , 1 ) )
return false ;
V_159 ++ ;
F_16 ( L_13 ,
V_155 , V_157 , V_159 ) ;
for ( V_18 = 0 ; V_18 < V_159 ; V_18 += 8 ) {
memset ( V_160 , 0 , 8 ) ;
if ( V_18 < V_157 )
memcpy ( V_160 , V_63 + V_18 , F_60 ( unsigned , 8 , V_157 - V_18 ) ) ;
if ( ! F_34 ( V_1 ,
V_163 ,
V_160 , 8 ) )
return false ;
}
return F_34 ( V_1 ,
V_164 ,
& V_156 , 1 ) ;
}
static bool F_61 ( struct V_1 * V_1 ,
struct V_165 * V_166 )
{
T_5 V_167 [ F_62 ( V_168 ) ] ;
union V_169 V_170 ;
int V_33 ;
T_6 V_30 ;
V_33 = F_63 ( & V_170 . V_171 ,
& V_166 -> V_4 . V_59 ,
false ) ;
if ( V_33 < 0 ) {
F_64 ( L_14 ) ;
return false ;
}
if ( V_1 -> V_172 ) {
if ( V_166 -> V_173 )
V_170 . V_171 . V_174 =
V_175 ;
else
V_170 . V_171 . V_174 =
V_176 ;
}
V_30 = F_65 ( & V_170 , V_167 , sizeof( V_167 ) ) ;
if ( V_30 < 0 )
return false ;
return F_59 ( V_1 , V_177 ,
V_178 ,
V_167 , sizeof( V_167 ) ) ;
}
static bool F_66 ( struct V_1 * V_1 ,
struct V_9 * V_10 )
{
struct V_179 V_180 ;
T_7 V_181 ;
V_181 = 1 << V_10 -> V_182 . V_77 ;
memset ( & V_180 , 0 , sizeof( V_180 ) ) ;
memcpy ( & V_180 , & V_181 , V_93 ( sizeof( V_180 ) , sizeof( V_181 ) ) ) ;
F_38 ( sizeof( V_180 ) != 6 ) ;
return F_34 ( V_1 ,
V_183 ,
& V_180 , sizeof( V_180 ) ) ;
}
static bool
F_67 ( struct V_1 * V_1 ,
const struct V_58 * V_77 )
{
struct V_96 V_184 ;
if ( ! F_43 ( V_1 ,
V_1 -> V_185 ) )
return false ;
F_52 ( & V_184 , V_77 ) ;
if ( ! F_47 ( V_1 , & V_184 ) )
return false ;
return true ;
}
static bool
F_68 ( struct V_1 * V_1 ,
const struct V_58 * V_77 ,
struct V_58 * V_59 )
{
struct V_96 V_186 ;
if ( ! F_36 ( V_1 ) )
return false ;
if ( ! F_49 ( V_1 ,
V_77 -> clock / 10 ,
V_77 -> V_109 ,
V_77 -> V_110 ) )
return false ;
if ( ! F_50 ( V_1 ,
& V_186 ) )
return false ;
F_53 ( V_59 , & V_186 ) ;
V_1 -> V_187 = V_186 . V_99 . V_188 ;
return true ;
}
static void F_69 ( struct V_165 * V_166 )
{
unsigned V_189 = V_166 -> V_190 ;
struct V_191 * clock = & V_166 -> V_191 ;
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
F_70 ( 1 , L_15 , V_189 ) ;
}
V_166 -> V_197 = true ;
}
static bool F_71 ( struct V_2 * V_3 ,
struct V_165 * V_166 ,
struct V_9 * V_10 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_8 * V_198 =
F_6 ( V_10 ) ;
struct V_58 * V_59 = & V_166 -> V_4 . V_59 ;
struct V_58 * V_77 = & V_166 -> V_4 . V_77 ;
F_16 ( L_16 ) ;
V_166 -> V_199 = 8 * 3 ;
if ( F_9 ( F_8 ( V_3 -> V_4 . V_13 ) ) )
V_166 -> V_200 = true ;
if ( V_1 -> V_201 ) {
if ( ! F_67 ( V_1 , V_77 ) )
return false ;
( void ) F_68 ( V_1 ,
V_77 ,
V_59 ) ;
V_166 -> V_202 = true ;
} else if ( V_1 -> V_107 ) {
if ( ! F_67 ( V_1 ,
V_1 -> V_108 ) )
return false ;
( void ) F_68 ( V_1 ,
V_77 ,
V_59 ) ;
}
V_166 -> V_203 =
F_32 ( V_59 ) ;
if ( V_198 -> V_4 . V_204 != V_205 )
V_166 -> V_206 = V_1 -> V_207 ;
if ( V_198 -> V_4 . V_204 == V_208 ||
( V_198 -> V_4 . V_204 == V_209 && V_1 -> V_210 ) )
V_166 -> V_211 = true ;
if ( V_198 -> V_4 . V_212 == V_213 ) {
if ( V_166 -> V_206 &&
F_72 ( V_59 ) > 1 )
V_166 -> V_173 = true ;
} else {
if ( V_166 -> V_206 &&
V_198 -> V_4 . V_212 == V_214 )
V_166 -> V_173 = true ;
}
if ( V_1 -> V_201 )
F_69 ( V_166 ) ;
if ( V_1 -> V_215 )
V_59 -> V_216 = V_10 -> V_216 ;
return true ;
}
static void F_73 ( struct V_1 * V_1 ,
struct V_8 * V_217 )
{
struct V_9 * V_10 = & V_217 -> V_4 . V_4 ;
struct V_7 * V_218 =
F_5 ( V_10 -> V_6 ) ;
T_4 V_11 ;
if ( V_218 -> V_219 )
F_74 ( V_217 -> V_182 . V_220 , V_221 ) ;
if ( V_218 -> V_222 )
F_74 ( V_217 -> V_182 . V_223 , V_224 ) ;
if ( V_218 -> V_225 )
F_74 ( V_217 -> V_182 . V_225 , V_226 ) ;
if ( V_218 -> V_227 )
F_74 ( V_217 -> V_182 . V_227 , V_228 ) ;
if ( V_218 -> V_229 )
F_74 ( V_10 -> V_182 . V_229 , V_230 ) ;
if ( V_218 -> V_231 )
F_74 ( V_10 -> V_182 . V_231 , V_232 ) ;
if ( V_218 -> V_233 )
F_74 ( V_10 -> V_182 . V_233 , V_234 ) ;
if ( V_218 -> V_235 )
F_74 ( V_10 -> V_182 . V_235 , V_236 ) ;
if ( V_218 -> V_237 )
F_74 ( V_217 -> V_182 . V_237 , V_238 ) ;
if ( V_218 -> V_239 )
F_74 ( V_217 -> V_182 . V_239 , V_240 ) ;
if ( V_218 -> V_241 )
F_74 ( V_217 -> V_182 . V_241 , V_242 ) ;
if ( V_218 -> V_243 )
F_74 ( V_217 -> V_182 . V_243 , V_244 ) ;
if ( V_218 -> V_245 )
F_74 ( V_217 -> V_182 . V_246 , V_247 ) ;
if ( V_218 -> V_248 )
F_74 ( V_217 -> V_182 . V_249 , V_250 ) ;
if ( V_218 -> V_251 )
F_74 ( V_217 -> V_182 . V_251 , V_252 ) ;
#undef F_74
}
static void F_75 ( struct V_2 * V_2 ,
struct V_165 * V_253 ,
struct V_9 * V_10 )
{
struct V_14 * V_15 = F_8 ( V_2 -> V_4 . V_13 ) ;
struct V_254 * V_255 = F_76 ( V_253 -> V_4 . V_255 ) ;
const struct V_58 * V_59 = & V_253 -> V_4 . V_59 ;
struct V_8 * V_217 = F_6 ( V_10 ) ;
struct V_58 * V_77 = & V_253 -> V_4 . V_77 ;
struct V_1 * V_1 = F_1 ( V_2 ) ;
T_1 V_256 ;
struct V_257 V_258 ;
struct V_96 V_186 , V_184 ;
int V_259 ;
F_73 ( V_1 , V_217 ) ;
V_258 . V_260 = V_1 -> V_185 ;
V_258 . V_261 = 0 ;
F_34 ( V_1 ,
V_262 ,
& V_258 , sizeof( V_258 ) ) ;
if ( ! F_43 ( V_1 ,
V_1 -> V_185 ) )
return;
if ( V_1 -> V_107 )
F_52 ( & V_184 ,
V_1 -> V_108 ) ;
else
F_52 ( & V_184 , V_77 ) ;
if ( ! F_47 ( V_1 , & V_184 ) )
F_77 ( L_17 ,
F_22 ( V_1 ) ) ;
if ( ! F_36 ( V_1 ) )
return;
if ( V_253 -> V_206 ) {
F_57 ( V_1 , V_263 ) ;
F_58 ( V_1 ,
V_264 ) ;
F_61 ( V_1 , V_253 ) ;
} else
F_57 ( V_1 , V_265 ) ;
if ( V_1 -> V_201 &&
! F_66 ( V_1 , V_10 ) )
return;
F_52 ( & V_186 , V_59 ) ;
if ( V_1 -> V_201 || V_1 -> V_107 )
V_186 . V_99 . V_188 = V_1 -> V_187 ;
if ( ! F_46 ( V_1 , & V_186 ) )
F_77 ( L_18 ,
F_22 ( V_1 ) ) ;
switch ( V_253 -> V_203 ) {
default:
F_70 ( 1 , L_19 ) ;
case 1 : V_259 = V_266 ; break;
case 2 : V_259 = V_267 ; break;
case 4 : V_259 = V_268 ; break;
}
if ( ! F_51 ( V_1 , V_259 ) )
return;
if ( F_78 ( V_15 ) >= 4 ) {
V_256 = V_269 | V_270 ;
if ( ! F_9 ( V_15 ) && V_253 -> V_173 )
V_256 |= V_271 ;
if ( F_78 ( V_15 ) < 5 )
V_256 |= V_272 ;
} else {
V_256 = F_13 ( V_1 -> V_19 ) ;
if ( V_1 -> V_20 == V_21 )
V_256 &= V_273 ;
else
V_256 &= V_274 ;
V_256 |= ( 9 << 19 ) | V_272 ;
}
if ( F_79 ( V_15 ) )
V_256 |= F_80 ( V_255 -> V_275 ) ;
else
V_256 |= F_81 ( V_255 -> V_275 ) ;
if ( V_253 -> V_211 ) {
F_82 ( F_78 ( V_15 ) < 4 ) ;
V_256 |= V_276 ;
}
if ( F_78 ( V_15 ) >= 4 ) {
} else if ( F_83 ( V_15 ) || F_84 ( V_15 ) ||
F_85 ( V_15 ) || F_86 ( V_15 ) ) {
} else {
V_256 |= ( V_253 -> V_203 - 1 )
<< V_277 ;
}
if ( V_186 . V_99 . V_188 & V_278 &&
F_78 ( V_15 ) < 5 )
V_256 |= V_279 ;
F_7 ( V_1 , V_256 ) ;
}
static bool F_87 ( struct V_280 * V_6 )
{
struct V_7 * V_7 =
F_5 ( & V_6 -> V_4 ) ;
struct V_1 * V_1 = F_3 ( & V_6 -> V_4 ) ;
T_3 V_281 = 0 ;
F_40 ( V_1 , & V_281 ) ;
if ( V_281 & V_7 -> V_282 )
return true ;
else
return false ;
}
static bool F_88 ( struct V_2 * V_3 ,
enum V_275 * V_275 )
{
struct V_12 * V_13 = V_3 -> V_4 . V_13 ;
struct V_14 * V_15 = F_8 ( V_13 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
T_3 V_281 = 0 ;
T_1 V_160 ;
V_160 = F_13 ( V_1 -> V_19 ) ;
F_40 ( V_1 , & V_281 ) ;
if ( ! ( V_160 & V_283 ) && ( V_281 == 0 ) )
return false ;
if ( F_79 ( V_15 ) )
* V_275 = F_89 ( V_160 ) ;
else
* V_275 = F_90 ( V_160 ) ;
return true ;
}
static void F_91 ( struct V_2 * V_3 ,
struct V_165 * V_166 )
{
struct V_12 * V_13 = V_3 -> V_4 . V_13 ;
struct V_14 * V_15 = F_8 ( V_13 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_96 V_97 ;
int V_284 = 0 ;
int V_189 ;
T_1 V_29 = 0 , V_256 ;
T_2 V_11 ;
bool V_33 ;
V_256 = F_13 ( V_1 -> V_19 ) ;
V_33 = F_48 ( V_1 , & V_97 ) ;
if ( ! V_33 ) {
F_92 ( L_20 ) ;
V_166 -> V_285 |= V_286 ;
} else {
if ( V_97 . V_99 . V_139 & V_143 )
V_29 |= V_142 ;
else
V_29 |= V_148 ;
if ( V_97 . V_99 . V_139 & V_145 )
V_29 |= V_144 ;
else
V_29 |= V_149 ;
}
V_166 -> V_4 . V_59 . V_29 |= V_29 ;
if ( F_93 ( V_15 ) || F_94 ( V_15 ) ) {
V_166 -> V_203 =
( ( V_256 & V_287 )
>> V_277 ) + 1 ;
}
V_189 = V_166 -> V_190 ;
if ( V_166 -> V_203 )
V_189 /= V_166 -> V_203 ;
V_166 -> V_4 . V_59 . V_60 = V_189 ;
if ( F_35 ( V_1 , V_288 ,
& V_11 , 1 ) ) {
switch ( V_11 ) {
case V_266 :
V_284 = 1 ;
break;
case V_267 :
V_284 = 2 ;
break;
case V_268 :
V_284 = 4 ;
break;
}
}
if ( V_256 & V_271 )
V_166 -> V_173 = true ;
if ( V_256 & V_276 )
V_166 -> V_211 = true ;
if ( F_35 ( V_1 , V_289 ,
& V_11 , 1 ) ) {
if ( V_11 == V_263 )
V_166 -> V_206 = true ;
}
F_70 ( V_284 != V_166 -> V_203 ,
L_21 ,
V_166 -> V_203 , V_284 ) ;
}
static void F_95 ( struct V_2 * V_3 ,
struct V_165 * V_290 ,
struct V_9 * V_10 )
{
struct V_14 * V_15 = F_8 ( V_3 -> V_4 . V_13 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_254 * V_255 = F_76 ( V_3 -> V_4 . V_255 ) ;
T_1 V_291 ;
F_39 ( V_1 , 0 ) ;
if ( 0 )
F_41 ( V_1 ,
V_85 ) ;
V_291 = F_13 ( V_1 -> V_19 ) ;
V_291 &= ~ V_283 ;
F_7 ( V_1 , V_291 ) ;
if ( F_12 ( V_15 ) && V_255 -> V_275 == V_292 ) {
F_96 ( V_15 , V_293 , false ) ;
F_97 ( V_15 , V_293 , false ) ;
V_291 &= ~ V_294 ;
V_291 |= V_283 ;
F_7 ( V_1 , V_291 ) ;
V_291 &= ~ V_283 ;
F_7 ( V_1 , V_291 ) ;
F_98 ( V_15 , V_293 ) ;
F_96 ( V_15 , V_293 , true ) ;
F_97 ( V_15 , V_293 , true ) ;
}
}
static void F_99 ( struct V_2 * V_3 ,
struct V_165 * V_290 ,
struct V_9 * V_295 )
{
}
static void F_100 ( struct V_2 * V_3 ,
struct V_165 * V_290 ,
struct V_9 * V_295 )
{
F_95 ( V_3 , V_290 , V_295 ) ;
}
static void F_101 ( struct V_2 * V_3 ,
struct V_165 * V_166 ,
struct V_9 * V_10 )
{
struct V_12 * V_13 = V_3 -> V_4 . V_13 ;
struct V_14 * V_15 = F_8 ( V_13 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_254 * V_254 = F_76 ( V_3 -> V_4 . V_255 ) ;
T_1 V_291 ;
bool V_296 , V_297 ;
int V_18 ;
bool V_298 ;
V_291 = F_13 ( V_1 -> V_19 ) ;
V_291 |= V_283 ;
F_7 ( V_1 , V_291 ) ;
for ( V_18 = 0 ; V_18 < 2 ; V_18 ++ )
F_102 ( V_15 , V_254 -> V_275 ) ;
V_298 = F_37 ( V_1 , & V_296 , & V_297 ) ;
if ( V_298 && ! V_296 ) {
F_16 ( L_22
L_23 , F_22 ( V_1 ) ) ;
}
if ( 0 )
F_41 ( V_1 ,
V_80 ) ;
F_39 ( V_1 , V_1 -> V_185 ) ;
}
static enum V_299
F_103 ( struct V_5 * V_6 ,
struct V_58 * V_77 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
int V_300 = F_8 ( V_6 -> V_13 ) -> V_301 ;
if ( V_77 -> V_29 & V_302 )
return V_303 ;
if ( V_1 -> V_304 > V_77 -> clock )
return V_305 ;
if ( V_1 -> V_306 < V_77 -> clock )
return V_307 ;
if ( V_77 -> clock > V_300 )
return V_307 ;
if ( V_1 -> V_107 ) {
if ( V_77 -> V_109 > V_1 -> V_108 -> V_109 )
return V_308 ;
if ( V_77 -> V_110 > V_1 -> V_108 -> V_110 )
return V_308 ;
}
return V_309 ;
}
static bool F_104 ( struct V_1 * V_1 , struct V_310 * V_311 )
{
F_38 ( sizeof( * V_311 ) != 8 ) ;
if ( ! F_35 ( V_1 ,
V_312 ,
V_311 , sizeof( * V_311 ) ) )
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
V_311 -> V_313 ,
V_311 -> V_314 ,
V_311 -> V_315 ,
V_311 -> V_316 ,
V_311 -> V_317 ,
V_311 -> V_318 ,
V_311 -> V_319 ,
V_311 -> V_320 ,
V_311 -> V_321 ,
V_311 -> V_322 ,
V_311 -> V_323 ,
V_311 -> V_324 ) ;
return true ;
}
static T_4 F_105 ( struct V_1 * V_1 )
{
struct V_14 * V_15 = F_8 ( V_1 -> V_4 . V_4 . V_13 ) ;
T_4 V_325 ;
if ( ! F_106 ( V_15 ) )
return 0 ;
if ( F_83 ( V_15 ) || F_84 ( V_15 ) )
return 0 ;
if ( ! F_35 ( V_1 , V_326 ,
& V_325 , sizeof( V_325 ) ) )
return 0 ;
return V_325 ;
}
static void F_107 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
F_28 ( V_1 , V_327 ,
& V_1 -> V_328 , 2 ) ;
}
static bool
F_108 ( struct V_1 * V_1 )
{
return F_109 ( V_1 -> V_311 . V_324 ) > 1 ;
}
static struct V_329 *
F_110 ( struct V_5 * V_6 )
{
struct V_1 * V_330 = F_3 ( V_6 ) ;
return F_111 ( V_6 , & V_330 -> V_331 ) ;
}
static struct V_329 *
F_112 ( struct V_5 * V_6 )
{
struct V_14 * V_15 = F_8 ( V_6 -> V_13 ) ;
return F_111 ( V_6 ,
F_113 ( V_15 ,
V_15 -> V_332 . V_333 ) ) ;
}
static enum V_334
F_114 ( struct V_5 * V_6 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
enum V_334 V_42 ;
struct V_329 * V_329 ;
V_329 = F_110 ( V_6 ) ;
if ( V_329 == NULL && F_108 ( V_1 ) ) {
T_2 V_331 , V_335 = V_1 -> V_61 ;
for ( V_331 = V_1 -> V_61 >> 1 ; V_331 > 1 ; V_331 >>= 1 ) {
V_1 -> V_61 = V_331 ;
V_329 = F_110 ( V_6 ) ;
if ( V_329 )
break;
}
if ( V_329 == NULL )
V_1 -> V_61 = V_335 ;
}
if ( V_329 == NULL )
V_329 = F_112 ( V_6 ) ;
V_42 = V_336 ;
if ( V_329 != NULL ) {
if ( V_329 -> V_337 & V_338 ) {
V_42 = V_339 ;
if ( V_1 -> V_215 ) {
V_1 -> V_207 = F_115 ( V_329 ) ;
V_1 -> V_210 = F_116 ( V_329 ) ;
V_1 -> V_172 =
F_117 ( V_329 ) ;
}
} else
V_42 = V_340 ;
F_26 ( V_329 ) ;
}
return V_42 ;
}
static bool
F_118 ( struct V_7 * V_330 ,
struct V_329 * V_329 )
{
bool V_341 = ! ! ( V_329 -> V_337 & V_338 ) ;
bool V_342 = ! ! F_119 ( V_330 ) ;
F_16 ( L_37 ,
V_342 , V_341 ) ;
return V_342 == V_341 ;
}
static enum V_334
F_120 ( struct V_5 * V_6 , bool V_343 )
{
T_4 V_48 ;
struct V_1 * V_1 = F_3 ( V_6 ) ;
struct V_7 * V_7 = F_5 ( V_6 ) ;
enum V_334 V_33 ;
F_16 ( L_38 ,
V_6 -> V_4 . V_344 , V_6 -> V_40 ) ;
if ( ! F_35 ( V_1 ,
V_345 ,
& V_48 , 2 ) )
return V_336 ;
F_16 ( L_39 ,
V_48 & 0xff , V_48 >> 8 ,
V_7 -> V_282 ) ;
if ( V_48 == 0 )
return V_340 ;
V_1 -> V_185 = V_48 ;
V_1 -> V_207 = false ;
V_1 -> V_210 = false ;
V_1 -> V_172 = false ;
if ( ( V_7 -> V_282 & V_48 ) == 0 )
V_33 = V_340 ;
else if ( F_121 ( V_7 ) )
V_33 = F_114 ( V_6 ) ;
else {
struct V_329 * V_329 ;
V_329 = F_110 ( V_6 ) ;
if ( V_329 == NULL )
V_329 = F_112 ( V_6 ) ;
if ( V_329 != NULL ) {
if ( F_118 ( V_7 ,
V_329 ) )
V_33 = V_339 ;
else
V_33 = V_340 ;
F_26 ( V_329 ) ;
} else
V_33 = V_339 ;
}
if ( V_33 == V_339 ) {
V_1 -> V_201 = false ;
V_1 -> V_107 = false ;
if ( V_48 & V_346 )
V_1 -> V_201 = true ;
if ( V_48 & V_347 )
V_1 -> V_107 = V_1 -> V_108 != NULL ;
}
return V_33 ;
}
static void F_122 ( struct V_5 * V_6 )
{
struct V_329 * V_329 ;
F_16 ( L_38 ,
V_6 -> V_4 . V_344 , V_6 -> V_40 ) ;
V_329 = F_110 ( V_6 ) ;
if ( V_329 == NULL )
V_329 = F_112 ( V_6 ) ;
if ( V_329 != NULL ) {
if ( F_118 ( F_5 ( V_6 ) ,
V_329 ) ) {
F_123 ( V_6 , V_329 ) ;
F_124 ( V_6 , V_329 ) ;
}
F_26 ( V_329 ) ;
}
}
static void F_125 ( struct V_5 * V_6 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
const struct V_9 * V_10 = V_6 -> V_78 ;
struct V_348 V_349 ;
T_7 V_350 = 0 , V_181 = 0 ;
int V_18 ;
F_16 ( L_38 ,
V_6 -> V_4 . V_344 , V_6 -> V_40 ) ;
V_181 = 1 << V_10 -> V_182 . V_77 ;
memcpy ( & V_349 , & V_181 ,
V_93 ( sizeof( V_181 ) , sizeof( struct V_348 ) ) ) ;
if ( ! F_43 ( V_1 , V_1 -> V_185 ) )
return;
F_38 ( sizeof( V_349 ) != 3 ) ;
if ( ! F_28 ( V_1 ,
V_351 ,
& V_349 , sizeof( V_349 ) ) )
return;
if ( ! F_29 ( V_1 , & V_350 , 3 ) )
return;
for ( V_18 = 0 ; V_18 < F_20 ( V_352 ) ; V_18 ++ )
if ( V_350 & ( 1 << V_18 ) ) {
struct V_58 * V_353 ;
V_353 = F_126 ( V_6 -> V_13 ,
& V_352 [ V_18 ] ) ;
if ( V_353 )
F_127 ( V_6 , V_353 ) ;
}
}
static void F_128 ( struct V_5 * V_6 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
struct V_14 * V_15 = F_8 ( V_6 -> V_13 ) ;
struct V_58 * V_354 ;
F_16 ( L_38 ,
V_6 -> V_4 . V_344 , V_6 -> V_40 ) ;
if ( V_15 -> V_332 . V_355 != NULL ) {
V_354 = F_126 ( V_6 -> V_13 ,
V_15 -> V_332 . V_355 ) ;
if ( V_354 != NULL ) {
V_354 -> type = ( V_356 |
V_357 ) ;
F_127 ( V_6 , V_354 ) ;
}
}
F_129 ( V_6 , & V_1 -> V_331 ) ;
F_130 (newmode, &connector->probed_modes, head) {
if ( V_354 -> type & V_356 ) {
V_1 -> V_108 =
F_126 ( V_6 -> V_13 , V_354 ) ;
V_1 -> V_107 = true ;
break;
}
}
}
static int F_131 ( struct V_5 * V_6 )
{
struct V_7 * V_7 = F_5 ( V_6 ) ;
if ( F_132 ( V_7 ) )
F_125 ( V_6 ) ;
else if ( F_133 ( V_7 ) )
F_128 ( V_6 ) ;
else
F_122 ( V_6 ) ;
return ! F_134 ( & V_6 -> V_358 ) ;
}
static void F_135 ( struct V_5 * V_6 )
{
struct V_7 * V_7 = F_5 ( V_6 ) ;
F_136 ( V_6 ) ;
F_26 ( V_7 ) ;
}
static int
F_137 ( struct V_5 * V_6 ,
const struct V_9 * V_78 ,
struct V_359 * V_360 ,
T_8 * V_11 )
{
struct V_7 * V_7 = F_5 ( V_6 ) ;
const struct V_8 * V_217 = F_6 ( ( void * ) V_78 ) ;
if ( V_360 == V_7 -> V_361 ) {
int V_18 ;
for ( V_18 = 0 ; V_18 < V_7 -> V_362 ; V_18 ++ )
if ( V_78 -> V_182 . V_77 == V_7 -> V_363 [ V_18 ] ) {
* V_11 = V_18 ;
return 0 ;
}
F_138 ( 1 ) ;
* V_11 = 0 ;
} else if ( V_360 == V_7 -> V_222 ||
V_360 == V_7 -> V_364 )
* V_11 = V_7 -> V_365 - V_217 -> V_182 . V_223 ;
else if ( V_360 == V_7 -> V_219 ||
V_360 == V_7 -> V_366 )
* V_11 = V_7 -> V_367 - V_217 -> V_182 . V_220 ;
else if ( V_360 == V_7 -> V_225 )
* V_11 = V_217 -> V_182 . V_225 ;
else if ( V_360 == V_7 -> V_227 )
* V_11 = V_217 -> V_182 . V_227 ;
else if ( V_360 == V_7 -> V_229 )
* V_11 = V_78 -> V_182 . V_229 ;
else if ( V_360 == V_7 -> V_231 )
* V_11 = V_78 -> V_182 . V_231 ;
else if ( V_360 == V_7 -> V_233 )
* V_11 = V_78 -> V_182 . V_233 ;
else if ( V_360 == V_7 -> V_235 )
* V_11 = V_78 -> V_182 . V_235 ;
else if ( V_360 == V_7 -> V_237 )
* V_11 = V_217 -> V_182 . V_237 ;
else if ( V_360 == V_7 -> V_239 )
* V_11 = V_217 -> V_182 . V_239 ;
else if ( V_360 == V_7 -> V_241 )
* V_11 = V_217 -> V_182 . V_241 ;
else if ( V_360 == V_7 -> V_243 )
* V_11 = V_217 -> V_182 . V_243 ;
else if ( V_360 == V_7 -> V_245 )
* V_11 = V_217 -> V_182 . V_246 ;
else if ( V_360 == V_7 -> V_248 )
* V_11 = V_217 -> V_182 . V_249 ;
else if ( V_360 == V_7 -> V_251 )
* V_11 = V_217 -> V_182 . V_251 ;
else
return F_139 ( V_6 , V_78 , V_360 , V_11 ) ;
return 0 ;
}
static int
F_140 ( struct V_5 * V_6 ,
struct V_9 * V_78 ,
struct V_359 * V_360 ,
T_8 V_11 )
{
struct V_7 * V_7 = F_5 ( V_6 ) ;
struct V_8 * V_217 = F_6 ( V_78 ) ;
if ( V_360 == V_7 -> V_361 ) {
V_78 -> V_182 . V_77 = V_7 -> V_363 [ V_11 ] ;
if ( V_78 -> V_255 ) {
struct V_368 * V_253 =
F_141 ( V_78 -> V_78 , V_78 -> V_255 ) ;
V_253 -> V_369 = true ;
}
} else if ( V_360 == V_7 -> V_222 ||
V_360 == V_7 -> V_364 )
V_217 -> V_182 . V_223 = V_7 -> V_365 - V_11 ;
else if ( V_360 == V_7 -> V_219 ||
V_360 == V_7 -> V_366 )
V_217 -> V_182 . V_220 = V_7 -> V_367 - V_11 ;
else if ( V_360 == V_7 -> V_225 )
V_217 -> V_182 . V_225 = V_11 ;
else if ( V_360 == V_7 -> V_227 )
V_217 -> V_182 . V_227 = V_11 ;
else if ( V_360 == V_7 -> V_229 )
V_78 -> V_182 . V_229 = V_11 ;
else if ( V_360 == V_7 -> V_231 )
V_78 -> V_182 . V_231 = V_11 ;
else if ( V_360 == V_7 -> V_233 )
V_78 -> V_182 . V_233 = V_11 ;
else if ( V_360 == V_7 -> V_235 )
V_78 -> V_182 . V_235 = V_11 ;
else if ( V_360 == V_7 -> V_237 )
V_217 -> V_182 . V_237 = V_11 ;
else if ( V_360 == V_7 -> V_239 )
V_217 -> V_182 . V_239 = V_11 ;
else if ( V_360 == V_7 -> V_241 )
V_217 -> V_182 . V_241 = V_11 ;
else if ( V_360 == V_7 -> V_243 )
V_217 -> V_182 . V_243 = V_11 ;
else if ( V_360 == V_7 -> V_245 )
V_217 -> V_182 . V_246 = V_11 ;
else if ( V_360 == V_7 -> V_248 )
V_217 -> V_182 . V_249 = V_11 ;
else if ( V_360 == V_7 -> V_251 )
V_217 -> V_182 . V_251 = V_11 ;
else
return F_142 ( V_6 , V_78 , V_360 , V_11 ) ;
return 0 ;
}
static int
F_143 ( struct V_5 * V_6 )
{
struct V_1 * V_330 = F_3 ( V_6 ) ;
int V_33 ;
V_33 = F_144 ( V_6 ) ;
if ( V_33 )
return V_33 ;
return F_145 ( & V_6 -> V_370 -> V_371 ,
& V_330 -> V_331 . V_13 . V_371 ,
V_330 -> V_331 . V_13 . V_371 . V_40 ) ;
}
static void
F_146 ( struct V_5 * V_6 )
{
struct V_1 * V_330 = F_3 ( V_6 ) ;
F_147 ( & V_6 -> V_370 -> V_371 ,
V_330 -> V_331 . V_13 . V_371 . V_40 ) ;
F_148 ( V_6 ) ;
}
static struct V_9 *
F_149 ( struct V_5 * V_6 )
{
struct V_8 * V_78 ;
V_78 = F_150 ( V_6 -> V_78 , sizeof( * V_78 ) , V_43 ) ;
if ( ! V_78 )
return NULL ;
F_151 ( V_6 , & V_78 -> V_4 . V_4 ) ;
return & V_78 -> V_4 . V_4 ;
}
static int F_152 ( struct V_5 * V_372 ,
struct V_9 * V_373 )
{
struct V_374 * V_78 = V_373 -> V_78 ;
struct V_9 * V_295 =
F_153 ( V_78 , V_372 ) ;
struct V_8 * V_375 =
F_6 ( V_295 ) ;
struct V_8 * V_376 =
F_6 ( V_373 ) ;
if ( V_373 -> V_255 &&
( memcmp ( & V_375 -> V_182 , & V_376 -> V_182 , sizeof( V_375 -> V_182 ) ) ||
memcmp ( & V_295 -> V_182 , & V_373 -> V_182 , sizeof( V_295 -> V_182 ) ) ) ) {
struct V_368 * V_253 =
F_141 ( V_373 -> V_78 ,
V_373 -> V_255 ) ;
V_253 -> V_369 = true ;
}
return F_154 ( V_372 , V_373 ) ;
}
static void F_155 ( struct V_377 * V_3 )
{
struct V_1 * V_1 = F_1 ( F_156 ( V_3 ) ) ;
if ( V_1 -> V_108 != NULL )
F_157 ( V_3 -> V_13 ,
V_1 -> V_108 ) ;
F_158 ( & V_1 -> V_331 ) ;
F_159 ( V_3 ) ;
}
static void
F_160 ( struct V_1 * V_330 )
{
T_4 V_378 = 0 ;
unsigned int V_379 ;
switch ( V_330 -> V_380 ) {
case V_381 :
V_378 |= V_381 ;
case V_382 :
V_378 |= V_382 ;
case V_383 :
V_378 |= V_383 ;
case V_384 :
V_378 |= V_384 ;
case V_385 :
V_378 |= V_385 ;
case V_386 :
V_378 |= V_386 ;
break;
}
V_378 &= V_330 -> V_311 . V_324 ;
V_379 = F_109 ( V_378 ) ;
if ( V_379 > 3 )
V_379 = 3 ;
V_330 -> V_61 = 1 << V_379 ;
}
static void
F_161 ( struct V_14 * V_15 ,
struct V_1 * V_330 )
{
struct V_387 * V_388 ;
if ( V_330 -> V_20 == V_21 )
V_388 = & V_15 -> V_332 . V_389 [ 0 ] ;
else
V_388 = & V_15 -> V_332 . V_389 [ 1 ] ;
if ( V_388 -> V_390 )
V_330 -> V_61 = 1 << ( ( V_388 -> V_391 & 0xf0 ) >> 4 ) ;
else
F_160 ( V_330 ) ;
}
static void
F_162 ( struct V_14 * V_15 ,
struct V_1 * V_330 )
{
struct V_387 * V_388 ;
T_2 V_392 ;
if ( V_330 -> V_20 == V_21 )
V_388 = & V_15 -> V_332 . V_389 [ 0 ] ;
else
V_388 = & V_15 -> V_332 . V_389 [ 1 ] ;
if ( V_388 -> V_390 &&
F_163 ( V_15 , V_388 -> V_393 ) )
V_392 = V_388 -> V_393 ;
else
V_392 = V_394 ;
V_330 -> V_34 = F_113 ( V_15 , V_392 ) ;
F_164 ( V_330 -> V_34 , true ) ;
}
static void
F_165 ( struct V_1 * V_330 )
{
F_164 ( V_330 -> V_34 , false ) ;
}
static bool
F_166 ( struct V_1 * V_1 , int V_395 )
{
return F_56 ( V_1 ) ;
}
static T_2
F_167 ( struct V_14 * V_15 ,
struct V_1 * V_330 )
{
struct V_387 * V_396 , * V_397 ;
if ( V_330 -> V_20 == V_21 ) {
V_396 = & V_15 -> V_332 . V_389 [ 0 ] ;
V_397 = & V_15 -> V_332 . V_389 [ 1 ] ;
} else {
V_396 = & V_15 -> V_332 . V_389 [ 1 ] ;
V_397 = & V_15 -> V_332 . V_389 [ 0 ] ;
}
if ( V_396 -> V_28 )
return V_396 -> V_28 ;
if ( V_397 -> V_28 ) {
if ( V_397 -> V_28 == 0x70 )
return 0x72 ;
else
return 0x70 ;
}
if ( V_330 -> V_20 == V_21 )
return 0x70 ;
else
return 0x72 ;
}
static int
F_168 ( struct V_7 * V_6 ,
struct V_1 * V_3 )
{
struct V_5 * V_5 ;
int V_33 ;
V_5 = & V_6 -> V_4 . V_4 ;
V_33 = F_169 ( V_3 -> V_4 . V_4 . V_13 ,
V_5 ,
& V_398 ,
V_6 -> V_4 . V_4 . V_399 ) ;
if ( V_33 < 0 )
return V_33 ;
F_170 ( V_5 ,
& V_400 ) ;
V_6 -> V_4 . V_4 . V_401 = 1 ;
V_6 -> V_4 . V_4 . V_402 = 0 ;
V_6 -> V_4 . V_4 . V_403 . V_404 = V_405 ;
V_6 -> V_4 . V_406 = F_87 ;
F_171 ( & V_6 -> V_4 , & V_3 -> V_4 ) ;
return 0 ;
}
static void
F_172 ( struct V_1 * V_1 ,
struct V_7 * V_6 )
{
struct V_14 * V_15 = F_8 ( V_6 -> V_4 . V_4 . V_13 ) ;
F_173 ( & V_6 -> V_4 . V_4 ) ;
if ( F_78 ( V_15 ) >= 4 && F_174 ( V_15 ) ) {
F_175 ( & V_6 -> V_4 . V_4 ) ;
}
F_176 ( & V_6 -> V_4 . V_4 ) ;
V_6 -> V_4 . V_4 . V_78 -> V_216 = V_407 ;
}
static struct V_7 * F_177 ( void )
{
struct V_7 * V_408 ;
struct V_8 * V_10 ;
V_408 = F_24 ( sizeof( * V_408 ) , V_43 ) ;
if ( ! V_408 )
return NULL ;
V_10 = F_24 ( sizeof( * V_10 ) , V_43 ) ;
if ( ! V_10 ) {
F_26 ( V_408 ) ;
return NULL ;
}
F_178 ( & V_408 -> V_4 . V_4 ,
& V_10 -> V_4 . V_4 ) ;
return V_408 ;
}
static bool
F_179 ( struct V_1 * V_1 , int V_395 )
{
struct V_377 * V_3 = & V_1 -> V_4 . V_4 ;
struct V_14 * V_15 = F_8 ( V_3 -> V_13 ) ;
struct V_5 * V_6 ;
struct V_2 * V_2 = F_156 ( V_3 ) ;
struct V_280 * V_280 ;
struct V_7 * V_7 ;
F_16 ( L_40 , V_395 ) ;
V_7 = F_177 () ;
if ( ! V_7 )
return false ;
if ( V_395 == 0 ) {
V_1 -> V_380 |= V_384 ;
V_7 -> V_282 = V_384 ;
} else if ( V_395 == 1 ) {
V_1 -> V_380 |= V_383 ;
V_7 -> V_282 = V_383 ;
}
V_280 = & V_7 -> V_4 ;
V_6 = & V_280 -> V_4 ;
if ( F_105 ( V_1 ) &
V_7 -> V_282 ) {
V_1 -> V_328 |= V_7 -> V_282 ;
V_2 -> V_409 = F_107 ;
F_107 ( V_2 ) ;
} else {
V_280 -> V_410 = V_411 | V_412 ;
}
V_3 -> V_413 = V_414 ;
V_6 -> V_399 = V_415 ;
if ( F_78 ( V_15 ) >= 4 &&
F_166 ( V_1 , V_395 ) ) {
V_6 -> V_399 = V_416 ;
V_1 -> V_215 = true ;
}
if ( F_168 ( V_7 , V_1 ) < 0 ) {
F_26 ( V_7 ) ;
return false ;
}
if ( V_1 -> V_215 )
F_172 ( V_1 , V_7 ) ;
return true ;
}
static bool
F_180 ( struct V_1 * V_1 , int type )
{
struct V_377 * V_3 = & V_1 -> V_4 . V_4 ;
struct V_5 * V_6 ;
struct V_280 * V_280 ;
struct V_7 * V_7 ;
F_16 ( L_41 , type ) ;
V_7 = F_177 () ;
if ( ! V_7 )
return false ;
V_280 = & V_7 -> V_4 ;
V_6 = & V_280 -> V_4 ;
V_3 -> V_413 = V_417 ;
V_6 -> V_399 = V_418 ;
V_1 -> V_380 |= type ;
V_7 -> V_282 = type ;
V_1 -> V_201 = true ;
if ( F_168 ( V_7 , V_1 ) < 0 ) {
F_26 ( V_7 ) ;
return false ;
}
if ( ! F_181 ( V_1 , V_7 , type ) )
goto V_419;
if ( ! F_182 ( V_1 , V_7 ) )
goto V_419;
return true ;
V_419:
F_135 ( V_6 ) ;
return false ;
}
static bool
F_183 ( struct V_1 * V_1 , int V_395 )
{
struct V_377 * V_3 = & V_1 -> V_4 . V_4 ;
struct V_5 * V_6 ;
struct V_280 * V_280 ;
struct V_7 * V_7 ;
F_16 ( L_42 , V_395 ) ;
V_7 = F_177 () ;
if ( ! V_7 )
return false ;
V_280 = & V_7 -> V_4 ;
V_6 = & V_280 -> V_4 ;
V_280 -> V_410 = V_411 ;
V_3 -> V_413 = V_420 ;
V_6 -> V_399 = V_421 ;
if ( V_395 == 0 ) {
V_1 -> V_380 |= V_386 ;
V_7 -> V_282 = V_386 ;
} else if ( V_395 == 1 ) {
V_1 -> V_380 |= V_385 ;
V_7 -> V_282 = V_385 ;
}
if ( F_168 ( V_7 , V_1 ) < 0 ) {
F_26 ( V_7 ) ;
return false ;
}
return true ;
}
static bool
F_184 ( struct V_1 * V_1 , int V_395 )
{
struct V_377 * V_3 = & V_1 -> V_4 . V_4 ;
struct V_5 * V_6 ;
struct V_280 * V_280 ;
struct V_7 * V_7 ;
F_16 ( L_43 , V_395 ) ;
V_7 = F_177 () ;
if ( ! V_7 )
return false ;
V_280 = & V_7 -> V_4 ;
V_6 = & V_280 -> V_4 ;
V_3 -> V_413 = V_422 ;
V_6 -> V_399 = V_423 ;
if ( V_395 == 0 ) {
V_1 -> V_380 |= V_382 ;
V_7 -> V_282 = V_382 ;
} else if ( V_395 == 1 ) {
V_1 -> V_380 |= V_381 ;
V_7 -> V_282 = V_381 ;
}
if ( F_168 ( V_7 , V_1 ) < 0 ) {
F_26 ( V_7 ) ;
return false ;
}
if ( ! F_182 ( V_1 , V_7 ) )
goto V_419;
return true ;
V_419:
F_135 ( V_6 ) ;
return false ;
}
static bool
F_185 ( struct V_1 * V_1 , T_4 V_29 )
{
V_1 -> V_201 = false ;
V_1 -> V_107 = false ;
if ( V_29 & V_384 )
if ( ! F_179 ( V_1 , 0 ) )
return false ;
if ( ( V_29 & V_424 ) == V_424 )
if ( ! F_179 ( V_1 , 1 ) )
return false ;
if ( V_29 & V_425 )
if ( ! F_180 ( V_1 , V_425 ) )
return false ;
if ( V_29 & V_426 )
if ( ! F_180 ( V_1 , V_426 ) )
return false ;
if ( V_29 & V_427 )
if ( ! F_180 ( V_1 , V_427 ) )
return false ;
if ( V_29 & V_386 )
if ( ! F_183 ( V_1 , 0 ) )
return false ;
if ( ( V_29 & V_428 ) == V_428 )
if ( ! F_183 ( V_1 , 1 ) )
return false ;
if ( V_29 & V_382 )
if ( ! F_184 ( V_1 , 0 ) )
return false ;
if ( ( V_29 & V_347 ) == V_347 )
if ( ! F_184 ( V_1 , 1 ) )
return false ;
if ( ( V_29 & V_429 ) == 0 ) {
unsigned char V_430 [ 2 ] ;
V_1 -> V_380 = 0 ;
memcpy ( V_430 , & V_1 -> V_311 . V_324 , 2 ) ;
F_16 ( L_44 ,
F_22 ( V_1 ) ,
V_430 [ 0 ] , V_430 [ 1 ] ) ;
return false ;
}
V_1 -> V_4 . V_431 = ( 1 << 0 ) | ( 1 << 1 ) | ( 1 << 2 ) ;
return true ;
}
static void F_186 ( struct V_1 * V_1 )
{
struct V_12 * V_13 = V_1 -> V_4 . V_4 . V_13 ;
struct V_5 * V_6 , * V_160 ;
F_187 (connector, tmp,
&dev->mode_config.connector_list, head) {
if ( F_4 ( V_6 ) == & V_1 -> V_4 ) {
F_188 ( V_6 ) ;
F_135 ( V_6 ) ;
}
}
}
static bool F_181 ( struct V_1 * V_1 ,
struct V_7 * V_7 ,
int type )
{
struct V_12 * V_13 = V_1 -> V_4 . V_4 . V_13 ;
struct V_179 V_180 ;
T_7 V_181 , V_18 ;
if ( ! F_43 ( V_1 , type ) )
return false ;
F_38 ( sizeof( V_180 ) != 6 ) ;
if ( ! F_35 ( V_1 ,
V_432 ,
& V_180 , sizeof( V_180 ) ) )
return false ;
memcpy ( & V_181 , & V_180 , V_93 ( sizeof( V_181 ) , sizeof( V_180 ) ) ) ;
if ( V_181 == 0 )
return false ;
V_7 -> V_362 = 0 ;
for ( V_18 = 0 ; V_18 < V_433 ; V_18 ++ )
if ( V_181 & ( 1 << V_18 ) )
V_7 -> V_363 [ V_7 -> V_362 ++ ] = V_18 ;
V_7 -> V_361 =
F_189 ( V_13 , V_434 ,
L_45 , V_7 -> V_362 ) ;
if ( ! V_7 -> V_361 )
return false ;
for ( V_18 = 0 ; V_18 < V_7 -> V_362 ; V_18 ++ )
F_190 (
V_7 -> V_361 , V_18 ,
V_18 , V_435 [ V_7 -> V_363 [ V_18 ] ] ) ;
V_7 -> V_4 . V_4 . V_78 -> V_182 . V_77 = V_7 -> V_363 [ 0 ] ;
F_191 ( & V_7 -> V_4 . V_4 . V_4 ,
V_7 -> V_361 , 0 ) ;
return true ;
}
static bool
F_192 ( struct V_1 * V_1 ,
struct V_7 * V_7 ,
struct V_436 V_437 )
{
struct V_12 * V_13 = V_1 -> V_4 . V_4 . V_13 ;
struct V_5 * V_6 = & V_7 -> V_4 . V_4 ;
struct V_9 * V_10 = V_6 -> V_78 ;
struct V_8 * V_217 =
F_6 ( V_10 ) ;
T_4 V_48 , V_438 [ 2 ] ;
if ( V_437 . V_220 ) {
if ( ! F_35 ( V_1 ,
V_439 ,
& V_438 , 4 ) )
return false ;
if ( ! F_35 ( V_1 ,
V_440 ,
& V_48 , 2 ) )
return false ;
V_217 -> V_182 . V_220 = V_48 ;
V_7 -> V_367 = V_438 [ 0 ] ;
V_7 -> V_219 =
F_193 ( V_13 , 0 , L_46 , 0 , V_438 [ 0 ] ) ;
if ( ! V_7 -> V_219 )
return false ;
F_191 ( & V_6 -> V_4 ,
V_7 -> V_219 , 0 ) ;
V_7 -> V_366 =
F_193 ( V_13 , 0 , L_47 , 0 , V_438 [ 0 ] ) ;
if ( ! V_7 -> V_366 )
return false ;
F_191 ( & V_6 -> V_4 ,
V_7 -> V_366 , 0 ) ;
F_16 ( L_48
L_49 ,
V_438 [ 0 ] , V_438 [ 1 ] , V_48 ) ;
}
if ( V_437 . V_223 ) {
if ( ! F_35 ( V_1 ,
V_441 ,
& V_438 , 4 ) )
return false ;
if ( ! F_35 ( V_1 ,
V_442 ,
& V_48 , 2 ) )
return false ;
V_217 -> V_182 . V_223 = V_48 ;
V_7 -> V_365 = V_438 [ 0 ] ;
V_7 -> V_222 =
F_193 ( V_13 , 0 ,
L_50 , 0 , V_438 [ 0 ] ) ;
if ( ! V_7 -> V_222 )
return false ;
F_191 ( & V_6 -> V_4 ,
V_7 -> V_222 , 0 ) ;
V_7 -> V_364 =
F_193 ( V_13 , 0 ,
L_51 , 0 , V_438 [ 0 ] ) ;
if ( ! V_7 -> V_364 )
return false ;
F_191 ( & V_6 -> V_4 ,
V_7 -> V_364 , 0 ) ;
F_16 ( L_52
L_49 ,
V_438 [ 0 ] , V_438 [ 1 ] , V_48 ) ;
}
F_194 ( & V_217 -> V_182 , V_225 , V_226 ) ;
F_194 ( & V_217 -> V_182 , V_227 , V_228 ) ;
F_194 ( & V_10 -> V_182 , V_229 , V_230 ) ;
F_194 ( & V_10 -> V_182 , V_231 , V_232 ) ;
F_194 ( & V_10 -> V_182 , V_233 , V_234 ) ;
F_194 ( & V_10 -> V_182 , V_235 , V_236 ) ;
F_194 ( & V_217 -> V_182 , V_237 , V_238 ) ;
F_194 ( & V_217 -> V_182 , V_239 , V_240 ) ;
F_194 ( & V_217 -> V_182 , V_243 , V_244 ) ;
F_194 ( & V_217 -> V_182 , V_241 , V_242 ) ;
F_195 ( V_217 -> V_182 . V_246 , V_245 , V_247 ) ;
F_195 ( V_217 -> V_182 . V_249 , V_248 , V_250 ) ;
if ( V_437 . V_251 ) {
if ( ! F_35 ( V_1 , V_443 , & V_48 , 2 ) )
return false ;
V_217 -> V_182 . V_251 = V_48 & 0x1 ;
V_7 -> V_251 =
F_193 ( V_13 , 0 , L_53 , 0 , 1 ) ;
if ( ! V_7 -> V_251 )
return false ;
F_191 ( & V_6 -> V_4 ,
V_7 -> V_251 , 0 ) ;
F_16 ( L_54 , V_48 ) ;
}
return true ;
}
static bool
F_196 ( struct V_1 * V_1 ,
struct V_7 * V_7 ,
struct V_436 V_437 )
{
struct V_12 * V_13 = V_1 -> V_4 . V_4 . V_13 ;
struct V_5 * V_6 = & V_7 -> V_4 . V_4 ;
T_4 V_48 , V_438 [ 2 ] ;
F_194 ( & V_6 -> V_78 -> V_182 , V_235 , V_236 ) ;
return true ;
}
static bool F_182 ( struct V_1 * V_1 ,
struct V_7 * V_7 )
{
union {
struct V_436 V_350 ;
T_4 V_48 ;
} V_437 ;
F_38 ( sizeof( V_437 ) != 2 ) ;
if ( ! F_35 ( V_1 ,
V_444 ,
& V_437 , sizeof( V_437 ) ) ||
V_437 . V_48 == 0 ) {
F_16 ( L_55 ) ;
return true ;
}
if ( F_132 ( V_7 ) )
return F_192 ( V_1 , V_7 , V_437 . V_350 ) ;
else if ( F_133 ( V_7 ) )
return F_196 ( V_1 , V_7 , V_437 . V_350 ) ;
else
return true ;
}
static int F_197 ( struct V_445 * V_446 ,
struct V_26 * V_27 ,
int V_447 )
{
struct V_1 * V_330 = V_446 -> V_448 ;
if ( ! F_33 ( V_330 , V_330 -> V_61 ) )
return - V_449 ;
return V_330 -> V_34 -> V_450 -> V_451 ( V_330 -> V_34 , V_27 , V_447 ) ;
}
static T_1 F_198 ( struct V_445 * V_446 )
{
struct V_1 * V_330 = V_446 -> V_448 ;
return V_330 -> V_34 -> V_450 -> V_452 ( V_330 -> V_34 ) ;
}
static void F_199 ( struct V_445 * V_446 ,
unsigned int V_29 )
{
struct V_1 * V_330 = V_446 -> V_448 ;
V_330 -> V_34 -> V_453 -> V_454 ( V_330 -> V_34 , V_29 ) ;
}
static int F_200 ( struct V_445 * V_446 ,
unsigned int V_29 )
{
struct V_1 * V_330 = V_446 -> V_448 ;
return V_330 -> V_34 -> V_453 -> V_455 ( V_330 -> V_34 , V_29 ) ;
}
static void F_201 ( struct V_445 * V_446 ,
unsigned int V_29 )
{
struct V_1 * V_330 = V_446 -> V_448 ;
V_330 -> V_34 -> V_453 -> V_456 ( V_330 -> V_34 , V_29 ) ;
}
static bool
F_202 ( struct V_1 * V_330 ,
struct V_14 * V_15 )
{
struct V_457 * V_458 = V_15 -> V_459 . V_458 ;
V_330 -> V_331 . V_460 = V_461 ;
V_330 -> V_331 . V_462 = V_463 ;
snprintf ( V_330 -> V_331 . V_40 , V_464 , L_56 ) ;
V_330 -> V_331 . V_13 . V_465 = & V_458 -> V_13 ;
V_330 -> V_331 . V_448 = V_330 ;
V_330 -> V_331 . V_450 = & V_466 ;
V_330 -> V_331 . V_453 = & V_467 ;
return F_203 ( & V_330 -> V_331 ) == 0 ;
}
static void F_204 ( const struct V_14 * V_15 ,
enum V_20 V_20 )
{
if ( F_9 ( V_15 ) )
F_138 ( V_20 != V_21 ) ;
else
F_138 ( V_20 != V_21 && V_20 != V_468 ) ;
}
bool F_205 ( struct V_14 * V_15 ,
T_9 V_19 , enum V_20 V_20 )
{
struct V_2 * V_2 ;
struct V_1 * V_1 ;
int V_18 ;
F_204 ( V_15 , V_20 ) ;
V_1 = F_24 ( sizeof( * V_1 ) , V_43 ) ;
if ( ! V_1 )
return false ;
V_1 -> V_19 = V_19 ;
V_1 -> V_20 = V_20 ;
V_1 -> V_28 =
F_167 ( V_15 , V_1 ) >> 1 ;
F_162 ( V_15 , V_1 ) ;
if ( ! F_202 ( V_1 , V_15 ) )
goto V_469;
V_2 = & V_1 -> V_4 ;
V_2 -> type = V_470 ;
V_2 -> V_471 = V_472 ;
V_2 -> V_20 = V_20 ;
F_206 ( & V_15 -> V_459 , & V_2 -> V_4 ,
& V_473 , 0 ,
L_57 , F_207 ( V_20 ) ) ;
for ( V_18 = 0 ; V_18 < 0x40 ; V_18 ++ ) {
T_2 V_474 ;
if ( ! F_14 ( V_1 , V_18 , & V_474 ) ) {
F_16 ( L_58 ,
F_22 ( V_1 ) ) ;
goto V_419;
}
}
V_2 -> V_475 = F_71 ;
if ( F_9 ( V_15 ) ) {
V_2 -> V_476 = F_99 ;
V_2 -> V_477 = F_100 ;
} else {
V_2 -> V_476 = F_95 ;
}
V_2 -> V_478 = F_75 ;
V_2 -> V_479 = F_101 ;
V_2 -> V_406 = F_88 ;
V_2 -> V_480 = F_91 ;
if ( ! F_104 ( V_1 , & V_1 -> V_311 ) )
goto V_419;
if ( F_185 ( V_1 ,
V_1 -> V_311 . V_324 ) != true ) {
F_16 ( L_59 ,
F_22 ( V_1 ) ) ;
goto V_481;
}
if ( V_1 -> V_328 ) {
if ( V_1 -> V_20 == V_21 )
V_2 -> V_482 = V_483 ;
else
V_2 -> V_482 = V_484 ;
}
V_1 -> V_4 . V_485 = 0 ;
F_161 ( V_15 , V_1 ) ;
if ( ! F_36 ( V_1 ) )
goto V_481;
if ( ! F_42 ( V_1 ,
& V_1 -> V_304 ,
& V_1 -> V_306 ) )
goto V_481;
F_16 ( L_60
L_61
L_62
L_63 ,
F_22 ( V_1 ) ,
V_1 -> V_311 . V_313 , V_1 -> V_311 . V_314 ,
V_1 -> V_311 . V_315 ,
V_1 -> V_304 / 1000 ,
V_1 -> V_306 / 1000 ,
( V_1 -> V_311 . V_318 & 0x1 ) ? 'Y' : 'N' ,
( V_1 -> V_311 . V_318 & 0x2 ) ? 'Y' : 'N' ,
V_1 -> V_311 . V_324 &
( V_384 | V_386 ) ? 'Y' : 'N' ,
V_1 -> V_311 . V_324 &
( V_383 | V_385 ) ? 'Y' : 'N' ) ;
return true ;
V_481:
F_186 ( V_1 ) ;
V_419:
F_208 ( & V_2 -> V_4 ) ;
F_158 ( & V_1 -> V_331 ) ;
V_469:
F_165 ( V_1 ) ;
F_26 ( V_1 ) ;
return false ;
}
