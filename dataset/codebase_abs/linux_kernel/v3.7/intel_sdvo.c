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
T_2 V_44 = 5 ;
T_2 V_36 ;
int V_16 ;
F_12 ( L_10 , F_14 ( V_1 ) ) ;
if ( ! F_10 ( V_1 ,
V_40 ,
& V_36 ) )
goto V_45;
while ( V_36 == V_46 && V_44 -- ) {
F_22 ( 15 ) ;
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
static int F_23 ( struct V_51 * V_52 )
{
if ( V_52 -> clock >= 100000 )
return 1 ;
else if ( V_52 -> clock >= 50000 )
return 2 ;
else
return 4 ;
}
static bool F_24 ( struct V_1 * V_1 ,
T_2 V_53 )
{
return F_17 ( V_1 ,
V_54 ,
& V_53 , 1 ) ;
}
static bool F_25 ( struct V_1 * V_1 , T_2 V_32 , const void * V_55 , int V_27 )
{
if ( ! F_17 ( V_1 , V_32 , V_55 , V_27 ) )
return false ;
return F_21 ( V_1 , NULL , 0 ) ;
}
static bool
F_26 ( struct V_1 * V_1 , T_2 V_32 , void * V_56 , int V_27 )
{
if ( ! F_17 ( V_1 , V_32 , NULL , 0 ) )
return false ;
return F_21 ( V_1 , V_56 , V_27 ) ;
}
static bool F_27 ( struct V_1 * V_1 )
{
struct V_57 V_58 = { 0 } ;
return F_25 ( V_1 ,
V_59 ,
& V_58 , sizeof( V_58 ) ) ;
}
static bool F_28 ( struct V_1 * V_1 , bool * V_60 , bool * V_61 )
{
struct V_62 V_42 ;
F_29 ( sizeof( V_42 ) != 1 ) ;
if ( ! F_26 ( V_1 , V_63 ,
& V_42 , sizeof( V_42 ) ) )
return false ;
* V_60 = V_42 . V_64 ;
* V_61 = V_42 . V_65 ;
return true ;
}
static bool F_30 ( struct V_1 * V_1 ,
T_3 V_66 )
{
return F_25 ( V_1 ,
V_67 ,
& V_66 , sizeof( V_66 ) ) ;
}
static bool F_31 ( struct V_1 * V_1 ,
T_3 * V_66 )
{
return F_26 ( V_1 ,
V_68 ,
V_66 , sizeof( * V_66 ) ) ;
}
static bool F_32 ( struct V_1 * V_1 ,
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
return F_25 ( V_1 ,
V_78 , & V_69 , sizeof( V_69 ) ) ;
}
static bool F_33 ( struct V_1 * V_1 ,
int * V_79 ,
int * V_80 )
{
struct V_81 V_82 ;
F_29 ( sizeof( V_82 ) != 4 ) ;
if ( ! F_26 ( V_1 ,
V_83 ,
& V_82 , sizeof( V_82 ) ) )
return false ;
* V_79 = V_82 . V_84 * 10 ;
* V_80 = V_82 . V_85 * 10 ;
return true ;
}
static bool F_34 ( struct V_1 * V_1 ,
T_3 V_66 )
{
return F_25 ( V_1 ,
V_86 ,
& V_66 , sizeof( V_66 ) ) ;
}
static bool F_35 ( struct V_1 * V_1 , T_2 V_32 ,
struct V_87 * V_88 )
{
return F_25 ( V_1 , V_32 , & V_88 -> V_89 , sizeof( V_88 -> V_89 ) ) &&
F_25 ( V_1 , V_32 + 1 , & V_88 -> V_90 , sizeof( V_88 -> V_90 ) ) ;
}
static bool F_36 ( struct V_1 * V_1 ,
struct V_87 * V_88 )
{
return F_35 ( V_1 ,
V_91 , V_88 ) ;
}
static bool F_37 ( struct V_1 * V_1 ,
struct V_87 * V_88 )
{
return F_35 ( V_1 ,
V_92 , V_88 ) ;
}
static bool
F_38 ( struct V_1 * V_1 ,
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
return F_25 ( V_1 ,
V_102 ,
& args , sizeof( args ) ) ;
}
static bool F_39 ( struct V_1 * V_1 ,
struct V_87 * V_88 )
{
F_29 ( sizeof( V_88 -> V_89 ) != 8 ) ;
F_29 ( sizeof( V_88 -> V_90 ) != 8 ) ;
return F_26 ( V_1 , V_103 ,
& V_88 -> V_89 , sizeof( V_88 -> V_89 ) ) &&
F_26 ( V_1 , V_104 ,
& V_88 -> V_90 , sizeof( V_88 -> V_90 ) ) ;
}
static bool F_40 ( struct V_1 * V_1 , T_2 V_8 )
{
return F_25 ( V_1 , V_105 , & V_8 , 1 ) ;
}
static void F_41 ( struct V_87 * V_88 ,
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
V_112 /= F_42 ( V_52 ) ? : 1 ;
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
F_29 ( sizeof( V_140 ) != 2 ) ;
return F_26 ( V_1 ,
V_141 ,
& V_140 , sizeof( V_140 ) ) ;
}
static bool F_45 ( struct V_1 * V_1 ,
T_5 V_52 )
{
return F_25 ( V_1 , V_142 , & V_52 , 1 ) ;
}
static bool F_46 ( struct V_1 * V_1 ,
T_5 V_52 )
{
return F_25 ( V_1 , V_143 , & V_52 , 1 ) ;
}
static bool F_47 ( struct V_1 * V_1 ,
unsigned V_144 , T_5 V_145 ,
T_5 * V_55 , unsigned V_146 )
{
T_5 V_147 [ 2 ] = { V_144 , 0 } ;
T_5 V_148 , V_149 [ 8 ] ;
int V_16 ;
if ( ! F_25 ( V_1 ,
V_150 ,
V_147 , 2 ) )
return false ;
if ( ! F_26 ( V_1 , V_151 ,
& V_148 , 1 ) )
return false ;
V_148 ++ ;
F_12 ( L_14 ,
V_144 , V_146 , V_148 ) ;
for ( V_16 = 0 ; V_16 < V_148 ; V_16 += 8 ) {
memset ( V_149 , 0 , 8 ) ;
if ( V_16 < V_146 )
memcpy ( V_149 , V_55 + V_16 , F_48 ( unsigned , 8 , V_146 - V_16 ) ) ;
if ( ! F_25 ( V_1 ,
V_152 ,
V_149 , 8 ) )
return false ;
}
return F_25 ( V_1 ,
V_153 ,
& V_145 , 1 ) ;
}
static bool F_49 ( struct V_1 * V_1 )
{
struct V_154 V_155 = {
. type = V_156 ,
. V_157 = V_158 ,
. V_27 = V_159 ,
} ;
T_5 V_160 [ 4 + sizeof( V_155 . V_161 . V_162 ) ] ;
F_50 ( & V_155 ) ;
memcpy ( V_160 , & V_155 , 3 ) ;
V_160 [ 3 ] = V_155 . V_163 ;
memcpy ( & V_160 [ 4 ] , & V_155 . V_161 , sizeof( V_155 . V_161 . V_162 ) ) ;
return F_47 ( V_1 , V_164 ,
V_165 ,
V_160 , sizeof( V_160 ) ) ;
}
static bool F_51 ( struct V_1 * V_1 )
{
struct V_166 V_167 ;
T_6 V_168 ;
V_168 = 1 << V_1 -> V_169 ;
memset ( & V_167 , 0 , sizeof( V_167 ) ) ;
memcpy ( & V_167 , & V_168 , V_84 ( sizeof( V_167 ) , sizeof( V_168 ) ) ) ;
F_29 ( sizeof( V_167 ) != 6 ) ;
return F_25 ( V_1 ,
V_170 ,
& V_167 , sizeof( V_167 ) ) ;
}
static bool
F_52 ( struct V_1 * V_1 ,
const struct V_51 * V_52 )
{
struct V_87 V_171 ;
if ( ! F_34 ( V_1 ,
V_1 -> V_172 ) )
return false ;
F_41 ( & V_171 , V_52 ) ;
if ( ! F_37 ( V_1 , & V_171 ) )
return false ;
return true ;
}
static bool
F_53 ( struct V_1 * V_1 ,
const struct V_51 * V_52 ,
struct V_51 * V_173 )
{
struct V_87 V_174 ;
if ( ! F_27 ( V_1 ) )
return false ;
if ( ! F_38 ( V_1 ,
V_52 -> clock / 10 ,
V_52 -> V_99 ,
V_52 -> V_100 ) )
return false ;
if ( ! F_39 ( V_1 ,
& V_174 ) )
return false ;
F_43 ( V_173 , & V_174 ) ;
V_1 -> V_175 = V_174 . V_90 . V_136 ;
return true ;
}
static bool F_54 ( struct V_2 * V_3 ,
const struct V_51 * V_52 ,
struct V_51 * V_173 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
int V_176 ;
if ( V_1 -> V_177 ) {
if ( ! F_52 ( V_1 , V_52 ) )
return false ;
( void ) F_53 ( V_1 ,
V_52 ,
V_173 ) ;
} else if ( V_1 -> V_97 ) {
if ( ! F_52 ( V_1 ,
V_1 -> V_98 ) )
return false ;
( void ) F_53 ( V_1 ,
V_52 ,
V_173 ) ;
}
V_176 = F_23 ( V_173 ) ;
F_55 ( V_173 , V_176 ) ;
return true ;
}
static void F_56 ( struct V_2 * V_3 ,
struct V_51 * V_52 ,
struct V_51 * V_173 )
{
struct V_9 * V_10 = V_3 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_178 * V_179 = V_3 -> V_179 ;
struct V_180 * V_180 = F_57 ( V_179 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
T_1 V_181 ;
struct V_182 V_183 ;
struct V_87 V_174 , V_171 ;
int V_184 = F_42 ( V_173 ) ;
int V_185 ;
if ( ! V_52 )
return;
V_183 . V_186 = V_1 -> V_172 ;
V_183 . V_187 = 0 ;
F_25 ( V_1 ,
V_188 ,
& V_183 , sizeof( V_183 ) ) ;
if ( ! F_34 ( V_1 ,
V_1 -> V_172 ) )
return;
if ( V_1 -> V_97 )
F_41 ( & V_171 ,
V_1 -> V_98 ) ;
else
F_41 ( & V_171 , V_52 ) ;
if ( ! F_37 ( V_1 , & V_171 ) )
F_58 ( L_15 ,
F_14 ( V_1 ) ) ;
if ( ! F_27 ( V_1 ) )
return;
if ( V_1 -> V_189 ) {
F_45 ( V_1 , V_190 ) ;
F_46 ( V_1 ,
V_191 ) ;
F_49 ( V_1 ) ;
} else
F_45 ( V_1 , V_192 ) ;
if ( V_1 -> V_177 &&
! F_51 ( V_1 ) )
return;
F_41 ( & V_174 , V_173 ) ;
if ( V_1 -> V_177 || V_1 -> V_97 )
V_174 . V_90 . V_136 = V_1 -> V_175 ;
if ( ! F_36 ( V_1 , & V_174 ) )
F_58 ( L_16 ,
F_14 ( V_1 ) ) ;
switch ( V_184 ) {
default:
case 1 : V_185 = V_193 ; break;
case 2 : V_185 = V_194 ; break;
case 4 : V_185 = V_195 ; break;
}
if ( ! F_40 ( V_1 , V_185 ) )
return;
if ( F_59 ( V_10 ) -> V_196 >= 4 ) {
V_181 = V_197 | V_198 ;
if ( V_1 -> V_199 )
V_181 |= V_1 -> V_200 ;
if ( F_59 ( V_10 ) -> V_196 < 5 )
V_181 |= V_201 ;
} else {
V_181 = F_9 ( V_1 -> V_17 ) ;
switch ( V_1 -> V_17 ) {
case V_19 :
V_181 &= V_202 ;
break;
case V_20 :
V_181 &= V_203 ;
break;
}
V_181 |= ( 9 << 19 ) | V_201 ;
}
if ( F_60 ( V_10 ) >= V_204 )
V_181 |= F_61 ( V_180 -> V_205 ) ;
else
V_181 |= F_62 ( V_180 -> V_205 ) ;
if ( V_1 -> V_206 )
V_181 |= V_207 ;
if ( F_59 ( V_10 ) -> V_196 >= 4 ) {
} else if ( F_63 ( V_10 ) || F_64 ( V_10 ) || F_65 ( V_10 ) ) {
} else {
V_181 |= ( V_184 - 1 ) << V_208 ;
}
if ( V_174 . V_90 . V_136 & V_209 &&
F_59 ( V_10 ) -> V_196 < 5 )
V_181 |= V_210 ;
F_7 ( V_1 , V_181 ) ;
}
static bool F_66 ( struct V_211 * V_6 )
{
struct V_7 * V_7 =
F_5 ( & V_6 -> V_4 ) ;
struct V_1 * V_1 = F_3 ( & V_6 -> V_4 ) ;
T_3 V_212 ;
F_31 ( V_1 , & V_212 ) ;
if ( V_212 & V_7 -> V_213 )
return true ;
else
return false ;
}
static bool F_67 ( struct V_214 * V_3 ,
enum V_205 * V_205 )
{
struct V_9 * V_10 = V_3 -> V_4 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_1 * V_1 = F_1 ( & V_3 -> V_4 ) ;
T_1 V_149 ;
V_149 = F_9 ( V_1 -> V_17 ) ;
if ( ! ( V_149 & V_215 ) )
return false ;
if ( F_68 ( V_10 ) )
* V_205 = F_69 ( V_149 ) ;
else
* V_205 = F_70 ( V_149 ) ;
return true ;
}
static void F_71 ( struct V_214 * V_3 )
{
struct V_11 * V_12 = V_3 -> V_4 . V_10 -> V_13 ;
struct V_1 * V_1 = F_1 ( & V_3 -> V_4 ) ;
T_1 V_216 ;
F_30 ( V_1 , 0 ) ;
if ( 0 )
F_32 ( V_1 ,
V_76 ) ;
V_216 = F_9 ( V_1 -> V_17 ) ;
if ( ( V_216 & V_215 ) != 0 ) {
F_7 ( V_1 , V_216 & ~ V_215 ) ;
}
}
static void F_72 ( struct V_214 * V_3 )
{
struct V_9 * V_10 = V_3 -> V_4 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_1 * V_1 = F_1 ( & V_3 -> V_4 ) ;
struct V_180 * V_180 = F_57 ( V_3 -> V_4 . V_179 ) ;
T_1 V_216 ;
bool V_217 , V_218 ;
int V_16 ;
T_2 V_36 ;
V_216 = F_9 ( V_1 -> V_17 ) ;
if ( ( V_216 & V_215 ) == 0 )
F_7 ( V_1 , V_216 | V_215 ) ;
for ( V_16 = 0 ; V_16 < 2 ; V_16 ++ )
F_73 ( V_10 , V_180 -> V_205 ) ;
V_36 = F_28 ( V_1 , & V_217 , & V_218 ) ;
if ( V_36 == V_49 && ! V_217 ) {
F_12 ( L_17
L_18 , F_14 ( V_1 ) ) ;
}
if ( 0 )
F_32 ( V_1 ,
V_71 ) ;
F_30 ( V_1 , V_1 -> V_172 ) ;
}
static void F_74 ( struct V_5 * V_6 , int V_52 )
{
struct V_178 * V_179 ;
struct V_1 * V_1 = F_3 ( V_6 ) ;
if ( V_52 != V_71 )
V_52 = V_76 ;
if ( V_52 == V_6 -> V_219 )
return;
V_6 -> V_219 = V_52 ;
V_179 = V_1 -> V_4 . V_4 . V_179 ;
if ( ! V_179 ) {
V_1 -> V_4 . V_220 = false ;
return;
}
if ( V_52 != V_71 ) {
F_30 ( V_1 , 0 ) ;
if ( 0 )
F_32 ( V_1 , V_52 ) ;
V_1 -> V_4 . V_220 = false ;
F_75 ( V_179 ) ;
} else {
V_1 -> V_4 . V_220 = true ;
F_75 ( V_179 ) ;
if ( 0 )
F_32 ( V_1 , V_52 ) ;
F_30 ( V_1 , V_1 -> V_172 ) ;
}
F_76 ( V_6 -> V_10 ) ;
}
static int F_77 ( struct V_5 * V_6 ,
struct V_51 * V_52 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
if ( V_52 -> V_26 & V_221 )
return V_222 ;
if ( V_1 -> V_223 > V_52 -> clock )
return V_224 ;
if ( V_1 -> V_225 < V_52 -> clock )
return V_226 ;
if ( V_1 -> V_97 ) {
if ( V_52 -> V_99 > V_1 -> V_98 -> V_99 )
return V_227 ;
if ( V_52 -> V_100 > V_1 -> V_98 -> V_100 )
return V_227 ;
}
return V_228 ;
}
static bool F_78 ( struct V_1 * V_1 , struct V_229 * V_230 )
{
F_29 ( sizeof( * V_230 ) != 8 ) ;
if ( ! F_26 ( V_1 ,
V_231 ,
V_230 , sizeof( * V_230 ) ) )
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
V_230 -> V_232 ,
V_230 -> V_233 ,
V_230 -> V_234 ,
V_230 -> V_235 ,
V_230 -> V_236 ,
V_230 -> V_237 ,
V_230 -> V_238 ,
V_230 -> V_239 ,
V_230 -> V_240 ,
V_230 -> V_241 ,
V_230 -> V_242 ,
V_230 -> V_243 ) ;
return true ;
}
static T_4 F_79 ( struct V_1 * V_1 )
{
struct V_9 * V_10 = V_1 -> V_4 . V_4 . V_10 ;
T_4 V_244 ;
if ( F_63 ( V_10 ) || F_64 ( V_10 ) )
return 0 ;
if ( ! F_26 ( V_1 , V_245 ,
& V_244 , sizeof( V_244 ) ) )
return 0 ;
return V_244 ;
}
static void F_80 ( struct V_214 * V_3 )
{
struct V_1 * V_1 = F_1 ( & V_3 -> V_4 ) ;
F_17 ( V_1 , V_246 ,
& V_1 -> V_247 , 2 ) ;
}
static bool
F_81 ( struct V_1 * V_1 )
{
return F_82 ( V_1 -> V_230 . V_243 ) > 1 ;
}
static struct V_248 *
F_83 ( struct V_5 * V_6 )
{
struct V_1 * V_249 = F_3 ( V_6 ) ;
return F_84 ( V_6 , & V_249 -> V_250 ) ;
}
static struct V_248 *
F_85 ( struct V_5 * V_6 )
{
struct V_11 * V_12 = V_6 -> V_10 -> V_13 ;
return F_84 ( V_6 ,
F_86 ( V_12 ,
V_12 -> V_251 ) ) ;
}
static enum V_252
F_87 ( struct V_5 * V_6 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
enum V_252 V_36 ;
struct V_248 * V_248 ;
V_248 = F_83 ( V_6 ) ;
if ( V_248 == NULL && F_81 ( V_1 ) ) {
T_2 V_250 , V_253 = V_1 -> V_53 ;
for ( V_250 = V_1 -> V_53 >> 1 ; V_250 > 1 ; V_250 >>= 1 ) {
V_1 -> V_53 = V_250 ;
V_248 = F_83 ( V_6 ) ;
if ( V_248 )
break;
}
if ( V_248 == NULL )
V_1 -> V_53 = V_253 ;
}
if ( V_248 == NULL )
V_248 = F_85 ( V_6 ) ;
V_36 = V_254 ;
if ( V_248 != NULL ) {
if ( V_248 -> V_255 & V_256 ) {
V_36 = V_257 ;
if ( V_1 -> V_199 ) {
V_1 -> V_189 = F_88 ( V_248 ) ;
V_1 -> V_206 = F_89 ( V_248 ) ;
}
} else
V_36 = V_258 ;
F_20 ( V_248 ) ;
}
if ( V_36 == V_257 ) {
struct V_7 * V_7 = F_5 ( V_6 ) ;
if ( V_7 -> V_259 != V_260 )
V_1 -> V_206 = ( V_7 -> V_259 == V_261 ) ;
}
return V_36 ;
}
static bool
F_90 ( struct V_7 * V_249 ,
struct V_248 * V_248 )
{
bool V_262 = ! ! ( V_248 -> V_255 & V_256 ) ;
bool V_263 = ! ! F_91 ( V_249 ) ;
F_12 ( L_32 ,
V_263 , V_262 ) ;
return V_263 == V_262 ;
}
static enum V_252
F_92 ( struct V_5 * V_6 , bool V_264 )
{
T_4 V_42 ;
struct V_1 * V_1 = F_3 ( V_6 ) ;
struct V_7 * V_7 = F_5 ( V_6 ) ;
enum V_252 V_30 ;
if ( ! F_17 ( V_1 ,
V_265 , NULL , 0 ) )
return V_254 ;
if ( V_1 -> V_230 . V_243 & V_266 )
F_93 ( 30 ) ;
if ( ! F_21 ( V_1 , & V_42 , 2 ) )
return V_254 ;
F_12 ( L_33 ,
V_42 & 0xff , V_42 >> 8 ,
V_7 -> V_213 ) ;
if ( V_42 == 0 )
return V_258 ;
V_1 -> V_172 = V_42 ;
V_1 -> V_189 = false ;
V_1 -> V_206 = false ;
if ( ( V_7 -> V_213 & V_42 ) == 0 )
V_30 = V_258 ;
else if ( F_94 ( V_7 ) )
V_30 = F_87 ( V_6 ) ;
else {
struct V_248 * V_248 ;
V_248 = F_83 ( V_6 ) ;
if ( V_248 == NULL )
V_248 = F_85 ( V_6 ) ;
if ( V_248 != NULL ) {
if ( F_90 ( V_7 ,
V_248 ) )
V_30 = V_257 ;
else
V_30 = V_258 ;
F_20 ( V_248 ) ;
} else
V_30 = V_257 ;
}
if ( V_30 == V_257 ) {
V_1 -> V_177 = false ;
V_1 -> V_97 = false ;
V_1 -> V_4 . V_267 = false ;
if ( V_42 & V_266 ) {
V_1 -> V_177 = true ;
V_1 -> V_4 . V_267 = true ;
}
if ( V_42 & V_268 )
V_1 -> V_97 = V_1 -> V_98 != NULL ;
}
return V_30 ;
}
static void F_95 ( struct V_5 * V_6 )
{
struct V_248 * V_248 ;
V_248 = F_83 ( V_6 ) ;
if ( V_248 == NULL )
V_248 = F_85 ( V_6 ) ;
if ( V_248 != NULL ) {
if ( F_90 ( F_5 ( V_6 ) ,
V_248 ) ) {
F_96 ( V_6 , V_248 ) ;
F_97 ( V_6 , V_248 ) ;
}
F_20 ( V_248 ) ;
}
}
static void F_98 ( struct V_5 * V_6 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
struct V_269 V_270 ;
T_6 V_271 = 0 , V_168 = 0 ;
int V_16 ;
V_168 = 1 << V_1 -> V_169 ;
memcpy ( & V_270 , & V_168 ,
V_84 ( sizeof( V_168 ) , sizeof( struct V_269 ) ) ) ;
if ( ! F_34 ( V_1 , V_1 -> V_172 ) )
return;
F_29 ( sizeof( V_270 ) != 3 ) ;
if ( ! F_17 ( V_1 ,
V_272 ,
& V_270 , sizeof( V_270 ) ) )
return;
if ( ! F_21 ( V_1 , & V_271 , 3 ) )
return;
for ( V_16 = 0 ; V_16 < F_16 ( V_273 ) ; V_16 ++ )
if ( V_271 & ( 1 << V_16 ) ) {
struct V_51 * V_274 ;
V_274 = F_99 ( V_6 -> V_10 ,
& V_273 [ V_16 ] ) ;
if ( V_274 )
F_100 ( V_6 , V_274 ) ;
}
}
static void F_101 ( struct V_5 * V_6 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
struct V_11 * V_12 = V_6 -> V_10 -> V_13 ;
struct V_51 * V_275 ;
F_102 ( V_6 , V_1 -> V_31 ) ;
if ( F_103 ( & V_6 -> V_276 ) == false )
goto V_277;
if ( V_12 -> V_278 != NULL ) {
V_275 = F_99 ( V_6 -> V_10 ,
V_12 -> V_278 ) ;
if ( V_275 != NULL ) {
V_275 -> type = ( V_279 |
V_280 ) ;
F_100 ( V_6 , V_275 ) ;
}
}
V_277:
F_104 (newmode, &connector->probed_modes, head) {
if ( V_275 -> type & V_279 ) {
V_1 -> V_98 =
F_99 ( V_6 -> V_10 , V_275 ) ;
V_1 -> V_97 = true ;
break;
}
}
}
static int F_105 ( struct V_5 * V_6 )
{
struct V_7 * V_7 = F_5 ( V_6 ) ;
if ( F_106 ( V_7 ) )
F_98 ( V_6 ) ;
else if ( F_107 ( V_7 ) )
F_101 ( V_6 ) ;
else
F_95 ( V_6 ) ;
return ! F_103 ( & V_6 -> V_276 ) ;
}
static void
F_108 ( struct V_5 * V_6 )
{
struct V_7 * V_7 = F_5 ( V_6 ) ;
struct V_9 * V_10 = V_6 -> V_10 ;
if ( V_7 -> V_281 )
F_109 ( V_10 , V_7 -> V_281 ) ;
if ( V_7 -> V_282 )
F_109 ( V_10 , V_7 -> V_282 ) ;
if ( V_7 -> V_283 )
F_109 ( V_10 , V_7 -> V_283 ) ;
if ( V_7 -> V_284 )
F_109 ( V_10 , V_7 -> V_284 ) ;
if ( V_7 -> V_285 )
F_109 ( V_10 , V_7 -> V_285 ) ;
if ( V_7 -> V_286 )
F_109 ( V_10 , V_7 -> V_286 ) ;
if ( V_7 -> V_287 )
F_109 ( V_10 , V_7 -> V_287 ) ;
if ( V_7 -> V_288 )
F_109 ( V_10 , V_7 -> V_288 ) ;
if ( V_7 -> V_289 )
F_109 ( V_10 , V_7 -> V_289 ) ;
if ( V_7 -> V_290 )
F_109 ( V_10 , V_7 -> V_290 ) ;
if ( V_7 -> V_291 )
F_109 ( V_10 , V_7 -> V_291 ) ;
if ( V_7 -> V_292 )
F_109 ( V_10 , V_7 -> V_292 ) ;
if ( V_7 -> V_293 )
F_109 ( V_10 , V_7 -> V_293 ) ;
if ( V_7 -> V_294 )
F_109 ( V_10 , V_7 -> V_294 ) ;
if ( V_7 -> V_295 )
F_109 ( V_10 , V_7 -> V_295 ) ;
if ( V_7 -> V_296 )
F_109 ( V_10 , V_7 -> V_296 ) ;
if ( V_7 -> V_297 )
F_109 ( V_10 , V_7 -> V_297 ) ;
}
static void F_110 ( struct V_5 * V_6 )
{
struct V_7 * V_7 = F_5 ( V_6 ) ;
if ( V_7 -> V_298 )
F_109 ( V_6 -> V_10 ,
V_7 -> V_298 ) ;
F_108 ( V_6 ) ;
F_111 ( V_6 ) ;
F_112 ( V_6 ) ;
F_20 ( V_6 ) ;
}
static bool F_113 ( struct V_5 * V_6 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
struct V_248 * V_248 ;
bool V_299 = false ;
if ( ! V_1 -> V_199 )
return false ;
V_248 = F_83 ( V_6 ) ;
if ( V_248 != NULL && V_248 -> V_255 & V_256 )
V_299 = F_89 ( V_248 ) ;
F_20 ( V_248 ) ;
return V_299 ;
}
static int
F_114 ( struct V_5 * V_6 ,
struct V_300 * V_301 ,
T_7 V_8 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
struct V_7 * V_7 = F_5 ( V_6 ) ;
struct V_11 * V_12 = V_6 -> V_10 -> V_13 ;
T_4 V_302 ;
T_5 V_32 ;
int V_30 ;
V_30 = F_115 ( V_6 , V_301 , V_8 ) ;
if ( V_30 )
return V_30 ;
if ( V_301 == V_12 -> V_303 ) {
int V_16 = V_8 ;
bool V_299 ;
if ( V_16 == V_7 -> V_259 )
return 0 ;
V_7 -> V_259 = V_16 ;
if ( V_16 == V_260 )
V_299 = F_113 ( V_6 ) ;
else
V_299 = ( V_16 == V_261 ) ;
if ( V_299 == V_1 -> V_206 )
return 0 ;
V_1 -> V_206 = V_299 ;
goto V_304;
}
if ( V_301 == V_12 -> V_305 ) {
if ( V_8 == ! ! V_1 -> V_200 )
return 0 ;
V_1 -> V_200 = V_8 ? V_306 : 0 ;
goto V_304;
}
#define F_116 ( V_35 , T_8 ) \
if (intel_sdvo_connector->name == property) { \
if (intel_sdvo_connector->cur_##name == temp_value) return 0; \
if (intel_sdvo_connector->max_##name < temp_value) return -EINVAL; \
cmd = SDVO_CMD_SET_##NAME; \
intel_sdvo_connector->cur_##name = temp_value; \
goto set_value; \
}
if ( V_301 == V_7 -> V_298 ) {
if ( V_8 >= V_307 )
return - V_308 ;
if ( V_1 -> V_169 ==
V_7 -> V_309 [ V_8 ] )
return 0 ;
V_1 -> V_169 = V_7 -> V_309 [ V_8 ] ;
goto V_304;
} else if ( F_117 ( V_7 ) ) {
V_302 = V_8 ;
if ( V_7 -> V_281 == V_301 ) {
F_115 ( V_6 ,
V_7 -> V_282 , V_8 ) ;
if ( V_7 -> V_310 == V_302 )
return 0 ;
V_7 -> V_310 = V_302 ;
V_7 -> V_311 = V_302 ;
V_302 = V_7 -> V_312 -
V_7 -> V_310 ;
V_32 = V_313 ;
goto V_314;
} else if ( V_7 -> V_282 == V_301 ) {
F_115 ( V_6 ,
V_7 -> V_281 , V_8 ) ;
if ( V_7 -> V_311 == V_302 )
return 0 ;
V_7 -> V_310 = V_302 ;
V_7 -> V_311 = V_302 ;
V_302 = V_7 -> V_312 -
V_7 -> V_310 ;
V_32 = V_313 ;
goto V_314;
} else if ( V_7 -> V_283 == V_301 ) {
F_115 ( V_6 ,
V_7 -> V_284 , V_8 ) ;
if ( V_7 -> V_315 == V_302 )
return 0 ;
V_7 -> V_315 = V_302 ;
V_7 -> V_316 = V_302 ;
V_302 = V_7 -> V_317 -
V_7 -> V_315 ;
V_32 = V_318 ;
goto V_314;
} else if ( V_7 -> V_284 == V_301 ) {
F_115 ( V_6 ,
V_7 -> V_283 , V_8 ) ;
if ( V_7 -> V_316 == V_302 )
return 0 ;
V_7 -> V_315 = V_302 ;
V_7 -> V_316 = V_302 ;
V_302 = V_7 -> V_317 -
V_7 -> V_315 ;
V_32 = V_318 ;
goto V_314;
}
F_116 (hpos, HPOS)
F_116 (vpos, VPOS)
F_116 (saturation, SATURATION)
F_116 (contrast, CONTRAST)
F_116 (hue, HUE)
F_116 (brightness, BRIGHTNESS)
F_116 (sharpness, SHARPNESS)
F_116 (flicker_filter, FLICKER_FILTER)
F_116 (flicker_filter_2d, FLICKER_FILTER_2D)
F_116 (flicker_filter_adaptive, FLICKER_FILTER_ADAPTIVE)
F_116 (tv_chroma_filter, TV_CHROMA_FILTER)
F_116 (tv_luma_filter, TV_LUMA_FILTER)
F_116 (dot_crawl, DOT_CRAWL)
}
return - V_308 ;
V_314:
if ( ! F_25 ( V_1 , V_32 , & V_302 , 2 ) )
return - V_319 ;
V_304:
if ( V_1 -> V_4 . V_4 . V_179 ) {
struct V_178 * V_179 = V_1 -> V_4 . V_4 . V_179 ;
F_118 ( V_179 , & V_179 -> V_52 ,
V_179 -> V_320 , V_179 -> V_321 , V_179 -> V_322 ) ;
}
return 0 ;
#undef F_116
}
static void F_119 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
if ( V_1 -> V_98 != NULL )
F_120 ( V_3 -> V_10 ,
V_1 -> V_98 ) ;
F_121 ( & V_1 -> V_250 ) ;
F_122 ( V_3 ) ;
}
static void
F_123 ( struct V_1 * V_249 )
{
T_4 V_323 = 0 ;
unsigned int V_324 ;
switch ( V_249 -> V_325 ) {
case V_326 :
V_323 |= V_326 ;
case V_327 :
V_323 |= V_327 ;
case V_328 :
V_323 |= V_328 ;
case V_329 :
V_323 |= V_329 ;
case V_330 :
V_323 |= V_330 ;
case V_331 :
V_323 |= V_331 ;
break;
}
V_323 &= V_249 -> V_230 . V_243 ;
V_324 = F_82 ( V_323 ) ;
if ( V_324 > 3 )
V_324 = 3 ;
V_249 -> V_53 = 1 << V_324 ;
}
static void
F_124 ( struct V_11 * V_12 ,
struct V_1 * V_249 , T_1 V_332 )
{
struct V_333 * V_334 ;
if ( V_249 -> V_335 )
V_334 = & ( V_12 -> V_336 [ 0 ] ) ;
else
V_334 = & ( V_12 -> V_336 [ 1 ] ) ;
if ( V_334 -> V_337 )
V_249 -> V_53 = 1 << ( ( V_334 -> V_338 & 0xf0 ) >> 4 ) ;
else
F_123 ( V_249 ) ;
}
static void
F_125 ( struct V_11 * V_12 ,
struct V_1 * V_249 , T_1 V_332 )
{
struct V_333 * V_334 ;
T_2 V_339 ;
if ( V_249 -> V_335 )
V_334 = & V_12 -> V_336 [ 0 ] ;
else
V_334 = & V_12 -> V_336 [ 1 ] ;
V_339 = V_340 ;
if ( V_334 -> V_337 )
V_339 = V_334 -> V_341 ;
if ( F_126 ( V_339 ) ) {
V_249 -> V_31 = F_86 ( V_12 , V_339 ) ;
F_127 ( V_249 -> V_31 , V_342 ) ;
F_128 ( V_249 -> V_31 , true ) ;
} else {
V_249 -> V_31 = F_86 ( V_12 , V_340 ) ;
}
}
static bool
F_129 ( struct V_1 * V_1 , int V_343 )
{
return F_44 ( V_1 ) ;
}
static T_2
F_130 ( struct V_9 * V_10 , struct V_1 * V_249 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_333 * V_344 , * V_345 ;
if ( V_249 -> V_335 ) {
V_344 = & V_12 -> V_336 [ 0 ] ;
V_345 = & V_12 -> V_336 [ 1 ] ;
} else {
V_344 = & V_12 -> V_336 [ 1 ] ;
V_345 = & V_12 -> V_336 [ 0 ] ;
}
if ( V_344 -> V_25 )
return V_344 -> V_25 ;
if ( V_345 -> V_25 ) {
if ( V_345 -> V_25 == 0x70 )
return 0x72 ;
else
return 0x70 ;
}
if ( V_249 -> V_335 )
return 0x70 ;
else
return 0x72 ;
}
static void
F_131 ( struct V_7 * V_6 ,
struct V_1 * V_3 )
{
F_132 ( V_3 -> V_4 . V_4 . V_10 ,
& V_6 -> V_4 . V_4 ,
& V_346 ,
V_6 -> V_4 . V_4 . V_347 ) ;
F_133 ( & V_6 -> V_4 . V_4 ,
& V_348 ) ;
V_6 -> V_4 . V_4 . V_349 = 1 ;
V_6 -> V_4 . V_4 . V_350 = 0 ;
V_6 -> V_4 . V_4 . V_351 . V_352 = V_353 ;
V_6 -> V_4 . V_354 = F_66 ;
F_134 ( & V_6 -> V_4 , & V_3 -> V_4 ) ;
F_135 ( & V_6 -> V_4 . V_4 ) ;
}
static void
F_136 ( struct V_7 * V_6 )
{
struct V_9 * V_10 = V_6 -> V_4 . V_4 . V_10 ;
F_137 ( & V_6 -> V_4 . V_4 ) ;
if ( F_59 ( V_10 ) -> V_196 >= 4 && F_138 ( V_10 ) )
F_139 ( & V_6 -> V_4 . V_4 ) ;
}
static bool
F_140 ( struct V_1 * V_1 , int V_343 )
{
struct V_2 * V_3 = & V_1 -> V_4 . V_4 ;
struct V_5 * V_6 ;
struct V_214 * V_214 = F_141 ( V_3 ) ;
struct V_211 * V_211 ;
struct V_7 * V_7 ;
V_7 = F_18 ( sizeof( struct V_7 ) , V_37 ) ;
if ( ! V_7 )
return false ;
if ( V_343 == 0 ) {
V_1 -> V_325 |= V_329 ;
V_7 -> V_213 = V_329 ;
} else if ( V_343 == 1 ) {
V_1 -> V_325 |= V_328 ;
V_7 -> V_213 = V_328 ;
}
V_211 = & V_7 -> V_4 ;
V_6 = & V_211 -> V_4 ;
if ( F_79 ( V_1 ) &
V_7 -> V_213 ) {
V_6 -> V_355 = V_356 ;
V_1 -> V_247 |= V_7 -> V_213 ;
V_214 -> V_357 = F_80 ;
F_80 ( V_214 ) ;
} else {
V_6 -> V_355 = V_358 | V_359 ;
}
V_3 -> V_360 = V_361 ;
V_6 -> V_347 = V_362 ;
if ( F_129 ( V_1 , V_343 ) ) {
V_6 -> V_347 = V_363 ;
V_1 -> V_199 = true ;
}
F_131 ( V_7 , V_1 ) ;
if ( V_1 -> V_199 )
F_136 ( V_7 ) ;
return true ;
}
static bool
F_142 ( struct V_1 * V_1 , int type )
{
struct V_2 * V_3 = & V_1 -> V_4 . V_4 ;
struct V_5 * V_6 ;
struct V_211 * V_211 ;
struct V_7 * V_7 ;
V_7 = F_18 ( sizeof( struct V_7 ) , V_37 ) ;
if ( ! V_7 )
return false ;
V_211 = & V_7 -> V_4 ;
V_6 = & V_211 -> V_4 ;
V_3 -> V_360 = V_364 ;
V_6 -> V_347 = V_365 ;
V_1 -> V_325 |= type ;
V_7 -> V_213 = type ;
V_1 -> V_177 = true ;
V_1 -> V_4 . V_267 = true ;
F_131 ( V_7 , V_1 ) ;
if ( ! F_143 ( V_1 , V_7 , type ) )
goto V_366;
if ( ! F_144 ( V_1 , V_7 ) )
goto V_366;
return true ;
V_366:
F_110 ( V_6 ) ;
return false ;
}
static bool
F_145 ( struct V_1 * V_1 , int V_343 )
{
struct V_2 * V_3 = & V_1 -> V_4 . V_4 ;
struct V_5 * V_6 ;
struct V_211 * V_211 ;
struct V_7 * V_7 ;
V_7 = F_18 ( sizeof( struct V_7 ) , V_37 ) ;
if ( ! V_7 )
return false ;
V_211 = & V_7 -> V_4 ;
V_6 = & V_211 -> V_4 ;
V_6 -> V_355 = V_358 ;
V_3 -> V_360 = V_367 ;
V_6 -> V_347 = V_368 ;
if ( V_343 == 0 ) {
V_1 -> V_325 |= V_331 ;
V_7 -> V_213 = V_331 ;
} else if ( V_343 == 1 ) {
V_1 -> V_325 |= V_330 ;
V_7 -> V_213 = V_330 ;
}
F_131 ( V_7 ,
V_1 ) ;
return true ;
}
static bool
F_146 ( struct V_1 * V_1 , int V_343 )
{
struct V_2 * V_3 = & V_1 -> V_4 . V_4 ;
struct V_5 * V_6 ;
struct V_211 * V_211 ;
struct V_7 * V_7 ;
V_7 = F_18 ( sizeof( struct V_7 ) , V_37 ) ;
if ( ! V_7 )
return false ;
V_211 = & V_7 -> V_4 ;
V_6 = & V_211 -> V_4 ;
V_3 -> V_360 = V_369 ;
V_6 -> V_347 = V_370 ;
if ( V_343 == 0 ) {
V_1 -> V_325 |= V_327 ;
V_7 -> V_213 = V_327 ;
} else if ( V_343 == 1 ) {
V_1 -> V_325 |= V_326 ;
V_7 -> V_213 = V_326 ;
}
F_131 ( V_7 , V_1 ) ;
if ( ! F_144 ( V_1 , V_7 ) )
goto V_366;
return true ;
V_366:
F_110 ( V_6 ) ;
return false ;
}
static bool
F_147 ( struct V_1 * V_1 , T_4 V_26 )
{
V_1 -> V_177 = false ;
V_1 -> V_4 . V_267 = false ;
V_1 -> V_97 = false ;
if ( V_26 & V_329 )
if ( ! F_140 ( V_1 , 0 ) )
return false ;
if ( ( V_26 & V_371 ) == V_371 )
if ( ! F_140 ( V_1 , 1 ) )
return false ;
if ( V_26 & V_372 )
if ( ! F_142 ( V_1 , V_372 ) )
return false ;
if ( V_26 & V_373 )
if ( ! F_142 ( V_1 , V_373 ) )
return false ;
if ( V_26 & V_374 )
if ( ! F_142 ( V_1 , V_374 ) )
return false ;
if ( V_26 & V_331 )
if ( ! F_145 ( V_1 , 0 ) )
return false ;
if ( ( V_26 & V_375 ) == V_375 )
if ( ! F_145 ( V_1 , 1 ) )
return false ;
if ( V_26 & V_327 )
if ( ! F_146 ( V_1 , 0 ) )
return false ;
if ( ( V_26 & V_268 ) == V_268 )
if ( ! F_146 ( V_1 , 1 ) )
return false ;
if ( ( V_26 & V_376 ) == 0 ) {
unsigned char V_377 [ 2 ] ;
V_1 -> V_325 = 0 ;
memcpy ( V_377 , & V_1 -> V_230 . V_243 , 2 ) ;
F_12 ( L_34 ,
F_14 ( V_1 ) ,
V_377 [ 0 ] , V_377 [ 1 ] ) ;
return false ;
}
V_1 -> V_4 . V_378 = ( 1 << 0 ) | ( 1 << 1 ) | ( 1 << 2 ) ;
return true ;
}
static void F_148 ( struct V_1 * V_1 )
{
struct V_9 * V_10 = V_1 -> V_4 . V_4 . V_10 ;
struct V_5 * V_6 , * V_149 ;
F_149 (connector, tmp,
&dev->mode_config.connector_list, head) {
if ( F_4 ( V_6 ) == & V_1 -> V_4 )
F_110 ( V_6 ) ;
}
}
static bool F_143 ( struct V_1 * V_1 ,
struct V_7 * V_7 ,
int type )
{
struct V_9 * V_10 = V_1 -> V_4 . V_4 . V_10 ;
struct V_166 V_167 ;
T_6 V_168 , V_16 ;
if ( ! F_34 ( V_1 , type ) )
return false ;
F_29 ( sizeof( V_167 ) != 6 ) ;
if ( ! F_26 ( V_1 ,
V_379 ,
& V_167 , sizeof( V_167 ) ) )
return false ;
memcpy ( & V_168 , & V_167 , V_84 ( sizeof( V_168 ) , sizeof( V_167 ) ) ) ;
if ( V_168 == 0 )
return false ;
V_7 -> V_380 = 0 ;
for ( V_16 = 0 ; V_16 < V_307 ; V_16 ++ )
if ( V_168 & ( 1 << V_16 ) )
V_7 -> V_309 [ V_7 -> V_380 ++ ] = V_16 ;
V_7 -> V_298 =
F_150 ( V_10 , V_381 ,
L_35 , V_7 -> V_380 ) ;
if ( ! V_7 -> V_298 )
return false ;
for ( V_16 = 0 ; V_16 < V_7 -> V_380 ; V_16 ++ )
F_151 (
V_7 -> V_298 , V_16 ,
V_16 , V_382 [ V_7 -> V_309 [ V_16 ] ] ) ;
V_1 -> V_169 = V_7 -> V_309 [ 0 ] ;
F_152 ( & V_7 -> V_4 . V_4 ,
V_7 -> V_298 , 0 ) ;
return true ;
}
static bool
F_153 ( struct V_1 * V_1 ,
struct V_7 * V_7 ,
struct V_383 V_384 )
{
struct V_9 * V_10 = V_1 -> V_4 . V_4 . V_10 ;
struct V_5 * V_6 = & V_7 -> V_4 . V_4 ;
T_4 V_42 , V_385 [ 2 ] ;
if ( V_384 . V_386 ) {
if ( ! F_26 ( V_1 ,
V_387 ,
& V_385 , 4 ) )
return false ;
if ( ! F_26 ( V_1 ,
V_388 ,
& V_42 , 2 ) )
return false ;
V_7 -> V_312 = V_385 [ 0 ] ;
V_7 -> V_310 = V_385 [ 0 ] - V_42 ;
V_7 -> V_311 = V_7 -> V_310 ;
V_7 -> V_281 =
F_154 ( V_10 , 0 , L_36 , 0 , V_385 [ 0 ] ) ;
if ( ! V_7 -> V_281 )
return false ;
F_152 ( V_6 ,
V_7 -> V_281 ,
V_7 -> V_310 ) ;
V_7 -> V_282 =
F_154 ( V_10 , 0 , L_37 , 0 , V_385 [ 0 ] ) ;
if ( ! V_7 -> V_282 )
return false ;
F_152 ( V_6 ,
V_7 -> V_282 ,
V_7 -> V_311 ) ;
F_12 ( L_38
L_39 ,
V_385 [ 0 ] , V_385 [ 1 ] , V_42 ) ;
}
if ( V_384 . V_389 ) {
if ( ! F_26 ( V_1 ,
V_390 ,
& V_385 , 4 ) )
return false ;
if ( ! F_26 ( V_1 ,
V_391 ,
& V_42 , 2 ) )
return false ;
V_7 -> V_317 = V_385 [ 0 ] ;
V_7 -> V_315 = V_385 [ 0 ] - V_42 ;
V_7 -> V_316 = V_7 -> V_315 ;
V_7 -> V_283 =
F_154 ( V_10 , 0 ,
L_40 , 0 , V_385 [ 0 ] ) ;
if ( ! V_7 -> V_283 )
return false ;
F_152 ( V_6 ,
V_7 -> V_283 ,
V_7 -> V_315 ) ;
V_7 -> V_284 =
F_154 ( V_10 , 0 ,
L_41 , 0 , V_385 [ 0 ] ) ;
if ( ! V_7 -> V_284 )
return false ;
F_152 ( V_6 ,
V_7 -> V_284 ,
V_7 -> V_316 ) ;
F_12 ( L_42
L_39 ,
V_385 [ 0 ] , V_385 [ 1 ] , V_42 ) ;
}
F_155 ( V_285 , V_392 ) ;
F_155 ( V_286 , V_393 ) ;
F_155 ( V_287 , V_394 ) ;
F_155 ( V_288 , V_395 ) ;
F_155 ( V_289 , V_396 ) ;
F_155 ( V_290 , V_397 ) ;
F_155 ( V_297 , V_398 ) ;
F_155 ( V_291 , V_399 ) ;
F_155 ( V_293 , V_400 ) ;
F_155 ( V_292 , V_401 ) ;
F_155 ( V_295 , V_402 ) ;
F_155 ( V_294 , V_403 ) ;
if ( V_384 . V_296 ) {
if ( ! F_26 ( V_1 , V_404 , & V_42 , 2 ) )
return false ;
V_7 -> V_405 = 1 ;
V_7 -> V_406 = V_42 & 0x1 ;
V_7 -> V_296 =
F_154 ( V_10 , 0 , L_43 , 0 , 1 ) ;
if ( ! V_7 -> V_296 )
return false ;
F_152 ( V_6 ,
V_7 -> V_296 ,
V_7 -> V_406 ) ;
F_12 ( L_44 , V_42 ) ;
}
return true ;
}
static bool
F_156 ( struct V_1 * V_1 ,
struct V_7 * V_7 ,
struct V_383 V_384 )
{
struct V_9 * V_10 = V_1 -> V_4 . V_4 . V_10 ;
struct V_5 * V_6 = & V_7 -> V_4 . V_4 ;
T_4 V_42 , V_385 [ 2 ] ;
F_155 ( V_297 , V_398 ) ;
return true ;
}
static bool F_144 ( struct V_1 * V_1 ,
struct V_7 * V_7 )
{
union {
struct V_383 V_271 ;
T_4 V_42 ;
} V_384 ;
F_29 ( sizeof( V_384 ) != 2 ) ;
V_384 . V_42 = 0 ;
F_26 ( V_1 ,
V_407 ,
& V_384 , sizeof( V_384 ) ) ;
if ( V_384 . V_42 == 0 ) {
F_12 ( L_45 ) ;
return true ;
}
if ( F_106 ( V_7 ) )
return F_153 ( V_1 , V_7 , V_384 . V_271 ) ;
else if ( F_107 ( V_7 ) )
return F_156 ( V_1 , V_7 , V_384 . V_271 ) ;
else
return true ;
}
static int F_157 ( struct V_408 * V_409 ,
struct V_23 * V_24 ,
int V_410 )
{
struct V_1 * V_249 = V_409 -> V_411 ;
if ( ! F_24 ( V_249 , V_249 -> V_53 ) )
return - V_319 ;
return V_249 -> V_31 -> V_412 -> V_413 ( V_249 -> V_31 , V_24 , V_410 ) ;
}
static T_1 F_158 ( struct V_408 * V_409 )
{
struct V_1 * V_249 = V_409 -> V_411 ;
return V_249 -> V_31 -> V_412 -> V_414 ( V_249 -> V_31 ) ;
}
static bool
F_159 ( struct V_1 * V_249 ,
struct V_9 * V_10 )
{
V_249 -> V_250 . V_415 = V_416 ;
V_249 -> V_250 . V_417 = V_418 ;
snprintf ( V_249 -> V_250 . V_35 , V_419 , L_46 ) ;
V_249 -> V_250 . V_10 . V_420 = & V_10 -> V_421 -> V_10 ;
V_249 -> V_250 . V_411 = V_249 ;
V_249 -> V_250 . V_412 = & V_422 ;
return F_160 ( & V_249 -> V_250 ) == 0 ;
}
bool F_161 ( struct V_9 * V_10 , T_6 V_17 , bool V_335 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_214 * V_214 ;
struct V_1 * V_1 ;
T_1 V_423 ;
int V_16 ;
V_1 = F_18 ( sizeof( struct V_1 ) , V_37 ) ;
if ( ! V_1 )
return false ;
V_1 -> V_17 = V_17 ;
V_1 -> V_335 = V_335 ;
V_1 -> V_25 = F_130 ( V_10 , V_1 ) >> 1 ;
F_125 ( V_12 , V_1 , V_17 ) ;
if ( ! F_159 ( V_1 , V_10 ) ) {
F_20 ( V_1 ) ;
return false ;
}
V_214 = & V_1 -> V_4 ;
V_214 -> type = V_424 ;
F_162 ( V_10 , & V_214 -> V_4 , & V_425 , 0 ) ;
for ( V_16 = 0 ; V_16 < 0x40 ; V_16 ++ ) {
T_2 V_426 ;
if ( ! F_10 ( V_1 , V_16 , & V_426 ) ) {
F_12 ( L_47 ,
F_14 ( V_1 ) ) ;
goto V_366;
}
}
V_423 = 0 ;
if ( F_163 ( V_10 ) ) {
V_423 = V_1 -> V_335 ?
V_427 : V_428 ;
} else if ( F_164 ( V_10 ) ) {
V_423 = V_1 -> V_335 ?
V_429 : V_430 ;
} else {
V_423 = V_1 -> V_335 ?
V_431 : V_432 ;
}
F_165 ( & V_214 -> V_4 , & V_433 ) ;
V_214 -> V_434 = F_71 ;
V_214 -> V_435 = F_72 ;
V_214 -> V_354 = F_67 ;
if ( ! F_78 ( V_1 , & V_1 -> V_230 ) )
goto V_366;
if ( F_147 ( V_1 ,
V_1 -> V_230 . V_243 ) != true ) {
F_12 ( L_48 ,
F_14 ( V_1 ) ) ;
goto V_436;
}
V_1 -> V_4 . V_437 = false ;
if ( V_1 -> V_247 )
V_12 -> V_438 |= V_423 ;
F_124 ( V_12 , V_1 , V_17 ) ;
if ( ! F_27 ( V_1 ) )
goto V_436;
if ( ! F_33 ( V_1 ,
& V_1 -> V_223 ,
& V_1 -> V_225 ) )
goto V_436;
F_12 ( L_49
L_50
L_51
L_52 ,
F_14 ( V_1 ) ,
V_1 -> V_230 . V_232 , V_1 -> V_230 . V_233 ,
V_1 -> V_230 . V_234 ,
V_1 -> V_223 / 1000 ,
V_1 -> V_225 / 1000 ,
( V_1 -> V_230 . V_237 & 0x1 ) ? 'Y' : 'N' ,
( V_1 -> V_230 . V_237 & 0x2 ) ? 'Y' : 'N' ,
V_1 -> V_230 . V_243 &
( V_329 | V_331 ) ? 'Y' : 'N' ,
V_1 -> V_230 . V_243 &
( V_328 | V_330 ) ? 'Y' : 'N' ) ;
return true ;
V_436:
F_148 ( V_1 ) ;
V_366:
F_166 ( & V_214 -> V_4 ) ;
F_121 ( & V_1 -> V_250 ) ;
F_20 ( V_1 ) ;
return false ;
}
