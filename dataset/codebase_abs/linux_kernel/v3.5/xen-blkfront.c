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
T_3 V_67 ;
struct V_68 * V_69 ;
if ( F_25 ( V_2 -> V_70 != V_71 ) )
return 1 ;
if ( F_26 (
V_72 , & V_67 ) < 0 ) {
F_27 (
& V_2 -> V_73 ,
F_16 ,
V_2 ,
V_72 ) ;
return 1 ;
}
V_63 = F_28 ( & V_2 -> V_74 , V_2 -> V_74 . V_75 ) ;
V_9 = F_1 ( V_2 ) ;
V_2 -> V_5 [ V_9 ] . V_11 = V_6 ;
V_63 -> V_7 . V_8 . V_9 = V_9 ;
V_63 -> V_7 . V_8 . V_76 = ( V_77 ) F_29 ( V_6 ) ;
V_63 -> V_7 . V_8 . V_78 = V_2 -> V_78 ;
V_63 -> V_79 = F_30 ( V_6 ) ?
V_15 : V_14 ;
if ( V_6 -> V_80 & ( V_81 | V_82 ) ) {
V_63 -> V_79 = V_2 -> V_83 ;
}
if ( F_25 ( V_6 -> V_80 & ( V_84 | V_85 ) ) ) {
V_63 -> V_79 = V_18 ;
V_63 -> V_7 . V_86 . V_87 = F_31 ( V_6 ) ;
if ( ( V_6 -> V_80 & V_85 ) && V_2 -> V_88 )
V_63 -> V_7 . V_86 . V_89 = V_90 ;
else
V_63 -> V_7 . V_86 . V_89 = 0 ;
} else {
V_63 -> V_7 . V_8 . V_91 = F_32 ( V_6 -> V_92 , V_6 ,
V_2 -> V_69 ) ;
F_2 ( V_63 -> V_7 . V_8 . V_91 >
V_72 ) ;
F_33 (info->sg, sg, ring_req->u.rw.nr_segments, i) {
V_61 = F_34 ( F_35 ( F_36 ( V_69 ) ) ) ;
V_64 = V_69 -> V_93 >> 9 ;
V_65 = V_64 + ( V_69 -> V_94 >> 9 ) - 1 ;
V_66 = F_37 ( & V_67 ) ;
F_2 ( V_66 == - V_95 ) ;
F_38 (
V_66 ,
V_2 -> V_49 -> V_96 ,
V_61 ,
F_30 ( V_6 ) ) ;
V_2 -> V_5 [ V_9 ] . V_97 [ V_48 ] = F_39 ( V_61 ) ;
V_63 -> V_7 . V_8 . V_98 [ V_48 ] =
(struct V_99 ) {
. V_100 = V_66 ,
. V_101 = V_64 ,
. V_102 = V_65 } ;
}
}
V_2 -> V_74 . V_75 ++ ;
V_2 -> V_5 [ V_9 ] . V_6 = * V_63 ;
F_40 ( V_67 ) ;
return 0 ;
}
static inline void F_41 ( struct V_1 * V_2 )
{
int V_103 ;
F_42 ( & V_2 -> V_74 , V_103 ) ;
if ( V_103 )
F_43 ( V_2 -> V_104 ) ;
}
static void F_44 ( struct V_105 * V_106 )
{
struct V_1 * V_2 = NULL ;
struct V_11 * V_6 ;
int V_107 ;
F_45 ( L_10 ) ;
V_107 = 0 ;
while ( ( V_6 = F_46 ( V_106 ) ) != NULL ) {
V_2 = V_6 -> V_60 -> V_47 ;
if ( F_47 ( & V_2 -> V_74 ) )
goto V_108;
F_48 ( V_6 ) ;
if ( ( V_6 -> V_109 != V_110 ) ||
( ( V_6 -> V_80 & ( V_81 | V_82 ) ) &&
! V_2 -> V_83 ) ) {
F_49 ( V_6 , - V_111 ) ;
continue;
}
F_45 ( L_11
L_12 ,
V_6 , V_6 -> V_112 , ( unsigned long ) F_29 ( V_6 ) ,
F_50 ( V_6 ) , F_31 ( V_6 ) ,
V_6 -> V_113 , F_30 ( V_6 ) ? L_2 : L_1 ) ;
if ( F_24 ( V_6 ) ) {
F_51 ( V_106 , V_6 ) ;
V_108:
F_52 ( V_106 ) ;
break;
}
V_107 ++ ;
}
if ( V_107 != 0 )
F_41 ( V_2 ) ;
}
static int F_53 ( struct V_56 * V_57 , T_4 V_114 )
{
struct V_105 * V_106 ;
struct V_1 * V_2 = V_57 -> V_47 ;
V_106 = F_54 ( F_44 , & V_2 -> V_115 ) ;
if ( V_106 == NULL )
return - 1 ;
F_55 ( V_116 , V_106 ) ;
if ( V_2 -> V_117 ) {
F_55 ( V_118 , V_106 ) ;
F_56 ( V_106 , F_19 ( V_57 ) ) ;
V_106 -> V_119 . V_120 = V_2 -> V_120 ;
V_106 -> V_119 . V_121 = V_2 -> V_121 ;
if ( V_2 -> V_88 )
F_55 ( V_122 , V_106 ) ;
}
F_57 ( V_106 , V_114 ) ;
F_58 ( V_106 , 512 ) ;
F_59 ( V_106 , V_123 - 1 ) ;
F_60 ( V_106 , V_123 ) ;
F_61 ( V_106 , V_72 ) ;
F_62 ( V_106 , 511 ) ;
F_63 ( V_106 , V_124 ) ;
V_57 -> V_125 = V_106 ;
return 0 ;
}
static void F_64 ( struct V_1 * V_2 )
{
F_65 ( V_2 -> V_106 , V_2 -> V_126 ) ;
F_66 ( V_127 L_13 ,
V_2 -> V_57 -> V_128 ,
V_2 -> V_83 == V_16 ?
L_3 : ( V_2 -> V_83 == V_17 ?
L_14 : L_15 ) ,
V_2 -> V_126 ? L_16 : L_17 ) ;
}
static int F_67 ( int V_129 , int * V_19 , unsigned int * V_93 )
{
int V_130 ;
V_130 = F_68 ( V_129 ) ;
* V_19 = F_69 ( V_129 ) ;
switch ( V_130 ) {
case V_131 :
* V_93 = ( * V_19 / 64 ) + V_132 ;
* V_19 = ( ( * V_19 / 64 ) * V_133 ) +
V_134 ;
break;
case V_135 :
* V_93 = ( * V_19 / 64 ) + 2 + V_132 ;
* V_19 = ( ( ( * V_19 / 64 ) + 2 ) * V_133 ) +
V_134 ;
break;
case V_136 :
* V_93 = ( * V_19 / V_133 ) + V_137 ;
* V_19 = * V_19 + V_138 ;
break;
case V_139 :
case V_140 :
case V_141 :
case V_142 :
case V_143 :
case V_144 :
case V_145 :
* V_93 = ( * V_19 / V_133 ) +
( ( V_130 - V_139 + 1 ) * 16 ) +
V_137 ;
* V_19 = * V_19 +
( ( V_130 - V_139 + 1 ) * 16 * V_133 ) +
V_138 ;
break;
case V_146 :
case V_147 :
case V_148 :
case V_149 :
case V_150 :
case V_151 :
case V_152 :
case V_153 :
* V_93 = ( * V_19 / V_133 ) +
( ( V_130 - V_146 + 8 ) * 16 ) +
V_137 ;
* V_19 = * V_19 +
( ( V_130 - V_146 + 8 ) * 16 * V_133 ) +
V_138 ;
break;
case V_154 :
* V_93 = * V_19 / V_133 ;
break;
default:
F_66 ( V_155 L_18
L_19 ) ;
return - V_156 ;
}
return 0 ;
}
static char * F_70 ( char * V_157 , unsigned int V_158 )
{
if ( V_158 >= 26 )
V_157 = F_70 ( V_157 , V_158 / 26 - 1 ) ;
* V_157 = 'a' + V_158 % 26 ;
return V_157 + 1 ;
}
static int F_71 ( V_77 V_159 ,
struct V_1 * V_2 ,
T_4 V_160 , T_4 V_114 )
{
struct V_56 * V_57 ;
int V_23 = 1 ;
int V_161 ;
unsigned int V_93 ;
int V_19 ;
int V_162 ;
char * V_157 ;
F_2 ( V_2 -> V_57 != NULL ) ;
F_2 ( V_2 -> V_106 != NULL ) ;
if ( ( V_2 -> V_129 >> V_163 ) > 1 ) {
F_66 ( V_155 L_20 , V_2 -> V_129 ) ;
return - V_156 ;
}
if ( ! F_72 ( V_2 -> V_129 ) ) {
V_161 = F_67 ( V_2 -> V_129 , & V_19 , & V_93 ) ;
if ( V_161 )
return V_161 ;
V_162 = V_133 ;
} else {
V_19 = F_73 ( V_2 -> V_129 ) ;
V_162 = V_164 ;
V_93 = V_19 / V_162 ;
if ( F_74 () && V_93 < V_132 + 4 )
F_66 ( V_155 L_21
L_22
L_23 , V_2 -> V_129 ) ;
}
if ( V_19 >> V_165 ) {
F_75 ( L_24 ,
V_2 -> V_129 , V_19 ) ;
return - V_156 ;
}
if ( ( V_19 % V_162 ) == 0 )
V_23 = V_162 ;
V_161 = F_6 ( V_19 , V_23 ) ;
if ( V_161 )
goto V_166;
V_161 = - V_156 ;
V_57 = F_76 ( V_23 ) ;
if ( V_57 == NULL )
goto V_167;
strcpy ( V_57 -> V_128 , V_168 ) ;
V_157 = F_70 ( V_57 -> V_128 + sizeof( V_168 ) - 1 , V_93 ) ;
F_2 ( V_157 >= V_57 -> V_128 + V_169 ) ;
if ( V_23 > 1 )
* V_157 = 0 ;
else
snprintf ( V_157 , V_57 -> V_128 + V_169 - V_157 ,
L_25 , V_19 & ( V_162 - 1 ) ) ;
V_57 -> V_130 = V_154 ;
V_57 -> V_170 = V_19 ;
V_57 -> V_171 = & V_172 ;
V_57 -> V_47 = V_2 ;
V_57 -> V_173 = & ( V_2 -> V_49 -> V_50 ) ;
F_77 ( V_57 , V_159 ) ;
if ( F_53 ( V_57 , V_114 ) ) {
F_78 ( V_57 ) ;
goto V_167;
}
V_2 -> V_106 = V_57 -> V_125 ;
V_2 -> V_57 = V_57 ;
F_64 ( V_2 ) ;
if ( V_160 & V_174 )
F_79 ( V_57 , 1 ) ;
if ( V_160 & V_175 )
V_57 -> V_58 |= V_176 ;
if ( V_160 & V_177 )
V_57 -> V_58 |= V_59 ;
return 0 ;
V_167:
F_14 ( V_19 , V_23 ) ;
V_166:
return V_161 ;
}
static void F_80 ( struct V_1 * V_2 )
{
unsigned int V_19 , V_23 ;
unsigned long V_58 ;
if ( V_2 -> V_106 == NULL )
return;
F_81 ( & V_2 -> V_115 , V_58 ) ;
F_52 ( V_2 -> V_106 ) ;
F_82 ( & V_2 -> V_73 ) ;
F_83 ( & V_2 -> V_115 , V_58 ) ;
F_84 ( & V_2 -> V_33 ) ;
F_78 ( V_2 -> V_57 ) ;
V_19 = V_2 -> V_57 -> V_170 ;
V_23 = V_2 -> V_57 -> V_29 ;
F_14 ( V_19 , V_23 ) ;
F_85 ( V_2 -> V_106 ) ;
V_2 -> V_106 = NULL ;
F_86 ( V_2 -> V_57 ) ;
V_2 -> V_57 = NULL ;
}
static void F_87 ( struct V_1 * V_2 )
{
if ( ! F_47 ( & V_2 -> V_74 ) ) {
F_88 ( V_2 -> V_106 ) ;
F_44 ( V_2 -> V_106 ) ;
}
}
static void F_89 ( struct V_178 * V_33 )
{
struct V_1 * V_2 = F_90 ( V_33 , struct V_1 , V_33 ) ;
F_91 ( & V_2 -> V_115 ) ;
if ( V_2 -> V_70 == V_71 )
F_87 ( V_2 ) ;
F_92 ( & V_2 -> V_115 ) ;
}
static void F_93 ( struct V_1 * V_2 , int V_179 )
{
F_91 ( & V_2 -> V_115 ) ;
V_2 -> V_70 = V_179 ?
V_180 : V_181 ;
if ( V_2 -> V_106 )
F_52 ( V_2 -> V_106 ) ;
F_82 ( & V_2 -> V_73 ) ;
F_92 ( & V_2 -> V_115 ) ;
F_84 ( & V_2 -> V_33 ) ;
if ( V_2 -> V_182 != V_183 ) {
F_94 ( V_2 -> V_182 , 0 ,
( unsigned long ) V_2 -> V_74 . V_184 ) ;
V_2 -> V_182 = V_183 ;
V_2 -> V_74 . V_184 = NULL ;
}
if ( V_2 -> V_104 )
F_95 ( V_2 -> V_104 , V_2 ) ;
V_2 -> V_185 = V_2 -> V_104 = 0 ;
}
static void F_96 ( struct V_186 * V_187 )
{
int V_48 ;
for ( V_48 = 0 ; V_48 < V_187 -> V_6 . V_7 . V_8 . V_91 ; V_48 ++ )
F_94 ( V_187 -> V_6 . V_7 . V_8 . V_98 [ V_48 ] . V_100 , 0 , 0UL ) ;
}
static T_5 F_97 ( int V_104 , void * V_188 )
{
struct V_11 * V_6 ;
struct V_189 * V_190 ;
T_6 V_48 , V_191 ;
unsigned long V_58 ;
struct V_1 * V_2 = (struct V_1 * ) V_188 ;
int error ;
F_81 ( & V_2 -> V_115 , V_58 ) ;
if ( F_25 ( V_2 -> V_70 != V_71 ) ) {
F_83 ( & V_2 -> V_115 , V_58 ) ;
return V_192 ;
}
V_193:
V_191 = V_2 -> V_74 . V_184 -> V_194 ;
F_98 () ;
for ( V_48 = V_2 -> V_74 . V_195 ; V_48 != V_191 ; V_48 ++ ) {
unsigned long V_9 ;
V_190 = F_99 ( & V_2 -> V_74 , V_48 ) ;
V_9 = V_190 -> V_9 ;
if ( V_9 >= V_4 ) {
F_100 ( 1 , L_26 ,
V_2 -> V_57 -> V_128 , F_4 ( V_190 -> V_79 ) , V_9 ) ;
continue;
}
V_6 = V_2 -> V_5 [ V_9 ] . V_11 ;
if ( V_190 -> V_79 != V_18 )
F_96 ( & V_2 -> V_5 [ V_9 ] ) ;
if ( F_3 ( V_2 , V_9 ) ) {
F_100 ( 1 , L_27 ,
V_2 -> V_57 -> V_128 , F_4 ( V_190 -> V_79 ) , V_9 ) ;
continue;
}
error = ( V_190 -> V_196 == V_197 ) ? 0 : - V_111 ;
switch ( V_190 -> V_79 ) {
case V_18 :
if ( F_25 ( V_190 -> V_196 == V_198 ) ) {
struct V_105 * V_106 = V_2 -> V_106 ;
F_66 ( V_155 L_28 ,
V_2 -> V_57 -> V_128 , F_4 ( V_190 -> V_79 ) ) ;
error = - V_199 ;
V_2 -> V_117 = 0 ;
V_2 -> V_88 = 0 ;
F_101 ( V_118 , V_106 ) ;
F_101 ( V_122 , V_106 ) ;
}
F_49 ( V_6 , error ) ;
break;
case V_17 :
case V_16 :
if ( F_25 ( V_190 -> V_196 == V_198 ) ) {
F_66 ( V_155 L_28 ,
V_2 -> V_57 -> V_128 , F_4 ( V_190 -> V_79 ) ) ;
error = - V_199 ;
}
if ( F_25 ( V_190 -> V_196 == V_200 &&
V_2 -> V_5 [ V_9 ] . V_6 . V_7 . V_8 . V_91 == 0 ) ) {
F_66 ( V_155 L_29 ,
V_2 -> V_57 -> V_128 , F_4 ( V_190 -> V_79 ) ) ;
error = - V_199 ;
}
if ( F_25 ( error ) ) {
if ( error == - V_199 )
error = 0 ;
V_2 -> V_126 = 0 ;
V_2 -> V_83 = 0 ;
F_64 ( V_2 ) ;
}
case V_14 :
case V_15 :
if ( F_25 ( V_190 -> V_196 != V_197 ) )
F_22 ( & V_2 -> V_49 -> V_50 , L_30
L_31 , V_190 -> V_196 ) ;
F_49 ( V_6 , error ) ;
break;
default:
F_102 () ;
}
}
V_2 -> V_74 . V_195 = V_48 ;
if ( V_48 != V_2 -> V_74 . V_75 ) {
int V_201 ;
F_103 ( & V_2 -> V_74 , V_201 ) ;
if ( V_201 )
goto V_193;
} else
V_2 -> V_74 . V_184 -> V_202 = V_48 + 1 ;
F_87 ( V_2 ) ;
F_83 ( & V_2 -> V_115 , V_58 ) ;
return V_192 ;
}
static int F_104 ( struct V_203 * V_50 ,
struct V_1 * V_2 )
{
struct V_204 * V_184 ;
int V_161 ;
V_2 -> V_182 = V_183 ;
V_184 = (struct V_204 * ) F_105 ( V_205 | V_206 ) ;
if ( ! V_184 ) {
F_106 ( V_50 , - V_27 , L_32 ) ;
return - V_27 ;
}
F_107 ( V_184 ) ;
F_108 ( & V_2 -> V_74 , V_184 , V_123 ) ;
F_109 ( V_2 -> V_69 , V_72 ) ;
V_161 = F_110 ( V_50 , F_111 ( V_2 -> V_74 . V_184 ) ) ;
if ( V_161 < 0 ) {
F_112 ( ( unsigned long ) V_184 ) ;
V_2 -> V_74 . V_184 = NULL ;
goto V_207;
}
V_2 -> V_182 = V_161 ;
V_161 = F_113 ( V_50 , & V_2 -> V_185 ) ;
if ( V_161 )
goto V_207;
V_161 = F_114 ( V_2 -> V_185 ,
F_97 ,
V_208 , L_33 , V_2 ) ;
if ( V_161 <= 0 ) {
F_106 ( V_50 , V_161 ,
L_34 ) ;
goto V_207;
}
V_2 -> V_104 = V_161 ;
return 0 ;
V_207:
F_93 ( V_2 , 0 ) ;
return V_161 ;
}
static int F_115 ( struct V_203 * V_50 ,
struct V_1 * V_2 )
{
const char * V_209 = NULL ;
struct V_210 V_211 ;
int V_161 ;
V_161 = F_104 ( V_50 , V_2 ) ;
if ( V_161 )
goto V_166;
V_193:
V_161 = F_116 ( & V_211 ) ;
if ( V_161 ) {
F_106 ( V_50 , V_161 , L_35 ) ;
goto V_212;
}
V_161 = F_117 ( V_211 , V_50 -> V_213 ,
L_36 , L_37 , V_2 -> V_182 ) ;
if ( V_161 ) {
V_209 = L_38 ;
goto V_214;
}
V_161 = F_117 ( V_211 , V_50 -> V_213 ,
L_39 , L_37 , V_2 -> V_185 ) ;
if ( V_161 ) {
V_209 = L_40 ;
goto V_214;
}
V_161 = F_117 ( V_211 , V_50 -> V_213 , L_41 , L_42 ,
V_215 ) ;
if ( V_161 ) {
V_209 = L_43 ;
goto V_214;
}
V_161 = F_118 ( V_211 , 0 ) ;
if ( V_161 ) {
if ( V_161 == - V_216 )
goto V_193;
F_106 ( V_50 , V_161 , L_44 ) ;
goto V_212;
}
F_119 ( V_50 , V_217 ) ;
return 0 ;
V_214:
F_118 ( V_211 , 1 ) ;
if ( V_209 )
F_106 ( V_50 , V_161 , L_42 , V_209 ) ;
V_212:
F_93 ( V_2 , 0 ) ;
V_166:
return V_161 ;
}
static int F_120 ( struct V_203 * V_50 ,
const struct V_218 * V_9 )
{
int V_161 , V_129 , V_48 ;
struct V_1 * V_2 ;
V_161 = F_121 ( V_219 , V_50 -> V_213 ,
L_45 , L_46 , & V_129 ) ;
if ( V_161 != 1 ) {
V_161 = F_121 ( V_219 , V_50 -> V_213 , L_47 ,
L_46 , & V_129 ) ;
if ( V_161 != 1 ) {
F_106 ( V_50 , V_161 , L_48 ) ;
return V_161 ;
}
}
if ( F_74 () ) {
char * type ;
int V_220 ;
if ( V_221 & V_222 ) {
int V_130 ;
if ( ! F_72 ( V_129 ) )
V_130 = F_68 ( V_129 ) ;
else
V_130 = V_154 ;
if ( V_130 != V_154 ) {
F_66 ( V_127
L_49 ,
V_223 , V_129 ) ;
return - V_156 ;
}
}
type = F_122 ( V_219 , V_50 -> V_213 , L_50 , & V_220 ) ;
if ( F_123 ( type ) )
return - V_156 ;
if ( strncmp ( type , L_51 , 5 ) == 0 ) {
F_11 ( type ) ;
return - V_156 ;
}
F_11 ( type ) ;
}
V_2 = F_124 ( sizeof( * V_2 ) , V_26 ) ;
if ( ! V_2 ) {
F_106 ( V_50 , - V_27 , L_52 ) ;
return - V_27 ;
}
F_125 ( & V_2 -> V_224 ) ;
F_126 ( & V_2 -> V_115 ) ;
V_2 -> V_49 = V_50 ;
V_2 -> V_129 = V_129 ;
V_2 -> V_70 = V_181 ;
F_127 ( & V_2 -> V_33 , F_89 ) ;
for ( V_48 = 0 ; V_48 < V_4 ; V_48 ++ )
V_2 -> V_5 [ V_48 ] . V_6 . V_7 . V_8 . V_9 = V_48 + 1 ;
V_2 -> V_5 [ V_4 - 1 ] . V_6 . V_7 . V_8 . V_9 = 0x0fffffff ;
V_2 -> V_78 = F_128 ( strrchr ( V_50 -> V_213 , '/' ) + 1 , NULL , 0 ) ;
F_129 ( & V_50 -> V_50 , V_2 ) ;
V_161 = F_115 ( V_50 , V_2 ) ;
if ( V_161 ) {
F_11 ( V_2 ) ;
F_129 ( & V_50 -> V_50 , NULL ) ;
return V_161 ;
}
return 0 ;
}
static int F_130 ( struct V_1 * V_2 )
{
int V_48 ;
struct V_62 * V_6 ;
struct V_186 * V_225 ;
int V_226 ;
V_225 = F_131 ( sizeof( V_2 -> V_5 ) ,
V_205 | V_227 | V_206 ) ;
if ( ! V_225 )
return - V_27 ;
memcpy ( V_225 , V_2 -> V_5 , sizeof( V_2 -> V_5 ) ) ;
memset ( & V_2 -> V_5 , 0 , sizeof( V_2 -> V_5 ) ) ;
for ( V_48 = 0 ; V_48 < V_4 ; V_48 ++ )
V_2 -> V_5 [ V_48 ] . V_6 . V_7 . V_8 . V_9 = V_48 + 1 ;
V_2 -> V_3 = V_2 -> V_74 . V_75 ;
V_2 -> V_5 [ V_4 - 1 ] . V_6 . V_7 . V_8 . V_9 = 0x0fffffff ;
for ( V_48 = 0 ; V_48 < V_4 ; V_48 ++ ) {
if ( ! V_225 [ V_48 ] . V_11 )
continue;
V_6 = F_28 ( & V_2 -> V_74 , V_2 -> V_74 . V_75 ) ;
* V_6 = V_225 [ V_48 ] . V_6 ;
V_6 -> V_7 . V_8 . V_9 = F_1 ( V_2 ) ;
memcpy ( & V_2 -> V_5 [ V_6 -> V_7 . V_8 . V_9 ] , & V_225 [ V_48 ] , sizeof( V_225 [ V_48 ] ) ) ;
if ( V_6 -> V_79 != V_18 ) {
for ( V_226 = 0 ; V_226 < V_6 -> V_7 . V_8 . V_91 ; V_226 ++ )
F_38 (
V_6 -> V_7 . V_8 . V_98 [ V_226 ] . V_100 ,
V_2 -> V_49 -> V_96 ,
F_34 ( V_2 -> V_5 [ V_6 -> V_7 . V_8 . V_9 ] . V_97 [ V_226 ] ) ,
F_30 ( V_2 -> V_5 [ V_6 -> V_7 . V_8 . V_9 ] . V_11 ) ) ;
}
V_2 -> V_5 [ V_6 -> V_7 . V_8 . V_9 ] . V_6 = * V_6 ;
V_2 -> V_74 . V_75 ++ ;
}
F_11 ( V_225 ) ;
F_119 ( V_2 -> V_49 , V_228 ) ;
F_91 ( & V_2 -> V_115 ) ;
V_2 -> V_70 = V_71 ;
F_41 ( V_2 ) ;
F_87 ( V_2 ) ;
F_92 ( & V_2 -> V_115 ) ;
return 0 ;
}
static int F_132 ( struct V_203 * V_50 )
{
struct V_1 * V_2 = F_133 ( & V_50 -> V_50 ) ;
int V_161 ;
F_22 ( & V_50 -> V_50 , L_53 , V_50 -> V_213 ) ;
F_93 ( V_2 , V_2 -> V_70 == V_71 ) ;
V_161 = F_115 ( V_50 , V_2 ) ;
if ( V_2 -> V_70 == V_180 && ! V_161 )
V_161 = F_130 ( V_2 ) ;
return V_161 ;
}
static void
F_134 ( struct V_1 * V_2 )
{
struct V_203 * V_49 = V_2 -> V_49 ;
struct V_34 * V_43 = NULL ;
F_135 ( & V_2 -> V_224 ) ;
if ( V_49 -> V_229 == V_230 ) {
F_136 ( & V_2 -> V_224 ) ;
return;
}
if ( V_2 -> V_57 )
V_43 = F_137 ( V_2 -> V_57 , 0 ) ;
F_136 ( & V_2 -> V_224 ) ;
if ( ! V_43 ) {
F_138 ( V_49 ) ;
return;
}
F_135 ( & V_43 -> V_231 ) ;
if ( V_43 -> V_232 ) {
F_139 ( V_49 , - V_31 ,
L_54 ) ;
F_119 ( V_49 , V_230 ) ;
} else {
F_80 ( V_2 ) ;
F_138 ( V_49 ) ;
}
F_136 ( & V_43 -> V_231 ) ;
F_140 ( V_43 ) ;
}
static void F_141 ( struct V_1 * V_2 )
{
int V_161 ;
char * type ;
unsigned int V_120 ;
unsigned int V_121 ;
unsigned int V_233 ;
type = F_122 ( V_219 , V_2 -> V_49 -> V_234 , L_55 , NULL ) ;
if ( F_123 ( type ) )
return;
V_2 -> V_88 = 0 ;
if ( strncmp ( type , L_56 , 3 ) == 0 ) {
V_161 = F_142 ( V_219 , V_2 -> V_49 -> V_234 ,
L_57 , L_37 , & V_120 ,
L_58 , L_37 , & V_121 ,
NULL ) ;
if ( ! V_161 ) {
V_2 -> V_117 = 1 ;
V_2 -> V_120 = V_120 ;
V_2 -> V_121 = V_121 ;
}
V_161 = F_142 ( V_219 , V_2 -> V_49 -> V_234 ,
L_59 , L_25 , & V_233 ,
NULL ) ;
if ( ! V_161 )
V_2 -> V_88 = V_233 ;
} else if ( strncmp ( type , L_60 , 4 ) == 0 )
V_2 -> V_117 = 1 ;
F_11 ( type ) ;
}
static void F_143 ( struct V_1 * V_2 )
{
unsigned long long V_42 ;
unsigned long V_114 ;
unsigned int V_235 ;
int V_161 ;
int V_236 , V_237 , V_86 ;
switch ( V_2 -> V_70 ) {
case V_71 :
V_161 = F_121 ( V_219 , V_2 -> V_49 -> V_234 ,
L_61 , L_62 , & V_42 ) ;
if ( F_144 ( V_161 ) )
return;
F_66 ( V_127 L_63 ,
V_42 ) ;
F_77 ( V_2 -> V_57 , V_42 ) ;
F_145 ( V_2 -> V_57 ) ;
case V_180 :
return;
default:
break;
}
F_22 ( & V_2 -> V_49 -> V_50 , L_64 ,
V_238 , V_2 -> V_49 -> V_234 ) ;
V_161 = F_142 ( V_219 , V_2 -> V_49 -> V_234 ,
L_61 , L_65 , & V_42 ,
L_66 , L_37 , & V_235 ,
L_67 , L_68 , & V_114 ,
NULL ) ;
if ( V_161 ) {
F_106 ( V_2 -> V_49 , V_161 ,
L_69 ,
V_2 -> V_49 -> V_234 ) ;
return;
}
V_2 -> V_126 = 0 ;
V_2 -> V_83 = 0 ;
V_161 = F_142 ( V_219 , V_2 -> V_49 -> V_234 ,
L_70 , L_25 , & V_236 ,
NULL ) ;
if ( ! V_161 && V_236 ) {
V_2 -> V_126 = V_81 | V_82 ;
V_2 -> V_83 = V_16 ;
}
V_161 = F_142 ( V_219 , V_2 -> V_49 -> V_234 ,
L_71 , L_25 , & V_237 ,
NULL ) ;
if ( ! V_161 && V_237 ) {
V_2 -> V_126 = V_81 ;
V_2 -> V_83 = V_17 ;
}
V_161 = F_142 ( V_219 , V_2 -> V_49 -> V_234 ,
L_72 , L_25 , & V_86 ,
NULL ) ;
if ( ! V_161 && V_86 )
F_141 ( V_2 ) ;
V_161 = F_71 ( V_42 , V_2 , V_235 , V_114 ) ;
if ( V_161 ) {
F_106 ( V_2 -> V_49 , V_161 , L_73 ,
V_2 -> V_49 -> V_234 ) ;
return;
}
F_119 ( V_2 -> V_49 , V_228 ) ;
F_91 ( & V_2 -> V_115 ) ;
V_2 -> V_70 = V_71 ;
F_87 ( V_2 ) ;
F_92 ( & V_2 -> V_115 ) ;
F_146 ( V_2 -> V_57 ) ;
V_2 -> V_239 = 1 ;
}
static void F_147 ( struct V_203 * V_50 ,
enum V_240 V_241 )
{
struct V_1 * V_2 = F_133 ( & V_50 -> V_50 ) ;
F_22 ( & V_50 -> V_50 , L_74 , V_241 ) ;
switch ( V_241 ) {
case V_242 :
case V_243 :
case V_217 :
case V_244 :
case V_245 :
case V_246 :
case V_247 :
break;
case V_228 :
F_143 ( V_2 ) ;
break;
case V_230 :
F_134 ( V_2 ) ;
break;
}
}
static int F_148 ( struct V_203 * V_49 )
{
struct V_1 * V_2 = F_133 ( & V_49 -> V_50 ) ;
struct V_34 * V_43 = NULL ;
struct V_56 * V_248 ;
F_22 ( & V_49 -> V_50 , L_75 , V_49 -> V_213 ) ;
F_93 ( V_2 , 0 ) ;
F_135 ( & V_2 -> V_224 ) ;
V_248 = V_2 -> V_57 ;
if ( V_248 )
V_43 = F_137 ( V_248 , 0 ) ;
V_2 -> V_49 = NULL ;
F_136 ( & V_2 -> V_224 ) ;
if ( ! V_43 ) {
F_11 ( V_2 ) ;
return 0 ;
}
F_135 ( & V_43 -> V_231 ) ;
V_2 = V_248 -> V_47 ;
F_149 ( F_150 ( V_248 ) ,
L_76 ,
V_49 -> V_213 , V_43 -> V_232 ) ;
if ( V_2 && ! V_43 -> V_232 ) {
F_80 ( V_2 ) ;
V_248 -> V_47 = NULL ;
F_11 ( V_2 ) ;
}
F_136 ( & V_43 -> V_231 ) ;
F_140 ( V_43 ) ;
return 0 ;
}
static int F_151 ( struct V_203 * V_50 )
{
struct V_1 * V_2 = F_133 ( & V_50 -> V_50 ) ;
return V_2 -> V_239 && V_2 -> V_49 ;
}
static int F_152 ( struct V_34 * V_43 , T_2 V_44 )
{
struct V_56 * V_248 = V_43 -> V_39 ;
struct V_1 * V_2 ;
int V_161 = 0 ;
F_135 ( & V_249 ) ;
V_2 = V_248 -> V_47 ;
if ( ! V_2 ) {
V_161 = - V_250 ;
goto V_166;
}
F_135 ( & V_2 -> V_224 ) ;
if ( ! V_2 -> V_57 )
V_161 = - V_250 ;
F_136 ( & V_2 -> V_224 ) ;
V_166:
F_136 ( & V_249 ) ;
return V_161 ;
}
static int F_153 ( struct V_56 * V_248 , T_2 V_44 )
{
struct V_1 * V_2 = V_248 -> V_47 ;
struct V_34 * V_43 ;
struct V_203 * V_49 ;
F_135 ( & V_249 ) ;
V_43 = F_137 ( V_248 , 0 ) ;
if ( V_43 -> V_232 )
goto V_166;
F_135 ( & V_2 -> V_224 ) ;
V_49 = V_2 -> V_49 ;
if ( V_49 && V_49 -> V_229 == V_230 ) {
F_154 ( F_150 ( V_43 -> V_39 ) , L_77 ) ;
F_80 ( V_2 ) ;
F_138 ( V_2 -> V_49 ) ;
}
F_136 ( & V_2 -> V_224 ) ;
if ( ! V_49 ) {
F_154 ( F_150 ( V_43 -> V_39 ) , L_77 ) ;
F_80 ( V_2 ) ;
V_248 -> V_47 = NULL ;
F_11 ( V_2 ) ;
}
V_166:
F_140 ( V_43 ) ;
F_136 ( & V_249 ) ;
return 0 ;
}
static int T_7 F_155 ( void )
{
int V_251 ;
if ( ! F_156 () )
return - V_156 ;
if ( F_74 () && ! V_221 )
return - V_156 ;
if ( F_157 ( V_154 , V_168 ) ) {
F_66 ( V_155 L_78 ,
V_154 , V_168 ) ;
return - V_156 ;
}
V_251 = F_158 ( & V_252 ) ;
if ( V_251 ) {
F_159 ( V_154 , V_168 ) ;
return V_251 ;
}
return 0 ;
}
static void T_8 F_160 ( void )
{
F_161 ( & V_252 ) ;
F_159 ( V_154 , V_168 ) ;
F_11 ( V_29 ) ;
}
