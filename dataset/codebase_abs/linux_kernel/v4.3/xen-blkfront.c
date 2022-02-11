static int F_1 ( struct V_1 * V_2 )
{
unsigned long free = V_2 -> V_3 ;
F_2 ( free >= F_3 ( V_2 ) ) ;
V_2 -> V_3 = V_2 -> V_4 [ free ] . V_5 . V_6 . V_7 . V_8 ;
V_2 -> V_4 [ free ] . V_5 . V_6 . V_7 . V_8 = 0x0fffffee ;
return free ;
}
static int F_4 ( struct V_1 * V_2 ,
unsigned long V_8 )
{
if ( V_2 -> V_4 [ V_8 ] . V_5 . V_6 . V_7 . V_8 != V_8 )
return - V_9 ;
if ( V_2 -> V_4 [ V_8 ] . V_10 == NULL )
return - V_9 ;
V_2 -> V_4 [ V_8 ] . V_5 . V_6 . V_7 . V_8 = V_2 -> V_3 ;
V_2 -> V_4 [ V_8 ] . V_10 = NULL ;
V_2 -> V_3 = V_8 ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 , int V_11 )
{
struct V_12 * V_13 ;
struct V_14 * V_15 , * V_16 ;
int V_17 = 0 ;
while( V_17 < V_11 ) {
V_15 = F_6 ( sizeof( struct V_14 ) , V_18 ) ;
if ( ! V_15 )
goto V_19;
if ( V_2 -> V_20 ) {
V_13 = F_7 ( V_18 ) ;
if ( ! V_13 ) {
F_8 ( V_15 ) ;
goto V_19;
}
V_15 -> V_21 = F_9 ( V_13 ) ;
}
V_15 -> V_22 = V_23 ;
F_10 ( & V_15 -> V_24 , & V_2 -> V_25 ) ;
V_17 ++ ;
}
return 0 ;
V_19:
F_11 (gnt_list_entry, n,
&info->grants, node) {
F_12 ( & V_15 -> V_24 ) ;
if ( V_2 -> V_20 )
F_13 ( F_14 ( V_15 -> V_21 ) ) ;
F_8 ( V_15 ) ;
V_17 -- ;
}
F_2 ( V_17 != 0 ) ;
return - V_26 ;
}
static struct V_14 * F_15 ( T_1 * V_27 ,
unsigned long V_21 ,
struct V_1 * V_2 )
{
struct V_14 * V_15 ;
unsigned long V_28 ;
F_2 ( F_16 ( & V_2 -> V_25 ) ) ;
V_15 = F_17 ( & V_2 -> V_25 , struct V_14 ,
V_24 ) ;
F_12 ( & V_15 -> V_24 ) ;
if ( V_15 -> V_22 != V_23 ) {
V_2 -> V_29 -- ;
return V_15 ;
}
V_15 -> V_22 = F_18 ( V_27 ) ;
F_2 ( V_15 -> V_22 == - V_30 ) ;
if ( ! V_2 -> V_20 ) {
F_2 ( ! V_21 ) ;
V_15 -> V_21 = V_21 ;
}
V_28 = F_19 ( V_15 -> V_21 ) ;
F_20 ( V_15 -> V_22 ,
V_2 -> V_31 -> V_32 ,
V_28 , 0 ) ;
return V_15 ;
}
static const char * F_21 ( int V_33 )
{
static const char * const V_34 [] = {
[ V_35 ] = L_1 ,
[ V_36 ] = L_2 ,
[ V_37 ] = L_3 ,
[ V_38 ] = L_4 ,
[ V_39 ] = L_5 } ;
if ( V_33 < 0 || V_33 >= F_22 ( V_34 ) )
return L_6 ;
if ( ! V_34 [ V_33 ] )
return L_7 ;
return V_34 [ V_33 ] ;
}
static int F_23 ( unsigned int V_40 , unsigned int V_41 )
{
unsigned int V_42 = V_40 + V_41 ;
int V_43 ;
if ( V_42 > V_44 ) {
unsigned long * V_45 , * V_46 ;
V_45 = F_24 ( F_25 ( V_42 ) , sizeof( * V_45 ) ,
V_47 ) ;
if ( V_45 == NULL )
return - V_26 ;
F_26 ( & V_48 ) ;
if ( V_42 > V_44 ) {
V_46 = V_49 ;
memcpy ( V_45 , V_49 ,
F_25 ( V_44 ) * sizeof( * V_45 ) ) ;
V_49 = V_45 ;
V_44 = F_25 ( V_42 ) * V_50 ;
} else
V_46 = V_45 ;
F_27 ( & V_48 ) ;
F_8 ( V_46 ) ;
}
F_26 ( & V_48 ) ;
if ( F_28 ( V_49 , V_42 , V_40 ) >= V_42 ) {
F_29 ( V_49 , V_40 , V_41 ) ;
V_43 = 0 ;
} else
V_43 = - V_51 ;
F_27 ( & V_48 ) ;
return V_43 ;
}
static void F_30 ( unsigned int V_40 , unsigned int V_41 )
{
unsigned int V_42 = V_40 + V_41 ;
F_2 ( V_42 > V_44 ) ;
F_26 ( & V_48 ) ;
F_31 ( V_49 , V_40 , V_41 ) ;
F_27 ( & V_48 ) ;
}
static void F_32 ( void * V_52 )
{
struct V_1 * V_2 = (struct V_1 * ) V_52 ;
F_33 ( & V_2 -> V_53 ) ;
}
static int F_34 ( struct V_54 * V_55 , struct V_56 * V_57 )
{
T_2 V_58 = F_35 ( V_55 -> V_59 ) ;
T_2 V_60 = V_58 ;
V_57 -> V_61 = 0xff ;
V_57 -> V_62 = 0x3f ;
F_36 ( V_60 , V_57 -> V_61 * V_57 -> V_62 ) ;
V_57 -> V_60 = V_60 ;
if ( ( T_2 ) ( V_57 -> V_60 + 1 ) * V_57 -> V_61 * V_57 -> V_62 < V_58 )
V_57 -> V_60 = 0xffff ;
return 0 ;
}
static int F_37 ( struct V_54 * V_63 , T_3 V_64 ,
unsigned V_65 , unsigned long V_66 )
{
struct V_1 * V_2 = V_63 -> V_59 -> V_67 ;
int V_17 ;
F_38 ( & V_2 -> V_31 -> V_68 , L_8 ,
V_65 , ( long ) V_66 ) ;
switch ( V_65 ) {
case V_69 :
F_38 ( & V_2 -> V_31 -> V_68 , L_9 ) ;
for ( V_17 = 0 ; V_17 < sizeof( struct V_70 ) ; V_17 ++ )
if ( F_39 ( 0 , ( char V_71 * ) ( V_66 + V_17 ) ) )
return - V_72 ;
return 0 ;
case V_73 : {
struct V_74 * V_75 = V_2 -> V_75 ;
if ( V_75 -> V_76 & V_77 )
return 0 ;
return - V_9 ;
}
default:
return - V_9 ;
}
return 0 ;
}
static int F_40 ( struct V_10 * V_5 )
{
struct V_1 * V_2 = V_5 -> V_78 -> V_67 ;
struct V_79 * V_80 ;
unsigned long V_8 ;
unsigned int V_81 , V_82 ;
int V_17 , V_83 , V_16 ;
struct V_84 * V_85 = NULL ;
bool V_86 ;
T_1 V_27 ;
struct V_14 * V_15 = NULL ;
struct V_87 * V_88 ;
int V_89 , V_90 ;
if ( F_41 ( V_2 -> V_91 != V_92 ) )
return 1 ;
V_90 = V_5 -> V_93 ;
if ( V_90 > V_94 )
V_90 += F_42 ( V_5 -> V_93 ) ;
if ( V_2 -> V_29 < V_90 ) {
V_86 = 1 ;
if ( F_43 (
V_90 - V_2 -> V_29 ,
& V_27 ) < 0 ) {
F_44 (
& V_2 -> V_95 ,
F_32 ,
V_2 ,
V_90 ) ;
return 1 ;
}
} else
V_86 = 0 ;
V_80 = F_45 ( & V_2 -> V_96 , V_2 -> V_96 . V_97 ) ;
V_8 = F_1 ( V_2 ) ;
V_2 -> V_4 [ V_8 ] . V_10 = V_5 ;
if ( F_41 ( V_5 -> V_98 & ( V_99 | V_100 ) ) ) {
V_80 -> V_101 = V_39 ;
V_80 -> V_6 . V_102 . V_103 = F_46 ( V_5 ) ;
V_80 -> V_6 . V_102 . V_8 = V_8 ;
V_80 -> V_6 . V_102 . V_104 = ( V_105 ) F_47 ( V_5 ) ;
if ( ( V_5 -> V_98 & V_100 ) && V_2 -> V_106 )
V_80 -> V_6 . V_102 . V_107 = V_108 ;
else
V_80 -> V_6 . V_102 . V_107 = 0 ;
} else {
F_2 ( V_2 -> V_109 == 0 &&
V_5 -> V_93 > V_94 ) ;
F_2 ( V_2 -> V_109 &&
V_5 -> V_93 > V_2 -> V_109 ) ;
V_89 = F_48 ( V_5 -> V_110 , V_5 , V_2 -> V_4 [ V_8 ] . V_88 ) ;
V_80 -> V_6 . V_7 . V_8 = V_8 ;
if ( V_89 > V_94 ) {
F_2 ( V_5 -> V_98 & ( V_111 | V_112 ) ) ;
V_80 -> V_101 = V_113 ;
V_80 -> V_6 . V_114 . V_115 = F_49 ( V_5 ) ?
V_36 : V_35 ;
V_80 -> V_6 . V_114 . V_104 = ( V_105 ) F_47 ( V_5 ) ;
V_80 -> V_6 . V_114 . V_116 = V_2 -> V_116 ;
V_80 -> V_6 . V_114 . V_117 = V_89 ;
} else {
V_80 -> V_6 . V_7 . V_104 = ( V_105 ) F_47 ( V_5 ) ;
V_80 -> V_6 . V_7 . V_116 = V_2 -> V_116 ;
V_80 -> V_101 = F_49 ( V_5 ) ?
V_36 : V_35 ;
if ( V_5 -> V_98 & ( V_111 | V_112 ) ) {
switch ( V_2 -> V_118 &
( ( V_111 | V_112 ) ) ) {
case V_111 | V_112 :
V_80 -> V_101 =
V_37 ;
break;
case V_111 :
V_80 -> V_101 =
V_38 ;
break;
default:
V_80 -> V_101 = 0 ;
}
}
V_80 -> V_6 . V_7 . V_117 = V_89 ;
}
F_50 (info->shadow[id].sg, sg, nseg, i) {
V_81 = V_88 -> V_119 >> 9 ;
V_82 = V_81 + ( V_88 -> V_120 >> 9 ) - 1 ;
if ( ( V_80 -> V_101 == V_113 ) &&
( V_17 % V_121 == 0 ) ) {
unsigned long V_122 ( V_21 ) ;
if ( V_85 )
F_51 ( V_85 ) ;
V_16 = V_17 / V_121 ;
if ( ! V_2 -> V_20 ) {
struct V_12 * V_123 ;
F_2 ( F_16 ( & V_2 -> V_124 ) ) ;
V_123 = F_17 ( & V_2 -> V_124 ,
struct V_12 , V_125 ) ;
F_12 ( & V_123 -> V_125 ) ;
V_21 = F_9 ( V_123 ) ;
}
V_15 = F_15 ( & V_27 , V_21 , V_2 ) ;
V_2 -> V_4 [ V_8 ] . V_126 [ V_16 ] = V_15 ;
V_85 = F_52 ( F_14 ( V_15 -> V_21 ) ) ;
V_80 -> V_6 . V_114 . V_127 [ V_16 ] = V_15 -> V_22 ;
}
V_15 = F_15 ( & V_27 , F_9 ( F_53 ( V_88 ) ) , V_2 ) ;
V_83 = V_15 -> V_22 ;
V_2 -> V_4 [ V_8 ] . V_128 [ V_17 ] = V_15 ;
if ( F_49 ( V_5 ) && V_2 -> V_20 ) {
char * V_129 ;
void * V_130 ;
F_2 ( V_88 -> V_119 + V_88 -> V_120 > V_131 ) ;
V_130 = F_52 ( F_14 ( V_15 -> V_21 ) ) ;
V_129 = F_52 ( F_53 ( V_88 ) ) ;
memcpy ( V_130 + V_88 -> V_119 ,
V_129 + V_88 -> V_119 ,
V_88 -> V_120 ) ;
F_51 ( V_129 ) ;
F_51 ( V_130 ) ;
}
if ( V_80 -> V_101 != V_113 ) {
V_80 -> V_6 . V_7 . V_132 [ V_17 ] =
(struct V_84 ) {
. V_22 = V_83 ,
. V_133 = V_81 ,
. V_134 = V_82 } ;
} else {
V_16 = V_17 % V_121 ;
V_85 [ V_16 ] =
(struct V_84 ) {
. V_22 = V_83 ,
. V_133 = V_81 ,
. V_134 = V_82 } ;
}
}
if ( V_85 )
F_51 ( V_85 ) ;
}
V_2 -> V_96 . V_97 ++ ;
V_2 -> V_4 [ V_8 ] . V_5 = * V_80 ;
if ( V_86 )
F_54 ( V_27 ) ;
return 0 ;
}
static inline void F_55 ( struct V_1 * V_2 )
{
int V_135 ;
F_56 ( & V_2 -> V_96 , V_135 ) ;
if ( V_135 )
F_57 ( V_2 -> V_136 ) ;
}
static inline bool F_58 ( struct V_10 * V_5 ,
struct V_1 * V_2 )
{
return ( ( V_5 -> V_137 != V_138 ) ||
( ( V_5 -> V_98 & V_111 ) &&
! ( V_2 -> V_118 & V_111 ) ) ||
( ( V_5 -> V_98 & V_112 ) &&
! ( V_2 -> V_118 & V_112 ) ) ) ;
}
static int F_59 ( struct V_139 * V_140 ,
const struct V_141 * V_142 )
{
struct V_1 * V_2 = V_142 -> V_143 -> V_78 -> V_67 ;
F_60 ( V_142 -> V_143 ) ;
F_61 ( & V_2 -> V_144 ) ;
if ( F_62 ( & V_2 -> V_96 ) )
goto V_145;
if ( F_58 ( V_142 -> V_143 , V_2 ) )
goto V_146;
if ( F_40 ( V_142 -> V_143 ) )
goto V_145;
F_55 ( V_2 ) ;
F_63 ( & V_2 -> V_144 ) ;
return V_147 ;
V_146:
F_63 ( & V_2 -> V_144 ) ;
return V_148 ;
V_145:
F_63 ( & V_2 -> V_144 ) ;
F_64 ( V_140 ) ;
return V_149 ;
}
static int F_65 ( struct V_74 * V_75 , T_4 V_150 ,
unsigned int V_151 ,
unsigned int V_85 )
{
struct V_152 * V_143 ;
struct V_1 * V_2 = V_75 -> V_67 ;
memset ( & V_2 -> V_153 , 0 , sizeof( V_2 -> V_153 ) ) ;
V_2 -> V_153 . V_154 = & V_155 ;
V_2 -> V_153 . V_156 = 1 ;
V_2 -> V_153 . V_157 = F_3 ( V_2 ) ;
V_2 -> V_153 . V_158 = V_159 ;
V_2 -> V_153 . V_76 = V_160 | V_161 ;
V_2 -> V_153 . V_162 = 0 ;
V_2 -> V_153 . V_163 = V_2 ;
if ( F_66 ( & V_2 -> V_153 ) )
return - 1 ;
V_143 = F_67 ( & V_2 -> V_153 ) ;
if ( F_68 ( V_143 ) ) {
F_69 ( & V_2 -> V_153 ) ;
return - 1 ;
}
F_70 ( V_164 , V_143 ) ;
if ( V_2 -> V_165 ) {
F_70 ( V_166 , V_143 ) ;
F_71 ( V_143 , F_35 ( V_75 ) ) ;
V_143 -> V_167 . V_168 = V_2 -> V_168 ;
V_143 -> V_167 . V_169 = V_2 -> V_169 ;
if ( V_2 -> V_106 )
F_70 ( V_170 , V_143 ) ;
}
F_72 ( V_143 , V_150 ) ;
F_73 ( V_143 , V_151 ) ;
F_74 ( V_143 , ( V_85 * V_131 ) / 512 ) ;
F_75 ( V_143 , V_131 - 1 ) ;
F_76 ( V_143 , V_131 ) ;
F_77 ( V_143 , V_85 ) ;
F_78 ( V_143 , 511 ) ;
F_79 ( V_143 , V_171 ) ;
V_75 -> V_172 = V_143 ;
return 0 ;
}
static const char * F_80 ( unsigned int V_118 )
{
switch ( V_118 & ( ( V_111 | V_112 ) ) ) {
case V_111 | V_112 :
return L_10 ;
case V_111 :
return L_11 ;
default:
return L_12 ;
}
}
static void F_81 ( struct V_1 * V_2 )
{
F_82 ( V_2 -> V_143 , V_2 -> V_118 ) ;
F_83 ( L_13 ,
V_2 -> V_75 -> V_173 , F_80 ( V_2 -> V_118 ) ,
L_14 , V_2 -> V_20 ?
L_15 : L_16 , L_17 ,
V_2 -> V_109 ? L_15 : L_16 ) ;
}
static int F_84 ( int V_174 , int * V_40 , unsigned int * V_119 )
{
int V_175 ;
V_175 = F_85 ( V_174 ) ;
* V_40 = F_86 ( V_174 ) ;
switch ( V_175 ) {
case V_176 :
* V_119 = ( * V_40 / 64 ) + V_177 ;
* V_40 = ( ( * V_40 / 64 ) * V_178 ) +
V_179 ;
break;
case V_180 :
* V_119 = ( * V_40 / 64 ) + 2 + V_177 ;
* V_40 = ( ( ( * V_40 / 64 ) + 2 ) * V_178 ) +
V_179 ;
break;
case V_181 :
* V_119 = ( * V_40 / V_178 ) + V_182 ;
* V_40 = * V_40 + V_183 ;
break;
case V_184 :
case V_185 :
case V_186 :
case V_187 :
case V_188 :
case V_189 :
case V_190 :
* V_119 = ( * V_40 / V_178 ) +
( ( V_175 - V_184 + 1 ) * 16 ) +
V_182 ;
* V_40 = * V_40 +
( ( V_175 - V_184 + 1 ) * 16 * V_178 ) +
V_183 ;
break;
case V_191 :
case V_192 :
case V_193 :
case V_194 :
case V_195 :
case V_196 :
case V_197 :
case V_198 :
* V_119 = ( * V_40 / V_178 ) +
( ( V_175 - V_191 + 8 ) * 16 ) +
V_182 ;
* V_40 = * V_40 +
( ( V_175 - V_191 + 8 ) * 16 * V_178 ) +
V_183 ;
break;
case V_199 :
* V_119 = * V_40 / V_178 ;
break;
default:
F_87 ( V_200 L_18
L_19 ) ;
return - V_201 ;
}
return 0 ;
}
static char * F_88 ( char * V_202 , unsigned int V_16 )
{
if ( V_16 >= 26 )
V_202 = F_88 ( V_202 , V_16 / 26 - 1 ) ;
* V_202 = 'a' + V_16 % 26 ;
return V_202 + 1 ;
}
static int F_89 ( V_105 V_203 ,
struct V_1 * V_2 ,
T_4 V_204 , T_4 V_150 ,
unsigned int V_151 )
{
struct V_74 * V_75 ;
int V_44 = 1 ;
int V_205 ;
unsigned int V_119 ;
int V_40 ;
int V_206 ;
char * V_202 ;
F_2 ( V_2 -> V_75 != NULL ) ;
F_2 ( V_2 -> V_143 != NULL ) ;
if ( ( V_2 -> V_174 >> V_207 ) > 1 ) {
F_87 ( V_200 L_20 , V_2 -> V_174 ) ;
return - V_201 ;
}
if ( ! F_90 ( V_2 -> V_174 ) ) {
V_205 = F_84 ( V_2 -> V_174 , & V_40 , & V_119 ) ;
if ( V_205 )
return V_205 ;
V_206 = V_178 ;
} else {
V_40 = F_91 ( V_2 -> V_174 ) ;
V_206 = V_208 ;
V_119 = V_40 / V_206 ;
if ( F_92 () && V_119 < V_177 + 4 )
F_87 ( V_200 L_21
L_22
L_23 , V_2 -> V_174 ) ;
}
if ( V_40 >> V_209 ) {
F_93 ( L_24 ,
V_2 -> V_174 , V_40 ) ;
return - V_201 ;
}
if ( ( V_40 % V_206 ) == 0 )
V_44 = V_206 ;
V_205 = F_23 ( V_40 , V_44 ) ;
if ( V_205 )
goto V_210;
V_205 = - V_201 ;
V_75 = F_94 ( V_44 ) ;
if ( V_75 == NULL )
goto V_211;
strcpy ( V_75 -> V_173 , V_212 ) ;
V_202 = F_88 ( V_75 -> V_173 + sizeof( V_212 ) - 1 , V_119 ) ;
F_2 ( V_202 >= V_75 -> V_173 + V_213 ) ;
if ( V_44 > 1 )
* V_202 = 0 ;
else
snprintf ( V_202 , V_75 -> V_173 + V_213 - V_202 ,
L_25 , V_40 & ( V_206 - 1 ) ) ;
V_75 -> V_175 = V_199 ;
V_75 -> V_214 = V_40 ;
V_75 -> V_215 = & V_216 ;
V_75 -> V_67 = V_2 ;
V_75 -> V_217 = & ( V_2 -> V_31 -> V_68 ) ;
F_95 ( V_75 , V_203 ) ;
if ( F_65 ( V_75 , V_150 , V_151 ,
V_2 -> V_109 ? :
V_94 ) ) {
F_96 ( V_75 ) ;
goto V_211;
}
V_2 -> V_143 = V_75 -> V_172 ;
V_2 -> V_75 = V_75 ;
F_81 ( V_2 ) ;
if ( V_204 & V_218 )
F_97 ( V_75 , 1 ) ;
if ( V_204 & V_219 )
V_75 -> V_76 |= V_220 ;
if ( V_204 & V_221 )
V_75 -> V_76 |= V_77 ;
return 0 ;
V_211:
F_30 ( V_40 , V_44 ) ;
V_210:
return V_205 ;
}
static void F_98 ( struct V_1 * V_2 )
{
unsigned int V_40 , V_44 ;
if ( V_2 -> V_143 == NULL )
return;
F_99 ( V_2 -> V_143 ) ;
F_100 ( & V_2 -> V_95 ) ;
F_101 ( & V_2 -> V_53 ) ;
F_96 ( V_2 -> V_75 ) ;
V_40 = V_2 -> V_75 -> V_214 ;
V_44 = V_2 -> V_75 -> V_49 ;
F_30 ( V_40 , V_44 ) ;
F_102 ( V_2 -> V_143 ) ;
F_69 ( & V_2 -> V_153 ) ;
V_2 -> V_143 = NULL ;
F_103 ( V_2 -> V_75 ) ;
V_2 -> V_75 = NULL ;
}
static void F_104 ( struct V_1 * V_2 )
{
if ( ! F_62 ( & V_2 -> V_96 ) )
F_105 ( V_2 -> V_143 , true ) ;
}
static void F_106 ( struct V_222 * V_53 )
{
struct V_1 * V_2 = F_107 ( V_53 , struct V_1 , V_53 ) ;
F_61 ( & V_2 -> V_144 ) ;
if ( V_2 -> V_91 == V_92 )
F_104 ( V_2 ) ;
F_63 ( & V_2 -> V_144 ) ;
}
static void F_108 ( struct V_1 * V_2 , int V_223 )
{
struct V_14 * V_224 ;
struct V_14 * V_16 ;
int V_17 , V_225 , V_226 ;
F_61 ( & V_2 -> V_144 ) ;
V_2 -> V_91 = V_223 ?
V_227 : V_228 ;
if ( V_2 -> V_143 )
F_99 ( V_2 -> V_143 ) ;
if ( ! F_16 ( & V_2 -> V_25 ) ) {
F_11 (persistent_gnt, n,
&info->grants, node) {
F_12 ( & V_224 -> V_24 ) ;
if ( V_224 -> V_22 != V_23 ) {
F_109 ( V_224 -> V_22 ,
0 , 0UL ) ;
V_2 -> V_29 -- ;
}
if ( V_2 -> V_20 )
F_13 ( F_14 ( V_224 -> V_21 ) ) ;
F_8 ( V_224 ) ;
}
}
F_2 ( V_2 -> V_29 != 0 ) ;
if ( ! F_16 ( & V_2 -> V_124 ) ) {
struct V_12 * V_123 , * V_16 ;
F_2 ( V_2 -> V_20 ) ;
F_11 (indirect_page, n, &info->indirect_pages, lru) {
F_12 ( & V_123 -> V_125 ) ;
F_13 ( V_123 ) ;
}
}
for ( V_17 = 0 ; V_17 < F_3 ( V_2 ) ; V_17 ++ ) {
if ( ! V_2 -> V_4 [ V_17 ] . V_10 )
goto V_229;
V_226 = V_2 -> V_4 [ V_17 ] . V_5 . V_101 == V_113 ?
V_2 -> V_4 [ V_17 ] . V_5 . V_6 . V_114 . V_117 :
V_2 -> V_4 [ V_17 ] . V_5 . V_6 . V_7 . V_117 ;
for ( V_225 = 0 ; V_225 < V_226 ; V_225 ++ ) {
V_224 = V_2 -> V_4 [ V_17 ] . V_128 [ V_225 ] ;
F_109 ( V_224 -> V_22 , 0 , 0UL ) ;
if ( V_2 -> V_20 )
F_13 ( F_14 ( V_224 -> V_21 ) ) ;
F_8 ( V_224 ) ;
}
if ( V_2 -> V_4 [ V_17 ] . V_5 . V_101 != V_113 )
goto V_229;
for ( V_225 = 0 ; V_225 < F_42 ( V_226 ) ; V_225 ++ ) {
V_224 = V_2 -> V_4 [ V_17 ] . V_126 [ V_225 ] ;
F_109 ( V_224 -> V_22 , 0 , 0UL ) ;
F_13 ( F_14 ( V_224 -> V_21 ) ) ;
F_8 ( V_224 ) ;
}
V_229:
F_8 ( V_2 -> V_4 [ V_17 ] . V_128 ) ;
V_2 -> V_4 [ V_17 ] . V_128 = NULL ;
F_8 ( V_2 -> V_4 [ V_17 ] . V_126 ) ;
V_2 -> V_4 [ V_17 ] . V_126 = NULL ;
F_8 ( V_2 -> V_4 [ V_17 ] . V_88 ) ;
V_2 -> V_4 [ V_17 ] . V_88 = NULL ;
}
F_100 ( & V_2 -> V_95 ) ;
F_63 ( & V_2 -> V_144 ) ;
F_101 ( & V_2 -> V_53 ) ;
for ( V_17 = 0 ; V_17 < V_2 -> V_230 ; V_17 ++ ) {
if ( V_2 -> V_231 [ V_17 ] != V_23 ) {
F_109 ( V_2 -> V_231 [ V_17 ] , 0 , 0 ) ;
V_2 -> V_231 [ V_17 ] = V_23 ;
}
}
F_110 ( ( unsigned long ) V_2 -> V_96 . V_232 , F_111 ( V_2 -> V_230 * V_131 ) ) ;
V_2 -> V_96 . V_232 = NULL ;
if ( V_2 -> V_136 )
F_112 ( V_2 -> V_136 , V_2 ) ;
V_2 -> V_233 = V_2 -> V_136 = 0 ;
}
static void F_113 ( struct V_234 * V_235 , struct V_1 * V_2 ,
struct V_236 * V_237 )
{
int V_17 = 0 ;
struct V_87 * V_88 ;
char * V_129 ;
void * V_130 ;
int V_89 ;
V_89 = V_235 -> V_5 . V_101 == V_113 ?
V_235 -> V_5 . V_6 . V_114 . V_117 : V_235 -> V_5 . V_6 . V_7 . V_117 ;
if ( V_237 -> V_101 == V_35 && V_2 -> V_20 ) {
F_50 (s->sg, sg, nseg, i) {
F_2 ( V_88 -> V_119 + V_88 -> V_120 > V_131 ) ;
V_130 = F_52 (
F_14 ( V_235 -> V_128 [ V_17 ] -> V_21 ) ) ;
V_129 = F_52 ( F_53 ( V_88 ) ) ;
memcpy ( V_129 + V_88 -> V_119 ,
V_130 + V_88 -> V_119 ,
V_88 -> V_120 ) ;
F_51 ( V_129 ) ;
F_51 ( V_130 ) ;
}
}
for ( V_17 = 0 ; V_17 < V_89 ; V_17 ++ ) {
if ( F_114 ( V_235 -> V_128 [ V_17 ] -> V_22 ) ) {
if ( ! V_2 -> V_20 )
F_115 ( L_26 ,
V_235 -> V_128 [ V_17 ] -> V_22 ) ;
F_10 ( & V_235 -> V_128 [ V_17 ] -> V_24 , & V_2 -> V_25 ) ;
V_2 -> V_29 ++ ;
} else {
F_109 ( V_235 -> V_128 [ V_17 ] -> V_22 , 0 , 0UL ) ;
V_235 -> V_128 [ V_17 ] -> V_22 = V_23 ;
F_116 ( & V_235 -> V_128 [ V_17 ] -> V_24 , & V_2 -> V_25 ) ;
}
}
if ( V_235 -> V_5 . V_101 == V_113 ) {
for ( V_17 = 0 ; V_17 < F_42 ( V_89 ) ; V_17 ++ ) {
if ( F_114 ( V_235 -> V_126 [ V_17 ] -> V_22 ) ) {
if ( ! V_2 -> V_20 )
F_115 ( L_26 ,
V_235 -> V_126 [ V_17 ] -> V_22 ) ;
F_10 ( & V_235 -> V_126 [ V_17 ] -> V_24 , & V_2 -> V_25 ) ;
V_2 -> V_29 ++ ;
} else {
struct V_12 * V_123 ;
F_109 ( V_235 -> V_126 [ V_17 ] -> V_22 , 0 , 0UL ) ;
if ( ! V_2 -> V_20 ) {
V_123 = F_14 ( V_235 -> V_126 [ V_17 ] -> V_21 ) ;
F_10 ( & V_123 -> V_125 , & V_2 -> V_124 ) ;
}
V_235 -> V_126 [ V_17 ] -> V_22 = V_23 ;
F_116 ( & V_235 -> V_126 [ V_17 ] -> V_24 , & V_2 -> V_25 ) ;
}
}
}
}
static T_5 F_117 ( int V_136 , void * V_238 )
{
struct V_10 * V_5 ;
struct V_236 * V_237 ;
T_6 V_17 , V_239 ;
unsigned long V_76 ;
struct V_1 * V_2 = (struct V_1 * ) V_238 ;
int error ;
F_118 ( & V_2 -> V_144 , V_76 ) ;
if ( F_41 ( V_2 -> V_91 != V_92 ) ) {
F_119 ( & V_2 -> V_144 , V_76 ) ;
return V_240 ;
}
V_241:
V_239 = V_2 -> V_96 . V_232 -> V_242 ;
F_120 () ;
for ( V_17 = V_2 -> V_96 . V_243 ; V_17 != V_239 ; V_17 ++ ) {
unsigned long V_8 ;
V_237 = F_121 ( & V_2 -> V_96 , V_17 ) ;
V_8 = V_237 -> V_8 ;
if ( V_8 >= F_3 ( V_2 ) ) {
F_122 ( 1 , L_27 ,
V_2 -> V_75 -> V_173 , F_21 ( V_237 -> V_101 ) , V_8 ) ;
continue;
}
V_5 = V_2 -> V_4 [ V_8 ] . V_10 ;
if ( V_237 -> V_101 != V_39 )
F_113 ( & V_2 -> V_4 [ V_8 ] , V_2 , V_237 ) ;
if ( F_4 ( V_2 , V_8 ) ) {
F_122 ( 1 , L_28 ,
V_2 -> V_75 -> V_173 , F_21 ( V_237 -> V_101 ) , V_8 ) ;
continue;
}
error = ( V_237 -> V_244 == V_245 ) ? 0 : - V_246 ;
switch ( V_237 -> V_101 ) {
case V_39 :
if ( F_41 ( V_237 -> V_244 == V_247 ) ) {
struct V_152 * V_143 = V_2 -> V_143 ;
F_87 ( V_200 L_29 ,
V_2 -> V_75 -> V_173 , F_21 ( V_237 -> V_101 ) ) ;
error = - V_248 ;
V_2 -> V_165 = 0 ;
V_2 -> V_106 = 0 ;
F_123 ( V_166 , V_143 ) ;
F_123 ( V_170 , V_143 ) ;
}
F_124 ( V_5 , error ) ;
break;
case V_38 :
case V_37 :
if ( F_41 ( V_237 -> V_244 == V_247 ) ) {
F_87 ( V_200 L_29 ,
V_2 -> V_75 -> V_173 , F_21 ( V_237 -> V_101 ) ) ;
error = - V_248 ;
}
if ( F_41 ( V_237 -> V_244 == V_249 &&
V_2 -> V_4 [ V_8 ] . V_5 . V_6 . V_7 . V_117 == 0 ) ) {
F_87 ( V_200 L_30 ,
V_2 -> V_75 -> V_173 , F_21 ( V_237 -> V_101 ) ) ;
error = - V_248 ;
}
if ( F_41 ( error ) ) {
if ( error == - V_248 )
error = 0 ;
V_2 -> V_118 = 0 ;
F_81 ( V_2 ) ;
}
case V_35 :
case V_36 :
if ( F_41 ( V_237 -> V_244 != V_245 ) )
F_38 ( & V_2 -> V_31 -> V_68 , L_31
L_32 , V_237 -> V_244 ) ;
F_124 ( V_5 , error ) ;
break;
default:
F_125 () ;
}
}
V_2 -> V_96 . V_243 = V_17 ;
if ( V_17 != V_2 -> V_96 . V_97 ) {
int V_250 ;
F_126 ( & V_2 -> V_96 , V_250 ) ;
if ( V_250 )
goto V_241;
} else
V_2 -> V_96 . V_232 -> V_251 = V_17 + 1 ;
F_104 ( V_2 ) ;
F_119 ( & V_2 -> V_144 , V_76 ) ;
return V_240 ;
}
static int F_127 ( struct V_252 * V_68 ,
struct V_1 * V_2 )
{
struct V_253 * V_232 ;
int V_205 , V_17 ;
unsigned long V_254 = V_2 -> V_230 * V_131 ;
T_1 V_22 [ V_255 ] ;
for ( V_17 = 0 ; V_17 < V_2 -> V_230 ; V_17 ++ )
V_2 -> V_231 [ V_17 ] = V_23 ;
V_232 = (struct V_253 * ) F_128 ( V_18 | V_256 ,
F_111 ( V_254 ) ) ;
if ( ! V_232 ) {
F_129 ( V_68 , - V_26 , L_33 ) ;
return - V_26 ;
}
F_130 ( V_232 ) ;
F_131 ( & V_2 -> V_96 , V_232 , V_254 ) ;
V_205 = F_132 ( V_68 , V_2 -> V_96 . V_232 , V_2 -> V_230 , V_22 ) ;
if ( V_205 < 0 ) {
F_110 ( ( unsigned long ) V_232 , F_111 ( V_254 ) ) ;
V_2 -> V_96 . V_232 = NULL ;
goto V_257;
}
for ( V_17 = 0 ; V_17 < V_2 -> V_230 ; V_17 ++ )
V_2 -> V_231 [ V_17 ] = V_22 [ V_17 ] ;
V_205 = F_133 ( V_68 , & V_2 -> V_233 ) ;
if ( V_205 )
goto V_257;
V_205 = F_134 ( V_2 -> V_233 , F_117 , 0 ,
L_34 , V_2 ) ;
if ( V_205 <= 0 ) {
F_129 ( V_68 , V_205 ,
L_35 ) ;
goto V_257;
}
V_2 -> V_136 = V_205 ;
return 0 ;
V_257:
F_108 ( V_2 , 0 ) ;
return V_205 ;
}
static int F_135 ( struct V_252 * V_68 ,
struct V_1 * V_2 )
{
const char * V_258 = NULL ;
struct V_259 V_260 ;
int V_205 , V_17 ;
unsigned int V_261 = 0 ;
unsigned int V_262 = 0 ;
V_205 = F_136 ( V_263 , V_2 -> V_31 -> V_264 ,
L_36 , L_37 , & V_261 ) ;
if ( V_205 != 1 )
V_2 -> V_230 = 1 ;
else {
V_262 = F_137 ( V_265 , V_261 ) ;
V_2 -> V_230 = 1 << V_262 ;
}
V_205 = F_127 ( V_68 , V_2 ) ;
if ( V_205 )
goto V_210;
V_241:
V_205 = F_138 ( & V_260 ) ;
if ( V_205 ) {
F_129 ( V_68 , V_205 , L_38 ) ;
goto V_266;
}
if ( V_2 -> V_230 == 1 ) {
V_205 = F_139 ( V_260 , V_68 -> V_267 ,
L_39 , L_37 , V_2 -> V_231 [ 0 ] ) ;
if ( V_205 ) {
V_258 = L_40 ;
goto V_268;
}
} else {
V_205 = F_139 ( V_260 , V_68 -> V_267 ,
L_41 , L_37 , V_262 ) ;
if ( V_205 ) {
V_258 = L_42 ;
goto V_268;
}
for ( V_17 = 0 ; V_17 < V_2 -> V_230 ; V_17 ++ ) {
char V_269 [ V_270 ] ;
snprintf ( V_269 , V_270 , L_43 , V_17 ) ;
V_205 = F_139 ( V_260 , V_68 -> V_267 , V_269 ,
L_37 , V_2 -> V_231 [ V_17 ] ) ;
if ( V_205 ) {
V_258 = L_40 ;
goto V_268;
}
}
}
V_205 = F_139 ( V_260 , V_68 -> V_267 ,
L_44 , L_37 , V_2 -> V_233 ) ;
if ( V_205 ) {
V_258 = L_45 ;
goto V_268;
}
V_205 = F_139 ( V_260 , V_68 -> V_267 , L_46 , L_47 ,
V_271 ) ;
if ( V_205 ) {
V_258 = L_48 ;
goto V_268;
}
V_205 = F_139 ( V_260 , V_68 -> V_267 ,
L_49 , L_37 , 1 ) ;
if ( V_205 )
F_140 ( & V_68 -> V_68 ,
L_50 ) ;
V_205 = F_141 ( V_260 , 0 ) ;
if ( V_205 ) {
if ( V_205 == - V_272 )
goto V_241;
F_129 ( V_68 , V_205 , L_51 ) ;
goto V_266;
}
for ( V_17 = 0 ; V_17 < F_3 ( V_2 ) ; V_17 ++ )
V_2 -> V_4 [ V_17 ] . V_5 . V_6 . V_7 . V_8 = V_17 + 1 ;
V_2 -> V_4 [ F_3 ( V_2 ) - 1 ] . V_5 . V_6 . V_7 . V_8 = 0x0fffffff ;
F_142 ( V_68 , V_273 ) ;
return 0 ;
V_268:
F_141 ( V_260 , 1 ) ;
if ( V_258 )
F_129 ( V_68 , V_205 , L_47 , V_258 ) ;
V_266:
F_108 ( V_2 , 0 ) ;
V_210:
return V_205 ;
}
static int F_143 ( struct V_252 * V_68 ,
const struct V_274 * V_8 )
{
int V_205 , V_174 ;
struct V_1 * V_2 ;
V_205 = F_136 ( V_263 , V_68 -> V_267 ,
L_52 , L_53 , & V_174 ) ;
if ( V_205 != 1 ) {
V_205 = F_136 ( V_263 , V_68 -> V_267 , L_54 ,
L_53 , & V_174 ) ;
if ( V_205 != 1 ) {
F_129 ( V_68 , V_205 , L_55 ) ;
return V_205 ;
}
}
if ( F_92 () ) {
char * type ;
int V_275 ;
if ( F_144 () ) {
int V_175 ;
if ( ! F_90 ( V_174 ) )
V_175 = F_85 ( V_174 ) ;
else
V_175 = V_199 ;
if ( V_175 != V_199 ) {
F_87 ( V_276
L_56 ,
V_277 , V_174 ) ;
return - V_201 ;
}
}
type = F_145 ( V_263 , V_68 -> V_267 , L_57 , & V_275 ) ;
if ( F_68 ( type ) )
return - V_201 ;
if ( strncmp ( type , L_58 , 5 ) == 0 ) {
F_8 ( type ) ;
return - V_201 ;
}
F_8 ( type ) ;
}
V_2 = F_6 ( sizeof( * V_2 ) , V_47 ) ;
if ( ! V_2 ) {
F_129 ( V_68 , - V_26 , L_59 ) ;
return - V_26 ;
}
F_146 ( & V_2 -> V_278 ) ;
F_147 ( & V_2 -> V_144 ) ;
V_2 -> V_31 = V_68 ;
V_2 -> V_174 = V_174 ;
F_148 ( & V_2 -> V_25 ) ;
F_148 ( & V_2 -> V_124 ) ;
V_2 -> V_29 = 0 ;
V_2 -> V_91 = V_228 ;
F_149 ( & V_2 -> V_53 , F_106 ) ;
V_2 -> V_116 = F_150 ( strrchr ( V_68 -> V_267 , '/' ) + 1 , NULL , 0 ) ;
F_151 ( & V_68 -> V_68 , V_2 ) ;
return 0 ;
}
static void F_152 ( struct V_279 * V_279 )
{
struct V_280 * V_280 = V_279 -> V_281 ;
if ( F_153 ( & V_280 -> V_282 ) ) {
V_280 -> V_279 -> V_283 = 0 ;
V_280 -> V_279 -> V_284 = V_279 -> V_284 ;
F_154 ( V_280 -> V_279 ) ;
F_8 ( V_280 ) ;
}
F_155 ( V_279 ) ;
}
static int F_156 ( struct V_1 * V_2 )
{
int V_17 ;
struct V_10 * V_5 , * V_16 ;
struct V_234 * V_285 ;
int V_43 ;
struct V_279 * V_279 , * V_286 ;
struct V_287 V_287 , V_288 ;
unsigned int V_226 , V_119 ;
int V_282 , V_289 ;
struct V_280 * V_280 ;
struct V_290 V_291 ;
V_285 = F_157 ( V_2 -> V_4 , sizeof( V_2 -> V_4 ) ,
V_18 | V_292 | V_256 ) ;
if ( ! V_285 )
return - V_26 ;
memset ( & V_2 -> V_4 , 0 , sizeof( V_2 -> V_4 ) ) ;
for ( V_17 = 0 ; V_17 < F_3 ( V_2 ) ; V_17 ++ )
V_2 -> V_4 [ V_17 ] . V_5 . V_6 . V_7 . V_8 = V_17 + 1 ;
V_2 -> V_3 = V_2 -> V_96 . V_97 ;
V_2 -> V_4 [ F_3 ( V_2 ) - 1 ] . V_5 . V_6 . V_7 . V_8 = 0x0fffffff ;
V_43 = F_158 ( V_2 ) ;
if ( V_43 ) {
F_8 ( V_285 ) ;
return V_43 ;
}
V_226 = V_2 -> V_109 ? : V_94 ;
F_77 ( V_2 -> V_143 , V_226 ) ;
F_159 ( & V_287 ) ;
F_148 ( & V_291 ) ;
for ( V_17 = 0 ; V_17 < F_3 ( V_2 ) ; V_17 ++ ) {
if ( ! V_285 [ V_17 ] . V_10 )
continue;
if ( V_285 [ V_17 ] . V_10 -> V_98 &
( V_111 | V_112 | V_99 | V_100 ) ) {
F_10 ( & V_285 [ V_17 ] . V_10 -> V_293 , & V_291 ) ;
continue;
}
V_288 . V_294 = V_285 [ V_17 ] . V_10 -> V_279 ;
V_288 . V_295 = V_285 [ V_17 ] . V_10 -> V_296 ;
F_160 ( & V_287 , & V_288 ) ;
V_285 [ V_17 ] . V_10 -> V_279 = NULL ;
F_161 ( V_285 [ V_17 ] . V_10 , 0 ) ;
}
F_8 ( V_285 ) ;
F_142 ( V_2 -> V_31 , V_297 ) ;
F_61 ( & V_2 -> V_144 ) ;
V_2 -> V_91 = V_92 ;
F_104 ( V_2 ) ;
F_11 (req, n, &requests, queuelist) {
F_162 ( & V_5 -> V_293 ) ;
F_2 ( V_5 -> V_93 > V_226 ) ;
F_163 ( V_5 ) ;
}
F_63 ( & V_2 -> V_144 ) ;
F_164 ( V_2 -> V_143 ) ;
while ( ( V_279 = F_165 ( & V_287 ) ) != NULL ) {
if ( F_166 ( V_279 ) > V_226 ) {
V_282 = ( F_166 ( V_279 ) + V_226 - 1 ) / V_226 ;
V_280 = F_6 ( sizeof( * V_280 ) , V_18 ) ;
F_2 ( V_280 == NULL ) ;
F_167 ( & V_280 -> V_282 , V_282 ) ;
V_280 -> V_279 = V_279 ;
for ( V_17 = 0 ; V_17 < V_282 ; V_17 ++ ) {
V_119 = ( V_17 * V_226 * V_131 ) >> 9 ;
V_289 = F_137 ( ( unsigned int ) ( V_226 * V_131 ) >> 9 ,
( unsigned int ) F_168 ( V_279 ) - V_119 ) ;
V_286 = F_169 ( V_279 , V_18 ) ;
F_2 ( V_286 == NULL ) ;
F_170 ( V_286 , V_119 , V_289 ) ;
V_286 -> V_281 = V_280 ;
V_286 -> V_298 = F_152 ;
F_171 ( V_286 -> V_299 , V_286 ) ;
}
continue;
}
F_171 ( V_279 -> V_299 , V_279 ) ;
}
return 0 ;
}
static int F_172 ( struct V_252 * V_68 )
{
struct V_1 * V_2 = F_173 ( & V_68 -> V_68 ) ;
int V_205 ;
F_38 ( & V_68 -> V_68 , L_60 , V_68 -> V_267 ) ;
F_108 ( V_2 , V_2 -> V_91 == V_92 ) ;
V_205 = F_135 ( V_68 , V_2 ) ;
return V_205 ;
}
static void
F_174 ( struct V_1 * V_2 )
{
struct V_252 * V_31 = V_2 -> V_31 ;
struct V_54 * V_63 = NULL ;
F_175 ( & V_2 -> V_278 ) ;
if ( V_31 -> V_300 == V_301 ) {
F_176 ( & V_2 -> V_278 ) ;
return;
}
if ( V_2 -> V_75 )
V_63 = F_177 ( V_2 -> V_75 , 0 ) ;
F_176 ( & V_2 -> V_278 ) ;
if ( ! V_63 ) {
F_178 ( V_31 ) ;
return;
}
F_175 ( & V_63 -> V_302 ) ;
if ( V_63 -> V_303 ) {
F_179 ( V_31 , - V_51 ,
L_61 ) ;
F_142 ( V_31 , V_301 ) ;
} else {
F_98 ( V_2 ) ;
F_178 ( V_31 ) ;
}
F_176 ( & V_63 -> V_302 ) ;
F_180 ( V_63 ) ;
}
static void F_181 ( struct V_1 * V_2 )
{
int V_205 ;
unsigned int V_168 ;
unsigned int V_169 ;
unsigned int V_304 ;
V_2 -> V_165 = 1 ;
V_205 = F_182 ( V_263 , V_2 -> V_31 -> V_264 ,
L_62 , L_37 , & V_168 ,
L_63 , L_37 , & V_169 ,
NULL ) ;
if ( ! V_205 ) {
V_2 -> V_168 = V_168 ;
V_2 -> V_169 = V_169 ;
}
V_205 = F_182 ( V_263 , V_2 -> V_31 -> V_264 ,
L_64 , L_25 , & V_304 ,
NULL ) ;
if ( ! V_205 )
V_2 -> V_106 = ! ! V_304 ;
}
static int F_183 ( struct V_1 * V_2 )
{
unsigned int V_226 ;
int V_205 , V_17 ;
if ( V_2 -> V_109 == 0 )
V_226 = V_94 ;
else
V_226 = V_2 -> V_109 ;
V_205 = F_5 ( V_2 , ( V_226 + F_42 ( V_226 ) ) * F_3 ( V_2 ) ) ;
if ( V_205 )
goto V_19;
if ( ! V_2 -> V_20 && V_2 -> V_109 ) {
int V_11 = F_42 ( V_226 ) * F_3 ( V_2 ) ;
F_2 ( ! F_16 ( & V_2 -> V_124 ) ) ;
for ( V_17 = 0 ; V_17 < V_11 ; V_17 ++ ) {
struct V_12 * V_123 = F_7 ( V_18 ) ;
if ( ! V_123 )
goto V_19;
F_10 ( & V_123 -> V_125 , & V_2 -> V_124 ) ;
}
}
for ( V_17 = 0 ; V_17 < F_3 ( V_2 ) ; V_17 ++ ) {
V_2 -> V_4 [ V_17 ] . V_128 = F_6 (
sizeof( V_2 -> V_4 [ V_17 ] . V_128 [ 0 ] ) * V_226 ,
V_18 ) ;
V_2 -> V_4 [ V_17 ] . V_88 = F_6 ( sizeof( V_2 -> V_4 [ V_17 ] . V_88 [ 0 ] ) * V_226 , V_18 ) ;
if ( V_2 -> V_109 )
V_2 -> V_4 [ V_17 ] . V_126 = F_6 (
sizeof( V_2 -> V_4 [ V_17 ] . V_126 [ 0 ] ) *
F_42 ( V_226 ) ,
V_18 ) ;
if ( ( V_2 -> V_4 [ V_17 ] . V_128 == NULL ) ||
( V_2 -> V_4 [ V_17 ] . V_88 == NULL ) ||
( V_2 -> V_109 &&
( V_2 -> V_4 [ V_17 ] . V_126 == NULL ) ) )
goto V_19;
F_184 ( V_2 -> V_4 [ V_17 ] . V_88 , V_226 ) ;
}
return 0 ;
V_19:
for ( V_17 = 0 ; V_17 < F_3 ( V_2 ) ; V_17 ++ ) {
F_8 ( V_2 -> V_4 [ V_17 ] . V_128 ) ;
V_2 -> V_4 [ V_17 ] . V_128 = NULL ;
F_8 ( V_2 -> V_4 [ V_17 ] . V_88 ) ;
V_2 -> V_4 [ V_17 ] . V_88 = NULL ;
F_8 ( V_2 -> V_4 [ V_17 ] . V_126 ) ;
V_2 -> V_4 [ V_17 ] . V_126 = NULL ;
}
if ( ! F_16 ( & V_2 -> V_124 ) ) {
struct V_12 * V_123 , * V_16 ;
F_11 (indirect_page, n, &info->indirect_pages, lru) {
F_12 ( & V_123 -> V_125 ) ;
F_13 ( V_123 ) ;
}
}
return - V_26 ;
}
static int F_158 ( struct V_1 * V_2 )
{
int V_205 ;
int V_305 , V_306 , V_102 , V_307 ;
unsigned int V_308 ;
V_2 -> V_118 = 0 ;
V_205 = F_182 ( V_263 , V_2 -> V_31 -> V_264 ,
L_65 , L_25 , & V_305 ,
NULL ) ;
if ( ! V_205 && V_305 )
V_2 -> V_118 = V_111 | V_112 ;
V_205 = F_182 ( V_263 , V_2 -> V_31 -> V_264 ,
L_66 , L_25 , & V_306 ,
NULL ) ;
if ( ! V_205 && V_306 )
V_2 -> V_118 = V_111 ;
V_205 = F_182 ( V_263 , V_2 -> V_31 -> V_264 ,
L_67 , L_25 , & V_102 ,
NULL ) ;
if ( ! V_205 && V_102 )
F_181 ( V_2 ) ;
V_205 = F_182 ( V_263 , V_2 -> V_31 -> V_264 ,
L_49 , L_37 , & V_307 ,
NULL ) ;
if ( V_205 )
V_2 -> V_20 = 0 ;
else
V_2 -> V_20 = V_307 ;
V_205 = F_182 ( V_263 , V_2 -> V_31 -> V_264 ,
L_68 , L_37 , & V_308 ,
NULL ) ;
if ( V_205 )
V_2 -> V_109 = 0 ;
else
V_2 -> V_109 = F_137 ( V_308 ,
V_309 ) ;
return F_183 ( V_2 ) ;
}
static void F_185 ( struct V_1 * V_2 )
{
unsigned long long V_62 ;
unsigned long V_150 ;
unsigned int V_151 ;
unsigned int V_310 ;
int V_205 ;
switch ( V_2 -> V_91 ) {
case V_92 :
V_205 = F_136 ( V_263 , V_2 -> V_31 -> V_264 ,
L_69 , L_70 , & V_62 ) ;
if ( F_186 ( V_205 ) )
return;
F_87 ( V_276 L_71 ,
V_62 ) ;
F_95 ( V_2 -> V_75 , V_62 ) ;
F_187 ( V_2 -> V_75 ) ;
return;
case V_227 :
F_156 ( V_2 ) ;
return;
default:
break;
}
F_38 ( & V_2 -> V_31 -> V_68 , L_72 ,
V_277 , V_2 -> V_31 -> V_264 ) ;
V_205 = F_182 ( V_263 , V_2 -> V_31 -> V_264 ,
L_69 , L_73 , & V_62 ,
L_74 , L_37 , & V_310 ,
L_75 , L_76 , & V_150 ,
NULL ) ;
if ( V_205 ) {
F_129 ( V_2 -> V_31 , V_205 ,
L_77 ,
V_2 -> V_31 -> V_264 ) ;
return;
}
V_205 = F_136 ( V_263 , V_2 -> V_31 -> V_264 ,
L_78 , L_37 , & V_151 ) ;
if ( V_205 != 1 )
V_151 = V_150 ;
V_205 = F_158 ( V_2 ) ;
if ( V_205 ) {
F_129 ( V_2 -> V_31 , V_205 , L_79 ,
V_2 -> V_31 -> V_264 ) ;
return;
}
V_205 = F_89 ( V_62 , V_2 , V_310 , V_150 ,
V_151 ) ;
if ( V_205 ) {
F_129 ( V_2 -> V_31 , V_205 , L_80 ,
V_2 -> V_31 -> V_264 ) ;
return;
}
F_142 ( V_2 -> V_31 , V_297 ) ;
F_61 ( & V_2 -> V_144 ) ;
V_2 -> V_91 = V_92 ;
F_104 ( V_2 ) ;
F_63 ( & V_2 -> V_144 ) ;
F_188 ( V_2 -> V_75 ) ;
V_2 -> V_311 = 1 ;
}
static void F_189 ( struct V_252 * V_68 ,
enum V_312 V_313 )
{
struct V_1 * V_2 = F_173 ( & V_68 -> V_68 ) ;
F_38 ( & V_68 -> V_68 , L_81 , V_313 ) ;
switch ( V_313 ) {
case V_314 :
if ( V_68 -> V_300 != V_315 )
break;
if ( F_135 ( V_68 , V_2 ) ) {
F_8 ( V_2 ) ;
F_151 ( & V_68 -> V_68 , NULL ) ;
break;
}
case V_315 :
case V_273 :
case V_316 :
case V_317 :
case V_318 :
break;
case V_297 :
F_185 ( V_2 ) ;
break;
case V_319 :
if ( V_68 -> V_300 == V_319 )
break;
case V_301 :
if ( V_2 )
F_174 ( V_2 ) ;
break;
}
}
static int F_190 ( struct V_252 * V_31 )
{
struct V_1 * V_2 = F_173 ( & V_31 -> V_68 ) ;
struct V_54 * V_63 = NULL ;
struct V_74 * V_320 ;
F_38 ( & V_31 -> V_68 , L_82 , V_31 -> V_267 ) ;
F_108 ( V_2 , 0 ) ;
F_175 ( & V_2 -> V_278 ) ;
V_320 = V_2 -> V_75 ;
if ( V_320 )
V_63 = F_177 ( V_320 , 0 ) ;
V_2 -> V_31 = NULL ;
F_176 ( & V_2 -> V_278 ) ;
if ( ! V_63 ) {
F_8 ( V_2 ) ;
return 0 ;
}
F_175 ( & V_63 -> V_302 ) ;
V_2 = V_320 -> V_67 ;
F_140 ( F_191 ( V_320 ) ,
L_83 ,
V_31 -> V_267 , V_63 -> V_303 ) ;
if ( V_2 && ! V_63 -> V_303 ) {
F_98 ( V_2 ) ;
V_320 -> V_67 = NULL ;
F_8 ( V_2 ) ;
}
F_176 ( & V_63 -> V_302 ) ;
F_180 ( V_63 ) ;
return 0 ;
}
static int F_192 ( struct V_252 * V_68 )
{
struct V_1 * V_2 = F_173 ( & V_68 -> V_68 ) ;
return V_2 -> V_311 && V_2 -> V_31 ;
}
static int F_193 ( struct V_54 * V_63 , T_3 V_64 )
{
struct V_74 * V_320 = V_63 -> V_59 ;
struct V_1 * V_2 ;
int V_205 = 0 ;
F_175 ( & V_321 ) ;
V_2 = V_320 -> V_67 ;
if ( ! V_2 ) {
V_205 = - V_322 ;
goto V_210;
}
F_175 ( & V_2 -> V_278 ) ;
if ( ! V_2 -> V_75 )
V_205 = - V_322 ;
F_176 ( & V_2 -> V_278 ) ;
V_210:
F_176 ( & V_321 ) ;
return V_205 ;
}
static void F_194 ( struct V_74 * V_320 , T_3 V_64 )
{
struct V_1 * V_2 = V_320 -> V_67 ;
struct V_54 * V_63 ;
struct V_252 * V_31 ;
F_175 ( & V_321 ) ;
V_63 = F_177 ( V_320 , 0 ) ;
if ( ! V_63 ) {
F_122 ( 1 , L_84 , V_320 -> V_173 ) ;
goto V_323;
}
if ( V_63 -> V_303 )
goto V_210;
F_175 ( & V_2 -> V_278 ) ;
V_31 = V_2 -> V_31 ;
if ( V_31 && V_31 -> V_300 == V_301 ) {
F_195 ( F_191 ( V_63 -> V_59 ) , L_85 ) ;
F_98 ( V_2 ) ;
F_178 ( V_2 -> V_31 ) ;
}
F_176 ( & V_2 -> V_278 ) ;
if ( ! V_31 ) {
F_195 ( F_191 ( V_63 -> V_59 ) , L_85 ) ;
F_98 ( V_2 ) ;
V_320 -> V_67 = NULL ;
F_8 ( V_2 ) ;
}
V_210:
F_180 ( V_63 ) ;
V_323:
F_176 ( & V_321 ) ;
}
static int T_7 F_196 ( void )
{
int V_324 ;
if ( ! F_197 () )
return - V_201 ;
if ( V_265 > V_325 ) {
F_83 ( L_86 ,
V_265 , V_325 ) ;
V_265 = 0 ;
}
if ( ! F_198 () )
return - V_201 ;
if ( F_199 ( V_199 , V_212 ) ) {
F_87 ( V_200 L_87 ,
V_199 , V_212 ) ;
return - V_201 ;
}
V_324 = F_200 ( & V_326 ) ;
if ( V_324 ) {
F_201 ( V_199 , V_212 ) ;
return V_324 ;
}
return 0 ;
}
static void T_8 F_202 ( void )
{
F_203 ( & V_326 ) ;
F_201 ( V_199 , V_212 ) ;
F_8 ( V_49 ) ;
}
