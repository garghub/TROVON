static void F_1 ( T_1 V_1 )
{
F_2 ( L_1 ) ;
if ( V_1 & V_2 )
F_2 ( L_2 ) ;
if ( V_1 & V_3 )
F_2 ( L_3 ) ;
if ( V_1 & V_4 )
F_2 ( L_4 ) ;
if ( V_1 & V_5 )
F_2 ( L_5 ) ;
if ( V_1 & V_6 )
F_2 ( L_6 ) ;
if ( V_1 & V_7 )
F_2 ( L_7 ) ;
if ( V_1 & V_8 )
F_2 ( L_8 ) ;
if ( V_1 & V_9 )
F_2 ( L_9 ) ;
if ( V_1 & V_10 )
F_2 ( L_10 ) ;
if ( V_1 & V_11 )
F_2 ( L_11 ) ;
if ( V_1 & V_12 )
F_2 ( L_12 ) ;
if ( V_1 & V_13 )
F_2 ( L_13 ) ;
if ( V_1 & V_14 )
F_2 ( L_14 ) ;
if ( V_1 & V_15 )
F_2 ( L_15 ) ;
if ( V_1 & V_16 )
F_2 ( L_16 ) ;
if ( V_1 & V_17 )
F_2 ( L_17 ) ;
}
static void F_3 ( struct V_18 * V_19 )
{
struct V_20 V_21 ;
volatile T_2 * V_22 ;
bool V_23 ;
int V_24 ;
struct V_25 * V_26 = & V_19 -> V_26 ;
struct V_27 * V_28 = V_19 -> V_29 ;
F_4 ( V_28 , false , false , false , 0 ) ;
F_5 ( & V_26 -> V_30 ) ;
V_24 = F_6 ( V_28 , false , false , false ) ;
F_7 ( & V_26 -> V_30 ) ;
if ( F_8 ( V_24 != 0 ) )
( void ) F_9 ( V_19 , false , true , 0 , false ,
10 * V_31 ) ;
V_24 = F_10 ( V_28 , 0 , 1 , & V_21 ) ;
if ( F_11 ( V_24 == 0 ) ) {
V_22 = F_12 ( & V_21 , & V_23 ) ;
V_22 -> V_32 = sizeof( * V_22 ) ;
V_22 -> V_33 = V_34 ;
V_22 -> V_35 = 0xff ;
F_13 ( & V_21 ) ;
} else
F_14 ( L_18 ) ;
F_15 ( V_28 ) ;
}
static int F_16 ( struct V_18 * V_19 )
{
return F_17 ( & V_19 -> V_26 ,
V_36 ,
V_37 ,
& V_38 ,
0 , false , NULL ,
& V_19 -> V_29 ) ;
}
static int F_18 ( struct V_18 * V_19 )
{
int V_24 ;
V_24 = F_19 ( V_19 , & V_19 -> V_39 ) ;
if ( F_8 ( V_24 != 0 ) ) {
F_14 ( L_19 ) ;
return V_24 ;
}
F_20 ( V_19 -> V_40 ) ;
V_24 = F_16 ( V_19 ) ;
if ( F_8 ( V_24 != 0 ) )
goto V_41;
F_3 ( V_19 ) ;
return 0 ;
V_41:
F_21 ( V_19 -> V_40 ) ;
F_22 ( V_19 , & V_19 -> V_39 ) ;
return V_24 ;
}
static void F_23 ( struct V_18 * V_19 )
{
F_24 ( V_19 -> V_42 != NULL ) ;
F_25 ( & V_19 -> V_29 ) ;
F_21 ( V_19 -> V_40 ) ;
F_22 ( V_19 , & V_19 -> V_39 ) ;
}
int F_26 ( struct V_18 * V_19 ,
bool V_43 )
{
int V_24 = 0 ;
F_27 ( & V_19 -> V_44 ) ;
if ( F_8 ( V_19 -> V_45 ++ == 0 ) ) {
V_24 = F_18 ( V_19 ) ;
if ( F_8 ( V_24 != 0 ) )
-- V_19 -> V_45 ;
} else if ( V_43 ) {
F_27 ( & V_19 -> V_46 ) ;
F_28 ( V_19 , V_47 ,
F_29 ( V_19 , V_47 ) &
~ V_48 ) ;
F_30 ( & V_19 -> V_46 ) ;
}
F_30 ( & V_19 -> V_44 ) ;
return V_24 ;
}
void F_31 ( struct V_18 * V_19 ,
bool V_49 )
{
T_3 V_50 ;
F_27 ( & V_19 -> V_44 ) ;
if ( F_8 ( -- V_19 -> V_45 == 0 ) )
F_23 ( V_19 ) ;
else if ( V_49 ) {
F_27 ( & V_19 -> V_46 ) ;
F_28 ( V_19 , V_47 ,
F_29 ( V_19 , V_47 ) |
V_48 ) ;
F_30 ( & V_19 -> V_46 ) ;
}
V_50 = ( T_3 ) V_19 -> V_45 ;
F_30 ( & V_19 -> V_44 ) ;
F_24 ( V_50 < 0 ) ;
}
static void F_32 ( struct V_18 * V_19 )
{
T_1 V_51 ;
T_1 V_52 ;
V_51 = F_29 ( V_19 , V_53 ) ;
V_52 = F_29 ( V_19 , V_54 ) ;
V_51 = F_33 ( T_1 , V_51 , V_55 ) ;
V_52 = F_33 ( T_1 , V_52 , V_56 ) ;
if ( V_51 > V_19 -> V_57 ||
V_52 > V_19 -> V_58 ) {
V_51 = V_55 ;
V_52 = V_56 ;
}
V_19 -> V_59 = V_51 ;
V_19 -> V_60 = V_52 ;
}
static int F_34 ( struct V_18 * V_19 )
{
static const char * V_61 [ V_62 ] = {
[ V_63 ] = L_20 ,
[ V_64 ] = L_21 ,
[ V_65 ] = L_22 ,
[ V_66 ] = L_23 } ;
#ifdef F_35
const struct V_67 * V_68 = F_36 ( V_19 -> V_69 -> V_69 ) ;
#ifdef F_37
if ( V_70 ) {
V_19 -> V_71 = V_65 ;
goto V_72;
}
#endif
if ( ! ( V_73 || V_74 ) ) {
V_19 -> V_71 = V_63 ;
F_2 ( L_24 , V_61 [ V_19 -> V_71 ] ) ;
return 0 ;
}
V_19 -> V_71 = V_65 ;
if ( V_68 -> V_75 )
V_19 -> V_71 = V_64 ;
#ifdef F_38
if ( F_39 () == 0 )
V_19 -> V_71 = V_65 ;
#endif
#ifdef F_37
V_72:
#endif
if ( V_19 -> V_71 == V_65 &&
V_76 )
V_19 -> V_71 = V_66 ;
if ( V_74 )
V_19 -> V_71 = V_64 ;
#if ! F_40 ( F_38 ) && ! F_40 ( F_37 )
if ( V_19 -> V_71 == V_64 )
return - V_77 ;
#endif
#else
V_19 -> V_71 = V_65 ;
#endif
F_2 ( L_24 , V_61 [ V_19 -> V_71 ] ) ;
return 0 ;
}
static int F_41 ( struct V_78 * V_69 , unsigned long V_79 )
{
struct V_18 * V_19 ;
int V_24 ;
T_1 V_80 ;
enum V_81 V_82 ;
bool V_83 = false ;
V_19 = F_42 ( sizeof( * V_19 ) , V_84 ) ;
if ( F_8 ( V_19 == NULL ) ) {
F_14 ( L_25 ) ;
return - V_85 ;
}
F_43 ( V_69 -> V_86 ) ;
V_19 -> V_69 = V_69 ;
V_19 -> V_87 = V_79 ;
V_19 -> V_88 = ( T_1 ) - 100 ;
F_44 ( & V_19 -> V_46 ) ;
F_44 ( & V_19 -> V_89 ) ;
F_44 ( & V_19 -> V_44 ) ;
F_45 ( & V_19 -> V_90 ) ;
for ( V_82 = V_91 ; V_82 < V_92 ; ++ V_82 ) {
F_46 ( & V_19 -> V_93 [ V_82 ] ) ;
F_47 ( & V_19 -> V_94 [ V_82 ] ) ;
}
F_44 ( & V_19 -> V_95 ) ;
F_48 ( & V_19 -> V_96 ) ;
F_48 ( & V_19 -> V_97 ) ;
V_19 -> V_98 = 0 ;
F_49 ( & V_19 -> V_99 , 0 ) ;
V_19 -> V_100 = 0 ;
V_19 -> V_101 = F_50 ( V_69 -> V_86 , 0 ) ;
V_19 -> V_102 = F_50 ( V_69 -> V_86 , 1 ) ;
V_19 -> V_103 = F_50 ( V_69 -> V_86 , 2 ) ;
V_19 -> V_104 = V_105 ;
F_27 ( & V_19 -> V_46 ) ;
F_28 ( V_19 , V_106 , V_107 ) ;
V_80 = F_29 ( V_19 , V_106 ) ;
if ( V_80 != V_107 ) {
V_24 = - V_108 ;
F_14 ( L_26 , V_80 ) ;
F_30 ( & V_19 -> V_46 ) ;
goto V_109;
}
V_19 -> V_1 = F_29 ( V_19 , V_110 ) ;
V_24 = F_34 ( V_19 ) ;
if ( F_8 ( V_24 != 0 ) ) {
F_2 ( L_27 ) ;
V_83 = true ;
}
V_19 -> V_111 = F_29 ( V_19 , V_112 ) ;
V_19 -> V_113 = F_29 ( V_19 , V_114 ) ;
V_19 -> V_57 = F_29 ( V_19 , V_115 ) ;
V_19 -> V_58 = F_29 ( V_19 , V_116 ) ;
F_32 ( V_19 ) ;
if ( V_19 -> V_1 & V_14 ) {
V_19 -> V_117 =
F_29 ( V_19 ,
V_118 ) ;
V_19 -> V_119 =
F_29 ( V_19 , V_120 ) ;
}
if ( V_19 -> V_1 & V_16 ) {
V_19 -> V_121 =
F_29 ( V_19 , V_122 ) ;
V_19 -> V_123 =
F_29 ( V_19 , V_124 ) ;
V_19 -> V_123 -= V_19 -> V_111 ;
} else {
V_19 -> V_123 = 512 * 1024 * 1024 ;
}
F_30 ( & V_19 -> V_46 ) ;
F_1 ( V_19 -> V_1 ) ;
if ( V_19 -> V_1 & V_14 ) {
F_2 ( L_28 ,
( unsigned ) V_19 -> V_119 ) ;
F_2 ( L_29 ,
( unsigned ) V_19 -> V_117 ) ;
}
if ( V_19 -> V_1 & V_16 ) {
F_2 ( L_30 ,
( unsigned ) V_19 -> V_121 ) ;
F_2 ( L_31 ,
( unsigned ) V_19 -> V_123 / 1024 ) ;
}
F_2 ( L_32 ,
V_19 -> V_102 , V_19 -> V_111 / 1024 ) ;
F_2 ( L_33 ,
V_19 -> V_103 , V_19 -> V_113 / 1024 ) ;
V_24 = F_51 ( V_19 ) ;
if ( F_8 ( V_24 != 0 ) )
goto V_109;
F_52 ( & V_19 -> V_125 ) ;
F_53 ( & V_19 -> V_125 . V_126 , false , V_127 ) ;
V_19 -> V_128 = & V_19 -> V_125 ;
V_24 = F_54 ( & V_19 -> V_26 ,
V_19 -> V_129 . V_130 . V_131 ,
& V_132 , V_133 ,
false ) ;
if ( F_8 ( V_24 != 0 ) ) {
F_14 ( L_34 ) ;
goto V_134;
}
V_24 = F_55 ( & V_19 -> V_26 , V_135 ,
( V_19 -> V_111 >> V_136 ) ) ;
if ( F_8 ( V_24 != 0 ) ) {
F_14 ( L_35 ) ;
goto V_137;
}
V_19 -> V_138 = true ;
if ( ( ( V_19 -> V_1 & ( V_14 | V_16 ) ) == 0 ) ||
V_83 || F_55 ( & V_19 -> V_26 , V_139 ,
V_19 -> V_119 ) != 0 ) {
F_2 ( L_36
L_37 ) ;
V_19 -> V_138 = false ;
}
V_19 -> V_140 = F_56 ( V_19 -> V_103 ,
V_19 -> V_113 ) ;
V_19 -> V_141 = F_57 ( V_19 -> V_103 ,
V_19 -> V_113 ) ;
if ( F_8 ( V_19 -> V_141 == NULL ) ) {
V_24 = - V_85 ;
F_14 ( L_38 ) ;
goto V_142;
}
if ( ! ( V_19 -> V_1 & V_13 ) &&
! ( V_19 -> V_1 & V_11 ) &&
! F_58 ( V_19 ) ) {
V_24 = - V_108 ;
F_14 ( L_39 ) ;
goto V_143;
}
V_19 -> V_144 = F_59
( V_19 -> V_145 . V_131 , 12 , & V_146 ) ;
if ( F_8 ( V_19 -> V_144 == NULL ) ) {
F_14 ( L_40 ) ;
V_24 = - V_85 ;
goto V_143;
}
V_69 -> V_147 = V_19 ;
V_24 = F_60 ( V_69 -> V_86 , L_41 ) ;
V_19 -> V_148 = ( V_24 != 0 ) ;
if ( V_19 -> V_148 ) {
F_2 ( L_42
L_43 ) ;
V_24 = F_61 ( V_69 -> V_86 , 2 , L_44 ) ;
if ( F_8 ( V_24 != 0 ) ) {
F_14 ( L_45 ) ;
goto V_149;
}
}
if ( V_19 -> V_1 & V_12 ) {
V_24 = F_62 ( V_69 ) ;
if ( V_24 != 0 ) {
F_14 ( L_46 , V_24 ) ;
goto V_150;
}
}
V_19 -> V_40 = F_63 ( V_19 ) ;
if ( F_8 ( V_19 -> V_40 == NULL ) ) {
V_24 = - V_85 ;
goto V_151;
}
F_64 ( V_19 ) ;
V_24 = F_65 ( V_19 ) ;
if ( F_8 ( V_24 != 0 ) )
goto V_152;
F_66 ( V_19 ) ;
if ( V_19 -> V_104 ) {
V_24 = F_26 ( V_19 , true ) ;
if ( F_8 ( V_24 != 0 ) )
goto V_153;
F_67 ( V_19 ) ;
}
V_19 -> V_154 . V_155 = V_156 ;
F_68 ( & V_19 -> V_154 ) ;
return 0 ;
V_153:
F_69 ( V_19 ) ;
F_70 ( V_19 ) ;
V_152:
F_71 ( V_19 ) ;
F_72 ( V_19 -> V_40 ) ;
V_151:
if ( V_19 -> V_1 & V_12 )
F_73 ( V_19 -> V_69 ) ;
V_150:
if ( V_19 -> V_148 )
F_74 ( V_69 -> V_86 , 2 ) ;
else
F_75 ( V_69 -> V_86 ) ;
V_149:
F_76 ( & V_19 -> V_144 ) ;
V_143:
F_77 ( V_19 -> V_141 ) ;
V_142:
F_78 ( V_19 -> V_140 ) ;
if ( V_19 -> V_138 )
( void ) F_79 ( & V_19 -> V_26 , V_139 ) ;
( void ) F_79 ( & V_19 -> V_26 , V_135 ) ;
V_137:
( void ) F_80 ( & V_19 -> V_26 ) ;
V_134:
F_81 ( V_19 ) ;
V_109:
for ( V_82 = V_91 ; V_82 < V_92 ; ++ V_82 )
F_82 ( & V_19 -> V_93 [ V_82 ] ) ;
F_83 ( V_19 ) ;
return V_24 ;
}
static int F_84 ( struct V_78 * V_69 )
{
struct V_18 * V_19 = F_85 ( V_69 ) ;
enum V_81 V_82 ;
F_86 ( & V_19 -> V_154 ) ;
if ( V_19 -> V_157 . V_158 )
F_87 ( & V_19 -> V_157 . V_159 ) ;
if ( V_19 -> V_157 . V_160 )
F_88 ( V_19 -> V_157 . V_160 ) ;
if ( V_19 -> V_104 ) {
F_89 ( V_19 ) ;
F_71 ( V_19 ) ;
F_31 ( V_19 , false ) ;
}
F_70 ( V_19 ) ;
F_69 ( V_19 ) ;
F_72 ( V_19 -> V_40 ) ;
if ( V_19 -> V_1 & V_12 )
F_73 ( V_19 -> V_69 ) ;
if ( V_19 -> V_148 )
F_74 ( V_69 -> V_86 , 2 ) ;
else
F_75 ( V_69 -> V_86 ) ;
F_76 ( & V_19 -> V_144 ) ;
F_77 ( V_19 -> V_141 ) ;
F_78 ( V_19 -> V_140 ) ;
if ( V_19 -> V_138 )
( void ) F_79 ( & V_19 -> V_26 , V_139 ) ;
( void ) F_79 ( & V_19 -> V_26 , V_135 ) ;
( void ) F_80 ( & V_19 -> V_26 ) ;
F_81 ( V_19 ) ;
for ( V_82 = V_91 ; V_82 < V_92 ; ++ V_82 )
F_82 ( & V_19 -> V_93 [ V_82 ] ) ;
F_83 ( V_19 ) ;
return 0 ;
}
static void F_90 ( struct V_78 * V_69 ,
struct V_161 * V_162 )
{
struct V_163 * V_164 = V_163 ( V_162 ) ;
struct V_18 * V_19 = F_85 ( V_69 ) ;
F_91 ( V_19 -> V_40 , & V_164 -> V_165 ) ;
}
static void F_92 ( struct V_78 * V_69 ,
struct V_161 * V_162 )
{
struct V_163 * V_164 ;
V_164 = V_163 ( V_162 ) ;
if ( V_164 -> V_166 ) {
struct V_167 * V_168 =
V_167 ( V_164 -> V_166 ) ;
F_53 ( & V_168 -> V_126 , true , V_127 ) ;
F_93 ( & V_168 -> V_126 ) ;
F_94 ( & V_164 -> V_166 ) ;
}
F_95 ( & V_164 -> V_169 ) ;
F_83 ( V_164 ) ;
}
static int F_96 ( struct V_78 * V_69 , struct V_161 * V_162 )
{
struct V_18 * V_19 = F_85 ( V_69 ) ;
struct V_163 * V_164 ;
int V_24 = - V_85 ;
V_164 = F_42 ( sizeof( * V_164 ) , V_84 ) ;
if ( F_8 ( V_164 == NULL ) )
return V_24 ;
F_47 ( & V_164 -> V_165 ) ;
V_164 -> V_169 = F_97 ( V_19 -> V_144 , 10 ) ;
if ( F_8 ( V_164 -> V_169 == NULL ) )
goto V_170;
V_162 -> V_171 = V_164 ;
V_19 -> V_26 . V_172 = V_69 -> V_172 ;
return 0 ;
V_170:
F_83 ( V_164 ) ;
return V_24 ;
}
static long F_98 ( struct V_173 * V_174 , unsigned int V_175 ,
unsigned long V_176 )
{
struct V_161 * V_162 = V_174 -> V_177 ;
struct V_78 * V_69 = V_162 -> V_178 -> V_69 ;
unsigned int V_179 = F_99 ( V_175 ) ;
if ( ( V_179 >= V_180 ) && ( V_179 < V_181 )
&& ( V_179 < V_180 + V_69 -> V_182 -> V_183 ) ) {
const struct V_184 * V_185 =
& V_186 [ V_179 - V_180 ] ;
if ( F_8 ( V_185 -> V_187 != V_175 ) ) {
F_14 ( L_47 ,
V_179 - V_180 ) ;
return - V_77 ;
}
}
return F_100 ( V_174 , V_175 , V_176 ) ;
}
static void F_101 ( struct V_78 * V_69 )
{
struct V_188 * V_189 ;
struct V_190 V_191 ;
int V_24 ;
V_191 . V_192 = 0 ;
V_191 . V_193 = 0 ;
V_191 . V_194 = NULL ;
V_191 . V_195 = NULL ;
V_191 . V_196 = NULL ;
V_191 . V_197 = 0 ;
F_102 (crtc, &dev->mode_config.crtc_list, head) {
V_191 . V_189 = V_189 ;
V_24 = F_103 ( & V_191 ) ;
F_104 ( V_24 != 0 ) ;
}
}
static void F_52 ( struct V_167 * V_168 )
{
F_105 ( & V_168 -> V_126 ) ;
F_47 ( & V_168 -> V_198 ) ;
F_44 ( & V_168 -> V_199 ) ;
}
static int F_106 ( struct V_78 * V_69 ,
struct V_200 * V_201 )
{
struct V_167 * V_168 ;
V_168 = F_42 ( sizeof( * V_168 ) , V_84 ) ;
if ( F_8 ( V_168 == NULL ) )
return - V_85 ;
F_52 ( V_168 ) ;
F_53 ( & V_168 -> V_126 , true , V_127 ) ;
V_201 -> V_171 = V_168 ;
return 0 ;
}
static void F_107 ( struct V_78 * V_69 ,
struct V_200 * V_201 )
{
struct V_167 * V_168 = V_167 ( V_201 ) ;
V_201 -> V_171 = NULL ;
F_83 ( V_168 ) ;
}
static int F_108 ( struct V_78 * V_69 ,
struct V_161 * V_162 ,
bool V_202 )
{
struct V_18 * V_19 = F_85 ( V_69 ) ;
struct V_163 * V_164 = V_163 ( V_162 ) ;
struct V_167 * V_203 = V_19 -> V_128 ;
struct V_167 * V_168 = V_167 ( V_162 -> V_201 ) ;
int V_24 = 0 ;
if ( ! V_19 -> V_104 ) {
V_24 = F_26 ( V_19 , true ) ;
if ( F_8 ( V_24 != 0 ) )
return V_24 ;
F_64 ( V_19 ) ;
F_27 ( & V_19 -> V_46 ) ;
F_28 ( V_19 , V_204 , 0 ) ;
F_30 ( & V_19 -> V_46 ) ;
}
if ( V_203 ) {
F_24 ( V_203 != & V_19 -> V_125 ) ;
V_24 = F_109 ( & V_203 -> V_126 , false , V_164 -> V_169 ) ;
if ( F_8 ( V_24 != 0 ) )
goto V_205;
F_53 ( & V_203 -> V_126 , true , V_127 ) ;
V_24 = F_110 ( & V_19 -> V_26 , V_135 ) ;
if ( F_8 ( V_24 != 0 ) ) {
F_14 ( L_48
L_49 ) ;
}
V_19 -> V_128 = NULL ;
}
F_53 ( & V_168 -> V_126 , false , V_127 ) ;
if ( ! V_202 ) {
F_93 ( & V_168 -> V_126 ) ;
F_24 ( V_164 -> V_166 != V_162 -> V_201 ) ;
F_94 ( & V_164 -> V_166 ) ;
}
V_19 -> V_128 = V_168 ;
return 0 ;
V_205:
if ( ! V_19 -> V_104 ) {
F_71 ( V_19 ) ;
F_31 ( V_19 , true ) ;
F_27 ( & V_19 -> V_46 ) ;
F_28 ( V_19 , V_204 , 1 ) ;
F_30 ( & V_19 -> V_46 ) ;
}
return V_24 ;
}
static void F_111 ( struct V_78 * V_69 ,
struct V_161 * V_162 ,
bool V_206 )
{
struct V_18 * V_19 = F_85 ( V_69 ) ;
struct V_163 * V_164 = V_163 ( V_162 ) ;
struct V_167 * V_168 = V_167 ( V_162 -> V_201 ) ;
int V_24 ;
V_164 -> V_166 = F_112 ( V_162 -> V_201 ) ;
V_24 = F_109 ( & V_168 -> V_126 , false , V_164 -> V_169 ) ;
if ( F_8 ( ( V_24 != 0 ) ) ) {
F_14 ( L_50 ) ;
F_94 ( & V_164 -> V_166 ) ;
}
F_53 ( & V_168 -> V_126 , false , V_127 ) ;
F_113 ( V_19 ) ;
if ( ! V_19 -> V_104 ) {
V_24 = F_110 ( & V_19 -> V_26 , V_135 ) ;
if ( F_8 ( V_24 != 0 ) )
F_14 ( L_51 ) ;
F_71 ( V_19 ) ;
F_31 ( V_19 , true ) ;
F_27 ( & V_19 -> V_46 ) ;
F_28 ( V_19 , V_204 , 1 ) ;
F_30 ( & V_19 -> V_46 ) ;
}
V_19 -> V_128 = & V_19 -> V_125 ;
F_53 ( & V_19 -> V_125 . V_126 , false , V_127 ) ;
F_93 ( & V_19 -> V_125 . V_126 ) ;
if ( V_19 -> V_104 )
F_114 ( V_19 ) ;
}
static void F_115 ( struct V_207 * V_86 )
{
struct V_78 * V_69 = F_116 ( V_86 ) ;
F_117 ( V_69 ) ;
}
static int V_156 ( struct V_208 * V_209 , unsigned long V_210 ,
void * V_211 )
{
struct V_18 * V_19 =
F_118 ( V_209 , struct V_18 , V_154 ) ;
struct V_167 * V_168 = V_19 -> V_128 ;
switch ( V_210 ) {
case V_212 :
case V_213 :
F_119 ( & V_168 -> V_126 ) ;
F_113 ( V_19 ) ;
F_120 ( V_19 ) ;
F_121 ( & V_19 -> V_26 ) ;
break;
case V_214 :
case V_215 :
case V_216 :
F_122 ( & V_168 -> V_126 ) ;
break;
case V_217 :
break;
default:
break;
}
return 0 ;
}
static int F_123 ( struct V_207 * V_86 , T_4 V_33 )
{
struct V_78 * V_69 = F_116 ( V_86 ) ;
struct V_18 * V_19 = F_85 ( V_69 ) ;
if ( V_19 -> V_45 != 0 ) {
F_2 ( L_52
L_53 ) ;
return - V_218 ;
}
F_124 ( V_86 ) ;
F_125 ( V_86 ) ;
F_126 ( V_86 , V_219 ) ;
return 0 ;
}
static int F_127 ( struct V_207 * V_86 )
{
F_126 ( V_86 , V_220 ) ;
F_128 ( V_86 ) ;
return F_129 ( V_86 ) ;
}
static int F_130 ( struct V_221 * V_222 )
{
struct V_207 * V_86 = F_131 ( V_222 ) ;
struct V_223 V_23 ;
V_23 . V_224 = 0 ;
return F_123 ( V_86 , V_23 ) ;
}
static int F_132 ( struct V_221 * V_222 )
{
struct V_207 * V_86 = F_131 ( V_222 ) ;
return F_127 ( V_86 ) ;
}
static int F_133 ( struct V_221 * V_222 )
{
struct V_207 * V_86 = F_131 ( V_222 ) ;
struct V_78 * V_69 = F_116 ( V_86 ) ;
struct V_18 * V_19 = F_85 ( V_69 ) ;
V_19 -> V_225 = true ;
if ( V_19 -> V_104 )
F_31 ( V_19 , true ) ;
if ( V_19 -> V_45 != 0 ) {
F_2 ( L_52
L_53 ) ;
if ( V_19 -> V_104 )
F_26 ( V_19 , true ) ;
V_19 -> V_225 = false ;
return - V_218 ;
}
return 0 ;
}
static void F_134 ( struct V_221 * V_222 )
{
struct V_207 * V_86 = F_131 ( V_222 ) ;
struct V_78 * V_69 = F_116 ( V_86 ) ;
struct V_18 * V_19 = F_85 ( V_69 ) ;
F_27 ( & V_19 -> V_46 ) ;
F_28 ( V_19 , V_106 , V_107 ) ;
( void ) F_29 ( V_19 , V_106 ) ;
F_30 ( & V_19 -> V_46 ) ;
if ( V_19 -> V_104 )
F_26 ( V_19 , false ) ;
V_19 -> V_225 = false ;
}
static int F_135 ( struct V_207 * V_86 , const struct V_226 * V_227 )
{
return F_136 ( V_86 , V_227 , & V_182 ) ;
}
static int T_5 F_137 ( void )
{
int V_24 ;
V_24 = F_138 ( & V_182 , & V_228 ) ;
if ( V_24 )
F_14 ( L_54 ) ;
return V_24 ;
}
static void T_6 F_139 ( void )
{
F_140 ( & V_182 , & V_228 ) ;
}
