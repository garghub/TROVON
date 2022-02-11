void F_1 ( struct V_1 * V_2 , bool V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_5 -> V_8 ;
struct V_9 * V_10 = V_5 -> V_11 ;
struct V_12 * V_13 = & V_10 -> V_14 ;
memset ( V_13 , 0 , sizeof( struct V_12 ) ) ;
V_13 -> V_15 . V_16 = V_17 ;
if ( V_3 )
V_13 -> V_18 . V_19 . V_20 . V_21 =
V_22 ;
else
V_13 -> V_18 . V_19 . V_20 . V_21 =
V_23 ;
F_3 ( V_7 -> V_24 , V_13 ,
sizeof( struct V_12 ) ,
( unsigned long ) V_13 ,
V_25 , 0 ) ;
}
static struct V_9 * F_4 ( void )
{
struct V_9 * V_1 ;
V_1 = F_5 ( sizeof( struct V_9 ) , V_26 ) ;
if ( ! V_1 )
return NULL ;
V_1 -> V_27 = F_5 ( V_28 , V_26 ) ;
if ( ! V_1 -> V_27 ) {
F_6 ( V_1 ) ;
return NULL ;
}
F_7 ( & V_1 -> V_29 ) ;
V_1 -> V_30 = false ;
F_8 ( & V_1 -> V_31 , 0 ) ;
V_1 -> V_32 = V_33 ;
V_1 -> V_34 = V_35 ;
return V_1 ;
}
static void F_9 ( struct V_9 * V_11 )
{
F_6 ( V_11 -> V_27 ) ;
F_6 ( V_11 ) ;
}
static struct V_9 * F_10 ( struct V_6 * V_36 )
{
struct V_9 * V_1 = F_11 ( V_36 ) ;
if ( V_1 && V_1 -> V_30 )
V_1 = NULL ;
return V_1 ;
}
static struct V_9 * F_12 ( struct V_6 * V_36 )
{
struct V_9 * V_1 = F_11 ( V_36 ) ;
if ( ! V_1 )
goto V_37;
if ( V_1 -> V_30 &&
F_13 ( & V_1 -> V_38 ) == 0 )
V_1 = NULL ;
V_37:
return V_1 ;
}
static int F_14 ( struct V_6 * V_36 )
{
struct V_12 * V_39 ;
int V_40 = 0 ;
struct V_1 * V_2 = F_15 ( V_36 ) ;
struct V_9 * V_1 = F_16 ( V_2 ) ;
if ( V_1 -> V_41 ) {
V_39 = & V_1 -> V_39 ;
memset ( V_39 , 0 , sizeof( struct V_12 ) ) ;
V_39 -> V_15 . V_16 =
V_42 ;
V_39 -> V_18 . V_43 .
V_44 . V_45 = V_46 ;
V_40 = F_3 ( V_36 -> V_24 ,
V_39 ,
sizeof( struct V_12 ) ,
( unsigned long ) V_39 ,
V_25 , 0 ) ;
if ( V_40 != 0 ) {
F_17 ( V_2 , L_1
L_2 ) ;
return V_40 ;
}
}
if ( V_1 -> V_47 ) {
V_40 = F_18 ( V_36 -> V_24 ,
V_1 -> V_47 ) ;
if ( V_40 != 0 ) {
F_17 ( V_2 ,
L_3 ) ;
return V_40 ;
}
V_1 -> V_47 = 0 ;
}
if ( V_1 -> V_48 ) {
F_19 ( V_1 -> V_48 ) ;
V_1 -> V_48 = NULL ;
}
if ( V_1 -> V_49 ) {
V_1 -> V_41 = 0 ;
F_6 ( V_1 -> V_49 ) ;
V_1 -> V_49 = NULL ;
}
if ( V_1 -> V_50 ) {
V_39 = & V_1 -> V_39 ;
memset ( V_39 , 0 , sizeof( struct V_12 ) ) ;
V_39 -> V_15 . V_16 =
V_51 ;
V_39 -> V_18 . V_43 . V_52 . V_45 =
V_53 ;
V_40 = F_3 ( V_36 -> V_24 ,
V_39 ,
sizeof( struct V_12 ) ,
( unsigned long ) V_39 ,
V_25 , 0 ) ;
if ( V_40 != 0 ) {
F_17 ( V_2 , L_1
L_4 ) ;
return V_40 ;
}
}
if ( V_1 -> V_54 ) {
V_40 = F_18 ( V_36 -> V_24 ,
V_1 -> V_54 ) ;
if ( V_40 != 0 ) {
F_17 ( V_2 ,
L_5 ) ;
return V_40 ;
}
V_1 -> V_54 = 0 ;
}
if ( V_1 -> V_55 ) {
F_19 ( V_1 -> V_55 ) ;
V_1 -> V_55 = NULL ;
}
F_6 ( V_1 -> V_56 ) ;
return V_40 ;
}
static int F_20 ( struct V_6 * V_36 )
{
int V_40 = 0 ;
struct V_9 * V_1 ;
struct V_12 * V_57 ;
struct V_1 * V_2 ;
int V_58 ;
V_1 = F_10 ( V_36 ) ;
if ( ! V_1 )
return - V_59 ;
V_2 = F_15 ( V_36 ) ;
V_58 = F_21 ( V_36 -> V_24 -> V_60 ) ;
V_1 -> V_48 = F_22 ( V_1 -> V_61 , V_58 ) ;
if ( ! V_1 -> V_48 )
V_1 -> V_48 = F_23 ( V_1 -> V_61 ) ;
if ( ! V_1 -> V_48 ) {
F_17 ( V_2 , L_6
L_7 , V_1 -> V_61 ) ;
V_40 = - V_62 ;
goto V_63;
}
V_40 = F_24 ( V_36 -> V_24 , V_1 -> V_48 ,
V_1 -> V_61 ,
& V_1 -> V_47 ) ;
if ( V_40 != 0 ) {
F_17 ( V_2 ,
L_8 ) ;
goto V_63;
}
V_57 = & V_1 -> V_14 ;
memset ( V_57 , 0 , sizeof( struct V_12 ) ) ;
V_57 -> V_15 . V_16 = V_64 ;
V_57 -> V_18 . V_43 . V_65 .
V_66 = V_1 -> V_47 ;
V_57 -> V_18 . V_43 .
V_65 . V_45 = V_46 ;
V_40 = F_3 ( V_36 -> V_24 , V_57 ,
sizeof( struct V_12 ) ,
( unsigned long ) V_57 ,
V_25 ,
V_67 ) ;
if ( V_40 != 0 ) {
F_17 ( V_2 ,
L_9 ) ;
goto V_63;
}
F_25 ( & V_1 -> V_68 ) ;
if ( V_57 -> V_18 . V_43 .
V_69 . V_70 != V_71 ) {
F_17 ( V_2 , L_10
L_11 ,
V_57 -> V_18 . V_43 .
V_69 . V_70 ) ;
V_40 = - V_72 ;
goto V_63;
}
V_1 -> V_41 = V_57 -> V_18 .
V_43 . V_69 . V_73 ;
V_1 -> V_49 = F_26 (
V_57 -> V_18 . V_43 . V_69 . V_74 ,
V_1 -> V_41 *
sizeof( struct V_75 ) ,
V_26 ) ;
if ( V_1 -> V_49 == NULL ) {
V_40 = - V_72 ;
goto V_63;
}
if ( V_1 -> V_41 != 1 ||
V_1 -> V_49 -> V_76 != 0 ) {
V_40 = - V_72 ;
goto V_63;
}
V_1 -> V_55 = F_22 ( V_1 -> V_77 , V_58 ) ;
if ( ! V_1 -> V_55 )
V_1 -> V_55 = F_23 ( V_1 -> V_77 ) ;
if ( ! V_1 -> V_55 ) {
F_17 ( V_2 , L_12
L_7 , V_1 -> V_77 ) ;
V_40 = - V_62 ;
goto V_63;
}
V_40 = F_24 ( V_36 -> V_24 , V_1 -> V_55 ,
V_1 -> V_77 ,
& V_1 -> V_54 ) ;
if ( V_40 != 0 ) {
F_17 ( V_2 ,
L_13 ) ;
goto V_63;
}
V_57 = & V_1 -> V_14 ;
memset ( V_57 , 0 , sizeof( struct V_12 ) ) ;
V_57 -> V_15 . V_16 = V_78 ;
V_57 -> V_18 . V_43 . V_79 . V_66 =
V_1 -> V_54 ;
V_57 -> V_18 . V_43 . V_79 . V_45 = V_53 ;
V_40 = F_3 ( V_36 -> V_24 , V_57 ,
sizeof( struct V_12 ) ,
( unsigned long ) V_57 ,
V_25 ,
V_67 ) ;
if ( V_40 != 0 ) {
F_17 ( V_2 ,
L_14 ) ;
goto V_63;
}
F_25 ( & V_1 -> V_68 ) ;
if ( V_57 -> V_18 . V_43 .
V_80 . V_70 != V_71 ) {
F_17 ( V_2 , L_15
L_11 ,
V_57 -> V_18 . V_43 .
V_80 . V_70 ) ;
V_40 = - V_72 ;
goto V_63;
}
V_1 -> V_50 = V_57 -> V_18 .
V_43 . V_80 . V_81 ;
V_1 -> V_82 =
V_1 -> V_77 / V_1 -> V_50 ;
F_27 ( & V_36 -> V_36 , L_16 ,
V_1 -> V_50 , V_1 -> V_82 ) ;
V_1 -> V_83 = F_28 ( V_1 -> V_82 ,
V_84 ) ;
V_1 -> V_56 =
F_5 ( V_1 -> V_83 * sizeof( V_85 ) , V_26 ) ;
if ( V_1 -> V_56 == NULL ) {
V_40 = - V_62 ;
goto V_63;
}
goto exit;
V_63:
F_14 ( V_36 ) ;
exit:
return V_40 ;
}
static int F_29 ( struct V_6 * V_36 ,
struct V_9 * V_1 ,
struct V_12 * V_57 ,
T_1 V_86 )
{
struct V_1 * V_2 = F_15 ( V_36 ) ;
int V_40 ;
memset ( V_57 , 0 , sizeof( struct V_12 ) ) ;
V_57 -> V_15 . V_16 = V_87 ;
V_57 -> V_18 . V_88 . V_89 . V_90 = V_86 ;
V_57 -> V_18 . V_88 . V_89 . V_91 = V_86 ;
V_40 = F_3 ( V_36 -> V_24 , V_57 ,
sizeof( struct V_12 ) ,
( unsigned long ) V_57 ,
V_25 ,
V_67 ) ;
if ( V_40 != 0 )
return V_40 ;
F_25 ( & V_1 -> V_68 ) ;
if ( V_57 -> V_18 . V_88 . V_92 . V_70 !=
V_71 )
return - V_72 ;
if ( V_86 == V_93 )
return 0 ;
memset ( V_57 , 0 , sizeof( struct V_12 ) ) ;
V_57 -> V_15 . V_16 = V_94 ;
V_57 -> V_18 . V_95 . V_96 . V_97 = V_2 -> V_97 + V_98 ;
V_57 -> V_18 . V_95 . V_96 . V_99 . V_100 = 1 ;
if ( V_86 >= V_101 )
V_57 -> V_18 . V_95 . V_96 . V_99 . V_102 = 1 ;
V_40 = F_3 ( V_36 -> V_24 , V_57 ,
sizeof( struct V_12 ) ,
( unsigned long ) V_57 ,
V_25 , 0 ) ;
return V_40 ;
}
static int F_30 ( struct V_6 * V_36 )
{
int V_40 ;
struct V_9 * V_1 ;
struct V_12 * V_57 ;
int V_103 ;
T_1 V_104 [] = { V_93 , V_105 ,
V_106 , V_101 } ;
int V_107 , V_108 = 4 ;
V_1 = F_10 ( V_36 ) ;
if ( ! V_1 )
return - V_59 ;
V_57 = & V_1 -> V_14 ;
for ( V_107 = V_108 - 1 ; V_107 >= 0 ; V_107 -- )
if ( F_29 ( V_36 , V_1 , V_57 ,
V_104 [ V_107 ] ) == 0 ) {
V_1 -> V_109 = V_104 [ V_107 ] ;
break;
}
if ( V_107 < 0 ) {
V_40 = - V_110 ;
goto V_63;
}
F_31 ( L_17 , V_1 -> V_109 ) ;
memset ( V_57 , 0 , sizeof( struct V_12 ) ) ;
if ( V_1 -> V_109 <= V_106 )
V_103 = 0x00060001 ;
else
V_103 = 0x0006001e ;
V_57 -> V_15 . V_16 = V_111 ;
V_57 -> V_18 . V_43 .
V_112 . V_113 =
( V_103 & 0xFFFF0000 ) >> 16 ;
V_57 -> V_18 . V_43 .
V_112 . V_114 =
V_103 & 0xFFFF ;
V_40 = F_3 ( V_36 -> V_24 , V_57 ,
sizeof( struct V_12 ) ,
( unsigned long ) V_57 ,
V_25 , 0 ) ;
if ( V_40 != 0 )
goto V_63;
if ( V_1 -> V_109 <= V_105 )
V_1 -> V_61 = V_115 ;
else
V_1 -> V_61 = V_116 ;
V_1 -> V_77 = V_117 ;
V_40 = F_20 ( V_36 ) ;
V_63:
return V_40 ;
}
static void F_32 ( struct V_6 * V_36 )
{
F_14 ( V_36 ) ;
}
int F_33 ( struct V_6 * V_36 )
{
struct V_1 * V_2 = F_15 ( V_36 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_9 * V_1 = V_5 -> V_11 ;
F_32 ( V_36 ) ;
V_5 -> V_11 = NULL ;
F_34 ( & V_36 -> V_36 , L_18 ) ;
F_35 ( V_36 -> V_24 ) ;
F_19 ( V_1 -> V_118 ) ;
F_9 ( V_1 ) ;
return 0 ;
}
static inline T_1 F_36 (
struct V_119 * V_120 )
{
T_1 V_121 , V_122 ;
F_37 ( V_120 , & V_121 , & V_122 ) ;
return V_122 * 100 / V_120 -> V_123 ;
}
static inline void F_38 ( struct V_9 * V_1 ,
T_1 V_124 )
{
F_39 ( V_124 , V_1 -> V_56 ) ;
}
static void F_40 ( struct V_9 * V_1 ,
struct V_125 * V_126 ,
struct V_6 * V_36 ,
struct V_127 * V_128 )
{
struct V_12 * V_129 ;
struct V_130 * V_131 ;
struct V_1 * V_2 = F_15 ( V_36 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_1 V_132 ;
struct V_133 * V_134 ;
V_129 = (struct V_12 * ) ( ( unsigned long ) V_128 +
( V_128 -> V_135 << 3 ) ) ;
if ( ( V_129 -> V_15 . V_16 == V_136 ) ||
( V_129 -> V_15 . V_16 ==
V_137 ) ||
( V_129 -> V_15 . V_16 ==
V_138 ) ||
( V_129 -> V_15 . V_16 ==
V_139 ) ) {
memcpy ( & V_1 -> V_14 , V_129 ,
sizeof( struct V_12 ) ) ;
F_41 ( & V_1 -> V_68 ) ;
} else if ( V_129 -> V_15 . V_16 ==
V_140 ) {
int V_38 ;
T_2 V_141 = 0 ;
struct V_125 * V_24 = V_36 -> V_24 ;
int V_142 ;
V_134 = (struct V_133 * ) ( unsigned long ) V_128 -> V_143 ;
if ( V_134 ) {
V_131 = (struct V_130 * ) V_134 -> V_144 ;
V_132 = V_131 -> V_145 ;
if ( V_132 != V_146 )
F_38 ( V_1 , V_132 ) ;
V_141 = V_131 -> V_141 ;
V_24 = V_126 ;
F_42 ( V_134 ) ;
}
V_38 =
F_43 ( & V_1 -> V_38 ) ;
V_142 = F_43 ( & V_1 ->
V_142 [ V_141 ] ) ;
if ( V_1 -> V_30 && V_38 == 0 )
F_44 ( & V_1 -> V_29 ) ;
if ( F_45 ( F_46 ( V_2 , V_141 ) ) &&
! V_5 -> V_147 &&
( F_36 ( & V_24 -> V_148 ) >
V_149 || V_142 < 1 ) )
F_47 ( F_46 (
V_2 , V_141 ) ) ;
} else {
F_17 ( V_2 , L_19
L_20 , V_129 -> V_15 . V_16 ) ;
}
}
static T_1 F_48 ( struct V_9 * V_1 )
{
unsigned long V_124 ;
T_1 V_150 = V_1 -> V_83 ;
unsigned long * V_151 = ( unsigned long * ) V_1 -> V_56 ;
T_1 V_152 = V_1 -> V_82 ;
int V_153 = V_146 ;
int V_107 ;
int V_154 ;
for ( V_107 = 0 ; V_107 < V_150 ; V_107 ++ ) {
if ( ! ~ ( V_151 [ V_107 ] ) )
continue;
V_124 = F_49 ( V_151 [ V_107 ] ) ;
V_154 = F_50 ( V_124 , & V_151 [ V_107 ] ) ;
if ( V_154 )
continue;
if ( ( V_124 + ( V_107 * V_84 ) ) >= V_152 )
break;
V_153 = ( V_124 + ( V_107 * V_84 ) ) ;
break;
}
return V_153 ;
}
static T_1 F_51 ( struct V_9 * V_1 ,
unsigned int V_155 ,
T_1 V_156 ,
struct V_130 * V_128 ,
struct V_157 * V_158 ,
struct V_159 * * V_160 ,
struct V_133 * V_134 )
{
char * V_161 = V_1 -> V_55 ;
char * V_162 = V_161 + ( V_155 * V_1 -> V_50 )
+ V_156 ;
int V_107 ;
bool V_163 = ( V_134 != NULL ) ? true : false ;
bool V_164 = ( V_134 != NULL ) ? V_134 -> V_164 : false ;
T_1 V_165 = 0 ;
T_1 V_166 = 0 ;
T_1 V_167 = V_128 -> V_168 % V_1 -> V_34 ;
T_1 V_169 = V_128 -> V_170 ? V_128 -> V_171 :
V_128 -> V_172 ;
if ( V_163 && V_164 && V_167 &&
! V_128 -> V_170 ) {
V_166 = V_1 -> V_34 - V_167 ;
V_158 -> V_173 += V_166 ;
V_128 -> V_168 += V_166 ;
}
for ( V_107 = 0 ; V_107 < V_169 ; V_107 ++ ) {
char * V_174 = F_52 ( ( * V_160 ) [ V_107 ] . V_175 << V_176 ) ;
T_1 V_76 = ( * V_160 ) [ V_107 ] . V_76 ;
T_1 V_177 = ( * V_160 ) [ V_107 ] . V_177 ;
memcpy ( V_162 , ( V_174 + V_76 ) , V_177 ) ;
V_165 += V_177 ;
V_162 += V_177 ;
}
if ( V_166 ) {
memset ( V_162 , 0 , V_166 ) ;
V_165 += V_166 ;
}
return V_165 ;
}
static inline int F_53 (
struct V_6 * V_36 ,
struct V_130 * V_128 ,
struct V_9 * V_1 ,
struct V_159 * * V_160 ,
struct V_133 * V_134 )
{
struct V_12 V_178 ;
T_2 V_141 = V_128 -> V_141 ;
struct V_125 * V_179 = V_1 -> V_180 [ V_141 ] ;
struct V_1 * V_2 = F_15 ( V_36 ) ;
T_3 V_181 ;
int V_40 ;
struct V_159 * V_182 ;
T_1 V_183 = F_36 ( & V_179 -> V_148 ) ;
bool V_164 = ( V_134 != NULL ) ? V_134 -> V_164 : false ;
V_178 . V_15 . V_16 = V_184 ;
if ( V_134 != NULL ) {
V_178 . V_18 . V_43 . V_185 . V_186 = 0 ;
} else {
V_178 . V_18 . V_43 . V_185 . V_186 = 1 ;
}
V_178 . V_18 . V_43 . V_185 . V_187 =
V_128 -> V_145 ;
if ( V_128 -> V_145 == V_146 )
V_178 . V_18 . V_43 . V_185 . V_188 = 0 ;
else
V_178 . V_18 . V_43 . V_185 . V_188 =
V_128 -> V_168 ;
V_181 = ( V_85 ) V_134 ;
if ( V_179 -> V_189 )
return - V_59 ;
if ( V_183 < ( V_190 + 1 ) )
V_164 = false ;
if ( V_128 -> V_172 ) {
V_182 = V_128 -> V_170 ? ( * V_160 ) +
V_128 -> V_171 : ( * V_160 ) ;
V_40 = F_54 ( V_179 ,
V_182 ,
V_128 -> V_172 ,
& V_178 ,
sizeof( struct V_12 ) ,
V_181 ,
V_67 ,
! V_164 ) ;
} else {
V_40 = F_55 ( V_179 , & V_178 ,
sizeof( struct V_12 ) ,
V_181 ,
V_25 ,
V_67 ,
! V_164 ) ;
}
if ( V_40 == 0 ) {
F_56 ( & V_1 -> V_38 ) ;
F_56 ( & V_1 -> V_142 [ V_141 ] ) ;
if ( V_183 < V_190 ) {
F_57 ( F_46 ( V_2 , V_141 ) ) ;
if ( F_13 ( & V_1 ->
V_142 [ V_141 ] ) < 1 )
F_47 ( F_46 (
V_2 , V_141 ) ) ;
}
} else if ( V_40 == - V_191 ) {
F_57 ( F_46 (
V_2 , V_141 ) ) ;
if ( F_13 ( & V_1 -> V_142 [ V_141 ] ) < 1 ) {
F_47 ( F_46 (
V_2 , V_141 ) ) ;
V_40 = - V_192 ;
}
} else {
F_17 ( V_2 , L_21 ,
V_128 , V_40 ) ;
}
return V_40 ;
}
static inline void F_58 ( struct V_130 * * V_193 ,
struct V_133 * * V_194 ,
struct V_195 * V_196 )
{
* V_194 = V_196 -> V_134 ;
* V_193 = V_196 -> V_197 ;
V_196 -> V_134 = NULL ;
V_196 -> V_197 = NULL ;
V_196 -> V_198 = 0 ;
}
int F_59 ( struct V_6 * V_36 ,
struct V_130 * V_128 ,
struct V_157 * V_158 ,
struct V_159 * * V_160 ,
struct V_133 * V_134 )
{
struct V_9 * V_1 ;
int V_40 = 0 , V_199 = 0 ;
struct V_125 * V_179 ;
T_2 V_141 = V_128 -> V_141 ;
T_1 V_200 = V_128 -> V_168 , V_201 = 0 ;
unsigned int V_155 = V_146 ;
struct V_195 * V_196 ;
struct V_130 * V_193 = NULL , * V_202 = NULL ;
struct V_133 * V_194 = NULL ;
bool V_203 ;
bool V_164 = ( V_134 != NULL ) ? V_134 -> V_164 : false ;
V_1 = F_10 ( V_36 ) ;
if ( ! V_1 )
return - V_59 ;
V_179 = V_1 -> V_180 [ V_141 ] ;
V_128 -> V_145 = V_146 ;
V_128 -> V_170 = false ;
if ( ! V_134 ) {
V_202 = V_128 ;
goto V_204;
}
V_196 = & V_1 -> V_205 [ V_141 ] ;
if ( V_196 -> V_197 )
V_201 = V_196 -> V_197 -> V_168 ;
V_203 = ( V_134 != NULL ) && V_201 > 0 && V_196 -> V_198 <
V_1 -> V_32 ;
if ( V_203 && V_201 + V_200 + V_1 -> V_34 <
V_1 -> V_50 ) {
V_155 = V_196 -> V_197 -> V_145 ;
} else if ( V_203 && V_201 + V_128 -> V_206 <
V_1 -> V_50 ) {
V_155 = V_196 -> V_197 -> V_145 ;
V_128 -> V_170 = true ;
} else if ( ( V_134 != NULL ) && V_200 + V_1 -> V_34 <
V_1 -> V_50 ) {
V_155 = F_48 ( V_1 ) ;
if ( V_155 != V_146 ) {
F_58 ( & V_193 , & V_194 , V_196 ) ;
V_201 = 0 ;
}
}
if ( V_155 != V_146 ) {
F_51 ( V_1 ,
V_155 , V_201 ,
V_128 , V_158 , V_160 , V_134 ) ;
V_128 -> V_145 = V_155 ;
if ( V_128 -> V_170 ) {
V_128 -> V_172 -= V_128 -> V_171 ;
V_128 -> V_168 = V_201 + V_128 -> V_206 ;
} else {
V_128 -> V_172 = 0 ;
V_128 -> V_168 += V_201 ;
}
if ( V_196 -> V_134 )
F_42 ( V_196 -> V_134 ) ;
if ( V_164 && ! V_128 -> V_170 ) {
V_196 -> V_134 = V_134 ;
V_196 -> V_197 = V_128 ;
V_196 -> V_198 ++ ;
} else {
V_202 = V_128 ;
V_196 -> V_134 = NULL ;
V_196 -> V_197 = NULL ;
V_196 -> V_198 = 0 ;
}
} else {
F_58 ( & V_193 , & V_194 , V_196 ) ;
V_202 = V_128 ;
}
if ( V_193 ) {
V_199 = F_53 ( V_36 , V_193 , V_1 ,
NULL , V_194 ) ;
if ( V_199 != 0 ) {
F_38 ( V_1 ,
V_193 -> V_145 ) ;
F_42 ( V_194 ) ;
}
}
V_204:
if ( V_202 )
V_40 = F_53 ( V_36 , V_202 , V_1 , V_160 , V_134 ) ;
if ( V_40 != 0 && V_155 != V_146 )
F_38 ( V_1 , V_155 ) ;
return V_40 ;
}
static void F_60 ( struct V_6 * V_36 ,
struct V_125 * V_24 ,
struct V_9 * V_1 ,
T_3 V_207 , T_1 V_70 )
{
struct V_12 V_208 ;
int V_209 = 0 ;
int V_40 ;
struct V_1 * V_2 = F_15 ( V_36 ) ;
V_208 . V_15 . V_16 =
V_140 ;
V_208 . V_18 . V_43 . V_210 . V_70 = V_70 ;
V_211:
V_40 = F_3 ( V_24 , & V_208 ,
sizeof( struct V_12 ) , V_207 ,
V_212 , 0 ) ;
if ( V_40 == 0 ) {
} else if ( V_40 == - V_191 ) {
V_209 ++ ;
F_17 ( V_2 , L_22
L_23 , V_207 , V_209 ) ;
if ( V_209 < 4 ) {
F_61 ( 100 ) ;
goto V_211;
} else {
F_17 ( V_2 , L_24
L_25 ,
V_207 ) ;
}
} else {
F_17 ( V_2 , L_24
L_26 , V_207 ) ;
}
}
static void F_62 ( struct V_9 * V_1 ,
struct V_125 * V_24 ,
struct V_6 * V_36 ,
struct V_127 * V_128 )
{
struct V_213 * V_214 ;
struct V_12 * V_129 ;
struct V_130 V_215 ;
struct V_130 * V_216 = & V_215 ;
T_1 V_70 = V_71 ;
int V_107 ;
int V_198 = 0 ;
struct V_1 * V_2 = F_15 ( V_36 ) ;
void * V_217 ;
if ( V_128 -> type != V_218 ) {
F_17 ( V_2 , L_27 ,
V_128 -> type ) ;
return;
}
V_129 = (struct V_12 * ) ( ( unsigned long ) V_128 +
( V_128 -> V_135 << 3 ) ) ;
if ( V_129 -> V_15 . V_16 !=
V_184 ) {
F_17 ( V_2 , L_28
L_29 , V_129 -> V_15 . V_16 ) ;
return;
}
V_214 = (struct V_213 * ) V_128 ;
if ( V_214 -> V_219 != V_46 ) {
F_17 ( V_2 , L_30
L_31 , V_46 ,
V_214 -> V_219 ) ;
return;
}
V_198 = V_214 -> V_220 ;
for ( V_107 = 0 ; V_107 < V_198 ; V_107 ++ ) {
V_217 = ( void * ) ( ( unsigned long ) V_1 ->
V_48 + V_214 -> V_221 [ V_107 ] . V_222 ) ;
V_216 -> V_168 =
V_214 -> V_221 [ V_107 ] . V_223 ;
V_70 = F_63 ( V_36 , V_216 , & V_217 ,
V_24 ) ;
}
F_60 ( V_36 , V_24 , V_1 ,
V_214 -> V_224 . V_143 , V_70 ) ;
}
static void F_64 ( struct V_6 * V_225 ,
struct V_12 * V_178 )
{
struct V_9 * V_226 ;
struct V_1 * V_2 = F_15 ( V_225 ) ;
int V_107 ;
T_1 V_198 , * V_227 ;
V_226 = F_10 ( V_225 ) ;
if ( ! V_226 )
return;
V_198 = V_178 -> V_18 . V_228 . V_229 . V_198 ;
if ( V_198 != V_230 ) {
F_17 ( V_2 , L_32 , V_198 ) ;
return;
}
V_227 = ( T_1 * ) ( ( unsigned long ) & V_178 -> V_18 . V_228 . V_229 +
V_178 -> V_18 . V_228 . V_229 . V_76 ) ;
for ( V_107 = 0 ; V_107 < V_198 ; V_107 ++ )
V_226 -> V_229 [ V_107 ] = V_227 [ V_107 ] ;
}
static void F_65 ( struct V_4 * V_5 ,
struct V_12 * V_178 )
{
V_5 -> V_231 = V_178 -> V_18 . V_19 . V_232 . V_233 ;
V_5 -> V_234 = V_178 -> V_18 . V_19 . V_232 . V_235 ;
}
static inline void F_66 ( struct V_6 * V_225 ,
struct V_4 * V_5 ,
struct V_12 * V_178 )
{
switch ( V_178 -> V_15 . V_16 ) {
case V_236 :
F_64 ( V_225 , V_178 ) ;
break;
case V_237 :
F_65 ( V_5 , V_178 ) ;
break;
}
}
static void F_67 ( struct V_6 * V_36 ,
struct V_125 * V_24 ,
struct V_9 * V_1 ,
struct V_1 * V_2 ,
T_3 V_238 ,
struct V_127 * V_239 )
{
struct V_12 * V_178 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
V_178 = (struct V_12 * ) ( ( unsigned long )
V_239 + ( V_239 -> V_135 << 3 ) ) ;
switch ( V_239 -> type ) {
case V_212 :
F_40 ( V_1 , V_24 , V_36 , V_239 ) ;
break;
case V_218 :
F_62 ( V_1 , V_24 , V_36 , V_239 ) ;
break;
case V_25 :
F_66 ( V_36 , V_5 , V_178 ) ;
break;
default:
F_17 ( V_2 , L_33 ,
V_239 -> type , V_238 ) ;
break;
}
}
void F_68 ( void * V_240 )
{
int V_40 ;
struct V_125 * V_24 = (struct V_125 * ) V_240 ;
struct V_6 * V_36 ;
struct V_9 * V_1 ;
T_1 V_241 ;
T_3 V_238 ;
struct V_127 * V_239 ;
unsigned char * V_242 ;
int V_243 = V_28 ;
struct V_1 * V_2 ;
bool V_244 = false ;
if ( V_24 -> V_245 != NULL )
V_36 = V_24 -> V_245 -> V_246 ;
else
V_36 = V_24 -> V_246 ;
V_1 = F_12 ( V_36 ) ;
if ( ! V_1 )
return;
V_2 = F_15 ( V_36 ) ;
V_242 = F_69 ( V_24 ) ;
do {
V_239 = F_70 ( V_24 ) ;
if ( V_239 != NULL ) {
F_67 ( V_36 ,
V_24 ,
V_1 ,
V_2 ,
V_239 -> V_143 ,
V_239 ) ;
F_71 ( V_24 , V_239 ) ;
V_244 = true ;
continue;
}
if ( V_244 ) {
V_244 = false ;
F_72 ( V_24 ) ;
}
V_40 = F_73 ( V_24 , V_242 , V_243 ,
& V_241 , & V_238 ) ;
if ( V_40 == 0 ) {
if ( V_241 > 0 ) {
V_239 = (struct V_127 * ) V_242 ;
F_67 ( V_36 ,
V_24 ,
V_1 ,
V_2 ,
V_238 ,
V_239 ) ;
} else {
break;
}
} else if ( V_40 == - V_247 ) {
if ( V_243 > V_28 )
F_6 ( V_242 ) ;
V_242 = F_74 ( V_241 , V_248 ) ;
if ( V_242 == NULL ) {
F_17 ( V_2 ,
L_34
L_35 , V_241 ) ;
break;
}
V_243 = V_241 ;
}
} while ( 1 );
if ( V_243 > V_28 )
F_6 ( V_242 ) ;
return;
}
int F_75 ( struct V_6 * V_36 , void * V_249 )
{
int V_107 , V_40 = 0 ;
int V_250 =
( (struct V_251 * ) V_249 ) -> V_250 ;
struct V_9 * V_1 ;
struct V_1 * V_2 = F_15 ( V_36 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
V_1 = F_4 () ;
if ( ! V_1 )
return - V_62 ;
V_1 -> V_250 = V_250 ;
F_76 ( & V_1 -> V_68 ) ;
F_77 ( V_36 -> V_24 , V_1 -> V_27 ) ;
V_40 = F_78 ( V_36 -> V_24 , V_250 * V_252 ,
V_250 * V_252 , NULL , 0 ,
F_68 , V_36 -> V_24 ) ;
if ( V_40 != 0 ) {
F_17 ( V_2 , L_36 , V_40 ) ;
goto V_63;
}
F_79 ( L_37 ) ;
for ( V_107 = 0 ; V_107 < V_253 ; V_107 ++ )
V_1 -> V_180 [ V_107 ] = V_36 -> V_24 ;
F_80 () ;
V_5 -> V_11 = V_1 ;
V_40 = F_30 ( V_36 ) ;
if ( V_40 != 0 ) {
F_17 ( V_2 ,
L_38 , V_40 ) ;
goto V_254;
}
return V_40 ;
V_254:
F_35 ( V_36 -> V_24 ) ;
V_63:
F_9 ( V_1 ) ;
return V_40 ;
}
