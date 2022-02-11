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
static inline int
F_36 ( struct V_1 * V_2 , const struct V_22 * V_23 )
{
struct V_8 * V_9 ;
if ( ! ( V_23 -> V_25 & V_72 ) )
return 0 ;
V_9 = F_2 ( V_2 , V_73 | V_11 ) ;
if ( ! V_9 )
goto V_12;
if ( F_7 ( V_2 , F_37 ( V_23 ) ) < 0 )
goto V_12;
F_5 ( V_2 , V_9 ) ;
return 0 ;
V_12:
return - 1 ;
}
static int
F_38 ( struct V_1 * V_2 , const struct V_74 * V_75 , int type )
{
struct V_8 * V_9 ;
V_9 = F_2 ( V_2 , type | V_11 ) ;
if ( ! V_9 )
goto V_12;
if ( F_13 ( V_2 , V_76 ,
F_14 ( V_75 -> V_77 ) ) ||
F_13 ( V_2 , V_78 ,
F_14 ( V_75 -> V_79 ) ) ||
F_13 ( V_2 , V_80 ,
F_14 ( V_75 -> V_81 ) ) )
goto V_12;
F_5 ( V_2 , V_9 ) ;
return 0 ;
V_12:
return - 1 ;
}
static inline int
F_39 ( struct V_1 * V_2 , const struct V_22 * V_23 )
{
struct V_74 * V_75 ;
struct V_82 * V_83 = F_40 ( V_23 ) ;
if ( ! ( V_23 -> V_25 & V_84 ) || ! V_83 )
return 0 ;
V_75 = & V_83 -> V_85 [ V_86 ] ;
if ( F_38 ( V_2 , V_75 , V_87 ) == - 1 )
return - 1 ;
V_75 = & V_83 -> V_85 [ V_88 ] ;
if ( F_38 ( V_2 , V_75 , V_89 ) == - 1 )
return - 1 ;
return 0 ;
}
static inline int
F_41 ( struct V_1 * V_2 , const struct V_22 * V_23 )
{
if ( F_13 ( V_2 , V_90 , F_14 ( ( unsigned long ) V_23 ) ) )
goto V_12;
return 0 ;
V_12:
return - 1 ;
}
static inline int
F_42 ( struct V_1 * V_2 , const struct V_22 * V_23 )
{
if ( F_13 ( V_2 , V_91 , F_14 ( F_43 ( & V_23 -> V_92 . V_93 ) ) ) )
goto V_12;
return 0 ;
V_12:
return - 1 ;
}
static int
F_44 ( struct V_1 * V_2 , T_2 V_94 , T_2 V_85 , T_2 type ,
struct V_22 * V_23 )
{
struct V_95 * V_96 ;
struct V_97 * V_98 ;
struct V_8 * V_9 ;
unsigned int V_99 = V_94 ? V_100 : 0 , V_101 ;
V_101 = ( V_102 << 8 | V_103 ) ;
V_96 = F_45 ( V_2 , V_94 , V_85 , V_101 , sizeof( * V_98 ) , V_99 ) ;
if ( V_96 == NULL )
goto V_104;
V_98 = F_46 ( V_96 ) ;
V_98 -> V_105 = F_17 ( V_23 ) ;
V_98 -> V_106 = V_107 ;
V_98 -> V_108 = 0 ;
V_9 = F_2 ( V_2 , V_109 | V_11 ) ;
if ( ! V_9 )
goto V_12;
if ( F_7 ( V_2 , F_47 ( V_23 , V_86 ) ) < 0 )
goto V_12;
F_5 ( V_2 , V_9 ) ;
V_9 = F_2 ( V_2 , V_110 | V_11 ) ;
if ( ! V_9 )
goto V_12;
if ( F_7 ( V_2 , F_47 ( V_23 , V_88 ) ) < 0 )
goto V_12;
F_5 ( V_2 , V_9 ) ;
if ( F_48 ( V_23 ) &&
F_49 ( V_2 , V_111 , F_50 ( F_48 ( V_23 ) ) ) )
goto V_12;
if ( F_12 ( V_2 , V_23 ) < 0 ||
F_15 ( V_2 , V_23 ) < 0 ||
F_26 ( V_2 , V_23 , V_86 , type ) < 0 ||
F_26 ( V_2 , V_23 , V_88 , type ) < 0 ||
F_30 ( V_2 , V_23 ) < 0 ||
F_16 ( V_2 , V_23 ) < 0 ||
F_19 ( V_2 , V_23 ) < 0 ||
F_32 ( V_2 , V_23 ) < 0 ||
F_33 ( V_2 , V_23 ) < 0 ||
F_41 ( V_2 , V_23 ) < 0 ||
F_42 ( V_2 , V_23 ) < 0 ||
F_36 ( V_2 , V_23 ) < 0 ||
F_39 ( V_2 , V_23 ) < 0 )
goto V_12;
F_51 ( V_2 , V_96 ) ;
return V_2 -> V_67 ;
V_104:
V_12:
F_52 ( V_2 , V_96 ) ;
return - 1 ;
}
static inline T_3
F_53 ( const struct V_22 * V_23 )
{
struct V_17 * V_18 ;
struct V_5 * V_6 ;
T_3 V_67 = 0 ;
F_8 () ;
V_18 = F_9 ( F_17 ( V_23 ) ) ;
V_67 += V_18 -> V_112 ;
V_6 = F_10 ( F_17 ( V_23 ) , F_18 ( V_23 ) ) ;
V_67 += V_6 -> V_112 ;
F_11 () ;
return V_67 ;
}
static inline T_3
F_54 ( const struct V_22 * V_23 )
{
if ( ! F_55 ( V_23 , V_113 ) )
return 0 ;
return 2 * F_56 ( 0 )
+ 2 * F_56 ( sizeof( V_114 ) )
+ 2 * F_56 ( sizeof( V_114 ) )
;
}
static inline int
F_57 ( const struct V_22 * V_23 )
{
#ifdef F_58
int V_67 , V_7 ;
V_7 = F_34 ( V_23 -> V_69 , NULL , & V_67 ) ;
if ( V_7 )
return 0 ;
return F_56 ( 0 )
+ F_56 ( sizeof( char ) * V_67 ) ;
#else
return 0 ;
#endif
}
static inline T_3
F_59 ( const struct V_22 * V_23 )
{
#ifdef F_60
if ( ! F_55 ( V_23 , V_115 ) )
return 0 ;
return F_56 ( 0 ) + 2 * F_56 ( sizeof( V_114 ) ) ;
#else
return 0 ;
#endif
}
static inline T_3
F_61 ( const struct V_22 * V_23 )
{
return F_62 ( sizeof( struct V_97 ) )
+ 3 * F_56 ( 0 )
+ 3 * F_56 ( 0 )
+ 3 * F_56 ( 0 )
+ 3 * F_56 ( sizeof( V_116 ) )
+ F_56 ( sizeof( V_117 ) )
+ F_56 ( sizeof( V_117 ) )
+ F_54 ( V_23 )
+ F_59 ( V_23 )
+ F_56 ( sizeof( V_117 ) )
+ F_56 ( 0 )
+ F_56 ( 0 )
+ F_56 ( V_118 )
+ F_57 ( V_23 )
#ifdef F_63
+ 2 * F_56 ( 0 )
+ 6 * F_56 ( sizeof( V_117 ) )
#endif
#ifdef F_64
+ F_56 ( sizeof( V_117 ) )
#endif
+ F_53 ( V_23 )
;
}
static int
F_65 ( unsigned int V_119 , struct V_120 * V_121 )
{
struct V_122 * V_122 ;
struct V_95 * V_96 ;
struct V_97 * V_98 ;
struct V_8 * V_9 ;
struct V_22 * V_23 = V_121 -> V_23 ;
struct V_1 * V_2 ;
unsigned int type ;
unsigned int V_99 = 0 , V_123 ;
int V_124 ;
if ( F_66 ( V_23 ) )
return 0 ;
if ( V_119 & ( 1 << V_125 ) ) {
type = V_126 ;
V_123 = V_127 ;
} else if ( V_119 & ( ( 1 << V_128 ) | ( 1 << V_129 ) ) ) {
type = V_103 ;
V_99 = V_130 | V_131 ;
V_123 = V_132 ;
} else if ( V_119 ) {
type = V_103 ;
V_123 = V_133 ;
} else
return 0 ;
V_122 = F_67 ( V_23 ) ;
if ( ! V_121 -> V_134 && ! F_68 ( V_122 , V_123 ) )
return 0 ;
V_2 = F_69 ( F_61 ( V_23 ) , V_135 ) ;
if ( V_2 == NULL )
goto V_136;
type |= V_102 << 8 ;
V_96 = F_45 ( V_2 , V_121 -> V_94 , 0 , type , sizeof( * V_98 ) , V_99 ) ;
if ( V_96 == NULL )
goto V_104;
V_98 = F_46 ( V_96 ) ;
V_98 -> V_105 = F_17 ( V_23 ) ;
V_98 -> V_106 = V_107 ;
V_98 -> V_108 = 0 ;
F_8 () ;
V_9 = F_2 ( V_2 , V_109 | V_11 ) ;
if ( ! V_9 )
goto V_12;
if ( F_7 ( V_2 , F_47 ( V_23 , V_86 ) ) < 0 )
goto V_12;
F_5 ( V_2 , V_9 ) ;
V_9 = F_2 ( V_2 , V_110 | V_11 ) ;
if ( ! V_9 )
goto V_12;
if ( F_7 ( V_2 , F_47 ( V_23 , V_88 ) ) < 0 )
goto V_12;
F_5 ( V_2 , V_9 ) ;
if ( F_48 ( V_23 ) &&
F_49 ( V_2 , V_111 , F_50 ( F_48 ( V_23 ) ) ) )
goto V_12;
if ( F_41 ( V_2 , V_23 ) < 0 )
goto V_12;
if ( F_12 ( V_2 , V_23 ) < 0 )
goto V_12;
if ( V_119 & ( 1 << V_125 ) ) {
if ( F_26 ( V_2 , V_23 ,
V_86 , type ) < 0 ||
F_26 ( V_2 , V_23 ,
V_88 , type ) < 0 ||
F_30 ( V_2 , V_23 ) < 0 )
goto V_12;
} else {
if ( F_15 ( V_2 , V_23 ) < 0 )
goto V_12;
if ( V_119 & ( 1 << V_137 )
&& F_16 ( V_2 , V_23 ) < 0 )
goto V_12;
if ( ( V_119 & ( 1 << V_138 ) || F_20 ( V_23 ) )
&& F_19 ( V_2 , V_23 ) < 0 )
goto V_12;
#ifdef F_58
if ( ( V_119 & ( 1 << V_139 ) || V_23 -> V_69 )
&& F_33 ( V_2 , V_23 ) < 0 )
goto V_12;
#endif
if ( V_119 & ( 1 << V_129 ) &&
F_36 ( V_2 , V_23 ) < 0 )
goto V_12;
if ( V_119 & ( 1 << V_140 ) &&
F_39 ( V_2 , V_23 ) < 0 )
goto V_12;
}
#ifdef F_64
if ( ( V_119 & ( 1 << V_141 ) || V_23 -> V_65 )
&& F_32 ( V_2 , V_23 ) < 0 )
goto V_12;
#endif
F_11 () ;
F_51 ( V_2 , V_96 ) ;
V_124 = F_70 ( V_2 , V_122 , V_121 -> V_94 , V_123 , V_121 -> V_134 ,
V_135 ) ;
if ( V_124 == - V_142 || V_124 == - V_143 )
return - V_142 ;
return 0 ;
V_12:
F_11 () ;
F_52 ( V_2 , V_96 ) ;
V_104:
F_71 ( V_2 ) ;
V_136:
if ( F_72 ( V_122 , 0 , V_123 , - V_142 ) > 0 )
return - V_142 ;
return 0 ;
}
static int F_73 ( struct V_144 * V_145 )
{
if ( V_145 -> args [ 1 ] )
F_74 ( (struct V_22 * ) V_145 -> args [ 1 ] ) ;
if ( V_145 -> V_146 )
F_75 ( V_145 -> V_146 ) ;
return 0 ;
}
static int
F_76 ( struct V_1 * V_2 , struct V_144 * V_145 )
{
struct V_122 * V_122 = F_77 ( V_2 -> V_147 ) ;
struct V_22 * V_23 , * V_148 ;
struct V_149 * V_150 ;
struct V_151 * V_152 ;
struct V_97 * V_98 = F_46 ( V_145 -> V_96 ) ;
V_116 V_18 = V_98 -> V_105 ;
int V_153 ;
#ifdef F_64
const struct V_154 * V_155 = V_145 -> V_146 ;
#endif
F_78 ( & V_156 ) ;
V_148 = (struct V_22 * ) V_145 -> args [ 1 ] ;
for (; V_145 -> args [ 0 ] < V_122 -> V_23 . V_157 ; V_145 -> args [ 0 ] ++ ) {
V_158:
F_79 (h, n, &net->ct.hash[cb->args[0]],
hnnode) {
if ( F_80 ( V_150 ) != V_86 )
continue;
V_23 = F_81 ( V_150 ) ;
if ( V_18 && F_17 ( V_23 ) != V_18 )
continue;
if ( V_145 -> args [ 1 ] ) {
if ( V_23 != V_148 )
continue;
V_145 -> args [ 1 ] = 0 ;
}
#ifdef F_64
if ( V_155 && ! ( ( V_23 -> V_65 & V_155 -> V_65 . V_159 ) ==
V_155 -> V_65 . V_160 ) ) {
continue;
}
#endif
F_8 () ;
V_153 =
F_44 ( V_2 , F_82 ( V_145 -> V_2 ) . V_94 ,
V_145 -> V_96 -> V_161 ,
F_83 ( V_145 -> V_96 -> V_162 ) ,
V_23 ) ;
F_11 () ;
if ( V_153 < 0 ) {
F_84 ( & V_23 -> V_92 ) ;
V_145 -> args [ 1 ] = ( unsigned long ) V_23 ;
goto V_39;
}
}
if ( V_145 -> args [ 1 ] ) {
V_145 -> args [ 1 ] = 0 ;
goto V_158;
}
}
V_39:
F_85 ( & V_156 ) ;
if ( V_148 )
F_74 ( V_148 ) ;
return V_2 -> V_67 ;
}
static inline int
F_86 ( struct V_8 * V_163 , struct V_3 * V_4 )
{
struct V_8 * V_164 [ V_165 + 1 ] ;
struct V_17 * V_18 ;
int V_7 = 0 ;
F_87 ( V_164 , V_165 , V_163 , NULL ) ;
F_8 () ;
V_18 = F_9 ( V_4 -> V_20 . V_21 ) ;
if ( F_4 ( V_18 -> V_166 ) ) {
V_7 = F_88 ( V_163 , V_165 ,
V_18 -> V_167 ) ;
if ( V_7 == 0 )
V_7 = V_18 -> V_166 ( V_164 , V_4 ) ;
}
F_11 () ;
return V_7 ;
}
static inline int
F_89 ( struct V_8 * V_163 ,
struct V_3 * V_4 )
{
struct V_8 * V_164 [ V_168 + 1 ] ;
struct V_5 * V_6 ;
int V_7 = 0 ;
V_7 = F_87 ( V_164 , V_168 , V_163 , V_169 ) ;
if ( V_7 < 0 )
return V_7 ;
if ( ! V_164 [ V_13 ] )
return - V_170 ;
V_4 -> V_14 . V_15 = F_90 ( V_164 [ V_13 ] ) ;
F_8 () ;
V_6 = F_10 ( V_4 -> V_20 . V_21 , V_4 -> V_14 . V_15 ) ;
if ( F_4 ( V_6 -> V_166 ) ) {
V_7 = F_88 ( V_163 , V_168 ,
V_6 -> V_167 ) ;
if ( V_7 == 0 )
V_7 = V_6 -> V_166 ( V_164 , V_4 ) ;
}
F_11 () ;
return V_7 ;
}
static int
F_91 ( const struct V_8 * const V_171 [] ,
struct V_3 * V_4 ,
enum V_47 type , V_116 V_21 )
{
struct V_8 * V_164 [ V_172 + 1 ] ;
int V_124 ;
memset ( V_4 , 0 , sizeof( * V_4 ) ) ;
F_87 ( V_164 , V_172 , V_171 [ type ] , V_173 ) ;
if ( ! V_164 [ V_19 ] )
return - V_170 ;
V_4 -> V_20 . V_21 = V_21 ;
V_124 = F_86 ( V_164 [ V_19 ] , V_4 ) ;
if ( V_124 < 0 )
return V_124 ;
if ( ! V_164 [ V_10 ] )
return - V_170 ;
V_124 = F_89 ( V_164 [ V_10 ] , V_4 ) ;
if ( V_124 < 0 )
return V_124 ;
if ( type == V_110 )
V_4 -> V_14 . V_46 = V_88 ;
else
V_4 -> V_14 . V_46 = V_86 ;
return 0 ;
}
static int
F_92 ( const struct V_8 * V_163 , T_4 * V_174 )
{
if ( V_163 )
#ifdef F_93
* V_174 = F_94 ( F_95 ( V_163 ) ) ;
#else
return - V_175 ;
#endif
else
* V_174 = 0 ;
return 0 ;
}
static inline int
F_96 ( const struct V_8 * V_163 , char * * V_176 ,
struct V_8 * * V_177 )
{
struct V_8 * V_164 [ V_178 + 1 ] ;
F_87 ( V_164 , V_178 , V_163 , V_179 ) ;
if ( ! V_164 [ V_41 ] )
return - V_170 ;
* V_176 = F_97 ( V_164 [ V_41 ] ) ;
if ( V_164 [ V_180 ] )
* V_177 = V_164 [ V_180 ] ;
return 0 ;
}
static int
F_98 ( struct V_181 * V_182 , struct V_1 * V_2 ,
const struct V_95 * V_96 ,
const struct V_8 * const V_171 [] )
{
struct V_122 * V_122 = F_77 ( V_182 ) ;
struct V_149 * V_150 ;
struct V_3 V_4 ;
struct V_22 * V_23 ;
struct V_97 * V_98 = F_46 ( V_96 ) ;
V_116 V_183 = V_98 -> V_105 ;
T_4 V_174 ;
int V_124 ;
V_124 = F_92 ( V_171 [ V_111 ] , & V_174 ) ;
if ( V_124 < 0 )
return V_124 ;
if ( V_171 [ V_109 ] )
V_124 = F_91 ( V_171 , & V_4 , V_109 , V_183 ) ;
else if ( V_171 [ V_110 ] )
V_124 = F_91 ( V_171 , & V_4 , V_110 , V_183 ) ;
else {
F_99 ( V_122 ,
F_82 ( V_2 ) . V_94 ,
F_100 ( V_96 ) ) ;
return 0 ;
}
if ( V_124 < 0 )
return V_124 ;
V_150 = F_101 ( V_122 , V_174 , & V_4 ) ;
if ( ! V_150 )
return - V_184 ;
V_23 = F_81 ( V_150 ) ;
if ( V_171 [ V_90 ] ) {
V_117 V_185 = F_102 ( F_103 ( V_171 [ V_90 ] ) ) ;
if ( V_185 != ( T_2 ) ( unsigned long ) V_23 ) {
F_74 ( V_23 ) ;
return - V_184 ;
}
}
if ( F_104 ( & V_23 -> V_26 ) ) {
if ( F_105 ( V_125 , V_23 ,
F_82 ( V_2 ) . V_94 ,
F_100 ( V_96 ) ) < 0 ) {
F_106 ( V_23 ) ;
F_107 ( V_23 ) ;
F_74 ( V_23 ) ;
return 0 ;
}
F_108 ( V_186 , & V_23 -> V_25 ) ;
F_106 ( V_23 ) ;
F_74 ( V_23 ) ;
}
F_74 ( V_23 ) ;
return 0 ;
}
static int
F_109 ( struct V_181 * V_182 , struct V_1 * V_2 ,
const struct V_95 * V_96 ,
const struct V_8 * const V_171 [] )
{
struct V_122 * V_122 = F_77 ( V_182 ) ;
struct V_149 * V_150 ;
struct V_3 V_4 ;
struct V_22 * V_23 ;
struct V_1 * V_187 = NULL ;
struct V_97 * V_98 = F_46 ( V_96 ) ;
V_116 V_183 = V_98 -> V_105 ;
T_4 V_174 ;
int V_124 ;
if ( V_96 -> V_188 & V_189 ) {
struct V_190 V_191 = {
. V_192 = F_76 ,
. V_193 = F_73 ,
} ;
#ifdef F_64
if ( V_171 [ V_64 ] && V_171 [ V_194 ] ) {
struct V_154 * V_155 ;
V_155 = F_110 ( sizeof( struct V_154 ) ,
V_135 ) ;
if ( V_155 == NULL )
return - V_195 ;
V_155 -> V_65 . V_160 = F_102 ( F_103 ( V_171 [ V_64 ] ) ) ;
V_155 -> V_65 . V_159 =
F_102 ( F_103 ( V_171 [ V_194 ] ) ) ;
V_191 . V_146 = V_155 ;
}
#endif
return F_111 ( V_182 , V_2 , V_96 , & V_191 ) ;
}
V_124 = F_92 ( V_171 [ V_111 ] , & V_174 ) ;
if ( V_124 < 0 )
return V_124 ;
if ( V_171 [ V_109 ] )
V_124 = F_91 ( V_171 , & V_4 , V_109 , V_183 ) ;
else if ( V_171 [ V_110 ] )
V_124 = F_91 ( V_171 , & V_4 , V_110 , V_183 ) ;
else
return - V_170 ;
if ( V_124 < 0 )
return V_124 ;
V_150 = F_101 ( V_122 , V_174 , & V_4 ) ;
if ( ! V_150 )
return - V_184 ;
V_23 = F_81 ( V_150 ) ;
V_124 = - V_195 ;
V_187 = F_69 ( V_196 , V_197 ) ;
if ( V_187 == NULL ) {
F_74 ( V_23 ) ;
return - V_195 ;
}
F_8 () ;
V_124 = F_44 ( V_187 , F_82 ( V_2 ) . V_94 , V_96 -> V_161 ,
F_83 ( V_96 -> V_162 ) , V_23 ) ;
F_11 () ;
F_74 ( V_23 ) ;
if ( V_124 <= 0 )
goto free;
V_124 = F_112 ( V_182 , V_187 , F_82 ( V_2 ) . V_94 , V_198 ) ;
if ( V_124 < 0 )
goto V_39;
return 0 ;
free:
F_71 ( V_187 ) ;
V_39:
return V_124 == - V_143 ? - V_142 : V_124 ;
}
static int F_113 ( struct V_144 * V_145 )
{
if ( V_145 -> args [ 1 ] )
F_74 ( (struct V_22 * ) V_145 -> args [ 1 ] ) ;
return 0 ;
}
static int
F_114 ( struct V_1 * V_2 , struct V_144 * V_145 ,
struct V_199 * V_200 )
{
struct V_22 * V_23 , * V_148 ;
struct V_149 * V_150 ;
struct V_151 * V_152 ;
struct V_97 * V_98 = F_46 ( V_145 -> V_96 ) ;
V_116 V_18 = V_98 -> V_105 ;
int V_153 ;
if ( V_145 -> args [ 2 ] )
return 0 ;
F_78 ( & V_156 ) ;
V_148 = (struct V_22 * ) V_145 -> args [ 1 ] ;
V_158:
F_79 (h, n, list, hnnode) {
V_23 = F_81 ( V_150 ) ;
if ( V_18 && F_17 ( V_23 ) != V_18 )
continue;
if ( V_145 -> args [ 1 ] ) {
if ( V_23 != V_148 )
continue;
V_145 -> args [ 1 ] = 0 ;
}
F_8 () ;
V_153 = F_44 ( V_2 , F_82 ( V_145 -> V_2 ) . V_94 ,
V_145 -> V_96 -> V_161 ,
F_83 ( V_145 -> V_96 -> V_162 ) ,
V_23 ) ;
F_11 () ;
if ( V_153 < 0 ) {
F_84 ( & V_23 -> V_92 ) ;
V_145 -> args [ 1 ] = ( unsigned long ) V_23 ;
goto V_39;
}
}
if ( V_145 -> args [ 1 ] ) {
V_145 -> args [ 1 ] = 0 ;
goto V_158;
} else
V_145 -> args [ 2 ] = 1 ;
V_39:
F_85 ( & V_156 ) ;
if ( V_148 )
F_74 ( V_148 ) ;
return V_2 -> V_67 ;
}
static int
F_115 ( struct V_1 * V_2 , struct V_144 * V_145 )
{
struct V_122 * V_122 = F_77 ( V_2 -> V_147 ) ;
return F_114 ( V_2 , V_145 , & V_122 -> V_23 . V_201 ) ;
}
static int
F_116 ( struct V_181 * V_182 , struct V_1 * V_2 ,
const struct V_95 * V_96 ,
const struct V_8 * const V_171 [] )
{
if ( V_96 -> V_188 & V_189 ) {
struct V_190 V_191 = {
. V_192 = F_115 ,
. V_193 = F_113 ,
} ;
return F_111 ( V_182 , V_2 , V_96 , & V_191 ) ;
}
return - V_175 ;
}
static int
F_117 ( struct V_1 * V_2 , struct V_144 * V_145 )
{
struct V_122 * V_122 = F_77 ( V_2 -> V_147 ) ;
return F_114 ( V_2 , V_145 , & V_122 -> V_23 . V_202 ) ;
}
static int
F_118 ( struct V_181 * V_182 , struct V_1 * V_2 ,
const struct V_95 * V_96 ,
const struct V_8 * const V_171 [] )
{
if ( V_96 -> V_188 & V_189 ) {
struct V_190 V_191 = {
. V_192 = F_117 ,
. V_193 = F_113 ,
} ;
return F_111 ( V_182 , V_2 , V_96 , & V_191 ) ;
}
return - V_175 ;
}
static int
F_119 ( struct V_22 * V_23 ,
enum V_203 V_204 ,
const struct V_8 * V_163 )
{
F_120 (nfnetlink_parse_nat_setup_hook) V_205 ;
int V_124 ;
V_205 = F_21 ( V_206 ) ;
if ( ! V_205 ) {
#ifdef F_121
F_11 () ;
F_122 () ;
if ( F_123 ( L_1 ) < 0 ) {
F_124 () ;
F_8 () ;
return - V_175 ;
}
F_124 () ;
F_8 () ;
if ( V_206 )
return - V_143 ;
#endif
return - V_175 ;
}
V_124 = V_205 ( V_23 , V_204 , V_163 ) ;
if ( V_124 == - V_143 ) {
#ifdef F_121
F_11 () ;
F_122 () ;
if ( F_123 ( L_2 , F_17 ( V_23 ) ) < 0 ) {
F_124 () ;
F_8 () ;
return - V_175 ;
}
F_124 () ;
F_8 () ;
#else
V_124 = - V_175 ;
#endif
}
return V_124 ;
}
static int
F_125 ( struct V_22 * V_23 , const struct V_8 * const V_171 [] )
{
unsigned long V_207 ;
unsigned int V_25 = F_102 ( F_103 ( V_171 [ V_24 ] ) ) ;
V_207 = V_23 -> V_25 ^ V_25 ;
if ( V_207 & ( V_72 | V_208 | V_209 ) )
return - V_210 ;
if ( V_207 & V_211 && ! ( V_25 & V_211 ) )
return - V_210 ;
if ( V_207 & V_212 && ! ( V_25 & V_212 ) )
return - V_210 ;
V_23 -> V_25 |= V_25 & ~ ( V_213 | V_214 ) ;
return 0 ;
}
static int
F_126 ( struct V_22 * V_23 , const struct V_8 * const V_171 [] )
{
#ifdef F_63
int V_7 ;
if ( V_171 [ V_215 ] ) {
V_7 = F_119 ( V_23 ,
V_216 ,
V_171 [ V_215 ] ) ;
if ( V_7 < 0 )
return V_7 ;
}
if ( V_171 [ V_217 ] ) {
V_7 = F_119 ( V_23 ,
V_218 ,
V_171 [ V_217 ] ) ;
if ( V_7 < 0 )
return V_7 ;
}
return 0 ;
#else
return - V_175 ;
#endif
}
static inline int
F_127 ( struct V_22 * V_23 , const struct V_8 * const V_171 [] )
{
struct V_37 * V_38 ;
struct V_35 * V_36 = F_20 ( V_23 ) ;
char * V_219 = NULL ;
struct V_8 * V_177 = NULL ;
int V_124 ;
if ( V_23 -> V_220 )
return - V_210 ;
V_124 = F_96 ( V_171 [ V_40 ] , & V_219 , & V_177 ) ;
if ( V_124 < 0 )
return V_124 ;
if ( ! strcmp ( V_219 , L_3 ) ) {
if ( V_36 && V_36 -> V_38 ) {
F_128 ( V_23 ) ;
F_129 ( V_36 -> V_38 , NULL ) ;
}
return 0 ;
}
V_38 = F_130 ( V_219 , F_17 ( V_23 ) ,
F_18 ( V_23 ) ) ;
if ( V_38 == NULL ) {
#ifdef F_121
F_85 ( & V_156 ) ;
if ( F_123 ( L_4 , V_219 ) < 0 ) {
F_78 ( & V_156 ) ;
return - V_175 ;
}
F_78 ( & V_156 ) ;
V_38 = F_130 ( V_219 , F_17 ( V_23 ) ,
F_18 ( V_23 ) ) ;
if ( V_38 )
return - V_143 ;
#endif
return - V_175 ;
}
if ( V_36 ) {
if ( V_36 -> V_38 == V_38 ) {
if ( V_38 -> V_221 )
V_38 -> V_221 ( V_177 , V_23 ) ;
return 0 ;
} else
return - V_210 ;
}
return - V_175 ;
}
static inline int
F_131 ( struct V_22 * V_23 , const struct V_8 * const V_171 [] )
{
V_117 V_26 = F_102 ( F_103 ( V_171 [ V_30 ] ) ) ;
if ( ! F_104 ( & V_23 -> V_26 ) )
return - V_222 ;
V_23 -> V_26 . V_27 = V_28 + V_26 * V_29 ;
F_132 ( & V_23 -> V_26 ) ;
return 0 ;
}
static inline int
F_133 ( struct V_22 * V_23 , const struct V_8 * const V_171 [] )
{
const struct V_8 * V_163 = V_171 [ V_33 ] ;
struct V_8 * V_164 [ V_223 + 1 ] ;
struct V_5 * V_6 ;
int V_124 = 0 ;
F_87 ( V_164 , V_223 , V_163 , V_224 ) ;
F_8 () ;
V_6 = F_10 ( F_17 ( V_23 ) , F_18 ( V_23 ) ) ;
if ( V_6 -> V_221 )
V_124 = V_6 -> V_221 ( V_164 , V_23 ) ;
F_11 () ;
return V_124 ;
}
static inline int
F_134 ( struct V_74 * V_75 , const struct V_8 * const V_163 )
{
struct V_8 * V_171 [ V_225 + 1 ] ;
F_87 ( V_171 , V_225 , V_163 , V_226 ) ;
if ( ! V_171 [ V_76 ] )
return - V_170 ;
V_75 -> V_77 =
F_102 ( F_103 ( V_171 [ V_76 ] ) ) ;
if ( ! V_171 [ V_78 ] )
return - V_170 ;
V_75 -> V_79 =
F_102 ( F_103 ( V_171 [ V_78 ] ) ) ;
if ( ! V_171 [ V_80 ] )
return - V_170 ;
V_75 -> V_81 =
F_102 ( F_103 ( V_171 [ V_80 ] ) ) ;
return 0 ;
}
static int
F_135 ( struct V_22 * V_23 ,
const struct V_8 * const V_171 [] )
{
int V_7 = 0 ;
struct V_82 * V_83 = F_40 ( V_23 ) ;
if ( ! V_83 )
return 0 ;
if ( V_171 [ V_87 ] ) {
V_7 = F_134 ( & V_83 -> V_85 [ V_86 ] ,
V_171 [ V_87 ] ) ;
if ( V_7 < 0 )
return V_7 ;
V_23 -> V_25 |= V_84 ;
}
if ( V_171 [ V_89 ] ) {
V_7 = F_134 ( & V_83 -> V_85 [ V_88 ] ,
V_171 [ V_89 ] ) ;
if ( V_7 < 0 )
return V_7 ;
V_23 -> V_25 |= V_84 ;
}
return 0 ;
}
static int
F_136 ( struct V_22 * V_23 ,
const struct V_8 * const V_171 [] )
{
int V_124 ;
if ( V_171 [ V_217 ] || V_171 [ V_215 ] || V_171 [ V_73 ] )
return - V_175 ;
if ( V_171 [ V_40 ] ) {
V_124 = F_127 ( V_23 , V_171 ) ;
if ( V_124 < 0 )
return V_124 ;
}
if ( V_171 [ V_30 ] ) {
V_124 = F_131 ( V_23 , V_171 ) ;
if ( V_124 < 0 )
return V_124 ;
}
if ( V_171 [ V_24 ] ) {
V_124 = F_125 ( V_23 , V_171 ) ;
if ( V_124 < 0 )
return V_124 ;
}
if ( V_171 [ V_33 ] ) {
V_124 = F_133 ( V_23 , V_171 ) ;
if ( V_124 < 0 )
return V_124 ;
}
#if F_137 ( F_64 )
if ( V_171 [ V_64 ] )
V_23 -> V_65 = F_102 ( F_103 ( V_171 [ V_64 ] ) ) ;
#endif
#ifdef F_63
if ( V_171 [ V_87 ] || V_171 [ V_89 ] ) {
V_124 = F_135 ( V_23 , V_171 ) ;
if ( V_124 < 0 )
return V_124 ;
}
#endif
return 0 ;
}
static struct V_22 *
F_138 ( struct V_122 * V_122 , T_4 V_174 ,
const struct V_8 * const V_171 [] ,
struct V_3 * V_227 ,
struct V_3 * V_228 ,
T_5 V_183 )
{
struct V_22 * V_23 ;
int V_124 = - V_170 ;
struct V_37 * V_38 ;
struct V_57 * V_58 ;
V_23 = F_139 ( V_122 , V_174 , V_227 , V_228 , V_135 ) ;
if ( F_140 ( V_23 ) )
return F_141 ( - V_195 ) ;
if ( ! V_171 [ V_30 ] )
goto V_229;
V_23 -> V_26 . V_27 = F_102 ( F_103 ( V_171 [ V_30 ] ) ) ;
V_23 -> V_26 . V_27 = V_28 + V_23 -> V_26 . V_27 * V_29 ;
F_8 () ;
if ( V_171 [ V_40 ] ) {
char * V_219 = NULL ;
struct V_8 * V_177 = NULL ;
V_124 = F_96 ( V_171 [ V_40 ] , & V_219 , & V_177 ) ;
if ( V_124 < 0 )
goto V_230;
V_38 = F_130 ( V_219 , F_17 ( V_23 ) ,
F_18 ( V_23 ) ) ;
if ( V_38 == NULL ) {
F_11 () ;
#ifdef F_121
if ( F_123 ( L_4 , V_219 ) < 0 ) {
V_124 = - V_175 ;
goto V_229;
}
F_8 () ;
V_38 = F_130 ( V_219 ,
F_17 ( V_23 ) ,
F_18 ( V_23 ) ) ;
if ( V_38 ) {
V_124 = - V_143 ;
goto V_230;
}
F_11 () ;
#endif
V_124 = - V_175 ;
goto V_229;
} else {
struct V_35 * V_36 ;
V_36 = F_142 ( V_23 , V_38 , V_135 ) ;
if ( V_36 == NULL ) {
V_124 = - V_195 ;
goto V_230;
}
if ( V_38 -> V_221 )
V_38 -> V_221 ( V_177 , V_23 ) ;
F_129 ( V_36 -> V_38 , V_38 ) ;
}
} else {
V_124 = F_143 ( V_23 , NULL , V_135 ) ;
if ( V_124 < 0 )
goto V_230;
}
if ( V_171 [ V_217 ] || V_171 [ V_215 ] ) {
V_124 = F_126 ( V_23 , V_171 ) ;
if ( V_124 < 0 )
goto V_230;
}
F_144 ( V_23 , V_135 ) ;
F_145 ( V_23 , V_135 ) ;
F_146 ( V_23 , 0 , 0 , V_135 ) ;
V_23 -> V_25 |= V_208 ;
if ( V_171 [ V_24 ] ) {
V_124 = F_125 ( V_23 , V_171 ) ;
if ( V_124 < 0 )
goto V_230;
}
#ifdef F_63
if ( V_171 [ V_87 ] || V_171 [ V_89 ] ) {
V_124 = F_135 ( V_23 , V_171 ) ;
if ( V_124 < 0 )
goto V_230;
}
#endif
memset ( & V_23 -> V_231 , 0 , sizeof( V_23 -> V_231 ) ) ;
if ( V_171 [ V_33 ] ) {
V_124 = F_133 ( V_23 , V_171 ) ;
if ( V_124 < 0 )
goto V_230;
}
#if F_137 ( F_64 )
if ( V_171 [ V_64 ] )
V_23 -> V_65 = F_102 ( F_103 ( V_171 [ V_64 ] ) ) ;
#endif
if ( V_171 [ V_73 ] ) {
struct V_3 V_220 ;
struct V_149 * V_232 ;
struct V_22 * V_233 ;
V_124 = F_91 ( V_171 , & V_220 , V_73 , V_183 ) ;
if ( V_124 < 0 )
goto V_230;
V_232 = F_101 ( V_122 , V_174 , & V_220 ) ;
if ( V_232 == NULL ) {
V_124 = - V_184 ;
goto V_230;
}
V_233 = F_81 ( V_232 ) ;
F_147 ( V_234 , & V_23 -> V_25 ) ;
V_23 -> V_220 = V_233 ;
}
V_58 = F_31 ( V_23 ) ;
if ( V_58 )
V_58 -> V_61 = F_148 ( F_149 () ) ;
V_124 = F_150 ( V_23 ) ;
if ( V_124 < 0 )
goto V_230;
F_11 () ;
return V_23 ;
V_230:
F_11 () ;
V_229:
F_151 ( V_23 ) ;
return F_141 ( V_124 ) ;
}
static int
F_152 ( struct V_181 * V_182 , struct V_1 * V_2 ,
const struct V_95 * V_96 ,
const struct V_8 * const V_171 [] )
{
struct V_122 * V_122 = F_77 ( V_182 ) ;
struct V_3 V_227 , V_228 ;
struct V_149 * V_150 = NULL ;
struct V_97 * V_98 = F_46 ( V_96 ) ;
struct V_22 * V_23 ;
V_116 V_183 = V_98 -> V_105 ;
T_4 V_174 ;
int V_124 ;
V_124 = F_92 ( V_171 [ V_111 ] , & V_174 ) ;
if ( V_124 < 0 )
return V_124 ;
if ( V_171 [ V_109 ] ) {
V_124 = F_91 ( V_171 , & V_227 , V_109 , V_183 ) ;
if ( V_124 < 0 )
return V_124 ;
}
if ( V_171 [ V_110 ] ) {
V_124 = F_91 ( V_171 , & V_228 , V_110 , V_183 ) ;
if ( V_124 < 0 )
return V_124 ;
}
if ( V_171 [ V_109 ] )
V_150 = F_101 ( V_122 , V_174 , & V_227 ) ;
else if ( V_171 [ V_110 ] )
V_150 = F_101 ( V_122 , V_174 , & V_228 ) ;
if ( V_150 == NULL ) {
V_124 = - V_184 ;
if ( V_96 -> V_188 & V_130 ) {
enum V_235 V_119 ;
V_23 = F_138 ( V_122 , V_174 , V_171 , & V_227 ,
& V_228 , V_183 ) ;
if ( F_140 ( V_23 ) )
return F_153 ( V_23 ) ;
V_124 = 0 ;
if ( F_154 ( V_234 , & V_23 -> V_25 ) )
V_119 = V_129 ;
else
V_119 = V_128 ;
F_155 ( ( 1 << V_236 ) |
( 1 << V_237 ) |
( 1 << V_138 ) |
( 1 << V_137 ) |
( 1 << V_140 ) |
( 1 << V_141 ) | V_119 ,
V_23 , F_82 ( V_2 ) . V_94 ,
F_100 ( V_96 ) ) ;
F_74 ( V_23 ) ;
}
return V_124 ;
}
V_124 = - V_238 ;
V_23 = F_81 ( V_150 ) ;
if ( ! ( V_96 -> V_188 & V_131 ) ) {
F_78 ( & V_156 ) ;
V_124 = F_136 ( V_23 , V_171 ) ;
F_85 ( & V_156 ) ;
if ( V_124 == 0 ) {
F_155 ( ( 1 << V_236 ) |
( 1 << V_237 ) |
( 1 << V_138 ) |
( 1 << V_137 ) |
( 1 << V_140 ) |
( 1 << V_141 ) ,
V_23 , F_82 ( V_2 ) . V_94 ,
F_100 ( V_96 ) ) ;
}
}
F_74 ( V_23 ) ;
return V_124 ;
}
static int
F_156 ( struct V_1 * V_2 , T_2 V_94 , T_2 V_85 ,
T_6 V_239 , const struct V_240 * V_241 )
{
struct V_95 * V_96 ;
struct V_97 * V_98 ;
unsigned int V_99 = V_94 ? V_100 : 0 , V_101 ;
V_101 = ( V_102 << 8 | V_242 ) ;
V_96 = F_45 ( V_2 , V_94 , V_85 , V_101 , sizeof( * V_98 ) , V_99 ) ;
if ( V_96 == NULL )
goto V_104;
V_98 = F_46 ( V_96 ) ;
V_98 -> V_105 = V_243 ;
V_98 -> V_106 = V_107 ;
V_98 -> V_108 = F_50 ( V_239 ) ;
if ( F_13 ( V_2 , V_244 , F_14 ( V_241 -> V_245 ) ) ||
F_13 ( V_2 , V_246 , F_14 ( V_241 -> V_247 ) ) ||
F_13 ( V_2 , V_248 , F_14 ( V_241 -> V_249 ) ) ||
F_13 ( V_2 , V_250 , F_14 ( V_241 -> V_251 ) ) ||
F_13 ( V_2 , V_252 , F_14 ( V_241 -> V_253 ) ) ||
F_13 ( V_2 , V_254 , F_14 ( V_241 -> V_255 ) ) ||
F_13 ( V_2 , V_256 , F_14 ( V_241 -> V_257 ) ) ||
F_13 ( V_2 , V_258 , F_14 ( V_241 -> V_259 ) ) ||
F_13 ( V_2 , V_260 ,
F_14 ( V_241 -> V_261 ) ) ||
F_13 ( V_2 , V_262 , F_14 ( V_241 -> V_263 ) ) ||
F_13 ( V_2 , V_264 , F_14 ( V_241 -> V_265 ) ) ||
F_13 ( V_2 , V_266 , F_14 ( V_241 -> error ) ) ||
F_13 ( V_2 , V_267 ,
F_14 ( V_241 -> V_268 ) ) )
goto V_12;
F_51 ( V_2 , V_96 ) ;
return V_2 -> V_67 ;
V_12:
V_104:
F_52 ( V_2 , V_96 ) ;
return - 1 ;
}
static int
F_157 ( struct V_1 * V_2 , struct V_144 * V_145 )
{
int V_239 ;
struct V_122 * V_122 = F_77 ( V_2 -> V_147 ) ;
if ( V_145 -> args [ 0 ] == V_269 )
return 0 ;
for ( V_239 = V_145 -> args [ 0 ] ; V_239 < V_269 ; V_239 ++ ) {
const struct V_240 * V_241 ;
if ( ! F_158 ( V_239 ) )
continue;
V_241 = F_159 ( V_122 -> V_23 . V_270 , V_239 ) ;
if ( F_156 ( V_2 ,
F_82 ( V_145 -> V_2 ) . V_94 ,
V_145 -> V_96 -> V_161 ,
V_239 , V_241 ) < 0 )
break;
}
V_145 -> args [ 0 ] = V_239 ;
return V_2 -> V_67 ;
}
static int
F_160 ( struct V_181 * V_182 , struct V_1 * V_2 ,
const struct V_95 * V_96 ,
const struct V_8 * const V_171 [] )
{
if ( V_96 -> V_188 & V_189 ) {
struct V_190 V_191 = {
. V_192 = F_157 ,
} ;
return F_111 ( V_182 , V_2 , V_96 , & V_191 ) ;
}
return 0 ;
}
static int
F_161 ( struct V_1 * V_2 , T_2 V_94 , T_2 V_85 , T_2 type ,
struct V_122 * V_122 )
{
struct V_95 * V_96 ;
struct V_97 * V_98 ;
unsigned int V_99 = V_94 ? V_100 : 0 , V_101 ;
unsigned int V_271 = F_43 ( & V_122 -> V_23 . V_272 ) ;
V_101 = ( V_102 << 8 | V_273 ) ;
V_96 = F_45 ( V_2 , V_94 , V_85 , V_101 , sizeof( * V_98 ) , V_99 ) ;
if ( V_96 == NULL )
goto V_104;
V_98 = F_46 ( V_96 ) ;
V_98 -> V_105 = V_243 ;
V_98 -> V_106 = V_107 ;
V_98 -> V_108 = 0 ;
if ( F_13 ( V_2 , V_274 , F_14 ( V_271 ) ) )
goto V_12;
F_51 ( V_2 , V_96 ) ;
return V_2 -> V_67 ;
V_12:
V_104:
F_52 ( V_2 , V_96 ) ;
return - 1 ;
}
static int
F_162 ( struct V_181 * V_182 , struct V_1 * V_2 ,
const struct V_95 * V_96 ,
const struct V_8 * const V_171 [] )
{
struct V_1 * V_187 ;
int V_124 ;
V_187 = F_69 ( V_196 , V_197 ) ;
if ( V_187 == NULL )
return - V_195 ;
V_124 = F_161 ( V_187 , F_82 ( V_2 ) . V_94 ,
V_96 -> V_161 ,
F_83 ( V_96 -> V_162 ) ,
F_77 ( V_2 -> V_147 ) ) ;
if ( V_124 <= 0 )
goto free;
V_124 = F_112 ( V_182 , V_187 , F_82 ( V_2 ) . V_94 , V_198 ) ;
if ( V_124 < 0 )
goto V_39;
return 0 ;
free:
F_71 ( V_187 ) ;
V_39:
return V_124 == - V_143 ? - V_142 : V_124 ;
}
static T_3
F_163 ( const struct V_22 * V_23 )
{
return 3 * F_56 ( 0 )
+ 3 * F_56 ( 0 )
+ 3 * F_56 ( 0 )
+ 3 * F_56 ( sizeof( V_116 ) )
+ F_56 ( sizeof( V_117 ) )
+ F_56 ( sizeof( V_117 ) )
+ F_56 ( sizeof( V_117 ) )
+ F_56 ( 0 )
+ F_56 ( 0 )
+ F_56 ( V_118 )
+ F_57 ( V_23 )
#ifdef F_63
+ 2 * F_56 ( 0 )
+ 6 * F_56 ( sizeof( V_117 ) )
#endif
#ifdef F_64
+ F_56 ( sizeof( V_117 ) )
#endif
+ F_53 ( V_23 )
;
}
static int
F_164 ( struct V_1 * V_2 , struct V_22 * V_23 )
{
struct V_8 * V_9 ;
F_8 () ;
V_9 = F_2 ( V_2 , V_109 | V_11 ) ;
if ( ! V_9 )
goto V_12;
if ( F_7 ( V_2 , F_47 ( V_23 , V_86 ) ) < 0 )
goto V_12;
F_5 ( V_2 , V_9 ) ;
V_9 = F_2 ( V_2 , V_110 | V_11 ) ;
if ( ! V_9 )
goto V_12;
if ( F_7 ( V_2 , F_47 ( V_23 , V_88 ) ) < 0 )
goto V_12;
F_5 ( V_2 , V_9 ) ;
if ( F_48 ( V_23 ) ) {
if ( F_49 ( V_2 , V_111 , F_50 ( F_48 ( V_23 ) ) ) )
goto V_12;
}
if ( F_41 ( V_2 , V_23 ) < 0 )
goto V_12;
if ( F_12 ( V_2 , V_23 ) < 0 )
goto V_12;
if ( F_15 ( V_2 , V_23 ) < 0 )
goto V_12;
if ( F_16 ( V_2 , V_23 ) < 0 )
goto V_12;
if ( F_19 ( V_2 , V_23 ) < 0 )
goto V_12;
#ifdef F_58
if ( V_23 -> V_69 && F_33 ( V_2 , V_23 ) < 0 )
goto V_12;
#endif
if ( V_23 -> V_220 && F_36 ( V_2 , V_23 ) < 0 )
goto V_12;
if ( ( V_23 -> V_25 & V_84 ) &&
F_39 ( V_2 , V_23 ) < 0 )
goto V_12;
#ifdef F_64
if ( V_23 -> V_65 && F_32 ( V_2 , V_23 ) < 0 )
goto V_12;
#endif
F_11 () ;
return 0 ;
V_12:
F_11 () ;
return - V_275 ;
}
static int
F_165 ( const struct V_8 * V_171 [] , struct V_22 * V_23 )
{
int V_124 ;
if ( V_171 [ V_30 ] ) {
V_124 = F_131 ( V_23 , V_171 ) ;
if ( V_124 < 0 )
return V_124 ;
}
if ( V_171 [ V_24 ] ) {
V_124 = F_125 ( V_23 , V_171 ) ;
if ( V_124 < 0 )
return V_124 ;
}
if ( V_171 [ V_40 ] ) {
V_124 = F_127 ( V_23 , V_171 ) ;
if ( V_124 < 0 )
return V_124 ;
}
#if F_137 ( F_64 )
if ( V_171 [ V_64 ] )
V_23 -> V_65 = F_102 ( F_103 ( V_171 [ V_64 ] ) ) ;
#endif
return 0 ;
}
static int
F_166 ( const struct V_8 * V_163 , struct V_22 * V_23 )
{
struct V_8 * V_171 [ V_276 + 1 ] ;
int V_7 ;
F_87 ( V_171 , V_276 , V_163 , V_277 ) ;
F_78 ( & V_156 ) ;
V_7 = F_165 ( ( const struct V_8 * * ) V_171 , V_23 ) ;
F_85 ( & V_156 ) ;
return V_7 ;
}
static inline int
F_167 ( struct V_1 * V_2 ,
const struct V_3 * V_4 ,
enum V_278 type )
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
F_168 ( struct V_1 * V_2 ,
const struct V_3 * V_4 ,
const struct V_279 * V_159 )
{
int V_7 ;
struct V_17 * V_18 ;
struct V_5 * V_6 ;
struct V_3 V_280 ;
struct V_8 * V_9 ;
memset ( & V_280 , 0xFF , sizeof( V_280 ) ) ;
memcpy ( & V_280 . V_20 . V_183 , & V_159 -> V_20 . V_183 , sizeof( V_280 . V_20 . V_183 ) ) ;
V_280 . V_20 . V_281 . V_282 = V_159 -> V_20 . V_281 . V_282 ;
V_280 . V_14 . V_15 = V_4 -> V_14 . V_15 ;
V_9 = F_2 ( V_2 , V_283 | V_11 ) ;
if ( ! V_9 )
goto V_12;
F_8 () ;
V_18 = F_9 ( V_4 -> V_20 . V_21 ) ;
V_7 = F_6 ( V_2 , & V_280 , V_18 ) ;
if ( V_7 >= 0 ) {
V_6 = F_10 ( V_4 -> V_20 . V_21 ,
V_4 -> V_14 . V_15 ) ;
V_7 = F_1 ( V_2 , & V_280 , V_6 ) ;
}
F_11 () ;
if ( F_169 ( V_7 < 0 ) )
goto V_12;
F_5 ( V_2 , V_9 ) ;
return 0 ;
V_12:
return - 1 ;
}
static int
F_170 ( struct V_1 * V_2 ,
const struct V_284 * exp )
{
struct V_22 * V_220 = exp -> V_220 ;
long V_26 = ( ( long ) exp -> V_26 . V_27 - ( long ) V_28 ) / V_29 ;
struct V_35 * V_36 ;
#ifdef F_63
struct V_8 * V_9 ;
struct V_3 V_285 = {} ;
#endif
struct V_286 * V_287 ;
if ( V_26 < 0 )
V_26 = 0 ;
if ( F_167 ( V_2 , & exp -> V_4 , V_288 ) < 0 )
goto V_12;
if ( F_168 ( V_2 , & exp -> V_4 , & exp -> V_159 ) < 0 )
goto V_12;
if ( F_167 ( V_2 ,
& V_220 -> V_289 [ V_86 ] . V_4 ,
V_290 ) < 0 )
goto V_12;
#ifdef F_63
if ( ! F_171 ( & exp -> V_291 , & V_292 ) ||
exp -> V_293 . V_282 ) {
V_9 = F_2 ( V_2 , V_294 | V_11 ) ;
if ( ! V_9 )
goto V_12;
if ( F_13 ( V_2 , V_295 , F_14 ( exp -> V_46 ) ) )
goto V_12;
V_285 . V_20 . V_21 = F_17 ( V_220 ) ;
V_285 . V_20 . V_183 = exp -> V_291 ;
V_285 . V_14 . V_15 = F_18 ( V_220 ) ;
V_285 . V_20 . V_281 = exp -> V_293 ;
if ( F_167 ( V_2 , & V_285 ,
V_296 ) < 0 )
goto V_12;
F_5 ( V_2 , V_9 ) ;
}
#endif
if ( F_13 ( V_2 , V_297 , F_14 ( V_26 ) ) ||
F_13 ( V_2 , V_298 , F_14 ( ( unsigned long ) exp ) ) ||
F_13 ( V_2 , V_299 , F_14 ( exp -> V_99 ) ) ||
F_13 ( V_2 , V_300 , F_14 ( exp -> V_301 ) ) )
goto V_12;
V_36 = F_20 ( V_220 ) ;
if ( V_36 ) {
struct V_37 * V_38 ;
V_38 = F_21 ( V_36 -> V_38 ) ;
if ( V_38 &&
F_22 ( V_2 , V_302 , V_38 -> V_42 ) )
goto V_12;
}
V_287 = F_172 ( exp -> V_303 ) ;
if ( V_287 != NULL &&
F_22 ( V_2 , V_304 , V_287 -> V_42 ) )
goto V_12;
return 0 ;
V_12:
return - 1 ;
}
static int
F_173 ( struct V_1 * V_2 , T_2 V_94 , T_2 V_85 ,
int V_101 , const struct V_284 * exp )
{
struct V_95 * V_96 ;
struct V_97 * V_98 ;
unsigned int V_99 = V_94 ? V_100 : 0 ;
V_101 |= V_305 << 8 ;
V_96 = F_45 ( V_2 , V_94 , V_85 , V_101 , sizeof( * V_98 ) , V_99 ) ;
if ( V_96 == NULL )
goto V_104;
V_98 = F_46 ( V_96 ) ;
V_98 -> V_105 = exp -> V_4 . V_20 . V_21 ;
V_98 -> V_106 = V_107 ;
V_98 -> V_108 = 0 ;
if ( F_170 ( V_2 , exp ) < 0 )
goto V_12;
F_51 ( V_2 , V_96 ) ;
return V_2 -> V_67 ;
V_104:
V_12:
F_52 ( V_2 , V_96 ) ;
return - 1 ;
}
static int
F_174 ( unsigned int V_119 , struct V_306 * V_121 )
{
struct V_284 * exp = V_121 -> exp ;
struct V_122 * V_122 = F_175 ( exp ) ;
struct V_95 * V_96 ;
struct V_97 * V_98 ;
struct V_1 * V_2 ;
unsigned int type , V_123 ;
int V_99 = 0 ;
if ( V_119 & ( 1 << V_307 ) ) {
type = V_308 ;
V_123 = V_309 ;
} else if ( V_119 & ( 1 << V_310 ) ) {
type = V_311 ;
V_99 = V_130 | V_131 ;
V_123 = V_312 ;
} else
return 0 ;
if ( ! V_121 -> V_134 && ! F_68 ( V_122 , V_123 ) )
return 0 ;
V_2 = F_69 ( V_196 , V_135 ) ;
if ( V_2 == NULL )
goto V_136;
type |= V_305 << 8 ;
V_96 = F_45 ( V_2 , V_121 -> V_94 , 0 , type , sizeof( * V_98 ) , V_99 ) ;
if ( V_96 == NULL )
goto V_104;
V_98 = F_46 ( V_96 ) ;
V_98 -> V_105 = exp -> V_4 . V_20 . V_21 ;
V_98 -> V_106 = V_107 ;
V_98 -> V_108 = 0 ;
F_8 () ;
if ( F_170 ( V_2 , exp ) < 0 )
goto V_12;
F_11 () ;
F_51 ( V_2 , V_96 ) ;
F_70 ( V_2 , V_122 , V_121 -> V_94 , V_123 , V_121 -> V_134 , V_135 ) ;
return 0 ;
V_12:
F_11 () ;
F_52 ( V_2 , V_96 ) ;
V_104:
F_71 ( V_2 ) ;
V_136:
F_72 ( V_122 , 0 , 0 , - V_142 ) ;
return 0 ;
}
static int F_176 ( struct V_144 * V_145 )
{
if ( V_145 -> args [ 1 ] )
F_177 ( (struct V_284 * ) V_145 -> args [ 1 ] ) ;
return 0 ;
}
static int
F_178 ( struct V_1 * V_2 , struct V_144 * V_145 )
{
struct V_122 * V_122 = F_77 ( V_2 -> V_147 ) ;
struct V_284 * exp , * V_148 ;
struct V_97 * V_98 = F_46 ( V_145 -> V_96 ) ;
struct V_313 * V_152 ;
V_116 V_18 = V_98 -> V_105 ;
F_8 () ;
V_148 = (struct V_284 * ) V_145 -> args [ 1 ] ;
for (; V_145 -> args [ 0 ] < V_314 ; V_145 -> args [ 0 ] ++ ) {
V_158:
F_179 (exp, n, &net->ct.expect_hash[cb->args[0]],
hnode) {
if ( V_18 && exp -> V_4 . V_20 . V_21 != V_18 )
continue;
if ( V_145 -> args [ 1 ] ) {
if ( exp != V_148 )
continue;
V_145 -> args [ 1 ] = 0 ;
}
if ( F_173 ( V_2 ,
F_82 ( V_145 -> V_2 ) . V_94 ,
V_145 -> V_96 -> V_161 ,
V_311 ,
exp ) < 0 ) {
if ( ! F_180 ( & exp -> V_93 ) )
continue;
V_145 -> args [ 1 ] = ( unsigned long ) exp ;
goto V_39;
}
}
if ( V_145 -> args [ 1 ] ) {
V_145 -> args [ 1 ] = 0 ;
goto V_158;
}
}
V_39:
F_11 () ;
if ( V_148 )
F_177 ( V_148 ) ;
return V_2 -> V_67 ;
}
static int
F_181 ( struct V_181 * V_182 , struct V_1 * V_2 ,
const struct V_95 * V_96 ,
const struct V_8 * const V_171 [] )
{
struct V_122 * V_122 = F_77 ( V_182 ) ;
struct V_3 V_4 ;
struct V_284 * exp ;
struct V_1 * V_187 ;
struct V_97 * V_98 = F_46 ( V_96 ) ;
V_116 V_183 = V_98 -> V_105 ;
T_4 V_174 ;
int V_124 ;
if ( V_96 -> V_188 & V_189 ) {
struct V_190 V_191 = {
. V_192 = F_178 ,
. V_193 = F_176 ,
} ;
return F_111 ( V_182 , V_2 , V_96 , & V_191 ) ;
}
V_124 = F_92 ( V_171 [ V_315 ] , & V_174 ) ;
if ( V_124 < 0 )
return V_124 ;
if ( V_171 [ V_288 ] )
V_124 = F_91 ( V_171 , & V_4 , V_288 , V_183 ) ;
else if ( V_171 [ V_290 ] )
V_124 = F_91 ( V_171 , & V_4 , V_290 , V_183 ) ;
else
return - V_170 ;
if ( V_124 < 0 )
return V_124 ;
exp = F_182 ( V_122 , V_174 , & V_4 ) ;
if ( ! exp )
return - V_184 ;
if ( V_171 [ V_298 ] ) {
T_7 V_185 = F_103 ( V_171 [ V_298 ] ) ;
if ( F_102 ( V_185 ) != ( T_2 ) ( unsigned long ) exp ) {
F_177 ( exp ) ;
return - V_184 ;
}
}
V_124 = - V_195 ;
V_187 = F_69 ( V_196 , V_197 ) ;
if ( V_187 == NULL ) {
F_177 ( exp ) ;
goto V_39;
}
F_8 () ;
V_124 = F_173 ( V_187 , F_82 ( V_2 ) . V_94 ,
V_96 -> V_161 , V_311 , exp ) ;
F_11 () ;
F_177 ( exp ) ;
if ( V_124 <= 0 )
goto free;
V_124 = F_112 ( V_182 , V_187 , F_82 ( V_2 ) . V_94 , V_198 ) ;
if ( V_124 < 0 )
goto V_39;
return 0 ;
free:
F_71 ( V_187 ) ;
V_39:
return V_124 == - V_143 ? - V_142 : V_124 ;
}
static int
F_183 ( struct V_181 * V_182 , struct V_1 * V_2 ,
const struct V_95 * V_96 ,
const struct V_8 * const V_171 [] )
{
struct V_122 * V_122 = F_77 ( V_182 ) ;
struct V_284 * exp ;
struct V_3 V_4 ;
struct V_97 * V_98 = F_46 ( V_96 ) ;
struct V_313 * V_152 , * V_316 ;
V_116 V_183 = V_98 -> V_105 ;
unsigned int V_317 ;
T_4 V_174 ;
int V_124 ;
if ( V_171 [ V_288 ] ) {
V_124 = F_92 ( V_171 [ V_315 ] , & V_174 ) ;
if ( V_124 < 0 )
return V_124 ;
V_124 = F_91 ( V_171 , & V_4 , V_288 , V_183 ) ;
if ( V_124 < 0 )
return V_124 ;
exp = F_182 ( V_122 , V_174 , & V_4 ) ;
if ( ! exp )
return - V_184 ;
if ( V_171 [ V_298 ] ) {
T_7 V_185 = F_103 ( V_171 [ V_298 ] ) ;
if ( F_102 ( V_185 ) != ( T_2 ) ( unsigned long ) exp ) {
F_177 ( exp ) ;
return - V_184 ;
}
}
F_78 ( & V_156 ) ;
if ( F_104 ( & exp -> V_26 ) ) {
F_184 ( exp , F_82 ( V_2 ) . V_94 ,
F_100 ( V_96 ) ) ;
F_177 ( exp ) ;
}
F_85 ( & V_156 ) ;
F_177 ( exp ) ;
} else if ( V_171 [ V_302 ] ) {
char * V_42 = F_97 ( V_171 [ V_302 ] ) ;
struct V_35 * V_318 ;
F_78 ( & V_156 ) ;
for ( V_317 = 0 ; V_317 < V_314 ; V_317 ++ ) {
F_185 (exp, n, next,
&net->ct.expect_hash[i],
hnode) {
V_318 = F_20 ( exp -> V_220 ) ;
if ( ! strcmp ( V_318 -> V_38 -> V_42 , V_42 ) &&
F_104 ( & exp -> V_26 ) ) {
F_184 ( exp ,
F_82 ( V_2 ) . V_94 ,
F_100 ( V_96 ) ) ;
F_177 ( exp ) ;
}
}
}
F_85 ( & V_156 ) ;
} else {
F_78 ( & V_156 ) ;
for ( V_317 = 0 ; V_317 < V_314 ; V_317 ++ ) {
F_185 (exp, n, next,
&net->ct.expect_hash[i],
hnode) {
if ( F_104 ( & exp -> V_26 ) ) {
F_184 ( exp ,
F_82 ( V_2 ) . V_94 ,
F_100 ( V_96 ) ) ;
F_177 ( exp ) ;
}
}
}
F_85 ( & V_156 ) ;
}
return 0 ;
}
static int
F_186 ( struct V_284 * V_319 ,
const struct V_8 * const V_171 [] )
{
if ( V_171 [ V_297 ] ) {
if ( ! F_104 ( & V_319 -> V_26 ) )
return - V_222 ;
V_319 -> V_26 . V_27 = V_28 +
F_102 ( F_103 ( V_171 [ V_297 ] ) ) * V_29 ;
F_132 ( & V_319 -> V_26 ) ;
}
return 0 ;
}
static int
F_187 ( const struct V_8 * V_163 ,
struct V_284 * exp ,
V_116 V_183 )
{
#ifdef F_63
struct V_8 * V_164 [ V_320 + 1 ] ;
struct V_3 V_285 = {} ;
int V_124 ;
F_87 ( V_164 , V_320 , V_163 , V_321 ) ;
if ( ! V_164 [ V_295 ] || ! V_164 [ V_296 ] )
return - V_170 ;
V_124 = F_91 ( ( const struct V_8 * const * ) V_164 ,
& V_285 , V_296 , V_183 ) ;
if ( V_124 < 0 )
return V_124 ;
exp -> V_291 = V_285 . V_20 . V_183 ;
exp -> V_293 = V_285 . V_20 . V_281 ;
exp -> V_46 = F_102 ( F_103 ( V_164 [ V_295 ] ) ) ;
return 0 ;
#else
return - V_175 ;
#endif
}
static int
F_188 ( struct V_122 * V_122 , T_4 V_174 ,
const struct V_8 * const V_171 [] ,
V_116 V_183 ,
T_2 V_94 , int V_134 )
{
struct V_3 V_4 , V_159 , F_37 ;
struct V_149 * V_150 = NULL ;
struct V_284 * exp ;
struct V_22 * V_23 ;
struct V_35 * V_36 ;
struct V_37 * V_38 = NULL ;
V_117 V_301 = 0 ;
int V_124 = 0 ;
V_124 = F_91 ( V_171 , & V_4 , V_288 , V_183 ) ;
if ( V_124 < 0 )
return V_124 ;
V_124 = F_91 ( V_171 , & V_159 , V_283 , V_183 ) ;
if ( V_124 < 0 )
return V_124 ;
V_124 = F_91 ( V_171 , & F_37 , V_290 , V_183 ) ;
if ( V_124 < 0 )
return V_124 ;
V_150 = F_101 ( V_122 , V_174 , & F_37 ) ;
if ( ! V_150 )
return - V_184 ;
V_23 = F_81 ( V_150 ) ;
if ( V_171 [ V_302 ] ) {
const char * V_219 = F_97 ( V_171 [ V_302 ] ) ;
V_38 = F_130 ( V_219 , F_17 ( V_23 ) ,
F_18 ( V_23 ) ) ;
if ( V_38 == NULL ) {
#ifdef F_121
if ( F_123 ( L_4 , V_219 ) < 0 ) {
V_124 = - V_175 ;
goto V_39;
}
V_38 = F_130 ( V_219 ,
F_17 ( V_23 ) ,
F_18 ( V_23 ) ) ;
if ( V_38 ) {
V_124 = - V_143 ;
goto V_39;
}
#endif
V_124 = - V_175 ;
goto V_39;
}
}
if ( V_171 [ V_300 ] && V_38 ) {
V_301 = F_102 ( F_103 ( V_171 [ V_300 ] ) ) ;
if ( V_301 > V_38 -> V_322 ) {
V_124 = - V_170 ;
goto V_39;
}
}
exp = F_189 ( V_23 ) ;
if ( ! exp ) {
V_124 = - V_195 ;
goto V_39;
}
V_36 = F_20 ( V_23 ) ;
if ( ! V_36 ) {
if ( ! V_171 [ V_297 ] ) {
V_124 = - V_170 ;
goto V_323;
}
exp -> V_26 . V_27 =
V_28 + F_102 ( F_103 ( V_171 [ V_297 ] ) ) * V_29 ;
exp -> V_99 = V_324 ;
if ( V_171 [ V_299 ] ) {
exp -> V_99 |=
F_102 ( F_103 ( V_171 [ V_299 ] ) ) ;
}
} else {
if ( V_171 [ V_299 ] ) {
exp -> V_99 = F_102 ( F_103 ( V_171 [ V_299 ] ) ) ;
exp -> V_99 &= ~ V_324 ;
} else
exp -> V_99 = 0 ;
}
if ( V_171 [ V_304 ] ) {
const char * V_42 = F_97 ( V_171 [ V_304 ] ) ;
struct V_286 * V_287 ;
V_287 = F_190 ( V_42 ) ;
if ( V_287 == NULL ) {
V_124 = - V_170 ;
goto V_323;
}
exp -> V_303 = V_287 -> V_303 ;
} else
exp -> V_303 = NULL ;
exp -> V_301 = V_301 ;
exp -> V_220 = V_23 ;
exp -> V_38 = V_38 ;
memcpy ( & exp -> V_4 , & V_4 , sizeof( struct V_3 ) ) ;
memcpy ( & exp -> V_159 . V_20 . V_183 , & V_159 . V_20 . V_183 , sizeof( exp -> V_159 . V_20 . V_183 ) ) ;
exp -> V_159 . V_20 . V_281 . V_282 = V_159 . V_20 . V_281 . V_282 ;
if ( V_171 [ V_294 ] ) {
V_124 = F_187 ( V_171 [ V_294 ] ,
exp , V_183 ) ;
if ( V_124 < 0 )
goto V_323;
}
V_124 = F_191 ( exp , V_94 , V_134 ) ;
V_323:
F_177 ( exp ) ;
V_39:
F_74 ( F_81 ( V_150 ) ) ;
return V_124 ;
}
static int
F_192 ( struct V_181 * V_182 , struct V_1 * V_2 ,
const struct V_95 * V_96 ,
const struct V_8 * const V_171 [] )
{
struct V_122 * V_122 = F_77 ( V_182 ) ;
struct V_3 V_4 ;
struct V_284 * exp ;
struct V_97 * V_98 = F_46 ( V_96 ) ;
V_116 V_183 = V_98 -> V_105 ;
T_4 V_174 ;
int V_124 ;
if ( ! V_171 [ V_288 ]
|| ! V_171 [ V_283 ]
|| ! V_171 [ V_290 ] )
return - V_170 ;
V_124 = F_92 ( V_171 [ V_315 ] , & V_174 ) ;
if ( V_124 < 0 )
return V_124 ;
V_124 = F_91 ( V_171 , & V_4 , V_288 , V_183 ) ;
if ( V_124 < 0 )
return V_124 ;
F_78 ( & V_156 ) ;
exp = F_193 ( V_122 , V_174 , & V_4 ) ;
if ( ! exp ) {
F_85 ( & V_156 ) ;
V_124 = - V_184 ;
if ( V_96 -> V_188 & V_130 ) {
V_124 = F_188 ( V_122 , V_174 , V_171 ,
V_183 ,
F_82 ( V_2 ) . V_94 ,
F_100 ( V_96 ) ) ;
}
return V_124 ;
}
V_124 = - V_238 ;
if ( ! ( V_96 -> V_188 & V_131 ) )
V_124 = F_186 ( exp , V_171 ) ;
F_85 ( & V_156 ) ;
return V_124 ;
}
static int
F_194 ( struct V_1 * V_2 , T_2 V_94 , T_2 V_85 , int V_239 ,
const struct V_240 * V_241 )
{
struct V_95 * V_96 ;
struct V_97 * V_98 ;
unsigned int V_99 = V_94 ? V_100 : 0 , V_101 ;
V_101 = ( V_102 << 8 | V_325 ) ;
V_96 = F_45 ( V_2 , V_94 , V_85 , V_101 , sizeof( * V_98 ) , V_99 ) ;
if ( V_96 == NULL )
goto V_104;
V_98 = F_46 ( V_96 ) ;
V_98 -> V_105 = V_243 ;
V_98 -> V_106 = V_107 ;
V_98 -> V_108 = F_50 ( V_239 ) ;
if ( F_13 ( V_2 , V_326 , F_14 ( V_241 -> V_327 ) ) ||
F_13 ( V_2 , V_328 , F_14 ( V_241 -> V_329 ) ) ||
F_13 ( V_2 , V_330 , F_14 ( V_241 -> V_331 ) ) )
goto V_12;
F_51 ( V_2 , V_96 ) ;
return V_2 -> V_67 ;
V_12:
V_104:
F_52 ( V_2 , V_96 ) ;
return - 1 ;
}
static int
F_195 ( struct V_1 * V_2 , struct V_144 * V_145 )
{
int V_239 ;
struct V_122 * V_122 = F_77 ( V_2 -> V_147 ) ;
if ( V_145 -> args [ 0 ] == V_269 )
return 0 ;
for ( V_239 = V_145 -> args [ 0 ] ; V_239 < V_269 ; V_239 ++ ) {
const struct V_240 * V_241 ;
if ( ! F_158 ( V_239 ) )
continue;
V_241 = F_159 ( V_122 -> V_23 . V_270 , V_239 ) ;
if ( F_194 ( V_2 , F_82 ( V_145 -> V_2 ) . V_94 ,
V_145 -> V_96 -> V_161 ,
V_239 , V_241 ) < 0 )
break;
}
V_145 -> args [ 0 ] = V_239 ;
return V_2 -> V_67 ;
}
static int
F_196 ( struct V_181 * V_182 , struct V_1 * V_2 ,
const struct V_95 * V_96 ,
const struct V_8 * const V_171 [] )
{
if ( V_96 -> V_188 & V_189 ) {
struct V_190 V_191 = {
. V_192 = F_195 ,
} ;
return F_111 ( V_182 , V_2 , V_96 , & V_191 ) ;
}
return 0 ;
}
static int T_8 F_197 ( struct V_122 * V_122 )
{
#ifdef F_198
int V_7 ;
V_7 = F_199 ( V_122 , & V_332 ) ;
if ( V_7 < 0 ) {
F_200 ( L_5 ) ;
goto V_323;
}
V_7 = F_201 ( V_122 , & V_333 ) ;
if ( V_7 < 0 ) {
F_200 ( L_6 ) ;
goto V_334;
}
#endif
return 0 ;
#ifdef F_198
V_334:
F_202 ( V_122 , & V_332 ) ;
V_323:
return V_7 ;
#endif
}
static void F_203 ( struct V_122 * V_122 )
{
#ifdef F_198
F_204 ( V_122 , & V_333 ) ;
F_202 ( V_122 , & V_332 ) ;
#endif
}
static void T_9 F_205 ( struct V_335 * V_336 )
{
struct V_122 * V_122 ;
F_206 (net, net_exit_list, exit_list)
F_203 ( V_122 ) ;
}
static int T_10 F_207 ( void )
{
int V_7 ;
F_208 ( L_7 , V_106 ) ;
V_7 = F_209 ( & V_337 ) ;
if ( V_7 < 0 ) {
F_200 ( L_8 ) ;
goto V_323;
}
V_7 = F_209 ( & V_338 ) ;
if ( V_7 < 0 ) {
F_200 ( L_9 ) ;
goto V_339;
}
V_7 = F_210 ( & V_340 ) ;
if ( V_7 < 0 ) {
F_200 ( L_10 ) ;
goto V_341;
}
#ifdef F_211
F_129 ( V_342 , & V_343 ) ;
#endif
return 0 ;
V_341:
F_212 ( & V_338 ) ;
V_339:
F_212 ( & V_337 ) ;
V_323:
return V_7 ;
}
static void T_11 F_213 ( void )
{
F_208 ( L_11 ) ;
F_214 ( & V_340 ) ;
F_212 ( & V_338 ) ;
F_212 ( & V_337 ) ;
#ifdef F_211
F_129 ( V_342 , NULL ) ;
#endif
}
