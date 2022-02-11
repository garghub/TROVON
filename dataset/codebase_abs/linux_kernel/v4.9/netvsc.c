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
V_1 -> V_29 [ 0 ] . V_30 = F_7 ( V_31 *
sizeof( struct V_32 ) ) ;
F_8 ( & V_1 -> V_33 ) ;
V_1 -> V_34 = false ;
F_9 ( & V_1 -> V_35 , 0 ) ;
V_1 -> V_36 = V_37 ;
V_1 -> V_38 = V_39 ;
F_10 ( & V_1 -> V_40 ) ;
return V_1 ;
}
static void F_11 ( struct V_9 * V_11 )
{
int V_41 ;
for ( V_41 = 0 ; V_41 < V_42 ; V_41 ++ )
F_12 ( V_11 -> V_29 [ V_41 ] . V_30 ) ;
F_6 ( V_11 -> V_27 ) ;
F_6 ( V_11 ) ;
}
static struct V_9 * F_13 ( struct V_6 * V_43 )
{
struct V_9 * V_1 = F_14 ( V_43 ) ;
if ( V_1 && V_1 -> V_34 )
V_1 = NULL ;
return V_1 ;
}
static struct V_9 * F_15 ( struct V_6 * V_43 )
{
struct V_9 * V_1 = F_14 ( V_43 ) ;
if ( ! V_1 )
goto V_44;
if ( V_1 -> V_34 &&
F_16 ( & V_1 -> V_45 ) == 0 &&
F_16 ( & V_1 -> V_46 ) == 0 )
V_1 = NULL ;
V_44:
return V_1 ;
}
static void F_17 ( struct V_6 * V_43 )
{
struct V_12 * V_47 ;
struct V_1 * V_2 = F_18 ( V_43 ) ;
struct V_9 * V_1 = F_19 ( V_2 ) ;
int V_48 ;
if ( V_1 -> V_49 ) {
V_47 = & V_1 -> V_47 ;
memset ( V_47 , 0 , sizeof( struct V_12 ) ) ;
V_47 -> V_15 . V_16 =
V_50 ;
V_47 -> V_18 . V_51 .
V_52 . V_53 = V_54 ;
V_48 = F_3 ( V_43 -> V_24 ,
V_47 ,
sizeof( struct V_12 ) ,
( unsigned long ) V_47 ,
V_25 , 0 ) ;
if ( V_48 != 0 ) {
F_20 ( V_2 , L_1
L_2 ) ;
return;
}
}
if ( V_1 -> V_55 ) {
V_48 = F_21 ( V_43 -> V_24 ,
V_1 -> V_55 ) ;
if ( V_48 != 0 ) {
F_20 ( V_2 ,
L_3 ) ;
return;
}
V_1 -> V_55 = 0 ;
}
if ( V_1 -> V_56 ) {
F_12 ( V_1 -> V_56 ) ;
V_1 -> V_56 = NULL ;
}
if ( V_1 -> V_57 ) {
V_1 -> V_49 = 0 ;
F_6 ( V_1 -> V_57 ) ;
V_1 -> V_57 = NULL ;
}
if ( V_1 -> V_58 ) {
V_47 = & V_1 -> V_47 ;
memset ( V_47 , 0 , sizeof( struct V_12 ) ) ;
V_47 -> V_15 . V_16 =
V_59 ;
V_47 -> V_18 . V_51 . V_60 . V_53 =
V_61 ;
V_48 = F_3 ( V_43 -> V_24 ,
V_47 ,
sizeof( struct V_12 ) ,
( unsigned long ) V_47 ,
V_25 , 0 ) ;
if ( V_48 != 0 ) {
F_20 ( V_2 , L_1
L_4 ) ;
return;
}
}
if ( V_1 -> V_62 ) {
V_48 = F_21 ( V_43 -> V_24 ,
V_1 -> V_62 ) ;
if ( V_48 != 0 ) {
F_20 ( V_2 ,
L_5 ) ;
return;
}
V_1 -> V_62 = 0 ;
}
if ( V_1 -> V_63 ) {
F_12 ( V_1 -> V_63 ) ;
V_1 -> V_63 = NULL ;
}
F_6 ( V_1 -> V_64 ) ;
}
static int F_22 ( struct V_6 * V_43 )
{
int V_48 = 0 ;
struct V_9 * V_1 ;
struct V_12 * V_65 ;
struct V_1 * V_2 ;
int V_66 ;
V_1 = F_13 ( V_43 ) ;
if ( ! V_1 )
return - V_67 ;
V_2 = F_18 ( V_43 ) ;
V_66 = F_23 ( V_43 -> V_24 -> V_68 ) ;
V_1 -> V_56 = F_24 ( V_1 -> V_69 , V_66 ) ;
if ( ! V_1 -> V_56 )
V_1 -> V_56 = F_7 ( V_1 -> V_69 ) ;
if ( ! V_1 -> V_56 ) {
F_20 ( V_2 , L_6
L_7 , V_1 -> V_69 ) ;
V_48 = - V_70 ;
goto V_71;
}
V_48 = F_25 ( V_43 -> V_24 , V_1 -> V_56 ,
V_1 -> V_69 ,
& V_1 -> V_55 ) ;
if ( V_48 != 0 ) {
F_20 ( V_2 ,
L_8 ) ;
goto V_71;
}
V_65 = & V_1 -> V_14 ;
memset ( V_65 , 0 , sizeof( struct V_12 ) ) ;
V_65 -> V_15 . V_16 = V_72 ;
V_65 -> V_18 . V_51 . V_73 .
V_74 = V_1 -> V_55 ;
V_65 -> V_18 . V_51 .
V_73 . V_53 = V_54 ;
V_48 = F_3 ( V_43 -> V_24 , V_65 ,
sizeof( struct V_12 ) ,
( unsigned long ) V_65 ,
V_25 ,
V_75 ) ;
if ( V_48 != 0 ) {
F_20 ( V_2 ,
L_9 ) ;
goto V_71;
}
F_26 ( & V_1 -> V_40 ) ;
if ( V_65 -> V_18 . V_51 .
V_76 . V_77 != V_78 ) {
F_20 ( V_2 , L_10
L_11 ,
V_65 -> V_18 . V_51 .
V_76 . V_77 ) ;
V_48 = - V_79 ;
goto V_71;
}
V_1 -> V_49 = V_65 -> V_18 .
V_51 . V_76 . V_80 ;
V_1 -> V_57 = F_27 (
V_65 -> V_18 . V_51 . V_76 . V_81 ,
V_1 -> V_49 *
sizeof( struct V_82 ) ,
V_26 ) ;
if ( V_1 -> V_57 == NULL ) {
V_48 = - V_79 ;
goto V_71;
}
if ( V_1 -> V_49 != 1 ||
V_1 -> V_57 -> V_83 != 0 ) {
V_48 = - V_79 ;
goto V_71;
}
V_1 -> V_63 = F_24 ( V_1 -> V_84 , V_66 ) ;
if ( ! V_1 -> V_63 )
V_1 -> V_63 = F_7 ( V_1 -> V_84 ) ;
if ( ! V_1 -> V_63 ) {
F_20 ( V_2 , L_12
L_7 , V_1 -> V_84 ) ;
V_48 = - V_70 ;
goto V_71;
}
V_48 = F_25 ( V_43 -> V_24 , V_1 -> V_63 ,
V_1 -> V_84 ,
& V_1 -> V_62 ) ;
if ( V_48 != 0 ) {
F_20 ( V_2 ,
L_13 ) ;
goto V_71;
}
V_65 = & V_1 -> V_14 ;
memset ( V_65 , 0 , sizeof( struct V_12 ) ) ;
V_65 -> V_15 . V_16 = V_85 ;
V_65 -> V_18 . V_51 . V_86 . V_74 =
V_1 -> V_62 ;
V_65 -> V_18 . V_51 . V_86 . V_53 = V_61 ;
V_48 = F_3 ( V_43 -> V_24 , V_65 ,
sizeof( struct V_12 ) ,
( unsigned long ) V_65 ,
V_25 ,
V_75 ) ;
if ( V_48 != 0 ) {
F_20 ( V_2 ,
L_14 ) ;
goto V_71;
}
F_26 ( & V_1 -> V_40 ) ;
if ( V_65 -> V_18 . V_51 .
V_87 . V_77 != V_78 ) {
F_20 ( V_2 , L_15
L_11 ,
V_65 -> V_18 . V_51 .
V_87 . V_77 ) ;
V_48 = - V_79 ;
goto V_71;
}
V_1 -> V_58 = V_65 -> V_18 .
V_51 . V_87 . V_88 ;
V_1 -> V_89 =
V_1 -> V_84 / V_1 -> V_58 ;
F_28 ( & V_43 -> V_43 , L_16 ,
V_1 -> V_58 , V_1 -> V_89 ) ;
V_1 -> V_90 = F_29 ( V_1 -> V_89 ,
V_91 ) ;
V_1 -> V_64 = F_30 ( V_1 -> V_90 ,
sizeof( V_92 ) , V_26 ) ;
if ( V_1 -> V_64 == NULL ) {
V_48 = - V_70 ;
goto V_71;
}
goto exit;
V_71:
F_17 ( V_43 ) ;
exit:
return V_48 ;
}
static int F_31 ( struct V_6 * V_43 ,
struct V_9 * V_1 ,
struct V_12 * V_65 ,
T_1 V_93 )
{
struct V_1 * V_2 = F_18 ( V_43 ) ;
int V_48 ;
memset ( V_65 , 0 , sizeof( struct V_12 ) ) ;
V_65 -> V_15 . V_16 = V_94 ;
V_65 -> V_18 . V_95 . V_96 . V_97 = V_93 ;
V_65 -> V_18 . V_95 . V_96 . V_98 = V_93 ;
V_48 = F_3 ( V_43 -> V_24 , V_65 ,
sizeof( struct V_12 ) ,
( unsigned long ) V_65 ,
V_25 ,
V_75 ) ;
if ( V_48 != 0 )
return V_48 ;
F_26 ( & V_1 -> V_40 ) ;
if ( V_65 -> V_18 . V_95 . V_99 . V_77 !=
V_78 )
return - V_79 ;
if ( V_93 == V_100 )
return 0 ;
memset ( V_65 , 0 , sizeof( struct V_12 ) ) ;
V_65 -> V_15 . V_16 = V_101 ;
V_65 -> V_18 . V_102 . V_103 . V_104 = V_2 -> V_104 + V_105 ;
V_65 -> V_18 . V_102 . V_103 . V_106 . V_107 = 1 ;
if ( V_93 >= V_108 ) {
V_65 -> V_18 . V_102 . V_103 . V_106 . V_109 = 1 ;
V_65 -> V_18 . V_102 . V_103 . V_106 . V_110 = 1 ;
}
V_48 = F_3 ( V_43 -> V_24 , V_65 ,
sizeof( struct V_12 ) ,
( unsigned long ) V_65 ,
V_25 , 0 ) ;
return V_48 ;
}
static int F_32 ( struct V_6 * V_43 )
{
int V_48 ;
struct V_9 * V_1 ;
struct V_12 * V_65 ;
int V_111 ;
const T_1 V_112 [] = {
V_100 , V_113 ,
V_114 , V_108 } ;
int V_41 ;
V_1 = F_13 ( V_43 ) ;
if ( ! V_1 )
return - V_67 ;
V_65 = & V_1 -> V_14 ;
for ( V_41 = F_33 ( V_112 ) - 1 ; V_41 >= 0 ; V_41 -- )
if ( F_31 ( V_43 , V_1 , V_65 ,
V_112 [ V_41 ] ) == 0 ) {
V_1 -> V_115 = V_112 [ V_41 ] ;
break;
}
if ( V_41 < 0 ) {
V_48 = - V_116 ;
goto V_71;
}
F_34 ( L_17 , V_1 -> V_115 ) ;
memset ( V_65 , 0 , sizeof( struct V_12 ) ) ;
if ( V_1 -> V_115 <= V_114 )
V_111 = 0x00060001 ;
else
V_111 = 0x0006001e ;
V_65 -> V_15 . V_16 = V_117 ;
V_65 -> V_18 . V_51 .
V_118 . V_119 =
( V_111 & 0xFFFF0000 ) >> 16 ;
V_65 -> V_18 . V_51 .
V_118 . V_120 =
V_111 & 0xFFFF ;
V_48 = F_3 ( V_43 -> V_24 , V_65 ,
sizeof( struct V_12 ) ,
( unsigned long ) V_65 ,
V_25 , 0 ) ;
if ( V_48 != 0 )
goto V_71;
if ( V_1 -> V_115 <= V_113 )
V_1 -> V_69 = V_121 ;
else
V_1 -> V_69 = V_122 ;
V_1 -> V_84 = V_123 ;
V_48 = F_22 ( V_43 ) ;
V_71:
return V_48 ;
}
static void F_35 ( struct V_6 * V_43 )
{
F_17 ( V_43 ) ;
}
void F_36 ( struct V_6 * V_43 )
{
struct V_1 * V_2 = F_18 ( V_43 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_9 * V_1 = V_5 -> V_11 ;
F_35 ( V_43 ) ;
V_5 -> V_11 = NULL ;
F_37 ( & V_43 -> V_43 , L_18 ) ;
F_38 ( V_43 -> V_24 ) ;
F_12 ( V_1 -> V_124 ) ;
F_11 ( V_1 ) ;
}
static inline T_1 F_39 (
struct V_125 * V_126 )
{
T_1 V_127 , V_128 ;
F_40 ( V_126 , & V_127 , & V_128 ) ;
return V_128 * 100 / V_126 -> V_129 ;
}
static inline void F_41 ( struct V_9 * V_1 ,
T_1 V_130 )
{
F_42 ( V_130 , V_1 -> V_64 ) ;
}
static void F_43 ( struct V_9 * V_1 ,
struct V_131 * V_132 ,
struct V_6 * V_43 ,
struct V_133 * V_134 )
{
struct V_135 * V_136 = (struct V_135 * ) ( unsigned long ) V_134 -> V_137 ;
struct V_1 * V_2 = F_18 ( V_43 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_131 * V_24 = V_43 -> V_24 ;
int V_45 ;
T_2 V_138 = 0 ;
int V_139 ;
if ( F_44 ( V_136 ) ) {
struct V_140 * V_141
= (struct V_140 * ) V_136 -> V_142 ;
T_1 V_143 = V_141 -> V_144 ;
if ( V_143 != V_145 )
F_41 ( V_1 , V_143 ) ;
V_138 = V_141 -> V_138 ;
V_24 = V_132 ;
F_45 ( V_136 ) ;
}
V_45 =
F_46 ( & V_1 -> V_45 ) ;
V_139 = F_46 ( & V_1 -> V_139 [ V_138 ] ) ;
if ( V_1 -> V_34 && V_45 == 0 )
F_47 ( & V_1 -> V_33 ) ;
if ( F_48 ( F_49 ( V_2 , V_138 ) ) &&
! V_5 -> V_146 &&
( F_39 ( & V_24 -> V_147 ) > V_148 ||
V_139 < 1 ) )
F_50 ( F_49 ( V_2 , V_138 ) ) ;
}
static void F_51 ( struct V_9 * V_1 ,
struct V_131 * V_132 ,
struct V_6 * V_43 ,
struct V_133 * V_134 )
{
struct V_12 * V_149 ;
struct V_1 * V_2 = F_18 ( V_43 ) ;
V_149 = (struct V_12 * ) ( ( unsigned long ) V_134 +
( V_134 -> V_150 << 3 ) ) ;
switch ( V_149 -> V_15 . V_16 ) {
case V_151 :
case V_152 :
case V_153 :
case V_154 :
memcpy ( & V_1 -> V_14 , V_149 ,
sizeof( struct V_12 ) ) ;
F_52 ( & V_1 -> V_40 ) ;
break;
case V_155 :
F_43 ( V_1 , V_132 ,
V_43 , V_134 ) ;
break;
default:
F_20 ( V_2 ,
L_19 ,
V_149 -> V_15 . V_16 ) ;
}
}
static T_1 F_53 ( struct V_9 * V_1 )
{
unsigned long V_130 ;
T_1 V_156 = V_1 -> V_90 ;
unsigned long * V_157 = ( unsigned long * ) V_1 -> V_64 ;
T_1 V_158 = V_1 -> V_89 ;
int V_159 = V_145 ;
int V_41 ;
int V_160 ;
for ( V_41 = 0 ; V_41 < V_156 ; V_41 ++ ) {
if ( ! ~ ( V_157 [ V_41 ] ) )
continue;
V_130 = F_54 ( V_157 [ V_41 ] ) ;
V_160 = F_55 ( V_130 , & V_157 [ V_41 ] ) ;
if ( V_160 )
continue;
if ( ( V_130 + ( V_41 * V_91 ) ) >= V_158 )
break;
V_159 = ( V_130 + ( V_41 * V_91 ) ) ;
break;
}
return V_159 ;
}
static T_1 F_56 ( struct V_9 * V_1 ,
unsigned int V_161 ,
T_1 V_162 ,
struct V_140 * V_134 ,
struct V_163 * V_164 ,
struct V_165 * * V_166 ,
struct V_135 * V_136 )
{
char * V_167 = V_1 -> V_63 ;
char * V_168 = V_167 + ( V_161 * V_1 -> V_58 )
+ V_162 ;
int V_41 ;
bool V_169 = ( V_136 != NULL ) ? true : false ;
bool V_170 = ( V_136 != NULL ) ? V_136 -> V_170 : false ;
T_1 V_171 = 0 ;
T_1 V_172 = 0 ;
T_1 V_173 = V_134 -> V_174 % V_1 -> V_38 ;
T_1 V_175 = V_134 -> V_176 ? V_134 -> V_177 :
V_134 -> V_178 ;
if ( V_169 && V_170 && V_173 &&
! V_134 -> V_176 ) {
V_172 = V_1 -> V_38 - V_173 ;
V_164 -> V_179 += V_172 ;
V_134 -> V_174 += V_172 ;
}
for ( V_41 = 0 ; V_41 < V_175 ; V_41 ++ ) {
char * V_180 = F_57 ( ( * V_166 ) [ V_41 ] . V_181 << V_182 ) ;
T_1 V_83 = ( * V_166 ) [ V_41 ] . V_83 ;
T_1 V_183 = ( * V_166 ) [ V_41 ] . V_183 ;
memcpy ( V_168 , ( V_180 + V_83 ) , V_183 ) ;
V_171 += V_183 ;
V_168 += V_183 ;
}
if ( V_172 ) {
memset ( V_168 , 0 , V_172 ) ;
V_171 += V_172 ;
}
return V_171 ;
}
static inline int F_58 (
struct V_6 * V_43 ,
struct V_140 * V_134 ,
struct V_9 * V_1 ,
struct V_165 * * V_166 ,
struct V_135 * V_136 )
{
struct V_12 V_184 ;
T_2 V_138 = V_134 -> V_138 ;
struct V_131 * V_185 = V_1 -> V_186 [ V_138 ] ;
struct V_1 * V_2 = F_18 ( V_43 ) ;
T_3 V_187 ;
int V_48 ;
struct V_165 * V_188 ;
T_1 V_189 = F_39 ( & V_185 -> V_147 ) ;
bool V_170 = ( V_136 != NULL ) ? V_136 -> V_170 : false ;
V_184 . V_15 . V_16 = V_190 ;
if ( V_136 != NULL ) {
V_184 . V_18 . V_51 . V_191 . V_192 = 0 ;
} else {
V_184 . V_18 . V_51 . V_191 . V_192 = 1 ;
}
V_184 . V_18 . V_51 . V_191 . V_193 =
V_134 -> V_144 ;
if ( V_134 -> V_144 == V_145 )
V_184 . V_18 . V_51 . V_191 . V_194 = 0 ;
else
V_184 . V_18 . V_51 . V_191 . V_194 =
V_134 -> V_174 ;
V_187 = ( V_92 ) V_136 ;
if ( V_185 -> V_195 )
return - V_67 ;
if ( V_189 < ( V_196 + 1 ) )
V_170 = false ;
if ( V_134 -> V_178 ) {
V_188 = V_134 -> V_176 ? ( * V_166 ) +
V_134 -> V_177 : ( * V_166 ) ;
V_48 = F_59 ( V_185 ,
V_188 ,
V_134 -> V_178 ,
& V_184 ,
sizeof( struct V_12 ) ,
V_187 ,
V_75 ,
! V_170 ) ;
} else {
V_48 = F_60 ( V_185 , & V_184 ,
sizeof( struct V_12 ) ,
V_187 ,
V_25 ,
V_75 ,
! V_170 ) ;
}
if ( V_48 == 0 ) {
F_61 ( & V_1 -> V_45 ) ;
F_61 ( & V_1 -> V_139 [ V_138 ] ) ;
if ( V_189 < V_196 ) {
F_62 ( F_49 ( V_2 , V_138 ) ) ;
if ( F_16 ( & V_1 ->
V_139 [ V_138 ] ) < 1 )
F_50 ( F_49 (
V_2 , V_138 ) ) ;
}
} else if ( V_48 == - V_197 ) {
F_62 ( F_49 (
V_2 , V_138 ) ) ;
if ( F_16 ( & V_1 -> V_139 [ V_138 ] ) < 1 ) {
F_50 ( F_49 (
V_2 , V_138 ) ) ;
V_48 = - V_198 ;
}
} else {
F_20 ( V_2 , L_20 ,
V_134 , V_48 ) ;
}
return V_48 ;
}
static inline void F_63 ( struct V_140 * * V_199 ,
struct V_135 * * V_200 ,
struct V_201 * V_202 )
{
* V_200 = V_202 -> V_136 ;
* V_199 = V_202 -> V_203 ;
V_202 -> V_136 = NULL ;
V_202 -> V_203 = NULL ;
V_202 -> V_204 = 0 ;
}
int F_64 ( struct V_6 * V_43 ,
struct V_140 * V_134 ,
struct V_163 * V_164 ,
struct V_165 * * V_166 ,
struct V_135 * V_136 )
{
struct V_9 * V_1 ;
int V_48 = 0 ;
struct V_131 * V_185 ;
T_2 V_138 = V_134 -> V_138 ;
T_1 V_205 = V_134 -> V_174 , V_206 = 0 ;
unsigned int V_161 = V_145 ;
struct V_201 * V_202 ;
struct V_140 * V_199 = NULL , * V_207 = NULL ;
struct V_135 * V_200 = NULL ;
bool V_208 ;
bool V_170 = ( V_136 != NULL ) ? V_136 -> V_170 : false ;
V_1 = F_13 ( V_43 ) ;
if ( ! V_1 )
return - V_67 ;
V_185 = V_1 -> V_186 [ V_138 ] ;
V_134 -> V_144 = V_145 ;
V_134 -> V_176 = false ;
if ( ! V_136 ) {
V_207 = V_134 ;
goto V_209;
}
V_202 = & V_1 -> V_210 [ V_138 ] ;
if ( V_202 -> V_203 )
V_206 = V_202 -> V_203 -> V_174 ;
V_208 = ( V_136 != NULL ) && V_206 > 0 && V_202 -> V_204 <
V_1 -> V_36 ;
if ( V_208 && V_206 + V_205 + V_1 -> V_38 <
V_1 -> V_58 ) {
V_161 = V_202 -> V_203 -> V_144 ;
} else if ( V_208 && V_206 + V_134 -> V_211 <
V_1 -> V_58 ) {
V_161 = V_202 -> V_203 -> V_144 ;
V_134 -> V_176 = true ;
} else if ( ( V_136 != NULL ) && V_205 + V_1 -> V_38 <
V_1 -> V_58 ) {
V_161 = F_53 ( V_1 ) ;
if ( V_161 != V_145 ) {
F_63 ( & V_199 , & V_200 , V_202 ) ;
V_206 = 0 ;
}
}
if ( V_161 != V_145 ) {
F_56 ( V_1 ,
V_161 , V_206 ,
V_134 , V_164 , V_166 , V_136 ) ;
V_134 -> V_144 = V_161 ;
if ( V_134 -> V_176 ) {
V_134 -> V_178 -= V_134 -> V_177 ;
V_134 -> V_174 = V_206 + V_134 -> V_211 ;
} else {
V_134 -> V_178 = 0 ;
V_134 -> V_174 += V_206 ;
}
if ( V_202 -> V_136 )
F_45 ( V_202 -> V_136 ) ;
if ( V_170 && ! V_134 -> V_176 ) {
V_202 -> V_136 = V_136 ;
V_202 -> V_203 = V_134 ;
V_202 -> V_204 ++ ;
} else {
V_207 = V_134 ;
V_202 -> V_136 = NULL ;
V_202 -> V_203 = NULL ;
V_202 -> V_204 = 0 ;
}
} else {
F_63 ( & V_199 , & V_200 , V_202 ) ;
V_207 = V_134 ;
}
if ( V_199 ) {
int V_212 = F_58 ( V_43 , V_199 , V_1 ,
NULL , V_200 ) ;
if ( V_212 != 0 ) {
F_41 ( V_1 ,
V_199 -> V_144 ) ;
F_65 ( V_200 ) ;
}
}
V_209:
if ( V_207 )
V_48 = F_58 ( V_43 , V_207 , V_1 , V_166 , V_136 ) ;
if ( V_48 != 0 && V_161 != V_145 )
F_41 ( V_1 , V_161 ) ;
return V_48 ;
}
static int F_66 ( struct V_131 * V_24 ,
T_3 V_213 , T_1 V_77 )
{
struct V_12 V_214 ;
int V_48 ;
V_214 . V_15 . V_16 =
V_155 ;
V_214 . V_18 . V_51 . V_215 . V_77 = V_77 ;
V_48 = F_3 ( V_24 , & V_214 ,
sizeof( struct V_216 ) + sizeof( T_1 ) ,
V_213 , V_217 , 0 ) ;
return V_48 ;
}
static inline void F_67 ( struct V_9 * V_11 , T_2 V_138 ,
T_1 * V_218 , T_1 * V_219 )
{
T_1 V_220 = V_11 -> V_29 [ V_138 ] . V_220 ;
T_1 V_221 = V_11 -> V_29 [ V_138 ] . V_221 ;
* V_218 = ( V_220 > V_221 ) ? V_31 - V_220 + V_221 :
V_221 - V_220 ;
* V_219 = V_31 - * V_218 - 1 ;
}
static inline struct V_32 * F_68 ( struct V_9
* V_11 , T_2 V_138 )
{
T_1 V_218 , V_219 ;
if ( ! V_11 -> V_29 [ V_138 ] . V_30 )
return NULL ;
F_67 ( V_11 , V_138 , & V_218 , & V_219 ) ;
if ( ! V_218 )
return NULL ;
return V_11 -> V_29 [ V_138 ] . V_30 + V_11 -> V_29 [ V_138 ] . V_220 *
sizeof( struct V_32 ) ;
}
static inline void F_69 ( struct V_9 * V_11 , T_2 V_138 )
{
int V_222 ;
V_11 -> V_29 [ V_138 ] . V_220 = ( V_11 -> V_29 [ V_138 ] . V_220 + 1 ) %
V_31 ;
V_222 = F_46 ( & V_11 -> V_46 ) ;
if ( V_11 -> V_34 && V_222 == 0 )
F_47 ( & V_11 -> V_33 ) ;
}
static void F_70 ( struct V_9 * V_11 ,
struct V_131 * V_24 , T_2 V_138 )
{
struct V_32 * V_223 ;
int V_48 ;
while ( true ) {
V_223 = F_68 ( V_11 , V_138 ) ;
if ( ! V_223 )
break;
V_48 = F_66 ( V_24 , V_223 -> V_224 ,
V_223 -> V_77 ) ;
if ( V_48 )
break;
F_69 ( V_11 , V_138 ) ;
}
}
static inline struct V_32 * F_71 (
struct V_9 * V_11 , struct V_131 * V_24 , T_2 V_138 )
{
T_1 V_218 , V_219 , V_221 ;
struct V_32 * V_223 ;
if ( ! V_11 -> V_57 )
return NULL ;
if ( ! V_11 -> V_29 [ V_138 ] . V_30 )
return NULL ;
if ( F_16 ( & V_11 -> V_46 ) >
V_11 -> V_57 -> V_225 * V_226 / 100 )
F_70 ( V_11 , V_24 , V_138 ) ;
F_67 ( V_11 , V_138 , & V_218 , & V_219 ) ;
if ( ! V_219 )
return NULL ;
V_221 = V_11 -> V_29 [ V_138 ] . V_221 ;
V_223 = V_11 -> V_29 [ V_138 ] . V_30 + V_221 * sizeof( struct V_32 ) ;
V_11 -> V_29 [ V_138 ] . V_221 = ( V_221 + 1 ) % V_31 ;
F_61 ( & V_11 -> V_46 ) ;
return V_223 ;
}
static void F_72 ( struct V_9 * V_1 ,
struct V_131 * V_24 ,
struct V_6 * V_43 ,
struct V_133 * V_134 )
{
struct V_227 * V_228 ;
struct V_12 * V_149 ;
struct V_140 V_229 ;
struct V_140 * V_230 = & V_229 ;
T_1 V_77 = V_78 ;
int V_41 ;
int V_204 = 0 ;
struct V_1 * V_2 = F_18 ( V_43 ) ;
void * V_231 ;
int V_48 ;
struct V_32 * V_223 ;
T_2 V_138 = V_24 -> V_232 . V_233 . V_234 ;
if ( V_134 -> type != V_235 ) {
F_20 ( V_2 , L_21 ,
V_134 -> type ) ;
return;
}
V_149 = (struct V_12 * ) ( ( unsigned long ) V_134 +
( V_134 -> V_150 << 3 ) ) ;
if ( V_149 -> V_15 . V_16 !=
V_190 ) {
F_20 ( V_2 , L_22
L_23 , V_149 -> V_15 . V_16 ) ;
return;
}
V_228 = (struct V_227 * ) V_134 ;
if ( V_228 -> V_236 != V_54 ) {
F_20 ( V_2 , L_24
L_25 , V_54 ,
V_228 -> V_236 ) ;
return;
}
V_204 = V_228 -> V_237 ;
for ( V_41 = 0 ; V_41 < V_204 ; V_41 ++ ) {
V_231 = ( void * ) ( ( unsigned long ) V_1 ->
V_56 + V_228 -> V_238 [ V_41 ] . V_239 ) ;
V_230 -> V_174 =
V_228 -> V_238 [ V_41 ] . V_240 ;
V_77 = F_73 ( V_43 , V_230 , & V_231 ,
V_24 ) ;
}
if ( ! V_1 -> V_29 [ V_138 ] . V_30 ) {
V_48 = F_66 ( V_24 ,
V_228 -> V_241 . V_137 ,
V_77 ) ;
if ( V_48 )
F_20 ( V_2 , L_26 ,
V_138 , V_228 -> V_241 . V_137 , V_48 ) ;
return;
}
V_223 = F_71 ( V_1 , V_24 , V_138 ) ;
if ( ! V_223 ) {
F_20 ( V_2 , L_27 ,
V_138 , V_228 -> V_241 . V_137 ) ;
return;
}
V_223 -> V_224 = V_228 -> V_241 . V_137 ;
V_223 -> V_77 = V_77 ;
}
static void F_74 ( struct V_6 * V_242 ,
struct V_12 * V_184 )
{
struct V_9 * V_243 ;
struct V_1 * V_2 = F_18 ( V_242 ) ;
int V_41 ;
T_1 V_204 , * V_244 ;
V_243 = F_13 ( V_242 ) ;
if ( ! V_243 )
return;
V_204 = V_184 -> V_18 . V_245 . V_246 . V_204 ;
if ( V_204 != V_247 ) {
F_20 ( V_2 , L_28 , V_204 ) ;
return;
}
V_244 = ( T_1 * ) ( ( unsigned long ) & V_184 -> V_18 . V_245 . V_246 +
V_184 -> V_18 . V_245 . V_246 . V_83 ) ;
for ( V_41 = 0 ; V_41 < V_204 ; V_41 ++ )
V_243 -> V_246 [ V_41 ] = V_244 [ V_41 ] ;
}
static void F_75 ( struct V_4 * V_5 ,
struct V_12 * V_184 )
{
V_5 -> V_248 = V_184 -> V_18 . V_19 . V_249 . V_250 ;
V_5 -> V_251 = V_184 -> V_18 . V_19 . V_249 . V_252 ;
}
static inline void F_76 ( struct V_6 * V_242 ,
struct V_4 * V_5 ,
struct V_12 * V_184 )
{
switch ( V_184 -> V_15 . V_16 ) {
case V_253 :
F_74 ( V_242 , V_184 ) ;
break;
case V_254 :
F_75 ( V_5 , V_184 ) ;
break;
}
}
static void F_77 ( struct V_6 * V_43 ,
struct V_131 * V_24 ,
struct V_9 * V_1 ,
struct V_1 * V_2 ,
T_3 V_255 ,
struct V_133 * V_256 )
{
struct V_12 * V_184 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
V_184 = (struct V_12 * ) ( ( unsigned long )
V_256 + ( V_256 -> V_150 << 3 ) ) ;
switch ( V_256 -> type ) {
case V_217 :
F_51 ( V_1 , V_24 , V_43 , V_256 ) ;
break;
case V_235 :
F_72 ( V_1 , V_24 , V_43 , V_256 ) ;
break;
case V_25 :
F_76 ( V_43 , V_5 , V_184 ) ;
break;
default:
F_20 ( V_2 , L_29 ,
V_256 -> type , V_255 ) ;
break;
}
}
void F_78 ( void * V_257 )
{
int V_48 ;
struct V_131 * V_24 = (struct V_131 * ) V_257 ;
T_2 V_138 = V_24 -> V_232 . V_233 . V_234 ;
struct V_6 * V_43 ;
struct V_9 * V_1 ;
T_1 V_258 ;
T_3 V_255 ;
struct V_133 * V_256 ;
unsigned char * V_259 ;
int V_260 = V_28 ;
struct V_1 * V_2 ;
bool V_261 = false ;
if ( V_24 -> V_262 != NULL )
V_43 = V_24 -> V_262 -> V_263 ;
else
V_43 = V_24 -> V_263 ;
V_1 = F_15 ( V_43 ) ;
if ( ! V_1 )
return;
V_2 = F_18 ( V_43 ) ;
V_259 = F_79 ( V_24 ) ;
do {
V_256 = F_80 ( V_24 ) ;
if ( V_256 != NULL ) {
F_77 ( V_43 ,
V_24 ,
V_1 ,
V_2 ,
V_256 -> V_137 ,
V_256 ) ;
F_81 ( V_24 , V_256 ) ;
V_261 = true ;
continue;
}
if ( V_261 ) {
V_261 = false ;
F_82 ( V_24 ) ;
}
V_48 = F_83 ( V_24 , V_259 , V_260 ,
& V_258 , & V_255 ) ;
if ( V_48 == 0 ) {
if ( V_258 > 0 ) {
V_256 = (struct V_133 * ) V_259 ;
F_77 ( V_43 ,
V_24 ,
V_1 ,
V_2 ,
V_255 ,
V_256 ) ;
} else {
break;
}
} else if ( V_48 == - V_264 ) {
if ( V_260 > V_28 )
F_6 ( V_259 ) ;
V_259 = F_84 ( V_258 , V_265 ) ;
if ( V_259 == NULL ) {
F_20 ( V_2 ,
L_30
L_31 , V_258 ) ;
break;
}
V_260 = V_258 ;
}
} while ( 1 );
if ( V_260 > V_28 )
F_6 ( V_259 ) ;
F_70 ( V_1 , V_24 , V_138 ) ;
}
int F_85 ( struct V_6 * V_43 , void * V_266 )
{
int V_41 , V_48 = 0 ;
int V_267 =
( (struct V_268 * ) V_266 ) -> V_267 ;
struct V_9 * V_1 ;
struct V_1 * V_2 = F_18 ( V_43 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
V_1 = F_4 () ;
if ( ! V_1 )
return - V_70 ;
V_1 -> V_267 = V_267 ;
F_86 ( V_43 -> V_24 , V_1 -> V_27 ) ;
V_48 = F_87 ( V_43 -> V_24 , V_267 * V_269 ,
V_267 * V_269 , NULL , 0 ,
F_78 , V_43 -> V_24 ) ;
if ( V_48 != 0 ) {
F_20 ( V_2 , L_32 , V_48 ) ;
goto V_71;
}
F_88 ( L_33 ) ;
for ( V_41 = 0 ; V_41 < V_42 ; V_41 ++ )
V_1 -> V_186 [ V_41 ] = V_43 -> V_24 ;
F_89 () ;
V_5 -> V_11 = V_1 ;
V_48 = F_32 ( V_43 ) ;
if ( V_48 != 0 ) {
F_20 ( V_2 ,
L_34 , V_48 ) ;
goto V_270;
}
return V_48 ;
V_270:
F_38 ( V_43 -> V_24 ) ;
V_71:
F_11 ( V_1 ) ;
return V_48 ;
}
