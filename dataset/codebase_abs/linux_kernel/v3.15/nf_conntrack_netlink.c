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
+ F_58 ( V_23 )
+ F_36 ( V_23 )
;
}
static int
F_69 ( unsigned int V_127 , struct V_128 * V_129 )
{
struct V_130 * V_130 ;
struct V_103 * V_104 ;
struct V_105 * V_106 ;
struct V_8 * V_9 ;
struct V_22 * V_23 = V_129 -> V_23 ;
struct V_1 * V_2 ;
unsigned int type ;
unsigned int V_107 = 0 , V_131 ;
int V_132 ;
if ( F_70 ( V_23 ) )
return 0 ;
if ( V_127 & ( 1 << V_133 ) ) {
type = V_134 ;
V_131 = V_135 ;
} else if ( V_127 & ( ( 1 << V_136 ) | ( 1 << V_137 ) ) ) {
type = V_111 ;
V_107 = V_138 | V_139 ;
V_131 = V_140 ;
} else if ( V_127 ) {
type = V_111 ;
V_131 = V_141 ;
} else
return 0 ;
V_130 = F_71 ( V_23 ) ;
if ( ! V_129 -> V_142 && ! F_72 ( V_130 , V_131 ) )
return 0 ;
V_2 = F_73 ( F_65 ( V_23 ) , V_143 ) ;
if ( V_2 == NULL )
goto V_144;
type |= V_110 << 8 ;
V_104 = F_50 ( V_2 , V_129 -> V_102 , 0 , type , sizeof( * V_106 ) , V_107 ) ;
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
if ( V_127 & ( 1 << V_133 ) ) {
if ( F_28 ( V_2 , V_23 , type ) < 0 ||
F_30 ( V_2 , V_23 ) < 0 )
goto V_12;
} else {
if ( F_15 ( V_2 , V_23 ) < 0 )
goto V_12;
if ( V_127 & ( 1 << V_145 )
&& F_16 ( V_2 , V_23 ) < 0 )
goto V_12;
if ( ( V_127 & ( 1 << V_146 ) || F_20 ( V_23 ) )
&& F_19 ( V_2 , V_23 ) < 0 )
goto V_12;
#ifdef F_62
if ( ( V_127 & ( 1 << V_147 ) || V_23 -> V_74 )
&& F_33 ( V_2 , V_23 ) < 0 )
goto V_12;
#endif
if ( V_127 & ( 1 << V_148 ) &&
F_39 ( V_2 , V_23 ) < 0 )
goto V_12;
if ( V_127 & ( 1 << V_137 ) &&
F_41 ( V_2 , V_23 ) < 0 )
goto V_12;
if ( V_127 & ( 1 << V_149 ) &&
F_44 ( V_2 , V_23 ) < 0 )
goto V_12;
}
#ifdef F_68
if ( ( V_127 & ( 1 << V_150 ) || V_23 -> V_70 )
&& F_32 ( V_2 , V_23 ) < 0 )
goto V_12;
#endif
F_11 () ;
F_56 ( V_2 , V_104 ) ;
V_132 = F_74 ( V_2 , V_130 , V_129 -> V_102 , V_131 , V_129 -> V_142 ,
V_143 ) ;
if ( V_132 == - V_151 || V_132 == - V_152 )
return - V_151 ;
return 0 ;
V_12:
F_11 () ;
F_57 ( V_2 , V_104 ) ;
V_112:
F_75 ( V_2 ) ;
V_144:
if ( F_76 ( V_130 , 0 , V_131 , - V_151 ) > 0 )
return - V_151 ;
return 0 ;
}
static int F_77 ( struct V_153 * V_154 )
{
if ( V_154 -> args [ 1 ] )
F_78 ( (struct V_22 * ) V_154 -> args [ 1 ] ) ;
if ( V_154 -> V_155 )
F_79 ( V_154 -> V_155 ) ;
return 0 ;
}
static int
F_80 ( struct V_1 * V_2 , struct V_153 * V_154 )
{
struct V_130 * V_130 = F_81 ( V_2 -> V_156 ) ;
struct V_22 * V_23 , * V_157 ;
struct V_158 * V_159 ;
struct V_160 * V_161 ;
struct V_105 * V_106 = F_51 ( V_154 -> V_104 ) ;
V_124 V_18 = V_106 -> V_113 ;
int V_162 ;
T_4 * V_163 ;
#ifdef F_68
const struct V_164 * V_165 = V_154 -> V_155 ;
#endif
V_157 = (struct V_22 * ) V_154 -> args [ 1 ] ;
F_82 () ;
for (; V_154 -> args [ 0 ] < V_130 -> V_23 . V_166 ; V_154 -> args [ 0 ] ++ ) {
V_167:
V_163 = & V_168 [ V_154 -> args [ 0 ] % V_169 ] ;
F_83 ( V_163 ) ;
if ( V_154 -> args [ 0 ] >= V_130 -> V_23 . V_166 ) {
F_84 ( V_163 ) ;
goto V_39;
}
F_85 (h, n, &net->ct.hash[cb->args[0]],
hnnode) {
if ( F_86 ( V_159 ) != V_60 )
continue;
V_23 = F_87 ( V_159 ) ;
if ( V_18 && F_17 ( V_23 ) != V_18 )
continue;
if ( V_154 -> args [ 1 ] ) {
if ( V_23 != V_157 )
continue;
V_154 -> args [ 1 ] = 0 ;
}
#ifdef F_68
if ( V_165 && ! ( ( V_23 -> V_70 & V_165 -> V_70 . V_170 ) ==
V_165 -> V_70 . V_171 ) ) {
continue;
}
#endif
F_8 () ;
V_162 =
F_49 ( V_2 , F_88 ( V_154 -> V_2 ) . V_102 ,
V_154 -> V_104 -> V_172 ,
F_89 ( V_154 -> V_104 -> V_173 ) ,
V_23 ) ;
F_11 () ;
if ( V_162 < 0 ) {
F_90 ( & V_23 -> V_100 ) ;
V_154 -> args [ 1 ] = ( unsigned long ) V_23 ;
F_84 ( V_163 ) ;
goto V_39;
}
}
F_84 ( V_163 ) ;
if ( V_154 -> args [ 1 ] ) {
V_154 -> args [ 1 ] = 0 ;
goto V_167;
}
}
V_39:
F_91 () ;
if ( V_157 )
F_78 ( V_157 ) ;
return V_2 -> V_72 ;
}
static inline int
F_92 ( struct V_8 * V_48 , struct V_3 * V_4 )
{
struct V_8 * V_174 [ V_175 + 1 ] ;
struct V_17 * V_18 ;
int V_7 = 0 ;
V_7 = F_93 ( V_174 , V_175 , V_48 , NULL ) ;
if ( V_7 < 0 )
return V_7 ;
F_8 () ;
V_18 = F_9 ( V_4 -> V_20 . V_21 ) ;
if ( F_4 ( V_18 -> V_176 ) ) {
V_7 = F_94 ( V_48 , V_175 ,
V_18 -> V_177 ) ;
if ( V_7 == 0 )
V_7 = V_18 -> V_176 ( V_174 , V_4 ) ;
}
F_11 () ;
return V_7 ;
}
static inline int
F_95 ( struct V_8 * V_48 ,
struct V_3 * V_4 )
{
struct V_8 * V_174 [ V_178 + 1 ] ;
struct V_5 * V_6 ;
int V_7 = 0 ;
V_7 = F_93 ( V_174 , V_178 , V_48 , V_179 ) ;
if ( V_7 < 0 )
return V_7 ;
if ( ! V_174 [ V_13 ] )
return - V_180 ;
V_4 -> V_14 . V_15 = F_96 ( V_174 [ V_13 ] ) ;
F_8 () ;
V_6 = F_10 ( V_4 -> V_20 . V_21 , V_4 -> V_14 . V_15 ) ;
if ( F_4 ( V_6 -> V_176 ) ) {
V_7 = F_94 ( V_48 , V_178 ,
V_6 -> V_177 ) ;
if ( V_7 == 0 )
V_7 = V_6 -> V_176 ( V_174 , V_4 ) ;
}
F_11 () ;
return V_7 ;
}
static int
F_97 ( const struct V_8 * const V_181 [] ,
struct V_3 * V_4 ,
enum V_47 type , V_124 V_21 )
{
struct V_8 * V_174 [ V_182 + 1 ] ;
int V_132 ;
memset ( V_4 , 0 , sizeof( * V_4 ) ) ;
V_132 = F_93 ( V_174 , V_182 , V_181 [ type ] , V_183 ) ;
if ( V_132 < 0 )
return V_132 ;
if ( ! V_174 [ V_19 ] )
return - V_180 ;
V_4 -> V_20 . V_21 = V_21 ;
V_132 = F_92 ( V_174 [ V_19 ] , V_4 ) ;
if ( V_132 < 0 )
return V_132 ;
if ( ! V_174 [ V_10 ] )
return - V_180 ;
V_132 = F_95 ( V_174 [ V_10 ] , V_4 ) ;
if ( V_132 < 0 )
return V_132 ;
if ( type == V_118 )
V_4 -> V_14 . V_46 = V_61 ;
else
V_4 -> V_14 . V_46 = V_60 ;
return 0 ;
}
static int
F_98 ( const struct V_8 * V_48 , T_5 * V_184 )
{
if ( V_48 )
#ifdef F_99
* V_184 = F_100 ( F_101 ( V_48 ) ) ;
#else
return - V_185 ;
#endif
else
* V_184 = 0 ;
return 0 ;
}
static inline int
F_102 ( const struct V_8 * V_48 , char * * V_186 ,
struct V_8 * * V_187 )
{
int V_132 ;
struct V_8 * V_174 [ V_188 + 1 ] ;
V_132 = F_93 ( V_174 , V_188 , V_48 , V_189 ) ;
if ( V_132 < 0 )
return V_132 ;
if ( ! V_174 [ V_41 ] )
return - V_180 ;
* V_186 = F_103 ( V_174 [ V_41 ] ) ;
if ( V_174 [ V_190 ] )
* V_187 = V_174 [ V_190 ] ;
return 0 ;
}
static int
F_104 ( struct V_191 * V_192 , struct V_1 * V_2 ,
const struct V_103 * V_104 ,
const struct V_8 * const V_181 [] )
{
struct V_130 * V_130 = F_81 ( V_192 ) ;
struct V_158 * V_159 ;
struct V_3 V_4 ;
struct V_22 * V_23 ;
struct V_105 * V_106 = F_51 ( V_104 ) ;
V_124 V_193 = V_106 -> V_113 ;
T_5 V_184 ;
int V_132 ;
V_132 = F_98 ( V_181 [ V_119 ] , & V_184 ) ;
if ( V_132 < 0 )
return V_132 ;
if ( V_181 [ V_117 ] )
V_132 = F_97 ( V_181 , & V_4 , V_117 , V_193 ) ;
else if ( V_181 [ V_118 ] )
V_132 = F_97 ( V_181 , & V_4 , V_118 , V_193 ) ;
else {
F_105 ( V_130 ,
F_88 ( V_2 ) . V_102 ,
F_106 ( V_104 ) ) ;
return 0 ;
}
if ( V_132 < 0 )
return V_132 ;
V_159 = F_107 ( V_130 , V_184 , & V_4 ) ;
if ( ! V_159 )
return - V_194 ;
V_23 = F_87 ( V_159 ) ;
if ( V_181 [ V_98 ] ) {
V_125 V_195 = F_108 ( F_109 ( V_181 [ V_98 ] ) ) ;
if ( V_195 != ( T_2 ) ( unsigned long ) V_23 ) {
F_78 ( V_23 ) ;
return - V_194 ;
}
}
if ( F_110 ( & V_23 -> V_26 ) )
F_111 ( V_23 , F_88 ( V_2 ) . V_102 , F_106 ( V_104 ) ) ;
F_78 ( V_23 ) ;
return 0 ;
}
static int
F_112 ( struct V_191 * V_192 , struct V_1 * V_2 ,
const struct V_103 * V_104 ,
const struct V_8 * const V_181 [] )
{
struct V_130 * V_130 = F_81 ( V_192 ) ;
struct V_158 * V_159 ;
struct V_3 V_4 ;
struct V_22 * V_23 ;
struct V_1 * V_196 = NULL ;
struct V_105 * V_106 = F_51 ( V_104 ) ;
V_124 V_193 = V_106 -> V_113 ;
T_5 V_184 ;
int V_132 ;
if ( V_104 -> V_197 & V_198 ) {
struct V_199 V_200 = {
. V_201 = F_80 ,
. V_202 = F_77 ,
} ;
#ifdef F_68
if ( V_181 [ V_69 ] && V_181 [ V_203 ] ) {
struct V_164 * V_165 ;
V_165 = F_113 ( sizeof( struct V_164 ) ,
V_143 ) ;
if ( V_165 == NULL )
return - V_204 ;
V_165 -> V_70 . V_171 = F_108 ( F_109 ( V_181 [ V_69 ] ) ) ;
V_165 -> V_70 . V_170 =
F_108 ( F_109 ( V_181 [ V_203 ] ) ) ;
V_200 . V_155 = V_165 ;
}
#endif
return F_114 ( V_192 , V_2 , V_104 , & V_200 ) ;
}
V_132 = F_98 ( V_181 [ V_119 ] , & V_184 ) ;
if ( V_132 < 0 )
return V_132 ;
if ( V_181 [ V_117 ] )
V_132 = F_97 ( V_181 , & V_4 , V_117 , V_193 ) ;
else if ( V_181 [ V_118 ] )
V_132 = F_97 ( V_181 , & V_4 , V_118 , V_193 ) ;
else
return - V_180 ;
if ( V_132 < 0 )
return V_132 ;
V_159 = F_107 ( V_130 , V_184 , & V_4 ) ;
if ( ! V_159 )
return - V_194 ;
V_23 = F_87 ( V_159 ) ;
V_132 = - V_204 ;
V_196 = F_73 ( V_205 , V_206 ) ;
if ( V_196 == NULL ) {
F_78 ( V_23 ) ;
return - V_204 ;
}
F_8 () ;
V_132 = F_49 ( V_196 , F_88 ( V_2 ) . V_102 , V_104 -> V_172 ,
F_89 ( V_104 -> V_173 ) , V_23 ) ;
F_11 () ;
F_78 ( V_23 ) ;
if ( V_132 <= 0 )
goto free;
V_132 = F_115 ( V_192 , V_196 , F_88 ( V_2 ) . V_102 , V_207 ) ;
if ( V_132 < 0 )
goto V_39;
return 0 ;
free:
F_75 ( V_196 ) ;
V_39:
return V_132 == - V_152 ? - V_151 : V_132 ;
}
static int F_116 ( struct V_153 * V_154 )
{
if ( V_154 -> args [ 1 ] )
F_78 ( (struct V_22 * ) V_154 -> args [ 1 ] ) ;
return 0 ;
}
static int
F_117 ( struct V_1 * V_2 , struct V_153 * V_154 , bool V_208 )
{
struct V_22 * V_23 , * V_157 = NULL ;
struct V_158 * V_159 ;
struct V_160 * V_161 ;
struct V_105 * V_106 = F_51 ( V_154 -> V_104 ) ;
V_124 V_18 = V_106 -> V_113 ;
int V_162 ;
int V_209 ;
struct V_210 * V_211 ;
struct V_130 * V_130 = F_81 ( V_2 -> V_156 ) ;
if ( V_154 -> args [ 2 ] )
return 0 ;
if ( V_154 -> args [ 0 ] == V_212 )
return 0 ;
for ( V_209 = V_154 -> args [ 0 ] ; V_209 < V_212 ; V_209 ++ ) {
struct V_213 * V_214 ;
if ( ! F_118 ( V_209 ) )
continue;
V_214 = F_119 ( V_130 -> V_23 . V_215 , V_209 ) ;
F_120 ( & V_214 -> V_216 ) ;
V_157 = (struct V_22 * ) V_154 -> args [ 1 ] ;
V_211 = V_208 ? & V_214 -> V_208 : & V_214 -> V_217 ;
V_167:
F_85 (h, n, list, hnnode) {
V_23 = F_87 ( V_159 ) ;
if ( V_18 && F_17 ( V_23 ) != V_18 )
continue;
if ( V_154 -> args [ 1 ] ) {
if ( V_23 != V_157 )
continue;
V_154 -> args [ 1 ] = 0 ;
}
F_8 () ;
V_162 = F_49 ( V_2 , F_88 ( V_154 -> V_2 ) . V_102 ,
V_154 -> V_104 -> V_172 ,
F_89 ( V_154 -> V_104 -> V_173 ) ,
V_23 ) ;
F_11 () ;
if ( V_162 < 0 ) {
F_90 ( & V_23 -> V_100 ) ;
V_154 -> args [ 1 ] = ( unsigned long ) V_23 ;
F_121 ( & V_214 -> V_216 ) ;
goto V_39;
}
}
if ( V_154 -> args [ 1 ] ) {
V_154 -> args [ 1 ] = 0 ;
goto V_167;
} else
V_154 -> args [ 2 ] = 1 ;
F_121 ( & V_214 -> V_216 ) ;
}
V_39:
if ( V_157 )
F_78 ( V_157 ) ;
return V_2 -> V_72 ;
}
static int
F_122 ( struct V_1 * V_2 , struct V_153 * V_154 )
{
return F_117 ( V_2 , V_154 , true ) ;
}
static int
F_123 ( struct V_191 * V_192 , struct V_1 * V_2 ,
const struct V_103 * V_104 ,
const struct V_8 * const V_181 [] )
{
if ( V_104 -> V_197 & V_198 ) {
struct V_199 V_200 = {
. V_201 = F_122 ,
. V_202 = F_116 ,
} ;
return F_114 ( V_192 , V_2 , V_104 , & V_200 ) ;
}
return - V_185 ;
}
static int
F_124 ( struct V_1 * V_2 , struct V_153 * V_154 )
{
return F_117 ( V_2 , V_154 , false ) ;
}
static int
F_125 ( struct V_191 * V_192 , struct V_1 * V_2 ,
const struct V_103 * V_104 ,
const struct V_8 * const V_181 [] )
{
if ( V_104 -> V_197 & V_198 ) {
struct V_199 V_200 = {
. V_201 = F_124 ,
. V_202 = F_116 ,
} ;
return F_114 ( V_192 , V_2 , V_104 , & V_200 ) ;
}
return - V_185 ;
}
static int
F_126 ( struct V_22 * V_23 ,
enum V_218 V_219 ,
const struct V_8 * V_48 )
{
F_127 (nfnetlink_parse_nat_setup_hook) V_220 ;
int V_132 ;
V_220 = F_21 ( V_221 ) ;
if ( ! V_220 ) {
#ifdef F_128
F_11 () ;
F_129 ( V_110 ) ;
if ( F_130 ( L_1 ) < 0 ) {
F_131 ( V_110 ) ;
F_8 () ;
return - V_185 ;
}
F_131 ( V_110 ) ;
F_8 () ;
if ( V_221 )
return - V_152 ;
#endif
return - V_185 ;
}
V_132 = V_220 ( V_23 , V_219 , V_48 ) ;
if ( V_132 == - V_152 ) {
#ifdef F_128
F_11 () ;
F_129 ( V_110 ) ;
if ( F_130 ( L_2 , F_17 ( V_23 ) ) < 0 ) {
F_131 ( V_110 ) ;
F_8 () ;
return - V_185 ;
}
F_131 ( V_110 ) ;
F_8 () ;
#else
V_132 = - V_185 ;
#endif
}
return V_132 ;
}
static int
F_132 ( struct V_22 * V_23 , const struct V_8 * const V_181 [] )
{
unsigned long V_222 ;
unsigned int V_25 = F_108 ( F_109 ( V_181 [ V_24 ] ) ) ;
V_222 = V_23 -> V_25 ^ V_25 ;
if ( V_222 & ( V_83 | V_223 | V_224 ) )
return - V_225 ;
if ( V_222 & V_226 && ! ( V_25 & V_226 ) )
return - V_225 ;
if ( V_222 & V_227 && ! ( V_25 & V_227 ) )
return - V_225 ;
V_23 -> V_25 |= V_25 & ~ ( V_228 | V_229 ) ;
return 0 ;
}
static int
F_133 ( struct V_22 * V_23 , const struct V_8 * const V_181 [] )
{
#ifdef F_67
int V_7 ;
if ( ! V_181 [ V_230 ] && ! V_181 [ V_231 ] )
return 0 ;
V_7 = F_126 ( V_23 , V_232 ,
V_181 [ V_230 ] ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_126 ( V_23 , V_233 ,
V_181 [ V_231 ] ) ;
return V_7 ;
#else
if ( ! V_181 [ V_230 ] && ! V_181 [ V_231 ] )
return 0 ;
return - V_185 ;
#endif
}
static inline int
F_134 ( struct V_22 * V_23 , const struct V_8 * const V_181 [] )
{
struct V_37 * V_38 ;
struct V_35 * V_36 = F_20 ( V_23 ) ;
char * V_234 = NULL ;
struct V_8 * V_187 = NULL ;
int V_132 ;
if ( V_23 -> V_235 )
return - V_225 ;
V_132 = F_102 ( V_181 [ V_40 ] , & V_234 , & V_187 ) ;
if ( V_132 < 0 )
return V_132 ;
if ( ! strcmp ( V_234 , L_3 ) ) {
if ( V_36 && V_36 -> V_38 ) {
F_135 ( V_23 ) ;
F_136 ( V_36 -> V_38 , NULL ) ;
}
return 0 ;
}
V_38 = F_137 ( V_234 , F_17 ( V_23 ) ,
F_18 ( V_23 ) ) ;
if ( V_38 == NULL ) {
#ifdef F_128
F_121 ( & V_236 ) ;
if ( F_130 ( L_4 , V_234 ) < 0 ) {
F_120 ( & V_236 ) ;
return - V_185 ;
}
F_120 ( & V_236 ) ;
V_38 = F_137 ( V_234 , F_17 ( V_23 ) ,
F_18 ( V_23 ) ) ;
if ( V_38 )
return - V_152 ;
#endif
return - V_185 ;
}
if ( V_36 ) {
if ( V_36 -> V_38 == V_38 ) {
if ( V_38 -> V_237 )
V_38 -> V_237 ( V_187 , V_23 ) ;
return 0 ;
} else
return - V_225 ;
}
return - V_185 ;
}
static inline int
F_138 ( struct V_22 * V_23 , const struct V_8 * const V_181 [] )
{
V_125 V_26 = F_108 ( F_109 ( V_181 [ V_30 ] ) ) ;
if ( ! F_110 ( & V_23 -> V_26 ) )
return - V_238 ;
V_23 -> V_26 . V_27 = V_28 + V_26 * V_29 ;
F_139 ( & V_23 -> V_26 ) ;
return 0 ;
}
static inline int
F_140 ( struct V_22 * V_23 , const struct V_8 * const V_181 [] )
{
const struct V_8 * V_48 = V_181 [ V_33 ] ;
struct V_8 * V_174 [ V_239 + 1 ] ;
struct V_5 * V_6 ;
int V_132 = 0 ;
V_132 = F_93 ( V_174 , V_239 , V_48 , V_240 ) ;
if ( V_132 < 0 )
return V_132 ;
F_8 () ;
V_6 = F_10 ( F_17 ( V_23 ) , F_18 ( V_23 ) ) ;
if ( V_6 -> V_237 )
V_132 = V_6 -> V_237 ( V_174 , V_23 ) ;
F_11 () ;
return V_132 ;
}
static inline int
F_141 ( struct V_85 * V_86 , const struct V_8 * const V_48 )
{
int V_132 ;
struct V_8 * V_181 [ V_241 + 1 ] ;
V_132 = F_93 ( V_181 , V_241 , V_48 , V_242 ) ;
if ( V_132 < 0 )
return V_132 ;
if ( ! V_181 [ V_87 ] )
return - V_180 ;
V_86 -> V_88 =
F_108 ( F_109 ( V_181 [ V_87 ] ) ) ;
if ( ! V_181 [ V_89 ] )
return - V_180 ;
V_86 -> V_90 =
F_108 ( F_109 ( V_181 [ V_89 ] ) ) ;
if ( ! V_181 [ V_91 ] )
return - V_180 ;
V_86 -> V_92 =
F_108 ( F_109 ( V_181 [ V_91 ] ) ) ;
return 0 ;
}
static int
F_142 ( struct V_22 * V_23 ,
const struct V_8 * const V_181 [] )
{
struct V_93 * V_94 = F_45 ( V_23 ) ;
int V_7 = 0 ;
if ( ! V_94 )
return 0 ;
if ( V_181 [ V_96 ] ) {
V_7 = F_141 ( & V_94 -> V_86 [ V_60 ] ,
V_181 [ V_96 ] ) ;
if ( V_7 < 0 )
return V_7 ;
V_23 -> V_25 |= V_95 ;
}
if ( V_181 [ V_97 ] ) {
V_7 = F_141 ( & V_94 -> V_86 [ V_61 ] ,
V_181 [ V_97 ] ) ;
if ( V_7 < 0 )
return V_7 ;
V_23 -> V_25 |= V_95 ;
}
return 0 ;
}
static int
F_143 ( struct V_22 * V_23 , const struct V_8 * const V_181 [] )
{
#ifdef F_144
T_3 V_72 = F_145 ( V_181 [ V_82 ] ) ;
const void * V_170 = V_181 [ V_243 ] ;
if ( V_72 & ( sizeof( T_2 ) - 1 ) )
return - V_180 ;
if ( V_170 ) {
if ( F_145 ( V_181 [ V_243 ] ) == 0 ||
F_145 ( V_181 [ V_243 ] ) != V_72 )
return - V_180 ;
V_170 = F_103 ( V_181 [ V_243 ] ) ;
}
V_72 /= sizeof( T_2 ) ;
return F_146 ( V_23 , F_103 ( V_181 [ V_82 ] ) , V_170 , V_72 ) ;
#else
return - V_185 ;
#endif
}
static int
F_147 ( struct V_22 * V_23 ,
const struct V_8 * const V_181 [] )
{
int V_132 ;
if ( V_181 [ V_231 ] || V_181 [ V_230 ] || V_181 [ V_84 ] )
return - V_185 ;
if ( V_181 [ V_40 ] ) {
V_132 = F_134 ( V_23 , V_181 ) ;
if ( V_132 < 0 )
return V_132 ;
}
if ( V_181 [ V_30 ] ) {
V_132 = F_138 ( V_23 , V_181 ) ;
if ( V_132 < 0 )
return V_132 ;
}
if ( V_181 [ V_24 ] ) {
V_132 = F_132 ( V_23 , V_181 ) ;
if ( V_132 < 0 )
return V_132 ;
}
if ( V_181 [ V_33 ] ) {
V_132 = F_140 ( V_23 , V_181 ) ;
if ( V_132 < 0 )
return V_132 ;
}
#if F_148 ( F_68 )
if ( V_181 [ V_69 ] )
V_23 -> V_70 = F_108 ( F_109 ( V_181 [ V_69 ] ) ) ;
#endif
if ( V_181 [ V_96 ] || V_181 [ V_97 ] ) {
V_132 = F_142 ( V_23 , V_181 ) ;
if ( V_132 < 0 )
return V_132 ;
}
if ( V_181 [ V_82 ] ) {
V_132 = F_143 ( V_23 , V_181 ) ;
if ( V_132 < 0 )
return V_132 ;
}
return 0 ;
}
static struct V_22 *
F_149 ( struct V_130 * V_130 , T_5 V_184 ,
const struct V_8 * const V_181 [] ,
struct V_3 * V_244 ,
struct V_3 * V_245 ,
T_6 V_193 )
{
struct V_22 * V_23 ;
int V_132 = - V_180 ;
struct V_37 * V_38 ;
struct V_62 * V_63 ;
V_23 = F_150 ( V_130 , V_184 , V_244 , V_245 , V_143 ) ;
if ( F_151 ( V_23 ) )
return F_152 ( - V_204 ) ;
if ( ! V_181 [ V_30 ] )
goto V_246;
V_23 -> V_26 . V_27 = F_108 ( F_109 ( V_181 [ V_30 ] ) ) ;
V_23 -> V_26 . V_27 = V_28 + V_23 -> V_26 . V_27 * V_29 ;
F_8 () ;
if ( V_181 [ V_40 ] ) {
char * V_234 = NULL ;
struct V_8 * V_187 = NULL ;
V_132 = F_102 ( V_181 [ V_40 ] , & V_234 , & V_187 ) ;
if ( V_132 < 0 )
goto V_247;
V_38 = F_137 ( V_234 , F_17 ( V_23 ) ,
F_18 ( V_23 ) ) ;
if ( V_38 == NULL ) {
F_11 () ;
#ifdef F_128
if ( F_130 ( L_4 , V_234 ) < 0 ) {
V_132 = - V_185 ;
goto V_246;
}
F_8 () ;
V_38 = F_137 ( V_234 ,
F_17 ( V_23 ) ,
F_18 ( V_23 ) ) ;
if ( V_38 ) {
V_132 = - V_152 ;
goto V_247;
}
F_11 () ;
#endif
V_132 = - V_185 ;
goto V_246;
} else {
struct V_35 * V_36 ;
V_36 = F_153 ( V_23 , V_38 , V_143 ) ;
if ( V_36 == NULL ) {
V_132 = - V_204 ;
goto V_247;
}
if ( V_38 -> V_237 )
V_38 -> V_237 ( V_187 , V_23 ) ;
F_136 ( V_36 -> V_38 , V_38 ) ;
}
} else {
V_132 = F_154 ( V_23 , NULL , V_143 ) ;
if ( V_132 < 0 )
goto V_247;
}
V_132 = F_133 ( V_23 , V_181 ) ;
if ( V_132 < 0 )
goto V_247;
F_155 ( V_23 , V_143 ) ;
F_156 ( V_23 , V_143 ) ;
F_157 ( V_23 , 0 , 0 , V_143 ) ;
F_158 ( V_23 ) ;
V_23 -> V_25 |= V_223 ;
if ( V_181 [ V_24 ] ) {
V_132 = F_132 ( V_23 , V_181 ) ;
if ( V_132 < 0 )
goto V_247;
}
if ( V_181 [ V_96 ] || V_181 [ V_97 ] ) {
V_132 = F_142 ( V_23 , V_181 ) ;
if ( V_132 < 0 )
goto V_247;
}
memset ( & V_23 -> V_248 , 0 , sizeof( V_23 -> V_248 ) ) ;
if ( V_181 [ V_33 ] ) {
V_132 = F_140 ( V_23 , V_181 ) ;
if ( V_132 < 0 )
goto V_247;
}
#if F_148 ( F_68 )
if ( V_181 [ V_69 ] )
V_23 -> V_70 = F_108 ( F_109 ( V_181 [ V_69 ] ) ) ;
#endif
if ( V_181 [ V_84 ] ) {
struct V_3 V_235 ;
struct V_158 * V_249 ;
struct V_22 * V_250 ;
V_132 = F_97 ( V_181 , & V_235 , V_84 , V_193 ) ;
if ( V_132 < 0 )
goto V_247;
V_249 = F_107 ( V_130 , V_184 , & V_235 ) ;
if ( V_249 == NULL ) {
V_132 = - V_194 ;
goto V_247;
}
V_250 = F_87 ( V_249 ) ;
F_159 ( V_251 , & V_23 -> V_25 ) ;
V_23 -> V_235 = V_250 ;
}
V_63 = F_31 ( V_23 ) ;
if ( V_63 )
V_63 -> V_66 = F_160 ( F_161 () ) ;
V_132 = F_162 ( V_23 ) ;
if ( V_132 < 0 )
goto V_247;
F_11 () ;
return V_23 ;
V_247:
F_11 () ;
V_246:
F_163 ( V_23 ) ;
return F_152 ( V_132 ) ;
}
static int
F_164 ( struct V_191 * V_192 , struct V_1 * V_2 ,
const struct V_103 * V_104 ,
const struct V_8 * const V_181 [] )
{
struct V_130 * V_130 = F_81 ( V_192 ) ;
struct V_3 V_244 , V_245 ;
struct V_158 * V_159 = NULL ;
struct V_105 * V_106 = F_51 ( V_104 ) ;
struct V_22 * V_23 ;
V_124 V_193 = V_106 -> V_113 ;
T_5 V_184 ;
int V_132 ;
V_132 = F_98 ( V_181 [ V_119 ] , & V_184 ) ;
if ( V_132 < 0 )
return V_132 ;
if ( V_181 [ V_117 ] ) {
V_132 = F_97 ( V_181 , & V_244 , V_117 , V_193 ) ;
if ( V_132 < 0 )
return V_132 ;
}
if ( V_181 [ V_118 ] ) {
V_132 = F_97 ( V_181 , & V_245 , V_118 , V_193 ) ;
if ( V_132 < 0 )
return V_132 ;
}
if ( V_181 [ V_117 ] )
V_159 = F_107 ( V_130 , V_184 , & V_244 ) ;
else if ( V_181 [ V_118 ] )
V_159 = F_107 ( V_130 , V_184 , & V_245 ) ;
if ( V_159 == NULL ) {
V_132 = - V_194 ;
if ( V_104 -> V_197 & V_138 ) {
enum V_252 V_127 ;
if ( ! V_181 [ V_117 ] || ! V_181 [ V_118 ] )
return - V_180 ;
V_23 = F_149 ( V_130 , V_184 , V_181 , & V_244 ,
& V_245 , V_193 ) ;
if ( F_151 ( V_23 ) )
return F_165 ( V_23 ) ;
V_132 = 0 ;
if ( F_166 ( V_251 , & V_23 -> V_25 ) )
V_127 = V_137 ;
else
V_127 = V_136 ;
if ( V_181 [ V_82 ] &&
F_143 ( V_23 , V_181 ) == 0 )
V_127 |= ( 1 << V_148 ) ;
F_167 ( ( 1 << V_253 ) |
( 1 << V_254 ) |
( 1 << V_146 ) |
( 1 << V_145 ) |
( 1 << V_149 ) |
( 1 << V_150 ) | V_127 ,
V_23 , F_88 ( V_2 ) . V_102 ,
F_106 ( V_104 ) ) ;
F_78 ( V_23 ) ;
}
return V_132 ;
}
V_132 = - V_255 ;
V_23 = F_87 ( V_159 ) ;
if ( ! ( V_104 -> V_197 & V_139 ) ) {
F_120 ( & V_236 ) ;
V_132 = F_147 ( V_23 , V_181 ) ;
F_121 ( & V_236 ) ;
if ( V_132 == 0 ) {
F_167 ( ( 1 << V_253 ) |
( 1 << V_254 ) |
( 1 << V_146 ) |
( 1 << V_148 ) |
( 1 << V_145 ) |
( 1 << V_149 ) |
( 1 << V_150 ) ,
V_23 , F_88 ( V_2 ) . V_102 ,
F_106 ( V_104 ) ) ;
}
}
F_78 ( V_23 ) ;
return V_132 ;
}
static int
F_168 ( struct V_1 * V_2 , T_2 V_102 , T_2 V_86 ,
T_7 V_209 , const struct V_256 * V_257 )
{
struct V_103 * V_104 ;
struct V_105 * V_106 ;
unsigned int V_107 = V_102 ? V_108 : 0 , V_109 ;
V_109 = ( V_110 << 8 | V_258 ) ;
V_104 = F_50 ( V_2 , V_102 , V_86 , V_109 , sizeof( * V_106 ) , V_107 ) ;
if ( V_104 == NULL )
goto V_112;
V_106 = F_51 ( V_104 ) ;
V_106 -> V_113 = V_259 ;
V_106 -> V_114 = V_115 ;
V_106 -> V_116 = F_55 ( V_209 ) ;
if ( F_13 ( V_2 , V_260 , F_14 ( V_257 -> V_261 ) ) ||
F_13 ( V_2 , V_262 , F_14 ( V_257 -> V_263 ) ) ||
F_13 ( V_2 , V_264 , F_14 ( V_257 -> V_265 ) ) ||
F_13 ( V_2 , V_266 , F_14 ( V_257 -> V_267 ) ) ||
F_13 ( V_2 , V_268 , F_14 ( V_257 -> V_269 ) ) ||
F_13 ( V_2 , V_270 , F_14 ( V_257 -> V_271 ) ) ||
F_13 ( V_2 , V_272 , F_14 ( V_257 -> V_273 ) ) ||
F_13 ( V_2 , V_274 , F_14 ( V_257 -> V_275 ) ) ||
F_13 ( V_2 , V_276 ,
F_14 ( V_257 -> V_277 ) ) ||
F_13 ( V_2 , V_278 , F_14 ( V_257 -> V_279 ) ) ||
F_13 ( V_2 , V_280 , F_14 ( V_257 -> V_281 ) ) ||
F_13 ( V_2 , V_282 , F_14 ( V_257 -> error ) ) ||
F_13 ( V_2 , V_283 ,
F_14 ( V_257 -> V_284 ) ) )
goto V_12;
F_56 ( V_2 , V_104 ) ;
return V_2 -> V_72 ;
V_12:
V_112:
F_57 ( V_2 , V_104 ) ;
return - 1 ;
}
static int
F_169 ( struct V_1 * V_2 , struct V_153 * V_154 )
{
int V_209 ;
struct V_130 * V_130 = F_81 ( V_2 -> V_156 ) ;
if ( V_154 -> args [ 0 ] == V_212 )
return 0 ;
for ( V_209 = V_154 -> args [ 0 ] ; V_209 < V_212 ; V_209 ++ ) {
const struct V_256 * V_257 ;
if ( ! F_118 ( V_209 ) )
continue;
V_257 = F_119 ( V_130 -> V_23 . V_285 , V_209 ) ;
if ( F_168 ( V_2 ,
F_88 ( V_154 -> V_2 ) . V_102 ,
V_154 -> V_104 -> V_172 ,
V_209 , V_257 ) < 0 )
break;
}
V_154 -> args [ 0 ] = V_209 ;
return V_2 -> V_72 ;
}
static int
F_170 ( struct V_191 * V_192 , struct V_1 * V_2 ,
const struct V_103 * V_104 ,
const struct V_8 * const V_181 [] )
{
if ( V_104 -> V_197 & V_198 ) {
struct V_199 V_200 = {
. V_201 = F_169 ,
} ;
return F_114 ( V_192 , V_2 , V_104 , & V_200 ) ;
}
return 0 ;
}
static int
F_171 ( struct V_1 * V_2 , T_2 V_102 , T_2 V_86 , T_2 type ,
struct V_130 * V_130 )
{
struct V_103 * V_104 ;
struct V_105 * V_106 ;
unsigned int V_107 = V_102 ? V_108 : 0 , V_109 ;
unsigned int V_286 = F_48 ( & V_130 -> V_23 . V_287 ) ;
V_109 = ( V_110 << 8 | V_288 ) ;
V_104 = F_50 ( V_2 , V_102 , V_86 , V_109 , sizeof( * V_106 ) , V_107 ) ;
if ( V_104 == NULL )
goto V_112;
V_106 = F_51 ( V_104 ) ;
V_106 -> V_113 = V_259 ;
V_106 -> V_114 = V_115 ;
V_106 -> V_116 = 0 ;
if ( F_13 ( V_2 , V_289 , F_14 ( V_286 ) ) )
goto V_12;
F_56 ( V_2 , V_104 ) ;
return V_2 -> V_72 ;
V_12:
V_112:
F_57 ( V_2 , V_104 ) ;
return - 1 ;
}
static int
F_172 ( struct V_191 * V_192 , struct V_1 * V_2 ,
const struct V_103 * V_104 ,
const struct V_8 * const V_181 [] )
{
struct V_1 * V_196 ;
int V_132 ;
V_196 = F_73 ( V_205 , V_206 ) ;
if ( V_196 == NULL )
return - V_204 ;
V_132 = F_171 ( V_196 , F_88 ( V_2 ) . V_102 ,
V_104 -> V_172 ,
F_89 ( V_104 -> V_173 ) ,
F_81 ( V_2 -> V_156 ) ) ;
if ( V_132 <= 0 )
goto free;
V_132 = F_115 ( V_192 , V_196 , F_88 ( V_2 ) . V_102 , V_207 ) ;
if ( V_132 < 0 )
goto V_39;
return 0 ;
free:
F_75 ( V_196 ) ;
V_39:
return V_132 == - V_152 ? - V_151 : V_132 ;
}
static T_3
F_173 ( const struct V_22 * V_23 )
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
+ F_58 ( V_23 )
;
}
static int
F_174 ( struct V_1 * V_2 , struct V_22 * V_23 )
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
if ( V_23 -> V_235 && F_41 ( V_2 , V_23 ) < 0 )
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
return - V_290 ;
}
static int
F_175 ( const struct V_8 * V_181 [] , struct V_22 * V_23 )
{
int V_132 ;
if ( V_181 [ V_30 ] ) {
V_132 = F_138 ( V_23 , V_181 ) ;
if ( V_132 < 0 )
return V_132 ;
}
if ( V_181 [ V_24 ] ) {
V_132 = F_132 ( V_23 , V_181 ) ;
if ( V_132 < 0 )
return V_132 ;
}
if ( V_181 [ V_40 ] ) {
V_132 = F_134 ( V_23 , V_181 ) ;
if ( V_132 < 0 )
return V_132 ;
}
if ( V_181 [ V_82 ] ) {
V_132 = F_143 ( V_23 , V_181 ) ;
if ( V_132 < 0 )
return V_132 ;
}
#if F_148 ( F_68 )
if ( V_181 [ V_69 ] ) {
T_2 V_170 = 0 , V_70 , V_291 ;
if ( V_181 [ V_203 ] )
V_170 = ~ F_108 ( F_109 ( V_181 [ V_203 ] ) ) ;
V_70 = F_108 ( F_109 ( V_181 [ V_69 ] ) ) ;
V_291 = ( V_23 -> V_70 & V_170 ) ^ V_70 ;
if ( V_291 != V_23 -> V_70 )
V_23 -> V_70 = V_291 ;
}
#endif
return 0 ;
}
static int
F_176 ( const struct V_8 * V_48 , struct V_22 * V_23 )
{
struct V_8 * V_181 [ V_292 + 1 ] ;
int V_7 ;
V_7 = F_93 ( V_181 , V_292 , V_48 , V_293 ) ;
if ( V_7 < 0 )
return V_7 ;
F_120 ( & V_236 ) ;
V_7 = F_175 ( ( const struct V_8 * * ) V_181 , V_23 ) ;
F_121 ( & V_236 ) ;
return V_7 ;
}
static int F_177 ( const struct V_8 * const * V_181 ,
const struct V_22 * V_23 ,
struct V_3 * V_4 ,
struct V_3 * V_170 )
{
int V_132 ;
V_132 = F_97 ( V_181 , V_4 , V_294 ,
F_17 ( V_23 ) ) ;
if ( V_132 < 0 )
return V_132 ;
return F_97 ( V_181 , V_170 , V_295 ,
F_17 ( V_23 ) ) ;
}
static int
F_178 ( const struct V_8 * V_48 , struct V_22 * V_23 ,
T_2 V_102 , T_2 V_142 )
{
struct V_8 * V_181 [ V_296 + 1 ] ;
struct V_3 V_4 , V_170 ;
struct V_37 * V_38 = NULL ;
struct V_297 * exp ;
int V_132 ;
V_132 = F_93 ( V_181 , V_296 , V_48 , V_298 ) ;
if ( V_132 < 0 )
return V_132 ;
V_132 = F_177 ( ( const struct V_8 * const * ) V_181 ,
V_23 , & V_4 , & V_170 ) ;
if ( V_132 < 0 )
return V_132 ;
if ( V_181 [ V_299 ] ) {
const char * V_234 = F_103 ( V_181 [ V_299 ] ) ;
V_38 = F_137 ( V_234 , F_17 ( V_23 ) ,
F_18 ( V_23 ) ) ;
if ( V_38 == NULL )
return - V_185 ;
}
exp = F_179 ( ( const struct V_8 * const * ) V_181 , V_23 ,
V_38 , & V_4 , & V_170 ) ;
if ( F_151 ( exp ) )
return F_165 ( exp ) ;
V_132 = F_180 ( exp , V_102 , V_142 ) ;
if ( V_132 < 0 ) {
F_181 ( exp ) ;
return V_132 ;
}
return 0 ;
}
static inline int
F_182 ( struct V_1 * V_2 ,
const struct V_3 * V_4 ,
enum V_300 type )
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
F_183 ( struct V_1 * V_2 ,
const struct V_3 * V_4 ,
const struct V_301 * V_170 )
{
int V_7 ;
struct V_17 * V_18 ;
struct V_5 * V_6 ;
struct V_3 V_302 ;
struct V_8 * V_9 ;
memset ( & V_302 , 0xFF , sizeof( V_302 ) ) ;
memcpy ( & V_302 . V_20 . V_193 , & V_170 -> V_20 . V_193 , sizeof( V_302 . V_20 . V_193 ) ) ;
V_302 . V_20 . V_303 . V_304 = V_170 -> V_20 . V_303 . V_304 ;
V_302 . V_14 . V_15 = V_4 -> V_14 . V_15 ;
V_9 = F_2 ( V_2 , V_295 | V_11 ) ;
if ( ! V_9 )
goto V_12;
F_8 () ;
V_18 = F_9 ( V_4 -> V_20 . V_21 ) ;
V_7 = F_6 ( V_2 , & V_302 , V_18 ) ;
if ( V_7 >= 0 ) {
V_6 = F_10 ( V_4 -> V_20 . V_21 ,
V_4 -> V_14 . V_15 ) ;
V_7 = F_1 ( V_2 , & V_302 , V_6 ) ;
}
F_11 () ;
if ( F_184 ( V_7 < 0 ) )
goto V_12;
F_5 ( V_2 , V_9 ) ;
return 0 ;
V_12:
return - 1 ;
}
static int
F_185 ( struct V_1 * V_2 ,
const struct V_297 * exp )
{
struct V_22 * V_235 = exp -> V_235 ;
long V_26 = ( ( long ) exp -> V_26 . V_27 - ( long ) V_28 ) / V_29 ;
struct V_35 * V_36 ;
#ifdef F_67
struct V_8 * V_9 ;
struct V_3 V_305 = {} ;
#endif
struct V_306 * V_307 ;
if ( V_26 < 0 )
V_26 = 0 ;
if ( F_182 ( V_2 , & exp -> V_4 , V_294 ) < 0 )
goto V_12;
if ( F_183 ( V_2 , & exp -> V_4 , & exp -> V_170 ) < 0 )
goto V_12;
if ( F_182 ( V_2 ,
& V_235 -> V_308 [ V_60 ] . V_4 ,
V_309 ) < 0 )
goto V_12;
#ifdef F_67
if ( ! F_186 ( & exp -> V_310 , & V_311 ) ||
exp -> V_312 . V_304 ) {
V_9 = F_2 ( V_2 , V_313 | V_11 ) ;
if ( ! V_9 )
goto V_12;
if ( F_13 ( V_2 , V_314 , F_14 ( exp -> V_46 ) ) )
goto V_12;
V_305 . V_20 . V_21 = F_17 ( V_235 ) ;
V_305 . V_20 . V_193 = exp -> V_310 ;
V_305 . V_14 . V_15 = F_18 ( V_235 ) ;
V_305 . V_20 . V_303 = exp -> V_312 ;
if ( F_182 ( V_2 , & V_305 ,
V_315 ) < 0 )
goto V_12;
F_5 ( V_2 , V_9 ) ;
}
#endif
if ( F_13 ( V_2 , V_316 , F_14 ( V_26 ) ) ||
F_13 ( V_2 , V_317 , F_14 ( ( unsigned long ) exp ) ) ||
F_13 ( V_2 , V_318 , F_14 ( exp -> V_107 ) ) ||
F_13 ( V_2 , V_319 , F_14 ( exp -> V_320 ) ) )
goto V_12;
V_36 = F_20 ( V_235 ) ;
if ( V_36 ) {
struct V_37 * V_38 ;
V_38 = F_21 ( V_36 -> V_38 ) ;
if ( V_38 &&
F_22 ( V_2 , V_299 , V_38 -> V_42 ) )
goto V_12;
}
V_307 = F_187 ( exp -> V_321 ) ;
if ( V_307 != NULL &&
F_22 ( V_2 , V_322 , V_307 -> V_42 ) )
goto V_12;
return 0 ;
V_12:
return - 1 ;
}
static int
F_188 ( struct V_1 * V_2 , T_2 V_102 , T_2 V_86 ,
int V_109 , const struct V_297 * exp )
{
struct V_103 * V_104 ;
struct V_105 * V_106 ;
unsigned int V_107 = V_102 ? V_108 : 0 ;
V_109 |= V_323 << 8 ;
V_104 = F_50 ( V_2 , V_102 , V_86 , V_109 , sizeof( * V_106 ) , V_107 ) ;
if ( V_104 == NULL )
goto V_112;
V_106 = F_51 ( V_104 ) ;
V_106 -> V_113 = exp -> V_4 . V_20 . V_21 ;
V_106 -> V_114 = V_115 ;
V_106 -> V_116 = 0 ;
if ( F_185 ( V_2 , exp ) < 0 )
goto V_12;
F_56 ( V_2 , V_104 ) ;
return V_2 -> V_72 ;
V_112:
V_12:
F_57 ( V_2 , V_104 ) ;
return - 1 ;
}
static int
F_189 ( unsigned int V_127 , struct V_324 * V_129 )
{
struct V_297 * exp = V_129 -> exp ;
struct V_130 * V_130 = F_190 ( exp ) ;
struct V_103 * V_104 ;
struct V_105 * V_106 ;
struct V_1 * V_2 ;
unsigned int type , V_131 ;
int V_107 = 0 ;
if ( V_127 & ( 1 << V_325 ) ) {
type = V_326 ;
V_131 = V_327 ;
} else if ( V_127 & ( 1 << V_328 ) ) {
type = V_329 ;
V_107 = V_138 | V_139 ;
V_131 = V_330 ;
} else
return 0 ;
if ( ! V_129 -> V_142 && ! F_72 ( V_130 , V_131 ) )
return 0 ;
V_2 = F_73 ( V_205 , V_143 ) ;
if ( V_2 == NULL )
goto V_144;
type |= V_323 << 8 ;
V_104 = F_50 ( V_2 , V_129 -> V_102 , 0 , type , sizeof( * V_106 ) , V_107 ) ;
if ( V_104 == NULL )
goto V_112;
V_106 = F_51 ( V_104 ) ;
V_106 -> V_113 = exp -> V_4 . V_20 . V_21 ;
V_106 -> V_114 = V_115 ;
V_106 -> V_116 = 0 ;
F_8 () ;
if ( F_185 ( V_2 , exp ) < 0 )
goto V_12;
F_11 () ;
F_56 ( V_2 , V_104 ) ;
F_74 ( V_2 , V_130 , V_129 -> V_102 , V_131 , V_129 -> V_142 , V_143 ) ;
return 0 ;
V_12:
F_11 () ;
F_57 ( V_2 , V_104 ) ;
V_112:
F_75 ( V_2 ) ;
V_144:
F_76 ( V_130 , 0 , 0 , - V_151 ) ;
return 0 ;
}
static int F_191 ( struct V_153 * V_154 )
{
if ( V_154 -> args [ 1 ] )
F_181 ( (struct V_297 * ) V_154 -> args [ 1 ] ) ;
return 0 ;
}
static int
F_192 ( struct V_1 * V_2 , struct V_153 * V_154 )
{
struct V_130 * V_130 = F_81 ( V_2 -> V_156 ) ;
struct V_297 * exp , * V_157 ;
struct V_105 * V_106 = F_51 ( V_154 -> V_104 ) ;
V_124 V_18 = V_106 -> V_113 ;
F_8 () ;
V_157 = (struct V_297 * ) V_154 -> args [ 1 ] ;
for (; V_154 -> args [ 0 ] < V_331 ; V_154 -> args [ 0 ] ++ ) {
V_167:
F_193 (exp, &net->ct.expect_hash[cb->args[0]],
hnode) {
if ( V_18 && exp -> V_4 . V_20 . V_21 != V_18 )
continue;
if ( V_154 -> args [ 1 ] ) {
if ( exp != V_157 )
continue;
V_154 -> args [ 1 ] = 0 ;
}
if ( F_188 ( V_2 ,
F_88 ( V_154 -> V_2 ) . V_102 ,
V_154 -> V_104 -> V_172 ,
V_329 ,
exp ) < 0 ) {
if ( ! F_194 ( & exp -> V_101 ) )
continue;
V_154 -> args [ 1 ] = ( unsigned long ) exp ;
goto V_39;
}
}
if ( V_154 -> args [ 1 ] ) {
V_154 -> args [ 1 ] = 0 ;
goto V_167;
}
}
V_39:
F_11 () ;
if ( V_157 )
F_181 ( V_157 ) ;
return V_2 -> V_72 ;
}
static int
F_195 ( struct V_1 * V_2 , struct V_153 * V_154 )
{
struct V_297 * exp , * V_157 ;
struct V_105 * V_106 = F_51 ( V_154 -> V_104 ) ;
struct V_22 * V_23 = V_154 -> V_155 ;
struct V_35 * V_36 = F_20 ( V_23 ) ;
V_124 V_18 = V_106 -> V_113 ;
if ( V_154 -> args [ 0 ] )
return 0 ;
F_8 () ;
V_157 = (struct V_297 * ) V_154 -> args [ 1 ] ;
V_167:
F_193 (exp, &help->expectations, lnode) {
if ( V_18 && exp -> V_4 . V_20 . V_21 != V_18 )
continue;
if ( V_154 -> args [ 1 ] ) {
if ( exp != V_157 )
continue;
V_154 -> args [ 1 ] = 0 ;
}
if ( F_188 ( V_2 , F_88 ( V_154 -> V_2 ) . V_102 ,
V_154 -> V_104 -> V_172 ,
V_329 ,
exp ) < 0 ) {
if ( ! F_194 ( & exp -> V_101 ) )
continue;
V_154 -> args [ 1 ] = ( unsigned long ) exp ;
goto V_39;
}
}
if ( V_154 -> args [ 1 ] ) {
V_154 -> args [ 1 ] = 0 ;
goto V_167;
}
V_154 -> args [ 0 ] = 1 ;
V_39:
F_11 () ;
if ( V_157 )
F_181 ( V_157 ) ;
return V_2 -> V_72 ;
}
static int F_196 ( struct V_191 * V_192 , struct V_1 * V_2 ,
const struct V_103 * V_104 ,
const struct V_8 * const V_181 [] )
{
int V_132 ;
struct V_130 * V_130 = F_81 ( V_192 ) ;
struct V_105 * V_106 = F_51 ( V_104 ) ;
V_124 V_193 = V_106 -> V_113 ;
struct V_3 V_4 ;
struct V_158 * V_159 ;
struct V_22 * V_23 ;
T_5 V_184 = 0 ;
struct V_199 V_200 = {
. V_201 = F_195 ,
. V_202 = F_191 ,
} ;
V_132 = F_97 ( V_181 , & V_4 , V_309 , V_193 ) ;
if ( V_132 < 0 )
return V_132 ;
if ( V_181 [ V_332 ] ) {
V_132 = F_98 ( V_181 [ V_332 ] , & V_184 ) ;
if ( V_132 < 0 )
return V_132 ;
}
V_159 = F_107 ( V_130 , V_184 , & V_4 ) ;
if ( ! V_159 )
return - V_194 ;
V_23 = F_87 ( V_159 ) ;
V_200 . V_155 = V_23 ;
V_132 = F_114 ( V_192 , V_2 , V_104 , & V_200 ) ;
F_78 ( V_23 ) ;
return V_132 ;
}
static int
F_197 ( struct V_191 * V_192 , struct V_1 * V_2 ,
const struct V_103 * V_104 ,
const struct V_8 * const V_181 [] )
{
struct V_130 * V_130 = F_81 ( V_192 ) ;
struct V_3 V_4 ;
struct V_297 * exp ;
struct V_1 * V_196 ;
struct V_105 * V_106 = F_51 ( V_104 ) ;
V_124 V_193 = V_106 -> V_113 ;
T_5 V_184 ;
int V_132 ;
if ( V_104 -> V_197 & V_198 ) {
if ( V_181 [ V_309 ] )
return F_196 ( V_192 , V_2 , V_104 , V_181 ) ;
else {
struct V_199 V_200 = {
. V_201 = F_192 ,
. V_202 = F_191 ,
} ;
return F_114 ( V_192 , V_2 , V_104 , & V_200 ) ;
}
}
V_132 = F_98 ( V_181 [ V_332 ] , & V_184 ) ;
if ( V_132 < 0 )
return V_132 ;
if ( V_181 [ V_294 ] )
V_132 = F_97 ( V_181 , & V_4 , V_294 , V_193 ) ;
else if ( V_181 [ V_309 ] )
V_132 = F_97 ( V_181 , & V_4 , V_309 , V_193 ) ;
else
return - V_180 ;
if ( V_132 < 0 )
return V_132 ;
exp = F_198 ( V_130 , V_184 , & V_4 ) ;
if ( ! exp )
return - V_194 ;
if ( V_181 [ V_317 ] ) {
T_8 V_195 = F_109 ( V_181 [ V_317 ] ) ;
if ( F_108 ( V_195 ) != ( T_2 ) ( unsigned long ) exp ) {
F_181 ( exp ) ;
return - V_194 ;
}
}
V_132 = - V_204 ;
V_196 = F_73 ( V_205 , V_206 ) ;
if ( V_196 == NULL ) {
F_181 ( exp ) ;
goto V_39;
}
F_8 () ;
V_132 = F_188 ( V_196 , F_88 ( V_2 ) . V_102 ,
V_104 -> V_172 , V_329 , exp ) ;
F_11 () ;
F_181 ( exp ) ;
if ( V_132 <= 0 )
goto free;
V_132 = F_115 ( V_192 , V_196 , F_88 ( V_2 ) . V_102 , V_207 ) ;
if ( V_132 < 0 )
goto V_39;
return 0 ;
free:
F_75 ( V_196 ) ;
V_39:
return V_132 == - V_152 ? - V_151 : V_132 ;
}
static int
F_199 ( struct V_191 * V_192 , struct V_1 * V_2 ,
const struct V_103 * V_104 ,
const struct V_8 * const V_181 [] )
{
struct V_130 * V_130 = F_81 ( V_192 ) ;
struct V_297 * exp ;
struct V_3 V_4 ;
struct V_105 * V_106 = F_51 ( V_104 ) ;
struct V_333 * V_334 ;
V_124 V_193 = V_106 -> V_113 ;
unsigned int V_80 ;
T_5 V_184 ;
int V_132 ;
if ( V_181 [ V_294 ] ) {
V_132 = F_98 ( V_181 [ V_332 ] , & V_184 ) ;
if ( V_132 < 0 )
return V_132 ;
V_132 = F_97 ( V_181 , & V_4 , V_294 , V_193 ) ;
if ( V_132 < 0 )
return V_132 ;
exp = F_198 ( V_130 , V_184 , & V_4 ) ;
if ( ! exp )
return - V_194 ;
if ( V_181 [ V_317 ] ) {
T_8 V_195 = F_109 ( V_181 [ V_317 ] ) ;
if ( F_108 ( V_195 ) != ( T_2 ) ( unsigned long ) exp ) {
F_181 ( exp ) ;
return - V_194 ;
}
}
F_120 ( & V_236 ) ;
if ( F_110 ( & exp -> V_26 ) ) {
F_200 ( exp , F_88 ( V_2 ) . V_102 ,
F_106 ( V_104 ) ) ;
F_181 ( exp ) ;
}
F_121 ( & V_236 ) ;
F_181 ( exp ) ;
} else if ( V_181 [ V_299 ] ) {
char * V_42 = F_103 ( V_181 [ V_299 ] ) ;
struct V_35 * V_335 ;
F_120 ( & V_236 ) ;
for ( V_80 = 0 ; V_80 < V_331 ; V_80 ++ ) {
F_201 (exp, next,
&net->ct.expect_hash[i],
hnode) {
V_335 = F_20 ( exp -> V_235 ) ;
if ( ! strcmp ( V_335 -> V_38 -> V_42 , V_42 ) &&
F_110 ( & exp -> V_26 ) ) {
F_200 ( exp ,
F_88 ( V_2 ) . V_102 ,
F_106 ( V_104 ) ) ;
F_181 ( exp ) ;
}
}
}
F_121 ( & V_236 ) ;
} else {
F_120 ( & V_236 ) ;
for ( V_80 = 0 ; V_80 < V_331 ; V_80 ++ ) {
F_201 (exp, next,
&net->ct.expect_hash[i],
hnode) {
if ( F_110 ( & exp -> V_26 ) ) {
F_200 ( exp ,
F_88 ( V_2 ) . V_102 ,
F_106 ( V_104 ) ) ;
F_181 ( exp ) ;
}
}
}
F_121 ( & V_236 ) ;
}
return 0 ;
}
static int
F_202 ( struct V_297 * V_336 ,
const struct V_8 * const V_181 [] )
{
if ( V_181 [ V_316 ] ) {
if ( ! F_110 ( & V_336 -> V_26 ) )
return - V_238 ;
V_336 -> V_26 . V_27 = V_28 +
F_108 ( F_109 ( V_181 [ V_316 ] ) ) * V_29 ;
F_139 ( & V_336 -> V_26 ) ;
}
return 0 ;
}
static int
F_203 ( const struct V_8 * V_48 ,
struct V_297 * exp ,
V_124 V_193 )
{
#ifdef F_67
struct V_8 * V_174 [ V_337 + 1 ] ;
struct V_3 V_305 = {} ;
int V_132 ;
V_132 = F_93 ( V_174 , V_337 , V_48 , V_338 ) ;
if ( V_132 < 0 )
return V_132 ;
if ( ! V_174 [ V_314 ] || ! V_174 [ V_315 ] )
return - V_180 ;
V_132 = F_97 ( ( const struct V_8 * const * ) V_174 ,
& V_305 , V_315 , V_193 ) ;
if ( V_132 < 0 )
return V_132 ;
exp -> V_310 = V_305 . V_20 . V_193 ;
exp -> V_312 = V_305 . V_20 . V_303 ;
exp -> V_46 = F_108 ( F_109 ( V_174 [ V_314 ] ) ) ;
return 0 ;
#else
return - V_185 ;
#endif
}
static struct V_297 *
F_179 ( const struct V_8 * const V_181 [] , struct V_22 * V_23 ,
struct V_37 * V_38 ,
struct V_3 * V_4 ,
struct V_3 * V_170 )
{
V_125 V_320 = 0 ;
struct V_297 * exp ;
struct V_35 * V_36 ;
int V_132 ;
if ( V_181 [ V_319 ] && V_38 ) {
V_320 = F_108 ( F_109 ( V_181 [ V_319 ] ) ) ;
if ( V_320 > V_38 -> V_339 )
return F_152 ( - V_180 ) ;
}
exp = F_204 ( V_23 ) ;
if ( ! exp )
return F_152 ( - V_204 ) ;
V_36 = F_20 ( V_23 ) ;
if ( ! V_36 ) {
if ( ! V_181 [ V_316 ] ) {
V_132 = - V_180 ;
goto V_340;
}
exp -> V_26 . V_27 =
V_28 + F_108 ( F_109 ( V_181 [ V_316 ] ) ) * V_29 ;
exp -> V_107 = V_341 ;
if ( V_181 [ V_318 ] ) {
exp -> V_107 |=
F_108 ( F_109 ( V_181 [ V_318 ] ) ) ;
}
} else {
if ( V_181 [ V_318 ] ) {
exp -> V_107 = F_108 ( F_109 ( V_181 [ V_318 ] ) ) ;
exp -> V_107 &= ~ V_341 ;
} else
exp -> V_107 = 0 ;
}
if ( V_181 [ V_322 ] ) {
const char * V_42 = F_103 ( V_181 [ V_322 ] ) ;
struct V_306 * V_307 ;
V_307 = F_205 ( V_42 ) ;
if ( V_307 == NULL ) {
V_132 = - V_180 ;
goto V_340;
}
exp -> V_321 = V_307 -> V_321 ;
} else
exp -> V_321 = NULL ;
exp -> V_320 = V_320 ;
exp -> V_235 = V_23 ;
exp -> V_38 = V_38 ;
exp -> V_4 = * V_4 ;
exp -> V_170 . V_20 . V_193 = V_170 -> V_20 . V_193 ;
exp -> V_170 . V_20 . V_303 . V_304 = V_170 -> V_20 . V_303 . V_304 ;
if ( V_181 [ V_313 ] ) {
V_132 = F_203 ( V_181 [ V_313 ] ,
exp , F_17 ( V_23 ) ) ;
if ( V_132 < 0 )
goto V_340;
}
return exp ;
V_340:
F_181 ( exp ) ;
return F_152 ( V_132 ) ;
}
static int
F_206 ( struct V_130 * V_130 , T_5 V_184 ,
const struct V_8 * const V_181 [] ,
V_124 V_193 , T_2 V_102 , int V_142 )
{
struct V_3 V_4 , V_170 , F_42 ;
struct V_158 * V_159 = NULL ;
struct V_37 * V_38 = NULL ;
struct V_297 * exp ;
struct V_22 * V_23 ;
int V_132 ;
V_132 = F_97 ( V_181 , & V_4 , V_294 , V_193 ) ;
if ( V_132 < 0 )
return V_132 ;
V_132 = F_97 ( V_181 , & V_170 , V_295 , V_193 ) ;
if ( V_132 < 0 )
return V_132 ;
V_132 = F_97 ( V_181 , & F_42 , V_309 , V_193 ) ;
if ( V_132 < 0 )
return V_132 ;
V_159 = F_107 ( V_130 , V_184 , & F_42 ) ;
if ( ! V_159 )
return - V_194 ;
V_23 = F_87 ( V_159 ) ;
if ( V_181 [ V_299 ] ) {
const char * V_234 = F_103 ( V_181 [ V_299 ] ) ;
V_38 = F_137 ( V_234 , V_193 ,
F_18 ( V_23 ) ) ;
if ( V_38 == NULL ) {
#ifdef F_128
if ( F_130 ( L_4 , V_234 ) < 0 ) {
V_132 = - V_185 ;
goto V_342;
}
V_38 = F_137 ( V_234 , V_193 ,
F_18 ( V_23 ) ) ;
if ( V_38 ) {
V_132 = - V_152 ;
goto V_342;
}
#endif
V_132 = - V_185 ;
goto V_342;
}
}
exp = F_179 ( V_181 , V_23 , V_38 , & V_4 , & V_170 ) ;
if ( F_151 ( exp ) ) {
V_132 = F_165 ( exp ) ;
goto V_342;
}
V_132 = F_180 ( exp , V_102 , V_142 ) ;
if ( V_132 < 0 )
goto V_343;
return 0 ;
V_343:
F_181 ( exp ) ;
V_342:
F_78 ( V_23 ) ;
return V_132 ;
}
static int
F_207 ( struct V_191 * V_192 , struct V_1 * V_2 ,
const struct V_103 * V_104 ,
const struct V_8 * const V_181 [] )
{
struct V_130 * V_130 = F_81 ( V_192 ) ;
struct V_3 V_4 ;
struct V_297 * exp ;
struct V_105 * V_106 = F_51 ( V_104 ) ;
V_124 V_193 = V_106 -> V_113 ;
T_5 V_184 ;
int V_132 ;
if ( ! V_181 [ V_294 ]
|| ! V_181 [ V_295 ]
|| ! V_181 [ V_309 ] )
return - V_180 ;
V_132 = F_98 ( V_181 [ V_332 ] , & V_184 ) ;
if ( V_132 < 0 )
return V_132 ;
V_132 = F_97 ( V_181 , & V_4 , V_294 , V_193 ) ;
if ( V_132 < 0 )
return V_132 ;
F_120 ( & V_236 ) ;
exp = F_208 ( V_130 , V_184 , & V_4 ) ;
if ( ! exp ) {
F_121 ( & V_236 ) ;
V_132 = - V_194 ;
if ( V_104 -> V_197 & V_138 ) {
V_132 = F_206 ( V_130 , V_184 , V_181 ,
V_193 ,
F_88 ( V_2 ) . V_102 ,
F_106 ( V_104 ) ) ;
}
return V_132 ;
}
V_132 = - V_255 ;
if ( ! ( V_104 -> V_197 & V_139 ) )
V_132 = F_202 ( exp , V_181 ) ;
F_121 ( & V_236 ) ;
return V_132 ;
}
static int
F_209 ( struct V_1 * V_2 , T_2 V_102 , T_2 V_86 , int V_209 ,
const struct V_256 * V_257 )
{
struct V_103 * V_104 ;
struct V_105 * V_106 ;
unsigned int V_107 = V_102 ? V_108 : 0 , V_109 ;
V_109 = ( V_110 << 8 | V_344 ) ;
V_104 = F_50 ( V_2 , V_102 , V_86 , V_109 , sizeof( * V_106 ) , V_107 ) ;
if ( V_104 == NULL )
goto V_112;
V_106 = F_51 ( V_104 ) ;
V_106 -> V_113 = V_259 ;
V_106 -> V_114 = V_115 ;
V_106 -> V_116 = F_55 ( V_209 ) ;
if ( F_13 ( V_2 , V_345 , F_14 ( V_257 -> V_346 ) ) ||
F_13 ( V_2 , V_347 , F_14 ( V_257 -> V_348 ) ) ||
F_13 ( V_2 , V_349 , F_14 ( V_257 -> V_350 ) ) )
goto V_12;
F_56 ( V_2 , V_104 ) ;
return V_2 -> V_72 ;
V_12:
V_112:
F_57 ( V_2 , V_104 ) ;
return - 1 ;
}
static int
F_210 ( struct V_1 * V_2 , struct V_153 * V_154 )
{
int V_209 ;
struct V_130 * V_130 = F_81 ( V_2 -> V_156 ) ;
if ( V_154 -> args [ 0 ] == V_212 )
return 0 ;
for ( V_209 = V_154 -> args [ 0 ] ; V_209 < V_212 ; V_209 ++ ) {
const struct V_256 * V_257 ;
if ( ! F_118 ( V_209 ) )
continue;
V_257 = F_119 ( V_130 -> V_23 . V_285 , V_209 ) ;
if ( F_209 ( V_2 , F_88 ( V_154 -> V_2 ) . V_102 ,
V_154 -> V_104 -> V_172 ,
V_209 , V_257 ) < 0 )
break;
}
V_154 -> args [ 0 ] = V_209 ;
return V_2 -> V_72 ;
}
static int
F_211 ( struct V_191 * V_192 , struct V_1 * V_2 ,
const struct V_103 * V_104 ,
const struct V_8 * const V_181 [] )
{
if ( V_104 -> V_197 & V_198 ) {
struct V_199 V_200 = {
. V_201 = F_210 ,
} ;
return F_114 ( V_192 , V_2 , V_104 , & V_200 ) ;
}
return 0 ;
}
static int T_9 F_212 ( struct V_130 * V_130 )
{
#ifdef F_213
int V_7 ;
V_7 = F_214 ( V_130 , & V_351 ) ;
if ( V_7 < 0 ) {
F_215 ( L_5 ) ;
goto V_340;
}
V_7 = F_216 ( V_130 , & V_352 ) ;
if ( V_7 < 0 ) {
F_215 ( L_6 ) ;
goto V_353;
}
#endif
return 0 ;
#ifdef F_213
V_353:
F_217 ( V_130 , & V_351 ) ;
V_340:
return V_7 ;
#endif
}
static void F_218 ( struct V_130 * V_130 )
{
#ifdef F_213
F_219 ( V_130 , & V_352 ) ;
F_217 ( V_130 , & V_351 ) ;
#endif
}
static void T_10 F_220 ( struct V_354 * V_355 )
{
struct V_130 * V_130 ;
F_221 (net, net_exit_list, exit_list)
F_218 ( V_130 ) ;
}
static int T_11 F_222 ( void )
{
int V_7 ;
F_223 ( L_7 , V_114 ) ;
V_7 = F_224 ( & V_356 ) ;
if ( V_7 < 0 ) {
F_215 ( L_8 ) ;
goto V_340;
}
V_7 = F_224 ( & V_357 ) ;
if ( V_7 < 0 ) {
F_215 ( L_9 ) ;
goto V_358;
}
V_7 = F_225 ( & V_359 ) ;
if ( V_7 < 0 ) {
F_215 ( L_10 ) ;
goto V_360;
}
#ifdef F_226
F_136 ( V_361 , & V_362 ) ;
#endif
return 0 ;
V_360:
F_227 ( & V_357 ) ;
V_358:
F_227 ( & V_356 ) ;
V_340:
return V_7 ;
}
static void T_12 F_228 ( void )
{
F_223 ( L_11 ) ;
F_229 ( & V_359 ) ;
F_227 ( & V_357 ) ;
F_227 ( & V_356 ) ;
#ifdef F_226
F_136 ( V_361 , NULL ) ;
#endif
}
