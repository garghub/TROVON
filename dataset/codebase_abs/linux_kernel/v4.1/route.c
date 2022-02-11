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
struct V_67 * V_68 = V_69 + V_65 % V_70 ;
T_1 V_3 = F_43 ( V_68 -> V_71 ) ;
T_1 V_72 = ( T_1 ) V_73 ;
T_1 V_74 = 0 ;
if ( V_3 != V_72 && F_44 ( & V_68 -> V_71 , V_3 , V_72 ) == V_3 )
V_74 = F_45 ( V_72 - V_3 ) ;
return F_46 ( V_66 + V_74 , & V_68 -> V_75 ) - V_66 ;
}
void F_47 ( struct V_37 * V_37 , struct V_76 * V_77 , int V_66 )
{
static T_1 T_7 V_78 ;
T_1 V_65 , V_75 ;
F_48 ( & T_7 , sizeof( T_7 ) ) ;
V_65 = F_49 ( ( V_63 T_1 ) V_77 -> V_57 ,
( V_63 T_1 ) V_77 -> V_79 ,
V_77 -> V_80 ^ F_50 ( V_37 ) ,
T_7 ) ;
V_75 = F_42 ( V_65 , V_66 ) ;
V_77 -> V_75 = F_51 ( V_75 ) ;
}
static void F_52 ( struct V_81 * V_82 , const struct V_83 * V_84 ,
const struct V_76 * V_77 ,
int V_85 , T_8 V_86 ,
T_8 V_87 , T_1 V_88 , int V_89 )
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
V_77 -> V_57 , V_77 -> V_79 , 0 , 0 ) ;
}
static void F_56 ( struct V_81 * V_82 , const struct V_55 * V_56 ,
const struct V_83 * V_84 )
{
const struct V_76 * V_77 = F_39 ( V_56 ) ;
int V_85 = V_56 -> V_53 -> V_98 ;
T_8 V_86 = F_57 ( V_77 -> V_86 ) ;
T_8 V_87 = V_77 -> V_80 ;
T_1 V_88 = V_56 -> V_88 ;
F_52 ( V_82 , V_84 , V_77 , V_85 , V_86 , V_87 , V_88 , 0 ) ;
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
static T_1 T_9 V_78 ;
T_1 V_117 ;
F_48 ( & T_9 , sizeof( T_9 ) ) ;
V_117 = F_71 ( ( V_63 T_1 ) V_57 , T_9 ) ;
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
struct V_50 T_10 * * V_144 ;
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
if ( F_94 ( V_37 , V_82 , & V_154 ) == 0 ) {
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
const struct V_76 * V_77 = ( const struct V_76 * ) V_56 -> V_165 ;
T_6 V_57 = V_77 -> V_57 ;
T_6 V_79 = V_77 -> V_79 ;
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
const struct V_76 * V_77 = ( const struct V_76 * ) V_56 -> V_165 ;
int V_85 = V_56 -> V_53 -> V_98 ;
T_8 V_86 = F_57 ( V_77 -> V_86 ) ;
T_8 V_87 = V_77 -> V_80 ;
T_1 V_88 = V_56 -> V_88 ;
V_60 = (struct V_50 * ) V_2 ;
F_52 ( & V_82 , V_84 , V_77 , V_85 , V_86 , V_87 , V_88 , 0 ) ;
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
F_59 () ;
V_152 = F_82 ( V_60 -> V_2 . V_53 ) ;
if ( ! V_152 || ! F_106 ( V_152 ) ) {
F_62 () ;
return;
}
V_170 = F_99 ( V_152 ) ;
F_62 () ;
V_37 = F_35 ( V_60 -> V_2 . V_53 ) ;
V_169 = F_107 ( V_37 -> V_171 . V_172 , F_39 ( V_56 ) -> V_79 , 1 ) ;
if ( ! V_169 ) {
F_108 ( V_56 , V_173 , V_158 ,
F_109 ( V_60 , F_39 ( V_56 ) -> V_57 ) ) ;
return;
}
if ( F_110 ( V_73 , V_169 -> V_174 + V_175 ) )
V_169 -> V_176 = 0 ;
if ( V_169 -> V_176 >= V_177 ) {
V_169 -> V_174 = V_73 ;
goto V_178;
}
if ( V_169 -> V_176 == 0 ||
F_110 ( V_73 ,
( V_169 -> V_174 +
( V_179 << V_169 -> V_176 ) ) ) ) {
T_6 V_129 = F_109 ( V_60 , F_39 ( V_56 ) -> V_57 ) ;
F_108 ( V_56 , V_173 , V_158 , V_129 ) ;
V_169 -> V_174 = V_73 ;
++ V_169 -> V_176 ;
#ifdef F_98
if ( V_170 &&
V_169 -> V_176 == V_177 )
F_111 ( L_12 ,
& F_39 ( V_56 ) -> V_79 , F_112 ( V_56 ) ,
& F_39 ( V_56 ) -> V_57 , & V_129 ) ;
#endif
}
V_178:
F_113 ( V_169 ) ;
}
static int F_114 ( struct V_55 * V_56 )
{
struct V_151 * V_152 = F_82 ( V_56 -> V_53 ) ;
struct V_50 * V_60 = F_105 ( V_56 ) ;
struct V_168 * V_169 ;
unsigned long V_72 ;
struct V_37 * V_37 ;
bool V_180 ;
int V_155 ;
if ( ! V_152 )
goto V_181;
V_37 = F_35 ( V_60 -> V_2 . V_53 ) ;
if ( ! F_115 ( V_152 ) ) {
switch ( V_60 -> V_2 . error ) {
case V_182 :
F_116 ( V_37 , V_183 ) ;
break;
case V_184 :
F_116 ( V_37 , V_185 ) ;
break;
}
goto V_181;
}
switch ( V_60 -> V_2 . error ) {
case V_186 :
default:
goto V_181;
case V_182 :
V_155 = V_187 ;
break;
case V_184 :
V_155 = V_188 ;
F_116 ( V_37 , V_185 ) ;
break;
case V_189 :
V_155 = V_190 ;
break;
}
V_169 = F_107 ( V_37 -> V_171 . V_172 , F_39 ( V_56 ) -> V_79 , 1 ) ;
V_180 = true ;
if ( V_169 ) {
V_72 = V_73 ;
V_169 -> V_176 += V_72 - V_169 -> V_174 ;
if ( V_169 -> V_176 > V_191 )
V_169 -> V_176 = V_191 ;
V_169 -> V_174 = V_72 ;
if ( V_169 -> V_176 >= V_192 )
V_169 -> V_176 -= V_192 ;
else
V_180 = false ;
F_113 ( V_169 ) ;
}
if ( V_180 )
F_108 ( V_56 , V_193 , V_155 , 0 ) ;
V_181: F_117 ( V_56 ) ;
return 0 ;
}
static void F_118 ( struct V_50 * V_60 , struct V_81 * V_82 , T_1 V_194 )
{
struct V_1 * V_2 = & V_60 -> V_2 ;
struct V_153 V_154 ;
if ( F_119 ( V_2 , V_195 ) )
return;
if ( F_120 ( V_2 ) < V_194 )
return;
if ( V_194 < V_196 )
V_194 = V_196 ;
if ( V_60 -> V_119 == V_194 &&
F_69 ( V_73 , V_2 -> V_121 - V_197 / 2 ) )
return;
F_59 () ;
if ( F_94 ( F_35 ( V_2 -> V_53 ) , V_82 , & V_154 ) == 0 ) {
struct V_127 * V_128 = & F_95 ( V_154 ) ;
F_74 ( V_128 , V_82 -> V_57 , 0 , V_194 ,
V_73 + V_197 ) ;
}
F_62 () ;
}
static void F_121 ( struct V_1 * V_2 , struct V_83 * V_84 ,
struct V_55 * V_56 , T_1 V_194 )
{
struct V_50 * V_60 = (struct V_50 * ) V_2 ;
struct V_81 V_82 ;
F_63 ( & V_82 , V_84 , V_56 ) ;
F_118 ( V_60 , & V_82 , V_194 ) ;
}
void F_122 ( struct V_55 * V_56 , struct V_37 * V_37 , T_1 V_194 ,
int V_85 , T_1 V_88 , T_8 V_80 , int V_89 )
{
const struct V_76 * V_77 = ( const struct V_76 * ) V_56 -> V_165 ;
struct V_81 V_82 ;
struct V_50 * V_60 ;
if ( ! V_88 )
V_88 = F_123 ( V_37 , V_56 -> V_88 ) ;
F_52 ( & V_82 , NULL , V_77 , V_85 ,
F_57 ( V_77 -> V_86 ) , V_80 , V_88 , V_89 ) ;
V_60 = F_124 ( V_37 , & V_82 ) ;
if ( ! F_92 ( V_60 ) ) {
F_118 ( V_60 , & V_82 , V_194 ) ;
F_103 ( V_60 ) ;
}
}
static void F_125 ( struct V_55 * V_56 , struct V_83 * V_84 , T_1 V_194 )
{
const struct V_76 * V_77 = ( const struct V_76 * ) V_56 -> V_165 ;
struct V_81 V_82 ;
struct V_50 * V_60 ;
F_52 ( & V_82 , V_84 , V_77 , 0 , 0 , 0 , 0 , 0 ) ;
if ( ! V_82 . V_198 )
V_82 . V_198 = F_123 ( F_126 ( V_84 ) , V_56 -> V_88 ) ;
V_60 = F_124 ( F_126 ( V_84 ) , & V_82 ) ;
if ( ! F_92 ( V_60 ) ) {
F_118 ( V_60 , & V_82 , V_194 ) ;
F_103 ( V_60 ) ;
}
}
void F_127 ( struct V_55 * V_56 , struct V_83 * V_84 , T_1 V_194 )
{
const struct V_76 * V_77 = ( const struct V_76 * ) V_56 -> V_165 ;
struct V_81 V_82 ;
struct V_50 * V_60 ;
struct V_1 * V_199 = NULL ;
bool V_200 = false ;
F_128 ( V_84 ) ;
if ( ! F_129 ( V_84 ) )
goto V_181;
V_199 = F_130 ( V_84 ) ;
if ( F_131 ( V_84 ) || ! V_199 ) {
F_125 ( V_56 , V_84 , V_194 ) ;
goto V_181;
}
F_52 ( & V_82 , V_84 , V_77 , 0 , 0 , 0 , 0 , 0 ) ;
V_60 = (struct V_50 * ) V_199 ;
if ( V_199 -> V_142 && ! V_199 -> V_201 -> V_202 ( V_199 , 0 ) ) {
V_60 = F_132 ( F_126 ( V_84 ) , & V_82 , V_84 ) ;
if ( F_92 ( V_60 ) )
goto V_181;
V_200 = true ;
}
F_118 ( (struct V_50 * ) V_60 -> V_2 . V_203 , & V_82 , V_194 ) ;
if ( ! F_133 ( & V_60 -> V_2 , 0 ) ) {
if ( V_200 )
F_134 ( & V_60 -> V_2 ) ;
V_60 = F_132 ( F_126 ( V_84 ) , & V_82 , V_84 ) ;
if ( F_92 ( V_60 ) )
goto V_181;
V_200 = true ;
}
if ( V_200 )
F_135 ( V_84 , & V_60 -> V_2 ) ;
V_181:
F_136 ( V_84 ) ;
F_134 ( V_199 ) ;
}
void F_137 ( struct V_55 * V_56 , struct V_37 * V_37 ,
int V_85 , T_1 V_88 , T_8 V_80 , int V_89 )
{
const struct V_76 * V_77 = ( const struct V_76 * ) V_56 -> V_165 ;
struct V_81 V_82 ;
struct V_50 * V_60 ;
F_52 ( & V_82 , NULL , V_77 , V_85 ,
F_57 ( V_77 -> V_86 ) , V_80 , V_88 , V_89 ) ;
V_60 = F_124 ( V_37 , & V_82 ) ;
if ( ! F_92 ( V_60 ) ) {
F_80 ( V_60 , V_56 , & V_82 , false ) ;
F_103 ( V_60 ) ;
}
}
void F_138 ( struct V_55 * V_56 , struct V_83 * V_84 )
{
const struct V_76 * V_77 = ( const struct V_76 * ) V_56 -> V_165 ;
struct V_81 V_82 ;
struct V_50 * V_60 ;
F_52 ( & V_82 , V_84 , V_77 , 0 , 0 , 0 , 0 , 0 ) ;
V_60 = F_124 ( F_126 ( V_84 ) , & V_82 ) ;
if ( ! F_92 ( V_60 ) ) {
F_80 ( V_60 , V_56 , & V_82 , false ) ;
F_103 ( V_60 ) ;
}
}
static struct V_1 * F_139 ( struct V_1 * V_2 , T_1 V_204 )
{
struct V_50 * V_60 = (struct V_50 * ) V_2 ;
if ( V_2 -> V_142 != V_205 || F_33 ( V_60 ) )
return NULL ;
return V_2 ;
}
static void F_140 ( struct V_55 * V_56 )
{
struct V_50 * V_60 ;
F_108 ( V_56 , V_193 , V_187 , 0 ) ;
V_60 = F_105 ( V_56 ) ;
if ( V_60 )
F_141 ( & V_60 -> V_2 , 0 ) ;
}
static int F_142 ( struct V_83 * V_84 , struct V_55 * V_56 )
{
F_143 ( L_13 ,
V_206 , & F_39 ( V_56 ) -> V_79 , & F_39 ( V_56 ) -> V_57 ,
V_56 -> V_53 ? V_56 -> V_53 -> V_166 : L_14 ) ;
F_117 ( V_56 ) ;
F_2 ( 1 ) ;
return 0 ;
}
void F_144 ( T_8 * V_207 , struct V_55 * V_56 , struct V_50 * V_60 )
{
T_6 V_28 ;
if ( F_145 ( V_60 ) )
V_28 = F_39 ( V_56 ) -> V_79 ;
else {
struct V_153 V_154 ;
struct V_81 V_82 ;
struct V_76 * V_77 ;
V_77 = F_39 ( V_56 ) ;
memset ( & V_82 , 0 , sizeof( V_82 ) ) ;
V_82 . V_57 = V_77 -> V_57 ;
V_82 . V_79 = V_77 -> V_79 ;
V_82 . V_208 = F_57 ( V_77 -> V_86 ) ;
V_82 . V_209 = V_60 -> V_2 . V_53 -> V_98 ;
V_82 . V_210 = V_56 -> V_53 -> V_98 ;
V_82 . V_198 = V_56 -> V_88 ;
F_59 () ;
if ( F_94 ( F_35 ( V_60 -> V_2 . V_53 ) , & V_82 , & V_154 ) == 0 )
V_28 = F_146 ( F_35 ( V_60 -> V_2 . V_53 ) , V_154 ) ;
else
V_28 = F_147 ( V_60 -> V_2 . V_53 ,
F_109 ( V_60 , V_77 -> V_57 ) ,
V_97 ) ;
F_62 () ;
}
memcpy ( V_207 , & V_28 , 4 ) ;
}
static void F_148 ( struct V_50 * V_60 , T_1 V_211 )
{
if ( ! ( V_60 -> V_2 . V_212 & 0xFFFF ) )
V_60 -> V_2 . V_212 |= V_211 & 0xFFFF ;
if ( ! ( V_60 -> V_2 . V_212 & 0xFFFF0000 ) )
V_60 -> V_2 . V_212 |= V_211 & 0xFFFF0000 ;
}
static unsigned int F_149 ( const struct V_1 * V_2 )
{
unsigned int V_213 = F_150 ( V_2 , V_214 ) ;
if ( V_213 == 0 ) {
V_213 = F_151 (unsigned int, dst->dev->mtu - 40 ,
ip_rt_min_advmss) ;
if ( V_213 > 65535 - 40 )
V_213 = 65535 - 40 ;
}
return V_213 ;
}
static unsigned int F_120 ( const struct V_1 * V_2 )
{
const struct V_50 * V_60 = ( const struct V_50 * ) V_2 ;
unsigned int V_194 = V_60 -> V_119 ;
if ( ! V_194 || F_152 ( V_73 , V_60 -> V_2 . V_121 ) )
V_194 = F_150 ( V_2 , V_195 ) ;
if ( V_194 )
return V_194 ;
V_194 = V_2 -> V_53 -> V_194 ;
if ( F_153 ( F_119 ( V_2 , V_195 ) ) ) {
if ( V_60 -> V_126 && V_194 > 576 )
V_194 = 576 ;
}
return F_154 (unsigned int, mtu, IP_MAX_MTU) ;
}
static struct V_108 * F_155 ( struct V_127 * V_128 , T_6 V_57 )
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
static bool F_156 ( struct V_50 * V_60 , struct V_108 * V_109 ,
T_6 V_57 )
{
bool V_167 = false ;
F_75 ( & V_132 ) ;
if ( V_57 == V_109 -> V_137 ) {
struct V_50 T_10 * * V_215 ;
struct V_50 * V_216 ;
int V_217 = V_139 ( F_35 ( V_60 -> V_2 . V_53 ) ) ;
if ( F_157 ( V_60 ) )
V_215 = & V_109 -> V_110 ;
else
V_215 = & V_109 -> V_111 ;
V_216 = F_60 ( * V_215 ) ;
if ( V_109 -> V_139 != V_217 ) {
V_109 -> V_139 = V_217 ;
V_109 -> V_123 = 0 ;
V_109 -> V_120 = 0 ;
V_109 -> V_122 = 0 ;
F_66 ( V_109 ) ;
V_216 = NULL ;
}
F_73 ( V_60 , V_109 ) ;
if ( ! V_60 -> V_62 )
V_60 -> V_62 = V_57 ;
if ( ! ( V_60 -> V_2 . V_218 & V_219 ) ) {
F_77 ( * V_215 , V_60 ) ;
if ( V_216 )
F_64 ( V_216 ) ;
V_167 = true ;
}
V_109 -> V_116 = V_73 ;
}
F_79 ( & V_132 ) ;
return V_167 ;
}
static bool F_158 ( struct V_127 * V_128 , struct V_50 * V_60 )
{
struct V_50 * V_216 , * V_220 , * * V_221 ;
bool V_167 = true ;
if ( F_157 ( V_60 ) ) {
V_221 = (struct V_50 * * ) & V_128 -> V_141 ;
} else {
V_221 = (struct V_50 * * ) F_159 ( V_128 -> V_145 ) ;
}
V_216 = * V_221 ;
V_220 = F_44 ( V_221 , V_216 , V_60 ) ;
if ( V_220 == V_216 ) {
if ( V_216 )
F_64 ( V_216 ) ;
} else
V_167 = false ;
return V_167 ;
}
static void F_160 ( struct V_50 * V_60 )
{
struct V_222 * V_223 = F_159 ( & V_224 ) ;
V_60 -> V_224 = V_223 ;
F_75 ( & V_223 -> V_225 ) ;
F_161 ( & V_60 -> V_226 , & V_223 -> V_227 ) ;
F_79 ( & V_223 -> V_225 ) ;
}
static void F_162 ( struct V_1 * V_2 )
{
struct V_50 * V_60 = (struct V_50 * ) V_2 ;
if ( ! F_163 ( & V_60 -> V_226 ) ) {
struct V_222 * V_223 = V_60 -> V_224 ;
F_75 ( & V_223 -> V_225 ) ;
F_164 ( & V_60 -> V_226 ) ;
F_79 ( & V_223 -> V_225 ) ;
}
}
void F_165 ( struct V_58 * V_53 )
{
struct V_37 * V_37 = F_35 ( V_53 ) ;
struct V_50 * V_60 ;
int V_12 ;
F_20 (cpu) {
struct V_222 * V_223 = & F_12 ( V_224 , V_12 ) ;
F_75 ( & V_223 -> V_225 ) ;
F_166 (rt, &ul->head, rt_uncached) {
if ( V_60 -> V_2 . V_53 != V_53 )
continue;
V_60 -> V_2 . V_53 = V_37 -> V_228 ;
F_167 ( V_60 -> V_2 . V_53 ) ;
F_168 ( V_53 ) ;
}
F_79 ( & V_223 -> V_225 ) ;
}
}
static bool F_169 ( const struct V_50 * V_60 )
{
return V_60 &&
V_60 -> V_2 . V_142 == V_205 &&
! F_33 ( V_60 ) ;
}
static void F_170 ( struct V_50 * V_60 , T_6 V_57 ,
const struct V_153 * V_154 ,
struct V_108 * V_109 ,
struct V_229 * V_230 , T_11 type , T_1 V_231 )
{
bool V_232 = false ;
if ( V_230 ) {
struct V_127 * V_128 = & F_95 ( * V_154 ) ;
if ( V_128 -> V_233 && V_128 -> V_234 == V_235 ) {
V_60 -> V_62 = V_128 -> V_233 ;
V_60 -> V_126 = 1 ;
}
F_171 ( & V_60 -> V_2 , V_230 -> V_236 , true ) ;
#ifdef F_28
V_60 -> V_2 . V_212 = V_128 -> V_237 ;
#endif
if ( F_153 ( V_109 ) )
V_232 = F_156 ( V_60 , V_109 , V_57 ) ;
else if ( ! ( V_60 -> V_2 . V_218 & V_219 ) )
V_232 = F_158 ( V_128 , V_60 ) ;
if ( F_153 ( ! V_232 ) ) {
V_60 -> V_2 . V_218 |= V_219 ;
if ( ! V_60 -> V_62 )
V_60 -> V_62 = V_57 ;
F_160 ( V_60 ) ;
}
} else
F_160 ( V_60 ) ;
#ifdef F_28
#ifdef F_172
F_148 ( V_60 , V_154 -> V_212 ) ;
#endif
F_148 ( V_60 , V_231 ) ;
#endif
}
static struct V_50 * F_173 ( struct V_58 * V_53 ,
bool V_238 , bool V_239 , bool V_240 )
{
return F_174 ( & V_16 , V_53 , 1 , V_205 ,
( V_240 ? 0 : ( V_241 | V_219 ) ) |
( V_238 ? V_242 : 0 ) |
( V_239 ? V_243 : 0 ) ) ;
}
static int F_175 ( struct V_55 * V_56 , T_6 V_57 , T_6 V_79 ,
T_8 V_86 , struct V_58 * V_53 , int V_244 )
{
struct V_50 * V_51 ;
struct V_151 * V_152 = F_82 ( V_53 ) ;
T_1 V_231 = 0 ;
int V_245 ;
if ( ! V_152 )
return - V_186 ;
if ( F_84 ( V_79 ) || F_85 ( V_79 ) ||
V_56 -> V_80 != F_51 ( V_246 ) )
goto V_247;
if ( F_176 ( ! F_177 ( V_152 ) ) )
if ( F_178 ( V_79 ) )
goto V_247;
if ( F_86 ( V_79 ) ) {
if ( ! F_179 ( V_57 ) )
goto V_247;
} else {
V_245 = F_180 ( V_56 , V_79 , 0 , V_86 , 0 , V_53 ,
V_152 , & V_231 ) ;
if ( V_245 < 0 )
goto V_248;
}
V_51 = F_173 ( F_35 ( V_53 ) -> V_228 ,
F_181 ( V_152 , V_249 ) , false , false ) ;
if ( ! V_51 )
goto V_250;
#ifdef F_28
V_51 -> V_2 . V_212 = V_231 ;
#endif
V_51 -> V_2 . V_251 = F_142 ;
V_51 -> V_52 = F_34 ( F_35 ( V_53 ) ) ;
V_51 -> V_124 = V_252 ;
V_51 -> V_253 = V_254 ;
V_51 -> V_255 = 1 ;
V_51 -> V_256 = 0 ;
V_51 -> V_119 = 0 ;
V_51 -> V_62 = 0 ;
V_51 -> V_126 = 0 ;
F_182 ( & V_51 -> V_226 ) ;
if ( V_244 ) {
V_51 -> V_2 . V_257 = V_258 ;
V_51 -> V_124 |= V_259 ;
}
#ifdef F_183
if ( ! F_179 ( V_57 ) && F_184 ( V_152 ) )
V_51 -> V_2 . V_257 = V_260 ;
#endif
F_185 ( V_18 ) ;
F_186 ( V_56 , & V_51 -> V_2 ) ;
return 0 ;
V_250:
return - V_261 ;
V_247:
return - V_186 ;
V_248:
return V_245 ;
}
static void F_187 ( struct V_58 * V_53 ,
struct V_151 * V_152 ,
struct V_55 * V_56 ,
T_6 V_57 ,
T_6 V_79 )
{
F_185 ( V_22 ) ;
#ifdef F_98
if ( F_99 ( V_152 ) && F_188 () ) {
F_189 ( L_15 ,
& V_57 , & V_79 , V_53 -> V_166 ) ;
if ( V_53 -> V_262 && F_190 ( V_56 ) ) {
F_191 ( V_263 , L_16 ,
V_264 , 16 , 1 ,
F_192 ( V_56 ) ,
V_53 -> V_262 , true ) ;
}
}
#endif
}
static int F_193 ( struct V_55 * V_56 ,
const struct V_153 * V_154 ,
struct V_151 * V_152 ,
T_6 V_57 , T_6 V_79 , T_1 V_86 )
{
struct V_108 * V_109 ;
struct V_50 * V_51 ;
int V_245 ;
struct V_151 * V_265 ;
unsigned int V_218 = 0 ;
bool V_266 ;
T_1 V_231 = 0 ;
V_265 = F_82 ( F_194 ( * V_154 ) ) ;
if ( ! V_265 ) {
F_195 ( L_17 ) ;
return - V_186 ;
}
V_245 = F_180 ( V_56 , V_79 , V_57 , V_86 , F_196 ( * V_154 ) ,
V_152 -> V_53 , V_152 , & V_231 ) ;
if ( V_245 < 0 ) {
F_187 ( V_152 -> V_53 , V_152 , V_56 , V_57 ,
V_79 ) ;
goto V_267;
}
V_266 = V_154 -> V_230 && ! V_231 ;
if ( V_265 == V_152 && V_245 && F_106 ( V_265 ) &&
V_56 -> V_80 == F_51 ( V_246 ) &&
( F_87 ( V_265 ) ||
F_88 ( V_265 , V_79 , F_197 ( * V_154 ) ) ) )
F_198 ( V_56 ) -> V_218 |= V_268 ;
if ( V_56 -> V_80 != F_51 ( V_246 ) ) {
if ( V_265 == V_152 &&
F_199 ( V_152 ) == 0 ) {
V_245 = - V_186 ;
goto V_267;
}
}
V_109 = F_155 ( & F_95 ( * V_154 ) , V_57 ) ;
if ( V_266 ) {
if ( V_109 )
V_51 = F_60 ( V_109 -> V_110 ) ;
else
V_51 = F_60 ( F_95 ( * V_154 ) . V_141 ) ;
if ( F_169 ( V_51 ) ) {
F_200 ( V_56 , & V_51 -> V_2 ) ;
goto V_181;
}
}
V_51 = F_173 ( V_265 -> V_53 ,
F_181 ( V_152 , V_249 ) ,
F_181 ( V_265 , V_269 ) , V_266 ) ;
if ( ! V_51 ) {
V_245 = - V_261 ;
goto V_267;
}
V_51 -> V_52 = F_34 ( F_35 ( V_51 -> V_2 . V_53 ) ) ;
V_51 -> V_124 = V_218 ;
V_51 -> V_253 = V_154 -> type ;
V_51 -> V_255 = 1 ;
V_51 -> V_256 = 0 ;
V_51 -> V_119 = 0 ;
V_51 -> V_62 = 0 ;
V_51 -> V_126 = 0 ;
F_182 ( & V_51 -> V_226 ) ;
F_185 ( V_17 ) ;
V_51 -> V_2 . V_257 = V_270 ;
V_51 -> V_2 . V_251 = V_271 ;
F_170 ( V_51 , V_57 , V_154 , V_109 , V_154 -> V_230 , V_154 -> type , V_231 ) ;
F_186 ( V_56 , & V_51 -> V_2 ) ;
V_181:
V_245 = 0 ;
V_267:
return V_245 ;
}
static int F_201 ( struct V_55 * V_56 ,
struct V_153 * V_154 ,
const struct V_81 * V_82 ,
struct V_151 * V_152 ,
T_6 V_57 , T_6 V_79 , T_1 V_86 )
{
#ifdef F_202
if ( V_154 -> V_230 && V_154 -> V_230 -> V_272 > 1 )
F_203 ( V_154 ) ;
#endif
return F_193 ( V_56 , V_154 , V_152 , V_57 , V_79 , V_86 ) ;
}
static int F_204 ( struct V_55 * V_56 , T_6 V_57 , T_6 V_79 ,
T_8 V_86 , struct V_58 * V_53 )
{
struct V_153 V_154 ;
struct V_151 * V_152 = F_82 ( V_53 ) ;
struct V_81 V_82 ;
unsigned int V_218 = 0 ;
T_1 V_231 = 0 ;
struct V_50 * V_51 ;
int V_245 = - V_186 ;
struct V_37 * V_37 = F_35 ( V_53 ) ;
bool V_266 ;
if ( ! V_152 )
goto V_181;
if ( F_84 ( V_79 ) || F_85 ( V_79 ) )
goto V_273;
V_154 . V_230 = NULL ;
if ( F_85 ( V_57 ) || ( V_79 == 0 && V_57 == 0 ) )
goto V_274;
if ( F_86 ( V_79 ) )
goto V_273;
if ( F_86 ( V_57 ) )
goto V_275;
if ( F_178 ( V_57 ) ) {
if ( ! F_205 ( V_152 , V_37 ) )
goto V_275;
} else if ( F_178 ( V_79 ) ) {
if ( ! F_205 ( V_152 , V_37 ) )
goto V_273;
}
V_82 . V_209 = 0 ;
V_82 . V_210 = V_53 -> V_98 ;
V_82 . V_198 = V_56 -> V_88 ;
V_82 . V_208 = V_86 ;
V_82 . V_276 = V_97 ;
V_82 . V_57 = V_57 ;
V_82 . V_79 = V_79 ;
V_245 = F_94 ( V_37 , & V_82 , & V_154 ) ;
if ( V_245 != 0 ) {
if ( ! F_115 ( V_152 ) )
V_245 = - V_182 ;
goto V_277;
}
if ( V_154 . type == V_278 )
goto V_274;
if ( V_154 . type == V_279 ) {
V_245 = F_180 ( V_56 , V_79 , V_57 , V_86 ,
0 , V_53 , V_152 , & V_231 ) ;
if ( V_245 < 0 )
goto V_280;
goto V_281;
}
if ( ! F_115 ( V_152 ) ) {
V_245 = - V_182 ;
goto V_277;
}
if ( V_154 . type != V_161 )
goto V_275;
V_245 = F_201 ( V_56 , & V_154 , & V_82 , V_152 , V_57 , V_79 , V_86 ) ;
V_181: return V_245 ;
V_274:
if ( V_56 -> V_80 != F_51 ( V_246 ) )
goto V_247;
if ( ! F_86 ( V_79 ) ) {
V_245 = F_180 ( V_56 , V_79 , 0 , V_86 , 0 , V_53 ,
V_152 , & V_231 ) ;
if ( V_245 < 0 )
goto V_280;
}
V_218 |= V_282 ;
V_154 . type = V_278 ;
F_185 ( V_20 ) ;
V_281:
V_266 = false ;
if ( V_154 . V_230 ) {
if ( ! V_231 ) {
V_51 = F_60 ( F_95 ( V_154 ) . V_141 ) ;
if ( F_169 ( V_51 ) ) {
F_200 ( V_56 , & V_51 -> V_2 ) ;
V_245 = 0 ;
goto V_181;
}
V_266 = true ;
}
}
V_51 = F_173 ( V_37 -> V_228 ,
F_181 ( V_152 , V_249 ) , false , V_266 ) ;
if ( ! V_51 )
goto V_250;
V_51 -> V_2 . V_257 = V_258 ;
V_51 -> V_2 . V_251 = F_142 ;
#ifdef F_28
V_51 -> V_2 . V_212 = V_231 ;
#endif
V_51 -> V_52 = F_34 ( V_37 ) ;
V_51 -> V_124 = V_218 | V_259 ;
V_51 -> V_253 = V_154 . type ;
V_51 -> V_255 = 1 ;
V_51 -> V_256 = 0 ;
V_51 -> V_119 = 0 ;
V_51 -> V_62 = 0 ;
V_51 -> V_126 = 0 ;
F_182 ( & V_51 -> V_226 ) ;
F_185 ( V_17 ) ;
if ( V_154 . type == V_283 ) {
V_51 -> V_2 . V_257 = F_114 ;
V_51 -> V_2 . error = - V_245 ;
V_51 -> V_124 &= ~ V_259 ;
}
if ( V_266 ) {
if ( F_153 ( ! F_158 ( & F_95 ( V_154 ) , V_51 ) ) ) {
V_51 -> V_2 . V_218 |= V_219 ;
F_160 ( V_51 ) ;
}
}
F_186 ( V_56 , & V_51 -> V_2 ) ;
V_245 = 0 ;
goto V_181;
V_277:
F_185 ( V_19 ) ;
V_154 . type = V_283 ;
V_154 . V_230 = NULL ;
goto V_281;
V_275:
F_185 ( V_21 ) ;
#ifdef F_98
if ( F_99 ( V_152 ) )
F_111 ( L_18 ,
& V_57 , & V_79 , V_53 -> V_166 ) ;
#endif
V_247:
V_245 = - V_186 ;
goto V_181;
V_250:
V_245 = - V_261 ;
goto V_181;
V_273:
V_245 = - V_186 ;
V_280:
F_187 ( V_53 , V_152 , V_56 , V_57 , V_79 ) ;
goto V_181;
}
int F_206 ( struct V_55 * V_56 , T_6 V_57 , T_6 V_79 ,
T_8 V_86 , struct V_58 * V_53 )
{
int V_154 ;
F_59 () ;
if ( F_84 ( V_57 ) ) {
struct V_151 * V_152 = F_82 ( V_53 ) ;
if ( V_152 ) {
int V_244 = F_207 ( V_152 , V_57 , V_79 ,
F_39 ( V_56 ) -> V_80 ) ;
if ( V_244
#ifdef F_183
||
( ! F_179 ( V_57 ) &&
F_184 ( V_152 ) )
#endif
) {
int V_154 = F_175 ( V_56 , V_57 , V_79 ,
V_86 , V_53 , V_244 ) ;
F_62 () ;
return V_154 ;
}
}
F_62 () ;
return - V_186 ;
}
V_154 = F_204 ( V_56 , V_57 , V_79 , V_86 , V_53 ) ;
F_62 () ;
return V_154 ;
}
static struct V_50 * F_208 ( const struct V_153 * V_154 ,
const struct V_81 * V_82 , int V_284 ,
struct V_58 * V_285 ,
unsigned int V_218 )
{
struct V_229 * V_230 = V_154 -> V_230 ;
struct V_108 * V_109 ;
struct V_151 * V_152 ;
T_11 type = V_154 -> type ;
struct V_50 * V_51 ;
bool V_266 ;
V_152 = F_82 ( V_285 ) ;
if ( ! V_152 )
return F_209 ( - V_186 ) ;
if ( F_176 ( ! F_177 ( V_152 ) ) )
if ( F_178 ( V_82 -> V_79 ) && ! ( V_285 -> V_218 & V_286 ) )
return F_209 ( - V_186 ) ;
if ( F_85 ( V_82 -> V_57 ) )
type = V_278 ;
else if ( F_84 ( V_82 -> V_57 ) )
type = V_254 ;
else if ( F_86 ( V_82 -> V_57 ) )
return F_209 ( - V_186 ) ;
if ( V_285 -> V_218 & V_286 )
V_218 |= V_259 ;
V_266 = true ;
if ( type == V_278 ) {
V_218 |= V_282 | V_259 ;
V_230 = NULL ;
} else if ( type == V_254 ) {
V_218 |= V_252 | V_259 ;
if ( ! F_207 ( V_152 , V_82 -> V_57 , V_82 -> V_79 ,
V_82 -> V_287 ) )
V_218 &= ~ V_259 ;
else
V_266 = false ;
if ( V_230 && V_154 -> V_288 < 4 )
V_230 = NULL ;
}
V_109 = NULL ;
V_266 &= V_230 != NULL ;
if ( V_266 ) {
struct V_50 T_10 * * V_289 ;
struct V_127 * V_128 = & F_95 ( * V_154 ) ;
V_109 = F_155 ( V_128 , V_82 -> V_57 ) ;
if ( V_109 )
V_289 = & V_109 -> V_111 ;
else {
if ( F_153 ( V_82 -> V_290 &
V_291 &&
! ( V_128 -> V_233 &&
V_128 -> V_234 == V_235 ) ) ) {
V_266 = false ;
goto V_292;
}
V_289 = F_159 ( V_128 -> V_145 ) ;
}
V_51 = F_60 ( * V_289 ) ;
if ( F_169 ( V_51 ) ) {
F_210 ( & V_51 -> V_2 ) ;
return V_51 ;
}
}
V_292:
V_51 = F_173 ( V_285 ,
F_181 ( V_152 , V_249 ) ,
F_181 ( V_152 , V_269 ) ,
V_266 ) ;
if ( ! V_51 )
return F_209 ( - V_261 ) ;
V_51 -> V_2 . V_251 = V_271 ;
V_51 -> V_52 = F_34 ( F_35 ( V_285 ) ) ;
V_51 -> V_124 = V_218 ;
V_51 -> V_253 = type ;
V_51 -> V_255 = 0 ;
V_51 -> V_256 = V_284 ? : 0 ;
V_51 -> V_119 = 0 ;
V_51 -> V_62 = 0 ;
V_51 -> V_126 = 0 ;
F_182 ( & V_51 -> V_226 ) ;
F_185 ( V_23 ) ;
if ( V_218 & V_259 )
V_51 -> V_2 . V_257 = V_258 ;
if ( V_218 & ( V_282 | V_252 ) ) {
if ( V_218 & V_259 &&
! ( V_285 -> V_218 & V_286 ) ) {
V_51 -> V_2 . V_251 = V_293 ;
F_185 ( V_24 ) ;
}
#ifdef F_183
if ( type == V_254 ) {
if ( F_184 ( V_152 ) &&
! F_179 ( V_82 -> V_57 ) ) {
V_51 -> V_2 . V_257 = V_260 ;
V_51 -> V_2 . V_251 = V_293 ;
}
}
#endif
}
F_170 ( V_51 , V_82 -> V_57 , V_154 , V_109 , V_230 , type , 0 ) ;
return V_51 ;
}
struct V_50 * F_124 ( struct V_37 * V_37 , struct V_81 * V_82 )
{
struct V_58 * V_285 = NULL ;
T_12 V_86 = F_211 ( V_82 ) ;
unsigned int V_218 = 0 ;
struct V_153 V_154 ;
struct V_50 * V_51 ;
int V_284 ;
V_154 . V_212 = 0 ;
V_154 . V_230 = NULL ;
V_154 . V_294 = NULL ;
V_284 = V_82 -> V_209 ;
V_82 -> V_210 = V_295 ;
V_82 -> V_208 = V_86 & V_296 ;
V_82 -> V_276 = ( ( V_86 & V_297 ) ?
V_235 : V_97 ) ;
F_59 () ;
if ( V_82 -> V_79 ) {
V_51 = F_209 ( - V_186 ) ;
if ( F_84 ( V_82 -> V_79 ) ||
F_85 ( V_82 -> V_79 ) ||
F_86 ( V_82 -> V_79 ) )
goto V_181;
if ( V_82 -> V_209 == 0 &&
( F_84 ( V_82 -> V_57 ) ||
F_85 ( V_82 -> V_57 ) ) ) {
V_285 = F_212 ( V_37 , V_82 -> V_79 , false ) ;
if ( ! V_285 )
goto V_181;
V_82 -> V_209 = V_285 -> V_98 ;
goto V_298;
}
if ( ! ( V_82 -> V_290 & V_299 ) ) {
if ( ! F_212 ( V_37 , V_82 -> V_79 , false ) )
goto V_181;
}
}
if ( V_82 -> V_209 ) {
V_285 = F_213 ( V_37 , V_82 -> V_209 ) ;
V_51 = F_209 ( - V_300 ) ;
if ( ! V_285 )
goto V_181;
if ( ! ( V_285 -> V_218 & V_301 ) || ! F_82 ( V_285 ) ) {
V_51 = F_209 ( - V_184 ) ;
goto V_181;
}
if ( F_179 ( V_82 -> V_57 ) ||
F_85 ( V_82 -> V_57 ) ) {
if ( ! V_82 -> V_79 )
V_82 -> V_79 = F_147 ( V_285 , 0 ,
V_235 ) ;
goto V_298;
}
if ( ! V_82 -> V_79 ) {
if ( F_84 ( V_82 -> V_57 ) )
V_82 -> V_79 = F_147 ( V_285 , 0 ,
V_82 -> V_276 ) ;
else if ( ! V_82 -> V_57 )
V_82 -> V_79 = F_147 ( V_285 , 0 ,
V_302 ) ;
}
}
if ( ! V_82 -> V_57 ) {
V_82 -> V_57 = V_82 -> V_79 ;
if ( ! V_82 -> V_57 )
V_82 -> V_57 = V_82 -> V_79 = F_214 ( V_303 ) ;
V_285 = V_37 -> V_228 ;
V_82 -> V_209 = V_295 ;
V_154 . type = V_279 ;
V_218 |= V_259 ;
goto V_298;
}
if ( F_94 ( V_37 , V_82 , & V_154 ) ) {
V_154 . V_230 = NULL ;
V_154 . V_294 = NULL ;
if ( V_82 -> V_209 ) {
if ( V_82 -> V_79 == 0 )
V_82 -> V_79 = F_147 ( V_285 , 0 ,
V_235 ) ;
V_154 . type = V_161 ;
goto V_298;
}
V_51 = F_209 ( - V_184 ) ;
goto V_181;
}
if ( V_154 . type == V_279 ) {
if ( ! V_82 -> V_79 ) {
if ( V_154 . V_230 -> V_304 )
V_82 -> V_79 = V_154 . V_230 -> V_304 ;
else
V_82 -> V_79 = V_82 -> V_57 ;
}
V_285 = V_37 -> V_228 ;
V_82 -> V_209 = V_285 -> V_98 ;
V_218 |= V_259 ;
goto V_298;
}
#ifdef F_202
if ( V_154 . V_230 -> V_272 > 1 && V_82 -> V_209 == 0 )
F_203 ( & V_154 ) ;
else
#endif
if ( ! V_154 . V_288 &&
V_154 . V_294 -> V_305 > 1 &&
V_154 . type == V_161 && ! V_82 -> V_209 )
F_215 ( & V_154 ) ;
if ( ! V_82 -> V_79 )
V_82 -> V_79 = F_146 ( V_37 , V_154 ) ;
V_285 = F_194 ( V_154 ) ;
V_82 -> V_209 = V_285 -> V_98 ;
V_298:
V_51 = F_208 ( & V_154 , V_82 , V_284 , V_285 , V_218 ) ;
V_181:
F_62 () ;
return V_51 ;
}
static struct V_1 * F_216 ( struct V_1 * V_2 , T_1 V_204 )
{
return NULL ;
}
static unsigned int F_217 ( const struct V_1 * V_2 )
{
unsigned int V_194 = F_150 ( V_2 , V_195 ) ;
return V_194 ? : V_2 -> V_53 -> V_194 ;
}
static void F_218 ( struct V_1 * V_2 , struct V_83 * V_84 ,
struct V_55 * V_56 , T_1 V_194 )
{
}
static void F_219 ( struct V_1 * V_2 , struct V_83 * V_84 ,
struct V_55 * V_56 )
{
}
static T_1 * F_220 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
return NULL ;
}
struct V_1 * F_221 ( struct V_37 * V_37 , struct V_1 * V_306 )
{
struct V_50 * V_307 = (struct V_50 * ) V_306 ;
struct V_50 * V_60 ;
V_60 = F_174 ( & V_308 , NULL , 1 , V_309 , 0 ) ;
if ( V_60 ) {
struct V_1 * V_200 = & V_60 -> V_2 ;
V_200 -> V_310 = 1 ;
V_200 -> V_257 = V_311 ;
V_200 -> V_251 = V_312 ;
V_200 -> V_53 = V_307 -> V_2 . V_53 ;
if ( V_200 -> V_53 )
F_167 ( V_200 -> V_53 ) ;
V_60 -> V_255 = V_307 -> V_255 ;
V_60 -> V_256 = V_307 -> V_256 ;
V_60 -> V_119 = V_307 -> V_119 ;
V_60 -> V_52 = F_34 ( V_37 ) ;
V_60 -> V_124 = V_307 -> V_124 ;
V_60 -> V_253 = V_307 -> V_253 ;
V_60 -> V_62 = V_307 -> V_62 ;
V_60 -> V_126 = V_307 -> V_126 ;
F_182 ( & V_60 -> V_226 ) ;
F_222 ( V_200 ) ;
}
F_134 ( V_306 ) ;
return V_60 ? & V_60 -> V_2 : F_209 ( - V_32 ) ;
}
struct V_50 * F_132 ( struct V_37 * V_37 , struct V_81 * V_313 ,
struct V_83 * V_84 )
{
struct V_50 * V_60 = F_124 ( V_37 , V_313 ) ;
if ( F_92 ( V_60 ) )
return V_60 ;
if ( V_313 -> V_287 )
V_60 = (struct V_50 * ) F_223 ( V_37 , & V_60 -> V_2 ,
F_224 ( V_313 ) ,
V_84 , 0 ) ;
return V_60 ;
}
static int F_225 ( struct V_37 * V_37 , T_6 V_2 , T_6 V_28 ,
struct V_81 * V_82 , struct V_55 * V_56 , T_1 V_314 ,
T_1 V_5 , int V_315 , int V_316 , unsigned int V_218 )
{
struct V_50 * V_60 = F_105 ( V_56 ) ;
struct V_317 * V_318 ;
struct V_319 * V_320 ;
unsigned long V_121 = 0 ;
T_1 error ;
T_1 V_321 [ V_322 ] ;
V_320 = F_226 ( V_56 , V_314 , V_5 , V_315 , sizeof( * V_318 ) , V_218 ) ;
if ( ! V_320 )
return - V_323 ;
V_318 = F_227 ( V_320 ) ;
V_318 -> V_324 = V_325 ;
V_318 -> V_326 = 32 ;
V_318 -> V_327 = 0 ;
V_318 -> V_328 = V_82 -> V_208 ;
V_318 -> V_329 = V_330 ;
if ( F_228 ( V_56 , V_331 , V_330 ) )
goto V_332;
V_318 -> V_333 = V_60 -> V_253 ;
V_318 -> V_334 = V_97 ;
V_318 -> V_335 = V_336 ;
V_318 -> V_337 = ( V_60 -> V_124 & ~ 0xFFFF ) | V_338 ;
if ( V_60 -> V_124 & V_339 )
V_318 -> V_337 |= V_340 ;
if ( F_198 ( V_56 ) -> V_218 & V_268 )
V_318 -> V_337 |= V_341 ;
if ( F_229 ( V_56 , V_342 , V_2 ) )
goto V_332;
if ( V_28 ) {
V_318 -> V_327 = 32 ;
if ( F_229 ( V_56 , V_343 , V_28 ) )
goto V_332;
}
if ( V_60 -> V_2 . V_53 &&
F_228 ( V_56 , V_344 , V_60 -> V_2 . V_53 -> V_98 ) )
goto V_332;
#ifdef F_28
if ( V_60 -> V_2 . V_212 &&
F_228 ( V_56 , V_345 , V_60 -> V_2 . V_212 ) )
goto V_332;
#endif
if ( ! F_157 ( V_60 ) &&
V_82 -> V_79 != V_28 ) {
if ( F_229 ( V_56 , V_346 , V_82 -> V_79 ) )
goto V_332;
}
if ( V_60 -> V_126 &&
F_229 ( V_56 , V_347 , V_60 -> V_62 ) )
goto V_332;
V_121 = V_60 -> V_2 . V_121 ;
if ( V_121 ) {
unsigned long V_72 = V_73 ;
if ( F_69 ( V_72 , V_121 ) )
V_121 -= V_72 ;
else
V_121 = 0 ;
}
memcpy ( V_321 , F_230 ( & V_60 -> V_2 ) , sizeof( V_321 ) ) ;
if ( V_60 -> V_119 && V_121 )
V_321 [ V_195 - 1 ] = V_60 -> V_119 ;
if ( F_231 ( V_56 , V_321 ) < 0 )
goto V_332;
if ( V_82 -> V_198 &&
F_228 ( V_56 , V_348 , V_82 -> V_198 ) )
goto V_332;
error = V_60 -> V_2 . error ;
if ( F_157 ( V_60 ) ) {
#ifdef F_183
if ( F_84 ( V_2 ) && ! F_179 ( V_2 ) &&
F_232 ( V_37 , V_349 ) ) {
int V_245 = F_233 ( V_37 , V_56 ,
V_82 -> V_79 , V_82 -> V_57 ,
V_318 , V_316 ) ;
if ( V_245 <= 0 ) {
if ( ! V_316 ) {
if ( V_245 == 0 )
return 0 ;
goto V_332;
} else {
if ( V_245 == - V_323 )
goto V_332;
error = V_245 ;
}
}
} else
#endif
if ( F_228 ( V_56 , V_350 , V_56 -> V_53 -> V_98 ) )
goto V_332;
}
if ( F_234 ( V_56 , & V_60 -> V_2 , 0 , V_121 , error ) < 0 )
goto V_332;
F_235 ( V_56 , V_320 ) ;
return 0 ;
V_332:
F_236 ( V_56 , V_320 ) ;
return - V_323 ;
}
static int F_237 ( struct V_55 * V_351 , struct V_319 * V_320 )
{
struct V_37 * V_37 = F_126 ( V_351 -> V_84 ) ;
struct V_317 * V_352 ;
struct V_353 * V_354 [ V_355 + 1 ] ;
struct V_50 * V_60 = NULL ;
struct V_81 V_82 ;
T_6 V_2 = 0 ;
T_6 V_28 = 0 ;
T_1 V_356 ;
int V_245 ;
int V_88 ;
struct V_55 * V_56 ;
V_245 = F_238 ( V_320 , sizeof( * V_352 ) , V_354 , V_355 , V_357 ) ;
if ( V_245 < 0 )
goto V_358;
V_352 = F_227 ( V_320 ) ;
V_56 = F_239 ( V_359 , V_31 ) ;
if ( ! V_56 ) {
V_245 = - V_261 ;
goto V_358;
}
F_240 ( V_56 ) ;
F_241 ( V_56 ) ;
F_39 ( V_56 ) -> V_80 = V_360 ;
F_242 ( V_56 , V_361 + sizeof( struct V_76 ) ) ;
V_28 = V_354 [ V_343 ] ? F_243 ( V_354 [ V_343 ] ) : 0 ;
V_2 = V_354 [ V_342 ] ? F_243 ( V_354 [ V_342 ] ) : 0 ;
V_356 = V_354 [ V_350 ] ? F_244 ( V_354 [ V_350 ] ) : 0 ;
V_88 = V_354 [ V_348 ] ? F_244 ( V_354 [ V_348 ] ) : 0 ;
memset ( & V_82 , 0 , sizeof( V_82 ) ) ;
V_82 . V_57 = V_2 ;
V_82 . V_79 = V_28 ;
V_82 . V_208 = V_352 -> V_328 ;
V_82 . V_209 = V_354 [ V_344 ] ? F_244 ( V_354 [ V_344 ] ) : 0 ;
V_82 . V_198 = V_88 ;
if ( V_356 ) {
struct V_58 * V_53 ;
V_53 = F_245 ( V_37 , V_356 ) ;
if ( ! V_53 ) {
V_245 = - V_300 ;
goto V_362;
}
V_56 -> V_80 = F_51 ( V_246 ) ;
V_56 -> V_53 = V_53 ;
V_56 -> V_88 = V_88 ;
F_246 () ;
V_245 = F_247 ( V_56 , V_2 , V_28 , V_352 -> V_328 , V_53 ) ;
F_248 () ;
V_60 = F_105 ( V_56 ) ;
if ( V_245 == 0 && V_60 -> V_2 . error )
V_245 = - V_60 -> V_2 . error ;
} else {
V_60 = F_249 ( V_37 , & V_82 ) ;
V_245 = 0 ;
if ( F_92 ( V_60 ) )
V_245 = F_250 ( V_60 ) ;
}
if ( V_245 )
goto V_362;
F_186 ( V_56 , & V_60 -> V_2 ) ;
if ( V_352 -> V_337 & V_340 )
V_60 -> V_124 |= V_339 ;
V_245 = F_225 ( V_37 , V_2 , V_28 , & V_82 , V_56 ,
F_251 ( V_351 ) . V_314 , V_320 -> V_363 ,
V_364 , 0 , 0 ) ;
if ( V_245 < 0 )
goto V_362;
V_245 = F_252 ( V_56 , V_37 , F_251 ( V_351 ) . V_314 ) ;
V_358:
return V_245 ;
V_362:
F_117 ( V_56 ) ;
goto V_358;
}
void F_253 ( struct V_151 * V_152 )
{
F_36 ( F_35 ( V_152 -> V_53 ) ) ;
}
static int F_254 ( struct V_365 * V_366 , int V_367 ,
void T_13 * V_368 ,
T_14 * V_369 , T_2 * V_370 )
{
struct V_37 * V_37 = (struct V_37 * ) V_366 -> V_371 ;
if ( V_367 ) {
F_36 ( V_37 ) ;
F_255 ( V_37 ) ;
return 0 ;
}
return - V_186 ;
}
static T_3 int F_256 ( struct V_37 * V_37 )
{
struct V_365 * V_372 ;
V_372 = V_373 ;
if ( ! F_257 ( V_37 , & V_374 ) ) {
V_372 = F_258 ( V_372 , sizeof( V_373 ) , V_31 ) ;
if ( ! V_372 )
goto V_375;
if ( V_37 -> V_376 != & V_377 )
V_372 [ 0 ] . V_378 = NULL ;
}
V_372 [ 0 ] . V_371 = V_37 ;
V_37 -> V_171 . V_379 = F_259 ( V_37 , L_19 , V_372 ) ;
if ( ! V_37 -> V_171 . V_379 )
goto V_380;
return 0 ;
V_380:
if ( V_372 != V_373 )
F_23 ( V_372 ) ;
V_375:
return - V_32 ;
}
static T_4 void F_260 ( struct V_37 * V_37 )
{
struct V_365 * V_372 ;
V_372 = V_37 -> V_171 . V_379 -> V_381 ;
F_261 ( V_37 -> V_171 . V_379 ) ;
F_262 ( V_372 == V_373 ) ;
F_23 ( V_372 ) ;
}
static T_3 int F_263 ( struct V_37 * V_37 )
{
F_264 ( & V_37 -> V_171 . V_52 , 0 ) ;
F_264 ( & V_37 -> V_139 , 0 ) ;
F_265 ( & V_37 -> V_171 . V_382 ,
sizeof( V_37 -> V_171 . V_382 ) ) ;
return 0 ;
}
static int T_3 F_266 ( struct V_37 * V_37 )
{
struct V_383 * V_384 = F_267 ( sizeof( * V_384 ) , V_31 ) ;
if ( ! V_384 )
return - V_32 ;
F_268 ( V_384 ) ;
V_37 -> V_171 . V_172 = V_384 ;
return 0 ;
}
static void T_4 F_269 ( struct V_37 * V_37 )
{
struct V_383 * V_384 = V_37 -> V_171 . V_172 ;
V_37 -> V_171 . V_172 = NULL ;
F_270 ( V_384 ) ;
F_23 ( V_384 ) ;
}
int T_5 F_271 ( void )
{
int V_385 = 0 ;
int V_12 ;
V_69 = F_267 ( V_70 * sizeof( * V_69 ) , V_31 ) ;
if ( ! V_69 )
F_272 ( L_20 ) ;
F_273 ( V_69 , V_70 * sizeof( * V_69 ) ) ;
F_20 (cpu) {
struct V_222 * V_223 = & F_12 ( V_224 , V_12 ) ;
F_182 ( & V_223 -> V_227 ) ;
F_274 ( & V_223 -> V_225 ) ;
}
#ifdef F_28
V_27 = F_275 ( 256 * sizeof( struct V_27 ) , F_276 ( struct V_27 ) ) ;
if ( ! V_27 )
F_272 ( L_21 ) ;
#endif
V_16 . V_386 =
F_277 ( L_22 , sizeof( struct V_50 ) , 0 ,
V_387 | V_388 , NULL ) ;
V_308 . V_386 = V_16 . V_386 ;
if ( F_278 ( & V_16 ) < 0 )
F_272 ( L_23 ) ;
if ( F_278 ( & V_308 ) < 0 )
F_272 ( L_24 ) ;
V_16 . V_389 = ~ 0 ;
V_390 = V_391 ;
F_279 () ;
F_280 () ;
if ( F_31 () )
F_281 ( L_25 ) ;
#ifdef F_282
F_283 () ;
F_284 () ;
#endif
F_285 ( V_392 , V_393 , F_237 , NULL , NULL ) ;
#ifdef F_286
F_32 ( & V_394 ) ;
#endif
F_32 ( & V_395 ) ;
F_32 ( & V_396 ) ;
return V_385 ;
}
void T_5 F_287 ( void )
{
F_259 ( & V_374 , L_19 , V_397 ) ;
}
