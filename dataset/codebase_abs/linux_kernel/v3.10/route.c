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
V_50 = F_28 ( L_8 , V_51 , V_48 -> V_52 ,
& V_53 ) ;
if ( ! V_50 )
goto V_54;
V_50 = F_28 ( L_8 , V_51 ,
V_48 -> V_55 , & V_56 ) ;
if ( ! V_50 )
goto V_57;
#ifdef F_29
V_50 = F_28 ( L_9 , 0 , V_48 -> V_52 , & V_58 ) ;
if ( ! V_50 )
goto V_59;
#endif
return 0 ;
#ifdef F_29
V_59:
F_30 ( L_8 , V_48 -> V_55 ) ;
#endif
V_57:
F_30 ( L_8 , V_48 -> V_52 ) ;
V_54:
return - V_43 ;
}
static void T_4 F_31 ( struct V_48 * V_48 )
{
F_30 ( L_8 , V_48 -> V_55 ) ;
F_30 ( L_8 , V_48 -> V_52 ) ;
#ifdef F_29
F_30 ( L_9 , V_48 -> V_52 ) ;
#endif
}
static int T_5 F_32 ( void )
{
return F_33 ( & V_60 ) ;
}
static inline int F_32 ( void )
{
return 0 ;
}
static inline bool F_34 ( const struct V_61 * V_62 )
{
return V_62 -> V_63 != V_63 ( F_35 ( V_62 -> V_2 . V_4 ) ) ;
}
void F_36 ( struct V_48 * V_48 )
{
F_37 ( V_48 ) ;
}
static struct V_64 * F_38 ( const struct V_1 * V_2 ,
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
V_68 = & F_39 ( V_66 ) -> V_67 ;
V_70 = F_40 ( V_4 , * ( V_72 T_1 * ) V_68 ) ;
if ( V_70 )
return V_70 ;
return F_41 ( & V_73 , V_68 , V_4 ) ;
}
static void F_42 ( struct V_74 * V_75 )
{
static F_43 ( V_76 ) ;
static T_1 V_77 ;
T_1 V_78 ;
F_44 ( & V_76 ) ;
V_78 = F_45 ( ( V_72 T_6 ) V_77 ^ V_75 -> V_67 ) ;
V_75 -> V_79 = F_46 ( V_78 & 0xFFFF ) ;
V_77 = V_78 ;
F_47 ( & V_76 ) ;
}
void F_48 ( struct V_74 * V_75 , struct V_1 * V_2 , int V_80 )
{
struct V_48 * V_48 = F_35 ( V_2 -> V_4 ) ;
struct V_81 * V_82 ;
V_82 = F_49 ( V_48 -> V_83 . V_84 , V_75 -> V_67 , 1 ) ;
if ( V_82 ) {
V_75 -> V_79 = F_46 ( F_50 ( V_82 , V_80 ) ) ;
F_51 ( V_82 ) ;
return;
}
F_42 ( V_75 ) ;
}
static void F_52 ( struct V_85 * V_86 , const struct V_87 * V_88 ,
const struct V_74 * V_75 ,
int V_89 , T_7 V_90 ,
T_7 V_91 , T_1 V_92 , int V_93 )
{
if ( V_88 ) {
const struct V_94 * V_95 = F_53 ( V_88 ) ;
V_89 = V_88 -> V_96 ;
V_92 = V_88 -> V_97 ;
V_90 = F_54 ( V_88 ) ;
V_91 = V_95 -> V_98 ? V_99 : V_88 -> V_100 ;
}
F_55 ( V_86 , V_89 , V_92 , V_90 ,
V_101 , V_91 ,
V_93 ,
V_75 -> V_67 , V_75 -> V_102 , 0 , 0 ) ;
}
static void F_56 ( struct V_85 * V_86 , const struct V_65 * V_66 ,
const struct V_87 * V_88 )
{
const struct V_74 * V_75 = F_39 ( V_66 ) ;
int V_89 = V_66 -> V_4 -> V_103 ;
T_7 V_90 = F_57 ( V_75 -> V_90 ) ;
T_7 V_91 = V_75 -> V_104 ;
T_1 V_92 = V_66 -> V_92 ;
F_52 ( V_86 , V_88 , V_75 , V_89 , V_90 , V_91 , V_92 , 0 ) ;
}
static void F_58 ( struct V_85 * V_86 , const struct V_87 * V_88 )
{
const struct V_94 * V_95 = F_53 ( V_88 ) ;
const struct V_105 * V_106 ;
T_6 V_67 = V_95 -> V_107 ;
F_59 () ;
V_106 = F_60 ( V_95 -> V_106 ) ;
if ( V_106 && V_106 -> V_108 . V_109 )
V_67 = V_106 -> V_108 . V_110 ;
F_55 ( V_86 , V_88 -> V_96 , V_88 -> V_97 ,
F_54 ( V_88 ) , V_101 ,
V_95 -> V_98 ? V_99 : V_88 -> V_100 ,
F_61 ( V_88 ) ,
V_67 , V_95 -> V_111 , 0 , 0 ) ;
F_62 () ;
}
static void F_63 ( struct V_85 * V_86 , const struct V_87 * V_88 ,
const struct V_65 * V_66 )
{
if ( V_66 )
F_56 ( V_86 , V_66 , V_88 ) ;
else
F_58 ( V_86 , V_88 ) ;
}
static inline void F_64 ( struct V_61 * V_69 )
{
F_65 ( & V_69 -> V_2 . V_112 , V_113 ) ;
}
static struct V_114 * F_66 ( struct V_115 * V_116 )
{
struct V_114 * V_117 , * V_118 ;
struct V_61 * V_119 ;
V_118 = F_60 ( V_116 -> V_120 ) ;
for ( V_117 = F_60 ( V_118 -> V_121 ) ; V_117 ;
V_117 = F_60 ( V_117 -> V_121 ) ) {
if ( F_67 ( V_117 -> V_122 , V_118 -> V_122 ) )
V_118 = V_117 ;
}
V_119 = F_60 ( V_118 -> V_123 ) ;
if ( V_119 ) {
F_68 ( V_118 -> V_123 , NULL ) ;
F_64 ( V_119 ) ;
}
return V_118 ;
}
static inline T_1 F_69 ( T_6 V_67 )
{
T_1 V_124 ;
V_124 = ( V_72 T_1 ) V_67 ;
V_124 ^= ( V_124 >> 11 ) ^ ( V_124 >> 22 ) ;
return V_124 & ( V_125 - 1 ) ;
}
static void F_70 ( struct V_126 * V_127 , T_6 V_67 , T_6 V_128 ,
T_1 V_129 , unsigned long V_130 )
{
struct V_115 * V_116 ;
struct V_114 * V_117 ;
int V_131 ;
T_1 V_124 = F_69 ( V_67 ) ;
F_44 ( & V_132 ) ;
V_116 = V_127 -> V_133 ;
if ( ! V_116 ) {
V_116 = F_71 ( V_125 * sizeof( * V_116 ) , V_134 ) ;
if ( ! V_116 )
goto V_135;
V_127 -> V_133 = V_116 ;
}
V_116 += V_124 ;
V_131 = 0 ;
for ( V_117 = F_60 ( V_116 -> V_120 ) ; V_117 ;
V_117 = F_60 ( V_117 -> V_121 ) ) {
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
V_117 = F_66 ( V_116 ) ;
else {
V_117 = F_71 ( sizeof( * V_117 ) , V_134 ) ;
if ( ! V_117 )
goto V_135;
V_117 -> V_121 = V_116 -> V_120 ;
F_72 ( V_116 -> V_120 , V_117 ) ;
}
V_117 -> V_136 = V_67 ;
V_117 -> V_137 = V_128 ;
V_117 -> V_138 = V_129 ;
V_117 -> V_139 = V_130 ;
}
V_117 -> V_122 = V_141 ;
V_135:
F_47 ( & V_132 ) ;
return;
}
static void F_73 ( struct V_61 * V_69 , struct V_65 * V_66 , struct V_85 * V_86 ,
bool V_142 )
{
T_6 V_143 = F_74 ( V_66 ) -> V_144 . V_145 ;
T_6 V_146 = F_39 ( V_66 ) -> V_102 ;
struct V_3 * V_4 = V_66 -> V_4 ;
struct V_147 * V_148 ;
struct V_149 V_150 ;
struct V_64 * V_70 ;
struct V_48 * V_48 ;
switch ( F_74 ( V_66 ) -> V_151 & 7 ) {
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
V_148 = F_75 ( V_4 ) ;
if ( ! V_148 )
return;
V_48 = F_35 ( V_4 ) ;
if ( V_143 == V_146 || ! F_76 ( V_148 ) ||
F_77 ( V_143 ) || F_78 ( V_143 ) ||
F_79 ( V_143 ) )
goto V_156;
if ( ! F_80 ( V_148 ) ) {
if ( ! F_81 ( V_148 , V_143 , V_146 ) )
goto V_156;
if ( F_82 ( V_148 ) && F_83 ( V_143 , V_4 ) )
goto V_156;
} else {
if ( F_84 ( V_48 , V_143 ) != V_157 )
goto V_156;
}
V_70 = F_38 ( & V_69 -> V_2 , NULL , & V_143 ) ;
if ( V_70 ) {
if ( ! ( V_70 -> V_158 & V_159 ) ) {
F_85 ( V_70 , NULL ) ;
} else {
if ( F_86 ( V_48 , V_86 , & V_150 ) == 0 ) {
struct V_126 * V_127 = & F_87 ( V_150 ) ;
F_70 ( V_127 , V_86 -> V_67 , V_143 ,
0 , 0 ) ;
}
if ( V_142 )
V_69 -> V_2 . V_160 = V_161 ;
F_88 ( V_162 , V_70 ) ;
}
F_89 ( V_70 ) ;
}
return;
V_156:
#ifdef F_90
if ( F_91 ( V_148 ) ) {
const struct V_74 * V_75 = ( const struct V_74 * ) V_66 -> V_163 ;
T_6 V_67 = V_75 -> V_67 ;
T_6 V_102 = V_75 -> V_102 ;
F_92 ( L_10
L_11 ,
& V_146 , V_4 -> V_164 , & V_143 ,
& V_102 , & V_67 ) ;
}
#endif
;
}
static void F_93 ( struct V_1 * V_2 , struct V_87 * V_88 , struct V_65 * V_66 )
{
struct V_61 * V_69 ;
struct V_85 V_86 ;
const struct V_74 * V_75 = ( const struct V_74 * ) V_66 -> V_163 ;
int V_89 = V_66 -> V_4 -> V_103 ;
T_7 V_90 = F_57 ( V_75 -> V_90 ) ;
T_7 V_91 = V_75 -> V_104 ;
T_1 V_92 = V_66 -> V_92 ;
V_69 = (struct V_61 * ) V_2 ;
F_52 ( & V_86 , V_88 , V_75 , V_89 , V_90 , V_91 , V_92 , 0 ) ;
F_73 ( V_69 , V_66 , & V_86 , true ) ;
}
static struct V_1 * F_94 ( struct V_1 * V_2 )
{
struct V_61 * V_69 = (struct V_61 * ) V_2 ;
struct V_1 * V_165 = V_2 ;
if ( V_69 ) {
if ( V_2 -> V_160 > 0 ) {
F_95 ( V_69 ) ;
V_165 = NULL ;
} else if ( ( V_69 -> V_166 & V_167 ) ||
V_69 -> V_2 . V_130 ) {
F_95 ( V_69 ) ;
V_165 = NULL ;
}
}
return V_165 ;
}
void F_96 ( struct V_65 * V_66 )
{
struct V_61 * V_69 = F_97 ( V_66 ) ;
struct V_147 * V_148 ;
struct V_81 * V_82 ;
struct V_48 * V_48 ;
int V_168 ;
F_59 () ;
V_148 = F_75 ( V_69 -> V_2 . V_4 ) ;
if ( ! V_148 || ! F_98 ( V_148 ) ) {
F_62 () ;
return;
}
V_168 = F_91 ( V_148 ) ;
F_62 () ;
V_48 = F_35 ( V_69 -> V_2 . V_4 ) ;
V_82 = F_49 ( V_48 -> V_83 . V_84 , F_39 ( V_66 ) -> V_102 , 1 ) ;
if ( ! V_82 ) {
F_99 ( V_66 , V_169 , V_154 ,
F_100 ( V_69 , F_39 ( V_66 ) -> V_67 ) ) ;
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
T_6 V_128 = F_100 ( V_69 , F_39 ( V_66 ) -> V_67 ) ;
F_99 ( V_66 , V_169 , V_154 , V_128 ) ;
V_82 -> V_170 = V_141 ;
++ V_82 -> V_172 ;
#ifdef F_90
if ( V_168 &&
V_82 -> V_172 == V_173 )
F_102 ( L_12 ,
& F_39 ( V_66 ) -> V_102 , F_103 ( V_66 ) ,
& F_39 ( V_66 ) -> V_67 , & V_128 ) ;
#endif
}
V_174:
F_51 ( V_82 ) ;
}
static int F_104 ( struct V_65 * V_66 )
{
struct V_147 * V_148 = F_75 ( V_66 -> V_4 ) ;
struct V_61 * V_69 = F_97 ( V_66 ) ;
struct V_81 * V_82 ;
unsigned long V_176 ;
struct V_48 * V_48 ;
bool V_177 ;
int V_151 ;
V_48 = F_35 ( V_69 -> V_2 . V_4 ) ;
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
V_82 = F_49 ( V_48 -> V_83 . V_84 , F_39 ( V_66 ) -> V_102 , 1 ) ;
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
F_51 ( V_82 ) ;
}
if ( V_177 )
F_99 ( V_66 , V_190 , V_151 , 0 ) ;
V_182: F_107 ( V_66 ) ;
return 0 ;
}
static void F_108 ( struct V_61 * V_69 , struct V_85 * V_86 , T_1 V_191 )
{
struct V_1 * V_2 = & V_69 -> V_2 ;
struct V_149 V_150 ;
if ( F_109 ( V_2 , V_192 ) )
return;
if ( V_2 -> V_4 -> V_191 < V_191 )
return;
if ( V_191 < V_193 )
V_191 = V_193 ;
if ( ! V_69 -> V_194 ) {
V_2 -> V_160 = V_161 ;
} else {
V_69 -> V_194 = V_191 ;
V_2 -> V_130 = F_110 ( 1UL , V_141 + V_195 ) ;
}
F_59 () ;
if ( F_86 ( F_35 ( V_2 -> V_4 ) , V_86 , & V_150 ) == 0 ) {
struct V_126 * V_127 = & F_87 ( V_150 ) ;
F_70 ( V_127 , V_86 -> V_67 , 0 , V_191 ,
V_141 + V_195 ) ;
}
F_62 () ;
}
static void F_111 ( struct V_1 * V_2 , struct V_87 * V_88 ,
struct V_65 * V_66 , T_1 V_191 )
{
struct V_61 * V_69 = (struct V_61 * ) V_2 ;
struct V_85 V_86 ;
F_63 ( & V_86 , V_88 , V_66 ) ;
F_108 ( V_69 , & V_86 , V_191 ) ;
}
void F_112 ( struct V_65 * V_66 , struct V_48 * V_48 , T_1 V_191 ,
int V_89 , T_1 V_92 , T_7 V_104 , int V_93 )
{
const struct V_74 * V_75 = ( const struct V_74 * ) V_66 -> V_163 ;
struct V_85 V_86 ;
struct V_61 * V_69 ;
F_52 ( & V_86 , NULL , V_75 , V_89 ,
F_57 ( V_75 -> V_90 ) , V_104 , V_92 , V_93 ) ;
V_69 = F_113 ( V_48 , & V_86 ) ;
if ( ! F_114 ( V_69 ) ) {
F_108 ( V_69 , & V_86 , V_191 ) ;
F_95 ( V_69 ) ;
}
}
static void F_115 ( struct V_65 * V_66 , struct V_87 * V_88 , T_1 V_191 )
{
const struct V_74 * V_75 = ( const struct V_74 * ) V_66 -> V_163 ;
struct V_85 V_86 ;
struct V_61 * V_69 ;
F_52 ( & V_86 , V_88 , V_75 , 0 , 0 , 0 , 0 , 0 ) ;
V_69 = F_113 ( F_116 ( V_88 ) , & V_86 ) ;
if ( ! F_114 ( V_69 ) ) {
F_108 ( V_69 , & V_86 , V_191 ) ;
F_95 ( V_69 ) ;
}
}
void F_117 ( struct V_65 * V_66 , struct V_87 * V_88 , T_1 V_191 )
{
const struct V_74 * V_75 = ( const struct V_74 * ) V_66 -> V_163 ;
struct V_85 V_86 ;
struct V_61 * V_69 ;
struct V_1 * V_2 ;
bool V_196 = false ;
F_118 ( V_88 ) ;
V_69 = (struct V_61 * ) F_119 ( V_88 ) ;
if ( F_120 ( V_88 ) || ! V_69 ) {
F_115 ( V_66 , V_88 , V_191 ) ;
goto V_182;
}
F_52 ( & V_86 , V_88 , V_75 , 0 , 0 , 0 , 0 , 0 ) ;
if ( ! F_121 ( V_88 , 0 ) ) {
V_69 = F_122 ( F_116 ( V_88 ) , & V_86 , V_88 ) ;
if ( F_114 ( V_69 ) )
goto V_182;
V_196 = true ;
}
F_108 ( (struct V_61 * ) V_69 -> V_2 . V_197 , & V_86 , V_191 ) ;
V_2 = F_123 ( & V_69 -> V_2 , 0 ) ;
if ( ! V_2 ) {
if ( V_196 )
F_124 ( & V_69 -> V_2 ) ;
V_69 = F_122 ( F_116 ( V_88 ) , & V_86 , V_88 ) ;
if ( F_114 ( V_69 ) )
goto V_182;
V_196 = true ;
}
if ( V_196 )
F_125 ( V_88 , & V_69 -> V_2 ) ;
V_182:
F_126 ( V_88 ) ;
}
void F_127 ( struct V_65 * V_66 , struct V_48 * V_48 ,
int V_89 , T_1 V_92 , T_7 V_104 , int V_93 )
{
const struct V_74 * V_75 = ( const struct V_74 * ) V_66 -> V_163 ;
struct V_85 V_86 ;
struct V_61 * V_69 ;
F_52 ( & V_86 , NULL , V_75 , V_89 ,
F_57 ( V_75 -> V_90 ) , V_104 , V_92 , V_93 ) ;
V_69 = F_113 ( V_48 , & V_86 ) ;
if ( ! F_114 ( V_69 ) ) {
F_73 ( V_69 , V_66 , & V_86 , false ) ;
F_95 ( V_69 ) ;
}
}
void F_128 ( struct V_65 * V_66 , struct V_87 * V_88 )
{
const struct V_74 * V_75 = ( const struct V_74 * ) V_66 -> V_163 ;
struct V_85 V_86 ;
struct V_61 * V_69 ;
F_52 ( & V_86 , V_88 , V_75 , 0 , 0 , 0 , 0 , 0 ) ;
V_69 = F_113 ( F_116 ( V_88 ) , & V_86 ) ;
if ( ! F_114 ( V_69 ) ) {
F_73 ( V_69 , V_66 , & V_86 , false ) ;
F_95 ( V_69 ) ;
}
}
static struct V_1 * F_129 ( struct V_1 * V_2 , T_1 V_198 )
{
struct V_61 * V_69 = (struct V_61 * ) V_2 ;
if ( V_2 -> V_160 == V_161 || F_34 ( V_69 ) )
return NULL ;
return V_2 ;
}
static void F_130 ( struct V_65 * V_66 )
{
struct V_61 * V_69 ;
F_99 ( V_66 , V_190 , V_184 , 0 ) ;
V_69 = F_97 ( V_66 ) ;
if ( V_69 )
F_131 ( & V_69 -> V_2 , 0 ) ;
}
static int F_132 ( struct V_65 * V_66 )
{
F_133 ( L_13 ,
V_199 , & F_39 ( V_66 ) -> V_102 , & F_39 ( V_66 ) -> V_67 ,
V_66 -> V_4 ? V_66 -> V_4 -> V_164 : L_14 ) ;
F_107 ( V_66 ) ;
F_3 ( 1 ) ;
return 0 ;
}
void F_134 ( T_7 * V_200 , struct V_65 * V_66 , struct V_61 * V_69 )
{
T_6 V_39 ;
if ( F_135 ( V_69 ) )
V_39 = F_39 ( V_66 ) -> V_102 ;
else {
struct V_149 V_150 ;
struct V_85 V_86 ;
struct V_74 * V_75 ;
V_75 = F_39 ( V_66 ) ;
memset ( & V_86 , 0 , sizeof( V_86 ) ) ;
V_86 . V_67 = V_75 -> V_67 ;
V_86 . V_102 = V_75 -> V_102 ;
V_86 . V_201 = F_57 ( V_75 -> V_90 ) ;
V_86 . V_202 = V_69 -> V_2 . V_4 -> V_103 ;
V_86 . V_203 = V_66 -> V_4 -> V_103 ;
V_86 . V_204 = V_66 -> V_92 ;
F_59 () ;
if ( F_86 ( F_35 ( V_69 -> V_2 . V_4 ) , & V_86 , & V_150 ) == 0 )
V_39 = F_136 ( F_35 ( V_69 -> V_2 . V_4 ) , V_150 ) ;
else
V_39 = F_137 ( V_69 -> V_2 . V_4 ,
F_100 ( V_69 , V_75 -> V_67 ) ,
V_101 ) ;
F_62 () ;
}
memcpy ( V_200 , & V_39 , 4 ) ;
}
static void F_138 ( struct V_61 * V_69 , T_1 V_205 )
{
if ( ! ( V_69 -> V_2 . V_206 & 0xFFFF ) )
V_69 -> V_2 . V_206 |= V_205 & 0xFFFF ;
if ( ! ( V_69 -> V_2 . V_206 & 0xFFFF0000 ) )
V_69 -> V_2 . V_206 |= V_205 & 0xFFFF0000 ;
}
static unsigned int F_139 ( const struct V_1 * V_2 )
{
unsigned int V_207 = F_140 ( V_2 , V_208 ) ;
if ( V_207 == 0 ) {
V_207 = F_141 (unsigned int, dst->dev->mtu - 40 ,
ip_rt_min_advmss) ;
if ( V_207 > 65535 - 40 )
V_207 = 65535 - 40 ;
}
return V_207 ;
}
static unsigned int F_142 ( const struct V_1 * V_2 )
{
const struct V_61 * V_69 = ( const struct V_61 * ) V_2 ;
unsigned int V_191 = V_69 -> V_194 ;
if ( ! V_191 || F_143 ( V_141 , V_69 -> V_2 . V_130 ) )
V_191 = F_140 ( V_2 , V_192 ) ;
if ( V_191 )
return V_191 ;
V_191 = V_2 -> V_4 -> V_191 ;
if ( F_144 ( F_109 ( V_2 , V_192 ) ) ) {
if ( V_69 -> V_209 && V_191 > 576 )
V_191 = 576 ;
}
if ( V_191 > V_210 )
V_191 = V_210 ;
return V_191 ;
}
static struct V_114 * F_145 ( struct V_126 * V_127 , T_6 V_67 )
{
struct V_115 * V_116 = V_127 -> V_133 ;
struct V_114 * V_117 ;
T_1 V_124 ;
if ( ! V_116 )
return NULL ;
V_124 = F_69 ( V_67 ) ;
for ( V_117 = F_60 ( V_116 [ V_124 ] . V_120 ) ; V_117 ;
V_117 = F_60 ( V_117 -> V_121 ) ) {
if ( V_117 -> V_136 == V_67 )
return V_117 ;
}
return NULL ;
}
static bool F_146 ( struct V_61 * V_69 , struct V_114 * V_117 ,
T_6 V_67 )
{
bool V_165 = false ;
F_44 ( & V_132 ) ;
if ( V_67 == V_117 -> V_136 ) {
struct V_61 * V_119 = F_60 ( V_117 -> V_123 ) ;
if ( V_119 && F_34 ( V_119 ) ) {
V_117 -> V_137 = 0 ;
V_117 -> V_138 = 0 ;
V_117 -> V_139 = 0 ;
}
if ( V_117 -> V_138 ) {
unsigned long V_130 = V_117 -> V_139 ;
unsigned long V_211 = V_130 - V_141 ;
if ( F_67 ( V_141 , V_130 ) ) {
V_69 -> V_194 = V_117 -> V_138 ;
F_131 ( & V_69 -> V_2 , V_211 ) ;
}
}
if ( V_117 -> V_137 ) {
V_69 -> V_166 |= V_167 ;
V_69 -> V_71 = V_117 -> V_137 ;
V_69 -> V_209 = 1 ;
} else if ( ! V_69 -> V_71 )
V_69 -> V_71 = V_67 ;
F_72 ( V_117 -> V_123 , V_69 ) ;
if ( V_119 )
F_64 ( V_119 ) ;
V_117 -> V_122 = V_141 ;
V_165 = true ;
}
F_47 ( & V_132 ) ;
return V_165 ;
}
static bool F_147 ( struct V_126 * V_127 , struct V_61 * V_69 )
{
struct V_61 * V_119 , * V_212 , * * V_213 ;
bool V_165 = true ;
if ( F_148 ( V_69 ) ) {
V_213 = (struct V_61 * * ) & V_127 -> V_214 ;
} else {
V_213 = (struct V_61 * * ) F_149 ( V_127 -> V_215 ) ;
}
V_119 = * V_213 ;
V_212 = F_150 ( V_213 , V_119 , V_69 ) ;
if ( V_212 == V_119 ) {
if ( V_119 )
F_64 ( V_119 ) ;
} else
V_165 = false ;
return V_165 ;
}
static void F_151 ( struct V_61 * V_69 )
{
F_44 ( & V_216 ) ;
F_152 ( & V_69 -> V_217 , & V_218 ) ;
F_47 ( & V_216 ) ;
}
static void F_153 ( struct V_1 * V_2 )
{
struct V_61 * V_69 = (struct V_61 * ) V_2 ;
if ( ! F_154 ( & V_69 -> V_217 ) ) {
F_44 ( & V_216 ) ;
F_155 ( & V_69 -> V_217 ) ;
F_47 ( & V_216 ) ;
}
}
void F_156 ( struct V_3 * V_4 )
{
if ( ! F_154 ( & V_218 ) ) {
struct V_48 * V_48 = F_35 ( V_4 ) ;
struct V_61 * V_69 ;
F_44 ( & V_216 ) ;
F_157 (rt, &rt_uncached_list, rt_uncached) {
if ( V_69 -> V_2 . V_4 != V_4 )
continue;
V_69 -> V_2 . V_4 = V_48 -> V_219 ;
F_158 ( V_69 -> V_2 . V_4 ) ;
F_159 ( V_4 ) ;
}
F_47 ( & V_216 ) ;
}
}
static bool F_160 ( const struct V_61 * V_69 )
{
return V_69 &&
V_69 -> V_2 . V_160 == V_220 &&
! F_34 ( V_69 ) ;
}
static void F_161 ( struct V_61 * V_69 , T_6 V_67 ,
const struct V_149 * V_150 ,
struct V_114 * V_117 ,
struct V_221 * V_222 , T_8 type , T_1 V_223 )
{
bool V_224 = false ;
if ( V_222 ) {
struct V_126 * V_127 = & F_87 ( * V_150 ) ;
if ( V_127 -> V_225 && V_127 -> V_226 == V_227 ) {
V_69 -> V_71 = V_127 -> V_225 ;
V_69 -> V_209 = 1 ;
}
F_162 ( & V_69 -> V_2 , V_222 -> V_228 , true ) ;
#ifdef F_29
V_69 -> V_2 . V_206 = V_127 -> V_229 ;
#endif
if ( F_144 ( V_117 ) )
V_224 = F_146 ( V_69 , V_117 , V_67 ) ;
else if ( ! ( V_69 -> V_2 . V_230 & V_231 ) )
V_224 = F_147 ( V_127 , V_69 ) ;
if ( F_144 ( ! V_224 ) ) {
V_69 -> V_2 . V_230 |= V_231 ;
if ( ! V_69 -> V_71 )
V_69 -> V_71 = V_67 ;
F_151 ( V_69 ) ;
}
} else
F_151 ( V_69 ) ;
#ifdef F_29
#ifdef F_163
F_138 ( V_69 , V_150 -> V_206 ) ;
#endif
F_138 ( V_69 , V_223 ) ;
#endif
}
static struct V_61 * F_164 ( struct V_3 * V_4 ,
bool V_232 , bool V_233 , bool V_234 )
{
return F_165 ( & V_19 , V_4 , 1 , V_220 ,
( V_234 ? 0 : ( V_235 | V_231 ) ) |
( V_232 ? V_236 : 0 ) |
( V_233 ? V_237 : 0 ) ) ;
}
static int F_166 ( struct V_65 * V_66 , T_6 V_67 , T_6 V_102 ,
T_7 V_90 , struct V_3 * V_4 , int V_238 )
{
struct V_61 * V_62 ;
struct V_147 * V_148 = F_75 ( V_4 ) ;
T_1 V_223 = 0 ;
int V_239 ;
if ( V_148 == NULL )
return - V_183 ;
if ( F_77 ( V_102 ) || F_78 ( V_102 ) ||
V_66 -> V_104 != F_46 ( V_240 ) )
goto V_241;
if ( F_167 ( ! F_168 ( V_148 ) ) )
if ( F_169 ( V_102 ) )
goto V_241;
if ( F_79 ( V_102 ) ) {
if ( ! F_170 ( V_67 ) )
goto V_241;
} else {
V_239 = F_171 ( V_66 , V_102 , 0 , V_90 , 0 , V_4 ,
V_148 , & V_223 ) ;
if ( V_239 < 0 )
goto V_242;
}
V_62 = F_164 ( F_35 ( V_4 ) -> V_219 ,
F_172 ( V_148 , V_243 ) , false , false ) ;
if ( ! V_62 )
goto V_244;
#ifdef F_29
V_62 -> V_2 . V_206 = V_223 ;
#endif
V_62 -> V_2 . V_245 = F_132 ;
V_62 -> V_63 = V_63 ( F_35 ( V_4 ) ) ;
V_62 -> V_166 = V_246 ;
V_62 -> V_247 = V_248 ;
V_62 -> V_249 = 1 ;
V_62 -> V_250 = 0 ;
V_62 -> V_194 = 0 ;
V_62 -> V_71 = 0 ;
V_62 -> V_209 = 0 ;
F_173 ( & V_62 -> V_217 ) ;
if ( V_238 ) {
V_62 -> V_2 . V_251 = V_252 ;
V_62 -> V_166 |= V_253 ;
}
#ifdef F_174
if ( ! F_170 ( V_67 ) && F_175 ( V_148 ) )
V_62 -> V_2 . V_251 = V_254 ;
#endif
F_176 ( V_22 ) ;
F_177 ( V_66 , & V_62 -> V_2 ) ;
return 0 ;
V_244:
return - V_255 ;
V_241:
return - V_183 ;
V_242:
return V_239 ;
}
static void F_178 ( struct V_3 * V_4 ,
struct V_147 * V_148 ,
struct V_65 * V_66 ,
T_6 V_67 ,
T_6 V_102 )
{
F_176 ( V_26 ) ;
#ifdef F_90
if ( F_91 ( V_148 ) && F_179 () ) {
F_180 ( L_15 ,
& V_67 , & V_102 , V_4 -> V_164 ) ;
if ( V_4 -> V_256 && F_181 ( V_66 ) ) {
F_182 ( V_257 , L_16 ,
V_258 , 16 , 1 ,
F_183 ( V_66 ) ,
V_4 -> V_256 , true ) ;
}
}
#endif
}
static int F_184 ( struct V_65 * V_66 ,
const struct V_149 * V_150 ,
struct V_147 * V_148 ,
T_6 V_67 , T_6 V_102 , T_1 V_90 )
{
struct V_61 * V_62 ;
int V_239 ;
struct V_147 * V_259 ;
unsigned int V_230 = 0 ;
bool V_260 ;
T_1 V_223 ;
V_259 = F_75 ( F_185 ( * V_150 ) ) ;
if ( V_259 == NULL ) {
F_186 ( L_17 ) ;
return - V_183 ;
}
V_239 = F_171 ( V_66 , V_102 , V_67 , V_90 , F_187 ( * V_150 ) ,
V_148 -> V_4 , V_148 , & V_223 ) ;
if ( V_239 < 0 ) {
F_178 ( V_148 -> V_4 , V_148 , V_66 , V_67 ,
V_102 ) ;
goto V_261;
}
V_260 = V_150 -> V_222 && ! V_223 ;
if ( V_259 == V_148 && V_239 && F_98 ( V_259 ) &&
( F_80 ( V_259 ) ||
F_81 ( V_259 , V_102 , F_188 ( * V_150 ) ) ) ) {
V_230 |= V_262 ;
V_260 = false ;
}
if ( V_66 -> V_104 != F_46 ( V_240 ) ) {
if ( V_259 == V_148 &&
F_189 ( V_148 ) == 0 ) {
V_239 = - V_183 ;
goto V_261;
}
}
if ( V_260 ) {
V_62 = F_60 ( F_87 ( * V_150 ) . V_214 ) ;
if ( F_160 ( V_62 ) ) {
F_190 ( V_66 , & V_62 -> V_2 ) ;
goto V_182;
}
}
V_62 = F_164 ( V_259 -> V_4 ,
F_172 ( V_148 , V_243 ) ,
F_172 ( V_259 , V_263 ) , V_260 ) ;
if ( ! V_62 ) {
V_239 = - V_255 ;
goto V_261;
}
V_62 -> V_63 = V_63 ( F_35 ( V_62 -> V_2 . V_4 ) ) ;
V_62 -> V_166 = V_230 ;
V_62 -> V_247 = V_150 -> type ;
V_62 -> V_249 = 1 ;
V_62 -> V_250 = 0 ;
V_62 -> V_194 = 0 ;
V_62 -> V_71 = 0 ;
V_62 -> V_209 = 0 ;
F_173 ( & V_62 -> V_217 ) ;
V_62 -> V_2 . V_251 = V_264 ;
V_62 -> V_2 . V_245 = V_265 ;
F_161 ( V_62 , V_67 , V_150 , NULL , V_150 -> V_222 , V_150 -> type , V_223 ) ;
F_177 ( V_66 , & V_62 -> V_2 ) ;
V_182:
V_239 = 0 ;
V_261:
return V_239 ;
}
static int F_191 ( struct V_65 * V_66 ,
struct V_149 * V_150 ,
const struct V_85 * V_86 ,
struct V_147 * V_148 ,
T_6 V_67 , T_6 V_102 , T_1 V_90 )
{
#ifdef F_192
if ( V_150 -> V_222 && V_150 -> V_222 -> V_266 > 1 )
F_193 ( V_150 ) ;
#endif
return F_184 ( V_66 , V_150 , V_148 , V_67 , V_102 , V_90 ) ;
}
static int F_194 ( struct V_65 * V_66 , T_6 V_67 , T_6 V_102 ,
T_7 V_90 , struct V_3 * V_4 )
{
struct V_149 V_150 ;
struct V_147 * V_148 = F_75 ( V_4 ) ;
struct V_85 V_86 ;
unsigned int V_230 = 0 ;
T_1 V_223 = 0 ;
struct V_61 * V_62 ;
int V_239 = - V_183 ;
struct V_48 * V_48 = F_35 ( V_4 ) ;
bool V_260 ;
if ( ! V_148 )
goto V_182;
if ( F_77 ( V_102 ) || F_78 ( V_102 ) )
goto V_267;
V_150 . V_222 = NULL ;
if ( F_78 ( V_67 ) || ( V_102 == 0 && V_67 == 0 ) )
goto V_268;
if ( F_79 ( V_102 ) )
goto V_267;
if ( F_79 ( V_67 ) )
goto V_269;
if ( F_169 ( V_67 ) ) {
if ( ! F_195 ( V_148 , V_48 ) )
goto V_269;
} else if ( F_169 ( V_102 ) ) {
if ( ! F_195 ( V_148 , V_48 ) )
goto V_267;
}
V_86 . V_202 = 0 ;
V_86 . V_203 = V_4 -> V_103 ;
V_86 . V_204 = V_66 -> V_92 ;
V_86 . V_201 = V_90 ;
V_86 . V_270 = V_101 ;
V_86 . V_67 = V_67 ;
V_86 . V_102 = V_102 ;
V_239 = F_86 ( V_48 , & V_86 , & V_150 ) ;
if ( V_239 != 0 )
goto V_271;
F_176 ( V_21 ) ;
if ( V_150 . type == V_272 )
goto V_268;
if ( V_150 . type == V_273 ) {
V_239 = F_171 ( V_66 , V_102 , V_67 , V_90 ,
V_274 ,
V_4 , V_148 , & V_223 ) ;
if ( V_239 < 0 )
goto V_275;
goto V_276;
}
if ( ! F_105 ( V_148 ) )
goto V_271;
if ( V_150 . type != V_157 )
goto V_269;
V_239 = F_191 ( V_66 , & V_150 , & V_86 , V_148 , V_67 , V_102 , V_90 ) ;
V_182: return V_239 ;
V_268:
if ( V_66 -> V_104 != F_46 ( V_240 ) )
goto V_241;
if ( ! F_79 ( V_102 ) ) {
V_239 = F_171 ( V_66 , V_102 , 0 , V_90 , 0 , V_4 ,
V_148 , & V_223 ) ;
if ( V_239 < 0 )
goto V_275;
}
V_230 |= V_277 ;
V_150 . type = V_272 ;
F_176 ( V_24 ) ;
V_276:
V_260 = false ;
if ( V_150 . V_222 ) {
if ( ! V_223 ) {
V_62 = F_60 ( F_87 ( V_150 ) . V_214 ) ;
if ( F_160 ( V_62 ) ) {
F_190 ( V_66 , & V_62 -> V_2 ) ;
V_239 = 0 ;
goto V_182;
}
V_260 = true ;
}
}
V_62 = F_164 ( V_48 -> V_219 ,
F_172 ( V_148 , V_243 ) , false , V_260 ) ;
if ( ! V_62 )
goto V_244;
V_62 -> V_2 . V_251 = V_252 ;
V_62 -> V_2 . V_245 = F_132 ;
#ifdef F_29
V_62 -> V_2 . V_206 = V_223 ;
#endif
V_62 -> V_63 = V_63 ( V_48 ) ;
V_62 -> V_166 = V_230 | V_253 ;
V_62 -> V_247 = V_150 . type ;
V_62 -> V_249 = 1 ;
V_62 -> V_250 = 0 ;
V_62 -> V_194 = 0 ;
V_62 -> V_71 = 0 ;
V_62 -> V_209 = 0 ;
F_173 ( & V_62 -> V_217 ) ;
if ( V_150 . type == V_278 ) {
V_62 -> V_2 . V_251 = F_104 ;
V_62 -> V_2 . error = - V_239 ;
V_62 -> V_166 &= ~ V_253 ;
}
if ( V_260 )
F_147 ( & F_87 ( V_150 ) , V_62 ) ;
F_177 ( V_66 , & V_62 -> V_2 ) ;
V_239 = 0 ;
goto V_182;
V_271:
F_176 ( V_23 ) ;
V_150 . type = V_278 ;
if ( V_239 == - V_279 )
V_239 = - V_180 ;
goto V_276;
V_269:
F_176 ( V_25 ) ;
#ifdef F_90
if ( F_91 ( V_148 ) )
F_102 ( L_18 ,
& V_67 , & V_102 , V_4 -> V_164 ) ;
#endif
V_241:
V_239 = - V_183 ;
goto V_182;
V_244:
V_239 = - V_255 ;
goto V_182;
V_267:
V_239 = - V_183 ;
V_275:
F_178 ( V_4 , V_148 , V_66 , V_67 , V_102 ) ;
goto V_182;
}
int F_196 ( struct V_65 * V_66 , T_6 V_67 , T_6 V_102 ,
T_7 V_90 , struct V_3 * V_4 )
{
int V_150 ;
F_59 () ;
if ( F_77 ( V_67 ) ) {
struct V_147 * V_148 = F_75 ( V_4 ) ;
if ( V_148 ) {
int V_238 = F_197 ( V_148 , V_67 , V_102 ,
F_39 ( V_66 ) -> V_104 ) ;
if ( V_238
#ifdef F_174
||
( ! F_170 ( V_67 ) &&
F_175 ( V_148 ) )
#endif
) {
int V_150 = F_166 ( V_66 , V_67 , V_102 ,
V_90 , V_4 , V_238 ) ;
F_62 () ;
return V_150 ;
}
}
F_62 () ;
return - V_183 ;
}
V_150 = F_194 ( V_66 , V_67 , V_102 , V_90 , V_4 ) ;
F_62 () ;
return V_150 ;
}
static struct V_61 * F_198 ( const struct V_149 * V_150 ,
const struct V_85 * V_86 , int V_280 ,
struct V_3 * V_281 ,
unsigned int V_230 )
{
struct V_221 * V_222 = V_150 -> V_222 ;
struct V_114 * V_117 ;
struct V_147 * V_148 ;
T_8 type = V_150 -> type ;
struct V_61 * V_62 ;
bool V_260 ;
V_148 = F_75 ( V_281 ) ;
if ( ! V_148 )
return F_199 ( - V_183 ) ;
if ( F_167 ( ! F_168 ( V_148 ) ) )
if ( F_169 ( V_86 -> V_102 ) && ! ( V_281 -> V_230 & V_282 ) )
return F_199 ( - V_183 ) ;
if ( F_78 ( V_86 -> V_67 ) )
type = V_272 ;
else if ( F_77 ( V_86 -> V_67 ) )
type = V_248 ;
else if ( F_79 ( V_86 -> V_67 ) )
return F_199 ( - V_183 ) ;
if ( V_281 -> V_230 & V_282 )
V_230 |= V_253 ;
V_260 = true ;
if ( type == V_272 ) {
V_230 |= V_277 | V_253 ;
V_222 = NULL ;
} else if ( type == V_248 ) {
V_230 |= V_246 | V_253 ;
if ( ! F_197 ( V_148 , V_86 -> V_67 , V_86 -> V_102 ,
V_86 -> V_283 ) )
V_230 &= ~ V_253 ;
else
V_260 = false ;
if ( V_222 && V_150 -> V_284 < 4 )
V_222 = NULL ;
}
V_117 = NULL ;
V_260 &= V_222 != NULL ;
if ( V_260 ) {
struct V_61 T_9 * * V_285 ;
struct V_126 * V_127 = & F_87 ( * V_150 ) ;
V_117 = F_145 ( V_127 , V_86 -> V_67 ) ;
if ( V_117 )
V_285 = & V_117 -> V_123 ;
else {
if ( F_144 ( V_86 -> V_286 &
V_287 &&
! ( V_127 -> V_225 &&
V_127 -> V_226 == V_227 ) ) ) {
V_260 = false ;
goto V_288;
}
V_285 = F_149 ( V_127 -> V_215 ) ;
}
V_62 = F_60 ( * V_285 ) ;
if ( F_160 ( V_62 ) ) {
F_200 ( & V_62 -> V_2 ) ;
return V_62 ;
}
}
V_288:
V_62 = F_164 ( V_281 ,
F_172 ( V_148 , V_243 ) ,
F_172 ( V_148 , V_263 ) ,
V_260 ) ;
if ( ! V_62 )
return F_199 ( - V_255 ) ;
V_62 -> V_2 . V_245 = V_265 ;
V_62 -> V_63 = V_63 ( F_35 ( V_281 ) ) ;
V_62 -> V_166 = V_230 ;
V_62 -> V_247 = type ;
V_62 -> V_249 = 0 ;
V_62 -> V_250 = V_280 ? : 0 ;
V_62 -> V_194 = 0 ;
V_62 -> V_71 = 0 ;
V_62 -> V_209 = 0 ;
F_173 ( & V_62 -> V_217 ) ;
F_176 ( V_28 ) ;
if ( V_230 & V_253 )
V_62 -> V_2 . V_251 = V_252 ;
if ( V_230 & ( V_277 | V_246 ) ) {
if ( V_230 & V_253 &&
! ( V_281 -> V_230 & V_282 ) ) {
V_62 -> V_2 . V_245 = V_289 ;
F_176 ( V_29 ) ;
}
#ifdef F_174
if ( type == V_248 ) {
if ( F_175 ( V_148 ) &&
! F_170 ( V_86 -> V_67 ) ) {
V_62 -> V_2 . V_251 = V_254 ;
V_62 -> V_2 . V_245 = V_289 ;
}
}
#endif
}
F_161 ( V_62 , V_86 -> V_67 , V_150 , V_117 , V_222 , type , 0 ) ;
return V_62 ;
}
struct V_61 * F_113 ( struct V_48 * V_48 , struct V_85 * V_86 )
{
struct V_3 * V_281 = NULL ;
T_10 V_90 = F_201 ( V_86 ) ;
unsigned int V_230 = 0 ;
struct V_149 V_150 ;
struct V_61 * V_62 ;
int V_280 ;
V_150 . V_206 = 0 ;
V_150 . V_222 = NULL ;
V_150 . V_290 = NULL ;
V_280 = V_86 -> V_202 ;
V_86 -> V_203 = V_274 ;
V_86 -> V_201 = V_90 & V_291 ;
V_86 -> V_270 = ( ( V_90 & V_292 ) ?
V_227 : V_101 ) ;
F_59 () ;
if ( V_86 -> V_102 ) {
V_62 = F_199 ( - V_183 ) ;
if ( F_77 ( V_86 -> V_102 ) ||
F_78 ( V_86 -> V_102 ) ||
F_79 ( V_86 -> V_102 ) )
goto V_182;
if ( V_86 -> V_202 == 0 &&
( F_77 ( V_86 -> V_67 ) ||
F_78 ( V_86 -> V_67 ) ) ) {
V_281 = F_202 ( V_48 , V_86 -> V_102 , false ) ;
if ( V_281 == NULL )
goto V_182;
V_86 -> V_202 = V_281 -> V_103 ;
goto V_293;
}
if ( ! ( V_86 -> V_286 & V_294 ) ) {
if ( ! F_202 ( V_48 , V_86 -> V_102 , false ) )
goto V_182;
}
}
if ( V_86 -> V_202 ) {
V_281 = F_203 ( V_48 , V_86 -> V_202 ) ;
V_62 = F_199 ( - V_295 ) ;
if ( V_281 == NULL )
goto V_182;
if ( ! ( V_281 -> V_230 & V_296 ) || ! F_75 ( V_281 ) ) {
V_62 = F_199 ( - V_180 ) ;
goto V_182;
}
if ( F_170 ( V_86 -> V_67 ) ||
F_78 ( V_86 -> V_67 ) ) {
if ( ! V_86 -> V_102 )
V_86 -> V_102 = F_137 ( V_281 , 0 ,
V_227 ) ;
goto V_293;
}
if ( V_86 -> V_102 ) {
if ( F_77 ( V_86 -> V_67 ) )
V_86 -> V_102 = F_137 ( V_281 , 0 ,
V_86 -> V_270 ) ;
else if ( ! V_86 -> V_67 )
V_86 -> V_102 = F_137 ( V_281 , 0 ,
V_297 ) ;
}
}
if ( ! V_86 -> V_67 ) {
V_86 -> V_67 = V_86 -> V_102 ;
if ( ! V_86 -> V_67 )
V_86 -> V_67 = V_86 -> V_102 = F_204 ( V_298 ) ;
V_281 = V_48 -> V_219 ;
V_86 -> V_202 = V_274 ;
V_150 . type = V_273 ;
V_230 |= V_253 ;
goto V_293;
}
if ( F_86 ( V_48 , V_86 , & V_150 ) ) {
V_150 . V_222 = NULL ;
V_150 . V_290 = NULL ;
if ( V_86 -> V_202 ) {
if ( V_86 -> V_102 == 0 )
V_86 -> V_102 = F_137 ( V_281 , 0 ,
V_227 ) ;
V_150 . type = V_157 ;
goto V_293;
}
V_62 = F_199 ( - V_180 ) ;
goto V_182;
}
if ( V_150 . type == V_273 ) {
if ( ! V_86 -> V_102 ) {
if ( V_150 . V_222 -> V_299 )
V_86 -> V_102 = V_150 . V_222 -> V_299 ;
else
V_86 -> V_102 = V_86 -> V_67 ;
}
V_281 = V_48 -> V_219 ;
V_86 -> V_202 = V_281 -> V_103 ;
V_230 |= V_253 ;
goto V_293;
}
#ifdef F_192
if ( V_150 . V_222 -> V_266 > 1 && V_86 -> V_202 == 0 )
F_193 ( & V_150 ) ;
else
#endif
if ( ! V_150 . V_284 &&
V_150 . V_290 -> V_300 > 1 &&
V_150 . type == V_157 && ! V_86 -> V_202 )
F_205 ( & V_150 ) ;
if ( ! V_86 -> V_102 )
V_86 -> V_102 = F_136 ( V_48 , V_150 ) ;
V_281 = F_185 ( V_150 ) ;
V_86 -> V_202 = V_281 -> V_103 ;
V_293:
V_62 = F_198 ( & V_150 , V_86 , V_280 , V_281 , V_230 ) ;
V_182:
F_62 () ;
return V_62 ;
}
static struct V_1 * F_206 ( struct V_1 * V_2 , T_1 V_198 )
{
return NULL ;
}
static unsigned int F_207 ( const struct V_1 * V_2 )
{
unsigned int V_191 = F_140 ( V_2 , V_192 ) ;
return V_191 ? : V_2 -> V_4 -> V_191 ;
}
static void F_208 ( struct V_1 * V_2 , struct V_87 * V_88 ,
struct V_65 * V_66 , T_1 V_191 )
{
}
static void F_209 ( struct V_1 * V_2 , struct V_87 * V_88 ,
struct V_65 * V_66 )
{
}
static T_1 * F_210 ( struct V_1 * V_2 ,
unsigned long V_6 )
{
return NULL ;
}
struct V_1 * F_211 ( struct V_48 * V_48 , struct V_1 * V_301 )
{
struct V_61 * V_302 = (struct V_61 * ) V_301 ;
struct V_61 * V_69 ;
V_69 = F_165 ( & V_303 , NULL , 1 , V_304 , 0 ) ;
if ( V_69 ) {
struct V_1 * V_196 = & V_69 -> V_2 ;
V_196 -> V_305 = 1 ;
V_196 -> V_251 = V_306 ;
V_196 -> V_245 = V_306 ;
V_196 -> V_4 = V_302 -> V_2 . V_4 ;
if ( V_196 -> V_4 )
F_158 ( V_196 -> V_4 ) ;
V_69 -> V_249 = V_302 -> V_249 ;
V_69 -> V_250 = V_302 -> V_250 ;
V_69 -> V_194 = V_302 -> V_194 ;
V_69 -> V_63 = V_63 ( V_48 ) ;
V_69 -> V_166 = V_302 -> V_166 ;
V_69 -> V_247 = V_302 -> V_247 ;
V_69 -> V_71 = V_302 -> V_71 ;
V_69 -> V_209 = V_302 -> V_209 ;
F_173 ( & V_69 -> V_217 ) ;
F_212 ( V_196 ) ;
}
F_124 ( V_301 ) ;
return V_69 ? & V_69 -> V_2 : F_199 ( - V_43 ) ;
}
struct V_61 * F_122 ( struct V_48 * V_48 , struct V_85 * V_307 ,
struct V_87 * V_88 )
{
struct V_61 * V_69 = F_113 ( V_48 , V_307 ) ;
if ( F_114 ( V_69 ) )
return V_69 ;
if ( V_307 -> V_283 )
V_69 = (struct V_61 * ) F_213 ( V_48 , & V_69 -> V_2 ,
F_214 ( V_307 ) ,
V_88 , 0 ) ;
return V_69 ;
}
static int F_215 ( struct V_48 * V_48 , T_6 V_2 , T_6 V_39 ,
struct V_85 * V_86 , struct V_65 * V_66 , T_1 V_308 ,
T_1 V_8 , int V_309 , int V_310 , unsigned int V_230 )
{
struct V_61 * V_69 = F_97 ( V_66 ) ;
struct V_311 * V_312 ;
struct V_313 * V_314 ;
unsigned long V_130 = 0 ;
T_1 error ;
T_1 V_315 [ V_316 ] ;
V_314 = F_216 ( V_66 , V_308 , V_8 , V_309 , sizeof( * V_312 ) , V_230 ) ;
if ( V_314 == NULL )
return - V_317 ;
V_312 = F_217 ( V_314 ) ;
V_312 -> V_318 = V_319 ;
V_312 -> V_320 = 32 ;
V_312 -> V_321 = 0 ;
V_312 -> V_322 = V_86 -> V_201 ;
V_312 -> V_323 = V_324 ;
if ( F_218 ( V_66 , V_325 , V_324 ) )
goto V_326;
V_312 -> V_327 = V_69 -> V_247 ;
V_312 -> V_328 = V_101 ;
V_312 -> V_329 = V_330 ;
V_312 -> V_331 = ( V_69 -> V_166 & ~ 0xFFFF ) | V_332 ;
if ( V_69 -> V_166 & V_333 )
V_312 -> V_331 |= V_334 ;
if ( F_219 ( V_66 , V_335 , V_2 ) )
goto V_326;
if ( V_39 ) {
V_312 -> V_321 = 32 ;
if ( F_219 ( V_66 , V_336 , V_39 ) )
goto V_326;
}
if ( V_69 -> V_2 . V_4 &&
F_218 ( V_66 , V_337 , V_69 -> V_2 . V_4 -> V_103 ) )
goto V_326;
#ifdef F_29
if ( V_69 -> V_2 . V_206 &&
F_218 ( V_66 , V_338 , V_69 -> V_2 . V_206 ) )
goto V_326;
#endif
if ( ! F_148 ( V_69 ) &&
V_86 -> V_102 != V_39 ) {
if ( F_219 ( V_66 , V_339 , V_86 -> V_102 ) )
goto V_326;
}
if ( V_69 -> V_209 &&
F_219 ( V_66 , V_340 , V_69 -> V_71 ) )
goto V_326;
V_130 = V_69 -> V_2 . V_130 ;
if ( V_130 ) {
unsigned long V_176 = V_141 ;
if ( F_67 ( V_176 , V_130 ) )
V_130 -= V_176 ;
else
V_130 = 0 ;
}
memcpy ( V_315 , F_220 ( & V_69 -> V_2 ) , sizeof( V_315 ) ) ;
if ( V_69 -> V_194 && V_130 )
V_315 [ V_192 - 1 ] = V_69 -> V_194 ;
if ( F_221 ( V_66 , V_315 ) < 0 )
goto V_326;
if ( V_86 -> V_204 &&
F_218 ( V_66 , V_341 , V_86 -> V_204 ) )
goto V_326;
error = V_69 -> V_2 . error ;
if ( F_148 ( V_69 ) ) {
#ifdef F_174
if ( F_77 ( V_2 ) && ! F_170 ( V_2 ) &&
F_222 ( V_48 , V_342 ) ) {
int V_239 = F_223 ( V_48 , V_66 ,
V_86 -> V_102 , V_86 -> V_67 ,
V_312 , V_310 ) ;
if ( V_239 <= 0 ) {
if ( ! V_310 ) {
if ( V_239 == 0 )
return 0 ;
goto V_326;
} else {
if ( V_239 == - V_317 )
goto V_326;
error = V_239 ;
}
}
} else
#endif
if ( F_218 ( V_66 , V_343 , V_69 -> V_250 ) )
goto V_326;
}
if ( F_224 ( V_66 , & V_69 -> V_2 , 0 , V_130 , error ) < 0 )
goto V_326;
return F_225 ( V_66 , V_314 ) ;
V_326:
F_226 ( V_66 , V_314 ) ;
return - V_317 ;
}
static int F_227 ( struct V_65 * V_344 , struct V_313 * V_314 )
{
struct V_48 * V_48 = F_116 ( V_344 -> V_88 ) ;
struct V_311 * V_345 ;
struct V_346 * V_347 [ V_348 + 1 ] ;
struct V_61 * V_69 = NULL ;
struct V_85 V_86 ;
T_6 V_2 = 0 ;
T_6 V_39 = 0 ;
T_1 V_349 ;
int V_239 ;
int V_92 ;
struct V_65 * V_66 ;
V_239 = F_228 ( V_314 , sizeof( * V_345 ) , V_347 , V_348 , V_350 ) ;
if ( V_239 < 0 )
goto V_351;
V_345 = F_217 ( V_314 ) ;
V_66 = F_229 ( V_352 , V_42 ) ;
if ( V_66 == NULL ) {
V_239 = - V_255 ;
goto V_351;
}
F_230 ( V_66 ) ;
F_231 ( V_66 ) ;
F_39 ( V_66 ) -> V_104 = V_353 ;
F_232 ( V_66 , V_354 + sizeof( struct V_74 ) ) ;
V_39 = V_347 [ V_336 ] ? F_233 ( V_347 [ V_336 ] ) : 0 ;
V_2 = V_347 [ V_335 ] ? F_233 ( V_347 [ V_335 ] ) : 0 ;
V_349 = V_347 [ V_343 ] ? F_234 ( V_347 [ V_343 ] ) : 0 ;
V_92 = V_347 [ V_341 ] ? F_234 ( V_347 [ V_341 ] ) : 0 ;
memset ( & V_86 , 0 , sizeof( V_86 ) ) ;
V_86 . V_67 = V_2 ;
V_86 . V_102 = V_39 ;
V_86 . V_201 = V_345 -> V_322 ;
V_86 . V_202 = V_347 [ V_337 ] ? F_234 ( V_347 [ V_337 ] ) : 0 ;
V_86 . V_204 = V_92 ;
if ( V_349 ) {
struct V_3 * V_4 ;
V_4 = F_235 ( V_48 , V_349 ) ;
if ( V_4 == NULL ) {
V_239 = - V_295 ;
goto V_355;
}
V_66 -> V_104 = F_46 ( V_240 ) ;
V_66 -> V_4 = V_4 ;
V_66 -> V_92 = V_92 ;
F_236 () ;
V_239 = F_237 ( V_66 , V_2 , V_39 , V_345 -> V_322 , V_4 ) ;
F_238 () ;
V_69 = F_97 ( V_66 ) ;
if ( V_239 == 0 && V_69 -> V_2 . error )
V_239 = - V_69 -> V_2 . error ;
} else {
V_69 = F_239 ( V_48 , & V_86 ) ;
V_239 = 0 ;
if ( F_114 ( V_69 ) )
V_239 = F_240 ( V_69 ) ;
}
if ( V_239 )
goto V_355;
F_177 ( V_66 , & V_69 -> V_2 ) ;
if ( V_345 -> V_331 & V_334 )
V_69 -> V_166 |= V_333 ;
V_239 = F_215 ( V_48 , V_2 , V_39 , & V_86 , V_66 ,
F_241 ( V_344 ) . V_308 , V_314 -> V_356 ,
V_357 , 0 , 0 ) ;
if ( V_239 <= 0 )
goto V_355;
V_239 = F_242 ( V_66 , V_48 , F_241 ( V_344 ) . V_308 ) ;
V_351:
return V_239 ;
V_355:
F_107 ( V_66 ) ;
goto V_351;
}
int F_243 ( struct V_65 * V_66 , struct V_358 * V_359 )
{
return V_66 -> V_360 ;
}
void F_244 ( struct V_147 * V_148 )
{
F_36 ( F_35 ( V_148 -> V_4 ) ) ;
}
static int F_245 ( T_11 * V_361 , int V_362 ,
void T_12 * V_363 ,
T_13 * V_364 , T_2 * V_365 )
{
if ( V_362 ) {
F_36 ( (struct V_48 * ) V_361 -> V_366 ) ;
return 0 ;
}
return - V_183 ;
}
static T_3 int F_246 ( struct V_48 * V_48 )
{
struct T_11 * V_367 ;
V_367 = V_368 ;
if ( ! F_247 ( V_48 , & V_369 ) ) {
V_367 = F_248 ( V_367 , sizeof( V_368 ) , V_42 ) ;
if ( V_367 == NULL )
goto V_370;
if ( V_48 -> V_371 != & V_372 )
V_367 [ 0 ] . V_373 = NULL ;
}
V_367 [ 0 ] . V_366 = V_48 ;
V_48 -> V_83 . V_374 = F_249 ( V_48 , L_19 , V_367 ) ;
if ( V_48 -> V_83 . V_374 == NULL )
goto V_375;
return 0 ;
V_375:
if ( V_367 != V_368 )
F_24 ( V_367 ) ;
V_370:
return - V_43 ;
}
static T_4 void F_250 ( struct V_48 * V_48 )
{
struct T_11 * V_367 ;
V_367 = V_48 -> V_83 . V_374 -> V_376 ;
F_251 ( V_48 -> V_83 . V_374 ) ;
F_252 ( V_367 == V_368 ) ;
F_24 ( V_367 ) ;
}
static T_3 int F_253 ( struct V_48 * V_48 )
{
F_254 ( & V_48 -> V_63 , 0 ) ;
F_255 ( & V_48 -> V_83 . V_377 ,
sizeof( V_48 -> V_83 . V_377 ) ) ;
return 0 ;
}
static int T_3 F_256 ( struct V_48 * V_48 )
{
struct V_378 * V_379 = F_257 ( sizeof( * V_379 ) , V_42 ) ;
if ( ! V_379 )
return - V_43 ;
F_258 ( V_379 ) ;
V_48 -> V_83 . V_84 = V_379 ;
return 0 ;
}
static void T_4 F_259 ( struct V_48 * V_48 )
{
struct V_378 * V_379 = V_48 -> V_83 . V_84 ;
V_48 -> V_83 . V_84 = NULL ;
F_260 ( V_379 ) ;
F_24 ( V_379 ) ;
}
int T_5 F_261 ( void )
{
int V_380 = 0 ;
#ifdef F_29
V_38 = F_262 ( 256 * sizeof( struct V_38 ) , F_263 ( struct V_38 ) ) ;
if ( ! V_38 )
F_264 ( L_20 ) ;
#endif
V_19 . V_381 =
F_265 ( L_21 , sizeof( struct V_61 ) , 0 ,
V_382 | V_383 , NULL ) ;
V_303 . V_381 = V_19 . V_381 ;
if ( F_266 ( & V_19 ) < 0 )
F_264 ( L_22 ) ;
if ( F_266 ( & V_303 ) < 0 )
F_264 ( L_23 ) ;
V_19 . V_384 = ~ 0 ;
V_385 = V_386 ;
F_267 () ;
F_268 () ;
if ( F_32 () )
F_269 ( L_24 ) ;
#ifdef F_270
F_271 () ;
F_272 () ;
#endif
F_273 ( V_387 , V_388 , F_227 , NULL , NULL ) ;
#ifdef F_274
F_33 ( & V_389 ) ;
#endif
F_33 ( & V_390 ) ;
F_33 ( & V_391 ) ;
return V_380 ;
}
void T_5 F_275 ( void )
{
F_249 ( & V_369 , L_19 , V_392 ) ;
}
