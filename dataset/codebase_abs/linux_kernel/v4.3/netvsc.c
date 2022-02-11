static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
struct V_4 * V_5 = F_2 ( V_3 ) ;
int V_6 ;
V_4 = F_3 ( sizeof( struct V_1 ) , V_7 ) ;
if ( ! V_4 )
return NULL ;
V_4 -> V_8 = F_3 ( V_9 , V_7 ) ;
if ( ! V_4 -> V_8 ) {
F_4 ( V_4 ) ;
return NULL ;
}
F_5 ( & V_4 -> V_10 ) ;
V_4 -> V_11 = false ;
V_4 -> V_12 = false ;
V_4 -> V_13 = V_3 ;
V_4 -> V_5 = V_5 ;
V_4 -> V_14 = V_15 ;
V_4 -> V_16 = V_17 ;
for ( V_6 = 0 ; V_6 < F_6 () ; V_6 ++ )
F_7 ( & V_4 -> V_18 [ V_6 ] . V_19 ) ;
F_8 ( V_3 , V_4 ) ;
return V_4 ;
}
static void F_9 ( struct V_1 * V_20 )
{
F_4 ( V_20 -> V_8 ) ;
F_4 ( V_20 ) ;
}
static struct V_1 * F_10 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
V_4 = F_2 ( V_3 ) ;
if ( V_4 && V_4 -> V_12 )
V_4 = NULL ;
return V_4 ;
}
static struct V_1 * F_11 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
V_4 = F_2 ( V_3 ) ;
if ( ! V_4 )
goto V_21;
if ( V_4 -> V_12 &&
F_12 ( & V_4 -> V_22 ) == 0 )
V_4 = NULL ;
V_21:
return V_4 ;
}
static int F_13 ( struct V_1 * V_4 )
{
struct V_23 * V_24 ;
int V_25 = 0 ;
struct V_4 * V_5 = V_4 -> V_5 ;
if ( V_4 -> V_26 ) {
V_24 = & V_4 -> V_24 ;
memset ( V_24 , 0 , sizeof( struct V_23 ) ) ;
V_24 -> V_27 . V_28 =
V_29 ;
V_24 -> V_30 . V_31 .
V_32 . V_33 = V_34 ;
V_25 = F_14 ( V_4 -> V_13 -> V_35 ,
V_24 ,
sizeof( struct V_23 ) ,
( unsigned long ) V_24 ,
V_36 , 0 ) ;
if ( V_25 != 0 ) {
F_15 ( V_5 , L_1
L_2 ) ;
return V_25 ;
}
}
if ( V_4 -> V_37 ) {
V_25 = F_16 ( V_4 -> V_13 -> V_35 ,
V_4 -> V_37 ) ;
if ( V_25 != 0 ) {
F_15 ( V_5 ,
L_3 ) ;
return V_25 ;
}
V_4 -> V_37 = 0 ;
}
if ( V_4 -> V_38 ) {
F_17 ( V_4 -> V_38 ) ;
V_4 -> V_38 = NULL ;
}
if ( V_4 -> V_39 ) {
V_4 -> V_26 = 0 ;
F_4 ( V_4 -> V_39 ) ;
V_4 -> V_39 = NULL ;
}
if ( V_4 -> V_40 ) {
V_24 = & V_4 -> V_24 ;
memset ( V_24 , 0 , sizeof( struct V_23 ) ) ;
V_24 -> V_27 . V_28 =
V_41 ;
V_24 -> V_30 . V_31 . V_42 . V_33 =
V_43 ;
V_25 = F_14 ( V_4 -> V_13 -> V_35 ,
V_24 ,
sizeof( struct V_23 ) ,
( unsigned long ) V_24 ,
V_36 , 0 ) ;
if ( V_25 != 0 ) {
F_15 ( V_5 , L_1
L_4 ) ;
return V_25 ;
}
}
if ( V_4 -> V_44 ) {
V_25 = F_16 ( V_4 -> V_13 -> V_35 ,
V_4 -> V_44 ) ;
if ( V_25 != 0 ) {
F_15 ( V_5 ,
L_5 ) ;
return V_25 ;
}
V_4 -> V_44 = 0 ;
}
if ( V_4 -> V_45 ) {
F_17 ( V_4 -> V_45 ) ;
V_4 -> V_45 = NULL ;
}
F_4 ( V_4 -> V_46 ) ;
return V_25 ;
}
static int F_18 ( struct V_2 * V_3 )
{
int V_25 = 0 ;
unsigned long V_47 ;
struct V_1 * V_4 ;
struct V_23 * V_48 ;
struct V_4 * V_5 ;
int V_49 ;
V_4 = F_10 ( V_3 ) ;
if ( ! V_4 )
return - V_50 ;
V_5 = V_4 -> V_5 ;
V_49 = F_19 ( V_3 -> V_35 -> V_51 ) ;
V_4 -> V_38 = F_20 ( V_4 -> V_52 , V_49 ) ;
if ( ! V_4 -> V_38 )
V_4 -> V_38 = F_21 ( V_4 -> V_52 ) ;
if ( ! V_4 -> V_38 ) {
F_15 ( V_5 , L_6
L_7 , V_4 -> V_52 ) ;
V_25 = - V_53 ;
goto V_54;
}
V_25 = F_22 ( V_3 -> V_35 , V_4 -> V_38 ,
V_4 -> V_52 ,
& V_4 -> V_37 ) ;
if ( V_25 != 0 ) {
F_15 ( V_5 ,
L_8 ) ;
goto V_54;
}
V_48 = & V_4 -> V_55 ;
memset ( V_48 , 0 , sizeof( struct V_23 ) ) ;
V_48 -> V_27 . V_28 = V_56 ;
V_48 -> V_30 . V_31 . V_57 .
V_58 = V_4 -> V_37 ;
V_48 -> V_30 . V_31 .
V_57 . V_33 = V_34 ;
V_25 = F_14 ( V_3 -> V_35 , V_48 ,
sizeof( struct V_23 ) ,
( unsigned long ) V_48 ,
V_36 ,
V_59 ) ;
if ( V_25 != 0 ) {
F_15 ( V_5 ,
L_9 ) ;
goto V_54;
}
V_47 = F_23 ( & V_4 -> V_60 , 5 * V_61 ) ;
F_24 ( V_47 == 0 ) ;
if ( V_48 -> V_30 . V_31 .
V_62 . V_63 != V_64 ) {
F_15 ( V_5 , L_10
L_11 ,
V_48 -> V_30 . V_31 .
V_62 . V_63 ) ;
V_25 = - V_65 ;
goto V_54;
}
V_4 -> V_26 = V_48 -> V_30 .
V_31 . V_62 . V_66 ;
V_4 -> V_39 = F_25 (
V_48 -> V_30 . V_31 . V_62 . V_67 ,
V_4 -> V_26 *
sizeof( struct V_68 ) ,
V_7 ) ;
if ( V_4 -> V_39 == NULL ) {
V_25 = - V_65 ;
goto V_54;
}
if ( V_4 -> V_26 != 1 ||
V_4 -> V_39 -> V_69 != 0 ) {
V_25 = - V_65 ;
goto V_54;
}
V_4 -> V_45 = F_20 ( V_4 -> V_70 , V_49 ) ;
if ( ! V_4 -> V_45 )
V_4 -> V_45 = F_21 ( V_4 -> V_70 ) ;
if ( ! V_4 -> V_45 ) {
F_15 ( V_5 , L_12
L_7 , V_4 -> V_70 ) ;
V_25 = - V_53 ;
goto V_54;
}
V_25 = F_22 ( V_3 -> V_35 , V_4 -> V_45 ,
V_4 -> V_70 ,
& V_4 -> V_44 ) ;
if ( V_25 != 0 ) {
F_15 ( V_5 ,
L_13 ) ;
goto V_54;
}
V_48 = & V_4 -> V_55 ;
memset ( V_48 , 0 , sizeof( struct V_23 ) ) ;
V_48 -> V_27 . V_28 = V_71 ;
V_48 -> V_30 . V_31 . V_72 . V_58 =
V_4 -> V_44 ;
V_48 -> V_30 . V_31 . V_72 . V_33 = V_43 ;
V_25 = F_14 ( V_3 -> V_35 , V_48 ,
sizeof( struct V_23 ) ,
( unsigned long ) V_48 ,
V_36 ,
V_59 ) ;
if ( V_25 != 0 ) {
F_15 ( V_5 ,
L_14 ) ;
goto V_54;
}
V_47 = F_23 ( & V_4 -> V_60 , 5 * V_61 ) ;
F_24 ( V_47 == 0 ) ;
if ( V_48 -> V_30 . V_31 .
V_73 . V_63 != V_64 ) {
F_15 ( V_5 , L_15
L_11 ,
V_48 -> V_30 . V_31 .
V_73 . V_63 ) ;
V_25 = - V_65 ;
goto V_54;
}
V_4 -> V_40 = V_48 -> V_30 .
V_31 . V_73 . V_74 ;
V_4 -> V_75 =
V_4 -> V_70 / V_4 -> V_40 ;
F_26 ( & V_3 -> V_3 , L_16 ,
V_4 -> V_40 , V_4 -> V_75 ) ;
V_4 -> V_76 = F_27 ( V_4 -> V_75 ,
V_77 ) ;
V_4 -> V_46 =
F_3 ( V_4 -> V_76 * sizeof( V_78 ) , V_7 ) ;
if ( V_4 -> V_46 == NULL ) {
V_25 = - V_53 ;
goto V_54;
}
goto exit;
V_54:
F_13 ( V_4 ) ;
exit:
return V_25 ;
}
static int F_28 ( struct V_2 * V_3 ,
struct V_1 * V_4 ,
struct V_23 * V_48 ,
T_1 V_79 )
{
int V_25 ;
unsigned long V_47 ;
memset ( V_48 , 0 , sizeof( struct V_23 ) ) ;
V_48 -> V_27 . V_28 = V_80 ;
V_48 -> V_30 . V_81 . V_82 . V_83 = V_79 ;
V_48 -> V_30 . V_81 . V_82 . V_84 = V_79 ;
V_25 = F_14 ( V_3 -> V_35 , V_48 ,
sizeof( struct V_23 ) ,
( unsigned long ) V_48 ,
V_36 ,
V_59 ) ;
if ( V_25 != 0 )
return V_25 ;
V_47 = F_23 ( & V_4 -> V_60 , 5 * V_61 ) ;
if ( V_47 == 0 )
return - V_85 ;
if ( V_48 -> V_30 . V_81 . V_86 . V_63 !=
V_64 )
return - V_65 ;
if ( V_79 == V_87 )
return 0 ;
memset ( V_48 , 0 , sizeof( struct V_23 ) ) ;
V_48 -> V_27 . V_28 = V_88 ;
V_48 -> V_30 . V_89 . V_90 . V_91 = V_4 -> V_5 -> V_91 +
V_92 ;
V_48 -> V_30 . V_89 . V_90 . V_93 . V_94 = 1 ;
if ( V_79 >= V_95 )
V_48 -> V_30 . V_89 . V_90 . V_93 . V_96 = 1 ;
V_25 = F_14 ( V_3 -> V_35 , V_48 ,
sizeof( struct V_23 ) ,
( unsigned long ) V_48 ,
V_36 , 0 ) ;
return V_25 ;
}
static int F_29 ( struct V_2 * V_3 )
{
int V_25 ;
struct V_1 * V_4 ;
struct V_23 * V_48 ;
int V_97 ;
struct V_4 * V_5 ;
T_1 V_98 [] = { V_87 , V_99 ,
V_100 , V_95 } ;
int V_6 , V_101 = 4 ;
V_4 = F_10 ( V_3 ) ;
if ( ! V_4 )
return - V_50 ;
V_5 = V_4 -> V_5 ;
V_48 = & V_4 -> V_55 ;
for ( V_6 = V_101 - 1 ; V_6 >= 0 ; V_6 -- )
if ( F_28 ( V_3 , V_4 , V_48 ,
V_98 [ V_6 ] ) == 0 ) {
V_4 -> V_102 = V_98 [ V_6 ] ;
break;
}
if ( V_6 < 0 ) {
V_25 = - V_103 ;
goto V_54;
}
F_30 ( L_17 , V_4 -> V_102 ) ;
memset ( V_48 , 0 , sizeof( struct V_23 ) ) ;
if ( V_4 -> V_102 <= V_100 )
V_97 = 0x00060001 ;
else
V_97 = 0x0006001e ;
V_48 -> V_27 . V_28 = V_104 ;
V_48 -> V_30 . V_31 .
V_105 . V_106 =
( V_97 & 0xFFFF0000 ) >> 16 ;
V_48 -> V_30 . V_31 .
V_105 . V_107 =
V_97 & 0xFFFF ;
V_25 = F_14 ( V_3 -> V_35 , V_48 ,
sizeof( struct V_23 ) ,
( unsigned long ) V_48 ,
V_36 , 0 ) ;
if ( V_25 != 0 )
goto V_54;
if ( V_4 -> V_102 <= V_99 )
V_4 -> V_52 = V_108 ;
else
V_4 -> V_52 = V_109 ;
V_4 -> V_70 = V_110 ;
V_25 = F_18 ( V_3 ) ;
V_54:
return V_25 ;
}
static void F_31 ( struct V_1 * V_4 )
{
F_13 ( V_4 ) ;
}
int F_32 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
unsigned long V_111 ;
V_4 = F_2 ( V_3 ) ;
F_31 ( V_4 ) ;
F_33 ( & V_3 -> V_35 -> V_112 , V_111 ) ;
F_8 ( V_3 , NULL ) ;
F_34 ( & V_3 -> V_35 -> V_112 , V_111 ) ;
F_35 ( & V_3 -> V_3 , L_18 ) ;
F_36 ( V_3 -> V_35 ) ;
F_17 ( V_4 -> V_113 ) ;
F_9 ( V_4 ) ;
return 0 ;
}
static inline T_1 F_37 (
struct V_114 * V_115 )
{
T_1 V_116 , V_117 ;
F_38 ( V_115 , & V_116 , & V_117 ) ;
return V_117 * 100 / V_115 -> V_118 ;
}
static inline void F_39 ( struct V_1 * V_4 ,
T_1 V_119 )
{
F_40 ( V_119 , V_4 -> V_46 ) ;
}
static void F_41 ( struct V_1 * V_4 ,
struct V_2 * V_3 ,
struct V_120 * V_121 )
{
struct V_23 * V_122 ;
struct V_123 * V_124 ;
struct V_4 * V_5 ;
T_1 V_125 ;
V_5 = V_4 -> V_5 ;
V_122 = (struct V_23 * ) ( ( unsigned long ) V_121 +
( V_121 -> V_126 << 3 ) ) ;
if ( ( V_122 -> V_27 . V_28 == V_127 ) ||
( V_122 -> V_27 . V_28 ==
V_128 ) ||
( V_122 -> V_27 . V_28 ==
V_129 ) ||
( V_122 -> V_27 . V_28 ==
V_130 ) ) {
memcpy ( & V_4 -> V_55 , V_122 ,
sizeof( struct V_23 ) ) ;
F_42 ( & V_4 -> V_60 ) ;
} else if ( V_122 -> V_27 . V_28 ==
V_131 ) {
int V_22 ;
T_2 V_132 = 0 ;
struct V_133 * V_35 = V_3 -> V_35 ;
int V_134 ;
V_124 = (struct V_123 * ) ( unsigned long )
V_121 -> V_135 ;
if ( V_124 ) {
V_125 = V_124 -> V_136 ;
if ( V_125 != V_137 )
F_39 ( V_4 , V_125 ) ;
V_132 = V_124 -> V_132 ;
V_35 = V_124 -> V_35 ;
V_124 -> V_138 ( V_124 ->
V_139 ) ;
}
V_22 =
F_43 ( & V_4 -> V_22 ) ;
V_134 = F_43 ( & V_4 ->
V_134 [ V_132 ] ) ;
if ( V_4 -> V_12 && V_22 == 0 )
F_44 ( & V_4 -> V_10 ) ;
if ( F_45 ( F_46 ( V_5 , V_132 ) ) &&
! V_4 -> V_11 &&
( F_37 ( & V_35 -> V_140 ) >
V_141 || V_134 < 1 ) )
F_47 ( F_46 (
V_5 , V_132 ) ) ;
} else {
F_15 ( V_5 , L_19
L_20 , V_122 -> V_27 . V_28 ) ;
}
}
static T_1 F_48 ( struct V_1 * V_4 )
{
unsigned long V_119 ;
T_1 V_142 = V_4 -> V_76 ;
unsigned long * V_143 = ( unsigned long * ) V_4 -> V_46 ;
T_1 V_144 = V_4 -> V_75 ;
int V_145 = V_137 ;
int V_6 ;
int V_146 ;
for ( V_6 = 0 ; V_6 < V_142 ; V_6 ++ ) {
if ( ! ~ ( V_143 [ V_6 ] ) )
continue;
V_119 = F_49 ( V_143 [ V_6 ] ) ;
V_146 = F_50 ( V_119 , & V_143 [ V_6 ] ) ;
if ( V_146 )
continue;
if ( ( V_119 + ( V_6 * V_77 ) ) >= V_144 )
break;
V_145 = ( V_119 + ( V_6 * V_77 ) ) ;
break;
}
return V_145 ;
}
static T_1 F_51 ( struct V_1 * V_4 ,
unsigned int V_147 ,
T_1 V_148 ,
struct V_123 * V_121 )
{
char * V_149 = V_4 -> V_45 ;
char * V_150 = V_149 + ( V_147 * V_4 -> V_40 )
+ V_148 ;
int V_6 ;
T_1 V_151 = 0 ;
T_1 V_152 = 0 ;
T_1 V_153 = V_121 -> V_154 % V_4 -> V_16 ;
T_1 V_155 = V_121 -> V_156 ? V_121 -> V_157 :
V_121 -> V_158 ;
if ( V_121 -> V_159 && V_121 -> V_160 && V_153 &&
! V_121 -> V_156 ) {
V_152 = V_4 -> V_16 - V_153 ;
V_121 -> V_161 -> V_162 += V_152 ;
V_121 -> V_154 += V_152 ;
}
for ( V_6 = 0 ; V_6 < V_155 ; V_6 ++ ) {
char * V_163 = F_52 ( V_121 -> V_164 [ V_6 ] . V_165 << V_166 ) ;
T_1 V_69 = V_121 -> V_164 [ V_6 ] . V_69 ;
T_1 V_167 = V_121 -> V_164 [ V_6 ] . V_167 ;
memcpy ( V_150 , ( V_163 + V_69 ) , V_167 ) ;
V_151 += V_167 ;
V_150 += V_167 ;
}
if ( V_152 ) {
memset ( V_150 , 0 , V_152 ) ;
V_151 += V_152 ;
}
return V_151 ;
}
static inline int F_53 (
struct V_123 * V_121 ,
struct V_1 * V_4 )
{
struct V_23 V_168 ;
struct V_133 * V_169 = V_121 -> V_35 ;
T_2 V_132 = V_121 -> V_132 ;
struct V_4 * V_5 = V_4 -> V_5 ;
T_3 V_170 ;
int V_25 ;
struct V_171 * V_172 ;
T_1 V_173 = F_37 ( & V_169 -> V_140 ) ;
V_168 . V_27 . V_28 = V_174 ;
if ( V_121 -> V_159 ) {
V_168 . V_30 . V_31 . V_175 . V_176 = 0 ;
} else {
V_168 . V_30 . V_31 . V_175 . V_176 = 1 ;
}
V_168 . V_30 . V_31 . V_175 . V_177 =
V_121 -> V_136 ;
if ( V_121 -> V_136 == V_137 )
V_168 . V_30 . V_31 . V_175 . V_178 = 0 ;
else
V_168 . V_30 . V_31 . V_175 . V_178 =
V_121 -> V_154 ;
if ( V_121 -> V_138 )
V_170 = ( V_78 ) V_121 ;
else
V_170 = 0 ;
if ( V_169 -> V_179 )
return - V_50 ;
if ( V_173 < ( V_180 + 1 ) )
V_121 -> V_160 = false ;
if ( V_121 -> V_158 ) {
V_172 = V_121 -> V_156 ? V_121 -> V_164 +
V_121 -> V_157 : V_121 -> V_164 ;
V_25 = F_54 ( V_169 ,
V_172 ,
V_121 -> V_158 ,
& V_168 ,
sizeof( struct V_23 ) ,
V_170 ,
V_59 ,
! V_121 -> V_160 ) ;
} else {
V_25 = F_55 ( V_169 , & V_168 ,
sizeof( struct V_23 ) ,
V_170 ,
V_36 ,
V_59 ,
! V_121 -> V_160 ) ;
}
if ( V_25 == 0 ) {
F_56 ( & V_4 -> V_22 ) ;
F_56 ( & V_4 -> V_134 [ V_132 ] ) ;
if ( V_173 < V_180 ) {
F_57 ( F_46 ( V_5 , V_132 ) ) ;
if ( F_12 ( & V_4 ->
V_134 [ V_132 ] ) < 1 )
F_47 ( F_46 (
V_5 , V_132 ) ) ;
}
} else if ( V_25 == - V_181 ) {
F_57 ( F_46 (
V_5 , V_132 ) ) ;
if ( F_12 ( & V_4 -> V_134 [ V_132 ] ) < 1 ) {
F_47 ( F_46 (
V_5 , V_132 ) ) ;
V_25 = - V_182 ;
}
} else {
F_15 ( V_5 , L_21 ,
V_121 , V_25 ) ;
}
return V_25 ;
}
int F_58 ( struct V_2 * V_3 ,
struct V_123 * V_121 )
{
struct V_1 * V_4 ;
int V_25 = 0 , V_183 = 0 ;
struct V_133 * V_169 ;
T_2 V_132 = V_121 -> V_132 ;
T_1 V_184 = V_121 -> V_154 , V_185 = 0 ;
unsigned int V_147 = V_137 ;
unsigned long V_186 ;
struct V_187 * V_188 ;
struct V_123 * V_189 = NULL , * V_190 = NULL ;
bool V_191 ;
V_4 = F_10 ( V_3 ) ;
if ( ! V_4 )
return - V_50 ;
V_169 = V_4 -> V_192 [ V_132 ] ;
if ( ! V_169 ) {
V_169 = V_3 -> V_35 ;
V_132 = 0 ;
V_121 -> V_132 = 0 ;
}
V_121 -> V_35 = V_169 ;
V_121 -> V_136 = V_137 ;
V_121 -> V_156 = false ;
V_188 = & V_4 -> V_18 [ V_132 ] ;
F_33 ( & V_188 -> V_19 , V_186 ) ;
if ( V_188 -> V_193 )
V_185 = V_188 -> V_193 -> V_154 ;
V_191 = V_121 -> V_159 && V_185 > 0 && V_188 -> V_194 <
V_4 -> V_14 ;
if ( V_191 && V_185 + V_184 + V_4 -> V_16 <
V_4 -> V_40 ) {
V_147 = V_188 -> V_193 -> V_136 ;
} else if ( V_191 && V_185 + V_121 -> V_195 <
V_4 -> V_40 ) {
V_147 = V_188 -> V_193 -> V_136 ;
V_121 -> V_156 = true ;
} else if ( V_121 -> V_159 && V_184 + V_4 -> V_16 <
V_4 -> V_40 ) {
V_147 = F_48 ( V_4 ) ;
if ( V_147 != V_137 ) {
V_189 = V_188 -> V_193 ;
V_188 -> V_193 = NULL ;
V_188 -> V_194 = 0 ;
V_185 = 0 ;
}
}
if ( V_147 != V_137 ) {
F_51 ( V_4 ,
V_147 , V_185 ,
V_121 ) ;
V_121 -> V_136 = V_147 ;
if ( V_121 -> V_156 ) {
V_121 -> V_158 -= V_121 -> V_157 ;
V_121 -> V_154 = V_185 + V_121 -> V_195 ;
} else {
V_121 -> V_158 = 0 ;
V_121 -> V_154 += V_185 ;
}
if ( V_188 -> V_193 )
F_59 ( V_188 -> V_193 ) ;
if ( V_121 -> V_160 && ! V_121 -> V_156 ) {
V_188 -> V_193 = V_121 ;
V_188 -> V_194 ++ ;
} else {
V_190 = V_121 ;
V_188 -> V_193 = NULL ;
V_188 -> V_194 = 0 ;
}
} else {
V_189 = V_188 -> V_193 ;
V_188 -> V_193 = NULL ;
V_188 -> V_194 = 0 ;
V_190 = V_121 ;
}
F_34 ( & V_188 -> V_19 , V_186 ) ;
if ( V_189 ) {
V_183 = F_53 ( V_189 , V_4 ) ;
if ( V_183 != 0 ) {
F_39 ( V_4 ,
V_189 -> V_136 ) ;
F_59 ( V_189 ) ;
}
}
if ( V_190 )
V_25 = F_53 ( V_190 , V_4 ) ;
if ( V_25 != 0 && V_147 != V_137 )
F_39 ( V_4 , V_147 ) ;
return V_25 ;
}
static void F_60 ( struct V_2 * V_3 ,
struct V_133 * V_35 ,
struct V_1 * V_4 ,
T_3 V_196 , T_1 V_63 )
{
struct V_23 V_197 ;
int V_198 = 0 ;
int V_25 ;
struct V_4 * V_5 ;
V_5 = V_4 -> V_5 ;
V_197 . V_27 . V_28 =
V_131 ;
V_197 . V_30 . V_31 . V_199 . V_63 = V_63 ;
V_200:
V_25 = F_14 ( V_35 , & V_197 ,
sizeof( struct V_23 ) , V_196 ,
V_201 , 0 ) ;
if ( V_25 == 0 ) {
} else if ( V_25 == - V_181 ) {
V_198 ++ ;
F_15 ( V_5 , L_22
L_23 , V_196 , V_198 ) ;
if ( V_198 < 4 ) {
F_61 ( 100 ) ;
goto V_200;
} else {
F_15 ( V_5 , L_24
L_25 ,
V_196 ) ;
}
} else {
F_15 ( V_5 , L_24
L_26 , V_196 ) ;
}
}
static void F_62 ( struct V_1 * V_4 ,
struct V_133 * V_35 ,
struct V_2 * V_3 ,
struct V_120 * V_121 )
{
struct V_202 * V_203 ;
struct V_23 * V_122 ;
struct V_123 V_204 ;
struct V_123 * V_205 = & V_204 ;
T_1 V_63 = V_64 ;
int V_6 ;
int V_194 = 0 ;
struct V_4 * V_5 ;
V_5 = V_4 -> V_5 ;
if ( V_121 -> type != V_206 ) {
F_15 ( V_5 , L_27 ,
V_121 -> type ) ;
return;
}
V_122 = (struct V_23 * ) ( ( unsigned long ) V_121 +
( V_121 -> V_126 << 3 ) ) ;
if ( V_122 -> V_27 . V_28 !=
V_174 ) {
F_15 ( V_5 , L_28
L_29 , V_122 -> V_27 . V_28 ) ;
return;
}
V_203 = (struct V_202 * ) V_121 ;
if ( V_203 -> V_207 != V_34 ) {
F_15 ( V_5 , L_30
L_31 , V_34 ,
V_203 -> V_207 ) ;
return;
}
V_194 = V_203 -> V_208 ;
V_205 -> V_35 = V_35 ;
for ( V_6 = 0 ; V_6 < V_194 ; V_6 ++ ) {
V_205 -> V_63 = V_64 ;
V_205 -> V_209 = ( void * ) ( ( unsigned long ) V_4 ->
V_38 + V_203 -> V_210 [ V_6 ] . V_211 ) ;
V_205 -> V_154 =
V_203 -> V_210 [ V_6 ] . V_212 ;
F_63 ( V_3 , V_205 ) ;
if ( V_205 -> V_63 != V_64 )
V_63 = V_213 ;
}
F_60 ( V_3 , V_35 , V_4 ,
V_203 -> V_214 . V_135 , V_63 ) ;
}
static void F_64 ( struct V_2 * V_215 ,
struct V_23 * V_168 )
{
struct V_1 * V_216 ;
struct V_4 * V_5 ;
int V_6 ;
T_1 V_194 , * V_217 ;
V_216 = F_10 ( V_215 ) ;
if ( ! V_216 )
return;
V_5 = V_216 -> V_5 ;
V_194 = V_168 -> V_30 . V_218 . V_219 . V_194 ;
if ( V_194 != V_220 ) {
F_15 ( V_5 , L_32 , V_194 ) ;
return;
}
V_217 = ( T_1 * ) ( ( unsigned long ) & V_168 -> V_30 . V_218 . V_219 +
V_168 -> V_30 . V_218 . V_219 . V_69 ) ;
for ( V_6 = 0 ; V_6 < V_194 ; V_6 ++ )
V_216 -> V_219 [ V_6 ] = V_217 [ V_6 ] ;
}
static void F_65 ( struct V_1 * V_20 ,
struct V_23 * V_168 )
{
V_20 -> V_221 = V_168 -> V_30 . V_222 . V_223 . V_224 ;
V_20 -> V_225 = V_168 -> V_30 . V_222 . V_223 . V_226 ;
}
static inline void F_66 ( struct V_2 * V_215 ,
struct V_1 * V_20 ,
struct V_23 * V_168 )
{
switch ( V_168 -> V_27 . V_28 ) {
case V_227 :
F_64 ( V_215 , V_168 ) ;
break;
case V_228 :
F_65 ( V_20 , V_168 ) ;
break;
}
}
void F_67 ( void * V_229 )
{
int V_25 ;
struct V_133 * V_35 = (struct V_133 * ) V_229 ;
struct V_2 * V_3 ;
struct V_1 * V_4 ;
T_1 V_230 ;
T_3 V_231 ;
struct V_120 * V_232 ;
unsigned char * V_233 ;
int V_234 = V_9 ;
struct V_4 * V_5 ;
struct V_23 * V_168 ;
if ( V_35 -> V_235 != NULL )
V_3 = V_35 -> V_235 -> V_236 ;
else
V_3 = V_35 -> V_236 ;
V_4 = F_11 ( V_3 ) ;
if ( ! V_4 )
return;
V_5 = V_4 -> V_5 ;
V_233 = F_68 ( V_35 ) ;
do {
V_25 = F_69 ( V_35 , V_233 , V_234 ,
& V_230 , & V_231 ) ;
if ( V_25 == 0 ) {
if ( V_230 > 0 ) {
V_232 = (struct V_120 * ) V_233 ;
V_168 = (struct V_23 * ) ( ( unsigned long )
V_232 + ( V_232 -> V_126 << 3 ) ) ;
switch ( V_232 -> type ) {
case V_201 :
F_41 ( V_4 ,
V_3 , V_232 ) ;
break;
case V_206 :
F_62 ( V_4 , V_35 ,
V_3 , V_232 ) ;
break;
case V_36 :
F_66 ( V_3 ,
V_4 ,
V_168 ) ;
break;
default:
F_15 ( V_5 ,
L_33
L_34 ,
V_232 -> type , V_231 ,
V_230 ) ;
break;
}
} else {
break;
}
} else if ( V_25 == - V_237 ) {
if ( V_234 > V_9 )
F_4 ( V_233 ) ;
V_233 = F_70 ( V_230 , V_238 ) ;
if ( V_233 == NULL ) {
F_15 ( V_5 ,
L_35
L_36 , V_230 ) ;
break;
}
V_234 = V_230 ;
}
} while ( 1 );
if ( V_234 > V_9 )
F_4 ( V_233 ) ;
return;
}
int F_71 ( struct V_2 * V_3 , void * V_239 )
{
int V_25 = 0 ;
int V_240 =
( (struct V_241 * ) V_239 ) -> V_240 ;
struct V_1 * V_4 ;
struct V_4 * V_5 ;
V_4 = F_1 ( V_3 ) ;
if ( ! V_4 )
return - V_53 ;
V_4 -> V_240 = V_240 ;
V_5 = V_4 -> V_5 ;
V_4 -> V_242 = F_72 ( V_5 ) ;
F_73 ( & V_4 -> V_60 ) ;
F_74 ( V_3 -> V_35 , V_4 -> V_8 ) ;
V_25 = F_75 ( V_3 -> V_35 , V_240 * V_243 ,
V_240 * V_243 , NULL , 0 ,
F_67 , V_3 -> V_35 ) ;
if ( V_25 != 0 ) {
F_15 ( V_5 , L_37 , V_25 ) ;
goto V_54;
}
F_76 ( L_38 ) ;
V_4 -> V_192 [ 0 ] = V_3 -> V_35 ;
V_25 = F_29 ( V_3 ) ;
if ( V_25 != 0 ) {
F_15 ( V_5 ,
L_39 , V_25 ) ;
goto V_244;
}
return V_25 ;
V_244:
F_36 ( V_3 -> V_35 ) ;
V_54:
F_9 ( V_4 ) ;
return V_25 ;
}
