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
long V_32 = F_19 ( V_29 ) / V_33 ;
if ( F_16 ( V_2 , V_34 , F_17 ( V_32 ) ) )
goto V_12;
return 0 ;
V_12:
return - 1 ;
}
static int F_20 ( struct V_1 * V_2 , struct V_28 * V_29 )
{
struct V_5 * V_6 ;
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
static int F_49 ( struct V_1 * V_2 ,
const struct V_28 * V_29 )
{
struct V_97 * V_98 = F_50 ( V_29 ) ;
struct V_89 * V_90 ;
if ( ! ( V_29 -> V_31 & V_99 ) || ! V_98 )
return 0 ;
V_90 = & V_98 -> V_90 [ V_64 ] ;
if ( F_48 ( V_2 , V_90 , V_100 ) == - 1 )
return - 1 ;
V_90 = & V_98 -> V_90 [ V_65 ] ;
if ( F_48 ( V_2 , V_90 , V_101 ) == - 1 )
return - 1 ;
return 0 ;
}
static int F_51 ( struct V_1 * V_2 , const struct V_28 * V_29 )
{
if ( F_16 ( V_2 , V_102 , F_17 ( ( unsigned long ) V_29 ) ) )
goto V_12;
return 0 ;
V_12:
return - 1 ;
}
static int F_52 ( struct V_1 * V_2 , const struct V_28 * V_29 )
{
if ( F_16 ( V_2 , V_103 , F_17 ( F_53 ( & V_29 -> V_104 . V_105 ) ) ) )
goto V_12;
return 0 ;
V_12:
return - 1 ;
}
static int
F_54 ( struct V_1 * V_2 , T_2 V_106 , T_2 V_90 , T_2 type ,
struct V_28 * V_29 )
{
const struct V_23 * V_24 ;
struct V_107 * V_108 ;
struct V_109 * V_110 ;
struct V_8 * V_9 ;
unsigned int V_111 = V_106 ? V_112 : 0 , V_113 ;
V_113 = ( V_114 << 8 | V_115 ) ;
V_108 = F_55 ( V_2 , V_106 , V_90 , V_113 , sizeof( * V_110 ) , V_111 ) ;
if ( V_108 == NULL )
goto V_116;
V_110 = F_56 ( V_108 ) ;
V_110 -> V_117 = F_21 ( V_29 ) ;
V_110 -> V_118 = V_119 ;
V_110 -> V_120 = 0 ;
V_24 = F_57 ( V_29 ) ;
V_9 = F_2 ( V_2 , V_121 | V_11 ) ;
if ( ! V_9 )
goto V_12;
if ( F_7 ( V_2 , F_58 ( V_29 , V_64 ) ) < 0 )
goto V_12;
if ( F_12 ( V_2 , V_122 , V_24 ,
V_123 ) < 0 )
goto V_12;
F_5 ( V_2 , V_9 ) ;
V_9 = F_2 ( V_2 , V_124 | V_11 ) ;
if ( ! V_9 )
goto V_12;
if ( F_7 ( V_2 , F_58 ( V_29 , V_65 ) ) < 0 )
goto V_12;
if ( F_12 ( V_2 , V_122 , V_24 ,
V_125 ) < 0 )
goto V_12;
F_5 ( V_2 , V_9 ) ;
if ( F_12 ( V_2 , V_126 , V_24 ,
V_127 ) < 0 )
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
F_51 ( V_2 , V_29 ) < 0 ||
F_52 ( V_2 , V_29 ) < 0 ||
F_46 ( V_2 , V_29 ) < 0 ||
F_49 ( V_2 , V_29 ) < 0 )
goto V_12;
F_59 ( V_2 , V_108 ) ;
return V_2 -> V_77 ;
V_116:
V_12:
F_60 ( V_2 , V_108 ) ;
return - 1 ;
}
static inline T_3 F_61 ( const struct V_28 * V_29 )
{
struct V_17 * V_18 ;
struct V_5 * V_6 ;
T_3 V_77 = 0 ;
F_8 () ;
V_18 = F_9 ( F_21 ( V_29 ) ) ;
V_77 += V_18 -> V_128 ;
V_6 = F_10 ( F_21 ( V_29 ) , F_22 ( V_29 ) ) ;
V_77 += V_6 -> V_128 ;
F_11 () ;
return V_77 ;
}
static inline T_3 F_62 ( const struct V_28 * V_29 )
{
if ( ! F_63 ( V_29 , V_129 ) )
return 0 ;
return 2 * F_42 ( 0 )
+ 2 * F_64 ( sizeof( V_130 ) )
+ 2 * F_64 ( sizeof( V_130 ) )
;
}
static inline int F_65 ( const struct V_28 * V_29 )
{
#ifdef F_66
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
static inline T_3 F_67 ( const struct V_28 * V_29 )
{
#ifdef F_68
if ( ! F_63 ( V_29 , V_131 ) )
return 0 ;
return F_42 ( 0 ) + 2 * F_64 ( sizeof( V_130 ) ) ;
#else
return 0 ;
#endif
}
static T_3 F_69 ( const struct V_28 * V_29 )
{
return F_70 ( sizeof( struct V_109 ) )
+ 3 * F_42 ( 0 )
+ 3 * F_42 ( 0 )
+ 3 * F_42 ( 0 )
+ 3 * F_42 ( sizeof( V_132 ) )
+ F_42 ( sizeof( V_133 ) )
+ F_42 ( sizeof( V_133 ) )
+ F_62 ( V_29 )
+ F_67 ( V_29 )
+ F_42 ( sizeof( V_133 ) )
+ F_42 ( 0 )
+ F_42 ( 0 )
+ F_42 ( V_134 )
+ F_65 ( V_29 )
#ifdef F_71
+ 2 * F_42 ( 0 )
+ 6 * F_42 ( sizeof( V_133 ) )
#endif
#ifdef F_72
+ F_42 ( sizeof( V_133 ) )
#endif
#ifdef F_73
+ F_42 ( sizeof( V_135 ) )
#endif
+ F_61 ( V_29 )
+ F_40 ( V_29 )
;
}
static int
F_74 ( unsigned int V_136 , struct V_137 * V_138 )
{
const struct V_23 * V_24 ;
struct V_139 * V_139 ;
struct V_107 * V_108 ;
struct V_109 * V_110 ;
struct V_8 * V_9 ;
struct V_28 * V_29 = V_138 -> V_29 ;
struct V_1 * V_2 ;
unsigned int type ;
unsigned int V_111 = 0 , V_140 ;
int V_141 ;
if ( F_75 ( V_29 ) )
return 0 ;
if ( V_136 & ( 1 << V_142 ) ) {
type = V_143 ;
V_140 = V_144 ;
} else if ( V_136 & ( ( 1 << V_145 ) | ( 1 << V_146 ) ) ) {
type = V_115 ;
V_111 = V_147 | V_148 ;
V_140 = V_149 ;
} else if ( V_136 ) {
type = V_115 ;
V_140 = V_150 ;
} else
return 0 ;
V_139 = F_76 ( V_29 ) ;
if ( ! V_138 -> V_151 && ! F_77 ( V_139 , V_140 ) )
return 0 ;
V_2 = F_78 ( F_69 ( V_29 ) , V_152 ) ;
if ( V_2 == NULL )
goto V_153;
type |= V_114 << 8 ;
V_108 = F_55 ( V_2 , V_138 -> V_106 , 0 , type , sizeof( * V_110 ) , V_111 ) ;
if ( V_108 == NULL )
goto V_116;
V_110 = F_56 ( V_108 ) ;
V_110 -> V_117 = F_21 ( V_29 ) ;
V_110 -> V_118 = V_119 ;
V_110 -> V_120 = 0 ;
F_8 () ;
V_24 = F_57 ( V_29 ) ;
V_9 = F_2 ( V_2 , V_121 | V_11 ) ;
if ( ! V_9 )
goto V_12;
if ( F_7 ( V_2 , F_58 ( V_29 , V_64 ) ) < 0 )
goto V_12;
if ( F_12 ( V_2 , V_122 , V_24 ,
V_123 ) < 0 )
goto V_12;
F_5 ( V_2 , V_9 ) ;
V_9 = F_2 ( V_2 , V_124 | V_11 ) ;
if ( ! V_9 )
goto V_12;
if ( F_7 ( V_2 , F_58 ( V_29 , V_65 ) ) < 0 )
goto V_12;
if ( F_12 ( V_2 , V_122 , V_24 ,
V_125 ) < 0 )
goto V_12;
F_5 ( V_2 , V_9 ) ;
if ( F_12 ( V_2 , V_126 , V_24 ,
V_127 ) < 0 )
goto V_12;
if ( F_51 ( V_2 , V_29 ) < 0 )
goto V_12;
if ( F_15 ( V_2 , V_29 ) < 0 )
goto V_12;
if ( V_136 & ( 1 << V_142 ) ) {
if ( F_32 ( V_2 , V_29 , type ) < 0 ||
F_34 ( V_2 , V_29 ) < 0 )
goto V_12;
} else {
if ( F_18 ( V_2 , V_29 ) < 0 )
goto V_12;
if ( V_136 & ( 1 << V_154 )
&& F_20 ( V_2 , V_29 ) < 0 )
goto V_12;
if ( ( V_136 & ( 1 << V_155 ) || F_24 ( V_29 ) )
&& F_23 ( V_2 , V_29 ) < 0 )
goto V_12;
#ifdef F_66
if ( ( V_136 & ( 1 << V_156 ) || V_29 -> V_79 )
&& F_37 ( V_2 , V_29 ) < 0 )
goto V_12;
#endif
if ( V_136 & ( 1 << V_157 ) &&
F_43 ( V_2 , V_29 ) < 0 )
goto V_12;
if ( V_136 & ( 1 << V_146 ) &&
F_46 ( V_2 , V_29 ) < 0 )
goto V_12;
if ( V_136 & ( 1 << V_158 ) &&
F_49 ( V_2 , V_29 ) < 0 )
goto V_12;
}
#ifdef F_72
if ( ( V_136 & ( 1 << V_159 ) || V_29 -> V_75 )
&& F_36 ( V_2 , V_29 ) < 0 )
goto V_12;
#endif
F_11 () ;
F_59 ( V_2 , V_108 ) ;
V_141 = F_79 ( V_2 , V_139 , V_138 -> V_106 , V_140 , V_138 -> V_151 ,
V_152 ) ;
if ( V_141 == - V_160 || V_141 == - V_161 )
return - V_160 ;
return 0 ;
V_12:
F_11 () ;
F_60 ( V_2 , V_108 ) ;
V_116:
F_80 ( V_2 ) ;
V_153:
if ( F_81 ( V_139 , 0 , V_140 , - V_160 ) > 0 )
return - V_160 ;
return 0 ;
}
static int F_82 ( struct V_162 * V_163 )
{
if ( V_163 -> args [ 1 ] )
F_83 ( (struct V_28 * ) V_163 -> args [ 1 ] ) ;
F_84 ( V_163 -> V_164 ) ;
return 0 ;
}
static struct V_165 *
F_85 ( const struct V_8 * const V_166 [] )
{
#ifdef F_72
struct V_165 * V_167 ;
V_167 = F_86 ( sizeof( * V_167 ) , V_168 ) ;
if ( V_167 == NULL )
return F_87 ( - V_169 ) ;
V_167 -> V_75 . V_170 = F_88 ( F_89 ( V_166 [ V_74 ] ) ) ;
V_167 -> V_75 . V_171 = F_88 ( F_89 ( V_166 [ V_172 ] ) ) ;
return V_167 ;
#else
return F_87 ( - V_173 ) ;
#endif
}
static int F_90 ( struct V_28 * V_29 , void * V_164 )
{
struct V_165 * V_167 = V_164 ;
if ( V_167 == NULL )
return 1 ;
#ifdef F_72
if ( ( V_29 -> V_75 & V_167 -> V_75 . V_171 ) == V_167 -> V_75 . V_170 )
return 1 ;
#endif
return 0 ;
}
static int
F_91 ( struct V_1 * V_2 , struct V_162 * V_163 )
{
struct V_139 * V_139 = F_92 ( V_2 -> V_174 ) ;
struct V_28 * V_29 , * V_175 ;
struct V_176 * V_177 ;
struct V_178 * V_179 ;
struct V_109 * V_110 = F_56 ( V_163 -> V_108 ) ;
V_132 V_18 = V_110 -> V_117 ;
struct V_28 * V_180 [ 8 ] ;
int V_181 , V_85 ;
T_4 * V_182 ;
V_175 = (struct V_28 * ) V_163 -> args [ 1 ] ;
V_85 = 0 ;
F_93 () ;
for (; V_163 -> args [ 0 ] < V_183 ; V_163 -> args [ 0 ] ++ ) {
V_184:
while ( V_85 ) {
V_85 -- ;
if ( F_94 ( V_180 [ V_85 ] ) )
F_95 ( V_180 [ V_85 ] ) ;
F_83 ( V_180 [ V_85 ] ) ;
}
V_182 = & V_185 [ V_163 -> args [ 0 ] % V_186 ] ;
F_96 ( V_182 ) ;
if ( V_163 -> args [ 0 ] >= V_183 ) {
F_97 ( V_182 ) ;
goto V_43;
}
F_98 (h, n, &nf_conntrack_hash[cb->args[0]],
hnnode) {
if ( F_99 ( V_177 ) != V_64 )
continue;
V_29 = F_100 ( V_177 ) ;
if ( F_101 ( V_29 ) ) {
if ( V_85 < F_45 ( V_180 ) &&
F_102 ( & V_29 -> V_104 . V_105 ) )
V_180 [ V_85 ++ ] = V_29 ;
continue;
}
if ( ! F_103 ( V_139 , F_76 ( V_29 ) ) )
continue;
if ( V_18 && F_21 ( V_29 ) != V_18 )
continue;
if ( V_163 -> args [ 1 ] ) {
if ( V_29 != V_175 )
continue;
V_163 -> args [ 1 ] = 0 ;
}
if ( ! F_90 ( V_29 , V_163 -> V_164 ) )
continue;
F_8 () ;
V_181 =
F_54 ( V_2 , F_104 ( V_163 -> V_2 ) . V_106 ,
V_163 -> V_108 -> V_187 ,
F_105 ( V_163 -> V_108 -> V_188 ) ,
V_29 ) ;
F_11 () ;
if ( V_181 < 0 ) {
F_106 ( & V_29 -> V_104 ) ;
V_163 -> args [ 1 ] = ( unsigned long ) V_29 ;
F_97 ( V_182 ) ;
goto V_43;
}
}
F_97 ( V_182 ) ;
if ( V_163 -> args [ 1 ] ) {
V_163 -> args [ 1 ] = 0 ;
goto V_184;
}
}
V_43:
F_107 () ;
if ( V_175 )
F_83 ( V_175 ) ;
while ( V_85 ) {
V_85 -- ;
if ( F_94 ( V_180 [ V_85 ] ) )
F_95 ( V_180 [ V_85 ] ) ;
F_83 ( V_180 [ V_85 ] ) ;
}
return V_2 -> V_77 ;
}
static int F_108 ( struct V_8 * V_51 ,
struct V_3 * V_4 )
{
struct V_8 * V_189 [ V_190 + 1 ] ;
struct V_17 * V_18 ;
int V_7 = 0 ;
V_7 = F_109 ( V_189 , V_190 , V_51 , NULL ) ;
if ( V_7 < 0 )
return V_7 ;
F_8 () ;
V_18 = F_9 ( V_4 -> V_20 . V_21 ) ;
if ( F_4 ( V_18 -> V_191 ) ) {
V_7 = F_110 ( V_51 , V_190 ,
V_18 -> V_192 ) ;
if ( V_7 == 0 )
V_7 = V_18 -> V_191 ( V_189 , V_4 ) ;
}
F_11 () ;
return V_7 ;
}
static int F_111 ( struct V_8 * V_51 ,
struct V_3 * V_4 )
{
struct V_8 * V_189 [ V_193 + 1 ] ;
struct V_5 * V_6 ;
int V_7 = 0 ;
V_7 = F_109 ( V_189 , V_193 , V_51 , V_194 ) ;
if ( V_7 < 0 )
return V_7 ;
if ( ! V_189 [ V_13 ] )
return - V_195 ;
V_4 -> V_14 . V_15 = F_112 ( V_189 [ V_13 ] ) ;
F_8 () ;
V_6 = F_10 ( V_4 -> V_20 . V_21 , V_4 -> V_14 . V_15 ) ;
if ( F_4 ( V_6 -> V_191 ) ) {
V_7 = F_110 ( V_51 , V_193 ,
V_6 -> V_192 ) ;
if ( V_7 == 0 )
V_7 = V_6 -> V_191 ( V_189 , V_4 ) ;
}
F_11 () ;
return V_7 ;
}
static int
F_113 ( const struct V_8 * V_51 ,
struct V_23 * V_24 )
{
F_114 ( V_24 , V_27 ,
V_127 , 0 ) ;
#ifdef F_73
if ( V_51 )
V_24 -> V_26 = F_115 ( F_116 ( V_51 ) ) ;
#else
if ( V_51 )
return - V_173 ;
#endif
return 0 ;
}
static int
F_117 ( struct V_8 * V_51 , enum V_50 type ,
struct V_23 * V_24 )
{
int V_7 ;
if ( V_24 -> V_26 != V_27 )
return - V_195 ;
V_7 = F_113 ( V_51 , V_24 ) ;
if ( V_7 < 0 )
return V_7 ;
if ( type == V_124 )
V_24 -> V_25 = V_125 ;
else
V_24 -> V_25 = V_123 ;
return 0 ;
}
static int
F_118 ( const struct V_8 * const V_166 [] ,
struct V_3 * V_4 ,
enum V_50 type , V_132 V_21 ,
struct V_23 * V_24 )
{
struct V_8 * V_189 [ V_196 + 1 ] ;
int V_141 ;
memset ( V_4 , 0 , sizeof( * V_4 ) ) ;
V_141 = F_109 ( V_189 , V_196 , V_166 [ type ] , V_197 ) ;
if ( V_141 < 0 )
return V_141 ;
if ( ! V_189 [ V_19 ] )
return - V_195 ;
V_4 -> V_20 . V_21 = V_21 ;
V_141 = F_108 ( V_189 [ V_19 ] , V_4 ) ;
if ( V_141 < 0 )
return V_141 ;
if ( ! V_189 [ V_10 ] )
return - V_195 ;
V_141 = F_111 ( V_189 [ V_10 ] , V_4 ) ;
if ( V_141 < 0 )
return V_141 ;
if ( V_189 [ V_122 ] ) {
if ( ! V_24 )
return - V_195 ;
V_141 = F_117 ( V_189 [ V_122 ] ,
type , V_24 ) ;
if ( V_141 < 0 )
return V_141 ;
}
if ( type == V_124 )
V_4 -> V_14 . V_25 = V_65 ;
else
V_4 -> V_14 . V_25 = V_64 ;
return 0 ;
}
static int F_119 ( const struct V_8 * V_51 , char * * V_198 ,
struct V_8 * * V_199 )
{
int V_141 ;
struct V_8 * V_189 [ V_200 + 1 ] ;
V_141 = F_109 ( V_189 , V_200 , V_51 , V_201 ) ;
if ( V_141 < 0 )
return V_141 ;
if ( ! V_189 [ V_45 ] )
return - V_195 ;
* V_198 = F_120 ( V_189 [ V_45 ] ) ;
if ( V_189 [ V_202 ] )
* V_199 = V_189 [ V_202 ] ;
return 0 ;
}
static int F_121 ( struct V_139 * V_139 ,
const struct V_8 * const V_166 [] ,
T_2 V_106 , int V_151 )
{
struct V_165 * V_167 = NULL ;
if ( V_166 [ V_74 ] && V_166 [ V_172 ] ) {
V_167 = F_85 ( V_166 ) ;
if ( F_122 ( V_167 ) )
return F_123 ( V_167 ) ;
}
F_124 ( V_139 , F_90 , V_167 ,
V_106 , V_151 ) ;
F_84 ( V_167 ) ;
return 0 ;
}
static int F_125 ( struct V_139 * V_139 , struct V_203 * V_204 ,
struct V_1 * V_2 ,
const struct V_107 * V_108 ,
const struct V_8 * const V_166 [] )
{
struct V_176 * V_177 ;
struct V_3 V_4 ;
struct V_28 * V_29 ;
struct V_109 * V_110 = F_56 ( V_108 ) ;
V_132 V_205 = V_110 -> V_117 ;
struct V_23 V_24 ;
int V_141 ;
V_141 = F_113 ( V_166 [ V_126 ] , & V_24 ) ;
if ( V_141 < 0 )
return V_141 ;
if ( V_166 [ V_121 ] )
V_141 = F_118 ( V_166 , & V_4 , V_121 ,
V_205 , & V_24 ) ;
else if ( V_166 [ V_124 ] )
V_141 = F_118 ( V_166 , & V_4 , V_124 ,
V_205 , & V_24 ) ;
else {
return F_121 ( V_139 , V_166 ,
F_104 ( V_2 ) . V_106 ,
F_126 ( V_108 ) ) ;
}
if ( V_141 < 0 )
return V_141 ;
V_177 = F_127 ( V_139 , & V_24 , & V_4 ) ;
if ( ! V_177 )
return - V_206 ;
V_29 = F_100 ( V_177 ) ;
if ( V_166 [ V_102 ] ) {
V_133 V_26 = F_88 ( F_89 ( V_166 [ V_102 ] ) ) ;
if ( V_26 != ( T_2 ) ( unsigned long ) V_29 ) {
F_83 ( V_29 ) ;
return - V_206 ;
}
}
F_128 ( V_29 , F_104 ( V_2 ) . V_106 , F_126 ( V_108 ) ) ;
F_83 ( V_29 ) ;
return 0 ;
}
static int F_129 ( struct V_139 * V_139 , struct V_203 * V_204 ,
struct V_1 * V_2 ,
const struct V_107 * V_108 ,
const struct V_8 * const V_166 [] )
{
struct V_176 * V_177 ;
struct V_3 V_4 ;
struct V_28 * V_29 ;
struct V_1 * V_207 = NULL ;
struct V_109 * V_110 = F_56 ( V_108 ) ;
V_132 V_205 = V_110 -> V_117 ;
struct V_23 V_24 ;
int V_141 ;
if ( V_108 -> V_208 & V_209 ) {
struct V_210 V_211 = {
. V_212 = F_91 ,
. V_213 = F_82 ,
} ;
if ( V_166 [ V_74 ] && V_166 [ V_172 ] ) {
struct V_165 * V_167 ;
V_167 = F_85 ( V_166 ) ;
if ( F_122 ( V_167 ) )
return F_123 ( V_167 ) ;
V_211 . V_164 = V_167 ;
}
return F_130 ( V_204 , V_2 , V_108 , & V_211 ) ;
}
V_141 = F_113 ( V_166 [ V_126 ] , & V_24 ) ;
if ( V_141 < 0 )
return V_141 ;
if ( V_166 [ V_121 ] )
V_141 = F_118 ( V_166 , & V_4 , V_121 ,
V_205 , & V_24 ) ;
else if ( V_166 [ V_124 ] )
V_141 = F_118 ( V_166 , & V_4 , V_124 ,
V_205 , & V_24 ) ;
else
return - V_195 ;
if ( V_141 < 0 )
return V_141 ;
V_177 = F_127 ( V_139 , & V_24 , & V_4 ) ;
if ( ! V_177 )
return - V_206 ;
V_29 = F_100 ( V_177 ) ;
V_141 = - V_169 ;
V_207 = F_78 ( V_214 , V_168 ) ;
if ( V_207 == NULL ) {
F_83 ( V_29 ) ;
return - V_169 ;
}
F_8 () ;
V_141 = F_54 ( V_207 , F_104 ( V_2 ) . V_106 , V_108 -> V_187 ,
F_105 ( V_108 -> V_188 ) , V_29 ) ;
F_11 () ;
F_83 ( V_29 ) ;
if ( V_141 <= 0 )
goto free;
V_141 = F_131 ( V_204 , V_207 , F_104 ( V_2 ) . V_106 , V_215 ) ;
if ( V_141 < 0 )
goto V_43;
return 0 ;
free:
F_80 ( V_207 ) ;
V_43:
return V_141 == - V_161 ? - V_160 : V_141 ;
}
static int F_132 ( struct V_162 * V_163 )
{
if ( V_163 -> args [ 1 ] )
F_83 ( (struct V_28 * ) V_163 -> args [ 1 ] ) ;
return 0 ;
}
static int
F_133 ( struct V_1 * V_2 , struct V_162 * V_163 , bool V_216 )
{
struct V_28 * V_29 , * V_175 ;
struct V_176 * V_177 ;
struct V_178 * V_179 ;
struct V_109 * V_110 = F_56 ( V_163 -> V_108 ) ;
V_132 V_18 = V_110 -> V_117 ;
int V_181 ;
int V_217 ;
struct V_218 * V_219 ;
struct V_139 * V_139 = F_92 ( V_2 -> V_174 ) ;
if ( V_163 -> args [ 2 ] )
return 0 ;
V_175 = (struct V_28 * ) V_163 -> args [ 1 ] ;
for ( V_217 = V_163 -> args [ 0 ] ; V_217 < V_220 ; V_217 ++ ) {
struct V_221 * V_222 ;
if ( ! F_134 ( V_217 ) )
continue;
V_222 = F_135 ( V_139 -> V_29 . V_223 , V_217 ) ;
F_136 ( & V_222 -> V_224 ) ;
V_219 = V_216 ? & V_222 -> V_216 : & V_222 -> V_225 ;
V_184:
F_98 (h, n, list, hnnode) {
V_29 = F_100 ( V_177 ) ;
if ( V_18 && F_21 ( V_29 ) != V_18 )
continue;
if ( V_163 -> args [ 1 ] ) {
if ( V_29 != V_175 )
continue;
V_163 -> args [ 1 ] = 0 ;
}
F_8 () ;
V_181 = F_54 ( V_2 , F_104 ( V_163 -> V_2 ) . V_106 ,
V_163 -> V_108 -> V_187 ,
F_105 ( V_163 -> V_108 -> V_188 ) ,
V_29 ) ;
F_11 () ;
if ( V_181 < 0 ) {
if ( ! F_102 ( & V_29 -> V_104 . V_105 ) )
continue;
V_163 -> args [ 0 ] = V_217 ;
V_163 -> args [ 1 ] = ( unsigned long ) V_29 ;
F_137 ( & V_222 -> V_224 ) ;
goto V_43;
}
}
if ( V_163 -> args [ 1 ] ) {
V_163 -> args [ 1 ] = 0 ;
goto V_184;
}
F_137 ( & V_222 -> V_224 ) ;
}
V_163 -> args [ 2 ] = 1 ;
V_43:
if ( V_175 )
F_83 ( V_175 ) ;
return V_2 -> V_77 ;
}
static int
F_138 ( struct V_1 * V_2 , struct V_162 * V_163 )
{
return F_133 ( V_2 , V_163 , true ) ;
}
static int F_139 ( struct V_139 * V_139 , struct V_203 * V_204 ,
struct V_1 * V_2 ,
const struct V_107 * V_108 ,
const struct V_8 * const V_166 [] )
{
if ( V_108 -> V_208 & V_209 ) {
struct V_210 V_211 = {
. V_212 = F_138 ,
. V_213 = F_132 ,
} ;
return F_130 ( V_204 , V_2 , V_108 , & V_211 ) ;
}
return - V_173 ;
}
static int
F_140 ( struct V_1 * V_2 , struct V_162 * V_163 )
{
return F_133 ( V_2 , V_163 , false ) ;
}
static int F_141 ( struct V_139 * V_139 , struct V_203 * V_204 ,
struct V_1 * V_2 ,
const struct V_107 * V_108 ,
const struct V_8 * const V_166 [] )
{
if ( V_108 -> V_208 & V_209 ) {
struct V_210 V_211 = {
. V_212 = F_140 ,
. V_213 = F_132 ,
} ;
return F_130 ( V_204 , V_2 , V_108 , & V_211 ) ;
}
return - V_173 ;
}
static int
F_142 ( struct V_28 * V_29 ,
enum V_226 V_227 ,
const struct V_8 * V_51 )
{
F_143 (nfnetlink_parse_nat_setup_hook) V_228 ;
int V_141 ;
V_228 = F_25 ( V_229 ) ;
if ( ! V_228 ) {
#ifdef F_144
F_11 () ;
F_145 ( V_114 ) ;
if ( F_146 ( L_1 ) < 0 ) {
F_147 ( V_114 ) ;
F_8 () ;
return - V_173 ;
}
F_147 ( V_114 ) ;
F_8 () ;
if ( V_229 )
return - V_161 ;
#endif
return - V_173 ;
}
V_141 = V_228 ( V_29 , V_227 , V_51 ) ;
if ( V_141 == - V_161 ) {
#ifdef F_144
F_11 () ;
F_145 ( V_114 ) ;
if ( F_146 ( L_2 , F_21 ( V_29 ) ) < 0 ) {
F_147 ( V_114 ) ;
F_8 () ;
return - V_173 ;
}
F_147 ( V_114 ) ;
F_8 () ;
#else
V_141 = - V_173 ;
#endif
}
return V_141 ;
}
static int
F_148 ( struct V_28 * V_29 , const struct V_8 * const V_166 [] )
{
unsigned long V_230 ;
unsigned int V_31 = F_88 ( F_89 ( V_166 [ V_30 ] ) ) ;
V_230 = V_29 -> V_31 ^ V_31 ;
if ( V_230 & ( V_87 | V_231 | V_232 ) )
return - V_233 ;
if ( V_230 & V_234 && ! ( V_31 & V_234 ) )
return - V_233 ;
if ( V_230 & V_235 && ! ( V_31 & V_235 ) )
return - V_233 ;
V_29 -> V_31 |= V_31 & ~ ( V_236 | V_237 ) ;
return 0 ;
}
static int
F_149 ( struct V_28 * V_29 , const struct V_8 * const V_166 [] )
{
#ifdef F_71
int V_7 ;
if ( ! V_166 [ V_238 ] && ! V_166 [ V_239 ] )
return 0 ;
V_7 = F_142 ( V_29 , V_240 ,
V_166 [ V_238 ] ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_142 ( V_29 , V_241 ,
V_166 [ V_239 ] ) ;
return V_7 ;
#else
if ( ! V_166 [ V_238 ] && ! V_166 [ V_239 ] )
return 0 ;
return - V_173 ;
#endif
}
static int F_150 ( struct V_28 * V_29 ,
const struct V_8 * const V_166 [] )
{
struct V_41 * V_42 ;
struct V_39 * V_40 = F_24 ( V_29 ) ;
char * V_242 = NULL ;
struct V_8 * V_199 = NULL ;
int V_141 ;
if ( V_29 -> V_243 )
return - V_233 ;
V_141 = F_119 ( V_166 [ V_44 ] , & V_242 , & V_199 ) ;
if ( V_141 < 0 )
return V_141 ;
if ( ! strcmp ( V_242 , L_3 ) ) {
if ( V_40 && V_40 -> V_42 ) {
F_151 ( V_29 ) ;
F_152 ( V_40 -> V_42 , NULL ) ;
}
return 0 ;
}
V_42 = F_153 ( V_242 , F_21 ( V_29 ) ,
F_22 ( V_29 ) ) ;
if ( V_42 == NULL ) {
#ifdef F_144
F_137 ( & V_244 ) ;
if ( F_146 ( L_4 , V_242 ) < 0 ) {
F_136 ( & V_244 ) ;
return - V_173 ;
}
F_136 ( & V_244 ) ;
V_42 = F_153 ( V_242 , F_21 ( V_29 ) ,
F_22 ( V_29 ) ) ;
if ( V_42 )
return - V_161 ;
#endif
return - V_173 ;
}
if ( V_40 ) {
if ( V_40 -> V_42 == V_42 ) {
if ( V_42 -> V_245 )
V_42 -> V_245 ( V_199 , V_29 ) ;
return 0 ;
} else
return - V_233 ;
}
return - V_173 ;
}
static int F_154 ( struct V_28 * V_29 ,
const struct V_8 * const V_166 [] )
{
V_133 V_32 = F_88 ( F_89 ( V_166 [ V_34 ] ) ) ;
V_29 -> V_32 = V_246 + V_32 * V_33 ;
if ( F_155 ( V_247 , & V_29 -> V_31 ) )
return - V_248 ;
return 0 ;
}
static int F_156 ( struct V_28 * V_29 ,
const struct V_8 * const V_166 [] )
{
const struct V_8 * V_51 = V_166 [ V_37 ] ;
struct V_8 * V_189 [ V_249 + 1 ] ;
struct V_5 * V_6 ;
int V_141 = 0 ;
V_141 = F_109 ( V_189 , V_249 , V_51 , V_250 ) ;
if ( V_141 < 0 )
return V_141 ;
F_8 () ;
V_6 = F_10 ( F_21 ( V_29 ) , F_22 ( V_29 ) ) ;
if ( V_6 -> V_245 )
V_141 = V_6 -> V_245 ( V_189 , V_29 ) ;
F_11 () ;
return V_141 ;
}
static int F_157 ( struct V_89 * V_90 ,
const struct V_8 * const V_51 )
{
int V_141 ;
struct V_8 * V_166 [ V_251 + 1 ] ;
V_141 = F_109 ( V_166 , V_251 , V_51 , V_252 ) ;
if ( V_141 < 0 )
return V_141 ;
if ( ! V_166 [ V_91 ] )
return - V_195 ;
V_90 -> V_92 =
F_88 ( F_89 ( V_166 [ V_91 ] ) ) ;
if ( ! V_166 [ V_93 ] )
return - V_195 ;
V_90 -> V_94 =
F_88 ( F_89 ( V_166 [ V_93 ] ) ) ;
if ( ! V_166 [ V_95 ] )
return - V_195 ;
V_90 -> V_96 =
F_88 ( F_89 ( V_166 [ V_95 ] ) ) ;
return 0 ;
}
static int
F_158 ( struct V_28 * V_29 ,
const struct V_8 * const V_166 [] )
{
struct V_97 * V_98 = F_50 ( V_29 ) ;
int V_7 = 0 ;
if ( ! V_98 )
return 0 ;
if ( V_166 [ V_100 ] ) {
V_7 = F_157 ( & V_98 -> V_90 [ V_64 ] ,
V_166 [ V_100 ] ) ;
if ( V_7 < 0 )
return V_7 ;
V_29 -> V_31 |= V_99 ;
}
if ( V_166 [ V_101 ] ) {
V_7 = F_157 ( & V_98 -> V_90 [ V_65 ] ,
V_166 [ V_101 ] ) ;
if ( V_7 < 0 )
return V_7 ;
V_29 -> V_31 |= V_99 ;
}
return 0 ;
}
static int
F_159 ( struct V_28 * V_29 , const struct V_8 * const V_166 [] )
{
#ifdef F_160
T_3 V_77 = F_161 ( V_166 [ V_86 ] ) ;
const void * V_171 = V_166 [ V_253 ] ;
if ( V_77 & ( sizeof( T_2 ) - 1 ) )
return - V_195 ;
if ( V_171 ) {
if ( F_161 ( V_166 [ V_253 ] ) == 0 ||
F_161 ( V_166 [ V_253 ] ) != V_77 )
return - V_195 ;
V_171 = F_120 ( V_166 [ V_253 ] ) ;
}
V_77 /= sizeof( T_2 ) ;
return F_162 ( V_29 , F_120 ( V_166 [ V_86 ] ) , V_171 , V_77 ) ;
#else
return - V_173 ;
#endif
}
static int
F_163 ( struct V_28 * V_29 ,
const struct V_8 * const V_166 [] )
{
int V_141 ;
if ( V_166 [ V_239 ] || V_166 [ V_238 ] || V_166 [ V_88 ] )
return - V_173 ;
if ( V_166 [ V_44 ] ) {
V_141 = F_150 ( V_29 , V_166 ) ;
if ( V_141 < 0 )
return V_141 ;
}
if ( V_166 [ V_34 ] ) {
V_141 = F_154 ( V_29 , V_166 ) ;
if ( V_141 < 0 )
return V_141 ;
}
if ( V_166 [ V_30 ] ) {
V_141 = F_148 ( V_29 , V_166 ) ;
if ( V_141 < 0 )
return V_141 ;
}
if ( V_166 [ V_37 ] ) {
V_141 = F_156 ( V_29 , V_166 ) ;
if ( V_141 < 0 )
return V_141 ;
}
#if F_164 ( F_72 )
if ( V_166 [ V_74 ] )
V_29 -> V_75 = F_88 ( F_89 ( V_166 [ V_74 ] ) ) ;
#endif
if ( V_166 [ V_100 ] || V_166 [ V_101 ] ) {
V_141 = F_158 ( V_29 , V_166 ) ;
if ( V_141 < 0 )
return V_141 ;
}
if ( V_166 [ V_86 ] ) {
V_141 = F_159 ( V_29 , V_166 ) ;
if ( V_141 < 0 )
return V_141 ;
}
return 0 ;
}
static struct V_28 *
F_165 ( struct V_139 * V_139 ,
const struct V_23 * V_24 ,
const struct V_8 * const V_166 [] ,
struct V_3 * V_254 ,
struct V_3 * V_255 ,
T_5 V_205 )
{
struct V_28 * V_29 ;
int V_141 = - V_195 ;
struct V_41 * V_42 ;
struct V_66 * V_67 ;
V_29 = F_166 ( V_139 , V_24 , V_254 , V_255 , V_152 ) ;
if ( F_122 ( V_29 ) )
return F_87 ( - V_169 ) ;
if ( ! V_166 [ V_34 ] )
goto V_256;
V_29 -> V_32 = V_246 + F_88 ( F_89 ( V_166 [ V_34 ] ) ) * V_33 ;
F_8 () ;
if ( V_166 [ V_44 ] ) {
char * V_242 = NULL ;
struct V_8 * V_199 = NULL ;
V_141 = F_119 ( V_166 [ V_44 ] , & V_242 , & V_199 ) ;
if ( V_141 < 0 )
goto V_257;
V_42 = F_153 ( V_242 , F_21 ( V_29 ) ,
F_22 ( V_29 ) ) ;
if ( V_42 == NULL ) {
F_11 () ;
#ifdef F_144
if ( F_146 ( L_4 , V_242 ) < 0 ) {
V_141 = - V_173 ;
goto V_256;
}
F_8 () ;
V_42 = F_153 ( V_242 ,
F_21 ( V_29 ) ,
F_22 ( V_29 ) ) ;
if ( V_42 ) {
V_141 = - V_161 ;
goto V_257;
}
F_11 () ;
#endif
V_141 = - V_173 ;
goto V_256;
} else {
struct V_39 * V_40 ;
V_40 = F_167 ( V_29 , V_42 , V_152 ) ;
if ( V_40 == NULL ) {
V_141 = - V_169 ;
goto V_257;
}
if ( V_42 -> V_245 )
V_42 -> V_245 ( V_199 , V_29 ) ;
F_152 ( V_40 -> V_42 , V_42 ) ;
}
} else {
V_141 = F_168 ( V_29 , NULL , V_152 ) ;
if ( V_141 < 0 )
goto V_257;
}
V_141 = F_149 ( V_29 , V_166 ) ;
if ( V_141 < 0 )
goto V_257;
F_169 ( V_29 , V_152 ) ;
F_170 ( V_29 , V_152 ) ;
F_171 ( V_29 , 0 , 0 , V_152 ) ;
F_172 ( V_29 ) ;
V_29 -> V_31 |= V_231 ;
if ( V_166 [ V_30 ] ) {
V_141 = F_148 ( V_29 , V_166 ) ;
if ( V_141 < 0 )
goto V_257;
}
if ( V_166 [ V_100 ] || V_166 [ V_101 ] ) {
V_141 = F_158 ( V_29 , V_166 ) ;
if ( V_141 < 0 )
goto V_257;
}
memset ( & V_29 -> V_258 , 0 , sizeof( V_29 -> V_258 ) ) ;
if ( V_166 [ V_37 ] ) {
V_141 = F_156 ( V_29 , V_166 ) ;
if ( V_141 < 0 )
goto V_257;
}
#if F_164 ( F_72 )
if ( V_166 [ V_74 ] )
V_29 -> V_75 = F_88 ( F_89 ( V_166 [ V_74 ] ) ) ;
#endif
if ( V_166 [ V_88 ] ) {
struct V_3 V_243 ;
struct V_176 * V_259 ;
struct V_28 * V_260 ;
V_141 = F_118 ( V_166 , & V_243 , V_88 ,
V_205 , NULL ) ;
if ( V_141 < 0 )
goto V_257;
V_259 = F_127 ( V_139 , V_24 , & V_243 ) ;
if ( V_259 == NULL ) {
V_141 = - V_206 ;
goto V_257;
}
V_260 = F_100 ( V_259 ) ;
F_173 ( V_261 , & V_29 -> V_31 ) ;
V_29 -> V_243 = V_260 ;
}
V_67 = F_35 ( V_29 ) ;
if ( V_67 )
V_67 -> V_70 = F_174 () ;
V_141 = F_175 ( V_29 ) ;
if ( V_141 < 0 )
goto V_257;
F_11 () ;
return V_29 ;
V_257:
F_11 () ;
V_256:
F_176 ( V_29 ) ;
return F_87 ( V_141 ) ;
}
static int F_177 ( struct V_139 * V_139 , struct V_203 * V_204 ,
struct V_1 * V_2 ,
const struct V_107 * V_108 ,
const struct V_8 * const V_166 [] )
{
struct V_3 V_254 , V_255 ;
struct V_176 * V_177 = NULL ;
struct V_109 * V_110 = F_56 ( V_108 ) ;
struct V_28 * V_29 ;
V_132 V_205 = V_110 -> V_117 ;
struct V_23 V_24 ;
int V_141 ;
V_141 = F_113 ( V_166 [ V_126 ] , & V_24 ) ;
if ( V_141 < 0 )
return V_141 ;
if ( V_166 [ V_121 ] ) {
V_141 = F_118 ( V_166 , & V_254 , V_121 ,
V_205 , & V_24 ) ;
if ( V_141 < 0 )
return V_141 ;
}
if ( V_166 [ V_124 ] ) {
V_141 = F_118 ( V_166 , & V_255 , V_124 ,
V_205 , & V_24 ) ;
if ( V_141 < 0 )
return V_141 ;
}
if ( V_166 [ V_121 ] )
V_177 = F_127 ( V_139 , & V_24 , & V_254 ) ;
else if ( V_166 [ V_124 ] )
V_177 = F_127 ( V_139 , & V_24 , & V_255 ) ;
if ( V_177 == NULL ) {
V_141 = - V_206 ;
if ( V_108 -> V_208 & V_147 ) {
enum V_262 V_136 ;
if ( ! V_166 [ V_121 ] || ! V_166 [ V_124 ] )
return - V_195 ;
if ( V_254 . V_14 . V_15 != V_255 . V_14 . V_15 )
return - V_195 ;
V_29 = F_165 ( V_139 , & V_24 , V_166 , & V_254 ,
& V_255 , V_205 ) ;
if ( F_122 ( V_29 ) )
return F_123 ( V_29 ) ;
V_141 = 0 ;
if ( F_155 ( V_261 , & V_29 -> V_31 ) )
V_136 = V_146 ;
else
V_136 = V_145 ;
if ( V_166 [ V_86 ] &&
F_159 ( V_29 , V_166 ) == 0 )
V_136 |= ( 1 << V_157 ) ;
F_178 ( ( 1 << V_263 ) |
( 1 << V_264 ) |
( 1 << V_155 ) |
( 1 << V_154 ) |
( 1 << V_158 ) |
( 1 << V_159 ) | V_136 ,
V_29 , F_104 ( V_2 ) . V_106 ,
F_126 ( V_108 ) ) ;
F_83 ( V_29 ) ;
}
return V_141 ;
}
V_141 = - V_265 ;
V_29 = F_100 ( V_177 ) ;
if ( ! ( V_108 -> V_208 & V_148 ) ) {
F_136 ( & V_244 ) ;
V_141 = F_163 ( V_29 , V_166 ) ;
F_137 ( & V_244 ) ;
if ( V_141 == 0 ) {
F_178 ( ( 1 << V_263 ) |
( 1 << V_264 ) |
( 1 << V_155 ) |
( 1 << V_157 ) |
( 1 << V_154 ) |
( 1 << V_158 ) |
( 1 << V_159 ) ,
V_29 , F_104 ( V_2 ) . V_106 ,
F_126 ( V_108 ) ) ;
}
}
F_83 ( V_29 ) ;
return V_141 ;
}
static int
F_179 ( struct V_1 * V_2 , T_2 V_106 , T_2 V_90 ,
T_6 V_217 , const struct V_266 * V_267 )
{
struct V_107 * V_108 ;
struct V_109 * V_110 ;
unsigned int V_111 = V_106 ? V_112 : 0 , V_113 ;
V_113 = ( V_114 << 8 | V_268 ) ;
V_108 = F_55 ( V_2 , V_106 , V_90 , V_113 , sizeof( * V_110 ) , V_111 ) ;
if ( V_108 == NULL )
goto V_116;
V_110 = F_56 ( V_108 ) ;
V_110 -> V_117 = V_269 ;
V_110 -> V_118 = V_119 ;
V_110 -> V_120 = F_14 ( V_217 ) ;
if ( F_16 ( V_2 , V_270 , F_17 ( V_267 -> V_271 ) ) ||
F_16 ( V_2 , V_272 , F_17 ( V_267 -> V_273 ) ) ||
F_16 ( V_2 , V_274 , F_17 ( V_267 -> V_275 ) ) ||
F_16 ( V_2 , V_276 , F_17 ( V_267 -> V_277 ) ) ||
F_16 ( V_2 , V_278 ,
F_17 ( V_267 -> V_279 ) ) ||
F_16 ( V_2 , V_280 , F_17 ( V_267 -> V_281 ) ) ||
F_16 ( V_2 , V_282 , F_17 ( V_267 -> V_283 ) ) ||
F_16 ( V_2 , V_284 , F_17 ( V_267 -> error ) ) ||
F_16 ( V_2 , V_285 ,
F_17 ( V_267 -> V_286 ) ) )
goto V_12;
F_59 ( V_2 , V_108 ) ;
return V_2 -> V_77 ;
V_12:
V_116:
F_60 ( V_2 , V_108 ) ;
return - 1 ;
}
static int
F_180 ( struct V_1 * V_2 , struct V_162 * V_163 )
{
int V_217 ;
struct V_139 * V_139 = F_92 ( V_2 -> V_174 ) ;
if ( V_163 -> args [ 0 ] == V_220 )
return 0 ;
for ( V_217 = V_163 -> args [ 0 ] ; V_217 < V_220 ; V_217 ++ ) {
const struct V_266 * V_267 ;
if ( ! F_134 ( V_217 ) )
continue;
V_267 = F_135 ( V_139 -> V_29 . V_287 , V_217 ) ;
if ( F_179 ( V_2 ,
F_104 ( V_163 -> V_2 ) . V_106 ,
V_163 -> V_108 -> V_187 ,
V_217 , V_267 ) < 0 )
break;
}
V_163 -> args [ 0 ] = V_217 ;
return V_2 -> V_77 ;
}
static int F_181 ( struct V_139 * V_139 , struct V_203 * V_204 ,
struct V_1 * V_2 ,
const struct V_107 * V_108 ,
const struct V_8 * const V_166 [] )
{
if ( V_108 -> V_208 & V_209 ) {
struct V_210 V_211 = {
. V_212 = F_180 ,
} ;
return F_130 ( V_204 , V_2 , V_108 , & V_211 ) ;
}
return 0 ;
}
static int
F_182 ( struct V_1 * V_2 , T_2 V_106 , T_2 V_90 , T_2 type ,
struct V_139 * V_139 )
{
struct V_107 * V_108 ;
struct V_109 * V_110 ;
unsigned int V_111 = V_106 ? V_112 : 0 , V_113 ;
unsigned int V_288 = F_53 ( & V_139 -> V_29 . V_289 ) ;
V_113 = ( V_114 << 8 | V_290 ) ;
V_108 = F_55 ( V_2 , V_106 , V_90 , V_113 , sizeof( * V_110 ) , V_111 ) ;
if ( V_108 == NULL )
goto V_116;
V_110 = F_56 ( V_108 ) ;
V_110 -> V_117 = V_269 ;
V_110 -> V_118 = V_119 ;
V_110 -> V_120 = 0 ;
if ( F_16 ( V_2 , V_291 , F_17 ( V_288 ) ) )
goto V_12;
F_59 ( V_2 , V_108 ) ;
return V_2 -> V_77 ;
V_12:
V_116:
F_60 ( V_2 , V_108 ) ;
return - 1 ;
}
static int F_183 ( struct V_139 * V_139 , struct V_203 * V_204 ,
struct V_1 * V_2 , const struct V_107 * V_108 ,
const struct V_8 * const V_166 [] )
{
struct V_1 * V_207 ;
int V_141 ;
V_207 = F_78 ( V_214 , V_168 ) ;
if ( V_207 == NULL )
return - V_169 ;
V_141 = F_182 ( V_207 , F_104 ( V_2 ) . V_106 ,
V_108 -> V_187 ,
F_105 ( V_108 -> V_188 ) ,
F_92 ( V_2 -> V_174 ) ) ;
if ( V_141 <= 0 )
goto free;
V_141 = F_131 ( V_204 , V_207 , F_104 ( V_2 ) . V_106 , V_215 ) ;
if ( V_141 < 0 )
goto V_43;
return 0 ;
free:
F_80 ( V_207 ) ;
V_43:
return V_141 == - V_161 ? - V_160 : V_141 ;
}
static T_3
F_184 ( const struct V_28 * V_29 )
{
return 3 * F_42 ( 0 )
+ 3 * F_42 ( 0 )
+ 3 * F_42 ( 0 )
+ 3 * F_42 ( sizeof( V_132 ) )
+ F_42 ( sizeof( V_133 ) )
+ F_42 ( sizeof( V_133 ) )
+ F_42 ( sizeof( V_133 ) )
+ F_42 ( 0 )
+ F_42 ( 0 )
+ F_42 ( V_134 )
+ F_65 ( V_29 )
#ifdef F_71
+ 2 * F_42 ( 0 )
+ 6 * F_42 ( sizeof( V_133 ) )
#endif
#ifdef F_72
+ F_42 ( sizeof( V_133 ) )
#endif
#ifdef F_73
+ F_42 ( sizeof( V_135 ) )
#endif
+ F_61 ( V_29 )
;
}
static struct V_28 * F_185 ( const struct V_1 * V_2 ,
enum V_292 * V_293 )
{
struct V_28 * V_29 ;
V_29 = F_186 ( V_2 , V_293 ) ;
if ( V_29 && F_75 ( V_29 ) )
V_29 = NULL ;
return V_29 ;
}
static int F_187 ( struct V_1 * V_2 , struct V_28 * V_29 )
{
const struct V_23 * V_24 ;
struct V_8 * V_9 ;
F_8 () ;
V_24 = F_57 ( V_29 ) ;
V_9 = F_2 ( V_2 , V_121 | V_11 ) ;
if ( ! V_9 )
goto V_12;
if ( F_7 ( V_2 , F_58 ( V_29 , V_64 ) ) < 0 )
goto V_12;
if ( F_12 ( V_2 , V_122 , V_24 ,
V_123 ) < 0 )
goto V_12;
F_5 ( V_2 , V_9 ) ;
V_9 = F_2 ( V_2 , V_124 | V_11 ) ;
if ( ! V_9 )
goto V_12;
if ( F_7 ( V_2 , F_58 ( V_29 , V_65 ) ) < 0 )
goto V_12;
if ( F_12 ( V_2 , V_122 , V_24 ,
V_125 ) < 0 )
goto V_12;
F_5 ( V_2 , V_9 ) ;
if ( F_12 ( V_2 , V_126 , V_24 ,
V_127 ) < 0 )
goto V_12;
if ( F_51 ( V_2 , V_29 ) < 0 )
goto V_12;
if ( F_15 ( V_2 , V_29 ) < 0 )
goto V_12;
if ( F_18 ( V_2 , V_29 ) < 0 )
goto V_12;
if ( F_20 ( V_2 , V_29 ) < 0 )
goto V_12;
if ( F_23 ( V_2 , V_29 ) < 0 )
goto V_12;
#ifdef F_66
if ( V_29 -> V_79 && F_37 ( V_2 , V_29 ) < 0 )
goto V_12;
#endif
if ( V_29 -> V_243 && F_46 ( V_2 , V_29 ) < 0 )
goto V_12;
if ( ( V_29 -> V_31 & V_99 ) &&
F_49 ( V_2 , V_29 ) < 0 )
goto V_12;
#ifdef F_72
if ( V_29 -> V_75 && F_36 ( V_2 , V_29 ) < 0 )
goto V_12;
#endif
if ( F_43 ( V_2 , V_29 ) < 0 )
goto V_12;
F_11 () ;
return 0 ;
V_12:
F_11 () ;
return - V_294 ;
}
static int
F_188 ( struct V_1 * V_2 , struct V_28 * V_29 ,
enum V_292 V_293 ,
V_135 V_295 , V_135 V_296 )
{
struct V_8 * V_9 ;
V_9 = F_2 ( V_2 , V_295 | V_11 ) ;
if ( ! V_9 )
goto V_12;
if ( F_187 ( V_2 , V_29 ) < 0 )
goto V_12;
F_5 ( V_2 , V_9 ) ;
if ( F_16 ( V_2 , V_296 , F_17 ( V_293 ) ) )
goto V_12;
return 0 ;
V_12:
return - V_294 ;
}
static int
F_189 ( const struct V_8 * V_166 [] , struct V_28 * V_29 )
{
int V_141 ;
if ( V_166 [ V_34 ] ) {
V_141 = F_154 ( V_29 , V_166 ) ;
if ( V_141 < 0 )
return V_141 ;
}
if ( V_166 [ V_30 ] ) {
V_141 = F_148 ( V_29 , V_166 ) ;
if ( V_141 < 0 )
return V_141 ;
}
if ( V_166 [ V_44 ] ) {
V_141 = F_150 ( V_29 , V_166 ) ;
if ( V_141 < 0 )
return V_141 ;
}
if ( V_166 [ V_86 ] ) {
V_141 = F_159 ( V_29 , V_166 ) ;
if ( V_141 < 0 )
return V_141 ;
}
#if F_164 ( F_72 )
if ( V_166 [ V_74 ] ) {
T_2 V_171 = 0 , V_75 , V_297 ;
if ( V_166 [ V_172 ] )
V_171 = ~ F_88 ( F_89 ( V_166 [ V_172 ] ) ) ;
V_75 = F_88 ( F_89 ( V_166 [ V_74 ] ) ) ;
V_297 = ( V_29 -> V_75 & V_171 ) ^ V_75 ;
if ( V_297 != V_29 -> V_75 )
V_29 -> V_75 = V_297 ;
}
#endif
return 0 ;
}
static int
F_190 ( const struct V_8 * V_51 , struct V_28 * V_29 )
{
struct V_8 * V_166 [ V_298 + 1 ] ;
int V_7 ;
V_7 = F_109 ( V_166 , V_298 , V_51 , V_299 ) ;
if ( V_7 < 0 )
return V_7 ;
F_136 ( & V_244 ) ;
V_7 = F_189 ( ( const struct V_8 * * ) V_166 , V_29 ) ;
F_137 ( & V_244 ) ;
return V_7 ;
}
static int F_191 ( const struct V_8 * const * V_166 ,
const struct V_28 * V_29 ,
struct V_3 * V_4 ,
struct V_3 * V_171 )
{
int V_141 ;
V_141 = F_118 ( V_166 , V_4 , V_300 ,
F_21 ( V_29 ) , NULL ) ;
if ( V_141 < 0 )
return V_141 ;
return F_118 ( V_166 , V_171 , V_301 ,
F_21 ( V_29 ) , NULL ) ;
}
static int
F_192 ( const struct V_8 * V_51 , struct V_28 * V_29 ,
T_2 V_106 , T_2 V_151 )
{
struct V_8 * V_166 [ V_302 + 1 ] ;
struct V_3 V_4 , V_171 ;
struct V_41 * V_42 = NULL ;
struct V_303 * exp ;
int V_141 ;
V_141 = F_109 ( V_166 , V_302 , V_51 , V_304 ) ;
if ( V_141 < 0 )
return V_141 ;
V_141 = F_191 ( ( const struct V_8 * const * ) V_166 ,
V_29 , & V_4 , & V_171 ) ;
if ( V_141 < 0 )
return V_141 ;
if ( V_166 [ V_305 ] ) {
const char * V_242 = F_120 ( V_166 [ V_305 ] ) ;
V_42 = F_153 ( V_242 , F_21 ( V_29 ) ,
F_22 ( V_29 ) ) ;
if ( V_42 == NULL )
return - V_173 ;
}
exp = F_193 ( ( const struct V_8 * const * ) V_166 , V_29 ,
V_42 , & V_4 , & V_171 ) ;
if ( F_122 ( exp ) )
return F_123 ( exp ) ;
V_141 = F_194 ( exp , V_106 , V_151 ) ;
F_195 ( exp ) ;
return V_141 ;
}
static void F_196 ( struct V_1 * V_2 , struct V_28 * V_29 ,
enum V_292 V_293 , int V_306 )
{
if ( ! ( V_29 -> V_31 & V_237 ) )
return;
F_197 ( V_2 , V_29 , V_293 , V_306 ) ;
}
static int F_198 ( struct V_1 * V_2 ,
const struct V_3 * V_4 ,
enum V_307 type )
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
static int F_199 ( struct V_1 * V_2 ,
const struct V_3 * V_4 ,
const struct V_308 * V_171 )
{
int V_7 ;
struct V_17 * V_18 ;
struct V_5 * V_6 ;
struct V_3 V_309 ;
struct V_8 * V_9 ;
memset ( & V_309 , 0xFF , sizeof( V_309 ) ) ;
memcpy ( & V_309 . V_20 . V_205 , & V_171 -> V_20 . V_205 , sizeof( V_309 . V_20 . V_205 ) ) ;
V_309 . V_20 . V_310 . V_311 = V_171 -> V_20 . V_310 . V_311 ;
V_309 . V_14 . V_15 = V_4 -> V_14 . V_15 ;
V_9 = F_2 ( V_2 , V_301 | V_11 ) ;
if ( ! V_9 )
goto V_12;
F_8 () ;
V_18 = F_9 ( V_4 -> V_20 . V_21 ) ;
V_7 = F_6 ( V_2 , & V_309 , V_18 ) ;
if ( V_7 >= 0 ) {
V_6 = F_10 ( V_4 -> V_20 . V_21 ,
V_4 -> V_14 . V_15 ) ;
V_7 = F_1 ( V_2 , & V_309 , V_6 ) ;
}
F_11 () ;
if ( F_200 ( V_7 < 0 ) )
goto V_12;
F_5 ( V_2 , V_9 ) ;
return 0 ;
V_12:
return - 1 ;
}
static int
F_201 ( struct V_1 * V_2 ,
const struct V_303 * exp )
{
struct V_28 * V_243 = exp -> V_243 ;
long V_32 = ( ( long ) exp -> V_32 . V_312 - ( long ) V_313 ) / V_33 ;
struct V_39 * V_40 ;
#ifdef F_71
struct V_8 * V_9 ;
struct V_3 V_314 = {} ;
#endif
struct V_315 * V_316 ;
if ( V_32 < 0 )
V_32 = 0 ;
if ( F_198 ( V_2 , & exp -> V_4 , V_300 ) < 0 )
goto V_12;
if ( F_199 ( V_2 , & exp -> V_4 , & exp -> V_171 ) < 0 )
goto V_12;
if ( F_198 ( V_2 ,
& V_243 -> V_317 [ V_64 ] . V_4 ,
V_318 ) < 0 )
goto V_12;
#ifdef F_71
if ( ! F_202 ( & exp -> V_319 , & V_320 ) ||
exp -> V_321 . V_311 ) {
V_9 = F_2 ( V_2 , V_322 | V_11 ) ;
if ( ! V_9 )
goto V_12;
if ( F_16 ( V_2 , V_323 , F_17 ( exp -> V_25 ) ) )
goto V_12;
V_314 . V_20 . V_21 = F_21 ( V_243 ) ;
V_314 . V_20 . V_205 = exp -> V_319 ;
V_314 . V_14 . V_15 = F_22 ( V_243 ) ;
V_314 . V_20 . V_310 = exp -> V_321 ;
if ( F_198 ( V_2 , & V_314 ,
V_324 ) < 0 )
goto V_12;
F_5 ( V_2 , V_9 ) ;
}
#endif
if ( F_16 ( V_2 , V_325 , F_17 ( V_32 ) ) ||
F_16 ( V_2 , V_326 , F_17 ( ( unsigned long ) exp ) ) ||
F_16 ( V_2 , V_327 , F_17 ( exp -> V_111 ) ) ||
F_16 ( V_2 , V_328 , F_17 ( exp -> V_329 ) ) )
goto V_12;
V_40 = F_24 ( V_243 ) ;
if ( V_40 ) {
struct V_41 * V_42 ;
V_42 = F_25 ( V_40 -> V_42 ) ;
if ( V_42 &&
F_26 ( V_2 , V_305 , V_42 -> V_46 ) )
goto V_12;
}
V_316 = F_203 ( exp -> V_330 ) ;
if ( V_316 != NULL &&
F_26 ( V_2 , V_331 , V_316 -> V_46 ) )
goto V_12;
return 0 ;
V_12:
return - 1 ;
}
static int
F_204 ( struct V_1 * V_2 , T_2 V_106 , T_2 V_90 ,
int V_113 , const struct V_303 * exp )
{
struct V_107 * V_108 ;
struct V_109 * V_110 ;
unsigned int V_111 = V_106 ? V_112 : 0 ;
V_113 |= V_332 << 8 ;
V_108 = F_55 ( V_2 , V_106 , V_90 , V_113 , sizeof( * V_110 ) , V_111 ) ;
if ( V_108 == NULL )
goto V_116;
V_110 = F_56 ( V_108 ) ;
V_110 -> V_117 = exp -> V_4 . V_20 . V_21 ;
V_110 -> V_118 = V_119 ;
V_110 -> V_120 = 0 ;
if ( F_201 ( V_2 , exp ) < 0 )
goto V_12;
F_59 ( V_2 , V_108 ) ;
return V_2 -> V_77 ;
V_116:
V_12:
F_60 ( V_2 , V_108 ) ;
return - 1 ;
}
static int
F_205 ( unsigned int V_136 , struct V_333 * V_138 )
{
struct V_303 * exp = V_138 -> exp ;
struct V_139 * V_139 = F_206 ( exp ) ;
struct V_107 * V_108 ;
struct V_109 * V_110 ;
struct V_1 * V_2 ;
unsigned int type , V_140 ;
int V_111 = 0 ;
if ( V_136 & ( 1 << V_334 ) ) {
type = V_335 ;
V_140 = V_336 ;
} else if ( V_136 & ( 1 << V_337 ) ) {
type = V_338 ;
V_111 = V_147 | V_148 ;
V_140 = V_339 ;
} else
return 0 ;
if ( ! V_138 -> V_151 && ! F_77 ( V_139 , V_140 ) )
return 0 ;
V_2 = F_78 ( V_214 , V_152 ) ;
if ( V_2 == NULL )
goto V_153;
type |= V_332 << 8 ;
V_108 = F_55 ( V_2 , V_138 -> V_106 , 0 , type , sizeof( * V_110 ) , V_111 ) ;
if ( V_108 == NULL )
goto V_116;
V_110 = F_56 ( V_108 ) ;
V_110 -> V_117 = exp -> V_4 . V_20 . V_21 ;
V_110 -> V_118 = V_119 ;
V_110 -> V_120 = 0 ;
F_8 () ;
if ( F_201 ( V_2 , exp ) < 0 )
goto V_12;
F_11 () ;
F_59 ( V_2 , V_108 ) ;
F_79 ( V_2 , V_139 , V_138 -> V_106 , V_140 , V_138 -> V_151 , V_152 ) ;
return 0 ;
V_12:
F_11 () ;
F_60 ( V_2 , V_108 ) ;
V_116:
F_80 ( V_2 ) ;
V_153:
F_81 ( V_139 , 0 , 0 , - V_160 ) ;
return 0 ;
}
static int F_207 ( struct V_162 * V_163 )
{
if ( V_163 -> args [ 1 ] )
F_195 ( (struct V_303 * ) V_163 -> args [ 1 ] ) ;
return 0 ;
}
static int
F_208 ( struct V_1 * V_2 , struct V_162 * V_163 )
{
struct V_139 * V_139 = F_92 ( V_2 -> V_174 ) ;
struct V_303 * exp , * V_175 ;
struct V_109 * V_110 = F_56 ( V_163 -> V_108 ) ;
V_132 V_18 = V_110 -> V_117 ;
F_8 () ;
V_175 = (struct V_303 * ) V_163 -> args [ 1 ] ;
for (; V_163 -> args [ 0 ] < V_340 ; V_163 -> args [ 0 ] ++ ) {
V_184:
F_209 (exp, &nf_ct_expect_hash[cb->args[0]],
hnode) {
if ( V_18 && exp -> V_4 . V_20 . V_21 != V_18 )
continue;
if ( ! F_103 ( F_76 ( exp -> V_243 ) , V_139 ) )
continue;
if ( V_163 -> args [ 1 ] ) {
if ( exp != V_175 )
continue;
V_163 -> args [ 1 ] = 0 ;
}
if ( F_204 ( V_2 ,
F_104 ( V_163 -> V_2 ) . V_106 ,
V_163 -> V_108 -> V_187 ,
V_338 ,
exp ) < 0 ) {
if ( ! F_102 ( & exp -> V_105 ) )
continue;
V_163 -> args [ 1 ] = ( unsigned long ) exp ;
goto V_43;
}
}
if ( V_163 -> args [ 1 ] ) {
V_163 -> args [ 1 ] = 0 ;
goto V_184;
}
}
V_43:
F_11 () ;
if ( V_175 )
F_195 ( V_175 ) ;
return V_2 -> V_77 ;
}
static int
F_210 ( struct V_1 * V_2 , struct V_162 * V_163 )
{
struct V_303 * exp , * V_175 ;
struct V_109 * V_110 = F_56 ( V_163 -> V_108 ) ;
struct V_28 * V_29 = V_163 -> V_164 ;
struct V_39 * V_40 = F_24 ( V_29 ) ;
V_132 V_18 = V_110 -> V_117 ;
if ( V_163 -> args [ 0 ] )
return 0 ;
F_8 () ;
V_175 = (struct V_303 * ) V_163 -> args [ 1 ] ;
V_184:
F_209 (exp, &help->expectations, lnode) {
if ( V_18 && exp -> V_4 . V_20 . V_21 != V_18 )
continue;
if ( V_163 -> args [ 1 ] ) {
if ( exp != V_175 )
continue;
V_163 -> args [ 1 ] = 0 ;
}
if ( F_204 ( V_2 , F_104 ( V_163 -> V_2 ) . V_106 ,
V_163 -> V_108 -> V_187 ,
V_338 ,
exp ) < 0 ) {
if ( ! F_102 ( & exp -> V_105 ) )
continue;
V_163 -> args [ 1 ] = ( unsigned long ) exp ;
goto V_43;
}
}
if ( V_163 -> args [ 1 ] ) {
V_163 -> args [ 1 ] = 0 ;
goto V_184;
}
V_163 -> args [ 0 ] = 1 ;
V_43:
F_11 () ;
if ( V_175 )
F_195 ( V_175 ) ;
return V_2 -> V_77 ;
}
static int F_211 ( struct V_139 * V_139 , struct V_203 * V_204 ,
struct V_1 * V_2 ,
const struct V_107 * V_108 ,
const struct V_8 * const V_166 [] )
{
int V_141 ;
struct V_109 * V_110 = F_56 ( V_108 ) ;
V_132 V_205 = V_110 -> V_117 ;
struct V_3 V_4 ;
struct V_176 * V_177 ;
struct V_28 * V_29 ;
struct V_23 V_24 ;
struct V_210 V_211 = {
. V_212 = F_210 ,
. V_213 = F_207 ,
} ;
V_141 = F_118 ( V_166 , & V_4 , V_318 ,
V_205 , NULL ) ;
if ( V_141 < 0 )
return V_141 ;
V_141 = F_113 ( V_166 [ V_341 ] , & V_24 ) ;
if ( V_141 < 0 )
return V_141 ;
V_177 = F_127 ( V_139 , & V_24 , & V_4 ) ;
if ( ! V_177 )
return - V_206 ;
V_29 = F_100 ( V_177 ) ;
V_211 . V_164 = V_29 ;
V_141 = F_130 ( V_204 , V_2 , V_108 , & V_211 ) ;
F_83 ( V_29 ) ;
return V_141 ;
}
static int F_212 ( struct V_139 * V_139 , struct V_203 * V_204 ,
struct V_1 * V_2 , const struct V_107 * V_108 ,
const struct V_8 * const V_166 [] )
{
struct V_3 V_4 ;
struct V_303 * exp ;
struct V_1 * V_207 ;
struct V_109 * V_110 = F_56 ( V_108 ) ;
V_132 V_205 = V_110 -> V_117 ;
struct V_23 V_24 ;
int V_141 ;
if ( V_108 -> V_208 & V_209 ) {
if ( V_166 [ V_318 ] )
return F_211 ( V_139 , V_204 , V_2 , V_108 , V_166 ) ;
else {
struct V_210 V_211 = {
. V_212 = F_208 ,
. V_213 = F_207 ,
} ;
return F_130 ( V_204 , V_2 , V_108 , & V_211 ) ;
}
}
V_141 = F_113 ( V_166 [ V_341 ] , & V_24 ) ;
if ( V_141 < 0 )
return V_141 ;
if ( V_166 [ V_300 ] )
V_141 = F_118 ( V_166 , & V_4 , V_300 ,
V_205 , NULL ) ;
else if ( V_166 [ V_318 ] )
V_141 = F_118 ( V_166 , & V_4 , V_318 ,
V_205 , NULL ) ;
else
return - V_195 ;
if ( V_141 < 0 )
return V_141 ;
exp = F_213 ( V_139 , & V_24 , & V_4 ) ;
if ( ! exp )
return - V_206 ;
if ( V_166 [ V_326 ] ) {
T_7 V_26 = F_89 ( V_166 [ V_326 ] ) ;
if ( F_88 ( V_26 ) != ( T_2 ) ( unsigned long ) exp ) {
F_195 ( exp ) ;
return - V_206 ;
}
}
V_141 = - V_169 ;
V_207 = F_78 ( V_214 , V_168 ) ;
if ( V_207 == NULL ) {
F_195 ( exp ) ;
goto V_43;
}
F_8 () ;
V_141 = F_204 ( V_207 , F_104 ( V_2 ) . V_106 ,
V_108 -> V_187 , V_338 , exp ) ;
F_11 () ;
F_195 ( exp ) ;
if ( V_141 <= 0 )
goto free;
V_141 = F_131 ( V_204 , V_207 , F_104 ( V_2 ) . V_106 , V_215 ) ;
if ( V_141 < 0 )
goto V_43;
return 0 ;
free:
F_80 ( V_207 ) ;
V_43:
return V_141 == - V_161 ? - V_160 : V_141 ;
}
static int F_214 ( struct V_139 * V_139 , struct V_203 * V_204 ,
struct V_1 * V_2 , const struct V_107 * V_108 ,
const struct V_8 * const V_166 [] )
{
struct V_303 * exp ;
struct V_3 V_4 ;
struct V_109 * V_110 = F_56 ( V_108 ) ;
struct V_342 * V_343 ;
V_132 V_205 = V_110 -> V_117 ;
struct V_23 V_24 ;
unsigned int V_85 ;
int V_141 ;
if ( V_166 [ V_300 ] ) {
V_141 = F_113 ( V_166 [ V_341 ] , & V_24 ) ;
if ( V_141 < 0 )
return V_141 ;
V_141 = F_118 ( V_166 , & V_4 , V_300 ,
V_205 , NULL ) ;
if ( V_141 < 0 )
return V_141 ;
exp = F_213 ( V_139 , & V_24 , & V_4 ) ;
if ( ! exp )
return - V_206 ;
if ( V_166 [ V_326 ] ) {
T_7 V_26 = F_89 ( V_166 [ V_326 ] ) ;
if ( F_88 ( V_26 ) != ( T_2 ) ( unsigned long ) exp ) {
F_195 ( exp ) ;
return - V_206 ;
}
}
F_136 ( & V_244 ) ;
if ( F_215 ( & exp -> V_32 ) ) {
F_216 ( exp , F_104 ( V_2 ) . V_106 ,
F_126 ( V_108 ) ) ;
F_195 ( exp ) ;
}
F_137 ( & V_244 ) ;
F_195 ( exp ) ;
} else if ( V_166 [ V_305 ] ) {
char * V_46 = F_120 ( V_166 [ V_305 ] ) ;
struct V_39 * V_344 ;
F_136 ( & V_244 ) ;
for ( V_85 = 0 ; V_85 < V_340 ; V_85 ++ ) {
F_217 (exp, next,
&nf_ct_expect_hash[i],
hnode) {
if ( ! F_103 ( F_206 ( exp ) , V_139 ) )
continue;
V_344 = F_24 ( exp -> V_243 ) ;
if ( ! strcmp ( V_344 -> V_42 -> V_46 , V_46 ) &&
F_215 ( & exp -> V_32 ) ) {
F_216 ( exp ,
F_104 ( V_2 ) . V_106 ,
F_126 ( V_108 ) ) ;
F_195 ( exp ) ;
}
}
}
F_137 ( & V_244 ) ;
} else {
F_136 ( & V_244 ) ;
for ( V_85 = 0 ; V_85 < V_340 ; V_85 ++ ) {
F_217 (exp, next,
&nf_ct_expect_hash[i],
hnode) {
if ( ! F_103 ( F_206 ( exp ) , V_139 ) )
continue;
if ( F_215 ( & exp -> V_32 ) ) {
F_216 ( exp ,
F_104 ( V_2 ) . V_106 ,
F_126 ( V_108 ) ) ;
F_195 ( exp ) ;
}
}
}
F_137 ( & V_244 ) ;
}
return 0 ;
}
static int
F_218 ( struct V_303 * V_345 ,
const struct V_8 * const V_166 [] )
{
if ( V_166 [ V_325 ] ) {
if ( ! F_215 ( & V_345 -> V_32 ) )
return - V_248 ;
V_345 -> V_32 . V_312 = V_313 +
F_88 ( F_89 ( V_166 [ V_325 ] ) ) * V_33 ;
F_219 ( & V_345 -> V_32 ) ;
}
return 0 ;
}
static int
F_220 ( const struct V_8 * V_51 ,
struct V_303 * exp ,
V_132 V_205 )
{
#ifdef F_71
struct V_8 * V_189 [ V_346 + 1 ] ;
struct V_3 V_314 = {} ;
int V_141 ;
V_141 = F_109 ( V_189 , V_346 , V_51 , V_347 ) ;
if ( V_141 < 0 )
return V_141 ;
if ( ! V_189 [ V_323 ] || ! V_189 [ V_324 ] )
return - V_195 ;
V_141 = F_118 ( ( const struct V_8 * const * ) V_189 ,
& V_314 , V_324 ,
V_205 , NULL ) ;
if ( V_141 < 0 )
return V_141 ;
exp -> V_319 = V_314 . V_20 . V_205 ;
exp -> V_321 = V_314 . V_20 . V_310 ;
exp -> V_25 = F_88 ( F_89 ( V_189 [ V_323 ] ) ) ;
return 0 ;
#else
return - V_173 ;
#endif
}
static struct V_303 *
F_193 ( const struct V_8 * const V_166 [] , struct V_28 * V_29 ,
struct V_41 * V_42 ,
struct V_3 * V_4 ,
struct V_3 * V_171 )
{
V_133 V_329 = 0 ;
struct V_303 * exp ;
struct V_39 * V_40 ;
int V_141 ;
if ( V_166 [ V_328 ] && V_42 ) {
V_329 = F_88 ( F_89 ( V_166 [ V_328 ] ) ) ;
if ( V_329 > V_42 -> V_348 )
return F_87 ( - V_195 ) ;
}
exp = F_221 ( V_29 ) ;
if ( ! exp )
return F_87 ( - V_169 ) ;
V_40 = F_24 ( V_29 ) ;
if ( ! V_40 ) {
if ( ! V_166 [ V_325 ] ) {
V_141 = - V_195 ;
goto V_349;
}
exp -> V_32 . V_312 =
V_313 + F_88 ( F_89 ( V_166 [ V_325 ] ) ) * V_33 ;
exp -> V_111 = V_350 ;
if ( V_166 [ V_327 ] ) {
exp -> V_111 |=
F_88 ( F_89 ( V_166 [ V_327 ] ) ) ;
}
} else {
if ( V_166 [ V_327 ] ) {
exp -> V_111 = F_88 ( F_89 ( V_166 [ V_327 ] ) ) ;
exp -> V_111 &= ~ V_350 ;
} else
exp -> V_111 = 0 ;
}
if ( V_166 [ V_331 ] ) {
const char * V_46 = F_120 ( V_166 [ V_331 ] ) ;
struct V_315 * V_316 ;
V_316 = F_222 ( V_46 ) ;
if ( V_316 == NULL ) {
V_141 = - V_195 ;
goto V_349;
}
exp -> V_330 = V_316 -> V_330 ;
} else
exp -> V_330 = NULL ;
exp -> V_329 = V_329 ;
exp -> V_243 = V_29 ;
exp -> V_42 = V_42 ;
exp -> V_4 = * V_4 ;
exp -> V_171 . V_20 . V_205 = V_171 -> V_20 . V_205 ;
exp -> V_171 . V_20 . V_310 . V_311 = V_171 -> V_20 . V_310 . V_311 ;
if ( V_166 [ V_322 ] ) {
V_141 = F_220 ( V_166 [ V_322 ] ,
exp , F_21 ( V_29 ) ) ;
if ( V_141 < 0 )
goto V_349;
}
return exp ;
V_349:
F_195 ( exp ) ;
return F_87 ( V_141 ) ;
}
static int
F_223 ( struct V_139 * V_139 ,
const struct V_23 * V_24 ,
const struct V_8 * const V_166 [] ,
V_132 V_205 , T_2 V_106 , int V_151 )
{
struct V_3 V_4 , V_171 , F_47 ;
struct V_176 * V_177 = NULL ;
struct V_41 * V_42 = NULL ;
struct V_303 * exp ;
struct V_28 * V_29 ;
int V_141 ;
V_141 = F_118 ( V_166 , & V_4 , V_300 ,
V_205 , NULL ) ;
if ( V_141 < 0 )
return V_141 ;
V_141 = F_118 ( V_166 , & V_171 , V_301 ,
V_205 , NULL ) ;
if ( V_141 < 0 )
return V_141 ;
V_141 = F_118 ( V_166 , & F_47 , V_318 ,
V_205 , NULL ) ;
if ( V_141 < 0 )
return V_141 ;
V_177 = F_127 ( V_139 , V_24 , & F_47 ) ;
if ( ! V_177 )
return - V_206 ;
V_29 = F_100 ( V_177 ) ;
if ( V_166 [ V_305 ] ) {
const char * V_242 = F_120 ( V_166 [ V_305 ] ) ;
V_42 = F_153 ( V_242 , V_205 ,
F_22 ( V_29 ) ) ;
if ( V_42 == NULL ) {
#ifdef F_144
if ( F_146 ( L_4 , V_242 ) < 0 ) {
V_141 = - V_173 ;
goto V_351;
}
V_42 = F_153 ( V_242 , V_205 ,
F_22 ( V_29 ) ) ;
if ( V_42 ) {
V_141 = - V_161 ;
goto V_351;
}
#endif
V_141 = - V_173 ;
goto V_351;
}
}
exp = F_193 ( V_166 , V_29 , V_42 , & V_4 , & V_171 ) ;
if ( F_122 ( exp ) ) {
V_141 = F_123 ( exp ) ;
goto V_351;
}
V_141 = F_194 ( exp , V_106 , V_151 ) ;
F_195 ( exp ) ;
V_351:
F_83 ( V_29 ) ;
return V_141 ;
}
static int F_224 ( struct V_139 * V_139 , struct V_203 * V_204 ,
struct V_1 * V_2 , const struct V_107 * V_108 ,
const struct V_8 * const V_166 [] )
{
struct V_3 V_4 ;
struct V_303 * exp ;
struct V_109 * V_110 = F_56 ( V_108 ) ;
V_132 V_205 = V_110 -> V_117 ;
struct V_23 V_24 ;
int V_141 ;
if ( ! V_166 [ V_300 ]
|| ! V_166 [ V_301 ]
|| ! V_166 [ V_318 ] )
return - V_195 ;
V_141 = F_113 ( V_166 [ V_341 ] , & V_24 ) ;
if ( V_141 < 0 )
return V_141 ;
V_141 = F_118 ( V_166 , & V_4 , V_300 ,
V_205 , NULL ) ;
if ( V_141 < 0 )
return V_141 ;
F_136 ( & V_244 ) ;
exp = F_225 ( V_139 , & V_24 , & V_4 ) ;
if ( ! exp ) {
F_137 ( & V_244 ) ;
V_141 = - V_206 ;
if ( V_108 -> V_208 & V_147 ) {
V_141 = F_223 ( V_139 , & V_24 , V_166 , V_205 ,
F_104 ( V_2 ) . V_106 ,
F_126 ( V_108 ) ) ;
}
return V_141 ;
}
V_141 = - V_265 ;
if ( ! ( V_108 -> V_208 & V_148 ) )
V_141 = F_218 ( exp , V_166 ) ;
F_137 ( & V_244 ) ;
return V_141 ;
}
static int
F_226 ( struct V_1 * V_2 , T_2 V_106 , T_2 V_90 , int V_217 ,
const struct V_266 * V_267 )
{
struct V_107 * V_108 ;
struct V_109 * V_110 ;
unsigned int V_111 = V_106 ? V_112 : 0 , V_113 ;
V_113 = ( V_114 << 8 | V_352 ) ;
V_108 = F_55 ( V_2 , V_106 , V_90 , V_113 , sizeof( * V_110 ) , V_111 ) ;
if ( V_108 == NULL )
goto V_116;
V_110 = F_56 ( V_108 ) ;
V_110 -> V_117 = V_269 ;
V_110 -> V_118 = V_119 ;
V_110 -> V_120 = F_14 ( V_217 ) ;
if ( F_16 ( V_2 , V_353 , F_17 ( V_267 -> V_354 ) ) ||
F_16 ( V_2 , V_355 , F_17 ( V_267 -> V_356 ) ) ||
F_16 ( V_2 , V_357 , F_17 ( V_267 -> V_358 ) ) )
goto V_12;
F_59 ( V_2 , V_108 ) ;
return V_2 -> V_77 ;
V_12:
V_116:
F_60 ( V_2 , V_108 ) ;
return - 1 ;
}
static int
F_227 ( struct V_1 * V_2 , struct V_162 * V_163 )
{
int V_217 ;
struct V_139 * V_139 = F_92 ( V_2 -> V_174 ) ;
if ( V_163 -> args [ 0 ] == V_220 )
return 0 ;
for ( V_217 = V_163 -> args [ 0 ] ; V_217 < V_220 ; V_217 ++ ) {
const struct V_266 * V_267 ;
if ( ! F_134 ( V_217 ) )
continue;
V_267 = F_135 ( V_139 -> V_29 . V_287 , V_217 ) ;
if ( F_226 ( V_2 , F_104 ( V_163 -> V_2 ) . V_106 ,
V_163 -> V_108 -> V_187 ,
V_217 , V_267 ) < 0 )
break;
}
V_163 -> args [ 0 ] = V_217 ;
return V_2 -> V_77 ;
}
static int F_228 ( struct V_139 * V_139 , struct V_203 * V_204 ,
struct V_1 * V_2 ,
const struct V_107 * V_108 ,
const struct V_8 * const V_166 [] )
{
if ( V_108 -> V_208 & V_209 ) {
struct V_210 V_211 = {
. V_212 = F_227 ,
} ;
return F_130 ( V_204 , V_2 , V_108 , & V_211 ) ;
}
return 0 ;
}
static int T_8 F_229 ( struct V_139 * V_139 )
{
#ifdef F_230
int V_7 ;
V_7 = F_231 ( V_139 , & V_359 ) ;
if ( V_7 < 0 ) {
F_232 ( L_5 ) ;
goto V_349;
}
V_7 = F_233 ( V_139 , & V_360 ) ;
if ( V_7 < 0 ) {
F_232 ( L_6 ) ;
goto V_361;
}
#endif
return 0 ;
#ifdef F_230
V_361:
F_234 ( V_139 , & V_359 ) ;
V_349:
return V_7 ;
#endif
}
static void F_235 ( struct V_139 * V_139 )
{
#ifdef F_230
F_236 ( V_139 , & V_360 ) ;
F_234 ( V_139 , & V_359 ) ;
#endif
}
static void T_9 F_237 ( struct V_362 * V_363 )
{
struct V_139 * V_139 ;
F_238 (net, net_exit_list, exit_list)
F_235 ( V_139 ) ;
}
static int T_10 F_239 ( void )
{
int V_7 ;
F_240 ( L_7 , V_118 ) ;
V_7 = F_241 ( & V_364 ) ;
if ( V_7 < 0 ) {
F_232 ( L_8 ) ;
goto V_349;
}
V_7 = F_241 ( & V_365 ) ;
if ( V_7 < 0 ) {
F_232 ( L_9 ) ;
goto V_366;
}
V_7 = F_242 ( & V_367 ) ;
if ( V_7 < 0 ) {
F_232 ( L_10 ) ;
goto V_368;
}
#ifdef F_243
F_152 ( V_369 , & V_370 ) ;
#endif
return 0 ;
V_368:
F_244 ( & V_365 ) ;
V_366:
F_244 ( & V_364 ) ;
V_349:
return V_7 ;
}
static void T_11 F_245 ( void )
{
F_240 ( L_11 ) ;
F_246 ( & V_367 ) ;
F_244 ( & V_365 ) ;
F_244 ( & V_364 ) ;
#ifdef F_243
F_152 ( V_369 , NULL ) ;
#endif
}
