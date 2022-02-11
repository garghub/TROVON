static int F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 ,
const struct V_5 * V_6 )
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
const struct V_17 * V_18 )
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
const struct V_17 * V_18 ;
const struct V_5 * V_6 ;
int V_7 ;
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
long V_32 = F_19 ( V_29 ) / V_33 ;
if ( F_16 ( V_2 , V_34 , F_17 ( V_32 ) ) )
goto V_12;
return 0 ;
V_12:
return - 1 ;
}
static int F_20 ( struct V_1 * V_2 , struct V_28 * V_29 )
{
const struct V_5 * V_6 ;
struct V_8 * V_35 ;
int V_7 ;
V_6 = F_10 ( F_21 ( V_29 ) , F_22 ( V_29 ) ) ;
if ( ! V_6 -> V_36 )
return 0 ;
V_35 = F_2 ( V_2 , V_37 | V_11 ) ;
if ( ! V_35 )
goto V_12;
V_7 = V_6 -> V_36 ( V_2 , V_35 , V_29 ) ;
F_5 ( V_2 , V_35 ) ;
return V_7 ;
V_12:
return - 1 ;
}
static int F_23 ( struct V_1 * V_2 ,
const struct V_28 * V_29 )
{
struct V_8 * V_38 ;
const struct V_39 * V_40 = F_24 ( V_29 ) ;
struct V_41 * V_42 ;
if ( ! V_40 )
return 0 ;
V_42 = F_25 ( V_40 -> V_42 ) ;
if ( ! V_42 )
goto V_43;
V_38 = F_2 ( V_2 , V_44 | V_11 ) ;
if ( ! V_38 )
goto V_12;
if ( F_26 ( V_2 , V_45 , V_42 -> V_46 ) )
goto V_12;
if ( V_42 -> V_36 )
V_42 -> V_36 ( V_2 , V_29 ) ;
F_5 ( V_2 , V_38 ) ;
V_43:
return 0 ;
V_12:
return - 1 ;
}
static int
F_27 ( struct V_1 * V_2 , struct V_47 * V_48 ,
enum V_49 V_25 , int type )
{
enum V_50 V_51 = V_25 ? V_52 : V_53 ;
struct V_54 * V_55 = V_48 -> V_55 ;
struct V_8 * V_56 ;
T_1 V_57 , V_58 ;
if ( type == V_59 ) {
V_57 = F_28 ( & V_55 [ V_25 ] . V_60 , 0 ) ;
V_58 = F_28 ( & V_55 [ V_25 ] . V_58 , 0 ) ;
} else {
V_57 = F_29 ( & V_55 [ V_25 ] . V_60 ) ;
V_58 = F_29 ( & V_55 [ V_25 ] . V_58 ) ;
}
V_56 = F_2 ( V_2 , V_51 | V_11 ) ;
if ( ! V_56 )
goto V_12;
if ( F_30 ( V_2 , V_61 , F_31 ( V_57 ) ,
V_62 ) ||
F_30 ( V_2 , V_63 , F_31 ( V_58 ) ,
V_62 ) )
goto V_12;
F_5 ( V_2 , V_56 ) ;
return 0 ;
V_12:
return - 1 ;
}
static int
F_32 ( struct V_1 * V_2 , const struct V_28 * V_29 , int type )
{
struct V_47 * V_48 = F_33 ( V_29 ) ;
if ( ! V_48 )
return 0 ;
if ( F_27 ( V_2 , V_48 , V_64 , type ) < 0 )
return - 1 ;
if ( F_27 ( V_2 , V_48 , V_65 , type ) < 0 )
return - 1 ;
return 0 ;
}
static int
F_34 ( struct V_1 * V_2 , const struct V_28 * V_29 )
{
struct V_8 * V_56 ;
const struct V_66 * V_67 ;
V_67 = F_35 ( V_29 ) ;
if ( ! V_67 )
return 0 ;
V_56 = F_2 ( V_2 , V_68 | V_11 ) ;
if ( ! V_56 )
goto V_12;
if ( F_30 ( V_2 , V_69 , F_31 ( V_67 -> V_70 ) ,
V_71 ) ||
( V_67 -> V_72 != 0 && F_30 ( V_2 , V_73 ,
F_31 ( V_67 -> V_72 ) ,
V_71 ) ) )
goto V_12;
F_5 ( V_2 , V_56 ) ;
return 0 ;
V_12:
return - 1 ;
}
static int F_36 ( struct V_1 * V_2 , const struct V_28 * V_29 )
{
if ( F_16 ( V_2 , V_74 , F_17 ( V_29 -> V_75 ) ) )
goto V_12;
return 0 ;
V_12:
return - 1 ;
}
static int F_37 ( struct V_1 * V_2 , const struct V_28 * V_29 )
{
struct V_8 * V_76 ;
int V_77 , V_7 ;
char * V_78 ;
V_7 = F_38 ( V_29 -> V_79 , & V_78 , & V_77 ) ;
if ( V_7 )
return 0 ;
V_7 = - 1 ;
V_76 = F_2 ( V_2 , V_80 | V_11 ) ;
if ( ! V_76 )
goto V_12;
if ( F_26 ( V_2 , V_81 , V_78 ) )
goto V_12;
F_5 ( V_2 , V_76 ) ;
V_7 = 0 ;
V_12:
F_39 ( V_78 , V_77 ) ;
return V_7 ;
}
static inline int F_40 ( const struct V_28 * V_29 )
{
struct V_82 * V_83 = F_41 ( V_29 ) ;
if ( ! V_83 )
return 0 ;
return F_42 ( sizeof( V_83 -> V_84 ) ) ;
}
static int
F_43 ( struct V_1 * V_2 , const struct V_28 * V_29 )
{
struct V_82 * V_83 = F_41 ( V_29 ) ;
unsigned int V_85 ;
if ( ! V_83 )
return 0 ;
V_85 = 0 ;
do {
if ( V_83 -> V_84 [ V_85 ] != 0 )
return F_44 ( V_2 , V_86 , sizeof( V_83 -> V_84 ) ,
V_83 -> V_84 ) ;
V_85 ++ ;
} while ( V_85 < F_45 ( V_83 -> V_84 ) );
return 0 ;
}
static int F_46 ( struct V_1 * V_2 , const struct V_28 * V_29 )
{
struct V_8 * V_9 ;
if ( ! ( V_29 -> V_31 & V_87 ) )
return 0 ;
V_9 = F_2 ( V_2 , V_88 | V_11 ) ;
if ( ! V_9 )
goto V_12;
if ( F_7 ( V_2 , F_47 ( V_29 ) ) < 0 )
goto V_12;
F_5 ( V_2 , V_9 ) ;
return 0 ;
V_12:
return - 1 ;
}
static int
F_48 ( struct V_1 * V_2 , const struct V_89 * V_90 , int type )
{
struct V_8 * V_9 ;
V_9 = F_2 ( V_2 , type | V_11 ) ;
if ( ! V_9 )
goto V_12;
if ( F_16 ( V_2 , V_91 ,
F_17 ( V_90 -> V_92 ) ) ||
F_16 ( V_2 , V_93 ,
F_17 ( V_90 -> V_94 ) ) ||
F_16 ( V_2 , V_95 ,
F_17 ( V_90 -> V_96 ) ) )
goto V_12;
F_5 ( V_2 , V_9 ) ;
return 0 ;
V_12:
return - 1 ;
}
static int F_49 ( struct V_1 * V_2 , struct V_28 * V_29 )
{
struct V_97 * V_98 = F_50 ( V_29 ) ;
struct V_89 * V_90 ;
if ( ! ( V_29 -> V_31 & V_99 ) || ! V_98 )
return 0 ;
F_51 ( & V_29 -> V_100 ) ;
V_90 = & V_98 -> V_90 [ V_64 ] ;
if ( F_48 ( V_2 , V_90 , V_101 ) == - 1 )
goto V_102;
V_90 = & V_98 -> V_90 [ V_65 ] ;
if ( F_48 ( V_2 , V_90 , V_103 ) == - 1 )
goto V_102;
F_52 ( & V_29 -> V_100 ) ;
return 0 ;
V_102:
F_52 ( & V_29 -> V_100 ) ;
return - 1 ;
}
static int F_53 ( struct V_1 * V_2 , const struct V_28 * V_29 )
{
if ( F_16 ( V_2 , V_104 , F_17 ( ( unsigned long ) V_29 ) ) )
goto V_12;
return 0 ;
V_12:
return - 1 ;
}
static int F_54 ( struct V_1 * V_2 , const struct V_28 * V_29 )
{
if ( F_16 ( V_2 , V_105 , F_17 ( F_55 ( & V_29 -> V_106 . V_107 ) ) ) )
goto V_12;
return 0 ;
V_12:
return - 1 ;
}
static int
F_56 ( struct V_1 * V_2 , T_2 V_108 , T_2 V_90 , T_2 type ,
struct V_28 * V_29 )
{
const struct V_23 * V_24 ;
struct V_109 * V_110 ;
struct V_111 * V_112 ;
struct V_8 * V_9 ;
unsigned int V_113 = V_108 ? V_114 : 0 , V_115 ;
V_115 = F_57 ( V_116 , V_117 ) ;
V_110 = F_58 ( V_2 , V_108 , V_90 , V_115 , sizeof( * V_112 ) , V_113 ) ;
if ( V_110 == NULL )
goto V_118;
V_112 = F_59 ( V_110 ) ;
V_112 -> V_119 = F_21 ( V_29 ) ;
V_112 -> V_120 = V_121 ;
V_112 -> V_122 = 0 ;
V_24 = F_60 ( V_29 ) ;
V_9 = F_2 ( V_2 , V_123 | V_11 ) ;
if ( ! V_9 )
goto V_12;
if ( F_7 ( V_2 , F_61 ( V_29 , V_64 ) ) < 0 )
goto V_12;
if ( F_12 ( V_2 , V_124 , V_24 ,
V_125 ) < 0 )
goto V_12;
F_5 ( V_2 , V_9 ) ;
V_9 = F_2 ( V_2 , V_126 | V_11 ) ;
if ( ! V_9 )
goto V_12;
if ( F_7 ( V_2 , F_61 ( V_29 , V_65 ) ) < 0 )
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
F_32 ( V_2 , V_29 , type ) < 0 ||
F_34 ( V_2 , V_29 ) < 0 ||
F_20 ( V_2 , V_29 ) < 0 ||
F_23 ( V_2 , V_29 ) < 0 ||
F_36 ( V_2 , V_29 ) < 0 ||
F_37 ( V_2 , V_29 ) < 0 ||
F_43 ( V_2 , V_29 ) < 0 ||
F_53 ( V_2 , V_29 ) < 0 ||
F_54 ( V_2 , V_29 ) < 0 ||
F_46 ( V_2 , V_29 ) < 0 ||
F_49 ( V_2 , V_29 ) < 0 )
goto V_12;
F_62 ( V_2 , V_110 ) ;
return V_2 -> V_77 ;
V_118:
V_12:
F_63 ( V_2 , V_110 ) ;
return - 1 ;
}
static inline T_3 F_64 ( const struct V_28 * V_29 )
{
const struct V_17 * V_18 ;
const struct V_5 * V_6 ;
T_3 V_77 ;
V_18 = F_9 ( F_21 ( V_29 ) ) ;
V_77 = V_18 -> V_130 ;
V_77 *= 3u ;
V_6 = F_10 ( F_21 ( V_29 ) , F_22 ( V_29 ) ) ;
V_77 += V_6 -> V_130 ;
return V_77 ;
}
static inline T_3 F_65 ( const struct V_28 * V_29 )
{
if ( ! F_66 ( V_29 , V_131 ) )
return 0 ;
return 2 * F_42 ( 0 )
+ 2 * F_67 ( sizeof( V_132 ) )
+ 2 * F_67 ( sizeof( V_132 ) )
;
}
static inline int F_68 ( const struct V_28 * V_29 )
{
#ifdef F_69
int V_77 , V_7 ;
V_7 = F_38 ( V_29 -> V_79 , NULL , & V_77 ) ;
if ( V_7 )
return 0 ;
return F_42 ( 0 )
+ F_42 ( sizeof( char ) * V_77 ) ;
#else
return 0 ;
#endif
}
static inline T_3 F_70 ( const struct V_28 * V_29 )
{
#ifdef F_71
if ( ! F_66 ( V_29 , V_133 ) )
return 0 ;
return F_42 ( 0 ) + 2 * F_67 ( sizeof( V_132 ) ) ;
#else
return 0 ;
#endif
}
static T_3 F_72 ( const struct V_28 * V_29 )
{
return F_73 ( sizeof( struct V_111 ) )
+ 3 * F_42 ( 0 )
+ 3 * F_42 ( 0 )
+ 3 * F_42 ( 0 )
+ 3 * F_42 ( sizeof( V_134 ) )
+ F_42 ( sizeof( V_135 ) )
+ F_42 ( sizeof( V_135 ) )
+ F_65 ( V_29 )
+ F_70 ( V_29 )
+ F_42 ( sizeof( V_135 ) )
+ F_42 ( 0 )
+ F_42 ( 0 )
+ F_42 ( V_136 )
+ F_68 ( V_29 )
#ifdef F_74
+ 2 * F_42 ( 0 )
+ 6 * F_42 ( sizeof( V_135 ) )
#endif
#ifdef F_75
+ F_42 ( sizeof( V_135 ) )
#endif
#ifdef F_76
+ F_42 ( sizeof( V_137 ) )
#endif
+ F_64 ( V_29 )
+ F_40 ( V_29 )
;
}
static int
F_77 ( unsigned int V_138 , struct V_139 * V_140 )
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
int V_102 ;
if ( V_138 & ( 1 << V_143 ) ) {
type = V_144 ;
V_142 = V_145 ;
} else if ( V_138 & ( ( 1 << V_146 ) | ( 1 << V_147 ) ) ) {
type = V_117 ;
V_113 = V_148 | V_149 ;
V_142 = V_150 ;
} else if ( V_138 ) {
type = V_117 ;
V_142 = V_151 ;
} else
return 0 ;
V_141 = F_78 ( V_29 ) ;
if ( ! V_140 -> V_152 && ! F_79 ( V_141 , V_142 ) )
return 0 ;
V_2 = F_80 ( F_72 ( V_29 ) , V_153 ) ;
if ( V_2 == NULL )
goto V_154;
type = F_57 ( V_116 , type ) ;
V_110 = F_58 ( V_2 , V_140 -> V_108 , 0 , type , sizeof( * V_112 ) , V_113 ) ;
if ( V_110 == NULL )
goto V_118;
V_112 = F_59 ( V_110 ) ;
V_112 -> V_119 = F_21 ( V_29 ) ;
V_112 -> V_120 = V_121 ;
V_112 -> V_122 = 0 ;
V_24 = F_60 ( V_29 ) ;
V_9 = F_2 ( V_2 , V_123 | V_11 ) ;
if ( ! V_9 )
goto V_12;
if ( F_7 ( V_2 , F_61 ( V_29 , V_64 ) ) < 0 )
goto V_12;
if ( F_12 ( V_2 , V_124 , V_24 ,
V_125 ) < 0 )
goto V_12;
F_5 ( V_2 , V_9 ) ;
V_9 = F_2 ( V_2 , V_126 | V_11 ) ;
if ( ! V_9 )
goto V_12;
if ( F_7 ( V_2 , F_61 ( V_29 , V_65 ) ) < 0 )
goto V_12;
if ( F_12 ( V_2 , V_124 , V_24 ,
V_127 ) < 0 )
goto V_12;
F_5 ( V_2 , V_9 ) ;
if ( F_12 ( V_2 , V_128 , V_24 ,
V_129 ) < 0 )
goto V_12;
if ( F_53 ( V_2 , V_29 ) < 0 )
goto V_12;
if ( F_15 ( V_2 , V_29 ) < 0 )
goto V_12;
if ( V_138 & ( 1 << V_143 ) ) {
if ( F_32 ( V_2 , V_29 , type ) < 0 ||
F_34 ( V_2 , V_29 ) < 0 )
goto V_12;
} else {
if ( F_18 ( V_2 , V_29 ) < 0 )
goto V_12;
if ( V_138 & ( 1 << V_155 )
&& F_20 ( V_2 , V_29 ) < 0 )
goto V_12;
if ( ( V_138 & ( 1 << V_156 ) || F_24 ( V_29 ) )
&& F_23 ( V_2 , V_29 ) < 0 )
goto V_12;
#ifdef F_69
if ( ( V_138 & ( 1 << V_157 ) || V_29 -> V_79 )
&& F_37 ( V_2 , V_29 ) < 0 )
goto V_12;
#endif
if ( V_138 & ( 1 << V_158 ) &&
F_43 ( V_2 , V_29 ) < 0 )
goto V_12;
if ( V_138 & ( 1 << V_147 ) &&
F_46 ( V_2 , V_29 ) < 0 )
goto V_12;
if ( V_138 & ( 1 << V_159 ) &&
F_49 ( V_2 , V_29 ) < 0 )
goto V_12;
}
#ifdef F_75
if ( ( V_138 & ( 1 << V_160 ) || V_29 -> V_75 )
&& F_36 ( V_2 , V_29 ) < 0 )
goto V_12;
#endif
F_62 ( V_2 , V_110 ) ;
V_102 = F_81 ( V_2 , V_141 , V_140 -> V_108 , V_142 , V_140 -> V_152 ,
V_153 ) ;
if ( V_102 == - V_161 || V_102 == - V_162 )
return - V_161 ;
return 0 ;
V_12:
F_63 ( V_2 , V_110 ) ;
V_118:
F_82 ( V_2 ) ;
V_154:
if ( F_83 ( V_141 , 0 , V_142 , - V_161 ) > 0 )
return - V_161 ;
return 0 ;
}
static int F_84 ( struct V_163 * V_164 )
{
if ( V_164 -> args [ 1 ] )
F_85 ( (struct V_28 * ) V_164 -> args [ 1 ] ) ;
F_86 ( V_164 -> V_165 ) ;
return 0 ;
}
static struct V_166 *
F_87 ( const struct V_8 * const V_167 [] )
{
#ifdef F_75
struct V_166 * V_168 ;
V_168 = F_88 ( sizeof( * V_168 ) , V_169 ) ;
if ( V_168 == NULL )
return F_89 ( - V_170 ) ;
V_168 -> V_75 . V_171 = F_90 ( F_91 ( V_167 [ V_74 ] ) ) ;
V_168 -> V_75 . V_172 = F_90 ( F_91 ( V_167 [ V_173 ] ) ) ;
return V_168 ;
#else
return F_89 ( - V_174 ) ;
#endif
}
static int F_92 ( struct V_28 * V_29 , void * V_165 )
{
struct V_166 * V_168 = V_165 ;
if ( V_168 == NULL )
return 1 ;
#ifdef F_75
if ( ( V_29 -> V_75 & V_168 -> V_75 . V_172 ) == V_168 -> V_75 . V_171 )
return 1 ;
#endif
return 0 ;
}
static int
F_93 ( struct V_1 * V_2 , struct V_163 * V_164 )
{
struct V_141 * V_141 = F_94 ( V_2 -> V_175 ) ;
struct V_28 * V_29 , * V_176 ;
struct V_177 * V_178 ;
struct V_179 * V_180 ;
struct V_111 * V_112 = F_59 ( V_164 -> V_110 ) ;
V_134 V_18 = V_112 -> V_119 ;
struct V_28 * V_181 [ 8 ] ;
int V_182 , V_85 ;
T_4 * V_183 ;
V_176 = (struct V_28 * ) V_164 -> args [ 1 ] ;
V_85 = 0 ;
F_95 () ;
for (; V_164 -> args [ 0 ] < V_184 ; V_164 -> args [ 0 ] ++ ) {
V_185:
while ( V_85 ) {
V_85 -- ;
if ( F_96 ( V_181 [ V_85 ] ) )
F_97 ( V_181 [ V_85 ] ) ;
F_85 ( V_181 [ V_85 ] ) ;
}
V_183 = & V_186 [ V_164 -> args [ 0 ] % V_187 ] ;
F_98 ( V_183 ) ;
if ( V_164 -> args [ 0 ] >= V_184 ) {
F_99 ( V_183 ) ;
goto V_43;
}
F_100 (h, n, &nf_conntrack_hash[cb->args[0]],
hnnode) {
if ( F_101 ( V_178 ) != V_64 )
continue;
V_29 = F_102 ( V_178 ) ;
if ( F_103 ( V_29 ) ) {
if ( V_85 < F_45 ( V_181 ) &&
F_104 ( & V_29 -> V_106 . V_107 ) )
V_181 [ V_85 ++ ] = V_29 ;
continue;
}
if ( ! F_105 ( V_141 , F_78 ( V_29 ) ) )
continue;
if ( V_18 && F_21 ( V_29 ) != V_18 )
continue;
if ( V_164 -> args [ 1 ] ) {
if ( V_29 != V_176 )
continue;
V_164 -> args [ 1 ] = 0 ;
}
if ( ! F_92 ( V_29 , V_164 -> V_165 ) )
continue;
F_8 () ;
V_182 =
F_56 ( V_2 , F_106 ( V_164 -> V_2 ) . V_108 ,
V_164 -> V_110 -> V_188 ,
F_107 ( V_164 -> V_110 -> V_189 ) ,
V_29 ) ;
F_11 () ;
if ( V_182 < 0 ) {
F_108 ( & V_29 -> V_106 ) ;
V_164 -> args [ 1 ] = ( unsigned long ) V_29 ;
F_99 ( V_183 ) ;
goto V_43;
}
}
F_99 ( V_183 ) ;
if ( V_164 -> args [ 1 ] ) {
V_164 -> args [ 1 ] = 0 ;
goto V_185;
}
}
V_43:
F_109 () ;
if ( V_176 ) {
if ( (struct V_28 * ) V_164 -> args [ 1 ] == V_176 )
V_164 -> args [ 1 ] = 0 ;
F_85 ( V_176 ) ;
}
while ( V_85 ) {
V_85 -- ;
if ( F_96 ( V_181 [ V_85 ] ) )
F_97 ( V_181 [ V_85 ] ) ;
F_85 ( V_181 [ V_85 ] ) ;
}
return V_2 -> V_77 ;
}
static int F_110 ( struct V_8 * V_51 ,
struct V_3 * V_4 )
{
struct V_8 * V_190 [ V_191 + 1 ] ;
struct V_17 * V_18 ;
int V_7 = 0 ;
V_7 = F_111 ( V_190 , V_191 , V_51 , NULL , NULL ) ;
if ( V_7 < 0 )
return V_7 ;
F_8 () ;
V_18 = F_9 ( V_4 -> V_20 . V_21 ) ;
if ( F_4 ( V_18 -> V_192 ) ) {
V_7 = F_112 ( V_51 , V_191 ,
V_18 -> V_193 , NULL ) ;
if ( V_7 == 0 )
V_7 = V_18 -> V_192 ( V_190 , V_4 ) ;
}
F_11 () ;
return V_7 ;
}
static int F_113 ( struct V_8 * V_51 ,
struct V_3 * V_4 )
{
const struct V_5 * V_6 ;
struct V_8 * V_190 [ V_194 + 1 ] ;
int V_7 = 0 ;
V_7 = F_111 ( V_190 , V_194 , V_51 , V_195 ,
NULL ) ;
if ( V_7 < 0 )
return V_7 ;
if ( ! V_190 [ V_13 ] )
return - V_196 ;
V_4 -> V_14 . V_15 = F_114 ( V_190 [ V_13 ] ) ;
F_8 () ;
V_6 = F_10 ( V_4 -> V_20 . V_21 , V_4 -> V_14 . V_15 ) ;
if ( F_4 ( V_6 -> V_192 ) ) {
V_7 = F_112 ( V_51 , V_194 ,
V_6 -> V_193 , NULL ) ;
if ( V_7 == 0 )
V_7 = V_6 -> V_192 ( V_190 , V_4 ) ;
}
F_11 () ;
return V_7 ;
}
static int
F_115 ( const struct V_8 * V_51 ,
struct V_23 * V_24 )
{
F_116 ( V_24 , V_27 ,
V_129 , 0 ) ;
#ifdef F_76
if ( V_51 )
V_24 -> V_26 = F_117 ( F_118 ( V_51 ) ) ;
#else
if ( V_51 )
return - V_174 ;
#endif
return 0 ;
}
static int
F_119 ( struct V_8 * V_51 , enum V_50 type ,
struct V_23 * V_24 )
{
int V_7 ;
if ( V_24 -> V_26 != V_27 )
return - V_196 ;
V_7 = F_115 ( V_51 , V_24 ) ;
if ( V_7 < 0 )
return V_7 ;
if ( type == V_126 )
V_24 -> V_25 = V_127 ;
else
V_24 -> V_25 = V_125 ;
return 0 ;
}
static int
F_120 ( const struct V_8 * const V_167 [] ,
struct V_3 * V_4 , T_2 type ,
V_134 V_21 , struct V_23 * V_24 )
{
struct V_8 * V_190 [ V_197 + 1 ] ;
int V_102 ;
memset ( V_4 , 0 , sizeof( * V_4 ) ) ;
V_102 = F_111 ( V_190 , V_197 , V_167 [ type ] , V_198 ,
NULL ) ;
if ( V_102 < 0 )
return V_102 ;
if ( ! V_190 [ V_19 ] )
return - V_196 ;
V_4 -> V_20 . V_21 = V_21 ;
V_102 = F_110 ( V_190 [ V_19 ] , V_4 ) ;
if ( V_102 < 0 )
return V_102 ;
if ( ! V_190 [ V_10 ] )
return - V_196 ;
V_102 = F_113 ( V_190 [ V_10 ] , V_4 ) ;
if ( V_102 < 0 )
return V_102 ;
if ( V_190 [ V_124 ] ) {
if ( ! V_24 )
return - V_196 ;
V_102 = F_119 ( V_190 [ V_124 ] ,
type , V_24 ) ;
if ( V_102 < 0 )
return V_102 ;
}
if ( type == V_126 )
V_4 -> V_14 . V_25 = V_65 ;
else
V_4 -> V_14 . V_25 = V_64 ;
return 0 ;
}
static int F_121 ( const struct V_8 * V_51 , char * * V_199 ,
struct V_8 * * V_200 )
{
int V_102 ;
struct V_8 * V_190 [ V_201 + 1 ] ;
V_102 = F_111 ( V_190 , V_201 , V_51 , V_202 , NULL ) ;
if ( V_102 < 0 )
return V_102 ;
if ( ! V_190 [ V_45 ] )
return - V_196 ;
* V_199 = F_122 ( V_190 [ V_45 ] ) ;
if ( V_190 [ V_203 ] )
* V_200 = V_190 [ V_203 ] ;
return 0 ;
}
static int F_123 ( struct V_141 * V_141 ,
const struct V_8 * const V_167 [] ,
T_2 V_108 , int V_152 )
{
struct V_166 * V_168 = NULL ;
if ( V_167 [ V_74 ] && V_167 [ V_173 ] ) {
V_168 = F_87 ( V_167 ) ;
if ( F_124 ( V_168 ) )
return F_125 ( V_168 ) ;
}
F_126 ( V_141 , F_92 , V_168 ,
V_108 , V_152 ) ;
F_86 ( V_168 ) ;
return 0 ;
}
static int F_127 ( struct V_141 * V_141 , struct V_204 * V_205 ,
struct V_1 * V_2 ,
const struct V_109 * V_110 ,
const struct V_8 * const V_167 [] ,
struct V_206 * V_207 )
{
struct V_177 * V_178 ;
struct V_3 V_4 ;
struct V_28 * V_29 ;
struct V_111 * V_112 = F_59 ( V_110 ) ;
V_134 V_208 = V_112 -> V_119 ;
struct V_23 V_24 ;
int V_102 ;
V_102 = F_115 ( V_167 [ V_128 ] , & V_24 ) ;
if ( V_102 < 0 )
return V_102 ;
if ( V_167 [ V_123 ] )
V_102 = F_120 ( V_167 , & V_4 , V_123 ,
V_208 , & V_24 ) ;
else if ( V_167 [ V_126 ] )
V_102 = F_120 ( V_167 , & V_4 , V_126 ,
V_208 , & V_24 ) ;
else {
return F_123 ( V_141 , V_167 ,
F_106 ( V_2 ) . V_108 ,
F_128 ( V_110 ) ) ;
}
if ( V_102 < 0 )
return V_102 ;
V_178 = F_129 ( V_141 , & V_24 , & V_4 ) ;
if ( ! V_178 )
return - V_209 ;
V_29 = F_102 ( V_178 ) ;
if ( V_167 [ V_104 ] ) {
V_135 V_26 = F_90 ( F_91 ( V_167 [ V_104 ] ) ) ;
if ( V_26 != ( T_2 ) ( unsigned long ) V_29 ) {
F_85 ( V_29 ) ;
return - V_209 ;
}
}
F_130 ( V_29 , F_106 ( V_2 ) . V_108 , F_128 ( V_110 ) ) ;
F_85 ( V_29 ) ;
return 0 ;
}
static int F_131 ( struct V_141 * V_141 , struct V_204 * V_205 ,
struct V_1 * V_2 ,
const struct V_109 * V_110 ,
const struct V_8 * const V_167 [] ,
struct V_206 * V_207 )
{
struct V_177 * V_178 ;
struct V_3 V_4 ;
struct V_28 * V_29 ;
struct V_1 * V_210 = NULL ;
struct V_111 * V_112 = F_59 ( V_110 ) ;
V_134 V_208 = V_112 -> V_119 ;
struct V_23 V_24 ;
int V_102 ;
if ( V_110 -> V_211 & V_212 ) {
struct V_213 V_214 = {
. V_215 = F_93 ,
. V_216 = F_84 ,
} ;
if ( V_167 [ V_74 ] && V_167 [ V_173 ] ) {
struct V_166 * V_168 ;
V_168 = F_87 ( V_167 ) ;
if ( F_124 ( V_168 ) )
return F_125 ( V_168 ) ;
V_214 . V_165 = V_168 ;
}
return F_132 ( V_205 , V_2 , V_110 , & V_214 ) ;
}
V_102 = F_115 ( V_167 [ V_128 ] , & V_24 ) ;
if ( V_102 < 0 )
return V_102 ;
if ( V_167 [ V_123 ] )
V_102 = F_120 ( V_167 , & V_4 , V_123 ,
V_208 , & V_24 ) ;
else if ( V_167 [ V_126 ] )
V_102 = F_120 ( V_167 , & V_4 , V_126 ,
V_208 , & V_24 ) ;
else
return - V_196 ;
if ( V_102 < 0 )
return V_102 ;
V_178 = F_129 ( V_141 , & V_24 , & V_4 ) ;
if ( ! V_178 )
return - V_209 ;
V_29 = F_102 ( V_178 ) ;
V_102 = - V_170 ;
V_210 = F_80 ( V_217 , V_169 ) ;
if ( V_210 == NULL ) {
F_85 ( V_29 ) ;
return - V_170 ;
}
F_8 () ;
V_102 = F_56 ( V_210 , F_106 ( V_2 ) . V_108 , V_110 -> V_188 ,
F_107 ( V_110 -> V_189 ) , V_29 ) ;
F_11 () ;
F_85 ( V_29 ) ;
if ( V_102 <= 0 )
goto free;
V_102 = F_133 ( V_205 , V_210 , F_106 ( V_2 ) . V_108 , V_218 ) ;
if ( V_102 < 0 )
goto V_43;
return 0 ;
free:
F_82 ( V_210 ) ;
V_43:
return V_102 == - V_162 ? - V_161 : V_102 ;
}
static int F_134 ( struct V_163 * V_164 )
{
if ( V_164 -> args [ 1 ] )
F_85 ( (struct V_28 * ) V_164 -> args [ 1 ] ) ;
return 0 ;
}
static int
F_135 ( struct V_1 * V_2 , struct V_163 * V_164 , bool V_219 )
{
struct V_28 * V_29 , * V_176 ;
struct V_177 * V_178 ;
struct V_179 * V_180 ;
struct V_111 * V_112 = F_59 ( V_164 -> V_110 ) ;
V_134 V_18 = V_112 -> V_119 ;
int V_182 ;
int V_220 ;
struct V_221 * V_222 ;
struct V_141 * V_141 = F_94 ( V_2 -> V_175 ) ;
if ( V_164 -> args [ 2 ] )
return 0 ;
V_176 = (struct V_28 * ) V_164 -> args [ 1 ] ;
for ( V_220 = V_164 -> args [ 0 ] ; V_220 < V_223 ; V_220 ++ ) {
struct V_224 * V_225 ;
if ( ! F_136 ( V_220 ) )
continue;
V_225 = F_137 ( V_141 -> V_29 . V_226 , V_220 ) ;
F_51 ( & V_225 -> V_100 ) ;
V_222 = V_219 ? & V_225 -> V_219 : & V_225 -> V_227 ;
V_185:
F_100 (h, n, list, hnnode) {
V_29 = F_102 ( V_178 ) ;
if ( V_18 && F_21 ( V_29 ) != V_18 )
continue;
if ( V_164 -> args [ 1 ] ) {
if ( V_29 != V_176 )
continue;
V_164 -> args [ 1 ] = 0 ;
}
F_8 () ;
V_182 = F_56 ( V_2 , F_106 ( V_164 -> V_2 ) . V_108 ,
V_164 -> V_110 -> V_188 ,
F_107 ( V_164 -> V_110 -> V_189 ) ,
V_29 ) ;
F_11 () ;
if ( V_182 < 0 ) {
if ( ! F_104 ( & V_29 -> V_106 . V_107 ) )
continue;
V_164 -> args [ 0 ] = V_220 ;
V_164 -> args [ 1 ] = ( unsigned long ) V_29 ;
F_52 ( & V_225 -> V_100 ) ;
goto V_43;
}
}
if ( V_164 -> args [ 1 ] ) {
V_164 -> args [ 1 ] = 0 ;
goto V_185;
}
F_52 ( & V_225 -> V_100 ) ;
}
V_164 -> args [ 2 ] = 1 ;
V_43:
if ( V_176 )
F_85 ( V_176 ) ;
return V_2 -> V_77 ;
}
static int
F_138 ( struct V_1 * V_2 , struct V_163 * V_164 )
{
return F_135 ( V_2 , V_164 , true ) ;
}
static int F_139 ( struct V_141 * V_141 , struct V_204 * V_205 ,
struct V_1 * V_2 ,
const struct V_109 * V_110 ,
const struct V_8 * const V_167 [] ,
struct V_206 * V_207 )
{
if ( V_110 -> V_211 & V_212 ) {
struct V_213 V_214 = {
. V_215 = F_138 ,
. V_216 = F_134 ,
} ;
return F_132 ( V_205 , V_2 , V_110 , & V_214 ) ;
}
return - V_174 ;
}
static int
F_140 ( struct V_1 * V_2 , struct V_163 * V_164 )
{
return F_135 ( V_2 , V_164 , false ) ;
}
static int F_141 ( struct V_141 * V_141 , struct V_204 * V_205 ,
struct V_1 * V_2 ,
const struct V_109 * V_110 ,
const struct V_8 * const V_167 [] ,
struct V_206 * V_207 )
{
if ( V_110 -> V_211 & V_212 ) {
struct V_213 V_214 = {
. V_215 = F_140 ,
. V_216 = F_134 ,
} ;
return F_132 ( V_205 , V_2 , V_110 , & V_214 ) ;
}
return - V_174 ;
}
static int
F_142 ( struct V_28 * V_29 ,
enum V_228 V_229 ,
const struct V_8 * V_51 )
{
F_143 (nfnetlink_parse_nat_setup_hook) V_230 ;
int V_102 ;
V_230 = F_25 ( V_231 ) ;
if ( ! V_230 ) {
#ifdef F_144
F_11 () ;
F_145 ( V_116 ) ;
if ( F_146 ( L_1 ) < 0 ) {
F_147 ( V_116 ) ;
F_8 () ;
return - V_174 ;
}
F_147 ( V_116 ) ;
F_8 () ;
if ( V_231 )
return - V_162 ;
#endif
return - V_174 ;
}
V_102 = V_230 ( V_29 , V_229 , V_51 ) ;
if ( V_102 == - V_162 ) {
#ifdef F_144
F_11 () ;
F_145 ( V_116 ) ;
if ( F_146 ( L_2 , F_21 ( V_29 ) ) < 0 ) {
F_147 ( V_116 ) ;
F_8 () ;
return - V_174 ;
}
F_147 ( V_116 ) ;
F_8 () ;
#else
V_102 = - V_174 ;
#endif
}
return V_102 ;
}
static void
F_148 ( struct V_28 * V_29 , unsigned long V_232 ,
unsigned long V_233 )
{
unsigned int V_234 ;
V_232 &= ~ V_235 ;
V_233 &= ~ V_235 ;
for ( V_234 = 0 ; V_234 < V_236 ; V_234 ++ ) {
if ( V_232 & ( 1 << V_234 ) )
F_149 ( V_234 , & V_29 -> V_31 ) ;
else if ( V_233 & ( 1 << V_234 ) )
F_150 ( V_234 , & V_29 -> V_31 ) ;
}
}
static int
F_151 ( struct V_28 * V_29 , const struct V_8 * const V_167 [] )
{
unsigned long V_237 ;
unsigned int V_31 = F_90 ( F_91 ( V_167 [ V_30 ] ) ) ;
V_237 = V_29 -> V_31 ^ V_31 ;
if ( V_237 & ( V_87 | V_238 | V_239 ) )
return - V_240 ;
if ( V_237 & V_241 && ! ( V_31 & V_241 ) )
return - V_240 ;
if ( V_237 & V_242 && ! ( V_31 & V_242 ) )
return - V_240 ;
F_148 ( V_29 , V_31 , 0 ) ;
return 0 ;
}
static int
F_152 ( struct V_28 * V_29 , const struct V_8 * const V_167 [] )
{
#ifdef F_74
int V_7 ;
if ( ! V_167 [ V_243 ] && ! V_167 [ V_244 ] )
return 0 ;
V_7 = F_142 ( V_29 , V_245 ,
V_167 [ V_243 ] ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_142 ( V_29 , V_246 ,
V_167 [ V_244 ] ) ;
return V_7 ;
#else
if ( ! V_167 [ V_243 ] && ! V_167 [ V_244 ] )
return 0 ;
return - V_174 ;
#endif
}
static int F_153 ( struct V_28 * V_29 ,
const struct V_8 * const V_167 [] )
{
struct V_41 * V_42 ;
struct V_39 * V_40 = F_24 ( V_29 ) ;
char * V_247 = NULL ;
struct V_8 * V_200 = NULL ;
int V_102 ;
V_102 = F_121 ( V_167 [ V_44 ] , & V_247 , & V_200 ) ;
if ( V_102 < 0 )
return V_102 ;
if ( V_29 -> V_248 ) {
V_102 = - V_240 ;
if ( V_40 ) {
F_8 () ;
V_42 = F_25 ( V_40 -> V_42 ) ;
if ( V_42 && ! strcmp ( V_42 -> V_46 , V_247 ) )
V_102 = 0 ;
F_11 () ;
}
return V_102 ;
}
if ( ! strcmp ( V_247 , L_3 ) ) {
if ( V_40 && V_40 -> V_42 ) {
F_154 ( V_29 ) ;
F_155 ( V_40 -> V_42 , NULL ) ;
}
return 0 ;
}
F_8 () ;
V_42 = F_156 ( V_247 , F_21 ( V_29 ) ,
F_22 ( V_29 ) ) ;
if ( V_42 == NULL ) {
F_11 () ;
return - V_174 ;
}
if ( V_40 ) {
if ( V_40 -> V_42 == V_42 ) {
if ( V_42 -> V_249 )
V_42 -> V_249 ( V_200 , V_29 ) ;
V_102 = 0 ;
} else
V_102 = - V_240 ;
} else {
V_102 = - V_174 ;
}
F_11 () ;
return V_102 ;
}
static int F_157 ( struct V_28 * V_29 ,
const struct V_8 * const V_167 [] )
{
V_135 V_32 = F_90 ( F_91 ( V_167 [ V_34 ] ) ) ;
V_29 -> V_32 = V_250 + V_32 * V_33 ;
if ( F_158 ( V_251 , & V_29 -> V_31 ) )
return - V_252 ;
return 0 ;
}
static int F_159 ( struct V_28 * V_29 ,
const struct V_8 * const V_167 [] )
{
const struct V_8 * V_51 = V_167 [ V_37 ] ;
const struct V_5 * V_6 ;
struct V_8 * V_190 [ V_253 + 1 ] ;
int V_102 = 0 ;
V_102 = F_111 ( V_190 , V_253 , V_51 , V_254 ,
NULL ) ;
if ( V_102 < 0 )
return V_102 ;
F_8 () ;
V_6 = F_10 ( F_21 ( V_29 ) , F_22 ( V_29 ) ) ;
if ( V_6 -> V_249 )
V_102 = V_6 -> V_249 ( V_190 , V_29 ) ;
F_11 () ;
return V_102 ;
}
static int F_160 ( struct V_89 * V_90 ,
const struct V_8 * const V_51 )
{
int V_102 ;
struct V_8 * V_167 [ V_255 + 1 ] ;
V_102 = F_111 ( V_167 , V_255 , V_51 , V_256 , NULL ) ;
if ( V_102 < 0 )
return V_102 ;
if ( ! V_167 [ V_91 ] )
return - V_196 ;
V_90 -> V_92 =
F_90 ( F_91 ( V_167 [ V_91 ] ) ) ;
if ( ! V_167 [ V_93 ] )
return - V_196 ;
V_90 -> V_94 =
F_90 ( F_91 ( V_167 [ V_93 ] ) ) ;
if ( ! V_167 [ V_95 ] )
return - V_196 ;
V_90 -> V_96 =
F_90 ( F_91 ( V_167 [ V_95 ] ) ) ;
return 0 ;
}
static int
F_161 ( struct V_28 * V_29 ,
const struct V_8 * const V_167 [] )
{
struct V_97 * V_98 = F_50 ( V_29 ) ;
int V_7 = 0 ;
if ( ! V_98 )
return 0 ;
F_51 ( & V_29 -> V_100 ) ;
if ( V_167 [ V_101 ] ) {
V_7 = F_160 ( & V_98 -> V_90 [ V_64 ] ,
V_167 [ V_101 ] ) ;
if ( V_7 < 0 )
goto V_102;
F_149 ( V_257 , & V_29 -> V_31 ) ;
}
if ( V_167 [ V_103 ] ) {
V_7 = F_160 ( & V_98 -> V_90 [ V_65 ] ,
V_167 [ V_103 ] ) ;
if ( V_7 < 0 )
goto V_102;
F_149 ( V_257 , & V_29 -> V_31 ) ;
}
F_52 ( & V_29 -> V_100 ) ;
return 0 ;
V_102:
F_52 ( & V_29 -> V_100 ) ;
return V_7 ;
}
static int
F_162 ( struct V_28 * V_29 , const struct V_8 * const V_167 [] )
{
#ifdef F_163
T_3 V_77 = F_164 ( V_167 [ V_86 ] ) ;
const void * V_172 = V_167 [ V_258 ] ;
if ( V_77 & ( sizeof( T_2 ) - 1 ) )
return - V_196 ;
if ( V_172 ) {
if ( F_164 ( V_167 [ V_258 ] ) == 0 ||
F_164 ( V_167 [ V_258 ] ) != V_77 )
return - V_196 ;
V_172 = F_122 ( V_167 [ V_258 ] ) ;
}
V_77 /= sizeof( T_2 ) ;
return F_165 ( V_29 , F_122 ( V_167 [ V_86 ] ) , V_172 , V_77 ) ;
#else
return - V_174 ;
#endif
}
static int
F_166 ( struct V_28 * V_29 ,
const struct V_8 * const V_167 [] )
{
int V_102 ;
if ( V_167 [ V_244 ] || V_167 [ V_243 ] || V_167 [ V_88 ] )
return - V_174 ;
if ( V_167 [ V_44 ] ) {
V_102 = F_153 ( V_29 , V_167 ) ;
if ( V_102 < 0 )
return V_102 ;
}
if ( V_167 [ V_34 ] ) {
V_102 = F_157 ( V_29 , V_167 ) ;
if ( V_102 < 0 )
return V_102 ;
}
if ( V_167 [ V_30 ] ) {
V_102 = F_151 ( V_29 , V_167 ) ;
if ( V_102 < 0 )
return V_102 ;
}
if ( V_167 [ V_37 ] ) {
V_102 = F_159 ( V_29 , V_167 ) ;
if ( V_102 < 0 )
return V_102 ;
}
#if F_167 ( F_75 )
if ( V_167 [ V_74 ] )
V_29 -> V_75 = F_90 ( F_91 ( V_167 [ V_74 ] ) ) ;
#endif
if ( V_167 [ V_101 ] || V_167 [ V_103 ] ) {
V_102 = F_161 ( V_29 , V_167 ) ;
if ( V_102 < 0 )
return V_102 ;
}
if ( V_167 [ V_86 ] ) {
V_102 = F_162 ( V_29 , V_167 ) ;
if ( V_102 < 0 )
return V_102 ;
}
return 0 ;
}
static struct V_28 *
F_168 ( struct V_141 * V_141 ,
const struct V_23 * V_24 ,
const struct V_8 * const V_167 [] ,
struct V_3 * V_259 ,
struct V_3 * V_260 ,
T_5 V_208 )
{
struct V_28 * V_29 ;
int V_102 = - V_196 ;
struct V_41 * V_42 ;
struct V_66 * V_67 ;
V_29 = F_169 ( V_141 , V_24 , V_259 , V_260 , V_153 ) ;
if ( F_124 ( V_29 ) )
return F_89 ( - V_170 ) ;
if ( ! V_167 [ V_34 ] )
goto V_261;
V_29 -> V_32 = V_250 + F_90 ( F_91 ( V_167 [ V_34 ] ) ) * V_33 ;
F_8 () ;
if ( V_167 [ V_44 ] ) {
char * V_247 = NULL ;
struct V_8 * V_200 = NULL ;
V_102 = F_121 ( V_167 [ V_44 ] , & V_247 , & V_200 ) ;
if ( V_102 < 0 )
goto V_262;
V_42 = F_156 ( V_247 , F_21 ( V_29 ) ,
F_22 ( V_29 ) ) ;
if ( V_42 == NULL ) {
F_11 () ;
#ifdef F_144
if ( F_146 ( L_4 , V_247 ) < 0 ) {
V_102 = - V_174 ;
goto V_261;
}
F_8 () ;
V_42 = F_156 ( V_247 ,
F_21 ( V_29 ) ,
F_22 ( V_29 ) ) ;
if ( V_42 ) {
V_102 = - V_162 ;
goto V_262;
}
F_11 () ;
#endif
V_102 = - V_174 ;
goto V_261;
} else {
struct V_39 * V_40 ;
V_40 = F_170 ( V_29 , V_42 , V_153 ) ;
if ( V_40 == NULL ) {
V_102 = - V_170 ;
goto V_262;
}
if ( V_42 -> V_249 )
V_42 -> V_249 ( V_200 , V_29 ) ;
F_155 ( V_40 -> V_42 , V_42 ) ;
}
} else {
V_102 = F_171 ( V_29 , NULL , V_153 ) ;
if ( V_102 < 0 )
goto V_262;
}
V_102 = F_152 ( V_29 , V_167 ) ;
if ( V_102 < 0 )
goto V_262;
F_172 ( V_29 , V_153 ) ;
F_173 ( V_29 , V_153 ) ;
F_174 ( V_29 , 0 , 0 , V_153 ) ;
F_175 ( V_29 ) ;
F_176 ( V_29 ) ;
F_177 ( V_29 ) ;
V_29 -> V_31 |= V_238 ;
if ( V_167 [ V_30 ] ) {
V_102 = F_151 ( V_29 , V_167 ) ;
if ( V_102 < 0 )
goto V_262;
}
if ( V_167 [ V_101 ] || V_167 [ V_103 ] ) {
V_102 = F_161 ( V_29 , V_167 ) ;
if ( V_102 < 0 )
goto V_262;
}
memset ( & V_29 -> V_263 , 0 , sizeof( V_29 -> V_263 ) ) ;
if ( V_167 [ V_37 ] ) {
V_102 = F_159 ( V_29 , V_167 ) ;
if ( V_102 < 0 )
goto V_262;
}
#if F_167 ( F_75 )
if ( V_167 [ V_74 ] )
V_29 -> V_75 = F_90 ( F_91 ( V_167 [ V_74 ] ) ) ;
#endif
if ( V_167 [ V_88 ] ) {
struct V_3 V_248 ;
struct V_177 * V_264 ;
struct V_28 * V_265 ;
V_102 = F_120 ( V_167 , & V_248 , V_88 ,
V_208 , NULL ) ;
if ( V_102 < 0 )
goto V_262;
V_264 = F_129 ( V_141 , V_24 , & V_248 ) ;
if ( V_264 == NULL ) {
V_102 = - V_209 ;
goto V_262;
}
V_265 = F_102 ( V_264 ) ;
F_178 ( V_266 , & V_29 -> V_31 ) ;
V_29 -> V_248 = V_265 ;
}
V_67 = F_35 ( V_29 ) ;
if ( V_67 )
V_67 -> V_70 = F_179 () ;
V_102 = F_180 ( V_29 ) ;
if ( V_102 < 0 )
goto V_262;
F_11 () ;
return V_29 ;
V_262:
F_11 () ;
V_261:
F_181 ( V_29 ) ;
return F_89 ( V_102 ) ;
}
static int F_182 ( struct V_141 * V_141 , struct V_204 * V_205 ,
struct V_1 * V_2 ,
const struct V_109 * V_110 ,
const struct V_8 * const V_167 [] ,
struct V_206 * V_207 )
{
struct V_3 V_259 , V_260 ;
struct V_177 * V_178 = NULL ;
struct V_111 * V_112 = F_59 ( V_110 ) ;
struct V_28 * V_29 ;
V_134 V_208 = V_112 -> V_119 ;
struct V_23 V_24 ;
int V_102 ;
V_102 = F_115 ( V_167 [ V_128 ] , & V_24 ) ;
if ( V_102 < 0 )
return V_102 ;
if ( V_167 [ V_123 ] ) {
V_102 = F_120 ( V_167 , & V_259 , V_123 ,
V_208 , & V_24 ) ;
if ( V_102 < 0 )
return V_102 ;
}
if ( V_167 [ V_126 ] ) {
V_102 = F_120 ( V_167 , & V_260 , V_126 ,
V_208 , & V_24 ) ;
if ( V_102 < 0 )
return V_102 ;
}
if ( V_167 [ V_123 ] )
V_178 = F_129 ( V_141 , & V_24 , & V_259 ) ;
else if ( V_167 [ V_126 ] )
V_178 = F_129 ( V_141 , & V_24 , & V_260 ) ;
if ( V_178 == NULL ) {
V_102 = - V_209 ;
if ( V_110 -> V_211 & V_148 ) {
enum V_267 V_138 ;
if ( ! V_167 [ V_123 ] || ! V_167 [ V_126 ] )
return - V_196 ;
if ( V_259 . V_14 . V_15 != V_260 . V_14 . V_15 )
return - V_196 ;
V_29 = F_168 ( V_141 , & V_24 , V_167 , & V_259 ,
& V_260 , V_208 ) ;
if ( F_124 ( V_29 ) )
return F_125 ( V_29 ) ;
V_102 = 0 ;
if ( F_158 ( V_266 , & V_29 -> V_31 ) )
V_138 = 1 << V_147 ;
else
V_138 = 1 << V_146 ;
if ( V_167 [ V_86 ] &&
F_162 ( V_29 , V_167 ) == 0 )
V_138 |= ( 1 << V_158 ) ;
F_183 ( ( 1 << V_268 ) |
( 1 << V_269 ) |
( 1 << V_156 ) |
( 1 << V_155 ) |
( 1 << V_159 ) |
( 1 << V_160 ) | V_138 ,
V_29 , F_106 ( V_2 ) . V_108 ,
F_128 ( V_110 ) ) ;
F_85 ( V_29 ) ;
}
return V_102 ;
}
V_102 = - V_270 ;
V_29 = F_102 ( V_178 ) ;
if ( ! ( V_110 -> V_211 & V_149 ) ) {
V_102 = F_166 ( V_29 , V_167 ) ;
if ( V_102 == 0 ) {
F_183 ( ( 1 << V_268 ) |
( 1 << V_269 ) |
( 1 << V_156 ) |
( 1 << V_158 ) |
( 1 << V_155 ) |
( 1 << V_159 ) |
( 1 << V_160 ) ,
V_29 , F_106 ( V_2 ) . V_108 ,
F_128 ( V_110 ) ) ;
}
}
F_85 ( V_29 ) ;
return V_102 ;
}
static int
F_184 ( struct V_1 * V_2 , T_2 V_108 , T_2 V_90 ,
T_6 V_220 , const struct V_271 * V_272 )
{
struct V_109 * V_110 ;
struct V_111 * V_112 ;
unsigned int V_113 = V_108 ? V_114 : 0 , V_115 ;
V_115 = F_57 ( V_116 ,
V_273 ) ;
V_110 = F_58 ( V_2 , V_108 , V_90 , V_115 , sizeof( * V_112 ) , V_113 ) ;
if ( V_110 == NULL )
goto V_118;
V_112 = F_59 ( V_110 ) ;
V_112 -> V_119 = V_274 ;
V_112 -> V_120 = V_121 ;
V_112 -> V_122 = F_14 ( V_220 ) ;
if ( F_16 ( V_2 , V_275 , F_17 ( V_272 -> V_276 ) ) ||
F_16 ( V_2 , V_277 , F_17 ( V_272 -> V_278 ) ) ||
F_16 ( V_2 , V_279 , F_17 ( V_272 -> V_280 ) ) ||
F_16 ( V_2 , V_281 , F_17 ( V_272 -> V_282 ) ) ||
F_16 ( V_2 , V_283 ,
F_17 ( V_272 -> V_284 ) ) ||
F_16 ( V_2 , V_285 , F_17 ( V_272 -> V_286 ) ) ||
F_16 ( V_2 , V_287 , F_17 ( V_272 -> V_288 ) ) ||
F_16 ( V_2 , V_289 , F_17 ( V_272 -> error ) ) ||
F_16 ( V_2 , V_290 ,
F_17 ( V_272 -> V_291 ) ) )
goto V_12;
F_62 ( V_2 , V_110 ) ;
return V_2 -> V_77 ;
V_12:
V_118:
F_63 ( V_2 , V_110 ) ;
return - 1 ;
}
static int
F_185 ( struct V_1 * V_2 , struct V_163 * V_164 )
{
int V_220 ;
struct V_141 * V_141 = F_94 ( V_2 -> V_175 ) ;
if ( V_164 -> args [ 0 ] == V_223 )
return 0 ;
for ( V_220 = V_164 -> args [ 0 ] ; V_220 < V_223 ; V_220 ++ ) {
const struct V_271 * V_272 ;
if ( ! F_136 ( V_220 ) )
continue;
V_272 = F_137 ( V_141 -> V_29 . V_292 , V_220 ) ;
if ( F_184 ( V_2 ,
F_106 ( V_164 -> V_2 ) . V_108 ,
V_164 -> V_110 -> V_188 ,
V_220 , V_272 ) < 0 )
break;
}
V_164 -> args [ 0 ] = V_220 ;
return V_2 -> V_77 ;
}
static int F_186 ( struct V_141 * V_141 , struct V_204 * V_205 ,
struct V_1 * V_2 ,
const struct V_109 * V_110 ,
const struct V_8 * const V_167 [] ,
struct V_206 * V_207 )
{
if ( V_110 -> V_211 & V_212 ) {
struct V_213 V_214 = {
. V_215 = F_185 ,
} ;
return F_132 ( V_205 , V_2 , V_110 , & V_214 ) ;
}
return 0 ;
}
static int
F_187 ( struct V_1 * V_2 , T_2 V_108 , T_2 V_90 , T_2 type ,
struct V_141 * V_141 )
{
struct V_109 * V_110 ;
struct V_111 * V_112 ;
unsigned int V_113 = V_108 ? V_114 : 0 , V_115 ;
unsigned int V_293 = F_55 ( & V_141 -> V_29 . V_294 ) ;
V_115 = F_57 ( V_116 , V_295 ) ;
V_110 = F_58 ( V_2 , V_108 , V_90 , V_115 , sizeof( * V_112 ) , V_113 ) ;
if ( V_110 == NULL )
goto V_118;
V_112 = F_59 ( V_110 ) ;
V_112 -> V_119 = V_274 ;
V_112 -> V_120 = V_121 ;
V_112 -> V_122 = 0 ;
if ( F_16 ( V_2 , V_296 , F_17 ( V_293 ) ) )
goto V_12;
F_62 ( V_2 , V_110 ) ;
return V_2 -> V_77 ;
V_12:
V_118:
F_63 ( V_2 , V_110 ) ;
return - 1 ;
}
static int F_188 ( struct V_141 * V_141 , struct V_204 * V_205 ,
struct V_1 * V_2 , const struct V_109 * V_110 ,
const struct V_8 * const V_167 [] ,
struct V_206 * V_207 )
{
struct V_1 * V_210 ;
int V_102 ;
V_210 = F_80 ( V_217 , V_169 ) ;
if ( V_210 == NULL )
return - V_170 ;
V_102 = F_187 ( V_210 , F_106 ( V_2 ) . V_108 ,
V_110 -> V_188 ,
F_107 ( V_110 -> V_189 ) ,
F_94 ( V_2 -> V_175 ) ) ;
if ( V_102 <= 0 )
goto free;
V_102 = F_133 ( V_205 , V_210 , F_106 ( V_2 ) . V_108 , V_218 ) ;
if ( V_102 < 0 )
goto V_43;
return 0 ;
free:
F_82 ( V_210 ) ;
V_43:
return V_102 == - V_162 ? - V_161 : V_102 ;
}
static T_3
F_189 ( const struct V_28 * V_29 )
{
return 3 * F_42 ( 0 )
+ 3 * F_42 ( 0 )
+ 3 * F_42 ( 0 )
+ 3 * F_42 ( sizeof( V_134 ) )
+ F_42 ( sizeof( V_135 ) )
+ F_42 ( sizeof( V_135 ) )
+ F_42 ( sizeof( V_135 ) )
+ F_42 ( 0 )
+ F_42 ( 0 )
+ F_42 ( V_136 )
+ F_68 ( V_29 )
#ifdef F_74
+ 2 * F_42 ( 0 )
+ 6 * F_42 ( sizeof( V_135 ) )
#endif
#ifdef F_75
+ F_42 ( sizeof( V_135 ) )
#endif
#ifdef F_76
+ F_42 ( sizeof( V_137 ) )
#endif
+ F_64 ( V_29 )
;
}
static struct V_28 * F_190 ( const struct V_1 * V_2 ,
enum V_297 * V_298 )
{
return F_191 ( V_2 , V_298 ) ;
}
static int F_192 ( struct V_1 * V_2 , struct V_28 * V_29 )
{
const struct V_23 * V_24 ;
struct V_8 * V_9 ;
V_24 = F_60 ( V_29 ) ;
V_9 = F_2 ( V_2 , V_123 | V_11 ) ;
if ( ! V_9 )
goto V_12;
if ( F_7 ( V_2 , F_61 ( V_29 , V_64 ) ) < 0 )
goto V_12;
if ( F_12 ( V_2 , V_124 , V_24 ,
V_125 ) < 0 )
goto V_12;
F_5 ( V_2 , V_9 ) ;
V_9 = F_2 ( V_2 , V_126 | V_11 ) ;
if ( ! V_9 )
goto V_12;
if ( F_7 ( V_2 , F_61 ( V_29 , V_65 ) ) < 0 )
goto V_12;
if ( F_12 ( V_2 , V_124 , V_24 ,
V_127 ) < 0 )
goto V_12;
F_5 ( V_2 , V_9 ) ;
if ( F_12 ( V_2 , V_128 , V_24 ,
V_129 ) < 0 )
goto V_12;
if ( F_53 ( V_2 , V_29 ) < 0 )
goto V_12;
if ( F_15 ( V_2 , V_29 ) < 0 )
goto V_12;
if ( F_18 ( V_2 , V_29 ) < 0 )
goto V_12;
if ( F_20 ( V_2 , V_29 ) < 0 )
goto V_12;
if ( F_23 ( V_2 , V_29 ) < 0 )
goto V_12;
#ifdef F_69
if ( V_29 -> V_79 && F_37 ( V_2 , V_29 ) < 0 )
goto V_12;
#endif
if ( V_29 -> V_248 && F_46 ( V_2 , V_29 ) < 0 )
goto V_12;
if ( ( V_29 -> V_31 & V_99 ) &&
F_49 ( V_2 , V_29 ) < 0 )
goto V_12;
#ifdef F_75
if ( V_29 -> V_75 && F_36 ( V_2 , V_29 ) < 0 )
goto V_12;
#endif
if ( F_43 ( V_2 , V_29 ) < 0 )
goto V_12;
return 0 ;
V_12:
return - V_299 ;
}
static int
F_193 ( struct V_1 * V_2 , struct V_28 * V_29 ,
enum V_297 V_298 ,
V_137 V_300 , V_137 V_301 )
{
struct V_8 * V_9 ;
V_9 = F_2 ( V_2 , V_300 | V_11 ) ;
if ( ! V_9 )
goto V_12;
if ( F_192 ( V_2 , V_29 ) < 0 )
goto V_12;
F_5 ( V_2 , V_9 ) ;
if ( F_16 ( V_2 , V_301 , F_17 ( V_298 ) ) )
goto V_12;
return 0 ;
V_12:
return - V_299 ;
}
static int
F_194 ( struct V_28 * V_29 , const struct V_8 * const V_167 [] )
{
unsigned int V_31 = F_90 ( F_91 ( V_167 [ V_30 ] ) ) ;
unsigned long V_237 = V_29 -> V_31 ^ V_31 ;
if ( V_237 & V_241 && ! ( V_31 & V_241 ) )
return - V_240 ;
if ( V_237 & V_242 && ! ( V_31 & V_242 ) )
return - V_240 ;
F_148 ( V_29 , V_31 , ~ V_31 ) ;
return 0 ;
}
static int
F_195 ( const struct V_8 * V_167 [] , struct V_28 * V_29 )
{
int V_102 ;
if ( V_167 [ V_34 ] ) {
V_102 = F_157 ( V_29 , V_167 ) ;
if ( V_102 < 0 )
return V_102 ;
}
if ( V_167 [ V_30 ] ) {
V_102 = F_194 ( V_29 , V_167 ) ;
if ( V_102 < 0 )
return V_102 ;
}
if ( V_167 [ V_44 ] ) {
V_102 = F_153 ( V_29 , V_167 ) ;
if ( V_102 < 0 )
return V_102 ;
}
if ( V_167 [ V_86 ] ) {
V_102 = F_162 ( V_29 , V_167 ) ;
if ( V_102 < 0 )
return V_102 ;
}
#if F_167 ( F_75 )
if ( V_167 [ V_74 ] ) {
T_2 V_172 = 0 , V_75 , V_302 ;
if ( V_167 [ V_173 ] )
V_172 = ~ F_90 ( F_91 ( V_167 [ V_173 ] ) ) ;
V_75 = F_90 ( F_91 ( V_167 [ V_74 ] ) ) ;
V_302 = ( V_29 -> V_75 & V_172 ) ^ V_75 ;
if ( V_302 != V_29 -> V_75 )
V_29 -> V_75 = V_302 ;
}
#endif
return 0 ;
}
static int
F_196 ( const struct V_8 * V_51 , struct V_28 * V_29 )
{
struct V_8 * V_167 [ V_303 + 1 ] ;
int V_7 ;
V_7 = F_111 ( V_167 , V_303 , V_51 , V_304 , NULL ) ;
if ( V_7 < 0 )
return V_7 ;
return F_195 ( ( const struct V_8 * * ) V_167 , V_29 ) ;
}
static int F_197 ( const struct V_8 * const * V_167 ,
const struct V_28 * V_29 ,
struct V_3 * V_4 ,
struct V_3 * V_172 )
{
int V_102 ;
V_102 = F_120 ( V_167 , V_4 , V_305 ,
F_21 ( V_29 ) , NULL ) ;
if ( V_102 < 0 )
return V_102 ;
return F_120 ( V_167 , V_172 , V_306 ,
F_21 ( V_29 ) , NULL ) ;
}
static int
F_198 ( const struct V_8 * V_51 , struct V_28 * V_29 ,
T_2 V_108 , T_2 V_152 )
{
struct V_8 * V_167 [ V_307 + 1 ] ;
struct V_3 V_4 , V_172 ;
struct V_41 * V_42 = NULL ;
struct V_308 * exp ;
int V_102 ;
V_102 = F_111 ( V_167 , V_307 , V_51 , V_309 ,
NULL ) ;
if ( V_102 < 0 )
return V_102 ;
V_102 = F_197 ( ( const struct V_8 * const * ) V_167 ,
V_29 , & V_4 , & V_172 ) ;
if ( V_102 < 0 )
return V_102 ;
if ( V_167 [ V_310 ] ) {
const char * V_247 = F_122 ( V_167 [ V_310 ] ) ;
V_42 = F_156 ( V_247 , F_21 ( V_29 ) ,
F_22 ( V_29 ) ) ;
if ( V_42 == NULL )
return - V_174 ;
}
exp = F_199 ( ( const struct V_8 * const * ) V_167 , V_29 ,
V_42 , & V_4 , & V_172 ) ;
if ( F_124 ( exp ) )
return F_125 ( exp ) ;
V_102 = F_200 ( exp , V_108 , V_152 ) ;
F_201 ( exp ) ;
return V_102 ;
}
static void F_202 ( struct V_1 * V_2 , struct V_28 * V_29 ,
enum V_297 V_298 , int V_311 )
{
if ( ! ( V_29 -> V_31 & V_312 ) )
return;
F_203 ( V_2 , V_29 , V_298 , V_311 ) ;
}
static int F_204 ( struct V_1 * V_2 ,
const struct V_3 * V_4 ,
T_2 type )
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
static int F_205 ( struct V_1 * V_2 ,
const struct V_3 * V_4 ,
const struct V_313 * V_172 )
{
const struct V_17 * V_18 ;
const struct V_5 * V_6 ;
struct V_3 V_314 ;
struct V_8 * V_9 ;
int V_7 ;
memset ( & V_314 , 0xFF , sizeof( V_314 ) ) ;
memcpy ( & V_314 . V_20 . V_208 , & V_172 -> V_20 . V_208 , sizeof( V_314 . V_20 . V_208 ) ) ;
V_314 . V_20 . V_315 . V_316 = V_172 -> V_20 . V_315 . V_316 ;
V_314 . V_14 . V_15 = V_4 -> V_14 . V_15 ;
V_9 = F_2 ( V_2 , V_306 | V_11 ) ;
if ( ! V_9 )
goto V_12;
F_8 () ;
V_18 = F_9 ( V_4 -> V_20 . V_21 ) ;
V_7 = F_6 ( V_2 , & V_314 , V_18 ) ;
if ( V_7 >= 0 ) {
V_6 = F_10 ( V_4 -> V_20 . V_21 ,
V_4 -> V_14 . V_15 ) ;
V_7 = F_1 ( V_2 , & V_314 , V_6 ) ;
}
F_11 () ;
if ( F_206 ( V_7 < 0 ) )
goto V_12;
F_5 ( V_2 , V_9 ) ;
return 0 ;
V_12:
return - 1 ;
}
static int
F_207 ( struct V_1 * V_2 ,
const struct V_308 * exp )
{
struct V_28 * V_248 = exp -> V_248 ;
long V_32 = ( ( long ) exp -> V_32 . V_317 - ( long ) V_318 ) / V_33 ;
struct V_39 * V_40 ;
#ifdef F_74
struct V_8 * V_9 ;
struct V_3 V_319 = {} ;
#endif
struct V_320 * V_321 ;
if ( V_32 < 0 )
V_32 = 0 ;
if ( F_204 ( V_2 , & exp -> V_4 , V_305 ) < 0 )
goto V_12;
if ( F_205 ( V_2 , & exp -> V_4 , & exp -> V_172 ) < 0 )
goto V_12;
if ( F_204 ( V_2 ,
& V_248 -> V_322 [ V_64 ] . V_4 ,
V_323 ) < 0 )
goto V_12;
#ifdef F_74
if ( ! F_208 ( & exp -> V_324 , & V_325 ) ||
exp -> V_326 . V_316 ) {
V_9 = F_2 ( V_2 , V_327 | V_11 ) ;
if ( ! V_9 )
goto V_12;
if ( F_16 ( V_2 , V_328 , F_17 ( exp -> V_25 ) ) )
goto V_12;
V_319 . V_20 . V_21 = F_21 ( V_248 ) ;
V_319 . V_20 . V_208 = exp -> V_324 ;
V_319 . V_14 . V_15 = F_22 ( V_248 ) ;
V_319 . V_20 . V_315 = exp -> V_326 ;
if ( F_204 ( V_2 , & V_319 ,
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
V_40 = F_24 ( V_248 ) ;
if ( V_40 ) {
struct V_41 * V_42 ;
V_42 = F_25 ( V_40 -> V_42 ) ;
if ( V_42 &&
F_26 ( V_2 , V_310 , V_42 -> V_46 ) )
goto V_12;
}
V_321 = F_209 ( exp -> V_335 ) ;
if ( V_321 != NULL &&
F_26 ( V_2 , V_336 , V_321 -> V_46 ) )
goto V_12;
return 0 ;
V_12:
return - 1 ;
}
static int
F_210 ( struct V_1 * V_2 , T_2 V_108 , T_2 V_90 ,
int V_115 , const struct V_308 * exp )
{
struct V_109 * V_110 ;
struct V_111 * V_112 ;
unsigned int V_113 = V_108 ? V_114 : 0 ;
V_115 = F_57 ( V_337 , V_115 ) ;
V_110 = F_58 ( V_2 , V_108 , V_90 , V_115 , sizeof( * V_112 ) , V_113 ) ;
if ( V_110 == NULL )
goto V_118;
V_112 = F_59 ( V_110 ) ;
V_112 -> V_119 = exp -> V_4 . V_20 . V_21 ;
V_112 -> V_120 = V_121 ;
V_112 -> V_122 = 0 ;
if ( F_207 ( V_2 , exp ) < 0 )
goto V_12;
F_62 ( V_2 , V_110 ) ;
return V_2 -> V_77 ;
V_118:
V_12:
F_63 ( V_2 , V_110 ) ;
return - 1 ;
}
static int
F_211 ( unsigned int V_138 , struct V_338 * V_140 )
{
struct V_308 * exp = V_140 -> exp ;
struct V_141 * V_141 = F_212 ( exp ) ;
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
V_113 = V_148 | V_149 ;
V_142 = V_344 ;
} else
return 0 ;
if ( ! V_140 -> V_152 && ! F_79 ( V_141 , V_142 ) )
return 0 ;
V_2 = F_80 ( V_217 , V_153 ) ;
if ( V_2 == NULL )
goto V_154;
type = F_57 ( V_337 , type ) ;
V_110 = F_58 ( V_2 , V_140 -> V_108 , 0 , type , sizeof( * V_112 ) , V_113 ) ;
if ( V_110 == NULL )
goto V_118;
V_112 = F_59 ( V_110 ) ;
V_112 -> V_119 = exp -> V_4 . V_20 . V_21 ;
V_112 -> V_120 = V_121 ;
V_112 -> V_122 = 0 ;
if ( F_207 ( V_2 , exp ) < 0 )
goto V_12;
F_62 ( V_2 , V_110 ) ;
F_81 ( V_2 , V_141 , V_140 -> V_108 , V_142 , V_140 -> V_152 , V_153 ) ;
return 0 ;
V_12:
F_63 ( V_2 , V_110 ) ;
V_118:
F_82 ( V_2 ) ;
V_154:
F_83 ( V_141 , 0 , 0 , - V_161 ) ;
return 0 ;
}
static int F_213 ( struct V_163 * V_164 )
{
if ( V_164 -> args [ 1 ] )
F_201 ( (struct V_308 * ) V_164 -> args [ 1 ] ) ;
return 0 ;
}
static int
F_214 ( struct V_1 * V_2 , struct V_163 * V_164 )
{
struct V_141 * V_141 = F_94 ( V_2 -> V_175 ) ;
struct V_308 * exp , * V_176 ;
struct V_111 * V_112 = F_59 ( V_164 -> V_110 ) ;
V_134 V_18 = V_112 -> V_119 ;
F_8 () ;
V_176 = (struct V_308 * ) V_164 -> args [ 1 ] ;
for (; V_164 -> args [ 0 ] < V_345 ; V_164 -> args [ 0 ] ++ ) {
V_185:
F_215 (exp, &nf_ct_expect_hash[cb->args[0]],
hnode) {
if ( V_18 && exp -> V_4 . V_20 . V_21 != V_18 )
continue;
if ( ! F_105 ( F_78 ( exp -> V_248 ) , V_141 ) )
continue;
if ( V_164 -> args [ 1 ] ) {
if ( exp != V_176 )
continue;
V_164 -> args [ 1 ] = 0 ;
}
if ( F_210 ( V_2 ,
F_106 ( V_164 -> V_2 ) . V_108 ,
V_164 -> V_110 -> V_188 ,
V_343 ,
exp ) < 0 ) {
if ( ! F_216 ( & exp -> V_107 ) )
continue;
V_164 -> args [ 1 ] = ( unsigned long ) exp ;
goto V_43;
}
}
if ( V_164 -> args [ 1 ] ) {
V_164 -> args [ 1 ] = 0 ;
goto V_185;
}
}
V_43:
F_11 () ;
if ( V_176 )
F_201 ( V_176 ) ;
return V_2 -> V_77 ;
}
static int
F_217 ( struct V_1 * V_2 , struct V_163 * V_164 )
{
struct V_308 * exp , * V_176 ;
struct V_111 * V_112 = F_59 ( V_164 -> V_110 ) ;
struct V_28 * V_29 = V_164 -> V_165 ;
struct V_39 * V_40 = F_24 ( V_29 ) ;
V_134 V_18 = V_112 -> V_119 ;
if ( V_164 -> args [ 0 ] )
return 0 ;
F_8 () ;
V_176 = (struct V_308 * ) V_164 -> args [ 1 ] ;
V_185:
F_215 (exp, &help->expectations, lnode) {
if ( V_18 && exp -> V_4 . V_20 . V_21 != V_18 )
continue;
if ( V_164 -> args [ 1 ] ) {
if ( exp != V_176 )
continue;
V_164 -> args [ 1 ] = 0 ;
}
if ( F_210 ( V_2 , F_106 ( V_164 -> V_2 ) . V_108 ,
V_164 -> V_110 -> V_188 ,
V_343 ,
exp ) < 0 ) {
if ( ! F_216 ( & exp -> V_107 ) )
continue;
V_164 -> args [ 1 ] = ( unsigned long ) exp ;
goto V_43;
}
}
if ( V_164 -> args [ 1 ] ) {
V_164 -> args [ 1 ] = 0 ;
goto V_185;
}
V_164 -> args [ 0 ] = 1 ;
V_43:
F_11 () ;
if ( V_176 )
F_201 ( V_176 ) ;
return V_2 -> V_77 ;
}
static int F_218 ( struct V_141 * V_141 , struct V_204 * V_205 ,
struct V_1 * V_2 ,
const struct V_109 * V_110 ,
const struct V_8 * const V_167 [] ,
struct V_206 * V_207 )
{
int V_102 ;
struct V_111 * V_112 = F_59 ( V_110 ) ;
V_134 V_208 = V_112 -> V_119 ;
struct V_3 V_4 ;
struct V_177 * V_178 ;
struct V_28 * V_29 ;
struct V_23 V_24 ;
struct V_213 V_214 = {
. V_215 = F_217 ,
. V_216 = F_213 ,
} ;
V_102 = F_120 ( V_167 , & V_4 , V_323 ,
V_208 , NULL ) ;
if ( V_102 < 0 )
return V_102 ;
V_102 = F_115 ( V_167 [ V_346 ] , & V_24 ) ;
if ( V_102 < 0 )
return V_102 ;
V_178 = F_129 ( V_141 , & V_24 , & V_4 ) ;
if ( ! V_178 )
return - V_209 ;
V_29 = F_102 ( V_178 ) ;
if ( ! F_24 ( V_29 ) ) {
F_85 ( V_29 ) ;
return 0 ;
}
V_214 . V_165 = V_29 ;
V_102 = F_132 ( V_205 , V_2 , V_110 , & V_214 ) ;
F_85 ( V_29 ) ;
return V_102 ;
}
static int F_219 ( struct V_141 * V_141 , struct V_204 * V_205 ,
struct V_1 * V_2 , const struct V_109 * V_110 ,
const struct V_8 * const V_167 [] ,
struct V_206 * V_207 )
{
struct V_3 V_4 ;
struct V_308 * exp ;
struct V_1 * V_210 ;
struct V_111 * V_112 = F_59 ( V_110 ) ;
V_134 V_208 = V_112 -> V_119 ;
struct V_23 V_24 ;
int V_102 ;
if ( V_110 -> V_211 & V_212 ) {
if ( V_167 [ V_323 ] )
return F_218 ( V_141 , V_205 , V_2 , V_110 , V_167 ,
V_207 ) ;
else {
struct V_213 V_214 = {
. V_215 = F_214 ,
. V_216 = F_213 ,
} ;
return F_132 ( V_205 , V_2 , V_110 , & V_214 ) ;
}
}
V_102 = F_115 ( V_167 [ V_346 ] , & V_24 ) ;
if ( V_102 < 0 )
return V_102 ;
if ( V_167 [ V_305 ] )
V_102 = F_120 ( V_167 , & V_4 , V_305 ,
V_208 , NULL ) ;
else if ( V_167 [ V_323 ] )
V_102 = F_120 ( V_167 , & V_4 , V_323 ,
V_208 , NULL ) ;
else
return - V_196 ;
if ( V_102 < 0 )
return V_102 ;
exp = F_220 ( V_141 , & V_24 , & V_4 ) ;
if ( ! exp )
return - V_209 ;
if ( V_167 [ V_331 ] ) {
T_7 V_26 = F_91 ( V_167 [ V_331 ] ) ;
if ( F_90 ( V_26 ) != ( T_2 ) ( unsigned long ) exp ) {
F_201 ( exp ) ;
return - V_209 ;
}
}
V_102 = - V_170 ;
V_210 = F_80 ( V_217 , V_169 ) ;
if ( V_210 == NULL ) {
F_201 ( exp ) ;
goto V_43;
}
F_8 () ;
V_102 = F_210 ( V_210 , F_106 ( V_2 ) . V_108 ,
V_110 -> V_188 , V_343 , exp ) ;
F_11 () ;
F_201 ( exp ) ;
if ( V_102 <= 0 )
goto free;
V_102 = F_133 ( V_205 , V_210 , F_106 ( V_2 ) . V_108 , V_218 ) ;
if ( V_102 < 0 )
goto V_43;
return 0 ;
free:
F_82 ( V_210 ) ;
V_43:
return V_102 == - V_162 ? - V_161 : V_102 ;
}
static bool F_221 ( struct V_308 * exp , void * V_165 )
{
const struct V_39 * V_347 ;
const char * V_46 = V_165 ;
V_347 = F_24 ( exp -> V_248 ) ;
return strcmp ( V_347 -> V_42 -> V_46 , V_46 ) == 0 ;
}
static bool F_222 ( struct V_308 * exp , void * V_165 )
{
return true ;
}
static int F_223 ( struct V_141 * V_141 , struct V_204 * V_205 ,
struct V_1 * V_2 , const struct V_109 * V_110 ,
const struct V_8 * const V_167 [] ,
struct V_206 * V_207 )
{
struct V_308 * exp ;
struct V_3 V_4 ;
struct V_111 * V_112 = F_59 ( V_110 ) ;
V_134 V_208 = V_112 -> V_119 ;
struct V_23 V_24 ;
int V_102 ;
if ( V_167 [ V_305 ] ) {
V_102 = F_115 ( V_167 [ V_346 ] , & V_24 ) ;
if ( V_102 < 0 )
return V_102 ;
V_102 = F_120 ( V_167 , & V_4 , V_305 ,
V_208 , NULL ) ;
if ( V_102 < 0 )
return V_102 ;
exp = F_220 ( V_141 , & V_24 , & V_4 ) ;
if ( ! exp )
return - V_209 ;
if ( V_167 [ V_331 ] ) {
T_7 V_26 = F_91 ( V_167 [ V_331 ] ) ;
if ( F_90 ( V_26 ) != ( T_2 ) ( unsigned long ) exp ) {
F_201 ( exp ) ;
return - V_209 ;
}
}
F_51 ( & V_348 ) ;
if ( F_224 ( & exp -> V_32 ) ) {
F_225 ( exp , F_106 ( V_2 ) . V_108 ,
F_128 ( V_110 ) ) ;
F_201 ( exp ) ;
}
F_52 ( & V_348 ) ;
F_201 ( exp ) ;
} else if ( V_167 [ V_310 ] ) {
char * V_46 = F_122 ( V_167 [ V_310 ] ) ;
F_226 ( V_141 , F_221 , V_46 ,
F_106 ( V_2 ) . V_108 ,
F_128 ( V_110 ) ) ;
} else {
F_226 ( V_141 , F_222 , NULL ,
F_106 ( V_2 ) . V_108 ,
F_128 ( V_110 ) ) ;
}
return 0 ;
}
static int
F_227 ( struct V_308 * V_349 ,
const struct V_8 * const V_167 [] )
{
if ( V_167 [ V_330 ] ) {
if ( ! F_224 ( & V_349 -> V_32 ) )
return - V_252 ;
V_349 -> V_32 . V_317 = V_318 +
F_90 ( F_91 ( V_167 [ V_330 ] ) ) * V_33 ;
F_228 ( & V_349 -> V_32 ) ;
}
return 0 ;
}
static int
F_229 ( const struct V_8 * V_51 ,
struct V_308 * exp ,
V_134 V_208 )
{
#ifdef F_74
struct V_8 * V_190 [ V_350 + 1 ] ;
struct V_3 V_319 = {} ;
int V_102 ;
V_102 = F_111 ( V_190 , V_350 , V_51 ,
V_351 , NULL ) ;
if ( V_102 < 0 )
return V_102 ;
if ( ! V_190 [ V_328 ] || ! V_190 [ V_329 ] )
return - V_196 ;
V_102 = F_120 ( ( const struct V_8 * const * ) V_190 ,
& V_319 , V_329 ,
V_208 , NULL ) ;
if ( V_102 < 0 )
return V_102 ;
exp -> V_324 = V_319 . V_20 . V_208 ;
exp -> V_326 = V_319 . V_20 . V_315 ;
exp -> V_25 = F_90 ( F_91 ( V_190 [ V_328 ] ) ) ;
return 0 ;
#else
return - V_174 ;
#endif
}
static struct V_308 *
F_199 ( const struct V_8 * const V_167 [] , struct V_28 * V_29 ,
struct V_41 * V_42 ,
struct V_3 * V_4 ,
struct V_3 * V_172 )
{
V_135 V_334 = 0 ;
struct V_308 * exp ;
struct V_39 * V_40 ;
int V_102 ;
V_40 = F_24 ( V_29 ) ;
if ( ! V_40 )
return F_89 ( - V_174 ) ;
if ( V_167 [ V_333 ] && V_42 ) {
V_334 = F_90 ( F_91 ( V_167 [ V_333 ] ) ) ;
if ( V_334 > V_42 -> V_352 )
return F_89 ( - V_196 ) ;
}
exp = F_230 ( V_29 ) ;
if ( ! exp )
return F_89 ( - V_170 ) ;
if ( V_167 [ V_332 ] ) {
exp -> V_113 = F_90 ( F_91 ( V_167 [ V_332 ] ) ) ;
exp -> V_113 &= ~ V_353 ;
} else {
exp -> V_113 = 0 ;
}
if ( V_167 [ V_336 ] ) {
const char * V_46 = F_122 ( V_167 [ V_336 ] ) ;
struct V_320 * V_321 ;
V_321 = F_231 ( V_46 ) ;
if ( V_321 == NULL ) {
V_102 = - V_196 ;
goto V_354;
}
exp -> V_335 = V_321 -> V_335 ;
} else
exp -> V_335 = NULL ;
exp -> V_334 = V_334 ;
exp -> V_248 = V_29 ;
exp -> V_42 = V_42 ;
exp -> V_4 = * V_4 ;
exp -> V_172 . V_20 . V_208 = V_172 -> V_20 . V_208 ;
exp -> V_172 . V_20 . V_315 . V_316 = V_172 -> V_20 . V_315 . V_316 ;
if ( V_167 [ V_327 ] ) {
V_102 = F_229 ( V_167 [ V_327 ] ,
exp , F_21 ( V_29 ) ) ;
if ( V_102 < 0 )
goto V_354;
}
return exp ;
V_354:
F_201 ( exp ) ;
return F_89 ( V_102 ) ;
}
static int
F_232 ( struct V_141 * V_141 ,
const struct V_23 * V_24 ,
const struct V_8 * const V_167 [] ,
V_134 V_208 , T_2 V_108 , int V_152 )
{
struct V_3 V_4 , V_172 , F_47 ;
struct V_177 * V_178 = NULL ;
struct V_41 * V_42 = NULL ;
struct V_308 * exp ;
struct V_28 * V_29 ;
int V_102 ;
V_102 = F_120 ( V_167 , & V_4 , V_305 ,
V_208 , NULL ) ;
if ( V_102 < 0 )
return V_102 ;
V_102 = F_120 ( V_167 , & V_172 , V_306 ,
V_208 , NULL ) ;
if ( V_102 < 0 )
return V_102 ;
V_102 = F_120 ( V_167 , & F_47 , V_323 ,
V_208 , NULL ) ;
if ( V_102 < 0 )
return V_102 ;
V_178 = F_129 ( V_141 , V_24 , & F_47 ) ;
if ( ! V_178 )
return - V_209 ;
V_29 = F_102 ( V_178 ) ;
F_8 () ;
if ( V_167 [ V_310 ] ) {
const char * V_247 = F_122 ( V_167 [ V_310 ] ) ;
V_42 = F_156 ( V_247 , V_208 ,
F_22 ( V_29 ) ) ;
if ( V_42 == NULL ) {
F_11 () ;
#ifdef F_144
if ( F_146 ( L_4 , V_247 ) < 0 ) {
V_102 = - V_174 ;
goto V_355;
}
F_8 () ;
V_42 = F_156 ( V_247 , V_208 ,
F_22 ( V_29 ) ) ;
if ( V_42 ) {
V_102 = - V_162 ;
goto V_356;
}
F_11 () ;
#endif
V_102 = - V_174 ;
goto V_355;
}
}
exp = F_199 ( V_167 , V_29 , V_42 , & V_4 , & V_172 ) ;
if ( F_124 ( exp ) ) {
V_102 = F_125 ( exp ) ;
goto V_356;
}
V_102 = F_200 ( exp , V_108 , V_152 ) ;
F_201 ( exp ) ;
V_356:
F_11 () ;
V_355:
F_85 ( V_29 ) ;
return V_102 ;
}
static int F_233 ( struct V_141 * V_141 , struct V_204 * V_205 ,
struct V_1 * V_2 , const struct V_109 * V_110 ,
const struct V_8 * const V_167 [] ,
struct V_206 * V_207 )
{
struct V_3 V_4 ;
struct V_308 * exp ;
struct V_111 * V_112 = F_59 ( V_110 ) ;
V_134 V_208 = V_112 -> V_119 ;
struct V_23 V_24 ;
int V_102 ;
if ( ! V_167 [ V_305 ]
|| ! V_167 [ V_306 ]
|| ! V_167 [ V_323 ] )
return - V_196 ;
V_102 = F_115 ( V_167 [ V_346 ] , & V_24 ) ;
if ( V_102 < 0 )
return V_102 ;
V_102 = F_120 ( V_167 , & V_4 , V_305 ,
V_208 , NULL ) ;
if ( V_102 < 0 )
return V_102 ;
F_51 ( & V_348 ) ;
exp = F_234 ( V_141 , & V_24 , & V_4 ) ;
if ( ! exp ) {
F_52 ( & V_348 ) ;
V_102 = - V_209 ;
if ( V_110 -> V_211 & V_148 ) {
V_102 = F_232 ( V_141 , & V_24 , V_167 , V_208 ,
F_106 ( V_2 ) . V_108 ,
F_128 ( V_110 ) ) ;
}
return V_102 ;
}
V_102 = - V_270 ;
if ( ! ( V_110 -> V_211 & V_149 ) )
V_102 = F_227 ( exp , V_167 ) ;
F_52 ( & V_348 ) ;
return V_102 ;
}
static int
F_235 ( struct V_1 * V_2 , T_2 V_108 , T_2 V_90 , int V_220 ,
const struct V_271 * V_272 )
{
struct V_109 * V_110 ;
struct V_111 * V_112 ;
unsigned int V_113 = V_108 ? V_114 : 0 , V_115 ;
V_115 = F_57 ( V_116 ,
V_357 ) ;
V_110 = F_58 ( V_2 , V_108 , V_90 , V_115 , sizeof( * V_112 ) , V_113 ) ;
if ( V_110 == NULL )
goto V_118;
V_112 = F_59 ( V_110 ) ;
V_112 -> V_119 = V_274 ;
V_112 -> V_120 = V_121 ;
V_112 -> V_122 = F_14 ( V_220 ) ;
if ( F_16 ( V_2 , V_358 , F_17 ( V_272 -> V_359 ) ) ||
F_16 ( V_2 , V_360 , F_17 ( V_272 -> V_361 ) ) ||
F_16 ( V_2 , V_362 , F_17 ( V_272 -> V_363 ) ) )
goto V_12;
F_62 ( V_2 , V_110 ) ;
return V_2 -> V_77 ;
V_12:
V_118:
F_63 ( V_2 , V_110 ) ;
return - 1 ;
}
static int
F_236 ( struct V_1 * V_2 , struct V_163 * V_164 )
{
int V_220 ;
struct V_141 * V_141 = F_94 ( V_2 -> V_175 ) ;
if ( V_164 -> args [ 0 ] == V_223 )
return 0 ;
for ( V_220 = V_164 -> args [ 0 ] ; V_220 < V_223 ; V_220 ++ ) {
const struct V_271 * V_272 ;
if ( ! F_136 ( V_220 ) )
continue;
V_272 = F_137 ( V_141 -> V_29 . V_292 , V_220 ) ;
if ( F_235 ( V_2 , F_106 ( V_164 -> V_2 ) . V_108 ,
V_164 -> V_110 -> V_188 ,
V_220 , V_272 ) < 0 )
break;
}
V_164 -> args [ 0 ] = V_220 ;
return V_2 -> V_77 ;
}
static int F_237 ( struct V_141 * V_141 , struct V_204 * V_205 ,
struct V_1 * V_2 ,
const struct V_109 * V_110 ,
const struct V_8 * const V_167 [] ,
struct V_206 * V_207 )
{
if ( V_110 -> V_211 & V_212 ) {
struct V_213 V_214 = {
. V_215 = F_236 ,
} ;
return F_132 ( V_205 , V_2 , V_110 , & V_214 ) ;
}
return 0 ;
}
static int T_8 F_238 ( struct V_141 * V_141 )
{
#ifdef F_239
int V_7 ;
V_7 = F_240 ( V_141 , & V_364 ) ;
if ( V_7 < 0 ) {
F_241 ( L_5 ) ;
goto V_354;
}
V_7 = F_242 ( V_141 , & V_365 ) ;
if ( V_7 < 0 ) {
F_241 ( L_6 ) ;
goto V_366;
}
#endif
return 0 ;
#ifdef F_239
V_366:
F_243 ( V_141 , & V_364 ) ;
V_354:
return V_7 ;
#endif
}
static void F_244 ( struct V_141 * V_141 )
{
#ifdef F_239
F_245 ( V_141 , & V_365 ) ;
F_243 ( V_141 , & V_364 ) ;
#endif
}
static void T_9 F_246 ( struct V_367 * V_368 )
{
struct V_141 * V_141 ;
F_247 (net, net_exit_list, exit_list)
F_244 ( V_141 ) ;
}
static int T_10 F_248 ( void )
{
int V_7 ;
F_249 ( L_7 , V_120 ) ;
V_7 = F_250 ( & V_369 ) ;
if ( V_7 < 0 ) {
F_241 ( L_8 ) ;
goto V_354;
}
V_7 = F_250 ( & V_370 ) ;
if ( V_7 < 0 ) {
F_241 ( L_9 ) ;
goto V_371;
}
V_7 = F_251 ( & V_372 ) ;
if ( V_7 < 0 ) {
F_241 ( L_10 ) ;
goto V_373;
}
#ifdef F_252
F_155 ( V_374 , & V_375 ) ;
#endif
return 0 ;
V_373:
F_253 ( & V_370 ) ;
V_371:
F_253 ( & V_369 ) ;
V_354:
return V_7 ;
}
static void T_11 F_254 ( void )
{
F_249 ( L_11 ) ;
F_255 ( & V_372 ) ;
F_253 ( & V_370 ) ;
F_253 ( & V_369 ) ;
#ifdef F_252
F_155 ( V_374 , NULL ) ;
#endif
F_256 () ;
}
