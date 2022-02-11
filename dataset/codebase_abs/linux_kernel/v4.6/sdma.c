static const char * F_1 ( enum V_1 V_2 )
{
return V_3 [ V_2 ] ;
}
static void F_2 ( struct V_4 * V_5 )
{
F_3 ( & V_5 -> V_6 ) ;
}
static void F_4 ( struct V_6 * V_6 )
{
struct V_4 * V_5 =
F_5 ( V_6 , struct V_4 , V_6 ) ;
F_6 ( & V_5 -> V_7 ) ;
}
static void F_7 ( struct V_4 * V_5 )
{
F_8 ( & V_5 -> V_6 , F_4 ) ;
}
static void F_9 ( struct V_4 * V_5 )
{
F_7 ( V_5 ) ;
F_10 ( & V_5 -> V_7 ) ;
}
static inline void F_11 (
struct V_8 * V_9 ,
T_1 V_10 ,
T_2 V_11 )
{
F_12 ( V_9 -> V_12 , V_9 -> V_13 , V_10 , V_11 ) ;
}
static inline T_2 F_13 (
struct V_8 * V_9 ,
T_1 V_10 )
{
return F_14 ( V_9 -> V_12 , V_9 -> V_13 , V_10 ) ;
}
static void F_15 ( struct V_8 * V_9 ,
int V_14 )
{
T_2 V_15 = 8 * V_9 -> V_13 ;
struct V_16 * V_12 = V_9 -> V_12 ;
int V_17 = 0 ;
T_2 V_18 ;
T_2 V_19 = 0 ;
while ( 1 ) {
V_18 = V_19 ;
V_19 = F_16 ( V_12 , V_15 + V_20 ) ;
V_19 &= V_21 ;
V_19 >>= V_22 ;
if ( V_19 == 0 )
break;
if ( V_19 != V_18 )
V_17 = 0 ;
if ( V_17 ++ > 500 ) {
F_17 ( V_12 , L_1 ,
V_23 , V_9 -> V_13 , ( T_1 ) V_19 ) ;
F_18 ( V_12 -> V_24 -> V_25 ,
& V_12 -> V_24 -> V_26 ) ;
break;
}
F_19 ( 1 ) ;
}
}
void F_20 ( struct V_16 * V_12 )
{
int V_27 ;
for ( V_27 = 0 ; V_27 < V_12 -> V_28 ; V_27 ++ ) {
struct V_8 * V_9 = & V_12 -> V_29 [ V_27 ] ;
F_15 ( V_9 , 0 ) ;
}
}
static inline void F_21 ( struct V_8 * V_9 , unsigned V_30 )
{
T_2 V_19 ;
if ( ! ( V_9 -> V_12 -> V_31 & V_32 ) )
return;
V_19 = V_30 ;
V_19 &= F_22 ( V_33 ) ;
V_19 <<= F_22 ( V_34 ) ;
F_11 ( V_9 , F_22 ( V_35 ) , V_19 ) ;
}
static inline void F_23 ( struct V_8 * V_9 ,
struct V_36 * V_37 ,
int V_38 )
{
struct V_39 * V_40 = V_37 -> V_40 ;
T_3 F_6 = V_37 -> F_6 ;
#ifdef F_24
F_25 ( V_9 , V_37 -> V_41 ) ;
if ( F_26 ( V_9 -> V_42 != V_37 -> V_41 ) )
F_17 ( V_9 -> V_12 , L_2 ,
V_9 -> V_42 , V_37 -> V_41 ) ;
V_9 -> V_42 ++ ;
#endif
F_27 ( V_9 -> V_12 , V_37 ) ;
if ( F_6 )
(* F_6)( V_37 , V_38 ) ;
if ( F_28 ( V_40 ) && V_40 )
F_29 ( V_40 ) ;
}
static void F_30 ( struct V_8 * V_9 )
{
struct V_36 * V_43 , * V_44 ;
F_31 ( V_45 ) ;
unsigned long V_31 ;
F_32 ( V_9 ) ;
F_33 ( & V_9 -> V_46 , V_31 ) ;
F_34 (txp, txp_next, &sde->flushlist, list) {
F_35 ( & V_43 -> V_47 ) ;
F_36 ( & V_43 -> V_47 , & V_45 ) ;
}
F_37 ( & V_9 -> V_46 , V_31 ) ;
F_34 (txp, txp_next, &flushlist, list)
F_23 ( V_9 , V_43 , V_48 ) ;
}
static void F_38 ( struct V_49 * V_50 )
{
unsigned long V_31 ;
struct V_8 * V_9 =
F_5 ( V_50 , struct V_8 , V_51 ) ;
F_39 ( & V_9 -> V_52 , V_31 ) ;
if ( ! F_40 ( V_9 ) )
F_30 ( V_9 ) ;
F_41 ( & V_9 -> V_52 , V_31 ) ;
}
static void F_42 ( struct V_49 * V_50 )
{
struct V_8 * V_9 = F_5 ( V_50 , struct V_8 ,
V_53 ) ;
T_2 V_54 ;
unsigned long V_55 ;
V_55 = V_56 + F_43 ( V_57 ) ;
while ( 1 ) {
V_54 = F_13 ( V_9 , F_22 ( V_58 ) ) ;
V_54 &= F_22 ( V_59 ) ;
if ( V_54 )
break;
if ( F_44 ( V_56 , V_55 ) ) {
F_17 ( V_9 -> V_12 ,
L_3 ,
V_9 -> V_13 ) ;
break;
}
F_45 ( 80 , 120 ) ;
}
F_46 ( V_9 , V_60 ) ;
}
static void F_47 ( struct V_8 * V_9 )
{
if ( ! F_48 ( V_9 -> V_12 ) && F_49 ( V_61 ) ) {
unsigned V_62 ;
struct V_16 * V_12 = V_9 -> V_12 ;
for ( V_62 = 0 ; V_62 < V_12 -> V_28 ; V_62 ++ ) {
struct V_8 * V_63 = & V_12 -> V_29 [ V_62 ] ;
if ( V_63 != V_9 )
V_63 -> V_64 =
V_63 -> V_65 ;
}
F_17 ( V_9 -> V_12 ,
L_4 ,
V_9 -> V_13 ) ;
F_50 ( & V_9 -> V_66 , V_56 + 10 ) ;
}
}
static void F_51 ( unsigned long V_67 )
{
unsigned V_62 ;
struct V_8 * V_9 = (struct V_8 * ) V_67 ;
F_17 ( V_9 -> V_12 , L_5 ) ;
for ( V_62 = 0 ; V_62 < V_9 -> V_12 -> V_28 ; V_62 ++ ) {
struct V_8 * V_68 = & V_9 -> V_12 -> V_29 [ V_62 ] ;
unsigned long V_31 ;
if ( V_68 == V_9 )
continue;
F_33 ( & V_68 -> V_69 , V_31 ) ;
F_52 ( & V_68 -> V_52 ) ;
if ( V_68 -> V_2 . V_70 != V_71 ) {
F_53 ( & V_68 -> V_52 ) ;
F_37 ( & V_68 -> V_69 , V_31 ) ;
continue;
}
if ( ( V_68 -> V_65 != V_68 -> V_72 ) &&
( V_68 -> V_65 ==
V_68 -> V_64 ) )
F_54 ( V_68 ,
V_73 ) ;
F_53 ( & V_68 -> V_52 ) ;
F_37 ( & V_68 -> V_69 , V_31 ) ;
}
F_55 ( & V_9 -> V_53 ) ;
}
static void F_56 ( unsigned long V_74 )
{
struct V_8 * V_9 = (struct V_8 * ) V_74 ;
T_2 V_54 ;
while ( 1 ) {
#ifdef F_57
F_17 ( V_9 -> V_12 , L_6 ,
V_9 -> V_13 , F_58 ( __FILE__ ) , __LINE__ ,
V_23 ) ;
#endif
V_54 = F_13 ( V_9 , F_22 ( V_58 ) ) ;
V_54 &= F_22 ( V_75 ) ;
if ( V_54 )
break;
F_19 ( 10 ) ;
}
F_46 ( V_9 , V_76 ) ;
}
static inline struct V_36 * F_59 ( struct V_8 * V_9 )
{
F_60 () ;
return V_9 -> V_77 [ V_9 -> V_78 & V_9 -> V_79 ] ;
}
static void F_32 ( struct V_8 * V_9 )
{
T_4 V_80 , V_81 ;
int V_82 = 0 ;
struct V_36 * V_43 = F_59 ( V_9 ) ;
V_80 = V_9 -> V_65 & V_9 -> V_79 ;
V_81 = V_9 -> V_72 & V_9 -> V_79 ;
while ( V_80 != V_81 ) {
V_80 = ++ V_9 -> V_65 & V_9 -> V_79 ;
if ( V_43 && V_43 -> V_83 == V_80 ) {
V_9 -> V_77 [ V_9 -> V_78 ++ & V_9 -> V_79 ] = NULL ;
F_23 ( V_9 , V_43 , V_48 ) ;
F_61 ( V_9 , V_80 , V_81 , V_43 ) ;
V_43 = F_59 ( V_9 ) ;
}
V_82 ++ ;
}
if ( V_82 )
F_62 ( V_9 , F_63 ( V_9 ) ) ;
}
static void F_64 ( unsigned long V_74 )
{
struct V_8 * V_9 = (struct V_8 * ) V_74 ;
unsigned long V_31 ;
F_33 ( & V_9 -> V_69 , V_31 ) ;
F_52 ( & V_9 -> V_52 ) ;
F_65 ( V_9 , 0 ) ;
F_30 ( V_9 ) ;
V_9 -> V_72 = 0 ;
V_9 -> V_65 = 0 ;
V_9 -> V_84 = F_63 ( V_9 ) ;
* V_9 -> V_85 = 0 ;
F_54 ( V_9 , V_86 ) ;
F_53 ( & V_9 -> V_52 ) ;
F_37 ( & V_9 -> V_69 , V_31 ) ;
}
static void F_66 ( struct V_8 * V_9 )
{
struct V_4 * V_5 = & V_9 -> V_2 ;
F_7 ( V_5 ) ;
F_67 ( & V_9 -> V_12 -> V_87 , - 1 ) ;
F_68 ( & V_9 -> V_12 -> V_88 ) ;
}
static void F_69 ( struct V_8 * V_9 )
{
F_70 ( & V_9 -> F_56 ) ;
}
static void F_71 ( struct V_8 * V_9 ,
enum V_1 V_89 )
{
struct V_4 * V_5 = & V_9 -> V_2 ;
const struct V_90 * V_91 = V_92 ;
unsigned V_93 = 0 ;
F_72 (
V_9 ,
V_3 [ V_5 -> V_70 ] ,
V_3 [ V_89 ] ) ;
V_5 -> V_94 = V_5 -> V_70 ;
V_5 -> V_95 = V_5 -> V_96 ;
V_5 -> V_70 = V_89 ;
if ( V_5 -> V_94 != V_71 &&
V_89 == V_71 )
F_30 ( V_9 ) ;
if ( V_91 [ V_89 ] . V_97 )
V_93 |= V_98 ;
if ( V_91 [ V_89 ] . V_99 )
V_93 |= V_100 ;
if ( V_91 [ V_89 ] . V_101 )
V_93 |= V_102 ;
if ( V_91 [ V_89 ] . V_103 )
V_93 |= V_104 ;
if ( V_91 [ V_89 ] . V_105 )
V_5 -> V_106 = 0 ;
if ( V_91 [ V_89 ] . V_107 )
V_5 -> V_106 = 1 ;
V_5 -> V_96 = V_93 ;
F_73 ( V_9 , V_5 -> V_96 ) ;
}
T_4 F_74 ( void )
{
T_4 V_108 = V_109 ;
if ( ! V_108 )
return V_110 ;
if ( ! F_75 ( V_108 ) )
return V_110 ;
if ( V_108 < 64 || V_108 > 32768 )
return V_110 ;
return V_108 ;
}
struct V_8 * F_76 (
struct V_16 * V_12 ,
T_1 V_111 ,
T_5 V_112 )
{
struct V_113 * V_114 ;
struct V_115 * V_116 ;
struct V_8 * V_117 ;
if ( V_112 >= V_118 ) {
V_117 = NULL ;
goto V_119;
}
F_77 () ;
V_114 = F_78 ( V_12 -> V_120 ) ;
if ( F_79 ( ! V_114 ) ) {
F_80 () ;
return & V_12 -> V_29 [ 0 ] ;
}
V_116 = V_114 -> V_121 [ V_112 & V_114 -> V_122 ] ;
V_117 = V_116 -> V_9 [ V_111 & V_116 -> V_122 ] ;
F_80 () ;
V_119:
V_117 = ! V_117 ? & V_12 -> V_29 [ 0 ] : V_117 ;
F_81 ( V_12 , V_111 , V_112 , V_117 -> V_13 ) ;
return V_117 ;
}
struct V_8 * F_82 (
struct V_16 * V_12 ,
T_1 V_111 ,
T_5 V_123 )
{
T_5 V_112 = F_83 ( V_12 , V_123 ) ;
return F_76 ( V_12 , V_111 , V_112 ) ;
}
static void F_84 ( struct V_113 * V_114 )
{
int V_27 ;
for ( V_27 = 0 ; V_114 && V_27 < V_114 -> V_124 ; V_27 ++ )
F_85 ( V_114 -> V_121 [ V_27 ] ) ;
F_85 ( V_114 ) ;
}
static void F_86 ( struct V_125 * V_47 )
{
struct V_113 * V_114 = F_5 ( V_47 , struct V_113 , V_47 ) ;
F_84 ( V_114 ) ;
}
int F_87 ( struct V_16 * V_12 , T_5 V_126 , T_5 V_118 , T_5 * V_127 )
{
int V_27 , V_128 ;
int V_129 , V_130 ;
int V_131 = 0 ;
T_5 V_132 [ V_133 ] ;
struct V_113 * V_134 , * V_135 ;
if ( ! ( V_12 -> V_31 & V_136 ) )
return 0 ;
if ( ! V_127 ) {
V_130 = V_12 -> V_28 / V_118 ;
V_129 = V_12 -> V_28 % V_118 ;
V_127 = V_132 ;
for ( V_27 = V_118 - 1 ; V_27 >= 0 ; V_27 -- , V_129 -- )
V_127 [ V_27 ] = V_130 + ( V_129 > 0 ? 1 : 0 ) ;
}
V_135 = F_88 (
sizeof( struct V_113 ) +
F_89 ( V_118 ) *
sizeof( struct V_115 * ) ,
V_137 ) ;
if ( ! V_135 )
goto V_138;
V_135 -> V_124 = V_118 ;
V_135 -> V_139 = F_89 ( V_118 ) ;
V_135 -> V_122 = ( 1 << F_90 ( V_135 -> V_139 ) ) - 1 ;
for ( V_27 = 0 ; V_27 < V_140 ; V_27 ++ )
V_135 -> V_141 [ V_27 ] = - 1 ;
for ( V_27 = 0 ; V_27 < V_135 -> V_139 ; V_27 ++ ) {
int V_142 = V_131 ;
if ( V_27 < V_135 -> V_124 ) {
int V_143 = F_89 ( V_127 [ V_27 ] ) ;
V_135 -> V_121 [ V_27 ] = F_88 (
sizeof( struct V_115 ) +
V_143 * sizeof( struct V_8 * ) ,
V_137 ) ;
if ( ! V_135 -> V_121 [ V_27 ] )
goto V_138;
V_135 -> V_121 [ V_27 ] -> V_122 = ( 1 << F_90 ( V_143 ) ) - 1 ;
for ( V_128 = 0 ; V_128 < V_143 ; V_128 ++ ) {
V_135 -> V_121 [ V_27 ] -> V_9 [ V_128 ] =
& V_12 -> V_29 [ V_131 ] ;
if ( ++ V_131 >= V_142 + V_127 [ V_27 ] )
V_131 = V_142 ;
}
for ( V_128 = 0 ; V_128 < V_127 [ V_27 ] ; V_128 ++ )
V_135 -> V_141 [ V_142 + V_128 ] = V_27 ;
} else {
V_135 -> V_121 [ V_27 ] = V_135 -> V_121 [ V_27 % V_118 ] ;
}
V_131 = V_142 + V_127 [ V_27 ] ;
}
F_91 ( & V_12 -> V_144 ) ;
V_134 = F_92 ( V_12 -> V_120 ,
F_93 ( & V_12 -> V_144 ) ) ;
F_94 ( V_12 -> V_120 , V_135 ) ;
F_95 ( & V_12 -> V_144 ) ;
if ( V_134 )
F_96 ( & V_134 -> V_47 , F_86 ) ;
return 0 ;
V_138:
F_84 ( V_135 ) ;
return - V_145 ;
}
static void F_97 ( struct V_16 * V_12 , T_6 V_146 )
{
T_6 V_27 ;
struct V_8 * V_9 ;
if ( V_12 -> V_147 ) {
F_98 ( & V_12 -> V_148 -> V_149 , 4 ,
( void * ) V_12 -> V_147 ,
V_12 -> V_150 ) ;
V_12 -> V_147 = NULL ;
V_12 -> V_150 = 0 ;
}
if ( V_12 -> V_151 ) {
F_98 ( & V_12 -> V_148 -> V_149 , V_12 -> V_152 ,
( void * ) V_12 -> V_151 ,
V_12 -> V_153 ) ;
V_12 -> V_151 = NULL ;
V_12 -> V_153 = 0 ;
}
for ( V_27 = 0 ; V_12 -> V_29 && V_27 < V_146 ; ++ V_27 ) {
V_9 = & V_12 -> V_29 [ V_27 ] ;
V_9 -> V_85 = NULL ;
V_9 -> V_154 = 0 ;
if ( V_9 -> V_155 ) {
F_98 (
& V_12 -> V_148 -> V_149 ,
V_9 -> V_156 * sizeof( T_2 [ 2 ] ) ,
V_9 -> V_155 ,
V_9 -> V_157
) ;
V_9 -> V_155 = NULL ;
V_9 -> V_157 = 0 ;
}
F_99 ( V_9 -> V_77 ) ;
V_9 -> V_77 = NULL ;
}
F_91 ( & V_12 -> V_144 ) ;
F_84 ( F_100 ( V_12 -> V_120 ) ) ;
F_101 ( V_12 -> V_120 , NULL ) ;
F_95 ( & V_12 -> V_144 ) ;
F_102 () ;
F_85 ( V_12 -> V_29 ) ;
V_12 -> V_29 = NULL ;
}
int F_103 ( struct V_16 * V_12 , T_5 V_126 )
{
unsigned V_13 ;
struct V_8 * V_9 ;
T_4 V_156 ;
void * V_158 ;
struct V_159 * V_160 = V_12 -> V_24 + V_126 ;
T_1 V_161 ;
T_7 V_162 = V_163 ;
T_6 V_146 = V_12 -> V_164 ;
if ( ! F_49 ( V_165 ) ) {
F_104 ( V_61 ) ;
return 0 ;
}
if ( V_166 &&
V_166 <= V_12 -> V_164 &&
V_166 >= V_118 )
V_146 = V_166 ;
F_105 ( V_12 , L_7 , V_166 ) ;
F_105 ( V_12 , L_8 , V_12 -> V_164 ) ;
F_105 ( V_12 , L_9 ,
V_12 -> V_167 ) ;
V_161 =
V_12 -> V_167 / ( V_146 * V_168 ) ;
F_106 ( & V_12 -> V_88 ) ;
F_67 ( & V_12 -> V_87 , 0 ) ;
V_156 = F_74 () ;
F_105 ( V_12 , L_10 ,
V_146 , V_156 ) ;
V_12 -> V_29 = F_107 ( V_146 , sizeof( * V_12 -> V_29 ) , V_137 ) ;
if ( ! V_12 -> V_29 )
return - V_145 ;
V_162 = F_108 ( V_12 , V_162 ) ;
if ( ! V_169 )
V_169 = V_170 ;
for ( V_13 = 0 ; V_13 < V_146 ; ++ V_13 ) {
V_9 = & V_12 -> V_29 [ V_13 ] ;
V_9 -> V_12 = V_12 ;
V_9 -> V_160 = V_160 ;
V_9 -> V_13 = V_13 ;
V_9 -> V_156 = V_156 ;
V_9 -> V_84 = F_63 ( V_9 ) ;
V_9 -> V_171 = F_90 ( V_156 ) ;
V_9 -> V_79 = ( 1 << V_9 -> V_171 ) - 1 ;
V_9 -> V_172 = ( T_2 ) 1 << ( 0 * V_140 +
V_13 ) ;
V_9 -> V_173 = ( T_2 ) 1 << ( 1 * V_140 +
V_13 ) ;
V_9 -> V_174 = ( T_2 ) 1 << ( 2 * V_140 +
V_13 ) ;
V_9 -> V_175 = V_9 -> V_172 | V_9 -> V_173 |
V_9 -> V_174 ;
F_109 ( & V_9 -> V_69 ) ;
F_110 ( & V_9 -> V_52 ) ;
F_109 ( & V_9 -> V_176 ) ;
F_109 ( & V_9 -> V_46 ) ;
V_9 -> V_177 = 0xfffffffe00000000ULL ;
F_71 ( V_9 , V_178 ) ;
F_111 ( & V_9 -> V_2 . V_6 ) ;
F_112 ( & V_9 -> V_2 . V_7 ) ;
F_113 ( & V_9 -> V_45 ) ;
F_113 ( & V_9 -> V_179 ) ;
V_9 -> V_180 =
F_114 ( V_12 , V_13 , F_22 ( V_181 ) ) ;
if ( V_162 )
V_12 -> V_182 =
V_183 ;
else
V_12 -> V_182 =
V_184 ;
F_115 ( & V_9 -> F_56 , F_56 ,
( unsigned long ) V_9 ) ;
F_115 ( & V_9 -> F_64 , F_64 ,
( unsigned long ) V_9 ) ;
F_116 ( & V_9 -> V_53 , F_42 ) ;
F_116 ( & V_9 -> V_51 , F_38 ) ;
V_9 -> V_64 = 0 ;
F_117 ( & V_9 -> V_66 ,
F_51 , ( unsigned long ) V_9 ) ;
V_9 -> V_155 = F_118 (
& V_12 -> V_148 -> V_149 ,
V_156 * sizeof( T_2 [ 2 ] ) ,
& V_9 -> V_157 ,
V_137
) ;
if ( ! V_9 -> V_155 )
goto V_138;
V_9 -> V_77 =
F_107 ( V_156 , sizeof( struct V_36 * ) ,
V_137 ) ;
if ( ! V_9 -> V_77 )
V_9 -> V_77 =
F_119 (
sizeof( struct V_36 * ) *
V_156 ) ;
if ( ! V_9 -> V_77 )
goto V_138;
}
V_12 -> V_152 = V_185 * V_146 ;
V_12 -> V_151 = F_118 (
& V_12 -> V_148 -> V_149 ,
V_12 -> V_152 ,
& V_12 -> V_153 ,
V_137
) ;
if ( ! V_12 -> V_151 ) {
F_17 ( V_12 , L_11 ) ;
goto V_138;
}
V_12 -> V_147 = F_118 (
& V_12 -> V_148 -> V_149 ,
sizeof( T_1 ) ,
& V_12 -> V_150 ,
V_137
) ;
if ( ! V_12 -> V_147 ) {
F_17 ( V_12 , L_12 ) ;
goto V_138;
}
V_158 = ( void * ) V_12 -> V_151 ;
for ( V_13 = 0 ; V_13 < V_146 ; ++ V_13 ) {
unsigned long V_186 ;
V_9 = & V_12 -> V_29 [ V_13 ] ;
V_9 -> V_85 = V_158 ;
V_158 += V_185 ;
V_186 = ( unsigned long ) V_9 -> V_85 -
( unsigned long ) V_12 -> V_151 ;
V_9 -> V_154 = V_12 -> V_153 + V_186 ;
F_120 ( V_9 , V_161 , V_162 ) ;
}
V_12 -> V_31 |= V_136 ;
V_12 -> V_31 |= V_162 ? V_32 : 0 ;
V_12 -> V_28 = V_146 ;
if ( F_87 ( V_12 , V_126 , V_160 -> V_187 , NULL ) )
goto V_138;
F_105 ( V_12 , L_13 , V_12 -> V_28 ) ;
return 0 ;
V_138:
F_97 ( V_12 , V_146 ) ;
return - V_145 ;
}
void F_121 ( struct V_16 * V_12 )
{
struct V_8 * V_9 ;
unsigned int V_27 ;
for ( V_27 = 0 ; V_27 < V_12 -> V_28 ; ++ V_27 ) {
V_9 = & V_12 -> V_29 [ V_27 ] ;
F_46 ( V_9 , V_188 ) ;
}
}
void F_122 ( struct V_16 * V_12 )
{
struct V_8 * V_9 ;
unsigned int V_27 ;
for ( V_27 = 0 ; V_27 < V_12 -> V_28 ; ++ V_27 ) {
V_9 = & V_12 -> V_29 [ V_27 ] ;
F_46 ( V_9 , V_189 ) ;
}
}
void F_123 ( struct V_16 * V_12 )
{
unsigned V_27 ;
struct V_8 * V_9 ;
for ( V_27 = 0 ; V_27 < V_12 -> V_28 ; ++ V_27 ) {
V_9 = & V_12 -> V_29 [ V_27 ] ;
F_46 ( V_9 , V_190 ) ;
}
}
void F_124 ( struct V_16 * V_12 )
{
unsigned V_13 ;
struct V_8 * V_9 ;
for ( V_13 = 0 ; V_12 -> V_29 && V_13 < V_12 -> V_28 ;
++ V_13 ) {
V_9 = & V_12 -> V_29 [ V_13 ] ;
if ( ! F_125 ( & V_9 -> V_179 ) )
F_17 ( V_12 , L_14 ,
V_9 -> V_13 ) ;
F_46 ( V_9 , V_191 ) ;
F_126 ( & V_9 -> V_66 ) ;
F_9 ( & V_9 -> V_2 ) ;
}
F_97 ( V_12 , V_12 -> V_28 ) ;
}
static inline void F_127 (
struct V_16 * V_12 ,
struct V_192 * V_193 )
{
switch ( F_128 ( V_193 ) ) {
case V_194 :
F_129 (
& V_12 -> V_148 -> V_149 ,
F_130 ( V_193 ) ,
F_131 ( V_193 ) ,
V_195 ) ;
break;
case V_196 :
F_132 (
& V_12 -> V_148 -> V_149 ,
F_130 ( V_193 ) ,
F_131 ( V_193 ) ,
V_195 ) ;
break;
}
}
static inline T_5 F_133 ( struct V_36 * V_37 )
{
return ( V_37 -> V_193 [ 0 ] . V_197 [ 1 ] & V_198 )
>> V_199 ;
}
void F_27 (
struct V_16 * V_12 ,
struct V_36 * V_37 )
{
T_4 V_27 ;
if ( V_37 -> V_200 ) {
T_5 V_201 = 0 , V_202 = F_133 ( V_37 ) ;
F_127 ( V_12 , & V_37 -> V_193 [ 0 ] ) ;
if ( V_202 > V_203 )
V_201 = V_202 >> 1 ;
for ( V_27 = 1 + V_201 ; V_27 < V_37 -> V_200 ; V_27 ++ )
F_127 ( V_12 , & V_37 -> V_193 [ V_27 ] ) ;
V_37 -> V_200 = 0 ;
}
F_85 ( V_37 -> V_204 ) ;
V_37 -> V_204 = NULL ;
if ( F_79 ( V_37 -> V_205 > F_134 ( V_37 -> V_206 ) ) ) {
V_37 -> V_205 = F_134 ( V_37 -> V_206 ) ;
F_85 ( V_37 -> V_193 ) ;
}
}
static inline T_4 F_135 ( struct V_8 * V_9 )
{
struct V_16 * V_12 = V_9 -> V_12 ;
int V_207 ;
T_4 V_208 ;
#ifdef F_57
F_17 ( V_9 -> V_12 , L_6 ,
V_9 -> V_13 , F_58 ( __FILE__ ) , __LINE__ , V_23 ) ;
#endif
V_209:
V_207 = F_49 ( V_210 ) && F_40 ( V_9 ) &&
( V_12 -> V_31 & V_32 ) ;
V_208 = V_207 ?
( T_4 ) F_136 ( * V_9 -> V_85 ) :
( T_4 ) F_13 ( V_9 , F_22 ( V_211 ) ) ;
if ( F_79 ( F_49 ( V_212 ) ) ) {
T_4 V_30 ;
T_4 V_213 ;
T_4 V_214 ;
int V_215 ;
V_214 = V_9 -> V_65 & V_9 -> V_79 ;
V_213 = F_137 ( V_9 -> V_72 ) & V_9 -> V_79 ;
V_30 = V_9 -> V_156 ;
if ( V_214 < V_213 )
V_215 = ( V_208 >= V_214 ) & ( V_208 <= V_213 ) ;
else if ( V_214 > V_213 )
V_215 = ( ( V_208 >= V_214 ) && ( V_208 < V_30 ) ) ||
( V_208 <= V_213 ) ;
else
V_215 = ( V_208 == V_214 ) ;
if ( F_79 ( ! V_215 ) ) {
F_17 ( V_12 , L_15 ,
V_9 -> V_13 ,
V_207 ? L_16 : L_17 ,
V_208 , V_214 , V_213 , V_30 ) ;
if ( V_207 ) {
V_207 = 0 ;
goto V_209;
}
V_208 = V_214 ;
}
}
return V_208 ;
}
static void F_62 ( struct V_8 * V_9 , unsigned V_216 )
{
struct V_39 * V_40 , * V_217 ;
struct V_39 * V_218 [ V_219 ] ;
unsigned V_27 , V_220 = 0 , V_221 ;
struct V_36 * V_222 ;
struct V_223 * V_149 = & V_9 -> V_12 -> V_224 ;
#ifdef F_57
F_17 ( V_9 -> V_12 , L_6 , V_9 -> V_13 ,
F_58 ( __FILE__ ) , __LINE__ , V_23 ) ;
F_17 ( V_9 -> V_12 , L_18 , V_216 ) ;
#endif
do {
V_221 = F_138 ( & V_149 -> V_225 ) ;
if ( ! F_125 ( & V_9 -> V_179 ) ) {
F_52 ( & V_149 -> V_225 ) ;
F_34 (
wait,
nw,
&sde->dmawait,
list) {
T_4 V_200 = 0 ;
if ( ! V_40 -> V_226 )
continue;
if ( V_220 == F_134 ( V_218 ) )
break;
if ( ! F_125 ( & V_40 -> V_78 ) ) {
V_222 = F_139 (
& V_40 -> V_78 ,
struct V_36 ,
V_47 ) ;
V_200 = V_222 -> V_200 ;
}
if ( V_200 > V_216 )
break;
V_216 -= V_200 ;
F_35 ( & V_40 -> V_47 ) ;
V_218 [ V_220 ++ ] = V_40 ;
}
F_53 ( & V_149 -> V_225 ) ;
break;
}
} while ( F_140 ( & V_149 -> V_225 , V_221 ) );
for ( V_27 = 0 ; V_27 < V_220 ; V_27 ++ )
V_218 [ V_27 ] -> V_226 ( V_218 [ V_27 ] , V_227 ) ;
}
static void F_65 ( struct V_8 * V_9 , T_2 V_228 )
{
struct V_36 * V_43 = NULL ;
int V_82 = 0 ;
T_4 V_208 , V_214 ;
int V_229 = 0 ;
V_208 = F_135 ( V_9 ) ;
V_209:
V_43 = F_59 ( V_9 ) ;
V_214 = V_9 -> V_65 & V_9 -> V_79 ;
F_61 ( V_9 , V_208 , V_214 , V_43 ) ;
while ( V_214 != V_208 ) {
V_214 = ++ V_9 -> V_65 & V_9 -> V_79 ;
if ( V_43 && V_43 -> V_83 == V_214 ) {
V_9 -> V_77 [ V_9 -> V_78 ++ & V_9 -> V_79 ] = NULL ;
F_23 ( V_9 , V_43 , V_230 ) ;
V_43 = F_59 ( V_9 ) ;
}
F_61 ( V_9 , V_208 , V_214 , V_43 ) ;
V_82 ++ ;
}
if ( ( V_228 & V_9 -> V_174 ) && ! V_229 ) {
T_4 V_213 ;
V_213 = F_137 ( V_9 -> V_72 ) & V_9 -> V_79 ;
if ( V_213 != V_208 ) {
V_208 = ( T_4 ) F_13 ( V_9 , F_22 ( V_211 ) ) ;
V_229 = 1 ;
goto V_209;
}
}
V_9 -> V_231 = V_228 ;
if ( V_82 )
F_62 ( V_9 , F_63 ( V_9 ) ) ;
}
void F_141 ( struct V_8 * V_9 , T_2 V_228 )
{
F_142 ( V_9 , V_228 ) ;
F_52 ( & V_9 -> V_52 ) ;
F_21 ( V_9 , V_169 ) ;
if ( V_228 & V_9 -> V_174 )
V_9 -> V_232 ++ ;
else if ( V_228 & V_9 -> V_173 )
V_9 -> V_233 ++ ;
else if ( V_228 & V_9 -> V_172 )
V_9 -> V_234 ++ ;
F_65 ( V_9 , V_228 ) ;
F_53 ( & V_9 -> V_52 ) ;
}
void F_143 ( struct V_8 * V_9 , T_2 V_228 )
{
unsigned long V_31 ;
#ifdef F_57
F_17 ( V_9 -> V_12 , L_19 ,
V_9 -> V_13 ,
( unsigned long long ) V_228 ,
V_3 [ V_9 -> V_2 . V_70 ] ) ;
#endif
F_33 ( & V_9 -> V_69 , V_31 ) ;
F_52 ( & V_9 -> V_52 ) ;
if ( V_228 & V_235 )
F_54 ( V_9 , V_236 ) ;
if ( V_228 & ~ F_22 ( V_237 ) ) {
F_17 ( V_9 -> V_12 ,
L_20 ,
V_9 -> V_13 ,
( unsigned long long ) V_228 ,
V_3 [ V_9 -> V_2 . V_70 ] ) ;
F_144 ( V_9 ) ;
}
F_53 ( & V_9 -> V_52 ) ;
F_37 ( & V_9 -> V_69 , V_31 ) ;
}
static void F_73 ( struct V_8 * V_9 , unsigned V_93 )
{
T_2 V_238 = 0 ;
T_2 V_239 = 0 ;
unsigned long V_31 ;
#ifdef F_57
F_17 ( V_9 -> V_12 , L_21 ,
V_9 -> V_13 ,
( V_93 & V_98 ) ? 1 : 0 ,
( V_93 & V_100 ) ? 1 : 0 ,
( V_93 & V_102 ) ? 1 : 0 ,
( V_93 & V_104 ) ? 1 : 0 ) ;
#endif
if ( V_93 & V_98 )
V_238 |= F_22 ( V_240 ) ;
else
V_239 |= F_22 ( V_240 ) ;
if ( V_93 & V_100 )
V_238 |= F_22 ( V_241 ) ;
else
V_239 |= F_22 ( V_241 ) ;
if ( V_93 & V_102 )
V_238 |= F_22 ( V_242 ) ;
else
V_239 |= F_22 ( V_242 ) ;
F_33 ( & V_9 -> V_176 , V_31 ) ;
V_9 -> V_243 |= V_238 ;
V_9 -> V_243 &= ~ V_239 ;
if ( V_93 & V_104 )
F_11 ( V_9 , F_22 ( V_244 ) ,
V_9 -> V_243 |
F_22 ( V_245 ) ) ;
else
F_11 ( V_9 , F_22 ( V_244 ) , V_9 -> V_243 ) ;
F_37 ( & V_9 -> V_176 , V_31 ) ;
#ifdef F_57
F_145 ( V_9 ) ;
#endif
}
static void F_146 ( struct V_8 * V_9 )
{
#ifdef F_57
F_17 ( V_9 -> V_12 , L_6 ,
V_9 -> V_13 , F_58 ( __FILE__ ) , __LINE__ , V_23 ) ;
#endif
F_11 ( V_9 , F_22 ( V_246 ) ,
( V_9 -> V_156 / 64 ) << F_22 ( V_247 ) ) ;
F_11 ( V_9 , F_22 ( V_246 ) ,
( ( V_9 -> V_156 / 64 ) << F_22 ( V_247 ) ) |
( 4ULL << F_22 ( V_248 ) ) ) ;
}
static inline void F_147 ( struct V_8 * V_9 , T_4 V_81 )
{
F_148 () ;
F_149 ( V_81 , V_9 -> V_180 ) ;
}
static void F_150 ( struct V_8 * V_9 )
{
T_2 V_19 ;
#ifdef F_57
F_17 ( V_9 -> V_12 , L_6 ,
V_9 -> V_13 , F_58 ( __FILE__ ) , __LINE__ , V_23 ) ;
#endif
F_146 ( V_9 ) ;
F_147 ( V_9 , 0 ) ;
* V_9 -> V_85 = 0 ;
V_19 = F_22 ( V_249 ) <<
F_22 ( V_250 ) ;
F_11 ( V_9 , F_22 ( V_251 ) , V_19 ) ;
}
static void F_151 ( struct V_8 * V_9 )
{
struct V_16 * V_12 = V_9 -> V_12 ;
T_2 V_19 ;
if ( F_79 ( F_49 ( V_252 ) ) )
return;
V_19 = F_152 ( V_12 ) ;
if ( F_49 ( V_253 ) )
F_153 ( V_19 ) ;
else
F_154 ( V_19 ) ;
F_11 ( V_9 , F_22 ( V_254 ) , V_19 ) ;
}
static void F_120 (
struct V_8 * V_9 ,
T_1 V_255 ,
T_7 V_162 )
{
T_5 V_256 , V_257 ;
#ifdef F_57
struct V_16 * V_12 = V_9 -> V_12 ;
F_17 ( V_12 , L_6 ,
V_9 -> V_13 , F_58 ( __FILE__ ) , __LINE__ , V_23 ) ;
#endif
F_11 ( V_9 , F_22 ( V_258 ) , V_9 -> V_157 ) ;
F_146 ( V_9 ) ;
F_147 ( V_9 , 0 ) ;
F_11 ( V_9 , F_22 ( V_259 ) , V_162 ) ;
F_11 ( V_9 , F_22 ( V_35 ) , 0 ) ;
F_11 ( V_9 , F_22 ( V_260 ) , V_9 -> V_154 ) ;
F_11 ( V_9 , F_22 ( V_261 ) ,
( ( T_2 ) V_255 << F_22 ( V_262 ) ) |
( ( T_2 ) ( V_255 * V_9 -> V_13 ) <<
F_22 ( V_263 ) ) ) ;
F_11 ( V_9 , F_22 ( V_264 ) , ~ 0ull ) ;
F_151 ( V_9 ) ;
V_257 = V_265 ;
V_256 = V_266 ;
F_11 ( V_9 , F_22 ( V_267 ) ,
( V_257 << V_268 ) |
( V_256 << V_269 ) ) ;
}
void F_145 ( struct V_8 * V_9 )
{
T_2 V_270 ;
unsigned V_27 ;
F_155 ( F_22 ( V_244 ) ) ;
F_155 ( F_22 ( V_58 ) ) ;
F_156 ( F_22 ( V_271 ) ) ;
F_156 ( F_22 ( V_272 ) ) ;
F_155 ( F_22 ( V_273 ) ) ;
F_155 ( F_22 ( V_264 ) ) ;
for ( V_27 = 0 ; V_27 < V_274 ; ++ V_27 ) {
F_157 ( V_275 ) ;
F_157 ( V_276 ) ;
F_157 ( V_277 ) ;
}
F_155 ( F_22 ( V_181 ) ) ;
F_155 ( F_22 ( V_211 ) ) ;
F_155 ( F_22 ( V_278 ) ) ;
F_155 ( F_22 ( V_279 ) ) ;
F_155 ( F_22 ( V_259 ) ) ;
F_155 ( F_22 ( V_35 ) ) ;
F_155 ( F_22 ( V_280 ) ) ;
F_155 ( F_22 ( V_261 ) ) ;
F_156 ( F_22 ( V_281 ) ) ;
F_156 ( F_22 ( V_282 ) ) ;
F_155 ( F_22 ( V_258 ) ) ;
F_155 ( F_22 ( V_246 ) ) ;
F_155 ( F_22 ( V_260 ) ) ;
F_155 ( F_22 ( V_254 ) ) ;
F_155 ( F_22 ( V_283 ) ) ;
F_155 ( F_22 ( V_284 ) ) ;
F_155 ( F_22 ( V_285 ) ) ;
F_155 ( F_22 ( V_286 ) ) ;
F_155 ( F_22 ( V_267 ) ) ;
}
static void F_144 ( struct V_8 * V_9 )
{
struct V_287 * V_155 ;
struct V_287 * V_288 ;
T_2 V_289 [ 2 ] ;
T_2 V_290 ;
T_5 V_291 ;
T_4 V_292 ;
T_4 V_80 , V_81 , V_30 ;
V_80 = V_9 -> V_65 & V_9 -> V_79 ;
V_81 = V_9 -> V_72 & V_9 -> V_79 ;
V_30 = F_63 ( V_9 ) ;
V_155 = V_9 -> V_155 ;
F_17 ( V_9 -> V_12 ,
L_22 ,
V_9 -> V_13 , V_80 , V_81 , V_30 ,
! F_125 ( & V_9 -> V_45 ) ) ;
while ( V_80 != V_81 ) {
char V_31 [ 6 ] = { 'x' , 'x' , 'x' , 'x' , 0 } ;
V_288 = & V_9 -> V_155 [ V_80 ] ;
V_289 [ 0 ] = F_136 ( V_288 -> V_197 [ 0 ] ) ;
V_289 [ 1 ] = F_136 ( V_288 -> V_197 [ 1 ] ) ;
V_31 [ 0 ] = ( V_289 [ 1 ] & V_184 ) ? 'I' : '-' ;
V_31 [ 1 ] = ( V_289 [ 1 ] & V_183 ) ?
'H' : '-' ;
V_31 [ 2 ] = ( V_289 [ 0 ] & V_293 ) ? 'F' : '-' ;
V_31 [ 3 ] = ( V_289 [ 0 ] & V_294 ) ? 'L' : '-' ;
V_290 = ( V_289 [ 0 ] >> V_295 )
& V_296 ;
V_291 = ( V_289 [ 1 ] >> V_297 )
& V_298 ;
V_292 = ( V_289 [ 0 ] >> V_299 )
& V_300 ;
F_17 ( V_9 -> V_12 ,
L_23 ,
V_80 , V_31 , V_290 , V_291 , V_292 ) ;
F_17 ( V_9 -> V_12 ,
L_24 ,
V_289 [ 0 ] , V_289 [ 1 ] ) ;
if ( V_289 [ 0 ] & V_293 )
F_17 ( V_9 -> V_12 ,
L_25 ,
( T_5 ) ( ( V_289 [ 1 ] &
V_301 ) >>
V_302 ) ,
( T_5 ) ( ( V_289 [ 1 ] &
V_198 ) >>
V_199 ) ,
( T_5 ) ( ( V_289 [ 1 ] &
V_303 ) >>
V_304 ) ) ;
V_80 ++ ;
V_80 &= V_9 -> V_79 ;
}
}
void F_158 ( struct V_305 * V_306 , struct V_8 * V_9 )
{
T_4 V_80 , V_81 ;
struct V_287 * V_288 ;
T_2 V_289 [ 2 ] ;
T_2 V_290 ;
T_5 V_291 ;
T_4 V_292 ;
V_80 = V_9 -> V_65 & V_9 -> V_79 ;
V_81 = F_137 ( V_9 -> V_72 ) & V_9 -> V_79 ;
F_159 ( V_306 , V_307 , V_9 -> V_13 ,
V_9 -> V_308 ,
F_1 ( V_9 -> V_2 . V_70 ) ,
( unsigned long long ) F_13 ( V_9 , F_22 ( V_244 ) ) ,
( unsigned long long ) F_13 ( V_9 , F_22 ( V_58 ) ) ,
( unsigned long long ) F_13 ( V_9 , F_22 ( V_273 ) ) ,
( unsigned long long ) F_13 ( V_9 , F_22 ( V_181 ) ) , V_81 ,
( unsigned long long ) F_13 ( V_9 , F_22 ( V_211 ) ) , V_80 ,
( unsigned long long ) F_136 ( * V_9 -> V_85 ) ,
( unsigned long long ) F_13 ( V_9 , F_22 ( V_261 ) ) ,
( unsigned long long ) F_13 ( V_9 , F_22 ( V_246 ) ) ,
( unsigned long long ) F_13 ( V_9 , F_22 ( V_259 ) ) ,
( unsigned long long ) V_9 -> V_231 ,
( unsigned long long ) V_9 -> V_177 ,
V_9 -> V_309 ,
V_9 -> V_78 ,
V_9 -> V_72 ,
V_9 -> V_65 ,
! F_125 ( & V_9 -> V_45 ) ,
V_9 -> V_310 ,
( unsigned long long ) F_13 ( V_9 , V_311 ) ) ;
while ( V_80 != V_81 ) {
char V_31 [ 6 ] = { 'x' , 'x' , 'x' , 'x' , 0 } ;
V_288 = & V_9 -> V_155 [ V_80 ] ;
V_289 [ 0 ] = F_136 ( V_288 -> V_197 [ 0 ] ) ;
V_289 [ 1 ] = F_136 ( V_288 -> V_197 [ 1 ] ) ;
V_31 [ 0 ] = ( V_289 [ 1 ] & V_184 ) ? 'I' : '-' ;
V_31 [ 1 ] = ( V_289 [ 1 ] & V_183 ) ?
'H' : '-' ;
V_31 [ 2 ] = ( V_289 [ 0 ] & V_293 ) ? 'F' : '-' ;
V_31 [ 3 ] = ( V_289 [ 0 ] & V_294 ) ? 'L' : '-' ;
V_290 = ( V_289 [ 0 ] >> V_295 )
& V_296 ;
V_291 = ( V_289 [ 1 ] >> V_297 )
& V_298 ;
V_292 = ( V_289 [ 0 ] >> V_299 )
& V_300 ;
F_159 ( V_306 ,
L_26 ,
V_80 , V_31 , V_290 , V_291 , V_292 ) ;
if ( V_289 [ 0 ] & V_293 )
F_159 ( V_306 , L_27 ,
( T_5 ) ( ( V_289 [ 1 ] &
V_301 ) >>
V_302 ) ,
( T_5 ) ( ( V_289 [ 1 ] &
V_198 ) >>
V_199 ) ) ;
V_80 = ( V_80 + 1 ) & V_9 -> V_79 ;
}
}
static inline T_2 F_160 ( struct V_8 * V_9 , T_2 V_312 )
{
T_5 V_313 = ( V_9 -> V_72 >> V_9 -> V_171 ) & 3 ;
V_312 &= ~ V_314 ;
V_312 |= ( ( T_2 ) V_313 & V_298 )
<< V_297 ;
return V_312 ;
}
static inline T_4 F_161 ( struct V_8 * V_9 , struct V_36 * V_37 )
{
int V_27 ;
T_4 V_81 ;
struct V_192 * V_193 = V_37 -> V_193 ;
T_5 V_201 = 0 , V_202 = F_133 ( V_37 ) ;
V_81 = V_9 -> V_72 & V_9 -> V_79 ;
V_9 -> V_155 [ V_81 ] . V_197 [ 0 ] = F_162 ( V_193 -> V_197 [ 0 ] ) ;
V_9 -> V_155 [ V_81 ] . V_197 [ 1 ] = F_162 ( F_160 ( V_9 , V_193 -> V_197 [ 1 ] ) ) ;
F_163 ( V_9 , V_193 -> V_197 [ 0 ] , V_193 -> V_197 [ 1 ] ,
V_81 , & V_9 -> V_155 [ V_81 ] ) ;
V_81 = ++ V_9 -> V_72 & V_9 -> V_79 ;
V_193 ++ ;
if ( V_202 > V_203 )
V_201 = V_202 >> 1 ;
for ( V_27 = 1 ; V_27 < V_37 -> V_200 ; V_27 ++ , V_193 ++ ) {
T_2 V_312 ;
V_9 -> V_155 [ V_81 ] . V_197 [ 0 ] = F_162 ( V_193 -> V_197 [ 0 ] ) ;
if ( V_201 ) {
V_312 = V_193 -> V_197 [ 1 ] ;
V_201 -- ;
} else {
V_312 = F_160 ( V_9 , V_193 -> V_197 [ 1 ] ) ;
}
V_9 -> V_155 [ V_81 ] . V_197 [ 1 ] = F_162 ( V_312 ) ;
F_163 ( V_9 , V_193 -> V_197 [ 0 ] , V_312 ,
V_81 , & V_9 -> V_155 [ V_81 ] ) ;
V_81 = ++ V_9 -> V_72 & V_9 -> V_79 ;
}
V_37 -> V_83 = V_81 ;
#ifdef F_24
V_37 -> V_41 = V_9 -> V_315 ++ ;
F_164 ( V_9 , V_37 -> V_41 ) ;
F_26 ( V_9 -> V_77 [ V_9 -> V_309 & V_9 -> V_79 ] ) ;
#endif
V_9 -> V_77 [ V_9 -> V_309 ++ & V_9 -> V_79 ] = V_37 ;
V_9 -> V_84 -= V_37 -> V_200 ;
return V_81 ;
}
static int F_165 (
struct V_8 * V_9 ,
struct V_39 * V_40 ,
struct V_36 * V_37 )
{
int V_316 ;
V_9 -> V_84 = F_63 ( V_9 ) ;
if ( V_37 -> V_200 <= V_9 -> V_84 )
return - V_317 ;
if ( V_40 && V_40 -> V_318 ) {
unsigned V_221 ;
V_221 = F_166 (
( const V_319 * ) & V_9 -> V_52 . V_320 ) ;
V_316 = V_40 -> V_318 ( V_9 , V_40 , V_37 , V_221 ) ;
if ( V_316 == - V_317 )
V_9 -> V_84 = F_63 ( V_9 ) ;
} else {
V_316 = - V_321 ;
}
return V_316 ;
}
int F_167 ( struct V_8 * V_9 ,
struct V_39 * V_40 ,
struct V_36 * V_37 )
{
int V_316 = 0 ;
T_4 V_81 ;
unsigned long V_31 ;
if ( F_79 ( V_37 -> V_322 ) )
return - V_323 ;
V_37 -> V_40 = V_40 ;
F_33 ( & V_9 -> V_69 , V_31 ) ;
V_209:
if ( F_79 ( ! F_40 ( V_9 ) ) )
goto V_324;
if ( F_79 ( V_37 -> V_200 > V_9 -> V_84 ) )
goto V_325;
V_81 = F_161 ( V_9 , V_37 ) ;
if ( V_40 )
F_168 ( V_40 ) ;
F_147 ( V_9 , V_81 ) ;
V_326:
F_37 ( & V_9 -> V_69 , V_31 ) ;
return V_316 ;
V_324:
if ( V_40 )
F_168 ( V_40 ) ;
V_37 -> V_83 = 0 ;
#ifdef F_24
V_37 -> V_41 = V_9 -> V_315 ++ ;
F_164 ( V_9 , V_37 -> V_41 ) ;
#endif
F_169 ( & V_9 -> V_46 ) ;
F_36 ( & V_37 -> V_47 , & V_9 -> V_45 ) ;
F_170 ( & V_9 -> V_46 ) ;
if ( V_40 ) {
V_40 -> V_327 ++ ;
V_40 -> V_108 += V_37 -> V_200 ;
}
F_55 ( & V_9 -> V_51 ) ;
V_316 = - V_328 ;
goto V_326;
V_325:
V_316 = F_165 ( V_9 , V_40 , V_37 ) ;
if ( V_316 == - V_317 ) {
V_316 = 0 ;
goto V_209;
}
V_9 -> V_310 ++ ;
goto V_326;
}
int F_171 ( struct V_8 * V_9 , struct V_39 * V_40 ,
struct V_329 * V_330 )
{
struct V_36 * V_37 , * V_331 ;
int V_316 = 0 ;
unsigned long V_31 ;
T_4 V_81 = V_332 ;
int V_108 = 0 ;
F_33 ( & V_9 -> V_69 , V_31 ) ;
V_209:
F_34 (tx, tx_next, tx_list, list) {
V_37 -> V_40 = V_40 ;
if ( F_79 ( ! F_40 ( V_9 ) ) )
goto V_324;
if ( F_79 ( V_37 -> V_200 > V_9 -> V_84 ) )
goto V_325;
if ( F_79 ( V_37 -> V_322 ) ) {
V_316 = - V_323 ;
goto V_333;
}
F_35 ( & V_37 -> V_47 ) ;
V_81 = F_161 ( V_9 , V_37 ) ;
V_108 ++ ;
if ( V_81 != V_332 &&
( V_108 & V_334 ) == 0 ) {
F_147 ( V_9 , V_81 ) ;
V_81 = V_332 ;
}
}
V_333:
if ( V_40 )
F_172 ( V_40 , V_108 ) ;
if ( V_81 != V_332 )
F_147 ( V_9 , V_81 ) ;
F_37 ( & V_9 -> V_69 , V_31 ) ;
return V_316 == 0 ? V_108 : V_316 ;
V_324:
F_169 ( & V_9 -> V_46 ) ;
F_34 (tx, tx_next, tx_list, list) {
V_37 -> V_40 = V_40 ;
F_35 ( & V_37 -> V_47 ) ;
if ( V_40 )
F_168 ( V_40 ) ;
V_37 -> V_83 = 0 ;
#ifdef F_24
V_37 -> V_41 = V_9 -> V_315 ++ ;
F_164 ( V_9 , V_37 -> V_41 ) ;
#endif
F_36 ( & V_37 -> V_47 , & V_9 -> V_45 ) ;
if ( V_40 ) {
V_40 -> V_327 ++ ;
V_40 -> V_108 += V_37 -> V_200 ;
}
}
F_170 ( & V_9 -> V_46 ) ;
F_55 ( & V_9 -> V_51 ) ;
V_316 = - V_328 ;
goto V_333;
V_325:
V_316 = F_165 ( V_9 , V_40 , V_37 ) ;
if ( V_316 == - V_317 ) {
V_316 = 0 ;
goto V_209;
}
V_9 -> V_310 ++ ;
goto V_333;
}
static void F_46 ( struct V_8 * V_9 , enum V_335 V_336 )
{
unsigned long V_31 ;
F_33 ( & V_9 -> V_69 , V_31 ) ;
F_52 ( & V_9 -> V_52 ) ;
F_54 ( V_9 , V_336 ) ;
if ( V_9 -> V_2 . V_70 == V_71 )
F_62 ( V_9 , F_63 ( V_9 ) ) ;
F_53 ( & V_9 -> V_52 ) ;
F_37 ( & V_9 -> V_69 , V_31 ) ;
}
static void F_54 ( struct V_8 * V_9 ,
enum V_335 V_336 )
{
struct V_4 * V_5 = & V_9 -> V_2 ;
int V_337 = 0 ;
#ifdef F_57
F_17 ( V_9 -> V_12 , L_28 , V_9 -> V_13 ,
V_3 [ V_5 -> V_70 ] ,
V_338 [ V_336 ] ) ;
#endif
switch ( V_5 -> V_70 ) {
case V_178 :
switch ( V_336 ) {
case V_191 :
break;
case V_188 :
V_5 -> V_106 = 1 ;
case V_190 :
F_2 ( & V_9 -> V_2 ) ;
F_71 ( V_9 ,
V_339 ) ;
break;
case V_60 :
break;
case V_76 :
break;
case V_86 :
F_66 ( V_9 ) ;
break;
case V_340 :
break;
case V_236 :
break;
case V_189 :
break;
case V_341 :
break;
case V_342 :
break;
case V_343 :
break;
case V_344 :
break;
case V_73 :
break;
}
break;
case V_339 :
switch ( V_336 ) {
case V_191 :
F_71 ( V_9 , V_178 ) ;
F_66 ( V_9 ) ;
break;
case V_190 :
break;
case V_60 :
F_71 ( V_9 ,
V_345 ) ;
F_69 ( V_9 ) ;
break;
case V_76 :
break;
case V_188 :
V_5 -> V_106 = 1 ;
break;
case V_86 :
break;
case V_340 :
break;
case V_236 :
F_55 ( & V_9 -> V_53 ) ;
break;
case V_189 :
V_5 -> V_106 = 0 ;
break;
case V_341 :
break;
case V_342 :
break;
case V_343 :
break;
case V_344 :
break;
case V_73 :
break;
}
break;
case V_345 :
switch ( V_336 ) {
case V_191 :
F_71 ( V_9 , V_178 ) ;
F_66 ( V_9 ) ;
break;
case V_190 :
break;
case V_60 :
break;
case V_76 :
F_150 ( V_9 ) ;
F_71 ( V_9 , V_5 -> V_106 ?
V_71 :
V_346 ) ;
break;
case V_188 :
V_5 -> V_106 = 1 ;
break;
case V_86 :
break;
case V_340 :
break;
case V_236 :
break;
case V_189 :
V_5 -> V_106 = 0 ;
break;
case V_341 :
break;
case V_342 :
break;
case V_343 :
break;
case V_344 :
break;
case V_73 :
break;
}
break;
case V_346 :
switch ( V_336 ) {
case V_191 :
F_71 ( V_9 , V_178 ) ;
F_66 ( V_9 ) ;
break;
case V_190 :
break;
case V_60 :
break;
case V_76 :
break;
case V_188 :
F_71 ( V_9 , V_71 ) ;
V_5 -> V_106 = 1 ;
break;
case V_86 :
break;
case V_340 :
break;
case V_236 :
F_71 ( V_9 , V_347 ) ;
F_55 ( & V_9 -> V_53 ) ;
break;
case V_189 :
break;
case V_344 :
case V_341 :
F_71 ( V_9 , V_348 ) ;
F_173 ( & V_9 -> V_12 -> V_87 ) ;
F_68 ( & V_9 -> V_12 -> V_88 ) ;
break;
case V_342 :
break;
case V_343 :
break;
case V_73 :
break;
}
break;
case V_349 :
switch ( V_336 ) {
case V_191 :
F_71 ( V_9 , V_178 ) ;
break;
case V_190 :
break;
case V_60 :
break;
case V_76 :
break;
case V_188 :
V_5 -> V_106 = 1 ;
break;
case V_86 :
F_71 ( V_9 , V_350 ) ;
F_69 ( V_9 ) ;
break;
case V_340 :
break;
case V_236 :
break;
case V_189 :
V_5 -> V_106 = 0 ;
break;
case V_341 :
break;
case V_342 :
break;
case V_343 :
break;
case V_344 :
V_5 -> V_106 = 0 ;
break;
case V_73 :
break;
}
break;
case V_350 :
switch ( V_336 ) {
case V_191 :
F_71 ( V_9 , V_178 ) ;
F_70 ( & V_9 -> F_64 ) ;
break;
case V_190 :
break;
case V_60 :
break;
case V_76 :
F_150 ( V_9 ) ;
F_71 ( V_9 , V_5 -> V_106 ?
V_71 :
V_346 ) ;
break;
case V_188 :
V_5 -> V_106 = 1 ;
break;
case V_86 :
break;
case V_340 :
break;
case V_236 :
break;
case V_189 :
V_5 -> V_106 = 0 ;
break;
case V_341 :
break;
case V_342 :
break;
case V_343 :
break;
case V_344 :
V_5 -> V_106 = 0 ;
break;
case V_73 :
break;
}
break;
case V_347 :
switch ( V_336 ) {
case V_191 :
F_71 ( V_9 , V_178 ) ;
F_70 ( & V_9 -> F_64 ) ;
break;
case V_190 :
break;
case V_60 :
F_71 ( V_9 , V_349 ) ;
F_70 ( & V_9 -> F_64 ) ;
break;
case V_76 :
break;
case V_188 :
V_5 -> V_106 = 1 ;
break;
case V_86 :
break;
case V_340 :
break;
case V_236 :
F_55 ( & V_9 -> V_53 ) ;
break;
case V_189 :
V_5 -> V_106 = 0 ;
break;
case V_341 :
break;
case V_342 :
break;
case V_343 :
break;
case V_344 :
V_5 -> V_106 = 0 ;
break;
case V_73 :
break;
}
break;
case V_351 :
switch ( V_336 ) {
case V_191 :
F_71 ( V_9 , V_178 ) ;
F_70 ( & V_9 -> F_64 ) ;
break;
case V_190 :
break;
case V_60 :
F_71 ( V_9 , V_349 ) ;
F_70 ( & V_9 -> F_64 ) ;
break;
case V_76 :
break;
case V_188 :
V_5 -> V_106 = 1 ;
break;
case V_86 :
break;
case V_340 :
break;
case V_236 :
F_55 ( & V_9 -> V_53 ) ;
break;
case V_189 :
V_5 -> V_106 = 0 ;
break;
case V_341 :
break;
case V_342 :
break;
case V_343 :
break;
case V_344 :
break;
case V_73 :
break;
}
break;
case V_348 :
switch ( V_336 ) {
case V_191 :
F_71 ( V_9 , V_178 ) ;
F_70 ( & V_9 -> F_64 ) ;
break;
case V_190 :
break;
case V_60 :
break;
case V_76 :
break;
case V_188 :
V_5 -> V_106 = 1 ;
break;
case V_86 :
break;
case V_340 :
break;
case V_236 :
break;
case V_189 :
V_5 -> V_106 = 0 ;
break;
case V_341 :
break;
case V_342 :
F_71 ( V_9 , V_352 ) ;
F_70 ( & V_9 -> F_64 ) ;
break;
case V_343 :
break;
case V_344 :
break;
case V_73 :
break;
}
break;
case V_352 :
switch ( V_336 ) {
case V_191 :
F_71 ( V_9 , V_178 ) ;
F_70 ( & V_9 -> F_64 ) ;
break;
case V_190 :
break;
case V_60 :
break;
case V_76 :
break;
case V_188 :
V_5 -> V_106 = 1 ;
break;
case V_86 :
F_173 ( & V_9 -> V_12 -> V_87 ) ;
F_68 ( & V_9 -> V_12 -> V_88 ) ;
break;
case V_340 :
break;
case V_236 :
break;
case V_189 :
V_5 -> V_106 = 0 ;
break;
case V_341 :
break;
case V_342 :
break;
case V_343 :
F_150 ( V_9 ) ;
F_71 ( V_9 , V_5 -> V_106 ?
V_71 :
V_346 ) ;
break;
case V_344 :
break;
case V_73 :
break;
}
break;
case V_71 :
switch ( V_336 ) {
case V_191 :
F_71 ( V_9 , V_178 ) ;
F_70 ( & V_9 -> F_64 ) ;
break;
case V_190 :
break;
case V_60 :
break;
case V_76 :
break;
case V_188 :
break;
case V_86 :
break;
case V_340 :
break;
case V_236 :
V_337 = 1 ;
F_47 ( V_9 ) ;
case V_73 :
F_71 ( V_9 , V_347 ) ;
F_55 ( & V_9 -> V_53 ) ;
break;
case V_189 :
F_71 ( V_9 , V_351 ) ;
break;
case V_344 :
V_5 -> V_106 = 0 ;
case V_341 :
F_71 ( V_9 , V_348 ) ;
F_173 ( & V_9 -> V_12 -> V_87 ) ;
F_68 ( & V_9 -> V_12 -> V_88 ) ;
break;
case V_342 :
break;
case V_343 :
break;
}
break;
}
V_5 -> V_353 = V_336 ;
if ( V_337 )
F_65 ( V_9 , 0 ) ;
}
static int F_174 ( struct V_16 * V_12 , struct V_36 * V_37 )
{
int V_27 ;
if ( F_79 ( ( V_37 -> V_200 == ( V_354 - 1 ) ) ) ) {
if ( ! V_37 -> V_322 ) {
V_37 -> V_205 = V_354 ;
} else if ( ! V_37 -> V_204 ) {
V_37 -> V_204 = F_175 ( V_37 -> V_322 + sizeof( T_1 ) ,
V_355 ) ;
if ( ! V_37 -> V_204 )
goto V_356;
V_37 -> V_357 = 0 ;
}
return 0 ;
}
if ( F_79 ( V_37 -> V_200 == V_354 ) )
goto V_356;
V_37 -> V_193 = F_176 (
V_354 ,
sizeof( struct V_192 ) ,
V_355 ) ;
if ( ! V_37 -> V_193 )
goto V_356;
V_37 -> V_205 = V_354 - 1 ;
for ( V_27 = 0 ; V_27 < V_37 -> V_200 ; V_27 ++ )
V_37 -> V_193 [ V_27 ] = V_37 -> V_206 [ V_27 ] ;
return 0 ;
V_356:
F_27 ( V_12 , V_37 ) ;
return - V_145 ;
}
int F_177 ( struct V_16 * V_12 , struct V_36 * V_37 ,
int type , void * V_358 , struct V_359 * V_359 ,
unsigned long V_360 , T_4 V_292 )
{
int V_361 , V_117 ;
T_8 V_290 ;
V_117 = F_174 ( V_12 , V_37 ) ;
if ( V_117 ) {
F_27 ( V_12 , V_37 ) ;
return V_117 ;
}
if ( V_37 -> V_204 ) {
if ( type == V_362 ) {
F_27 ( V_12 , V_37 ) ;
return - V_323 ;
}
if ( type == V_196 ) {
V_358 = F_178 ( V_359 ) ;
V_358 += V_360 ;
} else if ( F_179 ( ! V_358 ) ) {
F_27 ( V_12 , V_37 ) ;
return - V_323 ;
}
memcpy ( V_37 -> V_204 + V_37 -> V_357 , V_358 , V_292 ) ;
V_37 -> V_357 += V_292 ;
if ( type == V_196 )
F_180 ( V_359 ) ;
if ( V_37 -> V_322 - V_37 -> V_357 )
return 0 ;
V_361 = V_37 -> V_363 & ( sizeof( T_1 ) - 1 ) ;
if ( V_361 ) {
V_361 = sizeof( T_1 ) - V_361 ;
memset ( V_37 -> V_204 + V_37 -> V_357 , 0 , V_361 ) ;
V_37 -> V_363 += V_361 ;
V_37 -> V_322 += V_361 ;
}
V_290 = F_181 ( & V_12 -> V_148 -> V_149 ,
V_37 -> V_204 ,
V_37 -> V_322 ,
V_195 ) ;
if ( F_79 ( F_182 ( & V_12 -> V_148 -> V_149 , V_290 ) ) ) {
F_27 ( V_12 , V_37 ) ;
return - V_364 ;
}
V_37 -> V_205 = V_354 ;
return F_183 ( V_12 , V_194 , V_37 ,
V_290 , V_37 -> V_322 ) ;
}
return 1 ;
}
void F_184 ( struct V_16 * V_12 , T_2 V_122 , T_1 V_365 )
{
struct V_8 * V_9 ;
int V_27 ;
T_2 V_366 ;
V_366 = ( ( V_122 & F_22 ( V_367 ) ) <<
F_22 ( V_368 ) ) |
( ( ( V_365 & V_122 ) & F_22 ( V_369 ) ) <<
F_22 ( V_370 ) ) ;
for ( V_27 = 0 ; V_27 < V_12 -> V_28 ; V_27 ++ ) {
F_185 ( V_371 , L_29 ,
V_27 , ( T_1 ) V_366 ) ;
V_9 = & V_12 -> V_29 [ V_27 ] ;
F_11 ( V_9 , F_22 ( V_286 ) , V_366 ) ;
}
}
int F_186 ( struct V_16 * V_12 , struct V_36 * V_37 )
{
int V_117 = 0 ;
V_37 -> V_200 ++ ;
if ( ( F_79 ( V_37 -> V_200 == V_37 -> V_205 ) ) ) {
V_117 = F_174 ( V_12 , V_37 ) ;
if ( V_117 ) {
F_27 ( V_12 , V_37 ) ;
return V_117 ;
}
}
F_187 (
V_37 ,
V_362 ,
V_12 -> V_150 ,
sizeof( T_1 ) - ( V_37 -> V_363 & ( sizeof( T_1 ) - 1 ) ) ) ;
F_188 ( V_12 , V_37 ) ;
return V_117 ;
}
void F_189 (
struct V_36 * V_37 ,
T_5 V_372 ,
T_5 V_373 ,
T_1 * V_374 ,
T_5 V_375 )
{
T_1 V_27 , V_376 = 0 , V_289 = 0 ;
T_5 V_202 ;
F_26 ( V_372 > 9 || ( V_375 & 3 ) || V_375 == 4 ) ;
if ( V_372 == 1 )
V_202 = V_203 ;
else if ( V_372 <= 5 )
V_202 = V_377 ;
else
V_202 = V_378 ;
V_37 -> V_200 ++ ;
switch ( V_202 ) {
case V_378 :
V_37 -> V_200 ++ ;
V_37 -> V_206 [ 2 ] . V_197 [ 0 ] = 0 ;
V_37 -> V_206 [ 2 ] . V_197 [ 1 ] = 0 ;
case V_377 :
V_37 -> V_200 ++ ;
V_37 -> V_206 [ 1 ] . V_197 [ 0 ] = 0 ;
V_37 -> V_206 [ 1 ] . V_197 [ 1 ] = 0 ;
break;
}
V_375 >>= 2 ;
V_37 -> V_206 [ 0 ] . V_197 [ 1 ] |=
( ( ( T_2 ) V_373 & V_379 )
<< V_302 ) |
( ( ( T_2 ) V_375 & V_380 )
<< V_304 ) |
( ( ( T_2 ) V_202 & V_381 )
<< V_199 ) |
( ( ( T_2 ) V_374 [ 0 ] & V_382 )
<< V_383 ) ;
for ( V_27 = 0 ; V_27 < ( V_372 - 1 ) ; V_27 ++ ) {
if ( ! V_376 && ! ( V_27 & 2 ) )
V_289 ++ ;
V_37 -> V_206 [ V_289 ] . V_197 [ ! ! ( V_27 & 2 ) ] |=
( ( ( T_2 ) V_374 [ V_27 + 1 ] )
<< V_376 ) ;
V_376 = ( V_376 + 32 ) & 63 ;
}
}
int F_190 ( struct V_8 * V_9 )
{
int V_384 ;
int V_385 ;
if ( ! V_9 ) {
F_191 ( V_9 , - V_323 ) ;
return - V_323 ;
}
while ( 1 ) {
V_384 = F_192 ( F_137 ( V_9 -> V_177 ) ) ;
if ( V_384 > 31 ) {
F_191 ( V_9 , - V_364 ) ;
return - V_364 ;
}
V_385 = F_193 ( V_384 , & V_9 -> V_177 ) ;
if ( ! V_385 )
break;
F_194 () ;
}
F_191 ( V_9 , V_384 ) ;
return V_384 ;
}
void F_195 ( struct V_8 * V_9 , int V_386 )
{
if ( ! V_9 )
return;
F_196 ( V_9 , V_386 ) ;
if ( V_386 < 0 || V_386 > 31 )
return;
F_197 ( V_386 , & V_9 -> V_177 ) ;
}
void F_198 ( struct V_16 * V_12 , int V_387 )
{
int V_27 ;
enum V_335 V_336 = V_387 ? V_344 :
V_341 ;
F_67 ( & V_12 -> V_87 , V_12 -> V_28 ) ;
for ( V_27 = 0 ; V_27 < V_12 -> V_28 ; V_27 ++ )
F_46 ( & V_12 -> V_29 [ V_27 ] , V_336 ) ;
}
void F_199 ( struct V_16 * V_12 )
{
int V_27 ;
int V_316 ;
V_316 = F_200 ( V_12 -> V_88 ,
F_201 ( & V_12 -> V_87 ) <=
0 ) ;
if ( V_316 || F_201 ( & V_12 -> V_87 ) < 0 )
return;
F_67 ( & V_12 -> V_87 , V_12 -> V_28 ) ;
for ( V_27 = 0 ; V_27 < V_12 -> V_28 ; V_27 ++ )
F_46 ( & V_12 -> V_29 [ V_27 ] , V_342 ) ;
( void ) F_200 ( V_12 -> V_88 ,
F_201 ( & V_12 -> V_87 ) <= 0 ) ;
}
void F_202 ( struct V_16 * V_12 )
{
int V_27 ;
for ( V_27 = 0 ; V_27 < V_12 -> V_28 ; V_27 ++ )
F_46 ( & V_12 -> V_29 [ V_27 ] ,
V_343 ) ;
}
void F_203 (
struct V_8 * V_9 )
{
F_204 ( V_9 , V_9 -> V_173 ) ;
F_205 ( V_9 -> V_12 ,
V_388 + ( 8 * ( V_389 / 64 ) ) ,
V_9 -> V_173 ) ;
}
