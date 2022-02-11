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
long V_26 = ( ( long ) V_23 -> V_26 . V_27 - ( long ) V_28 ) / V_29 ;
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
F_22 ( struct V_1 * V_2 , T_1 V_43 , T_1 V_44 ,
enum V_45 V_46 )
{
enum V_47 type = V_46 ? V_48 : V_49 ;
struct V_8 * V_50 ;
V_50 = F_2 ( V_2 , type | V_11 ) ;
if ( ! V_50 )
goto V_12;
F_23 ( V_2 , V_51 , F_24 ( V_43 ) ) ;
F_23 ( V_2 , V_52 , F_24 ( V_44 ) ) ;
F_5 ( V_2 , V_50 ) ;
return 0 ;
V_12:
return - 1 ;
}
static int
F_25 ( struct V_1 * V_2 , const struct V_22 * V_23 ,
enum V_45 V_46 , int type )
{
struct V_53 * V_54 ;
T_1 V_43 , V_44 ;
V_54 = F_26 ( V_23 ) ;
if ( ! V_54 )
return 0 ;
if ( type == V_55 ) {
V_43 = F_27 ( & V_54 [ V_46 ] . V_56 , 0 ) ;
V_44 = F_27 ( & V_54 [ V_46 ] . V_44 , 0 ) ;
} else {
V_43 = F_28 ( & V_54 [ V_46 ] . V_56 ) ;
V_44 = F_28 ( & V_54 [ V_46 ] . V_44 ) ;
}
return F_22 ( V_2 , V_43 , V_44 , V_46 ) ;
}
static int
F_29 ( struct V_1 * V_2 , const struct V_22 * V_23 )
{
struct V_8 * V_50 ;
const struct V_57 * V_58 ;
V_58 = F_30 ( V_23 ) ;
if ( ! V_58 )
return 0 ;
V_50 = F_2 ( V_2 , V_59 | V_11 ) ;
if ( ! V_50 )
goto V_12;
F_23 ( V_2 , V_60 , F_24 ( V_58 -> V_61 ) ) ;
if ( V_58 -> V_62 != 0 ) {
F_23 ( V_2 , V_63 ,
F_24 ( V_58 -> V_62 ) ) ;
}
F_5 ( V_2 , V_50 ) ;
return 0 ;
V_12:
return - 1 ;
}
static inline int
F_31 ( struct V_1 * V_2 , const struct V_22 * V_23 )
{
F_12 ( V_2 , V_64 , F_13 ( V_23 -> V_65 ) ) ;
return 0 ;
V_12:
return - 1 ;
}
static inline int
F_32 ( struct V_1 * V_2 , const struct V_22 * V_23 )
{
struct V_8 * V_66 ;
int V_67 , V_7 ;
char * V_68 ;
V_7 = F_33 ( V_23 -> V_69 , & V_68 , & V_67 ) ;
if ( V_7 )
return 0 ;
V_7 = - 1 ;
V_66 = F_2 ( V_2 , V_70 | V_11 ) ;
if ( ! V_66 )
goto V_12;
F_21 ( V_2 , V_71 , V_68 ) ;
F_5 ( V_2 , V_66 ) ;
V_7 = 0 ;
V_12:
F_34 ( V_68 , V_67 ) ;
return V_7 ;
}
static inline int
F_35 ( struct V_1 * V_2 , const struct V_22 * V_23 )
{
struct V_8 * V_9 ;
if ( ! ( V_23 -> V_25 & V_72 ) )
return 0 ;
V_9 = F_2 ( V_2 , V_73 | V_11 ) ;
if ( ! V_9 )
goto V_12;
if ( F_7 ( V_2 , F_36 ( V_23 ) ) < 0 )
goto V_12;
F_5 ( V_2 , V_9 ) ;
return 0 ;
V_12:
return - 1 ;
}
static int
F_37 ( struct V_1 * V_2 , const struct V_74 * V_75 , int type )
{
struct V_8 * V_9 ;
V_9 = F_2 ( V_2 , type | V_11 ) ;
if ( ! V_9 )
goto V_12;
F_12 ( V_2 , V_76 ,
F_13 ( V_75 -> V_77 ) ) ;
F_12 ( V_2 , V_78 ,
F_13 ( V_75 -> V_79 ) ) ;
F_12 ( V_2 , V_80 ,
F_13 ( V_75 -> V_81 ) ) ;
F_5 ( V_2 , V_9 ) ;
return 0 ;
V_12:
return - 1 ;
}
static inline int
F_38 ( struct V_1 * V_2 , const struct V_22 * V_23 )
{
struct V_74 * V_75 ;
struct V_82 * V_83 = F_39 ( V_23 ) ;
if ( ! ( V_23 -> V_25 & V_84 ) || ! V_83 )
return 0 ;
V_75 = & V_83 -> V_85 [ V_86 ] ;
if ( F_37 ( V_2 , V_75 , V_87 ) == - 1 )
return - 1 ;
V_75 = & V_83 -> V_85 [ V_88 ] ;
if ( F_37 ( V_2 , V_75 , V_89 ) == - 1 )
return - 1 ;
return 0 ;
}
static inline int
F_40 ( struct V_1 * V_2 , const struct V_22 * V_23 )
{
F_12 ( V_2 , V_90 , F_13 ( ( unsigned long ) V_23 ) ) ;
return 0 ;
V_12:
return - 1 ;
}
static inline int
F_41 ( struct V_1 * V_2 , const struct V_22 * V_23 )
{
F_12 ( V_2 , V_91 , F_13 ( F_42 ( & V_23 -> V_92 . V_93 ) ) ) ;
return 0 ;
V_12:
return - 1 ;
}
static int
F_43 ( struct V_1 * V_2 , T_2 V_94 , T_2 V_85 , T_2 type ,
struct V_22 * V_23 )
{
struct V_95 * V_96 ;
struct V_97 * V_98 ;
struct V_8 * V_9 ;
unsigned int V_99 = V_94 ? V_100 : 0 , V_101 ;
V_101 = ( V_102 << 8 | V_103 ) ;
V_96 = F_44 ( V_2 , V_94 , V_85 , V_101 , sizeof( * V_98 ) , V_99 ) ;
if ( V_96 == NULL )
goto V_104;
V_98 = F_45 ( V_96 ) ;
V_98 -> V_105 = F_16 ( V_23 ) ;
V_98 -> V_106 = V_107 ;
V_98 -> V_108 = 0 ;
V_9 = F_2 ( V_2 , V_109 | V_11 ) ;
if ( ! V_9 )
goto V_12;
if ( F_7 ( V_2 , F_46 ( V_23 , V_86 ) ) < 0 )
goto V_12;
F_5 ( V_2 , V_9 ) ;
V_9 = F_2 ( V_2 , V_110 | V_11 ) ;
if ( ! V_9 )
goto V_12;
if ( F_7 ( V_2 , F_46 ( V_23 , V_88 ) ) < 0 )
goto V_12;
F_5 ( V_2 , V_9 ) ;
if ( F_47 ( V_23 ) )
F_48 ( V_2 , V_111 , F_49 ( F_47 ( V_23 ) ) ) ;
if ( F_11 ( V_2 , V_23 ) < 0 ||
F_14 ( V_2 , V_23 ) < 0 ||
F_25 ( V_2 , V_23 , V_86 , type ) < 0 ||
F_25 ( V_2 , V_23 , V_88 , type ) < 0 ||
F_29 ( V_2 , V_23 ) < 0 ||
F_15 ( V_2 , V_23 ) < 0 ||
F_18 ( V_2 , V_23 ) < 0 ||
F_31 ( V_2 , V_23 ) < 0 ||
F_32 ( V_2 , V_23 ) < 0 ||
F_40 ( V_2 , V_23 ) < 0 ||
F_41 ( V_2 , V_23 ) < 0 ||
F_35 ( V_2 , V_23 ) < 0 ||
F_38 ( V_2 , V_23 ) < 0 )
goto V_12;
F_50 ( V_2 , V_96 ) ;
return V_2 -> V_67 ;
V_104:
V_12:
F_51 ( V_2 , V_96 ) ;
return - 1 ;
}
static inline T_3
F_52 ( const struct V_22 * V_23 )
{
struct V_17 * V_18 ;
struct V_5 * V_6 ;
T_3 V_67 = 0 ;
F_53 () ;
V_18 = F_8 ( F_16 ( V_23 ) ) ;
V_67 += V_18 -> V_112 ;
V_6 = F_10 ( F_16 ( V_23 ) , F_17 ( V_23 ) ) ;
V_67 += V_6 -> V_112 ;
F_54 () ;
return V_67 ;
}
static inline T_3
F_55 ( const struct V_22 * V_23 )
{
if ( ! F_56 ( V_23 , V_113 ) )
return 0 ;
return 2 * F_57 ( 0 )
+ 2 * F_57 ( sizeof( V_114 ) )
+ 2 * F_57 ( sizeof( V_114 ) )
;
}
static inline int
F_58 ( const struct V_22 * V_23 )
{
#ifdef F_59
int V_67 , V_7 ;
V_7 = F_33 ( V_23 -> V_69 , NULL , & V_67 ) ;
if ( V_7 )
return 0 ;
return F_57 ( 0 )
+ F_57 ( sizeof( char ) * V_67 ) ;
#else
return 0 ;
#endif
}
static inline T_3
F_60 ( const struct V_22 * V_23 )
{
#ifdef F_61
if ( ! F_56 ( V_23 , V_115 ) )
return 0 ;
return F_57 ( 0 ) + 2 * F_57 ( sizeof( V_114 ) ) ;
#else
return 0 ;
#endif
}
static inline T_3
F_62 ( const struct V_22 * V_23 )
{
return F_63 ( sizeof( struct V_97 ) )
+ 3 * F_57 ( 0 )
+ 3 * F_57 ( 0 )
+ 3 * F_57 ( 0 )
+ 3 * F_57 ( sizeof( V_116 ) )
+ F_57 ( sizeof( V_117 ) )
+ F_57 ( sizeof( V_117 ) )
+ F_55 ( V_23 )
+ F_60 ( V_23 )
+ F_57 ( sizeof( V_117 ) )
+ F_57 ( 0 )
+ F_57 ( 0 )
+ F_57 ( V_118 )
+ F_58 ( V_23 )
#ifdef F_64
+ 2 * F_57 ( 0 )
+ 6 * F_57 ( sizeof( V_117 ) )
#endif
#ifdef F_65
+ F_57 ( sizeof( V_117 ) )
#endif
+ F_52 ( V_23 )
;
}
static int
F_66 ( unsigned int V_119 , struct V_120 * V_121 )
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
if ( F_67 ( V_23 ) )
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
V_122 = F_68 ( V_23 ) ;
if ( ! V_121 -> V_134 && ! F_69 ( V_122 , V_123 ) )
return 0 ;
V_2 = F_70 ( F_62 ( V_23 ) , V_135 ) ;
if ( V_2 == NULL )
goto V_136;
type |= V_102 << 8 ;
V_96 = F_44 ( V_2 , V_121 -> V_94 , 0 , type , sizeof( * V_98 ) , V_99 ) ;
if ( V_96 == NULL )
goto V_104;
V_98 = F_45 ( V_96 ) ;
V_98 -> V_105 = F_16 ( V_23 ) ;
V_98 -> V_106 = V_107 ;
V_98 -> V_108 = 0 ;
F_53 () ;
V_9 = F_2 ( V_2 , V_109 | V_11 ) ;
if ( ! V_9 )
goto V_12;
if ( F_7 ( V_2 , F_46 ( V_23 , V_86 ) ) < 0 )
goto V_12;
F_5 ( V_2 , V_9 ) ;
V_9 = F_2 ( V_2 , V_110 | V_11 ) ;
if ( ! V_9 )
goto V_12;
if ( F_7 ( V_2 , F_46 ( V_23 , V_88 ) ) < 0 )
goto V_12;
F_5 ( V_2 , V_9 ) ;
if ( F_47 ( V_23 ) )
F_48 ( V_2 , V_111 , F_49 ( F_47 ( V_23 ) ) ) ;
if ( F_40 ( V_2 , V_23 ) < 0 )
goto V_12;
if ( F_11 ( V_2 , V_23 ) < 0 )
goto V_12;
if ( V_119 & ( 1 << V_125 ) ) {
if ( F_25 ( V_2 , V_23 ,
V_86 , type ) < 0 ||
F_25 ( V_2 , V_23 ,
V_88 , type ) < 0 ||
F_29 ( V_2 , V_23 ) < 0 )
goto V_12;
} else {
if ( F_14 ( V_2 , V_23 ) < 0 )
goto V_12;
if ( V_119 & ( 1 << V_137 )
&& F_15 ( V_2 , V_23 ) < 0 )
goto V_12;
if ( ( V_119 & ( 1 << V_138 ) || F_19 ( V_23 ) )
&& F_18 ( V_2 , V_23 ) < 0 )
goto V_12;
#ifdef F_59
if ( ( V_119 & ( 1 << V_139 ) || V_23 -> V_69 )
&& F_32 ( V_2 , V_23 ) < 0 )
goto V_12;
#endif
if ( V_119 & ( 1 << V_129 ) &&
F_35 ( V_2 , V_23 ) < 0 )
goto V_12;
if ( V_119 & ( 1 << V_140 ) &&
F_38 ( V_2 , V_23 ) < 0 )
goto V_12;
}
#ifdef F_65
if ( ( V_119 & ( 1 << V_141 ) || V_23 -> V_65 )
&& F_31 ( V_2 , V_23 ) < 0 )
goto V_12;
#endif
F_54 () ;
F_50 ( V_2 , V_96 ) ;
V_124 = F_71 ( V_2 , V_122 , V_121 -> V_94 , V_123 , V_121 -> V_134 ,
V_135 ) ;
if ( V_124 == - V_142 || V_124 == - V_143 )
return - V_142 ;
return 0 ;
V_12:
F_54 () ;
F_51 ( V_2 , V_96 ) ;
V_104:
F_72 ( V_2 ) ;
V_136:
if ( F_73 ( V_122 , 0 , V_123 , - V_142 ) > 0 )
return - V_142 ;
return 0 ;
}
static int F_74 ( struct V_144 * V_145 )
{
if ( V_145 -> args [ 1 ] )
F_75 ( (struct V_22 * ) V_145 -> args [ 1 ] ) ;
return 0 ;
}
static int
F_76 ( struct V_1 * V_2 , struct V_144 * V_145 )
{
struct V_122 * V_122 = F_77 ( V_2 -> V_146 ) ;
struct V_22 * V_23 , * V_147 ;
struct V_148 * V_149 ;
struct V_150 * V_151 ;
struct V_97 * V_98 = F_45 ( V_145 -> V_96 ) ;
V_116 V_18 = V_98 -> V_105 ;
F_78 ( & V_152 ) ;
V_147 = (struct V_22 * ) V_145 -> args [ 1 ] ;
for (; V_145 -> args [ 0 ] < V_122 -> V_23 . V_153 ; V_145 -> args [ 0 ] ++ ) {
V_154:
F_79 (h, n, &net->ct.hash[cb->args[0]],
hnnode) {
if ( F_80 ( V_149 ) != V_86 )
continue;
V_23 = F_81 ( V_149 ) ;
if ( V_18 && F_16 ( V_23 ) != V_18 )
continue;
if ( V_145 -> args [ 1 ] ) {
if ( V_23 != V_147 )
continue;
V_145 -> args [ 1 ] = 0 ;
}
if ( F_43 ( V_2 , F_82 ( V_145 -> V_2 ) . V_94 ,
V_145 -> V_96 -> V_155 ,
F_83 (
V_145 -> V_96 -> V_156 ) ,
V_23 ) < 0 ) {
F_84 ( & V_23 -> V_92 ) ;
V_145 -> args [ 1 ] = ( unsigned long ) V_23 ;
goto V_39;
}
}
if ( V_145 -> args [ 1 ] ) {
V_145 -> args [ 1 ] = 0 ;
goto V_154;
}
}
V_39:
F_85 ( & V_152 ) ;
if ( V_147 )
F_75 ( V_147 ) ;
return V_2 -> V_67 ;
}
static inline int
F_86 ( struct V_8 * V_157 , struct V_3 * V_4 )
{
struct V_8 * V_158 [ V_159 + 1 ] ;
struct V_17 * V_18 ;
int V_7 = 0 ;
F_87 ( V_158 , V_159 , V_157 , NULL ) ;
F_53 () ;
V_18 = F_8 ( V_4 -> V_20 . V_21 ) ;
if ( F_4 ( V_18 -> V_160 ) ) {
V_7 = F_88 ( V_157 , V_159 ,
V_18 -> V_161 ) ;
if ( V_7 == 0 )
V_7 = V_18 -> V_160 ( V_158 , V_4 ) ;
}
F_54 () ;
return V_7 ;
}
static inline int
F_89 ( struct V_8 * V_157 ,
struct V_3 * V_4 )
{
struct V_8 * V_158 [ V_162 + 1 ] ;
struct V_5 * V_6 ;
int V_7 = 0 ;
V_7 = F_87 ( V_158 , V_162 , V_157 , V_163 ) ;
if ( V_7 < 0 )
return V_7 ;
if ( ! V_158 [ V_13 ] )
return - V_164 ;
V_4 -> V_14 . V_15 = F_90 ( V_158 [ V_13 ] ) ;
F_53 () ;
V_6 = F_10 ( V_4 -> V_20 . V_21 , V_4 -> V_14 . V_15 ) ;
if ( F_4 ( V_6 -> V_160 ) ) {
V_7 = F_88 ( V_157 , V_162 ,
V_6 -> V_161 ) ;
if ( V_7 == 0 )
V_7 = V_6 -> V_160 ( V_158 , V_4 ) ;
}
F_54 () ;
return V_7 ;
}
static int
F_91 ( const struct V_8 * const V_165 [] ,
struct V_3 * V_4 ,
enum V_47 type , V_116 V_21 )
{
struct V_8 * V_158 [ V_166 + 1 ] ;
int V_124 ;
memset ( V_4 , 0 , sizeof( * V_4 ) ) ;
F_87 ( V_158 , V_166 , V_165 [ type ] , V_167 ) ;
if ( ! V_158 [ V_19 ] )
return - V_164 ;
V_4 -> V_20 . V_21 = V_21 ;
V_124 = F_86 ( V_158 [ V_19 ] , V_4 ) ;
if ( V_124 < 0 )
return V_124 ;
if ( ! V_158 [ V_10 ] )
return - V_164 ;
V_124 = F_89 ( V_158 [ V_10 ] , V_4 ) ;
if ( V_124 < 0 )
return V_124 ;
if ( type == V_110 )
V_4 -> V_14 . V_46 = V_88 ;
else
V_4 -> V_14 . V_46 = V_86 ;
return 0 ;
}
static int
F_92 ( const struct V_8 * V_157 , T_4 * V_168 )
{
if ( V_157 )
#ifdef F_93
* V_168 = F_94 ( F_95 ( V_157 ) ) ;
#else
return - V_169 ;
#endif
else
* V_168 = 0 ;
return 0 ;
}
static inline int
F_96 ( const struct V_8 * V_157 , char * * V_170 )
{
struct V_8 * V_158 [ V_171 + 1 ] ;
F_87 ( V_158 , V_171 , V_157 , V_172 ) ;
if ( ! V_158 [ V_41 ] )
return - V_164 ;
* V_170 = F_97 ( V_158 [ V_41 ] ) ;
return 0 ;
}
static int
F_98 ( struct V_173 * V_174 , struct V_1 * V_2 ,
const struct V_95 * V_96 ,
const struct V_8 * const V_165 [] )
{
struct V_122 * V_122 = F_77 ( V_174 ) ;
struct V_148 * V_149 ;
struct V_3 V_4 ;
struct V_22 * V_23 ;
struct V_97 * V_98 = F_45 ( V_96 ) ;
V_116 V_175 = V_98 -> V_105 ;
T_4 V_168 ;
int V_124 ;
V_124 = F_92 ( V_165 [ V_111 ] , & V_168 ) ;
if ( V_124 < 0 )
return V_124 ;
if ( V_165 [ V_109 ] )
V_124 = F_91 ( V_165 , & V_4 , V_109 , V_175 ) ;
else if ( V_165 [ V_110 ] )
V_124 = F_91 ( V_165 , & V_4 , V_110 , V_175 ) ;
else {
F_99 ( V_122 ,
F_82 ( V_2 ) . V_94 ,
F_100 ( V_96 ) ) ;
return 0 ;
}
if ( V_124 < 0 )
return V_124 ;
V_149 = F_101 ( V_122 , V_168 , & V_4 ) ;
if ( ! V_149 )
return - V_176 ;
V_23 = F_81 ( V_149 ) ;
if ( V_165 [ V_90 ] ) {
V_117 V_177 = F_102 ( F_103 ( V_165 [ V_90 ] ) ) ;
if ( V_177 != ( T_2 ) ( unsigned long ) V_23 ) {
F_75 ( V_23 ) ;
return - V_176 ;
}
}
if ( F_104 ( & V_23 -> V_26 ) ) {
if ( F_105 ( V_125 , V_23 ,
F_82 ( V_2 ) . V_94 ,
F_100 ( V_96 ) ) < 0 ) {
F_106 ( V_23 ) ;
F_107 ( V_23 ) ;
F_75 ( V_23 ) ;
return 0 ;
}
F_108 ( V_178 , & V_23 -> V_25 ) ;
F_106 ( V_23 ) ;
F_75 ( V_23 ) ;
}
F_75 ( V_23 ) ;
return 0 ;
}
static int
F_109 ( struct V_173 * V_174 , struct V_1 * V_2 ,
const struct V_95 * V_96 ,
const struct V_8 * const V_165 [] )
{
struct V_122 * V_122 = F_77 ( V_174 ) ;
struct V_148 * V_149 ;
struct V_3 V_4 ;
struct V_22 * V_23 ;
struct V_1 * V_179 = NULL ;
struct V_97 * V_98 = F_45 ( V_96 ) ;
V_116 V_175 = V_98 -> V_105 ;
T_4 V_168 ;
int V_124 ;
if ( V_96 -> V_180 & V_181 )
return F_110 ( V_174 , V_2 , V_96 , F_76 ,
F_74 , 0 ) ;
V_124 = F_92 ( V_165 [ V_111 ] , & V_168 ) ;
if ( V_124 < 0 )
return V_124 ;
if ( V_165 [ V_109 ] )
V_124 = F_91 ( V_165 , & V_4 , V_109 , V_175 ) ;
else if ( V_165 [ V_110 ] )
V_124 = F_91 ( V_165 , & V_4 , V_110 , V_175 ) ;
else
return - V_164 ;
if ( V_124 < 0 )
return V_124 ;
V_149 = F_101 ( V_122 , V_168 , & V_4 ) ;
if ( ! V_149 )
return - V_176 ;
V_23 = F_81 ( V_149 ) ;
V_124 = - V_182 ;
V_179 = F_70 ( V_183 , V_184 ) ;
if ( V_179 == NULL ) {
F_75 ( V_23 ) ;
return - V_182 ;
}
F_53 () ;
V_124 = F_43 ( V_179 , F_82 ( V_2 ) . V_94 , V_96 -> V_155 ,
F_83 ( V_96 -> V_156 ) , V_23 ) ;
F_54 () ;
F_75 ( V_23 ) ;
if ( V_124 <= 0 )
goto free;
V_124 = F_111 ( V_174 , V_179 , F_82 ( V_2 ) . V_94 , V_185 ) ;
if ( V_124 < 0 )
goto V_39;
return 0 ;
free:
F_72 ( V_179 ) ;
V_39:
return V_124 == - V_143 ? - V_142 : V_124 ;
}
static int
F_112 ( struct V_22 * V_23 ,
enum V_186 V_187 ,
const struct V_8 * V_157 )
{
F_113 (nfnetlink_parse_nat_setup_hook) V_188 ;
V_188 = F_20 ( V_189 ) ;
if ( ! V_188 ) {
#ifdef F_114
F_54 () ;
F_115 () ;
if ( F_116 ( L_1 ) < 0 ) {
F_117 () ;
F_53 () ;
return - V_169 ;
}
F_117 () ;
F_53 () ;
if ( V_189 )
return - V_143 ;
#endif
return - V_169 ;
}
return V_188 ( V_23 , V_187 , V_157 ) ;
}
static int
F_118 ( struct V_22 * V_23 , const struct V_8 * const V_165 [] )
{
unsigned long V_190 ;
unsigned int V_25 = F_102 ( F_103 ( V_165 [ V_24 ] ) ) ;
V_190 = V_23 -> V_25 ^ V_25 ;
if ( V_190 & ( V_72 | V_191 | V_192 ) )
return - V_193 ;
if ( V_190 & V_194 && ! ( V_25 & V_194 ) )
return - V_193 ;
if ( V_190 & V_195 && ! ( V_25 & V_195 ) )
return - V_193 ;
V_23 -> V_25 |= V_25 & ~ ( V_196 | V_197 ) ;
return 0 ;
}
static int
F_119 ( struct V_22 * V_23 , const struct V_8 * const V_165 [] )
{
#ifdef F_64
int V_7 ;
if ( V_165 [ V_198 ] ) {
V_7 = F_112 ( V_23 ,
V_199 ,
V_165 [ V_198 ] ) ;
if ( V_7 < 0 )
return V_7 ;
}
if ( V_165 [ V_200 ] ) {
V_7 = F_112 ( V_23 ,
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
F_120 ( struct V_22 * V_23 , const struct V_8 * const V_165 [] )
{
struct V_37 * V_38 ;
struct V_35 * V_36 = F_19 ( V_23 ) ;
char * V_202 = NULL ;
int V_124 ;
if ( V_23 -> V_203 )
return - V_193 ;
V_124 = F_96 ( V_165 [ V_40 ] , & V_202 ) ;
if ( V_124 < 0 )
return V_124 ;
if ( ! strcmp ( V_202 , L_2 ) ) {
if ( V_36 && V_36 -> V_38 ) {
F_121 ( V_23 ) ;
F_122 ( V_36 -> V_38 , NULL ) ;
}
return 0 ;
}
V_38 = F_123 ( V_202 , F_16 ( V_23 ) ,
F_17 ( V_23 ) ) ;
if ( V_38 == NULL ) {
#ifdef F_114
F_85 ( & V_152 ) ;
if ( F_116 ( L_3 , V_202 ) < 0 ) {
F_78 ( & V_152 ) ;
return - V_169 ;
}
F_78 ( & V_152 ) ;
V_38 = F_123 ( V_202 , F_16 ( V_23 ) ,
F_17 ( V_23 ) ) ;
if ( V_38 )
return - V_143 ;
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
F_124 ( V_36 -> V_38 , V_38 ) ;
return 0 ;
}
static inline int
F_125 ( struct V_22 * V_23 , const struct V_8 * const V_165 [] )
{
V_117 V_26 = F_102 ( F_103 ( V_165 [ V_30 ] ) ) ;
if ( ! F_104 ( & V_23 -> V_26 ) )
return - V_204 ;
V_23 -> V_26 . V_27 = V_28 + V_26 * V_29 ;
F_126 ( & V_23 -> V_26 ) ;
return 0 ;
}
static inline int
F_127 ( struct V_22 * V_23 , const struct V_8 * const V_165 [] )
{
const struct V_8 * V_157 = V_165 [ V_33 ] ;
struct V_8 * V_158 [ V_205 + 1 ] ;
struct V_5 * V_6 ;
int V_124 = 0 ;
F_87 ( V_158 , V_205 , V_157 , V_206 ) ;
F_53 () ;
V_6 = F_10 ( F_16 ( V_23 ) , F_17 ( V_23 ) ) ;
if ( V_6 -> V_207 )
V_124 = V_6 -> V_207 ( V_158 , V_23 ) ;
F_54 () ;
return V_124 ;
}
static inline int
F_128 ( struct V_74 * V_75 , const struct V_8 * const V_157 )
{
struct V_8 * V_165 [ V_208 + 1 ] ;
F_87 ( V_165 , V_208 , V_157 , V_209 ) ;
if ( ! V_165 [ V_76 ] )
return - V_164 ;
V_75 -> V_77 =
F_102 ( F_103 ( V_165 [ V_76 ] ) ) ;
if ( ! V_165 [ V_78 ] )
return - V_164 ;
V_75 -> V_79 =
F_102 ( F_103 ( V_165 [ V_78 ] ) ) ;
if ( ! V_165 [ V_80 ] )
return - V_164 ;
V_75 -> V_81 =
F_102 ( F_103 ( V_165 [ V_80 ] ) ) ;
return 0 ;
}
static int
F_129 ( struct V_22 * V_23 ,
const struct V_8 * const V_165 [] )
{
int V_7 = 0 ;
struct V_82 * V_83 = F_39 ( V_23 ) ;
if ( ! V_83 )
return 0 ;
if ( V_165 [ V_87 ] ) {
V_7 = F_128 ( & V_83 -> V_85 [ V_86 ] ,
V_165 [ V_87 ] ) ;
if ( V_7 < 0 )
return V_7 ;
V_23 -> V_25 |= V_84 ;
}
if ( V_165 [ V_89 ] ) {
V_7 = F_128 ( & V_83 -> V_85 [ V_88 ] ,
V_165 [ V_89 ] ) ;
if ( V_7 < 0 )
return V_7 ;
V_23 -> V_25 |= V_84 ;
}
return 0 ;
}
static int
F_130 ( struct V_22 * V_23 ,
const struct V_8 * const V_165 [] )
{
int V_124 ;
if ( V_165 [ V_200 ] || V_165 [ V_198 ] || V_165 [ V_73 ] )
return - V_169 ;
if ( V_165 [ V_40 ] ) {
V_124 = F_120 ( V_23 , V_165 ) ;
if ( V_124 < 0 )
return V_124 ;
}
if ( V_165 [ V_30 ] ) {
V_124 = F_125 ( V_23 , V_165 ) ;
if ( V_124 < 0 )
return V_124 ;
}
if ( V_165 [ V_24 ] ) {
V_124 = F_118 ( V_23 , V_165 ) ;
if ( V_124 < 0 )
return V_124 ;
}
if ( V_165 [ V_33 ] ) {
V_124 = F_127 ( V_23 , V_165 ) ;
if ( V_124 < 0 )
return V_124 ;
}
#if F_131 ( F_65 )
if ( V_165 [ V_64 ] )
V_23 -> V_65 = F_102 ( F_103 ( V_165 [ V_64 ] ) ) ;
#endif
#ifdef F_64
if ( V_165 [ V_87 ] || V_165 [ V_89 ] ) {
V_124 = F_129 ( V_23 , V_165 ) ;
if ( V_124 < 0 )
return V_124 ;
}
#endif
return 0 ;
}
static struct V_22 *
F_132 ( struct V_122 * V_122 , T_4 V_168 ,
const struct V_8 * const V_165 [] ,
struct V_3 * V_210 ,
struct V_3 * V_211 ,
T_5 V_175 )
{
struct V_22 * V_23 ;
int V_124 = - V_164 ;
struct V_37 * V_38 ;
struct V_57 * V_58 ;
V_23 = F_133 ( V_122 , V_168 , V_210 , V_211 , V_135 ) ;
if ( F_134 ( V_23 ) )
return F_135 ( - V_182 ) ;
if ( ! V_165 [ V_30 ] )
goto V_212;
V_23 -> V_26 . V_27 = F_102 ( F_103 ( V_165 [ V_30 ] ) ) ;
V_23 -> V_26 . V_27 = V_28 + V_23 -> V_26 . V_27 * V_29 ;
F_53 () ;
if ( V_165 [ V_40 ] ) {
char * V_202 = NULL ;
V_124 = F_96 ( V_165 [ V_40 ] , & V_202 ) ;
if ( V_124 < 0 )
goto V_213;
V_38 = F_123 ( V_202 , F_16 ( V_23 ) ,
F_17 ( V_23 ) ) ;
if ( V_38 == NULL ) {
F_54 () ;
#ifdef F_114
if ( F_116 ( L_3 , V_202 ) < 0 ) {
V_124 = - V_169 ;
goto V_212;
}
F_53 () ;
V_38 = F_123 ( V_202 ,
F_16 ( V_23 ) ,
F_17 ( V_23 ) ) ;
if ( V_38 ) {
V_124 = - V_143 ;
goto V_213;
}
F_54 () ;
#endif
V_124 = - V_169 ;
goto V_212;
} else {
struct V_35 * V_36 ;
V_36 = F_136 ( V_23 , V_135 ) ;
if ( V_36 == NULL ) {
V_124 = - V_182 ;
goto V_213;
}
F_122 ( V_36 -> V_38 , V_38 ) ;
}
} else {
V_124 = F_137 ( V_23 , NULL , V_135 ) ;
if ( V_124 < 0 )
goto V_213;
}
if ( V_165 [ V_200 ] || V_165 [ V_198 ] ) {
V_124 = F_119 ( V_23 , V_165 ) ;
if ( V_124 < 0 )
goto V_213;
}
F_138 ( V_23 , V_135 ) ;
F_139 ( V_23 , V_135 ) ;
F_140 ( V_23 , 0 , 0 , V_135 ) ;
V_23 -> V_25 |= V_191 ;
if ( V_165 [ V_24 ] ) {
V_124 = F_118 ( V_23 , V_165 ) ;
if ( V_124 < 0 )
goto V_213;
}
#ifdef F_64
if ( V_165 [ V_87 ] || V_165 [ V_89 ] ) {
V_124 = F_129 ( V_23 , V_165 ) ;
if ( V_124 < 0 )
goto V_213;
}
#endif
memset ( & V_23 -> V_214 , 0 , sizeof( V_23 -> V_214 ) ) ;
if ( V_165 [ V_33 ] ) {
V_124 = F_127 ( V_23 , V_165 ) ;
if ( V_124 < 0 )
goto V_213;
}
#if F_131 ( F_65 )
if ( V_165 [ V_64 ] )
V_23 -> V_65 = F_102 ( F_103 ( V_165 [ V_64 ] ) ) ;
#endif
if ( V_165 [ V_73 ] ) {
struct V_3 V_203 ;
struct V_148 * V_215 ;
struct V_22 * V_216 ;
V_124 = F_91 ( V_165 , & V_203 , V_73 , V_175 ) ;
if ( V_124 < 0 )
goto V_213;
V_215 = F_101 ( V_122 , V_168 , & V_203 ) ;
if ( V_215 == NULL ) {
V_124 = - V_176 ;
goto V_213;
}
V_216 = F_81 ( V_215 ) ;
F_141 ( V_217 , & V_23 -> V_25 ) ;
V_23 -> V_203 = V_216 ;
}
V_58 = F_30 ( V_23 ) ;
if ( V_58 )
V_58 -> V_61 = F_142 ( F_143 () ) ;
V_124 = F_144 ( V_23 ) ;
if ( V_124 < 0 )
goto V_213;
F_54 () ;
return V_23 ;
V_213:
F_54 () ;
V_212:
F_145 ( V_23 ) ;
return F_135 ( V_124 ) ;
}
static int
F_146 ( struct V_173 * V_174 , struct V_1 * V_2 ,
const struct V_95 * V_96 ,
const struct V_8 * const V_165 [] )
{
struct V_122 * V_122 = F_77 ( V_174 ) ;
struct V_3 V_210 , V_211 ;
struct V_148 * V_149 = NULL ;
struct V_97 * V_98 = F_45 ( V_96 ) ;
struct V_22 * V_23 ;
V_116 V_175 = V_98 -> V_105 ;
T_4 V_168 ;
int V_124 ;
V_124 = F_92 ( V_165 [ V_111 ] , & V_168 ) ;
if ( V_124 < 0 )
return V_124 ;
if ( V_165 [ V_109 ] ) {
V_124 = F_91 ( V_165 , & V_210 , V_109 , V_175 ) ;
if ( V_124 < 0 )
return V_124 ;
}
if ( V_165 [ V_110 ] ) {
V_124 = F_91 ( V_165 , & V_211 , V_110 , V_175 ) ;
if ( V_124 < 0 )
return V_124 ;
}
if ( V_165 [ V_109 ] )
V_149 = F_101 ( V_122 , V_168 , & V_210 ) ;
else if ( V_165 [ V_110 ] )
V_149 = F_101 ( V_122 , V_168 , & V_211 ) ;
if ( V_149 == NULL ) {
V_124 = - V_176 ;
if ( V_96 -> V_180 & V_130 ) {
enum V_218 V_119 ;
V_23 = F_132 ( V_122 , V_168 , V_165 , & V_210 ,
& V_211 , V_175 ) ;
if ( F_134 ( V_23 ) )
return F_147 ( V_23 ) ;
V_124 = 0 ;
if ( F_148 ( V_217 , & V_23 -> V_25 ) )
V_119 = V_129 ;
else
V_119 = V_128 ;
F_149 ( ( 1 << V_219 ) |
( 1 << V_220 ) |
( 1 << V_138 ) |
( 1 << V_137 ) |
( 1 << V_140 ) |
( 1 << V_141 ) | V_119 ,
V_23 , F_82 ( V_2 ) . V_94 ,
F_100 ( V_96 ) ) ;
F_75 ( V_23 ) ;
}
return V_124 ;
}
V_124 = - V_221 ;
V_23 = F_81 ( V_149 ) ;
if ( ! ( V_96 -> V_180 & V_131 ) ) {
F_78 ( & V_152 ) ;
V_124 = F_130 ( V_23 , V_165 ) ;
F_85 ( & V_152 ) ;
if ( V_124 == 0 ) {
F_149 ( ( 1 << V_219 ) |
( 1 << V_220 ) |
( 1 << V_138 ) |
( 1 << V_137 ) |
( 1 << V_140 ) |
( 1 << V_141 ) ,
V_23 , F_82 ( V_2 ) . V_94 ,
F_100 ( V_96 ) ) ;
}
}
F_75 ( V_23 ) ;
return V_124 ;
}
static inline int
F_150 ( struct V_1 * V_2 ,
const struct V_3 * V_4 ,
enum V_222 type )
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
F_151 ( struct V_1 * V_2 ,
const struct V_3 * V_4 ,
const struct V_223 * V_224 )
{
int V_7 ;
struct V_17 * V_18 ;
struct V_5 * V_6 ;
struct V_3 V_225 ;
struct V_8 * V_9 ;
memset ( & V_225 , 0xFF , sizeof( V_225 ) ) ;
memcpy ( & V_225 . V_20 . V_175 , & V_224 -> V_20 . V_175 , sizeof( V_225 . V_20 . V_175 ) ) ;
V_225 . V_20 . V_226 . V_227 = V_224 -> V_20 . V_226 . V_227 ;
V_225 . V_14 . V_15 = V_4 -> V_14 . V_15 ;
V_9 = F_2 ( V_2 , V_228 | V_11 ) ;
if ( ! V_9 )
goto V_12;
V_18 = F_8 ( V_4 -> V_20 . V_21 ) ;
V_7 = F_6 ( V_2 , & V_225 , V_18 ) ;
if ( F_9 ( V_7 < 0 ) )
goto V_12;
V_6 = F_10 ( V_4 -> V_20 . V_21 , V_4 -> V_14 . V_15 ) ;
V_7 = F_1 ( V_2 , & V_225 , V_6 ) ;
if ( F_9 ( V_7 < 0 ) )
goto V_12;
F_5 ( V_2 , V_9 ) ;
return 0 ;
V_12:
return - 1 ;
}
static int
F_152 ( struct V_1 * V_2 ,
const struct V_229 * exp )
{
struct V_22 * V_203 = exp -> V_203 ;
long V_26 = ( ( long ) exp -> V_26 . V_27 - ( long ) V_28 ) / V_29 ;
struct V_35 * V_36 ;
if ( V_26 < 0 )
V_26 = 0 ;
if ( F_150 ( V_2 , & exp -> V_4 , V_230 ) < 0 )
goto V_12;
if ( F_151 ( V_2 , & exp -> V_4 , & exp -> V_224 ) < 0 )
goto V_12;
if ( F_150 ( V_2 ,
& V_203 -> V_231 [ V_86 ] . V_4 ,
V_232 ) < 0 )
goto V_12;
F_12 ( V_2 , V_233 , F_13 ( V_26 ) ) ;
F_12 ( V_2 , V_234 , F_13 ( ( unsigned long ) exp ) ) ;
F_12 ( V_2 , V_235 , F_13 ( exp -> V_99 ) ) ;
V_36 = F_19 ( V_203 ) ;
if ( V_36 ) {
struct V_37 * V_38 ;
V_38 = F_20 ( V_36 -> V_38 ) ;
if ( V_38 )
F_21 ( V_2 , V_236 , V_38 -> V_42 ) ;
}
return 0 ;
V_12:
return - 1 ;
}
static int
F_153 ( struct V_1 * V_2 , T_2 V_94 , T_2 V_85 ,
int V_101 , const struct V_229 * exp )
{
struct V_95 * V_96 ;
struct V_97 * V_98 ;
unsigned int V_99 = V_94 ? V_100 : 0 ;
V_101 |= V_237 << 8 ;
V_96 = F_44 ( V_2 , V_94 , V_85 , V_101 , sizeof( * V_98 ) , V_99 ) ;
if ( V_96 == NULL )
goto V_104;
V_98 = F_45 ( V_96 ) ;
V_98 -> V_105 = exp -> V_4 . V_20 . V_21 ;
V_98 -> V_106 = V_107 ;
V_98 -> V_108 = 0 ;
if ( F_152 ( V_2 , exp ) < 0 )
goto V_12;
F_50 ( V_2 , V_96 ) ;
return V_2 -> V_67 ;
V_104:
V_12:
F_51 ( V_2 , V_96 ) ;
return - 1 ;
}
static int
F_154 ( unsigned int V_119 , struct V_238 * V_121 )
{
struct V_229 * exp = V_121 -> exp ;
struct V_122 * V_122 = F_155 ( exp ) ;
struct V_95 * V_96 ;
struct V_97 * V_98 ;
struct V_1 * V_2 ;
unsigned int type , V_123 ;
int V_99 = 0 ;
if ( V_119 & ( 1 << V_239 ) ) {
type = V_240 ;
V_123 = V_241 ;
} else if ( V_119 & ( 1 << V_242 ) ) {
type = V_243 ;
V_99 = V_130 | V_131 ;
V_123 = V_244 ;
} else
return 0 ;
if ( ! V_121 -> V_134 && ! F_69 ( V_122 , V_123 ) )
return 0 ;
V_2 = F_70 ( V_183 , V_135 ) ;
if ( V_2 == NULL )
goto V_136;
type |= V_237 << 8 ;
V_96 = F_44 ( V_2 , V_121 -> V_94 , 0 , type , sizeof( * V_98 ) , V_99 ) ;
if ( V_96 == NULL )
goto V_104;
V_98 = F_45 ( V_96 ) ;
V_98 -> V_105 = exp -> V_4 . V_20 . V_21 ;
V_98 -> V_106 = V_107 ;
V_98 -> V_108 = 0 ;
F_53 () ;
if ( F_152 ( V_2 , exp ) < 0 )
goto V_12;
F_54 () ;
F_50 ( V_2 , V_96 ) ;
F_71 ( V_2 , V_122 , V_121 -> V_94 , V_123 , V_121 -> V_134 , V_135 ) ;
return 0 ;
V_12:
F_54 () ;
F_51 ( V_2 , V_96 ) ;
V_104:
F_72 ( V_2 ) ;
V_136:
F_73 ( V_122 , 0 , 0 , - V_142 ) ;
return 0 ;
}
static int F_156 ( struct V_144 * V_145 )
{
if ( V_145 -> args [ 1 ] )
F_157 ( (struct V_229 * ) V_145 -> args [ 1 ] ) ;
return 0 ;
}
static int
F_158 ( struct V_1 * V_2 , struct V_144 * V_145 )
{
struct V_122 * V_122 = F_77 ( V_2 -> V_146 ) ;
struct V_229 * exp , * V_147 ;
struct V_97 * V_98 = F_45 ( V_145 -> V_96 ) ;
struct V_245 * V_151 ;
V_116 V_18 = V_98 -> V_105 ;
F_53 () ;
V_147 = (struct V_229 * ) V_145 -> args [ 1 ] ;
for (; V_145 -> args [ 0 ] < V_246 ; V_145 -> args [ 0 ] ++ ) {
V_154:
F_159 (exp, n, &net->ct.expect_hash[cb->args[0]],
hnode) {
if ( V_18 && exp -> V_4 . V_20 . V_21 != V_18 )
continue;
if ( V_145 -> args [ 1 ] ) {
if ( exp != V_147 )
continue;
V_145 -> args [ 1 ] = 0 ;
}
if ( F_153 ( V_2 ,
F_82 ( V_145 -> V_2 ) . V_94 ,
V_145 -> V_96 -> V_155 ,
V_243 ,
exp ) < 0 ) {
if ( ! F_160 ( & exp -> V_93 ) )
continue;
V_145 -> args [ 1 ] = ( unsigned long ) exp ;
goto V_39;
}
}
if ( V_145 -> args [ 1 ] ) {
V_145 -> args [ 1 ] = 0 ;
goto V_154;
}
}
V_39:
F_54 () ;
if ( V_147 )
F_157 ( V_147 ) ;
return V_2 -> V_67 ;
}
static int
F_161 ( struct V_173 * V_174 , struct V_1 * V_2 ,
const struct V_95 * V_96 ,
const struct V_8 * const V_165 [] )
{
struct V_122 * V_122 = F_77 ( V_174 ) ;
struct V_3 V_4 ;
struct V_229 * exp ;
struct V_1 * V_179 ;
struct V_97 * V_98 = F_45 ( V_96 ) ;
V_116 V_175 = V_98 -> V_105 ;
T_4 V_168 ;
int V_124 ;
if ( V_96 -> V_180 & V_181 ) {
return F_110 ( V_174 , V_2 , V_96 ,
F_158 ,
F_156 , 0 ) ;
}
V_124 = F_92 ( V_165 [ V_247 ] , & V_168 ) ;
if ( V_124 < 0 )
return V_124 ;
if ( V_165 [ V_230 ] )
V_124 = F_91 ( V_165 , & V_4 , V_230 , V_175 ) ;
else if ( V_165 [ V_232 ] )
V_124 = F_91 ( V_165 , & V_4 , V_232 , V_175 ) ;
else
return - V_164 ;
if ( V_124 < 0 )
return V_124 ;
exp = F_162 ( V_122 , V_168 , & V_4 ) ;
if ( ! exp )
return - V_176 ;
if ( V_165 [ V_234 ] ) {
T_6 V_177 = F_103 ( V_165 [ V_234 ] ) ;
if ( F_102 ( V_177 ) != ( T_2 ) ( unsigned long ) exp ) {
F_157 ( exp ) ;
return - V_176 ;
}
}
V_124 = - V_182 ;
V_179 = F_70 ( V_183 , V_184 ) ;
if ( V_179 == NULL ) {
F_157 ( exp ) ;
goto V_39;
}
F_53 () ;
V_124 = F_153 ( V_179 , F_82 ( V_2 ) . V_94 ,
V_96 -> V_155 , V_243 , exp ) ;
F_54 () ;
F_157 ( exp ) ;
if ( V_124 <= 0 )
goto free;
V_124 = F_111 ( V_174 , V_179 , F_82 ( V_2 ) . V_94 , V_185 ) ;
if ( V_124 < 0 )
goto V_39;
return 0 ;
free:
F_72 ( V_179 ) ;
V_39:
return V_124 == - V_143 ? - V_142 : V_124 ;
}
static int
F_163 ( struct V_173 * V_174 , struct V_1 * V_2 ,
const struct V_95 * V_96 ,
const struct V_8 * const V_165 [] )
{
struct V_122 * V_122 = F_77 ( V_174 ) ;
struct V_229 * exp ;
struct V_3 V_4 ;
struct V_97 * V_98 = F_45 ( V_96 ) ;
struct V_245 * V_151 , * V_248 ;
V_116 V_175 = V_98 -> V_105 ;
unsigned int V_249 ;
T_4 V_168 ;
int V_124 ;
if ( V_165 [ V_230 ] ) {
V_124 = F_92 ( V_165 [ V_247 ] , & V_168 ) ;
if ( V_124 < 0 )
return V_124 ;
V_124 = F_91 ( V_165 , & V_4 , V_230 , V_175 ) ;
if ( V_124 < 0 )
return V_124 ;
exp = F_162 ( V_122 , V_168 , & V_4 ) ;
if ( ! exp )
return - V_176 ;
if ( V_165 [ V_234 ] ) {
T_6 V_177 = F_103 ( V_165 [ V_234 ] ) ;
if ( F_102 ( V_177 ) != ( T_2 ) ( unsigned long ) exp ) {
F_157 ( exp ) ;
return - V_176 ;
}
}
F_78 ( & V_152 ) ;
if ( F_104 ( & exp -> V_26 ) ) {
F_164 ( exp , F_82 ( V_2 ) . V_94 ,
F_100 ( V_96 ) ) ;
F_157 ( exp ) ;
}
F_85 ( & V_152 ) ;
F_157 ( exp ) ;
} else if ( V_165 [ V_236 ] ) {
char * V_42 = F_97 ( V_165 [ V_236 ] ) ;
struct V_35 * V_250 ;
F_78 ( & V_152 ) ;
for ( V_249 = 0 ; V_249 < V_246 ; V_249 ++ ) {
F_165 (exp, n, next,
&net->ct.expect_hash[i],
hnode) {
V_250 = F_19 ( exp -> V_203 ) ;
if ( ! strcmp ( V_250 -> V_38 -> V_42 , V_42 ) &&
F_104 ( & exp -> V_26 ) ) {
F_164 ( exp ,
F_82 ( V_2 ) . V_94 ,
F_100 ( V_96 ) ) ;
F_157 ( exp ) ;
}
}
}
F_85 ( & V_152 ) ;
} else {
F_78 ( & V_152 ) ;
for ( V_249 = 0 ; V_249 < V_246 ; V_249 ++ ) {
F_165 (exp, n, next,
&net->ct.expect_hash[i],
hnode) {
if ( F_104 ( & exp -> V_26 ) ) {
F_164 ( exp ,
F_82 ( V_2 ) . V_94 ,
F_100 ( V_96 ) ) ;
F_157 ( exp ) ;
}
}
}
F_85 ( & V_152 ) ;
}
return 0 ;
}
static int
F_166 ( struct V_229 * V_251 ,
const struct V_8 * const V_165 [] )
{
return - V_169 ;
}
static int
F_167 ( struct V_122 * V_122 , T_4 V_168 ,
const struct V_8 * const V_165 [] ,
V_116 V_175 ,
T_2 V_94 , int V_134 )
{
struct V_3 V_4 , V_224 , F_36 ;
struct V_148 * V_149 = NULL ;
struct V_229 * exp ;
struct V_22 * V_23 ;
struct V_35 * V_36 ;
int V_124 = 0 ;
V_124 = F_91 ( V_165 , & V_4 , V_230 , V_175 ) ;
if ( V_124 < 0 )
return V_124 ;
V_124 = F_91 ( V_165 , & V_224 , V_228 , V_175 ) ;
if ( V_124 < 0 )
return V_124 ;
V_124 = F_91 ( V_165 , & F_36 , V_232 , V_175 ) ;
if ( V_124 < 0 )
return V_124 ;
V_149 = F_101 ( V_122 , V_168 , & F_36 ) ;
if ( ! V_149 )
return - V_176 ;
V_23 = F_81 ( V_149 ) ;
exp = F_168 ( V_23 ) ;
if ( ! exp ) {
V_124 = - V_182 ;
goto V_39;
}
V_36 = F_19 ( V_23 ) ;
if ( ! V_36 ) {
if ( ! V_165 [ V_233 ] ) {
V_124 = - V_164 ;
goto V_39;
}
exp -> V_26 . V_27 =
V_28 + F_102 ( F_103 ( V_165 [ V_233 ] ) ) * V_29 ;
exp -> V_99 = V_252 ;
if ( V_165 [ V_235 ] ) {
exp -> V_99 |=
F_102 ( F_103 ( V_165 [ V_235 ] ) ) ;
}
} else {
if ( V_165 [ V_235 ] ) {
exp -> V_99 = F_102 ( F_103 ( V_165 [ V_235 ] ) ) ;
exp -> V_99 &= ~ V_252 ;
} else
exp -> V_99 = 0 ;
}
exp -> V_253 = 0 ;
exp -> V_254 = NULL ;
exp -> V_203 = V_23 ;
exp -> V_38 = NULL ;
memcpy ( & exp -> V_4 , & V_4 , sizeof( struct V_3 ) ) ;
memcpy ( & exp -> V_224 . V_20 . V_175 , & V_224 . V_20 . V_175 , sizeof( exp -> V_224 . V_20 . V_175 ) ) ;
exp -> V_224 . V_20 . V_226 . V_227 = V_224 . V_20 . V_226 . V_227 ;
V_124 = F_169 ( exp , V_94 , V_134 ) ;
F_157 ( exp ) ;
V_39:
F_75 ( F_81 ( V_149 ) ) ;
return V_124 ;
}
static int
F_170 ( struct V_173 * V_174 , struct V_1 * V_2 ,
const struct V_95 * V_96 ,
const struct V_8 * const V_165 [] )
{
struct V_122 * V_122 = F_77 ( V_174 ) ;
struct V_3 V_4 ;
struct V_229 * exp ;
struct V_97 * V_98 = F_45 ( V_96 ) ;
V_116 V_175 = V_98 -> V_105 ;
T_4 V_168 ;
int V_124 ;
if ( ! V_165 [ V_230 ]
|| ! V_165 [ V_228 ]
|| ! V_165 [ V_232 ] )
return - V_164 ;
V_124 = F_92 ( V_165 [ V_247 ] , & V_168 ) ;
if ( V_124 < 0 )
return V_124 ;
V_124 = F_91 ( V_165 , & V_4 , V_230 , V_175 ) ;
if ( V_124 < 0 )
return V_124 ;
F_78 ( & V_152 ) ;
exp = F_171 ( V_122 , V_168 , & V_4 ) ;
if ( ! exp ) {
F_85 ( & V_152 ) ;
V_124 = - V_176 ;
if ( V_96 -> V_180 & V_130 ) {
V_124 = F_167 ( V_122 , V_168 , V_165 ,
V_175 ,
F_82 ( V_2 ) . V_94 ,
F_100 ( V_96 ) ) ;
}
return V_124 ;
}
V_124 = - V_221 ;
if ( ! ( V_96 -> V_180 & V_131 ) )
V_124 = F_166 ( exp , V_165 ) ;
F_85 ( & V_152 ) ;
return V_124 ;
}
static int T_7 F_172 ( struct V_122 * V_122 )
{
#ifdef F_173
int V_7 ;
V_7 = F_174 ( V_122 , & V_255 ) ;
if ( V_7 < 0 ) {
F_175 ( L_4 ) ;
goto V_256;
}
V_7 = F_176 ( V_122 , & V_257 ) ;
if ( V_7 < 0 ) {
F_175 ( L_5 ) ;
goto V_258;
}
#endif
return 0 ;
#ifdef F_173
V_258:
F_177 ( V_122 , & V_255 ) ;
V_256:
return V_7 ;
#endif
}
static void F_178 ( struct V_122 * V_122 )
{
#ifdef F_173
F_179 ( V_122 , & V_257 ) ;
F_177 ( V_122 , & V_255 ) ;
#endif
}
static void T_8 F_180 ( struct V_259 * V_260 )
{
struct V_122 * V_122 ;
F_181 (net, net_exit_list, exit_list)
F_178 ( V_122 ) ;
}
static int T_9 F_182 ( void )
{
int V_7 ;
F_183 ( L_6 , V_106 ) ;
V_7 = F_184 ( & V_261 ) ;
if ( V_7 < 0 ) {
F_175 ( L_7 ) ;
goto V_256;
}
V_7 = F_184 ( & V_262 ) ;
if ( V_7 < 0 ) {
F_175 ( L_8 ) ;
goto V_263;
}
if ( F_185 ( & V_264 ) ) {
F_175 ( L_9 ) ;
goto V_265;
}
return 0 ;
V_265:
F_186 ( & V_262 ) ;
V_263:
F_186 ( & V_261 ) ;
V_256:
return V_7 ;
}
static void T_10 F_187 ( void )
{
F_183 ( L_10 ) ;
F_188 ( & V_264 ) ;
F_186 ( & V_262 ) ;
F_186 ( & V_261 ) ;
}
