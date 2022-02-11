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
int V_18 , V_83 , V_17 ;
struct V_84 * V_85 = NULL ;
bool V_86 ;
T_1 V_27 ;
struct V_15 * V_16 = NULL ;
struct V_87 * V_88 ;
int V_89 , V_90 ;
if ( F_40 ( V_2 -> V_91 != V_92 ) )
return 1 ;
V_90 = V_2 -> V_93 ?
V_2 -> V_93 +
F_41 ( V_2 -> V_93 ) :
V_94 ;
if ( V_2 -> V_29 < V_90 ) {
V_86 = 1 ;
if ( F_42 (
V_90 - V_2 -> V_29 ,
& V_27 ) < 0 ) {
F_43 (
& V_2 -> V_95 ,
F_31 ,
V_2 ,
V_90 ) ;
return 1 ;
}
} else
V_86 = 0 ;
V_80 = F_44 ( & V_2 -> V_96 , V_2 -> V_96 . V_97 ) ;
V_9 = F_1 ( V_2 ) ;
V_2 -> V_5 [ V_9 ] . V_11 = V_6 ;
if ( F_40 ( V_6 -> V_98 & ( V_99 | V_100 ) ) ) {
V_80 -> V_101 = V_39 ;
V_80 -> V_7 . V_102 . V_103 = F_45 ( V_6 ) ;
V_80 -> V_7 . V_102 . V_9 = V_9 ;
V_80 -> V_7 . V_102 . V_104 = ( V_105 ) F_46 ( V_6 ) ;
if ( ( V_6 -> V_98 & V_100 ) && V_2 -> V_106 )
V_80 -> V_7 . V_102 . V_107 = V_108 ;
else
V_80 -> V_7 . V_102 . V_107 = 0 ;
} else {
F_2 ( V_2 -> V_93 == 0 &&
V_6 -> V_109 > V_94 ) ;
F_2 ( V_2 -> V_93 &&
V_6 -> V_109 > V_2 -> V_93 ) ;
V_89 = F_47 ( V_6 -> V_110 , V_6 , V_2 -> V_5 [ V_9 ] . V_88 ) ;
V_80 -> V_7 . V_8 . V_9 = V_9 ;
if ( V_89 > V_94 ) {
F_2 ( V_6 -> V_98 & ( V_111 | V_112 ) ) ;
V_80 -> V_101 = V_113 ;
V_80 -> V_7 . V_114 . V_115 = F_48 ( V_6 ) ?
V_36 : V_35 ;
V_80 -> V_7 . V_114 . V_104 = ( V_105 ) F_46 ( V_6 ) ;
V_80 -> V_7 . V_114 . V_116 = V_2 -> V_116 ;
V_80 -> V_7 . V_114 . V_117 = V_89 ;
} else {
V_80 -> V_7 . V_8 . V_104 = ( V_105 ) F_46 ( V_6 ) ;
V_80 -> V_7 . V_8 . V_116 = V_2 -> V_116 ;
V_80 -> V_101 = F_48 ( V_6 ) ?
V_36 : V_35 ;
if ( V_6 -> V_98 & ( V_111 | V_112 ) ) {
V_80 -> V_101 = V_2 -> V_118 ;
}
V_80 -> V_7 . V_8 . V_117 = V_89 ;
}
F_49 (info->shadow[id].sg, sg, nseg, i) {
V_81 = V_88 -> V_119 >> 9 ;
V_82 = V_81 + ( V_88 -> V_120 >> 9 ) - 1 ;
if ( ( V_80 -> V_101 == V_113 ) &&
( V_18 % V_121 == 0 ) ) {
if ( V_85 )
F_50 ( V_85 ) ;
V_17 = V_18 / V_121 ;
V_16 = F_14 ( & V_27 , V_2 ) ;
V_2 -> V_5 [ V_9 ] . V_122 [ V_17 ] = V_16 ;
V_85 = F_51 ( F_13 ( V_16 -> V_21 ) ) ;
V_80 -> V_7 . V_114 . V_123 [ V_17 ] = V_16 -> V_22 ;
}
V_16 = F_14 ( & V_27 , V_2 ) ;
V_83 = V_16 -> V_22 ;
V_2 -> V_5 [ V_9 ] . V_124 [ V_18 ] = V_16 ;
if ( F_48 ( V_6 ) ) {
char * V_125 ;
void * V_126 ;
F_2 ( V_88 -> V_119 + V_88 -> V_120 > V_127 ) ;
V_126 = F_51 ( F_13 ( V_16 -> V_21 ) ) ;
V_125 = F_51 ( F_52 ( V_88 ) ) ;
memcpy ( V_126 + V_88 -> V_119 ,
V_125 + V_88 -> V_119 ,
V_88 -> V_120 ) ;
F_50 ( V_125 ) ;
F_50 ( V_126 ) ;
}
if ( V_80 -> V_101 != V_113 ) {
V_80 -> V_7 . V_8 . V_128 [ V_18 ] =
(struct V_129 ) {
. V_22 = V_83 ,
. V_130 = V_81 ,
. V_131 = V_82 } ;
} else {
V_17 = V_18 % V_121 ;
V_85 [ V_17 ] =
(struct V_84 ) {
. V_22 = V_83 ,
. V_130 = V_81 ,
. V_131 = V_82 } ;
}
}
if ( V_85 )
F_50 ( V_85 ) ;
}
V_2 -> V_96 . V_97 ++ ;
V_2 -> V_5 [ V_9 ] . V_6 = * V_80 ;
if ( V_86 )
F_53 ( V_27 ) ;
return 0 ;
}
static inline void F_54 ( struct V_1 * V_2 )
{
int V_132 ;
F_55 ( & V_2 -> V_96 , V_132 ) ;
if ( V_132 )
F_56 ( V_2 -> V_133 ) ;
}
static void F_57 ( struct V_134 * V_135 )
{
struct V_1 * V_2 = NULL ;
struct V_11 * V_6 ;
int V_136 ;
F_58 ( L_10 ) ;
V_136 = 0 ;
while ( ( V_6 = F_59 ( V_135 ) ) != NULL ) {
V_2 = V_6 -> V_78 -> V_67 ;
if ( F_60 ( & V_2 -> V_96 ) )
goto V_137;
F_61 ( V_6 ) ;
if ( ( V_6 -> V_138 != V_139 ) ||
( ( V_6 -> V_98 & ( V_111 | V_112 ) ) &&
! V_2 -> V_118 ) ) {
F_62 ( V_6 , - V_140 ) ;
continue;
}
F_58 ( L_11
L_12 ,
V_6 , V_6 -> V_141 , ( unsigned long ) F_46 ( V_6 ) ,
F_63 ( V_6 ) , F_45 ( V_6 ) ,
V_6 -> V_142 , F_48 ( V_6 ) ? L_2 : L_1 ) ;
if ( F_39 ( V_6 ) ) {
F_64 ( V_135 , V_6 ) ;
V_137:
F_65 ( V_135 ) ;
break;
}
V_136 ++ ;
}
if ( V_136 != 0 )
F_54 ( V_2 ) ;
}
static int F_66 ( struct V_74 * V_75 , T_4 V_143 ,
unsigned int V_144 ,
unsigned int V_85 )
{
struct V_134 * V_135 ;
struct V_1 * V_2 = V_75 -> V_67 ;
V_135 = F_67 ( F_57 , & V_2 -> V_145 ) ;
if ( V_135 == NULL )
return - 1 ;
F_68 ( V_146 , V_135 ) ;
if ( V_2 -> V_147 ) {
F_68 ( V_148 , V_135 ) ;
F_69 ( V_135 , F_34 ( V_75 ) ) ;
V_135 -> V_149 . V_150 = V_2 -> V_150 ;
V_135 -> V_149 . V_151 = V_2 -> V_151 ;
if ( V_2 -> V_106 )
F_68 ( V_152 , V_135 ) ;
}
F_70 ( V_135 , V_143 ) ;
F_71 ( V_135 , V_144 ) ;
F_72 ( V_135 , ( V_85 * V_127 ) / 512 ) ;
F_73 ( V_135 , V_127 - 1 ) ;
F_74 ( V_135 , V_127 ) ;
F_75 ( V_135 , V_85 ) ;
F_76 ( V_135 , 511 ) ;
F_77 ( V_135 , V_153 ) ;
V_75 -> V_154 = V_135 ;
return 0 ;
}
static void F_78 ( struct V_1 * V_2 )
{
F_79 ( V_2 -> V_135 , V_2 -> V_155 ) ;
F_80 ( V_156 L_13 ,
V_2 -> V_75 -> V_157 ,
V_2 -> V_118 == V_37 ?
L_3 : ( V_2 -> V_118 == V_38 ?
L_14 : L_15 ) ,
V_2 -> V_155 ? L_16 : L_17 ,
L_18 ,
V_2 -> V_158 ? L_16 : L_17 ,
L_19 ,
V_2 -> V_93 ? L_16 : L_17 ) ;
}
static int F_81 ( int V_159 , int * V_40 , unsigned int * V_119 )
{
int V_160 ;
V_160 = F_82 ( V_159 ) ;
* V_40 = F_83 ( V_159 ) ;
switch ( V_160 ) {
case V_161 :
* V_119 = ( * V_40 / 64 ) + V_162 ;
* V_40 = ( ( * V_40 / 64 ) * V_163 ) +
V_164 ;
break;
case V_165 :
* V_119 = ( * V_40 / 64 ) + 2 + V_162 ;
* V_40 = ( ( ( * V_40 / 64 ) + 2 ) * V_163 ) +
V_164 ;
break;
case V_166 :
* V_119 = ( * V_40 / V_163 ) + V_167 ;
* V_40 = * V_40 + V_168 ;
break;
case V_169 :
case V_170 :
case V_171 :
case V_172 :
case V_173 :
case V_174 :
case V_175 :
* V_119 = ( * V_40 / V_163 ) +
( ( V_160 - V_169 + 1 ) * 16 ) +
V_167 ;
* V_40 = * V_40 +
( ( V_160 - V_169 + 1 ) * 16 * V_163 ) +
V_168 ;
break;
case V_176 :
case V_177 :
case V_178 :
case V_179 :
case V_180 :
case V_181 :
case V_182 :
case V_183 :
* V_119 = ( * V_40 / V_163 ) +
( ( V_160 - V_176 + 8 ) * 16 ) +
V_167 ;
* V_40 = * V_40 +
( ( V_160 - V_176 + 8 ) * 16 * V_163 ) +
V_168 ;
break;
case V_184 :
* V_119 = * V_40 / V_163 ;
break;
default:
F_80 ( V_185 L_20
L_21 ) ;
return - V_186 ;
}
return 0 ;
}
static char * F_84 ( char * V_187 , unsigned int V_17 )
{
if ( V_17 >= 26 )
V_187 = F_84 ( V_187 , V_17 / 26 - 1 ) ;
* V_187 = 'a' + V_17 % 26 ;
return V_187 + 1 ;
}
static int F_85 ( V_105 V_188 ,
struct V_1 * V_2 ,
T_4 V_189 , T_4 V_143 ,
unsigned int V_144 )
{
struct V_74 * V_75 ;
int V_44 = 1 ;
int V_190 ;
unsigned int V_119 ;
int V_40 ;
int V_191 ;
char * V_187 ;
F_2 ( V_2 -> V_75 != NULL ) ;
F_2 ( V_2 -> V_135 != NULL ) ;
if ( ( V_2 -> V_159 >> V_192 ) > 1 ) {
F_80 ( V_185 L_22 , V_2 -> V_159 ) ;
return - V_186 ;
}
if ( ! F_86 ( V_2 -> V_159 ) ) {
V_190 = F_81 ( V_2 -> V_159 , & V_40 , & V_119 ) ;
if ( V_190 )
return V_190 ;
V_191 = V_163 ;
} else {
V_40 = F_87 ( V_2 -> V_159 ) ;
V_191 = V_193 ;
V_119 = V_40 / V_191 ;
if ( F_88 () && V_119 < V_162 + 4 )
F_80 ( V_185 L_23
L_24
L_25 , V_2 -> V_159 ) ;
}
if ( V_40 >> V_194 ) {
F_89 ( L_26 ,
V_2 -> V_159 , V_40 ) ;
return - V_186 ;
}
if ( ( V_40 % V_191 ) == 0 )
V_44 = V_191 ;
V_190 = F_22 ( V_40 , V_44 ) ;
if ( V_190 )
goto V_195;
V_190 = - V_186 ;
V_75 = F_90 ( V_44 ) ;
if ( V_75 == NULL )
goto V_196;
strcpy ( V_75 -> V_157 , V_197 ) ;
V_187 = F_84 ( V_75 -> V_157 + sizeof( V_197 ) - 1 , V_119 ) ;
F_2 ( V_187 >= V_75 -> V_157 + V_198 ) ;
if ( V_44 > 1 )
* V_187 = 0 ;
else
snprintf ( V_187 , V_75 -> V_157 + V_198 - V_187 ,
L_27 , V_40 & ( V_191 - 1 ) ) ;
V_75 -> V_160 = V_184 ;
V_75 -> V_199 = V_40 ;
V_75 -> V_200 = & V_201 ;
V_75 -> V_67 = V_2 ;
V_75 -> V_202 = & ( V_2 -> V_31 -> V_68 ) ;
F_91 ( V_75 , V_188 ) ;
if ( F_66 ( V_75 , V_143 , V_144 ,
V_2 -> V_93 ? :
V_94 ) ) {
F_92 ( V_75 ) ;
goto V_196;
}
V_2 -> V_135 = V_75 -> V_154 ;
V_2 -> V_75 = V_75 ;
F_78 ( V_2 ) ;
if ( V_189 & V_203 )
F_93 ( V_75 , 1 ) ;
if ( V_189 & V_204 )
V_75 -> V_76 |= V_205 ;
if ( V_189 & V_206 )
V_75 -> V_76 |= V_77 ;
return 0 ;
V_196:
F_29 ( V_40 , V_44 ) ;
V_195:
return V_190 ;
}
static void F_94 ( struct V_1 * V_2 )
{
unsigned int V_40 , V_44 ;
unsigned long V_76 ;
if ( V_2 -> V_135 == NULL )
return;
F_95 ( & V_2 -> V_145 , V_76 ) ;
F_65 ( V_2 -> V_135 ) ;
F_96 ( & V_2 -> V_95 ) ;
F_97 ( & V_2 -> V_145 , V_76 ) ;
F_98 ( & V_2 -> V_53 ) ;
F_92 ( V_2 -> V_75 ) ;
V_40 = V_2 -> V_75 -> V_199 ;
V_44 = V_2 -> V_75 -> V_49 ;
F_29 ( V_40 , V_44 ) ;
F_99 ( V_2 -> V_135 ) ;
V_2 -> V_135 = NULL ;
F_100 ( V_2 -> V_75 ) ;
V_2 -> V_75 = NULL ;
}
static void F_101 ( struct V_1 * V_2 )
{
if ( ! F_60 ( & V_2 -> V_96 ) ) {
F_102 ( V_2 -> V_135 ) ;
F_57 ( V_2 -> V_135 ) ;
}
}
static void F_103 ( struct V_207 * V_53 )
{
struct V_1 * V_2 = F_104 ( V_53 , struct V_1 , V_53 ) ;
F_105 ( & V_2 -> V_145 ) ;
if ( V_2 -> V_91 == V_92 )
F_101 ( V_2 ) ;
F_106 ( & V_2 -> V_145 ) ;
}
static void F_107 ( struct V_1 * V_2 , int V_208 )
{
struct V_15 * V_209 ;
struct V_15 * V_17 ;
int V_18 , V_210 , V_211 ;
F_105 ( & V_2 -> V_145 ) ;
V_2 -> V_91 = V_208 ?
V_212 : V_213 ;
if ( V_2 -> V_135 )
F_65 ( V_2 -> V_135 ) ;
if ( ! F_15 ( & V_2 -> V_25 ) ) {
F_10 (persistent_gnt, n,
&info->persistent_gnts, node) {
F_11 ( & V_209 -> V_24 ) ;
if ( V_209 -> V_22 != V_23 ) {
F_108 ( V_209 -> V_22 ,
0 , 0UL ) ;
V_2 -> V_29 -- ;
}
F_12 ( F_13 ( V_209 -> V_21 ) ) ;
F_7 ( V_209 ) ;
}
}
F_2 ( V_2 -> V_29 != 0 ) ;
for ( V_18 = 0 ; V_18 < V_4 ; V_18 ++ ) {
if ( ! V_2 -> V_5 [ V_18 ] . V_11 )
goto V_214;
V_211 = V_2 -> V_5 [ V_18 ] . V_6 . V_101 == V_113 ?
V_2 -> V_5 [ V_18 ] . V_6 . V_7 . V_114 . V_117 :
V_2 -> V_5 [ V_18 ] . V_6 . V_7 . V_8 . V_117 ;
for ( V_210 = 0 ; V_210 < V_211 ; V_210 ++ ) {
V_209 = V_2 -> V_5 [ V_18 ] . V_124 [ V_210 ] ;
F_108 ( V_209 -> V_22 , 0 , 0UL ) ;
F_12 ( F_13 ( V_209 -> V_21 ) ) ;
F_7 ( V_209 ) ;
}
if ( V_2 -> V_5 [ V_18 ] . V_6 . V_101 != V_113 )
goto V_214;
for ( V_210 = 0 ; V_210 < F_41 ( V_211 ) ; V_210 ++ ) {
V_209 = V_2 -> V_5 [ V_18 ] . V_122 [ V_210 ] ;
F_108 ( V_209 -> V_22 , 0 , 0UL ) ;
F_12 ( F_13 ( V_209 -> V_21 ) ) ;
F_7 ( V_209 ) ;
}
V_214:
F_7 ( V_2 -> V_5 [ V_18 ] . V_124 ) ;
V_2 -> V_5 [ V_18 ] . V_124 = NULL ;
F_7 ( V_2 -> V_5 [ V_18 ] . V_122 ) ;
V_2 -> V_5 [ V_18 ] . V_122 = NULL ;
F_7 ( V_2 -> V_5 [ V_18 ] . V_88 ) ;
V_2 -> V_5 [ V_18 ] . V_88 = NULL ;
}
F_96 ( & V_2 -> V_95 ) ;
F_106 ( & V_2 -> V_145 ) ;
F_98 ( & V_2 -> V_53 ) ;
if ( V_2 -> V_215 != V_23 ) {
F_108 ( V_2 -> V_215 , 0 ,
( unsigned long ) V_2 -> V_96 . V_216 ) ;
V_2 -> V_215 = V_23 ;
V_2 -> V_96 . V_216 = NULL ;
}
if ( V_2 -> V_133 )
F_109 ( V_2 -> V_133 , V_2 ) ;
V_2 -> V_217 = V_2 -> V_133 = 0 ;
}
static void F_110 ( struct V_218 * V_219 , struct V_1 * V_2 ,
struct V_220 * V_221 )
{
int V_18 = 0 ;
struct V_87 * V_88 ;
char * V_125 ;
void * V_126 ;
int V_89 ;
V_89 = V_219 -> V_6 . V_101 == V_113 ?
V_219 -> V_6 . V_7 . V_114 . V_117 : V_219 -> V_6 . V_7 . V_8 . V_117 ;
if ( V_221 -> V_101 == V_35 ) {
F_49 (s->sg, sg, nseg, i) {
F_2 ( V_88 -> V_119 + V_88 -> V_120 > V_127 ) ;
V_126 = F_51 (
F_13 ( V_219 -> V_124 [ V_18 ] -> V_21 ) ) ;
V_125 = F_51 ( F_52 ( V_88 ) ) ;
memcpy ( V_125 + V_88 -> V_119 ,
V_126 + V_88 -> V_119 ,
V_88 -> V_120 ) ;
F_50 ( V_125 ) ;
F_50 ( V_126 ) ;
}
}
for ( V_18 = 0 ; V_18 < V_89 ; V_18 ++ ) {
F_9 ( & V_219 -> V_124 [ V_18 ] -> V_24 , & V_2 -> V_25 ) ;
V_2 -> V_29 ++ ;
}
if ( V_219 -> V_6 . V_101 == V_113 ) {
for ( V_18 = 0 ; V_18 < F_41 ( V_89 ) ; V_18 ++ ) {
F_9 ( & V_219 -> V_122 [ V_18 ] -> V_24 , & V_2 -> V_25 ) ;
V_2 -> V_29 ++ ;
}
}
}
static T_5 F_111 ( int V_133 , void * V_222 )
{
struct V_11 * V_6 ;
struct V_220 * V_221 ;
T_6 V_18 , V_223 ;
unsigned long V_76 ;
struct V_1 * V_2 = (struct V_1 * ) V_222 ;
int error ;
F_95 ( & V_2 -> V_145 , V_76 ) ;
if ( F_40 ( V_2 -> V_91 != V_92 ) ) {
F_97 ( & V_2 -> V_145 , V_76 ) ;
return V_224 ;
}
V_225:
V_223 = V_2 -> V_96 . V_216 -> V_226 ;
F_112 () ;
for ( V_18 = V_2 -> V_96 . V_227 ; V_18 != V_223 ; V_18 ++ ) {
unsigned long V_9 ;
V_221 = F_113 ( & V_2 -> V_96 , V_18 ) ;
V_9 = V_221 -> V_9 ;
if ( V_9 >= V_4 ) {
F_114 ( 1 , L_28 ,
V_2 -> V_75 -> V_157 , F_20 ( V_221 -> V_101 ) , V_9 ) ;
continue;
}
V_6 = V_2 -> V_5 [ V_9 ] . V_11 ;
if ( V_221 -> V_101 != V_39 )
F_110 ( & V_2 -> V_5 [ V_9 ] , V_2 , V_221 ) ;
if ( F_3 ( V_2 , V_9 ) ) {
F_114 ( 1 , L_29 ,
V_2 -> V_75 -> V_157 , F_20 ( V_221 -> V_101 ) , V_9 ) ;
continue;
}
error = ( V_221 -> V_228 == V_229 ) ? 0 : - V_140 ;
switch ( V_221 -> V_101 ) {
case V_39 :
if ( F_40 ( V_221 -> V_228 == V_230 ) ) {
struct V_134 * V_135 = V_2 -> V_135 ;
F_80 ( V_185 L_30 ,
V_2 -> V_75 -> V_157 , F_20 ( V_221 -> V_101 ) ) ;
error = - V_231 ;
V_2 -> V_147 = 0 ;
V_2 -> V_106 = 0 ;
F_115 ( V_148 , V_135 ) ;
F_115 ( V_152 , V_135 ) ;
}
F_62 ( V_6 , error ) ;
break;
case V_38 :
case V_37 :
if ( F_40 ( V_221 -> V_228 == V_230 ) ) {
F_80 ( V_185 L_30 ,
V_2 -> V_75 -> V_157 , F_20 ( V_221 -> V_101 ) ) ;
error = - V_231 ;
}
if ( F_40 ( V_221 -> V_228 == V_232 &&
V_2 -> V_5 [ V_9 ] . V_6 . V_7 . V_8 . V_117 == 0 ) ) {
F_80 ( V_185 L_31 ,
V_2 -> V_75 -> V_157 , F_20 ( V_221 -> V_101 ) ) ;
error = - V_231 ;
}
if ( F_40 ( error ) ) {
if ( error == - V_231 )
error = 0 ;
V_2 -> V_155 = 0 ;
V_2 -> V_118 = 0 ;
F_78 ( V_2 ) ;
}
case V_35 :
case V_36 :
if ( F_40 ( V_221 -> V_228 != V_229 ) )
F_37 ( & V_2 -> V_31 -> V_68 , L_32
L_33 , V_221 -> V_228 ) ;
F_62 ( V_6 , error ) ;
break;
default:
F_116 () ;
}
}
V_2 -> V_96 . V_227 = V_18 ;
if ( V_18 != V_2 -> V_96 . V_97 ) {
int V_233 ;
F_117 ( & V_2 -> V_96 , V_233 ) ;
if ( V_233 )
goto V_225;
} else
V_2 -> V_96 . V_216 -> V_234 = V_18 + 1 ;
F_101 ( V_2 ) ;
F_97 ( & V_2 -> V_145 , V_76 ) ;
return V_224 ;
}
static int F_118 ( struct V_235 * V_68 ,
struct V_1 * V_2 )
{
struct V_236 * V_216 ;
int V_190 ;
V_2 -> V_215 = V_23 ;
V_216 = (struct V_236 * ) F_119 ( V_19 | V_237 ) ;
if ( ! V_216 ) {
F_120 ( V_68 , - V_26 , L_34 ) ;
return - V_26 ;
}
F_121 ( V_216 ) ;
F_122 ( & V_2 -> V_96 , V_216 , V_127 ) ;
V_190 = F_123 ( V_68 , F_124 ( V_2 -> V_96 . V_216 ) ) ;
if ( V_190 < 0 ) {
F_125 ( ( unsigned long ) V_216 ) ;
V_2 -> V_96 . V_216 = NULL ;
goto V_238;
}
V_2 -> V_215 = V_190 ;
V_190 = F_126 ( V_68 , & V_2 -> V_217 ) ;
if ( V_190 )
goto V_238;
V_190 = F_127 ( V_2 -> V_217 , F_111 , 0 ,
L_35 , V_2 ) ;
if ( V_190 <= 0 ) {
F_120 ( V_68 , V_190 ,
L_36 ) ;
goto V_238;
}
V_2 -> V_133 = V_190 ;
return 0 ;
V_238:
F_107 ( V_2 , 0 ) ;
return V_190 ;
}
static int F_128 ( struct V_235 * V_68 ,
struct V_1 * V_2 )
{
const char * V_239 = NULL ;
struct V_240 V_241 ;
int V_190 ;
V_190 = F_118 ( V_68 , V_2 ) ;
if ( V_190 )
goto V_195;
V_225:
V_190 = F_129 ( & V_241 ) ;
if ( V_190 ) {
F_120 ( V_68 , V_190 , L_37 ) ;
goto V_242;
}
V_190 = F_130 ( V_241 , V_68 -> V_243 ,
L_38 , L_39 , V_2 -> V_215 ) ;
if ( V_190 ) {
V_239 = L_40 ;
goto V_244;
}
V_190 = F_130 ( V_241 , V_68 -> V_243 ,
L_41 , L_39 , V_2 -> V_217 ) ;
if ( V_190 ) {
V_239 = L_42 ;
goto V_244;
}
V_190 = F_130 ( V_241 , V_68 -> V_243 , L_43 , L_44 ,
V_245 ) ;
if ( V_190 ) {
V_239 = L_45 ;
goto V_244;
}
V_190 = F_130 ( V_241 , V_68 -> V_243 ,
L_46 , L_39 , 1 ) ;
if ( V_190 )
F_131 ( & V_68 -> V_68 ,
L_47 ) ;
V_190 = F_132 ( V_241 , 0 ) ;
if ( V_190 ) {
if ( V_190 == - V_246 )
goto V_225;
F_120 ( V_68 , V_190 , L_48 ) ;
goto V_242;
}
F_133 ( V_68 , V_247 ) ;
return 0 ;
V_244:
F_132 ( V_241 , 1 ) ;
if ( V_239 )
F_120 ( V_68 , V_190 , L_44 , V_239 ) ;
V_242:
F_107 ( V_2 , 0 ) ;
V_195:
return V_190 ;
}
static int F_134 ( struct V_235 * V_68 ,
const struct V_248 * V_9 )
{
int V_190 , V_159 , V_18 ;
struct V_1 * V_2 ;
V_190 = F_135 ( V_249 , V_68 -> V_243 ,
L_49 , L_50 , & V_159 ) ;
if ( V_190 != 1 ) {
V_190 = F_135 ( V_249 , V_68 -> V_243 , L_51 ,
L_50 , & V_159 ) ;
if ( V_190 != 1 ) {
F_120 ( V_68 , V_190 , L_52 ) ;
return V_190 ;
}
}
if ( F_88 () ) {
char * type ;
int V_250 ;
if ( V_251 & V_252 ) {
int V_160 ;
if ( ! F_86 ( V_159 ) )
V_160 = F_82 ( V_159 ) ;
else
V_160 = V_184 ;
if ( V_160 != V_184 ) {
F_80 ( V_156
L_53 ,
V_253 , V_159 ) ;
return - V_186 ;
}
}
type = F_136 ( V_249 , V_68 -> V_243 , L_54 , & V_250 ) ;
if ( F_137 ( type ) )
return - V_186 ;
if ( strncmp ( type , L_55 , 5 ) == 0 ) {
F_7 ( type ) ;
return - V_186 ;
}
F_7 ( type ) ;
}
V_2 = F_5 ( sizeof( * V_2 ) , V_47 ) ;
if ( ! V_2 ) {
F_120 ( V_68 , - V_26 , L_56 ) ;
return - V_26 ;
}
F_138 ( & V_2 -> V_254 ) ;
F_139 ( & V_2 -> V_145 ) ;
V_2 -> V_31 = V_68 ;
V_2 -> V_159 = V_159 ;
F_140 ( & V_2 -> V_25 ) ;
V_2 -> V_29 = 0 ;
V_2 -> V_91 = V_213 ;
F_141 ( & V_2 -> V_53 , F_103 ) ;
for ( V_18 = 0 ; V_18 < V_4 ; V_18 ++ )
V_2 -> V_5 [ V_18 ] . V_6 . V_7 . V_8 . V_9 = V_18 + 1 ;
V_2 -> V_5 [ V_4 - 1 ] . V_6 . V_7 . V_8 . V_9 = 0x0fffffff ;
V_2 -> V_116 = F_142 ( strrchr ( V_68 -> V_243 , '/' ) + 1 , NULL , 0 ) ;
F_143 ( & V_68 -> V_68 , V_2 ) ;
V_190 = F_128 ( V_68 , V_2 ) ;
if ( V_190 ) {
F_7 ( V_2 ) ;
F_143 ( & V_68 -> V_68 , NULL ) ;
return V_190 ;
}
return 0 ;
}
static void F_144 ( struct V_255 * V_255 , int V_119 , int V_256 )
{
int V_18 ;
struct V_257 * V_258 ;
int V_259 = 0 ;
V_256 <<= 9 ;
if ( V_119 == 0 && V_256 == V_255 -> V_260 )
return;
V_255 -> V_261 += V_119 ;
V_255 -> V_260 = V_256 ;
V_119 <<= 9 ;
F_145 ( V_262 , & V_255 -> V_263 ) ;
while ( V_255 -> V_264 < V_255 -> V_265 &&
V_255 -> V_266 [ V_255 -> V_264 ] . V_267 <= V_119 ) {
V_119 -= V_255 -> V_266 [ V_255 -> V_264 ] . V_267 ;
V_255 -> V_264 ++ ;
}
if ( V_255 -> V_264 < V_255 -> V_265 ) {
V_255 -> V_266 [ V_255 -> V_264 ] . V_268 += V_119 ;
V_255 -> V_266 [ V_255 -> V_264 ] . V_267 -= V_119 ;
}
if ( V_255 -> V_264 ) {
memmove ( V_255 -> V_266 , V_255 -> V_266 + V_255 -> V_264 ,
( V_255 -> V_265 - V_255 -> V_264 ) * sizeof( struct V_257 ) ) ;
V_255 -> V_265 -= V_255 -> V_264 ;
V_255 -> V_264 = 0 ;
}
F_146 (bvec, bio, i) {
if ( V_259 + V_258 -> V_267 > V_256 )
V_258 -> V_267 = V_256 - V_259 ;
if ( V_258 -> V_267 == 0 ) {
V_255 -> V_265 = V_18 ;
break;
}
V_259 += V_258 -> V_267 ;
}
}
static void F_147 ( struct V_255 * V_255 , int error )
{
struct V_269 * V_269 = V_255 -> V_270 ;
if ( error )
V_269 -> V_190 = error ;
if ( F_148 ( & V_269 -> V_271 ) ) {
V_269 -> V_255 -> V_272 = 0 ;
F_149 ( V_269 -> V_255 , V_269 -> V_190 ) ;
F_7 ( V_269 ) ;
}
F_150 ( V_255 ) ;
}
static int F_151 ( struct V_1 * V_2 )
{
int V_18 ;
struct V_11 * V_6 , * V_17 ;
struct V_218 * V_273 ;
int V_43 ;
struct V_255 * V_255 , * V_274 ;
struct V_275 V_275 , V_276 ;
unsigned int V_211 , V_119 ;
int V_271 , V_256 ;
struct V_269 * V_269 ;
struct V_277 V_278 ;
V_273 = F_152 ( V_2 -> V_5 , sizeof( V_2 -> V_5 ) ,
V_19 | V_279 | V_237 ) ;
if ( ! V_273 )
return - V_26 ;
memset ( & V_2 -> V_5 , 0 , sizeof( V_2 -> V_5 ) ) ;
for ( V_18 = 0 ; V_18 < V_4 ; V_18 ++ )
V_2 -> V_5 [ V_18 ] . V_6 . V_7 . V_8 . V_9 = V_18 + 1 ;
V_2 -> V_3 = V_2 -> V_96 . V_97 ;
V_2 -> V_5 [ V_4 - 1 ] . V_6 . V_7 . V_8 . V_9 = 0x0fffffff ;
V_43 = F_153 ( V_2 ) ;
if ( V_43 ) {
F_7 ( V_273 ) ;
return V_43 ;
}
V_211 = V_2 -> V_93 ? : V_94 ;
F_75 ( V_2 -> V_135 , V_211 ) ;
F_154 ( & V_275 ) ;
F_140 ( & V_278 ) ;
for ( V_18 = 0 ; V_18 < V_4 ; V_18 ++ ) {
if ( ! V_273 [ V_18 ] . V_11 )
continue;
if ( V_273 [ V_18 ] . V_11 -> V_98 &
( V_111 | V_112 | V_99 | V_100 ) ) {
F_9 ( & V_273 [ V_18 ] . V_11 -> V_280 , & V_278 ) ;
continue;
}
V_276 . V_281 = V_273 [ V_18 ] . V_11 -> V_255 ;
V_276 . V_282 = V_273 [ V_18 ] . V_11 -> V_283 ;
F_155 ( & V_275 , & V_276 ) ;
V_273 [ V_18 ] . V_11 -> V_255 = NULL ;
F_156 ( V_273 [ V_18 ] . V_11 ) ;
}
F_7 ( V_273 ) ;
F_105 ( & V_2 -> V_145 ) ;
while ( ( V_6 = F_157 ( V_2 -> V_135 ) ) != NULL ) {
if ( V_6 -> V_98 &
( V_111 | V_112 | V_99 | V_100 ) ) {
F_9 ( & V_6 -> V_280 , & V_278 ) ;
continue;
}
V_276 . V_281 = V_6 -> V_255 ;
V_276 . V_282 = V_6 -> V_283 ;
F_155 ( & V_275 , & V_276 ) ;
V_6 -> V_255 = NULL ;
if ( V_6 -> V_98 & ( V_111 | V_112 ) )
F_158 ( L_57 ) ;
F_159 ( V_2 -> V_135 , V_6 ) ;
}
F_106 ( & V_2 -> V_145 ) ;
F_133 ( V_2 -> V_31 , V_284 ) ;
F_105 ( & V_2 -> V_145 ) ;
V_2 -> V_91 = V_92 ;
F_101 ( V_2 ) ;
F_10 (req, n, &requests, queuelist) {
F_160 ( & V_6 -> V_280 ) ;
F_2 ( V_6 -> V_109 > V_211 ) ;
F_64 ( V_2 -> V_135 , V_6 ) ;
}
F_106 ( & V_2 -> V_145 ) ;
while ( ( V_255 = F_161 ( & V_275 ) ) != NULL ) {
if ( F_162 ( V_255 ) > V_211 ) {
V_271 = ( F_162 ( V_255 ) + V_211 - 1 ) / V_211 ;
V_269 = F_5 ( sizeof( * V_269 ) , V_19 ) ;
F_2 ( V_269 == NULL ) ;
F_163 ( & V_269 -> V_271 , V_271 ) ;
V_269 -> V_255 = V_255 ;
for ( V_18 = 0 ; V_18 < V_271 ; V_18 ++ ) {
V_119 = ( V_18 * V_211 * V_127 ) >> 9 ;
V_256 = F_164 ( ( unsigned int ) ( V_211 * V_127 ) >> 9 ,
( unsigned int ) ( V_255 -> V_260 >> 9 ) - V_119 ) ;
V_274 = F_165 ( V_255 , V_19 ) ;
F_2 ( V_274 == NULL ) ;
F_144 ( V_274 , V_119 , V_256 ) ;
V_274 -> V_270 = V_269 ;
V_274 -> V_285 = F_147 ;
F_166 ( V_274 -> V_286 , V_274 ) ;
}
continue;
}
F_166 ( V_255 -> V_286 , V_255 ) ;
}
return 0 ;
}
static int F_167 ( struct V_235 * V_68 )
{
struct V_1 * V_2 = F_168 ( & V_68 -> V_68 ) ;
int V_190 ;
F_37 ( & V_68 -> V_68 , L_58 , V_68 -> V_243 ) ;
F_107 ( V_2 , V_2 -> V_91 == V_92 ) ;
V_190 = F_128 ( V_68 , V_2 ) ;
return V_190 ;
}
static void
F_169 ( struct V_1 * V_2 )
{
struct V_235 * V_31 = V_2 -> V_31 ;
struct V_54 * V_63 = NULL ;
F_170 ( & V_2 -> V_254 ) ;
if ( V_31 -> V_287 == V_288 ) {
F_171 ( & V_2 -> V_254 ) ;
return;
}
if ( V_2 -> V_75 )
V_63 = F_172 ( V_2 -> V_75 , 0 ) ;
F_171 ( & V_2 -> V_254 ) ;
if ( ! V_63 ) {
F_173 ( V_31 ) ;
return;
}
F_170 ( & V_63 -> V_289 ) ;
if ( V_63 -> V_290 ) {
F_174 ( V_31 , - V_51 ,
L_59 ) ;
F_133 ( V_31 , V_288 ) ;
} else {
F_94 ( V_2 ) ;
F_173 ( V_31 ) ;
}
F_171 ( & V_63 -> V_289 ) ;
F_175 ( V_63 ) ;
}
static void F_176 ( struct V_1 * V_2 )
{
int V_190 ;
char * type ;
unsigned int V_150 ;
unsigned int V_151 ;
unsigned int V_291 ;
type = F_136 ( V_249 , V_2 -> V_31 -> V_292 , L_60 , NULL ) ;
if ( F_137 ( type ) )
return;
V_2 -> V_106 = 0 ;
if ( strncmp ( type , L_61 , 3 ) == 0 ) {
V_190 = F_177 ( V_249 , V_2 -> V_31 -> V_292 ,
L_62 , L_39 , & V_150 ,
L_63 , L_39 , & V_151 ,
NULL ) ;
if ( ! V_190 ) {
V_2 -> V_147 = 1 ;
V_2 -> V_150 = V_150 ;
V_2 -> V_151 = V_151 ;
}
V_190 = F_177 ( V_249 , V_2 -> V_31 -> V_292 ,
L_64 , L_27 , & V_291 ,
NULL ) ;
if ( ! V_190 )
V_2 -> V_106 = V_291 ;
} else if ( strncmp ( type , L_65 , 4 ) == 0 )
V_2 -> V_147 = 1 ;
F_7 ( type ) ;
}
static int F_153 ( struct V_1 * V_2 )
{
unsigned int V_293 , V_211 ;
int V_190 , V_18 ;
V_190 = F_177 ( V_249 , V_2 -> V_31 -> V_292 ,
L_66 , L_39 , & V_293 ,
NULL ) ;
if ( V_190 ) {
V_2 -> V_93 = 0 ;
V_211 = V_94 ;
} else {
V_2 -> V_93 = F_164 ( V_293 ,
V_294 ) ;
V_211 = V_2 -> V_93 ;
}
V_190 = F_4 ( V_2 , ( V_211 + F_41 ( V_211 ) ) * V_4 ) ;
if ( V_190 )
goto V_20;
for ( V_18 = 0 ; V_18 < V_4 ; V_18 ++ ) {
V_2 -> V_5 [ V_18 ] . V_124 = F_5 (
sizeof( V_2 -> V_5 [ V_18 ] . V_124 [ 0 ] ) * V_211 ,
V_19 ) ;
V_2 -> V_5 [ V_18 ] . V_88 = F_5 ( sizeof( V_2 -> V_5 [ V_18 ] . V_88 [ 0 ] ) * V_211 , V_19 ) ;
if ( V_2 -> V_93 )
V_2 -> V_5 [ V_18 ] . V_122 = F_5 (
sizeof( V_2 -> V_5 [ V_18 ] . V_122 [ 0 ] ) *
F_41 ( V_211 ) ,
V_19 ) ;
if ( ( V_2 -> V_5 [ V_18 ] . V_124 == NULL ) ||
( V_2 -> V_5 [ V_18 ] . V_88 == NULL ) ||
( V_2 -> V_93 &&
( V_2 -> V_5 [ V_18 ] . V_122 == NULL ) ) )
goto V_20;
F_178 ( V_2 -> V_5 [ V_18 ] . V_88 , V_211 ) ;
}
return 0 ;
V_20:
for ( V_18 = 0 ; V_18 < V_4 ; V_18 ++ ) {
F_7 ( V_2 -> V_5 [ V_18 ] . V_124 ) ;
V_2 -> V_5 [ V_18 ] . V_124 = NULL ;
F_7 ( V_2 -> V_5 [ V_18 ] . V_88 ) ;
V_2 -> V_5 [ V_18 ] . V_88 = NULL ;
F_7 ( V_2 -> V_5 [ V_18 ] . V_122 ) ;
V_2 -> V_5 [ V_18 ] . V_122 = NULL ;
}
return - V_26 ;
}
static void F_179 ( struct V_1 * V_2 )
{
unsigned long long V_62 ;
unsigned long V_143 ;
unsigned int V_144 ;
unsigned int V_295 ;
int V_190 ;
int V_296 , V_297 , V_102 , V_298 ;
switch ( V_2 -> V_91 ) {
case V_92 :
V_190 = F_135 ( V_249 , V_2 -> V_31 -> V_292 ,
L_67 , L_68 , & V_62 ) ;
if ( F_180 ( V_190 ) )
return;
F_80 ( V_156 L_69 ,
V_62 ) ;
F_91 ( V_2 -> V_75 , V_62 ) ;
F_181 ( V_2 -> V_75 ) ;
return;
case V_212 :
F_151 ( V_2 ) ;
return;
default:
break;
}
F_37 ( & V_2 -> V_31 -> V_68 , L_70 ,
V_299 , V_2 -> V_31 -> V_292 ) ;
V_190 = F_177 ( V_249 , V_2 -> V_31 -> V_292 ,
L_67 , L_71 , & V_62 ,
L_72 , L_39 , & V_295 ,
L_73 , L_74 , & V_143 ,
NULL ) ;
if ( V_190 ) {
F_120 ( V_2 -> V_31 , V_190 ,
L_75 ,
V_2 -> V_31 -> V_292 ) ;
return;
}
V_190 = F_135 ( V_249 , V_2 -> V_31 -> V_292 ,
L_76 , L_39 , & V_144 ) ;
if ( V_190 != 1 )
V_144 = V_143 ;
V_2 -> V_155 = 0 ;
V_2 -> V_118 = 0 ;
V_190 = F_177 ( V_249 , V_2 -> V_31 -> V_292 ,
L_77 , L_27 , & V_296 ,
NULL ) ;
if ( ! V_190 && V_296 ) {
V_2 -> V_155 = V_111 | V_112 ;
V_2 -> V_118 = V_37 ;
}
V_190 = F_177 ( V_249 , V_2 -> V_31 -> V_292 ,
L_78 , L_27 , & V_297 ,
NULL ) ;
if ( ! V_190 && V_297 ) {
V_2 -> V_155 = V_111 ;
V_2 -> V_118 = V_38 ;
}
V_190 = F_177 ( V_249 , V_2 -> V_31 -> V_292 ,
L_79 , L_27 , & V_102 ,
NULL ) ;
if ( ! V_190 && V_102 )
F_176 ( V_2 ) ;
V_190 = F_177 ( V_249 , V_2 -> V_31 -> V_292 ,
L_46 , L_39 , & V_298 ,
NULL ) ;
if ( V_190 )
V_2 -> V_158 = 0 ;
else
V_2 -> V_158 = V_298 ;
V_190 = F_153 ( V_2 ) ;
if ( V_190 ) {
F_120 ( V_2 -> V_31 , V_190 , L_80 ,
V_2 -> V_31 -> V_292 ) ;
return;
}
V_190 = F_85 ( V_62 , V_2 , V_295 , V_143 ,
V_144 ) ;
if ( V_190 ) {
F_120 ( V_2 -> V_31 , V_190 , L_81 ,
V_2 -> V_31 -> V_292 ) ;
return;
}
F_133 ( V_2 -> V_31 , V_284 ) ;
F_105 ( & V_2 -> V_145 ) ;
V_2 -> V_91 = V_92 ;
F_101 ( V_2 ) ;
F_106 ( & V_2 -> V_145 ) ;
F_182 ( V_2 -> V_75 ) ;
V_2 -> V_300 = 1 ;
}
static void F_183 ( struct V_235 * V_68 ,
enum V_301 V_302 )
{
struct V_1 * V_2 = F_168 ( & V_68 -> V_68 ) ;
F_37 ( & V_68 -> V_68 , L_82 , V_302 ) ;
switch ( V_302 ) {
case V_303 :
case V_304 :
case V_247 :
case V_305 :
case V_306 :
case V_307 :
case V_308 :
break;
case V_284 :
F_179 ( V_2 ) ;
break;
case V_288 :
F_169 ( V_2 ) ;
break;
}
}
static int F_184 ( struct V_235 * V_31 )
{
struct V_1 * V_2 = F_168 ( & V_31 -> V_68 ) ;
struct V_54 * V_63 = NULL ;
struct V_74 * V_309 ;
F_37 ( & V_31 -> V_68 , L_83 , V_31 -> V_243 ) ;
F_107 ( V_2 , 0 ) ;
F_170 ( & V_2 -> V_254 ) ;
V_309 = V_2 -> V_75 ;
if ( V_309 )
V_63 = F_172 ( V_309 , 0 ) ;
V_2 -> V_31 = NULL ;
F_171 ( & V_2 -> V_254 ) ;
if ( ! V_63 ) {
F_7 ( V_2 ) ;
return 0 ;
}
F_170 ( & V_63 -> V_289 ) ;
V_2 = V_309 -> V_67 ;
F_131 ( F_185 ( V_309 ) ,
L_84 ,
V_31 -> V_243 , V_63 -> V_290 ) ;
if ( V_2 && ! V_63 -> V_290 ) {
F_94 ( V_2 ) ;
V_309 -> V_67 = NULL ;
F_7 ( V_2 ) ;
}
F_171 ( & V_63 -> V_289 ) ;
F_175 ( V_63 ) ;
return 0 ;
}
static int F_186 ( struct V_235 * V_68 )
{
struct V_1 * V_2 = F_168 ( & V_68 -> V_68 ) ;
return V_2 -> V_300 && V_2 -> V_31 ;
}
static int F_187 ( struct V_54 * V_63 , T_3 V_64 )
{
struct V_74 * V_309 = V_63 -> V_59 ;
struct V_1 * V_2 ;
int V_190 = 0 ;
F_170 ( & V_310 ) ;
V_2 = V_309 -> V_67 ;
if ( ! V_2 ) {
V_190 = - V_311 ;
goto V_195;
}
F_170 ( & V_2 -> V_254 ) ;
if ( ! V_2 -> V_75 )
V_190 = - V_311 ;
F_171 ( & V_2 -> V_254 ) ;
V_195:
F_171 ( & V_310 ) ;
return V_190 ;
}
static void F_188 ( struct V_74 * V_309 , T_3 V_64 )
{
struct V_1 * V_2 = V_309 -> V_67 ;
struct V_54 * V_63 ;
struct V_235 * V_31 ;
F_170 ( & V_310 ) ;
V_63 = F_172 ( V_309 , 0 ) ;
if ( V_63 -> V_290 )
goto V_195;
F_170 ( & V_2 -> V_254 ) ;
V_31 = V_2 -> V_31 ;
if ( V_31 && V_31 -> V_287 == V_288 ) {
F_189 ( F_185 ( V_63 -> V_59 ) , L_85 ) ;
F_94 ( V_2 ) ;
F_173 ( V_2 -> V_31 ) ;
}
F_171 ( & V_2 -> V_254 ) ;
if ( ! V_31 ) {
F_189 ( F_185 ( V_63 -> V_59 ) , L_85 ) ;
F_94 ( V_2 ) ;
V_309 -> V_67 = NULL ;
F_7 ( V_2 ) ;
}
V_195:
F_175 ( V_63 ) ;
F_171 ( & V_310 ) ;
}
static int T_7 F_190 ( void )
{
int V_312 ;
if ( ! F_191 () )
return - V_186 ;
if ( F_88 () && ! V_251 )
return - V_186 ;
if ( F_192 ( V_184 , V_197 ) ) {
F_80 ( V_185 L_86 ,
V_184 , V_197 ) ;
return - V_186 ;
}
V_312 = F_193 ( & V_313 ) ;
if ( V_312 ) {
F_194 ( V_184 , V_197 ) ;
return V_312 ;
}
return 0 ;
}
static void T_8 F_195 ( void )
{
F_196 ( & V_313 ) ;
F_194 ( V_184 , V_197 ) ;
F_7 ( V_49 ) ;
}
