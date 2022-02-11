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
int V_52 )
{
T_2 V_68 = V_69 ;
switch ( V_52 ) {
case V_70 :
V_68 = V_69 ;
break;
case V_71 :
V_68 = V_72 ;
break;
case V_73 :
V_68 = V_74 ;
break;
case V_75 :
V_68 = V_76 ;
break;
}
return F_25 ( V_1 ,
V_77 , & V_68 , sizeof( V_68 ) ) ;
}
static bool F_32 ( struct V_1 * V_1 ,
int * V_78 ,
int * V_79 )
{
struct V_80 V_81 ;
F_29 ( sizeof( V_81 ) != 4 ) ;
if ( ! F_26 ( V_1 ,
V_82 ,
& V_81 , sizeof( V_81 ) ) )
return false ;
* V_78 = V_81 . V_83 * 10 ;
* V_79 = V_81 . V_84 * 10 ;
return true ;
}
static bool F_33 ( struct V_1 * V_1 ,
T_3 V_66 )
{
return F_25 ( V_1 ,
V_85 ,
& V_66 , sizeof( V_66 ) ) ;
}
static bool F_34 ( struct V_1 * V_1 , T_2 V_32 ,
struct V_86 * V_87 )
{
return F_25 ( V_1 , V_32 , & V_87 -> V_88 , sizeof( V_87 -> V_88 ) ) &&
F_25 ( V_1 , V_32 + 1 , & V_87 -> V_89 , sizeof( V_87 -> V_89 ) ) ;
}
static bool F_35 ( struct V_1 * V_1 ,
struct V_86 * V_87 )
{
return F_34 ( V_1 ,
V_90 , V_87 ) ;
}
static bool F_36 ( struct V_1 * V_1 ,
struct V_86 * V_87 )
{
return F_34 ( V_1 ,
V_91 , V_87 ) ;
}
static bool
F_37 ( struct V_1 * V_1 ,
T_4 clock ,
T_4 V_92 ,
T_4 V_93 )
{
struct V_94 args ;
memset ( & args , 0 , sizeof( args ) ) ;
args . clock = clock ;
args . V_92 = V_92 ;
args . V_93 = V_93 ;
args . V_95 = 0 ;
if ( V_1 -> V_96 &&
( V_1 -> V_97 -> V_98 != V_92 ||
V_1 -> V_97 -> V_99 != V_93 ) )
args . V_100 = 1 ;
return F_25 ( V_1 ,
V_101 ,
& args , sizeof( args ) ) ;
}
static bool F_38 ( struct V_1 * V_1 ,
struct V_86 * V_87 )
{
F_29 ( sizeof( V_87 -> V_88 ) != 8 ) ;
F_29 ( sizeof( V_87 -> V_89 ) != 8 ) ;
return F_26 ( V_1 , V_102 ,
& V_87 -> V_88 , sizeof( V_87 -> V_88 ) ) &&
F_26 ( V_1 , V_103 ,
& V_87 -> V_89 , sizeof( V_87 -> V_89 ) ) ;
}
static bool F_39 ( struct V_1 * V_1 , T_2 V_8 )
{
return F_25 ( V_1 , V_104 , & V_8 , 1 ) ;
}
static void F_40 ( struct V_86 * V_87 ,
const struct V_51 * V_52 )
{
T_4 V_92 , V_93 ;
T_4 V_105 , V_106 , V_107 , V_108 ;
T_4 V_109 , V_110 ;
int V_111 ;
V_92 = V_52 -> V_98 ;
V_93 = V_52 -> V_99 ;
V_105 = V_52 -> V_112 - V_52 -> V_98 ;
V_106 = V_52 -> V_113 - V_52 -> V_114 ;
V_107 = V_52 -> V_115 - V_52 -> V_99 ;
V_108 = V_52 -> V_116 - V_52 -> V_117 ;
V_109 = V_52 -> V_114 - V_52 -> V_98 ;
V_110 = V_52 -> V_117 - V_52 -> V_99 ;
V_111 = V_52 -> clock ;
V_111 /= F_41 ( V_52 ) ? : 1 ;
V_111 /= 10 ;
V_87 -> V_88 . clock = V_111 ;
V_87 -> V_88 . V_118 = V_92 & 0xff ;
V_87 -> V_88 . V_119 = V_105 & 0xff ;
V_87 -> V_88 . V_120 = ( ( ( V_92 >> 8 ) & 0xf ) << 4 ) |
( ( V_105 >> 8 ) & 0xf ) ;
V_87 -> V_88 . V_121 = V_93 & 0xff ;
V_87 -> V_88 . V_122 = V_107 & 0xff ;
V_87 -> V_88 . V_123 = ( ( ( V_93 >> 8 ) & 0xf ) << 4 ) |
( ( V_107 >> 8 ) & 0xf ) ;
V_87 -> V_89 . V_124 = V_109 & 0xff ;
V_87 -> V_89 . V_125 = V_106 & 0xff ;
V_87 -> V_89 . V_126 = ( V_110 & 0xf ) << 4 |
( V_108 & 0xf ) ;
V_87 -> V_89 . V_127 = ( ( V_109 & 0x300 ) >> 2 ) |
( ( V_106 & 0x300 ) >> 4 ) | ( ( V_110 & 0x30 ) >> 2 ) |
( ( V_108 & 0x30 ) >> 4 ) ;
V_87 -> V_89 . V_128 = 0x18 ;
if ( V_52 -> V_26 & V_129 )
V_87 -> V_89 . V_128 |= V_130 ;
if ( V_52 -> V_26 & V_131 )
V_87 -> V_89 . V_128 |= V_132 ;
if ( V_52 -> V_26 & V_133 )
V_87 -> V_89 . V_128 |= V_134 ;
V_87 -> V_89 . V_135 = 0 ;
V_87 -> V_89 . V_136 = V_110 & 0xc0 ;
V_87 -> V_89 . V_137 = 0 ;
}
static void F_42 ( struct V_51 * V_52 ,
const struct V_86 * V_87 )
{
V_52 -> V_98 = V_87 -> V_88 . V_118 ;
V_52 -> V_98 += ( ( V_87 -> V_88 . V_120 >> 4 ) & 0x0f ) << 8 ;
V_52 -> V_114 = V_52 -> V_98 + V_87 -> V_89 . V_124 ;
V_52 -> V_114 += ( V_87 -> V_89 . V_127 & 0xc0 ) << 2 ;
V_52 -> V_113 = V_52 -> V_114 + V_87 -> V_89 . V_125 ;
V_52 -> V_113 += ( V_87 -> V_89 . V_127 & 0x30 ) << 4 ;
V_52 -> V_112 = V_52 -> V_98 + V_87 -> V_88 . V_119 ;
V_52 -> V_112 += ( V_87 -> V_88 . V_120 & 0xf ) << 8 ;
V_52 -> V_99 = V_87 -> V_88 . V_121 ;
V_52 -> V_99 += ( ( V_87 -> V_88 . V_123 >> 4 ) & 0x0f ) << 8 ;
V_52 -> V_117 = V_52 -> V_99 ;
V_52 -> V_117 += ( V_87 -> V_89 . V_126 >> 4 ) & 0xf ;
V_52 -> V_117 += ( V_87 -> V_89 . V_127 & 0x0c ) << 2 ;
V_52 -> V_117 += V_87 -> V_89 . V_136 & 0xc0 ;
V_52 -> V_116 = V_52 -> V_117 +
( V_87 -> V_89 . V_126 & 0xf ) ;
V_52 -> V_116 += ( V_87 -> V_89 . V_127 & 0x3 ) << 4 ;
V_52 -> V_115 = V_52 -> V_99 + V_87 -> V_88 . V_122 ;
V_52 -> V_115 += ( V_87 -> V_88 . V_123 & 0xf ) << 8 ;
V_52 -> clock = V_87 -> V_88 . clock * 10 ;
V_52 -> V_26 &= ~ ( V_131 | V_133 ) ;
if ( V_87 -> V_89 . V_128 & V_130 )
V_52 -> V_26 |= V_129 ;
if ( V_87 -> V_89 . V_128 & V_132 )
V_52 -> V_26 |= V_131 ;
if ( V_87 -> V_89 . V_128 & V_134 )
V_52 -> V_26 |= V_133 ;
}
static bool F_43 ( struct V_1 * V_1 )
{
struct V_138 V_139 ;
F_29 ( sizeof( V_139 ) != 2 ) ;
return F_26 ( V_1 ,
V_140 ,
& V_139 , sizeof( V_139 ) ) ;
}
static bool F_44 ( struct V_1 * V_1 ,
T_5 V_52 )
{
return F_25 ( V_1 , V_141 , & V_52 , 1 ) ;
}
static bool F_45 ( struct V_1 * V_1 ,
T_5 V_52 )
{
return F_25 ( V_1 , V_142 , & V_52 , 1 ) ;
}
static bool F_46 ( struct V_1 * V_1 )
{
struct V_143 V_144 = {
. type = V_145 ,
. V_146 = V_147 ,
. V_27 = V_148 ,
} ;
T_5 V_149 = V_150 ;
T_5 V_151 [ 2 ] = { 1 , 0 } ;
T_5 V_152 [ 4 + sizeof( V_144 . V_153 . V_154 ) ] ;
T_6 * V_55 = ( T_6 * ) V_152 ;
unsigned V_16 ;
F_47 ( & V_144 ) ;
memcpy ( V_152 , & V_144 , 3 ) ;
V_152 [ 3 ] = V_144 . V_155 ;
memcpy ( & V_152 [ 4 ] , & V_144 . V_153 , sizeof( V_144 . V_153 . V_154 ) ) ;
if ( ! F_25 ( V_1 ,
V_156 ,
V_151 , 2 ) )
return false ;
for ( V_16 = 0 ; V_16 < sizeof( V_152 ) ; V_16 += 8 ) {
if ( ! F_25 ( V_1 ,
V_157 ,
V_55 , 8 ) )
return false ;
V_55 ++ ;
}
return F_25 ( V_1 ,
V_158 ,
& V_149 , 1 ) ;
}
static bool F_48 ( struct V_1 * V_1 )
{
struct V_159 V_160 ;
T_7 V_161 ;
V_161 = 1 << V_1 -> V_162 ;
memset ( & V_160 , 0 , sizeof( V_160 ) ) ;
memcpy ( & V_160 , & V_161 , V_83 ( sizeof( V_160 ) , sizeof( V_161 ) ) ) ;
F_29 ( sizeof( V_160 ) != 6 ) ;
return F_25 ( V_1 ,
V_163 ,
& V_160 , sizeof( V_160 ) ) ;
}
static bool
F_49 ( struct V_1 * V_1 ,
const struct V_51 * V_52 )
{
struct V_86 V_164 ;
if ( ! F_33 ( V_1 ,
V_1 -> V_165 ) )
return false ;
F_40 ( & V_164 , V_52 ) ;
if ( ! F_36 ( V_1 , & V_164 ) )
return false ;
return true ;
}
static bool
F_50 ( struct V_1 * V_1 ,
const struct V_51 * V_52 ,
struct V_51 * V_166 )
{
struct V_86 V_167 ;
if ( ! F_27 ( V_1 ) )
return false ;
if ( ! F_37 ( V_1 ,
V_52 -> clock / 10 ,
V_52 -> V_98 ,
V_52 -> V_99 ) )
return false ;
if ( ! F_38 ( V_1 ,
& V_167 ) )
return false ;
F_42 ( V_166 , & V_167 ) ;
return true ;
}
static bool F_51 ( struct V_2 * V_3 ,
const struct V_51 * V_52 ,
struct V_51 * V_166 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
int V_168 ;
if ( V_1 -> V_169 ) {
if ( ! F_49 ( V_1 , V_52 ) )
return false ;
( void ) F_50 ( V_1 ,
V_52 ,
V_166 ) ;
} else if ( V_1 -> V_96 ) {
if ( ! F_49 ( V_1 ,
V_1 -> V_97 ) )
return false ;
( void ) F_50 ( V_1 ,
V_52 ,
V_166 ) ;
}
V_168 = F_23 ( V_166 ) ;
F_52 ( V_166 , V_168 ) ;
return true ;
}
static void F_53 ( struct V_2 * V_3 ,
struct V_51 * V_52 ,
struct V_51 * V_166 )
{
struct V_9 * V_10 = V_3 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_170 * V_171 = V_3 -> V_171 ;
struct V_172 * V_172 = F_54 ( V_171 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
T_1 V_173 ;
struct V_174 V_175 ;
struct V_86 V_167 , V_164 ;
int V_176 = F_41 ( V_166 ) ;
int V_177 ;
if ( ! V_52 )
return;
V_175 . V_178 = V_1 -> V_165 ;
V_175 . V_179 = 0 ;
F_25 ( V_1 ,
V_180 ,
& V_175 , sizeof( V_175 ) ) ;
if ( ! F_33 ( V_1 ,
V_1 -> V_165 ) )
return;
if ( V_1 -> V_96 )
F_40 ( & V_164 ,
V_1 -> V_97 ) ;
else
F_40 ( & V_164 , V_52 ) ;
if ( ! F_36 ( V_1 , & V_164 ) )
F_55 ( L_14 ,
F_14 ( V_1 ) ) ;
if ( ! F_27 ( V_1 ) )
return;
if ( V_1 -> V_181 ) {
F_44 ( V_1 , V_182 ) ;
F_45 ( V_1 ,
V_183 ) ;
F_46 ( V_1 ) ;
} else
F_44 ( V_1 , V_184 ) ;
if ( V_1 -> V_169 &&
! F_48 ( V_1 ) )
return;
F_40 ( & V_167 , V_166 ) ;
if ( ! F_35 ( V_1 , & V_167 ) )
F_55 ( L_15 ,
F_14 ( V_1 ) ) ;
switch ( V_176 ) {
default:
case 1 : V_177 = V_185 ; break;
case 2 : V_177 = V_186 ; break;
case 4 : V_177 = V_187 ; break;
}
if ( ! F_39 ( V_1 , V_177 ) )
return;
if ( F_56 ( V_10 ) -> V_188 >= 4 ) {
V_173 = V_189 | V_190 ;
if ( V_1 -> V_191 )
V_173 |= V_1 -> V_192 ;
if ( F_56 ( V_10 ) -> V_188 < 5 )
V_173 |= V_193 ;
} else {
V_173 = F_9 ( V_1 -> V_17 ) ;
switch ( V_1 -> V_17 ) {
case V_19 :
V_173 &= V_194 ;
break;
case V_20 :
V_173 &= V_195 ;
break;
}
V_173 |= ( 9 << 19 ) | V_193 ;
}
if ( F_57 ( V_10 ) >= V_196 )
V_173 |= F_58 ( V_172 -> V_197 ) ;
else
V_173 |= F_59 ( V_172 -> V_197 ) ;
if ( V_1 -> V_198 )
V_173 |= V_199 ;
if ( F_56 ( V_10 ) -> V_188 >= 4 ) {
} else if ( F_60 ( V_10 ) || F_61 ( V_10 ) || F_62 ( V_10 ) ) {
} else {
V_173 |= ( V_176 - 1 ) << V_200 ;
}
if ( V_167 . V_89 . V_135 & V_201 &&
F_56 ( V_10 ) -> V_188 < 5 )
V_173 |= V_202 ;
F_7 ( V_1 , V_173 ) ;
}
static void F_63 ( struct V_2 * V_3 , int V_52 )
{
struct V_9 * V_10 = V_3 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_172 * V_172 = F_54 ( V_3 -> V_171 ) ;
T_1 V_203 ;
if ( V_52 != V_70 ) {
F_30 ( V_1 , 0 ) ;
if ( 0 )
F_31 ( V_1 , V_52 ) ;
if ( V_52 == V_75 ) {
V_203 = F_9 ( V_1 -> V_17 ) ;
if ( ( V_203 & V_204 ) != 0 ) {
F_7 ( V_1 , V_203 & ~ V_204 ) ;
}
}
} else {
bool V_205 , V_206 ;
int V_16 ;
T_2 V_36 ;
V_203 = F_9 ( V_1 -> V_17 ) ;
if ( ( V_203 & V_204 ) == 0 )
F_7 ( V_1 , V_203 | V_204 ) ;
for ( V_16 = 0 ; V_16 < 2 ; V_16 ++ )
F_64 ( V_10 , V_172 -> V_197 ) ;
V_36 = F_28 ( V_1 , & V_205 , & V_206 ) ;
if ( V_36 == V_49 && ! V_205 ) {
F_12 ( L_16
L_17 , F_14 ( V_1 ) ) ;
}
if ( 0 )
F_31 ( V_1 , V_52 ) ;
F_30 ( V_1 , V_1 -> V_165 ) ;
}
return;
}
static int F_65 ( struct V_5 * V_6 ,
struct V_51 * V_52 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
if ( V_52 -> V_26 & V_207 )
return V_208 ;
if ( V_1 -> V_209 > V_52 -> clock )
return V_210 ;
if ( V_1 -> V_211 < V_52 -> clock )
return V_212 ;
if ( V_1 -> V_96 ) {
if ( V_52 -> V_98 > V_1 -> V_97 -> V_98 )
return V_213 ;
if ( V_52 -> V_99 > V_1 -> V_97 -> V_99 )
return V_213 ;
}
return V_214 ;
}
static bool F_66 ( struct V_1 * V_1 , struct V_215 * V_216 )
{
F_29 ( sizeof( * V_216 ) != 8 ) ;
if ( ! F_26 ( V_1 ,
V_217 ,
V_216 , sizeof( * V_216 ) ) )
return false ;
F_12 ( L_18
L_19
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
L_30 ,
V_216 -> V_218 ,
V_216 -> V_219 ,
V_216 -> V_220 ,
V_216 -> V_221 ,
V_216 -> V_222 ,
V_216 -> V_223 ,
V_216 -> V_224 ,
V_216 -> V_225 ,
V_216 -> V_226 ,
V_216 -> V_227 ,
V_216 -> V_228 ,
V_216 -> V_229 ) ;
return true ;
}
static int F_67 ( struct V_1 * V_1 )
{
struct V_9 * V_10 = V_1 -> V_4 . V_4 . V_10 ;
T_2 V_42 [ 2 ] ;
if ( F_60 ( V_10 ) || F_61 ( V_10 ) )
return false ;
return F_26 ( V_1 , V_230 ,
& V_42 , 2 ) && V_42 [ 0 ] ;
}
static void F_68 ( struct V_231 * V_3 )
{
struct V_1 * V_1 = F_1 ( & V_3 -> V_4 ) ;
F_17 ( V_1 , V_232 , & V_1 -> V_233 , 2 ) ;
}
static bool
F_69 ( struct V_1 * V_1 )
{
return F_70 ( V_1 -> V_216 . V_229 ) > 1 ;
}
static struct V_234 *
F_71 ( struct V_5 * V_6 )
{
struct V_1 * V_235 = F_3 ( V_6 ) ;
return F_72 ( V_6 , & V_235 -> V_236 ) ;
}
static struct V_234 *
F_73 ( struct V_5 * V_6 )
{
struct V_11 * V_12 = V_6 -> V_10 -> V_13 ;
return F_72 ( V_6 ,
F_74 ( V_12 ,
V_12 -> V_237 ) ) ;
}
static enum V_238
F_75 ( struct V_5 * V_6 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
enum V_238 V_36 ;
struct V_234 * V_234 ;
V_234 = F_71 ( V_6 ) ;
if ( V_234 == NULL && F_69 ( V_1 ) ) {
T_2 V_236 , V_239 = V_1 -> V_53 ;
for ( V_236 = V_1 -> V_53 >> 1 ; V_236 > 1 ; V_236 >>= 1 ) {
V_1 -> V_53 = V_236 ;
V_234 = F_71 ( V_6 ) ;
if ( V_234 )
break;
}
if ( V_234 == NULL )
V_1 -> V_53 = V_239 ;
}
if ( V_234 == NULL )
V_234 = F_73 ( V_6 ) ;
V_36 = V_240 ;
if ( V_234 != NULL ) {
if ( V_234 -> V_241 & V_242 ) {
V_36 = V_243 ;
if ( V_1 -> V_191 ) {
V_1 -> V_181 = F_76 ( V_234 ) ;
V_1 -> V_198 = F_77 ( V_234 ) ;
}
} else
V_36 = V_244 ;
V_6 -> V_245 . V_246 = NULL ;
F_20 ( V_234 ) ;
}
if ( V_36 == V_243 ) {
struct V_7 * V_7 = F_5 ( V_6 ) ;
if ( V_7 -> V_247 != V_248 )
V_1 -> V_198 = ( V_7 -> V_247 == V_249 ) ;
}
return V_36 ;
}
static bool
F_78 ( struct V_7 * V_235 ,
struct V_234 * V_234 )
{
bool V_250 = ! ! ( V_234 -> V_241 & V_242 ) ;
bool V_251 = ! ! F_79 ( V_235 ) ;
F_12 ( L_31 ,
V_251 , V_250 ) ;
return V_251 == V_250 ;
}
static enum V_238
F_80 ( struct V_5 * V_6 , bool V_252 )
{
T_4 V_42 ;
struct V_1 * V_1 = F_3 ( V_6 ) ;
struct V_7 * V_7 = F_5 ( V_6 ) ;
enum V_238 V_30 ;
if ( ! F_17 ( V_1 ,
V_253 , NULL , 0 ) )
return V_240 ;
if ( V_1 -> V_216 . V_229 & V_254 )
F_81 ( 30 ) ;
if ( ! F_21 ( V_1 , & V_42 , 2 ) )
return V_240 ;
F_12 ( L_32 ,
V_42 & 0xff , V_42 >> 8 ,
V_7 -> V_255 ) ;
if ( V_42 == 0 )
return V_244 ;
V_1 -> V_165 = V_42 ;
V_1 -> V_181 = false ;
V_1 -> V_198 = false ;
if ( ( V_7 -> V_255 & V_42 ) == 0 )
V_30 = V_244 ;
else if ( F_82 ( V_7 ) )
V_30 = F_75 ( V_6 ) ;
else {
struct V_234 * V_234 ;
V_234 = F_71 ( V_6 ) ;
if ( V_234 == NULL )
V_234 = F_73 ( V_6 ) ;
if ( V_234 != NULL ) {
if ( F_78 ( V_7 ,
V_234 ) )
V_30 = V_243 ;
else
V_30 = V_244 ;
V_6 -> V_245 . V_246 = NULL ;
F_20 ( V_234 ) ;
} else
V_30 = V_243 ;
}
if ( V_30 == V_243 ) {
V_1 -> V_169 = false ;
V_1 -> V_96 = false ;
V_1 -> V_4 . V_256 = false ;
if ( V_42 & V_254 ) {
V_1 -> V_169 = true ;
V_1 -> V_4 . V_256 = true ;
}
if ( V_42 & V_257 )
V_1 -> V_96 = V_1 -> V_97 != NULL ;
}
return V_30 ;
}
static void F_83 ( struct V_5 * V_6 )
{
struct V_234 * V_234 ;
V_234 = F_71 ( V_6 ) ;
if ( V_234 == NULL )
V_234 = F_73 ( V_6 ) ;
if ( V_234 != NULL ) {
if ( F_78 ( F_5 ( V_6 ) ,
V_234 ) ) {
F_84 ( V_6 , V_234 ) ;
F_85 ( V_6 , V_234 ) ;
}
V_6 -> V_245 . V_246 = NULL ;
F_20 ( V_234 ) ;
}
}
static void F_86 ( struct V_5 * V_6 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
struct V_258 V_259 ;
T_7 V_260 = 0 , V_161 = 0 ;
int V_16 ;
V_161 = 1 << V_1 -> V_162 ;
memcpy ( & V_259 , & V_161 ,
V_83 ( sizeof( V_161 ) , sizeof( struct V_258 ) ) ) ;
if ( ! F_33 ( V_1 , V_1 -> V_165 ) )
return;
F_29 ( sizeof( V_259 ) != 3 ) ;
if ( ! F_17 ( V_1 ,
V_261 ,
& V_259 , sizeof( V_259 ) ) )
return;
if ( ! F_21 ( V_1 , & V_260 , 3 ) )
return;
for ( V_16 = 0 ; V_16 < F_16 ( V_262 ) ; V_16 ++ )
if ( V_260 & ( 1 << V_16 ) ) {
struct V_51 * V_263 ;
V_263 = F_87 ( V_6 -> V_10 ,
& V_262 [ V_16 ] ) ;
if ( V_263 )
F_88 ( V_6 , V_263 ) ;
}
}
static void F_89 ( struct V_5 * V_6 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
struct V_11 * V_12 = V_6 -> V_10 -> V_13 ;
struct V_51 * V_264 ;
F_90 ( V_6 , V_1 -> V_31 ) ;
if ( F_91 ( & V_6 -> V_265 ) == false )
goto V_266;
if ( V_12 -> V_267 != NULL ) {
V_264 = F_87 ( V_6 -> V_10 ,
V_12 -> V_267 ) ;
if ( V_264 != NULL ) {
V_264 -> type = ( V_268 |
V_269 ) ;
F_88 ( V_6 , V_264 ) ;
}
}
V_266:
F_92 (newmode, &connector->probed_modes, head) {
if ( V_264 -> type & V_268 ) {
V_1 -> V_97 =
F_87 ( V_6 -> V_10 , V_264 ) ;
V_1 -> V_96 = true ;
break;
}
}
}
static int F_93 ( struct V_5 * V_6 )
{
struct V_7 * V_7 = F_5 ( V_6 ) ;
if ( F_94 ( V_7 ) )
F_86 ( V_6 ) ;
else if ( F_95 ( V_7 ) )
F_89 ( V_6 ) ;
else
F_83 ( V_6 ) ;
return ! F_91 ( & V_6 -> V_265 ) ;
}
static void
F_96 ( struct V_5 * V_6 )
{
struct V_7 * V_7 = F_5 ( V_6 ) ;
struct V_9 * V_10 = V_6 -> V_10 ;
if ( V_7 -> V_270 )
F_97 ( V_10 , V_7 -> V_270 ) ;
if ( V_7 -> V_271 )
F_97 ( V_10 , V_7 -> V_271 ) ;
if ( V_7 -> V_272 )
F_97 ( V_10 , V_7 -> V_272 ) ;
if ( V_7 -> V_273 )
F_97 ( V_10 , V_7 -> V_273 ) ;
if ( V_7 -> V_274 )
F_97 ( V_10 , V_7 -> V_274 ) ;
if ( V_7 -> V_275 )
F_97 ( V_10 , V_7 -> V_275 ) ;
if ( V_7 -> V_276 )
F_97 ( V_10 , V_7 -> V_276 ) ;
if ( V_7 -> V_277 )
F_97 ( V_10 , V_7 -> V_277 ) ;
if ( V_7 -> V_278 )
F_97 ( V_10 , V_7 -> V_278 ) ;
if ( V_7 -> V_279 )
F_97 ( V_10 , V_7 -> V_279 ) ;
if ( V_7 -> V_280 )
F_97 ( V_10 , V_7 -> V_280 ) ;
if ( V_7 -> V_281 )
F_97 ( V_10 , V_7 -> V_281 ) ;
if ( V_7 -> V_282 )
F_97 ( V_10 , V_7 -> V_282 ) ;
if ( V_7 -> V_283 )
F_97 ( V_10 , V_7 -> V_283 ) ;
if ( V_7 -> V_284 )
F_97 ( V_10 , V_7 -> V_284 ) ;
if ( V_7 -> V_285 )
F_97 ( V_10 , V_7 -> V_285 ) ;
if ( V_7 -> V_286 )
F_97 ( V_10 , V_7 -> V_286 ) ;
}
static void F_98 ( struct V_5 * V_6 )
{
struct V_7 * V_7 = F_5 ( V_6 ) ;
if ( V_7 -> V_287 )
F_97 ( V_6 -> V_10 ,
V_7 -> V_287 ) ;
F_96 ( V_6 ) ;
F_99 ( V_6 ) ;
F_100 ( V_6 ) ;
F_20 ( V_6 ) ;
}
static bool F_101 ( struct V_5 * V_6 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
struct V_234 * V_234 ;
bool V_288 = false ;
if ( ! V_1 -> V_191 )
return false ;
V_234 = F_71 ( V_6 ) ;
if ( V_234 != NULL && V_234 -> V_241 & V_242 )
V_288 = F_77 ( V_234 ) ;
F_20 ( V_234 ) ;
return V_288 ;
}
static int
F_102 ( struct V_5 * V_6 ,
struct V_289 * V_290 ,
T_6 V_8 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
struct V_7 * V_7 = F_5 ( V_6 ) ;
struct V_11 * V_12 = V_6 -> V_10 -> V_13 ;
T_4 V_291 ;
T_5 V_32 ;
int V_30 ;
V_30 = F_103 ( V_6 , V_290 , V_8 ) ;
if ( V_30 )
return V_30 ;
if ( V_290 == V_12 -> V_292 ) {
int V_16 = V_8 ;
bool V_288 ;
if ( V_16 == V_7 -> V_247 )
return 0 ;
V_7 -> V_247 = V_16 ;
if ( V_16 == V_248 )
V_288 = F_101 ( V_6 ) ;
else
V_288 = ( V_16 == V_249 ) ;
if ( V_288 == V_1 -> V_198 )
return 0 ;
V_1 -> V_198 = V_288 ;
goto V_293;
}
if ( V_290 == V_12 -> V_294 ) {
if ( V_8 == ! ! V_1 -> V_192 )
return 0 ;
V_1 -> V_192 = V_8 ? V_295 : 0 ;
goto V_293;
}
#define F_104 ( V_35 , T_8 ) \
if (intel_sdvo_connector->name == property) { \
if (intel_sdvo_connector->cur_##name == temp_value) return 0; \
if (intel_sdvo_connector->max_##name < temp_value) return -EINVAL; \
cmd = SDVO_CMD_SET_##NAME; \
intel_sdvo_connector->cur_##name = temp_value; \
goto set_value; \
}
if ( V_290 == V_7 -> V_287 ) {
if ( V_8 >= V_296 )
return - V_297 ;
if ( V_1 -> V_162 ==
V_7 -> V_298 [ V_8 ] )
return 0 ;
V_1 -> V_162 = V_7 -> V_298 [ V_8 ] ;
goto V_293;
} else if ( F_105 ( V_7 ) ) {
V_291 = V_8 ;
if ( V_7 -> V_270 == V_290 ) {
F_103 ( V_6 ,
V_7 -> V_271 , V_8 ) ;
if ( V_7 -> V_299 == V_291 )
return 0 ;
V_7 -> V_299 = V_291 ;
V_7 -> V_300 = V_291 ;
V_291 = V_7 -> V_301 -
V_7 -> V_299 ;
V_32 = V_302 ;
goto V_303;
} else if ( V_7 -> V_271 == V_290 ) {
F_103 ( V_6 ,
V_7 -> V_270 , V_8 ) ;
if ( V_7 -> V_300 == V_291 )
return 0 ;
V_7 -> V_299 = V_291 ;
V_7 -> V_300 = V_291 ;
V_291 = V_7 -> V_301 -
V_7 -> V_299 ;
V_32 = V_302 ;
goto V_303;
} else if ( V_7 -> V_272 == V_290 ) {
F_103 ( V_6 ,
V_7 -> V_273 , V_8 ) ;
if ( V_7 -> V_304 == V_291 )
return 0 ;
V_7 -> V_304 = V_291 ;
V_7 -> V_305 = V_291 ;
V_291 = V_7 -> V_306 -
V_7 -> V_304 ;
V_32 = V_307 ;
goto V_303;
} else if ( V_7 -> V_273 == V_290 ) {
F_103 ( V_6 ,
V_7 -> V_272 , V_8 ) ;
if ( V_7 -> V_305 == V_291 )
return 0 ;
V_7 -> V_304 = V_291 ;
V_7 -> V_305 = V_291 ;
V_291 = V_7 -> V_306 -
V_7 -> V_304 ;
V_32 = V_307 ;
goto V_303;
}
F_104 (hpos, HPOS)
F_104 (vpos, VPOS)
F_104 (saturation, SATURATION)
F_104 (contrast, CONTRAST)
F_104 (hue, HUE)
F_104 (brightness, BRIGHTNESS)
F_104 (sharpness, SHARPNESS)
F_104 (flicker_filter, FLICKER_FILTER)
F_104 (flicker_filter_2d, FLICKER_FILTER_2D)
F_104 (flicker_filter_adaptive, FLICKER_FILTER_ADAPTIVE)
F_104 (tv_chroma_filter, TV_CHROMA_FILTER)
F_104 (tv_luma_filter, TV_LUMA_FILTER)
F_104 (dot_crawl, DOT_CRAWL)
}
return - V_297 ;
V_303:
if ( ! F_25 ( V_1 , V_32 , & V_291 , 2 ) )
return - V_308 ;
V_293:
if ( V_1 -> V_4 . V_4 . V_171 ) {
struct V_170 * V_171 = V_1 -> V_4 . V_4 . V_171 ;
F_106 ( V_171 , & V_171 -> V_52 , V_171 -> V_309 ,
V_171 -> V_310 , V_171 -> V_311 ) ;
}
return 0 ;
#undef F_104
}
static void F_107 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
if ( V_1 -> V_97 != NULL )
F_108 ( V_3 -> V_10 ,
V_1 -> V_97 ) ;
F_109 ( & V_1 -> V_236 ) ;
F_110 ( V_3 ) ;
}
static void
F_111 ( struct V_1 * V_235 )
{
T_4 V_312 = 0 ;
unsigned int V_313 ;
switch ( V_235 -> V_314 ) {
case V_315 :
V_312 |= V_315 ;
case V_316 :
V_312 |= V_316 ;
case V_317 :
V_312 |= V_317 ;
case V_318 :
V_312 |= V_318 ;
case V_319 :
V_312 |= V_319 ;
case V_320 :
V_312 |= V_320 ;
break;
}
V_312 &= V_235 -> V_216 . V_229 ;
V_313 = F_70 ( V_312 ) ;
if ( V_313 > 3 )
V_313 = 3 ;
V_235 -> V_53 = 1 << V_313 ;
}
static void
F_112 ( struct V_11 * V_12 ,
struct V_1 * V_235 , T_1 V_321 )
{
struct V_322 * V_323 ;
if ( V_235 -> V_324 )
V_323 = & ( V_12 -> V_325 [ 0 ] ) ;
else
V_323 = & ( V_12 -> V_325 [ 1 ] ) ;
if ( V_323 -> V_326 )
V_235 -> V_53 = 1 << ( ( V_323 -> V_327 & 0xf0 ) >> 4 ) ;
else
F_111 ( V_235 ) ;
}
static void
F_113 ( struct V_11 * V_12 ,
struct V_1 * V_235 , T_1 V_321 )
{
struct V_322 * V_323 ;
T_2 V_328 ;
if ( V_235 -> V_324 )
V_323 = & V_12 -> V_325 [ 0 ] ;
else
V_323 = & V_12 -> V_325 [ 1 ] ;
V_328 = V_329 ;
if ( V_323 -> V_326 )
V_328 = V_323 -> V_330 ;
if ( F_114 ( V_328 ) ) {
V_235 -> V_31 = F_74 ( V_12 , V_328 ) ;
F_115 ( V_235 -> V_31 , V_331 ) ;
F_116 ( V_235 -> V_31 , true ) ;
} else {
V_235 -> V_31 = F_74 ( V_12 , V_329 ) ;
}
}
static bool
F_117 ( struct V_1 * V_1 , int V_332 )
{
return F_43 ( V_1 ) ;
}
static T_2
F_118 ( struct V_9 * V_10 , struct V_1 * V_235 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_322 * V_333 , * V_334 ;
if ( V_235 -> V_324 ) {
V_333 = & V_12 -> V_325 [ 0 ] ;
V_334 = & V_12 -> V_325 [ 1 ] ;
} else {
V_333 = & V_12 -> V_325 [ 1 ] ;
V_334 = & V_12 -> V_325 [ 0 ] ;
}
if ( V_333 -> V_25 )
return V_333 -> V_25 ;
if ( V_334 -> V_25 ) {
if ( V_334 -> V_25 == 0x70 )
return 0x72 ;
else
return 0x70 ;
}
if ( V_235 -> V_324 )
return 0x70 ;
else
return 0x72 ;
}
static void
F_119 ( struct V_7 * V_6 ,
struct V_1 * V_3 )
{
F_120 ( V_3 -> V_4 . V_4 . V_10 ,
& V_6 -> V_4 . V_4 ,
& V_335 ,
V_6 -> V_4 . V_4 . V_336 ) ;
F_121 ( & V_6 -> V_4 . V_4 ,
& V_337 ) ;
V_6 -> V_4 . V_4 . V_338 = 1 ;
V_6 -> V_4 . V_4 . V_339 = 0 ;
V_6 -> V_4 . V_4 . V_245 . V_340 = V_341 ;
F_122 ( & V_6 -> V_4 , & V_3 -> V_4 ) ;
F_123 ( & V_6 -> V_4 . V_4 ) ;
}
static void
F_124 ( struct V_7 * V_6 )
{
struct V_9 * V_10 = V_6 -> V_4 . V_4 . V_10 ;
F_125 ( & V_6 -> V_4 . V_4 ) ;
if ( F_56 ( V_10 ) -> V_188 >= 4 && F_126 ( V_10 ) )
F_127 ( & V_6 -> V_4 . V_4 ) ;
}
static bool
F_128 ( struct V_1 * V_1 , int V_332 )
{
struct V_2 * V_3 = & V_1 -> V_4 . V_4 ;
struct V_5 * V_6 ;
struct V_231 * V_231 = F_129 ( V_3 ) ;
struct V_342 * V_342 ;
struct V_7 * V_7 ;
V_7 = F_18 ( sizeof( struct V_7 ) , V_37 ) ;
if ( ! V_7 )
return false ;
if ( V_332 == 0 ) {
V_1 -> V_314 |= V_318 ;
V_7 -> V_255 = V_318 ;
} else if ( V_332 == 1 ) {
V_1 -> V_314 |= V_317 ;
V_7 -> V_255 = V_317 ;
}
V_342 = & V_7 -> V_4 ;
V_6 = & V_342 -> V_4 ;
if ( F_67 ( V_1 ) & ( 1 << V_332 ) ) {
V_6 -> V_343 = V_344 ;
V_1 -> V_233 [ 0 ] |= 1 << V_332 ;
V_231 -> V_345 = F_68 ;
F_68 ( V_231 ) ;
}
else
V_6 -> V_343 = V_346 | V_347 ;
V_3 -> V_348 = V_349 ;
V_6 -> V_336 = V_350 ;
if ( F_117 ( V_1 , V_332 ) ) {
V_6 -> V_336 = V_351 ;
V_1 -> V_191 = true ;
}
V_1 -> V_4 . V_352 = ( ( 1 << V_353 ) |
( 1 << V_354 ) ) ;
F_119 ( V_7 , V_1 ) ;
if ( V_1 -> V_191 )
F_124 ( V_7 ) ;
return true ;
}
static bool
F_130 ( struct V_1 * V_1 , int type )
{
struct V_2 * V_3 = & V_1 -> V_4 . V_4 ;
struct V_5 * V_6 ;
struct V_342 * V_342 ;
struct V_7 * V_7 ;
V_7 = F_18 ( sizeof( struct V_7 ) , V_37 ) ;
if ( ! V_7 )
return false ;
V_342 = & V_7 -> V_4 ;
V_6 = & V_342 -> V_4 ;
V_3 -> V_348 = V_355 ;
V_6 -> V_336 = V_356 ;
V_1 -> V_314 |= type ;
V_7 -> V_255 = type ;
V_1 -> V_169 = true ;
V_1 -> V_4 . V_256 = true ;
V_1 -> V_4 . V_352 = 1 << V_357 ;
F_119 ( V_7 , V_1 ) ;
if ( ! F_131 ( V_1 , V_7 , type ) )
goto V_358;
if ( ! F_132 ( V_1 , V_7 ) )
goto V_358;
return true ;
V_358:
F_98 ( V_6 ) ;
return false ;
}
static bool
F_133 ( struct V_1 * V_1 , int V_332 )
{
struct V_2 * V_3 = & V_1 -> V_4 . V_4 ;
struct V_5 * V_6 ;
struct V_342 * V_342 ;
struct V_7 * V_7 ;
V_7 = F_18 ( sizeof( struct V_7 ) , V_37 ) ;
if ( ! V_7 )
return false ;
V_342 = & V_7 -> V_4 ;
V_6 = & V_342 -> V_4 ;
V_6 -> V_343 = V_346 ;
V_3 -> V_348 = V_359 ;
V_6 -> V_336 = V_360 ;
if ( V_332 == 0 ) {
V_1 -> V_314 |= V_320 ;
V_7 -> V_255 = V_320 ;
} else if ( V_332 == 1 ) {
V_1 -> V_314 |= V_319 ;
V_7 -> V_255 = V_319 ;
}
V_1 -> V_4 . V_352 = ( ( 1 << V_353 ) |
( 1 << V_354 ) ) ;
F_119 ( V_7 ,
V_1 ) ;
return true ;
}
static bool
F_134 ( struct V_1 * V_1 , int V_332 )
{
struct V_2 * V_3 = & V_1 -> V_4 . V_4 ;
struct V_5 * V_6 ;
struct V_342 * V_342 ;
struct V_7 * V_7 ;
V_7 = F_18 ( sizeof( struct V_7 ) , V_37 ) ;
if ( ! V_7 )
return false ;
V_342 = & V_7 -> V_4 ;
V_6 = & V_342 -> V_4 ;
V_3 -> V_348 = V_361 ;
V_6 -> V_336 = V_362 ;
if ( V_332 == 0 ) {
V_1 -> V_314 |= V_316 ;
V_7 -> V_255 = V_316 ;
} else if ( V_332 == 1 ) {
V_1 -> V_314 |= V_315 ;
V_7 -> V_255 = V_315 ;
}
V_1 -> V_4 . V_352 = ( ( 1 << V_354 ) |
( 1 << V_363 ) ) ;
F_119 ( V_7 , V_1 ) ;
if ( ! F_132 ( V_1 , V_7 ) )
goto V_358;
return true ;
V_358:
F_98 ( V_6 ) ;
return false ;
}
static bool
F_135 ( struct V_1 * V_1 , T_4 V_26 )
{
V_1 -> V_169 = false ;
V_1 -> V_4 . V_256 = false ;
V_1 -> V_96 = false ;
if ( V_26 & V_318 )
if ( ! F_128 ( V_1 , 0 ) )
return false ;
if ( ( V_26 & V_364 ) == V_364 )
if ( ! F_128 ( V_1 , 1 ) )
return false ;
if ( V_26 & V_365 )
if ( ! F_130 ( V_1 , V_365 ) )
return false ;
if ( V_26 & V_366 )
if ( ! F_130 ( V_1 , V_366 ) )
return false ;
if ( V_26 & V_367 )
if ( ! F_130 ( V_1 , V_367 ) )
return false ;
if ( V_26 & V_320 )
if ( ! F_133 ( V_1 , 0 ) )
return false ;
if ( ( V_26 & V_368 ) == V_368 )
if ( ! F_133 ( V_1 , 1 ) )
return false ;
if ( V_26 & V_316 )
if ( ! F_134 ( V_1 , 0 ) )
return false ;
if ( ( V_26 & V_257 ) == V_257 )
if ( ! F_134 ( V_1 , 1 ) )
return false ;
if ( ( V_26 & V_369 ) == 0 ) {
unsigned char V_370 [ 2 ] ;
V_1 -> V_314 = 0 ;
memcpy ( V_370 , & V_1 -> V_216 . V_229 , 2 ) ;
F_12 ( L_33 ,
F_14 ( V_1 ) ,
V_370 [ 0 ] , V_370 [ 1 ] ) ;
return false ;
}
V_1 -> V_4 . V_371 = ( 1 << 0 ) | ( 1 << 1 ) | ( 1 << 2 ) ;
return true ;
}
static bool F_131 ( struct V_1 * V_1 ,
struct V_7 * V_7 ,
int type )
{
struct V_9 * V_10 = V_1 -> V_4 . V_4 . V_10 ;
struct V_159 V_160 ;
T_7 V_161 , V_16 ;
if ( ! F_33 ( V_1 , type ) )
return false ;
F_29 ( sizeof( V_160 ) != 6 ) ;
if ( ! F_26 ( V_1 ,
V_372 ,
& V_160 , sizeof( V_160 ) ) )
return false ;
memcpy ( & V_161 , & V_160 , V_83 ( sizeof( V_161 ) , sizeof( V_160 ) ) ) ;
if ( V_161 == 0 )
return false ;
V_7 -> V_373 = 0 ;
for ( V_16 = 0 ; V_16 < V_296 ; V_16 ++ )
if ( V_161 & ( 1 << V_16 ) )
V_7 -> V_298 [ V_7 -> V_373 ++ ] = V_16 ;
V_7 -> V_287 =
F_136 ( V_10 , V_374 ,
L_34 , V_7 -> V_373 ) ;
if ( ! V_7 -> V_287 )
return false ;
for ( V_16 = 0 ; V_16 < V_7 -> V_373 ; V_16 ++ )
F_137 (
V_7 -> V_287 , V_16 ,
V_16 , V_375 [ V_7 -> V_298 [ V_16 ] ] ) ;
V_1 -> V_162 = V_7 -> V_298 [ 0 ] ;
F_138 ( & V_7 -> V_4 . V_4 ,
V_7 -> V_287 , 0 ) ;
return true ;
}
static bool
F_139 ( struct V_1 * V_1 ,
struct V_7 * V_7 ,
struct V_376 V_377 )
{
struct V_9 * V_10 = V_1 -> V_4 . V_4 . V_10 ;
struct V_5 * V_6 = & V_7 -> V_4 . V_4 ;
T_4 V_42 , V_378 [ 2 ] ;
if ( V_377 . V_379 ) {
if ( ! F_26 ( V_1 ,
V_380 ,
& V_378 , 4 ) )
return false ;
if ( ! F_26 ( V_1 ,
V_381 ,
& V_42 , 2 ) )
return false ;
V_7 -> V_301 = V_378 [ 0 ] ;
V_7 -> V_299 = V_378 [ 0 ] - V_42 ;
V_7 -> V_300 = V_7 -> V_299 ;
V_7 -> V_270 =
F_140 ( V_10 , 0 , L_35 , 0 , V_378 [ 0 ] ) ;
if ( ! V_7 -> V_270 )
return false ;
F_138 ( V_6 ,
V_7 -> V_270 ,
V_7 -> V_299 ) ;
V_7 -> V_271 =
F_140 ( V_10 , 0 , L_36 , 0 , V_378 [ 0 ] ) ;
if ( ! V_7 -> V_271 )
return false ;
F_138 ( V_6 ,
V_7 -> V_271 ,
V_7 -> V_300 ) ;
F_12 ( L_37
L_38 ,
V_378 [ 0 ] , V_378 [ 1 ] , V_42 ) ;
}
if ( V_377 . V_382 ) {
if ( ! F_26 ( V_1 ,
V_383 ,
& V_378 , 4 ) )
return false ;
if ( ! F_26 ( V_1 ,
V_384 ,
& V_42 , 2 ) )
return false ;
V_7 -> V_306 = V_378 [ 0 ] ;
V_7 -> V_304 = V_378 [ 0 ] - V_42 ;
V_7 -> V_305 = V_7 -> V_304 ;
V_7 -> V_272 =
F_140 ( V_10 , 0 ,
L_39 , 0 , V_378 [ 0 ] ) ;
if ( ! V_7 -> V_272 )
return false ;
F_138 ( V_6 ,
V_7 -> V_272 ,
V_7 -> V_304 ) ;
V_7 -> V_273 =
F_140 ( V_10 , 0 ,
L_40 , 0 , V_378 [ 0 ] ) ;
if ( ! V_7 -> V_273 )
return false ;
F_138 ( V_6 ,
V_7 -> V_273 ,
V_7 -> V_305 ) ;
F_12 ( L_41
L_38 ,
V_378 [ 0 ] , V_378 [ 1 ] , V_42 ) ;
}
F_141 ( V_274 , V_385 ) ;
F_141 ( V_275 , V_386 ) ;
F_141 ( V_276 , V_387 ) ;
F_141 ( V_277 , V_388 ) ;
F_141 ( V_278 , V_389 ) ;
F_141 ( V_279 , V_390 ) ;
F_141 ( V_286 , V_391 ) ;
F_141 ( V_280 , V_392 ) ;
F_141 ( V_282 , V_393 ) ;
F_141 ( V_281 , V_394 ) ;
F_141 ( V_284 , V_395 ) ;
F_141 ( V_283 , V_396 ) ;
if ( V_377 . V_285 ) {
if ( ! F_26 ( V_1 , V_397 , & V_42 , 2 ) )
return false ;
V_7 -> V_398 = 1 ;
V_7 -> V_399 = V_42 & 0x1 ;
V_7 -> V_285 =
F_140 ( V_10 , 0 , L_42 , 0 , 1 ) ;
if ( ! V_7 -> V_285 )
return false ;
F_138 ( V_6 ,
V_7 -> V_285 ,
V_7 -> V_399 ) ;
F_12 ( L_43 , V_42 ) ;
}
return true ;
}
static bool
F_142 ( struct V_1 * V_1 ,
struct V_7 * V_7 ,
struct V_376 V_377 )
{
struct V_9 * V_10 = V_1 -> V_4 . V_4 . V_10 ;
struct V_5 * V_6 = & V_7 -> V_4 . V_4 ;
T_4 V_42 , V_378 [ 2 ] ;
F_141 ( V_286 , V_391 ) ;
return true ;
}
static bool F_132 ( struct V_1 * V_1 ,
struct V_7 * V_7 )
{
union {
struct V_376 V_260 ;
T_4 V_42 ;
} V_377 ;
F_29 ( sizeof( V_377 ) != 2 ) ;
V_377 . V_42 = 0 ;
F_26 ( V_1 ,
V_400 ,
& V_377 , sizeof( V_377 ) ) ;
if ( V_377 . V_42 == 0 ) {
F_12 ( L_44 ) ;
return true ;
}
if ( F_94 ( V_7 ) )
return F_139 ( V_1 , V_7 , V_377 . V_260 ) ;
else if ( F_95 ( V_7 ) )
return F_142 ( V_1 , V_7 , V_377 . V_260 ) ;
else
return true ;
}
static int F_143 ( struct V_401 * V_402 ,
struct V_23 * V_24 ,
int V_403 )
{
struct V_1 * V_235 = V_402 -> V_404 ;
if ( ! F_24 ( V_235 , V_235 -> V_53 ) )
return - V_308 ;
return V_235 -> V_31 -> V_405 -> V_406 ( V_235 -> V_31 , V_24 , V_403 ) ;
}
static T_1 F_144 ( struct V_401 * V_402 )
{
struct V_1 * V_235 = V_402 -> V_404 ;
return V_235 -> V_31 -> V_405 -> V_407 ( V_235 -> V_31 ) ;
}
static bool
F_145 ( struct V_1 * V_235 ,
struct V_9 * V_10 )
{
V_235 -> V_236 . V_408 = V_409 ;
V_235 -> V_236 . V_410 = V_411 ;
snprintf ( V_235 -> V_236 . V_35 , V_412 , L_45 ) ;
V_235 -> V_236 . V_10 . V_413 = & V_10 -> V_414 -> V_10 ;
V_235 -> V_236 . V_404 = V_235 ;
V_235 -> V_236 . V_405 = & V_415 ;
return F_146 ( & V_235 -> V_236 ) == 0 ;
}
bool F_147 ( struct V_9 * V_10 , T_7 V_17 , bool V_324 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_231 * V_231 ;
struct V_1 * V_1 ;
T_1 V_416 ;
int V_16 ;
V_1 = F_18 ( sizeof( struct V_1 ) , V_37 ) ;
if ( ! V_1 )
return false ;
V_1 -> V_17 = V_17 ;
V_1 -> V_324 = V_324 ;
V_1 -> V_25 = F_118 ( V_10 , V_1 ) >> 1 ;
F_113 ( V_12 , V_1 , V_17 ) ;
if ( ! F_145 ( V_1 , V_10 ) ) {
F_20 ( V_1 ) ;
return false ;
}
V_231 = & V_1 -> V_4 ;
V_231 -> type = V_417 ;
F_148 ( V_10 , & V_231 -> V_4 , & V_418 , 0 ) ;
for ( V_16 = 0 ; V_16 < 0x40 ; V_16 ++ ) {
T_2 V_419 ;
if ( ! F_10 ( V_1 , V_16 , & V_419 ) ) {
F_12 ( L_46 ,
F_14 ( V_1 ) ) ;
goto V_358;
}
}
V_416 = 0 ;
if ( F_149 ( V_10 ) ) {
V_416 = V_1 -> V_324 ?
V_420 : V_421 ;
} else if ( F_150 ( V_10 ) ) {
V_416 = V_1 -> V_324 ?
V_422 : V_423 ;
} else {
V_416 = V_1 -> V_324 ?
V_424 : V_425 ;
}
F_151 ( & V_231 -> V_4 , & V_426 ) ;
if ( ! F_66 ( V_1 , & V_1 -> V_216 ) )
goto V_358;
if ( F_135 ( V_1 ,
V_1 -> V_216 . V_229 ) != true ) {
F_12 ( L_47 ,
F_14 ( V_1 ) ) ;
goto V_358;
}
if ( V_1 -> V_233 [ 0 ] )
V_12 -> V_427 |= V_416 ;
F_112 ( V_12 , V_1 , V_17 ) ;
if ( ! F_27 ( V_1 ) )
goto V_358;
if ( ! F_32 ( V_1 ,
& V_1 -> V_209 ,
& V_1 -> V_211 ) )
goto V_358;
F_12 ( L_48
L_49
L_50
L_51 ,
F_14 ( V_1 ) ,
V_1 -> V_216 . V_218 , V_1 -> V_216 . V_219 ,
V_1 -> V_216 . V_220 ,
V_1 -> V_209 / 1000 ,
V_1 -> V_211 / 1000 ,
( V_1 -> V_216 . V_223 & 0x1 ) ? 'Y' : 'N' ,
( V_1 -> V_216 . V_223 & 0x2 ) ? 'Y' : 'N' ,
V_1 -> V_216 . V_229 &
( V_318 | V_320 ) ? 'Y' : 'N' ,
V_1 -> V_216 . V_229 &
( V_317 | V_319 ) ? 'Y' : 'N' ) ;
return true ;
V_358:
F_152 ( & V_231 -> V_4 ) ;
F_109 ( & V_1 -> V_236 ) ;
F_20 ( V_1 ) ;
return false ;
}
