static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
int V_5 )
{
}
static T_1 * F_2 ( struct V_1 * V_2 , unsigned long V_6 )
{
F_3 ( 1 ) ;
return NULL ;
}
static void * F_4 ( struct V_7 * V_8 , T_2 * V_9 )
{
if ( * V_9 )
return NULL ;
return V_10 ;
}
static void * F_5 ( struct V_7 * V_8 , void * V_11 , T_2 * V_9 )
{
++ * V_9 ;
return NULL ;
}
static void F_6 ( struct V_7 * V_8 , void * V_11 )
{
}
static int F_7 ( struct V_7 * V_8 , void * V_11 )
{
if ( V_11 == V_10 )
F_8 ( V_8 , L_1 ,
L_2
L_3
L_4 ) ;
return 0 ;
}
static int F_9 ( struct V_12 * V_12 , struct V_13 * V_13 )
{
return F_10 ( V_13 , & V_14 ) ;
}
static void * F_11 ( struct V_7 * V_8 , T_2 * V_9 )
{
int V_15 ;
if ( * V_9 == 0 )
return V_10 ;
for ( V_15 = * V_9 - 1 ; V_15 < V_16 ; ++ V_15 ) {
if ( ! F_12 ( V_15 ) )
continue;
* V_9 = V_15 + 1 ;
return & F_13 ( V_17 , V_15 ) ;
}
return NULL ;
}
static void * F_14 ( struct V_7 * V_8 , void * V_11 , T_2 * V_9 )
{
int V_15 ;
for ( V_15 = * V_9 ; V_15 < V_16 ; ++ V_15 ) {
if ( ! F_12 ( V_15 ) )
continue;
* V_9 = V_15 + 1 ;
return & F_13 ( V_17 , V_15 ) ;
}
return NULL ;
}
static void F_15 ( struct V_7 * V_8 , void * V_11 )
{
}
static int F_16 ( struct V_7 * V_8 , void * V_11 )
{
struct V_17 * V_18 = V_11 ;
if ( V_11 == V_10 ) {
F_8 ( V_8 , L_5 ) ;
return 0 ;
}
F_8 ( V_8 , L_6
L_7 ,
F_17 ( & V_19 ) ,
V_18 -> V_20 ,
V_18 -> V_21 ,
V_18 -> V_22 ,
V_18 -> V_23 ,
V_18 -> V_24 ,
V_18 -> V_25 ,
V_18 -> V_26 ,
V_18 -> V_27 ,
V_18 -> V_28 ,
V_18 -> V_29 ,
V_18 -> V_30 ,
V_18 -> V_31 ,
V_18 -> V_32 ,
V_18 -> V_33 ,
V_18 -> V_34 ,
V_18 -> V_35
) ;
return 0 ;
}
static int F_18 ( struct V_12 * V_12 , struct V_13 * V_13 )
{
return F_10 ( V_13 , & V_36 ) ;
}
static int F_19 ( struct V_7 * V_37 , void * V_11 )
{
struct V_38 * V_2 , * V_39 ;
unsigned int V_40 , V_41 ;
V_2 = F_20 ( 256 , sizeof( struct V_38 ) , V_42 ) ;
if ( ! V_2 )
return - V_43 ;
F_21 (i) {
V_39 = (struct V_38 * ) F_22 ( V_38 , V_40 ) ;
for ( V_41 = 0 ; V_41 < 256 ; V_41 ++ ) {
V_2 [ V_41 ] . V_44 += V_39 [ V_41 ] . V_44 ;
V_2 [ V_41 ] . V_45 += V_39 [ V_41 ] . V_45 ;
V_2 [ V_41 ] . V_46 += V_39 [ V_41 ] . V_46 ;
V_2 [ V_41 ] . V_47 += V_39 [ V_41 ] . V_47 ;
}
}
F_23 ( V_37 , V_2 , 256 * sizeof( struct V_38 ) ) ;
F_24 ( V_2 ) ;
return 0 ;
}
static int F_25 ( struct V_12 * V_12 , struct V_13 * V_13 )
{
return F_26 ( V_13 , F_19 , NULL ) ;
}
static int T_3 F_27 ( struct V_48 * V_48 )
{
struct V_49 * V_50 ;
V_50 = F_28 ( V_48 , L_8 , V_51 ,
& V_52 ) ;
if ( ! V_50 )
goto V_53;
V_50 = F_29 ( L_8 , V_51 ,
V_48 -> V_54 , & V_55 ) ;
if ( ! V_50 )
goto V_56;
#ifdef F_30
V_50 = F_29 ( L_9 , 0 , V_48 -> V_57 , & V_58 ) ;
if ( ! V_50 )
goto V_59;
#endif
return 0 ;
#ifdef F_30
V_59:
F_31 ( L_8 , V_48 -> V_54 ) ;
#endif
V_56:
F_31 ( L_8 , V_48 -> V_57 ) ;
V_53:
return - V_43 ;
}
static void T_4 F_32 ( struct V_48 * V_48 )
{
F_31 ( L_8 , V_48 -> V_54 ) ;
F_31 ( L_8 , V_48 -> V_57 ) ;
#ifdef F_30
F_31 ( L_9 , V_48 -> V_57 ) ;
#endif
}
static int T_5 F_33 ( void )
{
return F_34 ( & V_60 ) ;
}
static inline int F_33 ( void )
{
return 0 ;
}
static inline bool F_35 ( const struct V_61 * V_62 )
{
return V_62 -> V_63 != V_63 ( F_36 ( V_62 -> V_2 . V_4 ) ) ;
}
void F_37 ( struct V_48 * V_48 )
{
F_38 ( V_48 ) ;
}
static struct V_64 * F_39 ( const struct V_1 * V_2 ,
struct V_65 * V_66 ,
const void * V_67 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
const T_6 * V_68 = V_67 ;
const struct V_61 * V_69 ;
struct V_64 * V_70 ;
V_69 = ( const struct V_61 * ) V_2 ;
if ( V_69 -> V_71 )
V_68 = ( const T_6 * ) & V_69 -> V_71 ;
else if ( V_66 )
V_68 = & F_40 ( V_66 ) -> V_67 ;
V_70 = F_41 ( V_4 , * ( V_72 T_1 * ) V_68 ) ;
if ( V_70 )
return V_70 ;
return F_42 ( & V_73 , V_68 , V_4 ) ;
}
static void F_43 ( struct V_74 * V_75 )
{
static F_44 ( V_76 ) ;
static T_1 V_77 ;
T_1 V_78 ;
F_45 ( & V_76 ) ;
V_78 = F_46 ( ( V_72 T_6 ) V_77 ^ V_75 -> V_67 ) ;
V_75 -> V_79 = F_47 ( V_78 & 0xFFFF ) ;
V_77 = V_78 ;
F_48 ( & V_76 ) ;
}
void F_49 ( struct V_74 * V_75 , struct V_1 * V_2 , int V_80 )
{
struct V_48 * V_48 = F_36 ( V_2 -> V_4 ) ;
struct V_81 * V_82 ;
V_82 = F_50 ( V_48 -> V_83 . V_84 , V_75 -> V_67 , 1 ) ;
if ( V_82 ) {
V_75 -> V_79 = F_47 ( F_51 ( V_82 , V_80 ) ) ;
F_52 ( V_82 ) ;
return;
}
F_43 ( V_75 ) ;
}
static void F_53 ( struct V_85 * V_86 , const struct V_87 * V_88 ,
const struct V_74 * V_75 ,
int V_89 , T_7 V_90 ,
T_7 V_91 , T_1 V_92 , int V_93 )
{
if ( V_88 ) {
const struct V_94 * V_95 = F_54 ( V_88 ) ;
V_89 = V_88 -> V_96 ;
V_92 = V_88 -> V_97 ;
V_90 = F_55 ( V_88 ) ;
V_91 = V_95 -> V_98 ? V_99 : V_88 -> V_100 ;
}
F_56 ( V_86 , V_89 , V_92 , V_90 ,
V_101 , V_91 ,
V_93 ,
V_75 -> V_67 , V_75 -> V_102 , 0 , 0 ) ;
}
static void F_57 ( struct V_85 * V_86 , const struct V_65 * V_66 ,
const struct V_87 * V_88 )
{
const struct V_74 * V_75 = F_40 ( V_66 ) ;
int V_89 = V_66 -> V_4 -> V_103 ;
T_7 V_90 = F_58 ( V_75 -> V_90 ) ;
T_7 V_91 = V_75 -> V_104 ;
T_1 V_92 = V_66 -> V_92 ;
F_53 ( V_86 , V_88 , V_75 , V_89 , V_90 , V_91 , V_92 , 0 ) ;
}
static void F_59 ( struct V_85 * V_86 , const struct V_87 * V_88 )
{
const struct V_94 * V_95 = F_54 ( V_88 ) ;
const struct V_105 * V_106 ;
T_6 V_67 = V_95 -> V_107 ;
F_60 () ;
V_106 = F_61 ( V_95 -> V_106 ) ;
if ( V_106 && V_106 -> V_108 . V_109 )
V_67 = V_106 -> V_108 . V_110 ;
F_56 ( V_86 , V_88 -> V_96 , V_88 -> V_97 ,
F_55 ( V_88 ) , V_101 ,
V_95 -> V_98 ? V_99 : V_88 -> V_100 ,
F_62 ( V_88 ) ,
V_67 , V_95 -> V_111 , 0 , 0 ) ;
F_63 () ;
}
static void F_64 ( struct V_85 * V_86 , const struct V_87 * V_88 ,
const struct V_65 * V_66 )
{
if ( V_66 )
F_57 ( V_86 , V_66 , V_88 ) ;
else
F_59 ( V_86 , V_88 ) ;
}
static inline void F_65 ( struct V_61 * V_69 )
{
F_66 ( & V_69 -> V_2 . V_112 , V_113 ) ;
}
static struct V_114 * F_67 ( struct V_115 * V_116 )
{
struct V_114 * V_117 , * V_118 ;
struct V_61 * V_119 ;
V_118 = F_61 ( V_116 -> V_120 ) ;
for ( V_117 = F_61 ( V_118 -> V_121 ) ; V_117 ;
V_117 = F_61 ( V_117 -> V_121 ) ) {
if ( F_68 ( V_117 -> V_122 , V_118 -> V_122 ) )
V_118 = V_117 ;
}
V_119 = F_61 ( V_118 -> V_123 ) ;
if ( V_119 ) {
F_69 ( V_118 -> V_123 , NULL ) ;
F_65 ( V_119 ) ;
}
return V_118 ;
}
static inline T_1 F_70 ( T_6 V_67 )
{
T_1 V_124 ;
V_124 = ( V_72 T_1 ) V_67 ;
V_124 ^= ( V_124 >> 11 ) ^ ( V_124 >> 22 ) ;
return V_124 & ( V_125 - 1 ) ;
}
static void F_71 ( struct V_126 * V_127 , T_6 V_67 , T_6 V_128 ,
T_1 V_129 , unsigned long V_130 )
{
struct V_115 * V_116 ;
struct V_114 * V_117 ;
int V_131 ;
T_1 V_124 = F_70 ( V_67 ) ;
F_45 ( & V_132 ) ;
V_116 = V_127 -> V_133 ;
if ( ! V_116 ) {
V_116 = F_72 ( V_125 * sizeof( * V_116 ) , V_134 ) ;
if ( ! V_116 )
goto V_135;
V_127 -> V_133 = V_116 ;
}
V_116 += V_124 ;
V_131 = 0 ;
for ( V_117 = F_61 ( V_116 -> V_120 ) ; V_117 ;
V_117 = F_61 ( V_117 -> V_121 ) ) {
if ( V_117 -> V_136 == V_67 )
break;
V_131 ++ ;
}
if ( V_117 ) {
if ( V_128 )
V_117 -> V_137 = V_128 ;
if ( V_129 ) {
V_117 -> V_138 = V_129 ;
V_117 -> V_139 = V_130 ;
}
} else {
if ( V_131 > V_140 )
V_117 = F_67 ( V_116 ) ;
else {
V_117 = F_72 ( sizeof( * V_117 ) , V_134 ) ;
if ( ! V_117 )
goto V_135;
V_117 -> V_121 = V_116 -> V_120 ;
F_73 ( V_116 -> V_120 , V_117 ) ;
}
V_117 -> V_136 = V_67 ;
V_117 -> V_137 = V_128 ;
V_117 -> V_138 = V_129 ;
V_117 -> V_139 = V_130 ;
}
V_117 -> V_122 = V_141 ;
V_135:
F_48 ( & V_132 ) ;
return;
}
static void F_74 ( struct V_61 * V_69 , struct V_65 * V_66 , struct V_85 * V_86 ,
bool V_142 )
{
T_6 V_143 = F_75 ( V_66 ) -> V_144 . V_145 ;
T_6 V_146 = F_40 ( V_66 ) -> V_102 ;
struct V_3 * V_4 = V_66 -> V_4 ;
struct V_147 * V_148 ;
struct V_149 V_150 ;
struct V_64 * V_70 ;
struct V_48 * V_48 ;
switch ( F_75 ( V_66 ) -> V_151 & 7 ) {
case V_152 :
case V_153 :
case V_154 :
case V_155 :
break;
default:
return;
}
if ( V_69 -> V_71 != V_146 )
return;
V_148 = F_76 ( V_4 ) ;
if ( ! V_148 )
return;
V_48 = F_36 ( V_4 ) ;
if ( V_143 == V_146 || ! F_77 ( V_148 ) ||
F_78 ( V_143 ) || F_79 ( V_143 ) ||
F_80 ( V_143 ) )
goto V_156;
if ( ! F_81 ( V_148 ) ) {
if ( ! F_82 ( V_148 , V_143 , V_146 ) )
goto V_156;
if ( F_83 ( V_148 ) && F_84 ( V_143 , V_4 ) )
goto V_156;
} else {
if ( F_85 ( V_48 , V_143 ) != V_157 )
goto V_156;
}
V_70 = F_39 ( & V_69 -> V_2 , NULL , & V_143 ) ;
if ( V_70 ) {
if ( ! ( V_70 -> V_158 & V_159 ) ) {
F_86 ( V_70 , NULL ) ;
} else {
if ( F_87 ( V_48 , V_86 , & V_150 ) == 0 ) {
struct V_126 * V_127 = & F_88 ( V_150 ) ;
F_71 ( V_127 , V_86 -> V_67 , V_143 ,
0 , 0 ) ;
}
if ( V_142 )
V_69 -> V_2 . V_160 = V_161 ;
F_89 ( V_162 , V_70 ) ;
}
F_90 ( V_70 ) ;
}
return;
V_156:
#ifdef F_91
if ( F_92 ( V_148 ) ) {
const struct V_74 * V_75 = ( const struct V_74 * ) V_66 -> V_163 ;
T_6 V_67 = V_75 -> V_67 ;
T_6 V_102 = V_75 -> V_102 ;
F_93 ( L_10
L_11 ,
& V_146 , V_4 -> V_164 , & V_143 ,
& V_102 , & V_67 ) ;
}
#endif
;
}
static void F_94 ( struct V_1 * V_2 , struct V_87 * V_88 , struct V_65 * V_66 )
{
struct V_61 * V_69 ;
struct V_85 V_86 ;
V_69 = (struct V_61 * ) V_2 ;
F_64 ( & V_86 , V_88 , V_66 ) ;
F_74 ( V_69 , V_66 , & V_86 , true ) ;
}
static struct V_1 * F_95 ( struct V_1 * V_2 )
{
struct V_61 * V_69 = (struct V_61 * ) V_2 ;
struct V_1 * V_165 = V_2 ;
if ( V_69 ) {
if ( V_2 -> V_160 > 0 ) {
F_96 ( V_69 ) ;
V_165 = NULL ;
} else if ( ( V_69 -> V_166 & V_167 ) ||
V_69 -> V_2 . V_130 ) {
F_96 ( V_69 ) ;
V_165 = NULL ;
}
}
return V_165 ;
}
void F_97 ( struct V_65 * V_66 )
{
struct V_61 * V_69 = F_98 ( V_66 ) ;
struct V_147 * V_148 ;
struct V_81 * V_82 ;
struct V_48 * V_48 ;
int V_168 ;
F_60 () ;
V_148 = F_76 ( V_69 -> V_2 . V_4 ) ;
if ( ! V_148 || ! F_99 ( V_148 ) ) {
F_63 () ;
return;
}
V_168 = F_92 ( V_148 ) ;
F_63 () ;
V_48 = F_36 ( V_69 -> V_2 . V_4 ) ;
V_82 = F_50 ( V_48 -> V_83 . V_84 , F_40 ( V_66 ) -> V_102 , 1 ) ;
if ( ! V_82 ) {
F_100 ( V_66 , V_169 , V_154 , V_69 -> V_71 ) ;
return;
}
if ( F_101 ( V_141 , V_82 -> V_170 + V_171 ) )
V_82 -> V_172 = 0 ;
if ( V_82 -> V_172 >= V_173 ) {
V_82 -> V_170 = V_141 ;
goto V_174;
}
if ( V_82 -> V_172 == 0 ||
F_101 ( V_141 ,
( V_82 -> V_170 +
( V_175 << V_82 -> V_172 ) ) ) ) {
F_100 ( V_66 , V_169 , V_154 , V_69 -> V_71 ) ;
V_82 -> V_170 = V_141 ;
++ V_82 -> V_172 ;
#ifdef F_91
if ( V_168 &&
V_82 -> V_172 == V_173 )
F_102 ( L_12 ,
& F_40 ( V_66 ) -> V_102 , F_103 ( V_66 ) ,
& F_40 ( V_66 ) -> V_67 , & V_69 -> V_71 ) ;
#endif
}
V_174:
F_52 ( V_82 ) ;
}
static int F_104 ( struct V_65 * V_66 )
{
struct V_147 * V_148 = F_76 ( V_66 -> V_4 ) ;
struct V_61 * V_69 = F_98 ( V_66 ) ;
struct V_81 * V_82 ;
unsigned long V_176 ;
struct V_48 * V_48 ;
bool V_177 ;
int V_151 ;
V_48 = F_36 ( V_69 -> V_2 . V_4 ) ;
if ( ! F_105 ( V_148 ) ) {
switch ( V_69 -> V_2 . error ) {
case V_178 :
F_106 ( V_48 , V_179 ) ;
break;
case V_180 :
F_106 ( V_48 , V_181 ) ;
break;
}
goto V_182;
}
switch ( V_69 -> V_2 . error ) {
case V_183 :
default:
goto V_182;
case V_178 :
V_151 = V_184 ;
break;
case V_180 :
V_151 = V_185 ;
F_106 ( V_48 , V_181 ) ;
break;
case V_186 :
V_151 = V_187 ;
break;
}
V_82 = F_50 ( V_48 -> V_83 . V_84 , F_40 ( V_66 ) -> V_102 , 1 ) ;
V_177 = true ;
if ( V_82 ) {
V_176 = V_141 ;
V_82 -> V_172 += V_176 - V_82 -> V_170 ;
if ( V_82 -> V_172 > V_188 )
V_82 -> V_172 = V_188 ;
V_82 -> V_170 = V_176 ;
if ( V_82 -> V_172 >= V_189 )
V_82 -> V_172 -= V_189 ;
else
V_177 = false ;
F_52 ( V_82 ) ;
}
if ( V_177 )
F_100 ( V_66 , V_190 , V_151 , 0 ) ;
V_182: F_107 ( V_66 ) ;
return 0 ;
}
static T_1 F_108 ( struct V_61 * V_69 , struct V_85 * V_86 , T_1 V_191 )
{
struct V_149 V_150 ;
if ( V_191 < V_192 )
V_191 = V_192 ;
F_60 () ;
if ( F_87 ( F_36 ( V_69 -> V_2 . V_4 ) , V_86 , & V_150 ) == 0 ) {
struct V_126 * V_127 = & F_88 ( V_150 ) ;
F_71 ( V_127 , V_86 -> V_67 , 0 , V_191 ,
V_141 + V_193 ) ;
}
F_63 () ;
return V_191 ;
}
static void F_109 ( struct V_1 * V_2 , struct V_87 * V_88 ,
struct V_65 * V_66 , T_1 V_191 )
{
struct V_61 * V_69 = (struct V_61 * ) V_2 ;
struct V_85 V_86 ;
F_64 ( & V_86 , V_88 , V_66 ) ;
V_191 = F_108 ( V_69 , & V_86 , V_191 ) ;
if ( ! V_69 -> V_194 ) {
V_2 -> V_160 = V_161 ;
} else {
V_69 -> V_194 = V_191 ;
V_69 -> V_2 . V_130 = F_110 ( 1UL , V_141 + V_193 ) ;
}
}
void F_111 ( struct V_65 * V_66 , struct V_48 * V_48 , T_1 V_191 ,
int V_89 , T_1 V_92 , T_7 V_104 , int V_93 )
{
const struct V_74 * V_75 = ( const struct V_74 * ) V_66 -> V_163 ;
struct V_85 V_86 ;
struct V_61 * V_69 ;
F_53 ( & V_86 , NULL , V_75 , V_89 ,
F_58 ( V_75 -> V_90 ) , V_104 , V_92 , V_93 ) ;
V_69 = F_112 ( V_48 , & V_86 ) ;
if ( ! F_113 ( V_69 ) ) {
F_108 ( V_69 , & V_86 , V_191 ) ;
F_96 ( V_69 ) ;
}
}
void F_114 ( struct V_65 * V_66 , struct V_87 * V_88 , T_1 V_191 )
{
const struct V_74 * V_75 = ( const struct V_74 * ) V_66 -> V_163 ;
struct V_85 V_86 ;
struct V_61 * V_69 ;
F_53 ( & V_86 , V_88 , V_75 , 0 , 0 , 0 , 0 , 0 ) ;
V_69 = F_112 ( F_115 ( V_88 ) , & V_86 ) ;
if ( ! F_113 ( V_69 ) ) {
F_108 ( V_69 , & V_86 , V_191 ) ;
F_96 ( V_69 ) ;
}
}
void F_116 ( struct V_65 * V_66 , struct V_48 * V_48 ,
int V_89 , T_1 V_92 , T_7 V_104 , int V_93 )
{
const struct V_74 * V_75 = ( const struct V_74 * ) V_66 -> V_163 ;
struct V_85 V_86 ;
struct V_61 * V_69 ;
F_53 ( & V_86 , NULL , V_75 , V_89 ,
F_58 ( V_75 -> V_90 ) , V_104 , V_92 , V_93 ) ;
V_69 = F_112 ( V_48 , & V_86 ) ;
if ( ! F_113 ( V_69 ) ) {
F_74 ( V_69 , V_66 , & V_86 , false ) ;
F_96 ( V_69 ) ;
}
}
void F_117 ( struct V_65 * V_66 , struct V_87 * V_88 )
{
const struct V_74 * V_75 = ( const struct V_74 * ) V_66 -> V_163 ;
struct V_85 V_86 ;
struct V_61 * V_69 ;
F_53 ( & V_86 , V_88 , V_75 , 0 , 0 , 0 , 0 , 0 ) ;
V_69 = F_112 ( F_115 ( V_88 ) , & V_86 ) ;
if ( ! F_113 ( V_69 ) ) {
F_74 ( V_69 , V_66 , & V_86 , false ) ;
F_96 ( V_69 ) ;
}
}
static struct V_1 * F_118 ( struct V_1 * V_2 , T_1 V_195 )
{
struct V_61 * V_69 = (struct V_61 * ) V_2 ;
if ( V_2 -> V_160 == V_161 || F_35 ( V_69 ) )
return NULL ;
return V_2 ;
}
static void F_119 ( struct V_65 * V_66 )
{
struct V_61 * V_69 ;
F_100 ( V_66 , V_190 , V_184 , 0 ) ;
V_69 = F_98 ( V_66 ) ;
if ( V_69 )
F_120 ( & V_69 -> V_2 , 0 ) ;
}
static int F_121 ( struct V_65 * V_66 )
{
F_122 ( L_13 ,
V_196 , & F_40 ( V_66 ) -> V_102 , & F_40 ( V_66 ) -> V_67 ,
V_66 -> V_4 ? V_66 -> V_4 -> V_164 : L_14 ) ;
F_107 ( V_66 ) ;
F_3 ( 1 ) ;
return 0 ;
}
void F_123 ( T_7 * V_197 , struct V_65 * V_66 , struct V_61 * V_69 )
{
T_6 V_39 ;
if ( F_124 ( V_69 ) )
V_39 = F_40 ( V_66 ) -> V_102 ;
else {
struct V_149 V_150 ;
struct V_85 V_86 ;
struct V_74 * V_75 ;
V_75 = F_40 ( V_66 ) ;
memset ( & V_86 , 0 , sizeof( V_86 ) ) ;
V_86 . V_67 = V_75 -> V_67 ;
V_86 . V_102 = V_75 -> V_102 ;
V_86 . V_198 = F_58 ( V_75 -> V_90 ) ;
V_86 . V_199 = V_69 -> V_2 . V_4 -> V_103 ;
V_86 . V_200 = V_66 -> V_4 -> V_103 ;
V_86 . V_201 = V_66 -> V_92 ;
F_60 () ;
if ( F_87 ( F_36 ( V_69 -> V_2 . V_4 ) , & V_86 , & V_150 ) == 0 )
V_39 = F_125 ( F_36 ( V_69 -> V_2 . V_4 ) , V_150 ) ;
else
V_39 = F_126 ( V_69 -> V_2 . V_4 ,
F_127 ( V_69 , V_75 -> V_67 ) ,
V_101 ) ;
F_63 () ;
}
memcpy ( V_197 , & V_39 , 4 ) ;
}
static void F_128 ( struct V_61 * V_69 , T_1 V_202 )
{
if ( ! ( V_69 -> V_2 . V_203 & 0xFFFF ) )
V_69 -> V_2 . V_203 |= V_202 & 0xFFFF ;
if ( ! ( V_69 -> V_2 . V_203 & 0xFFFF0000 ) )
V_69 -> V_2 . V_203 |= V_202 & 0xFFFF0000 ;
}
static unsigned int F_129 ( const struct V_1 * V_2 )
{
unsigned int V_204 = F_130 ( V_2 , V_205 ) ;
if ( V_204 == 0 ) {
V_204 = F_131 (unsigned int, dst->dev->mtu - 40 ,
ip_rt_min_advmss) ;
if ( V_204 > 65535 - 40 )
V_204 = 65535 - 40 ;
}
return V_204 ;
}
static unsigned int F_132 ( const struct V_1 * V_2 )
{
const struct V_61 * V_69 = ( const struct V_61 * ) V_2 ;
unsigned int V_191 = V_69 -> V_194 ;
if ( V_191 && F_133 ( V_141 , V_69 -> V_2 . V_130 ) )
V_191 = 0 ;
if ( ! V_191 )
V_191 = F_130 ( V_2 , V_206 ) ;
if ( V_191 && F_124 ( V_69 ) )
return V_191 ;
V_191 = V_2 -> V_4 -> V_191 ;
if ( F_134 ( F_135 ( V_2 , V_206 ) ) ) {
if ( V_69 -> V_71 && V_191 > 576 )
V_191 = 576 ;
}
if ( V_191 > V_207 )
V_191 = V_207 ;
return V_191 ;
}
static struct V_114 * F_136 ( struct V_126 * V_127 , T_6 V_67 )
{
struct V_115 * V_116 = V_127 -> V_133 ;
struct V_114 * V_117 ;
T_1 V_124 ;
if ( ! V_116 )
return NULL ;
V_124 = F_70 ( V_67 ) ;
for ( V_117 = F_61 ( V_116 [ V_124 ] . V_120 ) ; V_117 ;
V_117 = F_61 ( V_117 -> V_121 ) ) {
if ( V_117 -> V_136 == V_67 )
return V_117 ;
}
return NULL ;
}
static bool F_137 ( struct V_61 * V_69 , struct V_114 * V_117 ,
T_6 V_67 )
{
bool V_165 = false ;
F_45 ( & V_132 ) ;
if ( V_67 == V_117 -> V_136 ) {
struct V_61 * V_119 ;
if ( V_117 -> V_138 ) {
unsigned long V_130 = V_117 -> V_139 ;
unsigned long V_208 = V_130 - V_141 ;
if ( F_68 ( V_141 , V_130 ) ) {
V_69 -> V_194 = V_117 -> V_138 ;
F_120 ( & V_69 -> V_2 , V_208 ) ;
}
}
if ( V_117 -> V_137 ) {
V_69 -> V_166 |= V_167 ;
V_69 -> V_71 = V_117 -> V_137 ;
}
V_119 = F_61 ( V_117 -> V_123 ) ;
F_73 ( V_117 -> V_123 , V_69 ) ;
if ( V_119 )
F_65 ( V_119 ) ;
V_117 -> V_122 = V_141 ;
V_165 = true ;
} else {
V_69 -> V_2 . V_209 |= V_210 ;
}
F_48 ( & V_132 ) ;
return V_165 ;
}
static bool F_138 ( struct V_126 * V_127 , struct V_61 * V_69 )
{
struct V_61 * V_119 , * V_211 , * * V_212 ;
bool V_165 = true ;
if ( F_139 ( V_69 ) ) {
V_212 = (struct V_61 * * ) & V_127 -> V_213 ;
} else {
if ( ! V_127 -> V_214 )
goto V_215;
V_212 = (struct V_61 * * ) F_140 ( V_127 -> V_214 ) ;
}
V_119 = * V_212 ;
V_211 = F_141 ( V_212 , V_119 , V_69 ) ;
if ( V_211 == V_119 ) {
if ( V_119 )
F_65 ( V_119 ) ;
} else {
V_215:
V_69 -> V_2 . V_209 |= V_210 ;
V_165 = false ;
}
return V_165 ;
}
static void F_142 ( struct V_61 * V_69 )
{
F_45 ( & V_216 ) ;
F_143 ( & V_69 -> V_217 , & V_218 ) ;
F_48 ( & V_216 ) ;
}
static void F_144 ( struct V_1 * V_2 )
{
struct V_61 * V_69 = (struct V_61 * ) V_2 ;
if ( ! F_145 ( & V_69 -> V_217 ) ) {
F_45 ( & V_216 ) ;
F_146 ( & V_69 -> V_217 ) ;
F_48 ( & V_216 ) ;
}
}
void F_147 ( struct V_3 * V_4 )
{
if ( ! F_145 ( & V_218 ) ) {
struct V_48 * V_48 = F_36 ( V_4 ) ;
struct V_61 * V_69 ;
F_45 ( & V_216 ) ;
F_148 (rt, &rt_uncached_list, rt_uncached) {
if ( V_69 -> V_2 . V_4 != V_4 )
continue;
V_69 -> V_2 . V_4 = V_48 -> V_219 ;
F_149 ( V_69 -> V_2 . V_4 ) ;
F_150 ( V_4 ) ;
}
F_48 ( & V_216 ) ;
}
}
static bool F_151 ( const struct V_61 * V_69 )
{
return V_69 &&
V_69 -> V_2 . V_160 == V_220 &&
! F_35 ( V_69 ) ;
}
static void F_152 ( struct V_61 * V_69 , T_6 V_67 ,
const struct V_149 * V_150 ,
struct V_114 * V_117 ,
struct V_221 * V_222 , T_8 type , T_1 V_223 )
{
bool V_224 = false ;
if ( V_222 ) {
struct V_126 * V_127 = & F_88 ( * V_150 ) ;
if ( V_127 -> V_225 && V_127 -> V_226 == V_227 )
V_69 -> V_71 = V_127 -> V_225 ;
F_153 ( & V_69 -> V_2 , V_222 -> V_228 , true ) ;
#ifdef F_30
V_69 -> V_2 . V_203 = V_127 -> V_229 ;
#endif
if ( F_134 ( V_117 ) )
V_224 = F_137 ( V_69 , V_117 , V_67 ) ;
else if ( ! ( V_69 -> V_2 . V_209 & V_210 ) )
V_224 = F_138 ( V_127 , V_69 ) ;
}
if ( F_134 ( ! V_224 ) )
F_142 ( V_69 ) ;
#ifdef F_30
#ifdef F_154
F_128 ( V_69 , V_150 -> V_203 ) ;
#endif
F_128 ( V_69 , V_223 ) ;
#endif
}
static struct V_61 * F_155 ( struct V_3 * V_4 ,
bool V_230 , bool V_231 , bool V_232 )
{
return F_156 ( & V_19 , V_4 , 1 , V_220 ,
( V_232 ? 0 : ( V_233 | V_210 ) ) |
( V_230 ? V_234 : 0 ) |
( V_231 ? V_235 : 0 ) ) ;
}
static int F_157 ( struct V_65 * V_66 , T_6 V_67 , T_6 V_102 ,
T_7 V_90 , struct V_3 * V_4 , int V_236 )
{
struct V_61 * V_62 ;
struct V_147 * V_148 = F_76 ( V_4 ) ;
T_1 V_223 = 0 ;
int V_237 ;
if ( V_148 == NULL )
return - V_183 ;
if ( F_78 ( V_102 ) || F_79 ( V_102 ) ||
V_66 -> V_104 != F_47 ( V_238 ) )
goto V_239;
if ( F_158 ( ! F_159 ( V_148 ) ) )
if ( F_160 ( V_102 ) )
goto V_239;
if ( F_80 ( V_102 ) ) {
if ( ! F_161 ( V_67 ) )
goto V_239;
} else {
V_237 = F_162 ( V_66 , V_102 , 0 , V_90 , 0 , V_4 ,
V_148 , & V_223 ) ;
if ( V_237 < 0 )
goto V_240;
}
V_62 = F_155 ( F_36 ( V_4 ) -> V_219 ,
F_163 ( V_148 , V_241 ) , false , false ) ;
if ( ! V_62 )
goto V_242;
#ifdef F_30
V_62 -> V_2 . V_203 = V_223 ;
#endif
V_62 -> V_2 . V_243 = F_121 ;
V_62 -> V_63 = V_63 ( F_36 ( V_4 ) ) ;
V_62 -> V_166 = V_244 ;
V_62 -> V_245 = V_246 ;
V_62 -> V_247 = 1 ;
V_62 -> V_248 = 0 ;
V_62 -> V_194 = 0 ;
V_62 -> V_71 = 0 ;
F_164 ( & V_62 -> V_217 ) ;
if ( V_236 ) {
V_62 -> V_2 . V_249 = V_250 ;
V_62 -> V_166 |= V_251 ;
}
#ifdef F_165
if ( ! F_161 ( V_67 ) && F_166 ( V_148 ) )
V_62 -> V_2 . V_249 = V_252 ;
#endif
F_167 ( V_22 ) ;
F_168 ( V_66 , & V_62 -> V_2 ) ;
return 0 ;
V_242:
return - V_253 ;
V_239:
return - V_183 ;
V_240:
return V_237 ;
}
static void F_169 ( struct V_3 * V_4 ,
struct V_147 * V_148 ,
struct V_65 * V_66 ,
T_6 V_67 ,
T_6 V_102 )
{
F_167 ( V_26 ) ;
#ifdef F_91
if ( F_92 ( V_148 ) && F_170 () ) {
F_171 ( L_15 ,
& V_67 , & V_102 , V_4 -> V_164 ) ;
if ( V_4 -> V_254 && F_172 ( V_66 ) ) {
F_173 ( V_255 , L_16 ,
V_256 , 16 , 1 ,
F_174 ( V_66 ) ,
V_4 -> V_254 , true ) ;
}
}
#endif
}
static int F_175 ( struct V_65 * V_66 ,
const struct V_149 * V_150 ,
struct V_147 * V_148 ,
T_6 V_67 , T_6 V_102 , T_1 V_90 )
{
struct V_61 * V_62 ;
int V_237 ;
struct V_147 * V_257 ;
unsigned int V_209 = 0 ;
bool V_258 ;
T_1 V_223 ;
V_257 = F_76 ( F_176 ( * V_150 ) ) ;
if ( V_257 == NULL ) {
F_177 ( L_17 ) ;
return - V_183 ;
}
V_237 = F_162 ( V_66 , V_102 , V_67 , V_90 , F_178 ( * V_150 ) ,
V_148 -> V_4 , V_148 , & V_223 ) ;
if ( V_237 < 0 ) {
F_169 ( V_148 -> V_4 , V_148 , V_66 , V_67 ,
V_102 ) ;
goto V_259;
}
if ( V_257 == V_148 && V_237 &&
( F_81 ( V_257 ) ||
F_82 ( V_257 , V_102 , F_179 ( * V_150 ) ) ) )
V_209 |= V_260 ;
if ( V_66 -> V_104 != F_47 ( V_238 ) ) {
if ( V_257 == V_148 &&
F_180 ( V_148 ) == 0 ) {
V_237 = - V_183 ;
goto V_259;
}
}
V_258 = false ;
if ( V_150 -> V_222 ) {
if ( ! V_223 ) {
V_62 = F_61 ( F_88 ( * V_150 ) . V_213 ) ;
if ( F_151 ( V_62 ) ) {
F_181 ( V_66 , & V_62 -> V_2 ) ;
goto V_182;
}
V_258 = true ;
}
}
V_62 = F_155 ( V_257 -> V_4 ,
F_163 ( V_148 , V_241 ) ,
F_163 ( V_257 , V_261 ) , V_258 ) ;
if ( ! V_62 ) {
V_237 = - V_253 ;
goto V_259;
}
V_62 -> V_63 = V_63 ( F_36 ( V_62 -> V_2 . V_4 ) ) ;
V_62 -> V_166 = V_209 ;
V_62 -> V_245 = V_150 -> type ;
V_62 -> V_247 = 1 ;
V_62 -> V_248 = 0 ;
V_62 -> V_194 = 0 ;
V_62 -> V_71 = 0 ;
F_164 ( & V_62 -> V_217 ) ;
V_62 -> V_2 . V_249 = V_262 ;
V_62 -> V_2 . V_243 = V_263 ;
F_152 ( V_62 , V_67 , V_150 , NULL , V_150 -> V_222 , V_150 -> type , V_223 ) ;
F_168 ( V_66 , & V_62 -> V_2 ) ;
V_182:
V_237 = 0 ;
V_259:
return V_237 ;
}
static int F_182 ( struct V_65 * V_66 ,
struct V_149 * V_150 ,
const struct V_85 * V_86 ,
struct V_147 * V_148 ,
T_6 V_67 , T_6 V_102 , T_1 V_90 )
{
#ifdef F_183
if ( V_150 -> V_222 && V_150 -> V_222 -> V_264 > 1 )
F_184 ( V_150 ) ;
#endif
return F_175 ( V_66 , V_150 , V_148 , V_67 , V_102 , V_90 ) ;
}
static int F_185 ( struct V_65 * V_66 , T_6 V_67 , T_6 V_102 ,
T_7 V_90 , struct V_3 * V_4 )
{
struct V_149 V_150 ;
struct V_147 * V_148 = F_76 ( V_4 ) ;
struct V_85 V_86 ;
unsigned int V_209 = 0 ;
T_1 V_223 = 0 ;
struct V_61 * V_62 ;
int V_237 = - V_183 ;
struct V_48 * V_48 = F_36 ( V_4 ) ;
bool V_258 ;
if ( ! V_148 )
goto V_182;
if ( F_78 ( V_102 ) || F_79 ( V_102 ) )
goto V_265;
V_150 . V_222 = NULL ;
if ( F_79 ( V_67 ) || ( V_102 == 0 && V_67 == 0 ) )
goto V_266;
if ( F_80 ( V_102 ) )
goto V_265;
if ( F_80 ( V_67 ) )
goto V_267;
if ( F_158 ( ! F_159 ( V_148 ) ) ) {
if ( F_160 ( V_67 ) )
goto V_267;
if ( F_160 ( V_102 ) )
goto V_265;
}
V_86 . V_199 = 0 ;
V_86 . V_200 = V_4 -> V_103 ;
V_86 . V_201 = V_66 -> V_92 ;
V_86 . V_198 = V_90 ;
V_86 . V_268 = V_101 ;
V_86 . V_67 = V_67 ;
V_86 . V_102 = V_102 ;
V_237 = F_87 ( V_48 , & V_86 , & V_150 ) ;
if ( V_237 != 0 )
goto V_269;
F_167 ( V_21 ) ;
if ( V_150 . type == V_270 )
goto V_266;
if ( V_150 . type == V_271 ) {
V_237 = F_162 ( V_66 , V_102 , V_67 , V_90 ,
V_48 -> V_219 -> V_103 ,
V_4 , V_148 , & V_223 ) ;
if ( V_237 < 0 )
goto V_272;
goto V_273;
}
if ( ! F_105 ( V_148 ) )
goto V_269;
if ( V_150 . type != V_157 )
goto V_267;
V_237 = F_182 ( V_66 , & V_150 , & V_86 , V_148 , V_67 , V_102 , V_90 ) ;
V_182: return V_237 ;
V_266:
if ( V_66 -> V_104 != F_47 ( V_238 ) )
goto V_239;
if ( ! F_80 ( V_102 ) ) {
V_237 = F_162 ( V_66 , V_102 , 0 , V_90 , 0 , V_4 ,
V_148 , & V_223 ) ;
if ( V_237 < 0 )
goto V_272;
}
V_209 |= V_274 ;
V_150 . type = V_270 ;
F_167 ( V_24 ) ;
V_273:
V_258 = false ;
if ( V_150 . V_222 ) {
if ( ! V_223 ) {
V_62 = F_61 ( F_88 ( V_150 ) . V_213 ) ;
if ( F_151 ( V_62 ) ) {
F_181 ( V_66 , & V_62 -> V_2 ) ;
V_237 = 0 ;
goto V_182;
}
V_258 = true ;
}
}
V_62 = F_155 ( V_48 -> V_219 ,
F_163 ( V_148 , V_241 ) , false , V_258 ) ;
if ( ! V_62 )
goto V_242;
V_62 -> V_2 . V_249 = V_250 ;
V_62 -> V_2 . V_243 = F_121 ;
#ifdef F_30
V_62 -> V_2 . V_203 = V_223 ;
#endif
V_62 -> V_63 = V_63 ( V_48 ) ;
V_62 -> V_166 = V_209 | V_251 ;
V_62 -> V_245 = V_150 . type ;
V_62 -> V_247 = 1 ;
V_62 -> V_248 = 0 ;
V_62 -> V_194 = 0 ;
V_62 -> V_71 = 0 ;
F_164 ( & V_62 -> V_217 ) ;
if ( V_150 . type == V_275 ) {
V_62 -> V_2 . V_249 = F_104 ;
V_62 -> V_2 . error = - V_237 ;
V_62 -> V_166 &= ~ V_251 ;
}
if ( V_258 )
F_138 ( & F_88 ( V_150 ) , V_62 ) ;
F_168 ( V_66 , & V_62 -> V_2 ) ;
V_237 = 0 ;
goto V_182;
V_269:
F_167 ( V_23 ) ;
V_150 . type = V_275 ;
if ( V_237 == - V_276 )
V_237 = - V_180 ;
goto V_273;
V_267:
F_167 ( V_25 ) ;
#ifdef F_91
if ( F_92 ( V_148 ) )
F_102 ( L_18 ,
& V_67 , & V_102 , V_4 -> V_164 ) ;
#endif
V_239:
V_237 = - V_183 ;
goto V_182;
V_242:
V_237 = - V_253 ;
goto V_182;
V_265:
V_237 = - V_183 ;
V_272:
F_169 ( V_4 , V_148 , V_66 , V_67 , V_102 ) ;
goto V_182;
}
int F_186 ( struct V_65 * V_66 , T_6 V_67 , T_6 V_102 ,
T_7 V_90 , struct V_3 * V_4 )
{
int V_150 ;
F_60 () ;
if ( F_78 ( V_67 ) ) {
struct V_147 * V_148 = F_76 ( V_4 ) ;
if ( V_148 ) {
int V_236 = F_187 ( V_148 , V_67 , V_102 ,
F_40 ( V_66 ) -> V_104 ) ;
if ( V_236
#ifdef F_165
||
( ! F_161 ( V_67 ) &&
F_166 ( V_148 ) )
#endif
) {
int V_150 = F_157 ( V_66 , V_67 , V_102 ,
V_90 , V_4 , V_236 ) ;
F_63 () ;
return V_150 ;
}
}
F_63 () ;
return - V_183 ;
}
V_150 = F_185 ( V_66 , V_67 , V_102 , V_90 , V_4 ) ;
F_63 () ;
return V_150 ;
}
static struct V_61 * F_188 ( const struct V_149 * V_150 ,
const struct V_85 * V_86 , int V_277 ,
struct V_3 * V_278 ,
unsigned int V_209 )
{
struct V_221 * V_222 = V_150 -> V_222 ;
struct V_114 * V_117 ;
struct V_147 * V_148 ;
T_8 type = V_150 -> type ;
struct V_61 * V_62 ;
V_148 = F_76 ( V_278 ) ;
if ( ! V_148 )
return F_189 ( - V_183 ) ;
if ( F_158 ( ! F_159 ( V_148 ) ) )
if ( F_160 ( V_86 -> V_102 ) && ! ( V_278 -> V_209 & V_279 ) )
return F_189 ( - V_183 ) ;
if ( F_79 ( V_86 -> V_67 ) )
type = V_270 ;
else if ( F_78 ( V_86 -> V_67 ) )
type = V_246 ;
else if ( F_80 ( V_86 -> V_67 ) )
return F_189 ( - V_183 ) ;
if ( V_278 -> V_209 & V_279 )
V_209 |= V_251 ;
if ( type == V_270 ) {
V_209 |= V_274 | V_251 ;
V_222 = NULL ;
} else if ( type == V_246 ) {
V_209 |= V_244 | V_251 ;
if ( ! F_187 ( V_148 , V_86 -> V_67 , V_86 -> V_102 ,
V_86 -> V_280 ) )
V_209 &= ~ V_251 ;
if ( V_222 && V_150 -> V_281 < 4 )
V_222 = NULL ;
}
V_117 = NULL ;
if ( V_222 ) {
struct V_61 T_9 * * V_282 ;
V_117 = F_136 ( & F_88 ( * V_150 ) , V_86 -> V_67 ) ;
if ( V_117 )
V_282 = & V_117 -> V_123 ;
else
V_282 = F_140 ( F_88 ( * V_150 ) . V_214 ) ;
V_62 = F_61 ( * V_282 ) ;
if ( F_151 ( V_62 ) ) {
F_190 ( & V_62 -> V_2 ) ;
return V_62 ;
}
}
V_62 = F_155 ( V_278 ,
F_163 ( V_148 , V_241 ) ,
F_163 ( V_148 , V_261 ) ,
V_222 ) ;
if ( ! V_62 )
return F_189 ( - V_253 ) ;
V_62 -> V_2 . V_243 = V_263 ;
V_62 -> V_63 = V_63 ( F_36 ( V_278 ) ) ;
V_62 -> V_166 = V_209 ;
V_62 -> V_245 = type ;
V_62 -> V_247 = 0 ;
V_62 -> V_248 = V_277 ? : 0 ;
V_62 -> V_194 = 0 ;
V_62 -> V_71 = 0 ;
F_164 ( & V_62 -> V_217 ) ;
F_167 ( V_28 ) ;
if ( V_209 & V_251 )
V_62 -> V_2 . V_249 = V_250 ;
if ( V_209 & ( V_274 | V_244 ) ) {
if ( V_209 & V_251 &&
! ( V_278 -> V_209 & V_279 ) ) {
V_62 -> V_2 . V_243 = V_283 ;
F_167 ( V_29 ) ;
}
#ifdef F_165
if ( type == V_246 ) {
if ( F_166 ( V_148 ) &&
! F_161 ( V_86 -> V_67 ) ) {
V_62 -> V_2 . V_249 = V_252 ;
V_62 -> V_2 . V_243 = V_283 ;
}
}
#endif
}
F_152 ( V_62 , V_86 -> V_67 , V_150 , V_117 , V_222 , type , 0 ) ;
return V_62 ;
}
struct V_61 * F_112 ( struct V_48 * V_48 , struct V_85 * V_86 )
{
struct V_3 * V_278 = NULL ;
T_10 V_90 = F_191 ( V_86 ) ;
unsigned int V_209 = 0 ;
struct V_149 V_150 ;
struct V_61 * V_62 ;
int V_277 ;
V_150 . V_203 = 0 ;
V_150 . V_222 = NULL ;
V_150 . V_284 = NULL ;
V_277 = V_86 -> V_199 ;
V_86 -> V_200 = V_48 -> V_219 -> V_103 ;
V_86 -> V_198 = V_90 & V_285 ;
V_86 -> V_268 = ( ( V_90 & V_286 ) ?
V_227 : V_101 ) ;
F_60 () ;
if ( V_86 -> V_102 ) {
V_62 = F_189 ( - V_183 ) ;
if ( F_78 ( V_86 -> V_102 ) ||
F_79 ( V_86 -> V_102 ) ||
F_80 ( V_86 -> V_102 ) )
goto V_182;
if ( V_86 -> V_199 == 0 &&
( F_78 ( V_86 -> V_67 ) ||
F_79 ( V_86 -> V_67 ) ) ) {
V_278 = F_192 ( V_48 , V_86 -> V_102 , false ) ;
if ( V_278 == NULL )
goto V_182;
V_86 -> V_199 = V_278 -> V_103 ;
goto V_287;
}
if ( ! ( V_86 -> V_288 & V_289 ) ) {
if ( ! F_192 ( V_48 , V_86 -> V_102 , false ) )
goto V_182;
}
}
if ( V_86 -> V_199 ) {
V_278 = F_193 ( V_48 , V_86 -> V_199 ) ;
V_62 = F_189 ( - V_290 ) ;
if ( V_278 == NULL )
goto V_182;
if ( ! ( V_278 -> V_209 & V_291 ) || ! F_76 ( V_278 ) ) {
V_62 = F_189 ( - V_180 ) ;
goto V_182;
}
if ( F_161 ( V_86 -> V_67 ) ||
F_79 ( V_86 -> V_67 ) ) {
if ( ! V_86 -> V_102 )
V_86 -> V_102 = F_126 ( V_278 , 0 ,
V_227 ) ;
goto V_287;
}
if ( V_86 -> V_102 ) {
if ( F_78 ( V_86 -> V_67 ) )
V_86 -> V_102 = F_126 ( V_278 , 0 ,
V_86 -> V_268 ) ;
else if ( ! V_86 -> V_67 )
V_86 -> V_102 = F_126 ( V_278 , 0 ,
V_292 ) ;
}
}
if ( ! V_86 -> V_67 ) {
V_86 -> V_67 = V_86 -> V_102 ;
if ( ! V_86 -> V_67 )
V_86 -> V_67 = V_86 -> V_102 = F_194 ( V_293 ) ;
V_278 = V_48 -> V_219 ;
V_86 -> V_199 = V_48 -> V_219 -> V_103 ;
V_150 . type = V_271 ;
V_209 |= V_251 ;
goto V_287;
}
if ( F_87 ( V_48 , V_86 , & V_150 ) ) {
V_150 . V_222 = NULL ;
V_150 . V_284 = NULL ;
if ( V_86 -> V_199 ) {
if ( V_86 -> V_102 == 0 )
V_86 -> V_102 = F_126 ( V_278 , 0 ,
V_227 ) ;
V_150 . type = V_157 ;
goto V_287;
}
V_62 = F_189 ( - V_180 ) ;
goto V_182;
}
if ( V_150 . type == V_271 ) {
if ( ! V_86 -> V_102 ) {
if ( V_150 . V_222 -> V_294 )
V_86 -> V_102 = V_150 . V_222 -> V_294 ;
else
V_86 -> V_102 = V_86 -> V_67 ;
}
V_278 = V_48 -> V_219 ;
V_86 -> V_199 = V_278 -> V_103 ;
V_209 |= V_251 ;
goto V_287;
}
#ifdef F_183
if ( V_150 . V_222 -> V_264 > 1 && V_86 -> V_199 == 0 )
F_184 ( & V_150 ) ;
else
#endif
if ( ! V_150 . V_281 &&
V_150 . V_284 -> V_295 > 1 &&
V_150 . type == V_157 && ! V_86 -> V_199 )
F_195 ( & V_150 ) ;
if ( ! V_86 -> V_102 )
V_86 -> V_102 = F_125 ( V_48 , V_150 ) ;
V_278 = F_176 ( V_150 ) ;
V_86 -> V_199 = V_278 -> V_103 ;
V_287:
V_62 = F_188 ( & V_150 , V_86 , V_277 , V_278 , V_209 ) ;
V_182:
F_63 () ;
return V_62 ;
}
static struct V_1 * F_196 ( struct V_1 * V_2 , T_1 V_195 )
{
return NULL ;
}
static unsigned int F_197 ( const struct V_1 * V_2 )
{
unsigned int V_191 = F_130 ( V_2 , V_206 ) ;
return V_191 ? : V_2 -> V_4 -> V_191 ;
}
static void F_198 ( struct V_1 * V_2 , struct V_87 * V_88 ,
struct V_65 * V_66 , T_1 V_191 )
{
}
static void F_199 ( struct V_1 * V_2 , struct V_87 * V_88 ,
struct V_65 * V_66 )
{
}
static T_1 * F_200 ( struct V_1 * V_2 ,
unsigned long V_6 )
{
return NULL ;
}
struct V_1 * F_201 ( struct V_48 * V_48 , struct V_1 * V_296 )
{
struct V_61 * V_297 = (struct V_61 * ) V_296 ;
struct V_61 * V_69 ;
V_69 = F_156 ( & V_298 , NULL , 1 , V_299 , 0 ) ;
if ( V_69 ) {
struct V_1 * V_300 = & V_69 -> V_2 ;
V_300 -> V_301 = 1 ;
V_300 -> V_249 = V_302 ;
V_300 -> V_243 = V_302 ;
V_300 -> V_4 = V_297 -> V_2 . V_4 ;
if ( V_300 -> V_4 )
F_149 ( V_300 -> V_4 ) ;
V_69 -> V_247 = V_297 -> V_247 ;
V_69 -> V_248 = V_297 -> V_248 ;
V_69 -> V_194 = V_297 -> V_194 ;
V_69 -> V_63 = V_63 ( V_48 ) ;
V_69 -> V_166 = V_297 -> V_166 ;
V_69 -> V_245 = V_297 -> V_245 ;
V_69 -> V_71 = V_297 -> V_71 ;
F_164 ( & V_69 -> V_217 ) ;
F_202 ( V_300 ) ;
}
F_203 ( V_296 ) ;
return V_69 ? & V_69 -> V_2 : F_189 ( - V_43 ) ;
}
struct V_61 * F_204 ( struct V_48 * V_48 , struct V_85 * V_303 ,
struct V_87 * V_88 )
{
struct V_61 * V_69 = F_112 ( V_48 , V_303 ) ;
if ( F_113 ( V_69 ) )
return V_69 ;
if ( V_303 -> V_280 )
V_69 = (struct V_61 * ) F_205 ( V_48 , & V_69 -> V_2 ,
F_206 ( V_303 ) ,
V_88 , 0 ) ;
return V_69 ;
}
static int F_207 ( struct V_48 * V_48 , T_6 V_2 , T_6 V_39 ,
struct V_85 * V_86 , struct V_65 * V_66 , T_1 V_304 ,
T_1 V_8 , int V_305 , int V_306 , unsigned int V_209 )
{
struct V_61 * V_69 = F_98 ( V_66 ) ;
struct V_307 * V_308 ;
struct V_309 * V_310 ;
unsigned long V_130 = 0 ;
T_1 error ;
T_1 V_311 [ V_312 ] ;
V_310 = F_208 ( V_66 , V_304 , V_8 , V_305 , sizeof( * V_308 ) , V_209 ) ;
if ( V_310 == NULL )
return - V_313 ;
V_308 = F_209 ( V_310 ) ;
V_308 -> V_314 = V_315 ;
V_308 -> V_316 = 32 ;
V_308 -> V_317 = 0 ;
V_308 -> V_318 = V_86 -> V_198 ;
V_308 -> V_319 = V_320 ;
if ( F_210 ( V_66 , V_321 , V_320 ) )
goto V_322;
V_308 -> V_323 = V_69 -> V_245 ;
V_308 -> V_324 = V_101 ;
V_308 -> V_325 = V_326 ;
V_308 -> V_327 = ( V_69 -> V_166 & ~ 0xFFFF ) | V_328 ;
if ( V_69 -> V_166 & V_329 )
V_308 -> V_327 |= V_330 ;
if ( F_211 ( V_66 , V_331 , V_2 ) )
goto V_322;
if ( V_39 ) {
V_308 -> V_317 = 32 ;
if ( F_211 ( V_66 , V_332 , V_39 ) )
goto V_322;
}
if ( V_69 -> V_2 . V_4 &&
F_210 ( V_66 , V_333 , V_69 -> V_2 . V_4 -> V_103 ) )
goto V_322;
#ifdef F_30
if ( V_69 -> V_2 . V_203 &&
F_210 ( V_66 , V_334 , V_69 -> V_2 . V_203 ) )
goto V_322;
#endif
if ( ! F_139 ( V_69 ) &&
V_86 -> V_102 != V_39 ) {
if ( F_211 ( V_66 , V_335 , V_86 -> V_102 ) )
goto V_322;
}
if ( V_69 -> V_71 &&
F_211 ( V_66 , V_336 , V_69 -> V_71 ) )
goto V_322;
memcpy ( V_311 , F_212 ( & V_69 -> V_2 ) , sizeof( V_311 ) ) ;
if ( V_69 -> V_194 )
V_311 [ V_206 - 1 ] = V_69 -> V_194 ;
if ( F_213 ( V_66 , V_311 ) < 0 )
goto V_322;
if ( V_86 -> V_201 &&
F_211 ( V_66 , V_337 , V_86 -> V_201 ) )
goto V_322;
error = V_69 -> V_2 . error ;
V_130 = V_69 -> V_2 . V_130 ;
if ( V_130 ) {
if ( F_68 ( V_141 , V_130 ) )
V_130 -= V_141 ;
else
V_130 = 0 ;
}
if ( F_139 ( V_69 ) ) {
if ( F_210 ( V_66 , V_338 , V_69 -> V_248 ) )
goto V_322;
}
if ( F_214 ( V_66 , & V_69 -> V_2 , 0 , V_130 , error ) < 0 )
goto V_322;
return F_215 ( V_66 , V_310 ) ;
V_322:
F_216 ( V_66 , V_310 ) ;
return - V_313 ;
}
static int F_217 ( struct V_65 * V_339 , struct V_309 * V_310 , void * V_340 )
{
struct V_48 * V_48 = F_115 ( V_339 -> V_88 ) ;
struct V_307 * V_341 ;
struct V_342 * V_343 [ V_344 + 1 ] ;
struct V_61 * V_69 = NULL ;
struct V_85 V_86 ;
T_6 V_2 = 0 ;
T_6 V_39 = 0 ;
T_1 V_345 ;
int V_237 ;
int V_92 ;
struct V_65 * V_66 ;
V_237 = F_218 ( V_310 , sizeof( * V_341 ) , V_343 , V_344 , V_346 ) ;
if ( V_237 < 0 )
goto V_347;
V_341 = F_209 ( V_310 ) ;
V_66 = F_219 ( V_348 , V_42 ) ;
if ( V_66 == NULL ) {
V_237 = - V_253 ;
goto V_347;
}
F_220 ( V_66 ) ;
F_221 ( V_66 ) ;
F_40 ( V_66 ) -> V_104 = V_349 ;
F_222 ( V_66 , V_350 + sizeof( struct V_74 ) ) ;
V_39 = V_343 [ V_332 ] ? F_223 ( V_343 [ V_332 ] ) : 0 ;
V_2 = V_343 [ V_331 ] ? F_223 ( V_343 [ V_331 ] ) : 0 ;
V_345 = V_343 [ V_338 ] ? F_224 ( V_343 [ V_338 ] ) : 0 ;
V_92 = V_343 [ V_337 ] ? F_224 ( V_343 [ V_337 ] ) : 0 ;
memset ( & V_86 , 0 , sizeof( V_86 ) ) ;
V_86 . V_67 = V_2 ;
V_86 . V_102 = V_39 ;
V_86 . V_198 = V_341 -> V_318 ;
V_86 . V_199 = V_343 [ V_333 ] ? F_224 ( V_343 [ V_333 ] ) : 0 ;
V_86 . V_201 = V_92 ;
if ( V_345 ) {
struct V_3 * V_4 ;
V_4 = F_225 ( V_48 , V_345 ) ;
if ( V_4 == NULL ) {
V_237 = - V_290 ;
goto V_351;
}
V_66 -> V_104 = F_47 ( V_238 ) ;
V_66 -> V_4 = V_4 ;
V_66 -> V_92 = V_92 ;
F_226 () ;
V_237 = F_227 ( V_66 , V_2 , V_39 , V_341 -> V_318 , V_4 ) ;
F_228 () ;
V_69 = F_98 ( V_66 ) ;
if ( V_237 == 0 && V_69 -> V_2 . error )
V_237 = - V_69 -> V_2 . error ;
} else {
V_69 = F_229 ( V_48 , & V_86 ) ;
V_237 = 0 ;
if ( F_113 ( V_69 ) )
V_237 = F_230 ( V_69 ) ;
}
if ( V_237 )
goto V_351;
F_168 ( V_66 , & V_69 -> V_2 ) ;
if ( V_341 -> V_327 & V_330 )
V_69 -> V_166 |= V_329 ;
V_237 = F_207 ( V_48 , V_2 , V_39 , & V_86 , V_66 ,
F_231 ( V_339 ) . V_304 , V_310 -> V_352 ,
V_353 , 0 , 0 ) ;
if ( V_237 <= 0 )
goto V_351;
V_237 = F_232 ( V_66 , V_48 , F_231 ( V_339 ) . V_304 ) ;
V_347:
return V_237 ;
V_351:
F_107 ( V_66 ) ;
goto V_347;
}
int F_233 ( struct V_65 * V_66 , struct V_354 * V_355 )
{
return V_66 -> V_356 ;
}
void F_234 ( struct V_147 * V_148 )
{
F_37 ( F_36 ( V_148 -> V_4 ) ) ;
}
static int F_235 ( T_11 * V_357 , int V_358 ,
void T_12 * V_359 ,
T_13 * V_360 , T_2 * V_361 )
{
if ( V_358 ) {
F_37 ( (struct V_48 * ) V_357 -> V_362 ) ;
return 0 ;
}
return - V_183 ;
}
static T_3 int F_236 ( struct V_48 * V_48 )
{
struct T_11 * V_363 ;
V_363 = V_364 ;
if ( ! F_237 ( V_48 , & V_365 ) ) {
V_363 = F_238 ( V_363 , sizeof( V_364 ) , V_42 ) ;
if ( V_363 == NULL )
goto V_366;
}
V_363 [ 0 ] . V_362 = V_48 ;
V_48 -> V_83 . V_367 = F_239 ( V_48 , L_19 , V_363 ) ;
if ( V_48 -> V_83 . V_367 == NULL )
goto V_368;
return 0 ;
V_368:
if ( V_363 != V_364 )
F_24 ( V_363 ) ;
V_366:
return - V_43 ;
}
static T_4 void F_240 ( struct V_48 * V_48 )
{
struct T_11 * V_363 ;
V_363 = V_48 -> V_83 . V_367 -> V_369 ;
F_241 ( V_48 -> V_83 . V_367 ) ;
F_242 ( V_363 == V_364 ) ;
F_24 ( V_363 ) ;
}
static T_3 int F_243 ( struct V_48 * V_48 )
{
F_244 ( & V_48 -> V_63 , 0 ) ;
F_245 ( & V_48 -> V_83 . V_370 ,
sizeof( V_48 -> V_83 . V_370 ) ) ;
return 0 ;
}
static int T_3 F_246 ( struct V_48 * V_48 )
{
struct V_371 * V_372 = F_247 ( sizeof( * V_372 ) , V_42 ) ;
if ( ! V_372 )
return - V_43 ;
F_248 ( V_372 ) ;
V_48 -> V_83 . V_84 = V_372 ;
return 0 ;
}
static void T_4 F_249 ( struct V_48 * V_48 )
{
struct V_371 * V_372 = V_48 -> V_83 . V_84 ;
V_48 -> V_83 . V_84 = NULL ;
F_250 ( V_372 ) ;
F_24 ( V_372 ) ;
}
int T_5 F_251 ( void )
{
int V_373 = 0 ;
#ifdef F_30
V_38 = F_252 ( 256 * sizeof( struct V_38 ) , F_253 ( struct V_38 ) ) ;
if ( ! V_38 )
F_254 ( L_20 ) ;
#endif
V_19 . V_374 =
F_255 ( L_21 , sizeof( struct V_61 ) , 0 ,
V_375 | V_376 , NULL ) ;
V_298 . V_374 = V_19 . V_374 ;
if ( F_256 ( & V_19 ) < 0 )
F_254 ( L_22 ) ;
if ( F_256 ( & V_298 ) < 0 )
F_254 ( L_23 ) ;
V_19 . V_377 = ~ 0 ;
V_378 = V_379 ;
F_257 () ;
F_258 () ;
if ( F_33 () )
F_259 ( L_24 ) ;
#ifdef F_260
F_261 () ;
F_262 ( V_378 ) ;
#endif
F_263 ( V_380 , V_381 , F_217 , NULL , NULL ) ;
#ifdef F_264
F_34 ( & V_382 ) ;
#endif
F_34 ( & V_383 ) ;
F_34 ( & V_384 ) ;
return V_373 ;
}
void T_5 F_265 ( void )
{
F_239 ( & V_365 , L_19 , V_385 ) ;
}
