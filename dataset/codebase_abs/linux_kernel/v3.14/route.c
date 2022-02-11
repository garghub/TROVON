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
0 ,
V_18 -> V_20 ,
V_18 -> V_21 ,
V_18 -> V_22 ,
V_18 -> V_23 ,
V_18 -> V_24 ,
V_18 -> V_25 ,
0 ,
V_18 -> V_26 ,
V_18 -> V_27 ,
0 ,
0 ,
0 ,
0 ,
0 ,
0
) ;
return 0 ;
}
static int F_18 ( struct V_12 * V_12 , struct V_13 * V_13 )
{
return F_10 ( V_13 , & V_28 ) ;
}
static int F_19 ( struct V_7 * V_29 , void * V_11 )
{
struct V_30 * V_2 , * V_31 ;
unsigned int V_32 , V_33 ;
V_2 = F_20 ( 256 , sizeof( struct V_30 ) , V_34 ) ;
if ( ! V_2 )
return - V_35 ;
F_21 (i) {
V_31 = (struct V_30 * ) F_22 ( V_30 , V_32 ) ;
for ( V_33 = 0 ; V_33 < 256 ; V_33 ++ ) {
V_2 [ V_33 ] . V_36 += V_31 [ V_33 ] . V_36 ;
V_2 [ V_33 ] . V_37 += V_31 [ V_33 ] . V_37 ;
V_2 [ V_33 ] . V_38 += V_31 [ V_33 ] . V_38 ;
V_2 [ V_33 ] . V_39 += V_31 [ V_33 ] . V_39 ;
}
}
F_23 ( V_29 , V_2 , 256 * sizeof( struct V_30 ) ) ;
F_24 ( V_2 ) ;
return 0 ;
}
static int F_25 ( struct V_12 * V_12 , struct V_13 * V_13 )
{
return F_26 ( V_13 , F_19 , NULL ) ;
}
static int T_3 F_27 ( struct V_40 * V_40 )
{
struct V_41 * V_42 ;
V_42 = F_28 ( L_8 , V_43 , V_40 -> V_44 ,
& V_45 ) ;
if ( ! V_42 )
goto V_46;
V_42 = F_28 ( L_8 , V_43 ,
V_40 -> V_47 , & V_48 ) ;
if ( ! V_42 )
goto V_49;
#ifdef F_29
V_42 = F_28 ( L_9 , 0 , V_40 -> V_44 , & V_50 ) ;
if ( ! V_42 )
goto V_51;
#endif
return 0 ;
#ifdef F_29
V_51:
F_30 ( L_8 , V_40 -> V_47 ) ;
#endif
V_49:
F_30 ( L_8 , V_40 -> V_44 ) ;
V_46:
return - V_35 ;
}
static void T_4 F_31 ( struct V_40 * V_40 )
{
F_30 ( L_8 , V_40 -> V_47 ) ;
F_30 ( L_8 , V_40 -> V_44 ) ;
#ifdef F_29
F_30 ( L_9 , V_40 -> V_44 ) ;
#endif
}
static int T_5 F_32 ( void )
{
return F_33 ( & V_52 ) ;
}
static inline int F_32 ( void )
{
return 0 ;
}
static inline bool F_34 ( const struct V_53 * V_54 )
{
return V_54 -> V_55 != F_35 ( F_36 ( V_54 -> V_2 . V_4 ) ) ;
}
void F_37 ( struct V_40 * V_40 )
{
F_38 ( V_40 ) ;
}
static struct V_56 * F_39 ( const struct V_1 * V_2 ,
struct V_57 * V_58 ,
const void * V_59 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
const T_6 * V_60 = V_59 ;
const struct V_53 * V_61 ;
struct V_56 * V_62 ;
V_61 = ( const struct V_53 * ) V_2 ;
if ( V_61 -> V_63 )
V_60 = ( const T_6 * ) & V_61 -> V_63 ;
else if ( V_58 )
V_60 = & F_40 ( V_58 ) -> V_59 ;
V_62 = F_41 ( V_4 , * ( V_64 T_1 * ) V_60 ) ;
if ( V_62 )
return V_62 ;
return F_42 ( & V_65 , V_60 , V_4 ) ;
}
static void F_43 ( struct V_66 * V_67 )
{
static F_44 ( V_68 ) ;
static T_1 V_69 ;
T_1 V_70 ;
F_45 ( & V_68 ) ;
V_70 = F_46 ( ( V_64 T_6 ) V_69 ^ V_67 -> V_59 ) ;
V_67 -> V_71 = F_47 ( V_70 & 0xFFFF ) ;
V_69 = V_70 ;
F_48 ( & V_68 ) ;
}
void F_49 ( struct V_66 * V_67 , struct V_1 * V_2 , int V_72 )
{
struct V_40 * V_40 = F_36 ( V_2 -> V_4 ) ;
struct V_73 * V_74 ;
V_74 = F_50 ( V_40 -> V_75 . V_76 , V_67 -> V_59 , 1 ) ;
if ( V_74 ) {
V_67 -> V_71 = F_47 ( F_51 ( V_74 , V_72 ) ) ;
F_52 ( V_74 ) ;
return;
}
F_43 ( V_67 ) ;
}
static void F_53 ( struct V_77 * V_78 , const struct V_79 * V_80 ,
const struct V_66 * V_67 ,
int V_81 , T_7 V_82 ,
T_7 V_83 , T_1 V_84 , int V_85 )
{
if ( V_80 ) {
const struct V_86 * V_87 = F_54 ( V_80 ) ;
V_81 = V_80 -> V_88 ;
V_84 = V_80 -> V_89 ;
V_82 = F_55 ( V_80 ) ;
V_83 = V_87 -> V_90 ? V_91 : V_80 -> V_92 ;
}
F_56 ( V_78 , V_81 , V_84 , V_82 ,
V_93 , V_83 ,
V_85 ,
V_67 -> V_59 , V_67 -> V_94 , 0 , 0 ) ;
}
static void F_57 ( struct V_77 * V_78 , const struct V_57 * V_58 ,
const struct V_79 * V_80 )
{
const struct V_66 * V_67 = F_40 ( V_58 ) ;
int V_81 = V_58 -> V_4 -> V_95 ;
T_7 V_82 = F_58 ( V_67 -> V_82 ) ;
T_7 V_83 = V_67 -> V_96 ;
T_1 V_84 = V_58 -> V_84 ;
F_53 ( V_78 , V_80 , V_67 , V_81 , V_82 , V_83 , V_84 , 0 ) ;
}
static void F_59 ( struct V_77 * V_78 , const struct V_79 * V_80 )
{
const struct V_86 * V_87 = F_54 ( V_80 ) ;
const struct V_97 * V_98 ;
T_6 V_59 = V_87 -> V_99 ;
F_60 () ;
V_98 = F_61 ( V_87 -> V_98 ) ;
if ( V_98 && V_98 -> V_100 . V_101 )
V_59 = V_98 -> V_100 . V_102 ;
F_56 ( V_78 , V_80 -> V_88 , V_80 -> V_89 ,
F_55 ( V_80 ) , V_93 ,
V_87 -> V_90 ? V_91 : V_80 -> V_92 ,
F_62 ( V_80 ) ,
V_59 , V_87 -> V_103 , 0 , 0 ) ;
F_63 () ;
}
static void F_64 ( struct V_77 * V_78 , const struct V_79 * V_80 ,
const struct V_57 * V_58 )
{
if ( V_58 )
F_57 ( V_78 , V_58 , V_80 ) ;
else
F_59 ( V_78 , V_80 ) ;
}
static inline void F_65 ( struct V_53 * V_61 )
{
F_66 ( & V_61 -> V_2 . V_104 , V_105 ) ;
}
static void F_67 ( struct V_106 * V_107 )
{
struct V_53 * V_61 ;
V_61 = F_61 ( V_107 -> V_108 ) ;
if ( V_61 ) {
F_68 ( V_107 -> V_108 , NULL ) ;
F_65 ( V_61 ) ;
}
V_61 = F_61 ( V_107 -> V_109 ) ;
if ( V_61 ) {
F_68 ( V_107 -> V_109 , NULL ) ;
F_65 ( V_61 ) ;
}
}
static struct V_106 * F_69 ( struct V_110 * V_111 )
{
struct V_106 * V_107 , * V_112 ;
V_112 = F_61 ( V_111 -> V_113 ) ;
for ( V_107 = F_61 ( V_112 -> V_114 ) ; V_107 ;
V_107 = F_61 ( V_107 -> V_114 ) ) {
if ( F_70 ( V_107 -> V_115 , V_112 -> V_115 ) )
V_112 = V_107 ;
}
F_67 ( V_112 ) ;
return V_112 ;
}
static inline T_1 F_71 ( T_6 V_59 )
{
T_1 V_116 ;
V_116 = ( V_64 T_1 ) V_59 ;
V_116 ^= ( V_116 >> 11 ) ^ ( V_116 >> 22 ) ;
return V_116 & ( V_117 - 1 ) ;
}
static void F_72 ( struct V_53 * V_61 , struct V_106 * V_107 )
{
V_61 -> V_118 = V_107 -> V_119 ;
V_61 -> V_2 . V_120 = V_107 -> V_121 ;
if ( V_107 -> V_122 ) {
V_61 -> V_123 |= V_124 ;
V_61 -> V_63 = V_107 -> V_122 ;
V_61 -> V_125 = 1 ;
}
}
static void F_73 ( struct V_126 * V_127 , T_6 V_59 , T_6 V_128 ,
T_1 V_129 , unsigned long V_120 )
{
struct V_110 * V_111 ;
struct V_106 * V_107 ;
struct V_53 * V_61 ;
unsigned int V_32 ;
int V_130 ;
T_1 V_116 = F_71 ( V_59 ) ;
F_45 ( & V_131 ) ;
V_111 = V_127 -> V_132 ;
if ( ! V_111 ) {
V_111 = F_74 ( V_117 * sizeof( * V_111 ) , V_133 ) ;
if ( ! V_111 )
goto V_134;
V_127 -> V_132 = V_111 ;
}
V_111 += V_116 ;
V_130 = 0 ;
for ( V_107 = F_61 ( V_111 -> V_113 ) ; V_107 ;
V_107 = F_61 ( V_107 -> V_114 ) ) {
if ( V_107 -> V_135 == V_59 )
break;
V_130 ++ ;
}
if ( V_107 ) {
if ( V_128 )
V_107 -> V_122 = V_128 ;
if ( V_129 ) {
V_107 -> V_119 = V_129 ;
V_107 -> V_121 = F_75 ( 1UL , V_120 ) ;
}
V_61 = F_61 ( V_107 -> V_108 ) ;
if ( V_61 )
F_72 ( V_61 , V_107 ) ;
V_61 = F_61 ( V_107 -> V_109 ) ;
if ( V_61 )
F_72 ( V_61 , V_107 ) ;
} else {
if ( V_130 > V_136 )
V_107 = F_69 ( V_111 ) ;
else {
V_107 = F_74 ( sizeof( * V_107 ) , V_133 ) ;
if ( ! V_107 )
goto V_134;
V_107 -> V_114 = V_111 -> V_113 ;
F_76 ( V_111 -> V_113 , V_107 ) ;
}
V_107 -> V_137 = V_137 ( F_36 ( V_127 -> V_138 ) ) ;
V_107 -> V_135 = V_59 ;
V_107 -> V_122 = V_128 ;
V_107 -> V_119 = V_129 ;
V_107 -> V_121 = V_120 ;
V_61 = F_61 ( V_127 -> V_139 ) ;
if ( V_61 )
V_61 -> V_2 . V_140 = V_141 ;
F_21 (i) {
struct V_53 T_8 * * V_142 ;
V_142 = F_22 ( V_127 -> V_143 , V_32 ) ;
V_61 = F_61 ( * V_142 ) ;
if ( V_61 )
V_61 -> V_2 . V_140 = V_141 ;
}
}
V_107 -> V_115 = V_144 ;
V_134:
F_48 ( & V_131 ) ;
return;
}
static void F_77 ( struct V_53 * V_61 , struct V_57 * V_58 , struct V_77 * V_78 ,
bool V_145 )
{
T_6 V_146 = F_78 ( V_58 ) -> V_147 . V_148 ;
T_6 V_149 = F_40 ( V_58 ) -> V_94 ;
struct V_3 * V_4 = V_58 -> V_4 ;
struct V_150 * V_151 ;
struct V_152 V_153 ;
struct V_56 * V_62 ;
struct V_40 * V_40 ;
switch ( F_78 ( V_58 ) -> V_154 & 7 ) {
case V_155 :
case V_156 :
case V_157 :
case V_158 :
break;
default:
return;
}
if ( V_61 -> V_63 != V_149 )
return;
V_151 = F_79 ( V_4 ) ;
if ( ! V_151 )
return;
V_40 = F_36 ( V_4 ) ;
if ( V_146 == V_149 || ! F_80 ( V_151 ) ||
F_81 ( V_146 ) || F_82 ( V_146 ) ||
F_83 ( V_146 ) )
goto V_159;
if ( ! F_84 ( V_151 ) ) {
if ( ! F_85 ( V_151 , V_146 , V_149 ) )
goto V_159;
if ( F_86 ( V_151 ) && F_87 ( V_146 , V_4 ) )
goto V_159;
} else {
if ( F_88 ( V_40 , V_146 ) != V_160 )
goto V_159;
}
V_62 = F_39 ( & V_61 -> V_2 , NULL , & V_146 ) ;
if ( V_62 ) {
if ( ! ( V_62 -> V_161 & V_162 ) ) {
F_89 ( V_62 , NULL ) ;
} else {
if ( F_90 ( V_40 , V_78 , & V_153 ) == 0 ) {
struct V_126 * V_127 = & F_91 ( V_153 ) ;
F_73 ( V_127 , V_78 -> V_59 , V_146 ,
0 , 0 ) ;
}
if ( V_145 )
V_61 -> V_2 . V_140 = V_141 ;
F_92 ( V_163 , V_62 ) ;
}
F_93 ( V_62 ) ;
}
return;
V_159:
#ifdef F_94
if ( F_95 ( V_151 ) ) {
const struct V_66 * V_67 = ( const struct V_66 * ) V_58 -> V_164 ;
T_6 V_59 = V_67 -> V_59 ;
T_6 V_94 = V_67 -> V_94 ;
F_96 ( L_10
L_11 ,
& V_149 , V_4 -> V_165 , & V_146 ,
& V_94 , & V_59 ) ;
}
#endif
;
}
static void F_97 ( struct V_1 * V_2 , struct V_79 * V_80 , struct V_57 * V_58 )
{
struct V_53 * V_61 ;
struct V_77 V_78 ;
const struct V_66 * V_67 = ( const struct V_66 * ) V_58 -> V_164 ;
int V_81 = V_58 -> V_4 -> V_95 ;
T_7 V_82 = F_58 ( V_67 -> V_82 ) ;
T_7 V_83 = V_67 -> V_96 ;
T_1 V_84 = V_58 -> V_84 ;
V_61 = (struct V_53 * ) V_2 ;
F_53 ( & V_78 , V_80 , V_67 , V_81 , V_82 , V_83 , V_84 , 0 ) ;
F_77 ( V_61 , V_58 , & V_78 , true ) ;
}
static struct V_1 * F_98 ( struct V_1 * V_2 )
{
struct V_53 * V_61 = (struct V_53 * ) V_2 ;
struct V_1 * V_166 = V_2 ;
if ( V_61 ) {
if ( V_2 -> V_140 > 0 ) {
F_99 ( V_61 ) ;
V_166 = NULL ;
} else if ( ( V_61 -> V_123 & V_124 ) ||
V_61 -> V_2 . V_120 ) {
F_99 ( V_61 ) ;
V_166 = NULL ;
}
}
return V_166 ;
}
void F_100 ( struct V_57 * V_58 )
{
struct V_53 * V_61 = F_101 ( V_58 ) ;
struct V_150 * V_151 ;
struct V_73 * V_74 ;
struct V_40 * V_40 ;
int V_167 ;
F_60 () ;
V_151 = F_79 ( V_61 -> V_2 . V_4 ) ;
if ( ! V_151 || ! F_102 ( V_151 ) ) {
F_63 () ;
return;
}
V_167 = F_95 ( V_151 ) ;
F_63 () ;
V_40 = F_36 ( V_61 -> V_2 . V_4 ) ;
V_74 = F_50 ( V_40 -> V_75 . V_76 , F_40 ( V_58 ) -> V_94 , 1 ) ;
if ( ! V_74 ) {
F_103 ( V_58 , V_168 , V_157 ,
F_104 ( V_61 , F_40 ( V_58 ) -> V_59 ) ) ;
return;
}
if ( F_105 ( V_144 , V_74 -> V_169 + V_170 ) )
V_74 -> V_171 = 0 ;
if ( V_74 -> V_171 >= V_172 ) {
V_74 -> V_169 = V_144 ;
goto V_173;
}
if ( V_74 -> V_171 == 0 ||
F_105 ( V_144 ,
( V_74 -> V_169 +
( V_174 << V_74 -> V_171 ) ) ) ) {
T_6 V_128 = F_104 ( V_61 , F_40 ( V_58 ) -> V_59 ) ;
F_103 ( V_58 , V_168 , V_157 , V_128 ) ;
V_74 -> V_169 = V_144 ;
++ V_74 -> V_171 ;
#ifdef F_94
if ( V_167 &&
V_74 -> V_171 == V_172 )
F_106 ( L_12 ,
& F_40 ( V_58 ) -> V_94 , F_107 ( V_58 ) ,
& F_40 ( V_58 ) -> V_59 , & V_128 ) ;
#endif
}
V_173:
F_52 ( V_74 ) ;
}
static int F_108 ( struct V_57 * V_58 )
{
struct V_150 * V_151 = F_79 ( V_58 -> V_4 ) ;
struct V_53 * V_61 = F_101 ( V_58 ) ;
struct V_73 * V_74 ;
unsigned long V_175 ;
struct V_40 * V_40 ;
bool V_176 ;
int V_154 ;
V_40 = F_36 ( V_61 -> V_2 . V_4 ) ;
if ( ! F_109 ( V_151 ) ) {
switch ( V_61 -> V_2 . error ) {
case V_177 :
F_110 ( V_40 , V_178 ) ;
break;
case V_179 :
F_110 ( V_40 , V_180 ) ;
break;
}
goto V_181;
}
switch ( V_61 -> V_2 . error ) {
case V_182 :
default:
goto V_181;
case V_177 :
V_154 = V_183 ;
break;
case V_179 :
V_154 = V_184 ;
F_110 ( V_40 , V_180 ) ;
break;
case V_185 :
V_154 = V_186 ;
break;
}
V_74 = F_50 ( V_40 -> V_75 . V_76 , F_40 ( V_58 ) -> V_94 , 1 ) ;
V_176 = true ;
if ( V_74 ) {
V_175 = V_144 ;
V_74 -> V_171 += V_175 - V_74 -> V_169 ;
if ( V_74 -> V_171 > V_187 )
V_74 -> V_171 = V_187 ;
V_74 -> V_169 = V_175 ;
if ( V_74 -> V_171 >= V_188 )
V_74 -> V_171 -= V_188 ;
else
V_176 = false ;
F_52 ( V_74 ) ;
}
if ( V_176 )
F_103 ( V_58 , V_189 , V_154 , 0 ) ;
V_181: F_111 ( V_58 ) ;
return 0 ;
}
static void F_112 ( struct V_53 * V_61 , struct V_77 * V_78 , T_1 V_190 )
{
struct V_1 * V_2 = & V_61 -> V_2 ;
struct V_152 V_153 ;
if ( F_113 ( V_2 , V_191 ) )
return;
if ( V_2 -> V_4 -> V_190 < V_190 )
return;
if ( V_190 < V_192 )
V_190 = V_192 ;
if ( V_61 -> V_118 == V_190 &&
F_70 ( V_144 , V_2 -> V_120 - V_193 / 2 ) )
return;
F_60 () ;
if ( F_90 ( F_36 ( V_2 -> V_4 ) , V_78 , & V_153 ) == 0 ) {
struct V_126 * V_127 = & F_91 ( V_153 ) ;
F_73 ( V_127 , V_78 -> V_59 , 0 , V_190 ,
V_144 + V_193 ) ;
}
F_63 () ;
}
static void F_114 ( struct V_1 * V_2 , struct V_79 * V_80 ,
struct V_57 * V_58 , T_1 V_190 )
{
struct V_53 * V_61 = (struct V_53 * ) V_2 ;
struct V_77 V_78 ;
F_64 ( & V_78 , V_80 , V_58 ) ;
F_112 ( V_61 , & V_78 , V_190 ) ;
}
void F_115 ( struct V_57 * V_58 , struct V_40 * V_40 , T_1 V_190 ,
int V_81 , T_1 V_84 , T_7 V_96 , int V_85 )
{
const struct V_66 * V_67 = ( const struct V_66 * ) V_58 -> V_164 ;
struct V_77 V_78 ;
struct V_53 * V_61 ;
F_53 ( & V_78 , NULL , V_67 , V_81 ,
F_58 ( V_67 -> V_82 ) , V_96 , V_84 , V_85 ) ;
V_61 = F_116 ( V_40 , & V_78 ) ;
if ( ! F_117 ( V_61 ) ) {
F_112 ( V_61 , & V_78 , V_190 ) ;
F_99 ( V_61 ) ;
}
}
static void F_118 ( struct V_57 * V_58 , struct V_79 * V_80 , T_1 V_190 )
{
const struct V_66 * V_67 = ( const struct V_66 * ) V_58 -> V_164 ;
struct V_77 V_78 ;
struct V_53 * V_61 ;
F_53 ( & V_78 , V_80 , V_67 , 0 , 0 , 0 , 0 , 0 ) ;
V_61 = F_116 ( F_119 ( V_80 ) , & V_78 ) ;
if ( ! F_117 ( V_61 ) ) {
F_112 ( V_61 , & V_78 , V_190 ) ;
F_99 ( V_61 ) ;
}
}
void F_120 ( struct V_57 * V_58 , struct V_79 * V_80 , T_1 V_190 )
{
const struct V_66 * V_67 = ( const struct V_66 * ) V_58 -> V_164 ;
struct V_77 V_78 ;
struct V_53 * V_61 ;
struct V_1 * V_2 ;
bool V_194 = false ;
F_121 ( V_80 ) ;
if ( ! F_122 ( V_80 ) )
goto V_181;
V_61 = (struct V_53 * ) F_123 ( V_80 ) ;
if ( F_124 ( V_80 ) || ! V_61 ) {
F_118 ( V_58 , V_80 , V_190 ) ;
goto V_181;
}
F_53 ( & V_78 , V_80 , V_67 , 0 , 0 , 0 , 0 , 0 ) ;
if ( ! F_125 ( V_80 , 0 ) ) {
V_61 = F_126 ( F_119 ( V_80 ) , & V_78 , V_80 ) ;
if ( F_117 ( V_61 ) )
goto V_181;
V_194 = true ;
}
F_112 ( (struct V_53 * ) V_61 -> V_2 . V_195 , & V_78 , V_190 ) ;
V_2 = F_127 ( & V_61 -> V_2 , 0 ) ;
if ( ! V_2 ) {
if ( V_194 )
F_128 ( & V_61 -> V_2 ) ;
V_61 = F_126 ( F_119 ( V_80 ) , & V_78 , V_80 ) ;
if ( F_117 ( V_61 ) )
goto V_181;
V_194 = true ;
}
if ( V_194 )
F_129 ( V_80 , & V_61 -> V_2 ) ;
V_181:
F_130 ( V_80 ) ;
}
void F_131 ( struct V_57 * V_58 , struct V_40 * V_40 ,
int V_81 , T_1 V_84 , T_7 V_96 , int V_85 )
{
const struct V_66 * V_67 = ( const struct V_66 * ) V_58 -> V_164 ;
struct V_77 V_78 ;
struct V_53 * V_61 ;
F_53 ( & V_78 , NULL , V_67 , V_81 ,
F_58 ( V_67 -> V_82 ) , V_96 , V_84 , V_85 ) ;
V_61 = F_116 ( V_40 , & V_78 ) ;
if ( ! F_117 ( V_61 ) ) {
F_77 ( V_61 , V_58 , & V_78 , false ) ;
F_99 ( V_61 ) ;
}
}
void F_132 ( struct V_57 * V_58 , struct V_79 * V_80 )
{
const struct V_66 * V_67 = ( const struct V_66 * ) V_58 -> V_164 ;
struct V_77 V_78 ;
struct V_53 * V_61 ;
F_53 ( & V_78 , V_80 , V_67 , 0 , 0 , 0 , 0 , 0 ) ;
V_61 = F_116 ( F_119 ( V_80 ) , & V_78 ) ;
if ( ! F_117 ( V_61 ) ) {
F_77 ( V_61 , V_58 , & V_78 , false ) ;
F_99 ( V_61 ) ;
}
}
static struct V_1 * F_133 ( struct V_1 * V_2 , T_1 V_196 )
{
struct V_53 * V_61 = (struct V_53 * ) V_2 ;
if ( V_2 -> V_140 != V_197 || F_34 ( V_61 ) )
return NULL ;
return V_2 ;
}
static void F_134 ( struct V_57 * V_58 )
{
struct V_53 * V_61 ;
F_103 ( V_58 , V_189 , V_183 , 0 ) ;
V_61 = F_101 ( V_58 ) ;
if ( V_61 )
F_135 ( & V_61 -> V_2 , 0 ) ;
}
static int F_136 ( struct V_57 * V_58 )
{
F_137 ( L_13 ,
V_198 , & F_40 ( V_58 ) -> V_94 , & F_40 ( V_58 ) -> V_59 ,
V_58 -> V_4 ? V_58 -> V_4 -> V_165 : L_14 ) ;
F_111 ( V_58 ) ;
F_3 ( 1 ) ;
return 0 ;
}
void F_138 ( T_7 * V_199 , struct V_57 * V_58 , struct V_53 * V_61 )
{
T_6 V_31 ;
if ( F_139 ( V_61 ) )
V_31 = F_40 ( V_58 ) -> V_94 ;
else {
struct V_152 V_153 ;
struct V_77 V_78 ;
struct V_66 * V_67 ;
V_67 = F_40 ( V_58 ) ;
memset ( & V_78 , 0 , sizeof( V_78 ) ) ;
V_78 . V_59 = V_67 -> V_59 ;
V_78 . V_94 = V_67 -> V_94 ;
V_78 . V_200 = F_58 ( V_67 -> V_82 ) ;
V_78 . V_201 = V_61 -> V_2 . V_4 -> V_95 ;
V_78 . V_202 = V_58 -> V_4 -> V_95 ;
V_78 . V_203 = V_58 -> V_84 ;
F_60 () ;
if ( F_90 ( F_36 ( V_61 -> V_2 . V_4 ) , & V_78 , & V_153 ) == 0 )
V_31 = F_140 ( F_36 ( V_61 -> V_2 . V_4 ) , V_153 ) ;
else
V_31 = F_141 ( V_61 -> V_2 . V_4 ,
F_104 ( V_61 , V_67 -> V_59 ) ,
V_93 ) ;
F_63 () ;
}
memcpy ( V_199 , & V_31 , 4 ) ;
}
static void F_142 ( struct V_53 * V_61 , T_1 V_204 )
{
if ( ! ( V_61 -> V_2 . V_205 & 0xFFFF ) )
V_61 -> V_2 . V_205 |= V_204 & 0xFFFF ;
if ( ! ( V_61 -> V_2 . V_205 & 0xFFFF0000 ) )
V_61 -> V_2 . V_205 |= V_204 & 0xFFFF0000 ;
}
static unsigned int F_143 ( const struct V_1 * V_2 )
{
unsigned int V_206 = F_144 ( V_2 , V_207 ) ;
if ( V_206 == 0 ) {
V_206 = F_145 (unsigned int, dst->dev->mtu - 40 ,
ip_rt_min_advmss) ;
if ( V_206 > 65535 - 40 )
V_206 = 65535 - 40 ;
}
return V_206 ;
}
static unsigned int F_146 ( const struct V_1 * V_2 )
{
const struct V_53 * V_61 = ( const struct V_53 * ) V_2 ;
unsigned int V_190 = V_61 -> V_118 ;
if ( ! V_190 || F_147 ( V_144 , V_61 -> V_2 . V_120 ) )
V_190 = F_144 ( V_2 , V_191 ) ;
if ( V_190 )
return V_190 ;
V_190 = V_2 -> V_4 -> V_190 ;
if ( F_148 ( F_113 ( V_2 , V_191 ) ) ) {
if ( V_61 -> V_125 && V_190 > 576 )
V_190 = 576 ;
}
return F_149 (unsigned int, mtu, IP_MAX_MTU) ;
}
static struct V_106 * F_150 ( struct V_126 * V_127 , T_6 V_59 )
{
struct V_110 * V_111 = V_127 -> V_132 ;
struct V_106 * V_107 ;
T_1 V_116 ;
if ( ! V_111 )
return NULL ;
V_116 = F_71 ( V_59 ) ;
for ( V_107 = F_61 ( V_111 [ V_116 ] . V_113 ) ; V_107 ;
V_107 = F_61 ( V_107 -> V_114 ) ) {
if ( V_107 -> V_135 == V_59 )
return V_107 ;
}
return NULL ;
}
static bool F_151 ( struct V_53 * V_61 , struct V_106 * V_107 ,
T_6 V_59 )
{
bool V_166 = false ;
F_45 ( & V_131 ) ;
if ( V_59 == V_107 -> V_135 ) {
struct V_53 T_8 * * V_208 ;
struct V_53 * V_209 ;
int V_210 = V_137 ( F_36 ( V_61 -> V_2 . V_4 ) ) ;
if ( F_152 ( V_61 ) )
V_208 = & V_107 -> V_108 ;
else
V_208 = & V_107 -> V_109 ;
V_209 = F_61 ( * V_208 ) ;
if ( V_107 -> V_137 != V_210 ) {
V_107 -> V_137 = V_210 ;
V_107 -> V_122 = 0 ;
V_107 -> V_119 = 0 ;
V_107 -> V_121 = 0 ;
F_67 ( V_107 ) ;
V_209 = NULL ;
}
F_72 ( V_61 , V_107 ) ;
if ( ! V_61 -> V_63 )
V_61 -> V_63 = V_59 ;
if ( ! ( V_61 -> V_2 . V_211 & V_212 ) ) {
F_76 ( * V_208 , V_61 ) ;
if ( V_209 )
F_65 ( V_209 ) ;
V_166 = true ;
}
V_107 -> V_115 = V_144 ;
}
F_48 ( & V_131 ) ;
return V_166 ;
}
static bool F_153 ( struct V_126 * V_127 , struct V_53 * V_61 )
{
struct V_53 * V_209 , * V_213 , * * V_214 ;
bool V_166 = true ;
if ( F_152 ( V_61 ) ) {
V_214 = (struct V_53 * * ) & V_127 -> V_139 ;
} else {
V_214 = (struct V_53 * * ) F_154 ( V_127 -> V_143 ) ;
}
V_209 = * V_214 ;
V_213 = F_155 ( V_214 , V_209 , V_61 ) ;
if ( V_213 == V_209 ) {
if ( V_209 )
F_65 ( V_209 ) ;
} else
V_166 = false ;
return V_166 ;
}
static void F_156 ( struct V_53 * V_61 )
{
F_45 ( & V_215 ) ;
F_157 ( & V_61 -> V_216 , & V_217 ) ;
F_48 ( & V_215 ) ;
}
static void F_158 ( struct V_1 * V_2 )
{
struct V_53 * V_61 = (struct V_53 * ) V_2 ;
if ( ! F_159 ( & V_61 -> V_216 ) ) {
F_45 ( & V_215 ) ;
F_160 ( & V_61 -> V_216 ) ;
F_48 ( & V_215 ) ;
}
}
void F_161 ( struct V_3 * V_4 )
{
if ( ! F_159 ( & V_217 ) ) {
struct V_40 * V_40 = F_36 ( V_4 ) ;
struct V_53 * V_61 ;
F_45 ( & V_215 ) ;
F_162 (rt, &rt_uncached_list, rt_uncached) {
if ( V_61 -> V_2 . V_4 != V_4 )
continue;
V_61 -> V_2 . V_4 = V_40 -> V_218 ;
F_163 ( V_61 -> V_2 . V_4 ) ;
F_164 ( V_4 ) ;
}
F_48 ( & V_215 ) ;
}
}
static bool F_165 ( const struct V_53 * V_61 )
{
return V_61 &&
V_61 -> V_2 . V_140 == V_197 &&
! F_34 ( V_61 ) ;
}
static void F_166 ( struct V_53 * V_61 , T_6 V_59 ,
const struct V_152 * V_153 ,
struct V_106 * V_107 ,
struct V_219 * V_220 , T_9 type , T_1 V_221 )
{
bool V_222 = false ;
if ( V_220 ) {
struct V_126 * V_127 = & F_91 ( * V_153 ) ;
if ( V_127 -> V_223 && V_127 -> V_224 == V_225 ) {
V_61 -> V_63 = V_127 -> V_223 ;
V_61 -> V_125 = 1 ;
}
F_167 ( & V_61 -> V_2 , V_220 -> V_226 , true ) ;
#ifdef F_29
V_61 -> V_2 . V_205 = V_127 -> V_227 ;
#endif
if ( F_148 ( V_107 ) )
V_222 = F_151 ( V_61 , V_107 , V_59 ) ;
else if ( ! ( V_61 -> V_2 . V_211 & V_212 ) )
V_222 = F_153 ( V_127 , V_61 ) ;
if ( F_148 ( ! V_222 ) ) {
V_61 -> V_2 . V_211 |= V_212 ;
if ( ! V_61 -> V_63 )
V_61 -> V_63 = V_59 ;
F_156 ( V_61 ) ;
}
} else
F_156 ( V_61 ) ;
#ifdef F_29
#ifdef F_168
F_142 ( V_61 , V_153 -> V_205 ) ;
#endif
F_142 ( V_61 , V_221 ) ;
#endif
}
static struct V_53 * F_169 ( struct V_3 * V_4 ,
bool V_228 , bool V_229 , bool V_230 )
{
return F_170 ( & V_19 , V_4 , 1 , V_197 ,
( V_230 ? 0 : ( V_231 | V_212 ) ) |
( V_228 ? V_232 : 0 ) |
( V_229 ? V_233 : 0 ) ) ;
}
static int F_171 ( struct V_57 * V_58 , T_6 V_59 , T_6 V_94 ,
T_7 V_82 , struct V_3 * V_4 , int V_234 )
{
struct V_53 * V_54 ;
struct V_150 * V_151 = F_79 ( V_4 ) ;
T_1 V_221 = 0 ;
int V_235 ;
if ( V_151 == NULL )
return - V_182 ;
if ( F_81 ( V_94 ) || F_82 ( V_94 ) ||
V_58 -> V_96 != F_47 ( V_236 ) )
goto V_237;
if ( F_172 ( ! F_173 ( V_151 ) ) )
if ( F_174 ( V_94 ) )
goto V_237;
if ( F_83 ( V_94 ) ) {
if ( ! F_175 ( V_59 ) )
goto V_237;
} else {
V_235 = F_176 ( V_58 , V_94 , 0 , V_82 , 0 , V_4 ,
V_151 , & V_221 ) ;
if ( V_235 < 0 )
goto V_238;
}
V_54 = F_169 ( F_36 ( V_4 ) -> V_218 ,
F_177 ( V_151 , V_239 ) , false , false ) ;
if ( ! V_54 )
goto V_240;
#ifdef F_29
V_54 -> V_2 . V_205 = V_221 ;
#endif
V_54 -> V_2 . V_241 = F_136 ;
V_54 -> V_55 = F_35 ( F_36 ( V_4 ) ) ;
V_54 -> V_123 = V_242 ;
V_54 -> V_243 = V_244 ;
V_54 -> V_245 = 1 ;
V_54 -> V_246 = 0 ;
V_54 -> V_118 = 0 ;
V_54 -> V_63 = 0 ;
V_54 -> V_125 = 0 ;
F_178 ( & V_54 -> V_216 ) ;
if ( V_234 ) {
V_54 -> V_2 . V_247 = V_248 ;
V_54 -> V_123 |= V_249 ;
}
#ifdef F_179
if ( ! F_175 ( V_59 ) && F_180 ( V_151 ) )
V_54 -> V_2 . V_247 = V_250 ;
#endif
F_181 ( V_21 ) ;
F_182 ( V_58 , & V_54 -> V_2 ) ;
return 0 ;
V_240:
return - V_251 ;
V_237:
return - V_182 ;
V_238:
return V_235 ;
}
static void F_183 ( struct V_3 * V_4 ,
struct V_150 * V_151 ,
struct V_57 * V_58 ,
T_6 V_59 ,
T_6 V_94 )
{
F_181 ( V_25 ) ;
#ifdef F_94
if ( F_95 ( V_151 ) && F_184 () ) {
F_185 ( L_15 ,
& V_59 , & V_94 , V_4 -> V_165 ) ;
if ( V_4 -> V_252 && F_186 ( V_58 ) ) {
F_187 ( V_253 , L_16 ,
V_254 , 16 , 1 ,
F_188 ( V_58 ) ,
V_4 -> V_252 , true ) ;
}
}
#endif
}
static int F_189 ( struct V_57 * V_58 ,
const struct V_152 * V_153 ,
struct V_150 * V_151 ,
T_6 V_59 , T_6 V_94 , T_1 V_82 )
{
struct V_106 * V_107 ;
struct V_53 * V_54 ;
int V_235 ;
struct V_150 * V_255 ;
unsigned int V_211 = 0 ;
bool V_256 ;
T_1 V_221 ;
V_255 = F_79 ( F_190 ( * V_153 ) ) ;
if ( V_255 == NULL ) {
F_191 ( L_17 ) ;
return - V_182 ;
}
V_235 = F_176 ( V_58 , V_94 , V_59 , V_82 , F_192 ( * V_153 ) ,
V_151 -> V_4 , V_151 , & V_221 ) ;
if ( V_235 < 0 ) {
F_183 ( V_151 -> V_4 , V_151 , V_58 , V_59 ,
V_94 ) ;
goto V_257;
}
V_256 = V_153 -> V_220 && ! V_221 ;
if ( V_255 == V_151 && V_235 && F_102 ( V_255 ) &&
( F_84 ( V_255 ) ||
F_85 ( V_255 , V_94 , F_193 ( * V_153 ) ) ) ) {
V_211 |= V_258 ;
V_256 = false ;
}
if ( V_58 -> V_96 != F_47 ( V_236 ) ) {
if ( V_255 == V_151 &&
F_194 ( V_151 ) == 0 ) {
V_235 = - V_182 ;
goto V_257;
}
}
V_107 = F_150 ( & F_91 ( * V_153 ) , V_59 ) ;
if ( V_256 ) {
if ( V_107 != NULL )
V_54 = F_61 ( V_107 -> V_108 ) ;
else
V_54 = F_61 ( F_91 ( * V_153 ) . V_139 ) ;
if ( F_165 ( V_54 ) ) {
F_195 ( V_58 , & V_54 -> V_2 ) ;
goto V_181;
}
}
V_54 = F_169 ( V_255 -> V_4 ,
F_177 ( V_151 , V_239 ) ,
F_177 ( V_255 , V_259 ) , V_256 ) ;
if ( ! V_54 ) {
V_235 = - V_251 ;
goto V_257;
}
V_54 -> V_55 = F_35 ( F_36 ( V_54 -> V_2 . V_4 ) ) ;
V_54 -> V_123 = V_211 ;
V_54 -> V_243 = V_153 -> type ;
V_54 -> V_245 = 1 ;
V_54 -> V_246 = 0 ;
V_54 -> V_118 = 0 ;
V_54 -> V_63 = 0 ;
V_54 -> V_125 = 0 ;
F_178 ( & V_54 -> V_216 ) ;
F_181 ( V_20 ) ;
V_54 -> V_2 . V_247 = V_260 ;
V_54 -> V_2 . V_241 = V_261 ;
F_166 ( V_54 , V_59 , V_153 , V_107 , V_153 -> V_220 , V_153 -> type , V_221 ) ;
F_182 ( V_58 , & V_54 -> V_2 ) ;
V_181:
V_235 = 0 ;
V_257:
return V_235 ;
}
static int F_196 ( struct V_57 * V_58 ,
struct V_152 * V_153 ,
const struct V_77 * V_78 ,
struct V_150 * V_151 ,
T_6 V_59 , T_6 V_94 , T_1 V_82 )
{
#ifdef F_197
if ( V_153 -> V_220 && V_153 -> V_220 -> V_262 > 1 )
F_198 ( V_153 ) ;
#endif
return F_189 ( V_58 , V_153 , V_151 , V_59 , V_94 , V_82 ) ;
}
static int F_199 ( struct V_57 * V_58 , T_6 V_59 , T_6 V_94 ,
T_7 V_82 , struct V_3 * V_4 )
{
struct V_152 V_153 ;
struct V_150 * V_151 = F_79 ( V_4 ) ;
struct V_77 V_78 ;
unsigned int V_211 = 0 ;
T_1 V_221 = 0 ;
struct V_53 * V_54 ;
int V_235 = - V_182 ;
struct V_40 * V_40 = F_36 ( V_4 ) ;
bool V_256 ;
if ( ! V_151 )
goto V_181;
if ( F_81 ( V_94 ) || F_82 ( V_94 ) )
goto V_263;
V_153 . V_220 = NULL ;
if ( F_82 ( V_59 ) || ( V_94 == 0 && V_59 == 0 ) )
goto V_264;
if ( F_83 ( V_94 ) )
goto V_263;
if ( F_83 ( V_59 ) )
goto V_265;
if ( F_174 ( V_59 ) ) {
if ( ! F_200 ( V_151 , V_40 ) )
goto V_265;
} else if ( F_174 ( V_94 ) ) {
if ( ! F_200 ( V_151 , V_40 ) )
goto V_263;
}
V_78 . V_201 = 0 ;
V_78 . V_202 = V_4 -> V_95 ;
V_78 . V_203 = V_58 -> V_84 ;
V_78 . V_200 = V_82 ;
V_78 . V_266 = V_93 ;
V_78 . V_59 = V_59 ;
V_78 . V_94 = V_94 ;
V_235 = F_90 ( V_40 , & V_78 , & V_153 ) ;
if ( V_235 != 0 ) {
if ( ! F_109 ( V_151 ) )
V_235 = - V_177 ;
goto V_267;
}
if ( V_153 . type == V_268 )
goto V_264;
if ( V_153 . type == V_269 ) {
V_235 = F_176 ( V_58 , V_94 , V_59 , V_82 ,
V_270 ,
V_4 , V_151 , & V_221 ) ;
if ( V_235 < 0 )
goto V_271;
goto V_272;
}
if ( ! F_109 ( V_151 ) ) {
V_235 = - V_177 ;
goto V_267;
}
if ( V_153 . type != V_160 )
goto V_265;
V_235 = F_196 ( V_58 , & V_153 , & V_78 , V_151 , V_59 , V_94 , V_82 ) ;
V_181: return V_235 ;
V_264:
if ( V_58 -> V_96 != F_47 ( V_236 ) )
goto V_237;
if ( ! F_83 ( V_94 ) ) {
V_235 = F_176 ( V_58 , V_94 , 0 , V_82 , 0 , V_4 ,
V_151 , & V_221 ) ;
if ( V_235 < 0 )
goto V_271;
}
V_211 |= V_273 ;
V_153 . type = V_268 ;
F_181 ( V_23 ) ;
V_272:
V_256 = false ;
if ( V_153 . V_220 ) {
if ( ! V_221 ) {
V_54 = F_61 ( F_91 ( V_153 ) . V_139 ) ;
if ( F_165 ( V_54 ) ) {
F_195 ( V_58 , & V_54 -> V_2 ) ;
V_235 = 0 ;
goto V_181;
}
V_256 = true ;
}
}
V_54 = F_169 ( V_40 -> V_218 ,
F_177 ( V_151 , V_239 ) , false , V_256 ) ;
if ( ! V_54 )
goto V_240;
V_54 -> V_2 . V_247 = V_248 ;
V_54 -> V_2 . V_241 = F_136 ;
#ifdef F_29
V_54 -> V_2 . V_205 = V_221 ;
#endif
V_54 -> V_55 = F_35 ( V_40 ) ;
V_54 -> V_123 = V_211 | V_249 ;
V_54 -> V_243 = V_153 . type ;
V_54 -> V_245 = 1 ;
V_54 -> V_246 = 0 ;
V_54 -> V_118 = 0 ;
V_54 -> V_63 = 0 ;
V_54 -> V_125 = 0 ;
F_178 ( & V_54 -> V_216 ) ;
F_181 ( V_20 ) ;
if ( V_153 . type == V_274 ) {
V_54 -> V_2 . V_247 = F_108 ;
V_54 -> V_2 . error = - V_235 ;
V_54 -> V_123 &= ~ V_249 ;
}
if ( V_256 ) {
if ( F_148 ( ! F_153 ( & F_91 ( V_153 ) , V_54 ) ) ) {
V_54 -> V_2 . V_211 |= V_212 ;
F_156 ( V_54 ) ;
}
}
F_182 ( V_58 , & V_54 -> V_2 ) ;
V_235 = 0 ;
goto V_181;
V_267:
F_181 ( V_22 ) ;
V_153 . type = V_274 ;
if ( V_235 == - V_275 )
V_235 = - V_179 ;
goto V_272;
V_265:
F_181 ( V_24 ) ;
#ifdef F_94
if ( F_95 ( V_151 ) )
F_106 ( L_18 ,
& V_59 , & V_94 , V_4 -> V_165 ) ;
#endif
V_237:
V_235 = - V_182 ;
goto V_181;
V_240:
V_235 = - V_251 ;
goto V_181;
V_263:
V_235 = - V_182 ;
V_271:
F_183 ( V_4 , V_151 , V_58 , V_59 , V_94 ) ;
goto V_181;
}
int F_201 ( struct V_57 * V_58 , T_6 V_59 , T_6 V_94 ,
T_7 V_82 , struct V_3 * V_4 )
{
int V_153 ;
F_60 () ;
if ( F_81 ( V_59 ) ) {
struct V_150 * V_151 = F_79 ( V_4 ) ;
if ( V_151 ) {
int V_234 = F_202 ( V_151 , V_59 , V_94 ,
F_40 ( V_58 ) -> V_96 ) ;
if ( V_234
#ifdef F_179
||
( ! F_175 ( V_59 ) &&
F_180 ( V_151 ) )
#endif
) {
int V_153 = F_171 ( V_58 , V_59 , V_94 ,
V_82 , V_4 , V_234 ) ;
F_63 () ;
return V_153 ;
}
}
F_63 () ;
return - V_182 ;
}
V_153 = F_199 ( V_58 , V_59 , V_94 , V_82 , V_4 ) ;
F_63 () ;
return V_153 ;
}
static struct V_53 * F_203 ( const struct V_152 * V_153 ,
const struct V_77 * V_78 , int V_276 ,
struct V_3 * V_277 ,
unsigned int V_211 )
{
struct V_219 * V_220 = V_153 -> V_220 ;
struct V_106 * V_107 ;
struct V_150 * V_151 ;
T_9 type = V_153 -> type ;
struct V_53 * V_54 ;
bool V_256 ;
V_151 = F_79 ( V_277 ) ;
if ( ! V_151 )
return F_204 ( - V_182 ) ;
if ( F_172 ( ! F_173 ( V_151 ) ) )
if ( F_174 ( V_78 -> V_94 ) && ! ( V_277 -> V_211 & V_278 ) )
return F_204 ( - V_182 ) ;
if ( F_82 ( V_78 -> V_59 ) )
type = V_268 ;
else if ( F_81 ( V_78 -> V_59 ) )
type = V_244 ;
else if ( F_83 ( V_78 -> V_59 ) )
return F_204 ( - V_182 ) ;
if ( V_277 -> V_211 & V_278 )
V_211 |= V_249 ;
V_256 = true ;
if ( type == V_268 ) {
V_211 |= V_273 | V_249 ;
V_220 = NULL ;
} else if ( type == V_244 ) {
V_211 |= V_242 | V_249 ;
if ( ! F_202 ( V_151 , V_78 -> V_59 , V_78 -> V_94 ,
V_78 -> V_279 ) )
V_211 &= ~ V_249 ;
else
V_256 = false ;
if ( V_220 && V_153 -> V_280 < 4 )
V_220 = NULL ;
}
V_107 = NULL ;
V_256 &= V_220 != NULL ;
if ( V_256 ) {
struct V_53 T_8 * * V_281 ;
struct V_126 * V_127 = & F_91 ( * V_153 ) ;
V_107 = F_150 ( V_127 , V_78 -> V_59 ) ;
if ( V_107 )
V_281 = & V_107 -> V_109 ;
else {
if ( F_148 ( V_78 -> V_282 &
V_283 &&
! ( V_127 -> V_223 &&
V_127 -> V_224 == V_225 ) ) ) {
V_256 = false ;
goto V_284;
}
V_281 = F_154 ( V_127 -> V_143 ) ;
}
V_54 = F_61 ( * V_281 ) ;
if ( F_165 ( V_54 ) ) {
F_205 ( & V_54 -> V_2 ) ;
return V_54 ;
}
}
V_284:
V_54 = F_169 ( V_277 ,
F_177 ( V_151 , V_239 ) ,
F_177 ( V_151 , V_259 ) ,
V_256 ) ;
if ( ! V_54 )
return F_204 ( - V_251 ) ;
V_54 -> V_2 . V_241 = V_261 ;
V_54 -> V_55 = F_35 ( F_36 ( V_277 ) ) ;
V_54 -> V_123 = V_211 ;
V_54 -> V_243 = type ;
V_54 -> V_245 = 0 ;
V_54 -> V_246 = V_276 ? : 0 ;
V_54 -> V_118 = 0 ;
V_54 -> V_63 = 0 ;
V_54 -> V_125 = 0 ;
F_178 ( & V_54 -> V_216 ) ;
F_181 ( V_26 ) ;
if ( V_211 & V_249 )
V_54 -> V_2 . V_247 = V_248 ;
if ( V_211 & ( V_273 | V_242 ) ) {
if ( V_211 & V_249 &&
! ( V_277 -> V_211 & V_278 ) ) {
V_54 -> V_2 . V_241 = V_285 ;
F_181 ( V_27 ) ;
}
#ifdef F_179
if ( type == V_244 ) {
if ( F_180 ( V_151 ) &&
! F_175 ( V_78 -> V_59 ) ) {
V_54 -> V_2 . V_247 = V_250 ;
V_54 -> V_2 . V_241 = V_285 ;
}
}
#endif
}
F_166 ( V_54 , V_78 -> V_59 , V_153 , V_107 , V_220 , type , 0 ) ;
return V_54 ;
}
struct V_53 * F_116 ( struct V_40 * V_40 , struct V_77 * V_78 )
{
struct V_3 * V_277 = NULL ;
T_10 V_82 = F_206 ( V_78 ) ;
unsigned int V_211 = 0 ;
struct V_152 V_153 ;
struct V_53 * V_54 ;
int V_276 ;
V_153 . V_205 = 0 ;
V_153 . V_220 = NULL ;
V_153 . V_286 = NULL ;
V_276 = V_78 -> V_201 ;
V_78 -> V_202 = V_270 ;
V_78 -> V_200 = V_82 & V_287 ;
V_78 -> V_266 = ( ( V_82 & V_288 ) ?
V_225 : V_93 ) ;
F_60 () ;
if ( V_78 -> V_94 ) {
V_54 = F_204 ( - V_182 ) ;
if ( F_81 ( V_78 -> V_94 ) ||
F_82 ( V_78 -> V_94 ) ||
F_83 ( V_78 -> V_94 ) )
goto V_181;
if ( V_78 -> V_201 == 0 &&
( F_81 ( V_78 -> V_59 ) ||
F_82 ( V_78 -> V_59 ) ) ) {
V_277 = F_207 ( V_40 , V_78 -> V_94 , false ) ;
if ( V_277 == NULL )
goto V_181;
V_78 -> V_201 = V_277 -> V_95 ;
goto V_289;
}
if ( ! ( V_78 -> V_282 & V_290 ) ) {
if ( ! F_207 ( V_40 , V_78 -> V_94 , false ) )
goto V_181;
}
}
if ( V_78 -> V_201 ) {
V_277 = F_208 ( V_40 , V_78 -> V_201 ) ;
V_54 = F_204 ( - V_291 ) ;
if ( V_277 == NULL )
goto V_181;
if ( ! ( V_277 -> V_211 & V_292 ) || ! F_79 ( V_277 ) ) {
V_54 = F_204 ( - V_179 ) ;
goto V_181;
}
if ( F_175 ( V_78 -> V_59 ) ||
F_82 ( V_78 -> V_59 ) ) {
if ( ! V_78 -> V_94 )
V_78 -> V_94 = F_141 ( V_277 , 0 ,
V_225 ) ;
goto V_289;
}
if ( ! V_78 -> V_94 ) {
if ( F_81 ( V_78 -> V_59 ) )
V_78 -> V_94 = F_141 ( V_277 , 0 ,
V_78 -> V_266 ) ;
else if ( ! V_78 -> V_59 )
V_78 -> V_94 = F_141 ( V_277 , 0 ,
V_293 ) ;
}
}
if ( ! V_78 -> V_59 ) {
V_78 -> V_59 = V_78 -> V_94 ;
if ( ! V_78 -> V_59 )
V_78 -> V_59 = V_78 -> V_94 = F_209 ( V_294 ) ;
V_277 = V_40 -> V_218 ;
V_78 -> V_201 = V_270 ;
V_153 . type = V_269 ;
V_211 |= V_249 ;
goto V_289;
}
if ( F_90 ( V_40 , V_78 , & V_153 ) ) {
V_153 . V_220 = NULL ;
V_153 . V_286 = NULL ;
if ( V_78 -> V_201 ) {
if ( V_78 -> V_94 == 0 )
V_78 -> V_94 = F_141 ( V_277 , 0 ,
V_225 ) ;
V_153 . type = V_160 ;
goto V_289;
}
V_54 = F_204 ( - V_179 ) ;
goto V_181;
}
if ( V_153 . type == V_269 ) {
if ( ! V_78 -> V_94 ) {
if ( V_153 . V_220 -> V_295 )
V_78 -> V_94 = V_153 . V_220 -> V_295 ;
else
V_78 -> V_94 = V_78 -> V_59 ;
}
V_277 = V_40 -> V_218 ;
V_78 -> V_201 = V_277 -> V_95 ;
V_211 |= V_249 ;
goto V_289;
}
#ifdef F_197
if ( V_153 . V_220 -> V_262 > 1 && V_78 -> V_201 == 0 )
F_198 ( & V_153 ) ;
else
#endif
if ( ! V_153 . V_280 &&
V_153 . V_286 -> V_296 > 1 &&
V_153 . type == V_160 && ! V_78 -> V_201 )
F_210 ( & V_153 ) ;
if ( ! V_78 -> V_94 )
V_78 -> V_94 = F_140 ( V_40 , V_153 ) ;
V_277 = F_190 ( V_153 ) ;
V_78 -> V_201 = V_277 -> V_95 ;
V_289:
V_54 = F_203 ( & V_153 , V_78 , V_276 , V_277 , V_211 ) ;
V_181:
F_63 () ;
return V_54 ;
}
static struct V_1 * F_211 ( struct V_1 * V_2 , T_1 V_196 )
{
return NULL ;
}
static unsigned int F_212 ( const struct V_1 * V_2 )
{
unsigned int V_190 = F_144 ( V_2 , V_191 ) ;
return V_190 ? : V_2 -> V_4 -> V_190 ;
}
static void F_213 ( struct V_1 * V_2 , struct V_79 * V_80 ,
struct V_57 * V_58 , T_1 V_190 )
{
}
static void F_214 ( struct V_1 * V_2 , struct V_79 * V_80 ,
struct V_57 * V_58 )
{
}
static T_1 * F_215 ( struct V_1 * V_2 ,
unsigned long V_6 )
{
return NULL ;
}
struct V_1 * F_216 ( struct V_40 * V_40 , struct V_1 * V_297 )
{
struct V_53 * V_298 = (struct V_53 * ) V_297 ;
struct V_53 * V_61 ;
V_61 = F_170 ( & V_299 , NULL , 1 , V_300 , 0 ) ;
if ( V_61 ) {
struct V_1 * V_194 = & V_61 -> V_2 ;
V_194 -> V_301 = 1 ;
V_194 -> V_247 = V_302 ;
V_194 -> V_241 = V_302 ;
V_194 -> V_4 = V_298 -> V_2 . V_4 ;
if ( V_194 -> V_4 )
F_163 ( V_194 -> V_4 ) ;
V_61 -> V_245 = V_298 -> V_245 ;
V_61 -> V_246 = V_298 -> V_246 ;
V_61 -> V_118 = V_298 -> V_118 ;
V_61 -> V_55 = F_35 ( V_40 ) ;
V_61 -> V_123 = V_298 -> V_123 ;
V_61 -> V_243 = V_298 -> V_243 ;
V_61 -> V_63 = V_298 -> V_63 ;
V_61 -> V_125 = V_298 -> V_125 ;
F_178 ( & V_61 -> V_216 ) ;
F_217 ( V_194 ) ;
}
F_128 ( V_297 ) ;
return V_61 ? & V_61 -> V_2 : F_204 ( - V_35 ) ;
}
struct V_53 * F_126 ( struct V_40 * V_40 , struct V_77 * V_303 ,
struct V_79 * V_80 )
{
struct V_53 * V_61 = F_116 ( V_40 , V_303 ) ;
if ( F_117 ( V_61 ) )
return V_61 ;
if ( V_303 -> V_279 )
V_61 = (struct V_53 * ) F_218 ( V_40 , & V_61 -> V_2 ,
F_219 ( V_303 ) ,
V_80 , 0 ) ;
return V_61 ;
}
static int F_220 ( struct V_40 * V_40 , T_6 V_2 , T_6 V_31 ,
struct V_77 * V_78 , struct V_57 * V_58 , T_1 V_304 ,
T_1 V_8 , int V_305 , int V_306 , unsigned int V_211 )
{
struct V_53 * V_61 = F_101 ( V_58 ) ;
struct V_307 * V_308 ;
struct V_309 * V_310 ;
unsigned long V_120 = 0 ;
T_1 error ;
T_1 V_311 [ V_312 ] ;
V_310 = F_221 ( V_58 , V_304 , V_8 , V_305 , sizeof( * V_308 ) , V_211 ) ;
if ( V_310 == NULL )
return - V_313 ;
V_308 = F_222 ( V_310 ) ;
V_308 -> V_314 = V_315 ;
V_308 -> V_316 = 32 ;
V_308 -> V_317 = 0 ;
V_308 -> V_318 = V_78 -> V_200 ;
V_308 -> V_319 = V_320 ;
if ( F_223 ( V_58 , V_321 , V_320 ) )
goto V_322;
V_308 -> V_323 = V_61 -> V_243 ;
V_308 -> V_324 = V_93 ;
V_308 -> V_325 = V_326 ;
V_308 -> V_327 = ( V_61 -> V_123 & ~ 0xFFFF ) | V_328 ;
if ( V_61 -> V_123 & V_329 )
V_308 -> V_327 |= V_330 ;
if ( F_224 ( V_58 , V_331 , V_2 ) )
goto V_322;
if ( V_31 ) {
V_308 -> V_317 = 32 ;
if ( F_224 ( V_58 , V_332 , V_31 ) )
goto V_322;
}
if ( V_61 -> V_2 . V_4 &&
F_223 ( V_58 , V_333 , V_61 -> V_2 . V_4 -> V_95 ) )
goto V_322;
#ifdef F_29
if ( V_61 -> V_2 . V_205 &&
F_223 ( V_58 , V_334 , V_61 -> V_2 . V_205 ) )
goto V_322;
#endif
if ( ! F_152 ( V_61 ) &&
V_78 -> V_94 != V_31 ) {
if ( F_224 ( V_58 , V_335 , V_78 -> V_94 ) )
goto V_322;
}
if ( V_61 -> V_125 &&
F_224 ( V_58 , V_336 , V_61 -> V_63 ) )
goto V_322;
V_120 = V_61 -> V_2 . V_120 ;
if ( V_120 ) {
unsigned long V_175 = V_144 ;
if ( F_70 ( V_175 , V_120 ) )
V_120 -= V_175 ;
else
V_120 = 0 ;
}
memcpy ( V_311 , F_225 ( & V_61 -> V_2 ) , sizeof( V_311 ) ) ;
if ( V_61 -> V_118 && V_120 )
V_311 [ V_191 - 1 ] = V_61 -> V_118 ;
if ( F_226 ( V_58 , V_311 ) < 0 )
goto V_322;
if ( V_78 -> V_203 &&
F_223 ( V_58 , V_337 , V_78 -> V_203 ) )
goto V_322;
error = V_61 -> V_2 . error ;
if ( F_152 ( V_61 ) ) {
#ifdef F_179
if ( F_81 ( V_2 ) && ! F_175 ( V_2 ) &&
F_227 ( V_40 , V_338 ) ) {
int V_235 = F_228 ( V_40 , V_58 ,
V_78 -> V_94 , V_78 -> V_59 ,
V_308 , V_306 ) ;
if ( V_235 <= 0 ) {
if ( ! V_306 ) {
if ( V_235 == 0 )
return 0 ;
goto V_322;
} else {
if ( V_235 == - V_313 )
goto V_322;
error = V_235 ;
}
}
} else
#endif
if ( F_223 ( V_58 , V_339 , V_61 -> V_246 ) )
goto V_322;
}
if ( F_229 ( V_58 , & V_61 -> V_2 , 0 , V_120 , error ) < 0 )
goto V_322;
return F_230 ( V_58 , V_310 ) ;
V_322:
F_231 ( V_58 , V_310 ) ;
return - V_313 ;
}
static int F_232 ( struct V_57 * V_340 , struct V_309 * V_310 )
{
struct V_40 * V_40 = F_119 ( V_340 -> V_80 ) ;
struct V_307 * V_341 ;
struct V_342 * V_343 [ V_344 + 1 ] ;
struct V_53 * V_61 = NULL ;
struct V_77 V_78 ;
T_6 V_2 = 0 ;
T_6 V_31 = 0 ;
T_1 V_345 ;
int V_235 ;
int V_84 ;
struct V_57 * V_58 ;
V_235 = F_233 ( V_310 , sizeof( * V_341 ) , V_343 , V_344 , V_346 ) ;
if ( V_235 < 0 )
goto V_347;
V_341 = F_222 ( V_310 ) ;
V_58 = F_234 ( V_348 , V_34 ) ;
if ( V_58 == NULL ) {
V_235 = - V_251 ;
goto V_347;
}
F_235 ( V_58 ) ;
F_236 ( V_58 ) ;
F_40 ( V_58 ) -> V_96 = V_349 ;
F_237 ( V_58 , V_350 + sizeof( struct V_66 ) ) ;
V_31 = V_343 [ V_332 ] ? F_238 ( V_343 [ V_332 ] ) : 0 ;
V_2 = V_343 [ V_331 ] ? F_238 ( V_343 [ V_331 ] ) : 0 ;
V_345 = V_343 [ V_339 ] ? F_239 ( V_343 [ V_339 ] ) : 0 ;
V_84 = V_343 [ V_337 ] ? F_239 ( V_343 [ V_337 ] ) : 0 ;
memset ( & V_78 , 0 , sizeof( V_78 ) ) ;
V_78 . V_59 = V_2 ;
V_78 . V_94 = V_31 ;
V_78 . V_200 = V_341 -> V_318 ;
V_78 . V_201 = V_343 [ V_333 ] ? F_239 ( V_343 [ V_333 ] ) : 0 ;
V_78 . V_203 = V_84 ;
if ( V_345 ) {
struct V_3 * V_4 ;
V_4 = F_240 ( V_40 , V_345 ) ;
if ( V_4 == NULL ) {
V_235 = - V_291 ;
goto V_351;
}
V_58 -> V_96 = F_47 ( V_236 ) ;
V_58 -> V_4 = V_4 ;
V_58 -> V_84 = V_84 ;
F_241 () ;
V_235 = F_242 ( V_58 , V_2 , V_31 , V_341 -> V_318 , V_4 ) ;
F_243 () ;
V_61 = F_101 ( V_58 ) ;
if ( V_235 == 0 && V_61 -> V_2 . error )
V_235 = - V_61 -> V_2 . error ;
} else {
V_61 = F_244 ( V_40 , & V_78 ) ;
V_235 = 0 ;
if ( F_117 ( V_61 ) )
V_235 = F_245 ( V_61 ) ;
}
if ( V_235 )
goto V_351;
F_182 ( V_58 , & V_61 -> V_2 ) ;
if ( V_341 -> V_327 & V_330 )
V_61 -> V_123 |= V_329 ;
V_235 = F_220 ( V_40 , V_2 , V_31 , & V_78 , V_58 ,
F_246 ( V_340 ) . V_304 , V_310 -> V_352 ,
V_353 , 0 , 0 ) ;
if ( V_235 <= 0 )
goto V_351;
V_235 = F_247 ( V_58 , V_40 , F_246 ( V_340 ) . V_304 ) ;
V_347:
return V_235 ;
V_351:
F_111 ( V_58 ) ;
goto V_347;
}
int F_248 ( struct V_57 * V_58 , struct V_354 * V_355 )
{
return V_58 -> V_356 ;
}
void F_249 ( struct V_150 * V_151 )
{
F_37 ( F_36 ( V_151 -> V_4 ) ) ;
}
static int F_250 ( struct V_357 * V_358 , int V_359 ,
void T_11 * V_360 ,
T_12 * V_361 , T_2 * V_362 )
{
struct V_40 * V_40 = (struct V_40 * ) V_358 -> V_363 ;
if ( V_359 ) {
F_37 ( V_40 ) ;
F_251 ( V_40 ) ;
return 0 ;
}
return - V_182 ;
}
static T_3 int F_252 ( struct V_40 * V_40 )
{
struct V_357 * V_364 ;
V_364 = V_365 ;
if ( ! F_253 ( V_40 , & V_366 ) ) {
V_364 = F_254 ( V_364 , sizeof( V_365 ) , V_34 ) ;
if ( V_364 == NULL )
goto V_367;
if ( V_40 -> V_368 != & V_369 )
V_364 [ 0 ] . V_370 = NULL ;
}
V_364 [ 0 ] . V_363 = V_40 ;
V_40 -> V_75 . V_371 = F_255 ( V_40 , L_19 , V_364 ) ;
if ( V_40 -> V_75 . V_371 == NULL )
goto V_372;
return 0 ;
V_372:
if ( V_364 != V_365 )
F_24 ( V_364 ) ;
V_367:
return - V_35 ;
}
static T_4 void F_256 ( struct V_40 * V_40 )
{
struct V_357 * V_364 ;
V_364 = V_40 -> V_75 . V_371 -> V_373 ;
F_257 ( V_40 -> V_75 . V_371 ) ;
F_258 ( V_364 == V_365 ) ;
F_24 ( V_364 ) ;
}
static T_3 int F_259 ( struct V_40 * V_40 )
{
F_260 ( & V_40 -> V_75 . V_55 , 0 ) ;
F_260 ( & V_40 -> V_137 , 0 ) ;
F_261 ( & V_40 -> V_75 . V_374 ,
sizeof( V_40 -> V_75 . V_374 ) ) ;
return 0 ;
}
static int T_3 F_262 ( struct V_40 * V_40 )
{
struct V_375 * V_376 = F_263 ( sizeof( * V_376 ) , V_34 ) ;
if ( ! V_376 )
return - V_35 ;
F_264 ( V_376 ) ;
V_40 -> V_75 . V_76 = V_376 ;
return 0 ;
}
static void T_4 F_265 ( struct V_40 * V_40 )
{
struct V_375 * V_376 = V_40 -> V_75 . V_76 ;
V_40 -> V_75 . V_76 = NULL ;
F_266 ( V_376 ) ;
F_24 ( V_376 ) ;
}
int T_5 F_267 ( void )
{
int V_377 = 0 ;
#ifdef F_29
V_30 = F_268 ( 256 * sizeof( struct V_30 ) , F_269 ( struct V_30 ) ) ;
if ( ! V_30 )
F_270 ( L_20 ) ;
#endif
V_19 . V_378 =
F_271 ( L_21 , sizeof( struct V_53 ) , 0 ,
V_379 | V_380 , NULL ) ;
V_299 . V_378 = V_19 . V_378 ;
if ( F_272 ( & V_19 ) < 0 )
F_270 ( L_22 ) ;
if ( F_272 ( & V_299 ) < 0 )
F_270 ( L_23 ) ;
V_19 . V_381 = ~ 0 ;
V_382 = V_383 ;
F_273 () ;
F_274 () ;
if ( F_32 () )
F_275 ( L_24 ) ;
#ifdef F_276
F_277 () ;
F_278 () ;
#endif
F_279 ( V_384 , V_385 , F_232 , NULL , NULL ) ;
#ifdef F_280
F_33 ( & V_386 ) ;
#endif
F_33 ( & V_387 ) ;
F_33 ( & V_388 ) ;
return V_377 ;
}
void T_5 F_281 ( void )
{
F_255 ( & V_366 , L_19 , V_389 ) ;
}
