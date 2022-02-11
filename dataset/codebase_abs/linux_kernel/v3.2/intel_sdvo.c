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
V_90 = V_50 -> V_109 ;
V_91 = V_50 -> V_110 ;
V_103 = V_50 -> V_111 - V_50 -> V_112 ;
V_104 = V_50 -> V_113 - V_50 -> V_114 ;
V_105 = V_50 -> V_115 - V_50 -> V_116 ;
V_106 = V_50 -> V_117 - V_50 -> V_118 ;
V_107 = V_50 -> V_114 - V_50 -> V_112 ;
V_108 = V_50 -> V_118 - V_50 -> V_116 ;
V_85 -> V_86 . clock = V_50 -> clock / 10 ;
V_85 -> V_86 . V_119 = V_90 & 0xff ;
V_85 -> V_86 . V_120 = V_103 & 0xff ;
V_85 -> V_86 . V_121 = ( ( ( V_90 >> 8 ) & 0xf ) << 4 ) |
( ( V_103 >> 8 ) & 0xf ) ;
V_85 -> V_86 . V_122 = V_91 & 0xff ;
V_85 -> V_86 . V_123 = V_105 & 0xff ;
V_85 -> V_86 . V_124 = ( ( ( V_91 >> 8 ) & 0xf ) << 4 ) |
( ( V_105 >> 8 ) & 0xf ) ;
V_85 -> V_87 . V_125 = V_107 & 0xff ;
V_85 -> V_87 . V_126 = V_104 & 0xff ;
V_85 -> V_87 . V_127 = ( V_108 & 0xf ) << 4 |
( V_106 & 0xf ) ;
V_85 -> V_87 . V_128 = ( ( V_107 & 0x300 ) >> 2 ) |
( ( V_104 & 0x300 ) >> 4 ) | ( ( V_108 & 0x30 ) >> 2 ) |
( ( V_106 & 0x30 ) >> 4 ) ;
V_85 -> V_87 . V_129 = 0x18 ;
if ( V_50 -> V_26 & V_130 )
V_85 -> V_87 . V_129 |= 0x2 ;
if ( V_50 -> V_26 & V_131 )
V_85 -> V_87 . V_129 |= 0x4 ;
V_85 -> V_87 . V_132 = 0 ;
V_85 -> V_87 . V_133 = V_108 & 0xc0 ;
V_85 -> V_87 . V_134 = 0 ;
}
static void F_38 ( struct V_49 * V_50 ,
const struct V_84 * V_85 )
{
V_50 -> V_96 = V_85 -> V_86 . V_119 ;
V_50 -> V_96 += ( ( V_85 -> V_86 . V_121 >> 4 ) & 0x0f ) << 8 ;
V_50 -> V_135 = V_50 -> V_96 + V_85 -> V_87 . V_125 ;
V_50 -> V_135 += ( V_85 -> V_87 . V_128 & 0xc0 ) << 2 ;
V_50 -> V_136 = V_50 -> V_135 + V_85 -> V_87 . V_126 ;
V_50 -> V_136 += ( V_85 -> V_87 . V_128 & 0x30 ) << 4 ;
V_50 -> V_137 = V_50 -> V_96 + V_85 -> V_86 . V_120 ;
V_50 -> V_137 += ( V_85 -> V_86 . V_121 & 0xf ) << 8 ;
V_50 -> V_97 = V_85 -> V_86 . V_122 ;
V_50 -> V_97 += ( ( V_85 -> V_86 . V_124 >> 4 ) & 0x0f ) << 8 ;
V_50 -> V_138 = V_50 -> V_97 ;
V_50 -> V_138 += ( V_85 -> V_87 . V_127 >> 4 ) & 0xf ;
V_50 -> V_138 += ( V_85 -> V_87 . V_128 & 0x0c ) << 2 ;
V_50 -> V_138 += V_85 -> V_87 . V_133 & 0xc0 ;
V_50 -> V_139 = V_50 -> V_138 +
( V_85 -> V_87 . V_127 & 0xf ) ;
V_50 -> V_139 += ( V_85 -> V_87 . V_128 & 0x3 ) << 4 ;
V_50 -> V_140 = V_50 -> V_97 + V_85 -> V_86 . V_123 ;
V_50 -> V_140 += ( V_85 -> V_86 . V_124 & 0xf ) << 8 ;
V_50 -> clock = V_85 -> V_86 . clock * 10 ;
V_50 -> V_26 &= ~ ( V_130 | V_131 ) ;
if ( V_85 -> V_87 . V_129 & 0x2 )
V_50 -> V_26 |= V_130 ;
if ( V_85 -> V_87 . V_129 & 0x4 )
V_50 -> V_26 |= V_131 ;
}
static bool F_39 ( struct V_1 * V_1 )
{
struct V_141 V_142 ;
F_26 ( sizeof( V_142 ) != 2 ) ;
return F_23 ( V_1 ,
V_143 ,
& V_142 , sizeof( V_142 ) ) ;
}
static bool F_40 ( struct V_1 * V_1 ,
T_5 V_50 )
{
return F_22 ( V_1 , V_144 , & V_50 , 1 ) ;
}
static bool F_41 ( struct V_1 * V_1 ,
T_5 V_50 )
{
return F_22 ( V_1 , V_145 , & V_50 , 1 ) ;
}
static bool F_42 ( struct V_1 * V_1 )
{
struct V_146 V_147 = {
. type = V_148 ,
. V_149 = V_150 ,
. V_27 = V_151 ,
} ;
T_5 V_152 = V_153 ;
T_5 V_154 [ 2 ] = { 1 , 0 } ;
T_6 * V_53 = ( T_6 * ) & V_147 ;
unsigned V_16 ;
F_43 ( & V_147 ) ;
if ( ! F_22 ( V_1 ,
V_155 ,
V_154 , 2 ) )
return false ;
for ( V_16 = 0 ; V_16 < sizeof( V_147 ) ; V_16 += 8 ) {
if ( ! F_22 ( V_1 ,
V_156 ,
V_53 , 8 ) )
return false ;
V_53 ++ ;
}
return F_22 ( V_1 ,
V_157 ,
& V_152 , 1 ) ;
}
static bool F_44 ( struct V_1 * V_1 )
{
struct V_158 V_159 ;
T_7 V_160 ;
V_160 = 1 << V_1 -> V_161 ;
memset ( & V_159 , 0 , sizeof( V_159 ) ) ;
memcpy ( & V_159 , & V_160 , V_81 ( sizeof( V_159 ) , sizeof( V_160 ) ) ) ;
F_26 ( sizeof( V_159 ) != 6 ) ;
return F_22 ( V_1 ,
V_162 ,
& V_159 , sizeof( V_159 ) ) ;
}
static bool
F_45 ( struct V_1 * V_1 ,
struct V_49 * V_50 )
{
struct V_84 V_163 ;
if ( ! F_30 ( V_1 ,
V_1 -> V_164 ) )
return false ;
F_37 ( & V_163 , V_50 ) ;
if ( ! F_33 ( V_1 , & V_163 ) )
return false ;
return true ;
}
static bool
F_46 ( struct V_1 * V_1 ,
struct V_49 * V_50 ,
struct V_49 * V_165 )
{
if ( ! F_24 ( V_1 ) )
return false ;
if ( ! F_34 ( V_1 ,
V_50 -> clock / 10 ,
V_50 -> V_96 ,
V_50 -> V_97 ) )
return false ;
if ( ! F_35 ( V_1 ,
& V_1 -> V_166 ) )
return false ;
F_38 ( V_165 , & V_1 -> V_166 ) ;
F_47 ( V_165 , 0 ) ;
return true ;
}
static bool F_48 ( struct V_2 * V_3 ,
struct V_49 * V_50 ,
struct V_49 * V_165 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
int V_167 ;
if ( V_1 -> V_168 ) {
if ( ! F_45 ( V_1 , V_50 ) )
return false ;
( void ) F_46 ( V_1 ,
V_50 ,
V_165 ) ;
} else if ( V_1 -> V_94 ) {
if ( ! F_45 ( V_1 ,
V_1 -> V_95 ) )
return false ;
( void ) F_46 ( V_1 ,
V_50 ,
V_165 ) ;
}
V_167 = F_20 ( V_165 ) ;
F_49 ( V_165 , V_167 ) ;
return true ;
}
static void F_50 ( struct V_2 * V_3 ,
struct V_49 * V_50 ,
struct V_49 * V_165 )
{
struct V_9 * V_10 = V_3 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_169 * V_170 = V_3 -> V_170 ;
struct V_171 * V_171 = F_51 ( V_170 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
T_1 V_172 ;
struct V_173 V_174 ;
struct V_84 V_166 ;
int V_175 = F_52 ( V_165 ) ;
int V_176 ;
if ( ! V_50 )
return;
V_174 . V_177 = V_1 -> V_164 ;
V_174 . V_178 = 0 ;
F_22 ( V_1 ,
V_179 ,
& V_174 , sizeof( V_174 ) ) ;
if ( ! F_30 ( V_1 ,
V_1 -> V_164 ) )
return;
if ( V_1 -> V_168 || V_1 -> V_94 ) {
V_166 = V_1 -> V_166 ;
} else {
if ( ! F_30 ( V_1 ,
V_1 -> V_164 ) )
return;
F_37 ( & V_166 , V_165 ) ;
( void ) F_33 ( V_1 , & V_166 ) ;
}
if ( ! F_24 ( V_1 ) )
return;
if ( V_1 -> V_180 ) {
F_40 ( V_1 , V_181 ) ;
F_41 ( V_1 ,
V_182 ) ;
F_42 ( V_1 ) ;
} else
F_40 ( V_1 , V_183 ) ;
if ( V_1 -> V_168 &&
! F_44 ( V_1 ) )
return;
( void ) F_32 ( V_1 , & V_166 ) ;
switch ( V_175 ) {
default:
case 1 : V_176 = V_184 ; break;
case 2 : V_176 = V_185 ; break;
case 4 : V_176 = V_186 ; break;
}
if ( ! F_36 ( V_1 , V_176 ) )
return;
if ( F_53 ( V_10 ) -> V_187 >= 4 ) {
V_172 = 0 ;
if ( V_1 -> V_188 )
V_172 |= V_1 -> V_189 ;
if ( F_53 ( V_10 ) -> V_187 < 5 )
V_172 |= V_190 ;
if ( V_165 -> V_26 & V_131 )
V_172 |= V_191 ;
if ( V_165 -> V_26 & V_130 )
V_172 |= V_192 ;
} else {
V_172 = F_9 ( V_1 -> V_17 ) ;
switch ( V_1 -> V_17 ) {
case V_19 :
V_172 &= V_193 ;
break;
case V_20 :
V_172 &= V_194 ;
break;
}
V_172 |= ( 9 << 19 ) | V_190 ;
}
if ( F_54 ( V_10 ) >= V_195 )
V_172 |= F_55 ( V_171 -> V_196 ) ;
else
V_172 |= F_56 ( V_171 -> V_196 ) ;
if ( V_1 -> V_197 )
V_172 |= V_198 ;
if ( F_53 ( V_10 ) -> V_187 >= 4 ) {
} else if ( F_57 ( V_10 ) || F_58 ( V_10 ) || F_59 ( V_10 ) ) {
} else {
V_172 |= ( V_175 - 1 ) << V_199 ;
}
if ( V_166 . V_87 . V_132 & V_200 &&
F_53 ( V_10 ) -> V_187 < 5 )
V_172 |= V_201 ;
F_7 ( V_1 , V_172 ) ;
}
static void F_60 ( struct V_2 * V_3 , int V_50 )
{
struct V_9 * V_10 = V_3 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_171 * V_171 = F_51 ( V_3 -> V_170 ) ;
T_1 V_202 ;
if ( V_50 != V_68 ) {
F_27 ( V_1 , 0 ) ;
if ( 0 )
F_28 ( V_1 , V_50 ) ;
if ( V_50 == V_73 ) {
V_202 = F_9 ( V_1 -> V_17 ) ;
if ( ( V_202 & V_203 ) != 0 ) {
F_7 ( V_1 , V_202 & ~ V_203 ) ;
}
}
} else {
bool V_204 , V_205 ;
int V_16 ;
T_2 V_36 ;
V_202 = F_9 ( V_1 -> V_17 ) ;
if ( ( V_202 & V_203 ) == 0 )
F_7 ( V_1 , V_202 | V_203 ) ;
for ( V_16 = 0 ; V_16 < 2 ; V_16 ++ )
F_61 ( V_10 , V_171 -> V_196 ) ;
V_36 = F_25 ( V_1 , & V_204 , & V_205 ) ;
if ( V_36 == V_47 && ! V_204 ) {
F_12 ( L_14
L_15 , F_14 ( V_1 ) ) ;
}
if ( 0 )
F_28 ( V_1 , V_50 ) ;
F_27 ( V_1 , V_1 -> V_164 ) ;
}
return;
}
static int F_62 ( struct V_5 * V_6 ,
struct V_49 * V_50 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
if ( V_50 -> V_26 & V_206 )
return V_207 ;
if ( V_1 -> V_208 > V_50 -> clock )
return V_209 ;
if ( V_1 -> V_210 < V_50 -> clock )
return V_211 ;
if ( V_1 -> V_94 ) {
if ( V_50 -> V_96 > V_1 -> V_95 -> V_96 )
return V_212 ;
if ( V_50 -> V_97 > V_1 -> V_95 -> V_97 )
return V_212 ;
}
return V_213 ;
}
static bool F_63 ( struct V_1 * V_1 , struct V_214 * V_215 )
{
F_26 ( sizeof( * V_215 ) != 8 ) ;
if ( ! F_23 ( V_1 ,
V_216 ,
V_215 , sizeof( * V_215 ) ) )
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
V_215 -> V_217 ,
V_215 -> V_218 ,
V_215 -> V_219 ,
V_215 -> V_220 ,
V_215 -> V_221 ,
V_215 -> V_222 ,
V_215 -> V_223 ,
V_215 -> V_224 ,
V_215 -> V_225 ,
V_215 -> V_226 ,
V_215 -> V_227 ,
V_215 -> V_228 ) ;
return true ;
}
static int F_64 ( struct V_1 * V_1 )
{
T_2 V_40 [ 2 ] ;
return F_23 ( V_1 , V_229 ,
& V_40 , 2 ) && V_40 [ 0 ] ;
}
static void F_65 ( struct V_230 * V_3 )
{
struct V_1 * V_1 = F_1 ( & V_3 -> V_4 ) ;
F_17 ( V_1 , V_231 , & V_1 -> V_232 , 2 ) ;
}
static bool
F_66 ( struct V_1 * V_1 )
{
return F_67 ( V_1 -> V_215 . V_228 ) > 1 ;
}
static struct V_233 *
F_68 ( struct V_5 * V_6 )
{
struct V_1 * V_234 = F_3 ( V_6 ) ;
return F_69 ( V_6 , & V_234 -> V_235 ) ;
}
static struct V_233 *
F_70 ( struct V_5 * V_6 )
{
struct V_11 * V_12 = V_6 -> V_10 -> V_13 ;
return F_69 ( V_6 ,
& V_12 -> V_236 [ V_12 -> V_237 ] . V_238 ) ;
}
enum V_239
F_71 ( struct V_5 * V_6 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
enum V_239 V_36 ;
struct V_233 * V_233 ;
V_233 = F_68 ( V_6 ) ;
if ( V_233 == NULL && F_66 ( V_1 ) ) {
T_2 V_235 , V_240 = V_1 -> V_51 ;
for ( V_235 = V_1 -> V_51 >> 1 ; V_235 > 1 ; V_235 >>= 1 ) {
V_1 -> V_51 = V_235 ;
V_233 = F_68 ( V_6 ) ;
if ( V_233 )
break;
}
if ( V_233 == NULL )
V_1 -> V_51 = V_240 ;
}
if ( V_233 == NULL )
V_233 = F_70 ( V_6 ) ;
V_36 = V_241 ;
if ( V_233 != NULL ) {
if ( V_233 -> V_242 & V_243 ) {
V_36 = V_244 ;
if ( V_1 -> V_188 ) {
V_1 -> V_180 = F_72 ( V_233 ) ;
V_1 -> V_197 = F_73 ( V_233 ) ;
}
} else
V_36 = V_245 ;
V_6 -> V_246 . V_247 = NULL ;
F_74 ( V_233 ) ;
}
if ( V_36 == V_244 ) {
struct V_7 * V_7 = F_5 ( V_6 ) ;
if ( V_7 -> V_248 )
V_1 -> V_197 = V_7 -> V_248 > 0 ;
}
return V_36 ;
}
static bool
F_75 ( struct V_7 * V_234 ,
struct V_233 * V_233 )
{
bool V_249 = ! ! ( V_233 -> V_242 & V_243 ) ;
bool V_250 = ! ! F_76 ( V_234 ) ;
F_12 ( L_29 ,
V_250 , V_249 ) ;
return V_250 == V_249 ;
}
static enum V_239
F_77 ( struct V_5 * V_6 , bool V_251 )
{
T_4 V_40 ;
struct V_1 * V_1 = F_3 ( V_6 ) ;
struct V_7 * V_7 = F_5 ( V_6 ) ;
enum V_239 V_30 ;
if ( ! F_17 ( V_1 ,
V_252 , NULL , 0 ) )
return V_241 ;
if ( V_1 -> V_215 . V_228 &
( V_253 | V_254 ) )
F_78 ( 30 ) ;
if ( ! F_18 ( V_1 , & V_40 , 2 ) )
return V_241 ;
F_12 ( L_30 ,
V_40 & 0xff , V_40 >> 8 ,
V_7 -> V_255 ) ;
if ( V_40 == 0 )
return V_245 ;
V_1 -> V_164 = V_40 ;
V_1 -> V_180 = false ;
V_1 -> V_197 = false ;
if ( ( V_7 -> V_255 & V_40 ) == 0 )
V_30 = V_245 ;
else if ( F_79 ( V_7 ) )
V_30 = F_71 ( V_6 ) ;
else {
struct V_233 * V_233 ;
V_233 = F_68 ( V_6 ) ;
if ( V_233 == NULL )
V_233 = F_70 ( V_6 ) ;
if ( V_233 != NULL ) {
if ( F_75 ( V_7 ,
V_233 ) )
V_30 = V_244 ;
else
V_30 = V_245 ;
V_6 -> V_246 . V_247 = NULL ;
F_74 ( V_233 ) ;
} else
V_30 = V_244 ;
}
if ( V_30 == V_244 ) {
V_1 -> V_168 = false ;
V_1 -> V_94 = false ;
V_1 -> V_4 . V_256 = false ;
if ( V_40 & V_257 ) {
V_1 -> V_168 = true ;
V_1 -> V_4 . V_256 = true ;
}
if ( V_40 & V_258 )
V_1 -> V_94 = V_1 -> V_95 != NULL ;
}
return V_30 ;
}
static void F_80 ( struct V_5 * V_6 )
{
struct V_233 * V_233 ;
V_233 = F_68 ( V_6 ) ;
if ( V_233 == NULL )
V_233 = F_70 ( V_6 ) ;
if ( V_233 != NULL ) {
if ( F_75 ( F_5 ( V_6 ) ,
V_233 ) ) {
F_81 ( V_6 , V_233 ) ;
F_82 ( V_6 , V_233 ) ;
}
V_6 -> V_246 . V_247 = NULL ;
F_74 ( V_233 ) ;
}
}
static void F_83 ( struct V_5 * V_6 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
struct V_259 V_260 ;
T_7 V_261 = 0 , V_160 = 0 ;
int V_16 ;
V_160 = 1 << V_1 -> V_161 ;
memcpy ( & V_260 , & V_160 ,
V_81 ( sizeof( V_160 ) , sizeof( struct V_259 ) ) ) ;
if ( ! F_30 ( V_1 , V_1 -> V_164 ) )
return;
F_26 ( sizeof( V_260 ) != 3 ) ;
if ( ! F_17 ( V_1 ,
V_262 ,
& V_260 , sizeof( V_260 ) ) )
return;
if ( ! F_18 ( V_1 , & V_261 , 3 ) )
return;
for ( V_16 = 0 ; V_16 < F_16 ( V_263 ) ; V_16 ++ )
if ( V_261 & ( 1 << V_16 ) ) {
struct V_49 * V_264 ;
V_264 = F_84 ( V_6 -> V_10 ,
& V_263 [ V_16 ] ) ;
if ( V_264 )
F_85 ( V_6 , V_264 ) ;
}
}
static void F_86 ( struct V_5 * V_6 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
struct V_11 * V_12 = V_6 -> V_10 -> V_13 ;
struct V_49 * V_265 ;
F_87 ( V_6 , V_1 -> V_31 ) ;
if ( F_88 ( & V_6 -> V_266 ) == false )
goto V_267;
if ( V_12 -> V_268 != NULL ) {
V_265 = F_84 ( V_6 -> V_10 ,
V_12 -> V_268 ) ;
if ( V_265 != NULL ) {
V_265 -> type = ( V_269 |
V_270 ) ;
F_85 ( V_6 , V_265 ) ;
}
}
V_267:
F_89 (newmode, &connector->probed_modes, head) {
if ( V_265 -> type & V_269 ) {
V_1 -> V_95 =
F_84 ( V_6 -> V_10 , V_265 ) ;
F_47 ( V_1 -> V_95 ,
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
F_83 ( V_6 ) ;
else if ( F_92 ( V_7 ) )
F_86 ( V_6 ) ;
else
F_80 ( V_6 ) ;
return ! F_88 ( & V_6 -> V_266 ) ;
}
static void
F_93 ( struct V_5 * V_6 )
{
struct V_7 * V_7 = F_5 ( V_6 ) ;
struct V_9 * V_10 = V_6 -> V_10 ;
if ( V_7 -> V_271 )
F_94 ( V_10 , V_7 -> V_271 ) ;
if ( V_7 -> V_272 )
F_94 ( V_10 , V_7 -> V_272 ) ;
if ( V_7 -> V_273 )
F_94 ( V_10 , V_7 -> V_273 ) ;
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
}
static void F_95 ( struct V_5 * V_6 )
{
struct V_7 * V_7 = F_5 ( V_6 ) ;
if ( V_7 -> V_288 )
F_94 ( V_6 -> V_10 ,
V_7 -> V_288 ) ;
F_93 ( V_6 ) ;
F_96 ( V_6 ) ;
F_97 ( V_6 ) ;
F_74 ( V_6 ) ;
}
static bool F_98 ( struct V_5 * V_6 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
struct V_233 * V_233 ;
bool V_289 = false ;
if ( ! V_1 -> V_188 )
return false ;
V_233 = F_68 ( V_6 ) ;
if ( V_233 != NULL && V_233 -> V_242 & V_243 )
V_289 = F_73 ( V_233 ) ;
return V_289 ;
}
static int
F_99 ( struct V_5 * V_6 ,
struct V_290 * V_291 ,
T_6 V_8 )
{
struct V_1 * V_1 = F_3 ( V_6 ) ;
struct V_7 * V_7 = F_5 ( V_6 ) ;
struct V_11 * V_12 = V_6 -> V_10 -> V_13 ;
T_4 V_292 ;
T_5 V_32 ;
int V_30 ;
V_30 = F_100 ( V_6 , V_291 , V_8 ) ;
if ( V_30 )
return V_30 ;
if ( V_291 == V_12 -> V_293 ) {
int V_16 = V_8 ;
bool V_289 ;
if ( V_16 == V_7 -> V_248 )
return 0 ;
V_7 -> V_248 = V_16 ;
if ( V_16 == 0 )
V_289 = F_98 ( V_6 ) ;
else
V_289 = V_16 > 0 ;
if ( V_289 == V_1 -> V_197 )
return 0 ;
V_1 -> V_197 = V_289 ;
goto V_294;
}
if ( V_291 == V_12 -> V_295 ) {
if ( V_8 == ! ! V_1 -> V_189 )
return 0 ;
V_1 -> V_189 = V_8 ? V_296 : 0 ;
goto V_294;
}
#define F_101 ( V_35 , T_8 ) \
if (intel_sdvo_connector->name == property) { \
if (intel_sdvo_connector->cur_##name == temp_value) return 0; \
if (intel_sdvo_connector->max_##name < temp_value) return -EINVAL; \
cmd = SDVO_CMD_SET_##NAME; \
intel_sdvo_connector->cur_##name = temp_value; \
goto set_value; \
}
if ( V_291 == V_7 -> V_288 ) {
if ( V_8 >= V_297 )
return - V_298 ;
if ( V_1 -> V_161 ==
V_7 -> V_299 [ V_8 ] )
return 0 ;
V_1 -> V_161 = V_7 -> V_299 [ V_8 ] ;
goto V_294;
} else if ( F_102 ( V_7 ) ) {
V_292 = V_8 ;
if ( V_7 -> V_271 == V_291 ) {
F_100 ( V_6 ,
V_7 -> V_272 , V_8 ) ;
if ( V_7 -> V_300 == V_292 )
return 0 ;
V_7 -> V_300 = V_292 ;
V_7 -> V_301 = V_292 ;
V_292 = V_7 -> V_302 -
V_7 -> V_300 ;
V_32 = V_303 ;
goto V_304;
} else if ( V_7 -> V_272 == V_291 ) {
F_100 ( V_6 ,
V_7 -> V_271 , V_8 ) ;
if ( V_7 -> V_301 == V_292 )
return 0 ;
V_7 -> V_300 = V_292 ;
V_7 -> V_301 = V_292 ;
V_292 = V_7 -> V_302 -
V_7 -> V_300 ;
V_32 = V_303 ;
goto V_304;
} else if ( V_7 -> V_273 == V_291 ) {
F_100 ( V_6 ,
V_7 -> V_274 , V_8 ) ;
if ( V_7 -> V_305 == V_292 )
return 0 ;
V_7 -> V_305 = V_292 ;
V_7 -> V_306 = V_292 ;
V_292 = V_7 -> V_307 -
V_7 -> V_305 ;
V_32 = V_308 ;
goto V_304;
} else if ( V_7 -> V_274 == V_291 ) {
F_100 ( V_6 ,
V_7 -> V_273 , V_8 ) ;
if ( V_7 -> V_306 == V_292 )
return 0 ;
V_7 -> V_305 = V_292 ;
V_7 -> V_306 = V_292 ;
V_292 = V_7 -> V_307 -
V_7 -> V_305 ;
V_32 = V_308 ;
goto V_304;
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
return - V_298 ;
V_304:
if ( ! F_22 ( V_1 , V_32 , & V_292 , 2 ) )
return - V_309 ;
V_294:
if ( V_1 -> V_4 . V_4 . V_170 ) {
struct V_169 * V_170 = V_1 -> V_4 . V_4 . V_170 ;
F_103 ( V_170 , & V_170 -> V_50 , V_170 -> V_310 ,
V_170 -> V_311 , V_170 -> V_312 ) ;
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
F_106 ( & V_1 -> V_235 ) ;
F_107 ( V_3 ) ;
}
static void
F_108 ( struct V_1 * V_234 )
{
T_4 V_313 = 0 ;
unsigned int V_314 ;
switch ( V_234 -> V_315 ) {
case V_316 :
V_313 |= V_316 ;
case V_317 :
V_313 |= V_317 ;
case V_318 :
V_313 |= V_318 ;
case V_319 :
V_313 |= V_319 ;
case V_320 :
V_313 |= V_320 ;
case V_321 :
V_313 |= V_321 ;
break;
}
V_313 &= V_234 -> V_215 . V_228 ;
V_314 = F_67 ( V_313 ) ;
if ( V_314 > 3 )
V_314 = 3 ;
V_234 -> V_51 = 1 << V_314 ;
}
static void
F_109 ( struct V_11 * V_12 ,
struct V_1 * V_234 , T_1 V_322 )
{
struct V_323 * V_324 ;
if ( F_110 ( V_322 ) )
V_324 = & ( V_12 -> V_325 [ 0 ] ) ;
else
V_324 = & ( V_12 -> V_325 [ 1 ] ) ;
if ( V_324 -> V_326 )
V_234 -> V_51 = 1 << ( ( V_324 -> V_327 & 0xf0 ) >> 4 ) ;
else
F_108 ( V_234 ) ;
}
static void
F_111 ( struct V_11 * V_12 ,
struct V_1 * V_234 , T_1 V_322 )
{
struct V_323 * V_324 ;
T_2 V_328 ;
if ( F_110 ( V_322 ) )
V_324 = & V_12 -> V_325 [ 0 ] ;
else
V_324 = & V_12 -> V_325 [ 1 ] ;
V_328 = V_329 ;
if ( V_324 -> V_326 )
V_328 = V_324 -> V_330 ;
if ( V_328 < V_331 ) {
V_234 -> V_31 = & V_12 -> V_236 [ V_328 ] . V_238 ;
F_112 ( V_234 -> V_31 , V_332 ) ;
F_113 ( V_234 -> V_31 , true ) ;
} else {
V_234 -> V_31 = & V_12 -> V_236 [ V_329 ] . V_238 ;
}
}
static bool
F_114 ( struct V_1 * V_1 , int V_333 )
{
return F_39 ( V_1 ) ;
}
static T_2
F_115 ( struct V_9 * V_10 , int V_17 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_323 * V_334 , * V_335 ;
if ( F_110 ( V_17 ) ) {
V_334 = & V_12 -> V_325 [ 0 ] ;
V_335 = & V_12 -> V_325 [ 1 ] ;
} else {
V_334 = & V_12 -> V_325 [ 1 ] ;
V_335 = & V_12 -> V_325 [ 0 ] ;
}
if ( V_334 -> V_25 )
return V_334 -> V_25 ;
if ( V_335 -> V_25 ) {
if ( V_335 -> V_25 == 0x70 )
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
& V_336 ,
V_6 -> V_4 . V_4 . V_337 ) ;
F_118 ( & V_6 -> V_4 . V_4 ,
& V_338 ) ;
V_6 -> V_4 . V_4 . V_339 = 0 ;
V_6 -> V_4 . V_4 . V_340 = 0 ;
V_6 -> V_4 . V_4 . V_246 . V_341 = V_342 ;
F_119 ( & V_6 -> V_4 , & V_3 -> V_4 ) ;
F_120 ( & V_6 -> V_4 . V_4 ) ;
}
static void
F_121 ( struct V_7 * V_6 )
{
struct V_9 * V_10 = V_6 -> V_4 . V_4 . V_10 ;
F_122 ( & V_6 -> V_4 . V_4 ) ;
if ( F_53 ( V_10 ) -> V_187 >= 4 && F_123 ( V_10 ) )
F_124 ( & V_6 -> V_4 . V_4 ) ;
}
static bool
F_125 ( struct V_1 * V_1 , int V_333 )
{
struct V_2 * V_3 = & V_1 -> V_4 . V_4 ;
struct V_5 * V_6 ;
struct V_230 * V_230 = F_126 ( V_3 ) ;
struct V_343 * V_343 ;
struct V_7 * V_7 ;
V_7 = F_127 ( sizeof( struct V_7 ) , V_344 ) ;
if ( ! V_7 )
return false ;
if ( V_333 == 0 ) {
V_1 -> V_315 |= V_319 ;
V_7 -> V_255 = V_319 ;
} else if ( V_333 == 1 ) {
V_1 -> V_315 |= V_318 ;
V_7 -> V_255 = V_318 ;
}
V_343 = & V_7 -> V_4 ;
V_6 = & V_343 -> V_4 ;
if ( F_64 ( V_1 ) & ( 1 << V_333 ) ) {
V_6 -> V_345 = V_346 ;
V_1 -> V_232 [ 0 ] |= 1 << V_333 ;
V_230 -> V_347 = F_65 ;
F_65 ( V_230 ) ;
}
else
V_6 -> V_345 = V_348 | V_349 ;
V_3 -> V_350 = V_351 ;
V_6 -> V_337 = V_352 ;
if ( F_114 ( V_1 , V_333 ) ) {
V_6 -> V_337 = V_353 ;
V_1 -> V_188 = true ;
}
V_1 -> V_4 . V_354 = ( ( 1 << V_355 ) |
( 1 << V_356 ) ) ;
F_116 ( V_7 , V_1 ) ;
if ( V_1 -> V_188 )
F_121 ( V_7 ) ;
return true ;
}
static bool
F_128 ( struct V_1 * V_1 , int type )
{
struct V_2 * V_3 = & V_1 -> V_4 . V_4 ;
struct V_5 * V_6 ;
struct V_343 * V_343 ;
struct V_7 * V_7 ;
V_7 = F_127 ( sizeof( struct V_7 ) , V_344 ) ;
if ( ! V_7 )
return false ;
V_343 = & V_7 -> V_4 ;
V_6 = & V_343 -> V_4 ;
V_3 -> V_350 = V_357 ;
V_6 -> V_337 = V_358 ;
V_1 -> V_315 |= type ;
V_7 -> V_255 = type ;
V_1 -> V_168 = true ;
V_1 -> V_4 . V_256 = true ;
V_1 -> V_4 . V_354 = 1 << V_359 ;
F_116 ( V_7 , V_1 ) ;
if ( ! F_129 ( V_1 , V_7 , type ) )
goto V_360;
if ( ! F_130 ( V_1 , V_7 ) )
goto V_360;
return true ;
V_360:
F_95 ( V_6 ) ;
return false ;
}
static bool
F_131 ( struct V_1 * V_1 , int V_333 )
{
struct V_2 * V_3 = & V_1 -> V_4 . V_4 ;
struct V_5 * V_6 ;
struct V_343 * V_343 ;
struct V_7 * V_7 ;
V_7 = F_127 ( sizeof( struct V_7 ) , V_344 ) ;
if ( ! V_7 )
return false ;
V_343 = & V_7 -> V_4 ;
V_6 = & V_343 -> V_4 ;
V_6 -> V_345 = V_348 ;
V_3 -> V_350 = V_361 ;
V_6 -> V_337 = V_362 ;
if ( V_333 == 0 ) {
V_1 -> V_315 |= V_321 ;
V_7 -> V_255 = V_321 ;
} else if ( V_333 == 1 ) {
V_1 -> V_315 |= V_320 ;
V_7 -> V_255 = V_320 ;
}
V_1 -> V_4 . V_354 = ( ( 1 << V_355 ) |
( 1 << V_356 ) ) ;
F_116 ( V_7 ,
V_1 ) ;
return true ;
}
static bool
F_132 ( struct V_1 * V_1 , int V_333 )
{
struct V_2 * V_3 = & V_1 -> V_4 . V_4 ;
struct V_5 * V_6 ;
struct V_343 * V_343 ;
struct V_7 * V_7 ;
V_7 = F_127 ( sizeof( struct V_7 ) , V_344 ) ;
if ( ! V_7 )
return false ;
V_343 = & V_7 -> V_4 ;
V_6 = & V_343 -> V_4 ;
V_3 -> V_350 = V_363 ;
V_6 -> V_337 = V_364 ;
if ( V_333 == 0 ) {
V_1 -> V_315 |= V_317 ;
V_7 -> V_255 = V_317 ;
} else if ( V_333 == 1 ) {
V_1 -> V_315 |= V_316 ;
V_7 -> V_255 = V_316 ;
}
V_1 -> V_4 . V_354 = ( ( 1 << V_356 ) |
( 1 << V_365 ) ) ;
F_116 ( V_7 , V_1 ) ;
if ( ! F_130 ( V_1 , V_7 ) )
goto V_360;
return true ;
V_360:
F_95 ( V_6 ) ;
return false ;
}
static bool
F_133 ( struct V_1 * V_1 , T_4 V_26 )
{
V_1 -> V_168 = false ;
V_1 -> V_4 . V_256 = false ;
V_1 -> V_94 = false ;
if ( V_26 & V_319 )
if ( ! F_125 ( V_1 , 0 ) )
return false ;
if ( ( V_26 & V_366 ) == V_366 )
if ( ! F_125 ( V_1 , 1 ) )
return false ;
if ( V_26 & V_253 )
if ( ! F_128 ( V_1 , V_253 ) )
return false ;
if ( V_26 & V_254 )
if ( ! F_128 ( V_1 , V_254 ) )
return false ;
if ( V_26 & V_321 )
if ( ! F_131 ( V_1 , 0 ) )
return false ;
if ( ( V_26 & V_367 ) == V_367 )
if ( ! F_131 ( V_1 , 1 ) )
return false ;
if ( V_26 & V_317 )
if ( ! F_132 ( V_1 , 0 ) )
return false ;
if ( ( V_26 & V_258 ) == V_258 )
if ( ! F_132 ( V_1 , 1 ) )
return false ;
if ( ( V_26 & V_368 ) == 0 ) {
unsigned char V_369 [ 2 ] ;
V_1 -> V_315 = 0 ;
memcpy ( V_369 , & V_1 -> V_215 . V_228 , 2 ) ;
F_12 ( L_31 ,
F_14 ( V_1 ) ,
V_369 [ 0 ] , V_369 [ 1 ] ) ;
return false ;
}
V_1 -> V_4 . V_370 = ( 1 << 0 ) | ( 1 << 1 ) | ( 1 << 2 ) ;
return true ;
}
static bool F_129 ( struct V_1 * V_1 ,
struct V_7 * V_7 ,
int type )
{
struct V_9 * V_10 = V_1 -> V_4 . V_4 . V_10 ;
struct V_158 V_159 ;
T_7 V_160 , V_16 ;
if ( ! F_30 ( V_1 , type ) )
return false ;
F_26 ( sizeof( V_159 ) != 6 ) ;
if ( ! F_23 ( V_1 ,
V_371 ,
& V_159 , sizeof( V_159 ) ) )
return false ;
memcpy ( & V_160 , & V_159 , V_81 ( sizeof( V_160 ) , sizeof( V_159 ) ) ) ;
if ( V_160 == 0 )
return false ;
V_7 -> V_372 = 0 ;
for ( V_16 = 0 ; V_16 < V_297 ; V_16 ++ )
if ( V_160 & ( 1 << V_16 ) )
V_7 -> V_299 [ V_7 -> V_372 ++ ] = V_16 ;
V_7 -> V_288 =
F_134 ( V_10 , V_373 ,
L_32 , V_7 -> V_372 ) ;
if ( ! V_7 -> V_288 )
return false ;
for ( V_16 = 0 ; V_16 < V_7 -> V_372 ; V_16 ++ )
F_135 (
V_7 -> V_288 , V_16 ,
V_16 , V_374 [ V_7 -> V_299 [ V_16 ] ] ) ;
V_1 -> V_161 = V_7 -> V_299 [ 0 ] ;
F_136 ( & V_7 -> V_4 . V_4 ,
V_7 -> V_288 , 0 ) ;
return true ;
}
static bool
F_137 ( struct V_1 * V_1 ,
struct V_7 * V_7 ,
struct V_375 V_376 )
{
struct V_9 * V_10 = V_1 -> V_4 . V_4 . V_10 ;
struct V_5 * V_6 = & V_7 -> V_4 . V_4 ;
T_4 V_40 , V_377 [ 2 ] ;
if ( V_376 . V_378 ) {
if ( ! F_23 ( V_1 ,
V_379 ,
& V_377 , 4 ) )
return false ;
if ( ! F_23 ( V_1 ,
V_380 ,
& V_40 , 2 ) )
return false ;
V_7 -> V_302 = V_377 [ 0 ] ;
V_7 -> V_300 = V_377 [ 0 ] - V_40 ;
V_7 -> V_301 = V_7 -> V_300 ;
V_7 -> V_271 =
F_134 ( V_10 , V_381 ,
L_33 , 2 ) ;
if ( ! V_7 -> V_271 )
return false ;
V_7 -> V_271 -> V_382 [ 0 ] = 0 ;
V_7 -> V_271 -> V_382 [ 1 ] = V_377 [ 0 ] ;
F_136 ( V_6 ,
V_7 -> V_271 ,
V_7 -> V_300 ) ;
V_7 -> V_272 =
F_134 ( V_10 , V_381 ,
L_34 , 2 ) ;
if ( ! V_7 -> V_272 )
return false ;
V_7 -> V_272 -> V_382 [ 0 ] = 0 ;
V_7 -> V_272 -> V_382 [ 1 ] = V_377 [ 0 ] ;
F_136 ( V_6 ,
V_7 -> V_272 ,
V_7 -> V_301 ) ;
F_12 ( L_35
L_36 ,
V_377 [ 0 ] , V_377 [ 1 ] , V_40 ) ;
}
if ( V_376 . V_383 ) {
if ( ! F_23 ( V_1 ,
V_384 ,
& V_377 , 4 ) )
return false ;
if ( ! F_23 ( V_1 ,
V_385 ,
& V_40 , 2 ) )
return false ;
V_7 -> V_307 = V_377 [ 0 ] ;
V_7 -> V_305 = V_377 [ 0 ] - V_40 ;
V_7 -> V_306 = V_7 -> V_305 ;
V_7 -> V_273 =
F_134 ( V_10 , V_381 ,
L_37 , 2 ) ;
if ( ! V_7 -> V_273 )
return false ;
V_7 -> V_273 -> V_382 [ 0 ] = 0 ;
V_7 -> V_273 -> V_382 [ 1 ] = V_377 [ 0 ] ;
F_136 ( V_6 ,
V_7 -> V_273 ,
V_7 -> V_305 ) ;
V_7 -> V_274 =
F_134 ( V_10 , V_381 ,
L_38 , 2 ) ;
if ( ! V_7 -> V_274 )
return false ;
V_7 -> V_274 -> V_382 [ 0 ] = 0 ;
V_7 -> V_274 -> V_382 [ 1 ] = V_377 [ 0 ] ;
F_136 ( V_6 ,
V_7 -> V_274 ,
V_7 -> V_306 ) ;
F_12 ( L_39
L_36 ,
V_377 [ 0 ] , V_377 [ 1 ] , V_40 ) ;
}
F_138 ( V_275 , V_386 ) ;
F_138 ( V_276 , V_387 ) ;
F_138 ( V_277 , V_388 ) ;
F_138 ( V_278 , V_389 ) ;
F_138 ( V_279 , V_390 ) ;
F_138 ( V_280 , V_391 ) ;
F_138 ( V_287 , V_392 ) ;
F_138 ( V_281 , V_393 ) ;
F_138 ( V_283 , V_394 ) ;
F_138 ( V_282 , V_395 ) ;
F_138 ( V_285 , V_396 ) ;
F_138 ( V_284 , V_397 ) ;
if ( V_376 . V_286 ) {
if ( ! F_23 ( V_1 , V_398 , & V_40 , 2 ) )
return false ;
V_7 -> V_399 = 1 ;
V_7 -> V_400 = V_40 & 0x1 ;
V_7 -> V_286 =
F_134 ( V_10 , V_381 , L_40 , 2 ) ;
if ( ! V_7 -> V_286 )
return false ;
V_7 -> V_286 -> V_382 [ 0 ] = 0 ;
V_7 -> V_286 -> V_382 [ 1 ] = 1 ;
F_136 ( V_6 ,
V_7 -> V_286 ,
V_7 -> V_400 ) ;
F_12 ( L_41 , V_40 ) ;
}
return true ;
}
static bool
F_139 ( struct V_1 * V_1 ,
struct V_7 * V_7 ,
struct V_375 V_376 )
{
struct V_9 * V_10 = V_1 -> V_4 . V_4 . V_10 ;
struct V_5 * V_6 = & V_7 -> V_4 . V_4 ;
T_4 V_40 , V_377 [ 2 ] ;
F_138 ( V_287 , V_392 ) ;
return true ;
}
static bool F_130 ( struct V_1 * V_1 ,
struct V_7 * V_7 )
{
union {
struct V_375 V_261 ;
T_4 V_40 ;
} V_376 ;
F_26 ( sizeof( V_376 ) != 2 ) ;
V_376 . V_40 = 0 ;
F_23 ( V_1 ,
V_401 ,
& V_376 , sizeof( V_376 ) ) ;
if ( V_376 . V_40 == 0 ) {
F_12 ( L_42 ) ;
return true ;
}
if ( F_91 ( V_7 ) )
return F_137 ( V_1 , V_7 , V_376 . V_261 ) ;
else if ( F_92 ( V_7 ) )
return F_139 ( V_1 , V_7 , V_376 . V_261 ) ;
else
return true ;
}
static int F_140 ( struct V_402 * V_238 ,
struct V_23 * V_24 ,
int V_403 )
{
struct V_1 * V_234 = V_238 -> V_404 ;
if ( ! F_21 ( V_234 , V_234 -> V_51 ) )
return - V_309 ;
return V_234 -> V_31 -> V_405 -> V_406 ( V_234 -> V_31 , V_24 , V_403 ) ;
}
static T_1 F_141 ( struct V_402 * V_238 )
{
struct V_1 * V_234 = V_238 -> V_404 ;
return V_234 -> V_31 -> V_405 -> V_407 ( V_234 -> V_31 ) ;
}
static bool
F_142 ( struct V_1 * V_234 ,
struct V_9 * V_10 )
{
V_234 -> V_235 . V_408 = V_409 ;
V_234 -> V_235 . V_410 = V_411 ;
snprintf ( V_234 -> V_235 . V_35 , V_412 , L_43 ) ;
V_234 -> V_235 . V_10 . V_413 = & V_10 -> V_414 -> V_10 ;
V_234 -> V_235 . V_404 = V_234 ;
V_234 -> V_235 . V_405 = & V_415 ;
return F_143 ( & V_234 -> V_235 ) == 0 ;
}
bool F_144 ( struct V_9 * V_10 , int V_17 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_230 * V_230 ;
struct V_1 * V_1 ;
int V_16 ;
V_1 = F_127 ( sizeof( struct V_1 ) , V_344 ) ;
if ( ! V_1 )
return false ;
V_1 -> V_17 = V_17 ;
V_1 -> V_25 = F_115 ( V_10 , V_17 ) >> 1 ;
F_111 ( V_12 , V_1 , V_17 ) ;
if ( ! F_142 ( V_1 , V_10 ) ) {
F_74 ( V_1 ) ;
return false ;
}
V_230 = & V_1 -> V_4 ;
V_230 -> type = V_416 ;
F_145 ( V_10 , & V_230 -> V_4 , & V_417 , 0 ) ;
for ( V_16 = 0 ; V_16 < 0x40 ; V_16 ++ ) {
T_2 V_418 ;
if ( ! F_10 ( V_1 , V_16 , & V_418 ) ) {
F_12 ( L_44 ,
F_110 ( V_17 ) ? 'B' : 'C' ) ;
goto V_360;
}
}
if ( F_110 ( V_17 ) )
V_12 -> V_419 |= V_420 ;
else
V_12 -> V_419 |= V_421 ;
F_146 ( & V_230 -> V_4 , & V_422 ) ;
if ( ! F_63 ( V_1 , & V_1 -> V_215 ) )
goto V_360;
F_23 ( V_1 , V_423 ,
& V_1 -> V_232 , 2 ) ;
V_1 -> V_232 [ 0 ] &= ~ 0x3 ;
if ( F_133 ( V_1 ,
V_1 -> V_215 . V_228 ) != true ) {
F_12 ( L_45 ,
F_110 ( V_17 ) ? 'B' : 'C' ) ;
goto V_360;
}
F_109 ( V_12 , V_1 , V_17 ) ;
if ( ! F_24 ( V_1 ) )
goto V_360;
if ( ! F_29 ( V_1 ,
& V_1 -> V_208 ,
& V_1 -> V_210 ) )
goto V_360;
F_12 ( L_46
L_47
L_48
L_49 ,
F_14 ( V_1 ) ,
V_1 -> V_215 . V_217 , V_1 -> V_215 . V_218 ,
V_1 -> V_215 . V_219 ,
V_1 -> V_208 / 1000 ,
V_1 -> V_210 / 1000 ,
( V_1 -> V_215 . V_222 & 0x1 ) ? 'Y' : 'N' ,
( V_1 -> V_215 . V_222 & 0x2 ) ? 'Y' : 'N' ,
V_1 -> V_215 . V_228 &
( V_319 | V_321 ) ? 'Y' : 'N' ,
V_1 -> V_215 . V_228 &
( V_318 | V_320 ) ? 'Y' : 'N' ) ;
return true ;
V_360:
F_147 ( & V_230 -> V_4 ) ;
F_106 ( & V_1 -> V_235 ) ;
F_74 ( V_1 ) ;
return false ;
}
