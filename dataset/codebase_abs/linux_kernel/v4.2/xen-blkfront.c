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
static void F_59 ( struct V_139 * V_140 )
{
struct V_1 * V_2 = NULL ;
struct V_10 * V_5 ;
int V_141 ;
F_60 ( L_10 ) ;
V_141 = 0 ;
while ( ( V_5 = F_61 ( V_140 ) ) != NULL ) {
V_2 = V_5 -> V_78 -> V_67 ;
if ( F_62 ( & V_2 -> V_96 ) )
goto V_142;
F_63 ( V_5 ) ;
if ( F_58 ( V_5 , V_2 ) ) {
F_64 ( V_5 , - V_143 ) ;
continue;
}
F_60 ( L_11
L_12 ,
V_5 , V_5 -> V_144 , ( unsigned long ) F_47 ( V_5 ) ,
F_65 ( V_5 ) , F_46 ( V_5 ) ,
F_49 ( V_5 ) ? L_2 : L_1 ) ;
if ( F_40 ( V_5 ) ) {
F_66 ( V_140 , V_5 ) ;
V_142:
F_67 ( V_140 ) ;
break;
}
V_141 ++ ;
}
if ( V_141 != 0 )
F_55 ( V_2 ) ;
}
static int F_68 ( struct V_74 * V_75 , T_4 V_145 ,
unsigned int V_146 ,
unsigned int V_85 )
{
struct V_139 * V_140 ;
struct V_1 * V_2 = V_75 -> V_67 ;
V_140 = F_69 ( F_59 , & V_2 -> V_147 ) ;
if ( V_140 == NULL )
return - 1 ;
F_70 ( V_148 , V_140 ) ;
if ( V_2 -> V_149 ) {
F_70 ( V_150 , V_140 ) ;
F_71 ( V_140 , F_35 ( V_75 ) ) ;
V_140 -> V_151 . V_152 = V_2 -> V_152 ;
V_140 -> V_151 . V_153 = V_2 -> V_153 ;
if ( V_2 -> V_106 )
F_70 ( V_154 , V_140 ) ;
}
F_72 ( V_140 , V_145 ) ;
F_73 ( V_140 , V_146 ) ;
F_74 ( V_140 , ( V_85 * V_131 ) / 512 ) ;
F_75 ( V_140 , V_131 - 1 ) ;
F_76 ( V_140 , V_131 ) ;
F_77 ( V_140 , V_85 ) ;
F_78 ( V_140 , 511 ) ;
F_79 ( V_140 , V_155 ) ;
V_75 -> V_156 = V_140 ;
return 0 ;
}
static const char * F_80 ( unsigned int V_118 )
{
switch ( V_118 & ( ( V_111 | V_112 ) ) ) {
case V_111 | V_112 :
return L_13 ;
case V_111 :
return L_14 ;
default:
return L_15 ;
}
}
static void F_81 ( struct V_1 * V_2 )
{
F_82 ( V_2 -> V_140 , V_2 -> V_118 ) ;
F_83 ( L_16 ,
V_2 -> V_75 -> V_157 , F_80 ( V_2 -> V_118 ) ,
L_17 , V_2 -> V_20 ?
L_18 : L_19 , L_20 ,
V_2 -> V_109 ? L_18 : L_19 ) ;
}
static int F_84 ( int V_158 , int * V_40 , unsigned int * V_119 )
{
int V_159 ;
V_159 = F_85 ( V_158 ) ;
* V_40 = F_86 ( V_158 ) ;
switch ( V_159 ) {
case V_160 :
* V_119 = ( * V_40 / 64 ) + V_161 ;
* V_40 = ( ( * V_40 / 64 ) * V_162 ) +
V_163 ;
break;
case V_164 :
* V_119 = ( * V_40 / 64 ) + 2 + V_161 ;
* V_40 = ( ( ( * V_40 / 64 ) + 2 ) * V_162 ) +
V_163 ;
break;
case V_165 :
* V_119 = ( * V_40 / V_162 ) + V_166 ;
* V_40 = * V_40 + V_167 ;
break;
case V_168 :
case V_169 :
case V_170 :
case V_171 :
case V_172 :
case V_173 :
case V_174 :
* V_119 = ( * V_40 / V_162 ) +
( ( V_159 - V_168 + 1 ) * 16 ) +
V_166 ;
* V_40 = * V_40 +
( ( V_159 - V_168 + 1 ) * 16 * V_162 ) +
V_167 ;
break;
case V_175 :
case V_176 :
case V_177 :
case V_178 :
case V_179 :
case V_180 :
case V_181 :
case V_182 :
* V_119 = ( * V_40 / V_162 ) +
( ( V_159 - V_175 + 8 ) * 16 ) +
V_166 ;
* V_40 = * V_40 +
( ( V_159 - V_175 + 8 ) * 16 * V_162 ) +
V_167 ;
break;
case V_183 :
* V_119 = * V_40 / V_162 ;
break;
default:
F_87 ( V_184 L_21
L_22 ) ;
return - V_185 ;
}
return 0 ;
}
static char * F_88 ( char * V_186 , unsigned int V_16 )
{
if ( V_16 >= 26 )
V_186 = F_88 ( V_186 , V_16 / 26 - 1 ) ;
* V_186 = 'a' + V_16 % 26 ;
return V_186 + 1 ;
}
static int F_89 ( V_105 V_187 ,
struct V_1 * V_2 ,
T_4 V_188 , T_4 V_145 ,
unsigned int V_146 )
{
struct V_74 * V_75 ;
int V_44 = 1 ;
int V_189 ;
unsigned int V_119 ;
int V_40 ;
int V_190 ;
char * V_186 ;
F_2 ( V_2 -> V_75 != NULL ) ;
F_2 ( V_2 -> V_140 != NULL ) ;
if ( ( V_2 -> V_158 >> V_191 ) > 1 ) {
F_87 ( V_184 L_23 , V_2 -> V_158 ) ;
return - V_185 ;
}
if ( ! F_90 ( V_2 -> V_158 ) ) {
V_189 = F_84 ( V_2 -> V_158 , & V_40 , & V_119 ) ;
if ( V_189 )
return V_189 ;
V_190 = V_162 ;
} else {
V_40 = F_91 ( V_2 -> V_158 ) ;
V_190 = V_192 ;
V_119 = V_40 / V_190 ;
if ( F_92 () && V_119 < V_161 + 4 )
F_87 ( V_184 L_24
L_25
L_26 , V_2 -> V_158 ) ;
}
if ( V_40 >> V_193 ) {
F_93 ( L_27 ,
V_2 -> V_158 , V_40 ) ;
return - V_185 ;
}
if ( ( V_40 % V_190 ) == 0 )
V_44 = V_190 ;
V_189 = F_23 ( V_40 , V_44 ) ;
if ( V_189 )
goto V_194;
V_189 = - V_185 ;
V_75 = F_94 ( V_44 ) ;
if ( V_75 == NULL )
goto V_195;
strcpy ( V_75 -> V_157 , V_196 ) ;
V_186 = F_88 ( V_75 -> V_157 + sizeof( V_196 ) - 1 , V_119 ) ;
F_2 ( V_186 >= V_75 -> V_157 + V_197 ) ;
if ( V_44 > 1 )
* V_186 = 0 ;
else
snprintf ( V_186 , V_75 -> V_157 + V_197 - V_186 ,
L_28 , V_40 & ( V_190 - 1 ) ) ;
V_75 -> V_159 = V_183 ;
V_75 -> V_198 = V_40 ;
V_75 -> V_199 = & V_200 ;
V_75 -> V_67 = V_2 ;
V_75 -> V_201 = & ( V_2 -> V_31 -> V_68 ) ;
F_95 ( V_75 , V_187 ) ;
if ( F_68 ( V_75 , V_145 , V_146 ,
V_2 -> V_109 ? :
V_94 ) ) {
F_96 ( V_75 ) ;
goto V_195;
}
V_2 -> V_140 = V_75 -> V_156 ;
V_2 -> V_75 = V_75 ;
F_81 ( V_2 ) ;
if ( V_188 & V_202 )
F_97 ( V_75 , 1 ) ;
if ( V_188 & V_203 )
V_75 -> V_76 |= V_204 ;
if ( V_188 & V_205 )
V_75 -> V_76 |= V_77 ;
return 0 ;
V_195:
F_30 ( V_40 , V_44 ) ;
V_194:
return V_189 ;
}
static void F_98 ( struct V_1 * V_2 )
{
unsigned int V_40 , V_44 ;
unsigned long V_76 ;
if ( V_2 -> V_140 == NULL )
return;
F_99 ( & V_2 -> V_147 , V_76 ) ;
F_67 ( V_2 -> V_140 ) ;
F_100 ( & V_2 -> V_95 ) ;
F_101 ( & V_2 -> V_147 , V_76 ) ;
F_102 ( & V_2 -> V_53 ) ;
F_96 ( V_2 -> V_75 ) ;
V_40 = V_2 -> V_75 -> V_198 ;
V_44 = V_2 -> V_75 -> V_49 ;
F_30 ( V_40 , V_44 ) ;
F_103 ( V_2 -> V_140 ) ;
V_2 -> V_140 = NULL ;
F_104 ( V_2 -> V_75 ) ;
V_2 -> V_75 = NULL ;
}
static void F_105 ( struct V_1 * V_2 )
{
if ( ! F_62 ( & V_2 -> V_96 ) ) {
F_106 ( V_2 -> V_140 ) ;
F_59 ( V_2 -> V_140 ) ;
}
}
static void F_107 ( struct V_206 * V_53 )
{
struct V_1 * V_2 = F_108 ( V_53 , struct V_1 , V_53 ) ;
F_109 ( & V_2 -> V_147 ) ;
if ( V_2 -> V_91 == V_92 )
F_105 ( V_2 ) ;
F_110 ( & V_2 -> V_147 ) ;
}
static void F_111 ( struct V_1 * V_2 , int V_207 )
{
struct V_14 * V_208 ;
struct V_14 * V_16 ;
int V_17 , V_209 , V_210 ;
F_109 ( & V_2 -> V_147 ) ;
V_2 -> V_91 = V_207 ?
V_211 : V_212 ;
if ( V_2 -> V_140 )
F_67 ( V_2 -> V_140 ) ;
if ( ! F_16 ( & V_2 -> V_25 ) ) {
F_11 (persistent_gnt, n,
&info->grants, node) {
F_12 ( & V_208 -> V_24 ) ;
if ( V_208 -> V_22 != V_23 ) {
F_112 ( V_208 -> V_22 ,
0 , 0UL ) ;
V_2 -> V_29 -- ;
}
if ( V_2 -> V_20 )
F_13 ( F_14 ( V_208 -> V_21 ) ) ;
F_8 ( V_208 ) ;
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
goto V_213;
V_210 = V_2 -> V_4 [ V_17 ] . V_5 . V_101 == V_113 ?
V_2 -> V_4 [ V_17 ] . V_5 . V_6 . V_114 . V_117 :
V_2 -> V_4 [ V_17 ] . V_5 . V_6 . V_7 . V_117 ;
for ( V_209 = 0 ; V_209 < V_210 ; V_209 ++ ) {
V_208 = V_2 -> V_4 [ V_17 ] . V_128 [ V_209 ] ;
F_112 ( V_208 -> V_22 , 0 , 0UL ) ;
if ( V_2 -> V_20 )
F_13 ( F_14 ( V_208 -> V_21 ) ) ;
F_8 ( V_208 ) ;
}
if ( V_2 -> V_4 [ V_17 ] . V_5 . V_101 != V_113 )
goto V_213;
for ( V_209 = 0 ; V_209 < F_42 ( V_210 ) ; V_209 ++ ) {
V_208 = V_2 -> V_4 [ V_17 ] . V_126 [ V_209 ] ;
F_112 ( V_208 -> V_22 , 0 , 0UL ) ;
F_13 ( F_14 ( V_208 -> V_21 ) ) ;
F_8 ( V_208 ) ;
}
V_213:
F_8 ( V_2 -> V_4 [ V_17 ] . V_128 ) ;
V_2 -> V_4 [ V_17 ] . V_128 = NULL ;
F_8 ( V_2 -> V_4 [ V_17 ] . V_126 ) ;
V_2 -> V_4 [ V_17 ] . V_126 = NULL ;
F_8 ( V_2 -> V_4 [ V_17 ] . V_88 ) ;
V_2 -> V_4 [ V_17 ] . V_88 = NULL ;
}
F_100 ( & V_2 -> V_95 ) ;
F_110 ( & V_2 -> V_147 ) ;
F_102 ( & V_2 -> V_53 ) ;
for ( V_17 = 0 ; V_17 < V_2 -> V_214 ; V_17 ++ ) {
if ( V_2 -> V_215 [ V_17 ] != V_23 ) {
F_112 ( V_2 -> V_215 [ V_17 ] , 0 , 0 ) ;
V_2 -> V_215 [ V_17 ] = V_23 ;
}
}
F_113 ( ( unsigned long ) V_2 -> V_96 . V_216 , F_114 ( V_2 -> V_214 * V_131 ) ) ;
V_2 -> V_96 . V_216 = NULL ;
if ( V_2 -> V_136 )
F_115 ( V_2 -> V_136 , V_2 ) ;
V_2 -> V_217 = V_2 -> V_136 = 0 ;
}
static void F_116 ( struct V_218 * V_219 , struct V_1 * V_2 ,
struct V_220 * V_221 )
{
int V_17 = 0 ;
struct V_87 * V_88 ;
char * V_129 ;
void * V_130 ;
int V_89 ;
V_89 = V_219 -> V_5 . V_101 == V_113 ?
V_219 -> V_5 . V_6 . V_114 . V_117 : V_219 -> V_5 . V_6 . V_7 . V_117 ;
if ( V_221 -> V_101 == V_35 && V_2 -> V_20 ) {
F_50 (s->sg, sg, nseg, i) {
F_2 ( V_88 -> V_119 + V_88 -> V_120 > V_131 ) ;
V_130 = F_52 (
F_14 ( V_219 -> V_128 [ V_17 ] -> V_21 ) ) ;
V_129 = F_52 ( F_53 ( V_88 ) ) ;
memcpy ( V_129 + V_88 -> V_119 ,
V_130 + V_88 -> V_119 ,
V_88 -> V_120 ) ;
F_51 ( V_129 ) ;
F_51 ( V_130 ) ;
}
}
for ( V_17 = 0 ; V_17 < V_89 ; V_17 ++ ) {
if ( F_117 ( V_219 -> V_128 [ V_17 ] -> V_22 ) ) {
if ( ! V_2 -> V_20 )
F_118 ( L_29 ,
V_219 -> V_128 [ V_17 ] -> V_22 ) ;
F_10 ( & V_219 -> V_128 [ V_17 ] -> V_24 , & V_2 -> V_25 ) ;
V_2 -> V_29 ++ ;
} else {
F_112 ( V_219 -> V_128 [ V_17 ] -> V_22 , 0 , 0UL ) ;
V_219 -> V_128 [ V_17 ] -> V_22 = V_23 ;
F_119 ( & V_219 -> V_128 [ V_17 ] -> V_24 , & V_2 -> V_25 ) ;
}
}
if ( V_219 -> V_5 . V_101 == V_113 ) {
for ( V_17 = 0 ; V_17 < F_42 ( V_89 ) ; V_17 ++ ) {
if ( F_117 ( V_219 -> V_126 [ V_17 ] -> V_22 ) ) {
if ( ! V_2 -> V_20 )
F_118 ( L_29 ,
V_219 -> V_126 [ V_17 ] -> V_22 ) ;
F_10 ( & V_219 -> V_126 [ V_17 ] -> V_24 , & V_2 -> V_25 ) ;
V_2 -> V_29 ++ ;
} else {
struct V_12 * V_123 ;
F_112 ( V_219 -> V_126 [ V_17 ] -> V_22 , 0 , 0UL ) ;
if ( ! V_2 -> V_20 ) {
V_123 = F_14 ( V_219 -> V_126 [ V_17 ] -> V_21 ) ;
F_10 ( & V_123 -> V_125 , & V_2 -> V_124 ) ;
}
V_219 -> V_126 [ V_17 ] -> V_22 = V_23 ;
F_119 ( & V_219 -> V_126 [ V_17 ] -> V_24 , & V_2 -> V_25 ) ;
}
}
}
}
static T_5 F_120 ( int V_136 , void * V_222 )
{
struct V_10 * V_5 ;
struct V_220 * V_221 ;
T_6 V_17 , V_223 ;
unsigned long V_76 ;
struct V_1 * V_2 = (struct V_1 * ) V_222 ;
int error ;
F_99 ( & V_2 -> V_147 , V_76 ) ;
if ( F_41 ( V_2 -> V_91 != V_92 ) ) {
F_101 ( & V_2 -> V_147 , V_76 ) ;
return V_224 ;
}
V_225:
V_223 = V_2 -> V_96 . V_216 -> V_226 ;
F_121 () ;
for ( V_17 = V_2 -> V_96 . V_227 ; V_17 != V_223 ; V_17 ++ ) {
unsigned long V_8 ;
V_221 = F_122 ( & V_2 -> V_96 , V_17 ) ;
V_8 = V_221 -> V_8 ;
if ( V_8 >= F_3 ( V_2 ) ) {
F_123 ( 1 , L_30 ,
V_2 -> V_75 -> V_157 , F_21 ( V_221 -> V_101 ) , V_8 ) ;
continue;
}
V_5 = V_2 -> V_4 [ V_8 ] . V_10 ;
if ( V_221 -> V_101 != V_39 )
F_116 ( & V_2 -> V_4 [ V_8 ] , V_2 , V_221 ) ;
if ( F_4 ( V_2 , V_8 ) ) {
F_123 ( 1 , L_31 ,
V_2 -> V_75 -> V_157 , F_21 ( V_221 -> V_101 ) , V_8 ) ;
continue;
}
error = ( V_221 -> V_228 == V_229 ) ? 0 : - V_230 ;
switch ( V_221 -> V_101 ) {
case V_39 :
if ( F_41 ( V_221 -> V_228 == V_231 ) ) {
struct V_139 * V_140 = V_2 -> V_140 ;
F_87 ( V_184 L_32 ,
V_2 -> V_75 -> V_157 , F_21 ( V_221 -> V_101 ) ) ;
error = - V_143 ;
V_2 -> V_149 = 0 ;
V_2 -> V_106 = 0 ;
F_124 ( V_150 , V_140 ) ;
F_124 ( V_154 , V_140 ) ;
}
F_64 ( V_5 , error ) ;
break;
case V_38 :
case V_37 :
if ( F_41 ( V_221 -> V_228 == V_231 ) ) {
F_87 ( V_184 L_32 ,
V_2 -> V_75 -> V_157 , F_21 ( V_221 -> V_101 ) ) ;
error = - V_143 ;
}
if ( F_41 ( V_221 -> V_228 == V_232 &&
V_2 -> V_4 [ V_8 ] . V_5 . V_6 . V_7 . V_117 == 0 ) ) {
F_87 ( V_184 L_33 ,
V_2 -> V_75 -> V_157 , F_21 ( V_221 -> V_101 ) ) ;
error = - V_143 ;
}
if ( F_41 ( error ) ) {
if ( error == - V_143 )
error = 0 ;
V_2 -> V_118 = 0 ;
F_81 ( V_2 ) ;
}
case V_35 :
case V_36 :
if ( F_41 ( V_221 -> V_228 != V_229 ) )
F_38 ( & V_2 -> V_31 -> V_68 , L_34
L_35 , V_221 -> V_228 ) ;
F_64 ( V_5 , error ) ;
break;
default:
F_125 () ;
}
}
V_2 -> V_96 . V_227 = V_17 ;
if ( V_17 != V_2 -> V_96 . V_97 ) {
int V_233 ;
F_126 ( & V_2 -> V_96 , V_233 ) ;
if ( V_233 )
goto V_225;
} else
V_2 -> V_96 . V_216 -> V_234 = V_17 + 1 ;
F_105 ( V_2 ) ;
F_101 ( & V_2 -> V_147 , V_76 ) ;
return V_224 ;
}
static int F_127 ( struct V_235 * V_68 ,
struct V_1 * V_2 )
{
struct V_236 * V_216 ;
int V_189 , V_17 ;
unsigned long V_237 = V_2 -> V_214 * V_131 ;
T_1 V_22 [ V_238 ] ;
for ( V_17 = 0 ; V_17 < V_2 -> V_214 ; V_17 ++ )
V_2 -> V_215 [ V_17 ] = V_23 ;
V_216 = (struct V_236 * ) F_128 ( V_18 | V_239 ,
F_114 ( V_237 ) ) ;
if ( ! V_216 ) {
F_129 ( V_68 , - V_26 , L_36 ) ;
return - V_26 ;
}
F_130 ( V_216 ) ;
F_131 ( & V_2 -> V_96 , V_216 , V_237 ) ;
V_189 = F_132 ( V_68 , V_2 -> V_96 . V_216 , V_2 -> V_214 , V_22 ) ;
if ( V_189 < 0 ) {
F_113 ( ( unsigned long ) V_216 , F_114 ( V_237 ) ) ;
V_2 -> V_96 . V_216 = NULL ;
goto V_240;
}
for ( V_17 = 0 ; V_17 < V_2 -> V_214 ; V_17 ++ )
V_2 -> V_215 [ V_17 ] = V_22 [ V_17 ] ;
V_189 = F_133 ( V_68 , & V_2 -> V_217 ) ;
if ( V_189 )
goto V_240;
V_189 = F_134 ( V_2 -> V_217 , F_120 , 0 ,
L_37 , V_2 ) ;
if ( V_189 <= 0 ) {
F_129 ( V_68 , V_189 ,
L_38 ) ;
goto V_240;
}
V_2 -> V_136 = V_189 ;
return 0 ;
V_240:
F_111 ( V_2 , 0 ) ;
return V_189 ;
}
static int F_135 ( struct V_235 * V_68 ,
struct V_1 * V_2 )
{
const char * V_241 = NULL ;
struct V_242 V_243 ;
int V_189 , V_17 ;
unsigned int V_244 = 0 ;
unsigned int V_245 = 0 ;
V_189 = F_136 ( V_246 , V_2 -> V_31 -> V_247 ,
L_39 , L_40 , & V_244 ) ;
if ( V_189 != 1 )
V_2 -> V_214 = 1 ;
else {
V_245 = F_137 ( V_248 , V_244 ) ;
V_2 -> V_214 = 1 << V_245 ;
}
V_189 = F_127 ( V_68 , V_2 ) ;
if ( V_189 )
goto V_194;
V_225:
V_189 = F_138 ( & V_243 ) ;
if ( V_189 ) {
F_129 ( V_68 , V_189 , L_41 ) ;
goto V_249;
}
if ( V_2 -> V_214 == 1 ) {
V_189 = F_139 ( V_243 , V_68 -> V_250 ,
L_42 , L_40 , V_2 -> V_215 [ 0 ] ) ;
if ( V_189 ) {
V_241 = L_43 ;
goto V_251;
}
} else {
V_189 = F_139 ( V_243 , V_68 -> V_250 ,
L_44 , L_40 , V_245 ) ;
if ( V_189 ) {
V_241 = L_45 ;
goto V_251;
}
for ( V_17 = 0 ; V_17 < V_2 -> V_214 ; V_17 ++ ) {
char V_252 [ V_253 ] ;
snprintf ( V_252 , V_253 , L_46 , V_17 ) ;
V_189 = F_139 ( V_243 , V_68 -> V_250 , V_252 ,
L_40 , V_2 -> V_215 [ V_17 ] ) ;
if ( V_189 ) {
V_241 = L_43 ;
goto V_251;
}
}
}
V_189 = F_139 ( V_243 , V_68 -> V_250 ,
L_47 , L_40 , V_2 -> V_217 ) ;
if ( V_189 ) {
V_241 = L_48 ;
goto V_251;
}
V_189 = F_139 ( V_243 , V_68 -> V_250 , L_49 , L_50 ,
V_254 ) ;
if ( V_189 ) {
V_241 = L_51 ;
goto V_251;
}
V_189 = F_139 ( V_243 , V_68 -> V_250 ,
L_52 , L_40 , 1 ) ;
if ( V_189 )
F_140 ( & V_68 -> V_68 ,
L_53 ) ;
V_189 = F_141 ( V_243 , 0 ) ;
if ( V_189 ) {
if ( V_189 == - V_255 )
goto V_225;
F_129 ( V_68 , V_189 , L_54 ) ;
goto V_249;
}
for ( V_17 = 0 ; V_17 < F_3 ( V_2 ) ; V_17 ++ )
V_2 -> V_4 [ V_17 ] . V_5 . V_6 . V_7 . V_8 = V_17 + 1 ;
V_2 -> V_4 [ F_3 ( V_2 ) - 1 ] . V_5 . V_6 . V_7 . V_8 = 0x0fffffff ;
F_142 ( V_68 , V_256 ) ;
return 0 ;
V_251:
F_141 ( V_243 , 1 ) ;
if ( V_241 )
F_129 ( V_68 , V_189 , L_50 , V_241 ) ;
V_249:
F_111 ( V_2 , 0 ) ;
V_194:
return V_189 ;
}
static int F_143 ( struct V_235 * V_68 ,
const struct V_257 * V_8 )
{
int V_189 , V_158 ;
struct V_1 * V_2 ;
V_189 = F_136 ( V_246 , V_68 -> V_250 ,
L_55 , L_56 , & V_158 ) ;
if ( V_189 != 1 ) {
V_189 = F_136 ( V_246 , V_68 -> V_250 , L_57 ,
L_56 , & V_158 ) ;
if ( V_189 != 1 ) {
F_129 ( V_68 , V_189 , L_58 ) ;
return V_189 ;
}
}
if ( F_92 () ) {
char * type ;
int V_258 ;
if ( F_144 () ) {
int V_159 ;
if ( ! F_90 ( V_158 ) )
V_159 = F_85 ( V_158 ) ;
else
V_159 = V_183 ;
if ( V_159 != V_183 ) {
F_87 ( V_259
L_59 ,
V_260 , V_158 ) ;
return - V_185 ;
}
}
type = F_145 ( V_246 , V_68 -> V_250 , L_60 , & V_258 ) ;
if ( F_146 ( type ) )
return - V_185 ;
if ( strncmp ( type , L_61 , 5 ) == 0 ) {
F_8 ( type ) ;
return - V_185 ;
}
F_8 ( type ) ;
}
V_2 = F_6 ( sizeof( * V_2 ) , V_47 ) ;
if ( ! V_2 ) {
F_129 ( V_68 , - V_26 , L_62 ) ;
return - V_26 ;
}
F_147 ( & V_2 -> V_261 ) ;
F_148 ( & V_2 -> V_147 ) ;
V_2 -> V_31 = V_68 ;
V_2 -> V_158 = V_158 ;
F_149 ( & V_2 -> V_25 ) ;
F_149 ( & V_2 -> V_124 ) ;
V_2 -> V_29 = 0 ;
V_2 -> V_91 = V_212 ;
F_150 ( & V_2 -> V_53 , F_107 ) ;
V_2 -> V_116 = F_151 ( strrchr ( V_68 -> V_250 , '/' ) + 1 , NULL , 0 ) ;
F_152 ( & V_68 -> V_68 , V_2 ) ;
return 0 ;
}
static void F_153 ( struct V_262 * V_262 , int error )
{
struct V_263 * V_263 = V_262 -> V_264 ;
if ( error )
V_263 -> V_189 = error ;
if ( F_154 ( & V_263 -> V_265 ) ) {
V_263 -> V_262 -> V_266 = 0 ;
F_155 ( V_263 -> V_262 , V_263 -> V_189 ) ;
F_8 ( V_263 ) ;
}
F_156 ( V_262 ) ;
}
static int F_157 ( struct V_1 * V_2 )
{
int V_17 ;
struct V_10 * V_5 , * V_16 ;
struct V_218 * V_267 ;
int V_43 ;
struct V_262 * V_262 , * V_268 ;
struct V_269 V_269 , V_270 ;
unsigned int V_210 , V_119 ;
int V_265 , V_271 ;
struct V_263 * V_263 ;
struct V_272 V_273 ;
V_267 = F_158 ( V_2 -> V_4 , sizeof( V_2 -> V_4 ) ,
V_18 | V_274 | V_239 ) ;
if ( ! V_267 )
return - V_26 ;
memset ( & V_2 -> V_4 , 0 , sizeof( V_2 -> V_4 ) ) ;
for ( V_17 = 0 ; V_17 < F_3 ( V_2 ) ; V_17 ++ )
V_2 -> V_4 [ V_17 ] . V_5 . V_6 . V_7 . V_8 = V_17 + 1 ;
V_2 -> V_3 = V_2 -> V_96 . V_97 ;
V_2 -> V_4 [ F_3 ( V_2 ) - 1 ] . V_5 . V_6 . V_7 . V_8 = 0x0fffffff ;
V_43 = F_159 ( V_2 ) ;
if ( V_43 ) {
F_8 ( V_267 ) ;
return V_43 ;
}
V_210 = V_2 -> V_109 ? : V_94 ;
F_77 ( V_2 -> V_140 , V_210 ) ;
F_160 ( & V_269 ) ;
F_149 ( & V_273 ) ;
for ( V_17 = 0 ; V_17 < F_3 ( V_2 ) ; V_17 ++ ) {
if ( ! V_267 [ V_17 ] . V_10 )
continue;
if ( V_267 [ V_17 ] . V_10 -> V_98 &
( V_111 | V_112 | V_99 | V_100 ) ) {
F_10 ( & V_267 [ V_17 ] . V_10 -> V_275 , & V_273 ) ;
continue;
}
V_270 . V_276 = V_267 [ V_17 ] . V_10 -> V_262 ;
V_270 . V_277 = V_267 [ V_17 ] . V_10 -> V_278 ;
F_161 ( & V_269 , & V_270 ) ;
V_267 [ V_17 ] . V_10 -> V_262 = NULL ;
F_162 ( V_267 [ V_17 ] . V_10 , 0 ) ;
}
F_8 ( V_267 ) ;
F_109 ( & V_2 -> V_147 ) ;
while ( ( V_5 = F_163 ( V_2 -> V_140 ) ) != NULL ) {
if ( V_5 -> V_98 &
( V_111 | V_112 | V_99 | V_100 ) ) {
F_10 ( & V_5 -> V_275 , & V_273 ) ;
continue;
}
V_270 . V_276 = V_5 -> V_262 ;
V_270 . V_277 = V_5 -> V_278 ;
F_161 ( & V_269 , & V_270 ) ;
V_5 -> V_262 = NULL ;
if ( V_5 -> V_98 & ( V_111 | V_112 ) )
F_164 ( L_63 ) ;
F_64 ( V_5 , 0 ) ;
}
F_110 ( & V_2 -> V_147 ) ;
F_142 ( V_2 -> V_31 , V_279 ) ;
F_109 ( & V_2 -> V_147 ) ;
V_2 -> V_91 = V_92 ;
F_105 ( V_2 ) ;
F_11 (req, n, &requests, queuelist) {
F_165 ( & V_5 -> V_275 ) ;
F_2 ( V_5 -> V_93 > V_210 ) ;
F_66 ( V_2 -> V_140 , V_5 ) ;
}
F_110 ( & V_2 -> V_147 ) ;
while ( ( V_262 = F_166 ( & V_269 ) ) != NULL ) {
if ( F_167 ( V_262 ) > V_210 ) {
V_265 = ( F_167 ( V_262 ) + V_210 - 1 ) / V_210 ;
V_263 = F_6 ( sizeof( * V_263 ) , V_18 ) ;
F_2 ( V_263 == NULL ) ;
F_168 ( & V_263 -> V_265 , V_265 ) ;
V_263 -> V_262 = V_262 ;
for ( V_17 = 0 ; V_17 < V_265 ; V_17 ++ ) {
V_119 = ( V_17 * V_210 * V_131 ) >> 9 ;
V_271 = F_137 ( ( unsigned int ) ( V_210 * V_131 ) >> 9 ,
( unsigned int ) F_169 ( V_262 ) - V_119 ) ;
V_268 = F_170 ( V_262 , V_18 ) ;
F_2 ( V_268 == NULL ) ;
F_171 ( V_268 , V_119 , V_271 ) ;
V_268 -> V_264 = V_263 ;
V_268 -> V_280 = F_153 ;
F_172 ( V_268 -> V_281 , V_268 ) ;
}
continue;
}
F_172 ( V_262 -> V_281 , V_262 ) ;
}
return 0 ;
}
static int F_173 ( struct V_235 * V_68 )
{
struct V_1 * V_2 = F_174 ( & V_68 -> V_68 ) ;
int V_189 ;
F_38 ( & V_68 -> V_68 , L_64 , V_68 -> V_250 ) ;
F_111 ( V_2 , V_2 -> V_91 == V_92 ) ;
V_189 = F_135 ( V_68 , V_2 ) ;
return V_189 ;
}
static void
F_175 ( struct V_1 * V_2 )
{
struct V_235 * V_31 = V_2 -> V_31 ;
struct V_54 * V_63 = NULL ;
F_176 ( & V_2 -> V_261 ) ;
if ( V_31 -> V_282 == V_283 ) {
F_177 ( & V_2 -> V_261 ) ;
return;
}
if ( V_2 -> V_75 )
V_63 = F_178 ( V_2 -> V_75 , 0 ) ;
F_177 ( & V_2 -> V_261 ) ;
if ( ! V_63 ) {
F_179 ( V_31 ) ;
return;
}
F_176 ( & V_63 -> V_284 ) ;
if ( V_63 -> V_285 ) {
F_180 ( V_31 , - V_51 ,
L_65 ) ;
F_142 ( V_31 , V_283 ) ;
} else {
F_98 ( V_2 ) ;
F_179 ( V_31 ) ;
}
F_177 ( & V_63 -> V_284 ) ;
F_181 ( V_63 ) ;
}
static void F_182 ( struct V_1 * V_2 )
{
int V_189 ;
unsigned int V_152 ;
unsigned int V_153 ;
unsigned int V_286 ;
V_2 -> V_149 = 1 ;
V_189 = F_183 ( V_246 , V_2 -> V_31 -> V_247 ,
L_66 , L_40 , & V_152 ,
L_67 , L_40 , & V_153 ,
NULL ) ;
if ( ! V_189 ) {
V_2 -> V_152 = V_152 ;
V_2 -> V_153 = V_153 ;
}
V_189 = F_183 ( V_246 , V_2 -> V_31 -> V_247 ,
L_68 , L_28 , & V_286 ,
NULL ) ;
if ( ! V_189 )
V_2 -> V_106 = ! ! V_286 ;
}
static int F_184 ( struct V_1 * V_2 )
{
unsigned int V_210 ;
int V_189 , V_17 ;
if ( V_2 -> V_109 == 0 )
V_210 = V_94 ;
else
V_210 = V_2 -> V_109 ;
V_189 = F_5 ( V_2 , ( V_210 + F_42 ( V_210 ) ) * F_3 ( V_2 ) ) ;
if ( V_189 )
goto V_19;
if ( ! V_2 -> V_20 && V_2 -> V_109 ) {
int V_11 = F_42 ( V_210 ) * F_3 ( V_2 ) ;
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
sizeof( V_2 -> V_4 [ V_17 ] . V_128 [ 0 ] ) * V_210 ,
V_18 ) ;
V_2 -> V_4 [ V_17 ] . V_88 = F_6 ( sizeof( V_2 -> V_4 [ V_17 ] . V_88 [ 0 ] ) * V_210 , V_18 ) ;
if ( V_2 -> V_109 )
V_2 -> V_4 [ V_17 ] . V_126 = F_6 (
sizeof( V_2 -> V_4 [ V_17 ] . V_126 [ 0 ] ) *
F_42 ( V_210 ) ,
V_18 ) ;
if ( ( V_2 -> V_4 [ V_17 ] . V_128 == NULL ) ||
( V_2 -> V_4 [ V_17 ] . V_88 == NULL ) ||
( V_2 -> V_109 &&
( V_2 -> V_4 [ V_17 ] . V_126 == NULL ) ) )
goto V_19;
F_185 ( V_2 -> V_4 [ V_17 ] . V_88 , V_210 ) ;
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
static int F_159 ( struct V_1 * V_2 )
{
int V_189 ;
int V_287 , V_288 , V_102 , V_289 ;
unsigned int V_290 ;
V_2 -> V_118 = 0 ;
V_189 = F_183 ( V_246 , V_2 -> V_31 -> V_247 ,
L_69 , L_28 , & V_287 ,
NULL ) ;
if ( ! V_189 && V_287 )
V_2 -> V_118 = V_111 | V_112 ;
V_189 = F_183 ( V_246 , V_2 -> V_31 -> V_247 ,
L_70 , L_28 , & V_288 ,
NULL ) ;
if ( ! V_189 && V_288 )
V_2 -> V_118 = V_111 ;
V_189 = F_183 ( V_246 , V_2 -> V_31 -> V_247 ,
L_71 , L_28 , & V_102 ,
NULL ) ;
if ( ! V_189 && V_102 )
F_182 ( V_2 ) ;
V_189 = F_183 ( V_246 , V_2 -> V_31 -> V_247 ,
L_52 , L_40 , & V_289 ,
NULL ) ;
if ( V_189 )
V_2 -> V_20 = 0 ;
else
V_2 -> V_20 = V_289 ;
V_189 = F_183 ( V_246 , V_2 -> V_31 -> V_247 ,
L_72 , L_40 , & V_290 ,
NULL ) ;
if ( V_189 )
V_2 -> V_109 = 0 ;
else
V_2 -> V_109 = F_137 ( V_290 ,
V_291 ) ;
return F_184 ( V_2 ) ;
}
static void F_186 ( struct V_1 * V_2 )
{
unsigned long long V_62 ;
unsigned long V_145 ;
unsigned int V_146 ;
unsigned int V_292 ;
int V_189 ;
switch ( V_2 -> V_91 ) {
case V_92 :
V_189 = F_136 ( V_246 , V_2 -> V_31 -> V_247 ,
L_73 , L_74 , & V_62 ) ;
if ( F_187 ( V_189 ) )
return;
F_87 ( V_259 L_75 ,
V_62 ) ;
F_95 ( V_2 -> V_75 , V_62 ) ;
F_188 ( V_2 -> V_75 ) ;
return;
case V_211 :
F_157 ( V_2 ) ;
return;
default:
break;
}
F_38 ( & V_2 -> V_31 -> V_68 , L_76 ,
V_260 , V_2 -> V_31 -> V_247 ) ;
V_189 = F_183 ( V_246 , V_2 -> V_31 -> V_247 ,
L_73 , L_77 , & V_62 ,
L_78 , L_40 , & V_292 ,
L_79 , L_80 , & V_145 ,
NULL ) ;
if ( V_189 ) {
F_129 ( V_2 -> V_31 , V_189 ,
L_81 ,
V_2 -> V_31 -> V_247 ) ;
return;
}
V_189 = F_136 ( V_246 , V_2 -> V_31 -> V_247 ,
L_82 , L_40 , & V_146 ) ;
if ( V_189 != 1 )
V_146 = V_145 ;
V_189 = F_159 ( V_2 ) ;
if ( V_189 ) {
F_129 ( V_2 -> V_31 , V_189 , L_83 ,
V_2 -> V_31 -> V_247 ) ;
return;
}
V_189 = F_89 ( V_62 , V_2 , V_292 , V_145 ,
V_146 ) ;
if ( V_189 ) {
F_129 ( V_2 -> V_31 , V_189 , L_84 ,
V_2 -> V_31 -> V_247 ) ;
return;
}
F_142 ( V_2 -> V_31 , V_279 ) ;
F_109 ( & V_2 -> V_147 ) ;
V_2 -> V_91 = V_92 ;
F_105 ( V_2 ) ;
F_110 ( & V_2 -> V_147 ) ;
F_189 ( V_2 -> V_75 ) ;
V_2 -> V_293 = 1 ;
}
static void F_190 ( struct V_235 * V_68 ,
enum V_294 V_295 )
{
struct V_1 * V_2 = F_174 ( & V_68 -> V_68 ) ;
F_38 ( & V_68 -> V_68 , L_85 , V_295 ) ;
switch ( V_295 ) {
case V_296 :
if ( V_68 -> V_282 != V_297 )
break;
if ( F_135 ( V_68 , V_2 ) ) {
F_8 ( V_2 ) ;
F_152 ( & V_68 -> V_68 , NULL ) ;
break;
}
case V_297 :
case V_256 :
case V_298 :
case V_299 :
case V_300 :
break;
case V_279 :
F_186 ( V_2 ) ;
break;
case V_301 :
if ( V_68 -> V_282 == V_301 )
break;
case V_283 :
F_175 ( V_2 ) ;
break;
}
}
static int F_191 ( struct V_235 * V_31 )
{
struct V_1 * V_2 = F_174 ( & V_31 -> V_68 ) ;
struct V_54 * V_63 = NULL ;
struct V_74 * V_302 ;
F_38 ( & V_31 -> V_68 , L_86 , V_31 -> V_250 ) ;
F_111 ( V_2 , 0 ) ;
F_176 ( & V_2 -> V_261 ) ;
V_302 = V_2 -> V_75 ;
if ( V_302 )
V_63 = F_178 ( V_302 , 0 ) ;
V_2 -> V_31 = NULL ;
F_177 ( & V_2 -> V_261 ) ;
if ( ! V_63 ) {
F_8 ( V_2 ) ;
return 0 ;
}
F_176 ( & V_63 -> V_284 ) ;
V_2 = V_302 -> V_67 ;
F_140 ( F_192 ( V_302 ) ,
L_87 ,
V_31 -> V_250 , V_63 -> V_285 ) ;
if ( V_2 && ! V_63 -> V_285 ) {
F_98 ( V_2 ) ;
V_302 -> V_67 = NULL ;
F_8 ( V_2 ) ;
}
F_177 ( & V_63 -> V_284 ) ;
F_181 ( V_63 ) ;
return 0 ;
}
static int F_193 ( struct V_235 * V_68 )
{
struct V_1 * V_2 = F_174 ( & V_68 -> V_68 ) ;
return V_2 -> V_293 && V_2 -> V_31 ;
}
static int F_194 ( struct V_54 * V_63 , T_3 V_64 )
{
struct V_74 * V_302 = V_63 -> V_59 ;
struct V_1 * V_2 ;
int V_189 = 0 ;
F_176 ( & V_303 ) ;
V_2 = V_302 -> V_67 ;
if ( ! V_2 ) {
V_189 = - V_304 ;
goto V_194;
}
F_176 ( & V_2 -> V_261 ) ;
if ( ! V_2 -> V_75 )
V_189 = - V_304 ;
F_177 ( & V_2 -> V_261 ) ;
V_194:
F_177 ( & V_303 ) ;
return V_189 ;
}
static void F_195 ( struct V_74 * V_302 , T_3 V_64 )
{
struct V_1 * V_2 = V_302 -> V_67 ;
struct V_54 * V_63 ;
struct V_235 * V_31 ;
F_176 ( & V_303 ) ;
V_63 = F_178 ( V_302 , 0 ) ;
if ( ! V_63 ) {
F_123 ( 1 , L_88 , V_302 -> V_157 ) ;
goto V_305;
}
if ( V_63 -> V_285 )
goto V_194;
F_176 ( & V_2 -> V_261 ) ;
V_31 = V_2 -> V_31 ;
if ( V_31 && V_31 -> V_282 == V_283 ) {
F_196 ( F_192 ( V_63 -> V_59 ) , L_89 ) ;
F_98 ( V_2 ) ;
F_179 ( V_2 -> V_31 ) ;
}
F_177 ( & V_2 -> V_261 ) ;
if ( ! V_31 ) {
F_196 ( F_192 ( V_63 -> V_59 ) , L_89 ) ;
F_98 ( V_2 ) ;
V_302 -> V_67 = NULL ;
F_8 ( V_2 ) ;
}
V_194:
F_181 ( V_63 ) ;
V_305:
F_177 ( & V_303 ) ;
}
static int T_7 F_197 ( void )
{
int V_306 ;
if ( ! F_198 () )
return - V_185 ;
if ( V_248 > V_307 ) {
F_83 ( L_90 ,
V_248 , V_307 ) ;
V_248 = 0 ;
}
if ( ! F_199 () )
return - V_185 ;
if ( F_200 ( V_183 , V_196 ) ) {
F_87 ( V_184 L_91 ,
V_183 , V_196 ) ;
return - V_185 ;
}
V_306 = F_201 ( & V_308 ) ;
if ( V_306 ) {
F_202 ( V_183 , V_196 ) ;
return V_306 ;
}
return 0 ;
}
static void T_8 F_203 ( void )
{
F_204 ( & V_308 ) ;
F_202 ( V_183 , V_196 ) ;
F_8 ( V_49 ) ;
}
