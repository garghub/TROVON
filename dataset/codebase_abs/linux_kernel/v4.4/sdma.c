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
static void F_23 ( struct V_8 * V_9 )
{
struct V_36 * V_37 , * V_38 ;
F_24 ( V_39 ) ;
unsigned long V_31 ;
F_25 ( V_9 ) ;
F_26 ( & V_9 -> V_40 , V_31 ) ;
F_27 (txp, txp_next, &sde->flushlist, list) {
F_28 ( & V_37 -> V_41 ) ;
F_29 ( & V_37 -> V_41 , & V_39 ) ;
}
F_30 ( & V_9 -> V_40 , V_31 ) ;
F_27 (txp, txp_next, &flushlist, list) {
int V_42 = 0 ;
struct V_43 * V_44 = V_37 -> V_44 ;
F_28 ( & V_37 -> V_41 ) ;
#ifdef F_31
F_32 ( V_9 , V_37 -> V_45 ) ;
if ( F_33 ( V_9 -> V_46 != V_37 -> V_45 ) )
F_17 ( V_9 -> V_12 , L_2 ,
V_9 -> V_46 , V_37 -> V_45 ) ;
V_9 -> V_46 ++ ;
#endif
F_34 ( V_9 -> V_12 , V_37 ) ;
if ( V_44 )
V_42 = F_35 ( & V_44 -> V_47 ) ;
if ( V_37 -> F_6 )
(* V_37 -> F_6 )( V_37 , V_48 , V_42 ) ;
if ( V_44 && V_42 )
F_36 ( V_44 ) ;
}
}
static void F_37 ( struct V_49 * V_50 )
{
unsigned long V_31 ;
struct V_8 * V_9 =
F_5 ( V_50 , struct V_8 , V_51 ) ;
F_38 ( & V_9 -> V_52 , V_31 ) ;
if ( ! F_39 ( V_9 ) )
F_23 ( V_9 ) ;
F_40 ( & V_9 -> V_52 , V_31 ) ;
}
static void F_41 ( struct V_49 * V_50 )
{
struct V_8 * V_9 = F_5 ( V_50 , struct V_8 ,
V_53 ) ;
T_2 V_54 ;
unsigned long V_55 ;
V_55 = V_56 + F_42 ( V_57 ) ;
while ( 1 ) {
V_54 = F_13 ( V_9 , F_22 ( V_58 ) ) ;
V_54 &= F_22 ( V_59 ) ;
if ( V_54 )
break;
if ( F_43 ( V_56 , V_55 ) ) {
F_17 ( V_9 -> V_12 ,
L_3 ,
V_9 -> V_13 ) ;
break;
}
F_44 ( 80 , 120 ) ;
}
F_45 ( V_9 , V_60 ) ;
}
static void F_46 ( struct V_8 * V_9 )
{
F_47 ( & V_9 -> V_53 ) ;
}
static void F_48 ( struct V_8 * V_9 )
{
if ( ! F_49 ( V_9 -> V_12 ) && F_50 ( V_61 ) ) {
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
F_51 ( & V_9 -> V_66 , V_56 + 10 ) ;
}
}
static void F_52 ( unsigned long V_67 )
{
unsigned V_62 ;
struct V_8 * V_9 = (struct V_8 * ) V_67 ;
F_17 ( V_9 -> V_12 , L_5 ) ;
for ( V_62 = 0 ; V_62 < V_9 -> V_12 -> V_28 ; V_62 ++ ) {
struct V_8 * V_68 = & V_9 -> V_12 -> V_29 [ V_62 ] ;
unsigned long V_31 ;
if ( V_68 == V_9 )
continue;
F_26 ( & V_68 -> V_69 , V_31 ) ;
F_53 ( & V_68 -> V_52 ) ;
if ( V_68 -> V_2 . V_70 != V_71 ) {
F_54 ( & V_68 -> V_52 ) ;
F_30 ( & V_68 -> V_69 , V_31 ) ;
continue;
}
if ( ( V_68 -> V_65 != V_68 -> V_72 ) &&
( V_68 -> V_65 ==
V_68 -> V_64 ) )
F_55 ( V_68 ,
V_73 ) ;
F_54 ( & V_68 -> V_52 ) ;
F_30 ( & V_68 -> V_69 , V_31 ) ;
}
F_47 ( & V_9 -> V_53 ) ;
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
F_45 ( V_9 , V_76 ) ;
}
static inline struct V_36 * F_59 ( struct V_8 * V_9 )
{
F_60 () ;
return V_9 -> V_77 [ V_9 -> V_78 & V_9 -> V_79 ] ;
}
static void F_25 ( struct V_8 * V_9 )
{
T_3 V_80 , V_81 ;
int V_82 = 0 ;
struct V_36 * V_37 = F_59 ( V_9 ) ;
V_80 = V_9 -> V_65 & V_9 -> V_79 ;
V_81 = V_9 -> V_72 & V_9 -> V_79 ;
while ( V_80 != V_81 ) {
V_80 = ++ V_9 -> V_65 & V_9 -> V_79 ;
if ( V_37 && V_37 -> V_83 == V_80 ) {
int V_42 = 0 ;
struct V_43 * V_44 = V_37 -> V_44 ;
V_9 -> V_77 [ V_9 -> V_78 ++ & V_9 -> V_79 ] = NULL ;
if ( V_44 )
V_42 = F_35 ( & V_44 -> V_47 ) ;
#ifdef F_31
F_32 ( V_9 , V_37 -> V_45 ) ;
if ( F_33 ( V_9 -> V_46 != V_37 -> V_45 ) )
F_17 ( V_9 -> V_12 , L_2 ,
V_9 -> V_46 , V_37 -> V_45 ) ;
V_9 -> V_46 ++ ;
#endif
F_34 ( V_9 -> V_12 , V_37 ) ;
F_61 ( V_9 , V_80 , V_81 , V_37 ) ;
if ( V_37 -> F_6 )
(* V_37 -> F_6 )(
V_37 ,
V_48 ,
V_42 ) ;
if ( V_44 && V_42 )
F_36 ( V_44 ) ;
V_37 = F_59 ( V_9 ) ;
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
F_26 ( & V_9 -> V_69 , V_31 ) ;
F_53 ( & V_9 -> V_52 ) ;
F_65 ( V_9 , 0 ) ;
F_23 ( V_9 ) ;
V_9 -> V_72 = 0 ;
V_9 -> V_65 = 0 ;
V_9 -> V_84 = F_63 ( V_9 ) ;
* V_9 -> V_85 = 0 ;
F_55 ( V_9 , V_86 ) ;
F_54 ( & V_9 -> V_52 ) ;
F_30 ( & V_9 -> V_69 , V_31 ) ;
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
static void F_71 ( struct V_8 * V_9 )
{
F_70 ( & V_9 -> F_64 ) ;
}
static void F_72 ( struct V_8 * V_9 ,
enum V_1 V_89 )
{
struct V_4 * V_5 = & V_9 -> V_2 ;
const struct V_90 * V_91 = V_92 ;
unsigned V_93 = 0 ;
F_73 (
V_9 ,
V_3 [ V_5 -> V_70 ] ,
V_3 [ V_89 ] ) ;
V_5 -> V_94 = V_5 -> V_70 ;
V_5 -> V_95 = V_5 -> V_96 ;
V_5 -> V_70 = V_89 ;
if ( V_5 -> V_94 != V_71
&& V_89 == V_71 )
F_23 ( V_9 ) ;
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
F_74 ( V_9 , V_5 -> V_96 ) ;
}
T_3 F_75 ( void )
{
T_3 V_108 = V_109 ;
if ( ! V_108 )
return V_110 ;
if ( ! F_76 ( V_108 ) )
return V_110 ;
if ( V_108 < 64 || V_108 > 32768 )
return V_110 ;
return V_108 ;
}
struct V_8 * F_77 (
struct V_16 * V_12 ,
T_1 V_111 ,
T_4 V_112 )
{
struct V_113 * V_114 ;
struct V_115 * V_116 ;
struct V_8 * V_117 ;
if ( F_78 ( V_112 > 8 ) )
return NULL ;
F_79 () ;
V_114 = F_80 ( V_12 -> V_118 ) ;
if ( F_81 ( ! V_114 ) ) {
F_82 () ;
return NULL ;
}
V_116 = V_114 -> V_119 [ V_112 & V_114 -> V_120 ] ;
V_117 = V_116 -> V_9 [ V_111 & V_116 -> V_120 ] ;
F_82 () ;
F_83 ( V_12 , V_111 , V_112 , V_117 -> V_13 ) ;
return V_117 ;
}
struct V_8 * F_84 (
struct V_16 * V_12 ,
T_1 V_111 ,
T_4 V_121 )
{
T_4 V_112 = F_85 ( V_12 , V_121 ) ;
return F_77 ( V_12 , V_111 , V_112 ) ;
}
static void F_86 ( struct V_113 * V_114 )
{
int V_27 ;
for ( V_27 = 0 ; V_114 && V_27 < V_114 -> V_122 ; V_27 ++ )
F_87 ( V_114 -> V_119 [ V_27 ] ) ;
F_87 ( V_114 ) ;
}
static void F_88 ( struct V_123 * V_41 )
{
struct V_113 * V_114 = F_5 ( V_41 , struct V_113 , V_41 ) ;
F_86 ( V_114 ) ;
}
int F_89 ( struct V_16 * V_12 , T_4 V_124 , T_4 V_125 , T_4 * V_126 )
{
int V_27 , V_127 ;
int V_128 , V_129 ;
int V_130 = 0 ;
T_4 V_131 [ V_132 ] ;
struct V_113 * V_133 , * V_134 ;
if ( ! ( V_12 -> V_31 & V_135 ) )
return 0 ;
if ( ! V_126 ) {
V_129 = V_12 -> V_28 / V_125 ;
V_128 = V_12 -> V_28 % V_125 ;
V_126 = V_131 ;
for ( V_27 = V_125 - 1 ; V_27 >= 0 ; V_27 -- , V_128 -- )
V_126 [ V_27 ] = V_129 + ( V_128 > 0 ? 1 : 0 ) ;
}
V_134 = F_90 (
sizeof( struct V_113 ) +
F_91 ( V_125 ) *
sizeof( struct V_115 * ) ,
V_136 ) ;
if ( ! V_134 )
goto V_137;
V_134 -> V_122 = V_125 ;
V_134 -> V_138 = F_91 ( V_125 ) ;
V_134 -> V_120 = ( 1 << F_92 ( V_134 -> V_138 ) ) - 1 ;
for ( V_27 = 0 ; V_27 < V_134 -> V_138 ; V_27 ++ ) {
int V_139 = V_130 ;
if ( V_27 < V_134 -> V_122 ) {
int V_140 = F_91 ( V_126 [ V_27 ] ) ;
V_134 -> V_119 [ V_27 ] = F_90 (
sizeof( struct V_115 ) +
V_140 * sizeof( struct V_8 * ) ,
V_136 ) ;
if ( ! V_134 -> V_119 [ V_27 ] )
goto V_137;
V_134 -> V_119 [ V_27 ] -> V_120 = ( 1 << F_92 ( V_140 ) ) - 1 ;
for ( V_127 = 0 ; V_127 < V_140 ; V_127 ++ ) {
V_134 -> V_119 [ V_27 ] -> V_9 [ V_127 ] =
& V_12 -> V_29 [ V_130 ] ;
if ( ++ V_130 >= V_139 + V_126 [ V_27 ] )
V_130 = V_139 ;
}
} else {
V_134 -> V_119 [ V_27 ] = V_134 -> V_119 [ V_27 % V_125 ] ;
}
V_130 = V_139 + V_126 [ V_27 ] ;
}
F_93 ( & V_12 -> V_141 ) ;
V_133 = F_94 ( V_12 -> V_118 ,
F_95 ( & V_12 -> V_141 ) ) ;
F_96 ( V_12 -> V_118 , V_134 ) ;
F_97 ( & V_12 -> V_141 ) ;
if ( V_133 )
F_98 ( & V_133 -> V_41 , F_88 ) ;
return 0 ;
V_137:
F_86 ( V_134 ) ;
return - V_142 ;
}
static void F_99 ( struct V_16 * V_12 , T_5 V_143 )
{
T_5 V_27 ;
struct V_8 * V_9 ;
if ( V_12 -> V_144 ) {
F_100 ( & V_12 -> V_145 -> V_146 , 4 ,
( void * ) V_12 -> V_144 ,
V_12 -> V_147 ) ;
V_12 -> V_144 = NULL ;
V_12 -> V_147 = 0 ;
}
if ( V_12 -> V_148 ) {
F_100 ( & V_12 -> V_145 -> V_146 , V_12 -> V_149 ,
( void * ) V_12 -> V_148 ,
V_12 -> V_150 ) ;
V_12 -> V_148 = NULL ;
V_12 -> V_150 = 0 ;
}
for ( V_27 = 0 ; V_12 -> V_29 && V_27 < V_143 ; ++ V_27 ) {
V_9 = & V_12 -> V_29 [ V_27 ] ;
V_9 -> V_85 = NULL ;
V_9 -> V_151 = 0 ;
if ( V_9 -> V_152 ) {
F_100 (
& V_12 -> V_145 -> V_146 ,
V_9 -> V_153 * sizeof( T_2 [ 2 ] ) ,
V_9 -> V_152 ,
V_9 -> V_154
) ;
V_9 -> V_152 = NULL ;
V_9 -> V_154 = 0 ;
}
F_101 ( V_9 -> V_77 ) ;
V_9 -> V_77 = NULL ;
}
F_93 ( & V_12 -> V_141 ) ;
F_87 ( F_102 ( V_12 -> V_118 ) ) ;
F_103 ( V_12 -> V_118 , NULL ) ;
F_97 ( & V_12 -> V_141 ) ;
F_104 () ;
F_87 ( V_12 -> V_29 ) ;
V_12 -> V_29 = NULL ;
}
int F_105 ( struct V_16 * V_12 , T_4 V_124 )
{
unsigned V_13 ;
struct V_8 * V_9 ;
T_3 V_153 ;
void * V_155 ;
struct V_156 * V_157 = V_12 -> V_24 + V_124 ;
T_1 V_158 ;
T_6 V_159 = V_160 ;
T_5 V_143 = V_12 -> V_161 ;
if ( ! F_50 ( V_162 ) ) {
F_106 ( V_61 ) ;
return 0 ;
}
if ( V_163 &&
V_163 <= V_12 -> V_161 &&
V_163 >= V_125 )
V_143 = V_163 ;
F_107 ( V_12 , L_7 , V_163 ) ;
F_107 ( V_12 , L_8 , V_12 -> V_161 ) ;
F_107 ( V_12 , L_9 ,
V_12 -> V_164 ) ;
V_158 =
V_12 -> V_164 / ( V_143 * V_165 ) ;
F_108 ( & V_12 -> V_88 ) ;
F_67 ( & V_12 -> V_87 , 0 ) ;
V_153 = F_75 () ;
F_107 ( V_12 , L_10 ,
V_143 , V_153 ) ;
V_12 -> V_29 = F_109 ( V_143 , sizeof( * V_12 -> V_29 ) , V_136 ) ;
if ( ! V_12 -> V_29 )
return - V_142 ;
V_159 = F_110 ( V_12 , V_159 ) ;
if ( ! V_166 )
V_166 = V_167 ;
for ( V_13 = 0 ; V_13 < V_143 ; ++ V_13 ) {
V_9 = & V_12 -> V_29 [ V_13 ] ;
V_9 -> V_12 = V_12 ;
V_9 -> V_157 = V_157 ;
V_9 -> V_13 = V_13 ;
V_9 -> V_153 = V_153 ;
V_9 -> V_84 = F_63 ( V_9 ) ;
V_9 -> V_168 = F_92 ( V_153 ) ;
V_9 -> V_79 = ( 1 << V_9 -> V_168 ) - 1 ;
V_9 -> V_169 = 0 ;
V_9 -> V_170 = ( T_2 ) 1 << ( 0 * V_171 + V_13 )
| ( T_2 ) 1 << ( 1 * V_171 + V_13 )
| ( T_2 ) 1 << ( 2 * V_171 + V_13 ) ;
V_9 -> V_172 =
( T_2 ) 1 << ( 2 * V_171 + V_13 ) ;
V_9 -> V_173 =
( T_2 ) 1 << ( V_171 + V_13 ) ;
F_111 ( & V_9 -> V_69 ) ;
F_112 ( & V_9 -> V_52 ) ;
F_111 ( & V_9 -> V_174 ) ;
F_111 ( & V_9 -> V_40 ) ;
V_9 -> V_175 = 0xfffffffe00000000ULL ;
F_72 ( V_9 , V_176 ) ;
F_113 ( & V_9 -> V_2 . V_6 ) ;
F_114 ( & V_9 -> V_2 . V_7 ) ;
F_115 ( & V_9 -> V_39 ) ;
F_115 ( & V_9 -> V_177 ) ;
V_9 -> V_178 =
F_116 ( V_12 , V_13 , F_22 ( V_179 ) ) ;
if ( V_159 )
V_12 -> V_180 =
V_181 ;
else
V_12 -> V_180 =
V_182 ;
F_117 ( & V_9 -> F_56 , F_56 ,
( unsigned long ) V_9 ) ;
F_117 ( & V_9 -> F_64 , F_64 ,
( unsigned long ) V_9 ) ;
F_118 ( & V_9 -> V_53 , F_41 ) ;
F_118 ( & V_9 -> V_51 , F_37 ) ;
V_9 -> V_64 = 0 ;
F_119 ( & V_9 -> V_66 ,
F_52 , ( unsigned long ) V_9 ) ;
V_9 -> V_152 = F_120 (
& V_12 -> V_145 -> V_146 ,
V_153 * sizeof( T_2 [ 2 ] ) ,
& V_9 -> V_154 ,
V_136
) ;
if ( ! V_9 -> V_152 )
goto V_137;
V_9 -> V_77 =
F_109 ( V_153 , sizeof( struct V_36 * ) ,
V_136 ) ;
if ( ! V_9 -> V_77 )
V_9 -> V_77 =
F_121 (
sizeof( struct V_36 * ) *
V_153 ) ;
if ( ! V_9 -> V_77 )
goto V_137;
}
V_12 -> V_149 = V_183 * V_143 ;
V_12 -> V_148 = F_120 (
& V_12 -> V_145 -> V_146 ,
V_12 -> V_149 ,
& V_12 -> V_150 ,
V_136
) ;
if ( ! V_12 -> V_148 ) {
F_17 ( V_12 , L_11 ) ;
goto V_137;
}
V_12 -> V_144 = F_120 (
& V_12 -> V_145 -> V_146 ,
sizeof( T_1 ) ,
& V_12 -> V_147 ,
V_136
) ;
if ( ! V_12 -> V_144 ) {
F_17 ( V_12 , L_12 ) ;
goto V_137;
}
V_155 = ( void * ) V_12 -> V_148 ;
for ( V_13 = 0 ; V_13 < V_143 ; ++ V_13 ) {
unsigned long V_184 ;
V_9 = & V_12 -> V_29 [ V_13 ] ;
V_9 -> V_85 = V_155 ;
V_155 += V_183 ;
V_184 = ( unsigned long ) V_9 -> V_85 -
( unsigned long ) V_12 -> V_148 ;
V_9 -> V_151 = V_12 -> V_150 + V_184 ;
F_122 ( V_9 , V_158 , V_159 ) ;
}
V_12 -> V_31 |= V_135 ;
V_12 -> V_31 |= V_159 ? V_32 : 0 ;
V_12 -> V_28 = V_143 ;
if ( F_89 ( V_12 , V_124 , V_157 -> V_185 , NULL ) )
goto V_137;
F_107 ( V_12 , L_13 , V_12 -> V_28 ) ;
return 0 ;
V_137:
F_99 ( V_12 , V_143 ) ;
return - V_142 ;
}
void F_123 ( struct V_16 * V_12 )
{
struct V_8 * V_9 ;
unsigned int V_27 ;
for ( V_27 = 0 ; V_27 < V_12 -> V_28 ; ++ V_27 ) {
V_9 = & V_12 -> V_29 [ V_27 ] ;
F_45 ( V_9 , V_186 ) ;
}
}
void F_124 ( struct V_16 * V_12 )
{
struct V_8 * V_9 ;
unsigned int V_27 ;
for ( V_27 = 0 ; V_27 < V_12 -> V_28 ; ++ V_27 ) {
V_9 = & V_12 -> V_29 [ V_27 ] ;
F_45 ( V_9 , V_187 ) ;
}
}
void F_125 ( struct V_16 * V_12 )
{
unsigned V_27 ;
struct V_8 * V_9 ;
for ( V_27 = 0 ; V_27 < V_12 -> V_28 ; ++ V_27 ) {
V_9 = & V_12 -> V_29 [ V_27 ] ;
F_45 ( V_9 , V_188 ) ;
}
}
void F_126 ( struct V_16 * V_12 )
{
unsigned V_13 ;
struct V_8 * V_9 ;
for ( V_13 = 0 ; V_12 -> V_29 && V_13 < V_12 -> V_28 ;
++ V_13 ) {
V_9 = & V_12 -> V_29 [ V_13 ] ;
if ( ! F_127 ( & V_9 -> V_177 ) )
F_17 ( V_12 , L_14 ,
V_9 -> V_13 ) ;
F_45 ( V_9 , V_189 ) ;
F_128 ( & V_9 -> V_66 ) ;
F_9 ( & V_9 -> V_2 ) ;
}
F_99 ( V_12 , V_12 -> V_28 ) ;
}
static inline void F_129 (
struct V_16 * V_12 ,
struct V_190 * V_191 )
{
switch ( F_130 ( V_191 ) ) {
case V_192 :
F_131 (
& V_12 -> V_145 -> V_146 ,
F_132 ( V_191 ) ,
F_133 ( V_191 ) ,
V_193 ) ;
break;
case V_194 :
F_134 (
& V_12 -> V_145 -> V_146 ,
F_132 ( V_191 ) ,
F_133 ( V_191 ) ,
V_193 ) ;
break;
}
}
static inline T_4 F_135 ( struct V_36 * V_195 )
{
return ( V_195 -> V_191 [ 0 ] . V_196 [ 1 ] & V_197 )
>> V_198 ;
}
void F_34 (
struct V_16 * V_12 ,
struct V_36 * V_195 )
{
T_3 V_27 ;
if ( V_195 -> V_199 ) {
T_4 V_200 = 0 , V_201 = F_135 ( V_195 ) ;
F_129 ( V_12 , & V_195 -> V_191 [ 0 ] ) ;
if ( V_201 > V_202 )
V_200 = V_201 >> 1 ;
for ( V_27 = 1 + V_200 ; V_27 < V_195 -> V_199 ; V_27 ++ )
F_129 ( V_12 , & V_195 -> V_191 [ V_27 ] ) ;
V_195 -> V_199 = 0 ;
}
F_87 ( V_195 -> V_203 ) ;
V_195 -> V_203 = NULL ;
if ( F_81 ( V_195 -> V_204 > F_136 ( V_195 -> V_205 ) ) ) {
V_195 -> V_204 = F_136 ( V_195 -> V_205 ) ;
F_87 ( V_195 -> V_191 ) ;
}
}
static inline T_3 F_137 ( struct V_8 * V_9 )
{
struct V_16 * V_12 = V_9 -> V_12 ;
int V_206 ;
T_3 V_207 ;
#ifdef F_57
F_17 ( V_9 -> V_12 , L_6 ,
V_9 -> V_13 , F_58 ( __FILE__ ) , __LINE__ , V_23 ) ;
#endif
V_208:
V_206 = F_50 ( V_209 ) && F_39 ( V_9 ) &&
( V_12 -> V_31 & V_32 ) ;
V_207 = V_206 ?
( T_3 ) F_138 ( * V_9 -> V_85 ) :
( T_3 ) F_13 ( V_9 , F_22 ( V_210 ) ) ;
if ( F_81 ( F_50 ( V_211 ) ) ) {
T_3 V_30 ;
T_3 V_212 ;
T_3 V_213 ;
int V_214 ;
V_213 = V_9 -> V_65 & V_9 -> V_79 ;
V_212 = F_139 ( V_9 -> V_72 ) & V_9 -> V_79 ;
V_30 = V_9 -> V_153 ;
if ( V_213 < V_212 )
V_214 = ( V_207 >= V_213 ) & ( V_207 <= V_212 ) ;
else if ( V_213 > V_212 )
V_214 = ( ( V_207 >= V_213 ) && ( V_207 < V_30 ) ) ||
( V_207 <= V_212 ) ;
else
V_214 = ( V_207 == V_213 ) ;
if ( F_81 ( ! V_214 ) ) {
F_17 ( V_12 , L_15 ,
V_9 -> V_13 ,
V_206 ? L_16 : L_17 ,
V_207 , V_213 , V_212 , V_30 ) ;
if ( V_206 ) {
V_206 = 0 ;
goto V_208;
}
V_207 = V_213 ;
}
}
return V_207 ;
}
static void F_62 ( struct V_8 * V_9 , unsigned V_215 )
{
struct V_43 * V_44 , * V_216 ;
struct V_43 * V_217 [ V_218 ] ;
unsigned V_27 , V_219 = 0 , V_220 ;
struct V_36 * V_221 ;
struct V_222 * V_146 = & V_9 -> V_12 -> V_223 ;
#ifdef F_57
F_17 ( V_9 -> V_12 , L_6 , V_9 -> V_13 ,
F_58 ( __FILE__ ) , __LINE__ , V_23 ) ;
F_17 ( V_9 -> V_12 , L_18 , V_215 ) ;
#endif
do {
V_220 = F_140 ( & V_146 -> V_224 ) ;
if ( ! F_127 ( & V_9 -> V_177 ) ) {
F_53 ( & V_146 -> V_224 ) ;
F_27 (
wait,
nw,
&sde->dmawait,
list) {
T_3 V_199 = 0 ;
if ( ! V_44 -> V_225 )
continue;
if ( V_219 == F_136 ( V_217 ) )
break;
if ( ! F_127 ( & V_44 -> V_78 ) ) {
V_221 = F_141 (
& V_44 -> V_78 ,
struct V_36 ,
V_41 ) ;
V_199 = V_221 -> V_199 ;
}
if ( V_199 > V_215 )
break;
V_215 -= V_199 ;
F_28 ( & V_44 -> V_41 ) ;
V_217 [ V_219 ++ ] = V_44 ;
}
F_54 ( & V_146 -> V_224 ) ;
break;
}
} while ( F_142 ( & V_146 -> V_224 , V_220 ) );
for ( V_27 = 0 ; V_27 < V_219 ; V_27 ++ )
V_217 [ V_27 ] -> V_225 ( V_217 [ V_27 ] , V_226 ) ;
}
static void F_65 ( struct V_8 * V_9 , T_2 V_227 )
{
struct V_36 * V_37 = NULL ;
int V_82 = 0 ;
T_3 V_207 , V_213 , V_212 ;
int V_228 = 0 ;
V_207 = F_137 ( V_9 ) ;
V_208:
V_37 = F_59 ( V_9 ) ;
V_213 = V_9 -> V_65 & V_9 -> V_79 ;
F_61 ( V_9 , V_207 , V_213 , V_37 ) ;
while ( V_213 != V_207 ) {
V_213 = ++ V_9 -> V_65 & V_9 -> V_79 ;
if ( V_37 && V_37 -> V_83 == V_213 ) {
int V_42 = 0 ;
struct V_43 * V_44 = V_37 -> V_44 ;
V_9 -> V_77 [ V_9 -> V_78 ++ & V_9 -> V_79 ] = NULL ;
if ( V_44 )
V_42 = F_35 ( & V_44 -> V_47 ) ;
#ifdef F_31
F_32 ( V_9 , V_37 -> V_45 ) ;
if ( F_33 ( V_9 -> V_46 != V_37 -> V_45 ) )
F_17 ( V_9 -> V_12 , L_2 ,
V_9 -> V_46 , V_37 -> V_45 ) ;
V_9 -> V_46 ++ ;
#endif
F_34 ( V_9 -> V_12 , V_37 ) ;
if ( V_37 -> F_6 )
(* V_37 -> F_6 )(
V_37 ,
V_229 ,
V_42 ) ;
if ( V_44 && V_42 )
F_36 ( V_44 ) ;
V_37 = F_59 ( V_9 ) ;
}
F_61 ( V_9 , V_207 , V_213 , V_37 ) ;
V_82 ++ ;
}
if ( ( V_227 & V_9 -> V_172 ) && ! V_228 ) {
V_212 = F_139 ( V_9 -> V_72 ) & V_9 -> V_79 ;
if ( V_212 != V_207 ) {
V_207 = ( T_3 ) F_13 ( V_9 , F_22 ( V_210 ) ) ;
V_228 = 1 ;
goto V_208;
}
}
V_9 -> V_230 = V_227 ;
if ( V_82 )
F_62 ( V_9 , F_63 ( V_9 ) ) ;
}
void F_143 ( struct V_8 * V_9 , T_2 V_227 )
{
F_144 ( V_9 , V_227 ) ;
F_53 ( & V_9 -> V_52 ) ;
F_21 ( V_9 , V_166 ) ;
F_65 ( V_9 , V_227 ) ;
F_54 ( & V_9 -> V_52 ) ;
}
void F_145 ( struct V_8 * V_9 , T_2 V_227 )
{
unsigned long V_31 ;
#ifdef F_57
F_17 ( V_9 -> V_12 , L_19 ,
V_9 -> V_13 ,
( unsigned long long ) V_227 ,
V_3 [ V_9 -> V_2 . V_70 ] ) ;
#endif
F_26 ( & V_9 -> V_69 , V_31 ) ;
F_53 ( & V_9 -> V_52 ) ;
if ( V_227 & V_231 )
F_55 ( V_9 , V_232 ) ;
if ( V_227 & ~ F_22 ( V_233 ) ) {
F_17 ( V_9 -> V_12 ,
L_20 ,
V_9 -> V_13 ,
( unsigned long long ) V_227 ,
V_3 [ V_9 -> V_2 . V_70 ] ) ;
F_146 ( V_9 ) ;
}
F_54 ( & V_9 -> V_52 ) ;
F_30 ( & V_9 -> V_69 , V_31 ) ;
}
static void F_74 ( struct V_8 * V_9 , unsigned V_93 )
{
T_2 V_234 = 0 ;
T_2 V_235 = 0 ;
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
V_234 |= F_22 ( V_236 ) ;
else
V_235 |= F_22 ( V_236 ) ;
if ( V_93 & V_100 )
V_234 |= F_22 ( V_237 ) ;
else
V_235 |= F_22 ( V_237 ) ;
if ( V_93 & V_102 )
V_234 |= F_22 ( V_238 ) ;
else
V_235 |= F_22 ( V_238 ) ;
F_26 ( & V_9 -> V_174 , V_31 ) ;
V_9 -> V_239 |= V_234 ;
V_9 -> V_239 &= ~ V_235 ;
if ( V_93 & V_104 )
F_11 ( V_9 , F_22 ( V_240 ) ,
V_9 -> V_239 |
F_22 ( V_241 ) ) ;
else
F_11 ( V_9 , F_22 ( V_240 ) , V_9 -> V_239 ) ;
F_30 ( & V_9 -> V_174 , V_31 ) ;
#ifdef F_57
F_147 ( V_9 ) ;
#endif
}
static void F_148 ( struct V_8 * V_9 )
{
#ifdef F_57
F_17 ( V_9 -> V_12 , L_6 ,
V_9 -> V_13 , F_58 ( __FILE__ ) , __LINE__ , V_23 ) ;
#endif
F_11 ( V_9 , F_22 ( V_242 ) ,
( V_9 -> V_153 / 64 ) << F_22 ( V_243 )
) ;
F_11 ( V_9 , F_22 ( V_242 ) ,
( ( V_9 -> V_153 / 64 ) << F_22 ( V_243 ) )
| ( 4ULL << F_22 ( V_244 ) )
) ;
}
static inline void F_149 ( struct V_8 * V_9 , T_3 V_81 )
{
F_150 () ;
F_151 ( V_81 , V_9 -> V_178 ) ;
}
static void F_152 ( struct V_8 * V_9 )
{
T_2 V_19 ;
#ifdef F_57
F_17 ( V_9 -> V_12 , L_6 ,
V_9 -> V_13 , F_58 ( __FILE__ ) , __LINE__ , V_23 ) ;
#endif
F_148 ( V_9 ) ;
F_149 ( V_9 , 0 ) ;
* V_9 -> V_85 = 0 ;
V_19 = F_22 ( V_245 ) <<
F_22 ( V_246 ) ;
F_11 ( V_9 , F_22 ( V_247 ) , V_19 ) ;
}
static void F_153 ( struct V_8 * V_9 )
{
struct V_16 * V_12 = V_9 -> V_12 ;
T_2 V_19 ;
if ( F_81 ( F_50 ( V_248 ) ) )
return;
V_19 = F_154 ( V_12 ) ;
if ( F_50 ( V_249 ) )
F_155 ( V_19 ) ;
else
F_156 ( V_19 ) ;
F_11 ( V_9 , F_22 ( V_250 ) , V_19 ) ;
}
static void F_122 (
struct V_8 * V_9 ,
T_1 V_251 ,
T_6 V_159 )
{
T_4 V_252 , V_253 ;
#ifdef F_57
struct V_16 * V_12 = V_9 -> V_12 ;
F_17 ( V_12 , L_6 ,
V_9 -> V_13 , F_58 ( __FILE__ ) , __LINE__ , V_23 ) ;
#endif
F_11 ( V_9 , F_22 ( V_254 ) , V_9 -> V_154 ) ;
F_148 ( V_9 ) ;
F_149 ( V_9 , 0 ) ;
F_11 ( V_9 , F_22 ( V_255 ) , V_159 ) ;
F_11 ( V_9 , F_22 ( V_35 ) , 0 ) ;
F_11 ( V_9 , F_22 ( V_256 ) , V_9 -> V_151 ) ;
F_11 ( V_9 , F_22 ( V_257 ) ,
( ( T_2 ) V_251 <<
F_22 ( V_258 ) ) |
( ( T_2 ) ( V_251 * V_9 -> V_13 ) <<
F_22 ( V_259 ) ) ) ;
F_11 ( V_9 , F_22 ( V_260 ) , ~ 0ull ) ;
F_153 ( V_9 ) ;
V_253 = V_261 ;
V_252 = V_262 ;
F_11 ( V_9 , F_22 ( V_263 ) ,
( V_253 << V_264 ) |
( V_252 << V_265 ) ) ;
}
void F_147 ( struct V_8 * V_9 )
{
T_2 V_266 ;
unsigned V_27 ;
F_157 ( F_22 ( V_240 ) ) ;
F_157 ( F_22 ( V_58 ) ) ;
F_158 ( F_22 ( V_267 ) ) ;
F_158 ( F_22 ( V_268 ) ) ;
F_157 ( F_22 ( V_269 ) ) ;
F_157 ( F_22 ( V_260 ) ) ;
for ( V_27 = 0 ; V_27 < V_270 ; ++ V_27 ) {
F_159 ( V_271 ) ;
F_159 ( V_272 ) ;
F_159 ( V_273 ) ;
}
F_157 ( F_22 ( V_179 ) ) ;
F_157 ( F_22 ( V_210 ) ) ;
F_157 ( F_22 ( V_274 ) ) ;
F_157 ( F_22 ( V_275 ) ) ;
F_157 ( F_22 ( V_255 ) ) ;
F_157 ( F_22 ( V_35 ) ) ;
F_157 ( F_22 ( V_276 ) ) ;
F_157 ( F_22 ( V_257 ) ) ;
F_158 ( F_22 ( V_277 ) ) ;
F_158 ( F_22 ( V_278 ) ) ;
F_157 ( F_22 ( V_254 ) ) ;
F_157 ( F_22 ( V_242 ) ) ;
F_157 ( F_22 ( V_256 ) ) ;
F_157 ( F_22 ( V_250 ) ) ;
F_157 ( F_22 ( V_279 ) ) ;
F_157 ( F_22 ( V_280 ) ) ;
F_157 ( F_22 ( V_281 ) ) ;
F_157 ( F_22 ( V_282 ) ) ;
F_157 ( F_22 ( V_263 ) ) ;
}
static void F_146 ( struct V_8 * V_9 )
{
struct V_283 * V_152 ;
struct V_283 * V_284 ;
T_2 V_285 [ 2 ] ;
T_2 V_286 ;
T_4 V_287 ;
T_3 V_288 ;
T_3 V_80 , V_81 , V_30 ;
V_80 = V_9 -> V_65 & V_9 -> V_79 ;
V_81 = V_9 -> V_72 & V_9 -> V_79 ;
V_30 = F_63 ( V_9 ) ;
V_152 = V_9 -> V_152 ;
F_17 ( V_9 -> V_12 ,
L_22 ,
V_9 -> V_13 ,
V_80 ,
V_81 ,
V_30 ,
! F_127 ( & V_9 -> V_39 ) ) ;
while ( V_80 != V_81 ) {
char V_31 [ 6 ] = { 'x' , 'x' , 'x' , 'x' , 0 } ;
V_284 = & V_9 -> V_152 [ V_80 ] ;
V_285 [ 0 ] = F_138 ( V_284 -> V_196 [ 0 ] ) ;
V_285 [ 1 ] = F_138 ( V_284 -> V_196 [ 1 ] ) ;
V_31 [ 0 ] = ( V_285 [ 1 ] & V_182 ) ? 'I' : '-' ;
V_31 [ 1 ] = ( V_285 [ 1 ] & V_181 ) ?
'H' : '-' ;
V_31 [ 2 ] = ( V_285 [ 0 ] & V_289 ) ? 'F' : '-' ;
V_31 [ 3 ] = ( V_285 [ 0 ] & V_290 ) ? 'L' : '-' ;
V_286 = ( V_285 [ 0 ] >> V_291 )
& V_292 ;
V_287 = ( V_285 [ 1 ] >> V_293 )
& V_294 ;
V_288 = ( V_285 [ 0 ] >> V_295 )
& V_296 ;
F_17 ( V_9 -> V_12 ,
L_23 ,
V_80 , V_31 , V_286 , V_287 , V_288 ) ;
F_17 ( V_9 -> V_12 ,
L_24 ,
V_285 [ 0 ] , V_285 [ 1 ] ) ;
if ( V_285 [ 0 ] & V_289 )
F_17 ( V_9 -> V_12 ,
L_25 ,
( T_4 ) ( ( V_285 [ 1 ] & V_297 )
>> V_298 ) ,
( T_4 ) ( ( V_285 [ 1 ] & V_197 )
>> V_198 ) ,
( T_4 ) ( ( V_285 [ 1 ] & V_299 )
>> V_300 ) ) ;
V_80 ++ ;
V_80 &= V_9 -> V_79 ;
}
}
void F_160 ( struct V_301 * V_302 , struct V_8 * V_9 )
{
T_3 V_80 , V_81 ;
struct V_283 * V_284 ;
T_2 V_285 [ 2 ] ;
T_2 V_286 ;
T_4 V_287 ;
T_3 V_288 ;
V_80 = V_9 -> V_65 & V_9 -> V_79 ;
V_81 = F_139 ( V_9 -> V_72 ) & V_9 -> V_79 ;
F_161 ( V_302 , V_303 , V_9 -> V_13 ,
F_1 ( V_9 -> V_2 . V_70 ) ,
( unsigned long long ) F_13 ( V_9 , F_22 ( V_240 ) ) ,
( unsigned long long ) F_13 ( V_9 , F_22 ( V_58 ) ) ,
( unsigned long long ) F_13 ( V_9 ,
F_22 ( V_269 ) ) ,
( unsigned long long ) F_13 ( V_9 , F_22 ( V_179 ) ) ,
V_81 ,
( unsigned long long ) F_13 ( V_9 , F_22 ( V_210 ) ) ,
V_80 ,
( unsigned long long ) F_138 ( * V_9 -> V_85 ) ,
( unsigned long long ) F_13 ( V_9 , F_22 ( V_257 ) ) ,
( unsigned long long ) F_13 ( V_9 , F_22 ( V_242 ) ) ,
( unsigned long long ) F_13 ( V_9 , F_22 ( V_255 ) ) ,
( unsigned long long ) V_9 -> V_230 ,
( unsigned long long ) V_9 -> V_175 ,
V_9 -> V_304 ,
V_9 -> V_78 ,
V_9 -> V_72 ,
V_9 -> V_65 ,
! F_127 ( & V_9 -> V_39 ) ,
V_9 -> V_169 ,
( unsigned long long ) F_13 ( V_9 , V_305 ) ) ;
while ( V_80 != V_81 ) {
char V_31 [ 6 ] = { 'x' , 'x' , 'x' , 'x' , 0 } ;
V_284 = & V_9 -> V_152 [ V_80 ] ;
V_285 [ 0 ] = F_138 ( V_284 -> V_196 [ 0 ] ) ;
V_285 [ 1 ] = F_138 ( V_284 -> V_196 [ 1 ] ) ;
V_31 [ 0 ] = ( V_285 [ 1 ] & V_182 ) ? 'I' : '-' ;
V_31 [ 1 ] = ( V_285 [ 1 ] & V_181 ) ?
'H' : '-' ;
V_31 [ 2 ] = ( V_285 [ 0 ] & V_289 ) ? 'F' : '-' ;
V_31 [ 3 ] = ( V_285 [ 0 ] & V_290 ) ? 'L' : '-' ;
V_286 = ( V_285 [ 0 ] >> V_291 )
& V_292 ;
V_287 = ( V_285 [ 1 ] >> V_293 )
& V_294 ;
V_288 = ( V_285 [ 0 ] >> V_295 )
& V_296 ;
F_161 ( V_302 ,
L_26 ,
V_80 , V_31 , V_286 , V_287 , V_288 ) ;
if ( V_285 [ 0 ] & V_289 )
F_161 ( V_302 , L_27 ,
( T_4 ) ( ( V_285 [ 1 ] & V_297 )
>> V_298 ) ,
( T_4 ) ( ( V_285 [ 1 ] & V_197 )
>> V_198 ) ) ;
V_80 = ( V_80 + 1 ) & V_9 -> V_79 ;
}
}
static inline T_2 F_162 ( struct V_8 * V_9 , T_2 V_306 )
{
T_4 V_307 = ( V_9 -> V_72 >> V_9 -> V_168 ) & 3 ;
V_306 &= ~ V_308 ;
V_306 |= ( ( T_2 ) V_307 & V_294 )
<< V_293 ;
return V_306 ;
}
static inline T_3 F_163 ( struct V_8 * V_9 , struct V_36 * V_195 )
{
int V_27 ;
T_3 V_81 ;
struct V_190 * V_191 = V_195 -> V_191 ;
T_4 V_200 = 0 , V_201 = F_135 ( V_195 ) ;
V_81 = V_9 -> V_72 & V_9 -> V_79 ;
V_9 -> V_152 [ V_81 ] . V_196 [ 0 ] = F_164 ( V_191 -> V_196 [ 0 ] ) ;
V_9 -> V_152 [ V_81 ] . V_196 [ 1 ] = F_164 ( F_162 ( V_9 , V_191 -> V_196 [ 1 ] ) ) ;
F_165 ( V_9 , V_191 -> V_196 [ 0 ] , V_191 -> V_196 [ 1 ] ,
V_81 , & V_9 -> V_152 [ V_81 ] ) ;
V_81 = ++ V_9 -> V_72 & V_9 -> V_79 ;
V_191 ++ ;
if ( V_201 > V_202 )
V_200 = V_201 >> 1 ;
for ( V_27 = 1 ; V_27 < V_195 -> V_199 ; V_27 ++ , V_191 ++ ) {
T_2 V_306 ;
V_9 -> V_152 [ V_81 ] . V_196 [ 0 ] = F_164 ( V_191 -> V_196 [ 0 ] ) ;
if ( V_200 ) {
V_306 = V_191 -> V_196 [ 1 ] ;
V_200 -- ;
} else {
V_306 = F_162 ( V_9 , V_191 -> V_196 [ 1 ] ) ;
}
V_9 -> V_152 [ V_81 ] . V_196 [ 1 ] = F_164 ( V_306 ) ;
F_165 ( V_9 , V_191 -> V_196 [ 0 ] , V_306 ,
V_81 , & V_9 -> V_152 [ V_81 ] ) ;
V_81 = ++ V_9 -> V_72 & V_9 -> V_79 ;
}
V_195 -> V_83 = V_81 ;
#ifdef F_31
V_195 -> V_45 = V_9 -> V_309 ++ ;
F_166 ( V_9 , V_195 -> V_45 ) ;
F_33 ( V_9 -> V_77 [ V_9 -> V_304 & V_9 -> V_79 ] ) ;
#endif
V_9 -> V_77 [ V_9 -> V_304 ++ & V_9 -> V_79 ] = V_195 ;
V_9 -> V_84 -= V_195 -> V_199 ;
return V_81 ;
}
static int F_167 (
struct V_8 * V_9 ,
struct V_43 * V_44 ,
struct V_36 * V_195 )
{
int V_310 ;
V_9 -> V_84 = F_63 ( V_9 ) ;
if ( V_195 -> V_199 <= V_9 -> V_84 )
return - V_311 ;
if ( V_44 && V_44 -> V_312 ) {
unsigned V_220 ;
V_220 = F_168 (
( const V_313 * ) & V_9 -> V_52 . V_314 ) ;
V_310 = V_44 -> V_312 ( V_9 , V_44 , V_195 , V_220 ) ;
if ( V_310 == - V_311 )
V_9 -> V_84 = F_63 ( V_9 ) ;
} else
V_310 = - V_315 ;
return V_310 ;
}
int F_169 ( struct V_8 * V_9 ,
struct V_43 * V_44 ,
struct V_36 * V_195 )
{
int V_310 = 0 ;
T_3 V_81 ;
unsigned long V_31 ;
if ( F_81 ( V_195 -> V_316 ) )
return - V_317 ;
V_195 -> V_44 = V_44 ;
F_26 ( & V_9 -> V_69 , V_31 ) ;
V_208:
if ( F_81 ( ! F_39 ( V_9 ) ) )
goto V_318;
if ( F_81 ( V_195 -> V_199 > V_9 -> V_84 ) )
goto V_319;
V_81 = F_163 ( V_9 , V_195 ) ;
if ( V_44 )
F_170 ( & V_44 -> V_47 ) ;
F_149 ( V_9 , V_81 ) ;
V_320:
F_30 ( & V_9 -> V_69 , V_31 ) ;
return V_310 ;
V_318:
if ( V_44 )
F_170 ( & V_44 -> V_47 ) ;
V_195 -> V_83 = 0 ;
#ifdef F_31
V_195 -> V_45 = V_9 -> V_309 ++ ;
F_166 ( V_9 , V_195 -> V_45 ) ;
#endif
F_171 ( & V_9 -> V_40 ) ;
F_29 ( & V_195 -> V_41 , & V_9 -> V_39 ) ;
F_172 ( & V_9 -> V_40 ) ;
if ( V_44 ) {
V_44 -> V_321 ++ ;
V_44 -> V_108 += V_195 -> V_199 ;
}
F_47 ( & V_9 -> V_51 ) ;
V_310 = - V_322 ;
goto V_320;
V_319:
V_310 = F_167 ( V_9 , V_44 , V_195 ) ;
if ( V_310 == - V_311 ) {
V_310 = 0 ;
goto V_208;
}
V_9 -> V_169 ++ ;
goto V_320;
}
int F_173 ( struct V_8 * V_9 ,
struct V_43 * V_44 ,
struct V_323 * V_324 )
{
struct V_36 * V_195 , * V_325 ;
int V_310 = 0 ;
unsigned long V_31 ;
T_3 V_81 = V_326 ;
int V_108 = 0 ;
F_26 ( & V_9 -> V_69 , V_31 ) ;
V_208:
F_27 (tx, tx_next, tx_list, list) {
V_195 -> V_44 = V_44 ;
if ( F_81 ( ! F_39 ( V_9 ) ) )
goto V_318;
if ( F_81 ( V_195 -> V_199 > V_9 -> V_84 ) )
goto V_319;
if ( F_81 ( V_195 -> V_316 ) ) {
V_310 = - V_317 ;
goto V_327;
}
F_28 ( & V_195 -> V_41 ) ;
V_81 = F_163 ( V_9 , V_195 ) ;
V_108 ++ ;
if ( V_81 != V_326 &&
( V_108 & V_328 ) == 0 ) {
F_149 ( V_9 , V_81 ) ;
V_81 = V_326 ;
}
}
V_327:
if ( V_44 )
F_174 ( V_108 , & V_44 -> V_47 ) ;
if ( V_81 != V_326 )
F_149 ( V_9 , V_81 ) ;
F_30 ( & V_9 -> V_69 , V_31 ) ;
return V_310 ;
V_318:
F_171 ( & V_9 -> V_40 ) ;
F_27 (tx, tx_next, tx_list, list) {
V_195 -> V_44 = V_44 ;
F_28 ( & V_195 -> V_41 ) ;
if ( V_44 )
F_170 ( & V_44 -> V_47 ) ;
V_195 -> V_83 = 0 ;
#ifdef F_31
V_195 -> V_45 = V_9 -> V_309 ++ ;
F_166 ( V_9 , V_195 -> V_45 ) ;
#endif
F_29 ( & V_195 -> V_41 , & V_9 -> V_39 ) ;
if ( V_44 ) {
V_44 -> V_321 ++ ;
V_44 -> V_108 += V_195 -> V_199 ;
}
}
F_172 ( & V_9 -> V_40 ) ;
F_47 ( & V_9 -> V_51 ) ;
V_310 = - V_322 ;
goto V_327;
V_319:
V_310 = F_167 ( V_9 , V_44 , V_195 ) ;
if ( V_310 == - V_311 ) {
V_310 = 0 ;
goto V_208;
}
V_9 -> V_169 ++ ;
goto V_327;
}
static void F_45 ( struct V_8 * V_9 ,
enum V_329 V_330 )
{
unsigned long V_31 ;
F_26 ( & V_9 -> V_69 , V_31 ) ;
F_53 ( & V_9 -> V_52 ) ;
F_55 ( V_9 , V_330 ) ;
if ( V_9 -> V_2 . V_70 == V_71 )
F_62 ( V_9 , F_63 ( V_9 ) ) ;
F_54 ( & V_9 -> V_52 ) ;
F_30 ( & V_9 -> V_69 , V_31 ) ;
}
static void F_55 ( struct V_8 * V_9 ,
enum V_329 V_330 )
{
struct V_4 * V_5 = & V_9 -> V_2 ;
int V_331 = 0 ;
#ifdef F_57
F_17 ( V_9 -> V_12 , L_28 , V_9 -> V_13 ,
V_3 [ V_5 -> V_70 ] ,
V_332 [ V_330 ] ) ;
#endif
switch ( V_5 -> V_70 ) {
case V_176 :
switch ( V_330 ) {
case V_189 :
break;
case V_186 :
V_5 -> V_106 = 1 ;
case V_188 :
F_2 ( & V_9 -> V_2 ) ;
F_72 ( V_9 ,
V_333 ) ;
break;
case V_60 :
break;
case V_76 :
break;
case V_86 :
F_66 ( V_9 ) ;
break;
case V_334 :
break;
case V_232 :
break;
case V_187 :
break;
case V_335 :
break;
case V_336 :
break;
case V_337 :
break;
case V_338 :
break;
case V_73 :
break;
}
break;
case V_333 :
switch ( V_330 ) {
case V_189 :
F_72 ( V_9 , V_176 ) ;
F_66 ( V_9 ) ;
break;
case V_188 :
break;
case V_60 :
F_72 ( V_9 ,
V_339 ) ;
F_69 ( V_9 ) ;
break;
case V_76 :
break;
case V_186 :
V_5 -> V_106 = 1 ;
break;
case V_86 :
break;
case V_334 :
break;
case V_232 :
F_46 ( V_9 ) ;
break;
case V_187 :
V_5 -> V_106 = 0 ;
break;
case V_335 :
break;
case V_336 :
break;
case V_337 :
break;
case V_338 :
break;
case V_73 :
break;
}
break;
case V_339 :
switch ( V_330 ) {
case V_189 :
F_72 ( V_9 , V_176 ) ;
F_66 ( V_9 ) ;
break;
case V_188 :
break;
case V_60 :
break;
case V_76 :
F_152 ( V_9 ) ;
F_72 ( V_9 , V_5 -> V_106 ?
V_71 :
V_340 ) ;
break;
case V_186 :
V_5 -> V_106 = 1 ;
break;
case V_86 :
break;
case V_334 :
break;
case V_232 :
break;
case V_187 :
V_5 -> V_106 = 0 ;
break;
case V_335 :
break;
case V_336 :
break;
case V_337 :
break;
case V_338 :
break;
case V_73 :
break;
}
break;
case V_340 :
switch ( V_330 ) {
case V_189 :
F_72 ( V_9 , V_176 ) ;
F_66 ( V_9 ) ;
break;
case V_188 :
break;
case V_60 :
break;
case V_76 :
break;
case V_186 :
F_72 ( V_9 , V_71 ) ;
V_5 -> V_106 = 1 ;
break;
case V_86 :
break;
case V_334 :
break;
case V_232 :
F_72 ( V_9 , V_341 ) ;
F_46 ( V_9 ) ;
break;
case V_187 :
break;
case V_338 :
case V_335 :
F_72 ( V_9 , V_342 ) ;
F_175 ( & V_9 -> V_12 -> V_87 ) ;
F_68 ( & V_9 -> V_12 -> V_88 ) ;
break;
case V_336 :
break;
case V_337 :
break;
case V_73 :
break;
}
break;
case V_343 :
switch ( V_330 ) {
case V_189 :
F_72 ( V_9 , V_176 ) ;
break;
case V_188 :
break;
case V_60 :
break;
case V_76 :
break;
case V_186 :
V_5 -> V_106 = 1 ;
break;
case V_86 :
F_72 ( V_9 , V_344 ) ;
F_69 ( V_9 ) ;
break;
case V_334 :
break;
case V_232 :
break;
case V_187 :
V_5 -> V_106 = 0 ;
break;
case V_335 :
break;
case V_336 :
break;
case V_337 :
break;
case V_338 :
V_5 -> V_106 = 0 ;
break;
case V_73 :
break;
}
break;
case V_344 :
switch ( V_330 ) {
case V_189 :
F_72 ( V_9 , V_176 ) ;
F_71 ( V_9 ) ;
break;
case V_188 :
break;
case V_60 :
break;
case V_76 :
F_152 ( V_9 ) ;
F_72 ( V_9 , V_5 -> V_106 ?
V_71 :
V_340 ) ;
break;
case V_186 :
V_5 -> V_106 = 1 ;
break;
case V_86 :
break;
case V_334 :
break;
case V_232 :
break;
case V_187 :
V_5 -> V_106 = 0 ;
break;
case V_335 :
break;
case V_336 :
break;
case V_337 :
break;
case V_338 :
V_5 -> V_106 = 0 ;
break;
case V_73 :
break;
}
break;
case V_341 :
switch ( V_330 ) {
case V_189 :
F_72 ( V_9 , V_176 ) ;
F_71 ( V_9 ) ;
break;
case V_188 :
break;
case V_60 :
F_72 ( V_9 , V_343 ) ;
F_71 ( V_9 ) ;
break;
case V_76 :
break;
case V_186 :
V_5 -> V_106 = 1 ;
break;
case V_86 :
break;
case V_334 :
break;
case V_232 :
F_46 ( V_9 ) ;
break;
case V_187 :
V_5 -> V_106 = 0 ;
break;
case V_335 :
break;
case V_336 :
break;
case V_337 :
break;
case V_338 :
V_5 -> V_106 = 0 ;
break;
case V_73 :
break;
}
break;
case V_345 :
switch ( V_330 ) {
case V_189 :
F_72 ( V_9 , V_176 ) ;
F_71 ( V_9 ) ;
break;
case V_188 :
break;
case V_60 :
F_72 ( V_9 , V_343 ) ;
F_71 ( V_9 ) ;
break;
case V_76 :
break;
case V_186 :
V_5 -> V_106 = 1 ;
break;
case V_86 :
break;
case V_334 :
break;
case V_232 :
F_46 ( V_9 ) ;
break;
case V_187 :
V_5 -> V_106 = 0 ;
break;
case V_335 :
break;
case V_336 :
break;
case V_337 :
break;
case V_338 :
break;
case V_73 :
break;
}
break;
case V_342 :
switch ( V_330 ) {
case V_189 :
F_72 ( V_9 , V_176 ) ;
F_71 ( V_9 ) ;
break;
case V_188 :
break;
case V_60 :
break;
case V_76 :
break;
case V_186 :
V_5 -> V_106 = 1 ;
break;
case V_86 :
break;
case V_334 :
break;
case V_232 :
break;
case V_187 :
V_5 -> V_106 = 0 ;
break;
case V_335 :
break;
case V_336 :
F_72 ( V_9 , V_346 ) ;
F_71 ( V_9 ) ;
break;
case V_337 :
break;
case V_338 :
break;
case V_73 :
break;
}
break;
case V_346 :
switch ( V_330 ) {
case V_189 :
F_72 ( V_9 , V_176 ) ;
F_71 ( V_9 ) ;
break;
case V_188 :
break;
case V_60 :
break;
case V_76 :
break;
case V_186 :
V_5 -> V_106 = 1 ;
break;
case V_86 :
F_175 ( & V_9 -> V_12 -> V_87 ) ;
F_68 ( & V_9 -> V_12 -> V_88 ) ;
break;
case V_334 :
break;
case V_232 :
break;
case V_187 :
V_5 -> V_106 = 0 ;
break;
case V_335 :
break;
case V_336 :
break;
case V_337 :
F_152 ( V_9 ) ;
F_72 ( V_9 , V_5 -> V_106 ?
V_71 :
V_340 ) ;
break;
case V_338 :
break;
case V_73 :
break;
}
break;
case V_71 :
switch ( V_330 ) {
case V_189 :
F_72 ( V_9 , V_176 ) ;
F_71 ( V_9 ) ;
break;
case V_188 :
break;
case V_60 :
break;
case V_76 :
break;
case V_186 :
break;
case V_86 :
break;
case V_334 :
break;
case V_232 :
V_331 = 1 ;
F_48 ( V_9 ) ;
case V_73 :
F_72 ( V_9 , V_341 ) ;
F_46 ( V_9 ) ;
break;
case V_187 :
F_72 ( V_9 , V_345 ) ;
break;
case V_338 :
V_5 -> V_106 = 0 ;
case V_335 :
F_72 ( V_9 , V_342 ) ;
F_175 ( & V_9 -> V_12 -> V_87 ) ;
F_68 ( & V_9 -> V_12 -> V_88 ) ;
break;
case V_336 :
break;
case V_337 :
break;
}
break;
}
V_5 -> V_347 = V_330 ;
if ( V_331 )
F_65 ( V_9 , 0 ) ;
}
static int F_176 ( struct V_16 * V_12 , struct V_36 * V_195 )
{
int V_27 ;
if ( F_81 ( ( V_195 -> V_199 == ( V_348 - 1 ) ) ) ) {
if ( ! V_195 -> V_316 ) {
V_195 -> V_204 = V_348 ;
} else if ( ! V_195 -> V_203 ) {
V_195 -> V_203 = F_177 ( V_195 -> V_316 + sizeof( T_1 ) ,
V_349 ) ;
if ( ! V_195 -> V_203 )
return - V_142 ;
V_195 -> V_350 = 0 ;
}
return 0 ;
}
if ( F_81 ( V_195 -> V_199 == V_348 ) )
return - V_142 ;
V_195 -> V_191 = F_178 (
V_348 ,
sizeof( struct V_190 ) ,
V_349 ) ;
if ( ! V_195 -> V_191 )
return - V_142 ;
V_195 -> V_204 = V_348 - 1 ;
for ( V_27 = 0 ; V_27 < V_195 -> V_199 ; V_27 ++ )
V_195 -> V_191 [ V_27 ] = V_195 -> V_205 [ V_27 ] ;
return 0 ;
}
int F_179 ( struct V_16 * V_12 , struct V_36 * V_195 ,
int type , void * V_351 , struct V_352 * V_352 ,
unsigned long V_353 , T_3 V_288 )
{
int V_354 , V_117 ;
T_7 V_286 ;
V_117 = F_176 ( V_12 , V_195 ) ;
if ( V_117 ) {
F_34 ( V_12 , V_195 ) ;
return V_117 ;
}
if ( V_195 -> V_203 ) {
if ( type == V_355 ) {
F_34 ( V_12 , V_195 ) ;
return - V_317 ;
}
if ( type == V_194 ) {
V_351 = F_180 ( V_352 ) ;
V_351 += V_353 ;
} else if ( F_78 ( ! V_351 ) ) {
F_34 ( V_12 , V_195 ) ;
return - V_317 ;
}
memcpy ( V_195 -> V_203 + V_195 -> V_350 , V_351 , V_288 ) ;
V_195 -> V_350 += V_288 ;
if ( type == V_194 )
F_181 ( V_352 ) ;
if ( V_195 -> V_316 - V_195 -> V_350 )
return 0 ;
V_354 = V_195 -> V_356 & ( sizeof( T_1 ) - 1 ) ;
if ( V_354 ) {
V_354 = sizeof( T_1 ) - V_354 ;
memset ( V_195 -> V_203 + V_195 -> V_350 , 0 , V_354 ) ;
V_195 -> V_356 += V_354 ;
V_195 -> V_316 += V_354 ;
}
V_286 = F_182 ( & V_12 -> V_145 -> V_146 ,
V_195 -> V_203 ,
V_195 -> V_316 ,
V_193 ) ;
if ( F_81 ( F_183 ( & V_12 -> V_145 -> V_146 , V_286 ) ) ) {
F_34 ( V_12 , V_195 ) ;
return - V_357 ;
}
V_195 -> V_204 = V_348 ;
return F_184 ( V_12 , V_192 , V_195 ,
V_286 , V_195 -> V_316 ) ;
}
return 1 ;
}
void F_185 ( struct V_16 * V_12 , T_2 V_120 , T_1 V_358 )
{
struct V_8 * V_9 ;
int V_27 ;
T_2 V_359 ;
V_359 = ( ( V_120 & F_22 ( V_360 ) ) <<
F_22 ( V_361 ) ) |
( ( ( V_358 & V_120 ) & F_22 ( V_362 ) ) <<
F_22 ( V_363 ) ) ;
for ( V_27 = 0 ; V_27 < V_12 -> V_28 ; V_27 ++ ) {
F_186 ( V_364 , L_29 ,
V_27 , ( T_1 ) V_359 ) ;
V_9 = & V_12 -> V_29 [ V_27 ] ;
F_11 ( V_9 , F_22 ( V_282 ) , V_359 ) ;
}
}
int F_187 ( struct V_16 * V_12 , struct V_36 * V_195 )
{
int V_117 = 0 ;
V_195 -> V_199 ++ ;
if ( ( F_81 ( V_195 -> V_199 == V_195 -> V_204 ) ) ) {
V_117 = F_176 ( V_12 , V_195 ) ;
if ( V_117 ) {
F_34 ( V_12 , V_195 ) ;
return V_117 ;
}
}
F_188 (
V_195 ,
V_355 ,
V_12 -> V_147 ,
sizeof( T_1 ) - ( V_195 -> V_356 & ( sizeof( T_1 ) - 1 ) ) ) ;
F_189 ( V_12 , V_195 ) ;
return V_117 ;
}
void F_190 (
struct V_36 * V_195 ,
T_4 V_365 ,
T_4 V_366 ,
T_1 * V_367 ,
T_4 V_368 )
{
T_1 V_27 , V_369 = 0 , V_285 = 0 ;
T_4 V_201 ;
F_33 ( V_365 > 9 || ( V_368 & 3 ) || V_368 == 4 ) ;
if ( V_365 == 1 )
V_201 = V_202 ;
else if ( V_365 <= 5 )
V_201 = V_370 ;
else
V_201 = V_371 ;
V_195 -> V_199 ++ ;
switch ( V_201 ) {
case V_371 :
V_195 -> V_199 ++ ;
V_195 -> V_205 [ 2 ] . V_196 [ 0 ] = 0 ;
V_195 -> V_205 [ 2 ] . V_196 [ 1 ] = 0 ;
case V_370 :
V_195 -> V_199 ++ ;
V_195 -> V_205 [ 1 ] . V_196 [ 0 ] = 0 ;
V_195 -> V_205 [ 1 ] . V_196 [ 1 ] = 0 ;
break;
}
V_368 >>= 2 ;
V_195 -> V_205 [ 0 ] . V_196 [ 1 ] |=
( ( ( T_2 ) V_366 & V_372 )
<< V_298 ) |
( ( ( T_2 ) V_368 & V_373 )
<< V_300 ) |
( ( ( T_2 ) V_201 & V_374 )
<< V_198 ) |
( ( ( T_2 ) V_367 [ 0 ] & V_375 )
<< V_376 ) ;
for ( V_27 = 0 ; V_27 < ( V_365 - 1 ) ; V_27 ++ ) {
if ( ! V_369 && ! ( V_27 & 2 ) )
V_285 ++ ;
V_195 -> V_205 [ V_285 ] . V_196 [ ! ! ( V_27 & 2 ) ] |=
( ( ( T_2 ) V_367 [ V_27 + 1 ] )
<< V_369 ) ;
V_369 = ( V_369 + 32 ) & 63 ;
}
}
int F_191 ( struct V_8 * V_9 )
{
int V_377 ;
int V_378 ;
if ( ! V_9 ) {
F_192 ( V_9 , - V_317 ) ;
return - V_317 ;
}
while ( 1 ) {
V_377 = F_193 ( F_139 ( V_9 -> V_175 ) ) ;
if ( V_377 > 31 ) {
F_192 ( V_9 , - V_357 ) ;
return - V_357 ;
}
V_378 = F_194 ( V_377 , & V_9 -> V_175 ) ;
if ( ! V_378 )
break;
F_195 () ;
}
F_192 ( V_9 , V_377 ) ;
return V_377 ;
}
void F_196 ( struct V_8 * V_9 , int V_379 )
{
if ( ! V_9 )
return;
F_197 ( V_9 , V_379 ) ;
if ( V_379 < 0 || V_379 > 31 )
return;
F_198 ( V_379 , & V_9 -> V_175 ) ;
}
void F_199 ( struct V_16 * V_12 , int V_380 )
{
int V_27 ;
enum V_329 V_330 = V_380 ? V_338 :
V_335 ;
F_67 ( & V_12 -> V_87 , V_12 -> V_28 ) ;
for ( V_27 = 0 ; V_27 < V_12 -> V_28 ; V_27 ++ )
F_45 ( & V_12 -> V_29 [ V_27 ] , V_330 ) ;
}
void F_200 ( struct V_16 * V_12 )
{
int V_27 ;
int V_310 ;
V_310 = F_201 ( V_12 -> V_88 ,
F_202 ( & V_12 -> V_87 ) <= 0 ) ;
if ( V_310 || F_202 ( & V_12 -> V_87 ) < 0 )
return;
F_67 ( & V_12 -> V_87 , V_12 -> V_28 ) ;
for ( V_27 = 0 ; V_27 < V_12 -> V_28 ; V_27 ++ )
F_45 ( & V_12 -> V_29 [ V_27 ] , V_336 ) ;
( void ) F_201 ( V_12 -> V_88 ,
F_202 ( & V_12 -> V_87 ) <= 0 ) ;
}
void F_203 ( struct V_16 * V_12 )
{
int V_27 ;
for ( V_27 = 0 ; V_27 < V_12 -> V_28 ; V_27 ++ )
F_45 ( & V_12 -> V_29 [ V_27 ] ,
V_337 ) ;
}
void F_204 (
struct V_8 * V_9 )
{
F_205 ( V_9 , V_9 -> V_173 ) ;
F_206 ( V_9 -> V_12 ,
V_381 + ( 8 * ( V_382 / 64 ) ) , V_9 -> V_173 ) ;
}
