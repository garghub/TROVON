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
unsigned int V_219 = sizeof( struct V_220 ) + sizeof( struct V_80 ) ;
unsigned int V_221 = F_156 (unsigned int, dst->dev->mtu - header_size,
ip_rt_min_advmss) ;
return F_157 ( V_221 , V_222 - V_219 ) ;
}
static unsigned int F_126 ( const struct V_1 * V_2 )
{
const struct V_50 * V_60 = ( const struct V_50 * ) V_2 ;
unsigned int V_201 = V_60 -> V_125 ;
if ( ! V_201 || F_158 ( V_77 , V_60 -> V_2 . V_127 ) )
V_201 = F_159 ( V_2 , V_202 ) ;
if ( V_201 )
return V_201 ;
V_201 = V_2 -> V_53 -> V_201 ;
if ( F_160 ( F_125 ( V_2 , V_202 ) ) ) {
if ( V_60 -> V_131 && V_201 > 576 )
V_201 = 576 ;
}
V_201 = F_161 (unsigned int, mtu, IP_MAX_MTU) ;
return V_201 - F_162 ( V_2 -> V_223 , V_201 ) ;
}
static struct V_114 * F_163 ( struct V_132 * V_133 , T_6 V_57 )
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
static bool F_164 ( struct V_50 * V_60 , struct V_114 * V_115 ,
T_6 V_57 )
{
bool V_173 = false ;
F_79 ( & V_137 ) ;
if ( V_57 == V_115 -> V_142 ) {
struct V_50 T_11 * * V_224 ;
struct V_50 * V_225 ;
int V_226 = V_144 ( F_35 ( V_60 -> V_2 . V_53 ) ) ;
if ( F_165 ( V_60 ) )
V_224 = & V_115 -> V_116 ;
else
V_224 = & V_115 -> V_117 ;
V_225 = F_64 ( * V_224 ) ;
if ( V_115 -> V_144 != V_226 ) {
V_115 -> V_144 = V_226 ;
V_115 -> V_129 = 0 ;
V_115 -> V_126 = 0 ;
V_115 -> V_128 = 0 ;
F_70 ( V_115 ) ;
V_225 = NULL ;
}
F_77 ( V_60 , V_115 ) ;
if ( ! V_60 -> V_62 )
V_60 -> V_62 = V_57 ;
if ( ! ( V_60 -> V_2 . V_227 & V_228 ) ) {
F_81 ( * V_224 , V_60 ) ;
if ( V_225 )
F_68 ( V_225 ) ;
V_173 = true ;
}
V_115 -> V_122 = V_77 ;
}
F_83 ( & V_137 ) ;
return V_173 ;
}
static bool F_166 ( struct V_132 * V_133 , struct V_50 * V_60 )
{
struct V_50 * V_225 , * V_229 , * * V_230 ;
bool V_173 = true ;
if ( F_165 ( V_60 ) ) {
V_230 = (struct V_50 * * ) & V_133 -> V_146 ;
} else {
V_230 = (struct V_50 * * ) F_167 ( V_133 -> V_150 ) ;
}
V_225 = * V_230 ;
V_229 = F_46 ( V_230 , V_225 , V_60 ) ;
if ( V_229 == V_225 ) {
if ( V_225 )
F_68 ( V_225 ) ;
} else
V_173 = false ;
return V_173 ;
}
static void F_168 ( struct V_50 * V_60 )
{
struct V_231 * V_232 = F_167 ( & V_233 ) ;
V_60 -> V_233 = V_232 ;
F_79 ( & V_232 -> V_234 ) ;
F_169 ( & V_60 -> V_235 , & V_232 -> V_236 ) ;
F_83 ( & V_232 -> V_234 ) ;
}
static void F_170 ( struct V_1 * V_2 )
{
struct V_237 * V_230 = (struct V_237 * ) F_171 ( V_2 ) ;
struct V_50 * V_60 = (struct V_50 * ) V_2 ;
if ( V_230 != & V_238 && F_172 ( & V_230 -> V_239 ) )
F_23 ( V_230 ) ;
if ( ! F_173 ( & V_60 -> V_235 ) ) {
struct V_231 * V_232 = V_60 -> V_233 ;
F_79 ( & V_232 -> V_234 ) ;
F_174 ( & V_60 -> V_235 ) ;
F_83 ( & V_232 -> V_234 ) ;
}
}
void F_175 ( struct V_58 * V_53 )
{
struct V_37 * V_37 = F_35 ( V_53 ) ;
struct V_50 * V_60 ;
int V_12 ;
F_20 (cpu) {
struct V_231 * V_232 = & F_12 ( V_233 , V_12 ) ;
F_79 ( & V_232 -> V_234 ) ;
F_176 (rt, &ul->head, rt_uncached) {
if ( V_60 -> V_2 . V_53 != V_53 )
continue;
V_60 -> V_2 . V_53 = V_37 -> V_240 ;
F_177 ( V_60 -> V_2 . V_53 ) ;
F_178 ( V_53 ) ;
}
F_83 ( & V_232 -> V_234 ) ;
}
}
static bool F_179 ( const struct V_50 * V_60 )
{
return V_60 &&
V_60 -> V_2 . V_147 == V_211 &&
! F_33 ( V_60 ) ;
}
static void F_180 ( struct V_50 * V_60 , T_6 V_57 ,
const struct V_158 * V_159 ,
struct V_114 * V_115 ,
struct V_241 * V_242 , T_12 type , T_1 V_243 )
{
bool V_244 = false ;
if ( V_242 ) {
struct V_132 * V_133 = & F_99 ( * V_159 ) ;
if ( V_133 -> V_245 && V_133 -> V_246 == V_247 ) {
V_60 -> V_62 = V_133 -> V_245 ;
V_60 -> V_131 = 1 ;
}
F_181 ( & V_60 -> V_2 , V_242 -> V_248 -> V_249 , true ) ;
if ( V_242 -> V_248 != & V_238 ) {
V_60 -> V_2 . V_250 |= V_251 ;
F_182 ( & V_242 -> V_248 -> V_239 ) ;
}
#ifdef F_28
V_60 -> V_2 . V_218 = V_133 -> V_252 ;
#endif
V_60 -> V_2 . V_223 = F_183 ( V_133 -> V_253 ) ;
if ( F_160 ( V_115 ) )
V_244 = F_164 ( V_60 , V_115 , V_57 ) ;
else if ( ! ( V_60 -> V_2 . V_227 & V_228 ) )
V_244 = F_166 ( V_133 , V_60 ) ;
if ( F_160 ( ! V_244 ) ) {
V_60 -> V_2 . V_227 |= V_228 ;
if ( ! V_60 -> V_62 )
V_60 -> V_62 = V_57 ;
F_168 ( V_60 ) ;
}
} else
F_168 ( V_60 ) ;
#ifdef F_28
#ifdef F_184
F_154 ( V_60 , V_159 -> V_218 ) ;
#endif
F_154 ( V_60 , V_243 ) ;
#endif
}
struct V_50 * F_185 ( struct V_58 * V_53 ,
unsigned int V_227 , T_12 type ,
bool V_254 , bool V_255 , bool V_256 )
{
struct V_50 * V_60 ;
V_60 = F_186 ( & V_16 , V_53 , 1 , V_211 ,
( V_256 ? 0 : ( V_257 | V_228 ) ) |
( V_254 ? V_258 : 0 ) |
( V_255 ? V_259 : 0 ) ) ;
if ( V_60 ) {
V_60 -> V_52 = F_34 ( F_35 ( V_53 ) ) ;
V_60 -> V_65 = V_227 ;
V_60 -> V_260 = type ;
V_60 -> V_261 = 0 ;
V_60 -> V_262 = 0 ;
V_60 -> V_125 = 0 ;
V_60 -> V_62 = 0 ;
V_60 -> V_131 = 0 ;
V_60 -> V_263 = 0 ;
F_187 ( & V_60 -> V_235 ) ;
V_60 -> V_2 . V_264 = V_265 ;
if ( V_227 & V_68 )
V_60 -> V_2 . V_266 = V_267 ;
}
return V_60 ;
}
static int F_188 ( struct V_55 * V_56 , T_6 V_57 , T_6 V_84 ,
T_9 V_91 , struct V_58 * V_53 , int V_268 )
{
struct V_50 * V_51 ;
struct V_156 * V_157 = F_86 ( V_53 ) ;
unsigned int V_227 = V_66 ;
T_1 V_243 = 0 ;
int V_269 ;
if ( ! V_157 )
return - V_193 ;
if ( F_88 ( V_84 ) || F_89 ( V_84 ) ||
V_56 -> V_85 != F_54 ( V_270 ) )
goto V_271;
if ( F_189 ( V_84 ) && ! F_190 ( V_157 ) )
goto V_271;
if ( F_90 ( V_84 ) ) {
if ( ! F_191 ( V_57 ) )
goto V_271;
} else {
V_269 = F_192 ( V_56 , V_84 , 0 , V_91 , 0 , V_53 ,
V_157 , & V_243 ) ;
if ( V_269 < 0 )
goto V_272;
}
if ( V_268 )
V_227 |= V_68 ;
V_51 = F_185 ( F_35 ( V_53 ) -> V_240 , V_227 , V_273 ,
F_193 ( V_157 , V_274 ) , false , false ) ;
if ( ! V_51 )
goto V_275;
#ifdef F_28
V_51 -> V_2 . V_218 = V_243 ;
#endif
V_51 -> V_2 . V_264 = F_148 ;
V_51 -> V_261 = 1 ;
#ifdef F_194
if ( ! F_191 ( V_57 ) && F_195 ( V_157 ) )
V_51 -> V_2 . V_266 = V_276 ;
#endif
F_196 ( V_18 ) ;
F_197 ( V_56 , & V_51 -> V_2 ) ;
return 0 ;
V_275:
return - V_277 ;
V_271:
return - V_193 ;
V_272:
return V_269 ;
}
static void F_198 ( struct V_58 * V_53 ,
struct V_156 * V_157 ,
struct V_55 * V_56 ,
T_6 V_57 ,
T_6 V_84 )
{
F_196 ( V_22 ) ;
#ifdef F_102
if ( F_103 ( V_157 ) && F_199 () ) {
F_200 ( L_15 ,
& V_57 , & V_84 , V_53 -> V_172 ) ;
if ( V_53 -> V_278 && F_201 ( V_56 ) ) {
F_202 ( V_279 , L_16 ,
V_280 , 16 , 1 ,
F_203 ( V_56 ) ,
V_53 -> V_278 , true ) ;
}
}
#endif
}
static void F_204 ( struct V_132 * V_133 , T_6 V_57 )
{
struct V_118 * V_69 ;
struct V_114 * V_115 , T_11 * * V_281 ;
T_1 V_123 = F_74 ( V_57 ) ;
F_79 ( & V_137 ) ;
V_69 = F_205 ( V_133 -> V_138 ,
F_206 ( & V_137 ) ) ;
V_69 += V_123 ;
V_281 = & V_69 -> V_120 ;
V_115 = F_205 ( * V_281 , F_206 ( & V_137 ) ) ;
while ( V_115 ) {
if ( V_115 -> V_142 == V_57 ) {
F_81 ( * V_281 , F_205 (
V_115 -> V_121 , F_206 ( & V_137 ) ) ) ;
F_70 ( V_115 ) ;
F_207 ( V_115 , V_282 ) ;
break;
}
V_281 = & V_115 -> V_121 ;
V_115 = F_205 ( V_115 -> V_121 ,
F_206 ( & V_137 ) ) ;
}
F_83 ( & V_137 ) ;
}
static void F_208 ( struct V_50 * V_51 )
{
if ( F_209 ( V_51 -> V_2 . V_223 ) ) {
V_51 -> V_2 . V_223 -> V_283 = V_51 -> V_2 . V_264 ;
V_51 -> V_2 . V_264 = V_284 ;
}
if ( F_210 ( V_51 -> V_2 . V_223 ) ) {
V_51 -> V_2 . V_223 -> V_285 = V_51 -> V_2 . V_266 ;
V_51 -> V_2 . V_266 = V_286 ;
}
}
static int F_211 ( struct V_55 * V_56 ,
const struct V_158 * V_159 ,
struct V_156 * V_157 ,
T_6 V_57 , T_6 V_84 , T_1 V_91 )
{
struct V_114 * V_115 ;
struct V_50 * V_51 ;
int V_269 ;
struct V_156 * V_287 ;
bool V_288 ;
T_1 V_243 = 0 ;
V_287 = F_86 ( F_212 ( * V_159 ) ) ;
if ( ! V_287 ) {
F_213 ( L_17 ) ;
return - V_193 ;
}
V_269 = F_192 ( V_56 , V_84 , V_57 , V_91 , F_214 ( * V_159 ) ,
V_157 -> V_53 , V_157 , & V_243 ) ;
if ( V_269 < 0 ) {
F_198 ( V_157 -> V_53 , V_157 , V_56 , V_57 ,
V_84 ) ;
goto V_289;
}
V_288 = V_159 -> V_242 && ! V_243 ;
if ( V_287 == V_157 && V_269 && F_110 ( V_287 ) &&
V_56 -> V_85 == F_54 ( V_270 ) &&
( F_91 ( V_287 ) ||
F_92 ( V_287 , V_84 , F_215 ( * V_159 ) ) ) )
F_216 ( V_56 ) -> V_227 |= V_290 ;
if ( V_56 -> V_85 != F_54 ( V_270 ) ) {
if ( V_287 == V_157 &&
F_217 ( V_157 ) == 0 ) {
V_269 = - V_193 ;
goto V_289;
}
}
V_115 = F_163 ( & F_99 ( * V_159 ) , V_57 ) ;
if ( V_288 ) {
if ( V_115 ) {
V_51 = F_64 ( V_115 -> V_116 ) ;
if ( V_51 && V_51 -> V_2 . V_127 &&
F_115 ( V_77 , V_51 -> V_2 . V_127 ) ) {
F_204 ( & F_99 ( * V_159 ) , V_57 ) ;
V_115 = NULL ;
} else {
goto V_291;
}
}
V_51 = F_64 ( F_99 ( * V_159 ) . V_146 ) ;
V_291:
if ( F_179 ( V_51 ) ) {
F_218 ( V_56 , & V_51 -> V_2 ) ;
goto V_188;
}
}
V_51 = F_185 ( V_287 -> V_53 , 0 , V_159 -> type ,
F_193 ( V_157 , V_274 ) ,
F_193 ( V_287 , V_292 ) , V_288 ) ;
if ( ! V_51 ) {
V_269 = - V_277 ;
goto V_289;
}
V_51 -> V_261 = 1 ;
if ( V_159 -> V_293 )
V_51 -> V_263 = V_159 -> V_293 -> V_294 ;
F_196 ( V_17 ) ;
V_51 -> V_2 . V_266 = V_295 ;
F_180 ( V_51 , V_57 , V_159 , V_115 , V_159 -> V_242 , V_159 -> type , V_243 ) ;
F_208 ( V_51 ) ;
F_197 ( V_56 , & V_51 -> V_2 ) ;
V_188:
V_269 = 0 ;
V_289:
return V_269 ;
}
static void F_219 ( const struct V_55 * V_56 ,
struct V_296 * V_297 )
{
const struct V_80 * V_298 = F_39 ( V_56 ) ;
const struct V_80 * V_299 ;
const struct V_300 * V_301 ;
struct V_80 V_302 ;
struct V_300 V_303 ;
V_297 -> V_304 . V_305 . V_28 = V_298 -> V_84 ;
V_297 -> V_304 . V_305 . V_2 = V_298 -> V_57 ;
if ( F_220 ( V_298 -> V_85 != V_306 ) )
return;
if ( F_160 ( ( V_298 -> V_307 & F_54 ( V_308 ) ) != 0 ) )
return;
V_301 = F_221 ( V_56 , V_298 -> V_309 * 4 , sizeof( V_303 ) ,
& V_303 ) ;
if ( ! V_301 )
return;
if ( V_301 -> type != V_200 &&
V_301 -> type != V_180 &&
V_301 -> type != V_310 &&
V_301 -> type != V_311 )
return;
V_299 = F_221 ( V_56 ,
V_298 -> V_309 * 4 + sizeof( V_303 ) ,
sizeof( V_302 ) , & V_302 ) ;
if ( ! V_299 )
return;
V_297 -> V_304 . V_305 . V_28 = V_299 -> V_84 ;
V_297 -> V_304 . V_305 . V_2 = V_299 -> V_57 ;
}
int F_222 ( const struct V_241 * V_242 , const struct V_86 * V_87 ,
const struct V_55 * V_56 )
{
struct V_37 * V_37 = V_242 -> V_312 ;
struct V_296 V_297 ;
T_1 V_313 ;
switch ( V_37 -> V_178 . V_314 ) {
case 0 :
memset ( & V_297 , 0 , sizeof( V_297 ) ) ;
V_297 . V_315 . V_316 = V_317 ;
if ( V_56 ) {
F_219 ( V_56 , & V_297 ) ;
} else {
V_297 . V_304 . V_305 . V_28 = V_87 -> V_84 ;
V_297 . V_304 . V_305 . V_2 = V_87 -> V_57 ;
}
break;
case 1 :
if ( V_56 ) {
unsigned int V_318 = V_319 ;
struct V_296 V_320 ;
if ( V_56 -> V_321 )
return F_223 ( V_56 ) >> 1 ;
memset ( & V_297 , 0 , sizeof( V_297 ) ) ;
F_224 ( V_56 , & V_320 , V_318 ) ;
V_297 . V_304 . V_305 . V_28 = V_320 . V_304 . V_305 . V_28 ;
V_297 . V_304 . V_305 . V_2 = V_320 . V_304 . V_305 . V_2 ;
V_297 . V_322 . V_28 = V_320 . V_322 . V_28 ;
V_297 . V_322 . V_2 = V_320 . V_322 . V_2 ;
V_297 . V_323 . V_324 = V_320 . V_323 . V_324 ;
} else {
memset ( & V_297 , 0 , sizeof( V_297 ) ) ;
V_297 . V_315 . V_316 = V_317 ;
V_297 . V_304 . V_305 . V_28 = V_87 -> V_84 ;
V_297 . V_304 . V_305 . V_2 = V_87 -> V_57 ;
V_297 . V_322 . V_28 = V_87 -> V_325 ;
V_297 . V_322 . V_2 = V_87 -> V_326 ;
V_297 . V_323 . V_324 = V_87 -> V_327 ;
}
break;
}
V_313 = F_225 ( & V_297 ) ;
return V_313 >> 1 ;
}
static int F_226 ( struct V_55 * V_56 ,
struct V_158 * V_159 ,
struct V_156 * V_157 ,
T_6 V_57 , T_6 V_84 , T_1 V_91 )
{
#ifdef F_227
if ( V_159 -> V_242 && V_159 -> V_242 -> V_328 > 1 ) {
int V_329 = F_222 ( V_159 -> V_242 , NULL , V_56 ) ;
F_228 ( V_159 , V_329 ) ;
}
#endif
return F_211 ( V_56 , V_159 , V_157 , V_57 , V_84 , V_91 ) ;
}
static int F_229 ( struct V_55 * V_56 , T_6 V_57 , T_6 V_84 ,
T_9 V_91 , struct V_58 * V_53 )
{
struct V_158 V_159 ;
struct V_156 * V_157 = F_86 ( V_53 ) ;
struct V_330 * V_331 ;
struct V_86 V_87 ;
unsigned int V_227 = 0 ;
T_1 V_243 = 0 ;
struct V_50 * V_51 ;
int V_269 = - V_193 ;
struct V_37 * V_37 = F_35 ( V_53 ) ;
bool V_288 ;
if ( ! V_157 )
goto V_188;
V_331 = F_230 ( V_56 ) ;
if ( V_331 && ! ( V_331 -> V_332 & V_333 ) )
V_87 . V_334 . V_335 = V_331 -> V_336 . V_335 ;
else
V_87 . V_334 . V_335 = 0 ;
F_231 ( V_56 ) ;
if ( F_88 ( V_84 ) || F_89 ( V_84 ) )
goto V_337;
V_159 . V_242 = NULL ;
V_159 . V_293 = NULL ;
if ( F_89 ( V_57 ) || ( V_84 == 0 && V_57 == 0 ) )
goto V_338;
if ( F_90 ( V_84 ) )
goto V_337;
if ( F_90 ( V_57 ) )
goto V_339;
if ( F_189 ( V_57 ) ) {
if ( ! F_232 ( V_157 , V_37 ) )
goto V_339;
} else if ( F_189 ( V_84 ) ) {
if ( ! F_232 ( V_157 , V_37 ) )
goto V_337;
}
V_87 . V_215 = 0 ;
V_87 . V_216 = V_53 -> V_103 ;
V_87 . V_205 = V_56 -> V_93 ;
V_87 . V_214 = V_91 ;
V_87 . V_340 = V_102 ;
V_87 . V_341 = 0 ;
V_87 . V_57 = V_57 ;
V_87 . V_84 = V_84 ;
V_87 . V_342 = F_59 ( V_37 , NULL ) ;
V_269 = F_98 ( V_37 , & V_87 , & V_159 , 0 ) ;
if ( V_269 != 0 ) {
if ( ! F_120 ( V_157 ) )
V_269 = - V_189 ;
goto V_343;
}
if ( V_159 . type == V_344 )
goto V_338;
if ( V_159 . type == V_345 ) {
V_269 = F_192 ( V_56 , V_84 , V_57 , V_91 ,
0 , V_53 , V_157 , & V_243 ) ;
if ( V_269 < 0 )
goto V_337;
goto V_346;
}
if ( ! F_120 ( V_157 ) ) {
V_269 = - V_189 ;
goto V_343;
}
if ( V_159 . type != V_166 )
goto V_339;
V_269 = F_226 ( V_56 , & V_159 , V_157 , V_57 , V_84 , V_91 ) ;
V_188: return V_269 ;
V_338:
if ( V_56 -> V_85 != F_54 ( V_270 ) )
goto V_271;
if ( ! F_90 ( V_84 ) ) {
V_269 = F_192 ( V_56 , V_84 , 0 , V_91 , 0 , V_53 ,
V_157 , & V_243 ) ;
if ( V_269 < 0 )
goto V_337;
}
V_227 |= V_67 ;
V_159 . type = V_344 ;
F_196 ( V_20 ) ;
V_346:
V_288 = false ;
if ( V_159 . V_242 ) {
if ( ! V_243 ) {
V_51 = F_64 ( F_99 ( V_159 ) . V_146 ) ;
if ( F_179 ( V_51 ) ) {
F_218 ( V_56 , & V_51 -> V_2 ) ;
V_269 = 0 ;
goto V_188;
}
V_288 = true ;
}
}
V_51 = F_185 ( F_233 ( V_53 ) ? : V_37 -> V_240 ,
V_227 | V_68 , V_159 . type ,
F_193 ( V_157 , V_274 ) , false , V_288 ) ;
if ( ! V_51 )
goto V_275;
V_51 -> V_2 . V_264 = F_148 ;
#ifdef F_28
V_51 -> V_2 . V_218 = V_243 ;
#endif
V_51 -> V_261 = 1 ;
if ( V_159 . V_293 )
V_51 -> V_263 = V_159 . V_293 -> V_294 ;
F_196 ( V_17 ) ;
if ( V_159 . type == V_347 ) {
V_51 -> V_2 . V_266 = F_119 ;
V_51 -> V_2 . error = - V_269 ;
V_51 -> V_65 &= ~ V_68 ;
}
if ( V_288 ) {
struct V_132 * V_133 = & F_99 ( V_159 ) ;
V_51 -> V_2 . V_223 = F_183 ( V_133 -> V_253 ) ;
if ( F_210 ( V_51 -> V_2 . V_223 ) ) {
F_2 ( V_51 -> V_2 . V_266 == V_286 ) ;
V_51 -> V_2 . V_223 -> V_285 = V_51 -> V_2 . V_266 ;
V_51 -> V_2 . V_266 = V_286 ;
}
if ( F_160 ( ! F_166 ( V_133 , V_51 ) ) ) {
V_51 -> V_2 . V_227 |= V_228 ;
F_168 ( V_51 ) ;
}
}
F_197 ( V_56 , & V_51 -> V_2 ) ;
V_269 = 0 ;
goto V_188;
V_343:
F_196 ( V_19 ) ;
V_159 . type = V_347 ;
V_159 . V_242 = NULL ;
V_159 . V_293 = NULL ;
goto V_346;
V_339:
F_196 ( V_21 ) ;
#ifdef F_102
if ( F_103 ( V_157 ) )
F_116 ( L_18 ,
& V_57 , & V_84 , V_53 -> V_172 ) ;
#endif
V_271:
V_269 = - V_193 ;
goto V_188;
V_275:
V_269 = - V_277 ;
goto V_188;
V_337:
F_198 ( V_53 , V_157 , V_56 , V_57 , V_84 ) ;
goto V_188;
}
int F_234 ( struct V_55 * V_56 , T_6 V_57 , T_6 V_84 ,
T_9 V_91 , struct V_58 * V_53 )
{
int V_159 ;
V_91 &= V_348 ;
F_63 () ;
if ( F_88 ( V_57 ) ) {
struct V_156 * V_157 = F_86 ( V_53 ) ;
int V_268 = 0 ;
if ( V_157 )
V_268 = F_235 ( V_157 , V_57 , V_84 ,
F_39 ( V_56 ) -> V_85 ) ;
if ( ( ! V_157 || ! V_268 ) && F_236 ( V_53 ) ) {
struct V_156 * V_349 ;
V_349 = F_86 ( V_56 -> V_53 ) ;
if ( V_349 )
V_268 = F_235 ( V_349 , V_57 , V_84 ,
F_39 ( V_56 ) -> V_85 ) ;
}
V_159 = - V_193 ;
if ( V_268
#ifdef F_194
||
( ! F_191 ( V_57 ) &&
F_195 ( V_157 ) )
#endif
) {
V_159 = F_188 ( V_56 , V_57 , V_84 ,
V_91 , V_53 , V_268 ) ;
}
F_66 () ;
return V_159 ;
}
V_159 = F_229 ( V_56 , V_57 , V_84 , V_91 , V_53 ) ;
F_66 () ;
return V_159 ;
}
static struct V_50 * F_237 ( const struct V_158 * V_159 ,
const struct V_86 * V_87 , int V_350 ,
struct V_58 * V_351 ,
unsigned int V_227 )
{
struct V_241 * V_242 = V_159 -> V_242 ;
struct V_114 * V_115 ;
struct V_156 * V_157 ;
T_12 type = V_159 -> type ;
struct V_50 * V_51 ;
bool V_288 ;
V_157 = F_86 ( V_351 ) ;
if ( ! V_157 )
return F_238 ( - V_193 ) ;
if ( F_220 ( ! F_190 ( V_157 ) ) )
if ( F_189 ( V_87 -> V_84 ) &&
! ( V_351 -> V_227 & V_352 ) &&
! F_239 ( V_351 ) )
return F_238 ( - V_193 ) ;
if ( F_89 ( V_87 -> V_57 ) )
type = V_344 ;
else if ( F_88 ( V_87 -> V_57 ) )
type = V_273 ;
else if ( F_90 ( V_87 -> V_57 ) )
return F_238 ( - V_193 ) ;
if ( V_351 -> V_227 & V_352 )
V_227 |= V_68 ;
V_288 = true ;
if ( type == V_344 ) {
V_227 |= V_67 | V_68 ;
V_242 = NULL ;
} else if ( type == V_273 ) {
V_227 |= V_66 | V_68 ;
if ( ! F_235 ( V_157 , V_87 -> V_57 , V_87 -> V_84 ,
V_87 -> V_327 ) )
V_227 &= ~ V_68 ;
else
V_288 = false ;
if ( V_242 && V_159 -> V_353 < 4 )
V_242 = NULL ;
} else if ( ( type == V_345 ) && ( V_350 != 0 ) &&
( V_350 != V_351 -> V_103 ) ) {
V_242 = NULL ;
}
V_115 = NULL ;
V_288 &= V_242 != NULL ;
if ( V_288 ) {
struct V_50 T_11 * * V_354 ;
struct V_132 * V_133 = & F_99 ( * V_159 ) ;
V_115 = F_163 ( V_133 , V_87 -> V_57 ) ;
if ( V_115 ) {
V_354 = & V_115 -> V_117 ;
V_51 = F_64 ( * V_354 ) ;
if ( V_51 && V_51 -> V_2 . V_127 &&
F_115 ( V_77 , V_51 -> V_2 . V_127 ) ) {
F_204 ( V_133 , V_87 -> V_57 ) ;
V_115 = NULL ;
} else {
goto V_291;
}
}
if ( F_160 ( V_87 -> V_341 &
V_355 &&
! ( V_133 -> V_245 &&
V_133 -> V_246 == V_247 ) ) ) {
V_288 = false ;
goto V_356;
}
V_354 = F_167 ( V_133 -> V_150 ) ;
V_51 = F_64 ( * V_354 ) ;
V_291:
if ( F_179 ( V_51 ) ) {
F_240 ( & V_51 -> V_2 ) ;
return V_51 ;
}
}
V_356:
V_51 = F_185 ( V_351 , V_227 , type ,
F_193 ( V_157 , V_274 ) ,
F_193 ( V_157 , V_292 ) ,
V_288 ) ;
if ( ! V_51 )
return F_238 ( - V_277 ) ;
V_51 -> V_262 = V_350 ? : 0 ;
if ( V_159 -> V_293 )
V_51 -> V_263 = V_159 -> V_293 -> V_294 ;
F_196 ( V_23 ) ;
if ( V_227 & ( V_67 | V_66 ) ) {
if ( V_227 & V_68 &&
! ( V_351 -> V_227 & V_352 ) ) {
V_51 -> V_2 . V_264 = V_357 ;
F_196 ( V_24 ) ;
}
#ifdef F_194
if ( type == V_273 ) {
if ( F_195 ( V_157 ) &&
! F_191 ( V_87 -> V_57 ) ) {
V_51 -> V_2 . V_266 = V_276 ;
V_51 -> V_2 . V_264 = V_357 ;
}
}
#endif
}
F_180 ( V_51 , V_87 -> V_57 , V_159 , V_115 , V_242 , type , 0 ) ;
F_208 ( V_51 ) ;
return V_51 ;
}
struct V_50 * F_241 ( struct V_37 * V_37 , struct V_86 * V_87 ,
const struct V_55 * V_56 )
{
struct V_58 * V_351 = NULL ;
T_13 V_91 = F_242 ( V_87 ) ;
unsigned int V_227 = 0 ;
struct V_158 V_159 ;
struct V_50 * V_51 ;
int V_350 ;
int V_269 = - V_191 ;
V_159 . V_218 = 0 ;
V_159 . V_242 = NULL ;
V_159 . V_293 = NULL ;
V_350 = V_87 -> V_215 ;
V_87 -> V_216 = V_358 ;
V_87 -> V_214 = V_91 & V_348 ;
V_87 -> V_340 = ( ( V_91 & V_359 ) ?
V_247 : V_102 ) ;
F_63 () ;
if ( V_87 -> V_84 ) {
V_51 = F_238 ( - V_193 ) ;
if ( F_88 ( V_87 -> V_84 ) ||
F_89 ( V_87 -> V_84 ) ||
F_90 ( V_87 -> V_84 ) )
goto V_188;
if ( V_87 -> V_215 == 0 &&
( F_88 ( V_87 -> V_57 ) ||
F_89 ( V_87 -> V_57 ) ) ) {
V_351 = F_243 ( V_37 , V_87 -> V_84 , false ) ;
if ( ! V_351 )
goto V_188;
V_87 -> V_215 = V_351 -> V_103 ;
goto V_360;
}
if ( ! ( V_87 -> V_341 & V_361 ) ) {
if ( ! F_243 ( V_37 , V_87 -> V_84 , false ) )
goto V_188;
}
}
if ( V_87 -> V_215 ) {
V_351 = F_244 ( V_37 , V_87 -> V_215 ) ;
V_51 = F_238 ( - V_362 ) ;
if ( ! V_351 )
goto V_188;
if ( ! ( V_351 -> V_227 & V_363 ) || ! F_86 ( V_351 ) ) {
V_51 = F_238 ( - V_191 ) ;
goto V_188;
}
if ( F_191 ( V_87 -> V_57 ) ||
F_89 ( V_87 -> V_57 ) ||
V_87 -> V_327 == V_364 ) {
if ( ! V_87 -> V_84 )
V_87 -> V_84 = F_153 ( V_351 , 0 ,
V_247 ) ;
goto V_360;
}
if ( ! V_87 -> V_84 ) {
if ( F_88 ( V_87 -> V_57 ) )
V_87 -> V_84 = F_153 ( V_351 , 0 ,
V_87 -> V_340 ) ;
else if ( ! V_87 -> V_57 )
V_87 -> V_84 = F_153 ( V_351 , 0 ,
V_365 ) ;
}
}
if ( ! V_87 -> V_57 ) {
V_87 -> V_57 = V_87 -> V_84 ;
if ( ! V_87 -> V_57 )
V_87 -> V_57 = V_87 -> V_84 = F_245 ( V_366 ) ;
V_351 = V_37 -> V_240 ;
V_87 -> V_215 = V_358 ;
V_159 . type = V_345 ;
V_227 |= V_68 ;
goto V_360;
}
V_269 = F_98 ( V_37 , V_87 , & V_159 , 0 ) ;
if ( V_269 ) {
V_159 . V_242 = NULL ;
V_159 . V_293 = NULL ;
if ( V_87 -> V_215 &&
( F_88 ( V_87 -> V_57 ) ||
! F_246 ( V_37 , V_87 -> V_215 ) ) ) {
if ( V_87 -> V_84 == 0 )
V_87 -> V_84 = F_153 ( V_351 , 0 ,
V_247 ) ;
V_159 . type = V_166 ;
goto V_360;
}
V_51 = F_238 ( V_269 ) ;
goto V_188;
}
if ( V_159 . type == V_345 ) {
if ( ! V_87 -> V_84 ) {
if ( V_159 . V_242 -> V_367 )
V_87 -> V_84 = V_159 . V_242 -> V_367 ;
else
V_87 -> V_84 = V_87 -> V_57 ;
}
V_351 = F_233 ( F_212 ( V_159 ) ) ? :
V_37 -> V_240 ;
V_87 -> V_215 = V_351 -> V_103 ;
V_227 |= V_68 ;
goto V_360;
}
F_247 ( V_37 , & V_159 , V_87 , V_56 ) ;
V_351 = F_212 ( V_159 ) ;
V_87 -> V_215 = V_351 -> V_103 ;
V_360:
V_51 = F_237 ( & V_159 , V_87 , V_350 , V_351 , V_227 ) ;
V_188:
F_66 () ;
return V_51 ;
}
static struct V_1 * F_248 ( struct V_1 * V_2 , T_1 V_210 )
{
return NULL ;
}
static unsigned int F_249 ( const struct V_1 * V_2 )
{
unsigned int V_201 = F_159 ( V_2 , V_202 ) ;
return V_201 ? : V_2 -> V_53 -> V_201 ;
}
static void F_250 ( struct V_1 * V_2 , struct V_88 * V_89 ,
struct V_55 * V_56 , T_1 V_201 )
{
}
static void F_251 ( struct V_1 * V_2 , struct V_88 * V_89 ,
struct V_55 * V_56 )
{
}
static T_1 * F_252 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
return NULL ;
}
struct V_1 * F_253 ( struct V_37 * V_37 , struct V_1 * V_368 )
{
struct V_50 * V_369 = (struct V_50 * ) V_368 ;
struct V_50 * V_60 ;
V_60 = F_186 ( & V_370 , NULL , 1 , V_371 , 0 ) ;
if ( V_60 ) {
struct V_1 * V_78 = & V_60 -> V_2 ;
V_78 -> V_372 = 1 ;
V_78 -> V_266 = V_373 ;
V_78 -> V_264 = V_374 ;
V_78 -> V_53 = V_369 -> V_2 . V_53 ;
if ( V_78 -> V_53 )
F_177 ( V_78 -> V_53 ) ;
V_60 -> V_261 = V_369 -> V_261 ;
V_60 -> V_262 = V_369 -> V_262 ;
V_60 -> V_125 = V_369 -> V_125 ;
V_60 -> V_52 = F_34 ( V_37 ) ;
V_60 -> V_65 = V_369 -> V_65 ;
V_60 -> V_260 = V_369 -> V_260 ;
V_60 -> V_62 = V_369 -> V_62 ;
V_60 -> V_131 = V_369 -> V_131 ;
F_187 ( & V_60 -> V_235 ) ;
F_254 ( V_78 ) ;
}
F_140 ( V_368 ) ;
return V_60 ? & V_60 -> V_2 : F_238 ( - V_32 ) ;
}
struct V_50 * F_138 ( struct V_37 * V_37 , struct V_86 * V_375 ,
const struct V_88 * V_89 )
{
struct V_50 * V_60 = F_130 ( V_37 , V_375 ) ;
if ( F_96 ( V_60 ) )
return V_60 ;
if ( V_375 -> V_327 )
V_60 = (struct V_50 * ) F_255 ( V_37 , & V_60 -> V_2 ,
F_256 ( V_375 ) ,
V_89 , 0 ) ;
return V_60 ;
}
static int F_257 ( struct V_37 * V_37 , T_6 V_2 , T_6 V_28 , T_1 V_376 ,
struct V_86 * V_87 , struct V_55 * V_56 , T_1 V_377 ,
T_1 V_5 , int V_378 )
{
struct V_50 * V_60 = F_109 ( V_56 ) ;
struct V_379 * V_380 ;
struct V_381 * V_382 ;
unsigned long V_127 = 0 ;
T_1 error ;
T_1 V_249 [ V_383 ] ;
V_382 = F_258 ( V_56 , V_377 , V_5 , V_378 , sizeof( * V_380 ) , 0 ) ;
if ( ! V_382 )
return - V_384 ;
V_380 = F_259 ( V_382 ) ;
V_380 -> V_385 = V_386 ;
V_380 -> V_387 = 32 ;
V_380 -> V_388 = 0 ;
V_380 -> V_389 = V_87 -> V_214 ;
V_380 -> V_390 = V_376 < 256 ? V_376 : V_391 ;
if ( F_260 ( V_56 , V_392 , V_376 ) )
goto V_393;
V_380 -> V_394 = V_60 -> V_260 ;
V_380 -> V_395 = V_102 ;
V_380 -> V_396 = V_397 ;
V_380 -> V_398 = ( V_60 -> V_65 & ~ 0xFFFF ) | V_399 ;
if ( V_60 -> V_65 & V_400 )
V_380 -> V_398 |= V_401 ;
if ( F_216 ( V_56 ) -> V_227 & V_290 )
V_380 -> V_398 |= V_402 ;
if ( F_261 ( V_56 , V_403 , V_2 ) )
goto V_393;
if ( V_28 ) {
V_380 -> V_388 = 32 ;
if ( F_261 ( V_56 , V_404 , V_28 ) )
goto V_393;
}
if ( V_60 -> V_2 . V_53 &&
F_260 ( V_56 , V_405 , V_60 -> V_2 . V_53 -> V_103 ) )
goto V_393;
#ifdef F_28
if ( V_60 -> V_2 . V_218 &&
F_260 ( V_56 , V_406 , V_60 -> V_2 . V_218 ) )
goto V_393;
#endif
if ( ! F_165 ( V_60 ) &&
V_87 -> V_84 != V_28 ) {
if ( F_261 ( V_56 , V_407 , V_87 -> V_84 ) )
goto V_393;
}
if ( V_60 -> V_131 &&
F_261 ( V_56 , V_408 , V_60 -> V_62 ) )
goto V_393;
V_127 = V_60 -> V_2 . V_127 ;
if ( V_127 ) {
unsigned long V_76 = V_77 ;
if ( F_73 ( V_76 , V_127 ) )
V_127 -= V_76 ;
else
V_127 = 0 ;
}
memcpy ( V_249 , F_262 ( & V_60 -> V_2 ) , sizeof( V_249 ) ) ;
if ( V_60 -> V_125 && V_127 )
V_249 [ V_202 - 1 ] = V_60 -> V_125 ;
if ( F_263 ( V_56 , V_249 ) < 0 )
goto V_393;
if ( V_87 -> V_205 &&
F_260 ( V_56 , V_409 , V_87 -> V_205 ) )
goto V_393;
if ( ! F_264 ( V_87 -> V_342 , V_410 ) &&
F_260 ( V_56 , V_411 ,
F_265 ( F_266 () , V_87 -> V_342 ) ) )
goto V_393;
error = V_60 -> V_2 . error ;
if ( F_165 ( V_60 ) ) {
#ifdef F_194
if ( F_88 ( V_2 ) && ! F_191 ( V_2 ) &&
F_267 ( V_37 , V_412 ) ) {
int V_269 = F_268 ( V_37 , V_56 ,
V_87 -> V_84 , V_87 -> V_57 ,
V_380 , V_377 ) ;
if ( V_269 <= 0 ) {
if ( V_269 == 0 )
return 0 ;
goto V_393;
}
} else
#endif
if ( F_260 ( V_56 , V_413 , V_56 -> V_53 -> V_103 ) )
goto V_393;
}
if ( F_269 ( V_56 , & V_60 -> V_2 , 0 , V_127 , error ) < 0 )
goto V_393;
F_270 ( V_56 , V_382 ) ;
return 0 ;
V_393:
F_271 ( V_56 , V_382 ) ;
return - V_384 ;
}
static int F_272 ( struct V_55 * V_414 , struct V_381 * V_382 ,
struct V_415 * V_416 )
{
struct V_37 * V_37 = F_132 ( V_414 -> V_89 ) ;
struct V_379 * V_417 ;
struct V_418 * V_419 [ V_420 + 1 ] ;
struct V_50 * V_60 = NULL ;
struct V_86 V_87 ;
T_6 V_2 = 0 ;
T_6 V_28 = 0 ;
T_1 V_421 ;
int V_269 ;
int V_93 ;
struct V_55 * V_56 ;
T_1 V_376 = V_422 ;
T_14 V_423 ;
V_269 = F_273 ( V_382 , sizeof( * V_417 ) , V_419 , V_420 , V_424 ,
V_416 ) ;
if ( V_269 < 0 )
goto V_425;
V_417 = F_259 ( V_382 ) ;
V_56 = F_274 ( V_426 , V_31 ) ;
if ( ! V_56 ) {
V_269 = - V_277 ;
goto V_425;
}
F_275 ( V_56 ) ;
F_276 ( V_56 ) ;
V_28 = V_419 [ V_404 ] ? F_277 ( V_419 [ V_404 ] ) : 0 ;
V_2 = V_419 [ V_403 ] ? F_277 ( V_419 [ V_403 ] ) : 0 ;
V_421 = V_419 [ V_413 ] ? F_278 ( V_419 [ V_413 ] ) : 0 ;
V_93 = V_419 [ V_409 ] ? F_278 ( V_419 [ V_409 ] ) : 0 ;
if ( V_419 [ V_411 ] )
V_423 = F_279 ( F_266 () , F_278 ( V_419 [ V_411 ] ) ) ;
else
V_423 = ( V_421 ? V_410 : F_280 () ) ;
F_39 ( V_56 ) -> V_85 = V_427 ;
F_39 ( V_56 ) -> V_84 = V_28 ;
F_39 ( V_56 ) -> V_57 = V_2 ;
F_281 ( V_56 , V_428 + sizeof( struct V_80 ) ) ;
memset ( & V_87 , 0 , sizeof( V_87 ) ) ;
V_87 . V_57 = V_2 ;
V_87 . V_84 = V_28 ;
V_87 . V_214 = V_417 -> V_389 ;
V_87 . V_215 = V_419 [ V_405 ] ? F_278 ( V_419 [ V_405 ] ) : 0 ;
V_87 . V_205 = V_93 ;
V_87 . V_342 = V_423 ;
if ( V_421 ) {
struct V_58 * V_53 ;
V_53 = F_282 ( V_37 , V_421 ) ;
if ( ! V_53 ) {
V_269 = - V_362 ;
goto V_429;
}
V_56 -> V_85 = F_54 ( V_270 ) ;
V_56 -> V_53 = V_53 ;
V_56 -> V_93 = V_93 ;
V_269 = F_283 ( V_56 , V_2 , V_28 , V_417 -> V_389 , V_53 ) ;
V_60 = F_109 ( V_56 ) ;
if ( V_269 == 0 && V_60 -> V_2 . error )
V_269 = - V_60 -> V_2 . error ;
} else {
V_60 = F_284 ( V_37 , & V_87 ) ;
V_269 = 0 ;
if ( F_96 ( V_60 ) )
V_269 = F_285 ( V_60 ) ;
}
if ( V_269 )
goto V_429;
F_197 ( V_56 , & V_60 -> V_2 ) ;
if ( V_417 -> V_398 & V_401 )
V_60 -> V_65 |= V_400 ;
if ( V_417 -> V_398 & V_430 )
V_376 = V_60 -> V_263 ;
V_269 = F_257 ( V_37 , V_2 , V_28 , V_376 , & V_87 , V_56 ,
F_286 ( V_414 ) . V_377 , V_382 -> V_431 ,
V_432 ) ;
if ( V_269 < 0 )
goto V_429;
V_269 = F_287 ( V_56 , V_37 , F_286 ( V_414 ) . V_377 ) ;
V_425:
return V_269 ;
V_429:
F_123 ( V_56 ) ;
goto V_425;
}
void F_288 ( struct V_156 * V_157 )
{
F_36 ( F_35 ( V_157 -> V_53 ) ) ;
}
static int F_289 ( struct V_433 * V_434 , int V_435 ,
void T_15 * V_436 ,
T_16 * V_437 , T_2 * V_438 )
{
struct V_37 * V_37 = (struct V_37 * ) V_434 -> V_439 ;
if ( V_435 ) {
F_36 ( V_37 ) ;
F_290 ( V_37 ) ;
return 0 ;
}
return - V_193 ;
}
static T_3 int F_291 ( struct V_37 * V_37 )
{
struct V_433 * V_440 ;
V_440 = V_441 ;
if ( ! F_292 ( V_37 , & V_442 ) ) {
V_440 = F_293 ( V_440 , sizeof( V_441 ) , V_31 ) ;
if ( ! V_440 )
goto V_443;
if ( V_37 -> V_444 != & V_445 )
V_440 [ 0 ] . V_446 = NULL ;
}
V_440 [ 0 ] . V_439 = V_37 ;
V_37 -> V_178 . V_447 = F_294 ( V_37 , L_19 , V_440 ) ;
if ( ! V_37 -> V_178 . V_447 )
goto V_448;
return 0 ;
V_448:
if ( V_440 != V_441 )
F_23 ( V_440 ) ;
V_443:
return - V_32 ;
}
static T_4 void F_295 ( struct V_37 * V_37 )
{
struct V_433 * V_440 ;
V_440 = V_37 -> V_178 . V_447 -> V_449 ;
F_296 ( V_37 -> V_178 . V_447 ) ;
F_297 ( V_440 == V_441 ) ;
F_23 ( V_440 ) ;
}
static T_3 int F_298 ( struct V_37 * V_37 )
{
F_299 ( & V_37 -> V_178 . V_52 , 0 ) ;
F_299 ( & V_37 -> V_144 , 0 ) ;
F_300 ( & V_37 -> V_178 . V_450 ,
sizeof( V_37 -> V_178 . V_450 ) ) ;
return 0 ;
}
static int T_3 F_301 ( struct V_37 * V_37 )
{
struct V_451 * V_452 = F_302 ( sizeof( * V_452 ) , V_31 ) ;
if ( ! V_452 )
return - V_32 ;
F_303 ( V_452 ) ;
V_37 -> V_178 . V_179 = V_452 ;
return 0 ;
}
static void T_4 F_304 ( struct V_37 * V_37 )
{
struct V_451 * V_452 = V_37 -> V_178 . V_179 ;
V_37 -> V_178 . V_179 = NULL ;
F_305 ( V_452 ) ;
F_23 ( V_452 ) ;
}
int T_5 F_306 ( void )
{
int V_453 = 0 ;
int V_12 ;
V_75 = F_302 ( V_73 * sizeof( * V_75 ) , V_31 ) ;
if ( ! V_75 )
F_307 ( L_20 ) ;
F_308 ( V_75 , V_73 * sizeof( * V_75 ) ) ;
V_72 = F_19 ( V_73 , sizeof( * V_72 ) , V_31 ) ;
if ( ! V_72 )
F_307 ( L_21 ) ;
F_20 (cpu) {
struct V_231 * V_232 = & F_12 ( V_233 , V_12 ) ;
F_187 ( & V_232 -> V_236 ) ;
F_309 ( & V_232 -> V_234 ) ;
}
#ifdef F_28
V_27 = F_310 ( 256 * sizeof( struct V_27 ) , F_311 ( struct V_27 ) ) ;
if ( ! V_27 )
F_307 ( L_22 ) ;
#endif
V_16 . V_454 =
F_312 ( L_23 , sizeof( struct V_50 ) , 0 ,
V_455 | V_456 , NULL ) ;
V_370 . V_454 = V_16 . V_454 ;
if ( F_313 ( & V_16 ) < 0 )
F_307 ( L_24 ) ;
if ( F_313 ( & V_370 ) < 0 )
F_307 ( L_25 ) ;
V_16 . V_457 = ~ 0 ;
V_458 = V_459 ;
F_314 () ;
F_315 () ;
if ( F_31 () )
F_316 ( L_26 ) ;
#ifdef F_317
F_318 () ;
F_319 () ;
#endif
F_320 ( V_460 , V_461 , F_272 , NULL , NULL ) ;
#ifdef F_321
F_32 ( & V_462 ) ;
#endif
F_32 ( & V_463 ) ;
F_32 ( & V_464 ) ;
return V_453 ;
}
void T_5 F_322 ( void )
{
F_294 ( & V_442 , L_19 , V_465 ) ;
}
