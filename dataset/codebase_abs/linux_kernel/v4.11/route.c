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
static void F_42 ( const struct V_1 * V_2 , const void * V_57 )
{
struct V_58 * V_53 = V_2 -> V_53 ;
const T_6 * V_59 = V_57 ;
const struct V_50 * V_60 ;
V_60 = ( const struct V_50 * ) V_2 ;
if ( V_60 -> V_62 )
V_59 = ( const T_6 * ) & V_60 -> V_62 ;
else if ( ! V_57 ||
( V_60 -> V_65 &
( V_66 | V_67 | V_68 ) ) )
return;
F_43 ( V_53 , * ( V_63 T_1 * ) V_59 ) ;
}
T_1 F_44 ( T_1 V_69 , int V_70 )
{
T_1 * V_71 = V_72 + V_69 % V_73 ;
T_7 * V_74 = V_75 + V_69 % V_73 ;
T_1 V_3 = F_45 ( * V_71 ) ;
T_1 V_76 = ( T_1 ) V_77 ;
T_1 V_78 , V_79 = 0 ;
if ( V_3 != V_76 && F_46 ( V_71 , V_3 , V_76 ) == V_3 )
V_79 = F_47 ( V_76 - V_3 ) ;
do {
V_3 = ( T_1 ) F_48 ( V_74 ) ;
V_78 = V_3 + V_79 + V_70 ;
} while ( F_49 ( V_74 , V_3 , V_78 ) != V_3 );
return V_78 - V_70 ;
}
void F_50 ( struct V_37 * V_37 , struct V_80 * V_81 , int V_70 )
{
static T_1 T_8 V_82 ;
T_1 V_69 , V_83 ;
F_51 ( & T_8 , sizeof( T_8 ) ) ;
V_69 = F_52 ( ( V_63 T_1 ) V_81 -> V_57 ,
( V_63 T_1 ) V_81 -> V_84 ,
V_81 -> V_85 ^ F_53 ( V_37 ) ,
T_8 ) ;
V_83 = F_44 ( V_69 , V_70 ) ;
V_81 -> V_83 = F_54 ( V_83 ) ;
}
static void F_55 ( const struct V_37 * V_37 , struct V_86 * V_87 ,
const struct V_88 * V_89 ,
const struct V_80 * V_81 ,
int V_90 , T_9 V_91 ,
T_9 V_92 , T_1 V_93 , int V_94 )
{
if ( V_89 ) {
const struct V_95 * V_96 = F_56 ( V_89 ) ;
V_90 = V_89 -> V_97 ;
V_93 = V_89 -> V_98 ;
V_91 = F_57 ( V_89 ) ;
V_92 = V_96 -> V_99 ? V_100 : V_89 -> V_101 ;
}
F_58 ( V_87 , V_90 , V_93 , V_91 ,
V_102 , V_92 ,
V_94 ,
V_81 -> V_57 , V_81 -> V_84 , 0 , 0 ,
F_59 ( V_37 , V_89 ) ) ;
}
static void F_60 ( struct V_86 * V_87 , const struct V_55 * V_56 ,
const struct V_88 * V_89 )
{
const struct V_37 * V_37 = F_35 ( V_56 -> V_53 ) ;
const struct V_80 * V_81 = F_39 ( V_56 ) ;
int V_90 = V_56 -> V_53 -> V_103 ;
T_9 V_91 = F_61 ( V_81 -> V_91 ) ;
T_9 V_92 = V_81 -> V_85 ;
T_1 V_93 = V_56 -> V_93 ;
F_55 ( V_37 , V_87 , V_89 , V_81 , V_90 , V_91 , V_92 , V_93 , 0 ) ;
}
static void F_62 ( struct V_86 * V_87 , const struct V_88 * V_89 )
{
const struct V_95 * V_96 = F_56 ( V_89 ) ;
const struct V_104 * V_105 ;
T_6 V_57 = V_96 -> V_106 ;
F_63 () ;
V_105 = F_64 ( V_96 -> V_105 ) ;
if ( V_105 && V_105 -> V_107 . V_108 )
V_57 = V_105 -> V_107 . V_109 ;
F_58 ( V_87 , V_89 -> V_97 , V_89 -> V_98 ,
F_57 ( V_89 ) , V_102 ,
V_96 -> V_99 ? V_100 : V_89 -> V_101 ,
F_65 ( V_89 ) ,
V_57 , V_96 -> V_110 , 0 , 0 , V_89 -> V_111 ) ;
F_66 () ;
}
static void F_67 ( struct V_86 * V_87 , const struct V_88 * V_89 ,
const struct V_55 * V_56 )
{
if ( V_56 )
F_60 ( V_87 , V_56 , V_89 ) ;
else
F_62 ( V_87 , V_89 ) ;
}
static inline void F_68 ( struct V_50 * V_60 )
{
F_69 ( & V_60 -> V_2 . V_112 , V_113 ) ;
}
static void F_70 ( struct V_114 * V_115 )
{
struct V_50 * V_60 ;
V_60 = F_64 ( V_115 -> V_116 ) ;
if ( V_60 ) {
F_71 ( V_115 -> V_116 , NULL ) ;
F_68 ( V_60 ) ;
}
V_60 = F_64 ( V_115 -> V_117 ) ;
if ( V_60 ) {
F_71 ( V_115 -> V_117 , NULL ) ;
F_68 ( V_60 ) ;
}
}
static struct V_114 * F_72 ( struct V_118 * V_69 )
{
struct V_114 * V_115 , * V_119 ;
V_119 = F_64 ( V_69 -> V_120 ) ;
for ( V_115 = F_64 ( V_119 -> V_121 ) ; V_115 ;
V_115 = F_64 ( V_115 -> V_121 ) ) {
if ( F_73 ( V_115 -> V_122 , V_119 -> V_122 ) )
V_119 = V_115 ;
}
F_70 ( V_119 ) ;
return V_119 ;
}
static inline T_1 F_74 ( T_6 V_57 )
{
static T_1 T_10 V_82 ;
T_1 V_123 ;
F_51 ( & T_10 , sizeof( T_10 ) ) ;
V_123 = F_75 ( ( V_63 T_1 ) V_57 , T_10 ) ;
return F_76 ( V_123 , V_124 ) ;
}
static void F_77 ( struct V_50 * V_60 , struct V_114 * V_115 )
{
V_60 -> V_125 = V_115 -> V_126 ;
V_60 -> V_2 . V_127 = V_115 -> V_128 ;
if ( V_115 -> V_129 ) {
V_60 -> V_65 |= V_130 ;
V_60 -> V_62 = V_115 -> V_129 ;
V_60 -> V_131 = 1 ;
}
}
static void F_78 ( struct V_132 * V_133 , T_6 V_57 , T_6 V_134 ,
T_1 V_135 , unsigned long V_127 )
{
struct V_118 * V_69 ;
struct V_114 * V_115 ;
struct V_50 * V_60 ;
unsigned int V_29 ;
int V_136 ;
T_1 V_123 = F_74 ( V_57 ) ;
F_79 ( & V_137 ) ;
V_69 = F_64 ( V_133 -> V_138 ) ;
if ( ! V_69 ) {
V_69 = F_80 ( V_139 * sizeof( * V_69 ) , V_140 ) ;
if ( ! V_69 )
goto V_141;
F_81 ( V_133 -> V_138 , V_69 ) ;
}
V_69 += V_123 ;
V_136 = 0 ;
for ( V_115 = F_64 ( V_69 -> V_120 ) ; V_115 ;
V_115 = F_64 ( V_115 -> V_121 ) ) {
if ( V_115 -> V_142 == V_57 )
break;
V_136 ++ ;
}
if ( V_115 ) {
if ( V_134 )
V_115 -> V_129 = V_134 ;
if ( V_135 ) {
V_115 -> V_126 = V_135 ;
V_115 -> V_128 = F_82 ( 1UL , V_127 ) ;
}
V_60 = F_64 ( V_115 -> V_116 ) ;
if ( V_60 )
F_77 ( V_60 , V_115 ) ;
V_60 = F_64 ( V_115 -> V_117 ) ;
if ( V_60 )
F_77 ( V_60 , V_115 ) ;
} else {
if ( V_136 > V_143 )
V_115 = F_72 ( V_69 ) ;
else {
V_115 = F_80 ( sizeof( * V_115 ) , V_140 ) ;
if ( ! V_115 )
goto V_141;
V_115 -> V_121 = V_69 -> V_120 ;
F_81 ( V_69 -> V_120 , V_115 ) ;
}
V_115 -> V_144 = V_144 ( F_35 ( V_133 -> V_145 ) ) ;
V_115 -> V_142 = V_57 ;
V_115 -> V_129 = V_134 ;
V_115 -> V_126 = V_135 ;
V_115 -> V_128 = V_127 ;
V_60 = F_64 ( V_133 -> V_146 ) ;
if ( V_60 )
V_60 -> V_2 . V_147 = V_148 ;
F_20 (i) {
struct V_50 T_11 * * V_149 ;
V_149 = F_21 ( V_133 -> V_150 , V_29 ) ;
V_60 = F_64 ( * V_149 ) ;
if ( V_60 )
V_60 -> V_2 . V_147 = V_148 ;
}
}
V_115 -> V_122 = V_77 ;
V_141:
F_83 ( & V_137 ) ;
}
static void F_84 ( struct V_50 * V_60 , struct V_55 * V_56 , struct V_86 * V_87 ,
bool V_151 )
{
T_6 V_152 = F_85 ( V_56 ) -> V_153 . V_154 ;
T_6 V_155 = F_39 ( V_56 ) -> V_84 ;
struct V_58 * V_53 = V_56 -> V_53 ;
struct V_156 * V_157 ;
struct V_158 V_159 ;
struct V_54 * V_61 ;
struct V_37 * V_37 ;
switch ( F_85 ( V_56 ) -> V_160 & 7 ) {
case V_161 :
case V_162 :
case V_163 :
case V_164 :
break;
default:
return;
}
if ( V_60 -> V_62 != V_155 )
return;
V_157 = F_86 ( V_53 ) ;
if ( ! V_157 )
return;
V_37 = F_35 ( V_53 ) ;
if ( V_152 == V_155 || ! F_87 ( V_157 ) ||
F_88 ( V_152 ) || F_89 ( V_152 ) ||
F_90 ( V_152 ) )
goto V_165;
if ( ! F_91 ( V_157 ) ) {
if ( ! F_92 ( V_157 , V_152 , V_155 ) )
goto V_165;
if ( F_93 ( V_157 ) && F_94 ( V_152 , V_53 ) )
goto V_165;
} else {
if ( F_95 ( V_37 , V_152 ) != V_166 )
goto V_165;
}
V_61 = F_40 ( V_60 -> V_2 . V_53 , V_152 ) ;
if ( ! V_61 )
V_61 = F_41 ( & V_64 , & V_152 , V_60 -> V_2 . V_53 ) ;
if ( ! F_96 ( V_61 ) ) {
if ( ! ( V_61 -> V_167 & V_168 ) ) {
F_97 ( V_61 , NULL ) ;
} else {
if ( F_98 ( V_37 , V_87 , & V_159 , 0 ) == 0 ) {
struct V_132 * V_133 = & F_99 ( V_159 ) ;
F_78 ( V_133 , V_87 -> V_57 , V_152 ,
0 , V_77 + V_169 ) ;
}
if ( V_151 )
V_60 -> V_2 . V_147 = V_148 ;
F_100 ( V_170 , V_61 ) ;
}
F_101 ( V_61 ) ;
}
return;
V_165:
#ifdef F_102
if ( F_103 ( V_157 ) ) {
const struct V_80 * V_81 = ( const struct V_80 * ) V_56 -> V_171 ;
T_6 V_57 = V_81 -> V_57 ;
T_6 V_84 = V_81 -> V_84 ;
F_104 ( L_10
L_11 ,
& V_155 , V_53 -> V_172 , & V_152 ,
& V_84 , & V_57 ) ;
}
#endif
;
}
static void F_105 ( struct V_1 * V_2 , struct V_88 * V_89 , struct V_55 * V_56 )
{
struct V_50 * V_60 ;
struct V_86 V_87 ;
const struct V_80 * V_81 = ( const struct V_80 * ) V_56 -> V_171 ;
struct V_37 * V_37 = F_35 ( V_56 -> V_53 ) ;
int V_90 = V_56 -> V_53 -> V_103 ;
T_9 V_91 = F_61 ( V_81 -> V_91 ) ;
T_9 V_92 = V_81 -> V_85 ;
T_1 V_93 = V_56 -> V_93 ;
V_60 = (struct V_50 * ) V_2 ;
F_55 ( V_37 , & V_87 , V_89 , V_81 , V_90 , V_91 , V_92 , V_93 , 0 ) ;
F_84 ( V_60 , V_56 , & V_87 , true ) ;
}
static struct V_1 * F_106 ( struct V_1 * V_2 )
{
struct V_50 * V_60 = (struct V_50 * ) V_2 ;
struct V_1 * V_173 = V_2 ;
if ( V_60 ) {
if ( V_2 -> V_147 > 0 ) {
F_107 ( V_60 ) ;
V_173 = NULL ;
} else if ( ( V_60 -> V_65 & V_130 ) ||
V_60 -> V_2 . V_127 ) {
F_107 ( V_60 ) ;
V_173 = NULL ;
}
}
return V_173 ;
}
void F_108 ( struct V_55 * V_56 )
{
struct V_50 * V_60 = F_109 ( V_56 ) ;
struct V_156 * V_157 ;
struct V_174 * V_175 ;
struct V_37 * V_37 ;
int V_176 ;
int V_177 ;
F_63 () ;
V_157 = F_86 ( V_60 -> V_2 . V_53 ) ;
if ( ! V_157 || ! F_110 ( V_157 ) ) {
F_66 () ;
return;
}
V_176 = F_103 ( V_157 ) ;
V_177 = F_111 ( V_60 -> V_2 . V_53 ) ;
F_66 () ;
V_37 = F_35 ( V_60 -> V_2 . V_53 ) ;
V_175 = F_112 ( V_37 -> V_178 . V_179 , F_39 ( V_56 ) -> V_84 , V_177 , 1 ) ;
if ( ! V_175 ) {
F_113 ( V_56 , V_180 , V_163 ,
F_114 ( V_60 , F_39 ( V_56 ) -> V_57 ) ) ;
return;
}
if ( F_115 ( V_77 , V_175 -> V_181 + V_182 ) )
V_175 -> V_183 = 0 ;
if ( V_175 -> V_183 >= V_184 ) {
V_175 -> V_181 = V_77 ;
goto V_185;
}
if ( V_175 -> V_183 == 0 ||
F_115 ( V_77 ,
( V_175 -> V_181 +
( V_186 << V_175 -> V_183 ) ) ) ) {
T_6 V_134 = F_114 ( V_60 , F_39 ( V_56 ) -> V_57 ) ;
F_113 ( V_56 , V_180 , V_163 , V_134 ) ;
V_175 -> V_181 = V_77 ;
++ V_175 -> V_183 ;
#ifdef F_102
if ( V_176 &&
V_175 -> V_183 == V_184 )
F_116 ( L_12 ,
& F_39 ( V_56 ) -> V_84 , F_117 ( V_56 ) ,
& F_39 ( V_56 ) -> V_57 , & V_134 ) ;
#endif
}
V_185:
F_118 ( V_175 ) ;
}
static int F_119 ( struct V_55 * V_56 )
{
struct V_156 * V_157 = F_86 ( V_56 -> V_53 ) ;
struct V_50 * V_60 = F_109 ( V_56 ) ;
struct V_174 * V_175 ;
unsigned long V_76 ;
struct V_37 * V_37 ;
bool V_187 ;
int V_160 ;
if ( ! V_157 )
goto V_188;
V_37 = F_35 ( V_60 -> V_2 . V_53 ) ;
if ( ! F_120 ( V_157 ) ) {
switch ( V_60 -> V_2 . error ) {
case V_189 :
F_121 ( V_37 , V_190 ) ;
break;
case V_191 :
F_121 ( V_37 , V_192 ) ;
break;
}
goto V_188;
}
switch ( V_60 -> V_2 . error ) {
case V_193 :
default:
goto V_188;
case V_189 :
V_160 = V_194 ;
break;
case V_191 :
V_160 = V_195 ;
F_121 ( V_37 , V_192 ) ;
break;
case V_196 :
V_160 = V_197 ;
break;
}
V_175 = F_112 ( V_37 -> V_178 . V_179 , F_39 ( V_56 ) -> V_84 ,
F_122 ( V_56 -> V_53 ) , 1 ) ;
V_187 = true ;
if ( V_175 ) {
V_76 = V_77 ;
V_175 -> V_183 += V_76 - V_175 -> V_181 ;
if ( V_175 -> V_183 > V_198 )
V_175 -> V_183 = V_198 ;
V_175 -> V_181 = V_76 ;
if ( V_175 -> V_183 >= V_199 )
V_175 -> V_183 -= V_199 ;
else
V_187 = false ;
F_118 ( V_175 ) ;
}
if ( V_187 )
F_113 ( V_56 , V_200 , V_160 , 0 ) ;
V_188: F_123 ( V_56 ) ;
return 0 ;
}
static void F_124 ( struct V_50 * V_60 , struct V_86 * V_87 , T_1 V_201 )
{
struct V_1 * V_2 = & V_60 -> V_2 ;
struct V_158 V_159 ;
if ( F_125 ( V_2 , V_202 ) )
return;
if ( F_126 ( V_2 ) < V_201 )
return;
if ( V_201 < V_203 )
V_201 = V_203 ;
if ( V_60 -> V_125 == V_201 &&
F_73 ( V_77 , V_2 -> V_127 - V_204 / 2 ) )
return;
F_63 () ;
if ( F_98 ( F_35 ( V_2 -> V_53 ) , V_87 , & V_159 , 0 ) == 0 ) {
struct V_132 * V_133 = & F_99 ( V_159 ) ;
F_78 ( V_133 , V_87 -> V_57 , 0 , V_201 ,
V_77 + V_204 ) ;
}
F_66 () ;
}
static void F_127 ( struct V_1 * V_2 , struct V_88 * V_89 ,
struct V_55 * V_56 , T_1 V_201 )
{
struct V_50 * V_60 = (struct V_50 * ) V_2 ;
struct V_86 V_87 ;
F_67 ( & V_87 , V_89 , V_56 ) ;
F_124 ( V_60 , & V_87 , V_201 ) ;
}
void F_128 ( struct V_55 * V_56 , struct V_37 * V_37 , T_1 V_201 ,
int V_90 , T_1 V_93 , T_9 V_85 , int V_94 )
{
const struct V_80 * V_81 = ( const struct V_80 * ) V_56 -> V_171 ;
struct V_86 V_87 ;
struct V_50 * V_60 ;
if ( ! V_93 )
V_93 = F_129 ( V_37 , V_56 -> V_93 ) ;
F_55 ( V_37 , & V_87 , NULL , V_81 , V_90 ,
F_61 ( V_81 -> V_91 ) , V_85 , V_93 , V_94 ) ;
V_60 = F_130 ( V_37 , & V_87 ) ;
if ( ! F_96 ( V_60 ) ) {
F_124 ( V_60 , & V_87 , V_201 ) ;
F_107 ( V_60 ) ;
}
}
static void F_131 ( struct V_55 * V_56 , struct V_88 * V_89 , T_1 V_201 )
{
const struct V_80 * V_81 = ( const struct V_80 * ) V_56 -> V_171 ;
struct V_86 V_87 ;
struct V_50 * V_60 ;
F_55 ( F_132 ( V_89 ) , & V_87 , V_89 , V_81 , 0 , 0 , 0 , 0 , 0 ) ;
if ( ! V_87 . V_205 )
V_87 . V_205 = F_129 ( F_132 ( V_89 ) , V_56 -> V_93 ) ;
V_60 = F_130 ( F_132 ( V_89 ) , & V_87 ) ;
if ( ! F_96 ( V_60 ) ) {
F_124 ( V_60 , & V_87 , V_201 ) ;
F_107 ( V_60 ) ;
}
}
void F_133 ( struct V_55 * V_56 , struct V_88 * V_89 , T_1 V_201 )
{
const struct V_80 * V_81 = ( const struct V_80 * ) V_56 -> V_171 ;
struct V_86 V_87 ;
struct V_50 * V_60 ;
struct V_1 * V_206 = NULL ;
bool V_78 = false ;
struct V_37 * V_37 = F_132 ( V_89 ) ;
F_134 ( V_89 ) ;
if ( ! F_135 ( V_89 ) )
goto V_188;
V_206 = F_136 ( V_89 ) ;
if ( F_137 ( V_89 ) || ! V_206 ) {
F_131 ( V_56 , V_89 , V_201 ) ;
goto V_188;
}
F_55 ( V_37 , & V_87 , V_89 , V_81 , 0 , 0 , 0 , 0 , 0 ) ;
V_60 = (struct V_50 * ) V_206 ;
if ( V_206 -> V_147 && ! V_206 -> V_207 -> V_208 ( V_206 , 0 ) ) {
V_60 = F_138 ( F_132 ( V_89 ) , & V_87 , V_89 ) ;
if ( F_96 ( V_60 ) )
goto V_188;
V_78 = true ;
}
F_124 ( (struct V_50 * ) V_60 -> V_2 . V_209 , & V_87 , V_201 ) ;
if ( ! F_139 ( & V_60 -> V_2 , 0 ) ) {
if ( V_78 )
F_140 ( & V_60 -> V_2 ) ;
V_60 = F_138 ( F_132 ( V_89 ) , & V_87 , V_89 ) ;
if ( F_96 ( V_60 ) )
goto V_188;
V_78 = true ;
}
if ( V_78 )
F_141 ( V_89 , & V_60 -> V_2 ) ;
V_188:
F_142 ( V_89 ) ;
F_140 ( V_206 ) ;
}
void F_143 ( struct V_55 * V_56 , struct V_37 * V_37 ,
int V_90 , T_1 V_93 , T_9 V_85 , int V_94 )
{
const struct V_80 * V_81 = ( const struct V_80 * ) V_56 -> V_171 ;
struct V_86 V_87 ;
struct V_50 * V_60 ;
F_55 ( V_37 , & V_87 , NULL , V_81 , V_90 ,
F_61 ( V_81 -> V_91 ) , V_85 , V_93 , V_94 ) ;
V_60 = F_130 ( V_37 , & V_87 ) ;
if ( ! F_96 ( V_60 ) ) {
F_84 ( V_60 , V_56 , & V_87 , false ) ;
F_107 ( V_60 ) ;
}
}
void F_144 ( struct V_55 * V_56 , struct V_88 * V_89 )
{
const struct V_80 * V_81 = ( const struct V_80 * ) V_56 -> V_171 ;
struct V_86 V_87 ;
struct V_50 * V_60 ;
struct V_37 * V_37 = F_132 ( V_89 ) ;
F_55 ( V_37 , & V_87 , V_89 , V_81 , 0 , 0 , 0 , 0 , 0 ) ;
V_60 = F_130 ( V_37 , & V_87 ) ;
if ( ! F_96 ( V_60 ) ) {
F_84 ( V_60 , V_56 , & V_87 , false ) ;
F_107 ( V_60 ) ;
}
}
static struct V_1 * F_145 ( struct V_1 * V_2 , T_1 V_210 )
{
struct V_50 * V_60 = (struct V_50 * ) V_2 ;
if ( V_2 -> V_147 != V_211 || F_33 ( V_60 ) )
return NULL ;
return V_2 ;
}
static void F_146 ( struct V_55 * V_56 )
{
struct V_50 * V_60 ;
F_113 ( V_56 , V_200 , V_194 , 0 ) ;
V_60 = F_109 ( V_56 ) ;
if ( V_60 )
F_147 ( & V_60 -> V_2 , 0 ) ;
}
static int F_148 ( struct V_37 * V_37 , struct V_88 * V_89 , struct V_55 * V_56 )
{
F_149 ( L_13 ,
V_212 , & F_39 ( V_56 ) -> V_84 , & F_39 ( V_56 ) -> V_57 ,
V_56 -> V_53 ? V_56 -> V_53 -> V_172 : L_14 ) ;
F_123 ( V_56 ) ;
F_2 ( 1 ) ;
return 0 ;
}
void F_150 ( T_9 * V_213 , struct V_55 * V_56 , struct V_50 * V_60 )
{
T_6 V_28 ;
if ( F_151 ( V_60 ) )
V_28 = F_39 ( V_56 ) -> V_84 ;
else {
struct V_158 V_159 ;
struct V_86 V_87 ;
struct V_80 * V_81 ;
V_81 = F_39 ( V_56 ) ;
memset ( & V_87 , 0 , sizeof( V_87 ) ) ;
V_87 . V_57 = V_81 -> V_57 ;
V_87 . V_84 = V_81 -> V_84 ;
V_87 . V_214 = F_61 ( V_81 -> V_91 ) ;
V_87 . V_215 = V_60 -> V_2 . V_53 -> V_103 ;
V_87 . V_216 = V_56 -> V_53 -> V_103 ;
V_87 . V_205 = V_56 -> V_93 ;
F_63 () ;
if ( F_98 ( F_35 ( V_60 -> V_2 . V_53 ) , & V_87 , & V_159 , 0 ) == 0 )
V_28 = F_152 ( F_35 ( V_60 -> V_2 . V_53 ) , V_159 ) ;
else
V_28 = F_153 ( V_60 -> V_2 . V_53 ,
F_114 ( V_60 , V_81 -> V_57 ) ,
V_102 ) ;
F_66 () ;
}
memcpy ( V_213 , & V_28 , 4 ) ;
}
static void F_154 ( struct V_50 * V_60 , T_1 V_217 )
{
if ( ! ( V_60 -> V_2 . V_218 & 0xFFFF ) )
V_60 -> V_2 . V_218 |= V_217 & 0xFFFF ;
if ( ! ( V_60 -> V_2 . V_218 & 0xFFFF0000 ) )
V_60 -> V_2 . V_218 |= V_217 & 0xFFFF0000 ;
}
static unsigned int F_155 ( const struct V_1 * V_2 )
{
unsigned int V_219 = F_156 ( V_2 , V_220 ) ;
if ( V_219 == 0 ) {
V_219 = F_157 (unsigned int, dst->dev->mtu - 40 ,
ip_rt_min_advmss) ;
if ( V_219 > 65535 - 40 )
V_219 = 65535 - 40 ;
}
return V_219 ;
}
static unsigned int F_126 ( const struct V_1 * V_2 )
{
const struct V_50 * V_60 = ( const struct V_50 * ) V_2 ;
unsigned int V_201 = V_60 -> V_125 ;
if ( ! V_201 || F_158 ( V_77 , V_60 -> V_2 . V_127 ) )
V_201 = F_156 ( V_2 , V_202 ) ;
if ( V_201 )
return V_201 ;
V_201 = V_2 -> V_53 -> V_201 ;
if ( F_159 ( F_125 ( V_2 , V_202 ) ) ) {
if ( V_60 -> V_131 && V_201 > 576 )
V_201 = 576 ;
}
V_201 = F_160 (unsigned int, mtu, IP_MAX_MTU) ;
return V_201 - F_161 ( V_2 -> V_221 , V_201 ) ;
}
static struct V_114 * F_162 ( struct V_132 * V_133 , T_6 V_57 )
{
struct V_118 * V_69 = F_64 ( V_133 -> V_138 ) ;
struct V_114 * V_115 ;
T_1 V_123 ;
if ( ! V_69 )
return NULL ;
V_123 = F_74 ( V_57 ) ;
for ( V_115 = F_64 ( V_69 [ V_123 ] . V_120 ) ; V_115 ;
V_115 = F_64 ( V_115 -> V_121 ) ) {
if ( V_115 -> V_142 == V_57 )
return V_115 ;
}
return NULL ;
}
static bool F_163 ( struct V_50 * V_60 , struct V_114 * V_115 ,
T_6 V_57 )
{
bool V_173 = false ;
F_79 ( & V_137 ) ;
if ( V_57 == V_115 -> V_142 ) {
struct V_50 T_11 * * V_222 ;
struct V_50 * V_223 ;
int V_224 = V_144 ( F_35 ( V_60 -> V_2 . V_53 ) ) ;
if ( F_164 ( V_60 ) )
V_222 = & V_115 -> V_116 ;
else
V_222 = & V_115 -> V_117 ;
V_223 = F_64 ( * V_222 ) ;
if ( V_115 -> V_144 != V_224 ) {
V_115 -> V_144 = V_224 ;
V_115 -> V_129 = 0 ;
V_115 -> V_126 = 0 ;
V_115 -> V_128 = 0 ;
F_70 ( V_115 ) ;
V_223 = NULL ;
}
F_77 ( V_60 , V_115 ) ;
if ( ! V_60 -> V_62 )
V_60 -> V_62 = V_57 ;
if ( ! ( V_60 -> V_2 . V_225 & V_226 ) ) {
F_81 ( * V_222 , V_60 ) ;
if ( V_223 )
F_68 ( V_223 ) ;
V_173 = true ;
}
V_115 -> V_122 = V_77 ;
}
F_83 ( & V_137 ) ;
return V_173 ;
}
static bool F_165 ( struct V_132 * V_133 , struct V_50 * V_60 )
{
struct V_50 * V_223 , * V_227 , * * V_228 ;
bool V_173 = true ;
if ( F_164 ( V_60 ) ) {
V_228 = (struct V_50 * * ) & V_133 -> V_146 ;
} else {
V_228 = (struct V_50 * * ) F_166 ( V_133 -> V_150 ) ;
}
V_223 = * V_228 ;
V_227 = F_46 ( V_228 , V_223 , V_60 ) ;
if ( V_227 == V_223 ) {
if ( V_223 )
F_68 ( V_223 ) ;
} else
V_173 = false ;
return V_173 ;
}
static void F_167 ( struct V_50 * V_60 )
{
struct V_229 * V_230 = F_166 ( & V_231 ) ;
V_60 -> V_231 = V_230 ;
F_79 ( & V_230 -> V_232 ) ;
F_168 ( & V_60 -> V_233 , & V_230 -> V_234 ) ;
F_83 ( & V_230 -> V_232 ) ;
}
static void F_169 ( struct V_1 * V_2 )
{
struct V_50 * V_60 = (struct V_50 * ) V_2 ;
if ( ! F_170 ( & V_60 -> V_233 ) ) {
struct V_229 * V_230 = V_60 -> V_231 ;
F_79 ( & V_230 -> V_232 ) ;
F_171 ( & V_60 -> V_233 ) ;
F_83 ( & V_230 -> V_232 ) ;
}
}
void F_172 ( struct V_58 * V_53 )
{
struct V_37 * V_37 = F_35 ( V_53 ) ;
struct V_50 * V_60 ;
int V_12 ;
F_20 (cpu) {
struct V_229 * V_230 = & F_12 ( V_231 , V_12 ) ;
F_79 ( & V_230 -> V_232 ) ;
F_173 (rt, &ul->head, rt_uncached) {
if ( V_60 -> V_2 . V_53 != V_53 )
continue;
V_60 -> V_2 . V_53 = V_37 -> V_235 ;
F_174 ( V_60 -> V_2 . V_53 ) ;
F_175 ( V_53 ) ;
}
F_83 ( & V_230 -> V_232 ) ;
}
}
static bool F_176 ( const struct V_50 * V_60 )
{
return V_60 &&
V_60 -> V_2 . V_147 == V_211 &&
! F_33 ( V_60 ) ;
}
static void F_177 ( struct V_50 * V_60 , T_6 V_57 ,
const struct V_158 * V_159 ,
struct V_114 * V_115 ,
struct V_236 * V_237 , T_12 type , T_1 V_238 )
{
bool V_239 = false ;
if ( V_237 ) {
struct V_132 * V_133 = & F_99 ( * V_159 ) ;
if ( V_133 -> V_240 && V_133 -> V_241 == V_242 ) {
V_60 -> V_62 = V_133 -> V_240 ;
V_60 -> V_131 = 1 ;
}
F_178 ( & V_60 -> V_2 , V_237 -> V_243 , true ) ;
#ifdef F_28
V_60 -> V_2 . V_218 = V_133 -> V_244 ;
#endif
V_60 -> V_2 . V_221 = F_179 ( V_133 -> V_245 ) ;
if ( F_159 ( V_115 ) )
V_239 = F_163 ( V_60 , V_115 , V_57 ) ;
else if ( ! ( V_60 -> V_2 . V_225 & V_226 ) )
V_239 = F_165 ( V_133 , V_60 ) ;
if ( F_159 ( ! V_239 ) ) {
V_60 -> V_2 . V_225 |= V_226 ;
if ( ! V_60 -> V_62 )
V_60 -> V_62 = V_57 ;
F_167 ( V_60 ) ;
}
} else
F_167 ( V_60 ) ;
#ifdef F_28
#ifdef F_180
F_154 ( V_60 , V_159 -> V_218 ) ;
#endif
F_154 ( V_60 , V_238 ) ;
#endif
}
struct V_50 * F_181 ( struct V_58 * V_53 ,
unsigned int V_225 , T_12 type ,
bool V_246 , bool V_247 , bool V_248 )
{
struct V_50 * V_60 ;
V_60 = F_182 ( & V_16 , V_53 , 1 , V_211 ,
( V_248 ? 0 : ( V_249 | V_226 ) ) |
( V_246 ? V_250 : 0 ) |
( V_247 ? V_251 : 0 ) ) ;
if ( V_60 ) {
V_60 -> V_52 = F_34 ( F_35 ( V_53 ) ) ;
V_60 -> V_65 = V_225 ;
V_60 -> V_252 = type ;
V_60 -> V_253 = 0 ;
V_60 -> V_254 = 0 ;
V_60 -> V_125 = 0 ;
V_60 -> V_62 = 0 ;
V_60 -> V_131 = 0 ;
V_60 -> V_255 = 0 ;
F_183 ( & V_60 -> V_233 ) ;
V_60 -> V_2 . V_256 = V_257 ;
if ( V_225 & V_68 )
V_60 -> V_2 . V_258 = V_259 ;
}
return V_60 ;
}
static int F_184 ( struct V_55 * V_56 , T_6 V_57 , T_6 V_84 ,
T_9 V_91 , struct V_58 * V_53 , int V_260 )
{
struct V_50 * V_51 ;
struct V_156 * V_157 = F_86 ( V_53 ) ;
unsigned int V_225 = V_66 ;
T_1 V_238 = 0 ;
int V_261 ;
if ( ! V_157 )
return - V_193 ;
if ( F_88 ( V_84 ) || F_89 ( V_84 ) ||
V_56 -> V_85 != F_54 ( V_262 ) )
goto V_263;
if ( F_185 ( V_84 ) && ! F_186 ( V_157 ) )
goto V_263;
if ( F_90 ( V_84 ) ) {
if ( ! F_187 ( V_57 ) )
goto V_263;
} else {
V_261 = F_188 ( V_56 , V_84 , 0 , V_91 , 0 , V_53 ,
V_157 , & V_238 ) ;
if ( V_261 < 0 )
goto V_264;
}
if ( V_260 )
V_225 |= V_68 ;
V_51 = F_181 ( F_35 ( V_53 ) -> V_235 , V_225 , V_265 ,
F_189 ( V_157 , V_266 ) , false , false ) ;
if ( ! V_51 )
goto V_267;
#ifdef F_28
V_51 -> V_2 . V_218 = V_238 ;
#endif
V_51 -> V_2 . V_256 = F_148 ;
V_51 -> V_253 = 1 ;
#ifdef F_190
if ( ! F_187 ( V_57 ) && F_191 ( V_157 ) )
V_51 -> V_2 . V_258 = V_268 ;
#endif
F_192 ( V_18 ) ;
F_193 ( V_56 , & V_51 -> V_2 ) ;
return 0 ;
V_267:
return - V_269 ;
V_263:
return - V_193 ;
V_264:
return V_261 ;
}
static void F_194 ( struct V_58 * V_53 ,
struct V_156 * V_157 ,
struct V_55 * V_56 ,
T_6 V_57 ,
T_6 V_84 )
{
F_192 ( V_22 ) ;
#ifdef F_102
if ( F_103 ( V_157 ) && F_195 () ) {
F_196 ( L_15 ,
& V_57 , & V_84 , V_53 -> V_172 ) ;
if ( V_53 -> V_270 && F_197 ( V_56 ) ) {
F_198 ( V_271 , L_16 ,
V_272 , 16 , 1 ,
F_199 ( V_56 ) ,
V_53 -> V_270 , true ) ;
}
}
#endif
}
static void F_200 ( struct V_132 * V_133 , T_6 V_57 )
{
struct V_118 * V_69 ;
struct V_114 * V_115 , T_11 * * V_273 ;
T_1 V_123 = F_74 ( V_57 ) ;
F_79 ( & V_137 ) ;
V_69 = F_201 ( V_133 -> V_138 ,
F_202 ( & V_137 ) ) ;
V_69 += V_123 ;
V_273 = & V_69 -> V_120 ;
V_115 = F_201 ( * V_273 , F_202 ( & V_137 ) ) ;
while ( V_115 ) {
if ( V_115 -> V_142 == V_57 ) {
F_81 ( * V_273 , F_201 (
V_115 -> V_121 , F_202 ( & V_137 ) ) ) ;
F_70 ( V_115 ) ;
F_203 ( V_115 , V_274 ) ;
break;
}
V_273 = & V_115 -> V_121 ;
V_115 = F_201 ( V_115 -> V_121 ,
F_202 ( & V_137 ) ) ;
}
F_83 ( & V_137 ) ;
}
static void F_204 ( struct V_50 * V_51 )
{
if ( F_205 ( V_51 -> V_2 . V_221 ) ) {
V_51 -> V_2 . V_221 -> V_275 = V_51 -> V_2 . V_256 ;
V_51 -> V_2 . V_256 = V_276 ;
}
if ( F_206 ( V_51 -> V_2 . V_221 ) ) {
V_51 -> V_2 . V_221 -> V_277 = V_51 -> V_2 . V_258 ;
V_51 -> V_2 . V_258 = V_278 ;
}
}
static int F_207 ( struct V_55 * V_56 ,
const struct V_158 * V_159 ,
struct V_156 * V_157 ,
T_6 V_57 , T_6 V_84 , T_1 V_91 )
{
struct V_114 * V_115 ;
struct V_50 * V_51 ;
int V_261 ;
struct V_156 * V_279 ;
bool V_280 ;
T_1 V_238 = 0 ;
V_279 = F_86 ( F_208 ( * V_159 ) ) ;
if ( ! V_279 ) {
F_209 ( L_17 ) ;
return - V_193 ;
}
V_261 = F_188 ( V_56 , V_84 , V_57 , V_91 , F_210 ( * V_159 ) ,
V_157 -> V_53 , V_157 , & V_238 ) ;
if ( V_261 < 0 ) {
F_194 ( V_157 -> V_53 , V_157 , V_56 , V_57 ,
V_84 ) ;
goto V_281;
}
V_280 = V_159 -> V_237 && ! V_238 ;
if ( V_279 == V_157 && V_261 && F_110 ( V_279 ) &&
V_56 -> V_85 == F_54 ( V_262 ) &&
( F_91 ( V_279 ) ||
F_92 ( V_279 , V_84 , F_211 ( * V_159 ) ) ) )
F_212 ( V_56 ) -> V_225 |= V_282 ;
if ( V_56 -> V_85 != F_54 ( V_262 ) ) {
if ( V_279 == V_157 &&
F_213 ( V_157 ) == 0 ) {
V_261 = - V_193 ;
goto V_281;
}
}
V_115 = F_162 ( & F_99 ( * V_159 ) , V_57 ) ;
if ( V_280 ) {
if ( V_115 ) {
V_51 = F_64 ( V_115 -> V_116 ) ;
if ( V_51 && V_51 -> V_2 . V_127 &&
F_115 ( V_77 , V_51 -> V_2 . V_127 ) ) {
F_200 ( & F_99 ( * V_159 ) , V_57 ) ;
V_115 = NULL ;
} else {
goto V_283;
}
}
V_51 = F_64 ( F_99 ( * V_159 ) . V_146 ) ;
V_283:
if ( F_176 ( V_51 ) ) {
F_214 ( V_56 , & V_51 -> V_2 ) ;
goto V_188;
}
}
V_51 = F_181 ( V_279 -> V_53 , 0 , V_159 -> type ,
F_189 ( V_157 , V_266 ) ,
F_189 ( V_279 , V_284 ) , V_280 ) ;
if ( ! V_51 ) {
V_261 = - V_269 ;
goto V_281;
}
V_51 -> V_253 = 1 ;
if ( V_159 -> V_285 )
V_51 -> V_255 = V_159 -> V_285 -> V_286 ;
F_192 ( V_17 ) ;
V_51 -> V_2 . V_258 = V_287 ;
F_177 ( V_51 , V_57 , V_159 , V_115 , V_159 -> V_237 , V_159 -> type , V_238 ) ;
F_204 ( V_51 ) ;
F_193 ( V_56 , & V_51 -> V_2 ) ;
V_188:
V_261 = 0 ;
V_281:
return V_261 ;
}
static int F_215 ( struct V_55 * V_56 )
{
const struct V_80 * V_288 = F_39 ( V_56 ) ;
struct V_289 V_290 ;
const struct V_289 * V_291 ;
struct V_80 V_292 ;
const struct V_80 * V_293 ;
if ( F_159 ( ( V_288 -> V_294 & F_54 ( V_295 ) ) != 0 ) )
goto V_296;
V_291 = F_216 ( V_56 , V_288 -> V_297 * 4 , sizeof( V_290 ) ,
& V_290 ) ;
if ( ! V_291 )
goto V_296;
if ( V_291 -> type != V_200 &&
V_291 -> type != V_180 &&
V_291 -> type != V_298 &&
V_291 -> type != V_299 ) {
goto V_296;
}
V_293 = F_216 ( V_56 ,
V_288 -> V_297 * 4 + sizeof( V_290 ) ,
sizeof( V_292 ) , & V_292 ) ;
if ( ! V_293 )
goto V_296;
return F_217 ( V_293 -> V_57 , V_293 -> V_84 ) ;
V_296:
return F_217 ( V_288 -> V_84 , V_288 -> V_57 ) ;
}
static int F_218 ( struct V_55 * V_56 ,
struct V_158 * V_159 ,
struct V_156 * V_157 ,
T_6 V_57 , T_6 V_84 , T_1 V_91 )
{
#ifdef F_219
if ( V_159 -> V_237 && V_159 -> V_237 -> V_300 > 1 ) {
int V_301 ;
if ( F_159 ( F_39 ( V_56 ) -> V_85 == V_302 ) )
V_301 = F_215 ( V_56 ) ;
else
V_301 = F_217 ( V_84 , V_57 ) ;
F_220 ( V_159 , V_301 ) ;
}
#endif
return F_207 ( V_56 , V_159 , V_157 , V_57 , V_84 , V_91 ) ;
}
static int F_221 ( struct V_55 * V_56 , T_6 V_57 , T_6 V_84 ,
T_9 V_91 , struct V_58 * V_53 )
{
struct V_158 V_159 ;
struct V_156 * V_157 = F_86 ( V_53 ) ;
struct V_303 * V_304 ;
struct V_86 V_87 ;
unsigned int V_225 = 0 ;
T_1 V_238 = 0 ;
struct V_50 * V_51 ;
int V_261 = - V_193 ;
struct V_37 * V_37 = F_35 ( V_53 ) ;
bool V_280 ;
if ( ! V_157 )
goto V_188;
V_304 = F_222 ( V_56 ) ;
if ( V_304 && ! ( V_304 -> V_305 & V_306 ) )
V_87 . V_307 . V_308 = V_304 -> V_309 . V_308 ;
else
V_87 . V_307 . V_308 = 0 ;
F_223 ( V_56 ) ;
if ( F_88 ( V_84 ) || F_89 ( V_84 ) )
goto V_310;
V_159 . V_237 = NULL ;
V_159 . V_285 = NULL ;
if ( F_89 ( V_57 ) || ( V_84 == 0 && V_57 == 0 ) )
goto V_311;
if ( F_90 ( V_84 ) )
goto V_310;
if ( F_90 ( V_57 ) )
goto V_312;
if ( F_185 ( V_57 ) ) {
if ( ! F_224 ( V_157 , V_37 ) )
goto V_312;
} else if ( F_185 ( V_84 ) ) {
if ( ! F_224 ( V_157 , V_37 ) )
goto V_310;
}
V_87 . V_215 = 0 ;
V_87 . V_216 = V_53 -> V_103 ;
V_87 . V_205 = V_56 -> V_93 ;
V_87 . V_214 = V_91 ;
V_87 . V_313 = V_102 ;
V_87 . V_314 = 0 ;
V_87 . V_57 = V_57 ;
V_87 . V_84 = V_84 ;
V_87 . V_315 = F_59 ( V_37 , NULL ) ;
V_261 = F_98 ( V_37 , & V_87 , & V_159 , 0 ) ;
if ( V_261 != 0 ) {
if ( ! F_120 ( V_157 ) )
V_261 = - V_189 ;
goto V_316;
}
if ( V_159 . type == V_317 )
goto V_311;
if ( V_159 . type == V_318 ) {
V_261 = F_188 ( V_56 , V_84 , V_57 , V_91 ,
0 , V_53 , V_157 , & V_238 ) ;
if ( V_261 < 0 )
goto V_310;
goto V_319;
}
if ( ! F_120 ( V_157 ) ) {
V_261 = - V_189 ;
goto V_316;
}
if ( V_159 . type != V_166 )
goto V_312;
V_261 = F_218 ( V_56 , & V_159 , V_157 , V_57 , V_84 , V_91 ) ;
V_188: return V_261 ;
V_311:
if ( V_56 -> V_85 != F_54 ( V_262 ) )
goto V_263;
if ( ! F_90 ( V_84 ) ) {
V_261 = F_188 ( V_56 , V_84 , 0 , V_91 , 0 , V_53 ,
V_157 , & V_238 ) ;
if ( V_261 < 0 )
goto V_310;
}
V_225 |= V_67 ;
V_159 . type = V_317 ;
F_192 ( V_20 ) ;
V_319:
V_280 = false ;
if ( V_159 . V_237 ) {
if ( ! V_238 ) {
V_51 = F_64 ( F_99 ( V_159 ) . V_146 ) ;
if ( F_176 ( V_51 ) ) {
F_214 ( V_56 , & V_51 -> V_2 ) ;
V_261 = 0 ;
goto V_188;
}
V_280 = true ;
}
}
V_51 = F_181 ( F_225 ( V_53 ) ? : V_37 -> V_235 ,
V_225 | V_68 , V_159 . type ,
F_189 ( V_157 , V_266 ) , false , V_280 ) ;
if ( ! V_51 )
goto V_267;
V_51 -> V_2 . V_256 = F_148 ;
#ifdef F_28
V_51 -> V_2 . V_218 = V_238 ;
#endif
V_51 -> V_253 = 1 ;
if ( V_159 . V_285 )
V_51 -> V_255 = V_159 . V_285 -> V_286 ;
F_192 ( V_17 ) ;
if ( V_159 . type == V_320 ) {
V_51 -> V_2 . V_258 = F_119 ;
V_51 -> V_2 . error = - V_261 ;
V_51 -> V_65 &= ~ V_68 ;
}
if ( V_280 ) {
struct V_132 * V_133 = & F_99 ( V_159 ) ;
V_51 -> V_2 . V_221 = F_179 ( V_133 -> V_245 ) ;
if ( F_206 ( V_51 -> V_2 . V_221 ) ) {
F_2 ( V_51 -> V_2 . V_258 == V_278 ) ;
V_51 -> V_2 . V_221 -> V_277 = V_51 -> V_2 . V_258 ;
V_51 -> V_2 . V_258 = V_278 ;
}
if ( F_159 ( ! F_165 ( V_133 , V_51 ) ) ) {
V_51 -> V_2 . V_225 |= V_226 ;
F_167 ( V_51 ) ;
}
}
F_193 ( V_56 , & V_51 -> V_2 ) ;
V_261 = 0 ;
goto V_188;
V_316:
F_192 ( V_19 ) ;
V_159 . type = V_320 ;
V_159 . V_237 = NULL ;
V_159 . V_285 = NULL ;
goto V_319;
V_312:
F_192 ( V_21 ) ;
#ifdef F_102
if ( F_103 ( V_157 ) )
F_116 ( L_18 ,
& V_57 , & V_84 , V_53 -> V_172 ) ;
#endif
V_263:
V_261 = - V_193 ;
goto V_188;
V_267:
V_261 = - V_269 ;
goto V_188;
V_310:
F_194 ( V_53 , V_157 , V_56 , V_57 , V_84 ) ;
goto V_188;
}
int F_226 ( struct V_55 * V_56 , T_6 V_57 , T_6 V_84 ,
T_9 V_91 , struct V_58 * V_53 )
{
int V_159 ;
V_91 &= V_321 ;
F_63 () ;
if ( F_88 ( V_57 ) ) {
struct V_156 * V_157 = F_86 ( V_53 ) ;
int V_260 = 0 ;
if ( V_157 )
V_260 = F_227 ( V_157 , V_57 , V_84 ,
F_39 ( V_56 ) -> V_85 ) ;
if ( ( ! V_157 || ! V_260 ) && F_228 ( V_53 ) ) {
struct V_156 * V_322 ;
V_322 = F_86 ( V_56 -> V_53 ) ;
if ( V_322 )
V_260 = F_227 ( V_322 , V_57 , V_84 ,
F_39 ( V_56 ) -> V_85 ) ;
}
V_159 = - V_193 ;
if ( V_260
#ifdef F_190
||
( ! F_187 ( V_57 ) &&
F_191 ( V_157 ) )
#endif
) {
V_159 = F_184 ( V_56 , V_57 , V_84 ,
V_91 , V_53 , V_260 ) ;
}
F_66 () ;
return V_159 ;
}
V_159 = F_221 ( V_56 , V_57 , V_84 , V_91 , V_53 ) ;
F_66 () ;
return V_159 ;
}
static struct V_50 * F_229 ( const struct V_158 * V_159 ,
const struct V_86 * V_87 , int V_323 ,
struct V_58 * V_324 ,
unsigned int V_225 )
{
struct V_236 * V_237 = V_159 -> V_237 ;
struct V_114 * V_115 ;
struct V_156 * V_157 ;
T_12 type = V_159 -> type ;
struct V_50 * V_51 ;
bool V_280 ;
V_157 = F_86 ( V_324 ) ;
if ( ! V_157 )
return F_230 ( - V_193 ) ;
if ( F_231 ( ! F_186 ( V_157 ) ) )
if ( F_185 ( V_87 -> V_84 ) &&
! ( V_324 -> V_225 & V_325 ) &&
! F_232 ( V_324 ) )
return F_230 ( - V_193 ) ;
if ( F_89 ( V_87 -> V_57 ) )
type = V_317 ;
else if ( F_88 ( V_87 -> V_57 ) )
type = V_265 ;
else if ( F_90 ( V_87 -> V_57 ) )
return F_230 ( - V_193 ) ;
if ( V_324 -> V_225 & V_325 )
V_225 |= V_68 ;
V_280 = true ;
if ( type == V_317 ) {
V_225 |= V_67 | V_68 ;
V_237 = NULL ;
} else if ( type == V_265 ) {
V_225 |= V_66 | V_68 ;
if ( ! F_227 ( V_157 , V_87 -> V_57 , V_87 -> V_84 ,
V_87 -> V_326 ) )
V_225 &= ~ V_68 ;
else
V_280 = false ;
if ( V_237 && V_159 -> V_327 < 4 )
V_237 = NULL ;
} else if ( ( type == V_318 ) && ( V_323 != 0 ) &&
( V_323 != V_324 -> V_103 ) ) {
V_237 = NULL ;
}
V_115 = NULL ;
V_280 &= V_237 != NULL ;
if ( V_280 ) {
struct V_50 T_11 * * V_328 ;
struct V_132 * V_133 = & F_99 ( * V_159 ) ;
V_115 = F_162 ( V_133 , V_87 -> V_57 ) ;
if ( V_115 ) {
V_328 = & V_115 -> V_117 ;
V_51 = F_64 ( * V_328 ) ;
if ( V_51 && V_51 -> V_2 . V_127 &&
F_115 ( V_77 , V_51 -> V_2 . V_127 ) ) {
F_200 ( V_133 , V_87 -> V_57 ) ;
V_115 = NULL ;
} else {
goto V_283;
}
}
if ( F_159 ( V_87 -> V_314 &
V_329 &&
! ( V_133 -> V_240 &&
V_133 -> V_241 == V_242 ) ) ) {
V_280 = false ;
goto V_330;
}
V_328 = F_166 ( V_133 -> V_150 ) ;
V_51 = F_64 ( * V_328 ) ;
V_283:
if ( F_176 ( V_51 ) ) {
F_233 ( & V_51 -> V_2 ) ;
return V_51 ;
}
}
V_330:
V_51 = F_181 ( V_324 , V_225 , type ,
F_189 ( V_157 , V_266 ) ,
F_189 ( V_157 , V_284 ) ,
V_280 ) ;
if ( ! V_51 )
return F_230 ( - V_269 ) ;
V_51 -> V_254 = V_323 ? : 0 ;
if ( V_159 -> V_285 )
V_51 -> V_255 = V_159 -> V_285 -> V_286 ;
F_192 ( V_23 ) ;
if ( V_225 & ( V_67 | V_66 ) ) {
if ( V_225 & V_68 &&
! ( V_324 -> V_225 & V_325 ) ) {
V_51 -> V_2 . V_256 = V_331 ;
F_192 ( V_24 ) ;
}
#ifdef F_190
if ( type == V_265 ) {
if ( F_191 ( V_157 ) &&
! F_187 ( V_87 -> V_57 ) ) {
V_51 -> V_2 . V_258 = V_268 ;
V_51 -> V_2 . V_256 = V_331 ;
}
}
#endif
}
F_177 ( V_51 , V_87 -> V_57 , V_159 , V_115 , V_237 , type , 0 ) ;
F_204 ( V_51 ) ;
return V_51 ;
}
struct V_50 * F_234 ( struct V_37 * V_37 , struct V_86 * V_87 ,
int V_332 )
{
struct V_58 * V_324 = NULL ;
T_13 V_91 = F_235 ( V_87 ) ;
unsigned int V_225 = 0 ;
struct V_158 V_159 ;
struct V_50 * V_51 ;
int V_323 ;
int V_261 = - V_191 ;
V_159 . V_218 = 0 ;
V_159 . V_237 = NULL ;
V_159 . V_285 = NULL ;
V_323 = V_87 -> V_215 ;
V_87 -> V_216 = V_333 ;
V_87 -> V_214 = V_91 & V_321 ;
V_87 -> V_313 = ( ( V_91 & V_334 ) ?
V_242 : V_102 ) ;
F_63 () ;
if ( V_87 -> V_84 ) {
V_51 = F_230 ( - V_193 ) ;
if ( F_88 ( V_87 -> V_84 ) ||
F_89 ( V_87 -> V_84 ) ||
F_90 ( V_87 -> V_84 ) )
goto V_188;
if ( V_87 -> V_215 == 0 &&
( F_88 ( V_87 -> V_57 ) ||
F_89 ( V_87 -> V_57 ) ) ) {
V_324 = F_236 ( V_37 , V_87 -> V_84 , false ) ;
if ( ! V_324 )
goto V_188;
V_87 -> V_215 = V_324 -> V_103 ;
goto V_335;
}
if ( ! ( V_87 -> V_314 & V_336 ) ) {
if ( ! F_236 ( V_37 , V_87 -> V_84 , false ) )
goto V_188;
}
}
if ( V_87 -> V_215 ) {
V_324 = F_237 ( V_37 , V_87 -> V_215 ) ;
V_51 = F_230 ( - V_337 ) ;
if ( ! V_324 )
goto V_188;
if ( ! ( V_324 -> V_225 & V_338 ) || ! F_86 ( V_324 ) ) {
V_51 = F_230 ( - V_191 ) ;
goto V_188;
}
if ( F_187 ( V_87 -> V_57 ) ||
F_89 ( V_87 -> V_57 ) ||
V_87 -> V_326 == V_339 ) {
if ( ! V_87 -> V_84 )
V_87 -> V_84 = F_153 ( V_324 , 0 ,
V_242 ) ;
goto V_335;
}
if ( ! V_87 -> V_84 ) {
if ( F_88 ( V_87 -> V_57 ) )
V_87 -> V_84 = F_153 ( V_324 , 0 ,
V_87 -> V_313 ) ;
else if ( ! V_87 -> V_57 )
V_87 -> V_84 = F_153 ( V_324 , 0 ,
V_340 ) ;
}
}
if ( ! V_87 -> V_57 ) {
V_87 -> V_57 = V_87 -> V_84 ;
if ( ! V_87 -> V_57 )
V_87 -> V_57 = V_87 -> V_84 = F_238 ( V_341 ) ;
V_324 = V_37 -> V_235 ;
V_87 -> V_215 = V_333 ;
V_159 . type = V_318 ;
V_225 |= V_68 ;
goto V_335;
}
V_261 = F_98 ( V_37 , V_87 , & V_159 , 0 ) ;
if ( V_261 ) {
V_159 . V_237 = NULL ;
V_159 . V_285 = NULL ;
if ( V_87 -> V_215 &&
( F_88 ( V_87 -> V_57 ) ||
! F_239 ( V_37 , V_87 -> V_215 ) ) ) {
if ( V_87 -> V_84 == 0 )
V_87 -> V_84 = F_153 ( V_324 , 0 ,
V_242 ) ;
V_159 . type = V_166 ;
goto V_335;
}
V_51 = F_230 ( V_261 ) ;
goto V_188;
}
if ( V_159 . type == V_318 ) {
if ( ! V_87 -> V_84 ) {
if ( V_159 . V_237 -> V_342 )
V_87 -> V_84 = V_159 . V_237 -> V_342 ;
else
V_87 -> V_84 = V_87 -> V_57 ;
}
V_324 = F_225 ( F_208 ( V_159 ) ) ? :
V_37 -> V_235 ;
V_87 -> V_215 = V_324 -> V_103 ;
V_225 |= V_68 ;
goto V_335;
}
F_240 ( V_37 , & V_159 , V_87 , V_332 ) ;
V_324 = F_208 ( V_159 ) ;
V_87 -> V_215 = V_324 -> V_103 ;
V_335:
V_51 = F_229 ( & V_159 , V_87 , V_323 , V_324 , V_225 ) ;
V_188:
F_66 () ;
return V_51 ;
}
static struct V_1 * F_241 ( struct V_1 * V_2 , T_1 V_210 )
{
return NULL ;
}
static unsigned int F_242 ( const struct V_1 * V_2 )
{
unsigned int V_201 = F_156 ( V_2 , V_202 ) ;
return V_201 ? : V_2 -> V_53 -> V_201 ;
}
static void F_243 ( struct V_1 * V_2 , struct V_88 * V_89 ,
struct V_55 * V_56 , T_1 V_201 )
{
}
static void F_244 ( struct V_1 * V_2 , struct V_88 * V_89 ,
struct V_55 * V_56 )
{
}
static T_1 * F_245 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
return NULL ;
}
struct V_1 * F_246 ( struct V_37 * V_37 , struct V_1 * V_343 )
{
struct V_50 * V_344 = (struct V_50 * ) V_343 ;
struct V_50 * V_60 ;
V_60 = F_182 ( & V_345 , NULL , 1 , V_346 , 0 ) ;
if ( V_60 ) {
struct V_1 * V_78 = & V_60 -> V_2 ;
V_78 -> V_347 = 1 ;
V_78 -> V_258 = V_348 ;
V_78 -> V_256 = V_349 ;
V_78 -> V_53 = V_344 -> V_2 . V_53 ;
if ( V_78 -> V_53 )
F_174 ( V_78 -> V_53 ) ;
V_60 -> V_253 = V_344 -> V_253 ;
V_60 -> V_254 = V_344 -> V_254 ;
V_60 -> V_125 = V_344 -> V_125 ;
V_60 -> V_52 = F_34 ( V_37 ) ;
V_60 -> V_65 = V_344 -> V_65 ;
V_60 -> V_252 = V_344 -> V_252 ;
V_60 -> V_62 = V_344 -> V_62 ;
V_60 -> V_131 = V_344 -> V_131 ;
F_183 ( & V_60 -> V_233 ) ;
F_247 ( V_78 ) ;
}
F_140 ( V_343 ) ;
return V_60 ? & V_60 -> V_2 : F_230 ( - V_32 ) ;
}
struct V_50 * F_138 ( struct V_37 * V_37 , struct V_86 * V_350 ,
const struct V_88 * V_89 )
{
struct V_50 * V_60 = F_130 ( V_37 , V_350 ) ;
if ( F_96 ( V_60 ) )
return V_60 ;
if ( V_350 -> V_326 )
V_60 = (struct V_50 * ) F_248 ( V_37 , & V_60 -> V_2 ,
F_249 ( V_350 ) ,
V_89 , 0 ) ;
return V_60 ;
}
static int F_250 ( struct V_37 * V_37 , T_6 V_2 , T_6 V_28 , T_1 V_351 ,
struct V_86 * V_87 , struct V_55 * V_56 , T_1 V_352 ,
T_1 V_5 , int V_353 )
{
struct V_50 * V_60 = F_109 ( V_56 ) ;
struct V_354 * V_355 ;
struct V_356 * V_357 ;
unsigned long V_127 = 0 ;
T_1 error ;
T_1 V_358 [ V_359 ] ;
V_357 = F_251 ( V_56 , V_352 , V_5 , V_353 , sizeof( * V_355 ) , 0 ) ;
if ( ! V_357 )
return - V_360 ;
V_355 = F_252 ( V_357 ) ;
V_355 -> V_361 = V_362 ;
V_355 -> V_363 = 32 ;
V_355 -> V_364 = 0 ;
V_355 -> V_365 = V_87 -> V_214 ;
V_355 -> V_366 = V_351 < 256 ? V_351 : V_367 ;
if ( F_253 ( V_56 , V_368 , V_351 ) )
goto V_369;
V_355 -> V_370 = V_60 -> V_252 ;
V_355 -> V_371 = V_102 ;
V_355 -> V_372 = V_373 ;
V_355 -> V_374 = ( V_60 -> V_65 & ~ 0xFFFF ) | V_375 ;
if ( V_60 -> V_65 & V_376 )
V_355 -> V_374 |= V_377 ;
if ( F_212 ( V_56 ) -> V_225 & V_282 )
V_355 -> V_374 |= V_378 ;
if ( F_254 ( V_56 , V_379 , V_2 ) )
goto V_369;
if ( V_28 ) {
V_355 -> V_364 = 32 ;
if ( F_254 ( V_56 , V_380 , V_28 ) )
goto V_369;
}
if ( V_60 -> V_2 . V_53 &&
F_253 ( V_56 , V_381 , V_60 -> V_2 . V_53 -> V_103 ) )
goto V_369;
#ifdef F_28
if ( V_60 -> V_2 . V_218 &&
F_253 ( V_56 , V_382 , V_60 -> V_2 . V_218 ) )
goto V_369;
#endif
if ( ! F_164 ( V_60 ) &&
V_87 -> V_84 != V_28 ) {
if ( F_254 ( V_56 , V_383 , V_87 -> V_84 ) )
goto V_369;
}
if ( V_60 -> V_131 &&
F_254 ( V_56 , V_384 , V_60 -> V_62 ) )
goto V_369;
V_127 = V_60 -> V_2 . V_127 ;
if ( V_127 ) {
unsigned long V_76 = V_77 ;
if ( F_73 ( V_76 , V_127 ) )
V_127 -= V_76 ;
else
V_127 = 0 ;
}
memcpy ( V_358 , F_255 ( & V_60 -> V_2 ) , sizeof( V_358 ) ) ;
if ( V_60 -> V_125 && V_127 )
V_358 [ V_202 - 1 ] = V_60 -> V_125 ;
if ( F_256 ( V_56 , V_358 ) < 0 )
goto V_369;
if ( V_87 -> V_205 &&
F_253 ( V_56 , V_385 , V_87 -> V_205 ) )
goto V_369;
if ( ! F_257 ( V_87 -> V_315 , V_386 ) &&
F_253 ( V_56 , V_387 ,
F_258 ( F_259 () , V_87 -> V_315 ) ) )
goto V_369;
error = V_60 -> V_2 . error ;
if ( F_164 ( V_60 ) ) {
#ifdef F_190
if ( F_88 ( V_2 ) && ! F_187 ( V_2 ) &&
F_260 ( V_37 , V_388 ) ) {
int V_261 = F_261 ( V_37 , V_56 ,
V_87 -> V_84 , V_87 -> V_57 ,
V_355 , V_352 ) ;
if ( V_261 <= 0 ) {
if ( V_261 == 0 )
return 0 ;
goto V_369;
}
} else
#endif
if ( F_253 ( V_56 , V_389 , V_56 -> V_53 -> V_103 ) )
goto V_369;
}
if ( F_262 ( V_56 , & V_60 -> V_2 , 0 , V_127 , error ) < 0 )
goto V_369;
F_263 ( V_56 , V_357 ) ;
return 0 ;
V_369:
F_264 ( V_56 , V_357 ) ;
return - V_360 ;
}
static int F_265 ( struct V_55 * V_390 , struct V_356 * V_357 )
{
struct V_37 * V_37 = F_132 ( V_390 -> V_89 ) ;
struct V_354 * V_391 ;
struct V_392 * V_393 [ V_394 + 1 ] ;
struct V_50 * V_60 = NULL ;
struct V_86 V_87 ;
T_6 V_2 = 0 ;
T_6 V_28 = 0 ;
T_1 V_395 ;
int V_261 ;
int V_93 ;
struct V_55 * V_56 ;
T_1 V_351 = V_396 ;
T_14 V_397 ;
V_261 = F_266 ( V_357 , sizeof( * V_391 ) , V_393 , V_394 , V_398 ) ;
if ( V_261 < 0 )
goto V_399;
V_391 = F_252 ( V_357 ) ;
V_56 = F_267 ( V_400 , V_31 ) ;
if ( ! V_56 ) {
V_261 = - V_269 ;
goto V_399;
}
F_268 ( V_56 ) ;
F_269 ( V_56 ) ;
F_39 ( V_56 ) -> V_85 = V_401 ;
F_270 ( V_56 , V_402 + sizeof( struct V_80 ) ) ;
V_28 = V_393 [ V_380 ] ? F_271 ( V_393 [ V_380 ] ) : 0 ;
V_2 = V_393 [ V_379 ] ? F_271 ( V_393 [ V_379 ] ) : 0 ;
V_395 = V_393 [ V_389 ] ? F_272 ( V_393 [ V_389 ] ) : 0 ;
V_93 = V_393 [ V_385 ] ? F_272 ( V_393 [ V_385 ] ) : 0 ;
if ( V_393 [ V_387 ] )
V_397 = F_273 ( F_259 () , F_272 ( V_393 [ V_387 ] ) ) ;
else
V_397 = ( V_395 ? V_386 : F_274 () ) ;
memset ( & V_87 , 0 , sizeof( V_87 ) ) ;
V_87 . V_57 = V_2 ;
V_87 . V_84 = V_28 ;
V_87 . V_214 = V_391 -> V_365 ;
V_87 . V_215 = V_393 [ V_381 ] ? F_272 ( V_393 [ V_381 ] ) : 0 ;
V_87 . V_205 = V_93 ;
V_87 . V_315 = V_397 ;
if ( V_395 ) {
struct V_58 * V_53 ;
V_53 = F_275 ( V_37 , V_395 ) ;
if ( ! V_53 ) {
V_261 = - V_337 ;
goto V_403;
}
V_56 -> V_85 = F_54 ( V_262 ) ;
V_56 -> V_53 = V_53 ;
V_56 -> V_93 = V_93 ;
V_261 = F_276 ( V_56 , V_2 , V_28 , V_391 -> V_365 , V_53 ) ;
V_60 = F_109 ( V_56 ) ;
if ( V_261 == 0 && V_60 -> V_2 . error )
V_261 = - V_60 -> V_2 . error ;
} else {
V_60 = F_277 ( V_37 , & V_87 ) ;
V_261 = 0 ;
if ( F_96 ( V_60 ) )
V_261 = F_278 ( V_60 ) ;
}
if ( V_261 )
goto V_403;
F_193 ( V_56 , & V_60 -> V_2 ) ;
if ( V_391 -> V_374 & V_377 )
V_60 -> V_65 |= V_376 ;
if ( V_391 -> V_374 & V_404 )
V_351 = V_60 -> V_255 ;
V_261 = F_250 ( V_37 , V_2 , V_28 , V_351 , & V_87 , V_56 ,
F_279 ( V_390 ) . V_352 , V_357 -> V_405 ,
V_406 ) ;
if ( V_261 < 0 )
goto V_403;
V_261 = F_280 ( V_56 , V_37 , F_279 ( V_390 ) . V_352 ) ;
V_399:
return V_261 ;
V_403:
F_123 ( V_56 ) ;
goto V_399;
}
void F_281 ( struct V_156 * V_157 )
{
F_36 ( F_35 ( V_157 -> V_53 ) ) ;
}
static int F_282 ( struct V_407 * V_408 , int V_409 ,
void T_15 * V_410 ,
T_16 * V_411 , T_2 * V_412 )
{
struct V_37 * V_37 = (struct V_37 * ) V_408 -> V_413 ;
if ( V_409 ) {
F_36 ( V_37 ) ;
F_283 ( V_37 ) ;
return 0 ;
}
return - V_193 ;
}
static T_3 int F_284 ( struct V_37 * V_37 )
{
struct V_407 * V_414 ;
V_414 = V_415 ;
if ( ! F_285 ( V_37 , & V_416 ) ) {
V_414 = F_286 ( V_414 , sizeof( V_415 ) , V_31 ) ;
if ( ! V_414 )
goto V_417;
if ( V_37 -> V_418 != & V_419 )
V_414 [ 0 ] . V_420 = NULL ;
}
V_414 [ 0 ] . V_413 = V_37 ;
V_37 -> V_178 . V_421 = F_287 ( V_37 , L_19 , V_414 ) ;
if ( ! V_37 -> V_178 . V_421 )
goto V_422;
return 0 ;
V_422:
if ( V_414 != V_415 )
F_23 ( V_414 ) ;
V_417:
return - V_32 ;
}
static T_4 void F_288 ( struct V_37 * V_37 )
{
struct V_407 * V_414 ;
V_414 = V_37 -> V_178 . V_421 -> V_423 ;
F_289 ( V_37 -> V_178 . V_421 ) ;
F_290 ( V_414 == V_415 ) ;
F_23 ( V_414 ) ;
}
static T_3 int F_291 ( struct V_37 * V_37 )
{
F_292 ( & V_37 -> V_178 . V_52 , 0 ) ;
F_292 ( & V_37 -> V_144 , 0 ) ;
F_293 ( & V_37 -> V_178 . V_424 ,
sizeof( V_37 -> V_178 . V_424 ) ) ;
return 0 ;
}
static int T_3 F_294 ( struct V_37 * V_37 )
{
struct V_425 * V_426 = F_295 ( sizeof( * V_426 ) , V_31 ) ;
if ( ! V_426 )
return - V_32 ;
F_296 ( V_426 ) ;
V_37 -> V_178 . V_179 = V_426 ;
return 0 ;
}
static void T_4 F_297 ( struct V_37 * V_37 )
{
struct V_425 * V_426 = V_37 -> V_178 . V_179 ;
V_37 -> V_178 . V_179 = NULL ;
F_298 ( V_426 ) ;
F_23 ( V_426 ) ;
}
int T_5 F_299 ( void )
{
int V_427 = 0 ;
int V_12 ;
V_75 = F_295 ( V_73 * sizeof( * V_75 ) , V_31 ) ;
if ( ! V_75 )
F_300 ( L_20 ) ;
F_301 ( V_75 , V_73 * sizeof( * V_75 ) ) ;
V_72 = F_19 ( V_73 , sizeof( * V_72 ) , V_31 ) ;
if ( ! V_72 )
F_300 ( L_21 ) ;
F_20 (cpu) {
struct V_229 * V_230 = & F_12 ( V_231 , V_12 ) ;
F_183 ( & V_230 -> V_234 ) ;
F_302 ( & V_230 -> V_232 ) ;
}
#ifdef F_28
V_27 = F_303 ( 256 * sizeof( struct V_27 ) , F_304 ( struct V_27 ) ) ;
if ( ! V_27 )
F_300 ( L_22 ) ;
#endif
V_16 . V_428 =
F_305 ( L_23 , sizeof( struct V_50 ) , 0 ,
V_429 | V_430 , NULL ) ;
V_345 . V_428 = V_16 . V_428 ;
if ( F_306 ( & V_16 ) < 0 )
F_300 ( L_24 ) ;
if ( F_306 ( & V_345 ) < 0 )
F_300 ( L_25 ) ;
V_16 . V_431 = ~ 0 ;
V_432 = V_433 ;
F_307 () ;
F_308 () ;
if ( F_31 () )
F_309 ( L_26 ) ;
#ifdef F_310
F_311 () ;
F_312 () ;
#endif
F_313 ( V_434 , V_435 , F_265 , NULL , NULL ) ;
#ifdef F_314
F_32 ( & V_436 ) ;
#endif
F_32 ( & V_437 ) ;
F_32 ( & V_438 ) ;
return V_427 ;
}
void T_5 F_315 ( void )
{
F_287 ( & V_416 , L_19 , V_439 ) ;
}
