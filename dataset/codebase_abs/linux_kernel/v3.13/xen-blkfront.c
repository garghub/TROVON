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
(struct V_134 ) {
. V_23 = V_84 ,
. V_135 = V_82 ,
. V_136 = V_83 } ;
} else {
V_17 = V_18 % V_122 ;
V_86 [ V_17 ] =
(struct V_85 ) {
. V_23 = V_84 ,
. V_135 = V_82 ,
. V_136 = V_83 } ;
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
int V_137 ;
F_55 ( & V_2 -> V_97 , V_137 ) ;
if ( V_137 )
F_56 ( V_2 -> V_138 ) ;
}
static void F_57 ( struct V_139 * V_140 )
{
struct V_1 * V_2 = NULL ;
struct V_11 * V_6 ;
int V_141 ;
F_58 ( L_10 ) ;
V_141 = 0 ;
while ( ( V_6 = F_59 ( V_140 ) ) != NULL ) {
V_2 = V_6 -> V_79 -> V_68 ;
if ( F_60 ( & V_2 -> V_97 ) )
goto V_142;
F_61 ( V_6 ) ;
if ( ( V_6 -> V_143 != V_144 ) ||
( ( V_6 -> V_99 & ( V_112 | V_113 ) ) &&
! V_2 -> V_119 ) ) {
F_62 ( V_6 , - V_145 ) ;
continue;
}
F_58 ( L_11
L_12 ,
V_6 , V_6 -> V_146 , ( unsigned long ) F_46 ( V_6 ) ,
F_63 ( V_6 ) , F_45 ( V_6 ) ,
V_6 -> V_147 , F_48 ( V_6 ) ? L_2 : L_1 ) ;
if ( F_39 ( V_6 ) ) {
F_64 ( V_140 , V_6 ) ;
V_142:
F_65 ( V_140 ) ;
break;
}
V_141 ++ ;
}
if ( V_141 != 0 )
F_54 ( V_2 ) ;
}
static int F_66 ( struct V_75 * V_76 , T_4 V_148 ,
unsigned int V_149 ,
unsigned int V_86 )
{
struct V_139 * V_140 ;
struct V_1 * V_2 = V_76 -> V_68 ;
V_140 = F_67 ( F_57 , & V_2 -> V_150 ) ;
if ( V_140 == NULL )
return - 1 ;
F_68 ( V_151 , V_140 ) ;
if ( V_2 -> V_152 ) {
F_68 ( V_153 , V_140 ) ;
F_69 ( V_140 , F_34 ( V_76 ) ) ;
V_140 -> V_154 . V_155 = V_2 -> V_155 ;
V_140 -> V_154 . V_156 = V_2 -> V_156 ;
if ( V_2 -> V_107 )
F_68 ( V_157 , V_140 ) ;
}
F_70 ( V_140 , V_148 ) ;
F_71 ( V_140 , V_149 ) ;
F_72 ( V_140 , ( V_86 * V_132 ) / 512 ) ;
F_73 ( V_140 , V_132 - 1 ) ;
F_74 ( V_140 , V_132 ) ;
F_75 ( V_140 , V_86 ) ;
F_76 ( V_140 , 511 ) ;
F_77 ( V_140 , V_158 ) ;
V_76 -> V_159 = V_140 ;
return 0 ;
}
static void F_78 ( struct V_1 * V_2 )
{
F_79 ( V_2 -> V_140 , V_2 -> V_160 ) ;
F_80 ( V_161 L_13 ,
V_2 -> V_76 -> V_162 ,
V_2 -> V_119 == V_38 ?
L_3 : ( V_2 -> V_119 == V_39 ?
L_14 : L_15 ) ,
V_2 -> V_160 ? L_16 : L_17 ,
L_18 ,
V_2 -> V_21 ? L_16 : L_17 ,
L_19 ,
V_2 -> V_110 ? L_16 : L_17 ) ;
}
static int F_81 ( int V_163 , int * V_41 , unsigned int * V_120 )
{
int V_164 ;
V_164 = F_82 ( V_163 ) ;
* V_41 = F_83 ( V_163 ) ;
switch ( V_164 ) {
case V_165 :
* V_120 = ( * V_41 / 64 ) + V_166 ;
* V_41 = ( ( * V_41 / 64 ) * V_167 ) +
V_168 ;
break;
case V_169 :
* V_120 = ( * V_41 / 64 ) + 2 + V_166 ;
* V_41 = ( ( ( * V_41 / 64 ) + 2 ) * V_167 ) +
V_168 ;
break;
case V_170 :
* V_120 = ( * V_41 / V_167 ) + V_171 ;
* V_41 = * V_41 + V_172 ;
break;
case V_173 :
case V_174 :
case V_175 :
case V_176 :
case V_177 :
case V_178 :
case V_179 :
* V_120 = ( * V_41 / V_167 ) +
( ( V_164 - V_173 + 1 ) * 16 ) +
V_171 ;
* V_41 = * V_41 +
( ( V_164 - V_173 + 1 ) * 16 * V_167 ) +
V_172 ;
break;
case V_180 :
case V_181 :
case V_182 :
case V_183 :
case V_184 :
case V_185 :
case V_186 :
case V_187 :
* V_120 = ( * V_41 / V_167 ) +
( ( V_164 - V_180 + 8 ) * 16 ) +
V_171 ;
* V_41 = * V_41 +
( ( V_164 - V_180 + 8 ) * 16 * V_167 ) +
V_172 ;
break;
case V_188 :
* V_120 = * V_41 / V_167 ;
break;
default:
F_80 ( V_189 L_20
L_21 ) ;
return - V_190 ;
}
return 0 ;
}
static char * F_84 ( char * V_191 , unsigned int V_17 )
{
if ( V_17 >= 26 )
V_191 = F_84 ( V_191 , V_17 / 26 - 1 ) ;
* V_191 = 'a' + V_17 % 26 ;
return V_191 + 1 ;
}
static int F_85 ( V_106 V_192 ,
struct V_1 * V_2 ,
T_4 V_193 , T_4 V_148 ,
unsigned int V_149 )
{
struct V_75 * V_76 ;
int V_45 = 1 ;
int V_194 ;
unsigned int V_120 ;
int V_41 ;
int V_195 ;
char * V_191 ;
F_2 ( V_2 -> V_76 != NULL ) ;
F_2 ( V_2 -> V_140 != NULL ) ;
if ( ( V_2 -> V_163 >> V_196 ) > 1 ) {
F_80 ( V_189 L_22 , V_2 -> V_163 ) ;
return - V_190 ;
}
if ( ! F_86 ( V_2 -> V_163 ) ) {
V_194 = F_81 ( V_2 -> V_163 , & V_41 , & V_120 ) ;
if ( V_194 )
return V_194 ;
V_195 = V_167 ;
} else {
V_41 = F_87 ( V_2 -> V_163 ) ;
V_195 = V_197 ;
V_120 = V_41 / V_195 ;
if ( F_88 () && V_120 < V_166 + 4 )
F_80 ( V_189 L_23
L_24
L_25 , V_2 -> V_163 ) ;
}
if ( V_41 >> V_198 ) {
F_89 ( L_26 ,
V_2 -> V_163 , V_41 ) ;
return - V_190 ;
}
if ( ( V_41 % V_195 ) == 0 )
V_45 = V_195 ;
V_194 = F_22 ( V_41 , V_45 ) ;
if ( V_194 )
goto V_199;
V_194 = - V_190 ;
V_76 = F_90 ( V_45 ) ;
if ( V_76 == NULL )
goto V_200;
strcpy ( V_76 -> V_162 , V_201 ) ;
V_191 = F_84 ( V_76 -> V_162 + sizeof( V_201 ) - 1 , V_120 ) ;
F_2 ( V_191 >= V_76 -> V_162 + V_202 ) ;
if ( V_45 > 1 )
* V_191 = 0 ;
else
snprintf ( V_191 , V_76 -> V_162 + V_202 - V_191 ,
L_27 , V_41 & ( V_195 - 1 ) ) ;
V_76 -> V_164 = V_188 ;
V_76 -> V_203 = V_41 ;
V_76 -> V_204 = & V_205 ;
V_76 -> V_68 = V_2 ;
V_76 -> V_206 = & ( V_2 -> V_32 -> V_69 ) ;
F_91 ( V_76 , V_192 ) ;
if ( F_66 ( V_76 , V_148 , V_149 ,
V_2 -> V_110 ? :
V_95 ) ) {
F_92 ( V_76 ) ;
goto V_200;
}
V_2 -> V_140 = V_76 -> V_159 ;
V_2 -> V_76 = V_76 ;
F_78 ( V_2 ) ;
if ( V_193 & V_207 )
F_93 ( V_76 , 1 ) ;
if ( V_193 & V_208 )
V_76 -> V_77 |= V_209 ;
if ( V_193 & V_210 )
V_76 -> V_77 |= V_78 ;
return 0 ;
V_200:
F_29 ( V_41 , V_45 ) ;
V_199:
return V_194 ;
}
static void F_94 ( struct V_1 * V_2 )
{
unsigned int V_41 , V_45 ;
unsigned long V_77 ;
if ( V_2 -> V_140 == NULL )
return;
F_95 ( & V_2 -> V_150 , V_77 ) ;
F_65 ( V_2 -> V_140 ) ;
F_96 ( & V_2 -> V_96 ) ;
F_97 ( & V_2 -> V_150 , V_77 ) ;
F_98 ( & V_2 -> V_54 ) ;
F_92 ( V_2 -> V_76 ) ;
V_41 = V_2 -> V_76 -> V_203 ;
V_45 = V_2 -> V_76 -> V_50 ;
F_29 ( V_41 , V_45 ) ;
F_99 ( V_2 -> V_140 ) ;
V_2 -> V_140 = NULL ;
F_100 ( V_2 -> V_76 ) ;
V_2 -> V_76 = NULL ;
}
static void F_101 ( struct V_1 * V_2 )
{
if ( ! F_60 ( & V_2 -> V_97 ) ) {
F_102 ( V_2 -> V_140 ) ;
F_57 ( V_2 -> V_140 ) ;
}
}
static void F_103 ( struct V_211 * V_54 )
{
struct V_1 * V_2 = F_104 ( V_54 , struct V_1 , V_54 ) ;
F_105 ( & V_2 -> V_150 ) ;
if ( V_2 -> V_92 == V_93 )
F_101 ( V_2 ) ;
F_106 ( & V_2 -> V_150 ) ;
}
static void F_107 ( struct V_1 * V_2 , int V_212 )
{
struct V_15 * V_213 ;
struct V_15 * V_17 ;
int V_18 , V_214 , V_215 ;
F_105 ( & V_2 -> V_150 ) ;
V_2 -> V_92 = V_212 ?
V_216 : V_217 ;
if ( V_2 -> V_140 )
F_65 ( V_2 -> V_140 ) ;
if ( ! F_15 ( & V_2 -> V_26 ) ) {
F_10 (persistent_gnt, n,
&info->grants, node) {
F_11 ( & V_213 -> V_25 ) ;
if ( V_213 -> V_23 != V_24 ) {
F_108 ( V_213 -> V_23 ,
0 , 0UL ) ;
V_2 -> V_30 -- ;
}
if ( V_2 -> V_21 )
F_12 ( F_13 ( V_213 -> V_22 ) ) ;
F_7 ( V_213 ) ;
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
goto V_218;
V_215 = V_2 -> V_5 [ V_18 ] . V_6 . V_102 == V_114 ?
V_2 -> V_5 [ V_18 ] . V_6 . V_7 . V_115 . V_118 :
V_2 -> V_5 [ V_18 ] . V_6 . V_7 . V_8 . V_118 ;
for ( V_214 = 0 ; V_214 < V_215 ; V_214 ++ ) {
V_213 = V_2 -> V_5 [ V_18 ] . V_129 [ V_214 ] ;
F_108 ( V_213 -> V_23 , 0 , 0UL ) ;
if ( V_2 -> V_21 )
F_12 ( F_13 ( V_213 -> V_22 ) ) ;
F_7 ( V_213 ) ;
}
if ( V_2 -> V_5 [ V_18 ] . V_6 . V_102 != V_114 )
goto V_218;
for ( V_214 = 0 ; V_214 < F_41 ( V_215 ) ; V_214 ++ ) {
V_213 = V_2 -> V_5 [ V_18 ] . V_127 [ V_214 ] ;
F_108 ( V_213 -> V_23 , 0 , 0UL ) ;
F_12 ( F_13 ( V_213 -> V_22 ) ) ;
F_7 ( V_213 ) ;
}
V_218:
F_7 ( V_2 -> V_5 [ V_18 ] . V_129 ) ;
V_2 -> V_5 [ V_18 ] . V_129 = NULL ;
F_7 ( V_2 -> V_5 [ V_18 ] . V_127 ) ;
V_2 -> V_5 [ V_18 ] . V_127 = NULL ;
F_7 ( V_2 -> V_5 [ V_18 ] . V_89 ) ;
V_2 -> V_5 [ V_18 ] . V_89 = NULL ;
}
F_96 ( & V_2 -> V_96 ) ;
F_106 ( & V_2 -> V_150 ) ;
F_98 ( & V_2 -> V_54 ) ;
if ( V_2 -> V_219 != V_24 ) {
F_108 ( V_2 -> V_219 , 0 ,
( unsigned long ) V_2 -> V_97 . V_220 ) ;
V_2 -> V_219 = V_24 ;
V_2 -> V_97 . V_220 = NULL ;
}
if ( V_2 -> V_138 )
F_109 ( V_2 -> V_138 , V_2 ) ;
V_2 -> V_221 = V_2 -> V_138 = 0 ;
}
static void F_110 ( struct V_222 * V_223 , struct V_1 * V_2 ,
struct V_224 * V_225 )
{
int V_18 = 0 ;
struct V_88 * V_89 ;
char * V_130 ;
void * V_131 ;
int V_90 ;
V_90 = V_223 -> V_6 . V_102 == V_114 ?
V_223 -> V_6 . V_7 . V_115 . V_118 : V_223 -> V_6 . V_7 . V_8 . V_118 ;
if ( V_225 -> V_102 == V_36 && V_2 -> V_21 ) {
F_49 (s->sg, sg, nseg, i) {
F_2 ( V_89 -> V_120 + V_89 -> V_121 > V_132 ) ;
V_131 = F_51 (
F_13 ( V_223 -> V_129 [ V_18 ] -> V_22 ) ) ;
V_130 = F_51 ( F_52 ( V_89 ) ) ;
memcpy ( V_130 + V_89 -> V_120 ,
V_131 + V_89 -> V_120 ,
V_89 -> V_121 ) ;
F_50 ( V_130 ) ;
F_50 ( V_131 ) ;
}
}
for ( V_18 = 0 ; V_18 < V_90 ; V_18 ++ ) {
if ( F_111 ( V_223 -> V_129 [ V_18 ] -> V_23 ) ) {
if ( ! V_2 -> V_21 )
F_112 ( L_28 ,
V_223 -> V_129 [ V_18 ] -> V_23 ) ;
F_9 ( & V_223 -> V_129 [ V_18 ] -> V_25 , & V_2 -> V_26 ) ;
V_2 -> V_30 ++ ;
} else {
F_108 ( V_223 -> V_129 [ V_18 ] -> V_23 , 0 , 0UL ) ;
V_223 -> V_129 [ V_18 ] -> V_23 = V_24 ;
F_113 ( & V_223 -> V_129 [ V_18 ] -> V_25 , & V_2 -> V_26 ) ;
}
}
if ( V_223 -> V_6 . V_102 == V_114 ) {
for ( V_18 = 0 ; V_18 < F_41 ( V_90 ) ; V_18 ++ ) {
if ( F_111 ( V_223 -> V_127 [ V_18 ] -> V_23 ) ) {
if ( ! V_2 -> V_21 )
F_112 ( L_28 ,
V_223 -> V_127 [ V_18 ] -> V_23 ) ;
F_9 ( & V_223 -> V_127 [ V_18 ] -> V_25 , & V_2 -> V_26 ) ;
V_2 -> V_30 ++ ;
} else {
struct V_13 * V_124 ;
F_108 ( V_223 -> V_127 [ V_18 ] -> V_23 , 0 , 0UL ) ;
V_124 = F_13 ( V_223 -> V_127 [ V_18 ] -> V_22 ) ;
F_9 ( & V_124 -> V_126 , & V_2 -> V_125 ) ;
V_223 -> V_127 [ V_18 ] -> V_23 = V_24 ;
F_113 ( & V_223 -> V_127 [ V_18 ] -> V_25 , & V_2 -> V_26 ) ;
}
}
}
}
static T_5 F_114 ( int V_138 , void * V_226 )
{
struct V_11 * V_6 ;
struct V_224 * V_225 ;
T_6 V_18 , V_227 ;
unsigned long V_77 ;
struct V_1 * V_2 = (struct V_1 * ) V_226 ;
int error ;
F_95 ( & V_2 -> V_150 , V_77 ) ;
if ( F_40 ( V_2 -> V_92 != V_93 ) ) {
F_97 ( & V_2 -> V_150 , V_77 ) ;
return V_228 ;
}
V_229:
V_227 = V_2 -> V_97 . V_220 -> V_230 ;
F_115 () ;
for ( V_18 = V_2 -> V_97 . V_231 ; V_18 != V_227 ; V_18 ++ ) {
unsigned long V_9 ;
V_225 = F_116 ( & V_2 -> V_97 , V_18 ) ;
V_9 = V_225 -> V_9 ;
if ( V_9 >= V_4 ) {
F_117 ( 1 , L_29 ,
V_2 -> V_76 -> V_162 , F_20 ( V_225 -> V_102 ) , V_9 ) ;
continue;
}
V_6 = V_2 -> V_5 [ V_9 ] . V_11 ;
if ( V_225 -> V_102 != V_40 )
F_110 ( & V_2 -> V_5 [ V_9 ] , V_2 , V_225 ) ;
if ( F_3 ( V_2 , V_9 ) ) {
F_117 ( 1 , L_30 ,
V_2 -> V_76 -> V_162 , F_20 ( V_225 -> V_102 ) , V_9 ) ;
continue;
}
error = ( V_225 -> V_232 == V_233 ) ? 0 : - V_145 ;
switch ( V_225 -> V_102 ) {
case V_40 :
if ( F_40 ( V_225 -> V_232 == V_234 ) ) {
struct V_139 * V_140 = V_2 -> V_140 ;
F_80 ( V_189 L_31 ,
V_2 -> V_76 -> V_162 , F_20 ( V_225 -> V_102 ) ) ;
error = - V_235 ;
V_2 -> V_152 = 0 ;
V_2 -> V_107 = 0 ;
F_118 ( V_153 , V_140 ) ;
F_118 ( V_157 , V_140 ) ;
}
F_62 ( V_6 , error ) ;
break;
case V_39 :
case V_38 :
if ( F_40 ( V_225 -> V_232 == V_234 ) ) {
F_80 ( V_189 L_31 ,
V_2 -> V_76 -> V_162 , F_20 ( V_225 -> V_102 ) ) ;
error = - V_235 ;
}
if ( F_40 ( V_225 -> V_232 == V_236 &&
V_2 -> V_5 [ V_9 ] . V_6 . V_7 . V_8 . V_118 == 0 ) ) {
F_80 ( V_189 L_32 ,
V_2 -> V_76 -> V_162 , F_20 ( V_225 -> V_102 ) ) ;
error = - V_235 ;
}
if ( F_40 ( error ) ) {
if ( error == - V_235 )
error = 0 ;
V_2 -> V_160 = 0 ;
V_2 -> V_119 = 0 ;
F_78 ( V_2 ) ;
}
case V_36 :
case V_37 :
if ( F_40 ( V_225 -> V_232 != V_233 ) )
F_37 ( & V_2 -> V_32 -> V_69 , L_33
L_34 , V_225 -> V_232 ) ;
F_62 ( V_6 , error ) ;
break;
default:
F_119 () ;
}
}
V_2 -> V_97 . V_231 = V_18 ;
if ( V_18 != V_2 -> V_97 . V_98 ) {
int V_237 ;
F_120 ( & V_2 -> V_97 , V_237 ) ;
if ( V_237 )
goto V_229;
} else
V_2 -> V_97 . V_220 -> V_238 = V_18 + 1 ;
F_101 ( V_2 ) ;
F_97 ( & V_2 -> V_150 , V_77 ) ;
return V_228 ;
}
static int F_121 ( struct V_239 * V_69 ,
struct V_1 * V_2 )
{
struct V_240 * V_220 ;
int V_194 ;
V_2 -> V_219 = V_24 ;
V_220 = (struct V_240 * ) F_122 ( V_19 | V_241 ) ;
if ( ! V_220 ) {
F_123 ( V_69 , - V_27 , L_35 ) ;
return - V_27 ;
}
F_124 ( V_220 ) ;
F_125 ( & V_2 -> V_97 , V_220 , V_132 ) ;
V_194 = F_126 ( V_69 , F_127 ( V_2 -> V_97 . V_220 ) ) ;
if ( V_194 < 0 ) {
F_128 ( ( unsigned long ) V_220 ) ;
V_2 -> V_97 . V_220 = NULL ;
goto V_242;
}
V_2 -> V_219 = V_194 ;
V_194 = F_129 ( V_69 , & V_2 -> V_221 ) ;
if ( V_194 )
goto V_242;
V_194 = F_130 ( V_2 -> V_221 , F_114 , 0 ,
L_36 , V_2 ) ;
if ( V_194 <= 0 ) {
F_123 ( V_69 , V_194 ,
L_37 ) ;
goto V_242;
}
V_2 -> V_138 = V_194 ;
return 0 ;
V_242:
F_107 ( V_2 , 0 ) ;
return V_194 ;
}
static int F_131 ( struct V_239 * V_69 ,
struct V_1 * V_2 )
{
const char * V_243 = NULL ;
struct V_244 V_245 ;
int V_194 ;
V_194 = F_121 ( V_69 , V_2 ) ;
if ( V_194 )
goto V_199;
V_229:
V_194 = F_132 ( & V_245 ) ;
if ( V_194 ) {
F_123 ( V_69 , V_194 , L_38 ) ;
goto V_246;
}
V_194 = F_133 ( V_245 , V_69 -> V_247 ,
L_39 , L_40 , V_2 -> V_219 ) ;
if ( V_194 ) {
V_243 = L_41 ;
goto V_248;
}
V_194 = F_133 ( V_245 , V_69 -> V_247 ,
L_42 , L_40 , V_2 -> V_221 ) ;
if ( V_194 ) {
V_243 = L_43 ;
goto V_248;
}
V_194 = F_133 ( V_245 , V_69 -> V_247 , L_44 , L_45 ,
V_249 ) ;
if ( V_194 ) {
V_243 = L_46 ;
goto V_248;
}
V_194 = F_133 ( V_245 , V_69 -> V_247 ,
L_47 , L_40 , 1 ) ;
if ( V_194 )
F_134 ( & V_69 -> V_69 ,
L_48 ) ;
V_194 = F_135 ( V_245 , 0 ) ;
if ( V_194 ) {
if ( V_194 == - V_250 )
goto V_229;
F_123 ( V_69 , V_194 , L_49 ) ;
goto V_246;
}
F_136 ( V_69 , V_251 ) ;
return 0 ;
V_248:
F_135 ( V_245 , 1 ) ;
if ( V_243 )
F_123 ( V_69 , V_194 , L_45 , V_243 ) ;
V_246:
F_107 ( V_2 , 0 ) ;
V_199:
return V_194 ;
}
static int F_137 ( struct V_239 * V_69 ,
const struct V_252 * V_9 )
{
int V_194 , V_163 , V_18 ;
struct V_1 * V_2 ;
V_194 = F_138 ( V_253 , V_69 -> V_247 ,
L_50 , L_51 , & V_163 ) ;
if ( V_194 != 1 ) {
V_194 = F_138 ( V_253 , V_69 -> V_247 , L_52 ,
L_51 , & V_163 ) ;
if ( V_194 != 1 ) {
F_123 ( V_69 , V_194 , L_53 ) ;
return V_194 ;
}
}
if ( F_88 () ) {
char * type ;
int V_254 ;
if ( V_255 & V_256 ) {
int V_164 ;
if ( ! F_86 ( V_163 ) )
V_164 = F_82 ( V_163 ) ;
else
V_164 = V_188 ;
if ( V_164 != V_188 ) {
F_80 ( V_161
L_54 ,
V_257 , V_163 ) ;
return - V_190 ;
}
}
type = F_139 ( V_253 , V_69 -> V_247 , L_55 , & V_254 ) ;
if ( F_140 ( type ) )
return - V_190 ;
if ( strncmp ( type , L_56 , 5 ) == 0 ) {
F_7 ( type ) ;
return - V_190 ;
}
F_7 ( type ) ;
}
V_2 = F_5 ( sizeof( * V_2 ) , V_48 ) ;
if ( ! V_2 ) {
F_123 ( V_69 , - V_27 , L_57 ) ;
return - V_27 ;
}
F_141 ( & V_2 -> V_258 ) ;
F_142 ( & V_2 -> V_150 ) ;
V_2 -> V_32 = V_69 ;
V_2 -> V_163 = V_163 ;
F_143 ( & V_2 -> V_26 ) ;
F_143 ( & V_2 -> V_125 ) ;
V_2 -> V_30 = 0 ;
V_2 -> V_92 = V_217 ;
F_144 ( & V_2 -> V_54 , F_103 ) ;
for ( V_18 = 0 ; V_18 < V_4 ; V_18 ++ )
V_2 -> V_5 [ V_18 ] . V_6 . V_7 . V_8 . V_9 = V_18 + 1 ;
V_2 -> V_5 [ V_4 - 1 ] . V_6 . V_7 . V_8 . V_9 = 0x0fffffff ;
V_2 -> V_117 = F_145 ( strrchr ( V_69 -> V_247 , '/' ) + 1 , NULL , 0 ) ;
F_146 ( & V_69 -> V_69 , V_2 ) ;
V_194 = F_131 ( V_69 , V_2 ) ;
if ( V_194 ) {
F_7 ( V_2 ) ;
F_146 ( & V_69 -> V_69 , NULL ) ;
return V_194 ;
}
return 0 ;
}
static void F_147 ( struct V_259 * V_259 , int error )
{
struct V_260 * V_260 = V_259 -> V_261 ;
if ( error )
V_260 -> V_194 = error ;
if ( F_148 ( & V_260 -> V_262 ) ) {
V_260 -> V_259 -> V_263 = 0 ;
F_149 ( V_260 -> V_259 , V_260 -> V_194 ) ;
F_7 ( V_260 ) ;
}
F_150 ( V_259 ) ;
}
static int F_151 ( struct V_1 * V_2 )
{
int V_18 ;
struct V_11 * V_6 , * V_17 ;
struct V_222 * V_264 ;
int V_44 ;
struct V_259 * V_259 , * V_265 ;
struct V_266 V_266 , V_267 ;
unsigned int V_215 , V_120 ;
int V_262 , V_268 ;
struct V_260 * V_260 ;
struct V_269 V_270 ;
V_264 = F_152 ( V_2 -> V_5 , sizeof( V_2 -> V_5 ) ,
V_19 | V_271 | V_241 ) ;
if ( ! V_264 )
return - V_27 ;
memset ( & V_2 -> V_5 , 0 , sizeof( V_2 -> V_5 ) ) ;
for ( V_18 = 0 ; V_18 < V_4 ; V_18 ++ )
V_2 -> V_5 [ V_18 ] . V_6 . V_7 . V_8 . V_9 = V_18 + 1 ;
V_2 -> V_3 = V_2 -> V_97 . V_98 ;
V_2 -> V_5 [ V_4 - 1 ] . V_6 . V_7 . V_8 . V_9 = 0x0fffffff ;
V_44 = F_153 ( V_2 ) ;
if ( V_44 ) {
F_7 ( V_264 ) ;
return V_44 ;
}
V_215 = V_2 -> V_110 ? : V_95 ;
F_75 ( V_2 -> V_140 , V_215 ) ;
F_154 ( & V_266 ) ;
F_143 ( & V_270 ) ;
for ( V_18 = 0 ; V_18 < V_4 ; V_18 ++ ) {
if ( ! V_264 [ V_18 ] . V_11 )
continue;
if ( V_264 [ V_18 ] . V_11 -> V_99 &
( V_112 | V_113 | V_100 | V_101 ) ) {
F_9 ( & V_264 [ V_18 ] . V_11 -> V_272 , & V_270 ) ;
continue;
}
V_267 . V_273 = V_264 [ V_18 ] . V_11 -> V_259 ;
V_267 . V_274 = V_264 [ V_18 ] . V_11 -> V_275 ;
F_155 ( & V_266 , & V_267 ) ;
V_264 [ V_18 ] . V_11 -> V_259 = NULL ;
F_156 ( V_264 [ V_18 ] . V_11 ) ;
}
F_7 ( V_264 ) ;
F_105 ( & V_2 -> V_150 ) ;
while ( ( V_6 = F_157 ( V_2 -> V_140 ) ) != NULL ) {
if ( V_6 -> V_99 &
( V_112 | V_113 | V_100 | V_101 ) ) {
F_9 ( & V_6 -> V_272 , & V_270 ) ;
continue;
}
V_267 . V_273 = V_6 -> V_259 ;
V_267 . V_274 = V_6 -> V_275 ;
F_155 ( & V_266 , & V_267 ) ;
V_6 -> V_259 = NULL ;
if ( V_6 -> V_99 & ( V_112 | V_113 ) )
F_158 ( L_58 ) ;
F_159 ( V_2 -> V_140 , V_6 ) ;
}
F_106 ( & V_2 -> V_150 ) ;
F_136 ( V_2 -> V_32 , V_276 ) ;
F_105 ( & V_2 -> V_150 ) ;
V_2 -> V_92 = V_93 ;
F_101 ( V_2 ) ;
F_10 (req, n, &requests, queuelist) {
F_160 ( & V_6 -> V_272 ) ;
F_2 ( V_6 -> V_94 > V_215 ) ;
F_64 ( V_2 -> V_140 , V_6 ) ;
}
F_106 ( & V_2 -> V_150 ) ;
while ( ( V_259 = F_161 ( & V_266 ) ) != NULL ) {
if ( F_162 ( V_259 ) > V_215 ) {
V_262 = ( F_162 ( V_259 ) + V_215 - 1 ) / V_215 ;
V_260 = F_5 ( sizeof( * V_260 ) , V_19 ) ;
F_2 ( V_260 == NULL ) ;
F_163 ( & V_260 -> V_262 , V_262 ) ;
V_260 -> V_259 = V_259 ;
for ( V_18 = 0 ; V_18 < V_262 ; V_18 ++ ) {
V_120 = ( V_18 * V_215 * V_132 ) >> 9 ;
V_268 = F_164 ( ( unsigned int ) ( V_215 * V_132 ) >> 9 ,
( unsigned int ) ( V_259 -> V_277 >> 9 ) - V_120 ) ;
V_265 = F_165 ( V_259 , V_19 ) ;
F_2 ( V_265 == NULL ) ;
F_166 ( V_265 , V_120 , V_268 ) ;
V_265 -> V_261 = V_260 ;
V_265 -> V_278 = F_147 ;
F_167 ( V_265 -> V_279 , V_265 ) ;
}
continue;
}
F_167 ( V_259 -> V_279 , V_259 ) ;
}
return 0 ;
}
static int F_168 ( struct V_239 * V_69 )
{
struct V_1 * V_2 = F_169 ( & V_69 -> V_69 ) ;
int V_194 ;
F_37 ( & V_69 -> V_69 , L_59 , V_69 -> V_247 ) ;
F_107 ( V_2 , V_2 -> V_92 == V_93 ) ;
V_194 = F_131 ( V_69 , V_2 ) ;
return V_194 ;
}
static void
F_170 ( struct V_1 * V_2 )
{
struct V_239 * V_32 = V_2 -> V_32 ;
struct V_55 * V_64 = NULL ;
F_171 ( & V_2 -> V_258 ) ;
if ( V_32 -> V_280 == V_281 ) {
F_172 ( & V_2 -> V_258 ) ;
return;
}
if ( V_2 -> V_76 )
V_64 = F_173 ( V_2 -> V_76 , 0 ) ;
F_172 ( & V_2 -> V_258 ) ;
if ( ! V_64 ) {
F_174 ( V_32 ) ;
return;
}
F_171 ( & V_64 -> V_282 ) ;
if ( V_64 -> V_283 ) {
F_175 ( V_32 , - V_52 ,
L_60 ) ;
F_136 ( V_32 , V_281 ) ;
} else {
F_94 ( V_2 ) ;
F_174 ( V_32 ) ;
}
F_172 ( & V_64 -> V_282 ) ;
F_176 ( V_64 ) ;
}
static void F_177 ( struct V_1 * V_2 )
{
int V_194 ;
char * type ;
unsigned int V_155 ;
unsigned int V_156 ;
unsigned int V_284 ;
type = F_139 ( V_253 , V_2 -> V_32 -> V_285 , L_61 , NULL ) ;
if ( F_140 ( type ) )
return;
V_2 -> V_107 = 0 ;
if ( strncmp ( type , L_62 , 3 ) == 0 ) {
V_194 = F_178 ( V_253 , V_2 -> V_32 -> V_285 ,
L_63 , L_40 , & V_155 ,
L_64 , L_40 , & V_156 ,
NULL ) ;
if ( ! V_194 ) {
V_2 -> V_152 = 1 ;
V_2 -> V_155 = V_155 ;
V_2 -> V_156 = V_156 ;
}
V_194 = F_178 ( V_253 , V_2 -> V_32 -> V_285 ,
L_65 , L_27 , & V_284 ,
NULL ) ;
if ( ! V_194 )
V_2 -> V_107 = V_284 ;
} else if ( strncmp ( type , L_66 , 4 ) == 0 )
V_2 -> V_152 = 1 ;
F_7 ( type ) ;
}
static int F_153 ( struct V_1 * V_2 )
{
unsigned int V_286 , V_215 ;
int V_194 , V_18 ;
V_194 = F_178 ( V_253 , V_2 -> V_32 -> V_285 ,
L_67 , L_40 , & V_286 ,
NULL ) ;
if ( V_194 ) {
V_2 -> V_110 = 0 ;
V_215 = V_95 ;
} else {
V_2 -> V_110 = F_164 ( V_286 ,
V_287 ) ;
V_215 = V_2 -> V_110 ;
}
V_194 = F_4 ( V_2 , ( V_215 + F_41 ( V_215 ) ) * V_4 ) ;
if ( V_194 )
goto V_20;
if ( ! V_2 -> V_21 && V_2 -> V_110 ) {
int V_12 = F_41 ( V_215 ) * V_4 ;
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
sizeof( V_2 -> V_5 [ V_18 ] . V_129 [ 0 ] ) * V_215 ,
V_19 ) ;
V_2 -> V_5 [ V_18 ] . V_89 = F_5 ( sizeof( V_2 -> V_5 [ V_18 ] . V_89 [ 0 ] ) * V_215 , V_19 ) ;
if ( V_2 -> V_110 )
V_2 -> V_5 [ V_18 ] . V_127 = F_5 (
sizeof( V_2 -> V_5 [ V_18 ] . V_127 [ 0 ] ) *
F_41 ( V_215 ) ,
V_19 ) ;
if ( ( V_2 -> V_5 [ V_18 ] . V_129 == NULL ) ||
( V_2 -> V_5 [ V_18 ] . V_89 == NULL ) ||
( V_2 -> V_110 &&
( V_2 -> V_5 [ V_18 ] . V_127 == NULL ) ) )
goto V_20;
F_179 ( V_2 -> V_5 [ V_18 ] . V_89 , V_215 ) ;
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
static void F_180 ( struct V_1 * V_2 )
{
unsigned long long V_63 ;
unsigned long V_148 ;
unsigned int V_149 ;
unsigned int V_288 ;
int V_194 ;
int V_289 , V_290 , V_103 , V_291 ;
switch ( V_2 -> V_92 ) {
case V_93 :
V_194 = F_138 ( V_253 , V_2 -> V_32 -> V_285 ,
L_68 , L_69 , & V_63 ) ;
if ( F_181 ( V_194 ) )
return;
F_80 ( V_161 L_70 ,
V_63 ) ;
F_91 ( V_2 -> V_76 , V_63 ) ;
F_182 ( V_2 -> V_76 ) ;
return;
case V_216 :
F_151 ( V_2 ) ;
return;
default:
break;
}
F_37 ( & V_2 -> V_32 -> V_69 , L_71 ,
V_292 , V_2 -> V_32 -> V_285 ) ;
V_194 = F_178 ( V_253 , V_2 -> V_32 -> V_285 ,
L_68 , L_72 , & V_63 ,
L_73 , L_40 , & V_288 ,
L_74 , L_75 , & V_148 ,
NULL ) ;
if ( V_194 ) {
F_123 ( V_2 -> V_32 , V_194 ,
L_76 ,
V_2 -> V_32 -> V_285 ) ;
return;
}
V_194 = F_138 ( V_253 , V_2 -> V_32 -> V_285 ,
L_77 , L_40 , & V_149 ) ;
if ( V_194 != 1 )
V_149 = V_148 ;
V_2 -> V_160 = 0 ;
V_2 -> V_119 = 0 ;
V_194 = F_178 ( V_253 , V_2 -> V_32 -> V_285 ,
L_78 , L_27 , & V_289 ,
NULL ) ;
if ( ! V_194 && V_289 ) {
V_2 -> V_160 = V_112 | V_113 ;
V_2 -> V_119 = V_38 ;
}
V_194 = F_178 ( V_253 , V_2 -> V_32 -> V_285 ,
L_79 , L_27 , & V_290 ,
NULL ) ;
if ( ! V_194 && V_290 ) {
V_2 -> V_160 = V_112 ;
V_2 -> V_119 = V_39 ;
}
V_194 = F_178 ( V_253 , V_2 -> V_32 -> V_285 ,
L_80 , L_27 , & V_103 ,
NULL ) ;
if ( ! V_194 && V_103 )
F_177 ( V_2 ) ;
V_194 = F_178 ( V_253 , V_2 -> V_32 -> V_285 ,
L_47 , L_40 , & V_291 ,
NULL ) ;
if ( V_194 )
V_2 -> V_21 = 0 ;
else
V_2 -> V_21 = V_291 ;
V_194 = F_153 ( V_2 ) ;
if ( V_194 ) {
F_123 ( V_2 -> V_32 , V_194 , L_81 ,
V_2 -> V_32 -> V_285 ) ;
return;
}
V_194 = F_85 ( V_63 , V_2 , V_288 , V_148 ,
V_149 ) ;
if ( V_194 ) {
F_123 ( V_2 -> V_32 , V_194 , L_82 ,
V_2 -> V_32 -> V_285 ) ;
return;
}
F_136 ( V_2 -> V_32 , V_276 ) ;
F_105 ( & V_2 -> V_150 ) ;
V_2 -> V_92 = V_93 ;
F_101 ( V_2 ) ;
F_106 ( & V_2 -> V_150 ) ;
F_183 ( V_2 -> V_76 ) ;
V_2 -> V_293 = 1 ;
}
static void F_184 ( struct V_239 * V_69 ,
enum V_294 V_295 )
{
struct V_1 * V_2 = F_169 ( & V_69 -> V_69 ) ;
F_37 ( & V_69 -> V_69 , L_83 , V_295 ) ;
switch ( V_295 ) {
case V_296 :
case V_297 :
case V_251 :
case V_298 :
case V_299 :
case V_300 :
case V_301 :
break;
case V_276 :
F_180 ( V_2 ) ;
break;
case V_281 :
F_170 ( V_2 ) ;
break;
}
}
static int F_185 ( struct V_239 * V_32 )
{
struct V_1 * V_2 = F_169 ( & V_32 -> V_69 ) ;
struct V_55 * V_64 = NULL ;
struct V_75 * V_302 ;
F_37 ( & V_32 -> V_69 , L_84 , V_32 -> V_247 ) ;
F_107 ( V_2 , 0 ) ;
F_171 ( & V_2 -> V_258 ) ;
V_302 = V_2 -> V_76 ;
if ( V_302 )
V_64 = F_173 ( V_302 , 0 ) ;
V_2 -> V_32 = NULL ;
F_172 ( & V_2 -> V_258 ) ;
if ( ! V_64 ) {
F_7 ( V_2 ) ;
return 0 ;
}
F_171 ( & V_64 -> V_282 ) ;
V_2 = V_302 -> V_68 ;
F_134 ( F_186 ( V_302 ) ,
L_85 ,
V_32 -> V_247 , V_64 -> V_283 ) ;
if ( V_2 && ! V_64 -> V_283 ) {
F_94 ( V_2 ) ;
V_302 -> V_68 = NULL ;
F_7 ( V_2 ) ;
}
F_172 ( & V_64 -> V_282 ) ;
F_176 ( V_64 ) ;
return 0 ;
}
static int F_187 ( struct V_239 * V_69 )
{
struct V_1 * V_2 = F_169 ( & V_69 -> V_69 ) ;
return V_2 -> V_293 && V_2 -> V_32 ;
}
static int F_188 ( struct V_55 * V_64 , T_3 V_65 )
{
struct V_75 * V_302 = V_64 -> V_60 ;
struct V_1 * V_2 ;
int V_194 = 0 ;
F_171 ( & V_303 ) ;
V_2 = V_302 -> V_68 ;
if ( ! V_2 ) {
V_194 = - V_304 ;
goto V_199;
}
F_171 ( & V_2 -> V_258 ) ;
if ( ! V_2 -> V_76 )
V_194 = - V_304 ;
F_172 ( & V_2 -> V_258 ) ;
V_199:
F_172 ( & V_303 ) ;
return V_194 ;
}
static void F_189 ( struct V_75 * V_302 , T_3 V_65 )
{
struct V_1 * V_2 = V_302 -> V_68 ;
struct V_55 * V_64 ;
struct V_239 * V_32 ;
F_171 ( & V_303 ) ;
V_64 = F_173 ( V_302 , 0 ) ;
if ( ! V_64 ) {
F_117 ( 1 , L_86 , V_302 -> V_162 ) ;
goto V_305;
}
if ( V_64 -> V_283 )
goto V_199;
F_171 ( & V_2 -> V_258 ) ;
V_32 = V_2 -> V_32 ;
if ( V_32 && V_32 -> V_280 == V_281 ) {
F_190 ( F_186 ( V_64 -> V_60 ) , L_87 ) ;
F_94 ( V_2 ) ;
F_174 ( V_2 -> V_32 ) ;
}
F_172 ( & V_2 -> V_258 ) ;
if ( ! V_32 ) {
F_190 ( F_186 ( V_64 -> V_60 ) , L_87 ) ;
F_94 ( V_2 ) ;
V_302 -> V_68 = NULL ;
F_7 ( V_2 ) ;
}
V_199:
F_176 ( V_64 ) ;
V_305:
F_172 ( & V_303 ) ;
}
static int T_7 F_191 ( void )
{
int V_306 ;
if ( ! F_192 () )
return - V_190 ;
if ( F_88 () && ! V_255 )
return - V_190 ;
if ( F_193 ( V_188 , V_201 ) ) {
F_80 ( V_189 L_88 ,
V_188 , V_201 ) ;
return - V_190 ;
}
V_306 = F_194 ( & V_307 ) ;
if ( V_306 ) {
F_195 ( V_188 , V_201 ) ;
return V_306 ;
}
return 0 ;
}
static void T_8 F_196 ( void )
{
F_197 ( & V_307 ) ;
F_195 ( V_188 , V_201 ) ;
F_7 ( V_50 ) ;
}
