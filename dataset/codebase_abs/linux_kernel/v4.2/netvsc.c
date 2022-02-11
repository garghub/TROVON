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
int V_95 ;
struct V_4 * V_5 ;
T_1 V_96 [] = { V_87 , V_97 ,
V_98 , V_99 } ;
int V_6 , V_100 = 4 ;
V_4 = F_10 ( V_3 ) ;
if ( ! V_4 )
return - V_50 ;
V_5 = V_4 -> V_5 ;
V_48 = & V_4 -> V_55 ;
for ( V_6 = V_100 - 1 ; V_6 >= 0 ; V_6 -- )
if ( F_28 ( V_3 , V_4 , V_48 ,
V_96 [ V_6 ] ) == 0 ) {
V_4 -> V_101 = V_96 [ V_6 ] ;
break;
}
if ( V_6 < 0 ) {
V_25 = - V_102 ;
goto V_54;
}
F_30 ( L_17 , V_4 -> V_101 ) ;
memset ( V_48 , 0 , sizeof( struct V_23 ) ) ;
if ( V_4 -> V_101 <= V_98 )
V_95 = 0x00060001 ;
else
V_95 = 0x0006001e ;
V_48 -> V_27 . V_28 = V_103 ;
V_48 -> V_30 . V_31 .
V_104 . V_105 =
( V_95 & 0xFFFF0000 ) >> 16 ;
V_48 -> V_30 . V_31 .
V_104 . V_106 =
V_95 & 0xFFFF ;
V_25 = F_14 ( V_3 -> V_35 , V_48 ,
sizeof( struct V_23 ) ,
( unsigned long ) V_48 ,
V_36 , 0 ) ;
if ( V_25 != 0 )
goto V_54;
if ( V_4 -> V_101 <= V_97 )
V_4 -> V_52 = V_107 ;
else
V_4 -> V_52 = V_108 ;
V_4 -> V_70 = V_109 ;
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
unsigned long V_110 ;
V_4 = F_2 ( V_3 ) ;
F_31 ( V_4 ) ;
F_33 ( & V_3 -> V_35 -> V_111 , V_110 ) ;
F_8 ( V_3 , NULL ) ;
F_34 ( & V_3 -> V_35 -> V_111 , V_110 ) ;
F_35 ( & V_3 -> V_3 , L_18 ) ;
F_36 ( V_3 -> V_35 ) ;
F_17 ( V_4 -> V_112 ) ;
F_9 ( V_4 ) ;
return 0 ;
}
static inline T_1 F_37 (
struct V_113 * V_114 )
{
T_1 V_115 , V_116 ;
F_38 ( V_114 , & V_115 , & V_116 ) ;
return V_116 * 100 / V_114 -> V_117 ;
}
static inline void F_39 ( struct V_1 * V_4 ,
T_1 V_118 )
{
F_40 ( V_118 , V_4 -> V_46 ) ;
}
static void F_41 ( struct V_1 * V_4 ,
struct V_2 * V_3 ,
struct V_119 * V_120 )
{
struct V_23 * V_121 ;
struct V_122 * V_123 ;
struct V_4 * V_5 ;
T_1 V_124 ;
V_5 = V_4 -> V_5 ;
V_121 = (struct V_23 * ) ( ( unsigned long ) V_120 +
( V_120 -> V_125 << 3 ) ) ;
if ( ( V_121 -> V_27 . V_28 == V_126 ) ||
( V_121 -> V_27 . V_28 ==
V_127 ) ||
( V_121 -> V_27 . V_28 ==
V_128 ) ||
( V_121 -> V_27 . V_28 ==
V_129 ) ) {
memcpy ( & V_4 -> V_55 , V_121 ,
sizeof( struct V_23 ) ) ;
F_42 ( & V_4 -> V_60 ) ;
} else if ( V_121 -> V_27 . V_28 ==
V_130 ) {
int V_22 ;
T_2 V_131 = 0 ;
struct V_132 * V_35 = V_3 -> V_35 ;
int V_133 ;
V_123 = (struct V_122 * ) ( unsigned long )
V_120 -> V_134 ;
if ( V_123 ) {
V_124 = V_123 -> V_135 ;
if ( V_124 != V_136 )
F_39 ( V_4 , V_124 ) ;
V_131 = V_123 -> V_131 ;
V_35 = V_123 -> V_35 ;
V_123 -> V_137 ( V_123 ->
V_138 ) ;
}
V_22 =
F_43 ( & V_4 -> V_22 ) ;
V_133 = F_43 ( & V_4 ->
V_133 [ V_131 ] ) ;
if ( V_4 -> V_12 && V_22 == 0 )
F_44 ( & V_4 -> V_10 ) ;
if ( F_45 ( F_46 ( V_5 , V_131 ) ) &&
! V_4 -> V_11 &&
( F_37 ( & V_35 -> V_139 ) >
V_140 || V_133 < 1 ) )
F_47 ( F_46 (
V_5 , V_131 ) ) ;
} else {
F_15 ( V_5 , L_19
L_20 , V_121 -> V_27 . V_28 ) ;
}
}
static T_1 F_48 ( struct V_1 * V_4 )
{
unsigned long V_118 ;
T_1 V_141 = V_4 -> V_76 ;
unsigned long * V_142 = ( unsigned long * ) V_4 -> V_46 ;
T_1 V_143 = V_4 -> V_75 ;
int V_144 = V_136 ;
int V_6 ;
int V_145 ;
for ( V_6 = 0 ; V_6 < V_141 ; V_6 ++ ) {
if ( ! ~ ( V_142 [ V_6 ] ) )
continue;
V_118 = F_49 ( V_142 [ V_6 ] ) ;
V_145 = F_50 ( V_118 , & V_142 [ V_6 ] ) ;
if ( V_145 )
continue;
if ( ( V_118 + ( V_6 * V_77 ) ) >= V_143 )
break;
V_144 = ( V_118 + ( V_6 * V_77 ) ) ;
break;
}
return V_144 ;
}
static T_1 F_51 ( struct V_1 * V_4 ,
unsigned int V_146 ,
T_1 V_147 ,
struct V_122 * V_120 )
{
char * V_148 = V_4 -> V_45 ;
char * V_149 = V_148 + ( V_146 * V_4 -> V_40 )
+ V_147 ;
int V_6 ;
T_1 V_150 = 0 ;
T_1 V_151 = 0 ;
T_1 V_152 = V_120 -> V_153 % V_4 -> V_16 ;
T_1 V_154 = V_120 -> V_155 ? V_120 -> V_156 :
V_120 -> V_157 ;
if ( V_120 -> V_158 && V_120 -> V_159 && V_152 &&
! V_120 -> V_155 ) {
V_151 = V_4 -> V_16 - V_152 ;
V_120 -> V_160 -> V_161 += V_151 ;
V_120 -> V_153 += V_151 ;
}
for ( V_6 = 0 ; V_6 < V_154 ; V_6 ++ ) {
char * V_162 = F_52 ( V_120 -> V_163 [ V_6 ] . V_164 << V_165 ) ;
T_1 V_69 = V_120 -> V_163 [ V_6 ] . V_69 ;
T_1 V_166 = V_120 -> V_163 [ V_6 ] . V_166 ;
memcpy ( V_149 , ( V_162 + V_69 ) , V_166 ) ;
V_150 += V_166 ;
V_149 += V_166 ;
}
if ( V_151 ) {
memset ( V_149 , 0 , V_151 ) ;
V_150 += V_151 ;
}
return V_150 ;
}
static inline int F_53 (
struct V_122 * V_120 ,
struct V_1 * V_4 )
{
struct V_23 V_167 ;
struct V_132 * V_168 = V_120 -> V_35 ;
T_2 V_131 = V_120 -> V_131 ;
struct V_4 * V_5 = V_4 -> V_5 ;
T_3 V_169 ;
int V_25 ;
struct V_170 * V_171 ;
T_1 V_172 = F_37 ( & V_168 -> V_139 ) ;
V_167 . V_27 . V_28 = V_173 ;
if ( V_120 -> V_158 ) {
V_167 . V_30 . V_31 . V_174 . V_175 = 0 ;
} else {
V_167 . V_30 . V_31 . V_174 . V_175 = 1 ;
}
V_167 . V_30 . V_31 . V_174 . V_176 =
V_120 -> V_135 ;
if ( V_120 -> V_135 == V_136 )
V_167 . V_30 . V_31 . V_174 . V_177 = 0 ;
else
V_167 . V_30 . V_31 . V_174 . V_177 =
V_120 -> V_153 ;
if ( V_120 -> V_137 )
V_169 = ( V_78 ) V_120 ;
else
V_169 = 0 ;
if ( V_168 -> V_178 )
return - V_50 ;
if ( V_172 < ( V_179 + 1 ) )
V_120 -> V_159 = false ;
if ( V_120 -> V_157 ) {
V_171 = V_120 -> V_155 ? V_120 -> V_163 +
V_120 -> V_156 : V_120 -> V_163 ;
V_25 = F_54 ( V_168 ,
V_171 ,
V_120 -> V_157 ,
& V_167 ,
sizeof( struct V_23 ) ,
V_169 ,
V_59 ,
! V_120 -> V_159 ) ;
} else {
V_25 = F_55 ( V_168 , & V_167 ,
sizeof( struct V_23 ) ,
V_169 ,
V_36 ,
V_59 ,
! V_120 -> V_159 ) ;
}
if ( V_25 == 0 ) {
F_56 ( & V_4 -> V_22 ) ;
F_56 ( & V_4 -> V_133 [ V_131 ] ) ;
if ( V_172 < V_179 ) {
F_57 ( F_46 ( V_5 , V_131 ) ) ;
if ( F_12 ( & V_4 ->
V_133 [ V_131 ] ) < 1 )
F_47 ( F_46 (
V_5 , V_131 ) ) ;
}
} else if ( V_25 == - V_180 ) {
F_57 ( F_46 (
V_5 , V_131 ) ) ;
if ( F_12 ( & V_4 -> V_133 [ V_131 ] ) < 1 ) {
F_47 ( F_46 (
V_5 , V_131 ) ) ;
V_25 = - V_181 ;
}
} else {
F_15 ( V_5 , L_21 ,
V_120 , V_25 ) ;
}
return V_25 ;
}
int F_58 ( struct V_2 * V_3 ,
struct V_122 * V_120 )
{
struct V_1 * V_4 ;
int V_25 = 0 , V_182 = 0 ;
struct V_132 * V_168 ;
T_2 V_131 = V_120 -> V_131 ;
T_1 V_183 = V_120 -> V_153 , V_184 = 0 ;
unsigned int V_146 = V_136 ;
unsigned long V_185 ;
struct V_186 * V_187 ;
struct V_122 * V_188 = NULL , * V_189 = NULL ;
bool V_190 ;
V_4 = F_10 ( V_3 ) ;
if ( ! V_4 )
return - V_50 ;
V_168 = V_4 -> V_191 [ V_131 ] ;
if ( ! V_168 ) {
V_168 = V_3 -> V_35 ;
V_131 = 0 ;
V_120 -> V_131 = 0 ;
}
V_120 -> V_35 = V_168 ;
V_120 -> V_135 = V_136 ;
V_120 -> V_155 = false ;
V_187 = & V_4 -> V_18 [ V_131 ] ;
F_33 ( & V_187 -> V_19 , V_185 ) ;
if ( V_187 -> V_192 )
V_184 = V_187 -> V_192 -> V_153 ;
V_190 = V_120 -> V_158 && V_184 > 0 && V_187 -> V_193 <
V_4 -> V_14 ;
if ( V_190 && V_184 + V_183 + V_4 -> V_16 <
V_4 -> V_40 ) {
V_146 = V_187 -> V_192 -> V_135 ;
} else if ( V_190 && V_184 + V_120 -> V_194 <
V_4 -> V_40 ) {
V_146 = V_187 -> V_192 -> V_135 ;
V_120 -> V_155 = true ;
} else if ( V_120 -> V_158 && V_183 + V_4 -> V_16 <
V_4 -> V_40 ) {
V_146 = F_48 ( V_4 ) ;
if ( V_146 != V_136 ) {
V_188 = V_187 -> V_192 ;
V_187 -> V_192 = NULL ;
V_187 -> V_193 = 0 ;
V_184 = 0 ;
}
}
if ( V_146 != V_136 ) {
F_51 ( V_4 ,
V_146 , V_184 ,
V_120 ) ;
V_120 -> V_135 = V_146 ;
if ( V_120 -> V_155 ) {
V_120 -> V_157 -= V_120 -> V_156 ;
V_120 -> V_153 = V_184 + V_120 -> V_194 ;
} else {
V_120 -> V_157 = 0 ;
V_120 -> V_153 += V_184 ;
}
if ( V_187 -> V_192 )
F_59 ( V_187 -> V_192 ) ;
if ( V_120 -> V_159 && ! V_120 -> V_155 ) {
V_187 -> V_192 = V_120 ;
V_187 -> V_193 ++ ;
} else {
V_189 = V_120 ;
V_187 -> V_192 = NULL ;
V_187 -> V_193 = 0 ;
}
} else {
V_188 = V_187 -> V_192 ;
V_187 -> V_192 = NULL ;
V_187 -> V_193 = 0 ;
V_189 = V_120 ;
}
F_34 ( & V_187 -> V_19 , V_185 ) ;
if ( V_188 ) {
V_182 = F_53 ( V_188 , V_4 ) ;
if ( V_182 != 0 ) {
F_39 ( V_4 ,
V_188 -> V_135 ) ;
F_59 ( V_188 ) ;
}
}
if ( V_189 )
V_25 = F_53 ( V_189 , V_4 ) ;
if ( V_25 != 0 && V_146 != V_136 )
F_39 ( V_4 , V_146 ) ;
return V_25 ;
}
static void F_60 ( struct V_2 * V_3 ,
struct V_132 * V_35 ,
struct V_1 * V_4 ,
T_3 V_195 , T_1 V_63 )
{
struct V_23 V_196 ;
int V_197 = 0 ;
int V_25 ;
struct V_4 * V_5 ;
V_5 = V_4 -> V_5 ;
V_196 . V_27 . V_28 =
V_130 ;
V_196 . V_30 . V_31 . V_198 . V_63 = V_63 ;
V_199:
V_25 = F_14 ( V_35 , & V_196 ,
sizeof( struct V_23 ) , V_195 ,
V_200 , 0 ) ;
if ( V_25 == 0 ) {
} else if ( V_25 == - V_180 ) {
V_197 ++ ;
F_15 ( V_5 , L_22
L_23 , V_195 , V_197 ) ;
if ( V_197 < 4 ) {
F_61 ( 100 ) ;
goto V_199;
} else {
F_15 ( V_5 , L_24
L_25 ,
V_195 ) ;
}
} else {
F_15 ( V_5 , L_24
L_26 , V_195 ) ;
}
}
static void F_62 ( struct V_1 * V_4 ,
struct V_132 * V_35 ,
struct V_2 * V_3 ,
struct V_119 * V_120 )
{
struct V_201 * V_202 ;
struct V_23 * V_121 ;
struct V_122 V_203 ;
struct V_122 * V_204 = & V_203 ;
T_1 V_63 = V_64 ;
int V_6 ;
int V_193 = 0 ;
struct V_4 * V_5 ;
V_5 = V_4 -> V_5 ;
if ( V_120 -> type != V_205 ) {
F_15 ( V_5 , L_27 ,
V_120 -> type ) ;
return;
}
V_121 = (struct V_23 * ) ( ( unsigned long ) V_120 +
( V_120 -> V_125 << 3 ) ) ;
if ( V_121 -> V_27 . V_28 !=
V_173 ) {
F_15 ( V_5 , L_28
L_29 , V_121 -> V_27 . V_28 ) ;
return;
}
V_202 = (struct V_201 * ) V_120 ;
if ( V_202 -> V_206 != V_34 ) {
F_15 ( V_5 , L_30
L_31 , V_34 ,
V_202 -> V_206 ) ;
return;
}
V_193 = V_202 -> V_207 ;
V_204 -> V_35 = V_35 ;
for ( V_6 = 0 ; V_6 < V_193 ; V_6 ++ ) {
V_204 -> V_63 = V_64 ;
V_204 -> V_208 = ( void * ) ( ( unsigned long ) V_4 ->
V_38 + V_202 -> V_209 [ V_6 ] . V_210 ) ;
V_204 -> V_153 =
V_202 -> V_209 [ V_6 ] . V_211 ;
F_63 ( V_3 , V_204 ) ;
if ( V_204 -> V_63 != V_64 )
V_63 = V_212 ;
}
F_60 ( V_3 , V_35 , V_4 ,
V_202 -> V_213 . V_134 , V_63 ) ;
}
static void F_64 ( struct V_2 * V_214 ,
struct V_119 * V_215 )
{
struct V_1 * V_216 ;
struct V_4 * V_5 ;
struct V_23 * V_167 ;
int V_6 ;
T_1 V_193 , * V_217 ;
V_216 = F_10 ( V_214 ) ;
if ( ! V_216 )
return;
V_5 = V_216 -> V_5 ;
V_167 = (struct V_23 * ) ( ( unsigned long ) V_215 +
( V_215 -> V_125 << 3 ) ) ;
if ( V_167 -> V_27 . V_28 != V_218 )
return;
V_193 = V_167 -> V_30 . V_219 . V_220 . V_193 ;
if ( V_193 != V_221 ) {
F_15 ( V_5 , L_32 , V_193 ) ;
return;
}
V_217 = ( T_1 * ) ( ( unsigned long ) & V_167 -> V_30 . V_219 . V_220 +
V_167 -> V_30 . V_219 . V_220 . V_69 ) ;
for ( V_6 = 0 ; V_6 < V_193 ; V_6 ++ )
V_216 -> V_220 [ V_6 ] = V_217 [ V_6 ] ;
}
void F_65 ( void * V_222 )
{
int V_25 ;
struct V_132 * V_35 = (struct V_132 * ) V_222 ;
struct V_2 * V_3 ;
struct V_1 * V_4 ;
T_1 V_223 ;
T_3 V_224 ;
struct V_119 * V_225 ;
unsigned char * V_226 ;
int V_227 = V_9 ;
struct V_4 * V_5 ;
if ( V_35 -> V_228 != NULL )
V_3 = V_35 -> V_228 -> V_229 ;
else
V_3 = V_35 -> V_229 ;
V_4 = F_11 ( V_3 ) ;
if ( ! V_4 )
return;
V_5 = V_4 -> V_5 ;
V_226 = F_66 ( V_35 ) ;
do {
V_25 = F_67 ( V_35 , V_226 , V_227 ,
& V_223 , & V_224 ) ;
if ( V_25 == 0 ) {
if ( V_223 > 0 ) {
V_225 = (struct V_119 * ) V_226 ;
switch ( V_225 -> type ) {
case V_200 :
F_41 ( V_4 ,
V_3 , V_225 ) ;
break;
case V_205 :
F_62 ( V_4 , V_35 ,
V_3 , V_225 ) ;
break;
case V_36 :
F_64 ( V_3 , V_225 ) ;
break;
default:
F_15 ( V_5 ,
L_33
L_34 ,
V_225 -> type , V_224 ,
V_223 ) ;
break;
}
} else {
break;
}
} else if ( V_25 == - V_230 ) {
if ( V_227 > V_9 )
F_4 ( V_226 ) ;
V_226 = F_68 ( V_223 , V_231 ) ;
if ( V_226 == NULL ) {
F_15 ( V_5 ,
L_35
L_36 , V_223 ) ;
break;
}
V_227 = V_223 ;
}
} while ( 1 );
if ( V_227 > V_9 )
F_4 ( V_226 ) ;
return;
}
int F_69 ( struct V_2 * V_3 , void * V_232 )
{
int V_25 = 0 ;
int V_233 =
( (struct V_234 * ) V_232 ) -> V_233 ;
struct V_1 * V_4 ;
struct V_4 * V_5 ;
V_4 = F_1 ( V_3 ) ;
if ( ! V_4 )
return - V_53 ;
V_4 -> V_233 = V_233 ;
V_5 = V_4 -> V_5 ;
V_4 -> V_235 = F_70 ( V_5 ) ;
F_71 ( & V_4 -> V_60 ) ;
F_72 ( V_3 -> V_35 , V_4 -> V_8 ) ;
V_25 = F_73 ( V_3 -> V_35 , V_233 * V_236 ,
V_233 * V_236 , NULL , 0 ,
F_65 , V_3 -> V_35 ) ;
if ( V_25 != 0 ) {
F_15 ( V_5 , L_37 , V_25 ) ;
goto V_54;
}
F_74 ( L_38 ) ;
V_4 -> V_191 [ 0 ] = V_3 -> V_35 ;
V_25 = F_29 ( V_3 ) ;
if ( V_25 != 0 ) {
F_15 ( V_5 ,
L_39 , V_25 ) ;
goto V_237;
}
return V_25 ;
V_237:
F_36 ( V_3 -> V_35 ) ;
V_54:
F_9 ( V_4 ) ;
return V_25 ;
}
