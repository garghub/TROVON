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
if ( ! F_47 ( V_9 -> V_12 ) && F_48 ( V_61 ) ) {
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
F_49 ( & V_9 -> V_66 , V_56 + 10 ) ;
}
}
static void F_50 ( unsigned long V_67 )
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
F_51 ( & V_68 -> V_52 ) ;
if ( V_68 -> V_2 . V_70 != V_71 ) {
F_52 ( & V_68 -> V_52 ) ;
F_30 ( & V_68 -> V_69 , V_31 ) ;
continue;
}
if ( ( V_68 -> V_65 != V_68 -> V_72 ) &&
( V_68 -> V_65 ==
V_68 -> V_64 ) )
F_53 ( V_68 ,
V_73 ) ;
F_52 ( & V_68 -> V_52 ) ;
F_30 ( & V_68 -> V_69 , V_31 ) ;
}
F_54 ( & V_9 -> V_53 ) ;
}
static void F_55 ( unsigned long V_74 )
{
struct V_8 * V_9 = (struct V_8 * ) V_74 ;
T_2 V_54 ;
while ( 1 ) {
#ifdef F_56
F_17 ( V_9 -> V_12 , L_6 ,
V_9 -> V_13 , F_57 ( __FILE__ ) , __LINE__ ,
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
static inline struct V_36 * F_58 ( struct V_8 * V_9 )
{
F_59 () ;
return V_9 -> V_77 [ V_9 -> V_78 & V_9 -> V_79 ] ;
}
static void F_25 ( struct V_8 * V_9 )
{
T_3 V_80 , V_81 ;
int V_82 = 0 ;
struct V_36 * V_37 = F_58 ( V_9 ) ;
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
F_60 ( V_9 , V_80 , V_81 , V_37 ) ;
if ( V_37 -> F_6 )
(* V_37 -> F_6 )(
V_37 ,
V_48 ,
V_42 ) ;
if ( V_44 && V_42 )
F_36 ( V_44 ) ;
V_37 = F_58 ( V_9 ) ;
}
V_82 ++ ;
}
if ( V_82 )
F_61 ( V_9 , F_62 ( V_9 ) ) ;
}
static void F_63 ( unsigned long V_74 )
{
struct V_8 * V_9 = (struct V_8 * ) V_74 ;
unsigned long V_31 ;
F_26 ( & V_9 -> V_69 , V_31 ) ;
F_51 ( & V_9 -> V_52 ) ;
F_64 ( V_9 , 0 ) ;
F_23 ( V_9 ) ;
V_9 -> V_72 = 0 ;
V_9 -> V_65 = 0 ;
V_9 -> V_84 = F_62 ( V_9 ) ;
* V_9 -> V_85 = 0 ;
F_53 ( V_9 , V_86 ) ;
F_52 ( & V_9 -> V_52 ) ;
F_30 ( & V_9 -> V_69 , V_31 ) ;
}
static void F_65 ( struct V_8 * V_9 )
{
struct V_4 * V_5 = & V_9 -> V_2 ;
F_7 ( V_5 ) ;
F_66 ( & V_9 -> V_12 -> V_87 , - 1 ) ;
F_67 ( & V_9 -> V_12 -> V_88 ) ;
}
static void F_68 ( struct V_8 * V_9 )
{
F_69 ( & V_9 -> F_55 ) ;
}
static void F_70 ( struct V_8 * V_9 ,
enum V_1 V_89 )
{
struct V_4 * V_5 = & V_9 -> V_2 ;
const struct V_90 * V_91 = V_92 ;
unsigned V_93 = 0 ;
F_71 (
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
F_72 ( V_9 , V_5 -> V_96 ) ;
}
T_3 F_73 ( void )
{
T_3 V_108 = V_109 ;
if ( ! V_108 )
return V_110 ;
if ( ! F_74 ( V_108 ) )
return V_110 ;
if ( V_108 < 64 || V_108 > 32768 )
return V_110 ;
return V_108 ;
}
struct V_8 * F_75 (
struct V_16 * V_12 ,
T_1 V_111 ,
T_4 V_112 )
{
struct V_113 * V_114 ;
struct V_115 * V_116 ;
struct V_8 * V_117 ;
if ( V_112 >= V_118 ) {
V_117 = NULL ;
goto V_119;
}
F_76 () ;
V_114 = F_77 ( V_12 -> V_120 ) ;
if ( F_78 ( ! V_114 ) ) {
F_79 () ;
return & V_12 -> V_29 [ 0 ] ;
}
V_116 = V_114 -> V_121 [ V_112 & V_114 -> V_122 ] ;
V_117 = V_116 -> V_9 [ V_111 & V_116 -> V_122 ] ;
F_79 () ;
V_119:
V_117 = ! V_117 ? & V_12 -> V_29 [ 0 ] : V_117 ;
F_80 ( V_12 , V_111 , V_112 , V_117 -> V_13 ) ;
return V_117 ;
}
struct V_8 * F_81 (
struct V_16 * V_12 ,
T_1 V_111 ,
T_4 V_123 )
{
T_4 V_112 = F_82 ( V_12 , V_123 ) ;
return F_75 ( V_12 , V_111 , V_112 ) ;
}
static void F_83 ( struct V_113 * V_114 )
{
int V_27 ;
for ( V_27 = 0 ; V_114 && V_27 < V_114 -> V_124 ; V_27 ++ )
F_84 ( V_114 -> V_121 [ V_27 ] ) ;
F_84 ( V_114 ) ;
}
static void F_85 ( struct V_125 * V_41 )
{
struct V_113 * V_114 = F_5 ( V_41 , struct V_113 , V_41 ) ;
F_83 ( V_114 ) ;
}
int F_86 ( struct V_16 * V_12 , T_4 V_126 , T_4 V_118 , T_4 * V_127 )
{
int V_27 , V_128 ;
int V_129 , V_130 ;
int V_131 = 0 ;
T_4 V_132 [ V_133 ] ;
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
V_135 = F_87 (
sizeof( struct V_113 ) +
F_88 ( V_118 ) *
sizeof( struct V_115 * ) ,
V_137 ) ;
if ( ! V_135 )
goto V_138;
V_135 -> V_124 = V_118 ;
V_135 -> V_139 = F_88 ( V_118 ) ;
V_135 -> V_122 = ( 1 << F_89 ( V_135 -> V_139 ) ) - 1 ;
for ( V_27 = 0 ; V_27 < V_135 -> V_139 ; V_27 ++ ) {
int V_140 = V_131 ;
if ( V_27 < V_135 -> V_124 ) {
int V_141 = F_88 ( V_127 [ V_27 ] ) ;
V_135 -> V_121 [ V_27 ] = F_87 (
sizeof( struct V_115 ) +
V_141 * sizeof( struct V_8 * ) ,
V_137 ) ;
if ( ! V_135 -> V_121 [ V_27 ] )
goto V_138;
V_135 -> V_121 [ V_27 ] -> V_122 = ( 1 << F_89 ( V_141 ) ) - 1 ;
for ( V_128 = 0 ; V_128 < V_141 ; V_128 ++ ) {
V_135 -> V_121 [ V_27 ] -> V_9 [ V_128 ] =
& V_12 -> V_29 [ V_131 ] ;
if ( ++ V_131 >= V_140 + V_127 [ V_27 ] )
V_131 = V_140 ;
}
} else {
V_135 -> V_121 [ V_27 ] = V_135 -> V_121 [ V_27 % V_118 ] ;
}
V_131 = V_140 + V_127 [ V_27 ] ;
}
F_90 ( & V_12 -> V_142 ) ;
V_134 = F_91 ( V_12 -> V_120 ,
F_92 ( & V_12 -> V_142 ) ) ;
F_93 ( V_12 -> V_120 , V_135 ) ;
F_94 ( & V_12 -> V_142 ) ;
if ( V_134 )
F_95 ( & V_134 -> V_41 , F_85 ) ;
return 0 ;
V_138:
F_83 ( V_135 ) ;
return - V_143 ;
}
static void F_96 ( struct V_16 * V_12 , T_5 V_144 )
{
T_5 V_27 ;
struct V_8 * V_9 ;
if ( V_12 -> V_145 ) {
F_97 ( & V_12 -> V_146 -> V_147 , 4 ,
( void * ) V_12 -> V_145 ,
V_12 -> V_148 ) ;
V_12 -> V_145 = NULL ;
V_12 -> V_148 = 0 ;
}
if ( V_12 -> V_149 ) {
F_97 ( & V_12 -> V_146 -> V_147 , V_12 -> V_150 ,
( void * ) V_12 -> V_149 ,
V_12 -> V_151 ) ;
V_12 -> V_149 = NULL ;
V_12 -> V_151 = 0 ;
}
for ( V_27 = 0 ; V_12 -> V_29 && V_27 < V_144 ; ++ V_27 ) {
V_9 = & V_12 -> V_29 [ V_27 ] ;
V_9 -> V_85 = NULL ;
V_9 -> V_152 = 0 ;
if ( V_9 -> V_153 ) {
F_97 (
& V_12 -> V_146 -> V_147 ,
V_9 -> V_154 * sizeof( T_2 [ 2 ] ) ,
V_9 -> V_153 ,
V_9 -> V_155
) ;
V_9 -> V_153 = NULL ;
V_9 -> V_155 = 0 ;
}
F_98 ( V_9 -> V_77 ) ;
V_9 -> V_77 = NULL ;
}
F_90 ( & V_12 -> V_142 ) ;
F_84 ( F_99 ( V_12 -> V_120 ) ) ;
F_100 ( V_12 -> V_120 , NULL ) ;
F_94 ( & V_12 -> V_142 ) ;
F_101 () ;
F_84 ( V_12 -> V_29 ) ;
V_12 -> V_29 = NULL ;
}
int F_102 ( struct V_16 * V_12 , T_4 V_126 )
{
unsigned V_13 ;
struct V_8 * V_9 ;
T_3 V_154 ;
void * V_156 ;
struct V_157 * V_158 = V_12 -> V_24 + V_126 ;
T_1 V_159 ;
T_6 V_160 = V_161 ;
T_5 V_144 = V_12 -> V_162 ;
if ( ! F_48 ( V_163 ) ) {
F_103 ( V_61 ) ;
return 0 ;
}
if ( V_164 &&
V_164 <= V_12 -> V_162 &&
V_164 >= V_118 )
V_144 = V_164 ;
F_104 ( V_12 , L_7 , V_164 ) ;
F_104 ( V_12 , L_8 , V_12 -> V_162 ) ;
F_104 ( V_12 , L_9 ,
V_12 -> V_165 ) ;
V_159 =
V_12 -> V_165 / ( V_144 * V_166 ) ;
F_105 ( & V_12 -> V_88 ) ;
F_66 ( & V_12 -> V_87 , 0 ) ;
V_154 = F_73 () ;
F_104 ( V_12 , L_10 ,
V_144 , V_154 ) ;
V_12 -> V_29 = F_106 ( V_144 , sizeof( * V_12 -> V_29 ) , V_137 ) ;
if ( ! V_12 -> V_29 )
return - V_143 ;
V_160 = F_107 ( V_12 , V_160 ) ;
if ( ! V_167 )
V_167 = V_168 ;
for ( V_13 = 0 ; V_13 < V_144 ; ++ V_13 ) {
V_9 = & V_12 -> V_29 [ V_13 ] ;
V_9 -> V_12 = V_12 ;
V_9 -> V_158 = V_158 ;
V_9 -> V_13 = V_13 ;
V_9 -> V_154 = V_154 ;
V_9 -> V_84 = F_62 ( V_9 ) ;
V_9 -> V_169 = F_89 ( V_154 ) ;
V_9 -> V_79 = ( 1 << V_9 -> V_169 ) - 1 ;
V_9 -> V_170 = 0 ;
V_9 -> V_171 = ( T_2 ) 1 << ( 0 * V_172 + V_13 )
| ( T_2 ) 1 << ( 1 * V_172 + V_13 )
| ( T_2 ) 1 << ( 2 * V_172 + V_13 ) ;
V_9 -> V_173 =
( T_2 ) 1 << ( 2 * V_172 + V_13 ) ;
V_9 -> V_174 =
( T_2 ) 1 << ( V_172 + V_13 ) ;
F_108 ( & V_9 -> V_69 ) ;
F_109 ( & V_9 -> V_52 ) ;
F_108 ( & V_9 -> V_175 ) ;
F_108 ( & V_9 -> V_40 ) ;
V_9 -> V_176 = 0xfffffffe00000000ULL ;
F_70 ( V_9 , V_177 ) ;
F_110 ( & V_9 -> V_2 . V_6 ) ;
F_111 ( & V_9 -> V_2 . V_7 ) ;
F_112 ( & V_9 -> V_39 ) ;
F_112 ( & V_9 -> V_178 ) ;
V_9 -> V_179 =
F_113 ( V_12 , V_13 , F_22 ( V_180 ) ) ;
if ( V_160 )
V_12 -> V_181 =
V_182 ;
else
V_12 -> V_181 =
V_183 ;
F_114 ( & V_9 -> F_55 , F_55 ,
( unsigned long ) V_9 ) ;
F_114 ( & V_9 -> F_63 , F_63 ,
( unsigned long ) V_9 ) ;
F_115 ( & V_9 -> V_53 , F_41 ) ;
F_115 ( & V_9 -> V_51 , F_37 ) ;
V_9 -> V_64 = 0 ;
F_116 ( & V_9 -> V_66 ,
F_50 , ( unsigned long ) V_9 ) ;
V_9 -> V_153 = F_117 (
& V_12 -> V_146 -> V_147 ,
V_154 * sizeof( T_2 [ 2 ] ) ,
& V_9 -> V_155 ,
V_137
) ;
if ( ! V_9 -> V_153 )
goto V_138;
V_9 -> V_77 =
F_106 ( V_154 , sizeof( struct V_36 * ) ,
V_137 ) ;
if ( ! V_9 -> V_77 )
V_9 -> V_77 =
F_118 (
sizeof( struct V_36 * ) *
V_154 ) ;
if ( ! V_9 -> V_77 )
goto V_138;
}
V_12 -> V_150 = V_184 * V_144 ;
V_12 -> V_149 = F_117 (
& V_12 -> V_146 -> V_147 ,
V_12 -> V_150 ,
& V_12 -> V_151 ,
V_137
) ;
if ( ! V_12 -> V_149 ) {
F_17 ( V_12 , L_11 ) ;
goto V_138;
}
V_12 -> V_145 = F_117 (
& V_12 -> V_146 -> V_147 ,
sizeof( T_1 ) ,
& V_12 -> V_148 ,
V_137
) ;
if ( ! V_12 -> V_145 ) {
F_17 ( V_12 , L_12 ) ;
goto V_138;
}
V_156 = ( void * ) V_12 -> V_149 ;
for ( V_13 = 0 ; V_13 < V_144 ; ++ V_13 ) {
unsigned long V_185 ;
V_9 = & V_12 -> V_29 [ V_13 ] ;
V_9 -> V_85 = V_156 ;
V_156 += V_184 ;
V_185 = ( unsigned long ) V_9 -> V_85 -
( unsigned long ) V_12 -> V_149 ;
V_9 -> V_152 = V_12 -> V_151 + V_185 ;
F_119 ( V_9 , V_159 , V_160 ) ;
}
V_12 -> V_31 |= V_136 ;
V_12 -> V_31 |= V_160 ? V_32 : 0 ;
V_12 -> V_28 = V_144 ;
if ( F_86 ( V_12 , V_126 , V_158 -> V_186 , NULL ) )
goto V_138;
F_104 ( V_12 , L_13 , V_12 -> V_28 ) ;
return 0 ;
V_138:
F_96 ( V_12 , V_144 ) ;
return - V_143 ;
}
void F_120 ( struct V_16 * V_12 )
{
struct V_8 * V_9 ;
unsigned int V_27 ;
for ( V_27 = 0 ; V_27 < V_12 -> V_28 ; ++ V_27 ) {
V_9 = & V_12 -> V_29 [ V_27 ] ;
F_45 ( V_9 , V_187 ) ;
}
}
void F_121 ( struct V_16 * V_12 )
{
struct V_8 * V_9 ;
unsigned int V_27 ;
for ( V_27 = 0 ; V_27 < V_12 -> V_28 ; ++ V_27 ) {
V_9 = & V_12 -> V_29 [ V_27 ] ;
F_45 ( V_9 , V_188 ) ;
}
}
void F_122 ( struct V_16 * V_12 )
{
unsigned V_27 ;
struct V_8 * V_9 ;
for ( V_27 = 0 ; V_27 < V_12 -> V_28 ; ++ V_27 ) {
V_9 = & V_12 -> V_29 [ V_27 ] ;
F_45 ( V_9 , V_189 ) ;
}
}
void F_123 ( struct V_16 * V_12 )
{
unsigned V_13 ;
struct V_8 * V_9 ;
for ( V_13 = 0 ; V_12 -> V_29 && V_13 < V_12 -> V_28 ;
++ V_13 ) {
V_9 = & V_12 -> V_29 [ V_13 ] ;
if ( ! F_124 ( & V_9 -> V_178 ) )
F_17 ( V_12 , L_14 ,
V_9 -> V_13 ) ;
F_45 ( V_9 , V_190 ) ;
F_125 ( & V_9 -> V_66 ) ;
F_9 ( & V_9 -> V_2 ) ;
}
F_96 ( V_12 , V_12 -> V_28 ) ;
}
static inline void F_126 (
struct V_16 * V_12 ,
struct V_191 * V_192 )
{
switch ( F_127 ( V_192 ) ) {
case V_193 :
F_128 (
& V_12 -> V_146 -> V_147 ,
F_129 ( V_192 ) ,
F_130 ( V_192 ) ,
V_194 ) ;
break;
case V_195 :
F_131 (
& V_12 -> V_146 -> V_147 ,
F_129 ( V_192 ) ,
F_130 ( V_192 ) ,
V_194 ) ;
break;
}
}
static inline T_4 F_132 ( struct V_36 * V_196 )
{
return ( V_196 -> V_192 [ 0 ] . V_197 [ 1 ] & V_198 )
>> V_199 ;
}
void F_34 (
struct V_16 * V_12 ,
struct V_36 * V_196 )
{
T_3 V_27 ;
if ( V_196 -> V_200 ) {
T_4 V_201 = 0 , V_202 = F_132 ( V_196 ) ;
F_126 ( V_12 , & V_196 -> V_192 [ 0 ] ) ;
if ( V_202 > V_203 )
V_201 = V_202 >> 1 ;
for ( V_27 = 1 + V_201 ; V_27 < V_196 -> V_200 ; V_27 ++ )
F_126 ( V_12 , & V_196 -> V_192 [ V_27 ] ) ;
V_196 -> V_200 = 0 ;
}
F_84 ( V_196 -> V_204 ) ;
V_196 -> V_204 = NULL ;
if ( F_78 ( V_196 -> V_205 > F_133 ( V_196 -> V_206 ) ) ) {
V_196 -> V_205 = F_133 ( V_196 -> V_206 ) ;
F_84 ( V_196 -> V_192 ) ;
}
}
static inline T_3 F_134 ( struct V_8 * V_9 )
{
struct V_16 * V_12 = V_9 -> V_12 ;
int V_207 ;
T_3 V_208 ;
#ifdef F_56
F_17 ( V_9 -> V_12 , L_6 ,
V_9 -> V_13 , F_57 ( __FILE__ ) , __LINE__ , V_23 ) ;
#endif
V_209:
V_207 = F_48 ( V_210 ) && F_39 ( V_9 ) &&
( V_12 -> V_31 & V_32 ) ;
V_208 = V_207 ?
( T_3 ) F_135 ( * V_9 -> V_85 ) :
( T_3 ) F_13 ( V_9 , F_22 ( V_211 ) ) ;
if ( F_78 ( F_48 ( V_212 ) ) ) {
T_3 V_30 ;
T_3 V_213 ;
T_3 V_214 ;
int V_215 ;
V_214 = V_9 -> V_65 & V_9 -> V_79 ;
V_213 = F_136 ( V_9 -> V_72 ) & V_9 -> V_79 ;
V_30 = V_9 -> V_154 ;
if ( V_214 < V_213 )
V_215 = ( V_208 >= V_214 ) & ( V_208 <= V_213 ) ;
else if ( V_214 > V_213 )
V_215 = ( ( V_208 >= V_214 ) && ( V_208 < V_30 ) ) ||
( V_208 <= V_213 ) ;
else
V_215 = ( V_208 == V_214 ) ;
if ( F_78 ( ! V_215 ) ) {
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
static void F_61 ( struct V_8 * V_9 , unsigned V_216 )
{
struct V_43 * V_44 , * V_217 ;
struct V_43 * V_218 [ V_219 ] ;
unsigned V_27 , V_220 = 0 , V_221 ;
struct V_36 * V_222 ;
struct V_223 * V_147 = & V_9 -> V_12 -> V_224 ;
#ifdef F_56
F_17 ( V_9 -> V_12 , L_6 , V_9 -> V_13 ,
F_57 ( __FILE__ ) , __LINE__ , V_23 ) ;
F_17 ( V_9 -> V_12 , L_18 , V_216 ) ;
#endif
do {
V_221 = F_137 ( & V_147 -> V_225 ) ;
if ( ! F_124 ( & V_9 -> V_178 ) ) {
F_51 ( & V_147 -> V_225 ) ;
F_27 (
wait,
nw,
&sde->dmawait,
list) {
T_3 V_200 = 0 ;
if ( ! V_44 -> V_226 )
continue;
if ( V_220 == F_133 ( V_218 ) )
break;
if ( ! F_124 ( & V_44 -> V_78 ) ) {
V_222 = F_138 (
& V_44 -> V_78 ,
struct V_36 ,
V_41 ) ;
V_200 = V_222 -> V_200 ;
}
if ( V_200 > V_216 )
break;
V_216 -= V_200 ;
F_28 ( & V_44 -> V_41 ) ;
V_218 [ V_220 ++ ] = V_44 ;
}
F_52 ( & V_147 -> V_225 ) ;
break;
}
} while ( F_139 ( & V_147 -> V_225 , V_221 ) );
for ( V_27 = 0 ; V_27 < V_220 ; V_27 ++ )
V_218 [ V_27 ] -> V_226 ( V_218 [ V_27 ] , V_227 ) ;
}
static void F_64 ( struct V_8 * V_9 , T_2 V_228 )
{
struct V_36 * V_37 = NULL ;
int V_82 = 0 ;
T_3 V_208 , V_214 , V_213 ;
int V_229 = 0 ;
V_208 = F_134 ( V_9 ) ;
V_209:
V_37 = F_58 ( V_9 ) ;
V_214 = V_9 -> V_65 & V_9 -> V_79 ;
F_60 ( V_9 , V_208 , V_214 , V_37 ) ;
while ( V_214 != V_208 ) {
V_214 = ++ V_9 -> V_65 & V_9 -> V_79 ;
if ( V_37 && V_37 -> V_83 == V_214 ) {
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
V_230 ,
V_42 ) ;
if ( V_44 && V_42 )
F_36 ( V_44 ) ;
V_37 = F_58 ( V_9 ) ;
}
F_60 ( V_9 , V_208 , V_214 , V_37 ) ;
V_82 ++ ;
}
if ( ( V_228 & V_9 -> V_173 ) && ! V_229 ) {
V_213 = F_136 ( V_9 -> V_72 ) & V_9 -> V_79 ;
if ( V_213 != V_208 ) {
V_208 = ( T_3 ) F_13 ( V_9 , F_22 ( V_211 ) ) ;
V_229 = 1 ;
goto V_209;
}
}
V_9 -> V_231 = V_228 ;
if ( V_82 )
F_61 ( V_9 , F_62 ( V_9 ) ) ;
}
void F_140 ( struct V_8 * V_9 , T_2 V_228 )
{
F_141 ( V_9 , V_228 ) ;
F_51 ( & V_9 -> V_52 ) ;
F_21 ( V_9 , V_167 ) ;
F_64 ( V_9 , V_228 ) ;
F_52 ( & V_9 -> V_52 ) ;
}
void F_142 ( struct V_8 * V_9 , T_2 V_228 )
{
unsigned long V_31 ;
#ifdef F_56
F_17 ( V_9 -> V_12 , L_19 ,
V_9 -> V_13 ,
( unsigned long long ) V_228 ,
V_3 [ V_9 -> V_2 . V_70 ] ) ;
#endif
F_26 ( & V_9 -> V_69 , V_31 ) ;
F_51 ( & V_9 -> V_52 ) ;
if ( V_228 & V_232 )
F_53 ( V_9 , V_233 ) ;
if ( V_228 & ~ F_22 ( V_234 ) ) {
F_17 ( V_9 -> V_12 ,
L_20 ,
V_9 -> V_13 ,
( unsigned long long ) V_228 ,
V_3 [ V_9 -> V_2 . V_70 ] ) ;
F_143 ( V_9 ) ;
}
F_52 ( & V_9 -> V_52 ) ;
F_30 ( & V_9 -> V_69 , V_31 ) ;
}
static void F_72 ( struct V_8 * V_9 , unsigned V_93 )
{
T_2 V_235 = 0 ;
T_2 V_236 = 0 ;
unsigned long V_31 ;
#ifdef F_56
F_17 ( V_9 -> V_12 , L_21 ,
V_9 -> V_13 ,
( V_93 & V_98 ) ? 1 : 0 ,
( V_93 & V_100 ) ? 1 : 0 ,
( V_93 & V_102 ) ? 1 : 0 ,
( V_93 & V_104 ) ? 1 : 0 ) ;
#endif
if ( V_93 & V_98 )
V_235 |= F_22 ( V_237 ) ;
else
V_236 |= F_22 ( V_237 ) ;
if ( V_93 & V_100 )
V_235 |= F_22 ( V_238 ) ;
else
V_236 |= F_22 ( V_238 ) ;
if ( V_93 & V_102 )
V_235 |= F_22 ( V_239 ) ;
else
V_236 |= F_22 ( V_239 ) ;
F_26 ( & V_9 -> V_175 , V_31 ) ;
V_9 -> V_240 |= V_235 ;
V_9 -> V_240 &= ~ V_236 ;
if ( V_93 & V_104 )
F_11 ( V_9 , F_22 ( V_241 ) ,
V_9 -> V_240 |
F_22 ( V_242 ) ) ;
else
F_11 ( V_9 , F_22 ( V_241 ) , V_9 -> V_240 ) ;
F_30 ( & V_9 -> V_175 , V_31 ) ;
#ifdef F_56
F_144 ( V_9 ) ;
#endif
}
static void F_145 ( struct V_8 * V_9 )
{
#ifdef F_56
F_17 ( V_9 -> V_12 , L_6 ,
V_9 -> V_13 , F_57 ( __FILE__ ) , __LINE__ , V_23 ) ;
#endif
F_11 ( V_9 , F_22 ( V_243 ) ,
( V_9 -> V_154 / 64 ) << F_22 ( V_244 )
) ;
F_11 ( V_9 , F_22 ( V_243 ) ,
( ( V_9 -> V_154 / 64 ) << F_22 ( V_244 ) )
| ( 4ULL << F_22 ( V_245 ) )
) ;
}
static inline void F_146 ( struct V_8 * V_9 , T_3 V_81 )
{
F_147 () ;
F_148 ( V_81 , V_9 -> V_179 ) ;
}
static void F_149 ( struct V_8 * V_9 )
{
T_2 V_19 ;
#ifdef F_56
F_17 ( V_9 -> V_12 , L_6 ,
V_9 -> V_13 , F_57 ( __FILE__ ) , __LINE__ , V_23 ) ;
#endif
F_145 ( V_9 ) ;
F_146 ( V_9 , 0 ) ;
* V_9 -> V_85 = 0 ;
V_19 = F_22 ( V_246 ) <<
F_22 ( V_247 ) ;
F_11 ( V_9 , F_22 ( V_248 ) , V_19 ) ;
}
static void F_150 ( struct V_8 * V_9 )
{
struct V_16 * V_12 = V_9 -> V_12 ;
T_2 V_19 ;
if ( F_78 ( F_48 ( V_249 ) ) )
return;
V_19 = F_151 ( V_12 ) ;
if ( F_48 ( V_250 ) )
F_152 ( V_19 ) ;
else
F_153 ( V_19 ) ;
F_11 ( V_9 , F_22 ( V_251 ) , V_19 ) ;
}
static void F_119 (
struct V_8 * V_9 ,
T_1 V_252 ,
T_6 V_160 )
{
T_4 V_253 , V_254 ;
#ifdef F_56
struct V_16 * V_12 = V_9 -> V_12 ;
F_17 ( V_12 , L_6 ,
V_9 -> V_13 , F_57 ( __FILE__ ) , __LINE__ , V_23 ) ;
#endif
F_11 ( V_9 , F_22 ( V_255 ) , V_9 -> V_155 ) ;
F_145 ( V_9 ) ;
F_146 ( V_9 , 0 ) ;
F_11 ( V_9 , F_22 ( V_256 ) , V_160 ) ;
F_11 ( V_9 , F_22 ( V_35 ) , 0 ) ;
F_11 ( V_9 , F_22 ( V_257 ) , V_9 -> V_152 ) ;
F_11 ( V_9 , F_22 ( V_258 ) ,
( ( T_2 ) V_252 <<
F_22 ( V_259 ) ) |
( ( T_2 ) ( V_252 * V_9 -> V_13 ) <<
F_22 ( V_260 ) ) ) ;
F_11 ( V_9 , F_22 ( V_261 ) , ~ 0ull ) ;
F_150 ( V_9 ) ;
V_254 = V_262 ;
V_253 = V_263 ;
F_11 ( V_9 , F_22 ( V_264 ) ,
( V_254 << V_265 ) |
( V_253 << V_266 ) ) ;
}
void F_144 ( struct V_8 * V_9 )
{
T_2 V_267 ;
unsigned V_27 ;
F_154 ( F_22 ( V_241 ) ) ;
F_154 ( F_22 ( V_58 ) ) ;
F_155 ( F_22 ( V_268 ) ) ;
F_155 ( F_22 ( V_269 ) ) ;
F_154 ( F_22 ( V_270 ) ) ;
F_154 ( F_22 ( V_261 ) ) ;
for ( V_27 = 0 ; V_27 < V_271 ; ++ V_27 ) {
F_156 ( V_272 ) ;
F_156 ( V_273 ) ;
F_156 ( V_274 ) ;
}
F_154 ( F_22 ( V_180 ) ) ;
F_154 ( F_22 ( V_211 ) ) ;
F_154 ( F_22 ( V_275 ) ) ;
F_154 ( F_22 ( V_276 ) ) ;
F_154 ( F_22 ( V_256 ) ) ;
F_154 ( F_22 ( V_35 ) ) ;
F_154 ( F_22 ( V_277 ) ) ;
F_154 ( F_22 ( V_258 ) ) ;
F_155 ( F_22 ( V_278 ) ) ;
F_155 ( F_22 ( V_279 ) ) ;
F_154 ( F_22 ( V_255 ) ) ;
F_154 ( F_22 ( V_243 ) ) ;
F_154 ( F_22 ( V_257 ) ) ;
F_154 ( F_22 ( V_251 ) ) ;
F_154 ( F_22 ( V_280 ) ) ;
F_154 ( F_22 ( V_281 ) ) ;
F_154 ( F_22 ( V_282 ) ) ;
F_154 ( F_22 ( V_283 ) ) ;
F_154 ( F_22 ( V_264 ) ) ;
}
static void F_143 ( struct V_8 * V_9 )
{
struct V_284 * V_153 ;
struct V_284 * V_285 ;
T_2 V_286 [ 2 ] ;
T_2 V_287 ;
T_4 V_288 ;
T_3 V_289 ;
T_3 V_80 , V_81 , V_30 ;
V_80 = V_9 -> V_65 & V_9 -> V_79 ;
V_81 = V_9 -> V_72 & V_9 -> V_79 ;
V_30 = F_62 ( V_9 ) ;
V_153 = V_9 -> V_153 ;
F_17 ( V_9 -> V_12 ,
L_22 ,
V_9 -> V_13 ,
V_80 ,
V_81 ,
V_30 ,
! F_124 ( & V_9 -> V_39 ) ) ;
while ( V_80 != V_81 ) {
char V_31 [ 6 ] = { 'x' , 'x' , 'x' , 'x' , 0 } ;
V_285 = & V_9 -> V_153 [ V_80 ] ;
V_286 [ 0 ] = F_135 ( V_285 -> V_197 [ 0 ] ) ;
V_286 [ 1 ] = F_135 ( V_285 -> V_197 [ 1 ] ) ;
V_31 [ 0 ] = ( V_286 [ 1 ] & V_183 ) ? 'I' : '-' ;
V_31 [ 1 ] = ( V_286 [ 1 ] & V_182 ) ?
'H' : '-' ;
V_31 [ 2 ] = ( V_286 [ 0 ] & V_290 ) ? 'F' : '-' ;
V_31 [ 3 ] = ( V_286 [ 0 ] & V_291 ) ? 'L' : '-' ;
V_287 = ( V_286 [ 0 ] >> V_292 )
& V_293 ;
V_288 = ( V_286 [ 1 ] >> V_294 )
& V_295 ;
V_289 = ( V_286 [ 0 ] >> V_296 )
& V_297 ;
F_17 ( V_9 -> V_12 ,
L_23 ,
V_80 , V_31 , V_287 , V_288 , V_289 ) ;
F_17 ( V_9 -> V_12 ,
L_24 ,
V_286 [ 0 ] , V_286 [ 1 ] ) ;
if ( V_286 [ 0 ] & V_290 )
F_17 ( V_9 -> V_12 ,
L_25 ,
( T_4 ) ( ( V_286 [ 1 ] & V_298 )
>> V_299 ) ,
( T_4 ) ( ( V_286 [ 1 ] & V_198 )
>> V_199 ) ,
( T_4 ) ( ( V_286 [ 1 ] & V_300 )
>> V_301 ) ) ;
V_80 ++ ;
V_80 &= V_9 -> V_79 ;
}
}
void F_157 ( struct V_302 * V_303 , struct V_8 * V_9 )
{
T_3 V_80 , V_81 ;
struct V_284 * V_285 ;
T_2 V_286 [ 2 ] ;
T_2 V_287 ;
T_4 V_288 ;
T_3 V_289 ;
V_80 = V_9 -> V_65 & V_9 -> V_79 ;
V_81 = F_136 ( V_9 -> V_72 ) & V_9 -> V_79 ;
F_158 ( V_303 , V_304 , V_9 -> V_13 ,
V_9 -> V_305 ,
F_1 ( V_9 -> V_2 . V_70 ) ,
( unsigned long long ) F_13 ( V_9 , F_22 ( V_241 ) ) ,
( unsigned long long ) F_13 ( V_9 , F_22 ( V_58 ) ) ,
( unsigned long long ) F_13 ( V_9 ,
F_22 ( V_270 ) ) ,
( unsigned long long ) F_13 ( V_9 , F_22 ( V_180 ) ) ,
V_81 ,
( unsigned long long ) F_13 ( V_9 , F_22 ( V_211 ) ) ,
V_80 ,
( unsigned long long ) F_135 ( * V_9 -> V_85 ) ,
( unsigned long long ) F_13 ( V_9 , F_22 ( V_258 ) ) ,
( unsigned long long ) F_13 ( V_9 , F_22 ( V_243 ) ) ,
( unsigned long long ) F_13 ( V_9 , F_22 ( V_256 ) ) ,
( unsigned long long ) V_9 -> V_231 ,
( unsigned long long ) V_9 -> V_176 ,
V_9 -> V_306 ,
V_9 -> V_78 ,
V_9 -> V_72 ,
V_9 -> V_65 ,
! F_124 ( & V_9 -> V_39 ) ,
V_9 -> V_170 ,
( unsigned long long ) F_13 ( V_9 , V_307 ) ) ;
while ( V_80 != V_81 ) {
char V_31 [ 6 ] = { 'x' , 'x' , 'x' , 'x' , 0 } ;
V_285 = & V_9 -> V_153 [ V_80 ] ;
V_286 [ 0 ] = F_135 ( V_285 -> V_197 [ 0 ] ) ;
V_286 [ 1 ] = F_135 ( V_285 -> V_197 [ 1 ] ) ;
V_31 [ 0 ] = ( V_286 [ 1 ] & V_183 ) ? 'I' : '-' ;
V_31 [ 1 ] = ( V_286 [ 1 ] & V_182 ) ?
'H' : '-' ;
V_31 [ 2 ] = ( V_286 [ 0 ] & V_290 ) ? 'F' : '-' ;
V_31 [ 3 ] = ( V_286 [ 0 ] & V_291 ) ? 'L' : '-' ;
V_287 = ( V_286 [ 0 ] >> V_292 )
& V_293 ;
V_288 = ( V_286 [ 1 ] >> V_294 )
& V_295 ;
V_289 = ( V_286 [ 0 ] >> V_296 )
& V_297 ;
F_158 ( V_303 ,
L_26 ,
V_80 , V_31 , V_287 , V_288 , V_289 ) ;
if ( V_286 [ 0 ] & V_290 )
F_158 ( V_303 , L_27 ,
( T_4 ) ( ( V_286 [ 1 ] & V_298 )
>> V_299 ) ,
( T_4 ) ( ( V_286 [ 1 ] & V_198 )
>> V_199 ) ) ;
V_80 = ( V_80 + 1 ) & V_9 -> V_79 ;
}
}
static inline T_2 F_159 ( struct V_8 * V_9 , T_2 V_308 )
{
T_4 V_309 = ( V_9 -> V_72 >> V_9 -> V_169 ) & 3 ;
V_308 &= ~ V_310 ;
V_308 |= ( ( T_2 ) V_309 & V_295 )
<< V_294 ;
return V_308 ;
}
static inline T_3 F_160 ( struct V_8 * V_9 , struct V_36 * V_196 )
{
int V_27 ;
T_3 V_81 ;
struct V_191 * V_192 = V_196 -> V_192 ;
T_4 V_201 = 0 , V_202 = F_132 ( V_196 ) ;
V_81 = V_9 -> V_72 & V_9 -> V_79 ;
V_9 -> V_153 [ V_81 ] . V_197 [ 0 ] = F_161 ( V_192 -> V_197 [ 0 ] ) ;
V_9 -> V_153 [ V_81 ] . V_197 [ 1 ] = F_161 ( F_159 ( V_9 , V_192 -> V_197 [ 1 ] ) ) ;
F_162 ( V_9 , V_192 -> V_197 [ 0 ] , V_192 -> V_197 [ 1 ] ,
V_81 , & V_9 -> V_153 [ V_81 ] ) ;
V_81 = ++ V_9 -> V_72 & V_9 -> V_79 ;
V_192 ++ ;
if ( V_202 > V_203 )
V_201 = V_202 >> 1 ;
for ( V_27 = 1 ; V_27 < V_196 -> V_200 ; V_27 ++ , V_192 ++ ) {
T_2 V_308 ;
V_9 -> V_153 [ V_81 ] . V_197 [ 0 ] = F_161 ( V_192 -> V_197 [ 0 ] ) ;
if ( V_201 ) {
V_308 = V_192 -> V_197 [ 1 ] ;
V_201 -- ;
} else {
V_308 = F_159 ( V_9 , V_192 -> V_197 [ 1 ] ) ;
}
V_9 -> V_153 [ V_81 ] . V_197 [ 1 ] = F_161 ( V_308 ) ;
F_162 ( V_9 , V_192 -> V_197 [ 0 ] , V_308 ,
V_81 , & V_9 -> V_153 [ V_81 ] ) ;
V_81 = ++ V_9 -> V_72 & V_9 -> V_79 ;
}
V_196 -> V_83 = V_81 ;
#ifdef F_31
V_196 -> V_45 = V_9 -> V_311 ++ ;
F_163 ( V_9 , V_196 -> V_45 ) ;
F_33 ( V_9 -> V_77 [ V_9 -> V_306 & V_9 -> V_79 ] ) ;
#endif
V_9 -> V_77 [ V_9 -> V_306 ++ & V_9 -> V_79 ] = V_196 ;
V_9 -> V_84 -= V_196 -> V_200 ;
return V_81 ;
}
static int F_164 (
struct V_8 * V_9 ,
struct V_43 * V_44 ,
struct V_36 * V_196 )
{
int V_312 ;
V_9 -> V_84 = F_62 ( V_9 ) ;
if ( V_196 -> V_200 <= V_9 -> V_84 )
return - V_313 ;
if ( V_44 && V_44 -> V_314 ) {
unsigned V_221 ;
V_221 = F_165 (
( const V_315 * ) & V_9 -> V_52 . V_316 ) ;
V_312 = V_44 -> V_314 ( V_9 , V_44 , V_196 , V_221 ) ;
if ( V_312 == - V_313 )
V_9 -> V_84 = F_62 ( V_9 ) ;
} else
V_312 = - V_317 ;
return V_312 ;
}
int F_166 ( struct V_8 * V_9 ,
struct V_43 * V_44 ,
struct V_36 * V_196 )
{
int V_312 = 0 ;
T_3 V_81 ;
unsigned long V_31 ;
if ( F_78 ( V_196 -> V_318 ) )
return - V_319 ;
V_196 -> V_44 = V_44 ;
F_26 ( & V_9 -> V_69 , V_31 ) ;
V_209:
if ( F_78 ( ! F_39 ( V_9 ) ) )
goto V_320;
if ( F_78 ( V_196 -> V_200 > V_9 -> V_84 ) )
goto V_321;
V_81 = F_160 ( V_9 , V_196 ) ;
if ( V_44 )
F_167 ( & V_44 -> V_47 ) ;
F_146 ( V_9 , V_81 ) ;
V_322:
F_30 ( & V_9 -> V_69 , V_31 ) ;
return V_312 ;
V_320:
if ( V_44 )
F_167 ( & V_44 -> V_47 ) ;
V_196 -> V_83 = 0 ;
#ifdef F_31
V_196 -> V_45 = V_9 -> V_311 ++ ;
F_163 ( V_9 , V_196 -> V_45 ) ;
#endif
F_168 ( & V_9 -> V_40 ) ;
F_29 ( & V_196 -> V_41 , & V_9 -> V_39 ) ;
F_169 ( & V_9 -> V_40 ) ;
if ( V_44 ) {
V_44 -> V_323 ++ ;
V_44 -> V_108 += V_196 -> V_200 ;
}
F_54 ( & V_9 -> V_51 ) ;
V_312 = - V_324 ;
goto V_322;
V_321:
V_312 = F_164 ( V_9 , V_44 , V_196 ) ;
if ( V_312 == - V_313 ) {
V_312 = 0 ;
goto V_209;
}
V_9 -> V_170 ++ ;
goto V_322;
}
int F_170 ( struct V_8 * V_9 ,
struct V_43 * V_44 ,
struct V_325 * V_326 )
{
struct V_36 * V_196 , * V_327 ;
int V_312 = 0 ;
unsigned long V_31 ;
T_3 V_81 = V_328 ;
int V_108 = 0 ;
F_26 ( & V_9 -> V_69 , V_31 ) ;
V_209:
F_27 (tx, tx_next, tx_list, list) {
V_196 -> V_44 = V_44 ;
if ( F_78 ( ! F_39 ( V_9 ) ) )
goto V_320;
if ( F_78 ( V_196 -> V_200 > V_9 -> V_84 ) )
goto V_321;
if ( F_78 ( V_196 -> V_318 ) ) {
V_312 = - V_319 ;
goto V_329;
}
F_28 ( & V_196 -> V_41 ) ;
V_81 = F_160 ( V_9 , V_196 ) ;
V_108 ++ ;
if ( V_81 != V_328 &&
( V_108 & V_330 ) == 0 ) {
F_146 ( V_9 , V_81 ) ;
V_81 = V_328 ;
}
}
V_329:
if ( V_44 )
F_171 ( V_108 , & V_44 -> V_47 ) ;
if ( V_81 != V_328 )
F_146 ( V_9 , V_81 ) ;
F_30 ( & V_9 -> V_69 , V_31 ) ;
return V_312 ;
V_320:
F_168 ( & V_9 -> V_40 ) ;
F_27 (tx, tx_next, tx_list, list) {
V_196 -> V_44 = V_44 ;
F_28 ( & V_196 -> V_41 ) ;
if ( V_44 )
F_167 ( & V_44 -> V_47 ) ;
V_196 -> V_83 = 0 ;
#ifdef F_31
V_196 -> V_45 = V_9 -> V_311 ++ ;
F_163 ( V_9 , V_196 -> V_45 ) ;
#endif
F_29 ( & V_196 -> V_41 , & V_9 -> V_39 ) ;
if ( V_44 ) {
V_44 -> V_323 ++ ;
V_44 -> V_108 += V_196 -> V_200 ;
}
}
F_169 ( & V_9 -> V_40 ) ;
F_54 ( & V_9 -> V_51 ) ;
V_312 = - V_324 ;
goto V_329;
V_321:
V_312 = F_164 ( V_9 , V_44 , V_196 ) ;
if ( V_312 == - V_313 ) {
V_312 = 0 ;
goto V_209;
}
V_9 -> V_170 ++ ;
goto V_329;
}
static void F_45 ( struct V_8 * V_9 ,
enum V_331 V_332 )
{
unsigned long V_31 ;
F_26 ( & V_9 -> V_69 , V_31 ) ;
F_51 ( & V_9 -> V_52 ) ;
F_53 ( V_9 , V_332 ) ;
if ( V_9 -> V_2 . V_70 == V_71 )
F_61 ( V_9 , F_62 ( V_9 ) ) ;
F_52 ( & V_9 -> V_52 ) ;
F_30 ( & V_9 -> V_69 , V_31 ) ;
}
static void F_53 ( struct V_8 * V_9 ,
enum V_331 V_332 )
{
struct V_4 * V_5 = & V_9 -> V_2 ;
int V_333 = 0 ;
#ifdef F_56
F_17 ( V_9 -> V_12 , L_28 , V_9 -> V_13 ,
V_3 [ V_5 -> V_70 ] ,
V_334 [ V_332 ] ) ;
#endif
switch ( V_5 -> V_70 ) {
case V_177 :
switch ( V_332 ) {
case V_190 :
break;
case V_187 :
V_5 -> V_106 = 1 ;
case V_189 :
F_2 ( & V_9 -> V_2 ) ;
F_70 ( V_9 ,
V_335 ) ;
break;
case V_60 :
break;
case V_76 :
break;
case V_86 :
F_65 ( V_9 ) ;
break;
case V_336 :
break;
case V_233 :
break;
case V_188 :
break;
case V_337 :
break;
case V_338 :
break;
case V_339 :
break;
case V_340 :
break;
case V_73 :
break;
}
break;
case V_335 :
switch ( V_332 ) {
case V_190 :
F_70 ( V_9 , V_177 ) ;
F_65 ( V_9 ) ;
break;
case V_189 :
break;
case V_60 :
F_70 ( V_9 ,
V_341 ) ;
F_68 ( V_9 ) ;
break;
case V_76 :
break;
case V_187 :
V_5 -> V_106 = 1 ;
break;
case V_86 :
break;
case V_336 :
break;
case V_233 :
F_54 ( & V_9 -> V_53 ) ;
break;
case V_188 :
V_5 -> V_106 = 0 ;
break;
case V_337 :
break;
case V_338 :
break;
case V_339 :
break;
case V_340 :
break;
case V_73 :
break;
}
break;
case V_341 :
switch ( V_332 ) {
case V_190 :
F_70 ( V_9 , V_177 ) ;
F_65 ( V_9 ) ;
break;
case V_189 :
break;
case V_60 :
break;
case V_76 :
F_149 ( V_9 ) ;
F_70 ( V_9 , V_5 -> V_106 ?
V_71 :
V_342 ) ;
break;
case V_187 :
V_5 -> V_106 = 1 ;
break;
case V_86 :
break;
case V_336 :
break;
case V_233 :
break;
case V_188 :
V_5 -> V_106 = 0 ;
break;
case V_337 :
break;
case V_338 :
break;
case V_339 :
break;
case V_340 :
break;
case V_73 :
break;
}
break;
case V_342 :
switch ( V_332 ) {
case V_190 :
F_70 ( V_9 , V_177 ) ;
F_65 ( V_9 ) ;
break;
case V_189 :
break;
case V_60 :
break;
case V_76 :
break;
case V_187 :
F_70 ( V_9 , V_71 ) ;
V_5 -> V_106 = 1 ;
break;
case V_86 :
break;
case V_336 :
break;
case V_233 :
F_70 ( V_9 , V_343 ) ;
F_54 ( & V_9 -> V_53 ) ;
break;
case V_188 :
break;
case V_340 :
case V_337 :
F_70 ( V_9 , V_344 ) ;
F_172 ( & V_9 -> V_12 -> V_87 ) ;
F_67 ( & V_9 -> V_12 -> V_88 ) ;
break;
case V_338 :
break;
case V_339 :
break;
case V_73 :
break;
}
break;
case V_345 :
switch ( V_332 ) {
case V_190 :
F_70 ( V_9 , V_177 ) ;
break;
case V_189 :
break;
case V_60 :
break;
case V_76 :
break;
case V_187 :
V_5 -> V_106 = 1 ;
break;
case V_86 :
F_70 ( V_9 , V_346 ) ;
F_68 ( V_9 ) ;
break;
case V_336 :
break;
case V_233 :
break;
case V_188 :
V_5 -> V_106 = 0 ;
break;
case V_337 :
break;
case V_338 :
break;
case V_339 :
break;
case V_340 :
V_5 -> V_106 = 0 ;
break;
case V_73 :
break;
}
break;
case V_346 :
switch ( V_332 ) {
case V_190 :
F_70 ( V_9 , V_177 ) ;
F_69 ( & V_9 -> F_63 ) ;
break;
case V_189 :
break;
case V_60 :
break;
case V_76 :
F_149 ( V_9 ) ;
F_70 ( V_9 , V_5 -> V_106 ?
V_71 :
V_342 ) ;
break;
case V_187 :
V_5 -> V_106 = 1 ;
break;
case V_86 :
break;
case V_336 :
break;
case V_233 :
break;
case V_188 :
V_5 -> V_106 = 0 ;
break;
case V_337 :
break;
case V_338 :
break;
case V_339 :
break;
case V_340 :
V_5 -> V_106 = 0 ;
break;
case V_73 :
break;
}
break;
case V_343 :
switch ( V_332 ) {
case V_190 :
F_70 ( V_9 , V_177 ) ;
F_69 ( & V_9 -> F_63 ) ;
break;
case V_189 :
break;
case V_60 :
F_70 ( V_9 , V_345 ) ;
F_69 ( & V_9 -> F_63 ) ;
break;
case V_76 :
break;
case V_187 :
V_5 -> V_106 = 1 ;
break;
case V_86 :
break;
case V_336 :
break;
case V_233 :
F_54 ( & V_9 -> V_53 ) ;
break;
case V_188 :
V_5 -> V_106 = 0 ;
break;
case V_337 :
break;
case V_338 :
break;
case V_339 :
break;
case V_340 :
V_5 -> V_106 = 0 ;
break;
case V_73 :
break;
}
break;
case V_347 :
switch ( V_332 ) {
case V_190 :
F_70 ( V_9 , V_177 ) ;
F_69 ( & V_9 -> F_63 ) ;
break;
case V_189 :
break;
case V_60 :
F_70 ( V_9 , V_345 ) ;
F_69 ( & V_9 -> F_63 ) ;
break;
case V_76 :
break;
case V_187 :
V_5 -> V_106 = 1 ;
break;
case V_86 :
break;
case V_336 :
break;
case V_233 :
F_54 ( & V_9 -> V_53 ) ;
break;
case V_188 :
V_5 -> V_106 = 0 ;
break;
case V_337 :
break;
case V_338 :
break;
case V_339 :
break;
case V_340 :
break;
case V_73 :
break;
}
break;
case V_344 :
switch ( V_332 ) {
case V_190 :
F_70 ( V_9 , V_177 ) ;
F_69 ( & V_9 -> F_63 ) ;
break;
case V_189 :
break;
case V_60 :
break;
case V_76 :
break;
case V_187 :
V_5 -> V_106 = 1 ;
break;
case V_86 :
break;
case V_336 :
break;
case V_233 :
break;
case V_188 :
V_5 -> V_106 = 0 ;
break;
case V_337 :
break;
case V_338 :
F_70 ( V_9 , V_348 ) ;
F_69 ( & V_9 -> F_63 ) ;
break;
case V_339 :
break;
case V_340 :
break;
case V_73 :
break;
}
break;
case V_348 :
switch ( V_332 ) {
case V_190 :
F_70 ( V_9 , V_177 ) ;
F_69 ( & V_9 -> F_63 ) ;
break;
case V_189 :
break;
case V_60 :
break;
case V_76 :
break;
case V_187 :
V_5 -> V_106 = 1 ;
break;
case V_86 :
F_172 ( & V_9 -> V_12 -> V_87 ) ;
F_67 ( & V_9 -> V_12 -> V_88 ) ;
break;
case V_336 :
break;
case V_233 :
break;
case V_188 :
V_5 -> V_106 = 0 ;
break;
case V_337 :
break;
case V_338 :
break;
case V_339 :
F_149 ( V_9 ) ;
F_70 ( V_9 , V_5 -> V_106 ?
V_71 :
V_342 ) ;
break;
case V_340 :
break;
case V_73 :
break;
}
break;
case V_71 :
switch ( V_332 ) {
case V_190 :
F_70 ( V_9 , V_177 ) ;
F_69 ( & V_9 -> F_63 ) ;
break;
case V_189 :
break;
case V_60 :
break;
case V_76 :
break;
case V_187 :
break;
case V_86 :
break;
case V_336 :
break;
case V_233 :
V_333 = 1 ;
F_46 ( V_9 ) ;
case V_73 :
F_70 ( V_9 , V_343 ) ;
F_54 ( & V_9 -> V_53 ) ;
break;
case V_188 :
F_70 ( V_9 , V_347 ) ;
break;
case V_340 :
V_5 -> V_106 = 0 ;
case V_337 :
F_70 ( V_9 , V_344 ) ;
F_172 ( & V_9 -> V_12 -> V_87 ) ;
F_67 ( & V_9 -> V_12 -> V_88 ) ;
break;
case V_338 :
break;
case V_339 :
break;
}
break;
}
V_5 -> V_349 = V_332 ;
if ( V_333 )
F_64 ( V_9 , 0 ) ;
}
static int F_173 ( struct V_16 * V_12 , struct V_36 * V_196 )
{
int V_27 ;
if ( F_78 ( ( V_196 -> V_200 == ( V_350 - 1 ) ) ) ) {
if ( ! V_196 -> V_318 ) {
V_196 -> V_205 = V_350 ;
} else if ( ! V_196 -> V_204 ) {
V_196 -> V_204 = F_174 ( V_196 -> V_318 + sizeof( T_1 ) ,
V_351 ) ;
if ( ! V_196 -> V_204 )
goto V_352;
V_196 -> V_353 = 0 ;
}
return 0 ;
}
if ( F_78 ( V_196 -> V_200 == V_350 ) )
goto V_352;
V_196 -> V_192 = F_175 (
V_350 ,
sizeof( struct V_191 ) ,
V_351 ) ;
if ( ! V_196 -> V_192 )
goto V_352;
V_196 -> V_205 = V_350 - 1 ;
for ( V_27 = 0 ; V_27 < V_196 -> V_200 ; V_27 ++ )
V_196 -> V_192 [ V_27 ] = V_196 -> V_206 [ V_27 ] ;
return 0 ;
V_352:
F_34 ( V_12 , V_196 ) ;
return - V_143 ;
}
int F_176 ( struct V_16 * V_12 , struct V_36 * V_196 ,
int type , void * V_354 , struct V_355 * V_355 ,
unsigned long V_356 , T_3 V_289 )
{
int V_357 , V_117 ;
T_7 V_287 ;
V_117 = F_173 ( V_12 , V_196 ) ;
if ( V_117 ) {
F_34 ( V_12 , V_196 ) ;
return V_117 ;
}
if ( V_196 -> V_204 ) {
if ( type == V_358 ) {
F_34 ( V_12 , V_196 ) ;
return - V_319 ;
}
if ( type == V_195 ) {
V_354 = F_177 ( V_355 ) ;
V_354 += V_356 ;
} else if ( F_178 ( ! V_354 ) ) {
F_34 ( V_12 , V_196 ) ;
return - V_319 ;
}
memcpy ( V_196 -> V_204 + V_196 -> V_353 , V_354 , V_289 ) ;
V_196 -> V_353 += V_289 ;
if ( type == V_195 )
F_179 ( V_355 ) ;
if ( V_196 -> V_318 - V_196 -> V_353 )
return 0 ;
V_357 = V_196 -> V_359 & ( sizeof( T_1 ) - 1 ) ;
if ( V_357 ) {
V_357 = sizeof( T_1 ) - V_357 ;
memset ( V_196 -> V_204 + V_196 -> V_353 , 0 , V_357 ) ;
V_196 -> V_359 += V_357 ;
V_196 -> V_318 += V_357 ;
}
V_287 = F_180 ( & V_12 -> V_146 -> V_147 ,
V_196 -> V_204 ,
V_196 -> V_318 ,
V_194 ) ;
if ( F_78 ( F_181 ( & V_12 -> V_146 -> V_147 , V_287 ) ) ) {
F_34 ( V_12 , V_196 ) ;
return - V_360 ;
}
V_196 -> V_205 = V_350 ;
return F_182 ( V_12 , V_193 , V_196 ,
V_287 , V_196 -> V_318 ) ;
}
return 1 ;
}
void F_183 ( struct V_16 * V_12 , T_2 V_122 , T_1 V_361 )
{
struct V_8 * V_9 ;
int V_27 ;
T_2 V_362 ;
V_362 = ( ( V_122 & F_22 ( V_363 ) ) <<
F_22 ( V_364 ) ) |
( ( ( V_361 & V_122 ) & F_22 ( V_365 ) ) <<
F_22 ( V_366 ) ) ;
for ( V_27 = 0 ; V_27 < V_12 -> V_28 ; V_27 ++ ) {
F_184 ( V_367 , L_29 ,
V_27 , ( T_1 ) V_362 ) ;
V_9 = & V_12 -> V_29 [ V_27 ] ;
F_11 ( V_9 , F_22 ( V_283 ) , V_362 ) ;
}
}
int F_185 ( struct V_16 * V_12 , struct V_36 * V_196 )
{
int V_117 = 0 ;
V_196 -> V_200 ++ ;
if ( ( F_78 ( V_196 -> V_200 == V_196 -> V_205 ) ) ) {
V_117 = F_173 ( V_12 , V_196 ) ;
if ( V_117 ) {
F_34 ( V_12 , V_196 ) ;
return V_117 ;
}
}
F_186 (
V_196 ,
V_358 ,
V_12 -> V_148 ,
sizeof( T_1 ) - ( V_196 -> V_359 & ( sizeof( T_1 ) - 1 ) ) ) ;
F_187 ( V_12 , V_196 ) ;
return V_117 ;
}
void F_188 (
struct V_36 * V_196 ,
T_4 V_368 ,
T_4 V_369 ,
T_1 * V_370 ,
T_4 V_371 )
{
T_1 V_27 , V_372 = 0 , V_286 = 0 ;
T_4 V_202 ;
F_33 ( V_368 > 9 || ( V_371 & 3 ) || V_371 == 4 ) ;
if ( V_368 == 1 )
V_202 = V_203 ;
else if ( V_368 <= 5 )
V_202 = V_373 ;
else
V_202 = V_374 ;
V_196 -> V_200 ++ ;
switch ( V_202 ) {
case V_374 :
V_196 -> V_200 ++ ;
V_196 -> V_206 [ 2 ] . V_197 [ 0 ] = 0 ;
V_196 -> V_206 [ 2 ] . V_197 [ 1 ] = 0 ;
case V_373 :
V_196 -> V_200 ++ ;
V_196 -> V_206 [ 1 ] . V_197 [ 0 ] = 0 ;
V_196 -> V_206 [ 1 ] . V_197 [ 1 ] = 0 ;
break;
}
V_371 >>= 2 ;
V_196 -> V_206 [ 0 ] . V_197 [ 1 ] |=
( ( ( T_2 ) V_369 & V_375 )
<< V_299 ) |
( ( ( T_2 ) V_371 & V_376 )
<< V_301 ) |
( ( ( T_2 ) V_202 & V_377 )
<< V_199 ) |
( ( ( T_2 ) V_370 [ 0 ] & V_378 )
<< V_379 ) ;
for ( V_27 = 0 ; V_27 < ( V_368 - 1 ) ; V_27 ++ ) {
if ( ! V_372 && ! ( V_27 & 2 ) )
V_286 ++ ;
V_196 -> V_206 [ V_286 ] . V_197 [ ! ! ( V_27 & 2 ) ] |=
( ( ( T_2 ) V_370 [ V_27 + 1 ] )
<< V_372 ) ;
V_372 = ( V_372 + 32 ) & 63 ;
}
}
int F_189 ( struct V_8 * V_9 )
{
int V_380 ;
int V_381 ;
if ( ! V_9 ) {
F_190 ( V_9 , - V_319 ) ;
return - V_319 ;
}
while ( 1 ) {
V_380 = F_191 ( F_136 ( V_9 -> V_176 ) ) ;
if ( V_380 > 31 ) {
F_190 ( V_9 , - V_360 ) ;
return - V_360 ;
}
V_381 = F_192 ( V_380 , & V_9 -> V_176 ) ;
if ( ! V_381 )
break;
F_193 () ;
}
F_190 ( V_9 , V_380 ) ;
return V_380 ;
}
void F_194 ( struct V_8 * V_9 , int V_382 )
{
if ( ! V_9 )
return;
F_195 ( V_9 , V_382 ) ;
if ( V_382 < 0 || V_382 > 31 )
return;
F_196 ( V_382 , & V_9 -> V_176 ) ;
}
void F_197 ( struct V_16 * V_12 , int V_383 )
{
int V_27 ;
enum V_331 V_332 = V_383 ? V_340 :
V_337 ;
F_66 ( & V_12 -> V_87 , V_12 -> V_28 ) ;
for ( V_27 = 0 ; V_27 < V_12 -> V_28 ; V_27 ++ )
F_45 ( & V_12 -> V_29 [ V_27 ] , V_332 ) ;
}
void F_198 ( struct V_16 * V_12 )
{
int V_27 ;
int V_312 ;
V_312 = F_199 ( V_12 -> V_88 ,
F_200 ( & V_12 -> V_87 ) <= 0 ) ;
if ( V_312 || F_200 ( & V_12 -> V_87 ) < 0 )
return;
F_66 ( & V_12 -> V_87 , V_12 -> V_28 ) ;
for ( V_27 = 0 ; V_27 < V_12 -> V_28 ; V_27 ++ )
F_45 ( & V_12 -> V_29 [ V_27 ] , V_338 ) ;
( void ) F_199 ( V_12 -> V_88 ,
F_200 ( & V_12 -> V_87 ) <= 0 ) ;
}
void F_201 ( struct V_16 * V_12 )
{
int V_27 ;
for ( V_27 = 0 ; V_27 < V_12 -> V_28 ; V_27 ++ )
F_45 ( & V_12 -> V_29 [ V_27 ] ,
V_339 ) ;
}
void F_202 (
struct V_8 * V_9 )
{
F_203 ( V_9 , V_9 -> V_174 ) ;
F_204 ( V_9 -> V_12 ,
V_384 + ( 8 * ( V_385 / 64 ) ) , V_9 -> V_174 ) ;
}
