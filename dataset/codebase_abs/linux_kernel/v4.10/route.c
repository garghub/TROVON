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
static void F_53 ( const struct V_37 * V_37 , struct V_82 * V_83 ,
const struct V_84 * V_85 ,
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
V_77 -> V_57 , V_77 -> V_80 , 0 , 0 ,
F_57 ( V_37 , V_85 ) ) ;
}
static void F_58 ( struct V_82 * V_83 , const struct V_55 * V_56 ,
const struct V_84 * V_85 )
{
const struct V_37 * V_37 = F_35 ( V_56 -> V_53 ) ;
const struct V_76 * V_77 = F_39 ( V_56 ) ;
int V_86 = V_56 -> V_53 -> V_99 ;
T_9 V_87 = F_59 ( V_77 -> V_87 ) ;
T_9 V_88 = V_77 -> V_81 ;
T_1 V_89 = V_56 -> V_89 ;
F_53 ( V_37 , V_83 , V_85 , V_77 , V_86 , V_87 , V_88 , V_89 , 0 ) ;
}
static void F_60 ( struct V_82 * V_83 , const struct V_84 * V_85 )
{
const struct V_91 * V_92 = F_54 ( V_85 ) ;
const struct V_100 * V_101 ;
T_6 V_57 = V_92 -> V_102 ;
F_61 () ;
V_101 = F_62 ( V_92 -> V_101 ) ;
if ( V_101 && V_101 -> V_103 . V_104 )
V_57 = V_101 -> V_103 . V_105 ;
F_56 ( V_83 , V_85 -> V_93 , V_85 -> V_94 ,
F_55 ( V_85 ) , V_98 ,
V_92 -> V_95 ? V_96 : V_85 -> V_97 ,
F_63 ( V_85 ) ,
V_57 , V_92 -> V_106 , 0 , 0 , V_85 -> V_107 ) ;
F_64 () ;
}
static void F_65 ( struct V_82 * V_83 , const struct V_84 * V_85 ,
const struct V_55 * V_56 )
{
if ( V_56 )
F_58 ( V_83 , V_56 , V_85 ) ;
else
F_60 ( V_83 , V_85 ) ;
}
static inline void F_66 ( struct V_50 * V_60 )
{
F_67 ( & V_60 -> V_2 . V_108 , V_109 ) ;
}
static void F_68 ( struct V_110 * V_111 )
{
struct V_50 * V_60 ;
V_60 = F_62 ( V_111 -> V_112 ) ;
if ( V_60 ) {
F_69 ( V_111 -> V_112 , NULL ) ;
F_66 ( V_60 ) ;
}
V_60 = F_62 ( V_111 -> V_113 ) ;
if ( V_60 ) {
F_69 ( V_111 -> V_113 , NULL ) ;
F_66 ( V_60 ) ;
}
}
static struct V_110 * F_70 ( struct V_114 * V_65 )
{
struct V_110 * V_111 , * V_115 ;
V_115 = F_62 ( V_65 -> V_116 ) ;
for ( V_111 = F_62 ( V_115 -> V_117 ) ; V_111 ;
V_111 = F_62 ( V_111 -> V_117 ) ) {
if ( F_71 ( V_111 -> V_118 , V_115 -> V_118 ) )
V_115 = V_111 ;
}
F_68 ( V_115 ) ;
return V_115 ;
}
static inline T_1 F_72 ( T_6 V_57 )
{
static T_1 T_10 V_78 ;
T_1 V_119 ;
F_49 ( & T_10 , sizeof( T_10 ) ) ;
V_119 = F_73 ( ( V_63 T_1 ) V_57 , T_10 ) ;
return F_74 ( V_119 , V_120 ) ;
}
static void F_75 ( struct V_50 * V_60 , struct V_110 * V_111 )
{
V_60 -> V_121 = V_111 -> V_122 ;
V_60 -> V_2 . V_123 = V_111 -> V_124 ;
if ( V_111 -> V_125 ) {
V_60 -> V_126 |= V_127 ;
V_60 -> V_62 = V_111 -> V_125 ;
V_60 -> V_128 = 1 ;
}
}
static void F_76 ( struct V_129 * V_130 , T_6 V_57 , T_6 V_131 ,
T_1 V_132 , unsigned long V_123 )
{
struct V_114 * V_65 ;
struct V_110 * V_111 ;
struct V_50 * V_60 ;
unsigned int V_29 ;
int V_133 ;
T_1 V_119 = F_72 ( V_57 ) ;
F_77 ( & V_134 ) ;
V_65 = F_62 ( V_130 -> V_135 ) ;
if ( ! V_65 ) {
V_65 = F_78 ( V_136 * sizeof( * V_65 ) , V_137 ) ;
if ( ! V_65 )
goto V_138;
F_79 ( V_130 -> V_135 , V_65 ) ;
}
V_65 += V_119 ;
V_133 = 0 ;
for ( V_111 = F_62 ( V_65 -> V_116 ) ; V_111 ;
V_111 = F_62 ( V_111 -> V_117 ) ) {
if ( V_111 -> V_139 == V_57 )
break;
V_133 ++ ;
}
if ( V_111 ) {
if ( V_131 )
V_111 -> V_125 = V_131 ;
if ( V_132 ) {
V_111 -> V_122 = V_132 ;
V_111 -> V_124 = F_80 ( 1UL , V_123 ) ;
}
V_60 = F_62 ( V_111 -> V_112 ) ;
if ( V_60 )
F_75 ( V_60 , V_111 ) ;
V_60 = F_62 ( V_111 -> V_113 ) ;
if ( V_60 )
F_75 ( V_60 , V_111 ) ;
} else {
if ( V_133 > V_140 )
V_111 = F_70 ( V_65 ) ;
else {
V_111 = F_78 ( sizeof( * V_111 ) , V_137 ) ;
if ( ! V_111 )
goto V_138;
V_111 -> V_117 = V_65 -> V_116 ;
F_79 ( V_65 -> V_116 , V_111 ) ;
}
V_111 -> V_141 = V_141 ( F_35 ( V_130 -> V_142 ) ) ;
V_111 -> V_139 = V_57 ;
V_111 -> V_125 = V_131 ;
V_111 -> V_122 = V_132 ;
V_111 -> V_124 = V_123 ;
V_60 = F_62 ( V_130 -> V_143 ) ;
if ( V_60 )
V_60 -> V_2 . V_144 = V_145 ;
F_20 (i) {
struct V_50 T_11 * * V_146 ;
V_146 = F_21 ( V_130 -> V_147 , V_29 ) ;
V_60 = F_62 ( * V_146 ) ;
if ( V_60 )
V_60 -> V_2 . V_144 = V_145 ;
}
}
V_111 -> V_118 = V_73 ;
V_138:
F_81 ( & V_134 ) ;
}
static void F_82 ( struct V_50 * V_60 , struct V_55 * V_56 , struct V_82 * V_83 ,
bool V_148 )
{
T_6 V_149 = F_83 ( V_56 ) -> V_150 . V_151 ;
T_6 V_152 = F_39 ( V_56 ) -> V_80 ;
struct V_58 * V_53 = V_56 -> V_53 ;
struct V_153 * V_154 ;
struct V_155 V_156 ;
struct V_54 * V_61 ;
struct V_37 * V_37 ;
switch ( F_83 ( V_56 ) -> V_157 & 7 ) {
case V_158 :
case V_159 :
case V_160 :
case V_161 :
break;
default:
return;
}
if ( V_60 -> V_62 != V_152 )
return;
V_154 = F_84 ( V_53 ) ;
if ( ! V_154 )
return;
V_37 = F_35 ( V_53 ) ;
if ( V_149 == V_152 || ! F_85 ( V_154 ) ||
F_86 ( V_149 ) || F_87 ( V_149 ) ||
F_88 ( V_149 ) )
goto V_162;
if ( ! F_89 ( V_154 ) ) {
if ( ! F_90 ( V_154 , V_149 , V_152 ) )
goto V_162;
if ( F_91 ( V_154 ) && F_92 ( V_149 , V_53 ) )
goto V_162;
} else {
if ( F_93 ( V_37 , V_149 ) != V_163 )
goto V_162;
}
V_61 = F_40 ( V_60 -> V_2 . V_53 , V_149 ) ;
if ( ! V_61 )
V_61 = F_41 ( & V_64 , & V_149 , V_60 -> V_2 . V_53 ) ;
if ( ! F_94 ( V_61 ) ) {
if ( ! ( V_61 -> V_164 & V_165 ) ) {
F_95 ( V_61 , NULL ) ;
} else {
if ( F_96 ( V_37 , V_83 , & V_156 , 0 ) == 0 ) {
struct V_129 * V_130 = & F_97 ( V_156 ) ;
F_76 ( V_130 , V_83 -> V_57 , V_149 ,
0 , V_73 + V_166 ) ;
}
if ( V_148 )
V_60 -> V_2 . V_144 = V_145 ;
F_98 ( V_167 , V_61 ) ;
}
F_99 ( V_61 ) ;
}
return;
V_162:
#ifdef F_100
if ( F_101 ( V_154 ) ) {
const struct V_76 * V_77 = ( const struct V_76 * ) V_56 -> V_168 ;
T_6 V_57 = V_77 -> V_57 ;
T_6 V_80 = V_77 -> V_80 ;
F_102 ( L_10
L_11 ,
& V_152 , V_53 -> V_169 , & V_149 ,
& V_80 , & V_57 ) ;
}
#endif
;
}
static void F_103 ( struct V_1 * V_2 , struct V_84 * V_85 , struct V_55 * V_56 )
{
struct V_50 * V_60 ;
struct V_82 V_83 ;
const struct V_76 * V_77 = ( const struct V_76 * ) V_56 -> V_168 ;
struct V_37 * V_37 = F_35 ( V_56 -> V_53 ) ;
int V_86 = V_56 -> V_53 -> V_99 ;
T_9 V_87 = F_59 ( V_77 -> V_87 ) ;
T_9 V_88 = V_77 -> V_81 ;
T_1 V_89 = V_56 -> V_89 ;
V_60 = (struct V_50 * ) V_2 ;
F_53 ( V_37 , & V_83 , V_85 , V_77 , V_86 , V_87 , V_88 , V_89 , 0 ) ;
F_82 ( V_60 , V_56 , & V_83 , true ) ;
}
static struct V_1 * F_104 ( struct V_1 * V_2 )
{
struct V_50 * V_60 = (struct V_50 * ) V_2 ;
struct V_1 * V_170 = V_2 ;
if ( V_60 ) {
if ( V_2 -> V_144 > 0 ) {
F_105 ( V_60 ) ;
V_170 = NULL ;
} else if ( ( V_60 -> V_126 & V_127 ) ||
V_60 -> V_2 . V_123 ) {
F_105 ( V_60 ) ;
V_170 = NULL ;
}
}
return V_170 ;
}
void F_106 ( struct V_55 * V_56 )
{
struct V_50 * V_60 = F_107 ( V_56 ) ;
struct V_153 * V_154 ;
struct V_171 * V_172 ;
struct V_37 * V_37 ;
int V_173 ;
int V_174 ;
F_61 () ;
V_154 = F_84 ( V_60 -> V_2 . V_53 ) ;
if ( ! V_154 || ! F_108 ( V_154 ) ) {
F_64 () ;
return;
}
V_173 = F_101 ( V_154 ) ;
V_174 = F_109 ( V_60 -> V_2 . V_53 ) ;
F_64 () ;
V_37 = F_35 ( V_60 -> V_2 . V_53 ) ;
V_172 = F_110 ( V_37 -> V_175 . V_176 , F_39 ( V_56 ) -> V_80 , V_174 , 1 ) ;
if ( ! V_172 ) {
F_111 ( V_56 , V_177 , V_160 ,
F_112 ( V_60 , F_39 ( V_56 ) -> V_57 ) ) ;
return;
}
if ( F_113 ( V_73 , V_172 -> V_178 + V_179 ) )
V_172 -> V_180 = 0 ;
if ( V_172 -> V_180 >= V_181 ) {
V_172 -> V_178 = V_73 ;
goto V_182;
}
if ( V_172 -> V_180 == 0 ||
F_113 ( V_73 ,
( V_172 -> V_178 +
( V_183 << V_172 -> V_180 ) ) ) ) {
T_6 V_131 = F_112 ( V_60 , F_39 ( V_56 ) -> V_57 ) ;
F_111 ( V_56 , V_177 , V_160 , V_131 ) ;
V_172 -> V_178 = V_73 ;
++ V_172 -> V_180 ;
#ifdef F_100
if ( V_173 &&
V_172 -> V_180 == V_181 )
F_114 ( L_12 ,
& F_39 ( V_56 ) -> V_80 , F_115 ( V_56 ) ,
& F_39 ( V_56 ) -> V_57 , & V_131 ) ;
#endif
}
V_182:
F_116 ( V_172 ) ;
}
static int F_117 ( struct V_55 * V_56 )
{
struct V_153 * V_154 = F_84 ( V_56 -> V_53 ) ;
struct V_50 * V_60 = F_107 ( V_56 ) ;
struct V_171 * V_172 ;
unsigned long V_72 ;
struct V_37 * V_37 ;
bool V_184 ;
int V_157 ;
if ( ! V_154 )
goto V_185;
V_37 = F_35 ( V_60 -> V_2 . V_53 ) ;
if ( ! F_118 ( V_154 ) ) {
switch ( V_60 -> V_2 . error ) {
case V_186 :
F_119 ( V_37 , V_187 ) ;
break;
case V_188 :
F_119 ( V_37 , V_189 ) ;
break;
}
goto V_185;
}
switch ( V_60 -> V_2 . error ) {
case V_190 :
default:
goto V_185;
case V_186 :
V_157 = V_191 ;
break;
case V_188 :
V_157 = V_192 ;
F_119 ( V_37 , V_189 ) ;
break;
case V_193 :
V_157 = V_194 ;
break;
}
V_172 = F_110 ( V_37 -> V_175 . V_176 , F_39 ( V_56 ) -> V_80 ,
F_120 ( V_56 -> V_53 ) , 1 ) ;
V_184 = true ;
if ( V_172 ) {
V_72 = V_73 ;
V_172 -> V_180 += V_72 - V_172 -> V_178 ;
if ( V_172 -> V_180 > V_195 )
V_172 -> V_180 = V_195 ;
V_172 -> V_178 = V_72 ;
if ( V_172 -> V_180 >= V_196 )
V_172 -> V_180 -= V_196 ;
else
V_184 = false ;
F_116 ( V_172 ) ;
}
if ( V_184 )
F_111 ( V_56 , V_197 , V_157 , 0 ) ;
V_185: F_121 ( V_56 ) ;
return 0 ;
}
static void F_122 ( struct V_50 * V_60 , struct V_82 * V_83 , T_1 V_198 )
{
struct V_1 * V_2 = & V_60 -> V_2 ;
struct V_155 V_156 ;
if ( F_123 ( V_2 , V_199 ) )
return;
if ( F_124 ( V_2 ) < V_198 )
return;
if ( V_198 < V_200 )
V_198 = V_200 ;
if ( V_60 -> V_121 == V_198 &&
F_71 ( V_73 , V_2 -> V_123 - V_201 / 2 ) )
return;
F_61 () ;
if ( F_96 ( F_35 ( V_2 -> V_53 ) , V_83 , & V_156 , 0 ) == 0 ) {
struct V_129 * V_130 = & F_97 ( V_156 ) ;
F_76 ( V_130 , V_83 -> V_57 , 0 , V_198 ,
V_73 + V_201 ) ;
}
F_64 () ;
}
static void F_125 ( struct V_1 * V_2 , struct V_84 * V_85 ,
struct V_55 * V_56 , T_1 V_198 )
{
struct V_50 * V_60 = (struct V_50 * ) V_2 ;
struct V_82 V_83 ;
F_65 ( & V_83 , V_85 , V_56 ) ;
F_122 ( V_60 , & V_83 , V_198 ) ;
}
void F_126 ( struct V_55 * V_56 , struct V_37 * V_37 , T_1 V_198 ,
int V_86 , T_1 V_89 , T_9 V_81 , int V_90 )
{
const struct V_76 * V_77 = ( const struct V_76 * ) V_56 -> V_168 ;
struct V_82 V_83 ;
struct V_50 * V_60 ;
if ( ! V_89 )
V_89 = F_127 ( V_37 , V_56 -> V_89 ) ;
F_53 ( V_37 , & V_83 , NULL , V_77 , V_86 ,
F_59 ( V_77 -> V_87 ) , V_81 , V_89 , V_90 ) ;
V_60 = F_128 ( V_37 , & V_83 ) ;
if ( ! F_94 ( V_60 ) ) {
F_122 ( V_60 , & V_83 , V_198 ) ;
F_105 ( V_60 ) ;
}
}
static void F_129 ( struct V_55 * V_56 , struct V_84 * V_85 , T_1 V_198 )
{
const struct V_76 * V_77 = ( const struct V_76 * ) V_56 -> V_168 ;
struct V_82 V_83 ;
struct V_50 * V_60 ;
F_53 ( F_130 ( V_85 ) , & V_83 , V_85 , V_77 , 0 , 0 , 0 , 0 , 0 ) ;
if ( ! V_83 . V_202 )
V_83 . V_202 = F_127 ( F_130 ( V_85 ) , V_56 -> V_89 ) ;
V_60 = F_128 ( F_130 ( V_85 ) , & V_83 ) ;
if ( ! F_94 ( V_60 ) ) {
F_122 ( V_60 , & V_83 , V_198 ) ;
F_105 ( V_60 ) ;
}
}
void F_131 ( struct V_55 * V_56 , struct V_84 * V_85 , T_1 V_198 )
{
const struct V_76 * V_77 = ( const struct V_76 * ) V_56 -> V_168 ;
struct V_82 V_83 ;
struct V_50 * V_60 ;
struct V_1 * V_203 = NULL ;
bool V_74 = false ;
struct V_37 * V_37 = F_130 ( V_85 ) ;
F_132 ( V_85 ) ;
if ( ! F_133 ( V_85 ) )
goto V_185;
V_203 = F_134 ( V_85 ) ;
if ( F_135 ( V_85 ) || ! V_203 ) {
F_129 ( V_56 , V_85 , V_198 ) ;
goto V_185;
}
F_53 ( V_37 , & V_83 , V_85 , V_77 , 0 , 0 , 0 , 0 , 0 ) ;
V_60 = (struct V_50 * ) V_203 ;
if ( V_203 -> V_144 && ! V_203 -> V_204 -> V_205 ( V_203 , 0 ) ) {
V_60 = F_136 ( F_130 ( V_85 ) , & V_83 , V_85 ) ;
if ( F_94 ( V_60 ) )
goto V_185;
V_74 = true ;
}
F_122 ( (struct V_50 * ) V_60 -> V_2 . V_206 , & V_83 , V_198 ) ;
if ( ! F_137 ( & V_60 -> V_2 , 0 ) ) {
if ( V_74 )
F_138 ( & V_60 -> V_2 ) ;
V_60 = F_136 ( F_130 ( V_85 ) , & V_83 , V_85 ) ;
if ( F_94 ( V_60 ) )
goto V_185;
V_74 = true ;
}
if ( V_74 )
F_139 ( V_85 , & V_60 -> V_2 ) ;
V_185:
F_140 ( V_85 ) ;
F_138 ( V_203 ) ;
}
void F_141 ( struct V_55 * V_56 , struct V_37 * V_37 ,
int V_86 , T_1 V_89 , T_9 V_81 , int V_90 )
{
const struct V_76 * V_77 = ( const struct V_76 * ) V_56 -> V_168 ;
struct V_82 V_83 ;
struct V_50 * V_60 ;
F_53 ( V_37 , & V_83 , NULL , V_77 , V_86 ,
F_59 ( V_77 -> V_87 ) , V_81 , V_89 , V_90 ) ;
V_60 = F_128 ( V_37 , & V_83 ) ;
if ( ! F_94 ( V_60 ) ) {
F_82 ( V_60 , V_56 , & V_83 , false ) ;
F_105 ( V_60 ) ;
}
}
void F_142 ( struct V_55 * V_56 , struct V_84 * V_85 )
{
const struct V_76 * V_77 = ( const struct V_76 * ) V_56 -> V_168 ;
struct V_82 V_83 ;
struct V_50 * V_60 ;
struct V_37 * V_37 = F_130 ( V_85 ) ;
F_53 ( V_37 , & V_83 , V_85 , V_77 , 0 , 0 , 0 , 0 , 0 ) ;
V_60 = F_128 ( V_37 , & V_83 ) ;
if ( ! F_94 ( V_60 ) ) {
F_82 ( V_60 , V_56 , & V_83 , false ) ;
F_105 ( V_60 ) ;
}
}
static struct V_1 * F_143 ( struct V_1 * V_2 , T_1 V_207 )
{
struct V_50 * V_60 = (struct V_50 * ) V_2 ;
if ( V_2 -> V_144 != V_208 || F_33 ( V_60 ) )
return NULL ;
return V_2 ;
}
static void F_144 ( struct V_55 * V_56 )
{
struct V_50 * V_60 ;
F_111 ( V_56 , V_197 , V_191 , 0 ) ;
V_60 = F_107 ( V_56 ) ;
if ( V_60 )
F_145 ( & V_60 -> V_2 , 0 ) ;
}
static int F_146 ( struct V_37 * V_37 , struct V_84 * V_85 , struct V_55 * V_56 )
{
F_147 ( L_13 ,
V_209 , & F_39 ( V_56 ) -> V_80 , & F_39 ( V_56 ) -> V_57 ,
V_56 -> V_53 ? V_56 -> V_53 -> V_169 : L_14 ) ;
F_121 ( V_56 ) ;
F_2 ( 1 ) ;
return 0 ;
}
void F_148 ( T_9 * V_210 , struct V_55 * V_56 , struct V_50 * V_60 )
{
T_6 V_28 ;
if ( F_149 ( V_60 ) )
V_28 = F_39 ( V_56 ) -> V_80 ;
else {
struct V_155 V_156 ;
struct V_82 V_83 ;
struct V_76 * V_77 ;
V_77 = F_39 ( V_56 ) ;
memset ( & V_83 , 0 , sizeof( V_83 ) ) ;
V_83 . V_57 = V_77 -> V_57 ;
V_83 . V_80 = V_77 -> V_80 ;
V_83 . V_211 = F_59 ( V_77 -> V_87 ) ;
V_83 . V_212 = V_60 -> V_2 . V_53 -> V_99 ;
V_83 . V_213 = V_56 -> V_53 -> V_99 ;
V_83 . V_202 = V_56 -> V_89 ;
F_61 () ;
if ( F_96 ( F_35 ( V_60 -> V_2 . V_53 ) , & V_83 , & V_156 , 0 ) == 0 )
V_28 = F_150 ( F_35 ( V_60 -> V_2 . V_53 ) , V_156 ) ;
else
V_28 = F_151 ( V_60 -> V_2 . V_53 ,
F_112 ( V_60 , V_77 -> V_57 ) ,
V_98 ) ;
F_64 () ;
}
memcpy ( V_210 , & V_28 , 4 ) ;
}
static void F_152 ( struct V_50 * V_60 , T_1 V_214 )
{
if ( ! ( V_60 -> V_2 . V_215 & 0xFFFF ) )
V_60 -> V_2 . V_215 |= V_214 & 0xFFFF ;
if ( ! ( V_60 -> V_2 . V_215 & 0xFFFF0000 ) )
V_60 -> V_2 . V_215 |= V_214 & 0xFFFF0000 ;
}
static unsigned int F_153 ( const struct V_1 * V_2 )
{
unsigned int V_216 = F_154 ( V_2 , V_217 ) ;
if ( V_216 == 0 ) {
V_216 = F_155 (unsigned int, dst->dev->mtu - 40 ,
ip_rt_min_advmss) ;
if ( V_216 > 65535 - 40 )
V_216 = 65535 - 40 ;
}
return V_216 ;
}
static unsigned int F_124 ( const struct V_1 * V_2 )
{
const struct V_50 * V_60 = ( const struct V_50 * ) V_2 ;
unsigned int V_198 = V_60 -> V_121 ;
if ( ! V_198 || F_156 ( V_73 , V_60 -> V_2 . V_123 ) )
V_198 = F_154 ( V_2 , V_199 ) ;
if ( V_198 )
return V_198 ;
V_198 = V_2 -> V_53 -> V_198 ;
if ( F_157 ( F_123 ( V_2 , V_199 ) ) ) {
if ( V_60 -> V_128 && V_198 > 576 )
V_198 = 576 ;
}
V_198 = F_158 (unsigned int, mtu, IP_MAX_MTU) ;
return V_198 - F_159 ( V_2 -> V_218 , V_198 ) ;
}
static struct V_110 * F_160 ( struct V_129 * V_130 , T_6 V_57 )
{
struct V_114 * V_65 = F_62 ( V_130 -> V_135 ) ;
struct V_110 * V_111 ;
T_1 V_119 ;
if ( ! V_65 )
return NULL ;
V_119 = F_72 ( V_57 ) ;
for ( V_111 = F_62 ( V_65 [ V_119 ] . V_116 ) ; V_111 ;
V_111 = F_62 ( V_111 -> V_117 ) ) {
if ( V_111 -> V_139 == V_57 )
return V_111 ;
}
return NULL ;
}
static bool F_161 ( struct V_50 * V_60 , struct V_110 * V_111 ,
T_6 V_57 )
{
bool V_170 = false ;
F_77 ( & V_134 ) ;
if ( V_57 == V_111 -> V_139 ) {
struct V_50 T_11 * * V_219 ;
struct V_50 * V_220 ;
int V_221 = V_141 ( F_35 ( V_60 -> V_2 . V_53 ) ) ;
if ( F_162 ( V_60 ) )
V_219 = & V_111 -> V_112 ;
else
V_219 = & V_111 -> V_113 ;
V_220 = F_62 ( * V_219 ) ;
if ( V_111 -> V_141 != V_221 ) {
V_111 -> V_141 = V_221 ;
V_111 -> V_125 = 0 ;
V_111 -> V_122 = 0 ;
V_111 -> V_124 = 0 ;
F_68 ( V_111 ) ;
V_220 = NULL ;
}
F_75 ( V_60 , V_111 ) ;
if ( ! V_60 -> V_62 )
V_60 -> V_62 = V_57 ;
if ( ! ( V_60 -> V_2 . V_222 & V_223 ) ) {
F_79 ( * V_219 , V_60 ) ;
if ( V_220 )
F_66 ( V_220 ) ;
V_170 = true ;
}
V_111 -> V_118 = V_73 ;
}
F_81 ( & V_134 ) ;
return V_170 ;
}
static bool F_163 ( struct V_129 * V_130 , struct V_50 * V_60 )
{
struct V_50 * V_220 , * V_224 , * * V_225 ;
bool V_170 = true ;
if ( F_162 ( V_60 ) ) {
V_225 = (struct V_50 * * ) & V_130 -> V_143 ;
} else {
V_225 = (struct V_50 * * ) F_164 ( V_130 -> V_147 ) ;
}
V_220 = * V_225 ;
V_224 = F_44 ( V_225 , V_220 , V_60 ) ;
if ( V_224 == V_220 ) {
if ( V_220 )
F_66 ( V_220 ) ;
} else
V_170 = false ;
return V_170 ;
}
static void F_165 ( struct V_50 * V_60 )
{
struct V_226 * V_227 = F_164 ( & V_228 ) ;
V_60 -> V_228 = V_227 ;
F_77 ( & V_227 -> V_229 ) ;
F_166 ( & V_60 -> V_230 , & V_227 -> V_231 ) ;
F_81 ( & V_227 -> V_229 ) ;
}
static void F_167 ( struct V_1 * V_2 )
{
struct V_50 * V_60 = (struct V_50 * ) V_2 ;
if ( ! F_168 ( & V_60 -> V_230 ) ) {
struct V_226 * V_227 = V_60 -> V_228 ;
F_77 ( & V_227 -> V_229 ) ;
F_169 ( & V_60 -> V_230 ) ;
F_81 ( & V_227 -> V_229 ) ;
}
}
void F_170 ( struct V_58 * V_53 )
{
struct V_37 * V_37 = F_35 ( V_53 ) ;
struct V_50 * V_60 ;
int V_12 ;
F_20 (cpu) {
struct V_226 * V_227 = & F_12 ( V_228 , V_12 ) ;
F_77 ( & V_227 -> V_229 ) ;
F_171 (rt, &ul->head, rt_uncached) {
if ( V_60 -> V_2 . V_53 != V_53 )
continue;
V_60 -> V_2 . V_53 = V_37 -> V_232 ;
F_172 ( V_60 -> V_2 . V_53 ) ;
F_173 ( V_53 ) ;
}
F_81 ( & V_227 -> V_229 ) ;
}
}
static bool F_174 ( const struct V_50 * V_60 )
{
return V_60 &&
V_60 -> V_2 . V_144 == V_208 &&
! F_33 ( V_60 ) ;
}
static void F_175 ( struct V_50 * V_60 , T_6 V_57 ,
const struct V_155 * V_156 ,
struct V_110 * V_111 ,
struct V_233 * V_234 , T_12 type , T_1 V_235 )
{
bool V_236 = false ;
if ( V_234 ) {
struct V_129 * V_130 = & F_97 ( * V_156 ) ;
if ( V_130 -> V_237 && V_130 -> V_238 == V_239 ) {
V_60 -> V_62 = V_130 -> V_237 ;
V_60 -> V_128 = 1 ;
}
F_176 ( & V_60 -> V_2 , V_234 -> V_240 , true ) ;
#ifdef F_28
V_60 -> V_2 . V_215 = V_130 -> V_241 ;
#endif
V_60 -> V_2 . V_218 = F_177 ( V_130 -> V_242 ) ;
if ( F_157 ( V_111 ) )
V_236 = F_161 ( V_60 , V_111 , V_57 ) ;
else if ( ! ( V_60 -> V_2 . V_222 & V_223 ) )
V_236 = F_163 ( V_130 , V_60 ) ;
if ( F_157 ( ! V_236 ) ) {
V_60 -> V_2 . V_222 |= V_223 ;
if ( ! V_60 -> V_62 )
V_60 -> V_62 = V_57 ;
F_165 ( V_60 ) ;
}
} else
F_165 ( V_60 ) ;
#ifdef F_28
#ifdef F_178
F_152 ( V_60 , V_156 -> V_215 ) ;
#endif
F_152 ( V_60 , V_235 ) ;
#endif
}
struct V_50 * F_179 ( struct V_58 * V_53 ,
unsigned int V_222 , T_12 type ,
bool V_243 , bool V_244 , bool V_245 )
{
struct V_50 * V_60 ;
V_60 = F_180 ( & V_16 , V_53 , 1 , V_208 ,
( V_245 ? 0 : ( V_246 | V_223 ) ) |
( V_243 ? V_247 : 0 ) |
( V_244 ? V_248 : 0 ) ) ;
if ( V_60 ) {
V_60 -> V_52 = F_34 ( F_35 ( V_53 ) ) ;
V_60 -> V_126 = V_222 ;
V_60 -> V_249 = type ;
V_60 -> V_250 = 0 ;
V_60 -> V_251 = 0 ;
V_60 -> V_121 = 0 ;
V_60 -> V_62 = 0 ;
V_60 -> V_128 = 0 ;
V_60 -> V_252 = 0 ;
F_181 ( & V_60 -> V_230 ) ;
V_60 -> V_2 . V_253 = V_254 ;
if ( V_222 & V_255 )
V_60 -> V_2 . V_256 = V_257 ;
}
return V_60 ;
}
static int F_182 ( struct V_55 * V_56 , T_6 V_57 , T_6 V_80 ,
T_9 V_87 , struct V_58 * V_53 , int V_258 )
{
struct V_50 * V_51 ;
struct V_153 * V_154 = F_84 ( V_53 ) ;
unsigned int V_222 = V_259 ;
T_1 V_235 = 0 ;
int V_260 ;
if ( ! V_154 )
return - V_190 ;
if ( F_86 ( V_80 ) || F_87 ( V_80 ) ||
V_56 -> V_81 != F_52 ( V_261 ) )
goto V_262;
if ( F_183 ( V_80 ) && ! F_184 ( V_154 ) )
goto V_262;
if ( F_88 ( V_80 ) ) {
if ( ! F_185 ( V_57 ) )
goto V_262;
} else {
V_260 = F_186 ( V_56 , V_80 , 0 , V_87 , 0 , V_53 ,
V_154 , & V_235 ) ;
if ( V_260 < 0 )
goto V_263;
}
if ( V_258 )
V_222 |= V_255 ;
V_51 = F_179 ( F_35 ( V_53 ) -> V_232 , V_222 , V_264 ,
F_187 ( V_154 , V_265 ) , false , false ) ;
if ( ! V_51 )
goto V_266;
#ifdef F_28
V_51 -> V_2 . V_215 = V_235 ;
#endif
V_51 -> V_2 . V_253 = F_146 ;
V_51 -> V_250 = 1 ;
#ifdef F_188
if ( ! F_185 ( V_57 ) && F_189 ( V_154 ) )
V_51 -> V_2 . V_256 = V_267 ;
#endif
F_190 ( V_18 ) ;
F_191 ( V_56 , & V_51 -> V_2 ) ;
return 0 ;
V_266:
return - V_268 ;
V_262:
return - V_190 ;
V_263:
return V_260 ;
}
static void F_192 ( struct V_58 * V_53 ,
struct V_153 * V_154 ,
struct V_55 * V_56 ,
T_6 V_57 ,
T_6 V_80 )
{
F_190 ( V_22 ) ;
#ifdef F_100
if ( F_101 ( V_154 ) && F_193 () ) {
F_194 ( L_15 ,
& V_57 , & V_80 , V_53 -> V_169 ) ;
if ( V_53 -> V_269 && F_195 ( V_56 ) ) {
F_196 ( V_270 , L_16 ,
V_271 , 16 , 1 ,
F_197 ( V_56 ) ,
V_53 -> V_269 , true ) ;
}
}
#endif
}
static void F_198 ( struct V_129 * V_130 , T_6 V_57 )
{
struct V_114 * V_65 ;
struct V_110 * V_111 , T_11 * * V_272 ;
T_1 V_119 = F_72 ( V_57 ) ;
F_77 ( & V_134 ) ;
V_65 = F_199 ( V_130 -> V_135 ,
F_200 ( & V_134 ) ) ;
V_65 += V_119 ;
V_272 = & V_65 -> V_116 ;
V_111 = F_199 ( * V_272 , F_200 ( & V_134 ) ) ;
while ( V_111 ) {
if ( V_111 -> V_139 == V_57 ) {
F_79 ( * V_272 , F_199 (
V_111 -> V_117 , F_200 ( & V_134 ) ) ) ;
F_68 ( V_111 ) ;
F_201 ( V_111 , V_273 ) ;
break;
}
V_272 = & V_111 -> V_117 ;
V_111 = F_199 ( V_111 -> V_117 ,
F_200 ( & V_134 ) ) ;
}
F_81 ( & V_134 ) ;
}
static void F_202 ( struct V_50 * V_51 )
{
if ( F_203 ( V_51 -> V_2 . V_218 ) ) {
V_51 -> V_2 . V_218 -> V_274 = V_51 -> V_2 . V_253 ;
V_51 -> V_2 . V_253 = V_275 ;
}
if ( F_204 ( V_51 -> V_2 . V_218 ) ) {
V_51 -> V_2 . V_218 -> V_276 = V_51 -> V_2 . V_256 ;
V_51 -> V_2 . V_256 = V_277 ;
}
}
static int F_205 ( struct V_55 * V_56 ,
const struct V_155 * V_156 ,
struct V_153 * V_154 ,
T_6 V_57 , T_6 V_80 , T_1 V_87 )
{
struct V_110 * V_111 ;
struct V_50 * V_51 ;
int V_260 ;
struct V_153 * V_278 ;
bool V_279 ;
T_1 V_235 = 0 ;
V_278 = F_84 ( F_206 ( * V_156 ) ) ;
if ( ! V_278 ) {
F_207 ( L_17 ) ;
return - V_190 ;
}
V_260 = F_186 ( V_56 , V_80 , V_57 , V_87 , F_208 ( * V_156 ) ,
V_154 -> V_53 , V_154 , & V_235 ) ;
if ( V_260 < 0 ) {
F_192 ( V_154 -> V_53 , V_154 , V_56 , V_57 ,
V_80 ) ;
goto V_280;
}
V_279 = V_156 -> V_234 && ! V_235 ;
if ( V_278 == V_154 && V_260 && F_108 ( V_278 ) &&
V_56 -> V_81 == F_52 ( V_261 ) &&
( F_89 ( V_278 ) ||
F_90 ( V_278 , V_80 , F_209 ( * V_156 ) ) ) )
F_210 ( V_56 ) -> V_222 |= V_281 ;
if ( V_56 -> V_81 != F_52 ( V_261 ) ) {
if ( V_278 == V_154 &&
F_211 ( V_154 ) == 0 ) {
V_260 = - V_190 ;
goto V_280;
}
}
V_111 = F_160 ( & F_97 ( * V_156 ) , V_57 ) ;
if ( V_279 ) {
if ( V_111 ) {
V_51 = F_62 ( V_111 -> V_112 ) ;
if ( V_51 && V_51 -> V_2 . V_123 &&
F_113 ( V_73 , V_51 -> V_2 . V_123 ) ) {
F_198 ( & F_97 ( * V_156 ) , V_57 ) ;
V_111 = NULL ;
} else {
goto V_282;
}
}
V_51 = F_62 ( F_97 ( * V_156 ) . V_143 ) ;
V_282:
if ( F_174 ( V_51 ) ) {
F_212 ( V_56 , & V_51 -> V_2 ) ;
goto V_185;
}
}
V_51 = F_179 ( V_278 -> V_53 , 0 , V_156 -> type ,
F_187 ( V_154 , V_265 ) ,
F_187 ( V_278 , V_283 ) , V_279 ) ;
if ( ! V_51 ) {
V_260 = - V_268 ;
goto V_280;
}
V_51 -> V_250 = 1 ;
if ( V_156 -> V_284 )
V_51 -> V_252 = V_156 -> V_284 -> V_285 ;
F_190 ( V_17 ) ;
V_51 -> V_2 . V_256 = V_286 ;
F_175 ( V_51 , V_57 , V_156 , V_111 , V_156 -> V_234 , V_156 -> type , V_235 ) ;
F_202 ( V_51 ) ;
F_191 ( V_56 , & V_51 -> V_2 ) ;
V_185:
V_260 = 0 ;
V_280:
return V_260 ;
}
static int F_213 ( struct V_55 * V_56 )
{
const struct V_76 * V_287 = F_39 ( V_56 ) ;
struct V_288 V_289 ;
const struct V_288 * V_290 ;
struct V_76 V_291 ;
const struct V_76 * V_292 ;
if ( F_157 ( ( V_287 -> V_293 & F_52 ( V_294 ) ) != 0 ) )
goto V_295;
V_290 = F_214 ( V_56 , V_287 -> V_296 * 4 , sizeof( V_289 ) ,
& V_289 ) ;
if ( ! V_290 )
goto V_295;
if ( V_290 -> type != V_197 &&
V_290 -> type != V_177 &&
V_290 -> type != V_297 &&
V_290 -> type != V_298 ) {
goto V_295;
}
V_292 = F_214 ( V_56 ,
V_287 -> V_296 * 4 + sizeof( V_289 ) ,
sizeof( V_291 ) , & V_291 ) ;
if ( ! V_292 )
goto V_295;
return F_215 ( V_292 -> V_57 , V_292 -> V_80 ) ;
V_295:
return F_215 ( V_287 -> V_80 , V_287 -> V_57 ) ;
}
static int F_216 ( struct V_55 * V_56 ,
struct V_155 * V_156 ,
const struct V_82 * V_83 ,
struct V_153 * V_154 ,
T_6 V_57 , T_6 V_80 , T_1 V_87 )
{
#ifdef F_217
if ( V_156 -> V_234 && V_156 -> V_234 -> V_299 > 1 ) {
int V_300 ;
if ( F_157 ( F_39 ( V_56 ) -> V_81 == V_301 ) )
V_300 = F_213 ( V_56 ) ;
else
V_300 = F_215 ( V_80 , V_57 ) ;
F_218 ( V_156 , V_300 ) ;
}
#endif
return F_205 ( V_56 , V_156 , V_154 , V_57 , V_80 , V_87 ) ;
}
static int F_219 ( struct V_55 * V_56 , T_6 V_57 , T_6 V_80 ,
T_9 V_87 , struct V_58 * V_53 )
{
struct V_155 V_156 ;
struct V_153 * V_154 = F_84 ( V_53 ) ;
struct V_302 * V_303 ;
struct V_82 V_83 ;
unsigned int V_222 = 0 ;
T_1 V_235 = 0 ;
struct V_50 * V_51 ;
int V_260 = - V_190 ;
struct V_37 * V_37 = F_35 ( V_53 ) ;
bool V_279 ;
if ( ! V_154 )
goto V_185;
V_303 = F_220 ( V_56 ) ;
if ( V_303 && ! ( V_303 -> V_304 & V_305 ) )
V_83 . V_306 . V_307 = V_303 -> V_308 . V_307 ;
else
V_83 . V_306 . V_307 = 0 ;
F_221 ( V_56 ) ;
if ( F_86 ( V_80 ) || F_87 ( V_80 ) )
goto V_309;
V_156 . V_234 = NULL ;
V_156 . V_284 = NULL ;
if ( F_87 ( V_57 ) || ( V_80 == 0 && V_57 == 0 ) )
goto V_310;
if ( F_88 ( V_80 ) )
goto V_309;
if ( F_88 ( V_57 ) )
goto V_311;
if ( F_183 ( V_57 ) ) {
if ( ! F_222 ( V_154 , V_37 ) )
goto V_311;
} else if ( F_183 ( V_80 ) ) {
if ( ! F_222 ( V_154 , V_37 ) )
goto V_309;
}
V_83 . V_212 = 0 ;
V_83 . V_213 = V_53 -> V_99 ;
V_83 . V_202 = V_56 -> V_89 ;
V_83 . V_211 = V_87 ;
V_83 . V_312 = V_98 ;
V_83 . V_313 = 0 ;
V_83 . V_57 = V_57 ;
V_83 . V_80 = V_80 ;
V_260 = F_96 ( V_37 , & V_83 , & V_156 , 0 ) ;
if ( V_260 != 0 ) {
if ( ! F_118 ( V_154 ) )
V_260 = - V_186 ;
goto V_314;
}
if ( V_156 . type == V_315 )
goto V_310;
if ( V_156 . type == V_316 ) {
V_260 = F_186 ( V_56 , V_80 , V_57 , V_87 ,
0 , V_53 , V_154 , & V_235 ) ;
if ( V_260 < 0 )
goto V_309;
goto V_317;
}
if ( ! F_118 ( V_154 ) ) {
V_260 = - V_186 ;
goto V_314;
}
if ( V_156 . type != V_163 )
goto V_311;
V_260 = F_216 ( V_56 , & V_156 , & V_83 , V_154 , V_57 , V_80 , V_87 ) ;
V_185: return V_260 ;
V_310:
if ( V_56 -> V_81 != F_52 ( V_261 ) )
goto V_262;
if ( ! F_88 ( V_80 ) ) {
V_260 = F_186 ( V_56 , V_80 , 0 , V_87 , 0 , V_53 ,
V_154 , & V_235 ) ;
if ( V_260 < 0 )
goto V_309;
}
V_222 |= V_318 ;
V_156 . type = V_315 ;
F_190 ( V_20 ) ;
V_317:
V_279 = false ;
if ( V_156 . V_234 ) {
if ( ! V_235 ) {
V_51 = F_62 ( F_97 ( V_156 ) . V_143 ) ;
if ( F_174 ( V_51 ) ) {
F_212 ( V_56 , & V_51 -> V_2 ) ;
V_260 = 0 ;
goto V_185;
}
V_279 = true ;
}
}
V_51 = F_179 ( F_223 ( V_53 ) ? : V_37 -> V_232 ,
V_222 | V_255 , V_156 . type ,
F_187 ( V_154 , V_265 ) , false , V_279 ) ;
if ( ! V_51 )
goto V_266;
V_51 -> V_2 . V_253 = F_146 ;
#ifdef F_28
V_51 -> V_2 . V_215 = V_235 ;
#endif
V_51 -> V_250 = 1 ;
if ( V_156 . V_284 )
V_51 -> V_252 = V_156 . V_284 -> V_285 ;
F_190 ( V_17 ) ;
if ( V_156 . type == V_319 ) {
V_51 -> V_2 . V_256 = F_117 ;
V_51 -> V_2 . error = - V_260 ;
V_51 -> V_126 &= ~ V_255 ;
}
if ( V_279 ) {
struct V_129 * V_130 = & F_97 ( V_156 ) ;
V_51 -> V_2 . V_218 = F_177 ( V_130 -> V_242 ) ;
if ( F_204 ( V_51 -> V_2 . V_218 ) ) {
F_2 ( V_51 -> V_2 . V_256 == V_277 ) ;
V_51 -> V_2 . V_218 -> V_276 = V_51 -> V_2 . V_256 ;
V_51 -> V_2 . V_256 = V_277 ;
}
if ( F_157 ( ! F_163 ( V_130 , V_51 ) ) ) {
V_51 -> V_2 . V_222 |= V_223 ;
F_165 ( V_51 ) ;
}
}
F_191 ( V_56 , & V_51 -> V_2 ) ;
V_260 = 0 ;
goto V_185;
V_314:
F_190 ( V_19 ) ;
V_156 . type = V_319 ;
V_156 . V_234 = NULL ;
V_156 . V_284 = NULL ;
goto V_317;
V_311:
F_190 ( V_21 ) ;
#ifdef F_100
if ( F_101 ( V_154 ) )
F_114 ( L_18 ,
& V_57 , & V_80 , V_53 -> V_169 ) ;
#endif
V_262:
V_260 = - V_190 ;
goto V_185;
V_266:
V_260 = - V_268 ;
goto V_185;
V_309:
F_192 ( V_53 , V_154 , V_56 , V_57 , V_80 ) ;
goto V_185;
}
int F_224 ( struct V_55 * V_56 , T_6 V_57 , T_6 V_80 ,
T_9 V_87 , struct V_58 * V_53 )
{
int V_156 ;
F_61 () ;
if ( F_86 ( V_57 ) ) {
struct V_153 * V_154 = F_84 ( V_53 ) ;
int V_258 = 0 ;
if ( V_154 )
V_258 = F_225 ( V_154 , V_57 , V_80 ,
F_39 ( V_56 ) -> V_81 ) ;
if ( ( ! V_154 || ! V_258 ) && F_226 ( V_53 ) ) {
struct V_153 * V_320 ;
V_320 = F_84 ( V_56 -> V_53 ) ;
if ( V_320 )
V_258 = F_225 ( V_320 , V_57 , V_80 ,
F_39 ( V_56 ) -> V_81 ) ;
}
V_156 = - V_190 ;
if ( V_258
#ifdef F_188
||
( ! F_185 ( V_57 ) &&
F_189 ( V_154 ) )
#endif
) {
V_156 = F_182 ( V_56 , V_57 , V_80 ,
V_87 , V_53 , V_258 ) ;
}
F_64 () ;
return V_156 ;
}
V_156 = F_219 ( V_56 , V_57 , V_80 , V_87 , V_53 ) ;
F_64 () ;
return V_156 ;
}
static struct V_50 * F_227 ( const struct V_155 * V_156 ,
const struct V_82 * V_83 , int V_321 ,
struct V_58 * V_322 ,
unsigned int V_222 )
{
struct V_233 * V_234 = V_156 -> V_234 ;
struct V_110 * V_111 ;
struct V_153 * V_154 ;
T_12 type = V_156 -> type ;
struct V_50 * V_51 ;
bool V_279 ;
V_154 = F_84 ( V_322 ) ;
if ( ! V_154 )
return F_228 ( - V_190 ) ;
if ( F_229 ( ! F_184 ( V_154 ) ) )
if ( F_183 ( V_83 -> V_80 ) &&
! ( V_322 -> V_222 & V_323 ) &&
! F_230 ( V_322 ) )
return F_228 ( - V_190 ) ;
if ( F_87 ( V_83 -> V_57 ) )
type = V_315 ;
else if ( F_86 ( V_83 -> V_57 ) )
type = V_264 ;
else if ( F_88 ( V_83 -> V_57 ) )
return F_228 ( - V_190 ) ;
if ( V_322 -> V_222 & V_323 )
V_222 |= V_255 ;
V_279 = true ;
if ( type == V_315 ) {
V_222 |= V_318 | V_255 ;
V_234 = NULL ;
} else if ( type == V_264 ) {
V_222 |= V_259 | V_255 ;
if ( ! F_225 ( V_154 , V_83 -> V_57 , V_83 -> V_80 ,
V_83 -> V_324 ) )
V_222 &= ~ V_255 ;
else
V_279 = false ;
if ( V_234 && V_156 -> V_325 < 4 )
V_234 = NULL ;
} else if ( ( type == V_316 ) && ( V_321 != 0 ) &&
( V_321 != V_322 -> V_99 ) ) {
V_234 = NULL ;
}
V_111 = NULL ;
V_279 &= V_234 != NULL ;
if ( V_279 ) {
struct V_50 T_11 * * V_326 ;
struct V_129 * V_130 = & F_97 ( * V_156 ) ;
V_111 = F_160 ( V_130 , V_83 -> V_57 ) ;
if ( V_111 ) {
V_326 = & V_111 -> V_113 ;
V_51 = F_62 ( * V_326 ) ;
if ( V_51 && V_51 -> V_2 . V_123 &&
F_113 ( V_73 , V_51 -> V_2 . V_123 ) ) {
F_198 ( V_130 , V_83 -> V_57 ) ;
V_111 = NULL ;
} else {
goto V_282;
}
}
if ( F_157 ( V_83 -> V_313 &
V_327 &&
! ( V_130 -> V_237 &&
V_130 -> V_238 == V_239 ) ) ) {
V_279 = false ;
goto V_328;
}
V_326 = F_164 ( V_130 -> V_147 ) ;
V_51 = F_62 ( * V_326 ) ;
V_282:
if ( F_174 ( V_51 ) ) {
F_231 ( & V_51 -> V_2 ) ;
return V_51 ;
}
}
V_328:
V_51 = F_179 ( V_322 , V_222 , type ,
F_187 ( V_154 , V_265 ) ,
F_187 ( V_154 , V_283 ) ,
V_279 ) ;
if ( ! V_51 )
return F_228 ( - V_268 ) ;
V_51 -> V_251 = V_321 ? : 0 ;
if ( V_156 -> V_284 )
V_51 -> V_252 = V_156 -> V_284 -> V_285 ;
F_190 ( V_23 ) ;
if ( V_222 & ( V_318 | V_259 ) ) {
if ( V_222 & V_255 &&
! ( V_322 -> V_222 & V_323 ) ) {
V_51 -> V_2 . V_253 = V_329 ;
F_190 ( V_24 ) ;
}
#ifdef F_188
if ( type == V_264 ) {
if ( F_189 ( V_154 ) &&
! F_185 ( V_83 -> V_57 ) ) {
V_51 -> V_2 . V_256 = V_267 ;
V_51 -> V_2 . V_253 = V_329 ;
}
}
#endif
}
F_175 ( V_51 , V_83 -> V_57 , V_156 , V_111 , V_234 , type , 0 ) ;
F_202 ( V_51 ) ;
return V_51 ;
}
struct V_50 * F_232 ( struct V_37 * V_37 , struct V_82 * V_83 ,
int V_330 )
{
struct V_58 * V_322 = NULL ;
T_13 V_87 = F_233 ( V_83 ) ;
unsigned int V_222 = 0 ;
struct V_155 V_156 ;
struct V_50 * V_51 ;
int V_321 ;
int V_260 = - V_188 ;
V_156 . V_215 = 0 ;
V_156 . V_234 = NULL ;
V_156 . V_284 = NULL ;
V_321 = V_83 -> V_212 ;
V_83 -> V_213 = V_331 ;
V_83 -> V_211 = V_87 & V_332 ;
V_83 -> V_312 = ( ( V_87 & V_333 ) ?
V_239 : V_98 ) ;
F_61 () ;
if ( V_83 -> V_80 ) {
V_51 = F_228 ( - V_190 ) ;
if ( F_86 ( V_83 -> V_80 ) ||
F_87 ( V_83 -> V_80 ) ||
F_88 ( V_83 -> V_80 ) )
goto V_185;
if ( V_83 -> V_212 == 0 &&
( F_86 ( V_83 -> V_57 ) ||
F_87 ( V_83 -> V_57 ) ) ) {
V_322 = F_234 ( V_37 , V_83 -> V_80 , false ) ;
if ( ! V_322 )
goto V_185;
V_83 -> V_212 = V_322 -> V_99 ;
goto V_334;
}
if ( ! ( V_83 -> V_313 & V_335 ) ) {
if ( ! F_234 ( V_37 , V_83 -> V_80 , false ) )
goto V_185;
}
}
if ( V_83 -> V_212 ) {
V_322 = F_235 ( V_37 , V_83 -> V_212 ) ;
V_51 = F_228 ( - V_336 ) ;
if ( ! V_322 )
goto V_185;
if ( ! ( V_322 -> V_222 & V_337 ) || ! F_84 ( V_322 ) ) {
V_51 = F_228 ( - V_188 ) ;
goto V_185;
}
if ( F_185 ( V_83 -> V_57 ) ||
F_87 ( V_83 -> V_57 ) ||
V_83 -> V_324 == V_338 ) {
if ( ! V_83 -> V_80 )
V_83 -> V_80 = F_151 ( V_322 , 0 ,
V_239 ) ;
goto V_334;
}
if ( ! V_83 -> V_80 ) {
if ( F_86 ( V_83 -> V_57 ) )
V_83 -> V_80 = F_151 ( V_322 , 0 ,
V_83 -> V_312 ) ;
else if ( ! V_83 -> V_57 )
V_83 -> V_80 = F_151 ( V_322 , 0 ,
V_339 ) ;
}
}
if ( ! V_83 -> V_57 ) {
V_83 -> V_57 = V_83 -> V_80 ;
if ( ! V_83 -> V_57 )
V_83 -> V_57 = V_83 -> V_80 = F_236 ( V_340 ) ;
V_322 = V_37 -> V_232 ;
V_83 -> V_212 = V_331 ;
V_156 . type = V_316 ;
V_222 |= V_255 ;
goto V_334;
}
V_260 = F_96 ( V_37 , V_83 , & V_156 , 0 ) ;
if ( V_260 ) {
V_156 . V_234 = NULL ;
V_156 . V_284 = NULL ;
if ( V_83 -> V_212 &&
( F_86 ( V_83 -> V_57 ) ||
! F_237 ( V_37 , V_83 -> V_212 ) ) ) {
if ( V_83 -> V_80 == 0 )
V_83 -> V_80 = F_151 ( V_322 , 0 ,
V_239 ) ;
V_156 . type = V_163 ;
goto V_334;
}
V_51 = F_228 ( V_260 ) ;
goto V_185;
}
if ( V_156 . type == V_316 ) {
if ( ! V_83 -> V_80 ) {
if ( V_156 . V_234 -> V_341 )
V_83 -> V_80 = V_156 . V_234 -> V_341 ;
else
V_83 -> V_80 = V_83 -> V_57 ;
}
V_322 = F_223 ( V_322 ) ? : V_37 -> V_232 ;
V_83 -> V_212 = V_322 -> V_99 ;
V_222 |= V_255 ;
goto V_334;
}
F_238 ( V_37 , & V_156 , V_83 , V_330 ) ;
V_322 = F_206 ( V_156 ) ;
V_83 -> V_212 = V_322 -> V_99 ;
V_334:
V_51 = F_227 ( & V_156 , V_83 , V_321 , V_322 , V_222 ) ;
V_185:
F_64 () ;
return V_51 ;
}
static struct V_1 * F_239 ( struct V_1 * V_2 , T_1 V_207 )
{
return NULL ;
}
static unsigned int F_240 ( const struct V_1 * V_2 )
{
unsigned int V_198 = F_154 ( V_2 , V_199 ) ;
return V_198 ? : V_2 -> V_53 -> V_198 ;
}
static void F_241 ( struct V_1 * V_2 , struct V_84 * V_85 ,
struct V_55 * V_56 , T_1 V_198 )
{
}
static void F_242 ( struct V_1 * V_2 , struct V_84 * V_85 ,
struct V_55 * V_56 )
{
}
static T_1 * F_243 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
return NULL ;
}
struct V_1 * F_244 ( struct V_37 * V_37 , struct V_1 * V_342 )
{
struct V_50 * V_343 = (struct V_50 * ) V_342 ;
struct V_50 * V_60 ;
V_60 = F_180 ( & V_344 , NULL , 1 , V_345 , 0 ) ;
if ( V_60 ) {
struct V_1 * V_74 = & V_60 -> V_2 ;
V_74 -> V_346 = 1 ;
V_74 -> V_256 = V_347 ;
V_74 -> V_253 = V_348 ;
V_74 -> V_53 = V_343 -> V_2 . V_53 ;
if ( V_74 -> V_53 )
F_172 ( V_74 -> V_53 ) ;
V_60 -> V_250 = V_343 -> V_250 ;
V_60 -> V_251 = V_343 -> V_251 ;
V_60 -> V_121 = V_343 -> V_121 ;
V_60 -> V_52 = F_34 ( V_37 ) ;
V_60 -> V_126 = V_343 -> V_126 ;
V_60 -> V_249 = V_343 -> V_249 ;
V_60 -> V_62 = V_343 -> V_62 ;
V_60 -> V_128 = V_343 -> V_128 ;
F_181 ( & V_60 -> V_230 ) ;
F_245 ( V_74 ) ;
}
F_138 ( V_342 ) ;
return V_60 ? & V_60 -> V_2 : F_228 ( - V_32 ) ;
}
struct V_50 * F_136 ( struct V_37 * V_37 , struct V_82 * V_349 ,
const struct V_84 * V_85 )
{
struct V_50 * V_60 = F_128 ( V_37 , V_349 ) ;
if ( F_94 ( V_60 ) )
return V_60 ;
if ( V_349 -> V_324 )
V_60 = (struct V_50 * ) F_246 ( V_37 , & V_60 -> V_2 ,
F_247 ( V_349 ) ,
V_85 , 0 ) ;
return V_60 ;
}
static int F_248 ( struct V_37 * V_37 , T_6 V_2 , T_6 V_28 , T_1 V_350 ,
struct V_82 * V_83 , struct V_55 * V_56 , T_1 V_351 ,
T_1 V_5 , int V_352 , int V_353 , unsigned int V_222 )
{
struct V_50 * V_60 = F_107 ( V_56 ) ;
struct V_354 * V_355 ;
struct V_356 * V_357 ;
unsigned long V_123 = 0 ;
T_1 error ;
T_1 V_358 [ V_359 ] ;
V_357 = F_249 ( V_56 , V_351 , V_5 , V_352 , sizeof( * V_355 ) , V_222 ) ;
if ( ! V_357 )
return - V_360 ;
V_355 = F_250 ( V_357 ) ;
V_355 -> V_361 = V_362 ;
V_355 -> V_363 = 32 ;
V_355 -> V_364 = 0 ;
V_355 -> V_365 = V_83 -> V_211 ;
V_355 -> V_366 = V_350 < 256 ? V_350 : V_367 ;
if ( F_251 ( V_56 , V_368 , V_350 ) )
goto V_369;
V_355 -> V_370 = V_60 -> V_249 ;
V_355 -> V_371 = V_98 ;
V_355 -> V_372 = V_373 ;
V_355 -> V_374 = ( V_60 -> V_126 & ~ 0xFFFF ) | V_375 ;
if ( V_60 -> V_126 & V_376 )
V_355 -> V_374 |= V_377 ;
if ( F_210 ( V_56 ) -> V_222 & V_281 )
V_355 -> V_374 |= V_378 ;
if ( F_252 ( V_56 , V_379 , V_2 ) )
goto V_369;
if ( V_28 ) {
V_355 -> V_364 = 32 ;
if ( F_252 ( V_56 , V_380 , V_28 ) )
goto V_369;
}
if ( V_60 -> V_2 . V_53 &&
F_251 ( V_56 , V_381 , V_60 -> V_2 . V_53 -> V_99 ) )
goto V_369;
#ifdef F_28
if ( V_60 -> V_2 . V_215 &&
F_251 ( V_56 , V_382 , V_60 -> V_2 . V_215 ) )
goto V_369;
#endif
if ( ! F_162 ( V_60 ) &&
V_83 -> V_80 != V_28 ) {
if ( F_252 ( V_56 , V_383 , V_83 -> V_80 ) )
goto V_369;
}
if ( V_60 -> V_128 &&
F_252 ( V_56 , V_384 , V_60 -> V_62 ) )
goto V_369;
V_123 = V_60 -> V_2 . V_123 ;
if ( V_123 ) {
unsigned long V_72 = V_73 ;
if ( F_71 ( V_72 , V_123 ) )
V_123 -= V_72 ;
else
V_123 = 0 ;
}
memcpy ( V_358 , F_253 ( & V_60 -> V_2 ) , sizeof( V_358 ) ) ;
if ( V_60 -> V_121 && V_123 )
V_358 [ V_199 - 1 ] = V_60 -> V_121 ;
if ( F_254 ( V_56 , V_358 ) < 0 )
goto V_369;
if ( V_83 -> V_202 &&
F_251 ( V_56 , V_385 , V_83 -> V_202 ) )
goto V_369;
if ( ! F_255 ( V_83 -> V_386 , V_387 ) &&
F_251 ( V_56 , V_388 ,
F_256 ( F_257 () , V_83 -> V_386 ) ) )
goto V_369;
error = V_60 -> V_2 . error ;
if ( F_162 ( V_60 ) ) {
#ifdef F_188
if ( F_86 ( V_2 ) && ! F_185 ( V_2 ) &&
F_258 ( V_37 , V_389 ) ) {
int V_260 = F_259 ( V_37 , V_56 ,
V_83 -> V_80 , V_83 -> V_57 ,
V_355 , V_353 , V_351 ) ;
if ( V_260 <= 0 ) {
if ( ! V_353 ) {
if ( V_260 == 0 )
return 0 ;
goto V_369;
} else {
if ( V_260 == - V_360 )
goto V_369;
error = V_260 ;
}
}
} else
#endif
if ( F_251 ( V_56 , V_390 , V_56 -> V_53 -> V_99 ) )
goto V_369;
}
if ( F_260 ( V_56 , & V_60 -> V_2 , 0 , V_123 , error ) < 0 )
goto V_369;
F_261 ( V_56 , V_357 ) ;
return 0 ;
V_369:
F_262 ( V_56 , V_357 ) ;
return - V_360 ;
}
static int F_263 ( struct V_55 * V_391 , struct V_356 * V_357 )
{
struct V_37 * V_37 = F_130 ( V_391 -> V_85 ) ;
struct V_354 * V_392 ;
struct V_393 * V_394 [ V_395 + 1 ] ;
struct V_50 * V_60 = NULL ;
struct V_82 V_83 ;
T_6 V_2 = 0 ;
T_6 V_28 = 0 ;
T_1 V_396 ;
int V_260 ;
int V_89 ;
struct V_55 * V_56 ;
T_1 V_350 = V_397 ;
T_14 V_398 ;
V_260 = F_264 ( V_357 , sizeof( * V_392 ) , V_394 , V_395 , V_399 ) ;
if ( V_260 < 0 )
goto V_400;
V_392 = F_250 ( V_357 ) ;
V_56 = F_265 ( V_401 , V_31 ) ;
if ( ! V_56 ) {
V_260 = - V_268 ;
goto V_400;
}
F_266 ( V_56 ) ;
F_267 ( V_56 ) ;
F_39 ( V_56 ) -> V_81 = V_301 ;
F_268 ( V_56 , V_402 + sizeof( struct V_76 ) ) ;
V_28 = V_394 [ V_380 ] ? F_269 ( V_394 [ V_380 ] ) : 0 ;
V_2 = V_394 [ V_379 ] ? F_269 ( V_394 [ V_379 ] ) : 0 ;
V_396 = V_394 [ V_390 ] ? F_270 ( V_394 [ V_390 ] ) : 0 ;
V_89 = V_394 [ V_385 ] ? F_270 ( V_394 [ V_385 ] ) : 0 ;
if ( V_394 [ V_388 ] )
V_398 = F_271 ( F_257 () , F_270 ( V_394 [ V_388 ] ) ) ;
else
V_398 = ( V_396 ? V_387 : F_272 () ) ;
memset ( & V_83 , 0 , sizeof( V_83 ) ) ;
V_83 . V_57 = V_2 ;
V_83 . V_80 = V_28 ;
V_83 . V_211 = V_392 -> V_365 ;
V_83 . V_212 = V_394 [ V_381 ] ? F_270 ( V_394 [ V_381 ] ) : 0 ;
V_83 . V_202 = V_89 ;
V_83 . V_386 = V_398 ;
if ( V_396 ) {
struct V_58 * V_53 ;
V_53 = F_273 ( V_37 , V_396 ) ;
if ( ! V_53 ) {
V_260 = - V_336 ;
goto V_403;
}
V_56 -> V_81 = F_52 ( V_261 ) ;
V_56 -> V_53 = V_53 ;
V_56 -> V_89 = V_89 ;
F_274 () ;
V_260 = F_275 ( V_56 , V_2 , V_28 , V_392 -> V_365 , V_53 ) ;
F_276 () ;
V_60 = F_107 ( V_56 ) ;
if ( V_260 == 0 && V_60 -> V_2 . error )
V_260 = - V_60 -> V_2 . error ;
} else {
V_60 = F_277 ( V_37 , & V_83 ) ;
V_260 = 0 ;
if ( F_94 ( V_60 ) )
V_260 = F_278 ( V_60 ) ;
}
if ( V_260 )
goto V_403;
F_191 ( V_56 , & V_60 -> V_2 ) ;
if ( V_392 -> V_374 & V_377 )
V_60 -> V_126 |= V_376 ;
if ( V_392 -> V_374 & V_404 )
V_350 = V_60 -> V_252 ;
V_260 = F_248 ( V_37 , V_2 , V_28 , V_350 , & V_83 , V_56 ,
F_279 ( V_391 ) . V_351 , V_357 -> V_405 ,
V_406 , 0 , 0 ) ;
if ( V_260 < 0 )
goto V_403;
V_260 = F_280 ( V_56 , V_37 , F_279 ( V_391 ) . V_351 ) ;
V_400:
return V_260 ;
V_403:
F_121 ( V_56 ) ;
goto V_400;
}
void F_281 ( struct V_153 * V_154 )
{
F_36 ( F_35 ( V_154 -> V_53 ) ) ;
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
return - V_190 ;
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
V_37 -> V_175 . V_421 = F_287 ( V_37 , L_19 , V_414 ) ;
if ( ! V_37 -> V_175 . V_421 )
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
V_414 = V_37 -> V_175 . V_421 -> V_423 ;
F_289 ( V_37 -> V_175 . V_421 ) ;
F_290 ( V_414 == V_415 ) ;
F_23 ( V_414 ) ;
}
static T_3 int F_291 ( struct V_37 * V_37 )
{
F_292 ( & V_37 -> V_175 . V_52 , 0 ) ;
F_292 ( & V_37 -> V_141 , 0 ) ;
F_293 ( & V_37 -> V_175 . V_424 ,
sizeof( V_37 -> V_175 . V_424 ) ) ;
return 0 ;
}
static int T_3 F_294 ( struct V_37 * V_37 )
{
struct V_425 * V_426 = F_295 ( sizeof( * V_426 ) , V_31 ) ;
if ( ! V_426 )
return - V_32 ;
F_296 ( V_426 ) ;
V_37 -> V_175 . V_176 = V_426 ;
return 0 ;
}
static void T_4 F_297 ( struct V_37 * V_37 )
{
struct V_425 * V_426 = V_37 -> V_175 . V_176 ;
V_37 -> V_175 . V_176 = NULL ;
F_298 ( V_426 ) ;
F_23 ( V_426 ) ;
}
int T_5 F_299 ( void )
{
int V_427 = 0 ;
int V_12 ;
V_71 = F_295 ( V_69 * sizeof( * V_71 ) , V_31 ) ;
if ( ! V_71 )
F_300 ( L_20 ) ;
F_301 ( V_71 , V_69 * sizeof( * V_71 ) ) ;
V_68 = F_19 ( V_69 , sizeof( * V_68 ) , V_31 ) ;
if ( ! V_68 )
F_300 ( L_21 ) ;
F_20 (cpu) {
struct V_226 * V_227 = & F_12 ( V_228 , V_12 ) ;
F_181 ( & V_227 -> V_231 ) ;
F_302 ( & V_227 -> V_229 ) ;
}
#ifdef F_28
V_27 = F_303 ( 256 * sizeof( struct V_27 ) , F_304 ( struct V_27 ) ) ;
if ( ! V_27 )
F_300 ( L_22 ) ;
#endif
V_16 . V_428 =
F_305 ( L_23 , sizeof( struct V_50 ) , 0 ,
V_429 | V_430 , NULL ) ;
V_344 . V_428 = V_16 . V_428 ;
if ( F_306 ( & V_16 ) < 0 )
F_300 ( L_24 ) ;
if ( F_306 ( & V_344 ) < 0 )
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
F_313 ( V_434 , V_435 , F_263 , NULL , NULL ) ;
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
