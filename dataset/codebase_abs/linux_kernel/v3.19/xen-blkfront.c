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
switch ( V_2 -> V_119 &
( ( V_112 | V_113 ) ) ) {
case V_112 | V_113 :
V_81 -> V_102 =
V_38 ;
break;
case V_112 :
V_81 -> V_102 =
V_39 ;
break;
default:
V_81 -> V_102 = 0 ;
}
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
static inline bool F_57 ( struct V_11 * V_6 ,
struct V_1 * V_2 )
{
return ( ( V_6 -> V_138 != V_139 ) ||
( ( V_6 -> V_99 & V_112 ) &&
! ( V_2 -> V_119 & V_112 ) ) ||
( ( V_6 -> V_99 & V_113 ) &&
! ( V_2 -> V_119 & V_113 ) ) ) ;
}
static void F_58 ( struct V_140 * V_141 )
{
struct V_1 * V_2 = NULL ;
struct V_11 * V_6 ;
int V_142 ;
F_59 ( L_10 ) ;
V_142 = 0 ;
while ( ( V_6 = F_60 ( V_141 ) ) != NULL ) {
V_2 = V_6 -> V_79 -> V_68 ;
if ( F_61 ( & V_2 -> V_97 ) )
goto V_143;
F_62 ( V_6 ) ;
if ( F_57 ( V_6 , V_2 ) ) {
F_63 ( V_6 , - V_144 ) ;
continue;
}
F_59 ( L_11
L_12 ,
V_6 , V_6 -> V_145 , ( unsigned long ) F_46 ( V_6 ) ,
F_64 ( V_6 ) , F_45 ( V_6 ) ,
F_48 ( V_6 ) ? L_2 : L_1 ) ;
if ( F_39 ( V_6 ) ) {
F_65 ( V_141 , V_6 ) ;
V_143:
F_66 ( V_141 ) ;
break;
}
V_142 ++ ;
}
if ( V_142 != 0 )
F_54 ( V_2 ) ;
}
static int F_67 ( struct V_75 * V_76 , T_4 V_146 ,
unsigned int V_147 ,
unsigned int V_86 )
{
struct V_140 * V_141 ;
struct V_1 * V_2 = V_76 -> V_68 ;
V_141 = F_68 ( F_58 , & V_2 -> V_148 ) ;
if ( V_141 == NULL )
return - 1 ;
F_69 ( V_149 , V_141 ) ;
if ( V_2 -> V_150 ) {
F_69 ( V_151 , V_141 ) ;
F_70 ( V_141 , F_34 ( V_76 ) ) ;
V_141 -> V_152 . V_153 = V_2 -> V_153 ;
V_141 -> V_152 . V_154 = V_2 -> V_154 ;
if ( V_2 -> V_107 )
F_69 ( V_155 , V_141 ) ;
}
F_71 ( V_141 , V_146 ) ;
F_72 ( V_141 , V_147 ) ;
F_73 ( V_141 , ( V_86 * V_132 ) / 512 ) ;
F_74 ( V_141 , V_132 - 1 ) ;
F_75 ( V_141 , V_132 ) ;
F_76 ( V_141 , V_86 ) ;
F_77 ( V_141 , 511 ) ;
F_78 ( V_141 , V_156 ) ;
V_76 -> V_157 = V_141 ;
return 0 ;
}
static const char * F_79 ( unsigned int V_119 )
{
switch ( V_119 & ( ( V_112 | V_113 ) ) ) {
case V_112 | V_113 :
return L_13 ;
case V_112 :
return L_14 ;
default:
return L_15 ;
}
}
static void F_80 ( struct V_1 * V_2 )
{
F_81 ( V_2 -> V_141 , V_2 -> V_119 ) ;
F_82 ( L_16 ,
V_2 -> V_76 -> V_158 , F_79 ( V_2 -> V_119 ) ,
L_17 , V_2 -> V_21 ?
L_18 : L_19 , L_20 ,
V_2 -> V_110 ? L_18 : L_19 ) ;
}
static int F_83 ( int V_159 , int * V_41 , unsigned int * V_120 )
{
int V_160 ;
V_160 = F_84 ( V_159 ) ;
* V_41 = F_85 ( V_159 ) ;
switch ( V_160 ) {
case V_161 :
* V_120 = ( * V_41 / 64 ) + V_162 ;
* V_41 = ( ( * V_41 / 64 ) * V_163 ) +
V_164 ;
break;
case V_165 :
* V_120 = ( * V_41 / 64 ) + 2 + V_162 ;
* V_41 = ( ( ( * V_41 / 64 ) + 2 ) * V_163 ) +
V_164 ;
break;
case V_166 :
* V_120 = ( * V_41 / V_163 ) + V_167 ;
* V_41 = * V_41 + V_168 ;
break;
case V_169 :
case V_170 :
case V_171 :
case V_172 :
case V_173 :
case V_174 :
case V_175 :
* V_120 = ( * V_41 / V_163 ) +
( ( V_160 - V_169 + 1 ) * 16 ) +
V_167 ;
* V_41 = * V_41 +
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
* V_120 = ( * V_41 / V_163 ) +
( ( V_160 - V_176 + 8 ) * 16 ) +
V_167 ;
* V_41 = * V_41 +
( ( V_160 - V_176 + 8 ) * 16 * V_163 ) +
V_168 ;
break;
case V_184 :
* V_120 = * V_41 / V_163 ;
break;
default:
F_86 ( V_185 L_21
L_22 ) ;
return - V_186 ;
}
return 0 ;
}
static char * F_87 ( char * V_187 , unsigned int V_17 )
{
if ( V_17 >= 26 )
V_187 = F_87 ( V_187 , V_17 / 26 - 1 ) ;
* V_187 = 'a' + V_17 % 26 ;
return V_187 + 1 ;
}
static int F_88 ( V_106 V_188 ,
struct V_1 * V_2 ,
T_4 V_189 , T_4 V_146 ,
unsigned int V_147 )
{
struct V_75 * V_76 ;
int V_45 = 1 ;
int V_190 ;
unsigned int V_120 ;
int V_41 ;
int V_191 ;
char * V_187 ;
F_2 ( V_2 -> V_76 != NULL ) ;
F_2 ( V_2 -> V_141 != NULL ) ;
if ( ( V_2 -> V_159 >> V_192 ) > 1 ) {
F_86 ( V_185 L_23 , V_2 -> V_159 ) ;
return - V_186 ;
}
if ( ! F_89 ( V_2 -> V_159 ) ) {
V_190 = F_83 ( V_2 -> V_159 , & V_41 , & V_120 ) ;
if ( V_190 )
return V_190 ;
V_191 = V_163 ;
} else {
V_41 = F_90 ( V_2 -> V_159 ) ;
V_191 = V_193 ;
V_120 = V_41 / V_191 ;
if ( F_91 () && V_120 < V_162 + 4 )
F_86 ( V_185 L_24
L_25
L_26 , V_2 -> V_159 ) ;
}
if ( V_41 >> V_194 ) {
F_92 ( L_27 ,
V_2 -> V_159 , V_41 ) ;
return - V_186 ;
}
if ( ( V_41 % V_191 ) == 0 )
V_45 = V_191 ;
V_190 = F_22 ( V_41 , V_45 ) ;
if ( V_190 )
goto V_195;
V_190 = - V_186 ;
V_76 = F_93 ( V_45 ) ;
if ( V_76 == NULL )
goto V_196;
strcpy ( V_76 -> V_158 , V_197 ) ;
V_187 = F_87 ( V_76 -> V_158 + sizeof( V_197 ) - 1 , V_120 ) ;
F_2 ( V_187 >= V_76 -> V_158 + V_198 ) ;
if ( V_45 > 1 )
* V_187 = 0 ;
else
snprintf ( V_187 , V_76 -> V_158 + V_198 - V_187 ,
L_28 , V_41 & ( V_191 - 1 ) ) ;
V_76 -> V_160 = V_184 ;
V_76 -> V_199 = V_41 ;
V_76 -> V_200 = & V_201 ;
V_76 -> V_68 = V_2 ;
V_76 -> V_202 = & ( V_2 -> V_32 -> V_69 ) ;
F_94 ( V_76 , V_188 ) ;
if ( F_67 ( V_76 , V_146 , V_147 ,
V_2 -> V_110 ? :
V_95 ) ) {
F_95 ( V_76 ) ;
goto V_196;
}
V_2 -> V_141 = V_76 -> V_157 ;
V_2 -> V_76 = V_76 ;
F_80 ( V_2 ) ;
if ( V_189 & V_203 )
F_96 ( V_76 , 1 ) ;
if ( V_189 & V_204 )
V_76 -> V_77 |= V_205 ;
if ( V_189 & V_206 )
V_76 -> V_77 |= V_78 ;
return 0 ;
V_196:
F_29 ( V_41 , V_45 ) ;
V_195:
return V_190 ;
}
static void F_97 ( struct V_1 * V_2 )
{
unsigned int V_41 , V_45 ;
unsigned long V_77 ;
if ( V_2 -> V_141 == NULL )
return;
F_98 ( & V_2 -> V_148 , V_77 ) ;
F_66 ( V_2 -> V_141 ) ;
F_99 ( & V_2 -> V_96 ) ;
F_100 ( & V_2 -> V_148 , V_77 ) ;
F_101 ( & V_2 -> V_54 ) ;
F_95 ( V_2 -> V_76 ) ;
V_41 = V_2 -> V_76 -> V_199 ;
V_45 = V_2 -> V_76 -> V_50 ;
F_29 ( V_41 , V_45 ) ;
F_102 ( V_2 -> V_141 ) ;
V_2 -> V_141 = NULL ;
F_103 ( V_2 -> V_76 ) ;
V_2 -> V_76 = NULL ;
}
static void F_104 ( struct V_1 * V_2 )
{
if ( ! F_61 ( & V_2 -> V_97 ) ) {
F_105 ( V_2 -> V_141 ) ;
F_58 ( V_2 -> V_141 ) ;
}
}
static void F_106 ( struct V_207 * V_54 )
{
struct V_1 * V_2 = F_107 ( V_54 , struct V_1 , V_54 ) ;
F_108 ( & V_2 -> V_148 ) ;
if ( V_2 -> V_92 == V_93 )
F_104 ( V_2 ) ;
F_109 ( & V_2 -> V_148 ) ;
}
static void F_110 ( struct V_1 * V_2 , int V_208 )
{
struct V_15 * V_209 ;
struct V_15 * V_17 ;
int V_18 , V_210 , V_211 ;
F_108 ( & V_2 -> V_148 ) ;
V_2 -> V_92 = V_208 ?
V_212 : V_213 ;
if ( V_2 -> V_141 )
F_66 ( V_2 -> V_141 ) ;
if ( ! F_15 ( & V_2 -> V_26 ) ) {
F_10 (persistent_gnt, n,
&info->grants, node) {
F_11 ( & V_209 -> V_25 ) ;
if ( V_209 -> V_23 != V_24 ) {
F_111 ( V_209 -> V_23 ,
0 , 0UL ) ;
V_2 -> V_30 -- ;
}
if ( V_2 -> V_21 )
F_12 ( F_13 ( V_209 -> V_22 ) ) ;
F_7 ( V_209 ) ;
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
goto V_214;
V_211 = V_2 -> V_5 [ V_18 ] . V_6 . V_102 == V_114 ?
V_2 -> V_5 [ V_18 ] . V_6 . V_7 . V_115 . V_118 :
V_2 -> V_5 [ V_18 ] . V_6 . V_7 . V_8 . V_118 ;
for ( V_210 = 0 ; V_210 < V_211 ; V_210 ++ ) {
V_209 = V_2 -> V_5 [ V_18 ] . V_129 [ V_210 ] ;
F_111 ( V_209 -> V_23 , 0 , 0UL ) ;
if ( V_2 -> V_21 )
F_12 ( F_13 ( V_209 -> V_22 ) ) ;
F_7 ( V_209 ) ;
}
if ( V_2 -> V_5 [ V_18 ] . V_6 . V_102 != V_114 )
goto V_214;
for ( V_210 = 0 ; V_210 < F_41 ( V_211 ) ; V_210 ++ ) {
V_209 = V_2 -> V_5 [ V_18 ] . V_127 [ V_210 ] ;
F_111 ( V_209 -> V_23 , 0 , 0UL ) ;
F_12 ( F_13 ( V_209 -> V_22 ) ) ;
F_7 ( V_209 ) ;
}
V_214:
F_7 ( V_2 -> V_5 [ V_18 ] . V_129 ) ;
V_2 -> V_5 [ V_18 ] . V_129 = NULL ;
F_7 ( V_2 -> V_5 [ V_18 ] . V_127 ) ;
V_2 -> V_5 [ V_18 ] . V_127 = NULL ;
F_7 ( V_2 -> V_5 [ V_18 ] . V_89 ) ;
V_2 -> V_5 [ V_18 ] . V_89 = NULL ;
}
F_99 ( & V_2 -> V_96 ) ;
F_109 ( & V_2 -> V_148 ) ;
F_101 ( & V_2 -> V_54 ) ;
if ( V_2 -> V_215 != V_24 ) {
F_111 ( V_2 -> V_215 , 0 ,
( unsigned long ) V_2 -> V_97 . V_216 ) ;
V_2 -> V_215 = V_24 ;
V_2 -> V_97 . V_216 = NULL ;
}
if ( V_2 -> V_137 )
F_112 ( V_2 -> V_137 , V_2 ) ;
V_2 -> V_217 = V_2 -> V_137 = 0 ;
}
static void F_113 ( struct V_218 * V_219 , struct V_1 * V_2 ,
struct V_220 * V_221 )
{
int V_18 = 0 ;
struct V_88 * V_89 ;
char * V_130 ;
void * V_131 ;
int V_90 ;
V_90 = V_219 -> V_6 . V_102 == V_114 ?
V_219 -> V_6 . V_7 . V_115 . V_118 : V_219 -> V_6 . V_7 . V_8 . V_118 ;
if ( V_221 -> V_102 == V_36 && V_2 -> V_21 ) {
F_49 (s->sg, sg, nseg, i) {
F_2 ( V_89 -> V_120 + V_89 -> V_121 > V_132 ) ;
V_131 = F_51 (
F_13 ( V_219 -> V_129 [ V_18 ] -> V_22 ) ) ;
V_130 = F_51 ( F_52 ( V_89 ) ) ;
memcpy ( V_130 + V_89 -> V_120 ,
V_131 + V_89 -> V_120 ,
V_89 -> V_121 ) ;
F_50 ( V_130 ) ;
F_50 ( V_131 ) ;
}
}
for ( V_18 = 0 ; V_18 < V_90 ; V_18 ++ ) {
if ( F_114 ( V_219 -> V_129 [ V_18 ] -> V_23 ) ) {
if ( ! V_2 -> V_21 )
F_115 ( L_29 ,
V_219 -> V_129 [ V_18 ] -> V_23 ) ;
F_9 ( & V_219 -> V_129 [ V_18 ] -> V_25 , & V_2 -> V_26 ) ;
V_2 -> V_30 ++ ;
} else {
F_111 ( V_219 -> V_129 [ V_18 ] -> V_23 , 0 , 0UL ) ;
V_219 -> V_129 [ V_18 ] -> V_23 = V_24 ;
F_116 ( & V_219 -> V_129 [ V_18 ] -> V_25 , & V_2 -> V_26 ) ;
}
}
if ( V_219 -> V_6 . V_102 == V_114 ) {
for ( V_18 = 0 ; V_18 < F_41 ( V_90 ) ; V_18 ++ ) {
if ( F_114 ( V_219 -> V_127 [ V_18 ] -> V_23 ) ) {
if ( ! V_2 -> V_21 )
F_115 ( L_29 ,
V_219 -> V_127 [ V_18 ] -> V_23 ) ;
F_9 ( & V_219 -> V_127 [ V_18 ] -> V_25 , & V_2 -> V_26 ) ;
V_2 -> V_30 ++ ;
} else {
struct V_13 * V_124 ;
F_111 ( V_219 -> V_127 [ V_18 ] -> V_23 , 0 , 0UL ) ;
V_124 = F_13 ( V_219 -> V_127 [ V_18 ] -> V_22 ) ;
F_9 ( & V_124 -> V_126 , & V_2 -> V_125 ) ;
V_219 -> V_127 [ V_18 ] -> V_23 = V_24 ;
F_116 ( & V_219 -> V_127 [ V_18 ] -> V_25 , & V_2 -> V_26 ) ;
}
}
}
}
static T_5 F_117 ( int V_137 , void * V_222 )
{
struct V_11 * V_6 ;
struct V_220 * V_221 ;
T_6 V_18 , V_223 ;
unsigned long V_77 ;
struct V_1 * V_2 = (struct V_1 * ) V_222 ;
int error ;
F_98 ( & V_2 -> V_148 , V_77 ) ;
if ( F_40 ( V_2 -> V_92 != V_93 ) ) {
F_100 ( & V_2 -> V_148 , V_77 ) ;
return V_224 ;
}
V_225:
V_223 = V_2 -> V_97 . V_216 -> V_226 ;
F_118 () ;
for ( V_18 = V_2 -> V_97 . V_227 ; V_18 != V_223 ; V_18 ++ ) {
unsigned long V_9 ;
V_221 = F_119 ( & V_2 -> V_97 , V_18 ) ;
V_9 = V_221 -> V_9 ;
if ( V_9 >= V_4 ) {
F_120 ( 1 , L_30 ,
V_2 -> V_76 -> V_158 , F_20 ( V_221 -> V_102 ) , V_9 ) ;
continue;
}
V_6 = V_2 -> V_5 [ V_9 ] . V_11 ;
if ( V_221 -> V_102 != V_40 )
F_113 ( & V_2 -> V_5 [ V_9 ] , V_2 , V_221 ) ;
if ( F_3 ( V_2 , V_9 ) ) {
F_120 ( 1 , L_31 ,
V_2 -> V_76 -> V_158 , F_20 ( V_221 -> V_102 ) , V_9 ) ;
continue;
}
error = ( V_221 -> V_228 == V_229 ) ? 0 : - V_230 ;
switch ( V_221 -> V_102 ) {
case V_40 :
if ( F_40 ( V_221 -> V_228 == V_231 ) ) {
struct V_140 * V_141 = V_2 -> V_141 ;
F_86 ( V_185 L_32 ,
V_2 -> V_76 -> V_158 , F_20 ( V_221 -> V_102 ) ) ;
error = - V_144 ;
V_2 -> V_150 = 0 ;
V_2 -> V_107 = 0 ;
F_121 ( V_151 , V_141 ) ;
F_121 ( V_155 , V_141 ) ;
}
F_63 ( V_6 , error ) ;
break;
case V_39 :
case V_38 :
if ( F_40 ( V_221 -> V_228 == V_231 ) ) {
F_86 ( V_185 L_32 ,
V_2 -> V_76 -> V_158 , F_20 ( V_221 -> V_102 ) ) ;
error = - V_144 ;
}
if ( F_40 ( V_221 -> V_228 == V_232 &&
V_2 -> V_5 [ V_9 ] . V_6 . V_7 . V_8 . V_118 == 0 ) ) {
F_86 ( V_185 L_33 ,
V_2 -> V_76 -> V_158 , F_20 ( V_221 -> V_102 ) ) ;
error = - V_144 ;
}
if ( F_40 ( error ) ) {
if ( error == - V_144 )
error = 0 ;
V_2 -> V_119 = 0 ;
F_80 ( V_2 ) ;
}
case V_36 :
case V_37 :
if ( F_40 ( V_221 -> V_228 != V_229 ) )
F_37 ( & V_2 -> V_32 -> V_69 , L_34
L_35 , V_221 -> V_228 ) ;
F_63 ( V_6 , error ) ;
break;
default:
F_122 () ;
}
}
V_2 -> V_97 . V_227 = V_18 ;
if ( V_18 != V_2 -> V_97 . V_98 ) {
int V_233 ;
F_123 ( & V_2 -> V_97 , V_233 ) ;
if ( V_233 )
goto V_225;
} else
V_2 -> V_97 . V_216 -> V_234 = V_18 + 1 ;
F_104 ( V_2 ) ;
F_100 ( & V_2 -> V_148 , V_77 ) ;
return V_224 ;
}
static int F_124 ( struct V_235 * V_69 ,
struct V_1 * V_2 )
{
struct V_236 * V_216 ;
int V_190 ;
V_2 -> V_215 = V_24 ;
V_216 = (struct V_236 * ) F_125 ( V_19 | V_237 ) ;
if ( ! V_216 ) {
F_126 ( V_69 , - V_27 , L_36 ) ;
return - V_27 ;
}
F_127 ( V_216 ) ;
F_128 ( & V_2 -> V_97 , V_216 , V_132 ) ;
V_190 = F_129 ( V_69 , F_130 ( V_2 -> V_97 . V_216 ) ) ;
if ( V_190 < 0 ) {
F_131 ( ( unsigned long ) V_216 ) ;
V_2 -> V_97 . V_216 = NULL ;
goto V_238;
}
V_2 -> V_215 = V_190 ;
V_190 = F_132 ( V_69 , & V_2 -> V_217 ) ;
if ( V_190 )
goto V_238;
V_190 = F_133 ( V_2 -> V_217 , F_117 , 0 ,
L_37 , V_2 ) ;
if ( V_190 <= 0 ) {
F_126 ( V_69 , V_190 ,
L_38 ) ;
goto V_238;
}
V_2 -> V_137 = V_190 ;
return 0 ;
V_238:
F_110 ( V_2 , 0 ) ;
return V_190 ;
}
static int F_134 ( struct V_235 * V_69 ,
struct V_1 * V_2 )
{
const char * V_239 = NULL ;
struct V_240 V_241 ;
int V_190 ;
V_190 = F_124 ( V_69 , V_2 ) ;
if ( V_190 )
goto V_195;
V_225:
V_190 = F_135 ( & V_241 ) ;
if ( V_190 ) {
F_126 ( V_69 , V_190 , L_39 ) ;
goto V_242;
}
V_190 = F_136 ( V_241 , V_69 -> V_243 ,
L_40 , L_41 , V_2 -> V_215 ) ;
if ( V_190 ) {
V_239 = L_42 ;
goto V_244;
}
V_190 = F_136 ( V_241 , V_69 -> V_243 ,
L_43 , L_41 , V_2 -> V_217 ) ;
if ( V_190 ) {
V_239 = L_44 ;
goto V_244;
}
V_190 = F_136 ( V_241 , V_69 -> V_243 , L_45 , L_46 ,
V_245 ) ;
if ( V_190 ) {
V_239 = L_47 ;
goto V_244;
}
V_190 = F_136 ( V_241 , V_69 -> V_243 ,
L_48 , L_41 , 1 ) ;
if ( V_190 )
F_137 ( & V_69 -> V_69 ,
L_49 ) ;
V_190 = F_138 ( V_241 , 0 ) ;
if ( V_190 ) {
if ( V_190 == - V_246 )
goto V_225;
F_126 ( V_69 , V_190 , L_50 ) ;
goto V_242;
}
F_139 ( V_69 , V_247 ) ;
return 0 ;
V_244:
F_138 ( V_241 , 1 ) ;
if ( V_239 )
F_126 ( V_69 , V_190 , L_46 , V_239 ) ;
V_242:
F_110 ( V_2 , 0 ) ;
V_195:
return V_190 ;
}
static int F_140 ( struct V_235 * V_69 ,
const struct V_248 * V_9 )
{
int V_190 , V_159 , V_18 ;
struct V_1 * V_2 ;
V_190 = F_141 ( V_249 , V_69 -> V_243 ,
L_51 , L_52 , & V_159 ) ;
if ( V_190 != 1 ) {
V_190 = F_141 ( V_249 , V_69 -> V_243 , L_53 ,
L_52 , & V_159 ) ;
if ( V_190 != 1 ) {
F_126 ( V_69 , V_190 , L_54 ) ;
return V_190 ;
}
}
if ( F_91 () ) {
char * type ;
int V_250 ;
if ( F_142 () ) {
int V_160 ;
if ( ! F_89 ( V_159 ) )
V_160 = F_84 ( V_159 ) ;
else
V_160 = V_184 ;
if ( V_160 != V_184 ) {
F_86 ( V_251
L_55 ,
V_252 , V_159 ) ;
return - V_186 ;
}
}
type = F_143 ( V_249 , V_69 -> V_243 , L_56 , & V_250 ) ;
if ( F_144 ( type ) )
return - V_186 ;
if ( strncmp ( type , L_57 , 5 ) == 0 ) {
F_7 ( type ) ;
return - V_186 ;
}
F_7 ( type ) ;
}
V_2 = F_5 ( sizeof( * V_2 ) , V_48 ) ;
if ( ! V_2 ) {
F_126 ( V_69 , - V_27 , L_58 ) ;
return - V_27 ;
}
F_145 ( & V_2 -> V_253 ) ;
F_146 ( & V_2 -> V_148 ) ;
V_2 -> V_32 = V_69 ;
V_2 -> V_159 = V_159 ;
F_147 ( & V_2 -> V_26 ) ;
F_147 ( & V_2 -> V_125 ) ;
V_2 -> V_30 = 0 ;
V_2 -> V_92 = V_213 ;
F_148 ( & V_2 -> V_54 , F_106 ) ;
for ( V_18 = 0 ; V_18 < V_4 ; V_18 ++ )
V_2 -> V_5 [ V_18 ] . V_6 . V_7 . V_8 . V_9 = V_18 + 1 ;
V_2 -> V_5 [ V_4 - 1 ] . V_6 . V_7 . V_8 . V_9 = 0x0fffffff ;
V_2 -> V_117 = F_149 ( strrchr ( V_69 -> V_243 , '/' ) + 1 , NULL , 0 ) ;
F_150 ( & V_69 -> V_69 , V_2 ) ;
V_190 = F_134 ( V_69 , V_2 ) ;
if ( V_190 ) {
F_7 ( V_2 ) ;
F_150 ( & V_69 -> V_69 , NULL ) ;
return V_190 ;
}
return 0 ;
}
static void F_151 ( struct V_254 * V_254 , int error )
{
struct V_255 * V_255 = V_254 -> V_256 ;
if ( error )
V_255 -> V_190 = error ;
if ( F_152 ( & V_255 -> V_257 ) ) {
V_255 -> V_254 -> V_258 = 0 ;
F_153 ( V_255 -> V_254 , V_255 -> V_190 ) ;
F_7 ( V_255 ) ;
}
F_154 ( V_254 ) ;
}
static int F_155 ( struct V_1 * V_2 )
{
int V_18 ;
struct V_11 * V_6 , * V_17 ;
struct V_218 * V_259 ;
int V_44 ;
struct V_254 * V_254 , * V_260 ;
struct V_261 V_261 , V_262 ;
unsigned int V_211 , V_120 ;
int V_257 , V_263 ;
struct V_255 * V_255 ;
struct V_264 V_265 ;
V_259 = F_156 ( V_2 -> V_5 , sizeof( V_2 -> V_5 ) ,
V_19 | V_266 | V_237 ) ;
if ( ! V_259 )
return - V_27 ;
memset ( & V_2 -> V_5 , 0 , sizeof( V_2 -> V_5 ) ) ;
for ( V_18 = 0 ; V_18 < V_4 ; V_18 ++ )
V_2 -> V_5 [ V_18 ] . V_6 . V_7 . V_8 . V_9 = V_18 + 1 ;
V_2 -> V_3 = V_2 -> V_97 . V_98 ;
V_2 -> V_5 [ V_4 - 1 ] . V_6 . V_7 . V_8 . V_9 = 0x0fffffff ;
V_44 = F_157 ( V_2 ) ;
if ( V_44 ) {
F_7 ( V_259 ) ;
return V_44 ;
}
V_211 = V_2 -> V_110 ? : V_95 ;
F_76 ( V_2 -> V_141 , V_211 ) ;
F_158 ( & V_261 ) ;
F_147 ( & V_265 ) ;
for ( V_18 = 0 ; V_18 < V_4 ; V_18 ++ ) {
if ( ! V_259 [ V_18 ] . V_11 )
continue;
if ( V_259 [ V_18 ] . V_11 -> V_99 &
( V_112 | V_113 | V_100 | V_101 ) ) {
F_9 ( & V_259 [ V_18 ] . V_11 -> V_267 , & V_265 ) ;
continue;
}
V_262 . V_268 = V_259 [ V_18 ] . V_11 -> V_254 ;
V_262 . V_269 = V_259 [ V_18 ] . V_11 -> V_270 ;
F_159 ( & V_261 , & V_262 ) ;
V_259 [ V_18 ] . V_11 -> V_254 = NULL ;
F_160 ( V_259 [ V_18 ] . V_11 ) ;
}
F_7 ( V_259 ) ;
F_108 ( & V_2 -> V_148 ) ;
while ( ( V_6 = F_161 ( V_2 -> V_141 ) ) != NULL ) {
if ( V_6 -> V_99 &
( V_112 | V_113 | V_100 | V_101 ) ) {
F_9 ( & V_6 -> V_267 , & V_265 ) ;
continue;
}
V_262 . V_268 = V_6 -> V_254 ;
V_262 . V_269 = V_6 -> V_270 ;
F_159 ( & V_261 , & V_262 ) ;
V_6 -> V_254 = NULL ;
if ( V_6 -> V_99 & ( V_112 | V_113 ) )
F_162 ( L_59 ) ;
F_163 ( V_2 -> V_141 , V_6 ) ;
}
F_109 ( & V_2 -> V_148 ) ;
F_139 ( V_2 -> V_32 , V_271 ) ;
F_108 ( & V_2 -> V_148 ) ;
V_2 -> V_92 = V_93 ;
F_104 ( V_2 ) ;
F_10 (req, n, &requests, queuelist) {
F_164 ( & V_6 -> V_267 ) ;
F_2 ( V_6 -> V_94 > V_211 ) ;
F_65 ( V_2 -> V_141 , V_6 ) ;
}
F_109 ( & V_2 -> V_148 ) ;
while ( ( V_254 = F_165 ( & V_261 ) ) != NULL ) {
if ( F_166 ( V_254 ) > V_211 ) {
V_257 = ( F_166 ( V_254 ) + V_211 - 1 ) / V_211 ;
V_255 = F_5 ( sizeof( * V_255 ) , V_19 ) ;
F_2 ( V_255 == NULL ) ;
F_167 ( & V_255 -> V_257 , V_257 ) ;
V_255 -> V_254 = V_254 ;
for ( V_18 = 0 ; V_18 < V_257 ; V_18 ++ ) {
V_120 = ( V_18 * V_211 * V_132 ) >> 9 ;
V_263 = F_168 ( ( unsigned int ) ( V_211 * V_132 ) >> 9 ,
( unsigned int ) F_169 ( V_254 ) - V_120 ) ;
V_260 = F_170 ( V_254 , V_19 ) ;
F_2 ( V_260 == NULL ) ;
F_171 ( V_260 , V_120 , V_263 ) ;
V_260 -> V_256 = V_255 ;
V_260 -> V_272 = F_151 ;
F_172 ( V_260 -> V_273 , V_260 ) ;
}
continue;
}
F_172 ( V_254 -> V_273 , V_254 ) ;
}
return 0 ;
}
static int F_173 ( struct V_235 * V_69 )
{
struct V_1 * V_2 = F_174 ( & V_69 -> V_69 ) ;
int V_190 ;
F_37 ( & V_69 -> V_69 , L_60 , V_69 -> V_243 ) ;
F_110 ( V_2 , V_2 -> V_92 == V_93 ) ;
V_190 = F_134 ( V_69 , V_2 ) ;
return V_190 ;
}
static void
F_175 ( struct V_1 * V_2 )
{
struct V_235 * V_32 = V_2 -> V_32 ;
struct V_55 * V_64 = NULL ;
F_176 ( & V_2 -> V_253 ) ;
if ( V_32 -> V_274 == V_275 ) {
F_177 ( & V_2 -> V_253 ) ;
return;
}
if ( V_2 -> V_76 )
V_64 = F_178 ( V_2 -> V_76 , 0 ) ;
F_177 ( & V_2 -> V_253 ) ;
if ( ! V_64 ) {
F_179 ( V_32 ) ;
return;
}
F_176 ( & V_64 -> V_276 ) ;
if ( V_64 -> V_277 ) {
F_180 ( V_32 , - V_52 ,
L_61 ) ;
F_139 ( V_32 , V_275 ) ;
} else {
F_97 ( V_2 ) ;
F_179 ( V_32 ) ;
}
F_177 ( & V_64 -> V_276 ) ;
F_181 ( V_64 ) ;
}
static void F_182 ( struct V_1 * V_2 )
{
int V_190 ;
unsigned int V_153 ;
unsigned int V_154 ;
unsigned int V_278 ;
V_2 -> V_150 = 1 ;
V_190 = F_183 ( V_249 , V_2 -> V_32 -> V_279 ,
L_62 , L_41 , & V_153 ,
L_63 , L_41 , & V_154 ,
NULL ) ;
if ( ! V_190 ) {
V_2 -> V_153 = V_153 ;
V_2 -> V_154 = V_154 ;
}
V_190 = F_183 ( V_249 , V_2 -> V_32 -> V_279 ,
L_64 , L_28 , & V_278 ,
NULL ) ;
if ( ! V_190 )
V_2 -> V_107 = ! ! V_278 ;
}
static int F_157 ( struct V_1 * V_2 )
{
unsigned int V_280 , V_211 ;
int V_190 , V_18 ;
V_190 = F_183 ( V_249 , V_2 -> V_32 -> V_279 ,
L_65 , L_41 , & V_280 ,
NULL ) ;
if ( V_190 ) {
V_2 -> V_110 = 0 ;
V_211 = V_95 ;
} else {
V_2 -> V_110 = F_168 ( V_280 ,
V_281 ) ;
V_211 = V_2 -> V_110 ;
}
V_190 = F_4 ( V_2 , ( V_211 + F_41 ( V_211 ) ) * V_4 ) ;
if ( V_190 )
goto V_20;
if ( ! V_2 -> V_21 && V_2 -> V_110 ) {
int V_12 = F_41 ( V_211 ) * V_4 ;
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
sizeof( V_2 -> V_5 [ V_18 ] . V_129 [ 0 ] ) * V_211 ,
V_19 ) ;
V_2 -> V_5 [ V_18 ] . V_89 = F_5 ( sizeof( V_2 -> V_5 [ V_18 ] . V_89 [ 0 ] ) * V_211 , V_19 ) ;
if ( V_2 -> V_110 )
V_2 -> V_5 [ V_18 ] . V_127 = F_5 (
sizeof( V_2 -> V_5 [ V_18 ] . V_127 [ 0 ] ) *
F_41 ( V_211 ) ,
V_19 ) ;
if ( ( V_2 -> V_5 [ V_18 ] . V_129 == NULL ) ||
( V_2 -> V_5 [ V_18 ] . V_89 == NULL ) ||
( V_2 -> V_110 &&
( V_2 -> V_5 [ V_18 ] . V_127 == NULL ) ) )
goto V_20;
F_184 ( V_2 -> V_5 [ V_18 ] . V_89 , V_211 ) ;
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
static void F_185 ( struct V_1 * V_2 )
{
unsigned long long V_63 ;
unsigned long V_146 ;
unsigned int V_147 ;
unsigned int V_282 ;
int V_190 ;
int V_283 , V_284 , V_103 , V_285 ;
switch ( V_2 -> V_92 ) {
case V_93 :
V_190 = F_141 ( V_249 , V_2 -> V_32 -> V_279 ,
L_66 , L_67 , & V_63 ) ;
if ( F_186 ( V_190 ) )
return;
F_86 ( V_251 L_68 ,
V_63 ) ;
F_94 ( V_2 -> V_76 , V_63 ) ;
F_187 ( V_2 -> V_76 ) ;
return;
case V_212 :
F_155 ( V_2 ) ;
return;
default:
break;
}
F_37 ( & V_2 -> V_32 -> V_69 , L_69 ,
V_286 , V_2 -> V_32 -> V_279 ) ;
V_190 = F_183 ( V_249 , V_2 -> V_32 -> V_279 ,
L_66 , L_70 , & V_63 ,
L_71 , L_41 , & V_282 ,
L_72 , L_73 , & V_146 ,
NULL ) ;
if ( V_190 ) {
F_126 ( V_2 -> V_32 , V_190 ,
L_74 ,
V_2 -> V_32 -> V_279 ) ;
return;
}
V_190 = F_141 ( V_249 , V_2 -> V_32 -> V_279 ,
L_75 , L_41 , & V_147 ) ;
if ( V_190 != 1 )
V_147 = V_146 ;
V_2 -> V_119 = 0 ;
V_190 = F_183 ( V_249 , V_2 -> V_32 -> V_279 ,
L_76 , L_28 , & V_283 ,
NULL ) ;
if ( ! V_190 && V_283 )
V_2 -> V_119 = V_112 | V_113 ;
V_190 = F_183 ( V_249 , V_2 -> V_32 -> V_279 ,
L_77 , L_28 , & V_284 ,
NULL ) ;
if ( ! V_190 && V_284 )
V_2 -> V_119 = V_112 ;
V_190 = F_183 ( V_249 , V_2 -> V_32 -> V_279 ,
L_78 , L_28 , & V_103 ,
NULL ) ;
if ( ! V_190 && V_103 )
F_182 ( V_2 ) ;
V_190 = F_183 ( V_249 , V_2 -> V_32 -> V_279 ,
L_48 , L_41 , & V_285 ,
NULL ) ;
if ( V_190 )
V_2 -> V_21 = 0 ;
else
V_2 -> V_21 = V_285 ;
V_190 = F_157 ( V_2 ) ;
if ( V_190 ) {
F_126 ( V_2 -> V_32 , V_190 , L_79 ,
V_2 -> V_32 -> V_279 ) ;
return;
}
V_190 = F_88 ( V_63 , V_2 , V_282 , V_146 ,
V_147 ) ;
if ( V_190 ) {
F_126 ( V_2 -> V_32 , V_190 , L_80 ,
V_2 -> V_32 -> V_279 ) ;
return;
}
F_139 ( V_2 -> V_32 , V_271 ) ;
F_108 ( & V_2 -> V_148 ) ;
V_2 -> V_92 = V_93 ;
F_104 ( V_2 ) ;
F_109 ( & V_2 -> V_148 ) ;
F_188 ( V_2 -> V_76 ) ;
V_2 -> V_287 = 1 ;
}
static void F_189 ( struct V_235 * V_69 ,
enum V_288 V_289 )
{
struct V_1 * V_2 = F_174 ( & V_69 -> V_69 ) ;
F_37 ( & V_69 -> V_69 , L_81 , V_289 ) ;
switch ( V_289 ) {
case V_290 :
case V_291 :
case V_247 :
case V_292 :
case V_293 :
case V_294 :
break;
case V_271 :
F_185 ( V_2 ) ;
break;
case V_295 :
if ( V_69 -> V_274 == V_295 )
break;
case V_275 :
F_175 ( V_2 ) ;
break;
}
}
static int F_190 ( struct V_235 * V_32 )
{
struct V_1 * V_2 = F_174 ( & V_32 -> V_69 ) ;
struct V_55 * V_64 = NULL ;
struct V_75 * V_296 ;
F_37 ( & V_32 -> V_69 , L_82 , V_32 -> V_243 ) ;
F_110 ( V_2 , 0 ) ;
F_176 ( & V_2 -> V_253 ) ;
V_296 = V_2 -> V_76 ;
if ( V_296 )
V_64 = F_178 ( V_296 , 0 ) ;
V_2 -> V_32 = NULL ;
F_177 ( & V_2 -> V_253 ) ;
if ( ! V_64 ) {
F_7 ( V_2 ) ;
return 0 ;
}
F_176 ( & V_64 -> V_276 ) ;
V_2 = V_296 -> V_68 ;
F_137 ( F_191 ( V_296 ) ,
L_83 ,
V_32 -> V_243 , V_64 -> V_277 ) ;
if ( V_2 && ! V_64 -> V_277 ) {
F_97 ( V_2 ) ;
V_296 -> V_68 = NULL ;
F_7 ( V_2 ) ;
}
F_177 ( & V_64 -> V_276 ) ;
F_181 ( V_64 ) ;
return 0 ;
}
static int F_192 ( struct V_235 * V_69 )
{
struct V_1 * V_2 = F_174 ( & V_69 -> V_69 ) ;
return V_2 -> V_287 && V_2 -> V_32 ;
}
static int F_193 ( struct V_55 * V_64 , T_3 V_65 )
{
struct V_75 * V_296 = V_64 -> V_60 ;
struct V_1 * V_2 ;
int V_190 = 0 ;
F_176 ( & V_297 ) ;
V_2 = V_296 -> V_68 ;
if ( ! V_2 ) {
V_190 = - V_298 ;
goto V_195;
}
F_176 ( & V_2 -> V_253 ) ;
if ( ! V_2 -> V_76 )
V_190 = - V_298 ;
F_177 ( & V_2 -> V_253 ) ;
V_195:
F_177 ( & V_297 ) ;
return V_190 ;
}
static void F_194 ( struct V_75 * V_296 , T_3 V_65 )
{
struct V_1 * V_2 = V_296 -> V_68 ;
struct V_55 * V_64 ;
struct V_235 * V_32 ;
F_176 ( & V_297 ) ;
V_64 = F_178 ( V_296 , 0 ) ;
if ( ! V_64 ) {
F_120 ( 1 , L_84 , V_296 -> V_158 ) ;
goto V_299;
}
if ( V_64 -> V_277 )
goto V_195;
F_176 ( & V_2 -> V_253 ) ;
V_32 = V_2 -> V_32 ;
if ( V_32 && V_32 -> V_274 == V_275 ) {
F_195 ( F_191 ( V_64 -> V_60 ) , L_85 ) ;
F_97 ( V_2 ) ;
F_179 ( V_2 -> V_32 ) ;
}
F_177 ( & V_2 -> V_253 ) ;
if ( ! V_32 ) {
F_195 ( F_191 ( V_64 -> V_60 ) , L_85 ) ;
F_97 ( V_2 ) ;
V_296 -> V_68 = NULL ;
F_7 ( V_2 ) ;
}
V_195:
F_181 ( V_64 ) ;
V_299:
F_177 ( & V_297 ) ;
}
static int T_7 F_196 ( void )
{
int V_300 ;
if ( ! F_197 () )
return - V_186 ;
if ( ! F_198 () )
return - V_186 ;
if ( F_199 ( V_184 , V_197 ) ) {
F_86 ( V_185 L_86 ,
V_184 , V_197 ) ;
return - V_186 ;
}
V_300 = F_200 ( & V_301 ) ;
if ( V_300 ) {
F_201 ( V_184 , V_197 ) ;
return V_300 ;
}
return 0 ;
}
static void T_8 F_202 ( void )
{
F_203 ( & V_301 ) ;
F_201 ( V_184 , V_197 ) ;
F_7 ( V_50 ) ;
}
