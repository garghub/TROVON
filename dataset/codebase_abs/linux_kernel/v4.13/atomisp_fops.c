static int F_1 ( struct V_1 * V_2 , unsigned int * V_3 ,
unsigned int * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
* V_4 = V_6 -> V_8 . V_9 ;
return 0 ;
}
static int F_2 ( struct V_1 * V_2 ,
struct V_10 * V_11 ,
enum V_12 V_13 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
V_11 -> V_4 = V_6 -> V_8 . V_9 ;
V_11 -> V_14 = V_6 -> V_8 . V_14 ;
V_11 -> V_15 = V_6 -> V_8 . V_15 ;
V_11 -> V_13 = V_13 ;
V_11 -> V_16 = V_17 ;
return 0 ;
}
static int F_3 ( struct V_18 * V_19 ,
enum V_20 V_21 ,
enum V_22 V_23 )
{
struct V_24 * V_25 ;
enum V_26 V_27 =
F_4 ( V_19 , V_23 ) ;
struct V_28 * V_29 ;
if ( V_19 -> V_30 [ V_21 ] [ V_23 ] >=
V_31 )
return 0 ;
if ( ! F_5 ( & V_19 -> V_32 [ V_27 ] ) ) {
V_29 = & V_19 -> V_32 [ V_27 ] ;
} else if ( ! F_5 ( & V_19 -> V_33 [ V_27 ] ) ) {
V_29 = & V_19 -> V_33 [ V_27 ] ;
} else {
F_6 ( V_19 -> V_34 -> V_35 , L_1 ,
V_36 , V_27 ) ;
return - V_37 ;
}
V_25 = F_7 ( V_29 -> V_38 ,
struct V_24 , V_39 ) ;
F_8 ( & V_25 -> V_39 ) ;
if ( F_9 ( V_19 , V_25 ,
V_21 , V_23 ) ) {
F_10 ( & V_25 -> V_39 , V_29 ) ;
return - V_37 ;
} else {
F_11 ( & V_25 -> V_39 ,
& V_19 -> V_40 [ V_27 ] ) ;
}
V_19 -> V_30 [ V_21 ] [ V_23 ] ++ ;
return 0 ;
}
static int F_12 ( struct V_18 * V_19 ,
enum V_20 V_21 ,
enum V_22 V_23 )
{
struct V_41 * V_42 ;
struct V_28 * V_43 ;
unsigned int V_44 ;
if ( V_19 -> V_45 [ V_23 ] >= V_31 )
return 0 ;
if ( ! F_5 ( & V_19 -> V_46 ) ) {
V_43 = & V_19 -> V_46 ;
} else if ( ! F_5 ( & V_19 -> V_47 ) ) {
V_43 = & V_19 -> V_47 ;
} else {
F_6 ( V_19 -> V_34 -> V_35 , L_2 ,
V_36 ) ;
return - V_37 ;
}
V_42 = F_7 ( V_43 -> V_38 , struct V_41 , V_39 ) ;
F_8 ( & V_42 -> V_39 ) ;
V_44 = V_42 -> V_48 -> V_44 ;
F_13 ( V_42 -> V_48 -> V_49 ) ;
if ( F_14 ( V_19 , V_42 ,
V_21 , V_23 ) ) {
F_10 ( & V_42 -> V_39 , V_43 ) ;
return - V_37 ;
} else {
F_11 ( & V_42 -> V_39 , & V_19 -> V_50 ) ;
if ( V_43 == & V_19 -> V_47 )
F_6 ( V_19 -> V_34 -> V_35 , L_3 ,
V_36 , V_44 ) ;
}
V_19 -> V_45 [ V_23 ] ++ ;
return 0 ;
}
static int F_15 ( struct V_18 * V_19 ,
enum V_20 V_21 ,
enum V_22 V_23 )
{
struct V_51 * V_52 ;
unsigned long V_53 ;
if ( V_19 -> V_54 >= V_31 )
return 0 ;
F_16 ( & V_19 -> V_55 , V_53 ) ;
if ( F_5 ( & V_19 -> V_56 ) ) {
F_17 ( & V_19 -> V_55 , V_53 ) ;
F_6 ( V_19 -> V_34 -> V_35 , L_4 ,
V_36 ) ;
return - V_37 ;
}
V_52 = F_7 ( V_19 -> V_56 . V_57 ,
struct V_51 , V_39 ) ;
F_8 ( & V_52 -> V_39 ) ;
F_17 ( & V_19 -> V_55 , V_53 ) ;
F_13 ( V_52 -> V_58 -> V_49 ) ;
if ( F_18 ( V_19 , V_52 ,
V_21 , V_23 ) ) {
F_16 ( & V_19 -> V_55 , V_53 ) ;
F_11 ( & V_52 -> V_39 , & V_19 -> V_56 ) ;
F_17 ( & V_19 -> V_55 , V_53 ) ;
return - V_37 ;
} else {
F_16 ( & V_19 -> V_55 , V_53 ) ;
F_11 ( & V_52 -> V_39 , & V_19 -> V_59 ) ;
F_17 ( & V_19 -> V_55 , V_53 ) ;
}
V_19 -> V_54 ++ ;
return 0 ;
}
int F_19 ( struct V_18 * V_19 ,
struct V_5 * V_6 ,
enum V_20 V_21 ,
enum V_60 V_61 ,
enum V_22 V_23 )
{
struct V_62 * V_63 ;
struct V_64 * V_65 ;
struct V_66 * V_67 =
F_20 ( & V_19 -> V_68 . V_69 ) ;
unsigned long V_53 ;
int V_70 = 0 ;
while ( V_6 -> V_71 < V_31 ) {
struct V_10 * V_11 ;
F_16 ( & V_6 -> V_72 , V_53 ) ;
if ( F_5 ( & V_6 -> V_73 ) ) {
F_17 ( & V_6 -> V_72 , V_53 ) ;
return - V_37 ;
}
V_11 = F_7 ( V_6 -> V_73 . V_38 ,
struct V_10 , V_74 ) ;
F_8 ( & V_11 -> V_74 ) ;
V_11 -> V_16 = V_75 ;
F_17 ( & V_6 -> V_72 , V_53 ) ;
V_63 = V_11 -> V_76 ;
V_65 = V_6 -> V_77 [ V_11 -> V_78 ] ;
if ( V_65 ) {
F_21 ( V_19 ,
& V_19 -> V_68 . V_79 . V_80 ,
& V_65 -> V_68 ) ;
F_22 ( V_19 , & V_65 -> V_68 ) ;
if ( V_65 -> V_68 . V_80 . V_81 &&
V_19 -> V_82 -> V_83 != V_84 ) {
V_70 = F_23 ( V_19 ,
& V_65 -> V_68 . V_81 , V_23 ) ;
if ( ! V_70 )
F_24 ( V_19 ,
& V_65 -> V_68 . V_81 ) ;
}
F_25 ( V_19 ,
V_63 -> V_85 ) ;
F_26 ( V_19 ,
V_19 -> V_86 [ V_21 ] . V_87 [ V_23 ] ) ;
V_19 -> V_68 . V_88 = (struct V_89 * )
V_65 -> V_68 . V_88 ;
if ( V_65 -> V_68 . V_80 . V_81 &&
V_19 -> V_82 -> V_83 != V_84
&& ! V_70 ) {
memcpy ( & V_19 -> V_68 . V_79 . V_81 ,
& V_65 -> V_68 . V_81 ,
sizeof( struct V_90 ) ) ;
V_19 -> V_68 . V_79 . V_80 . V_81 =
(struct V_91 * )
& V_19 -> V_68 . V_79 . V_81 ;
V_19 -> V_68 . V_92 = true ;
}
}
V_70 = F_27 ( V_19 , V_63 , V_21 ,
V_61 , V_23 ) ;
if ( V_70 ) {
F_16 ( & V_6 -> V_72 , V_53 ) ;
F_11 ( & V_11 -> V_74 , & V_6 -> V_73 ) ;
V_11 -> V_16 = V_93 ;
F_17 ( & V_6 -> V_72 , V_53 ) ;
F_28 ( V_19 -> V_34 -> V_35 , L_5 ,
V_36 , V_70 ) ;
return - V_37 ;
}
V_6 -> V_71 ++ ;
if ( V_19 -> V_68 . V_69 . V_94 . V_95 &&
V_23 == V_19 -> V_68 . V_96 &&
V_61 == V_97 )
F_12 ( V_19 , V_21 ,
V_23 ) ;
if ( V_19 -> V_86 [ V_98 ] . V_99 .
V_100 . V_4 &&
V_61 == V_97 )
F_3 ( V_19 , V_21 ,
V_23 ) ;
if ( V_67 && V_67 -> V_95 &&
V_23 == V_101 &&
V_61 == V_97 )
F_15 ( V_19 , V_21 ,
V_23 ) ;
}
return 0 ;
}
static int F_29 ( struct V_18 * V_19 ,
enum V_22 V_102 ,
T_1 V_103 )
{
if ( F_30 ( V_19 ) ) {
if ( V_19 -> V_104 -> V_83 &&
V_19 -> V_82 -> V_83 == V_105 ) {
if ( V_103 == V_106 )
return V_97 ;
else if ( V_103 == V_107 )
return V_108 ;
else
return V_109 ;
}
if ( V_19 -> V_104 -> V_83 &&
V_19 -> V_82 -> V_83 == V_84 ) {
if ( V_103 == V_106 )
return V_97 ;
else if ( V_103 == V_107 )
return V_110 ;
else if ( V_103 == V_111 )
return V_108 ;
else
return V_109 ;
}
if ( V_103 == V_106 ||
V_103 == V_111 ||
( V_103 == V_107 &&
V_19 -> V_82 -> V_83 != V_84 ) )
return V_97 ;
else
return V_109 ;
}
if ( V_102 == V_112 ||
V_103 == V_106 ||
V_103 == V_111 ||
( V_103 == V_107 &&
V_19 -> V_82 -> V_83 != V_84 ) )
return V_97 ;
else
return V_109 ;
}
static int F_31 ( struct V_18 * V_19 )
{
enum V_60 V_113 ;
enum V_22 V_114 = V_112 ;
enum V_22 V_115 = V_112 ;
enum V_22 V_116 = V_112 ;
enum V_20 V_117 ;
struct V_5 * V_118 ;
struct V_5 * V_119 ;
struct V_5 * V_120 ;
V_118 = & V_19 -> V_121 ;
V_119 = & V_19 -> V_122 ;
V_120 = & V_19 -> V_123 ;
V_113 = F_29 (
V_19 , V_115 ,
F_32 ( & V_119 -> V_124 ) ) ;
V_117 = V_125 ;
F_19 ( V_19 , V_119 ,
V_117 ,
V_113 , V_115 ) ;
V_113 = F_29 ( V_19 , V_114 ,
F_32 ( & V_118 -> V_124 ) ) ;
V_117 = V_98 ;
F_19 ( V_19 , V_118 ,
V_117 ,
V_113 , V_114 ) ;
V_113 = F_29 ( V_19 , V_116 ,
F_32 ( & V_120 -> V_124 ) ) ;
V_117 = V_126 ;
F_19 ( V_19 , V_120 ,
V_117 ,
V_113 , V_116 ) ;
return 0 ;
}
int F_33 ( struct V_18 * V_19 )
{
enum V_60 V_113 ;
enum V_22 V_114 = V_127 ;
enum V_22 V_115 = V_127 ;
enum V_22 V_116 = V_127 ;
enum V_20 V_117 ;
struct V_5 * V_118 = NULL ;
struct V_5 * V_128 = NULL ;
struct V_5 * V_119 = NULL ;
struct V_5 * V_120 = NULL ;
bool V_129 = F_34 (
V_19 -> V_130 [ V_19 -> V_131 ] . V_130 . V_132 ) ;
if ( V_19 -> V_34 -> V_133 [ V_19 -> V_134 ] . V_135 ->
V_136 [ V_19 -> V_137 ] . V_138 == 2 &&
! V_19 -> V_139 )
return F_31 ( V_19 ) ;
if ( V_19 -> V_140 -> V_83 == V_141 ) {
V_120 = & V_19 -> V_123 ;
V_116 = V_101 ;
} else if ( V_19 -> V_140 -> V_83 == V_142 ) {
V_119 = & V_19 -> V_121 ;
V_115 = V_143 ;
} else if ( V_19 -> V_82 -> V_83 == V_84 ) {
if ( V_19 -> V_104 -> V_83 ) {
V_118 = & V_19 -> V_121 ;
V_128 = & V_19 -> V_144 ;
V_114 = V_143 ;
}
V_120 = & V_19 -> V_123 ;
V_119 = & V_19 -> V_122 ;
V_116 = V_101 ;
V_115 = V_101 ;
} else if ( V_19 -> V_104 -> V_83 ) {
V_118 = & V_19 -> V_121 ;
V_128 = & V_19 -> V_144 ;
V_119 = & V_19 -> V_122 ;
V_115 = V_145 ;
V_114 = V_143 ;
} else if ( V_19 -> V_82 -> V_83 == V_105 ) {
V_119 = & V_19 -> V_122 ;
V_115 = V_145 ;
} else {
V_118 = & V_19 -> V_121 ;
if ( ! V_129 )
V_128 = & V_19 -> V_144 ;
V_114 = V_143 ;
}
#ifdef F_35
if ( V_19 -> V_146 ) {
V_114 = V_112 ;
V_115 = V_112 ;
V_116 = V_112 ;
}
#endif
if ( V_19 -> V_139 ) {
V_118 = & V_19 -> V_121 ;
V_120 = & V_19 -> V_123 ;
V_119 = & V_19 -> V_122 ;
V_114 = V_112 ;
V_116 = V_147 ;
V_115 = V_147 ;
}
if ( V_118 ) {
V_113 = F_29 (
V_19 , V_114 ,
F_32 ( & V_118 -> V_124 ) ) ;
V_117 = V_98 ;
if ( F_30 ( V_19 ) )
V_114 = V_147 ;
F_19 ( V_19 , V_118 ,
V_117 ,
V_113 , V_114 ) ;
}
if ( V_128 ) {
V_113 = F_29 (
V_19 , V_114 ,
F_32 ( & V_128 -> V_124 ) ) ;
if ( V_19 -> V_86 [ V_148 ] . V_149 )
V_117 = V_148 ;
else
V_117 = V_98 ;
if ( F_30 ( V_19 ) )
V_114 = V_147 ;
F_19 ( V_19 , V_128 ,
V_117 ,
V_113 , V_114 ) ;
}
if ( V_119 ) {
V_113 = F_29 (
V_19 , V_115 ,
F_32 ( & V_119 -> V_124 ) ) ;
if ( F_36 ( V_19 ) && V_115 == V_147 )
V_117 = V_98 ;
else if ( V_115 == V_147 )
V_117 = V_126 ;
else if ( V_19 -> V_86 [ V_125 ] . V_149 )
V_117 = V_125 ;
else
V_117 = V_98 ;
if ( F_30 ( V_19 ) )
V_115 = V_147 ;
F_19 ( V_19 , V_119 ,
V_117 ,
V_113 , V_115 ) ;
}
if ( V_120 ) {
V_113 = F_29 (
V_19 , V_116 ,
F_32 ( & V_120 -> V_124 ) ) ;
if ( V_19 -> V_86 [ V_126 ] . V_149 )
V_117 = V_126 ;
else
V_117 = V_98 ;
if ( F_30 ( V_19 ) )
V_116 = V_147 ;
F_19 ( V_19 , V_120 ,
V_117 ,
V_113 , V_116 ) ;
}
return 0 ;
}
static void F_37 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
if ( ! F_38 ( V_6 ) &&
( V_6 -> V_150 [ V_11 -> V_78 ] ||
! F_5 ( & V_6 -> V_151 ) ) )
F_11 ( & V_11 -> V_74 , & V_6 -> V_151 ) ;
else
F_11 ( & V_11 -> V_74 , & V_6 -> V_73 ) ;
V_11 -> V_16 = V_93 ;
}
static void F_39 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
V_11 -> V_16 = V_152 ;
F_40 ( V_11 ) ;
}
static int F_41 ( struct V_1 * V_2 ,
unsigned int * V_3 , unsigned int * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
* V_4 = V_6 -> V_8 . V_9 ;
return 0 ;
}
static int F_42 ( struct V_1 * V_2 ,
struct V_10 * V_11 ,
enum V_12 V_13 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
V_11 -> V_4 = V_6 -> V_8 . V_9 ;
V_11 -> V_14 = V_6 -> V_8 . V_14 ;
V_11 -> V_15 = V_6 -> V_8 . V_15 ;
V_11 -> V_13 = V_13 ;
V_11 -> V_16 = V_17 ;
return 0 ;
}
static void F_43 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
F_11 ( & V_11 -> V_74 , & V_6 -> V_153 ) ;
V_11 -> V_16 = V_93 ;
}
static void F_44 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
F_45 ( V_11 ) ;
V_11 -> V_16 = V_152 ;
}
static int F_46 ( struct V_5 * V_6 )
{
F_47 ( & V_6 -> V_72 ) ;
F_48 ( & V_6 -> V_154 , & V_155 , NULL ,
& V_6 -> V_72 ,
V_156 ,
V_157 ,
sizeof( struct V_158 ) , V_6 ,
NULL ) ;
F_48 ( & V_6 -> V_159 , & V_160 , NULL ,
& V_6 -> V_72 ,
V_161 ,
V_157 ,
sizeof( struct V_158 ) , V_6 ,
NULL ) ;
F_49 ( & V_6 -> V_73 ) ;
F_49 ( & V_6 -> V_153 ) ;
F_49 ( & V_6 -> V_151 ) ;
F_49 ( & V_6 -> V_162 ) ;
memset ( V_6 -> V_150 , 0 ,
V_163 * sizeof( unsigned int ) ) ;
memset ( V_6 -> V_77 , 0 ,
V_163 *
sizeof( struct V_64 * ) ) ;
return 0 ;
}
static void F_50 ( struct V_164 * V_34 )
{
unsigned int V_78 ;
V_34 -> V_165 . V_166 = 0 ;
V_34 -> V_167 = true ;
V_34 -> V_168 = false ;
V_34 -> V_169 = 0 ;
for ( V_78 = 0 ; V_78 < V_34 -> V_170 ; V_78 ++ )
V_34 -> V_133 [ V_78 ] . V_19 = NULL ;
V_34 -> V_165 . V_171 = V_172 ;
}
static void F_51 ( struct V_18 * V_19 )
{
F_52 ( V_19 -> V_82 , V_173 ) ;
memset ( & V_19 -> V_68 . V_79 , 0 , sizeof( V_19 -> V_68 . V_79 ) ) ;
V_19 -> V_68 . V_174 = V_175 ;
V_19 -> V_68 . V_176 = 1 ;
V_19 -> V_68 . V_177 = 0 ;
V_19 -> V_68 . V_178 = 0 ;
V_19 -> V_68 . V_179 = 0 ;
V_19 -> V_68 . V_180 = 0 ;
V_19 -> V_68 . V_181 = 0 ;
V_19 -> V_68 . V_182 = 0 ;
V_19 -> V_68 . V_183 = 1 ;
V_19 -> V_68 . V_184 = 0 ;
V_19 -> V_68 . V_96 = V_127 ;
V_19 -> V_68 . V_185 . V_186 = 1 ;
V_19 -> V_68 . V_185 . V_187 = 0 ;
V_19 -> V_68 . V_185 . V_188 = 0 ;
V_19 -> V_189 = V_190 ;
V_19 -> V_134 = 0 ;
V_19 -> V_169 = 0 ;
V_19 -> V_146 = false ;
V_19 -> V_139 = false ;
V_19 -> V_191 = false ;
V_19 -> V_192 = false ;
V_19 -> V_193 . V_15 = 0 ;
V_19 -> V_193 . V_14 = 0 ;
F_53 ( V_19 ) ;
}
static unsigned int F_54 ( struct V_18 * V_19 )
{
return V_19 -> V_122 . V_194 +
V_19 -> V_144 . V_194 +
V_19 -> V_121 . V_194 +
V_19 -> V_123 . V_194 +
V_19 -> V_195 . V_194 +
V_19 -> V_196 . V_194 ;
}
unsigned int F_55 ( struct V_164 * V_34 )
{
unsigned int V_78 , V_197 ;
for ( V_78 = 0 , V_197 = 0 ; V_78 < V_34 -> V_198 ; V_78 ++ )
V_197 += F_54 ( & V_34 -> V_19 [ V_78 ] ) ;
return V_197 ;
}
static int F_56 ( struct V_199 * V_199 )
{
struct V_200 * V_124 = F_57 ( V_199 ) ;
struct V_164 * V_34 = F_58 ( V_124 ) ;
struct V_5 * V_6 = NULL ;
struct V_201 * V_202 = NULL ;
struct V_18 * V_19 ;
bool V_203 = false ;
int V_204 ;
F_59 ( V_34 -> V_35 , L_6 , V_124 -> V_205 ) ;
F_60 ( & V_34 -> V_206 ) ;
V_203 = ! strncmp ( V_124 -> V_205 , L_7 ,
sizeof( V_124 -> V_205 ) ) ;
if ( V_203 ) {
V_202 = F_61 ( V_124 ) ;
V_19 = V_202 -> V_19 ;
} else {
V_6 = F_62 ( V_124 ) ;
V_19 = V_6 -> V_19 ;
}
V_19 -> V_207 . V_208 = V_124 ;
if ( V_34 -> V_209 . V_210 . V_211 == 0 ) {
V_34 -> V_212 = F_63 ( V_34 ) ;
if ( ! V_34 -> V_212 ) {
F_28 ( V_34 -> V_35 , L_8 ) ;
V_204 = - V_213 ;
goto error;
}
V_204 = F_64 ( V_34 ) ;
if ( V_204 ) {
F_28 ( V_34 -> V_35 , L_9 ) ;
goto error;
}
F_65 ( V_34 -> V_212 ) ;
V_34 -> V_212 = NULL ;
V_34 -> V_209 . V_210 . V_214 = NULL ;
}
if ( V_203 && V_202 -> V_194 ) {
F_59 ( V_34 -> V_35 , L_10 ) ;
F_66 ( & V_34 -> V_206 ) ;
return - V_215 ;
} else if ( V_203 ) {
goto V_216;
}
if ( ! V_34 -> V_170 ) {
F_28 ( V_34 -> V_35 , L_11 ) ;
V_204 = - V_37 ;
goto error;
}
if ( V_6 -> V_194 ) {
F_59 ( V_34 -> V_35 , L_12 ) ;
F_66 ( & V_34 -> V_206 ) ;
return - V_215 ;
}
V_204 = F_46 ( V_6 ) ;
if ( V_204 )
goto error;
V_216:
if ( F_55 ( V_34 ) ) {
F_59 ( V_34 -> V_35 , L_13 ) ;
goto V_217;
}
V_204 = F_67 ( V_124 -> V_218 -> V_35 ) ;
if ( V_204 < 0 ) {
F_28 ( V_34 -> V_35 , L_14 ) ;
goto error;
}
if ( V_219 ) {
V_204 = F_68 ( V_220 , V_221 ) ;
if ( V_204 )
F_28 ( V_34 -> V_35 , L_15 ) ;
}
if ( F_69 ( V_34 ) ) {
V_204 = - V_37 ;
goto V_222;
}
F_50 ( V_34 ) ;
V_204 = F_70 ( V_34 -> V_223 , V_224 , V_225 , 1 ) ;
if ( V_204 < 0 && V_204 != - V_226 && V_204 != - V_227 ) {
F_28 ( V_34 -> V_35 , L_16 ) ;
goto V_222;
}
V_217:
if ( F_54 ( V_19 ) )
goto V_228;
F_51 ( V_19 ) ;
V_228:
if ( V_203 )
V_202 -> V_194 ++ ;
else
V_6 -> V_194 ++ ;
F_66 ( & V_34 -> V_206 ) ;
return 0 ;
V_222:
F_71 ( V_34 ) ;
error:
F_72 ( V_221 ) ;
F_73 ( V_124 -> V_218 -> V_35 ) ;
F_66 ( & V_34 -> V_206 ) ;
return V_204 ;
}
static int F_74 ( struct V_199 * V_199 )
{
struct V_200 * V_124 = F_57 ( V_199 ) ;
struct V_164 * V_34 = F_58 ( V_124 ) ;
struct V_5 * V_6 ;
struct V_201 * V_202 ;
struct V_18 * V_19 ;
bool V_203 ;
struct V_229 V_230 ;
struct V_231 V_232 ;
struct V_233 V_234 = { 0 } ;
int V_204 = 0 ;
F_75 ( & V_232 . V_235 , V_124 ) ;
V_230 . V_3 = 0 ;
if ( V_34 == NULL )
return - V_236 ;
F_76 ( & V_34 -> V_237 ) ;
F_60 ( & V_34 -> V_206 ) ;
F_59 ( V_34 -> V_35 , L_17 , V_124 -> V_205 ) ;
V_203 = ! strncmp ( V_124 -> V_205 , L_7 ,
sizeof( V_124 -> V_205 ) ) ;
if ( V_203 ) {
V_202 = F_61 ( V_124 ) ;
V_19 = V_202 -> V_19 ;
} else {
V_6 = F_62 ( V_124 ) ;
V_19 = V_6 -> V_19 ;
}
V_19 -> V_207 . V_208 = V_124 ;
if ( V_203 ) {
V_202 -> V_194 -- ;
goto V_238;
}
V_6 -> V_194 -- ;
if ( V_6 -> V_154 . V_239 )
F_6 ( V_34 -> V_35 ,
L_18 ,
V_36 ) ;
if ( V_6 -> V_154 . V_239 &&
F_77 ( V_199 , NULL , V_156 ) ) {
F_28 ( V_34 -> V_35 ,
L_19 ) ;
goto V_228;
}
if ( V_6 -> V_194 )
goto V_228;
if ( F_78 ( V_199 , NULL , & V_230 ) ) {
F_28 ( V_34 -> V_35 ,
L_20 ) ;
goto V_228;
}
if ( V_6 -> V_159 . V_240 [ 0 ] ) {
F_76 ( & V_6 -> V_159 . V_241 ) ;
F_79 ( & V_6 -> V_159 ) ;
F_80 ( & V_6 -> V_159 . V_241 ) ;
}
if ( ! V_34 -> V_165 . V_166 && V_19 -> V_242 -> V_83 ) {
struct V_243 V_244 = { 0 } ;
F_81 ( & V_19 -> V_207 , V_232 . V_245 ,
V_246 ,
V_247 , & V_244 ) ;
}
V_238:
if ( F_54 ( V_19 ) )
goto V_228;
if ( V_34 -> V_165 . V_166 && V_19 -> V_242 -> V_83 ) {
struct V_243 V_244 = { 0 } ;
F_81 ( & V_19 -> V_207 , V_232 . V_245 ,
V_246 ,
V_247 , & V_244 ) ;
}
F_82 ( V_19 ) ;
F_83 ( V_19 ) ;
V_204 = F_70 ( V_34 -> V_133 [ V_19 -> V_134 ] . V_248 ,
V_224 , V_225 , 0 ) ;
if ( V_204 )
F_6 ( V_34 -> V_35 , L_21 ) ;
V_34 -> V_133 [ V_19 -> V_134 ] . V_19 = NULL ;
V_19 -> V_239 = V_249 ;
if ( F_55 ( V_34 ) )
goto V_228;
F_84 ( V_19 ) ;
F_85 ( V_19 ) ;
F_71 ( V_34 ) ;
if ( V_250 ) {
F_86 ( V_34 ) ;
V_34 -> V_209 . V_210 . V_214 = NULL ;
V_34 -> V_209 . V_210 . V_211 = 0 ;
}
F_72 ( V_221 ) ;
V_204 = F_70 ( V_34 -> V_223 , V_224 , V_225 , 0 ) ;
if ( V_204 < 0 && V_204 != - V_226 && V_204 != - V_227 )
F_6 ( V_34 -> V_35 , L_22 ) ;
if ( F_87 ( V_124 -> V_218 -> V_35 ) < 0 )
F_28 ( V_34 -> V_35 , L_23 ) ;
V_228:
if ( ! V_203 ) {
F_88 ( & V_19 -> V_207 , V_232 . V_245 ,
V_246 ,
F_32 ( V_124 ) ,
V_251 , 0 ,
& V_234 ) ;
}
F_66 ( & V_34 -> V_206 ) ;
F_80 ( & V_34 -> V_237 ) ;
return 0 ;
}
static int F_89 ( struct V_164 * V_34 ,
struct V_252 * V_253 ,
T_2 V_254 , T_3 V_255 , T_3 V_256 )
{
T_3 V_257 ;
while ( V_256 ) {
V_257 = F_90 ( V_254 ) >> V_258 ;
if ( F_91 ( V_253 , V_255 , V_257 ,
V_259 , V_260 ) ) {
F_28 ( V_34 -> V_35 , L_24 ) ;
return - V_261 ;
}
V_254 += V_259 ;
V_255 += V_259 ;
V_256 -- ;
}
return 0 ;
}
static int F_92 ( struct V_164 * V_34 ,
const struct V_262 * V_263 , struct V_252 * V_253 )
{
T_2 V_254 ;
T_3 V_255 ;
T_3 V_256 ;
if ( ! V_263 ) {
F_28 ( V_34 -> V_35 , L_25 , V_36 ) ;
return - V_37 ;
}
V_255 = V_253 -> V_264 ;
V_254 = V_263 -> V_214 ;
F_93 ( V_34 , V_263 , & V_256 ) ;
if ( F_89 ( V_34 , V_253 , V_254 , V_255 , V_256 ) )
return - V_261 ;
return 0 ;
}
int F_94 ( struct V_1 * V_265 ,
struct V_252 * V_253 )
{
T_3 V_188 = V_253 -> V_266 << V_258 ;
int V_204 = - V_37 , V_78 ;
struct V_164 * V_34 =
( (struct V_5 * ) ( V_265 -> V_7 ) ) -> V_34 ;
struct V_62 * V_63 ;
struct V_267 * V_268 ;
F_95 ( V_265 -> V_269 -> V_270 , V_271 ) ;
if ( ! ( V_253 -> V_272 & V_273 ) || ! ( V_253 -> V_272 & V_274 ) ) {
F_28 ( V_34 -> V_35 , L_26 ) ;
return - V_37 ;
}
F_76 ( & V_265 -> V_241 ) ;
for ( V_78 = 0 ; V_78 < V_163 ; V_78 ++ ) {
struct V_10 * V_275 = V_265 -> V_240 [ V_78 ] ;
if ( V_275 == NULL )
continue;
V_268 = F_96 ( sizeof( struct V_267 ) , V_276 ) ;
if ( ! V_268 ) {
F_80 ( & V_265 -> V_241 ) ;
return - V_277 ;
}
V_275 -> V_268 = V_268 ;
V_268 -> V_265 = V_265 ;
V_275 -> V_278 = V_253 -> V_264 ;
if ( V_275 && V_275 -> V_279 == V_280 &&
V_275 -> V_281 == V_188 ) {
V_63 = V_275 -> V_76 ;
V_204 = F_92 ( V_34 , V_63 -> V_85 , V_253 ) ;
V_253 -> V_272 |= V_282 | V_283 | V_284 ;
break;
}
}
F_80 ( & V_265 -> V_241 ) ;
return V_204 ;
}
static int F_97 ( struct V_164 * V_34 ,
struct V_262 * V_285 , T_4 V_14 , T_4 V_15 )
{
unsigned int V_78 ;
unsigned short * V_286 ;
int V_204 = 0 ;
T_2 V_287 = V_285 -> V_214 ;
T_2 V_288 = V_287 ;
V_286 = F_98 ( V_14 * sizeof( V_287 ) , V_276 ) ;
if ( ! V_286 ) {
F_28 ( V_34 -> V_35 , L_27 ) ;
return - V_277 ;
}
V_287 += V_289 ;
for ( V_78 = 0 ; V_78 < V_15 ; V_78 ++ ) {
V_204 = F_99 ( V_287 , V_286 , V_14 * sizeof( V_287 ) ) ;
if ( V_204 < 0 )
goto V_290;
V_204 = F_100 ( V_288 , V_286 , V_14 * sizeof( V_288 ) ) ;
if ( V_204 < 0 )
goto V_290;
V_287 += V_285 -> V_291 . V_292 ;
V_288 += V_14 ;
}
V_290:
F_101 ( V_286 ) ;
return V_204 ;
}
static int F_102 ( struct V_199 * V_199 , struct V_252 * V_253 )
{
struct V_200 * V_124 = F_57 ( V_199 ) ;
struct V_164 * V_34 = F_58 ( V_124 ) ;
struct V_5 * V_6 = F_62 ( V_124 ) ;
struct V_18 * V_19 = V_6 -> V_19 ;
struct V_262 * V_293 ;
T_3 V_294 = V_253 -> V_264 ;
T_3 V_295 = V_253 -> V_296 ;
T_3 V_4 = V_295 - V_294 ;
T_3 V_297 , V_298 ;
int V_204 ;
if ( ! ( V_253 -> V_272 & ( V_273 | V_299 ) ) )
return - V_300 ;
F_60 ( & V_34 -> V_206 ) ;
if ( ! ( V_253 -> V_272 & V_274 ) ) {
V_253 -> V_272 |= V_274 ;
V_204 = F_103 ( V_253 , V_253 -> V_266 << V_258 ) ;
F_66 ( & V_34 -> V_206 ) ;
return V_204 ;
}
if ( F_32 ( V_124 )
== V_106 &&
V_253 -> V_266 == ( V_301 >> V_258 ) ) {
V_298 = V_6 -> V_8 . V_14 * V_6 -> V_8 . V_15 * 2 ;
if ( V_19 -> V_68 . V_183 != 0 ) {
V_204 = - V_37 ;
goto error;
}
V_293 = V_19 -> V_302 ;
if ( V_293 == NULL ) {
F_28 ( V_34 -> V_35 , L_28 ) ;
V_204 = - V_37 ;
goto error;
}
V_204 = F_97 ( V_34 , V_293 ,
V_6 -> V_8 . V_14 , V_6 -> V_8 . V_15 ) ;
if ( V_204 < 0 ) {
F_28 ( V_34 -> V_35 , L_29 ) ;
goto error;
}
V_297 = V_293 -> V_303 ;
V_293 -> V_303 = V_298 ;
if ( V_4 != F_104 ( V_298 ) ) {
F_28 ( V_34 -> V_35 , L_30 ) ;
V_204 = - V_37 ;
goto error;
}
if ( F_92 ( V_34 , V_293 , V_253 ) ) {
F_28 ( V_34 -> V_35 , L_31 ) ;
V_293 -> V_303 = V_297 ;
V_204 = - V_261 ;
goto error;
}
V_293 -> V_303 = V_297 ;
V_253 -> V_272 |= V_282 | V_283 | V_284 ;
F_66 ( & V_34 -> V_206 ) ;
return 0 ;
}
if ( V_4 != V_6 -> V_8 . V_9 ) {
F_28 ( V_34 -> V_35 , L_32 ) ;
V_204 = - V_37 ;
goto error;
}
F_66 ( & V_34 -> V_206 ) ;
return F_94 ( & V_6 -> V_154 , V_253 ) ;
error:
F_66 ( & V_34 -> V_206 ) ;
return V_204 ;
}
static int F_105 ( struct V_199 * V_199 , struct V_252 * V_253 )
{
struct V_200 * V_124 = F_57 ( V_199 ) ;
struct V_5 * V_6 = F_62 ( V_124 ) ;
return F_106 ( & V_6 -> V_159 , V_253 ) ;
}
static unsigned int F_107 ( struct V_199 * V_199 ,
struct V_304 * V_305 )
{
struct V_200 * V_124 = F_57 ( V_199 ) ;
struct V_164 * V_34 = F_58 ( V_124 ) ;
struct V_5 * V_6 = F_62 ( V_124 ) ;
F_60 ( & V_34 -> V_206 ) ;
if ( V_6 -> V_154 . V_239 != 1 ) {
F_66 ( & V_34 -> V_206 ) ;
return V_306 ;
}
F_66 ( & V_34 -> V_206 ) ;
return F_108 ( V_199 , & V_6 -> V_154 , V_305 ) ;
}
