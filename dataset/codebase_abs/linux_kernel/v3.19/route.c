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
void F_47 ( struct V_76 * V_77 , int V_66 )
{
static T_1 T_7 V_78 ;
T_1 V_65 , V_75 ;
F_48 ( & T_7 , sizeof( T_7 ) ) ;
V_65 = F_49 ( ( V_63 T_1 ) V_77 -> V_57 ,
( V_63 T_1 ) V_77 -> V_79 ,
V_77 -> V_80 ,
T_7 ) ;
V_75 = F_42 ( V_65 , V_66 ) ;
V_77 -> V_75 = F_50 ( V_75 ) ;
}
static void F_51 ( struct V_81 * V_82 , const struct V_83 * V_84 ,
const struct V_76 * V_77 ,
int V_85 , T_8 V_86 ,
T_8 V_87 , T_1 V_88 , int V_89 )
{
if ( V_84 ) {
const struct V_90 * V_91 = F_52 ( V_84 ) ;
V_85 = V_84 -> V_92 ;
V_88 = V_84 -> V_93 ;
V_86 = F_53 ( V_84 ) ;
V_87 = V_91 -> V_94 ? V_95 : V_84 -> V_96 ;
}
F_54 ( V_82 , V_85 , V_88 , V_86 ,
V_97 , V_87 ,
V_89 ,
V_77 -> V_57 , V_77 -> V_79 , 0 , 0 ) ;
}
static void F_55 ( struct V_81 * V_82 , const struct V_55 * V_56 ,
const struct V_83 * V_84 )
{
const struct V_76 * V_77 = F_39 ( V_56 ) ;
int V_85 = V_56 -> V_53 -> V_98 ;
T_8 V_86 = F_56 ( V_77 -> V_86 ) ;
T_8 V_87 = V_77 -> V_80 ;
T_1 V_88 = V_56 -> V_88 ;
F_51 ( V_82 , V_84 , V_77 , V_85 , V_86 , V_87 , V_88 , 0 ) ;
}
static void F_57 ( struct V_81 * V_82 , const struct V_83 * V_84 )
{
const struct V_90 * V_91 = F_52 ( V_84 ) ;
const struct V_99 * V_100 ;
T_6 V_57 = V_91 -> V_101 ;
F_58 () ;
V_100 = F_59 ( V_91 -> V_100 ) ;
if ( V_100 && V_100 -> V_102 . V_103 )
V_57 = V_100 -> V_102 . V_104 ;
F_54 ( V_82 , V_84 -> V_92 , V_84 -> V_93 ,
F_53 ( V_84 ) , V_97 ,
V_91 -> V_94 ? V_95 : V_84 -> V_96 ,
F_60 ( V_84 ) ,
V_57 , V_91 -> V_105 , 0 , 0 ) ;
F_61 () ;
}
static void F_62 ( struct V_81 * V_82 , const struct V_83 * V_84 ,
const struct V_55 * V_56 )
{
if ( V_56 )
F_55 ( V_82 , V_56 , V_84 ) ;
else
F_57 ( V_82 , V_84 ) ;
}
static inline void F_63 ( struct V_50 * V_60 )
{
F_64 ( & V_60 -> V_2 . V_106 , V_107 ) ;
}
static void F_65 ( struct V_108 * V_109 )
{
struct V_50 * V_60 ;
V_60 = F_59 ( V_109 -> V_110 ) ;
if ( V_60 ) {
F_66 ( V_109 -> V_110 , NULL ) ;
F_63 ( V_60 ) ;
}
V_60 = F_59 ( V_109 -> V_111 ) ;
if ( V_60 ) {
F_66 ( V_109 -> V_111 , NULL ) ;
F_63 ( V_60 ) ;
}
}
static struct V_108 * F_67 ( struct V_112 * V_65 )
{
struct V_108 * V_109 , * V_113 ;
V_113 = F_59 ( V_65 -> V_114 ) ;
for ( V_109 = F_59 ( V_113 -> V_115 ) ; V_109 ;
V_109 = F_59 ( V_109 -> V_115 ) ) {
if ( F_68 ( V_109 -> V_116 , V_113 -> V_116 ) )
V_113 = V_109 ;
}
F_65 ( V_113 ) ;
return V_113 ;
}
static inline T_1 F_69 ( T_6 V_57 )
{
static T_1 T_9 V_78 ;
T_1 V_117 ;
F_48 ( & T_9 , sizeof( T_9 ) ) ;
V_117 = F_70 ( ( V_63 T_1 ) V_57 , T_9 ) ;
return F_71 ( V_117 , V_118 ) ;
}
static void F_72 ( struct V_50 * V_60 , struct V_108 * V_109 )
{
V_60 -> V_119 = V_109 -> V_120 ;
V_60 -> V_2 . V_121 = V_109 -> V_122 ;
if ( V_109 -> V_123 ) {
V_60 -> V_124 |= V_125 ;
V_60 -> V_62 = V_109 -> V_123 ;
V_60 -> V_126 = 1 ;
}
}
static void F_73 ( struct V_127 * V_128 , T_6 V_57 , T_6 V_129 ,
T_1 V_130 , unsigned long V_121 )
{
struct V_112 * V_65 ;
struct V_108 * V_109 ;
struct V_50 * V_60 ;
unsigned int V_29 ;
int V_131 ;
T_1 V_117 = F_69 ( V_57 ) ;
F_74 ( & V_132 ) ;
V_65 = F_59 ( V_128 -> V_133 ) ;
if ( ! V_65 ) {
V_65 = F_75 ( V_134 * sizeof( * V_65 ) , V_135 ) ;
if ( ! V_65 )
goto V_136;
F_76 ( V_128 -> V_133 , V_65 ) ;
}
V_65 += V_117 ;
V_131 = 0 ;
for ( V_109 = F_59 ( V_65 -> V_114 ) ; V_109 ;
V_109 = F_59 ( V_109 -> V_115 ) ) {
if ( V_109 -> V_137 == V_57 )
break;
V_131 ++ ;
}
if ( V_109 ) {
if ( V_129 )
V_109 -> V_123 = V_129 ;
if ( V_130 ) {
V_109 -> V_120 = V_130 ;
V_109 -> V_122 = F_77 ( 1UL , V_121 ) ;
}
V_60 = F_59 ( V_109 -> V_110 ) ;
if ( V_60 )
F_72 ( V_60 , V_109 ) ;
V_60 = F_59 ( V_109 -> V_111 ) ;
if ( V_60 )
F_72 ( V_60 , V_109 ) ;
} else {
if ( V_131 > V_138 )
V_109 = F_67 ( V_65 ) ;
else {
V_109 = F_75 ( sizeof( * V_109 ) , V_135 ) ;
if ( ! V_109 )
goto V_136;
V_109 -> V_115 = V_65 -> V_114 ;
F_76 ( V_65 -> V_114 , V_109 ) ;
}
V_109 -> V_139 = V_139 ( F_35 ( V_128 -> V_140 ) ) ;
V_109 -> V_137 = V_57 ;
V_109 -> V_123 = V_129 ;
V_109 -> V_120 = V_130 ;
V_109 -> V_122 = V_121 ;
V_60 = F_59 ( V_128 -> V_141 ) ;
if ( V_60 )
V_60 -> V_2 . V_142 = V_143 ;
F_20 (i) {
struct V_50 T_10 * * V_144 ;
V_144 = F_21 ( V_128 -> V_145 , V_29 ) ;
V_60 = F_59 ( * V_144 ) ;
if ( V_60 )
V_60 -> V_2 . V_142 = V_143 ;
}
}
V_109 -> V_116 = V_73 ;
V_136:
F_78 ( & V_132 ) ;
}
static void F_79 ( struct V_50 * V_60 , struct V_55 * V_56 , struct V_81 * V_82 ,
bool V_146 )
{
T_6 V_147 = F_80 ( V_56 ) -> V_148 . V_149 ;
T_6 V_150 = F_39 ( V_56 ) -> V_79 ;
struct V_58 * V_53 = V_56 -> V_53 ;
struct V_151 * V_152 ;
struct V_153 V_154 ;
struct V_54 * V_61 ;
struct V_37 * V_37 ;
switch ( F_80 ( V_56 ) -> V_155 & 7 ) {
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
V_152 = F_81 ( V_53 ) ;
if ( ! V_152 )
return;
V_37 = F_35 ( V_53 ) ;
if ( V_147 == V_150 || ! F_82 ( V_152 ) ||
F_83 ( V_147 ) || F_84 ( V_147 ) ||
F_85 ( V_147 ) )
goto V_160;
if ( ! F_86 ( V_152 ) ) {
if ( ! F_87 ( V_152 , V_147 , V_150 ) )
goto V_160;
if ( F_88 ( V_152 ) && F_89 ( V_147 , V_53 ) )
goto V_160;
} else {
if ( F_90 ( V_37 , V_147 ) != V_161 )
goto V_160;
}
V_61 = F_38 ( & V_60 -> V_2 , NULL , & V_147 ) ;
if ( ! F_91 ( V_61 ) ) {
if ( ! ( V_61 -> V_162 & V_163 ) ) {
F_92 ( V_61 , NULL ) ;
} else {
if ( F_93 ( V_37 , V_82 , & V_154 ) == 0 ) {
struct V_127 * V_128 = & F_94 ( V_154 ) ;
F_73 ( V_128 , V_82 -> V_57 , V_147 ,
0 , 0 ) ;
}
if ( V_146 )
V_60 -> V_2 . V_142 = V_143 ;
F_95 ( V_164 , V_61 ) ;
}
F_96 ( V_61 ) ;
}
return;
V_160:
#ifdef F_97
if ( F_98 ( V_152 ) ) {
const struct V_76 * V_77 = ( const struct V_76 * ) V_56 -> V_165 ;
T_6 V_57 = V_77 -> V_57 ;
T_6 V_79 = V_77 -> V_79 ;
F_99 ( L_10
L_11 ,
& V_150 , V_53 -> V_166 , & V_147 ,
& V_79 , & V_57 ) ;
}
#endif
;
}
static void F_100 ( struct V_1 * V_2 , struct V_83 * V_84 , struct V_55 * V_56 )
{
struct V_50 * V_60 ;
struct V_81 V_82 ;
const struct V_76 * V_77 = ( const struct V_76 * ) V_56 -> V_165 ;
int V_85 = V_56 -> V_53 -> V_98 ;
T_8 V_86 = F_56 ( V_77 -> V_86 ) ;
T_8 V_87 = V_77 -> V_80 ;
T_1 V_88 = V_56 -> V_88 ;
V_60 = (struct V_50 * ) V_2 ;
F_51 ( & V_82 , V_84 , V_77 , V_85 , V_86 , V_87 , V_88 , 0 ) ;
F_79 ( V_60 , V_56 , & V_82 , true ) ;
}
static struct V_1 * F_101 ( struct V_1 * V_2 )
{
struct V_50 * V_60 = (struct V_50 * ) V_2 ;
struct V_1 * V_167 = V_2 ;
if ( V_60 ) {
if ( V_2 -> V_142 > 0 ) {
F_102 ( V_60 ) ;
V_167 = NULL ;
} else if ( ( V_60 -> V_124 & V_125 ) ||
V_60 -> V_2 . V_121 ) {
F_102 ( V_60 ) ;
V_167 = NULL ;
}
}
return V_167 ;
}
void F_103 ( struct V_55 * V_56 )
{
struct V_50 * V_60 = F_104 ( V_56 ) ;
struct V_151 * V_152 ;
struct V_168 * V_169 ;
struct V_37 * V_37 ;
int V_170 ;
F_58 () ;
V_152 = F_81 ( V_60 -> V_2 . V_53 ) ;
if ( ! V_152 || ! F_105 ( V_152 ) ) {
F_61 () ;
return;
}
V_170 = F_98 ( V_152 ) ;
F_61 () ;
V_37 = F_35 ( V_60 -> V_2 . V_53 ) ;
V_169 = F_106 ( V_37 -> V_171 . V_172 , F_39 ( V_56 ) -> V_79 , 1 ) ;
if ( ! V_169 ) {
F_107 ( V_56 , V_173 , V_158 ,
F_108 ( V_60 , F_39 ( V_56 ) -> V_57 ) ) ;
return;
}
if ( F_109 ( V_73 , V_169 -> V_174 + V_175 ) )
V_169 -> V_176 = 0 ;
if ( V_169 -> V_176 >= V_177 ) {
V_169 -> V_174 = V_73 ;
goto V_178;
}
if ( V_169 -> V_176 == 0 ||
F_109 ( V_73 ,
( V_169 -> V_174 +
( V_179 << V_169 -> V_176 ) ) ) ) {
T_6 V_129 = F_108 ( V_60 , F_39 ( V_56 ) -> V_57 ) ;
F_107 ( V_56 , V_173 , V_158 , V_129 ) ;
V_169 -> V_174 = V_73 ;
++ V_169 -> V_176 ;
#ifdef F_97
if ( V_170 &&
V_169 -> V_176 == V_177 )
F_110 ( L_12 ,
& F_39 ( V_56 ) -> V_79 , F_111 ( V_56 ) ,
& F_39 ( V_56 ) -> V_57 , & V_129 ) ;
#endif
}
V_178:
F_112 ( V_169 ) ;
}
static int F_113 ( struct V_55 * V_56 )
{
struct V_151 * V_152 = F_81 ( V_56 -> V_53 ) ;
struct V_50 * V_60 = F_104 ( V_56 ) ;
struct V_168 * V_169 ;
unsigned long V_72 ;
struct V_37 * V_37 ;
bool V_180 ;
int V_155 ;
V_37 = F_35 ( V_60 -> V_2 . V_53 ) ;
if ( ! F_114 ( V_152 ) ) {
switch ( V_60 -> V_2 . error ) {
case V_181 :
F_115 ( V_37 , V_182 ) ;
break;
case V_183 :
F_115 ( V_37 , V_184 ) ;
break;
}
goto V_185;
}
switch ( V_60 -> V_2 . error ) {
case V_186 :
default:
goto V_185;
case V_181 :
V_155 = V_187 ;
break;
case V_183 :
V_155 = V_188 ;
F_115 ( V_37 , V_184 ) ;
break;
case V_189 :
V_155 = V_190 ;
break;
}
V_169 = F_106 ( V_37 -> V_171 . V_172 , F_39 ( V_56 ) -> V_79 , 1 ) ;
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
F_112 ( V_169 ) ;
}
if ( V_180 )
F_107 ( V_56 , V_193 , V_155 , 0 ) ;
V_185: F_116 ( V_56 ) ;
return 0 ;
}
static void F_117 ( struct V_50 * V_60 , struct V_81 * V_82 , T_1 V_194 )
{
struct V_1 * V_2 = & V_60 -> V_2 ;
struct V_153 V_154 ;
if ( F_118 ( V_2 , V_195 ) )
return;
if ( V_2 -> V_53 -> V_194 < V_194 )
return;
if ( V_60 -> V_119 && V_60 -> V_119 < V_194 )
return;
if ( V_194 < V_196 )
V_194 = V_196 ;
if ( V_60 -> V_119 == V_194 &&
F_68 ( V_73 , V_2 -> V_121 - V_197 / 2 ) )
return;
F_58 () ;
if ( F_93 ( F_35 ( V_2 -> V_53 ) , V_82 , & V_154 ) == 0 ) {
struct V_127 * V_128 = & F_94 ( V_154 ) ;
F_73 ( V_128 , V_82 -> V_57 , 0 , V_194 ,
V_73 + V_197 ) ;
}
F_61 () ;
}
static void F_119 ( struct V_1 * V_2 , struct V_83 * V_84 ,
struct V_55 * V_56 , T_1 V_194 )
{
struct V_50 * V_60 = (struct V_50 * ) V_2 ;
struct V_81 V_82 ;
F_62 ( & V_82 , V_84 , V_56 ) ;
F_117 ( V_60 , & V_82 , V_194 ) ;
}
void F_120 ( struct V_55 * V_56 , struct V_37 * V_37 , T_1 V_194 ,
int V_85 , T_1 V_88 , T_8 V_80 , int V_89 )
{
const struct V_76 * V_77 = ( const struct V_76 * ) V_56 -> V_165 ;
struct V_81 V_82 ;
struct V_50 * V_60 ;
if ( ! V_88 )
V_88 = F_121 ( V_37 , V_56 -> V_88 ) ;
F_51 ( & V_82 , NULL , V_77 , V_85 ,
F_56 ( V_77 -> V_86 ) , V_80 , V_88 , V_89 ) ;
V_60 = F_122 ( V_37 , & V_82 ) ;
if ( ! F_91 ( V_60 ) ) {
F_117 ( V_60 , & V_82 , V_194 ) ;
F_102 ( V_60 ) ;
}
}
static void F_123 ( struct V_55 * V_56 , struct V_83 * V_84 , T_1 V_194 )
{
const struct V_76 * V_77 = ( const struct V_76 * ) V_56 -> V_165 ;
struct V_81 V_82 ;
struct V_50 * V_60 ;
F_51 ( & V_82 , V_84 , V_77 , 0 , 0 , 0 , 0 , 0 ) ;
if ( ! V_82 . V_198 )
V_82 . V_198 = F_121 ( F_124 ( V_84 ) , V_56 -> V_88 ) ;
V_60 = F_122 ( F_124 ( V_84 ) , & V_82 ) ;
if ( ! F_91 ( V_60 ) ) {
F_117 ( V_60 , & V_82 , V_194 ) ;
F_102 ( V_60 ) ;
}
}
void F_125 ( struct V_55 * V_56 , struct V_83 * V_84 , T_1 V_194 )
{
const struct V_76 * V_77 = ( const struct V_76 * ) V_56 -> V_165 ;
struct V_81 V_82 ;
struct V_50 * V_60 ;
struct V_1 * V_199 = NULL ;
bool V_200 = false ;
F_126 ( V_84 ) ;
if ( ! F_127 ( V_84 ) )
goto V_185;
V_199 = F_128 ( V_84 ) ;
if ( F_129 ( V_84 ) || ! V_199 ) {
F_123 ( V_56 , V_84 , V_194 ) ;
goto V_185;
}
F_51 ( & V_82 , V_84 , V_77 , 0 , 0 , 0 , 0 , 0 ) ;
V_60 = (struct V_50 * ) V_199 ;
if ( V_199 -> V_142 && V_199 -> V_201 -> V_202 ( V_199 , 0 ) == NULL ) {
V_60 = F_130 ( F_124 ( V_84 ) , & V_82 , V_84 ) ;
if ( F_91 ( V_60 ) )
goto V_185;
V_200 = true ;
}
F_117 ( (struct V_50 * ) V_60 -> V_2 . V_203 , & V_82 , V_194 ) ;
if ( ! F_131 ( & V_60 -> V_2 , 0 ) ) {
if ( V_200 )
F_132 ( & V_60 -> V_2 ) ;
V_60 = F_130 ( F_124 ( V_84 ) , & V_82 , V_84 ) ;
if ( F_91 ( V_60 ) )
goto V_185;
V_200 = true ;
}
if ( V_200 )
F_133 ( V_84 , & V_60 -> V_2 ) ;
V_185:
F_134 ( V_84 ) ;
F_132 ( V_199 ) ;
}
void F_135 ( struct V_55 * V_56 , struct V_37 * V_37 ,
int V_85 , T_1 V_88 , T_8 V_80 , int V_89 )
{
const struct V_76 * V_77 = ( const struct V_76 * ) V_56 -> V_165 ;
struct V_81 V_82 ;
struct V_50 * V_60 ;
F_51 ( & V_82 , NULL , V_77 , V_85 ,
F_56 ( V_77 -> V_86 ) , V_80 , V_88 , V_89 ) ;
V_60 = F_122 ( V_37 , & V_82 ) ;
if ( ! F_91 ( V_60 ) ) {
F_79 ( V_60 , V_56 , & V_82 , false ) ;
F_102 ( V_60 ) ;
}
}
void F_136 ( struct V_55 * V_56 , struct V_83 * V_84 )
{
const struct V_76 * V_77 = ( const struct V_76 * ) V_56 -> V_165 ;
struct V_81 V_82 ;
struct V_50 * V_60 ;
F_51 ( & V_82 , V_84 , V_77 , 0 , 0 , 0 , 0 , 0 ) ;
V_60 = F_122 ( F_124 ( V_84 ) , & V_82 ) ;
if ( ! F_91 ( V_60 ) ) {
F_79 ( V_60 , V_56 , & V_82 , false ) ;
F_102 ( V_60 ) ;
}
}
static struct V_1 * F_137 ( struct V_1 * V_2 , T_1 V_204 )
{
struct V_50 * V_60 = (struct V_50 * ) V_2 ;
if ( V_2 -> V_142 != V_205 || F_33 ( V_60 ) )
return NULL ;
return V_2 ;
}
static void F_138 ( struct V_55 * V_56 )
{
struct V_50 * V_60 ;
F_107 ( V_56 , V_193 , V_187 , 0 ) ;
V_60 = F_104 ( V_56 ) ;
if ( V_60 )
F_139 ( & V_60 -> V_2 , 0 ) ;
}
static int F_140 ( struct V_83 * V_84 , struct V_55 * V_56 )
{
F_141 ( L_13 ,
V_206 , & F_39 ( V_56 ) -> V_79 , & F_39 ( V_56 ) -> V_57 ,
V_56 -> V_53 ? V_56 -> V_53 -> V_166 : L_14 ) ;
F_116 ( V_56 ) ;
F_2 ( 1 ) ;
return 0 ;
}
void F_142 ( T_8 * V_207 , struct V_55 * V_56 , struct V_50 * V_60 )
{
T_6 V_28 ;
if ( F_143 ( V_60 ) )
V_28 = F_39 ( V_56 ) -> V_79 ;
else {
struct V_153 V_154 ;
struct V_81 V_82 ;
struct V_76 * V_77 ;
V_77 = F_39 ( V_56 ) ;
memset ( & V_82 , 0 , sizeof( V_82 ) ) ;
V_82 . V_57 = V_77 -> V_57 ;
V_82 . V_79 = V_77 -> V_79 ;
V_82 . V_208 = F_56 ( V_77 -> V_86 ) ;
V_82 . V_209 = V_60 -> V_2 . V_53 -> V_98 ;
V_82 . V_210 = V_56 -> V_53 -> V_98 ;
V_82 . V_198 = V_56 -> V_88 ;
F_58 () ;
if ( F_93 ( F_35 ( V_60 -> V_2 . V_53 ) , & V_82 , & V_154 ) == 0 )
V_28 = F_144 ( F_35 ( V_60 -> V_2 . V_53 ) , V_154 ) ;
else
V_28 = F_145 ( V_60 -> V_2 . V_53 ,
F_108 ( V_60 , V_77 -> V_57 ) ,
V_97 ) ;
F_61 () ;
}
memcpy ( V_207 , & V_28 , 4 ) ;
}
static void F_146 ( struct V_50 * V_60 , T_1 V_211 )
{
if ( ! ( V_60 -> V_2 . V_212 & 0xFFFF ) )
V_60 -> V_2 . V_212 |= V_211 & 0xFFFF ;
if ( ! ( V_60 -> V_2 . V_212 & 0xFFFF0000 ) )
V_60 -> V_2 . V_212 |= V_211 & 0xFFFF0000 ;
}
static unsigned int F_147 ( const struct V_1 * V_2 )
{
unsigned int V_213 = F_148 ( V_2 , V_214 ) ;
if ( V_213 == 0 ) {
V_213 = F_149 (unsigned int, dst->dev->mtu - 40 ,
ip_rt_min_advmss) ;
if ( V_213 > 65535 - 40 )
V_213 = 65535 - 40 ;
}
return V_213 ;
}
static unsigned int F_150 ( const struct V_1 * V_2 )
{
const struct V_50 * V_60 = ( const struct V_50 * ) V_2 ;
unsigned int V_194 = V_60 -> V_119 ;
if ( ! V_194 || F_151 ( V_73 , V_60 -> V_2 . V_121 ) )
V_194 = F_148 ( V_2 , V_195 ) ;
if ( V_194 )
return V_194 ;
V_194 = V_2 -> V_53 -> V_194 ;
if ( F_152 ( F_118 ( V_2 , V_195 ) ) ) {
if ( V_60 -> V_126 && V_194 > 576 )
V_194 = 576 ;
}
return F_153 (unsigned int, mtu, IP_MAX_MTU) ;
}
static struct V_108 * F_154 ( struct V_127 * V_128 , T_6 V_57 )
{
struct V_112 * V_65 = F_59 ( V_128 -> V_133 ) ;
struct V_108 * V_109 ;
T_1 V_117 ;
if ( ! V_65 )
return NULL ;
V_117 = F_69 ( V_57 ) ;
for ( V_109 = F_59 ( V_65 [ V_117 ] . V_114 ) ; V_109 ;
V_109 = F_59 ( V_109 -> V_115 ) ) {
if ( V_109 -> V_137 == V_57 )
return V_109 ;
}
return NULL ;
}
static bool F_155 ( struct V_50 * V_60 , struct V_108 * V_109 ,
T_6 V_57 )
{
bool V_167 = false ;
F_74 ( & V_132 ) ;
if ( V_57 == V_109 -> V_137 ) {
struct V_50 T_10 * * V_215 ;
struct V_50 * V_216 ;
int V_217 = V_139 ( F_35 ( V_60 -> V_2 . V_53 ) ) ;
if ( F_156 ( V_60 ) )
V_215 = & V_109 -> V_110 ;
else
V_215 = & V_109 -> V_111 ;
V_216 = F_59 ( * V_215 ) ;
if ( V_109 -> V_139 != V_217 ) {
V_109 -> V_139 = V_217 ;
V_109 -> V_123 = 0 ;
V_109 -> V_120 = 0 ;
V_109 -> V_122 = 0 ;
F_65 ( V_109 ) ;
V_216 = NULL ;
}
F_72 ( V_60 , V_109 ) ;
if ( ! V_60 -> V_62 )
V_60 -> V_62 = V_57 ;
if ( ! ( V_60 -> V_2 . V_218 & V_219 ) ) {
F_76 ( * V_215 , V_60 ) ;
if ( V_216 )
F_63 ( V_216 ) ;
V_167 = true ;
}
V_109 -> V_116 = V_73 ;
}
F_78 ( & V_132 ) ;
return V_167 ;
}
static bool F_157 ( struct V_127 * V_128 , struct V_50 * V_60 )
{
struct V_50 * V_216 , * V_220 , * * V_221 ;
bool V_167 = true ;
if ( F_156 ( V_60 ) ) {
V_221 = (struct V_50 * * ) & V_128 -> V_141 ;
} else {
V_221 = (struct V_50 * * ) F_158 ( V_128 -> V_145 ) ;
}
V_216 = * V_221 ;
V_220 = F_44 ( V_221 , V_216 , V_60 ) ;
if ( V_220 == V_216 ) {
if ( V_216 )
F_63 ( V_216 ) ;
} else
V_167 = false ;
return V_167 ;
}
static void F_159 ( struct V_50 * V_60 )
{
F_74 ( & V_222 ) ;
F_160 ( & V_60 -> V_223 , & V_224 ) ;
F_78 ( & V_222 ) ;
}
static void F_161 ( struct V_1 * V_2 )
{
struct V_50 * V_60 = (struct V_50 * ) V_2 ;
if ( ! F_162 ( & V_60 -> V_223 ) ) {
F_74 ( & V_222 ) ;
F_163 ( & V_60 -> V_223 ) ;
F_78 ( & V_222 ) ;
}
}
void F_164 ( struct V_58 * V_53 )
{
if ( ! F_162 ( & V_224 ) ) {
struct V_37 * V_37 = F_35 ( V_53 ) ;
struct V_50 * V_60 ;
F_74 ( & V_222 ) ;
F_165 (rt, &rt_uncached_list, rt_uncached) {
if ( V_60 -> V_2 . V_53 != V_53 )
continue;
V_60 -> V_2 . V_53 = V_37 -> V_225 ;
F_166 ( V_60 -> V_2 . V_53 ) ;
F_167 ( V_53 ) ;
}
F_78 ( & V_222 ) ;
}
}
static bool F_168 ( const struct V_50 * V_60 )
{
return V_60 &&
V_60 -> V_2 . V_142 == V_205 &&
! F_33 ( V_60 ) ;
}
static void F_169 ( struct V_50 * V_60 , T_6 V_57 ,
const struct V_153 * V_154 ,
struct V_108 * V_109 ,
struct V_226 * V_227 , T_11 type , T_1 V_228 )
{
bool V_229 = false ;
if ( V_227 ) {
struct V_127 * V_128 = & F_94 ( * V_154 ) ;
if ( V_128 -> V_230 && V_128 -> V_231 == V_232 ) {
V_60 -> V_62 = V_128 -> V_230 ;
V_60 -> V_126 = 1 ;
}
F_170 ( & V_60 -> V_2 , V_227 -> V_233 , true ) ;
#ifdef F_28
V_60 -> V_2 . V_212 = V_128 -> V_234 ;
#endif
if ( F_152 ( V_109 ) )
V_229 = F_155 ( V_60 , V_109 , V_57 ) ;
else if ( ! ( V_60 -> V_2 . V_218 & V_219 ) )
V_229 = F_157 ( V_128 , V_60 ) ;
if ( F_152 ( ! V_229 ) ) {
V_60 -> V_2 . V_218 |= V_219 ;
if ( ! V_60 -> V_62 )
V_60 -> V_62 = V_57 ;
F_159 ( V_60 ) ;
}
} else
F_159 ( V_60 ) ;
#ifdef F_28
#ifdef F_171
F_146 ( V_60 , V_154 -> V_212 ) ;
#endif
F_146 ( V_60 , V_228 ) ;
#endif
}
static struct V_50 * F_172 ( struct V_58 * V_53 ,
bool V_235 , bool V_236 , bool V_237 )
{
return F_173 ( & V_16 , V_53 , 1 , V_205 ,
( V_237 ? 0 : ( V_238 | V_219 ) ) |
( V_235 ? V_239 : 0 ) |
( V_236 ? V_240 : 0 ) ) ;
}
static int F_174 ( struct V_55 * V_56 , T_6 V_57 , T_6 V_79 ,
T_8 V_86 , struct V_58 * V_53 , int V_241 )
{
struct V_50 * V_51 ;
struct V_151 * V_152 = F_81 ( V_53 ) ;
T_1 V_228 = 0 ;
int V_242 ;
if ( V_152 == NULL )
return - V_186 ;
if ( F_83 ( V_79 ) || F_84 ( V_79 ) ||
V_56 -> V_80 != F_50 ( V_243 ) )
goto V_244;
if ( F_175 ( ! F_176 ( V_152 ) ) )
if ( F_177 ( V_79 ) )
goto V_244;
if ( F_85 ( V_79 ) ) {
if ( ! F_178 ( V_57 ) )
goto V_244;
} else {
V_242 = F_179 ( V_56 , V_79 , 0 , V_86 , 0 , V_53 ,
V_152 , & V_228 ) ;
if ( V_242 < 0 )
goto V_245;
}
V_51 = F_172 ( F_35 ( V_53 ) -> V_225 ,
F_180 ( V_152 , V_246 ) , false , false ) ;
if ( ! V_51 )
goto V_247;
#ifdef F_28
V_51 -> V_2 . V_212 = V_228 ;
#endif
V_51 -> V_2 . V_248 = F_140 ;
V_51 -> V_52 = F_34 ( F_35 ( V_53 ) ) ;
V_51 -> V_124 = V_249 ;
V_51 -> V_250 = V_251 ;
V_51 -> V_252 = 1 ;
V_51 -> V_253 = 0 ;
V_51 -> V_119 = 0 ;
V_51 -> V_62 = 0 ;
V_51 -> V_126 = 0 ;
F_181 ( & V_51 -> V_223 ) ;
if ( V_241 ) {
V_51 -> V_2 . V_254 = V_255 ;
V_51 -> V_124 |= V_256 ;
}
#ifdef F_182
if ( ! F_178 ( V_57 ) && F_183 ( V_152 ) )
V_51 -> V_2 . V_254 = V_257 ;
#endif
F_184 ( V_18 ) ;
F_185 ( V_56 , & V_51 -> V_2 ) ;
return 0 ;
V_247:
return - V_258 ;
V_244:
return - V_186 ;
V_245:
return V_242 ;
}
static void F_186 ( struct V_58 * V_53 ,
struct V_151 * V_152 ,
struct V_55 * V_56 ,
T_6 V_57 ,
T_6 V_79 )
{
F_184 ( V_22 ) ;
#ifdef F_97
if ( F_98 ( V_152 ) && F_187 () ) {
F_188 ( L_15 ,
& V_57 , & V_79 , V_53 -> V_166 ) ;
if ( V_53 -> V_259 && F_189 ( V_56 ) ) {
F_190 ( V_260 , L_16 ,
V_261 , 16 , 1 ,
F_191 ( V_56 ) ,
V_53 -> V_259 , true ) ;
}
}
#endif
}
static int F_192 ( struct V_55 * V_56 ,
const struct V_153 * V_154 ,
struct V_151 * V_152 ,
T_6 V_57 , T_6 V_79 , T_1 V_86 )
{
struct V_108 * V_109 ;
struct V_50 * V_51 ;
int V_242 ;
struct V_151 * V_262 ;
unsigned int V_218 = 0 ;
bool V_263 ;
T_1 V_228 = 0 ;
V_262 = F_81 ( F_193 ( * V_154 ) ) ;
if ( V_262 == NULL ) {
F_194 ( L_17 ) ;
return - V_186 ;
}
V_242 = F_179 ( V_56 , V_79 , V_57 , V_86 , F_195 ( * V_154 ) ,
V_152 -> V_53 , V_152 , & V_228 ) ;
if ( V_242 < 0 ) {
F_186 ( V_152 -> V_53 , V_152 , V_56 , V_57 ,
V_79 ) ;
goto V_264;
}
V_263 = V_154 -> V_227 && ! V_228 ;
if ( V_262 == V_152 && V_242 && F_105 ( V_262 ) &&
V_56 -> V_80 == F_50 ( V_243 ) &&
( F_86 ( V_262 ) ||
F_87 ( V_262 , V_79 , F_196 ( * V_154 ) ) ) )
F_197 ( V_56 ) -> V_218 |= V_265 ;
if ( V_56 -> V_80 != F_50 ( V_243 ) ) {
if ( V_262 == V_152 &&
F_198 ( V_152 ) == 0 ) {
V_242 = - V_186 ;
goto V_264;
}
}
V_109 = F_154 ( & F_94 ( * V_154 ) , V_57 ) ;
if ( V_263 ) {
if ( V_109 != NULL )
V_51 = F_59 ( V_109 -> V_110 ) ;
else
V_51 = F_59 ( F_94 ( * V_154 ) . V_141 ) ;
if ( F_168 ( V_51 ) ) {
F_199 ( V_56 , & V_51 -> V_2 ) ;
goto V_185;
}
}
V_51 = F_172 ( V_262 -> V_53 ,
F_180 ( V_152 , V_246 ) ,
F_180 ( V_262 , V_266 ) , V_263 ) ;
if ( ! V_51 ) {
V_242 = - V_258 ;
goto V_264;
}
V_51 -> V_52 = F_34 ( F_35 ( V_51 -> V_2 . V_53 ) ) ;
V_51 -> V_124 = V_218 ;
V_51 -> V_250 = V_154 -> type ;
V_51 -> V_252 = 1 ;
V_51 -> V_253 = 0 ;
V_51 -> V_119 = 0 ;
V_51 -> V_62 = 0 ;
V_51 -> V_126 = 0 ;
F_181 ( & V_51 -> V_223 ) ;
F_184 ( V_17 ) ;
V_51 -> V_2 . V_254 = V_267 ;
V_51 -> V_2 . V_248 = V_268 ;
F_169 ( V_51 , V_57 , V_154 , V_109 , V_154 -> V_227 , V_154 -> type , V_228 ) ;
F_185 ( V_56 , & V_51 -> V_2 ) ;
V_185:
V_242 = 0 ;
V_264:
return V_242 ;
}
static int F_200 ( struct V_55 * V_56 ,
struct V_153 * V_154 ,
const struct V_81 * V_82 ,
struct V_151 * V_152 ,
T_6 V_57 , T_6 V_79 , T_1 V_86 )
{
#ifdef F_201
if ( V_154 -> V_227 && V_154 -> V_227 -> V_269 > 1 )
F_202 ( V_154 ) ;
#endif
return F_192 ( V_56 , V_154 , V_152 , V_57 , V_79 , V_86 ) ;
}
static int F_203 ( struct V_55 * V_56 , T_6 V_57 , T_6 V_79 ,
T_8 V_86 , struct V_58 * V_53 )
{
struct V_153 V_154 ;
struct V_151 * V_152 = F_81 ( V_53 ) ;
struct V_81 V_82 ;
unsigned int V_218 = 0 ;
T_1 V_228 = 0 ;
struct V_50 * V_51 ;
int V_242 = - V_186 ;
struct V_37 * V_37 = F_35 ( V_53 ) ;
bool V_263 ;
if ( ! V_152 )
goto V_185;
if ( F_83 ( V_79 ) || F_84 ( V_79 ) )
goto V_270;
V_154 . V_227 = NULL ;
if ( F_84 ( V_57 ) || ( V_79 == 0 && V_57 == 0 ) )
goto V_271;
if ( F_85 ( V_79 ) )
goto V_270;
if ( F_85 ( V_57 ) )
goto V_272;
if ( F_177 ( V_57 ) ) {
if ( ! F_204 ( V_152 , V_37 ) )
goto V_272;
} else if ( F_177 ( V_79 ) ) {
if ( ! F_204 ( V_152 , V_37 ) )
goto V_270;
}
V_82 . V_209 = 0 ;
V_82 . V_210 = V_53 -> V_98 ;
V_82 . V_198 = V_56 -> V_88 ;
V_82 . V_208 = V_86 ;
V_82 . V_273 = V_97 ;
V_82 . V_57 = V_57 ;
V_82 . V_79 = V_79 ;
V_242 = F_93 ( V_37 , & V_82 , & V_154 ) ;
if ( V_242 != 0 ) {
if ( ! F_114 ( V_152 ) )
V_242 = - V_181 ;
goto V_274;
}
if ( V_154 . type == V_275 )
goto V_271;
if ( V_154 . type == V_276 ) {
V_242 = F_179 ( V_56 , V_79 , V_57 , V_86 ,
0 , V_53 , V_152 , & V_228 ) ;
if ( V_242 < 0 )
goto V_277;
goto V_278;
}
if ( ! F_114 ( V_152 ) ) {
V_242 = - V_181 ;
goto V_274;
}
if ( V_154 . type != V_161 )
goto V_272;
V_242 = F_200 ( V_56 , & V_154 , & V_82 , V_152 , V_57 , V_79 , V_86 ) ;
V_185: return V_242 ;
V_271:
if ( V_56 -> V_80 != F_50 ( V_243 ) )
goto V_244;
if ( ! F_85 ( V_79 ) ) {
V_242 = F_179 ( V_56 , V_79 , 0 , V_86 , 0 , V_53 ,
V_152 , & V_228 ) ;
if ( V_242 < 0 )
goto V_277;
}
V_218 |= V_279 ;
V_154 . type = V_275 ;
F_184 ( V_20 ) ;
V_278:
V_263 = false ;
if ( V_154 . V_227 ) {
if ( ! V_228 ) {
V_51 = F_59 ( F_94 ( V_154 ) . V_141 ) ;
if ( F_168 ( V_51 ) ) {
F_199 ( V_56 , & V_51 -> V_2 ) ;
V_242 = 0 ;
goto V_185;
}
V_263 = true ;
}
}
V_51 = F_172 ( V_37 -> V_225 ,
F_180 ( V_152 , V_246 ) , false , V_263 ) ;
if ( ! V_51 )
goto V_247;
V_51 -> V_2 . V_254 = V_255 ;
V_51 -> V_2 . V_248 = F_140 ;
#ifdef F_28
V_51 -> V_2 . V_212 = V_228 ;
#endif
V_51 -> V_52 = F_34 ( V_37 ) ;
V_51 -> V_124 = V_218 | V_256 ;
V_51 -> V_250 = V_154 . type ;
V_51 -> V_252 = 1 ;
V_51 -> V_253 = 0 ;
V_51 -> V_119 = 0 ;
V_51 -> V_62 = 0 ;
V_51 -> V_126 = 0 ;
F_181 ( & V_51 -> V_223 ) ;
F_184 ( V_17 ) ;
if ( V_154 . type == V_280 ) {
V_51 -> V_2 . V_254 = F_113 ;
V_51 -> V_2 . error = - V_242 ;
V_51 -> V_124 &= ~ V_256 ;
}
if ( V_263 ) {
if ( F_152 ( ! F_157 ( & F_94 ( V_154 ) , V_51 ) ) ) {
V_51 -> V_2 . V_218 |= V_219 ;
F_159 ( V_51 ) ;
}
}
F_185 ( V_56 , & V_51 -> V_2 ) ;
V_242 = 0 ;
goto V_185;
V_274:
F_184 ( V_19 ) ;
V_154 . type = V_280 ;
V_154 . V_227 = NULL ;
goto V_278;
V_272:
F_184 ( V_21 ) ;
#ifdef F_97
if ( F_98 ( V_152 ) )
F_110 ( L_18 ,
& V_57 , & V_79 , V_53 -> V_166 ) ;
#endif
V_244:
V_242 = - V_186 ;
goto V_185;
V_247:
V_242 = - V_258 ;
goto V_185;
V_270:
V_242 = - V_186 ;
V_277:
F_186 ( V_53 , V_152 , V_56 , V_57 , V_79 ) ;
goto V_185;
}
int F_205 ( struct V_55 * V_56 , T_6 V_57 , T_6 V_79 ,
T_8 V_86 , struct V_58 * V_53 )
{
int V_154 ;
F_58 () ;
if ( F_83 ( V_57 ) ) {
struct V_151 * V_152 = F_81 ( V_53 ) ;
if ( V_152 ) {
int V_241 = F_206 ( V_152 , V_57 , V_79 ,
F_39 ( V_56 ) -> V_80 ) ;
if ( V_241
#ifdef F_182
||
( ! F_178 ( V_57 ) &&
F_183 ( V_152 ) )
#endif
) {
int V_154 = F_174 ( V_56 , V_57 , V_79 ,
V_86 , V_53 , V_241 ) ;
F_61 () ;
return V_154 ;
}
}
F_61 () ;
return - V_186 ;
}
V_154 = F_203 ( V_56 , V_57 , V_79 , V_86 , V_53 ) ;
F_61 () ;
return V_154 ;
}
static struct V_50 * F_207 ( const struct V_153 * V_154 ,
const struct V_81 * V_82 , int V_281 ,
struct V_58 * V_282 ,
unsigned int V_218 )
{
struct V_226 * V_227 = V_154 -> V_227 ;
struct V_108 * V_109 ;
struct V_151 * V_152 ;
T_11 type = V_154 -> type ;
struct V_50 * V_51 ;
bool V_263 ;
V_152 = F_81 ( V_282 ) ;
if ( ! V_152 )
return F_208 ( - V_186 ) ;
if ( F_175 ( ! F_176 ( V_152 ) ) )
if ( F_177 ( V_82 -> V_79 ) && ! ( V_282 -> V_218 & V_283 ) )
return F_208 ( - V_186 ) ;
if ( F_84 ( V_82 -> V_57 ) )
type = V_275 ;
else if ( F_83 ( V_82 -> V_57 ) )
type = V_251 ;
else if ( F_85 ( V_82 -> V_57 ) )
return F_208 ( - V_186 ) ;
if ( V_282 -> V_218 & V_283 )
V_218 |= V_256 ;
V_263 = true ;
if ( type == V_275 ) {
V_218 |= V_279 | V_256 ;
V_227 = NULL ;
} else if ( type == V_251 ) {
V_218 |= V_249 | V_256 ;
if ( ! F_206 ( V_152 , V_82 -> V_57 , V_82 -> V_79 ,
V_82 -> V_284 ) )
V_218 &= ~ V_256 ;
else
V_263 = false ;
if ( V_227 && V_154 -> V_285 < 4 )
V_227 = NULL ;
}
V_109 = NULL ;
V_263 &= V_227 != NULL ;
if ( V_263 ) {
struct V_50 T_10 * * V_286 ;
struct V_127 * V_128 = & F_94 ( * V_154 ) ;
V_109 = F_154 ( V_128 , V_82 -> V_57 ) ;
if ( V_109 )
V_286 = & V_109 -> V_111 ;
else {
if ( F_152 ( V_82 -> V_287 &
V_288 &&
! ( V_128 -> V_230 &&
V_128 -> V_231 == V_232 ) ) ) {
V_263 = false ;
goto V_289;
}
V_286 = F_158 ( V_128 -> V_145 ) ;
}
V_51 = F_59 ( * V_286 ) ;
if ( F_168 ( V_51 ) ) {
F_209 ( & V_51 -> V_2 ) ;
return V_51 ;
}
}
V_289:
V_51 = F_172 ( V_282 ,
F_180 ( V_152 , V_246 ) ,
F_180 ( V_152 , V_266 ) ,
V_263 ) ;
if ( ! V_51 )
return F_208 ( - V_258 ) ;
V_51 -> V_2 . V_248 = V_268 ;
V_51 -> V_52 = F_34 ( F_35 ( V_282 ) ) ;
V_51 -> V_124 = V_218 ;
V_51 -> V_250 = type ;
V_51 -> V_252 = 0 ;
V_51 -> V_253 = V_281 ? : 0 ;
V_51 -> V_119 = 0 ;
V_51 -> V_62 = 0 ;
V_51 -> V_126 = 0 ;
F_181 ( & V_51 -> V_223 ) ;
F_184 ( V_23 ) ;
if ( V_218 & V_256 )
V_51 -> V_2 . V_254 = V_255 ;
if ( V_218 & ( V_279 | V_249 ) ) {
if ( V_218 & V_256 &&
! ( V_282 -> V_218 & V_283 ) ) {
V_51 -> V_2 . V_248 = V_290 ;
F_184 ( V_24 ) ;
}
#ifdef F_182
if ( type == V_251 ) {
if ( F_183 ( V_152 ) &&
! F_178 ( V_82 -> V_57 ) ) {
V_51 -> V_2 . V_254 = V_257 ;
V_51 -> V_2 . V_248 = V_290 ;
}
}
#endif
}
F_169 ( V_51 , V_82 -> V_57 , V_154 , V_109 , V_227 , type , 0 ) ;
return V_51 ;
}
struct V_50 * F_122 ( struct V_37 * V_37 , struct V_81 * V_82 )
{
struct V_58 * V_282 = NULL ;
T_12 V_86 = F_210 ( V_82 ) ;
unsigned int V_218 = 0 ;
struct V_153 V_154 ;
struct V_50 * V_51 ;
int V_281 ;
V_154 . V_212 = 0 ;
V_154 . V_227 = NULL ;
V_154 . V_291 = NULL ;
V_281 = V_82 -> V_209 ;
V_82 -> V_210 = V_292 ;
V_82 -> V_208 = V_86 & V_293 ;
V_82 -> V_273 = ( ( V_86 & V_294 ) ?
V_232 : V_97 ) ;
F_58 () ;
if ( V_82 -> V_79 ) {
V_51 = F_208 ( - V_186 ) ;
if ( F_83 ( V_82 -> V_79 ) ||
F_84 ( V_82 -> V_79 ) ||
F_85 ( V_82 -> V_79 ) )
goto V_185;
if ( V_82 -> V_209 == 0 &&
( F_83 ( V_82 -> V_57 ) ||
F_84 ( V_82 -> V_57 ) ) ) {
V_282 = F_211 ( V_37 , V_82 -> V_79 , false ) ;
if ( V_282 == NULL )
goto V_185;
V_82 -> V_209 = V_282 -> V_98 ;
goto V_295;
}
if ( ! ( V_82 -> V_287 & V_296 ) ) {
if ( ! F_211 ( V_37 , V_82 -> V_79 , false ) )
goto V_185;
}
}
if ( V_82 -> V_209 ) {
V_282 = F_212 ( V_37 , V_82 -> V_209 ) ;
V_51 = F_208 ( - V_297 ) ;
if ( V_282 == NULL )
goto V_185;
if ( ! ( V_282 -> V_218 & V_298 ) || ! F_81 ( V_282 ) ) {
V_51 = F_208 ( - V_183 ) ;
goto V_185;
}
if ( F_178 ( V_82 -> V_57 ) ||
F_84 ( V_82 -> V_57 ) ) {
if ( ! V_82 -> V_79 )
V_82 -> V_79 = F_145 ( V_282 , 0 ,
V_232 ) ;
goto V_295;
}
if ( ! V_82 -> V_79 ) {
if ( F_83 ( V_82 -> V_57 ) )
V_82 -> V_79 = F_145 ( V_282 , 0 ,
V_82 -> V_273 ) ;
else if ( ! V_82 -> V_57 )
V_82 -> V_79 = F_145 ( V_282 , 0 ,
V_299 ) ;
}
}
if ( ! V_82 -> V_57 ) {
V_82 -> V_57 = V_82 -> V_79 ;
if ( ! V_82 -> V_57 )
V_82 -> V_57 = V_82 -> V_79 = F_213 ( V_300 ) ;
V_282 = V_37 -> V_225 ;
V_82 -> V_209 = V_292 ;
V_154 . type = V_276 ;
V_218 |= V_256 ;
goto V_295;
}
if ( F_93 ( V_37 , V_82 , & V_154 ) ) {
V_154 . V_227 = NULL ;
V_154 . V_291 = NULL ;
if ( V_82 -> V_209 ) {
if ( V_82 -> V_79 == 0 )
V_82 -> V_79 = F_145 ( V_282 , 0 ,
V_232 ) ;
V_154 . type = V_161 ;
goto V_295;
}
V_51 = F_208 ( - V_183 ) ;
goto V_185;
}
if ( V_154 . type == V_276 ) {
if ( ! V_82 -> V_79 ) {
if ( V_154 . V_227 -> V_301 )
V_82 -> V_79 = V_154 . V_227 -> V_301 ;
else
V_82 -> V_79 = V_82 -> V_57 ;
}
V_282 = V_37 -> V_225 ;
V_82 -> V_209 = V_282 -> V_98 ;
V_218 |= V_256 ;
goto V_295;
}
#ifdef F_201
if ( V_154 . V_227 -> V_269 > 1 && V_82 -> V_209 == 0 )
F_202 ( & V_154 ) ;
else
#endif
if ( ! V_154 . V_285 &&
V_154 . V_291 -> V_302 > 1 &&
V_154 . type == V_161 && ! V_82 -> V_209 )
F_214 ( & V_154 ) ;
if ( ! V_82 -> V_79 )
V_82 -> V_79 = F_144 ( V_37 , V_154 ) ;
V_282 = F_193 ( V_154 ) ;
V_82 -> V_209 = V_282 -> V_98 ;
V_295:
V_51 = F_207 ( & V_154 , V_82 , V_281 , V_282 , V_218 ) ;
V_185:
F_61 () ;
return V_51 ;
}
static struct V_1 * F_215 ( struct V_1 * V_2 , T_1 V_204 )
{
return NULL ;
}
static unsigned int F_216 ( const struct V_1 * V_2 )
{
unsigned int V_194 = F_148 ( V_2 , V_195 ) ;
return V_194 ? : V_2 -> V_53 -> V_194 ;
}
static void F_217 ( struct V_1 * V_2 , struct V_83 * V_84 ,
struct V_55 * V_56 , T_1 V_194 )
{
}
static void F_218 ( struct V_1 * V_2 , struct V_83 * V_84 ,
struct V_55 * V_56 )
{
}
static T_1 * F_219 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
return NULL ;
}
struct V_1 * F_220 ( struct V_37 * V_37 , struct V_1 * V_303 )
{
struct V_50 * V_304 = (struct V_50 * ) V_303 ;
struct V_50 * V_60 ;
V_60 = F_173 ( & V_305 , NULL , 1 , V_306 , 0 ) ;
if ( V_60 ) {
struct V_1 * V_200 = & V_60 -> V_2 ;
V_200 -> V_307 = 1 ;
V_200 -> V_254 = V_308 ;
V_200 -> V_248 = V_309 ;
V_200 -> V_53 = V_304 -> V_2 . V_53 ;
if ( V_200 -> V_53 )
F_166 ( V_200 -> V_53 ) ;
V_60 -> V_252 = V_304 -> V_252 ;
V_60 -> V_253 = V_304 -> V_253 ;
V_60 -> V_119 = V_304 -> V_119 ;
V_60 -> V_52 = F_34 ( V_37 ) ;
V_60 -> V_124 = V_304 -> V_124 ;
V_60 -> V_250 = V_304 -> V_250 ;
V_60 -> V_62 = V_304 -> V_62 ;
V_60 -> V_126 = V_304 -> V_126 ;
F_181 ( & V_60 -> V_223 ) ;
F_221 ( V_200 ) ;
}
F_132 ( V_303 ) ;
return V_60 ? & V_60 -> V_2 : F_208 ( - V_32 ) ;
}
struct V_50 * F_130 ( struct V_37 * V_37 , struct V_81 * V_310 ,
struct V_83 * V_84 )
{
struct V_50 * V_60 = F_122 ( V_37 , V_310 ) ;
if ( F_91 ( V_60 ) )
return V_60 ;
if ( V_310 -> V_284 )
V_60 = (struct V_50 * ) F_222 ( V_37 , & V_60 -> V_2 ,
F_223 ( V_310 ) ,
V_84 , 0 ) ;
return V_60 ;
}
static int F_224 ( struct V_37 * V_37 , T_6 V_2 , T_6 V_28 ,
struct V_81 * V_82 , struct V_55 * V_56 , T_1 V_311 ,
T_1 V_5 , int V_312 , int V_313 , unsigned int V_218 )
{
struct V_50 * V_60 = F_104 ( V_56 ) ;
struct V_314 * V_315 ;
struct V_316 * V_317 ;
unsigned long V_121 = 0 ;
T_1 error ;
T_1 V_318 [ V_319 ] ;
V_317 = F_225 ( V_56 , V_311 , V_5 , V_312 , sizeof( * V_315 ) , V_218 ) ;
if ( V_317 == NULL )
return - V_320 ;
V_315 = F_226 ( V_317 ) ;
V_315 -> V_321 = V_322 ;
V_315 -> V_323 = 32 ;
V_315 -> V_324 = 0 ;
V_315 -> V_325 = V_82 -> V_208 ;
V_315 -> V_326 = V_327 ;
if ( F_227 ( V_56 , V_328 , V_327 ) )
goto V_329;
V_315 -> V_330 = V_60 -> V_250 ;
V_315 -> V_331 = V_97 ;
V_315 -> V_332 = V_333 ;
V_315 -> V_334 = ( V_60 -> V_124 & ~ 0xFFFF ) | V_335 ;
if ( V_60 -> V_124 & V_336 )
V_315 -> V_334 |= V_337 ;
if ( F_197 ( V_56 ) -> V_218 & V_265 )
V_315 -> V_334 |= V_338 ;
if ( F_228 ( V_56 , V_339 , V_2 ) )
goto V_329;
if ( V_28 ) {
V_315 -> V_324 = 32 ;
if ( F_228 ( V_56 , V_340 , V_28 ) )
goto V_329;
}
if ( V_60 -> V_2 . V_53 &&
F_227 ( V_56 , V_341 , V_60 -> V_2 . V_53 -> V_98 ) )
goto V_329;
#ifdef F_28
if ( V_60 -> V_2 . V_212 &&
F_227 ( V_56 , V_342 , V_60 -> V_2 . V_212 ) )
goto V_329;
#endif
if ( ! F_156 ( V_60 ) &&
V_82 -> V_79 != V_28 ) {
if ( F_228 ( V_56 , V_343 , V_82 -> V_79 ) )
goto V_329;
}
if ( V_60 -> V_126 &&
F_228 ( V_56 , V_344 , V_60 -> V_62 ) )
goto V_329;
V_121 = V_60 -> V_2 . V_121 ;
if ( V_121 ) {
unsigned long V_72 = V_73 ;
if ( F_68 ( V_72 , V_121 ) )
V_121 -= V_72 ;
else
V_121 = 0 ;
}
memcpy ( V_318 , F_229 ( & V_60 -> V_2 ) , sizeof( V_318 ) ) ;
if ( V_60 -> V_119 && V_121 )
V_318 [ V_195 - 1 ] = V_60 -> V_119 ;
if ( F_230 ( V_56 , V_318 ) < 0 )
goto V_329;
if ( V_82 -> V_198 &&
F_227 ( V_56 , V_345 , V_82 -> V_198 ) )
goto V_329;
error = V_60 -> V_2 . error ;
if ( F_156 ( V_60 ) ) {
#ifdef F_182
if ( F_83 ( V_2 ) && ! F_178 ( V_2 ) &&
F_231 ( V_37 , V_346 ) ) {
int V_242 = F_232 ( V_37 , V_56 ,
V_82 -> V_79 , V_82 -> V_57 ,
V_315 , V_313 ) ;
if ( V_242 <= 0 ) {
if ( ! V_313 ) {
if ( V_242 == 0 )
return 0 ;
goto V_329;
} else {
if ( V_242 == - V_320 )
goto V_329;
error = V_242 ;
}
}
} else
#endif
if ( F_227 ( V_56 , V_347 , V_56 -> V_53 -> V_98 ) )
goto V_329;
}
if ( F_233 ( V_56 , & V_60 -> V_2 , 0 , V_121 , error ) < 0 )
goto V_329;
return F_234 ( V_56 , V_317 ) ;
V_329:
F_235 ( V_56 , V_317 ) ;
return - V_320 ;
}
static int F_236 ( struct V_55 * V_348 , struct V_316 * V_317 )
{
struct V_37 * V_37 = F_124 ( V_348 -> V_84 ) ;
struct V_314 * V_349 ;
struct V_350 * V_351 [ V_352 + 1 ] ;
struct V_50 * V_60 = NULL ;
struct V_81 V_82 ;
T_6 V_2 = 0 ;
T_6 V_28 = 0 ;
T_1 V_353 ;
int V_242 ;
int V_88 ;
struct V_55 * V_56 ;
V_242 = F_237 ( V_317 , sizeof( * V_349 ) , V_351 , V_352 , V_354 ) ;
if ( V_242 < 0 )
goto V_355;
V_349 = F_226 ( V_317 ) ;
V_56 = F_238 ( V_356 , V_31 ) ;
if ( V_56 == NULL ) {
V_242 = - V_258 ;
goto V_355;
}
F_239 ( V_56 ) ;
F_240 ( V_56 ) ;
F_39 ( V_56 ) -> V_80 = V_357 ;
F_241 ( V_56 , V_358 + sizeof( struct V_76 ) ) ;
V_28 = V_351 [ V_340 ] ? F_242 ( V_351 [ V_340 ] ) : 0 ;
V_2 = V_351 [ V_339 ] ? F_242 ( V_351 [ V_339 ] ) : 0 ;
V_353 = V_351 [ V_347 ] ? F_243 ( V_351 [ V_347 ] ) : 0 ;
V_88 = V_351 [ V_345 ] ? F_243 ( V_351 [ V_345 ] ) : 0 ;
memset ( & V_82 , 0 , sizeof( V_82 ) ) ;
V_82 . V_57 = V_2 ;
V_82 . V_79 = V_28 ;
V_82 . V_208 = V_349 -> V_325 ;
V_82 . V_209 = V_351 [ V_341 ] ? F_243 ( V_351 [ V_341 ] ) : 0 ;
V_82 . V_198 = V_88 ;
if ( V_353 ) {
struct V_58 * V_53 ;
V_53 = F_244 ( V_37 , V_353 ) ;
if ( V_53 == NULL ) {
V_242 = - V_297 ;
goto V_359;
}
V_56 -> V_80 = F_50 ( V_243 ) ;
V_56 -> V_53 = V_53 ;
V_56 -> V_88 = V_88 ;
F_245 () ;
V_242 = F_246 ( V_56 , V_2 , V_28 , V_349 -> V_325 , V_53 ) ;
F_247 () ;
V_60 = F_104 ( V_56 ) ;
if ( V_242 == 0 && V_60 -> V_2 . error )
V_242 = - V_60 -> V_2 . error ;
} else {
V_60 = F_248 ( V_37 , & V_82 ) ;
V_242 = 0 ;
if ( F_91 ( V_60 ) )
V_242 = F_249 ( V_60 ) ;
}
if ( V_242 )
goto V_359;
F_185 ( V_56 , & V_60 -> V_2 ) ;
if ( V_349 -> V_334 & V_337 )
V_60 -> V_124 |= V_336 ;
V_242 = F_224 ( V_37 , V_2 , V_28 , & V_82 , V_56 ,
F_250 ( V_348 ) . V_311 , V_317 -> V_360 ,
V_361 , 0 , 0 ) ;
if ( V_242 <= 0 )
goto V_359;
V_242 = F_251 ( V_56 , V_37 , F_250 ( V_348 ) . V_311 ) ;
V_355:
return V_242 ;
V_359:
F_116 ( V_56 ) ;
goto V_355;
}
void F_252 ( struct V_151 * V_152 )
{
F_36 ( F_35 ( V_152 -> V_53 ) ) ;
}
static int F_253 ( struct V_362 * V_363 , int V_364 ,
void T_13 * V_365 ,
T_14 * V_366 , T_2 * V_367 )
{
struct V_37 * V_37 = (struct V_37 * ) V_363 -> V_368 ;
if ( V_364 ) {
F_36 ( V_37 ) ;
F_254 ( V_37 ) ;
return 0 ;
}
return - V_186 ;
}
static T_3 int F_255 ( struct V_37 * V_37 )
{
struct V_362 * V_369 ;
V_369 = V_370 ;
if ( ! F_256 ( V_37 , & V_371 ) ) {
V_369 = F_257 ( V_369 , sizeof( V_370 ) , V_31 ) ;
if ( V_369 == NULL )
goto V_372;
if ( V_37 -> V_373 != & V_374 )
V_369 [ 0 ] . V_375 = NULL ;
}
V_369 [ 0 ] . V_368 = V_37 ;
V_37 -> V_171 . V_376 = F_258 ( V_37 , L_19 , V_369 ) ;
if ( V_37 -> V_171 . V_376 == NULL )
goto V_377;
return 0 ;
V_377:
if ( V_369 != V_370 )
F_23 ( V_369 ) ;
V_372:
return - V_32 ;
}
static T_4 void F_259 ( struct V_37 * V_37 )
{
struct V_362 * V_369 ;
V_369 = V_37 -> V_171 . V_376 -> V_378 ;
F_260 ( V_37 -> V_171 . V_376 ) ;
F_261 ( V_369 == V_370 ) ;
F_23 ( V_369 ) ;
}
static T_3 int F_262 ( struct V_37 * V_37 )
{
F_263 ( & V_37 -> V_171 . V_52 , 0 ) ;
F_263 ( & V_37 -> V_139 , 0 ) ;
F_264 ( & V_37 -> V_171 . V_379 ,
sizeof( V_37 -> V_171 . V_379 ) ) ;
return 0 ;
}
static int T_3 F_265 ( struct V_37 * V_37 )
{
struct V_380 * V_381 = F_266 ( sizeof( * V_381 ) , V_31 ) ;
if ( ! V_381 )
return - V_32 ;
F_267 ( V_381 ) ;
V_37 -> V_171 . V_172 = V_381 ;
return 0 ;
}
static void T_4 F_268 ( struct V_37 * V_37 )
{
struct V_380 * V_381 = V_37 -> V_171 . V_172 ;
V_37 -> V_171 . V_172 = NULL ;
F_269 ( V_381 ) ;
F_23 ( V_381 ) ;
}
int T_5 F_270 ( void )
{
int V_382 = 0 ;
V_69 = F_266 ( V_70 * sizeof( * V_69 ) , V_31 ) ;
if ( ! V_69 )
F_271 ( L_20 ) ;
F_272 ( V_69 , V_70 * sizeof( * V_69 ) ) ;
#ifdef F_28
V_27 = F_273 ( 256 * sizeof( struct V_27 ) , F_274 ( struct V_27 ) ) ;
if ( ! V_27 )
F_271 ( L_21 ) ;
#endif
V_16 . V_383 =
F_275 ( L_22 , sizeof( struct V_50 ) , 0 ,
V_384 | V_385 , NULL ) ;
V_305 . V_383 = V_16 . V_383 ;
if ( F_276 ( & V_16 ) < 0 )
F_271 ( L_23 ) ;
if ( F_276 ( & V_305 ) < 0 )
F_271 ( L_24 ) ;
V_16 . V_386 = ~ 0 ;
V_387 = V_388 ;
F_277 () ;
F_278 () ;
if ( F_31 () )
F_279 ( L_25 ) ;
#ifdef F_280
F_281 () ;
F_282 () ;
#endif
F_283 ( V_389 , V_390 , F_236 , NULL , NULL ) ;
#ifdef F_284
F_32 ( & V_391 ) ;
#endif
F_32 ( & V_392 ) ;
F_32 ( & V_393 ) ;
return V_382 ;
}
void T_5 F_285 ( void )
{
F_258 ( & V_371 , L_19 , V_394 ) ;
}
