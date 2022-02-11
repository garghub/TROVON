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
0 , V_73 + V_164 ) ;
}
if ( V_146 )
V_60 -> V_2 . V_142 = V_143 ;
F_96 ( V_165 , V_61 ) ;
}
F_97 ( V_61 ) ;
}
return;
V_160:
#ifdef F_98
if ( F_99 ( V_152 ) ) {
const struct V_75 * V_76 = ( const struct V_75 * ) V_56 -> V_166 ;
T_6 V_57 = V_76 -> V_57 ;
T_6 V_79 = V_76 -> V_79 ;
F_100 ( L_10
L_11 ,
& V_150 , V_53 -> V_167 , & V_147 ,
& V_79 , & V_57 ) ;
}
#endif
;
}
static void F_101 ( struct V_1 * V_2 , struct V_83 * V_84 , struct V_55 * V_56 )
{
struct V_50 * V_60 ;
struct V_81 V_82 ;
const struct V_75 * V_76 = ( const struct V_75 * ) V_56 -> V_166 ;
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
struct V_1 * V_168 = V_2 ;
if ( V_60 ) {
if ( V_2 -> V_142 > 0 ) {
F_103 ( V_60 ) ;
V_168 = NULL ;
} else if ( ( V_60 -> V_124 & V_125 ) ||
V_60 -> V_2 . V_121 ) {
F_103 ( V_60 ) ;
V_168 = NULL ;
}
}
return V_168 ;
}
void F_104 ( struct V_55 * V_56 )
{
struct V_50 * V_60 = F_105 ( V_56 ) ;
struct V_151 * V_152 ;
struct V_169 * V_170 ;
struct V_37 * V_37 ;
int V_171 ;
int V_172 ;
F_59 () ;
V_152 = F_82 ( V_60 -> V_2 . V_53 ) ;
if ( ! V_152 || ! F_106 ( V_152 ) ) {
F_62 () ;
return;
}
V_171 = F_99 ( V_152 ) ;
V_172 = F_107 ( V_60 -> V_2 . V_53 ) ;
F_62 () ;
V_37 = F_35 ( V_60 -> V_2 . V_53 ) ;
V_170 = F_108 ( V_37 -> V_173 . V_174 , F_39 ( V_56 ) -> V_79 , V_172 , 1 ) ;
if ( ! V_170 ) {
F_109 ( V_56 , V_175 , V_158 ,
F_110 ( V_60 , F_39 ( V_56 ) -> V_57 ) ) ;
return;
}
if ( F_111 ( V_73 , V_170 -> V_176 + V_177 ) )
V_170 -> V_178 = 0 ;
if ( V_170 -> V_178 >= V_179 ) {
V_170 -> V_176 = V_73 ;
goto V_180;
}
if ( V_170 -> V_178 == 0 ||
F_111 ( V_73 ,
( V_170 -> V_176 +
( V_181 << V_170 -> V_178 ) ) ) ) {
T_6 V_129 = F_110 ( V_60 , F_39 ( V_56 ) -> V_57 ) ;
F_109 ( V_56 , V_175 , V_158 , V_129 ) ;
V_170 -> V_176 = V_73 ;
++ V_170 -> V_178 ;
#ifdef F_98
if ( V_171 &&
V_170 -> V_178 == V_179 )
F_112 ( L_12 ,
& F_39 ( V_56 ) -> V_79 , F_113 ( V_56 ) ,
& F_39 ( V_56 ) -> V_57 , & V_129 ) ;
#endif
}
V_180:
F_114 ( V_170 ) ;
}
static int F_115 ( struct V_55 * V_56 )
{
struct V_151 * V_152 = F_82 ( V_56 -> V_53 ) ;
struct V_50 * V_60 = F_105 ( V_56 ) ;
struct V_169 * V_170 ;
unsigned long V_72 ;
struct V_37 * V_37 ;
bool V_182 ;
int V_155 ;
if ( ! V_152 )
goto V_183;
V_37 = F_35 ( V_60 -> V_2 . V_53 ) ;
if ( ! F_116 ( V_152 ) ) {
switch ( V_60 -> V_2 . error ) {
case V_184 :
F_117 ( V_37 , V_185 ) ;
break;
case V_186 :
F_117 ( V_37 , V_187 ) ;
break;
}
goto V_183;
}
switch ( V_60 -> V_2 . error ) {
case V_188 :
default:
goto V_183;
case V_184 :
V_155 = V_189 ;
break;
case V_186 :
V_155 = V_190 ;
F_117 ( V_37 , V_187 ) ;
break;
case V_191 :
V_155 = V_192 ;
break;
}
V_170 = F_108 ( V_37 -> V_173 . V_174 , F_39 ( V_56 ) -> V_79 ,
F_118 ( V_56 -> V_53 ) , 1 ) ;
V_182 = true ;
if ( V_170 ) {
V_72 = V_73 ;
V_170 -> V_178 += V_72 - V_170 -> V_176 ;
if ( V_170 -> V_178 > V_193 )
V_170 -> V_178 = V_193 ;
V_170 -> V_176 = V_72 ;
if ( V_170 -> V_178 >= V_194 )
V_170 -> V_178 -= V_194 ;
else
V_182 = false ;
F_114 ( V_170 ) ;
}
if ( V_182 )
F_109 ( V_56 , V_195 , V_155 , 0 ) ;
V_183: F_119 ( V_56 ) ;
return 0 ;
}
static void F_120 ( struct V_50 * V_60 , struct V_81 * V_82 , T_1 V_196 )
{
struct V_1 * V_2 = & V_60 -> V_2 ;
struct V_153 V_154 ;
if ( F_121 ( V_2 , V_197 ) )
return;
if ( F_122 ( V_2 ) < V_196 )
return;
if ( V_196 < V_198 )
V_196 = V_198 ;
if ( V_60 -> V_119 == V_196 &&
F_69 ( V_73 , V_2 -> V_121 - V_199 / 2 ) )
return;
F_59 () ;
if ( F_94 ( F_35 ( V_2 -> V_53 ) , V_82 , & V_154 , 0 ) == 0 ) {
struct V_127 * V_128 = & F_95 ( V_154 ) ;
F_74 ( V_128 , V_82 -> V_57 , 0 , V_196 ,
V_73 + V_199 ) ;
}
F_62 () ;
}
static void F_123 ( struct V_1 * V_2 , struct V_83 * V_84 ,
struct V_55 * V_56 , T_1 V_196 )
{
struct V_50 * V_60 = (struct V_50 * ) V_2 ;
struct V_81 V_82 ;
F_63 ( & V_82 , V_84 , V_56 ) ;
F_120 ( V_60 , & V_82 , V_196 ) ;
}
void F_124 ( struct V_55 * V_56 , struct V_37 * V_37 , T_1 V_196 ,
int V_85 , T_1 V_88 , T_9 V_80 , int V_89 )
{
const struct V_75 * V_76 = ( const struct V_75 * ) V_56 -> V_166 ;
struct V_81 V_82 ;
struct V_50 * V_60 ;
if ( ! V_88 )
V_88 = F_125 ( V_37 , V_56 -> V_88 ) ;
F_52 ( & V_82 , NULL , V_76 , V_85 ,
F_57 ( V_76 -> V_86 ) , V_80 , V_88 , V_89 ) ;
V_60 = F_126 ( V_37 , & V_82 ) ;
if ( ! F_92 ( V_60 ) ) {
F_120 ( V_60 , & V_82 , V_196 ) ;
F_103 ( V_60 ) ;
}
}
static void F_127 ( struct V_55 * V_56 , struct V_83 * V_84 , T_1 V_196 )
{
const struct V_75 * V_76 = ( const struct V_75 * ) V_56 -> V_166 ;
struct V_81 V_82 ;
struct V_50 * V_60 ;
F_52 ( & V_82 , V_84 , V_76 , 0 , 0 , 0 , 0 , 0 ) ;
if ( ! V_82 . V_200 )
V_82 . V_200 = F_125 ( F_128 ( V_84 ) , V_56 -> V_88 ) ;
V_60 = F_126 ( F_128 ( V_84 ) , & V_82 ) ;
if ( ! F_92 ( V_60 ) ) {
F_120 ( V_60 , & V_82 , V_196 ) ;
F_103 ( V_60 ) ;
}
}
void F_129 ( struct V_55 * V_56 , struct V_83 * V_84 , T_1 V_196 )
{
const struct V_75 * V_76 = ( const struct V_75 * ) V_56 -> V_166 ;
struct V_81 V_82 ;
struct V_50 * V_60 ;
struct V_1 * V_201 = NULL ;
bool V_202 = false ;
F_130 ( V_84 ) ;
if ( ! F_131 ( V_84 ) )
goto V_183;
V_201 = F_132 ( V_84 ) ;
if ( F_133 ( V_84 ) || ! V_201 ) {
F_127 ( V_56 , V_84 , V_196 ) ;
goto V_183;
}
F_52 ( & V_82 , V_84 , V_76 , 0 , 0 , 0 , 0 , 0 ) ;
V_60 = (struct V_50 * ) V_201 ;
if ( V_201 -> V_142 && ! V_201 -> V_203 -> V_204 ( V_201 , 0 ) ) {
V_60 = F_134 ( F_128 ( V_84 ) , & V_82 , V_84 ) ;
if ( F_92 ( V_60 ) )
goto V_183;
V_202 = true ;
}
F_120 ( (struct V_50 * ) V_60 -> V_2 . V_205 , & V_82 , V_196 ) ;
if ( ! F_135 ( & V_60 -> V_2 , 0 ) ) {
if ( V_202 )
F_136 ( & V_60 -> V_2 ) ;
V_60 = F_134 ( F_128 ( V_84 ) , & V_82 , V_84 ) ;
if ( F_92 ( V_60 ) )
goto V_183;
V_202 = true ;
}
if ( V_202 )
F_137 ( V_84 , & V_60 -> V_2 ) ;
V_183:
F_138 ( V_84 ) ;
F_136 ( V_201 ) ;
}
void F_139 ( struct V_55 * V_56 , struct V_37 * V_37 ,
int V_85 , T_1 V_88 , T_9 V_80 , int V_89 )
{
const struct V_75 * V_76 = ( const struct V_75 * ) V_56 -> V_166 ;
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
const struct V_75 * V_76 = ( const struct V_75 * ) V_56 -> V_166 ;
struct V_81 V_82 ;
struct V_50 * V_60 ;
F_52 ( & V_82 , V_84 , V_76 , 0 , 0 , 0 , 0 , 0 ) ;
V_60 = F_126 ( F_128 ( V_84 ) , & V_82 ) ;
if ( ! F_92 ( V_60 ) ) {
F_80 ( V_60 , V_56 , & V_82 , false ) ;
F_103 ( V_60 ) ;
}
}
static struct V_1 * F_141 ( struct V_1 * V_2 , T_1 V_206 )
{
struct V_50 * V_60 = (struct V_50 * ) V_2 ;
if ( V_2 -> V_142 != V_207 || F_33 ( V_60 ) )
return NULL ;
return V_2 ;
}
static void F_142 ( struct V_55 * V_56 )
{
struct V_50 * V_60 ;
F_109 ( V_56 , V_195 , V_189 , 0 ) ;
V_60 = F_105 ( V_56 ) ;
if ( V_60 )
F_143 ( & V_60 -> V_2 , 0 ) ;
}
static int F_144 ( struct V_37 * V_37 , struct V_83 * V_84 , struct V_55 * V_56 )
{
F_145 ( L_13 ,
V_208 , & F_39 ( V_56 ) -> V_79 , & F_39 ( V_56 ) -> V_57 ,
V_56 -> V_53 ? V_56 -> V_53 -> V_167 : L_14 ) ;
F_119 ( V_56 ) ;
F_2 ( 1 ) ;
return 0 ;
}
void F_146 ( T_9 * V_209 , struct V_55 * V_56 , struct V_50 * V_60 )
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
V_82 . V_210 = F_57 ( V_76 -> V_86 ) ;
V_82 . V_211 = V_60 -> V_2 . V_53 -> V_98 ;
V_82 . V_212 = V_56 -> V_53 -> V_98 ;
V_82 . V_200 = V_56 -> V_88 ;
F_59 () ;
if ( F_94 ( F_35 ( V_60 -> V_2 . V_53 ) , & V_82 , & V_154 , 0 ) == 0 )
V_28 = F_148 ( F_35 ( V_60 -> V_2 . V_53 ) , V_154 ) ;
else
V_28 = F_149 ( V_60 -> V_2 . V_53 ,
F_110 ( V_60 , V_76 -> V_57 ) ,
V_97 ) ;
F_62 () ;
}
memcpy ( V_209 , & V_28 , 4 ) ;
}
static void F_150 ( struct V_50 * V_60 , T_1 V_213 )
{
if ( ! ( V_60 -> V_2 . V_214 & 0xFFFF ) )
V_60 -> V_2 . V_214 |= V_213 & 0xFFFF ;
if ( ! ( V_60 -> V_2 . V_214 & 0xFFFF0000 ) )
V_60 -> V_2 . V_214 |= V_213 & 0xFFFF0000 ;
}
static unsigned int F_151 ( const struct V_1 * V_2 )
{
unsigned int V_215 = F_152 ( V_2 , V_216 ) ;
if ( V_215 == 0 ) {
V_215 = F_153 (unsigned int, dst->dev->mtu - 40 ,
ip_rt_min_advmss) ;
if ( V_215 > 65535 - 40 )
V_215 = 65535 - 40 ;
}
return V_215 ;
}
static unsigned int F_122 ( const struct V_1 * V_2 )
{
const struct V_50 * V_60 = ( const struct V_50 * ) V_2 ;
unsigned int V_196 = V_60 -> V_119 ;
if ( ! V_196 || F_154 ( V_73 , V_60 -> V_2 . V_121 ) )
V_196 = F_152 ( V_2 , V_197 ) ;
if ( V_196 )
return V_196 ;
V_196 = V_2 -> V_53 -> V_196 ;
if ( F_155 ( F_121 ( V_2 , V_197 ) ) ) {
if ( V_60 -> V_126 && V_196 > 576 )
V_196 = 576 ;
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
bool V_168 = false ;
F_75 ( & V_132 ) ;
if ( V_57 == V_109 -> V_137 ) {
struct V_50 T_11 * * V_217 ;
struct V_50 * V_218 ;
int V_219 = V_139 ( F_35 ( V_60 -> V_2 . V_53 ) ) ;
if ( F_159 ( V_60 ) )
V_217 = & V_109 -> V_110 ;
else
V_217 = & V_109 -> V_111 ;
V_218 = F_60 ( * V_217 ) ;
if ( V_109 -> V_139 != V_219 ) {
V_109 -> V_139 = V_219 ;
V_109 -> V_123 = 0 ;
V_109 -> V_120 = 0 ;
V_109 -> V_122 = 0 ;
F_66 ( V_109 ) ;
V_218 = NULL ;
}
F_73 ( V_60 , V_109 ) ;
if ( ! V_60 -> V_62 )
V_60 -> V_62 = V_57 ;
if ( ! ( V_60 -> V_2 . V_220 & V_221 ) ) {
F_77 ( * V_217 , V_60 ) ;
if ( V_218 )
F_64 ( V_218 ) ;
V_168 = true ;
}
V_109 -> V_116 = V_73 ;
}
F_79 ( & V_132 ) ;
return V_168 ;
}
static bool F_160 ( struct V_127 * V_128 , struct V_50 * V_60 )
{
struct V_50 * V_218 , * V_222 , * * V_223 ;
bool V_168 = true ;
if ( F_159 ( V_60 ) ) {
V_223 = (struct V_50 * * ) & V_128 -> V_141 ;
} else {
V_223 = (struct V_50 * * ) F_161 ( V_128 -> V_145 ) ;
}
V_218 = * V_223 ;
V_222 = F_44 ( V_223 , V_218 , V_60 ) ;
if ( V_222 == V_218 ) {
if ( V_218 )
F_64 ( V_218 ) ;
} else
V_168 = false ;
return V_168 ;
}
static void F_162 ( struct V_50 * V_60 )
{
struct V_224 * V_225 = F_161 ( & V_226 ) ;
V_60 -> V_226 = V_225 ;
F_75 ( & V_225 -> V_227 ) ;
F_163 ( & V_60 -> V_228 , & V_225 -> V_229 ) ;
F_79 ( & V_225 -> V_227 ) ;
}
static void F_164 ( struct V_1 * V_2 )
{
struct V_50 * V_60 = (struct V_50 * ) V_2 ;
if ( ! F_165 ( & V_60 -> V_228 ) ) {
struct V_224 * V_225 = V_60 -> V_226 ;
F_75 ( & V_225 -> V_227 ) ;
F_166 ( & V_60 -> V_228 ) ;
F_79 ( & V_225 -> V_227 ) ;
}
}
void F_167 ( struct V_58 * V_53 )
{
struct V_37 * V_37 = F_35 ( V_53 ) ;
struct V_50 * V_60 ;
int V_12 ;
F_20 (cpu) {
struct V_224 * V_225 = & F_12 ( V_226 , V_12 ) ;
F_75 ( & V_225 -> V_227 ) ;
F_168 (rt, &ul->head, rt_uncached) {
if ( V_60 -> V_2 . V_53 != V_53 )
continue;
V_60 -> V_2 . V_53 = V_37 -> V_230 ;
F_169 ( V_60 -> V_2 . V_53 ) ;
F_170 ( V_53 ) ;
}
F_79 ( & V_225 -> V_227 ) ;
}
}
static bool F_171 ( const struct V_50 * V_60 )
{
return V_60 &&
V_60 -> V_2 . V_142 == V_207 &&
! F_33 ( V_60 ) ;
}
static void F_172 ( struct V_50 * V_60 , T_6 V_57 ,
const struct V_153 * V_154 ,
struct V_108 * V_109 ,
struct V_231 * V_232 , T_12 type , T_1 V_233 )
{
bool V_234 = false ;
if ( V_232 ) {
struct V_127 * V_128 = & F_95 ( * V_154 ) ;
if ( V_128 -> V_235 && V_128 -> V_236 == V_237 ) {
V_60 -> V_62 = V_128 -> V_235 ;
V_60 -> V_126 = 1 ;
}
F_173 ( & V_60 -> V_2 , V_232 -> V_238 , true ) ;
#ifdef F_28
V_60 -> V_2 . V_214 = V_128 -> V_239 ;
#endif
V_60 -> V_2 . V_240 = F_174 ( V_128 -> V_241 ) ;
if ( F_155 ( V_109 ) )
V_234 = F_158 ( V_60 , V_109 , V_57 ) ;
else if ( ! ( V_60 -> V_2 . V_220 & V_221 ) )
V_234 = F_160 ( V_128 , V_60 ) ;
if ( F_155 ( ! V_234 ) ) {
V_60 -> V_2 . V_220 |= V_221 ;
if ( ! V_60 -> V_62 )
V_60 -> V_62 = V_57 ;
F_162 ( V_60 ) ;
}
} else
F_162 ( V_60 ) ;
#ifdef F_28
#ifdef F_175
F_150 ( V_60 , V_154 -> V_214 ) ;
#endif
F_150 ( V_60 , V_233 ) ;
#endif
}
static struct V_50 * F_176 ( struct V_58 * V_53 ,
unsigned int V_220 , T_12 type ,
bool V_242 , bool V_243 , bool V_244 )
{
struct V_50 * V_60 ;
V_60 = F_177 ( & V_16 , V_53 , 1 , V_207 ,
( V_244 ? 0 : ( V_245 | V_221 ) ) |
( V_242 ? V_246 : 0 ) |
( V_243 ? V_247 : 0 ) ) ;
if ( V_60 ) {
V_60 -> V_52 = F_34 ( F_35 ( V_53 ) ) ;
V_60 -> V_124 = V_220 ;
V_60 -> V_248 = type ;
V_60 -> V_249 = 0 ;
V_60 -> V_250 = 0 ;
V_60 -> V_119 = 0 ;
V_60 -> V_62 = 0 ;
V_60 -> V_126 = 0 ;
V_60 -> V_251 = 0 ;
F_178 ( & V_60 -> V_228 ) ;
V_60 -> V_2 . V_252 = V_253 ;
if ( V_220 & V_254 )
V_60 -> V_2 . V_255 = V_256 ;
}
return V_60 ;
}
static int F_179 ( struct V_55 * V_56 , T_6 V_57 , T_6 V_79 ,
T_9 V_86 , struct V_58 * V_53 , int V_257 )
{
struct V_50 * V_51 ;
struct V_151 * V_152 = F_82 ( V_53 ) ;
unsigned int V_220 = V_258 ;
T_1 V_233 = 0 ;
int V_259 ;
if ( ! V_152 )
return - V_188 ;
if ( F_84 ( V_79 ) || F_85 ( V_79 ) ||
V_56 -> V_80 != F_51 ( V_260 ) )
goto V_261;
if ( F_180 ( V_79 ) && ! F_181 ( V_152 ) )
goto V_261;
if ( F_86 ( V_79 ) ) {
if ( ! F_182 ( V_57 ) )
goto V_261;
} else {
V_259 = F_183 ( V_56 , V_79 , 0 , V_86 , 0 , V_53 ,
V_152 , & V_233 ) ;
if ( V_259 < 0 )
goto V_262;
}
if ( V_257 )
V_220 |= V_254 ;
V_51 = F_176 ( F_35 ( V_53 ) -> V_230 , V_220 , V_263 ,
F_184 ( V_152 , V_264 ) , false , false ) ;
if ( ! V_51 )
goto V_265;
#ifdef F_28
V_51 -> V_2 . V_214 = V_233 ;
#endif
V_51 -> V_2 . V_252 = F_144 ;
V_51 -> V_249 = 1 ;
#ifdef F_185
if ( ! F_182 ( V_57 ) && F_186 ( V_152 ) )
V_51 -> V_2 . V_255 = V_266 ;
#endif
F_187 ( V_18 ) ;
F_188 ( V_56 , & V_51 -> V_2 ) ;
return 0 ;
V_265:
return - V_267 ;
V_261:
return - V_188 ;
V_262:
return V_259 ;
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
& V_57 , & V_79 , V_53 -> V_167 ) ;
if ( V_53 -> V_268 && F_192 ( V_56 ) ) {
F_193 ( V_269 , L_16 ,
V_270 , 16 , 1 ,
F_194 ( V_56 ) ,
V_53 -> V_268 , true ) ;
}
}
#endif
}
static void F_195 ( struct V_127 * V_128 , T_6 V_57 )
{
struct V_112 * V_65 ;
struct V_108 * V_109 , T_11 * * V_271 ;
T_1 V_117 = F_70 ( V_57 ) ;
F_75 ( & V_132 ) ;
V_65 = F_196 ( V_128 -> V_133 ,
F_197 ( & V_132 ) ) ;
V_65 += V_117 ;
V_271 = & V_65 -> V_114 ;
V_109 = F_196 ( * V_271 , F_197 ( & V_132 ) ) ;
while ( V_109 ) {
if ( V_109 -> V_137 == V_57 ) {
F_77 ( * V_271 , F_196 (
V_109 -> V_115 , F_197 ( & V_132 ) ) ) ;
F_66 ( V_109 ) ;
F_198 ( V_109 , V_272 ) ;
break;
}
V_271 = & V_109 -> V_115 ;
V_109 = F_196 ( V_109 -> V_115 ,
F_197 ( & V_132 ) ) ;
}
F_79 ( & V_132 ) ;
}
static int F_199 ( struct V_55 * V_56 ,
const struct V_153 * V_154 ,
struct V_151 * V_152 ,
T_6 V_57 , T_6 V_79 , T_1 V_86 )
{
struct V_108 * V_109 ;
struct V_50 * V_51 ;
int V_259 ;
struct V_151 * V_273 ;
bool V_274 ;
T_1 V_233 = 0 ;
V_273 = F_82 ( F_200 ( * V_154 ) ) ;
if ( ! V_273 ) {
F_201 ( L_17 ) ;
return - V_188 ;
}
V_259 = F_183 ( V_56 , V_79 , V_57 , V_86 , F_202 ( * V_154 ) ,
V_152 -> V_53 , V_152 , & V_233 ) ;
if ( V_259 < 0 ) {
F_189 ( V_152 -> V_53 , V_152 , V_56 , V_57 ,
V_79 ) ;
goto V_275;
}
V_274 = V_154 -> V_232 && ! V_233 ;
if ( V_273 == V_152 && V_259 && F_106 ( V_273 ) &&
V_56 -> V_80 == F_51 ( V_260 ) &&
( F_87 ( V_273 ) ||
F_88 ( V_273 , V_79 , F_203 ( * V_154 ) ) ) )
F_204 ( V_56 ) -> V_220 |= V_276 ;
if ( V_56 -> V_80 != F_51 ( V_260 ) ) {
if ( V_273 == V_152 &&
F_205 ( V_152 ) == 0 ) {
V_259 = - V_188 ;
goto V_275;
}
}
V_109 = F_157 ( & F_95 ( * V_154 ) , V_57 ) ;
if ( V_274 ) {
if ( V_109 ) {
V_51 = F_60 ( V_109 -> V_110 ) ;
if ( V_51 && V_51 -> V_2 . V_121 &&
F_111 ( V_73 , V_51 -> V_2 . V_121 ) ) {
F_195 ( & F_95 ( * V_154 ) , V_57 ) ;
V_109 = NULL ;
} else {
goto V_277;
}
}
V_51 = F_60 ( F_95 ( * V_154 ) . V_141 ) ;
V_277:
if ( F_171 ( V_51 ) ) {
F_206 ( V_56 , & V_51 -> V_2 ) ;
goto V_183;
}
}
V_51 = F_176 ( V_273 -> V_53 , 0 , V_154 -> type ,
F_184 ( V_152 , V_264 ) ,
F_184 ( V_273 , V_278 ) , V_274 ) ;
if ( ! V_51 ) {
V_259 = - V_267 ;
goto V_275;
}
V_51 -> V_249 = 1 ;
if ( V_154 -> V_279 )
V_51 -> V_251 = V_154 -> V_279 -> V_280 ;
F_187 ( V_17 ) ;
V_51 -> V_2 . V_255 = V_281 ;
F_172 ( V_51 , V_57 , V_154 , V_109 , V_154 -> V_232 , V_154 -> type , V_233 ) ;
if ( F_207 ( V_51 -> V_2 . V_240 ) ) {
V_51 -> V_2 . V_240 -> V_282 = V_51 -> V_2 . V_252 ;
V_51 -> V_2 . V_252 = V_283 ;
}
if ( F_208 ( V_51 -> V_2 . V_240 ) ) {
V_51 -> V_2 . V_240 -> V_284 = V_51 -> V_2 . V_255 ;
V_51 -> V_2 . V_255 = V_285 ;
}
F_188 ( V_56 , & V_51 -> V_2 ) ;
V_183:
V_259 = 0 ;
V_275:
return V_259 ;
}
static int F_209 ( struct V_55 * V_56 )
{
const struct V_75 * V_286 = F_39 ( V_56 ) ;
struct V_287 V_288 ;
const struct V_287 * V_289 ;
struct V_75 V_290 ;
const struct V_75 * V_291 ;
if ( F_155 ( ( V_286 -> V_292 & F_51 ( V_293 ) ) != 0 ) )
goto V_294;
V_289 = F_210 ( V_56 , V_286 -> V_295 * 4 , sizeof( V_288 ) ,
& V_288 ) ;
if ( ! V_289 )
goto V_294;
if ( V_289 -> type != V_195 &&
V_289 -> type != V_175 &&
V_289 -> type != V_296 &&
V_289 -> type != V_297 ) {
goto V_294;
}
V_291 = F_210 ( V_56 ,
V_286 -> V_295 * 4 + sizeof( V_288 ) ,
sizeof( V_290 ) , & V_290 ) ;
if ( ! V_291 )
goto V_294;
return F_211 ( V_291 -> V_57 , V_291 -> V_79 ) ;
V_294:
return F_211 ( V_286 -> V_79 , V_286 -> V_57 ) ;
}
static int F_212 ( struct V_55 * V_56 ,
struct V_153 * V_154 ,
const struct V_81 * V_82 ,
struct V_151 * V_152 ,
T_6 V_57 , T_6 V_79 , T_1 V_86 )
{
#ifdef F_213
if ( V_154 -> V_232 && V_154 -> V_232 -> V_298 > 1 ) {
int V_299 ;
if ( F_155 ( F_39 ( V_56 ) -> V_80 == V_300 ) )
V_299 = F_209 ( V_56 ) ;
else
V_299 = F_211 ( V_79 , V_57 ) ;
F_214 ( V_154 , V_299 ) ;
}
#endif
return F_199 ( V_56 , V_154 , V_152 , V_57 , V_79 , V_86 ) ;
}
static int F_215 ( struct V_55 * V_56 , T_6 V_57 , T_6 V_79 ,
T_9 V_86 , struct V_58 * V_53 )
{
struct V_153 V_154 ;
struct V_151 * V_152 = F_82 ( V_53 ) ;
struct V_301 * V_302 ;
struct V_81 V_82 ;
unsigned int V_220 = 0 ;
T_1 V_233 = 0 ;
struct V_50 * V_51 ;
int V_259 = - V_188 ;
struct V_37 * V_37 = F_35 ( V_53 ) ;
bool V_274 ;
if ( ! V_152 )
goto V_183;
V_302 = F_216 ( V_56 ) ;
if ( V_302 && ! ( V_302 -> V_303 & V_304 ) )
V_82 . V_305 . V_306 = V_302 -> V_307 . V_306 ;
else
V_82 . V_305 . V_306 = 0 ;
F_217 ( V_56 ) ;
if ( F_84 ( V_79 ) || F_85 ( V_79 ) )
goto V_308;
V_154 . V_232 = NULL ;
V_154 . V_279 = NULL ;
if ( F_85 ( V_57 ) || ( V_79 == 0 && V_57 == 0 ) )
goto V_309;
if ( F_86 ( V_79 ) )
goto V_308;
if ( F_86 ( V_57 ) )
goto V_310;
if ( F_180 ( V_57 ) ) {
if ( ! F_218 ( V_152 , V_37 ) )
goto V_310;
} else if ( F_180 ( V_79 ) ) {
if ( ! F_218 ( V_152 , V_37 ) )
goto V_308;
}
V_82 . V_211 = 0 ;
V_82 . V_212 = F_219 ( V_53 ) ;
V_82 . V_200 = V_56 -> V_88 ;
V_82 . V_210 = V_86 ;
V_82 . V_311 = V_97 ;
V_82 . V_312 = 0 ;
V_82 . V_57 = V_57 ;
V_82 . V_79 = V_79 ;
V_259 = F_94 ( V_37 , & V_82 , & V_154 , 0 ) ;
if ( V_259 != 0 ) {
if ( ! F_116 ( V_152 ) )
V_259 = - V_184 ;
goto V_313;
}
if ( V_154 . type == V_314 )
goto V_309;
if ( V_154 . type == V_315 ) {
V_259 = F_183 ( V_56 , V_79 , V_57 , V_86 ,
0 , V_53 , V_152 , & V_233 ) ;
if ( V_259 < 0 )
goto V_308;
goto V_316;
}
if ( ! F_116 ( V_152 ) ) {
V_259 = - V_184 ;
goto V_313;
}
if ( V_154 . type != V_161 )
goto V_310;
V_259 = F_212 ( V_56 , & V_154 , & V_82 , V_152 , V_57 , V_79 , V_86 ) ;
V_183: return V_259 ;
V_309:
if ( V_56 -> V_80 != F_51 ( V_260 ) )
goto V_261;
if ( ! F_86 ( V_79 ) ) {
V_259 = F_183 ( V_56 , V_79 , 0 , V_86 , 0 , V_53 ,
V_152 , & V_233 ) ;
if ( V_259 < 0 )
goto V_308;
}
V_220 |= V_317 ;
V_154 . type = V_314 ;
F_187 ( V_20 ) ;
V_316:
V_274 = false ;
if ( V_154 . V_232 ) {
if ( ! V_233 ) {
V_51 = F_60 ( F_95 ( V_154 ) . V_141 ) ;
if ( F_171 ( V_51 ) ) {
F_206 ( V_56 , & V_51 -> V_2 ) ;
V_259 = 0 ;
goto V_183;
}
V_274 = true ;
}
}
V_51 = F_176 ( V_37 -> V_230 , V_220 | V_254 , V_154 . type ,
F_184 ( V_152 , V_264 ) , false , V_274 ) ;
if ( ! V_51 )
goto V_265;
V_51 -> V_2 . V_252 = F_144 ;
#ifdef F_28
V_51 -> V_2 . V_214 = V_233 ;
#endif
V_51 -> V_249 = 1 ;
if ( V_154 . V_279 )
V_51 -> V_251 = V_154 . V_279 -> V_280 ;
F_187 ( V_17 ) ;
if ( V_154 . type == V_318 ) {
V_51 -> V_2 . V_255 = F_115 ;
V_51 -> V_2 . error = - V_259 ;
V_51 -> V_124 &= ~ V_254 ;
}
if ( V_274 ) {
if ( F_155 ( ! F_160 ( & F_95 ( V_154 ) , V_51 ) ) ) {
V_51 -> V_2 . V_220 |= V_221 ;
F_162 ( V_51 ) ;
}
}
F_188 ( V_56 , & V_51 -> V_2 ) ;
V_259 = 0 ;
goto V_183;
V_313:
F_187 ( V_19 ) ;
V_154 . type = V_318 ;
V_154 . V_232 = NULL ;
V_154 . V_279 = NULL ;
goto V_316;
V_310:
F_187 ( V_21 ) ;
#ifdef F_98
if ( F_99 ( V_152 ) )
F_112 ( L_18 ,
& V_57 , & V_79 , V_53 -> V_167 ) ;
#endif
V_261:
V_259 = - V_188 ;
goto V_183;
V_265:
V_259 = - V_267 ;
goto V_183;
V_308:
F_189 ( V_53 , V_152 , V_56 , V_57 , V_79 ) ;
goto V_183;
}
int F_220 ( struct V_55 * V_56 , T_6 V_57 , T_6 V_79 ,
T_9 V_86 , struct V_58 * V_53 )
{
int V_154 ;
F_59 () ;
if ( F_84 ( V_57 ) ) {
struct V_151 * V_152 = F_82 ( V_53 ) ;
if ( V_152 ) {
int V_257 = F_221 ( V_152 , V_57 , V_79 ,
F_39 ( V_56 ) -> V_80 ) ;
if ( V_257
#ifdef F_185
||
( ! F_182 ( V_57 ) &&
F_186 ( V_152 ) )
#endif
) {
int V_154 = F_179 ( V_56 , V_57 , V_79 ,
V_86 , V_53 , V_257 ) ;
F_62 () ;
return V_154 ;
}
}
F_62 () ;
return - V_188 ;
}
V_154 = F_215 ( V_56 , V_57 , V_79 , V_86 , V_53 ) ;
F_62 () ;
return V_154 ;
}
static struct V_50 * F_222 ( const struct V_153 * V_154 ,
const struct V_81 * V_82 , int V_319 ,
struct V_58 * V_320 ,
unsigned int V_220 )
{
struct V_231 * V_232 = V_154 -> V_232 ;
struct V_108 * V_109 ;
struct V_151 * V_152 ;
T_12 type = V_154 -> type ;
struct V_50 * V_51 ;
bool V_274 ;
V_152 = F_82 ( V_320 ) ;
if ( ! V_152 )
return F_223 ( - V_188 ) ;
if ( F_224 ( ! F_181 ( V_152 ) ) )
if ( F_180 ( V_82 -> V_79 ) && ! ( V_320 -> V_220 & V_321 ) )
return F_223 ( - V_188 ) ;
if ( F_85 ( V_82 -> V_57 ) )
type = V_314 ;
else if ( F_84 ( V_82 -> V_57 ) )
type = V_263 ;
else if ( F_86 ( V_82 -> V_57 ) )
return F_223 ( - V_188 ) ;
if ( V_320 -> V_220 & V_321 )
V_220 |= V_254 ;
V_274 = true ;
if ( type == V_314 ) {
V_220 |= V_317 | V_254 ;
V_232 = NULL ;
} else if ( type == V_263 ) {
V_220 |= V_258 | V_254 ;
if ( ! F_221 ( V_152 , V_82 -> V_57 , V_82 -> V_79 ,
V_82 -> V_322 ) )
V_220 &= ~ V_254 ;
else
V_274 = false ;
if ( V_232 && V_154 -> V_323 < 4 )
V_232 = NULL ;
}
V_109 = NULL ;
V_274 &= V_232 != NULL ;
if ( V_274 ) {
struct V_50 T_11 * * V_324 ;
struct V_127 * V_128 = & F_95 ( * V_154 ) ;
V_109 = F_157 ( V_128 , V_82 -> V_57 ) ;
if ( V_109 ) {
V_324 = & V_109 -> V_111 ;
V_51 = F_60 ( * V_324 ) ;
if ( V_51 && V_51 -> V_2 . V_121 &&
F_111 ( V_73 , V_51 -> V_2 . V_121 ) ) {
F_195 ( V_128 , V_82 -> V_57 ) ;
V_109 = NULL ;
} else {
goto V_277;
}
}
if ( F_155 ( V_82 -> V_312 &
V_325 &&
! ( V_128 -> V_235 &&
V_128 -> V_236 == V_237 ) ) ) {
V_274 = false ;
goto V_326;
}
V_324 = F_161 ( V_128 -> V_145 ) ;
V_51 = F_60 ( * V_324 ) ;
V_277:
if ( F_171 ( V_51 ) ) {
F_225 ( & V_51 -> V_2 ) ;
return V_51 ;
}
}
V_326:
V_51 = F_176 ( V_320 , V_220 , type ,
F_184 ( V_152 , V_264 ) ,
F_184 ( V_152 , V_278 ) ,
V_274 ) ;
if ( ! V_51 )
return F_223 ( - V_267 ) ;
V_51 -> V_250 = V_319 ? : 0 ;
if ( V_154 -> V_279 )
V_51 -> V_251 = V_154 -> V_279 -> V_280 ;
F_187 ( V_23 ) ;
if ( V_220 & ( V_317 | V_258 ) ) {
if ( V_220 & V_254 &&
! ( V_320 -> V_220 & V_321 ) ) {
V_51 -> V_2 . V_252 = V_327 ;
F_187 ( V_24 ) ;
}
#ifdef F_185
if ( type == V_263 ) {
if ( F_186 ( V_152 ) &&
! F_182 ( V_82 -> V_57 ) ) {
V_51 -> V_2 . V_255 = V_266 ;
V_51 -> V_2 . V_252 = V_327 ;
}
}
#endif
}
F_172 ( V_51 , V_82 -> V_57 , V_154 , V_109 , V_232 , type , 0 ) ;
if ( F_207 ( V_51 -> V_2 . V_240 ) )
V_51 -> V_2 . V_252 = V_283 ;
return V_51 ;
}
struct V_50 * F_226 ( struct V_37 * V_37 , struct V_81 * V_82 ,
int V_328 )
{
struct V_58 * V_320 = NULL ;
T_13 V_86 = F_227 ( V_82 ) ;
unsigned int V_220 = 0 ;
struct V_153 V_154 ;
struct V_50 * V_51 ;
int V_319 ;
int V_259 = - V_186 ;
V_154 . V_214 = 0 ;
V_154 . V_232 = NULL ;
V_154 . V_279 = NULL ;
V_319 = V_82 -> V_211 ;
V_82 -> V_212 = V_329 ;
V_82 -> V_210 = V_86 & V_330 ;
V_82 -> V_311 = ( ( V_86 & V_331 ) ?
V_237 : V_97 ) ;
F_59 () ;
if ( V_82 -> V_79 ) {
V_51 = F_223 ( - V_188 ) ;
if ( F_84 ( V_82 -> V_79 ) ||
F_85 ( V_82 -> V_79 ) ||
F_86 ( V_82 -> V_79 ) )
goto V_183;
if ( V_82 -> V_211 == 0 &&
( F_84 ( V_82 -> V_57 ) ||
F_85 ( V_82 -> V_57 ) ) ) {
V_320 = F_228 ( V_37 , V_82 -> V_79 , false ) ;
if ( ! V_320 )
goto V_183;
V_82 -> V_211 = V_320 -> V_98 ;
goto V_332;
}
if ( ! ( V_82 -> V_312 & V_333 ) ) {
if ( ! F_228 ( V_37 , V_82 -> V_79 , false ) )
goto V_183;
}
}
if ( V_82 -> V_211 ) {
V_320 = F_229 ( V_37 , V_82 -> V_211 ) ;
V_51 = F_223 ( - V_334 ) ;
if ( ! V_320 )
goto V_183;
if ( ! ( V_320 -> V_220 & V_335 ) || ! F_82 ( V_320 ) ) {
V_51 = F_223 ( - V_186 ) ;
goto V_183;
}
if ( F_182 ( V_82 -> V_57 ) ||
F_85 ( V_82 -> V_57 ) ||
V_82 -> V_322 == V_336 ) {
if ( ! V_82 -> V_79 )
V_82 -> V_79 = F_149 ( V_320 , 0 ,
V_237 ) ;
goto V_332;
}
if ( ! V_82 -> V_79 ) {
if ( F_84 ( V_82 -> V_57 ) )
V_82 -> V_79 = F_149 ( V_320 , 0 ,
V_82 -> V_311 ) ;
else if ( ! V_82 -> V_57 )
V_82 -> V_79 = F_149 ( V_320 , 0 ,
V_337 ) ;
}
V_51 = F_230 ( V_320 , V_82 ) ;
if ( V_51 )
goto V_183;
}
if ( ! V_82 -> V_57 ) {
V_82 -> V_57 = V_82 -> V_79 ;
if ( ! V_82 -> V_57 )
V_82 -> V_57 = V_82 -> V_79 = F_231 ( V_338 ) ;
V_320 = V_37 -> V_230 ;
V_82 -> V_211 = V_329 ;
V_154 . type = V_315 ;
V_220 |= V_254 ;
goto V_332;
}
V_259 = F_94 ( V_37 , V_82 , & V_154 , 0 ) ;
if ( V_259 ) {
V_154 . V_232 = NULL ;
V_154 . V_279 = NULL ;
if ( V_82 -> V_211 &&
! F_232 ( V_37 , V_82 -> V_211 ) ) {
if ( V_82 -> V_79 == 0 )
V_82 -> V_79 = F_149 ( V_320 , 0 ,
V_237 ) ;
V_154 . type = V_161 ;
goto V_332;
}
V_51 = F_223 ( V_259 ) ;
goto V_183;
}
if ( V_154 . type == V_315 ) {
if ( ! V_82 -> V_79 ) {
if ( V_154 . V_232 -> V_339 )
V_82 -> V_79 = V_154 . V_232 -> V_339 ;
else
V_82 -> V_79 = V_82 -> V_57 ;
}
V_320 = V_37 -> V_230 ;
V_82 -> V_211 = V_320 -> V_98 ;
V_220 |= V_254 ;
goto V_332;
}
F_233 ( V_37 , & V_154 , V_82 , V_328 ) ;
V_320 = F_200 ( V_154 ) ;
V_82 -> V_211 = V_320 -> V_98 ;
V_332:
V_51 = F_222 ( & V_154 , V_82 , V_319 , V_320 , V_220 ) ;
V_183:
F_62 () ;
return V_51 ;
}
static struct V_1 * F_234 ( struct V_1 * V_2 , T_1 V_206 )
{
return NULL ;
}
static unsigned int F_235 ( const struct V_1 * V_2 )
{
unsigned int V_196 = F_152 ( V_2 , V_197 ) ;
return V_196 ? : V_2 -> V_53 -> V_196 ;
}
static void F_236 ( struct V_1 * V_2 , struct V_83 * V_84 ,
struct V_55 * V_56 , T_1 V_196 )
{
}
static void F_237 ( struct V_1 * V_2 , struct V_83 * V_84 ,
struct V_55 * V_56 )
{
}
static T_1 * F_238 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
return NULL ;
}
struct V_1 * F_239 ( struct V_37 * V_37 , struct V_1 * V_340 )
{
struct V_50 * V_341 = (struct V_50 * ) V_340 ;
struct V_50 * V_60 ;
V_60 = F_177 ( & V_342 , NULL , 1 , V_343 , 0 ) ;
if ( V_60 ) {
struct V_1 * V_202 = & V_60 -> V_2 ;
V_202 -> V_344 = 1 ;
V_202 -> V_255 = V_345 ;
V_202 -> V_252 = V_346 ;
V_202 -> V_53 = V_341 -> V_2 . V_53 ;
if ( V_202 -> V_53 )
F_169 ( V_202 -> V_53 ) ;
V_60 -> V_249 = V_341 -> V_249 ;
V_60 -> V_250 = V_341 -> V_250 ;
V_60 -> V_119 = V_341 -> V_119 ;
V_60 -> V_52 = F_34 ( V_37 ) ;
V_60 -> V_124 = V_341 -> V_124 ;
V_60 -> V_248 = V_341 -> V_248 ;
V_60 -> V_62 = V_341 -> V_62 ;
V_60 -> V_126 = V_341 -> V_126 ;
F_178 ( & V_60 -> V_228 ) ;
F_240 ( V_202 ) ;
}
F_136 ( V_340 ) ;
return V_60 ? & V_60 -> V_2 : F_223 ( - V_32 ) ;
}
struct V_50 * F_134 ( struct V_37 * V_37 , struct V_81 * V_347 ,
const struct V_83 * V_84 )
{
struct V_50 * V_60 = F_126 ( V_37 , V_347 ) ;
if ( F_92 ( V_60 ) )
return V_60 ;
if ( V_347 -> V_322 )
V_60 = (struct V_50 * ) F_241 ( V_37 , & V_60 -> V_2 ,
F_242 ( V_347 ) ,
V_84 , 0 ) ;
return V_60 ;
}
static int F_243 ( struct V_37 * V_37 , T_6 V_2 , T_6 V_28 , T_1 V_348 ,
struct V_81 * V_82 , struct V_55 * V_56 , T_1 V_349 ,
T_1 V_5 , int V_350 , int V_351 , unsigned int V_220 )
{
struct V_50 * V_60 = F_105 ( V_56 ) ;
struct V_352 * V_353 ;
struct V_354 * V_355 ;
unsigned long V_121 = 0 ;
T_1 error ;
T_1 V_356 [ V_357 ] ;
V_355 = F_244 ( V_56 , V_349 , V_5 , V_350 , sizeof( * V_353 ) , V_220 ) ;
if ( ! V_355 )
return - V_358 ;
V_353 = F_245 ( V_355 ) ;
V_353 -> V_359 = V_360 ;
V_353 -> V_361 = 32 ;
V_353 -> V_362 = 0 ;
V_353 -> V_363 = V_82 -> V_210 ;
V_353 -> V_364 = V_348 ;
if ( F_246 ( V_56 , V_365 , V_348 ) )
goto V_366;
V_353 -> V_367 = V_60 -> V_248 ;
V_353 -> V_368 = V_97 ;
V_353 -> V_369 = V_370 ;
V_353 -> V_371 = ( V_60 -> V_124 & ~ 0xFFFF ) | V_372 ;
if ( V_60 -> V_124 & V_373 )
V_353 -> V_371 |= V_374 ;
if ( F_204 ( V_56 ) -> V_220 & V_276 )
V_353 -> V_371 |= V_375 ;
if ( F_247 ( V_56 , V_376 , V_2 ) )
goto V_366;
if ( V_28 ) {
V_353 -> V_362 = 32 ;
if ( F_247 ( V_56 , V_377 , V_28 ) )
goto V_366;
}
if ( V_60 -> V_2 . V_53 &&
F_246 ( V_56 , V_378 , V_60 -> V_2 . V_53 -> V_98 ) )
goto V_366;
#ifdef F_28
if ( V_60 -> V_2 . V_214 &&
F_246 ( V_56 , V_379 , V_60 -> V_2 . V_214 ) )
goto V_366;
#endif
if ( ! F_159 ( V_60 ) &&
V_82 -> V_79 != V_28 ) {
if ( F_247 ( V_56 , V_380 , V_82 -> V_79 ) )
goto V_366;
}
if ( V_60 -> V_126 &&
F_247 ( V_56 , V_381 , V_60 -> V_62 ) )
goto V_366;
V_121 = V_60 -> V_2 . V_121 ;
if ( V_121 ) {
unsigned long V_72 = V_73 ;
if ( F_69 ( V_72 , V_121 ) )
V_121 -= V_72 ;
else
V_121 = 0 ;
}
memcpy ( V_356 , F_248 ( & V_60 -> V_2 ) , sizeof( V_356 ) ) ;
if ( V_60 -> V_119 && V_121 )
V_356 [ V_197 - 1 ] = V_60 -> V_119 ;
if ( F_249 ( V_56 , V_356 ) < 0 )
goto V_366;
if ( V_82 -> V_200 &&
F_246 ( V_56 , V_382 , V_82 -> V_200 ) )
goto V_366;
error = V_60 -> V_2 . error ;
if ( F_159 ( V_60 ) ) {
#ifdef F_185
if ( F_84 ( V_2 ) && ! F_182 ( V_2 ) &&
F_250 ( V_37 , V_383 ) ) {
int V_259 = F_251 ( V_37 , V_56 ,
V_82 -> V_79 , V_82 -> V_57 ,
V_353 , V_351 ) ;
if ( V_259 <= 0 ) {
if ( ! V_351 ) {
if ( V_259 == 0 )
return 0 ;
goto V_366;
} else {
if ( V_259 == - V_358 )
goto V_366;
error = V_259 ;
}
}
} else
#endif
if ( F_246 ( V_56 , V_384 , V_56 -> V_53 -> V_98 ) )
goto V_366;
}
if ( F_252 ( V_56 , & V_60 -> V_2 , 0 , V_121 , error ) < 0 )
goto V_366;
F_253 ( V_56 , V_355 ) ;
return 0 ;
V_366:
F_254 ( V_56 , V_355 ) ;
return - V_358 ;
}
static int F_255 ( struct V_55 * V_385 , struct V_354 * V_355 )
{
struct V_37 * V_37 = F_128 ( V_385 -> V_84 ) ;
struct V_352 * V_386 ;
struct V_387 * V_388 [ V_389 + 1 ] ;
struct V_50 * V_60 = NULL ;
struct V_81 V_82 ;
T_6 V_2 = 0 ;
T_6 V_28 = 0 ;
T_1 V_390 ;
int V_259 ;
int V_88 ;
struct V_55 * V_56 ;
T_1 V_348 = V_391 ;
V_259 = F_256 ( V_355 , sizeof( * V_386 ) , V_388 , V_389 , V_392 ) ;
if ( V_259 < 0 )
goto V_393;
V_386 = F_245 ( V_355 ) ;
V_56 = F_257 ( V_394 , V_31 ) ;
if ( ! V_56 ) {
V_259 = - V_267 ;
goto V_393;
}
F_258 ( V_56 ) ;
F_259 ( V_56 ) ;
F_39 ( V_56 ) -> V_80 = V_300 ;
F_260 ( V_56 , V_395 + sizeof( struct V_75 ) ) ;
V_28 = V_388 [ V_377 ] ? F_261 ( V_388 [ V_377 ] ) : 0 ;
V_2 = V_388 [ V_376 ] ? F_261 ( V_388 [ V_376 ] ) : 0 ;
V_390 = V_388 [ V_384 ] ? F_262 ( V_388 [ V_384 ] ) : 0 ;
V_88 = V_388 [ V_382 ] ? F_262 ( V_388 [ V_382 ] ) : 0 ;
memset ( & V_82 , 0 , sizeof( V_82 ) ) ;
V_82 . V_57 = V_2 ;
V_82 . V_79 = V_28 ;
V_82 . V_210 = V_386 -> V_363 ;
V_82 . V_211 = V_388 [ V_378 ] ? F_262 ( V_388 [ V_378 ] ) : 0 ;
V_82 . V_200 = V_88 ;
if ( F_232 ( V_37 , V_82 . V_211 ) )
V_82 . V_312 = V_396 | V_397 ;
if ( V_390 ) {
struct V_58 * V_53 ;
V_53 = F_263 ( V_37 , V_390 ) ;
if ( ! V_53 ) {
V_259 = - V_334 ;
goto V_398;
}
V_56 -> V_80 = F_51 ( V_260 ) ;
V_56 -> V_53 = V_53 ;
V_56 -> V_88 = V_88 ;
F_264 () ;
V_259 = F_265 ( V_56 , V_2 , V_28 , V_386 -> V_363 , V_53 ) ;
F_266 () ;
V_60 = F_105 ( V_56 ) ;
if ( V_259 == 0 && V_60 -> V_2 . error )
V_259 = - V_60 -> V_2 . error ;
} else {
V_60 = F_267 ( V_37 , & V_82 ) ;
V_259 = 0 ;
if ( F_92 ( V_60 ) )
V_259 = F_268 ( V_60 ) ;
}
if ( V_259 )
goto V_398;
F_188 ( V_56 , & V_60 -> V_2 ) ;
if ( V_386 -> V_371 & V_374 )
V_60 -> V_124 |= V_373 ;
if ( V_386 -> V_371 & V_399 )
V_348 = V_60 -> V_251 ;
V_259 = F_243 ( V_37 , V_2 , V_28 , V_348 , & V_82 , V_56 ,
F_269 ( V_385 ) . V_349 , V_355 -> V_400 ,
V_401 , 0 , 0 ) ;
if ( V_259 < 0 )
goto V_398;
V_259 = F_270 ( V_56 , V_37 , F_269 ( V_385 ) . V_349 ) ;
V_393:
return V_259 ;
V_398:
F_119 ( V_56 ) ;
goto V_393;
}
void F_271 ( struct V_151 * V_152 )
{
F_36 ( F_35 ( V_152 -> V_53 ) ) ;
}
static int F_272 ( struct V_402 * V_403 , int V_404 ,
void T_14 * V_405 ,
T_15 * V_406 , T_2 * V_407 )
{
struct V_37 * V_37 = (struct V_37 * ) V_403 -> V_408 ;
if ( V_404 ) {
F_36 ( V_37 ) ;
F_273 ( V_37 ) ;
return 0 ;
}
return - V_188 ;
}
static T_3 int F_274 ( struct V_37 * V_37 )
{
struct V_402 * V_409 ;
V_409 = V_410 ;
if ( ! F_275 ( V_37 , & V_411 ) ) {
V_409 = F_276 ( V_409 , sizeof( V_410 ) , V_31 ) ;
if ( ! V_409 )
goto V_412;
if ( V_37 -> V_413 != & V_414 )
V_409 [ 0 ] . V_415 = NULL ;
}
V_409 [ 0 ] . V_408 = V_37 ;
V_37 -> V_173 . V_416 = F_277 ( V_37 , L_19 , V_409 ) ;
if ( ! V_37 -> V_173 . V_416 )
goto V_417;
return 0 ;
V_417:
if ( V_409 != V_410 )
F_23 ( V_409 ) ;
V_412:
return - V_32 ;
}
static T_4 void F_278 ( struct V_37 * V_37 )
{
struct V_402 * V_409 ;
V_409 = V_37 -> V_173 . V_416 -> V_418 ;
F_279 ( V_37 -> V_173 . V_416 ) ;
F_280 ( V_409 == V_410 ) ;
F_23 ( V_409 ) ;
}
static T_3 int F_281 ( struct V_37 * V_37 )
{
F_282 ( & V_37 -> V_173 . V_52 , 0 ) ;
F_282 ( & V_37 -> V_139 , 0 ) ;
F_283 ( & V_37 -> V_173 . V_419 ,
sizeof( V_37 -> V_173 . V_419 ) ) ;
return 0 ;
}
static int T_3 F_284 ( struct V_37 * V_37 )
{
struct V_420 * V_421 = F_285 ( sizeof( * V_421 ) , V_31 ) ;
if ( ! V_421 )
return - V_32 ;
F_286 ( V_421 ) ;
V_37 -> V_173 . V_174 = V_421 ;
return 0 ;
}
static void T_4 F_287 ( struct V_37 * V_37 )
{
struct V_420 * V_421 = V_37 -> V_173 . V_174 ;
V_37 -> V_173 . V_174 = NULL ;
F_288 ( V_421 ) ;
F_23 ( V_421 ) ;
}
int T_5 F_289 ( void )
{
int V_422 = 0 ;
int V_12 ;
V_71 = F_285 ( V_69 * sizeof( * V_71 ) , V_31 ) ;
if ( ! V_71 )
F_290 ( L_20 ) ;
F_291 ( V_71 , V_69 * sizeof( * V_71 ) ) ;
V_68 = F_19 ( V_69 , sizeof( * V_68 ) , V_31 ) ;
if ( ! V_68 )
F_290 ( L_21 ) ;
F_20 (cpu) {
struct V_224 * V_225 = & F_12 ( V_226 , V_12 ) ;
F_178 ( & V_225 -> V_229 ) ;
F_292 ( & V_225 -> V_227 ) ;
}
#ifdef F_28
V_27 = F_293 ( 256 * sizeof( struct V_27 ) , F_294 ( struct V_27 ) ) ;
if ( ! V_27 )
F_290 ( L_22 ) ;
#endif
V_16 . V_423 =
F_295 ( L_23 , sizeof( struct V_50 ) , 0 ,
V_424 | V_425 , NULL ) ;
V_342 . V_423 = V_16 . V_423 ;
if ( F_296 ( & V_16 ) < 0 )
F_290 ( L_24 ) ;
if ( F_296 ( & V_342 ) < 0 )
F_290 ( L_25 ) ;
V_16 . V_426 = ~ 0 ;
V_427 = V_428 ;
F_297 () ;
F_298 () ;
if ( F_31 () )
F_299 ( L_26 ) ;
#ifdef F_300
F_301 () ;
F_302 () ;
#endif
F_303 ( V_429 , V_430 , F_255 , NULL , NULL ) ;
#ifdef F_304
F_32 ( & V_431 ) ;
#endif
F_32 ( & V_432 ) ;
F_32 ( & V_433 ) ;
return V_422 ;
}
void T_5 F_305 ( void )
{
F_277 ( & V_411 , L_19 , V_434 ) ;
}
