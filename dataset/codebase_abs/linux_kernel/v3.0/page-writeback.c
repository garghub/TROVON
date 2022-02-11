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
F_14 ( & V_8 , & V_22 -> V_23 ,
V_22 -> V_24 ) ;
}
void F_15 ( struct V_21 * V_22 )
{
unsigned long V_25 ;
F_16 ( V_25 ) ;
F_13 ( V_22 ) ;
F_17 ( V_25 ) ;
}
void F_18 ( struct V_26 * V_27 )
{
F_19 ( & V_9 , & V_27 -> V_28 ) ;
}
static void F_20 ( struct V_21 * V_22 ,
long * V_29 , long * V_30 )
{
if ( F_21 ( V_22 ) ) {
F_22 ( & V_8 , & V_22 -> V_23 ,
V_29 , V_30 ) ;
} else {
* V_29 = 0 ;
* V_30 = 1 ;
}
}
static inline void F_23 ( struct V_26 * V_27 ,
long * V_29 , long * V_30 )
{
F_24 ( & V_9 , & V_27 -> V_28 ,
V_29 , V_30 ) ;
}
static unsigned long F_25 ( struct V_26 * V_27 ,
unsigned long V_31 )
{
long V_29 , V_30 ;
unsigned long V_32 = V_31 ;
T_4 V_33 = V_32 >> 3 ;
F_23 ( V_27 , & V_29 , & V_30 ) ;
V_33 *= V_29 ;
F_26 ( V_33 , V_30 ) ;
V_32 -= V_33 ;
return F_27 ( V_32 , V_31 / 2 ) ;
}
int F_28 ( struct V_21 * V_22 , unsigned int V_34 )
{
int V_16 = 0 ;
F_29 ( & V_35 ) ;
if ( V_34 > V_22 -> V_36 ) {
V_16 = - V_37 ;
} else {
V_34 -= V_22 -> V_34 ;
if ( V_38 + V_34 < 100 ) {
V_38 += V_34 ;
V_22 -> V_34 += V_34 ;
} else {
V_16 = - V_37 ;
}
}
F_30 ( & V_35 ) ;
return V_16 ;
}
int F_31 ( struct V_21 * V_22 , unsigned V_36 )
{
int V_16 = 0 ;
if ( V_36 > 100 )
return - V_37 ;
F_29 ( & V_35 ) ;
if ( V_22 -> V_34 > V_36 ) {
V_16 = - V_37 ;
} else {
V_22 -> V_36 = V_36 ;
V_22 -> V_24 = ( V_39 * V_36 ) / 100 ;
}
F_30 ( & V_35 ) ;
return V_16 ;
}
static unsigned long F_32 ( unsigned long V_40 )
{
#ifdef F_33
int V_41 ;
unsigned long V_42 = 0 ;
F_34 (node, N_HIGH_MEMORY) {
struct V_43 * V_44 =
& F_35 ( V_41 ) -> V_45 [ V_46 ] ;
V_42 += F_36 ( V_44 , V_47 ) +
F_37 ( V_44 ) ;
}
return F_38 ( V_42 , V_40 ) ;
#else
return 0 ;
#endif
}
unsigned long F_3 ( void )
{
unsigned long V_42 ;
V_42 = F_39 ( V_47 ) + F_40 () ;
if ( ! V_48 )
V_42 -= F_32 ( V_42 ) ;
return V_42 + 1 ;
}
void F_41 ( unsigned long * V_49 , unsigned long * V_50 )
{
unsigned long V_51 ;
unsigned long V_32 ;
unsigned long V_52 ( V_53 ) ;
struct V_26 * V_27 ;
if ( ! V_4 || ! V_17 )
V_53 = F_3 () ;
if ( V_4 )
V_32 = F_42 ( V_4 , V_5 ) ;
else
V_32 = ( V_6 * V_53 ) / 100 ;
if ( V_17 )
V_51 = F_42 ( V_17 , V_5 ) ;
else
V_51 = ( V_18 * V_53 ) / 100 ;
if ( V_51 >= V_32 )
V_51 = V_32 / 2 ;
V_27 = V_54 ;
if ( V_27 -> V_25 & V_55 || F_43 ( V_27 ) ) {
V_51 += V_51 / 4 ;
V_32 += V_32 / 4 ;
}
* V_49 = V_51 ;
* V_50 = V_32 ;
}
unsigned long F_44 ( struct V_21 * V_22 , unsigned long V_32 )
{
T_4 V_31 ;
long V_29 , V_30 ;
F_20 ( V_22 , & V_29 , & V_30 ) ;
V_31 = ( V_32 * ( 100 - V_38 ) ) / 100 ;
V_31 *= V_29 ;
F_26 ( V_31 , V_30 ) ;
V_31 += ( V_32 * V_22 -> V_34 ) / 100 ;
if ( V_31 > ( V_32 * V_22 -> V_36 ) / 100 )
V_31 = V_32 * V_22 -> V_36 / 100 ;
return V_31 ;
}
static void F_45 ( struct V_56 * V_57 ,
unsigned long V_58 )
{
long V_59 , V_60 ;
long V_61 , V_62 ;
unsigned long V_63 ;
unsigned long V_64 ;
unsigned long V_65 ;
unsigned long V_66 = 0 ;
unsigned long V_67 = 1 ;
bool V_68 = false ;
struct V_21 * V_22 = V_57 -> V_21 ;
for (; ; ) {
struct V_69 V_70 = {
. V_71 = V_72 ,
. V_73 = NULL ,
. V_74 = V_58 ,
. V_75 = 1 ,
} ;
V_59 = F_39 ( V_76 ) +
F_39 ( V_77 ) ;
V_61 = F_39 ( V_78 ) ;
F_41 ( & V_63 , & V_64 ) ;
if ( V_59 + V_61 <=
( V_63 + V_64 ) / 2 )
break;
V_65 = F_44 ( V_22 , V_64 ) ;
V_65 = F_25 ( V_54 , V_65 ) ;
if ( V_65 < 2 * F_46 ( V_22 ) ) {
V_60 = F_47 ( V_22 , V_79 ) ;
V_62 = F_47 ( V_22 , V_80 ) ;
} else {
V_60 = F_48 ( V_22 , V_79 ) ;
V_62 = F_48 ( V_22 , V_80 ) ;
}
V_68 =
( V_60 + V_62 > V_65 )
|| ( V_59 + V_61 > V_64 ) ;
if ( ! V_68 )
break;
if ( ! V_22 -> V_68 )
V_22 -> V_68 = 1 ;
F_49 ( & V_70 , V_22 ) ;
if ( V_60 > V_65 ) {
F_50 ( & V_22 -> V_81 , & V_70 ) ;
V_66 += V_58 - V_70 . V_74 ;
F_51 ( & V_70 , V_22 ) ;
if ( V_66 >= V_58 )
break;
}
F_52 ( & V_70 , V_22 ) ;
F_53 ( V_82 ) ;
F_54 ( V_67 ) ;
V_67 <<= 1 ;
if ( V_67 > V_83 / 10 )
V_67 = V_83 / 10 ;
}
if ( ! V_68 && V_22 -> V_68 )
V_22 -> V_68 = 0 ;
if ( F_55 ( V_22 ) )
return;
if ( ( V_84 && V_66 ) ||
( ! V_84 && ( V_59 > V_63 ) ) )
F_56 ( V_22 ) ;
}
void F_57 ( struct V_85 * V_85 , int V_86 )
{
if ( F_58 ( V_85 ) || V_86 ) {
struct V_56 * V_57 = F_59 ( V_85 ) ;
if ( V_57 )
F_60 ( V_57 ) ;
}
}
void F_61 ( struct V_56 * V_57 ,
unsigned long V_87 )
{
unsigned long V_88 ;
unsigned long * V_89 ;
V_88 = V_2 ;
if ( V_57 -> V_21 -> V_68 )
V_88 = 8 ;
F_62 () ;
V_89 = & F_63 ( V_90 ) ;
* V_89 += V_87 ;
if ( F_64 ( * V_89 >= V_88 ) ) {
V_88 = F_1 ( * V_89 ) ;
* V_89 = 0 ;
F_65 () ;
F_45 ( V_57 , V_88 ) ;
return;
}
F_65 () ;
}
void F_66 ( T_5 V_91 )
{
unsigned long V_63 ;
unsigned long V_64 ;
for ( ; ; ) {
F_41 ( & V_63 , & V_64 ) ;
V_64 += V_64 / 10 ;
if ( F_39 ( V_77 ) +
F_39 ( V_78 ) <= V_64 )
break;
F_67 ( V_92 , V_83 / 10 ) ;
if ( ( V_91 & ( V_93 | V_94 ) ) != ( V_93 | V_94 ) )
break;
}
}
int F_68 ( V_10 * V_11 , int V_12 ,
void T_1 * V_13 , T_2 * V_95 , T_3 * V_15 )
{
F_69 ( V_11 , V_12 , V_13 , V_95 , V_15 ) ;
F_70 () ;
return 0 ;
}
void F_71 ( unsigned long V_96 )
{
struct V_97 * V_98 = (struct V_97 * ) V_96 ;
int V_99 = F_39 ( V_76 ) +
F_39 ( V_77 ) ;
if ( F_72 ( & V_98 -> V_21 ) )
F_73 ( & V_98 -> V_21 , V_99 ) ;
}
void F_74 ( struct V_21 * V_100 )
{
F_75 ( & V_100 -> V_101 , V_102 + V_84 ) ;
}
void F_76 ( void )
{
struct V_21 * V_22 ;
F_77 () ;
F_78 (bdi, &bdi_list, bdi_list)
F_79 ( & V_22 -> V_101 ) ;
F_80 () ;
}
void F_81 ( void )
{
V_2 = V_103 / ( F_82 () * 32 ) ;
if ( V_2 < 16 )
V_2 = 16 ;
if ( V_2 * V_104 > 4096 * 1024 )
V_2 = ( 4096 * 1024 ) / V_104 ;
}
static int T_6
F_83 ( struct V_105 * V_106 , unsigned long V_107 , void * V_108 )
{
F_81 () ;
return V_109 ;
}
void T_7 F_84 ( void )
{
int V_7 ;
F_81 () ;
F_85 ( & V_110 ) ;
V_7 = F_2 () ;
F_86 ( & V_8 , V_7 ) ;
F_86 ( & V_9 , V_7 ) ;
}
void F_87 ( struct V_56 * V_57 ,
T_8 V_111 , T_8 V_112 )
{
#define F_88 4096
unsigned long V_113 ;
do {
F_89 ( & V_57 -> V_114 ) ;
V_113 = F_90 ( & V_57 -> V_115 ,
& V_111 , V_112 , F_88 ,
V_116 , V_117 ) ;
F_91 ( & V_57 -> V_114 ) ;
F_92 ( V_113 > F_88 ) ;
F_93 () ;
} while ( V_113 >= F_88 && V_111 );
}
int F_94 ( struct V_56 * V_57 ,
struct V_69 * V_70 , T_9 V_118 ,
void * V_96 )
{
int V_16 = 0 ;
int V_119 = 0 ;
struct V_120 V_121 ;
int V_99 ;
T_8 V_52 ( V_122 ) ;
T_8 V_123 ;
T_8 V_112 ;
T_8 V_124 ;
int V_125 ;
int V_126 = 0 ;
int V_127 ;
F_95 ( & V_121 , 0 ) ;
if ( V_70 -> V_75 ) {
V_122 = V_57 -> V_122 ;
V_123 = V_122 ;
if ( V_123 == 0 )
V_125 = 1 ;
else
V_125 = 0 ;
V_112 = - 1 ;
} else {
V_123 = V_70 -> V_128 >> V_129 ;
V_112 = V_70 -> V_130 >> V_129 ;
if ( V_70 -> V_128 == 0 && V_70 -> V_130 == V_131 )
V_126 = 1 ;
V_125 = 1 ;
}
if ( V_70 -> V_71 == V_132 )
V_127 = V_117 ;
else
V_127 = V_116 ;
V_133:
if ( V_70 -> V_71 == V_132 )
F_87 ( V_57 , V_123 , V_112 ) ;
V_124 = V_123 ;
while ( ! V_119 && ( V_123 <= V_112 ) ) {
int V_134 ;
V_99 = F_96 ( & V_121 , V_57 , & V_123 , V_127 ,
F_38 ( V_112 - V_123 , ( T_8 ) V_135 - 1 ) + 1 ) ;
if ( V_99 == 0 )
break;
for ( V_134 = 0 ; V_134 < V_99 ; V_134 ++ ) {
struct V_85 * V_85 = V_121 . V_136 [ V_134 ] ;
if ( V_85 -> V_123 > V_112 ) {
V_119 = 1 ;
break;
}
V_124 = V_85 -> V_123 ;
F_97 ( V_85 ) ;
if ( F_64 ( V_85 -> V_57 != V_57 ) ) {
V_137:
F_98 ( V_85 ) ;
continue;
}
if ( ! F_99 ( V_85 ) ) {
goto V_137;
}
if ( F_100 ( V_85 ) ) {
if ( V_70 -> V_71 != V_72 )
F_101 ( V_85 ) ;
else
goto V_137;
}
F_102 ( F_100 ( V_85 ) ) ;
if ( ! F_103 ( V_85 ) )
goto V_137;
F_104 ( V_70 , V_57 -> V_21 ) ;
V_16 = (* V_118)( V_85 , V_70 , V_96 ) ;
if ( F_64 ( V_16 ) ) {
if ( V_16 == V_138 ) {
F_98 ( V_85 ) ;
V_16 = 0 ;
} else {
V_124 = V_85 -> V_123 + 1 ;
V_119 = 1 ;
break;
}
}
if ( -- V_70 -> V_74 <= 0 &&
V_70 -> V_71 == V_72 ) {
V_119 = 1 ;
break;
}
}
F_105 ( & V_121 ) ;
F_93 () ;
}
if ( ! V_125 && ! V_119 ) {
V_125 = 1 ;
V_123 = 0 ;
V_112 = V_122 - 1 ;
goto V_133;
}
if ( V_70 -> V_75 || ( V_126 && V_70 -> V_74 > 0 ) )
V_57 -> V_122 = V_124 ;
return V_16 ;
}
static int F_106 ( struct V_85 * V_85 , struct V_69 * V_70 ,
void * V_96 )
{
struct V_56 * V_57 = V_96 ;
int V_16 = V_57 -> V_139 -> V_118 ( V_85 , V_70 ) ;
F_107 ( V_57 , V_16 ) ;
return V_16 ;
}
int F_108 ( struct V_56 * V_57 ,
struct V_69 * V_70 )
{
struct V_140 V_141 ;
int V_16 ;
if ( ! V_57 -> V_139 -> V_118 )
return 0 ;
F_109 ( & V_141 ) ;
V_16 = F_94 ( V_57 , V_70 , F_106 , V_57 ) ;
F_110 ( & V_141 ) ;
return V_16 ;
}
int F_111 ( struct V_56 * V_57 , struct V_69 * V_70 )
{
int V_16 ;
if ( V_70 -> V_74 <= 0 )
return 0 ;
if ( V_57 -> V_139 -> V_142 )
V_16 = V_57 -> V_139 -> V_142 ( V_57 , V_70 ) ;
else
V_16 = F_108 ( V_57 , V_70 ) ;
return V_16 ;
}
int F_112 ( struct V_85 * V_85 , int V_143 )
{
struct V_56 * V_57 = V_85 -> V_57 ;
int V_16 = 0 ;
struct V_69 V_70 = {
. V_71 = V_132 ,
. V_74 = 1 ,
} ;
F_102 ( ! F_113 ( V_85 ) ) ;
if ( V_143 )
F_101 ( V_85 ) ;
if ( F_103 ( V_85 ) ) {
F_114 ( V_85 ) ;
V_16 = V_57 -> V_139 -> V_118 ( V_85 , & V_70 ) ;
if ( V_16 == 0 && V_143 ) {
F_101 ( V_85 ) ;
if ( F_115 ( V_85 ) )
V_16 = - V_144 ;
}
F_116 ( V_85 ) ;
} else {
F_98 ( V_85 ) ;
}
return V_16 ;
}
int F_117 ( struct V_85 * V_85 )
{
if ( ! F_99 ( V_85 ) )
return ! F_118 ( V_85 ) ;
return 0 ;
}
void F_119 ( struct V_85 * V_85 , struct V_56 * V_57 )
{
if ( F_120 ( V_57 ) ) {
F_121 ( V_85 , V_76 ) ;
F_121 ( V_85 , V_145 ) ;
F_122 ( V_57 -> V_21 , V_79 ) ;
F_18 ( V_54 ) ;
F_123 ( V_104 ) ;
}
}
void F_124 ( struct V_85 * V_85 )
{
F_125 ( V_85 , V_78 ) ;
F_125 ( V_85 , V_146 ) ;
}
int F_126 ( struct V_85 * V_85 )
{
if ( ! F_118 ( V_85 ) ) {
struct V_56 * V_57 = F_59 ( V_85 ) ;
struct V_56 * V_147 ;
if ( ! V_57 )
return 1 ;
F_89 ( & V_57 -> V_114 ) ;
V_147 = F_59 ( V_85 ) ;
if ( V_147 ) {
F_102 ( V_147 != V_57 ) ;
F_92 ( ! F_127 ( V_85 ) && ! F_128 ( V_85 ) ) ;
F_119 ( V_85 , V_57 ) ;
F_129 ( & V_57 -> V_115 ,
F_130 ( V_85 ) , V_116 ) ;
}
F_91 ( & V_57 -> V_114 ) ;
if ( V_57 -> V_148 ) {
F_131 ( V_57 -> V_148 , V_149 ) ;
}
return 1 ;
}
return 0 ;
}
int F_132 ( struct V_69 * V_70 , struct V_85 * V_85 )
{
V_70 -> V_150 ++ ;
return F_126 ( V_85 ) ;
}
int F_58 ( struct V_85 * V_85 )
{
struct V_56 * V_57 = F_59 ( V_85 ) ;
if ( F_133 ( V_57 ) ) {
int (* F_134)( struct V_85 * ) = V_57 -> V_139 -> F_58 ;
F_135 ( V_85 ) ;
#ifdef F_136
if ( ! F_134 )
F_134 = V_151 ;
#endif
return (* F_134)( V_85 ) ;
}
if ( ! F_99 ( V_85 ) ) {
if ( ! F_118 ( V_85 ) )
return 1 ;
}
return 0 ;
}
int F_137 ( struct V_85 * V_85 )
{
int V_16 ;
F_97 ( V_85 ) ;
V_16 = F_58 ( V_85 ) ;
F_98 ( V_85 ) ;
return V_16 ;
}
int F_103 ( struct V_85 * V_85 )
{
struct V_56 * V_57 = F_59 ( V_85 ) ;
F_102 ( ! F_113 ( V_85 ) ) ;
if ( V_57 && F_120 ( V_57 ) ) {
if ( F_138 ( V_85 ) )
F_58 ( V_85 ) ;
if ( F_139 ( V_85 ) ) {
F_140 ( V_85 , V_76 ) ;
F_141 ( V_57 -> V_21 ,
V_79 ) ;
return 1 ;
}
return 0 ;
}
return F_139 ( V_85 ) ;
}
int F_142 ( struct V_85 * V_85 )
{
struct V_56 * V_57 = F_59 ( V_85 ) ;
int V_16 ;
if ( V_57 ) {
struct V_21 * V_22 = V_57 -> V_21 ;
unsigned long V_25 ;
F_143 ( & V_57 -> V_114 , V_25 ) ;
V_16 = F_144 ( V_85 ) ;
if ( V_16 ) {
F_145 ( & V_57 -> V_115 ,
F_130 ( V_85 ) ,
V_152 ) ;
if ( F_146 ( V_22 ) ) {
F_147 ( V_22 , V_80 ) ;
F_13 ( V_22 ) ;
}
}
F_148 ( & V_57 -> V_114 , V_25 ) ;
} else {
V_16 = F_144 ( V_85 ) ;
}
if ( V_16 )
F_140 ( V_85 , V_78 ) ;
return V_16 ;
}
int F_149 ( struct V_85 * V_85 )
{
struct V_56 * V_57 = F_59 ( V_85 ) ;
int V_16 ;
if ( V_57 ) {
struct V_21 * V_22 = V_57 -> V_21 ;
unsigned long V_25 ;
F_143 ( & V_57 -> V_114 , V_25 ) ;
V_16 = F_150 ( V_85 ) ;
if ( ! V_16 ) {
F_129 ( & V_57 -> V_115 ,
F_130 ( V_85 ) ,
V_152 ) ;
if ( F_146 ( V_22 ) )
F_122 ( V_22 , V_80 ) ;
}
if ( ! F_99 ( V_85 ) )
F_145 ( & V_57 -> V_115 ,
F_130 ( V_85 ) ,
V_116 ) ;
F_145 ( & V_57 -> V_115 ,
F_130 ( V_85 ) ,
V_117 ) ;
F_148 ( & V_57 -> V_114 , V_25 ) ;
} else {
V_16 = F_150 ( V_85 ) ;
}
if ( ! V_16 )
F_124 ( V_85 ) ;
return V_16 ;
}
int F_151 ( struct V_56 * V_57 , int V_127 )
{
int V_16 ;
F_77 () ;
V_16 = F_152 ( & V_57 -> V_115 , V_127 ) ;
F_80 () ;
return V_16 ;
}
