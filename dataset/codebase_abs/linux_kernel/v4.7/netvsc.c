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
F_8 ( & V_1 -> V_32 , 0 ) ;
V_1 -> V_33 = V_34 ;
V_1 -> V_35 = V_36 ;
V_1 -> V_37 = NULL ;
V_1 -> V_38 = false ;
return V_1 ;
}
static void F_9 ( struct V_9 * V_11 )
{
F_6 ( V_11 -> V_27 ) ;
F_6 ( V_11 ) ;
}
static struct V_9 * F_10 ( struct V_6 * V_39 )
{
struct V_1 * V_2 = F_11 ( V_39 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_9 * V_1 = V_5 -> V_11 ;
if ( V_1 && V_1 -> V_30 )
V_1 = NULL ;
return V_1 ;
}
static struct V_9 * F_12 ( struct V_6 * V_39 )
{
struct V_1 * V_2 = F_11 ( V_39 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_9 * V_1 = V_5 -> V_11 ;
if ( ! V_1 )
goto V_40;
if ( V_1 -> V_30 &&
F_13 ( & V_1 -> V_41 ) == 0 )
V_1 = NULL ;
V_40:
return V_1 ;
}
static int F_14 ( struct V_6 * V_39 )
{
struct V_12 * V_42 ;
int V_43 = 0 ;
struct V_1 * V_2 = F_11 ( V_39 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_9 * V_1 = V_5 -> V_11 ;
if ( V_1 -> V_44 ) {
V_42 = & V_1 -> V_42 ;
memset ( V_42 , 0 , sizeof( struct V_12 ) ) ;
V_42 -> V_15 . V_16 =
V_45 ;
V_42 -> V_18 . V_46 .
V_47 . V_48 = V_49 ;
V_43 = F_3 ( V_39 -> V_24 ,
V_42 ,
sizeof( struct V_12 ) ,
( unsigned long ) V_42 ,
V_25 , 0 ) ;
if ( V_43 != 0 ) {
F_15 ( V_2 , L_1
L_2 ) ;
return V_43 ;
}
}
if ( V_1 -> V_50 ) {
V_43 = F_16 ( V_39 -> V_24 ,
V_1 -> V_50 ) ;
if ( V_43 != 0 ) {
F_15 ( V_2 ,
L_3 ) ;
return V_43 ;
}
V_1 -> V_50 = 0 ;
}
if ( V_1 -> V_51 ) {
F_17 ( V_1 -> V_51 ) ;
V_1 -> V_51 = NULL ;
}
if ( V_1 -> V_52 ) {
V_1 -> V_44 = 0 ;
F_6 ( V_1 -> V_52 ) ;
V_1 -> V_52 = NULL ;
}
if ( V_1 -> V_53 ) {
V_42 = & V_1 -> V_42 ;
memset ( V_42 , 0 , sizeof( struct V_12 ) ) ;
V_42 -> V_15 . V_16 =
V_54 ;
V_42 -> V_18 . V_46 . V_55 . V_48 =
V_56 ;
V_43 = F_3 ( V_39 -> V_24 ,
V_42 ,
sizeof( struct V_12 ) ,
( unsigned long ) V_42 ,
V_25 , 0 ) ;
if ( V_43 != 0 ) {
F_15 ( V_2 , L_1
L_4 ) ;
return V_43 ;
}
}
if ( V_1 -> V_57 ) {
V_43 = F_16 ( V_39 -> V_24 ,
V_1 -> V_57 ) ;
if ( V_43 != 0 ) {
F_15 ( V_2 ,
L_5 ) ;
return V_43 ;
}
V_1 -> V_57 = 0 ;
}
if ( V_1 -> V_58 ) {
F_17 ( V_1 -> V_58 ) ;
V_1 -> V_58 = NULL ;
}
F_6 ( V_1 -> V_59 ) ;
return V_43 ;
}
static int F_18 ( struct V_6 * V_39 )
{
int V_43 = 0 ;
unsigned long V_60 ;
struct V_9 * V_1 ;
struct V_12 * V_61 ;
struct V_1 * V_2 ;
int V_62 ;
V_1 = F_10 ( V_39 ) ;
if ( ! V_1 )
return - V_63 ;
V_2 = F_11 ( V_39 ) ;
V_62 = F_19 ( V_39 -> V_24 -> V_64 ) ;
V_1 -> V_51 = F_20 ( V_1 -> V_65 , V_62 ) ;
if ( ! V_1 -> V_51 )
V_1 -> V_51 = F_21 ( V_1 -> V_65 ) ;
if ( ! V_1 -> V_51 ) {
F_15 ( V_2 , L_6
L_7 , V_1 -> V_65 ) ;
V_43 = - V_66 ;
goto V_67;
}
V_43 = F_22 ( V_39 -> V_24 , V_1 -> V_51 ,
V_1 -> V_65 ,
& V_1 -> V_50 ) ;
if ( V_43 != 0 ) {
F_15 ( V_2 ,
L_8 ) ;
goto V_67;
}
V_61 = & V_1 -> V_14 ;
memset ( V_61 , 0 , sizeof( struct V_12 ) ) ;
V_61 -> V_15 . V_16 = V_68 ;
V_61 -> V_18 . V_46 . V_69 .
V_70 = V_1 -> V_50 ;
V_61 -> V_18 . V_46 .
V_69 . V_48 = V_49 ;
V_43 = F_3 ( V_39 -> V_24 , V_61 ,
sizeof( struct V_12 ) ,
( unsigned long ) V_61 ,
V_25 ,
V_71 ) ;
if ( V_43 != 0 ) {
F_15 ( V_2 ,
L_9 ) ;
goto V_67;
}
V_60 = F_23 ( & V_1 -> V_72 , 5 * V_73 ) ;
F_24 ( V_60 == 0 ) ;
if ( V_61 -> V_18 . V_46 .
V_74 . V_75 != V_76 ) {
F_15 ( V_2 , L_10
L_11 ,
V_61 -> V_18 . V_46 .
V_74 . V_75 ) ;
V_43 = - V_77 ;
goto V_67;
}
V_1 -> V_44 = V_61 -> V_18 .
V_46 . V_74 . V_78 ;
V_1 -> V_52 = F_25 (
V_61 -> V_18 . V_46 . V_74 . V_79 ,
V_1 -> V_44 *
sizeof( struct V_80 ) ,
V_26 ) ;
if ( V_1 -> V_52 == NULL ) {
V_43 = - V_77 ;
goto V_67;
}
if ( V_1 -> V_44 != 1 ||
V_1 -> V_52 -> V_81 != 0 ) {
V_43 = - V_77 ;
goto V_67;
}
V_1 -> V_58 = F_20 ( V_1 -> V_82 , V_62 ) ;
if ( ! V_1 -> V_58 )
V_1 -> V_58 = F_21 ( V_1 -> V_82 ) ;
if ( ! V_1 -> V_58 ) {
F_15 ( V_2 , L_12
L_7 , V_1 -> V_82 ) ;
V_43 = - V_66 ;
goto V_67;
}
V_43 = F_22 ( V_39 -> V_24 , V_1 -> V_58 ,
V_1 -> V_82 ,
& V_1 -> V_57 ) ;
if ( V_43 != 0 ) {
F_15 ( V_2 ,
L_13 ) ;
goto V_67;
}
V_61 = & V_1 -> V_14 ;
memset ( V_61 , 0 , sizeof( struct V_12 ) ) ;
V_61 -> V_15 . V_16 = V_83 ;
V_61 -> V_18 . V_46 . V_84 . V_70 =
V_1 -> V_57 ;
V_61 -> V_18 . V_46 . V_84 . V_48 = V_56 ;
V_43 = F_3 ( V_39 -> V_24 , V_61 ,
sizeof( struct V_12 ) ,
( unsigned long ) V_61 ,
V_25 ,
V_71 ) ;
if ( V_43 != 0 ) {
F_15 ( V_2 ,
L_14 ) ;
goto V_67;
}
V_60 = F_23 ( & V_1 -> V_72 , 5 * V_73 ) ;
F_24 ( V_60 == 0 ) ;
if ( V_61 -> V_18 . V_46 .
V_85 . V_75 != V_76 ) {
F_15 ( V_2 , L_15
L_11 ,
V_61 -> V_18 . V_46 .
V_85 . V_75 ) ;
V_43 = - V_77 ;
goto V_67;
}
V_1 -> V_53 = V_61 -> V_18 .
V_46 . V_85 . V_86 ;
V_1 -> V_87 =
V_1 -> V_82 / V_1 -> V_53 ;
F_26 ( & V_39 -> V_39 , L_16 ,
V_1 -> V_53 , V_1 -> V_87 ) ;
V_1 -> V_88 = F_27 ( V_1 -> V_87 ,
V_89 ) ;
V_1 -> V_59 =
F_5 ( V_1 -> V_88 * sizeof( V_90 ) , V_26 ) ;
if ( V_1 -> V_59 == NULL ) {
V_43 = - V_66 ;
goto V_67;
}
goto exit;
V_67:
F_14 ( V_39 ) ;
exit:
return V_43 ;
}
static int F_28 ( struct V_6 * V_39 ,
struct V_9 * V_1 ,
struct V_12 * V_61 ,
T_1 V_91 )
{
struct V_1 * V_2 = F_11 ( V_39 ) ;
int V_43 ;
unsigned long V_60 ;
memset ( V_61 , 0 , sizeof( struct V_12 ) ) ;
V_61 -> V_15 . V_16 = V_92 ;
V_61 -> V_18 . V_93 . V_94 . V_95 = V_91 ;
V_61 -> V_18 . V_93 . V_94 . V_96 = V_91 ;
V_43 = F_3 ( V_39 -> V_24 , V_61 ,
sizeof( struct V_12 ) ,
( unsigned long ) V_61 ,
V_25 ,
V_71 ) ;
if ( V_43 != 0 )
return V_43 ;
V_60 = F_23 ( & V_1 -> V_72 , 5 * V_73 ) ;
if ( V_60 == 0 )
return - V_97 ;
if ( V_61 -> V_18 . V_93 . V_98 . V_75 !=
V_76 )
return - V_77 ;
if ( V_91 == V_99 )
return 0 ;
memset ( V_61 , 0 , sizeof( struct V_12 ) ) ;
V_61 -> V_15 . V_16 = V_100 ;
V_61 -> V_18 . V_101 . V_102 . V_103 = V_2 -> V_103 + V_104 ;
V_61 -> V_18 . V_101 . V_102 . V_105 . V_106 = 1 ;
if ( V_91 >= V_107 )
V_61 -> V_18 . V_101 . V_102 . V_105 . V_108 = 1 ;
V_43 = F_3 ( V_39 -> V_24 , V_61 ,
sizeof( struct V_12 ) ,
( unsigned long ) V_61 ,
V_25 , 0 ) ;
return V_43 ;
}
static int F_29 ( struct V_6 * V_39 )
{
int V_43 ;
struct V_9 * V_1 ;
struct V_12 * V_61 ;
int V_109 ;
T_1 V_110 [] = { V_99 , V_111 ,
V_112 , V_107 } ;
int V_113 , V_114 = 4 ;
V_1 = F_10 ( V_39 ) ;
if ( ! V_1 )
return - V_63 ;
V_61 = & V_1 -> V_14 ;
for ( V_113 = V_114 - 1 ; V_113 >= 0 ; V_113 -- )
if ( F_28 ( V_39 , V_1 , V_61 ,
V_110 [ V_113 ] ) == 0 ) {
V_1 -> V_115 = V_110 [ V_113 ] ;
break;
}
if ( V_113 < 0 ) {
V_43 = - V_116 ;
goto V_67;
}
F_30 ( L_17 , V_1 -> V_115 ) ;
memset ( V_61 , 0 , sizeof( struct V_12 ) ) ;
if ( V_1 -> V_115 <= V_112 )
V_109 = 0x00060001 ;
else
V_109 = 0x0006001e ;
V_61 -> V_15 . V_16 = V_117 ;
V_61 -> V_18 . V_46 .
V_118 . V_119 =
( V_109 & 0xFFFF0000 ) >> 16 ;
V_61 -> V_18 . V_46 .
V_118 . V_120 =
V_109 & 0xFFFF ;
V_43 = F_3 ( V_39 -> V_24 , V_61 ,
sizeof( struct V_12 ) ,
( unsigned long ) V_61 ,
V_25 , 0 ) ;
if ( V_43 != 0 )
goto V_67;
if ( V_1 -> V_115 <= V_111 )
V_1 -> V_65 = V_121 ;
else
V_1 -> V_65 = V_122 ;
V_1 -> V_82 = V_123 ;
V_43 = F_18 ( V_39 ) ;
V_67:
return V_43 ;
}
static void F_31 ( struct V_6 * V_39 )
{
F_14 ( V_39 ) ;
}
int F_32 ( struct V_6 * V_39 )
{
struct V_1 * V_2 = F_11 ( V_39 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_9 * V_1 = V_5 -> V_11 ;
F_31 ( V_39 ) ;
V_5 -> V_11 = NULL ;
F_33 ( & V_39 -> V_39 , L_18 ) ;
F_34 ( V_39 -> V_24 ) ;
F_17 ( V_1 -> V_124 ) ;
F_9 ( V_1 ) ;
return 0 ;
}
static inline T_1 F_35 (
struct V_125 * V_126 )
{
T_1 V_127 , V_128 ;
F_36 ( V_126 , & V_127 , & V_128 ) ;
return V_128 * 100 / V_126 -> V_129 ;
}
static inline void F_37 ( struct V_9 * V_1 ,
T_1 V_130 )
{
F_38 ( V_130 , V_1 -> V_59 ) ;
}
static void F_39 ( struct V_9 * V_1 ,
struct V_131 * V_132 ,
struct V_6 * V_39 ,
struct V_133 * V_134 )
{
struct V_12 * V_135 ;
struct V_136 * V_137 ;
struct V_1 * V_2 = F_11 ( V_39 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_1 V_138 ;
struct V_139 * V_140 ;
V_135 = (struct V_12 * ) ( ( unsigned long ) V_134 +
( V_134 -> V_141 << 3 ) ) ;
if ( ( V_135 -> V_15 . V_16 == V_142 ) ||
( V_135 -> V_15 . V_16 ==
V_143 ) ||
( V_135 -> V_15 . V_16 ==
V_144 ) ||
( V_135 -> V_15 . V_16 ==
V_145 ) ) {
memcpy ( & V_1 -> V_14 , V_135 ,
sizeof( struct V_12 ) ) ;
F_40 ( & V_1 -> V_72 ) ;
} else if ( V_135 -> V_15 . V_16 ==
V_146 ) {
int V_41 ;
T_2 V_147 = 0 ;
struct V_131 * V_24 = V_39 -> V_24 ;
int V_148 ;
V_140 = (struct V_139 * ) ( unsigned long ) V_134 -> V_149 ;
if ( V_140 ) {
V_137 = (struct V_136 * ) V_140 -> V_150 ;
V_138 = V_137 -> V_151 ;
if ( V_138 != V_152 )
F_37 ( V_1 , V_138 ) ;
V_147 = V_137 -> V_147 ;
V_24 = V_132 ;
F_41 ( V_140 ) ;
}
V_41 =
F_42 ( & V_1 -> V_41 ) ;
V_148 = F_42 ( & V_1 ->
V_148 [ V_147 ] ) ;
if ( V_1 -> V_30 && V_41 == 0 )
F_43 ( & V_1 -> V_29 ) ;
if ( F_44 ( F_45 ( V_2 , V_147 ) ) &&
! V_5 -> V_153 &&
( F_35 ( & V_24 -> V_154 ) >
V_155 || V_148 < 1 ) )
F_46 ( F_45 (
V_2 , V_147 ) ) ;
} else {
F_15 ( V_2 , L_19
L_20 , V_135 -> V_15 . V_16 ) ;
}
}
static T_1 F_47 ( struct V_9 * V_1 )
{
unsigned long V_130 ;
T_1 V_156 = V_1 -> V_88 ;
unsigned long * V_157 = ( unsigned long * ) V_1 -> V_59 ;
T_1 V_158 = V_1 -> V_87 ;
int V_159 = V_152 ;
int V_113 ;
int V_160 ;
for ( V_113 = 0 ; V_113 < V_156 ; V_113 ++ ) {
if ( ! ~ ( V_157 [ V_113 ] ) )
continue;
V_130 = F_48 ( V_157 [ V_113 ] ) ;
V_160 = F_49 ( V_130 , & V_157 [ V_113 ] ) ;
if ( V_160 )
continue;
if ( ( V_130 + ( V_113 * V_89 ) ) >= V_158 )
break;
V_159 = ( V_130 + ( V_113 * V_89 ) ) ;
break;
}
return V_159 ;
}
static T_1 F_50 ( struct V_9 * V_1 ,
unsigned int V_161 ,
T_1 V_162 ,
struct V_136 * V_134 ,
struct V_163 * V_164 ,
struct V_165 * * V_166 ,
struct V_139 * V_140 )
{
char * V_167 = V_1 -> V_58 ;
char * V_168 = V_167 + ( V_161 * V_1 -> V_53 )
+ V_162 ;
int V_113 ;
bool V_169 = ( V_140 != NULL ) ? true : false ;
bool V_170 = ( V_140 != NULL ) ? V_140 -> V_170 : false ;
T_1 V_171 = 0 ;
T_1 V_172 = 0 ;
T_1 V_173 = V_134 -> V_174 % V_1 -> V_35 ;
T_1 V_175 = V_134 -> V_176 ? V_134 -> V_177 :
V_134 -> V_178 ;
if ( V_169 && V_170 && V_173 &&
! V_134 -> V_176 ) {
V_172 = V_1 -> V_35 - V_173 ;
V_164 -> V_179 += V_172 ;
V_134 -> V_174 += V_172 ;
}
for ( V_113 = 0 ; V_113 < V_175 ; V_113 ++ ) {
char * V_180 = F_51 ( ( * V_166 ) [ V_113 ] . V_181 << V_182 ) ;
T_1 V_81 = ( * V_166 ) [ V_113 ] . V_81 ;
T_1 V_183 = ( * V_166 ) [ V_113 ] . V_183 ;
memcpy ( V_168 , ( V_180 + V_81 ) , V_183 ) ;
V_171 += V_183 ;
V_168 += V_183 ;
}
if ( V_172 ) {
memset ( V_168 , 0 , V_172 ) ;
V_171 += V_172 ;
}
return V_171 ;
}
static inline int F_52 (
struct V_6 * V_39 ,
struct V_136 * V_134 ,
struct V_9 * V_1 ,
struct V_165 * * V_166 ,
struct V_139 * V_140 )
{
struct V_12 V_184 ;
T_2 V_147 = V_134 -> V_147 ;
struct V_131 * V_185 = V_1 -> V_186 [ V_147 ] ;
struct V_1 * V_2 = F_11 ( V_39 ) ;
T_3 V_187 ;
int V_43 ;
struct V_165 * V_188 ;
T_1 V_189 = F_35 ( & V_185 -> V_154 ) ;
bool V_170 = ( V_140 != NULL ) ? V_140 -> V_170 : false ;
V_184 . V_15 . V_16 = V_190 ;
if ( V_140 != NULL ) {
V_184 . V_18 . V_46 . V_191 . V_192 = 0 ;
} else {
V_184 . V_18 . V_46 . V_191 . V_192 = 1 ;
}
V_184 . V_18 . V_46 . V_191 . V_193 =
V_134 -> V_151 ;
if ( V_134 -> V_151 == V_152 )
V_184 . V_18 . V_46 . V_191 . V_194 = 0 ;
else
V_184 . V_18 . V_46 . V_191 . V_194 =
V_134 -> V_174 ;
V_187 = ( V_90 ) V_140 ;
if ( V_185 -> V_195 )
return - V_63 ;
if ( V_189 < ( V_196 + 1 ) )
V_170 = false ;
if ( V_134 -> V_178 ) {
V_188 = V_134 -> V_176 ? ( * V_166 ) +
V_134 -> V_177 : ( * V_166 ) ;
V_43 = F_53 ( V_185 ,
V_188 ,
V_134 -> V_178 ,
& V_184 ,
sizeof( struct V_12 ) ,
V_187 ,
V_71 ,
! V_170 ) ;
} else {
V_43 = F_54 ( V_185 , & V_184 ,
sizeof( struct V_12 ) ,
V_187 ,
V_25 ,
V_71 ,
! V_170 ) ;
}
if ( V_43 == 0 ) {
F_55 ( & V_1 -> V_41 ) ;
F_55 ( & V_1 -> V_148 [ V_147 ] ) ;
if ( V_189 < V_196 ) {
F_56 ( F_45 ( V_2 , V_147 ) ) ;
if ( F_13 ( & V_1 ->
V_148 [ V_147 ] ) < 1 )
F_46 ( F_45 (
V_2 , V_147 ) ) ;
}
} else if ( V_43 == - V_197 ) {
F_56 ( F_45 (
V_2 , V_147 ) ) ;
if ( F_13 ( & V_1 -> V_148 [ V_147 ] ) < 1 ) {
F_46 ( F_45 (
V_2 , V_147 ) ) ;
V_43 = - V_198 ;
}
} else {
F_15 ( V_2 , L_21 ,
V_134 , V_43 ) ;
}
return V_43 ;
}
static inline void F_57 ( struct V_136 * * V_199 ,
struct V_139 * * V_200 ,
struct V_201 * V_202 )
{
* V_200 = V_202 -> V_140 ;
* V_199 = V_202 -> V_203 ;
V_202 -> V_140 = NULL ;
V_202 -> V_203 = NULL ;
V_202 -> V_204 = 0 ;
}
int F_58 ( struct V_6 * V_39 ,
struct V_136 * V_134 ,
struct V_163 * V_164 ,
struct V_165 * * V_166 ,
struct V_139 * V_140 )
{
struct V_9 * V_1 ;
int V_43 = 0 , V_205 = 0 ;
struct V_131 * V_185 ;
T_2 V_147 = V_134 -> V_147 ;
T_1 V_206 = V_134 -> V_174 , V_207 = 0 ;
unsigned int V_161 = V_152 ;
struct V_201 * V_202 ;
struct V_136 * V_199 = NULL , * V_208 = NULL ;
struct V_139 * V_200 = NULL ;
bool V_209 ;
bool V_170 = ( V_140 != NULL ) ? V_140 -> V_170 : false ;
V_1 = F_10 ( V_39 ) ;
if ( ! V_1 )
return - V_63 ;
V_185 = V_1 -> V_186 [ V_147 ] ;
V_134 -> V_151 = V_152 ;
V_134 -> V_176 = false ;
if ( ! V_140 ) {
V_208 = V_134 ;
goto V_210;
}
V_202 = & V_1 -> V_211 [ V_147 ] ;
if ( V_202 -> V_203 )
V_207 = V_202 -> V_203 -> V_174 ;
V_209 = ( V_140 != NULL ) && V_207 > 0 && V_202 -> V_204 <
V_1 -> V_33 ;
if ( V_209 && V_207 + V_206 + V_1 -> V_35 <
V_1 -> V_53 ) {
V_161 = V_202 -> V_203 -> V_151 ;
} else if ( V_209 && V_207 + V_134 -> V_212 <
V_1 -> V_53 ) {
V_161 = V_202 -> V_203 -> V_151 ;
V_134 -> V_176 = true ;
} else if ( ( V_140 != NULL ) && V_206 + V_1 -> V_35 <
V_1 -> V_53 ) {
V_161 = F_47 ( V_1 ) ;
if ( V_161 != V_152 ) {
F_57 ( & V_199 , & V_200 , V_202 ) ;
V_207 = 0 ;
}
}
if ( V_161 != V_152 ) {
F_50 ( V_1 ,
V_161 , V_207 ,
V_134 , V_164 , V_166 , V_140 ) ;
V_134 -> V_151 = V_161 ;
if ( V_134 -> V_176 ) {
V_134 -> V_178 -= V_134 -> V_177 ;
V_134 -> V_174 = V_207 + V_134 -> V_212 ;
} else {
V_134 -> V_178 = 0 ;
V_134 -> V_174 += V_207 ;
}
if ( V_202 -> V_140 )
F_41 ( V_202 -> V_140 ) ;
if ( V_170 && ! V_134 -> V_176 ) {
V_202 -> V_140 = V_140 ;
V_202 -> V_203 = V_134 ;
V_202 -> V_204 ++ ;
} else {
V_208 = V_134 ;
V_202 -> V_140 = NULL ;
V_202 -> V_203 = NULL ;
V_202 -> V_204 = 0 ;
}
} else {
F_57 ( & V_199 , & V_200 , V_202 ) ;
V_208 = V_134 ;
}
if ( V_199 ) {
V_205 = F_52 ( V_39 , V_199 , V_1 ,
NULL , V_200 ) ;
if ( V_205 != 0 ) {
F_37 ( V_1 ,
V_199 -> V_151 ) ;
F_41 ( V_200 ) ;
}
}
V_210:
if ( V_208 )
V_43 = F_52 ( V_39 , V_208 , V_1 , V_166 , V_140 ) ;
if ( V_43 != 0 && V_161 != V_152 )
F_37 ( V_1 , V_161 ) ;
return V_43 ;
}
static void F_59 ( struct V_6 * V_39 ,
struct V_131 * V_24 ,
struct V_9 * V_1 ,
T_3 V_213 , T_1 V_75 )
{
struct V_12 V_214 ;
int V_215 = 0 ;
int V_43 ;
struct V_1 * V_2 = F_11 ( V_39 ) ;
V_214 . V_15 . V_16 =
V_146 ;
V_214 . V_18 . V_46 . V_216 . V_75 = V_75 ;
V_217:
V_43 = F_3 ( V_24 , & V_214 ,
sizeof( struct V_12 ) , V_213 ,
V_218 , 0 ) ;
if ( V_43 == 0 ) {
} else if ( V_43 == - V_197 ) {
V_215 ++ ;
F_15 ( V_2 , L_22
L_23 , V_213 , V_215 ) ;
if ( V_215 < 4 ) {
F_60 ( 100 ) ;
goto V_217;
} else {
F_15 ( V_2 , L_24
L_25 ,
V_213 ) ;
}
} else {
F_15 ( V_2 , L_24
L_26 , V_213 ) ;
}
}
static void F_61 ( struct V_9 * V_1 ,
struct V_131 * V_24 ,
struct V_6 * V_39 ,
struct V_133 * V_134 )
{
struct V_219 * V_220 ;
struct V_12 * V_135 ;
struct V_136 V_221 ;
struct V_136 * V_222 = & V_221 ;
T_1 V_75 = V_76 ;
int V_113 ;
int V_204 = 0 ;
struct V_1 * V_2 = F_11 ( V_39 ) ;
void * V_223 ;
if ( V_134 -> type != V_224 ) {
F_15 ( V_2 , L_27 ,
V_134 -> type ) ;
return;
}
V_135 = (struct V_12 * ) ( ( unsigned long ) V_134 +
( V_134 -> V_141 << 3 ) ) ;
if ( V_135 -> V_15 . V_16 !=
V_190 ) {
F_15 ( V_2 , L_28
L_29 , V_135 -> V_15 . V_16 ) ;
return;
}
V_220 = (struct V_219 * ) V_134 ;
if ( V_220 -> V_225 != V_49 ) {
F_15 ( V_2 , L_30
L_31 , V_49 ,
V_220 -> V_225 ) ;
return;
}
V_204 = V_220 -> V_226 ;
for ( V_113 = 0 ; V_113 < V_204 ; V_113 ++ ) {
V_223 = ( void * ) ( ( unsigned long ) V_1 ->
V_51 + V_220 -> V_227 [ V_113 ] . V_228 ) ;
V_222 -> V_174 =
V_220 -> V_227 [ V_113 ] . V_229 ;
V_75 = F_62 ( V_39 , V_222 , & V_223 ,
V_24 ) ;
}
F_59 ( V_39 , V_24 , V_1 ,
V_220 -> V_230 . V_149 , V_75 ) ;
}
static void F_63 ( struct V_6 * V_231 ,
struct V_12 * V_184 )
{
struct V_9 * V_232 ;
struct V_1 * V_2 = F_11 ( V_231 ) ;
int V_113 ;
T_1 V_204 , * V_233 ;
V_232 = F_10 ( V_231 ) ;
if ( ! V_232 )
return;
V_204 = V_184 -> V_18 . V_234 . V_235 . V_204 ;
if ( V_204 != V_236 ) {
F_15 ( V_2 , L_32 , V_204 ) ;
return;
}
V_233 = ( T_1 * ) ( ( unsigned long ) & V_184 -> V_18 . V_234 . V_235 +
V_184 -> V_18 . V_234 . V_235 . V_81 ) ;
for ( V_113 = 0 ; V_113 < V_204 ; V_113 ++ )
V_232 -> V_235 [ V_113 ] = V_233 [ V_113 ] ;
}
static void F_64 ( struct V_9 * V_11 ,
struct V_12 * V_184 )
{
V_11 -> V_237 = V_184 -> V_18 . V_19 . V_238 . V_239 ;
V_11 -> V_240 = V_184 -> V_18 . V_19 . V_238 . V_241 ;
}
static inline void F_65 ( struct V_6 * V_231 ,
struct V_9 * V_11 ,
struct V_12 * V_184 )
{
switch ( V_184 -> V_15 . V_16 ) {
case V_242 :
F_63 ( V_231 , V_184 ) ;
break;
case V_243 :
F_64 ( V_11 , V_184 ) ;
break;
}
}
void F_66 ( void * V_244 )
{
int V_43 ;
struct V_131 * V_24 = (struct V_131 * ) V_244 ;
struct V_6 * V_39 ;
struct V_9 * V_1 ;
T_1 V_245 ;
T_3 V_246 ;
struct V_133 * V_247 ;
unsigned char * V_248 ;
int V_249 = V_28 ;
struct V_1 * V_2 ;
struct V_12 * V_184 ;
if ( V_24 -> V_250 != NULL )
V_39 = V_24 -> V_250 -> V_251 ;
else
V_39 = V_24 -> V_251 ;
V_1 = F_12 ( V_39 ) ;
if ( ! V_1 )
return;
V_2 = F_11 ( V_39 ) ;
V_248 = F_67 ( V_24 ) ;
do {
V_43 = F_68 ( V_24 , V_248 , V_249 ,
& V_245 , & V_246 ) ;
if ( V_43 == 0 ) {
if ( V_245 > 0 ) {
V_247 = (struct V_133 * ) V_248 ;
V_184 = (struct V_12 * ) ( ( unsigned long )
V_247 + ( V_247 -> V_141 << 3 ) ) ;
switch ( V_247 -> type ) {
case V_218 :
F_39 ( V_1 ,
V_24 ,
V_39 , V_247 ) ;
break;
case V_224 :
F_61 ( V_1 , V_24 ,
V_39 , V_247 ) ;
break;
case V_25 :
F_65 ( V_39 ,
V_1 ,
V_184 ) ;
break;
default:
F_15 ( V_2 ,
L_33
L_34 ,
V_247 -> type , V_246 ,
V_245 ) ;
break;
}
} else {
break;
}
} else if ( V_43 == - V_252 ) {
if ( V_249 > V_28 )
F_6 ( V_248 ) ;
V_248 = F_69 ( V_245 , V_253 ) ;
if ( V_248 == NULL ) {
F_15 ( V_2 ,
L_35
L_36 , V_245 ) ;
break;
}
V_249 = V_245 ;
}
} while ( 1 );
if ( V_249 > V_28 )
F_6 ( V_248 ) ;
return;
}
int F_70 ( struct V_6 * V_39 , void * V_254 )
{
int V_113 , V_43 = 0 ;
int V_255 =
( (struct V_256 * ) V_254 ) -> V_255 ;
struct V_9 * V_1 ;
struct V_1 * V_2 = F_11 ( V_39 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
V_1 = F_4 () ;
if ( ! V_1 )
return - V_66 ;
V_1 -> V_255 = V_255 ;
F_71 ( & V_1 -> V_72 ) ;
F_72 ( V_39 -> V_24 , V_1 -> V_27 ) ;
V_43 = F_73 ( V_39 -> V_24 , V_255 * V_257 ,
V_255 * V_257 , NULL , 0 ,
F_66 , V_39 -> V_24 ) ;
if ( V_43 != 0 ) {
F_15 ( V_2 , L_37 , V_43 ) ;
goto V_67;
}
F_74 ( L_38 ) ;
for ( V_113 = 0 ; V_113 < V_258 ; V_113 ++ )
V_1 -> V_186 [ V_113 ] = V_39 -> V_24 ;
F_75 () ;
V_5 -> V_11 = V_1 ;
V_43 = F_29 ( V_39 ) ;
if ( V_43 != 0 ) {
F_15 ( V_2 ,
L_39 , V_43 ) ;
goto V_259;
}
return V_43 ;
V_259:
F_34 ( V_39 -> V_24 ) ;
V_67:
F_9 ( V_1 ) ;
return V_43 ;
}
