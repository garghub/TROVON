static T_1 * F_1 ( struct V_1 * V_2 , unsigned long V_3 )
{
F_2 ( 1 ) ;
return NULL ;
}
static void * F_3 ( struct V_4 * V_5 , T_2 * V_6 )
{
if ( * V_6 )
return NULL ;
return V_7 ;
}
static void * F_4 ( struct V_4 * V_5 , void * V_8 , T_2 * V_6 )
{
++ * V_6 ;
return NULL ;
}
static void F_5 ( struct V_4 * V_5 , void * V_8 )
{
}
static int F_6 ( struct V_4 * V_5 , void * V_8 )
{
if ( V_8 == V_7 )
F_7 ( V_5 , L_1 ,
L_2
L_3
L_4 ) ;
return 0 ;
}
static int F_8 ( struct V_9 * V_9 , struct V_10 * V_10 )
{
return F_9 ( V_10 , & V_11 ) ;
}
static void * F_10 ( struct V_4 * V_5 , T_2 * V_6 )
{
int V_12 ;
if ( * V_6 == 0 )
return V_7 ;
for ( V_12 = * V_6 - 1 ; V_12 < V_13 ; ++ V_12 ) {
if ( ! F_11 ( V_12 ) )
continue;
* V_6 = V_12 + 1 ;
return & F_12 ( V_14 , V_12 ) ;
}
return NULL ;
}
static void * F_13 ( struct V_4 * V_5 , void * V_8 , T_2 * V_6 )
{
int V_12 ;
for ( V_12 = * V_6 ; V_12 < V_13 ; ++ V_12 ) {
if ( ! F_11 ( V_12 ) )
continue;
* V_6 = V_12 + 1 ;
return & F_12 ( V_14 , V_12 ) ;
}
return NULL ;
}
static void F_14 ( struct V_4 * V_5 , void * V_8 )
{
}
static int F_15 ( struct V_4 * V_5 , void * V_8 )
{
struct V_14 * V_15 = V_8 ;
if ( V_8 == V_7 ) {
F_7 ( V_5 , L_5 ) ;
return 0 ;
}
F_7 ( V_5 , L_6
L_7 ,
F_16 ( & V_16 ) ,
0 ,
V_15 -> V_17 ,
V_15 -> V_18 ,
V_15 -> V_19 ,
V_15 -> V_20 ,
V_15 -> V_21 ,
V_15 -> V_22 ,
0 ,
V_15 -> V_23 ,
V_15 -> V_24 ,
0 ,
0 ,
0 ,
0 ,
0 ,
0
) ;
return 0 ;
}
static int F_17 ( struct V_9 * V_9 , struct V_10 * V_10 )
{
return F_9 ( V_10 , & V_25 ) ;
}
static int F_18 ( struct V_4 * V_26 , void * V_8 )
{
struct V_27 * V_2 , * V_28 ;
unsigned int V_29 , V_30 ;
V_2 = F_19 ( 256 , sizeof( struct V_27 ) , V_31 ) ;
if ( ! V_2 )
return - V_32 ;
F_20 (i) {
V_28 = (struct V_27 * ) F_21 ( V_27 , V_29 ) ;
for ( V_30 = 0 ; V_30 < 256 ; V_30 ++ ) {
V_2 [ V_30 ] . V_33 += V_28 [ V_30 ] . V_33 ;
V_2 [ V_30 ] . V_34 += V_28 [ V_30 ] . V_34 ;
V_2 [ V_30 ] . V_35 += V_28 [ V_30 ] . V_35 ;
V_2 [ V_30 ] . V_36 += V_28 [ V_30 ] . V_36 ;
}
}
F_22 ( V_26 , V_2 , 256 * sizeof( struct V_27 ) ) ;
F_23 ( V_2 ) ;
return 0 ;
}
static int F_24 ( struct V_9 * V_9 , struct V_10 * V_10 )
{
return F_25 ( V_10 , F_18 , NULL ) ;
}
static int T_3 F_26 ( struct V_37 * V_37 )
{
struct V_38 * V_39 ;
V_39 = F_27 ( L_8 , V_40 , V_37 -> V_41 ,
& V_42 ) ;
if ( ! V_39 )
goto V_43;
V_39 = F_27 ( L_8 , V_40 ,
V_37 -> V_44 , & V_45 ) ;
if ( ! V_39 )
goto V_46;
#ifdef F_28
V_39 = F_27 ( L_9 , 0 , V_37 -> V_41 , & V_47 ) ;
if ( ! V_39 )
goto V_48;
#endif
return 0 ;
#ifdef F_28
V_48:
F_29 ( L_8 , V_37 -> V_44 ) ;
#endif
V_46:
F_29 ( L_8 , V_37 -> V_41 ) ;
V_43:
return - V_32 ;
}
static void T_4 F_30 ( struct V_37 * V_37 )
{
F_29 ( L_8 , V_37 -> V_44 ) ;
F_29 ( L_8 , V_37 -> V_41 ) ;
#ifdef F_28
F_29 ( L_9 , V_37 -> V_41 ) ;
#endif
}
static int T_5 F_31 ( void )
{
return F_32 ( & V_49 ) ;
}
static inline int F_31 ( void )
{
return 0 ;
}
static inline bool F_33 ( const struct V_50 * V_51 )
{
return V_51 -> V_52 != F_34 ( F_35 ( V_51 -> V_2 . V_53 ) ) ;
}
void F_36 ( struct V_37 * V_37 )
{
F_37 ( V_37 ) ;
}
static struct V_54 * F_38 ( const struct V_1 * V_2 ,
struct V_55 * V_56 ,
const void * V_57 )
{
struct V_58 * V_53 = V_2 -> V_53 ;
const T_6 * V_59 = V_57 ;
const struct V_50 * V_60 ;
struct V_54 * V_61 ;
V_60 = ( const struct V_50 * ) V_2 ;
if ( V_60 -> V_62 )
V_59 = ( const T_6 * ) & V_60 -> V_62 ;
else if ( V_56 )
V_59 = & F_39 ( V_56 ) -> V_57 ;
V_61 = F_40 ( V_53 , * ( V_63 T_1 * ) V_59 ) ;
if ( V_61 )
return V_61 ;
return F_41 ( & V_64 , V_59 , V_53 ) ;
}
T_1 F_42 ( T_1 V_65 , int V_66 )
{
T_1 * V_67 = V_68 + V_65 % V_69 ;
T_7 * V_70 = V_71 + V_65 % V_69 ;
T_1 V_3 = F_43 ( * V_67 ) ;
T_1 V_72 = ( T_1 ) V_73 ;
T_1 V_74 = 0 ;
if ( V_3 != V_72 && F_44 ( V_67 , V_3 , V_72 ) == V_3 )
V_74 = F_45 ( V_72 - V_3 ) ;
return F_46 ( V_66 + V_74 , V_70 ) - V_66 ;
}
void F_47 ( struct V_37 * V_37 , struct V_75 * V_76 , int V_66 )
{
static T_1 T_8 V_77 ;
T_1 V_65 , V_78 ;
F_48 ( & T_8 , sizeof( T_8 ) ) ;
V_65 = F_49 ( ( V_63 T_1 ) V_76 -> V_57 ,
( V_63 T_1 ) V_76 -> V_79 ,
V_76 -> V_80 ^ F_50 ( V_37 ) ,
T_8 ) ;
V_78 = F_42 ( V_65 , V_66 ) ;
V_76 -> V_78 = F_51 ( V_78 ) ;
}
static void F_52 ( struct V_81 * V_82 , const struct V_83 * V_84 ,
const struct V_75 * V_76 ,
int V_85 , T_9 V_86 ,
T_9 V_87 , T_1 V_88 , int V_89 )
{
if ( V_84 ) {
const struct V_90 * V_91 = F_53 ( V_84 ) ;
V_85 = V_84 -> V_92 ;
V_88 = V_84 -> V_93 ;
V_86 = F_54 ( V_84 ) ;
V_87 = V_91 -> V_94 ? V_95 : V_84 -> V_96 ;
}
F_55 ( V_82 , V_85 , V_88 , V_86 ,
V_97 , V_87 ,
V_89 ,
V_76 -> V_57 , V_76 -> V_79 , 0 , 0 ) ;
}
static void F_56 ( struct V_81 * V_82 , const struct V_55 * V_56 ,
const struct V_83 * V_84 )
{
const struct V_75 * V_76 = F_39 ( V_56 ) ;
int V_85 = V_56 -> V_53 -> V_98 ;
T_9 V_86 = F_57 ( V_76 -> V_86 ) ;
T_9 V_87 = V_76 -> V_80 ;
T_1 V_88 = V_56 -> V_88 ;
F_52 ( V_82 , V_84 , V_76 , V_85 , V_86 , V_87 , V_88 , 0 ) ;
}
static void F_58 ( struct V_81 * V_82 , const struct V_83 * V_84 )
{
const struct V_90 * V_91 = F_53 ( V_84 ) ;
const struct V_99 * V_100 ;
T_6 V_57 = V_91 -> V_101 ;
F_59 () ;
V_100 = F_60 ( V_91 -> V_100 ) ;
if ( V_100 && V_100 -> V_102 . V_103 )
V_57 = V_100 -> V_102 . V_104 ;
F_55 ( V_82 , V_84 -> V_92 , V_84 -> V_93 ,
F_54 ( V_84 ) , V_97 ,
V_91 -> V_94 ? V_95 : V_84 -> V_96 ,
F_61 ( V_84 ) ,
V_57 , V_91 -> V_105 , 0 , 0 ) ;
F_62 () ;
}
static void F_63 ( struct V_81 * V_82 , const struct V_83 * V_84 ,
const struct V_55 * V_56 )
{
if ( V_56 )
F_56 ( V_82 , V_56 , V_84 ) ;
else
F_58 ( V_82 , V_84 ) ;
}
static inline void F_64 ( struct V_50 * V_60 )
{
F_65 ( & V_60 -> V_2 . V_106 , V_107 ) ;
}
static void F_66 ( struct V_108 * V_109 )
{
struct V_50 * V_60 ;
V_60 = F_60 ( V_109 -> V_110 ) ;
if ( V_60 ) {
F_67 ( V_109 -> V_110 , NULL ) ;
F_64 ( V_60 ) ;
}
V_60 = F_60 ( V_109 -> V_111 ) ;
if ( V_60 ) {
F_67 ( V_109 -> V_111 , NULL ) ;
F_64 ( V_60 ) ;
}
}
static struct V_108 * F_68 ( struct V_112 * V_65 )
{
struct V_108 * V_109 , * V_113 ;
V_113 = F_60 ( V_65 -> V_114 ) ;
for ( V_109 = F_60 ( V_113 -> V_115 ) ; V_109 ;
V_109 = F_60 ( V_109 -> V_115 ) ) {
if ( F_69 ( V_109 -> V_116 , V_113 -> V_116 ) )
V_113 = V_109 ;
}
F_66 ( V_113 ) ;
return V_113 ;
}
static inline T_1 F_70 ( T_6 V_57 )
{
static T_1 T_10 V_77 ;
T_1 V_117 ;
F_48 ( & T_10 , sizeof( T_10 ) ) ;
V_117 = F_71 ( ( V_63 T_1 ) V_57 , T_10 ) ;
return F_72 ( V_117 , V_118 ) ;
}
static void F_73 ( struct V_50 * V_60 , struct V_108 * V_109 )
{
V_60 -> V_119 = V_109 -> V_120 ;
V_60 -> V_2 . V_121 = V_109 -> V_122 ;
if ( V_109 -> V_123 ) {
V_60 -> V_124 |= V_125 ;
V_60 -> V_62 = V_109 -> V_123 ;
V_60 -> V_126 = 1 ;
}
}
static void F_74 ( struct V_127 * V_128 , T_6 V_57 , T_6 V_129 ,
T_1 V_130 , unsigned long V_121 )
{
struct V_112 * V_65 ;
struct V_108 * V_109 ;
struct V_50 * V_60 ;
unsigned int V_29 ;
int V_131 ;
T_1 V_117 = F_70 ( V_57 ) ;
F_75 ( & V_132 ) ;
V_65 = F_60 ( V_128 -> V_133 ) ;
if ( ! V_65 ) {
V_65 = F_76 ( V_134 * sizeof( * V_65 ) , V_135 ) ;
if ( ! V_65 )
goto V_136;
F_77 ( V_128 -> V_133 , V_65 ) ;
}
V_65 += V_117 ;
V_131 = 0 ;
for ( V_109 = F_60 ( V_65 -> V_114 ) ; V_109 ;
V_109 = F_60 ( V_109 -> V_115 ) ) {
if ( V_109 -> V_137 == V_57 )
break;
V_131 ++ ;
}
if ( V_109 ) {
if ( V_129 )
V_109 -> V_123 = V_129 ;
if ( V_130 ) {
V_109 -> V_120 = V_130 ;
V_109 -> V_122 = F_78 ( 1UL , V_121 ) ;
}
V_60 = F_60 ( V_109 -> V_110 ) ;
if ( V_60 )
F_73 ( V_60 , V_109 ) ;
V_60 = F_60 ( V_109 -> V_111 ) ;
if ( V_60 )
F_73 ( V_60 , V_109 ) ;
} else {
if ( V_131 > V_138 )
V_109 = F_68 ( V_65 ) ;
else {
V_109 = F_76 ( sizeof( * V_109 ) , V_135 ) ;
if ( ! V_109 )
goto V_136;
V_109 -> V_115 = V_65 -> V_114 ;
F_77 ( V_65 -> V_114 , V_109 ) ;
}
V_109 -> V_139 = V_139 ( F_35 ( V_128 -> V_140 ) ) ;
V_109 -> V_137 = V_57 ;
V_109 -> V_123 = V_129 ;
V_109 -> V_120 = V_130 ;
V_109 -> V_122 = V_121 ;
V_60 = F_60 ( V_128 -> V_141 ) ;
if ( V_60 )
V_60 -> V_2 . V_142 = V_143 ;
F_20 (i) {
struct V_50 T_11 * * V_144 ;
V_144 = F_21 ( V_128 -> V_145 , V_29 ) ;
V_60 = F_60 ( * V_144 ) ;
if ( V_60 )
V_60 -> V_2 . V_142 = V_143 ;
}
}
V_109 -> V_116 = V_73 ;
V_136:
F_79 ( & V_132 ) ;
}
static void F_80 ( struct V_50 * V_60 , struct V_55 * V_56 , struct V_81 * V_82 ,
bool V_146 )
{
T_6 V_147 = F_81 ( V_56 ) -> V_148 . V_149 ;
T_6 V_150 = F_39 ( V_56 ) -> V_79 ;
struct V_58 * V_53 = V_56 -> V_53 ;
struct V_151 * V_152 ;
struct V_153 V_154 ;
struct V_54 * V_61 ;
struct V_37 * V_37 ;
switch ( F_81 ( V_56 ) -> V_155 & 7 ) {
case V_156 :
case V_157 :
case V_158 :
case V_159 :
break;
default:
return;
}
if ( V_60 -> V_62 != V_150 )
return;
V_152 = F_82 ( V_53 ) ;
if ( ! V_152 )
return;
V_37 = F_35 ( V_53 ) ;
if ( V_147 == V_150 || ! F_83 ( V_152 ) ||
F_84 ( V_147 ) || F_85 ( V_147 ) ||
F_86 ( V_147 ) )
goto V_160;
if ( ! F_87 ( V_152 ) ) {
if ( ! F_88 ( V_152 , V_147 , V_150 ) )
goto V_160;
if ( F_89 ( V_152 ) && F_90 ( V_147 , V_53 ) )
goto V_160;
} else {
if ( F_91 ( V_37 , V_147 ) != V_161 )
goto V_160;
}
V_61 = F_38 ( & V_60 -> V_2 , NULL , & V_147 ) ;
if ( ! F_92 ( V_61 ) ) {
if ( ! ( V_61 -> V_162 & V_163 ) ) {
F_93 ( V_61 , NULL ) ;
} else {
if ( F_94 ( V_37 , V_82 , & V_154 , 0 ) == 0 ) {
struct V_127 * V_128 = & F_95 ( V_154 ) ;
F_74 ( V_128 , V_82 -> V_57 , V_147 ,
0 , 0 ) ;
}
if ( V_146 )
V_60 -> V_2 . V_142 = V_143 ;
F_96 ( V_164 , V_61 ) ;
}
F_97 ( V_61 ) ;
}
return;
V_160:
#ifdef F_98
if ( F_99 ( V_152 ) ) {
const struct V_75 * V_76 = ( const struct V_75 * ) V_56 -> V_165 ;
T_6 V_57 = V_76 -> V_57 ;
T_6 V_79 = V_76 -> V_79 ;
F_100 ( L_10
L_11 ,
& V_150 , V_53 -> V_166 , & V_147 ,
& V_79 , & V_57 ) ;
}
#endif
;
}
static void F_101 ( struct V_1 * V_2 , struct V_83 * V_84 , struct V_55 * V_56 )
{
struct V_50 * V_60 ;
struct V_81 V_82 ;
const struct V_75 * V_76 = ( const struct V_75 * ) V_56 -> V_165 ;
int V_85 = V_56 -> V_53 -> V_98 ;
T_9 V_86 = F_57 ( V_76 -> V_86 ) ;
T_9 V_87 = V_76 -> V_80 ;
T_1 V_88 = V_56 -> V_88 ;
V_60 = (struct V_50 * ) V_2 ;
F_52 ( & V_82 , V_84 , V_76 , V_85 , V_86 , V_87 , V_88 , 0 ) ;
F_80 ( V_60 , V_56 , & V_82 , true ) ;
}
static struct V_1 * F_102 ( struct V_1 * V_2 )
{
struct V_50 * V_60 = (struct V_50 * ) V_2 ;
struct V_1 * V_167 = V_2 ;
if ( V_60 ) {
if ( V_2 -> V_142 > 0 ) {
F_103 ( V_60 ) ;
V_167 = NULL ;
} else if ( ( V_60 -> V_124 & V_125 ) ||
V_60 -> V_2 . V_121 ) {
F_103 ( V_60 ) ;
V_167 = NULL ;
}
}
return V_167 ;
}
void F_104 ( struct V_55 * V_56 )
{
struct V_50 * V_60 = F_105 ( V_56 ) ;
struct V_151 * V_152 ;
struct V_168 * V_169 ;
struct V_37 * V_37 ;
int V_170 ;
int V_171 ;
F_59 () ;
V_152 = F_82 ( V_60 -> V_2 . V_53 ) ;
if ( ! V_152 || ! F_106 ( V_152 ) ) {
F_62 () ;
return;
}
V_170 = F_99 ( V_152 ) ;
V_171 = F_107 ( V_60 -> V_2 . V_53 ) ;
F_62 () ;
V_37 = F_35 ( V_60 -> V_2 . V_53 ) ;
V_169 = F_108 ( V_37 -> V_172 . V_173 , F_39 ( V_56 ) -> V_79 , V_171 , 1 ) ;
if ( ! V_169 ) {
F_109 ( V_56 , V_174 , V_158 ,
F_110 ( V_60 , F_39 ( V_56 ) -> V_57 ) ) ;
return;
}
if ( F_111 ( V_73 , V_169 -> V_175 + V_176 ) )
V_169 -> V_177 = 0 ;
if ( V_169 -> V_177 >= V_178 ) {
V_169 -> V_175 = V_73 ;
goto V_179;
}
if ( V_169 -> V_177 == 0 ||
F_111 ( V_73 ,
( V_169 -> V_175 +
( V_180 << V_169 -> V_177 ) ) ) ) {
T_6 V_129 = F_110 ( V_60 , F_39 ( V_56 ) -> V_57 ) ;
F_109 ( V_56 , V_174 , V_158 , V_129 ) ;
V_169 -> V_175 = V_73 ;
++ V_169 -> V_177 ;
#ifdef F_98
if ( V_170 &&
V_169 -> V_177 == V_178 )
F_112 ( L_12 ,
& F_39 ( V_56 ) -> V_79 , F_113 ( V_56 ) ,
& F_39 ( V_56 ) -> V_57 , & V_129 ) ;
#endif
}
V_179:
F_114 ( V_169 ) ;
}
static int F_115 ( struct V_55 * V_56 )
{
struct V_151 * V_152 = F_82 ( V_56 -> V_53 ) ;
struct V_50 * V_60 = F_105 ( V_56 ) ;
struct V_168 * V_169 ;
unsigned long V_72 ;
struct V_37 * V_37 ;
bool V_181 ;
int V_155 ;
if ( ! V_152 )
goto V_182;
V_37 = F_35 ( V_60 -> V_2 . V_53 ) ;
if ( ! F_116 ( V_152 ) ) {
switch ( V_60 -> V_2 . error ) {
case V_183 :
F_117 ( V_37 , V_184 ) ;
break;
case V_185 :
F_117 ( V_37 , V_186 ) ;
break;
}
goto V_182;
}
switch ( V_60 -> V_2 . error ) {
case V_187 :
default:
goto V_182;
case V_183 :
V_155 = V_188 ;
break;
case V_185 :
V_155 = V_189 ;
F_117 ( V_37 , V_186 ) ;
break;
case V_190 :
V_155 = V_191 ;
break;
}
V_169 = F_108 ( V_37 -> V_172 . V_173 , F_39 ( V_56 ) -> V_79 ,
F_118 ( V_56 -> V_53 ) , 1 ) ;
V_181 = true ;
if ( V_169 ) {
V_72 = V_73 ;
V_169 -> V_177 += V_72 - V_169 -> V_175 ;
if ( V_169 -> V_177 > V_192 )
V_169 -> V_177 = V_192 ;
V_169 -> V_175 = V_72 ;
if ( V_169 -> V_177 >= V_193 )
V_169 -> V_177 -= V_193 ;
else
V_181 = false ;
F_114 ( V_169 ) ;
}
if ( V_181 )
F_109 ( V_56 , V_194 , V_155 , 0 ) ;
V_182: F_119 ( V_56 ) ;
return 0 ;
}
static void F_120 ( struct V_50 * V_60 , struct V_81 * V_82 , T_1 V_195 )
{
struct V_1 * V_2 = & V_60 -> V_2 ;
struct V_153 V_154 ;
if ( F_121 ( V_2 , V_196 ) )
return;
if ( F_122 ( V_2 ) < V_195 )
return;
if ( V_195 < V_197 )
V_195 = V_197 ;
if ( V_60 -> V_119 == V_195 &&
F_69 ( V_73 , V_2 -> V_121 - V_198 / 2 ) )
return;
F_59 () ;
if ( F_94 ( F_35 ( V_2 -> V_53 ) , V_82 , & V_154 , 0 ) == 0 ) {
struct V_127 * V_128 = & F_95 ( V_154 ) ;
F_74 ( V_128 , V_82 -> V_57 , 0 , V_195 ,
V_73 + V_198 ) ;
}
F_62 () ;
}
static void F_123 ( struct V_1 * V_2 , struct V_83 * V_84 ,
struct V_55 * V_56 , T_1 V_195 )
{
struct V_50 * V_60 = (struct V_50 * ) V_2 ;
struct V_81 V_82 ;
F_63 ( & V_82 , V_84 , V_56 ) ;
F_120 ( V_60 , & V_82 , V_195 ) ;
}
void F_124 ( struct V_55 * V_56 , struct V_37 * V_37 , T_1 V_195 ,
int V_85 , T_1 V_88 , T_9 V_80 , int V_89 )
{
const struct V_75 * V_76 = ( const struct V_75 * ) V_56 -> V_165 ;
struct V_81 V_82 ;
struct V_50 * V_60 ;
if ( ! V_88 )
V_88 = F_125 ( V_37 , V_56 -> V_88 ) ;
F_52 ( & V_82 , NULL , V_76 , V_85 ,
F_57 ( V_76 -> V_86 ) , V_80 , V_88 , V_89 ) ;
V_60 = F_126 ( V_37 , & V_82 ) ;
if ( ! F_92 ( V_60 ) ) {
F_120 ( V_60 , & V_82 , V_195 ) ;
F_103 ( V_60 ) ;
}
}
static void F_127 ( struct V_55 * V_56 , struct V_83 * V_84 , T_1 V_195 )
{
const struct V_75 * V_76 = ( const struct V_75 * ) V_56 -> V_165 ;
struct V_81 V_82 ;
struct V_50 * V_60 ;
F_52 ( & V_82 , V_84 , V_76 , 0 , 0 , 0 , 0 , 0 ) ;
if ( ! V_82 . V_199 )
V_82 . V_199 = F_125 ( F_128 ( V_84 ) , V_56 -> V_88 ) ;
V_60 = F_126 ( F_128 ( V_84 ) , & V_82 ) ;
if ( ! F_92 ( V_60 ) ) {
F_120 ( V_60 , & V_82 , V_195 ) ;
F_103 ( V_60 ) ;
}
}
void F_129 ( struct V_55 * V_56 , struct V_83 * V_84 , T_1 V_195 )
{
const struct V_75 * V_76 = ( const struct V_75 * ) V_56 -> V_165 ;
struct V_81 V_82 ;
struct V_50 * V_60 ;
struct V_1 * V_200 = NULL ;
bool V_201 = false ;
F_130 ( V_84 ) ;
if ( ! F_131 ( V_84 ) )
goto V_182;
V_200 = F_132 ( V_84 ) ;
if ( F_133 ( V_84 ) || ! V_200 ) {
F_127 ( V_56 , V_84 , V_195 ) ;
goto V_182;
}
F_52 ( & V_82 , V_84 , V_76 , 0 , 0 , 0 , 0 , 0 ) ;
V_60 = (struct V_50 * ) V_200 ;
if ( V_200 -> V_142 && ! V_200 -> V_202 -> V_203 ( V_200 , 0 ) ) {
V_60 = F_134 ( F_128 ( V_84 ) , & V_82 , V_84 ) ;
if ( F_92 ( V_60 ) )
goto V_182;
V_201 = true ;
}
F_120 ( (struct V_50 * ) V_60 -> V_2 . V_204 , & V_82 , V_195 ) ;
if ( ! F_135 ( & V_60 -> V_2 , 0 ) ) {
if ( V_201 )
F_136 ( & V_60 -> V_2 ) ;
V_60 = F_134 ( F_128 ( V_84 ) , & V_82 , V_84 ) ;
if ( F_92 ( V_60 ) )
goto V_182;
V_201 = true ;
}
if ( V_201 )
F_137 ( V_84 , & V_60 -> V_2 ) ;
V_182:
F_138 ( V_84 ) ;
F_136 ( V_200 ) ;
}
void F_139 ( struct V_55 * V_56 , struct V_37 * V_37 ,
int V_85 , T_1 V_88 , T_9 V_80 , int V_89 )
{
const struct V_75 * V_76 = ( const struct V_75 * ) V_56 -> V_165 ;
struct V_81 V_82 ;
struct V_50 * V_60 ;
F_52 ( & V_82 , NULL , V_76 , V_85 ,
F_57 ( V_76 -> V_86 ) , V_80 , V_88 , V_89 ) ;
V_60 = F_126 ( V_37 , & V_82 ) ;
if ( ! F_92 ( V_60 ) ) {
F_80 ( V_60 , V_56 , & V_82 , false ) ;
F_103 ( V_60 ) ;
}
}
void F_140 ( struct V_55 * V_56 , struct V_83 * V_84 )
{
const struct V_75 * V_76 = ( const struct V_75 * ) V_56 -> V_165 ;
struct V_81 V_82 ;
struct V_50 * V_60 ;
F_52 ( & V_82 , V_84 , V_76 , 0 , 0 , 0 , 0 , 0 ) ;
V_60 = F_126 ( F_128 ( V_84 ) , & V_82 ) ;
if ( ! F_92 ( V_60 ) ) {
F_80 ( V_60 , V_56 , & V_82 , false ) ;
F_103 ( V_60 ) ;
}
}
static struct V_1 * F_141 ( struct V_1 * V_2 , T_1 V_205 )
{
struct V_50 * V_60 = (struct V_50 * ) V_2 ;
if ( V_2 -> V_142 != V_206 || F_33 ( V_60 ) )
return NULL ;
return V_2 ;
}
static void F_142 ( struct V_55 * V_56 )
{
struct V_50 * V_60 ;
F_109 ( V_56 , V_194 , V_188 , 0 ) ;
V_60 = F_105 ( V_56 ) ;
if ( V_60 )
F_143 ( & V_60 -> V_2 , 0 ) ;
}
static int F_144 ( struct V_37 * V_37 , struct V_83 * V_84 , struct V_55 * V_56 )
{
F_145 ( L_13 ,
V_207 , & F_39 ( V_56 ) -> V_79 , & F_39 ( V_56 ) -> V_57 ,
V_56 -> V_53 ? V_56 -> V_53 -> V_166 : L_14 ) ;
F_119 ( V_56 ) ;
F_2 ( 1 ) ;
return 0 ;
}
void F_146 ( T_9 * V_208 , struct V_55 * V_56 , struct V_50 * V_60 )
{
T_6 V_28 ;
if ( F_147 ( V_60 ) )
V_28 = F_39 ( V_56 ) -> V_79 ;
else {
struct V_153 V_154 ;
struct V_81 V_82 ;
struct V_75 * V_76 ;
V_76 = F_39 ( V_56 ) ;
memset ( & V_82 , 0 , sizeof( V_82 ) ) ;
V_82 . V_57 = V_76 -> V_57 ;
V_82 . V_79 = V_76 -> V_79 ;
V_82 . V_209 = F_57 ( V_76 -> V_86 ) ;
V_82 . V_210 = V_60 -> V_2 . V_53 -> V_98 ;
V_82 . V_211 = V_56 -> V_53 -> V_98 ;
V_82 . V_199 = V_56 -> V_88 ;
F_59 () ;
if ( F_94 ( F_35 ( V_60 -> V_2 . V_53 ) , & V_82 , & V_154 , 0 ) == 0 )
V_28 = F_148 ( F_35 ( V_60 -> V_2 . V_53 ) , V_154 ) ;
else
V_28 = F_149 ( V_60 -> V_2 . V_53 ,
F_110 ( V_60 , V_76 -> V_57 ) ,
V_97 ) ;
F_62 () ;
}
memcpy ( V_208 , & V_28 , 4 ) ;
}
static void F_150 ( struct V_50 * V_60 , T_1 V_212 )
{
if ( ! ( V_60 -> V_2 . V_213 & 0xFFFF ) )
V_60 -> V_2 . V_213 |= V_212 & 0xFFFF ;
if ( ! ( V_60 -> V_2 . V_213 & 0xFFFF0000 ) )
V_60 -> V_2 . V_213 |= V_212 & 0xFFFF0000 ;
}
static unsigned int F_151 ( const struct V_1 * V_2 )
{
unsigned int V_214 = F_152 ( V_2 , V_215 ) ;
if ( V_214 == 0 ) {
V_214 = F_153 (unsigned int, dst->dev->mtu - 40 ,
ip_rt_min_advmss) ;
if ( V_214 > 65535 - 40 )
V_214 = 65535 - 40 ;
}
return V_214 ;
}
static unsigned int F_122 ( const struct V_1 * V_2 )
{
const struct V_50 * V_60 = ( const struct V_50 * ) V_2 ;
unsigned int V_195 = V_60 -> V_119 ;
if ( ! V_195 || F_154 ( V_73 , V_60 -> V_2 . V_121 ) )
V_195 = F_152 ( V_2 , V_196 ) ;
if ( V_195 )
return V_195 ;
V_195 = V_2 -> V_53 -> V_195 ;
if ( F_155 ( F_121 ( V_2 , V_196 ) ) ) {
if ( V_60 -> V_126 && V_195 > 576 )
V_195 = 576 ;
}
return F_156 (unsigned int, mtu, IP_MAX_MTU) ;
}
static struct V_108 * F_157 ( struct V_127 * V_128 , T_6 V_57 )
{
struct V_112 * V_65 = F_60 ( V_128 -> V_133 ) ;
struct V_108 * V_109 ;
T_1 V_117 ;
if ( ! V_65 )
return NULL ;
V_117 = F_70 ( V_57 ) ;
for ( V_109 = F_60 ( V_65 [ V_117 ] . V_114 ) ; V_109 ;
V_109 = F_60 ( V_109 -> V_115 ) ) {
if ( V_109 -> V_137 == V_57 )
return V_109 ;
}
return NULL ;
}
static bool F_158 ( struct V_50 * V_60 , struct V_108 * V_109 ,
T_6 V_57 )
{
bool V_167 = false ;
F_75 ( & V_132 ) ;
if ( V_57 == V_109 -> V_137 ) {
struct V_50 T_11 * * V_216 ;
struct V_50 * V_217 ;
int V_218 = V_139 ( F_35 ( V_60 -> V_2 . V_53 ) ) ;
if ( F_159 ( V_60 ) )
V_216 = & V_109 -> V_110 ;
else
V_216 = & V_109 -> V_111 ;
V_217 = F_60 ( * V_216 ) ;
if ( V_109 -> V_139 != V_218 ) {
V_109 -> V_139 = V_218 ;
V_109 -> V_123 = 0 ;
V_109 -> V_120 = 0 ;
V_109 -> V_122 = 0 ;
F_66 ( V_109 ) ;
V_217 = NULL ;
}
F_73 ( V_60 , V_109 ) ;
if ( ! V_60 -> V_62 )
V_60 -> V_62 = V_57 ;
if ( ! ( V_60 -> V_2 . V_219 & V_220 ) ) {
F_77 ( * V_216 , V_60 ) ;
if ( V_217 )
F_64 ( V_217 ) ;
V_167 = true ;
}
V_109 -> V_116 = V_73 ;
}
F_79 ( & V_132 ) ;
return V_167 ;
}
static bool F_160 ( struct V_127 * V_128 , struct V_50 * V_60 )
{
struct V_50 * V_217 , * V_221 , * * V_222 ;
bool V_167 = true ;
if ( F_159 ( V_60 ) ) {
V_222 = (struct V_50 * * ) & V_128 -> V_141 ;
} else {
V_222 = (struct V_50 * * ) F_161 ( V_128 -> V_145 ) ;
}
V_217 = * V_222 ;
V_221 = F_44 ( V_222 , V_217 , V_60 ) ;
if ( V_221 == V_217 ) {
if ( V_217 )
F_64 ( V_217 ) ;
} else
V_167 = false ;
return V_167 ;
}
static void F_162 ( struct V_50 * V_60 )
{
struct V_223 * V_224 = F_161 ( & V_225 ) ;
V_60 -> V_225 = V_224 ;
F_75 ( & V_224 -> V_226 ) ;
F_163 ( & V_60 -> V_227 , & V_224 -> V_228 ) ;
F_79 ( & V_224 -> V_226 ) ;
}
static void F_164 ( struct V_1 * V_2 )
{
struct V_50 * V_60 = (struct V_50 * ) V_2 ;
if ( ! F_165 ( & V_60 -> V_227 ) ) {
struct V_223 * V_224 = V_60 -> V_225 ;
F_75 ( & V_224 -> V_226 ) ;
F_166 ( & V_60 -> V_227 ) ;
F_79 ( & V_224 -> V_226 ) ;
}
}
void F_167 ( struct V_58 * V_53 )
{
struct V_37 * V_37 = F_35 ( V_53 ) ;
struct V_50 * V_60 ;
int V_12 ;
F_20 (cpu) {
struct V_223 * V_224 = & F_12 ( V_225 , V_12 ) ;
F_75 ( & V_224 -> V_226 ) ;
F_168 (rt, &ul->head, rt_uncached) {
if ( V_60 -> V_2 . V_53 != V_53 )
continue;
V_60 -> V_2 . V_53 = V_37 -> V_229 ;
F_169 ( V_60 -> V_2 . V_53 ) ;
F_170 ( V_53 ) ;
}
F_79 ( & V_224 -> V_226 ) ;
}
}
static bool F_171 ( const struct V_50 * V_60 )
{
return V_60 &&
V_60 -> V_2 . V_142 == V_206 &&
! F_33 ( V_60 ) ;
}
static void F_172 ( struct V_50 * V_60 , T_6 V_57 ,
const struct V_153 * V_154 ,
struct V_108 * V_109 ,
struct V_230 * V_231 , T_12 type , T_1 V_232 )
{
bool V_233 = false ;
if ( V_231 ) {
struct V_127 * V_128 = & F_95 ( * V_154 ) ;
if ( V_128 -> V_234 && V_128 -> V_235 == V_236 ) {
V_60 -> V_62 = V_128 -> V_234 ;
V_60 -> V_126 = 1 ;
}
F_173 ( & V_60 -> V_2 , V_231 -> V_237 , true ) ;
#ifdef F_28
V_60 -> V_2 . V_213 = V_128 -> V_238 ;
#endif
V_60 -> V_2 . V_239 = F_174 ( V_128 -> V_240 ) ;
if ( F_155 ( V_109 ) )
V_233 = F_158 ( V_60 , V_109 , V_57 ) ;
else if ( ! ( V_60 -> V_2 . V_219 & V_220 ) )
V_233 = F_160 ( V_128 , V_60 ) ;
if ( F_155 ( ! V_233 ) ) {
V_60 -> V_2 . V_219 |= V_220 ;
if ( ! V_60 -> V_62 )
V_60 -> V_62 = V_57 ;
F_162 ( V_60 ) ;
}
} else
F_162 ( V_60 ) ;
#ifdef F_28
#ifdef F_175
F_150 ( V_60 , V_154 -> V_213 ) ;
#endif
F_150 ( V_60 , V_232 ) ;
#endif
}
static struct V_50 * F_176 ( struct V_58 * V_53 ,
unsigned int V_219 , T_12 type ,
bool V_241 , bool V_242 , bool V_243 )
{
struct V_50 * V_60 ;
V_60 = F_177 ( & V_16 , V_53 , 1 , V_206 ,
( V_243 ? 0 : ( V_244 | V_220 ) ) |
( V_241 ? V_245 : 0 ) |
( V_242 ? V_246 : 0 ) ) ;
if ( V_60 ) {
V_60 -> V_52 = F_34 ( F_35 ( V_53 ) ) ;
V_60 -> V_124 = V_219 ;
V_60 -> V_247 = type ;
V_60 -> V_248 = 0 ;
V_60 -> V_249 = 0 ;
V_60 -> V_119 = 0 ;
V_60 -> V_62 = 0 ;
V_60 -> V_126 = 0 ;
V_60 -> V_250 = 0 ;
F_178 ( & V_60 -> V_227 ) ;
V_60 -> V_2 . V_251 = V_252 ;
if ( V_219 & V_253 )
V_60 -> V_2 . V_254 = V_255 ;
}
return V_60 ;
}
static int F_179 ( struct V_55 * V_56 , T_6 V_57 , T_6 V_79 ,
T_9 V_86 , struct V_58 * V_53 , int V_256 )
{
struct V_50 * V_51 ;
struct V_151 * V_152 = F_82 ( V_53 ) ;
unsigned int V_219 = V_257 ;
T_1 V_232 = 0 ;
int V_258 ;
if ( ! V_152 )
return - V_187 ;
if ( F_84 ( V_79 ) || F_85 ( V_79 ) ||
V_56 -> V_80 != F_51 ( V_259 ) )
goto V_260;
if ( F_180 ( V_79 ) && ! F_181 ( V_152 ) )
goto V_260;
if ( F_86 ( V_79 ) ) {
if ( ! F_182 ( V_57 ) )
goto V_260;
} else {
V_258 = F_183 ( V_56 , V_79 , 0 , V_86 , 0 , V_53 ,
V_152 , & V_232 ) ;
if ( V_258 < 0 )
goto V_261;
}
if ( V_256 )
V_219 |= V_253 ;
V_51 = F_176 ( F_35 ( V_53 ) -> V_229 , V_219 , V_262 ,
F_184 ( V_152 , V_263 ) , false , false ) ;
if ( ! V_51 )
goto V_264;
#ifdef F_28
V_51 -> V_2 . V_213 = V_232 ;
#endif
V_51 -> V_2 . V_251 = F_144 ;
V_51 -> V_248 = 1 ;
#ifdef F_185
if ( ! F_182 ( V_57 ) && F_186 ( V_152 ) )
V_51 -> V_2 . V_254 = V_265 ;
#endif
F_187 ( V_18 ) ;
F_188 ( V_56 , & V_51 -> V_2 ) ;
return 0 ;
V_264:
return - V_266 ;
V_260:
return - V_187 ;
V_261:
return V_258 ;
}
static void F_189 ( struct V_58 * V_53 ,
struct V_151 * V_152 ,
struct V_55 * V_56 ,
T_6 V_57 ,
T_6 V_79 )
{
F_187 ( V_22 ) ;
#ifdef F_98
if ( F_99 ( V_152 ) && F_190 () ) {
F_191 ( L_15 ,
& V_57 , & V_79 , V_53 -> V_166 ) ;
if ( V_53 -> V_267 && F_192 ( V_56 ) ) {
F_193 ( V_268 , L_16 ,
V_269 , 16 , 1 ,
F_194 ( V_56 ) ,
V_53 -> V_267 , true ) ;
}
}
#endif
}
static int F_195 ( struct V_55 * V_56 ,
const struct V_153 * V_154 ,
struct V_151 * V_152 ,
T_6 V_57 , T_6 V_79 , T_1 V_86 )
{
struct V_108 * V_109 ;
struct V_50 * V_51 ;
int V_258 ;
struct V_151 * V_270 ;
bool V_271 ;
T_1 V_232 = 0 ;
V_270 = F_82 ( F_196 ( * V_154 ) ) ;
if ( ! V_270 ) {
F_197 ( L_17 ) ;
return - V_187 ;
}
V_258 = F_183 ( V_56 , V_79 , V_57 , V_86 , F_198 ( * V_154 ) ,
V_152 -> V_53 , V_152 , & V_232 ) ;
if ( V_258 < 0 ) {
F_189 ( V_152 -> V_53 , V_152 , V_56 , V_57 ,
V_79 ) ;
goto V_272;
}
V_271 = V_154 -> V_231 && ! V_232 ;
if ( V_270 == V_152 && V_258 && F_106 ( V_270 ) &&
V_56 -> V_80 == F_51 ( V_259 ) &&
( F_87 ( V_270 ) ||
F_88 ( V_270 , V_79 , F_199 ( * V_154 ) ) ) )
F_200 ( V_56 ) -> V_219 |= V_273 ;
if ( V_56 -> V_80 != F_51 ( V_259 ) ) {
if ( V_270 == V_152 &&
F_201 ( V_152 ) == 0 ) {
V_258 = - V_187 ;
goto V_272;
}
}
V_109 = F_157 ( & F_95 ( * V_154 ) , V_57 ) ;
if ( V_271 ) {
if ( V_109 )
V_51 = F_60 ( V_109 -> V_110 ) ;
else
V_51 = F_60 ( F_95 ( * V_154 ) . V_141 ) ;
if ( F_171 ( V_51 ) ) {
F_202 ( V_56 , & V_51 -> V_2 ) ;
goto V_182;
}
}
V_51 = F_176 ( V_270 -> V_53 , 0 , V_154 -> type ,
F_184 ( V_152 , V_263 ) ,
F_184 ( V_270 , V_274 ) , V_271 ) ;
if ( ! V_51 ) {
V_258 = - V_266 ;
goto V_272;
}
V_51 -> V_248 = 1 ;
if ( V_154 -> V_275 )
V_51 -> V_250 = V_154 -> V_275 -> V_276 ;
F_187 ( V_17 ) ;
V_51 -> V_2 . V_254 = V_277 ;
F_172 ( V_51 , V_57 , V_154 , V_109 , V_154 -> V_231 , V_154 -> type , V_232 ) ;
if ( F_203 ( V_51 -> V_2 . V_239 ) ) {
V_51 -> V_2 . V_239 -> V_278 = V_51 -> V_2 . V_251 ;
V_51 -> V_2 . V_251 = V_279 ;
}
if ( F_204 ( V_51 -> V_2 . V_239 ) ) {
V_51 -> V_2 . V_239 -> V_280 = V_51 -> V_2 . V_254 ;
V_51 -> V_2 . V_254 = V_281 ;
}
F_188 ( V_56 , & V_51 -> V_2 ) ;
V_182:
V_258 = 0 ;
V_272:
return V_258 ;
}
static int F_205 ( struct V_55 * V_56 )
{
const struct V_75 * V_282 = F_39 ( V_56 ) ;
struct V_283 V_284 ;
const struct V_283 * V_285 ;
struct V_75 V_286 ;
const struct V_75 * V_287 ;
if ( F_155 ( ( V_282 -> V_288 & F_51 ( V_289 ) ) != 0 ) )
goto V_290;
V_285 = F_206 ( V_56 , V_282 -> V_291 * 4 , sizeof( V_284 ) ,
& V_284 ) ;
if ( ! V_285 )
goto V_290;
if ( V_285 -> type != V_194 &&
V_285 -> type != V_174 &&
V_285 -> type != V_292 &&
V_285 -> type != V_293 ) {
goto V_290;
}
V_287 = F_206 ( V_56 ,
V_282 -> V_291 * 4 + sizeof( V_284 ) ,
sizeof( V_286 ) , & V_286 ) ;
if ( ! V_287 )
goto V_290;
return F_207 ( V_287 -> V_57 , V_287 -> V_79 ) ;
V_290:
return F_207 ( V_282 -> V_79 , V_282 -> V_57 ) ;
}
static int F_208 ( struct V_55 * V_56 ,
struct V_153 * V_154 ,
const struct V_81 * V_82 ,
struct V_151 * V_152 ,
T_6 V_57 , T_6 V_79 , T_1 V_86 )
{
#ifdef F_209
if ( V_154 -> V_231 && V_154 -> V_231 -> V_294 > 1 ) {
int V_295 ;
if ( F_155 ( F_39 ( V_56 ) -> V_80 == V_296 ) )
V_295 = F_205 ( V_56 ) ;
else
V_295 = F_207 ( V_79 , V_57 ) ;
F_210 ( V_154 , V_295 ) ;
}
#endif
return F_195 ( V_56 , V_154 , V_152 , V_57 , V_79 , V_86 ) ;
}
static int F_211 ( struct V_55 * V_56 , T_6 V_57 , T_6 V_79 ,
T_9 V_86 , struct V_58 * V_53 )
{
struct V_153 V_154 ;
struct V_151 * V_152 = F_82 ( V_53 ) ;
struct V_297 * V_298 ;
struct V_81 V_82 ;
unsigned int V_219 = 0 ;
T_1 V_232 = 0 ;
struct V_50 * V_51 ;
int V_258 = - V_187 ;
struct V_37 * V_37 = F_35 ( V_53 ) ;
bool V_271 ;
if ( ! V_152 )
goto V_182;
V_298 = F_212 ( V_56 ) ;
if ( V_298 && ! ( V_298 -> V_299 & V_300 ) )
V_82 . V_301 . V_302 = V_298 -> V_303 . V_302 ;
else
V_82 . V_301 . V_302 = 0 ;
F_213 ( V_56 ) ;
if ( F_84 ( V_79 ) || F_85 ( V_79 ) )
goto V_304;
V_154 . V_231 = NULL ;
V_154 . V_275 = NULL ;
if ( F_85 ( V_57 ) || ( V_79 == 0 && V_57 == 0 ) )
goto V_305;
if ( F_86 ( V_79 ) )
goto V_304;
if ( F_86 ( V_57 ) )
goto V_306;
if ( F_180 ( V_57 ) ) {
if ( ! F_214 ( V_152 , V_37 ) )
goto V_306;
} else if ( F_180 ( V_79 ) ) {
if ( ! F_214 ( V_152 , V_37 ) )
goto V_304;
}
V_82 . V_210 = 0 ;
V_82 . V_211 = F_215 ( V_53 ) ;
V_82 . V_199 = V_56 -> V_88 ;
V_82 . V_209 = V_86 ;
V_82 . V_307 = V_97 ;
V_82 . V_308 = 0 ;
V_82 . V_57 = V_57 ;
V_82 . V_79 = V_79 ;
V_258 = F_94 ( V_37 , & V_82 , & V_154 , 0 ) ;
if ( V_258 != 0 ) {
if ( ! F_116 ( V_152 ) )
V_258 = - V_183 ;
goto V_309;
}
if ( V_154 . type == V_310 )
goto V_305;
if ( V_154 . type == V_311 ) {
V_258 = F_183 ( V_56 , V_79 , V_57 , V_86 ,
0 , V_53 , V_152 , & V_232 ) ;
if ( V_258 < 0 )
goto V_304;
goto V_312;
}
if ( ! F_116 ( V_152 ) ) {
V_258 = - V_183 ;
goto V_309;
}
if ( V_154 . type != V_161 )
goto V_306;
V_258 = F_208 ( V_56 , & V_154 , & V_82 , V_152 , V_57 , V_79 , V_86 ) ;
V_182: return V_258 ;
V_305:
if ( V_56 -> V_80 != F_51 ( V_259 ) )
goto V_260;
if ( ! F_86 ( V_79 ) ) {
V_258 = F_183 ( V_56 , V_79 , 0 , V_86 , 0 , V_53 ,
V_152 , & V_232 ) ;
if ( V_258 < 0 )
goto V_304;
}
V_219 |= V_313 ;
V_154 . type = V_310 ;
F_187 ( V_20 ) ;
V_312:
V_271 = false ;
if ( V_154 . V_231 ) {
if ( ! V_232 ) {
V_51 = F_60 ( F_95 ( V_154 ) . V_141 ) ;
if ( F_171 ( V_51 ) ) {
F_202 ( V_56 , & V_51 -> V_2 ) ;
V_258 = 0 ;
goto V_182;
}
V_271 = true ;
}
}
V_51 = F_176 ( V_37 -> V_229 , V_219 | V_253 , V_154 . type ,
F_184 ( V_152 , V_263 ) , false , V_271 ) ;
if ( ! V_51 )
goto V_264;
V_51 -> V_2 . V_251 = F_144 ;
#ifdef F_28
V_51 -> V_2 . V_213 = V_232 ;
#endif
V_51 -> V_248 = 1 ;
if ( V_154 . V_275 )
V_51 -> V_250 = V_154 . V_275 -> V_276 ;
F_187 ( V_17 ) ;
if ( V_154 . type == V_314 ) {
V_51 -> V_2 . V_254 = F_115 ;
V_51 -> V_2 . error = - V_258 ;
V_51 -> V_124 &= ~ V_253 ;
}
if ( V_271 ) {
if ( F_155 ( ! F_160 ( & F_95 ( V_154 ) , V_51 ) ) ) {
V_51 -> V_2 . V_219 |= V_220 ;
F_162 ( V_51 ) ;
}
}
F_188 ( V_56 , & V_51 -> V_2 ) ;
V_258 = 0 ;
goto V_182;
V_309:
F_187 ( V_19 ) ;
V_154 . type = V_314 ;
V_154 . V_231 = NULL ;
V_154 . V_275 = NULL ;
goto V_312;
V_306:
F_187 ( V_21 ) ;
#ifdef F_98
if ( F_99 ( V_152 ) )
F_112 ( L_18 ,
& V_57 , & V_79 , V_53 -> V_166 ) ;
#endif
V_260:
V_258 = - V_187 ;
goto V_182;
V_264:
V_258 = - V_266 ;
goto V_182;
V_304:
F_189 ( V_53 , V_152 , V_56 , V_57 , V_79 ) ;
goto V_182;
}
int F_216 ( struct V_55 * V_56 , T_6 V_57 , T_6 V_79 ,
T_9 V_86 , struct V_58 * V_53 )
{
int V_154 ;
F_59 () ;
if ( F_84 ( V_57 ) ) {
struct V_151 * V_152 = F_82 ( V_53 ) ;
if ( V_152 ) {
int V_256 = F_217 ( V_152 , V_57 , V_79 ,
F_39 ( V_56 ) -> V_80 ) ;
if ( V_256
#ifdef F_185
||
( ! F_182 ( V_57 ) &&
F_186 ( V_152 ) )
#endif
) {
int V_154 = F_179 ( V_56 , V_57 , V_79 ,
V_86 , V_53 , V_256 ) ;
F_62 () ;
return V_154 ;
}
}
F_62 () ;
return - V_187 ;
}
V_154 = F_211 ( V_56 , V_57 , V_79 , V_86 , V_53 ) ;
F_62 () ;
return V_154 ;
}
static struct V_50 * F_218 ( const struct V_153 * V_154 ,
const struct V_81 * V_82 , int V_315 ,
struct V_58 * V_316 ,
unsigned int V_219 )
{
struct V_230 * V_231 = V_154 -> V_231 ;
struct V_108 * V_109 ;
struct V_151 * V_152 ;
T_12 type = V_154 -> type ;
struct V_50 * V_51 ;
bool V_271 ;
V_152 = F_82 ( V_316 ) ;
if ( ! V_152 )
return F_219 ( - V_187 ) ;
if ( F_220 ( ! F_181 ( V_152 ) ) )
if ( F_180 ( V_82 -> V_79 ) && ! ( V_316 -> V_219 & V_317 ) )
return F_219 ( - V_187 ) ;
if ( F_85 ( V_82 -> V_57 ) )
type = V_310 ;
else if ( F_84 ( V_82 -> V_57 ) )
type = V_262 ;
else if ( F_86 ( V_82 -> V_57 ) )
return F_219 ( - V_187 ) ;
if ( V_316 -> V_219 & V_317 )
V_219 |= V_253 ;
V_271 = true ;
if ( type == V_310 ) {
V_219 |= V_313 | V_253 ;
V_231 = NULL ;
} else if ( type == V_262 ) {
V_219 |= V_257 | V_253 ;
if ( ! F_217 ( V_152 , V_82 -> V_57 , V_82 -> V_79 ,
V_82 -> V_318 ) )
V_219 &= ~ V_253 ;
else
V_271 = false ;
if ( V_231 && V_154 -> V_319 < 4 )
V_231 = NULL ;
}
V_109 = NULL ;
V_271 &= V_231 != NULL ;
if ( V_271 ) {
struct V_50 T_11 * * V_320 ;
struct V_127 * V_128 = & F_95 ( * V_154 ) ;
V_109 = F_157 ( V_128 , V_82 -> V_57 ) ;
if ( V_109 )
V_320 = & V_109 -> V_111 ;
else {
if ( F_155 ( V_82 -> V_308 &
V_321 &&
! ( V_128 -> V_234 &&
V_128 -> V_235 == V_236 ) ) ) {
V_271 = false ;
goto V_322;
}
V_320 = F_161 ( V_128 -> V_145 ) ;
}
V_51 = F_60 ( * V_320 ) ;
if ( F_171 ( V_51 ) ) {
F_221 ( & V_51 -> V_2 ) ;
return V_51 ;
}
}
V_322:
V_51 = F_176 ( V_316 , V_219 , type ,
F_184 ( V_152 , V_263 ) ,
F_184 ( V_152 , V_274 ) ,
V_271 ) ;
if ( ! V_51 )
return F_219 ( - V_266 ) ;
V_51 -> V_249 = V_315 ? : 0 ;
if ( V_154 -> V_275 )
V_51 -> V_250 = V_154 -> V_275 -> V_276 ;
F_187 ( V_23 ) ;
if ( V_219 & ( V_313 | V_257 ) ) {
if ( V_219 & V_253 &&
! ( V_316 -> V_219 & V_317 ) ) {
V_51 -> V_2 . V_251 = V_323 ;
F_187 ( V_24 ) ;
}
#ifdef F_185
if ( type == V_262 ) {
if ( F_186 ( V_152 ) &&
! F_182 ( V_82 -> V_57 ) ) {
V_51 -> V_2 . V_254 = V_265 ;
V_51 -> V_2 . V_251 = V_323 ;
}
}
#endif
}
F_172 ( V_51 , V_82 -> V_57 , V_154 , V_109 , V_231 , type , 0 ) ;
if ( F_203 ( V_51 -> V_2 . V_239 ) )
V_51 -> V_2 . V_251 = V_279 ;
return V_51 ;
}
struct V_50 * F_222 ( struct V_37 * V_37 , struct V_81 * V_82 ,
int V_324 )
{
struct V_58 * V_316 = NULL ;
T_13 V_86 = F_223 ( V_82 ) ;
unsigned int V_219 = 0 ;
struct V_153 V_154 ;
struct V_50 * V_51 ;
int V_315 ;
int V_258 = - V_185 ;
V_154 . V_213 = 0 ;
V_154 . V_231 = NULL ;
V_154 . V_275 = NULL ;
V_315 = V_82 -> V_210 ;
V_82 -> V_211 = V_325 ;
V_82 -> V_209 = V_86 & V_326 ;
V_82 -> V_307 = ( ( V_86 & V_327 ) ?
V_236 : V_97 ) ;
F_59 () ;
if ( V_82 -> V_79 ) {
V_51 = F_219 ( - V_187 ) ;
if ( F_84 ( V_82 -> V_79 ) ||
F_85 ( V_82 -> V_79 ) ||
F_86 ( V_82 -> V_79 ) )
goto V_182;
if ( V_82 -> V_210 == 0 &&
( F_84 ( V_82 -> V_57 ) ||
F_85 ( V_82 -> V_57 ) ) ) {
V_316 = F_224 ( V_37 , V_82 -> V_79 , false ) ;
if ( ! V_316 )
goto V_182;
V_82 -> V_210 = V_316 -> V_98 ;
goto V_328;
}
if ( ! ( V_82 -> V_308 & V_329 ) ) {
if ( ! F_224 ( V_37 , V_82 -> V_79 , false ) )
goto V_182;
}
}
if ( V_82 -> V_210 ) {
V_316 = F_225 ( V_37 , V_82 -> V_210 ) ;
V_51 = F_219 ( - V_330 ) ;
if ( ! V_316 )
goto V_182;
if ( ! ( V_316 -> V_219 & V_331 ) || ! F_82 ( V_316 ) ) {
V_51 = F_219 ( - V_185 ) ;
goto V_182;
}
if ( F_182 ( V_82 -> V_57 ) ||
F_85 ( V_82 -> V_57 ) ||
V_82 -> V_318 == V_332 ) {
if ( ! V_82 -> V_79 )
V_82 -> V_79 = F_149 ( V_316 , 0 ,
V_236 ) ;
goto V_328;
}
if ( ! V_82 -> V_79 ) {
if ( F_84 ( V_82 -> V_57 ) )
V_82 -> V_79 = F_149 ( V_316 , 0 ,
V_82 -> V_307 ) ;
else if ( ! V_82 -> V_57 )
V_82 -> V_79 = F_149 ( V_316 , 0 ,
V_333 ) ;
}
V_51 = F_226 ( V_316 , V_82 ) ;
if ( V_51 )
goto V_182;
}
if ( ! V_82 -> V_57 ) {
V_82 -> V_57 = V_82 -> V_79 ;
if ( ! V_82 -> V_57 )
V_82 -> V_57 = V_82 -> V_79 = F_227 ( V_334 ) ;
V_316 = V_37 -> V_229 ;
V_82 -> V_210 = V_325 ;
V_154 . type = V_311 ;
V_219 |= V_253 ;
goto V_328;
}
V_258 = F_94 ( V_37 , V_82 , & V_154 , 0 ) ;
if ( V_258 ) {
V_154 . V_231 = NULL ;
V_154 . V_275 = NULL ;
if ( V_82 -> V_210 &&
! F_228 ( V_37 , V_82 -> V_210 ) ) {
if ( V_82 -> V_79 == 0 )
V_82 -> V_79 = F_149 ( V_316 , 0 ,
V_236 ) ;
V_154 . type = V_161 ;
goto V_328;
}
V_51 = F_219 ( V_258 ) ;
goto V_182;
}
if ( V_154 . type == V_311 ) {
if ( ! V_82 -> V_79 ) {
if ( V_154 . V_231 -> V_335 )
V_82 -> V_79 = V_154 . V_231 -> V_335 ;
else
V_82 -> V_79 = V_82 -> V_57 ;
}
V_316 = V_37 -> V_229 ;
V_82 -> V_210 = V_316 -> V_98 ;
V_219 |= V_253 ;
goto V_328;
}
F_229 ( V_37 , & V_154 , V_82 , V_324 ) ;
V_316 = F_196 ( V_154 ) ;
V_82 -> V_210 = V_316 -> V_98 ;
V_328:
V_51 = F_218 ( & V_154 , V_82 , V_315 , V_316 , V_219 ) ;
V_182:
F_62 () ;
return V_51 ;
}
static struct V_1 * F_230 ( struct V_1 * V_2 , T_1 V_205 )
{
return NULL ;
}
static unsigned int F_231 ( const struct V_1 * V_2 )
{
unsigned int V_195 = F_152 ( V_2 , V_196 ) ;
return V_195 ? : V_2 -> V_53 -> V_195 ;
}
static void F_232 ( struct V_1 * V_2 , struct V_83 * V_84 ,
struct V_55 * V_56 , T_1 V_195 )
{
}
static void F_233 ( struct V_1 * V_2 , struct V_83 * V_84 ,
struct V_55 * V_56 )
{
}
static T_1 * F_234 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
return NULL ;
}
struct V_1 * F_235 ( struct V_37 * V_37 , struct V_1 * V_336 )
{
struct V_50 * V_337 = (struct V_50 * ) V_336 ;
struct V_50 * V_60 ;
V_60 = F_177 ( & V_338 , NULL , 1 , V_339 , 0 ) ;
if ( V_60 ) {
struct V_1 * V_201 = & V_60 -> V_2 ;
V_201 -> V_340 = 1 ;
V_201 -> V_254 = V_341 ;
V_201 -> V_251 = V_342 ;
V_201 -> V_53 = V_337 -> V_2 . V_53 ;
if ( V_201 -> V_53 )
F_169 ( V_201 -> V_53 ) ;
V_60 -> V_248 = V_337 -> V_248 ;
V_60 -> V_249 = V_337 -> V_249 ;
V_60 -> V_119 = V_337 -> V_119 ;
V_60 -> V_52 = F_34 ( V_37 ) ;
V_60 -> V_124 = V_337 -> V_124 ;
V_60 -> V_247 = V_337 -> V_247 ;
V_60 -> V_62 = V_337 -> V_62 ;
V_60 -> V_126 = V_337 -> V_126 ;
F_178 ( & V_60 -> V_227 ) ;
F_236 ( V_201 ) ;
}
F_136 ( V_336 ) ;
return V_60 ? & V_60 -> V_2 : F_219 ( - V_32 ) ;
}
struct V_50 * F_134 ( struct V_37 * V_37 , struct V_81 * V_343 ,
const struct V_83 * V_84 )
{
struct V_50 * V_60 = F_126 ( V_37 , V_343 ) ;
if ( F_92 ( V_60 ) )
return V_60 ;
if ( V_343 -> V_318 )
V_60 = (struct V_50 * ) F_237 ( V_37 , & V_60 -> V_2 ,
F_238 ( V_343 ) ,
V_84 , 0 ) ;
return V_60 ;
}
static int F_239 ( struct V_37 * V_37 , T_6 V_2 , T_6 V_28 , T_1 V_344 ,
struct V_81 * V_82 , struct V_55 * V_56 , T_1 V_345 ,
T_1 V_5 , int V_346 , int V_347 , unsigned int V_219 )
{
struct V_50 * V_60 = F_105 ( V_56 ) ;
struct V_348 * V_349 ;
struct V_350 * V_351 ;
unsigned long V_121 = 0 ;
T_1 error ;
T_1 V_352 [ V_353 ] ;
V_351 = F_240 ( V_56 , V_345 , V_5 , V_346 , sizeof( * V_349 ) , V_219 ) ;
if ( ! V_351 )
return - V_354 ;
V_349 = F_241 ( V_351 ) ;
V_349 -> V_355 = V_356 ;
V_349 -> V_357 = 32 ;
V_349 -> V_358 = 0 ;
V_349 -> V_359 = V_82 -> V_209 ;
V_349 -> V_360 = V_344 ;
if ( F_242 ( V_56 , V_361 , V_344 ) )
goto V_362;
V_349 -> V_363 = V_60 -> V_247 ;
V_349 -> V_364 = V_97 ;
V_349 -> V_365 = V_366 ;
V_349 -> V_367 = ( V_60 -> V_124 & ~ 0xFFFF ) | V_368 ;
if ( V_60 -> V_124 & V_369 )
V_349 -> V_367 |= V_370 ;
if ( F_200 ( V_56 ) -> V_219 & V_273 )
V_349 -> V_367 |= V_371 ;
if ( F_243 ( V_56 , V_372 , V_2 ) )
goto V_362;
if ( V_28 ) {
V_349 -> V_358 = 32 ;
if ( F_243 ( V_56 , V_373 , V_28 ) )
goto V_362;
}
if ( V_60 -> V_2 . V_53 &&
F_242 ( V_56 , V_374 , V_60 -> V_2 . V_53 -> V_98 ) )
goto V_362;
#ifdef F_28
if ( V_60 -> V_2 . V_213 &&
F_242 ( V_56 , V_375 , V_60 -> V_2 . V_213 ) )
goto V_362;
#endif
if ( ! F_159 ( V_60 ) &&
V_82 -> V_79 != V_28 ) {
if ( F_243 ( V_56 , V_376 , V_82 -> V_79 ) )
goto V_362;
}
if ( V_60 -> V_126 &&
F_243 ( V_56 , V_377 , V_60 -> V_62 ) )
goto V_362;
V_121 = V_60 -> V_2 . V_121 ;
if ( V_121 ) {
unsigned long V_72 = V_73 ;
if ( F_69 ( V_72 , V_121 ) )
V_121 -= V_72 ;
else
V_121 = 0 ;
}
memcpy ( V_352 , F_244 ( & V_60 -> V_2 ) , sizeof( V_352 ) ) ;
if ( V_60 -> V_119 && V_121 )
V_352 [ V_196 - 1 ] = V_60 -> V_119 ;
if ( F_245 ( V_56 , V_352 ) < 0 )
goto V_362;
if ( V_82 -> V_199 &&
F_242 ( V_56 , V_378 , V_82 -> V_199 ) )
goto V_362;
error = V_60 -> V_2 . error ;
if ( F_159 ( V_60 ) ) {
#ifdef F_185
if ( F_84 ( V_2 ) && ! F_182 ( V_2 ) &&
F_246 ( V_37 , V_379 ) ) {
int V_258 = F_247 ( V_37 , V_56 ,
V_82 -> V_79 , V_82 -> V_57 ,
V_349 , V_347 ) ;
if ( V_258 <= 0 ) {
if ( ! V_347 ) {
if ( V_258 == 0 )
return 0 ;
goto V_362;
} else {
if ( V_258 == - V_354 )
goto V_362;
error = V_258 ;
}
}
} else
#endif
if ( F_242 ( V_56 , V_380 , V_56 -> V_53 -> V_98 ) )
goto V_362;
}
if ( F_248 ( V_56 , & V_60 -> V_2 , 0 , V_121 , error ) < 0 )
goto V_362;
F_249 ( V_56 , V_351 ) ;
return 0 ;
V_362:
F_250 ( V_56 , V_351 ) ;
return - V_354 ;
}
static int F_251 ( struct V_55 * V_381 , struct V_350 * V_351 )
{
struct V_37 * V_37 = F_128 ( V_381 -> V_84 ) ;
struct V_348 * V_382 ;
struct V_383 * V_384 [ V_385 + 1 ] ;
struct V_50 * V_60 = NULL ;
struct V_81 V_82 ;
T_6 V_2 = 0 ;
T_6 V_28 = 0 ;
T_1 V_386 ;
int V_258 ;
int V_88 ;
struct V_55 * V_56 ;
T_1 V_344 = V_387 ;
V_258 = F_252 ( V_351 , sizeof( * V_382 ) , V_384 , V_385 , V_388 ) ;
if ( V_258 < 0 )
goto V_389;
V_382 = F_241 ( V_351 ) ;
V_56 = F_253 ( V_390 , V_31 ) ;
if ( ! V_56 ) {
V_258 = - V_266 ;
goto V_389;
}
F_254 ( V_56 ) ;
F_255 ( V_56 ) ;
F_39 ( V_56 ) -> V_80 = V_296 ;
F_256 ( V_56 , V_391 + sizeof( struct V_75 ) ) ;
V_28 = V_384 [ V_373 ] ? F_257 ( V_384 [ V_373 ] ) : 0 ;
V_2 = V_384 [ V_372 ] ? F_257 ( V_384 [ V_372 ] ) : 0 ;
V_386 = V_384 [ V_380 ] ? F_258 ( V_384 [ V_380 ] ) : 0 ;
V_88 = V_384 [ V_378 ] ? F_258 ( V_384 [ V_378 ] ) : 0 ;
memset ( & V_82 , 0 , sizeof( V_82 ) ) ;
V_82 . V_57 = V_2 ;
V_82 . V_79 = V_28 ;
V_82 . V_209 = V_382 -> V_359 ;
V_82 . V_210 = V_384 [ V_374 ] ? F_258 ( V_384 [ V_374 ] ) : 0 ;
V_82 . V_199 = V_88 ;
if ( F_228 ( V_37 , V_82 . V_210 ) )
V_82 . V_308 = V_392 | V_393 ;
if ( V_386 ) {
struct V_58 * V_53 ;
V_53 = F_259 ( V_37 , V_386 ) ;
if ( ! V_53 ) {
V_258 = - V_330 ;
goto V_394;
}
V_56 -> V_80 = F_51 ( V_259 ) ;
V_56 -> V_53 = V_53 ;
V_56 -> V_88 = V_88 ;
F_260 () ;
V_258 = F_261 ( V_56 , V_2 , V_28 , V_382 -> V_359 , V_53 ) ;
F_262 () ;
V_60 = F_105 ( V_56 ) ;
if ( V_258 == 0 && V_60 -> V_2 . error )
V_258 = - V_60 -> V_2 . error ;
} else {
V_60 = F_263 ( V_37 , & V_82 ) ;
V_258 = 0 ;
if ( F_92 ( V_60 ) )
V_258 = F_264 ( V_60 ) ;
}
if ( V_258 )
goto V_394;
F_188 ( V_56 , & V_60 -> V_2 ) ;
if ( V_382 -> V_367 & V_370 )
V_60 -> V_124 |= V_369 ;
if ( V_382 -> V_367 & V_395 )
V_344 = V_60 -> V_250 ;
V_258 = F_239 ( V_37 , V_2 , V_28 , V_344 , & V_82 , V_56 ,
F_265 ( V_381 ) . V_345 , V_351 -> V_396 ,
V_397 , 0 , 0 ) ;
if ( V_258 < 0 )
goto V_394;
V_258 = F_266 ( V_56 , V_37 , F_265 ( V_381 ) . V_345 ) ;
V_389:
return V_258 ;
V_394:
F_119 ( V_56 ) ;
goto V_389;
}
void F_267 ( struct V_151 * V_152 )
{
F_36 ( F_35 ( V_152 -> V_53 ) ) ;
}
static int F_268 ( struct V_398 * V_399 , int V_400 ,
void T_14 * V_401 ,
T_15 * V_402 , T_2 * V_403 )
{
struct V_37 * V_37 = (struct V_37 * ) V_399 -> V_404 ;
if ( V_400 ) {
F_36 ( V_37 ) ;
F_269 ( V_37 ) ;
return 0 ;
}
return - V_187 ;
}
static T_3 int F_270 ( struct V_37 * V_37 )
{
struct V_398 * V_405 ;
V_405 = V_406 ;
if ( ! F_271 ( V_37 , & V_407 ) ) {
V_405 = F_272 ( V_405 , sizeof( V_406 ) , V_31 ) ;
if ( ! V_405 )
goto V_408;
if ( V_37 -> V_409 != & V_410 )
V_405 [ 0 ] . V_411 = NULL ;
}
V_405 [ 0 ] . V_404 = V_37 ;
V_37 -> V_172 . V_412 = F_273 ( V_37 , L_19 , V_405 ) ;
if ( ! V_37 -> V_172 . V_412 )
goto V_413;
return 0 ;
V_413:
if ( V_405 != V_406 )
F_23 ( V_405 ) ;
V_408:
return - V_32 ;
}
static T_4 void F_274 ( struct V_37 * V_37 )
{
struct V_398 * V_405 ;
V_405 = V_37 -> V_172 . V_412 -> V_414 ;
F_275 ( V_37 -> V_172 . V_412 ) ;
F_276 ( V_405 == V_406 ) ;
F_23 ( V_405 ) ;
}
static T_3 int F_277 ( struct V_37 * V_37 )
{
F_278 ( & V_37 -> V_172 . V_52 , 0 ) ;
F_278 ( & V_37 -> V_139 , 0 ) ;
F_279 ( & V_37 -> V_172 . V_415 ,
sizeof( V_37 -> V_172 . V_415 ) ) ;
return 0 ;
}
static int T_3 F_280 ( struct V_37 * V_37 )
{
struct V_416 * V_417 = F_281 ( sizeof( * V_417 ) , V_31 ) ;
if ( ! V_417 )
return - V_32 ;
F_282 ( V_417 ) ;
V_37 -> V_172 . V_173 = V_417 ;
return 0 ;
}
static void T_4 F_283 ( struct V_37 * V_37 )
{
struct V_416 * V_417 = V_37 -> V_172 . V_173 ;
V_37 -> V_172 . V_173 = NULL ;
F_284 ( V_417 ) ;
F_23 ( V_417 ) ;
}
int T_5 F_285 ( void )
{
int V_418 = 0 ;
int V_12 ;
V_71 = F_281 ( V_69 * sizeof( * V_71 ) , V_31 ) ;
if ( ! V_71 )
F_286 ( L_20 ) ;
F_287 ( V_71 , V_69 * sizeof( * V_71 ) ) ;
V_68 = F_19 ( V_69 , sizeof( * V_68 ) , V_31 ) ;
if ( ! V_68 )
F_286 ( L_21 ) ;
F_20 (cpu) {
struct V_223 * V_224 = & F_12 ( V_225 , V_12 ) ;
F_178 ( & V_224 -> V_228 ) ;
F_288 ( & V_224 -> V_226 ) ;
}
#ifdef F_28
V_27 = F_289 ( 256 * sizeof( struct V_27 ) , F_290 ( struct V_27 ) ) ;
if ( ! V_27 )
F_286 ( L_22 ) ;
#endif
V_16 . V_419 =
F_291 ( L_23 , sizeof( struct V_50 ) , 0 ,
V_420 | V_421 , NULL ) ;
V_338 . V_419 = V_16 . V_419 ;
if ( F_292 ( & V_16 ) < 0 )
F_286 ( L_24 ) ;
if ( F_292 ( & V_338 ) < 0 )
F_286 ( L_25 ) ;
V_16 . V_422 = ~ 0 ;
V_423 = V_424 ;
F_293 () ;
F_294 () ;
if ( F_31 () )
F_295 ( L_26 ) ;
#ifdef F_296
F_297 () ;
F_298 () ;
#endif
F_299 ( V_425 , V_426 , F_251 , NULL , NULL ) ;
#ifdef F_300
F_32 ( & V_427 ) ;
#endif
F_32 ( & V_428 ) ;
F_32 ( & V_429 ) ;
return V_418 ;
}
void T_5 F_301 ( void )
{
F_273 ( & V_407 , L_19 , V_430 ) ;
}
