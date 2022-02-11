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
static void F_42 ( struct V_65 * V_66 )
{
static F_43 ( V_67 ) ;
static T_1 V_68 ;
T_1 V_69 ;
F_44 ( & V_67 ) ;
V_69 = F_45 ( ( V_63 T_6 ) V_68 ^ V_66 -> V_57 ) ;
V_66 -> V_70 = F_46 ( V_69 & 0xFFFF ) ;
V_68 = V_69 ;
F_47 ( & V_67 ) ;
}
void F_48 ( struct V_65 * V_66 , struct V_1 * V_2 , int V_71 )
{
struct V_37 * V_37 = F_35 ( V_2 -> V_53 ) ;
struct V_72 * V_73 ;
V_73 = F_49 ( V_37 -> V_74 . V_75 , V_66 -> V_57 , 1 ) ;
if ( V_73 ) {
V_66 -> V_70 = F_46 ( F_50 ( V_73 , V_71 ) ) ;
F_51 ( V_73 ) ;
return;
}
F_42 ( V_66 ) ;
}
static void F_52 ( struct V_76 * V_77 , const struct V_78 * V_79 ,
const struct V_65 * V_66 ,
int V_80 , T_7 V_81 ,
T_7 V_82 , T_1 V_83 , int V_84 )
{
if ( V_79 ) {
const struct V_85 * V_86 = F_53 ( V_79 ) ;
V_80 = V_79 -> V_87 ;
V_83 = V_79 -> V_88 ;
V_81 = F_54 ( V_79 ) ;
V_82 = V_86 -> V_89 ? V_90 : V_79 -> V_91 ;
}
F_55 ( V_77 , V_80 , V_83 , V_81 ,
V_92 , V_82 ,
V_84 ,
V_66 -> V_57 , V_66 -> V_93 , 0 , 0 ) ;
}
static void F_56 ( struct V_76 * V_77 , const struct V_55 * V_56 ,
const struct V_78 * V_79 )
{
const struct V_65 * V_66 = F_39 ( V_56 ) ;
int V_80 = V_56 -> V_53 -> V_94 ;
T_7 V_81 = F_57 ( V_66 -> V_81 ) ;
T_7 V_82 = V_66 -> V_95 ;
T_1 V_83 = V_56 -> V_83 ;
F_52 ( V_77 , V_79 , V_66 , V_80 , V_81 , V_82 , V_83 , 0 ) ;
}
static void F_58 ( struct V_76 * V_77 , const struct V_78 * V_79 )
{
const struct V_85 * V_86 = F_53 ( V_79 ) ;
const struct V_96 * V_97 ;
T_6 V_57 = V_86 -> V_98 ;
F_59 () ;
V_97 = F_60 ( V_86 -> V_97 ) ;
if ( V_97 && V_97 -> V_99 . V_100 )
V_57 = V_97 -> V_99 . V_101 ;
F_55 ( V_77 , V_79 -> V_87 , V_79 -> V_88 ,
F_54 ( V_79 ) , V_92 ,
V_86 -> V_89 ? V_90 : V_79 -> V_91 ,
F_61 ( V_79 ) ,
V_57 , V_86 -> V_102 , 0 , 0 ) ;
F_62 () ;
}
static void F_63 ( struct V_76 * V_77 , const struct V_78 * V_79 ,
const struct V_55 * V_56 )
{
if ( V_56 )
F_56 ( V_77 , V_56 , V_79 ) ;
else
F_58 ( V_77 , V_79 ) ;
}
static inline void F_64 ( struct V_50 * V_60 )
{
F_65 ( & V_60 -> V_2 . V_103 , V_104 ) ;
}
static void F_66 ( struct V_105 * V_106 )
{
struct V_50 * V_60 ;
V_60 = F_60 ( V_106 -> V_107 ) ;
if ( V_60 ) {
F_67 ( V_106 -> V_107 , NULL ) ;
F_64 ( V_60 ) ;
}
V_60 = F_60 ( V_106 -> V_108 ) ;
if ( V_60 ) {
F_67 ( V_106 -> V_108 , NULL ) ;
F_64 ( V_60 ) ;
}
}
static struct V_105 * F_68 ( struct V_109 * V_110 )
{
struct V_105 * V_106 , * V_111 ;
V_111 = F_60 ( V_110 -> V_112 ) ;
for ( V_106 = F_60 ( V_111 -> V_113 ) ; V_106 ;
V_106 = F_60 ( V_106 -> V_113 ) ) {
if ( F_69 ( V_106 -> V_114 , V_111 -> V_114 ) )
V_111 = V_106 ;
}
F_66 ( V_111 ) ;
return V_111 ;
}
static inline T_1 F_70 ( T_6 V_57 )
{
T_1 V_115 ;
V_115 = ( V_63 T_1 ) V_57 ;
V_115 ^= ( V_115 >> 11 ) ^ ( V_115 >> 22 ) ;
return V_115 & ( V_116 - 1 ) ;
}
static void F_71 ( struct V_50 * V_60 , struct V_105 * V_106 )
{
V_60 -> V_117 = V_106 -> V_118 ;
V_60 -> V_2 . V_119 = V_106 -> V_120 ;
if ( V_106 -> V_121 ) {
V_60 -> V_122 |= V_123 ;
V_60 -> V_62 = V_106 -> V_121 ;
V_60 -> V_124 = 1 ;
}
}
static void F_72 ( struct V_125 * V_126 , T_6 V_57 , T_6 V_127 ,
T_1 V_128 , unsigned long V_119 )
{
struct V_109 * V_110 ;
struct V_105 * V_106 ;
struct V_50 * V_60 ;
unsigned int V_29 ;
int V_129 ;
T_1 V_115 = F_70 ( V_57 ) ;
F_44 ( & V_130 ) ;
V_110 = V_126 -> V_131 ;
if ( ! V_110 ) {
V_110 = F_73 ( V_116 * sizeof( * V_110 ) , V_132 ) ;
if ( ! V_110 )
goto V_133;
V_126 -> V_131 = V_110 ;
}
V_110 += V_115 ;
V_129 = 0 ;
for ( V_106 = F_60 ( V_110 -> V_112 ) ; V_106 ;
V_106 = F_60 ( V_106 -> V_113 ) ) {
if ( V_106 -> V_134 == V_57 )
break;
V_129 ++ ;
}
if ( V_106 ) {
if ( V_127 )
V_106 -> V_121 = V_127 ;
if ( V_128 ) {
V_106 -> V_118 = V_128 ;
V_106 -> V_120 = F_74 ( 1UL , V_119 ) ;
}
V_60 = F_60 ( V_106 -> V_107 ) ;
if ( V_60 )
F_71 ( V_60 , V_106 ) ;
V_60 = F_60 ( V_106 -> V_108 ) ;
if ( V_60 )
F_71 ( V_60 , V_106 ) ;
} else {
if ( V_129 > V_135 )
V_106 = F_68 ( V_110 ) ;
else {
V_106 = F_73 ( sizeof( * V_106 ) , V_132 ) ;
if ( ! V_106 )
goto V_133;
V_106 -> V_113 = V_110 -> V_112 ;
F_75 ( V_110 -> V_112 , V_106 ) ;
}
V_106 -> V_136 = V_136 ( F_35 ( V_126 -> V_137 ) ) ;
V_106 -> V_134 = V_57 ;
V_106 -> V_121 = V_127 ;
V_106 -> V_118 = V_128 ;
V_106 -> V_120 = V_119 ;
V_60 = F_60 ( V_126 -> V_138 ) ;
if ( V_60 )
V_60 -> V_2 . V_139 = V_140 ;
F_20 (i) {
struct V_50 T_8 * * V_141 ;
V_141 = F_21 ( V_126 -> V_142 , V_29 ) ;
V_60 = F_60 ( * V_141 ) ;
if ( V_60 )
V_60 -> V_2 . V_139 = V_140 ;
}
}
V_106 -> V_114 = V_143 ;
V_133:
F_47 ( & V_130 ) ;
}
static void F_76 ( struct V_50 * V_60 , struct V_55 * V_56 , struct V_76 * V_77 ,
bool V_144 )
{
T_6 V_145 = F_77 ( V_56 ) -> V_146 . V_147 ;
T_6 V_148 = F_39 ( V_56 ) -> V_93 ;
struct V_58 * V_53 = V_56 -> V_53 ;
struct V_149 * V_150 ;
struct V_151 V_152 ;
struct V_54 * V_61 ;
struct V_37 * V_37 ;
switch ( F_77 ( V_56 ) -> V_153 & 7 ) {
case V_154 :
case V_155 :
case V_156 :
case V_157 :
break;
default:
return;
}
if ( V_60 -> V_62 != V_148 )
return;
V_150 = F_78 ( V_53 ) ;
if ( ! V_150 )
return;
V_37 = F_35 ( V_53 ) ;
if ( V_145 == V_148 || ! F_79 ( V_150 ) ||
F_80 ( V_145 ) || F_81 ( V_145 ) ||
F_82 ( V_145 ) )
goto V_158;
if ( ! F_83 ( V_150 ) ) {
if ( ! F_84 ( V_150 , V_145 , V_148 ) )
goto V_158;
if ( F_85 ( V_150 ) && F_86 ( V_145 , V_53 ) )
goto V_158;
} else {
if ( F_87 ( V_37 , V_145 ) != V_159 )
goto V_158;
}
V_61 = F_38 ( & V_60 -> V_2 , NULL , & V_145 ) ;
if ( V_61 ) {
if ( ! ( V_61 -> V_160 & V_161 ) ) {
F_88 ( V_61 , NULL ) ;
} else {
if ( F_89 ( V_37 , V_77 , & V_152 ) == 0 ) {
struct V_125 * V_126 = & F_90 ( V_152 ) ;
F_72 ( V_126 , V_77 -> V_57 , V_145 ,
0 , 0 ) ;
}
if ( V_144 )
V_60 -> V_2 . V_139 = V_140 ;
F_91 ( V_162 , V_61 ) ;
}
F_92 ( V_61 ) ;
}
return;
V_158:
#ifdef F_93
if ( F_94 ( V_150 ) ) {
const struct V_65 * V_66 = ( const struct V_65 * ) V_56 -> V_163 ;
T_6 V_57 = V_66 -> V_57 ;
T_6 V_93 = V_66 -> V_93 ;
F_95 ( L_10
L_11 ,
& V_148 , V_53 -> V_164 , & V_145 ,
& V_93 , & V_57 ) ;
}
#endif
;
}
static void F_96 ( struct V_1 * V_2 , struct V_78 * V_79 , struct V_55 * V_56 )
{
struct V_50 * V_60 ;
struct V_76 V_77 ;
const struct V_65 * V_66 = ( const struct V_65 * ) V_56 -> V_163 ;
int V_80 = V_56 -> V_53 -> V_94 ;
T_7 V_81 = F_57 ( V_66 -> V_81 ) ;
T_7 V_82 = V_66 -> V_95 ;
T_1 V_83 = V_56 -> V_83 ;
V_60 = (struct V_50 * ) V_2 ;
F_52 ( & V_77 , V_79 , V_66 , V_80 , V_81 , V_82 , V_83 , 0 ) ;
F_76 ( V_60 , V_56 , & V_77 , true ) ;
}
static struct V_1 * F_97 ( struct V_1 * V_2 )
{
struct V_50 * V_60 = (struct V_50 * ) V_2 ;
struct V_1 * V_165 = V_2 ;
if ( V_60 ) {
if ( V_2 -> V_139 > 0 ) {
F_98 ( V_60 ) ;
V_165 = NULL ;
} else if ( ( V_60 -> V_122 & V_123 ) ||
V_60 -> V_2 . V_119 ) {
F_98 ( V_60 ) ;
V_165 = NULL ;
}
}
return V_165 ;
}
void F_99 ( struct V_55 * V_56 )
{
struct V_50 * V_60 = F_100 ( V_56 ) ;
struct V_149 * V_150 ;
struct V_72 * V_73 ;
struct V_37 * V_37 ;
int V_166 ;
F_59 () ;
V_150 = F_78 ( V_60 -> V_2 . V_53 ) ;
if ( ! V_150 || ! F_101 ( V_150 ) ) {
F_62 () ;
return;
}
V_166 = F_94 ( V_150 ) ;
F_62 () ;
V_37 = F_35 ( V_60 -> V_2 . V_53 ) ;
V_73 = F_49 ( V_37 -> V_74 . V_75 , F_39 ( V_56 ) -> V_93 , 1 ) ;
if ( ! V_73 ) {
F_102 ( V_56 , V_167 , V_156 ,
F_103 ( V_60 , F_39 ( V_56 ) -> V_57 ) ) ;
return;
}
if ( F_104 ( V_143 , V_73 -> V_168 + V_169 ) )
V_73 -> V_170 = 0 ;
if ( V_73 -> V_170 >= V_171 ) {
V_73 -> V_168 = V_143 ;
goto V_172;
}
if ( V_73 -> V_170 == 0 ||
F_104 ( V_143 ,
( V_73 -> V_168 +
( V_173 << V_73 -> V_170 ) ) ) ) {
T_6 V_127 = F_103 ( V_60 , F_39 ( V_56 ) -> V_57 ) ;
F_102 ( V_56 , V_167 , V_156 , V_127 ) ;
V_73 -> V_168 = V_143 ;
++ V_73 -> V_170 ;
#ifdef F_93
if ( V_166 &&
V_73 -> V_170 == V_171 )
F_105 ( L_12 ,
& F_39 ( V_56 ) -> V_93 , F_106 ( V_56 ) ,
& F_39 ( V_56 ) -> V_57 , & V_127 ) ;
#endif
}
V_172:
F_51 ( V_73 ) ;
}
static int F_107 ( struct V_55 * V_56 )
{
struct V_149 * V_150 = F_78 ( V_56 -> V_53 ) ;
struct V_50 * V_60 = F_100 ( V_56 ) ;
struct V_72 * V_73 ;
unsigned long V_174 ;
struct V_37 * V_37 ;
bool V_175 ;
int V_153 ;
V_37 = F_35 ( V_60 -> V_2 . V_53 ) ;
if ( ! F_108 ( V_150 ) ) {
switch ( V_60 -> V_2 . error ) {
case V_176 :
F_109 ( V_37 , V_177 ) ;
break;
case V_178 :
F_109 ( V_37 , V_179 ) ;
break;
}
goto V_180;
}
switch ( V_60 -> V_2 . error ) {
case V_181 :
default:
goto V_180;
case V_176 :
V_153 = V_182 ;
break;
case V_178 :
V_153 = V_183 ;
F_109 ( V_37 , V_179 ) ;
break;
case V_184 :
V_153 = V_185 ;
break;
}
V_73 = F_49 ( V_37 -> V_74 . V_75 , F_39 ( V_56 ) -> V_93 , 1 ) ;
V_175 = true ;
if ( V_73 ) {
V_174 = V_143 ;
V_73 -> V_170 += V_174 - V_73 -> V_168 ;
if ( V_73 -> V_170 > V_186 )
V_73 -> V_170 = V_186 ;
V_73 -> V_168 = V_174 ;
if ( V_73 -> V_170 >= V_187 )
V_73 -> V_170 -= V_187 ;
else
V_175 = false ;
F_51 ( V_73 ) ;
}
if ( V_175 )
F_102 ( V_56 , V_188 , V_153 , 0 ) ;
V_180: F_110 ( V_56 ) ;
return 0 ;
}
static void F_111 ( struct V_50 * V_60 , struct V_76 * V_77 , T_1 V_189 )
{
struct V_1 * V_2 = & V_60 -> V_2 ;
struct V_151 V_152 ;
if ( F_112 ( V_2 , V_190 ) )
return;
if ( V_2 -> V_53 -> V_189 < V_189 )
return;
if ( V_189 < V_191 )
V_189 = V_191 ;
if ( V_60 -> V_117 == V_189 &&
F_69 ( V_143 , V_2 -> V_119 - V_192 / 2 ) )
return;
F_59 () ;
if ( F_89 ( F_35 ( V_2 -> V_53 ) , V_77 , & V_152 ) == 0 ) {
struct V_125 * V_126 = & F_90 ( V_152 ) ;
F_72 ( V_126 , V_77 -> V_57 , 0 , V_189 ,
V_143 + V_192 ) ;
}
F_62 () ;
}
static void F_113 ( struct V_1 * V_2 , struct V_78 * V_79 ,
struct V_55 * V_56 , T_1 V_189 )
{
struct V_50 * V_60 = (struct V_50 * ) V_2 ;
struct V_76 V_77 ;
F_63 ( & V_77 , V_79 , V_56 ) ;
F_111 ( V_60 , & V_77 , V_189 ) ;
}
void F_114 ( struct V_55 * V_56 , struct V_37 * V_37 , T_1 V_189 ,
int V_80 , T_1 V_83 , T_7 V_95 , int V_84 )
{
const struct V_65 * V_66 = ( const struct V_65 * ) V_56 -> V_163 ;
struct V_76 V_77 ;
struct V_50 * V_60 ;
F_52 ( & V_77 , NULL , V_66 , V_80 ,
F_57 ( V_66 -> V_81 ) , V_95 , V_83 , V_84 ) ;
V_60 = F_115 ( V_37 , & V_77 ) ;
if ( ! F_116 ( V_60 ) ) {
F_111 ( V_60 , & V_77 , V_189 ) ;
F_98 ( V_60 ) ;
}
}
static void F_117 ( struct V_55 * V_56 , struct V_78 * V_79 , T_1 V_189 )
{
const struct V_65 * V_66 = ( const struct V_65 * ) V_56 -> V_163 ;
struct V_76 V_77 ;
struct V_50 * V_60 ;
F_52 ( & V_77 , V_79 , V_66 , 0 , 0 , 0 , 0 , 0 ) ;
V_60 = F_115 ( F_118 ( V_79 ) , & V_77 ) ;
if ( ! F_116 ( V_60 ) ) {
F_111 ( V_60 , & V_77 , V_189 ) ;
F_98 ( V_60 ) ;
}
}
void F_119 ( struct V_55 * V_56 , struct V_78 * V_79 , T_1 V_189 )
{
const struct V_65 * V_66 = ( const struct V_65 * ) V_56 -> V_163 ;
struct V_76 V_77 ;
struct V_50 * V_60 ;
struct V_1 * V_2 ;
bool V_193 = false ;
F_120 ( V_79 ) ;
if ( ! F_121 ( V_79 ) )
goto V_180;
V_60 = (struct V_50 * ) F_122 ( V_79 ) ;
if ( F_123 ( V_79 ) || ! V_60 ) {
F_117 ( V_56 , V_79 , V_189 ) ;
goto V_180;
}
F_52 ( & V_77 , V_79 , V_66 , 0 , 0 , 0 , 0 , 0 ) ;
if ( ! F_124 ( V_79 , 0 ) ) {
V_60 = F_125 ( F_118 ( V_79 ) , & V_77 , V_79 ) ;
if ( F_116 ( V_60 ) )
goto V_180;
V_193 = true ;
}
F_111 ( (struct V_50 * ) V_60 -> V_2 . V_194 , & V_77 , V_189 ) ;
V_2 = F_126 ( & V_60 -> V_2 , 0 ) ;
if ( ! V_2 ) {
if ( V_193 )
F_127 ( & V_60 -> V_2 ) ;
V_60 = F_125 ( F_118 ( V_79 ) , & V_77 , V_79 ) ;
if ( F_116 ( V_60 ) )
goto V_180;
V_193 = true ;
}
if ( V_193 )
F_128 ( V_79 , & V_60 -> V_2 ) ;
V_180:
F_129 ( V_79 ) ;
}
void F_130 ( struct V_55 * V_56 , struct V_37 * V_37 ,
int V_80 , T_1 V_83 , T_7 V_95 , int V_84 )
{
const struct V_65 * V_66 = ( const struct V_65 * ) V_56 -> V_163 ;
struct V_76 V_77 ;
struct V_50 * V_60 ;
F_52 ( & V_77 , NULL , V_66 , V_80 ,
F_57 ( V_66 -> V_81 ) , V_95 , V_83 , V_84 ) ;
V_60 = F_115 ( V_37 , & V_77 ) ;
if ( ! F_116 ( V_60 ) ) {
F_76 ( V_60 , V_56 , & V_77 , false ) ;
F_98 ( V_60 ) ;
}
}
void F_131 ( struct V_55 * V_56 , struct V_78 * V_79 )
{
const struct V_65 * V_66 = ( const struct V_65 * ) V_56 -> V_163 ;
struct V_76 V_77 ;
struct V_50 * V_60 ;
F_52 ( & V_77 , V_79 , V_66 , 0 , 0 , 0 , 0 , 0 ) ;
V_60 = F_115 ( F_118 ( V_79 ) , & V_77 ) ;
if ( ! F_116 ( V_60 ) ) {
F_76 ( V_60 , V_56 , & V_77 , false ) ;
F_98 ( V_60 ) ;
}
}
static struct V_1 * F_132 ( struct V_1 * V_2 , T_1 V_195 )
{
struct V_50 * V_60 = (struct V_50 * ) V_2 ;
if ( V_2 -> V_139 != V_196 || F_33 ( V_60 ) )
return NULL ;
return V_2 ;
}
static void F_133 ( struct V_55 * V_56 )
{
struct V_50 * V_60 ;
F_102 ( V_56 , V_188 , V_182 , 0 ) ;
V_60 = F_100 ( V_56 ) ;
if ( V_60 )
F_134 ( & V_60 -> V_2 , 0 ) ;
}
static int F_135 ( struct V_78 * V_79 , struct V_55 * V_56 )
{
F_136 ( L_13 ,
V_197 , & F_39 ( V_56 ) -> V_93 , & F_39 ( V_56 ) -> V_57 ,
V_56 -> V_53 ? V_56 -> V_53 -> V_164 : L_14 ) ;
F_110 ( V_56 ) ;
F_2 ( 1 ) ;
return 0 ;
}
void F_137 ( T_7 * V_198 , struct V_55 * V_56 , struct V_50 * V_60 )
{
T_6 V_28 ;
if ( F_138 ( V_60 ) )
V_28 = F_39 ( V_56 ) -> V_93 ;
else {
struct V_151 V_152 ;
struct V_76 V_77 ;
struct V_65 * V_66 ;
V_66 = F_39 ( V_56 ) ;
memset ( & V_77 , 0 , sizeof( V_77 ) ) ;
V_77 . V_57 = V_66 -> V_57 ;
V_77 . V_93 = V_66 -> V_93 ;
V_77 . V_199 = F_57 ( V_66 -> V_81 ) ;
V_77 . V_200 = V_60 -> V_2 . V_53 -> V_94 ;
V_77 . V_201 = V_56 -> V_53 -> V_94 ;
V_77 . V_202 = V_56 -> V_83 ;
F_59 () ;
if ( F_89 ( F_35 ( V_60 -> V_2 . V_53 ) , & V_77 , & V_152 ) == 0 )
V_28 = F_139 ( F_35 ( V_60 -> V_2 . V_53 ) , V_152 ) ;
else
V_28 = F_140 ( V_60 -> V_2 . V_53 ,
F_103 ( V_60 , V_66 -> V_57 ) ,
V_92 ) ;
F_62 () ;
}
memcpy ( V_198 , & V_28 , 4 ) ;
}
static void F_141 ( struct V_50 * V_60 , T_1 V_203 )
{
if ( ! ( V_60 -> V_2 . V_204 & 0xFFFF ) )
V_60 -> V_2 . V_204 |= V_203 & 0xFFFF ;
if ( ! ( V_60 -> V_2 . V_204 & 0xFFFF0000 ) )
V_60 -> V_2 . V_204 |= V_203 & 0xFFFF0000 ;
}
static unsigned int F_142 ( const struct V_1 * V_2 )
{
unsigned int V_205 = F_143 ( V_2 , V_206 ) ;
if ( V_205 == 0 ) {
V_205 = F_144 (unsigned int, dst->dev->mtu - 40 ,
ip_rt_min_advmss) ;
if ( V_205 > 65535 - 40 )
V_205 = 65535 - 40 ;
}
return V_205 ;
}
static unsigned int F_145 ( const struct V_1 * V_2 )
{
const struct V_50 * V_60 = ( const struct V_50 * ) V_2 ;
unsigned int V_189 = V_60 -> V_117 ;
if ( ! V_189 || F_146 ( V_143 , V_60 -> V_2 . V_119 ) )
V_189 = F_143 ( V_2 , V_190 ) ;
if ( V_189 )
return V_189 ;
V_189 = V_2 -> V_53 -> V_189 ;
if ( F_147 ( F_112 ( V_2 , V_190 ) ) ) {
if ( V_60 -> V_124 && V_189 > 576 )
V_189 = 576 ;
}
return F_148 (unsigned int, mtu, IP_MAX_MTU) ;
}
static struct V_105 * F_149 ( struct V_125 * V_126 , T_6 V_57 )
{
struct V_109 * V_110 = V_126 -> V_131 ;
struct V_105 * V_106 ;
T_1 V_115 ;
if ( ! V_110 )
return NULL ;
V_115 = F_70 ( V_57 ) ;
for ( V_106 = F_60 ( V_110 [ V_115 ] . V_112 ) ; V_106 ;
V_106 = F_60 ( V_106 -> V_113 ) ) {
if ( V_106 -> V_134 == V_57 )
return V_106 ;
}
return NULL ;
}
static bool F_150 ( struct V_50 * V_60 , struct V_105 * V_106 ,
T_6 V_57 )
{
bool V_165 = false ;
F_44 ( & V_130 ) ;
if ( V_57 == V_106 -> V_134 ) {
struct V_50 T_8 * * V_207 ;
struct V_50 * V_208 ;
int V_209 = V_136 ( F_35 ( V_60 -> V_2 . V_53 ) ) ;
if ( F_151 ( V_60 ) )
V_207 = & V_106 -> V_107 ;
else
V_207 = & V_106 -> V_108 ;
V_208 = F_60 ( * V_207 ) ;
if ( V_106 -> V_136 != V_209 ) {
V_106 -> V_136 = V_209 ;
V_106 -> V_121 = 0 ;
V_106 -> V_118 = 0 ;
V_106 -> V_120 = 0 ;
F_66 ( V_106 ) ;
V_208 = NULL ;
}
F_71 ( V_60 , V_106 ) ;
if ( ! V_60 -> V_62 )
V_60 -> V_62 = V_57 ;
if ( ! ( V_60 -> V_2 . V_210 & V_211 ) ) {
F_75 ( * V_207 , V_60 ) ;
if ( V_208 )
F_64 ( V_208 ) ;
V_165 = true ;
}
V_106 -> V_114 = V_143 ;
}
F_47 ( & V_130 ) ;
return V_165 ;
}
static bool F_152 ( struct V_125 * V_126 , struct V_50 * V_60 )
{
struct V_50 * V_208 , * V_212 , * * V_213 ;
bool V_165 = true ;
if ( F_151 ( V_60 ) ) {
V_213 = (struct V_50 * * ) & V_126 -> V_138 ;
} else {
V_213 = (struct V_50 * * ) F_153 ( V_126 -> V_142 ) ;
}
V_208 = * V_213 ;
V_212 = F_154 ( V_213 , V_208 , V_60 ) ;
if ( V_212 == V_208 ) {
if ( V_208 )
F_64 ( V_208 ) ;
} else
V_165 = false ;
return V_165 ;
}
static void F_155 ( struct V_50 * V_60 )
{
F_44 ( & V_214 ) ;
F_156 ( & V_60 -> V_215 , & V_216 ) ;
F_47 ( & V_214 ) ;
}
static void F_157 ( struct V_1 * V_2 )
{
struct V_50 * V_60 = (struct V_50 * ) V_2 ;
if ( ! F_158 ( & V_60 -> V_215 ) ) {
F_44 ( & V_214 ) ;
F_159 ( & V_60 -> V_215 ) ;
F_47 ( & V_214 ) ;
}
}
void F_160 ( struct V_58 * V_53 )
{
if ( ! F_158 ( & V_216 ) ) {
struct V_37 * V_37 = F_35 ( V_53 ) ;
struct V_50 * V_60 ;
F_44 ( & V_214 ) ;
F_161 (rt, &rt_uncached_list, rt_uncached) {
if ( V_60 -> V_2 . V_53 != V_53 )
continue;
V_60 -> V_2 . V_53 = V_37 -> V_217 ;
F_162 ( V_60 -> V_2 . V_53 ) ;
F_163 ( V_53 ) ;
}
F_47 ( & V_214 ) ;
}
}
static bool F_164 ( const struct V_50 * V_60 )
{
return V_60 &&
V_60 -> V_2 . V_139 == V_196 &&
! F_33 ( V_60 ) ;
}
static void F_165 ( struct V_50 * V_60 , T_6 V_57 ,
const struct V_151 * V_152 ,
struct V_105 * V_106 ,
struct V_218 * V_219 , T_9 type , T_1 V_220 )
{
bool V_221 = false ;
if ( V_219 ) {
struct V_125 * V_126 = & F_90 ( * V_152 ) ;
if ( V_126 -> V_222 && V_126 -> V_223 == V_224 ) {
V_60 -> V_62 = V_126 -> V_222 ;
V_60 -> V_124 = 1 ;
}
F_166 ( & V_60 -> V_2 , V_219 -> V_225 , true ) ;
#ifdef F_28
V_60 -> V_2 . V_204 = V_126 -> V_226 ;
#endif
if ( F_147 ( V_106 ) )
V_221 = F_150 ( V_60 , V_106 , V_57 ) ;
else if ( ! ( V_60 -> V_2 . V_210 & V_211 ) )
V_221 = F_152 ( V_126 , V_60 ) ;
if ( F_147 ( ! V_221 ) ) {
V_60 -> V_2 . V_210 |= V_211 ;
if ( ! V_60 -> V_62 )
V_60 -> V_62 = V_57 ;
F_155 ( V_60 ) ;
}
} else
F_155 ( V_60 ) ;
#ifdef F_28
#ifdef F_167
F_141 ( V_60 , V_152 -> V_204 ) ;
#endif
F_141 ( V_60 , V_220 ) ;
#endif
}
static struct V_50 * F_168 ( struct V_58 * V_53 ,
bool V_227 , bool V_228 , bool V_229 )
{
return F_169 ( & V_16 , V_53 , 1 , V_196 ,
( V_229 ? 0 : ( V_230 | V_211 ) ) |
( V_227 ? V_231 : 0 ) |
( V_228 ? V_232 : 0 ) ) ;
}
static int F_170 ( struct V_55 * V_56 , T_6 V_57 , T_6 V_93 ,
T_7 V_81 , struct V_58 * V_53 , int V_233 )
{
struct V_50 * V_51 ;
struct V_149 * V_150 = F_78 ( V_53 ) ;
T_1 V_220 = 0 ;
int V_234 ;
if ( V_150 == NULL )
return - V_181 ;
if ( F_80 ( V_93 ) || F_81 ( V_93 ) ||
V_56 -> V_95 != F_46 ( V_235 ) )
goto V_236;
if ( F_171 ( ! F_172 ( V_150 ) ) )
if ( F_173 ( V_93 ) )
goto V_236;
if ( F_82 ( V_93 ) ) {
if ( ! F_174 ( V_57 ) )
goto V_236;
} else {
V_234 = F_175 ( V_56 , V_93 , 0 , V_81 , 0 , V_53 ,
V_150 , & V_220 ) ;
if ( V_234 < 0 )
goto V_237;
}
V_51 = F_168 ( F_35 ( V_53 ) -> V_217 ,
F_176 ( V_150 , V_238 ) , false , false ) ;
if ( ! V_51 )
goto V_239;
#ifdef F_28
V_51 -> V_2 . V_204 = V_220 ;
#endif
V_51 -> V_2 . V_240 = F_135 ;
V_51 -> V_52 = F_34 ( F_35 ( V_53 ) ) ;
V_51 -> V_122 = V_241 ;
V_51 -> V_242 = V_243 ;
V_51 -> V_244 = 1 ;
V_51 -> V_245 = 0 ;
V_51 -> V_117 = 0 ;
V_51 -> V_62 = 0 ;
V_51 -> V_124 = 0 ;
F_177 ( & V_51 -> V_215 ) ;
if ( V_233 ) {
V_51 -> V_2 . V_246 = V_247 ;
V_51 -> V_122 |= V_248 ;
}
#ifdef F_178
if ( ! F_174 ( V_57 ) && F_179 ( V_150 ) )
V_51 -> V_2 . V_246 = V_249 ;
#endif
F_180 ( V_18 ) ;
F_181 ( V_56 , & V_51 -> V_2 ) ;
return 0 ;
V_239:
return - V_250 ;
V_236:
return - V_181 ;
V_237:
return V_234 ;
}
static void F_182 ( struct V_58 * V_53 ,
struct V_149 * V_150 ,
struct V_55 * V_56 ,
T_6 V_57 ,
T_6 V_93 )
{
F_180 ( V_22 ) ;
#ifdef F_93
if ( F_94 ( V_150 ) && F_183 () ) {
F_184 ( L_15 ,
& V_57 , & V_93 , V_53 -> V_164 ) ;
if ( V_53 -> V_251 && F_185 ( V_56 ) ) {
F_186 ( V_252 , L_16 ,
V_253 , 16 , 1 ,
F_187 ( V_56 ) ,
V_53 -> V_251 , true ) ;
}
}
#endif
}
static int F_188 ( struct V_55 * V_56 ,
const struct V_151 * V_152 ,
struct V_149 * V_150 ,
T_6 V_57 , T_6 V_93 , T_1 V_81 )
{
struct V_105 * V_106 ;
struct V_50 * V_51 ;
int V_234 ;
struct V_149 * V_254 ;
unsigned int V_210 = 0 ;
bool V_255 ;
T_1 V_220 = 0 ;
V_254 = F_78 ( F_189 ( * V_152 ) ) ;
if ( V_254 == NULL ) {
F_190 ( L_17 ) ;
return - V_181 ;
}
V_234 = F_175 ( V_56 , V_93 , V_57 , V_81 , F_191 ( * V_152 ) ,
V_150 -> V_53 , V_150 , & V_220 ) ;
if ( V_234 < 0 ) {
F_182 ( V_150 -> V_53 , V_150 , V_56 , V_57 ,
V_93 ) ;
goto V_256;
}
V_255 = V_152 -> V_219 && ! V_220 ;
if ( V_254 == V_150 && V_234 && F_101 ( V_254 ) &&
( F_83 ( V_254 ) ||
F_84 ( V_254 , V_93 , F_192 ( * V_152 ) ) ) ) {
V_210 |= V_257 ;
V_255 = false ;
}
if ( V_56 -> V_95 != F_46 ( V_235 ) ) {
if ( V_254 == V_150 &&
F_193 ( V_150 ) == 0 ) {
V_234 = - V_181 ;
goto V_256;
}
}
V_106 = F_149 ( & F_90 ( * V_152 ) , V_57 ) ;
if ( V_255 ) {
if ( V_106 != NULL )
V_51 = F_60 ( V_106 -> V_107 ) ;
else
V_51 = F_60 ( F_90 ( * V_152 ) . V_138 ) ;
if ( F_164 ( V_51 ) ) {
F_194 ( V_56 , & V_51 -> V_2 ) ;
goto V_180;
}
}
V_51 = F_168 ( V_254 -> V_53 ,
F_176 ( V_150 , V_238 ) ,
F_176 ( V_254 , V_258 ) , V_255 ) ;
if ( ! V_51 ) {
V_234 = - V_250 ;
goto V_256;
}
V_51 -> V_52 = F_34 ( F_35 ( V_51 -> V_2 . V_53 ) ) ;
V_51 -> V_122 = V_210 ;
V_51 -> V_242 = V_152 -> type ;
V_51 -> V_244 = 1 ;
V_51 -> V_245 = 0 ;
V_51 -> V_117 = 0 ;
V_51 -> V_62 = 0 ;
V_51 -> V_124 = 0 ;
F_177 ( & V_51 -> V_215 ) ;
F_180 ( V_17 ) ;
V_51 -> V_2 . V_246 = V_259 ;
V_51 -> V_2 . V_240 = V_260 ;
F_165 ( V_51 , V_57 , V_152 , V_106 , V_152 -> V_219 , V_152 -> type , V_220 ) ;
F_181 ( V_56 , & V_51 -> V_2 ) ;
V_180:
V_234 = 0 ;
V_256:
return V_234 ;
}
static int F_195 ( struct V_55 * V_56 ,
struct V_151 * V_152 ,
const struct V_76 * V_77 ,
struct V_149 * V_150 ,
T_6 V_57 , T_6 V_93 , T_1 V_81 )
{
#ifdef F_196
if ( V_152 -> V_219 && V_152 -> V_219 -> V_261 > 1 )
F_197 ( V_152 ) ;
#endif
return F_188 ( V_56 , V_152 , V_150 , V_57 , V_93 , V_81 ) ;
}
static int F_198 ( struct V_55 * V_56 , T_6 V_57 , T_6 V_93 ,
T_7 V_81 , struct V_58 * V_53 )
{
struct V_151 V_152 ;
struct V_149 * V_150 = F_78 ( V_53 ) ;
struct V_76 V_77 ;
unsigned int V_210 = 0 ;
T_1 V_220 = 0 ;
struct V_50 * V_51 ;
int V_234 = - V_181 ;
struct V_37 * V_37 = F_35 ( V_53 ) ;
bool V_255 ;
if ( ! V_150 )
goto V_180;
if ( F_80 ( V_93 ) || F_81 ( V_93 ) )
goto V_262;
V_152 . V_219 = NULL ;
if ( F_81 ( V_57 ) || ( V_93 == 0 && V_57 == 0 ) )
goto V_263;
if ( F_82 ( V_93 ) )
goto V_262;
if ( F_82 ( V_57 ) )
goto V_264;
if ( F_173 ( V_57 ) ) {
if ( ! F_199 ( V_150 , V_37 ) )
goto V_264;
} else if ( F_173 ( V_93 ) ) {
if ( ! F_199 ( V_150 , V_37 ) )
goto V_262;
}
V_77 . V_200 = 0 ;
V_77 . V_201 = V_53 -> V_94 ;
V_77 . V_202 = V_56 -> V_83 ;
V_77 . V_199 = V_81 ;
V_77 . V_265 = V_92 ;
V_77 . V_57 = V_57 ;
V_77 . V_93 = V_93 ;
V_234 = F_89 ( V_37 , & V_77 , & V_152 ) ;
if ( V_234 != 0 ) {
if ( ! F_108 ( V_150 ) )
V_234 = - V_176 ;
goto V_266;
}
if ( V_152 . type == V_267 )
goto V_263;
if ( V_152 . type == V_268 ) {
V_234 = F_175 ( V_56 , V_93 , V_57 , V_81 ,
0 , V_53 , V_150 , & V_220 ) ;
if ( V_234 < 0 )
goto V_269;
goto V_270;
}
if ( ! F_108 ( V_150 ) ) {
V_234 = - V_176 ;
goto V_266;
}
if ( V_152 . type != V_159 )
goto V_264;
V_234 = F_195 ( V_56 , & V_152 , & V_77 , V_150 , V_57 , V_93 , V_81 ) ;
V_180: return V_234 ;
V_263:
if ( V_56 -> V_95 != F_46 ( V_235 ) )
goto V_236;
if ( ! F_82 ( V_93 ) ) {
V_234 = F_175 ( V_56 , V_93 , 0 , V_81 , 0 , V_53 ,
V_150 , & V_220 ) ;
if ( V_234 < 0 )
goto V_269;
}
V_210 |= V_271 ;
V_152 . type = V_267 ;
F_180 ( V_20 ) ;
V_270:
V_255 = false ;
if ( V_152 . V_219 ) {
if ( ! V_220 ) {
V_51 = F_60 ( F_90 ( V_152 ) . V_138 ) ;
if ( F_164 ( V_51 ) ) {
F_194 ( V_56 , & V_51 -> V_2 ) ;
V_234 = 0 ;
goto V_180;
}
V_255 = true ;
}
}
V_51 = F_168 ( V_37 -> V_217 ,
F_176 ( V_150 , V_238 ) , false , V_255 ) ;
if ( ! V_51 )
goto V_239;
V_51 -> V_2 . V_246 = V_247 ;
V_51 -> V_2 . V_240 = F_135 ;
#ifdef F_28
V_51 -> V_2 . V_204 = V_220 ;
#endif
V_51 -> V_52 = F_34 ( V_37 ) ;
V_51 -> V_122 = V_210 | V_248 ;
V_51 -> V_242 = V_152 . type ;
V_51 -> V_244 = 1 ;
V_51 -> V_245 = 0 ;
V_51 -> V_117 = 0 ;
V_51 -> V_62 = 0 ;
V_51 -> V_124 = 0 ;
F_177 ( & V_51 -> V_215 ) ;
F_180 ( V_17 ) ;
if ( V_152 . type == V_272 ) {
V_51 -> V_2 . V_246 = F_107 ;
V_51 -> V_2 . error = - V_234 ;
V_51 -> V_122 &= ~ V_248 ;
}
if ( V_255 ) {
if ( F_147 ( ! F_152 ( & F_90 ( V_152 ) , V_51 ) ) ) {
V_51 -> V_2 . V_210 |= V_211 ;
F_155 ( V_51 ) ;
}
}
F_181 ( V_56 , & V_51 -> V_2 ) ;
V_234 = 0 ;
goto V_180;
V_266:
F_180 ( V_19 ) ;
V_152 . type = V_272 ;
if ( V_234 == - V_273 )
V_234 = - V_178 ;
goto V_270;
V_264:
F_180 ( V_21 ) ;
#ifdef F_93
if ( F_94 ( V_150 ) )
F_105 ( L_18 ,
& V_57 , & V_93 , V_53 -> V_164 ) ;
#endif
V_236:
V_234 = - V_181 ;
goto V_180;
V_239:
V_234 = - V_250 ;
goto V_180;
V_262:
V_234 = - V_181 ;
V_269:
F_182 ( V_53 , V_150 , V_56 , V_57 , V_93 ) ;
goto V_180;
}
int F_200 ( struct V_55 * V_56 , T_6 V_57 , T_6 V_93 ,
T_7 V_81 , struct V_58 * V_53 )
{
int V_152 ;
F_59 () ;
if ( F_80 ( V_57 ) ) {
struct V_149 * V_150 = F_78 ( V_53 ) ;
if ( V_150 ) {
int V_233 = F_201 ( V_150 , V_57 , V_93 ,
F_39 ( V_56 ) -> V_95 ) ;
if ( V_233
#ifdef F_178
||
( ! F_174 ( V_57 ) &&
F_179 ( V_150 ) )
#endif
) {
int V_152 = F_170 ( V_56 , V_57 , V_93 ,
V_81 , V_53 , V_233 ) ;
F_62 () ;
return V_152 ;
}
}
F_62 () ;
return - V_181 ;
}
V_152 = F_198 ( V_56 , V_57 , V_93 , V_81 , V_53 ) ;
F_62 () ;
return V_152 ;
}
static struct V_50 * F_202 ( const struct V_151 * V_152 ,
const struct V_76 * V_77 , int V_274 ,
struct V_58 * V_275 ,
unsigned int V_210 )
{
struct V_218 * V_219 = V_152 -> V_219 ;
struct V_105 * V_106 ;
struct V_149 * V_150 ;
T_9 type = V_152 -> type ;
struct V_50 * V_51 ;
bool V_255 ;
V_150 = F_78 ( V_275 ) ;
if ( ! V_150 )
return F_203 ( - V_181 ) ;
if ( F_171 ( ! F_172 ( V_150 ) ) )
if ( F_173 ( V_77 -> V_93 ) && ! ( V_275 -> V_210 & V_276 ) )
return F_203 ( - V_181 ) ;
if ( F_81 ( V_77 -> V_57 ) )
type = V_267 ;
else if ( F_80 ( V_77 -> V_57 ) )
type = V_243 ;
else if ( F_82 ( V_77 -> V_57 ) )
return F_203 ( - V_181 ) ;
if ( V_275 -> V_210 & V_276 )
V_210 |= V_248 ;
V_255 = true ;
if ( type == V_267 ) {
V_210 |= V_271 | V_248 ;
V_219 = NULL ;
} else if ( type == V_243 ) {
V_210 |= V_241 | V_248 ;
if ( ! F_201 ( V_150 , V_77 -> V_57 , V_77 -> V_93 ,
V_77 -> V_277 ) )
V_210 &= ~ V_248 ;
else
V_255 = false ;
if ( V_219 && V_152 -> V_278 < 4 )
V_219 = NULL ;
}
V_106 = NULL ;
V_255 &= V_219 != NULL ;
if ( V_255 ) {
struct V_50 T_8 * * V_279 ;
struct V_125 * V_126 = & F_90 ( * V_152 ) ;
V_106 = F_149 ( V_126 , V_77 -> V_57 ) ;
if ( V_106 )
V_279 = & V_106 -> V_108 ;
else {
if ( F_147 ( V_77 -> V_280 &
V_281 &&
! ( V_126 -> V_222 &&
V_126 -> V_223 == V_224 ) ) ) {
V_255 = false ;
goto V_282;
}
V_279 = F_153 ( V_126 -> V_142 ) ;
}
V_51 = F_60 ( * V_279 ) ;
if ( F_164 ( V_51 ) ) {
F_204 ( & V_51 -> V_2 ) ;
return V_51 ;
}
}
V_282:
V_51 = F_168 ( V_275 ,
F_176 ( V_150 , V_238 ) ,
F_176 ( V_150 , V_258 ) ,
V_255 ) ;
if ( ! V_51 )
return F_203 ( - V_250 ) ;
V_51 -> V_2 . V_240 = V_260 ;
V_51 -> V_52 = F_34 ( F_35 ( V_275 ) ) ;
V_51 -> V_122 = V_210 ;
V_51 -> V_242 = type ;
V_51 -> V_244 = 0 ;
V_51 -> V_245 = V_274 ? : 0 ;
V_51 -> V_117 = 0 ;
V_51 -> V_62 = 0 ;
V_51 -> V_124 = 0 ;
F_177 ( & V_51 -> V_215 ) ;
F_180 ( V_23 ) ;
if ( V_210 & V_248 )
V_51 -> V_2 . V_246 = V_247 ;
if ( V_210 & ( V_271 | V_241 ) ) {
if ( V_210 & V_248 &&
! ( V_275 -> V_210 & V_276 ) ) {
V_51 -> V_2 . V_240 = V_283 ;
F_180 ( V_24 ) ;
}
#ifdef F_178
if ( type == V_243 ) {
if ( F_179 ( V_150 ) &&
! F_174 ( V_77 -> V_57 ) ) {
V_51 -> V_2 . V_246 = V_249 ;
V_51 -> V_2 . V_240 = V_283 ;
}
}
#endif
}
F_165 ( V_51 , V_77 -> V_57 , V_152 , V_106 , V_219 , type , 0 ) ;
return V_51 ;
}
struct V_50 * F_115 ( struct V_37 * V_37 , struct V_76 * V_77 )
{
struct V_58 * V_275 = NULL ;
T_10 V_81 = F_205 ( V_77 ) ;
unsigned int V_210 = 0 ;
struct V_151 V_152 ;
struct V_50 * V_51 ;
int V_274 ;
V_152 . V_204 = 0 ;
V_152 . V_219 = NULL ;
V_152 . V_284 = NULL ;
V_274 = V_77 -> V_200 ;
V_77 -> V_201 = V_285 ;
V_77 -> V_199 = V_81 & V_286 ;
V_77 -> V_265 = ( ( V_81 & V_287 ) ?
V_224 : V_92 ) ;
F_59 () ;
if ( V_77 -> V_93 ) {
V_51 = F_203 ( - V_181 ) ;
if ( F_80 ( V_77 -> V_93 ) ||
F_81 ( V_77 -> V_93 ) ||
F_82 ( V_77 -> V_93 ) )
goto V_180;
if ( V_77 -> V_200 == 0 &&
( F_80 ( V_77 -> V_57 ) ||
F_81 ( V_77 -> V_57 ) ) ) {
V_275 = F_206 ( V_37 , V_77 -> V_93 , false ) ;
if ( V_275 == NULL )
goto V_180;
V_77 -> V_200 = V_275 -> V_94 ;
goto V_288;
}
if ( ! ( V_77 -> V_280 & V_289 ) ) {
if ( ! F_206 ( V_37 , V_77 -> V_93 , false ) )
goto V_180;
}
}
if ( V_77 -> V_200 ) {
V_275 = F_207 ( V_37 , V_77 -> V_200 ) ;
V_51 = F_203 ( - V_290 ) ;
if ( V_275 == NULL )
goto V_180;
if ( ! ( V_275 -> V_210 & V_291 ) || ! F_78 ( V_275 ) ) {
V_51 = F_203 ( - V_178 ) ;
goto V_180;
}
if ( F_174 ( V_77 -> V_57 ) ||
F_81 ( V_77 -> V_57 ) ) {
if ( ! V_77 -> V_93 )
V_77 -> V_93 = F_140 ( V_275 , 0 ,
V_224 ) ;
goto V_288;
}
if ( ! V_77 -> V_93 ) {
if ( F_80 ( V_77 -> V_57 ) )
V_77 -> V_93 = F_140 ( V_275 , 0 ,
V_77 -> V_265 ) ;
else if ( ! V_77 -> V_57 )
V_77 -> V_93 = F_140 ( V_275 , 0 ,
V_292 ) ;
}
}
if ( ! V_77 -> V_57 ) {
V_77 -> V_57 = V_77 -> V_93 ;
if ( ! V_77 -> V_57 )
V_77 -> V_57 = V_77 -> V_93 = F_208 ( V_293 ) ;
V_275 = V_37 -> V_217 ;
V_77 -> V_200 = V_285 ;
V_152 . type = V_268 ;
V_210 |= V_248 ;
goto V_288;
}
if ( F_89 ( V_37 , V_77 , & V_152 ) ) {
V_152 . V_219 = NULL ;
V_152 . V_284 = NULL ;
if ( V_77 -> V_200 ) {
if ( V_77 -> V_93 == 0 )
V_77 -> V_93 = F_140 ( V_275 , 0 ,
V_224 ) ;
V_152 . type = V_159 ;
goto V_288;
}
V_51 = F_203 ( - V_178 ) ;
goto V_180;
}
if ( V_152 . type == V_268 ) {
if ( ! V_77 -> V_93 ) {
if ( V_152 . V_219 -> V_294 )
V_77 -> V_93 = V_152 . V_219 -> V_294 ;
else
V_77 -> V_93 = V_77 -> V_57 ;
}
V_275 = V_37 -> V_217 ;
V_77 -> V_200 = V_275 -> V_94 ;
V_210 |= V_248 ;
goto V_288;
}
#ifdef F_196
if ( V_152 . V_219 -> V_261 > 1 && V_77 -> V_200 == 0 )
F_197 ( & V_152 ) ;
else
#endif
if ( ! V_152 . V_278 &&
V_152 . V_284 -> V_295 > 1 &&
V_152 . type == V_159 && ! V_77 -> V_200 )
F_209 ( & V_152 ) ;
if ( ! V_77 -> V_93 )
V_77 -> V_93 = F_139 ( V_37 , V_152 ) ;
V_275 = F_189 ( V_152 ) ;
V_77 -> V_200 = V_275 -> V_94 ;
V_288:
V_51 = F_202 ( & V_152 , V_77 , V_274 , V_275 , V_210 ) ;
V_180:
F_62 () ;
return V_51 ;
}
static struct V_1 * F_210 ( struct V_1 * V_2 , T_1 V_195 )
{
return NULL ;
}
static unsigned int F_211 ( const struct V_1 * V_2 )
{
unsigned int V_189 = F_143 ( V_2 , V_190 ) ;
return V_189 ? : V_2 -> V_53 -> V_189 ;
}
static void F_212 ( struct V_1 * V_2 , struct V_78 * V_79 ,
struct V_55 * V_56 , T_1 V_189 )
{
}
static void F_213 ( struct V_1 * V_2 , struct V_78 * V_79 ,
struct V_55 * V_56 )
{
}
static T_1 * F_214 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
return NULL ;
}
struct V_1 * F_215 ( struct V_37 * V_37 , struct V_1 * V_296 )
{
struct V_50 * V_297 = (struct V_50 * ) V_296 ;
struct V_50 * V_60 ;
V_60 = F_169 ( & V_298 , NULL , 1 , V_299 , 0 ) ;
if ( V_60 ) {
struct V_1 * V_193 = & V_60 -> V_2 ;
V_193 -> V_300 = 1 ;
V_193 -> V_246 = V_301 ;
V_193 -> V_240 = V_302 ;
V_193 -> V_53 = V_297 -> V_2 . V_53 ;
if ( V_193 -> V_53 )
F_162 ( V_193 -> V_53 ) ;
V_60 -> V_244 = V_297 -> V_244 ;
V_60 -> V_245 = V_297 -> V_245 ;
V_60 -> V_117 = V_297 -> V_117 ;
V_60 -> V_52 = F_34 ( V_37 ) ;
V_60 -> V_122 = V_297 -> V_122 ;
V_60 -> V_242 = V_297 -> V_242 ;
V_60 -> V_62 = V_297 -> V_62 ;
V_60 -> V_124 = V_297 -> V_124 ;
F_177 ( & V_60 -> V_215 ) ;
F_216 ( V_193 ) ;
}
F_127 ( V_296 ) ;
return V_60 ? & V_60 -> V_2 : F_203 ( - V_32 ) ;
}
struct V_50 * F_125 ( struct V_37 * V_37 , struct V_76 * V_303 ,
struct V_78 * V_79 )
{
struct V_50 * V_60 = F_115 ( V_37 , V_303 ) ;
if ( F_116 ( V_60 ) )
return V_60 ;
if ( V_303 -> V_277 )
V_60 = (struct V_50 * ) F_217 ( V_37 , & V_60 -> V_2 ,
F_218 ( V_303 ) ,
V_79 , 0 ) ;
return V_60 ;
}
static int F_219 ( struct V_37 * V_37 , T_6 V_2 , T_6 V_28 ,
struct V_76 * V_77 , struct V_55 * V_56 , T_1 V_304 ,
T_1 V_5 , int V_305 , int V_306 , unsigned int V_210 )
{
struct V_50 * V_60 = F_100 ( V_56 ) ;
struct V_307 * V_308 ;
struct V_309 * V_310 ;
unsigned long V_119 = 0 ;
T_1 error ;
T_1 V_311 [ V_312 ] ;
V_310 = F_220 ( V_56 , V_304 , V_5 , V_305 , sizeof( * V_308 ) , V_210 ) ;
if ( V_310 == NULL )
return - V_313 ;
V_308 = F_221 ( V_310 ) ;
V_308 -> V_314 = V_315 ;
V_308 -> V_316 = 32 ;
V_308 -> V_317 = 0 ;
V_308 -> V_318 = V_77 -> V_199 ;
V_308 -> V_319 = V_320 ;
if ( F_222 ( V_56 , V_321 , V_320 ) )
goto V_322;
V_308 -> V_323 = V_60 -> V_242 ;
V_308 -> V_324 = V_92 ;
V_308 -> V_325 = V_326 ;
V_308 -> V_327 = ( V_60 -> V_122 & ~ 0xFFFF ) | V_328 ;
if ( V_60 -> V_122 & V_329 )
V_308 -> V_327 |= V_330 ;
if ( F_223 ( V_56 , V_331 , V_2 ) )
goto V_322;
if ( V_28 ) {
V_308 -> V_317 = 32 ;
if ( F_223 ( V_56 , V_332 , V_28 ) )
goto V_322;
}
if ( V_60 -> V_2 . V_53 &&
F_222 ( V_56 , V_333 , V_60 -> V_2 . V_53 -> V_94 ) )
goto V_322;
#ifdef F_28
if ( V_60 -> V_2 . V_204 &&
F_222 ( V_56 , V_334 , V_60 -> V_2 . V_204 ) )
goto V_322;
#endif
if ( ! F_151 ( V_60 ) &&
V_77 -> V_93 != V_28 ) {
if ( F_223 ( V_56 , V_335 , V_77 -> V_93 ) )
goto V_322;
}
if ( V_60 -> V_124 &&
F_223 ( V_56 , V_336 , V_60 -> V_62 ) )
goto V_322;
V_119 = V_60 -> V_2 . V_119 ;
if ( V_119 ) {
unsigned long V_174 = V_143 ;
if ( F_69 ( V_174 , V_119 ) )
V_119 -= V_174 ;
else
V_119 = 0 ;
}
memcpy ( V_311 , F_224 ( & V_60 -> V_2 ) , sizeof( V_311 ) ) ;
if ( V_60 -> V_117 && V_119 )
V_311 [ V_190 - 1 ] = V_60 -> V_117 ;
if ( F_225 ( V_56 , V_311 ) < 0 )
goto V_322;
if ( V_77 -> V_202 &&
F_222 ( V_56 , V_337 , V_77 -> V_202 ) )
goto V_322;
error = V_60 -> V_2 . error ;
if ( F_151 ( V_60 ) ) {
#ifdef F_178
if ( F_80 ( V_2 ) && ! F_174 ( V_2 ) &&
F_226 ( V_37 , V_338 ) ) {
int V_234 = F_227 ( V_37 , V_56 ,
V_77 -> V_93 , V_77 -> V_57 ,
V_308 , V_306 ) ;
if ( V_234 <= 0 ) {
if ( ! V_306 ) {
if ( V_234 == 0 )
return 0 ;
goto V_322;
} else {
if ( V_234 == - V_313 )
goto V_322;
error = V_234 ;
}
}
} else
#endif
if ( F_222 ( V_56 , V_339 , V_56 -> V_53 -> V_94 ) )
goto V_322;
}
if ( F_228 ( V_56 , & V_60 -> V_2 , 0 , V_119 , error ) < 0 )
goto V_322;
return F_229 ( V_56 , V_310 ) ;
V_322:
F_230 ( V_56 , V_310 ) ;
return - V_313 ;
}
static int F_231 ( struct V_55 * V_340 , struct V_309 * V_310 )
{
struct V_37 * V_37 = F_118 ( V_340 -> V_79 ) ;
struct V_307 * V_341 ;
struct V_342 * V_343 [ V_344 + 1 ] ;
struct V_50 * V_60 = NULL ;
struct V_76 V_77 ;
T_6 V_2 = 0 ;
T_6 V_28 = 0 ;
T_1 V_345 ;
int V_234 ;
int V_83 ;
struct V_55 * V_56 ;
V_234 = F_232 ( V_310 , sizeof( * V_341 ) , V_343 , V_344 , V_346 ) ;
if ( V_234 < 0 )
goto V_347;
V_341 = F_221 ( V_310 ) ;
V_56 = F_233 ( V_348 , V_31 ) ;
if ( V_56 == NULL ) {
V_234 = - V_250 ;
goto V_347;
}
F_234 ( V_56 ) ;
F_235 ( V_56 ) ;
F_39 ( V_56 ) -> V_95 = V_349 ;
F_236 ( V_56 , V_350 + sizeof( struct V_65 ) ) ;
V_28 = V_343 [ V_332 ] ? F_237 ( V_343 [ V_332 ] ) : 0 ;
V_2 = V_343 [ V_331 ] ? F_237 ( V_343 [ V_331 ] ) : 0 ;
V_345 = V_343 [ V_339 ] ? F_238 ( V_343 [ V_339 ] ) : 0 ;
V_83 = V_343 [ V_337 ] ? F_238 ( V_343 [ V_337 ] ) : 0 ;
memset ( & V_77 , 0 , sizeof( V_77 ) ) ;
V_77 . V_57 = V_2 ;
V_77 . V_93 = V_28 ;
V_77 . V_199 = V_341 -> V_318 ;
V_77 . V_200 = V_343 [ V_333 ] ? F_238 ( V_343 [ V_333 ] ) : 0 ;
V_77 . V_202 = V_83 ;
if ( V_345 ) {
struct V_58 * V_53 ;
V_53 = F_239 ( V_37 , V_345 ) ;
if ( V_53 == NULL ) {
V_234 = - V_290 ;
goto V_351;
}
V_56 -> V_95 = F_46 ( V_235 ) ;
V_56 -> V_53 = V_53 ;
V_56 -> V_83 = V_83 ;
F_240 () ;
V_234 = F_241 ( V_56 , V_2 , V_28 , V_341 -> V_318 , V_53 ) ;
F_242 () ;
V_60 = F_100 ( V_56 ) ;
if ( V_234 == 0 && V_60 -> V_2 . error )
V_234 = - V_60 -> V_2 . error ;
} else {
V_60 = F_243 ( V_37 , & V_77 ) ;
V_234 = 0 ;
if ( F_116 ( V_60 ) )
V_234 = F_244 ( V_60 ) ;
}
if ( V_234 )
goto V_351;
F_181 ( V_56 , & V_60 -> V_2 ) ;
if ( V_341 -> V_327 & V_330 )
V_60 -> V_122 |= V_329 ;
V_234 = F_219 ( V_37 , V_2 , V_28 , & V_77 , V_56 ,
F_245 ( V_340 ) . V_304 , V_310 -> V_352 ,
V_353 , 0 , 0 ) ;
if ( V_234 <= 0 )
goto V_351;
V_234 = F_246 ( V_56 , V_37 , F_245 ( V_340 ) . V_304 ) ;
V_347:
return V_234 ;
V_351:
F_110 ( V_56 ) ;
goto V_347;
}
void F_247 ( struct V_149 * V_150 )
{
F_36 ( F_35 ( V_150 -> V_53 ) ) ;
}
static int F_248 ( struct V_354 * V_355 , int V_356 ,
void T_11 * V_357 ,
T_12 * V_358 , T_2 * V_359 )
{
struct V_37 * V_37 = (struct V_37 * ) V_355 -> V_360 ;
if ( V_356 ) {
F_36 ( V_37 ) ;
F_249 ( V_37 ) ;
return 0 ;
}
return - V_181 ;
}
static T_3 int F_250 ( struct V_37 * V_37 )
{
struct V_354 * V_361 ;
V_361 = V_362 ;
if ( ! F_251 ( V_37 , & V_363 ) ) {
V_361 = F_252 ( V_361 , sizeof( V_362 ) , V_31 ) ;
if ( V_361 == NULL )
goto V_364;
if ( V_37 -> V_365 != & V_366 )
V_361 [ 0 ] . V_367 = NULL ;
}
V_361 [ 0 ] . V_360 = V_37 ;
V_37 -> V_74 . V_368 = F_253 ( V_37 , L_19 , V_361 ) ;
if ( V_37 -> V_74 . V_368 == NULL )
goto V_369;
return 0 ;
V_369:
if ( V_361 != V_362 )
F_23 ( V_361 ) ;
V_364:
return - V_32 ;
}
static T_4 void F_254 ( struct V_37 * V_37 )
{
struct V_354 * V_361 ;
V_361 = V_37 -> V_74 . V_368 -> V_370 ;
F_255 ( V_37 -> V_74 . V_368 ) ;
F_256 ( V_361 == V_362 ) ;
F_23 ( V_361 ) ;
}
static T_3 int F_257 ( struct V_37 * V_37 )
{
F_258 ( & V_37 -> V_74 . V_52 , 0 ) ;
F_258 ( & V_37 -> V_136 , 0 ) ;
F_259 ( & V_37 -> V_74 . V_371 ,
sizeof( V_37 -> V_74 . V_371 ) ) ;
return 0 ;
}
static int T_3 F_260 ( struct V_37 * V_37 )
{
struct V_372 * V_373 = F_261 ( sizeof( * V_373 ) , V_31 ) ;
if ( ! V_373 )
return - V_32 ;
F_262 ( V_373 ) ;
V_37 -> V_74 . V_75 = V_373 ;
return 0 ;
}
static void T_4 F_263 ( struct V_37 * V_37 )
{
struct V_372 * V_373 = V_37 -> V_74 . V_75 ;
V_37 -> V_74 . V_75 = NULL ;
F_264 ( V_373 ) ;
F_23 ( V_373 ) ;
}
int T_5 F_265 ( void )
{
int V_374 = 0 ;
#ifdef F_28
V_27 = F_266 ( 256 * sizeof( struct V_27 ) , F_267 ( struct V_27 ) ) ;
if ( ! V_27 )
F_268 ( L_20 ) ;
#endif
V_16 . V_375 =
F_269 ( L_21 , sizeof( struct V_50 ) , 0 ,
V_376 | V_377 , NULL ) ;
V_298 . V_375 = V_16 . V_375 ;
if ( F_270 ( & V_16 ) < 0 )
F_268 ( L_22 ) ;
if ( F_270 ( & V_298 ) < 0 )
F_268 ( L_23 ) ;
V_16 . V_378 = ~ 0 ;
V_379 = V_380 ;
F_271 () ;
F_272 () ;
if ( F_31 () )
F_273 ( L_24 ) ;
#ifdef F_274
F_275 () ;
F_276 () ;
#endif
F_277 ( V_381 , V_382 , F_231 , NULL , NULL ) ;
#ifdef F_278
F_32 ( & V_383 ) ;
#endif
F_32 ( & V_384 ) ;
F_32 ( & V_385 ) ;
return V_374 ;
}
void T_5 F_279 ( void )
{
F_253 ( & V_363 , L_19 , V_386 ) ;
}
