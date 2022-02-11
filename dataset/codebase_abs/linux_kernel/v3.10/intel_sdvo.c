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
static void F_43 ( struct V_51 * V_52 ,
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
static bool F_44 ( struct V_1 * V_1 )
{
struct V_139 V_140 ;
F_30 ( sizeof( V_140 ) != 2 ) ;
return F_27 ( V_1 ,
V_141 ,
& V_140 , sizeof( V_140 ) ) ;
}
static bool F_45 ( struct V_1 * V_1 ,
T_5 V_52 )
{
return F_26 ( V_1 , V_142 , & V_52 , 1 ) ;
}
static bool F_46 ( struct V_1 * V_1 ,
T_5 V_52 )
{
return F_26 ( V_1 , V_143 , & V_52 , 1 ) ;
}
static bool F_47 ( struct V_1 * V_1 ,
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
memcpy ( V_149 , V_55 + V_16 , F_48 ( unsigned , 8 , V_146 - V_16 ) ) ;
if ( ! F_26 ( V_1 ,
V_152 ,
V_149 , 8 ) )
return false ;
}
return F_26 ( V_1 ,
V_153 ,
& V_145 , 1 ) ;
}
static bool F_49 ( struct V_1 * V_1 ,
const struct V_51 * V_154 )
{
struct V_155 V_156 = {
. type = V_157 ,
. V_158 = V_159 ,
. V_27 = V_160 ,
} ;
T_5 V_161 [ 4 + sizeof( V_156 . V_162 . V_163 ) ] ;
struct V_164 * V_164 = F_50 ( V_1 -> V_4 . V_4 . V_165 ) ;
if ( V_1 -> V_166 ) {
if ( V_164 -> V_167 . V_168 )
V_156 . V_162 . V_163 . V_169 |= V_170 ;
else
V_156 . V_162 . V_163 . V_169 |= V_171 ;
}
V_156 . V_162 . V_163 . V_172 = F_51 ( V_154 ) ;
F_52 ( & V_156 ) ;
memcpy ( V_161 , & V_156 , 3 ) ;
V_161 [ 3 ] = V_156 . V_173 ;
memcpy ( & V_161 [ 4 ] , & V_156 . V_162 , sizeof( V_156 . V_162 . V_163 ) ) ;
return F_47 ( V_1 , V_174 ,
V_175 ,
V_161 , sizeof( V_161 ) ) ;
}
static bool F_53 ( struct V_1 * V_1 )
{
struct V_176 V_177 ;
T_6 V_178 ;
V_178 = 1 << V_1 -> V_179 ;
memset ( & V_177 , 0 , sizeof( V_177 ) ) ;
memcpy ( & V_177 , & V_178 , V_84 ( sizeof( V_177 ) , sizeof( V_178 ) ) ) ;
F_30 ( sizeof( V_177 ) != 6 ) ;
return F_26 ( V_1 ,
V_180 ,
& V_177 , sizeof( V_177 ) ) ;
}
static bool
F_54 ( struct V_1 * V_1 ,
const struct V_51 * V_52 )
{
struct V_87 V_181 ;
if ( ! F_35 ( V_1 ,
V_1 -> V_182 ) )
return false ;
F_42 ( & V_181 , V_52 ) ;
if ( ! F_38 ( V_1 , & V_181 ) )
return false ;
return true ;
}
static bool
F_55 ( struct V_1 * V_1 ,
const struct V_51 * V_52 ,
struct V_51 * V_154 )
{
struct V_87 V_183 ;
if ( ! F_28 ( V_1 ) )
return false ;
if ( ! F_39 ( V_1 ,
V_52 -> clock / 10 ,
V_52 -> V_99 ,
V_52 -> V_100 ) )
return false ;
if ( ! F_40 ( V_1 ,
& V_183 ) )
return false ;
F_43 ( V_154 , & V_183 ) ;
V_1 -> V_184 = V_183 . V_90 . V_136 ;
return true ;
}
static bool F_56 ( struct V_185 * V_3 ,
struct V_186 * V_187 )
{
struct V_1 * V_1 = F_1 ( & V_3 -> V_4 ) ;
struct V_51 * V_154 = & V_187 -> V_154 ;
struct V_51 * V_52 = & V_187 -> V_188 ;
F_12 ( L_15 ) ;
V_187 -> V_189 = 8 * 3 ;
if ( F_57 ( V_3 -> V_4 . V_10 ) )
V_187 -> V_190 = true ;
if ( V_1 -> V_191 ) {
if ( ! F_54 ( V_1 , V_52 ) )
return false ;
( void ) F_55 ( V_1 ,
V_52 ,
V_154 ) ;
} else if ( V_1 -> V_97 ) {
if ( ! F_54 ( V_1 ,
V_1 -> V_98 ) )
return false ;
( void ) F_55 ( V_1 ,
V_52 ,
V_154 ) ;
}
V_187 -> V_192 =
F_24 ( V_154 ) ;
V_154 -> clock *= V_187 -> V_192 ;
if ( V_1 -> V_193 ) {
if ( V_1 -> V_194 &&
F_51 ( V_154 ) > 1 )
V_1 -> V_195 = V_196 ;
else
V_1 -> V_195 = 0 ;
}
if ( V_1 -> V_195 )
V_187 -> V_168 = true ;
return true ;
}
static void F_58 ( struct V_185 * V_185 )
{
struct V_9 * V_10 = V_185 -> V_4 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_197 * V_165 = V_185 -> V_4 . V_165 ;
struct V_164 * V_164 = F_50 ( V_165 ) ;
struct V_51 * V_154 =
& V_164 -> V_167 . V_154 ;
struct V_51 * V_52 = & V_164 -> V_167 . V_188 ;
struct V_1 * V_1 = F_1 ( & V_185 -> V_4 ) ;
T_1 V_198 ;
struct V_199 V_200 ;
struct V_87 V_183 , V_181 ;
int V_201 ;
if ( ! V_52 )
return;
V_200 . V_202 = V_1 -> V_182 ;
V_200 . V_203 = 0 ;
F_26 ( V_1 ,
V_204 ,
& V_200 , sizeof( V_200 ) ) ;
if ( ! F_35 ( V_1 ,
V_1 -> V_182 ) )
return;
if ( V_1 -> V_97 )
F_42 ( & V_181 ,
V_1 -> V_98 ) ;
else
F_42 ( & V_181 , V_52 ) ;
if ( ! F_38 ( V_1 , & V_181 ) )
F_59 ( L_16 ,
F_14 ( V_1 ) ) ;
if ( ! F_28 ( V_1 ) )
return;
if ( V_1 -> V_194 ) {
F_45 ( V_1 , V_205 ) ;
F_46 ( V_1 ,
V_206 ) ;
F_49 ( V_1 , V_154 ) ;
} else
F_45 ( V_1 , V_207 ) ;
if ( V_1 -> V_191 &&
! F_53 ( V_1 ) )
return;
F_42 ( & V_183 , V_154 ) ;
if ( V_1 -> V_191 || V_1 -> V_97 )
V_183 . V_90 . V_136 = V_1 -> V_184 ;
if ( ! F_37 ( V_1 , & V_183 ) )
F_59 ( L_17 ,
F_14 ( V_1 ) ) ;
switch ( V_164 -> V_167 . V_192 ) {
default:
case 1 : V_201 = V_208 ; break;
case 2 : V_201 = V_209 ; break;
case 4 : V_201 = V_210 ; break;
}
if ( ! F_41 ( V_1 , V_201 ) )
return;
if ( F_60 ( V_10 ) -> V_211 >= 4 ) {
V_198 = V_212 | V_213 ;
if ( ! F_57 ( V_10 ) && V_1 -> V_214 )
V_198 |= V_1 -> V_195 ;
if ( F_60 ( V_10 ) -> V_211 < 5 )
V_198 |= V_215 ;
} else {
V_198 = F_9 ( V_1 -> V_17 ) ;
switch ( V_1 -> V_17 ) {
case V_19 :
V_198 &= V_216 ;
break;
case V_20 :
V_198 &= V_217 ;
break;
}
V_198 |= ( 9 << 19 ) | V_215 ;
}
if ( F_61 ( V_10 ) >= V_218 )
V_198 |= F_62 ( V_164 -> V_219 ) ;
else
V_198 |= F_63 ( V_164 -> V_219 ) ;
if ( V_1 -> V_220 )
V_198 |= V_221 ;
if ( F_60 ( V_10 ) -> V_211 >= 4 ) {
} else if ( F_64 ( V_10 ) || F_65 ( V_10 ) || F_66 ( V_10 ) ) {
} else {
V_198 |= ( V_164 -> V_167 . V_192 - 1 )
<< V_222 ;
}
if ( V_183 . V_90 . V_136 & V_223 &&
F_60 ( V_10 ) -> V_211 < 5 )
V_198 |= V_224 ;
F_7 ( V_1 , V_198 ) ;
}
static bool F_67 ( struct V_225 * V_6 )
{
struct V_7 * V_7 =
F_5 ( & V_6 -> V_4 ) ;
struct V_1 * V_1 = F_3 ( & V_6 -> V_4 ) ;
T_3 V_226 ;
F_32 ( V_1 , & V_226 ) ;
if ( V_226 & V_7 -> V_227 )
return true ;
else
return false ;
}
static bool F_68 ( struct V_185 * V_3 ,
enum V_219 * V_219 )
{
struct V_9 * V_10 = V_3 -> V_4 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_1 * V_1 = F_1 ( & V_3 -> V_4 ) ;
T_3 V_226 ;
T_1 V_149 ;
V_149 = F_9 ( V_1 -> V_17 ) ;
F_32 ( V_1 , & V_226 ) ;
if ( ! ( V_149 & V_228 ) && ( V_226 == 0 ) )
return false ;
if ( F_69 ( V_10 ) )
* V_219 = F_70 ( V_149 ) ;
else
* V_219 = F_71 ( V_149 ) ;
return true ;
}
static void F_72 ( struct V_185 * V_3 )
{
struct V_11 * V_12 = V_3 -> V_4 . V_10 -> V_13 ;
struct V_1 * V_1 = F_1 ( & V_3 -> V_4 ) ;
T_1 V_229 ;
F_31 ( V_1 , 0 ) ;
if ( 0 )
F_33 ( V_1 ,
V_76 ) ;
V_229 = F_9 ( V_1 -> V_17 ) ;
if ( ( V_229 & V_228 ) != 0 ) {
if ( F_73 ( V_3 -> V_4 . V_10 ) ) {
struct V_197 * V_165 = V_3 -> V_4 . V_165 ;
int V_219 = V_165 ? F_50 ( V_165 ) -> V_219 : - 1 ;
if ( V_229 & V_230 ) {
V_229 &= ~ V_230 ;
F_8 ( V_1 -> V_17 , V_229 ) ;
F_74 ( V_1 -> V_17 ) ;
F_8 ( V_1 -> V_17 , V_229 ) ;
F_74 ( V_1 -> V_17 ) ;
if ( V_165 )
F_75 ( V_3 -> V_4 . V_10 , V_219 ) ;
else
F_22 ( 50 ) ;
}
}
F_7 ( V_1 , V_229 & ~ V_228 ) ;
}
}
static void F_76 ( struct V_185 * V_3 )
{
struct V_9 * V_10 = V_3 -> V_4 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_1 * V_1 = F_1 ( & V_3 -> V_4 ) ;
struct V_164 * V_164 = F_50 ( V_3 -> V_4 . V_165 ) ;
T_1 V_229 ;
bool V_231 , V_232 ;
int V_16 ;
T_2 V_36 ;
V_229 = F_9 ( V_1 -> V_17 ) ;
if ( ( V_229 & V_228 ) == 0 ) {
if ( F_73 ( V_10 ) )
V_229 |= F_63 ( V_164 -> V_219 ) ;
F_7 ( V_1 , V_229 | V_228 ) ;
}
for ( V_16 = 0 ; V_16 < 2 ; V_16 ++ )
F_75 ( V_10 , V_164 -> V_219 ) ;
V_36 = F_29 ( V_1 , & V_231 , & V_232 ) ;
if ( V_36 == V_49 && ! V_231 ) {
F_12 ( L_18
L_19 , F_14 ( V_1 ) ) ;
}
if ( 0 )
F_33 ( V_1 ,
V_71 ) ;
F_31 ( V_1 , V_1 -> V_182 ) ;
}
static void F_77 ( struct V_5 * V_6 , int V_52 )
{
struct V_197 * V_165 ;
struct V_1 * V_1 = F_3 ( V_6 ) ;
if ( V_52 != V_71 )
V_52 = V_76 ;
if ( V_52 == V_6 -> V_233 )
return;
V_6 -> V_233 = V_52 ;
V_165 = V_1 -> V_4 . V_4 . V_165 ;
if ( ! V_165 ) {
V_1 -> V_4 . V_234 = false ;
return;
}
if ( V_52 != V_71 ) {
F_31 ( V_1 , 0 ) ;
if ( 0 )
F_33 ( V_1 , V_52 ) ;
V_1 -> V_4 . V_234 = false ;
F_78 ( V_165 ) ;
} else {
V_1 -> V_4 . V_234 = true ;
F_78 ( V_165 ) ;
if ( 0 )
F_33 ( V_1 , V_52 ) ;
F_31 ( V_1 , V_1 -> V_182 ) ;
}
F_79 ( V_6 -> V_10 ) ;
}
static int F_80 ( struct V_5 * V_6 ,
struct V_51 * V_52 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
if ( V_52 -> V_26 & V_235 )
return V_236 ;
if ( V_1 -> V_237 > V_52 -> clock )
return V_238 ;
if ( V_1 -> V_239 < V_52 -> clock )
return V_240 ;
if ( V_1 -> V_97 ) {
if ( V_52 -> V_99 > V_1 -> V_98 -> V_99 )
return V_241 ;
if ( V_52 -> V_100 > V_1 -> V_98 -> V_100 )
return V_241 ;
}
return V_242 ;
}
static bool F_81 ( struct V_1 * V_1 , struct V_243 * V_244 )
{
F_30 ( sizeof( * V_244 ) != 8 ) ;
if ( ! F_27 ( V_1 ,
V_245 ,
V_244 , sizeof( * V_244 ) ) )
return false ;
F_12 ( L_20
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
L_31
L_32 ,
V_244 -> V_246 ,
V_244 -> V_247 ,
V_244 -> V_248 ,
V_244 -> V_249 ,
V_244 -> V_250 ,
V_244 -> V_251 ,
V_244 -> V_252 ,
V_244 -> V_253 ,
V_244 -> V_254 ,
V_244 -> V_255 ,
V_244 -> V_256 ,
V_244 -> V_257 ) ;
return true ;
}
static T_4 F_82 ( struct V_1 * V_1 )
{
struct V_9 * V_10 = V_1 -> V_4 . V_4 . V_10 ;
T_4 V_258 ;
if ( F_64 ( V_10 ) || F_65 ( V_10 ) )
return 0 ;
if ( ! F_27 ( V_1 , V_259 ,
& V_258 , sizeof( V_258 ) ) )
return 0 ;
return V_258 ;
}
static void F_83 ( struct V_185 * V_3 )
{
struct V_1 * V_1 = F_1 ( & V_3 -> V_4 ) ;
F_17 ( V_1 , V_260 ,
& V_1 -> V_261 , 2 ) ;
}
static bool
F_84 ( struct V_1 * V_1 )
{
return F_85 ( V_1 -> V_244 . V_257 ) > 1 ;
}
static struct V_262 *
F_86 ( struct V_5 * V_6 )
{
struct V_1 * V_263 = F_3 ( V_6 ) ;
return F_87 ( V_6 , & V_263 -> V_264 ) ;
}
static struct V_262 *
F_88 ( struct V_5 * V_6 )
{
struct V_11 * V_12 = V_6 -> V_10 -> V_13 ;
return F_87 ( V_6 ,
F_89 ( V_12 ,
V_12 -> V_265 ) ) ;
}
static enum V_266
F_90 ( struct V_5 * V_6 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
enum V_266 V_36 ;
struct V_262 * V_262 ;
V_262 = F_86 ( V_6 ) ;
if ( V_262 == NULL && F_84 ( V_1 ) ) {
T_2 V_264 , V_267 = V_1 -> V_53 ;
for ( V_264 = V_1 -> V_53 >> 1 ; V_264 > 1 ; V_264 >>= 1 ) {
V_1 -> V_53 = V_264 ;
V_262 = F_86 ( V_6 ) ;
if ( V_262 )
break;
}
if ( V_262 == NULL )
V_1 -> V_53 = V_267 ;
}
if ( V_262 == NULL )
V_262 = F_88 ( V_6 ) ;
V_36 = V_268 ;
if ( V_262 != NULL ) {
if ( V_262 -> V_269 & V_270 ) {
V_36 = V_271 ;
if ( V_1 -> V_214 ) {
V_1 -> V_194 = F_91 ( V_262 ) ;
V_1 -> V_220 = F_92 ( V_262 ) ;
V_1 -> V_166 =
F_93 ( V_262 ) ;
}
} else
V_36 = V_272 ;
F_20 ( V_262 ) ;
}
if ( V_36 == V_271 ) {
struct V_7 * V_7 = F_5 ( V_6 ) ;
if ( V_7 -> V_273 != V_274 )
V_1 -> V_220 = ( V_7 -> V_273 == V_275 ) ;
}
return V_36 ;
}
static bool
F_94 ( struct V_7 * V_263 ,
struct V_262 * V_262 )
{
bool V_276 = ! ! ( V_262 -> V_269 & V_270 ) ;
bool V_277 = ! ! F_95 ( V_263 ) ;
F_12 ( L_33 ,
V_277 , V_276 ) ;
return V_277 == V_276 ;
}
static enum V_266
F_96 ( struct V_5 * V_6 , bool V_278 )
{
T_4 V_42 ;
struct V_1 * V_1 = F_3 ( V_6 ) ;
struct V_7 * V_7 = F_5 ( V_6 ) ;
enum V_266 V_30 ;
if ( ! F_27 ( V_1 ,
V_279 ,
& V_42 , 2 ) )
return V_268 ;
F_12 ( L_34 ,
V_42 & 0xff , V_42 >> 8 ,
V_7 -> V_227 ) ;
if ( V_42 == 0 )
return V_272 ;
V_1 -> V_182 = V_42 ;
V_1 -> V_194 = false ;
V_1 -> V_220 = false ;
V_1 -> V_166 = false ;
if ( ( V_7 -> V_227 & V_42 ) == 0 )
V_30 = V_272 ;
else if ( F_97 ( V_7 ) )
V_30 = F_90 ( V_6 ) ;
else {
struct V_262 * V_262 ;
V_262 = F_86 ( V_6 ) ;
if ( V_262 == NULL )
V_262 = F_88 ( V_6 ) ;
if ( V_262 != NULL ) {
if ( F_94 ( V_7 ,
V_262 ) )
V_30 = V_271 ;
else
V_30 = V_272 ;
F_20 ( V_262 ) ;
} else
V_30 = V_271 ;
}
if ( V_30 == V_271 ) {
V_1 -> V_191 = false ;
V_1 -> V_97 = false ;
V_1 -> V_4 . V_280 = false ;
if ( V_42 & V_281 ) {
V_1 -> V_191 = true ;
V_1 -> V_4 . V_280 = true ;
}
if ( V_42 & V_282 )
V_1 -> V_97 = V_1 -> V_98 != NULL ;
}
return V_30 ;
}
static void F_98 ( struct V_5 * V_6 )
{
struct V_262 * V_262 ;
V_262 = F_86 ( V_6 ) ;
if ( V_262 == NULL )
V_262 = F_88 ( V_6 ) ;
if ( V_262 != NULL ) {
if ( F_94 ( F_5 ( V_6 ) ,
V_262 ) ) {
F_99 ( V_6 , V_262 ) ;
F_100 ( V_6 , V_262 ) ;
}
F_20 ( V_262 ) ;
}
}
static void F_101 ( struct V_5 * V_6 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
struct V_283 V_284 ;
T_6 V_285 = 0 , V_178 = 0 ;
int V_16 ;
V_178 = 1 << V_1 -> V_179 ;
memcpy ( & V_284 , & V_178 ,
V_84 ( sizeof( V_178 ) , sizeof( struct V_283 ) ) ) ;
if ( ! F_35 ( V_1 , V_1 -> V_182 ) )
return;
F_30 ( sizeof( V_284 ) != 3 ) ;
if ( ! F_17 ( V_1 ,
V_286 ,
& V_284 , sizeof( V_284 ) ) )
return;
if ( ! F_21 ( V_1 , & V_285 , 3 ) )
return;
for ( V_16 = 0 ; V_16 < F_16 ( V_287 ) ; V_16 ++ )
if ( V_285 & ( 1 << V_16 ) ) {
struct V_51 * V_288 ;
V_288 = F_102 ( V_6 -> V_10 ,
& V_287 [ V_16 ] ) ;
if ( V_288 )
F_103 ( V_6 , V_288 ) ;
}
}
static void F_104 ( struct V_5 * V_6 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
struct V_11 * V_12 = V_6 -> V_10 -> V_13 ;
struct V_51 * V_289 ;
F_105 ( V_6 , & V_1 -> V_264 ) ;
if ( V_12 -> V_290 != NULL ) {
V_289 = F_102 ( V_6 -> V_10 ,
V_12 -> V_290 ) ;
if ( V_289 != NULL ) {
V_289 -> type = ( V_291 |
V_292 ) ;
F_103 ( V_6 , V_289 ) ;
}
}
F_106 (newmode, &connector->probed_modes, head) {
if ( V_289 -> type & V_291 ) {
V_1 -> V_98 =
F_102 ( V_6 -> V_10 , V_289 ) ;
V_1 -> V_97 = true ;
break;
}
}
}
static int F_107 ( struct V_5 * V_6 )
{
struct V_7 * V_7 = F_5 ( V_6 ) ;
if ( F_108 ( V_7 ) )
F_101 ( V_6 ) ;
else if ( F_109 ( V_7 ) )
F_104 ( V_6 ) ;
else
F_98 ( V_6 ) ;
return ! F_110 ( & V_6 -> V_293 ) ;
}
static void
F_111 ( struct V_5 * V_6 )
{
struct V_7 * V_7 = F_5 ( V_6 ) ;
struct V_9 * V_10 = V_6 -> V_10 ;
if ( V_7 -> V_294 )
F_112 ( V_10 , V_7 -> V_294 ) ;
if ( V_7 -> V_295 )
F_112 ( V_10 , V_7 -> V_295 ) ;
if ( V_7 -> V_296 )
F_112 ( V_10 , V_7 -> V_296 ) ;
if ( V_7 -> V_297 )
F_112 ( V_10 , V_7 -> V_297 ) ;
if ( V_7 -> V_298 )
F_112 ( V_10 , V_7 -> V_298 ) ;
if ( V_7 -> V_299 )
F_112 ( V_10 , V_7 -> V_299 ) ;
if ( V_7 -> V_300 )
F_112 ( V_10 , V_7 -> V_300 ) ;
if ( V_7 -> V_301 )
F_112 ( V_10 , V_7 -> V_301 ) ;
if ( V_7 -> V_302 )
F_112 ( V_10 , V_7 -> V_302 ) ;
if ( V_7 -> V_303 )
F_112 ( V_10 , V_7 -> V_303 ) ;
if ( V_7 -> V_304 )
F_112 ( V_10 , V_7 -> V_304 ) ;
if ( V_7 -> V_305 )
F_112 ( V_10 , V_7 -> V_305 ) ;
if ( V_7 -> V_306 )
F_112 ( V_10 , V_7 -> V_306 ) ;
if ( V_7 -> V_307 )
F_112 ( V_10 , V_7 -> V_307 ) ;
if ( V_7 -> V_308 )
F_112 ( V_10 , V_7 -> V_308 ) ;
if ( V_7 -> V_309 )
F_112 ( V_10 , V_7 -> V_309 ) ;
if ( V_7 -> V_310 )
F_112 ( V_10 , V_7 -> V_310 ) ;
}
static void F_113 ( struct V_5 * V_6 )
{
struct V_7 * V_7 = F_5 ( V_6 ) ;
if ( V_7 -> V_311 )
F_112 ( V_6 -> V_10 ,
V_7 -> V_311 ) ;
F_111 ( V_6 ) ;
F_114 ( V_6 ) ;
F_115 ( V_6 ) ;
F_20 ( V_7 ) ;
}
static bool F_116 ( struct V_5 * V_6 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
struct V_262 * V_262 ;
bool V_312 = false ;
if ( ! V_1 -> V_214 )
return false ;
V_262 = F_86 ( V_6 ) ;
if ( V_262 != NULL && V_262 -> V_269 & V_270 )
V_312 = F_92 ( V_262 ) ;
F_20 ( V_262 ) ;
return V_312 ;
}
static int
F_117 ( struct V_5 * V_6 ,
struct V_313 * V_314 ,
T_7 V_8 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
struct V_7 * V_7 = F_5 ( V_6 ) ;
struct V_11 * V_12 = V_6 -> V_10 -> V_13 ;
T_4 V_315 ;
T_5 V_32 ;
int V_30 ;
V_30 = F_118 ( & V_6 -> V_4 , V_314 , V_8 ) ;
if ( V_30 )
return V_30 ;
if ( V_314 == V_12 -> V_316 ) {
int V_16 = V_8 ;
bool V_312 ;
if ( V_16 == V_7 -> V_273 )
return 0 ;
V_7 -> V_273 = V_16 ;
if ( V_16 == V_274 )
V_312 = F_116 ( V_6 ) ;
else
V_312 = ( V_16 == V_275 ) ;
if ( V_312 == V_1 -> V_220 )
return 0 ;
V_1 -> V_220 = V_312 ;
goto V_317;
}
if ( V_314 == V_12 -> V_318 ) {
bool V_319 = V_1 -> V_193 ;
T_6 V_320 = V_1 -> V_195 ;
switch ( V_8 ) {
case V_321 :
V_1 -> V_193 = true ;
break;
case V_322 :
V_1 -> V_193 = false ;
V_1 -> V_195 = 0 ;
break;
case V_323 :
V_1 -> V_193 = false ;
V_1 -> V_195 = V_196 ;
break;
default:
return - V_324 ;
}
if ( V_319 == V_1 -> V_193 &&
V_320 == V_1 -> V_195 )
return 0 ;
goto V_317;
}
#define F_119 ( V_35 , T_8 ) \
if (intel_sdvo_connector->name == property) { \
if (intel_sdvo_connector->cur_##name == temp_value) return 0; \
if (intel_sdvo_connector->max_##name < temp_value) return -EINVAL; \
cmd = SDVO_CMD_SET_##NAME; \
intel_sdvo_connector->cur_##name = temp_value; \
goto set_value; \
}
if ( V_314 == V_7 -> V_311 ) {
if ( V_8 >= V_325 )
return - V_324 ;
if ( V_1 -> V_179 ==
V_7 -> V_326 [ V_8 ] )
return 0 ;
V_1 -> V_179 = V_7 -> V_326 [ V_8 ] ;
goto V_317;
} else if ( F_120 ( V_7 ) ) {
V_315 = V_8 ;
if ( V_7 -> V_294 == V_314 ) {
F_118 ( & V_6 -> V_4 ,
V_7 -> V_295 , V_8 ) ;
if ( V_7 -> V_327 == V_315 )
return 0 ;
V_7 -> V_327 = V_315 ;
V_7 -> V_328 = V_315 ;
V_315 = V_7 -> V_329 -
V_7 -> V_327 ;
V_32 = V_330 ;
goto V_331;
} else if ( V_7 -> V_295 == V_314 ) {
F_118 ( & V_6 -> V_4 ,
V_7 -> V_294 , V_8 ) ;
if ( V_7 -> V_328 == V_315 )
return 0 ;
V_7 -> V_327 = V_315 ;
V_7 -> V_328 = V_315 ;
V_315 = V_7 -> V_329 -
V_7 -> V_327 ;
V_32 = V_330 ;
goto V_331;
} else if ( V_7 -> V_296 == V_314 ) {
F_118 ( & V_6 -> V_4 ,
V_7 -> V_297 , V_8 ) ;
if ( V_7 -> V_332 == V_315 )
return 0 ;
V_7 -> V_332 = V_315 ;
V_7 -> V_333 = V_315 ;
V_315 = V_7 -> V_334 -
V_7 -> V_332 ;
V_32 = V_335 ;
goto V_331;
} else if ( V_7 -> V_297 == V_314 ) {
F_118 ( & V_6 -> V_4 ,
V_7 -> V_296 , V_8 ) ;
if ( V_7 -> V_333 == V_315 )
return 0 ;
V_7 -> V_332 = V_315 ;
V_7 -> V_333 = V_315 ;
V_315 = V_7 -> V_334 -
V_7 -> V_332 ;
V_32 = V_335 ;
goto V_331;
}
F_119 (hpos, HPOS)
F_119 (vpos, VPOS)
F_119 (saturation, SATURATION)
F_119 (contrast, CONTRAST)
F_119 (hue, HUE)
F_119 (brightness, BRIGHTNESS)
F_119 (sharpness, SHARPNESS)
F_119 (flicker_filter, FLICKER_FILTER)
F_119 (flicker_filter_2d, FLICKER_FILTER_2D)
F_119 (flicker_filter_adaptive, FLICKER_FILTER_ADAPTIVE)
F_119 (tv_chroma_filter, TV_CHROMA_FILTER)
F_119 (tv_luma_filter, TV_LUMA_FILTER)
F_119 (dot_crawl, DOT_CRAWL)
}
return - V_324 ;
V_331:
if ( ! F_26 ( V_1 , V_32 , & V_315 , 2 ) )
return - V_336 ;
V_317:
if ( V_1 -> V_4 . V_4 . V_165 )
F_121 ( V_1 -> V_4 . V_4 . V_165 ) ;
return 0 ;
#undef F_119
}
static void F_122 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
if ( V_1 -> V_98 != NULL )
F_123 ( V_3 -> V_10 ,
V_1 -> V_98 ) ;
F_124 ( & V_1 -> V_264 ) ;
F_125 ( V_3 ) ;
}
static void
F_126 ( struct V_1 * V_263 )
{
T_4 V_337 = 0 ;
unsigned int V_338 ;
switch ( V_263 -> V_339 ) {
case V_340 :
V_337 |= V_340 ;
case V_341 :
V_337 |= V_341 ;
case V_342 :
V_337 |= V_342 ;
case V_343 :
V_337 |= V_343 ;
case V_344 :
V_337 |= V_344 ;
case V_345 :
V_337 |= V_345 ;
break;
}
V_337 &= V_263 -> V_244 . V_257 ;
V_338 = F_85 ( V_337 ) ;
if ( V_338 > 3 )
V_338 = 3 ;
V_263 -> V_53 = 1 << V_338 ;
}
static void
F_127 ( struct V_11 * V_12 ,
struct V_1 * V_263 , T_1 V_346 )
{
struct V_347 * V_348 ;
if ( V_263 -> V_349 )
V_348 = & ( V_12 -> V_350 [ 0 ] ) ;
else
V_348 = & ( V_12 -> V_350 [ 1 ] ) ;
if ( V_348 -> V_351 )
V_263 -> V_53 = 1 << ( ( V_348 -> V_352 & 0xf0 ) >> 4 ) ;
else
F_126 ( V_263 ) ;
}
static void
F_128 ( struct V_11 * V_12 ,
struct V_1 * V_263 , T_1 V_346 )
{
struct V_347 * V_348 ;
T_2 V_353 ;
if ( V_263 -> V_349 )
V_348 = & V_12 -> V_350 [ 0 ] ;
else
V_348 = & V_12 -> V_350 [ 1 ] ;
if ( V_348 -> V_351 && F_129 ( V_348 -> V_354 ) )
V_353 = V_348 -> V_354 ;
else
V_353 = V_355 ;
V_263 -> V_31 = F_89 ( V_12 , V_353 ) ;
F_130 ( V_263 -> V_31 , true ) ;
}
static void
F_131 ( struct V_1 * V_263 )
{
F_130 ( V_263 -> V_31 , false ) ;
}
static bool
F_132 ( struct V_1 * V_1 , int V_356 )
{
return F_44 ( V_1 ) ;
}
static T_2
F_133 ( struct V_9 * V_10 , struct V_1 * V_263 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_347 * V_357 , * V_358 ;
if ( V_263 -> V_349 ) {
V_357 = & V_12 -> V_350 [ 0 ] ;
V_358 = & V_12 -> V_350 [ 1 ] ;
} else {
V_357 = & V_12 -> V_350 [ 1 ] ;
V_358 = & V_12 -> V_350 [ 0 ] ;
}
if ( V_357 -> V_25 )
return V_357 -> V_25 ;
if ( V_358 -> V_25 ) {
if ( V_358 -> V_25 == 0x70 )
return 0x72 ;
else
return 0x70 ;
}
if ( V_263 -> V_349 )
return 0x70 ;
else
return 0x72 ;
}
static void
F_134 ( struct V_7 * V_6 ,
struct V_1 * V_3 )
{
F_135 ( V_3 -> V_4 . V_4 . V_10 ,
& V_6 -> V_4 . V_4 ,
& V_359 ,
V_6 -> V_4 . V_4 . V_360 ) ;
F_136 ( & V_6 -> V_4 . V_4 ,
& V_361 ) ;
V_6 -> V_4 . V_4 . V_362 = 1 ;
V_6 -> V_4 . V_4 . V_363 = 0 ;
V_6 -> V_4 . V_4 . V_364 . V_365 = V_366 ;
V_6 -> V_4 . V_367 = F_67 ;
F_137 ( & V_6 -> V_4 , & V_3 -> V_4 ) ;
F_138 ( & V_6 -> V_4 . V_4 ) ;
}
static void
F_139 ( struct V_1 * V_1 ,
struct V_7 * V_6 )
{
struct V_9 * V_10 = V_6 -> V_4 . V_4 . V_10 ;
F_140 ( & V_6 -> V_4 . V_4 ) ;
if ( F_60 ( V_10 ) -> V_211 >= 4 && F_141 ( V_10 ) ) {
F_142 ( & V_6 -> V_4 . V_4 ) ;
V_1 -> V_193 = true ;
}
}
static bool
F_143 ( struct V_1 * V_1 , int V_356 )
{
struct V_2 * V_3 = & V_1 -> V_4 . V_4 ;
struct V_5 * V_6 ;
struct V_185 * V_185 = F_144 ( V_3 ) ;
struct V_225 * V_225 ;
struct V_7 * V_7 ;
V_7 = F_18 ( sizeof( struct V_7 ) , V_37 ) ;
if ( ! V_7 )
return false ;
if ( V_356 == 0 ) {
V_1 -> V_339 |= V_343 ;
V_7 -> V_227 = V_343 ;
} else if ( V_356 == 1 ) {
V_1 -> V_339 |= V_342 ;
V_7 -> V_227 = V_342 ;
}
V_225 = & V_7 -> V_4 ;
V_6 = & V_225 -> V_4 ;
if ( F_82 ( V_1 ) &
V_7 -> V_227 ) {
V_1 -> V_261 |= V_7 -> V_227 ;
V_185 -> V_368 = F_83 ;
F_83 ( V_185 ) ;
} else {
V_225 -> V_369 = V_370 | V_371 ;
}
V_3 -> V_372 = V_373 ;
V_6 -> V_360 = V_374 ;
if ( F_132 ( V_1 , V_356 ) ) {
V_6 -> V_360 = V_375 ;
V_1 -> V_214 = true ;
}
F_134 ( V_7 , V_1 ) ;
if ( V_1 -> V_214 )
F_139 ( V_1 , V_7 ) ;
return true ;
}
static bool
F_145 ( struct V_1 * V_1 , int type )
{
struct V_2 * V_3 = & V_1 -> V_4 . V_4 ;
struct V_5 * V_6 ;
struct V_225 * V_225 ;
struct V_7 * V_7 ;
V_7 = F_18 ( sizeof( struct V_7 ) , V_37 ) ;
if ( ! V_7 )
return false ;
V_225 = & V_7 -> V_4 ;
V_6 = & V_225 -> V_4 ;
V_3 -> V_372 = V_376 ;
V_6 -> V_360 = V_377 ;
V_1 -> V_339 |= type ;
V_7 -> V_227 = type ;
V_1 -> V_191 = true ;
V_1 -> V_4 . V_280 = true ;
F_134 ( V_7 , V_1 ) ;
if ( ! F_146 ( V_1 , V_7 , type ) )
goto V_378;
if ( ! F_147 ( V_1 , V_7 ) )
goto V_378;
return true ;
V_378:
F_113 ( V_6 ) ;
return false ;
}
static bool
F_148 ( struct V_1 * V_1 , int V_356 )
{
struct V_2 * V_3 = & V_1 -> V_4 . V_4 ;
struct V_5 * V_6 ;
struct V_225 * V_225 ;
struct V_7 * V_7 ;
V_7 = F_18 ( sizeof( struct V_7 ) , V_37 ) ;
if ( ! V_7 )
return false ;
V_225 = & V_7 -> V_4 ;
V_6 = & V_225 -> V_4 ;
V_225 -> V_369 = V_370 ;
V_3 -> V_372 = V_379 ;
V_6 -> V_360 = V_380 ;
if ( V_356 == 0 ) {
V_1 -> V_339 |= V_345 ;
V_7 -> V_227 = V_345 ;
} else if ( V_356 == 1 ) {
V_1 -> V_339 |= V_344 ;
V_7 -> V_227 = V_344 ;
}
F_134 ( V_7 ,
V_1 ) ;
return true ;
}
static bool
F_149 ( struct V_1 * V_1 , int V_356 )
{
struct V_2 * V_3 = & V_1 -> V_4 . V_4 ;
struct V_5 * V_6 ;
struct V_225 * V_225 ;
struct V_7 * V_7 ;
V_7 = F_18 ( sizeof( struct V_7 ) , V_37 ) ;
if ( ! V_7 )
return false ;
V_225 = & V_7 -> V_4 ;
V_6 = & V_225 -> V_4 ;
V_3 -> V_372 = V_381 ;
V_6 -> V_360 = V_382 ;
if ( V_356 == 0 ) {
V_1 -> V_339 |= V_341 ;
V_7 -> V_227 = V_341 ;
} else if ( V_356 == 1 ) {
V_1 -> V_339 |= V_340 ;
V_7 -> V_227 = V_340 ;
}
F_134 ( V_7 , V_1 ) ;
if ( ! F_147 ( V_1 , V_7 ) )
goto V_378;
return true ;
V_378:
F_113 ( V_6 ) ;
return false ;
}
static bool
F_150 ( struct V_1 * V_1 , T_4 V_26 )
{
V_1 -> V_191 = false ;
V_1 -> V_4 . V_280 = false ;
V_1 -> V_97 = false ;
if ( V_26 & V_343 )
if ( ! F_143 ( V_1 , 0 ) )
return false ;
if ( ( V_26 & V_383 ) == V_383 )
if ( ! F_143 ( V_1 , 1 ) )
return false ;
if ( V_26 & V_384 )
if ( ! F_145 ( V_1 , V_384 ) )
return false ;
if ( V_26 & V_385 )
if ( ! F_145 ( V_1 , V_385 ) )
return false ;
if ( V_26 & V_386 )
if ( ! F_145 ( V_1 , V_386 ) )
return false ;
if ( V_26 & V_345 )
if ( ! F_148 ( V_1 , 0 ) )
return false ;
if ( ( V_26 & V_387 ) == V_387 )
if ( ! F_148 ( V_1 , 1 ) )
return false ;
if ( V_26 & V_341 )
if ( ! F_149 ( V_1 , 0 ) )
return false ;
if ( ( V_26 & V_282 ) == V_282 )
if ( ! F_149 ( V_1 , 1 ) )
return false ;
if ( ( V_26 & V_388 ) == 0 ) {
unsigned char V_389 [ 2 ] ;
V_1 -> V_339 = 0 ;
memcpy ( V_389 , & V_1 -> V_244 . V_257 , 2 ) ;
F_12 ( L_35 ,
F_14 ( V_1 ) ,
V_389 [ 0 ] , V_389 [ 1 ] ) ;
return false ;
}
V_1 -> V_4 . V_390 = ( 1 << 0 ) | ( 1 << 1 ) | ( 1 << 2 ) ;
return true ;
}
static void F_151 ( struct V_1 * V_1 )
{
struct V_9 * V_10 = V_1 -> V_4 . V_4 . V_10 ;
struct V_5 * V_6 , * V_149 ;
F_152 (connector, tmp,
&dev->mode_config.connector_list, head) {
if ( F_4 ( V_6 ) == & V_1 -> V_4 )
F_113 ( V_6 ) ;
}
}
static bool F_146 ( struct V_1 * V_1 ,
struct V_7 * V_7 ,
int type )
{
struct V_9 * V_10 = V_1 -> V_4 . V_4 . V_10 ;
struct V_176 V_177 ;
T_6 V_178 , V_16 ;
if ( ! F_35 ( V_1 , type ) )
return false ;
F_30 ( sizeof( V_177 ) != 6 ) ;
if ( ! F_27 ( V_1 ,
V_391 ,
& V_177 , sizeof( V_177 ) ) )
return false ;
memcpy ( & V_178 , & V_177 , V_84 ( sizeof( V_178 ) , sizeof( V_177 ) ) ) ;
if ( V_178 == 0 )
return false ;
V_7 -> V_392 = 0 ;
for ( V_16 = 0 ; V_16 < V_325 ; V_16 ++ )
if ( V_178 & ( 1 << V_16 ) )
V_7 -> V_326 [ V_7 -> V_392 ++ ] = V_16 ;
V_7 -> V_311 =
F_153 ( V_10 , V_393 ,
L_36 , V_7 -> V_392 ) ;
if ( ! V_7 -> V_311 )
return false ;
for ( V_16 = 0 ; V_16 < V_7 -> V_392 ; V_16 ++ )
F_154 (
V_7 -> V_311 , V_16 ,
V_16 , V_394 [ V_7 -> V_326 [ V_16 ] ] ) ;
V_1 -> V_179 = V_7 -> V_326 [ 0 ] ;
F_155 ( & V_7 -> V_4 . V_4 . V_4 ,
V_7 -> V_311 , 0 ) ;
return true ;
}
static bool
F_156 ( struct V_1 * V_1 ,
struct V_7 * V_7 ,
struct V_395 V_396 )
{
struct V_9 * V_10 = V_1 -> V_4 . V_4 . V_10 ;
struct V_5 * V_6 = & V_7 -> V_4 . V_4 ;
T_4 V_42 , V_397 [ 2 ] ;
if ( V_396 . V_398 ) {
if ( ! F_27 ( V_1 ,
V_399 ,
& V_397 , 4 ) )
return false ;
if ( ! F_27 ( V_1 ,
V_400 ,
& V_42 , 2 ) )
return false ;
V_7 -> V_329 = V_397 [ 0 ] ;
V_7 -> V_327 = V_397 [ 0 ] - V_42 ;
V_7 -> V_328 = V_7 -> V_327 ;
V_7 -> V_294 =
F_157 ( V_10 , 0 , L_37 , 0 , V_397 [ 0 ] ) ;
if ( ! V_7 -> V_294 )
return false ;
F_155 ( & V_6 -> V_4 ,
V_7 -> V_294 ,
V_7 -> V_327 ) ;
V_7 -> V_295 =
F_157 ( V_10 , 0 , L_38 , 0 , V_397 [ 0 ] ) ;
if ( ! V_7 -> V_295 )
return false ;
F_155 ( & V_6 -> V_4 ,
V_7 -> V_295 ,
V_7 -> V_328 ) ;
F_12 ( L_39
L_40 ,
V_397 [ 0 ] , V_397 [ 1 ] , V_42 ) ;
}
if ( V_396 . V_401 ) {
if ( ! F_27 ( V_1 ,
V_402 ,
& V_397 , 4 ) )
return false ;
if ( ! F_27 ( V_1 ,
V_403 ,
& V_42 , 2 ) )
return false ;
V_7 -> V_334 = V_397 [ 0 ] ;
V_7 -> V_332 = V_397 [ 0 ] - V_42 ;
V_7 -> V_333 = V_7 -> V_332 ;
V_7 -> V_296 =
F_157 ( V_10 , 0 ,
L_41 , 0 , V_397 [ 0 ] ) ;
if ( ! V_7 -> V_296 )
return false ;
F_155 ( & V_6 -> V_4 ,
V_7 -> V_296 ,
V_7 -> V_332 ) ;
V_7 -> V_297 =
F_157 ( V_10 , 0 ,
L_42 , 0 , V_397 [ 0 ] ) ;
if ( ! V_7 -> V_297 )
return false ;
F_155 ( & V_6 -> V_4 ,
V_7 -> V_297 ,
V_7 -> V_333 ) ;
F_12 ( L_43
L_40 ,
V_397 [ 0 ] , V_397 [ 1 ] , V_42 ) ;
}
F_158 ( V_298 , V_404 ) ;
F_158 ( V_299 , V_405 ) ;
F_158 ( V_300 , V_406 ) ;
F_158 ( V_301 , V_407 ) ;
F_158 ( V_302 , V_408 ) ;
F_158 ( V_303 , V_409 ) ;
F_158 ( V_310 , V_410 ) ;
F_158 ( V_304 , V_411 ) ;
F_158 ( V_306 , V_412 ) ;
F_158 ( V_305 , V_413 ) ;
F_158 ( V_308 , V_414 ) ;
F_158 ( V_307 , V_415 ) ;
if ( V_396 . V_309 ) {
if ( ! F_27 ( V_1 , V_416 , & V_42 , 2 ) )
return false ;
V_7 -> V_417 = 1 ;
V_7 -> V_418 = V_42 & 0x1 ;
V_7 -> V_309 =
F_157 ( V_10 , 0 , L_44 , 0 , 1 ) ;
if ( ! V_7 -> V_309 )
return false ;
F_155 ( & V_6 -> V_4 ,
V_7 -> V_309 ,
V_7 -> V_418 ) ;
F_12 ( L_45 , V_42 ) ;
}
return true ;
}
static bool
F_159 ( struct V_1 * V_1 ,
struct V_7 * V_7 ,
struct V_395 V_396 )
{
struct V_9 * V_10 = V_1 -> V_4 . V_4 . V_10 ;
struct V_5 * V_6 = & V_7 -> V_4 . V_4 ;
T_4 V_42 , V_397 [ 2 ] ;
F_158 ( V_310 , V_410 ) ;
return true ;
}
static bool F_147 ( struct V_1 * V_1 ,
struct V_7 * V_7 )
{
union {
struct V_395 V_285 ;
T_4 V_42 ;
} V_396 ;
F_30 ( sizeof( V_396 ) != 2 ) ;
V_396 . V_42 = 0 ;
F_27 ( V_1 ,
V_419 ,
& V_396 , sizeof( V_396 ) ) ;
if ( V_396 . V_42 == 0 ) {
F_12 ( L_46 ) ;
return true ;
}
if ( F_108 ( V_7 ) )
return F_156 ( V_1 , V_7 , V_396 . V_285 ) ;
else if ( F_109 ( V_7 ) )
return F_159 ( V_1 , V_7 , V_396 . V_285 ) ;
else
return true ;
}
static int F_160 ( struct V_420 * V_421 ,
struct V_23 * V_24 ,
int V_422 )
{
struct V_1 * V_263 = V_421 -> V_423 ;
if ( ! F_25 ( V_263 , V_263 -> V_53 ) )
return - V_336 ;
return V_263 -> V_31 -> V_424 -> V_425 ( V_263 -> V_31 , V_24 , V_422 ) ;
}
static T_1 F_161 ( struct V_420 * V_421 )
{
struct V_1 * V_263 = V_421 -> V_423 ;
return V_263 -> V_31 -> V_424 -> V_426 ( V_263 -> V_31 ) ;
}
static bool
F_162 ( struct V_1 * V_263 ,
struct V_9 * V_10 )
{
V_263 -> V_264 . V_427 = V_428 ;
V_263 -> V_264 . V_429 = V_430 ;
snprintf ( V_263 -> V_264 . V_35 , V_431 , L_47 ) ;
V_263 -> V_264 . V_10 . V_432 = & V_10 -> V_433 -> V_10 ;
V_263 -> V_264 . V_423 = V_263 ;
V_263 -> V_264 . V_424 = & V_434 ;
return F_163 ( & V_263 -> V_264 ) == 0 ;
}
bool F_164 ( struct V_9 * V_10 , T_6 V_17 , bool V_349 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_185 * V_185 ;
struct V_1 * V_1 ;
T_1 V_435 ;
int V_16 ;
V_1 = F_18 ( sizeof( struct V_1 ) , V_37 ) ;
if ( ! V_1 )
return false ;
V_1 -> V_17 = V_17 ;
V_1 -> V_349 = V_349 ;
V_1 -> V_25 = F_133 ( V_10 , V_1 ) >> 1 ;
F_128 ( V_12 , V_1 , V_17 ) ;
if ( ! F_162 ( V_1 , V_10 ) )
goto V_436;
V_185 = & V_1 -> V_4 ;
V_185 -> type = V_437 ;
F_165 ( V_10 , & V_185 -> V_4 , & V_438 , 0 ) ;
for ( V_16 = 0 ; V_16 < 0x40 ; V_16 ++ ) {
T_2 V_439 ;
if ( ! F_10 ( V_1 , V_16 , & V_439 ) ) {
F_12 ( L_48 ,
F_14 ( V_1 ) ) ;
goto V_378;
}
}
V_435 = 0 ;
if ( F_166 ( V_10 ) ) {
V_435 = V_1 -> V_349 ?
V_440 : V_441 ;
} else if ( F_167 ( V_10 ) ) {
V_435 = V_1 -> V_349 ?
V_442 : V_443 ;
} else {
V_435 = V_1 -> V_349 ?
V_444 : V_445 ;
}
V_185 -> V_446 = F_56 ;
V_185 -> V_447 = F_72 ;
V_185 -> V_448 = F_58 ;
V_185 -> V_449 = F_76 ;
V_185 -> V_367 = F_68 ;
if ( ! F_81 ( V_1 , & V_1 -> V_244 ) )
goto V_378;
if ( F_150 ( V_1 ,
V_1 -> V_244 . V_257 ) != true ) {
F_12 ( L_49 ,
F_14 ( V_1 ) ) ;
goto V_450;
}
if ( V_1 -> V_261 ) {
V_185 -> V_451 =
V_1 -> V_349 ? V_452 : V_453 ;
}
V_1 -> V_4 . V_454 = false ;
F_127 ( V_12 , V_1 , V_17 ) ;
if ( ! F_28 ( V_1 ) )
goto V_450;
if ( ! F_34 ( V_1 ,
& V_1 -> V_237 ,
& V_1 -> V_239 ) )
goto V_450;
F_12 ( L_50
L_51
L_52
L_53 ,
F_14 ( V_1 ) ,
V_1 -> V_244 . V_246 , V_1 -> V_244 . V_247 ,
V_1 -> V_244 . V_248 ,
V_1 -> V_237 / 1000 ,
V_1 -> V_239 / 1000 ,
( V_1 -> V_244 . V_251 & 0x1 ) ? 'Y' : 'N' ,
( V_1 -> V_244 . V_251 & 0x2 ) ? 'Y' : 'N' ,
V_1 -> V_244 . V_257 &
( V_343 | V_345 ) ? 'Y' : 'N' ,
V_1 -> V_244 . V_257 &
( V_342 | V_344 ) ? 'Y' : 'N' ) ;
return true ;
V_450:
F_151 ( V_1 ) ;
V_378:
F_168 ( & V_185 -> V_4 ) ;
F_124 ( & V_1 -> V_264 ) ;
V_436:
F_131 ( V_1 ) ;
F_20 ( V_1 ) ;
return false ;
}
