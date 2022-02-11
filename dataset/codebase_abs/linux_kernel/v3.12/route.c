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
return V_62 -> V_63 != F_35 ( F_36 ( V_62 -> V_2 . V_4 ) ) ;
}
void F_37 ( struct V_48 * V_48 )
{
F_38 ( V_48 ) ;
}
static struct V_64 * F_39 ( const struct V_1 * V_2 ,
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
V_68 = & F_40 ( V_66 ) -> V_67 ;
V_70 = F_41 ( V_4 , * ( V_72 T_1 * ) V_68 ) ;
if ( V_70 )
return V_70 ;
return F_42 ( & V_73 , V_68 , V_4 ) ;
}
static void F_43 ( struct V_74 * V_75 )
{
static F_44 ( V_76 ) ;
static T_1 V_77 ;
T_1 V_78 ;
F_45 ( & V_76 ) ;
V_78 = F_46 ( ( V_72 T_6 ) V_77 ^ V_75 -> V_67 ) ;
V_75 -> V_79 = F_47 ( V_78 & 0xFFFF ) ;
V_77 = V_78 ;
F_48 ( & V_76 ) ;
}
void F_49 ( struct V_74 * V_75 , struct V_1 * V_2 , int V_80 )
{
struct V_48 * V_48 = F_36 ( V_2 -> V_4 ) ;
struct V_81 * V_82 ;
V_82 = F_50 ( V_48 -> V_83 . V_84 , V_75 -> V_67 , 1 ) ;
if ( V_82 ) {
V_75 -> V_79 = F_47 ( F_51 ( V_82 , V_80 ) ) ;
F_52 ( V_82 ) ;
return;
}
F_43 ( V_75 ) ;
}
static void F_53 ( struct V_85 * V_86 , const struct V_87 * V_88 ,
const struct V_74 * V_75 ,
int V_89 , T_7 V_90 ,
T_7 V_91 , T_1 V_92 , int V_93 )
{
if ( V_88 ) {
const struct V_94 * V_95 = F_54 ( V_88 ) ;
V_89 = V_88 -> V_96 ;
V_92 = V_88 -> V_97 ;
V_90 = F_55 ( V_88 ) ;
V_91 = V_95 -> V_98 ? V_99 : V_88 -> V_100 ;
}
F_56 ( V_86 , V_89 , V_92 , V_90 ,
V_101 , V_91 ,
V_93 ,
V_75 -> V_67 , V_75 -> V_102 , 0 , 0 ) ;
}
static void F_57 ( struct V_85 * V_86 , const struct V_65 * V_66 ,
const struct V_87 * V_88 )
{
const struct V_74 * V_75 = F_40 ( V_66 ) ;
int V_89 = V_66 -> V_4 -> V_103 ;
T_7 V_90 = F_58 ( V_75 -> V_90 ) ;
T_7 V_91 = V_75 -> V_104 ;
T_1 V_92 = V_66 -> V_92 ;
F_53 ( V_86 , V_88 , V_75 , V_89 , V_90 , V_91 , V_92 , 0 ) ;
}
static void F_59 ( struct V_85 * V_86 , const struct V_87 * V_88 )
{
const struct V_94 * V_95 = F_54 ( V_88 ) ;
const struct V_105 * V_106 ;
T_6 V_67 = V_95 -> V_107 ;
F_60 () ;
V_106 = F_61 ( V_95 -> V_106 ) ;
if ( V_106 && V_106 -> V_108 . V_109 )
V_67 = V_106 -> V_108 . V_110 ;
F_56 ( V_86 , V_88 -> V_96 , V_88 -> V_97 ,
F_55 ( V_88 ) , V_101 ,
V_95 -> V_98 ? V_99 : V_88 -> V_100 ,
F_62 ( V_88 ) ,
V_67 , V_95 -> V_111 , 0 , 0 ) ;
F_63 () ;
}
static void F_64 ( struct V_85 * V_86 , const struct V_87 * V_88 ,
const struct V_65 * V_66 )
{
if ( V_66 )
F_57 ( V_86 , V_66 , V_88 ) ;
else
F_59 ( V_86 , V_88 ) ;
}
static inline void F_65 ( struct V_61 * V_69 )
{
F_66 ( & V_69 -> V_2 . V_112 , V_113 ) ;
}
static void F_67 ( struct V_114 * V_115 )
{
struct V_61 * V_69 ;
V_69 = F_61 ( V_115 -> V_116 ) ;
if ( V_69 ) {
F_68 ( V_115 -> V_116 , NULL ) ;
F_65 ( V_69 ) ;
}
V_69 = F_61 ( V_115 -> V_117 ) ;
if ( V_69 ) {
F_68 ( V_115 -> V_117 , NULL ) ;
F_65 ( V_69 ) ;
}
}
static struct V_114 * F_69 ( struct V_118 * V_119 )
{
struct V_114 * V_115 , * V_120 ;
V_120 = F_61 ( V_119 -> V_121 ) ;
for ( V_115 = F_61 ( V_120 -> V_122 ) ; V_115 ;
V_115 = F_61 ( V_115 -> V_122 ) ) {
if ( F_70 ( V_115 -> V_123 , V_120 -> V_123 ) )
V_120 = V_115 ;
}
F_67 ( V_120 ) ;
return V_120 ;
}
static inline T_1 F_71 ( T_6 V_67 )
{
T_1 V_124 ;
V_124 = ( V_72 T_1 ) V_67 ;
V_124 ^= ( V_124 >> 11 ) ^ ( V_124 >> 22 ) ;
return V_124 & ( V_125 - 1 ) ;
}
static void F_72 ( struct V_61 * V_69 , struct V_114 * V_115 )
{
V_69 -> V_126 = V_115 -> V_127 ;
V_69 -> V_2 . V_128 = V_115 -> V_129 ;
if ( V_115 -> V_130 ) {
V_69 -> V_131 |= V_132 ;
V_69 -> V_71 = V_115 -> V_130 ;
V_69 -> V_133 = 1 ;
}
}
static void F_73 ( struct V_134 * V_135 , T_6 V_67 , T_6 V_136 ,
T_1 V_137 , unsigned long V_128 )
{
struct V_118 * V_119 ;
struct V_114 * V_115 ;
struct V_61 * V_69 ;
unsigned int V_40 ;
int V_138 ;
T_1 V_124 = F_71 ( V_67 ) ;
F_45 ( & V_139 ) ;
V_119 = V_135 -> V_140 ;
if ( ! V_119 ) {
V_119 = F_74 ( V_125 * sizeof( * V_119 ) , V_141 ) ;
if ( ! V_119 )
goto V_142;
V_135 -> V_140 = V_119 ;
}
V_119 += V_124 ;
V_138 = 0 ;
for ( V_115 = F_61 ( V_119 -> V_121 ) ; V_115 ;
V_115 = F_61 ( V_115 -> V_122 ) ) {
if ( V_115 -> V_143 == V_67 )
break;
V_138 ++ ;
}
if ( V_115 ) {
if ( V_136 )
V_115 -> V_130 = V_136 ;
if ( V_137 ) {
V_115 -> V_127 = V_137 ;
V_115 -> V_129 = F_75 ( 1UL , V_128 ) ;
}
V_69 = F_61 ( V_115 -> V_116 ) ;
if ( V_69 )
F_72 ( V_69 , V_115 ) ;
V_69 = F_61 ( V_115 -> V_117 ) ;
if ( V_69 )
F_72 ( V_69 , V_115 ) ;
} else {
if ( V_138 > V_144 )
V_115 = F_69 ( V_119 ) ;
else {
V_115 = F_74 ( sizeof( * V_115 ) , V_141 ) ;
if ( ! V_115 )
goto V_142;
V_115 -> V_122 = V_119 -> V_121 ;
F_76 ( V_119 -> V_121 , V_115 ) ;
}
V_115 -> V_145 = V_145 ( F_36 ( V_135 -> V_146 ) ) ;
V_115 -> V_143 = V_67 ;
V_115 -> V_130 = V_136 ;
V_115 -> V_127 = V_137 ;
V_115 -> V_129 = V_128 ;
V_69 = F_61 ( V_135 -> V_147 ) ;
if ( V_69 )
V_69 -> V_2 . V_148 = V_149 ;
F_21 (i) {
struct V_61 T_8 * * V_150 ;
V_150 = F_22 ( V_135 -> V_151 , V_40 ) ;
V_69 = F_61 ( * V_150 ) ;
if ( V_69 )
V_69 -> V_2 . V_148 = V_149 ;
}
}
V_115 -> V_123 = V_152 ;
V_142:
F_48 ( & V_139 ) ;
return;
}
static void F_77 ( struct V_61 * V_69 , struct V_65 * V_66 , struct V_85 * V_86 ,
bool V_153 )
{
T_6 V_154 = F_78 ( V_66 ) -> V_155 . V_156 ;
T_6 V_157 = F_40 ( V_66 ) -> V_102 ;
struct V_3 * V_4 = V_66 -> V_4 ;
struct V_158 * V_159 ;
struct V_160 V_161 ;
struct V_64 * V_70 ;
struct V_48 * V_48 ;
switch ( F_78 ( V_66 ) -> V_162 & 7 ) {
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
V_159 = F_79 ( V_4 ) ;
if ( ! V_159 )
return;
V_48 = F_36 ( V_4 ) ;
if ( V_154 == V_157 || ! F_80 ( V_159 ) ||
F_81 ( V_154 ) || F_82 ( V_154 ) ||
F_83 ( V_154 ) )
goto V_167;
if ( ! F_84 ( V_159 ) ) {
if ( ! F_85 ( V_159 , V_154 , V_157 ) )
goto V_167;
if ( F_86 ( V_159 ) && F_87 ( V_154 , V_4 ) )
goto V_167;
} else {
if ( F_88 ( V_48 , V_154 ) != V_168 )
goto V_167;
}
V_70 = F_39 ( & V_69 -> V_2 , NULL , & V_154 ) ;
if ( V_70 ) {
if ( ! ( V_70 -> V_169 & V_170 ) ) {
F_89 ( V_70 , NULL ) ;
} else {
if ( F_90 ( V_48 , V_86 , & V_161 ) == 0 ) {
struct V_134 * V_135 = & F_91 ( V_161 ) ;
F_73 ( V_135 , V_86 -> V_67 , V_154 ,
0 , 0 ) ;
}
if ( V_153 )
V_69 -> V_2 . V_148 = V_149 ;
F_92 ( V_171 , V_70 ) ;
}
F_93 ( V_70 ) ;
}
return;
V_167:
#ifdef F_94
if ( F_95 ( V_159 ) ) {
const struct V_74 * V_75 = ( const struct V_74 * ) V_66 -> V_172 ;
T_6 V_67 = V_75 -> V_67 ;
T_6 V_102 = V_75 -> V_102 ;
F_96 ( L_10
L_11 ,
& V_157 , V_4 -> V_173 , & V_154 ,
& V_102 , & V_67 ) ;
}
#endif
;
}
static void F_97 ( struct V_1 * V_2 , struct V_87 * V_88 , struct V_65 * V_66 )
{
struct V_61 * V_69 ;
struct V_85 V_86 ;
const struct V_74 * V_75 = ( const struct V_74 * ) V_66 -> V_172 ;
int V_89 = V_66 -> V_4 -> V_103 ;
T_7 V_90 = F_58 ( V_75 -> V_90 ) ;
T_7 V_91 = V_75 -> V_104 ;
T_1 V_92 = V_66 -> V_92 ;
V_69 = (struct V_61 * ) V_2 ;
F_53 ( & V_86 , V_88 , V_75 , V_89 , V_90 , V_91 , V_92 , 0 ) ;
F_77 ( V_69 , V_66 , & V_86 , true ) ;
}
static struct V_1 * F_98 ( struct V_1 * V_2 )
{
struct V_61 * V_69 = (struct V_61 * ) V_2 ;
struct V_1 * V_174 = V_2 ;
if ( V_69 ) {
if ( V_2 -> V_148 > 0 ) {
F_99 ( V_69 ) ;
V_174 = NULL ;
} else if ( ( V_69 -> V_131 & V_132 ) ||
V_69 -> V_2 . V_128 ) {
F_99 ( V_69 ) ;
V_174 = NULL ;
}
}
return V_174 ;
}
void F_100 ( struct V_65 * V_66 )
{
struct V_61 * V_69 = F_101 ( V_66 ) ;
struct V_158 * V_159 ;
struct V_81 * V_82 ;
struct V_48 * V_48 ;
int V_175 ;
F_60 () ;
V_159 = F_79 ( V_69 -> V_2 . V_4 ) ;
if ( ! V_159 || ! F_102 ( V_159 ) ) {
F_63 () ;
return;
}
V_175 = F_95 ( V_159 ) ;
F_63 () ;
V_48 = F_36 ( V_69 -> V_2 . V_4 ) ;
V_82 = F_50 ( V_48 -> V_83 . V_84 , F_40 ( V_66 ) -> V_102 , 1 ) ;
if ( ! V_82 ) {
F_103 ( V_66 , V_176 , V_165 ,
F_104 ( V_69 , F_40 ( V_66 ) -> V_67 ) ) ;
return;
}
if ( F_105 ( V_152 , V_82 -> V_177 + V_178 ) )
V_82 -> V_179 = 0 ;
if ( V_82 -> V_179 >= V_180 ) {
V_82 -> V_177 = V_152 ;
goto V_181;
}
if ( V_82 -> V_179 == 0 ||
F_105 ( V_152 ,
( V_82 -> V_177 +
( V_182 << V_82 -> V_179 ) ) ) ) {
T_6 V_136 = F_104 ( V_69 , F_40 ( V_66 ) -> V_67 ) ;
F_103 ( V_66 , V_176 , V_165 , V_136 ) ;
V_82 -> V_177 = V_152 ;
++ V_82 -> V_179 ;
#ifdef F_94
if ( V_175 &&
V_82 -> V_179 == V_180 )
F_106 ( L_12 ,
& F_40 ( V_66 ) -> V_102 , F_107 ( V_66 ) ,
& F_40 ( V_66 ) -> V_67 , & V_136 ) ;
#endif
}
V_181:
F_52 ( V_82 ) ;
}
static int F_108 ( struct V_65 * V_66 )
{
struct V_158 * V_159 = F_79 ( V_66 -> V_4 ) ;
struct V_61 * V_69 = F_101 ( V_66 ) ;
struct V_81 * V_82 ;
unsigned long V_183 ;
struct V_48 * V_48 ;
bool V_184 ;
int V_162 ;
V_48 = F_36 ( V_69 -> V_2 . V_4 ) ;
if ( ! F_109 ( V_159 ) ) {
switch ( V_69 -> V_2 . error ) {
case V_185 :
F_110 ( V_48 , V_186 ) ;
break;
case V_187 :
F_110 ( V_48 , V_188 ) ;
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
F_110 ( V_48 , V_188 ) ;
break;
case V_193 :
V_162 = V_194 ;
break;
}
V_82 = F_50 ( V_48 -> V_83 . V_84 , F_40 ( V_66 ) -> V_102 , 1 ) ;
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
F_52 ( V_82 ) ;
}
if ( V_184 )
F_103 ( V_66 , V_197 , V_162 , 0 ) ;
V_189: F_111 ( V_66 ) ;
return 0 ;
}
static void F_112 ( struct V_61 * V_69 , struct V_85 * V_86 , T_1 V_198 )
{
struct V_1 * V_2 = & V_69 -> V_2 ;
struct V_160 V_161 ;
if ( F_113 ( V_2 , V_199 ) )
return;
if ( V_2 -> V_4 -> V_198 < V_198 )
return;
if ( V_198 < V_200 )
V_198 = V_200 ;
if ( V_69 -> V_126 == V_198 &&
F_70 ( V_152 , V_2 -> V_128 - V_201 / 2 ) )
return;
F_60 () ;
if ( F_90 ( F_36 ( V_2 -> V_4 ) , V_86 , & V_161 ) == 0 ) {
struct V_134 * V_135 = & F_91 ( V_161 ) ;
F_73 ( V_135 , V_86 -> V_67 , 0 , V_198 ,
V_152 + V_201 ) ;
}
F_63 () ;
}
static void F_114 ( struct V_1 * V_2 , struct V_87 * V_88 ,
struct V_65 * V_66 , T_1 V_198 )
{
struct V_61 * V_69 = (struct V_61 * ) V_2 ;
struct V_85 V_86 ;
F_64 ( & V_86 , V_88 , V_66 ) ;
F_112 ( V_69 , & V_86 , V_198 ) ;
}
void F_115 ( struct V_65 * V_66 , struct V_48 * V_48 , T_1 V_198 ,
int V_89 , T_1 V_92 , T_7 V_104 , int V_93 )
{
const struct V_74 * V_75 = ( const struct V_74 * ) V_66 -> V_172 ;
struct V_85 V_86 ;
struct V_61 * V_69 ;
F_53 ( & V_86 , NULL , V_75 , V_89 ,
F_58 ( V_75 -> V_90 ) , V_104 , V_92 , V_93 ) ;
V_69 = F_116 ( V_48 , & V_86 ) ;
if ( ! F_117 ( V_69 ) ) {
F_112 ( V_69 , & V_86 , V_198 ) ;
F_99 ( V_69 ) ;
}
}
static void F_118 ( struct V_65 * V_66 , struct V_87 * V_88 , T_1 V_198 )
{
const struct V_74 * V_75 = ( const struct V_74 * ) V_66 -> V_172 ;
struct V_85 V_86 ;
struct V_61 * V_69 ;
F_53 ( & V_86 , V_88 , V_75 , 0 , 0 , 0 , 0 , 0 ) ;
V_69 = F_116 ( F_119 ( V_88 ) , & V_86 ) ;
if ( ! F_117 ( V_69 ) ) {
F_112 ( V_69 , & V_86 , V_198 ) ;
F_99 ( V_69 ) ;
}
}
void F_120 ( struct V_65 * V_66 , struct V_87 * V_88 , T_1 V_198 )
{
const struct V_74 * V_75 = ( const struct V_74 * ) V_66 -> V_172 ;
struct V_85 V_86 ;
struct V_61 * V_69 ;
struct V_1 * V_2 ;
bool V_202 = false ;
F_121 ( V_88 ) ;
V_69 = (struct V_61 * ) F_122 ( V_88 ) ;
if ( F_123 ( V_88 ) || ! V_69 ) {
F_118 ( V_66 , V_88 , V_198 ) ;
goto V_189;
}
F_53 ( & V_86 , V_88 , V_75 , 0 , 0 , 0 , 0 , 0 ) ;
if ( ! F_124 ( V_88 , 0 ) ) {
V_69 = F_125 ( F_119 ( V_88 ) , & V_86 , V_88 ) ;
if ( F_117 ( V_69 ) )
goto V_189;
V_202 = true ;
}
F_112 ( (struct V_61 * ) V_69 -> V_2 . V_203 , & V_86 , V_198 ) ;
V_2 = F_126 ( & V_69 -> V_2 , 0 ) ;
if ( ! V_2 ) {
if ( V_202 )
F_127 ( & V_69 -> V_2 ) ;
V_69 = F_125 ( F_119 ( V_88 ) , & V_86 , V_88 ) ;
if ( F_117 ( V_69 ) )
goto V_189;
V_202 = true ;
}
if ( V_202 )
F_128 ( V_88 , & V_69 -> V_2 ) ;
V_189:
F_129 ( V_88 ) ;
}
void F_130 ( struct V_65 * V_66 , struct V_48 * V_48 ,
int V_89 , T_1 V_92 , T_7 V_104 , int V_93 )
{
const struct V_74 * V_75 = ( const struct V_74 * ) V_66 -> V_172 ;
struct V_85 V_86 ;
struct V_61 * V_69 ;
F_53 ( & V_86 , NULL , V_75 , V_89 ,
F_58 ( V_75 -> V_90 ) , V_104 , V_92 , V_93 ) ;
V_69 = F_116 ( V_48 , & V_86 ) ;
if ( ! F_117 ( V_69 ) ) {
F_77 ( V_69 , V_66 , & V_86 , false ) ;
F_99 ( V_69 ) ;
}
}
void F_131 ( struct V_65 * V_66 , struct V_87 * V_88 )
{
const struct V_74 * V_75 = ( const struct V_74 * ) V_66 -> V_172 ;
struct V_85 V_86 ;
struct V_61 * V_69 ;
F_53 ( & V_86 , V_88 , V_75 , 0 , 0 , 0 , 0 , 0 ) ;
V_69 = F_116 ( F_119 ( V_88 ) , & V_86 ) ;
if ( ! F_117 ( V_69 ) ) {
F_77 ( V_69 , V_66 , & V_86 , false ) ;
F_99 ( V_69 ) ;
}
}
static struct V_1 * F_132 ( struct V_1 * V_2 , T_1 V_204 )
{
struct V_61 * V_69 = (struct V_61 * ) V_2 ;
if ( V_2 -> V_148 != V_205 || F_34 ( V_69 ) )
return NULL ;
return V_2 ;
}
static void F_133 ( struct V_65 * V_66 )
{
struct V_61 * V_69 ;
F_103 ( V_66 , V_197 , V_191 , 0 ) ;
V_69 = F_101 ( V_66 ) ;
if ( V_69 )
F_134 ( & V_69 -> V_2 , 0 ) ;
}
static int F_135 ( struct V_65 * V_66 )
{
F_136 ( L_13 ,
V_206 , & F_40 ( V_66 ) -> V_102 , & F_40 ( V_66 ) -> V_67 ,
V_66 -> V_4 ? V_66 -> V_4 -> V_173 : L_14 ) ;
F_111 ( V_66 ) ;
F_3 ( 1 ) ;
return 0 ;
}
void F_137 ( T_7 * V_207 , struct V_65 * V_66 , struct V_61 * V_69 )
{
T_6 V_39 ;
if ( F_138 ( V_69 ) )
V_39 = F_40 ( V_66 ) -> V_102 ;
else {
struct V_160 V_161 ;
struct V_85 V_86 ;
struct V_74 * V_75 ;
V_75 = F_40 ( V_66 ) ;
memset ( & V_86 , 0 , sizeof( V_86 ) ) ;
V_86 . V_67 = V_75 -> V_67 ;
V_86 . V_102 = V_75 -> V_102 ;
V_86 . V_208 = F_58 ( V_75 -> V_90 ) ;
V_86 . V_209 = V_69 -> V_2 . V_4 -> V_103 ;
V_86 . V_210 = V_66 -> V_4 -> V_103 ;
V_86 . V_211 = V_66 -> V_92 ;
F_60 () ;
if ( F_90 ( F_36 ( V_69 -> V_2 . V_4 ) , & V_86 , & V_161 ) == 0 )
V_39 = F_139 ( F_36 ( V_69 -> V_2 . V_4 ) , V_161 ) ;
else
V_39 = F_140 ( V_69 -> V_2 . V_4 ,
F_104 ( V_69 , V_75 -> V_67 ) ,
V_101 ) ;
F_63 () ;
}
memcpy ( V_207 , & V_39 , 4 ) ;
}
static void F_141 ( struct V_61 * V_69 , T_1 V_212 )
{
if ( ! ( V_69 -> V_2 . V_213 & 0xFFFF ) )
V_69 -> V_2 . V_213 |= V_212 & 0xFFFF ;
if ( ! ( V_69 -> V_2 . V_213 & 0xFFFF0000 ) )
V_69 -> V_2 . V_213 |= V_212 & 0xFFFF0000 ;
}
static unsigned int F_142 ( const struct V_1 * V_2 )
{
unsigned int V_214 = F_143 ( V_2 , V_215 ) ;
if ( V_214 == 0 ) {
V_214 = F_144 (unsigned int, dst->dev->mtu - 40 ,
ip_rt_min_advmss) ;
if ( V_214 > 65535 - 40 )
V_214 = 65535 - 40 ;
}
return V_214 ;
}
static unsigned int F_145 ( const struct V_1 * V_2 )
{
const struct V_61 * V_69 = ( const struct V_61 * ) V_2 ;
unsigned int V_198 = V_69 -> V_126 ;
if ( ! V_198 || F_146 ( V_152 , V_69 -> V_2 . V_128 ) )
V_198 = F_143 ( V_2 , V_199 ) ;
if ( V_198 )
return V_198 ;
V_198 = V_2 -> V_4 -> V_198 ;
if ( F_147 ( F_113 ( V_2 , V_199 ) ) ) {
if ( V_69 -> V_133 && V_198 > 576 )
V_198 = 576 ;
}
return F_148 (unsigned int, mtu, IP_MAX_MTU) ;
}
static struct V_114 * F_149 ( struct V_134 * V_135 , T_6 V_67 )
{
struct V_118 * V_119 = V_135 -> V_140 ;
struct V_114 * V_115 ;
T_1 V_124 ;
if ( ! V_119 )
return NULL ;
V_124 = F_71 ( V_67 ) ;
for ( V_115 = F_61 ( V_119 [ V_124 ] . V_121 ) ; V_115 ;
V_115 = F_61 ( V_115 -> V_122 ) ) {
if ( V_115 -> V_143 == V_67 )
return V_115 ;
}
return NULL ;
}
static bool F_150 ( struct V_61 * V_69 , struct V_114 * V_115 ,
T_6 V_67 )
{
bool V_174 = false ;
F_45 ( & V_139 ) ;
if ( V_67 == V_115 -> V_143 ) {
struct V_61 T_8 * * V_216 ;
struct V_61 * V_217 ;
int V_218 = V_145 ( F_36 ( V_69 -> V_2 . V_4 ) ) ;
if ( F_151 ( V_69 ) )
V_216 = & V_115 -> V_116 ;
else
V_216 = & V_115 -> V_117 ;
V_217 = F_61 ( * V_216 ) ;
if ( V_115 -> V_145 != V_218 ) {
V_115 -> V_145 = V_218 ;
V_115 -> V_130 = 0 ;
V_115 -> V_127 = 0 ;
V_115 -> V_129 = 0 ;
F_67 ( V_115 ) ;
V_217 = NULL ;
}
F_72 ( V_69 , V_115 ) ;
if ( ! V_69 -> V_71 )
V_69 -> V_71 = V_67 ;
if ( ! ( V_69 -> V_2 . V_219 & V_220 ) ) {
F_76 ( * V_216 , V_69 ) ;
if ( V_217 )
F_65 ( V_217 ) ;
V_174 = true ;
}
V_115 -> V_123 = V_152 ;
}
F_48 ( & V_139 ) ;
return V_174 ;
}
static bool F_152 ( struct V_134 * V_135 , struct V_61 * V_69 )
{
struct V_61 * V_217 , * V_221 , * * V_222 ;
bool V_174 = true ;
if ( F_151 ( V_69 ) ) {
V_222 = (struct V_61 * * ) & V_135 -> V_147 ;
} else {
V_222 = (struct V_61 * * ) F_153 ( V_135 -> V_151 ) ;
}
V_217 = * V_222 ;
V_221 = F_154 ( V_222 , V_217 , V_69 ) ;
if ( V_221 == V_217 ) {
if ( V_217 )
F_65 ( V_217 ) ;
} else
V_174 = false ;
return V_174 ;
}
static void F_155 ( struct V_61 * V_69 )
{
F_45 ( & V_223 ) ;
F_156 ( & V_69 -> V_224 , & V_225 ) ;
F_48 ( & V_223 ) ;
}
static void F_157 ( struct V_1 * V_2 )
{
struct V_61 * V_69 = (struct V_61 * ) V_2 ;
if ( ! F_158 ( & V_69 -> V_224 ) ) {
F_45 ( & V_223 ) ;
F_159 ( & V_69 -> V_224 ) ;
F_48 ( & V_223 ) ;
}
}
void F_160 ( struct V_3 * V_4 )
{
if ( ! F_158 ( & V_225 ) ) {
struct V_48 * V_48 = F_36 ( V_4 ) ;
struct V_61 * V_69 ;
F_45 ( & V_223 ) ;
F_161 (rt, &rt_uncached_list, rt_uncached) {
if ( V_69 -> V_2 . V_4 != V_4 )
continue;
V_69 -> V_2 . V_4 = V_48 -> V_226 ;
F_162 ( V_69 -> V_2 . V_4 ) ;
F_163 ( V_4 ) ;
}
F_48 ( & V_223 ) ;
}
}
static bool F_164 ( const struct V_61 * V_69 )
{
return V_69 &&
V_69 -> V_2 . V_148 == V_205 &&
! F_34 ( V_69 ) ;
}
static void F_165 ( struct V_61 * V_69 , T_6 V_67 ,
const struct V_160 * V_161 ,
struct V_114 * V_115 ,
struct V_227 * V_228 , T_9 type , T_1 V_229 )
{
bool V_230 = false ;
if ( V_228 ) {
struct V_134 * V_135 = & F_91 ( * V_161 ) ;
if ( V_135 -> V_231 && V_135 -> V_232 == V_233 ) {
V_69 -> V_71 = V_135 -> V_231 ;
V_69 -> V_133 = 1 ;
}
F_166 ( & V_69 -> V_2 , V_228 -> V_234 , true ) ;
#ifdef F_29
V_69 -> V_2 . V_213 = V_135 -> V_235 ;
#endif
if ( F_147 ( V_115 ) )
V_230 = F_150 ( V_69 , V_115 , V_67 ) ;
else if ( ! ( V_69 -> V_2 . V_219 & V_220 ) )
V_230 = F_152 ( V_135 , V_69 ) ;
if ( F_147 ( ! V_230 ) ) {
V_69 -> V_2 . V_219 |= V_220 ;
if ( ! V_69 -> V_71 )
V_69 -> V_71 = V_67 ;
F_155 ( V_69 ) ;
}
} else
F_155 ( V_69 ) ;
#ifdef F_29
#ifdef F_167
F_141 ( V_69 , V_161 -> V_213 ) ;
#endif
F_141 ( V_69 , V_229 ) ;
#endif
}
static struct V_61 * F_168 ( struct V_3 * V_4 ,
bool V_236 , bool V_237 , bool V_238 )
{
return F_169 ( & V_19 , V_4 , 1 , V_205 ,
( V_238 ? 0 : ( V_239 | V_220 ) ) |
( V_236 ? V_240 : 0 ) |
( V_237 ? V_241 : 0 ) ) ;
}
static int F_170 ( struct V_65 * V_66 , T_6 V_67 , T_6 V_102 ,
T_7 V_90 , struct V_3 * V_4 , int V_242 )
{
struct V_61 * V_62 ;
struct V_158 * V_159 = F_79 ( V_4 ) ;
T_1 V_229 = 0 ;
int V_243 ;
if ( V_159 == NULL )
return - V_190 ;
if ( F_81 ( V_102 ) || F_82 ( V_102 ) ||
V_66 -> V_104 != F_47 ( V_244 ) )
goto V_245;
if ( F_171 ( ! F_172 ( V_159 ) ) )
if ( F_173 ( V_102 ) )
goto V_245;
if ( F_83 ( V_102 ) ) {
if ( ! F_174 ( V_67 ) )
goto V_245;
} else {
V_243 = F_175 ( V_66 , V_102 , 0 , V_90 , 0 , V_4 ,
V_159 , & V_229 ) ;
if ( V_243 < 0 )
goto V_246;
}
V_62 = F_168 ( F_36 ( V_4 ) -> V_226 ,
F_176 ( V_159 , V_247 ) , false , false ) ;
if ( ! V_62 )
goto V_248;
#ifdef F_29
V_62 -> V_2 . V_213 = V_229 ;
#endif
V_62 -> V_2 . V_249 = F_135 ;
V_62 -> V_63 = F_35 ( F_36 ( V_4 ) ) ;
V_62 -> V_131 = V_250 ;
V_62 -> V_251 = V_252 ;
V_62 -> V_253 = 1 ;
V_62 -> V_254 = 0 ;
V_62 -> V_126 = 0 ;
V_62 -> V_71 = 0 ;
V_62 -> V_133 = 0 ;
F_177 ( & V_62 -> V_224 ) ;
if ( V_242 ) {
V_62 -> V_2 . V_255 = V_256 ;
V_62 -> V_131 |= V_257 ;
}
#ifdef F_178
if ( ! F_174 ( V_67 ) && F_179 ( V_159 ) )
V_62 -> V_2 . V_255 = V_258 ;
#endif
F_180 ( V_22 ) ;
F_181 ( V_66 , & V_62 -> V_2 ) ;
return 0 ;
V_248:
return - V_259 ;
V_245:
return - V_190 ;
V_246:
return V_243 ;
}
static void F_182 ( struct V_3 * V_4 ,
struct V_158 * V_159 ,
struct V_65 * V_66 ,
T_6 V_67 ,
T_6 V_102 )
{
F_180 ( V_26 ) ;
#ifdef F_94
if ( F_95 ( V_159 ) && F_183 () ) {
F_184 ( L_15 ,
& V_67 , & V_102 , V_4 -> V_173 ) ;
if ( V_4 -> V_260 && F_185 ( V_66 ) ) {
F_186 ( V_261 , L_16 ,
V_262 , 16 , 1 ,
F_187 ( V_66 ) ,
V_4 -> V_260 , true ) ;
}
}
#endif
}
static int F_188 ( struct V_65 * V_66 ,
const struct V_160 * V_161 ,
struct V_158 * V_159 ,
T_6 V_67 , T_6 V_102 , T_1 V_90 )
{
struct V_114 * V_115 ;
struct V_61 * V_62 ;
int V_243 ;
struct V_158 * V_263 ;
unsigned int V_219 = 0 ;
bool V_264 ;
T_1 V_229 ;
V_263 = F_79 ( F_189 ( * V_161 ) ) ;
if ( V_263 == NULL ) {
F_190 ( L_17 ) ;
return - V_190 ;
}
V_243 = F_175 ( V_66 , V_102 , V_67 , V_90 , F_191 ( * V_161 ) ,
V_159 -> V_4 , V_159 , & V_229 ) ;
if ( V_243 < 0 ) {
F_182 ( V_159 -> V_4 , V_159 , V_66 , V_67 ,
V_102 ) ;
goto V_265;
}
V_264 = V_161 -> V_228 && ! V_229 ;
if ( V_263 == V_159 && V_243 && F_102 ( V_263 ) &&
( F_84 ( V_263 ) ||
F_85 ( V_263 , V_102 , F_192 ( * V_161 ) ) ) ) {
V_219 |= V_266 ;
V_264 = false ;
}
if ( V_66 -> V_104 != F_47 ( V_244 ) ) {
if ( V_263 == V_159 &&
F_193 ( V_159 ) == 0 ) {
V_243 = - V_190 ;
goto V_265;
}
}
V_115 = F_149 ( & F_91 ( * V_161 ) , V_67 ) ;
if ( V_264 ) {
if ( V_115 != NULL )
V_62 = F_61 ( V_115 -> V_116 ) ;
else
V_62 = F_61 ( F_91 ( * V_161 ) . V_147 ) ;
if ( F_164 ( V_62 ) ) {
F_194 ( V_66 , & V_62 -> V_2 ) ;
goto V_189;
}
}
V_62 = F_168 ( V_263 -> V_4 ,
F_176 ( V_159 , V_247 ) ,
F_176 ( V_263 , V_267 ) , V_264 ) ;
if ( ! V_62 ) {
V_243 = - V_259 ;
goto V_265;
}
V_62 -> V_63 = F_35 ( F_36 ( V_62 -> V_2 . V_4 ) ) ;
V_62 -> V_131 = V_219 ;
V_62 -> V_251 = V_161 -> type ;
V_62 -> V_253 = 1 ;
V_62 -> V_254 = 0 ;
V_62 -> V_126 = 0 ;
V_62 -> V_71 = 0 ;
V_62 -> V_133 = 0 ;
F_177 ( & V_62 -> V_224 ) ;
V_62 -> V_2 . V_255 = V_268 ;
V_62 -> V_2 . V_249 = V_269 ;
F_165 ( V_62 , V_67 , V_161 , V_115 , V_161 -> V_228 , V_161 -> type , V_229 ) ;
F_181 ( V_66 , & V_62 -> V_2 ) ;
V_189:
V_243 = 0 ;
V_265:
return V_243 ;
}
static int F_195 ( struct V_65 * V_66 ,
struct V_160 * V_161 ,
const struct V_85 * V_86 ,
struct V_158 * V_159 ,
T_6 V_67 , T_6 V_102 , T_1 V_90 )
{
#ifdef F_196
if ( V_161 -> V_228 && V_161 -> V_228 -> V_270 > 1 )
F_197 ( V_161 ) ;
#endif
return F_188 ( V_66 , V_161 , V_159 , V_67 , V_102 , V_90 ) ;
}
static int F_198 ( struct V_65 * V_66 , T_6 V_67 , T_6 V_102 ,
T_7 V_90 , struct V_3 * V_4 )
{
struct V_160 V_161 ;
struct V_158 * V_159 = F_79 ( V_4 ) ;
struct V_85 V_86 ;
unsigned int V_219 = 0 ;
T_1 V_229 = 0 ;
struct V_61 * V_62 ;
int V_243 = - V_190 ;
struct V_48 * V_48 = F_36 ( V_4 ) ;
bool V_264 ;
if ( ! V_159 )
goto V_189;
if ( F_81 ( V_102 ) || F_82 ( V_102 ) )
goto V_271;
V_161 . V_228 = NULL ;
if ( F_82 ( V_67 ) || ( V_102 == 0 && V_67 == 0 ) )
goto V_272;
if ( F_83 ( V_102 ) )
goto V_271;
if ( F_83 ( V_67 ) )
goto V_273;
if ( F_173 ( V_67 ) ) {
if ( ! F_199 ( V_159 , V_48 ) )
goto V_273;
} else if ( F_173 ( V_102 ) ) {
if ( ! F_199 ( V_159 , V_48 ) )
goto V_271;
}
V_86 . V_209 = 0 ;
V_86 . V_210 = V_4 -> V_103 ;
V_86 . V_211 = V_66 -> V_92 ;
V_86 . V_208 = V_90 ;
V_86 . V_274 = V_101 ;
V_86 . V_67 = V_67 ;
V_86 . V_102 = V_102 ;
V_243 = F_90 ( V_48 , & V_86 , & V_161 ) ;
if ( V_243 != 0 )
goto V_275;
F_180 ( V_21 ) ;
if ( V_161 . type == V_276 )
goto V_272;
if ( V_161 . type == V_277 ) {
V_243 = F_175 ( V_66 , V_102 , V_67 , V_90 ,
V_278 ,
V_4 , V_159 , & V_229 ) ;
if ( V_243 < 0 )
goto V_279;
goto V_280;
}
if ( ! F_109 ( V_159 ) )
goto V_275;
if ( V_161 . type != V_168 )
goto V_273;
V_243 = F_195 ( V_66 , & V_161 , & V_86 , V_159 , V_67 , V_102 , V_90 ) ;
V_189: return V_243 ;
V_272:
if ( V_66 -> V_104 != F_47 ( V_244 ) )
goto V_245;
if ( ! F_83 ( V_102 ) ) {
V_243 = F_175 ( V_66 , V_102 , 0 , V_90 , 0 , V_4 ,
V_159 , & V_229 ) ;
if ( V_243 < 0 )
goto V_279;
}
V_219 |= V_281 ;
V_161 . type = V_276 ;
F_180 ( V_24 ) ;
V_280:
V_264 = false ;
if ( V_161 . V_228 ) {
if ( ! V_229 ) {
V_62 = F_61 ( F_91 ( V_161 ) . V_147 ) ;
if ( F_164 ( V_62 ) ) {
F_194 ( V_66 , & V_62 -> V_2 ) ;
V_243 = 0 ;
goto V_189;
}
V_264 = true ;
}
}
V_62 = F_168 ( V_48 -> V_226 ,
F_176 ( V_159 , V_247 ) , false , V_264 ) ;
if ( ! V_62 )
goto V_248;
V_62 -> V_2 . V_255 = V_256 ;
V_62 -> V_2 . V_249 = F_135 ;
#ifdef F_29
V_62 -> V_2 . V_213 = V_229 ;
#endif
V_62 -> V_63 = F_35 ( V_48 ) ;
V_62 -> V_131 = V_219 | V_257 ;
V_62 -> V_251 = V_161 . type ;
V_62 -> V_253 = 1 ;
V_62 -> V_254 = 0 ;
V_62 -> V_126 = 0 ;
V_62 -> V_71 = 0 ;
V_62 -> V_133 = 0 ;
F_177 ( & V_62 -> V_224 ) ;
if ( V_161 . type == V_282 ) {
V_62 -> V_2 . V_255 = F_108 ;
V_62 -> V_2 . error = - V_243 ;
V_62 -> V_131 &= ~ V_257 ;
}
if ( V_264 )
F_152 ( & F_91 ( V_161 ) , V_62 ) ;
F_181 ( V_66 , & V_62 -> V_2 ) ;
V_243 = 0 ;
goto V_189;
V_275:
F_180 ( V_23 ) ;
V_161 . type = V_282 ;
if ( V_243 == - V_283 )
V_243 = - V_187 ;
goto V_280;
V_273:
F_180 ( V_25 ) ;
#ifdef F_94
if ( F_95 ( V_159 ) )
F_106 ( L_18 ,
& V_67 , & V_102 , V_4 -> V_173 ) ;
#endif
V_245:
V_243 = - V_190 ;
goto V_189;
V_248:
V_243 = - V_259 ;
goto V_189;
V_271:
V_243 = - V_190 ;
V_279:
F_182 ( V_4 , V_159 , V_66 , V_67 , V_102 ) ;
goto V_189;
}
int F_200 ( struct V_65 * V_66 , T_6 V_67 , T_6 V_102 ,
T_7 V_90 , struct V_3 * V_4 )
{
int V_161 ;
F_60 () ;
if ( F_81 ( V_67 ) ) {
struct V_158 * V_159 = F_79 ( V_4 ) ;
if ( V_159 ) {
int V_242 = F_201 ( V_159 , V_67 , V_102 ,
F_40 ( V_66 ) -> V_104 ) ;
if ( V_242
#ifdef F_178
||
( ! F_174 ( V_67 ) &&
F_179 ( V_159 ) )
#endif
) {
int V_161 = F_170 ( V_66 , V_67 , V_102 ,
V_90 , V_4 , V_242 ) ;
F_63 () ;
return V_161 ;
}
}
F_63 () ;
return - V_190 ;
}
V_161 = F_198 ( V_66 , V_67 , V_102 , V_90 , V_4 ) ;
F_63 () ;
return V_161 ;
}
static struct V_61 * F_202 ( const struct V_160 * V_161 ,
const struct V_85 * V_86 , int V_284 ,
struct V_3 * V_285 ,
unsigned int V_219 )
{
struct V_227 * V_228 = V_161 -> V_228 ;
struct V_114 * V_115 ;
struct V_158 * V_159 ;
T_9 type = V_161 -> type ;
struct V_61 * V_62 ;
bool V_264 ;
V_159 = F_79 ( V_285 ) ;
if ( ! V_159 )
return F_203 ( - V_190 ) ;
if ( F_171 ( ! F_172 ( V_159 ) ) )
if ( F_173 ( V_86 -> V_102 ) && ! ( V_285 -> V_219 & V_286 ) )
return F_203 ( - V_190 ) ;
if ( F_82 ( V_86 -> V_67 ) )
type = V_276 ;
else if ( F_81 ( V_86 -> V_67 ) )
type = V_252 ;
else if ( F_83 ( V_86 -> V_67 ) )
return F_203 ( - V_190 ) ;
if ( V_285 -> V_219 & V_286 )
V_219 |= V_257 ;
V_264 = true ;
if ( type == V_276 ) {
V_219 |= V_281 | V_257 ;
V_228 = NULL ;
} else if ( type == V_252 ) {
V_219 |= V_250 | V_257 ;
if ( ! F_201 ( V_159 , V_86 -> V_67 , V_86 -> V_102 ,
V_86 -> V_287 ) )
V_219 &= ~ V_257 ;
else
V_264 = false ;
if ( V_228 && V_161 -> V_288 < 4 )
V_228 = NULL ;
}
V_115 = NULL ;
V_264 &= V_228 != NULL ;
if ( V_264 ) {
struct V_61 T_8 * * V_289 ;
struct V_134 * V_135 = & F_91 ( * V_161 ) ;
V_115 = F_149 ( V_135 , V_86 -> V_67 ) ;
if ( V_115 )
V_289 = & V_115 -> V_117 ;
else {
if ( F_147 ( V_86 -> V_290 &
V_291 &&
! ( V_135 -> V_231 &&
V_135 -> V_232 == V_233 ) ) ) {
V_264 = false ;
goto V_292;
}
V_289 = F_153 ( V_135 -> V_151 ) ;
}
V_62 = F_61 ( * V_289 ) ;
if ( F_164 ( V_62 ) ) {
F_204 ( & V_62 -> V_2 ) ;
return V_62 ;
}
}
V_292:
V_62 = F_168 ( V_285 ,
F_176 ( V_159 , V_247 ) ,
F_176 ( V_159 , V_267 ) ,
V_264 ) ;
if ( ! V_62 )
return F_203 ( - V_259 ) ;
V_62 -> V_2 . V_249 = V_269 ;
V_62 -> V_63 = F_35 ( F_36 ( V_285 ) ) ;
V_62 -> V_131 = V_219 ;
V_62 -> V_251 = type ;
V_62 -> V_253 = 0 ;
V_62 -> V_254 = V_284 ? : 0 ;
V_62 -> V_126 = 0 ;
V_62 -> V_71 = 0 ;
V_62 -> V_133 = 0 ;
F_177 ( & V_62 -> V_224 ) ;
F_180 ( V_28 ) ;
if ( V_219 & V_257 )
V_62 -> V_2 . V_255 = V_256 ;
if ( V_219 & ( V_281 | V_250 ) ) {
if ( V_219 & V_257 &&
! ( V_285 -> V_219 & V_286 ) ) {
V_62 -> V_2 . V_249 = V_293 ;
F_180 ( V_29 ) ;
}
#ifdef F_178
if ( type == V_252 ) {
if ( F_179 ( V_159 ) &&
! F_174 ( V_86 -> V_67 ) ) {
V_62 -> V_2 . V_255 = V_258 ;
V_62 -> V_2 . V_249 = V_293 ;
}
}
#endif
}
F_165 ( V_62 , V_86 -> V_67 , V_161 , V_115 , V_228 , type , 0 ) ;
return V_62 ;
}
struct V_61 * F_116 ( struct V_48 * V_48 , struct V_85 * V_86 )
{
struct V_3 * V_285 = NULL ;
T_10 V_90 = F_205 ( V_86 ) ;
unsigned int V_219 = 0 ;
struct V_160 V_161 ;
struct V_61 * V_62 ;
int V_284 ;
V_161 . V_213 = 0 ;
V_161 . V_228 = NULL ;
V_161 . V_294 = NULL ;
V_284 = V_86 -> V_209 ;
V_86 -> V_210 = V_278 ;
V_86 -> V_208 = V_90 & V_295 ;
V_86 -> V_274 = ( ( V_90 & V_296 ) ?
V_233 : V_101 ) ;
F_60 () ;
if ( V_86 -> V_102 ) {
V_62 = F_203 ( - V_190 ) ;
if ( F_81 ( V_86 -> V_102 ) ||
F_82 ( V_86 -> V_102 ) ||
F_83 ( V_86 -> V_102 ) )
goto V_189;
if ( V_86 -> V_209 == 0 &&
( F_81 ( V_86 -> V_67 ) ||
F_82 ( V_86 -> V_67 ) ) ) {
V_285 = F_206 ( V_48 , V_86 -> V_102 , false ) ;
if ( V_285 == NULL )
goto V_189;
V_86 -> V_209 = V_285 -> V_103 ;
goto V_297;
}
if ( ! ( V_86 -> V_290 & V_298 ) ) {
if ( ! F_206 ( V_48 , V_86 -> V_102 , false ) )
goto V_189;
}
}
if ( V_86 -> V_209 ) {
V_285 = F_207 ( V_48 , V_86 -> V_209 ) ;
V_62 = F_203 ( - V_299 ) ;
if ( V_285 == NULL )
goto V_189;
if ( ! ( V_285 -> V_219 & V_300 ) || ! F_79 ( V_285 ) ) {
V_62 = F_203 ( - V_187 ) ;
goto V_189;
}
if ( F_174 ( V_86 -> V_67 ) ||
F_82 ( V_86 -> V_67 ) ) {
if ( ! V_86 -> V_102 )
V_86 -> V_102 = F_140 ( V_285 , 0 ,
V_233 ) ;
goto V_297;
}
if ( ! V_86 -> V_102 ) {
if ( F_81 ( V_86 -> V_67 ) )
V_86 -> V_102 = F_140 ( V_285 , 0 ,
V_86 -> V_274 ) ;
else if ( ! V_86 -> V_67 )
V_86 -> V_102 = F_140 ( V_285 , 0 ,
V_301 ) ;
}
}
if ( ! V_86 -> V_67 ) {
V_86 -> V_67 = V_86 -> V_102 ;
if ( ! V_86 -> V_67 )
V_86 -> V_67 = V_86 -> V_102 = F_208 ( V_302 ) ;
V_285 = V_48 -> V_226 ;
V_86 -> V_209 = V_278 ;
V_161 . type = V_277 ;
V_219 |= V_257 ;
goto V_297;
}
if ( F_90 ( V_48 , V_86 , & V_161 ) ) {
V_161 . V_228 = NULL ;
V_161 . V_294 = NULL ;
if ( V_86 -> V_209 ) {
if ( V_86 -> V_102 == 0 )
V_86 -> V_102 = F_140 ( V_285 , 0 ,
V_233 ) ;
V_161 . type = V_168 ;
goto V_297;
}
V_62 = F_203 ( - V_187 ) ;
goto V_189;
}
if ( V_161 . type == V_277 ) {
if ( ! V_86 -> V_102 ) {
if ( V_161 . V_228 -> V_303 )
V_86 -> V_102 = V_161 . V_228 -> V_303 ;
else
V_86 -> V_102 = V_86 -> V_67 ;
}
V_285 = V_48 -> V_226 ;
V_86 -> V_209 = V_285 -> V_103 ;
V_219 |= V_257 ;
goto V_297;
}
#ifdef F_196
if ( V_161 . V_228 -> V_270 > 1 && V_86 -> V_209 == 0 )
F_197 ( & V_161 ) ;
else
#endif
if ( ! V_161 . V_288 &&
V_161 . V_294 -> V_304 > 1 &&
V_161 . type == V_168 && ! V_86 -> V_209 )
F_209 ( & V_161 ) ;
if ( ! V_86 -> V_102 )
V_86 -> V_102 = F_139 ( V_48 , V_161 ) ;
V_285 = F_189 ( V_161 ) ;
V_86 -> V_209 = V_285 -> V_103 ;
V_297:
V_62 = F_202 ( & V_161 , V_86 , V_284 , V_285 , V_219 ) ;
V_189:
F_63 () ;
return V_62 ;
}
static struct V_1 * F_210 ( struct V_1 * V_2 , T_1 V_204 )
{
return NULL ;
}
static unsigned int F_211 ( const struct V_1 * V_2 )
{
unsigned int V_198 = F_143 ( V_2 , V_199 ) ;
return V_198 ? : V_2 -> V_4 -> V_198 ;
}
static void F_212 ( struct V_1 * V_2 , struct V_87 * V_88 ,
struct V_65 * V_66 , T_1 V_198 )
{
}
static void F_213 ( struct V_1 * V_2 , struct V_87 * V_88 ,
struct V_65 * V_66 )
{
}
static T_1 * F_214 ( struct V_1 * V_2 ,
unsigned long V_6 )
{
return NULL ;
}
struct V_1 * F_215 ( struct V_48 * V_48 , struct V_1 * V_305 )
{
struct V_61 * V_306 = (struct V_61 * ) V_305 ;
struct V_61 * V_69 ;
V_69 = F_169 ( & V_307 , NULL , 1 , V_308 , 0 ) ;
if ( V_69 ) {
struct V_1 * V_202 = & V_69 -> V_2 ;
V_202 -> V_309 = 1 ;
V_202 -> V_255 = V_310 ;
V_202 -> V_249 = V_310 ;
V_202 -> V_4 = V_306 -> V_2 . V_4 ;
if ( V_202 -> V_4 )
F_162 ( V_202 -> V_4 ) ;
V_69 -> V_253 = V_306 -> V_253 ;
V_69 -> V_254 = V_306 -> V_254 ;
V_69 -> V_126 = V_306 -> V_126 ;
V_69 -> V_63 = F_35 ( V_48 ) ;
V_69 -> V_131 = V_306 -> V_131 ;
V_69 -> V_251 = V_306 -> V_251 ;
V_69 -> V_71 = V_306 -> V_71 ;
V_69 -> V_133 = V_306 -> V_133 ;
F_177 ( & V_69 -> V_224 ) ;
F_216 ( V_202 ) ;
}
F_127 ( V_305 ) ;
return V_69 ? & V_69 -> V_2 : F_203 ( - V_43 ) ;
}
struct V_61 * F_125 ( struct V_48 * V_48 , struct V_85 * V_311 ,
struct V_87 * V_88 )
{
struct V_61 * V_69 = F_116 ( V_48 , V_311 ) ;
if ( F_117 ( V_69 ) )
return V_69 ;
if ( V_311 -> V_287 )
V_69 = (struct V_61 * ) F_217 ( V_48 , & V_69 -> V_2 ,
F_218 ( V_311 ) ,
V_88 , 0 ) ;
return V_69 ;
}
static int F_219 ( struct V_48 * V_48 , T_6 V_2 , T_6 V_39 ,
struct V_85 * V_86 , struct V_65 * V_66 , T_1 V_312 ,
T_1 V_8 , int V_313 , int V_314 , unsigned int V_219 )
{
struct V_61 * V_69 = F_101 ( V_66 ) ;
struct V_315 * V_316 ;
struct V_317 * V_318 ;
unsigned long V_128 = 0 ;
T_1 error ;
T_1 V_319 [ V_320 ] ;
V_318 = F_220 ( V_66 , V_312 , V_8 , V_313 , sizeof( * V_316 ) , V_219 ) ;
if ( V_318 == NULL )
return - V_321 ;
V_316 = F_221 ( V_318 ) ;
V_316 -> V_322 = V_323 ;
V_316 -> V_324 = 32 ;
V_316 -> V_325 = 0 ;
V_316 -> V_326 = V_86 -> V_208 ;
V_316 -> V_327 = V_328 ;
if ( F_222 ( V_66 , V_329 , V_328 ) )
goto V_330;
V_316 -> V_331 = V_69 -> V_251 ;
V_316 -> V_332 = V_101 ;
V_316 -> V_333 = V_334 ;
V_316 -> V_335 = ( V_69 -> V_131 & ~ 0xFFFF ) | V_336 ;
if ( V_69 -> V_131 & V_337 )
V_316 -> V_335 |= V_338 ;
if ( F_223 ( V_66 , V_339 , V_2 ) )
goto V_330;
if ( V_39 ) {
V_316 -> V_325 = 32 ;
if ( F_223 ( V_66 , V_340 , V_39 ) )
goto V_330;
}
if ( V_69 -> V_2 . V_4 &&
F_222 ( V_66 , V_341 , V_69 -> V_2 . V_4 -> V_103 ) )
goto V_330;
#ifdef F_29
if ( V_69 -> V_2 . V_213 &&
F_222 ( V_66 , V_342 , V_69 -> V_2 . V_213 ) )
goto V_330;
#endif
if ( ! F_151 ( V_69 ) &&
V_86 -> V_102 != V_39 ) {
if ( F_223 ( V_66 , V_343 , V_86 -> V_102 ) )
goto V_330;
}
if ( V_69 -> V_133 &&
F_223 ( V_66 , V_344 , V_69 -> V_71 ) )
goto V_330;
V_128 = V_69 -> V_2 . V_128 ;
if ( V_128 ) {
unsigned long V_183 = V_152 ;
if ( F_70 ( V_183 , V_128 ) )
V_128 -= V_183 ;
else
V_128 = 0 ;
}
memcpy ( V_319 , F_224 ( & V_69 -> V_2 ) , sizeof( V_319 ) ) ;
if ( V_69 -> V_126 && V_128 )
V_319 [ V_199 - 1 ] = V_69 -> V_126 ;
if ( F_225 ( V_66 , V_319 ) < 0 )
goto V_330;
if ( V_86 -> V_211 &&
F_222 ( V_66 , V_345 , V_86 -> V_211 ) )
goto V_330;
error = V_69 -> V_2 . error ;
if ( F_151 ( V_69 ) ) {
#ifdef F_178
if ( F_81 ( V_2 ) && ! F_174 ( V_2 ) &&
F_226 ( V_48 , V_346 ) ) {
int V_243 = F_227 ( V_48 , V_66 ,
V_86 -> V_102 , V_86 -> V_67 ,
V_316 , V_314 ) ;
if ( V_243 <= 0 ) {
if ( ! V_314 ) {
if ( V_243 == 0 )
return 0 ;
goto V_330;
} else {
if ( V_243 == - V_321 )
goto V_330;
error = V_243 ;
}
}
} else
#endif
if ( F_222 ( V_66 , V_347 , V_69 -> V_254 ) )
goto V_330;
}
if ( F_228 ( V_66 , & V_69 -> V_2 , 0 , V_128 , error ) < 0 )
goto V_330;
return F_229 ( V_66 , V_318 ) ;
V_330:
F_230 ( V_66 , V_318 ) ;
return - V_321 ;
}
static int F_231 ( struct V_65 * V_348 , struct V_317 * V_318 )
{
struct V_48 * V_48 = F_119 ( V_348 -> V_88 ) ;
struct V_315 * V_349 ;
struct V_350 * V_351 [ V_352 + 1 ] ;
struct V_61 * V_69 = NULL ;
struct V_85 V_86 ;
T_6 V_2 = 0 ;
T_6 V_39 = 0 ;
T_1 V_353 ;
int V_243 ;
int V_92 ;
struct V_65 * V_66 ;
V_243 = F_232 ( V_318 , sizeof( * V_349 ) , V_351 , V_352 , V_354 ) ;
if ( V_243 < 0 )
goto V_355;
V_349 = F_221 ( V_318 ) ;
V_66 = F_233 ( V_356 , V_42 ) ;
if ( V_66 == NULL ) {
V_243 = - V_259 ;
goto V_355;
}
F_234 ( V_66 ) ;
F_235 ( V_66 ) ;
F_40 ( V_66 ) -> V_104 = V_357 ;
F_236 ( V_66 , V_358 + sizeof( struct V_74 ) ) ;
V_39 = V_351 [ V_340 ] ? F_237 ( V_351 [ V_340 ] ) : 0 ;
V_2 = V_351 [ V_339 ] ? F_237 ( V_351 [ V_339 ] ) : 0 ;
V_353 = V_351 [ V_347 ] ? F_238 ( V_351 [ V_347 ] ) : 0 ;
V_92 = V_351 [ V_345 ] ? F_238 ( V_351 [ V_345 ] ) : 0 ;
memset ( & V_86 , 0 , sizeof( V_86 ) ) ;
V_86 . V_67 = V_2 ;
V_86 . V_102 = V_39 ;
V_86 . V_208 = V_349 -> V_326 ;
V_86 . V_209 = V_351 [ V_341 ] ? F_238 ( V_351 [ V_341 ] ) : 0 ;
V_86 . V_211 = V_92 ;
if ( V_353 ) {
struct V_3 * V_4 ;
V_4 = F_239 ( V_48 , V_353 ) ;
if ( V_4 == NULL ) {
V_243 = - V_299 ;
goto V_359;
}
V_66 -> V_104 = F_47 ( V_244 ) ;
V_66 -> V_4 = V_4 ;
V_66 -> V_92 = V_92 ;
F_240 () ;
V_243 = F_241 ( V_66 , V_2 , V_39 , V_349 -> V_326 , V_4 ) ;
F_242 () ;
V_69 = F_101 ( V_66 ) ;
if ( V_243 == 0 && V_69 -> V_2 . error )
V_243 = - V_69 -> V_2 . error ;
} else {
V_69 = F_243 ( V_48 , & V_86 ) ;
V_243 = 0 ;
if ( F_117 ( V_69 ) )
V_243 = F_244 ( V_69 ) ;
}
if ( V_243 )
goto V_359;
F_181 ( V_66 , & V_69 -> V_2 ) ;
if ( V_349 -> V_335 & V_338 )
V_69 -> V_131 |= V_337 ;
V_243 = F_219 ( V_48 , V_2 , V_39 , & V_86 , V_66 ,
F_245 ( V_348 ) . V_312 , V_318 -> V_360 ,
V_361 , 0 , 0 ) ;
if ( V_243 <= 0 )
goto V_359;
V_243 = F_246 ( V_66 , V_48 , F_245 ( V_348 ) . V_312 ) ;
V_355:
return V_243 ;
V_359:
F_111 ( V_66 ) ;
goto V_355;
}
int F_247 ( struct V_65 * V_66 , struct V_362 * V_363 )
{
return V_66 -> V_364 ;
}
void F_248 ( struct V_158 * V_159 )
{
F_37 ( F_36 ( V_159 -> V_4 ) ) ;
}
static int F_249 ( struct V_365 * V_366 , int V_367 ,
void T_11 * V_368 ,
T_12 * V_369 , T_2 * V_370 )
{
struct V_48 * V_48 = (struct V_48 * ) V_366 -> V_371 ;
if ( V_367 ) {
F_37 ( V_48 ) ;
F_250 ( V_48 ) ;
return 0 ;
}
return - V_190 ;
}
static T_3 int F_251 ( struct V_48 * V_48 )
{
struct V_365 * V_372 ;
V_372 = V_373 ;
if ( ! F_252 ( V_48 , & V_374 ) ) {
V_372 = F_253 ( V_372 , sizeof( V_373 ) , V_42 ) ;
if ( V_372 == NULL )
goto V_375;
if ( V_48 -> V_376 != & V_377 )
V_372 [ 0 ] . V_378 = NULL ;
}
V_372 [ 0 ] . V_371 = V_48 ;
V_48 -> V_83 . V_379 = F_254 ( V_48 , L_19 , V_372 ) ;
if ( V_48 -> V_83 . V_379 == NULL )
goto V_380;
return 0 ;
V_380:
if ( V_372 != V_373 )
F_24 ( V_372 ) ;
V_375:
return - V_43 ;
}
static T_4 void F_255 ( struct V_48 * V_48 )
{
struct V_365 * V_372 ;
V_372 = V_48 -> V_83 . V_379 -> V_381 ;
F_256 ( V_48 -> V_83 . V_379 ) ;
F_257 ( V_372 == V_373 ) ;
F_24 ( V_372 ) ;
}
static T_3 int F_258 ( struct V_48 * V_48 )
{
F_259 ( & V_48 -> V_83 . V_63 , 0 ) ;
F_259 ( & V_48 -> V_145 , 0 ) ;
F_260 ( & V_48 -> V_83 . V_382 ,
sizeof( V_48 -> V_83 . V_382 ) ) ;
return 0 ;
}
static int T_3 F_261 ( struct V_48 * V_48 )
{
struct V_383 * V_384 = F_262 ( sizeof( * V_384 ) , V_42 ) ;
if ( ! V_384 )
return - V_43 ;
F_263 ( V_384 ) ;
V_48 -> V_83 . V_84 = V_384 ;
return 0 ;
}
static void T_4 F_264 ( struct V_48 * V_48 )
{
struct V_383 * V_384 = V_48 -> V_83 . V_84 ;
V_48 -> V_83 . V_84 = NULL ;
F_265 ( V_384 ) ;
F_24 ( V_384 ) ;
}
int T_5 F_266 ( void )
{
int V_385 = 0 ;
#ifdef F_29
V_38 = F_267 ( 256 * sizeof( struct V_38 ) , F_268 ( struct V_38 ) ) ;
if ( ! V_38 )
F_269 ( L_20 ) ;
#endif
V_19 . V_386 =
F_270 ( L_21 , sizeof( struct V_61 ) , 0 ,
V_387 | V_388 , NULL ) ;
V_307 . V_386 = V_19 . V_386 ;
if ( F_271 ( & V_19 ) < 0 )
F_269 ( L_22 ) ;
if ( F_271 ( & V_307 ) < 0 )
F_269 ( L_23 ) ;
V_19 . V_389 = ~ 0 ;
V_390 = V_391 ;
F_272 () ;
F_273 () ;
if ( F_32 () )
F_274 ( L_24 ) ;
#ifdef F_275
F_276 () ;
F_277 () ;
#endif
F_278 ( V_392 , V_393 , F_231 , NULL , NULL ) ;
#ifdef F_279
F_33 ( & V_394 ) ;
#endif
F_33 ( & V_395 ) ;
F_33 ( & V_396 ) ;
return V_385 ;
}
void T_5 F_280 ( void )
{
F_254 ( & V_374 , L_19 , V_397 ) ;
}
