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
return F_41 ( V_85 -> V_86 * sizeof( long ) ) ;
}
static int
F_42 ( struct V_1 * V_2 , const struct V_28 * V_29 )
{
struct V_84 * V_85 = F_40 ( V_29 ) ;
unsigned int V_79 , V_87 ;
if ( ! V_85 )
return 0 ;
V_79 = V_85 -> V_86 * sizeof( long ) ;
V_87 = 0 ;
do {
if ( V_85 -> V_88 [ V_87 ] != 0 )
return F_43 ( V_2 , V_89 , V_79 , V_85 -> V_88 ) ;
V_87 ++ ;
} while ( V_87 < V_85 -> V_86 );
return 0 ;
}
static int F_44 ( struct V_1 * V_2 , const struct V_28 * V_29 )
{
struct V_8 * V_9 ;
if ( ! ( V_29 -> V_31 & V_90 ) )
return 0 ;
V_9 = F_2 ( V_2 , V_91 | V_11 ) ;
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
F_46 ( struct V_1 * V_2 , const struct V_92 * V_93 , int type )
{
struct V_8 * V_9 ;
V_9 = F_2 ( V_2 , type | V_11 ) ;
if ( ! V_9 )
goto V_12;
if ( F_16 ( V_2 , V_94 ,
F_17 ( V_93 -> V_95 ) ) ||
F_16 ( V_2 , V_96 ,
F_17 ( V_93 -> V_97 ) ) ||
F_16 ( V_2 , V_98 ,
F_17 ( V_93 -> V_99 ) ) )
goto V_12;
F_5 ( V_2 , V_9 ) ;
return 0 ;
V_12:
return - 1 ;
}
static int F_47 ( struct V_1 * V_2 ,
const struct V_28 * V_29 )
{
struct V_100 * V_101 = F_48 ( V_29 ) ;
struct V_92 * V_93 ;
if ( ! ( V_29 -> V_31 & V_102 ) || ! V_101 )
return 0 ;
V_93 = & V_101 -> V_93 [ V_66 ] ;
if ( F_46 ( V_2 , V_93 , V_103 ) == - 1 )
return - 1 ;
V_93 = & V_101 -> V_93 [ V_67 ] ;
if ( F_46 ( V_2 , V_93 , V_104 ) == - 1 )
return - 1 ;
return 0 ;
}
static int F_49 ( struct V_1 * V_2 , const struct V_28 * V_29 )
{
if ( F_16 ( V_2 , V_105 , F_17 ( ( unsigned long ) V_29 ) ) )
goto V_12;
return 0 ;
V_12:
return - 1 ;
}
static int F_50 ( struct V_1 * V_2 , const struct V_28 * V_29 )
{
if ( F_16 ( V_2 , V_106 , F_17 ( F_51 ( & V_29 -> V_107 . V_108 ) ) ) )
goto V_12;
return 0 ;
V_12:
return - 1 ;
}
static int
F_52 ( struct V_1 * V_2 , T_2 V_109 , T_2 V_93 , T_2 type ,
struct V_28 * V_29 )
{
const struct V_23 * V_24 ;
struct V_110 * V_111 ;
struct V_112 * V_113 ;
struct V_8 * V_9 ;
unsigned int V_114 = V_109 ? V_115 : 0 , V_116 ;
V_116 = ( V_117 << 8 | V_118 ) ;
V_111 = F_53 ( V_2 , V_109 , V_93 , V_116 , sizeof( * V_113 ) , V_114 ) ;
if ( V_111 == NULL )
goto V_119;
V_113 = F_54 ( V_111 ) ;
V_113 -> V_120 = F_20 ( V_29 ) ;
V_113 -> V_121 = V_122 ;
V_113 -> V_123 = 0 ;
V_24 = F_55 ( V_29 ) ;
V_9 = F_2 ( V_2 , V_124 | V_11 ) ;
if ( ! V_9 )
goto V_12;
if ( F_7 ( V_2 , F_56 ( V_29 , V_66 ) ) < 0 )
goto V_12;
if ( F_12 ( V_2 , V_125 , V_24 ,
V_126 ) < 0 )
goto V_12;
F_5 ( V_2 , V_9 ) ;
V_9 = F_2 ( V_2 , V_127 | V_11 ) ;
if ( ! V_9 )
goto V_12;
if ( F_7 ( V_2 , F_56 ( V_29 , V_67 ) ) < 0 )
goto V_12;
if ( F_12 ( V_2 , V_125 , V_24 ,
V_128 ) < 0 )
goto V_12;
F_5 ( V_2 , V_9 ) ;
if ( F_12 ( V_2 , V_129 , V_24 ,
V_130 ) < 0 )
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
F_57 ( V_2 , V_111 ) ;
return V_2 -> V_79 ;
V_119:
V_12:
F_58 ( V_2 , V_111 ) ;
return - 1 ;
}
static inline T_3 F_59 ( const struct V_28 * V_29 )
{
struct V_17 * V_18 ;
struct V_5 * V_6 ;
T_3 V_79 = 0 ;
F_8 () ;
V_18 = F_9 ( F_20 ( V_29 ) ) ;
V_79 += V_18 -> V_131 ;
V_6 = F_10 ( F_20 ( V_29 ) , F_21 ( V_29 ) ) ;
V_79 += V_6 -> V_131 ;
F_11 () ;
return V_79 ;
}
static inline T_3 F_60 ( const struct V_28 * V_29 )
{
if ( ! F_61 ( V_29 , V_132 ) )
return 0 ;
return 2 * F_41 ( 0 )
+ 2 * F_62 ( sizeof( V_133 ) )
+ 2 * F_62 ( sizeof( V_133 ) )
;
}
static inline int F_63 ( const struct V_28 * V_29 )
{
#ifdef F_64
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
static inline T_3 F_65 ( const struct V_28 * V_29 )
{
#ifdef F_66
if ( ! F_61 ( V_29 , V_134 ) )
return 0 ;
return F_41 ( 0 ) + 2 * F_62 ( sizeof( V_133 ) ) ;
#else
return 0 ;
#endif
}
static T_3 F_67 ( const struct V_28 * V_29 )
{
return F_68 ( sizeof( struct V_112 ) )
+ 3 * F_41 ( 0 )
+ 3 * F_41 ( 0 )
+ 3 * F_41 ( 0 )
+ 3 * F_41 ( sizeof( V_135 ) )
+ F_41 ( sizeof( V_136 ) )
+ F_41 ( sizeof( V_136 ) )
+ F_60 ( V_29 )
+ F_65 ( V_29 )
+ F_41 ( sizeof( V_136 ) )
+ F_41 ( 0 )
+ F_41 ( 0 )
+ F_41 ( V_137 )
+ F_63 ( V_29 )
#ifdef F_69
+ 2 * F_41 ( 0 )
+ 6 * F_41 ( sizeof( V_136 ) )
#endif
#ifdef F_70
+ F_41 ( sizeof( V_136 ) )
#endif
#ifdef F_71
+ F_41 ( sizeof( V_138 ) )
#endif
+ F_59 ( V_29 )
+ F_39 ( V_29 )
;
}
static int
F_72 ( unsigned int V_139 , struct V_140 * V_141 )
{
const struct V_23 * V_24 ;
struct V_142 * V_142 ;
struct V_110 * V_111 ;
struct V_112 * V_113 ;
struct V_8 * V_9 ;
struct V_28 * V_29 = V_141 -> V_29 ;
struct V_1 * V_2 ;
unsigned int type ;
unsigned int V_114 = 0 , V_143 ;
int V_144 ;
if ( F_73 ( V_29 ) )
return 0 ;
if ( V_139 & ( 1 << V_145 ) ) {
type = V_146 ;
V_143 = V_147 ;
} else if ( V_139 & ( ( 1 << V_148 ) | ( 1 << V_149 ) ) ) {
type = V_118 ;
V_114 = V_150 | V_151 ;
V_143 = V_152 ;
} else if ( V_139 ) {
type = V_118 ;
V_143 = V_153 ;
} else
return 0 ;
V_142 = F_74 ( V_29 ) ;
if ( ! V_141 -> V_154 && ! F_75 ( V_142 , V_143 ) )
return 0 ;
V_2 = F_76 ( F_67 ( V_29 ) , V_155 ) ;
if ( V_2 == NULL )
goto V_156;
type |= V_117 << 8 ;
V_111 = F_53 ( V_2 , V_141 -> V_109 , 0 , type , sizeof( * V_113 ) , V_114 ) ;
if ( V_111 == NULL )
goto V_119;
V_113 = F_54 ( V_111 ) ;
V_113 -> V_120 = F_20 ( V_29 ) ;
V_113 -> V_121 = V_122 ;
V_113 -> V_123 = 0 ;
F_8 () ;
V_24 = F_55 ( V_29 ) ;
V_9 = F_2 ( V_2 , V_124 | V_11 ) ;
if ( ! V_9 )
goto V_12;
if ( F_7 ( V_2 , F_56 ( V_29 , V_66 ) ) < 0 )
goto V_12;
if ( F_12 ( V_2 , V_125 , V_24 ,
V_126 ) < 0 )
goto V_12;
F_5 ( V_2 , V_9 ) ;
V_9 = F_2 ( V_2 , V_127 | V_11 ) ;
if ( ! V_9 )
goto V_12;
if ( F_7 ( V_2 , F_56 ( V_29 , V_67 ) ) < 0 )
goto V_12;
if ( F_12 ( V_2 , V_125 , V_24 ,
V_128 ) < 0 )
goto V_12;
F_5 ( V_2 , V_9 ) ;
if ( F_12 ( V_2 , V_129 , V_24 ,
V_130 ) < 0 )
goto V_12;
if ( F_49 ( V_2 , V_29 ) < 0 )
goto V_12;
if ( F_15 ( V_2 , V_29 ) < 0 )
goto V_12;
if ( V_139 & ( 1 << V_145 ) ) {
if ( F_31 ( V_2 , V_29 , type ) < 0 ||
F_33 ( V_2 , V_29 ) < 0 )
goto V_12;
} else {
if ( F_18 ( V_2 , V_29 ) < 0 )
goto V_12;
if ( V_139 & ( 1 << V_157 )
&& F_19 ( V_2 , V_29 ) < 0 )
goto V_12;
if ( ( V_139 & ( 1 << V_158 ) || F_23 ( V_29 ) )
&& F_22 ( V_2 , V_29 ) < 0 )
goto V_12;
#ifdef F_64
if ( ( V_139 & ( 1 << V_159 ) || V_29 -> V_81 )
&& F_36 ( V_2 , V_29 ) < 0 )
goto V_12;
#endif
if ( V_139 & ( 1 << V_160 ) &&
F_42 ( V_2 , V_29 ) < 0 )
goto V_12;
if ( V_139 & ( 1 << V_149 ) &&
F_44 ( V_2 , V_29 ) < 0 )
goto V_12;
if ( V_139 & ( 1 << V_161 ) &&
F_47 ( V_2 , V_29 ) < 0 )
goto V_12;
}
#ifdef F_70
if ( ( V_139 & ( 1 << V_162 ) || V_29 -> V_77 )
&& F_35 ( V_2 , V_29 ) < 0 )
goto V_12;
#endif
F_11 () ;
F_57 ( V_2 , V_111 ) ;
V_144 = F_77 ( V_2 , V_142 , V_141 -> V_109 , V_143 , V_141 -> V_154 ,
V_155 ) ;
if ( V_144 == - V_163 || V_144 == - V_164 )
return - V_163 ;
return 0 ;
V_12:
F_11 () ;
F_58 ( V_2 , V_111 ) ;
V_119:
F_78 ( V_2 ) ;
V_156:
if ( F_79 ( V_142 , 0 , V_143 , - V_163 ) > 0 )
return - V_163 ;
return 0 ;
}
static int F_80 ( struct V_165 * V_166 )
{
if ( V_166 -> args [ 1 ] )
F_81 ( (struct V_28 * ) V_166 -> args [ 1 ] ) ;
F_82 ( V_166 -> V_167 ) ;
return 0 ;
}
static struct V_168 *
F_83 ( const struct V_8 * const V_169 [] )
{
#ifdef F_70
struct V_168 * V_170 ;
V_170 = F_84 ( sizeof( * V_170 ) , V_171 ) ;
if ( V_170 == NULL )
return F_85 ( - V_172 ) ;
V_170 -> V_77 . V_173 = F_86 ( F_87 ( V_169 [ V_76 ] ) ) ;
V_170 -> V_77 . V_174 = F_86 ( F_87 ( V_169 [ V_175 ] ) ) ;
return V_170 ;
#else
return F_85 ( - V_176 ) ;
#endif
}
static int F_88 ( struct V_28 * V_29 , void * V_167 )
{
struct V_168 * V_170 = V_167 ;
if ( V_170 == NULL )
return 1 ;
#ifdef F_70
if ( ( V_29 -> V_77 & V_170 -> V_77 . V_174 ) == V_170 -> V_77 . V_173 )
return 1 ;
#endif
return 0 ;
}
static int
F_89 ( struct V_1 * V_2 , struct V_165 * V_166 )
{
struct V_142 * V_142 = F_90 ( V_2 -> V_177 ) ;
struct V_28 * V_29 , * V_178 ;
struct V_179 * V_180 ;
struct V_181 * V_182 ;
struct V_112 * V_113 = F_54 ( V_166 -> V_111 ) ;
V_135 V_18 = V_113 -> V_120 ;
int V_183 ;
T_4 * V_184 ;
V_178 = (struct V_28 * ) V_166 -> args [ 1 ] ;
F_91 () ;
for (; V_166 -> args [ 0 ] < V_185 ; V_166 -> args [ 0 ] ++ ) {
V_186:
V_184 = & V_187 [ V_166 -> args [ 0 ] % V_188 ] ;
F_92 ( V_184 ) ;
if ( V_166 -> args [ 0 ] >= V_185 ) {
F_93 ( V_184 ) ;
goto V_45;
}
F_94 (h, n, &nf_conntrack_hash[cb->args[0]],
hnnode) {
if ( F_95 ( V_180 ) != V_66 )
continue;
V_29 = F_96 ( V_180 ) ;
if ( ! F_97 ( V_142 , F_74 ( V_29 ) ) )
continue;
if ( V_18 && F_20 ( V_29 ) != V_18 )
continue;
if ( V_166 -> args [ 1 ] ) {
if ( V_29 != V_178 )
continue;
V_166 -> args [ 1 ] = 0 ;
}
if ( ! F_88 ( V_29 , V_166 -> V_167 ) )
continue;
F_8 () ;
V_183 =
F_52 ( V_2 , F_98 ( V_166 -> V_2 ) . V_109 ,
V_166 -> V_111 -> V_189 ,
F_99 ( V_166 -> V_111 -> V_190 ) ,
V_29 ) ;
F_11 () ;
if ( V_183 < 0 ) {
F_100 ( & V_29 -> V_107 ) ;
V_166 -> args [ 1 ] = ( unsigned long ) V_29 ;
F_93 ( V_184 ) ;
goto V_45;
}
}
F_93 ( V_184 ) ;
if ( V_166 -> args [ 1 ] ) {
V_166 -> args [ 1 ] = 0 ;
goto V_186;
}
}
V_45:
F_101 () ;
if ( V_178 )
F_81 ( V_178 ) ;
return V_2 -> V_79 ;
}
static int F_102 ( struct V_8 * V_53 ,
struct V_3 * V_4 )
{
struct V_8 * V_191 [ V_192 + 1 ] ;
struct V_17 * V_18 ;
int V_7 = 0 ;
V_7 = F_103 ( V_191 , V_192 , V_53 , NULL ) ;
if ( V_7 < 0 )
return V_7 ;
F_8 () ;
V_18 = F_9 ( V_4 -> V_20 . V_21 ) ;
if ( F_4 ( V_18 -> V_193 ) ) {
V_7 = F_104 ( V_53 , V_192 ,
V_18 -> V_194 ) ;
if ( V_7 == 0 )
V_7 = V_18 -> V_193 ( V_191 , V_4 ) ;
}
F_11 () ;
return V_7 ;
}
static int F_105 ( struct V_8 * V_53 ,
struct V_3 * V_4 )
{
struct V_8 * V_191 [ V_195 + 1 ] ;
struct V_5 * V_6 ;
int V_7 = 0 ;
V_7 = F_103 ( V_191 , V_195 , V_53 , V_196 ) ;
if ( V_7 < 0 )
return V_7 ;
if ( ! V_191 [ V_13 ] )
return - V_197 ;
V_4 -> V_14 . V_15 = F_106 ( V_191 [ V_13 ] ) ;
F_8 () ;
V_6 = F_10 ( V_4 -> V_20 . V_21 , V_4 -> V_14 . V_15 ) ;
if ( F_4 ( V_6 -> V_193 ) ) {
V_7 = F_104 ( V_53 , V_195 ,
V_6 -> V_194 ) ;
if ( V_7 == 0 )
V_7 = V_6 -> V_193 ( V_191 , V_4 ) ;
}
F_11 () ;
return V_7 ;
}
static int
F_107 ( const struct V_8 * V_53 ,
struct V_23 * V_24 )
{
F_108 ( V_24 , V_27 ,
V_130 , 0 ) ;
#ifdef F_71
if ( V_53 )
V_24 -> V_26 = F_109 ( F_110 ( V_53 ) ) ;
#else
if ( V_53 )
return - V_176 ;
#endif
return 0 ;
}
static int
F_111 ( struct V_8 * V_53 , enum V_52 type ,
struct V_23 * V_24 )
{
int V_7 ;
if ( V_24 -> V_26 != V_27 )
return - V_197 ;
V_7 = F_107 ( V_53 , V_24 ) ;
if ( V_7 < 0 )
return V_7 ;
if ( type == V_127 )
V_24 -> V_25 = V_128 ;
else
V_24 -> V_25 = V_126 ;
return 0 ;
}
static int
F_112 ( const struct V_8 * const V_169 [] ,
struct V_3 * V_4 ,
enum V_52 type , V_135 V_21 ,
struct V_23 * V_24 )
{
struct V_8 * V_191 [ V_198 + 1 ] ;
int V_144 ;
memset ( V_4 , 0 , sizeof( * V_4 ) ) ;
V_144 = F_103 ( V_191 , V_198 , V_169 [ type ] , V_199 ) ;
if ( V_144 < 0 )
return V_144 ;
if ( ! V_191 [ V_19 ] )
return - V_197 ;
V_4 -> V_20 . V_21 = V_21 ;
V_144 = F_102 ( V_191 [ V_19 ] , V_4 ) ;
if ( V_144 < 0 )
return V_144 ;
if ( ! V_191 [ V_10 ] )
return - V_197 ;
V_144 = F_105 ( V_191 [ V_10 ] , V_4 ) ;
if ( V_144 < 0 )
return V_144 ;
if ( V_191 [ V_125 ] ) {
if ( ! V_24 )
return - V_197 ;
V_144 = F_111 ( V_191 [ V_125 ] ,
type , V_24 ) ;
if ( V_144 < 0 )
return V_144 ;
}
if ( type == V_127 )
V_4 -> V_14 . V_25 = V_67 ;
else
V_4 -> V_14 . V_25 = V_66 ;
return 0 ;
}
static int F_113 ( const struct V_8 * V_53 , char * * V_200 ,
struct V_8 * * V_201 )
{
int V_144 ;
struct V_8 * V_191 [ V_202 + 1 ] ;
V_144 = F_103 ( V_191 , V_202 , V_53 , V_203 ) ;
if ( V_144 < 0 )
return V_144 ;
if ( ! V_191 [ V_47 ] )
return - V_197 ;
* V_200 = F_114 ( V_191 [ V_47 ] ) ;
if ( V_191 [ V_204 ] )
* V_201 = V_191 [ V_204 ] ;
return 0 ;
}
static int F_115 ( struct V_142 * V_142 ,
const struct V_8 * const V_169 [] ,
T_2 V_109 , int V_154 )
{
struct V_168 * V_170 = NULL ;
if ( V_169 [ V_76 ] && V_169 [ V_175 ] ) {
V_170 = F_83 ( V_169 ) ;
if ( F_116 ( V_170 ) )
return F_117 ( V_170 ) ;
}
F_118 ( V_142 , F_88 , V_170 ,
V_109 , V_154 ) ;
F_82 ( V_170 ) ;
return 0 ;
}
static int F_119 ( struct V_142 * V_142 , struct V_205 * V_206 ,
struct V_1 * V_2 ,
const struct V_110 * V_111 ,
const struct V_8 * const V_169 [] )
{
struct V_179 * V_180 ;
struct V_3 V_4 ;
struct V_28 * V_29 ;
struct V_112 * V_113 = F_54 ( V_111 ) ;
V_135 V_207 = V_113 -> V_120 ;
struct V_23 V_24 ;
int V_144 ;
V_144 = F_107 ( V_169 [ V_129 ] , & V_24 ) ;
if ( V_144 < 0 )
return V_144 ;
if ( V_169 [ V_124 ] )
V_144 = F_112 ( V_169 , & V_4 , V_124 ,
V_207 , & V_24 ) ;
else if ( V_169 [ V_127 ] )
V_144 = F_112 ( V_169 , & V_4 , V_127 ,
V_207 , & V_24 ) ;
else {
return F_115 ( V_142 , V_169 ,
F_98 ( V_2 ) . V_109 ,
F_120 ( V_111 ) ) ;
}
if ( V_144 < 0 )
return V_144 ;
V_180 = F_121 ( V_142 , & V_24 , & V_4 ) ;
if ( ! V_180 )
return - V_208 ;
V_29 = F_96 ( V_180 ) ;
if ( V_169 [ V_105 ] ) {
V_136 V_26 = F_86 ( F_87 ( V_169 [ V_105 ] ) ) ;
if ( V_26 != ( T_2 ) ( unsigned long ) V_29 ) {
F_81 ( V_29 ) ;
return - V_208 ;
}
}
if ( F_122 ( & V_29 -> V_32 ) )
F_123 ( V_29 , F_98 ( V_2 ) . V_109 , F_120 ( V_111 ) ) ;
F_81 ( V_29 ) ;
return 0 ;
}
static int F_124 ( struct V_142 * V_142 , struct V_205 * V_206 ,
struct V_1 * V_2 ,
const struct V_110 * V_111 ,
const struct V_8 * const V_169 [] )
{
struct V_179 * V_180 ;
struct V_3 V_4 ;
struct V_28 * V_29 ;
struct V_1 * V_209 = NULL ;
struct V_112 * V_113 = F_54 ( V_111 ) ;
V_135 V_207 = V_113 -> V_120 ;
struct V_23 V_24 ;
int V_144 ;
if ( V_111 -> V_210 & V_211 ) {
struct V_212 V_213 = {
. V_214 = F_89 ,
. V_215 = F_80 ,
} ;
if ( V_169 [ V_76 ] && V_169 [ V_175 ] ) {
struct V_168 * V_170 ;
V_170 = F_83 ( V_169 ) ;
if ( F_116 ( V_170 ) )
return F_117 ( V_170 ) ;
V_213 . V_167 = V_170 ;
}
return F_125 ( V_206 , V_2 , V_111 , & V_213 ) ;
}
V_144 = F_107 ( V_169 [ V_129 ] , & V_24 ) ;
if ( V_144 < 0 )
return V_144 ;
if ( V_169 [ V_124 ] )
V_144 = F_112 ( V_169 , & V_4 , V_124 ,
V_207 , & V_24 ) ;
else if ( V_169 [ V_127 ] )
V_144 = F_112 ( V_169 , & V_4 , V_127 ,
V_207 , & V_24 ) ;
else
return - V_197 ;
if ( V_144 < 0 )
return V_144 ;
V_180 = F_121 ( V_142 , & V_24 , & V_4 ) ;
if ( ! V_180 )
return - V_208 ;
V_29 = F_96 ( V_180 ) ;
V_144 = - V_172 ;
V_209 = F_76 ( V_216 , V_171 ) ;
if ( V_209 == NULL ) {
F_81 ( V_29 ) ;
return - V_172 ;
}
F_8 () ;
V_144 = F_52 ( V_209 , F_98 ( V_2 ) . V_109 , V_111 -> V_189 ,
F_99 ( V_111 -> V_190 ) , V_29 ) ;
F_11 () ;
F_81 ( V_29 ) ;
if ( V_144 <= 0 )
goto free;
V_144 = F_126 ( V_206 , V_209 , F_98 ( V_2 ) . V_109 , V_217 ) ;
if ( V_144 < 0 )
goto V_45;
return 0 ;
free:
F_78 ( V_209 ) ;
V_45:
return V_144 == - V_164 ? - V_163 : V_144 ;
}
static int F_127 ( struct V_165 * V_166 )
{
if ( V_166 -> args [ 1 ] )
F_81 ( (struct V_28 * ) V_166 -> args [ 1 ] ) ;
return 0 ;
}
static int
F_128 ( struct V_1 * V_2 , struct V_165 * V_166 , bool V_218 )
{
struct V_28 * V_29 , * V_178 ;
struct V_179 * V_180 ;
struct V_181 * V_182 ;
struct V_112 * V_113 = F_54 ( V_166 -> V_111 ) ;
V_135 V_18 = V_113 -> V_120 ;
int V_183 ;
int V_219 ;
struct V_220 * V_221 ;
struct V_142 * V_142 = F_90 ( V_2 -> V_177 ) ;
if ( V_166 -> args [ 2 ] )
return 0 ;
V_178 = (struct V_28 * ) V_166 -> args [ 1 ] ;
for ( V_219 = V_166 -> args [ 0 ] ; V_219 < V_222 ; V_219 ++ ) {
struct V_223 * V_224 ;
if ( ! F_129 ( V_219 ) )
continue;
V_224 = F_130 ( V_142 -> V_29 . V_225 , V_219 ) ;
F_131 ( & V_224 -> V_226 ) ;
V_221 = V_218 ? & V_224 -> V_218 : & V_224 -> V_227 ;
V_186:
F_94 (h, n, list, hnnode) {
V_29 = F_96 ( V_180 ) ;
if ( V_18 && F_20 ( V_29 ) != V_18 )
continue;
if ( V_166 -> args [ 1 ] ) {
if ( V_29 != V_178 )
continue;
V_166 -> args [ 1 ] = 0 ;
}
F_8 () ;
V_183 = F_52 ( V_2 , F_98 ( V_166 -> V_2 ) . V_109 ,
V_166 -> V_111 -> V_189 ,
F_99 ( V_166 -> V_111 -> V_190 ) ,
V_29 ) ;
F_11 () ;
if ( V_183 < 0 ) {
if ( ! F_132 ( & V_29 -> V_107 . V_108 ) )
continue;
V_166 -> args [ 0 ] = V_219 ;
V_166 -> args [ 1 ] = ( unsigned long ) V_29 ;
F_133 ( & V_224 -> V_226 ) ;
goto V_45;
}
}
if ( V_166 -> args [ 1 ] ) {
V_166 -> args [ 1 ] = 0 ;
goto V_186;
}
F_133 ( & V_224 -> V_226 ) ;
}
V_166 -> args [ 2 ] = 1 ;
V_45:
if ( V_178 )
F_81 ( V_178 ) ;
return V_2 -> V_79 ;
}
static int
F_134 ( struct V_1 * V_2 , struct V_165 * V_166 )
{
return F_128 ( V_2 , V_166 , true ) ;
}
static int F_135 ( struct V_142 * V_142 , struct V_205 * V_206 ,
struct V_1 * V_2 ,
const struct V_110 * V_111 ,
const struct V_8 * const V_169 [] )
{
if ( V_111 -> V_210 & V_211 ) {
struct V_212 V_213 = {
. V_214 = F_134 ,
. V_215 = F_127 ,
} ;
return F_125 ( V_206 , V_2 , V_111 , & V_213 ) ;
}
return - V_176 ;
}
static int
F_136 ( struct V_1 * V_2 , struct V_165 * V_166 )
{
return F_128 ( V_2 , V_166 , false ) ;
}
static int F_137 ( struct V_142 * V_142 , struct V_205 * V_206 ,
struct V_1 * V_2 ,
const struct V_110 * V_111 ,
const struct V_8 * const V_169 [] )
{
if ( V_111 -> V_210 & V_211 ) {
struct V_212 V_213 = {
. V_214 = F_136 ,
. V_215 = F_127 ,
} ;
return F_125 ( V_206 , V_2 , V_111 , & V_213 ) ;
}
return - V_176 ;
}
static int
F_138 ( struct V_28 * V_29 ,
enum V_228 V_229 ,
const struct V_8 * V_53 )
{
F_139 (nfnetlink_parse_nat_setup_hook) V_230 ;
int V_144 ;
V_230 = F_24 ( V_231 ) ;
if ( ! V_230 ) {
#ifdef F_140
F_11 () ;
F_141 ( V_117 ) ;
if ( F_142 ( L_1 ) < 0 ) {
F_143 ( V_117 ) ;
F_8 () ;
return - V_176 ;
}
F_143 ( V_117 ) ;
F_8 () ;
if ( V_231 )
return - V_164 ;
#endif
return - V_176 ;
}
V_144 = V_230 ( V_29 , V_229 , V_53 ) ;
if ( V_144 == - V_164 ) {
#ifdef F_140
F_11 () ;
F_141 ( V_117 ) ;
if ( F_142 ( L_2 , F_20 ( V_29 ) ) < 0 ) {
F_143 ( V_117 ) ;
F_8 () ;
return - V_176 ;
}
F_143 ( V_117 ) ;
F_8 () ;
#else
V_144 = - V_176 ;
#endif
}
return V_144 ;
}
static int
F_144 ( struct V_28 * V_29 , const struct V_8 * const V_169 [] )
{
unsigned long V_232 ;
unsigned int V_31 = F_86 ( F_87 ( V_169 [ V_30 ] ) ) ;
V_232 = V_29 -> V_31 ^ V_31 ;
if ( V_232 & ( V_90 | V_233 | V_234 ) )
return - V_235 ;
if ( V_232 & V_236 && ! ( V_31 & V_236 ) )
return - V_235 ;
if ( V_232 & V_237 && ! ( V_31 & V_237 ) )
return - V_235 ;
V_29 -> V_31 |= V_31 & ~ ( V_238 | V_239 ) ;
return 0 ;
}
static int
F_145 ( struct V_28 * V_29 , const struct V_8 * const V_169 [] )
{
#ifdef F_69
int V_7 ;
if ( ! V_169 [ V_240 ] && ! V_169 [ V_241 ] )
return 0 ;
V_7 = F_138 ( V_29 , V_242 ,
V_169 [ V_240 ] ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_138 ( V_29 , V_243 ,
V_169 [ V_241 ] ) ;
return V_7 ;
#else
if ( ! V_169 [ V_240 ] && ! V_169 [ V_241 ] )
return 0 ;
return - V_176 ;
#endif
}
static int F_146 ( struct V_28 * V_29 ,
const struct V_8 * const V_169 [] )
{
struct V_43 * V_44 ;
struct V_41 * V_42 = F_23 ( V_29 ) ;
char * V_244 = NULL ;
struct V_8 * V_201 = NULL ;
int V_144 ;
if ( V_29 -> V_245 )
return - V_235 ;
V_144 = F_113 ( V_169 [ V_46 ] , & V_244 , & V_201 ) ;
if ( V_144 < 0 )
return V_144 ;
if ( ! strcmp ( V_244 , L_3 ) ) {
if ( V_42 && V_42 -> V_44 ) {
F_147 ( V_29 ) ;
F_148 ( V_42 -> V_44 , NULL ) ;
}
return 0 ;
}
V_44 = F_149 ( V_244 , F_20 ( V_29 ) ,
F_21 ( V_29 ) ) ;
if ( V_44 == NULL ) {
#ifdef F_140
F_133 ( & V_246 ) ;
if ( F_142 ( L_4 , V_244 ) < 0 ) {
F_131 ( & V_246 ) ;
return - V_176 ;
}
F_131 ( & V_246 ) ;
V_44 = F_149 ( V_244 , F_20 ( V_29 ) ,
F_21 ( V_29 ) ) ;
if ( V_44 )
return - V_164 ;
#endif
return - V_176 ;
}
if ( V_42 ) {
if ( V_42 -> V_44 == V_44 ) {
if ( V_44 -> V_247 )
V_44 -> V_247 ( V_201 , V_29 ) ;
return 0 ;
} else
return - V_235 ;
}
return - V_176 ;
}
static int F_150 ( struct V_28 * V_29 ,
const struct V_8 * const V_169 [] )
{
V_136 V_32 = F_86 ( F_87 ( V_169 [ V_36 ] ) ) ;
if ( ! F_122 ( & V_29 -> V_32 ) )
return - V_248 ;
V_29 -> V_32 . V_33 = V_34 + V_32 * V_35 ;
F_151 ( & V_29 -> V_32 ) ;
return 0 ;
}
static int F_152 ( struct V_28 * V_29 ,
const struct V_8 * const V_169 [] )
{
const struct V_8 * V_53 = V_169 [ V_39 ] ;
struct V_8 * V_191 [ V_249 + 1 ] ;
struct V_5 * V_6 ;
int V_144 = 0 ;
V_144 = F_103 ( V_191 , V_249 , V_53 , V_250 ) ;
if ( V_144 < 0 )
return V_144 ;
F_8 () ;
V_6 = F_10 ( F_20 ( V_29 ) , F_21 ( V_29 ) ) ;
if ( V_6 -> V_247 )
V_144 = V_6 -> V_247 ( V_191 , V_29 ) ;
F_11 () ;
return V_144 ;
}
static int F_153 ( struct V_92 * V_93 ,
const struct V_8 * const V_53 )
{
int V_144 ;
struct V_8 * V_169 [ V_251 + 1 ] ;
V_144 = F_103 ( V_169 , V_251 , V_53 , V_252 ) ;
if ( V_144 < 0 )
return V_144 ;
if ( ! V_169 [ V_94 ] )
return - V_197 ;
V_93 -> V_95 =
F_86 ( F_87 ( V_169 [ V_94 ] ) ) ;
if ( ! V_169 [ V_96 ] )
return - V_197 ;
V_93 -> V_97 =
F_86 ( F_87 ( V_169 [ V_96 ] ) ) ;
if ( ! V_169 [ V_98 ] )
return - V_197 ;
V_93 -> V_99 =
F_86 ( F_87 ( V_169 [ V_98 ] ) ) ;
return 0 ;
}
static int
F_154 ( struct V_28 * V_29 ,
const struct V_8 * const V_169 [] )
{
struct V_100 * V_101 = F_48 ( V_29 ) ;
int V_7 = 0 ;
if ( ! V_101 )
return 0 ;
if ( V_169 [ V_103 ] ) {
V_7 = F_153 ( & V_101 -> V_93 [ V_66 ] ,
V_169 [ V_103 ] ) ;
if ( V_7 < 0 )
return V_7 ;
V_29 -> V_31 |= V_102 ;
}
if ( V_169 [ V_104 ] ) {
V_7 = F_153 ( & V_101 -> V_93 [ V_67 ] ,
V_169 [ V_104 ] ) ;
if ( V_7 < 0 )
return V_7 ;
V_29 -> V_31 |= V_102 ;
}
return 0 ;
}
static int
F_155 ( struct V_28 * V_29 , const struct V_8 * const V_169 [] )
{
#ifdef F_156
T_3 V_79 = F_157 ( V_169 [ V_89 ] ) ;
const void * V_174 = V_169 [ V_253 ] ;
if ( V_79 & ( sizeof( T_2 ) - 1 ) )
return - V_197 ;
if ( V_174 ) {
if ( F_157 ( V_169 [ V_253 ] ) == 0 ||
F_157 ( V_169 [ V_253 ] ) != V_79 )
return - V_197 ;
V_174 = F_114 ( V_169 [ V_253 ] ) ;
}
V_79 /= sizeof( T_2 ) ;
return F_158 ( V_29 , F_114 ( V_169 [ V_89 ] ) , V_174 , V_79 ) ;
#else
return - V_176 ;
#endif
}
static int
F_159 ( struct V_28 * V_29 ,
const struct V_8 * const V_169 [] )
{
int V_144 ;
if ( V_169 [ V_241 ] || V_169 [ V_240 ] || V_169 [ V_91 ] )
return - V_176 ;
if ( V_169 [ V_46 ] ) {
V_144 = F_146 ( V_29 , V_169 ) ;
if ( V_144 < 0 )
return V_144 ;
}
if ( V_169 [ V_36 ] ) {
V_144 = F_150 ( V_29 , V_169 ) ;
if ( V_144 < 0 )
return V_144 ;
}
if ( V_169 [ V_30 ] ) {
V_144 = F_144 ( V_29 , V_169 ) ;
if ( V_144 < 0 )
return V_144 ;
}
if ( V_169 [ V_39 ] ) {
V_144 = F_152 ( V_29 , V_169 ) ;
if ( V_144 < 0 )
return V_144 ;
}
#if F_160 ( F_70 )
if ( V_169 [ V_76 ] )
V_29 -> V_77 = F_86 ( F_87 ( V_169 [ V_76 ] ) ) ;
#endif
if ( V_169 [ V_103 ] || V_169 [ V_104 ] ) {
V_144 = F_154 ( V_29 , V_169 ) ;
if ( V_144 < 0 )
return V_144 ;
}
if ( V_169 [ V_89 ] ) {
V_144 = F_155 ( V_29 , V_169 ) ;
if ( V_144 < 0 )
return V_144 ;
}
return 0 ;
}
static struct V_28 *
F_161 ( struct V_142 * V_142 ,
const struct V_23 * V_24 ,
const struct V_8 * const V_169 [] ,
struct V_3 * V_254 ,
struct V_3 * V_255 ,
T_5 V_207 )
{
struct V_28 * V_29 ;
int V_144 = - V_197 ;
struct V_43 * V_44 ;
struct V_68 * V_69 ;
V_29 = F_162 ( V_142 , V_24 , V_254 , V_255 , V_155 ) ;
if ( F_116 ( V_29 ) )
return F_85 ( - V_172 ) ;
if ( ! V_169 [ V_36 ] )
goto V_256;
V_29 -> V_32 . V_33 = F_86 ( F_87 ( V_169 [ V_36 ] ) ) ;
V_29 -> V_32 . V_33 = V_34 + V_29 -> V_32 . V_33 * V_35 ;
F_8 () ;
if ( V_169 [ V_46 ] ) {
char * V_244 = NULL ;
struct V_8 * V_201 = NULL ;
V_144 = F_113 ( V_169 [ V_46 ] , & V_244 , & V_201 ) ;
if ( V_144 < 0 )
goto V_257;
V_44 = F_149 ( V_244 , F_20 ( V_29 ) ,
F_21 ( V_29 ) ) ;
if ( V_44 == NULL ) {
F_11 () ;
#ifdef F_140
if ( F_142 ( L_4 , V_244 ) < 0 ) {
V_144 = - V_176 ;
goto V_256;
}
F_8 () ;
V_44 = F_149 ( V_244 ,
F_20 ( V_29 ) ,
F_21 ( V_29 ) ) ;
if ( V_44 ) {
V_144 = - V_164 ;
goto V_257;
}
F_11 () ;
#endif
V_144 = - V_176 ;
goto V_256;
} else {
struct V_41 * V_42 ;
V_42 = F_163 ( V_29 , V_44 , V_155 ) ;
if ( V_42 == NULL ) {
V_144 = - V_172 ;
goto V_257;
}
if ( V_44 -> V_247 )
V_44 -> V_247 ( V_201 , V_29 ) ;
F_148 ( V_42 -> V_44 , V_44 ) ;
}
} else {
V_144 = F_164 ( V_29 , NULL , V_155 ) ;
if ( V_144 < 0 )
goto V_257;
}
V_144 = F_145 ( V_29 , V_169 ) ;
if ( V_144 < 0 )
goto V_257;
F_165 ( V_29 , V_155 ) ;
F_166 ( V_29 , V_155 ) ;
F_167 ( V_29 , 0 , 0 , V_155 ) ;
F_168 ( V_29 ) ;
V_29 -> V_31 |= V_233 ;
if ( V_169 [ V_30 ] ) {
V_144 = F_144 ( V_29 , V_169 ) ;
if ( V_144 < 0 )
goto V_257;
}
if ( V_169 [ V_103 ] || V_169 [ V_104 ] ) {
V_144 = F_154 ( V_29 , V_169 ) ;
if ( V_144 < 0 )
goto V_257;
}
memset ( & V_29 -> V_258 , 0 , sizeof( V_29 -> V_258 ) ) ;
if ( V_169 [ V_39 ] ) {
V_144 = F_152 ( V_29 , V_169 ) ;
if ( V_144 < 0 )
goto V_257;
}
#if F_160 ( F_70 )
if ( V_169 [ V_76 ] )
V_29 -> V_77 = F_86 ( F_87 ( V_169 [ V_76 ] ) ) ;
#endif
if ( V_169 [ V_91 ] ) {
struct V_3 V_245 ;
struct V_179 * V_259 ;
struct V_28 * V_260 ;
V_144 = F_112 ( V_169 , & V_245 , V_91 ,
V_207 , NULL ) ;
if ( V_144 < 0 )
goto V_257;
V_259 = F_121 ( V_142 , V_24 , & V_245 ) ;
if ( V_259 == NULL ) {
V_144 = - V_208 ;
goto V_257;
}
V_260 = F_96 ( V_259 ) ;
F_169 ( V_261 , & V_29 -> V_31 ) ;
V_29 -> V_245 = V_260 ;
}
V_69 = F_34 ( V_29 ) ;
if ( V_69 )
V_69 -> V_72 = F_170 () ;
V_144 = F_171 ( V_29 ) ;
if ( V_144 < 0 )
goto V_257;
F_11 () ;
return V_29 ;
V_257:
F_11 () ;
V_256:
F_172 ( V_29 ) ;
return F_85 ( V_144 ) ;
}
static int F_173 ( struct V_142 * V_142 , struct V_205 * V_206 ,
struct V_1 * V_2 ,
const struct V_110 * V_111 ,
const struct V_8 * const V_169 [] )
{
struct V_3 V_254 , V_255 ;
struct V_179 * V_180 = NULL ;
struct V_112 * V_113 = F_54 ( V_111 ) ;
struct V_28 * V_29 ;
V_135 V_207 = V_113 -> V_120 ;
struct V_23 V_24 ;
int V_144 ;
V_144 = F_107 ( V_169 [ V_129 ] , & V_24 ) ;
if ( V_144 < 0 )
return V_144 ;
if ( V_169 [ V_124 ] ) {
V_144 = F_112 ( V_169 , & V_254 , V_124 ,
V_207 , & V_24 ) ;
if ( V_144 < 0 )
return V_144 ;
}
if ( V_169 [ V_127 ] ) {
V_144 = F_112 ( V_169 , & V_255 , V_127 ,
V_207 , & V_24 ) ;
if ( V_144 < 0 )
return V_144 ;
}
if ( V_169 [ V_124 ] )
V_180 = F_121 ( V_142 , & V_24 , & V_254 ) ;
else if ( V_169 [ V_127 ] )
V_180 = F_121 ( V_142 , & V_24 , & V_255 ) ;
if ( V_180 == NULL ) {
V_144 = - V_208 ;
if ( V_111 -> V_210 & V_150 ) {
enum V_262 V_139 ;
if ( ! V_169 [ V_124 ] || ! V_169 [ V_127 ] )
return - V_197 ;
V_29 = F_161 ( V_142 , & V_24 , V_169 , & V_254 ,
& V_255 , V_207 ) ;
if ( F_116 ( V_29 ) )
return F_117 ( V_29 ) ;
V_144 = 0 ;
if ( F_174 ( V_261 , & V_29 -> V_31 ) )
V_139 = V_149 ;
else
V_139 = V_148 ;
if ( V_169 [ V_89 ] &&
F_155 ( V_29 , V_169 ) == 0 )
V_139 |= ( 1 << V_160 ) ;
F_175 ( ( 1 << V_263 ) |
( 1 << V_264 ) |
( 1 << V_158 ) |
( 1 << V_157 ) |
( 1 << V_161 ) |
( 1 << V_162 ) | V_139 ,
V_29 , F_98 ( V_2 ) . V_109 ,
F_120 ( V_111 ) ) ;
F_81 ( V_29 ) ;
}
return V_144 ;
}
V_144 = - V_265 ;
V_29 = F_96 ( V_180 ) ;
if ( ! ( V_111 -> V_210 & V_151 ) ) {
F_131 ( & V_246 ) ;
V_144 = F_159 ( V_29 , V_169 ) ;
F_133 ( & V_246 ) ;
if ( V_144 == 0 ) {
F_175 ( ( 1 << V_263 ) |
( 1 << V_264 ) |
( 1 << V_158 ) |
( 1 << V_160 ) |
( 1 << V_157 ) |
( 1 << V_161 ) |
( 1 << V_162 ) ,
V_29 , F_98 ( V_2 ) . V_109 ,
F_120 ( V_111 ) ) ;
}
}
F_81 ( V_29 ) ;
return V_144 ;
}
static int
F_176 ( struct V_1 * V_2 , T_2 V_109 , T_2 V_93 ,
T_6 V_219 , const struct V_266 * V_267 )
{
struct V_110 * V_111 ;
struct V_112 * V_113 ;
unsigned int V_114 = V_109 ? V_115 : 0 , V_116 ;
V_116 = ( V_117 << 8 | V_268 ) ;
V_111 = F_53 ( V_2 , V_109 , V_93 , V_116 , sizeof( * V_113 ) , V_114 ) ;
if ( V_111 == NULL )
goto V_119;
V_113 = F_54 ( V_111 ) ;
V_113 -> V_120 = V_269 ;
V_113 -> V_121 = V_122 ;
V_113 -> V_123 = F_14 ( V_219 ) ;
if ( F_16 ( V_2 , V_270 , F_17 ( V_267 -> V_271 ) ) ||
F_16 ( V_2 , V_272 , F_17 ( V_267 -> V_273 ) ) ||
F_16 ( V_2 , V_274 , F_17 ( V_267 -> V_275 ) ) ||
F_16 ( V_2 , V_276 , F_17 ( V_267 -> V_277 ) ) ||
F_16 ( V_2 , V_278 , F_17 ( V_267 -> V_279 ) ) ||
F_16 ( V_2 , V_280 , F_17 ( V_267 -> V_281 ) ) ||
F_16 ( V_2 , V_282 , F_17 ( V_267 -> V_283 ) ) ||
F_16 ( V_2 , V_284 , F_17 ( V_267 -> V_285 ) ) ||
F_16 ( V_2 , V_286 ,
F_17 ( V_267 -> V_287 ) ) ||
F_16 ( V_2 , V_288 , F_17 ( V_267 -> V_289 ) ) ||
F_16 ( V_2 , V_290 , F_17 ( V_267 -> V_291 ) ) ||
F_16 ( V_2 , V_292 , F_17 ( V_267 -> error ) ) ||
F_16 ( V_2 , V_293 ,
F_17 ( V_267 -> V_294 ) ) )
goto V_12;
F_57 ( V_2 , V_111 ) ;
return V_2 -> V_79 ;
V_12:
V_119:
F_58 ( V_2 , V_111 ) ;
return - 1 ;
}
static int
F_177 ( struct V_1 * V_2 , struct V_165 * V_166 )
{
int V_219 ;
struct V_142 * V_142 = F_90 ( V_2 -> V_177 ) ;
if ( V_166 -> args [ 0 ] == V_222 )
return 0 ;
for ( V_219 = V_166 -> args [ 0 ] ; V_219 < V_222 ; V_219 ++ ) {
const struct V_266 * V_267 ;
if ( ! F_129 ( V_219 ) )
continue;
V_267 = F_130 ( V_142 -> V_29 . V_295 , V_219 ) ;
if ( F_176 ( V_2 ,
F_98 ( V_166 -> V_2 ) . V_109 ,
V_166 -> V_111 -> V_189 ,
V_219 , V_267 ) < 0 )
break;
}
V_166 -> args [ 0 ] = V_219 ;
return V_2 -> V_79 ;
}
static int F_178 ( struct V_142 * V_142 , struct V_205 * V_206 ,
struct V_1 * V_2 ,
const struct V_110 * V_111 ,
const struct V_8 * const V_169 [] )
{
if ( V_111 -> V_210 & V_211 ) {
struct V_212 V_213 = {
. V_214 = F_177 ,
} ;
return F_125 ( V_206 , V_2 , V_111 , & V_213 ) ;
}
return 0 ;
}
static int
F_179 ( struct V_1 * V_2 , T_2 V_109 , T_2 V_93 , T_2 type ,
struct V_142 * V_142 )
{
struct V_110 * V_111 ;
struct V_112 * V_113 ;
unsigned int V_114 = V_109 ? V_115 : 0 , V_116 ;
unsigned int V_296 = F_51 ( & V_142 -> V_29 . V_297 ) ;
V_116 = ( V_117 << 8 | V_298 ) ;
V_111 = F_53 ( V_2 , V_109 , V_93 , V_116 , sizeof( * V_113 ) , V_114 ) ;
if ( V_111 == NULL )
goto V_119;
V_113 = F_54 ( V_111 ) ;
V_113 -> V_120 = V_269 ;
V_113 -> V_121 = V_122 ;
V_113 -> V_123 = 0 ;
if ( F_16 ( V_2 , V_299 , F_17 ( V_296 ) ) )
goto V_12;
F_57 ( V_2 , V_111 ) ;
return V_2 -> V_79 ;
V_12:
V_119:
F_58 ( V_2 , V_111 ) ;
return - 1 ;
}
static int F_180 ( struct V_142 * V_142 , struct V_205 * V_206 ,
struct V_1 * V_2 , const struct V_110 * V_111 ,
const struct V_8 * const V_169 [] )
{
struct V_1 * V_209 ;
int V_144 ;
V_209 = F_76 ( V_216 , V_171 ) ;
if ( V_209 == NULL )
return - V_172 ;
V_144 = F_179 ( V_209 , F_98 ( V_2 ) . V_109 ,
V_111 -> V_189 ,
F_99 ( V_111 -> V_190 ) ,
F_90 ( V_2 -> V_177 ) ) ;
if ( V_144 <= 0 )
goto free;
V_144 = F_126 ( V_206 , V_209 , F_98 ( V_2 ) . V_109 , V_217 ) ;
if ( V_144 < 0 )
goto V_45;
return 0 ;
free:
F_78 ( V_209 ) ;
V_45:
return V_144 == - V_164 ? - V_163 : V_144 ;
}
static T_3
F_181 ( const struct V_28 * V_29 )
{
return 3 * F_41 ( 0 )
+ 3 * F_41 ( 0 )
+ 3 * F_41 ( 0 )
+ 3 * F_41 ( sizeof( V_135 ) )
+ F_41 ( sizeof( V_136 ) )
+ F_41 ( sizeof( V_136 ) )
+ F_41 ( sizeof( V_136 ) )
+ F_41 ( 0 )
+ F_41 ( 0 )
+ F_41 ( V_137 )
+ F_63 ( V_29 )
#ifdef F_69
+ 2 * F_41 ( 0 )
+ 6 * F_41 ( sizeof( V_136 ) )
#endif
#ifdef F_70
+ F_41 ( sizeof( V_136 ) )
#endif
#ifdef F_71
+ F_41 ( sizeof( V_138 ) )
#endif
+ F_59 ( V_29 )
;
}
static struct V_28 * F_182 ( const struct V_1 * V_2 ,
enum V_300 * V_301 )
{
struct V_28 * V_29 ;
V_29 = F_183 ( V_2 , V_301 ) ;
if ( V_29 && F_73 ( V_29 ) )
V_29 = NULL ;
return V_29 ;
}
static int F_184 ( struct V_1 * V_2 , struct V_28 * V_29 )
{
const struct V_23 * V_24 ;
struct V_8 * V_9 ;
F_8 () ;
V_24 = F_55 ( V_29 ) ;
V_9 = F_2 ( V_2 , V_124 | V_11 ) ;
if ( ! V_9 )
goto V_12;
if ( F_7 ( V_2 , F_56 ( V_29 , V_66 ) ) < 0 )
goto V_12;
if ( F_12 ( V_2 , V_125 , V_24 ,
V_126 ) < 0 )
goto V_12;
F_5 ( V_2 , V_9 ) ;
V_9 = F_2 ( V_2 , V_127 | V_11 ) ;
if ( ! V_9 )
goto V_12;
if ( F_7 ( V_2 , F_56 ( V_29 , V_67 ) ) < 0 )
goto V_12;
if ( F_12 ( V_2 , V_125 , V_24 ,
V_128 ) < 0 )
goto V_12;
F_5 ( V_2 , V_9 ) ;
if ( F_12 ( V_2 , V_129 , V_24 ,
V_130 ) < 0 )
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
#ifdef F_64
if ( V_29 -> V_81 && F_36 ( V_2 , V_29 ) < 0 )
goto V_12;
#endif
if ( V_29 -> V_245 && F_44 ( V_2 , V_29 ) < 0 )
goto V_12;
if ( ( V_29 -> V_31 & V_102 ) &&
F_47 ( V_2 , V_29 ) < 0 )
goto V_12;
#ifdef F_70
if ( V_29 -> V_77 && F_35 ( V_2 , V_29 ) < 0 )
goto V_12;
#endif
if ( F_42 ( V_2 , V_29 ) < 0 )
goto V_12;
F_11 () ;
return 0 ;
V_12:
F_11 () ;
return - V_302 ;
}
static int
F_185 ( struct V_1 * V_2 , struct V_28 * V_29 ,
enum V_300 V_301 ,
V_138 V_303 , V_138 V_304 )
{
struct V_8 * V_9 ;
V_9 = F_2 ( V_2 , V_303 | V_11 ) ;
if ( ! V_9 )
goto V_12;
if ( F_184 ( V_2 , V_29 ) < 0 )
goto V_12;
F_5 ( V_2 , V_9 ) ;
if ( F_16 ( V_2 , V_304 , F_17 ( V_301 ) ) )
goto V_12;
return 0 ;
V_12:
return - V_302 ;
}
static int
F_186 ( const struct V_8 * V_169 [] , struct V_28 * V_29 )
{
int V_144 ;
if ( V_169 [ V_36 ] ) {
V_144 = F_150 ( V_29 , V_169 ) ;
if ( V_144 < 0 )
return V_144 ;
}
if ( V_169 [ V_30 ] ) {
V_144 = F_144 ( V_29 , V_169 ) ;
if ( V_144 < 0 )
return V_144 ;
}
if ( V_169 [ V_46 ] ) {
V_144 = F_146 ( V_29 , V_169 ) ;
if ( V_144 < 0 )
return V_144 ;
}
if ( V_169 [ V_89 ] ) {
V_144 = F_155 ( V_29 , V_169 ) ;
if ( V_144 < 0 )
return V_144 ;
}
#if F_160 ( F_70 )
if ( V_169 [ V_76 ] ) {
T_2 V_174 = 0 , V_77 , V_305 ;
if ( V_169 [ V_175 ] )
V_174 = ~ F_86 ( F_87 ( V_169 [ V_175 ] ) ) ;
V_77 = F_86 ( F_87 ( V_169 [ V_76 ] ) ) ;
V_305 = ( V_29 -> V_77 & V_174 ) ^ V_77 ;
if ( V_305 != V_29 -> V_77 )
V_29 -> V_77 = V_305 ;
}
#endif
return 0 ;
}
static int
F_187 ( const struct V_8 * V_53 , struct V_28 * V_29 )
{
struct V_8 * V_169 [ V_306 + 1 ] ;
int V_7 ;
V_7 = F_103 ( V_169 , V_306 , V_53 , V_307 ) ;
if ( V_7 < 0 )
return V_7 ;
F_131 ( & V_246 ) ;
V_7 = F_186 ( ( const struct V_8 * * ) V_169 , V_29 ) ;
F_133 ( & V_246 ) ;
return V_7 ;
}
static int F_188 ( const struct V_8 * const * V_169 ,
const struct V_28 * V_29 ,
struct V_3 * V_4 ,
struct V_3 * V_174 )
{
int V_144 ;
V_144 = F_112 ( V_169 , V_4 , V_308 ,
F_20 ( V_29 ) , NULL ) ;
if ( V_144 < 0 )
return V_144 ;
return F_112 ( V_169 , V_174 , V_309 ,
F_20 ( V_29 ) , NULL ) ;
}
static int
F_189 ( const struct V_8 * V_53 , struct V_28 * V_29 ,
T_2 V_109 , T_2 V_154 )
{
struct V_8 * V_169 [ V_310 + 1 ] ;
struct V_3 V_4 , V_174 ;
struct V_43 * V_44 = NULL ;
struct V_311 * exp ;
int V_144 ;
V_144 = F_103 ( V_169 , V_310 , V_53 , V_312 ) ;
if ( V_144 < 0 )
return V_144 ;
V_144 = F_188 ( ( const struct V_8 * const * ) V_169 ,
V_29 , & V_4 , & V_174 ) ;
if ( V_144 < 0 )
return V_144 ;
if ( V_169 [ V_313 ] ) {
const char * V_244 = F_114 ( V_169 [ V_313 ] ) ;
V_44 = F_149 ( V_244 , F_20 ( V_29 ) ,
F_21 ( V_29 ) ) ;
if ( V_44 == NULL )
return - V_176 ;
}
exp = F_190 ( ( const struct V_8 * const * ) V_169 , V_29 ,
V_44 , & V_4 , & V_174 ) ;
if ( F_116 ( exp ) )
return F_117 ( exp ) ;
V_144 = F_191 ( exp , V_109 , V_154 ) ;
if ( V_144 < 0 ) {
F_192 ( exp ) ;
return V_144 ;
}
return 0 ;
}
static void F_193 ( struct V_1 * V_2 , struct V_28 * V_29 ,
enum V_300 V_301 , int V_314 )
{
if ( ! ( V_29 -> V_31 & V_239 ) )
return;
F_194 ( V_2 , V_29 , V_301 , V_314 ) ;
}
static int F_195 ( struct V_1 * V_2 ,
const struct V_3 * V_4 ,
enum V_315 type )
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
static int F_196 ( struct V_1 * V_2 ,
const struct V_3 * V_4 ,
const struct V_316 * V_174 )
{
int V_7 ;
struct V_17 * V_18 ;
struct V_5 * V_6 ;
struct V_3 V_317 ;
struct V_8 * V_9 ;
memset ( & V_317 , 0xFF , sizeof( V_317 ) ) ;
memcpy ( & V_317 . V_20 . V_207 , & V_174 -> V_20 . V_207 , sizeof( V_317 . V_20 . V_207 ) ) ;
V_317 . V_20 . V_318 . V_319 = V_174 -> V_20 . V_318 . V_319 ;
V_317 . V_14 . V_15 = V_4 -> V_14 . V_15 ;
V_9 = F_2 ( V_2 , V_309 | V_11 ) ;
if ( ! V_9 )
goto V_12;
F_8 () ;
V_18 = F_9 ( V_4 -> V_20 . V_21 ) ;
V_7 = F_6 ( V_2 , & V_317 , V_18 ) ;
if ( V_7 >= 0 ) {
V_6 = F_10 ( V_4 -> V_20 . V_21 ,
V_4 -> V_14 . V_15 ) ;
V_7 = F_1 ( V_2 , & V_317 , V_6 ) ;
}
F_11 () ;
if ( F_197 ( V_7 < 0 ) )
goto V_12;
F_5 ( V_2 , V_9 ) ;
return 0 ;
V_12:
return - 1 ;
}
static int
F_198 ( struct V_1 * V_2 ,
const struct V_311 * exp )
{
struct V_28 * V_245 = exp -> V_245 ;
long V_32 = ( ( long ) exp -> V_32 . V_33 - ( long ) V_34 ) / V_35 ;
struct V_41 * V_42 ;
#ifdef F_69
struct V_8 * V_9 ;
struct V_3 V_320 = {} ;
#endif
struct V_321 * V_322 ;
if ( V_32 < 0 )
V_32 = 0 ;
if ( F_195 ( V_2 , & exp -> V_4 , V_308 ) < 0 )
goto V_12;
if ( F_196 ( V_2 , & exp -> V_4 , & exp -> V_174 ) < 0 )
goto V_12;
if ( F_195 ( V_2 ,
& V_245 -> V_323 [ V_66 ] . V_4 ,
V_324 ) < 0 )
goto V_12;
#ifdef F_69
if ( ! F_199 ( & exp -> V_325 , & V_326 ) ||
exp -> V_327 . V_319 ) {
V_9 = F_2 ( V_2 , V_328 | V_11 ) ;
if ( ! V_9 )
goto V_12;
if ( F_16 ( V_2 , V_329 , F_17 ( exp -> V_25 ) ) )
goto V_12;
V_320 . V_20 . V_21 = F_20 ( V_245 ) ;
V_320 . V_20 . V_207 = exp -> V_325 ;
V_320 . V_14 . V_15 = F_21 ( V_245 ) ;
V_320 . V_20 . V_318 = exp -> V_327 ;
if ( F_195 ( V_2 , & V_320 ,
V_330 ) < 0 )
goto V_12;
F_5 ( V_2 , V_9 ) ;
}
#endif
if ( F_16 ( V_2 , V_331 , F_17 ( V_32 ) ) ||
F_16 ( V_2 , V_332 , F_17 ( ( unsigned long ) exp ) ) ||
F_16 ( V_2 , V_333 , F_17 ( exp -> V_114 ) ) ||
F_16 ( V_2 , V_334 , F_17 ( exp -> V_335 ) ) )
goto V_12;
V_42 = F_23 ( V_245 ) ;
if ( V_42 ) {
struct V_43 * V_44 ;
V_44 = F_24 ( V_42 -> V_44 ) ;
if ( V_44 &&
F_25 ( V_2 , V_313 , V_44 -> V_48 ) )
goto V_12;
}
V_322 = F_200 ( exp -> V_336 ) ;
if ( V_322 != NULL &&
F_25 ( V_2 , V_337 , V_322 -> V_48 ) )
goto V_12;
return 0 ;
V_12:
return - 1 ;
}
static int
F_201 ( struct V_1 * V_2 , T_2 V_109 , T_2 V_93 ,
int V_116 , const struct V_311 * exp )
{
struct V_110 * V_111 ;
struct V_112 * V_113 ;
unsigned int V_114 = V_109 ? V_115 : 0 ;
V_116 |= V_338 << 8 ;
V_111 = F_53 ( V_2 , V_109 , V_93 , V_116 , sizeof( * V_113 ) , V_114 ) ;
if ( V_111 == NULL )
goto V_119;
V_113 = F_54 ( V_111 ) ;
V_113 -> V_120 = exp -> V_4 . V_20 . V_21 ;
V_113 -> V_121 = V_122 ;
V_113 -> V_123 = 0 ;
if ( F_198 ( V_2 , exp ) < 0 )
goto V_12;
F_57 ( V_2 , V_111 ) ;
return V_2 -> V_79 ;
V_119:
V_12:
F_58 ( V_2 , V_111 ) ;
return - 1 ;
}
static int
F_202 ( unsigned int V_139 , struct V_339 * V_141 )
{
struct V_311 * exp = V_141 -> exp ;
struct V_142 * V_142 = F_203 ( exp ) ;
struct V_110 * V_111 ;
struct V_112 * V_113 ;
struct V_1 * V_2 ;
unsigned int type , V_143 ;
int V_114 = 0 ;
if ( V_139 & ( 1 << V_340 ) ) {
type = V_341 ;
V_143 = V_342 ;
} else if ( V_139 & ( 1 << V_343 ) ) {
type = V_344 ;
V_114 = V_150 | V_151 ;
V_143 = V_345 ;
} else
return 0 ;
if ( ! V_141 -> V_154 && ! F_75 ( V_142 , V_143 ) )
return 0 ;
V_2 = F_76 ( V_216 , V_155 ) ;
if ( V_2 == NULL )
goto V_156;
type |= V_338 << 8 ;
V_111 = F_53 ( V_2 , V_141 -> V_109 , 0 , type , sizeof( * V_113 ) , V_114 ) ;
if ( V_111 == NULL )
goto V_119;
V_113 = F_54 ( V_111 ) ;
V_113 -> V_120 = exp -> V_4 . V_20 . V_21 ;
V_113 -> V_121 = V_122 ;
V_113 -> V_123 = 0 ;
F_8 () ;
if ( F_198 ( V_2 , exp ) < 0 )
goto V_12;
F_11 () ;
F_57 ( V_2 , V_111 ) ;
F_77 ( V_2 , V_142 , V_141 -> V_109 , V_143 , V_141 -> V_154 , V_155 ) ;
return 0 ;
V_12:
F_11 () ;
F_58 ( V_2 , V_111 ) ;
V_119:
F_78 ( V_2 ) ;
V_156:
F_79 ( V_142 , 0 , 0 , - V_163 ) ;
return 0 ;
}
static int F_204 ( struct V_165 * V_166 )
{
if ( V_166 -> args [ 1 ] )
F_192 ( (struct V_311 * ) V_166 -> args [ 1 ] ) ;
return 0 ;
}
static int
F_205 ( struct V_1 * V_2 , struct V_165 * V_166 )
{
struct V_142 * V_142 = F_90 ( V_2 -> V_177 ) ;
struct V_311 * exp , * V_178 ;
struct V_112 * V_113 = F_54 ( V_166 -> V_111 ) ;
V_135 V_18 = V_113 -> V_120 ;
F_8 () ;
V_178 = (struct V_311 * ) V_166 -> args [ 1 ] ;
for (; V_166 -> args [ 0 ] < V_346 ; V_166 -> args [ 0 ] ++ ) {
V_186:
F_206 (exp, &nf_ct_expect_hash[cb->args[0]],
hnode) {
if ( V_18 && exp -> V_4 . V_20 . V_21 != V_18 )
continue;
if ( ! F_97 ( F_74 ( exp -> V_245 ) , V_142 ) )
continue;
if ( V_166 -> args [ 1 ] ) {
if ( exp != V_178 )
continue;
V_166 -> args [ 1 ] = 0 ;
}
if ( F_201 ( V_2 ,
F_98 ( V_166 -> V_2 ) . V_109 ,
V_166 -> V_111 -> V_189 ,
V_344 ,
exp ) < 0 ) {
if ( ! F_132 ( & exp -> V_108 ) )
continue;
V_166 -> args [ 1 ] = ( unsigned long ) exp ;
goto V_45;
}
}
if ( V_166 -> args [ 1 ] ) {
V_166 -> args [ 1 ] = 0 ;
goto V_186;
}
}
V_45:
F_11 () ;
if ( V_178 )
F_192 ( V_178 ) ;
return V_2 -> V_79 ;
}
static int
F_207 ( struct V_1 * V_2 , struct V_165 * V_166 )
{
struct V_311 * exp , * V_178 ;
struct V_112 * V_113 = F_54 ( V_166 -> V_111 ) ;
struct V_28 * V_29 = V_166 -> V_167 ;
struct V_41 * V_42 = F_23 ( V_29 ) ;
V_135 V_18 = V_113 -> V_120 ;
if ( V_166 -> args [ 0 ] )
return 0 ;
F_8 () ;
V_178 = (struct V_311 * ) V_166 -> args [ 1 ] ;
V_186:
F_206 (exp, &help->expectations, lnode) {
if ( V_18 && exp -> V_4 . V_20 . V_21 != V_18 )
continue;
if ( V_166 -> args [ 1 ] ) {
if ( exp != V_178 )
continue;
V_166 -> args [ 1 ] = 0 ;
}
if ( F_201 ( V_2 , F_98 ( V_166 -> V_2 ) . V_109 ,
V_166 -> V_111 -> V_189 ,
V_344 ,
exp ) < 0 ) {
if ( ! F_132 ( & exp -> V_108 ) )
continue;
V_166 -> args [ 1 ] = ( unsigned long ) exp ;
goto V_45;
}
}
if ( V_166 -> args [ 1 ] ) {
V_166 -> args [ 1 ] = 0 ;
goto V_186;
}
V_166 -> args [ 0 ] = 1 ;
V_45:
F_11 () ;
if ( V_178 )
F_192 ( V_178 ) ;
return V_2 -> V_79 ;
}
static int F_208 ( struct V_142 * V_142 , struct V_205 * V_206 ,
struct V_1 * V_2 ,
const struct V_110 * V_111 ,
const struct V_8 * const V_169 [] )
{
int V_144 ;
struct V_112 * V_113 = F_54 ( V_111 ) ;
V_135 V_207 = V_113 -> V_120 ;
struct V_3 V_4 ;
struct V_179 * V_180 ;
struct V_28 * V_29 ;
struct V_23 V_24 ;
struct V_212 V_213 = {
. V_214 = F_207 ,
. V_215 = F_204 ,
} ;
V_144 = F_112 ( V_169 , & V_4 , V_324 ,
V_207 , NULL ) ;
if ( V_144 < 0 )
return V_144 ;
V_144 = F_107 ( V_169 [ V_347 ] , & V_24 ) ;
if ( V_144 < 0 )
return V_144 ;
V_180 = F_121 ( V_142 , & V_24 , & V_4 ) ;
if ( ! V_180 )
return - V_208 ;
V_29 = F_96 ( V_180 ) ;
V_213 . V_167 = V_29 ;
V_144 = F_125 ( V_206 , V_2 , V_111 , & V_213 ) ;
F_81 ( V_29 ) ;
return V_144 ;
}
static int F_209 ( struct V_142 * V_142 , struct V_205 * V_206 ,
struct V_1 * V_2 , const struct V_110 * V_111 ,
const struct V_8 * const V_169 [] )
{
struct V_3 V_4 ;
struct V_311 * exp ;
struct V_1 * V_209 ;
struct V_112 * V_113 = F_54 ( V_111 ) ;
V_135 V_207 = V_113 -> V_120 ;
struct V_23 V_24 ;
int V_144 ;
if ( V_111 -> V_210 & V_211 ) {
if ( V_169 [ V_324 ] )
return F_208 ( V_142 , V_206 , V_2 , V_111 , V_169 ) ;
else {
struct V_212 V_213 = {
. V_214 = F_205 ,
. V_215 = F_204 ,
} ;
return F_125 ( V_206 , V_2 , V_111 , & V_213 ) ;
}
}
V_144 = F_107 ( V_169 [ V_347 ] , & V_24 ) ;
if ( V_144 < 0 )
return V_144 ;
if ( V_169 [ V_308 ] )
V_144 = F_112 ( V_169 , & V_4 , V_308 ,
V_207 , NULL ) ;
else if ( V_169 [ V_324 ] )
V_144 = F_112 ( V_169 , & V_4 , V_324 ,
V_207 , NULL ) ;
else
return - V_197 ;
if ( V_144 < 0 )
return V_144 ;
exp = F_210 ( V_142 , & V_24 , & V_4 ) ;
if ( ! exp )
return - V_208 ;
if ( V_169 [ V_332 ] ) {
T_7 V_26 = F_87 ( V_169 [ V_332 ] ) ;
if ( F_86 ( V_26 ) != ( T_2 ) ( unsigned long ) exp ) {
F_192 ( exp ) ;
return - V_208 ;
}
}
V_144 = - V_172 ;
V_209 = F_76 ( V_216 , V_171 ) ;
if ( V_209 == NULL ) {
F_192 ( exp ) ;
goto V_45;
}
F_8 () ;
V_144 = F_201 ( V_209 , F_98 ( V_2 ) . V_109 ,
V_111 -> V_189 , V_344 , exp ) ;
F_11 () ;
F_192 ( exp ) ;
if ( V_144 <= 0 )
goto free;
V_144 = F_126 ( V_206 , V_209 , F_98 ( V_2 ) . V_109 , V_217 ) ;
if ( V_144 < 0 )
goto V_45;
return 0 ;
free:
F_78 ( V_209 ) ;
V_45:
return V_144 == - V_164 ? - V_163 : V_144 ;
}
static int F_211 ( struct V_142 * V_142 , struct V_205 * V_206 ,
struct V_1 * V_2 , const struct V_110 * V_111 ,
const struct V_8 * const V_169 [] )
{
struct V_311 * exp ;
struct V_3 V_4 ;
struct V_112 * V_113 = F_54 ( V_111 ) ;
struct V_348 * V_349 ;
V_135 V_207 = V_113 -> V_120 ;
struct V_23 V_24 ;
unsigned int V_87 ;
int V_144 ;
if ( V_169 [ V_308 ] ) {
V_144 = F_107 ( V_169 [ V_347 ] , & V_24 ) ;
if ( V_144 < 0 )
return V_144 ;
V_144 = F_112 ( V_169 , & V_4 , V_308 ,
V_207 , NULL ) ;
if ( V_144 < 0 )
return V_144 ;
exp = F_210 ( V_142 , & V_24 , & V_4 ) ;
if ( ! exp )
return - V_208 ;
if ( V_169 [ V_332 ] ) {
T_7 V_26 = F_87 ( V_169 [ V_332 ] ) ;
if ( F_86 ( V_26 ) != ( T_2 ) ( unsigned long ) exp ) {
F_192 ( exp ) ;
return - V_208 ;
}
}
F_131 ( & V_246 ) ;
if ( F_122 ( & exp -> V_32 ) ) {
F_212 ( exp , F_98 ( V_2 ) . V_109 ,
F_120 ( V_111 ) ) ;
F_192 ( exp ) ;
}
F_133 ( & V_246 ) ;
F_192 ( exp ) ;
} else if ( V_169 [ V_313 ] ) {
char * V_48 = F_114 ( V_169 [ V_313 ] ) ;
struct V_41 * V_350 ;
F_131 ( & V_246 ) ;
for ( V_87 = 0 ; V_87 < V_346 ; V_87 ++ ) {
F_213 (exp, next,
&nf_ct_expect_hash[i],
hnode) {
if ( ! F_97 ( F_203 ( exp ) , V_142 ) )
continue;
V_350 = F_23 ( exp -> V_245 ) ;
if ( ! strcmp ( V_350 -> V_44 -> V_48 , V_48 ) &&
F_122 ( & exp -> V_32 ) ) {
F_212 ( exp ,
F_98 ( V_2 ) . V_109 ,
F_120 ( V_111 ) ) ;
F_192 ( exp ) ;
}
}
}
F_133 ( & V_246 ) ;
} else {
F_131 ( & V_246 ) ;
for ( V_87 = 0 ; V_87 < V_346 ; V_87 ++ ) {
F_213 (exp, next,
&nf_ct_expect_hash[i],
hnode) {
if ( ! F_97 ( F_203 ( exp ) , V_142 ) )
continue;
if ( F_122 ( & exp -> V_32 ) ) {
F_212 ( exp ,
F_98 ( V_2 ) . V_109 ,
F_120 ( V_111 ) ) ;
F_192 ( exp ) ;
}
}
}
F_133 ( & V_246 ) ;
}
return 0 ;
}
static int
F_214 ( struct V_311 * V_351 ,
const struct V_8 * const V_169 [] )
{
if ( V_169 [ V_331 ] ) {
if ( ! F_122 ( & V_351 -> V_32 ) )
return - V_248 ;
V_351 -> V_32 . V_33 = V_34 +
F_86 ( F_87 ( V_169 [ V_331 ] ) ) * V_35 ;
F_151 ( & V_351 -> V_32 ) ;
}
return 0 ;
}
static int
F_215 ( const struct V_8 * V_53 ,
struct V_311 * exp ,
V_135 V_207 )
{
#ifdef F_69
struct V_8 * V_191 [ V_352 + 1 ] ;
struct V_3 V_320 = {} ;
int V_144 ;
V_144 = F_103 ( V_191 , V_352 , V_53 , V_353 ) ;
if ( V_144 < 0 )
return V_144 ;
if ( ! V_191 [ V_329 ] || ! V_191 [ V_330 ] )
return - V_197 ;
V_144 = F_112 ( ( const struct V_8 * const * ) V_191 ,
& V_320 , V_330 ,
V_207 , NULL ) ;
if ( V_144 < 0 )
return V_144 ;
exp -> V_325 = V_320 . V_20 . V_207 ;
exp -> V_327 = V_320 . V_20 . V_318 ;
exp -> V_25 = F_86 ( F_87 ( V_191 [ V_329 ] ) ) ;
return 0 ;
#else
return - V_176 ;
#endif
}
static struct V_311 *
F_190 ( const struct V_8 * const V_169 [] , struct V_28 * V_29 ,
struct V_43 * V_44 ,
struct V_3 * V_4 ,
struct V_3 * V_174 )
{
V_136 V_335 = 0 ;
struct V_311 * exp ;
struct V_41 * V_42 ;
int V_144 ;
if ( V_169 [ V_334 ] && V_44 ) {
V_335 = F_86 ( F_87 ( V_169 [ V_334 ] ) ) ;
if ( V_335 > V_44 -> V_354 )
return F_85 ( - V_197 ) ;
}
exp = F_216 ( V_29 ) ;
if ( ! exp )
return F_85 ( - V_172 ) ;
V_42 = F_23 ( V_29 ) ;
if ( ! V_42 ) {
if ( ! V_169 [ V_331 ] ) {
V_144 = - V_197 ;
goto V_355;
}
exp -> V_32 . V_33 =
V_34 + F_86 ( F_87 ( V_169 [ V_331 ] ) ) * V_35 ;
exp -> V_114 = V_356 ;
if ( V_169 [ V_333 ] ) {
exp -> V_114 |=
F_86 ( F_87 ( V_169 [ V_333 ] ) ) ;
}
} else {
if ( V_169 [ V_333 ] ) {
exp -> V_114 = F_86 ( F_87 ( V_169 [ V_333 ] ) ) ;
exp -> V_114 &= ~ V_356 ;
} else
exp -> V_114 = 0 ;
}
if ( V_169 [ V_337 ] ) {
const char * V_48 = F_114 ( V_169 [ V_337 ] ) ;
struct V_321 * V_322 ;
V_322 = F_217 ( V_48 ) ;
if ( V_322 == NULL ) {
V_144 = - V_197 ;
goto V_355;
}
exp -> V_336 = V_322 -> V_336 ;
} else
exp -> V_336 = NULL ;
exp -> V_335 = V_335 ;
exp -> V_245 = V_29 ;
exp -> V_44 = V_44 ;
exp -> V_4 = * V_4 ;
exp -> V_174 . V_20 . V_207 = V_174 -> V_20 . V_207 ;
exp -> V_174 . V_20 . V_318 . V_319 = V_174 -> V_20 . V_318 . V_319 ;
if ( V_169 [ V_328 ] ) {
V_144 = F_215 ( V_169 [ V_328 ] ,
exp , F_20 ( V_29 ) ) ;
if ( V_144 < 0 )
goto V_355;
}
return exp ;
V_355:
F_192 ( exp ) ;
return F_85 ( V_144 ) ;
}
static int
F_218 ( struct V_142 * V_142 ,
const struct V_23 * V_24 ,
const struct V_8 * const V_169 [] ,
V_135 V_207 , T_2 V_109 , int V_154 )
{
struct V_3 V_4 , V_174 , F_45 ;
struct V_179 * V_180 = NULL ;
struct V_43 * V_44 = NULL ;
struct V_311 * exp ;
struct V_28 * V_29 ;
int V_144 ;
V_144 = F_112 ( V_169 , & V_4 , V_308 ,
V_207 , NULL ) ;
if ( V_144 < 0 )
return V_144 ;
V_144 = F_112 ( V_169 , & V_174 , V_309 ,
V_207 , NULL ) ;
if ( V_144 < 0 )
return V_144 ;
V_144 = F_112 ( V_169 , & F_45 , V_324 ,
V_207 , NULL ) ;
if ( V_144 < 0 )
return V_144 ;
V_180 = F_121 ( V_142 , V_24 , & F_45 ) ;
if ( ! V_180 )
return - V_208 ;
V_29 = F_96 ( V_180 ) ;
if ( V_169 [ V_313 ] ) {
const char * V_244 = F_114 ( V_169 [ V_313 ] ) ;
V_44 = F_149 ( V_244 , V_207 ,
F_21 ( V_29 ) ) ;
if ( V_44 == NULL ) {
#ifdef F_140
if ( F_142 ( L_4 , V_244 ) < 0 ) {
V_144 = - V_176 ;
goto V_357;
}
V_44 = F_149 ( V_244 , V_207 ,
F_21 ( V_29 ) ) ;
if ( V_44 ) {
V_144 = - V_164 ;
goto V_357;
}
#endif
V_144 = - V_176 ;
goto V_357;
}
}
exp = F_190 ( V_169 , V_29 , V_44 , & V_4 , & V_174 ) ;
if ( F_116 ( exp ) ) {
V_144 = F_117 ( exp ) ;
goto V_357;
}
V_144 = F_191 ( exp , V_109 , V_154 ) ;
F_192 ( exp ) ;
V_357:
F_81 ( V_29 ) ;
return V_144 ;
}
static int F_219 ( struct V_142 * V_142 , struct V_205 * V_206 ,
struct V_1 * V_2 , const struct V_110 * V_111 ,
const struct V_8 * const V_169 [] )
{
struct V_3 V_4 ;
struct V_311 * exp ;
struct V_112 * V_113 = F_54 ( V_111 ) ;
V_135 V_207 = V_113 -> V_120 ;
struct V_23 V_24 ;
int V_144 ;
if ( ! V_169 [ V_308 ]
|| ! V_169 [ V_309 ]
|| ! V_169 [ V_324 ] )
return - V_197 ;
V_144 = F_107 ( V_169 [ V_347 ] , & V_24 ) ;
if ( V_144 < 0 )
return V_144 ;
V_144 = F_112 ( V_169 , & V_4 , V_308 ,
V_207 , NULL ) ;
if ( V_144 < 0 )
return V_144 ;
F_131 ( & V_246 ) ;
exp = F_220 ( V_142 , & V_24 , & V_4 ) ;
if ( ! exp ) {
F_133 ( & V_246 ) ;
V_144 = - V_208 ;
if ( V_111 -> V_210 & V_150 ) {
V_144 = F_218 ( V_142 , & V_24 , V_169 , V_207 ,
F_98 ( V_2 ) . V_109 ,
F_120 ( V_111 ) ) ;
}
return V_144 ;
}
V_144 = - V_265 ;
if ( ! ( V_111 -> V_210 & V_151 ) )
V_144 = F_214 ( exp , V_169 ) ;
F_133 ( & V_246 ) ;
return V_144 ;
}
static int
F_221 ( struct V_1 * V_2 , T_2 V_109 , T_2 V_93 , int V_219 ,
const struct V_266 * V_267 )
{
struct V_110 * V_111 ;
struct V_112 * V_113 ;
unsigned int V_114 = V_109 ? V_115 : 0 , V_116 ;
V_116 = ( V_117 << 8 | V_358 ) ;
V_111 = F_53 ( V_2 , V_109 , V_93 , V_116 , sizeof( * V_113 ) , V_114 ) ;
if ( V_111 == NULL )
goto V_119;
V_113 = F_54 ( V_111 ) ;
V_113 -> V_120 = V_269 ;
V_113 -> V_121 = V_122 ;
V_113 -> V_123 = F_14 ( V_219 ) ;
if ( F_16 ( V_2 , V_359 , F_17 ( V_267 -> V_360 ) ) ||
F_16 ( V_2 , V_361 , F_17 ( V_267 -> V_362 ) ) ||
F_16 ( V_2 , V_363 , F_17 ( V_267 -> V_364 ) ) )
goto V_12;
F_57 ( V_2 , V_111 ) ;
return V_2 -> V_79 ;
V_12:
V_119:
F_58 ( V_2 , V_111 ) ;
return - 1 ;
}
static int
F_222 ( struct V_1 * V_2 , struct V_165 * V_166 )
{
int V_219 ;
struct V_142 * V_142 = F_90 ( V_2 -> V_177 ) ;
if ( V_166 -> args [ 0 ] == V_222 )
return 0 ;
for ( V_219 = V_166 -> args [ 0 ] ; V_219 < V_222 ; V_219 ++ ) {
const struct V_266 * V_267 ;
if ( ! F_129 ( V_219 ) )
continue;
V_267 = F_130 ( V_142 -> V_29 . V_295 , V_219 ) ;
if ( F_221 ( V_2 , F_98 ( V_166 -> V_2 ) . V_109 ,
V_166 -> V_111 -> V_189 ,
V_219 , V_267 ) < 0 )
break;
}
V_166 -> args [ 0 ] = V_219 ;
return V_2 -> V_79 ;
}
static int F_223 ( struct V_142 * V_142 , struct V_205 * V_206 ,
struct V_1 * V_2 ,
const struct V_110 * V_111 ,
const struct V_8 * const V_169 [] )
{
if ( V_111 -> V_210 & V_211 ) {
struct V_212 V_213 = {
. V_214 = F_222 ,
} ;
return F_125 ( V_206 , V_2 , V_111 , & V_213 ) ;
}
return 0 ;
}
static int T_8 F_224 ( struct V_142 * V_142 )
{
#ifdef F_225
int V_7 ;
V_7 = F_226 ( V_142 , & V_365 ) ;
if ( V_7 < 0 ) {
F_227 ( L_5 ) ;
goto V_355;
}
V_7 = F_228 ( V_142 , & V_366 ) ;
if ( V_7 < 0 ) {
F_227 ( L_6 ) ;
goto V_367;
}
#endif
return 0 ;
#ifdef F_225
V_367:
F_229 ( V_142 , & V_365 ) ;
V_355:
return V_7 ;
#endif
}
static void F_230 ( struct V_142 * V_142 )
{
#ifdef F_225
F_231 ( V_142 , & V_366 ) ;
F_229 ( V_142 , & V_365 ) ;
#endif
}
static void T_9 F_232 ( struct V_368 * V_369 )
{
struct V_142 * V_142 ;
F_233 (net, net_exit_list, exit_list)
F_230 ( V_142 ) ;
}
static int T_10 F_234 ( void )
{
int V_7 ;
F_235 ( L_7 , V_121 ) ;
V_7 = F_236 ( & V_370 ) ;
if ( V_7 < 0 ) {
F_227 ( L_8 ) ;
goto V_355;
}
V_7 = F_236 ( & V_371 ) ;
if ( V_7 < 0 ) {
F_227 ( L_9 ) ;
goto V_372;
}
V_7 = F_237 ( & V_373 ) ;
if ( V_7 < 0 ) {
F_227 ( L_10 ) ;
goto V_374;
}
#ifdef F_238
F_148 ( V_375 , & V_376 ) ;
#endif
return 0 ;
V_374:
F_239 ( & V_371 ) ;
V_372:
F_239 ( & V_370 ) ;
V_355:
return V_7 ;
}
static void T_11 F_240 ( void )
{
F_235 ( L_11 ) ;
F_241 ( & V_373 ) ;
F_239 ( & V_371 ) ;
F_239 ( & V_370 ) ;
#ifdef F_238
F_148 ( V_375 , NULL ) ;
#endif
}
