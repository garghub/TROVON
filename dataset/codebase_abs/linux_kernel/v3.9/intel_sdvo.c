static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 . V_4 ) ;
}
static struct V_1 * F_3 ( struct V_5 * V_6 )
{
return F_2 ( F_4 ( V_6 ) ,
struct V_1 , V_4 ) ;
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
if ( V_1 -> V_17 == V_19 ) {
V_15 = F_9 ( V_20 ) ;
} else {
V_14 = F_9 ( V_19 ) ;
}
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
V_28 = ( T_2 * ) F_18 ( V_33 * 2 + 2 , V_37 ) ;
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
while ( V_36 == V_46 && -- V_44 ) {
if ( V_44 < 10 )
F_22 ( 15 ) ;
else
F_23 ( 15 ) ;
if ( ! F_10 ( V_1 ,
V_40 ,
& V_36 ) )
goto V_45;
}
if ( V_36 <= V_47 )
F_15 ( L_5 , V_48 [ V_36 ] ) ;
else
F_15 ( L_11 , V_36 ) ;
if ( V_36 != V_49 )
goto V_45;
for ( V_16 = 0 ; V_16 < V_43 ; V_16 ++ ) {
if ( ! F_10 ( V_1 ,
V_50 + V_16 ,
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
static int F_24 ( struct V_51 * V_52 )
{
if ( V_52 -> clock >= 100000 )
return 1 ;
else if ( V_52 -> clock >= 50000 )
return 2 ;
else
return 4 ;
}
static bool F_25 ( struct V_1 * V_1 ,
T_2 V_53 )
{
return F_17 ( V_1 ,
V_54 ,
& V_53 , 1 ) ;
}
static bool F_26 ( struct V_1 * V_1 , T_2 V_32 , const void * V_55 , int V_27 )
{
if ( ! F_17 ( V_1 , V_32 , V_55 , V_27 ) )
return false ;
return F_21 ( V_1 , NULL , 0 ) ;
}
static bool
F_27 ( struct V_1 * V_1 , T_2 V_32 , void * V_56 , int V_27 )
{
if ( ! F_17 ( V_1 , V_32 , NULL , 0 ) )
return false ;
return F_21 ( V_1 , V_56 , V_27 ) ;
}
static bool F_28 ( struct V_1 * V_1 )
{
struct V_57 V_58 = { 0 } ;
return F_26 ( V_1 ,
V_59 ,
& V_58 , sizeof( V_58 ) ) ;
}
static bool F_29 ( struct V_1 * V_1 , bool * V_60 , bool * V_61 )
{
struct V_62 V_42 ;
F_30 ( sizeof( V_42 ) != 1 ) ;
if ( ! F_27 ( V_1 , V_63 ,
& V_42 , sizeof( V_42 ) ) )
return false ;
* V_60 = V_42 . V_64 ;
* V_61 = V_42 . V_65 ;
return true ;
}
static bool F_31 ( struct V_1 * V_1 ,
T_3 V_66 )
{
return F_26 ( V_1 ,
V_67 ,
& V_66 , sizeof( V_66 ) ) ;
}
static bool F_32 ( struct V_1 * V_1 ,
T_3 * V_66 )
{
return F_27 ( V_1 ,
V_68 ,
V_66 , sizeof( * V_66 ) ) ;
}
static bool F_33 ( struct V_1 * V_1 ,
int V_52 )
{
T_2 V_69 = V_70 ;
switch ( V_52 ) {
case V_71 :
V_69 = V_70 ;
break;
case V_72 :
V_69 = V_73 ;
break;
case V_74 :
V_69 = V_75 ;
break;
case V_76 :
V_69 = V_77 ;
break;
}
return F_26 ( V_1 ,
V_78 , & V_69 , sizeof( V_69 ) ) ;
}
static bool F_34 ( struct V_1 * V_1 ,
int * V_79 ,
int * V_80 )
{
struct V_81 V_82 ;
F_30 ( sizeof( V_82 ) != 4 ) ;
if ( ! F_27 ( V_1 ,
V_83 ,
& V_82 , sizeof( V_82 ) ) )
return false ;
* V_79 = V_82 . V_84 * 10 ;
* V_80 = V_82 . V_85 * 10 ;
return true ;
}
static bool F_35 ( struct V_1 * V_1 ,
T_3 V_66 )
{
return F_26 ( V_1 ,
V_86 ,
& V_66 , sizeof( V_66 ) ) ;
}
static bool F_36 ( struct V_1 * V_1 , T_2 V_32 ,
struct V_87 * V_88 )
{
return F_26 ( V_1 , V_32 , & V_88 -> V_89 , sizeof( V_88 -> V_89 ) ) &&
F_26 ( V_1 , V_32 + 1 , & V_88 -> V_90 , sizeof( V_88 -> V_90 ) ) ;
}
static bool F_37 ( struct V_1 * V_1 ,
struct V_87 * V_88 )
{
return F_36 ( V_1 ,
V_91 , V_88 ) ;
}
static bool F_38 ( struct V_1 * V_1 ,
struct V_87 * V_88 )
{
return F_36 ( V_1 ,
V_92 , V_88 ) ;
}
static bool
F_39 ( struct V_1 * V_1 ,
T_4 clock ,
T_4 V_93 ,
T_4 V_94 )
{
struct V_95 args ;
memset ( & args , 0 , sizeof( args ) ) ;
args . clock = clock ;
args . V_93 = V_93 ;
args . V_94 = V_94 ;
args . V_96 = 0 ;
if ( V_1 -> V_97 &&
( V_1 -> V_98 -> V_99 != V_93 ||
V_1 -> V_98 -> V_100 != V_94 ) )
args . V_101 = 1 ;
return F_26 ( V_1 ,
V_102 ,
& args , sizeof( args ) ) ;
}
static bool F_40 ( struct V_1 * V_1 ,
struct V_87 * V_88 )
{
F_30 ( sizeof( V_88 -> V_89 ) != 8 ) ;
F_30 ( sizeof( V_88 -> V_90 ) != 8 ) ;
return F_27 ( V_1 , V_103 ,
& V_88 -> V_89 , sizeof( V_88 -> V_89 ) ) &&
F_27 ( V_1 , V_104 ,
& V_88 -> V_90 , sizeof( V_88 -> V_90 ) ) ;
}
static bool F_41 ( struct V_1 * V_1 , T_2 V_8 )
{
return F_26 ( V_1 , V_105 , & V_8 , 1 ) ;
}
static void F_42 ( struct V_87 * V_88 ,
const struct V_51 * V_52 )
{
T_4 V_93 , V_94 ;
T_4 V_106 , V_107 , V_108 , V_109 ;
T_4 V_110 , V_111 ;
int V_112 ;
V_93 = V_52 -> V_99 ;
V_94 = V_52 -> V_100 ;
V_106 = V_52 -> V_113 - V_52 -> V_99 ;
V_107 = V_52 -> V_114 - V_52 -> V_115 ;
V_108 = V_52 -> V_116 - V_52 -> V_100 ;
V_109 = V_52 -> V_117 - V_52 -> V_118 ;
V_110 = V_52 -> V_115 - V_52 -> V_99 ;
V_111 = V_52 -> V_118 - V_52 -> V_100 ;
V_112 = V_52 -> clock ;
V_112 /= F_43 ( V_52 ) ? : 1 ;
V_112 /= 10 ;
V_88 -> V_89 . clock = V_112 ;
V_88 -> V_89 . V_119 = V_93 & 0xff ;
V_88 -> V_89 . V_120 = V_106 & 0xff ;
V_88 -> V_89 . V_121 = ( ( ( V_93 >> 8 ) & 0xf ) << 4 ) |
( ( V_106 >> 8 ) & 0xf ) ;
V_88 -> V_89 . V_122 = V_94 & 0xff ;
V_88 -> V_89 . V_123 = V_108 & 0xff ;
V_88 -> V_89 . V_124 = ( ( ( V_94 >> 8 ) & 0xf ) << 4 ) |
( ( V_108 >> 8 ) & 0xf ) ;
V_88 -> V_90 . V_125 = V_110 & 0xff ;
V_88 -> V_90 . V_126 = V_107 & 0xff ;
V_88 -> V_90 . V_127 = ( V_111 & 0xf ) << 4 |
( V_109 & 0xf ) ;
V_88 -> V_90 . V_128 = ( ( V_110 & 0x300 ) >> 2 ) |
( ( V_107 & 0x300 ) >> 4 ) | ( ( V_111 & 0x30 ) >> 2 ) |
( ( V_109 & 0x30 ) >> 4 ) ;
V_88 -> V_90 . V_129 = 0x18 ;
if ( V_52 -> V_26 & V_130 )
V_88 -> V_90 . V_129 |= V_131 ;
if ( V_52 -> V_26 & V_132 )
V_88 -> V_90 . V_129 |= V_133 ;
if ( V_52 -> V_26 & V_134 )
V_88 -> V_90 . V_129 |= V_135 ;
V_88 -> V_90 . V_136 = 0 ;
V_88 -> V_90 . V_137 = V_111 & 0xc0 ;
V_88 -> V_90 . V_138 = 0 ;
}
static void F_44 ( struct V_51 * V_52 ,
const struct V_87 * V_88 )
{
V_52 -> V_99 = V_88 -> V_89 . V_119 ;
V_52 -> V_99 += ( ( V_88 -> V_89 . V_121 >> 4 ) & 0x0f ) << 8 ;
V_52 -> V_115 = V_52 -> V_99 + V_88 -> V_90 . V_125 ;
V_52 -> V_115 += ( V_88 -> V_90 . V_128 & 0xc0 ) << 2 ;
V_52 -> V_114 = V_52 -> V_115 + V_88 -> V_90 . V_126 ;
V_52 -> V_114 += ( V_88 -> V_90 . V_128 & 0x30 ) << 4 ;
V_52 -> V_113 = V_52 -> V_99 + V_88 -> V_89 . V_120 ;
V_52 -> V_113 += ( V_88 -> V_89 . V_121 & 0xf ) << 8 ;
V_52 -> V_100 = V_88 -> V_89 . V_122 ;
V_52 -> V_100 += ( ( V_88 -> V_89 . V_124 >> 4 ) & 0x0f ) << 8 ;
V_52 -> V_118 = V_52 -> V_100 ;
V_52 -> V_118 += ( V_88 -> V_90 . V_127 >> 4 ) & 0xf ;
V_52 -> V_118 += ( V_88 -> V_90 . V_128 & 0x0c ) << 2 ;
V_52 -> V_118 += V_88 -> V_90 . V_137 & 0xc0 ;
V_52 -> V_117 = V_52 -> V_118 +
( V_88 -> V_90 . V_127 & 0xf ) ;
V_52 -> V_117 += ( V_88 -> V_90 . V_128 & 0x3 ) << 4 ;
V_52 -> V_116 = V_52 -> V_100 + V_88 -> V_89 . V_123 ;
V_52 -> V_116 += ( V_88 -> V_89 . V_124 & 0xf ) << 8 ;
V_52 -> clock = V_88 -> V_89 . clock * 10 ;
V_52 -> V_26 &= ~ ( V_132 | V_134 ) ;
if ( V_88 -> V_90 . V_129 & V_131 )
V_52 -> V_26 |= V_130 ;
if ( V_88 -> V_90 . V_129 & V_133 )
V_52 -> V_26 |= V_132 ;
if ( V_88 -> V_90 . V_129 & V_135 )
V_52 -> V_26 |= V_134 ;
}
static bool F_45 ( struct V_1 * V_1 )
{
struct V_139 V_140 ;
F_30 ( sizeof( V_140 ) != 2 ) ;
return F_27 ( V_1 ,
V_141 ,
& V_140 , sizeof( V_140 ) ) ;
}
static bool F_46 ( struct V_1 * V_1 ,
T_5 V_52 )
{
return F_26 ( V_1 , V_142 , & V_52 , 1 ) ;
}
static bool F_47 ( struct V_1 * V_1 ,
T_5 V_52 )
{
return F_26 ( V_1 , V_143 , & V_52 , 1 ) ;
}
static bool F_48 ( struct V_1 * V_1 ,
unsigned V_144 , T_5 V_145 ,
T_5 * V_55 , unsigned V_146 )
{
T_5 V_147 [ 2 ] = { V_144 , 0 } ;
T_5 V_148 , V_149 [ 8 ] ;
int V_16 ;
if ( ! F_26 ( V_1 ,
V_150 ,
V_147 , 2 ) )
return false ;
if ( ! F_27 ( V_1 , V_151 ,
& V_148 , 1 ) )
return false ;
V_148 ++ ;
F_12 ( L_14 ,
V_144 , V_146 , V_148 ) ;
for ( V_16 = 0 ; V_16 < V_148 ; V_16 += 8 ) {
memset ( V_149 , 0 , 8 ) ;
if ( V_16 < V_146 )
memcpy ( V_149 , V_55 + V_16 , F_49 ( unsigned , 8 , V_146 - V_16 ) ) ;
if ( ! F_26 ( V_1 ,
V_152 ,
V_149 , 8 ) )
return false ;
}
return F_26 ( V_1 ,
V_153 ,
& V_145 , 1 ) ;
}
static bool F_50 ( struct V_1 * V_1 ,
const struct V_51 * V_154 )
{
struct V_155 V_156 = {
. type = V_157 ,
. V_158 = V_159 ,
. V_27 = V_160 ,
} ;
T_5 V_161 [ 4 + sizeof( V_156 . V_162 . V_163 ) ] ;
if ( V_1 -> V_164 ) {
if ( V_154 -> V_165 & V_166 )
V_156 . V_162 . V_163 . V_167 |= V_168 ;
else
V_156 . V_162 . V_163 . V_167 |= V_169 ;
}
F_51 ( & V_156 ) ;
memcpy ( V_161 , & V_156 , 3 ) ;
V_161 [ 3 ] = V_156 . V_170 ;
memcpy ( & V_161 [ 4 ] , & V_156 . V_162 , sizeof( V_156 . V_162 . V_163 ) ) ;
return F_48 ( V_1 , V_171 ,
V_172 ,
V_161 , sizeof( V_161 ) ) ;
}
static bool F_52 ( struct V_1 * V_1 )
{
struct V_173 V_174 ;
T_6 V_175 ;
V_175 = 1 << V_1 -> V_176 ;
memset ( & V_174 , 0 , sizeof( V_174 ) ) ;
memcpy ( & V_174 , & V_175 , V_84 ( sizeof( V_174 ) , sizeof( V_175 ) ) ) ;
F_30 ( sizeof( V_174 ) != 6 ) ;
return F_26 ( V_1 ,
V_177 ,
& V_174 , sizeof( V_174 ) ) ;
}
static bool
F_53 ( struct V_1 * V_1 ,
const struct V_51 * V_52 )
{
struct V_87 V_178 ;
if ( ! F_35 ( V_1 ,
V_1 -> V_179 ) )
return false ;
F_42 ( & V_178 , V_52 ) ;
if ( ! F_38 ( V_1 , & V_178 ) )
return false ;
return true ;
}
static bool
F_54 ( struct V_1 * V_1 ,
const struct V_51 * V_52 ,
struct V_51 * V_154 )
{
struct V_87 V_180 ;
if ( ! F_28 ( V_1 ) )
return false ;
if ( ! F_39 ( V_1 ,
V_52 -> clock / 10 ,
V_52 -> V_99 ,
V_52 -> V_100 ) )
return false ;
if ( ! F_40 ( V_1 ,
& V_180 ) )
return false ;
F_44 ( V_154 , & V_180 ) ;
V_1 -> V_181 = V_180 . V_90 . V_136 ;
return true ;
}
static bool F_55 ( struct V_2 * V_3 ,
const struct V_51 * V_52 ,
struct V_51 * V_154 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
int V_182 ;
if ( V_1 -> V_183 ) {
if ( ! F_53 ( V_1 , V_52 ) )
return false ;
( void ) F_54 ( V_1 ,
V_52 ,
V_154 ) ;
} else if ( V_1 -> V_97 ) {
if ( ! F_53 ( V_1 ,
V_1 -> V_98 ) )
return false ;
( void ) F_54 ( V_1 ,
V_52 ,
V_154 ) ;
}
V_182 = F_24 ( V_154 ) ;
F_56 ( V_154 , V_182 ) ;
if ( V_1 -> V_184 ) {
if ( V_1 -> V_185 &&
F_57 ( V_154 ) > 1 )
V_1 -> V_186 = V_187 ;
else
V_1 -> V_186 = 0 ;
}
if ( V_1 -> V_186 )
V_154 -> V_165 |= V_166 ;
return true ;
}
static void F_58 ( struct V_2 * V_3 ,
struct V_51 * V_52 ,
struct V_51 * V_154 )
{
struct V_9 * V_10 = V_3 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_188 * V_189 = V_3 -> V_189 ;
struct V_190 * V_190 = F_59 ( V_189 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
T_1 V_191 ;
struct V_192 V_193 ;
struct V_87 V_180 , V_178 ;
int V_194 = F_43 ( V_154 ) ;
int V_195 ;
if ( ! V_52 )
return;
V_193 . V_196 = V_1 -> V_179 ;
V_193 . V_197 = 0 ;
F_26 ( V_1 ,
V_198 ,
& V_193 , sizeof( V_193 ) ) ;
if ( ! F_35 ( V_1 ,
V_1 -> V_179 ) )
return;
if ( V_1 -> V_97 )
F_42 ( & V_178 ,
V_1 -> V_98 ) ;
else
F_42 ( & V_178 , V_52 ) ;
if ( ! F_38 ( V_1 , & V_178 ) )
F_60 ( L_15 ,
F_14 ( V_1 ) ) ;
if ( ! F_28 ( V_1 ) )
return;
if ( V_1 -> V_185 ) {
F_46 ( V_1 , V_199 ) ;
F_47 ( V_1 ,
V_200 ) ;
F_50 ( V_1 , V_154 ) ;
} else
F_46 ( V_1 , V_201 ) ;
if ( V_1 -> V_183 &&
! F_52 ( V_1 ) )
return;
F_42 ( & V_180 , V_154 ) ;
if ( V_1 -> V_183 || V_1 -> V_97 )
V_180 . V_90 . V_136 = V_1 -> V_181 ;
if ( ! F_37 ( V_1 , & V_180 ) )
F_60 ( L_16 ,
F_14 ( V_1 ) ) ;
switch ( V_194 ) {
default:
case 1 : V_195 = V_202 ; break;
case 2 : V_195 = V_203 ; break;
case 4 : V_195 = V_204 ; break;
}
if ( ! F_41 ( V_1 , V_195 ) )
return;
if ( F_61 ( V_10 ) -> V_205 >= 4 ) {
V_191 = V_206 | V_207 ;
if ( ! F_62 ( V_10 ) && V_1 -> V_208 )
V_191 |= V_1 -> V_186 ;
if ( F_61 ( V_10 ) -> V_205 < 5 )
V_191 |= V_209 ;
} else {
V_191 = F_9 ( V_1 -> V_17 ) ;
switch ( V_1 -> V_17 ) {
case V_19 :
V_191 &= V_210 ;
break;
case V_20 :
V_191 &= V_211 ;
break;
}
V_191 |= ( 9 << 19 ) | V_209 ;
}
if ( F_63 ( V_10 ) >= V_212 )
V_191 |= F_64 ( V_190 -> V_213 ) ;
else
V_191 |= F_65 ( V_190 -> V_213 ) ;
if ( V_1 -> V_214 )
V_191 |= V_215 ;
if ( F_61 ( V_10 ) -> V_205 >= 4 ) {
} else if ( F_66 ( V_10 ) || F_67 ( V_10 ) || F_68 ( V_10 ) ) {
} else {
V_191 |= ( V_194 - 1 ) << V_216 ;
}
if ( V_180 . V_90 . V_136 & V_217 &&
F_61 ( V_10 ) -> V_205 < 5 )
V_191 |= V_218 ;
F_7 ( V_1 , V_191 ) ;
}
static bool F_69 ( struct V_219 * V_6 )
{
struct V_7 * V_7 =
F_5 ( & V_6 -> V_4 ) ;
struct V_1 * V_1 = F_3 ( & V_6 -> V_4 ) ;
T_3 V_220 ;
F_32 ( V_1 , & V_220 ) ;
if ( V_220 & V_7 -> V_221 )
return true ;
else
return false ;
}
static bool F_70 ( struct V_222 * V_3 ,
enum V_213 * V_213 )
{
struct V_9 * V_10 = V_3 -> V_4 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_1 * V_1 = F_1 ( & V_3 -> V_4 ) ;
T_1 V_149 ;
V_149 = F_9 ( V_1 -> V_17 ) ;
if ( ! ( V_149 & V_223 ) )
return false ;
if ( F_71 ( V_10 ) )
* V_213 = F_72 ( V_149 ) ;
else
* V_213 = F_73 ( V_149 ) ;
return true ;
}
static void F_74 ( struct V_222 * V_3 )
{
struct V_11 * V_12 = V_3 -> V_4 . V_10 -> V_13 ;
struct V_1 * V_1 = F_1 ( & V_3 -> V_4 ) ;
T_1 V_224 ;
F_31 ( V_1 , 0 ) ;
if ( 0 )
F_33 ( V_1 ,
V_76 ) ;
V_224 = F_9 ( V_1 -> V_17 ) ;
if ( ( V_224 & V_223 ) != 0 ) {
if ( F_75 ( V_3 -> V_4 . V_10 ) ) {
struct V_188 * V_189 = V_3 -> V_4 . V_189 ;
int V_213 = V_189 ? F_59 ( V_189 ) -> V_213 : - 1 ;
if ( V_224 & V_225 ) {
V_224 &= ~ V_225 ;
F_8 ( V_1 -> V_17 , V_224 ) ;
F_76 ( V_1 -> V_17 ) ;
F_8 ( V_1 -> V_17 , V_224 ) ;
F_76 ( V_1 -> V_17 ) ;
if ( V_189 )
F_77 ( V_3 -> V_4 . V_10 , V_213 ) ;
else
F_22 ( 50 ) ;
}
}
F_7 ( V_1 , V_224 & ~ V_223 ) ;
}
}
static void F_78 ( struct V_222 * V_3 )
{
struct V_9 * V_10 = V_3 -> V_4 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_1 * V_1 = F_1 ( & V_3 -> V_4 ) ;
struct V_190 * V_190 = F_59 ( V_3 -> V_4 . V_189 ) ;
T_1 V_224 ;
bool V_226 , V_227 ;
int V_16 ;
T_2 V_36 ;
V_224 = F_9 ( V_1 -> V_17 ) ;
if ( ( V_224 & V_223 ) == 0 ) {
if ( F_75 ( V_10 ) ) {
struct V_188 * V_189 = V_3 -> V_4 . V_189 ;
int V_213 = V_189 ? F_59 ( V_189 ) -> V_213 : - 1 ;
if ( V_213 == V_228 )
V_224 |= V_225 ;
}
F_7 ( V_1 , V_224 | V_223 ) ;
}
for ( V_16 = 0 ; V_16 < 2 ; V_16 ++ )
F_77 ( V_10 , V_190 -> V_213 ) ;
V_36 = F_29 ( V_1 , & V_226 , & V_227 ) ;
if ( V_36 == V_49 && ! V_226 ) {
F_12 ( L_17
L_18 , F_14 ( V_1 ) ) ;
}
if ( 0 )
F_33 ( V_1 ,
V_71 ) ;
F_31 ( V_1 , V_1 -> V_179 ) ;
}
static void F_79 ( struct V_5 * V_6 , int V_52 )
{
struct V_188 * V_189 ;
struct V_1 * V_1 = F_3 ( V_6 ) ;
if ( V_52 != V_71 )
V_52 = V_76 ;
if ( V_52 == V_6 -> V_229 )
return;
V_6 -> V_229 = V_52 ;
V_189 = V_1 -> V_4 . V_4 . V_189 ;
if ( ! V_189 ) {
V_1 -> V_4 . V_230 = false ;
return;
}
if ( V_52 != V_71 ) {
F_31 ( V_1 , 0 ) ;
if ( 0 )
F_33 ( V_1 , V_52 ) ;
V_1 -> V_4 . V_230 = false ;
F_80 ( V_189 ) ;
} else {
V_1 -> V_4 . V_230 = true ;
F_80 ( V_189 ) ;
if ( 0 )
F_33 ( V_1 , V_52 ) ;
F_31 ( V_1 , V_1 -> V_179 ) ;
}
F_81 ( V_6 -> V_10 ) ;
}
static int F_82 ( struct V_5 * V_6 ,
struct V_51 * V_52 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
if ( V_52 -> V_26 & V_231 )
return V_232 ;
if ( V_1 -> V_233 > V_52 -> clock )
return V_234 ;
if ( V_1 -> V_235 < V_52 -> clock )
return V_236 ;
if ( V_1 -> V_97 ) {
if ( V_52 -> V_99 > V_1 -> V_98 -> V_99 )
return V_237 ;
if ( V_52 -> V_100 > V_1 -> V_98 -> V_100 )
return V_237 ;
}
return V_238 ;
}
static bool F_83 ( struct V_1 * V_1 , struct V_239 * V_240 )
{
F_30 ( sizeof( * V_240 ) != 8 ) ;
if ( ! F_27 ( V_1 ,
V_241 ,
V_240 , sizeof( * V_240 ) ) )
return false ;
F_12 ( L_19
L_20
L_21
L_22
L_23
L_24
L_25
L_26
L_27
L_28
L_29
L_30
L_31 ,
V_240 -> V_242 ,
V_240 -> V_243 ,
V_240 -> V_244 ,
V_240 -> V_245 ,
V_240 -> V_246 ,
V_240 -> V_247 ,
V_240 -> V_248 ,
V_240 -> V_249 ,
V_240 -> V_250 ,
V_240 -> V_251 ,
V_240 -> V_252 ,
V_240 -> V_253 ) ;
return true ;
}
static T_4 F_84 ( struct V_1 * V_1 )
{
struct V_9 * V_10 = V_1 -> V_4 . V_4 . V_10 ;
T_4 V_254 ;
if ( F_66 ( V_10 ) || F_67 ( V_10 ) )
return 0 ;
if ( ! F_27 ( V_1 , V_255 ,
& V_254 , sizeof( V_254 ) ) )
return 0 ;
return V_254 ;
}
static void F_85 ( struct V_222 * V_3 )
{
struct V_1 * V_1 = F_1 ( & V_3 -> V_4 ) ;
F_17 ( V_1 , V_256 ,
& V_1 -> V_257 , 2 ) ;
}
static bool
F_86 ( struct V_1 * V_1 )
{
return F_87 ( V_1 -> V_240 . V_253 ) > 1 ;
}
static struct V_258 *
F_88 ( struct V_5 * V_6 )
{
struct V_1 * V_259 = F_3 ( V_6 ) ;
return F_89 ( V_6 , & V_259 -> V_260 ) ;
}
static struct V_258 *
F_90 ( struct V_5 * V_6 )
{
struct V_11 * V_12 = V_6 -> V_10 -> V_13 ;
return F_89 ( V_6 ,
F_91 ( V_12 ,
V_12 -> V_261 ) ) ;
}
static enum V_262
F_92 ( struct V_5 * V_6 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
enum V_262 V_36 ;
struct V_258 * V_258 ;
V_258 = F_88 ( V_6 ) ;
if ( V_258 == NULL && F_86 ( V_1 ) ) {
T_2 V_260 , V_263 = V_1 -> V_53 ;
for ( V_260 = V_1 -> V_53 >> 1 ; V_260 > 1 ; V_260 >>= 1 ) {
V_1 -> V_53 = V_260 ;
V_258 = F_88 ( V_6 ) ;
if ( V_258 )
break;
}
if ( V_258 == NULL )
V_1 -> V_53 = V_263 ;
}
if ( V_258 == NULL )
V_258 = F_90 ( V_6 ) ;
V_36 = V_264 ;
if ( V_258 != NULL ) {
if ( V_258 -> V_265 & V_266 ) {
V_36 = V_267 ;
if ( V_1 -> V_208 ) {
V_1 -> V_185 = F_93 ( V_258 ) ;
V_1 -> V_214 = F_94 ( V_258 ) ;
V_1 -> V_164 =
F_95 ( V_258 ) ;
}
} else
V_36 = V_268 ;
F_20 ( V_258 ) ;
}
if ( V_36 == V_267 ) {
struct V_7 * V_7 = F_5 ( V_6 ) ;
if ( V_7 -> V_269 != V_270 )
V_1 -> V_214 = ( V_7 -> V_269 == V_271 ) ;
}
return V_36 ;
}
static bool
F_96 ( struct V_7 * V_259 ,
struct V_258 * V_258 )
{
bool V_272 = ! ! ( V_258 -> V_265 & V_266 ) ;
bool V_273 = ! ! F_97 ( V_259 ) ;
F_12 ( L_32 ,
V_273 , V_272 ) ;
return V_273 == V_272 ;
}
static enum V_262
F_98 ( struct V_5 * V_6 , bool V_274 )
{
T_4 V_42 ;
struct V_1 * V_1 = F_3 ( V_6 ) ;
struct V_7 * V_7 = F_5 ( V_6 ) ;
enum V_262 V_30 ;
if ( ! F_27 ( V_1 ,
V_275 ,
& V_42 , 2 ) )
return V_264 ;
F_12 ( L_33 ,
V_42 & 0xff , V_42 >> 8 ,
V_7 -> V_221 ) ;
if ( V_42 == 0 )
return V_268 ;
V_1 -> V_179 = V_42 ;
V_1 -> V_185 = false ;
V_1 -> V_214 = false ;
V_1 -> V_164 = false ;
if ( ( V_7 -> V_221 & V_42 ) == 0 )
V_30 = V_268 ;
else if ( F_99 ( V_7 ) )
V_30 = F_92 ( V_6 ) ;
else {
struct V_258 * V_258 ;
V_258 = F_88 ( V_6 ) ;
if ( V_258 == NULL )
V_258 = F_90 ( V_6 ) ;
if ( V_258 != NULL ) {
if ( F_96 ( V_7 ,
V_258 ) )
V_30 = V_267 ;
else
V_30 = V_268 ;
F_20 ( V_258 ) ;
} else
V_30 = V_267 ;
}
if ( V_30 == V_267 ) {
V_1 -> V_183 = false ;
V_1 -> V_97 = false ;
V_1 -> V_4 . V_276 = false ;
if ( V_42 & V_277 ) {
V_1 -> V_183 = true ;
V_1 -> V_4 . V_276 = true ;
}
if ( V_42 & V_278 )
V_1 -> V_97 = V_1 -> V_98 != NULL ;
}
return V_30 ;
}
static void F_100 ( struct V_5 * V_6 )
{
struct V_258 * V_258 ;
V_258 = F_88 ( V_6 ) ;
if ( V_258 == NULL )
V_258 = F_90 ( V_6 ) ;
if ( V_258 != NULL ) {
if ( F_96 ( F_5 ( V_6 ) ,
V_258 ) ) {
F_101 ( V_6 , V_258 ) ;
F_102 ( V_6 , V_258 ) ;
}
F_20 ( V_258 ) ;
}
}
static void F_103 ( struct V_5 * V_6 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
struct V_279 V_280 ;
T_6 V_281 = 0 , V_175 = 0 ;
int V_16 ;
V_175 = 1 << V_1 -> V_176 ;
memcpy ( & V_280 , & V_175 ,
V_84 ( sizeof( V_175 ) , sizeof( struct V_279 ) ) ) ;
if ( ! F_35 ( V_1 , V_1 -> V_179 ) )
return;
F_30 ( sizeof( V_280 ) != 3 ) ;
if ( ! F_17 ( V_1 ,
V_282 ,
& V_280 , sizeof( V_280 ) ) )
return;
if ( ! F_21 ( V_1 , & V_281 , 3 ) )
return;
for ( V_16 = 0 ; V_16 < F_16 ( V_283 ) ; V_16 ++ )
if ( V_281 & ( 1 << V_16 ) ) {
struct V_51 * V_284 ;
V_284 = F_104 ( V_6 -> V_10 ,
& V_283 [ V_16 ] ) ;
if ( V_284 )
F_105 ( V_6 , V_284 ) ;
}
}
static void F_106 ( struct V_5 * V_6 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
struct V_11 * V_12 = V_6 -> V_10 -> V_13 ;
struct V_51 * V_285 ;
F_107 ( V_6 , V_1 -> V_31 ) ;
if ( F_108 ( & V_6 -> V_286 ) == false )
goto V_287;
if ( V_12 -> V_288 != NULL ) {
V_285 = F_104 ( V_6 -> V_10 ,
V_12 -> V_288 ) ;
if ( V_285 != NULL ) {
V_285 -> type = ( V_289 |
V_290 ) ;
F_105 ( V_6 , V_285 ) ;
}
}
V_287:
F_109 (newmode, &connector->probed_modes, head) {
if ( V_285 -> type & V_289 ) {
V_1 -> V_98 =
F_104 ( V_6 -> V_10 , V_285 ) ;
V_1 -> V_97 = true ;
break;
}
}
}
static int F_110 ( struct V_5 * V_6 )
{
struct V_7 * V_7 = F_5 ( V_6 ) ;
if ( F_111 ( V_7 ) )
F_103 ( V_6 ) ;
else if ( F_112 ( V_7 ) )
F_106 ( V_6 ) ;
else
F_100 ( V_6 ) ;
return ! F_108 ( & V_6 -> V_286 ) ;
}
static void
F_113 ( struct V_5 * V_6 )
{
struct V_7 * V_7 = F_5 ( V_6 ) ;
struct V_9 * V_10 = V_6 -> V_10 ;
if ( V_7 -> V_291 )
F_114 ( V_10 , V_7 -> V_291 ) ;
if ( V_7 -> V_292 )
F_114 ( V_10 , V_7 -> V_292 ) ;
if ( V_7 -> V_293 )
F_114 ( V_10 , V_7 -> V_293 ) ;
if ( V_7 -> V_294 )
F_114 ( V_10 , V_7 -> V_294 ) ;
if ( V_7 -> V_295 )
F_114 ( V_10 , V_7 -> V_295 ) ;
if ( V_7 -> V_296 )
F_114 ( V_10 , V_7 -> V_296 ) ;
if ( V_7 -> V_297 )
F_114 ( V_10 , V_7 -> V_297 ) ;
if ( V_7 -> V_298 )
F_114 ( V_10 , V_7 -> V_298 ) ;
if ( V_7 -> V_299 )
F_114 ( V_10 , V_7 -> V_299 ) ;
if ( V_7 -> V_300 )
F_114 ( V_10 , V_7 -> V_300 ) ;
if ( V_7 -> V_301 )
F_114 ( V_10 , V_7 -> V_301 ) ;
if ( V_7 -> V_302 )
F_114 ( V_10 , V_7 -> V_302 ) ;
if ( V_7 -> V_303 )
F_114 ( V_10 , V_7 -> V_303 ) ;
if ( V_7 -> V_304 )
F_114 ( V_10 , V_7 -> V_304 ) ;
if ( V_7 -> V_305 )
F_114 ( V_10 , V_7 -> V_305 ) ;
if ( V_7 -> V_306 )
F_114 ( V_10 , V_7 -> V_306 ) ;
if ( V_7 -> V_307 )
F_114 ( V_10 , V_7 -> V_307 ) ;
}
static void F_115 ( struct V_5 * V_6 )
{
struct V_7 * V_7 = F_5 ( V_6 ) ;
if ( V_7 -> V_308 )
F_114 ( V_6 -> V_10 ,
V_7 -> V_308 ) ;
F_113 ( V_6 ) ;
F_116 ( V_6 ) ;
F_117 ( V_6 ) ;
F_20 ( V_7 ) ;
}
static bool F_118 ( struct V_5 * V_6 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
struct V_258 * V_258 ;
bool V_309 = false ;
if ( ! V_1 -> V_208 )
return false ;
V_258 = F_88 ( V_6 ) ;
if ( V_258 != NULL && V_258 -> V_265 & V_266 )
V_309 = F_94 ( V_258 ) ;
F_20 ( V_258 ) ;
return V_309 ;
}
static int
F_119 ( struct V_5 * V_6 ,
struct V_310 * V_311 ,
T_7 V_8 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
struct V_7 * V_7 = F_5 ( V_6 ) ;
struct V_11 * V_12 = V_6 -> V_10 -> V_13 ;
T_4 V_312 ;
T_5 V_32 ;
int V_30 ;
V_30 = F_120 ( & V_6 -> V_4 , V_311 , V_8 ) ;
if ( V_30 )
return V_30 ;
if ( V_311 == V_12 -> V_313 ) {
int V_16 = V_8 ;
bool V_309 ;
if ( V_16 == V_7 -> V_269 )
return 0 ;
V_7 -> V_269 = V_16 ;
if ( V_16 == V_270 )
V_309 = F_118 ( V_6 ) ;
else
V_309 = ( V_16 == V_271 ) ;
if ( V_309 == V_1 -> V_214 )
return 0 ;
V_1 -> V_214 = V_309 ;
goto V_314;
}
if ( V_311 == V_12 -> V_315 ) {
switch ( V_8 ) {
case V_316 :
V_1 -> V_184 = true ;
break;
case V_317 :
V_1 -> V_184 = false ;
V_1 -> V_186 = 0 ;
break;
case V_318 :
V_1 -> V_184 = false ;
V_1 -> V_186 = V_187 ;
break;
default:
return - V_319 ;
}
goto V_314;
}
#define F_121 ( V_35 , T_8 ) \
if (intel_sdvo_connector->name == property) { \
if (intel_sdvo_connector->cur_##name == temp_value) return 0; \
if (intel_sdvo_connector->max_##name < temp_value) return -EINVAL; \
cmd = SDVO_CMD_SET_##NAME; \
intel_sdvo_connector->cur_##name = temp_value; \
goto set_value; \
}
if ( V_311 == V_7 -> V_308 ) {
if ( V_8 >= V_320 )
return - V_319 ;
if ( V_1 -> V_176 ==
V_7 -> V_321 [ V_8 ] )
return 0 ;
V_1 -> V_176 = V_7 -> V_321 [ V_8 ] ;
goto V_314;
} else if ( F_122 ( V_7 ) ) {
V_312 = V_8 ;
if ( V_7 -> V_291 == V_311 ) {
F_120 ( & V_6 -> V_4 ,
V_7 -> V_292 , V_8 ) ;
if ( V_7 -> V_322 == V_312 )
return 0 ;
V_7 -> V_322 = V_312 ;
V_7 -> V_323 = V_312 ;
V_312 = V_7 -> V_324 -
V_7 -> V_322 ;
V_32 = V_325 ;
goto V_326;
} else if ( V_7 -> V_292 == V_311 ) {
F_120 ( & V_6 -> V_4 ,
V_7 -> V_291 , V_8 ) ;
if ( V_7 -> V_323 == V_312 )
return 0 ;
V_7 -> V_322 = V_312 ;
V_7 -> V_323 = V_312 ;
V_312 = V_7 -> V_324 -
V_7 -> V_322 ;
V_32 = V_325 ;
goto V_326;
} else if ( V_7 -> V_293 == V_311 ) {
F_120 ( & V_6 -> V_4 ,
V_7 -> V_294 , V_8 ) ;
if ( V_7 -> V_327 == V_312 )
return 0 ;
V_7 -> V_327 = V_312 ;
V_7 -> V_328 = V_312 ;
V_312 = V_7 -> V_329 -
V_7 -> V_327 ;
V_32 = V_330 ;
goto V_326;
} else if ( V_7 -> V_294 == V_311 ) {
F_120 ( & V_6 -> V_4 ,
V_7 -> V_293 , V_8 ) ;
if ( V_7 -> V_328 == V_312 )
return 0 ;
V_7 -> V_327 = V_312 ;
V_7 -> V_328 = V_312 ;
V_312 = V_7 -> V_329 -
V_7 -> V_327 ;
V_32 = V_330 ;
goto V_326;
}
F_121 (hpos, HPOS)
F_121 (vpos, VPOS)
F_121 (saturation, SATURATION)
F_121 (contrast, CONTRAST)
F_121 (hue, HUE)
F_121 (brightness, BRIGHTNESS)
F_121 (sharpness, SHARPNESS)
F_121 (flicker_filter, FLICKER_FILTER)
F_121 (flicker_filter_2d, FLICKER_FILTER_2D)
F_121 (flicker_filter_adaptive, FLICKER_FILTER_ADAPTIVE)
F_121 (tv_chroma_filter, TV_CHROMA_FILTER)
F_121 (tv_luma_filter, TV_LUMA_FILTER)
F_121 (dot_crawl, DOT_CRAWL)
}
return - V_319 ;
V_326:
if ( ! F_26 ( V_1 , V_32 , & V_312 , 2 ) )
return - V_331 ;
V_314:
if ( V_1 -> V_4 . V_4 . V_189 )
F_123 ( V_1 -> V_4 . V_4 . V_189 ) ;
return 0 ;
#undef F_121
}
static void F_124 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
if ( V_1 -> V_98 != NULL )
F_125 ( V_3 -> V_10 ,
V_1 -> V_98 ) ;
F_126 ( & V_1 -> V_260 ) ;
F_127 ( V_3 ) ;
}
static void
F_128 ( struct V_1 * V_259 )
{
T_4 V_332 = 0 ;
unsigned int V_333 ;
switch ( V_259 -> V_334 ) {
case V_335 :
V_332 |= V_335 ;
case V_336 :
V_332 |= V_336 ;
case V_337 :
V_332 |= V_337 ;
case V_338 :
V_332 |= V_338 ;
case V_339 :
V_332 |= V_339 ;
case V_340 :
V_332 |= V_340 ;
break;
}
V_332 &= V_259 -> V_240 . V_253 ;
V_333 = F_87 ( V_332 ) ;
if ( V_333 > 3 )
V_333 = 3 ;
V_259 -> V_53 = 1 << V_333 ;
}
static void
F_129 ( struct V_11 * V_12 ,
struct V_1 * V_259 , T_1 V_341 )
{
struct V_342 * V_343 ;
if ( V_259 -> V_344 )
V_343 = & ( V_12 -> V_345 [ 0 ] ) ;
else
V_343 = & ( V_12 -> V_345 [ 1 ] ) ;
if ( V_343 -> V_346 )
V_259 -> V_53 = 1 << ( ( V_343 -> V_347 & 0xf0 ) >> 4 ) ;
else
F_128 ( V_259 ) ;
}
static void
F_130 ( struct V_11 * V_12 ,
struct V_1 * V_259 , T_1 V_341 )
{
struct V_342 * V_343 ;
T_2 V_348 ;
if ( V_259 -> V_344 )
V_343 = & V_12 -> V_345 [ 0 ] ;
else
V_343 = & V_12 -> V_345 [ 1 ] ;
if ( V_343 -> V_346 && F_131 ( V_343 -> V_349 ) )
V_348 = V_343 -> V_349 ;
else
V_348 = V_350 ;
V_259 -> V_31 = F_91 ( V_12 , V_348 ) ;
F_132 ( V_259 -> V_31 , true ) ;
}
static void
F_133 ( struct V_1 * V_259 )
{
F_132 ( V_259 -> V_31 , false ) ;
}
static bool
F_134 ( struct V_1 * V_1 , int V_351 )
{
return F_45 ( V_1 ) ;
}
static T_2
F_135 ( struct V_9 * V_10 , struct V_1 * V_259 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_342 * V_352 , * V_353 ;
if ( V_259 -> V_344 ) {
V_352 = & V_12 -> V_345 [ 0 ] ;
V_353 = & V_12 -> V_345 [ 1 ] ;
} else {
V_352 = & V_12 -> V_345 [ 1 ] ;
V_353 = & V_12 -> V_345 [ 0 ] ;
}
if ( V_352 -> V_25 )
return V_352 -> V_25 ;
if ( V_353 -> V_25 ) {
if ( V_353 -> V_25 == 0x70 )
return 0x72 ;
else
return 0x70 ;
}
if ( V_259 -> V_344 )
return 0x70 ;
else
return 0x72 ;
}
static void
F_136 ( struct V_7 * V_6 ,
struct V_1 * V_3 )
{
F_137 ( V_3 -> V_4 . V_4 . V_10 ,
& V_6 -> V_4 . V_4 ,
& V_354 ,
V_6 -> V_4 . V_4 . V_355 ) ;
F_138 ( & V_6 -> V_4 . V_4 ,
& V_356 ) ;
V_6 -> V_4 . V_4 . V_357 = 1 ;
V_6 -> V_4 . V_4 . V_358 = 0 ;
V_6 -> V_4 . V_4 . V_359 . V_360 = V_361 ;
V_6 -> V_4 . V_362 = F_69 ;
F_139 ( & V_6 -> V_4 , & V_3 -> V_4 ) ;
F_140 ( & V_6 -> V_4 . V_4 ) ;
}
static void
F_141 ( struct V_1 * V_1 ,
struct V_7 * V_6 )
{
struct V_9 * V_10 = V_6 -> V_4 . V_4 . V_10 ;
F_142 ( & V_6 -> V_4 . V_4 ) ;
if ( F_61 ( V_10 ) -> V_205 >= 4 && F_143 ( V_10 ) ) {
F_144 ( & V_6 -> V_4 . V_4 ) ;
V_1 -> V_184 = true ;
}
}
static bool
F_145 ( struct V_1 * V_1 , int V_351 )
{
struct V_2 * V_3 = & V_1 -> V_4 . V_4 ;
struct V_5 * V_6 ;
struct V_222 * V_222 = F_146 ( V_3 ) ;
struct V_219 * V_219 ;
struct V_7 * V_7 ;
V_7 = F_18 ( sizeof( struct V_7 ) , V_37 ) ;
if ( ! V_7 )
return false ;
if ( V_351 == 0 ) {
V_1 -> V_334 |= V_338 ;
V_7 -> V_221 = V_338 ;
} else if ( V_351 == 1 ) {
V_1 -> V_334 |= V_337 ;
V_7 -> V_221 = V_337 ;
}
V_219 = & V_7 -> V_4 ;
V_6 = & V_219 -> V_4 ;
if ( F_84 ( V_1 ) &
V_7 -> V_221 ) {
V_6 -> V_363 = V_364 ;
V_1 -> V_257 |= V_7 -> V_221 ;
V_222 -> V_365 = F_85 ;
F_85 ( V_222 ) ;
} else {
V_6 -> V_363 = V_366 | V_367 ;
}
V_3 -> V_368 = V_369 ;
V_6 -> V_355 = V_370 ;
if ( F_134 ( V_1 , V_351 ) ) {
V_6 -> V_355 = V_371 ;
V_1 -> V_208 = true ;
}
F_136 ( V_7 , V_1 ) ;
if ( V_1 -> V_208 )
F_141 ( V_1 , V_7 ) ;
return true ;
}
static bool
F_147 ( struct V_1 * V_1 , int type )
{
struct V_2 * V_3 = & V_1 -> V_4 . V_4 ;
struct V_5 * V_6 ;
struct V_219 * V_219 ;
struct V_7 * V_7 ;
V_7 = F_18 ( sizeof( struct V_7 ) , V_37 ) ;
if ( ! V_7 )
return false ;
V_219 = & V_7 -> V_4 ;
V_6 = & V_219 -> V_4 ;
V_3 -> V_368 = V_372 ;
V_6 -> V_355 = V_373 ;
V_1 -> V_334 |= type ;
V_7 -> V_221 = type ;
V_1 -> V_183 = true ;
V_1 -> V_4 . V_276 = true ;
F_136 ( V_7 , V_1 ) ;
if ( ! F_148 ( V_1 , V_7 , type ) )
goto V_374;
if ( ! F_149 ( V_1 , V_7 ) )
goto V_374;
return true ;
V_374:
F_115 ( V_6 ) ;
return false ;
}
static bool
F_150 ( struct V_1 * V_1 , int V_351 )
{
struct V_2 * V_3 = & V_1 -> V_4 . V_4 ;
struct V_5 * V_6 ;
struct V_219 * V_219 ;
struct V_7 * V_7 ;
V_7 = F_18 ( sizeof( struct V_7 ) , V_37 ) ;
if ( ! V_7 )
return false ;
V_219 = & V_7 -> V_4 ;
V_6 = & V_219 -> V_4 ;
V_6 -> V_363 = V_366 ;
V_3 -> V_368 = V_375 ;
V_6 -> V_355 = V_376 ;
if ( V_351 == 0 ) {
V_1 -> V_334 |= V_340 ;
V_7 -> V_221 = V_340 ;
} else if ( V_351 == 1 ) {
V_1 -> V_334 |= V_339 ;
V_7 -> V_221 = V_339 ;
}
F_136 ( V_7 ,
V_1 ) ;
return true ;
}
static bool
F_151 ( struct V_1 * V_1 , int V_351 )
{
struct V_2 * V_3 = & V_1 -> V_4 . V_4 ;
struct V_5 * V_6 ;
struct V_219 * V_219 ;
struct V_7 * V_7 ;
V_7 = F_18 ( sizeof( struct V_7 ) , V_37 ) ;
if ( ! V_7 )
return false ;
V_219 = & V_7 -> V_4 ;
V_6 = & V_219 -> V_4 ;
V_3 -> V_368 = V_377 ;
V_6 -> V_355 = V_378 ;
if ( V_351 == 0 ) {
V_1 -> V_334 |= V_336 ;
V_7 -> V_221 = V_336 ;
} else if ( V_351 == 1 ) {
V_1 -> V_334 |= V_335 ;
V_7 -> V_221 = V_335 ;
}
F_136 ( V_7 , V_1 ) ;
if ( ! F_149 ( V_1 , V_7 ) )
goto V_374;
return true ;
V_374:
F_115 ( V_6 ) ;
return false ;
}
static bool
F_152 ( struct V_1 * V_1 , T_4 V_26 )
{
V_1 -> V_183 = false ;
V_1 -> V_4 . V_276 = false ;
V_1 -> V_97 = false ;
if ( V_26 & V_338 )
if ( ! F_145 ( V_1 , 0 ) )
return false ;
if ( ( V_26 & V_379 ) == V_379 )
if ( ! F_145 ( V_1 , 1 ) )
return false ;
if ( V_26 & V_380 )
if ( ! F_147 ( V_1 , V_380 ) )
return false ;
if ( V_26 & V_381 )
if ( ! F_147 ( V_1 , V_381 ) )
return false ;
if ( V_26 & V_382 )
if ( ! F_147 ( V_1 , V_382 ) )
return false ;
if ( V_26 & V_340 )
if ( ! F_150 ( V_1 , 0 ) )
return false ;
if ( ( V_26 & V_383 ) == V_383 )
if ( ! F_150 ( V_1 , 1 ) )
return false ;
if ( V_26 & V_336 )
if ( ! F_151 ( V_1 , 0 ) )
return false ;
if ( ( V_26 & V_278 ) == V_278 )
if ( ! F_151 ( V_1 , 1 ) )
return false ;
if ( ( V_26 & V_384 ) == 0 ) {
unsigned char V_385 [ 2 ] ;
V_1 -> V_334 = 0 ;
memcpy ( V_385 , & V_1 -> V_240 . V_253 , 2 ) ;
F_12 ( L_34 ,
F_14 ( V_1 ) ,
V_385 [ 0 ] , V_385 [ 1 ] ) ;
return false ;
}
V_1 -> V_4 . V_386 = ( 1 << 0 ) | ( 1 << 1 ) | ( 1 << 2 ) ;
return true ;
}
static void F_153 ( struct V_1 * V_1 )
{
struct V_9 * V_10 = V_1 -> V_4 . V_4 . V_10 ;
struct V_5 * V_6 , * V_149 ;
F_154 (connector, tmp,
&dev->mode_config.connector_list, head) {
if ( F_4 ( V_6 ) == & V_1 -> V_4 )
F_115 ( V_6 ) ;
}
}
static bool F_148 ( struct V_1 * V_1 ,
struct V_7 * V_7 ,
int type )
{
struct V_9 * V_10 = V_1 -> V_4 . V_4 . V_10 ;
struct V_173 V_174 ;
T_6 V_175 , V_16 ;
if ( ! F_35 ( V_1 , type ) )
return false ;
F_30 ( sizeof( V_174 ) != 6 ) ;
if ( ! F_27 ( V_1 ,
V_387 ,
& V_174 , sizeof( V_174 ) ) )
return false ;
memcpy ( & V_175 , & V_174 , V_84 ( sizeof( V_175 ) , sizeof( V_174 ) ) ) ;
if ( V_175 == 0 )
return false ;
V_7 -> V_388 = 0 ;
for ( V_16 = 0 ; V_16 < V_320 ; V_16 ++ )
if ( V_175 & ( 1 << V_16 ) )
V_7 -> V_321 [ V_7 -> V_388 ++ ] = V_16 ;
V_7 -> V_308 =
F_155 ( V_10 , V_389 ,
L_35 , V_7 -> V_388 ) ;
if ( ! V_7 -> V_308 )
return false ;
for ( V_16 = 0 ; V_16 < V_7 -> V_388 ; V_16 ++ )
F_156 (
V_7 -> V_308 , V_16 ,
V_16 , V_390 [ V_7 -> V_321 [ V_16 ] ] ) ;
V_1 -> V_176 = V_7 -> V_321 [ 0 ] ;
F_157 ( & V_7 -> V_4 . V_4 . V_4 ,
V_7 -> V_308 , 0 ) ;
return true ;
}
static bool
F_158 ( struct V_1 * V_1 ,
struct V_7 * V_7 ,
struct V_391 V_392 )
{
struct V_9 * V_10 = V_1 -> V_4 . V_4 . V_10 ;
struct V_5 * V_6 = & V_7 -> V_4 . V_4 ;
T_4 V_42 , V_393 [ 2 ] ;
if ( V_392 . V_394 ) {
if ( ! F_27 ( V_1 ,
V_395 ,
& V_393 , 4 ) )
return false ;
if ( ! F_27 ( V_1 ,
V_396 ,
& V_42 , 2 ) )
return false ;
V_7 -> V_324 = V_393 [ 0 ] ;
V_7 -> V_322 = V_393 [ 0 ] - V_42 ;
V_7 -> V_323 = V_7 -> V_322 ;
V_7 -> V_291 =
F_159 ( V_10 , 0 , L_36 , 0 , V_393 [ 0 ] ) ;
if ( ! V_7 -> V_291 )
return false ;
F_157 ( & V_6 -> V_4 ,
V_7 -> V_291 ,
V_7 -> V_322 ) ;
V_7 -> V_292 =
F_159 ( V_10 , 0 , L_37 , 0 , V_393 [ 0 ] ) ;
if ( ! V_7 -> V_292 )
return false ;
F_157 ( & V_6 -> V_4 ,
V_7 -> V_292 ,
V_7 -> V_323 ) ;
F_12 ( L_38
L_39 ,
V_393 [ 0 ] , V_393 [ 1 ] , V_42 ) ;
}
if ( V_392 . V_397 ) {
if ( ! F_27 ( V_1 ,
V_398 ,
& V_393 , 4 ) )
return false ;
if ( ! F_27 ( V_1 ,
V_399 ,
& V_42 , 2 ) )
return false ;
V_7 -> V_329 = V_393 [ 0 ] ;
V_7 -> V_327 = V_393 [ 0 ] - V_42 ;
V_7 -> V_328 = V_7 -> V_327 ;
V_7 -> V_293 =
F_159 ( V_10 , 0 ,
L_40 , 0 , V_393 [ 0 ] ) ;
if ( ! V_7 -> V_293 )
return false ;
F_157 ( & V_6 -> V_4 ,
V_7 -> V_293 ,
V_7 -> V_327 ) ;
V_7 -> V_294 =
F_159 ( V_10 , 0 ,
L_41 , 0 , V_393 [ 0 ] ) ;
if ( ! V_7 -> V_294 )
return false ;
F_157 ( & V_6 -> V_4 ,
V_7 -> V_294 ,
V_7 -> V_328 ) ;
F_12 ( L_42
L_39 ,
V_393 [ 0 ] , V_393 [ 1 ] , V_42 ) ;
}
F_160 ( V_295 , V_400 ) ;
F_160 ( V_296 , V_401 ) ;
F_160 ( V_297 , V_402 ) ;
F_160 ( V_298 , V_403 ) ;
F_160 ( V_299 , V_404 ) ;
F_160 ( V_300 , V_405 ) ;
F_160 ( V_307 , V_406 ) ;
F_160 ( V_301 , V_407 ) ;
F_160 ( V_303 , V_408 ) ;
F_160 ( V_302 , V_409 ) ;
F_160 ( V_305 , V_410 ) ;
F_160 ( V_304 , V_411 ) ;
if ( V_392 . V_306 ) {
if ( ! F_27 ( V_1 , V_412 , & V_42 , 2 ) )
return false ;
V_7 -> V_413 = 1 ;
V_7 -> V_414 = V_42 & 0x1 ;
V_7 -> V_306 =
F_159 ( V_10 , 0 , L_43 , 0 , 1 ) ;
if ( ! V_7 -> V_306 )
return false ;
F_157 ( & V_6 -> V_4 ,
V_7 -> V_306 ,
V_7 -> V_414 ) ;
F_12 ( L_44 , V_42 ) ;
}
return true ;
}
static bool
F_161 ( struct V_1 * V_1 ,
struct V_7 * V_7 ,
struct V_391 V_392 )
{
struct V_9 * V_10 = V_1 -> V_4 . V_4 . V_10 ;
struct V_5 * V_6 = & V_7 -> V_4 . V_4 ;
T_4 V_42 , V_393 [ 2 ] ;
F_160 ( V_307 , V_406 ) ;
return true ;
}
static bool F_149 ( struct V_1 * V_1 ,
struct V_7 * V_7 )
{
union {
struct V_391 V_281 ;
T_4 V_42 ;
} V_392 ;
F_30 ( sizeof( V_392 ) != 2 ) ;
V_392 . V_42 = 0 ;
F_27 ( V_1 ,
V_415 ,
& V_392 , sizeof( V_392 ) ) ;
if ( V_392 . V_42 == 0 ) {
F_12 ( L_45 ) ;
return true ;
}
if ( F_111 ( V_7 ) )
return F_158 ( V_1 , V_7 , V_392 . V_281 ) ;
else if ( F_112 ( V_7 ) )
return F_161 ( V_1 , V_7 , V_392 . V_281 ) ;
else
return true ;
}
static int F_162 ( struct V_416 * V_417 ,
struct V_23 * V_24 ,
int V_418 )
{
struct V_1 * V_259 = V_417 -> V_419 ;
if ( ! F_25 ( V_259 , V_259 -> V_53 ) )
return - V_331 ;
return V_259 -> V_31 -> V_420 -> V_421 ( V_259 -> V_31 , V_24 , V_418 ) ;
}
static T_1 F_163 ( struct V_416 * V_417 )
{
struct V_1 * V_259 = V_417 -> V_419 ;
return V_259 -> V_31 -> V_420 -> V_422 ( V_259 -> V_31 ) ;
}
static bool
F_164 ( struct V_1 * V_259 ,
struct V_9 * V_10 )
{
V_259 -> V_260 . V_423 = V_424 ;
V_259 -> V_260 . V_425 = V_426 ;
snprintf ( V_259 -> V_260 . V_35 , V_427 , L_46 ) ;
V_259 -> V_260 . V_10 . V_428 = & V_10 -> V_429 -> V_10 ;
V_259 -> V_260 . V_419 = V_259 ;
V_259 -> V_260 . V_420 = & V_430 ;
return F_165 ( & V_259 -> V_260 ) == 0 ;
}
bool F_166 ( struct V_9 * V_10 , T_6 V_17 , bool V_344 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_222 * V_222 ;
struct V_1 * V_1 ;
T_1 V_431 ;
int V_16 ;
V_1 = F_18 ( sizeof( struct V_1 ) , V_37 ) ;
if ( ! V_1 )
return false ;
V_1 -> V_17 = V_17 ;
V_1 -> V_344 = V_344 ;
V_1 -> V_25 = F_135 ( V_10 , V_1 ) >> 1 ;
F_130 ( V_12 , V_1 , V_17 ) ;
if ( ! F_164 ( V_1 , V_10 ) )
goto V_432;
V_222 = & V_1 -> V_4 ;
V_222 -> type = V_433 ;
F_167 ( V_10 , & V_222 -> V_4 , & V_434 , 0 ) ;
for ( V_16 = 0 ; V_16 < 0x40 ; V_16 ++ ) {
T_2 V_435 ;
if ( ! F_10 ( V_1 , V_16 , & V_435 ) ) {
F_12 ( L_47 ,
F_14 ( V_1 ) ) ;
goto V_374;
}
}
V_431 = 0 ;
if ( F_168 ( V_10 ) ) {
V_431 = V_1 -> V_344 ?
V_436 : V_437 ;
} else if ( F_169 ( V_10 ) ) {
V_431 = V_1 -> V_344 ?
V_438 : V_439 ;
} else {
V_431 = V_1 -> V_344 ?
V_440 : V_441 ;
}
F_170 ( & V_222 -> V_4 , & V_442 ) ;
V_222 -> V_443 = F_74 ;
V_222 -> V_444 = F_78 ;
V_222 -> V_362 = F_70 ;
if ( ! F_83 ( V_1 , & V_1 -> V_240 ) )
goto V_374;
if ( F_152 ( V_1 ,
V_1 -> V_240 . V_253 ) != true ) {
F_12 ( L_48 ,
F_14 ( V_1 ) ) ;
goto V_445;
}
V_1 -> V_4 . V_446 = false ;
if ( V_1 -> V_257 )
V_12 -> V_447 |= V_431 ;
F_129 ( V_12 , V_1 , V_17 ) ;
if ( ! F_28 ( V_1 ) )
goto V_445;
if ( ! F_34 ( V_1 ,
& V_1 -> V_233 ,
& V_1 -> V_235 ) )
goto V_445;
F_12 ( L_49
L_50
L_51
L_52 ,
F_14 ( V_1 ) ,
V_1 -> V_240 . V_242 , V_1 -> V_240 . V_243 ,
V_1 -> V_240 . V_244 ,
V_1 -> V_233 / 1000 ,
V_1 -> V_235 / 1000 ,
( V_1 -> V_240 . V_247 & 0x1 ) ? 'Y' : 'N' ,
( V_1 -> V_240 . V_247 & 0x2 ) ? 'Y' : 'N' ,
V_1 -> V_240 . V_253 &
( V_338 | V_340 ) ? 'Y' : 'N' ,
V_1 -> V_240 . V_253 &
( V_337 | V_339 ) ? 'Y' : 'N' ) ;
return true ;
V_445:
F_153 ( V_1 ) ;
V_374:
F_171 ( & V_222 -> V_4 ) ;
F_126 ( & V_1 -> V_260 ) ;
V_432:
F_133 ( V_1 ) ;
F_20 ( V_1 ) ;
return false ;
}
