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
T_1 V_74 , V_75 = 0 ;
if ( V_3 != V_72 && F_44 ( V_67 , V_3 , V_72 ) == V_3 )
V_75 = F_45 ( V_72 - V_3 ) ;
do {
V_3 = ( T_1 ) F_46 ( V_70 ) ;
V_74 = V_3 + V_75 + V_66 ;
} while ( F_47 ( V_70 , V_3 , V_74 ) != V_3 );
return V_74 - V_66 ;
}
void F_48 ( struct V_37 * V_37 , struct V_76 * V_77 , int V_66 )
{
static T_1 T_8 V_78 ;
T_1 V_65 , V_79 ;
F_49 ( & T_8 , sizeof( T_8 ) ) ;
V_65 = F_50 ( ( V_63 T_1 ) V_77 -> V_57 ,
( V_63 T_1 ) V_77 -> V_80 ,
V_77 -> V_81 ^ F_51 ( V_37 ) ,
T_8 ) ;
V_79 = F_42 ( V_65 , V_66 ) ;
V_77 -> V_79 = F_52 ( V_79 ) ;
}
static void F_53 ( struct V_82 * V_83 , const struct V_84 * V_85 ,
const struct V_76 * V_77 ,
int V_86 , T_9 V_87 ,
T_9 V_88 , T_1 V_89 , int V_90 )
{
if ( V_85 ) {
const struct V_91 * V_92 = F_54 ( V_85 ) ;
V_86 = V_85 -> V_93 ;
V_89 = V_85 -> V_94 ;
V_87 = F_55 ( V_85 ) ;
V_88 = V_92 -> V_95 ? V_96 : V_85 -> V_97 ;
}
F_56 ( V_83 , V_86 , V_89 , V_87 ,
V_98 , V_88 ,
V_90 ,
V_77 -> V_57 , V_77 -> V_80 , 0 , 0 ) ;
}
static void F_57 ( struct V_82 * V_83 , const struct V_55 * V_56 ,
const struct V_84 * V_85 )
{
const struct V_76 * V_77 = F_39 ( V_56 ) ;
int V_86 = V_56 -> V_53 -> V_99 ;
T_9 V_87 = F_58 ( V_77 -> V_87 ) ;
T_9 V_88 = V_77 -> V_81 ;
T_1 V_89 = V_56 -> V_89 ;
F_53 ( V_83 , V_85 , V_77 , V_86 , V_87 , V_88 , V_89 , 0 ) ;
}
static void F_59 ( struct V_82 * V_83 , const struct V_84 * V_85 )
{
const struct V_91 * V_92 = F_54 ( V_85 ) ;
const struct V_100 * V_101 ;
T_6 V_57 = V_92 -> V_102 ;
F_60 () ;
V_101 = F_61 ( V_92 -> V_101 ) ;
if ( V_101 && V_101 -> V_103 . V_104 )
V_57 = V_101 -> V_103 . V_105 ;
F_56 ( V_83 , V_85 -> V_93 , V_85 -> V_94 ,
F_55 ( V_85 ) , V_98 ,
V_92 -> V_95 ? V_96 : V_85 -> V_97 ,
F_62 ( V_85 ) ,
V_57 , V_92 -> V_106 , 0 , 0 ) ;
F_63 () ;
}
static void F_64 ( struct V_82 * V_83 , const struct V_84 * V_85 ,
const struct V_55 * V_56 )
{
if ( V_56 )
F_57 ( V_83 , V_56 , V_85 ) ;
else
F_59 ( V_83 , V_85 ) ;
}
static inline void F_65 ( struct V_50 * V_60 )
{
F_66 ( & V_60 -> V_2 . V_107 , V_108 ) ;
}
static void F_67 ( struct V_109 * V_110 )
{
struct V_50 * V_60 ;
V_60 = F_61 ( V_110 -> V_111 ) ;
if ( V_60 ) {
F_68 ( V_110 -> V_111 , NULL ) ;
F_65 ( V_60 ) ;
}
V_60 = F_61 ( V_110 -> V_112 ) ;
if ( V_60 ) {
F_68 ( V_110 -> V_112 , NULL ) ;
F_65 ( V_60 ) ;
}
}
static struct V_109 * F_69 ( struct V_113 * V_65 )
{
struct V_109 * V_110 , * V_114 ;
V_114 = F_61 ( V_65 -> V_115 ) ;
for ( V_110 = F_61 ( V_114 -> V_116 ) ; V_110 ;
V_110 = F_61 ( V_110 -> V_116 ) ) {
if ( F_70 ( V_110 -> V_117 , V_114 -> V_117 ) )
V_114 = V_110 ;
}
F_67 ( V_114 ) ;
return V_114 ;
}
static inline T_1 F_71 ( T_6 V_57 )
{
static T_1 T_10 V_78 ;
T_1 V_118 ;
F_49 ( & T_10 , sizeof( T_10 ) ) ;
V_118 = F_72 ( ( V_63 T_1 ) V_57 , T_10 ) ;
return F_73 ( V_118 , V_119 ) ;
}
static void F_74 ( struct V_50 * V_60 , struct V_109 * V_110 )
{
V_60 -> V_120 = V_110 -> V_121 ;
V_60 -> V_2 . V_122 = V_110 -> V_123 ;
if ( V_110 -> V_124 ) {
V_60 -> V_125 |= V_126 ;
V_60 -> V_62 = V_110 -> V_124 ;
V_60 -> V_127 = 1 ;
}
}
static void F_75 ( struct V_128 * V_129 , T_6 V_57 , T_6 V_130 ,
T_1 V_131 , unsigned long V_122 )
{
struct V_113 * V_65 ;
struct V_109 * V_110 ;
struct V_50 * V_60 ;
unsigned int V_29 ;
int V_132 ;
T_1 V_118 = F_71 ( V_57 ) ;
F_76 ( & V_133 ) ;
V_65 = F_61 ( V_129 -> V_134 ) ;
if ( ! V_65 ) {
V_65 = F_77 ( V_135 * sizeof( * V_65 ) , V_136 ) ;
if ( ! V_65 )
goto V_137;
F_78 ( V_129 -> V_134 , V_65 ) ;
}
V_65 += V_118 ;
V_132 = 0 ;
for ( V_110 = F_61 ( V_65 -> V_115 ) ; V_110 ;
V_110 = F_61 ( V_110 -> V_116 ) ) {
if ( V_110 -> V_138 == V_57 )
break;
V_132 ++ ;
}
if ( V_110 ) {
if ( V_130 )
V_110 -> V_124 = V_130 ;
if ( V_131 ) {
V_110 -> V_121 = V_131 ;
V_110 -> V_123 = F_79 ( 1UL , V_122 ) ;
}
V_60 = F_61 ( V_110 -> V_111 ) ;
if ( V_60 )
F_74 ( V_60 , V_110 ) ;
V_60 = F_61 ( V_110 -> V_112 ) ;
if ( V_60 )
F_74 ( V_60 , V_110 ) ;
} else {
if ( V_132 > V_139 )
V_110 = F_69 ( V_65 ) ;
else {
V_110 = F_77 ( sizeof( * V_110 ) , V_136 ) ;
if ( ! V_110 )
goto V_137;
V_110 -> V_116 = V_65 -> V_115 ;
F_78 ( V_65 -> V_115 , V_110 ) ;
}
V_110 -> V_140 = V_140 ( F_35 ( V_129 -> V_141 ) ) ;
V_110 -> V_138 = V_57 ;
V_110 -> V_124 = V_130 ;
V_110 -> V_121 = V_131 ;
V_110 -> V_123 = V_122 ;
V_60 = F_61 ( V_129 -> V_142 ) ;
if ( V_60 )
V_60 -> V_2 . V_143 = V_144 ;
F_20 (i) {
struct V_50 T_11 * * V_145 ;
V_145 = F_21 ( V_129 -> V_146 , V_29 ) ;
V_60 = F_61 ( * V_145 ) ;
if ( V_60 )
V_60 -> V_2 . V_143 = V_144 ;
}
}
V_110 -> V_117 = V_73 ;
V_137:
F_80 ( & V_133 ) ;
}
static void F_81 ( struct V_50 * V_60 , struct V_55 * V_56 , struct V_82 * V_83 ,
bool V_147 )
{
T_6 V_148 = F_82 ( V_56 ) -> V_149 . V_150 ;
T_6 V_151 = F_39 ( V_56 ) -> V_80 ;
struct V_58 * V_53 = V_56 -> V_53 ;
struct V_152 * V_153 ;
struct V_154 V_155 ;
struct V_54 * V_61 ;
struct V_37 * V_37 ;
switch ( F_82 ( V_56 ) -> V_156 & 7 ) {
case V_157 :
case V_158 :
case V_159 :
case V_160 :
break;
default:
return;
}
if ( V_60 -> V_62 != V_151 )
return;
V_153 = F_83 ( V_53 ) ;
if ( ! V_153 )
return;
V_37 = F_35 ( V_53 ) ;
if ( V_148 == V_151 || ! F_84 ( V_153 ) ||
F_85 ( V_148 ) || F_86 ( V_148 ) ||
F_87 ( V_148 ) )
goto V_161;
if ( ! F_88 ( V_153 ) ) {
if ( ! F_89 ( V_153 , V_148 , V_151 ) )
goto V_161;
if ( F_90 ( V_153 ) && F_91 ( V_148 , V_53 ) )
goto V_161;
} else {
if ( F_92 ( V_37 , V_148 ) != V_162 )
goto V_161;
}
V_61 = F_40 ( V_60 -> V_2 . V_53 , V_148 ) ;
if ( ! V_61 )
V_61 = F_41 ( & V_64 , & V_148 , V_60 -> V_2 . V_53 ) ;
if ( ! F_93 ( V_61 ) ) {
if ( ! ( V_61 -> V_163 & V_164 ) ) {
F_94 ( V_61 , NULL ) ;
} else {
if ( F_95 ( V_37 , V_83 , & V_155 , 0 ) == 0 ) {
struct V_128 * V_129 = & F_96 ( V_155 ) ;
F_75 ( V_129 , V_83 -> V_57 , V_148 ,
0 , V_73 + V_165 ) ;
}
if ( V_147 )
V_60 -> V_2 . V_143 = V_144 ;
F_97 ( V_166 , V_61 ) ;
}
F_98 ( V_61 ) ;
}
return;
V_161:
#ifdef F_99
if ( F_100 ( V_153 ) ) {
const struct V_76 * V_77 = ( const struct V_76 * ) V_56 -> V_167 ;
T_6 V_57 = V_77 -> V_57 ;
T_6 V_80 = V_77 -> V_80 ;
F_101 ( L_10
L_11 ,
& V_151 , V_53 -> V_168 , & V_148 ,
& V_80 , & V_57 ) ;
}
#endif
;
}
static void F_102 ( struct V_1 * V_2 , struct V_84 * V_85 , struct V_55 * V_56 )
{
struct V_50 * V_60 ;
struct V_82 V_83 ;
const struct V_76 * V_77 = ( const struct V_76 * ) V_56 -> V_167 ;
int V_86 = V_56 -> V_53 -> V_99 ;
T_9 V_87 = F_58 ( V_77 -> V_87 ) ;
T_9 V_88 = V_77 -> V_81 ;
T_1 V_89 = V_56 -> V_89 ;
V_60 = (struct V_50 * ) V_2 ;
F_53 ( & V_83 , V_85 , V_77 , V_86 , V_87 , V_88 , V_89 , 0 ) ;
F_81 ( V_60 , V_56 , & V_83 , true ) ;
}
static struct V_1 * F_103 ( struct V_1 * V_2 )
{
struct V_50 * V_60 = (struct V_50 * ) V_2 ;
struct V_1 * V_169 = V_2 ;
if ( V_60 ) {
if ( V_2 -> V_143 > 0 ) {
F_104 ( V_60 ) ;
V_169 = NULL ;
} else if ( ( V_60 -> V_125 & V_126 ) ||
V_60 -> V_2 . V_122 ) {
F_104 ( V_60 ) ;
V_169 = NULL ;
}
}
return V_169 ;
}
void F_105 ( struct V_55 * V_56 )
{
struct V_50 * V_60 = F_106 ( V_56 ) ;
struct V_152 * V_153 ;
struct V_170 * V_171 ;
struct V_37 * V_37 ;
int V_172 ;
int V_173 ;
F_60 () ;
V_153 = F_83 ( V_60 -> V_2 . V_53 ) ;
if ( ! V_153 || ! F_107 ( V_153 ) ) {
F_63 () ;
return;
}
V_172 = F_100 ( V_153 ) ;
V_173 = F_108 ( V_60 -> V_2 . V_53 ) ;
F_63 () ;
V_37 = F_35 ( V_60 -> V_2 . V_53 ) ;
V_171 = F_109 ( V_37 -> V_174 . V_175 , F_39 ( V_56 ) -> V_80 , V_173 , 1 ) ;
if ( ! V_171 ) {
F_110 ( V_56 , V_176 , V_159 ,
F_111 ( V_60 , F_39 ( V_56 ) -> V_57 ) ) ;
return;
}
if ( F_112 ( V_73 , V_171 -> V_177 + V_178 ) )
V_171 -> V_179 = 0 ;
if ( V_171 -> V_179 >= V_180 ) {
V_171 -> V_177 = V_73 ;
goto V_181;
}
if ( V_171 -> V_179 == 0 ||
F_112 ( V_73 ,
( V_171 -> V_177 +
( V_182 << V_171 -> V_179 ) ) ) ) {
T_6 V_130 = F_111 ( V_60 , F_39 ( V_56 ) -> V_57 ) ;
F_110 ( V_56 , V_176 , V_159 , V_130 ) ;
V_171 -> V_177 = V_73 ;
++ V_171 -> V_179 ;
#ifdef F_99
if ( V_172 &&
V_171 -> V_179 == V_180 )
F_113 ( L_12 ,
& F_39 ( V_56 ) -> V_80 , F_114 ( V_56 ) ,
& F_39 ( V_56 ) -> V_57 , & V_130 ) ;
#endif
}
V_181:
F_115 ( V_171 ) ;
}
static int F_116 ( struct V_55 * V_56 )
{
struct V_152 * V_153 = F_83 ( V_56 -> V_53 ) ;
struct V_50 * V_60 = F_106 ( V_56 ) ;
struct V_170 * V_171 ;
unsigned long V_72 ;
struct V_37 * V_37 ;
bool V_183 ;
int V_156 ;
if ( ! V_153 )
goto V_184;
V_37 = F_35 ( V_60 -> V_2 . V_53 ) ;
if ( ! F_117 ( V_153 ) ) {
switch ( V_60 -> V_2 . error ) {
case V_185 :
F_118 ( V_37 , V_186 ) ;
break;
case V_187 :
F_118 ( V_37 , V_188 ) ;
break;
}
goto V_184;
}
switch ( V_60 -> V_2 . error ) {
case V_189 :
default:
goto V_184;
case V_185 :
V_156 = V_190 ;
break;
case V_187 :
V_156 = V_191 ;
F_118 ( V_37 , V_188 ) ;
break;
case V_192 :
V_156 = V_193 ;
break;
}
V_171 = F_109 ( V_37 -> V_174 . V_175 , F_39 ( V_56 ) -> V_80 ,
F_119 ( V_56 -> V_53 ) , 1 ) ;
V_183 = true ;
if ( V_171 ) {
V_72 = V_73 ;
V_171 -> V_179 += V_72 - V_171 -> V_177 ;
if ( V_171 -> V_179 > V_194 )
V_171 -> V_179 = V_194 ;
V_171 -> V_177 = V_72 ;
if ( V_171 -> V_179 >= V_195 )
V_171 -> V_179 -= V_195 ;
else
V_183 = false ;
F_115 ( V_171 ) ;
}
if ( V_183 )
F_110 ( V_56 , V_196 , V_156 , 0 ) ;
V_184: F_120 ( V_56 ) ;
return 0 ;
}
static void F_121 ( struct V_50 * V_60 , struct V_82 * V_83 , T_1 V_197 )
{
struct V_1 * V_2 = & V_60 -> V_2 ;
struct V_154 V_155 ;
if ( F_122 ( V_2 , V_198 ) )
return;
if ( F_123 ( V_2 ) < V_197 )
return;
if ( V_197 < V_199 )
V_197 = V_199 ;
if ( V_60 -> V_120 == V_197 &&
F_70 ( V_73 , V_2 -> V_122 - V_200 / 2 ) )
return;
F_60 () ;
if ( F_95 ( F_35 ( V_2 -> V_53 ) , V_83 , & V_155 , 0 ) == 0 ) {
struct V_128 * V_129 = & F_96 ( V_155 ) ;
F_75 ( V_129 , V_83 -> V_57 , 0 , V_197 ,
V_73 + V_200 ) ;
}
F_63 () ;
}
static void F_124 ( struct V_1 * V_2 , struct V_84 * V_85 ,
struct V_55 * V_56 , T_1 V_197 )
{
struct V_50 * V_60 = (struct V_50 * ) V_2 ;
struct V_82 V_83 ;
F_64 ( & V_83 , V_85 , V_56 ) ;
F_121 ( V_60 , & V_83 , V_197 ) ;
}
void F_125 ( struct V_55 * V_56 , struct V_37 * V_37 , T_1 V_197 ,
int V_86 , T_1 V_89 , T_9 V_81 , int V_90 )
{
const struct V_76 * V_77 = ( const struct V_76 * ) V_56 -> V_167 ;
struct V_82 V_83 ;
struct V_50 * V_60 ;
if ( ! V_89 )
V_89 = F_126 ( V_37 , V_56 -> V_89 ) ;
F_53 ( & V_83 , NULL , V_77 , V_86 ,
F_58 ( V_77 -> V_87 ) , V_81 , V_89 , V_90 ) ;
V_60 = F_127 ( V_37 , & V_83 ) ;
if ( ! F_93 ( V_60 ) ) {
F_121 ( V_60 , & V_83 , V_197 ) ;
F_104 ( V_60 ) ;
}
}
static void F_128 ( struct V_55 * V_56 , struct V_84 * V_85 , T_1 V_197 )
{
const struct V_76 * V_77 = ( const struct V_76 * ) V_56 -> V_167 ;
struct V_82 V_83 ;
struct V_50 * V_60 ;
F_53 ( & V_83 , V_85 , V_77 , 0 , 0 , 0 , 0 , 0 ) ;
if ( ! V_83 . V_201 )
V_83 . V_201 = F_126 ( F_129 ( V_85 ) , V_56 -> V_89 ) ;
V_60 = F_127 ( F_129 ( V_85 ) , & V_83 ) ;
if ( ! F_93 ( V_60 ) ) {
F_121 ( V_60 , & V_83 , V_197 ) ;
F_104 ( V_60 ) ;
}
}
void F_130 ( struct V_55 * V_56 , struct V_84 * V_85 , T_1 V_197 )
{
const struct V_76 * V_77 = ( const struct V_76 * ) V_56 -> V_167 ;
struct V_82 V_83 ;
struct V_50 * V_60 ;
struct V_1 * V_202 = NULL ;
bool V_74 = false ;
F_131 ( V_85 ) ;
if ( ! F_132 ( V_85 ) )
goto V_184;
V_202 = F_133 ( V_85 ) ;
if ( F_134 ( V_85 ) || ! V_202 ) {
F_128 ( V_56 , V_85 , V_197 ) ;
goto V_184;
}
F_53 ( & V_83 , V_85 , V_77 , 0 , 0 , 0 , 0 , 0 ) ;
V_60 = (struct V_50 * ) V_202 ;
if ( V_202 -> V_143 && ! V_202 -> V_203 -> V_204 ( V_202 , 0 ) ) {
V_60 = F_135 ( F_129 ( V_85 ) , & V_83 , V_85 ) ;
if ( F_93 ( V_60 ) )
goto V_184;
V_74 = true ;
}
F_121 ( (struct V_50 * ) V_60 -> V_2 . V_205 , & V_83 , V_197 ) ;
if ( ! F_136 ( & V_60 -> V_2 , 0 ) ) {
if ( V_74 )
F_137 ( & V_60 -> V_2 ) ;
V_60 = F_135 ( F_129 ( V_85 ) , & V_83 , V_85 ) ;
if ( F_93 ( V_60 ) )
goto V_184;
V_74 = true ;
}
if ( V_74 )
F_138 ( V_85 , & V_60 -> V_2 ) ;
V_184:
F_139 ( V_85 ) ;
F_137 ( V_202 ) ;
}
void F_140 ( struct V_55 * V_56 , struct V_37 * V_37 ,
int V_86 , T_1 V_89 , T_9 V_81 , int V_90 )
{
const struct V_76 * V_77 = ( const struct V_76 * ) V_56 -> V_167 ;
struct V_82 V_83 ;
struct V_50 * V_60 ;
F_53 ( & V_83 , NULL , V_77 , V_86 ,
F_58 ( V_77 -> V_87 ) , V_81 , V_89 , V_90 ) ;
V_60 = F_127 ( V_37 , & V_83 ) ;
if ( ! F_93 ( V_60 ) ) {
F_81 ( V_60 , V_56 , & V_83 , false ) ;
F_104 ( V_60 ) ;
}
}
void F_141 ( struct V_55 * V_56 , struct V_84 * V_85 )
{
const struct V_76 * V_77 = ( const struct V_76 * ) V_56 -> V_167 ;
struct V_82 V_83 ;
struct V_50 * V_60 ;
F_53 ( & V_83 , V_85 , V_77 , 0 , 0 , 0 , 0 , 0 ) ;
V_60 = F_127 ( F_129 ( V_85 ) , & V_83 ) ;
if ( ! F_93 ( V_60 ) ) {
F_81 ( V_60 , V_56 , & V_83 , false ) ;
F_104 ( V_60 ) ;
}
}
static struct V_1 * F_142 ( struct V_1 * V_2 , T_1 V_206 )
{
struct V_50 * V_60 = (struct V_50 * ) V_2 ;
if ( V_2 -> V_143 != V_207 || F_33 ( V_60 ) )
return NULL ;
return V_2 ;
}
static void F_143 ( struct V_55 * V_56 )
{
struct V_50 * V_60 ;
F_110 ( V_56 , V_196 , V_190 , 0 ) ;
V_60 = F_106 ( V_56 ) ;
if ( V_60 )
F_144 ( & V_60 -> V_2 , 0 ) ;
}
static int F_145 ( struct V_37 * V_37 , struct V_84 * V_85 , struct V_55 * V_56 )
{
F_146 ( L_13 ,
V_208 , & F_39 ( V_56 ) -> V_80 , & F_39 ( V_56 ) -> V_57 ,
V_56 -> V_53 ? V_56 -> V_53 -> V_168 : L_14 ) ;
F_120 ( V_56 ) ;
F_2 ( 1 ) ;
return 0 ;
}
void F_147 ( T_9 * V_209 , struct V_55 * V_56 , struct V_50 * V_60 )
{
T_6 V_28 ;
if ( F_148 ( V_60 ) )
V_28 = F_39 ( V_56 ) -> V_80 ;
else {
struct V_154 V_155 ;
struct V_82 V_83 ;
struct V_76 * V_77 ;
V_77 = F_39 ( V_56 ) ;
memset ( & V_83 , 0 , sizeof( V_83 ) ) ;
V_83 . V_57 = V_77 -> V_57 ;
V_83 . V_80 = V_77 -> V_80 ;
V_83 . V_210 = F_58 ( V_77 -> V_87 ) ;
V_83 . V_211 = V_60 -> V_2 . V_53 -> V_99 ;
V_83 . V_212 = V_56 -> V_53 -> V_99 ;
V_83 . V_201 = V_56 -> V_89 ;
F_60 () ;
if ( F_95 ( F_35 ( V_60 -> V_2 . V_53 ) , & V_83 , & V_155 , 0 ) == 0 )
V_28 = F_149 ( F_35 ( V_60 -> V_2 . V_53 ) , V_155 ) ;
else
V_28 = F_150 ( V_60 -> V_2 . V_53 ,
F_111 ( V_60 , V_77 -> V_57 ) ,
V_98 ) ;
F_63 () ;
}
memcpy ( V_209 , & V_28 , 4 ) ;
}
static void F_151 ( struct V_50 * V_60 , T_1 V_213 )
{
if ( ! ( V_60 -> V_2 . V_214 & 0xFFFF ) )
V_60 -> V_2 . V_214 |= V_213 & 0xFFFF ;
if ( ! ( V_60 -> V_2 . V_214 & 0xFFFF0000 ) )
V_60 -> V_2 . V_214 |= V_213 & 0xFFFF0000 ;
}
static unsigned int F_152 ( const struct V_1 * V_2 )
{
unsigned int V_215 = F_153 ( V_2 , V_216 ) ;
if ( V_215 == 0 ) {
V_215 = F_154 (unsigned int, dst->dev->mtu - 40 ,
ip_rt_min_advmss) ;
if ( V_215 > 65535 - 40 )
V_215 = 65535 - 40 ;
}
return V_215 ;
}
static unsigned int F_123 ( const struct V_1 * V_2 )
{
const struct V_50 * V_60 = ( const struct V_50 * ) V_2 ;
unsigned int V_197 = V_60 -> V_120 ;
if ( ! V_197 || F_155 ( V_73 , V_60 -> V_2 . V_122 ) )
V_197 = F_153 ( V_2 , V_198 ) ;
if ( V_197 )
return V_197 ;
V_197 = V_2 -> V_53 -> V_197 ;
if ( F_156 ( F_122 ( V_2 , V_198 ) ) ) {
if ( V_60 -> V_127 && V_197 > 576 )
V_197 = 576 ;
}
V_197 = F_157 (unsigned int, mtu, IP_MAX_MTU) ;
return V_197 - F_158 ( V_2 -> V_217 , V_197 ) ;
}
static struct V_109 * F_159 ( struct V_128 * V_129 , T_6 V_57 )
{
struct V_113 * V_65 = F_61 ( V_129 -> V_134 ) ;
struct V_109 * V_110 ;
T_1 V_118 ;
if ( ! V_65 )
return NULL ;
V_118 = F_71 ( V_57 ) ;
for ( V_110 = F_61 ( V_65 [ V_118 ] . V_115 ) ; V_110 ;
V_110 = F_61 ( V_110 -> V_116 ) ) {
if ( V_110 -> V_138 == V_57 )
return V_110 ;
}
return NULL ;
}
static bool F_160 ( struct V_50 * V_60 , struct V_109 * V_110 ,
T_6 V_57 )
{
bool V_169 = false ;
F_76 ( & V_133 ) ;
if ( V_57 == V_110 -> V_138 ) {
struct V_50 T_11 * * V_218 ;
struct V_50 * V_219 ;
int V_220 = V_140 ( F_35 ( V_60 -> V_2 . V_53 ) ) ;
if ( F_161 ( V_60 ) )
V_218 = & V_110 -> V_111 ;
else
V_218 = & V_110 -> V_112 ;
V_219 = F_61 ( * V_218 ) ;
if ( V_110 -> V_140 != V_220 ) {
V_110 -> V_140 = V_220 ;
V_110 -> V_124 = 0 ;
V_110 -> V_121 = 0 ;
V_110 -> V_123 = 0 ;
F_67 ( V_110 ) ;
V_219 = NULL ;
}
F_74 ( V_60 , V_110 ) ;
if ( ! V_60 -> V_62 )
V_60 -> V_62 = V_57 ;
if ( ! ( V_60 -> V_2 . V_221 & V_222 ) ) {
F_78 ( * V_218 , V_60 ) ;
if ( V_219 )
F_65 ( V_219 ) ;
V_169 = true ;
}
V_110 -> V_117 = V_73 ;
}
F_80 ( & V_133 ) ;
return V_169 ;
}
static bool F_162 ( struct V_128 * V_129 , struct V_50 * V_60 )
{
struct V_50 * V_219 , * V_223 , * * V_224 ;
bool V_169 = true ;
if ( F_161 ( V_60 ) ) {
V_224 = (struct V_50 * * ) & V_129 -> V_142 ;
} else {
V_224 = (struct V_50 * * ) F_163 ( V_129 -> V_146 ) ;
}
V_219 = * V_224 ;
V_223 = F_44 ( V_224 , V_219 , V_60 ) ;
if ( V_223 == V_219 ) {
if ( V_219 )
F_65 ( V_219 ) ;
} else
V_169 = false ;
return V_169 ;
}
static void F_164 ( struct V_50 * V_60 )
{
struct V_225 * V_226 = F_163 ( & V_227 ) ;
V_60 -> V_227 = V_226 ;
F_76 ( & V_226 -> V_228 ) ;
F_165 ( & V_60 -> V_229 , & V_226 -> V_230 ) ;
F_80 ( & V_226 -> V_228 ) ;
}
static void F_166 ( struct V_1 * V_2 )
{
struct V_50 * V_60 = (struct V_50 * ) V_2 ;
if ( ! F_167 ( & V_60 -> V_229 ) ) {
struct V_225 * V_226 = V_60 -> V_227 ;
F_76 ( & V_226 -> V_228 ) ;
F_168 ( & V_60 -> V_229 ) ;
F_80 ( & V_226 -> V_228 ) ;
}
}
void F_169 ( struct V_58 * V_53 )
{
struct V_37 * V_37 = F_35 ( V_53 ) ;
struct V_50 * V_60 ;
int V_12 ;
F_20 (cpu) {
struct V_225 * V_226 = & F_12 ( V_227 , V_12 ) ;
F_76 ( & V_226 -> V_228 ) ;
F_170 (rt, &ul->head, rt_uncached) {
if ( V_60 -> V_2 . V_53 != V_53 )
continue;
V_60 -> V_2 . V_53 = V_37 -> V_231 ;
F_171 ( V_60 -> V_2 . V_53 ) ;
F_172 ( V_53 ) ;
}
F_80 ( & V_226 -> V_228 ) ;
}
}
static bool F_173 ( const struct V_50 * V_60 )
{
return V_60 &&
V_60 -> V_2 . V_143 == V_207 &&
! F_33 ( V_60 ) ;
}
static void F_174 ( struct V_50 * V_60 , T_6 V_57 ,
const struct V_154 * V_155 ,
struct V_109 * V_110 ,
struct V_232 * V_233 , T_12 type , T_1 V_234 )
{
bool V_235 = false ;
if ( V_233 ) {
struct V_128 * V_129 = & F_96 ( * V_155 ) ;
if ( V_129 -> V_236 && V_129 -> V_237 == V_238 ) {
V_60 -> V_62 = V_129 -> V_236 ;
V_60 -> V_127 = 1 ;
}
F_175 ( & V_60 -> V_2 , V_233 -> V_239 , true ) ;
#ifdef F_28
V_60 -> V_2 . V_214 = V_129 -> V_240 ;
#endif
V_60 -> V_2 . V_217 = F_176 ( V_129 -> V_241 ) ;
if ( F_156 ( V_110 ) )
V_235 = F_160 ( V_60 , V_110 , V_57 ) ;
else if ( ! ( V_60 -> V_2 . V_221 & V_222 ) )
V_235 = F_162 ( V_129 , V_60 ) ;
if ( F_156 ( ! V_235 ) ) {
V_60 -> V_2 . V_221 |= V_222 ;
if ( ! V_60 -> V_62 )
V_60 -> V_62 = V_57 ;
F_164 ( V_60 ) ;
}
} else
F_164 ( V_60 ) ;
#ifdef F_28
#ifdef F_177
F_151 ( V_60 , V_155 -> V_214 ) ;
#endif
F_151 ( V_60 , V_234 ) ;
#endif
}
struct V_50 * F_178 ( struct V_58 * V_53 ,
unsigned int V_221 , T_12 type ,
bool V_242 , bool V_243 , bool V_244 )
{
struct V_50 * V_60 ;
V_60 = F_179 ( & V_16 , V_53 , 1 , V_207 ,
( V_244 ? 0 : ( V_245 | V_222 ) ) |
( V_242 ? V_246 : 0 ) |
( V_243 ? V_247 : 0 ) ) ;
if ( V_60 ) {
V_60 -> V_52 = F_34 ( F_35 ( V_53 ) ) ;
V_60 -> V_125 = V_221 ;
V_60 -> V_248 = type ;
V_60 -> V_249 = 0 ;
V_60 -> V_250 = 0 ;
V_60 -> V_120 = 0 ;
V_60 -> V_62 = 0 ;
V_60 -> V_127 = 0 ;
V_60 -> V_251 = 0 ;
F_180 ( & V_60 -> V_229 ) ;
V_60 -> V_2 . V_252 = V_253 ;
if ( V_221 & V_254 )
V_60 -> V_2 . V_255 = V_256 ;
}
return V_60 ;
}
static int F_181 ( struct V_55 * V_56 , T_6 V_57 , T_6 V_80 ,
T_9 V_87 , struct V_58 * V_53 , int V_257 )
{
struct V_50 * V_51 ;
struct V_152 * V_153 = F_83 ( V_53 ) ;
unsigned int V_221 = V_258 ;
T_1 V_234 = 0 ;
int V_259 ;
if ( ! V_153 )
return - V_189 ;
if ( F_85 ( V_80 ) || F_86 ( V_80 ) ||
V_56 -> V_81 != F_52 ( V_260 ) )
goto V_261;
if ( F_182 ( V_80 ) && ! F_183 ( V_153 ) )
goto V_261;
if ( F_87 ( V_80 ) ) {
if ( ! F_184 ( V_57 ) )
goto V_261;
} else {
V_259 = F_185 ( V_56 , V_80 , 0 , V_87 , 0 , V_53 ,
V_153 , & V_234 ) ;
if ( V_259 < 0 )
goto V_262;
}
if ( V_257 )
V_221 |= V_254 ;
V_51 = F_178 ( F_35 ( V_53 ) -> V_231 , V_221 , V_263 ,
F_186 ( V_153 , V_264 ) , false , false ) ;
if ( ! V_51 )
goto V_265;
#ifdef F_28
V_51 -> V_2 . V_214 = V_234 ;
#endif
V_51 -> V_2 . V_252 = F_145 ;
V_51 -> V_249 = 1 ;
#ifdef F_187
if ( ! F_184 ( V_57 ) && F_188 ( V_153 ) )
V_51 -> V_2 . V_255 = V_266 ;
#endif
F_189 ( V_18 ) ;
F_190 ( V_56 , & V_51 -> V_2 ) ;
return 0 ;
V_265:
return - V_267 ;
V_261:
return - V_189 ;
V_262:
return V_259 ;
}
static void F_191 ( struct V_58 * V_53 ,
struct V_152 * V_153 ,
struct V_55 * V_56 ,
T_6 V_57 ,
T_6 V_80 )
{
F_189 ( V_22 ) ;
#ifdef F_99
if ( F_100 ( V_153 ) && F_192 () ) {
F_193 ( L_15 ,
& V_57 , & V_80 , V_53 -> V_168 ) ;
if ( V_53 -> V_268 && F_194 ( V_56 ) ) {
F_195 ( V_269 , L_16 ,
V_270 , 16 , 1 ,
F_196 ( V_56 ) ,
V_53 -> V_268 , true ) ;
}
}
#endif
}
static void F_197 ( struct V_128 * V_129 , T_6 V_57 )
{
struct V_113 * V_65 ;
struct V_109 * V_110 , T_11 * * V_271 ;
T_1 V_118 = F_71 ( V_57 ) ;
F_76 ( & V_133 ) ;
V_65 = F_198 ( V_129 -> V_134 ,
F_199 ( & V_133 ) ) ;
V_65 += V_118 ;
V_271 = & V_65 -> V_115 ;
V_110 = F_198 ( * V_271 , F_199 ( & V_133 ) ) ;
while ( V_110 ) {
if ( V_110 -> V_138 == V_57 ) {
F_78 ( * V_271 , F_198 (
V_110 -> V_116 , F_199 ( & V_133 ) ) ) ;
F_67 ( V_110 ) ;
F_200 ( V_110 , V_272 ) ;
break;
}
V_271 = & V_110 -> V_116 ;
V_110 = F_198 ( V_110 -> V_116 ,
F_199 ( & V_133 ) ) ;
}
F_80 ( & V_133 ) ;
}
static int F_201 ( struct V_55 * V_56 ,
const struct V_154 * V_155 ,
struct V_152 * V_153 ,
T_6 V_57 , T_6 V_80 , T_1 V_87 )
{
struct V_109 * V_110 ;
struct V_50 * V_51 ;
int V_259 ;
struct V_152 * V_273 ;
bool V_274 ;
T_1 V_234 = 0 ;
V_273 = F_83 ( F_202 ( * V_155 ) ) ;
if ( ! V_273 ) {
F_203 ( L_17 ) ;
return - V_189 ;
}
V_259 = F_185 ( V_56 , V_80 , V_57 , V_87 , F_204 ( * V_155 ) ,
V_153 -> V_53 , V_153 , & V_234 ) ;
if ( V_259 < 0 ) {
F_191 ( V_153 -> V_53 , V_153 , V_56 , V_57 ,
V_80 ) ;
goto V_275;
}
V_274 = V_155 -> V_233 && ! V_234 ;
if ( V_273 == V_153 && V_259 && F_107 ( V_273 ) &&
V_56 -> V_81 == F_52 ( V_260 ) &&
( F_88 ( V_273 ) ||
F_89 ( V_273 , V_80 , F_205 ( * V_155 ) ) ) )
F_206 ( V_56 ) -> V_221 |= V_276 ;
if ( V_56 -> V_81 != F_52 ( V_260 ) ) {
if ( V_273 == V_153 &&
F_207 ( V_153 ) == 0 ) {
V_259 = - V_189 ;
goto V_275;
}
}
V_110 = F_159 ( & F_96 ( * V_155 ) , V_57 ) ;
if ( V_274 ) {
if ( V_110 ) {
V_51 = F_61 ( V_110 -> V_111 ) ;
if ( V_51 && V_51 -> V_2 . V_122 &&
F_112 ( V_73 , V_51 -> V_2 . V_122 ) ) {
F_197 ( & F_96 ( * V_155 ) , V_57 ) ;
V_110 = NULL ;
} else {
goto V_277;
}
}
V_51 = F_61 ( F_96 ( * V_155 ) . V_142 ) ;
V_277:
if ( F_173 ( V_51 ) ) {
F_208 ( V_56 , & V_51 -> V_2 ) ;
goto V_184;
}
}
V_51 = F_178 ( V_273 -> V_53 , 0 , V_155 -> type ,
F_186 ( V_153 , V_264 ) ,
F_186 ( V_273 , V_278 ) , V_274 ) ;
if ( ! V_51 ) {
V_259 = - V_267 ;
goto V_275;
}
V_51 -> V_249 = 1 ;
if ( V_155 -> V_279 )
V_51 -> V_251 = V_155 -> V_279 -> V_280 ;
F_189 ( V_17 ) ;
V_51 -> V_2 . V_255 = V_281 ;
F_174 ( V_51 , V_57 , V_155 , V_110 , V_155 -> V_233 , V_155 -> type , V_234 ) ;
if ( F_209 ( V_51 -> V_2 . V_217 ) ) {
V_51 -> V_2 . V_217 -> V_282 = V_51 -> V_2 . V_252 ;
V_51 -> V_2 . V_252 = V_283 ;
}
if ( F_210 ( V_51 -> V_2 . V_217 ) ) {
V_51 -> V_2 . V_217 -> V_284 = V_51 -> V_2 . V_255 ;
V_51 -> V_2 . V_255 = V_285 ;
}
F_190 ( V_56 , & V_51 -> V_2 ) ;
V_184:
V_259 = 0 ;
V_275:
return V_259 ;
}
static int F_211 ( struct V_55 * V_56 )
{
const struct V_76 * V_286 = F_39 ( V_56 ) ;
struct V_287 V_288 ;
const struct V_287 * V_289 ;
struct V_76 V_290 ;
const struct V_76 * V_291 ;
if ( F_156 ( ( V_286 -> V_292 & F_52 ( V_293 ) ) != 0 ) )
goto V_294;
V_289 = F_212 ( V_56 , V_286 -> V_295 * 4 , sizeof( V_288 ) ,
& V_288 ) ;
if ( ! V_289 )
goto V_294;
if ( V_289 -> type != V_196 &&
V_289 -> type != V_176 &&
V_289 -> type != V_296 &&
V_289 -> type != V_297 ) {
goto V_294;
}
V_291 = F_212 ( V_56 ,
V_286 -> V_295 * 4 + sizeof( V_288 ) ,
sizeof( V_290 ) , & V_290 ) ;
if ( ! V_291 )
goto V_294;
return F_213 ( V_291 -> V_57 , V_291 -> V_80 ) ;
V_294:
return F_213 ( V_286 -> V_80 , V_286 -> V_57 ) ;
}
static int F_214 ( struct V_55 * V_56 ,
struct V_154 * V_155 ,
const struct V_82 * V_83 ,
struct V_152 * V_153 ,
T_6 V_57 , T_6 V_80 , T_1 V_87 )
{
#ifdef F_215
if ( V_155 -> V_233 && V_155 -> V_233 -> V_298 > 1 ) {
int V_299 ;
if ( F_156 ( F_39 ( V_56 ) -> V_81 == V_300 ) )
V_299 = F_211 ( V_56 ) ;
else
V_299 = F_213 ( V_80 , V_57 ) ;
F_216 ( V_155 , V_299 ) ;
}
#endif
return F_201 ( V_56 , V_155 , V_153 , V_57 , V_80 , V_87 ) ;
}
static int F_217 ( struct V_55 * V_56 , T_6 V_57 , T_6 V_80 ,
T_9 V_87 , struct V_58 * V_53 )
{
struct V_154 V_155 ;
struct V_152 * V_153 = F_83 ( V_53 ) ;
struct V_301 * V_302 ;
struct V_82 V_83 ;
unsigned int V_221 = 0 ;
T_1 V_234 = 0 ;
struct V_50 * V_51 ;
int V_259 = - V_189 ;
struct V_37 * V_37 = F_35 ( V_53 ) ;
bool V_274 ;
if ( ! V_153 )
goto V_184;
V_302 = F_218 ( V_56 ) ;
if ( V_302 && ! ( V_302 -> V_303 & V_304 ) )
V_83 . V_305 . V_306 = V_302 -> V_307 . V_306 ;
else
V_83 . V_305 . V_306 = 0 ;
F_219 ( V_56 ) ;
if ( F_85 ( V_80 ) || F_86 ( V_80 ) )
goto V_308;
V_155 . V_233 = NULL ;
V_155 . V_279 = NULL ;
if ( F_86 ( V_57 ) || ( V_80 == 0 && V_57 == 0 ) )
goto V_309;
if ( F_87 ( V_80 ) )
goto V_308;
if ( F_87 ( V_57 ) )
goto V_310;
if ( F_182 ( V_57 ) ) {
if ( ! F_220 ( V_153 , V_37 ) )
goto V_310;
} else if ( F_182 ( V_80 ) ) {
if ( ! F_220 ( V_153 , V_37 ) )
goto V_308;
}
V_83 . V_211 = 0 ;
V_83 . V_212 = V_53 -> V_99 ;
V_83 . V_201 = V_56 -> V_89 ;
V_83 . V_210 = V_87 ;
V_83 . V_311 = V_98 ;
V_83 . V_312 = 0 ;
V_83 . V_57 = V_57 ;
V_83 . V_80 = V_80 ;
V_259 = F_95 ( V_37 , & V_83 , & V_155 , 0 ) ;
if ( V_259 != 0 ) {
if ( ! F_117 ( V_153 ) )
V_259 = - V_185 ;
goto V_313;
}
if ( V_155 . type == V_314 )
goto V_309;
if ( V_155 . type == V_315 ) {
V_259 = F_185 ( V_56 , V_80 , V_57 , V_87 ,
0 , V_53 , V_153 , & V_234 ) ;
if ( V_259 < 0 )
goto V_308;
goto V_316;
}
if ( ! F_117 ( V_153 ) ) {
V_259 = - V_185 ;
goto V_313;
}
if ( V_155 . type != V_162 )
goto V_310;
V_259 = F_214 ( V_56 , & V_155 , & V_83 , V_153 , V_57 , V_80 , V_87 ) ;
V_184: return V_259 ;
V_309:
if ( V_56 -> V_81 != F_52 ( V_260 ) )
goto V_261;
if ( ! F_87 ( V_80 ) ) {
V_259 = F_185 ( V_56 , V_80 , 0 , V_87 , 0 , V_53 ,
V_153 , & V_234 ) ;
if ( V_259 < 0 )
goto V_308;
}
V_221 |= V_317 ;
V_155 . type = V_314 ;
F_189 ( V_20 ) ;
V_316:
V_274 = false ;
if ( V_155 . V_233 ) {
if ( ! V_234 ) {
V_51 = F_61 ( F_96 ( V_155 ) . V_142 ) ;
if ( F_173 ( V_51 ) ) {
F_208 ( V_56 , & V_51 -> V_2 ) ;
V_259 = 0 ;
goto V_184;
}
V_274 = true ;
}
}
V_51 = F_178 ( V_37 -> V_231 , V_221 | V_254 , V_155 . type ,
F_186 ( V_153 , V_264 ) , false , V_274 ) ;
if ( ! V_51 )
goto V_265;
V_51 -> V_2 . V_252 = F_145 ;
#ifdef F_28
V_51 -> V_2 . V_214 = V_234 ;
#endif
V_51 -> V_249 = 1 ;
if ( V_155 . V_279 )
V_51 -> V_251 = V_155 . V_279 -> V_280 ;
F_189 ( V_17 ) ;
if ( V_155 . type == V_318 ) {
V_51 -> V_2 . V_255 = F_116 ;
V_51 -> V_2 . error = - V_259 ;
V_51 -> V_125 &= ~ V_254 ;
}
if ( V_274 ) {
if ( F_156 ( ! F_162 ( & F_96 ( V_155 ) , V_51 ) ) ) {
V_51 -> V_2 . V_221 |= V_222 ;
F_164 ( V_51 ) ;
}
}
F_190 ( V_56 , & V_51 -> V_2 ) ;
V_259 = 0 ;
goto V_184;
V_313:
F_189 ( V_19 ) ;
V_155 . type = V_318 ;
V_155 . V_233 = NULL ;
V_155 . V_279 = NULL ;
goto V_316;
V_310:
F_189 ( V_21 ) ;
#ifdef F_99
if ( F_100 ( V_153 ) )
F_113 ( L_18 ,
& V_57 , & V_80 , V_53 -> V_168 ) ;
#endif
V_261:
V_259 = - V_189 ;
goto V_184;
V_265:
V_259 = - V_267 ;
goto V_184;
V_308:
F_191 ( V_53 , V_153 , V_56 , V_57 , V_80 ) ;
goto V_184;
}
int F_221 ( struct V_55 * V_56 , T_6 V_57 , T_6 V_80 ,
T_9 V_87 , struct V_58 * V_53 )
{
int V_155 ;
F_60 () ;
if ( F_85 ( V_57 ) ) {
struct V_152 * V_153 = F_83 ( V_53 ) ;
if ( V_153 ) {
int V_257 = F_222 ( V_153 , V_57 , V_80 ,
F_39 ( V_56 ) -> V_81 ) ;
if ( V_257
#ifdef F_187
||
( ! F_184 ( V_57 ) &&
F_188 ( V_153 ) )
#endif
) {
int V_155 = F_181 ( V_56 , V_57 , V_80 ,
V_87 , V_53 , V_257 ) ;
F_63 () ;
return V_155 ;
}
}
F_63 () ;
return - V_189 ;
}
V_155 = F_217 ( V_56 , V_57 , V_80 , V_87 , V_53 ) ;
F_63 () ;
return V_155 ;
}
static struct V_50 * F_223 ( const struct V_154 * V_155 ,
const struct V_82 * V_83 , int V_319 ,
struct V_58 * V_320 ,
unsigned int V_221 )
{
struct V_232 * V_233 = V_155 -> V_233 ;
struct V_109 * V_110 ;
struct V_152 * V_153 ;
T_12 type = V_155 -> type ;
struct V_50 * V_51 ;
bool V_274 ;
V_153 = F_83 ( V_320 ) ;
if ( ! V_153 )
return F_224 ( - V_189 ) ;
if ( F_225 ( ! F_183 ( V_153 ) ) )
if ( F_182 ( V_83 -> V_80 ) &&
! ( V_320 -> V_221 & V_321 ) &&
! F_226 ( V_320 ) )
return F_224 ( - V_189 ) ;
if ( F_86 ( V_83 -> V_57 ) )
type = V_314 ;
else if ( F_85 ( V_83 -> V_57 ) )
type = V_263 ;
else if ( F_87 ( V_83 -> V_57 ) )
return F_224 ( - V_189 ) ;
if ( V_320 -> V_221 & V_321 )
V_221 |= V_254 ;
V_274 = true ;
if ( type == V_314 ) {
V_221 |= V_317 | V_254 ;
V_233 = NULL ;
} else if ( type == V_263 ) {
V_221 |= V_258 | V_254 ;
if ( ! F_222 ( V_153 , V_83 -> V_57 , V_83 -> V_80 ,
V_83 -> V_322 ) )
V_221 &= ~ V_254 ;
else
V_274 = false ;
if ( V_233 && V_155 -> V_323 < 4 )
V_233 = NULL ;
} else if ( ( type == V_315 ) && ( V_319 != 0 ) &&
( V_319 != V_320 -> V_99 ) ) {
V_233 = NULL ;
}
V_110 = NULL ;
V_274 &= V_233 != NULL ;
if ( V_274 ) {
struct V_50 T_11 * * V_324 ;
struct V_128 * V_129 = & F_96 ( * V_155 ) ;
V_110 = F_159 ( V_129 , V_83 -> V_57 ) ;
if ( V_110 ) {
V_324 = & V_110 -> V_112 ;
V_51 = F_61 ( * V_324 ) ;
if ( V_51 && V_51 -> V_2 . V_122 &&
F_112 ( V_73 , V_51 -> V_2 . V_122 ) ) {
F_197 ( V_129 , V_83 -> V_57 ) ;
V_110 = NULL ;
} else {
goto V_277;
}
}
if ( F_156 ( V_83 -> V_312 &
V_325 &&
! ( V_129 -> V_236 &&
V_129 -> V_237 == V_238 ) ) ) {
V_274 = false ;
goto V_326;
}
V_324 = F_163 ( V_129 -> V_146 ) ;
V_51 = F_61 ( * V_324 ) ;
V_277:
if ( F_173 ( V_51 ) ) {
F_227 ( & V_51 -> V_2 ) ;
return V_51 ;
}
}
V_326:
V_51 = F_178 ( V_320 , V_221 , type ,
F_186 ( V_153 , V_264 ) ,
F_186 ( V_153 , V_278 ) ,
V_274 ) ;
if ( ! V_51 )
return F_224 ( - V_267 ) ;
V_51 -> V_250 = V_319 ? : 0 ;
if ( V_155 -> V_279 )
V_51 -> V_251 = V_155 -> V_279 -> V_280 ;
F_189 ( V_23 ) ;
if ( V_221 & ( V_317 | V_258 ) ) {
if ( V_221 & V_254 &&
! ( V_320 -> V_221 & V_321 ) ) {
V_51 -> V_2 . V_252 = V_327 ;
F_189 ( V_24 ) ;
}
#ifdef F_187
if ( type == V_263 ) {
if ( F_188 ( V_153 ) &&
! F_184 ( V_83 -> V_57 ) ) {
V_51 -> V_2 . V_255 = V_266 ;
V_51 -> V_2 . V_252 = V_327 ;
}
}
#endif
}
F_174 ( V_51 , V_83 -> V_57 , V_155 , V_110 , V_233 , type , 0 ) ;
if ( F_209 ( V_51 -> V_2 . V_217 ) )
V_51 -> V_2 . V_252 = V_283 ;
return V_51 ;
}
struct V_50 * F_228 ( struct V_37 * V_37 , struct V_82 * V_83 ,
int V_328 )
{
struct V_58 * V_320 = NULL ;
T_13 V_87 = F_229 ( V_83 ) ;
unsigned int V_221 = 0 ;
struct V_154 V_155 ;
struct V_50 * V_51 ;
int V_319 ;
int V_259 = - V_187 ;
V_155 . V_214 = 0 ;
V_155 . V_233 = NULL ;
V_155 . V_279 = NULL ;
V_319 = V_83 -> V_211 ;
V_83 -> V_212 = V_329 ;
V_83 -> V_210 = V_87 & V_330 ;
V_83 -> V_311 = ( ( V_87 & V_331 ) ?
V_238 : V_98 ) ;
F_60 () ;
if ( V_83 -> V_80 ) {
V_51 = F_224 ( - V_189 ) ;
if ( F_85 ( V_83 -> V_80 ) ||
F_86 ( V_83 -> V_80 ) ||
F_87 ( V_83 -> V_80 ) )
goto V_184;
if ( V_83 -> V_211 == 0 &&
( F_85 ( V_83 -> V_57 ) ||
F_86 ( V_83 -> V_57 ) ) ) {
V_320 = F_230 ( V_37 , V_83 -> V_80 , false ) ;
if ( ! V_320 )
goto V_184;
V_83 -> V_211 = V_320 -> V_99 ;
goto V_332;
}
if ( ! ( V_83 -> V_312 & V_333 ) ) {
if ( ! F_230 ( V_37 , V_83 -> V_80 , false ) )
goto V_184;
}
}
if ( V_83 -> V_211 ) {
V_320 = F_231 ( V_37 , V_83 -> V_211 ) ;
V_51 = F_224 ( - V_334 ) ;
if ( ! V_320 )
goto V_184;
if ( ! ( V_320 -> V_221 & V_335 ) || ! F_83 ( V_320 ) ) {
V_51 = F_224 ( - V_187 ) ;
goto V_184;
}
if ( F_184 ( V_83 -> V_57 ) ||
F_86 ( V_83 -> V_57 ) ||
V_83 -> V_322 == V_336 ) {
if ( ! V_83 -> V_80 )
V_83 -> V_80 = F_150 ( V_320 , 0 ,
V_238 ) ;
goto V_332;
}
if ( ! V_83 -> V_80 ) {
if ( F_85 ( V_83 -> V_57 ) )
V_83 -> V_80 = F_150 ( V_320 , 0 ,
V_83 -> V_311 ) ;
else if ( ! V_83 -> V_57 )
V_83 -> V_80 = F_150 ( V_320 , 0 ,
V_337 ) ;
}
}
if ( ! V_83 -> V_57 ) {
V_83 -> V_57 = V_83 -> V_80 ;
if ( ! V_83 -> V_57 )
V_83 -> V_57 = V_83 -> V_80 = F_232 ( V_338 ) ;
V_320 = V_37 -> V_231 ;
V_83 -> V_211 = V_329 ;
V_155 . type = V_315 ;
V_221 |= V_254 ;
goto V_332;
}
V_259 = F_95 ( V_37 , V_83 , & V_155 , 0 ) ;
if ( V_259 ) {
V_155 . V_233 = NULL ;
V_155 . V_279 = NULL ;
if ( V_83 -> V_211 &&
! F_233 ( V_37 , V_83 -> V_211 ) ) {
if ( V_83 -> V_80 == 0 )
V_83 -> V_80 = F_150 ( V_320 , 0 ,
V_238 ) ;
V_155 . type = V_162 ;
goto V_332;
}
V_51 = F_224 ( V_259 ) ;
goto V_184;
}
if ( V_155 . type == V_315 ) {
if ( ! V_83 -> V_80 ) {
if ( V_155 . V_233 -> V_339 )
V_83 -> V_80 = V_155 . V_233 -> V_339 ;
else
V_83 -> V_80 = V_83 -> V_57 ;
}
V_320 = F_234 ( V_320 ) ? : V_37 -> V_231 ;
V_83 -> V_211 = V_320 -> V_99 ;
V_221 |= V_254 ;
goto V_332;
}
F_235 ( V_37 , & V_155 , V_83 , V_328 ) ;
V_320 = F_202 ( V_155 ) ;
V_83 -> V_211 = V_320 -> V_99 ;
V_332:
V_51 = F_223 ( & V_155 , V_83 , V_319 , V_320 , V_221 ) ;
V_184:
F_63 () ;
return V_51 ;
}
static struct V_1 * F_236 ( struct V_1 * V_2 , T_1 V_206 )
{
return NULL ;
}
static unsigned int F_237 ( const struct V_1 * V_2 )
{
unsigned int V_197 = F_153 ( V_2 , V_198 ) ;
return V_197 ? : V_2 -> V_53 -> V_197 ;
}
static void F_238 ( struct V_1 * V_2 , struct V_84 * V_85 ,
struct V_55 * V_56 , T_1 V_197 )
{
}
static void F_239 ( struct V_1 * V_2 , struct V_84 * V_85 ,
struct V_55 * V_56 )
{
}
static T_1 * F_240 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
return NULL ;
}
struct V_1 * F_241 ( struct V_37 * V_37 , struct V_1 * V_340 )
{
struct V_50 * V_341 = (struct V_50 * ) V_340 ;
struct V_50 * V_60 ;
V_60 = F_179 ( & V_342 , NULL , 1 , V_343 , 0 ) ;
if ( V_60 ) {
struct V_1 * V_74 = & V_60 -> V_2 ;
V_74 -> V_344 = 1 ;
V_74 -> V_255 = V_345 ;
V_74 -> V_252 = V_346 ;
V_74 -> V_53 = V_341 -> V_2 . V_53 ;
if ( V_74 -> V_53 )
F_171 ( V_74 -> V_53 ) ;
V_60 -> V_249 = V_341 -> V_249 ;
V_60 -> V_250 = V_341 -> V_250 ;
V_60 -> V_120 = V_341 -> V_120 ;
V_60 -> V_52 = F_34 ( V_37 ) ;
V_60 -> V_125 = V_341 -> V_125 ;
V_60 -> V_248 = V_341 -> V_248 ;
V_60 -> V_62 = V_341 -> V_62 ;
V_60 -> V_127 = V_341 -> V_127 ;
F_180 ( & V_60 -> V_229 ) ;
F_242 ( V_74 ) ;
}
F_137 ( V_340 ) ;
return V_60 ? & V_60 -> V_2 : F_224 ( - V_32 ) ;
}
struct V_50 * F_135 ( struct V_37 * V_37 , struct V_82 * V_347 ,
const struct V_84 * V_85 )
{
struct V_50 * V_60 = F_127 ( V_37 , V_347 ) ;
if ( F_93 ( V_60 ) )
return V_60 ;
if ( V_347 -> V_322 )
V_60 = (struct V_50 * ) F_243 ( V_37 , & V_60 -> V_2 ,
F_244 ( V_347 ) ,
V_85 , 0 ) ;
return V_60 ;
}
static int F_245 ( struct V_37 * V_37 , T_6 V_2 , T_6 V_28 , T_1 V_348 ,
struct V_82 * V_83 , struct V_55 * V_56 , T_1 V_349 ,
T_1 V_5 , int V_350 , int V_351 , unsigned int V_221 )
{
struct V_50 * V_60 = F_106 ( V_56 ) ;
struct V_352 * V_353 ;
struct V_354 * V_355 ;
unsigned long V_122 = 0 ;
T_1 error ;
T_1 V_356 [ V_357 ] ;
V_355 = F_246 ( V_56 , V_349 , V_5 , V_350 , sizeof( * V_353 ) , V_221 ) ;
if ( ! V_355 )
return - V_358 ;
V_353 = F_247 ( V_355 ) ;
V_353 -> V_359 = V_360 ;
V_353 -> V_361 = 32 ;
V_353 -> V_362 = 0 ;
V_353 -> V_363 = V_83 -> V_210 ;
V_353 -> V_364 = V_348 ;
if ( F_248 ( V_56 , V_365 , V_348 ) )
goto V_366;
V_353 -> V_367 = V_60 -> V_248 ;
V_353 -> V_368 = V_98 ;
V_353 -> V_369 = V_370 ;
V_353 -> V_371 = ( V_60 -> V_125 & ~ 0xFFFF ) | V_372 ;
if ( V_60 -> V_125 & V_373 )
V_353 -> V_371 |= V_374 ;
if ( F_206 ( V_56 ) -> V_221 & V_276 )
V_353 -> V_371 |= V_375 ;
if ( F_249 ( V_56 , V_376 , V_2 ) )
goto V_366;
if ( V_28 ) {
V_353 -> V_362 = 32 ;
if ( F_249 ( V_56 , V_377 , V_28 ) )
goto V_366;
}
if ( V_60 -> V_2 . V_53 &&
F_248 ( V_56 , V_378 , V_60 -> V_2 . V_53 -> V_99 ) )
goto V_366;
#ifdef F_28
if ( V_60 -> V_2 . V_214 &&
F_248 ( V_56 , V_379 , V_60 -> V_2 . V_214 ) )
goto V_366;
#endif
if ( ! F_161 ( V_60 ) &&
V_83 -> V_80 != V_28 ) {
if ( F_249 ( V_56 , V_380 , V_83 -> V_80 ) )
goto V_366;
}
if ( V_60 -> V_127 &&
F_249 ( V_56 , V_381 , V_60 -> V_62 ) )
goto V_366;
V_122 = V_60 -> V_2 . V_122 ;
if ( V_122 ) {
unsigned long V_72 = V_73 ;
if ( F_70 ( V_72 , V_122 ) )
V_122 -= V_72 ;
else
V_122 = 0 ;
}
memcpy ( V_356 , F_250 ( & V_60 -> V_2 ) , sizeof( V_356 ) ) ;
if ( V_60 -> V_120 && V_122 )
V_356 [ V_198 - 1 ] = V_60 -> V_120 ;
if ( F_251 ( V_56 , V_356 ) < 0 )
goto V_366;
if ( V_83 -> V_201 &&
F_248 ( V_56 , V_382 , V_83 -> V_201 ) )
goto V_366;
error = V_60 -> V_2 . error ;
if ( F_161 ( V_60 ) ) {
#ifdef F_187
if ( F_85 ( V_2 ) && ! F_184 ( V_2 ) &&
F_252 ( V_37 , V_383 ) ) {
int V_259 = F_253 ( V_37 , V_56 ,
V_83 -> V_80 , V_83 -> V_57 ,
V_353 , V_351 , V_349 ) ;
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
if ( F_248 ( V_56 , V_384 , V_56 -> V_53 -> V_99 ) )
goto V_366;
}
if ( F_254 ( V_56 , & V_60 -> V_2 , 0 , V_122 , error ) < 0 )
goto V_366;
F_255 ( V_56 , V_355 ) ;
return 0 ;
V_366:
F_256 ( V_56 , V_355 ) ;
return - V_358 ;
}
static int F_257 ( struct V_55 * V_385 , struct V_354 * V_355 )
{
struct V_37 * V_37 = F_129 ( V_385 -> V_85 ) ;
struct V_352 * V_386 ;
struct V_387 * V_388 [ V_389 + 1 ] ;
struct V_50 * V_60 = NULL ;
struct V_82 V_83 ;
T_6 V_2 = 0 ;
T_6 V_28 = 0 ;
T_1 V_390 ;
int V_259 ;
int V_89 ;
struct V_55 * V_56 ;
T_1 V_348 = V_391 ;
V_259 = F_258 ( V_355 , sizeof( * V_386 ) , V_388 , V_389 , V_392 ) ;
if ( V_259 < 0 )
goto V_393;
V_386 = F_247 ( V_355 ) ;
V_56 = F_259 ( V_394 , V_31 ) ;
if ( ! V_56 ) {
V_259 = - V_267 ;
goto V_393;
}
F_260 ( V_56 ) ;
F_261 ( V_56 ) ;
F_39 ( V_56 ) -> V_81 = V_300 ;
F_262 ( V_56 , V_395 + sizeof( struct V_76 ) ) ;
V_28 = V_388 [ V_377 ] ? F_263 ( V_388 [ V_377 ] ) : 0 ;
V_2 = V_388 [ V_376 ] ? F_263 ( V_388 [ V_376 ] ) : 0 ;
V_390 = V_388 [ V_384 ] ? F_264 ( V_388 [ V_384 ] ) : 0 ;
V_89 = V_388 [ V_382 ] ? F_264 ( V_388 [ V_382 ] ) : 0 ;
memset ( & V_83 , 0 , sizeof( V_83 ) ) ;
V_83 . V_57 = V_2 ;
V_83 . V_80 = V_28 ;
V_83 . V_210 = V_386 -> V_363 ;
V_83 . V_211 = V_388 [ V_378 ] ? F_264 ( V_388 [ V_378 ] ) : 0 ;
V_83 . V_201 = V_89 ;
if ( V_390 ) {
struct V_58 * V_53 ;
V_53 = F_265 ( V_37 , V_390 ) ;
if ( ! V_53 ) {
V_259 = - V_334 ;
goto V_396;
}
V_56 -> V_81 = F_52 ( V_260 ) ;
V_56 -> V_53 = V_53 ;
V_56 -> V_89 = V_89 ;
F_266 () ;
V_259 = F_267 ( V_56 , V_2 , V_28 , V_386 -> V_363 , V_53 ) ;
F_268 () ;
V_60 = F_106 ( V_56 ) ;
if ( V_259 == 0 && V_60 -> V_2 . error )
V_259 = - V_60 -> V_2 . error ;
} else {
V_60 = F_269 ( V_37 , & V_83 ) ;
V_259 = 0 ;
if ( F_93 ( V_60 ) )
V_259 = F_270 ( V_60 ) ;
}
if ( V_259 )
goto V_396;
F_190 ( V_56 , & V_60 -> V_2 ) ;
if ( V_386 -> V_371 & V_374 )
V_60 -> V_125 |= V_373 ;
if ( V_386 -> V_371 & V_397 )
V_348 = V_60 -> V_251 ;
V_259 = F_245 ( V_37 , V_2 , V_28 , V_348 , & V_83 , V_56 ,
F_271 ( V_385 ) . V_349 , V_355 -> V_398 ,
V_399 , 0 , 0 ) ;
if ( V_259 < 0 )
goto V_396;
V_259 = F_272 ( V_56 , V_37 , F_271 ( V_385 ) . V_349 ) ;
V_393:
return V_259 ;
V_396:
F_120 ( V_56 ) ;
goto V_393;
}
void F_273 ( struct V_152 * V_153 )
{
F_36 ( F_35 ( V_153 -> V_53 ) ) ;
}
static int F_274 ( struct V_400 * V_401 , int V_402 ,
void T_14 * V_403 ,
T_15 * V_404 , T_2 * V_405 )
{
struct V_37 * V_37 = (struct V_37 * ) V_401 -> V_406 ;
if ( V_402 ) {
F_36 ( V_37 ) ;
F_275 ( V_37 ) ;
return 0 ;
}
return - V_189 ;
}
static T_3 int F_276 ( struct V_37 * V_37 )
{
struct V_400 * V_407 ;
V_407 = V_408 ;
if ( ! F_277 ( V_37 , & V_409 ) ) {
V_407 = F_278 ( V_407 , sizeof( V_408 ) , V_31 ) ;
if ( ! V_407 )
goto V_410;
if ( V_37 -> V_411 != & V_412 )
V_407 [ 0 ] . V_413 = NULL ;
}
V_407 [ 0 ] . V_406 = V_37 ;
V_37 -> V_174 . V_414 = F_279 ( V_37 , L_19 , V_407 ) ;
if ( ! V_37 -> V_174 . V_414 )
goto V_415;
return 0 ;
V_415:
if ( V_407 != V_408 )
F_23 ( V_407 ) ;
V_410:
return - V_32 ;
}
static T_4 void F_280 ( struct V_37 * V_37 )
{
struct V_400 * V_407 ;
V_407 = V_37 -> V_174 . V_414 -> V_416 ;
F_281 ( V_37 -> V_174 . V_414 ) ;
F_282 ( V_407 == V_408 ) ;
F_23 ( V_407 ) ;
}
static T_3 int F_283 ( struct V_37 * V_37 )
{
F_284 ( & V_37 -> V_174 . V_52 , 0 ) ;
F_284 ( & V_37 -> V_140 , 0 ) ;
F_285 ( & V_37 -> V_174 . V_417 ,
sizeof( V_37 -> V_174 . V_417 ) ) ;
return 0 ;
}
static int T_3 F_286 ( struct V_37 * V_37 )
{
struct V_418 * V_419 = F_287 ( sizeof( * V_419 ) , V_31 ) ;
if ( ! V_419 )
return - V_32 ;
F_288 ( V_419 ) ;
V_37 -> V_174 . V_175 = V_419 ;
return 0 ;
}
static void T_4 F_289 ( struct V_37 * V_37 )
{
struct V_418 * V_419 = V_37 -> V_174 . V_175 ;
V_37 -> V_174 . V_175 = NULL ;
F_290 ( V_419 ) ;
F_23 ( V_419 ) ;
}
int T_5 F_291 ( void )
{
int V_420 = 0 ;
int V_12 ;
V_71 = F_287 ( V_69 * sizeof( * V_71 ) , V_31 ) ;
if ( ! V_71 )
F_292 ( L_20 ) ;
F_293 ( V_71 , V_69 * sizeof( * V_71 ) ) ;
V_68 = F_19 ( V_69 , sizeof( * V_68 ) , V_31 ) ;
if ( ! V_68 )
F_292 ( L_21 ) ;
F_20 (cpu) {
struct V_225 * V_226 = & F_12 ( V_227 , V_12 ) ;
F_180 ( & V_226 -> V_230 ) ;
F_294 ( & V_226 -> V_228 ) ;
}
#ifdef F_28
V_27 = F_295 ( 256 * sizeof( struct V_27 ) , F_296 ( struct V_27 ) ) ;
if ( ! V_27 )
F_292 ( L_22 ) ;
#endif
V_16 . V_421 =
F_297 ( L_23 , sizeof( struct V_50 ) , 0 ,
V_422 | V_423 , NULL ) ;
V_342 . V_421 = V_16 . V_421 ;
if ( F_298 ( & V_16 ) < 0 )
F_292 ( L_24 ) ;
if ( F_298 ( & V_342 ) < 0 )
F_292 ( L_25 ) ;
V_16 . V_424 = ~ 0 ;
V_425 = V_426 ;
F_299 () ;
F_300 () ;
if ( F_31 () )
F_301 ( L_26 ) ;
#ifdef F_302
F_303 () ;
F_304 () ;
#endif
F_305 ( V_427 , V_428 , F_257 , NULL , NULL ) ;
#ifdef F_306
F_32 ( & V_429 ) ;
#endif
F_32 ( & V_430 ) ;
F_32 ( & V_431 ) ;
return V_420 ;
}
void T_5 F_307 ( void )
{
F_279 ( & V_409 , L_19 , V_432 ) ;
}
