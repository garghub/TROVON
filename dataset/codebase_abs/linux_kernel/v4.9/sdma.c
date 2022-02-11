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
if ( V_40 && F_28 ( V_40 ) )
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
int F_76 ( struct V_8 * V_9 )
{
struct V_16 * V_12 = V_9 -> V_12 ;
struct V_111 * V_112 ;
T_5 V_113 ;
if ( V_9 -> V_13 >= V_114 )
return - V_115 ;
F_77 () ;
V_112 = F_78 ( V_12 -> V_116 ) ;
if ( F_79 ( ! V_112 ) ) {
F_80 () ;
return - V_115 ;
}
V_113 = V_112 -> V_117 [ V_9 -> V_13 ] ;
F_80 () ;
return V_113 ;
}
struct V_8 * F_81 (
struct V_16 * V_12 ,
T_1 V_118 ,
T_5 V_113 )
{
struct V_111 * V_112 ;
struct V_119 * V_120 ;
struct V_8 * V_121 ;
if ( V_113 >= V_122 ) {
V_121 = NULL ;
goto V_123;
}
F_77 () ;
V_112 = F_78 ( V_12 -> V_116 ) ;
if ( F_79 ( ! V_112 ) ) {
F_80 () ;
return & V_12 -> V_29 [ 0 ] ;
}
V_120 = V_112 -> V_124 [ V_113 & V_112 -> V_125 ] ;
V_121 = V_120 -> V_9 [ V_118 & V_120 -> V_125 ] ;
F_80 () ;
V_123:
V_121 = ! V_121 ? & V_12 -> V_29 [ 0 ] : V_121 ;
F_82 ( V_12 , V_118 , V_113 , V_121 -> V_13 ) ;
return V_121 ;
}
struct V_8 * F_83 (
struct V_16 * V_12 ,
T_1 V_118 ,
T_5 V_126 )
{
T_5 V_113 = F_84 ( V_12 , V_126 ) ;
return F_81 ( V_12 , V_118 , V_113 ) ;
}
struct V_8 * F_85 ( struct V_16 * V_12 ,
T_1 V_118 , T_5 V_113 )
{
struct V_127 * V_128 ;
struct V_8 * V_9 = NULL ;
const struct V_129 * V_130 = F_86 ( V_131 ) ;
unsigned long V_132 ;
if ( F_87 ( V_130 ) != 1 )
goto V_133;
V_132 = F_88 () ;
F_77 () ;
V_128 = F_89 ( & V_12 -> V_134 , & V_132 ,
V_135 ) ;
if ( V_128 && V_128 -> V_124 [ V_113 ] ) {
struct V_136 * V_124 = V_128 -> V_124 [ V_113 ] ;
V_9 = V_124 -> V_9 [ V_118 & V_124 -> V_125 ] ;
}
F_80 () ;
if ( V_9 )
return V_9 ;
V_133:
return F_81 ( V_12 , V_118 , V_113 ) ;
}
static void F_90 ( struct V_136 * V_124 )
{
int V_27 ;
for ( V_27 = 0 ; V_27 < F_91 ( V_124 -> V_137 ? : 1 ) - V_124 -> V_137 ; V_27 ++ )
V_124 -> V_9 [ V_124 -> V_137 + V_27 ] = V_124 -> V_9 [ V_27 ] ;
}
static void F_92 ( struct V_136 * V_124 ,
struct V_8 * V_9 )
{
unsigned int V_27 , pow ;
for ( V_27 = 0 ; V_27 < V_124 -> V_137 ; V_27 ++ ) {
if ( V_124 -> V_9 [ V_27 ] == V_9 ) {
memmove ( & V_124 -> V_9 [ V_27 ] , & V_124 -> V_9 [ V_27 + 1 ] ,
( V_124 -> V_137 - V_27 - 1 ) * sizeof( V_124 -> V_9 [ 0 ] ) ) ;
V_124 -> V_137 -- ;
pow = F_91 ( V_124 -> V_137 ? : 1 ) ;
V_124 -> V_125 = pow - 1 ;
F_90 ( V_124 ) ;
break;
}
}
}
T_6 F_93 ( struct V_8 * V_9 , const char * V_138 ,
T_7 V_108 )
{
struct V_16 * V_12 = V_9 -> V_12 ;
T_8 V_125 , V_139 ;
unsigned long V_140 ;
int V_141 , V_113 , V_142 ;
V_113 = F_76 ( V_9 ) ;
if ( F_79 ( V_113 < 0 ) )
return - V_115 ;
V_141 = F_94 ( & V_125 , V_143 ) ;
if ( ! V_141 )
return - V_144 ;
V_141 = F_94 ( & V_139 , V_143 ) ;
if ( ! V_141 ) {
F_95 ( V_125 ) ;
return - V_144 ;
}
V_141 = F_96 ( V_138 , V_125 ) ;
if ( V_141 )
goto V_145;
if ( ! F_97 ( V_125 , V_146 ) ) {
F_98 ( V_9 -> V_12 , L_7 ) ;
V_141 = - V_115 ;
goto V_145;
}
V_142 = sizeof( struct V_136 ) +
( V_114 * sizeof( struct V_8 * ) ) ;
F_99 ( & V_147 ) ;
F_100 (cpu, mask) {
struct V_127 * V_128 ;
if ( F_101 ( V_140 , & V_9 -> V_148 ) ) {
F_102 ( V_140 , V_139 ) ;
continue;
}
V_128 = F_89 ( & V_12 -> V_134 , & V_140 ,
V_135 ) ;
if ( ! V_128 ) {
V_128 = F_103 ( sizeof( * V_128 ) , V_143 ) ;
if ( ! V_128 ) {
V_141 = - V_144 ;
goto V_133;
}
V_128 -> V_124 [ V_113 ] = F_103 ( V_142 , V_143 ) ;
if ( ! V_128 -> V_124 [ V_113 ] ) {
F_104 ( V_128 ) ;
V_141 = - V_144 ;
goto V_133;
}
V_128 -> V_132 = V_140 ;
V_128 -> V_124 [ V_113 ] -> V_125 = 0 ;
V_128 -> V_124 [ V_113 ] -> V_137 = 1 ;
V_128 -> V_124 [ V_113 ] -> V_9 [ 0 ] = V_9 ;
V_141 = F_105 ( & V_12 -> V_134 ,
& V_128 -> V_149 ,
V_135 ) ;
if ( V_141 ) {
F_104 ( V_128 -> V_124 [ V_113 ] ) ;
F_104 ( V_128 ) ;
F_17 ( V_9 -> V_12 , L_8 ,
V_140 ) ;
goto V_133;
}
} else {
int V_137 , pow ;
if ( ! V_128 -> V_124 [ V_113 ] )
V_128 -> V_124 [ V_113 ] = F_103 ( V_142 , V_143 ) ;
if ( ! V_128 -> V_124 [ V_113 ] ) {
V_141 = - V_144 ;
goto V_133;
}
V_128 -> V_124 [ V_113 ] -> V_137 ++ ;
V_137 = V_128 -> V_124 [ V_113 ] -> V_137 ;
V_128 -> V_124 [ V_113 ] -> V_9 [ V_137 - 1 ] = V_9 ;
pow = F_91 ( V_137 ) ;
V_128 -> V_124 [ V_113 ] -> V_125 = pow - 1 ;
F_90 ( V_128 -> V_124 [ V_113 ] ) ;
}
F_102 ( V_140 , V_139 ) ;
}
F_100 (cpu, cpu_online_mask) {
struct V_127 * V_128 ;
if ( F_101 ( V_140 , V_125 ) )
continue;
V_128 = F_89 ( & V_12 -> V_134 , & V_140 ,
V_135 ) ;
if ( V_128 ) {
bool V_150 = true ;
int V_27 ;
for ( V_27 = 0 ; V_27 < V_151 ; V_27 ++ )
if ( V_128 -> V_124 [ V_27 ] )
F_92 ( V_128 -> V_124 [ V_27 ] ,
V_9 ) ;
for ( V_27 = 0 ; V_27 < V_151 ; V_27 ++ ) {
if ( ! V_128 -> V_124 [ V_27 ] )
continue;
if ( V_128 -> V_124 [ V_27 ] -> V_137 ) {
V_150 = false ;
break;
}
}
if ( V_150 ) {
V_141 = F_106 ( & V_12 -> V_134 ,
& V_128 -> V_149 ,
V_135 ) ;
F_107 ( V_141 ) ;
for ( V_27 = 0 ; V_27 < V_151 ; V_27 ++ )
F_104 ( V_128 -> V_124 [ V_27 ] ) ;
F_104 ( V_128 ) ;
}
}
}
F_108 ( & V_9 -> V_148 , V_139 ) ;
V_133:
F_109 ( & V_147 ) ;
V_145:
F_95 ( V_125 ) ;
F_95 ( V_139 ) ;
return V_141 ? : F_110 ( V_138 , V_152 ) ;
}
T_6 F_111 ( struct V_8 * V_9 , char * V_138 )
{
F_99 ( & V_147 ) ;
if ( F_112 ( & V_9 -> V_148 ) )
snprintf ( V_138 , V_152 , L_9 , L_10 ) ;
else
F_113 ( true , V_138 , & V_9 -> V_148 ) ;
F_109 ( & V_147 ) ;
return F_110 ( V_138 , V_152 ) ;
}
static void F_114 ( void * V_153 , void * V_154 )
{
struct V_127 * V_128 = V_153 ;
int V_27 ;
for ( V_27 = 0 ; V_27 < V_151 ; V_27 ++ )
F_104 ( V_128 -> V_124 [ V_27 ] ) ;
F_104 ( V_128 ) ;
}
void F_115 ( struct V_155 * V_156 ,
struct V_16 * V_12 ,
unsigned long V_157 )
{
struct V_127 * V_128 ;
int V_27 , V_158 ;
V_128 = F_89 ( & V_12 -> V_134 , & V_157 ,
V_135 ) ;
if ( ! V_128 )
return;
F_116 ( V_156 , L_11 , V_157 ) ;
for ( V_27 = 0 ; V_27 < V_151 ; V_27 ++ ) {
if ( ! V_128 -> V_124 [ V_27 ] || ! V_128 -> V_124 [ V_27 ] -> V_137 )
continue;
F_116 ( V_156 , L_12 , V_27 ) ;
for ( V_158 = 0 ; V_158 < V_128 -> V_124 [ V_27 ] -> V_137 ; V_158 ++ ) {
if ( ! V_128 -> V_124 [ V_27 ] -> V_9 [ V_158 ] )
continue;
if ( V_158 > 0 )
F_117 ( V_156 , L_13 ) ;
F_116 ( V_156 , L_14 ,
V_128 -> V_124 [ V_27 ] -> V_9 [ V_158 ] -> V_13 ) ;
}
F_117 ( V_156 , L_15 ) ;
}
F_117 ( V_156 , L_16 ) ;
}
static void F_118 ( struct V_111 * V_112 )
{
int V_27 ;
for ( V_27 = 0 ; V_112 && V_27 < V_112 -> V_159 ; V_27 ++ )
F_104 ( V_112 -> V_124 [ V_27 ] ) ;
F_104 ( V_112 ) ;
}
static void F_119 ( struct V_160 * V_47 )
{
struct V_111 * V_112 = F_5 ( V_47 , struct V_111 , V_47 ) ;
F_118 ( V_112 ) ;
}
int F_120 ( struct V_16 * V_12 , T_5 V_161 , T_5 V_122 , T_5 * V_162 )
{
int V_27 , V_158 ;
int V_163 , V_164 ;
int V_165 = 0 ;
T_5 V_166 [ V_167 ] ;
struct V_111 * V_168 , * V_169 ;
if ( ! ( V_12 -> V_31 & V_170 ) )
return 0 ;
if ( ! V_162 ) {
V_164 = V_12 -> V_28 / V_122 ;
V_163 = V_12 -> V_28 % V_122 ;
V_162 = V_166 ;
for ( V_27 = V_122 - 1 ; V_27 >= 0 ; V_27 -- , V_163 -- )
V_162 [ V_27 ] = V_164 + ( V_163 > 0 ? 1 : 0 ) ;
}
V_169 = F_103 (
sizeof( struct V_111 ) +
F_91 ( V_122 ) *
sizeof( struct V_119 * ) ,
V_143 ) ;
if ( ! V_169 )
goto V_171;
V_169 -> V_159 = V_122 ;
V_169 -> V_172 = F_91 ( V_122 ) ;
V_169 -> V_125 = ( 1 << F_121 ( V_169 -> V_172 ) ) - 1 ;
for ( V_27 = 0 ; V_27 < V_114 ; V_27 ++ )
V_169 -> V_117 [ V_27 ] = - 1 ;
for ( V_27 = 0 ; V_27 < V_169 -> V_172 ; V_27 ++ ) {
int V_173 = V_165 ;
if ( V_27 < V_169 -> V_159 ) {
int V_142 = F_91 ( V_162 [ V_27 ] ) ;
V_169 -> V_124 [ V_27 ] = F_103 (
sizeof( struct V_119 ) +
V_142 * sizeof( struct V_8 * ) ,
V_143 ) ;
if ( ! V_169 -> V_124 [ V_27 ] )
goto V_171;
V_169 -> V_124 [ V_27 ] -> V_125 = ( 1 << F_121 ( V_142 ) ) - 1 ;
for ( V_158 = 0 ; V_158 < V_142 ; V_158 ++ ) {
V_169 -> V_124 [ V_27 ] -> V_9 [ V_158 ] =
& V_12 -> V_29 [ V_165 ] ;
if ( ++ V_165 >= V_173 + V_162 [ V_27 ] )
V_165 = V_173 ;
}
for ( V_158 = 0 ; V_158 < V_162 [ V_27 ] ; V_158 ++ )
V_169 -> V_117 [ V_173 + V_158 ] = V_27 ;
} else {
V_169 -> V_124 [ V_27 ] = V_169 -> V_124 [ V_27 % V_122 ] ;
}
V_165 = V_173 + V_162 [ V_27 ] ;
}
F_122 ( & V_12 -> V_174 ) ;
V_168 = F_123 ( V_12 -> V_116 ,
F_124 ( & V_12 -> V_174 ) ) ;
F_125 ( V_12 -> V_116 , V_169 ) ;
F_126 ( & V_12 -> V_174 ) ;
if ( V_168 )
F_127 ( & V_168 -> V_47 , F_119 ) ;
return 0 ;
V_171:
F_118 ( V_169 ) ;
return - V_144 ;
}
static void F_128 ( struct V_16 * V_12 , T_7 V_175 )
{
T_7 V_27 ;
struct V_8 * V_9 ;
if ( V_12 -> V_176 ) {
F_129 ( & V_12 -> V_177 -> V_178 , 4 ,
( void * ) V_12 -> V_176 ,
V_12 -> V_179 ) ;
V_12 -> V_176 = NULL ;
V_12 -> V_179 = 0 ;
}
if ( V_12 -> V_180 ) {
F_129 ( & V_12 -> V_177 -> V_178 , V_12 -> V_181 ,
( void * ) V_12 -> V_180 ,
V_12 -> V_182 ) ;
V_12 -> V_180 = NULL ;
V_12 -> V_182 = 0 ;
}
for ( V_27 = 0 ; V_12 -> V_29 && V_27 < V_175 ; ++ V_27 ) {
V_9 = & V_12 -> V_29 [ V_27 ] ;
V_9 -> V_85 = NULL ;
V_9 -> V_183 = 0 ;
if ( V_9 -> V_184 ) {
F_129 (
& V_12 -> V_177 -> V_178 ,
V_9 -> V_185 * sizeof( T_2 [ 2 ] ) ,
V_9 -> V_184 ,
V_9 -> V_186
) ;
V_9 -> V_184 = NULL ;
V_9 -> V_186 = 0 ;
}
F_130 ( V_9 -> V_77 ) ;
V_9 -> V_77 = NULL ;
}
F_122 ( & V_12 -> V_174 ) ;
F_118 ( F_131 ( V_12 -> V_116 ) ) ;
F_132 ( V_12 -> V_116 , NULL ) ;
F_126 ( & V_12 -> V_174 ) ;
F_133 () ;
F_104 ( V_12 -> V_29 ) ;
V_12 -> V_29 = NULL ;
}
int F_134 ( struct V_16 * V_12 , T_5 V_161 )
{
unsigned V_13 ;
struct V_8 * V_9 ;
T_4 V_185 ;
void * V_187 ;
struct V_188 * V_189 = V_12 -> V_24 + V_161 ;
T_1 V_190 ;
T_9 V_191 = V_192 ;
T_7 V_175 = V_12 -> V_193 ;
if ( ! F_49 ( V_194 ) ) {
F_135 ( V_61 ) ;
return 0 ;
}
if ( V_195 &&
V_195 <= V_12 -> V_193 &&
V_195 >= V_122 )
V_175 = V_195 ;
F_136 ( V_12 , L_17 , V_195 ) ;
F_136 ( V_12 , L_18 , V_12 -> V_193 ) ;
F_136 ( V_12 , L_19 ,
V_12 -> V_196 ) ;
V_190 =
V_12 -> V_196 / ( V_175 * V_197 ) ;
F_137 ( & V_12 -> V_88 ) ;
F_67 ( & V_12 -> V_87 , 0 ) ;
V_185 = F_74 () ;
F_136 ( V_12 , L_20 ,
V_175 , V_185 ) ;
V_12 -> V_29 = F_138 ( V_175 , sizeof( * V_12 -> V_29 ) , V_143 ) ;
if ( ! V_12 -> V_29 )
return - V_144 ;
V_191 = F_139 ( V_12 , V_191 ) ;
if ( ! V_198 )
V_198 = V_199 ;
for ( V_13 = 0 ; V_13 < V_175 ; ++ V_13 ) {
V_9 = & V_12 -> V_29 [ V_13 ] ;
V_9 -> V_12 = V_12 ;
V_9 -> V_189 = V_189 ;
V_9 -> V_13 = V_13 ;
V_9 -> V_185 = V_185 ;
V_9 -> V_84 = F_63 ( V_9 ) ;
V_9 -> V_200 = F_121 ( V_185 ) ;
V_9 -> V_79 = ( 1 << V_9 -> V_200 ) - 1 ;
V_9 -> V_201 = ( T_2 ) 1 << ( 0 * V_114 +
V_13 ) ;
V_9 -> V_202 = ( T_2 ) 1 << ( 1 * V_114 +
V_13 ) ;
V_9 -> V_203 = ( T_2 ) 1 << ( 2 * V_114 +
V_13 ) ;
V_9 -> V_204 = V_9 -> V_201 | V_9 -> V_202 |
V_9 -> V_203 ;
F_140 ( & V_9 -> V_69 ) ;
F_141 ( & V_9 -> V_52 ) ;
F_140 ( & V_9 -> V_205 ) ;
F_140 ( & V_9 -> V_46 ) ;
V_9 -> V_206 = 0xfffffffe00000000ULL ;
F_71 ( V_9 , V_207 ) ;
F_142 ( & V_9 -> V_2 . V_6 ) ;
F_143 ( & V_9 -> V_2 . V_7 ) ;
F_144 ( & V_9 -> V_45 ) ;
F_144 ( & V_9 -> V_208 ) ;
V_9 -> V_209 =
F_145 ( V_12 , V_13 , F_22 ( V_210 ) ) ;
if ( V_191 )
V_12 -> V_211 =
V_212 ;
else
V_12 -> V_211 =
V_213 ;
F_146 ( & V_9 -> F_56 , F_56 ,
( unsigned long ) V_9 ) ;
F_146 ( & V_9 -> F_64 , F_64 ,
( unsigned long ) V_9 ) ;
F_147 ( & V_9 -> V_53 , F_42 ) ;
F_147 ( & V_9 -> V_51 , F_38 ) ;
V_9 -> V_64 = 0 ;
F_148 ( & V_9 -> V_66 ,
F_51 , ( unsigned long ) V_9 ) ;
V_9 -> V_184 = F_149 (
& V_12 -> V_177 -> V_178 ,
V_185 * sizeof( T_2 [ 2 ] ) ,
& V_9 -> V_186 ,
V_143
) ;
if ( ! V_9 -> V_184 )
goto V_171;
V_9 -> V_77 =
F_138 ( V_185 , sizeof( struct V_36 * ) ,
V_143 ) ;
if ( ! V_9 -> V_77 )
V_9 -> V_77 =
F_150 (
sizeof( struct V_36 * ) *
V_185 ) ;
if ( ! V_9 -> V_77 )
goto V_171;
}
V_12 -> V_181 = V_214 * V_175 ;
V_12 -> V_180 = F_149 (
& V_12 -> V_177 -> V_178 ,
V_12 -> V_181 ,
& V_12 -> V_182 ,
V_143
) ;
if ( ! V_12 -> V_180 ) {
F_17 ( V_12 , L_21 ) ;
goto V_171;
}
V_12 -> V_176 = F_149 (
& V_12 -> V_177 -> V_178 ,
sizeof( T_1 ) ,
& V_12 -> V_179 ,
V_143
) ;
if ( ! V_12 -> V_176 ) {
F_17 ( V_12 , L_22 ) ;
goto V_171;
}
V_187 = ( void * ) V_12 -> V_180 ;
for ( V_13 = 0 ; V_13 < V_175 ; ++ V_13 ) {
unsigned long V_215 ;
V_9 = & V_12 -> V_29 [ V_13 ] ;
V_9 -> V_85 = V_187 ;
V_187 += V_214 ;
V_215 = ( unsigned long ) V_9 -> V_85 -
( unsigned long ) V_12 -> V_180 ;
V_9 -> V_183 = V_12 -> V_182 + V_215 ;
F_151 ( V_9 , V_190 , V_191 ) ;
}
V_12 -> V_31 |= V_170 ;
V_12 -> V_31 |= V_191 ? V_32 : 0 ;
V_12 -> V_28 = V_175 ;
if ( F_120 ( V_12 , V_161 , V_189 -> V_216 , NULL ) )
goto V_171;
if ( F_152 ( & V_12 -> V_134 , & V_135 ) )
goto V_171;
F_136 ( V_12 , L_23 , V_12 -> V_28 ) ;
return 0 ;
V_171:
F_128 ( V_12 , V_175 ) ;
return - V_144 ;
}
void F_153 ( struct V_16 * V_12 )
{
struct V_8 * V_9 ;
unsigned int V_27 ;
for ( V_27 = 0 ; V_27 < V_12 -> V_28 ; ++ V_27 ) {
V_9 = & V_12 -> V_29 [ V_27 ] ;
F_46 ( V_9 , V_217 ) ;
}
}
void F_154 ( struct V_16 * V_12 )
{
struct V_8 * V_9 ;
unsigned int V_27 ;
for ( V_27 = 0 ; V_27 < V_12 -> V_28 ; ++ V_27 ) {
V_9 = & V_12 -> V_29 [ V_27 ] ;
F_46 ( V_9 , V_218 ) ;
}
}
void F_155 ( struct V_16 * V_12 )
{
unsigned V_27 ;
struct V_8 * V_9 ;
for ( V_27 = 0 ; V_27 < V_12 -> V_28 ; ++ V_27 ) {
V_9 = & V_12 -> V_29 [ V_27 ] ;
F_46 ( V_9 , V_219 ) ;
}
}
void F_156 ( struct V_16 * V_12 )
{
unsigned V_13 ;
struct V_8 * V_9 ;
for ( V_13 = 0 ; V_12 -> V_29 && V_13 < V_12 -> V_28 ;
++ V_13 ) {
V_9 = & V_12 -> V_29 [ V_13 ] ;
if ( ! F_157 ( & V_9 -> V_208 ) )
F_17 ( V_12 , L_24 ,
V_9 -> V_13 ) ;
F_46 ( V_9 , V_220 ) ;
F_158 ( & V_9 -> V_66 ) ;
F_9 ( & V_9 -> V_2 ) ;
}
F_128 ( V_12 , V_12 -> V_28 ) ;
F_159 ( & V_12 -> V_134 , F_114 , NULL ) ;
}
static inline void F_160 (
struct V_16 * V_12 ,
struct V_221 * V_222 )
{
switch ( F_161 ( V_222 ) ) {
case V_223 :
F_162 (
& V_12 -> V_177 -> V_178 ,
F_163 ( V_222 ) ,
F_164 ( V_222 ) ,
V_224 ) ;
break;
case V_225 :
F_165 (
& V_12 -> V_177 -> V_178 ,
F_163 ( V_222 ) ,
F_164 ( V_222 ) ,
V_224 ) ;
break;
}
}
static inline T_5 F_166 ( struct V_36 * V_37 )
{
return ( V_37 -> V_222 [ 0 ] . V_226 [ 1 ] & V_227 )
>> V_228 ;
}
void F_27 (
struct V_16 * V_12 ,
struct V_36 * V_37 )
{
T_4 V_27 ;
if ( V_37 -> V_229 ) {
T_5 V_230 = 0 , V_231 = F_166 ( V_37 ) ;
F_160 ( V_12 , & V_37 -> V_222 [ 0 ] ) ;
if ( V_231 > V_232 )
V_230 = V_231 >> 1 ;
for ( V_27 = 1 + V_230 ; V_27 < V_37 -> V_229 ; V_27 ++ )
F_160 ( V_12 , & V_37 -> V_222 [ V_27 ] ) ;
V_37 -> V_229 = 0 ;
}
F_104 ( V_37 -> V_233 ) ;
V_37 -> V_233 = NULL ;
if ( F_79 ( V_37 -> V_234 > F_167 ( V_37 -> V_235 ) ) ) {
V_37 -> V_234 = F_167 ( V_37 -> V_235 ) ;
F_104 ( V_37 -> V_222 ) ;
}
}
static inline T_4 F_168 ( struct V_8 * V_9 )
{
struct V_16 * V_12 = V_9 -> V_12 ;
int V_236 ;
T_4 V_237 ;
#ifdef F_57
F_17 ( V_9 -> V_12 , L_6 ,
V_9 -> V_13 , F_58 ( __FILE__ ) , __LINE__ , V_23 ) ;
#endif
V_238:
V_236 = F_49 ( V_239 ) && F_40 ( V_9 ) &&
( V_12 -> V_31 & V_32 ) ;
V_237 = V_236 ?
( T_4 ) F_169 ( * V_9 -> V_85 ) :
( T_4 ) F_13 ( V_9 , F_22 ( V_240 ) ) ;
if ( F_79 ( F_49 ( V_241 ) ) ) {
T_4 V_30 ;
T_4 V_242 ;
T_4 V_243 ;
int V_244 ;
V_243 = V_9 -> V_65 & V_9 -> V_79 ;
V_242 = F_170 ( V_9 -> V_72 ) & V_9 -> V_79 ;
V_30 = V_9 -> V_185 ;
if ( V_243 < V_242 )
V_244 = ( V_237 >= V_243 ) & ( V_237 <= V_242 ) ;
else if ( V_243 > V_242 )
V_244 = ( ( V_237 >= V_243 ) && ( V_237 < V_30 ) ) ||
( V_237 <= V_242 ) ;
else
V_244 = ( V_237 == V_243 ) ;
if ( F_79 ( ! V_244 ) ) {
F_17 ( V_12 , L_25 ,
V_9 -> V_13 ,
V_236 ? L_26 : L_27 ,
V_237 , V_243 , V_242 , V_30 ) ;
if ( V_236 ) {
V_236 = 0 ;
goto V_238;
}
V_237 = V_243 ;
}
}
return V_237 ;
}
static void F_62 ( struct V_8 * V_9 , unsigned V_245 )
{
struct V_39 * V_40 , * V_246 ;
struct V_39 * V_247 [ V_248 ] ;
unsigned V_27 , V_249 = 0 , V_250 ;
struct V_36 * V_251 ;
struct V_252 * V_178 = & V_9 -> V_12 -> V_253 ;
#ifdef F_57
F_17 ( V_9 -> V_12 , L_6 , V_9 -> V_13 ,
F_58 ( __FILE__ ) , __LINE__ , V_23 ) ;
F_17 ( V_9 -> V_12 , L_28 , V_245 ) ;
#endif
do {
V_250 = F_171 ( & V_178 -> V_254 ) ;
if ( ! F_157 ( & V_9 -> V_208 ) ) {
F_52 ( & V_178 -> V_254 ) ;
F_34 (
wait,
nw,
&sde->dmawait,
list) {
T_4 V_229 = 0 ;
if ( ! V_40 -> V_255 )
continue;
if ( V_249 == F_167 ( V_247 ) )
break;
if ( ! F_157 ( & V_40 -> V_78 ) ) {
V_251 = F_172 (
& V_40 -> V_78 ,
struct V_36 ,
V_47 ) ;
V_229 = V_251 -> V_229 ;
}
if ( V_229 > V_245 )
break;
V_245 -= V_229 ;
F_35 ( & V_40 -> V_47 ) ;
V_247 [ V_249 ++ ] = V_40 ;
}
F_53 ( & V_178 -> V_254 ) ;
break;
}
} while ( F_173 ( & V_178 -> V_254 , V_250 ) );
for ( V_27 = 0 ; V_27 < V_249 ; V_27 ++ )
V_247 [ V_27 ] -> V_255 ( V_247 [ V_27 ] , V_256 ) ;
}
static void F_65 ( struct V_8 * V_9 , T_2 V_257 )
{
struct V_36 * V_43 = NULL ;
int V_82 = 0 ;
T_4 V_237 , V_243 ;
int V_258 = 0 ;
V_237 = F_168 ( V_9 ) ;
V_238:
V_43 = F_59 ( V_9 ) ;
V_243 = V_9 -> V_65 & V_9 -> V_79 ;
F_61 ( V_9 , V_237 , V_243 , V_43 ) ;
while ( V_243 != V_237 ) {
V_243 = ++ V_9 -> V_65 & V_9 -> V_79 ;
if ( V_43 && V_43 -> V_83 == V_243 ) {
V_9 -> V_77 [ V_9 -> V_78 ++ & V_9 -> V_79 ] = NULL ;
F_23 ( V_9 , V_43 , V_259 ) ;
V_43 = F_59 ( V_9 ) ;
}
F_61 ( V_9 , V_237 , V_243 , V_43 ) ;
V_82 ++ ;
}
if ( ( V_257 & V_9 -> V_203 ) && ! V_258 ) {
T_4 V_242 ;
V_242 = F_170 ( V_9 -> V_72 ) & V_9 -> V_79 ;
if ( V_242 != V_237 ) {
V_237 = ( T_4 ) F_13 ( V_9 , F_22 ( V_240 ) ) ;
V_258 = 1 ;
goto V_238;
}
}
V_9 -> V_260 = V_257 ;
if ( V_82 )
F_62 ( V_9 , F_63 ( V_9 ) ) ;
}
void F_174 ( struct V_8 * V_9 , T_2 V_257 )
{
F_175 ( V_9 , V_257 ) ;
F_52 ( & V_9 -> V_52 ) ;
F_21 ( V_9 , V_198 ) ;
if ( V_257 & V_9 -> V_203 )
V_9 -> V_261 ++ ;
else if ( V_257 & V_9 -> V_202 )
V_9 -> V_262 ++ ;
else if ( V_257 & V_9 -> V_201 )
V_9 -> V_263 ++ ;
F_65 ( V_9 , V_257 ) ;
F_53 ( & V_9 -> V_52 ) ;
}
void F_176 ( struct V_8 * V_9 , T_2 V_257 )
{
unsigned long V_31 ;
#ifdef F_57
F_17 ( V_9 -> V_12 , L_29 ,
V_9 -> V_13 ,
( unsigned long long ) V_257 ,
V_3 [ V_9 -> V_2 . V_70 ] ) ;
#endif
F_33 ( & V_9 -> V_69 , V_31 ) ;
F_52 ( & V_9 -> V_52 ) ;
if ( V_257 & V_264 )
F_54 ( V_9 , V_265 ) ;
if ( V_257 & ~ F_22 ( V_266 ) ) {
F_17 ( V_9 -> V_12 ,
L_30 ,
V_9 -> V_13 ,
( unsigned long long ) V_257 ,
V_3 [ V_9 -> V_2 . V_70 ] ) ;
F_177 ( V_9 ) ;
}
F_53 ( & V_9 -> V_52 ) ;
F_37 ( & V_9 -> V_69 , V_31 ) ;
}
static void F_73 ( struct V_8 * V_9 , unsigned V_93 )
{
T_2 V_267 = 0 ;
T_2 V_268 = 0 ;
unsigned long V_31 ;
#ifdef F_57
F_17 ( V_9 -> V_12 , L_31 ,
V_9 -> V_13 ,
( V_93 & V_98 ) ? 1 : 0 ,
( V_93 & V_100 ) ? 1 : 0 ,
( V_93 & V_102 ) ? 1 : 0 ,
( V_93 & V_104 ) ? 1 : 0 ) ;
#endif
if ( V_93 & V_98 )
V_267 |= F_22 ( V_269 ) ;
else
V_268 |= F_22 ( V_269 ) ;
if ( V_93 & V_100 )
V_267 |= F_22 ( V_270 ) ;
else
V_268 |= F_22 ( V_270 ) ;
if ( V_93 & V_102 )
V_267 |= F_22 ( V_271 ) ;
else
V_268 |= F_22 ( V_271 ) ;
F_33 ( & V_9 -> V_205 , V_31 ) ;
V_9 -> V_272 |= V_267 ;
V_9 -> V_272 &= ~ V_268 ;
if ( V_93 & V_104 )
F_11 ( V_9 , F_22 ( V_273 ) ,
V_9 -> V_272 |
F_22 ( V_274 ) ) ;
else
F_11 ( V_9 , F_22 ( V_273 ) , V_9 -> V_272 ) ;
F_37 ( & V_9 -> V_205 , V_31 ) ;
#ifdef F_57
F_178 ( V_9 ) ;
#endif
}
static void F_179 ( struct V_8 * V_9 )
{
#ifdef F_57
F_17 ( V_9 -> V_12 , L_6 ,
V_9 -> V_13 , F_58 ( __FILE__ ) , __LINE__ , V_23 ) ;
#endif
F_11 ( V_9 , F_22 ( V_275 ) ,
( V_9 -> V_185 / 64 ) << F_22 ( V_276 ) ) ;
F_11 ( V_9 , F_22 ( V_275 ) ,
( ( V_9 -> V_185 / 64 ) << F_22 ( V_276 ) ) |
( 4ULL << F_22 ( V_277 ) ) ) ;
}
static inline void F_180 ( struct V_8 * V_9 , T_4 V_81 )
{
F_181 () ;
F_182 ( V_81 , V_9 -> V_209 ) ;
}
static void F_183 ( struct V_8 * V_9 )
{
T_2 V_19 ;
#ifdef F_57
F_17 ( V_9 -> V_12 , L_6 ,
V_9 -> V_13 , F_58 ( __FILE__ ) , __LINE__ , V_23 ) ;
#endif
F_179 ( V_9 ) ;
F_180 ( V_9 , 0 ) ;
* V_9 -> V_85 = 0 ;
V_19 = F_22 ( V_278 ) <<
F_22 ( V_279 ) ;
F_11 ( V_9 , F_22 ( V_280 ) , V_19 ) ;
}
static void F_184 ( struct V_8 * V_9 )
{
struct V_16 * V_12 = V_9 -> V_12 ;
F_11 ( V_9 , F_22 ( V_281 ) ,
F_185 ( V_12 ) ) ;
}
static void F_151 (
struct V_8 * V_9 ,
T_1 V_282 ,
T_9 V_191 )
{
T_5 V_283 , V_284 ;
#ifdef F_57
struct V_16 * V_12 = V_9 -> V_12 ;
F_17 ( V_12 , L_6 ,
V_9 -> V_13 , F_58 ( __FILE__ ) , __LINE__ , V_23 ) ;
#endif
F_11 ( V_9 , F_22 ( V_285 ) , V_9 -> V_186 ) ;
F_179 ( V_9 ) ;
F_180 ( V_9 , 0 ) ;
F_11 ( V_9 , F_22 ( V_286 ) , V_191 ) ;
F_11 ( V_9 , F_22 ( V_35 ) , 0 ) ;
F_11 ( V_9 , F_22 ( V_287 ) , V_9 -> V_183 ) ;
F_11 ( V_9 , F_22 ( V_288 ) ,
( ( T_2 ) V_282 << F_22 ( V_289 ) ) |
( ( T_2 ) ( V_282 * V_9 -> V_13 ) <<
F_22 ( V_290 ) ) ) ;
F_11 ( V_9 , F_22 ( V_291 ) , ~ 0ull ) ;
F_184 ( V_9 ) ;
V_284 = V_292 ;
V_283 = V_293 ;
F_11 ( V_9 , F_22 ( V_294 ) ,
( V_284 << V_295 ) |
( V_283 << V_296 ) ) ;
}
void F_178 ( struct V_8 * V_9 )
{
T_2 V_297 ;
unsigned V_27 ;
F_186 ( F_22 ( V_273 ) ) ;
F_186 ( F_22 ( V_58 ) ) ;
F_187 ( F_22 ( V_298 ) ) ;
F_187 ( F_22 ( V_299 ) ) ;
F_186 ( F_22 ( V_300 ) ) ;
F_186 ( F_22 ( V_291 ) ) ;
for ( V_27 = 0 ; V_27 < V_301 ; ++ V_27 ) {
F_188 ( V_302 ) ;
F_188 ( V_303 ) ;
F_188 ( V_304 ) ;
}
F_186 ( F_22 ( V_210 ) ) ;
F_186 ( F_22 ( V_240 ) ) ;
F_186 ( F_22 ( V_305 ) ) ;
F_186 ( F_22 ( V_306 ) ) ;
F_186 ( F_22 ( V_286 ) ) ;
F_186 ( F_22 ( V_35 ) ) ;
F_186 ( F_22 ( V_307 ) ) ;
F_186 ( F_22 ( V_288 ) ) ;
F_187 ( F_22 ( V_308 ) ) ;
F_187 ( F_22 ( V_309 ) ) ;
F_186 ( F_22 ( V_285 ) ) ;
F_186 ( F_22 ( V_275 ) ) ;
F_186 ( F_22 ( V_287 ) ) ;
F_186 ( F_22 ( V_281 ) ) ;
F_186 ( F_22 ( V_310 ) ) ;
F_186 ( F_22 ( V_311 ) ) ;
F_186 ( F_22 ( V_312 ) ) ;
F_186 ( F_22 ( V_313 ) ) ;
F_186 ( F_22 ( V_294 ) ) ;
}
static void F_177 ( struct V_8 * V_9 )
{
struct V_314 * V_184 ;
struct V_314 * V_315 ;
T_2 V_316 [ 2 ] ;
T_2 V_317 ;
T_5 V_318 ;
T_4 V_319 ;
T_4 V_80 , V_81 , V_30 ;
V_80 = V_9 -> V_65 & V_9 -> V_79 ;
V_81 = V_9 -> V_72 & V_9 -> V_79 ;
V_30 = F_63 ( V_9 ) ;
V_184 = V_9 -> V_184 ;
F_17 ( V_9 -> V_12 ,
L_32 ,
V_9 -> V_13 , V_80 , V_81 , V_30 ,
! F_157 ( & V_9 -> V_45 ) ) ;
while ( V_80 != V_81 ) {
char V_31 [ 6 ] = { 'x' , 'x' , 'x' , 'x' , 0 } ;
V_315 = & V_9 -> V_184 [ V_80 ] ;
V_316 [ 0 ] = F_169 ( V_315 -> V_226 [ 0 ] ) ;
V_316 [ 1 ] = F_169 ( V_315 -> V_226 [ 1 ] ) ;
V_31 [ 0 ] = ( V_316 [ 1 ] & V_213 ) ? 'I' : '-' ;
V_31 [ 1 ] = ( V_316 [ 1 ] & V_212 ) ?
'H' : '-' ;
V_31 [ 2 ] = ( V_316 [ 0 ] & V_320 ) ? 'F' : '-' ;
V_31 [ 3 ] = ( V_316 [ 0 ] & V_321 ) ? 'L' : '-' ;
V_317 = ( V_316 [ 0 ] >> V_322 )
& V_323 ;
V_318 = ( V_316 [ 1 ] >> V_324 )
& V_325 ;
V_319 = ( V_316 [ 0 ] >> V_326 )
& V_327 ;
F_17 ( V_9 -> V_12 ,
L_33 ,
V_80 , V_31 , V_317 , V_318 , V_319 ) ;
F_17 ( V_9 -> V_12 ,
L_34 ,
V_316 [ 0 ] , V_316 [ 1 ] ) ;
if ( V_316 [ 0 ] & V_320 )
F_17 ( V_9 -> V_12 ,
L_35 ,
( T_5 ) ( ( V_316 [ 1 ] &
V_328 ) >>
V_329 ) ,
( T_5 ) ( ( V_316 [ 1 ] &
V_227 ) >>
V_228 ) ,
( T_5 ) ( ( V_316 [ 1 ] &
V_330 ) >>
V_331 ) ) ;
V_80 ++ ;
V_80 &= V_9 -> V_79 ;
}
}
void F_189 ( struct V_155 * V_156 , struct V_8 * V_9 )
{
T_4 V_80 , V_81 ;
struct V_314 * V_315 ;
T_2 V_316 [ 2 ] ;
T_2 V_317 ;
T_5 V_318 ;
T_4 V_319 ;
V_80 = V_9 -> V_65 & V_9 -> V_79 ;
V_81 = F_170 ( V_9 -> V_72 ) & V_9 -> V_79 ;
F_116 ( V_156 , V_332 , V_9 -> V_13 ,
V_9 -> V_140 ,
F_1 ( V_9 -> V_2 . V_70 ) ,
( unsigned long long ) F_13 ( V_9 , F_22 ( V_273 ) ) ,
( unsigned long long ) F_13 ( V_9 , F_22 ( V_58 ) ) ,
( unsigned long long ) F_13 ( V_9 , F_22 ( V_300 ) ) ,
( unsigned long long ) F_13 ( V_9 , F_22 ( V_210 ) ) , V_81 ,
( unsigned long long ) F_13 ( V_9 , F_22 ( V_240 ) ) , V_80 ,
( unsigned long long ) F_169 ( * V_9 -> V_85 ) ,
( unsigned long long ) F_13 ( V_9 , F_22 ( V_288 ) ) ,
( unsigned long long ) F_13 ( V_9 , F_22 ( V_275 ) ) ,
( unsigned long long ) F_13 ( V_9 , F_22 ( V_286 ) ) ,
( unsigned long long ) V_9 -> V_260 ,
( unsigned long long ) V_9 -> V_206 ,
V_9 -> V_333 ,
V_9 -> V_78 ,
V_9 -> V_72 ,
V_9 -> V_65 ,
! F_157 ( & V_9 -> V_45 ) ,
V_9 -> V_334 ,
( unsigned long long ) F_13 ( V_9 , V_335 ) ) ;
while ( V_80 != V_81 ) {
char V_31 [ 6 ] = { 'x' , 'x' , 'x' , 'x' , 0 } ;
V_315 = & V_9 -> V_184 [ V_80 ] ;
V_316 [ 0 ] = F_169 ( V_315 -> V_226 [ 0 ] ) ;
V_316 [ 1 ] = F_169 ( V_315 -> V_226 [ 1 ] ) ;
V_31 [ 0 ] = ( V_316 [ 1 ] & V_213 ) ? 'I' : '-' ;
V_31 [ 1 ] = ( V_316 [ 1 ] & V_212 ) ?
'H' : '-' ;
V_31 [ 2 ] = ( V_316 [ 0 ] & V_320 ) ? 'F' : '-' ;
V_31 [ 3 ] = ( V_316 [ 0 ] & V_321 ) ? 'L' : '-' ;
V_317 = ( V_316 [ 0 ] >> V_322 )
& V_323 ;
V_318 = ( V_316 [ 1 ] >> V_324 )
& V_325 ;
V_319 = ( V_316 [ 0 ] >> V_326 )
& V_327 ;
F_116 ( V_156 ,
L_36 ,
V_80 , V_31 , V_317 , V_318 , V_319 ) ;
if ( V_316 [ 0 ] & V_320 )
F_116 ( V_156 , L_37 ,
( T_5 ) ( ( V_316 [ 1 ] &
V_328 ) >>
V_329 ) ,
( T_5 ) ( ( V_316 [ 1 ] &
V_227 ) >>
V_228 ) ) ;
V_80 = ( V_80 + 1 ) & V_9 -> V_79 ;
}
}
static inline T_2 F_190 ( struct V_8 * V_9 , T_2 V_336 )
{
T_5 V_337 = ( V_9 -> V_72 >> V_9 -> V_200 ) & 3 ;
V_336 &= ~ V_338 ;
V_336 |= ( ( T_2 ) V_337 & V_325 )
<< V_324 ;
return V_336 ;
}
static inline T_4 F_191 ( struct V_8 * V_9 , struct V_36 * V_37 )
{
int V_27 ;
T_4 V_81 ;
struct V_221 * V_222 = V_37 -> V_222 ;
T_5 V_230 = 0 , V_231 = F_166 ( V_37 ) ;
V_81 = V_9 -> V_72 & V_9 -> V_79 ;
V_9 -> V_184 [ V_81 ] . V_226 [ 0 ] = F_192 ( V_222 -> V_226 [ 0 ] ) ;
V_9 -> V_184 [ V_81 ] . V_226 [ 1 ] = F_192 ( F_190 ( V_9 , V_222 -> V_226 [ 1 ] ) ) ;
F_193 ( V_9 , V_222 -> V_226 [ 0 ] , V_222 -> V_226 [ 1 ] ,
V_81 , & V_9 -> V_184 [ V_81 ] ) ;
V_81 = ++ V_9 -> V_72 & V_9 -> V_79 ;
V_222 ++ ;
if ( V_231 > V_232 )
V_230 = V_231 >> 1 ;
for ( V_27 = 1 ; V_27 < V_37 -> V_229 ; V_27 ++ , V_222 ++ ) {
T_2 V_336 ;
V_9 -> V_184 [ V_81 ] . V_226 [ 0 ] = F_192 ( V_222 -> V_226 [ 0 ] ) ;
if ( V_230 ) {
V_336 = V_222 -> V_226 [ 1 ] ;
V_230 -- ;
} else {
V_336 = F_190 ( V_9 , V_222 -> V_226 [ 1 ] ) ;
}
V_9 -> V_184 [ V_81 ] . V_226 [ 1 ] = F_192 ( V_336 ) ;
F_193 ( V_9 , V_222 -> V_226 [ 0 ] , V_336 ,
V_81 , & V_9 -> V_184 [ V_81 ] ) ;
V_81 = ++ V_9 -> V_72 & V_9 -> V_79 ;
}
V_37 -> V_83 = V_81 ;
#ifdef F_24
V_37 -> V_41 = V_9 -> V_339 ++ ;
F_194 ( V_9 , V_37 -> V_41 ) ;
F_26 ( V_9 -> V_77 [ V_9 -> V_333 & V_9 -> V_79 ] ) ;
#endif
V_9 -> V_77 [ V_9 -> V_333 ++ & V_9 -> V_79 ] = V_37 ;
V_9 -> V_84 -= V_37 -> V_229 ;
return V_81 ;
}
static int F_195 (
struct V_8 * V_9 ,
struct V_39 * V_40 ,
struct V_36 * V_37 )
{
int V_141 ;
V_9 -> V_84 = F_63 ( V_9 ) ;
if ( V_37 -> V_229 <= V_9 -> V_84 )
return - V_340 ;
if ( V_40 && V_40 -> V_341 ) {
unsigned V_250 ;
V_250 = F_196 (
( const V_342 * ) & V_9 -> V_52 . V_343 ) ;
V_141 = V_40 -> V_341 ( V_9 , V_40 , V_37 , V_250 ) ;
if ( V_141 == - V_340 )
V_9 -> V_84 = F_63 ( V_9 ) ;
} else {
V_141 = - V_344 ;
}
return V_141 ;
}
int F_197 ( struct V_8 * V_9 ,
struct V_39 * V_40 ,
struct V_36 * V_37 )
{
int V_141 = 0 ;
T_4 V_81 ;
unsigned long V_31 ;
if ( F_79 ( V_37 -> V_345 ) )
return - V_115 ;
V_37 -> V_40 = V_40 ;
F_33 ( & V_9 -> V_69 , V_31 ) ;
V_238:
if ( F_79 ( ! F_40 ( V_9 ) ) )
goto V_346;
if ( F_79 ( V_37 -> V_229 > V_9 -> V_84 ) )
goto V_347;
V_81 = F_191 ( V_9 , V_37 ) ;
if ( V_40 )
F_198 ( V_40 ) ;
F_180 ( V_9 , V_81 ) ;
V_348:
F_37 ( & V_9 -> V_69 , V_31 ) ;
return V_141 ;
V_346:
if ( V_40 )
F_198 ( V_40 ) ;
V_37 -> V_83 = 0 ;
#ifdef F_24
V_37 -> V_41 = V_9 -> V_339 ++ ;
F_194 ( V_9 , V_37 -> V_41 ) ;
#endif
F_199 ( & V_9 -> V_46 ) ;
F_36 ( & V_37 -> V_47 , & V_9 -> V_45 ) ;
F_200 ( & V_9 -> V_46 ) ;
if ( V_40 ) {
V_40 -> V_349 ++ ;
V_40 -> V_108 += V_37 -> V_229 ;
}
F_55 ( & V_9 -> V_51 ) ;
V_141 = - V_350 ;
goto V_348;
V_347:
V_141 = F_195 ( V_9 , V_40 , V_37 ) ;
if ( V_141 == - V_340 ) {
V_141 = 0 ;
goto V_238;
}
V_9 -> V_334 ++ ;
goto V_348;
}
int F_201 ( struct V_8 * V_9 , struct V_39 * V_40 ,
struct V_351 * V_352 , T_1 * V_353 )
{
struct V_36 * V_37 , * V_354 ;
int V_141 = 0 ;
unsigned long V_31 ;
T_4 V_81 = V_355 ;
T_1 V_356 = 0 , V_357 = 0 , V_358 ;
F_33 ( & V_9 -> V_69 , V_31 ) ;
V_238:
F_34 (tx, tx_next, tx_list, list) {
V_37 -> V_40 = V_40 ;
if ( F_79 ( ! F_40 ( V_9 ) ) )
goto V_346;
if ( F_79 ( V_37 -> V_229 > V_9 -> V_84 ) )
goto V_347;
if ( F_79 ( V_37 -> V_345 ) ) {
V_141 = - V_115 ;
goto V_359;
}
F_35 ( & V_37 -> V_47 ) ;
V_81 = F_191 ( V_9 , V_37 ) ;
V_356 ++ ;
if ( V_81 != V_355 &&
( V_356 & V_360 ) == 0 ) {
F_180 ( V_9 , V_81 ) ;
V_81 = V_355 ;
}
}
V_359:
V_358 = V_356 + V_357 ;
if ( V_40 )
F_202 ( V_40 , V_358 ) ;
if ( V_81 != V_355 )
F_180 ( V_9 , V_81 ) ;
F_37 ( & V_9 -> V_69 , V_31 ) ;
* V_353 = V_358 ;
return V_141 ;
V_346:
F_199 ( & V_9 -> V_46 ) ;
F_34 (tx, tx_next, tx_list, list) {
V_37 -> V_40 = V_40 ;
F_35 ( & V_37 -> V_47 ) ;
V_37 -> V_83 = 0 ;
#ifdef F_24
V_37 -> V_41 = V_9 -> V_339 ++ ;
F_194 ( V_9 , V_37 -> V_41 ) ;
#endif
F_36 ( & V_37 -> V_47 , & V_9 -> V_45 ) ;
V_357 ++ ;
if ( V_40 ) {
V_40 -> V_349 ++ ;
V_40 -> V_108 += V_37 -> V_229 ;
}
}
F_200 ( & V_9 -> V_46 ) ;
F_55 ( & V_9 -> V_51 ) ;
V_141 = - V_350 ;
goto V_359;
V_347:
V_141 = F_195 ( V_9 , V_40 , V_37 ) ;
if ( V_141 == - V_340 ) {
V_141 = 0 ;
goto V_238;
}
V_9 -> V_334 ++ ;
goto V_359;
}
static void F_46 ( struct V_8 * V_9 , enum V_361 V_362 )
{
unsigned long V_31 ;
F_33 ( & V_9 -> V_69 , V_31 ) ;
F_52 ( & V_9 -> V_52 ) ;
F_54 ( V_9 , V_362 ) ;
if ( V_9 -> V_2 . V_70 == V_71 )
F_62 ( V_9 , F_63 ( V_9 ) ) ;
F_53 ( & V_9 -> V_52 ) ;
F_37 ( & V_9 -> V_69 , V_31 ) ;
}
static void F_54 ( struct V_8 * V_9 ,
enum V_361 V_362 )
{
struct V_4 * V_5 = & V_9 -> V_2 ;
int V_363 = 0 ;
#ifdef F_57
F_17 ( V_9 -> V_12 , L_38 , V_9 -> V_13 ,
V_3 [ V_5 -> V_70 ] ,
V_364 [ V_362 ] ) ;
#endif
switch ( V_5 -> V_70 ) {
case V_207 :
switch ( V_362 ) {
case V_220 :
break;
case V_217 :
V_5 -> V_106 = 1 ;
case V_219 :
F_2 ( & V_9 -> V_2 ) ;
F_71 ( V_9 ,
V_365 ) ;
break;
case V_60 :
break;
case V_76 :
break;
case V_86 :
F_66 ( V_9 ) ;
break;
case V_366 :
break;
case V_265 :
break;
case V_218 :
break;
case V_367 :
break;
case V_368 :
break;
case V_369 :
break;
case V_370 :
break;
case V_73 :
break;
}
break;
case V_365 :
switch ( V_362 ) {
case V_220 :
F_71 ( V_9 , V_207 ) ;
F_66 ( V_9 ) ;
break;
case V_219 :
break;
case V_60 :
F_71 ( V_9 ,
V_371 ) ;
F_69 ( V_9 ) ;
break;
case V_76 :
break;
case V_217 :
V_5 -> V_106 = 1 ;
break;
case V_86 :
break;
case V_366 :
break;
case V_265 :
F_55 ( & V_9 -> V_53 ) ;
break;
case V_218 :
V_5 -> V_106 = 0 ;
break;
case V_367 :
break;
case V_368 :
break;
case V_369 :
break;
case V_370 :
break;
case V_73 :
break;
}
break;
case V_371 :
switch ( V_362 ) {
case V_220 :
F_71 ( V_9 , V_207 ) ;
F_66 ( V_9 ) ;
break;
case V_219 :
break;
case V_60 :
break;
case V_76 :
F_183 ( V_9 ) ;
F_71 ( V_9 , V_5 -> V_106 ?
V_71 :
V_372 ) ;
break;
case V_217 :
V_5 -> V_106 = 1 ;
break;
case V_86 :
break;
case V_366 :
break;
case V_265 :
break;
case V_218 :
V_5 -> V_106 = 0 ;
break;
case V_367 :
break;
case V_368 :
break;
case V_369 :
break;
case V_370 :
break;
case V_73 :
break;
}
break;
case V_372 :
switch ( V_362 ) {
case V_220 :
F_71 ( V_9 , V_207 ) ;
F_66 ( V_9 ) ;
break;
case V_219 :
break;
case V_60 :
break;
case V_76 :
break;
case V_217 :
F_71 ( V_9 , V_71 ) ;
V_5 -> V_106 = 1 ;
break;
case V_86 :
break;
case V_366 :
break;
case V_265 :
F_71 ( V_9 , V_373 ) ;
F_55 ( & V_9 -> V_53 ) ;
break;
case V_218 :
break;
case V_370 :
case V_367 :
F_71 ( V_9 , V_374 ) ;
F_203 ( & V_9 -> V_12 -> V_87 ) ;
F_68 ( & V_9 -> V_12 -> V_88 ) ;
break;
case V_368 :
break;
case V_369 :
break;
case V_73 :
break;
}
break;
case V_375 :
switch ( V_362 ) {
case V_220 :
F_71 ( V_9 , V_207 ) ;
break;
case V_219 :
break;
case V_60 :
break;
case V_76 :
break;
case V_217 :
V_5 -> V_106 = 1 ;
break;
case V_86 :
F_71 ( V_9 , V_376 ) ;
F_69 ( V_9 ) ;
break;
case V_366 :
break;
case V_265 :
break;
case V_218 :
V_5 -> V_106 = 0 ;
break;
case V_367 :
break;
case V_368 :
break;
case V_369 :
break;
case V_370 :
V_5 -> V_106 = 0 ;
break;
case V_73 :
break;
}
break;
case V_376 :
switch ( V_362 ) {
case V_220 :
F_71 ( V_9 , V_207 ) ;
F_70 ( & V_9 -> F_64 ) ;
break;
case V_219 :
break;
case V_60 :
break;
case V_76 :
F_183 ( V_9 ) ;
F_71 ( V_9 , V_5 -> V_106 ?
V_71 :
V_372 ) ;
break;
case V_217 :
V_5 -> V_106 = 1 ;
break;
case V_86 :
break;
case V_366 :
break;
case V_265 :
break;
case V_218 :
V_5 -> V_106 = 0 ;
break;
case V_367 :
break;
case V_368 :
break;
case V_369 :
break;
case V_370 :
V_5 -> V_106 = 0 ;
break;
case V_73 :
break;
}
break;
case V_373 :
switch ( V_362 ) {
case V_220 :
F_71 ( V_9 , V_207 ) ;
F_70 ( & V_9 -> F_64 ) ;
break;
case V_219 :
break;
case V_60 :
F_71 ( V_9 , V_375 ) ;
F_70 ( & V_9 -> F_64 ) ;
break;
case V_76 :
break;
case V_217 :
V_5 -> V_106 = 1 ;
break;
case V_86 :
break;
case V_366 :
break;
case V_265 :
F_55 ( & V_9 -> V_53 ) ;
break;
case V_218 :
V_5 -> V_106 = 0 ;
break;
case V_367 :
break;
case V_368 :
break;
case V_369 :
break;
case V_370 :
V_5 -> V_106 = 0 ;
break;
case V_73 :
break;
}
break;
case V_377 :
switch ( V_362 ) {
case V_220 :
F_71 ( V_9 , V_207 ) ;
F_70 ( & V_9 -> F_64 ) ;
break;
case V_219 :
break;
case V_60 :
F_71 ( V_9 , V_375 ) ;
F_70 ( & V_9 -> F_64 ) ;
break;
case V_76 :
break;
case V_217 :
V_5 -> V_106 = 1 ;
break;
case V_86 :
break;
case V_366 :
break;
case V_265 :
F_55 ( & V_9 -> V_53 ) ;
break;
case V_218 :
V_5 -> V_106 = 0 ;
break;
case V_367 :
break;
case V_368 :
break;
case V_369 :
break;
case V_370 :
break;
case V_73 :
break;
}
break;
case V_374 :
switch ( V_362 ) {
case V_220 :
F_71 ( V_9 , V_207 ) ;
F_70 ( & V_9 -> F_64 ) ;
break;
case V_219 :
break;
case V_60 :
break;
case V_76 :
break;
case V_217 :
V_5 -> V_106 = 1 ;
break;
case V_86 :
break;
case V_366 :
break;
case V_265 :
break;
case V_218 :
V_5 -> V_106 = 0 ;
break;
case V_367 :
break;
case V_368 :
F_71 ( V_9 , V_378 ) ;
F_70 ( & V_9 -> F_64 ) ;
break;
case V_369 :
break;
case V_370 :
break;
case V_73 :
break;
}
break;
case V_378 :
switch ( V_362 ) {
case V_220 :
F_71 ( V_9 , V_207 ) ;
F_70 ( & V_9 -> F_64 ) ;
break;
case V_219 :
break;
case V_60 :
break;
case V_76 :
break;
case V_217 :
V_5 -> V_106 = 1 ;
break;
case V_86 :
F_203 ( & V_9 -> V_12 -> V_87 ) ;
F_68 ( & V_9 -> V_12 -> V_88 ) ;
break;
case V_366 :
break;
case V_265 :
break;
case V_218 :
V_5 -> V_106 = 0 ;
break;
case V_367 :
break;
case V_368 :
break;
case V_369 :
F_183 ( V_9 ) ;
F_71 ( V_9 , V_5 -> V_106 ?
V_71 :
V_372 ) ;
break;
case V_370 :
break;
case V_73 :
break;
}
break;
case V_71 :
switch ( V_362 ) {
case V_220 :
F_71 ( V_9 , V_207 ) ;
F_70 ( & V_9 -> F_64 ) ;
break;
case V_219 :
break;
case V_60 :
break;
case V_76 :
break;
case V_217 :
break;
case V_86 :
break;
case V_366 :
break;
case V_265 :
V_363 = 1 ;
F_47 ( V_9 ) ;
case V_73 :
F_71 ( V_9 , V_373 ) ;
F_55 ( & V_9 -> V_53 ) ;
break;
case V_218 :
F_71 ( V_9 , V_377 ) ;
break;
case V_370 :
V_5 -> V_106 = 0 ;
case V_367 :
F_71 ( V_9 , V_374 ) ;
F_203 ( & V_9 -> V_12 -> V_87 ) ;
F_68 ( & V_9 -> V_12 -> V_88 ) ;
break;
case V_368 :
break;
case V_369 :
break;
}
break;
}
V_5 -> V_379 = V_362 ;
if ( V_363 )
F_65 ( V_9 , 0 ) ;
}
static int F_204 ( struct V_16 * V_12 , struct V_36 * V_37 )
{
int V_27 ;
if ( F_79 ( ( V_37 -> V_229 == ( V_380 - 1 ) ) ) ) {
if ( ! V_37 -> V_345 ) {
V_37 -> V_234 = V_380 ;
} else if ( ! V_37 -> V_233 ) {
V_37 -> V_233 = F_205 ( V_37 -> V_345 + sizeof( T_1 ) ,
V_381 ) ;
if ( ! V_37 -> V_233 )
goto V_382;
V_37 -> V_383 = 0 ;
}
return 0 ;
}
if ( F_79 ( V_37 -> V_229 == V_380 ) )
goto V_382;
V_37 -> V_222 = F_206 (
V_380 ,
sizeof( struct V_221 ) ,
V_381 ) ;
if ( ! V_37 -> V_222 )
goto V_382;
V_37 -> V_234 = V_380 - 1 ;
for ( V_27 = 0 ; V_27 < V_37 -> V_229 ; V_27 ++ )
V_37 -> V_222 [ V_27 ] = V_37 -> V_235 [ V_27 ] ;
return 0 ;
V_382:
F_27 ( V_12 , V_37 ) ;
return - V_144 ;
}
int F_207 ( struct V_16 * V_12 , struct V_36 * V_37 ,
int type , void * V_384 , struct V_385 * V_385 ,
unsigned long V_386 , T_4 V_319 )
{
int V_387 , V_121 ;
T_10 V_317 ;
V_121 = F_204 ( V_12 , V_37 ) ;
if ( V_121 ) {
F_27 ( V_12 , V_37 ) ;
return V_121 ;
}
if ( V_37 -> V_233 ) {
if ( type == V_388 ) {
F_27 ( V_12 , V_37 ) ;
return - V_115 ;
}
if ( type == V_225 ) {
V_384 = F_208 ( V_385 ) ;
V_384 += V_386 ;
} else if ( F_107 ( ! V_384 ) ) {
F_27 ( V_12 , V_37 ) ;
return - V_115 ;
}
memcpy ( V_37 -> V_233 + V_37 -> V_383 , V_384 , V_319 ) ;
V_37 -> V_383 += V_319 ;
if ( type == V_225 )
F_209 ( V_385 ) ;
if ( V_37 -> V_345 - V_37 -> V_383 )
return 0 ;
V_387 = V_37 -> V_389 & ( sizeof( T_1 ) - 1 ) ;
if ( V_387 ) {
V_387 = sizeof( T_1 ) - V_387 ;
memset ( V_37 -> V_233 + V_37 -> V_383 , 0 , V_387 ) ;
V_37 -> V_389 += V_387 ;
V_37 -> V_345 += V_387 ;
}
V_317 = F_210 ( & V_12 -> V_177 -> V_178 ,
V_37 -> V_233 ,
V_37 -> V_345 ,
V_224 ) ;
if ( F_79 ( F_211 ( & V_12 -> V_177 -> V_178 , V_317 ) ) ) {
F_27 ( V_12 , V_37 ) ;
return - V_390 ;
}
V_37 -> V_234 = V_380 ;
return F_212 ( V_12 , V_223 , V_37 ,
V_317 , V_37 -> V_345 ) ;
}
return 1 ;
}
void F_213 ( struct V_16 * V_12 , T_2 V_125 , T_1 V_391 )
{
struct V_8 * V_9 ;
int V_27 ;
T_2 V_392 ;
V_392 = ( ( V_125 & F_22 ( V_393 ) ) <<
F_22 ( V_394 ) ) |
( ( ( V_391 & V_125 ) & F_22 ( V_395 ) ) <<
F_22 ( V_396 ) ) ;
for ( V_27 = 0 ; V_27 < V_12 -> V_28 ; V_27 ++ ) {
F_214 ( V_397 , L_39 ,
V_27 , ( T_1 ) V_392 ) ;
V_9 = & V_12 -> V_29 [ V_27 ] ;
F_11 ( V_9 , F_22 ( V_313 ) , V_392 ) ;
}
}
int F_215 ( struct V_16 * V_12 , struct V_36 * V_37 )
{
int V_121 = 0 ;
V_37 -> V_229 ++ ;
if ( ( F_79 ( V_37 -> V_229 == V_37 -> V_234 ) ) ) {
V_121 = F_204 ( V_12 , V_37 ) ;
if ( V_121 ) {
F_27 ( V_12 , V_37 ) ;
return V_121 ;
}
}
F_216 (
V_37 ,
V_388 ,
V_12 -> V_179 ,
sizeof( T_1 ) - ( V_37 -> V_389 & ( sizeof( T_1 ) - 1 ) ) ) ;
F_217 ( V_12 , V_37 ) ;
return V_121 ;
}
void F_218 (
struct V_36 * V_37 ,
T_5 V_398 ,
T_5 V_399 ,
T_1 * V_400 ,
T_5 V_401 )
{
T_1 V_27 , V_402 = 0 , V_316 = 0 ;
T_5 V_231 ;
F_26 ( V_398 > 9 || ( V_401 & 3 ) || V_401 == 4 ) ;
if ( V_398 == 1 )
V_231 = V_232 ;
else if ( V_398 <= 5 )
V_231 = V_403 ;
else
V_231 = V_404 ;
V_37 -> V_229 ++ ;
switch ( V_231 ) {
case V_404 :
V_37 -> V_229 ++ ;
V_37 -> V_235 [ 2 ] . V_226 [ 0 ] = 0 ;
V_37 -> V_235 [ 2 ] . V_226 [ 1 ] = 0 ;
case V_403 :
V_37 -> V_229 ++ ;
V_37 -> V_235 [ 1 ] . V_226 [ 0 ] = 0 ;
V_37 -> V_235 [ 1 ] . V_226 [ 1 ] = 0 ;
break;
}
V_401 >>= 2 ;
V_37 -> V_235 [ 0 ] . V_226 [ 1 ] |=
( ( ( T_2 ) V_399 & V_405 )
<< V_329 ) |
( ( ( T_2 ) V_401 & V_406 )
<< V_331 ) |
( ( ( T_2 ) V_231 & V_407 )
<< V_228 ) |
( ( ( T_2 ) V_400 [ 0 ] & V_408 )
<< V_409 ) ;
for ( V_27 = 0 ; V_27 < ( V_398 - 1 ) ; V_27 ++ ) {
if ( ! V_402 && ! ( V_27 & 2 ) )
V_316 ++ ;
V_37 -> V_235 [ V_316 ] . V_226 [ ! ! ( V_27 & 2 ) ] |=
( ( ( T_2 ) V_400 [ V_27 + 1 ] )
<< V_402 ) ;
V_402 = ( V_402 + 32 ) & 63 ;
}
}
int F_219 ( struct V_8 * V_9 )
{
int V_410 ;
int V_411 ;
if ( ! V_9 ) {
F_220 ( V_9 , - V_115 ) ;
return - V_115 ;
}
while ( 1 ) {
V_410 = F_221 ( F_170 ( V_9 -> V_206 ) ) ;
if ( V_410 > 31 ) {
F_220 ( V_9 , - V_390 ) ;
return - V_390 ;
}
V_411 = F_222 ( V_410 , & V_9 -> V_206 ) ;
if ( ! V_411 )
break;
F_223 () ;
}
F_220 ( V_9 , V_410 ) ;
return V_410 ;
}
void F_224 ( struct V_8 * V_9 , int V_412 )
{
if ( ! V_9 )
return;
F_225 ( V_9 , V_412 ) ;
if ( V_412 < 0 || V_412 > 31 )
return;
F_226 ( V_412 , & V_9 -> V_206 ) ;
}
void F_227 ( struct V_16 * V_12 , int V_413 )
{
int V_27 ;
enum V_361 V_362 = V_413 ? V_370 :
V_367 ;
F_67 ( & V_12 -> V_87 , V_12 -> V_28 ) ;
for ( V_27 = 0 ; V_27 < V_12 -> V_28 ; V_27 ++ )
F_46 ( & V_12 -> V_29 [ V_27 ] , V_362 ) ;
}
void F_228 ( struct V_16 * V_12 )
{
int V_27 ;
int V_141 ;
V_141 = F_229 ( V_12 -> V_88 ,
F_230 ( & V_12 -> V_87 ) <=
0 ) ;
if ( V_141 || F_230 ( & V_12 -> V_87 ) < 0 )
return;
F_67 ( & V_12 -> V_87 , V_12 -> V_28 ) ;
for ( V_27 = 0 ; V_27 < V_12 -> V_28 ; V_27 ++ )
F_46 ( & V_12 -> V_29 [ V_27 ] , V_368 ) ;
( void ) F_229 ( V_12 -> V_88 ,
F_230 ( & V_12 -> V_87 ) <= 0 ) ;
}
void F_231 ( struct V_16 * V_12 )
{
int V_27 ;
for ( V_27 = 0 ; V_27 < V_12 -> V_28 ; V_27 ++ )
F_46 ( & V_12 -> V_29 [ V_27 ] ,
V_369 ) ;
}
void F_232 (
struct V_8 * V_9 )
{
F_233 ( V_9 , V_9 -> V_202 ) ;
F_234 ( V_9 -> V_12 ,
V_414 + ( 8 * ( V_415 / 64 ) ) ,
V_9 -> V_202 ) ;
}
