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
static void F_68 ( struct V_112 * V_113 )
{
struct V_50 * V_60 ;
V_60 = F_64 ( V_113 -> V_114 ) ;
if ( V_60 ) {
F_69 ( V_113 -> V_114 , NULL ) ;
F_70 ( & V_60 -> V_2 ) ;
F_71 ( & V_60 -> V_2 ) ;
}
V_60 = F_64 ( V_113 -> V_115 ) ;
if ( V_60 ) {
F_69 ( V_113 -> V_115 , NULL ) ;
F_70 ( & V_60 -> V_2 ) ;
F_71 ( & V_60 -> V_2 ) ;
}
}
static struct V_112 * F_72 ( struct V_116 * V_69 )
{
struct V_112 * V_113 , * V_117 ;
V_117 = F_64 ( V_69 -> V_118 ) ;
for ( V_113 = F_64 ( V_117 -> V_119 ) ; V_113 ;
V_113 = F_64 ( V_113 -> V_119 ) ) {
if ( F_73 ( V_113 -> V_120 , V_117 -> V_120 ) )
V_117 = V_113 ;
}
F_68 ( V_117 ) ;
return V_117 ;
}
static inline T_1 F_74 ( T_6 V_57 )
{
static T_1 T_10 V_82 ;
T_1 V_121 ;
F_51 ( & T_10 , sizeof( T_10 ) ) ;
V_121 = F_75 ( ( V_63 T_1 ) V_57 , T_10 ) ;
return F_76 ( V_121 , V_122 ) ;
}
static void F_77 ( struct V_50 * V_60 , struct V_112 * V_113 )
{
V_60 -> V_123 = V_113 -> V_124 ;
V_60 -> V_2 . V_125 = V_113 -> V_126 ;
if ( V_113 -> V_127 ) {
V_60 -> V_65 |= V_128 ;
V_60 -> V_62 = V_113 -> V_127 ;
V_60 -> V_129 = 1 ;
}
}
static void F_78 ( struct V_130 * V_131 , T_6 V_57 , T_6 V_132 ,
T_1 V_133 , unsigned long V_125 )
{
struct V_116 * V_69 ;
struct V_112 * V_113 ;
struct V_50 * V_60 ;
unsigned int V_29 ;
int V_134 ;
T_1 V_121 = F_74 ( V_57 ) ;
F_79 ( & V_135 ) ;
V_69 = F_64 ( V_131 -> V_136 ) ;
if ( ! V_69 ) {
V_69 = F_80 ( V_137 * sizeof( * V_69 ) , V_138 ) ;
if ( ! V_69 )
goto V_139;
F_81 ( V_131 -> V_136 , V_69 ) ;
}
V_69 += V_121 ;
V_134 = 0 ;
for ( V_113 = F_64 ( V_69 -> V_118 ) ; V_113 ;
V_113 = F_64 ( V_113 -> V_119 ) ) {
if ( V_113 -> V_140 == V_57 )
break;
V_134 ++ ;
}
if ( V_113 ) {
if ( V_132 )
V_113 -> V_127 = V_132 ;
if ( V_133 ) {
V_113 -> V_124 = V_133 ;
V_113 -> V_126 = F_82 ( 1UL , V_125 ) ;
}
V_60 = F_64 ( V_113 -> V_114 ) ;
if ( V_60 )
F_77 ( V_60 , V_113 ) ;
V_60 = F_64 ( V_113 -> V_115 ) ;
if ( V_60 )
F_77 ( V_60 , V_113 ) ;
} else {
if ( V_134 > V_141 )
V_113 = F_72 ( V_69 ) ;
else {
V_113 = F_80 ( sizeof( * V_113 ) , V_138 ) ;
if ( ! V_113 )
goto V_139;
V_113 -> V_119 = V_69 -> V_118 ;
F_81 ( V_69 -> V_118 , V_113 ) ;
}
V_113 -> V_142 = V_142 ( F_35 ( V_131 -> V_143 ) ) ;
V_113 -> V_140 = V_57 ;
V_113 -> V_127 = V_132 ;
V_113 -> V_124 = V_133 ;
V_113 -> V_126 = V_125 ;
V_60 = F_64 ( V_131 -> V_144 ) ;
if ( V_60 )
V_60 -> V_2 . V_145 = V_146 ;
F_20 (i) {
struct V_50 T_11 * * V_147 ;
V_147 = F_21 ( V_131 -> V_148 , V_29 ) ;
V_60 = F_64 ( * V_147 ) ;
if ( V_60 )
V_60 -> V_2 . V_145 = V_146 ;
}
}
V_113 -> V_120 = V_77 ;
V_139:
F_83 ( & V_135 ) ;
}
static void F_84 ( struct V_50 * V_60 , struct V_55 * V_56 , struct V_86 * V_87 ,
bool V_149 )
{
T_6 V_150 = F_85 ( V_56 ) -> V_151 . V_152 ;
T_6 V_153 = F_39 ( V_56 ) -> V_84 ;
struct V_58 * V_53 = V_56 -> V_53 ;
struct V_154 * V_155 ;
struct V_156 V_157 ;
struct V_54 * V_61 ;
struct V_37 * V_37 ;
switch ( F_85 ( V_56 ) -> V_158 & 7 ) {
case V_159 :
case V_160 :
case V_161 :
case V_162 :
break;
default:
return;
}
if ( V_60 -> V_62 != V_153 )
return;
V_155 = F_86 ( V_53 ) ;
if ( ! V_155 )
return;
V_37 = F_35 ( V_53 ) ;
if ( V_150 == V_153 || ! F_87 ( V_155 ) ||
F_88 ( V_150 ) || F_89 ( V_150 ) ||
F_90 ( V_150 ) )
goto V_163;
if ( ! F_91 ( V_155 ) ) {
if ( ! F_92 ( V_155 , V_150 , V_153 ) )
goto V_163;
if ( F_93 ( V_155 ) && F_94 ( V_150 , V_53 ) )
goto V_163;
} else {
if ( F_95 ( V_37 , V_150 ) != V_164 )
goto V_163;
}
V_61 = F_40 ( V_60 -> V_2 . V_53 , V_150 ) ;
if ( ! V_61 )
V_61 = F_41 ( & V_64 , & V_150 , V_60 -> V_2 . V_53 ) ;
if ( ! F_96 ( V_61 ) ) {
if ( ! ( V_61 -> V_165 & V_166 ) ) {
F_97 ( V_61 , NULL ) ;
} else {
if ( F_98 ( V_37 , V_87 , & V_157 , 0 ) == 0 ) {
struct V_130 * V_131 = & F_99 ( V_157 ) ;
F_78 ( V_131 , V_87 -> V_57 , V_150 ,
0 , V_77 + V_167 ) ;
}
if ( V_149 )
V_60 -> V_2 . V_145 = V_146 ;
F_100 ( V_168 , V_61 ) ;
}
F_101 ( V_61 ) ;
}
return;
V_163:
#ifdef F_102
if ( F_103 ( V_155 ) ) {
const struct V_80 * V_81 = ( const struct V_80 * ) V_56 -> V_169 ;
T_6 V_57 = V_81 -> V_57 ;
T_6 V_84 = V_81 -> V_84 ;
F_104 ( L_10
L_11 ,
& V_153 , V_53 -> V_170 , & V_150 ,
& V_84 , & V_57 ) ;
}
#endif
;
}
static void F_105 ( struct V_1 * V_2 , struct V_88 * V_89 , struct V_55 * V_56 )
{
struct V_50 * V_60 ;
struct V_86 V_87 ;
const struct V_80 * V_81 = ( const struct V_80 * ) V_56 -> V_169 ;
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
struct V_1 * V_171 = V_2 ;
if ( V_60 ) {
if ( V_2 -> V_145 > 0 ) {
F_107 ( V_60 ) ;
V_171 = NULL ;
} else if ( ( V_60 -> V_65 & V_128 ) ||
V_60 -> V_2 . V_125 ) {
F_107 ( V_60 ) ;
V_171 = NULL ;
}
}
return V_171 ;
}
void F_108 ( struct V_55 * V_56 )
{
struct V_50 * V_60 = F_109 ( V_56 ) ;
struct V_154 * V_155 ;
struct V_172 * V_173 ;
struct V_37 * V_37 ;
int V_174 ;
int V_175 ;
F_63 () ;
V_155 = F_86 ( V_60 -> V_2 . V_53 ) ;
if ( ! V_155 || ! F_110 ( V_155 ) ) {
F_66 () ;
return;
}
V_174 = F_103 ( V_155 ) ;
V_175 = F_111 ( V_60 -> V_2 . V_53 ) ;
F_66 () ;
V_37 = F_35 ( V_60 -> V_2 . V_53 ) ;
V_173 = F_112 ( V_37 -> V_176 . V_177 , F_39 ( V_56 ) -> V_84 , V_175 , 1 ) ;
if ( ! V_173 ) {
F_113 ( V_56 , V_178 , V_161 ,
F_114 ( V_60 , F_39 ( V_56 ) -> V_57 ) ) ;
return;
}
if ( F_115 ( V_77 , V_173 -> V_179 + V_180 ) )
V_173 -> V_181 = 0 ;
if ( V_173 -> V_181 >= V_182 ) {
V_173 -> V_179 = V_77 ;
goto V_183;
}
if ( V_173 -> V_181 == 0 ||
F_115 ( V_77 ,
( V_173 -> V_179 +
( V_184 << V_173 -> V_181 ) ) ) ) {
T_6 V_132 = F_114 ( V_60 , F_39 ( V_56 ) -> V_57 ) ;
F_113 ( V_56 , V_178 , V_161 , V_132 ) ;
V_173 -> V_179 = V_77 ;
++ V_173 -> V_181 ;
#ifdef F_102
if ( V_174 &&
V_173 -> V_181 == V_182 )
F_116 ( L_12 ,
& F_39 ( V_56 ) -> V_84 , F_117 ( V_56 ) ,
& F_39 ( V_56 ) -> V_57 , & V_132 ) ;
#endif
}
V_183:
F_118 ( V_173 ) ;
}
static int F_119 ( struct V_55 * V_56 )
{
struct V_154 * V_155 = F_86 ( V_56 -> V_53 ) ;
struct V_50 * V_60 = F_109 ( V_56 ) ;
struct V_172 * V_173 ;
unsigned long V_76 ;
struct V_37 * V_37 ;
bool V_185 ;
int V_158 ;
if ( ! V_155 )
goto V_186;
V_37 = F_35 ( V_60 -> V_2 . V_53 ) ;
if ( ! F_120 ( V_155 ) ) {
switch ( V_60 -> V_2 . error ) {
case V_187 :
F_121 ( V_37 , V_188 ) ;
break;
case V_189 :
F_121 ( V_37 , V_190 ) ;
break;
}
goto V_186;
}
switch ( V_60 -> V_2 . error ) {
case V_191 :
default:
goto V_186;
case V_187 :
V_158 = V_192 ;
break;
case V_189 :
V_158 = V_193 ;
F_121 ( V_37 , V_190 ) ;
break;
case V_194 :
V_158 = V_195 ;
break;
}
V_173 = F_112 ( V_37 -> V_176 . V_177 , F_39 ( V_56 ) -> V_84 ,
F_122 ( V_56 -> V_53 ) , 1 ) ;
V_185 = true ;
if ( V_173 ) {
V_76 = V_77 ;
V_173 -> V_181 += V_76 - V_173 -> V_179 ;
if ( V_173 -> V_181 > V_196 )
V_173 -> V_181 = V_196 ;
V_173 -> V_179 = V_76 ;
if ( V_173 -> V_181 >= V_197 )
V_173 -> V_181 -= V_197 ;
else
V_185 = false ;
F_118 ( V_173 ) ;
}
if ( V_185 )
F_113 ( V_56 , V_198 , V_158 , 0 ) ;
V_186: F_123 ( V_56 ) ;
return 0 ;
}
static void F_124 ( struct V_50 * V_60 , struct V_86 * V_87 , T_1 V_199 )
{
struct V_1 * V_2 = & V_60 -> V_2 ;
struct V_156 V_157 ;
if ( F_125 ( V_2 , V_200 ) )
return;
if ( F_126 ( V_2 ) < V_199 )
return;
if ( V_199 < V_201 )
V_199 = V_201 ;
if ( V_60 -> V_123 == V_199 &&
F_73 ( V_77 , V_2 -> V_125 - V_202 / 2 ) )
return;
F_63 () ;
if ( F_98 ( F_35 ( V_2 -> V_53 ) , V_87 , & V_157 , 0 ) == 0 ) {
struct V_130 * V_131 = & F_99 ( V_157 ) ;
F_78 ( V_131 , V_87 -> V_57 , 0 , V_199 ,
V_77 + V_202 ) ;
}
F_66 () ;
}
static void F_127 ( struct V_1 * V_2 , struct V_88 * V_89 ,
struct V_55 * V_56 , T_1 V_199 )
{
struct V_50 * V_60 = (struct V_50 * ) V_2 ;
struct V_86 V_87 ;
F_67 ( & V_87 , V_89 , V_56 ) ;
F_124 ( V_60 , & V_87 , V_199 ) ;
}
void F_128 ( struct V_55 * V_56 , struct V_37 * V_37 , T_1 V_199 ,
int V_90 , T_1 V_93 , T_9 V_85 , int V_94 )
{
const struct V_80 * V_81 = ( const struct V_80 * ) V_56 -> V_169 ;
struct V_86 V_87 ;
struct V_50 * V_60 ;
if ( ! V_93 )
V_93 = F_129 ( V_37 , V_56 -> V_93 ) ;
F_55 ( V_37 , & V_87 , NULL , V_81 , V_90 ,
F_61 ( V_81 -> V_91 ) , V_85 , V_93 , V_94 ) ;
V_60 = F_130 ( V_37 , & V_87 ) ;
if ( ! F_96 ( V_60 ) ) {
F_124 ( V_60 , & V_87 , V_199 ) ;
F_107 ( V_60 ) ;
}
}
static void F_131 ( struct V_55 * V_56 , struct V_88 * V_89 , T_1 V_199 )
{
const struct V_80 * V_81 = ( const struct V_80 * ) V_56 -> V_169 ;
struct V_86 V_87 ;
struct V_50 * V_60 ;
F_55 ( F_132 ( V_89 ) , & V_87 , V_89 , V_81 , 0 , 0 , 0 , 0 , 0 ) ;
if ( ! V_87 . V_203 )
V_87 . V_203 = F_129 ( F_132 ( V_89 ) , V_56 -> V_93 ) ;
V_60 = F_130 ( F_132 ( V_89 ) , & V_87 ) ;
if ( ! F_96 ( V_60 ) ) {
F_124 ( V_60 , & V_87 , V_199 ) ;
F_107 ( V_60 ) ;
}
}
void F_133 ( struct V_55 * V_56 , struct V_88 * V_89 , T_1 V_199 )
{
const struct V_80 * V_81 = ( const struct V_80 * ) V_56 -> V_169 ;
struct V_86 V_87 ;
struct V_50 * V_60 ;
struct V_1 * V_204 = NULL ;
bool V_78 = false ;
struct V_37 * V_37 = F_132 ( V_89 ) ;
F_134 ( V_89 ) ;
if ( ! F_135 ( V_89 ) )
goto V_186;
V_204 = F_136 ( V_89 ) ;
if ( F_137 ( V_89 ) || ! V_204 ) {
F_131 ( V_56 , V_89 , V_199 ) ;
goto V_186;
}
F_55 ( V_37 , & V_87 , V_89 , V_81 , 0 , 0 , 0 , 0 , 0 ) ;
V_60 = (struct V_50 * ) V_204 ;
if ( V_204 -> V_145 && ! V_204 -> V_205 -> V_206 ( V_204 , 0 ) ) {
V_60 = F_138 ( F_132 ( V_89 ) , & V_87 , V_89 ) ;
if ( F_96 ( V_60 ) )
goto V_186;
V_78 = true ;
}
F_124 ( (struct V_50 * ) V_60 -> V_2 . V_207 , & V_87 , V_199 ) ;
if ( ! F_139 ( & V_60 -> V_2 , 0 ) ) {
if ( V_78 )
F_71 ( & V_60 -> V_2 ) ;
V_60 = F_138 ( F_132 ( V_89 ) , & V_87 , V_89 ) ;
if ( F_96 ( V_60 ) )
goto V_186;
V_78 = true ;
}
if ( V_78 )
F_140 ( V_89 , & V_60 -> V_2 ) ;
V_186:
F_141 ( V_89 ) ;
F_71 ( V_204 ) ;
}
void F_142 ( struct V_55 * V_56 , struct V_37 * V_37 ,
int V_90 , T_1 V_93 , T_9 V_85 , int V_94 )
{
const struct V_80 * V_81 = ( const struct V_80 * ) V_56 -> V_169 ;
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
void F_143 ( struct V_55 * V_56 , struct V_88 * V_89 )
{
const struct V_80 * V_81 = ( const struct V_80 * ) V_56 -> V_169 ;
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
static struct V_1 * F_144 ( struct V_1 * V_2 , T_1 V_208 )
{
struct V_50 * V_60 = (struct V_50 * ) V_2 ;
if ( V_2 -> V_145 != V_209 || F_33 ( V_60 ) )
return NULL ;
return V_2 ;
}
static void F_145 ( struct V_55 * V_56 )
{
struct V_50 * V_60 ;
F_113 ( V_56 , V_198 , V_192 , 0 ) ;
V_60 = F_109 ( V_56 ) ;
if ( V_60 )
F_146 ( & V_60 -> V_2 , 0 ) ;
}
static int F_147 ( struct V_37 * V_37 , struct V_88 * V_89 , struct V_55 * V_56 )
{
F_148 ( L_13 ,
V_210 , & F_39 ( V_56 ) -> V_84 , & F_39 ( V_56 ) -> V_57 ,
V_56 -> V_53 ? V_56 -> V_53 -> V_170 : L_14 ) ;
F_123 ( V_56 ) ;
F_2 ( 1 ) ;
return 0 ;
}
void F_149 ( T_9 * V_211 , struct V_55 * V_56 , struct V_50 * V_60 )
{
T_6 V_28 ;
if ( F_150 ( V_60 ) )
V_28 = F_39 ( V_56 ) -> V_84 ;
else {
struct V_156 V_157 ;
struct V_86 V_87 ;
struct V_80 * V_81 ;
V_81 = F_39 ( V_56 ) ;
memset ( & V_87 , 0 , sizeof( V_87 ) ) ;
V_87 . V_57 = V_81 -> V_57 ;
V_87 . V_84 = V_81 -> V_84 ;
V_87 . V_212 = F_61 ( V_81 -> V_91 ) ;
V_87 . V_213 = V_60 -> V_2 . V_53 -> V_103 ;
V_87 . V_214 = V_56 -> V_53 -> V_103 ;
V_87 . V_203 = V_56 -> V_93 ;
F_63 () ;
if ( F_98 ( F_35 ( V_60 -> V_2 . V_53 ) , & V_87 , & V_157 , 0 ) == 0 )
V_28 = F_151 ( F_35 ( V_60 -> V_2 . V_53 ) , V_157 ) ;
else
V_28 = F_152 ( V_60 -> V_2 . V_53 ,
F_114 ( V_60 , V_81 -> V_57 ) ,
V_102 ) ;
F_66 () ;
}
memcpy ( V_211 , & V_28 , 4 ) ;
}
static void F_153 ( struct V_50 * V_60 , T_1 V_215 )
{
if ( ! ( V_60 -> V_2 . V_216 & 0xFFFF ) )
V_60 -> V_2 . V_216 |= V_215 & 0xFFFF ;
if ( ! ( V_60 -> V_2 . V_216 & 0xFFFF0000 ) )
V_60 -> V_2 . V_216 |= V_215 & 0xFFFF0000 ;
}
static unsigned int F_154 ( const struct V_1 * V_2 )
{
unsigned int V_217 = sizeof( struct V_218 ) + sizeof( struct V_80 ) ;
unsigned int V_219 = F_155 (unsigned int, dst->dev->mtu - header_size,
ip_rt_min_advmss) ;
return F_156 ( V_219 , V_220 - V_217 ) ;
}
static unsigned int F_126 ( const struct V_1 * V_2 )
{
const struct V_50 * V_60 = ( const struct V_50 * ) V_2 ;
unsigned int V_199 = V_60 -> V_123 ;
if ( ! V_199 || F_157 ( V_77 , V_60 -> V_2 . V_125 ) )
V_199 = F_158 ( V_2 , V_200 ) ;
if ( V_199 )
return V_199 ;
V_199 = F_159 ( V_2 -> V_53 -> V_199 ) ;
if ( F_160 ( F_125 ( V_2 , V_200 ) ) ) {
if ( V_60 -> V_129 && V_199 > 576 )
V_199 = 576 ;
}
V_199 = F_161 (unsigned int, mtu, IP_MAX_MTU) ;
return V_199 - F_162 ( V_2 -> V_221 , V_199 ) ;
}
static struct V_112 * F_163 ( struct V_130 * V_131 , T_6 V_57 )
{
struct V_116 * V_69 = F_64 ( V_131 -> V_136 ) ;
struct V_112 * V_113 ;
T_1 V_121 ;
if ( ! V_69 )
return NULL ;
V_121 = F_74 ( V_57 ) ;
for ( V_113 = F_64 ( V_69 [ V_121 ] . V_118 ) ; V_113 ;
V_113 = F_64 ( V_113 -> V_119 ) ) {
if ( V_113 -> V_140 == V_57 )
return V_113 ;
}
return NULL ;
}
static bool F_164 ( struct V_50 * V_60 , struct V_112 * V_113 ,
T_6 V_57 , const bool V_222 )
{
bool V_171 = false ;
F_79 ( & V_135 ) ;
if ( V_57 == V_113 -> V_140 ) {
struct V_50 T_11 * * V_223 ;
struct V_50 * V_224 ;
int V_225 = V_142 ( F_35 ( V_60 -> V_2 . V_53 ) ) ;
if ( F_165 ( V_60 ) )
V_223 = & V_113 -> V_114 ;
else
V_223 = & V_113 -> V_115 ;
V_224 = F_64 ( * V_223 ) ;
if ( V_113 -> V_142 != V_225 ) {
V_113 -> V_142 = V_225 ;
V_113 -> V_127 = 0 ;
V_113 -> V_124 = 0 ;
V_113 -> V_126 = 0 ;
F_68 ( V_113 ) ;
V_224 = NULL ;
}
F_77 ( V_60 , V_113 ) ;
if ( ! V_60 -> V_62 )
V_60 -> V_62 = V_57 ;
if ( V_222 ) {
F_166 ( & V_60 -> V_2 ) ;
F_81 ( * V_223 , V_60 ) ;
if ( V_224 ) {
F_70 ( & V_224 -> V_2 ) ;
F_71 ( & V_224 -> V_2 ) ;
}
V_171 = true ;
}
V_113 -> V_120 = V_77 ;
}
F_83 ( & V_135 ) ;
return V_171 ;
}
static bool F_167 ( struct V_130 * V_131 , struct V_50 * V_60 )
{
struct V_50 * V_224 , * V_226 , * * V_227 ;
bool V_171 = true ;
if ( F_165 ( V_60 ) ) {
V_227 = (struct V_50 * * ) & V_131 -> V_144 ;
} else {
V_227 = (struct V_50 * * ) F_168 ( V_131 -> V_148 ) ;
}
V_224 = * V_227 ;
F_166 ( & V_60 -> V_2 ) ;
V_226 = F_46 ( V_227 , V_224 , V_60 ) ;
if ( V_226 == V_224 ) {
if ( V_224 ) {
F_70 ( & V_224 -> V_2 ) ;
F_71 ( & V_224 -> V_2 ) ;
}
} else {
F_71 ( & V_60 -> V_2 ) ;
V_171 = false ;
}
return V_171 ;
}
static void F_169 ( struct V_50 * V_60 )
{
struct V_228 * V_229 = F_168 ( & V_230 ) ;
V_60 -> V_230 = V_229 ;
F_79 ( & V_229 -> V_231 ) ;
F_170 ( & V_60 -> V_232 , & V_229 -> V_233 ) ;
F_83 ( & V_229 -> V_231 ) ;
}
static void F_171 ( struct V_1 * V_2 )
{
struct V_234 * V_227 = (struct V_234 * ) F_172 ( V_2 ) ;
struct V_50 * V_60 = (struct V_50 * ) V_2 ;
if ( V_227 != & V_235 && F_173 ( & V_227 -> V_236 ) )
F_23 ( V_227 ) ;
if ( ! F_174 ( & V_60 -> V_232 ) ) {
struct V_228 * V_229 = V_60 -> V_230 ;
F_79 ( & V_229 -> V_231 ) ;
F_175 ( & V_60 -> V_232 ) ;
F_83 ( & V_229 -> V_231 ) ;
}
}
void F_176 ( struct V_58 * V_53 )
{
struct V_37 * V_37 = F_35 ( V_53 ) ;
struct V_50 * V_60 ;
int V_12 ;
F_20 (cpu) {
struct V_228 * V_229 = & F_12 ( V_230 , V_12 ) ;
F_79 ( & V_229 -> V_231 ) ;
F_177 (rt, &ul->head, rt_uncached) {
if ( V_60 -> V_2 . V_53 != V_53 )
continue;
V_60 -> V_2 . V_53 = V_37 -> V_237 ;
F_178 ( V_60 -> V_2 . V_53 ) ;
F_179 ( V_53 ) ;
}
F_83 ( & V_229 -> V_231 ) ;
}
}
static bool F_180 ( const struct V_50 * V_60 )
{
return V_60 &&
V_60 -> V_2 . V_145 == V_209 &&
! F_33 ( V_60 ) ;
}
static void F_181 ( struct V_50 * V_60 , T_6 V_57 ,
const struct V_156 * V_157 ,
struct V_112 * V_113 ,
struct V_238 * V_239 , T_12 type , T_1 V_240 ,
const bool V_222 )
{
bool V_241 = false ;
if ( V_239 ) {
struct V_130 * V_131 = & F_99 ( * V_157 ) ;
if ( V_131 -> V_242 && V_131 -> V_243 == V_244 ) {
V_60 -> V_62 = V_131 -> V_242 ;
V_60 -> V_129 = 1 ;
}
F_182 ( & V_60 -> V_2 , V_239 -> V_245 -> V_246 , true ) ;
if ( V_239 -> V_245 != & V_235 ) {
V_60 -> V_2 . V_247 |= V_248 ;
F_183 ( & V_239 -> V_245 -> V_236 ) ;
}
#ifdef F_28
V_60 -> V_2 . V_216 = V_131 -> V_249 ;
#endif
V_60 -> V_2 . V_221 = F_184 ( V_131 -> V_250 ) ;
if ( F_160 ( V_113 ) )
V_241 = F_164 ( V_60 , V_113 , V_57 , V_222 ) ;
else if ( V_222 )
V_241 = F_167 ( V_131 , V_60 ) ;
if ( F_160 ( ! V_241 ) ) {
if ( ! V_60 -> V_62 )
V_60 -> V_62 = V_57 ;
F_169 ( V_60 ) ;
}
} else
F_169 ( V_60 ) ;
#ifdef F_28
#ifdef F_185
F_153 ( V_60 , V_157 -> V_216 ) ;
#endif
F_153 ( V_60 , V_240 ) ;
#endif
}
struct V_50 * F_186 ( struct V_58 * V_53 ,
unsigned int V_251 , T_12 type ,
bool V_252 , bool V_253 , bool V_254 )
{
struct V_50 * V_60 ;
V_60 = F_187 ( & V_16 , V_53 , 1 , V_209 ,
( V_254 ? 0 : V_255 ) |
( V_252 ? V_256 : 0 ) |
( V_253 ? V_257 : 0 ) ) ;
if ( V_60 ) {
V_60 -> V_52 = F_34 ( F_35 ( V_53 ) ) ;
V_60 -> V_65 = V_251 ;
V_60 -> V_258 = type ;
V_60 -> V_259 = 0 ;
V_60 -> V_260 = 0 ;
V_60 -> V_123 = 0 ;
V_60 -> V_62 = 0 ;
V_60 -> V_129 = 0 ;
V_60 -> V_261 = 0 ;
F_188 ( & V_60 -> V_232 ) ;
V_60 -> V_2 . V_262 = V_263 ;
if ( V_251 & V_68 )
V_60 -> V_2 . V_264 = V_265 ;
}
return V_60 ;
}
static int F_189 ( struct V_55 * V_56 , T_6 V_57 , T_6 V_84 ,
T_9 V_91 , struct V_58 * V_53 , int V_266 )
{
struct V_50 * V_51 ;
struct V_154 * V_155 = F_86 ( V_53 ) ;
unsigned int V_251 = V_66 ;
T_1 V_240 = 0 ;
int V_267 ;
if ( ! V_155 )
return - V_191 ;
if ( F_88 ( V_84 ) || F_89 ( V_84 ) ||
V_56 -> V_85 != F_54 ( V_268 ) )
goto V_269;
if ( F_190 ( V_84 ) && ! F_191 ( V_155 ) )
goto V_269;
if ( F_90 ( V_84 ) ) {
if ( ! F_192 ( V_57 ) )
goto V_269;
} else {
V_267 = F_193 ( V_56 , V_84 , 0 , V_91 , 0 , V_53 ,
V_155 , & V_240 ) ;
if ( V_267 < 0 )
goto V_270;
}
if ( V_266 )
V_251 |= V_68 ;
V_51 = F_186 ( F_35 ( V_53 ) -> V_237 , V_251 , V_271 ,
F_194 ( V_155 , V_272 ) , false , false ) ;
if ( ! V_51 )
goto V_273;
#ifdef F_28
V_51 -> V_2 . V_216 = V_240 ;
#endif
V_51 -> V_2 . V_262 = F_147 ;
V_51 -> V_259 = 1 ;
#ifdef F_195
if ( ! F_192 ( V_57 ) && F_196 ( V_155 ) )
V_51 -> V_2 . V_264 = V_274 ;
#endif
F_197 ( V_18 ) ;
F_198 ( V_56 , & V_51 -> V_2 ) ;
return 0 ;
V_273:
return - V_275 ;
V_269:
return - V_191 ;
V_270:
return V_267 ;
}
static void F_199 ( struct V_58 * V_53 ,
struct V_154 * V_155 ,
struct V_55 * V_56 ,
T_6 V_57 ,
T_6 V_84 )
{
F_197 ( V_22 ) ;
#ifdef F_102
if ( F_103 ( V_155 ) && F_200 () ) {
F_201 ( L_15 ,
& V_57 , & V_84 , V_53 -> V_170 ) ;
if ( V_53 -> V_276 && F_202 ( V_56 ) ) {
F_203 ( V_277 , L_16 ,
V_278 , 16 , 1 ,
F_204 ( V_56 ) ,
V_53 -> V_276 , true ) ;
}
}
#endif
}
static void F_205 ( struct V_130 * V_131 , T_6 V_57 )
{
struct V_116 * V_69 ;
struct V_112 * V_113 , T_11 * * V_279 ;
T_1 V_121 = F_74 ( V_57 ) ;
F_79 ( & V_135 ) ;
V_69 = F_206 ( V_131 -> V_136 ,
F_207 ( & V_135 ) ) ;
V_69 += V_121 ;
V_279 = & V_69 -> V_118 ;
V_113 = F_206 ( * V_279 , F_207 ( & V_135 ) ) ;
while ( V_113 ) {
if ( V_113 -> V_140 == V_57 ) {
F_81 ( * V_279 , F_206 (
V_113 -> V_119 , F_207 ( & V_135 ) ) ) ;
F_68 ( V_113 ) ;
F_208 ( V_113 , V_280 ) ;
break;
}
V_279 = & V_113 -> V_119 ;
V_113 = F_206 ( V_113 -> V_119 ,
F_207 ( & V_135 ) ) ;
}
F_83 ( & V_135 ) ;
}
static void F_209 ( struct V_50 * V_51 )
{
if ( F_210 ( V_51 -> V_2 . V_221 ) ) {
V_51 -> V_2 . V_221 -> V_281 = V_51 -> V_2 . V_262 ;
V_51 -> V_2 . V_262 = V_282 ;
}
if ( F_211 ( V_51 -> V_2 . V_221 ) ) {
V_51 -> V_2 . V_221 -> V_283 = V_51 -> V_2 . V_264 ;
V_51 -> V_2 . V_264 = V_284 ;
}
}
static int F_212 ( struct V_55 * V_56 ,
const struct V_156 * V_157 ,
struct V_154 * V_155 ,
T_6 V_57 , T_6 V_84 , T_1 V_91 )
{
struct V_112 * V_113 ;
struct V_50 * V_51 ;
int V_267 ;
struct V_154 * V_285 ;
bool V_222 ;
T_1 V_240 = 0 ;
V_285 = F_86 ( F_213 ( * V_157 ) ) ;
if ( ! V_285 ) {
F_214 ( L_17 ) ;
return - V_191 ;
}
V_267 = F_193 ( V_56 , V_84 , V_57 , V_91 , F_215 ( * V_157 ) ,
V_155 -> V_53 , V_155 , & V_240 ) ;
if ( V_267 < 0 ) {
F_199 ( V_155 -> V_53 , V_155 , V_56 , V_57 ,
V_84 ) ;
goto V_286;
}
V_222 = V_157 -> V_239 && ! V_240 ;
if ( V_285 == V_155 && V_267 && F_110 ( V_285 ) &&
V_56 -> V_85 == F_54 ( V_268 ) &&
( F_91 ( V_285 ) ||
F_92 ( V_285 , V_84 , F_216 ( * V_157 ) ) ) )
F_217 ( V_56 ) -> V_251 |= V_287 ;
if ( V_56 -> V_85 != F_54 ( V_268 ) ) {
if ( V_285 == V_155 &&
F_218 ( V_155 ) == 0 ) {
V_267 = - V_191 ;
goto V_286;
}
}
V_113 = F_163 ( & F_99 ( * V_157 ) , V_57 ) ;
if ( V_222 ) {
if ( V_113 ) {
V_51 = F_64 ( V_113 -> V_114 ) ;
if ( V_51 && V_51 -> V_2 . V_125 &&
F_115 ( V_77 , V_51 -> V_2 . V_125 ) ) {
F_205 ( & F_99 ( * V_157 ) , V_57 ) ;
V_113 = NULL ;
} else {
goto V_288;
}
}
V_51 = F_64 ( F_99 ( * V_157 ) . V_144 ) ;
V_288:
if ( F_180 ( V_51 ) ) {
F_219 ( V_56 , & V_51 -> V_2 ) ;
goto V_186;
}
}
V_51 = F_186 ( V_285 -> V_53 , 0 , V_157 -> type ,
F_194 ( V_155 , V_272 ) ,
F_194 ( V_285 , V_289 ) , V_222 ) ;
if ( ! V_51 ) {
V_267 = - V_275 ;
goto V_286;
}
V_51 -> V_259 = 1 ;
if ( V_157 -> V_290 )
V_51 -> V_261 = V_157 -> V_290 -> V_291 ;
F_197 ( V_17 ) ;
V_51 -> V_2 . V_264 = V_292 ;
F_181 ( V_51 , V_57 , V_157 , V_113 , V_157 -> V_239 , V_157 -> type , V_240 ,
V_222 ) ;
F_209 ( V_51 ) ;
F_198 ( V_56 , & V_51 -> V_2 ) ;
V_186:
V_267 = 0 ;
V_286:
return V_267 ;
}
static void F_220 ( const struct V_55 * V_56 ,
struct V_293 * V_294 )
{
const struct V_80 * V_295 = F_39 ( V_56 ) ;
const struct V_80 * V_296 ;
const struct V_297 * V_298 ;
struct V_80 V_299 ;
struct V_297 V_300 ;
V_294 -> V_301 . V_302 . V_28 = V_295 -> V_84 ;
V_294 -> V_301 . V_302 . V_2 = V_295 -> V_57 ;
if ( F_221 ( V_295 -> V_85 != V_303 ) )
return;
if ( F_160 ( ( V_295 -> V_304 & F_54 ( V_305 ) ) != 0 ) )
return;
V_298 = F_222 ( V_56 , V_295 -> V_306 * 4 , sizeof( V_300 ) ,
& V_300 ) ;
if ( ! V_298 )
return;
if ( V_298 -> type != V_198 &&
V_298 -> type != V_178 &&
V_298 -> type != V_307 &&
V_298 -> type != V_308 )
return;
V_296 = F_222 ( V_56 ,
V_295 -> V_306 * 4 + sizeof( V_300 ) ,
sizeof( V_299 ) , & V_299 ) ;
if ( ! V_296 )
return;
V_294 -> V_301 . V_302 . V_28 = V_296 -> V_84 ;
V_294 -> V_301 . V_302 . V_2 = V_296 -> V_57 ;
}
int F_223 ( const struct V_238 * V_239 , const struct V_86 * V_87 ,
const struct V_55 * V_56 )
{
struct V_37 * V_37 = V_239 -> V_309 ;
struct V_293 V_294 ;
T_1 V_310 ;
switch ( V_37 -> V_176 . V_311 ) {
case 0 :
memset ( & V_294 , 0 , sizeof( V_294 ) ) ;
V_294 . V_312 . V_313 = V_314 ;
if ( V_56 ) {
F_220 ( V_56 , & V_294 ) ;
} else {
V_294 . V_301 . V_302 . V_28 = V_87 -> V_84 ;
V_294 . V_301 . V_302 . V_2 = V_87 -> V_57 ;
}
break;
case 1 :
if ( V_56 ) {
unsigned int V_315 = V_316 ;
struct V_293 V_317 ;
if ( V_56 -> V_318 )
return F_224 ( V_56 ) >> 1 ;
memset ( & V_294 , 0 , sizeof( V_294 ) ) ;
F_225 ( V_56 , & V_317 , V_315 ) ;
V_294 . V_301 . V_302 . V_28 = V_317 . V_301 . V_302 . V_28 ;
V_294 . V_301 . V_302 . V_2 = V_317 . V_301 . V_302 . V_2 ;
V_294 . V_319 . V_28 = V_317 . V_319 . V_28 ;
V_294 . V_319 . V_2 = V_317 . V_319 . V_2 ;
V_294 . V_320 . V_321 = V_317 . V_320 . V_321 ;
} else {
memset ( & V_294 , 0 , sizeof( V_294 ) ) ;
V_294 . V_312 . V_313 = V_314 ;
V_294 . V_301 . V_302 . V_28 = V_87 -> V_84 ;
V_294 . V_301 . V_302 . V_2 = V_87 -> V_57 ;
V_294 . V_319 . V_28 = V_87 -> V_322 ;
V_294 . V_319 . V_2 = V_87 -> V_323 ;
V_294 . V_320 . V_321 = V_87 -> V_324 ;
}
break;
}
V_310 = F_226 ( & V_294 ) ;
return V_310 >> 1 ;
}
static int F_227 ( struct V_55 * V_56 ,
struct V_156 * V_157 ,
struct V_154 * V_155 ,
T_6 V_57 , T_6 V_84 , T_1 V_91 )
{
#ifdef F_228
if ( V_157 -> V_239 && V_157 -> V_239 -> V_325 > 1 ) {
int V_326 = F_223 ( V_157 -> V_239 , NULL , V_56 ) ;
F_229 ( V_157 , V_326 ) ;
}
#endif
return F_212 ( V_56 , V_157 , V_155 , V_57 , V_84 , V_91 ) ;
}
static int F_230 ( struct V_55 * V_56 , T_6 V_57 , T_6 V_84 ,
T_9 V_91 , struct V_58 * V_53 ,
struct V_156 * V_157 )
{
struct V_154 * V_155 = F_86 ( V_53 ) ;
struct V_327 * V_328 ;
struct V_86 V_87 ;
unsigned int V_251 = 0 ;
T_1 V_240 = 0 ;
struct V_50 * V_51 ;
int V_267 = - V_191 ;
struct V_37 * V_37 = F_35 ( V_53 ) ;
bool V_222 ;
if ( ! V_155 )
goto V_186;
V_328 = F_231 ( V_56 ) ;
if ( V_328 && ! ( V_328 -> V_329 & V_330 ) )
V_87 . V_331 . V_332 = V_328 -> V_333 . V_332 ;
else
V_87 . V_331 . V_332 = 0 ;
F_232 ( V_56 ) ;
if ( F_88 ( V_84 ) || F_89 ( V_84 ) )
goto V_334;
V_157 -> V_239 = NULL ;
V_157 -> V_290 = NULL ;
if ( F_89 ( V_57 ) || ( V_84 == 0 && V_57 == 0 ) )
goto V_335;
if ( F_90 ( V_84 ) )
goto V_334;
if ( F_90 ( V_57 ) )
goto V_336;
if ( F_190 ( V_57 ) ) {
if ( ! F_233 ( V_155 , V_37 ) )
goto V_336;
} else if ( F_190 ( V_84 ) ) {
if ( ! F_233 ( V_155 , V_37 ) )
goto V_334;
}
V_87 . V_213 = 0 ;
V_87 . V_214 = V_53 -> V_103 ;
V_87 . V_203 = V_56 -> V_93 ;
V_87 . V_212 = V_91 ;
V_87 . V_337 = V_102 ;
V_87 . V_338 = 0 ;
V_87 . V_57 = V_57 ;
V_87 . V_84 = V_84 ;
V_87 . V_339 = F_59 ( V_37 , NULL ) ;
V_267 = F_98 ( V_37 , & V_87 , V_157 , 0 ) ;
if ( V_267 != 0 ) {
if ( ! F_120 ( V_155 ) )
V_267 = - V_187 ;
goto V_340;
}
if ( V_157 -> type == V_341 )
goto V_335;
if ( V_157 -> type == V_342 ) {
V_267 = F_193 ( V_56 , V_84 , V_57 , V_91 ,
0 , V_53 , V_155 , & V_240 ) ;
if ( V_267 < 0 )
goto V_334;
goto V_343;
}
if ( ! F_120 ( V_155 ) ) {
V_267 = - V_187 ;
goto V_340;
}
if ( V_157 -> type != V_164 )
goto V_336;
V_267 = F_227 ( V_56 , V_157 , V_155 , V_57 , V_84 , V_91 ) ;
V_186: return V_267 ;
V_335:
if ( V_56 -> V_85 != F_54 ( V_268 ) )
goto V_269;
if ( ! F_90 ( V_84 ) ) {
V_267 = F_193 ( V_56 , V_84 , 0 , V_91 , 0 , V_53 ,
V_155 , & V_240 ) ;
if ( V_267 < 0 )
goto V_334;
}
V_251 |= V_67 ;
V_157 -> type = V_341 ;
F_197 ( V_20 ) ;
V_343:
V_222 = false ;
if ( V_157 -> V_239 ) {
if ( ! V_240 ) {
V_51 = F_64 ( F_99 ( * V_157 ) . V_144 ) ;
if ( F_180 ( V_51 ) ) {
F_219 ( V_56 , & V_51 -> V_2 ) ;
V_267 = 0 ;
goto V_186;
}
V_222 = true ;
}
}
V_51 = F_186 ( F_234 ( V_53 ) ? : V_37 -> V_237 ,
V_251 | V_68 , V_157 -> type ,
F_194 ( V_155 , V_272 ) , false , V_222 ) ;
if ( ! V_51 )
goto V_273;
V_51 -> V_2 . V_262 = F_147 ;
#ifdef F_28
V_51 -> V_2 . V_216 = V_240 ;
#endif
V_51 -> V_259 = 1 ;
if ( V_157 -> V_290 )
V_51 -> V_261 = V_157 -> V_290 -> V_291 ;
F_197 ( V_17 ) ;
if ( V_157 -> type == V_344 ) {
V_51 -> V_2 . V_264 = F_119 ;
V_51 -> V_2 . error = - V_267 ;
V_51 -> V_65 &= ~ V_68 ;
}
if ( V_222 ) {
struct V_130 * V_131 = & F_99 ( * V_157 ) ;
V_51 -> V_2 . V_221 = F_184 ( V_131 -> V_250 ) ;
if ( F_211 ( V_51 -> V_2 . V_221 ) ) {
F_2 ( V_51 -> V_2 . V_264 == V_284 ) ;
V_51 -> V_2 . V_221 -> V_283 = V_51 -> V_2 . V_264 ;
V_51 -> V_2 . V_264 = V_284 ;
}
if ( F_160 ( ! F_167 ( V_131 , V_51 ) ) )
F_169 ( V_51 ) ;
}
F_198 ( V_56 , & V_51 -> V_2 ) ;
V_267 = 0 ;
goto V_186;
V_340:
F_197 ( V_19 ) ;
V_157 -> type = V_344 ;
V_157 -> V_239 = NULL ;
V_157 -> V_290 = NULL ;
goto V_343;
V_336:
F_197 ( V_21 ) ;
#ifdef F_102
if ( F_103 ( V_155 ) )
F_116 ( L_18 ,
& V_57 , & V_84 , V_53 -> V_170 ) ;
#endif
V_269:
V_267 = - V_191 ;
goto V_186;
V_273:
V_267 = - V_275 ;
goto V_186;
V_334:
F_199 ( V_53 , V_155 , V_56 , V_57 , V_84 ) ;
goto V_186;
}
int F_235 ( struct V_55 * V_56 , T_6 V_57 , T_6 V_84 ,
T_9 V_91 , struct V_58 * V_53 )
{
struct V_156 V_157 ;
int V_267 ;
V_91 &= V_345 ;
F_63 () ;
V_267 = F_236 ( V_56 , V_57 , V_84 , V_91 , V_53 , & V_157 ) ;
F_66 () ;
return V_267 ;
}
int F_236 ( struct V_55 * V_56 , T_6 V_57 , T_6 V_84 ,
T_9 V_91 , struct V_58 * V_53 , struct V_156 * V_157 )
{
if ( F_88 ( V_57 ) ) {
struct V_154 * V_155 = F_86 ( V_53 ) ;
int V_266 = 0 ;
int V_267 = - V_191 ;
if ( V_155 )
V_266 = F_237 ( V_155 , V_57 , V_84 ,
F_39 ( V_56 ) -> V_85 ) ;
if ( ( ! V_155 || ! V_266 ) && F_238 ( V_53 ) ) {
struct V_154 * V_346 ;
V_346 = F_86 ( V_56 -> V_53 ) ;
if ( V_346 )
V_266 = F_237 ( V_346 , V_57 , V_84 ,
F_39 ( V_56 ) -> V_85 ) ;
}
if ( V_266
#ifdef F_195
||
( ! F_192 ( V_57 ) &&
F_196 ( V_155 ) )
#endif
) {
V_267 = F_189 ( V_56 , V_57 , V_84 ,
V_91 , V_53 , V_266 ) ;
}
return V_267 ;
}
return F_230 ( V_56 , V_57 , V_84 , V_91 , V_53 , V_157 ) ;
}
static struct V_50 * F_239 ( const struct V_156 * V_157 ,
const struct V_86 * V_87 , int V_347 ,
struct V_58 * V_348 ,
unsigned int V_251 )
{
struct V_238 * V_239 = V_157 -> V_239 ;
struct V_112 * V_113 ;
struct V_154 * V_155 ;
T_12 type = V_157 -> type ;
struct V_50 * V_51 ;
bool V_222 ;
V_155 = F_86 ( V_348 ) ;
if ( ! V_155 )
return F_240 ( - V_191 ) ;
if ( F_221 ( ! F_191 ( V_155 ) ) )
if ( F_190 ( V_87 -> V_84 ) &&
! ( V_348 -> V_251 & V_349 ) &&
! F_241 ( V_348 ) )
return F_240 ( - V_191 ) ;
if ( F_89 ( V_87 -> V_57 ) )
type = V_341 ;
else if ( F_88 ( V_87 -> V_57 ) )
type = V_271 ;
else if ( F_90 ( V_87 -> V_57 ) )
return F_240 ( - V_191 ) ;
if ( V_348 -> V_251 & V_349 )
V_251 |= V_68 ;
V_222 = true ;
if ( type == V_341 ) {
V_251 |= V_67 | V_68 ;
V_239 = NULL ;
} else if ( type == V_271 ) {
V_251 |= V_66 | V_68 ;
if ( ! F_237 ( V_155 , V_87 -> V_57 , V_87 -> V_84 ,
V_87 -> V_324 ) )
V_251 &= ~ V_68 ;
else
V_222 = false ;
if ( V_239 && V_157 -> V_350 < 4 )
V_239 = NULL ;
} else if ( ( type == V_342 ) && ( V_347 != 0 ) &&
( V_347 != V_348 -> V_103 ) ) {
V_239 = NULL ;
}
V_113 = NULL ;
V_222 &= V_239 != NULL ;
if ( V_222 ) {
struct V_50 T_11 * * V_351 ;
struct V_130 * V_131 = & F_99 ( * V_157 ) ;
V_113 = F_163 ( V_131 , V_87 -> V_57 ) ;
if ( V_113 ) {
V_351 = & V_113 -> V_115 ;
V_51 = F_64 ( * V_351 ) ;
if ( V_51 && V_51 -> V_2 . V_125 &&
F_115 ( V_77 , V_51 -> V_2 . V_125 ) ) {
F_205 ( V_131 , V_87 -> V_57 ) ;
V_113 = NULL ;
} else {
goto V_288;
}
}
if ( F_160 ( V_87 -> V_338 &
V_352 &&
! ( V_131 -> V_242 &&
V_131 -> V_243 == V_244 ) ) ) {
V_222 = false ;
goto V_353;
}
V_351 = F_168 ( V_131 -> V_148 ) ;
V_51 = F_64 ( * V_351 ) ;
V_288:
if ( F_180 ( V_51 ) && F_242 ( & V_51 -> V_2 ) )
return V_51 ;
}
V_353:
V_51 = F_186 ( V_348 , V_251 , type ,
F_194 ( V_155 , V_272 ) ,
F_194 ( V_155 , V_289 ) ,
V_222 ) ;
if ( ! V_51 )
return F_240 ( - V_275 ) ;
V_51 -> V_260 = V_347 ? : 0 ;
if ( V_157 -> V_290 )
V_51 -> V_261 = V_157 -> V_290 -> V_291 ;
F_197 ( V_23 ) ;
if ( V_251 & ( V_67 | V_66 ) ) {
if ( V_251 & V_68 &&
! ( V_348 -> V_251 & V_349 ) ) {
V_51 -> V_2 . V_262 = V_354 ;
F_197 ( V_24 ) ;
}
#ifdef F_195
if ( type == V_271 ) {
if ( F_196 ( V_155 ) &&
! F_192 ( V_87 -> V_57 ) ) {
V_51 -> V_2 . V_264 = V_274 ;
V_51 -> V_2 . V_262 = V_354 ;
}
}
#endif
}
F_181 ( V_51 , V_87 -> V_57 , V_157 , V_113 , V_239 , type , 0 , V_222 ) ;
F_209 ( V_51 ) ;
return V_51 ;
}
struct V_50 * F_243 ( struct V_37 * V_37 , struct V_86 * V_87 ,
const struct V_55 * V_56 )
{
T_13 V_91 = F_244 ( V_87 ) ;
struct V_156 V_157 ;
struct V_50 * V_51 ;
V_157 . V_216 = 0 ;
V_157 . V_239 = NULL ;
V_157 . V_290 = NULL ;
V_87 -> V_214 = V_355 ;
V_87 -> V_212 = V_91 & V_345 ;
V_87 -> V_337 = ( ( V_91 & V_356 ) ?
V_244 : V_102 ) ;
F_63 () ;
V_51 = F_245 ( V_37 , V_87 , & V_157 , V_56 ) ;
F_66 () ;
return V_51 ;
}
struct V_50 * F_245 ( struct V_37 * V_37 , struct V_86 * V_87 ,
struct V_156 * V_157 ,
const struct V_55 * V_56 )
{
struct V_58 * V_348 = NULL ;
int V_347 = V_87 -> V_213 ;
unsigned int V_251 = 0 ;
struct V_50 * V_51 ;
int V_267 = - V_189 ;
if ( V_87 -> V_84 ) {
V_51 = F_240 ( - V_191 ) ;
if ( F_88 ( V_87 -> V_84 ) ||
F_89 ( V_87 -> V_84 ) ||
F_90 ( V_87 -> V_84 ) )
goto V_186;
if ( V_87 -> V_213 == 0 &&
( F_88 ( V_87 -> V_57 ) ||
F_89 ( V_87 -> V_57 ) ) ) {
V_348 = F_246 ( V_37 , V_87 -> V_84 , false ) ;
if ( ! V_348 )
goto V_186;
V_87 -> V_213 = V_348 -> V_103 ;
goto V_357;
}
if ( ! ( V_87 -> V_338 & V_358 ) ) {
if ( ! F_246 ( V_37 , V_87 -> V_84 , false ) )
goto V_186;
}
}
if ( V_87 -> V_213 ) {
V_348 = F_247 ( V_37 , V_87 -> V_213 ) ;
V_51 = F_240 ( - V_359 ) ;
if ( ! V_348 )
goto V_186;
if ( ! ( V_348 -> V_251 & V_360 ) || ! F_86 ( V_348 ) ) {
V_51 = F_240 ( - V_189 ) ;
goto V_186;
}
if ( F_192 ( V_87 -> V_57 ) ||
F_89 ( V_87 -> V_57 ) ||
V_87 -> V_324 == V_361 ) {
if ( ! V_87 -> V_84 )
V_87 -> V_84 = F_152 ( V_348 , 0 ,
V_244 ) ;
goto V_357;
}
if ( ! V_87 -> V_84 ) {
if ( F_88 ( V_87 -> V_57 ) )
V_87 -> V_84 = F_152 ( V_348 , 0 ,
V_87 -> V_337 ) ;
else if ( ! V_87 -> V_57 )
V_87 -> V_84 = F_152 ( V_348 , 0 ,
V_362 ) ;
}
}
if ( ! V_87 -> V_57 ) {
V_87 -> V_57 = V_87 -> V_84 ;
if ( ! V_87 -> V_57 )
V_87 -> V_57 = V_87 -> V_84 = F_248 ( V_363 ) ;
V_348 = V_37 -> V_237 ;
V_87 -> V_213 = V_355 ;
V_157 -> type = V_342 ;
V_251 |= V_68 ;
goto V_357;
}
V_267 = F_98 ( V_37 , V_87 , V_157 , 0 ) ;
if ( V_267 ) {
V_157 -> V_239 = NULL ;
V_157 -> V_290 = NULL ;
if ( V_87 -> V_213 &&
( F_88 ( V_87 -> V_57 ) ||
! F_249 ( V_37 , V_87 -> V_213 ) ) ) {
if ( V_87 -> V_84 == 0 )
V_87 -> V_84 = F_152 ( V_348 , 0 ,
V_244 ) ;
V_157 -> type = V_164 ;
goto V_357;
}
V_51 = F_240 ( V_267 ) ;
goto V_186;
}
if ( V_157 -> type == V_342 ) {
if ( ! V_87 -> V_84 ) {
if ( V_157 -> V_239 -> V_364 )
V_87 -> V_84 = V_157 -> V_239 -> V_364 ;
else
V_87 -> V_84 = V_87 -> V_57 ;
}
V_348 = F_234 ( F_213 ( * V_157 ) ) ? :
V_37 -> V_237 ;
V_87 -> V_213 = V_348 -> V_103 ;
V_251 |= V_68 ;
goto V_357;
}
F_250 ( V_37 , V_157 , V_87 , V_56 ) ;
V_348 = F_213 ( * V_157 ) ;
V_87 -> V_213 = V_348 -> V_103 ;
V_357:
V_51 = F_239 ( V_157 , V_87 , V_347 , V_348 , V_251 ) ;
V_186:
return V_51 ;
}
static struct V_1 * F_251 ( struct V_1 * V_2 , T_1 V_208 )
{
return NULL ;
}
static unsigned int F_252 ( const struct V_1 * V_2 )
{
unsigned int V_199 = F_158 ( V_2 , V_200 ) ;
return V_199 ? : V_2 -> V_53 -> V_199 ;
}
static void F_253 ( struct V_1 * V_2 , struct V_88 * V_89 ,
struct V_55 * V_56 , T_1 V_199 )
{
}
static void F_254 ( struct V_1 * V_2 , struct V_88 * V_89 ,
struct V_55 * V_56 )
{
}
static T_1 * F_255 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
return NULL ;
}
struct V_1 * F_256 ( struct V_37 * V_37 , struct V_1 * V_365 )
{
struct V_50 * V_366 = (struct V_50 * ) V_365 ;
struct V_50 * V_60 ;
V_60 = F_187 ( & V_367 , NULL , 1 , V_368 , 0 ) ;
if ( V_60 ) {
struct V_1 * V_78 = & V_60 -> V_2 ;
V_78 -> V_369 = 1 ;
V_78 -> V_264 = V_370 ;
V_78 -> V_262 = V_371 ;
V_78 -> V_53 = V_37 -> V_237 ;
if ( V_78 -> V_53 )
F_178 ( V_78 -> V_53 ) ;
V_60 -> V_259 = V_366 -> V_259 ;
V_60 -> V_260 = V_366 -> V_260 ;
V_60 -> V_123 = V_366 -> V_123 ;
V_60 -> V_52 = F_34 ( V_37 ) ;
V_60 -> V_65 = V_366 -> V_65 ;
V_60 -> V_258 = V_366 -> V_258 ;
V_60 -> V_62 = V_366 -> V_62 ;
V_60 -> V_129 = V_366 -> V_129 ;
F_188 ( & V_60 -> V_232 ) ;
}
F_71 ( V_365 ) ;
return V_60 ? & V_60 -> V_2 : F_240 ( - V_32 ) ;
}
struct V_50 * F_138 ( struct V_37 * V_37 , struct V_86 * V_372 ,
const struct V_88 * V_89 )
{
struct V_50 * V_60 = F_130 ( V_37 , V_372 ) ;
if ( F_96 ( V_60 ) )
return V_60 ;
if ( V_372 -> V_324 )
V_60 = (struct V_50 * ) F_257 ( V_37 , & V_60 -> V_2 ,
F_258 ( V_372 ) ,
V_89 , 0 ) ;
return V_60 ;
}
static int F_259 ( struct V_37 * V_37 , T_6 V_2 , T_6 V_28 , T_1 V_373 ,
struct V_86 * V_87 , struct V_55 * V_56 , T_1 V_374 ,
T_1 V_5 )
{
struct V_50 * V_60 = F_109 ( V_56 ) ;
struct V_375 * V_376 ;
struct V_377 * V_378 ;
unsigned long V_125 = 0 ;
T_1 error ;
T_1 V_246 [ V_379 ] ;
V_378 = F_260 ( V_56 , V_374 , V_5 , V_380 , sizeof( * V_376 ) , 0 ) ;
if ( ! V_378 )
return - V_381 ;
V_376 = F_261 ( V_378 ) ;
V_376 -> V_382 = V_383 ;
V_376 -> V_384 = 32 ;
V_376 -> V_385 = 0 ;
V_376 -> V_386 = V_87 -> V_212 ;
V_376 -> V_387 = V_373 < 256 ? V_373 : V_388 ;
if ( F_262 ( V_56 , V_389 , V_373 ) )
goto V_390;
V_376 -> V_391 = V_60 -> V_258 ;
V_376 -> V_392 = V_102 ;
V_376 -> V_393 = V_394 ;
V_376 -> V_395 = ( V_60 -> V_65 & ~ 0xFFFF ) | V_396 ;
if ( V_60 -> V_65 & V_397 )
V_376 -> V_395 |= V_398 ;
if ( F_217 ( V_56 ) -> V_251 & V_287 )
V_376 -> V_395 |= V_399 ;
if ( F_263 ( V_56 , V_400 , V_2 ) )
goto V_390;
if ( V_28 ) {
V_376 -> V_385 = 32 ;
if ( F_263 ( V_56 , V_401 , V_28 ) )
goto V_390;
}
if ( V_60 -> V_2 . V_53 &&
F_262 ( V_56 , V_402 , V_60 -> V_2 . V_53 -> V_103 ) )
goto V_390;
#ifdef F_28
if ( V_60 -> V_2 . V_216 &&
F_262 ( V_56 , V_403 , V_60 -> V_2 . V_216 ) )
goto V_390;
#endif
if ( ! F_165 ( V_60 ) &&
V_87 -> V_84 != V_28 ) {
if ( F_263 ( V_56 , V_404 , V_87 -> V_84 ) )
goto V_390;
}
if ( V_60 -> V_129 &&
F_263 ( V_56 , V_405 , V_60 -> V_62 ) )
goto V_390;
V_125 = V_60 -> V_2 . V_125 ;
if ( V_125 ) {
unsigned long V_76 = V_77 ;
if ( F_73 ( V_76 , V_125 ) )
V_125 -= V_76 ;
else
V_125 = 0 ;
}
memcpy ( V_246 , F_264 ( & V_60 -> V_2 ) , sizeof( V_246 ) ) ;
if ( V_60 -> V_123 && V_125 )
V_246 [ V_200 - 1 ] = V_60 -> V_123 ;
if ( F_265 ( V_56 , V_246 ) < 0 )
goto V_390;
if ( V_87 -> V_203 &&
F_262 ( V_56 , V_406 , V_87 -> V_203 ) )
goto V_390;
if ( ! F_266 ( V_87 -> V_339 , V_407 ) &&
F_262 ( V_56 , V_408 ,
F_267 ( F_268 () , V_87 -> V_339 ) ) )
goto V_390;
error = V_60 -> V_2 . error ;
if ( F_165 ( V_60 ) ) {
#ifdef F_195
if ( F_88 ( V_2 ) && ! F_192 ( V_2 ) &&
F_269 ( V_37 , V_409 ) ) {
int V_267 = F_270 ( V_37 , V_56 ,
V_87 -> V_84 , V_87 -> V_57 ,
V_376 , V_374 ) ;
if ( V_267 <= 0 ) {
if ( V_267 == 0 )
return 0 ;
goto V_390;
}
} else
#endif
if ( F_262 ( V_56 , V_410 , V_56 -> V_53 -> V_103 ) )
goto V_390;
}
if ( F_271 ( V_56 , & V_60 -> V_2 , 0 , V_125 , error ) < 0 )
goto V_390;
F_272 ( V_56 , V_378 ) ;
return 0 ;
V_390:
F_273 ( V_56 , V_378 ) ;
return - V_381 ;
}
static int F_274 ( struct V_55 * V_411 , struct V_377 * V_378 ,
struct V_412 * V_413 )
{
struct V_37 * V_37 = F_132 ( V_411 -> V_89 ) ;
struct V_375 * V_414 ;
struct V_415 * V_416 [ V_417 + 1 ] ;
struct V_156 V_157 = {} ;
struct V_50 * V_60 = NULL ;
struct V_86 V_87 ;
T_6 V_2 = 0 ;
T_6 V_28 = 0 ;
T_1 V_418 ;
int V_267 ;
int V_93 ;
struct V_55 * V_56 ;
T_1 V_373 = V_419 ;
T_14 V_420 ;
V_267 = F_275 ( V_378 , sizeof( * V_414 ) , V_416 , V_417 , V_421 ,
V_413 ) ;
if ( V_267 < 0 )
goto V_422;
V_414 = F_261 ( V_378 ) ;
V_56 = F_276 ( V_423 , V_31 ) ;
if ( ! V_56 ) {
V_267 = - V_275 ;
goto V_422;
}
F_277 ( V_56 ) ;
F_278 ( V_56 ) ;
V_28 = V_416 [ V_401 ] ? F_279 ( V_416 [ V_401 ] ) : 0 ;
V_2 = V_416 [ V_400 ] ? F_279 ( V_416 [ V_400 ] ) : 0 ;
V_418 = V_416 [ V_410 ] ? F_280 ( V_416 [ V_410 ] ) : 0 ;
V_93 = V_416 [ V_406 ] ? F_280 ( V_416 [ V_406 ] ) : 0 ;
if ( V_416 [ V_408 ] )
V_420 = F_281 ( F_268 () , F_280 ( V_416 [ V_408 ] ) ) ;
else
V_420 = ( V_418 ? V_407 : F_282 () ) ;
F_39 ( V_56 ) -> V_85 = V_424 ;
F_39 ( V_56 ) -> V_84 = V_28 ;
F_39 ( V_56 ) -> V_57 = V_2 ;
F_283 ( V_56 , V_425 + sizeof( struct V_80 ) ) ;
memset ( & V_87 , 0 , sizeof( V_87 ) ) ;
V_87 . V_57 = V_2 ;
V_87 . V_84 = V_28 ;
V_87 . V_212 = V_414 -> V_386 ;
V_87 . V_213 = V_416 [ V_402 ] ? F_280 ( V_416 [ V_402 ] ) : 0 ;
V_87 . V_203 = V_93 ;
V_87 . V_339 = V_420 ;
F_63 () ;
if ( V_418 ) {
struct V_58 * V_53 ;
V_53 = F_247 ( V_37 , V_418 ) ;
if ( ! V_53 ) {
V_267 = - V_359 ;
goto V_426;
}
V_56 -> V_85 = F_54 ( V_268 ) ;
V_56 -> V_53 = V_53 ;
V_56 -> V_93 = V_93 ;
V_267 = F_236 ( V_56 , V_2 , V_28 , V_414 -> V_386 ,
V_53 , & V_157 ) ;
V_60 = F_109 ( V_56 ) ;
if ( V_267 == 0 && V_60 -> V_2 . error )
V_267 = - V_60 -> V_2 . error ;
} else {
V_60 = F_245 ( V_37 , & V_87 , & V_157 , V_56 ) ;
V_267 = 0 ;
if ( F_96 ( V_60 ) )
V_267 = F_284 ( V_60 ) ;
else
F_198 ( V_56 , & V_60 -> V_2 ) ;
}
if ( V_267 )
goto V_426;
if ( V_414 -> V_395 & V_398 )
V_60 -> V_65 |= V_397 ;
if ( V_414 -> V_395 & V_427 )
V_373 = V_60 -> V_261 ;
if ( V_414 -> V_395 & V_428 ) {
if ( ! V_157 . V_239 ) {
V_267 = V_429 [ V_157 . type ] . error ;
if ( ! V_267 )
V_267 = - V_187 ;
goto V_426;
}
V_267 = F_285 ( V_56 , F_286 ( V_411 ) . V_374 ,
V_378 -> V_430 , V_380 , V_373 ,
V_60 -> V_258 , V_157 . V_431 , V_157 . V_350 ,
V_87 . V_212 , V_157 . V_239 , 0 ) ;
} else {
V_267 = F_259 ( V_37 , V_2 , V_28 , V_373 , & V_87 , V_56 ,
F_286 ( V_411 ) . V_374 , V_378 -> V_430 ) ;
}
if ( V_267 < 0 )
goto V_426;
F_66 () ;
V_267 = F_287 ( V_56 , V_37 , F_286 ( V_411 ) . V_374 ) ;
V_422:
return V_267 ;
V_426:
F_66 () ;
F_123 ( V_56 ) ;
goto V_422;
}
void F_288 ( struct V_154 * V_155 )
{
F_36 ( F_35 ( V_155 -> V_53 ) ) ;
}
static int F_289 ( struct V_432 * V_433 , int V_434 ,
void T_15 * V_435 ,
T_16 * V_436 , T_2 * V_437 )
{
struct V_37 * V_37 = (struct V_37 * ) V_433 -> V_438 ;
if ( V_434 ) {
F_36 ( V_37 ) ;
F_290 ( V_37 ) ;
return 0 ;
}
return - V_191 ;
}
static T_3 int F_291 ( struct V_37 * V_37 )
{
struct V_432 * V_439 ;
V_439 = V_440 ;
if ( ! F_292 ( V_37 , & V_441 ) ) {
V_439 = F_293 ( V_439 , sizeof( V_440 ) , V_31 ) ;
if ( ! V_439 )
goto V_442;
if ( V_37 -> V_443 != & V_444 )
V_439 [ 0 ] . V_445 = NULL ;
}
V_439 [ 0 ] . V_438 = V_37 ;
V_37 -> V_176 . V_446 = F_294 ( V_37 , L_19 , V_439 ) ;
if ( ! V_37 -> V_176 . V_446 )
goto V_447;
return 0 ;
V_447:
if ( V_439 != V_440 )
F_23 ( V_439 ) ;
V_442:
return - V_32 ;
}
static T_4 void F_295 ( struct V_37 * V_37 )
{
struct V_432 * V_439 ;
V_439 = V_37 -> V_176 . V_446 -> V_448 ;
F_296 ( V_37 -> V_176 . V_446 ) ;
F_297 ( V_439 == V_440 ) ;
F_23 ( V_439 ) ;
}
static T_3 int F_298 ( struct V_37 * V_37 )
{
F_299 ( & V_37 -> V_176 . V_52 , 0 ) ;
F_299 ( & V_37 -> V_142 , 0 ) ;
F_299 ( & V_37 -> V_176 . V_449 , F_300 () ) ;
return 0 ;
}
static int T_3 F_301 ( struct V_37 * V_37 )
{
struct V_450 * V_451 = F_302 ( sizeof( * V_451 ) , V_31 ) ;
if ( ! V_451 )
return - V_32 ;
F_303 ( V_451 ) ;
V_37 -> V_176 . V_177 = V_451 ;
return 0 ;
}
static void T_4 F_304 ( struct V_37 * V_37 )
{
struct V_450 * V_451 = V_37 -> V_176 . V_177 ;
V_37 -> V_176 . V_177 = NULL ;
F_305 ( V_451 ) ;
F_23 ( V_451 ) ;
}
int T_5 F_306 ( void )
{
int V_452 = 0 ;
int V_12 ;
V_75 = F_302 ( V_73 * sizeof( * V_75 ) , V_31 ) ;
if ( ! V_75 )
F_307 ( L_20 ) ;
F_308 ( V_75 , V_73 * sizeof( * V_75 ) ) ;
V_72 = F_19 ( V_73 , sizeof( * V_72 ) , V_31 ) ;
if ( ! V_72 )
F_307 ( L_21 ) ;
F_20 (cpu) {
struct V_228 * V_229 = & F_12 ( V_230 , V_12 ) ;
F_188 ( & V_229 -> V_233 ) ;
F_309 ( & V_229 -> V_231 ) ;
}
#ifdef F_28
V_27 = F_310 ( 256 * sizeof( struct V_27 ) , F_311 ( struct V_27 ) ) ;
if ( ! V_27 )
F_307 ( L_22 ) ;
#endif
V_16 . V_453 =
F_312 ( L_23 , sizeof( struct V_50 ) , 0 ,
V_454 | V_455 , NULL ) ;
V_367 . V_453 = V_16 . V_453 ;
if ( F_313 ( & V_16 ) < 0 )
F_307 ( L_24 ) ;
if ( F_313 ( & V_367 ) < 0 )
F_307 ( L_25 ) ;
V_16 . V_456 = ~ 0 ;
V_457 = V_458 ;
F_314 () ;
F_315 () ;
if ( F_31 () )
F_316 ( L_26 ) ;
#ifdef F_317
F_318 () ;
F_319 () ;
#endif
F_320 ( V_459 , V_460 , F_274 , NULL , NULL ) ;
#ifdef F_321
F_32 ( & V_461 ) ;
#endif
F_32 ( & V_462 ) ;
F_32 ( & V_463 ) ;
return V_452 ;
}
void T_5 F_322 ( void )
{
F_294 ( & V_441 , L_19 , V_464 ) ;
}
