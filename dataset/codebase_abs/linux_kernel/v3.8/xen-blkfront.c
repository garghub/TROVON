static int F_1 ( struct V_1 * V_2 )
{
unsigned long free = V_2 -> V_3 ;
F_2 ( free >= V_4 ) ;
V_2 -> V_3 = V_2 -> V_5 [ free ] . V_6 . V_7 . V_8 . V_9 ;
V_2 -> V_5 [ free ] . V_6 . V_7 . V_8 . V_9 = 0x0fffffee ;
return free ;
}
static int F_3 ( struct V_1 * V_2 ,
unsigned long V_9 )
{
if ( V_2 -> V_5 [ V_9 ] . V_6 . V_7 . V_8 . V_9 != V_9 )
return - V_10 ;
if ( V_2 -> V_5 [ V_9 ] . V_11 == NULL )
return - V_10 ;
V_2 -> V_5 [ V_9 ] . V_6 . V_7 . V_8 . V_9 = V_2 -> V_3 ;
V_2 -> V_5 [ V_9 ] . V_11 = NULL ;
V_2 -> V_3 = V_9 ;
return 0 ;
}
static const char * F_4 ( int V_12 )
{
static const char * const V_13 [] = {
[ V_14 ] = L_1 ,
[ V_15 ] = L_2 ,
[ V_16 ] = L_3 ,
[ V_17 ] = L_4 ,
[ V_18 ] = L_5 } ;
if ( V_12 < 0 || V_12 >= F_5 ( V_13 ) )
return L_6 ;
if ( ! V_13 [ V_12 ] )
return L_7 ;
return V_13 [ V_12 ] ;
}
static int F_6 ( unsigned int V_19 , unsigned int V_20 )
{
unsigned int V_21 = V_19 + V_20 ;
int V_22 ;
if ( V_21 > V_23 ) {
unsigned long * V_24 , * V_25 ;
V_24 = F_7 ( F_8 ( V_21 ) , sizeof( * V_24 ) ,
V_26 ) ;
if ( V_24 == NULL )
return - V_27 ;
F_9 ( & V_28 ) ;
if ( V_21 > V_23 ) {
V_25 = V_29 ;
memcpy ( V_24 , V_29 ,
F_8 ( V_23 ) * sizeof( * V_24 ) ) ;
V_29 = V_24 ;
V_23 = F_8 ( V_21 ) * V_30 ;
} else
V_25 = V_24 ;
F_10 ( & V_28 ) ;
F_11 ( V_25 ) ;
}
F_9 ( & V_28 ) ;
if ( F_12 ( V_29 , V_21 , V_19 ) >= V_21 ) {
F_13 ( V_29 , V_19 , V_20 ) ;
V_22 = 0 ;
} else
V_22 = - V_31 ;
F_10 ( & V_28 ) ;
return V_22 ;
}
static void F_14 ( unsigned int V_19 , unsigned int V_20 )
{
unsigned int V_21 = V_19 + V_20 ;
F_2 ( V_21 > V_23 ) ;
F_9 ( & V_28 ) ;
F_15 ( V_29 , V_19 , V_20 ) ;
F_10 ( & V_28 ) ;
}
static void F_16 ( void * V_32 )
{
struct V_1 * V_2 = (struct V_1 * ) V_32 ;
F_17 ( & V_2 -> V_33 ) ;
}
static int F_18 ( struct V_34 * V_35 , struct V_36 * V_37 )
{
T_1 V_38 = F_19 ( V_35 -> V_39 ) ;
T_1 V_40 = V_38 ;
V_37 -> V_41 = 0xff ;
V_37 -> V_42 = 0x3f ;
F_20 ( V_40 , V_37 -> V_41 * V_37 -> V_42 ) ;
V_37 -> V_40 = V_40 ;
if ( ( T_1 ) ( V_37 -> V_40 + 1 ) * V_37 -> V_41 * V_37 -> V_42 < V_38 )
V_37 -> V_40 = 0xffff ;
return 0 ;
}
static int F_21 ( struct V_34 * V_43 , T_2 V_44 ,
unsigned V_45 , unsigned long V_46 )
{
struct V_1 * V_2 = V_43 -> V_39 -> V_47 ;
int V_48 ;
F_22 ( & V_2 -> V_49 -> V_50 , L_8 ,
V_45 , ( long ) V_46 ) ;
switch ( V_45 ) {
case V_51 :
F_22 ( & V_2 -> V_49 -> V_50 , L_9 ) ;
for ( V_48 = 0 ; V_48 < sizeof( struct V_52 ) ; V_48 ++ )
if ( F_23 ( 0 , ( char V_53 * ) ( V_46 + V_48 ) ) )
return - V_54 ;
return 0 ;
case V_55 : {
struct V_56 * V_57 = V_2 -> V_57 ;
if ( V_57 -> V_58 & V_59 )
return 0 ;
return - V_10 ;
}
default:
return - V_10 ;
}
return 0 ;
}
static int F_24 ( struct V_11 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_60 -> V_47 ;
unsigned long V_61 ;
struct V_62 * V_63 ;
unsigned long V_9 ;
unsigned int V_64 , V_65 ;
int V_48 , V_66 ;
bool V_67 ;
T_3 V_68 ;
struct V_69 * V_70 ;
struct V_71 * V_72 = NULL ;
struct V_73 * V_74 ;
if ( F_25 ( V_2 -> V_75 != V_76 ) )
return 1 ;
if ( V_2 -> V_77 < V_78 ) {
V_67 = 1 ;
if ( F_26 (
V_78 - V_2 -> V_77 ,
& V_68 ) < 0 ) {
F_27 (
& V_2 -> V_79 ,
F_16 ,
V_2 ,
V_78 ) ;
return 1 ;
}
} else
V_67 = 0 ;
V_63 = F_28 ( & V_2 -> V_80 , V_2 -> V_80 . V_81 ) ;
V_9 = F_1 ( V_2 ) ;
V_2 -> V_5 [ V_9 ] . V_11 = V_6 ;
V_63 -> V_7 . V_8 . V_9 = V_9 ;
V_63 -> V_7 . V_8 . V_82 = ( V_83 ) F_29 ( V_6 ) ;
V_63 -> V_7 . V_8 . V_84 = V_2 -> V_84 ;
V_63 -> V_85 = F_30 ( V_6 ) ?
V_15 : V_14 ;
if ( V_6 -> V_86 & ( V_87 | V_88 ) ) {
V_63 -> V_85 = V_2 -> V_89 ;
}
if ( F_25 ( V_6 -> V_86 & ( V_90 | V_91 ) ) ) {
V_63 -> V_85 = V_18 ;
V_63 -> V_7 . V_92 . V_93 = F_31 ( V_6 ) ;
if ( ( V_6 -> V_86 & V_91 ) && V_2 -> V_94 )
V_63 -> V_7 . V_92 . V_95 = V_96 ;
else
V_63 -> V_7 . V_92 . V_95 = 0 ;
} else {
V_63 -> V_7 . V_8 . V_97 = F_32 ( V_6 -> V_98 , V_6 ,
V_2 -> V_74 ) ;
F_2 ( V_63 -> V_7 . V_8 . V_97 >
V_78 ) ;
F_33 (info->sg, sg, ring_req->u.rw.nr_segments, i) {
V_64 = V_74 -> V_99 >> 9 ;
V_65 = V_64 + ( V_74 -> V_100 >> 9 ) - 1 ;
if ( V_2 -> V_77 ) {
F_2 ( F_34 ( & V_2 -> V_101 ) ) ;
V_72 = F_35 (
F_36 ( & V_2 -> V_101 ) ,
struct V_71 , V_102 ) ;
V_66 = V_72 -> V_103 ;
V_61 = F_37 ( V_72 -> V_104 ) ;
V_2 -> V_77 -- ;
} else {
V_66 = F_38 ( & V_68 ) ;
F_2 ( V_66 == - V_105 ) ;
V_72 =
F_39 ( sizeof( struct V_71 ) ,
V_106 ) ;
if ( ! V_72 )
return - V_27 ;
V_70 = F_40 ( V_106 ) ;
if ( ! V_70 ) {
F_11 ( V_72 ) ;
return - V_27 ;
}
V_72 -> V_104 =
F_41 ( V_70 ) ;
V_72 -> V_103 = V_66 ;
V_61 = F_37 ( F_41 (
V_70 ) ) ;
F_42 ( V_66 ,
V_2 -> V_49 -> V_107 ,
V_61 , 0 ) ;
}
V_2 -> V_5 [ V_9 ] . V_108 [ V_48 ] = V_72 ;
if ( F_30 ( V_6 ) ) {
char * V_109 ;
void * V_110 ;
F_2 ( V_74 -> V_99 + V_74 -> V_100 > V_111 ) ;
V_110 = F_43 (
F_44 ( V_72 -> V_104 ) ) ;
V_109 = F_43 ( F_45 ( V_74 ) ) ;
memcpy ( V_110 + V_74 -> V_99 ,
V_109 + V_74 -> V_99 ,
V_74 -> V_100 ) ;
F_46 ( V_109 ) ;
F_46 ( V_110 ) ;
}
V_2 -> V_5 [ V_9 ] . V_112 [ V_48 ] = F_47 ( V_61 ) ;
V_63 -> V_7 . V_8 . V_113 [ V_48 ] =
(struct V_114 ) {
. V_103 = V_66 ,
. V_115 = V_64 ,
. V_116 = V_65 } ;
}
}
V_2 -> V_80 . V_81 ++ ;
V_2 -> V_5 [ V_9 ] . V_6 = * V_63 ;
if ( V_67 )
F_48 ( V_68 ) ;
return 0 ;
}
static inline void F_49 ( struct V_1 * V_2 )
{
int V_117 ;
F_50 ( & V_2 -> V_80 , V_117 ) ;
if ( V_117 )
F_51 ( V_2 -> V_118 ) ;
}
static void F_52 ( struct V_119 * V_120 )
{
struct V_1 * V_2 = NULL ;
struct V_11 * V_6 ;
int V_121 ;
F_53 ( L_10 ) ;
V_121 = 0 ;
while ( ( V_6 = F_54 ( V_120 ) ) != NULL ) {
V_2 = V_6 -> V_60 -> V_47 ;
if ( F_55 ( & V_2 -> V_80 ) )
goto V_122;
F_56 ( V_6 ) ;
if ( ( V_6 -> V_123 != V_124 ) ||
( ( V_6 -> V_86 & ( V_87 | V_88 ) ) &&
! V_2 -> V_89 ) ) {
F_57 ( V_6 , - V_125 ) ;
continue;
}
F_53 ( L_11
L_12 ,
V_6 , V_6 -> V_126 , ( unsigned long ) F_29 ( V_6 ) ,
F_58 ( V_6 ) , F_31 ( V_6 ) ,
V_6 -> V_127 , F_30 ( V_6 ) ? L_2 : L_1 ) ;
if ( F_24 ( V_6 ) ) {
F_59 ( V_120 , V_6 ) ;
V_122:
F_60 ( V_120 ) ;
break;
}
V_121 ++ ;
}
if ( V_121 != 0 )
F_49 ( V_2 ) ;
}
static int F_61 ( struct V_56 * V_57 , T_4 V_128 )
{
struct V_119 * V_120 ;
struct V_1 * V_2 = V_57 -> V_47 ;
V_120 = F_62 ( F_52 , & V_2 -> V_129 ) ;
if ( V_120 == NULL )
return - 1 ;
F_63 ( V_130 , V_120 ) ;
if ( V_2 -> V_131 ) {
F_63 ( V_132 , V_120 ) ;
F_64 ( V_120 , F_19 ( V_57 ) ) ;
V_120 -> V_133 . V_134 = V_2 -> V_134 ;
V_120 -> V_133 . V_135 = V_2 -> V_135 ;
if ( V_2 -> V_94 )
F_63 ( V_136 , V_120 ) ;
}
F_65 ( V_120 , V_128 ) ;
F_66 ( V_120 , 512 ) ;
F_67 ( V_120 , V_111 - 1 ) ;
F_68 ( V_120 , V_111 ) ;
F_69 ( V_120 , V_78 ) ;
F_70 ( V_120 , 511 ) ;
F_71 ( V_120 , V_137 ) ;
V_57 -> V_138 = V_120 ;
return 0 ;
}
static void F_72 ( struct V_1 * V_2 )
{
F_73 ( V_2 -> V_120 , V_2 -> V_139 ) ;
F_74 ( V_140 L_13 ,
V_2 -> V_57 -> V_141 ,
V_2 -> V_89 == V_16 ?
L_3 : ( V_2 -> V_89 == V_17 ?
L_14 : L_15 ) ,
V_2 -> V_139 ? L_16 : L_17 ,
V_2 -> V_142 ? L_18 : L_19 ) ;
}
static int F_75 ( int V_143 , int * V_19 , unsigned int * V_99 )
{
int V_144 ;
V_144 = F_76 ( V_143 ) ;
* V_19 = F_77 ( V_143 ) ;
switch ( V_144 ) {
case V_145 :
* V_99 = ( * V_19 / 64 ) + V_146 ;
* V_19 = ( ( * V_19 / 64 ) * V_147 ) +
V_148 ;
break;
case V_149 :
* V_99 = ( * V_19 / 64 ) + 2 + V_146 ;
* V_19 = ( ( ( * V_19 / 64 ) + 2 ) * V_147 ) +
V_148 ;
break;
case V_150 :
* V_99 = ( * V_19 / V_147 ) + V_151 ;
* V_19 = * V_19 + V_152 ;
break;
case V_153 :
case V_154 :
case V_155 :
case V_156 :
case V_157 :
case V_158 :
case V_159 :
* V_99 = ( * V_19 / V_147 ) +
( ( V_144 - V_153 + 1 ) * 16 ) +
V_151 ;
* V_19 = * V_19 +
( ( V_144 - V_153 + 1 ) * 16 * V_147 ) +
V_152 ;
break;
case V_160 :
case V_161 :
case V_162 :
case V_163 :
case V_164 :
case V_165 :
case V_166 :
case V_167 :
* V_99 = ( * V_19 / V_147 ) +
( ( V_144 - V_160 + 8 ) * 16 ) +
V_151 ;
* V_19 = * V_19 +
( ( V_144 - V_160 + 8 ) * 16 * V_147 ) +
V_152 ;
break;
case V_168 :
* V_99 = * V_19 / V_147 ;
break;
default:
F_74 ( V_169 L_20
L_21 ) ;
return - V_170 ;
}
return 0 ;
}
static char * F_78 ( char * V_171 , unsigned int V_172 )
{
if ( V_172 >= 26 )
V_171 = F_78 ( V_171 , V_172 / 26 - 1 ) ;
* V_171 = 'a' + V_172 % 26 ;
return V_171 + 1 ;
}
static int F_79 ( V_83 V_173 ,
struct V_1 * V_2 ,
T_4 V_174 , T_4 V_128 )
{
struct V_56 * V_57 ;
int V_23 = 1 ;
int V_175 ;
unsigned int V_99 ;
int V_19 ;
int V_176 ;
char * V_171 ;
F_2 ( V_2 -> V_57 != NULL ) ;
F_2 ( V_2 -> V_120 != NULL ) ;
if ( ( V_2 -> V_143 >> V_177 ) > 1 ) {
F_74 ( V_169 L_22 , V_2 -> V_143 ) ;
return - V_170 ;
}
if ( ! F_80 ( V_2 -> V_143 ) ) {
V_175 = F_75 ( V_2 -> V_143 , & V_19 , & V_99 ) ;
if ( V_175 )
return V_175 ;
V_176 = V_147 ;
} else {
V_19 = F_81 ( V_2 -> V_143 ) ;
V_176 = V_178 ;
V_99 = V_19 / V_176 ;
if ( F_82 () && V_99 < V_146 + 4 )
F_74 ( V_169 L_23
L_24
L_25 , V_2 -> V_143 ) ;
}
if ( V_19 >> V_179 ) {
F_83 ( L_26 ,
V_2 -> V_143 , V_19 ) ;
return - V_170 ;
}
if ( ( V_19 % V_176 ) == 0 )
V_23 = V_176 ;
V_175 = F_6 ( V_19 , V_23 ) ;
if ( V_175 )
goto V_180;
V_175 = - V_170 ;
V_57 = F_84 ( V_23 ) ;
if ( V_57 == NULL )
goto V_181;
strcpy ( V_57 -> V_141 , V_182 ) ;
V_171 = F_78 ( V_57 -> V_141 + sizeof( V_182 ) - 1 , V_99 ) ;
F_2 ( V_171 >= V_57 -> V_141 + V_183 ) ;
if ( V_23 > 1 )
* V_171 = 0 ;
else
snprintf ( V_171 , V_57 -> V_141 + V_183 - V_171 ,
L_27 , V_19 & ( V_176 - 1 ) ) ;
V_57 -> V_144 = V_168 ;
V_57 -> V_184 = V_19 ;
V_57 -> V_185 = & V_186 ;
V_57 -> V_47 = V_2 ;
V_57 -> V_187 = & ( V_2 -> V_49 -> V_50 ) ;
F_85 ( V_57 , V_173 ) ;
if ( F_61 ( V_57 , V_128 ) ) {
F_86 ( V_57 ) ;
goto V_181;
}
V_2 -> V_120 = V_57 -> V_138 ;
V_2 -> V_57 = V_57 ;
F_72 ( V_2 ) ;
if ( V_174 & V_188 )
F_87 ( V_57 , 1 ) ;
if ( V_174 & V_189 )
V_57 -> V_58 |= V_190 ;
if ( V_174 & V_191 )
V_57 -> V_58 |= V_59 ;
return 0 ;
V_181:
F_14 ( V_19 , V_23 ) ;
V_180:
return V_175 ;
}
static void F_88 ( struct V_1 * V_2 )
{
unsigned int V_19 , V_23 ;
unsigned long V_58 ;
if ( V_2 -> V_120 == NULL )
return;
F_89 ( & V_2 -> V_129 , V_58 ) ;
F_60 ( V_2 -> V_120 ) ;
F_90 ( & V_2 -> V_79 ) ;
F_91 ( & V_2 -> V_129 , V_58 ) ;
F_92 ( & V_2 -> V_33 ) ;
F_86 ( V_2 -> V_57 ) ;
V_19 = V_2 -> V_57 -> V_184 ;
V_23 = V_2 -> V_57 -> V_29 ;
F_14 ( V_19 , V_23 ) ;
F_93 ( V_2 -> V_120 ) ;
V_2 -> V_120 = NULL ;
F_94 ( V_2 -> V_57 ) ;
V_2 -> V_57 = NULL ;
}
static void F_95 ( struct V_1 * V_2 )
{
if ( ! F_55 ( & V_2 -> V_80 ) ) {
F_96 ( V_2 -> V_120 ) ;
F_52 ( V_2 -> V_120 ) ;
}
}
static void F_97 ( struct V_192 * V_33 )
{
struct V_1 * V_2 = F_98 ( V_33 , struct V_1 , V_33 ) ;
F_99 ( & V_2 -> V_129 ) ;
if ( V_2 -> V_75 == V_76 )
F_95 ( V_2 ) ;
F_100 ( & V_2 -> V_129 ) ;
}
static void F_101 ( struct V_1 * V_2 , int V_193 )
{
struct V_194 * V_195 ;
struct V_71 * V_196 ;
struct V_194 * V_172 ;
F_99 ( & V_2 -> V_129 ) ;
V_2 -> V_75 = V_193 ?
V_197 : V_198 ;
if ( V_2 -> V_120 )
F_60 ( V_2 -> V_120 ) ;
if ( V_2 -> V_77 ) {
V_195 = F_102 ( & V_2 -> V_101 ) ;
F_103 (persistent_gnt, n, all_gnts, node) {
F_104 ( V_196 -> V_103 , 0 , 0UL ) ;
F_105 ( F_44 ( V_196 -> V_104 ) ) ;
F_11 ( V_196 ) ;
}
V_2 -> V_77 = 0 ;
}
F_90 ( & V_2 -> V_79 ) ;
F_100 ( & V_2 -> V_129 ) ;
F_92 ( & V_2 -> V_33 ) ;
if ( V_2 -> V_199 != V_200 ) {
F_104 ( V_2 -> V_199 , 0 ,
( unsigned long ) V_2 -> V_80 . V_201 ) ;
V_2 -> V_199 = V_200 ;
V_2 -> V_80 . V_201 = NULL ;
}
if ( V_2 -> V_118 )
F_106 ( V_2 -> V_118 , V_2 ) ;
V_2 -> V_202 = V_2 -> V_118 = 0 ;
}
static void F_107 ( struct V_203 * V_204 , struct V_1 * V_2 ,
struct V_205 * V_206 )
{
int V_48 = 0 ;
struct V_207 * V_208 ;
struct V_209 V_210 ;
unsigned long V_58 ;
char * V_109 ;
void * V_110 ;
unsigned int V_99 = 0 ;
if ( V_206 -> V_85 == V_14 ) {
F_108 (bvec, s->request, iter) {
F_2 ( ( V_208 -> V_211 + V_208 -> V_212 ) > V_111 ) ;
if ( V_208 -> V_211 < V_99 )
V_48 ++ ;
F_2 ( V_48 >= V_204 -> V_6 . V_7 . V_8 . V_97 ) ;
V_110 = F_43 (
F_44 ( V_204 -> V_108 [ V_48 ] -> V_104 ) ) ;
V_109 = F_109 ( V_208 , & V_58 ) ;
memcpy ( V_109 , V_110 + V_208 -> V_211 ,
V_208 -> V_212 ) ;
F_110 ( V_109 , & V_58 ) ;
F_46 ( V_110 ) ;
V_99 = V_208 -> V_211 + V_208 -> V_212 ;
}
}
for ( V_48 = 0 ; V_48 < V_204 -> V_6 . V_7 . V_8 . V_97 ; V_48 ++ ) {
F_111 ( & V_204 -> V_108 [ V_48 ] -> V_102 , & V_2 -> V_101 ) ;
V_2 -> V_77 ++ ;
}
}
static T_5 F_112 ( int V_118 , void * V_213 )
{
struct V_11 * V_6 ;
struct V_205 * V_206 ;
T_6 V_48 , V_214 ;
unsigned long V_58 ;
struct V_1 * V_2 = (struct V_1 * ) V_213 ;
int error ;
F_89 ( & V_2 -> V_129 , V_58 ) ;
if ( F_25 ( V_2 -> V_75 != V_76 ) ) {
F_91 ( & V_2 -> V_129 , V_58 ) ;
return V_215 ;
}
V_216:
V_214 = V_2 -> V_80 . V_201 -> V_217 ;
F_113 () ;
for ( V_48 = V_2 -> V_80 . V_218 ; V_48 != V_214 ; V_48 ++ ) {
unsigned long V_9 ;
V_206 = F_114 ( & V_2 -> V_80 , V_48 ) ;
V_9 = V_206 -> V_9 ;
if ( V_9 >= V_4 ) {
F_115 ( 1 , L_28 ,
V_2 -> V_57 -> V_141 , F_4 ( V_206 -> V_85 ) , V_9 ) ;
continue;
}
V_6 = V_2 -> V_5 [ V_9 ] . V_11 ;
if ( V_206 -> V_85 != V_18 )
F_107 ( & V_2 -> V_5 [ V_9 ] , V_2 , V_206 ) ;
if ( F_3 ( V_2 , V_9 ) ) {
F_115 ( 1 , L_29 ,
V_2 -> V_57 -> V_141 , F_4 ( V_206 -> V_85 ) , V_9 ) ;
continue;
}
error = ( V_206 -> V_219 == V_220 ) ? 0 : - V_125 ;
switch ( V_206 -> V_85 ) {
case V_18 :
if ( F_25 ( V_206 -> V_219 == V_221 ) ) {
struct V_119 * V_120 = V_2 -> V_120 ;
F_74 ( V_169 L_30 ,
V_2 -> V_57 -> V_141 , F_4 ( V_206 -> V_85 ) ) ;
error = - V_222 ;
V_2 -> V_131 = 0 ;
V_2 -> V_94 = 0 ;
F_116 ( V_132 , V_120 ) ;
F_116 ( V_136 , V_120 ) ;
}
F_57 ( V_6 , error ) ;
break;
case V_17 :
case V_16 :
if ( F_25 ( V_206 -> V_219 == V_221 ) ) {
F_74 ( V_169 L_30 ,
V_2 -> V_57 -> V_141 , F_4 ( V_206 -> V_85 ) ) ;
error = - V_222 ;
}
if ( F_25 ( V_206 -> V_219 == V_223 &&
V_2 -> V_5 [ V_9 ] . V_6 . V_7 . V_8 . V_97 == 0 ) ) {
F_74 ( V_169 L_31 ,
V_2 -> V_57 -> V_141 , F_4 ( V_206 -> V_85 ) ) ;
error = - V_222 ;
}
if ( F_25 ( error ) ) {
if ( error == - V_222 )
error = 0 ;
V_2 -> V_139 = 0 ;
V_2 -> V_89 = 0 ;
F_72 ( V_2 ) ;
}
case V_14 :
case V_15 :
if ( F_25 ( V_206 -> V_219 != V_220 ) )
F_22 ( & V_2 -> V_49 -> V_50 , L_32
L_33 , V_206 -> V_219 ) ;
F_57 ( V_6 , error ) ;
break;
default:
F_117 () ;
}
}
V_2 -> V_80 . V_218 = V_48 ;
if ( V_48 != V_2 -> V_80 . V_81 ) {
int V_224 ;
F_118 ( & V_2 -> V_80 , V_224 ) ;
if ( V_224 )
goto V_216;
} else
V_2 -> V_80 . V_201 -> V_225 = V_48 + 1 ;
F_95 ( V_2 ) ;
F_91 ( & V_2 -> V_129 , V_58 ) ;
return V_215 ;
}
static int F_119 ( struct V_226 * V_50 ,
struct V_1 * V_2 )
{
struct V_227 * V_201 ;
int V_175 ;
V_2 -> V_199 = V_200 ;
V_201 = (struct V_227 * ) F_120 ( V_228 | V_229 ) ;
if ( ! V_201 ) {
F_121 ( V_50 , - V_27 , L_34 ) ;
return - V_27 ;
}
F_122 ( V_201 ) ;
F_123 ( & V_2 -> V_80 , V_201 , V_111 ) ;
F_124 ( V_2 -> V_74 , V_78 ) ;
V_175 = F_125 ( V_50 , F_126 ( V_2 -> V_80 . V_201 ) ) ;
if ( V_175 < 0 ) {
F_127 ( ( unsigned long ) V_201 ) ;
V_2 -> V_80 . V_201 = NULL ;
goto V_230;
}
V_2 -> V_199 = V_175 ;
V_175 = F_128 ( V_50 , & V_2 -> V_202 ) ;
if ( V_175 )
goto V_230;
V_175 = F_129 ( V_2 -> V_202 , F_112 , 0 ,
L_35 , V_2 ) ;
if ( V_175 <= 0 ) {
F_121 ( V_50 , V_175 ,
L_36 ) ;
goto V_230;
}
V_2 -> V_118 = V_175 ;
return 0 ;
V_230:
F_101 ( V_2 , 0 ) ;
return V_175 ;
}
static int F_130 ( struct V_226 * V_50 ,
struct V_1 * V_2 )
{
const char * V_231 = NULL ;
struct V_232 V_233 ;
int V_175 ;
V_175 = F_119 ( V_50 , V_2 ) ;
if ( V_175 )
goto V_180;
V_216:
V_175 = F_131 ( & V_233 ) ;
if ( V_175 ) {
F_121 ( V_50 , V_175 , L_37 ) ;
goto V_234;
}
V_175 = F_132 ( V_233 , V_50 -> V_235 ,
L_38 , L_39 , V_2 -> V_199 ) ;
if ( V_175 ) {
V_231 = L_40 ;
goto V_236;
}
V_175 = F_132 ( V_233 , V_50 -> V_235 ,
L_41 , L_39 , V_2 -> V_202 ) ;
if ( V_175 ) {
V_231 = L_42 ;
goto V_236;
}
V_175 = F_132 ( V_233 , V_50 -> V_235 , L_43 , L_44 ,
V_237 ) ;
if ( V_175 ) {
V_231 = L_45 ;
goto V_236;
}
V_175 = F_132 ( V_233 , V_50 -> V_235 ,
L_46 , L_39 , 1 ) ;
if ( V_175 )
F_133 ( & V_50 -> V_50 ,
L_47 ) ;
V_175 = F_134 ( V_233 , 0 ) ;
if ( V_175 ) {
if ( V_175 == - V_238 )
goto V_216;
F_121 ( V_50 , V_175 , L_48 ) ;
goto V_234;
}
F_135 ( V_50 , V_239 ) ;
return 0 ;
V_236:
F_134 ( V_233 , 1 ) ;
if ( V_231 )
F_121 ( V_50 , V_175 , L_44 , V_231 ) ;
V_234:
F_101 ( V_2 , 0 ) ;
V_180:
return V_175 ;
}
static int F_136 ( struct V_226 * V_50 ,
const struct V_240 * V_9 )
{
int V_175 , V_143 , V_48 ;
struct V_1 * V_2 ;
V_175 = F_137 ( V_241 , V_50 -> V_235 ,
L_49 , L_50 , & V_143 ) ;
if ( V_175 != 1 ) {
V_175 = F_137 ( V_241 , V_50 -> V_235 , L_51 ,
L_50 , & V_143 ) ;
if ( V_175 != 1 ) {
F_121 ( V_50 , V_175 , L_52 ) ;
return V_175 ;
}
}
if ( F_82 () ) {
char * type ;
int V_242 ;
if ( V_243 & V_244 ) {
int V_144 ;
if ( ! F_80 ( V_143 ) )
V_144 = F_76 ( V_143 ) ;
else
V_144 = V_168 ;
if ( V_144 != V_168 ) {
F_74 ( V_140
L_53 ,
V_245 , V_143 ) ;
return - V_170 ;
}
}
type = F_138 ( V_241 , V_50 -> V_235 , L_54 , & V_242 ) ;
if ( F_139 ( type ) )
return - V_170 ;
if ( strncmp ( type , L_55 , 5 ) == 0 ) {
F_11 ( type ) ;
return - V_170 ;
}
F_11 ( type ) ;
}
V_2 = F_140 ( sizeof( * V_2 ) , V_26 ) ;
if ( ! V_2 ) {
F_121 ( V_50 , - V_27 , L_56 ) ;
return - V_27 ;
}
F_141 ( & V_2 -> V_246 ) ;
F_142 ( & V_2 -> V_129 ) ;
V_2 -> V_49 = V_50 ;
V_2 -> V_143 = V_143 ;
F_143 ( & V_2 -> V_101 ) ;
V_2 -> V_77 = 0 ;
V_2 -> V_75 = V_198 ;
F_144 ( & V_2 -> V_33 , F_97 ) ;
for ( V_48 = 0 ; V_48 < V_4 ; V_48 ++ )
V_2 -> V_5 [ V_48 ] . V_6 . V_7 . V_8 . V_9 = V_48 + 1 ;
V_2 -> V_5 [ V_4 - 1 ] . V_6 . V_7 . V_8 . V_9 = 0x0fffffff ;
V_2 -> V_84 = F_145 ( strrchr ( V_50 -> V_235 , '/' ) + 1 , NULL , 0 ) ;
F_146 ( & V_50 -> V_50 , V_2 ) ;
V_175 = F_130 ( V_50 , V_2 ) ;
if ( V_175 ) {
F_11 ( V_2 ) ;
F_146 ( & V_50 -> V_50 , NULL ) ;
return V_175 ;
}
return 0 ;
}
static int F_147 ( struct V_1 * V_2 )
{
int V_48 ;
struct V_62 * V_6 ;
struct V_203 * V_247 ;
int V_248 ;
V_247 = F_39 ( sizeof( V_2 -> V_5 ) ,
V_228 | V_249 | V_229 ) ;
if ( ! V_247 )
return - V_27 ;
memcpy ( V_247 , V_2 -> V_5 , sizeof( V_2 -> V_5 ) ) ;
memset ( & V_2 -> V_5 , 0 , sizeof( V_2 -> V_5 ) ) ;
for ( V_48 = 0 ; V_48 < V_4 ; V_48 ++ )
V_2 -> V_5 [ V_48 ] . V_6 . V_7 . V_8 . V_9 = V_48 + 1 ;
V_2 -> V_3 = V_2 -> V_80 . V_81 ;
V_2 -> V_5 [ V_4 - 1 ] . V_6 . V_7 . V_8 . V_9 = 0x0fffffff ;
for ( V_48 = 0 ; V_48 < V_4 ; V_48 ++ ) {
if ( ! V_247 [ V_48 ] . V_11 )
continue;
V_6 = F_28 ( & V_2 -> V_80 , V_2 -> V_80 . V_81 ) ;
* V_6 = V_247 [ V_48 ] . V_6 ;
V_6 -> V_7 . V_8 . V_9 = F_1 ( V_2 ) ;
memcpy ( & V_2 -> V_5 [ V_6 -> V_7 . V_8 . V_9 ] , & V_247 [ V_48 ] , sizeof( V_247 [ V_48 ] ) ) ;
if ( V_6 -> V_85 != V_18 ) {
for ( V_248 = 0 ; V_248 < V_6 -> V_7 . V_8 . V_97 ; V_248 ++ )
F_42 (
V_6 -> V_7 . V_8 . V_113 [ V_248 ] . V_103 ,
V_2 -> V_49 -> V_107 ,
F_37 ( V_2 -> V_5 [ V_6 -> V_7 . V_8 . V_9 ] . V_112 [ V_248 ] ) ,
0 ) ;
}
V_2 -> V_5 [ V_6 -> V_7 . V_8 . V_9 ] . V_6 = * V_6 ;
V_2 -> V_80 . V_81 ++ ;
}
F_11 ( V_247 ) ;
F_135 ( V_2 -> V_49 , V_250 ) ;
F_99 ( & V_2 -> V_129 ) ;
V_2 -> V_75 = V_76 ;
F_49 ( V_2 ) ;
F_95 ( V_2 ) ;
F_100 ( & V_2 -> V_129 ) ;
return 0 ;
}
static int F_148 ( struct V_226 * V_50 )
{
struct V_1 * V_2 = F_149 ( & V_50 -> V_50 ) ;
int V_175 ;
F_22 ( & V_50 -> V_50 , L_57 , V_50 -> V_235 ) ;
F_101 ( V_2 , V_2 -> V_75 == V_76 ) ;
V_175 = F_130 ( V_50 , V_2 ) ;
if ( V_2 -> V_75 == V_197 && ! V_175 )
V_175 = F_147 ( V_2 ) ;
return V_175 ;
}
static void
F_150 ( struct V_1 * V_2 )
{
struct V_226 * V_49 = V_2 -> V_49 ;
struct V_34 * V_43 = NULL ;
F_151 ( & V_2 -> V_246 ) ;
if ( V_49 -> V_251 == V_252 ) {
F_152 ( & V_2 -> V_246 ) ;
return;
}
if ( V_2 -> V_57 )
V_43 = F_153 ( V_2 -> V_57 , 0 ) ;
F_152 ( & V_2 -> V_246 ) ;
if ( ! V_43 ) {
F_154 ( V_49 ) ;
return;
}
F_151 ( & V_43 -> V_253 ) ;
if ( V_43 -> V_254 ) {
F_155 ( V_49 , - V_31 ,
L_58 ) ;
F_135 ( V_49 , V_252 ) ;
} else {
F_88 ( V_2 ) ;
F_154 ( V_49 ) ;
}
F_152 ( & V_43 -> V_253 ) ;
F_156 ( V_43 ) ;
}
static void F_157 ( struct V_1 * V_2 )
{
int V_175 ;
char * type ;
unsigned int V_134 ;
unsigned int V_135 ;
unsigned int V_255 ;
type = F_138 ( V_241 , V_2 -> V_49 -> V_256 , L_59 , NULL ) ;
if ( F_139 ( type ) )
return;
V_2 -> V_94 = 0 ;
if ( strncmp ( type , L_60 , 3 ) == 0 ) {
V_175 = F_158 ( V_241 , V_2 -> V_49 -> V_256 ,
L_61 , L_39 , & V_134 ,
L_62 , L_39 , & V_135 ,
NULL ) ;
if ( ! V_175 ) {
V_2 -> V_131 = 1 ;
V_2 -> V_134 = V_134 ;
V_2 -> V_135 = V_135 ;
}
V_175 = F_158 ( V_241 , V_2 -> V_49 -> V_256 ,
L_63 , L_27 , & V_255 ,
NULL ) ;
if ( ! V_175 )
V_2 -> V_94 = V_255 ;
} else if ( strncmp ( type , L_64 , 4 ) == 0 )
V_2 -> V_131 = 1 ;
F_11 ( type ) ;
}
static void F_159 ( struct V_1 * V_2 )
{
unsigned long long V_42 ;
unsigned long V_128 ;
unsigned int V_257 ;
int V_175 ;
int V_258 , V_259 , V_92 , V_260 ;
switch ( V_2 -> V_75 ) {
case V_76 :
V_175 = F_137 ( V_241 , V_2 -> V_49 -> V_256 ,
L_65 , L_66 , & V_42 ) ;
if ( F_160 ( V_175 ) )
return;
F_74 ( V_140 L_67 ,
V_42 ) ;
F_85 ( V_2 -> V_57 , V_42 ) ;
F_161 ( V_2 -> V_57 ) ;
case V_197 :
return;
default:
break;
}
F_22 ( & V_2 -> V_49 -> V_50 , L_68 ,
V_261 , V_2 -> V_49 -> V_256 ) ;
V_175 = F_158 ( V_241 , V_2 -> V_49 -> V_256 ,
L_65 , L_69 , & V_42 ,
L_70 , L_39 , & V_257 ,
L_71 , L_72 , & V_128 ,
NULL ) ;
if ( V_175 ) {
F_121 ( V_2 -> V_49 , V_175 ,
L_73 ,
V_2 -> V_49 -> V_256 ) ;
return;
}
V_2 -> V_139 = 0 ;
V_2 -> V_89 = 0 ;
V_175 = F_158 ( V_241 , V_2 -> V_49 -> V_256 ,
L_74 , L_27 , & V_258 ,
NULL ) ;
if ( ! V_175 && V_258 ) {
V_2 -> V_139 = V_87 | V_88 ;
V_2 -> V_89 = V_16 ;
}
V_175 = F_158 ( V_241 , V_2 -> V_49 -> V_256 ,
L_75 , L_27 , & V_259 ,
NULL ) ;
if ( ! V_175 && V_259 ) {
V_2 -> V_139 = V_87 ;
V_2 -> V_89 = V_17 ;
}
V_175 = F_158 ( V_241 , V_2 -> V_49 -> V_256 ,
L_76 , L_27 , & V_92 ,
NULL ) ;
if ( ! V_175 && V_92 )
F_157 ( V_2 ) ;
V_175 = F_158 ( V_241 , V_2 -> V_49 -> V_256 ,
L_46 , L_39 , & V_260 ,
NULL ) ;
if ( V_175 )
V_2 -> V_142 = 0 ;
else
V_2 -> V_142 = V_260 ;
V_175 = F_79 ( V_42 , V_2 , V_257 , V_128 ) ;
if ( V_175 ) {
F_121 ( V_2 -> V_49 , V_175 , L_77 ,
V_2 -> V_49 -> V_256 ) ;
return;
}
F_135 ( V_2 -> V_49 , V_250 ) ;
F_99 ( & V_2 -> V_129 ) ;
V_2 -> V_75 = V_76 ;
F_95 ( V_2 ) ;
F_100 ( & V_2 -> V_129 ) ;
F_162 ( V_2 -> V_57 ) ;
V_2 -> V_262 = 1 ;
}
static void F_163 ( struct V_226 * V_50 ,
enum V_263 V_264 )
{
struct V_1 * V_2 = F_149 ( & V_50 -> V_50 ) ;
F_22 ( & V_50 -> V_50 , L_78 , V_264 ) ;
switch ( V_264 ) {
case V_265 :
case V_266 :
case V_239 :
case V_267 :
case V_268 :
case V_269 :
case V_270 :
break;
case V_250 :
F_159 ( V_2 ) ;
break;
case V_252 :
F_150 ( V_2 ) ;
break;
}
}
static int F_164 ( struct V_226 * V_49 )
{
struct V_1 * V_2 = F_149 ( & V_49 -> V_50 ) ;
struct V_34 * V_43 = NULL ;
struct V_56 * V_271 ;
F_22 ( & V_49 -> V_50 , L_79 , V_49 -> V_235 ) ;
F_101 ( V_2 , 0 ) ;
F_151 ( & V_2 -> V_246 ) ;
V_271 = V_2 -> V_57 ;
if ( V_271 )
V_43 = F_153 ( V_271 , 0 ) ;
V_2 -> V_49 = NULL ;
F_152 ( & V_2 -> V_246 ) ;
if ( ! V_43 ) {
F_11 ( V_2 ) ;
return 0 ;
}
F_151 ( & V_43 -> V_253 ) ;
V_2 = V_271 -> V_47 ;
F_133 ( F_165 ( V_271 ) ,
L_80 ,
V_49 -> V_235 , V_43 -> V_254 ) ;
if ( V_2 && ! V_43 -> V_254 ) {
F_88 ( V_2 ) ;
V_271 -> V_47 = NULL ;
F_11 ( V_2 ) ;
}
F_152 ( & V_43 -> V_253 ) ;
F_156 ( V_43 ) ;
return 0 ;
}
static int F_166 ( struct V_226 * V_50 )
{
struct V_1 * V_2 = F_149 ( & V_50 -> V_50 ) ;
return V_2 -> V_262 && V_2 -> V_49 ;
}
static int F_167 ( struct V_34 * V_43 , T_2 V_44 )
{
struct V_56 * V_271 = V_43 -> V_39 ;
struct V_1 * V_2 ;
int V_175 = 0 ;
F_151 ( & V_272 ) ;
V_2 = V_271 -> V_47 ;
if ( ! V_2 ) {
V_175 = - V_273 ;
goto V_180;
}
F_151 ( & V_2 -> V_246 ) ;
if ( ! V_2 -> V_57 )
V_175 = - V_273 ;
F_152 ( & V_2 -> V_246 ) ;
V_180:
F_152 ( & V_272 ) ;
return V_175 ;
}
static int F_168 ( struct V_56 * V_271 , T_2 V_44 )
{
struct V_1 * V_2 = V_271 -> V_47 ;
struct V_34 * V_43 ;
struct V_226 * V_49 ;
F_151 ( & V_272 ) ;
V_43 = F_153 ( V_271 , 0 ) ;
if ( V_43 -> V_254 )
goto V_180;
F_151 ( & V_2 -> V_246 ) ;
V_49 = V_2 -> V_49 ;
if ( V_49 && V_49 -> V_251 == V_252 ) {
F_169 ( F_165 ( V_43 -> V_39 ) , L_81 ) ;
F_88 ( V_2 ) ;
F_154 ( V_2 -> V_49 ) ;
}
F_152 ( & V_2 -> V_246 ) ;
if ( ! V_49 ) {
F_169 ( F_165 ( V_43 -> V_39 ) , L_81 ) ;
F_88 ( V_2 ) ;
V_271 -> V_47 = NULL ;
F_11 ( V_2 ) ;
}
V_180:
F_156 ( V_43 ) ;
F_152 ( & V_272 ) ;
return 0 ;
}
static int T_7 F_170 ( void )
{
int V_274 ;
if ( ! F_171 () )
return - V_170 ;
if ( F_82 () && ! V_243 )
return - V_170 ;
if ( F_172 ( V_168 , V_182 ) ) {
F_74 ( V_169 L_82 ,
V_168 , V_182 ) ;
return - V_170 ;
}
V_274 = F_173 ( & V_275 ) ;
if ( V_274 ) {
F_174 ( V_168 , V_182 ) ;
return V_274 ;
}
return 0 ;
}
static void T_8 F_175 ( void )
{
F_176 ( & V_275 ) ;
F_174 ( V_168 , V_182 ) ;
F_11 ( V_29 ) ;
}
