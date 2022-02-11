static T_1 F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_5 = V_4 -> V_6 ;
struct V_7 * V_8 ;
V_8 = V_4 -> V_9 ;
if ( V_2 -> V_10 ) {
if ( ! F_3 ( V_2 -> V_10 ) )
V_5 = V_2 -> V_10 -> V_6 ;
else
V_5 = 0 ;
}
if ( V_8 -> V_11 && V_8 -> V_11 -> V_12 && V_8 -> V_11 -> V_12 -> V_13 )
V_5 = V_5 && V_8 -> V_11 -> V_12 -> V_13 ( V_8 ) ;
else
V_5 = 0 ;
return V_5 ;
}
static void F_4 ( struct V_1 * V_2 ,
struct V_14 * V_15 )
{
int V_16 , V_17 , V_18 , V_19 ;
struct V_20 * V_21 = V_2 -> V_10 ;
if ( ! V_21 || ! V_21 -> V_22 . V_23 ) {
V_15 -> V_24 . V_25 = V_26 ;
V_15 -> V_24 . V_27 = V_26 ;
return;
}
F_5 ( V_21 , V_28 , V_29 ) ;
V_18 = F_6 ( V_21 , V_30 ) ;
V_16 = F_7 ( V_18 , V_31 , V_32 ) ;
V_18 = F_6 ( V_21 , V_33 ) ;
V_17 = F_8 ( V_18 , V_34 ) ;
V_19 = F_8 ( V_18 , V_35 ) ;
F_5 ( V_21 , V_28 , V_36 ) ;
switch ( V_16 ) {
case 0x0 :
V_15 -> V_24 . V_25 = V_37 ;
break;
case 0x1 :
V_15 -> V_24 . V_25 = V_38 ;
break;
case 0x3 :
V_15 -> V_24 . V_25 = V_39 ;
break;
default:
V_15 -> V_24 . V_25 = V_26 ;
break;
}
if ( ! V_19 )
V_15 -> V_24 . V_27 = V_26 ;
else if ( V_17 )
V_15 -> V_24 . V_27 = V_38 ;
else
V_15 -> V_24 . V_27 = V_37 ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_14 * V_15 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_7 * V_8 ;
T_1 V_5 ;
int V_40 ;
T_2 V_41 ;
T_3 V_42 ;
T_1 V_43 , V_44 ;
if ( ! V_4 || ! V_4 -> V_9 )
return - V_45 ;
V_8 = V_4 -> V_9 ;
if ( ! V_8 -> V_11 || ! V_8 -> V_11 -> V_12 || ! V_8 -> V_11 -> V_12 -> V_46 )
return - V_45 ;
V_40 = V_8 -> V_11 -> V_12 -> V_46 ( V_8 , NULL , & V_42 , & V_41 ) ;
if ( V_40 < 0 ) {
F_10 ( V_2 , L_1 , V_47 ) ;
return - V_48 ;
}
F_11 ( & V_43 ,
V_15 -> V_49 . V_43 ) ;
F_11 ( & V_44 ,
V_15 -> V_49 . V_44 ) ;
V_15 -> V_24 . V_50 = false ;
V_15 -> V_24 . V_42 = V_42 ;
V_15 -> V_24 . V_41 = V_41 ;
if ( V_2 -> V_10 )
F_12 ( V_2 -> V_10 , V_15 ) ;
V_5 = F_1 ( V_2 ) ;
if ( ! V_5 ) {
V_15 -> V_24 . V_42 = ( T_1 ) V_51 ;
V_15 -> V_24 . V_41 = V_52 ;
}
if ( V_15 -> V_24 . V_50 )
V_44 |= V_53 ;
V_43 |= V_8 -> V_54 ;
if ( V_8 -> V_55 == V_56 ) {
V_43 |= V_57 ;
V_44 |= V_58 ;
} else if ( V_8 -> V_55 == V_59 ) {
V_43 |= V_60 ;
V_44 |= V_61 ;
}
switch ( V_8 -> V_62 ) {
case V_63 :
V_15 -> V_24 . V_64 = V_65 ;
break;
case V_66 :
V_15 -> V_24 . V_64 = V_67 ;
break;
case V_68 :
default:
break;
}
if ( ! ( F_13 ( V_4 -> V_69 ) && V_8 -> V_70 == V_71 ) )
V_43 |= V_72 ;
F_14 ( V_15 -> V_49 . V_43 ,
V_43 ) ;
F_14 ( V_15 -> V_49 . V_44 ,
V_44 ) ;
V_15 -> V_24 . V_73 = V_74 | V_75 ;
F_4 ( V_2 , V_15 ) ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 ,
const struct V_14 * V_15 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_7 * V_8 ;
T_1 V_42 ;
if ( ! F_16 ( V_2 ) )
return - V_45 ;
if ( ! V_4 || ! V_4 -> V_9 || ! V_4 -> V_9 -> V_11 ||
! V_4 -> V_9 -> V_11 -> V_12 )
return - V_76 ;
V_8 = V_4 -> V_9 ;
V_42 = V_15 -> V_24 . V_42 ;
if ( V_8 -> V_55 == V_59 ) {
if ( V_15 -> V_24 . V_50 == V_77 ||
V_42 != V_78 ||
V_15 -> V_24 . V_41 != V_79 )
return - V_48 ;
} else if ( V_8 -> V_55 == V_56 ) {
if ( ! V_2 -> V_10 && V_15 -> V_24 . V_50 == V_77 )
return - V_48 ;
if ( V_42 == V_80 && V_15 -> V_24 . V_41 == V_81 )
return - V_48 ;
if ( V_2 -> V_10 )
return F_17 ( V_2 -> V_10 , V_15 ) ;
if ( ( V_42 != V_82 && V_42 != V_83 &&
V_42 != V_80 ) || ( V_15 -> V_24 . V_41 != V_81 &&
V_15 -> V_24 . V_41 != V_79 ) )
return - V_48 ;
} else {
F_10 ( V_2 , L_2 ) ;
return - V_84 ;
}
if ( V_8 -> V_11 -> V_12 -> V_85 ) {
V_8 -> V_11 -> V_12 -> V_85 ( V_8 , ( int ) V_42 , V_15 -> V_24 . V_41 ) ;
return 0 ;
}
F_10 ( V_2 , L_2 ) ;
return - V_84 ;
}
static int F_18 ( struct V_20 * V_21 , T_2 V_86 )
{
int V_87 ;
if ( V_86 ) {
V_87 = F_19 ( V_21 ) ;
if ( V_87 )
goto V_88;
V_87 = F_20 ( V_21 , true ) ;
} else {
V_87 = F_20 ( V_21 , false ) ;
if ( V_87 )
goto V_88;
V_87 = F_21 ( V_21 ) ;
}
V_88:
return V_87 ;
}
static int F_22 ( struct V_1 * V_89 ,
enum V_90 V_91 )
{
int V_40 = 0 ;
struct V_3 * V_4 = F_2 ( V_89 ) ;
struct V_20 * V_21 = V_89 -> V_10 ;
struct V_7 * V_8 = V_4 -> V_9 ;
switch ( V_91 ) {
case V_92 :
V_40 = F_18 ( V_21 , 0x1 ) ;
if ( ! V_40 )
V_40 = V_8 -> V_11 -> V_12 -> V_93 ( V_8 , V_91 , 0x1 ) ;
break;
case V_94 :
if ( ( V_8 -> V_11 -> V_12 -> V_93 ) &&
( V_4 -> V_9 -> V_55 != V_59 ) )
V_40 = V_8 -> V_11 -> V_12 -> V_93 ( V_8 , V_91 , 0x1 ) ;
break;
case V_95 :
if ( V_8 -> V_11 -> V_12 -> V_93 )
V_40 = V_8 -> V_11 -> V_12 -> V_93 ( V_8 , V_91 , 0x1 ) ;
break;
case V_96 :
V_40 = F_18 ( V_21 , 0x0 ) ;
case V_97 :
if ( ! V_40 && V_8 -> V_11 -> V_12 -> V_93 ) {
if ( V_4 -> V_9 -> V_55 != V_59 )
V_40 = V_8 -> V_11 -> V_12 -> V_93 ( V_8 ,
V_94 , 0x0 ) ;
if ( ! V_40 )
V_40 = V_8 -> V_11 -> V_12 -> V_93 ( V_8 ,
V_95 , 0x0 ) ;
}
break;
default:
V_40 = - V_48 ;
break;
}
if ( ! V_40 ) {
if ( V_91 == V_97 )
V_8 -> V_11 -> V_12 -> V_98 (
V_8 , V_89 -> V_99 & V_100 ) ;
else
V_8 -> V_11 -> V_12 -> V_98 ( V_8 , 1 ) ;
}
return V_40 ;
}
static int F_23 ( struct V_1 * V_89 ,
enum V_90 V_101 )
{
struct V_3 * V_4 = F_2 ( V_89 ) ;
struct V_7 * V_8 = V_4 -> V_9 ;
int V_42 , V_41 ;
int V_40 ;
F_24 ( V_89 ) ;
V_40 = F_22 ( V_89 , V_101 ) ;
if ( V_40 )
return V_40 ;
F_25 ( 200 ) ;
V_40 = V_8 -> V_11 -> V_12 -> V_102 ? V_8 -> V_11 -> V_12 -> V_102 ( V_8 ) : 0 ;
if ( V_40 )
return V_40 ;
if ( V_4 -> V_9 -> V_55 != V_59 )
V_42 = 1000 ;
else
V_42 = 10000 ;
V_41 = 1 ;
V_8 -> V_11 -> V_12 -> V_85 ( V_8 , V_42 , V_41 ) ;
return 0 ;
}
static void F_26 ( struct V_103 * V_104 ,
struct V_105 * V_106 )
{
struct V_1 * V_89 ;
struct V_3 * V_4 ;
struct V_107 * V_108 ;
struct V_109 * V_110 ;
struct V_105 * V_111 ;
unsigned int V_112 ;
int V_113 ;
T_1 V_114 ;
char V_115 [ 33 ] ;
if ( ! V_104 ) {
V_89 = V_106 -> V_11 ;
V_4 = F_2 ( V_89 ) ;
V_112 = V_106 -> V_116 ;
memset ( V_106 -> V_117 , 0xFF , V_112 ) ;
if ( ( ! F_13 ( V_4 -> V_69 ) ) &&
( V_4 -> V_9 -> V_70 == V_118 ) ) {
memcpy ( V_106 -> V_117 , V_89 -> V_119 , 6 ) ;
V_106 -> V_117 [ 5 ] += 0x1f ;
}
V_112 &= ~ 1ul ;
memset ( & V_106 -> V_117 [ V_112 / 2 ] , 0xAA , V_112 / 2 - 1 ) ;
memset ( & V_106 -> V_117 [ V_112 / 2 + 10 ] , 0xBE ,
V_112 / 2 - 11 ) ;
memset ( & V_106 -> V_117 [ V_112 / 2 + 12 ] , 0xAF ,
V_112 / 2 - 13 ) ;
return;
}
V_108 = V_104 -> V_108 ;
V_89 = V_104 -> V_120 . V_11 ;
if ( F_27 ( V_108 ) ) {
V_110 = F_28 ( V_89 , V_104 -> V_121 ) ;
F_29 ( V_110 ) ;
return;
}
V_112 = V_106 -> V_116 ;
V_112 &= ~ 1ul ;
V_111 = F_30 ( V_106 , V_122 ) ;
F_31 ( V_106 ) ;
V_106 = V_111 ;
V_113 = 0 ;
if ( * ( V_106 -> V_117 + 10 ) == 0xFF ) {
if ( ( * ( V_106 -> V_117 + V_112 / 2 + 10 ) == 0xBE ) &&
( * ( V_106 -> V_117 + V_112 / 2 + 12 ) == 0xAF ) )
V_113 = 1 ;
}
if ( V_113 ) {
V_89 -> V_123 . V_124 ++ ;
V_89 -> V_123 . V_125 += V_106 -> V_116 ;
} else {
V_89 -> V_123 . V_126 ++ ;
for ( V_114 = 0 ; V_114 < V_106 -> V_116 ; V_114 ++ ) {
snprintf ( V_115 + V_114 % 16 * 2 , 3 ,
L_3 , * ( V_106 -> V_117 + V_114 ) ) ;
if ( ( V_114 % 16 == 15 ) || ( V_114 == V_106 -> V_116 - 1 ) )
F_32 ( L_4 , V_115 ) ;
}
}
F_31 ( V_106 ) ;
}
static int F_33 ( struct V_3 * V_4 ,
int V_127 , int V_128 , int V_129 )
{
int V_114 , V_40 ;
struct V_103 * V_104 ;
struct V_1 * V_89 = V_4 -> V_130 ;
unsigned long V_124 = V_89 -> V_123 . V_124 ;
unsigned long V_125 = V_89 -> V_123 . V_125 ;
unsigned long V_126 = V_89 -> V_123 . V_126 ;
for ( V_114 = V_127 ; V_114 <= V_128 ; V_114 ++ ) {
V_104 = & V_4 -> V_104 [ V_114 ] ;
( void ) V_104 -> V_131 ( V_104 ,
V_129 , F_26 ) ;
}
V_40 = ( int ) ( V_89 -> V_123 . V_124 - V_124 ) ;
V_89 -> V_123 . V_124 = V_124 ;
V_89 -> V_123 . V_125 = V_125 ;
V_89 -> V_123 . V_126 = V_126 ;
return V_40 ;
}
static int F_34 ( struct V_1 * V_89 ,
enum V_90 V_101 )
{
#define F_35 1
#define F_36 0
#define F_37 128
#define F_38 1
#define F_39 2
#define F_40 3
#define F_41 4
struct V_3 * V_4 = F_2 ( V_89 ) ;
struct V_7 * V_8 = V_4 -> V_9 ;
int V_114 , V_132 , V_133 , V_134 , V_135 = 0 ;
unsigned int V_136 ;
T_4 V_137 ;
struct V_105 * V_106 ;
V_136 = F_37 ;
V_106 = F_42 ( V_136 , V_138 ) ;
if ( ! V_106 )
return F_38 ;
( void ) F_43 ( V_106 , V_136 ) ;
V_106 -> V_11 = V_89 ;
F_26 ( NULL , V_106 ) ;
V_106 -> V_139 = F_36 ;
V_133 = 1 ;
for ( V_132 = 0 ; V_132 < V_133 ; V_132 ++ ) {
V_134 = 0 ;
for ( V_114 = 0 ; V_114 < F_35 ; V_114 ++ ) {
( void ) F_44 ( V_106 ) ;
V_137 = ( T_4 ) F_45 (
V_89 , V_106 ,
& F_46 ( V_4 , V_106 -> V_139 ) ) ;
if ( V_137 == V_140 )
V_134 ++ ;
else
break;
}
if ( V_134 != F_35 ) {
V_135 = F_39 ;
F_47 ( V_4 -> V_11 , L_5 ,
V_141 [ V_101 ] , V_134 ,
F_35 ) ;
break;
}
F_25 ( 100 ) ;
V_134 = F_33 ( V_4 ,
V_8 -> V_142 , V_8 -> V_142 * 2 - 1 ,
F_35 ) ;
if ( V_134 != F_35 ) {
V_135 = F_40 ;
F_47 ( V_4 -> V_11 , L_6 ,
V_141 [ V_101 ] , V_134 ,
F_35 ) ;
break;
}
( void ) F_33 ( V_4 ,
F_36 , F_36 ,
F_35 ) ;
}
F_48 ( V_106 ) ;
return V_135 ;
}
static int F_49 ( struct V_1 * V_89 , enum V_90 V_91 )
{
struct V_3 * V_4 = F_2 ( V_89 ) ;
struct V_7 * V_8 = V_4 -> V_9 ;
int V_40 ;
if ( V_91 == V_92 )
V_40 = F_22 ( V_89 , V_96 ) ;
else
V_40 = F_22 ( V_89 , V_97 ) ;
if ( V_40 )
F_10 ( V_89 , L_7 ,
V_47 ,
V_40 ) ;
if ( V_8 -> V_11 -> V_12 -> V_143 )
V_8 -> V_11 -> V_12 -> V_143 ( V_8 ) ;
F_50 ( 10000 , 20000 ) ;
( void ) F_33 ( V_4 , 0 , V_8 -> V_142 - 1 , 256 ) ;
F_24 ( V_89 ) ;
return 0 ;
}
static void F_51 ( struct V_1 * V_89 ,
struct V_144 * V_145 , T_5 * V_117 )
{
struct V_3 * V_4 = F_2 ( V_89 ) ;
bool V_146 = F_16 ( V_89 ) ;
#define F_52 3
int V_147 [ F_52 ] [ 2 ] ;
int V_114 ;
int V_148 = 0 ;
V_147 [ 0 ] [ 0 ] = V_94 ;
V_147 [ 0 ] [ 1 ] = ( V_4 -> V_9 -> V_55 != V_59 ) ;
V_147 [ 1 ] [ 0 ] = V_95 ;
V_147 [ 1 ] [ 1 ] = 1 ;
V_147 [ 2 ] [ 0 ] = V_92 ;
V_147 [ 2 ] [ 1 ] = ( ( ! ! ( V_4 -> V_9 -> V_21 ) ) &&
( V_4 -> V_9 -> V_55 != V_59 ) ) ;
if ( V_145 -> V_99 == V_149 ) {
F_53 ( V_150 , & V_4 -> V_151 ) ;
if ( V_146 )
( void ) F_54 ( V_89 ) ;
for ( V_114 = 0 ; V_114 < F_52 ; V_114 ++ ) {
if ( ! V_147 [ V_114 ] [ 1 ] )
continue;
V_117 [ V_148 ] = F_23 ( V_89 ,
(enum V_90 ) V_147 [ V_114 ] [ 0 ] ) ;
if ( ! V_117 [ V_148 ] ) {
V_117 [ V_148 ] = F_34 (
V_89 , (enum V_90 ) V_147 [ V_114 ] [ 0 ] ) ;
( void ) F_49 ( V_89 ,
(enum V_90 ) V_147 [ V_114 ] [ 0 ] ) ;
}
if ( V_117 [ V_148 ] )
V_145 -> V_99 |= V_152 ;
V_148 ++ ;
}
F_24 ( V_4 -> V_130 ) ;
F_55 ( V_150 , & V_4 -> V_151 ) ;
if ( V_146 )
( void ) F_56 ( V_89 ) ;
}
( void ) F_57 ( 4 * 1000 ) ;
}
static void F_58 ( struct V_1 * V_2 ,
struct V_153 * V_154 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
strncpy ( V_154 -> V_155 , V_156 ,
sizeof( V_154 -> V_155 ) ) ;
V_154 -> V_155 [ sizeof( V_154 -> V_155 ) - 1 ] = '\0' ;
strncpy ( V_154 -> V_157 , V_158 , sizeof( V_154 -> V_157 ) ) ;
V_154 -> V_157 [ sizeof( V_154 -> V_157 ) - 1 ] = '\0' ;
strncpy ( V_154 -> V_159 , V_4 -> V_11 -> V_23 -> V_160 ,
sizeof( V_154 -> V_159 ) ) ;
V_154 -> V_159 [ V_161 - 1 ] = '\0' ;
strncpy ( V_154 -> V_162 , L_8 , V_163 ) ;
V_154 -> V_164 = 0 ;
}
void F_59 ( struct V_1 * V_2 ,
struct V_165 * V_166 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_167 * V_12 ;
struct V_168 * V_169 ;
T_1 V_170 = 0 ;
V_169 = V_4 -> V_9 -> V_171 [ 0 ] ;
V_12 = V_4 -> V_9 -> V_11 -> V_12 ;
if ( V_12 -> V_172 )
V_12 -> V_172 ( V_169 , & V_170 ) ;
V_166 -> V_173 = V_170 ;
V_166 -> V_174 = V_170 ;
V_166 -> V_175 = V_169 -> V_176 . V_177 ;
V_166 -> V_178 = V_169 -> V_179 . V_177 ;
}
static void F_60 ( struct V_1 * V_2 ,
struct V_180 * V_166 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_167 * V_12 ;
V_12 = V_4 -> V_9 -> V_11 -> V_12 ;
if ( V_12 -> V_181 )
V_12 -> V_181 ( V_4 -> V_9 , & V_166 -> V_50 ,
& V_166 -> V_182 , & V_166 -> V_183 ) ;
}
static int F_61 ( struct V_1 * V_2 ,
struct V_180 * V_166 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_7 * V_8 ;
struct V_167 * V_12 ;
V_8 = V_4 -> V_9 ;
V_12 = V_8 -> V_11 -> V_12 ;
if ( ! V_12 -> V_184 )
return - V_45 ;
return V_12 -> V_184 ( V_4 -> V_9 , V_166 -> V_50 ,
V_166 -> V_182 , V_166 -> V_183 ) ;
}
static int F_62 ( struct V_1 * V_2 ,
struct V_185 * V_186 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_167 * V_12 ;
V_12 = V_4 -> V_9 -> V_11 -> V_12 ;
V_186 -> V_187 = 1 ;
V_186 -> V_188 = 1 ;
if ( ( ! V_12 -> V_189 ) ||
( ! V_12 -> V_190 ) )
return - V_45 ;
V_12 -> V_189 ( V_4 -> V_9 ,
& V_186 -> V_191 ,
& V_186 -> V_192 ) ;
V_12 -> V_190 (
V_4 -> V_9 ,
& V_186 -> V_193 ,
& V_186 -> V_194 ) ;
V_12 -> V_195 ( V_4 -> V_9 ,
& V_186 -> V_196 ,
& V_186 -> V_197 ,
& V_186 -> V_198 ,
& V_186 -> V_199 ,
& V_186 -> V_200 ,
& V_186 -> V_201 ,
& V_186 -> V_202 ,
& V_186 -> V_203 ) ;
return 0 ;
}
static int F_63 ( struct V_1 * V_2 ,
struct V_185 * V_186 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_167 * V_12 ;
int V_204 , V_205 ;
V_12 = V_4 -> V_9 -> V_11 -> V_12 ;
if ( V_186 -> V_191 != V_186 -> V_192 )
return - V_48 ;
if ( ( ! V_12 -> V_206 ) ||
( ! V_12 -> V_207 ) )
return - V_45 ;
V_204 = V_12 -> V_206 ( V_4 -> V_9 ,
V_186 -> V_192 ) ;
V_205 = V_12 -> V_207 ( V_4 -> V_9 ,
V_186 -> V_193 ,
V_186 -> V_194 ) ;
if ( V_204 || V_205 )
return - V_48 ;
return 0 ;
}
void F_64 ( struct V_1 * V_2 , struct V_208 * V_209 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_209 -> V_210 = V_4 -> V_9 -> V_142 ;
V_209 -> V_211 = V_4 -> V_9 -> V_142 ;
V_209 -> V_212 = V_4 -> V_9 -> V_142 ;
V_209 -> V_213 = V_4 -> V_9 -> V_142 ;
}
void F_65 ( struct V_1 * V_130 ,
struct V_214 * V_123 , T_5 * V_117 )
{
T_5 * V_215 = V_117 ;
struct V_3 * V_4 = F_2 ( V_130 ) ;
struct V_7 * V_8 = V_4 -> V_9 ;
const struct V_216 * V_217 ;
struct V_216 V_218 ;
if ( ! V_8 -> V_11 -> V_12 -> V_219 || ! V_8 -> V_11 -> V_12 -> V_220 ) {
F_10 ( V_130 , L_9 ) ;
return;
}
V_8 -> V_11 -> V_12 -> V_220 ( V_8 , & V_130 -> V_123 ) ;
V_217 = F_66 ( V_130 , & V_218 ) ;
V_215 [ 0 ] = V_217 -> V_124 ;
V_215 [ 1 ] = V_217 -> V_221 ;
V_215 [ 2 ] = V_217 -> V_125 ;
V_215 [ 3 ] = V_217 -> V_222 ;
V_215 [ 4 ] = V_217 -> V_223 ;
V_215 [ 5 ] = V_217 -> V_224 ;
V_215 [ 6 ] = V_217 -> V_225 ;
V_215 [ 7 ] = V_217 -> V_226 ;
V_215 [ 8 ] = V_217 -> V_227 ;
V_215 [ 9 ] = V_217 -> V_228 ;
V_215 [ 10 ] = V_217 -> V_229 ;
V_215 [ 11 ] = V_217 -> V_230 ;
V_215 [ 12 ] = V_217 -> V_126 ;
V_215 [ 13 ] = V_217 -> V_231 ;
V_215 [ 14 ] = V_217 -> V_232 ;
V_215 [ 15 ] = V_217 -> V_233 ;
V_215 [ 16 ] = V_217 -> V_234 ;
V_215 [ 17 ] = V_217 -> V_235 ;
V_215 [ 18 ] = V_217 -> V_236 ;
V_215 [ 19 ] = V_217 -> V_237 ;
V_215 [ 20 ] = V_217 -> V_238 ;
V_215 [ 21 ] = V_217 -> V_239 ;
V_215 [ 22 ] = V_217 -> V_240 ;
V_215 [ 23 ] = V_130 -> V_225 . V_241 ;
V_215 [ 24 ] = V_130 -> V_226 . V_241 ;
V_215 [ 25 ] = V_4 -> V_242 ;
V_8 -> V_11 -> V_12 -> V_219 ( V_8 , & V_215 [ 26 ] ) ;
}
void F_67 ( struct V_1 * V_130 , T_1 V_243 , T_2 * V_117 )
{
struct V_3 * V_4 = F_2 ( V_130 ) ;
struct V_7 * V_8 = V_4 -> V_9 ;
char * V_115 = ( char * ) V_117 ;
if ( ! V_8 -> V_11 -> V_12 -> V_244 ) {
F_10 ( V_130 , L_10 ) ;
return;
}
if ( V_243 == V_245 ) {
if ( V_4 -> V_9 -> V_55 != V_59 ) {
memcpy ( V_115 , V_141 [ V_94 ] ,
V_246 ) ;
V_115 += V_246 ;
}
memcpy ( V_115 , V_141 [ V_95 ] ,
V_246 ) ;
V_115 += V_246 ;
if ( ( V_130 -> V_10 ) && ( ! V_130 -> V_10 -> V_247 ) )
memcpy ( V_115 , V_141 [ V_92 ] ,
V_246 ) ;
} else {
snprintf ( V_115 , V_246 , L_11 ) ;
V_115 = V_115 + V_246 ;
snprintf ( V_115 , V_246 , L_12 ) ;
V_115 = V_115 + V_246 ;
snprintf ( V_115 , V_246 , L_13 ) ;
V_115 = V_115 + V_246 ;
snprintf ( V_115 , V_246 , L_14 ) ;
V_115 = V_115 + V_246 ;
snprintf ( V_115 , V_246 , L_15 ) ;
V_115 = V_115 + V_246 ;
snprintf ( V_115 , V_246 , L_16 ) ;
V_115 = V_115 + V_246 ;
snprintf ( V_115 , V_246 , L_17 ) ;
V_115 = V_115 + V_246 ;
snprintf ( V_115 , V_246 , L_18 ) ;
V_115 = V_115 + V_246 ;
snprintf ( V_115 , V_246 , L_19 ) ;
V_115 = V_115 + V_246 ;
snprintf ( V_115 , V_246 , L_20 ) ;
V_115 = V_115 + V_246 ;
snprintf ( V_115 , V_246 , L_21 ) ;
V_115 = V_115 + V_246 ;
snprintf ( V_115 , V_246 , L_22 ) ;
V_115 = V_115 + V_246 ;
snprintf ( V_115 , V_246 , L_23 ) ;
V_115 = V_115 + V_246 ;
snprintf ( V_115 , V_246 , L_24 ) ;
V_115 = V_115 + V_246 ;
snprintf ( V_115 , V_246 , L_25 ) ;
V_115 = V_115 + V_246 ;
snprintf ( V_115 , V_246 , L_26 ) ;
V_115 = V_115 + V_246 ;
snprintf ( V_115 , V_246 , L_27 ) ;
V_115 = V_115 + V_246 ;
snprintf ( V_115 , V_246 , L_28 ) ;
V_115 = V_115 + V_246 ;
snprintf ( V_115 , V_246 , L_29 ) ;
V_115 = V_115 + V_246 ;
snprintf ( V_115 , V_246 , L_30 ) ;
V_115 = V_115 + V_246 ;
snprintf ( V_115 , V_246 , L_31 ) ;
V_115 = V_115 + V_246 ;
snprintf ( V_115 , V_246 , L_32 ) ;
V_115 = V_115 + V_246 ;
snprintf ( V_115 , V_246 , L_33 ) ;
V_115 = V_115 + V_246 ;
snprintf ( V_115 , V_246 , L_34 ) ;
V_115 = V_115 + V_246 ;
snprintf ( V_115 , V_246 , L_35 ) ;
V_115 = V_115 + V_246 ;
snprintf ( V_115 , V_246 , L_36 ) ;
V_115 = V_115 + V_246 ;
V_8 -> V_11 -> V_12 -> V_244 ( V_8 , V_243 , ( T_2 * ) V_115 ) ;
}
}
int F_68 ( struct V_1 * V_130 , int V_243 )
{
struct V_3 * V_4 = F_2 ( V_130 ) ;
struct V_7 * V_8 = V_4 -> V_9 ;
struct V_167 * V_12 = V_8 -> V_11 -> V_12 ;
if ( ! V_12 -> V_248 ) {
F_10 ( V_130 , L_37 ) ;
return - V_249 ;
}
if ( V_243 == V_245 ) {
T_1 V_250 = ( sizeof( V_141 ) / V_246 ) ;
if ( V_4 -> V_9 -> V_55 == V_59 )
V_250 -- ;
if ( ( ! V_130 -> V_10 ) || ( V_130 -> V_10 -> V_247 ) )
V_250 -- ;
return V_250 ;
} else {
return ( V_251 + V_12 -> V_248 ( V_8 , V_243 ) ) ;
}
}
int F_69 ( struct V_1 * V_130 , int V_252 )
{
int V_18 ;
struct V_20 * V_21 = V_130 -> V_10 ;
V_18 = F_5 ( V_21 , V_28 , V_253 ) ;
V_18 |= F_5 ( V_21 , V_254 , V_252 ) ;
V_18 |= F_5 ( V_21 , V_28 , V_36 ) ;
if ( V_18 ) {
F_10 ( V_130 , L_38 ) ;
return V_18 ;
}
return 0 ;
}
int F_70 ( struct V_1 * V_130 , enum V_255 V_151 )
{
struct V_3 * V_4 = F_2 ( V_130 ) ;
struct V_7 * V_8 = V_4 -> V_9 ;
struct V_20 * V_21 = V_130 -> V_10 ;
int V_40 ;
if ( V_21 )
switch ( V_151 ) {
case V_256 :
V_40 = F_5 ( V_21 , V_28 ,
V_253 ) ;
if ( V_40 )
return V_40 ;
V_4 -> V_257 = F_6 ( V_21 , V_254 ) ;
V_40 = F_5 ( V_21 , V_28 ,
V_36 ) ;
if ( V_40 )
return V_40 ;
return 2 ;
case V_258 :
V_40 = F_69 ( V_130 , V_259 ) ;
if ( V_40 )
return V_40 ;
break;
case V_260 :
V_40 = F_69 ( V_130 , V_261 ) ;
if ( V_40 )
return V_40 ;
break;
case V_262 :
V_40 = F_5 ( V_21 , V_28 ,
V_253 ) ;
if ( V_40 )
return V_40 ;
V_40 = F_5 ( V_21 , V_254 ,
V_4 -> V_257 ) ;
if ( V_40 )
return V_40 ;
V_40 = F_5 ( V_21 , V_28 ,
V_36 ) ;
if ( V_40 )
return V_40 ;
break;
default:
return - V_48 ;
}
else
switch ( V_151 ) {
case V_256 :
return V_8 -> V_11 -> V_12 -> V_263 ( V_8 , V_264 ) ;
case V_258 :
return V_8 -> V_11 -> V_12 -> V_263 ( V_8 , V_265 ) ;
case V_260 :
return V_8 -> V_11 -> V_12 -> V_263 ( V_8 , V_266 ) ;
case V_262 :
return V_8 -> V_11 -> V_12 -> V_263 ( V_8 , V_267 ) ;
default:
return - V_48 ;
}
return 0 ;
}
void F_71 ( struct V_1 * V_2 , struct V_268 * V_15 ,
void * V_117 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_167 * V_12 ;
V_12 = V_4 -> V_9 -> V_11 -> V_12 ;
V_15 -> V_155 = V_269 ;
if ( ! V_12 -> V_270 ) {
F_10 ( V_2 , L_39 ) ;
return;
}
V_12 -> V_270 ( V_4 -> V_9 , V_117 ) ;
}
static int F_72 ( struct V_1 * V_2 )
{
T_1 V_271 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_167 * V_12 ;
V_12 = V_4 -> V_9 -> V_11 -> V_12 ;
if ( ! V_12 -> V_272 ) {
F_10 ( V_2 , L_40 ) ;
return - V_249 ;
}
V_271 = V_12 -> V_272 ( V_4 -> V_9 ) ;
if ( V_271 > 0 )
return V_271 * sizeof( T_1 ) ;
else
return V_271 ;
}
static int F_73 ( struct V_1 * V_130 )
{
int V_40 = 0 ;
struct V_20 * V_273 = V_130 -> V_10 ;
if ( F_16 ( V_130 ) ) {
if ( V_273 && V_273 -> V_50 == V_77 )
V_40 = F_74 ( V_273 ) ;
}
return V_40 ;
}
static T_1
F_75 ( struct V_1 * V_130 )
{
struct V_3 * V_4 = F_2 ( V_130 ) ;
struct V_167 * V_12 ;
if ( F_13 ( V_4 -> V_69 ) ) {
F_10 ( V_130 ,
L_41 ) ;
return 0 ;
}
V_12 = V_4 -> V_9 -> V_11 -> V_12 ;
return V_12 -> V_274 ( V_4 -> V_9 ) ;
}
static T_1
F_76 ( struct V_1 * V_130 )
{
struct V_3 * V_4 = F_2 ( V_130 ) ;
struct V_167 * V_12 ;
if ( F_13 ( V_4 -> V_69 ) ) {
F_10 ( V_130 ,
L_41 ) ;
return 0 ;
}
V_12 = V_4 -> V_9 -> V_11 -> V_12 ;
return V_12 -> V_275 ( V_4 -> V_9 ) ;
}
static int
F_77 ( struct V_1 * V_130 , T_1 * V_276 , T_2 * V_277 , T_2 * V_278 )
{
struct V_3 * V_4 = F_2 ( V_130 ) ;
struct V_167 * V_12 ;
if ( F_13 ( V_4 -> V_69 ) ) {
F_10 ( V_130 ,
L_41 ) ;
return - V_249 ;
}
V_12 = V_4 -> V_9 -> V_11 -> V_12 ;
if ( ! V_276 )
return 0 ;
return V_12 -> V_279 ( V_4 -> V_9 , V_276 , V_277 , V_278 ) ;
}
static int
F_78 ( struct V_1 * V_130 , const T_1 * V_276 , const T_2 * V_277 ,
const T_2 V_278 )
{
struct V_3 * V_4 = F_2 ( V_130 ) ;
struct V_167 * V_12 ;
if ( F_13 ( V_4 -> V_69 ) ) {
F_10 ( V_130 ,
L_41 ) ;
return - V_249 ;
}
V_12 = V_4 -> V_9 -> V_11 -> V_12 ;
if ( V_278 != V_280 && V_278 != V_281 ) {
F_10 ( V_130 , L_42 ) ;
return - V_249 ;
}
return V_12 -> V_282 ( V_4 -> V_9 , V_276 , V_277 , V_278 ) ;
}
static int F_79 ( struct V_1 * V_130 ,
struct V_283 * V_15 ,
T_1 * V_284 )
{
struct V_3 * V_4 = F_2 ( V_130 ) ;
switch ( V_15 -> V_15 ) {
case V_285 :
V_15 -> V_117 = V_4 -> V_9 -> V_142 ;
break;
default:
return - V_249 ;
}
return 0 ;
}
void F_80 ( struct V_1 * V_89 )
{
V_89 -> V_286 = & V_287 ;
}
