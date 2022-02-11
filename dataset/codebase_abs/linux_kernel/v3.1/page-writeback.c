static inline long F_1 ( unsigned long V_1 )
{
if ( V_1 < V_2 )
V_1 = V_2 ;
return V_1 + V_1 / 2 ;
}
static int F_2 ( void )
{
unsigned long V_3 ;
if ( V_4 )
V_3 = V_4 / V_5 ;
else
V_3 = ( V_6 * F_3 () ) /
100 ;
return 2 + F_4 ( V_3 - 1 ) ;
}
static void F_5 ( void )
{
int V_7 = F_2 () ;
F_6 ( & V_8 , V_7 ) ;
F_6 ( & V_9 , V_7 ) ;
}
int F_7 ( struct V_10 * V_11 , int V_12 ,
void T_1 * V_13 , T_2 * V_14 ,
T_3 * V_15 )
{
int V_16 ;
V_16 = F_8 ( V_11 , V_12 , V_13 , V_14 , V_15 ) ;
if ( V_16 == 0 && V_12 )
V_17 = 0 ;
return V_16 ;
}
int F_9 ( struct V_10 * V_11 , int V_12 ,
void T_1 * V_13 , T_2 * V_14 ,
T_3 * V_15 )
{
int V_16 ;
V_16 = F_10 ( V_11 , V_12 , V_13 , V_14 , V_15 ) ;
if ( V_16 == 0 && V_12 )
V_18 = 0 ;
return V_16 ;
}
int F_11 ( struct V_10 * V_11 , int V_12 ,
void T_1 * V_13 , T_2 * V_14 ,
T_3 * V_15 )
{
int V_19 = V_6 ;
int V_16 ;
V_16 = F_8 ( V_11 , V_12 , V_13 , V_14 , V_15 ) ;
if ( V_16 == 0 && V_12 && V_6 != V_19 ) {
F_5 () ;
V_4 = 0 ;
}
return V_16 ;
}
int F_12 ( struct V_10 * V_11 , int V_12 ,
void T_1 * V_13 , T_2 * V_14 ,
T_3 * V_15 )
{
unsigned long V_20 = V_4 ;
int V_16 ;
V_16 = F_10 ( V_11 , V_12 , V_13 , V_14 , V_15 ) ;
if ( V_16 == 0 && V_12 && V_4 != V_20 ) {
F_5 () ;
V_6 = 0 ;
}
return V_16 ;
}
static inline void F_13 ( struct V_21 * V_22 )
{
F_14 ( V_22 , V_23 ) ;
F_15 ( & V_8 , & V_22 -> V_24 ,
V_22 -> V_25 ) ;
}
void F_16 ( struct V_21 * V_22 )
{
unsigned long V_26 ;
F_17 ( V_26 ) ;
F_13 ( V_22 ) ;
F_18 ( V_26 ) ;
}
void F_19 ( struct V_27 * V_28 )
{
F_20 ( & V_9 , & V_28 -> V_29 ) ;
}
static void F_21 ( struct V_21 * V_22 ,
long * V_30 , long * V_31 )
{
F_22 ( & V_8 , & V_22 -> V_24 ,
V_30 , V_31 ) ;
}
static inline void F_23 ( struct V_27 * V_28 ,
long * V_30 , long * V_31 )
{
F_24 ( & V_9 , & V_28 -> V_29 ,
V_30 , V_31 ) ;
}
static unsigned long F_25 ( struct V_27 * V_28 ,
unsigned long V_32 )
{
long V_30 , V_31 ;
unsigned long V_33 = V_32 ;
T_4 V_34 = V_33 / V_35 ;
F_23 ( V_28 , & V_30 , & V_31 ) ;
V_34 *= V_30 ;
F_26 ( V_34 , V_31 ) ;
V_33 -= V_34 ;
return F_27 ( V_33 , V_32 / 2 ) ;
}
static unsigned long F_28 ( unsigned long V_32 )
{
return V_32 - V_32 / V_35 ;
}
int F_29 ( struct V_21 * V_22 , unsigned int V_36 )
{
int V_16 = 0 ;
F_30 ( & V_37 ) ;
if ( V_36 > V_22 -> V_38 ) {
V_16 = - V_39 ;
} else {
V_36 -= V_22 -> V_36 ;
if ( V_40 + V_36 < 100 ) {
V_40 += V_36 ;
V_22 -> V_36 += V_36 ;
} else {
V_16 = - V_39 ;
}
}
F_31 ( & V_37 ) ;
return V_16 ;
}
int F_32 ( struct V_21 * V_22 , unsigned V_38 )
{
int V_16 = 0 ;
if ( V_38 > 100 )
return - V_39 ;
F_30 ( & V_37 ) ;
if ( V_22 -> V_36 > V_38 ) {
V_16 = - V_39 ;
} else {
V_22 -> V_38 = V_38 ;
V_22 -> V_25 = ( V_41 * V_38 ) / 100 ;
}
F_31 ( & V_37 ) ;
return V_16 ;
}
static unsigned long F_33 ( unsigned long V_42 )
{
#ifdef F_34
int V_43 ;
unsigned long V_44 = 0 ;
F_35 (node, N_HIGH_MEMORY) {
struct V_45 * V_46 =
& F_36 ( V_43 ) -> V_47 [ V_48 ] ;
V_44 += F_37 ( V_46 , V_49 ) +
F_38 ( V_46 ) ;
}
return F_39 ( V_44 , V_42 ) ;
#else
return 0 ;
#endif
}
unsigned long F_3 ( void )
{
unsigned long V_44 ;
V_44 = F_40 ( V_49 ) + F_41 () ;
if ( ! V_50 )
V_44 -= F_33 ( V_44 ) ;
return V_44 + 1 ;
}
static unsigned long F_42 ( unsigned long V_51 )
{
return F_27 ( V_51 , V_52 ) ;
}
void F_43 ( unsigned long * V_53 , unsigned long * V_54 )
{
unsigned long V_55 ;
unsigned long V_33 ;
unsigned long V_56 ( V_57 ) ;
struct V_27 * V_28 ;
if ( ! V_4 || ! V_17 )
V_57 = F_3 () ;
if ( V_4 )
V_33 = F_44 ( V_4 , V_5 ) ;
else
V_33 = ( V_6 * V_57 ) / 100 ;
if ( V_17 )
V_55 = F_44 ( V_17 , V_5 ) ;
else
V_55 = ( V_18 * V_57 ) / 100 ;
if ( V_55 >= V_33 )
V_55 = V_33 / 2 ;
V_28 = V_58 ;
if ( V_28 -> V_26 & V_59 || F_45 ( V_28 ) ) {
V_55 += V_55 / 4 ;
V_33 += V_33 / 4 ;
}
* V_53 = V_55 ;
* V_54 = V_33 ;
F_46 ( V_55 , V_33 ) ;
}
unsigned long F_47 ( struct V_21 * V_22 , unsigned long V_33 )
{
T_4 V_32 ;
long V_30 , V_31 ;
F_21 ( V_22 , & V_30 , & V_31 ) ;
V_32 = ( V_33 * ( 100 - V_40 ) ) / 100 ;
V_32 *= V_30 ;
F_26 ( V_32 , V_31 ) ;
V_32 += ( V_33 * V_22 -> V_36 ) / 100 ;
if ( V_32 > ( V_33 * V_22 -> V_38 ) / 100 )
V_32 = V_33 * V_22 -> V_38 / 100 ;
return V_32 ;
}
static void F_48 ( struct V_21 * V_22 ,
unsigned long V_60 ,
unsigned long V_61 )
{
const unsigned long V_62 = F_49 ( 3 * V_63 ) ;
unsigned long V_64 = V_22 -> V_65 ;
unsigned long V_66 = V_22 -> V_67 ;
T_4 V_68 ;
V_68 = V_61 - V_22 -> V_69 ;
V_68 *= V_63 ;
if ( F_50 ( V_60 > V_62 ) ) {
F_26 ( V_68 , V_60 ) ;
V_64 = V_68 ;
goto V_70;
}
V_68 += ( T_4 ) V_22 -> V_67 * ( V_62 - V_60 ) ;
V_68 >>= F_4 ( V_62 ) ;
if ( V_64 > V_66 && V_66 >= ( unsigned long ) V_68 )
V_64 -= ( V_64 - V_66 ) >> 3 ;
if ( V_64 < V_66 && V_66 <= ( unsigned long ) V_68 )
V_64 += ( V_66 - V_64 ) >> 3 ;
V_70:
V_22 -> V_67 = V_68 ;
V_22 -> V_65 = V_64 ;
}
static void F_51 ( unsigned long V_51 , unsigned long V_33 )
{
unsigned long V_71 = V_52 ;
if ( V_71 < V_51 ) {
V_71 = V_51 ;
goto V_72;
}
V_51 = F_27 ( V_51 , V_33 ) ;
if ( V_71 > V_51 ) {
V_71 -= ( V_71 - V_51 ) >> 5 ;
goto V_72;
}
return;
V_72:
V_52 = V_71 ;
}
static void F_52 ( unsigned long V_51 ,
unsigned long V_33 ,
unsigned long V_73 )
{
static F_53 ( V_74 ) ;
static unsigned long V_75 ;
if ( F_54 ( V_73 , V_75 + V_76 ) )
return;
F_55 ( & V_74 ) ;
if ( F_56 ( V_73 , V_75 + V_76 ) ) {
F_51 ( V_51 , V_33 ) ;
V_75 = V_73 ;
}
F_57 ( & V_74 ) ;
}
void F_58 ( struct V_21 * V_22 ,
unsigned long V_51 ,
unsigned long V_33 ,
unsigned long V_77 ,
unsigned long V_32 ,
unsigned long V_78 )
{
unsigned long V_73 = V_79 ;
unsigned long V_60 = V_73 - V_22 -> V_80 ;
unsigned long V_61 ;
if ( V_60 < V_76 )
return;
V_61 = F_59 ( & V_22 -> V_81 [ V_23 ] ) ;
if ( V_60 > V_63 && F_54 ( V_22 -> V_80 , V_78 ) )
goto V_82;
if ( V_51 )
F_52 ( V_51 , V_33 , V_73 ) ;
F_48 ( V_22 , V_60 , V_61 ) ;
V_82:
V_22 -> V_69 = V_61 ;
V_22 -> V_80 = V_73 ;
}
static void F_60 ( struct V_21 * V_22 ,
unsigned long V_51 ,
unsigned long V_33 ,
unsigned long V_77 ,
unsigned long V_32 ,
unsigned long V_78 )
{
if ( F_61 ( V_22 -> V_80 + V_76 ) )
return;
F_55 ( & V_22 -> V_83 . V_84 ) ;
F_58 ( V_22 , V_51 , V_33 , V_77 , V_32 ,
V_78 ) ;
F_57 ( & V_22 -> V_83 . V_84 ) ;
}
static void F_62 ( struct V_85 * V_86 ,
unsigned long V_87 )
{
unsigned long V_88 , V_89 ;
unsigned long V_90 ;
unsigned long V_32 ;
unsigned long V_91 ;
unsigned long V_92 ;
unsigned long V_77 ;
unsigned long V_93 ;
unsigned long V_94 ;
unsigned long V_95 = 0 ;
unsigned long V_96 = 1 ;
bool V_97 = false ;
bool V_98 = true ;
struct V_21 * V_22 = V_86 -> V_21 ;
unsigned long V_78 = V_79 ;
for (; ; ) {
V_88 = F_40 ( V_99 ) +
F_40 ( V_100 ) ;
V_90 = V_88 + F_40 ( V_101 ) ;
F_43 ( & V_91 , & V_92 ) ;
if ( V_90 <= ( V_91 + V_92 ) / 2 )
break;
V_77 = F_47 ( V_22 , V_92 ) ;
V_94 = F_28 ( V_77 ) ;
V_93 = F_25 ( V_58 , V_77 ) ;
if ( V_93 < 2 * F_63 ( V_22 ) ) {
V_89 = F_64 ( V_22 , V_102 ) ;
V_32 = V_89 +
F_64 ( V_22 , V_103 ) ;
} else {
V_89 = V_81 ( V_22 , V_102 ) ;
V_32 = V_89 +
V_81 ( V_22 , V_103 ) ;
}
V_97 = ( V_32 > V_93 ) ||
( V_90 > V_92 ) ;
V_98 = ( V_32 <= V_94 ) &&
( V_90 <= V_92 ) ;
if ( ! V_97 )
break;
if ( ! V_22 -> V_97 )
V_22 -> V_97 = 1 ;
F_60 ( V_22 , V_92 , V_90 ,
V_77 , V_32 , V_78 ) ;
F_65 ( V_22 ) ;
if ( V_89 > V_93 ) {
V_95 += F_66 ( & V_22 -> V_83 ,
V_87 ) ;
F_67 ( V_22 , V_95 ) ;
if ( V_95 >= V_87 )
break;
}
F_68 ( V_104 ) ;
F_69 ( V_96 ) ;
F_70 ( V_22 ) ;
V_92 = F_42 ( V_92 ) ;
if ( V_90 < V_92 &&
V_32 < ( V_93 + V_77 ) / 2 &&
F_71 ( V_79 , V_78 + V_105 ) )
break;
V_96 <<= 1 ;
if ( V_96 > V_63 / 10 )
V_96 = V_63 / 10 ;
}
if ( V_98 && V_22 -> V_97 )
V_22 -> V_97 = 0 ;
if ( F_72 ( V_22 ) )
return;
if ( ( V_106 && V_95 ) ||
( ! V_106 && ( V_88 > V_91 ) ) )
F_73 ( V_22 ) ;
}
void F_74 ( struct V_107 * V_107 , int V_108 )
{
if ( F_75 ( V_107 ) || V_108 ) {
struct V_85 * V_86 = F_76 ( V_107 ) ;
if ( V_86 )
F_77 ( V_86 ) ;
}
}
void F_78 ( struct V_85 * V_86 ,
unsigned long V_109 )
{
struct V_21 * V_22 = V_86 -> V_21 ;
unsigned long V_110 ;
unsigned long * V_111 ;
if ( ! F_79 ( V_22 ) )
return;
V_110 = V_2 ;
if ( V_86 -> V_21 -> V_97 )
V_110 = 8 ;
F_80 () ;
V_111 = & F_81 ( V_112 ) ;
* V_111 += V_109 ;
if ( F_50 ( * V_111 >= V_110 ) ) {
V_110 = F_1 ( * V_111 ) ;
* V_111 = 0 ;
F_82 () ;
F_62 ( V_86 , V_110 ) ;
return;
}
F_82 () ;
}
void F_83 ( T_5 V_113 )
{
unsigned long V_91 ;
unsigned long V_92 ;
for ( ; ; ) {
F_43 ( & V_91 , & V_92 ) ;
V_92 += V_92 / 10 ;
if ( F_40 ( V_100 ) +
F_40 ( V_101 ) <= V_92 )
break;
F_84 ( V_114 , V_63 / 10 ) ;
if ( ( V_113 & ( V_115 | V_116 ) ) != ( V_115 | V_116 ) )
break;
}
}
int F_85 ( V_10 * V_11 , int V_12 ,
void T_1 * V_13 , T_2 * V_117 , T_3 * V_15 )
{
F_86 ( V_11 , V_12 , V_13 , V_117 , V_15 ) ;
F_87 () ;
return 0 ;
}
void F_88 ( unsigned long V_118 )
{
struct V_119 * V_120 = (struct V_119 * ) V_118 ;
int V_121 = F_40 ( V_99 ) +
F_40 ( V_100 ) ;
if ( F_89 ( & V_120 -> V_21 ) )
F_90 ( & V_120 -> V_21 , V_121 ) ;
}
void F_91 ( struct V_21 * V_122 )
{
F_92 ( & V_122 -> V_123 , V_79 + V_106 ) ;
}
void F_93 ( void )
{
struct V_21 * V_22 ;
F_94 () ;
F_95 (bdi, &bdi_list, bdi_list)
F_96 ( & V_22 -> V_123 ) ;
F_97 () ;
}
void F_98 ( void )
{
V_2 = V_124 / ( F_99 () * 32 ) ;
if ( V_2 < 16 )
V_2 = 16 ;
if ( V_2 * V_125 > 4096 * 1024 )
V_2 = ( 4096 * 1024 ) / V_125 ;
}
static int T_6
F_100 ( struct V_126 * V_127 , unsigned long V_128 , void * V_129 )
{
F_98 () ;
return V_130 ;
}
void T_7 F_101 ( void )
{
int V_7 ;
F_98 () ;
F_102 ( & V_131 ) ;
V_7 = F_2 () ;
F_103 ( & V_8 , V_7 ) ;
F_103 ( & V_9 , V_7 ) ;
}
void F_104 ( struct V_85 * V_86 ,
T_8 V_132 , T_8 V_133 )
{
#define F_105 4096
unsigned long V_134 ;
do {
F_106 ( & V_86 -> V_135 ) ;
V_134 = F_107 ( & V_86 -> V_136 ,
& V_132 , V_133 , F_105 ,
V_137 , V_138 ) ;
F_108 ( & V_86 -> V_135 ) ;
F_109 ( V_134 > F_105 ) ;
F_110 () ;
} while ( V_134 >= F_105 && V_132 );
}
int F_111 ( struct V_85 * V_86 ,
struct V_139 * V_140 , T_9 V_141 ,
void * V_118 )
{
int V_16 = 0 ;
int V_142 = 0 ;
struct V_143 V_144 ;
int V_121 ;
T_8 V_56 ( V_145 ) ;
T_8 V_146 ;
T_8 V_133 ;
T_8 V_147 ;
int V_148 ;
int V_149 = 0 ;
int V_150 ;
F_112 ( & V_144 , 0 ) ;
if ( V_140 -> V_151 ) {
V_145 = V_86 -> V_145 ;
V_146 = V_145 ;
if ( V_146 == 0 )
V_148 = 1 ;
else
V_148 = 0 ;
V_133 = - 1 ;
} else {
V_146 = V_140 -> V_152 >> V_153 ;
V_133 = V_140 -> V_154 >> V_153 ;
if ( V_140 -> V_152 == 0 && V_140 -> V_154 == V_155 )
V_149 = 1 ;
V_148 = 1 ;
}
if ( V_140 -> V_156 == V_157 || V_140 -> V_158 )
V_150 = V_138 ;
else
V_150 = V_137 ;
V_159:
if ( V_140 -> V_156 == V_157 || V_140 -> V_158 )
F_104 ( V_86 , V_146 , V_133 ) ;
V_147 = V_146 ;
while ( ! V_142 && ( V_146 <= V_133 ) ) {
int V_160 ;
V_121 = F_113 ( & V_144 , V_86 , & V_146 , V_150 ,
F_39 ( V_133 - V_146 , ( T_8 ) V_161 - 1 ) + 1 ) ;
if ( V_121 == 0 )
break;
for ( V_160 = 0 ; V_160 < V_121 ; V_160 ++ ) {
struct V_107 * V_107 = V_144 . V_162 [ V_160 ] ;
if ( V_107 -> V_146 > V_133 ) {
V_142 = 1 ;
break;
}
V_147 = V_107 -> V_146 ;
F_114 ( V_107 ) ;
if ( F_50 ( V_107 -> V_86 != V_86 ) ) {
V_163:
F_115 ( V_107 ) ;
continue;
}
if ( ! F_116 ( V_107 ) ) {
goto V_163;
}
if ( F_117 ( V_107 ) ) {
if ( V_140 -> V_156 != V_164 )
F_118 ( V_107 ) ;
else
goto V_163;
}
F_119 ( F_117 ( V_107 ) ) ;
if ( ! F_120 ( V_107 ) )
goto V_163;
F_121 ( V_140 , V_86 -> V_21 ) ;
V_16 = (* V_141)( V_107 , V_140 , V_118 ) ;
if ( F_50 ( V_16 ) ) {
if ( V_16 == V_165 ) {
F_115 ( V_107 ) ;
V_16 = 0 ;
} else {
V_147 = V_107 -> V_146 + 1 ;
V_142 = 1 ;
break;
}
}
if ( -- V_140 -> V_166 <= 0 &&
V_140 -> V_156 == V_164 ) {
V_142 = 1 ;
break;
}
}
F_122 ( & V_144 ) ;
F_110 () ;
}
if ( ! V_148 && ! V_142 ) {
V_148 = 1 ;
V_146 = 0 ;
V_133 = V_145 - 1 ;
goto V_159;
}
if ( V_140 -> V_151 || ( V_149 && V_140 -> V_166 > 0 ) )
V_86 -> V_145 = V_147 ;
return V_16 ;
}
static int F_123 ( struct V_107 * V_107 , struct V_139 * V_140 ,
void * V_118 )
{
struct V_85 * V_86 = V_118 ;
int V_16 = V_86 -> V_167 -> V_141 ( V_107 , V_140 ) ;
F_124 ( V_86 , V_16 ) ;
return V_16 ;
}
int F_125 ( struct V_85 * V_86 ,
struct V_139 * V_140 )
{
struct V_168 V_169 ;
int V_16 ;
if ( ! V_86 -> V_167 -> V_141 )
return 0 ;
F_126 ( & V_169 ) ;
V_16 = F_111 ( V_86 , V_140 , F_123 , V_86 ) ;
F_127 ( & V_169 ) ;
return V_16 ;
}
int F_128 ( struct V_85 * V_86 , struct V_139 * V_140 )
{
int V_16 ;
if ( V_140 -> V_166 <= 0 )
return 0 ;
if ( V_86 -> V_167 -> V_170 )
V_16 = V_86 -> V_167 -> V_170 ( V_86 , V_140 ) ;
else
V_16 = F_125 ( V_86 , V_140 ) ;
return V_16 ;
}
int F_129 ( struct V_107 * V_107 , int V_171 )
{
struct V_85 * V_86 = V_107 -> V_86 ;
int V_16 = 0 ;
struct V_139 V_140 = {
. V_156 = V_157 ,
. V_166 = 1 ,
} ;
F_119 ( ! F_130 ( V_107 ) ) ;
if ( V_171 )
F_118 ( V_107 ) ;
if ( F_120 ( V_107 ) ) {
F_131 ( V_107 ) ;
V_16 = V_86 -> V_167 -> V_141 ( V_107 , & V_140 ) ;
if ( V_16 == 0 && V_171 ) {
F_118 ( V_107 ) ;
if ( F_132 ( V_107 ) )
V_16 = - V_172 ;
}
F_133 ( V_107 ) ;
} else {
F_115 ( V_107 ) ;
}
return V_16 ;
}
int F_134 ( struct V_107 * V_107 )
{
if ( ! F_116 ( V_107 ) )
return ! F_135 ( V_107 ) ;
return 0 ;
}
void F_136 ( struct V_107 * V_107 , struct V_85 * V_86 )
{
if ( F_137 ( V_86 ) ) {
F_138 ( V_107 , V_99 ) ;
F_138 ( V_107 , V_173 ) ;
F_14 ( V_86 -> V_21 , V_102 ) ;
F_19 ( V_58 ) ;
F_139 ( V_125 ) ;
}
}
void F_140 ( struct V_107 * V_107 )
{
F_141 ( V_107 , V_101 ) ;
}
int F_142 ( struct V_107 * V_107 )
{
if ( ! F_135 ( V_107 ) ) {
struct V_85 * V_86 = F_76 ( V_107 ) ;
struct V_85 * V_174 ;
if ( ! V_86 )
return 1 ;
F_106 ( & V_86 -> V_135 ) ;
V_174 = F_76 ( V_107 ) ;
if ( V_174 ) {
F_119 ( V_174 != V_86 ) ;
F_109 ( ! F_143 ( V_107 ) && ! F_144 ( V_107 ) ) ;
F_136 ( V_107 , V_86 ) ;
F_145 ( & V_86 -> V_136 ,
F_146 ( V_107 ) , V_137 ) ;
}
F_108 ( & V_86 -> V_135 ) ;
if ( V_86 -> V_175 ) {
F_147 ( V_86 -> V_175 , V_176 ) ;
}
return 1 ;
}
return 0 ;
}
int F_148 ( struct V_139 * V_140 , struct V_107 * V_107 )
{
V_140 -> V_177 ++ ;
return F_142 ( V_107 ) ;
}
int F_75 ( struct V_107 * V_107 )
{
struct V_85 * V_86 = F_76 ( V_107 ) ;
if ( F_149 ( V_86 ) ) {
int (* F_150)( struct V_107 * ) = V_86 -> V_167 -> F_75 ;
F_151 ( V_107 ) ;
#ifdef F_152
if ( ! F_150 )
F_150 = V_178 ;
#endif
return (* F_150)( V_107 ) ;
}
if ( ! F_116 ( V_107 ) ) {
if ( ! F_135 ( V_107 ) )
return 1 ;
}
return 0 ;
}
int F_153 ( struct V_107 * V_107 )
{
int V_16 ;
F_114 ( V_107 ) ;
V_16 = F_75 ( V_107 ) ;
F_115 ( V_107 ) ;
return V_16 ;
}
int F_120 ( struct V_107 * V_107 )
{
struct V_85 * V_86 = F_76 ( V_107 ) ;
F_119 ( ! F_130 ( V_107 ) ) ;
if ( V_86 && F_137 ( V_86 ) ) {
if ( F_154 ( V_107 ) )
F_75 ( V_107 ) ;
if ( F_155 ( V_107 ) ) {
F_156 ( V_107 , V_99 ) ;
F_157 ( V_86 -> V_21 ,
V_102 ) ;
return 1 ;
}
return 0 ;
}
return F_155 ( V_107 ) ;
}
int F_158 ( struct V_107 * V_107 )
{
struct V_85 * V_86 = F_76 ( V_107 ) ;
int V_16 ;
if ( V_86 ) {
struct V_21 * V_22 = V_86 -> V_21 ;
unsigned long V_26 ;
F_159 ( & V_86 -> V_135 , V_26 ) ;
V_16 = F_160 ( V_107 ) ;
if ( V_16 ) {
F_161 ( & V_86 -> V_136 ,
F_146 ( V_107 ) ,
V_179 ) ;
if ( F_162 ( V_22 ) ) {
F_163 ( V_22 , V_103 ) ;
F_13 ( V_22 ) ;
}
}
F_164 ( & V_86 -> V_135 , V_26 ) ;
} else {
V_16 = F_160 ( V_107 ) ;
}
if ( V_16 ) {
F_156 ( V_107 , V_101 ) ;
F_141 ( V_107 , V_180 ) ;
}
return V_16 ;
}
int F_165 ( struct V_107 * V_107 )
{
struct V_85 * V_86 = F_76 ( V_107 ) ;
int V_16 ;
if ( V_86 ) {
struct V_21 * V_22 = V_86 -> V_21 ;
unsigned long V_26 ;
F_159 ( & V_86 -> V_135 , V_26 ) ;
V_16 = F_166 ( V_107 ) ;
if ( ! V_16 ) {
F_145 ( & V_86 -> V_136 ,
F_146 ( V_107 ) ,
V_179 ) ;
if ( F_162 ( V_22 ) )
F_14 ( V_22 , V_103 ) ;
}
if ( ! F_116 ( V_107 ) )
F_161 ( & V_86 -> V_136 ,
F_146 ( V_107 ) ,
V_137 ) ;
F_161 ( & V_86 -> V_136 ,
F_146 ( V_107 ) ,
V_138 ) ;
F_164 ( & V_86 -> V_135 , V_26 ) ;
} else {
V_16 = F_166 ( V_107 ) ;
}
if ( ! V_16 )
F_140 ( V_107 ) ;
return V_16 ;
}
int F_167 ( struct V_85 * V_86 , int V_150 )
{
return F_168 ( & V_86 -> V_136 , V_150 ) ;
}
