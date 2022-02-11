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
while ( 1 ) {
T_2 V_18 = F_16 ( V_12 , V_15 + V_19 ) ;
V_18 &= V_20 ;
V_18 >>= V_21 ;
if ( V_18 == 0 )
break;
if ( V_17 ++ > 100 ) {
F_17 ( V_12 , L_1 ,
V_22 , V_9 -> V_13 , ( T_1 ) V_18 ) ;
break;
}
F_18 ( 1 ) ;
}
}
void F_19 ( struct V_16 * V_12 )
{
int V_23 ;
for ( V_23 = 0 ; V_23 < V_12 -> V_24 ; V_23 ++ ) {
struct V_8 * V_9 = & V_12 -> V_25 [ V_23 ] ;
F_15 ( V_9 , 0 ) ;
}
}
static inline void F_20 ( struct V_8 * V_9 , unsigned V_26 )
{
T_2 V_18 ;
if ( ! ( V_9 -> V_12 -> V_27 & V_28 ) )
return;
V_18 = V_26 ;
V_18 &= F_21 ( V_29 ) ;
V_18 <<= F_21 ( V_30 ) ;
F_11 ( V_9 , F_21 ( V_31 ) , V_18 ) ;
}
static void F_22 ( struct V_8 * V_9 )
{
struct V_32 * V_33 , * V_34 ;
F_23 ( V_35 ) ;
F_24 ( V_9 ) ;
F_25 ( & V_9 -> V_36 ) ;
F_26 (txp, txp_next, &sde->flushlist, list) {
F_27 ( & V_33 -> V_37 ) ;
F_28 ( & V_33 -> V_37 , & V_35 ) ;
}
F_29 ( & V_9 -> V_36 ) ;
F_26 (txp, txp_next, &flushlist, list) {
int V_38 = 0 ;
struct V_39 * V_40 = V_33 -> V_40 ;
F_27 ( & V_33 -> V_37 ) ;
#ifdef F_30
F_31 ( V_9 , V_33 -> V_41 ) ;
if ( F_32 ( V_9 -> V_42 != V_33 -> V_41 ) )
F_17 ( V_9 -> V_12 , L_2 ,
V_9 -> V_42 , V_33 -> V_41 ) ;
V_9 -> V_42 ++ ;
#endif
F_33 ( V_9 -> V_12 , V_33 ) ;
if ( V_40 )
V_38 = F_34 ( & V_40 -> V_43 ) ;
if ( V_33 -> F_6 )
(* V_33 -> F_6 )( V_33 , V_44 , V_38 ) ;
if ( V_40 && V_38 )
F_35 ( V_40 ) ;
}
}
static void F_36 ( struct V_45 * V_46 )
{
unsigned long V_27 ;
struct V_8 * V_9 =
F_5 ( V_46 , struct V_8 , V_47 ) ;
F_37 ( & V_9 -> V_48 , V_27 ) ;
if ( ! F_38 ( V_9 ) )
F_22 ( V_9 ) ;
F_39 ( & V_9 -> V_48 , V_27 ) ;
}
static void F_40 ( struct V_45 * V_46 )
{
struct V_8 * V_9 = F_5 ( V_46 , struct V_8 ,
V_49 ) ;
T_2 V_50 ;
unsigned long V_51 ;
V_51 = V_52 + F_41 ( V_53 ) ;
while ( 1 ) {
V_50 = F_13 ( V_9 , F_21 ( V_54 ) ) ;
V_50 &= F_21 ( V_55 ) ;
if ( V_50 )
break;
if ( F_42 ( V_52 , V_51 ) ) {
F_17 ( V_9 -> V_12 ,
L_3 ,
V_9 -> V_13 ) ;
break;
}
F_43 ( 80 , 120 ) ;
}
F_44 ( V_9 , V_56 ) ;
}
static void F_45 ( struct V_8 * V_9 )
{
F_46 ( & V_9 -> V_49 ) ;
}
static void F_47 ( struct V_8 * V_9 )
{
if ( ! F_48 ( V_9 -> V_12 ) && F_49 ( V_57 ) ) {
unsigned V_58 ;
struct V_16 * V_12 = V_9 -> V_12 ;
for ( V_58 = 0 ; V_58 < V_12 -> V_24 ; V_58 ++ ) {
struct V_8 * V_59 = & V_12 -> V_25 [ V_58 ] ;
if ( V_59 != V_9 )
V_59 -> V_60 =
V_59 -> V_61 ;
}
F_17 ( V_9 -> V_12 ,
L_4 ,
V_9 -> V_13 ) ;
F_50 ( & V_9 -> V_62 , V_52 + 10 ) ;
}
}
static void F_51 ( unsigned long V_63 )
{
unsigned V_58 ;
struct V_8 * V_9 = (struct V_8 * ) V_63 ;
F_17 ( V_9 -> V_12 , L_5 ) ;
for ( V_58 = 0 ; V_58 < V_9 -> V_12 -> V_24 ; V_58 ++ ) {
struct V_8 * V_64 = & V_9 -> V_12 -> V_25 [ V_58 ] ;
unsigned long V_27 ;
if ( V_64 == V_9 )
continue;
F_52 ( & V_64 -> V_65 , V_27 ) ;
F_53 ( & V_64 -> V_48 ) ;
if ( V_64 -> V_2 . V_66 != V_67 ) {
F_54 ( & V_64 -> V_48 ) ;
F_55 ( & V_64 -> V_65 , V_27 ) ;
continue;
}
if ( ( V_64 -> V_61 != V_64 -> V_68 ) &&
( V_64 -> V_61 ==
V_64 -> V_60 ) )
F_56 ( V_64 ,
V_69 ) ;
F_54 ( & V_64 -> V_48 ) ;
F_55 ( & V_64 -> V_65 , V_27 ) ;
}
F_46 ( & V_9 -> V_49 ) ;
}
static void F_57 ( unsigned long V_70 )
{
struct V_8 * V_9 = (struct V_8 * ) V_70 ;
T_2 V_50 ;
while ( 1 ) {
#ifdef F_58
F_17 ( V_9 -> V_12 , L_6 ,
V_9 -> V_13 , F_59 ( __FILE__ ) , __LINE__ ,
V_22 ) ;
#endif
V_50 = F_13 ( V_9 , F_21 ( V_54 ) ) ;
V_50 &= F_21 ( V_71 ) ;
if ( V_50 )
break;
F_18 ( 10 ) ;
}
F_44 ( V_9 , V_72 ) ;
}
static inline struct V_32 * F_60 ( struct V_8 * V_9 )
{
F_61 () ;
return V_9 -> V_73 [ V_9 -> V_74 & V_9 -> V_75 ] ;
}
static void F_24 ( struct V_8 * V_9 )
{
T_3 V_76 , V_77 ;
int V_78 = 0 ;
struct V_32 * V_33 = F_60 ( V_9 ) ;
V_76 = V_9 -> V_61 & V_9 -> V_75 ;
V_77 = V_9 -> V_68 & V_9 -> V_75 ;
while ( V_76 != V_77 ) {
V_76 = ++ V_9 -> V_61 & V_9 -> V_75 ;
if ( V_33 && V_33 -> V_79 == V_76 ) {
int V_38 = 0 ;
struct V_39 * V_40 = V_33 -> V_40 ;
V_9 -> V_73 [ V_9 -> V_74 ++ & V_9 -> V_75 ] = NULL ;
if ( V_40 )
V_38 = F_34 ( & V_40 -> V_43 ) ;
#ifdef F_30
F_31 ( V_9 , V_33 -> V_41 ) ;
if ( F_32 ( V_9 -> V_42 != V_33 -> V_41 ) )
F_17 ( V_9 -> V_12 , L_2 ,
V_9 -> V_42 , V_33 -> V_41 ) ;
V_9 -> V_42 ++ ;
#endif
F_33 ( V_9 -> V_12 , V_33 ) ;
F_62 ( V_9 , V_76 , V_77 , V_33 ) ;
if ( V_33 -> F_6 )
(* V_33 -> F_6 )(
V_33 ,
V_44 ,
V_38 ) ;
if ( V_40 && V_38 )
F_35 ( V_40 ) ;
V_33 = F_60 ( V_9 ) ;
}
V_78 ++ ;
}
if ( V_78 )
F_63 ( V_9 , F_64 ( V_9 ) ) ;
}
static void F_65 ( unsigned long V_70 )
{
struct V_8 * V_9 = (struct V_8 * ) V_70 ;
unsigned long V_27 ;
F_52 ( & V_9 -> V_65 , V_27 ) ;
F_53 ( & V_9 -> V_48 ) ;
F_66 ( V_9 , 0 ) ;
F_22 ( V_9 ) ;
V_9 -> V_68 = 0 ;
V_9 -> V_61 = 0 ;
V_9 -> V_80 = F_64 ( V_9 ) ;
* V_9 -> V_81 = 0 ;
F_56 ( V_9 , V_82 ) ;
F_54 ( & V_9 -> V_48 ) ;
F_55 ( & V_9 -> V_65 , V_27 ) ;
}
static void F_67 ( struct V_8 * V_9 )
{
struct V_4 * V_5 = & V_9 -> V_2 ;
F_7 ( V_5 ) ;
F_68 ( & V_9 -> V_12 -> V_83 , - 1 ) ;
F_69 ( & V_9 -> V_12 -> V_84 ) ;
}
static void F_70 ( struct V_8 * V_9 )
{
F_71 ( & V_9 -> F_57 ) ;
}
static void F_72 ( struct V_8 * V_9 )
{
F_71 ( & V_9 -> F_65 ) ;
}
static void F_73 ( struct V_8 * V_9 ,
enum V_1 V_85 )
{
struct V_4 * V_5 = & V_9 -> V_2 ;
const struct V_86 * V_87 = V_88 ;
unsigned V_89 = 0 ;
F_74 (
V_9 ,
V_3 [ V_5 -> V_66 ] ,
V_3 [ V_85 ] ) ;
V_5 -> V_90 = V_5 -> V_66 ;
V_5 -> V_91 = V_5 -> V_92 ;
V_5 -> V_66 = V_85 ;
if ( V_5 -> V_90 != V_67
&& V_85 == V_67 )
F_22 ( V_9 ) ;
if ( V_87 [ V_85 ] . V_93 )
V_89 |= V_94 ;
if ( V_87 [ V_85 ] . V_95 )
V_89 |= V_96 ;
if ( V_87 [ V_85 ] . V_97 )
V_89 |= V_98 ;
if ( V_87 [ V_85 ] . V_99 )
V_89 |= V_100 ;
if ( V_87 [ V_85 ] . V_101 )
V_5 -> V_102 = 0 ;
if ( V_87 [ V_85 ] . V_103 )
V_5 -> V_102 = 1 ;
V_5 -> V_92 = V_89 ;
F_75 ( V_9 , V_5 -> V_92 ) ;
}
T_3 F_76 ( void )
{
T_3 V_104 = V_105 ;
if ( ! V_104 )
return V_106 ;
if ( ! F_77 ( V_104 ) )
return V_106 ;
if ( V_104 < 64 || V_104 > 32768 )
return V_106 ;
return V_104 ;
}
struct V_8 * F_78 (
struct V_16 * V_12 ,
T_1 V_107 ,
T_4 V_108 )
{
struct V_109 * V_110 ;
struct V_111 * V_112 ;
struct V_8 * V_113 ;
if ( F_79 ( V_108 > 8 ) )
return NULL ;
F_80 () ;
V_110 = F_81 ( V_12 -> V_114 ) ;
if ( F_82 ( ! V_110 ) ) {
F_83 () ;
return NULL ;
}
V_112 = V_110 -> V_115 [ V_108 & V_110 -> V_116 ] ;
V_113 = V_112 -> V_9 [ V_107 & V_112 -> V_116 ] ;
F_83 () ;
F_84 ( V_12 , V_107 , V_108 , V_113 -> V_13 ) ;
return V_113 ;
}
struct V_8 * F_85 (
struct V_16 * V_12 ,
T_1 V_107 ,
T_4 V_117 )
{
T_4 V_108 = F_86 ( V_12 , V_117 ) ;
return F_78 ( V_12 , V_107 , V_108 ) ;
}
static void F_87 ( struct V_109 * V_110 )
{
int V_23 ;
for ( V_23 = 0 ; V_110 && V_23 < V_110 -> V_118 ; V_23 ++ )
F_88 ( V_110 -> V_115 [ V_23 ] ) ;
F_88 ( V_110 ) ;
}
static void F_89 ( struct V_119 * V_37 )
{
struct V_109 * V_110 = F_5 ( V_37 , struct V_109 , V_37 ) ;
F_87 ( V_110 ) ;
}
int F_90 ( struct V_16 * V_12 , T_4 V_120 , T_4 V_121 , T_4 * V_122 )
{
int V_23 , V_123 ;
int V_124 , V_125 ;
int V_126 = 0 ;
T_4 V_127 [ V_128 ] ;
struct V_109 * V_129 , * V_130 ;
if ( ! ( V_12 -> V_27 & V_131 ) )
return 0 ;
if ( ! V_122 ) {
V_125 = V_12 -> V_24 / V_121 ;
V_124 = V_12 -> V_24 % V_121 ;
V_122 = V_127 ;
for ( V_23 = V_121 - 1 ; V_23 >= 0 ; V_23 -- , V_124 -- )
V_122 [ V_23 ] = V_125 + ( V_124 > 0 ? 1 : 0 ) ;
}
V_130 = F_91 (
sizeof( struct V_109 ) +
F_92 ( V_121 ) *
sizeof( struct V_111 * ) ,
V_132 ) ;
if ( ! V_130 )
goto V_133;
V_130 -> V_118 = V_121 ;
V_130 -> V_134 = F_92 ( V_121 ) ;
V_130 -> V_116 = ( 1 << F_93 ( V_130 -> V_134 ) ) - 1 ;
for ( V_23 = 0 ; V_23 < V_130 -> V_134 ; V_23 ++ ) {
int V_135 = V_126 ;
if ( V_23 < V_130 -> V_118 ) {
int V_136 = F_92 ( V_122 [ V_23 ] ) ;
V_130 -> V_115 [ V_23 ] = F_91 (
sizeof( struct V_111 ) +
V_136 * sizeof( struct V_8 * ) ,
V_132 ) ;
if ( ! V_130 -> V_115 [ V_23 ] )
goto V_133;
V_130 -> V_115 [ V_23 ] -> V_116 = ( 1 << F_93 ( V_136 ) ) - 1 ;
for ( V_123 = 0 ; V_123 < V_136 ; V_123 ++ ) {
V_130 -> V_115 [ V_23 ] -> V_9 [ V_123 ] =
& V_12 -> V_25 [ V_126 ] ;
if ( ++ V_126 >= V_135 + V_122 [ V_23 ] )
V_126 = V_135 ;
}
} else {
V_130 -> V_115 [ V_23 ] = V_130 -> V_115 [ V_23 % V_121 ] ;
}
V_126 = V_135 + V_122 [ V_23 ] ;
}
F_94 ( & V_12 -> V_137 ) ;
V_129 = F_95 ( V_12 -> V_114 ,
F_96 ( & V_12 -> V_137 ) ) ;
F_97 ( V_12 -> V_114 , V_130 ) ;
F_98 ( & V_12 -> V_137 ) ;
if ( V_129 )
F_99 ( & V_129 -> V_37 , F_89 ) ;
return 0 ;
V_133:
F_87 ( V_130 ) ;
return - V_138 ;
}
static void F_100 ( struct V_16 * V_12 , T_5 V_139 )
{
T_5 V_23 ;
struct V_8 * V_9 ;
if ( V_12 -> V_140 ) {
F_101 ( & V_12 -> V_141 -> V_142 , 4 ,
( void * ) V_12 -> V_140 ,
V_12 -> V_143 ) ;
V_12 -> V_140 = NULL ;
V_12 -> V_143 = 0 ;
}
if ( V_12 -> V_144 ) {
F_101 ( & V_12 -> V_141 -> V_142 , V_12 -> V_145 ,
( void * ) V_12 -> V_144 ,
V_12 -> V_146 ) ;
V_12 -> V_144 = NULL ;
V_12 -> V_146 = 0 ;
}
for ( V_23 = 0 ; V_12 -> V_25 && V_23 < V_139 ; ++ V_23 ) {
V_9 = & V_12 -> V_25 [ V_23 ] ;
V_9 -> V_81 = NULL ;
V_9 -> V_147 = 0 ;
if ( V_9 -> V_148 ) {
F_101 (
& V_12 -> V_141 -> V_142 ,
V_9 -> V_149 * sizeof( T_2 [ 2 ] ) ,
V_9 -> V_148 ,
V_9 -> V_150
) ;
V_9 -> V_148 = NULL ;
V_9 -> V_150 = 0 ;
}
if ( F_102 ( V_9 -> V_73 ) )
F_103 ( V_9 -> V_73 ) ;
else
F_88 ( V_9 -> V_73 ) ;
V_9 -> V_73 = NULL ;
}
F_94 ( & V_12 -> V_137 ) ;
F_88 ( F_104 ( V_12 -> V_114 ) ) ;
F_105 ( V_12 -> V_114 , NULL ) ;
F_98 ( & V_12 -> V_137 ) ;
F_106 () ;
F_88 ( V_12 -> V_25 ) ;
V_12 -> V_25 = NULL ;
}
int F_107 ( struct V_16 * V_12 , T_4 V_120 )
{
unsigned V_13 ;
struct V_8 * V_9 ;
T_3 V_149 ;
void * V_151 ;
struct V_152 * V_153 = V_12 -> V_154 + V_120 ;
T_1 V_155 ;
T_6 V_156 = V_157 ;
T_5 V_139 = V_12 -> V_158 ;
if ( ! F_49 ( V_159 ) ) {
F_108 ( V_57 ) ;
return 0 ;
}
if ( V_160 &&
V_160 <= V_12 -> V_158 &&
V_160 >= V_121 )
V_139 = V_160 ;
F_109 ( V_12 , L_7 , V_160 ) ;
F_109 ( V_12 , L_8 , V_12 -> V_158 ) ;
F_109 ( V_12 , L_9 ,
V_12 -> V_161 ) ;
V_155 =
V_12 -> V_161 / ( V_139 * V_162 ) ;
F_110 ( & V_12 -> V_84 ) ;
F_68 ( & V_12 -> V_83 , 0 ) ;
V_149 = F_76 () ;
F_109 ( V_12 , L_10 ,
V_139 , V_149 ) ;
V_12 -> V_25 = F_111 ( V_139 , sizeof( * V_12 -> V_25 ) , V_132 ) ;
if ( ! V_12 -> V_25 )
return - V_138 ;
V_156 = F_112 ( V_12 , V_156 ) ;
for ( V_13 = 0 ; V_13 < V_139 ; ++ V_13 ) {
V_9 = & V_12 -> V_25 [ V_13 ] ;
V_9 -> V_12 = V_12 ;
V_9 -> V_153 = V_153 ;
V_9 -> V_13 = V_13 ;
V_9 -> V_149 = V_149 ;
V_9 -> V_80 = F_64 ( V_9 ) ;
V_9 -> V_163 = F_93 ( V_149 ) ;
V_9 -> V_75 = ( 1 << V_9 -> V_163 ) - 1 ;
V_9 -> V_164 = 0 ;
V_9 -> V_165 = ( T_2 ) 1 << ( 0 * V_166 + V_13 )
| ( T_2 ) 1 << ( 1 * V_166 + V_13 )
| ( T_2 ) 1 << ( 2 * V_166 + V_13 ) ;
V_9 -> V_167 =
( T_2 ) 1 << ( 2 * V_166 + V_13 ) ;
V_9 -> V_168 =
( T_2 ) 1 << ( V_166 + V_13 ) ;
F_113 ( & V_9 -> V_65 ) ;
F_114 ( & V_9 -> V_48 ) ;
F_113 ( & V_9 -> V_169 ) ;
F_113 ( & V_9 -> V_36 ) ;
V_9 -> V_170 = 0xfffffffe00000000ULL ;
F_73 ( V_9 , V_171 ) ;
F_115 ( & V_9 -> V_2 . V_6 ) ;
F_116 ( & V_9 -> V_2 . V_7 ) ;
F_117 ( & V_9 -> V_35 ) ;
F_117 ( & V_9 -> V_172 ) ;
V_9 -> V_173 =
F_118 ( V_12 , V_13 , F_21 ( V_174 ) ) ;
if ( V_156 )
V_12 -> V_175 =
V_176 ;
else
V_12 -> V_175 =
V_177 ;
F_119 ( & V_9 -> F_57 , F_57 ,
( unsigned long ) V_9 ) ;
F_119 ( & V_9 -> F_65 , F_65 ,
( unsigned long ) V_9 ) ;
F_120 ( & V_9 -> V_49 , F_40 ) ;
F_120 ( & V_9 -> V_47 , F_36 ) ;
V_9 -> V_60 = 0 ;
F_121 ( & V_9 -> V_62 ) ;
V_9 -> V_62 . V_178 =
F_51 ;
V_9 -> V_62 . V_63 = ( unsigned long ) V_9 ;
V_9 -> V_148 = F_122 (
& V_12 -> V_141 -> V_142 ,
V_149 * sizeof( T_2 [ 2 ] ) ,
& V_9 -> V_150 ,
V_132
) ;
if ( ! V_9 -> V_148 )
goto V_133;
V_9 -> V_73 =
F_111 ( V_149 , sizeof( struct V_32 * ) ,
V_132 ) ;
if ( ! V_9 -> V_73 )
V_9 -> V_73 =
F_123 (
sizeof( struct V_32 * ) *
V_149 ) ;
if ( ! V_9 -> V_73 )
goto V_133;
}
V_12 -> V_145 = V_179 * V_139 ;
V_12 -> V_144 = F_122 (
& V_12 -> V_141 -> V_142 ,
V_12 -> V_145 ,
& V_12 -> V_146 ,
V_132
) ;
if ( ! V_12 -> V_144 ) {
F_17 ( V_12 , L_11 ) ;
goto V_133;
}
V_12 -> V_140 = F_122 (
& V_12 -> V_141 -> V_142 ,
sizeof( T_1 ) ,
& V_12 -> V_143 ,
V_132
) ;
if ( ! V_12 -> V_140 ) {
F_17 ( V_12 , L_12 ) ;
goto V_133;
}
V_151 = ( void * ) V_12 -> V_144 ;
for ( V_13 = 0 ; V_13 < V_139 ; ++ V_13 ) {
unsigned long V_180 ;
V_9 = & V_12 -> V_25 [ V_13 ] ;
V_9 -> V_81 = V_151 ;
V_151 += V_179 ;
V_180 = ( unsigned long ) V_9 -> V_81 -
( unsigned long ) V_12 -> V_144 ;
V_9 -> V_147 = V_12 -> V_146 + V_180 ;
F_124 ( V_9 , V_155 , V_156 ) ;
}
V_12 -> V_27 |= V_131 ;
V_12 -> V_27 |= V_156 ? V_28 : 0 ;
V_12 -> V_24 = V_139 ;
if ( F_90 ( V_12 , V_120 , V_153 -> V_181 , NULL ) )
goto V_133;
F_109 ( V_12 , L_13 , V_12 -> V_24 ) ;
return 0 ;
V_133:
F_100 ( V_12 , V_139 ) ;
return - V_138 ;
}
void F_125 ( struct V_16 * V_12 )
{
struct V_8 * V_9 ;
unsigned int V_23 ;
for ( V_23 = 0 ; V_23 < V_12 -> V_24 ; ++ V_23 ) {
V_9 = & V_12 -> V_25 [ V_23 ] ;
F_44 ( V_9 , V_182 ) ;
}
}
void F_126 ( struct V_16 * V_12 )
{
struct V_8 * V_9 ;
unsigned int V_23 ;
for ( V_23 = 0 ; V_23 < V_12 -> V_24 ; ++ V_23 ) {
V_9 = & V_12 -> V_25 [ V_23 ] ;
F_44 ( V_9 , V_183 ) ;
}
}
void F_127 ( struct V_16 * V_12 )
{
unsigned V_23 ;
struct V_8 * V_9 ;
for ( V_23 = 0 ; V_23 < V_12 -> V_24 ; ++ V_23 ) {
V_9 = & V_12 -> V_25 [ V_23 ] ;
F_44 ( V_9 , V_184 ) ;
}
}
void F_128 ( struct V_16 * V_12 )
{
unsigned V_13 ;
struct V_8 * V_9 ;
for ( V_13 = 0 ; V_12 -> V_25 && V_13 < V_12 -> V_24 ;
++ V_13 ) {
V_9 = & V_12 -> V_25 [ V_13 ] ;
if ( ! F_129 ( & V_9 -> V_172 ) )
F_17 ( V_12 , L_14 ,
V_9 -> V_13 ) ;
F_44 ( V_9 , V_185 ) ;
F_130 ( & V_9 -> V_62 ) ;
F_9 ( & V_9 -> V_2 ) ;
}
F_100 ( V_12 , V_12 -> V_24 ) ;
}
static inline void F_131 (
struct V_16 * V_12 ,
struct V_186 * V_187 )
{
switch ( F_132 ( V_187 ) ) {
case V_188 :
F_133 (
& V_12 -> V_141 -> V_142 ,
F_134 ( V_187 ) ,
F_135 ( V_187 ) ,
V_189 ) ;
break;
case V_190 :
F_136 (
& V_12 -> V_141 -> V_142 ,
F_134 ( V_187 ) ,
F_135 ( V_187 ) ,
V_189 ) ;
break;
}
}
static inline T_4 F_137 ( struct V_32 * V_191 )
{
return ( V_191 -> V_187 [ 0 ] . V_192 [ 1 ] & V_193 )
>> V_194 ;
}
void F_33 (
struct V_16 * V_12 ,
struct V_32 * V_191 )
{
T_3 V_23 ;
if ( V_191 -> V_195 ) {
T_4 V_196 = 0 , V_197 = F_137 ( V_191 ) ;
F_131 ( V_12 , & V_191 -> V_187 [ 0 ] ) ;
if ( V_197 > V_198 )
V_196 = V_197 >> 1 ;
for ( V_23 = 1 + V_196 ; V_23 < V_191 -> V_195 ; V_23 ++ )
F_131 ( V_12 , & V_191 -> V_187 [ V_23 ] ) ;
V_191 -> V_195 = 0 ;
}
F_88 ( V_191 -> V_199 ) ;
V_191 -> V_199 = NULL ;
if ( F_82 ( V_191 -> V_200 > F_138 ( V_191 -> V_201 ) ) ) {
V_191 -> V_200 = F_138 ( V_191 -> V_201 ) ;
F_88 ( V_191 -> V_187 ) ;
}
}
static inline T_3 F_139 ( struct V_8 * V_9 )
{
struct V_16 * V_12 = V_9 -> V_12 ;
int V_202 ;
T_3 V_203 ;
#ifdef F_58
F_17 ( V_9 -> V_12 , L_6 ,
V_9 -> V_13 , F_59 ( __FILE__ ) , __LINE__ , V_22 ) ;
#endif
V_204:
V_202 = F_49 ( V_205 ) && F_38 ( V_9 ) &&
( V_12 -> V_27 & V_28 ) ;
V_203 = V_202 ?
( T_3 ) F_140 ( * V_9 -> V_81 ) :
( T_3 ) F_13 ( V_9 , F_21 ( V_206 ) ) ;
if ( F_82 ( F_49 ( V_207 ) ) ) {
T_3 V_26 ;
T_3 V_208 ;
T_3 V_209 ;
int V_210 ;
V_209 = V_9 -> V_61 & V_9 -> V_75 ;
V_208 = F_141 ( V_9 -> V_68 ) & V_9 -> V_75 ;
V_26 = V_9 -> V_149 ;
if ( V_209 < V_208 )
V_210 = ( V_203 >= V_209 ) & ( V_203 <= V_208 ) ;
else if ( V_209 > V_208 )
V_210 = ( ( V_203 >= V_209 ) && ( V_203 < V_26 ) ) ||
( V_203 <= V_208 ) ;
else
V_210 = ( V_203 == V_209 ) ;
if ( F_82 ( ! V_210 ) ) {
F_17 ( V_12 , L_15 ,
V_9 -> V_13 ,
V_202 ? L_16 : L_17 ,
V_203 , V_209 , V_208 , V_26 ) ;
if ( V_202 ) {
V_202 = 0 ;
goto V_204;
}
V_203 = V_209 ;
}
}
return V_203 ;
}
static void F_63 ( struct V_8 * V_9 , unsigned V_211 )
{
struct V_39 * V_40 , * V_212 ;
struct V_39 * V_213 [ V_214 ] ;
unsigned V_23 , V_215 = 0 , V_216 ;
struct V_32 * V_217 ;
struct V_218 * V_142 = & V_9 -> V_12 -> V_219 ;
#ifdef F_58
F_17 ( V_9 -> V_12 , L_6 , V_9 -> V_13 ,
F_59 ( __FILE__ ) , __LINE__ , V_22 ) ;
F_17 ( V_9 -> V_12 , L_18 , V_211 ) ;
#endif
do {
V_216 = F_142 ( & V_142 -> V_220 ) ;
if ( ! F_129 ( & V_9 -> V_172 ) ) {
F_53 ( & V_142 -> V_220 ) ;
F_26 (
wait,
nw,
&sde->dmawait,
list) {
T_3 V_195 = 0 ;
if ( ! V_40 -> V_221 )
continue;
if ( V_215 == F_138 ( V_213 ) )
break;
if ( ! F_129 ( & V_40 -> V_74 ) ) {
V_217 = F_143 (
& V_40 -> V_74 ,
struct V_32 ,
V_37 ) ;
V_195 = V_217 -> V_195 ;
}
if ( V_195 > V_211 )
break;
V_211 -= V_195 ;
F_27 ( & V_40 -> V_37 ) ;
V_213 [ V_215 ++ ] = V_40 ;
}
F_54 ( & V_142 -> V_220 ) ;
break;
}
} while ( F_144 ( & V_142 -> V_220 , V_216 ) );
for ( V_23 = 0 ; V_23 < V_215 ; V_23 ++ )
V_213 [ V_23 ] -> V_221 ( V_213 [ V_23 ] , V_222 ) ;
}
static void F_66 ( struct V_8 * V_9 , T_2 V_223 )
{
struct V_32 * V_33 = NULL ;
int V_78 = 0 ;
T_3 V_203 , V_209 , V_208 ;
int V_224 = 0 ;
V_203 = F_139 ( V_9 ) ;
V_204:
V_33 = F_60 ( V_9 ) ;
V_209 = V_9 -> V_61 & V_9 -> V_75 ;
F_62 ( V_9 , V_203 , V_209 , V_33 ) ;
while ( V_209 != V_203 ) {
V_209 = ++ V_9 -> V_61 & V_9 -> V_75 ;
if ( V_33 && V_33 -> V_79 == V_209 ) {
int V_38 = 0 ;
struct V_39 * V_40 = V_33 -> V_40 ;
V_9 -> V_73 [ V_9 -> V_74 ++ & V_9 -> V_75 ] = NULL ;
if ( V_40 )
V_38 = F_34 ( & V_40 -> V_43 ) ;
#ifdef F_30
F_31 ( V_9 , V_33 -> V_41 ) ;
if ( F_32 ( V_9 -> V_42 != V_33 -> V_41 ) )
F_17 ( V_9 -> V_12 , L_2 ,
V_9 -> V_42 , V_33 -> V_41 ) ;
V_9 -> V_42 ++ ;
#endif
F_33 ( V_9 -> V_12 , V_33 ) ;
if ( V_33 -> F_6 )
(* V_33 -> F_6 )(
V_33 ,
V_225 ,
V_38 ) ;
if ( V_40 && V_38 )
F_35 ( V_40 ) ;
V_33 = F_60 ( V_9 ) ;
}
F_62 ( V_9 , V_203 , V_209 , V_33 ) ;
V_78 ++ ;
}
if ( ( V_223 & V_9 -> V_167 ) && ! V_224 ) {
V_208 = F_141 ( V_9 -> V_68 ) & V_9 -> V_75 ;
if ( V_208 != V_203 ) {
V_203 = ( T_3 ) F_13 ( V_9 , F_21 ( V_206 ) ) ;
V_224 = 1 ;
goto V_204;
}
}
V_9 -> V_226 = V_223 ;
if ( V_78 )
F_63 ( V_9 , F_64 ( V_9 ) ) ;
}
void F_145 ( struct V_8 * V_9 , T_2 V_223 )
{
F_146 ( V_9 , V_223 ) ;
F_53 ( & V_9 -> V_48 ) ;
F_20 ( V_9 , V_9 -> V_149 / 2 ) ;
F_66 ( V_9 , V_223 ) ;
F_54 ( & V_9 -> V_48 ) ;
}
void F_147 ( struct V_8 * V_9 , T_2 V_223 )
{
unsigned long V_27 ;
#ifdef F_58
F_17 ( V_9 -> V_12 , L_19 ,
V_9 -> V_13 ,
( unsigned long long ) V_223 ,
V_3 [ V_9 -> V_2 . V_66 ] ) ;
#endif
F_52 ( & V_9 -> V_65 , V_27 ) ;
F_53 ( & V_9 -> V_48 ) ;
if ( V_223 & V_227 )
F_56 ( V_9 , V_228 ) ;
if ( V_223 & ~ F_21 ( V_229 ) ) {
F_17 ( V_9 -> V_12 ,
L_20 ,
V_9 -> V_13 ,
( unsigned long long ) V_223 ,
V_3 [ V_9 -> V_2 . V_66 ] ) ;
F_148 ( V_9 ) ;
}
F_54 ( & V_9 -> V_48 ) ;
F_55 ( & V_9 -> V_65 , V_27 ) ;
}
static void F_75 ( struct V_8 * V_9 , unsigned V_89 )
{
T_2 V_230 = 0 ;
T_2 V_231 = 0 ;
unsigned long V_27 ;
#ifdef F_58
F_17 ( V_9 -> V_12 , L_21 ,
V_9 -> V_13 ,
( V_89 & V_94 ) ? 1 : 0 ,
( V_89 & V_96 ) ? 1 : 0 ,
( V_89 & V_98 ) ? 1 : 0 ,
( V_89 & V_100 ) ? 1 : 0 ) ;
#endif
if ( V_89 & V_94 )
V_230 |= F_21 ( V_232 ) ;
else
V_231 |= F_21 ( V_232 ) ;
if ( V_89 & V_96 )
V_230 |= F_21 ( V_233 ) ;
else
V_231 |= F_21 ( V_233 ) ;
if ( V_89 & V_98 )
V_230 |= F_21 ( V_234 ) ;
else
V_231 |= F_21 ( V_234 ) ;
F_52 ( & V_9 -> V_169 , V_27 ) ;
V_9 -> V_235 |= V_230 ;
V_9 -> V_235 &= ~ V_231 ;
if ( V_89 & V_100 )
F_11 ( V_9 , F_21 ( V_236 ) ,
V_9 -> V_235 |
F_21 ( V_237 ) ) ;
else
F_11 ( V_9 , F_21 ( V_236 ) , V_9 -> V_235 ) ;
F_55 ( & V_9 -> V_169 , V_27 ) ;
#ifdef F_58
F_149 ( V_9 ) ;
#endif
}
static void F_150 ( struct V_8 * V_9 )
{
#ifdef F_58
F_17 ( V_9 -> V_12 , L_6 ,
V_9 -> V_13 , F_59 ( __FILE__ ) , __LINE__ , V_22 ) ;
#endif
F_11 ( V_9 , F_21 ( V_238 ) ,
( V_9 -> V_149 / 64 ) << F_21 ( V_239 )
) ;
F_11 ( V_9 , F_21 ( V_238 ) ,
( ( V_9 -> V_149 / 64 ) << F_21 ( V_239 ) )
| ( 4ULL << F_21 ( V_240 ) )
) ;
}
static inline void F_151 ( struct V_8 * V_9 , T_3 V_77 )
{
F_152 () ;
F_153 ( V_77 , V_9 -> V_173 ) ;
}
static void F_154 ( struct V_8 * V_9 )
{
T_2 V_18 ;
#ifdef F_58
F_17 ( V_9 -> V_12 , L_6 ,
V_9 -> V_13 , F_59 ( __FILE__ ) , __LINE__ , V_22 ) ;
#endif
F_150 ( V_9 ) ;
F_151 ( V_9 , 0 ) ;
* V_9 -> V_81 = 0 ;
V_18 = F_21 ( V_241 ) <<
F_21 ( V_242 ) ;
F_11 ( V_9 , F_21 ( V_243 ) , V_18 ) ;
}
static void F_155 ( struct V_8 * V_9 )
{
struct V_16 * V_12 = V_9 -> V_12 ;
T_2 V_18 ;
if ( F_82 ( F_49 ( V_244 ) ) )
return;
V_18 = F_156 ( V_12 ) ;
if ( F_49 ( V_245 ) )
F_157 ( V_18 ) ;
else
F_158 ( V_18 ) ;
F_11 ( V_9 , F_21 ( V_246 ) , V_18 ) ;
}
static void F_124 (
struct V_8 * V_9 ,
T_1 V_247 ,
T_6 V_156 )
{
T_4 V_248 , V_249 ;
#ifdef F_58
struct V_16 * V_12 = V_9 -> V_12 ;
F_17 ( V_12 , L_6 ,
V_9 -> V_13 , F_59 ( __FILE__ ) , __LINE__ , V_22 ) ;
#endif
F_11 ( V_9 , F_21 ( V_250 ) , V_9 -> V_150 ) ;
F_150 ( V_9 ) ;
F_151 ( V_9 , 0 ) ;
F_11 ( V_9 , F_21 ( V_251 ) , V_156 ) ;
F_11 ( V_9 , F_21 ( V_31 ) , 0 ) ;
F_11 ( V_9 , F_21 ( V_252 ) , V_9 -> V_147 ) ;
F_11 ( V_9 , F_21 ( V_253 ) ,
( ( T_2 ) V_247 <<
F_21 ( V_254 ) ) |
( ( T_2 ) ( V_247 * V_9 -> V_13 ) <<
F_21 ( V_255 ) ) ) ;
F_11 ( V_9 , F_21 ( V_256 ) , ~ 0ull ) ;
F_155 ( V_9 ) ;
V_249 = V_257 ;
V_248 = V_258 ;
F_11 ( V_9 , F_21 ( V_259 ) ,
( V_249 << V_260 ) |
( V_248 << V_261 ) ) ;
}
void F_149 ( struct V_8 * V_9 )
{
T_2 V_262 ;
unsigned V_23 ;
F_159 ( F_21 ( V_236 ) ) ;
F_159 ( F_21 ( V_54 ) ) ;
F_160 ( F_21 ( V_263 ) ) ;
F_160 ( F_21 ( V_264 ) ) ;
F_159 ( F_21 ( V_265 ) ) ;
F_159 ( F_21 ( V_256 ) ) ;
for ( V_23 = 0 ; V_23 < V_266 ; ++ V_23 ) {
F_161 ( V_267 ) ;
F_161 ( V_268 ) ;
F_161 ( V_269 ) ;
}
F_159 ( F_21 ( V_174 ) ) ;
F_159 ( F_21 ( V_206 ) ) ;
F_159 ( F_21 ( V_270 ) ) ;
F_159 ( F_21 ( V_271 ) ) ;
F_159 ( F_21 ( V_251 ) ) ;
F_159 ( F_21 ( V_31 ) ) ;
F_159 ( F_21 ( V_272 ) ) ;
F_159 ( F_21 ( V_253 ) ) ;
F_160 ( F_21 ( V_273 ) ) ;
F_160 ( F_21 ( V_274 ) ) ;
F_159 ( F_21 ( V_250 ) ) ;
F_159 ( F_21 ( V_238 ) ) ;
F_159 ( F_21 ( V_252 ) ) ;
F_159 ( F_21 ( V_246 ) ) ;
F_159 ( F_21 ( V_275 ) ) ;
F_159 ( F_21 ( V_276 ) ) ;
F_159 ( F_21 ( V_277 ) ) ;
F_159 ( F_21 ( V_278 ) ) ;
F_159 ( F_21 ( V_259 ) ) ;
}
static void F_148 ( struct V_8 * V_9 )
{
struct V_279 * V_148 ;
struct V_279 * V_280 ;
T_2 V_281 [ 2 ] ;
T_2 V_282 ;
T_4 V_283 ;
T_3 V_284 ;
T_3 V_76 , V_77 , V_26 ;
V_76 = V_9 -> V_61 & V_9 -> V_75 ;
V_77 = V_9 -> V_68 & V_9 -> V_75 ;
V_26 = F_64 ( V_9 ) ;
V_148 = V_9 -> V_148 ;
F_17 ( V_9 -> V_12 ,
L_22 ,
V_9 -> V_13 ,
V_76 ,
V_77 ,
V_26 ,
! F_129 ( & V_9 -> V_35 ) ) ;
while ( V_76 != V_77 ) {
char V_27 [ 6 ] = { 'x' , 'x' , 'x' , 'x' , 0 } ;
V_280 = & V_9 -> V_148 [ V_76 ] ;
V_281 [ 0 ] = F_140 ( V_280 -> V_192 [ 0 ] ) ;
V_281 [ 1 ] = F_140 ( V_280 -> V_192 [ 1 ] ) ;
V_27 [ 0 ] = ( V_281 [ 1 ] & V_177 ) ? 'I' : '-' ;
V_27 [ 1 ] = ( V_281 [ 1 ] & V_176 ) ?
'H' : '-' ;
V_27 [ 2 ] = ( V_281 [ 0 ] & V_285 ) ? 'F' : '-' ;
V_27 [ 3 ] = ( V_281 [ 0 ] & V_286 ) ? 'L' : '-' ;
V_282 = ( V_281 [ 0 ] >> V_287 )
& V_288 ;
V_283 = ( V_281 [ 1 ] >> V_289 )
& V_290 ;
V_284 = ( V_281 [ 0 ] >> V_291 )
& V_292 ;
F_17 ( V_9 -> V_12 ,
L_23 ,
V_76 , V_27 , V_282 , V_283 , V_284 ) ;
F_17 ( V_9 -> V_12 ,
L_24 ,
V_281 [ 0 ] , V_281 [ 1 ] ) ;
if ( V_281 [ 0 ] & V_285 )
F_17 ( V_9 -> V_12 ,
L_25 ,
( T_4 ) ( ( V_281 [ 1 ] & V_293 )
>> V_294 ) ,
( T_4 ) ( ( V_281 [ 1 ] & V_193 )
>> V_194 ) ,
( T_4 ) ( ( V_281 [ 1 ] & V_295 )
>> V_296 ) ) ;
V_76 ++ ;
V_76 &= V_9 -> V_75 ;
}
}
void F_162 ( struct V_297 * V_298 , struct V_8 * V_9 )
{
T_3 V_76 , V_77 ;
struct V_279 * V_280 ;
T_2 V_281 [ 2 ] ;
T_2 V_282 ;
T_4 V_283 ;
T_3 V_284 ;
V_76 = V_9 -> V_61 & V_9 -> V_75 ;
V_77 = F_141 ( V_9 -> V_68 ) & V_9 -> V_75 ;
F_163 ( V_298 , V_299 , V_9 -> V_13 ,
F_1 ( V_9 -> V_2 . V_66 ) ,
( unsigned long long ) F_13 ( V_9 , F_21 ( V_236 ) ) ,
( unsigned long long ) F_13 ( V_9 , F_21 ( V_54 ) ) ,
( unsigned long long ) F_13 ( V_9 ,
F_21 ( V_265 ) ) ,
( unsigned long long ) F_13 ( V_9 , F_21 ( V_174 ) ) ,
V_77 ,
( unsigned long long ) F_13 ( V_9 , F_21 ( V_206 ) ) ,
V_76 ,
( unsigned long long ) F_140 ( * V_9 -> V_81 ) ,
( unsigned long long ) F_13 ( V_9 , F_21 ( V_253 ) ) ,
( unsigned long long ) F_13 ( V_9 , F_21 ( V_238 ) ) ,
( unsigned long long ) F_13 ( V_9 , F_21 ( V_251 ) ) ,
( unsigned long long ) V_9 -> V_226 ,
( unsigned long long ) V_9 -> V_170 ,
V_9 -> V_300 ,
V_9 -> V_74 ,
V_9 -> V_68 ,
V_9 -> V_61 ,
! F_129 ( & V_9 -> V_35 ) ,
V_9 -> V_164 ,
( unsigned long long ) F_13 ( V_9 , V_301 ) ) ;
while ( V_76 != V_77 ) {
char V_27 [ 6 ] = { 'x' , 'x' , 'x' , 'x' , 0 } ;
V_280 = & V_9 -> V_148 [ V_76 ] ;
V_281 [ 0 ] = F_140 ( V_280 -> V_192 [ 0 ] ) ;
V_281 [ 1 ] = F_140 ( V_280 -> V_192 [ 1 ] ) ;
V_27 [ 0 ] = ( V_281 [ 1 ] & V_177 ) ? 'I' : '-' ;
V_27 [ 1 ] = ( V_281 [ 1 ] & V_176 ) ?
'H' : '-' ;
V_27 [ 2 ] = ( V_281 [ 0 ] & V_285 ) ? 'F' : '-' ;
V_27 [ 3 ] = ( V_281 [ 0 ] & V_286 ) ? 'L' : '-' ;
V_282 = ( V_281 [ 0 ] >> V_287 )
& V_288 ;
V_283 = ( V_281 [ 1 ] >> V_289 )
& V_290 ;
V_284 = ( V_281 [ 0 ] >> V_291 )
& V_292 ;
F_163 ( V_298 ,
L_26 ,
V_76 , V_27 , V_282 , V_283 , V_284 ) ;
if ( V_281 [ 0 ] & V_285 )
F_163 ( V_298 , L_27 ,
( T_4 ) ( ( V_281 [ 1 ] & V_293 )
>> V_294 ) ,
( T_4 ) ( ( V_281 [ 1 ] & V_193 )
>> V_194 ) ) ;
V_76 = ( V_76 + 1 ) & V_9 -> V_75 ;
}
}
static inline T_2 F_164 ( struct V_8 * V_9 , T_2 V_302 )
{
T_4 V_303 = ( V_9 -> V_68 >> V_9 -> V_163 ) & 3 ;
V_302 &= ~ V_304 ;
V_302 |= ( ( T_2 ) V_303 & V_290 )
<< V_289 ;
return V_302 ;
}
static inline T_3 F_165 ( struct V_8 * V_9 , struct V_32 * V_191 )
{
int V_23 ;
T_3 V_77 ;
struct V_186 * V_187 = V_191 -> V_187 ;
T_4 V_196 = 0 , V_197 = F_137 ( V_191 ) ;
V_77 = V_9 -> V_68 & V_9 -> V_75 ;
V_9 -> V_148 [ V_77 ] . V_192 [ 0 ] = F_166 ( V_187 -> V_192 [ 0 ] ) ;
V_9 -> V_148 [ V_77 ] . V_192 [ 1 ] = F_166 ( F_164 ( V_9 , V_187 -> V_192 [ 1 ] ) ) ;
F_167 ( V_9 , V_187 -> V_192 [ 0 ] , V_187 -> V_192 [ 1 ] ,
V_77 , & V_9 -> V_148 [ V_77 ] ) ;
V_77 = ++ V_9 -> V_68 & V_9 -> V_75 ;
V_187 ++ ;
if ( V_197 > V_198 )
V_196 = V_197 >> 1 ;
for ( V_23 = 1 ; V_23 < V_191 -> V_195 ; V_23 ++ , V_187 ++ ) {
T_2 V_302 ;
V_9 -> V_148 [ V_77 ] . V_192 [ 0 ] = F_166 ( V_187 -> V_192 [ 0 ] ) ;
if ( V_196 ) {
V_302 = V_187 -> V_192 [ 1 ] ;
V_196 -- ;
} else {
V_302 = F_164 ( V_9 , V_187 -> V_192 [ 1 ] ) ;
}
V_9 -> V_148 [ V_77 ] . V_192 [ 1 ] = F_166 ( V_302 ) ;
F_167 ( V_9 , V_187 -> V_192 [ 0 ] , V_302 ,
V_77 , & V_9 -> V_148 [ V_77 ] ) ;
V_77 = ++ V_9 -> V_68 & V_9 -> V_75 ;
}
V_191 -> V_79 = V_77 ;
#ifdef F_30
V_191 -> V_41 = V_9 -> V_305 ++ ;
F_168 ( V_9 , V_191 -> V_41 ) ;
F_32 ( V_9 -> V_73 [ V_9 -> V_300 & V_9 -> V_75 ] ) ;
#endif
V_9 -> V_73 [ V_9 -> V_300 ++ & V_9 -> V_75 ] = V_191 ;
V_9 -> V_80 -= V_191 -> V_195 ;
return V_77 ;
}
static int F_169 (
struct V_8 * V_9 ,
struct V_39 * V_40 ,
struct V_32 * V_191 )
{
int V_306 ;
V_9 -> V_80 = F_64 ( V_9 ) ;
if ( V_191 -> V_195 <= V_9 -> V_80 )
return - V_307 ;
if ( V_40 && V_40 -> V_308 ) {
unsigned V_216 ;
V_216 = F_170 (
( const V_309 * ) & V_9 -> V_48 . V_310 ) ;
V_306 = V_40 -> V_308 ( V_9 , V_40 , V_191 , V_216 ) ;
if ( V_306 == - V_307 )
V_9 -> V_80 = F_64 ( V_9 ) ;
} else
V_306 = - V_311 ;
return V_306 ;
}
int F_171 ( struct V_8 * V_9 ,
struct V_39 * V_40 ,
struct V_32 * V_191 )
{
int V_306 = 0 ;
T_3 V_77 ;
unsigned long V_27 ;
if ( F_82 ( V_191 -> V_312 ) )
return - V_313 ;
V_191 -> V_40 = V_40 ;
F_52 ( & V_9 -> V_65 , V_27 ) ;
V_204:
if ( F_82 ( ! F_38 ( V_9 ) ) )
goto V_314;
if ( F_82 ( V_191 -> V_195 > V_9 -> V_80 ) )
goto V_315;
V_77 = F_165 ( V_9 , V_191 ) ;
if ( V_40 )
F_172 ( & V_40 -> V_43 ) ;
F_151 ( V_9 , V_77 ) ;
V_316:
F_55 ( & V_9 -> V_65 , V_27 ) ;
return V_306 ;
V_314:
if ( V_40 )
F_172 ( & V_40 -> V_43 ) ;
V_191 -> V_79 = 0 ;
#ifdef F_30
V_191 -> V_41 = V_9 -> V_305 ++ ;
F_168 ( V_9 , V_191 -> V_41 ) ;
#endif
F_25 ( & V_9 -> V_36 ) ;
F_28 ( & V_191 -> V_37 , & V_9 -> V_35 ) ;
F_29 ( & V_9 -> V_36 ) ;
if ( V_40 ) {
V_40 -> V_317 ++ ;
V_40 -> V_104 += V_191 -> V_195 ;
}
F_46 ( & V_9 -> V_47 ) ;
V_306 = - V_318 ;
goto V_316;
V_315:
V_306 = F_169 ( V_9 , V_40 , V_191 ) ;
if ( V_306 == - V_307 ) {
V_306 = 0 ;
goto V_204;
}
V_9 -> V_164 ++ ;
goto V_316;
}
int F_173 ( struct V_8 * V_9 ,
struct V_39 * V_40 ,
struct V_319 * V_320 )
{
struct V_32 * V_191 , * V_321 ;
int V_306 = 0 ;
unsigned long V_27 ;
T_3 V_77 = V_322 ;
int V_104 = 0 ;
F_52 ( & V_9 -> V_65 , V_27 ) ;
V_204:
F_26 (tx, tx_next, tx_list, list) {
V_191 -> V_40 = V_40 ;
if ( F_82 ( ! F_38 ( V_9 ) ) )
goto V_314;
if ( F_82 ( V_191 -> V_195 > V_9 -> V_80 ) )
goto V_315;
if ( F_82 ( V_191 -> V_312 ) ) {
V_306 = - V_313 ;
goto V_323;
}
F_27 ( & V_191 -> V_37 ) ;
V_77 = F_165 ( V_9 , V_191 ) ;
V_104 ++ ;
if ( V_77 != V_322 &&
( V_104 & V_324 ) == 0 ) {
F_151 ( V_9 , V_77 ) ;
V_77 = V_322 ;
}
}
V_323:
if ( V_40 )
F_174 ( V_104 , & V_40 -> V_43 ) ;
if ( V_77 != V_322 )
F_151 ( V_9 , V_77 ) ;
F_55 ( & V_9 -> V_65 , V_27 ) ;
return V_306 ;
V_314:
F_25 ( & V_9 -> V_36 ) ;
F_26 (tx, tx_next, tx_list, list) {
V_191 -> V_40 = V_40 ;
F_27 ( & V_191 -> V_37 ) ;
if ( V_40 )
F_172 ( & V_40 -> V_43 ) ;
V_191 -> V_79 = 0 ;
#ifdef F_30
V_191 -> V_41 = V_9 -> V_305 ++ ;
F_168 ( V_9 , V_191 -> V_41 ) ;
#endif
F_28 ( & V_191 -> V_37 , & V_9 -> V_35 ) ;
if ( V_40 ) {
V_40 -> V_317 ++ ;
V_40 -> V_104 += V_191 -> V_195 ;
}
}
F_29 ( & V_9 -> V_36 ) ;
F_46 ( & V_9 -> V_47 ) ;
V_306 = - V_318 ;
goto V_323;
V_315:
V_306 = F_169 ( V_9 , V_40 , V_191 ) ;
if ( V_306 == - V_307 ) {
V_306 = 0 ;
goto V_204;
}
V_9 -> V_164 ++ ;
goto V_323;
}
static void F_44 ( struct V_8 * V_9 ,
enum V_325 V_326 )
{
unsigned long V_27 ;
F_52 ( & V_9 -> V_65 , V_27 ) ;
F_53 ( & V_9 -> V_48 ) ;
F_56 ( V_9 , V_326 ) ;
if ( V_9 -> V_2 . V_66 == V_67 )
F_63 ( V_9 , F_64 ( V_9 ) ) ;
F_54 ( & V_9 -> V_48 ) ;
F_55 ( & V_9 -> V_65 , V_27 ) ;
}
static void F_56 ( struct V_8 * V_9 ,
enum V_325 V_326 )
{
struct V_4 * V_5 = & V_9 -> V_2 ;
int V_327 = 0 ;
#ifdef F_58
F_17 ( V_9 -> V_12 , L_28 , V_9 -> V_13 ,
V_3 [ V_5 -> V_66 ] ,
V_328 [ V_326 ] ) ;
#endif
switch ( V_5 -> V_66 ) {
case V_171 :
switch ( V_326 ) {
case V_185 :
break;
case V_182 :
V_5 -> V_102 = 1 ;
case V_184 :
F_2 ( & V_9 -> V_2 ) ;
F_73 ( V_9 ,
V_329 ) ;
break;
case V_56 :
break;
case V_72 :
break;
case V_82 :
F_67 ( V_9 ) ;
break;
case V_330 :
break;
case V_228 :
break;
case V_183 :
break;
case V_331 :
break;
case V_332 :
break;
case V_333 :
break;
case V_334 :
break;
case V_69 :
break;
}
break;
case V_329 :
switch ( V_326 ) {
case V_185 :
F_73 ( V_9 , V_171 ) ;
F_67 ( V_9 ) ;
break;
case V_184 :
break;
case V_56 :
F_73 ( V_9 ,
V_335 ) ;
F_70 ( V_9 ) ;
break;
case V_72 :
break;
case V_182 :
V_5 -> V_102 = 1 ;
break;
case V_82 :
break;
case V_330 :
break;
case V_228 :
F_45 ( V_9 ) ;
break;
case V_183 :
V_5 -> V_102 = 0 ;
break;
case V_331 :
break;
case V_332 :
break;
case V_333 :
break;
case V_334 :
break;
case V_69 :
break;
}
break;
case V_335 :
switch ( V_326 ) {
case V_185 :
F_73 ( V_9 , V_171 ) ;
F_67 ( V_9 ) ;
break;
case V_184 :
break;
case V_56 :
break;
case V_72 :
F_154 ( V_9 ) ;
F_73 ( V_9 , V_5 -> V_102 ?
V_67 :
V_336 ) ;
break;
case V_182 :
V_5 -> V_102 = 1 ;
break;
case V_82 :
break;
case V_330 :
break;
case V_228 :
break;
case V_183 :
V_5 -> V_102 = 0 ;
break;
case V_331 :
break;
case V_332 :
break;
case V_333 :
break;
case V_334 :
break;
case V_69 :
break;
}
break;
case V_336 :
switch ( V_326 ) {
case V_185 :
F_73 ( V_9 , V_171 ) ;
F_67 ( V_9 ) ;
break;
case V_184 :
break;
case V_56 :
break;
case V_72 :
break;
case V_182 :
F_73 ( V_9 , V_67 ) ;
V_5 -> V_102 = 1 ;
break;
case V_82 :
break;
case V_330 :
break;
case V_228 :
F_73 ( V_9 , V_337 ) ;
F_45 ( V_9 ) ;
break;
case V_183 :
break;
case V_334 :
case V_331 :
F_73 ( V_9 , V_338 ) ;
F_175 ( & V_9 -> V_12 -> V_83 ) ;
F_69 ( & V_9 -> V_12 -> V_84 ) ;
break;
case V_332 :
break;
case V_333 :
break;
case V_69 :
break;
}
break;
case V_339 :
switch ( V_326 ) {
case V_185 :
F_73 ( V_9 , V_171 ) ;
break;
case V_184 :
break;
case V_56 :
break;
case V_72 :
break;
case V_182 :
V_5 -> V_102 = 1 ;
break;
case V_82 :
F_73 ( V_9 , V_340 ) ;
F_70 ( V_9 ) ;
break;
case V_330 :
break;
case V_228 :
break;
case V_183 :
V_5 -> V_102 = 0 ;
break;
case V_331 :
break;
case V_332 :
break;
case V_333 :
break;
case V_334 :
V_5 -> V_102 = 0 ;
break;
case V_69 :
break;
}
break;
case V_340 :
switch ( V_326 ) {
case V_185 :
F_73 ( V_9 , V_171 ) ;
F_72 ( V_9 ) ;
break;
case V_184 :
break;
case V_56 :
break;
case V_72 :
F_154 ( V_9 ) ;
F_73 ( V_9 , V_5 -> V_102 ?
V_67 :
V_336 ) ;
break;
case V_182 :
V_5 -> V_102 = 1 ;
break;
case V_82 :
break;
case V_330 :
break;
case V_228 :
break;
case V_183 :
V_5 -> V_102 = 0 ;
break;
case V_331 :
break;
case V_332 :
break;
case V_333 :
break;
case V_334 :
V_5 -> V_102 = 0 ;
break;
case V_69 :
break;
}
break;
case V_337 :
switch ( V_326 ) {
case V_185 :
F_73 ( V_9 , V_171 ) ;
F_72 ( V_9 ) ;
break;
case V_184 :
break;
case V_56 :
F_73 ( V_9 , V_339 ) ;
F_72 ( V_9 ) ;
break;
case V_72 :
break;
case V_182 :
V_5 -> V_102 = 1 ;
break;
case V_82 :
break;
case V_330 :
break;
case V_228 :
F_45 ( V_9 ) ;
break;
case V_183 :
V_5 -> V_102 = 0 ;
break;
case V_331 :
break;
case V_332 :
break;
case V_333 :
break;
case V_334 :
V_5 -> V_102 = 0 ;
break;
case V_69 :
break;
}
break;
case V_341 :
switch ( V_326 ) {
case V_185 :
F_73 ( V_9 , V_171 ) ;
F_72 ( V_9 ) ;
break;
case V_184 :
break;
case V_56 :
F_73 ( V_9 , V_339 ) ;
F_72 ( V_9 ) ;
break;
case V_72 :
break;
case V_182 :
V_5 -> V_102 = 1 ;
break;
case V_82 :
break;
case V_330 :
break;
case V_228 :
F_45 ( V_9 ) ;
break;
case V_183 :
V_5 -> V_102 = 0 ;
break;
case V_331 :
break;
case V_332 :
break;
case V_333 :
break;
case V_334 :
break;
case V_69 :
break;
}
break;
case V_338 :
switch ( V_326 ) {
case V_185 :
F_73 ( V_9 , V_171 ) ;
F_72 ( V_9 ) ;
break;
case V_184 :
break;
case V_56 :
break;
case V_72 :
break;
case V_182 :
V_5 -> V_102 = 1 ;
break;
case V_82 :
break;
case V_330 :
break;
case V_228 :
break;
case V_183 :
V_5 -> V_102 = 0 ;
break;
case V_331 :
break;
case V_332 :
F_73 ( V_9 , V_342 ) ;
F_72 ( V_9 ) ;
break;
case V_333 :
break;
case V_334 :
break;
case V_69 :
break;
}
break;
case V_342 :
switch ( V_326 ) {
case V_185 :
F_73 ( V_9 , V_171 ) ;
F_72 ( V_9 ) ;
break;
case V_184 :
break;
case V_56 :
break;
case V_72 :
break;
case V_182 :
V_5 -> V_102 = 1 ;
break;
case V_82 :
F_175 ( & V_9 -> V_12 -> V_83 ) ;
F_69 ( & V_9 -> V_12 -> V_84 ) ;
break;
case V_330 :
break;
case V_228 :
break;
case V_183 :
V_5 -> V_102 = 0 ;
break;
case V_331 :
break;
case V_332 :
break;
case V_333 :
F_154 ( V_9 ) ;
F_73 ( V_9 , V_5 -> V_102 ?
V_67 :
V_336 ) ;
break;
case V_334 :
break;
case V_69 :
break;
}
break;
case V_67 :
switch ( V_326 ) {
case V_185 :
F_73 ( V_9 , V_171 ) ;
F_72 ( V_9 ) ;
break;
case V_184 :
break;
case V_56 :
break;
case V_72 :
break;
case V_182 :
break;
case V_82 :
break;
case V_330 :
break;
case V_228 :
V_327 = 1 ;
F_47 ( V_9 ) ;
case V_69 :
F_73 ( V_9 , V_337 ) ;
F_45 ( V_9 ) ;
break;
case V_183 :
F_73 ( V_9 , V_341 ) ;
break;
case V_334 :
V_5 -> V_102 = 0 ;
case V_331 :
F_73 ( V_9 , V_338 ) ;
F_175 ( & V_9 -> V_12 -> V_83 ) ;
F_69 ( & V_9 -> V_12 -> V_84 ) ;
break;
case V_332 :
break;
case V_333 :
break;
}
break;
}
V_5 -> V_343 = V_326 ;
if ( V_327 )
F_66 ( V_9 , 0 ) ;
}
int F_176 ( struct V_16 * V_12 , struct V_32 * V_191 )
{
int V_23 ;
V_191 -> V_187 = F_177 (
V_344 ,
sizeof( struct V_186 ) ,
V_345 ) ;
if ( ! V_191 -> V_187 )
return - V_138 ;
V_191 -> V_200 = V_344 ;
for ( V_23 = 0 ; V_23 < V_191 -> V_195 ; V_23 ++ )
V_191 -> V_187 [ V_23 ] = V_191 -> V_201 [ V_23 ] ;
return 0 ;
}
void F_178 ( struct V_16 * V_12 , T_2 V_116 , T_1 V_346 )
{
struct V_8 * V_9 ;
int V_23 ;
T_2 V_347 ;
V_347 = ( ( V_116 & F_21 ( V_348 ) ) <<
F_21 ( V_349 ) ) |
( ( ( V_346 & V_116 ) & F_21 ( V_350 ) ) <<
F_21 ( V_351 ) ) ;
for ( V_23 = 0 ; V_23 < V_12 -> V_24 ; V_23 ++ ) {
F_179 ( V_352 , L_29 ,
V_23 , ( T_1 ) V_347 ) ;
V_9 = & V_12 -> V_25 [ V_23 ] ;
F_11 ( V_9 , F_21 ( V_278 ) , V_347 ) ;
}
}
int F_180 ( struct V_16 * V_12 , struct V_32 * V_191 )
{
int V_113 = 0 ;
if ( ( F_82 ( V_191 -> V_195 == V_191 -> V_200 ) ) ) {
V_113 = F_176 ( V_12 , V_191 ) ;
if ( V_113 )
return V_113 ;
}
V_191 -> V_195 ++ ;
F_181 (
V_191 ,
V_353 ,
V_12 -> V_143 ,
sizeof( T_1 ) - ( V_191 -> V_354 & ( sizeof( T_1 ) - 1 ) ) ) ;
F_182 ( V_12 , V_191 ) ;
return V_113 ;
}
void F_183 (
struct V_32 * V_191 ,
T_4 V_355 ,
T_4 V_356 ,
T_1 * V_357 ,
T_4 V_358 )
{
T_1 V_23 , V_359 = 0 , V_281 = 0 ;
T_4 V_197 ;
F_32 ( V_355 > 9 || ( V_358 & 3 ) || V_358 == 4 ) ;
if ( V_355 == 1 )
V_197 = V_198 ;
else if ( V_355 <= 5 )
V_197 = V_360 ;
else
V_197 = V_361 ;
V_191 -> V_195 ++ ;
switch ( V_197 ) {
case V_361 :
V_191 -> V_195 ++ ;
V_191 -> V_201 [ 2 ] . V_192 [ 0 ] = 0 ;
V_191 -> V_201 [ 2 ] . V_192 [ 1 ] = 0 ;
case V_360 :
V_191 -> V_195 ++ ;
V_191 -> V_201 [ 1 ] . V_192 [ 0 ] = 0 ;
V_191 -> V_201 [ 1 ] . V_192 [ 1 ] = 0 ;
break;
}
V_358 >>= 2 ;
V_191 -> V_201 [ 0 ] . V_192 [ 1 ] |=
( ( ( T_2 ) V_356 & V_362 )
<< V_294 ) |
( ( ( T_2 ) V_358 & V_363 )
<< V_296 ) |
( ( ( T_2 ) V_197 & V_364 )
<< V_194 ) |
( ( ( T_2 ) V_357 [ 0 ] & V_365 )
<< V_366 ) ;
for ( V_23 = 0 ; V_23 < ( V_355 - 1 ) ; V_23 ++ ) {
if ( ! V_359 && ! ( V_23 & 2 ) )
V_281 ++ ;
V_191 -> V_201 [ V_281 ] . V_192 [ ! ! ( V_23 & 2 ) ] |=
( ( ( T_2 ) V_357 [ V_23 + 1 ] )
<< V_359 ) ;
V_359 = ( V_359 + 32 ) & 63 ;
}
}
int F_184 ( struct V_8 * V_9 )
{
int V_367 ;
int V_368 ;
if ( ! V_9 ) {
F_185 ( V_9 , - V_313 ) ;
return - V_313 ;
}
while ( 1 ) {
V_367 = F_186 ( F_141 ( V_9 -> V_170 ) ) ;
if ( V_367 > 31 ) {
F_185 ( V_9 , - V_369 ) ;
return - V_369 ;
}
V_368 = F_187 ( V_367 , & V_9 -> V_170 ) ;
if ( ! V_368 )
break;
F_188 () ;
}
F_185 ( V_9 , V_367 ) ;
return V_367 ;
}
void F_189 ( struct V_8 * V_9 , int V_370 )
{
if ( ! V_9 )
return;
F_190 ( V_9 , V_370 ) ;
if ( V_370 < 0 || V_370 > 31 )
return;
F_191 ( V_370 , & V_9 -> V_170 ) ;
}
void F_192 ( struct V_16 * V_12 , int V_371 )
{
int V_23 ;
enum V_325 V_326 = V_371 ? V_334 :
V_331 ;
F_68 ( & V_12 -> V_83 , V_12 -> V_24 ) ;
for ( V_23 = 0 ; V_23 < V_12 -> V_24 ; V_23 ++ )
F_44 ( & V_12 -> V_25 [ V_23 ] , V_326 ) ;
}
void F_193 ( struct V_16 * V_12 )
{
int V_23 ;
int V_306 ;
V_306 = F_194 ( V_12 -> V_84 ,
F_195 ( & V_12 -> V_83 ) <= 0 ) ;
if ( V_306 || F_195 ( & V_12 -> V_83 ) < 0 )
return;
F_68 ( & V_12 -> V_83 , V_12 -> V_24 ) ;
for ( V_23 = 0 ; V_23 < V_12 -> V_24 ; V_23 ++ )
F_44 ( & V_12 -> V_25 [ V_23 ] , V_332 ) ;
( void ) F_194 ( V_12 -> V_84 ,
F_195 ( & V_12 -> V_83 ) <= 0 ) ;
}
void F_196 ( struct V_16 * V_12 )
{
int V_23 ;
for ( V_23 = 0 ; V_23 < V_12 -> V_24 ; V_23 ++ )
F_44 ( & V_12 -> V_25 [ V_23 ] ,
V_333 ) ;
}
void F_197 (
struct V_8 * V_9 )
{
F_198 ( V_9 , V_9 -> V_168 ) ;
F_199 ( V_9 -> V_12 ,
V_372 + ( 8 * ( V_373 / 64 ) ) , V_9 -> V_168 ) ;
}
