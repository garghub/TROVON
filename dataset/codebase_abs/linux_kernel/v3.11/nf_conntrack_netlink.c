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
struct V_80 * V_81 ;
struct V_88 * V_89 = F_45 ( V_23 ) ;
if ( ! ( V_23 -> V_25 & V_90 ) || ! V_89 )
return 0 ;
V_81 = & V_89 -> V_91 [ V_92 ] ;
if ( F_43 ( V_2 , V_81 , V_93 ) == - 1 )
return - 1 ;
V_81 = & V_89 -> V_91 [ V_94 ] ;
if ( F_43 ( V_2 , V_81 , V_95 ) == - 1 )
return - 1 ;
return 0 ;
}
static inline int
F_46 ( struct V_1 * V_2 , const struct V_22 * V_23 )
{
if ( F_13 ( V_2 , V_96 , F_14 ( ( unsigned long ) V_23 ) ) )
goto V_12;
return 0 ;
V_12:
return - 1 ;
}
static inline int
F_47 ( struct V_1 * V_2 , const struct V_22 * V_23 )
{
if ( F_13 ( V_2 , V_97 , F_14 ( F_48 ( & V_23 -> V_98 . V_99 ) ) ) )
goto V_12;
return 0 ;
V_12:
return - 1 ;
}
static int
F_49 ( struct V_1 * V_2 , T_2 V_100 , T_2 V_91 , T_2 type ,
struct V_22 * V_23 )
{
struct V_101 * V_102 ;
struct V_103 * V_104 ;
struct V_8 * V_9 ;
unsigned int V_105 = V_100 ? V_106 : 0 , V_107 ;
V_107 = ( V_108 << 8 | V_109 ) ;
V_102 = F_50 ( V_2 , V_100 , V_91 , V_107 , sizeof( * V_104 ) , V_105 ) ;
if ( V_102 == NULL )
goto V_110;
V_104 = F_51 ( V_102 ) ;
V_104 -> V_111 = F_17 ( V_23 ) ;
V_104 -> V_112 = V_113 ;
V_104 -> V_114 = 0 ;
V_9 = F_2 ( V_2 , V_115 | V_11 ) ;
if ( ! V_9 )
goto V_12;
if ( F_7 ( V_2 , F_52 ( V_23 , V_92 ) ) < 0 )
goto V_12;
F_5 ( V_2 , V_9 ) ;
V_9 = F_2 ( V_2 , V_116 | V_11 ) ;
if ( ! V_9 )
goto V_12;
if ( F_7 ( V_2 , F_52 ( V_23 , V_94 ) ) < 0 )
goto V_12;
F_5 ( V_2 , V_9 ) ;
if ( F_53 ( V_23 ) &&
F_54 ( V_2 , V_117 , F_55 ( F_53 ( V_23 ) ) ) )
goto V_12;
if ( F_12 ( V_2 , V_23 ) < 0 ||
F_15 ( V_2 , V_23 ) < 0 ||
F_26 ( V_2 , V_23 , V_92 , type ) < 0 ||
F_26 ( V_2 , V_23 , V_94 , type ) < 0 ||
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
F_56 ( V_2 , V_102 ) ;
return V_2 -> V_67 ;
V_110:
V_12:
F_57 ( V_2 , V_102 ) ;
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
V_67 += V_18 -> V_118 ;
V_6 = F_10 ( F_17 ( V_23 ) , F_18 ( V_23 ) ) ;
V_67 += V_6 -> V_118 ;
F_11 () ;
return V_67 ;
}
static inline T_3
F_59 ( const struct V_22 * V_23 )
{
if ( ! F_60 ( V_23 , V_119 ) )
return 0 ;
return 2 * F_38 ( 0 )
+ 2 * F_38 ( sizeof( V_120 ) )
+ 2 * F_38 ( sizeof( V_120 ) )
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
if ( ! F_60 ( V_23 , V_121 ) )
return 0 ;
return F_38 ( 0 ) + 2 * F_38 ( sizeof( V_120 ) ) ;
#else
return 0 ;
#endif
}
static inline T_3
F_65 ( const struct V_22 * V_23 )
{
return F_66 ( sizeof( struct V_103 ) )
+ 3 * F_38 ( 0 )
+ 3 * F_38 ( 0 )
+ 3 * F_38 ( 0 )
+ 3 * F_38 ( sizeof( V_122 ) )
+ F_38 ( sizeof( V_123 ) )
+ F_38 ( sizeof( V_123 ) )
+ F_59 ( V_23 )
+ F_63 ( V_23 )
+ F_38 ( sizeof( V_123 ) )
+ F_38 ( 0 )
+ F_38 ( 0 )
+ F_38 ( V_124 )
+ F_61 ( V_23 )
#ifdef F_67
+ 2 * F_38 ( 0 )
+ 6 * F_38 ( sizeof( V_123 ) )
#endif
#ifdef F_68
+ F_38 ( sizeof( V_123 ) )
#endif
+ F_58 ( V_23 )
+ F_36 ( V_23 )
;
}
static int
F_69 ( unsigned int V_125 , struct V_126 * V_127 )
{
struct V_128 * V_128 ;
struct V_101 * V_102 ;
struct V_103 * V_104 ;
struct V_8 * V_9 ;
struct V_22 * V_23 = V_127 -> V_23 ;
struct V_1 * V_2 ;
unsigned int type ;
unsigned int V_105 = 0 , V_129 ;
int V_130 ;
if ( F_70 ( V_23 ) )
return 0 ;
if ( V_125 & ( 1 << V_131 ) ) {
type = V_132 ;
V_129 = V_133 ;
} else if ( V_125 & ( ( 1 << V_134 ) | ( 1 << V_135 ) ) ) {
type = V_109 ;
V_105 = V_136 | V_137 ;
V_129 = V_138 ;
} else if ( V_125 ) {
type = V_109 ;
V_129 = V_139 ;
} else
return 0 ;
V_128 = F_71 ( V_23 ) ;
if ( ! V_127 -> V_140 && ! F_72 ( V_128 , V_129 ) )
return 0 ;
V_2 = F_73 ( F_65 ( V_23 ) , V_141 ) ;
if ( V_2 == NULL )
goto V_142;
type |= V_108 << 8 ;
V_102 = F_50 ( V_2 , V_127 -> V_100 , 0 , type , sizeof( * V_104 ) , V_105 ) ;
if ( V_102 == NULL )
goto V_110;
V_104 = F_51 ( V_102 ) ;
V_104 -> V_111 = F_17 ( V_23 ) ;
V_104 -> V_112 = V_113 ;
V_104 -> V_114 = 0 ;
F_8 () ;
V_9 = F_2 ( V_2 , V_115 | V_11 ) ;
if ( ! V_9 )
goto V_12;
if ( F_7 ( V_2 , F_52 ( V_23 , V_92 ) ) < 0 )
goto V_12;
F_5 ( V_2 , V_9 ) ;
V_9 = F_2 ( V_2 , V_116 | V_11 ) ;
if ( ! V_9 )
goto V_12;
if ( F_7 ( V_2 , F_52 ( V_23 , V_94 ) ) < 0 )
goto V_12;
F_5 ( V_2 , V_9 ) ;
if ( F_53 ( V_23 ) &&
F_54 ( V_2 , V_117 , F_55 ( F_53 ( V_23 ) ) ) )
goto V_12;
if ( F_46 ( V_2 , V_23 ) < 0 )
goto V_12;
if ( F_12 ( V_2 , V_23 ) < 0 )
goto V_12;
if ( V_125 & ( 1 << V_131 ) ) {
if ( F_26 ( V_2 , V_23 ,
V_92 , type ) < 0 ||
F_26 ( V_2 , V_23 ,
V_94 , type ) < 0 ||
F_30 ( V_2 , V_23 ) < 0 )
goto V_12;
} else {
if ( F_15 ( V_2 , V_23 ) < 0 )
goto V_12;
if ( V_125 & ( 1 << V_143 )
&& F_16 ( V_2 , V_23 ) < 0 )
goto V_12;
if ( ( V_125 & ( 1 << V_144 ) || F_20 ( V_23 ) )
&& F_19 ( V_2 , V_23 ) < 0 )
goto V_12;
#ifdef F_62
if ( ( V_125 & ( 1 << V_145 ) || V_23 -> V_69 )
&& F_33 ( V_2 , V_23 ) < 0 )
goto V_12;
#endif
if ( V_125 & ( 1 << V_146 ) &&
F_39 ( V_2 , V_23 ) < 0 )
goto V_12;
if ( V_125 & ( 1 << V_135 ) &&
F_41 ( V_2 , V_23 ) < 0 )
goto V_12;
if ( V_125 & ( 1 << V_147 ) &&
F_44 ( V_2 , V_23 ) < 0 )
goto V_12;
}
#ifdef F_68
if ( ( V_125 & ( 1 << V_148 ) || V_23 -> V_65 )
&& F_32 ( V_2 , V_23 ) < 0 )
goto V_12;
#endif
F_11 () ;
F_56 ( V_2 , V_102 ) ;
V_130 = F_74 ( V_2 , V_128 , V_127 -> V_100 , V_129 , V_127 -> V_140 ,
V_141 ) ;
if ( V_130 == - V_149 || V_130 == - V_150 )
return - V_149 ;
return 0 ;
V_12:
F_11 () ;
F_57 ( V_2 , V_102 ) ;
V_110:
F_75 ( V_2 ) ;
V_142:
if ( F_76 ( V_128 , 0 , V_129 , - V_149 ) > 0 )
return - V_149 ;
return 0 ;
}
static int F_77 ( struct V_151 * V_152 )
{
if ( V_152 -> args [ 1 ] )
F_78 ( (struct V_22 * ) V_152 -> args [ 1 ] ) ;
if ( V_152 -> V_153 )
F_79 ( V_152 -> V_153 ) ;
return 0 ;
}
static int
F_80 ( struct V_1 * V_2 , struct V_151 * V_152 )
{
struct V_128 * V_128 = F_81 ( V_2 -> V_154 ) ;
struct V_22 * V_23 , * V_155 ;
struct V_156 * V_157 ;
struct V_158 * V_159 ;
struct V_103 * V_104 = F_51 ( V_152 -> V_102 ) ;
V_122 V_18 = V_104 -> V_111 ;
int V_160 ;
#ifdef F_68
const struct V_161 * V_162 = V_152 -> V_153 ;
#endif
F_82 ( & V_163 ) ;
V_155 = (struct V_22 * ) V_152 -> args [ 1 ] ;
for (; V_152 -> args [ 0 ] < V_128 -> V_23 . V_164 ; V_152 -> args [ 0 ] ++ ) {
V_165:
F_83 (h, n, &net->ct.hash[cb->args[0]],
hnnode) {
if ( F_84 ( V_157 ) != V_92 )
continue;
V_23 = F_85 ( V_157 ) ;
if ( V_18 && F_17 ( V_23 ) != V_18 )
continue;
if ( V_152 -> args [ 1 ] ) {
if ( V_23 != V_155 )
continue;
V_152 -> args [ 1 ] = 0 ;
}
#ifdef F_68
if ( V_162 && ! ( ( V_23 -> V_65 & V_162 -> V_65 . V_166 ) ==
V_162 -> V_65 . V_167 ) ) {
continue;
}
#endif
F_8 () ;
V_160 =
F_49 ( V_2 , F_86 ( V_152 -> V_2 ) . V_100 ,
V_152 -> V_102 -> V_168 ,
F_87 ( V_152 -> V_102 -> V_169 ) ,
V_23 ) ;
F_11 () ;
if ( V_160 < 0 ) {
F_88 ( & V_23 -> V_98 ) ;
V_152 -> args [ 1 ] = ( unsigned long ) V_23 ;
goto V_39;
}
}
if ( V_152 -> args [ 1 ] ) {
V_152 -> args [ 1 ] = 0 ;
goto V_165;
}
}
V_39:
F_89 ( & V_163 ) ;
if ( V_155 )
F_78 ( V_155 ) ;
return V_2 -> V_67 ;
}
static inline int
F_90 ( struct V_8 * V_170 , struct V_3 * V_4 )
{
struct V_8 * V_171 [ V_172 + 1 ] ;
struct V_17 * V_18 ;
int V_7 = 0 ;
V_7 = F_91 ( V_171 , V_172 , V_170 , NULL ) ;
if ( V_7 < 0 )
return V_7 ;
F_8 () ;
V_18 = F_9 ( V_4 -> V_20 . V_21 ) ;
if ( F_4 ( V_18 -> V_173 ) ) {
V_7 = F_92 ( V_170 , V_172 ,
V_18 -> V_174 ) ;
if ( V_7 == 0 )
V_7 = V_18 -> V_173 ( V_171 , V_4 ) ;
}
F_11 () ;
return V_7 ;
}
static inline int
F_93 ( struct V_8 * V_170 ,
struct V_3 * V_4 )
{
struct V_8 * V_171 [ V_175 + 1 ] ;
struct V_5 * V_6 ;
int V_7 = 0 ;
V_7 = F_91 ( V_171 , V_175 , V_170 , V_176 ) ;
if ( V_7 < 0 )
return V_7 ;
if ( ! V_171 [ V_13 ] )
return - V_177 ;
V_4 -> V_14 . V_15 = F_94 ( V_171 [ V_13 ] ) ;
F_8 () ;
V_6 = F_10 ( V_4 -> V_20 . V_21 , V_4 -> V_14 . V_15 ) ;
if ( F_4 ( V_6 -> V_173 ) ) {
V_7 = F_92 ( V_170 , V_175 ,
V_6 -> V_174 ) ;
if ( V_7 == 0 )
V_7 = V_6 -> V_173 ( V_171 , V_4 ) ;
}
F_11 () ;
return V_7 ;
}
static int
F_95 ( const struct V_8 * const V_178 [] ,
struct V_3 * V_4 ,
enum V_47 type , V_122 V_21 )
{
struct V_8 * V_171 [ V_179 + 1 ] ;
int V_130 ;
memset ( V_4 , 0 , sizeof( * V_4 ) ) ;
V_130 = F_91 ( V_171 , V_179 , V_178 [ type ] , V_180 ) ;
if ( V_130 < 0 )
return V_130 ;
if ( ! V_171 [ V_19 ] )
return - V_177 ;
V_4 -> V_20 . V_21 = V_21 ;
V_130 = F_90 ( V_171 [ V_19 ] , V_4 ) ;
if ( V_130 < 0 )
return V_130 ;
if ( ! V_171 [ V_10 ] )
return - V_177 ;
V_130 = F_93 ( V_171 [ V_10 ] , V_4 ) ;
if ( V_130 < 0 )
return V_130 ;
if ( type == V_116 )
V_4 -> V_14 . V_46 = V_94 ;
else
V_4 -> V_14 . V_46 = V_92 ;
return 0 ;
}
static int
F_96 ( const struct V_8 * V_170 , T_4 * V_181 )
{
if ( V_170 )
#ifdef F_97
* V_181 = F_98 ( F_99 ( V_170 ) ) ;
#else
return - V_182 ;
#endif
else
* V_181 = 0 ;
return 0 ;
}
static inline int
F_100 ( const struct V_8 * V_170 , char * * V_183 ,
struct V_8 * * V_184 )
{
int V_130 ;
struct V_8 * V_171 [ V_185 + 1 ] ;
V_130 = F_91 ( V_171 , V_185 , V_170 , V_186 ) ;
if ( V_130 < 0 )
return V_130 ;
if ( ! V_171 [ V_41 ] )
return - V_177 ;
* V_183 = F_101 ( V_171 [ V_41 ] ) ;
if ( V_171 [ V_187 ] )
* V_184 = V_171 [ V_187 ] ;
return 0 ;
}
static int
F_102 ( struct V_188 * V_189 , struct V_1 * V_2 ,
const struct V_101 * V_102 ,
const struct V_8 * const V_178 [] )
{
struct V_128 * V_128 = F_81 ( V_189 ) ;
struct V_156 * V_157 ;
struct V_3 V_4 ;
struct V_22 * V_23 ;
struct V_103 * V_104 = F_51 ( V_102 ) ;
V_122 V_190 = V_104 -> V_111 ;
T_4 V_181 ;
int V_130 ;
V_130 = F_96 ( V_178 [ V_117 ] , & V_181 ) ;
if ( V_130 < 0 )
return V_130 ;
if ( V_178 [ V_115 ] )
V_130 = F_95 ( V_178 , & V_4 , V_115 , V_190 ) ;
else if ( V_178 [ V_116 ] )
V_130 = F_95 ( V_178 , & V_4 , V_116 , V_190 ) ;
else {
F_103 ( V_128 ,
F_86 ( V_2 ) . V_100 ,
F_104 ( V_102 ) ) ;
return 0 ;
}
if ( V_130 < 0 )
return V_130 ;
V_157 = F_105 ( V_128 , V_181 , & V_4 ) ;
if ( ! V_157 )
return - V_191 ;
V_23 = F_85 ( V_157 ) ;
if ( V_178 [ V_96 ] ) {
V_123 V_192 = F_106 ( F_107 ( V_178 [ V_96 ] ) ) ;
if ( V_192 != ( T_2 ) ( unsigned long ) V_23 ) {
F_78 ( V_23 ) ;
return - V_191 ;
}
}
if ( F_108 ( & V_23 -> V_26 ) ) {
if ( F_109 ( V_131 , V_23 ,
F_86 ( V_2 ) . V_100 ,
F_104 ( V_102 ) ) < 0 ) {
F_110 ( V_23 ) ;
F_111 ( V_23 ) ;
F_78 ( V_23 ) ;
return 0 ;
}
F_112 ( V_193 , & V_23 -> V_25 ) ;
F_110 ( V_23 ) ;
F_78 ( V_23 ) ;
}
F_78 ( V_23 ) ;
return 0 ;
}
static int
F_113 ( struct V_188 * V_189 , struct V_1 * V_2 ,
const struct V_101 * V_102 ,
const struct V_8 * const V_178 [] )
{
struct V_128 * V_128 = F_81 ( V_189 ) ;
struct V_156 * V_157 ;
struct V_3 V_4 ;
struct V_22 * V_23 ;
struct V_1 * V_194 = NULL ;
struct V_103 * V_104 = F_51 ( V_102 ) ;
V_122 V_190 = V_104 -> V_111 ;
T_4 V_181 ;
int V_130 ;
if ( V_102 -> V_195 & V_196 ) {
struct V_197 V_198 = {
. V_199 = F_80 ,
. V_200 = F_77 ,
} ;
#ifdef F_68
if ( V_178 [ V_64 ] && V_178 [ V_201 ] ) {
struct V_161 * V_162 ;
V_162 = F_114 ( sizeof( struct V_161 ) ,
V_141 ) ;
if ( V_162 == NULL )
return - V_202 ;
V_162 -> V_65 . V_167 = F_106 ( F_107 ( V_178 [ V_64 ] ) ) ;
V_162 -> V_65 . V_166 =
F_106 ( F_107 ( V_178 [ V_201 ] ) ) ;
V_198 . V_153 = V_162 ;
}
#endif
return F_115 ( V_189 , V_2 , V_102 , & V_198 ) ;
}
V_130 = F_96 ( V_178 [ V_117 ] , & V_181 ) ;
if ( V_130 < 0 )
return V_130 ;
if ( V_178 [ V_115 ] )
V_130 = F_95 ( V_178 , & V_4 , V_115 , V_190 ) ;
else if ( V_178 [ V_116 ] )
V_130 = F_95 ( V_178 , & V_4 , V_116 , V_190 ) ;
else
return - V_177 ;
if ( V_130 < 0 )
return V_130 ;
V_157 = F_105 ( V_128 , V_181 , & V_4 ) ;
if ( ! V_157 )
return - V_191 ;
V_23 = F_85 ( V_157 ) ;
V_130 = - V_202 ;
V_194 = F_73 ( V_203 , V_204 ) ;
if ( V_194 == NULL ) {
F_78 ( V_23 ) ;
return - V_202 ;
}
F_8 () ;
V_130 = F_49 ( V_194 , F_86 ( V_2 ) . V_100 , V_102 -> V_168 ,
F_87 ( V_102 -> V_169 ) , V_23 ) ;
F_11 () ;
F_78 ( V_23 ) ;
if ( V_130 <= 0 )
goto free;
V_130 = F_116 ( V_189 , V_194 , F_86 ( V_2 ) . V_100 , V_205 ) ;
if ( V_130 < 0 )
goto V_39;
return 0 ;
free:
F_75 ( V_194 ) ;
V_39:
return V_130 == - V_150 ? - V_149 : V_130 ;
}
static int F_117 ( struct V_151 * V_152 )
{
if ( V_152 -> args [ 1 ] )
F_78 ( (struct V_22 * ) V_152 -> args [ 1 ] ) ;
return 0 ;
}
static int
F_118 ( struct V_1 * V_2 , struct V_151 * V_152 ,
struct V_206 * V_207 )
{
struct V_22 * V_23 , * V_155 ;
struct V_156 * V_157 ;
struct V_158 * V_159 ;
struct V_103 * V_104 = F_51 ( V_152 -> V_102 ) ;
V_122 V_18 = V_104 -> V_111 ;
int V_160 ;
if ( V_152 -> args [ 2 ] )
return 0 ;
F_82 ( & V_163 ) ;
V_155 = (struct V_22 * ) V_152 -> args [ 1 ] ;
V_165:
F_83 (h, n, list, hnnode) {
V_23 = F_85 ( V_157 ) ;
if ( V_18 && F_17 ( V_23 ) != V_18 )
continue;
if ( V_152 -> args [ 1 ] ) {
if ( V_23 != V_155 )
continue;
V_152 -> args [ 1 ] = 0 ;
}
F_8 () ;
V_160 = F_49 ( V_2 , F_86 ( V_152 -> V_2 ) . V_100 ,
V_152 -> V_102 -> V_168 ,
F_87 ( V_152 -> V_102 -> V_169 ) ,
V_23 ) ;
F_11 () ;
if ( V_160 < 0 ) {
F_88 ( & V_23 -> V_98 ) ;
V_152 -> args [ 1 ] = ( unsigned long ) V_23 ;
goto V_39;
}
}
if ( V_152 -> args [ 1 ] ) {
V_152 -> args [ 1 ] = 0 ;
goto V_165;
} else
V_152 -> args [ 2 ] = 1 ;
V_39:
F_89 ( & V_163 ) ;
if ( V_155 )
F_78 ( V_155 ) ;
return V_2 -> V_67 ;
}
static int
F_119 ( struct V_1 * V_2 , struct V_151 * V_152 )
{
struct V_128 * V_128 = F_81 ( V_2 -> V_154 ) ;
return F_118 ( V_2 , V_152 , & V_128 -> V_23 . V_208 ) ;
}
static int
F_120 ( struct V_188 * V_189 , struct V_1 * V_2 ,
const struct V_101 * V_102 ,
const struct V_8 * const V_178 [] )
{
if ( V_102 -> V_195 & V_196 ) {
struct V_197 V_198 = {
. V_199 = F_119 ,
. V_200 = F_117 ,
} ;
return F_115 ( V_189 , V_2 , V_102 , & V_198 ) ;
}
return - V_182 ;
}
static int
F_121 ( struct V_1 * V_2 , struct V_151 * V_152 )
{
struct V_128 * V_128 = F_81 ( V_2 -> V_154 ) ;
return F_118 ( V_2 , V_152 , & V_128 -> V_23 . V_209 ) ;
}
static int
F_122 ( struct V_188 * V_189 , struct V_1 * V_2 ,
const struct V_101 * V_102 ,
const struct V_8 * const V_178 [] )
{
if ( V_102 -> V_195 & V_196 ) {
struct V_197 V_198 = {
. V_199 = F_121 ,
. V_200 = F_117 ,
} ;
return F_115 ( V_189 , V_2 , V_102 , & V_198 ) ;
}
return - V_182 ;
}
static int
F_123 ( struct V_22 * V_23 ,
enum V_210 V_211 ,
const struct V_8 * V_170 )
{
F_124 (nfnetlink_parse_nat_setup_hook) V_212 ;
int V_130 ;
V_212 = F_21 ( V_213 ) ;
if ( ! V_212 ) {
#ifdef F_125
F_11 () ;
F_126 ( V_108 ) ;
if ( F_127 ( L_1 ) < 0 ) {
F_128 ( V_108 ) ;
F_8 () ;
return - V_182 ;
}
F_128 ( V_108 ) ;
F_8 () ;
if ( V_213 )
return - V_150 ;
#endif
return - V_182 ;
}
V_130 = V_212 ( V_23 , V_211 , V_170 ) ;
if ( V_130 == - V_150 ) {
#ifdef F_125
F_11 () ;
F_126 ( V_108 ) ;
if ( F_127 ( L_2 , F_17 ( V_23 ) ) < 0 ) {
F_128 ( V_108 ) ;
F_8 () ;
return - V_182 ;
}
F_128 ( V_108 ) ;
F_8 () ;
#else
V_130 = - V_182 ;
#endif
}
return V_130 ;
}
static int
F_129 ( struct V_22 * V_23 , const struct V_8 * const V_178 [] )
{
unsigned long V_214 ;
unsigned int V_25 = F_106 ( F_107 ( V_178 [ V_24 ] ) ) ;
V_214 = V_23 -> V_25 ^ V_25 ;
if ( V_214 & ( V_78 | V_215 | V_216 ) )
return - V_217 ;
if ( V_214 & V_218 && ! ( V_25 & V_218 ) )
return - V_217 ;
if ( V_214 & V_219 && ! ( V_25 & V_219 ) )
return - V_217 ;
V_23 -> V_25 |= V_25 & ~ ( V_220 | V_221 ) ;
return 0 ;
}
static int
F_130 ( struct V_22 * V_23 , const struct V_8 * const V_178 [] )
{
#ifdef F_67
int V_7 ;
if ( V_178 [ V_222 ] ) {
V_7 = F_123 ( V_23 ,
V_223 ,
V_178 [ V_222 ] ) ;
if ( V_7 < 0 )
return V_7 ;
}
if ( V_178 [ V_224 ] ) {
V_7 = F_123 ( V_23 ,
V_225 ,
V_178 [ V_224 ] ) ;
if ( V_7 < 0 )
return V_7 ;
}
return 0 ;
#else
return - V_182 ;
#endif
}
static inline int
F_131 ( struct V_22 * V_23 , const struct V_8 * const V_178 [] )
{
struct V_37 * V_38 ;
struct V_35 * V_36 = F_20 ( V_23 ) ;
char * V_226 = NULL ;
struct V_8 * V_184 = NULL ;
int V_130 ;
if ( V_23 -> V_227 )
return - V_217 ;
V_130 = F_100 ( V_178 [ V_40 ] , & V_226 , & V_184 ) ;
if ( V_130 < 0 )
return V_130 ;
if ( ! strcmp ( V_226 , L_3 ) ) {
if ( V_36 && V_36 -> V_38 ) {
F_132 ( V_23 ) ;
F_133 ( V_36 -> V_38 , NULL ) ;
}
return 0 ;
}
V_38 = F_134 ( V_226 , F_17 ( V_23 ) ,
F_18 ( V_23 ) ) ;
if ( V_38 == NULL ) {
#ifdef F_125
F_89 ( & V_163 ) ;
if ( F_127 ( L_4 , V_226 ) < 0 ) {
F_82 ( & V_163 ) ;
return - V_182 ;
}
F_82 ( & V_163 ) ;
V_38 = F_134 ( V_226 , F_17 ( V_23 ) ,
F_18 ( V_23 ) ) ;
if ( V_38 )
return - V_150 ;
#endif
return - V_182 ;
}
if ( V_36 ) {
if ( V_36 -> V_38 == V_38 ) {
if ( V_38 -> V_228 )
V_38 -> V_228 ( V_184 , V_23 ) ;
return 0 ;
} else
return - V_217 ;
}
return - V_182 ;
}
static inline int
F_135 ( struct V_22 * V_23 , const struct V_8 * const V_178 [] )
{
V_123 V_26 = F_106 ( F_107 ( V_178 [ V_30 ] ) ) ;
if ( ! F_108 ( & V_23 -> V_26 ) )
return - V_229 ;
V_23 -> V_26 . V_27 = V_28 + V_26 * V_29 ;
F_136 ( & V_23 -> V_26 ) ;
return 0 ;
}
static inline int
F_137 ( struct V_22 * V_23 , const struct V_8 * const V_178 [] )
{
const struct V_8 * V_170 = V_178 [ V_33 ] ;
struct V_8 * V_171 [ V_230 + 1 ] ;
struct V_5 * V_6 ;
int V_130 = 0 ;
V_130 = F_91 ( V_171 , V_230 , V_170 , V_231 ) ;
if ( V_130 < 0 )
return V_130 ;
F_8 () ;
V_6 = F_10 ( F_17 ( V_23 ) , F_18 ( V_23 ) ) ;
if ( V_6 -> V_228 )
V_130 = V_6 -> V_228 ( V_171 , V_23 ) ;
F_11 () ;
return V_130 ;
}
static inline int
F_138 ( struct V_80 * V_81 , const struct V_8 * const V_170 )
{
int V_130 ;
struct V_8 * V_178 [ V_232 + 1 ] ;
V_130 = F_91 ( V_178 , V_232 , V_170 , V_233 ) ;
if ( V_130 < 0 )
return V_130 ;
if ( ! V_178 [ V_82 ] )
return - V_177 ;
V_81 -> V_83 =
F_106 ( F_107 ( V_178 [ V_82 ] ) ) ;
if ( ! V_178 [ V_84 ] )
return - V_177 ;
V_81 -> V_85 =
F_106 ( F_107 ( V_178 [ V_84 ] ) ) ;
if ( ! V_178 [ V_86 ] )
return - V_177 ;
V_81 -> V_87 =
F_106 ( F_107 ( V_178 [ V_86 ] ) ) ;
return 0 ;
}
static int
F_139 ( struct V_22 * V_23 ,
const struct V_8 * const V_178 [] )
{
int V_7 = 0 ;
struct V_88 * V_89 = F_45 ( V_23 ) ;
if ( ! V_89 )
return 0 ;
if ( V_178 [ V_93 ] ) {
V_7 = F_138 ( & V_89 -> V_91 [ V_92 ] ,
V_178 [ V_93 ] ) ;
if ( V_7 < 0 )
return V_7 ;
V_23 -> V_25 |= V_90 ;
}
if ( V_178 [ V_95 ] ) {
V_7 = F_138 ( & V_89 -> V_91 [ V_94 ] ,
V_178 [ V_95 ] ) ;
if ( V_7 < 0 )
return V_7 ;
V_23 -> V_25 |= V_90 ;
}
return 0 ;
}
static int
F_140 ( struct V_22 * V_23 , const struct V_8 * const V_178 [] )
{
#ifdef F_141
T_3 V_67 = F_142 ( V_178 [ V_77 ] ) ;
const void * V_166 = V_178 [ V_234 ] ;
if ( V_67 & ( sizeof( T_2 ) - 1 ) )
return - V_177 ;
if ( V_166 ) {
if ( F_142 ( V_178 [ V_234 ] ) == 0 ||
F_142 ( V_178 [ V_234 ] ) != V_67 )
return - V_177 ;
V_166 = F_101 ( V_178 [ V_234 ] ) ;
}
V_67 /= sizeof( T_2 ) ;
return F_143 ( V_23 , F_101 ( V_178 [ V_77 ] ) , V_166 , V_67 ) ;
#else
return - V_182 ;
#endif
}
static int
F_144 ( struct V_22 * V_23 ,
const struct V_8 * const V_178 [] )
{
int V_130 ;
if ( V_178 [ V_224 ] || V_178 [ V_222 ] || V_178 [ V_79 ] )
return - V_182 ;
if ( V_178 [ V_40 ] ) {
V_130 = F_131 ( V_23 , V_178 ) ;
if ( V_130 < 0 )
return V_130 ;
}
if ( V_178 [ V_30 ] ) {
V_130 = F_135 ( V_23 , V_178 ) ;
if ( V_130 < 0 )
return V_130 ;
}
if ( V_178 [ V_24 ] ) {
V_130 = F_129 ( V_23 , V_178 ) ;
if ( V_130 < 0 )
return V_130 ;
}
if ( V_178 [ V_33 ] ) {
V_130 = F_137 ( V_23 , V_178 ) ;
if ( V_130 < 0 )
return V_130 ;
}
#if F_145 ( F_68 )
if ( V_178 [ V_64 ] )
V_23 -> V_65 = F_106 ( F_107 ( V_178 [ V_64 ] ) ) ;
#endif
#ifdef F_67
if ( V_178 [ V_93 ] || V_178 [ V_95 ] ) {
V_130 = F_139 ( V_23 , V_178 ) ;
if ( V_130 < 0 )
return V_130 ;
}
#endif
if ( V_178 [ V_77 ] ) {
V_130 = F_140 ( V_23 , V_178 ) ;
if ( V_130 < 0 )
return V_130 ;
}
return 0 ;
}
static struct V_22 *
F_146 ( struct V_128 * V_128 , T_4 V_181 ,
const struct V_8 * const V_178 [] ,
struct V_3 * V_235 ,
struct V_3 * V_236 ,
T_5 V_190 )
{
struct V_22 * V_23 ;
int V_130 = - V_177 ;
struct V_37 * V_38 ;
struct V_57 * V_58 ;
V_23 = F_147 ( V_128 , V_181 , V_235 , V_236 , V_141 ) ;
if ( F_148 ( V_23 ) )
return F_149 ( - V_202 ) ;
if ( ! V_178 [ V_30 ] )
goto V_237;
V_23 -> V_26 . V_27 = F_106 ( F_107 ( V_178 [ V_30 ] ) ) ;
V_23 -> V_26 . V_27 = V_28 + V_23 -> V_26 . V_27 * V_29 ;
F_8 () ;
if ( V_178 [ V_40 ] ) {
char * V_226 = NULL ;
struct V_8 * V_184 = NULL ;
V_130 = F_100 ( V_178 [ V_40 ] , & V_226 , & V_184 ) ;
if ( V_130 < 0 )
goto V_238;
V_38 = F_134 ( V_226 , F_17 ( V_23 ) ,
F_18 ( V_23 ) ) ;
if ( V_38 == NULL ) {
F_11 () ;
#ifdef F_125
if ( F_127 ( L_4 , V_226 ) < 0 ) {
V_130 = - V_182 ;
goto V_237;
}
F_8 () ;
V_38 = F_134 ( V_226 ,
F_17 ( V_23 ) ,
F_18 ( V_23 ) ) ;
if ( V_38 ) {
V_130 = - V_150 ;
goto V_238;
}
F_11 () ;
#endif
V_130 = - V_182 ;
goto V_237;
} else {
struct V_35 * V_36 ;
V_36 = F_150 ( V_23 , V_38 , V_141 ) ;
if ( V_36 == NULL ) {
V_130 = - V_202 ;
goto V_238;
}
if ( V_38 -> V_228 )
V_38 -> V_228 ( V_184 , V_23 ) ;
F_133 ( V_36 -> V_38 , V_38 ) ;
}
} else {
V_130 = F_151 ( V_23 , NULL , V_141 ) ;
if ( V_130 < 0 )
goto V_238;
}
if ( V_178 [ V_224 ] || V_178 [ V_222 ] ) {
V_130 = F_130 ( V_23 , V_178 ) ;
if ( V_130 < 0 )
goto V_238;
}
F_152 ( V_23 , V_141 ) ;
F_153 ( V_23 , V_141 ) ;
F_154 ( V_23 , 0 , 0 , V_141 ) ;
F_155 ( V_23 ) ;
V_23 -> V_25 |= V_215 ;
if ( V_178 [ V_24 ] ) {
V_130 = F_129 ( V_23 , V_178 ) ;
if ( V_130 < 0 )
goto V_238;
}
#ifdef F_67
if ( V_178 [ V_93 ] || V_178 [ V_95 ] ) {
V_130 = F_139 ( V_23 , V_178 ) ;
if ( V_130 < 0 )
goto V_238;
}
#endif
memset ( & V_23 -> V_239 , 0 , sizeof( V_23 -> V_239 ) ) ;
if ( V_178 [ V_33 ] ) {
V_130 = F_137 ( V_23 , V_178 ) ;
if ( V_130 < 0 )
goto V_238;
}
#if F_145 ( F_68 )
if ( V_178 [ V_64 ] )
V_23 -> V_65 = F_106 ( F_107 ( V_178 [ V_64 ] ) ) ;
#endif
if ( V_178 [ V_79 ] ) {
struct V_3 V_227 ;
struct V_156 * V_240 ;
struct V_22 * V_241 ;
V_130 = F_95 ( V_178 , & V_227 , V_79 , V_190 ) ;
if ( V_130 < 0 )
goto V_238;
V_240 = F_105 ( V_128 , V_181 , & V_227 ) ;
if ( V_240 == NULL ) {
V_130 = - V_191 ;
goto V_238;
}
V_241 = F_85 ( V_240 ) ;
F_156 ( V_242 , & V_23 -> V_25 ) ;
V_23 -> V_227 = V_241 ;
}
V_58 = F_31 ( V_23 ) ;
if ( V_58 )
V_58 -> V_61 = F_157 ( F_158 () ) ;
V_130 = F_159 ( V_23 ) ;
if ( V_130 < 0 )
goto V_238;
F_11 () ;
return V_23 ;
V_238:
F_11 () ;
V_237:
F_160 ( V_23 ) ;
return F_149 ( V_130 ) ;
}
static int
F_161 ( struct V_188 * V_189 , struct V_1 * V_2 ,
const struct V_101 * V_102 ,
const struct V_8 * const V_178 [] )
{
struct V_128 * V_128 = F_81 ( V_189 ) ;
struct V_3 V_235 , V_236 ;
struct V_156 * V_157 = NULL ;
struct V_103 * V_104 = F_51 ( V_102 ) ;
struct V_22 * V_23 ;
V_122 V_190 = V_104 -> V_111 ;
T_4 V_181 ;
int V_130 ;
V_130 = F_96 ( V_178 [ V_117 ] , & V_181 ) ;
if ( V_130 < 0 )
return V_130 ;
if ( V_178 [ V_115 ] ) {
V_130 = F_95 ( V_178 , & V_235 , V_115 , V_190 ) ;
if ( V_130 < 0 )
return V_130 ;
}
if ( V_178 [ V_116 ] ) {
V_130 = F_95 ( V_178 , & V_236 , V_116 , V_190 ) ;
if ( V_130 < 0 )
return V_130 ;
}
if ( V_178 [ V_115 ] )
V_157 = F_105 ( V_128 , V_181 , & V_235 ) ;
else if ( V_178 [ V_116 ] )
V_157 = F_105 ( V_128 , V_181 , & V_236 ) ;
if ( V_157 == NULL ) {
V_130 = - V_191 ;
if ( V_102 -> V_195 & V_136 ) {
enum V_243 V_125 ;
if ( ! V_178 [ V_115 ] || ! V_178 [ V_116 ] )
return - V_177 ;
V_23 = F_146 ( V_128 , V_181 , V_178 , & V_235 ,
& V_236 , V_190 ) ;
if ( F_148 ( V_23 ) )
return F_162 ( V_23 ) ;
V_130 = 0 ;
if ( F_163 ( V_242 , & V_23 -> V_25 ) )
V_125 = V_135 ;
else
V_125 = V_134 ;
if ( V_178 [ V_77 ] &&
F_140 ( V_23 , V_178 ) == 0 )
V_125 |= ( 1 << V_146 ) ;
F_164 ( ( 1 << V_244 ) |
( 1 << V_245 ) |
( 1 << V_144 ) |
( 1 << V_143 ) |
( 1 << V_147 ) |
( 1 << V_148 ) | V_125 ,
V_23 , F_86 ( V_2 ) . V_100 ,
F_104 ( V_102 ) ) ;
F_78 ( V_23 ) ;
}
return V_130 ;
}
V_130 = - V_246 ;
V_23 = F_85 ( V_157 ) ;
if ( ! ( V_102 -> V_195 & V_137 ) ) {
F_82 ( & V_163 ) ;
V_130 = F_144 ( V_23 , V_178 ) ;
F_89 ( & V_163 ) ;
if ( V_130 == 0 ) {
F_164 ( ( 1 << V_244 ) |
( 1 << V_245 ) |
( 1 << V_144 ) |
( 1 << V_146 ) |
( 1 << V_143 ) |
( 1 << V_147 ) |
( 1 << V_148 ) ,
V_23 , F_86 ( V_2 ) . V_100 ,
F_104 ( V_102 ) ) ;
}
}
F_78 ( V_23 ) ;
return V_130 ;
}
static int
F_165 ( struct V_1 * V_2 , T_2 V_100 , T_2 V_91 ,
T_6 V_247 , const struct V_248 * V_249 )
{
struct V_101 * V_102 ;
struct V_103 * V_104 ;
unsigned int V_105 = V_100 ? V_106 : 0 , V_107 ;
V_107 = ( V_108 << 8 | V_250 ) ;
V_102 = F_50 ( V_2 , V_100 , V_91 , V_107 , sizeof( * V_104 ) , V_105 ) ;
if ( V_102 == NULL )
goto V_110;
V_104 = F_51 ( V_102 ) ;
V_104 -> V_111 = V_251 ;
V_104 -> V_112 = V_113 ;
V_104 -> V_114 = F_55 ( V_247 ) ;
if ( F_13 ( V_2 , V_252 , F_14 ( V_249 -> V_253 ) ) ||
F_13 ( V_2 , V_254 , F_14 ( V_249 -> V_255 ) ) ||
F_13 ( V_2 , V_256 , F_14 ( V_249 -> V_257 ) ) ||
F_13 ( V_2 , V_258 , F_14 ( V_249 -> V_259 ) ) ||
F_13 ( V_2 , V_260 , F_14 ( V_249 -> V_261 ) ) ||
F_13 ( V_2 , V_262 , F_14 ( V_249 -> V_263 ) ) ||
F_13 ( V_2 , V_264 , F_14 ( V_249 -> V_265 ) ) ||
F_13 ( V_2 , V_266 , F_14 ( V_249 -> V_267 ) ) ||
F_13 ( V_2 , V_268 ,
F_14 ( V_249 -> V_269 ) ) ||
F_13 ( V_2 , V_270 , F_14 ( V_249 -> V_271 ) ) ||
F_13 ( V_2 , V_272 , F_14 ( V_249 -> V_273 ) ) ||
F_13 ( V_2 , V_274 , F_14 ( V_249 -> error ) ) ||
F_13 ( V_2 , V_275 ,
F_14 ( V_249 -> V_276 ) ) )
goto V_12;
F_56 ( V_2 , V_102 ) ;
return V_2 -> V_67 ;
V_12:
V_110:
F_57 ( V_2 , V_102 ) ;
return - 1 ;
}
static int
F_166 ( struct V_1 * V_2 , struct V_151 * V_152 )
{
int V_247 ;
struct V_128 * V_128 = F_81 ( V_2 -> V_154 ) ;
if ( V_152 -> args [ 0 ] == V_277 )
return 0 ;
for ( V_247 = V_152 -> args [ 0 ] ; V_247 < V_277 ; V_247 ++ ) {
const struct V_248 * V_249 ;
if ( ! F_167 ( V_247 ) )
continue;
V_249 = F_168 ( V_128 -> V_23 . V_278 , V_247 ) ;
if ( F_165 ( V_2 ,
F_86 ( V_152 -> V_2 ) . V_100 ,
V_152 -> V_102 -> V_168 ,
V_247 , V_249 ) < 0 )
break;
}
V_152 -> args [ 0 ] = V_247 ;
return V_2 -> V_67 ;
}
static int
F_169 ( struct V_188 * V_189 , struct V_1 * V_2 ,
const struct V_101 * V_102 ,
const struct V_8 * const V_178 [] )
{
if ( V_102 -> V_195 & V_196 ) {
struct V_197 V_198 = {
. V_199 = F_166 ,
} ;
return F_115 ( V_189 , V_2 , V_102 , & V_198 ) ;
}
return 0 ;
}
static int
F_170 ( struct V_1 * V_2 , T_2 V_100 , T_2 V_91 , T_2 type ,
struct V_128 * V_128 )
{
struct V_101 * V_102 ;
struct V_103 * V_104 ;
unsigned int V_105 = V_100 ? V_106 : 0 , V_107 ;
unsigned int V_279 = F_48 ( & V_128 -> V_23 . V_280 ) ;
V_107 = ( V_108 << 8 | V_281 ) ;
V_102 = F_50 ( V_2 , V_100 , V_91 , V_107 , sizeof( * V_104 ) , V_105 ) ;
if ( V_102 == NULL )
goto V_110;
V_104 = F_51 ( V_102 ) ;
V_104 -> V_111 = V_251 ;
V_104 -> V_112 = V_113 ;
V_104 -> V_114 = 0 ;
if ( F_13 ( V_2 , V_282 , F_14 ( V_279 ) ) )
goto V_12;
F_56 ( V_2 , V_102 ) ;
return V_2 -> V_67 ;
V_12:
V_110:
F_57 ( V_2 , V_102 ) ;
return - 1 ;
}
static int
F_171 ( struct V_188 * V_189 , struct V_1 * V_2 ,
const struct V_101 * V_102 ,
const struct V_8 * const V_178 [] )
{
struct V_1 * V_194 ;
int V_130 ;
V_194 = F_73 ( V_203 , V_204 ) ;
if ( V_194 == NULL )
return - V_202 ;
V_130 = F_170 ( V_194 , F_86 ( V_2 ) . V_100 ,
V_102 -> V_168 ,
F_87 ( V_102 -> V_169 ) ,
F_81 ( V_2 -> V_154 ) ) ;
if ( V_130 <= 0 )
goto free;
V_130 = F_116 ( V_189 , V_194 , F_86 ( V_2 ) . V_100 , V_205 ) ;
if ( V_130 < 0 )
goto V_39;
return 0 ;
free:
F_75 ( V_194 ) ;
V_39:
return V_130 == - V_150 ? - V_149 : V_130 ;
}
static T_3
F_172 ( const struct V_22 * V_23 )
{
return 3 * F_38 ( 0 )
+ 3 * F_38 ( 0 )
+ 3 * F_38 ( 0 )
+ 3 * F_38 ( sizeof( V_122 ) )
+ F_38 ( sizeof( V_123 ) )
+ F_38 ( sizeof( V_123 ) )
+ F_38 ( sizeof( V_123 ) )
+ F_38 ( 0 )
+ F_38 ( 0 )
+ F_38 ( V_124 )
+ F_61 ( V_23 )
#ifdef F_67
+ 2 * F_38 ( 0 )
+ 6 * F_38 ( sizeof( V_123 ) )
#endif
#ifdef F_68
+ F_38 ( sizeof( V_123 ) )
#endif
+ F_58 ( V_23 )
;
}
static int
F_173 ( struct V_1 * V_2 , struct V_22 * V_23 )
{
struct V_8 * V_9 ;
F_8 () ;
V_9 = F_2 ( V_2 , V_115 | V_11 ) ;
if ( ! V_9 )
goto V_12;
if ( F_7 ( V_2 , F_52 ( V_23 , V_92 ) ) < 0 )
goto V_12;
F_5 ( V_2 , V_9 ) ;
V_9 = F_2 ( V_2 , V_116 | V_11 ) ;
if ( ! V_9 )
goto V_12;
if ( F_7 ( V_2 , F_52 ( V_23 , V_94 ) ) < 0 )
goto V_12;
F_5 ( V_2 , V_9 ) ;
if ( F_53 ( V_23 ) ) {
if ( F_54 ( V_2 , V_117 , F_55 ( F_53 ( V_23 ) ) ) )
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
if ( V_23 -> V_227 && F_41 ( V_2 , V_23 ) < 0 )
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
return - V_283 ;
}
static int
F_174 ( const struct V_8 * V_178 [] , struct V_22 * V_23 )
{
int V_130 ;
if ( V_178 [ V_30 ] ) {
V_130 = F_135 ( V_23 , V_178 ) ;
if ( V_130 < 0 )
return V_130 ;
}
if ( V_178 [ V_24 ] ) {
V_130 = F_129 ( V_23 , V_178 ) ;
if ( V_130 < 0 )
return V_130 ;
}
if ( V_178 [ V_40 ] ) {
V_130 = F_131 ( V_23 , V_178 ) ;
if ( V_130 < 0 )
return V_130 ;
}
if ( V_178 [ V_77 ] ) {
V_130 = F_140 ( V_23 , V_178 ) ;
if ( V_130 < 0 )
return V_130 ;
}
#if F_145 ( F_68 )
if ( V_178 [ V_64 ] )
V_23 -> V_65 = F_106 ( F_107 ( V_178 [ V_64 ] ) ) ;
#endif
return 0 ;
}
static int
F_175 ( const struct V_8 * V_170 , struct V_22 * V_23 )
{
struct V_8 * V_178 [ V_284 + 1 ] ;
int V_7 ;
V_7 = F_91 ( V_178 , V_284 , V_170 , V_285 ) ;
if ( V_7 < 0 )
return V_7 ;
F_82 ( & V_163 ) ;
V_7 = F_174 ( ( const struct V_8 * * ) V_178 , V_23 ) ;
F_89 ( & V_163 ) ;
return V_7 ;
}
static inline int
F_176 ( struct V_1 * V_2 ,
const struct V_3 * V_4 ,
enum V_286 type )
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
F_177 ( struct V_1 * V_2 ,
const struct V_3 * V_4 ,
const struct V_287 * V_166 )
{
int V_7 ;
struct V_17 * V_18 ;
struct V_5 * V_6 ;
struct V_3 V_288 ;
struct V_8 * V_9 ;
memset ( & V_288 , 0xFF , sizeof( V_288 ) ) ;
memcpy ( & V_288 . V_20 . V_190 , & V_166 -> V_20 . V_190 , sizeof( V_288 . V_20 . V_190 ) ) ;
V_288 . V_20 . V_289 . V_290 = V_166 -> V_20 . V_289 . V_290 ;
V_288 . V_14 . V_15 = V_4 -> V_14 . V_15 ;
V_9 = F_2 ( V_2 , V_291 | V_11 ) ;
if ( ! V_9 )
goto V_12;
F_8 () ;
V_18 = F_9 ( V_4 -> V_20 . V_21 ) ;
V_7 = F_6 ( V_2 , & V_288 , V_18 ) ;
if ( V_7 >= 0 ) {
V_6 = F_10 ( V_4 -> V_20 . V_21 ,
V_4 -> V_14 . V_15 ) ;
V_7 = F_1 ( V_2 , & V_288 , V_6 ) ;
}
F_11 () ;
if ( F_178 ( V_7 < 0 ) )
goto V_12;
F_5 ( V_2 , V_9 ) ;
return 0 ;
V_12:
return - 1 ;
}
static int
F_179 ( struct V_1 * V_2 ,
const struct V_292 * exp )
{
struct V_22 * V_227 = exp -> V_227 ;
long V_26 = ( ( long ) exp -> V_26 . V_27 - ( long ) V_28 ) / V_29 ;
struct V_35 * V_36 ;
#ifdef F_67
struct V_8 * V_9 ;
struct V_3 V_293 = {} ;
#endif
struct V_294 * V_295 ;
if ( V_26 < 0 )
V_26 = 0 ;
if ( F_176 ( V_2 , & exp -> V_4 , V_296 ) < 0 )
goto V_12;
if ( F_177 ( V_2 , & exp -> V_4 , & exp -> V_166 ) < 0 )
goto V_12;
if ( F_176 ( V_2 ,
& V_227 -> V_297 [ V_92 ] . V_4 ,
V_298 ) < 0 )
goto V_12;
#ifdef F_67
if ( ! F_180 ( & exp -> V_299 , & V_300 ) ||
exp -> V_301 . V_290 ) {
V_9 = F_2 ( V_2 , V_302 | V_11 ) ;
if ( ! V_9 )
goto V_12;
if ( F_13 ( V_2 , V_303 , F_14 ( exp -> V_46 ) ) )
goto V_12;
V_293 . V_20 . V_21 = F_17 ( V_227 ) ;
V_293 . V_20 . V_190 = exp -> V_299 ;
V_293 . V_14 . V_15 = F_18 ( V_227 ) ;
V_293 . V_20 . V_289 = exp -> V_301 ;
if ( F_176 ( V_2 , & V_293 ,
V_304 ) < 0 )
goto V_12;
F_5 ( V_2 , V_9 ) ;
}
#endif
if ( F_13 ( V_2 , V_305 , F_14 ( V_26 ) ) ||
F_13 ( V_2 , V_306 , F_14 ( ( unsigned long ) exp ) ) ||
F_13 ( V_2 , V_307 , F_14 ( exp -> V_105 ) ) ||
F_13 ( V_2 , V_308 , F_14 ( exp -> V_309 ) ) )
goto V_12;
V_36 = F_20 ( V_227 ) ;
if ( V_36 ) {
struct V_37 * V_38 ;
V_38 = F_21 ( V_36 -> V_38 ) ;
if ( V_38 &&
F_22 ( V_2 , V_310 , V_38 -> V_42 ) )
goto V_12;
}
V_295 = F_181 ( exp -> V_311 ) ;
if ( V_295 != NULL &&
F_22 ( V_2 , V_312 , V_295 -> V_42 ) )
goto V_12;
return 0 ;
V_12:
return - 1 ;
}
static int
F_182 ( struct V_1 * V_2 , T_2 V_100 , T_2 V_91 ,
int V_107 , const struct V_292 * exp )
{
struct V_101 * V_102 ;
struct V_103 * V_104 ;
unsigned int V_105 = V_100 ? V_106 : 0 ;
V_107 |= V_313 << 8 ;
V_102 = F_50 ( V_2 , V_100 , V_91 , V_107 , sizeof( * V_104 ) , V_105 ) ;
if ( V_102 == NULL )
goto V_110;
V_104 = F_51 ( V_102 ) ;
V_104 -> V_111 = exp -> V_4 . V_20 . V_21 ;
V_104 -> V_112 = V_113 ;
V_104 -> V_114 = 0 ;
if ( F_179 ( V_2 , exp ) < 0 )
goto V_12;
F_56 ( V_2 , V_102 ) ;
return V_2 -> V_67 ;
V_110:
V_12:
F_57 ( V_2 , V_102 ) ;
return - 1 ;
}
static int
F_183 ( unsigned int V_125 , struct V_314 * V_127 )
{
struct V_292 * exp = V_127 -> exp ;
struct V_128 * V_128 = F_184 ( exp ) ;
struct V_101 * V_102 ;
struct V_103 * V_104 ;
struct V_1 * V_2 ;
unsigned int type , V_129 ;
int V_105 = 0 ;
if ( V_125 & ( 1 << V_315 ) ) {
type = V_316 ;
V_129 = V_317 ;
} else if ( V_125 & ( 1 << V_318 ) ) {
type = V_319 ;
V_105 = V_136 | V_137 ;
V_129 = V_320 ;
} else
return 0 ;
if ( ! V_127 -> V_140 && ! F_72 ( V_128 , V_129 ) )
return 0 ;
V_2 = F_73 ( V_203 , V_141 ) ;
if ( V_2 == NULL )
goto V_142;
type |= V_313 << 8 ;
V_102 = F_50 ( V_2 , V_127 -> V_100 , 0 , type , sizeof( * V_104 ) , V_105 ) ;
if ( V_102 == NULL )
goto V_110;
V_104 = F_51 ( V_102 ) ;
V_104 -> V_111 = exp -> V_4 . V_20 . V_21 ;
V_104 -> V_112 = V_113 ;
V_104 -> V_114 = 0 ;
F_8 () ;
if ( F_179 ( V_2 , exp ) < 0 )
goto V_12;
F_11 () ;
F_56 ( V_2 , V_102 ) ;
F_74 ( V_2 , V_128 , V_127 -> V_100 , V_129 , V_127 -> V_140 , V_141 ) ;
return 0 ;
V_12:
F_11 () ;
F_57 ( V_2 , V_102 ) ;
V_110:
F_75 ( V_2 ) ;
V_142:
F_76 ( V_128 , 0 , 0 , - V_149 ) ;
return 0 ;
}
static int F_185 ( struct V_151 * V_152 )
{
if ( V_152 -> args [ 1 ] )
F_186 ( (struct V_292 * ) V_152 -> args [ 1 ] ) ;
return 0 ;
}
static int
F_187 ( struct V_1 * V_2 , struct V_151 * V_152 )
{
struct V_128 * V_128 = F_81 ( V_2 -> V_154 ) ;
struct V_292 * exp , * V_155 ;
struct V_103 * V_104 = F_51 ( V_152 -> V_102 ) ;
V_122 V_18 = V_104 -> V_111 ;
F_8 () ;
V_155 = (struct V_292 * ) V_152 -> args [ 1 ] ;
for (; V_152 -> args [ 0 ] < V_321 ; V_152 -> args [ 0 ] ++ ) {
V_165:
F_188 (exp, &net->ct.expect_hash[cb->args[0]],
hnode) {
if ( V_18 && exp -> V_4 . V_20 . V_21 != V_18 )
continue;
if ( V_152 -> args [ 1 ] ) {
if ( exp != V_155 )
continue;
V_152 -> args [ 1 ] = 0 ;
}
if ( F_182 ( V_2 ,
F_86 ( V_152 -> V_2 ) . V_100 ,
V_152 -> V_102 -> V_168 ,
V_319 ,
exp ) < 0 ) {
if ( ! F_189 ( & exp -> V_99 ) )
continue;
V_152 -> args [ 1 ] = ( unsigned long ) exp ;
goto V_39;
}
}
if ( V_152 -> args [ 1 ] ) {
V_152 -> args [ 1 ] = 0 ;
goto V_165;
}
}
V_39:
F_11 () ;
if ( V_155 )
F_186 ( V_155 ) ;
return V_2 -> V_67 ;
}
static int
F_190 ( struct V_1 * V_2 , struct V_151 * V_152 )
{
struct V_292 * exp , * V_155 ;
struct V_103 * V_104 = F_51 ( V_152 -> V_102 ) ;
struct V_22 * V_23 = V_152 -> V_153 ;
struct V_35 * V_36 = F_20 ( V_23 ) ;
V_122 V_18 = V_104 -> V_111 ;
if ( V_152 -> args [ 0 ] )
return 0 ;
F_8 () ;
V_155 = (struct V_292 * ) V_152 -> args [ 1 ] ;
V_165:
F_188 (exp, &help->expectations, lnode) {
if ( V_18 && exp -> V_4 . V_20 . V_21 != V_18 )
continue;
if ( V_152 -> args [ 1 ] ) {
if ( exp != V_155 )
continue;
V_152 -> args [ 1 ] = 0 ;
}
if ( F_182 ( V_2 , F_86 ( V_152 -> V_2 ) . V_100 ,
V_152 -> V_102 -> V_168 ,
V_319 ,
exp ) < 0 ) {
if ( ! F_189 ( & exp -> V_99 ) )
continue;
V_152 -> args [ 1 ] = ( unsigned long ) exp ;
goto V_39;
}
}
if ( V_152 -> args [ 1 ] ) {
V_152 -> args [ 1 ] = 0 ;
goto V_165;
}
V_152 -> args [ 0 ] = 1 ;
V_39:
F_11 () ;
if ( V_155 )
F_186 ( V_155 ) ;
return V_2 -> V_67 ;
}
static int F_191 ( struct V_188 * V_189 , struct V_1 * V_2 ,
const struct V_101 * V_102 ,
const struct V_8 * const V_178 [] )
{
int V_130 ;
struct V_128 * V_128 = F_81 ( V_189 ) ;
struct V_103 * V_104 = F_51 ( V_102 ) ;
V_122 V_190 = V_104 -> V_111 ;
struct V_3 V_4 ;
struct V_156 * V_157 ;
struct V_22 * V_23 ;
T_4 V_181 = 0 ;
struct V_197 V_198 = {
. V_199 = F_190 ,
. V_200 = F_185 ,
} ;
V_130 = F_95 ( V_178 , & V_4 , V_298 , V_190 ) ;
if ( V_130 < 0 )
return V_130 ;
if ( V_178 [ V_322 ] ) {
V_130 = F_96 ( V_178 [ V_322 ] , & V_181 ) ;
if ( V_130 < 0 )
return V_130 ;
}
V_157 = F_105 ( V_128 , V_181 , & V_4 ) ;
if ( ! V_157 )
return - V_191 ;
V_23 = F_85 ( V_157 ) ;
V_198 . V_153 = V_23 ;
V_130 = F_115 ( V_189 , V_2 , V_102 , & V_198 ) ;
F_78 ( V_23 ) ;
return V_130 ;
}
static int
F_192 ( struct V_188 * V_189 , struct V_1 * V_2 ,
const struct V_101 * V_102 ,
const struct V_8 * const V_178 [] )
{
struct V_128 * V_128 = F_81 ( V_189 ) ;
struct V_3 V_4 ;
struct V_292 * exp ;
struct V_1 * V_194 ;
struct V_103 * V_104 = F_51 ( V_102 ) ;
V_122 V_190 = V_104 -> V_111 ;
T_4 V_181 ;
int V_130 ;
if ( V_102 -> V_195 & V_196 ) {
if ( V_178 [ V_298 ] )
return F_191 ( V_189 , V_2 , V_102 , V_178 ) ;
else {
struct V_197 V_198 = {
. V_199 = F_187 ,
. V_200 = F_185 ,
} ;
return F_115 ( V_189 , V_2 , V_102 , & V_198 ) ;
}
}
V_130 = F_96 ( V_178 [ V_322 ] , & V_181 ) ;
if ( V_130 < 0 )
return V_130 ;
if ( V_178 [ V_296 ] )
V_130 = F_95 ( V_178 , & V_4 , V_296 , V_190 ) ;
else if ( V_178 [ V_298 ] )
V_130 = F_95 ( V_178 , & V_4 , V_298 , V_190 ) ;
else
return - V_177 ;
if ( V_130 < 0 )
return V_130 ;
exp = F_193 ( V_128 , V_181 , & V_4 ) ;
if ( ! exp )
return - V_191 ;
if ( V_178 [ V_306 ] ) {
T_7 V_192 = F_107 ( V_178 [ V_306 ] ) ;
if ( F_106 ( V_192 ) != ( T_2 ) ( unsigned long ) exp ) {
F_186 ( exp ) ;
return - V_191 ;
}
}
V_130 = - V_202 ;
V_194 = F_73 ( V_203 , V_204 ) ;
if ( V_194 == NULL ) {
F_186 ( exp ) ;
goto V_39;
}
F_8 () ;
V_130 = F_182 ( V_194 , F_86 ( V_2 ) . V_100 ,
V_102 -> V_168 , V_319 , exp ) ;
F_11 () ;
F_186 ( exp ) ;
if ( V_130 <= 0 )
goto free;
V_130 = F_116 ( V_189 , V_194 , F_86 ( V_2 ) . V_100 , V_205 ) ;
if ( V_130 < 0 )
goto V_39;
return 0 ;
free:
F_75 ( V_194 ) ;
V_39:
return V_130 == - V_150 ? - V_149 : V_130 ;
}
static int
F_194 ( struct V_188 * V_189 , struct V_1 * V_2 ,
const struct V_101 * V_102 ,
const struct V_8 * const V_178 [] )
{
struct V_128 * V_128 = F_81 ( V_189 ) ;
struct V_292 * exp ;
struct V_3 V_4 ;
struct V_103 * V_104 = F_51 ( V_102 ) ;
struct V_323 * V_324 ;
V_122 V_190 = V_104 -> V_111 ;
unsigned int V_75 ;
T_4 V_181 ;
int V_130 ;
if ( V_178 [ V_296 ] ) {
V_130 = F_96 ( V_178 [ V_322 ] , & V_181 ) ;
if ( V_130 < 0 )
return V_130 ;
V_130 = F_95 ( V_178 , & V_4 , V_296 , V_190 ) ;
if ( V_130 < 0 )
return V_130 ;
exp = F_193 ( V_128 , V_181 , & V_4 ) ;
if ( ! exp )
return - V_191 ;
if ( V_178 [ V_306 ] ) {
T_7 V_192 = F_107 ( V_178 [ V_306 ] ) ;
if ( F_106 ( V_192 ) != ( T_2 ) ( unsigned long ) exp ) {
F_186 ( exp ) ;
return - V_191 ;
}
}
F_82 ( & V_163 ) ;
if ( F_108 ( & exp -> V_26 ) ) {
F_195 ( exp , F_86 ( V_2 ) . V_100 ,
F_104 ( V_102 ) ) ;
F_186 ( exp ) ;
}
F_89 ( & V_163 ) ;
F_186 ( exp ) ;
} else if ( V_178 [ V_310 ] ) {
char * V_42 = F_101 ( V_178 [ V_310 ] ) ;
struct V_35 * V_325 ;
F_82 ( & V_163 ) ;
for ( V_75 = 0 ; V_75 < V_321 ; V_75 ++ ) {
F_196 (exp, next,
&net->ct.expect_hash[i],
hnode) {
V_325 = F_20 ( exp -> V_227 ) ;
if ( ! strcmp ( V_325 -> V_38 -> V_42 , V_42 ) &&
F_108 ( & exp -> V_26 ) ) {
F_195 ( exp ,
F_86 ( V_2 ) . V_100 ,
F_104 ( V_102 ) ) ;
F_186 ( exp ) ;
}
}
}
F_89 ( & V_163 ) ;
} else {
F_82 ( & V_163 ) ;
for ( V_75 = 0 ; V_75 < V_321 ; V_75 ++ ) {
F_196 (exp, next,
&net->ct.expect_hash[i],
hnode) {
if ( F_108 ( & exp -> V_26 ) ) {
F_195 ( exp ,
F_86 ( V_2 ) . V_100 ,
F_104 ( V_102 ) ) ;
F_186 ( exp ) ;
}
}
}
F_89 ( & V_163 ) ;
}
return 0 ;
}
static int
F_197 ( struct V_292 * V_326 ,
const struct V_8 * const V_178 [] )
{
if ( V_178 [ V_305 ] ) {
if ( ! F_108 ( & V_326 -> V_26 ) )
return - V_229 ;
V_326 -> V_26 . V_27 = V_28 +
F_106 ( F_107 ( V_178 [ V_305 ] ) ) * V_29 ;
F_136 ( & V_326 -> V_26 ) ;
}
return 0 ;
}
static int
F_198 ( const struct V_8 * V_170 ,
struct V_292 * exp ,
V_122 V_190 )
{
#ifdef F_67
struct V_8 * V_171 [ V_327 + 1 ] ;
struct V_3 V_293 = {} ;
int V_130 ;
V_130 = F_91 ( V_171 , V_327 , V_170 , V_328 ) ;
if ( V_130 < 0 )
return V_130 ;
if ( ! V_171 [ V_303 ] || ! V_171 [ V_304 ] )
return - V_177 ;
V_130 = F_95 ( ( const struct V_8 * const * ) V_171 ,
& V_293 , V_304 , V_190 ) ;
if ( V_130 < 0 )
return V_130 ;
exp -> V_299 = V_293 . V_20 . V_190 ;
exp -> V_301 = V_293 . V_20 . V_289 ;
exp -> V_46 = F_106 ( F_107 ( V_171 [ V_303 ] ) ) ;
return 0 ;
#else
return - V_182 ;
#endif
}
static int
F_199 ( struct V_128 * V_128 , T_4 V_181 ,
const struct V_8 * const V_178 [] ,
V_122 V_190 ,
T_2 V_100 , int V_140 )
{
struct V_3 V_4 , V_166 , F_42 ;
struct V_156 * V_157 = NULL ;
struct V_292 * exp ;
struct V_22 * V_23 ;
struct V_35 * V_36 ;
struct V_37 * V_38 = NULL ;
V_123 V_309 = 0 ;
int V_130 = 0 ;
V_130 = F_95 ( V_178 , & V_4 , V_296 , V_190 ) ;
if ( V_130 < 0 )
return V_130 ;
V_130 = F_95 ( V_178 , & V_166 , V_291 , V_190 ) ;
if ( V_130 < 0 )
return V_130 ;
V_130 = F_95 ( V_178 , & F_42 , V_298 , V_190 ) ;
if ( V_130 < 0 )
return V_130 ;
V_157 = F_105 ( V_128 , V_181 , & F_42 ) ;
if ( ! V_157 )
return - V_191 ;
V_23 = F_85 ( V_157 ) ;
if ( V_178 [ V_310 ] ) {
const char * V_226 = F_101 ( V_178 [ V_310 ] ) ;
V_38 = F_134 ( V_226 , F_17 ( V_23 ) ,
F_18 ( V_23 ) ) ;
if ( V_38 == NULL ) {
#ifdef F_125
if ( F_127 ( L_4 , V_226 ) < 0 ) {
V_130 = - V_182 ;
goto V_39;
}
V_38 = F_134 ( V_226 ,
F_17 ( V_23 ) ,
F_18 ( V_23 ) ) ;
if ( V_38 ) {
V_130 = - V_150 ;
goto V_39;
}
#endif
V_130 = - V_182 ;
goto V_39;
}
}
if ( V_178 [ V_308 ] && V_38 ) {
V_309 = F_106 ( F_107 ( V_178 [ V_308 ] ) ) ;
if ( V_309 > V_38 -> V_329 ) {
V_130 = - V_177 ;
goto V_39;
}
}
exp = F_200 ( V_23 ) ;
if ( ! exp ) {
V_130 = - V_202 ;
goto V_39;
}
V_36 = F_20 ( V_23 ) ;
if ( ! V_36 ) {
if ( ! V_178 [ V_305 ] ) {
V_130 = - V_177 ;
goto V_330;
}
exp -> V_26 . V_27 =
V_28 + F_106 ( F_107 ( V_178 [ V_305 ] ) ) * V_29 ;
exp -> V_105 = V_331 ;
if ( V_178 [ V_307 ] ) {
exp -> V_105 |=
F_106 ( F_107 ( V_178 [ V_307 ] ) ) ;
}
} else {
if ( V_178 [ V_307 ] ) {
exp -> V_105 = F_106 ( F_107 ( V_178 [ V_307 ] ) ) ;
exp -> V_105 &= ~ V_331 ;
} else
exp -> V_105 = 0 ;
}
if ( V_178 [ V_312 ] ) {
const char * V_42 = F_101 ( V_178 [ V_312 ] ) ;
struct V_294 * V_295 ;
V_295 = F_201 ( V_42 ) ;
if ( V_295 == NULL ) {
V_130 = - V_177 ;
goto V_330;
}
exp -> V_311 = V_295 -> V_311 ;
} else
exp -> V_311 = NULL ;
exp -> V_309 = V_309 ;
exp -> V_227 = V_23 ;
exp -> V_38 = V_38 ;
memcpy ( & exp -> V_4 , & V_4 , sizeof( struct V_3 ) ) ;
memcpy ( & exp -> V_166 . V_20 . V_190 , & V_166 . V_20 . V_190 , sizeof( exp -> V_166 . V_20 . V_190 ) ) ;
exp -> V_166 . V_20 . V_289 . V_290 = V_166 . V_20 . V_289 . V_290 ;
if ( V_178 [ V_302 ] ) {
V_130 = F_198 ( V_178 [ V_302 ] ,
exp , V_190 ) ;
if ( V_130 < 0 )
goto V_330;
}
V_130 = F_202 ( exp , V_100 , V_140 ) ;
V_330:
F_186 ( exp ) ;
V_39:
F_78 ( F_85 ( V_157 ) ) ;
return V_130 ;
}
static int
F_203 ( struct V_188 * V_189 , struct V_1 * V_2 ,
const struct V_101 * V_102 ,
const struct V_8 * const V_178 [] )
{
struct V_128 * V_128 = F_81 ( V_189 ) ;
struct V_3 V_4 ;
struct V_292 * exp ;
struct V_103 * V_104 = F_51 ( V_102 ) ;
V_122 V_190 = V_104 -> V_111 ;
T_4 V_181 ;
int V_130 ;
if ( ! V_178 [ V_296 ]
|| ! V_178 [ V_291 ]
|| ! V_178 [ V_298 ] )
return - V_177 ;
V_130 = F_96 ( V_178 [ V_322 ] , & V_181 ) ;
if ( V_130 < 0 )
return V_130 ;
V_130 = F_95 ( V_178 , & V_4 , V_296 , V_190 ) ;
if ( V_130 < 0 )
return V_130 ;
F_82 ( & V_163 ) ;
exp = F_204 ( V_128 , V_181 , & V_4 ) ;
if ( ! exp ) {
F_89 ( & V_163 ) ;
V_130 = - V_191 ;
if ( V_102 -> V_195 & V_136 ) {
V_130 = F_199 ( V_128 , V_181 , V_178 ,
V_190 ,
F_86 ( V_2 ) . V_100 ,
F_104 ( V_102 ) ) ;
}
return V_130 ;
}
V_130 = - V_246 ;
if ( ! ( V_102 -> V_195 & V_137 ) )
V_130 = F_197 ( exp , V_178 ) ;
F_89 ( & V_163 ) ;
return V_130 ;
}
static int
F_205 ( struct V_1 * V_2 , T_2 V_100 , T_2 V_91 , int V_247 ,
const struct V_248 * V_249 )
{
struct V_101 * V_102 ;
struct V_103 * V_104 ;
unsigned int V_105 = V_100 ? V_106 : 0 , V_107 ;
V_107 = ( V_108 << 8 | V_332 ) ;
V_102 = F_50 ( V_2 , V_100 , V_91 , V_107 , sizeof( * V_104 ) , V_105 ) ;
if ( V_102 == NULL )
goto V_110;
V_104 = F_51 ( V_102 ) ;
V_104 -> V_111 = V_251 ;
V_104 -> V_112 = V_113 ;
V_104 -> V_114 = F_55 ( V_247 ) ;
if ( F_13 ( V_2 , V_333 , F_14 ( V_249 -> V_334 ) ) ||
F_13 ( V_2 , V_335 , F_14 ( V_249 -> V_336 ) ) ||
F_13 ( V_2 , V_337 , F_14 ( V_249 -> V_338 ) ) )
goto V_12;
F_56 ( V_2 , V_102 ) ;
return V_2 -> V_67 ;
V_12:
V_110:
F_57 ( V_2 , V_102 ) ;
return - 1 ;
}
static int
F_206 ( struct V_1 * V_2 , struct V_151 * V_152 )
{
int V_247 ;
struct V_128 * V_128 = F_81 ( V_2 -> V_154 ) ;
if ( V_152 -> args [ 0 ] == V_277 )
return 0 ;
for ( V_247 = V_152 -> args [ 0 ] ; V_247 < V_277 ; V_247 ++ ) {
const struct V_248 * V_249 ;
if ( ! F_167 ( V_247 ) )
continue;
V_249 = F_168 ( V_128 -> V_23 . V_278 , V_247 ) ;
if ( F_205 ( V_2 , F_86 ( V_152 -> V_2 ) . V_100 ,
V_152 -> V_102 -> V_168 ,
V_247 , V_249 ) < 0 )
break;
}
V_152 -> args [ 0 ] = V_247 ;
return V_2 -> V_67 ;
}
static int
F_207 ( struct V_188 * V_189 , struct V_1 * V_2 ,
const struct V_101 * V_102 ,
const struct V_8 * const V_178 [] )
{
if ( V_102 -> V_195 & V_196 ) {
struct V_197 V_198 = {
. V_199 = F_206 ,
} ;
return F_115 ( V_189 , V_2 , V_102 , & V_198 ) ;
}
return 0 ;
}
static int T_8 F_208 ( struct V_128 * V_128 )
{
#ifdef F_209
int V_7 ;
V_7 = F_210 ( V_128 , & V_339 ) ;
if ( V_7 < 0 ) {
F_211 ( L_5 ) ;
goto V_330;
}
V_7 = F_212 ( V_128 , & V_340 ) ;
if ( V_7 < 0 ) {
F_211 ( L_6 ) ;
goto V_341;
}
#endif
return 0 ;
#ifdef F_209
V_341:
F_213 ( V_128 , & V_339 ) ;
V_330:
return V_7 ;
#endif
}
static void F_214 ( struct V_128 * V_128 )
{
#ifdef F_209
F_215 ( V_128 , & V_340 ) ;
F_213 ( V_128 , & V_339 ) ;
#endif
}
static void T_9 F_216 ( struct V_342 * V_343 )
{
struct V_128 * V_128 ;
F_217 (net, net_exit_list, exit_list)
F_214 ( V_128 ) ;
}
static int T_10 F_218 ( void )
{
int V_7 ;
F_219 ( L_7 , V_112 ) ;
V_7 = F_220 ( & V_344 ) ;
if ( V_7 < 0 ) {
F_211 ( L_8 ) ;
goto V_330;
}
V_7 = F_220 ( & V_345 ) ;
if ( V_7 < 0 ) {
F_211 ( L_9 ) ;
goto V_346;
}
V_7 = F_221 ( & V_347 ) ;
if ( V_7 < 0 ) {
F_211 ( L_10 ) ;
goto V_348;
}
#ifdef F_222
F_133 ( V_349 , & V_350 ) ;
#endif
return 0 ;
V_348:
F_223 ( & V_345 ) ;
V_346:
F_223 ( & V_344 ) ;
V_330:
return V_7 ;
}
static void T_11 F_224 ( void )
{
F_219 ( L_11 ) ;
F_225 ( & V_347 ) ;
F_223 ( & V_345 ) ;
F_223 ( & V_344 ) ;
#ifdef F_222
F_133 ( V_349 , NULL ) ;
#endif
}
