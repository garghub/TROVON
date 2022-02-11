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
V_61 = F_38 ( & V_60 -> V_2 , NULL , & V_148 ) ;
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
return F_157 (unsigned int, mtu, IP_MAX_MTU) ;
}
static struct V_109 * F_158 ( struct V_128 * V_129 , T_6 V_57 )
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
static bool F_159 ( struct V_50 * V_60 , struct V_109 * V_110 ,
T_6 V_57 )
{
bool V_169 = false ;
F_76 ( & V_133 ) ;
if ( V_57 == V_110 -> V_138 ) {
struct V_50 T_11 * * V_217 ;
struct V_50 * V_218 ;
int V_219 = V_140 ( F_35 ( V_60 -> V_2 . V_53 ) ) ;
if ( F_160 ( V_60 ) )
V_217 = & V_110 -> V_111 ;
else
V_217 = & V_110 -> V_112 ;
V_218 = F_61 ( * V_217 ) ;
if ( V_110 -> V_140 != V_219 ) {
V_110 -> V_140 = V_219 ;
V_110 -> V_124 = 0 ;
V_110 -> V_121 = 0 ;
V_110 -> V_123 = 0 ;
F_67 ( V_110 ) ;
V_218 = NULL ;
}
F_74 ( V_60 , V_110 ) ;
if ( ! V_60 -> V_62 )
V_60 -> V_62 = V_57 ;
if ( ! ( V_60 -> V_2 . V_220 & V_221 ) ) {
F_78 ( * V_217 , V_60 ) ;
if ( V_218 )
F_65 ( V_218 ) ;
V_169 = true ;
}
V_110 -> V_117 = V_73 ;
}
F_80 ( & V_133 ) ;
return V_169 ;
}
static bool F_161 ( struct V_128 * V_129 , struct V_50 * V_60 )
{
struct V_50 * V_218 , * V_222 , * * V_223 ;
bool V_169 = true ;
if ( F_160 ( V_60 ) ) {
V_223 = (struct V_50 * * ) & V_129 -> V_142 ;
} else {
V_223 = (struct V_50 * * ) F_162 ( V_129 -> V_146 ) ;
}
V_218 = * V_223 ;
V_222 = F_44 ( V_223 , V_218 , V_60 ) ;
if ( V_222 == V_218 ) {
if ( V_218 )
F_65 ( V_218 ) ;
} else
V_169 = false ;
return V_169 ;
}
static void F_163 ( struct V_50 * V_60 )
{
struct V_224 * V_225 = F_162 ( & V_226 ) ;
V_60 -> V_226 = V_225 ;
F_76 ( & V_225 -> V_227 ) ;
F_164 ( & V_60 -> V_228 , & V_225 -> V_229 ) ;
F_80 ( & V_225 -> V_227 ) ;
}
static void F_165 ( struct V_1 * V_2 )
{
struct V_50 * V_60 = (struct V_50 * ) V_2 ;
if ( ! F_166 ( & V_60 -> V_228 ) ) {
struct V_224 * V_225 = V_60 -> V_226 ;
F_76 ( & V_225 -> V_227 ) ;
F_167 ( & V_60 -> V_228 ) ;
F_80 ( & V_225 -> V_227 ) ;
}
}
void F_168 ( struct V_58 * V_53 )
{
struct V_37 * V_37 = F_35 ( V_53 ) ;
struct V_50 * V_60 ;
int V_12 ;
F_20 (cpu) {
struct V_224 * V_225 = & F_12 ( V_226 , V_12 ) ;
F_76 ( & V_225 -> V_227 ) ;
F_169 (rt, &ul->head, rt_uncached) {
if ( V_60 -> V_2 . V_53 != V_53 )
continue;
V_60 -> V_2 . V_53 = V_37 -> V_230 ;
F_170 ( V_60 -> V_2 . V_53 ) ;
F_171 ( V_53 ) ;
}
F_80 ( & V_225 -> V_227 ) ;
}
}
static bool F_172 ( const struct V_50 * V_60 )
{
return V_60 &&
V_60 -> V_2 . V_143 == V_207 &&
! F_33 ( V_60 ) ;
}
static void F_173 ( struct V_50 * V_60 , T_6 V_57 ,
const struct V_154 * V_155 ,
struct V_109 * V_110 ,
struct V_231 * V_232 , T_12 type , T_1 V_233 )
{
bool V_234 = false ;
if ( V_232 ) {
struct V_128 * V_129 = & F_96 ( * V_155 ) ;
if ( V_129 -> V_235 && V_129 -> V_236 == V_237 ) {
V_60 -> V_62 = V_129 -> V_235 ;
V_60 -> V_127 = 1 ;
}
F_174 ( & V_60 -> V_2 , V_232 -> V_238 , true ) ;
#ifdef F_28
V_60 -> V_2 . V_214 = V_129 -> V_239 ;
#endif
V_60 -> V_2 . V_240 = F_175 ( V_129 -> V_241 ) ;
if ( F_156 ( V_110 ) )
V_234 = F_159 ( V_60 , V_110 , V_57 ) ;
else if ( ! ( V_60 -> V_2 . V_220 & V_221 ) )
V_234 = F_161 ( V_129 , V_60 ) ;
if ( F_156 ( ! V_234 ) ) {
V_60 -> V_2 . V_220 |= V_221 ;
if ( ! V_60 -> V_62 )
V_60 -> V_62 = V_57 ;
F_163 ( V_60 ) ;
}
} else
F_163 ( V_60 ) ;
#ifdef F_28
#ifdef F_176
F_151 ( V_60 , V_155 -> V_214 ) ;
#endif
F_151 ( V_60 , V_233 ) ;
#endif
}
struct V_50 * F_177 ( struct V_58 * V_53 ,
unsigned int V_220 , T_12 type ,
bool V_242 , bool V_243 , bool V_244 )
{
struct V_50 * V_60 ;
V_60 = F_178 ( & V_16 , V_53 , 1 , V_207 ,
( V_244 ? 0 : ( V_245 | V_221 ) ) |
( V_242 ? V_246 : 0 ) |
( V_243 ? V_247 : 0 ) ) ;
if ( V_60 ) {
V_60 -> V_52 = F_34 ( F_35 ( V_53 ) ) ;
V_60 -> V_125 = V_220 ;
V_60 -> V_248 = type ;
V_60 -> V_249 = 0 ;
V_60 -> V_250 = 0 ;
V_60 -> V_120 = 0 ;
V_60 -> V_62 = 0 ;
V_60 -> V_127 = 0 ;
V_60 -> V_251 = 0 ;
F_179 ( & V_60 -> V_228 ) ;
V_60 -> V_2 . V_252 = V_253 ;
if ( V_220 & V_254 )
V_60 -> V_2 . V_255 = V_256 ;
}
return V_60 ;
}
static int F_180 ( struct V_55 * V_56 , T_6 V_57 , T_6 V_80 ,
T_9 V_87 , struct V_58 * V_53 , int V_257 )
{
struct V_50 * V_51 ;
struct V_152 * V_153 = F_83 ( V_53 ) ;
unsigned int V_220 = V_258 ;
T_1 V_233 = 0 ;
int V_259 ;
if ( ! V_153 )
return - V_189 ;
if ( F_85 ( V_80 ) || F_86 ( V_80 ) ||
V_56 -> V_81 != F_52 ( V_260 ) )
goto V_261;
if ( F_181 ( V_80 ) && ! F_182 ( V_153 ) )
goto V_261;
if ( F_87 ( V_80 ) ) {
if ( ! F_183 ( V_57 ) )
goto V_261;
} else {
V_259 = F_184 ( V_56 , V_80 , 0 , V_87 , 0 , V_53 ,
V_153 , & V_233 ) ;
if ( V_259 < 0 )
goto V_262;
}
if ( V_257 )
V_220 |= V_254 ;
V_51 = F_177 ( F_35 ( V_53 ) -> V_230 , V_220 , V_263 ,
F_185 ( V_153 , V_264 ) , false , false ) ;
if ( ! V_51 )
goto V_265;
#ifdef F_28
V_51 -> V_2 . V_214 = V_233 ;
#endif
V_51 -> V_2 . V_252 = F_145 ;
V_51 -> V_249 = 1 ;
#ifdef F_186
if ( ! F_183 ( V_57 ) && F_187 ( V_153 ) )
V_51 -> V_2 . V_255 = V_266 ;
#endif
F_188 ( V_18 ) ;
F_189 ( V_56 , & V_51 -> V_2 ) ;
return 0 ;
V_265:
return - V_267 ;
V_261:
return - V_189 ;
V_262:
return V_259 ;
}
static void F_190 ( struct V_58 * V_53 ,
struct V_152 * V_153 ,
struct V_55 * V_56 ,
T_6 V_57 ,
T_6 V_80 )
{
F_188 ( V_22 ) ;
#ifdef F_99
if ( F_100 ( V_153 ) && F_191 () ) {
F_192 ( L_15 ,
& V_57 , & V_80 , V_53 -> V_168 ) ;
if ( V_53 -> V_268 && F_193 ( V_56 ) ) {
F_194 ( V_269 , L_16 ,
V_270 , 16 , 1 ,
F_195 ( V_56 ) ,
V_53 -> V_268 , true ) ;
}
}
#endif
}
static void F_196 ( struct V_128 * V_129 , T_6 V_57 )
{
struct V_113 * V_65 ;
struct V_109 * V_110 , T_11 * * V_271 ;
T_1 V_118 = F_71 ( V_57 ) ;
F_76 ( & V_133 ) ;
V_65 = F_197 ( V_129 -> V_134 ,
F_198 ( & V_133 ) ) ;
V_65 += V_118 ;
V_271 = & V_65 -> V_115 ;
V_110 = F_197 ( * V_271 , F_198 ( & V_133 ) ) ;
while ( V_110 ) {
if ( V_110 -> V_138 == V_57 ) {
F_78 ( * V_271 , F_197 (
V_110 -> V_116 , F_198 ( & V_133 ) ) ) ;
F_67 ( V_110 ) ;
F_199 ( V_110 , V_272 ) ;
break;
}
V_271 = & V_110 -> V_116 ;
V_110 = F_197 ( V_110 -> V_116 ,
F_198 ( & V_133 ) ) ;
}
F_80 ( & V_133 ) ;
}
static int F_200 ( struct V_55 * V_56 ,
const struct V_154 * V_155 ,
struct V_152 * V_153 ,
T_6 V_57 , T_6 V_80 , T_1 V_87 )
{
struct V_109 * V_110 ;
struct V_50 * V_51 ;
int V_259 ;
struct V_152 * V_273 ;
bool V_274 ;
T_1 V_233 = 0 ;
V_273 = F_83 ( F_201 ( * V_155 ) ) ;
if ( ! V_273 ) {
F_202 ( L_17 ) ;
return - V_189 ;
}
V_259 = F_184 ( V_56 , V_80 , V_57 , V_87 , F_203 ( * V_155 ) ,
V_153 -> V_53 , V_153 , & V_233 ) ;
if ( V_259 < 0 ) {
F_190 ( V_153 -> V_53 , V_153 , V_56 , V_57 ,
V_80 ) ;
goto V_275;
}
V_274 = V_155 -> V_232 && ! V_233 ;
if ( V_273 == V_153 && V_259 && F_107 ( V_273 ) &&
V_56 -> V_81 == F_52 ( V_260 ) &&
( F_88 ( V_273 ) ||
F_89 ( V_273 , V_80 , F_204 ( * V_155 ) ) ) )
F_205 ( V_56 ) -> V_220 |= V_276 ;
if ( V_56 -> V_81 != F_52 ( V_260 ) ) {
if ( V_273 == V_153 &&
F_206 ( V_153 ) == 0 ) {
V_259 = - V_189 ;
goto V_275;
}
}
V_110 = F_158 ( & F_96 ( * V_155 ) , V_57 ) ;
if ( V_274 ) {
if ( V_110 ) {
V_51 = F_61 ( V_110 -> V_111 ) ;
if ( V_51 && V_51 -> V_2 . V_122 &&
F_112 ( V_73 , V_51 -> V_2 . V_122 ) ) {
F_196 ( & F_96 ( * V_155 ) , V_57 ) ;
V_110 = NULL ;
} else {
goto V_277;
}
}
V_51 = F_61 ( F_96 ( * V_155 ) . V_142 ) ;
V_277:
if ( F_172 ( V_51 ) ) {
F_207 ( V_56 , & V_51 -> V_2 ) ;
goto V_184;
}
}
V_51 = F_177 ( V_273 -> V_53 , 0 , V_155 -> type ,
F_185 ( V_153 , V_264 ) ,
F_185 ( V_273 , V_278 ) , V_274 ) ;
if ( ! V_51 ) {
V_259 = - V_267 ;
goto V_275;
}
V_51 -> V_249 = 1 ;
if ( V_155 -> V_279 )
V_51 -> V_251 = V_155 -> V_279 -> V_280 ;
F_188 ( V_17 ) ;
V_51 -> V_2 . V_255 = V_281 ;
F_173 ( V_51 , V_57 , V_155 , V_110 , V_155 -> V_232 , V_155 -> type , V_233 ) ;
if ( F_208 ( V_51 -> V_2 . V_240 ) ) {
V_51 -> V_2 . V_240 -> V_282 = V_51 -> V_2 . V_252 ;
V_51 -> V_2 . V_252 = V_283 ;
}
if ( F_209 ( V_51 -> V_2 . V_240 ) ) {
V_51 -> V_2 . V_240 -> V_284 = V_51 -> V_2 . V_255 ;
V_51 -> V_2 . V_255 = V_285 ;
}
F_189 ( V_56 , & V_51 -> V_2 ) ;
V_184:
V_259 = 0 ;
V_275:
return V_259 ;
}
static int F_210 ( struct V_55 * V_56 )
{
const struct V_76 * V_286 = F_39 ( V_56 ) ;
struct V_287 V_288 ;
const struct V_287 * V_289 ;
struct V_76 V_290 ;
const struct V_76 * V_291 ;
if ( F_156 ( ( V_286 -> V_292 & F_52 ( V_293 ) ) != 0 ) )
goto V_294;
V_289 = F_211 ( V_56 , V_286 -> V_295 * 4 , sizeof( V_288 ) ,
& V_288 ) ;
if ( ! V_289 )
goto V_294;
if ( V_289 -> type != V_196 &&
V_289 -> type != V_176 &&
V_289 -> type != V_296 &&
V_289 -> type != V_297 ) {
goto V_294;
}
V_291 = F_211 ( V_56 ,
V_286 -> V_295 * 4 + sizeof( V_288 ) ,
sizeof( V_290 ) , & V_290 ) ;
if ( ! V_291 )
goto V_294;
return F_212 ( V_291 -> V_57 , V_291 -> V_80 ) ;
V_294:
return F_212 ( V_286 -> V_80 , V_286 -> V_57 ) ;
}
static int F_213 ( struct V_55 * V_56 ,
struct V_154 * V_155 ,
const struct V_82 * V_83 ,
struct V_152 * V_153 ,
T_6 V_57 , T_6 V_80 , T_1 V_87 )
{
#ifdef F_214
if ( V_155 -> V_232 && V_155 -> V_232 -> V_298 > 1 ) {
int V_299 ;
if ( F_156 ( F_39 ( V_56 ) -> V_81 == V_300 ) )
V_299 = F_210 ( V_56 ) ;
else
V_299 = F_212 ( V_80 , V_57 ) ;
F_215 ( V_155 , V_299 ) ;
}
#endif
return F_200 ( V_56 , V_155 , V_153 , V_57 , V_80 , V_87 ) ;
}
static int F_216 ( struct V_55 * V_56 , T_6 V_57 , T_6 V_80 ,
T_9 V_87 , struct V_58 * V_53 )
{
struct V_154 V_155 ;
struct V_152 * V_153 = F_83 ( V_53 ) ;
struct V_301 * V_302 ;
struct V_82 V_83 ;
unsigned int V_220 = 0 ;
T_1 V_233 = 0 ;
struct V_50 * V_51 ;
int V_259 = - V_189 ;
struct V_37 * V_37 = F_35 ( V_53 ) ;
bool V_274 ;
if ( ! V_153 )
goto V_184;
V_302 = F_217 ( V_56 ) ;
if ( V_302 && ! ( V_302 -> V_303 & V_304 ) )
V_83 . V_305 . V_306 = V_302 -> V_307 . V_306 ;
else
V_83 . V_305 . V_306 = 0 ;
F_218 ( V_56 ) ;
if ( F_85 ( V_80 ) || F_86 ( V_80 ) )
goto V_308;
V_155 . V_232 = NULL ;
V_155 . V_279 = NULL ;
if ( F_86 ( V_57 ) || ( V_80 == 0 && V_57 == 0 ) )
goto V_309;
if ( F_87 ( V_80 ) )
goto V_308;
if ( F_87 ( V_57 ) )
goto V_310;
if ( F_181 ( V_57 ) ) {
if ( ! F_219 ( V_153 , V_37 ) )
goto V_310;
} else if ( F_181 ( V_80 ) ) {
if ( ! F_219 ( V_153 , V_37 ) )
goto V_308;
}
V_83 . V_211 = 0 ;
V_83 . V_212 = F_220 ( V_53 ) ;
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
V_259 = F_184 ( V_56 , V_80 , V_57 , V_87 ,
0 , V_53 , V_153 , & V_233 ) ;
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
V_259 = F_213 ( V_56 , & V_155 , & V_83 , V_153 , V_57 , V_80 , V_87 ) ;
V_184: return V_259 ;
V_309:
if ( V_56 -> V_81 != F_52 ( V_260 ) )
goto V_261;
if ( ! F_87 ( V_80 ) ) {
V_259 = F_184 ( V_56 , V_80 , 0 , V_87 , 0 , V_53 ,
V_153 , & V_233 ) ;
if ( V_259 < 0 )
goto V_308;
}
V_220 |= V_317 ;
V_155 . type = V_314 ;
F_188 ( V_20 ) ;
V_316:
V_274 = false ;
if ( V_155 . V_232 ) {
if ( ! V_233 ) {
V_51 = F_61 ( F_96 ( V_155 ) . V_142 ) ;
if ( F_172 ( V_51 ) ) {
F_207 ( V_56 , & V_51 -> V_2 ) ;
V_259 = 0 ;
goto V_184;
}
V_274 = true ;
}
}
V_51 = F_177 ( V_37 -> V_230 , V_220 | V_254 , V_155 . type ,
F_185 ( V_153 , V_264 ) , false , V_274 ) ;
if ( ! V_51 )
goto V_265;
V_51 -> V_2 . V_252 = F_145 ;
#ifdef F_28
V_51 -> V_2 . V_214 = V_233 ;
#endif
V_51 -> V_249 = 1 ;
if ( V_155 . V_279 )
V_51 -> V_251 = V_155 . V_279 -> V_280 ;
F_188 ( V_17 ) ;
if ( V_155 . type == V_318 ) {
V_51 -> V_2 . V_255 = F_116 ;
V_51 -> V_2 . error = - V_259 ;
V_51 -> V_125 &= ~ V_254 ;
}
if ( V_274 ) {
if ( F_156 ( ! F_161 ( & F_96 ( V_155 ) , V_51 ) ) ) {
V_51 -> V_2 . V_220 |= V_221 ;
F_163 ( V_51 ) ;
}
}
F_189 ( V_56 , & V_51 -> V_2 ) ;
V_259 = 0 ;
goto V_184;
V_313:
F_188 ( V_19 ) ;
V_155 . type = V_318 ;
V_155 . V_232 = NULL ;
V_155 . V_279 = NULL ;
goto V_316;
V_310:
F_188 ( V_21 ) ;
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
F_190 ( V_53 , V_153 , V_56 , V_57 , V_80 ) ;
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
#ifdef F_186
||
( ! F_183 ( V_57 ) &&
F_187 ( V_153 ) )
#endif
) {
int V_155 = F_180 ( V_56 , V_57 , V_80 ,
V_87 , V_53 , V_257 ) ;
F_63 () ;
return V_155 ;
}
}
F_63 () ;
return - V_189 ;
}
V_155 = F_216 ( V_56 , V_57 , V_80 , V_87 , V_53 ) ;
F_63 () ;
return V_155 ;
}
static struct V_50 * F_223 ( const struct V_154 * V_155 ,
const struct V_82 * V_83 , int V_319 ,
struct V_58 * V_320 ,
unsigned int V_220 )
{
struct V_231 * V_232 = V_155 -> V_232 ;
struct V_109 * V_110 ;
struct V_152 * V_153 ;
T_12 type = V_155 -> type ;
struct V_50 * V_51 ;
bool V_274 ;
V_153 = F_83 ( V_320 ) ;
if ( ! V_153 )
return F_224 ( - V_189 ) ;
if ( F_225 ( ! F_182 ( V_153 ) ) )
if ( F_181 ( V_83 -> V_80 ) && ! ( V_320 -> V_220 & V_321 ) )
return F_224 ( - V_189 ) ;
if ( F_86 ( V_83 -> V_57 ) )
type = V_314 ;
else if ( F_85 ( V_83 -> V_57 ) )
type = V_263 ;
else if ( F_87 ( V_83 -> V_57 ) )
return F_224 ( - V_189 ) ;
if ( V_320 -> V_220 & V_321 )
V_220 |= V_254 ;
V_274 = true ;
if ( type == V_314 ) {
V_220 |= V_317 | V_254 ;
V_232 = NULL ;
} else if ( type == V_263 ) {
V_220 |= V_258 | V_254 ;
if ( ! F_222 ( V_153 , V_83 -> V_57 , V_83 -> V_80 ,
V_83 -> V_322 ) )
V_220 &= ~ V_254 ;
else
V_274 = false ;
if ( V_232 && V_155 -> V_323 < 4 )
V_232 = NULL ;
} else if ( ( type == V_315 ) && ( V_319 != 0 ) &&
( V_319 != V_320 -> V_99 ) ) {
V_232 = NULL ;
}
V_110 = NULL ;
V_274 &= V_232 != NULL ;
if ( V_274 ) {
struct V_50 T_11 * * V_324 ;
struct V_128 * V_129 = & F_96 ( * V_155 ) ;
V_110 = F_158 ( V_129 , V_83 -> V_57 ) ;
if ( V_110 ) {
V_324 = & V_110 -> V_112 ;
V_51 = F_61 ( * V_324 ) ;
if ( V_51 && V_51 -> V_2 . V_122 &&
F_112 ( V_73 , V_51 -> V_2 . V_122 ) ) {
F_196 ( V_129 , V_83 -> V_57 ) ;
V_110 = NULL ;
} else {
goto V_277;
}
}
if ( F_156 ( V_83 -> V_312 &
V_325 &&
! ( V_129 -> V_235 &&
V_129 -> V_236 == V_237 ) ) ) {
V_274 = false ;
goto V_326;
}
V_324 = F_162 ( V_129 -> V_146 ) ;
V_51 = F_61 ( * V_324 ) ;
V_277:
if ( F_172 ( V_51 ) ) {
F_226 ( & V_51 -> V_2 ) ;
return V_51 ;
}
}
V_326:
V_51 = F_177 ( V_320 , V_220 , type ,
F_185 ( V_153 , V_264 ) ,
F_185 ( V_153 , V_278 ) ,
V_274 ) ;
if ( ! V_51 )
return F_224 ( - V_267 ) ;
V_51 -> V_250 = V_319 ? : 0 ;
if ( V_155 -> V_279 )
V_51 -> V_251 = V_155 -> V_279 -> V_280 ;
F_188 ( V_23 ) ;
if ( V_220 & ( V_317 | V_258 ) ) {
if ( V_220 & V_254 &&
! ( V_320 -> V_220 & V_321 ) ) {
V_51 -> V_2 . V_252 = V_327 ;
F_188 ( V_24 ) ;
}
#ifdef F_186
if ( type == V_263 ) {
if ( F_187 ( V_153 ) &&
! F_183 ( V_83 -> V_57 ) ) {
V_51 -> V_2 . V_255 = V_266 ;
V_51 -> V_2 . V_252 = V_327 ;
}
}
#endif
}
F_173 ( V_51 , V_83 -> V_57 , V_155 , V_110 , V_232 , type , 0 ) ;
if ( F_208 ( V_51 -> V_2 . V_240 ) )
V_51 -> V_2 . V_252 = V_283 ;
return V_51 ;
}
struct V_50 * F_227 ( struct V_37 * V_37 , struct V_82 * V_83 ,
int V_328 )
{
struct V_58 * V_320 = NULL ;
T_13 V_87 = F_228 ( V_83 ) ;
unsigned int V_220 = 0 ;
struct V_154 V_155 ;
struct V_50 * V_51 ;
int V_329 ;
int V_319 ;
int V_259 = - V_187 ;
V_155 . V_214 = 0 ;
V_155 . V_232 = NULL ;
V_155 . V_279 = NULL ;
V_319 = V_83 -> V_211 ;
V_329 = F_229 ( V_37 , V_83 -> V_211 ) ;
if ( V_329 )
V_83 -> V_211 = V_329 ;
V_83 -> V_212 = V_330 ;
V_83 -> V_210 = V_87 & V_331 ;
V_83 -> V_311 = ( ( V_87 & V_332 ) ?
V_237 : V_98 ) ;
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
goto V_333;
}
if ( ! ( V_83 -> V_312 & V_334 ) ) {
if ( ! F_230 ( V_37 , V_83 -> V_80 , false ) )
goto V_184;
}
}
if ( V_83 -> V_211 ) {
V_320 = F_231 ( V_37 , V_83 -> V_211 ) ;
V_51 = F_224 ( - V_335 ) ;
if ( ! V_320 )
goto V_184;
if ( ! ( V_320 -> V_220 & V_336 ) || ! F_83 ( V_320 ) ) {
V_51 = F_224 ( - V_187 ) ;
goto V_184;
}
if ( F_183 ( V_83 -> V_57 ) ||
F_86 ( V_83 -> V_57 ) ||
V_83 -> V_322 == V_337 ) {
if ( ! V_83 -> V_80 )
V_83 -> V_80 = F_150 ( V_320 , 0 ,
V_237 ) ;
goto V_333;
}
if ( ! V_83 -> V_80 ) {
if ( F_85 ( V_83 -> V_57 ) )
V_83 -> V_80 = F_150 ( V_320 , 0 ,
V_83 -> V_311 ) ;
else if ( ! V_83 -> V_57 )
V_83 -> V_80 = F_150 ( V_320 , 0 ,
V_338 ) ;
}
V_51 = F_232 ( V_320 , V_83 ) ;
if ( V_51 )
goto V_184;
}
if ( ! V_83 -> V_57 ) {
V_83 -> V_57 = V_83 -> V_80 ;
if ( ! V_83 -> V_57 )
V_83 -> V_57 = V_83 -> V_80 = F_233 ( V_339 ) ;
V_320 = V_37 -> V_230 ;
V_83 -> V_211 = V_330 ;
V_155 . type = V_315 ;
V_220 |= V_254 ;
goto V_333;
}
V_259 = F_95 ( V_37 , V_83 , & V_155 , 0 ) ;
if ( V_259 ) {
V_155 . V_232 = NULL ;
V_155 . V_279 = NULL ;
if ( V_83 -> V_211 &&
! F_234 ( V_37 , V_83 -> V_211 ) ) {
if ( V_83 -> V_80 == 0 )
V_83 -> V_80 = F_150 ( V_320 , 0 ,
V_237 ) ;
V_155 . type = V_162 ;
goto V_333;
}
V_51 = F_224 ( V_259 ) ;
goto V_184;
}
if ( V_155 . type == V_315 ) {
if ( ! V_83 -> V_80 ) {
if ( V_155 . V_232 -> V_340 )
V_83 -> V_80 = V_155 . V_232 -> V_340 ;
else
V_83 -> V_80 = V_83 -> V_57 ;
}
V_320 = V_37 -> V_230 ;
V_83 -> V_211 = V_320 -> V_99 ;
V_220 |= V_254 ;
goto V_333;
}
F_235 ( V_37 , & V_155 , V_83 , V_328 ) ;
V_320 = F_201 ( V_155 ) ;
V_83 -> V_211 = V_320 -> V_99 ;
V_333:
V_51 = F_223 ( & V_155 , V_83 , V_319 , V_320 , V_220 ) ;
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
struct V_1 * F_241 ( struct V_37 * V_37 , struct V_1 * V_341 )
{
struct V_50 * V_342 = (struct V_50 * ) V_341 ;
struct V_50 * V_60 ;
V_60 = F_178 ( & V_343 , NULL , 1 , V_344 , 0 ) ;
if ( V_60 ) {
struct V_1 * V_74 = & V_60 -> V_2 ;
V_74 -> V_345 = 1 ;
V_74 -> V_255 = V_346 ;
V_74 -> V_252 = V_347 ;
V_74 -> V_53 = V_342 -> V_2 . V_53 ;
if ( V_74 -> V_53 )
F_170 ( V_74 -> V_53 ) ;
V_60 -> V_249 = V_342 -> V_249 ;
V_60 -> V_250 = V_342 -> V_250 ;
V_60 -> V_120 = V_342 -> V_120 ;
V_60 -> V_52 = F_34 ( V_37 ) ;
V_60 -> V_125 = V_342 -> V_125 ;
V_60 -> V_248 = V_342 -> V_248 ;
V_60 -> V_62 = V_342 -> V_62 ;
V_60 -> V_127 = V_342 -> V_127 ;
F_179 ( & V_60 -> V_228 ) ;
F_242 ( V_74 ) ;
}
F_137 ( V_341 ) ;
return V_60 ? & V_60 -> V_2 : F_224 ( - V_32 ) ;
}
struct V_50 * F_135 ( struct V_37 * V_37 , struct V_82 * V_348 ,
const struct V_84 * V_85 )
{
struct V_50 * V_60 = F_127 ( V_37 , V_348 ) ;
if ( F_93 ( V_60 ) )
return V_60 ;
if ( V_348 -> V_322 )
V_60 = (struct V_50 * ) F_243 ( V_37 , & V_60 -> V_2 ,
F_244 ( V_348 ) ,
V_85 , 0 ) ;
return V_60 ;
}
static int F_245 ( struct V_37 * V_37 , T_6 V_2 , T_6 V_28 , T_1 V_349 ,
struct V_82 * V_83 , struct V_55 * V_56 , T_1 V_350 ,
T_1 V_5 , int V_351 , int V_352 , unsigned int V_220 )
{
struct V_50 * V_60 = F_106 ( V_56 ) ;
struct V_353 * V_354 ;
struct V_355 * V_356 ;
unsigned long V_122 = 0 ;
T_1 error ;
T_1 V_357 [ V_358 ] ;
V_356 = F_246 ( V_56 , V_350 , V_5 , V_351 , sizeof( * V_354 ) , V_220 ) ;
if ( ! V_356 )
return - V_359 ;
V_354 = F_247 ( V_356 ) ;
V_354 -> V_360 = V_361 ;
V_354 -> V_362 = 32 ;
V_354 -> V_363 = 0 ;
V_354 -> V_364 = V_83 -> V_210 ;
V_354 -> V_365 = V_349 ;
if ( F_248 ( V_56 , V_366 , V_349 ) )
goto V_367;
V_354 -> V_368 = V_60 -> V_248 ;
V_354 -> V_369 = V_98 ;
V_354 -> V_370 = V_371 ;
V_354 -> V_372 = ( V_60 -> V_125 & ~ 0xFFFF ) | V_373 ;
if ( V_60 -> V_125 & V_374 )
V_354 -> V_372 |= V_375 ;
if ( F_205 ( V_56 ) -> V_220 & V_276 )
V_354 -> V_372 |= V_376 ;
if ( F_249 ( V_56 , V_377 , V_2 ) )
goto V_367;
if ( V_28 ) {
V_354 -> V_363 = 32 ;
if ( F_249 ( V_56 , V_378 , V_28 ) )
goto V_367;
}
if ( V_60 -> V_2 . V_53 &&
F_248 ( V_56 , V_379 , V_60 -> V_2 . V_53 -> V_99 ) )
goto V_367;
#ifdef F_28
if ( V_60 -> V_2 . V_214 &&
F_248 ( V_56 , V_380 , V_60 -> V_2 . V_214 ) )
goto V_367;
#endif
if ( ! F_160 ( V_60 ) &&
V_83 -> V_80 != V_28 ) {
if ( F_249 ( V_56 , V_381 , V_83 -> V_80 ) )
goto V_367;
}
if ( V_60 -> V_127 &&
F_249 ( V_56 , V_382 , V_60 -> V_62 ) )
goto V_367;
V_122 = V_60 -> V_2 . V_122 ;
if ( V_122 ) {
unsigned long V_72 = V_73 ;
if ( F_70 ( V_72 , V_122 ) )
V_122 -= V_72 ;
else
V_122 = 0 ;
}
memcpy ( V_357 , F_250 ( & V_60 -> V_2 ) , sizeof( V_357 ) ) ;
if ( V_60 -> V_120 && V_122 )
V_357 [ V_198 - 1 ] = V_60 -> V_120 ;
if ( F_251 ( V_56 , V_357 ) < 0 )
goto V_367;
if ( V_83 -> V_201 &&
F_248 ( V_56 , V_383 , V_83 -> V_201 ) )
goto V_367;
error = V_60 -> V_2 . error ;
if ( F_160 ( V_60 ) ) {
#ifdef F_186
if ( F_85 ( V_2 ) && ! F_183 ( V_2 ) &&
F_252 ( V_37 , V_384 ) ) {
int V_259 = F_253 ( V_37 , V_56 ,
V_83 -> V_80 , V_83 -> V_57 ,
V_354 , V_352 , V_350 ) ;
if ( V_259 <= 0 ) {
if ( ! V_352 ) {
if ( V_259 == 0 )
return 0 ;
goto V_367;
} else {
if ( V_259 == - V_359 )
goto V_367;
error = V_259 ;
}
}
} else
#endif
if ( F_248 ( V_56 , V_385 , V_56 -> V_53 -> V_99 ) )
goto V_367;
}
if ( F_254 ( V_56 , & V_60 -> V_2 , 0 , V_122 , error ) < 0 )
goto V_367;
F_255 ( V_56 , V_356 ) ;
return 0 ;
V_367:
F_256 ( V_56 , V_356 ) ;
return - V_359 ;
}
static int F_257 ( struct V_55 * V_386 , struct V_355 * V_356 )
{
struct V_37 * V_37 = F_129 ( V_386 -> V_85 ) ;
struct V_353 * V_387 ;
struct V_388 * V_389 [ V_390 + 1 ] ;
struct V_50 * V_60 = NULL ;
struct V_82 V_83 ;
T_6 V_2 = 0 ;
T_6 V_28 = 0 ;
T_1 V_391 ;
int V_259 ;
int V_89 ;
struct V_55 * V_56 ;
T_1 V_349 = V_392 ;
V_259 = F_258 ( V_356 , sizeof( * V_387 ) , V_389 , V_390 , V_393 ) ;
if ( V_259 < 0 )
goto V_394;
V_387 = F_247 ( V_356 ) ;
V_56 = F_259 ( V_395 , V_31 ) ;
if ( ! V_56 ) {
V_259 = - V_267 ;
goto V_394;
}
F_260 ( V_56 ) ;
F_261 ( V_56 ) ;
F_39 ( V_56 ) -> V_81 = V_300 ;
F_262 ( V_56 , V_396 + sizeof( struct V_76 ) ) ;
V_28 = V_389 [ V_378 ] ? F_263 ( V_389 [ V_378 ] ) : 0 ;
V_2 = V_389 [ V_377 ] ? F_263 ( V_389 [ V_377 ] ) : 0 ;
V_391 = V_389 [ V_385 ] ? F_264 ( V_389 [ V_385 ] ) : 0 ;
V_89 = V_389 [ V_383 ] ? F_264 ( V_389 [ V_383 ] ) : 0 ;
memset ( & V_83 , 0 , sizeof( V_83 ) ) ;
V_83 . V_57 = V_2 ;
V_83 . V_80 = V_28 ;
V_83 . V_210 = V_387 -> V_364 ;
V_83 . V_211 = V_389 [ V_379 ] ? F_264 ( V_389 [ V_379 ] ) : 0 ;
V_83 . V_201 = V_89 ;
if ( F_234 ( V_37 , V_83 . V_211 ) )
V_83 . V_312 = V_397 | V_398 ;
if ( V_391 ) {
struct V_58 * V_53 ;
V_53 = F_265 ( V_37 , V_391 ) ;
if ( ! V_53 ) {
V_259 = - V_335 ;
goto V_399;
}
V_56 -> V_81 = F_52 ( V_260 ) ;
V_56 -> V_53 = V_53 ;
V_56 -> V_89 = V_89 ;
F_266 () ;
V_259 = F_267 ( V_56 , V_2 , V_28 , V_387 -> V_364 , V_53 ) ;
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
goto V_399;
F_189 ( V_56 , & V_60 -> V_2 ) ;
if ( V_387 -> V_372 & V_375 )
V_60 -> V_125 |= V_374 ;
if ( V_387 -> V_372 & V_400 )
V_349 = V_60 -> V_251 ;
V_259 = F_245 ( V_37 , V_2 , V_28 , V_349 , & V_83 , V_56 ,
F_271 ( V_386 ) . V_350 , V_356 -> V_401 ,
V_402 , 0 , 0 ) ;
if ( V_259 < 0 )
goto V_399;
V_259 = F_272 ( V_56 , V_37 , F_271 ( V_386 ) . V_350 ) ;
V_394:
return V_259 ;
V_399:
F_120 ( V_56 ) ;
goto V_394;
}
void F_273 ( struct V_152 * V_153 )
{
F_36 ( F_35 ( V_153 -> V_53 ) ) ;
}
static int F_274 ( struct V_403 * V_404 , int V_405 ,
void T_14 * V_406 ,
T_15 * V_407 , T_2 * V_408 )
{
struct V_37 * V_37 = (struct V_37 * ) V_404 -> V_409 ;
if ( V_405 ) {
F_36 ( V_37 ) ;
F_275 ( V_37 ) ;
return 0 ;
}
return - V_189 ;
}
static T_3 int F_276 ( struct V_37 * V_37 )
{
struct V_403 * V_410 ;
V_410 = V_411 ;
if ( ! F_277 ( V_37 , & V_412 ) ) {
V_410 = F_278 ( V_410 , sizeof( V_411 ) , V_31 ) ;
if ( ! V_410 )
goto V_413;
if ( V_37 -> V_414 != & V_415 )
V_410 [ 0 ] . V_416 = NULL ;
}
V_410 [ 0 ] . V_409 = V_37 ;
V_37 -> V_174 . V_417 = F_279 ( V_37 , L_19 , V_410 ) ;
if ( ! V_37 -> V_174 . V_417 )
goto V_418;
return 0 ;
V_418:
if ( V_410 != V_411 )
F_23 ( V_410 ) ;
V_413:
return - V_32 ;
}
static T_4 void F_280 ( struct V_37 * V_37 )
{
struct V_403 * V_410 ;
V_410 = V_37 -> V_174 . V_417 -> V_419 ;
F_281 ( V_37 -> V_174 . V_417 ) ;
F_282 ( V_410 == V_411 ) ;
F_23 ( V_410 ) ;
}
static T_3 int F_283 ( struct V_37 * V_37 )
{
F_284 ( & V_37 -> V_174 . V_52 , 0 ) ;
F_284 ( & V_37 -> V_140 , 0 ) ;
F_285 ( & V_37 -> V_174 . V_420 ,
sizeof( V_37 -> V_174 . V_420 ) ) ;
return 0 ;
}
static int T_3 F_286 ( struct V_37 * V_37 )
{
struct V_421 * V_422 = F_287 ( sizeof( * V_422 ) , V_31 ) ;
if ( ! V_422 )
return - V_32 ;
F_288 ( V_422 ) ;
V_37 -> V_174 . V_175 = V_422 ;
return 0 ;
}
static void T_4 F_289 ( struct V_37 * V_37 )
{
struct V_421 * V_422 = V_37 -> V_174 . V_175 ;
V_37 -> V_174 . V_175 = NULL ;
F_290 ( V_422 ) ;
F_23 ( V_422 ) ;
}
int T_5 F_291 ( void )
{
int V_423 = 0 ;
int V_12 ;
V_71 = F_287 ( V_69 * sizeof( * V_71 ) , V_31 ) ;
if ( ! V_71 )
F_292 ( L_20 ) ;
F_293 ( V_71 , V_69 * sizeof( * V_71 ) ) ;
V_68 = F_19 ( V_69 , sizeof( * V_68 ) , V_31 ) ;
if ( ! V_68 )
F_292 ( L_21 ) ;
F_20 (cpu) {
struct V_224 * V_225 = & F_12 ( V_226 , V_12 ) ;
F_179 ( & V_225 -> V_229 ) ;
F_294 ( & V_225 -> V_227 ) ;
}
#ifdef F_28
V_27 = F_295 ( 256 * sizeof( struct V_27 ) , F_296 ( struct V_27 ) ) ;
if ( ! V_27 )
F_292 ( L_22 ) ;
#endif
V_16 . V_424 =
F_297 ( L_23 , sizeof( struct V_50 ) , 0 ,
V_425 | V_426 , NULL ) ;
V_343 . V_424 = V_16 . V_424 ;
if ( F_298 ( & V_16 ) < 0 )
F_292 ( L_24 ) ;
if ( F_298 ( & V_343 ) < 0 )
F_292 ( L_25 ) ;
V_16 . V_427 = ~ 0 ;
V_428 = V_429 ;
F_299 () ;
F_300 () ;
if ( F_31 () )
F_301 ( L_26 ) ;
#ifdef F_302
F_303 () ;
F_304 () ;
#endif
F_305 ( V_430 , V_431 , F_257 , NULL , NULL ) ;
#ifdef F_306
F_32 ( & V_432 ) ;
#endif
F_32 ( & V_433 ) ;
F_32 ( & V_434 ) ;
return V_423 ;
}
void T_5 F_307 ( void )
{
F_279 ( & V_412 , L_19 , V_435 ) ;
}
