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
V_15 -> V_12 = V_13 ;
}
V_15 -> V_21 = V_22 ;
F_9 ( & V_15 -> V_23 , & V_2 -> V_24 ) ;
V_17 ++ ;
}
return 0 ;
V_19:
F_10 (gnt_list_entry, n,
&info->grants, node) {
F_11 ( & V_15 -> V_23 ) ;
if ( V_2 -> V_20 )
F_12 ( V_15 -> V_12 ) ;
F_8 ( V_15 ) ;
V_17 -- ;
}
F_2 ( V_17 != 0 ) ;
return - V_25 ;
}
static struct V_14 * F_13 ( struct V_1 * V_2 )
{
struct V_14 * V_15 ;
F_2 ( F_14 ( & V_2 -> V_24 ) ) ;
V_15 = F_15 ( & V_2 -> V_24 , struct V_14 ,
V_23 ) ;
F_11 ( & V_15 -> V_23 ) ;
if ( V_15 -> V_21 != V_22 )
V_2 -> V_26 -- ;
return V_15 ;
}
static inline void F_16 ( const struct V_14 * V_15 ,
const struct V_1 * V_2 )
{
F_17 ( V_15 -> V_21 ,
V_2 -> V_27 -> V_28 ,
V_15 -> V_12 ,
0 ) ;
}
static struct V_14 * F_18 ( T_1 * V_29 ,
unsigned long V_30 ,
struct V_1 * V_2 )
{
struct V_14 * V_15 = F_13 ( V_2 ) ;
if ( V_15 -> V_21 != V_22 )
return V_15 ;
V_15 -> V_21 = F_19 ( V_29 ) ;
F_2 ( V_15 -> V_21 == - V_31 ) ;
if ( V_2 -> V_20 )
F_16 ( V_15 , V_2 ) ;
else {
F_20 ( V_15 -> V_21 ,
V_2 -> V_27 -> V_28 ,
V_30 , 0 ) ;
}
return V_15 ;
}
static struct V_14 * F_21 ( T_1 * V_29 ,
struct V_1 * V_2 )
{
struct V_14 * V_15 = F_13 ( V_2 ) ;
if ( V_15 -> V_21 != V_22 )
return V_15 ;
V_15 -> V_21 = F_19 ( V_29 ) ;
F_2 ( V_15 -> V_21 == - V_31 ) ;
if ( ! V_2 -> V_20 ) {
struct V_12 * V_32 ;
F_2 ( F_14 ( & V_2 -> V_33 ) ) ;
V_32 = F_15 ( & V_2 -> V_33 ,
struct V_12 , V_34 ) ;
F_11 ( & V_32 -> V_34 ) ;
V_15 -> V_12 = V_32 ;
}
F_16 ( V_15 , V_2 ) ;
return V_15 ;
}
static const char * F_22 ( int V_35 )
{
static const char * const V_36 [] = {
[ V_37 ] = L_1 ,
[ V_38 ] = L_2 ,
[ V_39 ] = L_3 ,
[ V_40 ] = L_4 ,
[ V_41 ] = L_5 } ;
if ( V_35 < 0 || V_35 >= F_23 ( V_36 ) )
return L_6 ;
if ( ! V_36 [ V_35 ] )
return L_7 ;
return V_36 [ V_35 ] ;
}
static int F_24 ( unsigned int V_42 , unsigned int V_43 )
{
unsigned int V_44 = V_42 + V_43 ;
int V_45 ;
if ( V_44 > V_46 ) {
unsigned long * V_47 , * V_48 ;
V_47 = F_25 ( F_26 ( V_44 ) , sizeof( * V_47 ) ,
V_49 ) ;
if ( V_47 == NULL )
return - V_25 ;
F_27 ( & V_50 ) ;
if ( V_44 > V_46 ) {
V_48 = V_51 ;
memcpy ( V_47 , V_51 ,
F_26 ( V_46 ) * sizeof( * V_47 ) ) ;
V_51 = V_47 ;
V_46 = F_26 ( V_44 ) * V_52 ;
} else
V_48 = V_47 ;
F_28 ( & V_50 ) ;
F_8 ( V_48 ) ;
}
F_27 ( & V_50 ) ;
if ( F_29 ( V_51 , V_44 , V_42 ) >= V_44 ) {
F_30 ( V_51 , V_42 , V_43 ) ;
V_45 = 0 ;
} else
V_45 = - V_53 ;
F_28 ( & V_50 ) ;
return V_45 ;
}
static void F_31 ( unsigned int V_42 , unsigned int V_43 )
{
unsigned int V_44 = V_42 + V_43 ;
F_2 ( V_44 > V_46 ) ;
F_27 ( & V_50 ) ;
F_32 ( V_51 , V_42 , V_43 ) ;
F_28 ( & V_50 ) ;
}
static void F_33 ( void * V_54 )
{
struct V_1 * V_2 = (struct V_1 * ) V_54 ;
F_34 ( & V_2 -> V_55 ) ;
}
static int F_35 ( struct V_56 * V_57 , struct V_58 * V_59 )
{
T_2 V_60 = F_36 ( V_57 -> V_61 ) ;
T_2 V_62 = V_60 ;
V_59 -> V_63 = 0xff ;
V_59 -> V_64 = 0x3f ;
F_37 ( V_62 , V_59 -> V_63 * V_59 -> V_64 ) ;
V_59 -> V_62 = V_62 ;
if ( ( T_2 ) ( V_59 -> V_62 + 1 ) * V_59 -> V_63 * V_59 -> V_64 < V_60 )
V_59 -> V_62 = 0xffff ;
return 0 ;
}
static int F_38 ( struct V_56 * V_65 , T_3 V_66 ,
unsigned V_67 , unsigned long V_68 )
{
struct V_1 * V_2 = V_65 -> V_61 -> V_69 ;
int V_17 ;
F_39 ( & V_2 -> V_27 -> V_70 , L_8 ,
V_67 , ( long ) V_68 ) ;
switch ( V_67 ) {
case V_71 :
F_39 ( & V_2 -> V_27 -> V_70 , L_9 ) ;
for ( V_17 = 0 ; V_17 < sizeof( struct V_72 ) ; V_17 ++ )
if ( F_40 ( 0 , ( char V_73 * ) ( V_68 + V_17 ) ) )
return - V_74 ;
return 0 ;
case V_75 : {
struct V_76 * V_77 = V_2 -> V_77 ;
if ( V_77 -> V_78 & V_79 )
return 0 ;
return - V_9 ;
}
default:
return - V_9 ;
}
return 0 ;
}
static int F_41 ( struct V_10 * V_5 )
{
struct V_1 * V_2 = V_5 -> V_80 -> V_69 ;
struct V_81 * V_82 ;
unsigned long V_8 ;
V_82 = F_42 ( & V_2 -> V_83 , V_2 -> V_83 . V_84 ) ;
V_8 = F_1 ( V_2 ) ;
V_2 -> V_4 [ V_8 ] . V_10 = V_5 ;
V_82 -> V_85 = V_41 ;
V_82 -> V_6 . V_86 . V_87 = F_43 ( V_5 ) ;
V_82 -> V_6 . V_86 . V_8 = V_8 ;
V_82 -> V_6 . V_86 . V_88 = ( V_89 ) F_44 ( V_5 ) ;
if ( ( V_5 -> V_90 & V_91 ) && V_2 -> V_92 )
V_82 -> V_6 . V_86 . V_93 = V_94 ;
else
V_82 -> V_6 . V_86 . V_93 = 0 ;
V_2 -> V_83 . V_84 ++ ;
V_2 -> V_4 [ V_8 ] . V_5 = * V_82 ;
return 0 ;
}
static void F_45 ( unsigned long V_30 , unsigned int V_95 ,
unsigned int V_96 , void * V_97 )
{
struct V_98 * V_99 = V_97 ;
int V_16 , V_100 ;
struct V_14 * V_15 ;
unsigned int V_101 , V_102 ;
unsigned int V_103 = V_99 -> V_103 ;
struct V_81 * V_82 = V_99 -> V_82 ;
struct V_1 * V_2 = V_99 -> V_2 ;
struct V_104 * V_4 = & V_2 -> V_4 [ V_99 -> V_8 ] ;
if ( ( V_82 -> V_85 == V_105 ) &&
( V_103 % V_106 == 0 ) ) {
if ( V_99 -> V_107 )
F_46 ( V_99 -> V_107 ) ;
V_16 = V_103 / V_106 ;
V_15 = F_21 ( & V_99 -> V_29 , V_2 ) ;
V_4 -> V_108 [ V_16 ] = V_15 ;
V_99 -> V_107 = F_47 ( V_15 -> V_12 ) ;
V_82 -> V_6 . V_109 . V_110 [ V_16 ] = V_15 -> V_21 ;
}
V_15 = F_18 ( & V_99 -> V_29 , V_30 , V_2 ) ;
V_100 = V_15 -> V_21 ;
V_4 -> V_111 [ V_103 ] = V_15 ;
if ( V_99 -> V_112 ) {
void * V_113 ;
V_113 = F_47 ( V_15 -> V_12 ) ;
memcpy ( V_113 + V_95 ,
V_99 -> V_114 + V_99 -> V_115 ,
V_96 ) ;
F_46 ( V_113 ) ;
V_99 -> V_115 += V_96 ;
}
V_101 = V_95 >> 9 ;
V_102 = V_101 + ( V_96 >> 9 ) - 1 ;
if ( V_82 -> V_85 != V_105 ) {
V_82 -> V_6 . V_7 . V_116 [ V_103 ] =
(struct V_117 ) {
. V_21 = V_100 ,
. V_118 = V_101 ,
. V_119 = V_102 } ;
} else {
V_99 -> V_107 [ V_103 % V_106 ] =
(struct V_117 ) {
. V_21 = V_100 ,
. V_118 = V_101 ,
. V_119 = V_102 } ;
}
( V_99 -> V_103 ) ++ ;
}
static int F_48 ( struct V_10 * V_5 )
{
struct V_1 * V_2 = V_5 -> V_80 -> V_69 ;
struct V_81 * V_82 ;
unsigned long V_8 ;
int V_17 ;
struct V_98 V_99 = {
. V_103 = 0 ,
. V_107 = NULL ,
. V_2 = V_2 ,
. V_112 = F_49 ( V_5 ) && V_2 -> V_20 ,
} ;
bool V_120 ;
struct V_121 * V_122 ;
int V_123 , V_124 , V_125 ;
V_124 = V_5 -> V_126 * V_127 ;
if ( V_124 > V_128 )
V_124 += F_50 ( V_124 ) ;
if ( V_2 -> V_26 < V_124 ) {
V_120 = 1 ;
if ( F_51 (
V_124 - V_2 -> V_26 ,
& V_99 . V_29 ) < 0 ) {
F_52 (
& V_2 -> V_129 ,
F_33 ,
V_2 ,
V_124 ) ;
return 1 ;
}
} else
V_120 = 0 ;
V_82 = F_42 ( & V_2 -> V_83 , V_2 -> V_83 . V_84 ) ;
V_8 = F_1 ( V_2 ) ;
V_2 -> V_4 [ V_8 ] . V_10 = V_5 ;
F_2 ( V_2 -> V_130 == 0 &&
F_53 ( V_5 -> V_126 ) > V_128 ) ;
F_2 ( V_2 -> V_130 &&
F_53 ( V_5 -> V_126 ) > V_2 -> V_130 ) ;
V_123 = F_54 ( V_5 -> V_131 , V_5 , V_2 -> V_4 [ V_8 ] . V_122 ) ;
V_125 = 0 ;
F_55 (info->shadow[id].sg, sg, num_sg, i)
V_125 += F_56 ( V_122 -> V_95 , V_122 -> V_132 ) ;
V_82 -> V_6 . V_7 . V_8 = V_8 ;
V_2 -> V_4 [ V_8 ] . V_123 = V_123 ;
if ( V_125 > V_128 ) {
F_2 ( V_5 -> V_90 & ( V_133 | V_134 ) ) ;
V_82 -> V_85 = V_105 ;
V_82 -> V_6 . V_109 . V_135 = F_49 ( V_5 ) ?
V_38 : V_37 ;
V_82 -> V_6 . V_109 . V_88 = ( V_89 ) F_44 ( V_5 ) ;
V_82 -> V_6 . V_109 . V_136 = V_2 -> V_136 ;
V_82 -> V_6 . V_109 . V_137 = V_125 ;
} else {
V_82 -> V_6 . V_7 . V_88 = ( V_89 ) F_44 ( V_5 ) ;
V_82 -> V_6 . V_7 . V_136 = V_2 -> V_136 ;
V_82 -> V_85 = F_49 ( V_5 ) ?
V_38 : V_37 ;
if ( V_5 -> V_90 & ( V_133 | V_134 ) ) {
switch ( V_2 -> V_138 &
( ( V_133 | V_134 ) ) ) {
case V_133 | V_134 :
V_82 -> V_85 =
V_39 ;
break;
case V_133 :
V_82 -> V_85 =
V_40 ;
break;
default:
V_82 -> V_85 = 0 ;
}
}
V_82 -> V_6 . V_7 . V_137 = V_125 ;
}
V_99 . V_82 = V_82 ;
V_99 . V_8 = V_8 ;
F_55 (info->shadow[id].sg, sg, num_sg, i) {
F_2 ( V_122 -> V_95 + V_122 -> V_132 > V_139 ) ;
if ( V_99 . V_112 ) {
V_99 . V_115 = V_122 -> V_95 ;
V_99 . V_114 = F_47 ( F_57 ( V_122 ) ) ;
}
F_58 ( F_57 ( V_122 ) ,
V_122 -> V_95 ,
V_122 -> V_132 ,
F_45 ,
& V_99 ) ;
if ( V_99 . V_112 )
F_46 ( V_99 . V_114 ) ;
}
if ( V_99 . V_107 )
F_46 ( V_99 . V_107 ) ;
V_2 -> V_83 . V_84 ++ ;
V_2 -> V_4 [ V_8 ] . V_5 = * V_82 ;
if ( V_120 )
F_59 ( V_99 . V_29 ) ;
return 0 ;
}
static int F_60 ( struct V_10 * V_5 )
{
struct V_1 * V_2 = V_5 -> V_80 -> V_69 ;
if ( F_61 ( V_2 -> V_140 != V_141 ) )
return 1 ;
if ( F_61 ( V_5 -> V_90 & ( V_142 | V_91 ) ) )
return F_41 ( V_5 ) ;
else
return F_48 ( V_5 ) ;
}
static inline void F_62 ( struct V_1 * V_2 )
{
int V_143 ;
F_63 ( & V_2 -> V_83 , V_143 ) ;
if ( V_143 )
F_64 ( V_2 -> V_144 ) ;
}
static inline bool F_65 ( struct V_10 * V_5 ,
struct V_1 * V_2 )
{
return ( ( V_5 -> V_145 != V_146 ) ||
( ( V_5 -> V_90 & V_133 ) &&
! ( V_2 -> V_138 & V_133 ) ) ||
( ( V_5 -> V_90 & V_134 ) &&
! ( V_2 -> V_138 & V_134 ) ) ) ;
}
static int F_66 ( struct V_147 * V_148 ,
const struct V_149 * V_150 )
{
struct V_1 * V_2 = V_150 -> V_151 -> V_80 -> V_69 ;
F_67 ( V_150 -> V_151 ) ;
F_68 ( & V_2 -> V_152 ) ;
if ( F_69 ( & V_2 -> V_83 ) )
goto V_153;
if ( F_65 ( V_150 -> V_151 , V_2 ) )
goto V_154;
if ( F_60 ( V_150 -> V_151 ) )
goto V_153;
F_62 ( V_2 ) ;
F_70 ( & V_2 -> V_152 ) ;
return V_155 ;
V_154:
F_70 ( & V_2 -> V_152 ) ;
return V_156 ;
V_153:
F_70 ( & V_2 -> V_152 ) ;
F_71 ( V_148 ) ;
return V_157 ;
}
static int F_72 ( struct V_76 * V_77 , T_4 V_158 ,
unsigned int V_159 ,
unsigned int V_107 )
{
struct V_160 * V_151 ;
struct V_1 * V_2 = V_77 -> V_69 ;
memset ( & V_2 -> V_161 , 0 , sizeof( V_2 -> V_161 ) ) ;
V_2 -> V_161 . V_162 = & V_163 ;
V_2 -> V_161 . V_164 = 1 ;
V_2 -> V_161 . V_165 = F_3 ( V_2 ) ;
V_2 -> V_161 . V_166 = V_167 ;
V_2 -> V_161 . V_78 = V_168 | V_169 ;
V_2 -> V_161 . V_170 = 0 ;
V_2 -> V_161 . V_171 = V_2 ;
if ( F_73 ( & V_2 -> V_161 ) )
return - 1 ;
V_151 = F_74 ( & V_2 -> V_161 ) ;
if ( F_75 ( V_151 ) ) {
F_76 ( & V_2 -> V_161 ) ;
return - 1 ;
}
F_77 ( V_172 , V_151 ) ;
if ( V_2 -> V_173 ) {
F_77 ( V_174 , V_151 ) ;
F_78 ( V_151 , F_36 ( V_77 ) ) ;
V_151 -> V_175 . V_176 = V_2 -> V_176 ;
V_151 -> V_175 . V_177 = V_2 -> V_177 ;
if ( V_2 -> V_92 )
F_77 ( V_178 , V_151 ) ;
}
F_79 ( V_151 , V_158 ) ;
F_80 ( V_151 , V_159 ) ;
F_81 ( V_151 , ( V_107 * V_179 ) / 512 ) ;
F_82 ( V_151 , V_139 - 1 ) ;
F_83 ( V_151 , V_139 ) ;
F_84 ( V_151 , V_107 / V_127 ) ;
F_85 ( V_151 , 511 ) ;
F_86 ( V_151 , V_180 ) ;
V_77 -> V_181 = V_151 ;
return 0 ;
}
static const char * F_87 ( unsigned int V_138 )
{
switch ( V_138 & ( ( V_133 | V_134 ) ) ) {
case V_133 | V_134 :
return L_10 ;
case V_133 :
return L_11 ;
default:
return L_12 ;
}
}
static void F_88 ( struct V_1 * V_2 )
{
F_89 ( V_2 -> V_151 , V_2 -> V_138 ) ;
F_90 ( L_13 ,
V_2 -> V_77 -> V_182 , F_87 ( V_2 -> V_138 ) ,
L_14 , V_2 -> V_20 ?
L_15 : L_16 , L_17 ,
V_2 -> V_130 ? L_15 : L_16 ) ;
}
static int F_91 ( int V_183 , int * V_42 , unsigned int * V_95 )
{
int V_184 ;
V_184 = F_92 ( V_183 ) ;
* V_42 = F_93 ( V_183 ) ;
switch ( V_184 ) {
case V_185 :
* V_95 = ( * V_42 / 64 ) + V_186 ;
* V_42 = ( ( * V_42 / 64 ) * V_187 ) +
V_188 ;
break;
case V_189 :
* V_95 = ( * V_42 / 64 ) + 2 + V_186 ;
* V_42 = ( ( ( * V_42 / 64 ) + 2 ) * V_187 ) +
V_188 ;
break;
case V_190 :
* V_95 = ( * V_42 / V_187 ) + V_191 ;
* V_42 = * V_42 + V_192 ;
break;
case V_193 :
case V_194 :
case V_195 :
case V_196 :
case V_197 :
case V_198 :
case V_199 :
* V_95 = ( * V_42 / V_187 ) +
( ( V_184 - V_193 + 1 ) * 16 ) +
V_191 ;
* V_42 = * V_42 +
( ( V_184 - V_193 + 1 ) * 16 * V_187 ) +
V_192 ;
break;
case V_200 :
case V_201 :
case V_202 :
case V_203 :
case V_204 :
case V_205 :
case V_206 :
case V_207 :
* V_95 = ( * V_42 / V_187 ) +
( ( V_184 - V_200 + 8 ) * 16 ) +
V_191 ;
* V_42 = * V_42 +
( ( V_184 - V_200 + 8 ) * 16 * V_187 ) +
V_192 ;
break;
case V_208 :
* V_95 = * V_42 / V_187 ;
break;
default:
F_94 ( V_209 L_18
L_19 ) ;
return - V_210 ;
}
return 0 ;
}
static char * F_95 ( char * V_211 , unsigned int V_16 )
{
if ( V_16 >= 26 )
V_211 = F_95 ( V_211 , V_16 / 26 - 1 ) ;
* V_211 = 'a' + V_16 % 26 ;
return V_211 + 1 ;
}
static int F_96 ( V_89 V_212 ,
struct V_1 * V_2 ,
T_4 V_213 , T_4 V_158 ,
unsigned int V_159 )
{
struct V_76 * V_77 ;
int V_46 = 1 ;
int V_214 ;
unsigned int V_95 ;
int V_42 ;
int V_215 ;
char * V_211 ;
F_2 ( V_2 -> V_77 != NULL ) ;
F_2 ( V_2 -> V_151 != NULL ) ;
if ( ( V_2 -> V_183 >> V_216 ) > 1 ) {
F_94 ( V_209 L_20 , V_2 -> V_183 ) ;
return - V_210 ;
}
if ( ! F_97 ( V_2 -> V_183 ) ) {
V_214 = F_91 ( V_2 -> V_183 , & V_42 , & V_95 ) ;
if ( V_214 )
return V_214 ;
V_215 = V_187 ;
} else {
V_42 = F_98 ( V_2 -> V_183 ) ;
V_215 = V_217 ;
V_95 = V_42 / V_215 ;
if ( F_99 () && V_95 < V_186 + 4 )
F_94 ( V_209 L_21
L_22
L_23 , V_2 -> V_183 ) ;
}
if ( V_42 >> V_218 ) {
F_100 ( L_24 ,
V_2 -> V_183 , V_42 ) ;
return - V_210 ;
}
if ( ( V_42 % V_215 ) == 0 )
V_46 = V_215 ;
V_214 = F_24 ( V_42 , V_46 ) ;
if ( V_214 )
goto V_219;
V_214 = - V_210 ;
V_77 = F_101 ( V_46 ) ;
if ( V_77 == NULL )
goto V_220;
strcpy ( V_77 -> V_182 , V_221 ) ;
V_211 = F_95 ( V_77 -> V_182 + sizeof( V_221 ) - 1 , V_95 ) ;
F_2 ( V_211 >= V_77 -> V_182 + V_222 ) ;
if ( V_46 > 1 )
* V_211 = 0 ;
else
snprintf ( V_211 , V_77 -> V_182 + V_222 - V_211 ,
L_25 , V_42 & ( V_215 - 1 ) ) ;
V_77 -> V_184 = V_208 ;
V_77 -> V_223 = V_42 ;
V_77 -> V_224 = & V_225 ;
V_77 -> V_69 = V_2 ;
V_77 -> V_226 = & ( V_2 -> V_27 -> V_70 ) ;
F_102 ( V_77 , V_212 ) ;
if ( F_72 ( V_77 , V_158 , V_159 ,
V_2 -> V_130 ? :
V_128 ) ) {
F_103 ( V_77 ) ;
goto V_220;
}
V_2 -> V_151 = V_77 -> V_181 ;
V_2 -> V_77 = V_77 ;
F_88 ( V_2 ) ;
if ( V_213 & V_227 )
F_104 ( V_77 , 1 ) ;
if ( V_213 & V_228 )
V_77 -> V_78 |= V_229 ;
if ( V_213 & V_230 )
V_77 -> V_78 |= V_79 ;
return 0 ;
V_220:
F_31 ( V_42 , V_46 ) ;
V_219:
return V_214 ;
}
static void F_105 ( struct V_1 * V_2 )
{
unsigned int V_42 , V_46 ;
if ( V_2 -> V_151 == NULL )
return;
F_106 ( V_2 -> V_151 ) ;
F_107 ( & V_2 -> V_129 ) ;
F_108 ( & V_2 -> V_55 ) ;
F_103 ( V_2 -> V_77 ) ;
V_42 = V_2 -> V_77 -> V_223 ;
V_46 = V_2 -> V_77 -> V_51 ;
F_31 ( V_42 , V_46 ) ;
F_109 ( V_2 -> V_151 ) ;
F_76 ( & V_2 -> V_161 ) ;
V_2 -> V_151 = NULL ;
F_110 ( V_2 -> V_77 ) ;
V_2 -> V_77 = NULL ;
}
static void F_111 ( struct V_1 * V_2 )
{
if ( ! F_69 ( & V_2 -> V_83 ) )
F_112 ( V_2 -> V_151 , true ) ;
}
static void F_113 ( struct V_231 * V_55 )
{
struct V_1 * V_2 = F_114 ( V_55 , struct V_1 , V_55 ) ;
F_68 ( & V_2 -> V_152 ) ;
if ( V_2 -> V_140 == V_141 )
F_111 ( V_2 ) ;
F_70 ( & V_2 -> V_152 ) ;
}
static void F_115 ( struct V_1 * V_2 , int V_232 )
{
struct V_14 * V_233 ;
struct V_14 * V_16 ;
int V_17 , V_234 , V_235 ;
F_68 ( & V_2 -> V_152 ) ;
V_2 -> V_140 = V_232 ?
V_236 : V_237 ;
if ( V_2 -> V_151 )
F_106 ( V_2 -> V_151 ) ;
if ( ! F_14 ( & V_2 -> V_24 ) ) {
F_10 (persistent_gnt, n,
&info->grants, node) {
F_11 ( & V_233 -> V_23 ) ;
if ( V_233 -> V_21 != V_22 ) {
F_116 ( V_233 -> V_21 ,
0 , 0UL ) ;
V_2 -> V_26 -- ;
}
if ( V_2 -> V_20 )
F_12 ( V_233 -> V_12 ) ;
F_8 ( V_233 ) ;
}
}
F_2 ( V_2 -> V_26 != 0 ) ;
if ( ! F_14 ( & V_2 -> V_33 ) ) {
struct V_12 * V_32 , * V_16 ;
F_2 ( V_2 -> V_20 ) ;
F_10 (indirect_page, n, &info->indirect_pages, lru) {
F_11 ( & V_32 -> V_34 ) ;
F_12 ( V_32 ) ;
}
}
for ( V_17 = 0 ; V_17 < F_3 ( V_2 ) ; V_17 ++ ) {
if ( ! V_2 -> V_4 [ V_17 ] . V_10 )
goto V_238;
V_235 = V_2 -> V_4 [ V_17 ] . V_5 . V_85 == V_105 ?
V_2 -> V_4 [ V_17 ] . V_5 . V_6 . V_109 . V_137 :
V_2 -> V_4 [ V_17 ] . V_5 . V_6 . V_7 . V_137 ;
for ( V_234 = 0 ; V_234 < V_235 ; V_234 ++ ) {
V_233 = V_2 -> V_4 [ V_17 ] . V_111 [ V_234 ] ;
F_116 ( V_233 -> V_21 , 0 , 0UL ) ;
if ( V_2 -> V_20 )
F_12 ( V_233 -> V_12 ) ;
F_8 ( V_233 ) ;
}
if ( V_2 -> V_4 [ V_17 ] . V_5 . V_85 != V_105 )
goto V_238;
for ( V_234 = 0 ; V_234 < F_50 ( V_235 ) ; V_234 ++ ) {
V_233 = V_2 -> V_4 [ V_17 ] . V_108 [ V_234 ] ;
F_116 ( V_233 -> V_21 , 0 , 0UL ) ;
F_12 ( V_233 -> V_12 ) ;
F_8 ( V_233 ) ;
}
V_238:
F_8 ( V_2 -> V_4 [ V_17 ] . V_111 ) ;
V_2 -> V_4 [ V_17 ] . V_111 = NULL ;
F_8 ( V_2 -> V_4 [ V_17 ] . V_108 ) ;
V_2 -> V_4 [ V_17 ] . V_108 = NULL ;
F_8 ( V_2 -> V_4 [ V_17 ] . V_122 ) ;
V_2 -> V_4 [ V_17 ] . V_122 = NULL ;
}
F_107 ( & V_2 -> V_129 ) ;
F_70 ( & V_2 -> V_152 ) ;
F_108 ( & V_2 -> V_55 ) ;
for ( V_17 = 0 ; V_17 < V_2 -> V_239 ; V_17 ++ ) {
if ( V_2 -> V_240 [ V_17 ] != V_22 ) {
F_116 ( V_2 -> V_240 [ V_17 ] , 0 , 0 ) ;
V_2 -> V_240 [ V_17 ] = V_22 ;
}
}
F_117 ( ( unsigned long ) V_2 -> V_83 . V_241 , F_118 ( V_2 -> V_239 * V_139 ) ) ;
V_2 -> V_83 . V_241 = NULL ;
if ( V_2 -> V_144 )
F_119 ( V_2 -> V_144 , V_2 ) ;
V_2 -> V_242 = V_2 -> V_144 = 0 ;
}
static void F_120 ( unsigned long V_30 , unsigned int V_95 ,
unsigned int V_96 , void * V_97 )
{
struct V_243 * V_2 = V_97 ;
char * V_113 ;
const struct V_104 * V_244 = V_2 -> V_244 ;
V_113 = F_47 ( V_244 -> V_111 [ V_2 -> V_103 ] -> V_12 ) ;
memcpy ( V_2 -> V_114 + V_2 -> V_245 ,
V_113 + V_95 , V_96 ) ;
V_2 -> V_245 += V_96 ;
V_2 -> V_103 ++ ;
F_46 ( V_113 ) ;
}
static void F_121 ( struct V_104 * V_244 , struct V_1 * V_2 ,
struct V_246 * V_247 )
{
int V_17 = 0 ;
struct V_121 * V_122 ;
int V_123 , V_125 ;
struct V_243 V_97 = {
. V_244 = V_244 ,
. V_103 = 0 ,
} ;
V_125 = V_244 -> V_5 . V_85 == V_105 ?
V_244 -> V_5 . V_6 . V_109 . V_137 : V_244 -> V_5 . V_6 . V_7 . V_137 ;
V_123 = V_244 -> V_123 ;
if ( V_247 -> V_85 == V_37 && V_2 -> V_20 ) {
F_55 (s->sg, sg, num_sg, i) {
F_2 ( V_122 -> V_95 + V_122 -> V_132 > V_139 ) ;
V_97 . V_245 = V_122 -> V_95 ;
V_97 . V_114 = F_47 ( F_57 ( V_122 ) ) ;
F_58 ( F_57 ( V_122 ) ,
V_122 -> V_95 ,
V_122 -> V_132 ,
F_120 ,
& V_97 ) ;
F_46 ( V_97 . V_114 ) ;
}
}
for ( V_17 = 0 ; V_17 < V_125 ; V_17 ++ ) {
if ( F_122 ( V_244 -> V_111 [ V_17 ] -> V_21 ) ) {
if ( ! V_2 -> V_20 )
F_123 ( L_26 ,
V_244 -> V_111 [ V_17 ] -> V_21 ) ;
F_9 ( & V_244 -> V_111 [ V_17 ] -> V_23 , & V_2 -> V_24 ) ;
V_2 -> V_26 ++ ;
} else {
F_116 ( V_244 -> V_111 [ V_17 ] -> V_21 , 0 , 0UL ) ;
V_244 -> V_111 [ V_17 ] -> V_21 = V_22 ;
F_124 ( & V_244 -> V_111 [ V_17 ] -> V_23 , & V_2 -> V_24 ) ;
}
}
if ( V_244 -> V_5 . V_85 == V_105 ) {
for ( V_17 = 0 ; V_17 < F_50 ( V_125 ) ; V_17 ++ ) {
if ( F_122 ( V_244 -> V_108 [ V_17 ] -> V_21 ) ) {
if ( ! V_2 -> V_20 )
F_123 ( L_26 ,
V_244 -> V_108 [ V_17 ] -> V_21 ) ;
F_9 ( & V_244 -> V_108 [ V_17 ] -> V_23 , & V_2 -> V_24 ) ;
V_2 -> V_26 ++ ;
} else {
struct V_12 * V_32 ;
F_116 ( V_244 -> V_108 [ V_17 ] -> V_21 , 0 , 0UL ) ;
if ( ! V_2 -> V_20 ) {
V_32 = V_244 -> V_108 [ V_17 ] -> V_12 ;
F_9 ( & V_32 -> V_34 , & V_2 -> V_33 ) ;
}
V_244 -> V_108 [ V_17 ] -> V_21 = V_22 ;
F_124 ( & V_244 -> V_108 [ V_17 ] -> V_23 , & V_2 -> V_24 ) ;
}
}
}
}
static T_5 F_125 ( int V_144 , void * V_248 )
{
struct V_10 * V_5 ;
struct V_246 * V_247 ;
T_6 V_17 , V_249 ;
unsigned long V_78 ;
struct V_1 * V_2 = (struct V_1 * ) V_248 ;
int error ;
F_126 ( & V_2 -> V_152 , V_78 ) ;
if ( F_61 ( V_2 -> V_140 != V_141 ) ) {
F_127 ( & V_2 -> V_152 , V_78 ) ;
return V_250 ;
}
V_251:
V_249 = V_2 -> V_83 . V_241 -> V_252 ;
F_128 () ;
for ( V_17 = V_2 -> V_83 . V_253 ; V_17 != V_249 ; V_17 ++ ) {
unsigned long V_8 ;
V_247 = F_129 ( & V_2 -> V_83 , V_17 ) ;
V_8 = V_247 -> V_8 ;
if ( V_8 >= F_3 ( V_2 ) ) {
F_130 ( 1 , L_27 ,
V_2 -> V_77 -> V_182 , F_22 ( V_247 -> V_85 ) , V_8 ) ;
continue;
}
V_5 = V_2 -> V_4 [ V_8 ] . V_10 ;
if ( V_247 -> V_85 != V_41 )
F_121 ( & V_2 -> V_4 [ V_8 ] , V_2 , V_247 ) ;
if ( F_4 ( V_2 , V_8 ) ) {
F_130 ( 1 , L_28 ,
V_2 -> V_77 -> V_182 , F_22 ( V_247 -> V_85 ) , V_8 ) ;
continue;
}
error = ( V_247 -> V_254 == V_255 ) ? 0 : - V_256 ;
switch ( V_247 -> V_85 ) {
case V_41 :
if ( F_61 ( V_247 -> V_254 == V_257 ) ) {
struct V_160 * V_151 = V_2 -> V_151 ;
F_94 ( V_209 L_29 ,
V_2 -> V_77 -> V_182 , F_22 ( V_247 -> V_85 ) ) ;
error = - V_258 ;
V_2 -> V_173 = 0 ;
V_2 -> V_92 = 0 ;
F_131 ( V_174 , V_151 ) ;
F_131 ( V_178 , V_151 ) ;
}
F_132 ( V_5 , error ) ;
break;
case V_40 :
case V_39 :
if ( F_61 ( V_247 -> V_254 == V_257 ) ) {
F_94 ( V_209 L_29 ,
V_2 -> V_77 -> V_182 , F_22 ( V_247 -> V_85 ) ) ;
error = - V_258 ;
}
if ( F_61 ( V_247 -> V_254 == V_259 &&
V_2 -> V_4 [ V_8 ] . V_5 . V_6 . V_7 . V_137 == 0 ) ) {
F_94 ( V_209 L_30 ,
V_2 -> V_77 -> V_182 , F_22 ( V_247 -> V_85 ) ) ;
error = - V_258 ;
}
if ( F_61 ( error ) ) {
if ( error == - V_258 )
error = 0 ;
V_2 -> V_138 = 0 ;
F_88 ( V_2 ) ;
}
case V_37 :
case V_38 :
if ( F_61 ( V_247 -> V_254 != V_255 ) )
F_39 ( & V_2 -> V_27 -> V_70 , L_31
L_32 , V_247 -> V_254 ) ;
F_132 ( V_5 , error ) ;
break;
default:
F_133 () ;
}
}
V_2 -> V_83 . V_253 = V_17 ;
if ( V_17 != V_2 -> V_83 . V_84 ) {
int V_260 ;
F_134 ( & V_2 -> V_83 , V_260 ) ;
if ( V_260 )
goto V_251;
} else
V_2 -> V_83 . V_241 -> V_261 = V_17 + 1 ;
F_111 ( V_2 ) ;
F_127 ( & V_2 -> V_152 , V_78 ) ;
return V_250 ;
}
static int F_135 ( struct V_262 * V_70 ,
struct V_1 * V_2 )
{
struct V_263 * V_241 ;
int V_214 , V_17 ;
unsigned long V_264 = V_2 -> V_239 * V_179 ;
T_1 V_21 [ V_265 ] ;
for ( V_17 = 0 ; V_17 < V_2 -> V_239 ; V_17 ++ )
V_2 -> V_240 [ V_17 ] = V_22 ;
V_241 = (struct V_263 * ) F_136 ( V_18 | V_266 ,
F_118 ( V_264 ) ) ;
if ( ! V_241 ) {
F_137 ( V_70 , - V_25 , L_33 ) ;
return - V_25 ;
}
F_138 ( V_241 ) ;
F_139 ( & V_2 -> V_83 , V_241 , V_264 ) ;
V_214 = F_140 ( V_70 , V_2 -> V_83 . V_241 , V_2 -> V_239 , V_21 ) ;
if ( V_214 < 0 ) {
F_117 ( ( unsigned long ) V_241 , F_118 ( V_264 ) ) ;
V_2 -> V_83 . V_241 = NULL ;
goto V_267;
}
for ( V_17 = 0 ; V_17 < V_2 -> V_239 ; V_17 ++ )
V_2 -> V_240 [ V_17 ] = V_21 [ V_17 ] ;
V_214 = F_141 ( V_70 , & V_2 -> V_242 ) ;
if ( V_214 )
goto V_267;
V_214 = F_142 ( V_2 -> V_242 , F_125 , 0 ,
L_34 , V_2 ) ;
if ( V_214 <= 0 ) {
F_137 ( V_70 , V_214 ,
L_35 ) ;
goto V_267;
}
V_2 -> V_144 = V_214 ;
return 0 ;
V_267:
F_115 ( V_2 , 0 ) ;
return V_214 ;
}
static int F_143 ( struct V_262 * V_70 ,
struct V_1 * V_2 )
{
const char * V_268 = NULL ;
struct V_269 V_270 ;
int V_214 , V_17 ;
unsigned int V_271 = 0 ;
unsigned int V_272 = 0 ;
V_214 = F_144 ( V_273 , V_2 -> V_27 -> V_274 ,
L_36 , L_37 , & V_271 ) ;
if ( V_214 != 1 )
V_2 -> V_239 = 1 ;
else {
V_272 = F_145 ( V_275 , V_271 ) ;
V_2 -> V_239 = 1 << V_272 ;
}
V_214 = F_135 ( V_70 , V_2 ) ;
if ( V_214 )
goto V_219;
V_251:
V_214 = F_146 ( & V_270 ) ;
if ( V_214 ) {
F_137 ( V_70 , V_214 , L_38 ) ;
goto V_276;
}
if ( V_2 -> V_239 == 1 ) {
V_214 = F_147 ( V_270 , V_70 -> V_277 ,
L_39 , L_37 , V_2 -> V_240 [ 0 ] ) ;
if ( V_214 ) {
V_268 = L_40 ;
goto V_278;
}
} else {
V_214 = F_147 ( V_270 , V_70 -> V_277 ,
L_41 , L_37 , V_272 ) ;
if ( V_214 ) {
V_268 = L_42 ;
goto V_278;
}
for ( V_17 = 0 ; V_17 < V_2 -> V_239 ; V_17 ++ ) {
char V_279 [ V_280 ] ;
snprintf ( V_279 , V_280 , L_43 , V_17 ) ;
V_214 = F_147 ( V_270 , V_70 -> V_277 , V_279 ,
L_37 , V_2 -> V_240 [ V_17 ] ) ;
if ( V_214 ) {
V_268 = L_40 ;
goto V_278;
}
}
}
V_214 = F_147 ( V_270 , V_70 -> V_277 ,
L_44 , L_37 , V_2 -> V_242 ) ;
if ( V_214 ) {
V_268 = L_45 ;
goto V_278;
}
V_214 = F_147 ( V_270 , V_70 -> V_277 , L_46 , L_47 ,
V_281 ) ;
if ( V_214 ) {
V_268 = L_48 ;
goto V_278;
}
V_214 = F_147 ( V_270 , V_70 -> V_277 ,
L_49 , L_37 , 1 ) ;
if ( V_214 )
F_148 ( & V_70 -> V_70 ,
L_50 ) ;
V_214 = F_149 ( V_270 , 0 ) ;
if ( V_214 ) {
if ( V_214 == - V_282 )
goto V_251;
F_137 ( V_70 , V_214 , L_51 ) ;
goto V_276;
}
for ( V_17 = 0 ; V_17 < F_3 ( V_2 ) ; V_17 ++ )
V_2 -> V_4 [ V_17 ] . V_5 . V_6 . V_7 . V_8 = V_17 + 1 ;
V_2 -> V_4 [ F_3 ( V_2 ) - 1 ] . V_5 . V_6 . V_7 . V_8 = 0x0fffffff ;
F_150 ( V_70 , V_283 ) ;
return 0 ;
V_278:
F_149 ( V_270 , 1 ) ;
if ( V_268 )
F_137 ( V_70 , V_214 , L_47 , V_268 ) ;
V_276:
F_115 ( V_2 , 0 ) ;
V_219:
return V_214 ;
}
static int F_151 ( struct V_262 * V_70 ,
const struct V_284 * V_8 )
{
int V_214 , V_183 ;
struct V_1 * V_2 ;
V_214 = F_144 ( V_273 , V_70 -> V_277 ,
L_52 , L_53 , & V_183 ) ;
if ( V_214 != 1 ) {
V_214 = F_144 ( V_273 , V_70 -> V_277 , L_54 ,
L_53 , & V_183 ) ;
if ( V_214 != 1 ) {
F_137 ( V_70 , V_214 , L_55 ) ;
return V_214 ;
}
}
if ( F_99 () ) {
char * type ;
int V_96 ;
if ( F_152 () ) {
int V_184 ;
if ( ! F_97 ( V_183 ) )
V_184 = F_92 ( V_183 ) ;
else
V_184 = V_208 ;
if ( V_184 != V_208 ) {
F_94 ( V_285
L_56 ,
V_286 , V_183 ) ;
return - V_210 ;
}
}
type = F_153 ( V_273 , V_70 -> V_277 , L_57 , & V_96 ) ;
if ( F_75 ( type ) )
return - V_210 ;
if ( strncmp ( type , L_58 , 5 ) == 0 ) {
F_8 ( type ) ;
return - V_210 ;
}
F_8 ( type ) ;
}
V_2 = F_6 ( sizeof( * V_2 ) , V_49 ) ;
if ( ! V_2 ) {
F_137 ( V_70 , - V_25 , L_59 ) ;
return - V_25 ;
}
F_154 ( & V_2 -> V_287 ) ;
F_155 ( & V_2 -> V_152 ) ;
V_2 -> V_27 = V_70 ;
V_2 -> V_183 = V_183 ;
F_156 ( & V_2 -> V_24 ) ;
F_156 ( & V_2 -> V_33 ) ;
V_2 -> V_26 = 0 ;
V_2 -> V_140 = V_237 ;
F_157 ( & V_2 -> V_55 , F_113 ) ;
V_2 -> V_136 = F_158 ( strrchr ( V_70 -> V_277 , '/' ) + 1 , NULL , 0 ) ;
F_159 ( & V_70 -> V_70 , V_2 ) ;
return 0 ;
}
static void F_160 ( struct V_288 * V_288 )
{
struct V_289 * V_289 = V_288 -> V_290 ;
if ( F_161 ( & V_289 -> V_291 ) ) {
V_289 -> V_288 -> V_292 = 0 ;
V_289 -> V_288 -> V_293 = V_288 -> V_293 ;
F_162 ( V_289 -> V_288 ) ;
F_8 ( V_289 ) ;
}
F_163 ( V_288 ) ;
}
static int F_164 ( struct V_1 * V_2 )
{
int V_17 ;
struct V_10 * V_5 , * V_16 ;
struct V_104 * V_294 ;
int V_45 ;
struct V_288 * V_288 , * V_295 ;
struct V_296 V_296 , V_297 ;
unsigned int V_235 , V_95 ;
int V_291 , V_298 ;
struct V_289 * V_289 ;
struct V_299 V_300 ;
V_294 = F_165 ( V_2 -> V_4 , sizeof( V_2 -> V_4 ) ,
V_18 | V_301 | V_266 ) ;
if ( ! V_294 )
return - V_25 ;
memset ( & V_2 -> V_4 , 0 , sizeof( V_2 -> V_4 ) ) ;
for ( V_17 = 0 ; V_17 < F_3 ( V_2 ) ; V_17 ++ )
V_2 -> V_4 [ V_17 ] . V_5 . V_6 . V_7 . V_8 = V_17 + 1 ;
V_2 -> V_3 = V_2 -> V_83 . V_84 ;
V_2 -> V_4 [ F_3 ( V_2 ) - 1 ] . V_5 . V_6 . V_7 . V_8 = 0x0fffffff ;
V_45 = F_166 ( V_2 ) ;
if ( V_45 ) {
F_8 ( V_294 ) ;
return V_45 ;
}
V_235 = V_2 -> V_130 ? : V_128 ;
F_84 ( V_2 -> V_151 , V_235 ) ;
F_167 ( & V_296 ) ;
F_156 ( & V_300 ) ;
for ( V_17 = 0 ; V_17 < F_3 ( V_2 ) ; V_17 ++ ) {
if ( ! V_294 [ V_17 ] . V_10 )
continue;
if ( V_294 [ V_17 ] . V_10 -> V_90 &
( V_133 | V_134 | V_142 | V_91 ) ) {
F_9 ( & V_294 [ V_17 ] . V_10 -> V_302 , & V_300 ) ;
continue;
}
V_297 . V_303 = V_294 [ V_17 ] . V_10 -> V_288 ;
V_297 . V_304 = V_294 [ V_17 ] . V_10 -> V_305 ;
F_168 ( & V_296 , & V_297 ) ;
V_294 [ V_17 ] . V_10 -> V_288 = NULL ;
F_169 ( V_294 [ V_17 ] . V_10 , 0 ) ;
}
F_8 ( V_294 ) ;
F_150 ( V_2 -> V_27 , V_306 ) ;
F_68 ( & V_2 -> V_152 ) ;
V_2 -> V_140 = V_141 ;
F_111 ( V_2 ) ;
F_10 (req, n, &requests, queuelist) {
F_170 ( & V_5 -> V_302 ) ;
F_2 ( V_5 -> V_126 > V_235 ) ;
F_171 ( V_5 ) ;
}
F_70 ( & V_2 -> V_152 ) ;
F_172 ( V_2 -> V_151 ) ;
while ( ( V_288 = F_173 ( & V_296 ) ) != NULL ) {
if ( F_174 ( V_288 ) > V_235 ) {
V_291 = ( F_174 ( V_288 ) + V_235 - 1 ) / V_235 ;
V_289 = F_6 ( sizeof( * V_289 ) , V_18 ) ;
F_2 ( V_289 == NULL ) ;
F_175 ( & V_289 -> V_291 , V_291 ) ;
V_289 -> V_288 = V_288 ;
for ( V_17 = 0 ; V_17 < V_291 ; V_17 ++ ) {
V_95 = ( V_17 * V_235 * V_179 ) >> 9 ;
V_298 = F_145 ( ( unsigned int ) ( V_235 * V_179 ) >> 9 ,
( unsigned int ) F_176 ( V_288 ) - V_95 ) ;
V_295 = F_177 ( V_288 , V_18 ) ;
F_2 ( V_295 == NULL ) ;
F_178 ( V_295 , V_95 , V_298 ) ;
V_295 -> V_290 = V_289 ;
V_295 -> V_307 = F_160 ;
F_179 ( V_295 -> V_308 , V_295 ) ;
}
continue;
}
F_179 ( V_288 -> V_308 , V_288 ) ;
}
return 0 ;
}
static int F_180 ( struct V_262 * V_70 )
{
struct V_1 * V_2 = F_181 ( & V_70 -> V_70 ) ;
int V_214 ;
F_39 ( & V_70 -> V_70 , L_60 , V_70 -> V_277 ) ;
F_115 ( V_2 , V_2 -> V_140 == V_141 ) ;
V_214 = F_143 ( V_70 , V_2 ) ;
return V_214 ;
}
static void
F_182 ( struct V_1 * V_2 )
{
struct V_262 * V_27 = V_2 -> V_27 ;
struct V_56 * V_65 = NULL ;
F_183 ( & V_2 -> V_287 ) ;
if ( V_27 -> V_309 == V_310 ) {
F_184 ( & V_2 -> V_287 ) ;
return;
}
if ( V_2 -> V_77 )
V_65 = F_185 ( V_2 -> V_77 , 0 ) ;
F_184 ( & V_2 -> V_287 ) ;
if ( ! V_65 ) {
F_186 ( V_27 ) ;
return;
}
F_183 ( & V_65 -> V_311 ) ;
if ( V_65 -> V_312 ) {
F_187 ( V_27 , - V_53 ,
L_61 ) ;
F_150 ( V_27 , V_310 ) ;
} else {
F_105 ( V_2 ) ;
F_186 ( V_27 ) ;
}
F_184 ( & V_65 -> V_311 ) ;
F_188 ( V_65 ) ;
}
static void F_189 ( struct V_1 * V_2 )
{
int V_214 ;
unsigned int V_176 ;
unsigned int V_177 ;
unsigned int V_313 ;
V_2 -> V_173 = 1 ;
V_214 = F_190 ( V_273 , V_2 -> V_27 -> V_274 ,
L_62 , L_37 , & V_176 ,
L_63 , L_37 , & V_177 ,
NULL ) ;
if ( ! V_214 ) {
V_2 -> V_176 = V_176 ;
V_2 -> V_177 = V_177 ;
}
V_214 = F_190 ( V_273 , V_2 -> V_27 -> V_274 ,
L_64 , L_25 , & V_313 ,
NULL ) ;
if ( ! V_214 )
V_2 -> V_92 = ! ! V_313 ;
}
static int F_191 ( struct V_1 * V_2 )
{
unsigned int V_314 , V_24 ;
int V_214 , V_17 ;
if ( V_2 -> V_130 == 0 )
V_24 = V_128 ;
else
V_24 = V_2 -> V_130 ;
V_314 = V_24 / V_127 ;
V_214 = F_5 ( V_2 ,
( V_24 + F_50 ( V_24 ) ) * F_3 ( V_2 ) ) ;
if ( V_214 )
goto V_19;
if ( ! V_2 -> V_20 && V_2 -> V_130 ) {
int V_11 = F_50 ( V_24 ) * F_3 ( V_2 ) ;
F_2 ( ! F_14 ( & V_2 -> V_33 ) ) ;
for ( V_17 = 0 ; V_17 < V_11 ; V_17 ++ ) {
struct V_12 * V_32 = F_7 ( V_18 ) ;
if ( ! V_32 )
goto V_19;
F_9 ( & V_32 -> V_34 , & V_2 -> V_33 ) ;
}
}
for ( V_17 = 0 ; V_17 < F_3 ( V_2 ) ; V_17 ++ ) {
V_2 -> V_4 [ V_17 ] . V_111 = F_6 (
sizeof( V_2 -> V_4 [ V_17 ] . V_111 [ 0 ] ) * V_24 ,
V_18 ) ;
V_2 -> V_4 [ V_17 ] . V_122 = F_6 ( sizeof( V_2 -> V_4 [ V_17 ] . V_122 [ 0 ] ) * V_314 , V_18 ) ;
if ( V_2 -> V_130 )
V_2 -> V_4 [ V_17 ] . V_108 = F_6 (
sizeof( V_2 -> V_4 [ V_17 ] . V_108 [ 0 ] ) *
F_50 ( V_24 ) ,
V_18 ) ;
if ( ( V_2 -> V_4 [ V_17 ] . V_111 == NULL ) ||
( V_2 -> V_4 [ V_17 ] . V_122 == NULL ) ||
( V_2 -> V_130 &&
( V_2 -> V_4 [ V_17 ] . V_108 == NULL ) ) )
goto V_19;
F_192 ( V_2 -> V_4 [ V_17 ] . V_122 , V_314 ) ;
}
return 0 ;
V_19:
for ( V_17 = 0 ; V_17 < F_3 ( V_2 ) ; V_17 ++ ) {
F_8 ( V_2 -> V_4 [ V_17 ] . V_111 ) ;
V_2 -> V_4 [ V_17 ] . V_111 = NULL ;
F_8 ( V_2 -> V_4 [ V_17 ] . V_122 ) ;
V_2 -> V_4 [ V_17 ] . V_122 = NULL ;
F_8 ( V_2 -> V_4 [ V_17 ] . V_108 ) ;
V_2 -> V_4 [ V_17 ] . V_108 = NULL ;
}
if ( ! F_14 ( & V_2 -> V_33 ) ) {
struct V_12 * V_32 , * V_16 ;
F_10 (indirect_page, n, &info->indirect_pages, lru) {
F_11 ( & V_32 -> V_34 ) ;
F_12 ( V_32 ) ;
}
}
return - V_25 ;
}
static int F_166 ( struct V_1 * V_2 )
{
int V_214 ;
int V_315 , V_316 , V_86 , V_317 ;
unsigned int V_318 ;
V_2 -> V_138 = 0 ;
V_214 = F_190 ( V_273 , V_2 -> V_27 -> V_274 ,
L_65 , L_25 , & V_315 ,
NULL ) ;
if ( ! V_214 && V_315 )
V_2 -> V_138 = V_133 | V_134 ;
V_214 = F_190 ( V_273 , V_2 -> V_27 -> V_274 ,
L_66 , L_25 , & V_316 ,
NULL ) ;
if ( ! V_214 && V_316 )
V_2 -> V_138 = V_133 ;
V_214 = F_190 ( V_273 , V_2 -> V_27 -> V_274 ,
L_67 , L_25 , & V_86 ,
NULL ) ;
if ( ! V_214 && V_86 )
F_189 ( V_2 ) ;
V_214 = F_190 ( V_273 , V_2 -> V_27 -> V_274 ,
L_49 , L_37 , & V_317 ,
NULL ) ;
if ( V_214 )
V_2 -> V_20 = 0 ;
else
V_2 -> V_20 = V_317 ;
V_214 = F_190 ( V_273 , V_2 -> V_27 -> V_274 ,
L_68 , L_37 , & V_318 ,
NULL ) ;
if ( V_214 )
V_2 -> V_130 = 0 ;
else
V_2 -> V_130 = F_145 ( V_318 ,
V_319 ) ;
return F_191 ( V_2 ) ;
}
static void F_193 ( struct V_1 * V_2 )
{
unsigned long long V_64 ;
unsigned long V_158 ;
unsigned int V_159 ;
unsigned int V_320 ;
int V_214 ;
switch ( V_2 -> V_140 ) {
case V_141 :
V_214 = F_144 ( V_273 , V_2 -> V_27 -> V_274 ,
L_69 , L_70 , & V_64 ) ;
if ( F_194 ( V_214 ) )
return;
F_94 ( V_285 L_71 ,
V_64 ) ;
F_102 ( V_2 -> V_77 , V_64 ) ;
F_195 ( V_2 -> V_77 ) ;
return;
case V_236 :
F_164 ( V_2 ) ;
return;
default:
break;
}
F_39 ( & V_2 -> V_27 -> V_70 , L_72 ,
V_286 , V_2 -> V_27 -> V_274 ) ;
V_214 = F_190 ( V_273 , V_2 -> V_27 -> V_274 ,
L_69 , L_73 , & V_64 ,
L_74 , L_37 , & V_320 ,
L_75 , L_76 , & V_158 ,
NULL ) ;
if ( V_214 ) {
F_137 ( V_2 -> V_27 , V_214 ,
L_77 ,
V_2 -> V_27 -> V_274 ) ;
return;
}
V_214 = F_144 ( V_273 , V_2 -> V_27 -> V_274 ,
L_78 , L_37 , & V_159 ) ;
if ( V_214 != 1 )
V_159 = V_158 ;
V_214 = F_166 ( V_2 ) ;
if ( V_214 ) {
F_137 ( V_2 -> V_27 , V_214 , L_79 ,
V_2 -> V_27 -> V_274 ) ;
return;
}
V_214 = F_96 ( V_64 , V_2 , V_320 , V_158 ,
V_159 ) ;
if ( V_214 ) {
F_137 ( V_2 -> V_27 , V_214 , L_80 ,
V_2 -> V_27 -> V_274 ) ;
return;
}
F_150 ( V_2 -> V_27 , V_306 ) ;
F_68 ( & V_2 -> V_152 ) ;
V_2 -> V_140 = V_141 ;
F_111 ( V_2 ) ;
F_70 ( & V_2 -> V_152 ) ;
F_196 ( V_2 -> V_77 ) ;
V_2 -> V_321 = 1 ;
}
static void F_197 ( struct V_262 * V_70 ,
enum V_322 V_323 )
{
struct V_1 * V_2 = F_181 ( & V_70 -> V_70 ) ;
F_39 ( & V_70 -> V_70 , L_81 , V_323 ) ;
switch ( V_323 ) {
case V_324 :
if ( V_70 -> V_309 != V_325 )
break;
if ( F_143 ( V_70 , V_2 ) ) {
F_8 ( V_2 ) ;
F_159 ( & V_70 -> V_70 , NULL ) ;
break;
}
case V_325 :
case V_283 :
case V_326 :
case V_327 :
case V_328 :
break;
case V_306 :
F_193 ( V_2 ) ;
break;
case V_329 :
if ( V_70 -> V_309 == V_329 )
break;
case V_310 :
if ( V_2 )
F_182 ( V_2 ) ;
break;
}
}
static int F_198 ( struct V_262 * V_27 )
{
struct V_1 * V_2 = F_181 ( & V_27 -> V_70 ) ;
struct V_56 * V_65 = NULL ;
struct V_76 * V_330 ;
F_39 ( & V_27 -> V_70 , L_82 , V_27 -> V_277 ) ;
F_115 ( V_2 , 0 ) ;
F_183 ( & V_2 -> V_287 ) ;
V_330 = V_2 -> V_77 ;
if ( V_330 )
V_65 = F_185 ( V_330 , 0 ) ;
V_2 -> V_27 = NULL ;
F_184 ( & V_2 -> V_287 ) ;
if ( ! V_65 ) {
F_8 ( V_2 ) ;
return 0 ;
}
F_183 ( & V_65 -> V_311 ) ;
V_2 = V_330 -> V_69 ;
F_148 ( F_199 ( V_330 ) ,
L_83 ,
V_27 -> V_277 , V_65 -> V_312 ) ;
if ( V_2 && ! V_65 -> V_312 ) {
F_105 ( V_2 ) ;
V_330 -> V_69 = NULL ;
F_8 ( V_2 ) ;
}
F_184 ( & V_65 -> V_311 ) ;
F_188 ( V_65 ) ;
return 0 ;
}
static int F_200 ( struct V_262 * V_70 )
{
struct V_1 * V_2 = F_181 ( & V_70 -> V_70 ) ;
return V_2 -> V_321 && V_2 -> V_27 ;
}
static int F_201 ( struct V_56 * V_65 , T_3 V_66 )
{
struct V_76 * V_330 = V_65 -> V_61 ;
struct V_1 * V_2 ;
int V_214 = 0 ;
F_183 ( & V_331 ) ;
V_2 = V_330 -> V_69 ;
if ( ! V_2 ) {
V_214 = - V_332 ;
goto V_219;
}
F_183 ( & V_2 -> V_287 ) ;
if ( ! V_2 -> V_77 )
V_214 = - V_332 ;
F_184 ( & V_2 -> V_287 ) ;
V_219:
F_184 ( & V_331 ) ;
return V_214 ;
}
static void F_202 ( struct V_76 * V_330 , T_3 V_66 )
{
struct V_1 * V_2 = V_330 -> V_69 ;
struct V_56 * V_65 ;
struct V_262 * V_27 ;
F_183 ( & V_331 ) ;
V_65 = F_185 ( V_330 , 0 ) ;
if ( ! V_65 ) {
F_130 ( 1 , L_84 , V_330 -> V_182 ) ;
goto V_333;
}
if ( V_65 -> V_312 )
goto V_219;
F_183 ( & V_2 -> V_287 ) ;
V_27 = V_2 -> V_27 ;
if ( V_27 && V_27 -> V_309 == V_310 ) {
F_203 ( F_199 ( V_65 -> V_61 ) , L_85 ) ;
F_105 ( V_2 ) ;
F_186 ( V_2 -> V_27 ) ;
}
F_184 ( & V_2 -> V_287 ) ;
if ( ! V_27 ) {
F_203 ( F_199 ( V_65 -> V_61 ) , L_85 ) ;
F_105 ( V_2 ) ;
V_330 -> V_69 = NULL ;
F_8 ( V_2 ) ;
}
V_219:
F_188 ( V_65 ) ;
V_333:
F_184 ( & V_331 ) ;
}
static int T_7 F_204 ( void )
{
int V_334 ;
if ( ! F_205 () )
return - V_210 ;
if ( V_275 > V_335 ) {
F_90 ( L_86 ,
V_275 , V_335 ) ;
V_275 = 0 ;
}
if ( ! F_206 () )
return - V_210 ;
if ( F_207 ( V_208 , V_221 ) ) {
F_94 ( V_209 L_87 ,
V_208 , V_221 ) ;
return - V_210 ;
}
V_334 = F_208 ( & V_336 ) ;
if ( V_334 ) {
F_209 ( V_208 , V_221 ) ;
return V_334 ;
}
return 0 ;
}
static void T_8 F_210 ( void )
{
F_211 ( & V_336 ) ;
F_209 ( V_208 , V_221 ) ;
F_8 ( V_51 ) ;
}
