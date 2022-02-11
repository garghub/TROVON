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
const struct V_129 * V_130 = & V_131 -> V_132 ;
unsigned long V_133 ;
if ( F_86 ( V_130 ) != 1 )
goto V_134;
V_133 = F_87 () ;
F_77 () ;
V_128 = F_88 ( & V_12 -> V_135 , & V_133 ,
V_136 ) ;
if ( V_128 && V_128 -> V_124 [ V_113 ] ) {
struct V_137 * V_124 = V_128 -> V_124 [ V_113 ] ;
V_9 = V_124 -> V_9 [ V_118 & V_124 -> V_125 ] ;
}
F_80 () ;
if ( V_9 )
return V_9 ;
V_134:
return F_81 ( V_12 , V_118 , V_113 ) ;
}
static void F_89 ( struct V_137 * V_124 )
{
int V_27 ;
for ( V_27 = 0 ; V_27 < F_90 ( V_124 -> V_138 ? : 1 ) - V_124 -> V_138 ; V_27 ++ )
V_124 -> V_9 [ V_124 -> V_138 + V_27 ] = V_124 -> V_9 [ V_27 ] ;
}
static void F_91 ( struct V_137 * V_124 ,
struct V_8 * V_9 )
{
unsigned int V_27 , pow ;
for ( V_27 = 0 ; V_27 < V_124 -> V_138 ; V_27 ++ ) {
if ( V_124 -> V_9 [ V_27 ] == V_9 ) {
memmove ( & V_124 -> V_9 [ V_27 ] , & V_124 -> V_9 [ V_27 + 1 ] ,
( V_124 -> V_138 - V_27 - 1 ) * sizeof( V_124 -> V_9 [ 0 ] ) ) ;
V_124 -> V_138 -- ;
pow = F_90 ( V_124 -> V_138 ? : 1 ) ;
V_124 -> V_125 = pow - 1 ;
F_89 ( V_124 ) ;
break;
}
}
}
T_6 F_92 ( struct V_8 * V_9 , const char * V_139 ,
T_7 V_108 )
{
struct V_16 * V_12 = V_9 -> V_12 ;
T_8 V_125 , V_140 ;
unsigned long V_141 ;
int V_142 , V_113 , V_143 ;
V_113 = F_76 ( V_9 ) ;
if ( F_79 ( V_113 < 0 ) )
return - V_115 ;
V_142 = F_93 ( & V_125 , V_144 ) ;
if ( ! V_142 )
return - V_145 ;
V_142 = F_93 ( & V_140 , V_144 ) ;
if ( ! V_142 ) {
F_94 ( V_125 ) ;
return - V_145 ;
}
V_142 = F_95 ( V_139 , V_125 ) ;
if ( V_142 )
goto V_146;
if ( ! F_96 ( V_125 , V_147 ) ) {
F_97 ( V_9 -> V_12 , L_7 ) ;
V_142 = - V_115 ;
goto V_146;
}
V_143 = sizeof( struct V_137 ) +
( V_114 * sizeof( struct V_8 * ) ) ;
F_98 ( & V_148 ) ;
F_99 (cpu, mask) {
struct V_127 * V_128 ;
if ( F_100 ( V_141 , & V_9 -> V_149 ) ) {
F_101 ( V_141 , V_140 ) ;
continue;
}
V_128 = F_88 ( & V_12 -> V_135 , & V_141 ,
V_136 ) ;
if ( ! V_128 ) {
V_128 = F_102 ( sizeof( * V_128 ) , V_144 ) ;
if ( ! V_128 ) {
V_142 = - V_145 ;
goto V_134;
}
V_128 -> V_124 [ V_113 ] = F_102 ( V_143 , V_144 ) ;
if ( ! V_128 -> V_124 [ V_113 ] ) {
F_103 ( V_128 ) ;
V_142 = - V_145 ;
goto V_134;
}
V_128 -> V_133 = V_141 ;
V_128 -> V_124 [ V_113 ] -> V_125 = 0 ;
V_128 -> V_124 [ V_113 ] -> V_138 = 1 ;
V_128 -> V_124 [ V_113 ] -> V_9 [ 0 ] = V_9 ;
V_142 = F_104 ( & V_12 -> V_135 ,
& V_128 -> V_150 ,
V_136 ) ;
if ( V_142 ) {
F_103 ( V_128 -> V_124 [ V_113 ] ) ;
F_103 ( V_128 ) ;
F_17 ( V_9 -> V_12 , L_8 ,
V_141 ) ;
goto V_134;
}
} else {
int V_138 , pow ;
if ( ! V_128 -> V_124 [ V_113 ] )
V_128 -> V_124 [ V_113 ] = F_102 ( V_143 , V_144 ) ;
if ( ! V_128 -> V_124 [ V_113 ] ) {
V_142 = - V_145 ;
goto V_134;
}
V_128 -> V_124 [ V_113 ] -> V_138 ++ ;
V_138 = V_128 -> V_124 [ V_113 ] -> V_138 ;
V_128 -> V_124 [ V_113 ] -> V_9 [ V_138 - 1 ] = V_9 ;
pow = F_90 ( V_138 ) ;
V_128 -> V_124 [ V_113 ] -> V_125 = pow - 1 ;
F_89 ( V_128 -> V_124 [ V_113 ] ) ;
}
F_101 ( V_141 , V_140 ) ;
}
F_99 (cpu, cpu_online_mask) {
struct V_127 * V_128 ;
if ( F_100 ( V_141 , V_125 ) )
continue;
V_128 = F_88 ( & V_12 -> V_135 , & V_141 ,
V_136 ) ;
if ( V_128 ) {
bool V_151 = true ;
int V_27 ;
for ( V_27 = 0 ; V_27 < V_152 ; V_27 ++ )
if ( V_128 -> V_124 [ V_27 ] )
F_91 ( V_128 -> V_124 [ V_27 ] ,
V_9 ) ;
for ( V_27 = 0 ; V_27 < V_152 ; V_27 ++ ) {
if ( ! V_128 -> V_124 [ V_27 ] )
continue;
if ( V_128 -> V_124 [ V_27 ] -> V_138 ) {
V_151 = false ;
break;
}
}
if ( V_151 ) {
V_142 = F_105 ( & V_12 -> V_135 ,
& V_128 -> V_150 ,
V_136 ) ;
F_106 ( V_142 ) ;
for ( V_27 = 0 ; V_27 < V_152 ; V_27 ++ )
F_103 ( V_128 -> V_124 [ V_27 ] ) ;
F_103 ( V_128 ) ;
}
}
}
F_107 ( & V_9 -> V_149 , V_140 ) ;
V_134:
F_108 ( & V_148 ) ;
V_146:
F_94 ( V_125 ) ;
F_94 ( V_140 ) ;
return V_142 ? : F_109 ( V_139 , V_153 ) ;
}
T_6 F_110 ( struct V_8 * V_9 , char * V_139 )
{
F_98 ( & V_148 ) ;
if ( F_111 ( & V_9 -> V_149 ) )
snprintf ( V_139 , V_153 , L_9 , L_10 ) ;
else
F_112 ( true , V_139 , & V_9 -> V_149 ) ;
F_108 ( & V_148 ) ;
return F_109 ( V_139 , V_153 ) ;
}
static void F_113 ( void * V_154 , void * V_155 )
{
struct V_127 * V_128 = V_154 ;
int V_27 ;
for ( V_27 = 0 ; V_27 < V_152 ; V_27 ++ )
F_103 ( V_128 -> V_124 [ V_27 ] ) ;
F_103 ( V_128 ) ;
}
void F_114 ( struct V_156 * V_157 ,
struct V_16 * V_12 ,
unsigned long V_158 )
{
struct V_127 * V_128 ;
int V_27 , V_159 ;
V_128 = F_88 ( & V_12 -> V_135 , & V_158 ,
V_136 ) ;
if ( ! V_128 )
return;
F_115 ( V_157 , L_11 , V_158 ) ;
for ( V_27 = 0 ; V_27 < V_152 ; V_27 ++ ) {
if ( ! V_128 -> V_124 [ V_27 ] || ! V_128 -> V_124 [ V_27 ] -> V_138 )
continue;
F_115 ( V_157 , L_12 , V_27 ) ;
for ( V_159 = 0 ; V_159 < V_128 -> V_124 [ V_27 ] -> V_138 ; V_159 ++ ) {
if ( ! V_128 -> V_124 [ V_27 ] -> V_9 [ V_159 ] )
continue;
if ( V_159 > 0 )
F_116 ( V_157 , L_13 ) ;
F_115 ( V_157 , L_14 ,
V_128 -> V_124 [ V_27 ] -> V_9 [ V_159 ] -> V_13 ) ;
}
F_116 ( V_157 , L_15 ) ;
}
F_116 ( V_157 , L_16 ) ;
}
static void F_117 ( struct V_111 * V_112 )
{
int V_27 ;
for ( V_27 = 0 ; V_112 && V_27 < V_112 -> V_160 ; V_27 ++ )
F_103 ( V_112 -> V_124 [ V_27 ] ) ;
F_103 ( V_112 ) ;
}
static void F_118 ( struct V_161 * V_47 )
{
struct V_111 * V_112 = F_5 ( V_47 , struct V_111 , V_47 ) ;
F_117 ( V_112 ) ;
}
int F_119 ( struct V_16 * V_12 , T_5 V_162 , T_5 V_122 , T_5 * V_163 )
{
int V_27 , V_159 ;
int V_164 , V_165 ;
int V_166 = 0 ;
T_5 V_167 [ V_168 ] ;
struct V_111 * V_169 , * V_170 ;
if ( ! ( V_12 -> V_31 & V_171 ) )
return 0 ;
if ( ! V_163 ) {
V_165 = V_12 -> V_28 / V_122 ;
V_164 = V_12 -> V_28 % V_122 ;
V_163 = V_167 ;
for ( V_27 = V_122 - 1 ; V_27 >= 0 ; V_27 -- , V_164 -- )
V_163 [ V_27 ] = V_165 + ( V_164 > 0 ? 1 : 0 ) ;
}
V_170 = F_102 (
sizeof( struct V_111 ) +
F_90 ( V_122 ) *
sizeof( struct V_119 * ) ,
V_144 ) ;
if ( ! V_170 )
goto V_172;
V_170 -> V_160 = V_122 ;
V_170 -> V_173 = F_90 ( V_122 ) ;
V_170 -> V_125 = ( 1 << F_120 ( V_170 -> V_173 ) ) - 1 ;
for ( V_27 = 0 ; V_27 < V_114 ; V_27 ++ )
V_170 -> V_117 [ V_27 ] = - 1 ;
for ( V_27 = 0 ; V_27 < V_170 -> V_173 ; V_27 ++ ) {
int V_174 = V_166 ;
if ( V_27 < V_170 -> V_160 ) {
int V_143 = F_90 ( V_163 [ V_27 ] ) ;
V_170 -> V_124 [ V_27 ] = F_102 (
sizeof( struct V_119 ) +
V_143 * sizeof( struct V_8 * ) ,
V_144 ) ;
if ( ! V_170 -> V_124 [ V_27 ] )
goto V_172;
V_170 -> V_124 [ V_27 ] -> V_125 = ( 1 << F_120 ( V_143 ) ) - 1 ;
for ( V_159 = 0 ; V_159 < V_143 ; V_159 ++ ) {
V_170 -> V_124 [ V_27 ] -> V_9 [ V_159 ] =
& V_12 -> V_29 [ V_166 ] ;
if ( ++ V_166 >= V_174 + V_163 [ V_27 ] )
V_166 = V_174 ;
}
for ( V_159 = 0 ; V_159 < V_163 [ V_27 ] ; V_159 ++ )
V_170 -> V_117 [ V_174 + V_159 ] = V_27 ;
} else {
V_170 -> V_124 [ V_27 ] = V_170 -> V_124 [ V_27 % V_122 ] ;
}
V_166 = V_174 + V_163 [ V_27 ] ;
}
F_121 ( & V_12 -> V_175 ) ;
V_169 = F_122 ( V_12 -> V_116 ,
F_123 ( & V_12 -> V_175 ) ) ;
F_124 ( V_12 -> V_116 , V_170 ) ;
F_125 ( & V_12 -> V_175 ) ;
if ( V_169 )
F_126 ( & V_169 -> V_47 , F_118 ) ;
return 0 ;
V_172:
F_117 ( V_170 ) ;
return - V_145 ;
}
static void F_127 ( struct V_16 * V_12 , T_7 V_176 )
{
T_7 V_27 ;
struct V_8 * V_9 ;
if ( V_12 -> V_177 ) {
F_128 ( & V_12 -> V_178 -> V_179 , 4 ,
( void * ) V_12 -> V_177 ,
V_12 -> V_180 ) ;
V_12 -> V_177 = NULL ;
V_12 -> V_180 = 0 ;
}
if ( V_12 -> V_181 ) {
F_128 ( & V_12 -> V_178 -> V_179 , V_12 -> V_182 ,
( void * ) V_12 -> V_181 ,
V_12 -> V_183 ) ;
V_12 -> V_181 = NULL ;
V_12 -> V_183 = 0 ;
}
for ( V_27 = 0 ; V_12 -> V_29 && V_27 < V_176 ; ++ V_27 ) {
V_9 = & V_12 -> V_29 [ V_27 ] ;
V_9 -> V_85 = NULL ;
V_9 -> V_184 = 0 ;
if ( V_9 -> V_185 ) {
F_128 (
& V_12 -> V_178 -> V_179 ,
V_9 -> V_186 * sizeof( T_2 [ 2 ] ) ,
V_9 -> V_185 ,
V_9 -> V_187
) ;
V_9 -> V_185 = NULL ;
V_9 -> V_187 = 0 ;
}
F_129 ( V_9 -> V_77 ) ;
V_9 -> V_77 = NULL ;
}
F_121 ( & V_12 -> V_175 ) ;
F_117 ( F_130 ( V_12 -> V_116 ) ) ;
F_131 ( V_12 -> V_116 , NULL ) ;
F_125 ( & V_12 -> V_175 ) ;
F_132 () ;
F_103 ( V_12 -> V_29 ) ;
V_12 -> V_29 = NULL ;
}
int F_133 ( struct V_16 * V_12 , T_5 V_162 )
{
unsigned V_13 ;
struct V_8 * V_9 ;
T_4 V_186 ;
void * V_188 ;
struct V_189 * V_190 = V_12 -> V_24 + V_162 ;
T_1 V_191 ;
T_9 V_192 = V_193 ;
T_7 V_176 = V_12 -> V_194 ;
if ( ! F_49 ( V_195 ) ) {
F_134 ( V_61 ) ;
return 0 ;
}
if ( V_196 &&
V_196 <= V_12 -> V_194 &&
V_196 >= V_122 )
V_176 = V_196 ;
F_135 ( V_12 , L_17 , V_196 ) ;
F_135 ( V_12 , L_18 , V_12 -> V_194 ) ;
F_135 ( V_12 , L_19 ,
V_12 -> V_197 ) ;
V_191 =
V_12 -> V_197 / ( V_176 * V_198 ) ;
F_136 ( & V_12 -> V_88 ) ;
F_67 ( & V_12 -> V_87 , 0 ) ;
V_186 = F_74 () ;
F_135 ( V_12 , L_20 ,
V_176 , V_186 ) ;
V_12 -> V_29 = F_137 ( V_176 , sizeof( * V_12 -> V_29 ) , V_144 ) ;
if ( ! V_12 -> V_29 )
return - V_145 ;
V_192 = F_138 ( V_12 , V_192 ) ;
if ( ! V_199 )
V_199 = V_200 ;
for ( V_13 = 0 ; V_13 < V_176 ; ++ V_13 ) {
V_9 = & V_12 -> V_29 [ V_13 ] ;
V_9 -> V_12 = V_12 ;
V_9 -> V_190 = V_190 ;
V_9 -> V_13 = V_13 ;
V_9 -> V_186 = V_186 ;
V_9 -> V_84 = F_63 ( V_9 ) ;
V_9 -> V_201 = F_120 ( V_186 ) ;
V_9 -> V_79 = ( 1 << V_9 -> V_201 ) - 1 ;
V_9 -> V_202 = ( T_2 ) 1 << ( 0 * V_114 +
V_13 ) ;
V_9 -> V_203 = ( T_2 ) 1 << ( 1 * V_114 +
V_13 ) ;
V_9 -> V_204 = ( T_2 ) 1 << ( 2 * V_114 +
V_13 ) ;
V_9 -> V_205 = V_9 -> V_202 | V_9 -> V_203 |
V_9 -> V_204 ;
F_139 ( & V_9 -> V_69 ) ;
F_140 ( & V_9 -> V_52 ) ;
F_139 ( & V_9 -> V_206 ) ;
F_139 ( & V_9 -> V_46 ) ;
V_9 -> V_207 = 0xfffffffe00000000ULL ;
F_71 ( V_9 , V_208 ) ;
F_141 ( & V_9 -> V_2 . V_6 ) ;
F_142 ( & V_9 -> V_2 . V_7 ) ;
F_143 ( & V_9 -> V_45 ) ;
F_143 ( & V_9 -> V_209 ) ;
V_9 -> V_210 =
F_144 ( V_12 , V_13 , F_22 ( V_211 ) ) ;
if ( V_192 )
V_12 -> V_212 =
V_213 ;
else
V_12 -> V_212 =
V_214 ;
F_145 ( & V_9 -> F_56 , F_56 ,
( unsigned long ) V_9 ) ;
F_145 ( & V_9 -> F_64 , F_64 ,
( unsigned long ) V_9 ) ;
F_146 ( & V_9 -> V_53 , F_42 ) ;
F_146 ( & V_9 -> V_51 , F_38 ) ;
V_9 -> V_64 = 0 ;
F_147 ( & V_9 -> V_66 ,
F_51 , ( unsigned long ) V_9 ) ;
V_9 -> V_185 = F_148 (
& V_12 -> V_178 -> V_179 ,
V_186 * sizeof( T_2 [ 2 ] ) ,
& V_9 -> V_187 ,
V_144
) ;
if ( ! V_9 -> V_185 )
goto V_172;
V_9 -> V_77 =
F_137 ( V_186 , sizeof( struct V_36 * ) ,
V_144 ) ;
if ( ! V_9 -> V_77 )
V_9 -> V_77 =
F_149 (
sizeof( struct V_36 * ) *
V_186 ) ;
if ( ! V_9 -> V_77 )
goto V_172;
}
V_12 -> V_182 = V_215 * V_176 ;
V_12 -> V_181 = F_148 (
& V_12 -> V_178 -> V_179 ,
V_12 -> V_182 ,
& V_12 -> V_183 ,
V_144
) ;
if ( ! V_12 -> V_181 ) {
F_17 ( V_12 , L_21 ) ;
goto V_172;
}
V_12 -> V_177 = F_148 (
& V_12 -> V_178 -> V_179 ,
sizeof( T_1 ) ,
& V_12 -> V_180 ,
V_144
) ;
if ( ! V_12 -> V_177 ) {
F_17 ( V_12 , L_22 ) ;
goto V_172;
}
V_188 = ( void * ) V_12 -> V_181 ;
for ( V_13 = 0 ; V_13 < V_176 ; ++ V_13 ) {
unsigned long V_216 ;
V_9 = & V_12 -> V_29 [ V_13 ] ;
V_9 -> V_85 = V_188 ;
V_188 += V_215 ;
V_216 = ( unsigned long ) V_9 -> V_85 -
( unsigned long ) V_12 -> V_181 ;
V_9 -> V_184 = V_12 -> V_183 + V_216 ;
F_150 ( V_9 , V_191 , V_192 ) ;
}
V_12 -> V_31 |= V_171 ;
V_12 -> V_31 |= V_192 ? V_32 : 0 ;
V_12 -> V_28 = V_176 ;
if ( F_119 ( V_12 , V_162 , V_190 -> V_217 , NULL ) )
goto V_172;
if ( F_151 ( & V_12 -> V_135 , & V_136 ) )
goto V_172;
F_135 ( V_12 , L_23 , V_12 -> V_28 ) ;
return 0 ;
V_172:
F_127 ( V_12 , V_176 ) ;
return - V_145 ;
}
void F_152 ( struct V_16 * V_12 )
{
struct V_8 * V_9 ;
unsigned int V_27 ;
for ( V_27 = 0 ; V_27 < V_12 -> V_28 ; ++ V_27 ) {
V_9 = & V_12 -> V_29 [ V_27 ] ;
F_46 ( V_9 , V_218 ) ;
}
}
void F_153 ( struct V_16 * V_12 )
{
struct V_8 * V_9 ;
unsigned int V_27 ;
for ( V_27 = 0 ; V_27 < V_12 -> V_28 ; ++ V_27 ) {
V_9 = & V_12 -> V_29 [ V_27 ] ;
F_46 ( V_9 , V_219 ) ;
}
}
void F_154 ( struct V_16 * V_12 )
{
unsigned V_27 ;
struct V_8 * V_9 ;
for ( V_27 = 0 ; V_27 < V_12 -> V_28 ; ++ V_27 ) {
V_9 = & V_12 -> V_29 [ V_27 ] ;
F_46 ( V_9 , V_220 ) ;
}
}
void F_155 ( struct V_16 * V_12 )
{
unsigned V_13 ;
struct V_8 * V_9 ;
for ( V_13 = 0 ; V_12 -> V_29 && V_13 < V_12 -> V_28 ;
++ V_13 ) {
V_9 = & V_12 -> V_29 [ V_13 ] ;
if ( ! F_156 ( & V_9 -> V_209 ) )
F_17 ( V_12 , L_24 ,
V_9 -> V_13 ) ;
F_46 ( V_9 , V_221 ) ;
F_157 ( & V_9 -> V_66 ) ;
F_9 ( & V_9 -> V_2 ) ;
}
F_127 ( V_12 , V_12 -> V_28 ) ;
F_158 ( & V_12 -> V_135 , F_113 , NULL ) ;
}
static inline void F_159 (
struct V_16 * V_12 ,
struct V_222 * V_223 )
{
switch ( F_160 ( V_223 ) ) {
case V_224 :
F_161 (
& V_12 -> V_178 -> V_179 ,
F_162 ( V_223 ) ,
F_163 ( V_223 ) ,
V_225 ) ;
break;
case V_226 :
F_164 (
& V_12 -> V_178 -> V_179 ,
F_162 ( V_223 ) ,
F_163 ( V_223 ) ,
V_225 ) ;
break;
}
}
static inline T_5 F_165 ( struct V_36 * V_37 )
{
return ( V_37 -> V_223 [ 0 ] . V_227 [ 1 ] & V_228 )
>> V_229 ;
}
void F_27 (
struct V_16 * V_12 ,
struct V_36 * V_37 )
{
T_4 V_27 ;
if ( V_37 -> V_230 ) {
T_5 V_231 = 0 , V_232 = F_165 ( V_37 ) ;
F_159 ( V_12 , & V_37 -> V_223 [ 0 ] ) ;
if ( V_232 > V_233 )
V_231 = V_232 >> 1 ;
for ( V_27 = 1 + V_231 ; V_27 < V_37 -> V_230 ; V_27 ++ )
F_159 ( V_12 , & V_37 -> V_223 [ V_27 ] ) ;
V_37 -> V_230 = 0 ;
}
F_103 ( V_37 -> V_234 ) ;
V_37 -> V_234 = NULL ;
if ( F_79 ( V_37 -> V_235 > F_166 ( V_37 -> V_236 ) ) ) {
V_37 -> V_235 = F_166 ( V_37 -> V_236 ) ;
F_103 ( V_37 -> V_223 ) ;
}
}
static inline T_4 F_167 ( struct V_8 * V_9 )
{
struct V_16 * V_12 = V_9 -> V_12 ;
int V_237 ;
T_4 V_238 ;
#ifdef F_57
F_17 ( V_9 -> V_12 , L_6 ,
V_9 -> V_13 , F_58 ( __FILE__ ) , __LINE__ , V_23 ) ;
#endif
V_239:
V_237 = F_49 ( V_240 ) && F_40 ( V_9 ) &&
( V_12 -> V_31 & V_32 ) ;
V_238 = V_237 ?
( T_4 ) F_168 ( * V_9 -> V_85 ) :
( T_4 ) F_13 ( V_9 , F_22 ( V_241 ) ) ;
if ( F_79 ( F_49 ( V_242 ) ) ) {
T_4 V_30 ;
T_4 V_243 ;
T_4 V_244 ;
int V_245 ;
V_244 = V_9 -> V_65 & V_9 -> V_79 ;
V_243 = F_169 ( V_9 -> V_72 ) & V_9 -> V_79 ;
V_30 = V_9 -> V_186 ;
if ( V_244 < V_243 )
V_245 = ( V_238 >= V_244 ) & ( V_238 <= V_243 ) ;
else if ( V_244 > V_243 )
V_245 = ( ( V_238 >= V_244 ) && ( V_238 < V_30 ) ) ||
( V_238 <= V_243 ) ;
else
V_245 = ( V_238 == V_244 ) ;
if ( F_79 ( ! V_245 ) ) {
F_17 ( V_12 , L_25 ,
V_9 -> V_13 ,
V_237 ? L_26 : L_27 ,
V_238 , V_244 , V_243 , V_30 ) ;
if ( V_237 ) {
V_237 = 0 ;
goto V_239;
}
V_238 = V_244 ;
}
}
return V_238 ;
}
static void F_62 ( struct V_8 * V_9 , unsigned V_246 )
{
struct V_39 * V_40 , * V_247 ;
struct V_39 * V_248 [ V_249 ] ;
unsigned V_27 , V_250 = 0 , V_251 ;
struct V_36 * V_252 ;
struct V_253 * V_179 = & V_9 -> V_12 -> V_254 ;
#ifdef F_57
F_17 ( V_9 -> V_12 , L_6 , V_9 -> V_13 ,
F_58 ( __FILE__ ) , __LINE__ , V_23 ) ;
F_17 ( V_9 -> V_12 , L_28 , V_246 ) ;
#endif
do {
V_251 = F_170 ( & V_179 -> V_255 ) ;
if ( ! F_156 ( & V_9 -> V_209 ) ) {
F_52 ( & V_179 -> V_255 ) ;
F_34 (
wait,
nw,
&sde->dmawait,
list) {
T_4 V_230 = 0 ;
if ( ! V_40 -> V_256 )
continue;
if ( V_250 == F_166 ( V_248 ) )
break;
if ( ! F_156 ( & V_40 -> V_78 ) ) {
V_252 = F_171 (
& V_40 -> V_78 ,
struct V_36 ,
V_47 ) ;
V_230 = V_252 -> V_230 ;
}
if ( V_230 > V_246 )
break;
V_246 -= V_230 ;
F_35 ( & V_40 -> V_47 ) ;
V_248 [ V_250 ++ ] = V_40 ;
}
F_53 ( & V_179 -> V_255 ) ;
break;
}
} while ( F_172 ( & V_179 -> V_255 , V_251 ) );
for ( V_27 = 0 ; V_27 < V_250 ; V_27 ++ )
V_248 [ V_27 ] -> V_256 ( V_248 [ V_27 ] , V_257 ) ;
}
static void F_65 ( struct V_8 * V_9 , T_2 V_258 )
{
struct V_36 * V_43 = NULL ;
int V_82 = 0 ;
T_4 V_238 , V_244 ;
int V_259 = 0 ;
V_238 = F_167 ( V_9 ) ;
V_239:
V_43 = F_59 ( V_9 ) ;
V_244 = V_9 -> V_65 & V_9 -> V_79 ;
F_61 ( V_9 , V_238 , V_244 , V_43 ) ;
while ( V_244 != V_238 ) {
V_244 = ++ V_9 -> V_65 & V_9 -> V_79 ;
if ( V_43 && V_43 -> V_83 == V_244 ) {
V_9 -> V_77 [ V_9 -> V_78 ++ & V_9 -> V_79 ] = NULL ;
F_23 ( V_9 , V_43 , V_260 ) ;
V_43 = F_59 ( V_9 ) ;
}
F_61 ( V_9 , V_238 , V_244 , V_43 ) ;
V_82 ++ ;
}
if ( ( V_258 & V_9 -> V_204 ) && ! V_259 ) {
T_4 V_243 ;
V_243 = F_169 ( V_9 -> V_72 ) & V_9 -> V_79 ;
if ( V_243 != V_238 ) {
V_238 = ( T_4 ) F_13 ( V_9 , F_22 ( V_241 ) ) ;
V_259 = 1 ;
goto V_239;
}
}
V_9 -> V_261 = V_258 ;
if ( V_82 )
F_62 ( V_9 , F_63 ( V_9 ) ) ;
}
void F_173 ( struct V_8 * V_9 , T_2 V_258 )
{
F_174 ( V_9 , V_258 ) ;
F_52 ( & V_9 -> V_52 ) ;
F_21 ( V_9 , V_199 ) ;
if ( V_258 & V_9 -> V_204 )
V_9 -> V_262 ++ ;
else if ( V_258 & V_9 -> V_203 )
V_9 -> V_263 ++ ;
else if ( V_258 & V_9 -> V_202 )
V_9 -> V_264 ++ ;
F_65 ( V_9 , V_258 ) ;
F_53 ( & V_9 -> V_52 ) ;
}
void F_175 ( struct V_8 * V_9 , T_2 V_258 )
{
unsigned long V_31 ;
#ifdef F_57
F_17 ( V_9 -> V_12 , L_29 ,
V_9 -> V_13 ,
( unsigned long long ) V_258 ,
V_3 [ V_9 -> V_2 . V_70 ] ) ;
#endif
F_33 ( & V_9 -> V_69 , V_31 ) ;
F_52 ( & V_9 -> V_52 ) ;
if ( V_258 & V_265 )
F_54 ( V_9 , V_266 ) ;
if ( V_258 & ~ F_22 ( V_267 ) ) {
F_17 ( V_9 -> V_12 ,
L_30 ,
V_9 -> V_13 ,
( unsigned long long ) V_258 ,
V_3 [ V_9 -> V_2 . V_70 ] ) ;
F_176 ( V_9 ) ;
}
F_53 ( & V_9 -> V_52 ) ;
F_37 ( & V_9 -> V_69 , V_31 ) ;
}
static void F_73 ( struct V_8 * V_9 , unsigned V_93 )
{
T_2 V_268 = 0 ;
T_2 V_269 = 0 ;
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
V_268 |= F_22 ( V_270 ) ;
else
V_269 |= F_22 ( V_270 ) ;
if ( V_93 & V_100 )
V_268 |= F_22 ( V_271 ) ;
else
V_269 |= F_22 ( V_271 ) ;
if ( V_93 & V_102 )
V_268 |= F_22 ( V_272 ) ;
else
V_269 |= F_22 ( V_272 ) ;
F_33 ( & V_9 -> V_206 , V_31 ) ;
V_9 -> V_273 |= V_268 ;
V_9 -> V_273 &= ~ V_269 ;
if ( V_93 & V_104 )
F_11 ( V_9 , F_22 ( V_274 ) ,
V_9 -> V_273 |
F_22 ( V_275 ) ) ;
else
F_11 ( V_9 , F_22 ( V_274 ) , V_9 -> V_273 ) ;
F_37 ( & V_9 -> V_206 , V_31 ) ;
#ifdef F_57
F_177 ( V_9 ) ;
#endif
}
static void F_178 ( struct V_8 * V_9 )
{
#ifdef F_57
F_17 ( V_9 -> V_12 , L_6 ,
V_9 -> V_13 , F_58 ( __FILE__ ) , __LINE__ , V_23 ) ;
#endif
F_11 ( V_9 , F_22 ( V_276 ) ,
( V_9 -> V_186 / 64 ) << F_22 ( V_277 ) ) ;
F_11 ( V_9 , F_22 ( V_276 ) ,
( ( V_9 -> V_186 / 64 ) << F_22 ( V_277 ) ) |
( 4ULL << F_22 ( V_278 ) ) ) ;
}
static inline void F_179 ( struct V_8 * V_9 , T_4 V_81 )
{
F_180 () ;
F_181 ( V_81 , V_9 -> V_210 ) ;
}
static void F_182 ( struct V_8 * V_9 )
{
T_2 V_19 ;
#ifdef F_57
F_17 ( V_9 -> V_12 , L_6 ,
V_9 -> V_13 , F_58 ( __FILE__ ) , __LINE__ , V_23 ) ;
#endif
F_178 ( V_9 ) ;
F_179 ( V_9 , 0 ) ;
* V_9 -> V_85 = 0 ;
V_19 = F_22 ( V_279 ) <<
F_22 ( V_280 ) ;
F_11 ( V_9 , F_22 ( V_281 ) , V_19 ) ;
}
static void F_183 ( struct V_8 * V_9 )
{
struct V_16 * V_12 = V_9 -> V_12 ;
F_11 ( V_9 , F_22 ( V_282 ) ,
F_184 ( V_12 ) ) ;
}
static void F_150 (
struct V_8 * V_9 ,
T_1 V_283 ,
T_9 V_192 )
{
T_5 V_284 , V_285 ;
#ifdef F_57
struct V_16 * V_12 = V_9 -> V_12 ;
F_17 ( V_12 , L_6 ,
V_9 -> V_13 , F_58 ( __FILE__ ) , __LINE__ , V_23 ) ;
#endif
F_11 ( V_9 , F_22 ( V_286 ) , V_9 -> V_187 ) ;
F_178 ( V_9 ) ;
F_179 ( V_9 , 0 ) ;
F_11 ( V_9 , F_22 ( V_287 ) , V_192 ) ;
F_11 ( V_9 , F_22 ( V_35 ) , 0 ) ;
F_11 ( V_9 , F_22 ( V_288 ) , V_9 -> V_184 ) ;
F_11 ( V_9 , F_22 ( V_289 ) ,
( ( T_2 ) V_283 << F_22 ( V_290 ) ) |
( ( T_2 ) ( V_283 * V_9 -> V_13 ) <<
F_22 ( V_291 ) ) ) ;
F_11 ( V_9 , F_22 ( V_292 ) , ~ 0ull ) ;
F_183 ( V_9 ) ;
V_285 = V_293 ;
V_284 = V_294 ;
F_11 ( V_9 , F_22 ( V_295 ) ,
( V_285 << V_296 ) |
( V_284 << V_297 ) ) ;
}
void F_177 ( struct V_8 * V_9 )
{
T_2 V_298 ;
unsigned V_27 ;
F_185 ( F_22 ( V_274 ) ) ;
F_185 ( F_22 ( V_58 ) ) ;
F_186 ( F_22 ( V_299 ) ) ;
F_186 ( F_22 ( V_300 ) ) ;
F_185 ( F_22 ( V_301 ) ) ;
F_185 ( F_22 ( V_292 ) ) ;
for ( V_27 = 0 ; V_27 < V_302 ; ++ V_27 ) {
F_187 ( V_303 ) ;
F_187 ( V_304 ) ;
F_187 ( V_305 ) ;
}
F_185 ( F_22 ( V_211 ) ) ;
F_185 ( F_22 ( V_241 ) ) ;
F_185 ( F_22 ( V_306 ) ) ;
F_185 ( F_22 ( V_307 ) ) ;
F_185 ( F_22 ( V_287 ) ) ;
F_185 ( F_22 ( V_35 ) ) ;
F_185 ( F_22 ( V_308 ) ) ;
F_185 ( F_22 ( V_289 ) ) ;
F_186 ( F_22 ( V_309 ) ) ;
F_186 ( F_22 ( V_310 ) ) ;
F_185 ( F_22 ( V_286 ) ) ;
F_185 ( F_22 ( V_276 ) ) ;
F_185 ( F_22 ( V_288 ) ) ;
F_185 ( F_22 ( V_282 ) ) ;
F_185 ( F_22 ( V_311 ) ) ;
F_185 ( F_22 ( V_312 ) ) ;
F_185 ( F_22 ( V_313 ) ) ;
F_185 ( F_22 ( V_314 ) ) ;
F_185 ( F_22 ( V_295 ) ) ;
}
static void F_176 ( struct V_8 * V_9 )
{
struct V_315 * V_185 ;
struct V_315 * V_316 ;
T_2 V_317 [ 2 ] ;
T_2 V_318 ;
T_5 V_319 ;
T_4 V_320 ;
T_4 V_80 , V_81 , V_30 ;
V_80 = V_9 -> V_65 & V_9 -> V_79 ;
V_81 = V_9 -> V_72 & V_9 -> V_79 ;
V_30 = F_63 ( V_9 ) ;
V_185 = V_9 -> V_185 ;
F_17 ( V_9 -> V_12 ,
L_32 ,
V_9 -> V_13 , V_80 , V_81 , V_30 ,
! F_156 ( & V_9 -> V_45 ) ) ;
while ( V_80 != V_81 ) {
char V_31 [ 6 ] = { 'x' , 'x' , 'x' , 'x' , 0 } ;
V_316 = & V_9 -> V_185 [ V_80 ] ;
V_317 [ 0 ] = F_168 ( V_316 -> V_227 [ 0 ] ) ;
V_317 [ 1 ] = F_168 ( V_316 -> V_227 [ 1 ] ) ;
V_31 [ 0 ] = ( V_317 [ 1 ] & V_214 ) ? 'I' : '-' ;
V_31 [ 1 ] = ( V_317 [ 1 ] & V_213 ) ?
'H' : '-' ;
V_31 [ 2 ] = ( V_317 [ 0 ] & V_321 ) ? 'F' : '-' ;
V_31 [ 3 ] = ( V_317 [ 0 ] & V_322 ) ? 'L' : '-' ;
V_318 = ( V_317 [ 0 ] >> V_323 )
& V_324 ;
V_319 = ( V_317 [ 1 ] >> V_325 )
& V_326 ;
V_320 = ( V_317 [ 0 ] >> V_327 )
& V_328 ;
F_17 ( V_9 -> V_12 ,
L_33 ,
V_80 , V_31 , V_318 , V_319 , V_320 ) ;
F_17 ( V_9 -> V_12 ,
L_34 ,
V_317 [ 0 ] , V_317 [ 1 ] ) ;
if ( V_317 [ 0 ] & V_321 )
F_17 ( V_9 -> V_12 ,
L_35 ,
( T_5 ) ( ( V_317 [ 1 ] &
V_329 ) >>
V_330 ) ,
( T_5 ) ( ( V_317 [ 1 ] &
V_228 ) >>
V_229 ) ,
( T_5 ) ( ( V_317 [ 1 ] &
V_331 ) >>
V_332 ) ) ;
V_80 ++ ;
V_80 &= V_9 -> V_79 ;
}
}
void F_188 ( struct V_156 * V_157 , struct V_8 * V_9 )
{
T_4 V_80 , V_81 ;
struct V_315 * V_316 ;
T_2 V_317 [ 2 ] ;
T_2 V_318 ;
T_5 V_319 ;
T_4 V_320 ;
V_80 = V_9 -> V_65 & V_9 -> V_79 ;
V_81 = F_169 ( V_9 -> V_72 ) & V_9 -> V_79 ;
F_115 ( V_157 , V_333 , V_9 -> V_13 ,
V_9 -> V_141 ,
F_1 ( V_9 -> V_2 . V_70 ) ,
( unsigned long long ) F_13 ( V_9 , F_22 ( V_274 ) ) ,
( unsigned long long ) F_13 ( V_9 , F_22 ( V_58 ) ) ,
( unsigned long long ) F_13 ( V_9 , F_22 ( V_301 ) ) ,
( unsigned long long ) F_13 ( V_9 , F_22 ( V_211 ) ) , V_81 ,
( unsigned long long ) F_13 ( V_9 , F_22 ( V_241 ) ) , V_80 ,
( unsigned long long ) F_168 ( * V_9 -> V_85 ) ,
( unsigned long long ) F_13 ( V_9 , F_22 ( V_289 ) ) ,
( unsigned long long ) F_13 ( V_9 , F_22 ( V_276 ) ) ,
( unsigned long long ) F_13 ( V_9 , F_22 ( V_287 ) ) ,
( unsigned long long ) V_9 -> V_261 ,
( unsigned long long ) V_9 -> V_207 ,
V_9 -> V_334 ,
V_9 -> V_78 ,
V_9 -> V_72 ,
V_9 -> V_65 ,
! F_156 ( & V_9 -> V_45 ) ,
V_9 -> V_335 ,
( unsigned long long ) F_13 ( V_9 , V_336 ) ) ;
while ( V_80 != V_81 ) {
char V_31 [ 6 ] = { 'x' , 'x' , 'x' , 'x' , 0 } ;
V_316 = & V_9 -> V_185 [ V_80 ] ;
V_317 [ 0 ] = F_168 ( V_316 -> V_227 [ 0 ] ) ;
V_317 [ 1 ] = F_168 ( V_316 -> V_227 [ 1 ] ) ;
V_31 [ 0 ] = ( V_317 [ 1 ] & V_214 ) ? 'I' : '-' ;
V_31 [ 1 ] = ( V_317 [ 1 ] & V_213 ) ?
'H' : '-' ;
V_31 [ 2 ] = ( V_317 [ 0 ] & V_321 ) ? 'F' : '-' ;
V_31 [ 3 ] = ( V_317 [ 0 ] & V_322 ) ? 'L' : '-' ;
V_318 = ( V_317 [ 0 ] >> V_323 )
& V_324 ;
V_319 = ( V_317 [ 1 ] >> V_325 )
& V_326 ;
V_320 = ( V_317 [ 0 ] >> V_327 )
& V_328 ;
F_115 ( V_157 ,
L_36 ,
V_80 , V_31 , V_318 , V_319 , V_320 ) ;
if ( V_317 [ 0 ] & V_321 )
F_115 ( V_157 , L_37 ,
( T_5 ) ( ( V_317 [ 1 ] &
V_329 ) >>
V_330 ) ,
( T_5 ) ( ( V_317 [ 1 ] &
V_228 ) >>
V_229 ) ) ;
V_80 = ( V_80 + 1 ) & V_9 -> V_79 ;
}
}
static inline T_2 F_189 ( struct V_8 * V_9 , T_2 V_337 )
{
T_5 V_338 = ( V_9 -> V_72 >> V_9 -> V_201 ) & 3 ;
V_337 &= ~ V_339 ;
V_337 |= ( ( T_2 ) V_338 & V_326 )
<< V_325 ;
return V_337 ;
}
static inline T_4 F_190 ( struct V_8 * V_9 , struct V_36 * V_37 )
{
int V_27 ;
T_4 V_81 ;
struct V_222 * V_223 = V_37 -> V_223 ;
T_5 V_231 = 0 , V_232 = F_165 ( V_37 ) ;
V_81 = V_9 -> V_72 & V_9 -> V_79 ;
V_9 -> V_185 [ V_81 ] . V_227 [ 0 ] = F_191 ( V_223 -> V_227 [ 0 ] ) ;
V_9 -> V_185 [ V_81 ] . V_227 [ 1 ] = F_191 ( F_189 ( V_9 , V_223 -> V_227 [ 1 ] ) ) ;
F_192 ( V_9 , V_223 -> V_227 [ 0 ] , V_223 -> V_227 [ 1 ] ,
V_81 , & V_9 -> V_185 [ V_81 ] ) ;
V_81 = ++ V_9 -> V_72 & V_9 -> V_79 ;
V_223 ++ ;
if ( V_232 > V_233 )
V_231 = V_232 >> 1 ;
for ( V_27 = 1 ; V_27 < V_37 -> V_230 ; V_27 ++ , V_223 ++ ) {
T_2 V_337 ;
V_9 -> V_185 [ V_81 ] . V_227 [ 0 ] = F_191 ( V_223 -> V_227 [ 0 ] ) ;
if ( V_231 ) {
V_337 = V_223 -> V_227 [ 1 ] ;
V_231 -- ;
} else {
V_337 = F_189 ( V_9 , V_223 -> V_227 [ 1 ] ) ;
}
V_9 -> V_185 [ V_81 ] . V_227 [ 1 ] = F_191 ( V_337 ) ;
F_192 ( V_9 , V_223 -> V_227 [ 0 ] , V_337 ,
V_81 , & V_9 -> V_185 [ V_81 ] ) ;
V_81 = ++ V_9 -> V_72 & V_9 -> V_79 ;
}
V_37 -> V_83 = V_81 ;
#ifdef F_24
V_37 -> V_41 = V_9 -> V_340 ++ ;
F_193 ( V_9 , V_37 -> V_41 ) ;
F_26 ( V_9 -> V_77 [ V_9 -> V_334 & V_9 -> V_79 ] ) ;
#endif
V_9 -> V_77 [ V_9 -> V_334 ++ & V_9 -> V_79 ] = V_37 ;
V_9 -> V_84 -= V_37 -> V_230 ;
return V_81 ;
}
static int F_194 (
struct V_8 * V_9 ,
struct V_39 * V_40 ,
struct V_36 * V_37 )
{
int V_142 ;
V_9 -> V_84 = F_63 ( V_9 ) ;
if ( V_37 -> V_230 <= V_9 -> V_84 )
return - V_341 ;
if ( V_40 && V_40 -> V_342 ) {
unsigned V_251 ;
V_251 = F_195 (
( const V_343 * ) & V_9 -> V_52 . V_344 ) ;
V_142 = V_40 -> V_342 ( V_9 , V_40 , V_37 , V_251 ) ;
if ( V_142 == - V_341 )
V_9 -> V_84 = F_63 ( V_9 ) ;
} else {
V_142 = - V_345 ;
}
return V_142 ;
}
int F_196 ( struct V_8 * V_9 ,
struct V_39 * V_40 ,
struct V_36 * V_37 )
{
int V_142 = 0 ;
T_4 V_81 ;
unsigned long V_31 ;
if ( F_79 ( V_37 -> V_346 ) )
return - V_115 ;
V_37 -> V_40 = V_40 ;
F_33 ( & V_9 -> V_69 , V_31 ) ;
V_239:
if ( F_79 ( ! F_40 ( V_9 ) ) )
goto V_347;
if ( F_79 ( V_37 -> V_230 > V_9 -> V_84 ) )
goto V_348;
V_81 = F_190 ( V_9 , V_37 ) ;
if ( V_40 )
F_197 ( V_40 ) ;
F_179 ( V_9 , V_81 ) ;
V_349:
F_37 ( & V_9 -> V_69 , V_31 ) ;
return V_142 ;
V_347:
if ( V_40 )
F_197 ( V_40 ) ;
V_37 -> V_83 = 0 ;
#ifdef F_24
V_37 -> V_41 = V_9 -> V_340 ++ ;
F_193 ( V_9 , V_37 -> V_41 ) ;
#endif
F_198 ( & V_9 -> V_46 ) ;
F_36 ( & V_37 -> V_47 , & V_9 -> V_45 ) ;
F_199 ( & V_9 -> V_46 ) ;
if ( V_40 ) {
V_40 -> V_350 ++ ;
V_40 -> V_108 += V_37 -> V_230 ;
}
F_55 ( & V_9 -> V_51 ) ;
V_142 = - V_351 ;
goto V_349;
V_348:
V_142 = F_194 ( V_9 , V_40 , V_37 ) ;
if ( V_142 == - V_341 ) {
V_142 = 0 ;
goto V_239;
}
V_9 -> V_335 ++ ;
goto V_349;
}
int F_200 ( struct V_8 * V_9 , struct V_39 * V_40 ,
struct V_352 * V_353 , T_1 * V_354 )
{
struct V_36 * V_37 , * V_355 ;
int V_142 = 0 ;
unsigned long V_31 ;
T_4 V_81 = V_356 ;
T_1 V_357 = 0 , V_358 = 0 , V_359 ;
F_33 ( & V_9 -> V_69 , V_31 ) ;
V_239:
F_34 (tx, tx_next, tx_list, list) {
V_37 -> V_40 = V_40 ;
if ( F_79 ( ! F_40 ( V_9 ) ) )
goto V_347;
if ( F_79 ( V_37 -> V_230 > V_9 -> V_84 ) )
goto V_348;
if ( F_79 ( V_37 -> V_346 ) ) {
V_142 = - V_115 ;
goto V_360;
}
F_35 ( & V_37 -> V_47 ) ;
V_81 = F_190 ( V_9 , V_37 ) ;
V_357 ++ ;
if ( V_81 != V_356 &&
( V_357 & V_361 ) == 0 ) {
F_179 ( V_9 , V_81 ) ;
V_81 = V_356 ;
}
}
V_360:
V_359 = V_357 + V_358 ;
if ( V_40 )
F_201 ( V_40 , V_359 ) ;
if ( V_81 != V_356 )
F_179 ( V_9 , V_81 ) ;
F_37 ( & V_9 -> V_69 , V_31 ) ;
* V_354 = V_359 ;
return V_142 ;
V_347:
F_198 ( & V_9 -> V_46 ) ;
F_34 (tx, tx_next, tx_list, list) {
V_37 -> V_40 = V_40 ;
F_35 ( & V_37 -> V_47 ) ;
V_37 -> V_83 = 0 ;
#ifdef F_24
V_37 -> V_41 = V_9 -> V_340 ++ ;
F_193 ( V_9 , V_37 -> V_41 ) ;
#endif
F_36 ( & V_37 -> V_47 , & V_9 -> V_45 ) ;
V_358 ++ ;
if ( V_40 ) {
V_40 -> V_350 ++ ;
V_40 -> V_108 += V_37 -> V_230 ;
}
}
F_199 ( & V_9 -> V_46 ) ;
F_55 ( & V_9 -> V_51 ) ;
V_142 = - V_351 ;
goto V_360;
V_348:
V_142 = F_194 ( V_9 , V_40 , V_37 ) ;
if ( V_142 == - V_341 ) {
V_142 = 0 ;
goto V_239;
}
V_9 -> V_335 ++ ;
goto V_360;
}
static void F_46 ( struct V_8 * V_9 , enum V_362 V_363 )
{
unsigned long V_31 ;
F_33 ( & V_9 -> V_69 , V_31 ) ;
F_52 ( & V_9 -> V_52 ) ;
F_54 ( V_9 , V_363 ) ;
if ( V_9 -> V_2 . V_70 == V_71 )
F_62 ( V_9 , F_63 ( V_9 ) ) ;
F_53 ( & V_9 -> V_52 ) ;
F_37 ( & V_9 -> V_69 , V_31 ) ;
}
static void F_54 ( struct V_8 * V_9 ,
enum V_362 V_363 )
{
struct V_4 * V_5 = & V_9 -> V_2 ;
int V_364 = 0 ;
#ifdef F_57
F_17 ( V_9 -> V_12 , L_38 , V_9 -> V_13 ,
V_3 [ V_5 -> V_70 ] ,
V_365 [ V_363 ] ) ;
#endif
switch ( V_5 -> V_70 ) {
case V_208 :
switch ( V_363 ) {
case V_221 :
break;
case V_218 :
V_5 -> V_106 = 1 ;
case V_220 :
F_2 ( & V_9 -> V_2 ) ;
F_71 ( V_9 ,
V_366 ) ;
break;
case V_60 :
break;
case V_76 :
break;
case V_86 :
F_66 ( V_9 ) ;
break;
case V_367 :
break;
case V_266 :
break;
case V_219 :
break;
case V_368 :
break;
case V_369 :
break;
case V_370 :
break;
case V_371 :
break;
case V_73 :
break;
}
break;
case V_366 :
switch ( V_363 ) {
case V_221 :
F_71 ( V_9 , V_208 ) ;
F_66 ( V_9 ) ;
break;
case V_220 :
break;
case V_60 :
F_71 ( V_9 ,
V_372 ) ;
F_69 ( V_9 ) ;
break;
case V_76 :
break;
case V_218 :
V_5 -> V_106 = 1 ;
break;
case V_86 :
break;
case V_367 :
break;
case V_266 :
F_55 ( & V_9 -> V_53 ) ;
break;
case V_219 :
V_5 -> V_106 = 0 ;
break;
case V_368 :
break;
case V_369 :
break;
case V_370 :
break;
case V_371 :
break;
case V_73 :
break;
}
break;
case V_372 :
switch ( V_363 ) {
case V_221 :
F_71 ( V_9 , V_208 ) ;
F_66 ( V_9 ) ;
break;
case V_220 :
break;
case V_60 :
break;
case V_76 :
F_182 ( V_9 ) ;
F_71 ( V_9 , V_5 -> V_106 ?
V_71 :
V_373 ) ;
break;
case V_218 :
V_5 -> V_106 = 1 ;
break;
case V_86 :
break;
case V_367 :
break;
case V_266 :
break;
case V_219 :
V_5 -> V_106 = 0 ;
break;
case V_368 :
break;
case V_369 :
break;
case V_370 :
break;
case V_371 :
break;
case V_73 :
break;
}
break;
case V_373 :
switch ( V_363 ) {
case V_221 :
F_71 ( V_9 , V_208 ) ;
F_66 ( V_9 ) ;
break;
case V_220 :
break;
case V_60 :
break;
case V_76 :
break;
case V_218 :
F_71 ( V_9 , V_71 ) ;
V_5 -> V_106 = 1 ;
break;
case V_86 :
break;
case V_367 :
break;
case V_266 :
F_71 ( V_9 , V_374 ) ;
F_55 ( & V_9 -> V_53 ) ;
break;
case V_219 :
break;
case V_371 :
case V_368 :
F_71 ( V_9 , V_375 ) ;
F_202 ( & V_9 -> V_12 -> V_87 ) ;
F_68 ( & V_9 -> V_12 -> V_88 ) ;
break;
case V_369 :
break;
case V_370 :
break;
case V_73 :
break;
}
break;
case V_376 :
switch ( V_363 ) {
case V_221 :
F_71 ( V_9 , V_208 ) ;
break;
case V_220 :
break;
case V_60 :
break;
case V_76 :
break;
case V_218 :
V_5 -> V_106 = 1 ;
break;
case V_86 :
F_71 ( V_9 , V_377 ) ;
F_69 ( V_9 ) ;
break;
case V_367 :
break;
case V_266 :
break;
case V_219 :
V_5 -> V_106 = 0 ;
break;
case V_368 :
break;
case V_369 :
break;
case V_370 :
break;
case V_371 :
V_5 -> V_106 = 0 ;
break;
case V_73 :
break;
}
break;
case V_377 :
switch ( V_363 ) {
case V_221 :
F_71 ( V_9 , V_208 ) ;
F_70 ( & V_9 -> F_64 ) ;
break;
case V_220 :
break;
case V_60 :
break;
case V_76 :
F_182 ( V_9 ) ;
F_71 ( V_9 , V_5 -> V_106 ?
V_71 :
V_373 ) ;
break;
case V_218 :
V_5 -> V_106 = 1 ;
break;
case V_86 :
break;
case V_367 :
break;
case V_266 :
break;
case V_219 :
V_5 -> V_106 = 0 ;
break;
case V_368 :
break;
case V_369 :
break;
case V_370 :
break;
case V_371 :
V_5 -> V_106 = 0 ;
break;
case V_73 :
break;
}
break;
case V_374 :
switch ( V_363 ) {
case V_221 :
F_71 ( V_9 , V_208 ) ;
F_70 ( & V_9 -> F_64 ) ;
break;
case V_220 :
break;
case V_60 :
F_71 ( V_9 , V_376 ) ;
F_70 ( & V_9 -> F_64 ) ;
break;
case V_76 :
break;
case V_218 :
V_5 -> V_106 = 1 ;
break;
case V_86 :
break;
case V_367 :
break;
case V_266 :
F_55 ( & V_9 -> V_53 ) ;
break;
case V_219 :
V_5 -> V_106 = 0 ;
break;
case V_368 :
break;
case V_369 :
break;
case V_370 :
break;
case V_371 :
V_5 -> V_106 = 0 ;
break;
case V_73 :
break;
}
break;
case V_378 :
switch ( V_363 ) {
case V_221 :
F_71 ( V_9 , V_208 ) ;
F_70 ( & V_9 -> F_64 ) ;
break;
case V_220 :
break;
case V_60 :
F_71 ( V_9 , V_376 ) ;
F_70 ( & V_9 -> F_64 ) ;
break;
case V_76 :
break;
case V_218 :
V_5 -> V_106 = 1 ;
break;
case V_86 :
break;
case V_367 :
break;
case V_266 :
F_55 ( & V_9 -> V_53 ) ;
break;
case V_219 :
V_5 -> V_106 = 0 ;
break;
case V_368 :
break;
case V_369 :
break;
case V_370 :
break;
case V_371 :
break;
case V_73 :
break;
}
break;
case V_375 :
switch ( V_363 ) {
case V_221 :
F_71 ( V_9 , V_208 ) ;
F_70 ( & V_9 -> F_64 ) ;
break;
case V_220 :
break;
case V_60 :
break;
case V_76 :
break;
case V_218 :
V_5 -> V_106 = 1 ;
break;
case V_86 :
break;
case V_367 :
break;
case V_266 :
break;
case V_219 :
V_5 -> V_106 = 0 ;
break;
case V_368 :
break;
case V_369 :
F_71 ( V_9 , V_379 ) ;
F_70 ( & V_9 -> F_64 ) ;
break;
case V_370 :
break;
case V_371 :
break;
case V_73 :
break;
}
break;
case V_379 :
switch ( V_363 ) {
case V_221 :
F_71 ( V_9 , V_208 ) ;
F_70 ( & V_9 -> F_64 ) ;
break;
case V_220 :
break;
case V_60 :
break;
case V_76 :
break;
case V_218 :
V_5 -> V_106 = 1 ;
break;
case V_86 :
F_202 ( & V_9 -> V_12 -> V_87 ) ;
F_68 ( & V_9 -> V_12 -> V_88 ) ;
break;
case V_367 :
break;
case V_266 :
break;
case V_219 :
V_5 -> V_106 = 0 ;
break;
case V_368 :
break;
case V_369 :
break;
case V_370 :
F_182 ( V_9 ) ;
F_71 ( V_9 , V_5 -> V_106 ?
V_71 :
V_373 ) ;
break;
case V_371 :
break;
case V_73 :
break;
}
break;
case V_71 :
switch ( V_363 ) {
case V_221 :
F_71 ( V_9 , V_208 ) ;
F_70 ( & V_9 -> F_64 ) ;
break;
case V_220 :
break;
case V_60 :
break;
case V_76 :
break;
case V_218 :
break;
case V_86 :
break;
case V_367 :
break;
case V_266 :
V_364 = 1 ;
F_47 ( V_9 ) ;
case V_73 :
F_71 ( V_9 , V_374 ) ;
F_55 ( & V_9 -> V_53 ) ;
break;
case V_219 :
F_71 ( V_9 , V_378 ) ;
break;
case V_371 :
V_5 -> V_106 = 0 ;
case V_368 :
F_71 ( V_9 , V_375 ) ;
F_202 ( & V_9 -> V_12 -> V_87 ) ;
F_68 ( & V_9 -> V_12 -> V_88 ) ;
break;
case V_369 :
break;
case V_370 :
break;
}
break;
}
V_5 -> V_380 = V_363 ;
if ( V_364 )
F_65 ( V_9 , 0 ) ;
}
static int F_203 ( struct V_16 * V_12 , struct V_36 * V_37 )
{
int V_27 ;
if ( F_79 ( ( V_37 -> V_230 == ( V_381 - 1 ) ) ) ) {
if ( ! V_37 -> V_346 ) {
V_37 -> V_235 = V_381 ;
} else if ( ! V_37 -> V_234 ) {
V_37 -> V_234 = F_204 ( V_37 -> V_346 + sizeof( T_1 ) ,
V_382 ) ;
if ( ! V_37 -> V_234 )
goto V_383;
V_37 -> V_384 = 0 ;
}
return 0 ;
}
if ( F_79 ( V_37 -> V_230 == V_381 ) )
goto V_383;
V_37 -> V_223 = F_205 (
V_381 ,
sizeof( struct V_222 ) ,
V_382 ) ;
if ( ! V_37 -> V_223 )
goto V_383;
V_37 -> V_235 = V_381 - 1 ;
for ( V_27 = 0 ; V_27 < V_37 -> V_230 ; V_27 ++ )
V_37 -> V_223 [ V_27 ] = V_37 -> V_236 [ V_27 ] ;
return 0 ;
V_383:
F_27 ( V_12 , V_37 ) ;
return - V_145 ;
}
int F_206 ( struct V_16 * V_12 , struct V_36 * V_37 ,
int type , void * V_385 , struct V_386 * V_386 ,
unsigned long V_387 , T_4 V_320 )
{
int V_388 , V_121 ;
T_10 V_318 ;
V_121 = F_203 ( V_12 , V_37 ) ;
if ( V_121 ) {
F_27 ( V_12 , V_37 ) ;
return V_121 ;
}
if ( V_37 -> V_234 ) {
if ( type == V_389 ) {
F_27 ( V_12 , V_37 ) ;
return - V_115 ;
}
if ( type == V_226 ) {
V_385 = F_207 ( V_386 ) ;
V_385 += V_387 ;
} else if ( F_106 ( ! V_385 ) ) {
F_27 ( V_12 , V_37 ) ;
return - V_115 ;
}
memcpy ( V_37 -> V_234 + V_37 -> V_384 , V_385 , V_320 ) ;
V_37 -> V_384 += V_320 ;
if ( type == V_226 )
F_208 ( V_386 ) ;
if ( V_37 -> V_346 - V_37 -> V_384 )
return 0 ;
V_388 = V_37 -> V_390 & ( sizeof( T_1 ) - 1 ) ;
if ( V_388 ) {
V_388 = sizeof( T_1 ) - V_388 ;
memset ( V_37 -> V_234 + V_37 -> V_384 , 0 , V_388 ) ;
V_37 -> V_390 += V_388 ;
V_37 -> V_346 += V_388 ;
}
V_318 = F_209 ( & V_12 -> V_178 -> V_179 ,
V_37 -> V_234 ,
V_37 -> V_346 ,
V_225 ) ;
if ( F_79 ( F_210 ( & V_12 -> V_178 -> V_179 , V_318 ) ) ) {
F_27 ( V_12 , V_37 ) ;
return - V_391 ;
}
V_37 -> V_235 = V_381 ;
return F_211 ( V_12 , V_224 , V_37 ,
V_318 , V_37 -> V_346 ) ;
}
return 1 ;
}
void F_212 ( struct V_16 * V_12 , T_2 V_125 , T_1 V_392 )
{
struct V_8 * V_9 ;
int V_27 ;
T_2 V_393 ;
V_393 = ( ( V_125 & F_22 ( V_394 ) ) <<
F_22 ( V_395 ) ) |
( ( ( V_392 & V_125 ) & F_22 ( V_396 ) ) <<
F_22 ( V_397 ) ) ;
for ( V_27 = 0 ; V_27 < V_12 -> V_28 ; V_27 ++ ) {
F_213 ( V_398 , L_39 ,
V_27 , ( T_1 ) V_393 ) ;
V_9 = & V_12 -> V_29 [ V_27 ] ;
F_11 ( V_9 , F_22 ( V_314 ) , V_393 ) ;
}
}
int F_214 ( struct V_16 * V_12 , struct V_36 * V_37 )
{
int V_121 = 0 ;
V_37 -> V_230 ++ ;
if ( ( F_79 ( V_37 -> V_230 == V_37 -> V_235 ) ) ) {
V_121 = F_203 ( V_12 , V_37 ) ;
if ( V_121 ) {
F_27 ( V_12 , V_37 ) ;
return V_121 ;
}
}
F_215 (
V_37 ,
V_389 ,
V_12 -> V_180 ,
sizeof( T_1 ) - ( V_37 -> V_390 & ( sizeof( T_1 ) - 1 ) ) ) ;
F_216 ( V_12 , V_37 ) ;
return V_121 ;
}
void F_217 (
struct V_36 * V_37 ,
T_5 V_399 ,
T_5 V_400 ,
T_1 * V_401 ,
T_5 V_402 )
{
T_1 V_27 , V_403 = 0 , V_317 = 0 ;
T_5 V_232 ;
F_26 ( V_399 > 9 || ( V_402 & 3 ) || V_402 == 4 ) ;
if ( V_399 == 1 )
V_232 = V_233 ;
else if ( V_399 <= 5 )
V_232 = V_404 ;
else
V_232 = V_405 ;
V_37 -> V_230 ++ ;
switch ( V_232 ) {
case V_405 :
V_37 -> V_230 ++ ;
V_37 -> V_236 [ 2 ] . V_227 [ 0 ] = 0 ;
V_37 -> V_236 [ 2 ] . V_227 [ 1 ] = 0 ;
case V_404 :
V_37 -> V_230 ++ ;
V_37 -> V_236 [ 1 ] . V_227 [ 0 ] = 0 ;
V_37 -> V_236 [ 1 ] . V_227 [ 1 ] = 0 ;
break;
}
V_402 >>= 2 ;
V_37 -> V_236 [ 0 ] . V_227 [ 1 ] |=
( ( ( T_2 ) V_400 & V_406 )
<< V_330 ) |
( ( ( T_2 ) V_402 & V_407 )
<< V_332 ) |
( ( ( T_2 ) V_232 & V_408 )
<< V_229 ) |
( ( ( T_2 ) V_401 [ 0 ] & V_409 )
<< V_410 ) ;
for ( V_27 = 0 ; V_27 < ( V_399 - 1 ) ; V_27 ++ ) {
if ( ! V_403 && ! ( V_27 & 2 ) )
V_317 ++ ;
V_37 -> V_236 [ V_317 ] . V_227 [ ! ! ( V_27 & 2 ) ] |=
( ( ( T_2 ) V_401 [ V_27 + 1 ] )
<< V_403 ) ;
V_403 = ( V_403 + 32 ) & 63 ;
}
}
int F_218 ( struct V_8 * V_9 )
{
int V_411 ;
int V_412 ;
if ( ! V_9 ) {
F_219 ( V_9 , - V_115 ) ;
return - V_115 ;
}
while ( 1 ) {
V_411 = F_220 ( F_169 ( V_9 -> V_207 ) ) ;
if ( V_411 > 31 ) {
F_219 ( V_9 , - V_391 ) ;
return - V_391 ;
}
V_412 = F_221 ( V_411 , & V_9 -> V_207 ) ;
if ( ! V_412 )
break;
F_222 () ;
}
F_219 ( V_9 , V_411 ) ;
return V_411 ;
}
void F_223 ( struct V_8 * V_9 , int V_413 )
{
if ( ! V_9 )
return;
F_224 ( V_9 , V_413 ) ;
if ( V_413 < 0 || V_413 > 31 )
return;
F_225 ( V_413 , & V_9 -> V_207 ) ;
}
void F_226 ( struct V_16 * V_12 , int V_414 )
{
int V_27 ;
enum V_362 V_363 = V_414 ? V_371 :
V_368 ;
F_67 ( & V_12 -> V_87 , V_12 -> V_28 ) ;
for ( V_27 = 0 ; V_27 < V_12 -> V_28 ; V_27 ++ )
F_46 ( & V_12 -> V_29 [ V_27 ] , V_363 ) ;
}
void F_227 ( struct V_16 * V_12 )
{
int V_27 ;
int V_142 ;
V_142 = F_228 ( V_12 -> V_88 ,
F_229 ( & V_12 -> V_87 ) <=
0 ) ;
if ( V_142 || F_229 ( & V_12 -> V_87 ) < 0 )
return;
F_67 ( & V_12 -> V_87 , V_12 -> V_28 ) ;
for ( V_27 = 0 ; V_27 < V_12 -> V_28 ; V_27 ++ )
F_46 ( & V_12 -> V_29 [ V_27 ] , V_369 ) ;
( void ) F_228 ( V_12 -> V_88 ,
F_229 ( & V_12 -> V_87 ) <= 0 ) ;
}
void F_230 ( struct V_16 * V_12 )
{
int V_27 ;
for ( V_27 = 0 ; V_27 < V_12 -> V_28 ; V_27 ++ )
F_46 ( & V_12 -> V_29 [ V_27 ] ,
V_370 ) ;
}
void F_231 (
struct V_8 * V_9 )
{
F_232 ( V_9 , V_9 -> V_203 ) ;
F_233 ( V_9 -> V_12 ,
V_415 + ( 8 * ( V_416 / 64 ) ) ,
V_9 -> V_203 ) ;
}
