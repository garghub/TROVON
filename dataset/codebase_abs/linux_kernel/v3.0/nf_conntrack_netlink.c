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
V_18 = F_8 ( V_4 -> V_20 . V_21 ) ;
V_7 = F_6 ( V_2 , V_4 , V_18 ) ;
if ( F_9 ( V_7 < 0 ) )
return V_7 ;
V_6 = F_10 ( V_4 -> V_20 . V_21 , V_4 -> V_14 . V_15 ) ;
V_7 = F_1 ( V_2 , V_4 , V_6 ) ;
return V_7 ;
}
static inline int
F_11 ( struct V_1 * V_2 , const struct V_22 * V_23 )
{
F_12 ( V_2 , V_24 , F_13 ( V_23 -> V_25 ) ) ;
return 0 ;
V_12:
return - 1 ;
}
static inline int
F_14 ( struct V_1 * V_2 , const struct V_22 * V_23 )
{
long V_26 = ( V_23 -> V_26 . V_27 - V_28 ) / V_29 ;
if ( V_26 < 0 )
V_26 = 0 ;
F_12 ( V_2 , V_30 , F_13 ( V_26 ) ) ;
return 0 ;
V_12:
return - 1 ;
}
static inline int
F_15 ( struct V_1 * V_2 , struct V_22 * V_23 )
{
struct V_5 * V_6 ;
struct V_8 * V_31 ;
int V_7 ;
V_6 = F_10 ( F_16 ( V_23 ) , F_17 ( V_23 ) ) ;
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
F_18 ( struct V_1 * V_2 , const struct V_22 * V_23 )
{
struct V_8 * V_34 ;
const struct V_35 * V_36 = F_19 ( V_23 ) ;
struct V_37 * V_38 ;
if ( ! V_36 )
return 0 ;
V_38 = F_20 ( V_36 -> V_38 ) ;
if ( ! V_38 )
goto V_39;
V_34 = F_2 ( V_2 , V_40 | V_11 ) ;
if ( ! V_34 )
goto V_12;
F_21 ( V_2 , V_41 , V_38 -> V_42 ) ;
if ( V_38 -> V_32 )
V_38 -> V_32 ( V_2 , V_23 ) ;
F_5 ( V_2 , V_34 ) ;
V_39:
return 0 ;
V_12:
return - 1 ;
}
static int
F_22 ( struct V_1 * V_2 , const struct V_22 * V_23 ,
enum V_43 V_44 )
{
enum V_45 type = V_44 ? V_46 : V_47 ;
struct V_8 * V_48 ;
const struct V_49 * V_50 ;
V_50 = F_23 ( V_23 ) ;
if ( ! V_50 )
return 0 ;
V_48 = F_2 ( V_2 , type | V_11 ) ;
if ( ! V_48 )
goto V_12;
F_24 ( V_2 , V_51 ,
F_25 ( V_50 [ V_44 ] . V_52 ) ) ;
F_24 ( V_2 , V_53 ,
F_25 ( V_50 [ V_44 ] . V_54 ) ) ;
F_5 ( V_2 , V_48 ) ;
return 0 ;
V_12:
return - 1 ;
}
static int
F_26 ( struct V_1 * V_2 , const struct V_22 * V_23 )
{
struct V_8 * V_48 ;
const struct V_55 * V_56 ;
V_56 = F_27 ( V_23 ) ;
if ( ! V_56 )
return 0 ;
V_48 = F_2 ( V_2 , V_57 | V_11 ) ;
if ( ! V_48 )
goto V_12;
F_24 ( V_2 , V_58 , F_25 ( V_56 -> V_59 ) ) ;
if ( V_56 -> V_60 != 0 ) {
F_24 ( V_2 , V_61 ,
F_25 ( V_56 -> V_60 ) ) ;
}
F_5 ( V_2 , V_48 ) ;
return 0 ;
V_12:
return - 1 ;
}
static inline int
F_28 ( struct V_1 * V_2 , const struct V_22 * V_23 )
{
F_12 ( V_2 , V_62 , F_13 ( V_23 -> V_63 ) ) ;
return 0 ;
V_12:
return - 1 ;
}
static inline int
F_29 ( struct V_1 * V_2 , const struct V_22 * V_23 )
{
struct V_8 * V_64 ;
int V_65 , V_7 ;
char * V_66 ;
V_7 = F_30 ( V_23 -> V_67 , & V_66 , & V_65 ) ;
if ( V_7 )
return 0 ;
V_7 = - 1 ;
V_64 = F_2 ( V_2 , V_68 | V_11 ) ;
if ( ! V_64 )
goto V_12;
F_21 ( V_2 , V_69 , V_66 ) ;
F_5 ( V_2 , V_64 ) ;
V_7 = 0 ;
V_12:
F_31 ( V_66 , V_65 ) ;
return V_7 ;
}
static inline int
F_32 ( struct V_1 * V_2 , const struct V_22 * V_23 )
{
struct V_8 * V_9 ;
if ( ! ( V_23 -> V_25 & V_70 ) )
return 0 ;
V_9 = F_2 ( V_2 , V_71 | V_11 ) ;
if ( ! V_9 )
goto V_12;
if ( F_7 ( V_2 , F_33 ( V_23 ) ) < 0 )
goto V_12;
F_5 ( V_2 , V_9 ) ;
return 0 ;
V_12:
return - 1 ;
}
static int
F_34 ( struct V_1 * V_2 , const struct V_72 * V_73 , int type )
{
struct V_8 * V_9 ;
V_9 = F_2 ( V_2 , type | V_11 ) ;
if ( ! V_9 )
goto V_12;
F_12 ( V_2 , V_74 ,
F_13 ( V_73 -> V_75 ) ) ;
F_12 ( V_2 , V_76 ,
F_13 ( V_73 -> V_77 ) ) ;
F_12 ( V_2 , V_78 ,
F_13 ( V_73 -> V_79 ) ) ;
F_5 ( V_2 , V_9 ) ;
return 0 ;
V_12:
return - 1 ;
}
static inline int
F_35 ( struct V_1 * V_2 , const struct V_22 * V_23 )
{
struct V_72 * V_73 ;
struct V_80 * V_81 = F_36 ( V_23 ) ;
if ( ! ( V_23 -> V_25 & V_82 ) || ! V_81 )
return 0 ;
V_73 = & V_81 -> V_83 [ V_84 ] ;
if ( F_34 ( V_2 , V_73 , V_85 ) == - 1 )
return - 1 ;
V_73 = & V_81 -> V_83 [ V_86 ] ;
if ( F_34 ( V_2 , V_73 , V_87 ) == - 1 )
return - 1 ;
return 0 ;
}
static inline int
F_37 ( struct V_1 * V_2 , const struct V_22 * V_23 )
{
F_12 ( V_2 , V_88 , F_13 ( ( unsigned long ) V_23 ) ) ;
return 0 ;
V_12:
return - 1 ;
}
static inline int
F_38 ( struct V_1 * V_2 , const struct V_22 * V_23 )
{
F_12 ( V_2 , V_89 , F_13 ( F_39 ( & V_23 -> V_90 . V_91 ) ) ) ;
return 0 ;
V_12:
return - 1 ;
}
static int
F_40 ( struct V_1 * V_2 , T_1 V_92 , T_1 V_83 ,
int V_93 , struct V_22 * V_23 )
{
struct V_94 * V_95 ;
struct V_96 * V_97 ;
struct V_8 * V_9 ;
unsigned int V_98 = V_92 ? V_99 : 0 ;
V_93 |= V_100 << 8 ;
V_95 = F_41 ( V_2 , V_92 , V_83 , V_93 , sizeof( * V_97 ) , V_98 ) ;
if ( V_95 == NULL )
goto V_101;
V_97 = F_42 ( V_95 ) ;
V_97 -> V_102 = F_16 ( V_23 ) ;
V_97 -> V_103 = V_104 ;
V_97 -> V_105 = 0 ;
V_9 = F_2 ( V_2 , V_106 | V_11 ) ;
if ( ! V_9 )
goto V_12;
if ( F_7 ( V_2 , F_43 ( V_23 , V_84 ) ) < 0 )
goto V_12;
F_5 ( V_2 , V_9 ) ;
V_9 = F_2 ( V_2 , V_107 | V_11 ) ;
if ( ! V_9 )
goto V_12;
if ( F_7 ( V_2 , F_43 ( V_23 , V_86 ) ) < 0 )
goto V_12;
F_5 ( V_2 , V_9 ) ;
if ( F_44 ( V_23 ) )
F_45 ( V_2 , V_108 , F_46 ( F_44 ( V_23 ) ) ) ;
if ( F_11 ( V_2 , V_23 ) < 0 ||
F_14 ( V_2 , V_23 ) < 0 ||
F_22 ( V_2 , V_23 , V_84 ) < 0 ||
F_22 ( V_2 , V_23 , V_86 ) < 0 ||
F_26 ( V_2 , V_23 ) < 0 ||
F_15 ( V_2 , V_23 ) < 0 ||
F_18 ( V_2 , V_23 ) < 0 ||
F_28 ( V_2 , V_23 ) < 0 ||
F_29 ( V_2 , V_23 ) < 0 ||
F_37 ( V_2 , V_23 ) < 0 ||
F_38 ( V_2 , V_23 ) < 0 ||
F_32 ( V_2 , V_23 ) < 0 ||
F_35 ( V_2 , V_23 ) < 0 )
goto V_12;
F_47 ( V_2 , V_95 ) ;
return V_2 -> V_65 ;
V_101:
V_12:
F_48 ( V_2 , V_95 ) ;
return - 1 ;
}
static inline T_2
F_49 ( const struct V_22 * V_23 )
{
struct V_17 * V_18 ;
struct V_5 * V_6 ;
T_2 V_65 = 0 ;
F_50 () ;
V_18 = F_8 ( F_16 ( V_23 ) ) ;
V_65 += V_18 -> V_109 ;
V_6 = F_10 ( F_16 ( V_23 ) , F_17 ( V_23 ) ) ;
V_65 += V_6 -> V_109 ;
F_51 () ;
return V_65 ;
}
static inline T_2
F_52 ( const struct V_22 * V_23 )
{
if ( ! F_53 ( V_23 , V_110 ) )
return 0 ;
return 2 * F_54 ( 0 )
+ 2 * F_54 ( sizeof( V_111 ) )
+ 2 * F_54 ( sizeof( V_111 ) )
;
}
static inline int
F_55 ( const struct V_22 * V_23 )
{
#ifdef F_56
int V_65 , V_7 ;
V_7 = F_30 ( V_23 -> V_67 , NULL , & V_65 ) ;
if ( V_7 )
return 0 ;
return F_54 ( 0 )
+ F_54 ( sizeof( char ) * V_65 ) ;
#else
return 0 ;
#endif
}
static inline T_2
F_57 ( const struct V_22 * V_23 )
{
#ifdef F_58
if ( ! F_53 ( V_23 , V_112 ) )
return 0 ;
return F_54 ( 0 ) + 2 * F_54 ( sizeof( V_111 ) ) ;
#else
return 0 ;
#endif
}
static inline T_2
F_59 ( const struct V_22 * V_23 )
{
return F_60 ( sizeof( struct V_96 ) )
+ 3 * F_54 ( 0 )
+ 3 * F_54 ( 0 )
+ 3 * F_54 ( 0 )
+ 3 * F_54 ( sizeof( V_113 ) )
+ F_54 ( sizeof( V_114 ) )
+ F_54 ( sizeof( V_114 ) )
+ F_52 ( V_23 )
+ F_57 ( V_23 )
+ F_54 ( sizeof( V_114 ) )
+ F_54 ( 0 )
+ F_54 ( 0 )
+ F_54 ( V_115 )
+ F_55 ( V_23 )
#ifdef F_61
+ 2 * F_54 ( 0 )
+ 6 * F_54 ( sizeof( V_114 ) )
#endif
#ifdef F_62
+ F_54 ( sizeof( V_114 ) )
#endif
+ F_49 ( V_23 )
;
}
static int
F_63 ( unsigned int V_116 , struct V_117 * V_118 )
{
struct V_119 * V_119 ;
struct V_94 * V_95 ;
struct V_96 * V_97 ;
struct V_8 * V_9 ;
struct V_22 * V_23 = V_118 -> V_23 ;
struct V_1 * V_2 ;
unsigned int type ;
unsigned int V_98 = 0 , V_120 ;
int V_121 ;
if ( F_64 ( V_23 ) )
return 0 ;
if ( V_116 & ( 1 << V_122 ) ) {
type = V_123 ;
V_120 = V_124 ;
} else if ( V_116 & ( ( 1 << V_125 ) | ( 1 << V_126 ) ) ) {
type = V_127 ;
V_98 = V_128 | V_129 ;
V_120 = V_130 ;
} else if ( V_116 ) {
type = V_127 ;
V_120 = V_131 ;
} else
return 0 ;
V_119 = F_65 ( V_23 ) ;
if ( ! V_118 -> V_132 && ! F_66 ( V_119 , V_120 ) )
return 0 ;
V_2 = F_67 ( F_59 ( V_23 ) , V_133 ) ;
if ( V_2 == NULL )
goto V_134;
type |= V_100 << 8 ;
V_95 = F_41 ( V_2 , V_118 -> V_92 , 0 , type , sizeof( * V_97 ) , V_98 ) ;
if ( V_95 == NULL )
goto V_101;
V_97 = F_42 ( V_95 ) ;
V_97 -> V_102 = F_16 ( V_23 ) ;
V_97 -> V_103 = V_104 ;
V_97 -> V_105 = 0 ;
F_50 () ;
V_9 = F_2 ( V_2 , V_106 | V_11 ) ;
if ( ! V_9 )
goto V_12;
if ( F_7 ( V_2 , F_43 ( V_23 , V_84 ) ) < 0 )
goto V_12;
F_5 ( V_2 , V_9 ) ;
V_9 = F_2 ( V_2 , V_107 | V_11 ) ;
if ( ! V_9 )
goto V_12;
if ( F_7 ( V_2 , F_43 ( V_23 , V_86 ) ) < 0 )
goto V_12;
F_5 ( V_2 , V_9 ) ;
if ( F_44 ( V_23 ) )
F_45 ( V_2 , V_108 , F_46 ( F_44 ( V_23 ) ) ) ;
if ( F_37 ( V_2 , V_23 ) < 0 )
goto V_12;
if ( F_11 ( V_2 , V_23 ) < 0 )
goto V_12;
if ( V_116 & ( 1 << V_122 ) ) {
if ( F_22 ( V_2 , V_23 , V_84 ) < 0 ||
F_22 ( V_2 , V_23 , V_86 ) < 0 ||
F_26 ( V_2 , V_23 ) < 0 )
goto V_12;
} else {
if ( F_14 ( V_2 , V_23 ) < 0 )
goto V_12;
if ( V_116 & ( 1 << V_135 )
&& F_15 ( V_2 , V_23 ) < 0 )
goto V_12;
if ( ( V_116 & ( 1 << V_136 ) || F_19 ( V_23 ) )
&& F_18 ( V_2 , V_23 ) < 0 )
goto V_12;
#ifdef F_56
if ( ( V_116 & ( 1 << V_137 ) || V_23 -> V_67 )
&& F_29 ( V_2 , V_23 ) < 0 )
goto V_12;
#endif
if ( V_116 & ( 1 << V_126 ) &&
F_32 ( V_2 , V_23 ) < 0 )
goto V_12;
if ( V_116 & ( 1 << V_138 ) &&
F_35 ( V_2 , V_23 ) < 0 )
goto V_12;
}
#ifdef F_62
if ( ( V_116 & ( 1 << V_139 ) || V_23 -> V_63 )
&& F_28 ( V_2 , V_23 ) < 0 )
goto V_12;
#endif
F_51 () ;
F_47 ( V_2 , V_95 ) ;
V_121 = F_68 ( V_2 , V_119 , V_118 -> V_92 , V_120 , V_118 -> V_132 ,
V_133 ) ;
if ( V_121 == - V_140 || V_121 == - V_141 )
return - V_140 ;
return 0 ;
V_12:
F_51 () ;
F_48 ( V_2 , V_95 ) ;
V_101:
F_69 ( V_2 ) ;
V_134:
if ( F_70 ( V_119 , 0 , V_120 , - V_140 ) > 0 )
return - V_140 ;
return 0 ;
}
static int F_71 ( struct V_142 * V_143 )
{
if ( V_143 -> args [ 1 ] )
F_72 ( (struct V_22 * ) V_143 -> args [ 1 ] ) ;
return 0 ;
}
static int
F_73 ( struct V_1 * V_2 , struct V_142 * V_143 )
{
struct V_119 * V_119 = F_74 ( V_2 -> V_144 ) ;
struct V_22 * V_23 , * V_145 ;
struct V_146 * V_147 ;
struct V_148 * V_149 ;
struct V_96 * V_97 = F_42 ( V_143 -> V_95 ) ;
V_113 V_18 = V_97 -> V_102 ;
F_75 ( & V_150 ) ;
V_145 = (struct V_22 * ) V_143 -> args [ 1 ] ;
for (; V_143 -> args [ 0 ] < V_119 -> V_23 . V_151 ; V_143 -> args [ 0 ] ++ ) {
V_152:
F_76 (h, n, &net->ct.hash[cb->args[0]],
hnnode) {
if ( F_77 ( V_147 ) != V_84 )
continue;
V_23 = F_78 ( V_147 ) ;
if ( V_18 && F_16 ( V_23 ) != V_18 )
continue;
if ( V_143 -> args [ 1 ] ) {
if ( V_23 != V_145 )
continue;
V_143 -> args [ 1 ] = 0 ;
}
if ( F_40 ( V_2 , F_79 ( V_143 -> V_2 ) . V_92 ,
V_143 -> V_95 -> V_153 ,
V_127 , V_23 ) < 0 ) {
F_80 ( & V_23 -> V_90 ) ;
V_143 -> args [ 1 ] = ( unsigned long ) V_23 ;
goto V_39;
}
if ( F_81 ( V_143 -> V_95 -> V_154 ) ==
V_155 ) {
struct V_49 * V_50 ;
V_50 = F_23 ( V_23 ) ;
if ( V_50 )
memset ( V_50 , 0 , sizeof( struct V_49 [ V_156 ] ) ) ;
}
}
if ( V_143 -> args [ 1 ] ) {
V_143 -> args [ 1 ] = 0 ;
goto V_152;
}
}
V_39:
F_82 ( & V_150 ) ;
if ( V_145 )
F_72 ( V_145 ) ;
return V_2 -> V_65 ;
}
static inline int
F_83 ( struct V_8 * V_157 , struct V_3 * V_4 )
{
struct V_8 * V_158 [ V_159 + 1 ] ;
struct V_17 * V_18 ;
int V_7 = 0 ;
F_84 ( V_158 , V_159 , V_157 , NULL ) ;
F_50 () ;
V_18 = F_8 ( V_4 -> V_20 . V_21 ) ;
if ( F_4 ( V_18 -> V_160 ) ) {
V_7 = F_85 ( V_157 , V_159 ,
V_18 -> V_161 ) ;
if ( V_7 == 0 )
V_7 = V_18 -> V_160 ( V_158 , V_4 ) ;
}
F_51 () ;
return V_7 ;
}
static inline int
F_86 ( struct V_8 * V_157 ,
struct V_3 * V_4 )
{
struct V_8 * V_158 [ V_162 + 1 ] ;
struct V_5 * V_6 ;
int V_7 = 0 ;
V_7 = F_84 ( V_158 , V_162 , V_157 , V_163 ) ;
if ( V_7 < 0 )
return V_7 ;
if ( ! V_158 [ V_13 ] )
return - V_164 ;
V_4 -> V_14 . V_15 = F_87 ( V_158 [ V_13 ] ) ;
F_50 () ;
V_6 = F_10 ( V_4 -> V_20 . V_21 , V_4 -> V_14 . V_15 ) ;
if ( F_4 ( V_6 -> V_160 ) ) {
V_7 = F_85 ( V_157 , V_162 ,
V_6 -> V_161 ) ;
if ( V_7 == 0 )
V_7 = V_6 -> V_160 ( V_158 , V_4 ) ;
}
F_51 () ;
return V_7 ;
}
static int
F_88 ( const struct V_8 * const V_165 [] ,
struct V_3 * V_4 ,
enum V_45 type , V_113 V_21 )
{
struct V_8 * V_158 [ V_166 + 1 ] ;
int V_121 ;
memset ( V_4 , 0 , sizeof( * V_4 ) ) ;
F_84 ( V_158 , V_166 , V_165 [ type ] , V_167 ) ;
if ( ! V_158 [ V_19 ] )
return - V_164 ;
V_4 -> V_20 . V_21 = V_21 ;
V_121 = F_83 ( V_158 [ V_19 ] , V_4 ) ;
if ( V_121 < 0 )
return V_121 ;
if ( ! V_158 [ V_10 ] )
return - V_164 ;
V_121 = F_86 ( V_158 [ V_10 ] , V_4 ) ;
if ( V_121 < 0 )
return V_121 ;
if ( type == V_107 )
V_4 -> V_14 . V_44 = V_86 ;
else
V_4 -> V_14 . V_44 = V_84 ;
return 0 ;
}
static int
F_89 ( const struct V_8 * V_157 , T_3 * V_168 )
{
if ( V_157 )
#ifdef F_90
* V_168 = F_91 ( F_92 ( V_157 ) ) ;
#else
return - V_169 ;
#endif
else
* V_168 = 0 ;
return 0 ;
}
static inline int
F_93 ( const struct V_8 * V_157 , char * * V_170 )
{
struct V_8 * V_158 [ V_171 + 1 ] ;
F_84 ( V_158 , V_171 , V_157 , V_172 ) ;
if ( ! V_158 [ V_41 ] )
return - V_164 ;
* V_170 = F_94 ( V_158 [ V_41 ] ) ;
return 0 ;
}
static int
F_95 ( struct V_173 * V_174 , struct V_1 * V_2 ,
const struct V_94 * V_95 ,
const struct V_8 * const V_165 [] )
{
struct V_119 * V_119 = F_74 ( V_174 ) ;
struct V_146 * V_147 ;
struct V_3 V_4 ;
struct V_22 * V_23 ;
struct V_96 * V_97 = F_42 ( V_95 ) ;
V_113 V_175 = V_97 -> V_102 ;
T_3 V_168 ;
int V_121 ;
V_121 = F_89 ( V_165 [ V_108 ] , & V_168 ) ;
if ( V_121 < 0 )
return V_121 ;
if ( V_165 [ V_106 ] )
V_121 = F_88 ( V_165 , & V_4 , V_106 , V_175 ) ;
else if ( V_165 [ V_107 ] )
V_121 = F_88 ( V_165 , & V_4 , V_107 , V_175 ) ;
else {
F_96 ( V_119 ,
F_79 ( V_2 ) . V_92 ,
F_97 ( V_95 ) ) ;
return 0 ;
}
if ( V_121 < 0 )
return V_121 ;
V_147 = F_98 ( V_119 , V_168 , & V_4 ) ;
if ( ! V_147 )
return - V_176 ;
V_23 = F_78 ( V_147 ) ;
if ( V_165 [ V_88 ] ) {
V_114 V_177 = F_99 ( F_100 ( V_165 [ V_88 ] ) ) ;
if ( V_177 != ( T_1 ) ( unsigned long ) V_23 ) {
F_72 ( V_23 ) ;
return - V_176 ;
}
}
if ( F_101 ( V_122 , V_23 ,
F_79 ( V_2 ) . V_92 ,
F_97 ( V_95 ) ) < 0 ) {
F_102 ( V_23 ) ;
F_103 ( V_23 ) ;
F_72 ( V_23 ) ;
return 0 ;
}
F_104 ( V_178 , & V_23 -> V_25 ) ;
F_105 ( V_23 ) ;
F_72 ( V_23 ) ;
return 0 ;
}
static int
F_106 ( struct V_173 * V_174 , struct V_1 * V_2 ,
const struct V_94 * V_95 ,
const struct V_8 * const V_165 [] )
{
struct V_119 * V_119 = F_74 ( V_174 ) ;
struct V_146 * V_147 ;
struct V_3 V_4 ;
struct V_22 * V_23 ;
struct V_1 * V_179 = NULL ;
struct V_96 * V_97 = F_42 ( V_95 ) ;
V_113 V_175 = V_97 -> V_102 ;
T_3 V_168 ;
int V_121 ;
if ( V_95 -> V_180 & V_181 )
return F_107 ( V_174 , V_2 , V_95 , F_73 ,
F_71 ) ;
V_121 = F_89 ( V_165 [ V_108 ] , & V_168 ) ;
if ( V_121 < 0 )
return V_121 ;
if ( V_165 [ V_106 ] )
V_121 = F_88 ( V_165 , & V_4 , V_106 , V_175 ) ;
else if ( V_165 [ V_107 ] )
V_121 = F_88 ( V_165 , & V_4 , V_107 , V_175 ) ;
else
return - V_164 ;
if ( V_121 < 0 )
return V_121 ;
V_147 = F_98 ( V_119 , V_168 , & V_4 ) ;
if ( ! V_147 )
return - V_176 ;
V_23 = F_78 ( V_147 ) ;
V_121 = - V_182 ;
V_179 = F_67 ( V_183 , V_184 ) ;
if ( V_179 == NULL ) {
F_72 ( V_23 ) ;
return - V_182 ;
}
F_50 () ;
V_121 = F_40 ( V_179 , F_79 ( V_2 ) . V_92 , V_95 -> V_153 ,
V_127 , V_23 ) ;
F_51 () ;
F_72 ( V_23 ) ;
if ( V_121 <= 0 )
goto free;
V_121 = F_108 ( V_174 , V_179 , F_79 ( V_2 ) . V_92 , V_185 ) ;
if ( V_121 < 0 )
goto V_39;
return 0 ;
free:
F_69 ( V_179 ) ;
V_39:
return V_121 == - V_141 ? - V_140 : V_121 ;
}
static int
F_109 ( struct V_22 * V_23 ,
enum V_186 V_187 ,
const struct V_8 * V_157 )
{
F_110 (nfnetlink_parse_nat_setup_hook) V_188 ;
V_188 = F_20 ( V_189 ) ;
if ( ! V_188 ) {
#ifdef F_111
F_51 () ;
F_82 ( & V_150 ) ;
F_112 () ;
if ( F_113 ( L_1 ) < 0 ) {
F_114 () ;
F_75 ( & V_150 ) ;
F_50 () ;
return - V_169 ;
}
F_114 () ;
F_75 ( & V_150 ) ;
F_50 () ;
if ( V_189 )
return - V_141 ;
#endif
return - V_169 ;
}
return V_188 ( V_23 , V_187 , V_157 ) ;
}
static int
F_115 ( struct V_22 * V_23 , const struct V_8 * const V_165 [] )
{
unsigned long V_190 ;
unsigned int V_25 = F_99 ( F_100 ( V_165 [ V_24 ] ) ) ;
V_190 = V_23 -> V_25 ^ V_25 ;
if ( V_190 & ( V_70 | V_191 | V_192 ) )
return - V_193 ;
if ( V_190 & V_194 && ! ( V_25 & V_194 ) )
return - V_193 ;
if ( V_190 & V_195 && ! ( V_25 & V_195 ) )
return - V_193 ;
V_23 -> V_25 |= V_25 & ~ ( V_196 | V_197 ) ;
return 0 ;
}
static int
F_116 ( struct V_22 * V_23 , const struct V_8 * const V_165 [] )
{
#ifdef F_61
int V_7 ;
if ( V_165 [ V_198 ] ) {
V_7 = F_109 ( V_23 ,
V_199 ,
V_165 [ V_198 ] ) ;
if ( V_7 < 0 )
return V_7 ;
}
if ( V_165 [ V_200 ] ) {
V_7 = F_109 ( V_23 ,
V_201 ,
V_165 [ V_200 ] ) ;
if ( V_7 < 0 )
return V_7 ;
}
return 0 ;
#else
return - V_169 ;
#endif
}
static inline int
F_117 ( struct V_22 * V_23 , const struct V_8 * const V_165 [] )
{
struct V_37 * V_38 ;
struct V_35 * V_36 = F_19 ( V_23 ) ;
char * V_202 = NULL ;
int V_121 ;
if ( V_23 -> V_203 )
return - V_193 ;
V_121 = F_93 ( V_165 [ V_40 ] , & V_202 ) ;
if ( V_121 < 0 )
return V_121 ;
if ( ! strcmp ( V_202 , L_2 ) ) {
if ( V_36 && V_36 -> V_38 ) {
F_118 ( V_23 ) ;
F_119 ( V_36 -> V_38 , NULL ) ;
}
return 0 ;
}
V_38 = F_120 ( V_202 , F_16 ( V_23 ) ,
F_17 ( V_23 ) ) ;
if ( V_38 == NULL ) {
#ifdef F_111
F_82 ( & V_150 ) ;
if ( F_113 ( L_3 , V_202 ) < 0 ) {
F_75 ( & V_150 ) ;
return - V_169 ;
}
F_75 ( & V_150 ) ;
V_38 = F_120 ( V_202 , F_16 ( V_23 ) ,
F_17 ( V_23 ) ) ;
if ( V_38 )
return - V_141 ;
#endif
return - V_169 ;
}
if ( V_36 ) {
if ( V_36 -> V_38 == V_38 )
return 0 ;
if ( V_36 -> V_38 )
return - V_193 ;
memset ( & V_36 -> V_36 , 0 , sizeof( V_36 -> V_36 ) ) ;
} else {
return - V_169 ;
}
F_119 ( V_36 -> V_38 , V_38 ) ;
return 0 ;
}
static inline int
F_121 ( struct V_22 * V_23 , const struct V_8 * const V_165 [] )
{
V_114 V_26 = F_99 ( F_100 ( V_165 [ V_30 ] ) ) ;
if ( ! F_122 ( & V_23 -> V_26 ) )
return - V_204 ;
V_23 -> V_26 . V_27 = V_28 + V_26 * V_29 ;
F_123 ( & V_23 -> V_26 ) ;
return 0 ;
}
static inline int
F_124 ( struct V_22 * V_23 , const struct V_8 * const V_165 [] )
{
const struct V_8 * V_157 = V_165 [ V_33 ] ;
struct V_8 * V_158 [ V_205 + 1 ] ;
struct V_5 * V_6 ;
int V_121 = 0 ;
F_84 ( V_158 , V_205 , V_157 , V_206 ) ;
F_50 () ;
V_6 = F_10 ( F_16 ( V_23 ) , F_17 ( V_23 ) ) ;
if ( V_6 -> V_207 )
V_121 = V_6 -> V_207 ( V_158 , V_23 ) ;
F_51 () ;
return V_121 ;
}
static inline int
F_125 ( struct V_72 * V_73 , const struct V_8 * const V_157 )
{
struct V_8 * V_165 [ V_208 + 1 ] ;
F_84 ( V_165 , V_208 , V_157 , V_209 ) ;
if ( ! V_165 [ V_74 ] )
return - V_164 ;
V_73 -> V_75 =
F_99 ( F_100 ( V_165 [ V_74 ] ) ) ;
if ( ! V_165 [ V_76 ] )
return - V_164 ;
V_73 -> V_77 =
F_99 ( F_100 ( V_165 [ V_76 ] ) ) ;
if ( ! V_165 [ V_78 ] )
return - V_164 ;
V_73 -> V_79 =
F_99 ( F_100 ( V_165 [ V_78 ] ) ) ;
return 0 ;
}
static int
F_126 ( struct V_22 * V_23 ,
const struct V_8 * const V_165 [] )
{
int V_7 = 0 ;
struct V_80 * V_81 = F_36 ( V_23 ) ;
if ( ! V_81 )
return 0 ;
if ( V_165 [ V_85 ] ) {
V_7 = F_125 ( & V_81 -> V_83 [ V_84 ] ,
V_165 [ V_85 ] ) ;
if ( V_7 < 0 )
return V_7 ;
V_23 -> V_25 |= V_82 ;
}
if ( V_165 [ V_87 ] ) {
V_7 = F_125 ( & V_81 -> V_83 [ V_86 ] ,
V_165 [ V_87 ] ) ;
if ( V_7 < 0 )
return V_7 ;
V_23 -> V_25 |= V_82 ;
}
return 0 ;
}
static int
F_127 ( struct V_22 * V_23 ,
const struct V_8 * const V_165 [] )
{
int V_121 ;
if ( V_165 [ V_200 ] || V_165 [ V_198 ] || V_165 [ V_71 ] )
return - V_169 ;
if ( V_165 [ V_40 ] ) {
V_121 = F_117 ( V_23 , V_165 ) ;
if ( V_121 < 0 )
return V_121 ;
}
if ( V_165 [ V_30 ] ) {
V_121 = F_121 ( V_23 , V_165 ) ;
if ( V_121 < 0 )
return V_121 ;
}
if ( V_165 [ V_24 ] ) {
V_121 = F_115 ( V_23 , V_165 ) ;
if ( V_121 < 0 )
return V_121 ;
}
if ( V_165 [ V_33 ] ) {
V_121 = F_124 ( V_23 , V_165 ) ;
if ( V_121 < 0 )
return V_121 ;
}
#if F_128 ( F_62 )
if ( V_165 [ V_62 ] )
V_23 -> V_63 = F_99 ( F_100 ( V_165 [ V_62 ] ) ) ;
#endif
#ifdef F_61
if ( V_165 [ V_85 ] || V_165 [ V_87 ] ) {
V_121 = F_126 ( V_23 , V_165 ) ;
if ( V_121 < 0 )
return V_121 ;
}
#endif
return 0 ;
}
static struct V_22 *
F_129 ( struct V_119 * V_119 , T_3 V_168 ,
const struct V_8 * const V_165 [] ,
struct V_3 * V_210 ,
struct V_3 * V_211 ,
T_4 V_175 )
{
struct V_22 * V_23 ;
int V_121 = - V_164 ;
struct V_37 * V_38 ;
struct V_55 * V_56 ;
V_23 = F_130 ( V_119 , V_168 , V_210 , V_211 , V_133 ) ;
if ( F_131 ( V_23 ) )
return F_132 ( - V_182 ) ;
if ( ! V_165 [ V_30 ] )
goto V_212;
V_23 -> V_26 . V_27 = F_99 ( F_100 ( V_165 [ V_30 ] ) ) ;
V_23 -> V_26 . V_27 = V_28 + V_23 -> V_26 . V_27 * V_29 ;
F_50 () ;
if ( V_165 [ V_40 ] ) {
char * V_202 = NULL ;
V_121 = F_93 ( V_165 [ V_40 ] , & V_202 ) ;
if ( V_121 < 0 )
goto V_213;
V_38 = F_120 ( V_202 , F_16 ( V_23 ) ,
F_17 ( V_23 ) ) ;
if ( V_38 == NULL ) {
F_51 () ;
#ifdef F_111
if ( F_113 ( L_3 , V_202 ) < 0 ) {
V_121 = - V_169 ;
goto V_212;
}
F_50 () ;
V_38 = F_120 ( V_202 ,
F_16 ( V_23 ) ,
F_17 ( V_23 ) ) ;
if ( V_38 ) {
V_121 = - V_141 ;
goto V_213;
}
F_51 () ;
#endif
V_121 = - V_169 ;
goto V_212;
} else {
struct V_35 * V_36 ;
V_36 = F_133 ( V_23 , V_133 ) ;
if ( V_36 == NULL ) {
V_121 = - V_182 ;
goto V_213;
}
F_119 ( V_36 -> V_38 , V_38 ) ;
}
} else {
V_121 = F_134 ( V_23 , NULL , V_133 ) ;
if ( V_121 < 0 )
goto V_213;
}
if ( V_165 [ V_200 ] || V_165 [ V_198 ] ) {
V_121 = F_116 ( V_23 , V_165 ) ;
if ( V_121 < 0 )
goto V_213;
}
F_135 ( V_23 , V_133 ) ;
F_136 ( V_23 , V_133 ) ;
F_137 ( V_23 , 0 , 0 , V_133 ) ;
V_23 -> V_25 |= V_191 ;
if ( V_165 [ V_24 ] ) {
V_121 = F_115 ( V_23 , V_165 ) ;
if ( V_121 < 0 )
goto V_213;
}
#ifdef F_61
if ( V_165 [ V_85 ] || V_165 [ V_87 ] ) {
V_121 = F_126 ( V_23 , V_165 ) ;
if ( V_121 < 0 )
goto V_213;
}
#endif
memset ( & V_23 -> V_214 , 0 , sizeof( V_23 -> V_214 ) ) ;
if ( V_165 [ V_33 ] ) {
V_121 = F_124 ( V_23 , V_165 ) ;
if ( V_121 < 0 )
goto V_213;
}
#if F_128 ( F_62 )
if ( V_165 [ V_62 ] )
V_23 -> V_63 = F_99 ( F_100 ( V_165 [ V_62 ] ) ) ;
#endif
if ( V_165 [ V_71 ] ) {
struct V_3 V_203 ;
struct V_146 * V_215 ;
struct V_22 * V_216 ;
V_121 = F_88 ( V_165 , & V_203 , V_71 , V_175 ) ;
if ( V_121 < 0 )
goto V_213;
V_215 = F_98 ( V_119 , V_168 , & V_203 ) ;
if ( V_215 == NULL ) {
V_121 = - V_176 ;
goto V_213;
}
V_216 = F_78 ( V_215 ) ;
F_138 ( V_217 , & V_23 -> V_25 ) ;
V_23 -> V_203 = V_216 ;
}
V_56 = F_27 ( V_23 ) ;
if ( V_56 )
V_56 -> V_59 = F_139 ( F_140 () ) ;
F_123 ( & V_23 -> V_26 ) ;
F_141 ( V_23 ) ;
F_51 () ;
return V_23 ;
V_213:
F_51 () ;
V_212:
F_142 ( V_23 ) ;
return F_132 ( V_121 ) ;
}
static int
F_143 ( struct V_173 * V_174 , struct V_1 * V_2 ,
const struct V_94 * V_95 ,
const struct V_8 * const V_165 [] )
{
struct V_119 * V_119 = F_74 ( V_174 ) ;
struct V_3 V_210 , V_211 ;
struct V_146 * V_147 = NULL ;
struct V_96 * V_97 = F_42 ( V_95 ) ;
V_113 V_175 = V_97 -> V_102 ;
T_3 V_168 ;
int V_121 ;
V_121 = F_89 ( V_165 [ V_108 ] , & V_168 ) ;
if ( V_121 < 0 )
return V_121 ;
if ( V_165 [ V_106 ] ) {
V_121 = F_88 ( V_165 , & V_210 , V_106 , V_175 ) ;
if ( V_121 < 0 )
return V_121 ;
}
if ( V_165 [ V_107 ] ) {
V_121 = F_88 ( V_165 , & V_211 , V_107 , V_175 ) ;
if ( V_121 < 0 )
return V_121 ;
}
F_75 ( & V_150 ) ;
if ( V_165 [ V_106 ] )
V_147 = F_144 ( V_119 , V_168 , & V_210 ) ;
else if ( V_165 [ V_107 ] )
V_147 = F_144 ( V_119 , V_168 , & V_211 ) ;
if ( V_147 == NULL ) {
V_121 = - V_176 ;
if ( V_95 -> V_180 & V_128 ) {
struct V_22 * V_23 ;
enum V_218 V_116 ;
V_23 = F_129 ( V_119 , V_168 , V_165 , & V_210 ,
& V_211 , V_175 ) ;
if ( F_131 ( V_23 ) ) {
V_121 = F_145 ( V_23 ) ;
goto V_219;
}
V_121 = 0 ;
F_80 ( & V_23 -> V_90 ) ;
F_82 ( & V_150 ) ;
if ( F_146 ( V_217 , & V_23 -> V_25 ) )
V_116 = V_126 ;
else
V_116 = V_125 ;
F_147 ( ( 1 << V_220 ) |
( 1 << V_221 ) |
( 1 << V_136 ) |
( 1 << V_135 ) |
( 1 << V_138 ) |
( 1 << V_139 ) | V_116 ,
V_23 , F_79 ( V_2 ) . V_92 ,
F_97 ( V_95 ) ) ;
F_72 ( V_23 ) ;
} else
F_82 ( & V_150 ) ;
return V_121 ;
}
V_121 = - V_222 ;
if ( ! ( V_95 -> V_180 & V_129 ) ) {
struct V_22 * V_23 = F_78 ( V_147 ) ;
V_121 = F_127 ( V_23 , V_165 ) ;
if ( V_121 == 0 ) {
F_80 ( & V_23 -> V_90 ) ;
F_82 ( & V_150 ) ;
F_147 ( ( 1 << V_220 ) |
( 1 << V_221 ) |
( 1 << V_136 ) |
( 1 << V_135 ) |
( 1 << V_138 ) |
( 1 << V_139 ) ,
V_23 , F_79 ( V_2 ) . V_92 ,
F_97 ( V_95 ) ) ;
F_72 ( V_23 ) ;
} else
F_82 ( & V_150 ) ;
return V_121 ;
}
V_219:
F_82 ( & V_150 ) ;
return V_121 ;
}
static inline int
F_148 ( struct V_1 * V_2 ,
const struct V_3 * V_4 ,
enum V_223 type )
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
F_149 ( struct V_1 * V_2 ,
const struct V_3 * V_4 ,
const struct V_224 * V_225 )
{
int V_7 ;
struct V_17 * V_18 ;
struct V_5 * V_6 ;
struct V_3 V_226 ;
struct V_8 * V_9 ;
memset ( & V_226 , 0xFF , sizeof( V_226 ) ) ;
memcpy ( & V_226 . V_20 . V_175 , & V_225 -> V_20 . V_175 , sizeof( V_226 . V_20 . V_175 ) ) ;
V_226 . V_20 . V_227 . V_228 = V_225 -> V_20 . V_227 . V_228 ;
V_226 . V_14 . V_15 = V_4 -> V_14 . V_15 ;
V_9 = F_2 ( V_2 , V_229 | V_11 ) ;
if ( ! V_9 )
goto V_12;
V_18 = F_8 ( V_4 -> V_20 . V_21 ) ;
V_7 = F_6 ( V_2 , & V_226 , V_18 ) ;
if ( F_9 ( V_7 < 0 ) )
goto V_12;
V_6 = F_10 ( V_4 -> V_20 . V_21 , V_4 -> V_14 . V_15 ) ;
V_7 = F_1 ( V_2 , & V_226 , V_6 ) ;
if ( F_9 ( V_7 < 0 ) )
goto V_12;
F_5 ( V_2 , V_9 ) ;
return 0 ;
V_12:
return - 1 ;
}
static int
F_150 ( struct V_1 * V_2 ,
const struct V_230 * exp )
{
struct V_22 * V_203 = exp -> V_203 ;
long V_26 = ( exp -> V_26 . V_27 - V_28 ) / V_29 ;
struct V_35 * V_36 ;
if ( V_26 < 0 )
V_26 = 0 ;
if ( F_148 ( V_2 , & exp -> V_4 , V_231 ) < 0 )
goto V_12;
if ( F_149 ( V_2 , & exp -> V_4 , & exp -> V_225 ) < 0 )
goto V_12;
if ( F_148 ( V_2 ,
& V_203 -> V_232 [ V_84 ] . V_4 ,
V_233 ) < 0 )
goto V_12;
F_12 ( V_2 , V_234 , F_13 ( V_26 ) ) ;
F_12 ( V_2 , V_235 , F_13 ( ( unsigned long ) exp ) ) ;
F_12 ( V_2 , V_236 , F_13 ( exp -> V_98 ) ) ;
V_36 = F_19 ( V_203 ) ;
if ( V_36 ) {
struct V_37 * V_38 ;
V_38 = F_20 ( V_36 -> V_38 ) ;
if ( V_38 )
F_21 ( V_2 , V_237 , V_38 -> V_42 ) ;
}
return 0 ;
V_12:
return - 1 ;
}
static int
F_151 ( struct V_1 * V_2 , T_1 V_92 , T_1 V_83 ,
int V_93 , const struct V_230 * exp )
{
struct V_94 * V_95 ;
struct V_96 * V_97 ;
unsigned int V_98 = V_92 ? V_99 : 0 ;
V_93 |= V_238 << 8 ;
V_95 = F_41 ( V_2 , V_92 , V_83 , V_93 , sizeof( * V_97 ) , V_98 ) ;
if ( V_95 == NULL )
goto V_101;
V_97 = F_42 ( V_95 ) ;
V_97 -> V_102 = exp -> V_4 . V_20 . V_21 ;
V_97 -> V_103 = V_104 ;
V_97 -> V_105 = 0 ;
if ( F_150 ( V_2 , exp ) < 0 )
goto V_12;
F_47 ( V_2 , V_95 ) ;
return V_2 -> V_65 ;
V_101:
V_12:
F_48 ( V_2 , V_95 ) ;
return - 1 ;
}
static int
F_152 ( unsigned int V_116 , struct V_239 * V_118 )
{
struct V_230 * exp = V_118 -> exp ;
struct V_119 * V_119 = F_153 ( exp ) ;
struct V_94 * V_95 ;
struct V_96 * V_97 ;
struct V_1 * V_2 ;
unsigned int type , V_120 ;
int V_98 = 0 ;
if ( V_116 & ( 1 << V_240 ) ) {
type = V_241 ;
V_120 = V_242 ;
} else if ( V_116 & ( 1 << V_243 ) ) {
type = V_244 ;
V_98 = V_128 | V_129 ;
V_120 = V_245 ;
} else
return 0 ;
if ( ! V_118 -> V_132 && ! F_66 ( V_119 , V_120 ) )
return 0 ;
V_2 = F_67 ( V_183 , V_133 ) ;
if ( V_2 == NULL )
goto V_134;
type |= V_238 << 8 ;
V_95 = F_41 ( V_2 , V_118 -> V_92 , 0 , type , sizeof( * V_97 ) , V_98 ) ;
if ( V_95 == NULL )
goto V_101;
V_97 = F_42 ( V_95 ) ;
V_97 -> V_102 = exp -> V_4 . V_20 . V_21 ;
V_97 -> V_103 = V_104 ;
V_97 -> V_105 = 0 ;
F_50 () ;
if ( F_150 ( V_2 , exp ) < 0 )
goto V_12;
F_51 () ;
F_47 ( V_2 , V_95 ) ;
F_68 ( V_2 , V_119 , V_118 -> V_92 , V_120 , V_118 -> V_132 , V_133 ) ;
return 0 ;
V_12:
F_51 () ;
F_48 ( V_2 , V_95 ) ;
V_101:
F_69 ( V_2 ) ;
V_134:
F_70 ( V_119 , 0 , 0 , - V_140 ) ;
return 0 ;
}
static int F_154 ( struct V_142 * V_143 )
{
if ( V_143 -> args [ 1 ] )
F_155 ( (struct V_230 * ) V_143 -> args [ 1 ] ) ;
return 0 ;
}
static int
F_156 ( struct V_1 * V_2 , struct V_142 * V_143 )
{
struct V_119 * V_119 = F_74 ( V_2 -> V_144 ) ;
struct V_230 * exp , * V_145 ;
struct V_96 * V_97 = F_42 ( V_143 -> V_95 ) ;
struct V_246 * V_149 ;
V_113 V_18 = V_97 -> V_102 ;
F_50 () ;
V_145 = (struct V_230 * ) V_143 -> args [ 1 ] ;
for (; V_143 -> args [ 0 ] < V_247 ; V_143 -> args [ 0 ] ++ ) {
V_152:
F_157 (exp, n, &net->ct.expect_hash[cb->args[0]],
hnode) {
if ( V_18 && exp -> V_4 . V_20 . V_21 != V_18 )
continue;
if ( V_143 -> args [ 1 ] ) {
if ( exp != V_145 )
continue;
V_143 -> args [ 1 ] = 0 ;
}
if ( F_151 ( V_2 ,
F_79 ( V_143 -> V_2 ) . V_92 ,
V_143 -> V_95 -> V_153 ,
V_244 ,
exp ) < 0 ) {
if ( ! F_158 ( & exp -> V_91 ) )
continue;
V_143 -> args [ 1 ] = ( unsigned long ) exp ;
goto V_39;
}
}
if ( V_143 -> args [ 1 ] ) {
V_143 -> args [ 1 ] = 0 ;
goto V_152;
}
}
V_39:
F_51 () ;
if ( V_145 )
F_155 ( V_145 ) ;
return V_2 -> V_65 ;
}
static int
F_159 ( struct V_173 * V_174 , struct V_1 * V_2 ,
const struct V_94 * V_95 ,
const struct V_8 * const V_165 [] )
{
struct V_119 * V_119 = F_74 ( V_174 ) ;
struct V_3 V_4 ;
struct V_230 * exp ;
struct V_1 * V_179 ;
struct V_96 * V_97 = F_42 ( V_95 ) ;
V_113 V_175 = V_97 -> V_102 ;
T_3 V_168 ;
int V_121 ;
if ( V_95 -> V_180 & V_181 ) {
return F_107 ( V_174 , V_2 , V_95 ,
F_156 ,
F_154 ) ;
}
V_121 = F_89 ( V_165 [ V_248 ] , & V_168 ) ;
if ( V_121 < 0 )
return V_121 ;
if ( V_165 [ V_233 ] )
V_121 = F_88 ( V_165 , & V_4 , V_233 , V_175 ) ;
else
return - V_164 ;
if ( V_121 < 0 )
return V_121 ;
exp = F_160 ( V_119 , V_168 , & V_4 ) ;
if ( ! exp )
return - V_176 ;
if ( V_165 [ V_235 ] ) {
T_5 V_177 = F_100 ( V_165 [ V_235 ] ) ;
if ( F_99 ( V_177 ) != ( T_1 ) ( unsigned long ) exp ) {
F_155 ( exp ) ;
return - V_176 ;
}
}
V_121 = - V_182 ;
V_179 = F_67 ( V_183 , V_184 ) ;
if ( V_179 == NULL )
goto V_39;
F_50 () ;
V_121 = F_151 ( V_179 , F_79 ( V_2 ) . V_92 ,
V_95 -> V_153 , V_244 , exp ) ;
F_51 () ;
if ( V_121 <= 0 )
goto free;
F_155 ( exp ) ;
return F_108 ( V_174 , V_179 , F_79 ( V_2 ) . V_92 , V_185 ) ;
free:
F_69 ( V_179 ) ;
V_39:
F_155 ( exp ) ;
return V_121 ;
}
static int
F_161 ( struct V_173 * V_174 , struct V_1 * V_2 ,
const struct V_94 * V_95 ,
const struct V_8 * const V_165 [] )
{
struct V_119 * V_119 = F_74 ( V_174 ) ;
struct V_230 * exp ;
struct V_3 V_4 ;
struct V_96 * V_97 = F_42 ( V_95 ) ;
struct V_246 * V_149 , * V_249 ;
V_113 V_175 = V_97 -> V_102 ;
unsigned int V_250 ;
T_3 V_168 ;
int V_121 ;
if ( V_165 [ V_231 ] ) {
V_121 = F_89 ( V_165 [ V_248 ] , & V_168 ) ;
if ( V_121 < 0 )
return V_121 ;
V_121 = F_88 ( V_165 , & V_4 , V_231 , V_175 ) ;
if ( V_121 < 0 )
return V_121 ;
exp = F_160 ( V_119 , V_168 , & V_4 ) ;
if ( ! exp )
return - V_176 ;
if ( V_165 [ V_235 ] ) {
T_5 V_177 = F_100 ( V_165 [ V_235 ] ) ;
if ( F_99 ( V_177 ) != ( T_1 ) ( unsigned long ) exp ) {
F_155 ( exp ) ;
return - V_176 ;
}
}
F_75 ( & V_150 ) ;
if ( F_122 ( & exp -> V_26 ) ) {
F_162 ( exp , F_79 ( V_2 ) . V_92 ,
F_97 ( V_95 ) ) ;
F_155 ( exp ) ;
}
F_82 ( & V_150 ) ;
F_155 ( exp ) ;
} else if ( V_165 [ V_237 ] ) {
char * V_42 = F_94 ( V_165 [ V_237 ] ) ;
struct V_35 * V_251 ;
F_75 ( & V_150 ) ;
for ( V_250 = 0 ; V_250 < V_247 ; V_250 ++ ) {
F_163 (exp, n, next,
&net->ct.expect_hash[i],
hnode) {
V_251 = F_19 ( exp -> V_203 ) ;
if ( ! strcmp ( V_251 -> V_38 -> V_42 , V_42 ) &&
F_122 ( & exp -> V_26 ) ) {
F_162 ( exp ,
F_79 ( V_2 ) . V_92 ,
F_97 ( V_95 ) ) ;
F_155 ( exp ) ;
}
}
}
F_82 ( & V_150 ) ;
} else {
F_75 ( & V_150 ) ;
for ( V_250 = 0 ; V_250 < V_247 ; V_250 ++ ) {
F_163 (exp, n, next,
&net->ct.expect_hash[i],
hnode) {
if ( F_122 ( & exp -> V_26 ) ) {
F_162 ( exp ,
F_79 ( V_2 ) . V_92 ,
F_97 ( V_95 ) ) ;
F_155 ( exp ) ;
}
}
}
F_82 ( & V_150 ) ;
}
return 0 ;
}
static int
F_164 ( struct V_230 * V_252 ,
const struct V_8 * const V_165 [] )
{
return - V_169 ;
}
static int
F_165 ( struct V_119 * V_119 , T_3 V_168 ,
const struct V_8 * const V_165 [] ,
V_113 V_175 ,
T_1 V_92 , int V_132 )
{
struct V_3 V_4 , V_225 , F_33 ;
struct V_146 * V_147 = NULL ;
struct V_230 * exp ;
struct V_22 * V_23 ;
struct V_35 * V_36 ;
int V_121 = 0 ;
V_121 = F_88 ( V_165 , & V_4 , V_231 , V_175 ) ;
if ( V_121 < 0 )
return V_121 ;
V_121 = F_88 ( V_165 , & V_225 , V_229 , V_175 ) ;
if ( V_121 < 0 )
return V_121 ;
V_121 = F_88 ( V_165 , & F_33 , V_233 , V_175 ) ;
if ( V_121 < 0 )
return V_121 ;
V_147 = F_98 ( V_119 , V_168 , & F_33 ) ;
if ( ! V_147 )
return - V_176 ;
V_23 = F_78 ( V_147 ) ;
exp = F_166 ( V_23 ) ;
if ( ! exp ) {
V_121 = - V_182 ;
goto V_39;
}
V_36 = F_19 ( V_23 ) ;
if ( ! V_36 ) {
if ( ! V_165 [ V_234 ] ) {
V_121 = - V_164 ;
goto V_39;
}
exp -> V_26 . V_27 =
V_28 + F_99 ( F_100 ( V_165 [ V_234 ] ) ) * V_29 ;
exp -> V_98 = V_253 ;
if ( V_165 [ V_236 ] ) {
exp -> V_98 |=
F_99 ( F_100 ( V_165 [ V_236 ] ) ) ;
}
} else {
if ( V_165 [ V_236 ] ) {
exp -> V_98 = F_99 ( F_100 ( V_165 [ V_236 ] ) ) ;
exp -> V_98 &= ~ V_253 ;
} else
exp -> V_98 = 0 ;
}
exp -> V_254 = 0 ;
exp -> V_255 = NULL ;
exp -> V_203 = V_23 ;
exp -> V_38 = NULL ;
memcpy ( & exp -> V_4 , & V_4 , sizeof( struct V_3 ) ) ;
memcpy ( & exp -> V_225 . V_20 . V_175 , & V_225 . V_20 . V_175 , sizeof( exp -> V_225 . V_20 . V_175 ) ) ;
exp -> V_225 . V_20 . V_227 . V_228 = V_225 . V_20 . V_227 . V_228 ;
V_121 = F_167 ( exp , V_92 , V_132 ) ;
F_155 ( exp ) ;
V_39:
F_72 ( F_78 ( V_147 ) ) ;
return V_121 ;
}
static int
F_168 ( struct V_173 * V_174 , struct V_1 * V_2 ,
const struct V_94 * V_95 ,
const struct V_8 * const V_165 [] )
{
struct V_119 * V_119 = F_74 ( V_174 ) ;
struct V_3 V_4 ;
struct V_230 * exp ;
struct V_96 * V_97 = F_42 ( V_95 ) ;
V_113 V_175 = V_97 -> V_102 ;
T_3 V_168 ;
int V_121 ;
if ( ! V_165 [ V_231 ]
|| ! V_165 [ V_229 ]
|| ! V_165 [ V_233 ] )
return - V_164 ;
V_121 = F_89 ( V_165 [ V_248 ] , & V_168 ) ;
if ( V_121 < 0 )
return V_121 ;
V_121 = F_88 ( V_165 , & V_4 , V_231 , V_175 ) ;
if ( V_121 < 0 )
return V_121 ;
F_75 ( & V_150 ) ;
exp = F_169 ( V_119 , V_168 , & V_4 ) ;
if ( ! exp ) {
F_82 ( & V_150 ) ;
V_121 = - V_176 ;
if ( V_95 -> V_180 & V_128 ) {
V_121 = F_165 ( V_119 , V_168 , V_165 ,
V_175 ,
F_79 ( V_2 ) . V_92 ,
F_97 ( V_95 ) ) ;
}
return V_121 ;
}
V_121 = - V_222 ;
if ( ! ( V_95 -> V_180 & V_129 ) )
V_121 = F_164 ( exp , V_165 ) ;
F_82 ( & V_150 ) ;
return V_121 ;
}
static int T_6 F_170 ( void )
{
int V_7 ;
F_171 ( L_4 , V_103 ) ;
V_7 = F_172 ( & V_256 ) ;
if ( V_7 < 0 ) {
F_173 ( L_5 ) ;
goto V_257;
}
V_7 = F_172 ( & V_258 ) ;
if ( V_7 < 0 ) {
F_173 ( L_6 ) ;
goto V_259;
}
#ifdef F_174
V_7 = F_175 ( & V_260 ) ;
if ( V_7 < 0 ) {
F_173 ( L_7 ) ;
goto V_261;
}
V_7 = F_176 ( & V_262 ) ;
if ( V_7 < 0 ) {
F_173 ( L_8 ) ;
goto V_263;
}
#endif
return 0 ;
#ifdef F_174
V_263:
F_177 ( & V_260 ) ;
V_261:
F_178 ( & V_258 ) ;
#endif
V_259:
F_178 ( & V_256 ) ;
V_257:
return V_7 ;
}
static void T_7 F_179 ( void )
{
F_171 ( L_9 ) ;
F_180 () ;
#ifdef F_174
F_181 ( & V_262 ) ;
F_177 ( & V_260 ) ;
#endif
F_178 ( & V_258 ) ;
F_178 ( & V_256 ) ;
}
