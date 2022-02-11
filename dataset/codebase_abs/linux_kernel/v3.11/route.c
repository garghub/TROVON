static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
int V_5 )
{
}
static T_1 * F_2 ( struct V_1 * V_2 , unsigned long V_6 )
{
F_3 ( 1 ) ;
return NULL ;
}
static void * F_4 ( struct V_7 * V_8 , T_2 * V_9 )
{
if ( * V_9 )
return NULL ;
return V_10 ;
}
static void * F_5 ( struct V_7 * V_8 , void * V_11 , T_2 * V_9 )
{
++ * V_9 ;
return NULL ;
}
static void F_6 ( struct V_7 * V_8 , void * V_11 )
{
}
static int F_7 ( struct V_7 * V_8 , void * V_11 )
{
if ( V_11 == V_10 )
F_8 ( V_8 , L_1 ,
L_2
L_3
L_4 ) ;
return 0 ;
}
static int F_9 ( struct V_12 * V_12 , struct V_13 * V_13 )
{
return F_10 ( V_13 , & V_14 ) ;
}
static void * F_11 ( struct V_7 * V_8 , T_2 * V_9 )
{
int V_15 ;
if ( * V_9 == 0 )
return V_10 ;
for ( V_15 = * V_9 - 1 ; V_15 < V_16 ; ++ V_15 ) {
if ( ! F_12 ( V_15 ) )
continue;
* V_9 = V_15 + 1 ;
return & F_13 ( V_17 , V_15 ) ;
}
return NULL ;
}
static void * F_14 ( struct V_7 * V_8 , void * V_11 , T_2 * V_9 )
{
int V_15 ;
for ( V_15 = * V_9 ; V_15 < V_16 ; ++ V_15 ) {
if ( ! F_12 ( V_15 ) )
continue;
* V_9 = V_15 + 1 ;
return & F_13 ( V_17 , V_15 ) ;
}
return NULL ;
}
static void F_15 ( struct V_7 * V_8 , void * V_11 )
{
}
static int F_16 ( struct V_7 * V_8 , void * V_11 )
{
struct V_17 * V_18 = V_11 ;
if ( V_11 == V_10 ) {
F_8 ( V_8 , L_5 ) ;
return 0 ;
}
F_8 ( V_8 , L_6
L_7 ,
F_17 ( & V_19 ) ,
V_18 -> V_20 ,
V_18 -> V_21 ,
V_18 -> V_22 ,
V_18 -> V_23 ,
V_18 -> V_24 ,
V_18 -> V_25 ,
V_18 -> V_26 ,
V_18 -> V_27 ,
V_18 -> V_28 ,
V_18 -> V_29 ,
V_18 -> V_30 ,
V_18 -> V_31 ,
V_18 -> V_32 ,
V_18 -> V_33 ,
V_18 -> V_34 ,
V_18 -> V_35
) ;
return 0 ;
}
static int F_18 ( struct V_12 * V_12 , struct V_13 * V_13 )
{
return F_10 ( V_13 , & V_36 ) ;
}
static int F_19 ( struct V_7 * V_37 , void * V_11 )
{
struct V_38 * V_2 , * V_39 ;
unsigned int V_40 , V_41 ;
V_2 = F_20 ( 256 , sizeof( struct V_38 ) , V_42 ) ;
if ( ! V_2 )
return - V_43 ;
F_21 (i) {
V_39 = (struct V_38 * ) F_22 ( V_38 , V_40 ) ;
for ( V_41 = 0 ; V_41 < 256 ; V_41 ++ ) {
V_2 [ V_41 ] . V_44 += V_39 [ V_41 ] . V_44 ;
V_2 [ V_41 ] . V_45 += V_39 [ V_41 ] . V_45 ;
V_2 [ V_41 ] . V_46 += V_39 [ V_41 ] . V_46 ;
V_2 [ V_41 ] . V_47 += V_39 [ V_41 ] . V_47 ;
}
}
F_23 ( V_37 , V_2 , 256 * sizeof( struct V_38 ) ) ;
F_24 ( V_2 ) ;
return 0 ;
}
static int F_25 ( struct V_12 * V_12 , struct V_13 * V_13 )
{
return F_26 ( V_13 , F_19 , NULL ) ;
}
static int T_3 F_27 ( struct V_48 * V_48 )
{
struct V_49 * V_50 ;
V_50 = F_28 ( L_8 , V_51 , V_48 -> V_52 ,
& V_53 ) ;
if ( ! V_50 )
goto V_54;
V_50 = F_28 ( L_8 , V_51 ,
V_48 -> V_55 , & V_56 ) ;
if ( ! V_50 )
goto V_57;
#ifdef F_29
V_50 = F_28 ( L_9 , 0 , V_48 -> V_52 , & V_58 ) ;
if ( ! V_50 )
goto V_59;
#endif
return 0 ;
#ifdef F_29
V_59:
F_30 ( L_8 , V_48 -> V_55 ) ;
#endif
V_57:
F_30 ( L_8 , V_48 -> V_52 ) ;
V_54:
return - V_43 ;
}
static void T_4 F_31 ( struct V_48 * V_48 )
{
F_30 ( L_8 , V_48 -> V_55 ) ;
F_30 ( L_8 , V_48 -> V_52 ) ;
#ifdef F_29
F_30 ( L_9 , V_48 -> V_52 ) ;
#endif
}
static int T_5 F_32 ( void )
{
return F_33 ( & V_60 ) ;
}
static inline int F_32 ( void )
{
return 0 ;
}
static inline bool F_34 ( const struct V_61 * V_62 )
{
return V_62 -> V_63 != V_63 ( F_35 ( V_62 -> V_2 . V_4 ) ) ;
}
void F_36 ( struct V_48 * V_48 )
{
F_37 ( V_48 ) ;
}
static struct V_64 * F_38 ( const struct V_1 * V_2 ,
struct V_65 * V_66 ,
const void * V_67 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
const T_6 * V_68 = V_67 ;
const struct V_61 * V_69 ;
struct V_64 * V_70 ;
V_69 = ( const struct V_61 * ) V_2 ;
if ( V_69 -> V_71 )
V_68 = ( const T_6 * ) & V_69 -> V_71 ;
else if ( V_66 )
V_68 = & F_39 ( V_66 ) -> V_67 ;
V_70 = F_40 ( V_4 , * ( V_72 T_1 * ) V_68 ) ;
if ( V_70 )
return V_70 ;
return F_41 ( & V_73 , V_68 , V_4 ) ;
}
static void F_42 ( struct V_74 * V_75 )
{
static F_43 ( V_76 ) ;
static T_1 V_77 ;
T_1 V_78 ;
F_44 ( & V_76 ) ;
V_78 = F_45 ( ( V_72 T_6 ) V_77 ^ V_75 -> V_67 ) ;
V_75 -> V_79 = F_46 ( V_78 & 0xFFFF ) ;
V_77 = V_78 ;
F_47 ( & V_76 ) ;
}
void F_48 ( struct V_74 * V_75 , struct V_1 * V_2 , int V_80 )
{
struct V_48 * V_48 = F_35 ( V_2 -> V_4 ) ;
struct V_81 * V_82 ;
V_82 = F_49 ( V_48 -> V_83 . V_84 , V_75 -> V_67 , 1 ) ;
if ( V_82 ) {
V_75 -> V_79 = F_46 ( F_50 ( V_82 , V_80 ) ) ;
F_51 ( V_82 ) ;
return;
}
F_42 ( V_75 ) ;
}
static void F_52 ( struct V_85 * V_86 , const struct V_87 * V_88 ,
const struct V_74 * V_75 ,
int V_89 , T_7 V_90 ,
T_7 V_91 , T_1 V_92 , int V_93 )
{
if ( V_88 ) {
const struct V_94 * V_95 = F_53 ( V_88 ) ;
V_89 = V_88 -> V_96 ;
V_92 = V_88 -> V_97 ;
V_90 = F_54 ( V_88 ) ;
V_91 = V_95 -> V_98 ? V_99 : V_88 -> V_100 ;
}
F_55 ( V_86 , V_89 , V_92 , V_90 ,
V_101 , V_91 ,
V_93 ,
V_75 -> V_67 , V_75 -> V_102 , 0 , 0 ) ;
}
static void F_56 ( struct V_85 * V_86 , const struct V_65 * V_66 ,
const struct V_87 * V_88 )
{
const struct V_74 * V_75 = F_39 ( V_66 ) ;
int V_89 = V_66 -> V_4 -> V_103 ;
T_7 V_90 = F_57 ( V_75 -> V_90 ) ;
T_7 V_91 = V_75 -> V_104 ;
T_1 V_92 = V_66 -> V_92 ;
F_52 ( V_86 , V_88 , V_75 , V_89 , V_90 , V_91 , V_92 , 0 ) ;
}
static void F_58 ( struct V_85 * V_86 , const struct V_87 * V_88 )
{
const struct V_94 * V_95 = F_53 ( V_88 ) ;
const struct V_105 * V_106 ;
T_6 V_67 = V_95 -> V_107 ;
F_59 () ;
V_106 = F_60 ( V_95 -> V_106 ) ;
if ( V_106 && V_106 -> V_108 . V_109 )
V_67 = V_106 -> V_108 . V_110 ;
F_55 ( V_86 , V_88 -> V_96 , V_88 -> V_97 ,
F_54 ( V_88 ) , V_101 ,
V_95 -> V_98 ? V_99 : V_88 -> V_100 ,
F_61 ( V_88 ) ,
V_67 , V_95 -> V_111 , 0 , 0 ) ;
F_62 () ;
}
static void F_63 ( struct V_85 * V_86 , const struct V_87 * V_88 ,
const struct V_65 * V_66 )
{
if ( V_66 )
F_56 ( V_86 , V_66 , V_88 ) ;
else
F_58 ( V_86 , V_88 ) ;
}
static inline void F_64 ( struct V_61 * V_69 )
{
F_65 ( & V_69 -> V_2 . V_112 , V_113 ) ;
}
static void F_66 ( struct V_114 * V_115 )
{
struct V_61 * V_69 ;
V_69 = F_60 ( V_115 -> V_116 ) ;
if ( V_69 ) {
F_67 ( V_115 -> V_116 , NULL ) ;
F_64 ( V_69 ) ;
}
V_69 = F_60 ( V_115 -> V_117 ) ;
if ( V_69 ) {
F_67 ( V_115 -> V_117 , NULL ) ;
F_64 ( V_69 ) ;
}
}
static struct V_114 * F_68 ( struct V_118 * V_119 )
{
struct V_114 * V_115 , * V_120 ;
V_120 = F_60 ( V_119 -> V_121 ) ;
for ( V_115 = F_60 ( V_120 -> V_122 ) ; V_115 ;
V_115 = F_60 ( V_115 -> V_122 ) ) {
if ( F_69 ( V_115 -> V_123 , V_120 -> V_123 ) )
V_120 = V_115 ;
}
F_66 ( V_120 ) ;
return V_120 ;
}
static inline T_1 F_70 ( T_6 V_67 )
{
T_1 V_124 ;
V_124 = ( V_72 T_1 ) V_67 ;
V_124 ^= ( V_124 >> 11 ) ^ ( V_124 >> 22 ) ;
return V_124 & ( V_125 - 1 ) ;
}
static void F_71 ( struct V_61 * V_69 , struct V_114 * V_115 )
{
V_69 -> V_126 = V_115 -> V_127 ;
V_69 -> V_2 . V_128 = V_115 -> V_129 ;
if ( V_115 -> V_130 ) {
V_69 -> V_131 |= V_132 ;
V_69 -> V_71 = V_115 -> V_130 ;
V_69 -> V_133 = 1 ;
}
}
static void F_72 ( struct V_134 * V_135 , T_6 V_67 , T_6 V_136 ,
T_1 V_137 , unsigned long V_128 )
{
struct V_118 * V_119 ;
struct V_114 * V_115 ;
struct V_61 * V_69 ;
unsigned int V_40 ;
int V_138 ;
T_1 V_124 = F_70 ( V_67 ) ;
F_44 ( & V_139 ) ;
V_119 = V_135 -> V_140 ;
if ( ! V_119 ) {
V_119 = F_73 ( V_125 * sizeof( * V_119 ) , V_141 ) ;
if ( ! V_119 )
goto V_142;
V_135 -> V_140 = V_119 ;
}
V_119 += V_124 ;
V_138 = 0 ;
for ( V_115 = F_60 ( V_119 -> V_121 ) ; V_115 ;
V_115 = F_60 ( V_115 -> V_122 ) ) {
if ( V_115 -> V_143 == V_67 )
break;
V_138 ++ ;
}
if ( V_115 ) {
if ( V_136 )
V_115 -> V_130 = V_136 ;
if ( V_137 ) {
V_115 -> V_127 = V_137 ;
V_115 -> V_129 = F_74 ( 1UL , V_128 ) ;
}
V_69 = F_60 ( V_115 -> V_116 ) ;
if ( V_69 )
F_71 ( V_69 , V_115 ) ;
V_69 = F_60 ( V_115 -> V_117 ) ;
if ( V_69 )
F_71 ( V_69 , V_115 ) ;
} else {
if ( V_138 > V_144 )
V_115 = F_68 ( V_119 ) ;
else {
V_115 = F_73 ( sizeof( * V_115 ) , V_141 ) ;
if ( ! V_115 )
goto V_142;
V_115 -> V_122 = V_119 -> V_121 ;
F_75 ( V_119 -> V_121 , V_115 ) ;
}
V_115 -> V_145 = V_145 ( F_35 ( V_135 -> V_146 ) ) ;
V_115 -> V_143 = V_67 ;
V_115 -> V_130 = V_136 ;
V_115 -> V_127 = V_137 ;
V_115 -> V_129 = V_128 ;
V_69 = F_60 ( V_135 -> V_147 ) ;
if ( V_69 )
V_69 -> V_2 . V_148 = V_149 ;
F_21 (i) {
struct V_61 T_8 * * V_150 ;
V_150 = F_22 ( V_135 -> V_151 , V_40 ) ;
V_69 = F_60 ( * V_150 ) ;
if ( V_69 )
V_69 -> V_2 . V_148 = V_149 ;
}
}
V_115 -> V_123 = V_152 ;
V_142:
F_47 ( & V_139 ) ;
return;
}
static void F_76 ( struct V_61 * V_69 , struct V_65 * V_66 , struct V_85 * V_86 ,
bool V_153 )
{
T_6 V_154 = F_77 ( V_66 ) -> V_155 . V_156 ;
T_6 V_157 = F_39 ( V_66 ) -> V_102 ;
struct V_3 * V_4 = V_66 -> V_4 ;
struct V_158 * V_159 ;
struct V_160 V_161 ;
struct V_64 * V_70 ;
struct V_48 * V_48 ;
switch ( F_77 ( V_66 ) -> V_162 & 7 ) {
case V_163 :
case V_164 :
case V_165 :
case V_166 :
break;
default:
return;
}
if ( V_69 -> V_71 != V_157 )
return;
V_159 = F_78 ( V_4 ) ;
if ( ! V_159 )
return;
V_48 = F_35 ( V_4 ) ;
if ( V_154 == V_157 || ! F_79 ( V_159 ) ||
F_80 ( V_154 ) || F_81 ( V_154 ) ||
F_82 ( V_154 ) )
goto V_167;
if ( ! F_83 ( V_159 ) ) {
if ( ! F_84 ( V_159 , V_154 , V_157 ) )
goto V_167;
if ( F_85 ( V_159 ) && F_86 ( V_154 , V_4 ) )
goto V_167;
} else {
if ( F_87 ( V_48 , V_154 ) != V_168 )
goto V_167;
}
V_70 = F_38 ( & V_69 -> V_2 , NULL , & V_154 ) ;
if ( V_70 ) {
if ( ! ( V_70 -> V_169 & V_170 ) ) {
F_88 ( V_70 , NULL ) ;
} else {
if ( F_89 ( V_48 , V_86 , & V_161 ) == 0 ) {
struct V_134 * V_135 = & F_90 ( V_161 ) ;
F_72 ( V_135 , V_86 -> V_67 , V_154 ,
0 , 0 ) ;
}
if ( V_153 )
V_69 -> V_2 . V_148 = V_149 ;
F_91 ( V_171 , V_70 ) ;
}
F_92 ( V_70 ) ;
}
return;
V_167:
#ifdef F_93
if ( F_94 ( V_159 ) ) {
const struct V_74 * V_75 = ( const struct V_74 * ) V_66 -> V_172 ;
T_6 V_67 = V_75 -> V_67 ;
T_6 V_102 = V_75 -> V_102 ;
F_95 ( L_10
L_11 ,
& V_157 , V_4 -> V_173 , & V_154 ,
& V_102 , & V_67 ) ;
}
#endif
;
}
static void F_96 ( struct V_1 * V_2 , struct V_87 * V_88 , struct V_65 * V_66 )
{
struct V_61 * V_69 ;
struct V_85 V_86 ;
const struct V_74 * V_75 = ( const struct V_74 * ) V_66 -> V_172 ;
int V_89 = V_66 -> V_4 -> V_103 ;
T_7 V_90 = F_57 ( V_75 -> V_90 ) ;
T_7 V_91 = V_75 -> V_104 ;
T_1 V_92 = V_66 -> V_92 ;
V_69 = (struct V_61 * ) V_2 ;
F_52 ( & V_86 , V_88 , V_75 , V_89 , V_90 , V_91 , V_92 , 0 ) ;
F_76 ( V_69 , V_66 , & V_86 , true ) ;
}
static struct V_1 * F_97 ( struct V_1 * V_2 )
{
struct V_61 * V_69 = (struct V_61 * ) V_2 ;
struct V_1 * V_174 = V_2 ;
if ( V_69 ) {
if ( V_2 -> V_148 > 0 ) {
F_98 ( V_69 ) ;
V_174 = NULL ;
} else if ( ( V_69 -> V_131 & V_132 ) ||
V_69 -> V_2 . V_128 ) {
F_98 ( V_69 ) ;
V_174 = NULL ;
}
}
return V_174 ;
}
void F_99 ( struct V_65 * V_66 )
{
struct V_61 * V_69 = F_100 ( V_66 ) ;
struct V_158 * V_159 ;
struct V_81 * V_82 ;
struct V_48 * V_48 ;
int V_175 ;
F_59 () ;
V_159 = F_78 ( V_69 -> V_2 . V_4 ) ;
if ( ! V_159 || ! F_101 ( V_159 ) ) {
F_62 () ;
return;
}
V_175 = F_94 ( V_159 ) ;
F_62 () ;
V_48 = F_35 ( V_69 -> V_2 . V_4 ) ;
V_82 = F_49 ( V_48 -> V_83 . V_84 , F_39 ( V_66 ) -> V_102 , 1 ) ;
if ( ! V_82 ) {
F_102 ( V_66 , V_176 , V_165 ,
F_103 ( V_69 , F_39 ( V_66 ) -> V_67 ) ) ;
return;
}
if ( F_104 ( V_152 , V_82 -> V_177 + V_178 ) )
V_82 -> V_179 = 0 ;
if ( V_82 -> V_179 >= V_180 ) {
V_82 -> V_177 = V_152 ;
goto V_181;
}
if ( V_82 -> V_179 == 0 ||
F_104 ( V_152 ,
( V_82 -> V_177 +
( V_182 << V_82 -> V_179 ) ) ) ) {
T_6 V_136 = F_103 ( V_69 , F_39 ( V_66 ) -> V_67 ) ;
F_102 ( V_66 , V_176 , V_165 , V_136 ) ;
V_82 -> V_177 = V_152 ;
++ V_82 -> V_179 ;
#ifdef F_93
if ( V_175 &&
V_82 -> V_179 == V_180 )
F_105 ( L_12 ,
& F_39 ( V_66 ) -> V_102 , F_106 ( V_66 ) ,
& F_39 ( V_66 ) -> V_67 , & V_136 ) ;
#endif
}
V_181:
F_51 ( V_82 ) ;
}
static int F_107 ( struct V_65 * V_66 )
{
struct V_158 * V_159 = F_78 ( V_66 -> V_4 ) ;
struct V_61 * V_69 = F_100 ( V_66 ) ;
struct V_81 * V_82 ;
unsigned long V_183 ;
struct V_48 * V_48 ;
bool V_184 ;
int V_162 ;
V_48 = F_35 ( V_69 -> V_2 . V_4 ) ;
if ( ! F_108 ( V_159 ) ) {
switch ( V_69 -> V_2 . error ) {
case V_185 :
F_109 ( V_48 , V_186 ) ;
break;
case V_187 :
F_109 ( V_48 , V_188 ) ;
break;
}
goto V_189;
}
switch ( V_69 -> V_2 . error ) {
case V_190 :
default:
goto V_189;
case V_185 :
V_162 = V_191 ;
break;
case V_187 :
V_162 = V_192 ;
F_109 ( V_48 , V_188 ) ;
break;
case V_193 :
V_162 = V_194 ;
break;
}
V_82 = F_49 ( V_48 -> V_83 . V_84 , F_39 ( V_66 ) -> V_102 , 1 ) ;
V_184 = true ;
if ( V_82 ) {
V_183 = V_152 ;
V_82 -> V_179 += V_183 - V_82 -> V_177 ;
if ( V_82 -> V_179 > V_195 )
V_82 -> V_179 = V_195 ;
V_82 -> V_177 = V_183 ;
if ( V_82 -> V_179 >= V_196 )
V_82 -> V_179 -= V_196 ;
else
V_184 = false ;
F_51 ( V_82 ) ;
}
if ( V_184 )
F_102 ( V_66 , V_197 , V_162 , 0 ) ;
V_189: F_110 ( V_66 ) ;
return 0 ;
}
static void F_111 ( struct V_61 * V_69 , struct V_85 * V_86 , T_1 V_198 )
{
struct V_1 * V_2 = & V_69 -> V_2 ;
struct V_160 V_161 ;
if ( F_112 ( V_2 , V_199 ) )
return;
if ( V_2 -> V_4 -> V_198 < V_198 )
return;
if ( V_198 < V_200 )
V_198 = V_200 ;
if ( V_69 -> V_126 == V_198 &&
F_69 ( V_152 , V_2 -> V_128 - V_201 / 2 ) )
return;
F_59 () ;
if ( F_89 ( F_35 ( V_2 -> V_4 ) , V_86 , & V_161 ) == 0 ) {
struct V_134 * V_135 = & F_90 ( V_161 ) ;
F_72 ( V_135 , V_86 -> V_67 , 0 , V_198 ,
V_152 + V_201 ) ;
}
F_62 () ;
}
static void F_113 ( struct V_1 * V_2 , struct V_87 * V_88 ,
struct V_65 * V_66 , T_1 V_198 )
{
struct V_61 * V_69 = (struct V_61 * ) V_2 ;
struct V_85 V_86 ;
F_63 ( & V_86 , V_88 , V_66 ) ;
F_111 ( V_69 , & V_86 , V_198 ) ;
}
void F_114 ( struct V_65 * V_66 , struct V_48 * V_48 , T_1 V_198 ,
int V_89 , T_1 V_92 , T_7 V_104 , int V_93 )
{
const struct V_74 * V_75 = ( const struct V_74 * ) V_66 -> V_172 ;
struct V_85 V_86 ;
struct V_61 * V_69 ;
F_52 ( & V_86 , NULL , V_75 , V_89 ,
F_57 ( V_75 -> V_90 ) , V_104 , V_92 , V_93 ) ;
V_69 = F_115 ( V_48 , & V_86 ) ;
if ( ! F_116 ( V_69 ) ) {
F_111 ( V_69 , & V_86 , V_198 ) ;
F_98 ( V_69 ) ;
}
}
static void F_117 ( struct V_65 * V_66 , struct V_87 * V_88 , T_1 V_198 )
{
const struct V_74 * V_75 = ( const struct V_74 * ) V_66 -> V_172 ;
struct V_85 V_86 ;
struct V_61 * V_69 ;
F_52 ( & V_86 , V_88 , V_75 , 0 , 0 , 0 , 0 , 0 ) ;
V_69 = F_115 ( F_118 ( V_88 ) , & V_86 ) ;
if ( ! F_116 ( V_69 ) ) {
F_111 ( V_69 , & V_86 , V_198 ) ;
F_98 ( V_69 ) ;
}
}
void F_119 ( struct V_65 * V_66 , struct V_87 * V_88 , T_1 V_198 )
{
const struct V_74 * V_75 = ( const struct V_74 * ) V_66 -> V_172 ;
struct V_85 V_86 ;
struct V_61 * V_69 ;
struct V_1 * V_2 ;
bool V_202 = false ;
F_120 ( V_88 ) ;
V_69 = (struct V_61 * ) F_121 ( V_88 ) ;
if ( F_122 ( V_88 ) || ! V_69 ) {
F_117 ( V_66 , V_88 , V_198 ) ;
goto V_189;
}
F_52 ( & V_86 , V_88 , V_75 , 0 , 0 , 0 , 0 , 0 ) ;
if ( ! F_123 ( V_88 , 0 ) ) {
V_69 = F_124 ( F_118 ( V_88 ) , & V_86 , V_88 ) ;
if ( F_116 ( V_69 ) )
goto V_189;
V_202 = true ;
}
F_111 ( (struct V_61 * ) V_69 -> V_2 . V_203 , & V_86 , V_198 ) ;
V_2 = F_125 ( & V_69 -> V_2 , 0 ) ;
if ( ! V_2 ) {
if ( V_202 )
F_126 ( & V_69 -> V_2 ) ;
V_69 = F_124 ( F_118 ( V_88 ) , & V_86 , V_88 ) ;
if ( F_116 ( V_69 ) )
goto V_189;
V_202 = true ;
}
if ( V_202 )
F_127 ( V_88 , & V_69 -> V_2 ) ;
V_189:
F_128 ( V_88 ) ;
}
void F_129 ( struct V_65 * V_66 , struct V_48 * V_48 ,
int V_89 , T_1 V_92 , T_7 V_104 , int V_93 )
{
const struct V_74 * V_75 = ( const struct V_74 * ) V_66 -> V_172 ;
struct V_85 V_86 ;
struct V_61 * V_69 ;
F_52 ( & V_86 , NULL , V_75 , V_89 ,
F_57 ( V_75 -> V_90 ) , V_104 , V_92 , V_93 ) ;
V_69 = F_115 ( V_48 , & V_86 ) ;
if ( ! F_116 ( V_69 ) ) {
F_76 ( V_69 , V_66 , & V_86 , false ) ;
F_98 ( V_69 ) ;
}
}
void F_130 ( struct V_65 * V_66 , struct V_87 * V_88 )
{
const struct V_74 * V_75 = ( const struct V_74 * ) V_66 -> V_172 ;
struct V_85 V_86 ;
struct V_61 * V_69 ;
F_52 ( & V_86 , V_88 , V_75 , 0 , 0 , 0 , 0 , 0 ) ;
V_69 = F_115 ( F_118 ( V_88 ) , & V_86 ) ;
if ( ! F_116 ( V_69 ) ) {
F_76 ( V_69 , V_66 , & V_86 , false ) ;
F_98 ( V_69 ) ;
}
}
static struct V_1 * F_131 ( struct V_1 * V_2 , T_1 V_204 )
{
struct V_61 * V_69 = (struct V_61 * ) V_2 ;
if ( V_2 -> V_148 != V_205 || F_34 ( V_69 ) )
return NULL ;
return V_2 ;
}
static void F_132 ( struct V_65 * V_66 )
{
struct V_61 * V_69 ;
F_102 ( V_66 , V_197 , V_191 , 0 ) ;
V_69 = F_100 ( V_66 ) ;
if ( V_69 )
F_133 ( & V_69 -> V_2 , 0 ) ;
}
static int F_134 ( struct V_65 * V_66 )
{
F_135 ( L_13 ,
V_206 , & F_39 ( V_66 ) -> V_102 , & F_39 ( V_66 ) -> V_67 ,
V_66 -> V_4 ? V_66 -> V_4 -> V_173 : L_14 ) ;
F_110 ( V_66 ) ;
F_3 ( 1 ) ;
return 0 ;
}
void F_136 ( T_7 * V_207 , struct V_65 * V_66 , struct V_61 * V_69 )
{
T_6 V_39 ;
if ( F_137 ( V_69 ) )
V_39 = F_39 ( V_66 ) -> V_102 ;
else {
struct V_160 V_161 ;
struct V_85 V_86 ;
struct V_74 * V_75 ;
V_75 = F_39 ( V_66 ) ;
memset ( & V_86 , 0 , sizeof( V_86 ) ) ;
V_86 . V_67 = V_75 -> V_67 ;
V_86 . V_102 = V_75 -> V_102 ;
V_86 . V_208 = F_57 ( V_75 -> V_90 ) ;
V_86 . V_209 = V_69 -> V_2 . V_4 -> V_103 ;
V_86 . V_210 = V_66 -> V_4 -> V_103 ;
V_86 . V_211 = V_66 -> V_92 ;
F_59 () ;
if ( F_89 ( F_35 ( V_69 -> V_2 . V_4 ) , & V_86 , & V_161 ) == 0 )
V_39 = F_138 ( F_35 ( V_69 -> V_2 . V_4 ) , V_161 ) ;
else
V_39 = F_139 ( V_69 -> V_2 . V_4 ,
F_103 ( V_69 , V_75 -> V_67 ) ,
V_101 ) ;
F_62 () ;
}
memcpy ( V_207 , & V_39 , 4 ) ;
}
static void F_140 ( struct V_61 * V_69 , T_1 V_212 )
{
if ( ! ( V_69 -> V_2 . V_213 & 0xFFFF ) )
V_69 -> V_2 . V_213 |= V_212 & 0xFFFF ;
if ( ! ( V_69 -> V_2 . V_213 & 0xFFFF0000 ) )
V_69 -> V_2 . V_213 |= V_212 & 0xFFFF0000 ;
}
static unsigned int F_141 ( const struct V_1 * V_2 )
{
unsigned int V_214 = F_142 ( V_2 , V_215 ) ;
if ( V_214 == 0 ) {
V_214 = F_143 (unsigned int, dst->dev->mtu - 40 ,
ip_rt_min_advmss) ;
if ( V_214 > 65535 - 40 )
V_214 = 65535 - 40 ;
}
return V_214 ;
}
static unsigned int F_144 ( const struct V_1 * V_2 )
{
const struct V_61 * V_69 = ( const struct V_61 * ) V_2 ;
unsigned int V_198 = V_69 -> V_126 ;
if ( ! V_198 || F_145 ( V_152 , V_69 -> V_2 . V_128 ) )
V_198 = F_142 ( V_2 , V_199 ) ;
if ( V_198 )
return V_198 ;
V_198 = V_2 -> V_4 -> V_198 ;
if ( F_146 ( F_112 ( V_2 , V_199 ) ) ) {
if ( V_69 -> V_133 && V_198 > 576 )
V_198 = 576 ;
}
if ( V_198 > V_216 )
V_198 = V_216 ;
return V_198 ;
}
static struct V_114 * F_147 ( struct V_134 * V_135 , T_6 V_67 )
{
struct V_118 * V_119 = V_135 -> V_140 ;
struct V_114 * V_115 ;
T_1 V_124 ;
if ( ! V_119 )
return NULL ;
V_124 = F_70 ( V_67 ) ;
for ( V_115 = F_60 ( V_119 [ V_124 ] . V_121 ) ; V_115 ;
V_115 = F_60 ( V_115 -> V_122 ) ) {
if ( V_115 -> V_143 == V_67 )
return V_115 ;
}
return NULL ;
}
static bool F_148 ( struct V_61 * V_69 , struct V_114 * V_115 ,
T_6 V_67 )
{
bool V_174 = false ;
F_44 ( & V_139 ) ;
if ( V_67 == V_115 -> V_143 ) {
struct V_61 T_8 * * V_217 ;
struct V_61 * V_218 ;
int V_219 = V_145 ( F_35 ( V_69 -> V_2 . V_4 ) ) ;
if ( F_149 ( V_69 ) )
V_217 = & V_115 -> V_116 ;
else
V_217 = & V_115 -> V_117 ;
V_218 = F_60 ( * V_217 ) ;
if ( V_115 -> V_145 != V_219 ) {
V_115 -> V_145 = V_219 ;
V_115 -> V_130 = 0 ;
V_115 -> V_127 = 0 ;
V_115 -> V_129 = 0 ;
F_66 ( V_115 ) ;
V_218 = NULL ;
}
F_71 ( V_69 , V_115 ) ;
if ( ! V_69 -> V_71 )
V_69 -> V_71 = V_67 ;
if ( ! ( V_69 -> V_2 . V_220 & V_221 ) ) {
F_75 ( * V_217 , V_69 ) ;
if ( V_218 )
F_64 ( V_218 ) ;
V_174 = true ;
}
V_115 -> V_123 = V_152 ;
}
F_47 ( & V_139 ) ;
return V_174 ;
}
static bool F_150 ( struct V_134 * V_135 , struct V_61 * V_69 )
{
struct V_61 * V_218 , * V_222 , * * V_223 ;
bool V_174 = true ;
if ( F_149 ( V_69 ) ) {
V_223 = (struct V_61 * * ) & V_135 -> V_147 ;
} else {
V_223 = (struct V_61 * * ) F_151 ( V_135 -> V_151 ) ;
}
V_218 = * V_223 ;
V_222 = F_152 ( V_223 , V_218 , V_69 ) ;
if ( V_222 == V_218 ) {
if ( V_218 )
F_64 ( V_218 ) ;
} else
V_174 = false ;
return V_174 ;
}
static void F_153 ( struct V_61 * V_69 )
{
F_44 ( & V_224 ) ;
F_154 ( & V_69 -> V_225 , & V_226 ) ;
F_47 ( & V_224 ) ;
}
static void F_155 ( struct V_1 * V_2 )
{
struct V_61 * V_69 = (struct V_61 * ) V_2 ;
if ( ! F_156 ( & V_69 -> V_225 ) ) {
F_44 ( & V_224 ) ;
F_157 ( & V_69 -> V_225 ) ;
F_47 ( & V_224 ) ;
}
}
void F_158 ( struct V_3 * V_4 )
{
if ( ! F_156 ( & V_226 ) ) {
struct V_48 * V_48 = F_35 ( V_4 ) ;
struct V_61 * V_69 ;
F_44 ( & V_224 ) ;
F_159 (rt, &rt_uncached_list, rt_uncached) {
if ( V_69 -> V_2 . V_4 != V_4 )
continue;
V_69 -> V_2 . V_4 = V_48 -> V_227 ;
F_160 ( V_69 -> V_2 . V_4 ) ;
F_161 ( V_4 ) ;
}
F_47 ( & V_224 ) ;
}
}
static bool F_162 ( const struct V_61 * V_69 )
{
return V_69 &&
V_69 -> V_2 . V_148 == V_205 &&
! F_34 ( V_69 ) ;
}
static void F_163 ( struct V_61 * V_69 , T_6 V_67 ,
const struct V_160 * V_161 ,
struct V_114 * V_115 ,
struct V_228 * V_229 , T_9 type , T_1 V_230 )
{
bool V_231 = false ;
if ( V_229 ) {
struct V_134 * V_135 = & F_90 ( * V_161 ) ;
if ( V_135 -> V_232 && V_135 -> V_233 == V_234 ) {
V_69 -> V_71 = V_135 -> V_232 ;
V_69 -> V_133 = 1 ;
}
F_164 ( & V_69 -> V_2 , V_229 -> V_235 , true ) ;
#ifdef F_29
V_69 -> V_2 . V_213 = V_135 -> V_236 ;
#endif
if ( F_146 ( V_115 ) )
V_231 = F_148 ( V_69 , V_115 , V_67 ) ;
else if ( ! ( V_69 -> V_2 . V_220 & V_221 ) )
V_231 = F_150 ( V_135 , V_69 ) ;
if ( F_146 ( ! V_231 ) ) {
V_69 -> V_2 . V_220 |= V_221 ;
if ( ! V_69 -> V_71 )
V_69 -> V_71 = V_67 ;
F_153 ( V_69 ) ;
}
} else
F_153 ( V_69 ) ;
#ifdef F_29
#ifdef F_165
F_140 ( V_69 , V_161 -> V_213 ) ;
#endif
F_140 ( V_69 , V_230 ) ;
#endif
}
static struct V_61 * F_166 ( struct V_3 * V_4 ,
bool V_237 , bool V_238 , bool V_239 )
{
return F_167 ( & V_19 , V_4 , 1 , V_205 ,
( V_239 ? 0 : ( V_240 | V_221 ) ) |
( V_237 ? V_241 : 0 ) |
( V_238 ? V_242 : 0 ) ) ;
}
static int F_168 ( struct V_65 * V_66 , T_6 V_67 , T_6 V_102 ,
T_7 V_90 , struct V_3 * V_4 , int V_243 )
{
struct V_61 * V_62 ;
struct V_158 * V_159 = F_78 ( V_4 ) ;
T_1 V_230 = 0 ;
int V_244 ;
if ( V_159 == NULL )
return - V_190 ;
if ( F_80 ( V_102 ) || F_81 ( V_102 ) ||
V_66 -> V_104 != F_46 ( V_245 ) )
goto V_246;
if ( F_169 ( ! F_170 ( V_159 ) ) )
if ( F_171 ( V_102 ) )
goto V_246;
if ( F_82 ( V_102 ) ) {
if ( ! F_172 ( V_67 ) )
goto V_246;
} else {
V_244 = F_173 ( V_66 , V_102 , 0 , V_90 , 0 , V_4 ,
V_159 , & V_230 ) ;
if ( V_244 < 0 )
goto V_247;
}
V_62 = F_166 ( F_35 ( V_4 ) -> V_227 ,
F_174 ( V_159 , V_248 ) , false , false ) ;
if ( ! V_62 )
goto V_249;
#ifdef F_29
V_62 -> V_2 . V_213 = V_230 ;
#endif
V_62 -> V_2 . V_250 = F_134 ;
V_62 -> V_63 = V_63 ( F_35 ( V_4 ) ) ;
V_62 -> V_131 = V_251 ;
V_62 -> V_252 = V_253 ;
V_62 -> V_254 = 1 ;
V_62 -> V_255 = 0 ;
V_62 -> V_126 = 0 ;
V_62 -> V_71 = 0 ;
V_62 -> V_133 = 0 ;
F_175 ( & V_62 -> V_225 ) ;
if ( V_243 ) {
V_62 -> V_2 . V_256 = V_257 ;
V_62 -> V_131 |= V_258 ;
}
#ifdef F_176
if ( ! F_172 ( V_67 ) && F_177 ( V_159 ) )
V_62 -> V_2 . V_256 = V_259 ;
#endif
F_178 ( V_22 ) ;
F_179 ( V_66 , & V_62 -> V_2 ) ;
return 0 ;
V_249:
return - V_260 ;
V_246:
return - V_190 ;
V_247:
return V_244 ;
}
static void F_180 ( struct V_3 * V_4 ,
struct V_158 * V_159 ,
struct V_65 * V_66 ,
T_6 V_67 ,
T_6 V_102 )
{
F_178 ( V_26 ) ;
#ifdef F_93
if ( F_94 ( V_159 ) && F_181 () ) {
F_182 ( L_15 ,
& V_67 , & V_102 , V_4 -> V_173 ) ;
if ( V_4 -> V_261 && F_183 ( V_66 ) ) {
F_184 ( V_262 , L_16 ,
V_263 , 16 , 1 ,
F_185 ( V_66 ) ,
V_4 -> V_261 , true ) ;
}
}
#endif
}
static int F_186 ( struct V_65 * V_66 ,
const struct V_160 * V_161 ,
struct V_158 * V_159 ,
T_6 V_67 , T_6 V_102 , T_1 V_90 )
{
struct V_114 * V_115 ;
struct V_61 * V_62 ;
int V_244 ;
struct V_158 * V_264 ;
unsigned int V_220 = 0 ;
bool V_265 ;
T_1 V_230 ;
V_264 = F_78 ( F_187 ( * V_161 ) ) ;
if ( V_264 == NULL ) {
F_188 ( L_17 ) ;
return - V_190 ;
}
V_244 = F_173 ( V_66 , V_102 , V_67 , V_90 , F_189 ( * V_161 ) ,
V_159 -> V_4 , V_159 , & V_230 ) ;
if ( V_244 < 0 ) {
F_180 ( V_159 -> V_4 , V_159 , V_66 , V_67 ,
V_102 ) ;
goto V_266;
}
V_265 = V_161 -> V_229 && ! V_230 ;
if ( V_264 == V_159 && V_244 && F_101 ( V_264 ) &&
( F_83 ( V_264 ) ||
F_84 ( V_264 , V_102 , F_190 ( * V_161 ) ) ) ) {
V_220 |= V_267 ;
V_265 = false ;
}
if ( V_66 -> V_104 != F_46 ( V_245 ) ) {
if ( V_264 == V_159 &&
F_191 ( V_159 ) == 0 ) {
V_244 = - V_190 ;
goto V_266;
}
}
V_115 = F_147 ( & F_90 ( * V_161 ) , V_67 ) ;
if ( V_265 ) {
if ( V_115 != NULL )
V_62 = F_60 ( V_115 -> V_116 ) ;
else
V_62 = F_60 ( F_90 ( * V_161 ) . V_147 ) ;
if ( F_162 ( V_62 ) ) {
F_192 ( V_66 , & V_62 -> V_2 ) ;
goto V_189;
}
}
V_62 = F_166 ( V_264 -> V_4 ,
F_174 ( V_159 , V_248 ) ,
F_174 ( V_264 , V_268 ) , V_265 ) ;
if ( ! V_62 ) {
V_244 = - V_260 ;
goto V_266;
}
V_62 -> V_63 = V_63 ( F_35 ( V_62 -> V_2 . V_4 ) ) ;
V_62 -> V_131 = V_220 ;
V_62 -> V_252 = V_161 -> type ;
V_62 -> V_254 = 1 ;
V_62 -> V_255 = 0 ;
V_62 -> V_126 = 0 ;
V_62 -> V_71 = 0 ;
V_62 -> V_133 = 0 ;
F_175 ( & V_62 -> V_225 ) ;
V_62 -> V_2 . V_256 = V_269 ;
V_62 -> V_2 . V_250 = V_270 ;
F_163 ( V_62 , V_67 , V_161 , V_115 , V_161 -> V_229 , V_161 -> type , V_230 ) ;
F_179 ( V_66 , & V_62 -> V_2 ) ;
V_189:
V_244 = 0 ;
V_266:
return V_244 ;
}
static int F_193 ( struct V_65 * V_66 ,
struct V_160 * V_161 ,
const struct V_85 * V_86 ,
struct V_158 * V_159 ,
T_6 V_67 , T_6 V_102 , T_1 V_90 )
{
#ifdef F_194
if ( V_161 -> V_229 && V_161 -> V_229 -> V_271 > 1 )
F_195 ( V_161 ) ;
#endif
return F_186 ( V_66 , V_161 , V_159 , V_67 , V_102 , V_90 ) ;
}
static int F_196 ( struct V_65 * V_66 , T_6 V_67 , T_6 V_102 ,
T_7 V_90 , struct V_3 * V_4 )
{
struct V_160 V_161 ;
struct V_158 * V_159 = F_78 ( V_4 ) ;
struct V_85 V_86 ;
unsigned int V_220 = 0 ;
T_1 V_230 = 0 ;
struct V_61 * V_62 ;
int V_244 = - V_190 ;
struct V_48 * V_48 = F_35 ( V_4 ) ;
bool V_265 ;
if ( ! V_159 )
goto V_189;
if ( F_80 ( V_102 ) || F_81 ( V_102 ) )
goto V_272;
V_161 . V_229 = NULL ;
if ( F_81 ( V_67 ) || ( V_102 == 0 && V_67 == 0 ) )
goto V_273;
if ( F_82 ( V_102 ) )
goto V_272;
if ( F_82 ( V_67 ) )
goto V_274;
if ( F_171 ( V_67 ) ) {
if ( ! F_197 ( V_159 , V_48 ) )
goto V_274;
} else if ( F_171 ( V_102 ) ) {
if ( ! F_197 ( V_159 , V_48 ) )
goto V_272;
}
V_86 . V_209 = 0 ;
V_86 . V_210 = V_4 -> V_103 ;
V_86 . V_211 = V_66 -> V_92 ;
V_86 . V_208 = V_90 ;
V_86 . V_275 = V_101 ;
V_86 . V_67 = V_67 ;
V_86 . V_102 = V_102 ;
V_244 = F_89 ( V_48 , & V_86 , & V_161 ) ;
if ( V_244 != 0 )
goto V_276;
F_178 ( V_21 ) ;
if ( V_161 . type == V_277 )
goto V_273;
if ( V_161 . type == V_278 ) {
V_244 = F_173 ( V_66 , V_102 , V_67 , V_90 ,
V_279 ,
V_4 , V_159 , & V_230 ) ;
if ( V_244 < 0 )
goto V_280;
goto V_281;
}
if ( ! F_108 ( V_159 ) )
goto V_276;
if ( V_161 . type != V_168 )
goto V_274;
V_244 = F_193 ( V_66 , & V_161 , & V_86 , V_159 , V_67 , V_102 , V_90 ) ;
V_189: return V_244 ;
V_273:
if ( V_66 -> V_104 != F_46 ( V_245 ) )
goto V_246;
if ( ! F_82 ( V_102 ) ) {
V_244 = F_173 ( V_66 , V_102 , 0 , V_90 , 0 , V_4 ,
V_159 , & V_230 ) ;
if ( V_244 < 0 )
goto V_280;
}
V_220 |= V_282 ;
V_161 . type = V_277 ;
F_178 ( V_24 ) ;
V_281:
V_265 = false ;
if ( V_161 . V_229 ) {
if ( ! V_230 ) {
V_62 = F_60 ( F_90 ( V_161 ) . V_147 ) ;
if ( F_162 ( V_62 ) ) {
F_192 ( V_66 , & V_62 -> V_2 ) ;
V_244 = 0 ;
goto V_189;
}
V_265 = true ;
}
}
V_62 = F_166 ( V_48 -> V_227 ,
F_174 ( V_159 , V_248 ) , false , V_265 ) ;
if ( ! V_62 )
goto V_249;
V_62 -> V_2 . V_256 = V_257 ;
V_62 -> V_2 . V_250 = F_134 ;
#ifdef F_29
V_62 -> V_2 . V_213 = V_230 ;
#endif
V_62 -> V_63 = V_63 ( V_48 ) ;
V_62 -> V_131 = V_220 | V_258 ;
V_62 -> V_252 = V_161 . type ;
V_62 -> V_254 = 1 ;
V_62 -> V_255 = 0 ;
V_62 -> V_126 = 0 ;
V_62 -> V_71 = 0 ;
V_62 -> V_133 = 0 ;
F_175 ( & V_62 -> V_225 ) ;
if ( V_161 . type == V_283 ) {
V_62 -> V_2 . V_256 = F_107 ;
V_62 -> V_2 . error = - V_244 ;
V_62 -> V_131 &= ~ V_258 ;
}
if ( V_265 )
F_150 ( & F_90 ( V_161 ) , V_62 ) ;
F_179 ( V_66 , & V_62 -> V_2 ) ;
V_244 = 0 ;
goto V_189;
V_276:
F_178 ( V_23 ) ;
V_161 . type = V_283 ;
if ( V_244 == - V_284 )
V_244 = - V_187 ;
goto V_281;
V_274:
F_178 ( V_25 ) ;
#ifdef F_93
if ( F_94 ( V_159 ) )
F_105 ( L_18 ,
& V_67 , & V_102 , V_4 -> V_173 ) ;
#endif
V_246:
V_244 = - V_190 ;
goto V_189;
V_249:
V_244 = - V_260 ;
goto V_189;
V_272:
V_244 = - V_190 ;
V_280:
F_180 ( V_4 , V_159 , V_66 , V_67 , V_102 ) ;
goto V_189;
}
int F_198 ( struct V_65 * V_66 , T_6 V_67 , T_6 V_102 ,
T_7 V_90 , struct V_3 * V_4 )
{
int V_161 ;
F_59 () ;
if ( F_80 ( V_67 ) ) {
struct V_158 * V_159 = F_78 ( V_4 ) ;
if ( V_159 ) {
int V_243 = F_199 ( V_159 , V_67 , V_102 ,
F_39 ( V_66 ) -> V_104 ) ;
if ( V_243
#ifdef F_176
||
( ! F_172 ( V_67 ) &&
F_177 ( V_159 ) )
#endif
) {
int V_161 = F_168 ( V_66 , V_67 , V_102 ,
V_90 , V_4 , V_243 ) ;
F_62 () ;
return V_161 ;
}
}
F_62 () ;
return - V_190 ;
}
V_161 = F_196 ( V_66 , V_67 , V_102 , V_90 , V_4 ) ;
F_62 () ;
return V_161 ;
}
static struct V_61 * F_200 ( const struct V_160 * V_161 ,
const struct V_85 * V_86 , int V_285 ,
struct V_3 * V_286 ,
unsigned int V_220 )
{
struct V_228 * V_229 = V_161 -> V_229 ;
struct V_114 * V_115 ;
struct V_158 * V_159 ;
T_9 type = V_161 -> type ;
struct V_61 * V_62 ;
bool V_265 ;
V_159 = F_78 ( V_286 ) ;
if ( ! V_159 )
return F_201 ( - V_190 ) ;
if ( F_169 ( ! F_170 ( V_159 ) ) )
if ( F_171 ( V_86 -> V_102 ) && ! ( V_286 -> V_220 & V_287 ) )
return F_201 ( - V_190 ) ;
if ( F_81 ( V_86 -> V_67 ) )
type = V_277 ;
else if ( F_80 ( V_86 -> V_67 ) )
type = V_253 ;
else if ( F_82 ( V_86 -> V_67 ) )
return F_201 ( - V_190 ) ;
if ( V_286 -> V_220 & V_287 )
V_220 |= V_258 ;
V_265 = true ;
if ( type == V_277 ) {
V_220 |= V_282 | V_258 ;
V_229 = NULL ;
} else if ( type == V_253 ) {
V_220 |= V_251 | V_258 ;
if ( ! F_199 ( V_159 , V_86 -> V_67 , V_86 -> V_102 ,
V_86 -> V_288 ) )
V_220 &= ~ V_258 ;
else
V_265 = false ;
if ( V_229 && V_161 -> V_289 < 4 )
V_229 = NULL ;
}
V_115 = NULL ;
V_265 &= V_229 != NULL ;
if ( V_265 ) {
struct V_61 T_8 * * V_290 ;
struct V_134 * V_135 = & F_90 ( * V_161 ) ;
V_115 = F_147 ( V_135 , V_86 -> V_67 ) ;
if ( V_115 )
V_290 = & V_115 -> V_117 ;
else {
if ( F_146 ( V_86 -> V_291 &
V_292 &&
! ( V_135 -> V_232 &&
V_135 -> V_233 == V_234 ) ) ) {
V_265 = false ;
goto V_293;
}
V_290 = F_151 ( V_135 -> V_151 ) ;
}
V_62 = F_60 ( * V_290 ) ;
if ( F_162 ( V_62 ) ) {
F_202 ( & V_62 -> V_2 ) ;
return V_62 ;
}
}
V_293:
V_62 = F_166 ( V_286 ,
F_174 ( V_159 , V_248 ) ,
F_174 ( V_159 , V_268 ) ,
V_265 ) ;
if ( ! V_62 )
return F_201 ( - V_260 ) ;
V_62 -> V_2 . V_250 = V_270 ;
V_62 -> V_63 = V_63 ( F_35 ( V_286 ) ) ;
V_62 -> V_131 = V_220 ;
V_62 -> V_252 = type ;
V_62 -> V_254 = 0 ;
V_62 -> V_255 = V_285 ? : 0 ;
V_62 -> V_126 = 0 ;
V_62 -> V_71 = 0 ;
V_62 -> V_133 = 0 ;
F_175 ( & V_62 -> V_225 ) ;
F_178 ( V_28 ) ;
if ( V_220 & V_258 )
V_62 -> V_2 . V_256 = V_257 ;
if ( V_220 & ( V_282 | V_251 ) ) {
if ( V_220 & V_258 &&
! ( V_286 -> V_220 & V_287 ) ) {
V_62 -> V_2 . V_250 = V_294 ;
F_178 ( V_29 ) ;
}
#ifdef F_176
if ( type == V_253 ) {
if ( F_177 ( V_159 ) &&
! F_172 ( V_86 -> V_67 ) ) {
V_62 -> V_2 . V_256 = V_259 ;
V_62 -> V_2 . V_250 = V_294 ;
}
}
#endif
}
F_163 ( V_62 , V_86 -> V_67 , V_161 , V_115 , V_229 , type , 0 ) ;
return V_62 ;
}
struct V_61 * F_115 ( struct V_48 * V_48 , struct V_85 * V_86 )
{
struct V_3 * V_286 = NULL ;
T_10 V_90 = F_203 ( V_86 ) ;
unsigned int V_220 = 0 ;
struct V_160 V_161 ;
struct V_61 * V_62 ;
int V_285 ;
V_161 . V_213 = 0 ;
V_161 . V_229 = NULL ;
V_161 . V_295 = NULL ;
V_285 = V_86 -> V_209 ;
V_86 -> V_210 = V_279 ;
V_86 -> V_208 = V_90 & V_296 ;
V_86 -> V_275 = ( ( V_90 & V_297 ) ?
V_234 : V_101 ) ;
F_59 () ;
if ( V_86 -> V_102 ) {
V_62 = F_201 ( - V_190 ) ;
if ( F_80 ( V_86 -> V_102 ) ||
F_81 ( V_86 -> V_102 ) ||
F_82 ( V_86 -> V_102 ) )
goto V_189;
if ( V_86 -> V_209 == 0 &&
( F_80 ( V_86 -> V_67 ) ||
F_81 ( V_86 -> V_67 ) ) ) {
V_286 = F_204 ( V_48 , V_86 -> V_102 , false ) ;
if ( V_286 == NULL )
goto V_189;
V_86 -> V_209 = V_286 -> V_103 ;
goto V_298;
}
if ( ! ( V_86 -> V_291 & V_299 ) ) {
if ( ! F_204 ( V_48 , V_86 -> V_102 , false ) )
goto V_189;
}
}
if ( V_86 -> V_209 ) {
V_286 = F_205 ( V_48 , V_86 -> V_209 ) ;
V_62 = F_201 ( - V_300 ) ;
if ( V_286 == NULL )
goto V_189;
if ( ! ( V_286 -> V_220 & V_301 ) || ! F_78 ( V_286 ) ) {
V_62 = F_201 ( - V_187 ) ;
goto V_189;
}
if ( F_172 ( V_86 -> V_67 ) ||
F_81 ( V_86 -> V_67 ) ) {
if ( ! V_86 -> V_102 )
V_86 -> V_102 = F_139 ( V_286 , 0 ,
V_234 ) ;
goto V_298;
}
if ( V_86 -> V_102 ) {
if ( F_80 ( V_86 -> V_67 ) )
V_86 -> V_102 = F_139 ( V_286 , 0 ,
V_86 -> V_275 ) ;
else if ( ! V_86 -> V_67 )
V_86 -> V_102 = F_139 ( V_286 , 0 ,
V_302 ) ;
}
}
if ( ! V_86 -> V_67 ) {
V_86 -> V_67 = V_86 -> V_102 ;
if ( ! V_86 -> V_67 )
V_86 -> V_67 = V_86 -> V_102 = F_206 ( V_303 ) ;
V_286 = V_48 -> V_227 ;
V_86 -> V_209 = V_279 ;
V_161 . type = V_278 ;
V_220 |= V_258 ;
goto V_298;
}
if ( F_89 ( V_48 , V_86 , & V_161 ) ) {
V_161 . V_229 = NULL ;
V_161 . V_295 = NULL ;
if ( V_86 -> V_209 ) {
if ( V_86 -> V_102 == 0 )
V_86 -> V_102 = F_139 ( V_286 , 0 ,
V_234 ) ;
V_161 . type = V_168 ;
goto V_298;
}
V_62 = F_201 ( - V_187 ) ;
goto V_189;
}
if ( V_161 . type == V_278 ) {
if ( ! V_86 -> V_102 ) {
if ( V_161 . V_229 -> V_304 )
V_86 -> V_102 = V_161 . V_229 -> V_304 ;
else
V_86 -> V_102 = V_86 -> V_67 ;
}
V_286 = V_48 -> V_227 ;
V_86 -> V_209 = V_286 -> V_103 ;
V_220 |= V_258 ;
goto V_298;
}
#ifdef F_194
if ( V_161 . V_229 -> V_271 > 1 && V_86 -> V_209 == 0 )
F_195 ( & V_161 ) ;
else
#endif
if ( ! V_161 . V_289 &&
V_161 . V_295 -> V_305 > 1 &&
V_161 . type == V_168 && ! V_86 -> V_209 )
F_207 ( & V_161 ) ;
if ( ! V_86 -> V_102 )
V_86 -> V_102 = F_138 ( V_48 , V_161 ) ;
V_286 = F_187 ( V_161 ) ;
V_86 -> V_209 = V_286 -> V_103 ;
V_298:
V_62 = F_200 ( & V_161 , V_86 , V_285 , V_286 , V_220 ) ;
V_189:
F_62 () ;
return V_62 ;
}
static struct V_1 * F_208 ( struct V_1 * V_2 , T_1 V_204 )
{
return NULL ;
}
static unsigned int F_209 ( const struct V_1 * V_2 )
{
unsigned int V_198 = F_142 ( V_2 , V_199 ) ;
return V_198 ? : V_2 -> V_4 -> V_198 ;
}
static void F_210 ( struct V_1 * V_2 , struct V_87 * V_88 ,
struct V_65 * V_66 , T_1 V_198 )
{
}
static void F_211 ( struct V_1 * V_2 , struct V_87 * V_88 ,
struct V_65 * V_66 )
{
}
static T_1 * F_212 ( struct V_1 * V_2 ,
unsigned long V_6 )
{
return NULL ;
}
struct V_1 * F_213 ( struct V_48 * V_48 , struct V_1 * V_306 )
{
struct V_61 * V_307 = (struct V_61 * ) V_306 ;
struct V_61 * V_69 ;
V_69 = F_167 ( & V_308 , NULL , 1 , V_309 , 0 ) ;
if ( V_69 ) {
struct V_1 * V_202 = & V_69 -> V_2 ;
V_202 -> V_310 = 1 ;
V_202 -> V_256 = V_311 ;
V_202 -> V_250 = V_311 ;
V_202 -> V_4 = V_307 -> V_2 . V_4 ;
if ( V_202 -> V_4 )
F_160 ( V_202 -> V_4 ) ;
V_69 -> V_254 = V_307 -> V_254 ;
V_69 -> V_255 = V_307 -> V_255 ;
V_69 -> V_126 = V_307 -> V_126 ;
V_69 -> V_63 = V_63 ( V_48 ) ;
V_69 -> V_131 = V_307 -> V_131 ;
V_69 -> V_252 = V_307 -> V_252 ;
V_69 -> V_71 = V_307 -> V_71 ;
V_69 -> V_133 = V_307 -> V_133 ;
F_175 ( & V_69 -> V_225 ) ;
F_214 ( V_202 ) ;
}
F_126 ( V_306 ) ;
return V_69 ? & V_69 -> V_2 : F_201 ( - V_43 ) ;
}
struct V_61 * F_124 ( struct V_48 * V_48 , struct V_85 * V_312 ,
struct V_87 * V_88 )
{
struct V_61 * V_69 = F_115 ( V_48 , V_312 ) ;
if ( F_116 ( V_69 ) )
return V_69 ;
if ( V_312 -> V_288 )
V_69 = (struct V_61 * ) F_215 ( V_48 , & V_69 -> V_2 ,
F_216 ( V_312 ) ,
V_88 , 0 ) ;
return V_69 ;
}
static int F_217 ( struct V_48 * V_48 , T_6 V_2 , T_6 V_39 ,
struct V_85 * V_86 , struct V_65 * V_66 , T_1 V_313 ,
T_1 V_8 , int V_314 , int V_315 , unsigned int V_220 )
{
struct V_61 * V_69 = F_100 ( V_66 ) ;
struct V_316 * V_317 ;
struct V_318 * V_319 ;
unsigned long V_128 = 0 ;
T_1 error ;
T_1 V_320 [ V_321 ] ;
V_319 = F_218 ( V_66 , V_313 , V_8 , V_314 , sizeof( * V_317 ) , V_220 ) ;
if ( V_319 == NULL )
return - V_322 ;
V_317 = F_219 ( V_319 ) ;
V_317 -> V_323 = V_324 ;
V_317 -> V_325 = 32 ;
V_317 -> V_326 = 0 ;
V_317 -> V_327 = V_86 -> V_208 ;
V_317 -> V_328 = V_329 ;
if ( F_220 ( V_66 , V_330 , V_329 ) )
goto V_331;
V_317 -> V_332 = V_69 -> V_252 ;
V_317 -> V_333 = V_101 ;
V_317 -> V_334 = V_335 ;
V_317 -> V_336 = ( V_69 -> V_131 & ~ 0xFFFF ) | V_337 ;
if ( V_69 -> V_131 & V_338 )
V_317 -> V_336 |= V_339 ;
if ( F_221 ( V_66 , V_340 , V_2 ) )
goto V_331;
if ( V_39 ) {
V_317 -> V_326 = 32 ;
if ( F_221 ( V_66 , V_341 , V_39 ) )
goto V_331;
}
if ( V_69 -> V_2 . V_4 &&
F_220 ( V_66 , V_342 , V_69 -> V_2 . V_4 -> V_103 ) )
goto V_331;
#ifdef F_29
if ( V_69 -> V_2 . V_213 &&
F_220 ( V_66 , V_343 , V_69 -> V_2 . V_213 ) )
goto V_331;
#endif
if ( ! F_149 ( V_69 ) &&
V_86 -> V_102 != V_39 ) {
if ( F_221 ( V_66 , V_344 , V_86 -> V_102 ) )
goto V_331;
}
if ( V_69 -> V_133 &&
F_221 ( V_66 , V_345 , V_69 -> V_71 ) )
goto V_331;
V_128 = V_69 -> V_2 . V_128 ;
if ( V_128 ) {
unsigned long V_183 = V_152 ;
if ( F_69 ( V_183 , V_128 ) )
V_128 -= V_183 ;
else
V_128 = 0 ;
}
memcpy ( V_320 , F_222 ( & V_69 -> V_2 ) , sizeof( V_320 ) ) ;
if ( V_69 -> V_126 && V_128 )
V_320 [ V_199 - 1 ] = V_69 -> V_126 ;
if ( F_223 ( V_66 , V_320 ) < 0 )
goto V_331;
if ( V_86 -> V_211 &&
F_220 ( V_66 , V_346 , V_86 -> V_211 ) )
goto V_331;
error = V_69 -> V_2 . error ;
if ( F_149 ( V_69 ) ) {
#ifdef F_176
if ( F_80 ( V_2 ) && ! F_172 ( V_2 ) &&
F_224 ( V_48 , V_347 ) ) {
int V_244 = F_225 ( V_48 , V_66 ,
V_86 -> V_102 , V_86 -> V_67 ,
V_317 , V_315 ) ;
if ( V_244 <= 0 ) {
if ( ! V_315 ) {
if ( V_244 == 0 )
return 0 ;
goto V_331;
} else {
if ( V_244 == - V_322 )
goto V_331;
error = V_244 ;
}
}
} else
#endif
if ( F_220 ( V_66 , V_348 , V_69 -> V_255 ) )
goto V_331;
}
if ( F_226 ( V_66 , & V_69 -> V_2 , 0 , V_128 , error ) < 0 )
goto V_331;
return F_227 ( V_66 , V_319 ) ;
V_331:
F_228 ( V_66 , V_319 ) ;
return - V_322 ;
}
static int F_229 ( struct V_65 * V_349 , struct V_318 * V_319 )
{
struct V_48 * V_48 = F_118 ( V_349 -> V_88 ) ;
struct V_316 * V_350 ;
struct V_351 * V_352 [ V_353 + 1 ] ;
struct V_61 * V_69 = NULL ;
struct V_85 V_86 ;
T_6 V_2 = 0 ;
T_6 V_39 = 0 ;
T_1 V_354 ;
int V_244 ;
int V_92 ;
struct V_65 * V_66 ;
V_244 = F_230 ( V_319 , sizeof( * V_350 ) , V_352 , V_353 , V_355 ) ;
if ( V_244 < 0 )
goto V_356;
V_350 = F_219 ( V_319 ) ;
V_66 = F_231 ( V_357 , V_42 ) ;
if ( V_66 == NULL ) {
V_244 = - V_260 ;
goto V_356;
}
F_232 ( V_66 ) ;
F_233 ( V_66 ) ;
F_39 ( V_66 ) -> V_104 = V_358 ;
F_234 ( V_66 , V_359 + sizeof( struct V_74 ) ) ;
V_39 = V_352 [ V_341 ] ? F_235 ( V_352 [ V_341 ] ) : 0 ;
V_2 = V_352 [ V_340 ] ? F_235 ( V_352 [ V_340 ] ) : 0 ;
V_354 = V_352 [ V_348 ] ? F_236 ( V_352 [ V_348 ] ) : 0 ;
V_92 = V_352 [ V_346 ] ? F_236 ( V_352 [ V_346 ] ) : 0 ;
memset ( & V_86 , 0 , sizeof( V_86 ) ) ;
V_86 . V_67 = V_2 ;
V_86 . V_102 = V_39 ;
V_86 . V_208 = V_350 -> V_327 ;
V_86 . V_209 = V_352 [ V_342 ] ? F_236 ( V_352 [ V_342 ] ) : 0 ;
V_86 . V_211 = V_92 ;
if ( V_354 ) {
struct V_3 * V_4 ;
V_4 = F_237 ( V_48 , V_354 ) ;
if ( V_4 == NULL ) {
V_244 = - V_300 ;
goto V_360;
}
V_66 -> V_104 = F_46 ( V_245 ) ;
V_66 -> V_4 = V_4 ;
V_66 -> V_92 = V_92 ;
F_238 () ;
V_244 = F_239 ( V_66 , V_2 , V_39 , V_350 -> V_327 , V_4 ) ;
F_240 () ;
V_69 = F_100 ( V_66 ) ;
if ( V_244 == 0 && V_69 -> V_2 . error )
V_244 = - V_69 -> V_2 . error ;
} else {
V_69 = F_241 ( V_48 , & V_86 ) ;
V_244 = 0 ;
if ( F_116 ( V_69 ) )
V_244 = F_242 ( V_69 ) ;
}
if ( V_244 )
goto V_360;
F_179 ( V_66 , & V_69 -> V_2 ) ;
if ( V_350 -> V_336 & V_339 )
V_69 -> V_131 |= V_338 ;
V_244 = F_217 ( V_48 , V_2 , V_39 , & V_86 , V_66 ,
F_243 ( V_349 ) . V_313 , V_319 -> V_361 ,
V_362 , 0 , 0 ) ;
if ( V_244 <= 0 )
goto V_360;
V_244 = F_244 ( V_66 , V_48 , F_243 ( V_349 ) . V_313 ) ;
V_356:
return V_244 ;
V_360:
F_110 ( V_66 ) ;
goto V_356;
}
int F_245 ( struct V_65 * V_66 , struct V_363 * V_364 )
{
return V_66 -> V_365 ;
}
void F_246 ( struct V_158 * V_159 )
{
F_36 ( F_35 ( V_159 -> V_4 ) ) ;
}
static int F_247 ( struct V_366 * V_367 , int V_368 ,
void T_11 * V_369 ,
T_12 * V_370 , T_2 * V_371 )
{
struct V_48 * V_48 = (struct V_48 * ) V_367 -> V_372 ;
if ( V_368 ) {
F_36 ( V_48 ) ;
F_248 ( V_48 ) ;
return 0 ;
}
return - V_190 ;
}
static T_3 int F_249 ( struct V_48 * V_48 )
{
struct V_366 * V_373 ;
V_373 = V_374 ;
if ( ! F_250 ( V_48 , & V_375 ) ) {
V_373 = F_251 ( V_373 , sizeof( V_374 ) , V_42 ) ;
if ( V_373 == NULL )
goto V_376;
if ( V_48 -> V_377 != & V_378 )
V_373 [ 0 ] . V_379 = NULL ;
}
V_373 [ 0 ] . V_372 = V_48 ;
V_48 -> V_83 . V_380 = F_252 ( V_48 , L_19 , V_373 ) ;
if ( V_48 -> V_83 . V_380 == NULL )
goto V_381;
return 0 ;
V_381:
if ( V_373 != V_374 )
F_24 ( V_373 ) ;
V_376:
return - V_43 ;
}
static T_4 void F_253 ( struct V_48 * V_48 )
{
struct V_366 * V_373 ;
V_373 = V_48 -> V_83 . V_380 -> V_382 ;
F_254 ( V_48 -> V_83 . V_380 ) ;
F_255 ( V_373 == V_374 ) ;
F_24 ( V_373 ) ;
}
static T_3 int F_256 ( struct V_48 * V_48 )
{
F_257 ( & V_48 -> V_63 , 0 ) ;
F_257 ( & V_48 -> V_145 , 0 ) ;
F_258 ( & V_48 -> V_83 . V_383 ,
sizeof( V_48 -> V_83 . V_383 ) ) ;
return 0 ;
}
static int T_3 F_259 ( struct V_48 * V_48 )
{
struct V_384 * V_385 = F_260 ( sizeof( * V_385 ) , V_42 ) ;
if ( ! V_385 )
return - V_43 ;
F_261 ( V_385 ) ;
V_48 -> V_83 . V_84 = V_385 ;
return 0 ;
}
static void T_4 F_262 ( struct V_48 * V_48 )
{
struct V_384 * V_385 = V_48 -> V_83 . V_84 ;
V_48 -> V_83 . V_84 = NULL ;
F_263 ( V_385 ) ;
F_24 ( V_385 ) ;
}
int T_5 F_264 ( void )
{
int V_386 = 0 ;
#ifdef F_29
V_38 = F_265 ( 256 * sizeof( struct V_38 ) , F_266 ( struct V_38 ) ) ;
if ( ! V_38 )
F_267 ( L_20 ) ;
#endif
V_19 . V_387 =
F_268 ( L_21 , sizeof( struct V_61 ) , 0 ,
V_388 | V_389 , NULL ) ;
V_308 . V_387 = V_19 . V_387 ;
if ( F_269 ( & V_19 ) < 0 )
F_267 ( L_22 ) ;
if ( F_269 ( & V_308 ) < 0 )
F_267 ( L_23 ) ;
V_19 . V_390 = ~ 0 ;
V_391 = V_392 ;
F_270 () ;
F_271 () ;
if ( F_32 () )
F_272 ( L_24 ) ;
#ifdef F_273
F_274 () ;
F_275 () ;
#endif
F_276 ( V_393 , V_394 , F_229 , NULL , NULL ) ;
#ifdef F_277
F_33 ( & V_395 ) ;
#endif
F_33 ( & V_396 ) ;
F_33 ( & V_397 ) ;
return V_386 ;
}
void T_5 F_278 ( void )
{
F_252 ( & V_375 , L_19 , V_398 ) ;
}
