static inline int
F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 ,
struct V_5 * V_6 )
{
int V_7 = 0 ;
struct V_8 * V_9 ;
V_9 = F_2 ( V_2 , V_10 | V_11 ) ;
if ( ! V_9 )
goto V_12;
if ( F_3 ( V_2 , V_13 , V_4 -> V_14 . V_15 ) )
goto V_12;
if ( F_4 ( V_6 -> V_16 ) )
V_7 = V_6 -> V_16 ( V_2 , V_4 ) ;
F_5 ( V_2 , V_9 ) ;
return V_7 ;
V_12:
return - 1 ;
}
static inline int
F_6 ( struct V_1 * V_2 ,
const struct V_3 * V_4 ,
struct V_17 * V_18 )
{
int V_7 = 0 ;
struct V_8 * V_9 ;
V_9 = F_2 ( V_2 , V_19 | V_11 ) ;
if ( ! V_9 )
goto V_12;
if ( F_4 ( V_18 -> V_16 ) )
V_7 = V_18 -> V_16 ( V_2 , V_4 ) ;
F_5 ( V_2 , V_9 ) ;
return V_7 ;
V_12:
return - 1 ;
}
static int
F_7 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
int V_7 ;
struct V_17 * V_18 ;
struct V_5 * V_6 ;
F_8 () ;
V_18 = F_9 ( V_4 -> V_20 . V_21 ) ;
V_7 = F_6 ( V_2 , V_4 , V_18 ) ;
if ( V_7 >= 0 ) {
V_6 = F_10 ( V_4 -> V_20 . V_21 ,
V_4 -> V_14 . V_15 ) ;
V_7 = F_1 ( V_2 , V_4 , V_6 ) ;
}
F_11 () ;
return V_7 ;
}
static inline int
F_12 ( struct V_1 * V_2 , int V_22 ,
const struct V_23 * V_24 , int V_25 )
{
if ( V_24 -> V_26 == V_27 || V_24 -> V_25 != V_25 )
return 0 ;
if ( F_13 ( V_2 , V_22 , F_14 ( V_24 -> V_26 ) ) )
goto V_12;
return 0 ;
V_12:
return - 1 ;
}
static inline int
F_15 ( struct V_1 * V_2 , const struct V_28 * V_29 )
{
if ( F_16 ( V_2 , V_30 , F_17 ( V_29 -> V_31 ) ) )
goto V_12;
return 0 ;
V_12:
return - 1 ;
}
static inline int
F_18 ( struct V_1 * V_2 , const struct V_28 * V_29 )
{
long V_32 = ( ( long ) V_29 -> V_32 . V_33 - ( long ) V_34 ) / V_35 ;
if ( V_32 < 0 )
V_32 = 0 ;
if ( F_16 ( V_2 , V_36 , F_17 ( V_32 ) ) )
goto V_12;
return 0 ;
V_12:
return - 1 ;
}
static inline int
F_19 ( struct V_1 * V_2 , struct V_28 * V_29 )
{
struct V_5 * V_6 ;
struct V_8 * V_37 ;
int V_7 ;
V_6 = F_10 ( F_20 ( V_29 ) , F_21 ( V_29 ) ) ;
if ( ! V_6 -> V_38 )
return 0 ;
V_37 = F_2 ( V_2 , V_39 | V_11 ) ;
if ( ! V_37 )
goto V_12;
V_7 = V_6 -> V_38 ( V_2 , V_37 , V_29 ) ;
F_5 ( V_2 , V_37 ) ;
return V_7 ;
V_12:
return - 1 ;
}
static inline int
F_22 ( struct V_1 * V_2 , const struct V_28 * V_29 )
{
struct V_8 * V_40 ;
const struct V_41 * V_42 = F_23 ( V_29 ) ;
struct V_43 * V_44 ;
if ( ! V_42 )
return 0 ;
V_44 = F_24 ( V_42 -> V_44 ) ;
if ( ! V_44 )
goto V_45;
V_40 = F_2 ( V_2 , V_46 | V_11 ) ;
if ( ! V_40 )
goto V_12;
if ( F_25 ( V_2 , V_47 , V_44 -> V_48 ) )
goto V_12;
if ( V_44 -> V_38 )
V_44 -> V_38 ( V_2 , V_29 ) ;
F_5 ( V_2 , V_40 ) ;
V_45:
return 0 ;
V_12:
return - 1 ;
}
static int
F_26 ( struct V_1 * V_2 , struct V_49 * V_50 ,
enum V_51 V_25 , int type )
{
enum V_52 V_53 = V_25 ? V_54 : V_55 ;
struct V_56 * V_57 = V_50 -> V_57 ;
struct V_8 * V_58 ;
T_1 V_59 , V_60 ;
if ( type == V_61 ) {
V_59 = F_27 ( & V_57 [ V_25 ] . V_62 , 0 ) ;
V_60 = F_27 ( & V_57 [ V_25 ] . V_60 , 0 ) ;
} else {
V_59 = F_28 ( & V_57 [ V_25 ] . V_62 ) ;
V_60 = F_28 ( & V_57 [ V_25 ] . V_60 ) ;
}
V_58 = F_2 ( V_2 , V_53 | V_11 ) ;
if ( ! V_58 )
goto V_12;
if ( F_29 ( V_2 , V_63 , F_30 ( V_59 ) ) ||
F_29 ( V_2 , V_64 , F_30 ( V_60 ) ) )
goto V_12;
F_5 ( V_2 , V_58 ) ;
return 0 ;
V_12:
return - 1 ;
}
static int
F_31 ( struct V_1 * V_2 , const struct V_28 * V_29 , int type )
{
struct V_49 * V_50 = F_32 ( V_29 ) ;
if ( ! V_50 )
return 0 ;
if ( F_26 ( V_2 , V_50 , V_65 , type ) < 0 )
return - 1 ;
if ( F_26 ( V_2 , V_50 , V_66 , type ) < 0 )
return - 1 ;
return 0 ;
}
static int
F_33 ( struct V_1 * V_2 , const struct V_28 * V_29 )
{
struct V_8 * V_58 ;
const struct V_67 * V_68 ;
V_68 = F_34 ( V_29 ) ;
if ( ! V_68 )
return 0 ;
V_58 = F_2 ( V_2 , V_69 | V_11 ) ;
if ( ! V_58 )
goto V_12;
if ( F_29 ( V_2 , V_70 , F_30 ( V_68 -> V_71 ) ) ||
( V_68 -> V_72 != 0 && F_29 ( V_2 , V_73 ,
F_30 ( V_68 -> V_72 ) ) ) )
goto V_12;
F_5 ( V_2 , V_58 ) ;
return 0 ;
V_12:
return - 1 ;
}
static inline int
F_35 ( struct V_1 * V_2 , const struct V_28 * V_29 )
{
if ( F_16 ( V_2 , V_74 , F_17 ( V_29 -> V_75 ) ) )
goto V_12;
return 0 ;
V_12:
return - 1 ;
}
static inline int
F_36 ( struct V_1 * V_2 , const struct V_28 * V_29 )
{
struct V_8 * V_76 ;
int V_77 , V_7 ;
char * V_78 ;
V_7 = F_37 ( V_29 -> V_79 , & V_78 , & V_77 ) ;
if ( V_7 )
return 0 ;
V_7 = - 1 ;
V_76 = F_2 ( V_2 , V_80 | V_11 ) ;
if ( ! V_76 )
goto V_12;
if ( F_25 ( V_2 , V_81 , V_78 ) )
goto V_12;
F_5 ( V_2 , V_76 ) ;
V_7 = 0 ;
V_12:
F_38 ( V_78 , V_77 ) ;
return V_7 ;
}
static int F_39 ( const struct V_28 * V_29 )
{
struct V_82 * V_83 = F_40 ( V_29 ) ;
if ( ! V_83 )
return 0 ;
return F_41 ( V_83 -> V_84 * sizeof( long ) ) ;
}
static int
F_42 ( struct V_1 * V_2 , const struct V_28 * V_29 )
{
struct V_82 * V_83 = F_40 ( V_29 ) ;
unsigned int V_77 , V_85 ;
if ( ! V_83 )
return 0 ;
V_77 = V_83 -> V_84 * sizeof( long ) ;
V_85 = 0 ;
do {
if ( V_83 -> V_86 [ V_85 ] != 0 )
return F_43 ( V_2 , V_87 , V_77 , V_83 -> V_86 ) ;
V_85 ++ ;
} while ( V_85 < V_83 -> V_84 );
return 0 ;
}
static inline int
F_44 ( struct V_1 * V_2 , const struct V_28 * V_29 )
{
struct V_8 * V_9 ;
if ( ! ( V_29 -> V_31 & V_88 ) )
return 0 ;
V_9 = F_2 ( V_2 , V_89 | V_11 ) ;
if ( ! V_9 )
goto V_12;
if ( F_7 ( V_2 , F_45 ( V_29 ) ) < 0 )
goto V_12;
F_5 ( V_2 , V_9 ) ;
return 0 ;
V_12:
return - 1 ;
}
static int
F_46 ( struct V_1 * V_2 , const struct V_90 * V_91 , int type )
{
struct V_8 * V_9 ;
V_9 = F_2 ( V_2 , type | V_11 ) ;
if ( ! V_9 )
goto V_12;
if ( F_16 ( V_2 , V_92 ,
F_17 ( V_91 -> V_93 ) ) ||
F_16 ( V_2 , V_94 ,
F_17 ( V_91 -> V_95 ) ) ||
F_16 ( V_2 , V_96 ,
F_17 ( V_91 -> V_97 ) ) )
goto V_12;
F_5 ( V_2 , V_9 ) ;
return 0 ;
V_12:
return - 1 ;
}
static inline int
F_47 ( struct V_1 * V_2 , const struct V_28 * V_29 )
{
struct V_98 * V_99 = F_48 ( V_29 ) ;
struct V_90 * V_91 ;
if ( ! ( V_29 -> V_31 & V_100 ) || ! V_99 )
return 0 ;
V_91 = & V_99 -> V_91 [ V_65 ] ;
if ( F_46 ( V_2 , V_91 , V_101 ) == - 1 )
return - 1 ;
V_91 = & V_99 -> V_91 [ V_66 ] ;
if ( F_46 ( V_2 , V_91 , V_102 ) == - 1 )
return - 1 ;
return 0 ;
}
static inline int
F_49 ( struct V_1 * V_2 , const struct V_28 * V_29 )
{
if ( F_16 ( V_2 , V_103 , F_17 ( ( unsigned long ) V_29 ) ) )
goto V_12;
return 0 ;
V_12:
return - 1 ;
}
static inline int
F_50 ( struct V_1 * V_2 , const struct V_28 * V_29 )
{
if ( F_16 ( V_2 , V_104 , F_17 ( F_51 ( & V_29 -> V_105 . V_106 ) ) ) )
goto V_12;
return 0 ;
V_12:
return - 1 ;
}
static int
F_52 ( struct V_1 * V_2 , T_2 V_107 , T_2 V_91 , T_2 type ,
struct V_28 * V_29 )
{
const struct V_23 * V_24 ;
struct V_108 * V_109 ;
struct V_110 * V_111 ;
struct V_8 * V_9 ;
unsigned int V_112 = V_107 ? V_113 : 0 , V_114 ;
V_114 = ( V_115 << 8 | V_116 ) ;
V_109 = F_53 ( V_2 , V_107 , V_91 , V_114 , sizeof( * V_111 ) , V_112 ) ;
if ( V_109 == NULL )
goto V_117;
V_111 = F_54 ( V_109 ) ;
V_111 -> V_118 = F_20 ( V_29 ) ;
V_111 -> V_119 = V_120 ;
V_111 -> V_121 = 0 ;
V_24 = F_55 ( V_29 ) ;
V_9 = F_2 ( V_2 , V_122 | V_11 ) ;
if ( ! V_9 )
goto V_12;
if ( F_7 ( V_2 , F_56 ( V_29 , V_65 ) ) < 0 )
goto V_12;
if ( F_12 ( V_2 , V_123 , V_24 ,
V_124 ) < 0 )
goto V_12;
F_5 ( V_2 , V_9 ) ;
V_9 = F_2 ( V_2 , V_125 | V_11 ) ;
if ( ! V_9 )
goto V_12;
if ( F_7 ( V_2 , F_56 ( V_29 , V_66 ) ) < 0 )
goto V_12;
if ( F_12 ( V_2 , V_123 , V_24 ,
V_126 ) < 0 )
goto V_12;
F_5 ( V_2 , V_9 ) ;
if ( F_12 ( V_2 , V_127 , V_24 ,
V_128 ) < 0 )
goto V_12;
if ( F_15 ( V_2 , V_29 ) < 0 ||
F_18 ( V_2 , V_29 ) < 0 ||
F_31 ( V_2 , V_29 , type ) < 0 ||
F_33 ( V_2 , V_29 ) < 0 ||
F_19 ( V_2 , V_29 ) < 0 ||
F_22 ( V_2 , V_29 ) < 0 ||
F_35 ( V_2 , V_29 ) < 0 ||
F_36 ( V_2 , V_29 ) < 0 ||
F_42 ( V_2 , V_29 ) < 0 ||
F_49 ( V_2 , V_29 ) < 0 ||
F_50 ( V_2 , V_29 ) < 0 ||
F_44 ( V_2 , V_29 ) < 0 ||
F_47 ( V_2 , V_29 ) < 0 )
goto V_12;
F_57 ( V_2 , V_109 ) ;
return V_2 -> V_77 ;
V_117:
V_12:
F_58 ( V_2 , V_109 ) ;
return - 1 ;
}
static inline T_3
F_59 ( const struct V_28 * V_29 )
{
struct V_17 * V_18 ;
struct V_5 * V_6 ;
T_3 V_77 = 0 ;
F_8 () ;
V_18 = F_9 ( F_20 ( V_29 ) ) ;
V_77 += V_18 -> V_129 ;
V_6 = F_10 ( F_20 ( V_29 ) , F_21 ( V_29 ) ) ;
V_77 += V_6 -> V_129 ;
F_11 () ;
return V_77 ;
}
static inline T_3
F_60 ( const struct V_28 * V_29 )
{
if ( ! F_61 ( V_29 , V_130 ) )
return 0 ;
return 2 * F_41 ( 0 )
+ 2 * F_41 ( sizeof( V_131 ) )
+ 2 * F_41 ( sizeof( V_131 ) )
;
}
static inline int
F_62 ( const struct V_28 * V_29 )
{
#ifdef F_63
int V_77 , V_7 ;
V_7 = F_37 ( V_29 -> V_79 , NULL , & V_77 ) ;
if ( V_7 )
return 0 ;
return F_41 ( 0 )
+ F_41 ( sizeof( char ) * V_77 ) ;
#else
return 0 ;
#endif
}
static inline T_3
F_64 ( const struct V_28 * V_29 )
{
#ifdef F_65
if ( ! F_61 ( V_29 , V_132 ) )
return 0 ;
return F_41 ( 0 ) + 2 * F_41 ( sizeof( V_131 ) ) ;
#else
return 0 ;
#endif
}
static inline T_3
F_66 ( const struct V_28 * V_29 )
{
return F_67 ( sizeof( struct V_110 ) )
+ 3 * F_41 ( 0 )
+ 3 * F_41 ( 0 )
+ 3 * F_41 ( 0 )
+ 3 * F_41 ( sizeof( V_133 ) )
+ F_41 ( sizeof( V_134 ) )
+ F_41 ( sizeof( V_134 ) )
+ F_60 ( V_29 )
+ F_64 ( V_29 )
+ F_41 ( sizeof( V_134 ) )
+ F_41 ( 0 )
+ F_41 ( 0 )
+ F_41 ( V_135 )
+ F_62 ( V_29 )
#ifdef F_68
+ 2 * F_41 ( 0 )
+ 6 * F_41 ( sizeof( V_134 ) )
#endif
#ifdef F_69
+ F_41 ( sizeof( V_134 ) )
#endif
#ifdef F_70
+ F_41 ( sizeof( V_136 ) )
#endif
+ F_59 ( V_29 )
+ F_39 ( V_29 )
;
}
static int
F_71 ( unsigned int V_137 , struct V_138 * V_139 )
{
const struct V_23 * V_24 ;
struct V_140 * V_140 ;
struct V_108 * V_109 ;
struct V_110 * V_111 ;
struct V_8 * V_9 ;
struct V_28 * V_29 = V_139 -> V_29 ;
struct V_1 * V_2 ;
unsigned int type ;
unsigned int V_112 = 0 , V_141 ;
int V_142 ;
if ( F_72 ( V_29 ) )
return 0 ;
if ( V_137 & ( 1 << V_143 ) ) {
type = V_144 ;
V_141 = V_145 ;
} else if ( V_137 & ( ( 1 << V_146 ) | ( 1 << V_147 ) ) ) {
type = V_116 ;
V_112 = V_148 | V_149 ;
V_141 = V_150 ;
} else if ( V_137 ) {
type = V_116 ;
V_141 = V_151 ;
} else
return 0 ;
V_140 = F_73 ( V_29 ) ;
if ( ! V_139 -> V_152 && ! F_74 ( V_140 , V_141 ) )
return 0 ;
V_2 = F_75 ( F_66 ( V_29 ) , V_153 ) ;
if ( V_2 == NULL )
goto V_154;
type |= V_115 << 8 ;
V_109 = F_53 ( V_2 , V_139 -> V_107 , 0 , type , sizeof( * V_111 ) , V_112 ) ;
if ( V_109 == NULL )
goto V_117;
V_111 = F_54 ( V_109 ) ;
V_111 -> V_118 = F_20 ( V_29 ) ;
V_111 -> V_119 = V_120 ;
V_111 -> V_121 = 0 ;
F_8 () ;
V_24 = F_55 ( V_29 ) ;
V_9 = F_2 ( V_2 , V_122 | V_11 ) ;
if ( ! V_9 )
goto V_12;
if ( F_7 ( V_2 , F_56 ( V_29 , V_65 ) ) < 0 )
goto V_12;
if ( F_12 ( V_2 , V_123 , V_24 ,
V_124 ) < 0 )
goto V_12;
F_5 ( V_2 , V_9 ) ;
V_9 = F_2 ( V_2 , V_125 | V_11 ) ;
if ( ! V_9 )
goto V_12;
if ( F_7 ( V_2 , F_56 ( V_29 , V_66 ) ) < 0 )
goto V_12;
if ( F_12 ( V_2 , V_123 , V_24 ,
V_126 ) < 0 )
goto V_12;
F_5 ( V_2 , V_9 ) ;
if ( F_12 ( V_2 , V_127 , V_24 ,
V_128 ) < 0 )
goto V_12;
if ( F_49 ( V_2 , V_29 ) < 0 )
goto V_12;
if ( F_15 ( V_2 , V_29 ) < 0 )
goto V_12;
if ( V_137 & ( 1 << V_143 ) ) {
if ( F_31 ( V_2 , V_29 , type ) < 0 ||
F_33 ( V_2 , V_29 ) < 0 )
goto V_12;
} else {
if ( F_18 ( V_2 , V_29 ) < 0 )
goto V_12;
if ( V_137 & ( 1 << V_155 )
&& F_19 ( V_2 , V_29 ) < 0 )
goto V_12;
if ( ( V_137 & ( 1 << V_156 ) || F_23 ( V_29 ) )
&& F_22 ( V_2 , V_29 ) < 0 )
goto V_12;
#ifdef F_63
if ( ( V_137 & ( 1 << V_157 ) || V_29 -> V_79 )
&& F_36 ( V_2 , V_29 ) < 0 )
goto V_12;
#endif
if ( V_137 & ( 1 << V_158 ) &&
F_42 ( V_2 , V_29 ) < 0 )
goto V_12;
if ( V_137 & ( 1 << V_147 ) &&
F_44 ( V_2 , V_29 ) < 0 )
goto V_12;
if ( V_137 & ( 1 << V_159 ) &&
F_47 ( V_2 , V_29 ) < 0 )
goto V_12;
}
#ifdef F_69
if ( ( V_137 & ( 1 << V_160 ) || V_29 -> V_75 )
&& F_35 ( V_2 , V_29 ) < 0 )
goto V_12;
#endif
F_11 () ;
F_57 ( V_2 , V_109 ) ;
V_142 = F_76 ( V_2 , V_140 , V_139 -> V_107 , V_141 , V_139 -> V_152 ,
V_153 ) ;
if ( V_142 == - V_161 || V_142 == - V_162 )
return - V_161 ;
return 0 ;
V_12:
F_11 () ;
F_58 ( V_2 , V_109 ) ;
V_117:
F_77 ( V_2 ) ;
V_154:
if ( F_78 ( V_140 , 0 , V_141 , - V_161 ) > 0 )
return - V_161 ;
return 0 ;
}
static int F_79 ( struct V_163 * V_164 )
{
if ( V_164 -> args [ 1 ] )
F_80 ( (struct V_28 * ) V_164 -> args [ 1 ] ) ;
F_81 ( V_164 -> V_165 ) ;
return 0 ;
}
static struct V_166 *
F_82 ( const struct V_8 * const V_167 [] )
{
#ifdef F_69
struct V_166 * V_168 ;
V_168 = F_83 ( sizeof( * V_168 ) , V_169 ) ;
if ( V_168 == NULL )
return F_84 ( - V_170 ) ;
V_168 -> V_75 . V_171 = F_85 ( F_86 ( V_167 [ V_74 ] ) ) ;
V_168 -> V_75 . V_172 = F_85 ( F_86 ( V_167 [ V_173 ] ) ) ;
return V_168 ;
#else
return F_84 ( - V_174 ) ;
#endif
}
static int F_87 ( struct V_28 * V_29 , void * V_165 )
{
struct V_166 * V_168 = V_165 ;
if ( V_168 == NULL )
return 1 ;
#ifdef F_69
if ( ( V_29 -> V_75 & V_168 -> V_75 . V_172 ) == V_168 -> V_75 . V_171 )
return 1 ;
#endif
return 0 ;
}
static int
F_88 ( struct V_1 * V_2 , struct V_163 * V_164 )
{
struct V_140 * V_140 = F_89 ( V_2 -> V_175 ) ;
struct V_28 * V_29 , * V_176 ;
struct V_177 * V_178 ;
struct V_179 * V_180 ;
struct V_110 * V_111 = F_54 ( V_164 -> V_109 ) ;
V_133 V_18 = V_111 -> V_118 ;
int V_181 ;
T_4 * V_182 ;
V_176 = (struct V_28 * ) V_164 -> args [ 1 ] ;
F_90 () ;
for (; V_164 -> args [ 0 ] < V_140 -> V_29 . V_183 ; V_164 -> args [ 0 ] ++ ) {
V_184:
V_182 = & V_185 [ V_164 -> args [ 0 ] % V_186 ] ;
F_91 ( V_182 ) ;
if ( V_164 -> args [ 0 ] >= V_140 -> V_29 . V_183 ) {
F_92 ( V_182 ) ;
goto V_45;
}
F_93 (h, n, &net->ct.hash[cb->args[0]],
hnnode) {
if ( F_94 ( V_178 ) != V_65 )
continue;
V_29 = F_95 ( V_178 ) ;
if ( V_18 && F_20 ( V_29 ) != V_18 )
continue;
if ( V_164 -> args [ 1 ] ) {
if ( V_29 != V_176 )
continue;
V_164 -> args [ 1 ] = 0 ;
}
if ( ! F_87 ( V_29 , V_164 -> V_165 ) )
continue;
F_8 () ;
V_181 =
F_52 ( V_2 , F_96 ( V_164 -> V_2 ) . V_107 ,
V_164 -> V_109 -> V_187 ,
F_97 ( V_164 -> V_109 -> V_188 ) ,
V_29 ) ;
F_11 () ;
if ( V_181 < 0 ) {
F_98 ( & V_29 -> V_105 ) ;
V_164 -> args [ 1 ] = ( unsigned long ) V_29 ;
F_92 ( V_182 ) ;
goto V_45;
}
}
F_92 ( V_182 ) ;
if ( V_164 -> args [ 1 ] ) {
V_164 -> args [ 1 ] = 0 ;
goto V_184;
}
}
V_45:
F_99 () ;
if ( V_176 )
F_80 ( V_176 ) ;
return V_2 -> V_77 ;
}
static inline int
F_100 ( struct V_8 * V_53 , struct V_3 * V_4 )
{
struct V_8 * V_189 [ V_190 + 1 ] ;
struct V_17 * V_18 ;
int V_7 = 0 ;
V_7 = F_101 ( V_189 , V_190 , V_53 , NULL ) ;
if ( V_7 < 0 )
return V_7 ;
F_8 () ;
V_18 = F_9 ( V_4 -> V_20 . V_21 ) ;
if ( F_4 ( V_18 -> V_191 ) ) {
V_7 = F_102 ( V_53 , V_190 ,
V_18 -> V_192 ) ;
if ( V_7 == 0 )
V_7 = V_18 -> V_191 ( V_189 , V_4 ) ;
}
F_11 () ;
return V_7 ;
}
static inline int
F_103 ( struct V_8 * V_53 ,
struct V_3 * V_4 )
{
struct V_8 * V_189 [ V_193 + 1 ] ;
struct V_5 * V_6 ;
int V_7 = 0 ;
V_7 = F_101 ( V_189 , V_193 , V_53 , V_194 ) ;
if ( V_7 < 0 )
return V_7 ;
if ( ! V_189 [ V_13 ] )
return - V_195 ;
V_4 -> V_14 . V_15 = F_104 ( V_189 [ V_13 ] ) ;
F_8 () ;
V_6 = F_10 ( V_4 -> V_20 . V_21 , V_4 -> V_14 . V_15 ) ;
if ( F_4 ( V_6 -> V_191 ) ) {
V_7 = F_102 ( V_53 , V_193 ,
V_6 -> V_192 ) ;
if ( V_7 == 0 )
V_7 = V_6 -> V_191 ( V_189 , V_4 ) ;
}
F_11 () ;
return V_7 ;
}
static int
F_105 ( const struct V_8 * V_53 ,
struct V_23 * V_24 )
{
F_106 ( V_24 , V_27 ,
V_128 , 0 ) ;
#ifdef F_70
if ( V_53 )
V_24 -> V_26 = F_107 ( F_108 ( V_53 ) ) ;
#else
if ( V_53 )
return - V_174 ;
#endif
return 0 ;
}
static int
F_109 ( struct V_8 * V_53 , enum V_52 type ,
struct V_23 * V_24 )
{
int V_7 ;
if ( V_24 -> V_26 != V_27 )
return - V_195 ;
V_7 = F_105 ( V_53 , V_24 ) ;
if ( V_7 < 0 )
return V_7 ;
if ( type == V_125 )
V_24 -> V_25 = V_126 ;
else
V_24 -> V_25 = V_124 ;
return 0 ;
}
static int
F_110 ( const struct V_8 * const V_167 [] ,
struct V_3 * V_4 ,
enum V_52 type , V_133 V_21 ,
struct V_23 * V_24 )
{
struct V_8 * V_189 [ V_196 + 1 ] ;
int V_142 ;
memset ( V_4 , 0 , sizeof( * V_4 ) ) ;
V_142 = F_101 ( V_189 , V_196 , V_167 [ type ] , V_197 ) ;
if ( V_142 < 0 )
return V_142 ;
if ( ! V_189 [ V_19 ] )
return - V_195 ;
V_4 -> V_20 . V_21 = V_21 ;
V_142 = F_100 ( V_189 [ V_19 ] , V_4 ) ;
if ( V_142 < 0 )
return V_142 ;
if ( ! V_189 [ V_10 ] )
return - V_195 ;
V_142 = F_103 ( V_189 [ V_10 ] , V_4 ) ;
if ( V_142 < 0 )
return V_142 ;
if ( V_189 [ V_123 ] ) {
if ( ! V_24 )
return - V_195 ;
V_142 = F_109 ( V_189 [ V_123 ] ,
type , V_24 ) ;
if ( V_142 < 0 )
return V_142 ;
}
if ( type == V_125 )
V_4 -> V_14 . V_25 = V_66 ;
else
V_4 -> V_14 . V_25 = V_65 ;
return 0 ;
}
static inline int
F_111 ( const struct V_8 * V_53 , char * * V_198 ,
struct V_8 * * V_199 )
{
int V_142 ;
struct V_8 * V_189 [ V_200 + 1 ] ;
V_142 = F_101 ( V_189 , V_200 , V_53 , V_201 ) ;
if ( V_142 < 0 )
return V_142 ;
if ( ! V_189 [ V_47 ] )
return - V_195 ;
* V_198 = F_112 ( V_189 [ V_47 ] ) ;
if ( V_189 [ V_202 ] )
* V_199 = V_189 [ V_202 ] ;
return 0 ;
}
static int F_113 ( struct V_140 * V_140 ,
const struct V_8 * const V_167 [] ,
T_2 V_107 , int V_152 )
{
struct V_166 * V_168 = NULL ;
if ( V_167 [ V_74 ] && V_167 [ V_173 ] ) {
V_168 = F_82 ( V_167 ) ;
if ( F_114 ( V_168 ) )
return F_115 ( V_168 ) ;
}
F_116 ( V_140 , F_87 , V_168 ,
V_107 , V_152 ) ;
F_81 ( V_168 ) ;
return 0 ;
}
static int
F_117 ( struct V_203 * V_204 , struct V_1 * V_2 ,
const struct V_108 * V_109 ,
const struct V_8 * const V_167 [] )
{
struct V_140 * V_140 = F_89 ( V_204 ) ;
struct V_177 * V_178 ;
struct V_3 V_4 ;
struct V_28 * V_29 ;
struct V_110 * V_111 = F_54 ( V_109 ) ;
V_133 V_205 = V_111 -> V_118 ;
struct V_23 V_24 ;
int V_142 ;
V_142 = F_105 ( V_167 [ V_127 ] , & V_24 ) ;
if ( V_142 < 0 )
return V_142 ;
if ( V_167 [ V_122 ] )
V_142 = F_110 ( V_167 , & V_4 , V_122 ,
V_205 , & V_24 ) ;
else if ( V_167 [ V_125 ] )
V_142 = F_110 ( V_167 , & V_4 , V_125 ,
V_205 , & V_24 ) ;
else {
return F_113 ( V_140 , V_167 ,
F_96 ( V_2 ) . V_107 ,
F_118 ( V_109 ) ) ;
}
if ( V_142 < 0 )
return V_142 ;
V_178 = F_119 ( V_140 , & V_24 , & V_4 ) ;
if ( ! V_178 )
return - V_206 ;
V_29 = F_95 ( V_178 ) ;
if ( V_167 [ V_103 ] ) {
V_134 V_26 = F_85 ( F_86 ( V_167 [ V_103 ] ) ) ;
if ( V_26 != ( T_2 ) ( unsigned long ) V_29 ) {
F_80 ( V_29 ) ;
return - V_206 ;
}
}
if ( F_120 ( & V_29 -> V_32 ) )
F_121 ( V_29 , F_96 ( V_2 ) . V_107 , F_118 ( V_109 ) ) ;
F_80 ( V_29 ) ;
return 0 ;
}
static int
F_122 ( struct V_203 * V_204 , struct V_1 * V_2 ,
const struct V_108 * V_109 ,
const struct V_8 * const V_167 [] )
{
struct V_140 * V_140 = F_89 ( V_204 ) ;
struct V_177 * V_178 ;
struct V_3 V_4 ;
struct V_28 * V_29 ;
struct V_1 * V_207 = NULL ;
struct V_110 * V_111 = F_54 ( V_109 ) ;
V_133 V_205 = V_111 -> V_118 ;
struct V_23 V_24 ;
int V_142 ;
if ( V_109 -> V_208 & V_209 ) {
struct V_210 V_211 = {
. V_212 = F_88 ,
. V_213 = F_79 ,
} ;
if ( V_167 [ V_74 ] && V_167 [ V_173 ] ) {
struct V_166 * V_168 ;
V_168 = F_82 ( V_167 ) ;
if ( F_114 ( V_168 ) )
return F_115 ( V_168 ) ;
V_211 . V_165 = V_168 ;
}
return F_123 ( V_204 , V_2 , V_109 , & V_211 ) ;
}
V_142 = F_105 ( V_167 [ V_127 ] , & V_24 ) ;
if ( V_142 < 0 )
return V_142 ;
if ( V_167 [ V_122 ] )
V_142 = F_110 ( V_167 , & V_4 , V_122 ,
V_205 , & V_24 ) ;
else if ( V_167 [ V_125 ] )
V_142 = F_110 ( V_167 , & V_4 , V_125 ,
V_205 , & V_24 ) ;
else
return - V_195 ;
if ( V_142 < 0 )
return V_142 ;
V_178 = F_119 ( V_140 , & V_24 , & V_4 ) ;
if ( ! V_178 )
return - V_206 ;
V_29 = F_95 ( V_178 ) ;
V_142 = - V_170 ;
V_207 = F_75 ( V_214 , V_169 ) ;
if ( V_207 == NULL ) {
F_80 ( V_29 ) ;
return - V_170 ;
}
F_8 () ;
V_142 = F_52 ( V_207 , F_96 ( V_2 ) . V_107 , V_109 -> V_187 ,
F_97 ( V_109 -> V_188 ) , V_29 ) ;
F_11 () ;
F_80 ( V_29 ) ;
if ( V_142 <= 0 )
goto free;
V_142 = F_124 ( V_204 , V_207 , F_96 ( V_2 ) . V_107 , V_215 ) ;
if ( V_142 < 0 )
goto V_45;
return 0 ;
free:
F_77 ( V_207 ) ;
V_45:
return V_142 == - V_162 ? - V_161 : V_142 ;
}
static int F_125 ( struct V_163 * V_164 )
{
if ( V_164 -> args [ 1 ] )
F_80 ( (struct V_28 * ) V_164 -> args [ 1 ] ) ;
return 0 ;
}
static int
F_126 ( struct V_1 * V_2 , struct V_163 * V_164 , bool V_216 )
{
struct V_28 * V_29 , * V_176 ;
struct V_177 * V_178 ;
struct V_179 * V_180 ;
struct V_110 * V_111 = F_54 ( V_164 -> V_109 ) ;
V_133 V_18 = V_111 -> V_118 ;
int V_181 ;
int V_217 ;
struct V_218 * V_219 ;
struct V_140 * V_140 = F_89 ( V_2 -> V_175 ) ;
if ( V_164 -> args [ 2 ] )
return 0 ;
V_176 = (struct V_28 * ) V_164 -> args [ 1 ] ;
for ( V_217 = V_164 -> args [ 0 ] ; V_217 < V_220 ; V_217 ++ ) {
struct V_221 * V_222 ;
if ( ! F_127 ( V_217 ) )
continue;
V_222 = F_128 ( V_140 -> V_29 . V_223 , V_217 ) ;
F_129 ( & V_222 -> V_224 ) ;
V_219 = V_216 ? & V_222 -> V_216 : & V_222 -> V_225 ;
V_184:
F_93 (h, n, list, hnnode) {
V_29 = F_95 ( V_178 ) ;
if ( V_18 && F_20 ( V_29 ) != V_18 )
continue;
if ( V_164 -> args [ 1 ] ) {
if ( V_29 != V_176 )
continue;
V_164 -> args [ 1 ] = 0 ;
}
F_8 () ;
V_181 = F_52 ( V_2 , F_96 ( V_164 -> V_2 ) . V_107 ,
V_164 -> V_109 -> V_187 ,
F_97 ( V_164 -> V_109 -> V_188 ) ,
V_29 ) ;
F_11 () ;
if ( V_181 < 0 ) {
if ( ! F_130 ( & V_29 -> V_105 . V_106 ) )
continue;
V_164 -> args [ 0 ] = V_217 ;
V_164 -> args [ 1 ] = ( unsigned long ) V_29 ;
F_131 ( & V_222 -> V_224 ) ;
goto V_45;
}
}
if ( V_164 -> args [ 1 ] ) {
V_164 -> args [ 1 ] = 0 ;
goto V_184;
}
F_131 ( & V_222 -> V_224 ) ;
}
V_164 -> args [ 2 ] = 1 ;
V_45:
if ( V_176 )
F_80 ( V_176 ) ;
return V_2 -> V_77 ;
}
static int
F_132 ( struct V_1 * V_2 , struct V_163 * V_164 )
{
return F_126 ( V_2 , V_164 , true ) ;
}
static int
F_133 ( struct V_203 * V_204 , struct V_1 * V_2 ,
const struct V_108 * V_109 ,
const struct V_8 * const V_167 [] )
{
if ( V_109 -> V_208 & V_209 ) {
struct V_210 V_211 = {
. V_212 = F_132 ,
. V_213 = F_125 ,
} ;
return F_123 ( V_204 , V_2 , V_109 , & V_211 ) ;
}
return - V_174 ;
}
static int
F_134 ( struct V_1 * V_2 , struct V_163 * V_164 )
{
return F_126 ( V_2 , V_164 , false ) ;
}
static int
F_135 ( struct V_203 * V_204 , struct V_1 * V_2 ,
const struct V_108 * V_109 ,
const struct V_8 * const V_167 [] )
{
if ( V_109 -> V_208 & V_209 ) {
struct V_210 V_211 = {
. V_212 = F_134 ,
. V_213 = F_125 ,
} ;
return F_123 ( V_204 , V_2 , V_109 , & V_211 ) ;
}
return - V_174 ;
}
static int
F_136 ( struct V_28 * V_29 ,
enum V_226 V_227 ,
const struct V_8 * V_53 )
{
F_137 (nfnetlink_parse_nat_setup_hook) V_228 ;
int V_142 ;
V_228 = F_24 ( V_229 ) ;
if ( ! V_228 ) {
#ifdef F_138
F_11 () ;
F_139 ( V_115 ) ;
if ( F_140 ( L_1 ) < 0 ) {
F_141 ( V_115 ) ;
F_8 () ;
return - V_174 ;
}
F_141 ( V_115 ) ;
F_8 () ;
if ( V_229 )
return - V_162 ;
#endif
return - V_174 ;
}
V_142 = V_228 ( V_29 , V_227 , V_53 ) ;
if ( V_142 == - V_162 ) {
#ifdef F_138
F_11 () ;
F_139 ( V_115 ) ;
if ( F_140 ( L_2 , F_20 ( V_29 ) ) < 0 ) {
F_141 ( V_115 ) ;
F_8 () ;
return - V_174 ;
}
F_141 ( V_115 ) ;
F_8 () ;
#else
V_142 = - V_174 ;
#endif
}
return V_142 ;
}
static int
F_142 ( struct V_28 * V_29 , const struct V_8 * const V_167 [] )
{
unsigned long V_230 ;
unsigned int V_31 = F_85 ( F_86 ( V_167 [ V_30 ] ) ) ;
V_230 = V_29 -> V_31 ^ V_31 ;
if ( V_230 & ( V_88 | V_231 | V_232 ) )
return - V_233 ;
if ( V_230 & V_234 && ! ( V_31 & V_234 ) )
return - V_233 ;
if ( V_230 & V_235 && ! ( V_31 & V_235 ) )
return - V_233 ;
V_29 -> V_31 |= V_31 & ~ ( V_236 | V_237 ) ;
return 0 ;
}
static int
F_143 ( struct V_28 * V_29 , const struct V_8 * const V_167 [] )
{
#ifdef F_68
int V_7 ;
if ( ! V_167 [ V_238 ] && ! V_167 [ V_239 ] )
return 0 ;
V_7 = F_136 ( V_29 , V_240 ,
V_167 [ V_238 ] ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_136 ( V_29 , V_241 ,
V_167 [ V_239 ] ) ;
return V_7 ;
#else
if ( ! V_167 [ V_238 ] && ! V_167 [ V_239 ] )
return 0 ;
return - V_174 ;
#endif
}
static inline int
F_144 ( struct V_28 * V_29 , const struct V_8 * const V_167 [] )
{
struct V_43 * V_44 ;
struct V_41 * V_42 = F_23 ( V_29 ) ;
char * V_242 = NULL ;
struct V_8 * V_199 = NULL ;
int V_142 ;
if ( V_29 -> V_243 )
return - V_233 ;
V_142 = F_111 ( V_167 [ V_46 ] , & V_242 , & V_199 ) ;
if ( V_142 < 0 )
return V_142 ;
if ( ! strcmp ( V_242 , L_3 ) ) {
if ( V_42 && V_42 -> V_44 ) {
F_145 ( V_29 ) ;
F_146 ( V_42 -> V_44 , NULL ) ;
}
return 0 ;
}
V_44 = F_147 ( V_242 , F_20 ( V_29 ) ,
F_21 ( V_29 ) ) ;
if ( V_44 == NULL ) {
#ifdef F_138
F_131 ( & V_244 ) ;
if ( F_140 ( L_4 , V_242 ) < 0 ) {
F_129 ( & V_244 ) ;
return - V_174 ;
}
F_129 ( & V_244 ) ;
V_44 = F_147 ( V_242 , F_20 ( V_29 ) ,
F_21 ( V_29 ) ) ;
if ( V_44 )
return - V_162 ;
#endif
return - V_174 ;
}
if ( V_42 ) {
if ( V_42 -> V_44 == V_44 ) {
if ( V_44 -> V_245 )
V_44 -> V_245 ( V_199 , V_29 ) ;
return 0 ;
} else
return - V_233 ;
}
return - V_174 ;
}
static inline int
F_148 ( struct V_28 * V_29 , const struct V_8 * const V_167 [] )
{
V_134 V_32 = F_85 ( F_86 ( V_167 [ V_36 ] ) ) ;
if ( ! F_120 ( & V_29 -> V_32 ) )
return - V_246 ;
V_29 -> V_32 . V_33 = V_34 + V_32 * V_35 ;
F_149 ( & V_29 -> V_32 ) ;
return 0 ;
}
static inline int
F_150 ( struct V_28 * V_29 , const struct V_8 * const V_167 [] )
{
const struct V_8 * V_53 = V_167 [ V_39 ] ;
struct V_8 * V_189 [ V_247 + 1 ] ;
struct V_5 * V_6 ;
int V_142 = 0 ;
V_142 = F_101 ( V_189 , V_247 , V_53 , V_248 ) ;
if ( V_142 < 0 )
return V_142 ;
F_8 () ;
V_6 = F_10 ( F_20 ( V_29 ) , F_21 ( V_29 ) ) ;
if ( V_6 -> V_245 )
V_142 = V_6 -> V_245 ( V_189 , V_29 ) ;
F_11 () ;
return V_142 ;
}
static inline int
F_151 ( struct V_90 * V_91 , const struct V_8 * const V_53 )
{
int V_142 ;
struct V_8 * V_167 [ V_249 + 1 ] ;
V_142 = F_101 ( V_167 , V_249 , V_53 , V_250 ) ;
if ( V_142 < 0 )
return V_142 ;
if ( ! V_167 [ V_92 ] )
return - V_195 ;
V_91 -> V_93 =
F_85 ( F_86 ( V_167 [ V_92 ] ) ) ;
if ( ! V_167 [ V_94 ] )
return - V_195 ;
V_91 -> V_95 =
F_85 ( F_86 ( V_167 [ V_94 ] ) ) ;
if ( ! V_167 [ V_96 ] )
return - V_195 ;
V_91 -> V_97 =
F_85 ( F_86 ( V_167 [ V_96 ] ) ) ;
return 0 ;
}
static int
F_152 ( struct V_28 * V_29 ,
const struct V_8 * const V_167 [] )
{
struct V_98 * V_99 = F_48 ( V_29 ) ;
int V_7 = 0 ;
if ( ! V_99 )
return 0 ;
if ( V_167 [ V_101 ] ) {
V_7 = F_151 ( & V_99 -> V_91 [ V_65 ] ,
V_167 [ V_101 ] ) ;
if ( V_7 < 0 )
return V_7 ;
V_29 -> V_31 |= V_100 ;
}
if ( V_167 [ V_102 ] ) {
V_7 = F_151 ( & V_99 -> V_91 [ V_66 ] ,
V_167 [ V_102 ] ) ;
if ( V_7 < 0 )
return V_7 ;
V_29 -> V_31 |= V_100 ;
}
return 0 ;
}
static int
F_153 ( struct V_28 * V_29 , const struct V_8 * const V_167 [] )
{
#ifdef F_154
T_3 V_77 = F_155 ( V_167 [ V_87 ] ) ;
const void * V_172 = V_167 [ V_251 ] ;
if ( V_77 & ( sizeof( T_2 ) - 1 ) )
return - V_195 ;
if ( V_172 ) {
if ( F_155 ( V_167 [ V_251 ] ) == 0 ||
F_155 ( V_167 [ V_251 ] ) != V_77 )
return - V_195 ;
V_172 = F_112 ( V_167 [ V_251 ] ) ;
}
V_77 /= sizeof( T_2 ) ;
return F_156 ( V_29 , F_112 ( V_167 [ V_87 ] ) , V_172 , V_77 ) ;
#else
return - V_174 ;
#endif
}
static int
F_157 ( struct V_28 * V_29 ,
const struct V_8 * const V_167 [] )
{
int V_142 ;
if ( V_167 [ V_239 ] || V_167 [ V_238 ] || V_167 [ V_89 ] )
return - V_174 ;
if ( V_167 [ V_46 ] ) {
V_142 = F_144 ( V_29 , V_167 ) ;
if ( V_142 < 0 )
return V_142 ;
}
if ( V_167 [ V_36 ] ) {
V_142 = F_148 ( V_29 , V_167 ) ;
if ( V_142 < 0 )
return V_142 ;
}
if ( V_167 [ V_30 ] ) {
V_142 = F_142 ( V_29 , V_167 ) ;
if ( V_142 < 0 )
return V_142 ;
}
if ( V_167 [ V_39 ] ) {
V_142 = F_150 ( V_29 , V_167 ) ;
if ( V_142 < 0 )
return V_142 ;
}
#if F_158 ( F_69 )
if ( V_167 [ V_74 ] )
V_29 -> V_75 = F_85 ( F_86 ( V_167 [ V_74 ] ) ) ;
#endif
if ( V_167 [ V_101 ] || V_167 [ V_102 ] ) {
V_142 = F_152 ( V_29 , V_167 ) ;
if ( V_142 < 0 )
return V_142 ;
}
if ( V_167 [ V_87 ] ) {
V_142 = F_153 ( V_29 , V_167 ) ;
if ( V_142 < 0 )
return V_142 ;
}
return 0 ;
}
static struct V_28 *
F_159 ( struct V_140 * V_140 ,
const struct V_23 * V_24 ,
const struct V_8 * const V_167 [] ,
struct V_3 * V_252 ,
struct V_3 * V_253 ,
T_5 V_205 )
{
struct V_28 * V_29 ;
int V_142 = - V_195 ;
struct V_43 * V_44 ;
struct V_67 * V_68 ;
V_29 = F_160 ( V_140 , V_24 , V_252 , V_253 , V_153 ) ;
if ( F_114 ( V_29 ) )
return F_84 ( - V_170 ) ;
if ( ! V_167 [ V_36 ] )
goto V_254;
V_29 -> V_32 . V_33 = F_85 ( F_86 ( V_167 [ V_36 ] ) ) ;
V_29 -> V_32 . V_33 = V_34 + V_29 -> V_32 . V_33 * V_35 ;
F_8 () ;
if ( V_167 [ V_46 ] ) {
char * V_242 = NULL ;
struct V_8 * V_199 = NULL ;
V_142 = F_111 ( V_167 [ V_46 ] , & V_242 , & V_199 ) ;
if ( V_142 < 0 )
goto V_255;
V_44 = F_147 ( V_242 , F_20 ( V_29 ) ,
F_21 ( V_29 ) ) ;
if ( V_44 == NULL ) {
F_11 () ;
#ifdef F_138
if ( F_140 ( L_4 , V_242 ) < 0 ) {
V_142 = - V_174 ;
goto V_254;
}
F_8 () ;
V_44 = F_147 ( V_242 ,
F_20 ( V_29 ) ,
F_21 ( V_29 ) ) ;
if ( V_44 ) {
V_142 = - V_162 ;
goto V_255;
}
F_11 () ;
#endif
V_142 = - V_174 ;
goto V_254;
} else {
struct V_41 * V_42 ;
V_42 = F_161 ( V_29 , V_44 , V_153 ) ;
if ( V_42 == NULL ) {
V_142 = - V_170 ;
goto V_255;
}
if ( V_44 -> V_245 )
V_44 -> V_245 ( V_199 , V_29 ) ;
F_146 ( V_42 -> V_44 , V_44 ) ;
}
} else {
V_142 = F_162 ( V_29 , NULL , V_153 ) ;
if ( V_142 < 0 )
goto V_255;
}
V_142 = F_143 ( V_29 , V_167 ) ;
if ( V_142 < 0 )
goto V_255;
F_163 ( V_29 , V_153 ) ;
F_164 ( V_29 , V_153 ) ;
F_165 ( V_29 , 0 , 0 , V_153 ) ;
F_166 ( V_29 ) ;
V_29 -> V_31 |= V_231 ;
if ( V_167 [ V_30 ] ) {
V_142 = F_142 ( V_29 , V_167 ) ;
if ( V_142 < 0 )
goto V_255;
}
if ( V_167 [ V_101 ] || V_167 [ V_102 ] ) {
V_142 = F_152 ( V_29 , V_167 ) ;
if ( V_142 < 0 )
goto V_255;
}
memset ( & V_29 -> V_256 , 0 , sizeof( V_29 -> V_256 ) ) ;
if ( V_167 [ V_39 ] ) {
V_142 = F_150 ( V_29 , V_167 ) ;
if ( V_142 < 0 )
goto V_255;
}
#if F_158 ( F_69 )
if ( V_167 [ V_74 ] )
V_29 -> V_75 = F_85 ( F_86 ( V_167 [ V_74 ] ) ) ;
#endif
if ( V_167 [ V_89 ] ) {
struct V_3 V_243 ;
struct V_177 * V_257 ;
struct V_28 * V_258 ;
V_142 = F_110 ( V_167 , & V_243 , V_89 ,
V_205 , NULL ) ;
if ( V_142 < 0 )
goto V_255;
V_257 = F_119 ( V_140 , V_24 , & V_243 ) ;
if ( V_257 == NULL ) {
V_142 = - V_206 ;
goto V_255;
}
V_258 = F_95 ( V_257 ) ;
F_167 ( V_259 , & V_29 -> V_31 ) ;
V_29 -> V_243 = V_258 ;
}
V_68 = F_34 ( V_29 ) ;
if ( V_68 )
V_68 -> V_71 = F_168 () ;
V_142 = F_169 ( V_29 ) ;
if ( V_142 < 0 )
goto V_255;
F_11 () ;
return V_29 ;
V_255:
F_11 () ;
V_254:
F_170 ( V_29 ) ;
return F_84 ( V_142 ) ;
}
static int
F_171 ( struct V_203 * V_204 , struct V_1 * V_2 ,
const struct V_108 * V_109 ,
const struct V_8 * const V_167 [] )
{
struct V_140 * V_140 = F_89 ( V_204 ) ;
struct V_3 V_252 , V_253 ;
struct V_177 * V_178 = NULL ;
struct V_110 * V_111 = F_54 ( V_109 ) ;
struct V_28 * V_29 ;
V_133 V_205 = V_111 -> V_118 ;
struct V_23 V_24 ;
int V_142 ;
V_142 = F_105 ( V_167 [ V_127 ] , & V_24 ) ;
if ( V_142 < 0 )
return V_142 ;
if ( V_167 [ V_122 ] ) {
V_142 = F_110 ( V_167 , & V_252 , V_122 ,
V_205 , & V_24 ) ;
if ( V_142 < 0 )
return V_142 ;
}
if ( V_167 [ V_125 ] ) {
V_142 = F_110 ( V_167 , & V_253 , V_125 ,
V_205 , & V_24 ) ;
if ( V_142 < 0 )
return V_142 ;
}
if ( V_167 [ V_122 ] )
V_178 = F_119 ( V_140 , & V_24 , & V_252 ) ;
else if ( V_167 [ V_125 ] )
V_178 = F_119 ( V_140 , & V_24 , & V_253 ) ;
if ( V_178 == NULL ) {
V_142 = - V_206 ;
if ( V_109 -> V_208 & V_148 ) {
enum V_260 V_137 ;
if ( ! V_167 [ V_122 ] || ! V_167 [ V_125 ] )
return - V_195 ;
V_29 = F_159 ( V_140 , & V_24 , V_167 , & V_252 ,
& V_253 , V_205 ) ;
if ( F_114 ( V_29 ) )
return F_115 ( V_29 ) ;
V_142 = 0 ;
if ( F_172 ( V_259 , & V_29 -> V_31 ) )
V_137 = V_147 ;
else
V_137 = V_146 ;
if ( V_167 [ V_87 ] &&
F_153 ( V_29 , V_167 ) == 0 )
V_137 |= ( 1 << V_158 ) ;
F_173 ( ( 1 << V_261 ) |
( 1 << V_262 ) |
( 1 << V_156 ) |
( 1 << V_155 ) |
( 1 << V_159 ) |
( 1 << V_160 ) | V_137 ,
V_29 , F_96 ( V_2 ) . V_107 ,
F_118 ( V_109 ) ) ;
F_80 ( V_29 ) ;
}
return V_142 ;
}
V_142 = - V_263 ;
V_29 = F_95 ( V_178 ) ;
if ( ! ( V_109 -> V_208 & V_149 ) ) {
F_129 ( & V_244 ) ;
V_142 = F_157 ( V_29 , V_167 ) ;
F_131 ( & V_244 ) ;
if ( V_142 == 0 ) {
F_173 ( ( 1 << V_261 ) |
( 1 << V_262 ) |
( 1 << V_156 ) |
( 1 << V_158 ) |
( 1 << V_155 ) |
( 1 << V_159 ) |
( 1 << V_160 ) ,
V_29 , F_96 ( V_2 ) . V_107 ,
F_118 ( V_109 ) ) ;
}
}
F_80 ( V_29 ) ;
return V_142 ;
}
static int
F_174 ( struct V_1 * V_2 , T_2 V_107 , T_2 V_91 ,
T_6 V_217 , const struct V_264 * V_265 )
{
struct V_108 * V_109 ;
struct V_110 * V_111 ;
unsigned int V_112 = V_107 ? V_113 : 0 , V_114 ;
V_114 = ( V_115 << 8 | V_266 ) ;
V_109 = F_53 ( V_2 , V_107 , V_91 , V_114 , sizeof( * V_111 ) , V_112 ) ;
if ( V_109 == NULL )
goto V_117;
V_111 = F_54 ( V_109 ) ;
V_111 -> V_118 = V_267 ;
V_111 -> V_119 = V_120 ;
V_111 -> V_121 = F_14 ( V_217 ) ;
if ( F_16 ( V_2 , V_268 , F_17 ( V_265 -> V_269 ) ) ||
F_16 ( V_2 , V_270 , F_17 ( V_265 -> V_271 ) ) ||
F_16 ( V_2 , V_272 , F_17 ( V_265 -> V_273 ) ) ||
F_16 ( V_2 , V_274 , F_17 ( V_265 -> V_275 ) ) ||
F_16 ( V_2 , V_276 , F_17 ( V_265 -> V_277 ) ) ||
F_16 ( V_2 , V_278 , F_17 ( V_265 -> V_279 ) ) ||
F_16 ( V_2 , V_280 , F_17 ( V_265 -> V_281 ) ) ||
F_16 ( V_2 , V_282 , F_17 ( V_265 -> V_283 ) ) ||
F_16 ( V_2 , V_284 ,
F_17 ( V_265 -> V_285 ) ) ||
F_16 ( V_2 , V_286 , F_17 ( V_265 -> V_287 ) ) ||
F_16 ( V_2 , V_288 , F_17 ( V_265 -> V_289 ) ) ||
F_16 ( V_2 , V_290 , F_17 ( V_265 -> error ) ) ||
F_16 ( V_2 , V_291 ,
F_17 ( V_265 -> V_292 ) ) )
goto V_12;
F_57 ( V_2 , V_109 ) ;
return V_2 -> V_77 ;
V_12:
V_117:
F_58 ( V_2 , V_109 ) ;
return - 1 ;
}
static int
F_175 ( struct V_1 * V_2 , struct V_163 * V_164 )
{
int V_217 ;
struct V_140 * V_140 = F_89 ( V_2 -> V_175 ) ;
if ( V_164 -> args [ 0 ] == V_220 )
return 0 ;
for ( V_217 = V_164 -> args [ 0 ] ; V_217 < V_220 ; V_217 ++ ) {
const struct V_264 * V_265 ;
if ( ! F_127 ( V_217 ) )
continue;
V_265 = F_128 ( V_140 -> V_29 . V_293 , V_217 ) ;
if ( F_174 ( V_2 ,
F_96 ( V_164 -> V_2 ) . V_107 ,
V_164 -> V_109 -> V_187 ,
V_217 , V_265 ) < 0 )
break;
}
V_164 -> args [ 0 ] = V_217 ;
return V_2 -> V_77 ;
}
static int
F_176 ( struct V_203 * V_204 , struct V_1 * V_2 ,
const struct V_108 * V_109 ,
const struct V_8 * const V_167 [] )
{
if ( V_109 -> V_208 & V_209 ) {
struct V_210 V_211 = {
. V_212 = F_175 ,
} ;
return F_123 ( V_204 , V_2 , V_109 , & V_211 ) ;
}
return 0 ;
}
static int
F_177 ( struct V_1 * V_2 , T_2 V_107 , T_2 V_91 , T_2 type ,
struct V_140 * V_140 )
{
struct V_108 * V_109 ;
struct V_110 * V_111 ;
unsigned int V_112 = V_107 ? V_113 : 0 , V_114 ;
unsigned int V_294 = F_51 ( & V_140 -> V_29 . V_295 ) ;
V_114 = ( V_115 << 8 | V_296 ) ;
V_109 = F_53 ( V_2 , V_107 , V_91 , V_114 , sizeof( * V_111 ) , V_112 ) ;
if ( V_109 == NULL )
goto V_117;
V_111 = F_54 ( V_109 ) ;
V_111 -> V_118 = V_267 ;
V_111 -> V_119 = V_120 ;
V_111 -> V_121 = 0 ;
if ( F_16 ( V_2 , V_297 , F_17 ( V_294 ) ) )
goto V_12;
F_57 ( V_2 , V_109 ) ;
return V_2 -> V_77 ;
V_12:
V_117:
F_58 ( V_2 , V_109 ) ;
return - 1 ;
}
static int
F_178 ( struct V_203 * V_204 , struct V_1 * V_2 ,
const struct V_108 * V_109 ,
const struct V_8 * const V_167 [] )
{
struct V_1 * V_207 ;
int V_142 ;
V_207 = F_75 ( V_214 , V_169 ) ;
if ( V_207 == NULL )
return - V_170 ;
V_142 = F_177 ( V_207 , F_96 ( V_2 ) . V_107 ,
V_109 -> V_187 ,
F_97 ( V_109 -> V_188 ) ,
F_89 ( V_2 -> V_175 ) ) ;
if ( V_142 <= 0 )
goto free;
V_142 = F_124 ( V_204 , V_207 , F_96 ( V_2 ) . V_107 , V_215 ) ;
if ( V_142 < 0 )
goto V_45;
return 0 ;
free:
F_77 ( V_207 ) ;
V_45:
return V_142 == - V_162 ? - V_161 : V_142 ;
}
static T_3
F_179 ( const struct V_28 * V_29 )
{
return 3 * F_41 ( 0 )
+ 3 * F_41 ( 0 )
+ 3 * F_41 ( 0 )
+ 3 * F_41 ( sizeof( V_133 ) )
+ F_41 ( sizeof( V_134 ) )
+ F_41 ( sizeof( V_134 ) )
+ F_41 ( sizeof( V_134 ) )
+ F_41 ( 0 )
+ F_41 ( 0 )
+ F_41 ( V_135 )
+ F_62 ( V_29 )
#ifdef F_68
+ 2 * F_41 ( 0 )
+ 6 * F_41 ( sizeof( V_134 ) )
#endif
#ifdef F_69
+ F_41 ( sizeof( V_134 ) )
#endif
#ifdef F_70
+ F_41 ( sizeof( V_136 ) )
#endif
+ F_59 ( V_29 )
;
}
static struct V_28 * F_180 ( const struct V_1 * V_2 ,
enum V_298 * V_299 )
{
struct V_28 * V_29 ;
V_29 = F_181 ( V_2 , V_299 ) ;
if ( V_29 && F_72 ( V_29 ) )
V_29 = NULL ;
return V_29 ;
}
static int F_182 ( struct V_1 * V_2 , struct V_28 * V_29 )
{
const struct V_23 * V_24 ;
struct V_8 * V_9 ;
F_8 () ;
V_24 = F_55 ( V_29 ) ;
V_9 = F_2 ( V_2 , V_122 | V_11 ) ;
if ( ! V_9 )
goto V_12;
if ( F_7 ( V_2 , F_56 ( V_29 , V_65 ) ) < 0 )
goto V_12;
if ( F_12 ( V_2 , V_123 , V_24 ,
V_124 ) < 0 )
goto V_12;
F_5 ( V_2 , V_9 ) ;
V_9 = F_2 ( V_2 , V_125 | V_11 ) ;
if ( ! V_9 )
goto V_12;
if ( F_7 ( V_2 , F_56 ( V_29 , V_66 ) ) < 0 )
goto V_12;
if ( F_12 ( V_2 , V_123 , V_24 ,
V_126 ) < 0 )
goto V_12;
F_5 ( V_2 , V_9 ) ;
if ( F_12 ( V_2 , V_127 , V_24 ,
V_128 ) < 0 )
goto V_12;
if ( F_49 ( V_2 , V_29 ) < 0 )
goto V_12;
if ( F_15 ( V_2 , V_29 ) < 0 )
goto V_12;
if ( F_18 ( V_2 , V_29 ) < 0 )
goto V_12;
if ( F_19 ( V_2 , V_29 ) < 0 )
goto V_12;
if ( F_22 ( V_2 , V_29 ) < 0 )
goto V_12;
#ifdef F_63
if ( V_29 -> V_79 && F_36 ( V_2 , V_29 ) < 0 )
goto V_12;
#endif
if ( V_29 -> V_243 && F_44 ( V_2 , V_29 ) < 0 )
goto V_12;
if ( ( V_29 -> V_31 & V_100 ) &&
F_47 ( V_2 , V_29 ) < 0 )
goto V_12;
#ifdef F_69
if ( V_29 -> V_75 && F_35 ( V_2 , V_29 ) < 0 )
goto V_12;
#endif
if ( F_42 ( V_2 , V_29 ) < 0 )
goto V_12;
F_11 () ;
return 0 ;
V_12:
F_11 () ;
return - V_300 ;
}
static int
F_183 ( struct V_1 * V_2 , struct V_28 * V_29 ,
enum V_298 V_299 ,
V_136 V_301 , V_136 V_302 )
{
struct V_8 * V_9 ;
V_9 = F_2 ( V_2 , V_301 | V_11 ) ;
if ( ! V_9 )
goto V_12;
if ( F_182 ( V_2 , V_29 ) < 0 )
goto V_12;
F_5 ( V_2 , V_9 ) ;
if ( F_16 ( V_2 , V_302 , F_17 ( V_299 ) ) )
goto V_12;
return 0 ;
V_12:
return - V_300 ;
}
static int
F_184 ( const struct V_8 * V_167 [] , struct V_28 * V_29 )
{
int V_142 ;
if ( V_167 [ V_36 ] ) {
V_142 = F_148 ( V_29 , V_167 ) ;
if ( V_142 < 0 )
return V_142 ;
}
if ( V_167 [ V_30 ] ) {
V_142 = F_142 ( V_29 , V_167 ) ;
if ( V_142 < 0 )
return V_142 ;
}
if ( V_167 [ V_46 ] ) {
V_142 = F_144 ( V_29 , V_167 ) ;
if ( V_142 < 0 )
return V_142 ;
}
if ( V_167 [ V_87 ] ) {
V_142 = F_153 ( V_29 , V_167 ) ;
if ( V_142 < 0 )
return V_142 ;
}
#if F_158 ( F_69 )
if ( V_167 [ V_74 ] ) {
T_2 V_172 = 0 , V_75 , V_303 ;
if ( V_167 [ V_173 ] )
V_172 = ~ F_85 ( F_86 ( V_167 [ V_173 ] ) ) ;
V_75 = F_85 ( F_86 ( V_167 [ V_74 ] ) ) ;
V_303 = ( V_29 -> V_75 & V_172 ) ^ V_75 ;
if ( V_303 != V_29 -> V_75 )
V_29 -> V_75 = V_303 ;
}
#endif
return 0 ;
}
static int
F_185 ( const struct V_8 * V_53 , struct V_28 * V_29 )
{
struct V_8 * V_167 [ V_304 + 1 ] ;
int V_7 ;
V_7 = F_101 ( V_167 , V_304 , V_53 , V_305 ) ;
if ( V_7 < 0 )
return V_7 ;
F_129 ( & V_244 ) ;
V_7 = F_184 ( ( const struct V_8 * * ) V_167 , V_29 ) ;
F_131 ( & V_244 ) ;
return V_7 ;
}
static int F_186 ( const struct V_8 * const * V_167 ,
const struct V_28 * V_29 ,
struct V_3 * V_4 ,
struct V_3 * V_172 )
{
int V_142 ;
V_142 = F_110 ( V_167 , V_4 , V_306 ,
F_20 ( V_29 ) , NULL ) ;
if ( V_142 < 0 )
return V_142 ;
return F_110 ( V_167 , V_172 , V_307 ,
F_20 ( V_29 ) , NULL ) ;
}
static int
F_187 ( const struct V_8 * V_53 , struct V_28 * V_29 ,
T_2 V_107 , T_2 V_152 )
{
struct V_8 * V_167 [ V_308 + 1 ] ;
struct V_3 V_4 , V_172 ;
struct V_43 * V_44 = NULL ;
struct V_309 * exp ;
int V_142 ;
V_142 = F_101 ( V_167 , V_308 , V_53 , V_310 ) ;
if ( V_142 < 0 )
return V_142 ;
V_142 = F_186 ( ( const struct V_8 * const * ) V_167 ,
V_29 , & V_4 , & V_172 ) ;
if ( V_142 < 0 )
return V_142 ;
if ( V_167 [ V_311 ] ) {
const char * V_242 = F_112 ( V_167 [ V_311 ] ) ;
V_44 = F_147 ( V_242 , F_20 ( V_29 ) ,
F_21 ( V_29 ) ) ;
if ( V_44 == NULL )
return - V_174 ;
}
exp = F_188 ( ( const struct V_8 * const * ) V_167 , V_29 ,
V_44 , & V_4 , & V_172 ) ;
if ( F_114 ( exp ) )
return F_115 ( exp ) ;
V_142 = F_189 ( exp , V_107 , V_152 ) ;
if ( V_142 < 0 ) {
F_190 ( exp ) ;
return V_142 ;
}
return 0 ;
}
static void F_191 ( struct V_1 * V_2 , struct V_28 * V_29 ,
enum V_298 V_299 , int V_312 )
{
if ( ! ( V_29 -> V_31 & V_237 ) )
return;
F_192 ( V_2 , V_29 , V_299 , V_312 ) ;
}
static inline int
F_193 ( struct V_1 * V_2 ,
const struct V_3 * V_4 ,
enum V_313 type )
{
struct V_8 * V_9 ;
V_9 = F_2 ( V_2 , type | V_11 ) ;
if ( ! V_9 )
goto V_12;
if ( F_7 ( V_2 , V_4 ) < 0 )
goto V_12;
F_5 ( V_2 , V_9 ) ;
return 0 ;
V_12:
return - 1 ;
}
static inline int
F_194 ( struct V_1 * V_2 ,
const struct V_3 * V_4 ,
const struct V_314 * V_172 )
{
int V_7 ;
struct V_17 * V_18 ;
struct V_5 * V_6 ;
struct V_3 V_315 ;
struct V_8 * V_9 ;
memset ( & V_315 , 0xFF , sizeof( V_315 ) ) ;
memcpy ( & V_315 . V_20 . V_205 , & V_172 -> V_20 . V_205 , sizeof( V_315 . V_20 . V_205 ) ) ;
V_315 . V_20 . V_316 . V_317 = V_172 -> V_20 . V_316 . V_317 ;
V_315 . V_14 . V_15 = V_4 -> V_14 . V_15 ;
V_9 = F_2 ( V_2 , V_307 | V_11 ) ;
if ( ! V_9 )
goto V_12;
F_8 () ;
V_18 = F_9 ( V_4 -> V_20 . V_21 ) ;
V_7 = F_6 ( V_2 , & V_315 , V_18 ) ;
if ( V_7 >= 0 ) {
V_6 = F_10 ( V_4 -> V_20 . V_21 ,
V_4 -> V_14 . V_15 ) ;
V_7 = F_1 ( V_2 , & V_315 , V_6 ) ;
}
F_11 () ;
if ( F_195 ( V_7 < 0 ) )
goto V_12;
F_5 ( V_2 , V_9 ) ;
return 0 ;
V_12:
return - 1 ;
}
static int
F_196 ( struct V_1 * V_2 ,
const struct V_309 * exp )
{
struct V_28 * V_243 = exp -> V_243 ;
long V_32 = ( ( long ) exp -> V_32 . V_33 - ( long ) V_34 ) / V_35 ;
struct V_41 * V_42 ;
#ifdef F_68
struct V_8 * V_9 ;
struct V_3 V_318 = {} ;
#endif
struct V_319 * V_320 ;
if ( V_32 < 0 )
V_32 = 0 ;
if ( F_193 ( V_2 , & exp -> V_4 , V_306 ) < 0 )
goto V_12;
if ( F_194 ( V_2 , & exp -> V_4 , & exp -> V_172 ) < 0 )
goto V_12;
if ( F_193 ( V_2 ,
& V_243 -> V_321 [ V_65 ] . V_4 ,
V_322 ) < 0 )
goto V_12;
#ifdef F_68
if ( ! F_197 ( & exp -> V_323 , & V_324 ) ||
exp -> V_325 . V_317 ) {
V_9 = F_2 ( V_2 , V_326 | V_11 ) ;
if ( ! V_9 )
goto V_12;
if ( F_16 ( V_2 , V_327 , F_17 ( exp -> V_25 ) ) )
goto V_12;
V_318 . V_20 . V_21 = F_20 ( V_243 ) ;
V_318 . V_20 . V_205 = exp -> V_323 ;
V_318 . V_14 . V_15 = F_21 ( V_243 ) ;
V_318 . V_20 . V_316 = exp -> V_325 ;
if ( F_193 ( V_2 , & V_318 ,
V_328 ) < 0 )
goto V_12;
F_5 ( V_2 , V_9 ) ;
}
#endif
if ( F_16 ( V_2 , V_329 , F_17 ( V_32 ) ) ||
F_16 ( V_2 , V_330 , F_17 ( ( unsigned long ) exp ) ) ||
F_16 ( V_2 , V_331 , F_17 ( exp -> V_112 ) ) ||
F_16 ( V_2 , V_332 , F_17 ( exp -> V_333 ) ) )
goto V_12;
V_42 = F_23 ( V_243 ) ;
if ( V_42 ) {
struct V_43 * V_44 ;
V_44 = F_24 ( V_42 -> V_44 ) ;
if ( V_44 &&
F_25 ( V_2 , V_311 , V_44 -> V_48 ) )
goto V_12;
}
V_320 = F_198 ( exp -> V_334 ) ;
if ( V_320 != NULL &&
F_25 ( V_2 , V_335 , V_320 -> V_48 ) )
goto V_12;
return 0 ;
V_12:
return - 1 ;
}
static int
F_199 ( struct V_1 * V_2 , T_2 V_107 , T_2 V_91 ,
int V_114 , const struct V_309 * exp )
{
struct V_108 * V_109 ;
struct V_110 * V_111 ;
unsigned int V_112 = V_107 ? V_113 : 0 ;
V_114 |= V_336 << 8 ;
V_109 = F_53 ( V_2 , V_107 , V_91 , V_114 , sizeof( * V_111 ) , V_112 ) ;
if ( V_109 == NULL )
goto V_117;
V_111 = F_54 ( V_109 ) ;
V_111 -> V_118 = exp -> V_4 . V_20 . V_21 ;
V_111 -> V_119 = V_120 ;
V_111 -> V_121 = 0 ;
if ( F_196 ( V_2 , exp ) < 0 )
goto V_12;
F_57 ( V_2 , V_109 ) ;
return V_2 -> V_77 ;
V_117:
V_12:
F_58 ( V_2 , V_109 ) ;
return - 1 ;
}
static int
F_200 ( unsigned int V_137 , struct V_337 * V_139 )
{
struct V_309 * exp = V_139 -> exp ;
struct V_140 * V_140 = F_201 ( exp ) ;
struct V_108 * V_109 ;
struct V_110 * V_111 ;
struct V_1 * V_2 ;
unsigned int type , V_141 ;
int V_112 = 0 ;
if ( V_137 & ( 1 << V_338 ) ) {
type = V_339 ;
V_141 = V_340 ;
} else if ( V_137 & ( 1 << V_341 ) ) {
type = V_342 ;
V_112 = V_148 | V_149 ;
V_141 = V_343 ;
} else
return 0 ;
if ( ! V_139 -> V_152 && ! F_74 ( V_140 , V_141 ) )
return 0 ;
V_2 = F_75 ( V_214 , V_153 ) ;
if ( V_2 == NULL )
goto V_154;
type |= V_336 << 8 ;
V_109 = F_53 ( V_2 , V_139 -> V_107 , 0 , type , sizeof( * V_111 ) , V_112 ) ;
if ( V_109 == NULL )
goto V_117;
V_111 = F_54 ( V_109 ) ;
V_111 -> V_118 = exp -> V_4 . V_20 . V_21 ;
V_111 -> V_119 = V_120 ;
V_111 -> V_121 = 0 ;
F_8 () ;
if ( F_196 ( V_2 , exp ) < 0 )
goto V_12;
F_11 () ;
F_57 ( V_2 , V_109 ) ;
F_76 ( V_2 , V_140 , V_139 -> V_107 , V_141 , V_139 -> V_152 , V_153 ) ;
return 0 ;
V_12:
F_11 () ;
F_58 ( V_2 , V_109 ) ;
V_117:
F_77 ( V_2 ) ;
V_154:
F_78 ( V_140 , 0 , 0 , - V_161 ) ;
return 0 ;
}
static int F_202 ( struct V_163 * V_164 )
{
if ( V_164 -> args [ 1 ] )
F_190 ( (struct V_309 * ) V_164 -> args [ 1 ] ) ;
return 0 ;
}
static int
F_203 ( struct V_1 * V_2 , struct V_163 * V_164 )
{
struct V_140 * V_140 = F_89 ( V_2 -> V_175 ) ;
struct V_309 * exp , * V_176 ;
struct V_110 * V_111 = F_54 ( V_164 -> V_109 ) ;
V_133 V_18 = V_111 -> V_118 ;
F_8 () ;
V_176 = (struct V_309 * ) V_164 -> args [ 1 ] ;
for (; V_164 -> args [ 0 ] < V_344 ; V_164 -> args [ 0 ] ++ ) {
V_184:
F_204 (exp, &net->ct.expect_hash[cb->args[0]],
hnode) {
if ( V_18 && exp -> V_4 . V_20 . V_21 != V_18 )
continue;
if ( V_164 -> args [ 1 ] ) {
if ( exp != V_176 )
continue;
V_164 -> args [ 1 ] = 0 ;
}
if ( F_199 ( V_2 ,
F_96 ( V_164 -> V_2 ) . V_107 ,
V_164 -> V_109 -> V_187 ,
V_342 ,
exp ) < 0 ) {
if ( ! F_130 ( & exp -> V_106 ) )
continue;
V_164 -> args [ 1 ] = ( unsigned long ) exp ;
goto V_45;
}
}
if ( V_164 -> args [ 1 ] ) {
V_164 -> args [ 1 ] = 0 ;
goto V_184;
}
}
V_45:
F_11 () ;
if ( V_176 )
F_190 ( V_176 ) ;
return V_2 -> V_77 ;
}
static int
F_205 ( struct V_1 * V_2 , struct V_163 * V_164 )
{
struct V_309 * exp , * V_176 ;
struct V_110 * V_111 = F_54 ( V_164 -> V_109 ) ;
struct V_28 * V_29 = V_164 -> V_165 ;
struct V_41 * V_42 = F_23 ( V_29 ) ;
V_133 V_18 = V_111 -> V_118 ;
if ( V_164 -> args [ 0 ] )
return 0 ;
F_8 () ;
V_176 = (struct V_309 * ) V_164 -> args [ 1 ] ;
V_184:
F_204 (exp, &help->expectations, lnode) {
if ( V_18 && exp -> V_4 . V_20 . V_21 != V_18 )
continue;
if ( V_164 -> args [ 1 ] ) {
if ( exp != V_176 )
continue;
V_164 -> args [ 1 ] = 0 ;
}
if ( F_199 ( V_2 , F_96 ( V_164 -> V_2 ) . V_107 ,
V_164 -> V_109 -> V_187 ,
V_342 ,
exp ) < 0 ) {
if ( ! F_130 ( & exp -> V_106 ) )
continue;
V_164 -> args [ 1 ] = ( unsigned long ) exp ;
goto V_45;
}
}
if ( V_164 -> args [ 1 ] ) {
V_164 -> args [ 1 ] = 0 ;
goto V_184;
}
V_164 -> args [ 0 ] = 1 ;
V_45:
F_11 () ;
if ( V_176 )
F_190 ( V_176 ) ;
return V_2 -> V_77 ;
}
static int F_206 ( struct V_203 * V_204 , struct V_1 * V_2 ,
const struct V_108 * V_109 ,
const struct V_8 * const V_167 [] )
{
int V_142 ;
struct V_140 * V_140 = F_89 ( V_204 ) ;
struct V_110 * V_111 = F_54 ( V_109 ) ;
V_133 V_205 = V_111 -> V_118 ;
struct V_3 V_4 ;
struct V_177 * V_178 ;
struct V_28 * V_29 ;
struct V_23 V_24 ;
struct V_210 V_211 = {
. V_212 = F_205 ,
. V_213 = F_202 ,
} ;
V_142 = F_110 ( V_167 , & V_4 , V_322 ,
V_205 , NULL ) ;
if ( V_142 < 0 )
return V_142 ;
V_142 = F_105 ( V_167 [ V_345 ] , & V_24 ) ;
if ( V_142 < 0 )
return V_142 ;
V_178 = F_119 ( V_140 , & V_24 , & V_4 ) ;
if ( ! V_178 )
return - V_206 ;
V_29 = F_95 ( V_178 ) ;
V_211 . V_165 = V_29 ;
V_142 = F_123 ( V_204 , V_2 , V_109 , & V_211 ) ;
F_80 ( V_29 ) ;
return V_142 ;
}
static int
F_207 ( struct V_203 * V_204 , struct V_1 * V_2 ,
const struct V_108 * V_109 ,
const struct V_8 * const V_167 [] )
{
struct V_140 * V_140 = F_89 ( V_204 ) ;
struct V_3 V_4 ;
struct V_309 * exp ;
struct V_1 * V_207 ;
struct V_110 * V_111 = F_54 ( V_109 ) ;
V_133 V_205 = V_111 -> V_118 ;
struct V_23 V_24 ;
int V_142 ;
if ( V_109 -> V_208 & V_209 ) {
if ( V_167 [ V_322 ] )
return F_206 ( V_204 , V_2 , V_109 , V_167 ) ;
else {
struct V_210 V_211 = {
. V_212 = F_203 ,
. V_213 = F_202 ,
} ;
return F_123 ( V_204 , V_2 , V_109 , & V_211 ) ;
}
}
V_142 = F_105 ( V_167 [ V_345 ] , & V_24 ) ;
if ( V_142 < 0 )
return V_142 ;
if ( V_167 [ V_306 ] )
V_142 = F_110 ( V_167 , & V_4 , V_306 ,
V_205 , NULL ) ;
else if ( V_167 [ V_322 ] )
V_142 = F_110 ( V_167 , & V_4 , V_322 ,
V_205 , NULL ) ;
else
return - V_195 ;
if ( V_142 < 0 )
return V_142 ;
exp = F_208 ( V_140 , & V_24 , & V_4 ) ;
if ( ! exp )
return - V_206 ;
if ( V_167 [ V_330 ] ) {
T_7 V_26 = F_86 ( V_167 [ V_330 ] ) ;
if ( F_85 ( V_26 ) != ( T_2 ) ( unsigned long ) exp ) {
F_190 ( exp ) ;
return - V_206 ;
}
}
V_142 = - V_170 ;
V_207 = F_75 ( V_214 , V_169 ) ;
if ( V_207 == NULL ) {
F_190 ( exp ) ;
goto V_45;
}
F_8 () ;
V_142 = F_199 ( V_207 , F_96 ( V_2 ) . V_107 ,
V_109 -> V_187 , V_342 , exp ) ;
F_11 () ;
F_190 ( exp ) ;
if ( V_142 <= 0 )
goto free;
V_142 = F_124 ( V_204 , V_207 , F_96 ( V_2 ) . V_107 , V_215 ) ;
if ( V_142 < 0 )
goto V_45;
return 0 ;
free:
F_77 ( V_207 ) ;
V_45:
return V_142 == - V_162 ? - V_161 : V_142 ;
}
static int
F_209 ( struct V_203 * V_204 , struct V_1 * V_2 ,
const struct V_108 * V_109 ,
const struct V_8 * const V_167 [] )
{
struct V_140 * V_140 = F_89 ( V_204 ) ;
struct V_309 * exp ;
struct V_3 V_4 ;
struct V_110 * V_111 = F_54 ( V_109 ) ;
struct V_346 * V_347 ;
V_133 V_205 = V_111 -> V_118 ;
struct V_23 V_24 ;
unsigned int V_85 ;
int V_142 ;
if ( V_167 [ V_306 ] ) {
V_142 = F_105 ( V_167 [ V_345 ] , & V_24 ) ;
if ( V_142 < 0 )
return V_142 ;
V_142 = F_110 ( V_167 , & V_4 , V_306 ,
V_205 , NULL ) ;
if ( V_142 < 0 )
return V_142 ;
exp = F_208 ( V_140 , & V_24 , & V_4 ) ;
if ( ! exp )
return - V_206 ;
if ( V_167 [ V_330 ] ) {
T_7 V_26 = F_86 ( V_167 [ V_330 ] ) ;
if ( F_85 ( V_26 ) != ( T_2 ) ( unsigned long ) exp ) {
F_190 ( exp ) ;
return - V_206 ;
}
}
F_129 ( & V_244 ) ;
if ( F_120 ( & exp -> V_32 ) ) {
F_210 ( exp , F_96 ( V_2 ) . V_107 ,
F_118 ( V_109 ) ) ;
F_190 ( exp ) ;
}
F_131 ( & V_244 ) ;
F_190 ( exp ) ;
} else if ( V_167 [ V_311 ] ) {
char * V_48 = F_112 ( V_167 [ V_311 ] ) ;
struct V_41 * V_348 ;
F_129 ( & V_244 ) ;
for ( V_85 = 0 ; V_85 < V_344 ; V_85 ++ ) {
F_211 (exp, next,
&net->ct.expect_hash[i],
hnode) {
V_348 = F_23 ( exp -> V_243 ) ;
if ( ! strcmp ( V_348 -> V_44 -> V_48 , V_48 ) &&
F_120 ( & exp -> V_32 ) ) {
F_210 ( exp ,
F_96 ( V_2 ) . V_107 ,
F_118 ( V_109 ) ) ;
F_190 ( exp ) ;
}
}
}
F_131 ( & V_244 ) ;
} else {
F_129 ( & V_244 ) ;
for ( V_85 = 0 ; V_85 < V_344 ; V_85 ++ ) {
F_211 (exp, next,
&net->ct.expect_hash[i],
hnode) {
if ( F_120 ( & exp -> V_32 ) ) {
F_210 ( exp ,
F_96 ( V_2 ) . V_107 ,
F_118 ( V_109 ) ) ;
F_190 ( exp ) ;
}
}
}
F_131 ( & V_244 ) ;
}
return 0 ;
}
static int
F_212 ( struct V_309 * V_349 ,
const struct V_8 * const V_167 [] )
{
if ( V_167 [ V_329 ] ) {
if ( ! F_120 ( & V_349 -> V_32 ) )
return - V_246 ;
V_349 -> V_32 . V_33 = V_34 +
F_85 ( F_86 ( V_167 [ V_329 ] ) ) * V_35 ;
F_149 ( & V_349 -> V_32 ) ;
}
return 0 ;
}
static int
F_213 ( const struct V_8 * V_53 ,
struct V_309 * exp ,
V_133 V_205 )
{
#ifdef F_68
struct V_8 * V_189 [ V_350 + 1 ] ;
struct V_3 V_318 = {} ;
int V_142 ;
V_142 = F_101 ( V_189 , V_350 , V_53 , V_351 ) ;
if ( V_142 < 0 )
return V_142 ;
if ( ! V_189 [ V_327 ] || ! V_189 [ V_328 ] )
return - V_195 ;
V_142 = F_110 ( ( const struct V_8 * const * ) V_189 ,
& V_318 , V_328 ,
V_205 , NULL ) ;
if ( V_142 < 0 )
return V_142 ;
exp -> V_323 = V_318 . V_20 . V_205 ;
exp -> V_325 = V_318 . V_20 . V_316 ;
exp -> V_25 = F_85 ( F_86 ( V_189 [ V_327 ] ) ) ;
return 0 ;
#else
return - V_174 ;
#endif
}
static struct V_309 *
F_188 ( const struct V_8 * const V_167 [] , struct V_28 * V_29 ,
struct V_43 * V_44 ,
struct V_3 * V_4 ,
struct V_3 * V_172 )
{
V_134 V_333 = 0 ;
struct V_309 * exp ;
struct V_41 * V_42 ;
int V_142 ;
if ( V_167 [ V_332 ] && V_44 ) {
V_333 = F_85 ( F_86 ( V_167 [ V_332 ] ) ) ;
if ( V_333 > V_44 -> V_352 )
return F_84 ( - V_195 ) ;
}
exp = F_214 ( V_29 ) ;
if ( ! exp )
return F_84 ( - V_170 ) ;
V_42 = F_23 ( V_29 ) ;
if ( ! V_42 ) {
if ( ! V_167 [ V_329 ] ) {
V_142 = - V_195 ;
goto V_353;
}
exp -> V_32 . V_33 =
V_34 + F_85 ( F_86 ( V_167 [ V_329 ] ) ) * V_35 ;
exp -> V_112 = V_354 ;
if ( V_167 [ V_331 ] ) {
exp -> V_112 |=
F_85 ( F_86 ( V_167 [ V_331 ] ) ) ;
}
} else {
if ( V_167 [ V_331 ] ) {
exp -> V_112 = F_85 ( F_86 ( V_167 [ V_331 ] ) ) ;
exp -> V_112 &= ~ V_354 ;
} else
exp -> V_112 = 0 ;
}
if ( V_167 [ V_335 ] ) {
const char * V_48 = F_112 ( V_167 [ V_335 ] ) ;
struct V_319 * V_320 ;
V_320 = F_215 ( V_48 ) ;
if ( V_320 == NULL ) {
V_142 = - V_195 ;
goto V_353;
}
exp -> V_334 = V_320 -> V_334 ;
} else
exp -> V_334 = NULL ;
exp -> V_333 = V_333 ;
exp -> V_243 = V_29 ;
exp -> V_44 = V_44 ;
exp -> V_4 = * V_4 ;
exp -> V_172 . V_20 . V_205 = V_172 -> V_20 . V_205 ;
exp -> V_172 . V_20 . V_316 . V_317 = V_172 -> V_20 . V_316 . V_317 ;
if ( V_167 [ V_326 ] ) {
V_142 = F_213 ( V_167 [ V_326 ] ,
exp , F_20 ( V_29 ) ) ;
if ( V_142 < 0 )
goto V_353;
}
return exp ;
V_353:
F_190 ( exp ) ;
return F_84 ( V_142 ) ;
}
static int
F_216 ( struct V_140 * V_140 ,
const struct V_23 * V_24 ,
const struct V_8 * const V_167 [] ,
V_133 V_205 , T_2 V_107 , int V_152 )
{
struct V_3 V_4 , V_172 , F_45 ;
struct V_177 * V_178 = NULL ;
struct V_43 * V_44 = NULL ;
struct V_309 * exp ;
struct V_28 * V_29 ;
int V_142 ;
V_142 = F_110 ( V_167 , & V_4 , V_306 ,
V_205 , NULL ) ;
if ( V_142 < 0 )
return V_142 ;
V_142 = F_110 ( V_167 , & V_172 , V_307 ,
V_205 , NULL ) ;
if ( V_142 < 0 )
return V_142 ;
V_142 = F_110 ( V_167 , & F_45 , V_322 ,
V_205 , NULL ) ;
if ( V_142 < 0 )
return V_142 ;
V_178 = F_119 ( V_140 , V_24 , & F_45 ) ;
if ( ! V_178 )
return - V_206 ;
V_29 = F_95 ( V_178 ) ;
if ( V_167 [ V_311 ] ) {
const char * V_242 = F_112 ( V_167 [ V_311 ] ) ;
V_44 = F_147 ( V_242 , V_205 ,
F_21 ( V_29 ) ) ;
if ( V_44 == NULL ) {
#ifdef F_138
if ( F_140 ( L_4 , V_242 ) < 0 ) {
V_142 = - V_174 ;
goto V_355;
}
V_44 = F_147 ( V_242 , V_205 ,
F_21 ( V_29 ) ) ;
if ( V_44 ) {
V_142 = - V_162 ;
goto V_355;
}
#endif
V_142 = - V_174 ;
goto V_355;
}
}
exp = F_188 ( V_167 , V_29 , V_44 , & V_4 , & V_172 ) ;
if ( F_114 ( exp ) ) {
V_142 = F_115 ( exp ) ;
goto V_355;
}
V_142 = F_189 ( exp , V_107 , V_152 ) ;
F_190 ( exp ) ;
V_355:
F_80 ( V_29 ) ;
return V_142 ;
}
static int
F_217 ( struct V_203 * V_204 , struct V_1 * V_2 ,
const struct V_108 * V_109 ,
const struct V_8 * const V_167 [] )
{
struct V_140 * V_140 = F_89 ( V_204 ) ;
struct V_3 V_4 ;
struct V_309 * exp ;
struct V_110 * V_111 = F_54 ( V_109 ) ;
V_133 V_205 = V_111 -> V_118 ;
struct V_23 V_24 ;
int V_142 ;
if ( ! V_167 [ V_306 ]
|| ! V_167 [ V_307 ]
|| ! V_167 [ V_322 ] )
return - V_195 ;
V_142 = F_105 ( V_167 [ V_345 ] , & V_24 ) ;
if ( V_142 < 0 )
return V_142 ;
V_142 = F_110 ( V_167 , & V_4 , V_306 ,
V_205 , NULL ) ;
if ( V_142 < 0 )
return V_142 ;
F_129 ( & V_244 ) ;
exp = F_218 ( V_140 , & V_24 , & V_4 ) ;
if ( ! exp ) {
F_131 ( & V_244 ) ;
V_142 = - V_206 ;
if ( V_109 -> V_208 & V_148 ) {
V_142 = F_216 ( V_140 , & V_24 , V_167 , V_205 ,
F_96 ( V_2 ) . V_107 ,
F_118 ( V_109 ) ) ;
}
return V_142 ;
}
V_142 = - V_263 ;
if ( ! ( V_109 -> V_208 & V_149 ) )
V_142 = F_212 ( exp , V_167 ) ;
F_131 ( & V_244 ) ;
return V_142 ;
}
static int
F_219 ( struct V_1 * V_2 , T_2 V_107 , T_2 V_91 , int V_217 ,
const struct V_264 * V_265 )
{
struct V_108 * V_109 ;
struct V_110 * V_111 ;
unsigned int V_112 = V_107 ? V_113 : 0 , V_114 ;
V_114 = ( V_115 << 8 | V_356 ) ;
V_109 = F_53 ( V_2 , V_107 , V_91 , V_114 , sizeof( * V_111 ) , V_112 ) ;
if ( V_109 == NULL )
goto V_117;
V_111 = F_54 ( V_109 ) ;
V_111 -> V_118 = V_267 ;
V_111 -> V_119 = V_120 ;
V_111 -> V_121 = F_14 ( V_217 ) ;
if ( F_16 ( V_2 , V_357 , F_17 ( V_265 -> V_358 ) ) ||
F_16 ( V_2 , V_359 , F_17 ( V_265 -> V_360 ) ) ||
F_16 ( V_2 , V_361 , F_17 ( V_265 -> V_362 ) ) )
goto V_12;
F_57 ( V_2 , V_109 ) ;
return V_2 -> V_77 ;
V_12:
V_117:
F_58 ( V_2 , V_109 ) ;
return - 1 ;
}
static int
F_220 ( struct V_1 * V_2 , struct V_163 * V_164 )
{
int V_217 ;
struct V_140 * V_140 = F_89 ( V_2 -> V_175 ) ;
if ( V_164 -> args [ 0 ] == V_220 )
return 0 ;
for ( V_217 = V_164 -> args [ 0 ] ; V_217 < V_220 ; V_217 ++ ) {
const struct V_264 * V_265 ;
if ( ! F_127 ( V_217 ) )
continue;
V_265 = F_128 ( V_140 -> V_29 . V_293 , V_217 ) ;
if ( F_219 ( V_2 , F_96 ( V_164 -> V_2 ) . V_107 ,
V_164 -> V_109 -> V_187 ,
V_217 , V_265 ) < 0 )
break;
}
V_164 -> args [ 0 ] = V_217 ;
return V_2 -> V_77 ;
}
static int
F_221 ( struct V_203 * V_204 , struct V_1 * V_2 ,
const struct V_108 * V_109 ,
const struct V_8 * const V_167 [] )
{
if ( V_109 -> V_208 & V_209 ) {
struct V_210 V_211 = {
. V_212 = F_220 ,
} ;
return F_123 ( V_204 , V_2 , V_109 , & V_211 ) ;
}
return 0 ;
}
static int T_8 F_222 ( struct V_140 * V_140 )
{
#ifdef F_223
int V_7 ;
V_7 = F_224 ( V_140 , & V_363 ) ;
if ( V_7 < 0 ) {
F_225 ( L_5 ) ;
goto V_353;
}
V_7 = F_226 ( V_140 , & V_364 ) ;
if ( V_7 < 0 ) {
F_225 ( L_6 ) ;
goto V_365;
}
#endif
return 0 ;
#ifdef F_223
V_365:
F_227 ( V_140 , & V_363 ) ;
V_353:
return V_7 ;
#endif
}
static void F_228 ( struct V_140 * V_140 )
{
#ifdef F_223
F_229 ( V_140 , & V_364 ) ;
F_227 ( V_140 , & V_363 ) ;
#endif
}
static void T_9 F_230 ( struct V_366 * V_367 )
{
struct V_140 * V_140 ;
F_231 (net, net_exit_list, exit_list)
F_228 ( V_140 ) ;
}
static int T_10 F_232 ( void )
{
int V_7 ;
F_233 ( L_7 , V_119 ) ;
V_7 = F_234 ( & V_368 ) ;
if ( V_7 < 0 ) {
F_225 ( L_8 ) ;
goto V_353;
}
V_7 = F_234 ( & V_369 ) ;
if ( V_7 < 0 ) {
F_225 ( L_9 ) ;
goto V_370;
}
V_7 = F_235 ( & V_371 ) ;
if ( V_7 < 0 ) {
F_225 ( L_10 ) ;
goto V_372;
}
#ifdef F_236
F_146 ( V_373 , & V_374 ) ;
#endif
return 0 ;
V_372:
F_237 ( & V_369 ) ;
V_370:
F_237 ( & V_368 ) ;
V_353:
return V_7 ;
}
static void T_11 F_238 ( void )
{
F_233 ( L_11 ) ;
F_239 ( & V_371 ) ;
F_237 ( & V_369 ) ;
F_237 ( & V_368 ) ;
#ifdef F_236
F_146 ( V_373 , NULL ) ;
#endif
}
