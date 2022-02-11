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
V_128 = F_88 ( V_12 -> V_135 , & V_133 ,
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
if ( V_113 >= F_102 ( V_128 -> V_124 ) ) {
V_142 = - V_115 ;
goto V_134;
}
V_128 = F_88 ( V_12 -> V_135 , & V_141 ,
V_136 ) ;
if ( ! V_128 ) {
V_128 = F_103 ( sizeof( * V_128 ) , V_144 ) ;
if ( ! V_128 ) {
V_142 = - V_145 ;
goto V_134;
}
V_128 -> V_124 [ V_113 ] = F_103 ( V_143 , V_144 ) ;
if ( ! V_128 -> V_124 [ V_113 ] ) {
F_104 ( V_128 ) ;
V_142 = - V_145 ;
goto V_134;
}
V_128 -> V_133 = V_141 ;
V_128 -> V_124 [ V_113 ] -> V_125 = 0 ;
V_128 -> V_124 [ V_113 ] -> V_138 = 1 ;
V_128 -> V_124 [ V_113 ] -> V_9 [ 0 ] = V_9 ;
V_142 = F_105 ( V_12 -> V_135 ,
& V_128 -> V_150 ,
V_136 ) ;
if ( V_142 ) {
F_104 ( V_128 -> V_124 [ V_113 ] ) ;
F_104 ( V_128 ) ;
F_17 ( V_9 -> V_12 , L_8 ,
V_141 ) ;
goto V_134;
}
} else {
int V_138 , pow ;
if ( ! V_128 -> V_124 [ V_113 ] )
V_128 -> V_124 [ V_113 ] = F_103 ( V_143 , V_144 ) ;
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
V_128 = F_88 ( V_12 -> V_135 , & V_141 ,
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
V_142 = F_106 ( V_12 -> V_135 ,
& V_128 -> V_150 ,
V_136 ) ;
F_107 ( V_142 ) ;
for ( V_27 = 0 ; V_27 < V_152 ; V_27 ++ )
F_104 ( V_128 -> V_124 [ V_27 ] ) ;
F_104 ( V_128 ) ;
}
}
}
F_108 ( & V_9 -> V_149 , V_140 ) ;
V_134:
F_109 ( & V_148 ) ;
V_146:
F_94 ( V_125 ) ;
F_94 ( V_140 ) ;
return V_142 ? : F_110 ( V_139 , V_153 ) ;
}
T_6 F_111 ( struct V_8 * V_9 , char * V_139 )
{
F_98 ( & V_148 ) ;
if ( F_112 ( & V_9 -> V_149 ) )
snprintf ( V_139 , V_153 , L_9 , L_10 ) ;
else
F_113 ( true , V_139 , & V_9 -> V_149 ) ;
F_109 ( & V_148 ) ;
return F_110 ( V_139 , V_153 ) ;
}
static void F_114 ( void * V_154 , void * V_155 )
{
struct V_127 * V_128 = V_154 ;
int V_27 ;
for ( V_27 = 0 ; V_27 < V_152 ; V_27 ++ )
F_104 ( V_128 -> V_124 [ V_27 ] ) ;
F_104 ( V_128 ) ;
}
void F_115 ( struct V_156 * V_157 ,
struct V_16 * V_12 ,
unsigned long V_158 )
{
struct V_127 * V_128 ;
int V_27 , V_159 ;
V_128 = F_88 ( V_12 -> V_135 , & V_158 ,
V_136 ) ;
if ( ! V_128 )
return;
F_116 ( V_157 , L_11 , V_158 ) ;
for ( V_27 = 0 ; V_27 < V_152 ; V_27 ++ ) {
if ( ! V_128 -> V_124 [ V_27 ] || ! V_128 -> V_124 [ V_27 ] -> V_138 )
continue;
F_116 ( V_157 , L_12 , V_27 ) ;
for ( V_159 = 0 ; V_159 < V_128 -> V_124 [ V_27 ] -> V_138 ; V_159 ++ ) {
if ( ! V_128 -> V_124 [ V_27 ] -> V_9 [ V_159 ] )
continue;
if ( V_159 > 0 )
F_117 ( V_157 , L_13 ) ;
F_116 ( V_157 , L_14 ,
V_128 -> V_124 [ V_27 ] -> V_9 [ V_159 ] -> V_13 ) ;
}
F_117 ( V_157 , L_15 ) ;
}
F_117 ( V_157 , L_16 ) ;
}
static void F_118 ( struct V_111 * V_112 )
{
int V_27 ;
for ( V_27 = 0 ; V_112 && V_27 < V_112 -> V_160 ; V_27 ++ )
F_104 ( V_112 -> V_124 [ V_27 ] ) ;
F_104 ( V_112 ) ;
}
static void F_119 ( struct V_161 * V_47 )
{
struct V_111 * V_112 = F_5 ( V_47 , struct V_111 , V_47 ) ;
F_118 ( V_112 ) ;
}
int F_120 ( struct V_16 * V_12 , T_5 V_162 , T_5 V_122 , T_5 * V_163 )
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
V_170 = F_103 (
sizeof( struct V_111 ) +
F_90 ( V_122 ) *
sizeof( struct V_119 * ) ,
V_144 ) ;
if ( ! V_170 )
goto V_172;
V_170 -> V_160 = V_122 ;
V_170 -> V_173 = F_90 ( V_122 ) ;
V_170 -> V_125 = ( 1 << F_121 ( V_170 -> V_173 ) ) - 1 ;
for ( V_27 = 0 ; V_27 < V_114 ; V_27 ++ )
V_170 -> V_117 [ V_27 ] = - 1 ;
for ( V_27 = 0 ; V_27 < V_170 -> V_173 ; V_27 ++ ) {
int V_174 = V_166 ;
if ( V_27 < V_170 -> V_160 ) {
int V_143 = F_90 ( V_163 [ V_27 ] ) ;
V_170 -> V_124 [ V_27 ] = F_103 (
sizeof( struct V_119 ) +
V_143 * sizeof( struct V_8 * ) ,
V_144 ) ;
if ( ! V_170 -> V_124 [ V_27 ] )
goto V_172;
V_170 -> V_124 [ V_27 ] -> V_125 = ( 1 << F_121 ( V_143 ) ) - 1 ;
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
F_122 ( & V_12 -> V_175 ) ;
V_169 = F_123 ( V_12 -> V_116 ,
F_124 ( & V_12 -> V_175 ) ) ;
F_125 ( V_12 -> V_116 , V_170 ) ;
F_126 ( & V_12 -> V_175 ) ;
if ( V_169 )
F_127 ( & V_169 -> V_47 , F_119 ) ;
return 0 ;
V_172:
F_118 ( V_170 ) ;
return - V_145 ;
}
static void F_128 ( struct V_16 * V_12 , T_7 V_176 )
{
T_7 V_27 ;
struct V_8 * V_9 ;
if ( V_12 -> V_177 ) {
F_129 ( & V_12 -> V_178 -> V_179 , 4 ,
( void * ) V_12 -> V_177 ,
V_12 -> V_180 ) ;
V_12 -> V_177 = NULL ;
V_12 -> V_180 = 0 ;
}
if ( V_12 -> V_181 ) {
F_129 ( & V_12 -> V_178 -> V_179 , V_12 -> V_182 ,
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
F_129 (
& V_12 -> V_178 -> V_179 ,
V_9 -> V_186 * sizeof( T_2 [ 2 ] ) ,
V_9 -> V_185 ,
V_9 -> V_187
) ;
V_9 -> V_185 = NULL ;
V_9 -> V_187 = 0 ;
}
F_130 ( V_9 -> V_77 ) ;
V_9 -> V_77 = NULL ;
}
F_122 ( & V_12 -> V_175 ) ;
F_118 ( F_131 ( V_12 -> V_116 ) ) ;
F_132 ( V_12 -> V_116 , NULL ) ;
F_126 ( & V_12 -> V_175 ) ;
F_133 () ;
F_104 ( V_12 -> V_29 ) ;
V_12 -> V_29 = NULL ;
if ( V_12 -> V_135 ) {
F_134 ( V_12 -> V_135 , F_114 , NULL ) ;
F_104 ( V_12 -> V_135 ) ;
V_12 -> V_135 = NULL ;
}
}
int F_135 ( struct V_16 * V_12 , T_5 V_162 )
{
unsigned V_13 ;
struct V_8 * V_9 ;
struct V_188 * V_189 ;
T_4 V_186 ;
void * V_190 ;
struct V_191 * V_192 = V_12 -> V_24 + V_162 ;
T_1 V_193 ;
T_9 V_194 = V_195 ;
T_7 V_176 = V_12 -> V_196 ;
int V_142 = - V_145 ;
if ( ! F_49 ( V_197 ) ) {
F_136 ( V_61 ) ;
return 0 ;
}
if ( V_198 &&
V_198 <= V_12 -> V_196 &&
V_198 >= V_122 )
V_176 = V_198 ;
F_137 ( V_12 , L_17 , V_198 ) ;
F_137 ( V_12 , L_18 , V_12 -> V_196 ) ;
F_137 ( V_12 , L_19 ,
V_12 -> V_199 ) ;
V_193 =
V_12 -> V_199 / ( V_176 * V_200 ) ;
F_138 ( & V_12 -> V_88 ) ;
F_67 ( & V_12 -> V_87 , 0 ) ;
V_186 = F_74 () ;
F_137 ( V_12 , L_20 ,
V_176 , V_186 ) ;
V_12 -> V_29 = F_139 ( V_176 , sizeof( * V_12 -> V_29 ) , V_144 ) ;
if ( ! V_12 -> V_29 )
return V_142 ;
V_194 = F_140 ( V_12 , V_194 ) ;
if ( ! V_201 )
V_201 = V_202 ;
for ( V_13 = 0 ; V_13 < V_176 ; ++ V_13 ) {
V_9 = & V_12 -> V_29 [ V_13 ] ;
V_9 -> V_12 = V_12 ;
V_9 -> V_192 = V_192 ;
V_9 -> V_13 = V_13 ;
V_9 -> V_186 = V_186 ;
V_9 -> V_84 = F_63 ( V_9 ) ;
V_9 -> V_203 = F_121 ( V_186 ) ;
V_9 -> V_79 = ( 1 << V_9 -> V_203 ) - 1 ;
V_9 -> V_204 = ( T_2 ) 1 << ( 0 * V_114 +
V_13 ) ;
V_9 -> V_205 = ( T_2 ) 1 << ( 1 * V_114 +
V_13 ) ;
V_9 -> V_206 = ( T_2 ) 1 << ( 2 * V_114 +
V_13 ) ;
V_9 -> V_207 = V_9 -> V_204 | V_9 -> V_205 |
V_9 -> V_206 ;
F_141 ( & V_9 -> V_69 ) ;
F_142 ( & V_9 -> V_52 ) ;
F_141 ( & V_9 -> V_208 ) ;
F_141 ( & V_9 -> V_46 ) ;
V_9 -> V_209 = 0xfffffffe00000000ULL ;
F_71 ( V_9 , V_210 ) ;
F_143 ( & V_9 -> V_2 . V_6 ) ;
F_144 ( & V_9 -> V_2 . V_7 ) ;
F_145 ( & V_9 -> V_45 ) ;
F_145 ( & V_9 -> V_211 ) ;
V_9 -> V_212 =
F_146 ( V_12 , V_13 , F_22 ( V_213 ) ) ;
if ( V_194 )
V_12 -> V_214 =
V_215 ;
else
V_12 -> V_214 =
V_216 ;
F_147 ( & V_9 -> F_56 , F_56 ,
( unsigned long ) V_9 ) ;
F_147 ( & V_9 -> F_64 , F_64 ,
( unsigned long ) V_9 ) ;
F_148 ( & V_9 -> V_53 , F_42 ) ;
F_148 ( & V_9 -> V_51 , F_38 ) ;
V_9 -> V_64 = 0 ;
F_149 ( & V_9 -> V_66 ,
F_51 , ( unsigned long ) V_9 ) ;
V_9 -> V_185 = F_150 (
& V_12 -> V_178 -> V_179 ,
V_186 * sizeof( T_2 [ 2 ] ) ,
& V_9 -> V_187 ,
V_144
) ;
if ( ! V_9 -> V_185 )
goto V_172;
V_9 -> V_77 =
F_139 ( V_186 , sizeof( struct V_36 * ) ,
V_144 ) ;
if ( ! V_9 -> V_77 )
V_9 -> V_77 =
F_151 (
sizeof( struct V_36 * ) *
V_186 ) ;
if ( ! V_9 -> V_77 )
goto V_172;
}
V_12 -> V_182 = V_217 * V_176 ;
V_12 -> V_181 = F_150 (
& V_12 -> V_178 -> V_179 ,
V_12 -> V_182 ,
& V_12 -> V_183 ,
V_144
) ;
if ( ! V_12 -> V_181 ) {
F_17 ( V_12 , L_21 ) ;
goto V_172;
}
V_12 -> V_177 = F_150 (
& V_12 -> V_178 -> V_179 ,
sizeof( T_1 ) ,
& V_12 -> V_180 ,
V_144
) ;
if ( ! V_12 -> V_177 ) {
F_17 ( V_12 , L_22 ) ;
goto V_172;
}
V_190 = ( void * ) V_12 -> V_181 ;
for ( V_13 = 0 ; V_13 < V_176 ; ++ V_13 ) {
unsigned long V_218 ;
V_9 = & V_12 -> V_29 [ V_13 ] ;
V_9 -> V_85 = V_190 ;
V_190 += V_217 ;
V_218 = ( unsigned long ) V_9 -> V_85 -
( unsigned long ) V_12 -> V_181 ;
V_9 -> V_184 = V_12 -> V_183 + V_218 ;
F_152 ( V_9 , V_193 , V_194 ) ;
}
V_12 -> V_31 |= V_171 ;
V_12 -> V_31 |= V_194 ? V_32 : 0 ;
V_12 -> V_28 = V_176 ;
V_142 = F_120 ( V_12 , V_162 , V_192 -> V_219 , NULL ) ;
if ( V_142 < 0 )
goto V_172;
V_189 = F_103 ( sizeof( * V_189 ) , V_144 ) ;
if ( ! V_189 ) {
V_142 = - V_145 ;
goto V_172;
}
V_142 = F_153 ( V_189 , & V_136 ) ;
if ( V_142 < 0 )
goto V_172;
V_12 -> V_135 = V_189 ;
F_137 ( V_12 , L_23 , V_12 -> V_28 ) ;
return 0 ;
V_172:
F_128 ( V_12 , V_176 ) ;
return V_142 ;
}
void F_154 ( struct V_16 * V_12 )
{
struct V_8 * V_9 ;
unsigned int V_27 ;
for ( V_27 = 0 ; V_27 < V_12 -> V_28 ; ++ V_27 ) {
V_9 = & V_12 -> V_29 [ V_27 ] ;
F_46 ( V_9 , V_220 ) ;
}
}
void F_155 ( struct V_16 * V_12 )
{
struct V_8 * V_9 ;
unsigned int V_27 ;
for ( V_27 = 0 ; V_27 < V_12 -> V_28 ; ++ V_27 ) {
V_9 = & V_12 -> V_29 [ V_27 ] ;
F_46 ( V_9 , V_221 ) ;
}
}
void F_156 ( struct V_16 * V_12 )
{
unsigned V_27 ;
struct V_8 * V_9 ;
for ( V_27 = 0 ; V_27 < V_12 -> V_28 ; ++ V_27 ) {
V_9 = & V_12 -> V_29 [ V_27 ] ;
F_46 ( V_9 , V_222 ) ;
}
}
void F_157 ( struct V_16 * V_12 )
{
unsigned V_13 ;
struct V_8 * V_9 ;
for ( V_13 = 0 ; V_12 -> V_29 && V_13 < V_12 -> V_28 ;
++ V_13 ) {
V_9 = & V_12 -> V_29 [ V_13 ] ;
if ( ! F_158 ( & V_9 -> V_211 ) )
F_17 ( V_12 , L_24 ,
V_9 -> V_13 ) ;
F_46 ( V_9 , V_223 ) ;
F_159 ( & V_9 -> V_66 ) ;
F_9 ( & V_9 -> V_2 ) ;
}
F_128 ( V_12 , V_12 -> V_28 ) ;
}
static inline void F_160 (
struct V_16 * V_12 ,
struct V_224 * V_225 )
{
switch ( F_161 ( V_225 ) ) {
case V_226 :
F_162 (
& V_12 -> V_178 -> V_179 ,
F_163 ( V_225 ) ,
F_164 ( V_225 ) ,
V_227 ) ;
break;
case V_228 :
F_165 (
& V_12 -> V_178 -> V_179 ,
F_163 ( V_225 ) ,
F_164 ( V_225 ) ,
V_227 ) ;
break;
}
}
static inline T_5 F_166 ( struct V_36 * V_37 )
{
return ( V_37 -> V_225 [ 0 ] . V_229 [ 1 ] & V_230 )
>> V_231 ;
}
void F_27 (
struct V_16 * V_12 ,
struct V_36 * V_37 )
{
T_4 V_27 ;
if ( V_37 -> V_232 ) {
T_5 V_233 = 0 , V_234 = F_166 ( V_37 ) ;
F_160 ( V_12 , & V_37 -> V_225 [ 0 ] ) ;
if ( V_234 > V_235 )
V_233 = V_234 >> 1 ;
for ( V_27 = 1 + V_233 ; V_27 < V_37 -> V_232 ; V_27 ++ )
F_160 ( V_12 , & V_37 -> V_225 [ V_27 ] ) ;
V_37 -> V_232 = 0 ;
}
F_104 ( V_37 -> V_236 ) ;
V_37 -> V_236 = NULL ;
if ( F_79 ( V_37 -> V_237 > F_102 ( V_37 -> V_238 ) ) ) {
V_37 -> V_237 = F_102 ( V_37 -> V_238 ) ;
F_104 ( V_37 -> V_225 ) ;
}
}
static inline T_4 F_167 ( struct V_8 * V_9 )
{
struct V_16 * V_12 = V_9 -> V_12 ;
int V_239 ;
T_4 V_240 ;
#ifdef F_57
F_17 ( V_9 -> V_12 , L_6 ,
V_9 -> V_13 , F_58 ( __FILE__ ) , __LINE__ , V_23 ) ;
#endif
V_241:
V_239 = F_49 ( V_242 ) && F_40 ( V_9 ) &&
( V_12 -> V_31 & V_32 ) ;
V_240 = V_239 ?
( T_4 ) F_168 ( * V_9 -> V_85 ) :
( T_4 ) F_13 ( V_9 , F_22 ( V_243 ) ) ;
if ( F_79 ( F_49 ( V_244 ) ) ) {
T_4 V_30 ;
T_4 V_245 ;
T_4 V_246 ;
int V_247 ;
V_246 = V_9 -> V_65 & V_9 -> V_79 ;
V_245 = F_169 ( V_9 -> V_72 ) & V_9 -> V_79 ;
V_30 = V_9 -> V_186 ;
if ( V_246 < V_245 )
V_247 = ( V_240 >= V_246 ) & ( V_240 <= V_245 ) ;
else if ( V_246 > V_245 )
V_247 = ( ( V_240 >= V_246 ) && ( V_240 < V_30 ) ) ||
( V_240 <= V_245 ) ;
else
V_247 = ( V_240 == V_246 ) ;
if ( F_79 ( ! V_247 ) ) {
F_17 ( V_12 , L_25 ,
V_9 -> V_13 ,
V_239 ? L_26 : L_27 ,
V_240 , V_246 , V_245 , V_30 ) ;
if ( V_239 ) {
V_239 = 0 ;
goto V_241;
}
V_240 = V_246 ;
}
}
return V_240 ;
}
static void F_62 ( struct V_8 * V_9 , T_9 V_248 )
{
struct V_39 * V_40 , * V_249 ;
struct V_39 * V_250 [ V_251 ] ;
T_9 V_27 , V_252 = 0 , V_253 , V_254 = 0 ;
struct V_36 * V_255 ;
struct V_256 * V_179 = & V_9 -> V_12 -> V_257 ;
T_5 V_258 = 0 ;
#ifdef F_57
F_17 ( V_9 -> V_12 , L_6 , V_9 -> V_13 ,
F_58 ( __FILE__ ) , __LINE__ , V_23 ) ;
F_17 ( V_9 -> V_12 , L_28 , V_248 ) ;
#endif
do {
V_253 = F_170 ( & V_179 -> V_259 ) ;
if ( ! F_158 ( & V_9 -> V_211 ) ) {
F_52 ( & V_179 -> V_259 ) ;
F_34 (
wait,
nw,
&sde->dmawait,
list) {
T_4 V_232 = 0 ;
if ( ! V_40 -> V_260 )
continue;
if ( V_252 == F_102 ( V_250 ) )
break;
if ( ! F_158 ( & V_40 -> V_78 ) ) {
V_255 = F_171 (
& V_40 -> V_78 ,
struct V_36 ,
V_47 ) ;
V_232 = V_255 -> V_232 ;
}
if ( V_232 > V_248 )
break;
V_248 -= V_232 ;
F_172 ( V_40 , & V_258 ,
V_252 , & V_254 ) ;
F_35 ( & V_40 -> V_47 ) ;
V_250 [ V_252 ++ ] = V_40 ;
}
F_53 ( & V_179 -> V_259 ) ;
break;
}
} while ( F_173 ( & V_179 -> V_259 , V_253 ) );
if ( V_252 )
V_250 [ V_254 ] -> V_260 ( V_250 [ V_254 ] , V_261 ) ;
for ( V_27 = 0 ; V_27 < V_252 ; V_27 ++ )
if ( V_27 != V_254 )
V_250 [ V_27 ] -> V_260 ( V_250 [ V_27 ] , V_261 ) ;
}
static void F_65 ( struct V_8 * V_9 , T_2 V_262 )
{
struct V_36 * V_43 = NULL ;
int V_82 = 0 ;
T_4 V_240 , V_246 ;
int V_263 = 0 ;
V_240 = F_167 ( V_9 ) ;
V_241:
V_43 = F_59 ( V_9 ) ;
V_246 = V_9 -> V_65 & V_9 -> V_79 ;
F_61 ( V_9 , V_240 , V_246 , V_43 ) ;
while ( V_246 != V_240 ) {
V_246 = ++ V_9 -> V_65 & V_9 -> V_79 ;
if ( V_43 && V_43 -> V_83 == V_246 ) {
V_9 -> V_77 [ V_9 -> V_78 ++ & V_9 -> V_79 ] = NULL ;
F_23 ( V_9 , V_43 , V_264 ) ;
V_43 = F_59 ( V_9 ) ;
}
F_61 ( V_9 , V_240 , V_246 , V_43 ) ;
V_82 ++ ;
}
if ( ( V_262 & V_9 -> V_206 ) && ! V_263 ) {
T_4 V_245 ;
V_245 = F_169 ( V_9 -> V_72 ) & V_9 -> V_79 ;
if ( V_245 != V_240 ) {
V_240 = ( T_4 ) F_13 ( V_9 , F_22 ( V_243 ) ) ;
V_263 = 1 ;
goto V_241;
}
}
V_9 -> V_265 = V_262 ;
if ( V_82 )
F_62 ( V_9 , F_63 ( V_9 ) ) ;
}
void F_174 ( struct V_8 * V_9 , T_2 V_262 )
{
F_175 ( V_9 , V_262 ) ;
F_52 ( & V_9 -> V_52 ) ;
F_21 ( V_9 , V_201 ) ;
if ( V_262 & V_9 -> V_206 )
V_9 -> V_266 ++ ;
else if ( V_262 & V_9 -> V_205 )
V_9 -> V_267 ++ ;
else if ( V_262 & V_9 -> V_204 )
V_9 -> V_268 ++ ;
F_65 ( V_9 , V_262 ) ;
F_53 ( & V_9 -> V_52 ) ;
}
void F_176 ( struct V_8 * V_9 , T_2 V_262 )
{
unsigned long V_31 ;
#ifdef F_57
F_17 ( V_9 -> V_12 , L_29 ,
V_9 -> V_13 ,
( unsigned long long ) V_262 ,
V_3 [ V_9 -> V_2 . V_70 ] ) ;
#endif
F_33 ( & V_9 -> V_69 , V_31 ) ;
F_52 ( & V_9 -> V_52 ) ;
if ( V_262 & V_269 )
F_54 ( V_9 , V_270 ) ;
if ( V_262 & ~ F_22 ( V_271 ) ) {
F_17 ( V_9 -> V_12 ,
L_30 ,
V_9 -> V_13 ,
( unsigned long long ) V_262 ,
V_3 [ V_9 -> V_2 . V_70 ] ) ;
F_177 ( V_9 ) ;
}
F_53 ( & V_9 -> V_52 ) ;
F_37 ( & V_9 -> V_69 , V_31 ) ;
}
static void F_73 ( struct V_8 * V_9 , unsigned V_93 )
{
T_2 V_272 = 0 ;
T_2 V_273 = 0 ;
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
V_272 |= F_22 ( V_274 ) ;
else
V_273 |= F_22 ( V_274 ) ;
if ( V_93 & V_100 )
V_272 |= F_22 ( V_275 ) ;
else
V_273 |= F_22 ( V_275 ) ;
if ( V_93 & V_102 )
V_272 |= F_22 ( V_276 ) ;
else
V_273 |= F_22 ( V_276 ) ;
F_33 ( & V_9 -> V_208 , V_31 ) ;
V_9 -> V_277 |= V_272 ;
V_9 -> V_277 &= ~ V_273 ;
if ( V_93 & V_104 )
F_11 ( V_9 , F_22 ( V_278 ) ,
V_9 -> V_277 |
F_22 ( V_279 ) ) ;
else
F_11 ( V_9 , F_22 ( V_278 ) , V_9 -> V_277 ) ;
F_37 ( & V_9 -> V_208 , V_31 ) ;
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
F_11 ( V_9 , F_22 ( V_280 ) ,
( V_9 -> V_186 / 64 ) << F_22 ( V_281 ) ) ;
F_11 ( V_9 , F_22 ( V_280 ) ,
( ( V_9 -> V_186 / 64 ) << F_22 ( V_281 ) ) |
( 4ULL << F_22 ( V_282 ) ) ) ;
}
static inline void F_180 ( struct V_8 * V_9 , T_4 V_81 )
{
F_181 () ;
F_182 ( V_81 , V_9 -> V_212 ) ;
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
V_19 = F_22 ( V_283 ) <<
F_22 ( V_284 ) ;
F_11 ( V_9 , F_22 ( V_285 ) , V_19 ) ;
}
static void F_184 ( struct V_8 * V_9 )
{
struct V_16 * V_12 = V_9 -> V_12 ;
F_11 ( V_9 , F_22 ( V_286 ) ,
F_185 ( V_12 ) ) ;
}
static void F_152 (
struct V_8 * V_9 ,
T_1 V_287 ,
T_9 V_194 )
{
T_5 V_288 , V_289 ;
#ifdef F_57
struct V_16 * V_12 = V_9 -> V_12 ;
F_17 ( V_12 , L_6 ,
V_9 -> V_13 , F_58 ( __FILE__ ) , __LINE__ , V_23 ) ;
#endif
F_11 ( V_9 , F_22 ( V_290 ) , V_9 -> V_187 ) ;
F_179 ( V_9 ) ;
F_180 ( V_9 , 0 ) ;
F_11 ( V_9 , F_22 ( V_291 ) , V_194 ) ;
F_11 ( V_9 , F_22 ( V_35 ) , 0 ) ;
F_11 ( V_9 , F_22 ( V_292 ) , V_9 -> V_184 ) ;
F_11 ( V_9 , F_22 ( V_293 ) ,
( ( T_2 ) V_287 << F_22 ( V_294 ) ) |
( ( T_2 ) ( V_287 * V_9 -> V_13 ) <<
F_22 ( V_295 ) ) ) ;
F_11 ( V_9 , F_22 ( V_296 ) , ~ 0ull ) ;
F_184 ( V_9 ) ;
V_289 = V_297 ;
V_288 = V_298 ;
F_11 ( V_9 , F_22 ( V_299 ) ,
( V_289 << V_300 ) |
( V_288 << V_301 ) ) ;
}
void F_178 ( struct V_8 * V_9 )
{
T_2 V_302 ;
unsigned V_27 ;
F_186 ( F_22 ( V_278 ) ) ;
F_186 ( F_22 ( V_58 ) ) ;
F_187 ( F_22 ( V_303 ) ) ;
F_187 ( F_22 ( V_304 ) ) ;
F_186 ( F_22 ( V_305 ) ) ;
F_186 ( F_22 ( V_296 ) ) ;
for ( V_27 = 0 ; V_27 < V_306 ; ++ V_27 ) {
F_188 ( V_307 ) ;
F_188 ( V_308 ) ;
F_188 ( V_309 ) ;
}
F_186 ( F_22 ( V_213 ) ) ;
F_186 ( F_22 ( V_243 ) ) ;
F_186 ( F_22 ( V_310 ) ) ;
F_186 ( F_22 ( V_311 ) ) ;
F_186 ( F_22 ( V_291 ) ) ;
F_186 ( F_22 ( V_35 ) ) ;
F_186 ( F_22 ( V_312 ) ) ;
F_186 ( F_22 ( V_293 ) ) ;
F_187 ( F_22 ( V_313 ) ) ;
F_187 ( F_22 ( V_314 ) ) ;
F_186 ( F_22 ( V_290 ) ) ;
F_186 ( F_22 ( V_280 ) ) ;
F_186 ( F_22 ( V_292 ) ) ;
F_186 ( F_22 ( V_286 ) ) ;
F_186 ( F_22 ( V_315 ) ) ;
F_186 ( F_22 ( V_316 ) ) ;
F_186 ( F_22 ( V_317 ) ) ;
F_186 ( F_22 ( V_318 ) ) ;
F_186 ( F_22 ( V_299 ) ) ;
}
static void F_177 ( struct V_8 * V_9 )
{
struct V_319 * V_185 ;
struct V_319 * V_320 ;
T_2 V_321 [ 2 ] ;
T_2 V_322 ;
T_5 V_323 ;
T_4 V_324 ;
T_4 V_80 , V_81 , V_30 ;
V_80 = V_9 -> V_65 & V_9 -> V_79 ;
V_81 = V_9 -> V_72 & V_9 -> V_79 ;
V_30 = F_63 ( V_9 ) ;
V_185 = V_9 -> V_185 ;
F_17 ( V_9 -> V_12 ,
L_32 ,
V_9 -> V_13 , V_80 , V_81 , V_30 ,
! F_158 ( & V_9 -> V_45 ) ) ;
while ( V_80 != V_81 ) {
char V_31 [ 6 ] = { 'x' , 'x' , 'x' , 'x' , 0 } ;
V_320 = & V_9 -> V_185 [ V_80 ] ;
V_321 [ 0 ] = F_168 ( V_320 -> V_229 [ 0 ] ) ;
V_321 [ 1 ] = F_168 ( V_320 -> V_229 [ 1 ] ) ;
V_31 [ 0 ] = ( V_321 [ 1 ] & V_216 ) ? 'I' : '-' ;
V_31 [ 1 ] = ( V_321 [ 1 ] & V_215 ) ?
'H' : '-' ;
V_31 [ 2 ] = ( V_321 [ 0 ] & V_325 ) ? 'F' : '-' ;
V_31 [ 3 ] = ( V_321 [ 0 ] & V_326 ) ? 'L' : '-' ;
V_322 = ( V_321 [ 0 ] >> V_327 )
& V_328 ;
V_323 = ( V_321 [ 1 ] >> V_329 )
& V_330 ;
V_324 = ( V_321 [ 0 ] >> V_331 )
& V_332 ;
F_17 ( V_9 -> V_12 ,
L_33 ,
V_80 , V_31 , V_322 , V_323 , V_324 ) ;
F_17 ( V_9 -> V_12 ,
L_34 ,
V_321 [ 0 ] , V_321 [ 1 ] ) ;
if ( V_321 [ 0 ] & V_325 )
F_17 ( V_9 -> V_12 ,
L_35 ,
( T_5 ) ( ( V_321 [ 1 ] &
V_333 ) >>
V_334 ) ,
( T_5 ) ( ( V_321 [ 1 ] &
V_230 ) >>
V_231 ) ,
( T_5 ) ( ( V_321 [ 1 ] &
V_335 ) >>
V_336 ) ) ;
V_80 ++ ;
V_80 &= V_9 -> V_79 ;
}
}
void F_189 ( struct V_156 * V_157 , struct V_8 * V_9 )
{
T_4 V_80 , V_81 ;
struct V_319 * V_320 ;
T_2 V_321 [ 2 ] ;
T_2 V_322 ;
T_5 V_323 ;
T_4 V_324 ;
V_80 = V_9 -> V_65 & V_9 -> V_79 ;
V_81 = F_169 ( V_9 -> V_72 ) & V_9 -> V_79 ;
F_116 ( V_157 , V_337 , V_9 -> V_13 ,
V_9 -> V_141 ,
F_1 ( V_9 -> V_2 . V_70 ) ,
( unsigned long long ) F_13 ( V_9 , F_22 ( V_278 ) ) ,
( unsigned long long ) F_13 ( V_9 , F_22 ( V_58 ) ) ,
( unsigned long long ) F_13 ( V_9 , F_22 ( V_305 ) ) ,
( unsigned long long ) F_13 ( V_9 , F_22 ( V_213 ) ) , V_81 ,
( unsigned long long ) F_13 ( V_9 , F_22 ( V_243 ) ) , V_80 ,
( unsigned long long ) F_168 ( * V_9 -> V_85 ) ,
( unsigned long long ) F_13 ( V_9 , F_22 ( V_293 ) ) ,
( unsigned long long ) F_13 ( V_9 , F_22 ( V_280 ) ) ,
( unsigned long long ) F_13 ( V_9 , F_22 ( V_291 ) ) ,
( unsigned long long ) V_9 -> V_265 ,
( unsigned long long ) V_9 -> V_209 ,
V_9 -> V_338 ,
V_9 -> V_78 ,
V_9 -> V_72 ,
V_9 -> V_65 ,
! F_158 ( & V_9 -> V_45 ) ,
V_9 -> V_339 ,
( unsigned long long ) F_13 ( V_9 , V_340 ) ) ;
while ( V_80 != V_81 ) {
char V_31 [ 6 ] = { 'x' , 'x' , 'x' , 'x' , 0 } ;
V_320 = & V_9 -> V_185 [ V_80 ] ;
V_321 [ 0 ] = F_168 ( V_320 -> V_229 [ 0 ] ) ;
V_321 [ 1 ] = F_168 ( V_320 -> V_229 [ 1 ] ) ;
V_31 [ 0 ] = ( V_321 [ 1 ] & V_216 ) ? 'I' : '-' ;
V_31 [ 1 ] = ( V_321 [ 1 ] & V_215 ) ?
'H' : '-' ;
V_31 [ 2 ] = ( V_321 [ 0 ] & V_325 ) ? 'F' : '-' ;
V_31 [ 3 ] = ( V_321 [ 0 ] & V_326 ) ? 'L' : '-' ;
V_322 = ( V_321 [ 0 ] >> V_327 )
& V_328 ;
V_323 = ( V_321 [ 1 ] >> V_329 )
& V_330 ;
V_324 = ( V_321 [ 0 ] >> V_331 )
& V_332 ;
F_116 ( V_157 ,
L_36 ,
V_80 , V_31 , V_322 , V_323 , V_324 ) ;
if ( V_321 [ 0 ] & V_325 )
F_116 ( V_157 , L_37 ,
( T_5 ) ( ( V_321 [ 1 ] &
V_333 ) >>
V_334 ) ,
( T_5 ) ( ( V_321 [ 1 ] &
V_230 ) >>
V_231 ) ) ;
V_80 = ( V_80 + 1 ) & V_9 -> V_79 ;
}
}
static inline T_2 F_190 ( struct V_8 * V_9 , T_2 V_341 )
{
T_5 V_342 = ( V_9 -> V_72 >> V_9 -> V_203 ) & 3 ;
V_341 &= ~ V_343 ;
V_341 |= ( ( T_2 ) V_342 & V_330 )
<< V_329 ;
return V_341 ;
}
static inline T_4 F_191 ( struct V_8 * V_9 , struct V_36 * V_37 )
{
int V_27 ;
T_4 V_81 ;
struct V_224 * V_225 = V_37 -> V_225 ;
T_5 V_233 = 0 , V_234 = F_166 ( V_37 ) ;
V_81 = V_9 -> V_72 & V_9 -> V_79 ;
V_9 -> V_185 [ V_81 ] . V_229 [ 0 ] = F_192 ( V_225 -> V_229 [ 0 ] ) ;
V_9 -> V_185 [ V_81 ] . V_229 [ 1 ] = F_192 ( F_190 ( V_9 , V_225 -> V_229 [ 1 ] ) ) ;
F_193 ( V_9 , V_225 -> V_229 [ 0 ] , V_225 -> V_229 [ 1 ] ,
V_81 , & V_9 -> V_185 [ V_81 ] ) ;
V_81 = ++ V_9 -> V_72 & V_9 -> V_79 ;
V_225 ++ ;
if ( V_234 > V_235 )
V_233 = V_234 >> 1 ;
for ( V_27 = 1 ; V_27 < V_37 -> V_232 ; V_27 ++ , V_225 ++ ) {
T_2 V_341 ;
V_9 -> V_185 [ V_81 ] . V_229 [ 0 ] = F_192 ( V_225 -> V_229 [ 0 ] ) ;
if ( V_233 ) {
V_341 = V_225 -> V_229 [ 1 ] ;
V_233 -- ;
} else {
V_341 = F_190 ( V_9 , V_225 -> V_229 [ 1 ] ) ;
}
V_9 -> V_185 [ V_81 ] . V_229 [ 1 ] = F_192 ( V_341 ) ;
F_193 ( V_9 , V_225 -> V_229 [ 0 ] , V_341 ,
V_81 , & V_9 -> V_185 [ V_81 ] ) ;
V_81 = ++ V_9 -> V_72 & V_9 -> V_79 ;
}
V_37 -> V_83 = V_81 ;
#ifdef F_24
V_37 -> V_41 = V_9 -> V_344 ++ ;
F_194 ( V_9 , V_37 -> V_41 ) ;
F_26 ( V_9 -> V_77 [ V_9 -> V_338 & V_9 -> V_79 ] ) ;
#endif
V_9 -> V_77 [ V_9 -> V_338 ++ & V_9 -> V_79 ] = V_37 ;
V_9 -> V_84 -= V_37 -> V_232 ;
return V_81 ;
}
static int F_195 (
struct V_8 * V_9 ,
struct V_39 * V_40 ,
struct V_36 * V_37 ,
bool V_345 )
{
int V_142 ;
V_9 -> V_84 = F_63 ( V_9 ) ;
if ( V_37 -> V_232 <= V_9 -> V_84 )
return - V_346 ;
if ( V_40 && V_40 -> V_347 ) {
unsigned V_253 ;
V_253 = F_196 (
( const V_348 * ) & V_9 -> V_52 . V_349 ) ;
V_142 = V_40 -> V_347 ( V_9 , V_40 , V_37 , V_253 , V_345 ) ;
if ( V_142 == - V_346 )
V_9 -> V_84 = F_63 ( V_9 ) ;
} else {
V_142 = - V_350 ;
}
return V_142 ;
}
int F_197 ( struct V_8 * V_9 ,
struct V_39 * V_40 ,
struct V_36 * V_37 ,
bool V_345 )
{
int V_142 = 0 ;
T_4 V_81 ;
unsigned long V_31 ;
if ( F_79 ( V_37 -> V_351 ) )
return - V_115 ;
V_37 -> V_40 = V_40 ;
F_33 ( & V_9 -> V_69 , V_31 ) ;
V_241:
if ( F_79 ( ! F_40 ( V_9 ) ) )
goto V_352;
if ( F_79 ( V_37 -> V_232 > V_9 -> V_84 ) )
goto V_353;
V_81 = F_191 ( V_9 , V_37 ) ;
if ( V_40 )
F_198 ( V_40 ) ;
F_180 ( V_9 , V_81 ) ;
V_354:
F_37 ( & V_9 -> V_69 , V_31 ) ;
return V_142 ;
V_352:
if ( V_40 )
F_198 ( V_40 ) ;
V_37 -> V_83 = 0 ;
#ifdef F_24
V_37 -> V_41 = V_9 -> V_344 ++ ;
F_194 ( V_9 , V_37 -> V_41 ) ;
#endif
F_199 ( & V_9 -> V_46 ) ;
F_36 ( & V_37 -> V_47 , & V_9 -> V_45 ) ;
F_200 ( & V_9 -> V_46 ) ;
if ( V_40 ) {
V_40 -> V_355 ++ ;
V_40 -> V_108 += V_37 -> V_232 ;
}
F_55 ( & V_9 -> V_51 ) ;
V_142 = - V_356 ;
goto V_354;
V_353:
V_142 = F_195 ( V_9 , V_40 , V_37 , V_345 ) ;
if ( V_142 == - V_346 ) {
V_142 = 0 ;
goto V_241;
}
V_9 -> V_339 ++ ;
goto V_354;
}
int F_201 ( struct V_8 * V_9 , struct V_39 * V_40 ,
struct V_357 * V_358 , T_1 * V_359 )
{
struct V_36 * V_37 , * V_360 ;
int V_142 = 0 ;
unsigned long V_31 ;
T_4 V_81 = V_361 ;
T_1 V_362 = 0 , V_363 = 0 , V_364 ;
F_33 ( & V_9 -> V_69 , V_31 ) ;
V_241:
F_34 (tx, tx_next, tx_list, list) {
V_37 -> V_40 = V_40 ;
if ( F_79 ( ! F_40 ( V_9 ) ) )
goto V_352;
if ( F_79 ( V_37 -> V_232 > V_9 -> V_84 ) )
goto V_353;
if ( F_79 ( V_37 -> V_351 ) ) {
V_142 = - V_115 ;
goto V_365;
}
F_35 ( & V_37 -> V_47 ) ;
V_81 = F_191 ( V_9 , V_37 ) ;
V_362 ++ ;
if ( V_81 != V_361 &&
( V_362 & V_366 ) == 0 ) {
F_180 ( V_9 , V_81 ) ;
V_81 = V_361 ;
}
}
V_365:
V_364 = V_362 + V_363 ;
if ( V_40 ) {
F_202 ( V_40 , V_364 ) ;
F_203 ( V_362 > 0 , V_40 ) ;
}
if ( V_81 != V_361 )
F_180 ( V_9 , V_81 ) ;
F_37 ( & V_9 -> V_69 , V_31 ) ;
* V_359 = V_364 ;
return V_142 ;
V_352:
F_199 ( & V_9 -> V_46 ) ;
F_34 (tx, tx_next, tx_list, list) {
V_37 -> V_40 = V_40 ;
F_35 ( & V_37 -> V_47 ) ;
V_37 -> V_83 = 0 ;
#ifdef F_24
V_37 -> V_41 = V_9 -> V_344 ++ ;
F_194 ( V_9 , V_37 -> V_41 ) ;
#endif
F_36 ( & V_37 -> V_47 , & V_9 -> V_45 ) ;
V_363 ++ ;
if ( V_40 ) {
V_40 -> V_355 ++ ;
V_40 -> V_108 += V_37 -> V_232 ;
}
}
F_200 ( & V_9 -> V_46 ) ;
F_55 ( & V_9 -> V_51 ) ;
V_142 = - V_356 ;
goto V_365;
V_353:
V_142 = F_195 ( V_9 , V_40 , V_37 , V_362 > 0 ) ;
if ( V_142 == - V_346 ) {
V_142 = 0 ;
goto V_241;
}
V_9 -> V_339 ++ ;
goto V_365;
}
static void F_46 ( struct V_8 * V_9 , enum V_367 V_368 )
{
unsigned long V_31 ;
F_33 ( & V_9 -> V_69 , V_31 ) ;
F_52 ( & V_9 -> V_52 ) ;
F_54 ( V_9 , V_368 ) ;
if ( V_9 -> V_2 . V_70 == V_71 )
F_62 ( V_9 , F_63 ( V_9 ) ) ;
F_53 ( & V_9 -> V_52 ) ;
F_37 ( & V_9 -> V_69 , V_31 ) ;
}
static void F_54 ( struct V_8 * V_9 ,
enum V_367 V_368 )
{
struct V_4 * V_5 = & V_9 -> V_2 ;
int V_369 = 0 ;
#ifdef F_57
F_17 ( V_9 -> V_12 , L_38 , V_9 -> V_13 ,
V_3 [ V_5 -> V_70 ] ,
V_370 [ V_368 ] ) ;
#endif
switch ( V_5 -> V_70 ) {
case V_210 :
switch ( V_368 ) {
case V_223 :
break;
case V_220 :
V_5 -> V_106 = 1 ;
case V_222 :
F_2 ( & V_9 -> V_2 ) ;
F_71 ( V_9 ,
V_371 ) ;
break;
case V_60 :
break;
case V_76 :
break;
case V_86 :
F_66 ( V_9 ) ;
break;
case V_372 :
break;
case V_270 :
break;
case V_221 :
break;
case V_373 :
break;
case V_374 :
break;
case V_375 :
break;
case V_376 :
break;
case V_73 :
break;
}
break;
case V_371 :
switch ( V_368 ) {
case V_223 :
F_71 ( V_9 , V_210 ) ;
F_66 ( V_9 ) ;
break;
case V_222 :
break;
case V_60 :
F_71 ( V_9 ,
V_377 ) ;
F_69 ( V_9 ) ;
break;
case V_76 :
break;
case V_220 :
V_5 -> V_106 = 1 ;
break;
case V_86 :
break;
case V_372 :
break;
case V_270 :
F_55 ( & V_9 -> V_53 ) ;
break;
case V_221 :
V_5 -> V_106 = 0 ;
break;
case V_373 :
break;
case V_374 :
break;
case V_375 :
break;
case V_376 :
break;
case V_73 :
break;
}
break;
case V_377 :
switch ( V_368 ) {
case V_223 :
F_71 ( V_9 , V_210 ) ;
F_66 ( V_9 ) ;
break;
case V_222 :
break;
case V_60 :
break;
case V_76 :
F_183 ( V_9 ) ;
F_71 ( V_9 , V_5 -> V_106 ?
V_71 :
V_378 ) ;
break;
case V_220 :
V_5 -> V_106 = 1 ;
break;
case V_86 :
break;
case V_372 :
break;
case V_270 :
break;
case V_221 :
V_5 -> V_106 = 0 ;
break;
case V_373 :
break;
case V_374 :
break;
case V_375 :
break;
case V_376 :
break;
case V_73 :
break;
}
break;
case V_378 :
switch ( V_368 ) {
case V_223 :
F_71 ( V_9 , V_210 ) ;
F_66 ( V_9 ) ;
break;
case V_222 :
break;
case V_60 :
break;
case V_76 :
break;
case V_220 :
F_71 ( V_9 , V_71 ) ;
V_5 -> V_106 = 1 ;
break;
case V_86 :
break;
case V_372 :
break;
case V_270 :
F_71 ( V_9 , V_379 ) ;
F_55 ( & V_9 -> V_53 ) ;
break;
case V_221 :
break;
case V_376 :
case V_373 :
F_71 ( V_9 , V_380 ) ;
F_204 ( & V_9 -> V_12 -> V_87 ) ;
F_68 ( & V_9 -> V_12 -> V_88 ) ;
break;
case V_374 :
break;
case V_375 :
break;
case V_73 :
break;
}
break;
case V_381 :
switch ( V_368 ) {
case V_223 :
F_71 ( V_9 , V_210 ) ;
break;
case V_222 :
break;
case V_60 :
break;
case V_76 :
break;
case V_220 :
V_5 -> V_106 = 1 ;
break;
case V_86 :
F_71 ( V_9 , V_382 ) ;
F_69 ( V_9 ) ;
break;
case V_372 :
break;
case V_270 :
break;
case V_221 :
V_5 -> V_106 = 0 ;
break;
case V_373 :
break;
case V_374 :
break;
case V_375 :
break;
case V_376 :
V_5 -> V_106 = 0 ;
break;
case V_73 :
break;
}
break;
case V_382 :
switch ( V_368 ) {
case V_223 :
F_71 ( V_9 , V_210 ) ;
F_70 ( & V_9 -> F_64 ) ;
break;
case V_222 :
break;
case V_60 :
break;
case V_76 :
F_183 ( V_9 ) ;
F_71 ( V_9 , V_5 -> V_106 ?
V_71 :
V_378 ) ;
break;
case V_220 :
V_5 -> V_106 = 1 ;
break;
case V_86 :
break;
case V_372 :
break;
case V_270 :
break;
case V_221 :
V_5 -> V_106 = 0 ;
break;
case V_373 :
break;
case V_374 :
break;
case V_375 :
break;
case V_376 :
V_5 -> V_106 = 0 ;
break;
case V_73 :
break;
}
break;
case V_379 :
switch ( V_368 ) {
case V_223 :
F_71 ( V_9 , V_210 ) ;
F_70 ( & V_9 -> F_64 ) ;
break;
case V_222 :
break;
case V_60 :
F_71 ( V_9 , V_381 ) ;
F_70 ( & V_9 -> F_64 ) ;
break;
case V_76 :
break;
case V_220 :
V_5 -> V_106 = 1 ;
break;
case V_86 :
break;
case V_372 :
break;
case V_270 :
F_55 ( & V_9 -> V_53 ) ;
break;
case V_221 :
V_5 -> V_106 = 0 ;
break;
case V_373 :
break;
case V_374 :
break;
case V_375 :
break;
case V_376 :
V_5 -> V_106 = 0 ;
break;
case V_73 :
break;
}
break;
case V_383 :
switch ( V_368 ) {
case V_223 :
F_71 ( V_9 , V_210 ) ;
F_70 ( & V_9 -> F_64 ) ;
break;
case V_222 :
break;
case V_60 :
F_71 ( V_9 , V_381 ) ;
F_70 ( & V_9 -> F_64 ) ;
break;
case V_76 :
break;
case V_220 :
V_5 -> V_106 = 1 ;
break;
case V_86 :
break;
case V_372 :
break;
case V_270 :
F_55 ( & V_9 -> V_53 ) ;
break;
case V_221 :
V_5 -> V_106 = 0 ;
break;
case V_373 :
break;
case V_374 :
break;
case V_375 :
break;
case V_376 :
break;
case V_73 :
break;
}
break;
case V_380 :
switch ( V_368 ) {
case V_223 :
F_71 ( V_9 , V_210 ) ;
F_70 ( & V_9 -> F_64 ) ;
break;
case V_222 :
break;
case V_60 :
break;
case V_76 :
break;
case V_220 :
V_5 -> V_106 = 1 ;
break;
case V_86 :
break;
case V_372 :
break;
case V_270 :
break;
case V_221 :
V_5 -> V_106 = 0 ;
break;
case V_373 :
break;
case V_374 :
F_71 ( V_9 , V_384 ) ;
F_70 ( & V_9 -> F_64 ) ;
break;
case V_375 :
break;
case V_376 :
break;
case V_73 :
break;
}
break;
case V_384 :
switch ( V_368 ) {
case V_223 :
F_71 ( V_9 , V_210 ) ;
F_70 ( & V_9 -> F_64 ) ;
break;
case V_222 :
break;
case V_60 :
break;
case V_76 :
break;
case V_220 :
V_5 -> V_106 = 1 ;
break;
case V_86 :
F_204 ( & V_9 -> V_12 -> V_87 ) ;
F_68 ( & V_9 -> V_12 -> V_88 ) ;
break;
case V_372 :
break;
case V_270 :
break;
case V_221 :
V_5 -> V_106 = 0 ;
break;
case V_373 :
break;
case V_374 :
break;
case V_375 :
F_183 ( V_9 ) ;
F_71 ( V_9 , V_5 -> V_106 ?
V_71 :
V_378 ) ;
break;
case V_376 :
break;
case V_73 :
break;
}
break;
case V_71 :
switch ( V_368 ) {
case V_223 :
F_71 ( V_9 , V_210 ) ;
F_70 ( & V_9 -> F_64 ) ;
break;
case V_222 :
break;
case V_60 :
break;
case V_76 :
break;
case V_220 :
break;
case V_86 :
break;
case V_372 :
break;
case V_270 :
V_369 = 1 ;
F_47 ( V_9 ) ;
case V_73 :
F_71 ( V_9 , V_379 ) ;
F_55 ( & V_9 -> V_53 ) ;
break;
case V_221 :
F_71 ( V_9 , V_383 ) ;
break;
case V_376 :
V_5 -> V_106 = 0 ;
case V_373 :
F_71 ( V_9 , V_380 ) ;
F_204 ( & V_9 -> V_12 -> V_87 ) ;
F_68 ( & V_9 -> V_12 -> V_88 ) ;
break;
case V_374 :
break;
case V_375 :
break;
}
break;
}
V_5 -> V_385 = V_368 ;
if ( V_369 )
F_65 ( V_9 , 0 ) ;
}
static int F_205 ( struct V_16 * V_12 , struct V_36 * V_37 )
{
int V_27 ;
if ( F_79 ( ( V_37 -> V_232 == ( V_386 - 1 ) ) ) ) {
if ( ! V_37 -> V_351 ) {
V_37 -> V_237 = V_386 ;
} else if ( ! V_37 -> V_236 ) {
V_37 -> V_236 = F_206 ( V_37 -> V_351 + sizeof( T_1 ) ,
V_387 ) ;
if ( ! V_37 -> V_236 )
goto V_388;
V_37 -> V_389 = 0 ;
}
return 0 ;
}
if ( F_79 ( V_37 -> V_232 == V_386 ) )
goto V_388;
V_37 -> V_225 = F_207 (
V_386 ,
sizeof( struct V_224 ) ,
V_387 ) ;
if ( ! V_37 -> V_225 )
goto V_388;
V_37 -> V_237 = V_386 - 1 ;
for ( V_27 = 0 ; V_27 < V_37 -> V_232 ; V_27 ++ )
V_37 -> V_225 [ V_27 ] = V_37 -> V_238 [ V_27 ] ;
return 0 ;
V_388:
F_27 ( V_12 , V_37 ) ;
return - V_145 ;
}
int F_208 ( struct V_16 * V_12 , struct V_36 * V_37 ,
int type , void * V_390 , struct V_391 * V_391 ,
unsigned long V_392 , T_4 V_324 )
{
int V_393 , V_121 ;
T_10 V_322 ;
V_121 = F_205 ( V_12 , V_37 ) ;
if ( V_121 ) {
F_27 ( V_12 , V_37 ) ;
return V_121 ;
}
if ( V_37 -> V_236 ) {
if ( type == V_394 ) {
F_27 ( V_12 , V_37 ) ;
return - V_115 ;
}
if ( type == V_228 ) {
V_390 = F_209 ( V_391 ) ;
V_390 += V_392 ;
} else if ( F_107 ( ! V_390 ) ) {
F_27 ( V_12 , V_37 ) ;
return - V_115 ;
}
memcpy ( V_37 -> V_236 + V_37 -> V_389 , V_390 , V_324 ) ;
V_37 -> V_389 += V_324 ;
if ( type == V_228 )
F_210 ( V_391 ) ;
if ( V_37 -> V_351 - V_37 -> V_389 )
return 0 ;
V_393 = V_37 -> V_395 & ( sizeof( T_1 ) - 1 ) ;
if ( V_393 ) {
V_393 = sizeof( T_1 ) - V_393 ;
memset ( V_37 -> V_236 + V_37 -> V_389 , 0 , V_393 ) ;
V_37 -> V_395 += V_393 ;
V_37 -> V_351 += V_393 ;
}
V_322 = F_211 ( & V_12 -> V_178 -> V_179 ,
V_37 -> V_236 ,
V_37 -> V_351 ,
V_227 ) ;
if ( F_79 ( F_212 ( & V_12 -> V_178 -> V_179 , V_322 ) ) ) {
F_27 ( V_12 , V_37 ) ;
return - V_396 ;
}
V_37 -> V_237 = V_386 ;
return F_213 ( V_12 , V_226 , V_37 ,
V_322 , V_37 -> V_351 ) ;
}
return 1 ;
}
void F_214 ( struct V_16 * V_12 , T_2 V_125 , T_1 V_397 )
{
struct V_8 * V_9 ;
int V_27 ;
T_2 V_398 ;
V_398 = ( ( V_125 & F_22 ( V_399 ) ) <<
F_22 ( V_400 ) ) |
( ( ( V_397 & V_125 ) & F_22 ( V_401 ) ) <<
F_22 ( V_402 ) ) ;
for ( V_27 = 0 ; V_27 < V_12 -> V_28 ; V_27 ++ ) {
F_215 ( V_403 , L_39 ,
V_27 , ( T_1 ) V_398 ) ;
V_9 = & V_12 -> V_29 [ V_27 ] ;
F_11 ( V_9 , F_22 ( V_318 ) , V_398 ) ;
}
}
int F_216 ( struct V_16 * V_12 , struct V_36 * V_37 )
{
int V_121 = 0 ;
V_37 -> V_232 ++ ;
if ( ( F_79 ( V_37 -> V_232 == V_37 -> V_237 ) ) ) {
V_121 = F_205 ( V_12 , V_37 ) ;
if ( V_121 ) {
F_27 ( V_12 , V_37 ) ;
return V_121 ;
}
}
F_217 (
V_37 ,
V_394 ,
V_12 -> V_180 ,
sizeof( T_1 ) - ( V_37 -> V_395 & ( sizeof( T_1 ) - 1 ) ) ) ;
F_218 ( V_12 , V_37 ) ;
return V_121 ;
}
void F_219 (
struct V_36 * V_37 ,
T_5 V_404 ,
T_5 V_405 ,
T_1 * V_406 ,
T_5 V_407 )
{
T_1 V_27 , V_408 = 0 , V_321 = 0 ;
T_5 V_234 ;
F_26 ( V_404 > 9 || ( V_407 & 3 ) || V_407 == 4 ) ;
if ( V_404 == 1 )
V_234 = V_235 ;
else if ( V_404 <= 5 )
V_234 = V_409 ;
else
V_234 = V_410 ;
V_37 -> V_232 ++ ;
switch ( V_234 ) {
case V_410 :
V_37 -> V_232 ++ ;
V_37 -> V_238 [ 2 ] . V_229 [ 0 ] = 0 ;
V_37 -> V_238 [ 2 ] . V_229 [ 1 ] = 0 ;
case V_409 :
V_37 -> V_232 ++ ;
V_37 -> V_238 [ 1 ] . V_229 [ 0 ] = 0 ;
V_37 -> V_238 [ 1 ] . V_229 [ 1 ] = 0 ;
break;
}
V_407 >>= 2 ;
V_37 -> V_238 [ 0 ] . V_229 [ 1 ] |=
( ( ( T_2 ) V_405 & V_411 )
<< V_334 ) |
( ( ( T_2 ) V_407 & V_412 )
<< V_336 ) |
( ( ( T_2 ) V_234 & V_413 )
<< V_231 ) |
( ( ( T_2 ) V_406 [ 0 ] & V_414 )
<< V_415 ) ;
for ( V_27 = 0 ; V_27 < ( V_404 - 1 ) ; V_27 ++ ) {
if ( ! V_408 && ! ( V_27 & 2 ) )
V_321 ++ ;
V_37 -> V_238 [ V_321 ] . V_229 [ ! ! ( V_27 & 2 ) ] |=
( ( ( T_2 ) V_406 [ V_27 + 1 ] )
<< V_408 ) ;
V_408 = ( V_408 + 32 ) & 63 ;
}
}
int F_220 ( struct V_8 * V_9 )
{
int V_416 ;
int V_417 ;
if ( ! V_9 ) {
F_221 ( V_9 , - V_115 ) ;
return - V_115 ;
}
while ( 1 ) {
V_416 = F_222 ( F_169 ( V_9 -> V_209 ) ) ;
if ( V_416 > 31 ) {
F_221 ( V_9 , - V_396 ) ;
return - V_396 ;
}
V_417 = F_223 ( V_416 , & V_9 -> V_209 ) ;
if ( ! V_417 )
break;
F_224 () ;
}
F_221 ( V_9 , V_416 ) ;
return V_416 ;
}
void F_225 ( struct V_8 * V_9 , int V_418 )
{
if ( ! V_9 )
return;
F_226 ( V_9 , V_418 ) ;
if ( V_418 < 0 || V_418 > 31 )
return;
F_227 ( V_418 , & V_9 -> V_209 ) ;
}
void F_228 ( struct V_16 * V_12 , int V_419 )
{
int V_27 ;
enum V_367 V_368 = V_419 ? V_376 :
V_373 ;
F_67 ( & V_12 -> V_87 , V_12 -> V_28 ) ;
for ( V_27 = 0 ; V_27 < V_12 -> V_28 ; V_27 ++ )
F_46 ( & V_12 -> V_29 [ V_27 ] , V_368 ) ;
}
void F_229 ( struct V_16 * V_12 )
{
int V_27 ;
int V_142 ;
V_142 = F_230 ( V_12 -> V_88 ,
F_231 ( & V_12 -> V_87 ) <=
0 ) ;
if ( V_142 || F_231 ( & V_12 -> V_87 ) < 0 )
return;
F_67 ( & V_12 -> V_87 , V_12 -> V_28 ) ;
for ( V_27 = 0 ; V_27 < V_12 -> V_28 ; V_27 ++ )
F_46 ( & V_12 -> V_29 [ V_27 ] , V_374 ) ;
( void ) F_230 ( V_12 -> V_88 ,
F_231 ( & V_12 -> V_87 ) <= 0 ) ;
}
void F_232 ( struct V_16 * V_12 )
{
int V_27 ;
for ( V_27 = 0 ; V_27 < V_12 -> V_28 ; V_27 ++ )
F_46 ( & V_12 -> V_29 [ V_27 ] ,
V_375 ) ;
}
void F_233 (
struct V_8 * V_9 )
{
F_234 ( V_9 , V_9 -> V_205 ) ;
F_235 ( V_9 -> V_12 ,
V_420 + ( 8 * ( V_421 / 64 ) ) ,
V_9 -> V_205 ) ;
}
