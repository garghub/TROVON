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
F_23 ( struct V_1 * V_2 , T_1 V_43 , T_1 V_44 ,
enum V_45 V_46 )
{
enum V_47 type = V_46 ? V_48 : V_49 ;
struct V_8 * V_50 ;
V_50 = F_2 ( V_2 , type | V_11 ) ;
if ( ! V_50 )
goto V_12;
if ( F_24 ( V_2 , V_51 , F_25 ( V_43 ) ) ||
F_24 ( V_2 , V_52 , F_25 ( V_44 ) ) )
goto V_12;
F_5 ( V_2 , V_50 ) ;
return 0 ;
V_12:
return - 1 ;
}
static int
F_26 ( struct V_1 * V_2 , const struct V_22 * V_23 ,
enum V_45 V_46 , int type )
{
struct V_53 * V_54 ;
T_1 V_43 , V_44 ;
V_54 = F_27 ( V_23 ) ;
if ( ! V_54 )
return 0 ;
if ( type == V_55 ) {
V_43 = F_28 ( & V_54 [ V_46 ] . V_56 , 0 ) ;
V_44 = F_28 ( & V_54 [ V_46 ] . V_44 , 0 ) ;
} else {
V_43 = F_29 ( & V_54 [ V_46 ] . V_56 ) ;
V_44 = F_29 ( & V_54 [ V_46 ] . V_44 ) ;
}
return F_23 ( V_2 , V_43 , V_44 , V_46 ) ;
}
static int
F_30 ( struct V_1 * V_2 , const struct V_22 * V_23 )
{
struct V_8 * V_50 ;
const struct V_57 * V_58 ;
V_58 = F_31 ( V_23 ) ;
if ( ! V_58 )
return 0 ;
V_50 = F_2 ( V_2 , V_59 | V_11 ) ;
if ( ! V_50 )
goto V_12;
if ( F_24 ( V_2 , V_60 , F_25 ( V_58 -> V_61 ) ) ||
( V_58 -> V_62 != 0 && F_24 ( V_2 , V_63 ,
F_25 ( V_58 -> V_62 ) ) ) )
goto V_12;
F_5 ( V_2 , V_50 ) ;
return 0 ;
V_12:
return - 1 ;
}
static inline int
F_32 ( struct V_1 * V_2 , const struct V_22 * V_23 )
{
if ( F_13 ( V_2 , V_64 , F_14 ( V_23 -> V_65 ) ) )
goto V_12;
return 0 ;
V_12:
return - 1 ;
}
static inline int
F_33 ( struct V_1 * V_2 , const struct V_22 * V_23 )
{
struct V_8 * V_66 ;
int V_67 , V_7 ;
char * V_68 ;
V_7 = F_34 ( V_23 -> V_69 , & V_68 , & V_67 ) ;
if ( V_7 )
return 0 ;
V_7 = - 1 ;
V_66 = F_2 ( V_2 , V_70 | V_11 ) ;
if ( ! V_66 )
goto V_12;
if ( F_22 ( V_2 , V_71 , V_68 ) )
goto V_12;
F_5 ( V_2 , V_66 ) ;
V_7 = 0 ;
V_12:
F_35 ( V_68 , V_67 ) ;
return V_7 ;
}
static int F_36 ( const struct V_22 * V_23 )
{
struct V_72 * V_73 = F_37 ( V_23 ) ;
if ( ! V_73 )
return 0 ;
return F_38 ( V_73 -> V_74 * sizeof( long ) ) ;
}
static int
F_39 ( struct V_1 * V_2 , const struct V_22 * V_23 )
{
struct V_72 * V_73 = F_37 ( V_23 ) ;
unsigned int V_67 , V_75 ;
if ( ! V_73 )
return 0 ;
V_67 = V_73 -> V_74 * sizeof( long ) ;
V_75 = 0 ;
do {
if ( V_73 -> V_76 [ V_75 ] != 0 )
return F_40 ( V_2 , V_77 , V_67 , V_73 -> V_76 ) ;
V_75 ++ ;
} while ( V_75 < V_73 -> V_74 );
return 0 ;
}
static inline int
F_41 ( struct V_1 * V_2 , const struct V_22 * V_23 )
{
struct V_8 * V_9 ;
if ( ! ( V_23 -> V_25 & V_78 ) )
return 0 ;
V_9 = F_2 ( V_2 , V_79 | V_11 ) ;
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
F_43 ( struct V_1 * V_2 , const struct V_80 * V_81 , int type )
{
struct V_8 * V_9 ;
V_9 = F_2 ( V_2 , type | V_11 ) ;
if ( ! V_9 )
goto V_12;
if ( F_13 ( V_2 , V_82 ,
F_14 ( V_81 -> V_83 ) ) ||
F_13 ( V_2 , V_84 ,
F_14 ( V_81 -> V_85 ) ) ||
F_13 ( V_2 , V_86 ,
F_14 ( V_81 -> V_87 ) ) )
goto V_12;
F_5 ( V_2 , V_9 ) ;
return 0 ;
V_12:
return - 1 ;
}
static inline int
F_44 ( struct V_1 * V_2 , const struct V_22 * V_23 )
{
struct V_88 * V_89 = F_45 ( V_23 ) ;
struct V_80 * V_81 ;
if ( ! ( V_23 -> V_25 & V_90 ) || ! V_89 )
return 0 ;
V_81 = & V_89 -> V_81 [ V_91 ] ;
if ( F_43 ( V_2 , V_81 , V_92 ) == - 1 )
return - 1 ;
V_81 = & V_89 -> V_81 [ V_93 ] ;
if ( F_43 ( V_2 , V_81 , V_94 ) == - 1 )
return - 1 ;
return 0 ;
}
static inline int
F_46 ( struct V_1 * V_2 , const struct V_22 * V_23 )
{
if ( F_13 ( V_2 , V_95 , F_14 ( ( unsigned long ) V_23 ) ) )
goto V_12;
return 0 ;
V_12:
return - 1 ;
}
static inline int
F_47 ( struct V_1 * V_2 , const struct V_22 * V_23 )
{
if ( F_13 ( V_2 , V_96 , F_14 ( F_48 ( & V_23 -> V_97 . V_98 ) ) ) )
goto V_12;
return 0 ;
V_12:
return - 1 ;
}
static int
F_49 ( struct V_1 * V_2 , T_2 V_99 , T_2 V_81 , T_2 type ,
struct V_22 * V_23 )
{
struct V_100 * V_101 ;
struct V_102 * V_103 ;
struct V_8 * V_9 ;
unsigned int V_104 = V_99 ? V_105 : 0 , V_106 ;
V_106 = ( V_107 << 8 | V_108 ) ;
V_101 = F_50 ( V_2 , V_99 , V_81 , V_106 , sizeof( * V_103 ) , V_104 ) ;
if ( V_101 == NULL )
goto V_109;
V_103 = F_51 ( V_101 ) ;
V_103 -> V_110 = F_17 ( V_23 ) ;
V_103 -> V_111 = V_112 ;
V_103 -> V_113 = 0 ;
V_9 = F_2 ( V_2 , V_114 | V_11 ) ;
if ( ! V_9 )
goto V_12;
if ( F_7 ( V_2 , F_52 ( V_23 , V_91 ) ) < 0 )
goto V_12;
F_5 ( V_2 , V_9 ) ;
V_9 = F_2 ( V_2 , V_115 | V_11 ) ;
if ( ! V_9 )
goto V_12;
if ( F_7 ( V_2 , F_52 ( V_23 , V_93 ) ) < 0 )
goto V_12;
F_5 ( V_2 , V_9 ) ;
if ( F_53 ( V_23 ) &&
F_54 ( V_2 , V_116 , F_55 ( F_53 ( V_23 ) ) ) )
goto V_12;
if ( F_12 ( V_2 , V_23 ) < 0 ||
F_15 ( V_2 , V_23 ) < 0 ||
F_26 ( V_2 , V_23 , V_91 , type ) < 0 ||
F_26 ( V_2 , V_23 , V_93 , type ) < 0 ||
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
F_56 ( V_2 , V_101 ) ;
return V_2 -> V_67 ;
V_109:
V_12:
F_57 ( V_2 , V_101 ) ;
return - 1 ;
}
static inline T_3
F_58 ( const struct V_22 * V_23 )
{
struct V_17 * V_18 ;
struct V_5 * V_6 ;
T_3 V_67 = 0 ;
F_8 () ;
V_18 = F_9 ( F_17 ( V_23 ) ) ;
V_67 += V_18 -> V_117 ;
V_6 = F_10 ( F_17 ( V_23 ) , F_18 ( V_23 ) ) ;
V_67 += V_6 -> V_117 ;
F_11 () ;
return V_67 ;
}
static inline T_3
F_59 ( const struct V_22 * V_23 )
{
if ( ! F_60 ( V_23 , V_118 ) )
return 0 ;
return 2 * F_38 ( 0 )
+ 2 * F_38 ( sizeof( V_119 ) )
+ 2 * F_38 ( sizeof( V_119 ) )
;
}
static inline int
F_61 ( const struct V_22 * V_23 )
{
#ifdef F_62
int V_67 , V_7 ;
V_7 = F_34 ( V_23 -> V_69 , NULL , & V_67 ) ;
if ( V_7 )
return 0 ;
return F_38 ( 0 )
+ F_38 ( sizeof( char ) * V_67 ) ;
#else
return 0 ;
#endif
}
static inline T_3
F_63 ( const struct V_22 * V_23 )
{
#ifdef F_64
if ( ! F_60 ( V_23 , V_120 ) )
return 0 ;
return F_38 ( 0 ) + 2 * F_38 ( sizeof( V_119 ) ) ;
#else
return 0 ;
#endif
}
static inline T_3
F_65 ( const struct V_22 * V_23 )
{
return F_66 ( sizeof( struct V_102 ) )
+ 3 * F_38 ( 0 )
+ 3 * F_38 ( 0 )
+ 3 * F_38 ( 0 )
+ 3 * F_38 ( sizeof( V_121 ) )
+ F_38 ( sizeof( V_122 ) )
+ F_38 ( sizeof( V_122 ) )
+ F_59 ( V_23 )
+ F_63 ( V_23 )
+ F_38 ( sizeof( V_122 ) )
+ F_38 ( 0 )
+ F_38 ( 0 )
+ F_38 ( V_123 )
+ F_61 ( V_23 )
#ifdef F_67
+ 2 * F_38 ( 0 )
+ 6 * F_38 ( sizeof( V_122 ) )
#endif
#ifdef F_68
+ F_38 ( sizeof( V_122 ) )
#endif
+ F_58 ( V_23 )
+ F_36 ( V_23 )
;
}
static int
F_69 ( unsigned int V_124 , struct V_125 * V_126 )
{
struct V_127 * V_127 ;
struct V_100 * V_101 ;
struct V_102 * V_103 ;
struct V_8 * V_9 ;
struct V_22 * V_23 = V_126 -> V_23 ;
struct V_1 * V_2 ;
unsigned int type ;
unsigned int V_104 = 0 , V_128 ;
int V_129 ;
if ( F_70 ( V_23 ) )
return 0 ;
if ( V_124 & ( 1 << V_130 ) ) {
type = V_131 ;
V_128 = V_132 ;
} else if ( V_124 & ( ( 1 << V_133 ) | ( 1 << V_134 ) ) ) {
type = V_108 ;
V_104 = V_135 | V_136 ;
V_128 = V_137 ;
} else if ( V_124 ) {
type = V_108 ;
V_128 = V_138 ;
} else
return 0 ;
V_127 = F_71 ( V_23 ) ;
if ( ! V_126 -> V_139 && ! F_72 ( V_127 , V_128 ) )
return 0 ;
V_2 = F_73 ( F_65 ( V_23 ) , V_140 ) ;
if ( V_2 == NULL )
goto V_141;
type |= V_107 << 8 ;
V_101 = F_50 ( V_2 , V_126 -> V_99 , 0 , type , sizeof( * V_103 ) , V_104 ) ;
if ( V_101 == NULL )
goto V_109;
V_103 = F_51 ( V_101 ) ;
V_103 -> V_110 = F_17 ( V_23 ) ;
V_103 -> V_111 = V_112 ;
V_103 -> V_113 = 0 ;
F_8 () ;
V_9 = F_2 ( V_2 , V_114 | V_11 ) ;
if ( ! V_9 )
goto V_12;
if ( F_7 ( V_2 , F_52 ( V_23 , V_91 ) ) < 0 )
goto V_12;
F_5 ( V_2 , V_9 ) ;
V_9 = F_2 ( V_2 , V_115 | V_11 ) ;
if ( ! V_9 )
goto V_12;
if ( F_7 ( V_2 , F_52 ( V_23 , V_93 ) ) < 0 )
goto V_12;
F_5 ( V_2 , V_9 ) ;
if ( F_53 ( V_23 ) &&
F_54 ( V_2 , V_116 , F_55 ( F_53 ( V_23 ) ) ) )
goto V_12;
if ( F_46 ( V_2 , V_23 ) < 0 )
goto V_12;
if ( F_12 ( V_2 , V_23 ) < 0 )
goto V_12;
if ( V_124 & ( 1 << V_130 ) ) {
if ( F_26 ( V_2 , V_23 ,
V_91 , type ) < 0 ||
F_26 ( V_2 , V_23 ,
V_93 , type ) < 0 ||
F_30 ( V_2 , V_23 ) < 0 )
goto V_12;
} else {
if ( F_15 ( V_2 , V_23 ) < 0 )
goto V_12;
if ( V_124 & ( 1 << V_142 )
&& F_16 ( V_2 , V_23 ) < 0 )
goto V_12;
if ( ( V_124 & ( 1 << V_143 ) || F_20 ( V_23 ) )
&& F_19 ( V_2 , V_23 ) < 0 )
goto V_12;
#ifdef F_62
if ( ( V_124 & ( 1 << V_144 ) || V_23 -> V_69 )
&& F_33 ( V_2 , V_23 ) < 0 )
goto V_12;
#endif
if ( V_124 & ( 1 << V_145 ) &&
F_39 ( V_2 , V_23 ) < 0 )
goto V_12;
if ( V_124 & ( 1 << V_134 ) &&
F_41 ( V_2 , V_23 ) < 0 )
goto V_12;
if ( V_124 & ( 1 << V_146 ) &&
F_44 ( V_2 , V_23 ) < 0 )
goto V_12;
}
#ifdef F_68
if ( ( V_124 & ( 1 << V_147 ) || V_23 -> V_65 )
&& F_32 ( V_2 , V_23 ) < 0 )
goto V_12;
#endif
F_11 () ;
F_56 ( V_2 , V_101 ) ;
V_129 = F_74 ( V_2 , V_127 , V_126 -> V_99 , V_128 , V_126 -> V_139 ,
V_140 ) ;
if ( V_129 == - V_148 || V_129 == - V_149 )
return - V_148 ;
return 0 ;
V_12:
F_11 () ;
F_57 ( V_2 , V_101 ) ;
V_109:
F_75 ( V_2 ) ;
V_141:
if ( F_76 ( V_127 , 0 , V_128 , - V_148 ) > 0 )
return - V_148 ;
return 0 ;
}
static int F_77 ( struct V_150 * V_151 )
{
if ( V_151 -> args [ 1 ] )
F_78 ( (struct V_22 * ) V_151 -> args [ 1 ] ) ;
if ( V_151 -> V_152 )
F_79 ( V_151 -> V_152 ) ;
return 0 ;
}
static int
F_80 ( struct V_1 * V_2 , struct V_150 * V_151 )
{
struct V_127 * V_127 = F_81 ( V_2 -> V_153 ) ;
struct V_22 * V_23 , * V_154 ;
struct V_155 * V_156 ;
struct V_157 * V_158 ;
struct V_102 * V_103 = F_51 ( V_151 -> V_101 ) ;
V_121 V_18 = V_103 -> V_110 ;
int V_159 ;
#ifdef F_68
const struct V_160 * V_161 = V_151 -> V_152 ;
#endif
F_82 ( & V_162 ) ;
V_154 = (struct V_22 * ) V_151 -> args [ 1 ] ;
for (; V_151 -> args [ 0 ] < V_127 -> V_23 . V_163 ; V_151 -> args [ 0 ] ++ ) {
V_164:
F_83 (h, n, &net->ct.hash[cb->args[0]],
hnnode) {
if ( F_84 ( V_156 ) != V_91 )
continue;
V_23 = F_85 ( V_156 ) ;
if ( V_18 && F_17 ( V_23 ) != V_18 )
continue;
if ( V_151 -> args [ 1 ] ) {
if ( V_23 != V_154 )
continue;
V_151 -> args [ 1 ] = 0 ;
}
#ifdef F_68
if ( V_161 && ! ( ( V_23 -> V_65 & V_161 -> V_65 . V_165 ) ==
V_161 -> V_65 . V_166 ) ) {
continue;
}
#endif
F_8 () ;
V_159 =
F_49 ( V_2 , F_86 ( V_151 -> V_2 ) . V_99 ,
V_151 -> V_101 -> V_167 ,
F_87 ( V_151 -> V_101 -> V_168 ) ,
V_23 ) ;
F_11 () ;
if ( V_159 < 0 ) {
F_88 ( & V_23 -> V_97 ) ;
V_151 -> args [ 1 ] = ( unsigned long ) V_23 ;
goto V_39;
}
}
if ( V_151 -> args [ 1 ] ) {
V_151 -> args [ 1 ] = 0 ;
goto V_164;
}
}
V_39:
F_89 ( & V_162 ) ;
if ( V_154 )
F_78 ( V_154 ) ;
return V_2 -> V_67 ;
}
static inline int
F_90 ( struct V_8 * V_169 , struct V_3 * V_4 )
{
struct V_8 * V_170 [ V_171 + 1 ] ;
struct V_17 * V_18 ;
int V_7 = 0 ;
V_7 = F_91 ( V_170 , V_171 , V_169 , NULL ) ;
if ( V_7 < 0 )
return V_7 ;
F_8 () ;
V_18 = F_9 ( V_4 -> V_20 . V_21 ) ;
if ( F_4 ( V_18 -> V_172 ) ) {
V_7 = F_92 ( V_169 , V_171 ,
V_18 -> V_173 ) ;
if ( V_7 == 0 )
V_7 = V_18 -> V_172 ( V_170 , V_4 ) ;
}
F_11 () ;
return V_7 ;
}
static inline int
F_93 ( struct V_8 * V_169 ,
struct V_3 * V_4 )
{
struct V_8 * V_170 [ V_174 + 1 ] ;
struct V_5 * V_6 ;
int V_7 = 0 ;
V_7 = F_91 ( V_170 , V_174 , V_169 , V_175 ) ;
if ( V_7 < 0 )
return V_7 ;
if ( ! V_170 [ V_13 ] )
return - V_176 ;
V_4 -> V_14 . V_15 = F_94 ( V_170 [ V_13 ] ) ;
F_8 () ;
V_6 = F_10 ( V_4 -> V_20 . V_21 , V_4 -> V_14 . V_15 ) ;
if ( F_4 ( V_6 -> V_172 ) ) {
V_7 = F_92 ( V_169 , V_174 ,
V_6 -> V_173 ) ;
if ( V_7 == 0 )
V_7 = V_6 -> V_172 ( V_170 , V_4 ) ;
}
F_11 () ;
return V_7 ;
}
static int
F_95 ( const struct V_8 * const V_177 [] ,
struct V_3 * V_4 ,
enum V_47 type , V_121 V_21 )
{
struct V_8 * V_170 [ V_178 + 1 ] ;
int V_129 ;
memset ( V_4 , 0 , sizeof( * V_4 ) ) ;
V_129 = F_91 ( V_170 , V_178 , V_177 [ type ] , V_179 ) ;
if ( V_129 < 0 )
return V_129 ;
if ( ! V_170 [ V_19 ] )
return - V_176 ;
V_4 -> V_20 . V_21 = V_21 ;
V_129 = F_90 ( V_170 [ V_19 ] , V_4 ) ;
if ( V_129 < 0 )
return V_129 ;
if ( ! V_170 [ V_10 ] )
return - V_176 ;
V_129 = F_93 ( V_170 [ V_10 ] , V_4 ) ;
if ( V_129 < 0 )
return V_129 ;
if ( type == V_115 )
V_4 -> V_14 . V_46 = V_93 ;
else
V_4 -> V_14 . V_46 = V_91 ;
return 0 ;
}
static int
F_96 ( const struct V_8 * V_169 , T_4 * V_180 )
{
if ( V_169 )
#ifdef F_97
* V_180 = F_98 ( F_99 ( V_169 ) ) ;
#else
return - V_181 ;
#endif
else
* V_180 = 0 ;
return 0 ;
}
static inline int
F_100 ( const struct V_8 * V_169 , char * * V_182 ,
struct V_8 * * V_183 )
{
int V_129 ;
struct V_8 * V_170 [ V_184 + 1 ] ;
V_129 = F_91 ( V_170 , V_184 , V_169 , V_185 ) ;
if ( V_129 < 0 )
return V_129 ;
if ( ! V_170 [ V_41 ] )
return - V_176 ;
* V_182 = F_101 ( V_170 [ V_41 ] ) ;
if ( V_170 [ V_186 ] )
* V_183 = V_170 [ V_186 ] ;
return 0 ;
}
static int
F_102 ( struct V_187 * V_188 , struct V_1 * V_2 ,
const struct V_100 * V_101 ,
const struct V_8 * const V_177 [] )
{
struct V_127 * V_127 = F_81 ( V_188 ) ;
struct V_155 * V_156 ;
struct V_3 V_4 ;
struct V_22 * V_23 ;
struct V_102 * V_103 = F_51 ( V_101 ) ;
V_121 V_189 = V_103 -> V_110 ;
T_4 V_180 ;
int V_129 ;
V_129 = F_96 ( V_177 [ V_116 ] , & V_180 ) ;
if ( V_129 < 0 )
return V_129 ;
if ( V_177 [ V_114 ] )
V_129 = F_95 ( V_177 , & V_4 , V_114 , V_189 ) ;
else if ( V_177 [ V_115 ] )
V_129 = F_95 ( V_177 , & V_4 , V_115 , V_189 ) ;
else {
F_103 ( V_127 ,
F_86 ( V_2 ) . V_99 ,
F_104 ( V_101 ) ) ;
return 0 ;
}
if ( V_129 < 0 )
return V_129 ;
V_156 = F_105 ( V_127 , V_180 , & V_4 ) ;
if ( ! V_156 )
return - V_190 ;
V_23 = F_85 ( V_156 ) ;
if ( V_177 [ V_95 ] ) {
V_122 V_191 = F_106 ( F_107 ( V_177 [ V_95 ] ) ) ;
if ( V_191 != ( T_2 ) ( unsigned long ) V_23 ) {
F_78 ( V_23 ) ;
return - V_190 ;
}
}
if ( F_108 ( & V_23 -> V_26 ) )
F_109 ( V_23 , F_86 ( V_2 ) . V_99 , F_104 ( V_101 ) ) ;
F_78 ( V_23 ) ;
return 0 ;
}
static int
F_110 ( struct V_187 * V_188 , struct V_1 * V_2 ,
const struct V_100 * V_101 ,
const struct V_8 * const V_177 [] )
{
struct V_127 * V_127 = F_81 ( V_188 ) ;
struct V_155 * V_156 ;
struct V_3 V_4 ;
struct V_22 * V_23 ;
struct V_1 * V_192 = NULL ;
struct V_102 * V_103 = F_51 ( V_101 ) ;
V_121 V_189 = V_103 -> V_110 ;
T_4 V_180 ;
int V_129 ;
if ( V_101 -> V_193 & V_194 ) {
struct V_195 V_196 = {
. V_197 = F_80 ,
. V_198 = F_77 ,
} ;
#ifdef F_68
if ( V_177 [ V_64 ] && V_177 [ V_199 ] ) {
struct V_160 * V_161 ;
V_161 = F_111 ( sizeof( struct V_160 ) ,
V_140 ) ;
if ( V_161 == NULL )
return - V_200 ;
V_161 -> V_65 . V_166 = F_106 ( F_107 ( V_177 [ V_64 ] ) ) ;
V_161 -> V_65 . V_165 =
F_106 ( F_107 ( V_177 [ V_199 ] ) ) ;
V_196 . V_152 = V_161 ;
}
#endif
return F_112 ( V_188 , V_2 , V_101 , & V_196 ) ;
}
V_129 = F_96 ( V_177 [ V_116 ] , & V_180 ) ;
if ( V_129 < 0 )
return V_129 ;
if ( V_177 [ V_114 ] )
V_129 = F_95 ( V_177 , & V_4 , V_114 , V_189 ) ;
else if ( V_177 [ V_115 ] )
V_129 = F_95 ( V_177 , & V_4 , V_115 , V_189 ) ;
else
return - V_176 ;
if ( V_129 < 0 )
return V_129 ;
V_156 = F_105 ( V_127 , V_180 , & V_4 ) ;
if ( ! V_156 )
return - V_190 ;
V_23 = F_85 ( V_156 ) ;
V_129 = - V_200 ;
V_192 = F_73 ( V_201 , V_202 ) ;
if ( V_192 == NULL ) {
F_78 ( V_23 ) ;
return - V_200 ;
}
F_8 () ;
V_129 = F_49 ( V_192 , F_86 ( V_2 ) . V_99 , V_101 -> V_167 ,
F_87 ( V_101 -> V_168 ) , V_23 ) ;
F_11 () ;
F_78 ( V_23 ) ;
if ( V_129 <= 0 )
goto free;
V_129 = F_113 ( V_188 , V_192 , F_86 ( V_2 ) . V_99 , V_203 ) ;
if ( V_129 < 0 )
goto V_39;
return 0 ;
free:
F_75 ( V_192 ) ;
V_39:
return V_129 == - V_149 ? - V_148 : V_129 ;
}
static int F_114 ( struct V_150 * V_151 )
{
if ( V_151 -> args [ 1 ] )
F_78 ( (struct V_22 * ) V_151 -> args [ 1 ] ) ;
return 0 ;
}
static int
F_115 ( struct V_1 * V_2 , struct V_150 * V_151 ,
struct V_204 * V_205 )
{
struct V_22 * V_23 , * V_154 ;
struct V_155 * V_156 ;
struct V_157 * V_158 ;
struct V_102 * V_103 = F_51 ( V_151 -> V_101 ) ;
V_121 V_18 = V_103 -> V_110 ;
int V_159 ;
if ( V_151 -> args [ 2 ] )
return 0 ;
F_82 ( & V_162 ) ;
V_154 = (struct V_22 * ) V_151 -> args [ 1 ] ;
V_164:
F_83 (h, n, list, hnnode) {
V_23 = F_85 ( V_156 ) ;
if ( V_18 && F_17 ( V_23 ) != V_18 )
continue;
if ( V_151 -> args [ 1 ] ) {
if ( V_23 != V_154 )
continue;
V_151 -> args [ 1 ] = 0 ;
}
F_8 () ;
V_159 = F_49 ( V_2 , F_86 ( V_151 -> V_2 ) . V_99 ,
V_151 -> V_101 -> V_167 ,
F_87 ( V_151 -> V_101 -> V_168 ) ,
V_23 ) ;
F_11 () ;
if ( V_159 < 0 ) {
F_88 ( & V_23 -> V_97 ) ;
V_151 -> args [ 1 ] = ( unsigned long ) V_23 ;
goto V_39;
}
}
if ( V_151 -> args [ 1 ] ) {
V_151 -> args [ 1 ] = 0 ;
goto V_164;
} else
V_151 -> args [ 2 ] = 1 ;
V_39:
F_89 ( & V_162 ) ;
if ( V_154 )
F_78 ( V_154 ) ;
return V_2 -> V_67 ;
}
static int
F_116 ( struct V_1 * V_2 , struct V_150 * V_151 )
{
struct V_127 * V_127 = F_81 ( V_2 -> V_153 ) ;
return F_115 ( V_2 , V_151 , & V_127 -> V_23 . V_206 ) ;
}
static int
F_117 ( struct V_187 * V_188 , struct V_1 * V_2 ,
const struct V_100 * V_101 ,
const struct V_8 * const V_177 [] )
{
if ( V_101 -> V_193 & V_194 ) {
struct V_195 V_196 = {
. V_197 = F_116 ,
. V_198 = F_114 ,
} ;
return F_112 ( V_188 , V_2 , V_101 , & V_196 ) ;
}
return - V_181 ;
}
static int
F_118 ( struct V_1 * V_2 , struct V_150 * V_151 )
{
struct V_127 * V_127 = F_81 ( V_2 -> V_153 ) ;
return F_115 ( V_2 , V_151 , & V_127 -> V_23 . V_207 ) ;
}
static int
F_119 ( struct V_187 * V_188 , struct V_1 * V_2 ,
const struct V_100 * V_101 ,
const struct V_8 * const V_177 [] )
{
if ( V_101 -> V_193 & V_194 ) {
struct V_195 V_196 = {
. V_197 = F_118 ,
. V_198 = F_114 ,
} ;
return F_112 ( V_188 , V_2 , V_101 , & V_196 ) ;
}
return - V_181 ;
}
static int
F_120 ( struct V_22 * V_23 ,
enum V_208 V_209 ,
const struct V_8 * V_169 )
{
F_121 (nfnetlink_parse_nat_setup_hook) V_210 ;
int V_129 ;
V_210 = F_21 ( V_211 ) ;
if ( ! V_210 ) {
#ifdef F_122
F_11 () ;
F_123 ( V_107 ) ;
if ( F_124 ( L_1 ) < 0 ) {
F_125 ( V_107 ) ;
F_8 () ;
return - V_181 ;
}
F_125 ( V_107 ) ;
F_8 () ;
if ( V_211 )
return - V_149 ;
#endif
return - V_181 ;
}
V_129 = V_210 ( V_23 , V_209 , V_169 ) ;
if ( V_129 == - V_149 ) {
#ifdef F_122
F_11 () ;
F_123 ( V_107 ) ;
if ( F_124 ( L_2 , F_17 ( V_23 ) ) < 0 ) {
F_125 ( V_107 ) ;
F_8 () ;
return - V_181 ;
}
F_125 ( V_107 ) ;
F_8 () ;
#else
V_129 = - V_181 ;
#endif
}
return V_129 ;
}
static int
F_126 ( struct V_22 * V_23 , const struct V_8 * const V_177 [] )
{
unsigned long V_212 ;
unsigned int V_25 = F_106 ( F_107 ( V_177 [ V_24 ] ) ) ;
V_212 = V_23 -> V_25 ^ V_25 ;
if ( V_212 & ( V_78 | V_213 | V_214 ) )
return - V_215 ;
if ( V_212 & V_216 && ! ( V_25 & V_216 ) )
return - V_215 ;
if ( V_212 & V_217 && ! ( V_25 & V_217 ) )
return - V_215 ;
V_23 -> V_25 |= V_25 & ~ ( V_218 | V_219 ) ;
return 0 ;
}
static int
F_127 ( struct V_22 * V_23 , const struct V_8 * const V_177 [] )
{
#ifdef F_67
int V_7 ;
if ( V_177 [ V_220 ] ) {
V_7 = F_120 ( V_23 ,
V_221 ,
V_177 [ V_220 ] ) ;
if ( V_7 < 0 )
return V_7 ;
}
if ( V_177 [ V_222 ] ) {
V_7 = F_120 ( V_23 ,
V_223 ,
V_177 [ V_222 ] ) ;
if ( V_7 < 0 )
return V_7 ;
}
return 0 ;
#else
return - V_181 ;
#endif
}
static inline int
F_128 ( struct V_22 * V_23 , const struct V_8 * const V_177 [] )
{
struct V_37 * V_38 ;
struct V_35 * V_36 = F_20 ( V_23 ) ;
char * V_224 = NULL ;
struct V_8 * V_183 = NULL ;
int V_129 ;
if ( V_23 -> V_225 )
return - V_215 ;
V_129 = F_100 ( V_177 [ V_40 ] , & V_224 , & V_183 ) ;
if ( V_129 < 0 )
return V_129 ;
if ( ! strcmp ( V_224 , L_3 ) ) {
if ( V_36 && V_36 -> V_38 ) {
F_129 ( V_23 ) ;
F_130 ( V_36 -> V_38 , NULL ) ;
}
return 0 ;
}
V_38 = F_131 ( V_224 , F_17 ( V_23 ) ,
F_18 ( V_23 ) ) ;
if ( V_38 == NULL ) {
#ifdef F_122
F_89 ( & V_162 ) ;
if ( F_124 ( L_4 , V_224 ) < 0 ) {
F_82 ( & V_162 ) ;
return - V_181 ;
}
F_82 ( & V_162 ) ;
V_38 = F_131 ( V_224 , F_17 ( V_23 ) ,
F_18 ( V_23 ) ) ;
if ( V_38 )
return - V_149 ;
#endif
return - V_181 ;
}
if ( V_36 ) {
if ( V_36 -> V_38 == V_38 ) {
if ( V_38 -> V_226 )
V_38 -> V_226 ( V_183 , V_23 ) ;
return 0 ;
} else
return - V_215 ;
}
return - V_181 ;
}
static inline int
F_132 ( struct V_22 * V_23 , const struct V_8 * const V_177 [] )
{
V_122 V_26 = F_106 ( F_107 ( V_177 [ V_30 ] ) ) ;
if ( ! F_108 ( & V_23 -> V_26 ) )
return - V_227 ;
V_23 -> V_26 . V_27 = V_28 + V_26 * V_29 ;
F_133 ( & V_23 -> V_26 ) ;
return 0 ;
}
static inline int
F_134 ( struct V_22 * V_23 , const struct V_8 * const V_177 [] )
{
const struct V_8 * V_169 = V_177 [ V_33 ] ;
struct V_8 * V_170 [ V_228 + 1 ] ;
struct V_5 * V_6 ;
int V_129 = 0 ;
V_129 = F_91 ( V_170 , V_228 , V_169 , V_229 ) ;
if ( V_129 < 0 )
return V_129 ;
F_8 () ;
V_6 = F_10 ( F_17 ( V_23 ) , F_18 ( V_23 ) ) ;
if ( V_6 -> V_226 )
V_129 = V_6 -> V_226 ( V_170 , V_23 ) ;
F_11 () ;
return V_129 ;
}
static inline int
F_135 ( struct V_80 * V_81 , const struct V_8 * const V_169 )
{
int V_129 ;
struct V_8 * V_177 [ V_230 + 1 ] ;
V_129 = F_91 ( V_177 , V_230 , V_169 , V_231 ) ;
if ( V_129 < 0 )
return V_129 ;
if ( ! V_177 [ V_82 ] )
return - V_176 ;
V_81 -> V_83 =
F_106 ( F_107 ( V_177 [ V_82 ] ) ) ;
if ( ! V_177 [ V_84 ] )
return - V_176 ;
V_81 -> V_85 =
F_106 ( F_107 ( V_177 [ V_84 ] ) ) ;
if ( ! V_177 [ V_86 ] )
return - V_176 ;
V_81 -> V_87 =
F_106 ( F_107 ( V_177 [ V_86 ] ) ) ;
return 0 ;
}
static int
F_136 ( struct V_22 * V_23 ,
const struct V_8 * const V_177 [] )
{
struct V_88 * V_89 = F_45 ( V_23 ) ;
int V_7 = 0 ;
if ( ! V_89 )
return 0 ;
if ( V_177 [ V_92 ] ) {
V_7 = F_135 ( & V_89 -> V_81 [ V_91 ] ,
V_177 [ V_92 ] ) ;
if ( V_7 < 0 )
return V_7 ;
V_23 -> V_25 |= V_90 ;
}
if ( V_177 [ V_94 ] ) {
V_7 = F_135 ( & V_89 -> V_81 [ V_93 ] ,
V_177 [ V_94 ] ) ;
if ( V_7 < 0 )
return V_7 ;
V_23 -> V_25 |= V_90 ;
}
return 0 ;
}
static int
F_137 ( struct V_22 * V_23 , const struct V_8 * const V_177 [] )
{
#ifdef F_138
T_3 V_67 = F_139 ( V_177 [ V_77 ] ) ;
const void * V_165 = V_177 [ V_232 ] ;
if ( V_67 & ( sizeof( T_2 ) - 1 ) )
return - V_176 ;
if ( V_165 ) {
if ( F_139 ( V_177 [ V_232 ] ) == 0 ||
F_139 ( V_177 [ V_232 ] ) != V_67 )
return - V_176 ;
V_165 = F_101 ( V_177 [ V_232 ] ) ;
}
V_67 /= sizeof( T_2 ) ;
return F_140 ( V_23 , F_101 ( V_177 [ V_77 ] ) , V_165 , V_67 ) ;
#else
return - V_181 ;
#endif
}
static int
F_141 ( struct V_22 * V_23 ,
const struct V_8 * const V_177 [] )
{
int V_129 ;
if ( V_177 [ V_222 ] || V_177 [ V_220 ] || V_177 [ V_79 ] )
return - V_181 ;
if ( V_177 [ V_40 ] ) {
V_129 = F_128 ( V_23 , V_177 ) ;
if ( V_129 < 0 )
return V_129 ;
}
if ( V_177 [ V_30 ] ) {
V_129 = F_132 ( V_23 , V_177 ) ;
if ( V_129 < 0 )
return V_129 ;
}
if ( V_177 [ V_24 ] ) {
V_129 = F_126 ( V_23 , V_177 ) ;
if ( V_129 < 0 )
return V_129 ;
}
if ( V_177 [ V_33 ] ) {
V_129 = F_134 ( V_23 , V_177 ) ;
if ( V_129 < 0 )
return V_129 ;
}
#if F_142 ( F_68 )
if ( V_177 [ V_64 ] )
V_23 -> V_65 = F_106 ( F_107 ( V_177 [ V_64 ] ) ) ;
#endif
if ( V_177 [ V_92 ] || V_177 [ V_94 ] ) {
V_129 = F_136 ( V_23 , V_177 ) ;
if ( V_129 < 0 )
return V_129 ;
}
if ( V_177 [ V_77 ] ) {
V_129 = F_137 ( V_23 , V_177 ) ;
if ( V_129 < 0 )
return V_129 ;
}
return 0 ;
}
static struct V_22 *
F_143 ( struct V_127 * V_127 , T_4 V_180 ,
const struct V_8 * const V_177 [] ,
struct V_3 * V_233 ,
struct V_3 * V_234 ,
T_5 V_189 )
{
struct V_22 * V_23 ;
int V_129 = - V_176 ;
struct V_37 * V_38 ;
struct V_57 * V_58 ;
V_23 = F_144 ( V_127 , V_180 , V_233 , V_234 , V_140 ) ;
if ( F_145 ( V_23 ) )
return F_146 ( - V_200 ) ;
if ( ! V_177 [ V_30 ] )
goto V_235;
V_23 -> V_26 . V_27 = F_106 ( F_107 ( V_177 [ V_30 ] ) ) ;
V_23 -> V_26 . V_27 = V_28 + V_23 -> V_26 . V_27 * V_29 ;
F_8 () ;
if ( V_177 [ V_40 ] ) {
char * V_224 = NULL ;
struct V_8 * V_183 = NULL ;
V_129 = F_100 ( V_177 [ V_40 ] , & V_224 , & V_183 ) ;
if ( V_129 < 0 )
goto V_236;
V_38 = F_131 ( V_224 , F_17 ( V_23 ) ,
F_18 ( V_23 ) ) ;
if ( V_38 == NULL ) {
F_11 () ;
#ifdef F_122
if ( F_124 ( L_4 , V_224 ) < 0 ) {
V_129 = - V_181 ;
goto V_235;
}
F_8 () ;
V_38 = F_131 ( V_224 ,
F_17 ( V_23 ) ,
F_18 ( V_23 ) ) ;
if ( V_38 ) {
V_129 = - V_149 ;
goto V_236;
}
F_11 () ;
#endif
V_129 = - V_181 ;
goto V_235;
} else {
struct V_35 * V_36 ;
V_36 = F_147 ( V_23 , V_38 , V_140 ) ;
if ( V_36 == NULL ) {
V_129 = - V_200 ;
goto V_236;
}
if ( V_38 -> V_226 )
V_38 -> V_226 ( V_183 , V_23 ) ;
F_130 ( V_36 -> V_38 , V_38 ) ;
}
} else {
V_129 = F_148 ( V_23 , NULL , V_140 ) ;
if ( V_129 < 0 )
goto V_236;
}
if ( V_177 [ V_222 ] || V_177 [ V_220 ] ) {
V_129 = F_127 ( V_23 , V_177 ) ;
if ( V_129 < 0 )
goto V_236;
}
F_149 ( V_23 , V_140 ) ;
F_150 ( V_23 , V_140 ) ;
F_151 ( V_23 , 0 , 0 , V_140 ) ;
F_152 ( V_23 ) ;
V_23 -> V_25 |= V_213 ;
if ( V_177 [ V_24 ] ) {
V_129 = F_126 ( V_23 , V_177 ) ;
if ( V_129 < 0 )
goto V_236;
}
if ( V_177 [ V_92 ] || V_177 [ V_94 ] ) {
V_129 = F_136 ( V_23 , V_177 ) ;
if ( V_129 < 0 )
goto V_236;
}
memset ( & V_23 -> V_237 , 0 , sizeof( V_23 -> V_237 ) ) ;
if ( V_177 [ V_33 ] ) {
V_129 = F_134 ( V_23 , V_177 ) ;
if ( V_129 < 0 )
goto V_236;
}
#if F_142 ( F_68 )
if ( V_177 [ V_64 ] )
V_23 -> V_65 = F_106 ( F_107 ( V_177 [ V_64 ] ) ) ;
#endif
if ( V_177 [ V_79 ] ) {
struct V_3 V_225 ;
struct V_155 * V_238 ;
struct V_22 * V_239 ;
V_129 = F_95 ( V_177 , & V_225 , V_79 , V_189 ) ;
if ( V_129 < 0 )
goto V_236;
V_238 = F_105 ( V_127 , V_180 , & V_225 ) ;
if ( V_238 == NULL ) {
V_129 = - V_190 ;
goto V_236;
}
V_239 = F_85 ( V_238 ) ;
F_153 ( V_240 , & V_23 -> V_25 ) ;
V_23 -> V_225 = V_239 ;
}
V_58 = F_31 ( V_23 ) ;
if ( V_58 )
V_58 -> V_61 = F_154 ( F_155 () ) ;
V_129 = F_156 ( V_23 ) ;
if ( V_129 < 0 )
goto V_236;
F_11 () ;
return V_23 ;
V_236:
F_11 () ;
V_235:
F_157 ( V_23 ) ;
return F_146 ( V_129 ) ;
}
static int
F_158 ( struct V_187 * V_188 , struct V_1 * V_2 ,
const struct V_100 * V_101 ,
const struct V_8 * const V_177 [] )
{
struct V_127 * V_127 = F_81 ( V_188 ) ;
struct V_3 V_233 , V_234 ;
struct V_155 * V_156 = NULL ;
struct V_102 * V_103 = F_51 ( V_101 ) ;
struct V_22 * V_23 ;
V_121 V_189 = V_103 -> V_110 ;
T_4 V_180 ;
int V_129 ;
V_129 = F_96 ( V_177 [ V_116 ] , & V_180 ) ;
if ( V_129 < 0 )
return V_129 ;
if ( V_177 [ V_114 ] ) {
V_129 = F_95 ( V_177 , & V_233 , V_114 , V_189 ) ;
if ( V_129 < 0 )
return V_129 ;
}
if ( V_177 [ V_115 ] ) {
V_129 = F_95 ( V_177 , & V_234 , V_115 , V_189 ) ;
if ( V_129 < 0 )
return V_129 ;
}
if ( V_177 [ V_114 ] )
V_156 = F_105 ( V_127 , V_180 , & V_233 ) ;
else if ( V_177 [ V_115 ] )
V_156 = F_105 ( V_127 , V_180 , & V_234 ) ;
if ( V_156 == NULL ) {
V_129 = - V_190 ;
if ( V_101 -> V_193 & V_135 ) {
enum V_241 V_124 ;
if ( ! V_177 [ V_114 ] || ! V_177 [ V_115 ] )
return - V_176 ;
V_23 = F_143 ( V_127 , V_180 , V_177 , & V_233 ,
& V_234 , V_189 ) ;
if ( F_145 ( V_23 ) )
return F_159 ( V_23 ) ;
V_129 = 0 ;
if ( F_160 ( V_240 , & V_23 -> V_25 ) )
V_124 = V_134 ;
else
V_124 = V_133 ;
if ( V_177 [ V_77 ] &&
F_137 ( V_23 , V_177 ) == 0 )
V_124 |= ( 1 << V_145 ) ;
F_161 ( ( 1 << V_242 ) |
( 1 << V_243 ) |
( 1 << V_143 ) |
( 1 << V_142 ) |
( 1 << V_146 ) |
( 1 << V_147 ) | V_124 ,
V_23 , F_86 ( V_2 ) . V_99 ,
F_104 ( V_101 ) ) ;
F_78 ( V_23 ) ;
}
return V_129 ;
}
V_129 = - V_244 ;
V_23 = F_85 ( V_156 ) ;
if ( ! ( V_101 -> V_193 & V_136 ) ) {
F_82 ( & V_162 ) ;
V_129 = F_141 ( V_23 , V_177 ) ;
F_89 ( & V_162 ) ;
if ( V_129 == 0 ) {
F_161 ( ( 1 << V_242 ) |
( 1 << V_243 ) |
( 1 << V_143 ) |
( 1 << V_145 ) |
( 1 << V_142 ) |
( 1 << V_146 ) |
( 1 << V_147 ) ,
V_23 , F_86 ( V_2 ) . V_99 ,
F_104 ( V_101 ) ) ;
}
}
F_78 ( V_23 ) ;
return V_129 ;
}
static int
F_162 ( struct V_1 * V_2 , T_2 V_99 , T_2 V_81 ,
T_6 V_245 , const struct V_246 * V_247 )
{
struct V_100 * V_101 ;
struct V_102 * V_103 ;
unsigned int V_104 = V_99 ? V_105 : 0 , V_106 ;
V_106 = ( V_107 << 8 | V_248 ) ;
V_101 = F_50 ( V_2 , V_99 , V_81 , V_106 , sizeof( * V_103 ) , V_104 ) ;
if ( V_101 == NULL )
goto V_109;
V_103 = F_51 ( V_101 ) ;
V_103 -> V_110 = V_249 ;
V_103 -> V_111 = V_112 ;
V_103 -> V_113 = F_55 ( V_245 ) ;
if ( F_13 ( V_2 , V_250 , F_14 ( V_247 -> V_251 ) ) ||
F_13 ( V_2 , V_252 , F_14 ( V_247 -> V_253 ) ) ||
F_13 ( V_2 , V_254 , F_14 ( V_247 -> V_255 ) ) ||
F_13 ( V_2 , V_256 , F_14 ( V_247 -> V_257 ) ) ||
F_13 ( V_2 , V_258 , F_14 ( V_247 -> V_259 ) ) ||
F_13 ( V_2 , V_260 , F_14 ( V_247 -> V_261 ) ) ||
F_13 ( V_2 , V_262 , F_14 ( V_247 -> V_263 ) ) ||
F_13 ( V_2 , V_264 , F_14 ( V_247 -> V_265 ) ) ||
F_13 ( V_2 , V_266 ,
F_14 ( V_247 -> V_267 ) ) ||
F_13 ( V_2 , V_268 , F_14 ( V_247 -> V_269 ) ) ||
F_13 ( V_2 , V_270 , F_14 ( V_247 -> V_271 ) ) ||
F_13 ( V_2 , V_272 , F_14 ( V_247 -> error ) ) ||
F_13 ( V_2 , V_273 ,
F_14 ( V_247 -> V_274 ) ) )
goto V_12;
F_56 ( V_2 , V_101 ) ;
return V_2 -> V_67 ;
V_12:
V_109:
F_57 ( V_2 , V_101 ) ;
return - 1 ;
}
static int
F_163 ( struct V_1 * V_2 , struct V_150 * V_151 )
{
int V_245 ;
struct V_127 * V_127 = F_81 ( V_2 -> V_153 ) ;
if ( V_151 -> args [ 0 ] == V_275 )
return 0 ;
for ( V_245 = V_151 -> args [ 0 ] ; V_245 < V_275 ; V_245 ++ ) {
const struct V_246 * V_247 ;
if ( ! F_164 ( V_245 ) )
continue;
V_247 = F_165 ( V_127 -> V_23 . V_276 , V_245 ) ;
if ( F_162 ( V_2 ,
F_86 ( V_151 -> V_2 ) . V_99 ,
V_151 -> V_101 -> V_167 ,
V_245 , V_247 ) < 0 )
break;
}
V_151 -> args [ 0 ] = V_245 ;
return V_2 -> V_67 ;
}
static int
F_166 ( struct V_187 * V_188 , struct V_1 * V_2 ,
const struct V_100 * V_101 ,
const struct V_8 * const V_177 [] )
{
if ( V_101 -> V_193 & V_194 ) {
struct V_195 V_196 = {
. V_197 = F_163 ,
} ;
return F_112 ( V_188 , V_2 , V_101 , & V_196 ) ;
}
return 0 ;
}
static int
F_167 ( struct V_1 * V_2 , T_2 V_99 , T_2 V_81 , T_2 type ,
struct V_127 * V_127 )
{
struct V_100 * V_101 ;
struct V_102 * V_103 ;
unsigned int V_104 = V_99 ? V_105 : 0 , V_106 ;
unsigned int V_277 = F_48 ( & V_127 -> V_23 . V_278 ) ;
V_106 = ( V_107 << 8 | V_279 ) ;
V_101 = F_50 ( V_2 , V_99 , V_81 , V_106 , sizeof( * V_103 ) , V_104 ) ;
if ( V_101 == NULL )
goto V_109;
V_103 = F_51 ( V_101 ) ;
V_103 -> V_110 = V_249 ;
V_103 -> V_111 = V_112 ;
V_103 -> V_113 = 0 ;
if ( F_13 ( V_2 , V_280 , F_14 ( V_277 ) ) )
goto V_12;
F_56 ( V_2 , V_101 ) ;
return V_2 -> V_67 ;
V_12:
V_109:
F_57 ( V_2 , V_101 ) ;
return - 1 ;
}
static int
F_168 ( struct V_187 * V_188 , struct V_1 * V_2 ,
const struct V_100 * V_101 ,
const struct V_8 * const V_177 [] )
{
struct V_1 * V_192 ;
int V_129 ;
V_192 = F_73 ( V_201 , V_202 ) ;
if ( V_192 == NULL )
return - V_200 ;
V_129 = F_167 ( V_192 , F_86 ( V_2 ) . V_99 ,
V_101 -> V_167 ,
F_87 ( V_101 -> V_168 ) ,
F_81 ( V_2 -> V_153 ) ) ;
if ( V_129 <= 0 )
goto free;
V_129 = F_113 ( V_188 , V_192 , F_86 ( V_2 ) . V_99 , V_203 ) ;
if ( V_129 < 0 )
goto V_39;
return 0 ;
free:
F_75 ( V_192 ) ;
V_39:
return V_129 == - V_149 ? - V_148 : V_129 ;
}
static T_3
F_169 ( const struct V_22 * V_23 )
{
return 3 * F_38 ( 0 )
+ 3 * F_38 ( 0 )
+ 3 * F_38 ( 0 )
+ 3 * F_38 ( sizeof( V_121 ) )
+ F_38 ( sizeof( V_122 ) )
+ F_38 ( sizeof( V_122 ) )
+ F_38 ( sizeof( V_122 ) )
+ F_38 ( 0 )
+ F_38 ( 0 )
+ F_38 ( V_123 )
+ F_61 ( V_23 )
#ifdef F_67
+ 2 * F_38 ( 0 )
+ 6 * F_38 ( sizeof( V_122 ) )
#endif
#ifdef F_68
+ F_38 ( sizeof( V_122 ) )
#endif
+ F_58 ( V_23 )
;
}
static int
F_170 ( struct V_1 * V_2 , struct V_22 * V_23 )
{
struct V_8 * V_9 ;
F_8 () ;
V_9 = F_2 ( V_2 , V_114 | V_11 ) ;
if ( ! V_9 )
goto V_12;
if ( F_7 ( V_2 , F_52 ( V_23 , V_91 ) ) < 0 )
goto V_12;
F_5 ( V_2 , V_9 ) ;
V_9 = F_2 ( V_2 , V_115 | V_11 ) ;
if ( ! V_9 )
goto V_12;
if ( F_7 ( V_2 , F_52 ( V_23 , V_93 ) ) < 0 )
goto V_12;
F_5 ( V_2 , V_9 ) ;
if ( F_53 ( V_23 ) ) {
if ( F_54 ( V_2 , V_116 , F_55 ( F_53 ( V_23 ) ) ) )
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
if ( V_23 -> V_69 && F_33 ( V_2 , V_23 ) < 0 )
goto V_12;
#endif
if ( V_23 -> V_225 && F_41 ( V_2 , V_23 ) < 0 )
goto V_12;
if ( ( V_23 -> V_25 & V_90 ) &&
F_44 ( V_2 , V_23 ) < 0 )
goto V_12;
#ifdef F_68
if ( V_23 -> V_65 && F_32 ( V_2 , V_23 ) < 0 )
goto V_12;
#endif
if ( F_39 ( V_2 , V_23 ) < 0 )
goto V_12;
F_11 () ;
return 0 ;
V_12:
F_11 () ;
return - V_281 ;
}
static int
F_171 ( const struct V_8 * V_177 [] , struct V_22 * V_23 )
{
int V_129 ;
if ( V_177 [ V_30 ] ) {
V_129 = F_132 ( V_23 , V_177 ) ;
if ( V_129 < 0 )
return V_129 ;
}
if ( V_177 [ V_24 ] ) {
V_129 = F_126 ( V_23 , V_177 ) ;
if ( V_129 < 0 )
return V_129 ;
}
if ( V_177 [ V_40 ] ) {
V_129 = F_128 ( V_23 , V_177 ) ;
if ( V_129 < 0 )
return V_129 ;
}
if ( V_177 [ V_77 ] ) {
V_129 = F_137 ( V_23 , V_177 ) ;
if ( V_129 < 0 )
return V_129 ;
}
#if F_142 ( F_68 )
if ( V_177 [ V_64 ] )
V_23 -> V_65 = F_106 ( F_107 ( V_177 [ V_64 ] ) ) ;
#endif
return 0 ;
}
static int
F_172 ( const struct V_8 * V_169 , struct V_22 * V_23 )
{
struct V_8 * V_177 [ V_282 + 1 ] ;
int V_7 ;
V_7 = F_91 ( V_177 , V_282 , V_169 , V_283 ) ;
if ( V_7 < 0 )
return V_7 ;
F_82 ( & V_162 ) ;
V_7 = F_171 ( ( const struct V_8 * * ) V_177 , V_23 ) ;
F_89 ( & V_162 ) ;
return V_7 ;
}
static int F_173 ( const struct V_8 * const * V_177 ,
const struct V_22 * V_23 ,
struct V_3 * V_4 ,
struct V_3 * V_165 )
{
int V_129 ;
V_129 = F_95 ( V_177 , V_4 , V_284 ,
F_17 ( V_23 ) ) ;
if ( V_129 < 0 )
return V_129 ;
return F_95 ( V_177 , V_165 , V_285 ,
F_17 ( V_23 ) ) ;
}
static int
F_174 ( const struct V_8 * V_169 , struct V_22 * V_23 ,
T_2 V_99 , T_2 V_139 )
{
struct V_8 * V_177 [ V_286 + 1 ] ;
struct V_3 V_4 , V_165 ;
struct V_37 * V_38 = NULL ;
struct V_287 * exp ;
int V_129 ;
V_129 = F_91 ( V_177 , V_286 , V_169 , V_288 ) ;
if ( V_129 < 0 )
return V_129 ;
V_129 = F_173 ( ( const struct V_8 * const * ) V_177 ,
V_23 , & V_4 , & V_165 ) ;
if ( V_129 < 0 )
return V_129 ;
if ( V_177 [ V_289 ] ) {
const char * V_224 = F_101 ( V_177 [ V_289 ] ) ;
V_38 = F_131 ( V_224 , F_17 ( V_23 ) ,
F_18 ( V_23 ) ) ;
if ( V_38 == NULL )
return - V_181 ;
}
exp = F_175 ( ( const struct V_8 * const * ) V_177 , V_23 ,
V_38 , & V_4 , & V_165 ) ;
if ( F_145 ( exp ) )
return F_159 ( exp ) ;
V_129 = F_176 ( exp , V_99 , V_139 ) ;
if ( V_129 < 0 ) {
F_177 ( exp ) ;
return V_129 ;
}
return 0 ;
}
static inline int
F_178 ( struct V_1 * V_2 ,
const struct V_3 * V_4 ,
enum V_290 type )
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
F_179 ( struct V_1 * V_2 ,
const struct V_3 * V_4 ,
const struct V_291 * V_165 )
{
int V_7 ;
struct V_17 * V_18 ;
struct V_5 * V_6 ;
struct V_3 V_292 ;
struct V_8 * V_9 ;
memset ( & V_292 , 0xFF , sizeof( V_292 ) ) ;
memcpy ( & V_292 . V_20 . V_189 , & V_165 -> V_20 . V_189 , sizeof( V_292 . V_20 . V_189 ) ) ;
V_292 . V_20 . V_293 . V_294 = V_165 -> V_20 . V_293 . V_294 ;
V_292 . V_14 . V_15 = V_4 -> V_14 . V_15 ;
V_9 = F_2 ( V_2 , V_285 | V_11 ) ;
if ( ! V_9 )
goto V_12;
F_8 () ;
V_18 = F_9 ( V_4 -> V_20 . V_21 ) ;
V_7 = F_6 ( V_2 , & V_292 , V_18 ) ;
if ( V_7 >= 0 ) {
V_6 = F_10 ( V_4 -> V_20 . V_21 ,
V_4 -> V_14 . V_15 ) ;
V_7 = F_1 ( V_2 , & V_292 , V_6 ) ;
}
F_11 () ;
if ( F_180 ( V_7 < 0 ) )
goto V_12;
F_5 ( V_2 , V_9 ) ;
return 0 ;
V_12:
return - 1 ;
}
static int
F_181 ( struct V_1 * V_2 ,
const struct V_287 * exp )
{
struct V_22 * V_225 = exp -> V_225 ;
long V_26 = ( ( long ) exp -> V_26 . V_27 - ( long ) V_28 ) / V_29 ;
struct V_35 * V_36 ;
#ifdef F_67
struct V_8 * V_9 ;
struct V_3 V_295 = {} ;
#endif
struct V_296 * V_297 ;
if ( V_26 < 0 )
V_26 = 0 ;
if ( F_178 ( V_2 , & exp -> V_4 , V_284 ) < 0 )
goto V_12;
if ( F_179 ( V_2 , & exp -> V_4 , & exp -> V_165 ) < 0 )
goto V_12;
if ( F_178 ( V_2 ,
& V_225 -> V_298 [ V_91 ] . V_4 ,
V_299 ) < 0 )
goto V_12;
#ifdef F_67
if ( ! F_182 ( & exp -> V_300 , & V_301 ) ||
exp -> V_302 . V_294 ) {
V_9 = F_2 ( V_2 , V_303 | V_11 ) ;
if ( ! V_9 )
goto V_12;
if ( F_13 ( V_2 , V_304 , F_14 ( exp -> V_46 ) ) )
goto V_12;
V_295 . V_20 . V_21 = F_17 ( V_225 ) ;
V_295 . V_20 . V_189 = exp -> V_300 ;
V_295 . V_14 . V_15 = F_18 ( V_225 ) ;
V_295 . V_20 . V_293 = exp -> V_302 ;
if ( F_178 ( V_2 , & V_295 ,
V_305 ) < 0 )
goto V_12;
F_5 ( V_2 , V_9 ) ;
}
#endif
if ( F_13 ( V_2 , V_306 , F_14 ( V_26 ) ) ||
F_13 ( V_2 , V_307 , F_14 ( ( unsigned long ) exp ) ) ||
F_13 ( V_2 , V_308 , F_14 ( exp -> V_104 ) ) ||
F_13 ( V_2 , V_309 , F_14 ( exp -> V_310 ) ) )
goto V_12;
V_36 = F_20 ( V_225 ) ;
if ( V_36 ) {
struct V_37 * V_38 ;
V_38 = F_21 ( V_36 -> V_38 ) ;
if ( V_38 &&
F_22 ( V_2 , V_289 , V_38 -> V_42 ) )
goto V_12;
}
V_297 = F_183 ( exp -> V_311 ) ;
if ( V_297 != NULL &&
F_22 ( V_2 , V_312 , V_297 -> V_42 ) )
goto V_12;
return 0 ;
V_12:
return - 1 ;
}
static int
F_184 ( struct V_1 * V_2 , T_2 V_99 , T_2 V_81 ,
int V_106 , const struct V_287 * exp )
{
struct V_100 * V_101 ;
struct V_102 * V_103 ;
unsigned int V_104 = V_99 ? V_105 : 0 ;
V_106 |= V_313 << 8 ;
V_101 = F_50 ( V_2 , V_99 , V_81 , V_106 , sizeof( * V_103 ) , V_104 ) ;
if ( V_101 == NULL )
goto V_109;
V_103 = F_51 ( V_101 ) ;
V_103 -> V_110 = exp -> V_4 . V_20 . V_21 ;
V_103 -> V_111 = V_112 ;
V_103 -> V_113 = 0 ;
if ( F_181 ( V_2 , exp ) < 0 )
goto V_12;
F_56 ( V_2 , V_101 ) ;
return V_2 -> V_67 ;
V_109:
V_12:
F_57 ( V_2 , V_101 ) ;
return - 1 ;
}
static int
F_185 ( unsigned int V_124 , struct V_314 * V_126 )
{
struct V_287 * exp = V_126 -> exp ;
struct V_127 * V_127 = F_186 ( exp ) ;
struct V_100 * V_101 ;
struct V_102 * V_103 ;
struct V_1 * V_2 ;
unsigned int type , V_128 ;
int V_104 = 0 ;
if ( V_124 & ( 1 << V_315 ) ) {
type = V_316 ;
V_128 = V_317 ;
} else if ( V_124 & ( 1 << V_318 ) ) {
type = V_319 ;
V_104 = V_135 | V_136 ;
V_128 = V_320 ;
} else
return 0 ;
if ( ! V_126 -> V_139 && ! F_72 ( V_127 , V_128 ) )
return 0 ;
V_2 = F_73 ( V_201 , V_140 ) ;
if ( V_2 == NULL )
goto V_141;
type |= V_313 << 8 ;
V_101 = F_50 ( V_2 , V_126 -> V_99 , 0 , type , sizeof( * V_103 ) , V_104 ) ;
if ( V_101 == NULL )
goto V_109;
V_103 = F_51 ( V_101 ) ;
V_103 -> V_110 = exp -> V_4 . V_20 . V_21 ;
V_103 -> V_111 = V_112 ;
V_103 -> V_113 = 0 ;
F_8 () ;
if ( F_181 ( V_2 , exp ) < 0 )
goto V_12;
F_11 () ;
F_56 ( V_2 , V_101 ) ;
F_74 ( V_2 , V_127 , V_126 -> V_99 , V_128 , V_126 -> V_139 , V_140 ) ;
return 0 ;
V_12:
F_11 () ;
F_57 ( V_2 , V_101 ) ;
V_109:
F_75 ( V_2 ) ;
V_141:
F_76 ( V_127 , 0 , 0 , - V_148 ) ;
return 0 ;
}
static int F_187 ( struct V_150 * V_151 )
{
if ( V_151 -> args [ 1 ] )
F_177 ( (struct V_287 * ) V_151 -> args [ 1 ] ) ;
return 0 ;
}
static int
F_188 ( struct V_1 * V_2 , struct V_150 * V_151 )
{
struct V_127 * V_127 = F_81 ( V_2 -> V_153 ) ;
struct V_287 * exp , * V_154 ;
struct V_102 * V_103 = F_51 ( V_151 -> V_101 ) ;
V_121 V_18 = V_103 -> V_110 ;
F_8 () ;
V_154 = (struct V_287 * ) V_151 -> args [ 1 ] ;
for (; V_151 -> args [ 0 ] < V_321 ; V_151 -> args [ 0 ] ++ ) {
V_164:
F_189 (exp, &net->ct.expect_hash[cb->args[0]],
hnode) {
if ( V_18 && exp -> V_4 . V_20 . V_21 != V_18 )
continue;
if ( V_151 -> args [ 1 ] ) {
if ( exp != V_154 )
continue;
V_151 -> args [ 1 ] = 0 ;
}
if ( F_184 ( V_2 ,
F_86 ( V_151 -> V_2 ) . V_99 ,
V_151 -> V_101 -> V_167 ,
V_319 ,
exp ) < 0 ) {
if ( ! F_190 ( & exp -> V_98 ) )
continue;
V_151 -> args [ 1 ] = ( unsigned long ) exp ;
goto V_39;
}
}
if ( V_151 -> args [ 1 ] ) {
V_151 -> args [ 1 ] = 0 ;
goto V_164;
}
}
V_39:
F_11 () ;
if ( V_154 )
F_177 ( V_154 ) ;
return V_2 -> V_67 ;
}
static int
F_191 ( struct V_1 * V_2 , struct V_150 * V_151 )
{
struct V_287 * exp , * V_154 ;
struct V_102 * V_103 = F_51 ( V_151 -> V_101 ) ;
struct V_22 * V_23 = V_151 -> V_152 ;
struct V_35 * V_36 = F_20 ( V_23 ) ;
V_121 V_18 = V_103 -> V_110 ;
if ( V_151 -> args [ 0 ] )
return 0 ;
F_8 () ;
V_154 = (struct V_287 * ) V_151 -> args [ 1 ] ;
V_164:
F_189 (exp, &help->expectations, lnode) {
if ( V_18 && exp -> V_4 . V_20 . V_21 != V_18 )
continue;
if ( V_151 -> args [ 1 ] ) {
if ( exp != V_154 )
continue;
V_151 -> args [ 1 ] = 0 ;
}
if ( F_184 ( V_2 , F_86 ( V_151 -> V_2 ) . V_99 ,
V_151 -> V_101 -> V_167 ,
V_319 ,
exp ) < 0 ) {
if ( ! F_190 ( & exp -> V_98 ) )
continue;
V_151 -> args [ 1 ] = ( unsigned long ) exp ;
goto V_39;
}
}
if ( V_151 -> args [ 1 ] ) {
V_151 -> args [ 1 ] = 0 ;
goto V_164;
}
V_151 -> args [ 0 ] = 1 ;
V_39:
F_11 () ;
if ( V_154 )
F_177 ( V_154 ) ;
return V_2 -> V_67 ;
}
static int F_192 ( struct V_187 * V_188 , struct V_1 * V_2 ,
const struct V_100 * V_101 ,
const struct V_8 * const V_177 [] )
{
int V_129 ;
struct V_127 * V_127 = F_81 ( V_188 ) ;
struct V_102 * V_103 = F_51 ( V_101 ) ;
V_121 V_189 = V_103 -> V_110 ;
struct V_3 V_4 ;
struct V_155 * V_156 ;
struct V_22 * V_23 ;
T_4 V_180 = 0 ;
struct V_195 V_196 = {
. V_197 = F_191 ,
. V_198 = F_187 ,
} ;
V_129 = F_95 ( V_177 , & V_4 , V_299 , V_189 ) ;
if ( V_129 < 0 )
return V_129 ;
if ( V_177 [ V_322 ] ) {
V_129 = F_96 ( V_177 [ V_322 ] , & V_180 ) ;
if ( V_129 < 0 )
return V_129 ;
}
V_156 = F_105 ( V_127 , V_180 , & V_4 ) ;
if ( ! V_156 )
return - V_190 ;
V_23 = F_85 ( V_156 ) ;
V_196 . V_152 = V_23 ;
V_129 = F_112 ( V_188 , V_2 , V_101 , & V_196 ) ;
F_78 ( V_23 ) ;
return V_129 ;
}
static int
F_193 ( struct V_187 * V_188 , struct V_1 * V_2 ,
const struct V_100 * V_101 ,
const struct V_8 * const V_177 [] )
{
struct V_127 * V_127 = F_81 ( V_188 ) ;
struct V_3 V_4 ;
struct V_287 * exp ;
struct V_1 * V_192 ;
struct V_102 * V_103 = F_51 ( V_101 ) ;
V_121 V_189 = V_103 -> V_110 ;
T_4 V_180 ;
int V_129 ;
if ( V_101 -> V_193 & V_194 ) {
if ( V_177 [ V_299 ] )
return F_192 ( V_188 , V_2 , V_101 , V_177 ) ;
else {
struct V_195 V_196 = {
. V_197 = F_188 ,
. V_198 = F_187 ,
} ;
return F_112 ( V_188 , V_2 , V_101 , & V_196 ) ;
}
}
V_129 = F_96 ( V_177 [ V_322 ] , & V_180 ) ;
if ( V_129 < 0 )
return V_129 ;
if ( V_177 [ V_284 ] )
V_129 = F_95 ( V_177 , & V_4 , V_284 , V_189 ) ;
else if ( V_177 [ V_299 ] )
V_129 = F_95 ( V_177 , & V_4 , V_299 , V_189 ) ;
else
return - V_176 ;
if ( V_129 < 0 )
return V_129 ;
exp = F_194 ( V_127 , V_180 , & V_4 ) ;
if ( ! exp )
return - V_190 ;
if ( V_177 [ V_307 ] ) {
T_7 V_191 = F_107 ( V_177 [ V_307 ] ) ;
if ( F_106 ( V_191 ) != ( T_2 ) ( unsigned long ) exp ) {
F_177 ( exp ) ;
return - V_190 ;
}
}
V_129 = - V_200 ;
V_192 = F_73 ( V_201 , V_202 ) ;
if ( V_192 == NULL ) {
F_177 ( exp ) ;
goto V_39;
}
F_8 () ;
V_129 = F_184 ( V_192 , F_86 ( V_2 ) . V_99 ,
V_101 -> V_167 , V_319 , exp ) ;
F_11 () ;
F_177 ( exp ) ;
if ( V_129 <= 0 )
goto free;
V_129 = F_113 ( V_188 , V_192 , F_86 ( V_2 ) . V_99 , V_203 ) ;
if ( V_129 < 0 )
goto V_39;
return 0 ;
free:
F_75 ( V_192 ) ;
V_39:
return V_129 == - V_149 ? - V_148 : V_129 ;
}
static int
F_195 ( struct V_187 * V_188 , struct V_1 * V_2 ,
const struct V_100 * V_101 ,
const struct V_8 * const V_177 [] )
{
struct V_127 * V_127 = F_81 ( V_188 ) ;
struct V_287 * exp ;
struct V_3 V_4 ;
struct V_102 * V_103 = F_51 ( V_101 ) ;
struct V_323 * V_324 ;
V_121 V_189 = V_103 -> V_110 ;
unsigned int V_75 ;
T_4 V_180 ;
int V_129 ;
if ( V_177 [ V_284 ] ) {
V_129 = F_96 ( V_177 [ V_322 ] , & V_180 ) ;
if ( V_129 < 0 )
return V_129 ;
V_129 = F_95 ( V_177 , & V_4 , V_284 , V_189 ) ;
if ( V_129 < 0 )
return V_129 ;
exp = F_194 ( V_127 , V_180 , & V_4 ) ;
if ( ! exp )
return - V_190 ;
if ( V_177 [ V_307 ] ) {
T_7 V_191 = F_107 ( V_177 [ V_307 ] ) ;
if ( F_106 ( V_191 ) != ( T_2 ) ( unsigned long ) exp ) {
F_177 ( exp ) ;
return - V_190 ;
}
}
F_82 ( & V_162 ) ;
if ( F_108 ( & exp -> V_26 ) ) {
F_196 ( exp , F_86 ( V_2 ) . V_99 ,
F_104 ( V_101 ) ) ;
F_177 ( exp ) ;
}
F_89 ( & V_162 ) ;
F_177 ( exp ) ;
} else if ( V_177 [ V_289 ] ) {
char * V_42 = F_101 ( V_177 [ V_289 ] ) ;
struct V_35 * V_325 ;
F_82 ( & V_162 ) ;
for ( V_75 = 0 ; V_75 < V_321 ; V_75 ++ ) {
F_197 (exp, next,
&net->ct.expect_hash[i],
hnode) {
V_325 = F_20 ( exp -> V_225 ) ;
if ( ! strcmp ( V_325 -> V_38 -> V_42 , V_42 ) &&
F_108 ( & exp -> V_26 ) ) {
F_196 ( exp ,
F_86 ( V_2 ) . V_99 ,
F_104 ( V_101 ) ) ;
F_177 ( exp ) ;
}
}
}
F_89 ( & V_162 ) ;
} else {
F_82 ( & V_162 ) ;
for ( V_75 = 0 ; V_75 < V_321 ; V_75 ++ ) {
F_197 (exp, next,
&net->ct.expect_hash[i],
hnode) {
if ( F_108 ( & exp -> V_26 ) ) {
F_196 ( exp ,
F_86 ( V_2 ) . V_99 ,
F_104 ( V_101 ) ) ;
F_177 ( exp ) ;
}
}
}
F_89 ( & V_162 ) ;
}
return 0 ;
}
static int
F_198 ( struct V_287 * V_326 ,
const struct V_8 * const V_177 [] )
{
if ( V_177 [ V_306 ] ) {
if ( ! F_108 ( & V_326 -> V_26 ) )
return - V_227 ;
V_326 -> V_26 . V_27 = V_28 +
F_106 ( F_107 ( V_177 [ V_306 ] ) ) * V_29 ;
F_133 ( & V_326 -> V_26 ) ;
}
return 0 ;
}
static int
F_199 ( const struct V_8 * V_169 ,
struct V_287 * exp ,
V_121 V_189 )
{
#ifdef F_67
struct V_8 * V_170 [ V_327 + 1 ] ;
struct V_3 V_295 = {} ;
int V_129 ;
V_129 = F_91 ( V_170 , V_327 , V_169 , V_328 ) ;
if ( V_129 < 0 )
return V_129 ;
if ( ! V_170 [ V_304 ] || ! V_170 [ V_305 ] )
return - V_176 ;
V_129 = F_95 ( ( const struct V_8 * const * ) V_170 ,
& V_295 , V_305 , V_189 ) ;
if ( V_129 < 0 )
return V_129 ;
exp -> V_300 = V_295 . V_20 . V_189 ;
exp -> V_302 = V_295 . V_20 . V_293 ;
exp -> V_46 = F_106 ( F_107 ( V_170 [ V_304 ] ) ) ;
return 0 ;
#else
return - V_181 ;
#endif
}
static struct V_287 *
F_175 ( const struct V_8 * const V_177 [] , struct V_22 * V_23 ,
struct V_37 * V_38 ,
struct V_3 * V_4 ,
struct V_3 * V_165 )
{
V_122 V_310 = 0 ;
struct V_287 * exp ;
struct V_35 * V_36 ;
int V_129 ;
if ( V_177 [ V_309 ] && V_38 ) {
V_310 = F_106 ( F_107 ( V_177 [ V_309 ] ) ) ;
if ( V_310 > V_38 -> V_329 )
return F_146 ( - V_176 ) ;
}
exp = F_200 ( V_23 ) ;
if ( ! exp )
return F_146 ( - V_200 ) ;
V_36 = F_20 ( V_23 ) ;
if ( ! V_36 ) {
if ( ! V_177 [ V_306 ] ) {
V_129 = - V_176 ;
goto V_330;
}
exp -> V_26 . V_27 =
V_28 + F_106 ( F_107 ( V_177 [ V_306 ] ) ) * V_29 ;
exp -> V_104 = V_331 ;
if ( V_177 [ V_308 ] ) {
exp -> V_104 |=
F_106 ( F_107 ( V_177 [ V_308 ] ) ) ;
}
} else {
if ( V_177 [ V_308 ] ) {
exp -> V_104 = F_106 ( F_107 ( V_177 [ V_308 ] ) ) ;
exp -> V_104 &= ~ V_331 ;
} else
exp -> V_104 = 0 ;
}
if ( V_177 [ V_312 ] ) {
const char * V_42 = F_101 ( V_177 [ V_312 ] ) ;
struct V_296 * V_297 ;
V_297 = F_201 ( V_42 ) ;
if ( V_297 == NULL ) {
V_129 = - V_176 ;
goto V_330;
}
exp -> V_311 = V_297 -> V_311 ;
} else
exp -> V_311 = NULL ;
exp -> V_310 = V_310 ;
exp -> V_225 = V_23 ;
exp -> V_38 = V_38 ;
exp -> V_4 = * V_4 ;
exp -> V_165 . V_20 . V_189 = V_165 -> V_20 . V_189 ;
exp -> V_165 . V_20 . V_293 . V_294 = V_165 -> V_20 . V_293 . V_294 ;
if ( V_177 [ V_303 ] ) {
V_129 = F_199 ( V_177 [ V_303 ] ,
exp , F_17 ( V_23 ) ) ;
if ( V_129 < 0 )
goto V_330;
}
return exp ;
V_330:
F_177 ( exp ) ;
return F_146 ( V_129 ) ;
}
static int
F_202 ( struct V_127 * V_127 , T_4 V_180 ,
const struct V_8 * const V_177 [] ,
V_121 V_189 , T_2 V_99 , int V_139 )
{
struct V_3 V_4 , V_165 , F_42 ;
struct V_155 * V_156 = NULL ;
struct V_37 * V_38 = NULL ;
struct V_287 * exp ;
struct V_22 * V_23 ;
int V_129 ;
V_129 = F_95 ( V_177 , & V_4 , V_284 , V_189 ) ;
if ( V_129 < 0 )
return V_129 ;
V_129 = F_95 ( V_177 , & V_165 , V_285 , V_189 ) ;
if ( V_129 < 0 )
return V_129 ;
V_129 = F_95 ( V_177 , & F_42 , V_299 , V_189 ) ;
if ( V_129 < 0 )
return V_129 ;
V_156 = F_105 ( V_127 , V_180 , & F_42 ) ;
if ( ! V_156 )
return - V_190 ;
V_23 = F_85 ( V_156 ) ;
if ( V_177 [ V_289 ] ) {
const char * V_224 = F_101 ( V_177 [ V_289 ] ) ;
V_38 = F_131 ( V_224 , V_189 ,
F_18 ( V_23 ) ) ;
if ( V_38 == NULL ) {
#ifdef F_122
if ( F_124 ( L_4 , V_224 ) < 0 ) {
V_129 = - V_181 ;
goto V_332;
}
V_38 = F_131 ( V_224 , V_189 ,
F_18 ( V_23 ) ) ;
if ( V_38 ) {
V_129 = - V_149 ;
goto V_332;
}
#endif
V_129 = - V_181 ;
goto V_332;
}
}
exp = F_175 ( V_177 , V_23 , V_38 , & V_4 , & V_165 ) ;
if ( F_145 ( exp ) ) {
V_129 = F_159 ( exp ) ;
goto V_332;
}
V_129 = F_176 ( exp , V_99 , V_139 ) ;
if ( V_129 < 0 )
goto V_333;
return 0 ;
V_333:
F_177 ( exp ) ;
V_332:
F_78 ( V_23 ) ;
return V_129 ;
}
static int
F_203 ( struct V_187 * V_188 , struct V_1 * V_2 ,
const struct V_100 * V_101 ,
const struct V_8 * const V_177 [] )
{
struct V_127 * V_127 = F_81 ( V_188 ) ;
struct V_3 V_4 ;
struct V_287 * exp ;
struct V_102 * V_103 = F_51 ( V_101 ) ;
V_121 V_189 = V_103 -> V_110 ;
T_4 V_180 ;
int V_129 ;
if ( ! V_177 [ V_284 ]
|| ! V_177 [ V_285 ]
|| ! V_177 [ V_299 ] )
return - V_176 ;
V_129 = F_96 ( V_177 [ V_322 ] , & V_180 ) ;
if ( V_129 < 0 )
return V_129 ;
V_129 = F_95 ( V_177 , & V_4 , V_284 , V_189 ) ;
if ( V_129 < 0 )
return V_129 ;
F_82 ( & V_162 ) ;
exp = F_204 ( V_127 , V_180 , & V_4 ) ;
if ( ! exp ) {
F_89 ( & V_162 ) ;
V_129 = - V_190 ;
if ( V_101 -> V_193 & V_135 ) {
V_129 = F_202 ( V_127 , V_180 , V_177 ,
V_189 ,
F_86 ( V_2 ) . V_99 ,
F_104 ( V_101 ) ) ;
}
return V_129 ;
}
V_129 = - V_244 ;
if ( ! ( V_101 -> V_193 & V_136 ) )
V_129 = F_198 ( exp , V_177 ) ;
F_89 ( & V_162 ) ;
return V_129 ;
}
static int
F_205 ( struct V_1 * V_2 , T_2 V_99 , T_2 V_81 , int V_245 ,
const struct V_246 * V_247 )
{
struct V_100 * V_101 ;
struct V_102 * V_103 ;
unsigned int V_104 = V_99 ? V_105 : 0 , V_106 ;
V_106 = ( V_107 << 8 | V_334 ) ;
V_101 = F_50 ( V_2 , V_99 , V_81 , V_106 , sizeof( * V_103 ) , V_104 ) ;
if ( V_101 == NULL )
goto V_109;
V_103 = F_51 ( V_101 ) ;
V_103 -> V_110 = V_249 ;
V_103 -> V_111 = V_112 ;
V_103 -> V_113 = F_55 ( V_245 ) ;
if ( F_13 ( V_2 , V_335 , F_14 ( V_247 -> V_336 ) ) ||
F_13 ( V_2 , V_337 , F_14 ( V_247 -> V_338 ) ) ||
F_13 ( V_2 , V_339 , F_14 ( V_247 -> V_340 ) ) )
goto V_12;
F_56 ( V_2 , V_101 ) ;
return V_2 -> V_67 ;
V_12:
V_109:
F_57 ( V_2 , V_101 ) ;
return - 1 ;
}
static int
F_206 ( struct V_1 * V_2 , struct V_150 * V_151 )
{
int V_245 ;
struct V_127 * V_127 = F_81 ( V_2 -> V_153 ) ;
if ( V_151 -> args [ 0 ] == V_275 )
return 0 ;
for ( V_245 = V_151 -> args [ 0 ] ; V_245 < V_275 ; V_245 ++ ) {
const struct V_246 * V_247 ;
if ( ! F_164 ( V_245 ) )
continue;
V_247 = F_165 ( V_127 -> V_23 . V_276 , V_245 ) ;
if ( F_205 ( V_2 , F_86 ( V_151 -> V_2 ) . V_99 ,
V_151 -> V_101 -> V_167 ,
V_245 , V_247 ) < 0 )
break;
}
V_151 -> args [ 0 ] = V_245 ;
return V_2 -> V_67 ;
}
static int
F_207 ( struct V_187 * V_188 , struct V_1 * V_2 ,
const struct V_100 * V_101 ,
const struct V_8 * const V_177 [] )
{
if ( V_101 -> V_193 & V_194 ) {
struct V_195 V_196 = {
. V_197 = F_206 ,
} ;
return F_112 ( V_188 , V_2 , V_101 , & V_196 ) ;
}
return 0 ;
}
static int T_8 F_208 ( struct V_127 * V_127 )
{
#ifdef F_209
int V_7 ;
V_7 = F_210 ( V_127 , & V_341 ) ;
if ( V_7 < 0 ) {
F_211 ( L_5 ) ;
goto V_330;
}
V_7 = F_212 ( V_127 , & V_342 ) ;
if ( V_7 < 0 ) {
F_211 ( L_6 ) ;
goto V_343;
}
#endif
return 0 ;
#ifdef F_209
V_343:
F_213 ( V_127 , & V_341 ) ;
V_330:
return V_7 ;
#endif
}
static void F_214 ( struct V_127 * V_127 )
{
#ifdef F_209
F_215 ( V_127 , & V_342 ) ;
F_213 ( V_127 , & V_341 ) ;
#endif
}
static void T_9 F_216 ( struct V_344 * V_345 )
{
struct V_127 * V_127 ;
F_217 (net, net_exit_list, exit_list)
F_214 ( V_127 ) ;
}
static int T_10 F_218 ( void )
{
int V_7 ;
F_219 ( L_7 , V_111 ) ;
V_7 = F_220 ( & V_346 ) ;
if ( V_7 < 0 ) {
F_211 ( L_8 ) ;
goto V_330;
}
V_7 = F_220 ( & V_347 ) ;
if ( V_7 < 0 ) {
F_211 ( L_9 ) ;
goto V_348;
}
V_7 = F_221 ( & V_349 ) ;
if ( V_7 < 0 ) {
F_211 ( L_10 ) ;
goto V_350;
}
#ifdef F_222
F_130 ( V_351 , & V_352 ) ;
#endif
return 0 ;
V_350:
F_223 ( & V_347 ) ;
V_348:
F_223 ( & V_346 ) ;
V_330:
return V_7 ;
}
static void T_11 F_224 ( void )
{
F_219 ( L_11 ) ;
F_225 ( & V_349 ) ;
F_223 ( & V_347 ) ;
F_223 ( & V_346 ) ;
#ifdef F_222
F_130 ( V_351 , NULL ) ;
#endif
}
