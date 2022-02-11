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
F_3 ( V_2 , V_13 , V_4 -> V_14 . V_15 ) ;
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
F_13 ( V_2 , V_24 , F_14 ( V_23 -> V_25 ) ) ;
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
F_13 ( V_2 , V_30 , F_14 ( V_26 ) ) ;
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
F_22 ( V_2 , V_41 , V_38 -> V_42 ) ;
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
F_24 ( V_2 , V_51 , F_25 ( V_43 ) ) ;
F_24 ( V_2 , V_52 , F_25 ( V_44 ) ) ;
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
F_24 ( V_2 , V_60 , F_25 ( V_58 -> V_61 ) ) ;
if ( V_58 -> V_62 != 0 ) {
F_24 ( V_2 , V_63 ,
F_25 ( V_58 -> V_62 ) ) ;
}
F_5 ( V_2 , V_50 ) ;
return 0 ;
V_12:
return - 1 ;
}
static inline int
F_32 ( struct V_1 * V_2 , const struct V_22 * V_23 )
{
F_13 ( V_2 , V_64 , F_14 ( V_23 -> V_65 ) ) ;
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
F_22 ( V_2 , V_71 , V_68 ) ;
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
F_13 ( V_2 , V_76 ,
F_14 ( V_75 -> V_77 ) ) ;
F_13 ( V_2 , V_78 ,
F_14 ( V_75 -> V_79 ) ) ;
F_13 ( V_2 , V_80 ,
F_14 ( V_75 -> V_81 ) ) ;
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
F_13 ( V_2 , V_90 , F_14 ( ( unsigned long ) V_23 ) ) ;
return 0 ;
V_12:
return - 1 ;
}
static inline int
F_42 ( struct V_1 * V_2 , const struct V_22 * V_23 )
{
F_13 ( V_2 , V_91 , F_14 ( F_43 ( & V_23 -> V_92 . V_93 ) ) ) ;
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
if ( F_48 ( V_23 ) )
F_49 ( V_2 , V_111 , F_50 ( F_48 ( V_23 ) ) ) ;
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
if ( F_48 ( V_23 ) )
F_49 ( V_2 , V_111 , F_50 ( F_48 ( V_23 ) ) ) ;
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
F_96 ( const struct V_8 * V_163 , char * * V_176 )
{
struct V_8 * V_164 [ V_177 + 1 ] ;
F_87 ( V_164 , V_177 , V_163 , V_178 ) ;
if ( ! V_164 [ V_41 ] )
return - V_170 ;
* V_176 = F_97 ( V_164 [ V_41 ] ) ;
return 0 ;
}
static int
F_98 ( struct V_179 * V_180 , struct V_1 * V_2 ,
const struct V_95 * V_96 ,
const struct V_8 * const V_171 [] )
{
struct V_122 * V_122 = F_77 ( V_180 ) ;
struct V_149 * V_150 ;
struct V_3 V_4 ;
struct V_22 * V_23 ;
struct V_97 * V_98 = F_46 ( V_96 ) ;
V_116 V_181 = V_98 -> V_105 ;
T_4 V_174 ;
int V_124 ;
V_124 = F_92 ( V_171 [ V_111 ] , & V_174 ) ;
if ( V_124 < 0 )
return V_124 ;
if ( V_171 [ V_109 ] )
V_124 = F_91 ( V_171 , & V_4 , V_109 , V_181 ) ;
else if ( V_171 [ V_110 ] )
V_124 = F_91 ( V_171 , & V_4 , V_110 , V_181 ) ;
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
return - V_182 ;
V_23 = F_81 ( V_150 ) ;
if ( V_171 [ V_90 ] ) {
V_117 V_183 = F_102 ( F_103 ( V_171 [ V_90 ] ) ) ;
if ( V_183 != ( T_2 ) ( unsigned long ) V_23 ) {
F_74 ( V_23 ) ;
return - V_182 ;
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
F_108 ( V_184 , & V_23 -> V_25 ) ;
F_106 ( V_23 ) ;
F_74 ( V_23 ) ;
}
F_74 ( V_23 ) ;
return 0 ;
}
static int
F_109 ( struct V_179 * V_180 , struct V_1 * V_2 ,
const struct V_95 * V_96 ,
const struct V_8 * const V_171 [] )
{
struct V_122 * V_122 = F_77 ( V_180 ) ;
struct V_149 * V_150 ;
struct V_3 V_4 ;
struct V_22 * V_23 ;
struct V_1 * V_185 = NULL ;
struct V_97 * V_98 = F_46 ( V_96 ) ;
V_116 V_181 = V_98 -> V_105 ;
T_4 V_174 ;
int V_124 ;
if ( V_96 -> V_186 & V_187 ) {
struct V_188 V_189 = {
. V_190 = F_76 ,
. V_191 = F_73 ,
} ;
#ifdef F_64
if ( V_171 [ V_64 ] && V_171 [ V_192 ] ) {
struct V_154 * V_155 ;
V_155 = F_110 ( sizeof( struct V_154 ) ,
V_135 ) ;
if ( V_155 == NULL )
return - V_193 ;
V_155 -> V_65 . V_160 = F_102 ( F_103 ( V_171 [ V_64 ] ) ) ;
V_155 -> V_65 . V_159 =
F_102 ( F_103 ( V_171 [ V_192 ] ) ) ;
V_189 . V_146 = V_155 ;
}
#endif
return F_111 ( V_180 , V_2 , V_96 , & V_189 ) ;
}
V_124 = F_92 ( V_171 [ V_111 ] , & V_174 ) ;
if ( V_124 < 0 )
return V_124 ;
if ( V_171 [ V_109 ] )
V_124 = F_91 ( V_171 , & V_4 , V_109 , V_181 ) ;
else if ( V_171 [ V_110 ] )
V_124 = F_91 ( V_171 , & V_4 , V_110 , V_181 ) ;
else
return - V_170 ;
if ( V_124 < 0 )
return V_124 ;
V_150 = F_101 ( V_122 , V_174 , & V_4 ) ;
if ( ! V_150 )
return - V_182 ;
V_23 = F_81 ( V_150 ) ;
V_124 = - V_193 ;
V_185 = F_69 ( V_194 , V_195 ) ;
if ( V_185 == NULL ) {
F_74 ( V_23 ) ;
return - V_193 ;
}
F_8 () ;
V_124 = F_44 ( V_185 , F_82 ( V_2 ) . V_94 , V_96 -> V_161 ,
F_83 ( V_96 -> V_162 ) , V_23 ) ;
F_11 () ;
F_74 ( V_23 ) ;
if ( V_124 <= 0 )
goto free;
V_124 = F_112 ( V_180 , V_185 , F_82 ( V_2 ) . V_94 , V_196 ) ;
if ( V_124 < 0 )
goto V_39;
return 0 ;
free:
F_71 ( V_185 ) ;
V_39:
return V_124 == - V_143 ? - V_142 : V_124 ;
}
static int
F_113 ( struct V_22 * V_23 ,
enum V_197 V_198 ,
const struct V_8 * V_163 )
{
F_114 (nfnetlink_parse_nat_setup_hook) V_199 ;
V_199 = F_21 ( V_200 ) ;
if ( ! V_199 ) {
#ifdef F_115
F_11 () ;
F_116 () ;
if ( F_117 ( L_1 ) < 0 ) {
F_118 () ;
F_8 () ;
return - V_175 ;
}
F_118 () ;
F_8 () ;
if ( V_200 )
return - V_143 ;
#endif
return - V_175 ;
}
return V_199 ( V_23 , V_198 , V_163 ) ;
}
static int
F_119 ( struct V_22 * V_23 , const struct V_8 * const V_171 [] )
{
unsigned long V_201 ;
unsigned int V_25 = F_102 ( F_103 ( V_171 [ V_24 ] ) ) ;
V_201 = V_23 -> V_25 ^ V_25 ;
if ( V_201 & ( V_72 | V_202 | V_203 ) )
return - V_204 ;
if ( V_201 & V_205 && ! ( V_25 & V_205 ) )
return - V_204 ;
if ( V_201 & V_206 && ! ( V_25 & V_206 ) )
return - V_204 ;
V_23 -> V_25 |= V_25 & ~ ( V_207 | V_208 ) ;
return 0 ;
}
static int
F_120 ( struct V_22 * V_23 , const struct V_8 * const V_171 [] )
{
#ifdef F_63
int V_7 ;
if ( V_171 [ V_209 ] ) {
V_7 = F_113 ( V_23 ,
V_210 ,
V_171 [ V_209 ] ) ;
if ( V_7 < 0 )
return V_7 ;
}
if ( V_171 [ V_211 ] ) {
V_7 = F_113 ( V_23 ,
V_212 ,
V_171 [ V_211 ] ) ;
if ( V_7 < 0 )
return V_7 ;
}
return 0 ;
#else
return - V_175 ;
#endif
}
static inline int
F_121 ( struct V_22 * V_23 , const struct V_8 * const V_171 [] )
{
struct V_37 * V_38 ;
struct V_35 * V_36 = F_20 ( V_23 ) ;
char * V_213 = NULL ;
int V_124 ;
if ( V_23 -> V_214 )
return - V_204 ;
V_124 = F_96 ( V_171 [ V_40 ] , & V_213 ) ;
if ( V_124 < 0 )
return V_124 ;
if ( ! strcmp ( V_213 , L_2 ) ) {
if ( V_36 && V_36 -> V_38 ) {
F_122 ( V_23 ) ;
F_123 ( V_36 -> V_38 , NULL ) ;
}
return 0 ;
}
V_38 = F_124 ( V_213 , F_17 ( V_23 ) ,
F_18 ( V_23 ) ) ;
if ( V_38 == NULL ) {
#ifdef F_115
F_85 ( & V_156 ) ;
if ( F_117 ( L_3 , V_213 ) < 0 ) {
F_78 ( & V_156 ) ;
return - V_175 ;
}
F_78 ( & V_156 ) ;
V_38 = F_124 ( V_213 , F_17 ( V_23 ) ,
F_18 ( V_23 ) ) ;
if ( V_38 )
return - V_143 ;
#endif
return - V_175 ;
}
if ( V_36 ) {
if ( V_36 -> V_38 == V_38 )
return 0 ;
if ( V_36 -> V_38 )
return - V_204 ;
memset ( & V_36 -> V_36 , 0 , sizeof( V_36 -> V_36 ) ) ;
} else {
return - V_175 ;
}
F_125 ( V_36 -> V_38 , V_38 ) ;
return 0 ;
}
static inline int
F_126 ( struct V_22 * V_23 , const struct V_8 * const V_171 [] )
{
V_117 V_26 = F_102 ( F_103 ( V_171 [ V_30 ] ) ) ;
if ( ! F_104 ( & V_23 -> V_26 ) )
return - V_215 ;
V_23 -> V_26 . V_27 = V_28 + V_26 * V_29 ;
F_127 ( & V_23 -> V_26 ) ;
return 0 ;
}
static inline int
F_128 ( struct V_22 * V_23 , const struct V_8 * const V_171 [] )
{
const struct V_8 * V_163 = V_171 [ V_33 ] ;
struct V_8 * V_164 [ V_216 + 1 ] ;
struct V_5 * V_6 ;
int V_124 = 0 ;
F_87 ( V_164 , V_216 , V_163 , V_217 ) ;
F_8 () ;
V_6 = F_10 ( F_17 ( V_23 ) , F_18 ( V_23 ) ) ;
if ( V_6 -> V_218 )
V_124 = V_6 -> V_218 ( V_164 , V_23 ) ;
F_11 () ;
return V_124 ;
}
static inline int
F_129 ( struct V_74 * V_75 , const struct V_8 * const V_163 )
{
struct V_8 * V_171 [ V_219 + 1 ] ;
F_87 ( V_171 , V_219 , V_163 , V_220 ) ;
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
F_130 ( struct V_22 * V_23 ,
const struct V_8 * const V_171 [] )
{
int V_7 = 0 ;
struct V_82 * V_83 = F_40 ( V_23 ) ;
if ( ! V_83 )
return 0 ;
if ( V_171 [ V_87 ] ) {
V_7 = F_129 ( & V_83 -> V_85 [ V_86 ] ,
V_171 [ V_87 ] ) ;
if ( V_7 < 0 )
return V_7 ;
V_23 -> V_25 |= V_84 ;
}
if ( V_171 [ V_89 ] ) {
V_7 = F_129 ( & V_83 -> V_85 [ V_88 ] ,
V_171 [ V_89 ] ) ;
if ( V_7 < 0 )
return V_7 ;
V_23 -> V_25 |= V_84 ;
}
return 0 ;
}
static int
F_131 ( struct V_22 * V_23 ,
const struct V_8 * const V_171 [] )
{
int V_124 ;
if ( V_171 [ V_211 ] || V_171 [ V_209 ] || V_171 [ V_73 ] )
return - V_175 ;
if ( V_171 [ V_40 ] ) {
V_124 = F_121 ( V_23 , V_171 ) ;
if ( V_124 < 0 )
return V_124 ;
}
if ( V_171 [ V_30 ] ) {
V_124 = F_126 ( V_23 , V_171 ) ;
if ( V_124 < 0 )
return V_124 ;
}
if ( V_171 [ V_24 ] ) {
V_124 = F_119 ( V_23 , V_171 ) ;
if ( V_124 < 0 )
return V_124 ;
}
if ( V_171 [ V_33 ] ) {
V_124 = F_128 ( V_23 , V_171 ) ;
if ( V_124 < 0 )
return V_124 ;
}
#if F_132 ( F_64 )
if ( V_171 [ V_64 ] )
V_23 -> V_65 = F_102 ( F_103 ( V_171 [ V_64 ] ) ) ;
#endif
#ifdef F_63
if ( V_171 [ V_87 ] || V_171 [ V_89 ] ) {
V_124 = F_130 ( V_23 , V_171 ) ;
if ( V_124 < 0 )
return V_124 ;
}
#endif
return 0 ;
}
static struct V_22 *
F_133 ( struct V_122 * V_122 , T_4 V_174 ,
const struct V_8 * const V_171 [] ,
struct V_3 * V_221 ,
struct V_3 * V_222 ,
T_5 V_181 )
{
struct V_22 * V_23 ;
int V_124 = - V_170 ;
struct V_37 * V_38 ;
struct V_57 * V_58 ;
V_23 = F_134 ( V_122 , V_174 , V_221 , V_222 , V_135 ) ;
if ( F_135 ( V_23 ) )
return F_136 ( - V_193 ) ;
if ( ! V_171 [ V_30 ] )
goto V_223;
V_23 -> V_26 . V_27 = F_102 ( F_103 ( V_171 [ V_30 ] ) ) ;
V_23 -> V_26 . V_27 = V_28 + V_23 -> V_26 . V_27 * V_29 ;
F_8 () ;
if ( V_171 [ V_40 ] ) {
char * V_213 = NULL ;
V_124 = F_96 ( V_171 [ V_40 ] , & V_213 ) ;
if ( V_124 < 0 )
goto V_224;
V_38 = F_124 ( V_213 , F_17 ( V_23 ) ,
F_18 ( V_23 ) ) ;
if ( V_38 == NULL ) {
F_11 () ;
#ifdef F_115
if ( F_117 ( L_3 , V_213 ) < 0 ) {
V_124 = - V_175 ;
goto V_223;
}
F_8 () ;
V_38 = F_124 ( V_213 ,
F_17 ( V_23 ) ,
F_18 ( V_23 ) ) ;
if ( V_38 ) {
V_124 = - V_143 ;
goto V_224;
}
F_11 () ;
#endif
V_124 = - V_175 ;
goto V_223;
} else {
struct V_35 * V_36 ;
V_36 = F_137 ( V_23 , V_135 ) ;
if ( V_36 == NULL ) {
V_124 = - V_193 ;
goto V_224;
}
F_123 ( V_36 -> V_38 , V_38 ) ;
}
} else {
V_124 = F_138 ( V_23 , NULL , V_135 ) ;
if ( V_124 < 0 )
goto V_224;
}
if ( V_171 [ V_211 ] || V_171 [ V_209 ] ) {
V_124 = F_120 ( V_23 , V_171 ) ;
if ( V_124 < 0 )
goto V_224;
}
F_139 ( V_23 , V_135 ) ;
F_140 ( V_23 , V_135 ) ;
F_141 ( V_23 , 0 , 0 , V_135 ) ;
V_23 -> V_25 |= V_202 ;
if ( V_171 [ V_24 ] ) {
V_124 = F_119 ( V_23 , V_171 ) ;
if ( V_124 < 0 )
goto V_224;
}
#ifdef F_63
if ( V_171 [ V_87 ] || V_171 [ V_89 ] ) {
V_124 = F_130 ( V_23 , V_171 ) ;
if ( V_124 < 0 )
goto V_224;
}
#endif
memset ( & V_23 -> V_225 , 0 , sizeof( V_23 -> V_225 ) ) ;
if ( V_171 [ V_33 ] ) {
V_124 = F_128 ( V_23 , V_171 ) ;
if ( V_124 < 0 )
goto V_224;
}
#if F_132 ( F_64 )
if ( V_171 [ V_64 ] )
V_23 -> V_65 = F_102 ( F_103 ( V_171 [ V_64 ] ) ) ;
#endif
if ( V_171 [ V_73 ] ) {
struct V_3 V_214 ;
struct V_149 * V_226 ;
struct V_22 * V_227 ;
V_124 = F_91 ( V_171 , & V_214 , V_73 , V_181 ) ;
if ( V_124 < 0 )
goto V_224;
V_226 = F_101 ( V_122 , V_174 , & V_214 ) ;
if ( V_226 == NULL ) {
V_124 = - V_182 ;
goto V_224;
}
V_227 = F_81 ( V_226 ) ;
F_142 ( V_228 , & V_23 -> V_25 ) ;
V_23 -> V_214 = V_227 ;
}
V_58 = F_31 ( V_23 ) ;
if ( V_58 )
V_58 -> V_61 = F_143 ( F_144 () ) ;
V_124 = F_145 ( V_23 ) ;
if ( V_124 < 0 )
goto V_224;
F_11 () ;
return V_23 ;
V_224:
F_11 () ;
V_223:
F_146 ( V_23 ) ;
return F_136 ( V_124 ) ;
}
static int
F_147 ( struct V_179 * V_180 , struct V_1 * V_2 ,
const struct V_95 * V_96 ,
const struct V_8 * const V_171 [] )
{
struct V_122 * V_122 = F_77 ( V_180 ) ;
struct V_3 V_221 , V_222 ;
struct V_149 * V_150 = NULL ;
struct V_97 * V_98 = F_46 ( V_96 ) ;
struct V_22 * V_23 ;
V_116 V_181 = V_98 -> V_105 ;
T_4 V_174 ;
int V_124 ;
V_124 = F_92 ( V_171 [ V_111 ] , & V_174 ) ;
if ( V_124 < 0 )
return V_124 ;
if ( V_171 [ V_109 ] ) {
V_124 = F_91 ( V_171 , & V_221 , V_109 , V_181 ) ;
if ( V_124 < 0 )
return V_124 ;
}
if ( V_171 [ V_110 ] ) {
V_124 = F_91 ( V_171 , & V_222 , V_110 , V_181 ) ;
if ( V_124 < 0 )
return V_124 ;
}
if ( V_171 [ V_109 ] )
V_150 = F_101 ( V_122 , V_174 , & V_221 ) ;
else if ( V_171 [ V_110 ] )
V_150 = F_101 ( V_122 , V_174 , & V_222 ) ;
if ( V_150 == NULL ) {
V_124 = - V_182 ;
if ( V_96 -> V_186 & V_130 ) {
enum V_229 V_119 ;
V_23 = F_133 ( V_122 , V_174 , V_171 , & V_221 ,
& V_222 , V_181 ) ;
if ( F_135 ( V_23 ) )
return F_148 ( V_23 ) ;
V_124 = 0 ;
if ( F_149 ( V_228 , & V_23 -> V_25 ) )
V_119 = V_129 ;
else
V_119 = V_128 ;
F_150 ( ( 1 << V_230 ) |
( 1 << V_231 ) |
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
V_124 = - V_232 ;
V_23 = F_81 ( V_150 ) ;
if ( ! ( V_96 -> V_186 & V_131 ) ) {
F_78 ( & V_156 ) ;
V_124 = F_131 ( V_23 , V_171 ) ;
F_85 ( & V_156 ) ;
if ( V_124 == 0 ) {
F_150 ( ( 1 << V_230 ) |
( 1 << V_231 ) |
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
static inline int
F_151 ( struct V_1 * V_2 ,
const struct V_3 * V_4 ,
enum V_233 type )
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
F_152 ( struct V_1 * V_2 ,
const struct V_3 * V_4 ,
const struct V_234 * V_159 )
{
int V_7 ;
struct V_17 * V_18 ;
struct V_5 * V_6 ;
struct V_3 V_235 ;
struct V_8 * V_9 ;
memset ( & V_235 , 0xFF , sizeof( V_235 ) ) ;
memcpy ( & V_235 . V_20 . V_181 , & V_159 -> V_20 . V_181 , sizeof( V_235 . V_20 . V_181 ) ) ;
V_235 . V_20 . V_236 . V_237 = V_159 -> V_20 . V_236 . V_237 ;
V_235 . V_14 . V_15 = V_4 -> V_14 . V_15 ;
V_9 = F_2 ( V_2 , V_238 | V_11 ) ;
if ( ! V_9 )
goto V_12;
F_8 () ;
V_18 = F_9 ( V_4 -> V_20 . V_21 ) ;
V_7 = F_6 ( V_2 , & V_235 , V_18 ) ;
if ( V_7 >= 0 ) {
V_6 = F_10 ( V_4 -> V_20 . V_21 ,
V_4 -> V_14 . V_15 ) ;
V_7 = F_1 ( V_2 , & V_235 , V_6 ) ;
}
F_11 () ;
if ( F_153 ( V_7 < 0 ) )
goto V_12;
F_5 ( V_2 , V_9 ) ;
return 0 ;
V_12:
return - 1 ;
}
static int
F_154 ( struct V_1 * V_2 ,
const struct V_239 * exp )
{
struct V_22 * V_214 = exp -> V_214 ;
long V_26 = ( ( long ) exp -> V_26 . V_27 - ( long ) V_28 ) / V_29 ;
struct V_35 * V_36 ;
#ifdef F_63
struct V_8 * V_9 ;
struct V_3 V_240 = {} ;
#endif
struct V_241 * V_242 ;
if ( V_26 < 0 )
V_26 = 0 ;
if ( F_151 ( V_2 , & exp -> V_4 , V_243 ) < 0 )
goto V_12;
if ( F_152 ( V_2 , & exp -> V_4 , & exp -> V_159 ) < 0 )
goto V_12;
if ( F_151 ( V_2 ,
& V_214 -> V_244 [ V_86 ] . V_4 ,
V_245 ) < 0 )
goto V_12;
#ifdef F_63
if ( exp -> V_246 || exp -> V_247 . V_237 ) {
V_9 = F_2 ( V_2 , V_248 | V_11 ) ;
if ( ! V_9 )
goto V_12;
F_13 ( V_2 , V_249 , F_14 ( exp -> V_46 ) ) ;
V_240 . V_20 . V_21 = F_17 ( V_214 ) ;
V_240 . V_20 . V_181 . V_250 = exp -> V_246 ;
V_240 . V_14 . V_15 = F_18 ( V_214 ) ;
V_240 . V_20 . V_236 = exp -> V_247 ;
if ( F_151 ( V_2 , & V_240 ,
V_251 ) < 0 )
goto V_12;
F_5 ( V_2 , V_9 ) ;
}
#endif
F_13 ( V_2 , V_252 , F_14 ( V_26 ) ) ;
F_13 ( V_2 , V_253 , F_14 ( ( unsigned long ) exp ) ) ;
F_13 ( V_2 , V_254 , F_14 ( exp -> V_99 ) ) ;
F_13 ( V_2 , V_255 , F_14 ( exp -> V_256 ) ) ;
V_36 = F_20 ( V_214 ) ;
if ( V_36 ) {
struct V_37 * V_38 ;
V_38 = F_21 ( V_36 -> V_38 ) ;
if ( V_38 )
F_22 ( V_2 , V_257 , V_38 -> V_42 ) ;
}
V_242 = F_155 ( exp -> V_258 ) ;
if ( V_242 != NULL )
F_22 ( V_2 , V_259 , V_242 -> V_42 ) ;
return 0 ;
V_12:
return - 1 ;
}
static int
F_156 ( struct V_1 * V_2 , T_2 V_94 , T_2 V_85 ,
int V_101 , const struct V_239 * exp )
{
struct V_95 * V_96 ;
struct V_97 * V_98 ;
unsigned int V_99 = V_94 ? V_100 : 0 ;
V_101 |= V_260 << 8 ;
V_96 = F_45 ( V_2 , V_94 , V_85 , V_101 , sizeof( * V_98 ) , V_99 ) ;
if ( V_96 == NULL )
goto V_104;
V_98 = F_46 ( V_96 ) ;
V_98 -> V_105 = exp -> V_4 . V_20 . V_21 ;
V_98 -> V_106 = V_107 ;
V_98 -> V_108 = 0 ;
if ( F_154 ( V_2 , exp ) < 0 )
goto V_12;
F_51 ( V_2 , V_96 ) ;
return V_2 -> V_67 ;
V_104:
V_12:
F_52 ( V_2 , V_96 ) ;
return - 1 ;
}
static int
F_157 ( unsigned int V_119 , struct V_261 * V_121 )
{
struct V_239 * exp = V_121 -> exp ;
struct V_122 * V_122 = F_158 ( exp ) ;
struct V_95 * V_96 ;
struct V_97 * V_98 ;
struct V_1 * V_2 ;
unsigned int type , V_123 ;
int V_99 = 0 ;
if ( V_119 & ( 1 << V_262 ) ) {
type = V_263 ;
V_123 = V_264 ;
} else if ( V_119 & ( 1 << V_265 ) ) {
type = V_266 ;
V_99 = V_130 | V_131 ;
V_123 = V_267 ;
} else
return 0 ;
if ( ! V_121 -> V_134 && ! F_68 ( V_122 , V_123 ) )
return 0 ;
V_2 = F_69 ( V_194 , V_135 ) ;
if ( V_2 == NULL )
goto V_136;
type |= V_260 << 8 ;
V_96 = F_45 ( V_2 , V_121 -> V_94 , 0 , type , sizeof( * V_98 ) , V_99 ) ;
if ( V_96 == NULL )
goto V_104;
V_98 = F_46 ( V_96 ) ;
V_98 -> V_105 = exp -> V_4 . V_20 . V_21 ;
V_98 -> V_106 = V_107 ;
V_98 -> V_108 = 0 ;
F_8 () ;
if ( F_154 ( V_2 , exp ) < 0 )
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
static int F_159 ( struct V_144 * V_145 )
{
if ( V_145 -> args [ 1 ] )
F_160 ( (struct V_239 * ) V_145 -> args [ 1 ] ) ;
return 0 ;
}
static int
F_161 ( struct V_1 * V_2 , struct V_144 * V_145 )
{
struct V_122 * V_122 = F_77 ( V_2 -> V_147 ) ;
struct V_239 * exp , * V_148 ;
struct V_97 * V_98 = F_46 ( V_145 -> V_96 ) ;
struct V_268 * V_152 ;
V_116 V_18 = V_98 -> V_105 ;
F_8 () ;
V_148 = (struct V_239 * ) V_145 -> args [ 1 ] ;
for (; V_145 -> args [ 0 ] < V_269 ; V_145 -> args [ 0 ] ++ ) {
V_158:
F_162 (exp, n, &net->ct.expect_hash[cb->args[0]],
hnode) {
if ( V_18 && exp -> V_4 . V_20 . V_21 != V_18 )
continue;
if ( V_145 -> args [ 1 ] ) {
if ( exp != V_148 )
continue;
V_145 -> args [ 1 ] = 0 ;
}
if ( F_156 ( V_2 ,
F_82 ( V_145 -> V_2 ) . V_94 ,
V_145 -> V_96 -> V_161 ,
V_266 ,
exp ) < 0 ) {
if ( ! F_163 ( & exp -> V_93 ) )
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
F_160 ( V_148 ) ;
return V_2 -> V_67 ;
}
static int
F_164 ( struct V_179 * V_180 , struct V_1 * V_2 ,
const struct V_95 * V_96 ,
const struct V_8 * const V_171 [] )
{
struct V_122 * V_122 = F_77 ( V_180 ) ;
struct V_3 V_4 ;
struct V_239 * exp ;
struct V_1 * V_185 ;
struct V_97 * V_98 = F_46 ( V_96 ) ;
V_116 V_181 = V_98 -> V_105 ;
T_4 V_174 ;
int V_124 ;
if ( V_96 -> V_186 & V_187 ) {
struct V_188 V_189 = {
. V_190 = F_161 ,
. V_191 = F_159 ,
} ;
return F_111 ( V_180 , V_2 , V_96 , & V_189 ) ;
}
V_124 = F_92 ( V_171 [ V_270 ] , & V_174 ) ;
if ( V_124 < 0 )
return V_124 ;
if ( V_171 [ V_243 ] )
V_124 = F_91 ( V_171 , & V_4 , V_243 , V_181 ) ;
else if ( V_171 [ V_245 ] )
V_124 = F_91 ( V_171 , & V_4 , V_245 , V_181 ) ;
else
return - V_170 ;
if ( V_124 < 0 )
return V_124 ;
exp = F_165 ( V_122 , V_174 , & V_4 ) ;
if ( ! exp )
return - V_182 ;
if ( V_171 [ V_253 ] ) {
T_6 V_183 = F_103 ( V_171 [ V_253 ] ) ;
if ( F_102 ( V_183 ) != ( T_2 ) ( unsigned long ) exp ) {
F_160 ( exp ) ;
return - V_182 ;
}
}
V_124 = - V_193 ;
V_185 = F_69 ( V_194 , V_195 ) ;
if ( V_185 == NULL ) {
F_160 ( exp ) ;
goto V_39;
}
F_8 () ;
V_124 = F_156 ( V_185 , F_82 ( V_2 ) . V_94 ,
V_96 -> V_161 , V_266 , exp ) ;
F_11 () ;
F_160 ( exp ) ;
if ( V_124 <= 0 )
goto free;
V_124 = F_112 ( V_180 , V_185 , F_82 ( V_2 ) . V_94 , V_196 ) ;
if ( V_124 < 0 )
goto V_39;
return 0 ;
free:
F_71 ( V_185 ) ;
V_39:
return V_124 == - V_143 ? - V_142 : V_124 ;
}
static int
F_166 ( struct V_179 * V_180 , struct V_1 * V_2 ,
const struct V_95 * V_96 ,
const struct V_8 * const V_171 [] )
{
struct V_122 * V_122 = F_77 ( V_180 ) ;
struct V_239 * exp ;
struct V_3 V_4 ;
struct V_97 * V_98 = F_46 ( V_96 ) ;
struct V_268 * V_152 , * V_271 ;
V_116 V_181 = V_98 -> V_105 ;
unsigned int V_272 ;
T_4 V_174 ;
int V_124 ;
if ( V_171 [ V_243 ] ) {
V_124 = F_92 ( V_171 [ V_270 ] , & V_174 ) ;
if ( V_124 < 0 )
return V_124 ;
V_124 = F_91 ( V_171 , & V_4 , V_243 , V_181 ) ;
if ( V_124 < 0 )
return V_124 ;
exp = F_165 ( V_122 , V_174 , & V_4 ) ;
if ( ! exp )
return - V_182 ;
if ( V_171 [ V_253 ] ) {
T_6 V_183 = F_103 ( V_171 [ V_253 ] ) ;
if ( F_102 ( V_183 ) != ( T_2 ) ( unsigned long ) exp ) {
F_160 ( exp ) ;
return - V_182 ;
}
}
F_78 ( & V_156 ) ;
if ( F_104 ( & exp -> V_26 ) ) {
F_167 ( exp , F_82 ( V_2 ) . V_94 ,
F_100 ( V_96 ) ) ;
F_160 ( exp ) ;
}
F_85 ( & V_156 ) ;
F_160 ( exp ) ;
} else if ( V_171 [ V_257 ] ) {
char * V_42 = F_97 ( V_171 [ V_257 ] ) ;
struct V_35 * V_273 ;
F_78 ( & V_156 ) ;
for ( V_272 = 0 ; V_272 < V_269 ; V_272 ++ ) {
F_168 (exp, n, next,
&net->ct.expect_hash[i],
hnode) {
V_273 = F_20 ( exp -> V_214 ) ;
if ( ! strcmp ( V_273 -> V_38 -> V_42 , V_42 ) &&
F_104 ( & exp -> V_26 ) ) {
F_167 ( exp ,
F_82 ( V_2 ) . V_94 ,
F_100 ( V_96 ) ) ;
F_160 ( exp ) ;
}
}
}
F_85 ( & V_156 ) ;
} else {
F_78 ( & V_156 ) ;
for ( V_272 = 0 ; V_272 < V_269 ; V_272 ++ ) {
F_168 (exp, n, next,
&net->ct.expect_hash[i],
hnode) {
if ( F_104 ( & exp -> V_26 ) ) {
F_167 ( exp ,
F_82 ( V_2 ) . V_94 ,
F_100 ( V_96 ) ) ;
F_160 ( exp ) ;
}
}
}
F_85 ( & V_156 ) ;
}
return 0 ;
}
static int
F_169 ( struct V_239 * V_274 ,
const struct V_8 * const V_171 [] )
{
return - V_175 ;
}
static int
F_170 ( const struct V_8 * V_163 ,
struct V_239 * exp ,
V_116 V_181 )
{
#ifdef F_63
struct V_8 * V_164 [ V_275 + 1 ] ;
struct V_3 V_240 = {} ;
int V_124 ;
F_87 ( V_164 , V_275 , V_163 , V_276 ) ;
if ( ! V_164 [ V_249 ] || ! V_164 [ V_251 ] )
return - V_170 ;
V_124 = F_91 ( ( const struct V_8 * const * ) V_164 ,
& V_240 , V_251 , V_181 ) ;
if ( V_124 < 0 )
return V_124 ;
exp -> V_246 = V_240 . V_20 . V_181 . V_250 ;
exp -> V_247 = V_240 . V_20 . V_236 ;
exp -> V_46 = F_102 ( F_103 ( V_164 [ V_249 ] ) ) ;
return 0 ;
#else
return - V_175 ;
#endif
}
static int
F_171 ( struct V_122 * V_122 , T_4 V_174 ,
const struct V_8 * const V_171 [] ,
V_116 V_181 ,
T_2 V_94 , int V_134 )
{
struct V_3 V_4 , V_159 , F_37 ;
struct V_149 * V_150 = NULL ;
struct V_239 * exp ;
struct V_22 * V_23 ;
struct V_35 * V_36 ;
struct V_37 * V_38 = NULL ;
V_117 V_256 = 0 ;
int V_124 = 0 ;
V_124 = F_91 ( V_171 , & V_4 , V_243 , V_181 ) ;
if ( V_124 < 0 )
return V_124 ;
V_124 = F_91 ( V_171 , & V_159 , V_238 , V_181 ) ;
if ( V_124 < 0 )
return V_124 ;
V_124 = F_91 ( V_171 , & F_37 , V_245 , V_181 ) ;
if ( V_124 < 0 )
return V_124 ;
V_150 = F_101 ( V_122 , V_174 , & F_37 ) ;
if ( ! V_150 )
return - V_182 ;
V_23 = F_81 ( V_150 ) ;
if ( V_171 [ V_257 ] ) {
const char * V_213 = F_97 ( V_171 [ V_257 ] ) ;
V_38 = F_124 ( V_213 , F_17 ( V_23 ) ,
F_18 ( V_23 ) ) ;
if ( V_38 == NULL ) {
#ifdef F_115
if ( F_117 ( L_3 , V_213 ) < 0 ) {
V_124 = - V_175 ;
goto V_39;
}
V_38 = F_124 ( V_213 ,
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
if ( V_171 [ V_255 ] && V_38 ) {
V_256 = F_102 ( F_103 ( V_171 [ V_255 ] ) ) ;
if ( V_256 > V_38 -> V_277 ) {
V_124 = - V_170 ;
goto V_39;
}
}
exp = F_172 ( V_23 ) ;
if ( ! exp ) {
V_124 = - V_193 ;
goto V_39;
}
V_36 = F_20 ( V_23 ) ;
if ( ! V_36 ) {
if ( ! V_171 [ V_252 ] ) {
V_124 = - V_170 ;
goto V_39;
}
exp -> V_26 . V_27 =
V_28 + F_102 ( F_103 ( V_171 [ V_252 ] ) ) * V_29 ;
exp -> V_99 = V_278 ;
if ( V_171 [ V_254 ] ) {
exp -> V_99 |=
F_102 ( F_103 ( V_171 [ V_254 ] ) ) ;
}
} else {
if ( V_171 [ V_254 ] ) {
exp -> V_99 = F_102 ( F_103 ( V_171 [ V_254 ] ) ) ;
exp -> V_99 &= ~ V_278 ;
} else
exp -> V_99 = 0 ;
}
if ( V_171 [ V_259 ] ) {
const char * V_42 = F_97 ( V_171 [ V_259 ] ) ;
struct V_241 * V_242 ;
V_242 = F_173 ( V_42 ) ;
if ( V_242 == NULL ) {
V_124 = - V_170 ;
goto V_279;
}
exp -> V_258 = V_242 -> V_258 ;
} else
exp -> V_258 = NULL ;
exp -> V_256 = V_256 ;
exp -> V_214 = V_23 ;
exp -> V_38 = V_38 ;
memcpy ( & exp -> V_4 , & V_4 , sizeof( struct V_3 ) ) ;
memcpy ( & exp -> V_159 . V_20 . V_181 , & V_159 . V_20 . V_181 , sizeof( exp -> V_159 . V_20 . V_181 ) ) ;
exp -> V_159 . V_20 . V_236 . V_237 = V_159 . V_20 . V_236 . V_237 ;
if ( V_171 [ V_248 ] ) {
V_124 = F_170 ( V_171 [ V_248 ] ,
exp , V_181 ) ;
if ( V_124 < 0 )
goto V_279;
}
V_124 = F_174 ( exp , V_94 , V_134 ) ;
V_279:
F_160 ( exp ) ;
V_39:
F_74 ( F_81 ( V_150 ) ) ;
return V_124 ;
}
static int
F_175 ( struct V_179 * V_180 , struct V_1 * V_2 ,
const struct V_95 * V_96 ,
const struct V_8 * const V_171 [] )
{
struct V_122 * V_122 = F_77 ( V_180 ) ;
struct V_3 V_4 ;
struct V_239 * exp ;
struct V_97 * V_98 = F_46 ( V_96 ) ;
V_116 V_181 = V_98 -> V_105 ;
T_4 V_174 ;
int V_124 ;
if ( ! V_171 [ V_243 ]
|| ! V_171 [ V_238 ]
|| ! V_171 [ V_245 ] )
return - V_170 ;
V_124 = F_92 ( V_171 [ V_270 ] , & V_174 ) ;
if ( V_124 < 0 )
return V_124 ;
V_124 = F_91 ( V_171 , & V_4 , V_243 , V_181 ) ;
if ( V_124 < 0 )
return V_124 ;
F_78 ( & V_156 ) ;
exp = F_176 ( V_122 , V_174 , & V_4 ) ;
if ( ! exp ) {
F_85 ( & V_156 ) ;
V_124 = - V_182 ;
if ( V_96 -> V_186 & V_130 ) {
V_124 = F_171 ( V_122 , V_174 , V_171 ,
V_181 ,
F_82 ( V_2 ) . V_94 ,
F_100 ( V_96 ) ) ;
}
return V_124 ;
}
V_124 = - V_232 ;
if ( ! ( V_96 -> V_186 & V_131 ) )
V_124 = F_169 ( exp , V_171 ) ;
F_85 ( & V_156 ) ;
return V_124 ;
}
static int T_7 F_177 ( struct V_122 * V_122 )
{
#ifdef F_178
int V_7 ;
V_7 = F_179 ( V_122 , & V_280 ) ;
if ( V_7 < 0 ) {
F_180 ( L_4 ) ;
goto V_279;
}
V_7 = F_181 ( V_122 , & V_281 ) ;
if ( V_7 < 0 ) {
F_180 ( L_5 ) ;
goto V_282;
}
#endif
return 0 ;
#ifdef F_178
V_282:
F_182 ( V_122 , & V_280 ) ;
V_279:
return V_7 ;
#endif
}
static void F_183 ( struct V_122 * V_122 )
{
#ifdef F_178
F_184 ( V_122 , & V_281 ) ;
F_182 ( V_122 , & V_280 ) ;
#endif
}
static void T_8 F_185 ( struct V_283 * V_284 )
{
struct V_122 * V_122 ;
F_186 (net, net_exit_list, exit_list)
F_183 ( V_122 ) ;
}
static int T_9 F_187 ( void )
{
int V_7 ;
F_188 ( L_6 , V_106 ) ;
V_7 = F_189 ( & V_285 ) ;
if ( V_7 < 0 ) {
F_180 ( L_7 ) ;
goto V_279;
}
V_7 = F_189 ( & V_286 ) ;
if ( V_7 < 0 ) {
F_180 ( L_8 ) ;
goto V_287;
}
if ( F_190 ( & V_288 ) ) {
F_180 ( L_9 ) ;
goto V_289;
}
return 0 ;
V_289:
F_191 ( & V_286 ) ;
V_287:
F_191 ( & V_285 ) ;
V_279:
return V_7 ;
}
static void T_10 F_192 ( void )
{
F_188 ( L_10 ) ;
F_193 ( & V_288 ) ;
F_191 ( & V_286 ) ;
F_191 ( & V_285 ) ;
}
