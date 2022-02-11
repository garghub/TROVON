static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
struct V_4 * V_5 = F_2 ( V_3 ) ;
V_4 = F_3 ( sizeof( struct V_1 ) , V_6 ) ;
if ( ! V_4 )
return NULL ;
V_4 -> V_7 = F_3 ( V_8 , V_6 ) ;
if ( ! V_4 -> V_7 ) {
F_4 ( V_4 ) ;
return NULL ;
}
F_5 ( & V_4 -> V_9 ) ;
V_4 -> V_10 = false ;
V_4 -> V_11 = false ;
V_4 -> V_12 = V_3 ;
V_4 -> V_5 = V_5 ;
V_4 -> V_13 = V_14 ;
V_4 -> V_15 = V_16 ;
F_6 ( V_3 , V_4 ) ;
return V_4 ;
}
static void F_7 ( struct V_1 * V_17 )
{
F_4 ( V_17 -> V_7 ) ;
F_4 ( V_17 ) ;
}
static struct V_1 * F_8 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
V_4 = F_2 ( V_3 ) ;
if ( V_4 && V_4 -> V_11 )
V_4 = NULL ;
return V_4 ;
}
static struct V_1 * F_9 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
V_4 = F_2 ( V_3 ) ;
if ( ! V_4 )
goto V_18;
if ( V_4 -> V_11 &&
F_10 ( & V_4 -> V_19 ) == 0 )
V_4 = NULL ;
V_18:
return V_4 ;
}
static int F_11 ( struct V_1 * V_4 )
{
struct V_20 * V_21 ;
int V_22 = 0 ;
struct V_4 * V_5 = V_4 -> V_5 ;
if ( V_4 -> V_23 ) {
V_21 = & V_4 -> V_21 ;
memset ( V_21 , 0 , sizeof( struct V_20 ) ) ;
V_21 -> V_24 . V_25 =
V_26 ;
V_21 -> V_27 . V_28 .
V_29 . V_30 = V_31 ;
V_22 = F_12 ( V_4 -> V_12 -> V_32 ,
V_21 ,
sizeof( struct V_20 ) ,
( unsigned long ) V_21 ,
V_33 , 0 ) ;
if ( V_22 != 0 ) {
F_13 ( V_5 , L_1
L_2 ) ;
return V_22 ;
}
}
if ( V_4 -> V_34 ) {
V_22 = F_14 ( V_4 -> V_12 -> V_32 ,
V_4 -> V_34 ) ;
if ( V_22 != 0 ) {
F_13 ( V_5 ,
L_3 ) ;
return V_22 ;
}
V_4 -> V_34 = 0 ;
}
if ( V_4 -> V_35 ) {
F_15 ( V_4 -> V_35 ) ;
V_4 -> V_35 = NULL ;
}
if ( V_4 -> V_36 ) {
V_4 -> V_23 = 0 ;
F_4 ( V_4 -> V_36 ) ;
V_4 -> V_36 = NULL ;
}
if ( V_4 -> V_37 ) {
V_21 = & V_4 -> V_21 ;
memset ( V_21 , 0 , sizeof( struct V_20 ) ) ;
V_21 -> V_24 . V_25 =
V_38 ;
V_21 -> V_27 . V_28 . V_39 . V_30 =
V_40 ;
V_22 = F_12 ( V_4 -> V_12 -> V_32 ,
V_21 ,
sizeof( struct V_20 ) ,
( unsigned long ) V_21 ,
V_33 , 0 ) ;
if ( V_22 != 0 ) {
F_13 ( V_5 , L_1
L_4 ) ;
return V_22 ;
}
}
if ( V_4 -> V_41 ) {
V_22 = F_14 ( V_4 -> V_12 -> V_32 ,
V_4 -> V_41 ) ;
if ( V_22 != 0 ) {
F_13 ( V_5 ,
L_5 ) ;
return V_22 ;
}
V_4 -> V_41 = 0 ;
}
if ( V_4 -> V_42 ) {
F_15 ( V_4 -> V_42 ) ;
V_4 -> V_42 = NULL ;
}
F_4 ( V_4 -> V_43 ) ;
return V_22 ;
}
static int F_16 ( struct V_2 * V_3 )
{
int V_22 = 0 ;
unsigned long V_44 ;
struct V_1 * V_4 ;
struct V_20 * V_45 ;
struct V_4 * V_5 ;
int V_46 ;
V_4 = F_8 ( V_3 ) ;
if ( ! V_4 )
return - V_47 ;
V_5 = V_4 -> V_5 ;
V_46 = F_17 ( V_3 -> V_32 -> V_48 ) ;
V_4 -> V_35 = F_18 ( V_4 -> V_49 , V_46 ) ;
if ( ! V_4 -> V_35 )
V_4 -> V_35 = F_19 ( V_4 -> V_49 ) ;
if ( ! V_4 -> V_35 ) {
F_13 ( V_5 , L_6
L_7 , V_4 -> V_49 ) ;
V_22 = - V_50 ;
goto V_51;
}
V_22 = F_20 ( V_3 -> V_32 , V_4 -> V_35 ,
V_4 -> V_49 ,
& V_4 -> V_34 ) ;
if ( V_22 != 0 ) {
F_13 ( V_5 ,
L_8 ) ;
goto V_51;
}
V_45 = & V_4 -> V_52 ;
memset ( V_45 , 0 , sizeof( struct V_20 ) ) ;
V_45 -> V_24 . V_25 = V_53 ;
V_45 -> V_27 . V_28 . V_54 .
V_55 = V_4 -> V_34 ;
V_45 -> V_27 . V_28 .
V_54 . V_30 = V_31 ;
V_22 = F_12 ( V_3 -> V_32 , V_45 ,
sizeof( struct V_20 ) ,
( unsigned long ) V_45 ,
V_33 ,
V_56 ) ;
if ( V_22 != 0 ) {
F_13 ( V_5 ,
L_9 ) ;
goto V_51;
}
V_44 = F_21 ( & V_4 -> V_57 , 5 * V_58 ) ;
F_22 ( V_44 == 0 ) ;
if ( V_45 -> V_27 . V_28 .
V_59 . V_60 != V_61 ) {
F_13 ( V_5 , L_10
L_11 ,
V_45 -> V_27 . V_28 .
V_59 . V_60 ) ;
V_22 = - V_62 ;
goto V_51;
}
V_4 -> V_23 = V_45 -> V_27 .
V_28 . V_59 . V_63 ;
V_4 -> V_36 = F_23 (
V_45 -> V_27 . V_28 . V_59 . V_64 ,
V_4 -> V_23 *
sizeof( struct V_65 ) ,
V_6 ) ;
if ( V_4 -> V_36 == NULL ) {
V_22 = - V_62 ;
goto V_51;
}
if ( V_4 -> V_23 != 1 ||
V_4 -> V_36 -> V_66 != 0 ) {
V_22 = - V_62 ;
goto V_51;
}
V_4 -> V_42 = F_18 ( V_4 -> V_67 , V_46 ) ;
if ( ! V_4 -> V_42 )
V_4 -> V_42 = F_19 ( V_4 -> V_67 ) ;
if ( ! V_4 -> V_42 ) {
F_13 ( V_5 , L_12
L_7 , V_4 -> V_67 ) ;
V_22 = - V_50 ;
goto V_51;
}
V_22 = F_20 ( V_3 -> V_32 , V_4 -> V_42 ,
V_4 -> V_67 ,
& V_4 -> V_41 ) ;
if ( V_22 != 0 ) {
F_13 ( V_5 ,
L_13 ) ;
goto V_51;
}
V_45 = & V_4 -> V_52 ;
memset ( V_45 , 0 , sizeof( struct V_20 ) ) ;
V_45 -> V_24 . V_25 = V_68 ;
V_45 -> V_27 . V_28 . V_69 . V_55 =
V_4 -> V_41 ;
V_45 -> V_27 . V_28 . V_69 . V_30 = V_40 ;
V_22 = F_12 ( V_3 -> V_32 , V_45 ,
sizeof( struct V_20 ) ,
( unsigned long ) V_45 ,
V_33 ,
V_56 ) ;
if ( V_22 != 0 ) {
F_13 ( V_5 ,
L_14 ) ;
goto V_51;
}
V_44 = F_21 ( & V_4 -> V_57 , 5 * V_58 ) ;
F_22 ( V_44 == 0 ) ;
if ( V_45 -> V_27 . V_28 .
V_70 . V_60 != V_61 ) {
F_13 ( V_5 , L_15
L_11 ,
V_45 -> V_27 . V_28 .
V_70 . V_60 ) ;
V_22 = - V_62 ;
goto V_51;
}
V_4 -> V_37 = V_45 -> V_27 .
V_28 . V_70 . V_71 ;
V_4 -> V_72 =
V_4 -> V_67 / V_4 -> V_37 ;
F_24 ( & V_3 -> V_3 , L_16 ,
V_4 -> V_37 , V_4 -> V_72 ) ;
V_4 -> V_73 = F_25 ( V_4 -> V_72 ,
V_74 ) ;
V_4 -> V_43 =
F_3 ( V_4 -> V_73 * sizeof( V_75 ) , V_6 ) ;
if ( V_4 -> V_43 == NULL ) {
V_22 = - V_50 ;
goto V_51;
}
goto exit;
V_51:
F_11 ( V_4 ) ;
exit:
return V_22 ;
}
static int F_26 ( struct V_2 * V_3 ,
struct V_1 * V_4 ,
struct V_20 * V_45 ,
T_1 V_76 )
{
int V_22 ;
unsigned long V_44 ;
memset ( V_45 , 0 , sizeof( struct V_20 ) ) ;
V_45 -> V_24 . V_25 = V_77 ;
V_45 -> V_27 . V_78 . V_79 . V_80 = V_76 ;
V_45 -> V_27 . V_78 . V_79 . V_81 = V_76 ;
V_22 = F_12 ( V_3 -> V_32 , V_45 ,
sizeof( struct V_20 ) ,
( unsigned long ) V_45 ,
V_33 ,
V_56 ) ;
if ( V_22 != 0 )
return V_22 ;
V_44 = F_21 ( & V_4 -> V_57 , 5 * V_58 ) ;
if ( V_44 == 0 )
return - V_82 ;
if ( V_45 -> V_27 . V_78 . V_83 . V_60 !=
V_61 )
return - V_62 ;
if ( V_76 == V_84 )
return 0 ;
memset ( V_45 , 0 , sizeof( struct V_20 ) ) ;
V_45 -> V_24 . V_25 = V_85 ;
V_45 -> V_27 . V_86 . V_87 . V_88 = V_4 -> V_5 -> V_88 +
V_89 ;
V_45 -> V_27 . V_86 . V_87 . V_90 . V_91 = 1 ;
if ( V_76 >= V_92 )
V_45 -> V_27 . V_86 . V_87 . V_90 . V_93 = 1 ;
V_22 = F_12 ( V_3 -> V_32 , V_45 ,
sizeof( struct V_20 ) ,
( unsigned long ) V_45 ,
V_33 , 0 ) ;
return V_22 ;
}
static int F_27 ( struct V_2 * V_3 )
{
int V_22 ;
struct V_1 * V_4 ;
struct V_20 * V_45 ;
int V_94 ;
struct V_4 * V_5 ;
T_1 V_95 [] = { V_84 , V_96 ,
V_97 , V_92 } ;
int V_98 , V_99 = 4 ;
V_4 = F_8 ( V_3 ) ;
if ( ! V_4 )
return - V_47 ;
V_5 = V_4 -> V_5 ;
V_45 = & V_4 -> V_52 ;
for ( V_98 = V_99 - 1 ; V_98 >= 0 ; V_98 -- )
if ( F_26 ( V_3 , V_4 , V_45 ,
V_95 [ V_98 ] ) == 0 ) {
V_4 -> V_100 = V_95 [ V_98 ] ;
break;
}
if ( V_98 < 0 ) {
V_22 = - V_101 ;
goto V_51;
}
F_28 ( L_17 , V_4 -> V_100 ) ;
memset ( V_45 , 0 , sizeof( struct V_20 ) ) ;
if ( V_4 -> V_100 <= V_97 )
V_94 = 0x00060001 ;
else
V_94 = 0x0006001e ;
V_45 -> V_24 . V_25 = V_102 ;
V_45 -> V_27 . V_28 .
V_103 . V_104 =
( V_94 & 0xFFFF0000 ) >> 16 ;
V_45 -> V_27 . V_28 .
V_103 . V_105 =
V_94 & 0xFFFF ;
V_22 = F_12 ( V_3 -> V_32 , V_45 ,
sizeof( struct V_20 ) ,
( unsigned long ) V_45 ,
V_33 , 0 ) ;
if ( V_22 != 0 )
goto V_51;
if ( V_4 -> V_100 <= V_96 )
V_4 -> V_49 = V_106 ;
else
V_4 -> V_49 = V_107 ;
V_4 -> V_67 = V_108 ;
V_22 = F_16 ( V_3 ) ;
V_51:
return V_22 ;
}
static void F_29 ( struct V_1 * V_4 )
{
F_11 ( V_4 ) ;
}
int F_30 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
unsigned long V_109 ;
V_4 = F_2 ( V_3 ) ;
F_29 ( V_4 ) ;
F_31 ( & V_3 -> V_32 -> V_110 , V_109 ) ;
F_6 ( V_3 , NULL ) ;
F_32 ( & V_3 -> V_32 -> V_110 , V_109 ) ;
F_33 ( & V_3 -> V_3 , L_18 ) ;
F_34 ( V_3 -> V_32 ) ;
F_15 ( V_4 -> V_111 ) ;
F_7 ( V_4 ) ;
return 0 ;
}
static inline T_1 F_35 (
struct V_112 * V_113 )
{
T_1 V_114 , V_115 ;
F_36 ( V_113 , & V_114 , & V_115 ) ;
return V_115 * 100 / V_113 -> V_116 ;
}
static inline void F_37 ( struct V_1 * V_4 ,
T_1 V_117 )
{
F_38 ( V_117 , V_4 -> V_43 ) ;
}
static void F_39 ( struct V_1 * V_4 ,
struct V_118 * V_119 ,
struct V_2 * V_3 ,
struct V_120 * V_121 )
{
struct V_20 * V_122 ;
struct V_123 * V_124 ;
struct V_4 * V_5 ;
T_1 V_125 ;
struct V_126 * V_127 ;
V_5 = V_4 -> V_5 ;
V_122 = (struct V_20 * ) ( ( unsigned long ) V_121 +
( V_121 -> V_128 << 3 ) ) ;
if ( ( V_122 -> V_24 . V_25 == V_129 ) ||
( V_122 -> V_24 . V_25 ==
V_130 ) ||
( V_122 -> V_24 . V_25 ==
V_131 ) ||
( V_122 -> V_24 . V_25 ==
V_132 ) ) {
memcpy ( & V_4 -> V_52 , V_122 ,
sizeof( struct V_20 ) ) ;
F_40 ( & V_4 -> V_57 ) ;
} else if ( V_122 -> V_24 . V_25 ==
V_133 ) {
int V_19 ;
T_2 V_134 = 0 ;
struct V_118 * V_32 = V_3 -> V_32 ;
int V_135 ;
V_127 = (struct V_126 * ) ( unsigned long ) V_121 -> V_136 ;
if ( V_127 ) {
V_124 = (struct V_123 * ) V_127 -> V_137 ;
V_125 = V_124 -> V_138 ;
if ( V_125 != V_139 )
F_37 ( V_4 , V_125 ) ;
V_134 = V_124 -> V_134 ;
V_32 = V_119 ;
F_41 ( V_127 ) ;
}
V_19 =
F_42 ( & V_4 -> V_19 ) ;
V_135 = F_42 ( & V_4 ->
V_135 [ V_134 ] ) ;
if ( V_4 -> V_11 && V_19 == 0 )
F_43 ( & V_4 -> V_9 ) ;
if ( F_44 ( F_45 ( V_5 , V_134 ) ) &&
! V_4 -> V_10 &&
( F_35 ( & V_32 -> V_140 ) >
V_141 || V_135 < 1 ) )
F_46 ( F_45 (
V_5 , V_134 ) ) ;
} else {
F_13 ( V_5 , L_19
L_20 , V_122 -> V_24 . V_25 ) ;
}
}
static T_1 F_47 ( struct V_1 * V_4 )
{
unsigned long V_117 ;
T_1 V_142 = V_4 -> V_73 ;
unsigned long * V_143 = ( unsigned long * ) V_4 -> V_43 ;
T_1 V_144 = V_4 -> V_72 ;
int V_145 = V_139 ;
int V_98 ;
int V_146 ;
for ( V_98 = 0 ; V_98 < V_142 ; V_98 ++ ) {
if ( ! ~ ( V_143 [ V_98 ] ) )
continue;
V_117 = F_48 ( V_143 [ V_98 ] ) ;
V_146 = F_49 ( V_117 , & V_143 [ V_98 ] ) ;
if ( V_146 )
continue;
if ( ( V_117 + ( V_98 * V_74 ) ) >= V_144 )
break;
V_145 = ( V_117 + ( V_98 * V_74 ) ) ;
break;
}
return V_145 ;
}
static T_1 F_50 ( struct V_1 * V_4 ,
unsigned int V_147 ,
T_1 V_148 ,
struct V_123 * V_121 ,
struct V_149 * V_150 ,
struct V_151 * * V_152 ,
struct V_126 * V_127 )
{
char * V_153 = V_4 -> V_42 ;
char * V_154 = V_153 + ( V_147 * V_4 -> V_37 )
+ V_148 ;
int V_98 ;
bool V_155 = ( V_127 != NULL ) ? true : false ;
bool V_156 = ( V_127 != NULL ) ? V_127 -> V_156 : false ;
T_1 V_157 = 0 ;
T_1 V_158 = 0 ;
T_1 V_159 = V_121 -> V_160 % V_4 -> V_15 ;
T_1 V_161 = V_121 -> V_162 ? V_121 -> V_163 :
V_121 -> V_164 ;
if ( V_155 && V_156 && V_159 &&
! V_121 -> V_162 ) {
V_158 = V_4 -> V_15 - V_159 ;
V_150 -> V_165 += V_158 ;
V_121 -> V_160 += V_158 ;
}
for ( V_98 = 0 ; V_98 < V_161 ; V_98 ++ ) {
char * V_166 = F_51 ( ( * V_152 ) [ V_98 ] . V_167 << V_168 ) ;
T_1 V_66 = ( * V_152 ) [ V_98 ] . V_66 ;
T_1 V_169 = ( * V_152 ) [ V_98 ] . V_169 ;
memcpy ( V_154 , ( V_166 + V_66 ) , V_169 ) ;
V_157 += V_169 ;
V_154 += V_169 ;
}
if ( V_158 ) {
memset ( V_154 , 0 , V_158 ) ;
V_157 += V_158 ;
}
return V_157 ;
}
static inline int F_52 (
struct V_123 * V_121 ,
struct V_1 * V_4 ,
struct V_151 * * V_152 ,
struct V_126 * V_127 )
{
struct V_20 V_170 ;
T_2 V_134 = V_121 -> V_134 ;
struct V_118 * V_171 = V_4 -> V_172 [ V_134 ] ;
struct V_4 * V_5 = V_4 -> V_5 ;
T_3 V_173 ;
int V_22 ;
struct V_151 * V_174 ;
T_1 V_175 = F_35 ( & V_171 -> V_140 ) ;
bool V_156 = ( V_127 != NULL ) ? V_127 -> V_156 : false ;
V_170 . V_24 . V_25 = V_176 ;
if ( V_127 != NULL ) {
V_170 . V_27 . V_28 . V_177 . V_178 = 0 ;
} else {
V_170 . V_27 . V_28 . V_177 . V_178 = 1 ;
}
V_170 . V_27 . V_28 . V_177 . V_179 =
V_121 -> V_138 ;
if ( V_121 -> V_138 == V_139 )
V_170 . V_27 . V_28 . V_177 . V_180 = 0 ;
else
V_170 . V_27 . V_28 . V_177 . V_180 =
V_121 -> V_160 ;
V_173 = ( V_75 ) V_127 ;
if ( V_171 -> V_181 )
return - V_47 ;
if ( V_175 < ( V_182 + 1 ) )
V_156 = false ;
if ( V_121 -> V_164 ) {
V_174 = V_121 -> V_162 ? ( * V_152 ) +
V_121 -> V_163 : ( * V_152 ) ;
V_22 = F_53 ( V_171 ,
V_174 ,
V_121 -> V_164 ,
& V_170 ,
sizeof( struct V_20 ) ,
V_173 ,
V_56 ,
! V_156 ) ;
} else {
V_22 = F_54 ( V_171 , & V_170 ,
sizeof( struct V_20 ) ,
V_173 ,
V_33 ,
V_56 ,
! V_156 ) ;
}
if ( V_22 == 0 ) {
F_55 ( & V_4 -> V_19 ) ;
F_55 ( & V_4 -> V_135 [ V_134 ] ) ;
if ( V_175 < V_182 ) {
F_56 ( F_45 ( V_5 , V_134 ) ) ;
if ( F_10 ( & V_4 ->
V_135 [ V_134 ] ) < 1 )
F_46 ( F_45 (
V_5 , V_134 ) ) ;
}
} else if ( V_22 == - V_183 ) {
F_56 ( F_45 (
V_5 , V_134 ) ) ;
if ( F_10 ( & V_4 -> V_135 [ V_134 ] ) < 1 ) {
F_46 ( F_45 (
V_5 , V_134 ) ) ;
V_22 = - V_184 ;
}
} else {
F_13 ( V_5 , L_21 ,
V_121 , V_22 ) ;
}
return V_22 ;
}
static inline void F_57 ( struct V_123 * * V_185 ,
struct V_126 * * V_186 ,
struct V_187 * V_188 )
{
* V_186 = V_188 -> V_127 ;
* V_185 = V_188 -> V_189 ;
V_188 -> V_127 = NULL ;
V_188 -> V_189 = NULL ;
V_188 -> V_190 = 0 ;
}
int F_58 ( struct V_2 * V_3 ,
struct V_123 * V_121 ,
struct V_149 * V_150 ,
struct V_151 * * V_152 ,
struct V_126 * V_127 )
{
struct V_1 * V_4 ;
int V_22 = 0 , V_191 = 0 ;
struct V_118 * V_171 ;
T_2 V_134 = V_121 -> V_134 ;
T_1 V_192 = V_121 -> V_160 , V_193 = 0 ;
unsigned int V_147 = V_139 ;
struct V_187 * V_188 ;
struct V_123 * V_185 = NULL , * V_194 = NULL ;
struct V_126 * V_186 = NULL ;
bool V_195 ;
bool V_156 = ( V_127 != NULL ) ? V_127 -> V_156 : false ;
V_4 = F_8 ( V_3 ) ;
if ( ! V_4 )
return - V_47 ;
V_171 = V_4 -> V_172 [ V_134 ] ;
V_121 -> V_138 = V_139 ;
V_121 -> V_162 = false ;
if ( ! V_127 ) {
V_194 = V_121 ;
goto V_196;
}
V_188 = & V_4 -> V_197 [ V_134 ] ;
if ( V_188 -> V_189 )
V_193 = V_188 -> V_189 -> V_160 ;
V_195 = ( V_127 != NULL ) && V_193 > 0 && V_188 -> V_190 <
V_4 -> V_13 ;
if ( V_195 && V_193 + V_192 + V_4 -> V_15 <
V_4 -> V_37 ) {
V_147 = V_188 -> V_189 -> V_138 ;
} else if ( V_195 && V_193 + V_121 -> V_198 <
V_4 -> V_37 ) {
V_147 = V_188 -> V_189 -> V_138 ;
V_121 -> V_162 = true ;
} else if ( ( V_127 != NULL ) && V_192 + V_4 -> V_15 <
V_4 -> V_37 ) {
V_147 = F_47 ( V_4 ) ;
if ( V_147 != V_139 ) {
F_57 ( & V_185 , & V_186 , V_188 ) ;
V_193 = 0 ;
}
}
if ( V_147 != V_139 ) {
F_50 ( V_4 ,
V_147 , V_193 ,
V_121 , V_150 , V_152 , V_127 ) ;
V_121 -> V_138 = V_147 ;
if ( V_121 -> V_162 ) {
V_121 -> V_164 -= V_121 -> V_163 ;
V_121 -> V_160 = V_193 + V_121 -> V_198 ;
} else {
V_121 -> V_164 = 0 ;
V_121 -> V_160 += V_193 ;
}
if ( V_188 -> V_127 )
F_41 ( V_188 -> V_127 ) ;
if ( V_156 && ! V_121 -> V_162 ) {
V_188 -> V_127 = V_127 ;
V_188 -> V_189 = V_121 ;
V_188 -> V_190 ++ ;
} else {
V_194 = V_121 ;
V_188 -> V_127 = NULL ;
V_188 -> V_189 = NULL ;
V_188 -> V_190 = 0 ;
}
} else {
F_57 ( & V_185 , & V_186 , V_188 ) ;
V_194 = V_121 ;
}
if ( V_185 ) {
V_191 = F_52 ( V_185 , V_4 , NULL , V_186 ) ;
if ( V_191 != 0 ) {
F_37 ( V_4 ,
V_185 -> V_138 ) ;
F_41 ( V_186 ) ;
}
}
V_196:
if ( V_194 )
V_22 = F_52 ( V_194 , V_4 , V_152 , V_127 ) ;
if ( V_22 != 0 && V_147 != V_139 )
F_37 ( V_4 , V_147 ) ;
return V_22 ;
}
static void F_59 ( struct V_2 * V_3 ,
struct V_118 * V_32 ,
struct V_1 * V_4 ,
T_3 V_199 , T_1 V_60 )
{
struct V_20 V_200 ;
int V_201 = 0 ;
int V_22 ;
struct V_4 * V_5 ;
V_5 = V_4 -> V_5 ;
V_200 . V_24 . V_25 =
V_133 ;
V_200 . V_27 . V_28 . V_202 . V_60 = V_60 ;
V_203:
V_22 = F_12 ( V_32 , & V_200 ,
sizeof( struct V_20 ) , V_199 ,
V_204 , 0 ) ;
if ( V_22 == 0 ) {
} else if ( V_22 == - V_183 ) {
V_201 ++ ;
F_13 ( V_5 , L_22
L_23 , V_199 , V_201 ) ;
if ( V_201 < 4 ) {
F_60 ( 100 ) ;
goto V_203;
} else {
F_13 ( V_5 , L_24
L_25 ,
V_199 ) ;
}
} else {
F_13 ( V_5 , L_24
L_26 , V_199 ) ;
}
}
static void F_61 ( struct V_1 * V_4 ,
struct V_118 * V_32 ,
struct V_2 * V_3 ,
struct V_120 * V_121 )
{
struct V_205 * V_206 ;
struct V_20 * V_122 ;
struct V_123 V_207 ;
struct V_123 * V_208 = & V_207 ;
T_1 V_60 = V_61 ;
int V_98 ;
int V_190 = 0 ;
struct V_4 * V_5 ;
void * V_209 ;
V_5 = V_4 -> V_5 ;
if ( V_121 -> type != V_210 ) {
F_13 ( V_5 , L_27 ,
V_121 -> type ) ;
return;
}
V_122 = (struct V_20 * ) ( ( unsigned long ) V_121 +
( V_121 -> V_128 << 3 ) ) ;
if ( V_122 -> V_24 . V_25 !=
V_176 ) {
F_13 ( V_5 , L_28
L_29 , V_122 -> V_24 . V_25 ) ;
return;
}
V_206 = (struct V_205 * ) V_121 ;
if ( V_206 -> V_211 != V_31 ) {
F_13 ( V_5 , L_30
L_31 , V_31 ,
V_206 -> V_211 ) ;
return;
}
V_190 = V_206 -> V_212 ;
for ( V_98 = 0 ; V_98 < V_190 ; V_98 ++ ) {
V_209 = ( void * ) ( ( unsigned long ) V_4 ->
V_35 + V_206 -> V_213 [ V_98 ] . V_214 ) ;
V_208 -> V_160 =
V_206 -> V_213 [ V_98 ] . V_215 ;
V_60 = F_62 ( V_3 , V_208 , & V_209 ,
V_32 ) ;
}
F_59 ( V_3 , V_32 , V_4 ,
V_206 -> V_216 . V_136 , V_60 ) ;
}
static void F_63 ( struct V_2 * V_217 ,
struct V_20 * V_170 )
{
struct V_1 * V_218 ;
struct V_4 * V_5 ;
int V_98 ;
T_1 V_190 , * V_219 ;
V_218 = F_8 ( V_217 ) ;
if ( ! V_218 )
return;
V_5 = V_218 -> V_5 ;
V_190 = V_170 -> V_27 . V_220 . V_221 . V_190 ;
if ( V_190 != V_222 ) {
F_13 ( V_5 , L_32 , V_190 ) ;
return;
}
V_219 = ( T_1 * ) ( ( unsigned long ) & V_170 -> V_27 . V_220 . V_221 +
V_170 -> V_27 . V_220 . V_221 . V_66 ) ;
for ( V_98 = 0 ; V_98 < V_190 ; V_98 ++ )
V_218 -> V_221 [ V_98 ] = V_219 [ V_98 ] ;
}
static void F_64 ( struct V_1 * V_17 ,
struct V_20 * V_170 )
{
V_17 -> V_223 = V_170 -> V_27 . V_224 . V_225 . V_226 ;
V_17 -> V_227 = V_170 -> V_27 . V_224 . V_225 . V_228 ;
}
static inline void F_65 ( struct V_2 * V_217 ,
struct V_1 * V_17 ,
struct V_20 * V_170 )
{
switch ( V_170 -> V_24 . V_25 ) {
case V_229 :
F_63 ( V_217 , V_170 ) ;
break;
case V_230 :
F_64 ( V_17 , V_170 ) ;
break;
}
}
void F_66 ( void * V_231 )
{
int V_22 ;
struct V_118 * V_32 = (struct V_118 * ) V_231 ;
struct V_2 * V_3 ;
struct V_1 * V_4 ;
T_1 V_232 ;
T_3 V_233 ;
struct V_120 * V_234 ;
unsigned char * V_235 ;
int V_236 = V_8 ;
struct V_4 * V_5 ;
struct V_20 * V_170 ;
if ( V_32 -> V_237 != NULL )
V_3 = V_32 -> V_237 -> V_238 ;
else
V_3 = V_32 -> V_238 ;
V_4 = F_9 ( V_3 ) ;
if ( ! V_4 )
return;
V_5 = V_4 -> V_5 ;
V_235 = F_67 ( V_32 ) ;
do {
V_22 = F_68 ( V_32 , V_235 , V_236 ,
& V_232 , & V_233 ) ;
if ( V_22 == 0 ) {
if ( V_232 > 0 ) {
V_234 = (struct V_120 * ) V_235 ;
V_170 = (struct V_20 * ) ( ( unsigned long )
V_234 + ( V_234 -> V_128 << 3 ) ) ;
switch ( V_234 -> type ) {
case V_204 :
F_39 ( V_4 ,
V_32 ,
V_3 , V_234 ) ;
break;
case V_210 :
F_61 ( V_4 , V_32 ,
V_3 , V_234 ) ;
break;
case V_33 :
F_65 ( V_3 ,
V_4 ,
V_170 ) ;
break;
default:
F_13 ( V_5 ,
L_33
L_34 ,
V_234 -> type , V_233 ,
V_232 ) ;
break;
}
} else {
break;
}
} else if ( V_22 == - V_239 ) {
if ( V_236 > V_8 )
F_4 ( V_235 ) ;
V_235 = F_69 ( V_232 , V_240 ) ;
if ( V_235 == NULL ) {
F_13 ( V_5 ,
L_35
L_36 , V_232 ) ;
break;
}
V_236 = V_232 ;
}
} while ( 1 );
if ( V_236 > V_8 )
F_4 ( V_235 ) ;
return;
}
int F_70 ( struct V_2 * V_3 , void * V_241 )
{
int V_22 = 0 ;
int V_242 =
( (struct V_243 * ) V_241 ) -> V_242 ;
struct V_1 * V_4 ;
struct V_4 * V_5 ;
V_4 = F_1 ( V_3 ) ;
if ( ! V_4 )
return - V_50 ;
V_4 -> V_242 = V_242 ;
V_5 = V_4 -> V_5 ;
V_4 -> V_244 = F_71 ( V_5 ) ;
F_72 ( & V_4 -> V_57 ) ;
F_73 ( V_3 -> V_32 , V_4 -> V_7 ) ;
V_22 = F_74 ( V_3 -> V_32 , V_242 * V_245 ,
V_242 * V_245 , NULL , 0 ,
F_66 , V_3 -> V_32 ) ;
if ( V_22 != 0 ) {
F_13 ( V_5 , L_37 , V_22 ) ;
goto V_51;
}
F_75 ( L_38 ) ;
V_4 -> V_172 [ 0 ] = V_3 -> V_32 ;
V_22 = F_27 ( V_3 ) ;
if ( V_22 != 0 ) {
F_13 ( V_5 ,
L_39 , V_22 ) ;
goto V_246;
}
return V_22 ;
V_246:
F_34 ( V_3 -> V_32 ) ;
V_51:
F_7 ( V_4 ) ;
return V_22 ;
}
