static int F_1 ( struct V_1 * V_2 ,
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
static int F_6 ( struct V_1 * V_2 ,
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
static int F_7 ( struct V_1 * V_2 ,
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
static int F_12 ( struct V_1 * V_2 , int V_22 ,
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
static int F_15 ( struct V_1 * V_2 , const struct V_28 * V_29 )
{
if ( F_16 ( V_2 , V_30 , F_17 ( V_29 -> V_31 ) ) )
goto V_12;
return 0 ;
V_12:
return - 1 ;
}
static int F_18 ( struct V_1 * V_2 , const struct V_28 * V_29 )
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
static int F_19 ( struct V_1 * V_2 , struct V_28 * V_29 )
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
static int F_22 ( struct V_1 * V_2 ,
const struct V_28 * V_29 )
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
if ( F_29 ( V_2 , V_63 , F_30 ( V_59 ) ,
V_64 ) ||
F_29 ( V_2 , V_65 , F_30 ( V_60 ) ,
V_64 ) )
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
if ( F_26 ( V_2 , V_50 , V_66 , type ) < 0 )
return - 1 ;
if ( F_26 ( V_2 , V_50 , V_67 , type ) < 0 )
return - 1 ;
return 0 ;
}
static int
F_33 ( struct V_1 * V_2 , const struct V_28 * V_29 )
{
struct V_8 * V_58 ;
const struct V_68 * V_69 ;
V_69 = F_34 ( V_29 ) ;
if ( ! V_69 )
return 0 ;
V_58 = F_2 ( V_2 , V_70 | V_11 ) ;
if ( ! V_58 )
goto V_12;
if ( F_29 ( V_2 , V_71 , F_30 ( V_69 -> V_72 ) ,
V_73 ) ||
( V_69 -> V_74 != 0 && F_29 ( V_2 , V_75 ,
F_30 ( V_69 -> V_74 ) ,
V_73 ) ) )
goto V_12;
F_5 ( V_2 , V_58 ) ;
return 0 ;
V_12:
return - 1 ;
}
static int F_35 ( struct V_1 * V_2 , const struct V_28 * V_29 )
{
if ( F_16 ( V_2 , V_76 , F_17 ( V_29 -> V_77 ) ) )
goto V_12;
return 0 ;
V_12:
return - 1 ;
}
static int F_36 ( struct V_1 * V_2 , const struct V_28 * V_29 )
{
struct V_8 * V_78 ;
int V_79 , V_7 ;
char * V_80 ;
V_7 = F_37 ( V_29 -> V_81 , & V_80 , & V_79 ) ;
if ( V_7 )
return 0 ;
V_7 = - 1 ;
V_78 = F_2 ( V_2 , V_82 | V_11 ) ;
if ( ! V_78 )
goto V_12;
if ( F_25 ( V_2 , V_83 , V_80 ) )
goto V_12;
F_5 ( V_2 , V_78 ) ;
V_7 = 0 ;
V_12:
F_38 ( V_80 , V_79 ) ;
return V_7 ;
}
static inline int F_39 ( const struct V_28 * V_29 )
{
struct V_84 * V_85 = F_40 ( V_29 ) ;
if ( ! V_85 )
return 0 ;
return F_41 ( sizeof( V_85 -> V_86 ) ) ;
}
static int
F_42 ( struct V_1 * V_2 , const struct V_28 * V_29 )
{
struct V_84 * V_85 = F_40 ( V_29 ) ;
unsigned int V_87 ;
if ( ! V_85 )
return 0 ;
V_87 = 0 ;
do {
if ( V_85 -> V_86 [ V_87 ] != 0 )
return F_43 ( V_2 , V_88 , sizeof( V_85 -> V_86 ) ,
V_85 -> V_86 ) ;
V_87 ++ ;
} while ( V_87 < F_44 ( V_85 -> V_86 ) );
return 0 ;
}
static int F_45 ( struct V_1 * V_2 , const struct V_28 * V_29 )
{
struct V_8 * V_9 ;
if ( ! ( V_29 -> V_31 & V_89 ) )
return 0 ;
V_9 = F_2 ( V_2 , V_90 | V_11 ) ;
if ( ! V_9 )
goto V_12;
if ( F_7 ( V_2 , F_46 ( V_29 ) ) < 0 )
goto V_12;
F_5 ( V_2 , V_9 ) ;
return 0 ;
V_12:
return - 1 ;
}
static int
F_47 ( struct V_1 * V_2 , const struct V_91 * V_92 , int type )
{
struct V_8 * V_9 ;
V_9 = F_2 ( V_2 , type | V_11 ) ;
if ( ! V_9 )
goto V_12;
if ( F_16 ( V_2 , V_93 ,
F_17 ( V_92 -> V_94 ) ) ||
F_16 ( V_2 , V_95 ,
F_17 ( V_92 -> V_96 ) ) ||
F_16 ( V_2 , V_97 ,
F_17 ( V_92 -> V_98 ) ) )
goto V_12;
F_5 ( V_2 , V_9 ) ;
return 0 ;
V_12:
return - 1 ;
}
static int F_48 ( struct V_1 * V_2 ,
const struct V_28 * V_29 )
{
struct V_99 * V_100 = F_49 ( V_29 ) ;
struct V_91 * V_92 ;
if ( ! ( V_29 -> V_31 & V_101 ) || ! V_100 )
return 0 ;
V_92 = & V_100 -> V_92 [ V_66 ] ;
if ( F_47 ( V_2 , V_92 , V_102 ) == - 1 )
return - 1 ;
V_92 = & V_100 -> V_92 [ V_67 ] ;
if ( F_47 ( V_2 , V_92 , V_103 ) == - 1 )
return - 1 ;
return 0 ;
}
static int F_50 ( struct V_1 * V_2 , const struct V_28 * V_29 )
{
if ( F_16 ( V_2 , V_104 , F_17 ( ( unsigned long ) V_29 ) ) )
goto V_12;
return 0 ;
V_12:
return - 1 ;
}
static int F_51 ( struct V_1 * V_2 , const struct V_28 * V_29 )
{
if ( F_16 ( V_2 , V_105 , F_17 ( F_52 ( & V_29 -> V_106 . V_107 ) ) ) )
goto V_12;
return 0 ;
V_12:
return - 1 ;
}
static int
F_53 ( struct V_1 * V_2 , T_2 V_108 , T_2 V_92 , T_2 type ,
struct V_28 * V_29 )
{
const struct V_23 * V_24 ;
struct V_109 * V_110 ;
struct V_111 * V_112 ;
struct V_8 * V_9 ;
unsigned int V_113 = V_108 ? V_114 : 0 , V_115 ;
V_115 = ( V_116 << 8 | V_117 ) ;
V_110 = F_54 ( V_2 , V_108 , V_92 , V_115 , sizeof( * V_112 ) , V_113 ) ;
if ( V_110 == NULL )
goto V_118;
V_112 = F_55 ( V_110 ) ;
V_112 -> V_119 = F_20 ( V_29 ) ;
V_112 -> V_120 = V_121 ;
V_112 -> V_122 = 0 ;
V_24 = F_56 ( V_29 ) ;
V_9 = F_2 ( V_2 , V_123 | V_11 ) ;
if ( ! V_9 )
goto V_12;
if ( F_7 ( V_2 , F_57 ( V_29 , V_66 ) ) < 0 )
goto V_12;
if ( F_12 ( V_2 , V_124 , V_24 ,
V_125 ) < 0 )
goto V_12;
F_5 ( V_2 , V_9 ) ;
V_9 = F_2 ( V_2 , V_126 | V_11 ) ;
if ( ! V_9 )
goto V_12;
if ( F_7 ( V_2 , F_57 ( V_29 , V_67 ) ) < 0 )
goto V_12;
if ( F_12 ( V_2 , V_124 , V_24 ,
V_127 ) < 0 )
goto V_12;
F_5 ( V_2 , V_9 ) ;
if ( F_12 ( V_2 , V_128 , V_24 ,
V_129 ) < 0 )
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
F_50 ( V_2 , V_29 ) < 0 ||
F_51 ( V_2 , V_29 ) < 0 ||
F_45 ( V_2 , V_29 ) < 0 ||
F_48 ( V_2 , V_29 ) < 0 )
goto V_12;
F_58 ( V_2 , V_110 ) ;
return V_2 -> V_79 ;
V_118:
V_12:
F_59 ( V_2 , V_110 ) ;
return - 1 ;
}
static inline T_3 F_60 ( const struct V_28 * V_29 )
{
struct V_17 * V_18 ;
struct V_5 * V_6 ;
T_3 V_79 = 0 ;
F_8 () ;
V_18 = F_9 ( F_20 ( V_29 ) ) ;
V_79 += V_18 -> V_130 ;
V_6 = F_10 ( F_20 ( V_29 ) , F_21 ( V_29 ) ) ;
V_79 += V_6 -> V_130 ;
F_11 () ;
return V_79 ;
}
static inline T_3 F_61 ( const struct V_28 * V_29 )
{
if ( ! F_62 ( V_29 , V_131 ) )
return 0 ;
return 2 * F_41 ( 0 )
+ 2 * F_63 ( sizeof( V_132 ) )
+ 2 * F_63 ( sizeof( V_132 ) )
;
}
static inline int F_64 ( const struct V_28 * V_29 )
{
#ifdef F_65
int V_79 , V_7 ;
V_7 = F_37 ( V_29 -> V_81 , NULL , & V_79 ) ;
if ( V_7 )
return 0 ;
return F_41 ( 0 )
+ F_41 ( sizeof( char ) * V_79 ) ;
#else
return 0 ;
#endif
}
static inline T_3 F_66 ( const struct V_28 * V_29 )
{
#ifdef F_67
if ( ! F_62 ( V_29 , V_133 ) )
return 0 ;
return F_41 ( 0 ) + 2 * F_63 ( sizeof( V_132 ) ) ;
#else
return 0 ;
#endif
}
static T_3 F_68 ( const struct V_28 * V_29 )
{
return F_69 ( sizeof( struct V_111 ) )
+ 3 * F_41 ( 0 )
+ 3 * F_41 ( 0 )
+ 3 * F_41 ( 0 )
+ 3 * F_41 ( sizeof( V_134 ) )
+ F_41 ( sizeof( V_135 ) )
+ F_41 ( sizeof( V_135 ) )
+ F_61 ( V_29 )
+ F_66 ( V_29 )
+ F_41 ( sizeof( V_135 ) )
+ F_41 ( 0 )
+ F_41 ( 0 )
+ F_41 ( V_136 )
+ F_64 ( V_29 )
#ifdef F_70
+ 2 * F_41 ( 0 )
+ 6 * F_41 ( sizeof( V_135 ) )
#endif
#ifdef F_71
+ F_41 ( sizeof( V_135 ) )
#endif
#ifdef F_72
+ F_41 ( sizeof( V_137 ) )
#endif
+ F_60 ( V_29 )
+ F_39 ( V_29 )
;
}
static int
F_73 ( unsigned int V_138 , struct V_139 * V_140 )
{
const struct V_23 * V_24 ;
struct V_141 * V_141 ;
struct V_109 * V_110 ;
struct V_111 * V_112 ;
struct V_8 * V_9 ;
struct V_28 * V_29 = V_140 -> V_29 ;
struct V_1 * V_2 ;
unsigned int type ;
unsigned int V_113 = 0 , V_142 ;
int V_143 ;
if ( F_74 ( V_29 ) )
return 0 ;
if ( V_138 & ( 1 << V_144 ) ) {
type = V_145 ;
V_142 = V_146 ;
} else if ( V_138 & ( ( 1 << V_147 ) | ( 1 << V_148 ) ) ) {
type = V_117 ;
V_113 = V_149 | V_150 ;
V_142 = V_151 ;
} else if ( V_138 ) {
type = V_117 ;
V_142 = V_152 ;
} else
return 0 ;
V_141 = F_75 ( V_29 ) ;
if ( ! V_140 -> V_153 && ! F_76 ( V_141 , V_142 ) )
return 0 ;
V_2 = F_77 ( F_68 ( V_29 ) , V_154 ) ;
if ( V_2 == NULL )
goto V_155;
type |= V_116 << 8 ;
V_110 = F_54 ( V_2 , V_140 -> V_108 , 0 , type , sizeof( * V_112 ) , V_113 ) ;
if ( V_110 == NULL )
goto V_118;
V_112 = F_55 ( V_110 ) ;
V_112 -> V_119 = F_20 ( V_29 ) ;
V_112 -> V_120 = V_121 ;
V_112 -> V_122 = 0 ;
F_8 () ;
V_24 = F_56 ( V_29 ) ;
V_9 = F_2 ( V_2 , V_123 | V_11 ) ;
if ( ! V_9 )
goto V_12;
if ( F_7 ( V_2 , F_57 ( V_29 , V_66 ) ) < 0 )
goto V_12;
if ( F_12 ( V_2 , V_124 , V_24 ,
V_125 ) < 0 )
goto V_12;
F_5 ( V_2 , V_9 ) ;
V_9 = F_2 ( V_2 , V_126 | V_11 ) ;
if ( ! V_9 )
goto V_12;
if ( F_7 ( V_2 , F_57 ( V_29 , V_67 ) ) < 0 )
goto V_12;
if ( F_12 ( V_2 , V_124 , V_24 ,
V_127 ) < 0 )
goto V_12;
F_5 ( V_2 , V_9 ) ;
if ( F_12 ( V_2 , V_128 , V_24 ,
V_129 ) < 0 )
goto V_12;
if ( F_50 ( V_2 , V_29 ) < 0 )
goto V_12;
if ( F_15 ( V_2 , V_29 ) < 0 )
goto V_12;
if ( V_138 & ( 1 << V_144 ) ) {
if ( F_31 ( V_2 , V_29 , type ) < 0 ||
F_33 ( V_2 , V_29 ) < 0 )
goto V_12;
} else {
if ( F_18 ( V_2 , V_29 ) < 0 )
goto V_12;
if ( V_138 & ( 1 << V_156 )
&& F_19 ( V_2 , V_29 ) < 0 )
goto V_12;
if ( ( V_138 & ( 1 << V_157 ) || F_23 ( V_29 ) )
&& F_22 ( V_2 , V_29 ) < 0 )
goto V_12;
#ifdef F_65
if ( ( V_138 & ( 1 << V_158 ) || V_29 -> V_81 )
&& F_36 ( V_2 , V_29 ) < 0 )
goto V_12;
#endif
if ( V_138 & ( 1 << V_159 ) &&
F_42 ( V_2 , V_29 ) < 0 )
goto V_12;
if ( V_138 & ( 1 << V_148 ) &&
F_45 ( V_2 , V_29 ) < 0 )
goto V_12;
if ( V_138 & ( 1 << V_160 ) &&
F_48 ( V_2 , V_29 ) < 0 )
goto V_12;
}
#ifdef F_71
if ( ( V_138 & ( 1 << V_161 ) || V_29 -> V_77 )
&& F_35 ( V_2 , V_29 ) < 0 )
goto V_12;
#endif
F_11 () ;
F_58 ( V_2 , V_110 ) ;
V_143 = F_78 ( V_2 , V_141 , V_140 -> V_108 , V_142 , V_140 -> V_153 ,
V_154 ) ;
if ( V_143 == - V_162 || V_143 == - V_163 )
return - V_162 ;
return 0 ;
V_12:
F_11 () ;
F_59 ( V_2 , V_110 ) ;
V_118:
F_79 ( V_2 ) ;
V_155:
if ( F_80 ( V_141 , 0 , V_142 , - V_162 ) > 0 )
return - V_162 ;
return 0 ;
}
static int F_81 ( struct V_164 * V_165 )
{
if ( V_165 -> args [ 1 ] )
F_82 ( (struct V_28 * ) V_165 -> args [ 1 ] ) ;
F_83 ( V_165 -> V_166 ) ;
return 0 ;
}
static struct V_167 *
F_84 ( const struct V_8 * const V_168 [] )
{
#ifdef F_71
struct V_167 * V_169 ;
V_169 = F_85 ( sizeof( * V_169 ) , V_170 ) ;
if ( V_169 == NULL )
return F_86 ( - V_171 ) ;
V_169 -> V_77 . V_172 = F_87 ( F_88 ( V_168 [ V_76 ] ) ) ;
V_169 -> V_77 . V_173 = F_87 ( F_88 ( V_168 [ V_174 ] ) ) ;
return V_169 ;
#else
return F_86 ( - V_175 ) ;
#endif
}
static int F_89 ( struct V_28 * V_29 , void * V_166 )
{
struct V_167 * V_169 = V_166 ;
if ( V_169 == NULL )
return 1 ;
#ifdef F_71
if ( ( V_29 -> V_77 & V_169 -> V_77 . V_173 ) == V_169 -> V_77 . V_172 )
return 1 ;
#endif
return 0 ;
}
static int
F_90 ( struct V_1 * V_2 , struct V_164 * V_165 )
{
struct V_141 * V_141 = F_91 ( V_2 -> V_176 ) ;
struct V_28 * V_29 , * V_177 ;
struct V_178 * V_179 ;
struct V_180 * V_181 ;
struct V_111 * V_112 = F_55 ( V_165 -> V_110 ) ;
V_134 V_18 = V_112 -> V_119 ;
int V_182 ;
T_4 * V_183 ;
V_177 = (struct V_28 * ) V_165 -> args [ 1 ] ;
F_92 () ;
for (; V_165 -> args [ 0 ] < V_184 ; V_165 -> args [ 0 ] ++ ) {
V_185:
V_183 = & V_186 [ V_165 -> args [ 0 ] % V_187 ] ;
F_93 ( V_183 ) ;
if ( V_165 -> args [ 0 ] >= V_184 ) {
F_94 ( V_183 ) ;
goto V_45;
}
F_95 (h, n, &nf_conntrack_hash[cb->args[0]],
hnnode) {
if ( F_96 ( V_179 ) != V_66 )
continue;
V_29 = F_97 ( V_179 ) ;
if ( ! F_98 ( V_141 , F_75 ( V_29 ) ) )
continue;
if ( V_18 && F_20 ( V_29 ) != V_18 )
continue;
if ( V_165 -> args [ 1 ] ) {
if ( V_29 != V_177 )
continue;
V_165 -> args [ 1 ] = 0 ;
}
if ( ! F_89 ( V_29 , V_165 -> V_166 ) )
continue;
F_8 () ;
V_182 =
F_53 ( V_2 , F_99 ( V_165 -> V_2 ) . V_108 ,
V_165 -> V_110 -> V_188 ,
F_100 ( V_165 -> V_110 -> V_189 ) ,
V_29 ) ;
F_11 () ;
if ( V_182 < 0 ) {
F_101 ( & V_29 -> V_106 ) ;
V_165 -> args [ 1 ] = ( unsigned long ) V_29 ;
F_94 ( V_183 ) ;
goto V_45;
}
}
F_94 ( V_183 ) ;
if ( V_165 -> args [ 1 ] ) {
V_165 -> args [ 1 ] = 0 ;
goto V_185;
}
}
V_45:
F_102 () ;
if ( V_177 )
F_82 ( V_177 ) ;
return V_2 -> V_79 ;
}
static int F_103 ( struct V_8 * V_53 ,
struct V_3 * V_4 )
{
struct V_8 * V_190 [ V_191 + 1 ] ;
struct V_17 * V_18 ;
int V_7 = 0 ;
V_7 = F_104 ( V_190 , V_191 , V_53 , NULL ) ;
if ( V_7 < 0 )
return V_7 ;
F_8 () ;
V_18 = F_9 ( V_4 -> V_20 . V_21 ) ;
if ( F_4 ( V_18 -> V_192 ) ) {
V_7 = F_105 ( V_53 , V_191 ,
V_18 -> V_193 ) ;
if ( V_7 == 0 )
V_7 = V_18 -> V_192 ( V_190 , V_4 ) ;
}
F_11 () ;
return V_7 ;
}
static int F_106 ( struct V_8 * V_53 ,
struct V_3 * V_4 )
{
struct V_8 * V_190 [ V_194 + 1 ] ;
struct V_5 * V_6 ;
int V_7 = 0 ;
V_7 = F_104 ( V_190 , V_194 , V_53 , V_195 ) ;
if ( V_7 < 0 )
return V_7 ;
if ( ! V_190 [ V_13 ] )
return - V_196 ;
V_4 -> V_14 . V_15 = F_107 ( V_190 [ V_13 ] ) ;
F_8 () ;
V_6 = F_10 ( V_4 -> V_20 . V_21 , V_4 -> V_14 . V_15 ) ;
if ( F_4 ( V_6 -> V_192 ) ) {
V_7 = F_105 ( V_53 , V_194 ,
V_6 -> V_193 ) ;
if ( V_7 == 0 )
V_7 = V_6 -> V_192 ( V_190 , V_4 ) ;
}
F_11 () ;
return V_7 ;
}
static int
F_108 ( const struct V_8 * V_53 ,
struct V_23 * V_24 )
{
F_109 ( V_24 , V_27 ,
V_129 , 0 ) ;
#ifdef F_72
if ( V_53 )
V_24 -> V_26 = F_110 ( F_111 ( V_53 ) ) ;
#else
if ( V_53 )
return - V_175 ;
#endif
return 0 ;
}
static int
F_112 ( struct V_8 * V_53 , enum V_52 type ,
struct V_23 * V_24 )
{
int V_7 ;
if ( V_24 -> V_26 != V_27 )
return - V_196 ;
V_7 = F_108 ( V_53 , V_24 ) ;
if ( V_7 < 0 )
return V_7 ;
if ( type == V_126 )
V_24 -> V_25 = V_127 ;
else
V_24 -> V_25 = V_125 ;
return 0 ;
}
static int
F_113 ( const struct V_8 * const V_168 [] ,
struct V_3 * V_4 ,
enum V_52 type , V_134 V_21 ,
struct V_23 * V_24 )
{
struct V_8 * V_190 [ V_197 + 1 ] ;
int V_143 ;
memset ( V_4 , 0 , sizeof( * V_4 ) ) ;
V_143 = F_104 ( V_190 , V_197 , V_168 [ type ] , V_198 ) ;
if ( V_143 < 0 )
return V_143 ;
if ( ! V_190 [ V_19 ] )
return - V_196 ;
V_4 -> V_20 . V_21 = V_21 ;
V_143 = F_103 ( V_190 [ V_19 ] , V_4 ) ;
if ( V_143 < 0 )
return V_143 ;
if ( ! V_190 [ V_10 ] )
return - V_196 ;
V_143 = F_106 ( V_190 [ V_10 ] , V_4 ) ;
if ( V_143 < 0 )
return V_143 ;
if ( V_190 [ V_124 ] ) {
if ( ! V_24 )
return - V_196 ;
V_143 = F_112 ( V_190 [ V_124 ] ,
type , V_24 ) ;
if ( V_143 < 0 )
return V_143 ;
}
if ( type == V_126 )
V_4 -> V_14 . V_25 = V_67 ;
else
V_4 -> V_14 . V_25 = V_66 ;
return 0 ;
}
static int F_114 ( const struct V_8 * V_53 , char * * V_199 ,
struct V_8 * * V_200 )
{
int V_143 ;
struct V_8 * V_190 [ V_201 + 1 ] ;
V_143 = F_104 ( V_190 , V_201 , V_53 , V_202 ) ;
if ( V_143 < 0 )
return V_143 ;
if ( ! V_190 [ V_47 ] )
return - V_196 ;
* V_199 = F_115 ( V_190 [ V_47 ] ) ;
if ( V_190 [ V_203 ] )
* V_200 = V_190 [ V_203 ] ;
return 0 ;
}
static int F_116 ( struct V_141 * V_141 ,
const struct V_8 * const V_168 [] ,
T_2 V_108 , int V_153 )
{
struct V_167 * V_169 = NULL ;
if ( V_168 [ V_76 ] && V_168 [ V_174 ] ) {
V_169 = F_84 ( V_168 ) ;
if ( F_117 ( V_169 ) )
return F_118 ( V_169 ) ;
}
F_119 ( V_141 , F_89 , V_169 ,
V_108 , V_153 ) ;
F_83 ( V_169 ) ;
return 0 ;
}
static int F_120 ( struct V_141 * V_141 , struct V_204 * V_205 ,
struct V_1 * V_2 ,
const struct V_109 * V_110 ,
const struct V_8 * const V_168 [] )
{
struct V_178 * V_179 ;
struct V_3 V_4 ;
struct V_28 * V_29 ;
struct V_111 * V_112 = F_55 ( V_110 ) ;
V_134 V_206 = V_112 -> V_119 ;
struct V_23 V_24 ;
int V_143 ;
V_143 = F_108 ( V_168 [ V_128 ] , & V_24 ) ;
if ( V_143 < 0 )
return V_143 ;
if ( V_168 [ V_123 ] )
V_143 = F_113 ( V_168 , & V_4 , V_123 ,
V_206 , & V_24 ) ;
else if ( V_168 [ V_126 ] )
V_143 = F_113 ( V_168 , & V_4 , V_126 ,
V_206 , & V_24 ) ;
else {
return F_116 ( V_141 , V_168 ,
F_99 ( V_2 ) . V_108 ,
F_121 ( V_110 ) ) ;
}
if ( V_143 < 0 )
return V_143 ;
V_179 = F_122 ( V_141 , & V_24 , & V_4 ) ;
if ( ! V_179 )
return - V_207 ;
V_29 = F_97 ( V_179 ) ;
if ( V_168 [ V_104 ] ) {
V_135 V_26 = F_87 ( F_88 ( V_168 [ V_104 ] ) ) ;
if ( V_26 != ( T_2 ) ( unsigned long ) V_29 ) {
F_82 ( V_29 ) ;
return - V_207 ;
}
}
if ( F_123 ( & V_29 -> V_32 ) )
F_124 ( V_29 , F_99 ( V_2 ) . V_108 , F_121 ( V_110 ) ) ;
F_82 ( V_29 ) ;
return 0 ;
}
static int F_125 ( struct V_141 * V_141 , struct V_204 * V_205 ,
struct V_1 * V_2 ,
const struct V_109 * V_110 ,
const struct V_8 * const V_168 [] )
{
struct V_178 * V_179 ;
struct V_3 V_4 ;
struct V_28 * V_29 ;
struct V_1 * V_208 = NULL ;
struct V_111 * V_112 = F_55 ( V_110 ) ;
V_134 V_206 = V_112 -> V_119 ;
struct V_23 V_24 ;
int V_143 ;
if ( V_110 -> V_209 & V_210 ) {
struct V_211 V_212 = {
. V_213 = F_90 ,
. V_214 = F_81 ,
} ;
if ( V_168 [ V_76 ] && V_168 [ V_174 ] ) {
struct V_167 * V_169 ;
V_169 = F_84 ( V_168 ) ;
if ( F_117 ( V_169 ) )
return F_118 ( V_169 ) ;
V_212 . V_166 = V_169 ;
}
return F_126 ( V_205 , V_2 , V_110 , & V_212 ) ;
}
V_143 = F_108 ( V_168 [ V_128 ] , & V_24 ) ;
if ( V_143 < 0 )
return V_143 ;
if ( V_168 [ V_123 ] )
V_143 = F_113 ( V_168 , & V_4 , V_123 ,
V_206 , & V_24 ) ;
else if ( V_168 [ V_126 ] )
V_143 = F_113 ( V_168 , & V_4 , V_126 ,
V_206 , & V_24 ) ;
else
return - V_196 ;
if ( V_143 < 0 )
return V_143 ;
V_179 = F_122 ( V_141 , & V_24 , & V_4 ) ;
if ( ! V_179 )
return - V_207 ;
V_29 = F_97 ( V_179 ) ;
V_143 = - V_171 ;
V_208 = F_77 ( V_215 , V_170 ) ;
if ( V_208 == NULL ) {
F_82 ( V_29 ) ;
return - V_171 ;
}
F_8 () ;
V_143 = F_53 ( V_208 , F_99 ( V_2 ) . V_108 , V_110 -> V_188 ,
F_100 ( V_110 -> V_189 ) , V_29 ) ;
F_11 () ;
F_82 ( V_29 ) ;
if ( V_143 <= 0 )
goto free;
V_143 = F_127 ( V_205 , V_208 , F_99 ( V_2 ) . V_108 , V_216 ) ;
if ( V_143 < 0 )
goto V_45;
return 0 ;
free:
F_79 ( V_208 ) ;
V_45:
return V_143 == - V_163 ? - V_162 : V_143 ;
}
static int F_128 ( struct V_164 * V_165 )
{
if ( V_165 -> args [ 1 ] )
F_82 ( (struct V_28 * ) V_165 -> args [ 1 ] ) ;
return 0 ;
}
static int
F_129 ( struct V_1 * V_2 , struct V_164 * V_165 , bool V_217 )
{
struct V_28 * V_29 , * V_177 ;
struct V_178 * V_179 ;
struct V_180 * V_181 ;
struct V_111 * V_112 = F_55 ( V_165 -> V_110 ) ;
V_134 V_18 = V_112 -> V_119 ;
int V_182 ;
int V_218 ;
struct V_219 * V_220 ;
struct V_141 * V_141 = F_91 ( V_2 -> V_176 ) ;
if ( V_165 -> args [ 2 ] )
return 0 ;
V_177 = (struct V_28 * ) V_165 -> args [ 1 ] ;
for ( V_218 = V_165 -> args [ 0 ] ; V_218 < V_221 ; V_218 ++ ) {
struct V_222 * V_223 ;
if ( ! F_130 ( V_218 ) )
continue;
V_223 = F_131 ( V_141 -> V_29 . V_224 , V_218 ) ;
F_132 ( & V_223 -> V_225 ) ;
V_220 = V_217 ? & V_223 -> V_217 : & V_223 -> V_226 ;
V_185:
F_95 (h, n, list, hnnode) {
V_29 = F_97 ( V_179 ) ;
if ( V_18 && F_20 ( V_29 ) != V_18 )
continue;
if ( V_165 -> args [ 1 ] ) {
if ( V_29 != V_177 )
continue;
V_165 -> args [ 1 ] = 0 ;
}
F_8 () ;
V_182 = F_53 ( V_2 , F_99 ( V_165 -> V_2 ) . V_108 ,
V_165 -> V_110 -> V_188 ,
F_100 ( V_165 -> V_110 -> V_189 ) ,
V_29 ) ;
F_11 () ;
if ( V_182 < 0 ) {
if ( ! F_133 ( & V_29 -> V_106 . V_107 ) )
continue;
V_165 -> args [ 0 ] = V_218 ;
V_165 -> args [ 1 ] = ( unsigned long ) V_29 ;
F_134 ( & V_223 -> V_225 ) ;
goto V_45;
}
}
if ( V_165 -> args [ 1 ] ) {
V_165 -> args [ 1 ] = 0 ;
goto V_185;
}
F_134 ( & V_223 -> V_225 ) ;
}
V_165 -> args [ 2 ] = 1 ;
V_45:
if ( V_177 )
F_82 ( V_177 ) ;
return V_2 -> V_79 ;
}
static int
F_135 ( struct V_1 * V_2 , struct V_164 * V_165 )
{
return F_129 ( V_2 , V_165 , true ) ;
}
static int F_136 ( struct V_141 * V_141 , struct V_204 * V_205 ,
struct V_1 * V_2 ,
const struct V_109 * V_110 ,
const struct V_8 * const V_168 [] )
{
if ( V_110 -> V_209 & V_210 ) {
struct V_211 V_212 = {
. V_213 = F_135 ,
. V_214 = F_128 ,
} ;
return F_126 ( V_205 , V_2 , V_110 , & V_212 ) ;
}
return - V_175 ;
}
static int
F_137 ( struct V_1 * V_2 , struct V_164 * V_165 )
{
return F_129 ( V_2 , V_165 , false ) ;
}
static int F_138 ( struct V_141 * V_141 , struct V_204 * V_205 ,
struct V_1 * V_2 ,
const struct V_109 * V_110 ,
const struct V_8 * const V_168 [] )
{
if ( V_110 -> V_209 & V_210 ) {
struct V_211 V_212 = {
. V_213 = F_137 ,
. V_214 = F_128 ,
} ;
return F_126 ( V_205 , V_2 , V_110 , & V_212 ) ;
}
return - V_175 ;
}
static int
F_139 ( struct V_28 * V_29 ,
enum V_227 V_228 ,
const struct V_8 * V_53 )
{
F_140 (nfnetlink_parse_nat_setup_hook) V_229 ;
int V_143 ;
V_229 = F_24 ( V_230 ) ;
if ( ! V_229 ) {
#ifdef F_141
F_11 () ;
F_142 ( V_116 ) ;
if ( F_143 ( L_1 ) < 0 ) {
F_144 ( V_116 ) ;
F_8 () ;
return - V_175 ;
}
F_144 ( V_116 ) ;
F_8 () ;
if ( V_230 )
return - V_163 ;
#endif
return - V_175 ;
}
V_143 = V_229 ( V_29 , V_228 , V_53 ) ;
if ( V_143 == - V_163 ) {
#ifdef F_141
F_11 () ;
F_142 ( V_116 ) ;
if ( F_143 ( L_2 , F_20 ( V_29 ) ) < 0 ) {
F_144 ( V_116 ) ;
F_8 () ;
return - V_175 ;
}
F_144 ( V_116 ) ;
F_8 () ;
#else
V_143 = - V_175 ;
#endif
}
return V_143 ;
}
static int
F_145 ( struct V_28 * V_29 , const struct V_8 * const V_168 [] )
{
unsigned long V_231 ;
unsigned int V_31 = F_87 ( F_88 ( V_168 [ V_30 ] ) ) ;
V_231 = V_29 -> V_31 ^ V_31 ;
if ( V_231 & ( V_89 | V_232 | V_233 ) )
return - V_234 ;
if ( V_231 & V_235 && ! ( V_31 & V_235 ) )
return - V_234 ;
if ( V_231 & V_236 && ! ( V_31 & V_236 ) )
return - V_234 ;
V_29 -> V_31 |= V_31 & ~ ( V_237 | V_238 ) ;
return 0 ;
}
static int
F_146 ( struct V_28 * V_29 , const struct V_8 * const V_168 [] )
{
#ifdef F_70
int V_7 ;
if ( ! V_168 [ V_239 ] && ! V_168 [ V_240 ] )
return 0 ;
V_7 = F_139 ( V_29 , V_241 ,
V_168 [ V_239 ] ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_139 ( V_29 , V_242 ,
V_168 [ V_240 ] ) ;
return V_7 ;
#else
if ( ! V_168 [ V_239 ] && ! V_168 [ V_240 ] )
return 0 ;
return - V_175 ;
#endif
}
static int F_147 ( struct V_28 * V_29 ,
const struct V_8 * const V_168 [] )
{
struct V_43 * V_44 ;
struct V_41 * V_42 = F_23 ( V_29 ) ;
char * V_243 = NULL ;
struct V_8 * V_200 = NULL ;
int V_143 ;
if ( V_29 -> V_244 )
return - V_234 ;
V_143 = F_114 ( V_168 [ V_46 ] , & V_243 , & V_200 ) ;
if ( V_143 < 0 )
return V_143 ;
if ( ! strcmp ( V_243 , L_3 ) ) {
if ( V_42 && V_42 -> V_44 ) {
F_148 ( V_29 ) ;
F_149 ( V_42 -> V_44 , NULL ) ;
}
return 0 ;
}
V_44 = F_150 ( V_243 , F_20 ( V_29 ) ,
F_21 ( V_29 ) ) ;
if ( V_44 == NULL ) {
#ifdef F_141
F_134 ( & V_245 ) ;
if ( F_143 ( L_4 , V_243 ) < 0 ) {
F_132 ( & V_245 ) ;
return - V_175 ;
}
F_132 ( & V_245 ) ;
V_44 = F_150 ( V_243 , F_20 ( V_29 ) ,
F_21 ( V_29 ) ) ;
if ( V_44 )
return - V_163 ;
#endif
return - V_175 ;
}
if ( V_42 ) {
if ( V_42 -> V_44 == V_44 ) {
if ( V_44 -> V_246 )
V_44 -> V_246 ( V_200 , V_29 ) ;
return 0 ;
} else
return - V_234 ;
}
return - V_175 ;
}
static int F_151 ( struct V_28 * V_29 ,
const struct V_8 * const V_168 [] )
{
V_135 V_32 = F_87 ( F_88 ( V_168 [ V_36 ] ) ) ;
if ( ! F_123 ( & V_29 -> V_32 ) )
return - V_247 ;
V_29 -> V_32 . V_33 = V_34 + V_32 * V_35 ;
F_152 ( & V_29 -> V_32 ) ;
return 0 ;
}
static int F_153 ( struct V_28 * V_29 ,
const struct V_8 * const V_168 [] )
{
const struct V_8 * V_53 = V_168 [ V_39 ] ;
struct V_8 * V_190 [ V_248 + 1 ] ;
struct V_5 * V_6 ;
int V_143 = 0 ;
V_143 = F_104 ( V_190 , V_248 , V_53 , V_249 ) ;
if ( V_143 < 0 )
return V_143 ;
F_8 () ;
V_6 = F_10 ( F_20 ( V_29 ) , F_21 ( V_29 ) ) ;
if ( V_6 -> V_246 )
V_143 = V_6 -> V_246 ( V_190 , V_29 ) ;
F_11 () ;
return V_143 ;
}
static int F_154 ( struct V_91 * V_92 ,
const struct V_8 * const V_53 )
{
int V_143 ;
struct V_8 * V_168 [ V_250 + 1 ] ;
V_143 = F_104 ( V_168 , V_250 , V_53 , V_251 ) ;
if ( V_143 < 0 )
return V_143 ;
if ( ! V_168 [ V_93 ] )
return - V_196 ;
V_92 -> V_94 =
F_87 ( F_88 ( V_168 [ V_93 ] ) ) ;
if ( ! V_168 [ V_95 ] )
return - V_196 ;
V_92 -> V_96 =
F_87 ( F_88 ( V_168 [ V_95 ] ) ) ;
if ( ! V_168 [ V_97 ] )
return - V_196 ;
V_92 -> V_98 =
F_87 ( F_88 ( V_168 [ V_97 ] ) ) ;
return 0 ;
}
static int
F_155 ( struct V_28 * V_29 ,
const struct V_8 * const V_168 [] )
{
struct V_99 * V_100 = F_49 ( V_29 ) ;
int V_7 = 0 ;
if ( ! V_100 )
return 0 ;
if ( V_168 [ V_102 ] ) {
V_7 = F_154 ( & V_100 -> V_92 [ V_66 ] ,
V_168 [ V_102 ] ) ;
if ( V_7 < 0 )
return V_7 ;
V_29 -> V_31 |= V_101 ;
}
if ( V_168 [ V_103 ] ) {
V_7 = F_154 ( & V_100 -> V_92 [ V_67 ] ,
V_168 [ V_103 ] ) ;
if ( V_7 < 0 )
return V_7 ;
V_29 -> V_31 |= V_101 ;
}
return 0 ;
}
static int
F_156 ( struct V_28 * V_29 , const struct V_8 * const V_168 [] )
{
#ifdef F_157
T_3 V_79 = F_158 ( V_168 [ V_88 ] ) ;
const void * V_173 = V_168 [ V_252 ] ;
if ( V_79 & ( sizeof( T_2 ) - 1 ) )
return - V_196 ;
if ( V_173 ) {
if ( F_158 ( V_168 [ V_252 ] ) == 0 ||
F_158 ( V_168 [ V_252 ] ) != V_79 )
return - V_196 ;
V_173 = F_115 ( V_168 [ V_252 ] ) ;
}
V_79 /= sizeof( T_2 ) ;
return F_159 ( V_29 , F_115 ( V_168 [ V_88 ] ) , V_173 , V_79 ) ;
#else
return - V_175 ;
#endif
}
static int
F_160 ( struct V_28 * V_29 ,
const struct V_8 * const V_168 [] )
{
int V_143 ;
if ( V_168 [ V_240 ] || V_168 [ V_239 ] || V_168 [ V_90 ] )
return - V_175 ;
if ( V_168 [ V_46 ] ) {
V_143 = F_147 ( V_29 , V_168 ) ;
if ( V_143 < 0 )
return V_143 ;
}
if ( V_168 [ V_36 ] ) {
V_143 = F_151 ( V_29 , V_168 ) ;
if ( V_143 < 0 )
return V_143 ;
}
if ( V_168 [ V_30 ] ) {
V_143 = F_145 ( V_29 , V_168 ) ;
if ( V_143 < 0 )
return V_143 ;
}
if ( V_168 [ V_39 ] ) {
V_143 = F_153 ( V_29 , V_168 ) ;
if ( V_143 < 0 )
return V_143 ;
}
#if F_161 ( F_71 )
if ( V_168 [ V_76 ] )
V_29 -> V_77 = F_87 ( F_88 ( V_168 [ V_76 ] ) ) ;
#endif
if ( V_168 [ V_102 ] || V_168 [ V_103 ] ) {
V_143 = F_155 ( V_29 , V_168 ) ;
if ( V_143 < 0 )
return V_143 ;
}
if ( V_168 [ V_88 ] ) {
V_143 = F_156 ( V_29 , V_168 ) ;
if ( V_143 < 0 )
return V_143 ;
}
return 0 ;
}
static struct V_28 *
F_162 ( struct V_141 * V_141 ,
const struct V_23 * V_24 ,
const struct V_8 * const V_168 [] ,
struct V_3 * V_253 ,
struct V_3 * V_254 ,
T_5 V_206 )
{
struct V_28 * V_29 ;
int V_143 = - V_196 ;
struct V_43 * V_44 ;
struct V_68 * V_69 ;
V_29 = F_163 ( V_141 , V_24 , V_253 , V_254 , V_154 ) ;
if ( F_117 ( V_29 ) )
return F_86 ( - V_171 ) ;
if ( ! V_168 [ V_36 ] )
goto V_255;
V_29 -> V_32 . V_33 = F_87 ( F_88 ( V_168 [ V_36 ] ) ) ;
V_29 -> V_32 . V_33 = V_34 + V_29 -> V_32 . V_33 * V_35 ;
F_8 () ;
if ( V_168 [ V_46 ] ) {
char * V_243 = NULL ;
struct V_8 * V_200 = NULL ;
V_143 = F_114 ( V_168 [ V_46 ] , & V_243 , & V_200 ) ;
if ( V_143 < 0 )
goto V_256;
V_44 = F_150 ( V_243 , F_20 ( V_29 ) ,
F_21 ( V_29 ) ) ;
if ( V_44 == NULL ) {
F_11 () ;
#ifdef F_141
if ( F_143 ( L_4 , V_243 ) < 0 ) {
V_143 = - V_175 ;
goto V_255;
}
F_8 () ;
V_44 = F_150 ( V_243 ,
F_20 ( V_29 ) ,
F_21 ( V_29 ) ) ;
if ( V_44 ) {
V_143 = - V_163 ;
goto V_256;
}
F_11 () ;
#endif
V_143 = - V_175 ;
goto V_255;
} else {
struct V_41 * V_42 ;
V_42 = F_164 ( V_29 , V_44 , V_154 ) ;
if ( V_42 == NULL ) {
V_143 = - V_171 ;
goto V_256;
}
if ( V_44 -> V_246 )
V_44 -> V_246 ( V_200 , V_29 ) ;
F_149 ( V_42 -> V_44 , V_44 ) ;
}
} else {
V_143 = F_165 ( V_29 , NULL , V_154 ) ;
if ( V_143 < 0 )
goto V_256;
}
V_143 = F_146 ( V_29 , V_168 ) ;
if ( V_143 < 0 )
goto V_256;
F_166 ( V_29 , V_154 ) ;
F_167 ( V_29 , V_154 ) ;
F_168 ( V_29 , 0 , 0 , V_154 ) ;
F_169 ( V_29 ) ;
V_29 -> V_31 |= V_232 ;
if ( V_168 [ V_30 ] ) {
V_143 = F_145 ( V_29 , V_168 ) ;
if ( V_143 < 0 )
goto V_256;
}
if ( V_168 [ V_102 ] || V_168 [ V_103 ] ) {
V_143 = F_155 ( V_29 , V_168 ) ;
if ( V_143 < 0 )
goto V_256;
}
memset ( & V_29 -> V_257 , 0 , sizeof( V_29 -> V_257 ) ) ;
if ( V_168 [ V_39 ] ) {
V_143 = F_153 ( V_29 , V_168 ) ;
if ( V_143 < 0 )
goto V_256;
}
#if F_161 ( F_71 )
if ( V_168 [ V_76 ] )
V_29 -> V_77 = F_87 ( F_88 ( V_168 [ V_76 ] ) ) ;
#endif
if ( V_168 [ V_90 ] ) {
struct V_3 V_244 ;
struct V_178 * V_258 ;
struct V_28 * V_259 ;
V_143 = F_113 ( V_168 , & V_244 , V_90 ,
V_206 , NULL ) ;
if ( V_143 < 0 )
goto V_256;
V_258 = F_122 ( V_141 , V_24 , & V_244 ) ;
if ( V_258 == NULL ) {
V_143 = - V_207 ;
goto V_256;
}
V_259 = F_97 ( V_258 ) ;
F_170 ( V_260 , & V_29 -> V_31 ) ;
V_29 -> V_244 = V_259 ;
}
V_69 = F_34 ( V_29 ) ;
if ( V_69 )
V_69 -> V_72 = F_171 () ;
V_143 = F_172 ( V_29 ) ;
if ( V_143 < 0 )
goto V_256;
F_11 () ;
return V_29 ;
V_256:
F_11 () ;
V_255:
F_173 ( V_29 ) ;
return F_86 ( V_143 ) ;
}
static int F_174 ( struct V_141 * V_141 , struct V_204 * V_205 ,
struct V_1 * V_2 ,
const struct V_109 * V_110 ,
const struct V_8 * const V_168 [] )
{
struct V_3 V_253 , V_254 ;
struct V_178 * V_179 = NULL ;
struct V_111 * V_112 = F_55 ( V_110 ) ;
struct V_28 * V_29 ;
V_134 V_206 = V_112 -> V_119 ;
struct V_23 V_24 ;
int V_143 ;
V_143 = F_108 ( V_168 [ V_128 ] , & V_24 ) ;
if ( V_143 < 0 )
return V_143 ;
if ( V_168 [ V_123 ] ) {
V_143 = F_113 ( V_168 , & V_253 , V_123 ,
V_206 , & V_24 ) ;
if ( V_143 < 0 )
return V_143 ;
}
if ( V_168 [ V_126 ] ) {
V_143 = F_113 ( V_168 , & V_254 , V_126 ,
V_206 , & V_24 ) ;
if ( V_143 < 0 )
return V_143 ;
}
if ( V_168 [ V_123 ] )
V_179 = F_122 ( V_141 , & V_24 , & V_253 ) ;
else if ( V_168 [ V_126 ] )
V_179 = F_122 ( V_141 , & V_24 , & V_254 ) ;
if ( V_179 == NULL ) {
V_143 = - V_207 ;
if ( V_110 -> V_209 & V_149 ) {
enum V_261 V_138 ;
if ( ! V_168 [ V_123 ] || ! V_168 [ V_126 ] )
return - V_196 ;
if ( V_253 . V_14 . V_15 != V_254 . V_14 . V_15 )
return - V_196 ;
V_29 = F_162 ( V_141 , & V_24 , V_168 , & V_253 ,
& V_254 , V_206 ) ;
if ( F_117 ( V_29 ) )
return F_118 ( V_29 ) ;
V_143 = 0 ;
if ( F_175 ( V_260 , & V_29 -> V_31 ) )
V_138 = V_148 ;
else
V_138 = V_147 ;
if ( V_168 [ V_88 ] &&
F_156 ( V_29 , V_168 ) == 0 )
V_138 |= ( 1 << V_159 ) ;
F_176 ( ( 1 << V_262 ) |
( 1 << V_263 ) |
( 1 << V_157 ) |
( 1 << V_156 ) |
( 1 << V_160 ) |
( 1 << V_161 ) | V_138 ,
V_29 , F_99 ( V_2 ) . V_108 ,
F_121 ( V_110 ) ) ;
F_82 ( V_29 ) ;
}
return V_143 ;
}
V_143 = - V_264 ;
V_29 = F_97 ( V_179 ) ;
if ( ! ( V_110 -> V_209 & V_150 ) ) {
F_132 ( & V_245 ) ;
V_143 = F_160 ( V_29 , V_168 ) ;
F_134 ( & V_245 ) ;
if ( V_143 == 0 ) {
F_176 ( ( 1 << V_262 ) |
( 1 << V_263 ) |
( 1 << V_157 ) |
( 1 << V_159 ) |
( 1 << V_156 ) |
( 1 << V_160 ) |
( 1 << V_161 ) ,
V_29 , F_99 ( V_2 ) . V_108 ,
F_121 ( V_110 ) ) ;
}
}
F_82 ( V_29 ) ;
return V_143 ;
}
static int
F_177 ( struct V_1 * V_2 , T_2 V_108 , T_2 V_92 ,
T_6 V_218 , const struct V_265 * V_266 )
{
struct V_109 * V_110 ;
struct V_111 * V_112 ;
unsigned int V_113 = V_108 ? V_114 : 0 , V_115 ;
V_115 = ( V_116 << 8 | V_267 ) ;
V_110 = F_54 ( V_2 , V_108 , V_92 , V_115 , sizeof( * V_112 ) , V_113 ) ;
if ( V_110 == NULL )
goto V_118;
V_112 = F_55 ( V_110 ) ;
V_112 -> V_119 = V_268 ;
V_112 -> V_120 = V_121 ;
V_112 -> V_122 = F_14 ( V_218 ) ;
if ( F_16 ( V_2 , V_269 , F_17 ( V_266 -> V_270 ) ) ||
F_16 ( V_2 , V_271 , F_17 ( V_266 -> V_272 ) ) ||
F_16 ( V_2 , V_273 , F_17 ( V_266 -> V_274 ) ) ||
F_16 ( V_2 , V_275 , F_17 ( V_266 -> V_276 ) ) ||
F_16 ( V_2 , V_277 , F_17 ( V_266 -> V_278 ) ) ||
F_16 ( V_2 , V_279 , F_17 ( V_266 -> V_280 ) ) ||
F_16 ( V_2 , V_281 , F_17 ( V_266 -> V_282 ) ) ||
F_16 ( V_2 , V_283 , F_17 ( V_266 -> V_284 ) ) ||
F_16 ( V_2 , V_285 ,
F_17 ( V_266 -> V_286 ) ) ||
F_16 ( V_2 , V_287 , F_17 ( V_266 -> V_288 ) ) ||
F_16 ( V_2 , V_289 , F_17 ( V_266 -> V_290 ) ) ||
F_16 ( V_2 , V_291 , F_17 ( V_266 -> error ) ) ||
F_16 ( V_2 , V_292 ,
F_17 ( V_266 -> V_293 ) ) )
goto V_12;
F_58 ( V_2 , V_110 ) ;
return V_2 -> V_79 ;
V_12:
V_118:
F_59 ( V_2 , V_110 ) ;
return - 1 ;
}
static int
F_178 ( struct V_1 * V_2 , struct V_164 * V_165 )
{
int V_218 ;
struct V_141 * V_141 = F_91 ( V_2 -> V_176 ) ;
if ( V_165 -> args [ 0 ] == V_221 )
return 0 ;
for ( V_218 = V_165 -> args [ 0 ] ; V_218 < V_221 ; V_218 ++ ) {
const struct V_265 * V_266 ;
if ( ! F_130 ( V_218 ) )
continue;
V_266 = F_131 ( V_141 -> V_29 . V_294 , V_218 ) ;
if ( F_177 ( V_2 ,
F_99 ( V_165 -> V_2 ) . V_108 ,
V_165 -> V_110 -> V_188 ,
V_218 , V_266 ) < 0 )
break;
}
V_165 -> args [ 0 ] = V_218 ;
return V_2 -> V_79 ;
}
static int F_179 ( struct V_141 * V_141 , struct V_204 * V_205 ,
struct V_1 * V_2 ,
const struct V_109 * V_110 ,
const struct V_8 * const V_168 [] )
{
if ( V_110 -> V_209 & V_210 ) {
struct V_211 V_212 = {
. V_213 = F_178 ,
} ;
return F_126 ( V_205 , V_2 , V_110 , & V_212 ) ;
}
return 0 ;
}
static int
F_180 ( struct V_1 * V_2 , T_2 V_108 , T_2 V_92 , T_2 type ,
struct V_141 * V_141 )
{
struct V_109 * V_110 ;
struct V_111 * V_112 ;
unsigned int V_113 = V_108 ? V_114 : 0 , V_115 ;
unsigned int V_295 = F_52 ( & V_141 -> V_29 . V_296 ) ;
V_115 = ( V_116 << 8 | V_297 ) ;
V_110 = F_54 ( V_2 , V_108 , V_92 , V_115 , sizeof( * V_112 ) , V_113 ) ;
if ( V_110 == NULL )
goto V_118;
V_112 = F_55 ( V_110 ) ;
V_112 -> V_119 = V_268 ;
V_112 -> V_120 = V_121 ;
V_112 -> V_122 = 0 ;
if ( F_16 ( V_2 , V_298 , F_17 ( V_295 ) ) )
goto V_12;
F_58 ( V_2 , V_110 ) ;
return V_2 -> V_79 ;
V_12:
V_118:
F_59 ( V_2 , V_110 ) ;
return - 1 ;
}
static int F_181 ( struct V_141 * V_141 , struct V_204 * V_205 ,
struct V_1 * V_2 , const struct V_109 * V_110 ,
const struct V_8 * const V_168 [] )
{
struct V_1 * V_208 ;
int V_143 ;
V_208 = F_77 ( V_215 , V_170 ) ;
if ( V_208 == NULL )
return - V_171 ;
V_143 = F_180 ( V_208 , F_99 ( V_2 ) . V_108 ,
V_110 -> V_188 ,
F_100 ( V_110 -> V_189 ) ,
F_91 ( V_2 -> V_176 ) ) ;
if ( V_143 <= 0 )
goto free;
V_143 = F_127 ( V_205 , V_208 , F_99 ( V_2 ) . V_108 , V_216 ) ;
if ( V_143 < 0 )
goto V_45;
return 0 ;
free:
F_79 ( V_208 ) ;
V_45:
return V_143 == - V_163 ? - V_162 : V_143 ;
}
static T_3
F_182 ( const struct V_28 * V_29 )
{
return 3 * F_41 ( 0 )
+ 3 * F_41 ( 0 )
+ 3 * F_41 ( 0 )
+ 3 * F_41 ( sizeof( V_134 ) )
+ F_41 ( sizeof( V_135 ) )
+ F_41 ( sizeof( V_135 ) )
+ F_41 ( sizeof( V_135 ) )
+ F_41 ( 0 )
+ F_41 ( 0 )
+ F_41 ( V_136 )
+ F_64 ( V_29 )
#ifdef F_70
+ 2 * F_41 ( 0 )
+ 6 * F_41 ( sizeof( V_135 ) )
#endif
#ifdef F_71
+ F_41 ( sizeof( V_135 ) )
#endif
#ifdef F_72
+ F_41 ( sizeof( V_137 ) )
#endif
+ F_60 ( V_29 )
;
}
static struct V_28 * F_183 ( const struct V_1 * V_2 ,
enum V_299 * V_300 )
{
struct V_28 * V_29 ;
V_29 = F_184 ( V_2 , V_300 ) ;
if ( V_29 && F_74 ( V_29 ) )
V_29 = NULL ;
return V_29 ;
}
static int F_185 ( struct V_1 * V_2 , struct V_28 * V_29 )
{
const struct V_23 * V_24 ;
struct V_8 * V_9 ;
F_8 () ;
V_24 = F_56 ( V_29 ) ;
V_9 = F_2 ( V_2 , V_123 | V_11 ) ;
if ( ! V_9 )
goto V_12;
if ( F_7 ( V_2 , F_57 ( V_29 , V_66 ) ) < 0 )
goto V_12;
if ( F_12 ( V_2 , V_124 , V_24 ,
V_125 ) < 0 )
goto V_12;
F_5 ( V_2 , V_9 ) ;
V_9 = F_2 ( V_2 , V_126 | V_11 ) ;
if ( ! V_9 )
goto V_12;
if ( F_7 ( V_2 , F_57 ( V_29 , V_67 ) ) < 0 )
goto V_12;
if ( F_12 ( V_2 , V_124 , V_24 ,
V_127 ) < 0 )
goto V_12;
F_5 ( V_2 , V_9 ) ;
if ( F_12 ( V_2 , V_128 , V_24 ,
V_129 ) < 0 )
goto V_12;
if ( F_50 ( V_2 , V_29 ) < 0 )
goto V_12;
if ( F_15 ( V_2 , V_29 ) < 0 )
goto V_12;
if ( F_18 ( V_2 , V_29 ) < 0 )
goto V_12;
if ( F_19 ( V_2 , V_29 ) < 0 )
goto V_12;
if ( F_22 ( V_2 , V_29 ) < 0 )
goto V_12;
#ifdef F_65
if ( V_29 -> V_81 && F_36 ( V_2 , V_29 ) < 0 )
goto V_12;
#endif
if ( V_29 -> V_244 && F_45 ( V_2 , V_29 ) < 0 )
goto V_12;
if ( ( V_29 -> V_31 & V_101 ) &&
F_48 ( V_2 , V_29 ) < 0 )
goto V_12;
#ifdef F_71
if ( V_29 -> V_77 && F_35 ( V_2 , V_29 ) < 0 )
goto V_12;
#endif
if ( F_42 ( V_2 , V_29 ) < 0 )
goto V_12;
F_11 () ;
return 0 ;
V_12:
F_11 () ;
return - V_301 ;
}
static int
F_186 ( struct V_1 * V_2 , struct V_28 * V_29 ,
enum V_299 V_300 ,
V_137 V_302 , V_137 V_303 )
{
struct V_8 * V_9 ;
V_9 = F_2 ( V_2 , V_302 | V_11 ) ;
if ( ! V_9 )
goto V_12;
if ( F_185 ( V_2 , V_29 ) < 0 )
goto V_12;
F_5 ( V_2 , V_9 ) ;
if ( F_16 ( V_2 , V_303 , F_17 ( V_300 ) ) )
goto V_12;
return 0 ;
V_12:
return - V_301 ;
}
static int
F_187 ( const struct V_8 * V_168 [] , struct V_28 * V_29 )
{
int V_143 ;
if ( V_168 [ V_36 ] ) {
V_143 = F_151 ( V_29 , V_168 ) ;
if ( V_143 < 0 )
return V_143 ;
}
if ( V_168 [ V_30 ] ) {
V_143 = F_145 ( V_29 , V_168 ) ;
if ( V_143 < 0 )
return V_143 ;
}
if ( V_168 [ V_46 ] ) {
V_143 = F_147 ( V_29 , V_168 ) ;
if ( V_143 < 0 )
return V_143 ;
}
if ( V_168 [ V_88 ] ) {
V_143 = F_156 ( V_29 , V_168 ) ;
if ( V_143 < 0 )
return V_143 ;
}
#if F_161 ( F_71 )
if ( V_168 [ V_76 ] ) {
T_2 V_173 = 0 , V_77 , V_304 ;
if ( V_168 [ V_174 ] )
V_173 = ~ F_87 ( F_88 ( V_168 [ V_174 ] ) ) ;
V_77 = F_87 ( F_88 ( V_168 [ V_76 ] ) ) ;
V_304 = ( V_29 -> V_77 & V_173 ) ^ V_77 ;
if ( V_304 != V_29 -> V_77 )
V_29 -> V_77 = V_304 ;
}
#endif
return 0 ;
}
static int
F_188 ( const struct V_8 * V_53 , struct V_28 * V_29 )
{
struct V_8 * V_168 [ V_305 + 1 ] ;
int V_7 ;
V_7 = F_104 ( V_168 , V_305 , V_53 , V_306 ) ;
if ( V_7 < 0 )
return V_7 ;
F_132 ( & V_245 ) ;
V_7 = F_187 ( ( const struct V_8 * * ) V_168 , V_29 ) ;
F_134 ( & V_245 ) ;
return V_7 ;
}
static int F_189 ( const struct V_8 * const * V_168 ,
const struct V_28 * V_29 ,
struct V_3 * V_4 ,
struct V_3 * V_173 )
{
int V_143 ;
V_143 = F_113 ( V_168 , V_4 , V_307 ,
F_20 ( V_29 ) , NULL ) ;
if ( V_143 < 0 )
return V_143 ;
return F_113 ( V_168 , V_173 , V_308 ,
F_20 ( V_29 ) , NULL ) ;
}
static int
F_190 ( const struct V_8 * V_53 , struct V_28 * V_29 ,
T_2 V_108 , T_2 V_153 )
{
struct V_8 * V_168 [ V_309 + 1 ] ;
struct V_3 V_4 , V_173 ;
struct V_43 * V_44 = NULL ;
struct V_310 * exp ;
int V_143 ;
V_143 = F_104 ( V_168 , V_309 , V_53 , V_311 ) ;
if ( V_143 < 0 )
return V_143 ;
V_143 = F_189 ( ( const struct V_8 * const * ) V_168 ,
V_29 , & V_4 , & V_173 ) ;
if ( V_143 < 0 )
return V_143 ;
if ( V_168 [ V_312 ] ) {
const char * V_243 = F_115 ( V_168 [ V_312 ] ) ;
V_44 = F_150 ( V_243 , F_20 ( V_29 ) ,
F_21 ( V_29 ) ) ;
if ( V_44 == NULL )
return - V_175 ;
}
exp = F_191 ( ( const struct V_8 * const * ) V_168 , V_29 ,
V_44 , & V_4 , & V_173 ) ;
if ( F_117 ( exp ) )
return F_118 ( exp ) ;
V_143 = F_192 ( exp , V_108 , V_153 ) ;
F_193 ( exp ) ;
return V_143 ;
}
static void F_194 ( struct V_1 * V_2 , struct V_28 * V_29 ,
enum V_299 V_300 , int V_313 )
{
if ( ! ( V_29 -> V_31 & V_238 ) )
return;
F_195 ( V_2 , V_29 , V_300 , V_313 ) ;
}
static int F_196 ( struct V_1 * V_2 ,
const struct V_3 * V_4 ,
enum V_314 type )
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
static int F_197 ( struct V_1 * V_2 ,
const struct V_3 * V_4 ,
const struct V_315 * V_173 )
{
int V_7 ;
struct V_17 * V_18 ;
struct V_5 * V_6 ;
struct V_3 V_316 ;
struct V_8 * V_9 ;
memset ( & V_316 , 0xFF , sizeof( V_316 ) ) ;
memcpy ( & V_316 . V_20 . V_206 , & V_173 -> V_20 . V_206 , sizeof( V_316 . V_20 . V_206 ) ) ;
V_316 . V_20 . V_317 . V_318 = V_173 -> V_20 . V_317 . V_318 ;
V_316 . V_14 . V_15 = V_4 -> V_14 . V_15 ;
V_9 = F_2 ( V_2 , V_308 | V_11 ) ;
if ( ! V_9 )
goto V_12;
F_8 () ;
V_18 = F_9 ( V_4 -> V_20 . V_21 ) ;
V_7 = F_6 ( V_2 , & V_316 , V_18 ) ;
if ( V_7 >= 0 ) {
V_6 = F_10 ( V_4 -> V_20 . V_21 ,
V_4 -> V_14 . V_15 ) ;
V_7 = F_1 ( V_2 , & V_316 , V_6 ) ;
}
F_11 () ;
if ( F_198 ( V_7 < 0 ) )
goto V_12;
F_5 ( V_2 , V_9 ) ;
return 0 ;
V_12:
return - 1 ;
}
static int
F_199 ( struct V_1 * V_2 ,
const struct V_310 * exp )
{
struct V_28 * V_244 = exp -> V_244 ;
long V_32 = ( ( long ) exp -> V_32 . V_33 - ( long ) V_34 ) / V_35 ;
struct V_41 * V_42 ;
#ifdef F_70
struct V_8 * V_9 ;
struct V_3 V_319 = {} ;
#endif
struct V_320 * V_321 ;
if ( V_32 < 0 )
V_32 = 0 ;
if ( F_196 ( V_2 , & exp -> V_4 , V_307 ) < 0 )
goto V_12;
if ( F_197 ( V_2 , & exp -> V_4 , & exp -> V_173 ) < 0 )
goto V_12;
if ( F_196 ( V_2 ,
& V_244 -> V_322 [ V_66 ] . V_4 ,
V_323 ) < 0 )
goto V_12;
#ifdef F_70
if ( ! F_200 ( & exp -> V_324 , & V_325 ) ||
exp -> V_326 . V_318 ) {
V_9 = F_2 ( V_2 , V_327 | V_11 ) ;
if ( ! V_9 )
goto V_12;
if ( F_16 ( V_2 , V_328 , F_17 ( exp -> V_25 ) ) )
goto V_12;
V_319 . V_20 . V_21 = F_20 ( V_244 ) ;
V_319 . V_20 . V_206 = exp -> V_324 ;
V_319 . V_14 . V_15 = F_21 ( V_244 ) ;
V_319 . V_20 . V_317 = exp -> V_326 ;
if ( F_196 ( V_2 , & V_319 ,
V_329 ) < 0 )
goto V_12;
F_5 ( V_2 , V_9 ) ;
}
#endif
if ( F_16 ( V_2 , V_330 , F_17 ( V_32 ) ) ||
F_16 ( V_2 , V_331 , F_17 ( ( unsigned long ) exp ) ) ||
F_16 ( V_2 , V_332 , F_17 ( exp -> V_113 ) ) ||
F_16 ( V_2 , V_333 , F_17 ( exp -> V_334 ) ) )
goto V_12;
V_42 = F_23 ( V_244 ) ;
if ( V_42 ) {
struct V_43 * V_44 ;
V_44 = F_24 ( V_42 -> V_44 ) ;
if ( V_44 &&
F_25 ( V_2 , V_312 , V_44 -> V_48 ) )
goto V_12;
}
V_321 = F_201 ( exp -> V_335 ) ;
if ( V_321 != NULL &&
F_25 ( V_2 , V_336 , V_321 -> V_48 ) )
goto V_12;
return 0 ;
V_12:
return - 1 ;
}
static int
F_202 ( struct V_1 * V_2 , T_2 V_108 , T_2 V_92 ,
int V_115 , const struct V_310 * exp )
{
struct V_109 * V_110 ;
struct V_111 * V_112 ;
unsigned int V_113 = V_108 ? V_114 : 0 ;
V_115 |= V_337 << 8 ;
V_110 = F_54 ( V_2 , V_108 , V_92 , V_115 , sizeof( * V_112 ) , V_113 ) ;
if ( V_110 == NULL )
goto V_118;
V_112 = F_55 ( V_110 ) ;
V_112 -> V_119 = exp -> V_4 . V_20 . V_21 ;
V_112 -> V_120 = V_121 ;
V_112 -> V_122 = 0 ;
if ( F_199 ( V_2 , exp ) < 0 )
goto V_12;
F_58 ( V_2 , V_110 ) ;
return V_2 -> V_79 ;
V_118:
V_12:
F_59 ( V_2 , V_110 ) ;
return - 1 ;
}
static int
F_203 ( unsigned int V_138 , struct V_338 * V_140 )
{
struct V_310 * exp = V_140 -> exp ;
struct V_141 * V_141 = F_204 ( exp ) ;
struct V_109 * V_110 ;
struct V_111 * V_112 ;
struct V_1 * V_2 ;
unsigned int type , V_142 ;
int V_113 = 0 ;
if ( V_138 & ( 1 << V_339 ) ) {
type = V_340 ;
V_142 = V_341 ;
} else if ( V_138 & ( 1 << V_342 ) ) {
type = V_343 ;
V_113 = V_149 | V_150 ;
V_142 = V_344 ;
} else
return 0 ;
if ( ! V_140 -> V_153 && ! F_76 ( V_141 , V_142 ) )
return 0 ;
V_2 = F_77 ( V_215 , V_154 ) ;
if ( V_2 == NULL )
goto V_155;
type |= V_337 << 8 ;
V_110 = F_54 ( V_2 , V_140 -> V_108 , 0 , type , sizeof( * V_112 ) , V_113 ) ;
if ( V_110 == NULL )
goto V_118;
V_112 = F_55 ( V_110 ) ;
V_112 -> V_119 = exp -> V_4 . V_20 . V_21 ;
V_112 -> V_120 = V_121 ;
V_112 -> V_122 = 0 ;
F_8 () ;
if ( F_199 ( V_2 , exp ) < 0 )
goto V_12;
F_11 () ;
F_58 ( V_2 , V_110 ) ;
F_78 ( V_2 , V_141 , V_140 -> V_108 , V_142 , V_140 -> V_153 , V_154 ) ;
return 0 ;
V_12:
F_11 () ;
F_59 ( V_2 , V_110 ) ;
V_118:
F_79 ( V_2 ) ;
V_155:
F_80 ( V_141 , 0 , 0 , - V_162 ) ;
return 0 ;
}
static int F_205 ( struct V_164 * V_165 )
{
if ( V_165 -> args [ 1 ] )
F_193 ( (struct V_310 * ) V_165 -> args [ 1 ] ) ;
return 0 ;
}
static int
F_206 ( struct V_1 * V_2 , struct V_164 * V_165 )
{
struct V_141 * V_141 = F_91 ( V_2 -> V_176 ) ;
struct V_310 * exp , * V_177 ;
struct V_111 * V_112 = F_55 ( V_165 -> V_110 ) ;
V_134 V_18 = V_112 -> V_119 ;
F_8 () ;
V_177 = (struct V_310 * ) V_165 -> args [ 1 ] ;
for (; V_165 -> args [ 0 ] < V_345 ; V_165 -> args [ 0 ] ++ ) {
V_185:
F_207 (exp, &nf_ct_expect_hash[cb->args[0]],
hnode) {
if ( V_18 && exp -> V_4 . V_20 . V_21 != V_18 )
continue;
if ( ! F_98 ( F_75 ( exp -> V_244 ) , V_141 ) )
continue;
if ( V_165 -> args [ 1 ] ) {
if ( exp != V_177 )
continue;
V_165 -> args [ 1 ] = 0 ;
}
if ( F_202 ( V_2 ,
F_99 ( V_165 -> V_2 ) . V_108 ,
V_165 -> V_110 -> V_188 ,
V_343 ,
exp ) < 0 ) {
if ( ! F_133 ( & exp -> V_107 ) )
continue;
V_165 -> args [ 1 ] = ( unsigned long ) exp ;
goto V_45;
}
}
if ( V_165 -> args [ 1 ] ) {
V_165 -> args [ 1 ] = 0 ;
goto V_185;
}
}
V_45:
F_11 () ;
if ( V_177 )
F_193 ( V_177 ) ;
return V_2 -> V_79 ;
}
static int
F_208 ( struct V_1 * V_2 , struct V_164 * V_165 )
{
struct V_310 * exp , * V_177 ;
struct V_111 * V_112 = F_55 ( V_165 -> V_110 ) ;
struct V_28 * V_29 = V_165 -> V_166 ;
struct V_41 * V_42 = F_23 ( V_29 ) ;
V_134 V_18 = V_112 -> V_119 ;
if ( V_165 -> args [ 0 ] )
return 0 ;
F_8 () ;
V_177 = (struct V_310 * ) V_165 -> args [ 1 ] ;
V_185:
F_207 (exp, &help->expectations, lnode) {
if ( V_18 && exp -> V_4 . V_20 . V_21 != V_18 )
continue;
if ( V_165 -> args [ 1 ] ) {
if ( exp != V_177 )
continue;
V_165 -> args [ 1 ] = 0 ;
}
if ( F_202 ( V_2 , F_99 ( V_165 -> V_2 ) . V_108 ,
V_165 -> V_110 -> V_188 ,
V_343 ,
exp ) < 0 ) {
if ( ! F_133 ( & exp -> V_107 ) )
continue;
V_165 -> args [ 1 ] = ( unsigned long ) exp ;
goto V_45;
}
}
if ( V_165 -> args [ 1 ] ) {
V_165 -> args [ 1 ] = 0 ;
goto V_185;
}
V_165 -> args [ 0 ] = 1 ;
V_45:
F_11 () ;
if ( V_177 )
F_193 ( V_177 ) ;
return V_2 -> V_79 ;
}
static int F_209 ( struct V_141 * V_141 , struct V_204 * V_205 ,
struct V_1 * V_2 ,
const struct V_109 * V_110 ,
const struct V_8 * const V_168 [] )
{
int V_143 ;
struct V_111 * V_112 = F_55 ( V_110 ) ;
V_134 V_206 = V_112 -> V_119 ;
struct V_3 V_4 ;
struct V_178 * V_179 ;
struct V_28 * V_29 ;
struct V_23 V_24 ;
struct V_211 V_212 = {
. V_213 = F_208 ,
. V_214 = F_205 ,
} ;
V_143 = F_113 ( V_168 , & V_4 , V_323 ,
V_206 , NULL ) ;
if ( V_143 < 0 )
return V_143 ;
V_143 = F_108 ( V_168 [ V_346 ] , & V_24 ) ;
if ( V_143 < 0 )
return V_143 ;
V_179 = F_122 ( V_141 , & V_24 , & V_4 ) ;
if ( ! V_179 )
return - V_207 ;
V_29 = F_97 ( V_179 ) ;
V_212 . V_166 = V_29 ;
V_143 = F_126 ( V_205 , V_2 , V_110 , & V_212 ) ;
F_82 ( V_29 ) ;
return V_143 ;
}
static int F_210 ( struct V_141 * V_141 , struct V_204 * V_205 ,
struct V_1 * V_2 , const struct V_109 * V_110 ,
const struct V_8 * const V_168 [] )
{
struct V_3 V_4 ;
struct V_310 * exp ;
struct V_1 * V_208 ;
struct V_111 * V_112 = F_55 ( V_110 ) ;
V_134 V_206 = V_112 -> V_119 ;
struct V_23 V_24 ;
int V_143 ;
if ( V_110 -> V_209 & V_210 ) {
if ( V_168 [ V_323 ] )
return F_209 ( V_141 , V_205 , V_2 , V_110 , V_168 ) ;
else {
struct V_211 V_212 = {
. V_213 = F_206 ,
. V_214 = F_205 ,
} ;
return F_126 ( V_205 , V_2 , V_110 , & V_212 ) ;
}
}
V_143 = F_108 ( V_168 [ V_346 ] , & V_24 ) ;
if ( V_143 < 0 )
return V_143 ;
if ( V_168 [ V_307 ] )
V_143 = F_113 ( V_168 , & V_4 , V_307 ,
V_206 , NULL ) ;
else if ( V_168 [ V_323 ] )
V_143 = F_113 ( V_168 , & V_4 , V_323 ,
V_206 , NULL ) ;
else
return - V_196 ;
if ( V_143 < 0 )
return V_143 ;
exp = F_211 ( V_141 , & V_24 , & V_4 ) ;
if ( ! exp )
return - V_207 ;
if ( V_168 [ V_331 ] ) {
T_7 V_26 = F_88 ( V_168 [ V_331 ] ) ;
if ( F_87 ( V_26 ) != ( T_2 ) ( unsigned long ) exp ) {
F_193 ( exp ) ;
return - V_207 ;
}
}
V_143 = - V_171 ;
V_208 = F_77 ( V_215 , V_170 ) ;
if ( V_208 == NULL ) {
F_193 ( exp ) ;
goto V_45;
}
F_8 () ;
V_143 = F_202 ( V_208 , F_99 ( V_2 ) . V_108 ,
V_110 -> V_188 , V_343 , exp ) ;
F_11 () ;
F_193 ( exp ) ;
if ( V_143 <= 0 )
goto free;
V_143 = F_127 ( V_205 , V_208 , F_99 ( V_2 ) . V_108 , V_216 ) ;
if ( V_143 < 0 )
goto V_45;
return 0 ;
free:
F_79 ( V_208 ) ;
V_45:
return V_143 == - V_163 ? - V_162 : V_143 ;
}
static int F_212 ( struct V_141 * V_141 , struct V_204 * V_205 ,
struct V_1 * V_2 , const struct V_109 * V_110 ,
const struct V_8 * const V_168 [] )
{
struct V_310 * exp ;
struct V_3 V_4 ;
struct V_111 * V_112 = F_55 ( V_110 ) ;
struct V_347 * V_348 ;
V_134 V_206 = V_112 -> V_119 ;
struct V_23 V_24 ;
unsigned int V_87 ;
int V_143 ;
if ( V_168 [ V_307 ] ) {
V_143 = F_108 ( V_168 [ V_346 ] , & V_24 ) ;
if ( V_143 < 0 )
return V_143 ;
V_143 = F_113 ( V_168 , & V_4 , V_307 ,
V_206 , NULL ) ;
if ( V_143 < 0 )
return V_143 ;
exp = F_211 ( V_141 , & V_24 , & V_4 ) ;
if ( ! exp )
return - V_207 ;
if ( V_168 [ V_331 ] ) {
T_7 V_26 = F_88 ( V_168 [ V_331 ] ) ;
if ( F_87 ( V_26 ) != ( T_2 ) ( unsigned long ) exp ) {
F_193 ( exp ) ;
return - V_207 ;
}
}
F_132 ( & V_245 ) ;
if ( F_123 ( & exp -> V_32 ) ) {
F_213 ( exp , F_99 ( V_2 ) . V_108 ,
F_121 ( V_110 ) ) ;
F_193 ( exp ) ;
}
F_134 ( & V_245 ) ;
F_193 ( exp ) ;
} else if ( V_168 [ V_312 ] ) {
char * V_48 = F_115 ( V_168 [ V_312 ] ) ;
struct V_41 * V_349 ;
F_132 ( & V_245 ) ;
for ( V_87 = 0 ; V_87 < V_345 ; V_87 ++ ) {
F_214 (exp, next,
&nf_ct_expect_hash[i],
hnode) {
if ( ! F_98 ( F_204 ( exp ) , V_141 ) )
continue;
V_349 = F_23 ( exp -> V_244 ) ;
if ( ! strcmp ( V_349 -> V_44 -> V_48 , V_48 ) &&
F_123 ( & exp -> V_32 ) ) {
F_213 ( exp ,
F_99 ( V_2 ) . V_108 ,
F_121 ( V_110 ) ) ;
F_193 ( exp ) ;
}
}
}
F_134 ( & V_245 ) ;
} else {
F_132 ( & V_245 ) ;
for ( V_87 = 0 ; V_87 < V_345 ; V_87 ++ ) {
F_214 (exp, next,
&nf_ct_expect_hash[i],
hnode) {
if ( ! F_98 ( F_204 ( exp ) , V_141 ) )
continue;
if ( F_123 ( & exp -> V_32 ) ) {
F_213 ( exp ,
F_99 ( V_2 ) . V_108 ,
F_121 ( V_110 ) ) ;
F_193 ( exp ) ;
}
}
}
F_134 ( & V_245 ) ;
}
return 0 ;
}
static int
F_215 ( struct V_310 * V_350 ,
const struct V_8 * const V_168 [] )
{
if ( V_168 [ V_330 ] ) {
if ( ! F_123 ( & V_350 -> V_32 ) )
return - V_247 ;
V_350 -> V_32 . V_33 = V_34 +
F_87 ( F_88 ( V_168 [ V_330 ] ) ) * V_35 ;
F_152 ( & V_350 -> V_32 ) ;
}
return 0 ;
}
static int
F_216 ( const struct V_8 * V_53 ,
struct V_310 * exp ,
V_134 V_206 )
{
#ifdef F_70
struct V_8 * V_190 [ V_351 + 1 ] ;
struct V_3 V_319 = {} ;
int V_143 ;
V_143 = F_104 ( V_190 , V_351 , V_53 , V_352 ) ;
if ( V_143 < 0 )
return V_143 ;
if ( ! V_190 [ V_328 ] || ! V_190 [ V_329 ] )
return - V_196 ;
V_143 = F_113 ( ( const struct V_8 * const * ) V_190 ,
& V_319 , V_329 ,
V_206 , NULL ) ;
if ( V_143 < 0 )
return V_143 ;
exp -> V_324 = V_319 . V_20 . V_206 ;
exp -> V_326 = V_319 . V_20 . V_317 ;
exp -> V_25 = F_87 ( F_88 ( V_190 [ V_328 ] ) ) ;
return 0 ;
#else
return - V_175 ;
#endif
}
static struct V_310 *
F_191 ( const struct V_8 * const V_168 [] , struct V_28 * V_29 ,
struct V_43 * V_44 ,
struct V_3 * V_4 ,
struct V_3 * V_173 )
{
V_135 V_334 = 0 ;
struct V_310 * exp ;
struct V_41 * V_42 ;
int V_143 ;
if ( V_168 [ V_333 ] && V_44 ) {
V_334 = F_87 ( F_88 ( V_168 [ V_333 ] ) ) ;
if ( V_334 > V_44 -> V_353 )
return F_86 ( - V_196 ) ;
}
exp = F_217 ( V_29 ) ;
if ( ! exp )
return F_86 ( - V_171 ) ;
V_42 = F_23 ( V_29 ) ;
if ( ! V_42 ) {
if ( ! V_168 [ V_330 ] ) {
V_143 = - V_196 ;
goto V_354;
}
exp -> V_32 . V_33 =
V_34 + F_87 ( F_88 ( V_168 [ V_330 ] ) ) * V_35 ;
exp -> V_113 = V_355 ;
if ( V_168 [ V_332 ] ) {
exp -> V_113 |=
F_87 ( F_88 ( V_168 [ V_332 ] ) ) ;
}
} else {
if ( V_168 [ V_332 ] ) {
exp -> V_113 = F_87 ( F_88 ( V_168 [ V_332 ] ) ) ;
exp -> V_113 &= ~ V_355 ;
} else
exp -> V_113 = 0 ;
}
if ( V_168 [ V_336 ] ) {
const char * V_48 = F_115 ( V_168 [ V_336 ] ) ;
struct V_320 * V_321 ;
V_321 = F_218 ( V_48 ) ;
if ( V_321 == NULL ) {
V_143 = - V_196 ;
goto V_354;
}
exp -> V_335 = V_321 -> V_335 ;
} else
exp -> V_335 = NULL ;
exp -> V_334 = V_334 ;
exp -> V_244 = V_29 ;
exp -> V_44 = V_44 ;
exp -> V_4 = * V_4 ;
exp -> V_173 . V_20 . V_206 = V_173 -> V_20 . V_206 ;
exp -> V_173 . V_20 . V_317 . V_318 = V_173 -> V_20 . V_317 . V_318 ;
if ( V_168 [ V_327 ] ) {
V_143 = F_216 ( V_168 [ V_327 ] ,
exp , F_20 ( V_29 ) ) ;
if ( V_143 < 0 )
goto V_354;
}
return exp ;
V_354:
F_193 ( exp ) ;
return F_86 ( V_143 ) ;
}
static int
F_219 ( struct V_141 * V_141 ,
const struct V_23 * V_24 ,
const struct V_8 * const V_168 [] ,
V_134 V_206 , T_2 V_108 , int V_153 )
{
struct V_3 V_4 , V_173 , F_46 ;
struct V_178 * V_179 = NULL ;
struct V_43 * V_44 = NULL ;
struct V_310 * exp ;
struct V_28 * V_29 ;
int V_143 ;
V_143 = F_113 ( V_168 , & V_4 , V_307 ,
V_206 , NULL ) ;
if ( V_143 < 0 )
return V_143 ;
V_143 = F_113 ( V_168 , & V_173 , V_308 ,
V_206 , NULL ) ;
if ( V_143 < 0 )
return V_143 ;
V_143 = F_113 ( V_168 , & F_46 , V_323 ,
V_206 , NULL ) ;
if ( V_143 < 0 )
return V_143 ;
V_179 = F_122 ( V_141 , V_24 , & F_46 ) ;
if ( ! V_179 )
return - V_207 ;
V_29 = F_97 ( V_179 ) ;
if ( V_168 [ V_312 ] ) {
const char * V_243 = F_115 ( V_168 [ V_312 ] ) ;
V_44 = F_150 ( V_243 , V_206 ,
F_21 ( V_29 ) ) ;
if ( V_44 == NULL ) {
#ifdef F_141
if ( F_143 ( L_4 , V_243 ) < 0 ) {
V_143 = - V_175 ;
goto V_356;
}
V_44 = F_150 ( V_243 , V_206 ,
F_21 ( V_29 ) ) ;
if ( V_44 ) {
V_143 = - V_163 ;
goto V_356;
}
#endif
V_143 = - V_175 ;
goto V_356;
}
}
exp = F_191 ( V_168 , V_29 , V_44 , & V_4 , & V_173 ) ;
if ( F_117 ( exp ) ) {
V_143 = F_118 ( exp ) ;
goto V_356;
}
V_143 = F_192 ( exp , V_108 , V_153 ) ;
F_193 ( exp ) ;
V_356:
F_82 ( V_29 ) ;
return V_143 ;
}
static int F_220 ( struct V_141 * V_141 , struct V_204 * V_205 ,
struct V_1 * V_2 , const struct V_109 * V_110 ,
const struct V_8 * const V_168 [] )
{
struct V_3 V_4 ;
struct V_310 * exp ;
struct V_111 * V_112 = F_55 ( V_110 ) ;
V_134 V_206 = V_112 -> V_119 ;
struct V_23 V_24 ;
int V_143 ;
if ( ! V_168 [ V_307 ]
|| ! V_168 [ V_308 ]
|| ! V_168 [ V_323 ] )
return - V_196 ;
V_143 = F_108 ( V_168 [ V_346 ] , & V_24 ) ;
if ( V_143 < 0 )
return V_143 ;
V_143 = F_113 ( V_168 , & V_4 , V_307 ,
V_206 , NULL ) ;
if ( V_143 < 0 )
return V_143 ;
F_132 ( & V_245 ) ;
exp = F_221 ( V_141 , & V_24 , & V_4 ) ;
if ( ! exp ) {
F_134 ( & V_245 ) ;
V_143 = - V_207 ;
if ( V_110 -> V_209 & V_149 ) {
V_143 = F_219 ( V_141 , & V_24 , V_168 , V_206 ,
F_99 ( V_2 ) . V_108 ,
F_121 ( V_110 ) ) ;
}
return V_143 ;
}
V_143 = - V_264 ;
if ( ! ( V_110 -> V_209 & V_150 ) )
V_143 = F_215 ( exp , V_168 ) ;
F_134 ( & V_245 ) ;
return V_143 ;
}
static int
F_222 ( struct V_1 * V_2 , T_2 V_108 , T_2 V_92 , int V_218 ,
const struct V_265 * V_266 )
{
struct V_109 * V_110 ;
struct V_111 * V_112 ;
unsigned int V_113 = V_108 ? V_114 : 0 , V_115 ;
V_115 = ( V_116 << 8 | V_357 ) ;
V_110 = F_54 ( V_2 , V_108 , V_92 , V_115 , sizeof( * V_112 ) , V_113 ) ;
if ( V_110 == NULL )
goto V_118;
V_112 = F_55 ( V_110 ) ;
V_112 -> V_119 = V_268 ;
V_112 -> V_120 = V_121 ;
V_112 -> V_122 = F_14 ( V_218 ) ;
if ( F_16 ( V_2 , V_358 , F_17 ( V_266 -> V_359 ) ) ||
F_16 ( V_2 , V_360 , F_17 ( V_266 -> V_361 ) ) ||
F_16 ( V_2 , V_362 , F_17 ( V_266 -> V_363 ) ) )
goto V_12;
F_58 ( V_2 , V_110 ) ;
return V_2 -> V_79 ;
V_12:
V_118:
F_59 ( V_2 , V_110 ) ;
return - 1 ;
}
static int
F_223 ( struct V_1 * V_2 , struct V_164 * V_165 )
{
int V_218 ;
struct V_141 * V_141 = F_91 ( V_2 -> V_176 ) ;
if ( V_165 -> args [ 0 ] == V_221 )
return 0 ;
for ( V_218 = V_165 -> args [ 0 ] ; V_218 < V_221 ; V_218 ++ ) {
const struct V_265 * V_266 ;
if ( ! F_130 ( V_218 ) )
continue;
V_266 = F_131 ( V_141 -> V_29 . V_294 , V_218 ) ;
if ( F_222 ( V_2 , F_99 ( V_165 -> V_2 ) . V_108 ,
V_165 -> V_110 -> V_188 ,
V_218 , V_266 ) < 0 )
break;
}
V_165 -> args [ 0 ] = V_218 ;
return V_2 -> V_79 ;
}
static int F_224 ( struct V_141 * V_141 , struct V_204 * V_205 ,
struct V_1 * V_2 ,
const struct V_109 * V_110 ,
const struct V_8 * const V_168 [] )
{
if ( V_110 -> V_209 & V_210 ) {
struct V_211 V_212 = {
. V_213 = F_223 ,
} ;
return F_126 ( V_205 , V_2 , V_110 , & V_212 ) ;
}
return 0 ;
}
static int T_8 F_225 ( struct V_141 * V_141 )
{
#ifdef F_226
int V_7 ;
V_7 = F_227 ( V_141 , & V_364 ) ;
if ( V_7 < 0 ) {
F_228 ( L_5 ) ;
goto V_354;
}
V_7 = F_229 ( V_141 , & V_365 ) ;
if ( V_7 < 0 ) {
F_228 ( L_6 ) ;
goto V_366;
}
#endif
return 0 ;
#ifdef F_226
V_366:
F_230 ( V_141 , & V_364 ) ;
V_354:
return V_7 ;
#endif
}
static void F_231 ( struct V_141 * V_141 )
{
#ifdef F_226
F_232 ( V_141 , & V_365 ) ;
F_230 ( V_141 , & V_364 ) ;
#endif
}
static void T_9 F_233 ( struct V_367 * V_368 )
{
struct V_141 * V_141 ;
F_234 (net, net_exit_list, exit_list)
F_231 ( V_141 ) ;
}
static int T_10 F_235 ( void )
{
int V_7 ;
F_236 ( L_7 , V_120 ) ;
V_7 = F_237 ( & V_369 ) ;
if ( V_7 < 0 ) {
F_228 ( L_8 ) ;
goto V_354;
}
V_7 = F_237 ( & V_370 ) ;
if ( V_7 < 0 ) {
F_228 ( L_9 ) ;
goto V_371;
}
V_7 = F_238 ( & V_372 ) ;
if ( V_7 < 0 ) {
F_228 ( L_10 ) ;
goto V_373;
}
#ifdef F_239
F_149 ( V_374 , & V_375 ) ;
#endif
return 0 ;
V_373:
F_240 ( & V_370 ) ;
V_371:
F_240 ( & V_369 ) ;
V_354:
return V_7 ;
}
static void T_11 F_241 ( void )
{
F_236 ( L_11 ) ;
F_242 ( & V_372 ) ;
F_240 ( & V_370 ) ;
F_240 ( & V_369 ) ;
#ifdef F_239
F_149 ( V_374 , NULL ) ;
#endif
}
