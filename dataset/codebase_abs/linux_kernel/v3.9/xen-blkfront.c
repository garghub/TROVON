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
static int F_4 ( struct V_1 * V_2 , int V_12 )
{
struct V_13 * V_14 ;
struct V_15 * V_16 , * V_17 ;
int V_18 = 0 ;
while( V_18 < V_12 ) {
V_16 = F_5 ( sizeof( struct V_15 ) , V_19 ) ;
if ( ! V_16 )
goto V_20;
V_14 = F_6 ( V_19 ) ;
if ( ! V_14 ) {
F_7 ( V_16 ) ;
goto V_20;
}
V_16 -> V_21 = F_8 ( V_14 ) ;
V_16 -> V_22 = V_23 ;
F_9 ( & V_16 -> V_24 , & V_2 -> V_25 ) ;
V_18 ++ ;
}
return 0 ;
V_20:
F_10 (gnt_list_entry, n,
&info->persistent_gnts, node) {
F_11 ( & V_16 -> V_24 ) ;
F_12 ( F_13 ( V_16 -> V_21 ) ) ;
F_7 ( V_16 ) ;
V_18 -- ;
}
F_2 ( V_18 != 0 ) ;
return - V_26 ;
}
static struct V_15 * F_14 ( T_1 * V_27 ,
struct V_1 * V_2 )
{
struct V_15 * V_16 ;
unsigned long V_28 ;
F_2 ( F_15 ( & V_2 -> V_25 ) ) ;
V_16 = F_16 ( & V_2 -> V_25 , struct V_15 ,
V_24 ) ;
F_11 ( & V_16 -> V_24 ) ;
if ( V_16 -> V_22 != V_23 ) {
V_2 -> V_29 -- ;
return V_16 ;
}
V_16 -> V_22 = F_17 ( V_27 ) ;
F_2 ( V_16 -> V_22 == - V_30 ) ;
V_28 = F_18 ( V_16 -> V_21 ) ;
F_19 ( V_16 -> V_22 ,
V_2 -> V_31 -> V_32 ,
V_28 , 0 ) ;
return V_16 ;
}
static const char * F_20 ( int V_33 )
{
static const char * const V_34 [] = {
[ V_35 ] = L_1 ,
[ V_36 ] = L_2 ,
[ V_37 ] = L_3 ,
[ V_38 ] = L_4 ,
[ V_39 ] = L_5 } ;
if ( V_33 < 0 || V_33 >= F_21 ( V_34 ) )
return L_6 ;
if ( ! V_34 [ V_33 ] )
return L_7 ;
return V_34 [ V_33 ] ;
}
static int F_22 ( unsigned int V_40 , unsigned int V_41 )
{
unsigned int V_42 = V_40 + V_41 ;
int V_43 ;
if ( V_42 > V_44 ) {
unsigned long * V_45 , * V_46 ;
V_45 = F_23 ( F_24 ( V_42 ) , sizeof( * V_45 ) ,
V_47 ) ;
if ( V_45 == NULL )
return - V_26 ;
F_25 ( & V_48 ) ;
if ( V_42 > V_44 ) {
V_46 = V_49 ;
memcpy ( V_45 , V_49 ,
F_24 ( V_44 ) * sizeof( * V_45 ) ) ;
V_49 = V_45 ;
V_44 = F_24 ( V_42 ) * V_50 ;
} else
V_46 = V_45 ;
F_26 ( & V_48 ) ;
F_7 ( V_46 ) ;
}
F_25 ( & V_48 ) ;
if ( F_27 ( V_49 , V_42 , V_40 ) >= V_42 ) {
F_28 ( V_49 , V_40 , V_41 ) ;
V_43 = 0 ;
} else
V_43 = - V_51 ;
F_26 ( & V_48 ) ;
return V_43 ;
}
static void F_29 ( unsigned int V_40 , unsigned int V_41 )
{
unsigned int V_42 = V_40 + V_41 ;
F_2 ( V_42 > V_44 ) ;
F_25 ( & V_48 ) ;
F_30 ( V_49 , V_40 , V_41 ) ;
F_26 ( & V_48 ) ;
}
static void F_31 ( void * V_52 )
{
struct V_1 * V_2 = (struct V_1 * ) V_52 ;
F_32 ( & V_2 -> V_53 ) ;
}
static int F_33 ( struct V_54 * V_55 , struct V_56 * V_57 )
{
T_2 V_58 = F_34 ( V_55 -> V_59 ) ;
T_2 V_60 = V_58 ;
V_57 -> V_61 = 0xff ;
V_57 -> V_62 = 0x3f ;
F_35 ( V_60 , V_57 -> V_61 * V_57 -> V_62 ) ;
V_57 -> V_60 = V_60 ;
if ( ( T_2 ) ( V_57 -> V_60 + 1 ) * V_57 -> V_61 * V_57 -> V_62 < V_58 )
V_57 -> V_60 = 0xffff ;
return 0 ;
}
static int F_36 ( struct V_54 * V_63 , T_3 V_64 ,
unsigned V_65 , unsigned long V_66 )
{
struct V_1 * V_2 = V_63 -> V_59 -> V_67 ;
int V_18 ;
F_37 ( & V_2 -> V_31 -> V_68 , L_8 ,
V_65 , ( long ) V_66 ) ;
switch ( V_65 ) {
case V_69 :
F_37 ( & V_2 -> V_31 -> V_68 , L_9 ) ;
for ( V_18 = 0 ; V_18 < sizeof( struct V_70 ) ; V_18 ++ )
if ( F_38 ( 0 , ( char V_71 * ) ( V_66 + V_18 ) ) )
return - V_72 ;
return 0 ;
case V_73 : {
struct V_74 * V_75 = V_2 -> V_75 ;
if ( V_75 -> V_76 & V_77 )
return 0 ;
return - V_10 ;
}
default:
return - V_10 ;
}
return 0 ;
}
static int F_39 ( struct V_11 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_78 -> V_67 ;
struct V_79 * V_80 ;
unsigned long V_9 ;
unsigned int V_81 , V_82 ;
int V_18 , V_83 ;
bool V_84 ;
T_1 V_27 ;
struct V_15 * V_16 = NULL ;
struct V_85 * V_86 ;
if ( F_40 ( V_2 -> V_87 != V_88 ) )
return 1 ;
if ( V_2 -> V_29 < V_89 ) {
V_84 = 1 ;
if ( F_41 (
V_89 - V_2 -> V_29 ,
& V_27 ) < 0 ) {
F_42 (
& V_2 -> V_90 ,
F_31 ,
V_2 ,
V_89 ) ;
return 1 ;
}
} else
V_84 = 0 ;
V_80 = F_43 ( & V_2 -> V_91 , V_2 -> V_91 . V_92 ) ;
V_9 = F_1 ( V_2 ) ;
V_2 -> V_5 [ V_9 ] . V_11 = V_6 ;
V_80 -> V_7 . V_8 . V_9 = V_9 ;
V_80 -> V_7 . V_8 . V_93 = ( V_94 ) F_44 ( V_6 ) ;
V_80 -> V_7 . V_8 . V_95 = V_2 -> V_95 ;
V_80 -> V_96 = F_45 ( V_6 ) ?
V_36 : V_35 ;
if ( V_6 -> V_97 & ( V_98 | V_99 ) ) {
V_80 -> V_96 = V_2 -> V_100 ;
}
if ( F_40 ( V_6 -> V_97 & ( V_101 | V_102 ) ) ) {
V_80 -> V_96 = V_39 ;
V_80 -> V_7 . V_103 . V_104 = F_46 ( V_6 ) ;
if ( ( V_6 -> V_97 & V_102 ) && V_2 -> V_105 )
V_80 -> V_7 . V_103 . V_106 = V_107 ;
else
V_80 -> V_7 . V_103 . V_106 = 0 ;
} else {
V_80 -> V_7 . V_8 . V_108 = F_47 ( V_6 -> V_109 , V_6 ,
V_2 -> V_86 ) ;
F_2 ( V_80 -> V_7 . V_8 . V_108 >
V_89 ) ;
F_48 (info->sg, sg, ring_req->u.rw.nr_segments, i) {
V_81 = V_86 -> V_110 >> 9 ;
V_82 = V_81 + ( V_86 -> V_111 >> 9 ) - 1 ;
V_16 = F_14 ( & V_27 , V_2 ) ;
V_83 = V_16 -> V_22 ;
V_2 -> V_5 [ V_9 ] . V_112 [ V_18 ] = V_16 ;
if ( F_45 ( V_6 ) ) {
char * V_113 ;
void * V_114 ;
F_2 ( V_86 -> V_110 + V_86 -> V_111 > V_115 ) ;
V_114 = F_49 (
F_13 ( V_16 -> V_21 ) ) ;
V_113 = F_49 ( F_50 ( V_86 ) ) ;
memcpy ( V_114 + V_86 -> V_110 ,
V_113 + V_86 -> V_110 ,
V_86 -> V_111 ) ;
F_51 ( V_113 ) ;
F_51 ( V_114 ) ;
}
V_80 -> V_7 . V_8 . V_116 [ V_18 ] =
(struct V_117 ) {
. V_22 = V_83 ,
. V_118 = V_81 ,
. V_119 = V_82 } ;
}
}
V_2 -> V_91 . V_92 ++ ;
V_2 -> V_5 [ V_9 ] . V_6 = * V_80 ;
if ( V_84 )
F_52 ( V_27 ) ;
return 0 ;
}
static inline void F_53 ( struct V_1 * V_2 )
{
int V_120 ;
F_54 ( & V_2 -> V_91 , V_120 ) ;
if ( V_120 )
F_55 ( V_2 -> V_121 ) ;
}
static void F_56 ( struct V_122 * V_123 )
{
struct V_1 * V_2 = NULL ;
struct V_11 * V_6 ;
int V_124 ;
F_57 ( L_10 ) ;
V_124 = 0 ;
while ( ( V_6 = F_58 ( V_123 ) ) != NULL ) {
V_2 = V_6 -> V_78 -> V_67 ;
if ( F_59 ( & V_2 -> V_91 ) )
goto V_125;
F_60 ( V_6 ) ;
if ( ( V_6 -> V_126 != V_127 ) ||
( ( V_6 -> V_97 & ( V_98 | V_99 ) ) &&
! V_2 -> V_100 ) ) {
F_61 ( V_6 , - V_128 ) ;
continue;
}
F_57 ( L_11
L_12 ,
V_6 , V_6 -> V_129 , ( unsigned long ) F_44 ( V_6 ) ,
F_62 ( V_6 ) , F_46 ( V_6 ) ,
V_6 -> V_130 , F_45 ( V_6 ) ? L_2 : L_1 ) ;
if ( F_39 ( V_6 ) ) {
F_63 ( V_123 , V_6 ) ;
V_125:
F_64 ( V_123 ) ;
break;
}
V_124 ++ ;
}
if ( V_124 != 0 )
F_53 ( V_2 ) ;
}
static int F_65 ( struct V_74 * V_75 , T_4 V_131 )
{
struct V_122 * V_123 ;
struct V_1 * V_2 = V_75 -> V_67 ;
V_123 = F_66 ( F_56 , & V_2 -> V_132 ) ;
if ( V_123 == NULL )
return - 1 ;
F_67 ( V_133 , V_123 ) ;
if ( V_2 -> V_134 ) {
F_67 ( V_135 , V_123 ) ;
F_68 ( V_123 , F_34 ( V_75 ) ) ;
V_123 -> V_136 . V_137 = V_2 -> V_137 ;
V_123 -> V_136 . V_138 = V_2 -> V_138 ;
if ( V_2 -> V_105 )
F_67 ( V_139 , V_123 ) ;
}
F_69 ( V_123 , V_131 ) ;
F_70 ( V_123 , 512 ) ;
F_71 ( V_123 , V_115 - 1 ) ;
F_72 ( V_123 , V_115 ) ;
F_73 ( V_123 , V_89 ) ;
F_74 ( V_123 , 511 ) ;
F_75 ( V_123 , V_140 ) ;
V_75 -> V_141 = V_123 ;
return 0 ;
}
static void F_76 ( struct V_1 * V_2 )
{
F_77 ( V_2 -> V_123 , V_2 -> V_142 ) ;
F_78 ( V_143 L_13 ,
V_2 -> V_75 -> V_144 ,
V_2 -> V_100 == V_37 ?
L_3 : ( V_2 -> V_100 == V_38 ?
L_14 : L_15 ) ,
V_2 -> V_142 ? L_16 : L_17 ,
V_2 -> V_145 ? L_18 : L_19 ) ;
}
static int F_79 ( int V_146 , int * V_40 , unsigned int * V_110 )
{
int V_147 ;
V_147 = F_80 ( V_146 ) ;
* V_40 = F_81 ( V_146 ) ;
switch ( V_147 ) {
case V_148 :
* V_110 = ( * V_40 / 64 ) + V_149 ;
* V_40 = ( ( * V_40 / 64 ) * V_150 ) +
V_151 ;
break;
case V_152 :
* V_110 = ( * V_40 / 64 ) + 2 + V_149 ;
* V_40 = ( ( ( * V_40 / 64 ) + 2 ) * V_150 ) +
V_151 ;
break;
case V_153 :
* V_110 = ( * V_40 / V_150 ) + V_154 ;
* V_40 = * V_40 + V_155 ;
break;
case V_156 :
case V_157 :
case V_158 :
case V_159 :
case V_160 :
case V_161 :
case V_162 :
* V_110 = ( * V_40 / V_150 ) +
( ( V_147 - V_156 + 1 ) * 16 ) +
V_154 ;
* V_40 = * V_40 +
( ( V_147 - V_156 + 1 ) * 16 * V_150 ) +
V_155 ;
break;
case V_163 :
case V_164 :
case V_165 :
case V_166 :
case V_167 :
case V_168 :
case V_169 :
case V_170 :
* V_110 = ( * V_40 / V_150 ) +
( ( V_147 - V_163 + 8 ) * 16 ) +
V_154 ;
* V_40 = * V_40 +
( ( V_147 - V_163 + 8 ) * 16 * V_150 ) +
V_155 ;
break;
case V_171 :
* V_110 = * V_40 / V_150 ;
break;
default:
F_78 ( V_172 L_20
L_21 ) ;
return - V_173 ;
}
return 0 ;
}
static char * F_82 ( char * V_174 , unsigned int V_17 )
{
if ( V_17 >= 26 )
V_174 = F_82 ( V_174 , V_17 / 26 - 1 ) ;
* V_174 = 'a' + V_17 % 26 ;
return V_174 + 1 ;
}
static int F_83 ( V_94 V_175 ,
struct V_1 * V_2 ,
T_4 V_176 , T_4 V_131 )
{
struct V_74 * V_75 ;
int V_44 = 1 ;
int V_177 ;
unsigned int V_110 ;
int V_40 ;
int V_178 ;
char * V_174 ;
F_2 ( V_2 -> V_75 != NULL ) ;
F_2 ( V_2 -> V_123 != NULL ) ;
if ( ( V_2 -> V_146 >> V_179 ) > 1 ) {
F_78 ( V_172 L_22 , V_2 -> V_146 ) ;
return - V_173 ;
}
if ( ! F_84 ( V_2 -> V_146 ) ) {
V_177 = F_79 ( V_2 -> V_146 , & V_40 , & V_110 ) ;
if ( V_177 )
return V_177 ;
V_178 = V_150 ;
} else {
V_40 = F_85 ( V_2 -> V_146 ) ;
V_178 = V_180 ;
V_110 = V_40 / V_178 ;
if ( F_86 () && V_110 < V_149 + 4 )
F_78 ( V_172 L_23
L_24
L_25 , V_2 -> V_146 ) ;
}
if ( V_40 >> V_181 ) {
F_87 ( L_26 ,
V_2 -> V_146 , V_40 ) ;
return - V_173 ;
}
if ( ( V_40 % V_178 ) == 0 )
V_44 = V_178 ;
V_177 = F_22 ( V_40 , V_44 ) ;
if ( V_177 )
goto V_182;
V_177 = - V_173 ;
V_75 = F_88 ( V_44 ) ;
if ( V_75 == NULL )
goto V_183;
strcpy ( V_75 -> V_144 , V_184 ) ;
V_174 = F_82 ( V_75 -> V_144 + sizeof( V_184 ) - 1 , V_110 ) ;
F_2 ( V_174 >= V_75 -> V_144 + V_185 ) ;
if ( V_44 > 1 )
* V_174 = 0 ;
else
snprintf ( V_174 , V_75 -> V_144 + V_185 - V_174 ,
L_27 , V_40 & ( V_178 - 1 ) ) ;
V_75 -> V_147 = V_171 ;
V_75 -> V_186 = V_40 ;
V_75 -> V_187 = & V_188 ;
V_75 -> V_67 = V_2 ;
V_75 -> V_189 = & ( V_2 -> V_31 -> V_68 ) ;
F_89 ( V_75 , V_175 ) ;
if ( F_65 ( V_75 , V_131 ) ) {
F_90 ( V_75 ) ;
goto V_183;
}
V_2 -> V_123 = V_75 -> V_141 ;
V_2 -> V_75 = V_75 ;
F_76 ( V_2 ) ;
if ( V_176 & V_190 )
F_91 ( V_75 , 1 ) ;
if ( V_176 & V_191 )
V_75 -> V_76 |= V_192 ;
if ( V_176 & V_193 )
V_75 -> V_76 |= V_77 ;
return 0 ;
V_183:
F_29 ( V_40 , V_44 ) ;
V_182:
return V_177 ;
}
static void F_92 ( struct V_1 * V_2 )
{
unsigned int V_40 , V_44 ;
unsigned long V_76 ;
if ( V_2 -> V_123 == NULL )
return;
F_93 ( & V_2 -> V_132 , V_76 ) ;
F_64 ( V_2 -> V_123 ) ;
F_94 ( & V_2 -> V_90 ) ;
F_95 ( & V_2 -> V_132 , V_76 ) ;
F_96 ( & V_2 -> V_53 ) ;
F_90 ( V_2 -> V_75 ) ;
V_40 = V_2 -> V_75 -> V_186 ;
V_44 = V_2 -> V_75 -> V_49 ;
F_29 ( V_40 , V_44 ) ;
F_97 ( V_2 -> V_123 ) ;
V_2 -> V_123 = NULL ;
F_98 ( V_2 -> V_75 ) ;
V_2 -> V_75 = NULL ;
}
static void F_99 ( struct V_1 * V_2 )
{
if ( ! F_59 ( & V_2 -> V_91 ) ) {
F_100 ( V_2 -> V_123 ) ;
F_56 ( V_2 -> V_123 ) ;
}
}
static void F_101 ( struct V_194 * V_53 )
{
struct V_1 * V_2 = F_102 ( V_53 , struct V_1 , V_53 ) ;
F_103 ( & V_2 -> V_132 ) ;
if ( V_2 -> V_87 == V_88 )
F_99 ( V_2 ) ;
F_104 ( & V_2 -> V_132 ) ;
}
static void F_105 ( struct V_1 * V_2 , int V_195 )
{
struct V_15 * V_196 ;
struct V_15 * V_17 ;
F_103 ( & V_2 -> V_132 ) ;
V_2 -> V_87 = V_195 ?
V_197 : V_198 ;
if ( V_2 -> V_123 )
F_64 ( V_2 -> V_123 ) ;
if ( ! F_15 ( & V_2 -> V_25 ) ) {
F_10 (persistent_gnt, n,
&info->persistent_gnts, node) {
F_11 ( & V_196 -> V_24 ) ;
if ( V_196 -> V_22 != V_23 ) {
F_106 ( V_196 -> V_22 ,
0 , 0UL ) ;
V_2 -> V_29 -- ;
}
F_12 ( F_13 ( V_196 -> V_21 ) ) ;
F_7 ( V_196 ) ;
}
}
F_2 ( V_2 -> V_29 != 0 ) ;
F_94 ( & V_2 -> V_90 ) ;
F_104 ( & V_2 -> V_132 ) ;
F_96 ( & V_2 -> V_53 ) ;
if ( V_2 -> V_199 != V_23 ) {
F_106 ( V_2 -> V_199 , 0 ,
( unsigned long ) V_2 -> V_91 . V_200 ) ;
V_2 -> V_199 = V_23 ;
V_2 -> V_91 . V_200 = NULL ;
}
if ( V_2 -> V_121 )
F_107 ( V_2 -> V_121 , V_2 ) ;
V_2 -> V_201 = V_2 -> V_121 = 0 ;
}
static void F_108 ( struct V_202 * V_203 , struct V_1 * V_2 ,
struct V_204 * V_205 )
{
int V_18 = 0 ;
struct V_206 * V_207 ;
struct V_208 V_209 ;
unsigned long V_76 ;
char * V_113 ;
void * V_114 ;
unsigned int V_110 = 0 ;
if ( V_205 -> V_96 == V_35 ) {
F_109 (bvec, s->request, iter) {
F_2 ( ( V_207 -> V_210 + V_207 -> V_211 ) > V_115 ) ;
if ( V_207 -> V_210 < V_110 )
V_18 ++ ;
F_2 ( V_18 >= V_203 -> V_6 . V_7 . V_8 . V_108 ) ;
V_114 = F_49 (
F_13 ( V_203 -> V_112 [ V_18 ] -> V_21 ) ) ;
V_113 = F_110 ( V_207 , & V_76 ) ;
memcpy ( V_113 , V_114 + V_207 -> V_210 ,
V_207 -> V_211 ) ;
F_111 ( V_113 , & V_76 ) ;
F_51 ( V_114 ) ;
V_110 = V_207 -> V_210 + V_207 -> V_211 ;
}
}
for ( V_18 = 0 ; V_18 < V_203 -> V_6 . V_7 . V_8 . V_108 ; V_18 ++ ) {
F_9 ( & V_203 -> V_112 [ V_18 ] -> V_24 , & V_2 -> V_25 ) ;
V_2 -> V_29 ++ ;
}
}
static T_5 F_112 ( int V_121 , void * V_212 )
{
struct V_11 * V_6 ;
struct V_204 * V_205 ;
T_6 V_18 , V_213 ;
unsigned long V_76 ;
struct V_1 * V_2 = (struct V_1 * ) V_212 ;
int error ;
F_93 ( & V_2 -> V_132 , V_76 ) ;
if ( F_40 ( V_2 -> V_87 != V_88 ) ) {
F_95 ( & V_2 -> V_132 , V_76 ) ;
return V_214 ;
}
V_215:
V_213 = V_2 -> V_91 . V_200 -> V_216 ;
F_113 () ;
for ( V_18 = V_2 -> V_91 . V_217 ; V_18 != V_213 ; V_18 ++ ) {
unsigned long V_9 ;
V_205 = F_114 ( & V_2 -> V_91 , V_18 ) ;
V_9 = V_205 -> V_9 ;
if ( V_9 >= V_4 ) {
F_115 ( 1 , L_28 ,
V_2 -> V_75 -> V_144 , F_20 ( V_205 -> V_96 ) , V_9 ) ;
continue;
}
V_6 = V_2 -> V_5 [ V_9 ] . V_11 ;
if ( V_205 -> V_96 != V_39 )
F_108 ( & V_2 -> V_5 [ V_9 ] , V_2 , V_205 ) ;
if ( F_3 ( V_2 , V_9 ) ) {
F_115 ( 1 , L_29 ,
V_2 -> V_75 -> V_144 , F_20 ( V_205 -> V_96 ) , V_9 ) ;
continue;
}
error = ( V_205 -> V_218 == V_219 ) ? 0 : - V_128 ;
switch ( V_205 -> V_96 ) {
case V_39 :
if ( F_40 ( V_205 -> V_218 == V_220 ) ) {
struct V_122 * V_123 = V_2 -> V_123 ;
F_78 ( V_172 L_30 ,
V_2 -> V_75 -> V_144 , F_20 ( V_205 -> V_96 ) ) ;
error = - V_221 ;
V_2 -> V_134 = 0 ;
V_2 -> V_105 = 0 ;
F_116 ( V_135 , V_123 ) ;
F_116 ( V_139 , V_123 ) ;
}
F_61 ( V_6 , error ) ;
break;
case V_38 :
case V_37 :
if ( F_40 ( V_205 -> V_218 == V_220 ) ) {
F_78 ( V_172 L_30 ,
V_2 -> V_75 -> V_144 , F_20 ( V_205 -> V_96 ) ) ;
error = - V_221 ;
}
if ( F_40 ( V_205 -> V_218 == V_222 &&
V_2 -> V_5 [ V_9 ] . V_6 . V_7 . V_8 . V_108 == 0 ) ) {
F_78 ( V_172 L_31 ,
V_2 -> V_75 -> V_144 , F_20 ( V_205 -> V_96 ) ) ;
error = - V_221 ;
}
if ( F_40 ( error ) ) {
if ( error == - V_221 )
error = 0 ;
V_2 -> V_142 = 0 ;
V_2 -> V_100 = 0 ;
F_76 ( V_2 ) ;
}
case V_35 :
case V_36 :
if ( F_40 ( V_205 -> V_218 != V_219 ) )
F_37 ( & V_2 -> V_31 -> V_68 , L_32
L_33 , V_205 -> V_218 ) ;
F_61 ( V_6 , error ) ;
break;
default:
F_117 () ;
}
}
V_2 -> V_91 . V_217 = V_18 ;
if ( V_18 != V_2 -> V_91 . V_92 ) {
int V_223 ;
F_118 ( & V_2 -> V_91 , V_223 ) ;
if ( V_223 )
goto V_215;
} else
V_2 -> V_91 . V_200 -> V_224 = V_18 + 1 ;
F_99 ( V_2 ) ;
F_95 ( & V_2 -> V_132 , V_76 ) ;
return V_214 ;
}
static int F_119 ( struct V_225 * V_68 ,
struct V_1 * V_2 )
{
struct V_226 * V_200 ;
int V_177 ;
V_2 -> V_199 = V_23 ;
V_200 = (struct V_226 * ) F_120 ( V_19 | V_227 ) ;
if ( ! V_200 ) {
F_121 ( V_68 , - V_26 , L_34 ) ;
return - V_26 ;
}
F_122 ( V_200 ) ;
F_123 ( & V_2 -> V_91 , V_200 , V_115 ) ;
F_124 ( V_2 -> V_86 , V_89 ) ;
V_177 = F_4 ( V_2 , V_4 *
V_89 ) ;
if ( V_177 )
goto V_228;
V_177 = F_125 ( V_68 , F_126 ( V_2 -> V_91 . V_200 ) ) ;
if ( V_177 < 0 ) {
F_127 ( ( unsigned long ) V_200 ) ;
V_2 -> V_91 . V_200 = NULL ;
goto V_228;
}
V_2 -> V_199 = V_177 ;
V_177 = F_128 ( V_68 , & V_2 -> V_201 ) ;
if ( V_177 )
goto V_228;
V_177 = F_129 ( V_2 -> V_201 , F_112 , 0 ,
L_35 , V_2 ) ;
if ( V_177 <= 0 ) {
F_121 ( V_68 , V_177 ,
L_36 ) ;
goto V_228;
}
V_2 -> V_121 = V_177 ;
return 0 ;
V_228:
F_105 ( V_2 , 0 ) ;
return V_177 ;
}
static int F_130 ( struct V_225 * V_68 ,
struct V_1 * V_2 )
{
const char * V_229 = NULL ;
struct V_230 V_231 ;
int V_177 ;
V_177 = F_119 ( V_68 , V_2 ) ;
if ( V_177 )
goto V_182;
V_215:
V_177 = F_131 ( & V_231 ) ;
if ( V_177 ) {
F_121 ( V_68 , V_177 , L_37 ) ;
goto V_232;
}
V_177 = F_132 ( V_231 , V_68 -> V_233 ,
L_38 , L_39 , V_2 -> V_199 ) ;
if ( V_177 ) {
V_229 = L_40 ;
goto V_234;
}
V_177 = F_132 ( V_231 , V_68 -> V_233 ,
L_41 , L_39 , V_2 -> V_201 ) ;
if ( V_177 ) {
V_229 = L_42 ;
goto V_234;
}
V_177 = F_132 ( V_231 , V_68 -> V_233 , L_43 , L_44 ,
V_235 ) ;
if ( V_177 ) {
V_229 = L_45 ;
goto V_234;
}
V_177 = F_132 ( V_231 , V_68 -> V_233 ,
L_46 , L_39 , 1 ) ;
if ( V_177 )
F_133 ( & V_68 -> V_68 ,
L_47 ) ;
V_177 = F_134 ( V_231 , 0 ) ;
if ( V_177 ) {
if ( V_177 == - V_236 )
goto V_215;
F_121 ( V_68 , V_177 , L_48 ) ;
goto V_232;
}
F_135 ( V_68 , V_237 ) ;
return 0 ;
V_234:
F_134 ( V_231 , 1 ) ;
if ( V_229 )
F_121 ( V_68 , V_177 , L_44 , V_229 ) ;
V_232:
F_105 ( V_2 , 0 ) ;
V_182:
return V_177 ;
}
static int F_136 ( struct V_225 * V_68 ,
const struct V_238 * V_9 )
{
int V_177 , V_146 , V_18 ;
struct V_1 * V_2 ;
V_177 = F_137 ( V_239 , V_68 -> V_233 ,
L_49 , L_50 , & V_146 ) ;
if ( V_177 != 1 ) {
V_177 = F_137 ( V_239 , V_68 -> V_233 , L_51 ,
L_50 , & V_146 ) ;
if ( V_177 != 1 ) {
F_121 ( V_68 , V_177 , L_52 ) ;
return V_177 ;
}
}
if ( F_86 () ) {
char * type ;
int V_240 ;
if ( V_241 & V_242 ) {
int V_147 ;
if ( ! F_84 ( V_146 ) )
V_147 = F_80 ( V_146 ) ;
else
V_147 = V_171 ;
if ( V_147 != V_171 ) {
F_78 ( V_143
L_53 ,
V_243 , V_146 ) ;
return - V_173 ;
}
}
type = F_138 ( V_239 , V_68 -> V_233 , L_54 , & V_240 ) ;
if ( F_139 ( type ) )
return - V_173 ;
if ( strncmp ( type , L_55 , 5 ) == 0 ) {
F_7 ( type ) ;
return - V_173 ;
}
F_7 ( type ) ;
}
V_2 = F_5 ( sizeof( * V_2 ) , V_47 ) ;
if ( ! V_2 ) {
F_121 ( V_68 , - V_26 , L_56 ) ;
return - V_26 ;
}
F_140 ( & V_2 -> V_244 ) ;
F_141 ( & V_2 -> V_132 ) ;
V_2 -> V_31 = V_68 ;
V_2 -> V_146 = V_146 ;
F_142 ( & V_2 -> V_25 ) ;
V_2 -> V_29 = 0 ;
V_2 -> V_87 = V_198 ;
F_143 ( & V_2 -> V_53 , F_101 ) ;
for ( V_18 = 0 ; V_18 < V_4 ; V_18 ++ )
V_2 -> V_5 [ V_18 ] . V_6 . V_7 . V_8 . V_9 = V_18 + 1 ;
V_2 -> V_5 [ V_4 - 1 ] . V_6 . V_7 . V_8 . V_9 = 0x0fffffff ;
V_2 -> V_95 = F_144 ( strrchr ( V_68 -> V_233 , '/' ) + 1 , NULL , 0 ) ;
F_145 ( & V_68 -> V_68 , V_2 ) ;
V_177 = F_130 ( V_68 , V_2 ) ;
if ( V_177 ) {
F_7 ( V_2 ) ;
F_145 ( & V_68 -> V_68 , NULL ) ;
return V_177 ;
}
return 0 ;
}
static int F_146 ( struct V_1 * V_2 )
{
int V_18 ;
struct V_79 * V_6 ;
struct V_202 * V_245 ;
int V_246 ;
V_245 = F_147 ( V_2 -> V_5 , sizeof( V_2 -> V_5 ) ,
V_19 | V_247 | V_227 ) ;
if ( ! V_245 )
return - V_26 ;
memset ( & V_2 -> V_5 , 0 , sizeof( V_2 -> V_5 ) ) ;
for ( V_18 = 0 ; V_18 < V_4 ; V_18 ++ )
V_2 -> V_5 [ V_18 ] . V_6 . V_7 . V_8 . V_9 = V_18 + 1 ;
V_2 -> V_3 = V_2 -> V_91 . V_92 ;
V_2 -> V_5 [ V_4 - 1 ] . V_6 . V_7 . V_8 . V_9 = 0x0fffffff ;
for ( V_18 = 0 ; V_18 < V_4 ; V_18 ++ ) {
if ( ! V_245 [ V_18 ] . V_11 )
continue;
V_6 = F_43 ( & V_2 -> V_91 , V_2 -> V_91 . V_92 ) ;
* V_6 = V_245 [ V_18 ] . V_6 ;
V_6 -> V_7 . V_8 . V_9 = F_1 ( V_2 ) ;
memcpy ( & V_2 -> V_5 [ V_6 -> V_7 . V_8 . V_9 ] , & V_245 [ V_18 ] , sizeof( V_245 [ V_18 ] ) ) ;
if ( V_6 -> V_96 != V_39 ) {
for ( V_246 = 0 ; V_246 < V_6 -> V_7 . V_8 . V_108 ; V_246 ++ )
F_19 (
V_6 -> V_7 . V_8 . V_116 [ V_246 ] . V_22 ,
V_2 -> V_31 -> V_32 ,
F_18 ( V_245 [ V_18 ] . V_112 [ V_246 ] -> V_21 ) ,
0 ) ;
}
V_2 -> V_5 [ V_6 -> V_7 . V_8 . V_9 ] . V_6 = * V_6 ;
V_2 -> V_91 . V_92 ++ ;
}
F_7 ( V_245 ) ;
F_135 ( V_2 -> V_31 , V_248 ) ;
F_103 ( & V_2 -> V_132 ) ;
V_2 -> V_87 = V_88 ;
F_53 ( V_2 ) ;
F_99 ( V_2 ) ;
F_104 ( & V_2 -> V_132 ) ;
return 0 ;
}
static int F_148 ( struct V_225 * V_68 )
{
struct V_1 * V_2 = F_149 ( & V_68 -> V_68 ) ;
int V_177 ;
F_37 ( & V_68 -> V_68 , L_57 , V_68 -> V_233 ) ;
F_105 ( V_2 , V_2 -> V_87 == V_88 ) ;
V_177 = F_130 ( V_68 , V_2 ) ;
if ( V_2 -> V_87 == V_197 && ! V_177 )
V_177 = F_146 ( V_2 ) ;
return V_177 ;
}
static void
F_150 ( struct V_1 * V_2 )
{
struct V_225 * V_31 = V_2 -> V_31 ;
struct V_54 * V_63 = NULL ;
F_151 ( & V_2 -> V_244 ) ;
if ( V_31 -> V_249 == V_250 ) {
F_152 ( & V_2 -> V_244 ) ;
return;
}
if ( V_2 -> V_75 )
V_63 = F_153 ( V_2 -> V_75 , 0 ) ;
F_152 ( & V_2 -> V_244 ) ;
if ( ! V_63 ) {
F_154 ( V_31 ) ;
return;
}
F_151 ( & V_63 -> V_251 ) ;
if ( V_63 -> V_252 ) {
F_155 ( V_31 , - V_51 ,
L_58 ) ;
F_135 ( V_31 , V_250 ) ;
} else {
F_92 ( V_2 ) ;
F_154 ( V_31 ) ;
}
F_152 ( & V_63 -> V_251 ) ;
F_156 ( V_63 ) ;
}
static void F_157 ( struct V_1 * V_2 )
{
int V_177 ;
char * type ;
unsigned int V_137 ;
unsigned int V_138 ;
unsigned int V_253 ;
type = F_138 ( V_239 , V_2 -> V_31 -> V_254 , L_59 , NULL ) ;
if ( F_139 ( type ) )
return;
V_2 -> V_105 = 0 ;
if ( strncmp ( type , L_60 , 3 ) == 0 ) {
V_177 = F_158 ( V_239 , V_2 -> V_31 -> V_254 ,
L_61 , L_39 , & V_137 ,
L_62 , L_39 , & V_138 ,
NULL ) ;
if ( ! V_177 ) {
V_2 -> V_134 = 1 ;
V_2 -> V_137 = V_137 ;
V_2 -> V_138 = V_138 ;
}
V_177 = F_158 ( V_239 , V_2 -> V_31 -> V_254 ,
L_63 , L_27 , & V_253 ,
NULL ) ;
if ( ! V_177 )
V_2 -> V_105 = V_253 ;
} else if ( strncmp ( type , L_64 , 4 ) == 0 )
V_2 -> V_134 = 1 ;
F_7 ( type ) ;
}
static void F_159 ( struct V_1 * V_2 )
{
unsigned long long V_62 ;
unsigned long V_131 ;
unsigned int V_255 ;
int V_177 ;
int V_256 , V_257 , V_103 , V_258 ;
switch ( V_2 -> V_87 ) {
case V_88 :
V_177 = F_137 ( V_239 , V_2 -> V_31 -> V_254 ,
L_65 , L_66 , & V_62 ) ;
if ( F_160 ( V_177 ) )
return;
F_78 ( V_143 L_67 ,
V_62 ) ;
F_89 ( V_2 -> V_75 , V_62 ) ;
F_161 ( V_2 -> V_75 ) ;
case V_197 :
return;
default:
break;
}
F_37 ( & V_2 -> V_31 -> V_68 , L_68 ,
V_259 , V_2 -> V_31 -> V_254 ) ;
V_177 = F_158 ( V_239 , V_2 -> V_31 -> V_254 ,
L_65 , L_69 , & V_62 ,
L_70 , L_39 , & V_255 ,
L_71 , L_72 , & V_131 ,
NULL ) ;
if ( V_177 ) {
F_121 ( V_2 -> V_31 , V_177 ,
L_73 ,
V_2 -> V_31 -> V_254 ) ;
return;
}
V_2 -> V_142 = 0 ;
V_2 -> V_100 = 0 ;
V_177 = F_158 ( V_239 , V_2 -> V_31 -> V_254 ,
L_74 , L_27 , & V_256 ,
NULL ) ;
if ( ! V_177 && V_256 ) {
V_2 -> V_142 = V_98 | V_99 ;
V_2 -> V_100 = V_37 ;
}
V_177 = F_158 ( V_239 , V_2 -> V_31 -> V_254 ,
L_75 , L_27 , & V_257 ,
NULL ) ;
if ( ! V_177 && V_257 ) {
V_2 -> V_142 = V_98 ;
V_2 -> V_100 = V_38 ;
}
V_177 = F_158 ( V_239 , V_2 -> V_31 -> V_254 ,
L_76 , L_27 , & V_103 ,
NULL ) ;
if ( ! V_177 && V_103 )
F_157 ( V_2 ) ;
V_177 = F_158 ( V_239 , V_2 -> V_31 -> V_254 ,
L_46 , L_39 , & V_258 ,
NULL ) ;
if ( V_177 )
V_2 -> V_145 = 0 ;
else
V_2 -> V_145 = V_258 ;
V_177 = F_83 ( V_62 , V_2 , V_255 , V_131 ) ;
if ( V_177 ) {
F_121 ( V_2 -> V_31 , V_177 , L_77 ,
V_2 -> V_31 -> V_254 ) ;
return;
}
F_135 ( V_2 -> V_31 , V_248 ) ;
F_103 ( & V_2 -> V_132 ) ;
V_2 -> V_87 = V_88 ;
F_99 ( V_2 ) ;
F_104 ( & V_2 -> V_132 ) ;
F_162 ( V_2 -> V_75 ) ;
V_2 -> V_260 = 1 ;
}
static void F_163 ( struct V_225 * V_68 ,
enum V_261 V_262 )
{
struct V_1 * V_2 = F_149 ( & V_68 -> V_68 ) ;
F_37 ( & V_68 -> V_68 , L_78 , V_262 ) ;
switch ( V_262 ) {
case V_263 :
case V_264 :
case V_237 :
case V_265 :
case V_266 :
case V_267 :
case V_268 :
break;
case V_248 :
F_159 ( V_2 ) ;
break;
case V_250 :
F_150 ( V_2 ) ;
break;
}
}
static int F_164 ( struct V_225 * V_31 )
{
struct V_1 * V_2 = F_149 ( & V_31 -> V_68 ) ;
struct V_54 * V_63 = NULL ;
struct V_74 * V_269 ;
F_37 ( & V_31 -> V_68 , L_79 , V_31 -> V_233 ) ;
F_105 ( V_2 , 0 ) ;
F_151 ( & V_2 -> V_244 ) ;
V_269 = V_2 -> V_75 ;
if ( V_269 )
V_63 = F_153 ( V_269 , 0 ) ;
V_2 -> V_31 = NULL ;
F_152 ( & V_2 -> V_244 ) ;
if ( ! V_63 ) {
F_7 ( V_2 ) ;
return 0 ;
}
F_151 ( & V_63 -> V_251 ) ;
V_2 = V_269 -> V_67 ;
F_133 ( F_165 ( V_269 ) ,
L_80 ,
V_31 -> V_233 , V_63 -> V_252 ) ;
if ( V_2 && ! V_63 -> V_252 ) {
F_92 ( V_2 ) ;
V_269 -> V_67 = NULL ;
F_7 ( V_2 ) ;
}
F_152 ( & V_63 -> V_251 ) ;
F_156 ( V_63 ) ;
return 0 ;
}
static int F_166 ( struct V_225 * V_68 )
{
struct V_1 * V_2 = F_149 ( & V_68 -> V_68 ) ;
return V_2 -> V_260 && V_2 -> V_31 ;
}
static int F_167 ( struct V_54 * V_63 , T_3 V_64 )
{
struct V_74 * V_269 = V_63 -> V_59 ;
struct V_1 * V_2 ;
int V_177 = 0 ;
F_151 ( & V_270 ) ;
V_2 = V_269 -> V_67 ;
if ( ! V_2 ) {
V_177 = - V_271 ;
goto V_182;
}
F_151 ( & V_2 -> V_244 ) ;
if ( ! V_2 -> V_75 )
V_177 = - V_271 ;
F_152 ( & V_2 -> V_244 ) ;
V_182:
F_152 ( & V_270 ) ;
return V_177 ;
}
static int F_168 ( struct V_74 * V_269 , T_3 V_64 )
{
struct V_1 * V_2 = V_269 -> V_67 ;
struct V_54 * V_63 ;
struct V_225 * V_31 ;
F_151 ( & V_270 ) ;
V_63 = F_153 ( V_269 , 0 ) ;
if ( V_63 -> V_252 )
goto V_182;
F_151 ( & V_2 -> V_244 ) ;
V_31 = V_2 -> V_31 ;
if ( V_31 && V_31 -> V_249 == V_250 ) {
F_169 ( F_165 ( V_63 -> V_59 ) , L_81 ) ;
F_92 ( V_2 ) ;
F_154 ( V_2 -> V_31 ) ;
}
F_152 ( & V_2 -> V_244 ) ;
if ( ! V_31 ) {
F_169 ( F_165 ( V_63 -> V_59 ) , L_81 ) ;
F_92 ( V_2 ) ;
V_269 -> V_67 = NULL ;
F_7 ( V_2 ) ;
}
V_182:
F_156 ( V_63 ) ;
F_152 ( & V_270 ) ;
return 0 ;
}
static int T_7 F_170 ( void )
{
int V_272 ;
if ( ! F_171 () )
return - V_173 ;
if ( F_86 () && ! V_241 )
return - V_173 ;
if ( F_172 ( V_171 , V_184 ) ) {
F_78 ( V_172 L_82 ,
V_171 , V_184 ) ;
return - V_173 ;
}
V_272 = F_173 ( & V_273 ) ;
if ( V_272 ) {
F_174 ( V_171 , V_184 ) ;
return V_272 ;
}
return 0 ;
}
static void T_8 F_175 ( void )
{
F_176 ( & V_273 ) ;
F_174 ( V_171 , V_184 ) ;
F_7 ( V_49 ) ;
}
