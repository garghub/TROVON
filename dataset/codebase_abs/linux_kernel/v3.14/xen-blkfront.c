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
if ( V_2 -> V_21 ) {
V_14 = F_6 ( V_19 ) ;
if ( ! V_14 ) {
F_7 ( V_16 ) ;
goto V_20;
}
V_16 -> V_22 = F_8 ( V_14 ) ;
}
V_16 -> V_23 = V_24 ;
F_9 ( & V_16 -> V_25 , & V_2 -> V_26 ) ;
V_18 ++ ;
}
return 0 ;
V_20:
F_10 (gnt_list_entry, n,
&info->grants, node) {
F_11 ( & V_16 -> V_25 ) ;
if ( V_2 -> V_21 )
F_12 ( F_13 ( V_16 -> V_22 ) ) ;
F_7 ( V_16 ) ;
V_18 -- ;
}
F_2 ( V_18 != 0 ) ;
return - V_27 ;
}
static struct V_15 * F_14 ( T_1 * V_28 ,
unsigned long V_22 ,
struct V_1 * V_2 )
{
struct V_15 * V_16 ;
unsigned long V_29 ;
F_2 ( F_15 ( & V_2 -> V_26 ) ) ;
V_16 = F_16 ( & V_2 -> V_26 , struct V_15 ,
V_25 ) ;
F_11 ( & V_16 -> V_25 ) ;
if ( V_16 -> V_23 != V_24 ) {
V_2 -> V_30 -- ;
return V_16 ;
}
V_16 -> V_23 = F_17 ( V_28 ) ;
F_2 ( V_16 -> V_23 == - V_31 ) ;
if ( ! V_2 -> V_21 ) {
F_2 ( ! V_22 ) ;
V_16 -> V_22 = V_22 ;
}
V_29 = F_18 ( V_16 -> V_22 ) ;
F_19 ( V_16 -> V_23 ,
V_2 -> V_32 -> V_33 ,
V_29 , 0 ) ;
return V_16 ;
}
static const char * F_20 ( int V_34 )
{
static const char * const V_35 [] = {
[ V_36 ] = L_1 ,
[ V_37 ] = L_2 ,
[ V_38 ] = L_3 ,
[ V_39 ] = L_4 ,
[ V_40 ] = L_5 } ;
if ( V_34 < 0 || V_34 >= F_21 ( V_35 ) )
return L_6 ;
if ( ! V_35 [ V_34 ] )
return L_7 ;
return V_35 [ V_34 ] ;
}
static int F_22 ( unsigned int V_41 , unsigned int V_42 )
{
unsigned int V_43 = V_41 + V_42 ;
int V_44 ;
if ( V_43 > V_45 ) {
unsigned long * V_46 , * V_47 ;
V_46 = F_23 ( F_24 ( V_43 ) , sizeof( * V_46 ) ,
V_48 ) ;
if ( V_46 == NULL )
return - V_27 ;
F_25 ( & V_49 ) ;
if ( V_43 > V_45 ) {
V_47 = V_50 ;
memcpy ( V_46 , V_50 ,
F_24 ( V_45 ) * sizeof( * V_46 ) ) ;
V_50 = V_46 ;
V_45 = F_24 ( V_43 ) * V_51 ;
} else
V_47 = V_46 ;
F_26 ( & V_49 ) ;
F_7 ( V_47 ) ;
}
F_25 ( & V_49 ) ;
if ( F_27 ( V_50 , V_43 , V_41 ) >= V_43 ) {
F_28 ( V_50 , V_41 , V_42 ) ;
V_44 = 0 ;
} else
V_44 = - V_52 ;
F_26 ( & V_49 ) ;
return V_44 ;
}
static void F_29 ( unsigned int V_41 , unsigned int V_42 )
{
unsigned int V_43 = V_41 + V_42 ;
F_2 ( V_43 > V_45 ) ;
F_25 ( & V_49 ) ;
F_30 ( V_50 , V_41 , V_42 ) ;
F_26 ( & V_49 ) ;
}
static void F_31 ( void * V_53 )
{
struct V_1 * V_2 = (struct V_1 * ) V_53 ;
F_32 ( & V_2 -> V_54 ) ;
}
static int F_33 ( struct V_55 * V_56 , struct V_57 * V_58 )
{
T_2 V_59 = F_34 ( V_56 -> V_60 ) ;
T_2 V_61 = V_59 ;
V_58 -> V_62 = 0xff ;
V_58 -> V_63 = 0x3f ;
F_35 ( V_61 , V_58 -> V_62 * V_58 -> V_63 ) ;
V_58 -> V_61 = V_61 ;
if ( ( T_2 ) ( V_58 -> V_61 + 1 ) * V_58 -> V_62 * V_58 -> V_63 < V_59 )
V_58 -> V_61 = 0xffff ;
return 0 ;
}
static int F_36 ( struct V_55 * V_64 , T_3 V_65 ,
unsigned V_66 , unsigned long V_67 )
{
struct V_1 * V_2 = V_64 -> V_60 -> V_68 ;
int V_18 ;
F_37 ( & V_2 -> V_32 -> V_69 , L_8 ,
V_66 , ( long ) V_67 ) ;
switch ( V_66 ) {
case V_70 :
F_37 ( & V_2 -> V_32 -> V_69 , L_9 ) ;
for ( V_18 = 0 ; V_18 < sizeof( struct V_71 ) ; V_18 ++ )
if ( F_38 ( 0 , ( char V_72 * ) ( V_67 + V_18 ) ) )
return - V_73 ;
return 0 ;
case V_74 : {
struct V_75 * V_76 = V_2 -> V_76 ;
if ( V_76 -> V_77 & V_78 )
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
struct V_1 * V_2 = V_6 -> V_79 -> V_68 ;
struct V_80 * V_81 ;
unsigned long V_9 ;
unsigned int V_82 , V_83 ;
int V_18 , V_84 , V_17 ;
struct V_85 * V_86 = NULL ;
bool V_87 ;
T_1 V_28 ;
struct V_15 * V_16 = NULL ;
struct V_88 * V_89 ;
int V_90 , V_91 ;
if ( F_40 ( V_2 -> V_92 != V_93 ) )
return 1 ;
V_91 = V_6 -> V_94 ;
if ( V_91 > V_95 )
V_91 += F_41 ( V_6 -> V_94 ) ;
if ( V_2 -> V_30 < V_91 ) {
V_87 = 1 ;
if ( F_42 (
V_91 - V_2 -> V_30 ,
& V_28 ) < 0 ) {
F_43 (
& V_2 -> V_96 ,
F_31 ,
V_2 ,
V_91 ) ;
return 1 ;
}
} else
V_87 = 0 ;
V_81 = F_44 ( & V_2 -> V_97 , V_2 -> V_97 . V_98 ) ;
V_9 = F_1 ( V_2 ) ;
V_2 -> V_5 [ V_9 ] . V_11 = V_6 ;
if ( F_40 ( V_6 -> V_99 & ( V_100 | V_101 ) ) ) {
V_81 -> V_102 = V_40 ;
V_81 -> V_7 . V_103 . V_104 = F_45 ( V_6 ) ;
V_81 -> V_7 . V_103 . V_9 = V_9 ;
V_81 -> V_7 . V_103 . V_105 = ( V_106 ) F_46 ( V_6 ) ;
if ( ( V_6 -> V_99 & V_101 ) && V_2 -> V_107 )
V_81 -> V_7 . V_103 . V_108 = V_109 ;
else
V_81 -> V_7 . V_103 . V_108 = 0 ;
} else {
F_2 ( V_2 -> V_110 == 0 &&
V_6 -> V_94 > V_95 ) ;
F_2 ( V_2 -> V_110 &&
V_6 -> V_94 > V_2 -> V_110 ) ;
V_90 = F_47 ( V_6 -> V_111 , V_6 , V_2 -> V_5 [ V_9 ] . V_89 ) ;
V_81 -> V_7 . V_8 . V_9 = V_9 ;
if ( V_90 > V_95 ) {
F_2 ( V_6 -> V_99 & ( V_112 | V_113 ) ) ;
V_81 -> V_102 = V_114 ;
V_81 -> V_7 . V_115 . V_116 = F_48 ( V_6 ) ?
V_37 : V_36 ;
V_81 -> V_7 . V_115 . V_105 = ( V_106 ) F_46 ( V_6 ) ;
V_81 -> V_7 . V_115 . V_117 = V_2 -> V_117 ;
V_81 -> V_7 . V_115 . V_118 = V_90 ;
} else {
V_81 -> V_7 . V_8 . V_105 = ( V_106 ) F_46 ( V_6 ) ;
V_81 -> V_7 . V_8 . V_117 = V_2 -> V_117 ;
V_81 -> V_102 = F_48 ( V_6 ) ?
V_37 : V_36 ;
if ( V_6 -> V_99 & ( V_112 | V_113 ) ) {
V_81 -> V_102 = V_2 -> V_119 ;
}
V_81 -> V_7 . V_8 . V_118 = V_90 ;
}
F_49 (info->shadow[id].sg, sg, nseg, i) {
V_82 = V_89 -> V_120 >> 9 ;
V_83 = V_82 + ( V_89 -> V_121 >> 9 ) - 1 ;
if ( ( V_81 -> V_102 == V_114 ) &&
( V_18 % V_122 == 0 ) ) {
unsigned long V_123 ( V_22 ) ;
if ( V_86 )
F_50 ( V_86 ) ;
V_17 = V_18 / V_122 ;
if ( ! V_2 -> V_21 ) {
struct V_13 * V_124 ;
F_2 ( F_15 ( & V_2 -> V_125 ) ) ;
V_124 = F_16 ( & V_2 -> V_125 ,
struct V_13 , V_126 ) ;
F_11 ( & V_124 -> V_126 ) ;
V_22 = F_8 ( V_124 ) ;
}
V_16 = F_14 ( & V_28 , V_22 , V_2 ) ;
V_2 -> V_5 [ V_9 ] . V_127 [ V_17 ] = V_16 ;
V_86 = F_51 ( F_13 ( V_16 -> V_22 ) ) ;
V_81 -> V_7 . V_115 . V_128 [ V_17 ] = V_16 -> V_23 ;
}
V_16 = F_14 ( & V_28 , F_8 ( F_52 ( V_89 ) ) , V_2 ) ;
V_84 = V_16 -> V_23 ;
V_2 -> V_5 [ V_9 ] . V_129 [ V_18 ] = V_16 ;
if ( F_48 ( V_6 ) && V_2 -> V_21 ) {
char * V_130 ;
void * V_131 ;
F_2 ( V_89 -> V_120 + V_89 -> V_121 > V_132 ) ;
V_131 = F_51 ( F_13 ( V_16 -> V_22 ) ) ;
V_130 = F_51 ( F_52 ( V_89 ) ) ;
memcpy ( V_131 + V_89 -> V_120 ,
V_130 + V_89 -> V_120 ,
V_89 -> V_121 ) ;
F_50 ( V_130 ) ;
F_50 ( V_131 ) ;
}
if ( V_81 -> V_102 != V_114 ) {
V_81 -> V_7 . V_8 . V_133 [ V_18 ] =
(struct V_85 ) {
. V_23 = V_84 ,
. V_134 = V_82 ,
. V_135 = V_83 } ;
} else {
V_17 = V_18 % V_122 ;
V_86 [ V_17 ] =
(struct V_85 ) {
. V_23 = V_84 ,
. V_134 = V_82 ,
. V_135 = V_83 } ;
}
}
if ( V_86 )
F_50 ( V_86 ) ;
}
V_2 -> V_97 . V_98 ++ ;
V_2 -> V_5 [ V_9 ] . V_6 = * V_81 ;
if ( V_87 )
F_53 ( V_28 ) ;
return 0 ;
}
static inline void F_54 ( struct V_1 * V_2 )
{
int V_136 ;
F_55 ( & V_2 -> V_97 , V_136 ) ;
if ( V_136 )
F_56 ( V_2 -> V_137 ) ;
}
static void F_57 ( struct V_138 * V_139 )
{
struct V_1 * V_2 = NULL ;
struct V_11 * V_6 ;
int V_140 ;
F_58 ( L_10 ) ;
V_140 = 0 ;
while ( ( V_6 = F_59 ( V_139 ) ) != NULL ) {
V_2 = V_6 -> V_79 -> V_68 ;
if ( F_60 ( & V_2 -> V_97 ) )
goto V_141;
F_61 ( V_6 ) ;
if ( ( V_6 -> V_142 != V_143 ) ||
( ( V_6 -> V_99 & ( V_112 | V_113 ) ) &&
! V_2 -> V_119 ) ) {
F_62 ( V_6 , - V_144 ) ;
continue;
}
F_58 ( L_11
L_12 ,
V_6 , V_6 -> V_145 , ( unsigned long ) F_46 ( V_6 ) ,
F_63 ( V_6 ) , F_45 ( V_6 ) ,
V_6 -> V_146 , F_48 ( V_6 ) ? L_2 : L_1 ) ;
if ( F_39 ( V_6 ) ) {
F_64 ( V_139 , V_6 ) ;
V_141:
F_65 ( V_139 ) ;
break;
}
V_140 ++ ;
}
if ( V_140 != 0 )
F_54 ( V_2 ) ;
}
static int F_66 ( struct V_75 * V_76 , T_4 V_147 ,
unsigned int V_148 ,
unsigned int V_86 )
{
struct V_138 * V_139 ;
struct V_1 * V_2 = V_76 -> V_68 ;
V_139 = F_67 ( F_57 , & V_2 -> V_149 ) ;
if ( V_139 == NULL )
return - 1 ;
F_68 ( V_150 , V_139 ) ;
if ( V_2 -> V_151 ) {
F_68 ( V_152 , V_139 ) ;
F_69 ( V_139 , F_34 ( V_76 ) ) ;
V_139 -> V_153 . V_154 = V_2 -> V_154 ;
V_139 -> V_153 . V_155 = V_2 -> V_155 ;
if ( V_2 -> V_107 )
F_68 ( V_156 , V_139 ) ;
}
F_70 ( V_139 , V_147 ) ;
F_71 ( V_139 , V_148 ) ;
F_72 ( V_139 , ( V_86 * V_132 ) / 512 ) ;
F_73 ( V_139 , V_132 - 1 ) ;
F_74 ( V_139 , V_132 ) ;
F_75 ( V_139 , V_86 ) ;
F_76 ( V_139 , 511 ) ;
F_77 ( V_139 , V_157 ) ;
V_76 -> V_158 = V_139 ;
return 0 ;
}
static void F_78 ( struct V_1 * V_2 )
{
F_79 ( V_2 -> V_139 , V_2 -> V_159 ) ;
F_80 ( V_160 L_13 ,
V_2 -> V_76 -> V_161 ,
V_2 -> V_119 == V_38 ?
L_3 : ( V_2 -> V_119 == V_39 ?
L_14 : L_15 ) ,
V_2 -> V_159 ? L_16 : L_17 ,
L_18 ,
V_2 -> V_21 ? L_16 : L_17 ,
L_19 ,
V_2 -> V_110 ? L_16 : L_17 ) ;
}
static int F_81 ( int V_162 , int * V_41 , unsigned int * V_120 )
{
int V_163 ;
V_163 = F_82 ( V_162 ) ;
* V_41 = F_83 ( V_162 ) ;
switch ( V_163 ) {
case V_164 :
* V_120 = ( * V_41 / 64 ) + V_165 ;
* V_41 = ( ( * V_41 / 64 ) * V_166 ) +
V_167 ;
break;
case V_168 :
* V_120 = ( * V_41 / 64 ) + 2 + V_165 ;
* V_41 = ( ( ( * V_41 / 64 ) + 2 ) * V_166 ) +
V_167 ;
break;
case V_169 :
* V_120 = ( * V_41 / V_166 ) + V_170 ;
* V_41 = * V_41 + V_171 ;
break;
case V_172 :
case V_173 :
case V_174 :
case V_175 :
case V_176 :
case V_177 :
case V_178 :
* V_120 = ( * V_41 / V_166 ) +
( ( V_163 - V_172 + 1 ) * 16 ) +
V_170 ;
* V_41 = * V_41 +
( ( V_163 - V_172 + 1 ) * 16 * V_166 ) +
V_171 ;
break;
case V_179 :
case V_180 :
case V_181 :
case V_182 :
case V_183 :
case V_184 :
case V_185 :
case V_186 :
* V_120 = ( * V_41 / V_166 ) +
( ( V_163 - V_179 + 8 ) * 16 ) +
V_170 ;
* V_41 = * V_41 +
( ( V_163 - V_179 + 8 ) * 16 * V_166 ) +
V_171 ;
break;
case V_187 :
* V_120 = * V_41 / V_166 ;
break;
default:
F_80 ( V_188 L_20
L_21 ) ;
return - V_189 ;
}
return 0 ;
}
static char * F_84 ( char * V_190 , unsigned int V_17 )
{
if ( V_17 >= 26 )
V_190 = F_84 ( V_190 , V_17 / 26 - 1 ) ;
* V_190 = 'a' + V_17 % 26 ;
return V_190 + 1 ;
}
static int F_85 ( V_106 V_191 ,
struct V_1 * V_2 ,
T_4 V_192 , T_4 V_147 ,
unsigned int V_148 )
{
struct V_75 * V_76 ;
int V_45 = 1 ;
int V_193 ;
unsigned int V_120 ;
int V_41 ;
int V_194 ;
char * V_190 ;
F_2 ( V_2 -> V_76 != NULL ) ;
F_2 ( V_2 -> V_139 != NULL ) ;
if ( ( V_2 -> V_162 >> V_195 ) > 1 ) {
F_80 ( V_188 L_22 , V_2 -> V_162 ) ;
return - V_189 ;
}
if ( ! F_86 ( V_2 -> V_162 ) ) {
V_193 = F_81 ( V_2 -> V_162 , & V_41 , & V_120 ) ;
if ( V_193 )
return V_193 ;
V_194 = V_166 ;
} else {
V_41 = F_87 ( V_2 -> V_162 ) ;
V_194 = V_196 ;
V_120 = V_41 / V_194 ;
if ( F_88 () && V_120 < V_165 + 4 )
F_80 ( V_188 L_23
L_24
L_25 , V_2 -> V_162 ) ;
}
if ( V_41 >> V_197 ) {
F_89 ( L_26 ,
V_2 -> V_162 , V_41 ) ;
return - V_189 ;
}
if ( ( V_41 % V_194 ) == 0 )
V_45 = V_194 ;
V_193 = F_22 ( V_41 , V_45 ) ;
if ( V_193 )
goto V_198;
V_193 = - V_189 ;
V_76 = F_90 ( V_45 ) ;
if ( V_76 == NULL )
goto V_199;
strcpy ( V_76 -> V_161 , V_200 ) ;
V_190 = F_84 ( V_76 -> V_161 + sizeof( V_200 ) - 1 , V_120 ) ;
F_2 ( V_190 >= V_76 -> V_161 + V_201 ) ;
if ( V_45 > 1 )
* V_190 = 0 ;
else
snprintf ( V_190 , V_76 -> V_161 + V_201 - V_190 ,
L_27 , V_41 & ( V_194 - 1 ) ) ;
V_76 -> V_163 = V_187 ;
V_76 -> V_202 = V_41 ;
V_76 -> V_203 = & V_204 ;
V_76 -> V_68 = V_2 ;
V_76 -> V_205 = & ( V_2 -> V_32 -> V_69 ) ;
F_91 ( V_76 , V_191 ) ;
if ( F_66 ( V_76 , V_147 , V_148 ,
V_2 -> V_110 ? :
V_95 ) ) {
F_92 ( V_76 ) ;
goto V_199;
}
V_2 -> V_139 = V_76 -> V_158 ;
V_2 -> V_76 = V_76 ;
F_78 ( V_2 ) ;
if ( V_192 & V_206 )
F_93 ( V_76 , 1 ) ;
if ( V_192 & V_207 )
V_76 -> V_77 |= V_208 ;
if ( V_192 & V_209 )
V_76 -> V_77 |= V_78 ;
return 0 ;
V_199:
F_29 ( V_41 , V_45 ) ;
V_198:
return V_193 ;
}
static void F_94 ( struct V_1 * V_2 )
{
unsigned int V_41 , V_45 ;
unsigned long V_77 ;
if ( V_2 -> V_139 == NULL )
return;
F_95 ( & V_2 -> V_149 , V_77 ) ;
F_65 ( V_2 -> V_139 ) ;
F_96 ( & V_2 -> V_96 ) ;
F_97 ( & V_2 -> V_149 , V_77 ) ;
F_98 ( & V_2 -> V_54 ) ;
F_92 ( V_2 -> V_76 ) ;
V_41 = V_2 -> V_76 -> V_202 ;
V_45 = V_2 -> V_76 -> V_50 ;
F_29 ( V_41 , V_45 ) ;
F_99 ( V_2 -> V_139 ) ;
V_2 -> V_139 = NULL ;
F_100 ( V_2 -> V_76 ) ;
V_2 -> V_76 = NULL ;
}
static void F_101 ( struct V_1 * V_2 )
{
if ( ! F_60 ( & V_2 -> V_97 ) ) {
F_102 ( V_2 -> V_139 ) ;
F_57 ( V_2 -> V_139 ) ;
}
}
static void F_103 ( struct V_210 * V_54 )
{
struct V_1 * V_2 = F_104 ( V_54 , struct V_1 , V_54 ) ;
F_105 ( & V_2 -> V_149 ) ;
if ( V_2 -> V_92 == V_93 )
F_101 ( V_2 ) ;
F_106 ( & V_2 -> V_149 ) ;
}
static void F_107 ( struct V_1 * V_2 , int V_211 )
{
struct V_15 * V_212 ;
struct V_15 * V_17 ;
int V_18 , V_213 , V_214 ;
F_105 ( & V_2 -> V_149 ) ;
V_2 -> V_92 = V_211 ?
V_215 : V_216 ;
if ( V_2 -> V_139 )
F_65 ( V_2 -> V_139 ) ;
if ( ! F_15 ( & V_2 -> V_26 ) ) {
F_10 (persistent_gnt, n,
&info->grants, node) {
F_11 ( & V_212 -> V_25 ) ;
if ( V_212 -> V_23 != V_24 ) {
F_108 ( V_212 -> V_23 ,
0 , 0UL ) ;
V_2 -> V_30 -- ;
}
if ( V_2 -> V_21 )
F_12 ( F_13 ( V_212 -> V_22 ) ) ;
F_7 ( V_212 ) ;
}
}
F_2 ( V_2 -> V_30 != 0 ) ;
if ( ! F_15 ( & V_2 -> V_125 ) ) {
struct V_13 * V_124 , * V_17 ;
F_2 ( V_2 -> V_21 ) ;
F_10 (indirect_page, n, &info->indirect_pages, lru) {
F_11 ( & V_124 -> V_126 ) ;
F_12 ( V_124 ) ;
}
}
for ( V_18 = 0 ; V_18 < V_4 ; V_18 ++ ) {
if ( ! V_2 -> V_5 [ V_18 ] . V_11 )
goto V_217;
V_214 = V_2 -> V_5 [ V_18 ] . V_6 . V_102 == V_114 ?
V_2 -> V_5 [ V_18 ] . V_6 . V_7 . V_115 . V_118 :
V_2 -> V_5 [ V_18 ] . V_6 . V_7 . V_8 . V_118 ;
for ( V_213 = 0 ; V_213 < V_214 ; V_213 ++ ) {
V_212 = V_2 -> V_5 [ V_18 ] . V_129 [ V_213 ] ;
F_108 ( V_212 -> V_23 , 0 , 0UL ) ;
if ( V_2 -> V_21 )
F_12 ( F_13 ( V_212 -> V_22 ) ) ;
F_7 ( V_212 ) ;
}
if ( V_2 -> V_5 [ V_18 ] . V_6 . V_102 != V_114 )
goto V_217;
for ( V_213 = 0 ; V_213 < F_41 ( V_214 ) ; V_213 ++ ) {
V_212 = V_2 -> V_5 [ V_18 ] . V_127 [ V_213 ] ;
F_108 ( V_212 -> V_23 , 0 , 0UL ) ;
F_12 ( F_13 ( V_212 -> V_22 ) ) ;
F_7 ( V_212 ) ;
}
V_217:
F_7 ( V_2 -> V_5 [ V_18 ] . V_129 ) ;
V_2 -> V_5 [ V_18 ] . V_129 = NULL ;
F_7 ( V_2 -> V_5 [ V_18 ] . V_127 ) ;
V_2 -> V_5 [ V_18 ] . V_127 = NULL ;
F_7 ( V_2 -> V_5 [ V_18 ] . V_89 ) ;
V_2 -> V_5 [ V_18 ] . V_89 = NULL ;
}
F_96 ( & V_2 -> V_96 ) ;
F_106 ( & V_2 -> V_149 ) ;
F_98 ( & V_2 -> V_54 ) ;
if ( V_2 -> V_218 != V_24 ) {
F_108 ( V_2 -> V_218 , 0 ,
( unsigned long ) V_2 -> V_97 . V_219 ) ;
V_2 -> V_218 = V_24 ;
V_2 -> V_97 . V_219 = NULL ;
}
if ( V_2 -> V_137 )
F_109 ( V_2 -> V_137 , V_2 ) ;
V_2 -> V_220 = V_2 -> V_137 = 0 ;
}
static void F_110 ( struct V_221 * V_222 , struct V_1 * V_2 ,
struct V_223 * V_224 )
{
int V_18 = 0 ;
struct V_88 * V_89 ;
char * V_130 ;
void * V_131 ;
int V_90 ;
V_90 = V_222 -> V_6 . V_102 == V_114 ?
V_222 -> V_6 . V_7 . V_115 . V_118 : V_222 -> V_6 . V_7 . V_8 . V_118 ;
if ( V_224 -> V_102 == V_36 && V_2 -> V_21 ) {
F_49 (s->sg, sg, nseg, i) {
F_2 ( V_89 -> V_120 + V_89 -> V_121 > V_132 ) ;
V_131 = F_51 (
F_13 ( V_222 -> V_129 [ V_18 ] -> V_22 ) ) ;
V_130 = F_51 ( F_52 ( V_89 ) ) ;
memcpy ( V_130 + V_89 -> V_120 ,
V_131 + V_89 -> V_120 ,
V_89 -> V_121 ) ;
F_50 ( V_130 ) ;
F_50 ( V_131 ) ;
}
}
for ( V_18 = 0 ; V_18 < V_90 ; V_18 ++ ) {
if ( F_111 ( V_222 -> V_129 [ V_18 ] -> V_23 ) ) {
if ( ! V_2 -> V_21 )
F_112 ( L_28 ,
V_222 -> V_129 [ V_18 ] -> V_23 ) ;
F_9 ( & V_222 -> V_129 [ V_18 ] -> V_25 , & V_2 -> V_26 ) ;
V_2 -> V_30 ++ ;
} else {
F_108 ( V_222 -> V_129 [ V_18 ] -> V_23 , 0 , 0UL ) ;
V_222 -> V_129 [ V_18 ] -> V_23 = V_24 ;
F_113 ( & V_222 -> V_129 [ V_18 ] -> V_25 , & V_2 -> V_26 ) ;
}
}
if ( V_222 -> V_6 . V_102 == V_114 ) {
for ( V_18 = 0 ; V_18 < F_41 ( V_90 ) ; V_18 ++ ) {
if ( F_111 ( V_222 -> V_127 [ V_18 ] -> V_23 ) ) {
if ( ! V_2 -> V_21 )
F_112 ( L_28 ,
V_222 -> V_127 [ V_18 ] -> V_23 ) ;
F_9 ( & V_222 -> V_127 [ V_18 ] -> V_25 , & V_2 -> V_26 ) ;
V_2 -> V_30 ++ ;
} else {
struct V_13 * V_124 ;
F_108 ( V_222 -> V_127 [ V_18 ] -> V_23 , 0 , 0UL ) ;
V_124 = F_13 ( V_222 -> V_127 [ V_18 ] -> V_22 ) ;
F_9 ( & V_124 -> V_126 , & V_2 -> V_125 ) ;
V_222 -> V_127 [ V_18 ] -> V_23 = V_24 ;
F_113 ( & V_222 -> V_127 [ V_18 ] -> V_25 , & V_2 -> V_26 ) ;
}
}
}
}
static T_5 F_114 ( int V_137 , void * V_225 )
{
struct V_11 * V_6 ;
struct V_223 * V_224 ;
T_6 V_18 , V_226 ;
unsigned long V_77 ;
struct V_1 * V_2 = (struct V_1 * ) V_225 ;
int error ;
F_95 ( & V_2 -> V_149 , V_77 ) ;
if ( F_40 ( V_2 -> V_92 != V_93 ) ) {
F_97 ( & V_2 -> V_149 , V_77 ) ;
return V_227 ;
}
V_228:
V_226 = V_2 -> V_97 . V_219 -> V_229 ;
F_115 () ;
for ( V_18 = V_2 -> V_97 . V_230 ; V_18 != V_226 ; V_18 ++ ) {
unsigned long V_9 ;
V_224 = F_116 ( & V_2 -> V_97 , V_18 ) ;
V_9 = V_224 -> V_9 ;
if ( V_9 >= V_4 ) {
F_117 ( 1 , L_29 ,
V_2 -> V_76 -> V_161 , F_20 ( V_224 -> V_102 ) , V_9 ) ;
continue;
}
V_6 = V_2 -> V_5 [ V_9 ] . V_11 ;
if ( V_224 -> V_102 != V_40 )
F_110 ( & V_2 -> V_5 [ V_9 ] , V_2 , V_224 ) ;
if ( F_3 ( V_2 , V_9 ) ) {
F_117 ( 1 , L_30 ,
V_2 -> V_76 -> V_161 , F_20 ( V_224 -> V_102 ) , V_9 ) ;
continue;
}
error = ( V_224 -> V_231 == V_232 ) ? 0 : - V_144 ;
switch ( V_224 -> V_102 ) {
case V_40 :
if ( F_40 ( V_224 -> V_231 == V_233 ) ) {
struct V_138 * V_139 = V_2 -> V_139 ;
F_80 ( V_188 L_31 ,
V_2 -> V_76 -> V_161 , F_20 ( V_224 -> V_102 ) ) ;
error = - V_234 ;
V_2 -> V_151 = 0 ;
V_2 -> V_107 = 0 ;
F_118 ( V_152 , V_139 ) ;
F_118 ( V_156 , V_139 ) ;
}
F_62 ( V_6 , error ) ;
break;
case V_39 :
case V_38 :
if ( F_40 ( V_224 -> V_231 == V_233 ) ) {
F_80 ( V_188 L_31 ,
V_2 -> V_76 -> V_161 , F_20 ( V_224 -> V_102 ) ) ;
error = - V_234 ;
}
if ( F_40 ( V_224 -> V_231 == V_235 &&
V_2 -> V_5 [ V_9 ] . V_6 . V_7 . V_8 . V_118 == 0 ) ) {
F_80 ( V_188 L_32 ,
V_2 -> V_76 -> V_161 , F_20 ( V_224 -> V_102 ) ) ;
error = - V_234 ;
}
if ( F_40 ( error ) ) {
if ( error == - V_234 )
error = 0 ;
V_2 -> V_159 = 0 ;
V_2 -> V_119 = 0 ;
F_78 ( V_2 ) ;
}
case V_36 :
case V_37 :
if ( F_40 ( V_224 -> V_231 != V_232 ) )
F_37 ( & V_2 -> V_32 -> V_69 , L_33
L_34 , V_224 -> V_231 ) ;
F_62 ( V_6 , error ) ;
break;
default:
F_119 () ;
}
}
V_2 -> V_97 . V_230 = V_18 ;
if ( V_18 != V_2 -> V_97 . V_98 ) {
int V_236 ;
F_120 ( & V_2 -> V_97 , V_236 ) ;
if ( V_236 )
goto V_228;
} else
V_2 -> V_97 . V_219 -> V_237 = V_18 + 1 ;
F_101 ( V_2 ) ;
F_97 ( & V_2 -> V_149 , V_77 ) ;
return V_227 ;
}
static int F_121 ( struct V_238 * V_69 ,
struct V_1 * V_2 )
{
struct V_239 * V_219 ;
int V_193 ;
V_2 -> V_218 = V_24 ;
V_219 = (struct V_239 * ) F_122 ( V_19 | V_240 ) ;
if ( ! V_219 ) {
F_123 ( V_69 , - V_27 , L_35 ) ;
return - V_27 ;
}
F_124 ( V_219 ) ;
F_125 ( & V_2 -> V_97 , V_219 , V_132 ) ;
V_193 = F_126 ( V_69 , F_127 ( V_2 -> V_97 . V_219 ) ) ;
if ( V_193 < 0 ) {
F_128 ( ( unsigned long ) V_219 ) ;
V_2 -> V_97 . V_219 = NULL ;
goto V_241;
}
V_2 -> V_218 = V_193 ;
V_193 = F_129 ( V_69 , & V_2 -> V_220 ) ;
if ( V_193 )
goto V_241;
V_193 = F_130 ( V_2 -> V_220 , F_114 , 0 ,
L_36 , V_2 ) ;
if ( V_193 <= 0 ) {
F_123 ( V_69 , V_193 ,
L_37 ) ;
goto V_241;
}
V_2 -> V_137 = V_193 ;
return 0 ;
V_241:
F_107 ( V_2 , 0 ) ;
return V_193 ;
}
static int F_131 ( struct V_238 * V_69 ,
struct V_1 * V_2 )
{
const char * V_242 = NULL ;
struct V_243 V_244 ;
int V_193 ;
V_193 = F_121 ( V_69 , V_2 ) ;
if ( V_193 )
goto V_198;
V_228:
V_193 = F_132 ( & V_244 ) ;
if ( V_193 ) {
F_123 ( V_69 , V_193 , L_38 ) ;
goto V_245;
}
V_193 = F_133 ( V_244 , V_69 -> V_246 ,
L_39 , L_40 , V_2 -> V_218 ) ;
if ( V_193 ) {
V_242 = L_41 ;
goto V_247;
}
V_193 = F_133 ( V_244 , V_69 -> V_246 ,
L_42 , L_40 , V_2 -> V_220 ) ;
if ( V_193 ) {
V_242 = L_43 ;
goto V_247;
}
V_193 = F_133 ( V_244 , V_69 -> V_246 , L_44 , L_45 ,
V_248 ) ;
if ( V_193 ) {
V_242 = L_46 ;
goto V_247;
}
V_193 = F_133 ( V_244 , V_69 -> V_246 ,
L_47 , L_40 , 1 ) ;
if ( V_193 )
F_134 ( & V_69 -> V_69 ,
L_48 ) ;
V_193 = F_135 ( V_244 , 0 ) ;
if ( V_193 ) {
if ( V_193 == - V_249 )
goto V_228;
F_123 ( V_69 , V_193 , L_49 ) ;
goto V_245;
}
F_136 ( V_69 , V_250 ) ;
return 0 ;
V_247:
F_135 ( V_244 , 1 ) ;
if ( V_242 )
F_123 ( V_69 , V_193 , L_45 , V_242 ) ;
V_245:
F_107 ( V_2 , 0 ) ;
V_198:
return V_193 ;
}
static int F_137 ( struct V_238 * V_69 ,
const struct V_251 * V_9 )
{
int V_193 , V_162 , V_18 ;
struct V_1 * V_2 ;
V_193 = F_138 ( V_252 , V_69 -> V_246 ,
L_50 , L_51 , & V_162 ) ;
if ( V_193 != 1 ) {
V_193 = F_138 ( V_252 , V_69 -> V_246 , L_52 ,
L_51 , & V_162 ) ;
if ( V_193 != 1 ) {
F_123 ( V_69 , V_193 , L_53 ) ;
return V_193 ;
}
}
if ( F_88 () ) {
char * type ;
int V_253 ;
if ( F_139 () ) {
int V_163 ;
if ( ! F_86 ( V_162 ) )
V_163 = F_82 ( V_162 ) ;
else
V_163 = V_187 ;
if ( V_163 != V_187 ) {
F_80 ( V_160
L_54 ,
V_254 , V_162 ) ;
return - V_189 ;
}
}
type = F_140 ( V_252 , V_69 -> V_246 , L_55 , & V_253 ) ;
if ( F_141 ( type ) )
return - V_189 ;
if ( strncmp ( type , L_56 , 5 ) == 0 ) {
F_7 ( type ) ;
return - V_189 ;
}
F_7 ( type ) ;
}
V_2 = F_5 ( sizeof( * V_2 ) , V_48 ) ;
if ( ! V_2 ) {
F_123 ( V_69 , - V_27 , L_57 ) ;
return - V_27 ;
}
F_142 ( & V_2 -> V_255 ) ;
F_143 ( & V_2 -> V_149 ) ;
V_2 -> V_32 = V_69 ;
V_2 -> V_162 = V_162 ;
F_144 ( & V_2 -> V_26 ) ;
F_144 ( & V_2 -> V_125 ) ;
V_2 -> V_30 = 0 ;
V_2 -> V_92 = V_216 ;
F_145 ( & V_2 -> V_54 , F_103 ) ;
for ( V_18 = 0 ; V_18 < V_4 ; V_18 ++ )
V_2 -> V_5 [ V_18 ] . V_6 . V_7 . V_8 . V_9 = V_18 + 1 ;
V_2 -> V_5 [ V_4 - 1 ] . V_6 . V_7 . V_8 . V_9 = 0x0fffffff ;
V_2 -> V_117 = F_146 ( strrchr ( V_69 -> V_246 , '/' ) + 1 , NULL , 0 ) ;
F_147 ( & V_69 -> V_69 , V_2 ) ;
V_193 = F_131 ( V_69 , V_2 ) ;
if ( V_193 ) {
F_7 ( V_2 ) ;
F_147 ( & V_69 -> V_69 , NULL ) ;
return V_193 ;
}
return 0 ;
}
static void F_148 ( struct V_256 * V_256 , int error )
{
struct V_257 * V_257 = V_256 -> V_258 ;
if ( error )
V_257 -> V_193 = error ;
if ( F_149 ( & V_257 -> V_259 ) ) {
V_257 -> V_256 -> V_260 = 0 ;
F_150 ( V_257 -> V_256 , V_257 -> V_193 ) ;
F_7 ( V_257 ) ;
}
F_151 ( V_256 ) ;
}
static int F_152 ( struct V_1 * V_2 )
{
int V_18 ;
struct V_11 * V_6 , * V_17 ;
struct V_221 * V_261 ;
int V_44 ;
struct V_256 * V_256 , * V_262 ;
struct V_263 V_263 , V_264 ;
unsigned int V_214 , V_120 ;
int V_259 , V_265 ;
struct V_257 * V_257 ;
struct V_266 V_267 ;
V_261 = F_153 ( V_2 -> V_5 , sizeof( V_2 -> V_5 ) ,
V_19 | V_268 | V_240 ) ;
if ( ! V_261 )
return - V_27 ;
memset ( & V_2 -> V_5 , 0 , sizeof( V_2 -> V_5 ) ) ;
for ( V_18 = 0 ; V_18 < V_4 ; V_18 ++ )
V_2 -> V_5 [ V_18 ] . V_6 . V_7 . V_8 . V_9 = V_18 + 1 ;
V_2 -> V_3 = V_2 -> V_97 . V_98 ;
V_2 -> V_5 [ V_4 - 1 ] . V_6 . V_7 . V_8 . V_9 = 0x0fffffff ;
V_44 = F_154 ( V_2 ) ;
if ( V_44 ) {
F_7 ( V_261 ) ;
return V_44 ;
}
V_214 = V_2 -> V_110 ? : V_95 ;
F_75 ( V_2 -> V_139 , V_214 ) ;
F_155 ( & V_263 ) ;
F_144 ( & V_267 ) ;
for ( V_18 = 0 ; V_18 < V_4 ; V_18 ++ ) {
if ( ! V_261 [ V_18 ] . V_11 )
continue;
if ( V_261 [ V_18 ] . V_11 -> V_99 &
( V_112 | V_113 | V_100 | V_101 ) ) {
F_9 ( & V_261 [ V_18 ] . V_11 -> V_269 , & V_267 ) ;
continue;
}
V_264 . V_270 = V_261 [ V_18 ] . V_11 -> V_256 ;
V_264 . V_271 = V_261 [ V_18 ] . V_11 -> V_272 ;
F_156 ( & V_263 , & V_264 ) ;
V_261 [ V_18 ] . V_11 -> V_256 = NULL ;
F_157 ( V_261 [ V_18 ] . V_11 ) ;
}
F_7 ( V_261 ) ;
F_105 ( & V_2 -> V_149 ) ;
while ( ( V_6 = F_158 ( V_2 -> V_139 ) ) != NULL ) {
if ( V_6 -> V_99 &
( V_112 | V_113 | V_100 | V_101 ) ) {
F_9 ( & V_6 -> V_269 , & V_267 ) ;
continue;
}
V_264 . V_270 = V_6 -> V_256 ;
V_264 . V_271 = V_6 -> V_272 ;
F_156 ( & V_263 , & V_264 ) ;
V_6 -> V_256 = NULL ;
if ( V_6 -> V_99 & ( V_112 | V_113 ) )
F_159 ( L_58 ) ;
F_160 ( V_2 -> V_139 , V_6 ) ;
}
F_106 ( & V_2 -> V_149 ) ;
F_136 ( V_2 -> V_32 , V_273 ) ;
F_105 ( & V_2 -> V_149 ) ;
V_2 -> V_92 = V_93 ;
F_101 ( V_2 ) ;
F_10 (req, n, &requests, queuelist) {
F_161 ( & V_6 -> V_269 ) ;
F_2 ( V_6 -> V_94 > V_214 ) ;
F_64 ( V_2 -> V_139 , V_6 ) ;
}
F_106 ( & V_2 -> V_149 ) ;
while ( ( V_256 = F_162 ( & V_263 ) ) != NULL ) {
if ( F_163 ( V_256 ) > V_214 ) {
V_259 = ( F_163 ( V_256 ) + V_214 - 1 ) / V_214 ;
V_257 = F_5 ( sizeof( * V_257 ) , V_19 ) ;
F_2 ( V_257 == NULL ) ;
F_164 ( & V_257 -> V_259 , V_259 ) ;
V_257 -> V_256 = V_256 ;
for ( V_18 = 0 ; V_18 < V_259 ; V_18 ++ ) {
V_120 = ( V_18 * V_214 * V_132 ) >> 9 ;
V_265 = F_165 ( ( unsigned int ) ( V_214 * V_132 ) >> 9 ,
( unsigned int ) F_166 ( V_256 ) - V_120 ) ;
V_262 = F_167 ( V_256 , V_19 ) ;
F_2 ( V_262 == NULL ) ;
F_168 ( V_262 , V_120 , V_265 ) ;
V_262 -> V_258 = V_257 ;
V_262 -> V_274 = F_148 ;
F_169 ( V_262 -> V_275 , V_262 ) ;
}
continue;
}
F_169 ( V_256 -> V_275 , V_256 ) ;
}
return 0 ;
}
static int F_170 ( struct V_238 * V_69 )
{
struct V_1 * V_2 = F_171 ( & V_69 -> V_69 ) ;
int V_193 ;
F_37 ( & V_69 -> V_69 , L_59 , V_69 -> V_246 ) ;
F_107 ( V_2 , V_2 -> V_92 == V_93 ) ;
V_193 = F_131 ( V_69 , V_2 ) ;
return V_193 ;
}
static void
F_172 ( struct V_1 * V_2 )
{
struct V_238 * V_32 = V_2 -> V_32 ;
struct V_55 * V_64 = NULL ;
F_173 ( & V_2 -> V_255 ) ;
if ( V_32 -> V_276 == V_277 ) {
F_174 ( & V_2 -> V_255 ) ;
return;
}
if ( V_2 -> V_76 )
V_64 = F_175 ( V_2 -> V_76 , 0 ) ;
F_174 ( & V_2 -> V_255 ) ;
if ( ! V_64 ) {
F_176 ( V_32 ) ;
return;
}
F_173 ( & V_64 -> V_278 ) ;
if ( V_64 -> V_279 ) {
F_177 ( V_32 , - V_52 ,
L_60 ) ;
F_136 ( V_32 , V_277 ) ;
} else {
F_94 ( V_2 ) ;
F_176 ( V_32 ) ;
}
F_174 ( & V_64 -> V_278 ) ;
F_178 ( V_64 ) ;
}
static void F_179 ( struct V_1 * V_2 )
{
int V_193 ;
char * type ;
unsigned int V_154 ;
unsigned int V_155 ;
unsigned int V_280 ;
type = F_140 ( V_252 , V_2 -> V_32 -> V_281 , L_61 , NULL ) ;
if ( F_141 ( type ) )
return;
V_2 -> V_107 = 0 ;
if ( strncmp ( type , L_62 , 3 ) == 0 ) {
V_193 = F_180 ( V_252 , V_2 -> V_32 -> V_281 ,
L_63 , L_40 , & V_154 ,
L_64 , L_40 , & V_155 ,
NULL ) ;
if ( ! V_193 ) {
V_2 -> V_151 = 1 ;
V_2 -> V_154 = V_154 ;
V_2 -> V_155 = V_155 ;
}
V_193 = F_180 ( V_252 , V_2 -> V_32 -> V_281 ,
L_65 , L_27 , & V_280 ,
NULL ) ;
if ( ! V_193 )
V_2 -> V_107 = V_280 ;
} else if ( strncmp ( type , L_66 , 4 ) == 0 )
V_2 -> V_151 = 1 ;
F_7 ( type ) ;
}
static int F_154 ( struct V_1 * V_2 )
{
unsigned int V_282 , V_214 ;
int V_193 , V_18 ;
V_193 = F_180 ( V_252 , V_2 -> V_32 -> V_281 ,
L_67 , L_40 , & V_282 ,
NULL ) ;
if ( V_193 ) {
V_2 -> V_110 = 0 ;
V_214 = V_95 ;
} else {
V_2 -> V_110 = F_165 ( V_282 ,
V_283 ) ;
V_214 = V_2 -> V_110 ;
}
V_193 = F_4 ( V_2 , ( V_214 + F_41 ( V_214 ) ) * V_4 ) ;
if ( V_193 )
goto V_20;
if ( ! V_2 -> V_21 && V_2 -> V_110 ) {
int V_12 = F_41 ( V_214 ) * V_4 ;
F_2 ( ! F_15 ( & V_2 -> V_125 ) ) ;
for ( V_18 = 0 ; V_18 < V_12 ; V_18 ++ ) {
struct V_13 * V_124 = F_6 ( V_19 ) ;
if ( ! V_124 )
goto V_20;
F_9 ( & V_124 -> V_126 , & V_2 -> V_125 ) ;
}
}
for ( V_18 = 0 ; V_18 < V_4 ; V_18 ++ ) {
V_2 -> V_5 [ V_18 ] . V_129 = F_5 (
sizeof( V_2 -> V_5 [ V_18 ] . V_129 [ 0 ] ) * V_214 ,
V_19 ) ;
V_2 -> V_5 [ V_18 ] . V_89 = F_5 ( sizeof( V_2 -> V_5 [ V_18 ] . V_89 [ 0 ] ) * V_214 , V_19 ) ;
if ( V_2 -> V_110 )
V_2 -> V_5 [ V_18 ] . V_127 = F_5 (
sizeof( V_2 -> V_5 [ V_18 ] . V_127 [ 0 ] ) *
F_41 ( V_214 ) ,
V_19 ) ;
if ( ( V_2 -> V_5 [ V_18 ] . V_129 == NULL ) ||
( V_2 -> V_5 [ V_18 ] . V_89 == NULL ) ||
( V_2 -> V_110 &&
( V_2 -> V_5 [ V_18 ] . V_127 == NULL ) ) )
goto V_20;
F_181 ( V_2 -> V_5 [ V_18 ] . V_89 , V_214 ) ;
}
return 0 ;
V_20:
for ( V_18 = 0 ; V_18 < V_4 ; V_18 ++ ) {
F_7 ( V_2 -> V_5 [ V_18 ] . V_129 ) ;
V_2 -> V_5 [ V_18 ] . V_129 = NULL ;
F_7 ( V_2 -> V_5 [ V_18 ] . V_89 ) ;
V_2 -> V_5 [ V_18 ] . V_89 = NULL ;
F_7 ( V_2 -> V_5 [ V_18 ] . V_127 ) ;
V_2 -> V_5 [ V_18 ] . V_127 = NULL ;
}
if ( ! F_15 ( & V_2 -> V_125 ) ) {
struct V_13 * V_124 , * V_17 ;
F_10 (indirect_page, n, &info->indirect_pages, lru) {
F_11 ( & V_124 -> V_126 ) ;
F_12 ( V_124 ) ;
}
}
return - V_27 ;
}
static void F_182 ( struct V_1 * V_2 )
{
unsigned long long V_63 ;
unsigned long V_147 ;
unsigned int V_148 ;
unsigned int V_284 ;
int V_193 ;
int V_285 , V_286 , V_103 , V_287 ;
switch ( V_2 -> V_92 ) {
case V_93 :
V_193 = F_138 ( V_252 , V_2 -> V_32 -> V_281 ,
L_68 , L_69 , & V_63 ) ;
if ( F_183 ( V_193 ) )
return;
F_80 ( V_160 L_70 ,
V_63 ) ;
F_91 ( V_2 -> V_76 , V_63 ) ;
F_184 ( V_2 -> V_76 ) ;
return;
case V_215 :
F_152 ( V_2 ) ;
return;
default:
break;
}
F_37 ( & V_2 -> V_32 -> V_69 , L_71 ,
V_288 , V_2 -> V_32 -> V_281 ) ;
V_193 = F_180 ( V_252 , V_2 -> V_32 -> V_281 ,
L_68 , L_72 , & V_63 ,
L_73 , L_40 , & V_284 ,
L_74 , L_75 , & V_147 ,
NULL ) ;
if ( V_193 ) {
F_123 ( V_2 -> V_32 , V_193 ,
L_76 ,
V_2 -> V_32 -> V_281 ) ;
return;
}
V_193 = F_138 ( V_252 , V_2 -> V_32 -> V_281 ,
L_77 , L_40 , & V_148 ) ;
if ( V_193 != 1 )
V_148 = V_147 ;
V_2 -> V_159 = 0 ;
V_2 -> V_119 = 0 ;
V_193 = F_180 ( V_252 , V_2 -> V_32 -> V_281 ,
L_78 , L_27 , & V_285 ,
NULL ) ;
if ( ! V_193 && V_285 ) {
V_2 -> V_159 = V_112 | V_113 ;
V_2 -> V_119 = V_38 ;
}
V_193 = F_180 ( V_252 , V_2 -> V_32 -> V_281 ,
L_79 , L_27 , & V_286 ,
NULL ) ;
if ( ! V_193 && V_286 ) {
V_2 -> V_159 = V_112 ;
V_2 -> V_119 = V_39 ;
}
V_193 = F_180 ( V_252 , V_2 -> V_32 -> V_281 ,
L_80 , L_27 , & V_103 ,
NULL ) ;
if ( ! V_193 && V_103 )
F_179 ( V_2 ) ;
V_193 = F_180 ( V_252 , V_2 -> V_32 -> V_281 ,
L_47 , L_40 , & V_287 ,
NULL ) ;
if ( V_193 )
V_2 -> V_21 = 0 ;
else
V_2 -> V_21 = V_287 ;
V_193 = F_154 ( V_2 ) ;
if ( V_193 ) {
F_123 ( V_2 -> V_32 , V_193 , L_81 ,
V_2 -> V_32 -> V_281 ) ;
return;
}
V_193 = F_85 ( V_63 , V_2 , V_284 , V_147 ,
V_148 ) ;
if ( V_193 ) {
F_123 ( V_2 -> V_32 , V_193 , L_82 ,
V_2 -> V_32 -> V_281 ) ;
return;
}
F_136 ( V_2 -> V_32 , V_273 ) ;
F_105 ( & V_2 -> V_149 ) ;
V_2 -> V_92 = V_93 ;
F_101 ( V_2 ) ;
F_106 ( & V_2 -> V_149 ) ;
F_185 ( V_2 -> V_76 ) ;
V_2 -> V_289 = 1 ;
}
static void F_186 ( struct V_238 * V_69 ,
enum V_290 V_291 )
{
struct V_1 * V_2 = F_171 ( & V_69 -> V_69 ) ;
F_37 ( & V_69 -> V_69 , L_83 , V_291 ) ;
switch ( V_291 ) {
case V_292 :
case V_293 :
case V_250 :
case V_294 :
case V_295 :
case V_296 :
break;
case V_273 :
F_182 ( V_2 ) ;
break;
case V_297 :
if ( V_69 -> V_276 == V_297 )
break;
case V_277 :
F_172 ( V_2 ) ;
break;
}
}
static int F_187 ( struct V_238 * V_32 )
{
struct V_1 * V_2 = F_171 ( & V_32 -> V_69 ) ;
struct V_55 * V_64 = NULL ;
struct V_75 * V_298 ;
F_37 ( & V_32 -> V_69 , L_84 , V_32 -> V_246 ) ;
F_107 ( V_2 , 0 ) ;
F_173 ( & V_2 -> V_255 ) ;
V_298 = V_2 -> V_76 ;
if ( V_298 )
V_64 = F_175 ( V_298 , 0 ) ;
V_2 -> V_32 = NULL ;
F_174 ( & V_2 -> V_255 ) ;
if ( ! V_64 ) {
F_7 ( V_2 ) ;
return 0 ;
}
F_173 ( & V_64 -> V_278 ) ;
V_2 = V_298 -> V_68 ;
F_134 ( F_188 ( V_298 ) ,
L_85 ,
V_32 -> V_246 , V_64 -> V_279 ) ;
if ( V_2 && ! V_64 -> V_279 ) {
F_94 ( V_2 ) ;
V_298 -> V_68 = NULL ;
F_7 ( V_2 ) ;
}
F_174 ( & V_64 -> V_278 ) ;
F_178 ( V_64 ) ;
return 0 ;
}
static int F_189 ( struct V_238 * V_69 )
{
struct V_1 * V_2 = F_171 ( & V_69 -> V_69 ) ;
return V_2 -> V_289 && V_2 -> V_32 ;
}
static int F_190 ( struct V_55 * V_64 , T_3 V_65 )
{
struct V_75 * V_298 = V_64 -> V_60 ;
struct V_1 * V_2 ;
int V_193 = 0 ;
F_173 ( & V_299 ) ;
V_2 = V_298 -> V_68 ;
if ( ! V_2 ) {
V_193 = - V_300 ;
goto V_198;
}
F_173 ( & V_2 -> V_255 ) ;
if ( ! V_2 -> V_76 )
V_193 = - V_300 ;
F_174 ( & V_2 -> V_255 ) ;
V_198:
F_174 ( & V_299 ) ;
return V_193 ;
}
static void F_191 ( struct V_75 * V_298 , T_3 V_65 )
{
struct V_1 * V_2 = V_298 -> V_68 ;
struct V_55 * V_64 ;
struct V_238 * V_32 ;
F_173 ( & V_299 ) ;
V_64 = F_175 ( V_298 , 0 ) ;
if ( ! V_64 ) {
F_117 ( 1 , L_86 , V_298 -> V_161 ) ;
goto V_301;
}
if ( V_64 -> V_279 )
goto V_198;
F_173 ( & V_2 -> V_255 ) ;
V_32 = V_2 -> V_32 ;
if ( V_32 && V_32 -> V_276 == V_277 ) {
F_192 ( F_188 ( V_64 -> V_60 ) , L_87 ) ;
F_94 ( V_2 ) ;
F_176 ( V_2 -> V_32 ) ;
}
F_174 ( & V_2 -> V_255 ) ;
if ( ! V_32 ) {
F_192 ( F_188 ( V_64 -> V_60 ) , L_87 ) ;
F_94 ( V_2 ) ;
V_298 -> V_68 = NULL ;
F_7 ( V_2 ) ;
}
V_198:
F_178 ( V_64 ) ;
V_301:
F_174 ( & V_299 ) ;
}
static int T_7 F_193 ( void )
{
int V_302 ;
if ( ! F_194 () )
return - V_189 ;
if ( ! F_195 () )
return - V_189 ;
if ( F_196 ( V_187 , V_200 ) ) {
F_80 ( V_188 L_88 ,
V_187 , V_200 ) ;
return - V_189 ;
}
V_302 = F_197 ( & V_303 ) ;
if ( V_302 ) {
F_198 ( V_187 , V_200 ) ;
return V_302 ;
}
return 0 ;
}
static void T_8 F_199 ( void )
{
F_200 ( & V_303 ) ;
F_198 ( V_187 , V_200 ) ;
F_7 ( V_50 ) ;
}
