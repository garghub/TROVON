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
T_2 V_28 [ V_33 * 2 + 2 ] , V_36 ;
struct V_23 V_24 [ V_33 + 3 ] ;
int V_16 , V_30 ;
F_13 ( V_1 , V_32 , args , V_33 ) ;
for ( V_16 = 0 ; V_16 < V_33 ; V_16 ++ ) {
V_24 [ V_16 ] . V_21 = V_1 -> V_25 ;
V_24 [ V_16 ] . V_26 = 0 ;
V_24 [ V_16 ] . V_27 = 2 ;
V_24 [ V_16 ] . V_28 = V_28 + 2 * V_16 ;
V_28 [ 2 * V_16 + 0 ] = V_37 - V_16 ;
V_28 [ 2 * V_16 + 1 ] = ( ( T_2 * ) args ) [ V_16 ] ;
}
V_24 [ V_16 ] . V_21 = V_1 -> V_25 ;
V_24 [ V_16 ] . V_26 = 0 ;
V_24 [ V_16 ] . V_27 = 2 ;
V_24 [ V_16 ] . V_28 = V_28 + 2 * V_16 ;
V_28 [ 2 * V_16 + 0 ] = V_38 ;
V_28 [ 2 * V_16 + 1 ] = V_32 ;
V_36 = V_39 ;
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
return false ;
}
if ( V_30 != V_16 + 3 ) {
F_12 ( L_9 , V_30 , V_16 + 3 ) ;
return false ;
}
return true ;
}
static bool F_18 ( struct V_1 * V_1 ,
void * V_40 , int V_41 )
{
T_2 V_42 = 5 ;
T_2 V_36 ;
int V_16 ;
F_12 ( L_10 , F_14 ( V_1 ) ) ;
if ( ! F_10 ( V_1 ,
V_39 ,
& V_36 ) )
goto V_43;
while ( V_36 == V_44 && V_42 -- ) {
F_19 ( 15 ) ;
if ( ! F_10 ( V_1 ,
V_39 ,
& V_36 ) )
goto V_43;
}
if ( V_36 <= V_45 )
F_15 ( L_5 , V_46 [ V_36 ] ) ;
else
F_15 ( L_11 , V_36 ) ;
if ( V_36 != V_47 )
goto V_43;
for ( V_16 = 0 ; V_16 < V_41 ; V_16 ++ ) {
if ( ! F_10 ( V_1 ,
V_48 + V_16 ,
& ( ( T_2 * ) V_40 ) [ V_16 ] ) )
goto V_43;
F_15 ( L_12 , ( ( T_2 * ) V_40 ) [ V_16 ] ) ;
}
F_15 ( L_7 ) ;
return true ;
V_43:
F_15 ( L_13 ) ;
return false ;
}
static int F_20 ( struct V_49 * V_50 )
{
if ( V_50 -> clock >= 100000 )
return 1 ;
else if ( V_50 -> clock >= 50000 )
return 2 ;
else
return 4 ;
}
static bool F_21 ( struct V_1 * V_1 ,
T_2 V_51 )
{
return F_17 ( V_1 ,
V_52 ,
& V_51 , 1 ) ;
}
static bool F_22 ( struct V_1 * V_1 , T_2 V_32 , const void * V_53 , int V_27 )
{
if ( ! F_17 ( V_1 , V_32 , V_53 , V_27 ) )
return false ;
return F_18 ( V_1 , NULL , 0 ) ;
}
static bool
F_23 ( struct V_1 * V_1 , T_2 V_32 , void * V_54 , int V_27 )
{
if ( ! F_17 ( V_1 , V_32 , NULL , 0 ) )
return false ;
return F_18 ( V_1 , V_54 , V_27 ) ;
}
static bool F_24 ( struct V_1 * V_1 )
{
struct V_55 V_56 = { 0 } ;
return F_22 ( V_1 ,
V_57 ,
& V_56 , sizeof( V_56 ) ) ;
}
static bool F_25 ( struct V_1 * V_1 , bool * V_58 , bool * V_59 )
{
struct V_60 V_40 ;
F_26 ( sizeof( V_40 ) != 1 ) ;
if ( ! F_23 ( V_1 , V_61 ,
& V_40 , sizeof( V_40 ) ) )
return false ;
* V_58 = V_40 . V_62 ;
* V_59 = V_40 . V_63 ;
return true ;
}
static bool F_27 ( struct V_1 * V_1 ,
T_3 V_64 )
{
return F_22 ( V_1 ,
V_65 ,
& V_64 , sizeof( V_64 ) ) ;
}
static bool F_28 ( struct V_1 * V_1 ,
int V_50 )
{
T_2 V_66 = V_67 ;
switch ( V_50 ) {
case V_68 :
V_66 = V_67 ;
break;
case V_69 :
V_66 = V_70 ;
break;
case V_71 :
V_66 = V_72 ;
break;
case V_73 :
V_66 = V_74 ;
break;
}
return F_22 ( V_1 ,
V_75 , & V_66 , sizeof( V_66 ) ) ;
}
static bool F_29 ( struct V_1 * V_1 ,
int * V_76 ,
int * V_77 )
{
struct V_78 V_79 ;
F_26 ( sizeof( V_79 ) != 4 ) ;
if ( ! F_23 ( V_1 ,
V_80 ,
& V_79 , sizeof( V_79 ) ) )
return false ;
* V_76 = V_79 . V_81 * 10 ;
* V_77 = V_79 . V_82 * 10 ;
return true ;
}
static bool F_30 ( struct V_1 * V_1 ,
T_3 V_64 )
{
return F_22 ( V_1 ,
V_83 ,
& V_64 , sizeof( V_64 ) ) ;
}
static bool F_31 ( struct V_1 * V_1 , T_2 V_32 ,
struct V_84 * V_85 )
{
return F_22 ( V_1 , V_32 , & V_85 -> V_86 , sizeof( V_85 -> V_86 ) ) &&
F_22 ( V_1 , V_32 + 1 , & V_85 -> V_87 , sizeof( V_85 -> V_87 ) ) ;
}
static bool F_32 ( struct V_1 * V_1 ,
struct V_84 * V_85 )
{
return F_31 ( V_1 ,
V_88 , V_85 ) ;
}
static bool F_33 ( struct V_1 * V_1 ,
struct V_84 * V_85 )
{
return F_31 ( V_1 ,
V_89 , V_85 ) ;
}
static bool
F_34 ( struct V_1 * V_1 ,
T_4 clock ,
T_4 V_90 ,
T_4 V_91 )
{
struct V_92 args ;
memset ( & args , 0 , sizeof( args ) ) ;
args . clock = clock ;
args . V_90 = V_90 ;
args . V_91 = V_91 ;
args . V_93 = 0 ;
if ( V_1 -> V_94 &&
( V_1 -> V_95 -> V_96 != V_90 ||
V_1 -> V_95 -> V_97 != V_91 ) )
args . V_98 = 1 ;
return F_22 ( V_1 ,
V_99 ,
& args , sizeof( args ) ) ;
}
static bool F_35 ( struct V_1 * V_1 ,
struct V_84 * V_85 )
{
F_26 ( sizeof( V_85 -> V_86 ) != 8 ) ;
F_26 ( sizeof( V_85 -> V_87 ) != 8 ) ;
return F_23 ( V_1 , V_100 ,
& V_85 -> V_86 , sizeof( V_85 -> V_86 ) ) &&
F_23 ( V_1 , V_101 ,
& V_85 -> V_87 , sizeof( V_85 -> V_87 ) ) ;
}
static bool F_36 ( struct V_1 * V_1 , T_2 V_8 )
{
return F_22 ( V_1 , V_102 , & V_8 , 1 ) ;
}
static void F_37 ( struct V_84 * V_85 ,
const struct V_49 * V_50 )
{
T_4 V_90 , V_91 ;
T_4 V_103 , V_104 , V_105 , V_106 ;
T_4 V_107 , V_108 ;
int V_109 ;
V_90 = V_50 -> V_110 ;
V_91 = V_50 -> V_111 ;
V_103 = V_50 -> V_112 - V_50 -> V_113 ;
V_104 = V_50 -> V_114 - V_50 -> V_115 ;
V_105 = V_50 -> V_116 - V_50 -> V_117 ;
V_106 = V_50 -> V_118 - V_50 -> V_119 ;
V_107 = V_50 -> V_115 - V_50 -> V_113 ;
V_108 = V_50 -> V_119 - V_50 -> V_117 ;
V_109 = V_50 -> clock ;
V_109 /= F_38 ( V_50 ) ? : 1 ;
V_109 /= 10 ;
V_85 -> V_86 . clock = V_109 ;
V_85 -> V_86 . V_120 = V_90 & 0xff ;
V_85 -> V_86 . V_121 = V_103 & 0xff ;
V_85 -> V_86 . V_122 = ( ( ( V_90 >> 8 ) & 0xf ) << 4 ) |
( ( V_103 >> 8 ) & 0xf ) ;
V_85 -> V_86 . V_123 = V_91 & 0xff ;
V_85 -> V_86 . V_124 = V_105 & 0xff ;
V_85 -> V_86 . V_125 = ( ( ( V_91 >> 8 ) & 0xf ) << 4 ) |
( ( V_105 >> 8 ) & 0xf ) ;
V_85 -> V_87 . V_126 = V_107 & 0xff ;
V_85 -> V_87 . V_127 = V_104 & 0xff ;
V_85 -> V_87 . V_128 = ( V_108 & 0xf ) << 4 |
( V_106 & 0xf ) ;
V_85 -> V_87 . V_129 = ( ( V_107 & 0x300 ) >> 2 ) |
( ( V_104 & 0x300 ) >> 4 ) | ( ( V_108 & 0x30 ) >> 2 ) |
( ( V_106 & 0x30 ) >> 4 ) ;
V_85 -> V_87 . V_130 = 0x18 ;
if ( V_50 -> V_26 & V_131 )
V_85 -> V_87 . V_130 |= 0x2 ;
if ( V_50 -> V_26 & V_132 )
V_85 -> V_87 . V_130 |= 0x4 ;
V_85 -> V_87 . V_133 = 0 ;
V_85 -> V_87 . V_134 = V_108 & 0xc0 ;
V_85 -> V_87 . V_135 = 0 ;
}
static void F_39 ( struct V_49 * V_50 ,
const struct V_84 * V_85 )
{
V_50 -> V_96 = V_85 -> V_86 . V_120 ;
V_50 -> V_96 += ( ( V_85 -> V_86 . V_122 >> 4 ) & 0x0f ) << 8 ;
V_50 -> V_136 = V_50 -> V_96 + V_85 -> V_87 . V_126 ;
V_50 -> V_136 += ( V_85 -> V_87 . V_129 & 0xc0 ) << 2 ;
V_50 -> V_137 = V_50 -> V_136 + V_85 -> V_87 . V_127 ;
V_50 -> V_137 += ( V_85 -> V_87 . V_129 & 0x30 ) << 4 ;
V_50 -> V_138 = V_50 -> V_96 + V_85 -> V_86 . V_121 ;
V_50 -> V_138 += ( V_85 -> V_86 . V_122 & 0xf ) << 8 ;
V_50 -> V_97 = V_85 -> V_86 . V_123 ;
V_50 -> V_97 += ( ( V_85 -> V_86 . V_125 >> 4 ) & 0x0f ) << 8 ;
V_50 -> V_139 = V_50 -> V_97 ;
V_50 -> V_139 += ( V_85 -> V_87 . V_128 >> 4 ) & 0xf ;
V_50 -> V_139 += ( V_85 -> V_87 . V_129 & 0x0c ) << 2 ;
V_50 -> V_139 += V_85 -> V_87 . V_134 & 0xc0 ;
V_50 -> V_140 = V_50 -> V_139 +
( V_85 -> V_87 . V_128 & 0xf ) ;
V_50 -> V_140 += ( V_85 -> V_87 . V_129 & 0x3 ) << 4 ;
V_50 -> V_141 = V_50 -> V_97 + V_85 -> V_86 . V_124 ;
V_50 -> V_141 += ( V_85 -> V_86 . V_125 & 0xf ) << 8 ;
V_50 -> clock = V_85 -> V_86 . clock * 10 ;
V_50 -> V_26 &= ~ ( V_131 | V_132 ) ;
if ( V_85 -> V_87 . V_130 & 0x2 )
V_50 -> V_26 |= V_131 ;
if ( V_85 -> V_87 . V_130 & 0x4 )
V_50 -> V_26 |= V_132 ;
}
static bool F_40 ( struct V_1 * V_1 )
{
struct V_142 V_143 ;
F_26 ( sizeof( V_143 ) != 2 ) ;
return F_23 ( V_1 ,
V_144 ,
& V_143 , sizeof( V_143 ) ) ;
}
static bool F_41 ( struct V_1 * V_1 ,
T_5 V_50 )
{
return F_22 ( V_1 , V_145 , & V_50 , 1 ) ;
}
static bool F_42 ( struct V_1 * V_1 ,
T_5 V_50 )
{
return F_22 ( V_1 , V_146 , & V_50 , 1 ) ;
}
static bool F_43 ( struct V_1 * V_1 )
{
struct V_147 V_148 = {
. type = V_149 ,
. V_150 = V_151 ,
. V_27 = V_152 ,
} ;
T_5 V_153 = V_154 ;
T_5 V_155 [ 2 ] = { 1 , 0 } ;
T_6 * V_53 = ( T_6 * ) & V_148 ;
unsigned V_16 ;
F_44 ( & V_148 ) ;
if ( ! F_22 ( V_1 ,
V_156 ,
V_155 , 2 ) )
return false ;
for ( V_16 = 0 ; V_16 < sizeof( V_148 ) ; V_16 += 8 ) {
if ( ! F_22 ( V_1 ,
V_157 ,
V_53 , 8 ) )
return false ;
V_53 ++ ;
}
return F_22 ( V_1 ,
V_158 ,
& V_153 , 1 ) ;
}
static bool F_45 ( struct V_1 * V_1 )
{
struct V_159 V_160 ;
T_7 V_161 ;
V_161 = 1 << V_1 -> V_162 ;
memset ( & V_160 , 0 , sizeof( V_160 ) ) ;
memcpy ( & V_160 , & V_161 , V_81 ( sizeof( V_160 ) , sizeof( V_161 ) ) ) ;
F_26 ( sizeof( V_160 ) != 6 ) ;
return F_22 ( V_1 ,
V_163 ,
& V_160 , sizeof( V_160 ) ) ;
}
static bool
F_46 ( struct V_1 * V_1 ,
struct V_49 * V_50 )
{
struct V_84 V_164 ;
if ( ! F_30 ( V_1 ,
V_1 -> V_165 ) )
return false ;
F_37 ( & V_164 , V_50 ) ;
if ( ! F_33 ( V_1 , & V_164 ) )
return false ;
return true ;
}
static bool
F_47 ( struct V_1 * V_1 ,
struct V_49 * V_50 ,
struct V_49 * V_166 )
{
if ( ! F_24 ( V_1 ) )
return false ;
if ( ! F_34 ( V_1 ,
V_50 -> clock / 10 ,
V_50 -> V_96 ,
V_50 -> V_97 ) )
return false ;
if ( ! F_35 ( V_1 ,
& V_1 -> V_167 ) )
return false ;
F_39 ( V_166 , & V_1 -> V_167 ) ;
return true ;
}
static bool F_48 ( struct V_2 * V_3 ,
struct V_49 * V_50 ,
struct V_49 * V_166 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
int V_168 ;
if ( V_1 -> V_169 ) {
if ( ! F_46 ( V_1 , V_50 ) )
return false ;
( void ) F_47 ( V_1 ,
V_50 ,
V_166 ) ;
} else if ( V_1 -> V_94 ) {
if ( ! F_46 ( V_1 ,
V_1 -> V_95 ) )
return false ;
( void ) F_47 ( V_1 ,
V_50 ,
V_166 ) ;
}
V_168 = F_20 ( V_166 ) ;
F_49 ( V_166 , V_168 ) ;
return true ;
}
static void F_50 ( struct V_2 * V_3 ,
struct V_49 * V_50 ,
struct V_49 * V_166 )
{
struct V_9 * V_10 = V_3 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_170 * V_171 = V_3 -> V_171 ;
struct V_172 * V_172 = F_51 ( V_171 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
T_1 V_173 ;
struct V_174 V_175 ;
struct V_84 V_167 , V_164 ;
int V_176 = F_38 ( V_166 ) ;
int V_177 ;
if ( ! V_50 )
return;
V_175 . V_178 = V_1 -> V_165 ;
V_175 . V_179 = 0 ;
F_22 ( V_1 ,
V_180 ,
& V_175 , sizeof( V_175 ) ) ;
if ( ! F_30 ( V_1 ,
V_1 -> V_165 ) )
return;
if ( V_1 -> V_94 )
F_37 ( & V_164 ,
V_1 -> V_95 ) ;
else
F_37 ( & V_164 , V_50 ) ;
( void ) F_33 ( V_1 , & V_164 ) ;
if ( ! F_24 ( V_1 ) )
return;
if ( V_1 -> V_181 ) {
F_41 ( V_1 , V_182 ) ;
F_42 ( V_1 ,
V_183 ) ;
F_43 ( V_1 ) ;
} else
F_41 ( V_1 , V_184 ) ;
if ( V_1 -> V_169 &&
! F_45 ( V_1 ) )
return;
F_37 ( & V_167 , V_166 ) ;
( void ) F_32 ( V_1 , & V_167 ) ;
switch ( V_176 ) {
default:
case 1 : V_177 = V_185 ; break;
case 2 : V_177 = V_186 ; break;
case 4 : V_177 = V_187 ; break;
}
if ( ! F_36 ( V_1 , V_177 ) )
return;
if ( F_52 ( V_10 ) -> V_188 >= 4 ) {
V_173 = V_189 | V_190 ;
if ( V_1 -> V_191 )
V_173 |= V_1 -> V_192 ;
if ( F_52 ( V_10 ) -> V_188 < 5 )
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
if ( F_53 ( V_10 ) >= V_196 )
V_173 |= F_54 ( V_172 -> V_197 ) ;
else
V_173 |= F_55 ( V_172 -> V_197 ) ;
if ( V_1 -> V_198 )
V_173 |= V_199 ;
if ( F_52 ( V_10 ) -> V_188 >= 4 ) {
} else if ( F_56 ( V_10 ) || F_57 ( V_10 ) || F_58 ( V_10 ) ) {
} else {
V_173 |= ( V_176 - 1 ) << V_200 ;
}
if ( V_167 . V_87 . V_133 & V_201 &&
F_52 ( V_10 ) -> V_188 < 5 )
V_173 |= V_202 ;
F_7 ( V_1 , V_173 ) ;
}
static void F_59 ( struct V_2 * V_3 , int V_50 )
{
struct V_9 * V_10 = V_3 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_172 * V_172 = F_51 ( V_3 -> V_171 ) ;
T_1 V_203 ;
if ( V_50 != V_68 ) {
F_27 ( V_1 , 0 ) ;
if ( 0 )
F_28 ( V_1 , V_50 ) ;
if ( V_50 == V_73 ) {
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
F_60 ( V_10 , V_172 -> V_197 ) ;
V_36 = F_25 ( V_1 , & V_205 , & V_206 ) ;
if ( V_36 == V_47 && ! V_205 ) {
F_12 ( L_14
L_15 , F_14 ( V_1 ) ) ;
}
if ( 0 )
F_28 ( V_1 , V_50 ) ;
F_27 ( V_1 , V_1 -> V_165 ) ;
}
return;
}
static int F_61 ( struct V_5 * V_6 ,
struct V_49 * V_50 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
if ( V_50 -> V_26 & V_207 )
return V_208 ;
if ( V_1 -> V_209 > V_50 -> clock )
return V_210 ;
if ( V_1 -> V_211 < V_50 -> clock )
return V_212 ;
if ( V_1 -> V_94 ) {
if ( V_50 -> V_96 > V_1 -> V_95 -> V_96 )
return V_213 ;
if ( V_50 -> V_97 > V_1 -> V_95 -> V_97 )
return V_213 ;
}
return V_214 ;
}
static bool F_62 ( struct V_1 * V_1 , struct V_215 * V_216 )
{
F_26 ( sizeof( * V_216 ) != 8 ) ;
if ( ! F_23 ( V_1 ,
V_217 ,
V_216 , sizeof( * V_216 ) ) )
return false ;
F_12 ( L_16
L_17
L_18
L_19
L_20
L_21
L_22
L_23
L_24
L_25
L_26
L_27
L_28 ,
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
static int F_63 ( struct V_1 * V_1 )
{
struct V_9 * V_10 = V_1 -> V_4 . V_4 . V_10 ;
T_2 V_40 [ 2 ] ;
if ( F_56 ( V_10 ) || F_57 ( V_10 ) )
return false ;
return F_23 ( V_1 , V_230 ,
& V_40 , 2 ) && V_40 [ 0 ] ;
}
static void F_64 ( struct V_231 * V_3 )
{
struct V_1 * V_1 = F_1 ( & V_3 -> V_4 ) ;
F_17 ( V_1 , V_232 , & V_1 -> V_233 , 2 ) ;
}
static bool
F_65 ( struct V_1 * V_1 )
{
return F_66 ( V_1 -> V_216 . V_229 ) > 1 ;
}
static struct V_234 *
F_67 ( struct V_5 * V_6 )
{
struct V_1 * V_235 = F_3 ( V_6 ) ;
return F_68 ( V_6 , & V_235 -> V_236 ) ;
}
static struct V_234 *
F_69 ( struct V_5 * V_6 )
{
struct V_11 * V_12 = V_6 -> V_10 -> V_13 ;
return F_68 ( V_6 ,
& V_12 -> V_237 [ V_12 -> V_238 ] . V_239 ) ;
}
enum V_240
F_70 ( struct V_5 * V_6 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
enum V_240 V_36 ;
struct V_234 * V_234 ;
V_234 = F_67 ( V_6 ) ;
if ( V_234 == NULL && F_65 ( V_1 ) ) {
T_2 V_236 , V_241 = V_1 -> V_51 ;
for ( V_236 = V_1 -> V_51 >> 1 ; V_236 > 1 ; V_236 >>= 1 ) {
V_1 -> V_51 = V_236 ;
V_234 = F_67 ( V_6 ) ;
if ( V_234 )
break;
}
if ( V_234 == NULL )
V_1 -> V_51 = V_241 ;
}
if ( V_234 == NULL )
V_234 = F_69 ( V_6 ) ;
V_36 = V_242 ;
if ( V_234 != NULL ) {
if ( V_234 -> V_243 & V_244 ) {
V_36 = V_245 ;
if ( V_1 -> V_191 ) {
V_1 -> V_181 = F_71 ( V_234 ) ;
V_1 -> V_198 = F_72 ( V_234 ) ;
}
} else
V_36 = V_246 ;
V_6 -> V_247 . V_248 = NULL ;
F_73 ( V_234 ) ;
}
if ( V_36 == V_245 ) {
struct V_7 * V_7 = F_5 ( V_6 ) ;
if ( V_7 -> V_249 != V_250 )
V_1 -> V_198 = ( V_7 -> V_249 == V_251 ) ;
}
return V_36 ;
}
static bool
F_74 ( struct V_7 * V_235 ,
struct V_234 * V_234 )
{
bool V_252 = ! ! ( V_234 -> V_243 & V_244 ) ;
bool V_253 = ! ! F_75 ( V_235 ) ;
F_12 ( L_29 ,
V_253 , V_252 ) ;
return V_253 == V_252 ;
}
static enum V_240
F_76 ( struct V_5 * V_6 , bool V_254 )
{
T_4 V_40 ;
struct V_1 * V_1 = F_3 ( V_6 ) ;
struct V_7 * V_7 = F_5 ( V_6 ) ;
enum V_240 V_30 ;
if ( ! F_17 ( V_1 ,
V_255 , NULL , 0 ) )
return V_242 ;
if ( V_1 -> V_216 . V_229 &
( V_256 | V_257 ) )
F_77 ( 30 ) ;
if ( ! F_18 ( V_1 , & V_40 , 2 ) )
return V_242 ;
F_12 ( L_30 ,
V_40 & 0xff , V_40 >> 8 ,
V_7 -> V_258 ) ;
if ( V_40 == 0 )
return V_246 ;
V_1 -> V_165 = V_40 ;
V_1 -> V_181 = false ;
V_1 -> V_198 = false ;
if ( ( V_7 -> V_258 & V_40 ) == 0 )
V_30 = V_246 ;
else if ( F_78 ( V_7 ) )
V_30 = F_70 ( V_6 ) ;
else {
struct V_234 * V_234 ;
V_234 = F_67 ( V_6 ) ;
if ( V_234 == NULL )
V_234 = F_69 ( V_6 ) ;
if ( V_234 != NULL ) {
if ( F_74 ( V_7 ,
V_234 ) )
V_30 = V_245 ;
else
V_30 = V_246 ;
V_6 -> V_247 . V_248 = NULL ;
F_73 ( V_234 ) ;
} else
V_30 = V_245 ;
}
if ( V_30 == V_245 ) {
V_1 -> V_169 = false ;
V_1 -> V_94 = false ;
V_1 -> V_4 . V_259 = false ;
if ( V_40 & V_260 ) {
V_1 -> V_169 = true ;
V_1 -> V_4 . V_259 = true ;
}
if ( V_40 & V_261 )
V_1 -> V_94 = V_1 -> V_95 != NULL ;
}
return V_30 ;
}
static void F_79 ( struct V_5 * V_6 )
{
struct V_234 * V_234 ;
V_234 = F_67 ( V_6 ) ;
if ( V_234 == NULL )
V_234 = F_69 ( V_6 ) ;
if ( V_234 != NULL ) {
if ( F_74 ( F_5 ( V_6 ) ,
V_234 ) ) {
F_80 ( V_6 , V_234 ) ;
F_81 ( V_6 , V_234 ) ;
}
V_6 -> V_247 . V_248 = NULL ;
F_73 ( V_234 ) ;
}
}
static void F_82 ( struct V_5 * V_6 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
struct V_262 V_263 ;
T_7 V_264 = 0 , V_161 = 0 ;
int V_16 ;
V_161 = 1 << V_1 -> V_162 ;
memcpy ( & V_263 , & V_161 ,
V_81 ( sizeof( V_161 ) , sizeof( struct V_262 ) ) ) ;
if ( ! F_30 ( V_1 , V_1 -> V_165 ) )
return;
F_26 ( sizeof( V_263 ) != 3 ) ;
if ( ! F_17 ( V_1 ,
V_265 ,
& V_263 , sizeof( V_263 ) ) )
return;
if ( ! F_18 ( V_1 , & V_264 , 3 ) )
return;
for ( V_16 = 0 ; V_16 < F_16 ( V_266 ) ; V_16 ++ )
if ( V_264 & ( 1 << V_16 ) ) {
struct V_49 * V_267 ;
V_267 = F_83 ( V_6 -> V_10 ,
& V_266 [ V_16 ] ) ;
if ( V_267 )
F_84 ( V_6 , V_267 ) ;
}
}
static void F_85 ( struct V_5 * V_6 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
struct V_11 * V_12 = V_6 -> V_10 -> V_13 ;
struct V_49 * V_268 ;
F_86 ( V_6 , V_1 -> V_31 ) ;
if ( F_87 ( & V_6 -> V_269 ) == false )
goto V_270;
if ( V_12 -> V_271 != NULL ) {
V_268 = F_83 ( V_6 -> V_10 ,
V_12 -> V_271 ) ;
if ( V_268 != NULL ) {
V_268 -> type = ( V_272 |
V_273 ) ;
F_84 ( V_6 , V_268 ) ;
}
}
V_270:
F_88 (newmode, &connector->probed_modes, head) {
if ( V_268 -> type & V_272 ) {
V_1 -> V_95 =
F_83 ( V_6 -> V_10 , V_268 ) ;
F_89 ( V_1 -> V_95 ,
0 ) ;
V_1 -> V_94 = true ;
break;
}
}
}
static int F_90 ( struct V_5 * V_6 )
{
struct V_7 * V_7 = F_5 ( V_6 ) ;
if ( F_91 ( V_7 ) )
F_82 ( V_6 ) ;
else if ( F_92 ( V_7 ) )
F_85 ( V_6 ) ;
else
F_79 ( V_6 ) ;
return ! F_87 ( & V_6 -> V_269 ) ;
}
static void
F_93 ( struct V_5 * V_6 )
{
struct V_7 * V_7 = F_5 ( V_6 ) ;
struct V_9 * V_10 = V_6 -> V_10 ;
if ( V_7 -> V_274 )
F_94 ( V_10 , V_7 -> V_274 ) ;
if ( V_7 -> V_275 )
F_94 ( V_10 , V_7 -> V_275 ) ;
if ( V_7 -> V_276 )
F_94 ( V_10 , V_7 -> V_276 ) ;
if ( V_7 -> V_277 )
F_94 ( V_10 , V_7 -> V_277 ) ;
if ( V_7 -> V_278 )
F_94 ( V_10 , V_7 -> V_278 ) ;
if ( V_7 -> V_279 )
F_94 ( V_10 , V_7 -> V_279 ) ;
if ( V_7 -> V_280 )
F_94 ( V_10 , V_7 -> V_280 ) ;
if ( V_7 -> V_281 )
F_94 ( V_10 , V_7 -> V_281 ) ;
if ( V_7 -> V_282 )
F_94 ( V_10 , V_7 -> V_282 ) ;
if ( V_7 -> V_283 )
F_94 ( V_10 , V_7 -> V_283 ) ;
if ( V_7 -> V_284 )
F_94 ( V_10 , V_7 -> V_284 ) ;
if ( V_7 -> V_285 )
F_94 ( V_10 , V_7 -> V_285 ) ;
if ( V_7 -> V_286 )
F_94 ( V_10 , V_7 -> V_286 ) ;
if ( V_7 -> V_287 )
F_94 ( V_10 , V_7 -> V_287 ) ;
if ( V_7 -> V_288 )
F_94 ( V_10 , V_7 -> V_288 ) ;
if ( V_7 -> V_289 )
F_94 ( V_10 , V_7 -> V_289 ) ;
if ( V_7 -> V_290 )
F_94 ( V_10 , V_7 -> V_290 ) ;
}
static void F_95 ( struct V_5 * V_6 )
{
struct V_7 * V_7 = F_5 ( V_6 ) ;
if ( V_7 -> V_291 )
F_94 ( V_6 -> V_10 ,
V_7 -> V_291 ) ;
F_93 ( V_6 ) ;
F_96 ( V_6 ) ;
F_97 ( V_6 ) ;
F_73 ( V_6 ) ;
}
static bool F_98 ( struct V_5 * V_6 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
struct V_234 * V_234 ;
bool V_292 = false ;
if ( ! V_1 -> V_191 )
return false ;
V_234 = F_67 ( V_6 ) ;
if ( V_234 != NULL && V_234 -> V_243 & V_244 )
V_292 = F_72 ( V_234 ) ;
return V_292 ;
}
static int
F_99 ( struct V_5 * V_6 ,
struct V_293 * V_294 ,
T_6 V_8 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
struct V_7 * V_7 = F_5 ( V_6 ) ;
struct V_11 * V_12 = V_6 -> V_10 -> V_13 ;
T_4 V_295 ;
T_5 V_32 ;
int V_30 ;
V_30 = F_100 ( V_6 , V_294 , V_8 ) ;
if ( V_30 )
return V_30 ;
if ( V_294 == V_12 -> V_296 ) {
int V_16 = V_8 ;
bool V_292 ;
if ( V_16 == V_7 -> V_249 )
return 0 ;
V_7 -> V_249 = V_16 ;
if ( V_16 == V_250 )
V_292 = F_98 ( V_6 ) ;
else
V_292 = ( V_16 == V_251 ) ;
if ( V_292 == V_1 -> V_198 )
return 0 ;
V_1 -> V_198 = V_292 ;
goto V_297;
}
if ( V_294 == V_12 -> V_298 ) {
if ( V_8 == ! ! V_1 -> V_192 )
return 0 ;
V_1 -> V_192 = V_8 ? V_299 : 0 ;
goto V_297;
}
#define F_101 ( V_35 , T_8 ) \
if (intel_sdvo_connector->name == property) { \
if (intel_sdvo_connector->cur_##name == temp_value) return 0; \
if (intel_sdvo_connector->max_##name < temp_value) return -EINVAL; \
cmd = SDVO_CMD_SET_##NAME; \
intel_sdvo_connector->cur_##name = temp_value; \
goto set_value; \
}
if ( V_294 == V_7 -> V_291 ) {
if ( V_8 >= V_300 )
return - V_301 ;
if ( V_1 -> V_162 ==
V_7 -> V_302 [ V_8 ] )
return 0 ;
V_1 -> V_162 = V_7 -> V_302 [ V_8 ] ;
goto V_297;
} else if ( F_102 ( V_7 ) ) {
V_295 = V_8 ;
if ( V_7 -> V_274 == V_294 ) {
F_100 ( V_6 ,
V_7 -> V_275 , V_8 ) ;
if ( V_7 -> V_303 == V_295 )
return 0 ;
V_7 -> V_303 = V_295 ;
V_7 -> V_304 = V_295 ;
V_295 = V_7 -> V_305 -
V_7 -> V_303 ;
V_32 = V_306 ;
goto V_307;
} else if ( V_7 -> V_275 == V_294 ) {
F_100 ( V_6 ,
V_7 -> V_274 , V_8 ) ;
if ( V_7 -> V_304 == V_295 )
return 0 ;
V_7 -> V_303 = V_295 ;
V_7 -> V_304 = V_295 ;
V_295 = V_7 -> V_305 -
V_7 -> V_303 ;
V_32 = V_306 ;
goto V_307;
} else if ( V_7 -> V_276 == V_294 ) {
F_100 ( V_6 ,
V_7 -> V_277 , V_8 ) ;
if ( V_7 -> V_308 == V_295 )
return 0 ;
V_7 -> V_308 = V_295 ;
V_7 -> V_309 = V_295 ;
V_295 = V_7 -> V_310 -
V_7 -> V_308 ;
V_32 = V_311 ;
goto V_307;
} else if ( V_7 -> V_277 == V_294 ) {
F_100 ( V_6 ,
V_7 -> V_276 , V_8 ) ;
if ( V_7 -> V_309 == V_295 )
return 0 ;
V_7 -> V_308 = V_295 ;
V_7 -> V_309 = V_295 ;
V_295 = V_7 -> V_310 -
V_7 -> V_308 ;
V_32 = V_311 ;
goto V_307;
}
F_101 (hpos, HPOS)
F_101 (vpos, VPOS)
F_101 (saturation, SATURATION)
F_101 (contrast, CONTRAST)
F_101 (hue, HUE)
F_101 (brightness, BRIGHTNESS)
F_101 (sharpness, SHARPNESS)
F_101 (flicker_filter, FLICKER_FILTER)
F_101 (flicker_filter_2d, FLICKER_FILTER_2D)
F_101 (flicker_filter_adaptive, FLICKER_FILTER_ADAPTIVE)
F_101 (tv_chroma_filter, TV_CHROMA_FILTER)
F_101 (tv_luma_filter, TV_LUMA_FILTER)
F_101 (dot_crawl, DOT_CRAWL)
}
return - V_301 ;
V_307:
if ( ! F_22 ( V_1 , V_32 , & V_295 , 2 ) )
return - V_312 ;
V_297:
if ( V_1 -> V_4 . V_4 . V_171 ) {
struct V_170 * V_171 = V_1 -> V_4 . V_4 . V_171 ;
F_103 ( V_171 , & V_171 -> V_50 , V_171 -> V_313 ,
V_171 -> V_314 , V_171 -> V_315 ) ;
}
return 0 ;
#undef F_101
}
static void F_104 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
if ( V_1 -> V_95 != NULL )
F_105 ( V_3 -> V_10 ,
V_1 -> V_95 ) ;
F_106 ( & V_1 -> V_236 ) ;
F_107 ( V_3 ) ;
}
static void
F_108 ( struct V_1 * V_235 )
{
T_4 V_316 = 0 ;
unsigned int V_317 ;
switch ( V_235 -> V_318 ) {
case V_319 :
V_316 |= V_319 ;
case V_320 :
V_316 |= V_320 ;
case V_321 :
V_316 |= V_321 ;
case V_322 :
V_316 |= V_322 ;
case V_323 :
V_316 |= V_323 ;
case V_324 :
V_316 |= V_324 ;
break;
}
V_316 &= V_235 -> V_216 . V_229 ;
V_317 = F_66 ( V_316 ) ;
if ( V_317 > 3 )
V_317 = 3 ;
V_235 -> V_51 = 1 << V_317 ;
}
static void
F_109 ( struct V_11 * V_12 ,
struct V_1 * V_235 , T_1 V_325 )
{
struct V_326 * V_327 ;
if ( F_110 ( V_325 ) )
V_327 = & ( V_12 -> V_328 [ 0 ] ) ;
else
V_327 = & ( V_12 -> V_328 [ 1 ] ) ;
if ( V_327 -> V_329 )
V_235 -> V_51 = 1 << ( ( V_327 -> V_330 & 0xf0 ) >> 4 ) ;
else
F_108 ( V_235 ) ;
}
static void
F_111 ( struct V_11 * V_12 ,
struct V_1 * V_235 , T_1 V_325 )
{
struct V_326 * V_327 ;
T_2 V_331 ;
if ( F_110 ( V_325 ) )
V_327 = & V_12 -> V_328 [ 0 ] ;
else
V_327 = & V_12 -> V_328 [ 1 ] ;
V_331 = V_332 ;
if ( V_327 -> V_329 )
V_331 = V_327 -> V_333 ;
if ( V_331 < V_334 ) {
V_235 -> V_31 = & V_12 -> V_237 [ V_331 ] . V_239 ;
F_112 ( V_235 -> V_31 , V_335 ) ;
F_113 ( V_235 -> V_31 , true ) ;
} else {
V_235 -> V_31 = & V_12 -> V_237 [ V_332 ] . V_239 ;
}
}
static bool
F_114 ( struct V_1 * V_1 , int V_336 )
{
return F_40 ( V_1 ) ;
}
static T_2
F_115 ( struct V_9 * V_10 , int V_17 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_326 * V_337 , * V_338 ;
if ( F_110 ( V_17 ) ) {
V_337 = & V_12 -> V_328 [ 0 ] ;
V_338 = & V_12 -> V_328 [ 1 ] ;
} else {
V_337 = & V_12 -> V_328 [ 1 ] ;
V_338 = & V_12 -> V_328 [ 0 ] ;
}
if ( V_337 -> V_25 )
return V_337 -> V_25 ;
if ( V_338 -> V_25 ) {
if ( V_338 -> V_25 == 0x70 )
return 0x72 ;
else
return 0x70 ;
}
if ( F_110 ( V_17 ) )
return 0x70 ;
else
return 0x72 ;
}
static void
F_116 ( struct V_7 * V_6 ,
struct V_1 * V_3 )
{
F_117 ( V_3 -> V_4 . V_4 . V_10 ,
& V_6 -> V_4 . V_4 ,
& V_339 ,
V_6 -> V_4 . V_4 . V_340 ) ;
F_118 ( & V_6 -> V_4 . V_4 ,
& V_341 ) ;
V_6 -> V_4 . V_4 . V_342 = 1 ;
V_6 -> V_4 . V_4 . V_343 = 0 ;
V_6 -> V_4 . V_4 . V_247 . V_344 = V_345 ;
F_119 ( & V_6 -> V_4 , & V_3 -> V_4 ) ;
F_120 ( & V_6 -> V_4 . V_4 ) ;
}
static void
F_121 ( struct V_7 * V_6 )
{
struct V_9 * V_10 = V_6 -> V_4 . V_4 . V_10 ;
F_122 ( & V_6 -> V_4 . V_4 ) ;
if ( F_52 ( V_10 ) -> V_188 >= 4 && F_123 ( V_10 ) )
F_124 ( & V_6 -> V_4 . V_4 ) ;
}
static bool
F_125 ( struct V_1 * V_1 , int V_336 )
{
struct V_2 * V_3 = & V_1 -> V_4 . V_4 ;
struct V_5 * V_6 ;
struct V_231 * V_231 = F_126 ( V_3 ) ;
struct V_346 * V_346 ;
struct V_7 * V_7 ;
V_7 = F_127 ( sizeof( struct V_7 ) , V_347 ) ;
if ( ! V_7 )
return false ;
if ( V_336 == 0 ) {
V_1 -> V_318 |= V_322 ;
V_7 -> V_258 = V_322 ;
} else if ( V_336 == 1 ) {
V_1 -> V_318 |= V_321 ;
V_7 -> V_258 = V_321 ;
}
V_346 = & V_7 -> V_4 ;
V_6 = & V_346 -> V_4 ;
if ( F_63 ( V_1 ) & ( 1 << V_336 ) ) {
V_6 -> V_348 = V_349 ;
V_1 -> V_233 [ 0 ] |= 1 << V_336 ;
V_231 -> V_350 = F_64 ;
F_64 ( V_231 ) ;
}
else
V_6 -> V_348 = V_351 | V_352 ;
V_3 -> V_353 = V_354 ;
V_6 -> V_340 = V_355 ;
if ( F_114 ( V_1 , V_336 ) ) {
V_6 -> V_340 = V_356 ;
V_1 -> V_191 = true ;
}
V_1 -> V_4 . V_357 = ( ( 1 << V_358 ) |
( 1 << V_359 ) ) ;
F_116 ( V_7 , V_1 ) ;
if ( V_1 -> V_191 )
F_121 ( V_7 ) ;
return true ;
}
static bool
F_128 ( struct V_1 * V_1 , int type )
{
struct V_2 * V_3 = & V_1 -> V_4 . V_4 ;
struct V_5 * V_6 ;
struct V_346 * V_346 ;
struct V_7 * V_7 ;
V_7 = F_127 ( sizeof( struct V_7 ) , V_347 ) ;
if ( ! V_7 )
return false ;
V_346 = & V_7 -> V_4 ;
V_6 = & V_346 -> V_4 ;
V_3 -> V_353 = V_360 ;
V_6 -> V_340 = V_361 ;
V_1 -> V_318 |= type ;
V_7 -> V_258 = type ;
V_1 -> V_169 = true ;
V_1 -> V_4 . V_259 = true ;
V_1 -> V_4 . V_357 = 1 << V_362 ;
F_116 ( V_7 , V_1 ) ;
if ( ! F_129 ( V_1 , V_7 , type ) )
goto V_363;
if ( ! F_130 ( V_1 , V_7 ) )
goto V_363;
return true ;
V_363:
F_95 ( V_6 ) ;
return false ;
}
static bool
F_131 ( struct V_1 * V_1 , int V_336 )
{
struct V_2 * V_3 = & V_1 -> V_4 . V_4 ;
struct V_5 * V_6 ;
struct V_346 * V_346 ;
struct V_7 * V_7 ;
V_7 = F_127 ( sizeof( struct V_7 ) , V_347 ) ;
if ( ! V_7 )
return false ;
V_346 = & V_7 -> V_4 ;
V_6 = & V_346 -> V_4 ;
V_6 -> V_348 = V_351 ;
V_3 -> V_353 = V_364 ;
V_6 -> V_340 = V_365 ;
if ( V_336 == 0 ) {
V_1 -> V_318 |= V_324 ;
V_7 -> V_258 = V_324 ;
} else if ( V_336 == 1 ) {
V_1 -> V_318 |= V_323 ;
V_7 -> V_258 = V_323 ;
}
V_1 -> V_4 . V_357 = ( ( 1 << V_358 ) |
( 1 << V_359 ) ) ;
F_116 ( V_7 ,
V_1 ) ;
return true ;
}
static bool
F_132 ( struct V_1 * V_1 , int V_336 )
{
struct V_2 * V_3 = & V_1 -> V_4 . V_4 ;
struct V_5 * V_6 ;
struct V_346 * V_346 ;
struct V_7 * V_7 ;
V_7 = F_127 ( sizeof( struct V_7 ) , V_347 ) ;
if ( ! V_7 )
return false ;
V_346 = & V_7 -> V_4 ;
V_6 = & V_346 -> V_4 ;
V_3 -> V_353 = V_366 ;
V_6 -> V_340 = V_367 ;
if ( V_336 == 0 ) {
V_1 -> V_318 |= V_320 ;
V_7 -> V_258 = V_320 ;
} else if ( V_336 == 1 ) {
V_1 -> V_318 |= V_319 ;
V_7 -> V_258 = V_319 ;
}
V_1 -> V_4 . V_357 = ( ( 1 << V_359 ) |
( 1 << V_368 ) ) ;
F_116 ( V_7 , V_1 ) ;
if ( ! F_130 ( V_1 , V_7 ) )
goto V_363;
return true ;
V_363:
F_95 ( V_6 ) ;
return false ;
}
static bool
F_133 ( struct V_1 * V_1 , T_4 V_26 )
{
V_1 -> V_169 = false ;
V_1 -> V_4 . V_259 = false ;
V_1 -> V_94 = false ;
if ( V_26 & V_322 )
if ( ! F_125 ( V_1 , 0 ) )
return false ;
if ( ( V_26 & V_369 ) == V_369 )
if ( ! F_125 ( V_1 , 1 ) )
return false ;
if ( V_26 & V_256 )
if ( ! F_128 ( V_1 , V_256 ) )
return false ;
if ( V_26 & V_257 )
if ( ! F_128 ( V_1 , V_257 ) )
return false ;
if ( V_26 & V_324 )
if ( ! F_131 ( V_1 , 0 ) )
return false ;
if ( ( V_26 & V_370 ) == V_370 )
if ( ! F_131 ( V_1 , 1 ) )
return false ;
if ( V_26 & V_320 )
if ( ! F_132 ( V_1 , 0 ) )
return false ;
if ( ( V_26 & V_261 ) == V_261 )
if ( ! F_132 ( V_1 , 1 ) )
return false ;
if ( ( V_26 & V_371 ) == 0 ) {
unsigned char V_372 [ 2 ] ;
V_1 -> V_318 = 0 ;
memcpy ( V_372 , & V_1 -> V_216 . V_229 , 2 ) ;
F_12 ( L_31 ,
F_14 ( V_1 ) ,
V_372 [ 0 ] , V_372 [ 1 ] ) ;
return false ;
}
V_1 -> V_4 . V_373 = ( 1 << 0 ) | ( 1 << 1 ) | ( 1 << 2 ) ;
return true ;
}
static bool F_129 ( struct V_1 * V_1 ,
struct V_7 * V_7 ,
int type )
{
struct V_9 * V_10 = V_1 -> V_4 . V_4 . V_10 ;
struct V_159 V_160 ;
T_7 V_161 , V_16 ;
if ( ! F_30 ( V_1 , type ) )
return false ;
F_26 ( sizeof( V_160 ) != 6 ) ;
if ( ! F_23 ( V_1 ,
V_374 ,
& V_160 , sizeof( V_160 ) ) )
return false ;
memcpy ( & V_161 , & V_160 , V_81 ( sizeof( V_161 ) , sizeof( V_160 ) ) ) ;
if ( V_161 == 0 )
return false ;
V_7 -> V_375 = 0 ;
for ( V_16 = 0 ; V_16 < V_300 ; V_16 ++ )
if ( V_161 & ( 1 << V_16 ) )
V_7 -> V_302 [ V_7 -> V_375 ++ ] = V_16 ;
V_7 -> V_291 =
F_134 ( V_10 , V_376 ,
L_32 , V_7 -> V_375 ) ;
if ( ! V_7 -> V_291 )
return false ;
for ( V_16 = 0 ; V_16 < V_7 -> V_375 ; V_16 ++ )
F_135 (
V_7 -> V_291 , V_16 ,
V_16 , V_377 [ V_7 -> V_302 [ V_16 ] ] ) ;
V_1 -> V_162 = V_7 -> V_302 [ 0 ] ;
F_136 ( & V_7 -> V_4 . V_4 ,
V_7 -> V_291 , 0 ) ;
return true ;
}
static bool
F_137 ( struct V_1 * V_1 ,
struct V_7 * V_7 ,
struct V_378 V_379 )
{
struct V_9 * V_10 = V_1 -> V_4 . V_4 . V_10 ;
struct V_5 * V_6 = & V_7 -> V_4 . V_4 ;
T_4 V_40 , V_380 [ 2 ] ;
if ( V_379 . V_381 ) {
if ( ! F_23 ( V_1 ,
V_382 ,
& V_380 , 4 ) )
return false ;
if ( ! F_23 ( V_1 ,
V_383 ,
& V_40 , 2 ) )
return false ;
V_7 -> V_305 = V_380 [ 0 ] ;
V_7 -> V_303 = V_380 [ 0 ] - V_40 ;
V_7 -> V_304 = V_7 -> V_303 ;
V_7 -> V_274 =
F_138 ( V_10 , 0 , L_33 , 0 , V_380 [ 0 ] ) ;
if ( ! V_7 -> V_274 )
return false ;
F_136 ( V_6 ,
V_7 -> V_274 ,
V_7 -> V_303 ) ;
V_7 -> V_275 =
F_138 ( V_10 , 0 , L_34 , 0 , V_380 [ 0 ] ) ;
if ( ! V_7 -> V_275 )
return false ;
F_136 ( V_6 ,
V_7 -> V_275 ,
V_7 -> V_304 ) ;
F_12 ( L_35
L_36 ,
V_380 [ 0 ] , V_380 [ 1 ] , V_40 ) ;
}
if ( V_379 . V_384 ) {
if ( ! F_23 ( V_1 ,
V_385 ,
& V_380 , 4 ) )
return false ;
if ( ! F_23 ( V_1 ,
V_386 ,
& V_40 , 2 ) )
return false ;
V_7 -> V_310 = V_380 [ 0 ] ;
V_7 -> V_308 = V_380 [ 0 ] - V_40 ;
V_7 -> V_309 = V_7 -> V_308 ;
V_7 -> V_276 =
F_138 ( V_10 , 0 ,
L_37 , 0 , V_380 [ 0 ] ) ;
if ( ! V_7 -> V_276 )
return false ;
F_136 ( V_6 ,
V_7 -> V_276 ,
V_7 -> V_308 ) ;
V_7 -> V_277 =
F_138 ( V_10 , 0 ,
L_38 , 0 , V_380 [ 0 ] ) ;
if ( ! V_7 -> V_277 )
return false ;
F_136 ( V_6 ,
V_7 -> V_277 ,
V_7 -> V_309 ) ;
F_12 ( L_39
L_36 ,
V_380 [ 0 ] , V_380 [ 1 ] , V_40 ) ;
}
F_139 ( V_278 , V_387 ) ;
F_139 ( V_279 , V_388 ) ;
F_139 ( V_280 , V_389 ) ;
F_139 ( V_281 , V_390 ) ;
F_139 ( V_282 , V_391 ) ;
F_139 ( V_283 , V_392 ) ;
F_139 ( V_290 , V_393 ) ;
F_139 ( V_284 , V_394 ) ;
F_139 ( V_286 , V_395 ) ;
F_139 ( V_285 , V_396 ) ;
F_139 ( V_288 , V_397 ) ;
F_139 ( V_287 , V_398 ) ;
if ( V_379 . V_289 ) {
if ( ! F_23 ( V_1 , V_399 , & V_40 , 2 ) )
return false ;
V_7 -> V_400 = 1 ;
V_7 -> V_401 = V_40 & 0x1 ;
V_7 -> V_289 =
F_138 ( V_10 , 0 , L_40 , 0 , 1 ) ;
if ( ! V_7 -> V_289 )
return false ;
F_136 ( V_6 ,
V_7 -> V_289 ,
V_7 -> V_401 ) ;
F_12 ( L_41 , V_40 ) ;
}
return true ;
}
static bool
F_140 ( struct V_1 * V_1 ,
struct V_7 * V_7 ,
struct V_378 V_379 )
{
struct V_9 * V_10 = V_1 -> V_4 . V_4 . V_10 ;
struct V_5 * V_6 = & V_7 -> V_4 . V_4 ;
T_4 V_40 , V_380 [ 2 ] ;
F_139 ( V_290 , V_393 ) ;
return true ;
}
static bool F_130 ( struct V_1 * V_1 ,
struct V_7 * V_7 )
{
union {
struct V_378 V_264 ;
T_4 V_40 ;
} V_379 ;
F_26 ( sizeof( V_379 ) != 2 ) ;
V_379 . V_40 = 0 ;
F_23 ( V_1 ,
V_402 ,
& V_379 , sizeof( V_379 ) ) ;
if ( V_379 . V_40 == 0 ) {
F_12 ( L_42 ) ;
return true ;
}
if ( F_91 ( V_7 ) )
return F_137 ( V_1 , V_7 , V_379 . V_264 ) ;
else if ( F_92 ( V_7 ) )
return F_140 ( V_1 , V_7 , V_379 . V_264 ) ;
else
return true ;
}
static int F_141 ( struct V_403 * V_239 ,
struct V_23 * V_24 ,
int V_404 )
{
struct V_1 * V_235 = V_239 -> V_405 ;
if ( ! F_21 ( V_235 , V_235 -> V_51 ) )
return - V_312 ;
return V_235 -> V_31 -> V_406 -> V_407 ( V_235 -> V_31 , V_24 , V_404 ) ;
}
static T_1 F_142 ( struct V_403 * V_239 )
{
struct V_1 * V_235 = V_239 -> V_405 ;
return V_235 -> V_31 -> V_406 -> V_408 ( V_235 -> V_31 ) ;
}
static bool
F_143 ( struct V_1 * V_235 ,
struct V_9 * V_10 )
{
V_235 -> V_236 . V_409 = V_410 ;
V_235 -> V_236 . V_411 = V_412 ;
snprintf ( V_235 -> V_236 . V_35 , V_413 , L_43 ) ;
V_235 -> V_236 . V_10 . V_414 = & V_10 -> V_415 -> V_10 ;
V_235 -> V_236 . V_405 = V_235 ;
V_235 -> V_236 . V_406 = & V_416 ;
return F_144 ( & V_235 -> V_236 ) == 0 ;
}
bool F_145 ( struct V_9 * V_10 , int V_17 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_231 * V_231 ;
struct V_1 * V_1 ;
int V_16 ;
V_1 = F_127 ( sizeof( struct V_1 ) , V_347 ) ;
if ( ! V_1 )
return false ;
V_1 -> V_17 = V_17 ;
V_1 -> V_25 = F_115 ( V_10 , V_17 ) >> 1 ;
F_111 ( V_12 , V_1 , V_17 ) ;
if ( ! F_143 ( V_1 , V_10 ) ) {
F_73 ( V_1 ) ;
return false ;
}
V_231 = & V_1 -> V_4 ;
V_231 -> type = V_417 ;
F_146 ( V_10 , & V_231 -> V_4 , & V_418 , 0 ) ;
for ( V_16 = 0 ; V_16 < 0x40 ; V_16 ++ ) {
T_2 V_419 ;
if ( ! F_10 ( V_1 , V_16 , & V_419 ) ) {
F_12 ( L_44 ,
F_110 ( V_17 ) ? 'B' : 'C' ) ;
goto V_363;
}
}
if ( F_110 ( V_17 ) )
V_12 -> V_420 |= V_421 ;
else
V_12 -> V_420 |= V_422 ;
F_147 ( & V_231 -> V_4 , & V_423 ) ;
if ( ! F_62 ( V_1 , & V_1 -> V_216 ) )
goto V_363;
F_23 ( V_1 , V_424 ,
& V_1 -> V_233 , 2 ) ;
V_1 -> V_233 [ 0 ] &= ~ 0x3 ;
if ( F_133 ( V_1 ,
V_1 -> V_216 . V_229 ) != true ) {
F_12 ( L_45 ,
F_110 ( V_17 ) ? 'B' : 'C' ) ;
goto V_363;
}
F_109 ( V_12 , V_1 , V_17 ) ;
if ( ! F_24 ( V_1 ) )
goto V_363;
if ( ! F_29 ( V_1 ,
& V_1 -> V_209 ,
& V_1 -> V_211 ) )
goto V_363;
F_12 ( L_46
L_47
L_48
L_49 ,
F_14 ( V_1 ) ,
V_1 -> V_216 . V_218 , V_1 -> V_216 . V_219 ,
V_1 -> V_216 . V_220 ,
V_1 -> V_209 / 1000 ,
V_1 -> V_211 / 1000 ,
( V_1 -> V_216 . V_223 & 0x1 ) ? 'Y' : 'N' ,
( V_1 -> V_216 . V_223 & 0x2 ) ? 'Y' : 'N' ,
V_1 -> V_216 . V_229 &
( V_322 | V_324 ) ? 'Y' : 'N' ,
V_1 -> V_216 . V_229 &
( V_321 | V_323 ) ? 'Y' : 'N' ) ;
return true ;
V_363:
F_148 ( & V_231 -> V_4 ) ;
F_106 ( & V_1 -> V_236 ) ;
F_73 ( V_1 ) ;
return false ;
}
