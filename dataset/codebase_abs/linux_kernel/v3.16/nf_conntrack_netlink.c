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
F_12 ( struct V_1 * V_2 , const struct V_22 * V_23 )
{
if ( F_13 ( V_2 , V_24 , F_14 ( V_23 -> V_25 ) ) )
goto V_12;
return 0 ;
V_12:
return - 1 ;
}
static inline int
F_15 ( struct V_1 * V_2 , const struct V_22 * V_23 )
{
long V_26 = ( ( long ) V_23 -> V_26 . V_27 - ( long ) V_28 ) / V_29 ;
if ( V_26 < 0 )
V_26 = 0 ;
if ( F_13 ( V_2 , V_30 , F_14 ( V_26 ) ) )
goto V_12;
return 0 ;
V_12:
return - 1 ;
}
static inline int
F_16 ( struct V_1 * V_2 , struct V_22 * V_23 )
{
struct V_5 * V_6 ;
struct V_8 * V_31 ;
int V_7 ;
V_6 = F_10 ( F_17 ( V_23 ) , F_18 ( V_23 ) ) ;
if ( ! V_6 -> V_32 )
return 0 ;
V_31 = F_2 ( V_2 , V_33 | V_11 ) ;
if ( ! V_31 )
goto V_12;
V_7 = V_6 -> V_32 ( V_2 , V_31 , V_23 ) ;
F_5 ( V_2 , V_31 ) ;
return V_7 ;
V_12:
return - 1 ;
}
static inline int
F_19 ( struct V_1 * V_2 , const struct V_22 * V_23 )
{
struct V_8 * V_34 ;
const struct V_35 * V_36 = F_20 ( V_23 ) ;
struct V_37 * V_38 ;
if ( ! V_36 )
return 0 ;
V_38 = F_21 ( V_36 -> V_38 ) ;
if ( ! V_38 )
goto V_39;
V_34 = F_2 ( V_2 , V_40 | V_11 ) ;
if ( ! V_34 )
goto V_12;
if ( F_22 ( V_2 , V_41 , V_38 -> V_42 ) )
goto V_12;
if ( V_38 -> V_32 )
V_38 -> V_32 ( V_2 , V_23 ) ;
F_5 ( V_2 , V_34 ) ;
V_39:
return 0 ;
V_12:
return - 1 ;
}
static int
F_23 ( struct V_1 * V_2 , struct V_43 * V_44 ,
enum V_45 V_46 , int type )
{
enum V_47 V_48 = V_46 ? V_49 : V_50 ;
struct V_51 * V_52 = V_44 -> V_52 ;
struct V_8 * V_53 ;
T_1 V_54 , V_55 ;
if ( type == V_56 ) {
V_54 = F_24 ( & V_52 [ V_46 ] . V_57 , 0 ) ;
V_55 = F_24 ( & V_52 [ V_46 ] . V_55 , 0 ) ;
} else {
V_54 = F_25 ( & V_52 [ V_46 ] . V_57 ) ;
V_55 = F_25 ( & V_52 [ V_46 ] . V_55 ) ;
}
V_53 = F_2 ( V_2 , V_48 | V_11 ) ;
if ( ! V_53 )
goto V_12;
if ( F_26 ( V_2 , V_58 , F_27 ( V_54 ) ) ||
F_26 ( V_2 , V_59 , F_27 ( V_55 ) ) )
goto V_12;
F_5 ( V_2 , V_53 ) ;
return 0 ;
V_12:
return - 1 ;
}
static int
F_28 ( struct V_1 * V_2 , const struct V_22 * V_23 , int type )
{
struct V_43 * V_44 = F_29 ( V_23 ) ;
if ( ! V_44 )
return 0 ;
if ( F_23 ( V_2 , V_44 , V_60 , type ) < 0 )
return - 1 ;
if ( F_23 ( V_2 , V_44 , V_61 , type ) < 0 )
return - 1 ;
return 0 ;
}
static int
F_30 ( struct V_1 * V_2 , const struct V_22 * V_23 )
{
struct V_8 * V_53 ;
const struct V_62 * V_63 ;
V_63 = F_31 ( V_23 ) ;
if ( ! V_63 )
return 0 ;
V_53 = F_2 ( V_2 , V_64 | V_11 ) ;
if ( ! V_53 )
goto V_12;
if ( F_26 ( V_2 , V_65 , F_27 ( V_63 -> V_66 ) ) ||
( V_63 -> V_67 != 0 && F_26 ( V_2 , V_68 ,
F_27 ( V_63 -> V_67 ) ) ) )
goto V_12;
F_5 ( V_2 , V_53 ) ;
return 0 ;
V_12:
return - 1 ;
}
static inline int
F_32 ( struct V_1 * V_2 , const struct V_22 * V_23 )
{
if ( F_13 ( V_2 , V_69 , F_14 ( V_23 -> V_70 ) ) )
goto V_12;
return 0 ;
V_12:
return - 1 ;
}
static inline int
F_33 ( struct V_1 * V_2 , const struct V_22 * V_23 )
{
struct V_8 * V_71 ;
int V_72 , V_7 ;
char * V_73 ;
V_7 = F_34 ( V_23 -> V_74 , & V_73 , & V_72 ) ;
if ( V_7 )
return 0 ;
V_7 = - 1 ;
V_71 = F_2 ( V_2 , V_75 | V_11 ) ;
if ( ! V_71 )
goto V_12;
if ( F_22 ( V_2 , V_76 , V_73 ) )
goto V_12;
F_5 ( V_2 , V_71 ) ;
V_7 = 0 ;
V_12:
F_35 ( V_73 , V_72 ) ;
return V_7 ;
}
static int F_36 ( const struct V_22 * V_23 )
{
struct V_77 * V_78 = F_37 ( V_23 ) ;
if ( ! V_78 )
return 0 ;
return F_38 ( V_78 -> V_79 * sizeof( long ) ) ;
}
static int
F_39 ( struct V_1 * V_2 , const struct V_22 * V_23 )
{
struct V_77 * V_78 = F_37 ( V_23 ) ;
unsigned int V_72 , V_80 ;
if ( ! V_78 )
return 0 ;
V_72 = V_78 -> V_79 * sizeof( long ) ;
V_80 = 0 ;
do {
if ( V_78 -> V_81 [ V_80 ] != 0 )
return F_40 ( V_2 , V_82 , V_72 , V_78 -> V_81 ) ;
V_80 ++ ;
} while ( V_80 < V_78 -> V_79 );
return 0 ;
}
static inline int
F_41 ( struct V_1 * V_2 , const struct V_22 * V_23 )
{
struct V_8 * V_9 ;
if ( ! ( V_23 -> V_25 & V_83 ) )
return 0 ;
V_9 = F_2 ( V_2 , V_84 | V_11 ) ;
if ( ! V_9 )
goto V_12;
if ( F_7 ( V_2 , F_42 ( V_23 ) ) < 0 )
goto V_12;
F_5 ( V_2 , V_9 ) ;
return 0 ;
V_12:
return - 1 ;
}
static int
F_43 ( struct V_1 * V_2 , const struct V_85 * V_86 , int type )
{
struct V_8 * V_9 ;
V_9 = F_2 ( V_2 , type | V_11 ) ;
if ( ! V_9 )
goto V_12;
if ( F_13 ( V_2 , V_87 ,
F_14 ( V_86 -> V_88 ) ) ||
F_13 ( V_2 , V_89 ,
F_14 ( V_86 -> V_90 ) ) ||
F_13 ( V_2 , V_91 ,
F_14 ( V_86 -> V_92 ) ) )
goto V_12;
F_5 ( V_2 , V_9 ) ;
return 0 ;
V_12:
return - 1 ;
}
static inline int
F_44 ( struct V_1 * V_2 , const struct V_22 * V_23 )
{
struct V_93 * V_94 = F_45 ( V_23 ) ;
struct V_85 * V_86 ;
if ( ! ( V_23 -> V_25 & V_95 ) || ! V_94 )
return 0 ;
V_86 = & V_94 -> V_86 [ V_60 ] ;
if ( F_43 ( V_2 , V_86 , V_96 ) == - 1 )
return - 1 ;
V_86 = & V_94 -> V_86 [ V_61 ] ;
if ( F_43 ( V_2 , V_86 , V_97 ) == - 1 )
return - 1 ;
return 0 ;
}
static inline int
F_46 ( struct V_1 * V_2 , const struct V_22 * V_23 )
{
if ( F_13 ( V_2 , V_98 , F_14 ( ( unsigned long ) V_23 ) ) )
goto V_12;
return 0 ;
V_12:
return - 1 ;
}
static inline int
F_47 ( struct V_1 * V_2 , const struct V_22 * V_23 )
{
if ( F_13 ( V_2 , V_99 , F_14 ( F_48 ( & V_23 -> V_100 . V_101 ) ) ) )
goto V_12;
return 0 ;
V_12:
return - 1 ;
}
static int
F_49 ( struct V_1 * V_2 , T_2 V_102 , T_2 V_86 , T_2 type ,
struct V_22 * V_23 )
{
struct V_103 * V_104 ;
struct V_105 * V_106 ;
struct V_8 * V_9 ;
unsigned int V_107 = V_102 ? V_108 : 0 , V_109 ;
V_109 = ( V_110 << 8 | V_111 ) ;
V_104 = F_50 ( V_2 , V_102 , V_86 , V_109 , sizeof( * V_106 ) , V_107 ) ;
if ( V_104 == NULL )
goto V_112;
V_106 = F_51 ( V_104 ) ;
V_106 -> V_113 = F_17 ( V_23 ) ;
V_106 -> V_114 = V_115 ;
V_106 -> V_116 = 0 ;
V_9 = F_2 ( V_2 , V_117 | V_11 ) ;
if ( ! V_9 )
goto V_12;
if ( F_7 ( V_2 , F_52 ( V_23 , V_60 ) ) < 0 )
goto V_12;
F_5 ( V_2 , V_9 ) ;
V_9 = F_2 ( V_2 , V_118 | V_11 ) ;
if ( ! V_9 )
goto V_12;
if ( F_7 ( V_2 , F_52 ( V_23 , V_61 ) ) < 0 )
goto V_12;
F_5 ( V_2 , V_9 ) ;
if ( F_53 ( V_23 ) &&
F_54 ( V_2 , V_119 , F_55 ( F_53 ( V_23 ) ) ) )
goto V_12;
if ( F_12 ( V_2 , V_23 ) < 0 ||
F_15 ( V_2 , V_23 ) < 0 ||
F_28 ( V_2 , V_23 , type ) < 0 ||
F_30 ( V_2 , V_23 ) < 0 ||
F_16 ( V_2 , V_23 ) < 0 ||
F_19 ( V_2 , V_23 ) < 0 ||
F_32 ( V_2 , V_23 ) < 0 ||
F_33 ( V_2 , V_23 ) < 0 ||
F_39 ( V_2 , V_23 ) < 0 ||
F_46 ( V_2 , V_23 ) < 0 ||
F_47 ( V_2 , V_23 ) < 0 ||
F_41 ( V_2 , V_23 ) < 0 ||
F_44 ( V_2 , V_23 ) < 0 )
goto V_12;
F_56 ( V_2 , V_104 ) ;
return V_2 -> V_72 ;
V_112:
V_12:
F_57 ( V_2 , V_104 ) ;
return - 1 ;
}
static inline T_3
F_58 ( const struct V_22 * V_23 )
{
struct V_17 * V_18 ;
struct V_5 * V_6 ;
T_3 V_72 = 0 ;
F_8 () ;
V_18 = F_9 ( F_17 ( V_23 ) ) ;
V_72 += V_18 -> V_120 ;
V_6 = F_10 ( F_17 ( V_23 ) , F_18 ( V_23 ) ) ;
V_72 += V_6 -> V_120 ;
F_11 () ;
return V_72 ;
}
static inline T_3
F_59 ( const struct V_22 * V_23 )
{
if ( ! F_60 ( V_23 , V_121 ) )
return 0 ;
return 2 * F_38 ( 0 )
+ 2 * F_38 ( sizeof( V_122 ) )
+ 2 * F_38 ( sizeof( V_122 ) )
;
}
static inline int
F_61 ( const struct V_22 * V_23 )
{
#ifdef F_62
int V_72 , V_7 ;
V_7 = F_34 ( V_23 -> V_74 , NULL , & V_72 ) ;
if ( V_7 )
return 0 ;
return F_38 ( 0 )
+ F_38 ( sizeof( char ) * V_72 ) ;
#else
return 0 ;
#endif
}
static inline T_3
F_63 ( const struct V_22 * V_23 )
{
#ifdef F_64
if ( ! F_60 ( V_23 , V_123 ) )
return 0 ;
return F_38 ( 0 ) + 2 * F_38 ( sizeof( V_122 ) ) ;
#else
return 0 ;
#endif
}
static inline T_3
F_65 ( const struct V_22 * V_23 )
{
return F_66 ( sizeof( struct V_105 ) )
+ 3 * F_38 ( 0 )
+ 3 * F_38 ( 0 )
+ 3 * F_38 ( 0 )
+ 3 * F_38 ( sizeof( V_124 ) )
+ F_38 ( sizeof( V_125 ) )
+ F_38 ( sizeof( V_125 ) )
+ F_59 ( V_23 )
+ F_63 ( V_23 )
+ F_38 ( sizeof( V_125 ) )
+ F_38 ( 0 )
+ F_38 ( 0 )
+ F_38 ( V_126 )
+ F_61 ( V_23 )
#ifdef F_67
+ 2 * F_38 ( 0 )
+ 6 * F_38 ( sizeof( V_125 ) )
#endif
#ifdef F_68
+ F_38 ( sizeof( V_125 ) )
#endif
#ifdef F_69
+ F_38 ( sizeof( V_127 ) )
#endif
+ F_58 ( V_23 )
+ F_36 ( V_23 )
;
}
static int
F_70 ( unsigned int V_128 , struct V_129 * V_130 )
{
struct V_131 * V_131 ;
struct V_103 * V_104 ;
struct V_105 * V_106 ;
struct V_8 * V_9 ;
struct V_22 * V_23 = V_130 -> V_23 ;
struct V_1 * V_2 ;
unsigned int type ;
unsigned int V_107 = 0 , V_132 ;
int V_133 ;
if ( F_71 ( V_23 ) )
return 0 ;
if ( V_128 & ( 1 << V_134 ) ) {
type = V_135 ;
V_132 = V_136 ;
} else if ( V_128 & ( ( 1 << V_137 ) | ( 1 << V_138 ) ) ) {
type = V_111 ;
V_107 = V_139 | V_140 ;
V_132 = V_141 ;
} else if ( V_128 ) {
type = V_111 ;
V_132 = V_142 ;
} else
return 0 ;
V_131 = F_72 ( V_23 ) ;
if ( ! V_130 -> V_143 && ! F_73 ( V_131 , V_132 ) )
return 0 ;
V_2 = F_74 ( F_65 ( V_23 ) , V_144 ) ;
if ( V_2 == NULL )
goto V_145;
type |= V_110 << 8 ;
V_104 = F_50 ( V_2 , V_130 -> V_102 , 0 , type , sizeof( * V_106 ) , V_107 ) ;
if ( V_104 == NULL )
goto V_112;
V_106 = F_51 ( V_104 ) ;
V_106 -> V_113 = F_17 ( V_23 ) ;
V_106 -> V_114 = V_115 ;
V_106 -> V_116 = 0 ;
F_8 () ;
V_9 = F_2 ( V_2 , V_117 | V_11 ) ;
if ( ! V_9 )
goto V_12;
if ( F_7 ( V_2 , F_52 ( V_23 , V_60 ) ) < 0 )
goto V_12;
F_5 ( V_2 , V_9 ) ;
V_9 = F_2 ( V_2 , V_118 | V_11 ) ;
if ( ! V_9 )
goto V_12;
if ( F_7 ( V_2 , F_52 ( V_23 , V_61 ) ) < 0 )
goto V_12;
F_5 ( V_2 , V_9 ) ;
if ( F_53 ( V_23 ) &&
F_54 ( V_2 , V_119 , F_55 ( F_53 ( V_23 ) ) ) )
goto V_12;
if ( F_46 ( V_2 , V_23 ) < 0 )
goto V_12;
if ( F_12 ( V_2 , V_23 ) < 0 )
goto V_12;
if ( V_128 & ( 1 << V_134 ) ) {
if ( F_28 ( V_2 , V_23 , type ) < 0 ||
F_30 ( V_2 , V_23 ) < 0 )
goto V_12;
} else {
if ( F_15 ( V_2 , V_23 ) < 0 )
goto V_12;
if ( V_128 & ( 1 << V_146 )
&& F_16 ( V_2 , V_23 ) < 0 )
goto V_12;
if ( ( V_128 & ( 1 << V_147 ) || F_20 ( V_23 ) )
&& F_19 ( V_2 , V_23 ) < 0 )
goto V_12;
#ifdef F_62
if ( ( V_128 & ( 1 << V_148 ) || V_23 -> V_74 )
&& F_33 ( V_2 , V_23 ) < 0 )
goto V_12;
#endif
if ( V_128 & ( 1 << V_149 ) &&
F_39 ( V_2 , V_23 ) < 0 )
goto V_12;
if ( V_128 & ( 1 << V_138 ) &&
F_41 ( V_2 , V_23 ) < 0 )
goto V_12;
if ( V_128 & ( 1 << V_150 ) &&
F_44 ( V_2 , V_23 ) < 0 )
goto V_12;
}
#ifdef F_68
if ( ( V_128 & ( 1 << V_151 ) || V_23 -> V_70 )
&& F_32 ( V_2 , V_23 ) < 0 )
goto V_12;
#endif
F_11 () ;
F_56 ( V_2 , V_104 ) ;
V_133 = F_75 ( V_2 , V_131 , V_130 -> V_102 , V_132 , V_130 -> V_143 ,
V_144 ) ;
if ( V_133 == - V_152 || V_133 == - V_153 )
return - V_152 ;
return 0 ;
V_12:
F_11 () ;
F_57 ( V_2 , V_104 ) ;
V_112:
F_76 ( V_2 ) ;
V_145:
if ( F_77 ( V_131 , 0 , V_132 , - V_152 ) > 0 )
return - V_152 ;
return 0 ;
}
static int F_78 ( struct V_154 * V_155 )
{
if ( V_155 -> args [ 1 ] )
F_79 ( (struct V_22 * ) V_155 -> args [ 1 ] ) ;
if ( V_155 -> V_156 )
F_80 ( V_155 -> V_156 ) ;
return 0 ;
}
static int
F_81 ( struct V_1 * V_2 , struct V_154 * V_155 )
{
struct V_131 * V_131 = F_82 ( V_2 -> V_157 ) ;
struct V_22 * V_23 , * V_158 ;
struct V_159 * V_160 ;
struct V_161 * V_162 ;
struct V_105 * V_106 = F_51 ( V_155 -> V_104 ) ;
V_124 V_18 = V_106 -> V_113 ;
int V_163 ;
T_4 * V_164 ;
#ifdef F_68
const struct V_165 * V_166 = V_155 -> V_156 ;
#endif
V_158 = (struct V_22 * ) V_155 -> args [ 1 ] ;
F_83 () ;
for (; V_155 -> args [ 0 ] < V_131 -> V_23 . V_167 ; V_155 -> args [ 0 ] ++ ) {
V_168:
V_164 = & V_169 [ V_155 -> args [ 0 ] % V_170 ] ;
F_84 ( V_164 ) ;
if ( V_155 -> args [ 0 ] >= V_131 -> V_23 . V_167 ) {
F_85 ( V_164 ) ;
goto V_39;
}
F_86 (h, n, &net->ct.hash[cb->args[0]],
hnnode) {
if ( F_87 ( V_160 ) != V_60 )
continue;
V_23 = F_88 ( V_160 ) ;
if ( V_18 && F_17 ( V_23 ) != V_18 )
continue;
if ( V_155 -> args [ 1 ] ) {
if ( V_23 != V_158 )
continue;
V_155 -> args [ 1 ] = 0 ;
}
#ifdef F_68
if ( V_166 && ! ( ( V_23 -> V_70 & V_166 -> V_70 . V_171 ) ==
V_166 -> V_70 . V_172 ) ) {
continue;
}
#endif
F_8 () ;
V_163 =
F_49 ( V_2 , F_89 ( V_155 -> V_2 ) . V_102 ,
V_155 -> V_104 -> V_173 ,
F_90 ( V_155 -> V_104 -> V_174 ) ,
V_23 ) ;
F_11 () ;
if ( V_163 < 0 ) {
F_91 ( & V_23 -> V_100 ) ;
V_155 -> args [ 1 ] = ( unsigned long ) V_23 ;
F_85 ( V_164 ) ;
goto V_39;
}
}
F_85 ( V_164 ) ;
if ( V_155 -> args [ 1 ] ) {
V_155 -> args [ 1 ] = 0 ;
goto V_168;
}
}
V_39:
F_92 () ;
if ( V_158 )
F_79 ( V_158 ) ;
return V_2 -> V_72 ;
}
static inline int
F_93 ( struct V_8 * V_48 , struct V_3 * V_4 )
{
struct V_8 * V_175 [ V_176 + 1 ] ;
struct V_17 * V_18 ;
int V_7 = 0 ;
V_7 = F_94 ( V_175 , V_176 , V_48 , NULL ) ;
if ( V_7 < 0 )
return V_7 ;
F_8 () ;
V_18 = F_9 ( V_4 -> V_20 . V_21 ) ;
if ( F_4 ( V_18 -> V_177 ) ) {
V_7 = F_95 ( V_48 , V_176 ,
V_18 -> V_178 ) ;
if ( V_7 == 0 )
V_7 = V_18 -> V_177 ( V_175 , V_4 ) ;
}
F_11 () ;
return V_7 ;
}
static inline int
F_96 ( struct V_8 * V_48 ,
struct V_3 * V_4 )
{
struct V_8 * V_175 [ V_179 + 1 ] ;
struct V_5 * V_6 ;
int V_7 = 0 ;
V_7 = F_94 ( V_175 , V_179 , V_48 , V_180 ) ;
if ( V_7 < 0 )
return V_7 ;
if ( ! V_175 [ V_13 ] )
return - V_181 ;
V_4 -> V_14 . V_15 = F_97 ( V_175 [ V_13 ] ) ;
F_8 () ;
V_6 = F_10 ( V_4 -> V_20 . V_21 , V_4 -> V_14 . V_15 ) ;
if ( F_4 ( V_6 -> V_177 ) ) {
V_7 = F_95 ( V_48 , V_179 ,
V_6 -> V_178 ) ;
if ( V_7 == 0 )
V_7 = V_6 -> V_177 ( V_175 , V_4 ) ;
}
F_11 () ;
return V_7 ;
}
static int
F_98 ( const struct V_8 * const V_182 [] ,
struct V_3 * V_4 ,
enum V_47 type , V_124 V_21 )
{
struct V_8 * V_175 [ V_183 + 1 ] ;
int V_133 ;
memset ( V_4 , 0 , sizeof( * V_4 ) ) ;
V_133 = F_94 ( V_175 , V_183 , V_182 [ type ] , V_184 ) ;
if ( V_133 < 0 )
return V_133 ;
if ( ! V_175 [ V_19 ] )
return - V_181 ;
V_4 -> V_20 . V_21 = V_21 ;
V_133 = F_93 ( V_175 [ V_19 ] , V_4 ) ;
if ( V_133 < 0 )
return V_133 ;
if ( ! V_175 [ V_10 ] )
return - V_181 ;
V_133 = F_96 ( V_175 [ V_10 ] , V_4 ) ;
if ( V_133 < 0 )
return V_133 ;
if ( type == V_118 )
V_4 -> V_14 . V_46 = V_61 ;
else
V_4 -> V_14 . V_46 = V_60 ;
return 0 ;
}
static int
F_99 ( const struct V_8 * V_48 , T_5 * V_185 )
{
if ( V_48 )
#ifdef F_69
* V_185 = F_100 ( F_101 ( V_48 ) ) ;
#else
return - V_186 ;
#endif
else
* V_185 = 0 ;
return 0 ;
}
static inline int
F_102 ( const struct V_8 * V_48 , char * * V_187 ,
struct V_8 * * V_188 )
{
int V_133 ;
struct V_8 * V_175 [ V_189 + 1 ] ;
V_133 = F_94 ( V_175 , V_189 , V_48 , V_190 ) ;
if ( V_133 < 0 )
return V_133 ;
if ( ! V_175 [ V_41 ] )
return - V_181 ;
* V_187 = F_103 ( V_175 [ V_41 ] ) ;
if ( V_175 [ V_191 ] )
* V_188 = V_175 [ V_191 ] ;
return 0 ;
}
static int
F_104 ( struct V_192 * V_193 , struct V_1 * V_2 ,
const struct V_103 * V_104 ,
const struct V_8 * const V_182 [] )
{
struct V_131 * V_131 = F_82 ( V_193 ) ;
struct V_159 * V_160 ;
struct V_3 V_4 ;
struct V_22 * V_23 ;
struct V_105 * V_106 = F_51 ( V_104 ) ;
V_124 V_194 = V_106 -> V_113 ;
T_5 V_185 ;
int V_133 ;
V_133 = F_99 ( V_182 [ V_119 ] , & V_185 ) ;
if ( V_133 < 0 )
return V_133 ;
if ( V_182 [ V_117 ] )
V_133 = F_98 ( V_182 , & V_4 , V_117 , V_194 ) ;
else if ( V_182 [ V_118 ] )
V_133 = F_98 ( V_182 , & V_4 , V_118 , V_194 ) ;
else {
F_105 ( V_131 ,
F_89 ( V_2 ) . V_102 ,
F_106 ( V_104 ) ) ;
return 0 ;
}
if ( V_133 < 0 )
return V_133 ;
V_160 = F_107 ( V_131 , V_185 , & V_4 ) ;
if ( ! V_160 )
return - V_195 ;
V_23 = F_88 ( V_160 ) ;
if ( V_182 [ V_98 ] ) {
V_125 V_196 = F_108 ( F_109 ( V_182 [ V_98 ] ) ) ;
if ( V_196 != ( T_2 ) ( unsigned long ) V_23 ) {
F_79 ( V_23 ) ;
return - V_195 ;
}
}
if ( F_110 ( & V_23 -> V_26 ) )
F_111 ( V_23 , F_89 ( V_2 ) . V_102 , F_106 ( V_104 ) ) ;
F_79 ( V_23 ) ;
return 0 ;
}
static int
F_112 ( struct V_192 * V_193 , struct V_1 * V_2 ,
const struct V_103 * V_104 ,
const struct V_8 * const V_182 [] )
{
struct V_131 * V_131 = F_82 ( V_193 ) ;
struct V_159 * V_160 ;
struct V_3 V_4 ;
struct V_22 * V_23 ;
struct V_1 * V_197 = NULL ;
struct V_105 * V_106 = F_51 ( V_104 ) ;
V_124 V_194 = V_106 -> V_113 ;
T_5 V_185 ;
int V_133 ;
if ( V_104 -> V_198 & V_199 ) {
struct V_200 V_201 = {
. V_202 = F_81 ,
. V_203 = F_78 ,
} ;
#ifdef F_68
if ( V_182 [ V_69 ] && V_182 [ V_204 ] ) {
struct V_165 * V_166 ;
V_166 = F_113 ( sizeof( struct V_165 ) ,
V_144 ) ;
if ( V_166 == NULL )
return - V_205 ;
V_166 -> V_70 . V_172 = F_108 ( F_109 ( V_182 [ V_69 ] ) ) ;
V_166 -> V_70 . V_171 =
F_108 ( F_109 ( V_182 [ V_204 ] ) ) ;
V_201 . V_156 = V_166 ;
}
#endif
return F_114 ( V_193 , V_2 , V_104 , & V_201 ) ;
}
V_133 = F_99 ( V_182 [ V_119 ] , & V_185 ) ;
if ( V_133 < 0 )
return V_133 ;
if ( V_182 [ V_117 ] )
V_133 = F_98 ( V_182 , & V_4 , V_117 , V_194 ) ;
else if ( V_182 [ V_118 ] )
V_133 = F_98 ( V_182 , & V_4 , V_118 , V_194 ) ;
else
return - V_181 ;
if ( V_133 < 0 )
return V_133 ;
V_160 = F_107 ( V_131 , V_185 , & V_4 ) ;
if ( ! V_160 )
return - V_195 ;
V_23 = F_88 ( V_160 ) ;
V_133 = - V_205 ;
V_197 = F_74 ( V_206 , V_207 ) ;
if ( V_197 == NULL ) {
F_79 ( V_23 ) ;
return - V_205 ;
}
F_8 () ;
V_133 = F_49 ( V_197 , F_89 ( V_2 ) . V_102 , V_104 -> V_173 ,
F_90 ( V_104 -> V_174 ) , V_23 ) ;
F_11 () ;
F_79 ( V_23 ) ;
if ( V_133 <= 0 )
goto free;
V_133 = F_115 ( V_193 , V_197 , F_89 ( V_2 ) . V_102 , V_208 ) ;
if ( V_133 < 0 )
goto V_39;
return 0 ;
free:
F_76 ( V_197 ) ;
V_39:
return V_133 == - V_153 ? - V_152 : V_133 ;
}
static int F_116 ( struct V_154 * V_155 )
{
if ( V_155 -> args [ 1 ] )
F_79 ( (struct V_22 * ) V_155 -> args [ 1 ] ) ;
return 0 ;
}
static int
F_117 ( struct V_1 * V_2 , struct V_154 * V_155 , bool V_209 )
{
struct V_22 * V_23 , * V_158 ;
struct V_159 * V_160 ;
struct V_161 * V_162 ;
struct V_105 * V_106 = F_51 ( V_155 -> V_104 ) ;
V_124 V_18 = V_106 -> V_113 ;
int V_163 ;
int V_210 ;
struct V_211 * V_212 ;
struct V_131 * V_131 = F_82 ( V_2 -> V_157 ) ;
if ( V_155 -> args [ 2 ] )
return 0 ;
V_158 = (struct V_22 * ) V_155 -> args [ 1 ] ;
for ( V_210 = V_155 -> args [ 0 ] ; V_210 < V_213 ; V_210 ++ ) {
struct V_214 * V_215 ;
if ( ! F_118 ( V_210 ) )
continue;
V_215 = F_119 ( V_131 -> V_23 . V_216 , V_210 ) ;
F_120 ( & V_215 -> V_217 ) ;
V_212 = V_209 ? & V_215 -> V_209 : & V_215 -> V_218 ;
V_168:
F_86 (h, n, list, hnnode) {
V_23 = F_88 ( V_160 ) ;
if ( V_18 && F_17 ( V_23 ) != V_18 )
continue;
if ( V_155 -> args [ 1 ] ) {
if ( V_23 != V_158 )
continue;
V_155 -> args [ 1 ] = 0 ;
}
F_8 () ;
V_163 = F_49 ( V_2 , F_89 ( V_155 -> V_2 ) . V_102 ,
V_155 -> V_104 -> V_173 ,
F_90 ( V_155 -> V_104 -> V_174 ) ,
V_23 ) ;
F_11 () ;
if ( V_163 < 0 ) {
if ( ! F_121 ( & V_23 -> V_100 . V_101 ) )
continue;
V_155 -> args [ 0 ] = V_210 ;
V_155 -> args [ 1 ] = ( unsigned long ) V_23 ;
F_122 ( & V_215 -> V_217 ) ;
goto V_39;
}
}
if ( V_155 -> args [ 1 ] ) {
V_155 -> args [ 1 ] = 0 ;
goto V_168;
}
F_122 ( & V_215 -> V_217 ) ;
}
V_155 -> args [ 2 ] = 1 ;
V_39:
if ( V_158 )
F_79 ( V_158 ) ;
return V_2 -> V_72 ;
}
static int
F_123 ( struct V_1 * V_2 , struct V_154 * V_155 )
{
return F_117 ( V_2 , V_155 , true ) ;
}
static int
F_124 ( struct V_192 * V_193 , struct V_1 * V_2 ,
const struct V_103 * V_104 ,
const struct V_8 * const V_182 [] )
{
if ( V_104 -> V_198 & V_199 ) {
struct V_200 V_201 = {
. V_202 = F_123 ,
. V_203 = F_116 ,
} ;
return F_114 ( V_193 , V_2 , V_104 , & V_201 ) ;
}
return - V_186 ;
}
static int
F_125 ( struct V_1 * V_2 , struct V_154 * V_155 )
{
return F_117 ( V_2 , V_155 , false ) ;
}
static int
F_126 ( struct V_192 * V_193 , struct V_1 * V_2 ,
const struct V_103 * V_104 ,
const struct V_8 * const V_182 [] )
{
if ( V_104 -> V_198 & V_199 ) {
struct V_200 V_201 = {
. V_202 = F_125 ,
. V_203 = F_116 ,
} ;
return F_114 ( V_193 , V_2 , V_104 , & V_201 ) ;
}
return - V_186 ;
}
static int
F_127 ( struct V_22 * V_23 ,
enum V_219 V_220 ,
const struct V_8 * V_48 )
{
F_128 (nfnetlink_parse_nat_setup_hook) V_221 ;
int V_133 ;
V_221 = F_21 ( V_222 ) ;
if ( ! V_221 ) {
#ifdef F_129
F_11 () ;
F_130 ( V_110 ) ;
if ( F_131 ( L_1 ) < 0 ) {
F_132 ( V_110 ) ;
F_8 () ;
return - V_186 ;
}
F_132 ( V_110 ) ;
F_8 () ;
if ( V_222 )
return - V_153 ;
#endif
return - V_186 ;
}
V_133 = V_221 ( V_23 , V_220 , V_48 ) ;
if ( V_133 == - V_153 ) {
#ifdef F_129
F_11 () ;
F_130 ( V_110 ) ;
if ( F_131 ( L_2 , F_17 ( V_23 ) ) < 0 ) {
F_132 ( V_110 ) ;
F_8 () ;
return - V_186 ;
}
F_132 ( V_110 ) ;
F_8 () ;
#else
V_133 = - V_186 ;
#endif
}
return V_133 ;
}
static int
F_133 ( struct V_22 * V_23 , const struct V_8 * const V_182 [] )
{
unsigned long V_223 ;
unsigned int V_25 = F_108 ( F_109 ( V_182 [ V_24 ] ) ) ;
V_223 = V_23 -> V_25 ^ V_25 ;
if ( V_223 & ( V_83 | V_224 | V_225 ) )
return - V_226 ;
if ( V_223 & V_227 && ! ( V_25 & V_227 ) )
return - V_226 ;
if ( V_223 & V_228 && ! ( V_25 & V_228 ) )
return - V_226 ;
V_23 -> V_25 |= V_25 & ~ ( V_229 | V_230 ) ;
return 0 ;
}
static int
F_134 ( struct V_22 * V_23 , const struct V_8 * const V_182 [] )
{
#ifdef F_67
int V_7 ;
if ( ! V_182 [ V_231 ] && ! V_182 [ V_232 ] )
return 0 ;
V_7 = F_127 ( V_23 , V_233 ,
V_182 [ V_231 ] ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_127 ( V_23 , V_234 ,
V_182 [ V_232 ] ) ;
return V_7 ;
#else
if ( ! V_182 [ V_231 ] && ! V_182 [ V_232 ] )
return 0 ;
return - V_186 ;
#endif
}
static inline int
F_135 ( struct V_22 * V_23 , const struct V_8 * const V_182 [] )
{
struct V_37 * V_38 ;
struct V_35 * V_36 = F_20 ( V_23 ) ;
char * V_235 = NULL ;
struct V_8 * V_188 = NULL ;
int V_133 ;
if ( V_23 -> V_236 )
return - V_226 ;
V_133 = F_102 ( V_182 [ V_40 ] , & V_235 , & V_188 ) ;
if ( V_133 < 0 )
return V_133 ;
if ( ! strcmp ( V_235 , L_3 ) ) {
if ( V_36 && V_36 -> V_38 ) {
F_136 ( V_23 ) ;
F_137 ( V_36 -> V_38 , NULL ) ;
}
return 0 ;
}
V_38 = F_138 ( V_235 , F_17 ( V_23 ) ,
F_18 ( V_23 ) ) ;
if ( V_38 == NULL ) {
#ifdef F_129
F_122 ( & V_237 ) ;
if ( F_131 ( L_4 , V_235 ) < 0 ) {
F_120 ( & V_237 ) ;
return - V_186 ;
}
F_120 ( & V_237 ) ;
V_38 = F_138 ( V_235 , F_17 ( V_23 ) ,
F_18 ( V_23 ) ) ;
if ( V_38 )
return - V_153 ;
#endif
return - V_186 ;
}
if ( V_36 ) {
if ( V_36 -> V_38 == V_38 ) {
if ( V_38 -> V_238 )
V_38 -> V_238 ( V_188 , V_23 ) ;
return 0 ;
} else
return - V_226 ;
}
return - V_186 ;
}
static inline int
F_139 ( struct V_22 * V_23 , const struct V_8 * const V_182 [] )
{
V_125 V_26 = F_108 ( F_109 ( V_182 [ V_30 ] ) ) ;
if ( ! F_110 ( & V_23 -> V_26 ) )
return - V_239 ;
V_23 -> V_26 . V_27 = V_28 + V_26 * V_29 ;
F_140 ( & V_23 -> V_26 ) ;
return 0 ;
}
static inline int
F_141 ( struct V_22 * V_23 , const struct V_8 * const V_182 [] )
{
const struct V_8 * V_48 = V_182 [ V_33 ] ;
struct V_8 * V_175 [ V_240 + 1 ] ;
struct V_5 * V_6 ;
int V_133 = 0 ;
V_133 = F_94 ( V_175 , V_240 , V_48 , V_241 ) ;
if ( V_133 < 0 )
return V_133 ;
F_8 () ;
V_6 = F_10 ( F_17 ( V_23 ) , F_18 ( V_23 ) ) ;
if ( V_6 -> V_238 )
V_133 = V_6 -> V_238 ( V_175 , V_23 ) ;
F_11 () ;
return V_133 ;
}
static inline int
F_142 ( struct V_85 * V_86 , const struct V_8 * const V_48 )
{
int V_133 ;
struct V_8 * V_182 [ V_242 + 1 ] ;
V_133 = F_94 ( V_182 , V_242 , V_48 , V_243 ) ;
if ( V_133 < 0 )
return V_133 ;
if ( ! V_182 [ V_87 ] )
return - V_181 ;
V_86 -> V_88 =
F_108 ( F_109 ( V_182 [ V_87 ] ) ) ;
if ( ! V_182 [ V_89 ] )
return - V_181 ;
V_86 -> V_90 =
F_108 ( F_109 ( V_182 [ V_89 ] ) ) ;
if ( ! V_182 [ V_91 ] )
return - V_181 ;
V_86 -> V_92 =
F_108 ( F_109 ( V_182 [ V_91 ] ) ) ;
return 0 ;
}
static int
F_143 ( struct V_22 * V_23 ,
const struct V_8 * const V_182 [] )
{
struct V_93 * V_94 = F_45 ( V_23 ) ;
int V_7 = 0 ;
if ( ! V_94 )
return 0 ;
if ( V_182 [ V_96 ] ) {
V_7 = F_142 ( & V_94 -> V_86 [ V_60 ] ,
V_182 [ V_96 ] ) ;
if ( V_7 < 0 )
return V_7 ;
V_23 -> V_25 |= V_95 ;
}
if ( V_182 [ V_97 ] ) {
V_7 = F_142 ( & V_94 -> V_86 [ V_61 ] ,
V_182 [ V_97 ] ) ;
if ( V_7 < 0 )
return V_7 ;
V_23 -> V_25 |= V_95 ;
}
return 0 ;
}
static int
F_144 ( struct V_22 * V_23 , const struct V_8 * const V_182 [] )
{
#ifdef F_145
T_3 V_72 = F_146 ( V_182 [ V_82 ] ) ;
const void * V_171 = V_182 [ V_244 ] ;
if ( V_72 & ( sizeof( T_2 ) - 1 ) )
return - V_181 ;
if ( V_171 ) {
if ( F_146 ( V_182 [ V_244 ] ) == 0 ||
F_146 ( V_182 [ V_244 ] ) != V_72 )
return - V_181 ;
V_171 = F_103 ( V_182 [ V_244 ] ) ;
}
V_72 /= sizeof( T_2 ) ;
return F_147 ( V_23 , F_103 ( V_182 [ V_82 ] ) , V_171 , V_72 ) ;
#else
return - V_186 ;
#endif
}
static int
F_148 ( struct V_22 * V_23 ,
const struct V_8 * const V_182 [] )
{
int V_133 ;
if ( V_182 [ V_232 ] || V_182 [ V_231 ] || V_182 [ V_84 ] )
return - V_186 ;
if ( V_182 [ V_40 ] ) {
V_133 = F_135 ( V_23 , V_182 ) ;
if ( V_133 < 0 )
return V_133 ;
}
if ( V_182 [ V_30 ] ) {
V_133 = F_139 ( V_23 , V_182 ) ;
if ( V_133 < 0 )
return V_133 ;
}
if ( V_182 [ V_24 ] ) {
V_133 = F_133 ( V_23 , V_182 ) ;
if ( V_133 < 0 )
return V_133 ;
}
if ( V_182 [ V_33 ] ) {
V_133 = F_141 ( V_23 , V_182 ) ;
if ( V_133 < 0 )
return V_133 ;
}
#if F_149 ( F_68 )
if ( V_182 [ V_69 ] )
V_23 -> V_70 = F_108 ( F_109 ( V_182 [ V_69 ] ) ) ;
#endif
if ( V_182 [ V_96 ] || V_182 [ V_97 ] ) {
V_133 = F_143 ( V_23 , V_182 ) ;
if ( V_133 < 0 )
return V_133 ;
}
if ( V_182 [ V_82 ] ) {
V_133 = F_144 ( V_23 , V_182 ) ;
if ( V_133 < 0 )
return V_133 ;
}
return 0 ;
}
static struct V_22 *
F_150 ( struct V_131 * V_131 , T_5 V_185 ,
const struct V_8 * const V_182 [] ,
struct V_3 * V_245 ,
struct V_3 * V_246 ,
T_6 V_194 )
{
struct V_22 * V_23 ;
int V_133 = - V_181 ;
struct V_37 * V_38 ;
struct V_62 * V_63 ;
V_23 = F_151 ( V_131 , V_185 , V_245 , V_246 , V_144 ) ;
if ( F_152 ( V_23 ) )
return F_153 ( - V_205 ) ;
if ( ! V_182 [ V_30 ] )
goto V_247;
V_23 -> V_26 . V_27 = F_108 ( F_109 ( V_182 [ V_30 ] ) ) ;
V_23 -> V_26 . V_27 = V_28 + V_23 -> V_26 . V_27 * V_29 ;
F_8 () ;
if ( V_182 [ V_40 ] ) {
char * V_235 = NULL ;
struct V_8 * V_188 = NULL ;
V_133 = F_102 ( V_182 [ V_40 ] , & V_235 , & V_188 ) ;
if ( V_133 < 0 )
goto V_248;
V_38 = F_138 ( V_235 , F_17 ( V_23 ) ,
F_18 ( V_23 ) ) ;
if ( V_38 == NULL ) {
F_11 () ;
#ifdef F_129
if ( F_131 ( L_4 , V_235 ) < 0 ) {
V_133 = - V_186 ;
goto V_247;
}
F_8 () ;
V_38 = F_138 ( V_235 ,
F_17 ( V_23 ) ,
F_18 ( V_23 ) ) ;
if ( V_38 ) {
V_133 = - V_153 ;
goto V_248;
}
F_11 () ;
#endif
V_133 = - V_186 ;
goto V_247;
} else {
struct V_35 * V_36 ;
V_36 = F_154 ( V_23 , V_38 , V_144 ) ;
if ( V_36 == NULL ) {
V_133 = - V_205 ;
goto V_248;
}
if ( V_38 -> V_238 )
V_38 -> V_238 ( V_188 , V_23 ) ;
F_137 ( V_36 -> V_38 , V_38 ) ;
}
} else {
V_133 = F_155 ( V_23 , NULL , V_144 ) ;
if ( V_133 < 0 )
goto V_248;
}
V_133 = F_134 ( V_23 , V_182 ) ;
if ( V_133 < 0 )
goto V_248;
F_156 ( V_23 , V_144 ) ;
F_157 ( V_23 , V_144 ) ;
F_158 ( V_23 , 0 , 0 , V_144 ) ;
F_159 ( V_23 ) ;
V_23 -> V_25 |= V_224 ;
if ( V_182 [ V_24 ] ) {
V_133 = F_133 ( V_23 , V_182 ) ;
if ( V_133 < 0 )
goto V_248;
}
if ( V_182 [ V_96 ] || V_182 [ V_97 ] ) {
V_133 = F_143 ( V_23 , V_182 ) ;
if ( V_133 < 0 )
goto V_248;
}
memset ( & V_23 -> V_249 , 0 , sizeof( V_23 -> V_249 ) ) ;
if ( V_182 [ V_33 ] ) {
V_133 = F_141 ( V_23 , V_182 ) ;
if ( V_133 < 0 )
goto V_248;
}
#if F_149 ( F_68 )
if ( V_182 [ V_69 ] )
V_23 -> V_70 = F_108 ( F_109 ( V_182 [ V_69 ] ) ) ;
#endif
if ( V_182 [ V_84 ] ) {
struct V_3 V_236 ;
struct V_159 * V_250 ;
struct V_22 * V_251 ;
V_133 = F_98 ( V_182 , & V_236 , V_84 , V_194 ) ;
if ( V_133 < 0 )
goto V_248;
V_250 = F_107 ( V_131 , V_185 , & V_236 ) ;
if ( V_250 == NULL ) {
V_133 = - V_195 ;
goto V_248;
}
V_251 = F_88 ( V_250 ) ;
F_160 ( V_252 , & V_23 -> V_25 ) ;
V_23 -> V_236 = V_251 ;
}
V_63 = F_31 ( V_23 ) ;
if ( V_63 )
V_63 -> V_66 = F_161 ( F_162 () ) ;
V_133 = F_163 ( V_23 ) ;
if ( V_133 < 0 )
goto V_248;
F_11 () ;
return V_23 ;
V_248:
F_11 () ;
V_247:
F_164 ( V_23 ) ;
return F_153 ( V_133 ) ;
}
static int
F_165 ( struct V_192 * V_193 , struct V_1 * V_2 ,
const struct V_103 * V_104 ,
const struct V_8 * const V_182 [] )
{
struct V_131 * V_131 = F_82 ( V_193 ) ;
struct V_3 V_245 , V_246 ;
struct V_159 * V_160 = NULL ;
struct V_105 * V_106 = F_51 ( V_104 ) ;
struct V_22 * V_23 ;
V_124 V_194 = V_106 -> V_113 ;
T_5 V_185 ;
int V_133 ;
V_133 = F_99 ( V_182 [ V_119 ] , & V_185 ) ;
if ( V_133 < 0 )
return V_133 ;
if ( V_182 [ V_117 ] ) {
V_133 = F_98 ( V_182 , & V_245 , V_117 , V_194 ) ;
if ( V_133 < 0 )
return V_133 ;
}
if ( V_182 [ V_118 ] ) {
V_133 = F_98 ( V_182 , & V_246 , V_118 , V_194 ) ;
if ( V_133 < 0 )
return V_133 ;
}
if ( V_182 [ V_117 ] )
V_160 = F_107 ( V_131 , V_185 , & V_245 ) ;
else if ( V_182 [ V_118 ] )
V_160 = F_107 ( V_131 , V_185 , & V_246 ) ;
if ( V_160 == NULL ) {
V_133 = - V_195 ;
if ( V_104 -> V_198 & V_139 ) {
enum V_253 V_128 ;
if ( ! V_182 [ V_117 ] || ! V_182 [ V_118 ] )
return - V_181 ;
V_23 = F_150 ( V_131 , V_185 , V_182 , & V_245 ,
& V_246 , V_194 ) ;
if ( F_152 ( V_23 ) )
return F_166 ( V_23 ) ;
V_133 = 0 ;
if ( F_167 ( V_252 , & V_23 -> V_25 ) )
V_128 = V_138 ;
else
V_128 = V_137 ;
if ( V_182 [ V_82 ] &&
F_144 ( V_23 , V_182 ) == 0 )
V_128 |= ( 1 << V_149 ) ;
F_168 ( ( 1 << V_254 ) |
( 1 << V_255 ) |
( 1 << V_147 ) |
( 1 << V_146 ) |
( 1 << V_150 ) |
( 1 << V_151 ) | V_128 ,
V_23 , F_89 ( V_2 ) . V_102 ,
F_106 ( V_104 ) ) ;
F_79 ( V_23 ) ;
}
return V_133 ;
}
V_133 = - V_256 ;
V_23 = F_88 ( V_160 ) ;
if ( ! ( V_104 -> V_198 & V_140 ) ) {
F_120 ( & V_237 ) ;
V_133 = F_148 ( V_23 , V_182 ) ;
F_122 ( & V_237 ) ;
if ( V_133 == 0 ) {
F_168 ( ( 1 << V_254 ) |
( 1 << V_255 ) |
( 1 << V_147 ) |
( 1 << V_149 ) |
( 1 << V_146 ) |
( 1 << V_150 ) |
( 1 << V_151 ) ,
V_23 , F_89 ( V_2 ) . V_102 ,
F_106 ( V_104 ) ) ;
}
}
F_79 ( V_23 ) ;
return V_133 ;
}
static int
F_169 ( struct V_1 * V_2 , T_2 V_102 , T_2 V_86 ,
T_7 V_210 , const struct V_257 * V_258 )
{
struct V_103 * V_104 ;
struct V_105 * V_106 ;
unsigned int V_107 = V_102 ? V_108 : 0 , V_109 ;
V_109 = ( V_110 << 8 | V_259 ) ;
V_104 = F_50 ( V_2 , V_102 , V_86 , V_109 , sizeof( * V_106 ) , V_107 ) ;
if ( V_104 == NULL )
goto V_112;
V_106 = F_51 ( V_104 ) ;
V_106 -> V_113 = V_260 ;
V_106 -> V_114 = V_115 ;
V_106 -> V_116 = F_55 ( V_210 ) ;
if ( F_13 ( V_2 , V_261 , F_14 ( V_258 -> V_262 ) ) ||
F_13 ( V_2 , V_263 , F_14 ( V_258 -> V_264 ) ) ||
F_13 ( V_2 , V_265 , F_14 ( V_258 -> V_266 ) ) ||
F_13 ( V_2 , V_267 , F_14 ( V_258 -> V_268 ) ) ||
F_13 ( V_2 , V_269 , F_14 ( V_258 -> V_270 ) ) ||
F_13 ( V_2 , V_271 , F_14 ( V_258 -> V_272 ) ) ||
F_13 ( V_2 , V_273 , F_14 ( V_258 -> V_274 ) ) ||
F_13 ( V_2 , V_275 , F_14 ( V_258 -> V_276 ) ) ||
F_13 ( V_2 , V_277 ,
F_14 ( V_258 -> V_278 ) ) ||
F_13 ( V_2 , V_279 , F_14 ( V_258 -> V_280 ) ) ||
F_13 ( V_2 , V_281 , F_14 ( V_258 -> V_282 ) ) ||
F_13 ( V_2 , V_283 , F_14 ( V_258 -> error ) ) ||
F_13 ( V_2 , V_284 ,
F_14 ( V_258 -> V_285 ) ) )
goto V_12;
F_56 ( V_2 , V_104 ) ;
return V_2 -> V_72 ;
V_12:
V_112:
F_57 ( V_2 , V_104 ) ;
return - 1 ;
}
static int
F_170 ( struct V_1 * V_2 , struct V_154 * V_155 )
{
int V_210 ;
struct V_131 * V_131 = F_82 ( V_2 -> V_157 ) ;
if ( V_155 -> args [ 0 ] == V_213 )
return 0 ;
for ( V_210 = V_155 -> args [ 0 ] ; V_210 < V_213 ; V_210 ++ ) {
const struct V_257 * V_258 ;
if ( ! F_118 ( V_210 ) )
continue;
V_258 = F_119 ( V_131 -> V_23 . V_286 , V_210 ) ;
if ( F_169 ( V_2 ,
F_89 ( V_155 -> V_2 ) . V_102 ,
V_155 -> V_104 -> V_173 ,
V_210 , V_258 ) < 0 )
break;
}
V_155 -> args [ 0 ] = V_210 ;
return V_2 -> V_72 ;
}
static int
F_171 ( struct V_192 * V_193 , struct V_1 * V_2 ,
const struct V_103 * V_104 ,
const struct V_8 * const V_182 [] )
{
if ( V_104 -> V_198 & V_199 ) {
struct V_200 V_201 = {
. V_202 = F_170 ,
} ;
return F_114 ( V_193 , V_2 , V_104 , & V_201 ) ;
}
return 0 ;
}
static int
F_172 ( struct V_1 * V_2 , T_2 V_102 , T_2 V_86 , T_2 type ,
struct V_131 * V_131 )
{
struct V_103 * V_104 ;
struct V_105 * V_106 ;
unsigned int V_107 = V_102 ? V_108 : 0 , V_109 ;
unsigned int V_287 = F_48 ( & V_131 -> V_23 . V_288 ) ;
V_109 = ( V_110 << 8 | V_289 ) ;
V_104 = F_50 ( V_2 , V_102 , V_86 , V_109 , sizeof( * V_106 ) , V_107 ) ;
if ( V_104 == NULL )
goto V_112;
V_106 = F_51 ( V_104 ) ;
V_106 -> V_113 = V_260 ;
V_106 -> V_114 = V_115 ;
V_106 -> V_116 = 0 ;
if ( F_13 ( V_2 , V_290 , F_14 ( V_287 ) ) )
goto V_12;
F_56 ( V_2 , V_104 ) ;
return V_2 -> V_72 ;
V_12:
V_112:
F_57 ( V_2 , V_104 ) ;
return - 1 ;
}
static int
F_173 ( struct V_192 * V_193 , struct V_1 * V_2 ,
const struct V_103 * V_104 ,
const struct V_8 * const V_182 [] )
{
struct V_1 * V_197 ;
int V_133 ;
V_197 = F_74 ( V_206 , V_207 ) ;
if ( V_197 == NULL )
return - V_205 ;
V_133 = F_172 ( V_197 , F_89 ( V_2 ) . V_102 ,
V_104 -> V_173 ,
F_90 ( V_104 -> V_174 ) ,
F_82 ( V_2 -> V_157 ) ) ;
if ( V_133 <= 0 )
goto free;
V_133 = F_115 ( V_193 , V_197 , F_89 ( V_2 ) . V_102 , V_208 ) ;
if ( V_133 < 0 )
goto V_39;
return 0 ;
free:
F_76 ( V_197 ) ;
V_39:
return V_133 == - V_153 ? - V_152 : V_133 ;
}
static T_3
F_174 ( const struct V_22 * V_23 )
{
return 3 * F_38 ( 0 )
+ 3 * F_38 ( 0 )
+ 3 * F_38 ( 0 )
+ 3 * F_38 ( sizeof( V_124 ) )
+ F_38 ( sizeof( V_125 ) )
+ F_38 ( sizeof( V_125 ) )
+ F_38 ( sizeof( V_125 ) )
+ F_38 ( 0 )
+ F_38 ( 0 )
+ F_38 ( V_126 )
+ F_61 ( V_23 )
#ifdef F_67
+ 2 * F_38 ( 0 )
+ 6 * F_38 ( sizeof( V_125 ) )
#endif
#ifdef F_68
+ F_38 ( sizeof( V_125 ) )
#endif
#ifdef F_69
+ F_38 ( sizeof( V_127 ) )
#endif
+ F_58 ( V_23 )
;
}
static int
F_175 ( struct V_1 * V_2 , struct V_22 * V_23 )
{
struct V_8 * V_9 ;
F_8 () ;
V_9 = F_2 ( V_2 , V_117 | V_11 ) ;
if ( ! V_9 )
goto V_12;
if ( F_7 ( V_2 , F_52 ( V_23 , V_60 ) ) < 0 )
goto V_12;
F_5 ( V_2 , V_9 ) ;
V_9 = F_2 ( V_2 , V_118 | V_11 ) ;
if ( ! V_9 )
goto V_12;
if ( F_7 ( V_2 , F_52 ( V_23 , V_61 ) ) < 0 )
goto V_12;
F_5 ( V_2 , V_9 ) ;
if ( F_53 ( V_23 ) ) {
if ( F_54 ( V_2 , V_119 , F_55 ( F_53 ( V_23 ) ) ) )
goto V_12;
}
if ( F_46 ( V_2 , V_23 ) < 0 )
goto V_12;
if ( F_12 ( V_2 , V_23 ) < 0 )
goto V_12;
if ( F_15 ( V_2 , V_23 ) < 0 )
goto V_12;
if ( F_16 ( V_2 , V_23 ) < 0 )
goto V_12;
if ( F_19 ( V_2 , V_23 ) < 0 )
goto V_12;
#ifdef F_62
if ( V_23 -> V_74 && F_33 ( V_2 , V_23 ) < 0 )
goto V_12;
#endif
if ( V_23 -> V_236 && F_41 ( V_2 , V_23 ) < 0 )
goto V_12;
if ( ( V_23 -> V_25 & V_95 ) &&
F_44 ( V_2 , V_23 ) < 0 )
goto V_12;
#ifdef F_68
if ( V_23 -> V_70 && F_32 ( V_2 , V_23 ) < 0 )
goto V_12;
#endif
if ( F_39 ( V_2 , V_23 ) < 0 )
goto V_12;
F_11 () ;
return 0 ;
V_12:
F_11 () ;
return - V_291 ;
}
static int
F_176 ( const struct V_8 * V_182 [] , struct V_22 * V_23 )
{
int V_133 ;
if ( V_182 [ V_30 ] ) {
V_133 = F_139 ( V_23 , V_182 ) ;
if ( V_133 < 0 )
return V_133 ;
}
if ( V_182 [ V_24 ] ) {
V_133 = F_133 ( V_23 , V_182 ) ;
if ( V_133 < 0 )
return V_133 ;
}
if ( V_182 [ V_40 ] ) {
V_133 = F_135 ( V_23 , V_182 ) ;
if ( V_133 < 0 )
return V_133 ;
}
if ( V_182 [ V_82 ] ) {
V_133 = F_144 ( V_23 , V_182 ) ;
if ( V_133 < 0 )
return V_133 ;
}
#if F_149 ( F_68 )
if ( V_182 [ V_69 ] ) {
T_2 V_171 = 0 , V_70 , V_292 ;
if ( V_182 [ V_204 ] )
V_171 = ~ F_108 ( F_109 ( V_182 [ V_204 ] ) ) ;
V_70 = F_108 ( F_109 ( V_182 [ V_69 ] ) ) ;
V_292 = ( V_23 -> V_70 & V_171 ) ^ V_70 ;
if ( V_292 != V_23 -> V_70 )
V_23 -> V_70 = V_292 ;
}
#endif
return 0 ;
}
static int
F_177 ( const struct V_8 * V_48 , struct V_22 * V_23 )
{
struct V_8 * V_182 [ V_293 + 1 ] ;
int V_7 ;
V_7 = F_94 ( V_182 , V_293 , V_48 , V_294 ) ;
if ( V_7 < 0 )
return V_7 ;
F_120 ( & V_237 ) ;
V_7 = F_176 ( ( const struct V_8 * * ) V_182 , V_23 ) ;
F_122 ( & V_237 ) ;
return V_7 ;
}
static int F_178 ( const struct V_8 * const * V_182 ,
const struct V_22 * V_23 ,
struct V_3 * V_4 ,
struct V_3 * V_171 )
{
int V_133 ;
V_133 = F_98 ( V_182 , V_4 , V_295 ,
F_17 ( V_23 ) ) ;
if ( V_133 < 0 )
return V_133 ;
return F_98 ( V_182 , V_171 , V_296 ,
F_17 ( V_23 ) ) ;
}
static int
F_179 ( const struct V_8 * V_48 , struct V_22 * V_23 ,
T_2 V_102 , T_2 V_143 )
{
struct V_8 * V_182 [ V_297 + 1 ] ;
struct V_3 V_4 , V_171 ;
struct V_37 * V_38 = NULL ;
struct V_298 * exp ;
int V_133 ;
V_133 = F_94 ( V_182 , V_297 , V_48 , V_299 ) ;
if ( V_133 < 0 )
return V_133 ;
V_133 = F_178 ( ( const struct V_8 * const * ) V_182 ,
V_23 , & V_4 , & V_171 ) ;
if ( V_133 < 0 )
return V_133 ;
if ( V_182 [ V_300 ] ) {
const char * V_235 = F_103 ( V_182 [ V_300 ] ) ;
V_38 = F_138 ( V_235 , F_17 ( V_23 ) ,
F_18 ( V_23 ) ) ;
if ( V_38 == NULL )
return - V_186 ;
}
exp = F_180 ( ( const struct V_8 * const * ) V_182 , V_23 ,
V_38 , & V_4 , & V_171 ) ;
if ( F_152 ( exp ) )
return F_166 ( exp ) ;
V_133 = F_181 ( exp , V_102 , V_143 ) ;
if ( V_133 < 0 ) {
F_182 ( exp ) ;
return V_133 ;
}
return 0 ;
}
static inline int
F_183 ( struct V_1 * V_2 ,
const struct V_3 * V_4 ,
enum V_301 type )
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
F_184 ( struct V_1 * V_2 ,
const struct V_3 * V_4 ,
const struct V_302 * V_171 )
{
int V_7 ;
struct V_17 * V_18 ;
struct V_5 * V_6 ;
struct V_3 V_303 ;
struct V_8 * V_9 ;
memset ( & V_303 , 0xFF , sizeof( V_303 ) ) ;
memcpy ( & V_303 . V_20 . V_194 , & V_171 -> V_20 . V_194 , sizeof( V_303 . V_20 . V_194 ) ) ;
V_303 . V_20 . V_304 . V_305 = V_171 -> V_20 . V_304 . V_305 ;
V_303 . V_14 . V_15 = V_4 -> V_14 . V_15 ;
V_9 = F_2 ( V_2 , V_296 | V_11 ) ;
if ( ! V_9 )
goto V_12;
F_8 () ;
V_18 = F_9 ( V_4 -> V_20 . V_21 ) ;
V_7 = F_6 ( V_2 , & V_303 , V_18 ) ;
if ( V_7 >= 0 ) {
V_6 = F_10 ( V_4 -> V_20 . V_21 ,
V_4 -> V_14 . V_15 ) ;
V_7 = F_1 ( V_2 , & V_303 , V_6 ) ;
}
F_11 () ;
if ( F_185 ( V_7 < 0 ) )
goto V_12;
F_5 ( V_2 , V_9 ) ;
return 0 ;
V_12:
return - 1 ;
}
static int
F_186 ( struct V_1 * V_2 ,
const struct V_298 * exp )
{
struct V_22 * V_236 = exp -> V_236 ;
long V_26 = ( ( long ) exp -> V_26 . V_27 - ( long ) V_28 ) / V_29 ;
struct V_35 * V_36 ;
#ifdef F_67
struct V_8 * V_9 ;
struct V_3 V_306 = {} ;
#endif
struct V_307 * V_308 ;
if ( V_26 < 0 )
V_26 = 0 ;
if ( F_183 ( V_2 , & exp -> V_4 , V_295 ) < 0 )
goto V_12;
if ( F_184 ( V_2 , & exp -> V_4 , & exp -> V_171 ) < 0 )
goto V_12;
if ( F_183 ( V_2 ,
& V_236 -> V_309 [ V_60 ] . V_4 ,
V_310 ) < 0 )
goto V_12;
#ifdef F_67
if ( ! F_187 ( & exp -> V_311 , & V_312 ) ||
exp -> V_313 . V_305 ) {
V_9 = F_2 ( V_2 , V_314 | V_11 ) ;
if ( ! V_9 )
goto V_12;
if ( F_13 ( V_2 , V_315 , F_14 ( exp -> V_46 ) ) )
goto V_12;
V_306 . V_20 . V_21 = F_17 ( V_236 ) ;
V_306 . V_20 . V_194 = exp -> V_311 ;
V_306 . V_14 . V_15 = F_18 ( V_236 ) ;
V_306 . V_20 . V_304 = exp -> V_313 ;
if ( F_183 ( V_2 , & V_306 ,
V_316 ) < 0 )
goto V_12;
F_5 ( V_2 , V_9 ) ;
}
#endif
if ( F_13 ( V_2 , V_317 , F_14 ( V_26 ) ) ||
F_13 ( V_2 , V_318 , F_14 ( ( unsigned long ) exp ) ) ||
F_13 ( V_2 , V_319 , F_14 ( exp -> V_107 ) ) ||
F_13 ( V_2 , V_320 , F_14 ( exp -> V_321 ) ) )
goto V_12;
V_36 = F_20 ( V_236 ) ;
if ( V_36 ) {
struct V_37 * V_38 ;
V_38 = F_21 ( V_36 -> V_38 ) ;
if ( V_38 &&
F_22 ( V_2 , V_300 , V_38 -> V_42 ) )
goto V_12;
}
V_308 = F_188 ( exp -> V_322 ) ;
if ( V_308 != NULL &&
F_22 ( V_2 , V_323 , V_308 -> V_42 ) )
goto V_12;
return 0 ;
V_12:
return - 1 ;
}
static int
F_189 ( struct V_1 * V_2 , T_2 V_102 , T_2 V_86 ,
int V_109 , const struct V_298 * exp )
{
struct V_103 * V_104 ;
struct V_105 * V_106 ;
unsigned int V_107 = V_102 ? V_108 : 0 ;
V_109 |= V_324 << 8 ;
V_104 = F_50 ( V_2 , V_102 , V_86 , V_109 , sizeof( * V_106 ) , V_107 ) ;
if ( V_104 == NULL )
goto V_112;
V_106 = F_51 ( V_104 ) ;
V_106 -> V_113 = exp -> V_4 . V_20 . V_21 ;
V_106 -> V_114 = V_115 ;
V_106 -> V_116 = 0 ;
if ( F_186 ( V_2 , exp ) < 0 )
goto V_12;
F_56 ( V_2 , V_104 ) ;
return V_2 -> V_72 ;
V_112:
V_12:
F_57 ( V_2 , V_104 ) ;
return - 1 ;
}
static int
F_190 ( unsigned int V_128 , struct V_325 * V_130 )
{
struct V_298 * exp = V_130 -> exp ;
struct V_131 * V_131 = F_191 ( exp ) ;
struct V_103 * V_104 ;
struct V_105 * V_106 ;
struct V_1 * V_2 ;
unsigned int type , V_132 ;
int V_107 = 0 ;
if ( V_128 & ( 1 << V_326 ) ) {
type = V_327 ;
V_132 = V_328 ;
} else if ( V_128 & ( 1 << V_329 ) ) {
type = V_330 ;
V_107 = V_139 | V_140 ;
V_132 = V_331 ;
} else
return 0 ;
if ( ! V_130 -> V_143 && ! F_73 ( V_131 , V_132 ) )
return 0 ;
V_2 = F_74 ( V_206 , V_144 ) ;
if ( V_2 == NULL )
goto V_145;
type |= V_324 << 8 ;
V_104 = F_50 ( V_2 , V_130 -> V_102 , 0 , type , sizeof( * V_106 ) , V_107 ) ;
if ( V_104 == NULL )
goto V_112;
V_106 = F_51 ( V_104 ) ;
V_106 -> V_113 = exp -> V_4 . V_20 . V_21 ;
V_106 -> V_114 = V_115 ;
V_106 -> V_116 = 0 ;
F_8 () ;
if ( F_186 ( V_2 , exp ) < 0 )
goto V_12;
F_11 () ;
F_56 ( V_2 , V_104 ) ;
F_75 ( V_2 , V_131 , V_130 -> V_102 , V_132 , V_130 -> V_143 , V_144 ) ;
return 0 ;
V_12:
F_11 () ;
F_57 ( V_2 , V_104 ) ;
V_112:
F_76 ( V_2 ) ;
V_145:
F_77 ( V_131 , 0 , 0 , - V_152 ) ;
return 0 ;
}
static int F_192 ( struct V_154 * V_155 )
{
if ( V_155 -> args [ 1 ] )
F_182 ( (struct V_298 * ) V_155 -> args [ 1 ] ) ;
return 0 ;
}
static int
F_193 ( struct V_1 * V_2 , struct V_154 * V_155 )
{
struct V_131 * V_131 = F_82 ( V_2 -> V_157 ) ;
struct V_298 * exp , * V_158 ;
struct V_105 * V_106 = F_51 ( V_155 -> V_104 ) ;
V_124 V_18 = V_106 -> V_113 ;
F_8 () ;
V_158 = (struct V_298 * ) V_155 -> args [ 1 ] ;
for (; V_155 -> args [ 0 ] < V_332 ; V_155 -> args [ 0 ] ++ ) {
V_168:
F_194 (exp, &net->ct.expect_hash[cb->args[0]],
hnode) {
if ( V_18 && exp -> V_4 . V_20 . V_21 != V_18 )
continue;
if ( V_155 -> args [ 1 ] ) {
if ( exp != V_158 )
continue;
V_155 -> args [ 1 ] = 0 ;
}
if ( F_189 ( V_2 ,
F_89 ( V_155 -> V_2 ) . V_102 ,
V_155 -> V_104 -> V_173 ,
V_330 ,
exp ) < 0 ) {
if ( ! F_121 ( & exp -> V_101 ) )
continue;
V_155 -> args [ 1 ] = ( unsigned long ) exp ;
goto V_39;
}
}
if ( V_155 -> args [ 1 ] ) {
V_155 -> args [ 1 ] = 0 ;
goto V_168;
}
}
V_39:
F_11 () ;
if ( V_158 )
F_182 ( V_158 ) ;
return V_2 -> V_72 ;
}
static int
F_195 ( struct V_1 * V_2 , struct V_154 * V_155 )
{
struct V_298 * exp , * V_158 ;
struct V_105 * V_106 = F_51 ( V_155 -> V_104 ) ;
struct V_22 * V_23 = V_155 -> V_156 ;
struct V_35 * V_36 = F_20 ( V_23 ) ;
V_124 V_18 = V_106 -> V_113 ;
if ( V_155 -> args [ 0 ] )
return 0 ;
F_8 () ;
V_158 = (struct V_298 * ) V_155 -> args [ 1 ] ;
V_168:
F_194 (exp, &help->expectations, lnode) {
if ( V_18 && exp -> V_4 . V_20 . V_21 != V_18 )
continue;
if ( V_155 -> args [ 1 ] ) {
if ( exp != V_158 )
continue;
V_155 -> args [ 1 ] = 0 ;
}
if ( F_189 ( V_2 , F_89 ( V_155 -> V_2 ) . V_102 ,
V_155 -> V_104 -> V_173 ,
V_330 ,
exp ) < 0 ) {
if ( ! F_121 ( & exp -> V_101 ) )
continue;
V_155 -> args [ 1 ] = ( unsigned long ) exp ;
goto V_39;
}
}
if ( V_155 -> args [ 1 ] ) {
V_155 -> args [ 1 ] = 0 ;
goto V_168;
}
V_155 -> args [ 0 ] = 1 ;
V_39:
F_11 () ;
if ( V_158 )
F_182 ( V_158 ) ;
return V_2 -> V_72 ;
}
static int F_196 ( struct V_192 * V_193 , struct V_1 * V_2 ,
const struct V_103 * V_104 ,
const struct V_8 * const V_182 [] )
{
int V_133 ;
struct V_131 * V_131 = F_82 ( V_193 ) ;
struct V_105 * V_106 = F_51 ( V_104 ) ;
V_124 V_194 = V_106 -> V_113 ;
struct V_3 V_4 ;
struct V_159 * V_160 ;
struct V_22 * V_23 ;
T_5 V_185 = 0 ;
struct V_200 V_201 = {
. V_202 = F_195 ,
. V_203 = F_192 ,
} ;
V_133 = F_98 ( V_182 , & V_4 , V_310 , V_194 ) ;
if ( V_133 < 0 )
return V_133 ;
if ( V_182 [ V_333 ] ) {
V_133 = F_99 ( V_182 [ V_333 ] , & V_185 ) ;
if ( V_133 < 0 )
return V_133 ;
}
V_160 = F_107 ( V_131 , V_185 , & V_4 ) ;
if ( ! V_160 )
return - V_195 ;
V_23 = F_88 ( V_160 ) ;
V_201 . V_156 = V_23 ;
V_133 = F_114 ( V_193 , V_2 , V_104 , & V_201 ) ;
F_79 ( V_23 ) ;
return V_133 ;
}
static int
F_197 ( struct V_192 * V_193 , struct V_1 * V_2 ,
const struct V_103 * V_104 ,
const struct V_8 * const V_182 [] )
{
struct V_131 * V_131 = F_82 ( V_193 ) ;
struct V_3 V_4 ;
struct V_298 * exp ;
struct V_1 * V_197 ;
struct V_105 * V_106 = F_51 ( V_104 ) ;
V_124 V_194 = V_106 -> V_113 ;
T_5 V_185 ;
int V_133 ;
if ( V_104 -> V_198 & V_199 ) {
if ( V_182 [ V_310 ] )
return F_196 ( V_193 , V_2 , V_104 , V_182 ) ;
else {
struct V_200 V_201 = {
. V_202 = F_193 ,
. V_203 = F_192 ,
} ;
return F_114 ( V_193 , V_2 , V_104 , & V_201 ) ;
}
}
V_133 = F_99 ( V_182 [ V_333 ] , & V_185 ) ;
if ( V_133 < 0 )
return V_133 ;
if ( V_182 [ V_295 ] )
V_133 = F_98 ( V_182 , & V_4 , V_295 , V_194 ) ;
else if ( V_182 [ V_310 ] )
V_133 = F_98 ( V_182 , & V_4 , V_310 , V_194 ) ;
else
return - V_181 ;
if ( V_133 < 0 )
return V_133 ;
exp = F_198 ( V_131 , V_185 , & V_4 ) ;
if ( ! exp )
return - V_195 ;
if ( V_182 [ V_318 ] ) {
T_8 V_196 = F_109 ( V_182 [ V_318 ] ) ;
if ( F_108 ( V_196 ) != ( T_2 ) ( unsigned long ) exp ) {
F_182 ( exp ) ;
return - V_195 ;
}
}
V_133 = - V_205 ;
V_197 = F_74 ( V_206 , V_207 ) ;
if ( V_197 == NULL ) {
F_182 ( exp ) ;
goto V_39;
}
F_8 () ;
V_133 = F_189 ( V_197 , F_89 ( V_2 ) . V_102 ,
V_104 -> V_173 , V_330 , exp ) ;
F_11 () ;
F_182 ( exp ) ;
if ( V_133 <= 0 )
goto free;
V_133 = F_115 ( V_193 , V_197 , F_89 ( V_2 ) . V_102 , V_208 ) ;
if ( V_133 < 0 )
goto V_39;
return 0 ;
free:
F_76 ( V_197 ) ;
V_39:
return V_133 == - V_153 ? - V_152 : V_133 ;
}
static int
F_199 ( struct V_192 * V_193 , struct V_1 * V_2 ,
const struct V_103 * V_104 ,
const struct V_8 * const V_182 [] )
{
struct V_131 * V_131 = F_82 ( V_193 ) ;
struct V_298 * exp ;
struct V_3 V_4 ;
struct V_105 * V_106 = F_51 ( V_104 ) ;
struct V_334 * V_335 ;
V_124 V_194 = V_106 -> V_113 ;
unsigned int V_80 ;
T_5 V_185 ;
int V_133 ;
if ( V_182 [ V_295 ] ) {
V_133 = F_99 ( V_182 [ V_333 ] , & V_185 ) ;
if ( V_133 < 0 )
return V_133 ;
V_133 = F_98 ( V_182 , & V_4 , V_295 , V_194 ) ;
if ( V_133 < 0 )
return V_133 ;
exp = F_198 ( V_131 , V_185 , & V_4 ) ;
if ( ! exp )
return - V_195 ;
if ( V_182 [ V_318 ] ) {
T_8 V_196 = F_109 ( V_182 [ V_318 ] ) ;
if ( F_108 ( V_196 ) != ( T_2 ) ( unsigned long ) exp ) {
F_182 ( exp ) ;
return - V_195 ;
}
}
F_120 ( & V_237 ) ;
if ( F_110 ( & exp -> V_26 ) ) {
F_200 ( exp , F_89 ( V_2 ) . V_102 ,
F_106 ( V_104 ) ) ;
F_182 ( exp ) ;
}
F_122 ( & V_237 ) ;
F_182 ( exp ) ;
} else if ( V_182 [ V_300 ] ) {
char * V_42 = F_103 ( V_182 [ V_300 ] ) ;
struct V_35 * V_336 ;
F_120 ( & V_237 ) ;
for ( V_80 = 0 ; V_80 < V_332 ; V_80 ++ ) {
F_201 (exp, next,
&net->ct.expect_hash[i],
hnode) {
V_336 = F_20 ( exp -> V_236 ) ;
if ( ! strcmp ( V_336 -> V_38 -> V_42 , V_42 ) &&
F_110 ( & exp -> V_26 ) ) {
F_200 ( exp ,
F_89 ( V_2 ) . V_102 ,
F_106 ( V_104 ) ) ;
F_182 ( exp ) ;
}
}
}
F_122 ( & V_237 ) ;
} else {
F_120 ( & V_237 ) ;
for ( V_80 = 0 ; V_80 < V_332 ; V_80 ++ ) {
F_201 (exp, next,
&net->ct.expect_hash[i],
hnode) {
if ( F_110 ( & exp -> V_26 ) ) {
F_200 ( exp ,
F_89 ( V_2 ) . V_102 ,
F_106 ( V_104 ) ) ;
F_182 ( exp ) ;
}
}
}
F_122 ( & V_237 ) ;
}
return 0 ;
}
static int
F_202 ( struct V_298 * V_337 ,
const struct V_8 * const V_182 [] )
{
if ( V_182 [ V_317 ] ) {
if ( ! F_110 ( & V_337 -> V_26 ) )
return - V_239 ;
V_337 -> V_26 . V_27 = V_28 +
F_108 ( F_109 ( V_182 [ V_317 ] ) ) * V_29 ;
F_140 ( & V_337 -> V_26 ) ;
}
return 0 ;
}
static int
F_203 ( const struct V_8 * V_48 ,
struct V_298 * exp ,
V_124 V_194 )
{
#ifdef F_67
struct V_8 * V_175 [ V_338 + 1 ] ;
struct V_3 V_306 = {} ;
int V_133 ;
V_133 = F_94 ( V_175 , V_338 , V_48 , V_339 ) ;
if ( V_133 < 0 )
return V_133 ;
if ( ! V_175 [ V_315 ] || ! V_175 [ V_316 ] )
return - V_181 ;
V_133 = F_98 ( ( const struct V_8 * const * ) V_175 ,
& V_306 , V_316 , V_194 ) ;
if ( V_133 < 0 )
return V_133 ;
exp -> V_311 = V_306 . V_20 . V_194 ;
exp -> V_313 = V_306 . V_20 . V_304 ;
exp -> V_46 = F_108 ( F_109 ( V_175 [ V_315 ] ) ) ;
return 0 ;
#else
return - V_186 ;
#endif
}
static struct V_298 *
F_180 ( const struct V_8 * const V_182 [] , struct V_22 * V_23 ,
struct V_37 * V_38 ,
struct V_3 * V_4 ,
struct V_3 * V_171 )
{
V_125 V_321 = 0 ;
struct V_298 * exp ;
struct V_35 * V_36 ;
int V_133 ;
if ( V_182 [ V_320 ] && V_38 ) {
V_321 = F_108 ( F_109 ( V_182 [ V_320 ] ) ) ;
if ( V_321 > V_38 -> V_340 )
return F_153 ( - V_181 ) ;
}
exp = F_204 ( V_23 ) ;
if ( ! exp )
return F_153 ( - V_205 ) ;
V_36 = F_20 ( V_23 ) ;
if ( ! V_36 ) {
if ( ! V_182 [ V_317 ] ) {
V_133 = - V_181 ;
goto V_341;
}
exp -> V_26 . V_27 =
V_28 + F_108 ( F_109 ( V_182 [ V_317 ] ) ) * V_29 ;
exp -> V_107 = V_342 ;
if ( V_182 [ V_319 ] ) {
exp -> V_107 |=
F_108 ( F_109 ( V_182 [ V_319 ] ) ) ;
}
} else {
if ( V_182 [ V_319 ] ) {
exp -> V_107 = F_108 ( F_109 ( V_182 [ V_319 ] ) ) ;
exp -> V_107 &= ~ V_342 ;
} else
exp -> V_107 = 0 ;
}
if ( V_182 [ V_323 ] ) {
const char * V_42 = F_103 ( V_182 [ V_323 ] ) ;
struct V_307 * V_308 ;
V_308 = F_205 ( V_42 ) ;
if ( V_308 == NULL ) {
V_133 = - V_181 ;
goto V_341;
}
exp -> V_322 = V_308 -> V_322 ;
} else
exp -> V_322 = NULL ;
exp -> V_321 = V_321 ;
exp -> V_236 = V_23 ;
exp -> V_38 = V_38 ;
exp -> V_4 = * V_4 ;
exp -> V_171 . V_20 . V_194 = V_171 -> V_20 . V_194 ;
exp -> V_171 . V_20 . V_304 . V_305 = V_171 -> V_20 . V_304 . V_305 ;
if ( V_182 [ V_314 ] ) {
V_133 = F_203 ( V_182 [ V_314 ] ,
exp , F_17 ( V_23 ) ) ;
if ( V_133 < 0 )
goto V_341;
}
return exp ;
V_341:
F_182 ( exp ) ;
return F_153 ( V_133 ) ;
}
static int
F_206 ( struct V_131 * V_131 , T_5 V_185 ,
const struct V_8 * const V_182 [] ,
V_124 V_194 , T_2 V_102 , int V_143 )
{
struct V_3 V_4 , V_171 , F_42 ;
struct V_159 * V_160 = NULL ;
struct V_37 * V_38 = NULL ;
struct V_298 * exp ;
struct V_22 * V_23 ;
int V_133 ;
V_133 = F_98 ( V_182 , & V_4 , V_295 , V_194 ) ;
if ( V_133 < 0 )
return V_133 ;
V_133 = F_98 ( V_182 , & V_171 , V_296 , V_194 ) ;
if ( V_133 < 0 )
return V_133 ;
V_133 = F_98 ( V_182 , & F_42 , V_310 , V_194 ) ;
if ( V_133 < 0 )
return V_133 ;
V_160 = F_107 ( V_131 , V_185 , & F_42 ) ;
if ( ! V_160 )
return - V_195 ;
V_23 = F_88 ( V_160 ) ;
if ( V_182 [ V_300 ] ) {
const char * V_235 = F_103 ( V_182 [ V_300 ] ) ;
V_38 = F_138 ( V_235 , V_194 ,
F_18 ( V_23 ) ) ;
if ( V_38 == NULL ) {
#ifdef F_129
if ( F_131 ( L_4 , V_235 ) < 0 ) {
V_133 = - V_186 ;
goto V_343;
}
V_38 = F_138 ( V_235 , V_194 ,
F_18 ( V_23 ) ) ;
if ( V_38 ) {
V_133 = - V_153 ;
goto V_343;
}
#endif
V_133 = - V_186 ;
goto V_343;
}
}
exp = F_180 ( V_182 , V_23 , V_38 , & V_4 , & V_171 ) ;
if ( F_152 ( exp ) ) {
V_133 = F_166 ( exp ) ;
goto V_343;
}
V_133 = F_181 ( exp , V_102 , V_143 ) ;
if ( V_133 < 0 )
goto V_344;
return 0 ;
V_344:
F_182 ( exp ) ;
V_343:
F_79 ( V_23 ) ;
return V_133 ;
}
static int
F_207 ( struct V_192 * V_193 , struct V_1 * V_2 ,
const struct V_103 * V_104 ,
const struct V_8 * const V_182 [] )
{
struct V_131 * V_131 = F_82 ( V_193 ) ;
struct V_3 V_4 ;
struct V_298 * exp ;
struct V_105 * V_106 = F_51 ( V_104 ) ;
V_124 V_194 = V_106 -> V_113 ;
T_5 V_185 ;
int V_133 ;
if ( ! V_182 [ V_295 ]
|| ! V_182 [ V_296 ]
|| ! V_182 [ V_310 ] )
return - V_181 ;
V_133 = F_99 ( V_182 [ V_333 ] , & V_185 ) ;
if ( V_133 < 0 )
return V_133 ;
V_133 = F_98 ( V_182 , & V_4 , V_295 , V_194 ) ;
if ( V_133 < 0 )
return V_133 ;
F_120 ( & V_237 ) ;
exp = F_208 ( V_131 , V_185 , & V_4 ) ;
if ( ! exp ) {
F_122 ( & V_237 ) ;
V_133 = - V_195 ;
if ( V_104 -> V_198 & V_139 ) {
V_133 = F_206 ( V_131 , V_185 , V_182 ,
V_194 ,
F_89 ( V_2 ) . V_102 ,
F_106 ( V_104 ) ) ;
}
return V_133 ;
}
V_133 = - V_256 ;
if ( ! ( V_104 -> V_198 & V_140 ) )
V_133 = F_202 ( exp , V_182 ) ;
F_122 ( & V_237 ) ;
return V_133 ;
}
static int
F_209 ( struct V_1 * V_2 , T_2 V_102 , T_2 V_86 , int V_210 ,
const struct V_257 * V_258 )
{
struct V_103 * V_104 ;
struct V_105 * V_106 ;
unsigned int V_107 = V_102 ? V_108 : 0 , V_109 ;
V_109 = ( V_110 << 8 | V_345 ) ;
V_104 = F_50 ( V_2 , V_102 , V_86 , V_109 , sizeof( * V_106 ) , V_107 ) ;
if ( V_104 == NULL )
goto V_112;
V_106 = F_51 ( V_104 ) ;
V_106 -> V_113 = V_260 ;
V_106 -> V_114 = V_115 ;
V_106 -> V_116 = F_55 ( V_210 ) ;
if ( F_13 ( V_2 , V_346 , F_14 ( V_258 -> V_347 ) ) ||
F_13 ( V_2 , V_348 , F_14 ( V_258 -> V_349 ) ) ||
F_13 ( V_2 , V_350 , F_14 ( V_258 -> V_351 ) ) )
goto V_12;
F_56 ( V_2 , V_104 ) ;
return V_2 -> V_72 ;
V_12:
V_112:
F_57 ( V_2 , V_104 ) ;
return - 1 ;
}
static int
F_210 ( struct V_1 * V_2 , struct V_154 * V_155 )
{
int V_210 ;
struct V_131 * V_131 = F_82 ( V_2 -> V_157 ) ;
if ( V_155 -> args [ 0 ] == V_213 )
return 0 ;
for ( V_210 = V_155 -> args [ 0 ] ; V_210 < V_213 ; V_210 ++ ) {
const struct V_257 * V_258 ;
if ( ! F_118 ( V_210 ) )
continue;
V_258 = F_119 ( V_131 -> V_23 . V_286 , V_210 ) ;
if ( F_209 ( V_2 , F_89 ( V_155 -> V_2 ) . V_102 ,
V_155 -> V_104 -> V_173 ,
V_210 , V_258 ) < 0 )
break;
}
V_155 -> args [ 0 ] = V_210 ;
return V_2 -> V_72 ;
}
static int
F_211 ( struct V_192 * V_193 , struct V_1 * V_2 ,
const struct V_103 * V_104 ,
const struct V_8 * const V_182 [] )
{
if ( V_104 -> V_198 & V_199 ) {
struct V_200 V_201 = {
. V_202 = F_210 ,
} ;
return F_114 ( V_193 , V_2 , V_104 , & V_201 ) ;
}
return 0 ;
}
static int T_9 F_212 ( struct V_131 * V_131 )
{
#ifdef F_213
int V_7 ;
V_7 = F_214 ( V_131 , & V_352 ) ;
if ( V_7 < 0 ) {
F_215 ( L_5 ) ;
goto V_341;
}
V_7 = F_216 ( V_131 , & V_353 ) ;
if ( V_7 < 0 ) {
F_215 ( L_6 ) ;
goto V_354;
}
#endif
return 0 ;
#ifdef F_213
V_354:
F_217 ( V_131 , & V_352 ) ;
V_341:
return V_7 ;
#endif
}
static void F_218 ( struct V_131 * V_131 )
{
#ifdef F_213
F_219 ( V_131 , & V_353 ) ;
F_217 ( V_131 , & V_352 ) ;
#endif
}
static void T_10 F_220 ( struct V_355 * V_356 )
{
struct V_131 * V_131 ;
F_221 (net, net_exit_list, exit_list)
F_218 ( V_131 ) ;
}
static int T_11 F_222 ( void )
{
int V_7 ;
F_223 ( L_7 , V_114 ) ;
V_7 = F_224 ( & V_357 ) ;
if ( V_7 < 0 ) {
F_215 ( L_8 ) ;
goto V_341;
}
V_7 = F_224 ( & V_358 ) ;
if ( V_7 < 0 ) {
F_215 ( L_9 ) ;
goto V_359;
}
V_7 = F_225 ( & V_360 ) ;
if ( V_7 < 0 ) {
F_215 ( L_10 ) ;
goto V_361;
}
#ifdef F_226
F_137 ( V_362 , & V_363 ) ;
#endif
return 0 ;
V_361:
F_227 ( & V_358 ) ;
V_359:
F_227 ( & V_357 ) ;
V_341:
return V_7 ;
}
static void T_12 F_228 ( void )
{
F_223 ( L_11 ) ;
F_229 ( & V_360 ) ;
F_227 ( & V_358 ) ;
F_227 ( & V_357 ) ;
#ifdef F_226
F_137 ( V_362 , NULL ) ;
#endif
}
