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
T_1 V_117 ;
V_117 = ( V_63 T_1 ) V_57 ;
V_117 ^= ( V_117 >> 11 ) ^ ( V_117 >> 22 ) ;
return V_117 & ( V_118 - 1 ) ;
}
static void F_70 ( struct V_50 * V_60 , struct V_108 * V_109 )
{
V_60 -> V_119 = V_109 -> V_120 ;
V_60 -> V_2 . V_121 = V_109 -> V_122 ;
if ( V_109 -> V_123 ) {
V_60 -> V_124 |= V_125 ;
V_60 -> V_62 = V_109 -> V_123 ;
V_60 -> V_126 = 1 ;
}
}
static void F_71 ( struct V_127 * V_128 , T_6 V_57 , T_6 V_129 ,
T_1 V_130 , unsigned long V_121 )
{
struct V_112 * V_65 ;
struct V_108 * V_109 ;
struct V_50 * V_60 ;
unsigned int V_29 ;
int V_131 ;
T_1 V_117 = F_69 ( V_57 ) ;
F_72 ( & V_132 ) ;
V_65 = V_128 -> V_133 ;
if ( ! V_65 ) {
V_65 = F_73 ( V_118 * sizeof( * V_65 ) , V_134 ) ;
if ( ! V_65 )
goto V_135;
V_128 -> V_133 = V_65 ;
}
V_65 += V_117 ;
V_131 = 0 ;
for ( V_109 = F_59 ( V_65 -> V_114 ) ; V_109 ;
V_109 = F_59 ( V_109 -> V_115 ) ) {
if ( V_109 -> V_136 == V_57 )
break;
V_131 ++ ;
}
if ( V_109 ) {
if ( V_129 )
V_109 -> V_123 = V_129 ;
if ( V_130 ) {
V_109 -> V_120 = V_130 ;
V_109 -> V_122 = F_74 ( 1UL , V_121 ) ;
}
V_60 = F_59 ( V_109 -> V_110 ) ;
if ( V_60 )
F_70 ( V_60 , V_109 ) ;
V_60 = F_59 ( V_109 -> V_111 ) ;
if ( V_60 )
F_70 ( V_60 , V_109 ) ;
} else {
if ( V_131 > V_137 )
V_109 = F_67 ( V_65 ) ;
else {
V_109 = F_73 ( sizeof( * V_109 ) , V_134 ) ;
if ( ! V_109 )
goto V_135;
V_109 -> V_115 = V_65 -> V_114 ;
F_75 ( V_65 -> V_114 , V_109 ) ;
}
V_109 -> V_138 = V_138 ( F_35 ( V_128 -> V_139 ) ) ;
V_109 -> V_136 = V_57 ;
V_109 -> V_123 = V_129 ;
V_109 -> V_120 = V_130 ;
V_109 -> V_122 = V_121 ;
V_60 = F_59 ( V_128 -> V_140 ) ;
if ( V_60 )
V_60 -> V_2 . V_141 = V_142 ;
F_20 (i) {
struct V_50 T_9 * * V_143 ;
V_143 = F_21 ( V_128 -> V_144 , V_29 ) ;
V_60 = F_59 ( * V_143 ) ;
if ( V_60 )
V_60 -> V_2 . V_141 = V_142 ;
}
}
V_109 -> V_116 = V_73 ;
V_135:
F_76 ( & V_132 ) ;
}
static void F_77 ( struct V_50 * V_60 , struct V_55 * V_56 , struct V_81 * V_82 ,
bool V_145 )
{
T_6 V_146 = F_78 ( V_56 ) -> V_147 . V_148 ;
T_6 V_149 = F_39 ( V_56 ) -> V_79 ;
struct V_58 * V_53 = V_56 -> V_53 ;
struct V_150 * V_151 ;
struct V_152 V_153 ;
struct V_54 * V_61 ;
struct V_37 * V_37 ;
switch ( F_78 ( V_56 ) -> V_154 & 7 ) {
case V_155 :
case V_156 :
case V_157 :
case V_158 :
break;
default:
return;
}
if ( V_60 -> V_62 != V_149 )
return;
V_151 = F_79 ( V_53 ) ;
if ( ! V_151 )
return;
V_37 = F_35 ( V_53 ) ;
if ( V_146 == V_149 || ! F_80 ( V_151 ) ||
F_81 ( V_146 ) || F_82 ( V_146 ) ||
F_83 ( V_146 ) )
goto V_159;
if ( ! F_84 ( V_151 ) ) {
if ( ! F_85 ( V_151 , V_146 , V_149 ) )
goto V_159;
if ( F_86 ( V_151 ) && F_87 ( V_146 , V_53 ) )
goto V_159;
} else {
if ( F_88 ( V_37 , V_146 ) != V_160 )
goto V_159;
}
V_61 = F_38 ( & V_60 -> V_2 , NULL , & V_146 ) ;
if ( ! F_89 ( V_61 ) ) {
if ( ! ( V_61 -> V_161 & V_162 ) ) {
F_90 ( V_61 , NULL ) ;
} else {
if ( F_91 ( V_37 , V_82 , & V_153 ) == 0 ) {
struct V_127 * V_128 = & F_92 ( V_153 ) ;
F_71 ( V_128 , V_82 -> V_57 , V_146 ,
0 , 0 ) ;
}
if ( V_145 )
V_60 -> V_2 . V_141 = V_142 ;
F_93 ( V_163 , V_61 ) ;
}
F_94 ( V_61 ) ;
}
return;
V_159:
#ifdef F_95
if ( F_96 ( V_151 ) ) {
const struct V_76 * V_77 = ( const struct V_76 * ) V_56 -> V_164 ;
T_6 V_57 = V_77 -> V_57 ;
T_6 V_79 = V_77 -> V_79 ;
F_97 ( L_10
L_11 ,
& V_149 , V_53 -> V_165 , & V_146 ,
& V_79 , & V_57 ) ;
}
#endif
;
}
static void F_98 ( struct V_1 * V_2 , struct V_83 * V_84 , struct V_55 * V_56 )
{
struct V_50 * V_60 ;
struct V_81 V_82 ;
const struct V_76 * V_77 = ( const struct V_76 * ) V_56 -> V_164 ;
int V_85 = V_56 -> V_53 -> V_98 ;
T_8 V_86 = F_56 ( V_77 -> V_86 ) ;
T_8 V_87 = V_77 -> V_80 ;
T_1 V_88 = V_56 -> V_88 ;
V_60 = (struct V_50 * ) V_2 ;
F_51 ( & V_82 , V_84 , V_77 , V_85 , V_86 , V_87 , V_88 , 0 ) ;
F_77 ( V_60 , V_56 , & V_82 , true ) ;
}
static struct V_1 * F_99 ( struct V_1 * V_2 )
{
struct V_50 * V_60 = (struct V_50 * ) V_2 ;
struct V_1 * V_166 = V_2 ;
if ( V_60 ) {
if ( V_2 -> V_141 > 0 ) {
F_100 ( V_60 ) ;
V_166 = NULL ;
} else if ( ( V_60 -> V_124 & V_125 ) ||
V_60 -> V_2 . V_121 ) {
F_100 ( V_60 ) ;
V_166 = NULL ;
}
}
return V_166 ;
}
void F_101 ( struct V_55 * V_56 )
{
struct V_50 * V_60 = F_102 ( V_56 ) ;
struct V_150 * V_151 ;
struct V_167 * V_168 ;
struct V_37 * V_37 ;
int V_169 ;
F_58 () ;
V_151 = F_79 ( V_60 -> V_2 . V_53 ) ;
if ( ! V_151 || ! F_103 ( V_151 ) ) {
F_61 () ;
return;
}
V_169 = F_96 ( V_151 ) ;
F_61 () ;
V_37 = F_35 ( V_60 -> V_2 . V_53 ) ;
V_168 = F_104 ( V_37 -> V_170 . V_171 , F_39 ( V_56 ) -> V_79 , 1 ) ;
if ( ! V_168 ) {
F_105 ( V_56 , V_172 , V_157 ,
F_106 ( V_60 , F_39 ( V_56 ) -> V_57 ) ) ;
return;
}
if ( F_107 ( V_73 , V_168 -> V_173 + V_174 ) )
V_168 -> V_175 = 0 ;
if ( V_168 -> V_175 >= V_176 ) {
V_168 -> V_173 = V_73 ;
goto V_177;
}
if ( V_168 -> V_175 == 0 ||
F_107 ( V_73 ,
( V_168 -> V_173 +
( V_178 << V_168 -> V_175 ) ) ) ) {
T_6 V_129 = F_106 ( V_60 , F_39 ( V_56 ) -> V_57 ) ;
F_105 ( V_56 , V_172 , V_157 , V_129 ) ;
V_168 -> V_173 = V_73 ;
++ V_168 -> V_175 ;
#ifdef F_95
if ( V_169 &&
V_168 -> V_175 == V_176 )
F_108 ( L_12 ,
& F_39 ( V_56 ) -> V_79 , F_109 ( V_56 ) ,
& F_39 ( V_56 ) -> V_57 , & V_129 ) ;
#endif
}
V_177:
F_110 ( V_168 ) ;
}
static int F_111 ( struct V_55 * V_56 )
{
struct V_150 * V_151 = F_79 ( V_56 -> V_53 ) ;
struct V_50 * V_60 = F_102 ( V_56 ) ;
struct V_167 * V_168 ;
unsigned long V_72 ;
struct V_37 * V_37 ;
bool V_179 ;
int V_154 ;
V_37 = F_35 ( V_60 -> V_2 . V_53 ) ;
if ( ! F_112 ( V_151 ) ) {
switch ( V_60 -> V_2 . error ) {
case V_180 :
F_113 ( V_37 , V_181 ) ;
break;
case V_182 :
F_113 ( V_37 , V_183 ) ;
break;
}
goto V_184;
}
switch ( V_60 -> V_2 . error ) {
case V_185 :
default:
goto V_184;
case V_180 :
V_154 = V_186 ;
break;
case V_182 :
V_154 = V_187 ;
F_113 ( V_37 , V_183 ) ;
break;
case V_188 :
V_154 = V_189 ;
break;
}
V_168 = F_104 ( V_37 -> V_170 . V_171 , F_39 ( V_56 ) -> V_79 , 1 ) ;
V_179 = true ;
if ( V_168 ) {
V_72 = V_73 ;
V_168 -> V_175 += V_72 - V_168 -> V_173 ;
if ( V_168 -> V_175 > V_190 )
V_168 -> V_175 = V_190 ;
V_168 -> V_173 = V_72 ;
if ( V_168 -> V_175 >= V_191 )
V_168 -> V_175 -= V_191 ;
else
V_179 = false ;
F_110 ( V_168 ) ;
}
if ( V_179 )
F_105 ( V_56 , V_192 , V_154 , 0 ) ;
V_184: F_114 ( V_56 ) ;
return 0 ;
}
static void F_115 ( struct V_50 * V_60 , struct V_81 * V_82 , T_1 V_193 )
{
struct V_1 * V_2 = & V_60 -> V_2 ;
struct V_152 V_153 ;
if ( F_116 ( V_2 , V_194 ) )
return;
if ( V_2 -> V_53 -> V_193 < V_193 )
return;
if ( V_193 < V_195 )
V_193 = V_195 ;
if ( V_60 -> V_119 == V_193 &&
F_68 ( V_73 , V_2 -> V_121 - V_196 / 2 ) )
return;
F_58 () ;
if ( F_91 ( F_35 ( V_2 -> V_53 ) , V_82 , & V_153 ) == 0 ) {
struct V_127 * V_128 = & F_92 ( V_153 ) ;
F_71 ( V_128 , V_82 -> V_57 , 0 , V_193 ,
V_73 + V_196 ) ;
}
F_61 () ;
}
static void F_117 ( struct V_1 * V_2 , struct V_83 * V_84 ,
struct V_55 * V_56 , T_1 V_193 )
{
struct V_50 * V_60 = (struct V_50 * ) V_2 ;
struct V_81 V_82 ;
F_62 ( & V_82 , V_84 , V_56 ) ;
F_115 ( V_60 , & V_82 , V_193 ) ;
}
void F_118 ( struct V_55 * V_56 , struct V_37 * V_37 , T_1 V_193 ,
int V_85 , T_1 V_88 , T_8 V_80 , int V_89 )
{
const struct V_76 * V_77 = ( const struct V_76 * ) V_56 -> V_164 ;
struct V_81 V_82 ;
struct V_50 * V_60 ;
if ( ! V_88 )
V_88 = F_119 ( V_37 , V_56 -> V_88 ) ;
F_51 ( & V_82 , NULL , V_77 , V_85 ,
F_56 ( V_77 -> V_86 ) , V_80 , V_88 , V_89 ) ;
V_60 = F_120 ( V_37 , & V_82 ) ;
if ( ! F_89 ( V_60 ) ) {
F_115 ( V_60 , & V_82 , V_193 ) ;
F_100 ( V_60 ) ;
}
}
static void F_121 ( struct V_55 * V_56 , struct V_83 * V_84 , T_1 V_193 )
{
const struct V_76 * V_77 = ( const struct V_76 * ) V_56 -> V_164 ;
struct V_81 V_82 ;
struct V_50 * V_60 ;
F_51 ( & V_82 , V_84 , V_77 , 0 , 0 , 0 , 0 , 0 ) ;
if ( ! V_82 . V_197 )
V_82 . V_197 = F_119 ( F_122 ( V_84 ) , V_56 -> V_88 ) ;
V_60 = F_120 ( F_122 ( V_84 ) , & V_82 ) ;
if ( ! F_89 ( V_60 ) ) {
F_115 ( V_60 , & V_82 , V_193 ) ;
F_100 ( V_60 ) ;
}
}
void F_123 ( struct V_55 * V_56 , struct V_83 * V_84 , T_1 V_193 )
{
const struct V_76 * V_77 = ( const struct V_76 * ) V_56 -> V_164 ;
struct V_81 V_82 ;
struct V_50 * V_60 ;
struct V_1 * V_198 = NULL ;
bool V_199 = false ;
F_124 ( V_84 ) ;
if ( ! F_125 ( V_84 ) )
goto V_184;
V_198 = F_126 ( V_84 ) ;
if ( F_127 ( V_84 ) || ! V_198 ) {
F_121 ( V_56 , V_84 , V_193 ) ;
goto V_184;
}
F_51 ( & V_82 , V_84 , V_77 , 0 , 0 , 0 , 0 , 0 ) ;
V_60 = (struct V_50 * ) V_198 ;
if ( V_198 -> V_141 && V_198 -> V_200 -> V_201 ( V_198 , 0 ) == NULL ) {
V_60 = F_128 ( F_122 ( V_84 ) , & V_82 , V_84 ) ;
if ( F_89 ( V_60 ) )
goto V_184;
V_199 = true ;
}
F_115 ( (struct V_50 * ) V_60 -> V_2 . V_202 , & V_82 , V_193 ) ;
if ( ! F_129 ( & V_60 -> V_2 , 0 ) ) {
if ( V_199 )
F_130 ( & V_60 -> V_2 ) ;
V_60 = F_128 ( F_122 ( V_84 ) , & V_82 , V_84 ) ;
if ( F_89 ( V_60 ) )
goto V_184;
V_199 = true ;
}
if ( V_199 )
F_131 ( V_84 , & V_60 -> V_2 ) ;
V_184:
F_132 ( V_84 ) ;
F_130 ( V_198 ) ;
}
void F_133 ( struct V_55 * V_56 , struct V_37 * V_37 ,
int V_85 , T_1 V_88 , T_8 V_80 , int V_89 )
{
const struct V_76 * V_77 = ( const struct V_76 * ) V_56 -> V_164 ;
struct V_81 V_82 ;
struct V_50 * V_60 ;
F_51 ( & V_82 , NULL , V_77 , V_85 ,
F_56 ( V_77 -> V_86 ) , V_80 , V_88 , V_89 ) ;
V_60 = F_120 ( V_37 , & V_82 ) ;
if ( ! F_89 ( V_60 ) ) {
F_77 ( V_60 , V_56 , & V_82 , false ) ;
F_100 ( V_60 ) ;
}
}
void F_134 ( struct V_55 * V_56 , struct V_83 * V_84 )
{
const struct V_76 * V_77 = ( const struct V_76 * ) V_56 -> V_164 ;
struct V_81 V_82 ;
struct V_50 * V_60 ;
F_51 ( & V_82 , V_84 , V_77 , 0 , 0 , 0 , 0 , 0 ) ;
V_60 = F_120 ( F_122 ( V_84 ) , & V_82 ) ;
if ( ! F_89 ( V_60 ) ) {
F_77 ( V_60 , V_56 , & V_82 , false ) ;
F_100 ( V_60 ) ;
}
}
static struct V_1 * F_135 ( struct V_1 * V_2 , T_1 V_203 )
{
struct V_50 * V_60 = (struct V_50 * ) V_2 ;
if ( V_2 -> V_141 != V_204 || F_33 ( V_60 ) )
return NULL ;
return V_2 ;
}
static void F_136 ( struct V_55 * V_56 )
{
struct V_50 * V_60 ;
F_105 ( V_56 , V_192 , V_186 , 0 ) ;
V_60 = F_102 ( V_56 ) ;
if ( V_60 )
F_137 ( & V_60 -> V_2 , 0 ) ;
}
static int F_138 ( struct V_83 * V_84 , struct V_55 * V_56 )
{
F_139 ( L_13 ,
V_205 , & F_39 ( V_56 ) -> V_79 , & F_39 ( V_56 ) -> V_57 ,
V_56 -> V_53 ? V_56 -> V_53 -> V_165 : L_14 ) ;
F_114 ( V_56 ) ;
F_2 ( 1 ) ;
return 0 ;
}
void F_140 ( T_8 * V_206 , struct V_55 * V_56 , struct V_50 * V_60 )
{
T_6 V_28 ;
if ( F_141 ( V_60 ) )
V_28 = F_39 ( V_56 ) -> V_79 ;
else {
struct V_152 V_153 ;
struct V_81 V_82 ;
struct V_76 * V_77 ;
V_77 = F_39 ( V_56 ) ;
memset ( & V_82 , 0 , sizeof( V_82 ) ) ;
V_82 . V_57 = V_77 -> V_57 ;
V_82 . V_79 = V_77 -> V_79 ;
V_82 . V_207 = F_56 ( V_77 -> V_86 ) ;
V_82 . V_208 = V_60 -> V_2 . V_53 -> V_98 ;
V_82 . V_209 = V_56 -> V_53 -> V_98 ;
V_82 . V_197 = V_56 -> V_88 ;
F_58 () ;
if ( F_91 ( F_35 ( V_60 -> V_2 . V_53 ) , & V_82 , & V_153 ) == 0 )
V_28 = F_142 ( F_35 ( V_60 -> V_2 . V_53 ) , V_153 ) ;
else
V_28 = F_143 ( V_60 -> V_2 . V_53 ,
F_106 ( V_60 , V_77 -> V_57 ) ,
V_97 ) ;
F_61 () ;
}
memcpy ( V_206 , & V_28 , 4 ) ;
}
static void F_144 ( struct V_50 * V_60 , T_1 V_210 )
{
if ( ! ( V_60 -> V_2 . V_211 & 0xFFFF ) )
V_60 -> V_2 . V_211 |= V_210 & 0xFFFF ;
if ( ! ( V_60 -> V_2 . V_211 & 0xFFFF0000 ) )
V_60 -> V_2 . V_211 |= V_210 & 0xFFFF0000 ;
}
static unsigned int F_145 ( const struct V_1 * V_2 )
{
unsigned int V_212 = F_146 ( V_2 , V_213 ) ;
if ( V_212 == 0 ) {
V_212 = F_147 (unsigned int, dst->dev->mtu - 40 ,
ip_rt_min_advmss) ;
if ( V_212 > 65535 - 40 )
V_212 = 65535 - 40 ;
}
return V_212 ;
}
static unsigned int F_148 ( const struct V_1 * V_2 )
{
const struct V_50 * V_60 = ( const struct V_50 * ) V_2 ;
unsigned int V_193 = V_60 -> V_119 ;
if ( ! V_193 || F_149 ( V_73 , V_60 -> V_2 . V_121 ) )
V_193 = F_146 ( V_2 , V_194 ) ;
if ( V_193 )
return V_193 ;
V_193 = V_2 -> V_53 -> V_193 ;
if ( F_150 ( F_116 ( V_2 , V_194 ) ) ) {
if ( V_60 -> V_126 && V_193 > 576 )
V_193 = 576 ;
}
return F_151 (unsigned int, mtu, IP_MAX_MTU) ;
}
static struct V_108 * F_152 ( struct V_127 * V_128 , T_6 V_57 )
{
struct V_112 * V_65 = V_128 -> V_133 ;
struct V_108 * V_109 ;
T_1 V_117 ;
if ( ! V_65 )
return NULL ;
V_117 = F_69 ( V_57 ) ;
for ( V_109 = F_59 ( V_65 [ V_117 ] . V_114 ) ; V_109 ;
V_109 = F_59 ( V_109 -> V_115 ) ) {
if ( V_109 -> V_136 == V_57 )
return V_109 ;
}
return NULL ;
}
static bool F_153 ( struct V_50 * V_60 , struct V_108 * V_109 ,
T_6 V_57 )
{
bool V_166 = false ;
F_72 ( & V_132 ) ;
if ( V_57 == V_109 -> V_136 ) {
struct V_50 T_9 * * V_214 ;
struct V_50 * V_215 ;
int V_216 = V_138 ( F_35 ( V_60 -> V_2 . V_53 ) ) ;
if ( F_154 ( V_60 ) )
V_214 = & V_109 -> V_110 ;
else
V_214 = & V_109 -> V_111 ;
V_215 = F_59 ( * V_214 ) ;
if ( V_109 -> V_138 != V_216 ) {
V_109 -> V_138 = V_216 ;
V_109 -> V_123 = 0 ;
V_109 -> V_120 = 0 ;
V_109 -> V_122 = 0 ;
F_65 ( V_109 ) ;
V_215 = NULL ;
}
F_70 ( V_60 , V_109 ) ;
if ( ! V_60 -> V_62 )
V_60 -> V_62 = V_57 ;
if ( ! ( V_60 -> V_2 . V_217 & V_218 ) ) {
F_75 ( * V_214 , V_60 ) ;
if ( V_215 )
F_63 ( V_215 ) ;
V_166 = true ;
}
V_109 -> V_116 = V_73 ;
}
F_76 ( & V_132 ) ;
return V_166 ;
}
static bool F_155 ( struct V_127 * V_128 , struct V_50 * V_60 )
{
struct V_50 * V_215 , * V_219 , * * V_220 ;
bool V_166 = true ;
if ( F_154 ( V_60 ) ) {
V_220 = (struct V_50 * * ) & V_128 -> V_140 ;
} else {
V_220 = (struct V_50 * * ) F_156 ( V_128 -> V_144 ) ;
}
V_215 = * V_220 ;
V_219 = F_44 ( V_220 , V_215 , V_60 ) ;
if ( V_219 == V_215 ) {
if ( V_215 )
F_63 ( V_215 ) ;
} else
V_166 = false ;
return V_166 ;
}
static void F_157 ( struct V_50 * V_60 )
{
F_72 ( & V_221 ) ;
F_158 ( & V_60 -> V_222 , & V_223 ) ;
F_76 ( & V_221 ) ;
}
static void F_159 ( struct V_1 * V_2 )
{
struct V_50 * V_60 = (struct V_50 * ) V_2 ;
if ( ! F_160 ( & V_60 -> V_222 ) ) {
F_72 ( & V_221 ) ;
F_161 ( & V_60 -> V_222 ) ;
F_76 ( & V_221 ) ;
}
}
void F_162 ( struct V_58 * V_53 )
{
if ( ! F_160 ( & V_223 ) ) {
struct V_37 * V_37 = F_35 ( V_53 ) ;
struct V_50 * V_60 ;
F_72 ( & V_221 ) ;
F_163 (rt, &rt_uncached_list, rt_uncached) {
if ( V_60 -> V_2 . V_53 != V_53 )
continue;
V_60 -> V_2 . V_53 = V_37 -> V_224 ;
F_164 ( V_60 -> V_2 . V_53 ) ;
F_165 ( V_53 ) ;
}
F_76 ( & V_221 ) ;
}
}
static bool F_166 ( const struct V_50 * V_60 )
{
return V_60 &&
V_60 -> V_2 . V_141 == V_204 &&
! F_33 ( V_60 ) ;
}
static void F_167 ( struct V_50 * V_60 , T_6 V_57 ,
const struct V_152 * V_153 ,
struct V_108 * V_109 ,
struct V_225 * V_226 , T_10 type , T_1 V_227 )
{
bool V_228 = false ;
if ( V_226 ) {
struct V_127 * V_128 = & F_92 ( * V_153 ) ;
if ( V_128 -> V_229 && V_128 -> V_230 == V_231 ) {
V_60 -> V_62 = V_128 -> V_229 ;
V_60 -> V_126 = 1 ;
}
F_168 ( & V_60 -> V_2 , V_226 -> V_232 , true ) ;
#ifdef F_28
V_60 -> V_2 . V_211 = V_128 -> V_233 ;
#endif
if ( F_150 ( V_109 ) )
V_228 = F_153 ( V_60 , V_109 , V_57 ) ;
else if ( ! ( V_60 -> V_2 . V_217 & V_218 ) )
V_228 = F_155 ( V_128 , V_60 ) ;
if ( F_150 ( ! V_228 ) ) {
V_60 -> V_2 . V_217 |= V_218 ;
if ( ! V_60 -> V_62 )
V_60 -> V_62 = V_57 ;
F_157 ( V_60 ) ;
}
} else
F_157 ( V_60 ) ;
#ifdef F_28
#ifdef F_169
F_144 ( V_60 , V_153 -> V_211 ) ;
#endif
F_144 ( V_60 , V_227 ) ;
#endif
}
static struct V_50 * F_170 ( struct V_58 * V_53 ,
bool V_234 , bool V_235 , bool V_236 )
{
return F_171 ( & V_16 , V_53 , 1 , V_204 ,
( V_236 ? 0 : ( V_237 | V_218 ) ) |
( V_234 ? V_238 : 0 ) |
( V_235 ? V_239 : 0 ) ) ;
}
static int F_172 ( struct V_55 * V_56 , T_6 V_57 , T_6 V_79 ,
T_8 V_86 , struct V_58 * V_53 , int V_240 )
{
struct V_50 * V_51 ;
struct V_150 * V_151 = F_79 ( V_53 ) ;
T_1 V_227 = 0 ;
int V_241 ;
if ( V_151 == NULL )
return - V_185 ;
if ( F_81 ( V_79 ) || F_82 ( V_79 ) ||
V_56 -> V_80 != F_50 ( V_242 ) )
goto V_243;
if ( F_173 ( ! F_174 ( V_151 ) ) )
if ( F_175 ( V_79 ) )
goto V_243;
if ( F_83 ( V_79 ) ) {
if ( ! F_176 ( V_57 ) )
goto V_243;
} else {
V_241 = F_177 ( V_56 , V_79 , 0 , V_86 , 0 , V_53 ,
V_151 , & V_227 ) ;
if ( V_241 < 0 )
goto V_244;
}
V_51 = F_170 ( F_35 ( V_53 ) -> V_224 ,
F_178 ( V_151 , V_245 ) , false , false ) ;
if ( ! V_51 )
goto V_246;
#ifdef F_28
V_51 -> V_2 . V_211 = V_227 ;
#endif
V_51 -> V_2 . V_247 = F_138 ;
V_51 -> V_52 = F_34 ( F_35 ( V_53 ) ) ;
V_51 -> V_124 = V_248 ;
V_51 -> V_249 = V_250 ;
V_51 -> V_251 = 1 ;
V_51 -> V_252 = 0 ;
V_51 -> V_119 = 0 ;
V_51 -> V_62 = 0 ;
V_51 -> V_126 = 0 ;
F_179 ( & V_51 -> V_222 ) ;
if ( V_240 ) {
V_51 -> V_2 . V_253 = V_254 ;
V_51 -> V_124 |= V_255 ;
}
#ifdef F_180
if ( ! F_176 ( V_57 ) && F_181 ( V_151 ) )
V_51 -> V_2 . V_253 = V_256 ;
#endif
F_182 ( V_18 ) ;
F_183 ( V_56 , & V_51 -> V_2 ) ;
return 0 ;
V_246:
return - V_257 ;
V_243:
return - V_185 ;
V_244:
return V_241 ;
}
static void F_184 ( struct V_58 * V_53 ,
struct V_150 * V_151 ,
struct V_55 * V_56 ,
T_6 V_57 ,
T_6 V_79 )
{
F_182 ( V_22 ) ;
#ifdef F_95
if ( F_96 ( V_151 ) && F_185 () ) {
F_186 ( L_15 ,
& V_57 , & V_79 , V_53 -> V_165 ) ;
if ( V_53 -> V_258 && F_187 ( V_56 ) ) {
F_188 ( V_259 , L_16 ,
V_260 , 16 , 1 ,
F_189 ( V_56 ) ,
V_53 -> V_258 , true ) ;
}
}
#endif
}
static int F_190 ( struct V_55 * V_56 ,
const struct V_152 * V_153 ,
struct V_150 * V_151 ,
T_6 V_57 , T_6 V_79 , T_1 V_86 )
{
struct V_108 * V_109 ;
struct V_50 * V_51 ;
int V_241 ;
struct V_150 * V_261 ;
unsigned int V_217 = 0 ;
bool V_262 ;
T_1 V_227 = 0 ;
V_261 = F_79 ( F_191 ( * V_153 ) ) ;
if ( V_261 == NULL ) {
F_192 ( L_17 ) ;
return - V_185 ;
}
V_241 = F_177 ( V_56 , V_79 , V_57 , V_86 , F_193 ( * V_153 ) ,
V_151 -> V_53 , V_151 , & V_227 ) ;
if ( V_241 < 0 ) {
F_184 ( V_151 -> V_53 , V_151 , V_56 , V_57 ,
V_79 ) ;
goto V_263;
}
V_262 = V_153 -> V_226 && ! V_227 ;
if ( V_261 == V_151 && V_241 && F_103 ( V_261 ) &&
( F_84 ( V_261 ) ||
F_85 ( V_261 , V_79 , F_194 ( * V_153 ) ) ) ) {
V_217 |= V_264 ;
V_262 = false ;
}
if ( V_56 -> V_80 != F_50 ( V_242 ) ) {
if ( V_261 == V_151 &&
F_195 ( V_151 ) == 0 ) {
V_241 = - V_185 ;
goto V_263;
}
}
V_109 = F_152 ( & F_92 ( * V_153 ) , V_57 ) ;
if ( V_262 ) {
if ( V_109 != NULL )
V_51 = F_59 ( V_109 -> V_110 ) ;
else
V_51 = F_59 ( F_92 ( * V_153 ) . V_140 ) ;
if ( F_166 ( V_51 ) ) {
F_196 ( V_56 , & V_51 -> V_2 ) ;
goto V_184;
}
}
V_51 = F_170 ( V_261 -> V_53 ,
F_178 ( V_151 , V_245 ) ,
F_178 ( V_261 , V_265 ) , V_262 ) ;
if ( ! V_51 ) {
V_241 = - V_257 ;
goto V_263;
}
V_51 -> V_52 = F_34 ( F_35 ( V_51 -> V_2 . V_53 ) ) ;
V_51 -> V_124 = V_217 ;
V_51 -> V_249 = V_153 -> type ;
V_51 -> V_251 = 1 ;
V_51 -> V_252 = 0 ;
V_51 -> V_119 = 0 ;
V_51 -> V_62 = 0 ;
V_51 -> V_126 = 0 ;
F_179 ( & V_51 -> V_222 ) ;
F_182 ( V_17 ) ;
V_51 -> V_2 . V_253 = V_266 ;
V_51 -> V_2 . V_247 = V_267 ;
F_167 ( V_51 , V_57 , V_153 , V_109 , V_153 -> V_226 , V_153 -> type , V_227 ) ;
F_183 ( V_56 , & V_51 -> V_2 ) ;
V_184:
V_241 = 0 ;
V_263:
return V_241 ;
}
static int F_197 ( struct V_55 * V_56 ,
struct V_152 * V_153 ,
const struct V_81 * V_82 ,
struct V_150 * V_151 ,
T_6 V_57 , T_6 V_79 , T_1 V_86 )
{
#ifdef F_198
if ( V_153 -> V_226 && V_153 -> V_226 -> V_268 > 1 )
F_199 ( V_153 ) ;
#endif
return F_190 ( V_56 , V_153 , V_151 , V_57 , V_79 , V_86 ) ;
}
static int F_200 ( struct V_55 * V_56 , T_6 V_57 , T_6 V_79 ,
T_8 V_86 , struct V_58 * V_53 )
{
struct V_152 V_153 ;
struct V_150 * V_151 = F_79 ( V_53 ) ;
struct V_81 V_82 ;
unsigned int V_217 = 0 ;
T_1 V_227 = 0 ;
struct V_50 * V_51 ;
int V_241 = - V_185 ;
struct V_37 * V_37 = F_35 ( V_53 ) ;
bool V_262 ;
if ( ! V_151 )
goto V_184;
if ( F_81 ( V_79 ) || F_82 ( V_79 ) )
goto V_269;
V_153 . V_226 = NULL ;
if ( F_82 ( V_57 ) || ( V_79 == 0 && V_57 == 0 ) )
goto V_270;
if ( F_83 ( V_79 ) )
goto V_269;
if ( F_83 ( V_57 ) )
goto V_271;
if ( F_175 ( V_57 ) ) {
if ( ! F_201 ( V_151 , V_37 ) )
goto V_271;
} else if ( F_175 ( V_79 ) ) {
if ( ! F_201 ( V_151 , V_37 ) )
goto V_269;
}
V_82 . V_208 = 0 ;
V_82 . V_209 = V_53 -> V_98 ;
V_82 . V_197 = V_56 -> V_88 ;
V_82 . V_207 = V_86 ;
V_82 . V_272 = V_97 ;
V_82 . V_57 = V_57 ;
V_82 . V_79 = V_79 ;
V_241 = F_91 ( V_37 , & V_82 , & V_153 ) ;
if ( V_241 != 0 ) {
if ( ! F_112 ( V_151 ) )
V_241 = - V_180 ;
goto V_273;
}
if ( V_153 . type == V_274 )
goto V_270;
if ( V_153 . type == V_275 ) {
V_241 = F_177 ( V_56 , V_79 , V_57 , V_86 ,
0 , V_53 , V_151 , & V_227 ) ;
if ( V_241 < 0 )
goto V_276;
goto V_277;
}
if ( ! F_112 ( V_151 ) ) {
V_241 = - V_180 ;
goto V_273;
}
if ( V_153 . type != V_160 )
goto V_271;
V_241 = F_197 ( V_56 , & V_153 , & V_82 , V_151 , V_57 , V_79 , V_86 ) ;
V_184: return V_241 ;
V_270:
if ( V_56 -> V_80 != F_50 ( V_242 ) )
goto V_243;
if ( ! F_83 ( V_79 ) ) {
V_241 = F_177 ( V_56 , V_79 , 0 , V_86 , 0 , V_53 ,
V_151 , & V_227 ) ;
if ( V_241 < 0 )
goto V_276;
}
V_217 |= V_278 ;
V_153 . type = V_274 ;
F_182 ( V_20 ) ;
V_277:
V_262 = false ;
if ( V_153 . V_226 ) {
if ( ! V_227 ) {
V_51 = F_59 ( F_92 ( V_153 ) . V_140 ) ;
if ( F_166 ( V_51 ) ) {
F_196 ( V_56 , & V_51 -> V_2 ) ;
V_241 = 0 ;
goto V_184;
}
V_262 = true ;
}
}
V_51 = F_170 ( V_37 -> V_224 ,
F_178 ( V_151 , V_245 ) , false , V_262 ) ;
if ( ! V_51 )
goto V_246;
V_51 -> V_2 . V_253 = V_254 ;
V_51 -> V_2 . V_247 = F_138 ;
#ifdef F_28
V_51 -> V_2 . V_211 = V_227 ;
#endif
V_51 -> V_52 = F_34 ( V_37 ) ;
V_51 -> V_124 = V_217 | V_255 ;
V_51 -> V_249 = V_153 . type ;
V_51 -> V_251 = 1 ;
V_51 -> V_252 = 0 ;
V_51 -> V_119 = 0 ;
V_51 -> V_62 = 0 ;
V_51 -> V_126 = 0 ;
F_179 ( & V_51 -> V_222 ) ;
F_182 ( V_17 ) ;
if ( V_153 . type == V_279 ) {
V_51 -> V_2 . V_253 = F_111 ;
V_51 -> V_2 . error = - V_241 ;
V_51 -> V_124 &= ~ V_255 ;
}
if ( V_262 ) {
if ( F_150 ( ! F_155 ( & F_92 ( V_153 ) , V_51 ) ) ) {
V_51 -> V_2 . V_217 |= V_218 ;
F_157 ( V_51 ) ;
}
}
F_183 ( V_56 , & V_51 -> V_2 ) ;
V_241 = 0 ;
goto V_184;
V_273:
F_182 ( V_19 ) ;
V_153 . type = V_279 ;
goto V_277;
V_271:
F_182 ( V_21 ) ;
#ifdef F_95
if ( F_96 ( V_151 ) )
F_108 ( L_18 ,
& V_57 , & V_79 , V_53 -> V_165 ) ;
#endif
V_243:
V_241 = - V_185 ;
goto V_184;
V_246:
V_241 = - V_257 ;
goto V_184;
V_269:
V_241 = - V_185 ;
V_276:
F_184 ( V_53 , V_151 , V_56 , V_57 , V_79 ) ;
goto V_184;
}
int F_202 ( struct V_55 * V_56 , T_6 V_57 , T_6 V_79 ,
T_8 V_86 , struct V_58 * V_53 )
{
int V_153 ;
F_58 () ;
if ( F_81 ( V_57 ) ) {
struct V_150 * V_151 = F_79 ( V_53 ) ;
if ( V_151 ) {
int V_240 = F_203 ( V_151 , V_57 , V_79 ,
F_39 ( V_56 ) -> V_80 ) ;
if ( V_240
#ifdef F_180
||
( ! F_176 ( V_57 ) &&
F_181 ( V_151 ) )
#endif
) {
int V_153 = F_172 ( V_56 , V_57 , V_79 ,
V_86 , V_53 , V_240 ) ;
F_61 () ;
return V_153 ;
}
}
F_61 () ;
return - V_185 ;
}
V_153 = F_200 ( V_56 , V_57 , V_79 , V_86 , V_53 ) ;
F_61 () ;
return V_153 ;
}
static struct V_50 * F_204 ( const struct V_152 * V_153 ,
const struct V_81 * V_82 , int V_280 ,
struct V_58 * V_281 ,
unsigned int V_217 )
{
struct V_225 * V_226 = V_153 -> V_226 ;
struct V_108 * V_109 ;
struct V_150 * V_151 ;
T_10 type = V_153 -> type ;
struct V_50 * V_51 ;
bool V_262 ;
V_151 = F_79 ( V_281 ) ;
if ( ! V_151 )
return F_205 ( - V_185 ) ;
if ( F_173 ( ! F_174 ( V_151 ) ) )
if ( F_175 ( V_82 -> V_79 ) && ! ( V_281 -> V_217 & V_282 ) )
return F_205 ( - V_185 ) ;
if ( F_82 ( V_82 -> V_57 ) )
type = V_274 ;
else if ( F_81 ( V_82 -> V_57 ) )
type = V_250 ;
else if ( F_83 ( V_82 -> V_57 ) )
return F_205 ( - V_185 ) ;
if ( V_281 -> V_217 & V_282 )
V_217 |= V_255 ;
V_262 = true ;
if ( type == V_274 ) {
V_217 |= V_278 | V_255 ;
V_226 = NULL ;
} else if ( type == V_250 ) {
V_217 |= V_248 | V_255 ;
if ( ! F_203 ( V_151 , V_82 -> V_57 , V_82 -> V_79 ,
V_82 -> V_283 ) )
V_217 &= ~ V_255 ;
else
V_262 = false ;
if ( V_226 && V_153 -> V_284 < 4 )
V_226 = NULL ;
}
V_109 = NULL ;
V_262 &= V_226 != NULL ;
if ( V_262 ) {
struct V_50 T_9 * * V_285 ;
struct V_127 * V_128 = & F_92 ( * V_153 ) ;
V_109 = F_152 ( V_128 , V_82 -> V_57 ) ;
if ( V_109 )
V_285 = & V_109 -> V_111 ;
else {
if ( F_150 ( V_82 -> V_286 &
V_287 &&
! ( V_128 -> V_229 &&
V_128 -> V_230 == V_231 ) ) ) {
V_262 = false ;
goto V_288;
}
V_285 = F_156 ( V_128 -> V_144 ) ;
}
V_51 = F_59 ( * V_285 ) ;
if ( F_166 ( V_51 ) ) {
F_206 ( & V_51 -> V_2 ) ;
return V_51 ;
}
}
V_288:
V_51 = F_170 ( V_281 ,
F_178 ( V_151 , V_245 ) ,
F_178 ( V_151 , V_265 ) ,
V_262 ) ;
if ( ! V_51 )
return F_205 ( - V_257 ) ;
V_51 -> V_2 . V_247 = V_267 ;
V_51 -> V_52 = F_34 ( F_35 ( V_281 ) ) ;
V_51 -> V_124 = V_217 ;
V_51 -> V_249 = type ;
V_51 -> V_251 = 0 ;
V_51 -> V_252 = V_280 ? : 0 ;
V_51 -> V_119 = 0 ;
V_51 -> V_62 = 0 ;
V_51 -> V_126 = 0 ;
F_179 ( & V_51 -> V_222 ) ;
F_182 ( V_23 ) ;
if ( V_217 & V_255 )
V_51 -> V_2 . V_253 = V_254 ;
if ( V_217 & ( V_278 | V_248 ) ) {
if ( V_217 & V_255 &&
! ( V_281 -> V_217 & V_282 ) ) {
V_51 -> V_2 . V_247 = V_289 ;
F_182 ( V_24 ) ;
}
#ifdef F_180
if ( type == V_250 ) {
if ( F_181 ( V_151 ) &&
! F_176 ( V_82 -> V_57 ) ) {
V_51 -> V_2 . V_253 = V_256 ;
V_51 -> V_2 . V_247 = V_289 ;
}
}
#endif
}
F_167 ( V_51 , V_82 -> V_57 , V_153 , V_109 , V_226 , type , 0 ) ;
return V_51 ;
}
struct V_50 * F_120 ( struct V_37 * V_37 , struct V_81 * V_82 )
{
struct V_58 * V_281 = NULL ;
T_11 V_86 = F_207 ( V_82 ) ;
unsigned int V_217 = 0 ;
struct V_152 V_153 ;
struct V_50 * V_51 ;
int V_280 ;
V_153 . V_211 = 0 ;
V_153 . V_226 = NULL ;
V_153 . V_290 = NULL ;
V_280 = V_82 -> V_208 ;
V_82 -> V_209 = V_291 ;
V_82 -> V_207 = V_86 & V_292 ;
V_82 -> V_272 = ( ( V_86 & V_293 ) ?
V_231 : V_97 ) ;
F_58 () ;
if ( V_82 -> V_79 ) {
V_51 = F_205 ( - V_185 ) ;
if ( F_81 ( V_82 -> V_79 ) ||
F_82 ( V_82 -> V_79 ) ||
F_83 ( V_82 -> V_79 ) )
goto V_184;
if ( V_82 -> V_208 == 0 &&
( F_81 ( V_82 -> V_57 ) ||
F_82 ( V_82 -> V_57 ) ) ) {
V_281 = F_208 ( V_37 , V_82 -> V_79 , false ) ;
if ( V_281 == NULL )
goto V_184;
V_82 -> V_208 = V_281 -> V_98 ;
goto V_294;
}
if ( ! ( V_82 -> V_286 & V_295 ) ) {
if ( ! F_208 ( V_37 , V_82 -> V_79 , false ) )
goto V_184;
}
}
if ( V_82 -> V_208 ) {
V_281 = F_209 ( V_37 , V_82 -> V_208 ) ;
V_51 = F_205 ( - V_296 ) ;
if ( V_281 == NULL )
goto V_184;
if ( ! ( V_281 -> V_217 & V_297 ) || ! F_79 ( V_281 ) ) {
V_51 = F_205 ( - V_182 ) ;
goto V_184;
}
if ( F_176 ( V_82 -> V_57 ) ||
F_82 ( V_82 -> V_57 ) ) {
if ( ! V_82 -> V_79 )
V_82 -> V_79 = F_143 ( V_281 , 0 ,
V_231 ) ;
goto V_294;
}
if ( ! V_82 -> V_79 ) {
if ( F_81 ( V_82 -> V_57 ) )
V_82 -> V_79 = F_143 ( V_281 , 0 ,
V_82 -> V_272 ) ;
else if ( ! V_82 -> V_57 )
V_82 -> V_79 = F_143 ( V_281 , 0 ,
V_298 ) ;
}
}
if ( ! V_82 -> V_57 ) {
V_82 -> V_57 = V_82 -> V_79 ;
if ( ! V_82 -> V_57 )
V_82 -> V_57 = V_82 -> V_79 = F_210 ( V_299 ) ;
V_281 = V_37 -> V_224 ;
V_82 -> V_208 = V_291 ;
V_153 . type = V_275 ;
V_217 |= V_255 ;
goto V_294;
}
if ( F_91 ( V_37 , V_82 , & V_153 ) ) {
V_153 . V_226 = NULL ;
V_153 . V_290 = NULL ;
if ( V_82 -> V_208 ) {
if ( V_82 -> V_79 == 0 )
V_82 -> V_79 = F_143 ( V_281 , 0 ,
V_231 ) ;
V_153 . type = V_160 ;
goto V_294;
}
V_51 = F_205 ( - V_182 ) ;
goto V_184;
}
if ( V_153 . type == V_275 ) {
if ( ! V_82 -> V_79 ) {
if ( V_153 . V_226 -> V_300 )
V_82 -> V_79 = V_153 . V_226 -> V_300 ;
else
V_82 -> V_79 = V_82 -> V_57 ;
}
V_281 = V_37 -> V_224 ;
V_82 -> V_208 = V_281 -> V_98 ;
V_217 |= V_255 ;
goto V_294;
}
#ifdef F_198
if ( V_153 . V_226 -> V_268 > 1 && V_82 -> V_208 == 0 )
F_199 ( & V_153 ) ;
else
#endif
if ( ! V_153 . V_284 &&
V_153 . V_290 -> V_301 > 1 &&
V_153 . type == V_160 && ! V_82 -> V_208 )
F_211 ( & V_153 ) ;
if ( ! V_82 -> V_79 )
V_82 -> V_79 = F_142 ( V_37 , V_153 ) ;
V_281 = F_191 ( V_153 ) ;
V_82 -> V_208 = V_281 -> V_98 ;
V_294:
V_51 = F_204 ( & V_153 , V_82 , V_280 , V_281 , V_217 ) ;
V_184:
F_61 () ;
return V_51 ;
}
static struct V_1 * F_212 ( struct V_1 * V_2 , T_1 V_203 )
{
return NULL ;
}
static unsigned int F_213 ( const struct V_1 * V_2 )
{
unsigned int V_193 = F_146 ( V_2 , V_194 ) ;
return V_193 ? : V_2 -> V_53 -> V_193 ;
}
static void F_214 ( struct V_1 * V_2 , struct V_83 * V_84 ,
struct V_55 * V_56 , T_1 V_193 )
{
}
static void F_215 ( struct V_1 * V_2 , struct V_83 * V_84 ,
struct V_55 * V_56 )
{
}
static T_1 * F_216 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
return NULL ;
}
struct V_1 * F_217 ( struct V_37 * V_37 , struct V_1 * V_302 )
{
struct V_50 * V_303 = (struct V_50 * ) V_302 ;
struct V_50 * V_60 ;
V_60 = F_171 ( & V_304 , NULL , 1 , V_305 , 0 ) ;
if ( V_60 ) {
struct V_1 * V_199 = & V_60 -> V_2 ;
V_199 -> V_306 = 1 ;
V_199 -> V_253 = V_307 ;
V_199 -> V_247 = V_308 ;
V_199 -> V_53 = V_303 -> V_2 . V_53 ;
if ( V_199 -> V_53 )
F_164 ( V_199 -> V_53 ) ;
V_60 -> V_251 = V_303 -> V_251 ;
V_60 -> V_252 = V_303 -> V_252 ;
V_60 -> V_119 = V_303 -> V_119 ;
V_60 -> V_52 = F_34 ( V_37 ) ;
V_60 -> V_124 = V_303 -> V_124 ;
V_60 -> V_249 = V_303 -> V_249 ;
V_60 -> V_62 = V_303 -> V_62 ;
V_60 -> V_126 = V_303 -> V_126 ;
F_179 ( & V_60 -> V_222 ) ;
F_218 ( V_199 ) ;
}
F_130 ( V_302 ) ;
return V_60 ? & V_60 -> V_2 : F_205 ( - V_32 ) ;
}
struct V_50 * F_128 ( struct V_37 * V_37 , struct V_81 * V_309 ,
struct V_83 * V_84 )
{
struct V_50 * V_60 = F_120 ( V_37 , V_309 ) ;
if ( F_89 ( V_60 ) )
return V_60 ;
if ( V_309 -> V_283 )
V_60 = (struct V_50 * ) F_219 ( V_37 , & V_60 -> V_2 ,
F_220 ( V_309 ) ,
V_84 , 0 ) ;
return V_60 ;
}
static int F_221 ( struct V_37 * V_37 , T_6 V_2 , T_6 V_28 ,
struct V_81 * V_82 , struct V_55 * V_56 , T_1 V_310 ,
T_1 V_5 , int V_311 , int V_312 , unsigned int V_217 )
{
struct V_50 * V_60 = F_102 ( V_56 ) ;
struct V_313 * V_314 ;
struct V_315 * V_316 ;
unsigned long V_121 = 0 ;
T_1 error ;
T_1 V_317 [ V_318 ] ;
V_316 = F_222 ( V_56 , V_310 , V_5 , V_311 , sizeof( * V_314 ) , V_217 ) ;
if ( V_316 == NULL )
return - V_319 ;
V_314 = F_223 ( V_316 ) ;
V_314 -> V_320 = V_321 ;
V_314 -> V_322 = 32 ;
V_314 -> V_323 = 0 ;
V_314 -> V_324 = V_82 -> V_207 ;
V_314 -> V_325 = V_326 ;
if ( F_224 ( V_56 , V_327 , V_326 ) )
goto V_328;
V_314 -> V_329 = V_60 -> V_249 ;
V_314 -> V_330 = V_97 ;
V_314 -> V_331 = V_332 ;
V_314 -> V_333 = ( V_60 -> V_124 & ~ 0xFFFF ) | V_334 ;
if ( V_60 -> V_124 & V_335 )
V_314 -> V_333 |= V_336 ;
if ( F_225 ( V_56 , V_337 , V_2 ) )
goto V_328;
if ( V_28 ) {
V_314 -> V_323 = 32 ;
if ( F_225 ( V_56 , V_338 , V_28 ) )
goto V_328;
}
if ( V_60 -> V_2 . V_53 &&
F_224 ( V_56 , V_339 , V_60 -> V_2 . V_53 -> V_98 ) )
goto V_328;
#ifdef F_28
if ( V_60 -> V_2 . V_211 &&
F_224 ( V_56 , V_340 , V_60 -> V_2 . V_211 ) )
goto V_328;
#endif
if ( ! F_154 ( V_60 ) &&
V_82 -> V_79 != V_28 ) {
if ( F_225 ( V_56 , V_341 , V_82 -> V_79 ) )
goto V_328;
}
if ( V_60 -> V_126 &&
F_225 ( V_56 , V_342 , V_60 -> V_62 ) )
goto V_328;
V_121 = V_60 -> V_2 . V_121 ;
if ( V_121 ) {
unsigned long V_72 = V_73 ;
if ( F_68 ( V_72 , V_121 ) )
V_121 -= V_72 ;
else
V_121 = 0 ;
}
memcpy ( V_317 , F_226 ( & V_60 -> V_2 ) , sizeof( V_317 ) ) ;
if ( V_60 -> V_119 && V_121 )
V_317 [ V_194 - 1 ] = V_60 -> V_119 ;
if ( F_227 ( V_56 , V_317 ) < 0 )
goto V_328;
if ( V_82 -> V_197 &&
F_224 ( V_56 , V_343 , V_82 -> V_197 ) )
goto V_328;
error = V_60 -> V_2 . error ;
if ( F_154 ( V_60 ) ) {
#ifdef F_180
if ( F_81 ( V_2 ) && ! F_176 ( V_2 ) &&
F_228 ( V_37 , V_344 ) ) {
int V_241 = F_229 ( V_37 , V_56 ,
V_82 -> V_79 , V_82 -> V_57 ,
V_314 , V_312 ) ;
if ( V_241 <= 0 ) {
if ( ! V_312 ) {
if ( V_241 == 0 )
return 0 ;
goto V_328;
} else {
if ( V_241 == - V_319 )
goto V_328;
error = V_241 ;
}
}
} else
#endif
if ( F_224 ( V_56 , V_345 , V_56 -> V_53 -> V_98 ) )
goto V_328;
}
if ( F_230 ( V_56 , & V_60 -> V_2 , 0 , V_121 , error ) < 0 )
goto V_328;
return F_231 ( V_56 , V_316 ) ;
V_328:
F_232 ( V_56 , V_316 ) ;
return - V_319 ;
}
static int F_233 ( struct V_55 * V_346 , struct V_315 * V_316 )
{
struct V_37 * V_37 = F_122 ( V_346 -> V_84 ) ;
struct V_313 * V_347 ;
struct V_348 * V_349 [ V_350 + 1 ] ;
struct V_50 * V_60 = NULL ;
struct V_81 V_82 ;
T_6 V_2 = 0 ;
T_6 V_28 = 0 ;
T_1 V_351 ;
int V_241 ;
int V_88 ;
struct V_55 * V_56 ;
V_241 = F_234 ( V_316 , sizeof( * V_347 ) , V_349 , V_350 , V_352 ) ;
if ( V_241 < 0 )
goto V_353;
V_347 = F_223 ( V_316 ) ;
V_56 = F_235 ( V_354 , V_31 ) ;
if ( V_56 == NULL ) {
V_241 = - V_257 ;
goto V_353;
}
F_236 ( V_56 ) ;
F_237 ( V_56 ) ;
F_39 ( V_56 ) -> V_80 = V_355 ;
F_238 ( V_56 , V_356 + sizeof( struct V_76 ) ) ;
V_28 = V_349 [ V_338 ] ? F_239 ( V_349 [ V_338 ] ) : 0 ;
V_2 = V_349 [ V_337 ] ? F_239 ( V_349 [ V_337 ] ) : 0 ;
V_351 = V_349 [ V_345 ] ? F_240 ( V_349 [ V_345 ] ) : 0 ;
V_88 = V_349 [ V_343 ] ? F_240 ( V_349 [ V_343 ] ) : 0 ;
memset ( & V_82 , 0 , sizeof( V_82 ) ) ;
V_82 . V_57 = V_2 ;
V_82 . V_79 = V_28 ;
V_82 . V_207 = V_347 -> V_324 ;
V_82 . V_208 = V_349 [ V_339 ] ? F_240 ( V_349 [ V_339 ] ) : 0 ;
V_82 . V_197 = V_88 ;
if ( V_351 ) {
struct V_58 * V_53 ;
V_53 = F_241 ( V_37 , V_351 ) ;
if ( V_53 == NULL ) {
V_241 = - V_296 ;
goto V_357;
}
V_56 -> V_80 = F_50 ( V_242 ) ;
V_56 -> V_53 = V_53 ;
V_56 -> V_88 = V_88 ;
F_242 () ;
V_241 = F_243 ( V_56 , V_2 , V_28 , V_347 -> V_324 , V_53 ) ;
F_244 () ;
V_60 = F_102 ( V_56 ) ;
if ( V_241 == 0 && V_60 -> V_2 . error )
V_241 = - V_60 -> V_2 . error ;
} else {
V_60 = F_245 ( V_37 , & V_82 ) ;
V_241 = 0 ;
if ( F_89 ( V_60 ) )
V_241 = F_246 ( V_60 ) ;
}
if ( V_241 )
goto V_357;
F_183 ( V_56 , & V_60 -> V_2 ) ;
if ( V_347 -> V_333 & V_336 )
V_60 -> V_124 |= V_335 ;
V_241 = F_221 ( V_37 , V_2 , V_28 , & V_82 , V_56 ,
F_247 ( V_346 ) . V_310 , V_316 -> V_358 ,
V_359 , 0 , 0 ) ;
if ( V_241 <= 0 )
goto V_357;
V_241 = F_248 ( V_56 , V_37 , F_247 ( V_346 ) . V_310 ) ;
V_353:
return V_241 ;
V_357:
F_114 ( V_56 ) ;
goto V_353;
}
void F_249 ( struct V_150 * V_151 )
{
F_36 ( F_35 ( V_151 -> V_53 ) ) ;
}
static int F_250 ( struct V_360 * V_361 , int V_362 ,
void T_12 * V_363 ,
T_13 * V_364 , T_2 * V_365 )
{
struct V_37 * V_37 = (struct V_37 * ) V_361 -> V_366 ;
if ( V_362 ) {
F_36 ( V_37 ) ;
F_251 ( V_37 ) ;
return 0 ;
}
return - V_185 ;
}
static T_3 int F_252 ( struct V_37 * V_37 )
{
struct V_360 * V_367 ;
V_367 = V_368 ;
if ( ! F_253 ( V_37 , & V_369 ) ) {
V_367 = F_254 ( V_367 , sizeof( V_368 ) , V_31 ) ;
if ( V_367 == NULL )
goto V_370;
if ( V_37 -> V_371 != & V_372 )
V_367 [ 0 ] . V_373 = NULL ;
}
V_367 [ 0 ] . V_366 = V_37 ;
V_37 -> V_170 . V_374 = F_255 ( V_37 , L_19 , V_367 ) ;
if ( V_37 -> V_170 . V_374 == NULL )
goto V_375;
return 0 ;
V_375:
if ( V_367 != V_368 )
F_23 ( V_367 ) ;
V_370:
return - V_32 ;
}
static T_4 void F_256 ( struct V_37 * V_37 )
{
struct V_360 * V_367 ;
V_367 = V_37 -> V_170 . V_374 -> V_376 ;
F_257 ( V_37 -> V_170 . V_374 ) ;
F_258 ( V_367 == V_368 ) ;
F_23 ( V_367 ) ;
}
static T_3 int F_259 ( struct V_37 * V_37 )
{
F_260 ( & V_37 -> V_170 . V_52 , 0 ) ;
F_260 ( & V_37 -> V_138 , 0 ) ;
F_261 ( & V_37 -> V_170 . V_377 ,
sizeof( V_37 -> V_170 . V_377 ) ) ;
return 0 ;
}
static int T_3 F_262 ( struct V_37 * V_37 )
{
struct V_378 * V_379 = F_263 ( sizeof( * V_379 ) , V_31 ) ;
if ( ! V_379 )
return - V_32 ;
F_264 ( V_379 ) ;
V_37 -> V_170 . V_171 = V_379 ;
return 0 ;
}
static void T_4 F_265 ( struct V_37 * V_37 )
{
struct V_378 * V_379 = V_37 -> V_170 . V_171 ;
V_37 -> V_170 . V_171 = NULL ;
F_266 ( V_379 ) ;
F_23 ( V_379 ) ;
}
int T_5 F_267 ( void )
{
int V_380 = 0 ;
V_69 = F_263 ( V_70 * sizeof( * V_69 ) , V_31 ) ;
if ( ! V_69 )
F_268 ( L_20 ) ;
F_269 ( V_69 , V_70 * sizeof( * V_69 ) ) ;
#ifdef F_28
V_27 = F_270 ( 256 * sizeof( struct V_27 ) , F_271 ( struct V_27 ) ) ;
if ( ! V_27 )
F_268 ( L_21 ) ;
#endif
V_16 . V_381 =
F_272 ( L_22 , sizeof( struct V_50 ) , 0 ,
V_382 | V_383 , NULL ) ;
V_304 . V_381 = V_16 . V_381 ;
if ( F_273 ( & V_16 ) < 0 )
F_268 ( L_23 ) ;
if ( F_273 ( & V_304 ) < 0 )
F_268 ( L_24 ) ;
V_16 . V_384 = ~ 0 ;
V_385 = V_386 ;
F_274 () ;
F_275 () ;
if ( F_31 () )
F_276 ( L_25 ) ;
#ifdef F_277
F_278 () ;
F_279 () ;
#endif
F_280 ( V_387 , V_388 , F_233 , NULL , NULL ) ;
#ifdef F_281
F_32 ( & V_389 ) ;
#endif
F_32 ( & V_390 ) ;
F_32 ( & V_391 ) ;
return V_380 ;
}
void T_5 F_282 ( void )
{
F_255 ( & V_369 , L_19 , V_392 ) ;
}
