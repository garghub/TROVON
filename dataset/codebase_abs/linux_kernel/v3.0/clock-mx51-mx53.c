static void F_1 ( T_1 div , T_1 * V_1 , T_1 * V_2 ,
T_1 V_3 , T_1 V_4 )
{
if ( div >= V_3 * V_4 ) {
* V_1 = V_3 ;
* V_2 = V_4 ;
} else if ( div >= V_3 ) {
T_1 V_5 , V_6 , V_7 , V_8 ;
V_5 = F_2 ( div , V_4 ) ;
V_7 = V_3 ;
for ( V_6 = V_3 ; V_6 >= V_5 ; V_6 -- ) {
V_8 = div % V_6 ;
if ( V_8 == 0 ) {
* V_1 = V_6 ;
break;
}
V_8 = V_6 - V_8 ;
if ( V_8 < V_7 ) {
V_7 = V_8 ;
* V_1 = V_6 ;
}
}
* V_2 = F_2 ( div , * V_1 ) ;
} else {
* V_1 = div ;
* V_2 = 1 ;
}
}
static void F_3 ( struct V_9 * V_9 , unsigned V_10 )
{
T_1 V_11 = F_4 ( V_9 -> V_12 ) ;
V_11 &= ~ ( V_13 << V_9 -> V_14 ) ;
V_11 |= V_10 << V_9 -> V_14 ;
F_5 ( V_11 , V_9 -> V_12 ) ;
}
static int F_6 ( struct V_9 * V_9 )
{
F_3 ( V_9 , V_15 ) ;
return 0 ;
}
static void F_7 ( struct V_9 * V_9 )
{
F_3 ( V_9 , V_16 ) ;
}
static int F_8 ( struct V_9 * V_9 )
{
F_3 ( V_9 , V_17 ) ;
return 0 ;
}
static void F_9 ( struct V_9 * V_9 )
{
F_3 ( V_9 , V_17 ) ;
}
static inline T_1 F_10 ( struct V_9 * V_18 , struct V_9 * V_19 ,
struct V_9 * V_20 , struct V_9 * V_21 , struct V_9 * V_22 )
{
if ( V_18 == V_19 )
return 0 ;
else if ( V_18 == V_20 )
return 1 ;
else if ( V_18 == V_21 )
return 2 ;
else if ( V_18 == V_22 )
return 3 ;
else
F_11 () ;
return - V_23 ;
}
static inline void T_2 * F_12 ( struct V_9 * V_24 )
{
if ( V_24 == & V_25 )
return V_26 ;
else if ( V_24 == & V_27 )
return V_28 ;
else if ( V_24 == & V_29 )
return V_30 ;
else
F_11 () ;
return NULL ;
}
static inline void T_2 * F_13 ( struct V_9 * V_24 )
{
if ( V_24 == & V_25 )
return V_31 ;
else if ( V_24 == & V_27 )
return V_32 ;
else if ( V_24 == & V_29 )
return V_33 ;
else if ( V_24 == & V_34 )
return V_35 ;
else
F_11 () ;
return NULL ;
}
static inline void T_2 * F_14 ( struct V_9 * V_24 )
{
if ( F_15 () )
return F_12 ( V_24 ) ;
else
return F_13 ( V_24 ) ;
}
static unsigned long F_16 ( struct V_9 * V_9 )
{
long V_36 , V_37 , V_38 , V_39 , V_40 , V_41 ;
unsigned long V_42 , V_43 , V_44 , V_45 , V_46 , V_47 ;
void T_2 * V_48 ;
T_3 V_49 ;
unsigned long V_50 ;
V_50 = F_17 ( V_9 -> V_18 ) ;
V_48 = F_14 ( V_9 ) ;
V_45 = F_4 ( V_48 + V_51 ) ;
V_46 = V_45 & V_52 ;
V_47 = V_45 & V_53 ;
if ( V_46 == 0 ) {
V_42 = F_4 ( V_48 + V_54 ) ;
V_43 = F_4 ( V_48 + V_55 ) ;
V_44 = F_4 ( V_48 + V_56 ) ;
} else {
V_42 = F_4 ( V_48 + V_57 ) ;
V_43 = F_4 ( V_48 + V_58 ) ;
V_44 = F_4 ( V_48 + V_59 ) ;
}
V_39 = V_42 & V_60 ;
V_36 = ( V_42 & V_61 ) >> V_62 ;
V_36 = ( V_36 <= 5 ) ? 5 : V_36 ;
V_38 = V_43 & V_63 ;
V_37 = V_41 = V_44 & V_64 ;
if ( V_37 >= 0x04000000 ) {
V_37 |= 0xFC000000 ;
V_41 = - V_37 ;
}
V_40 = 2 * V_50 ;
if ( V_47 != 0 )
V_40 *= 2 ;
V_40 /= ( V_39 + 1 ) ;
V_49 = ( V_65 ) V_40 * V_41 ;
F_18 ( V_49 , V_38 + 1 ) ;
if ( V_37 < 0 )
V_49 = - V_49 ;
V_49 = ( V_40 * V_36 ) + V_49 ;
return V_49 ;
}
static int F_19 ( struct V_9 * V_9 , unsigned long V_66 )
{
T_1 V_11 ;
void T_2 * V_48 ;
long V_36 , V_39 , V_37 , V_38 = 999999 ;
T_3 V_67 ;
unsigned long V_68 ;
unsigned long V_46 , V_45 ;
unsigned long V_50 ;
V_50 = F_17 ( V_9 -> V_18 ) ;
V_48 = F_14 ( V_9 ) ;
V_68 = 4 * V_50 ;
V_39 = V_36 = - 1 ;
while ( ++ V_39 < 16 && V_36 < 5 )
V_36 = V_66 * ( V_39 + 1 ) / V_68 ;
if ( V_36 > 15 )
return - V_23 ;
V_39 -- ;
V_67 = V_66 * ( V_39 + 1 ) - V_68 * V_36 ;
F_18 ( V_67 , V_68 / 1000000 ) ;
V_37 = ( long ) V_67 ;
V_45 = F_4 ( V_48 + V_51 ) ;
F_5 ( V_45 | 0x1000L , V_48 + V_51 ) ;
V_46 = V_45 & V_52 ;
if ( V_46 == 0 ) {
V_11 = V_36 << 4 | V_39 ;
F_5 ( V_11 , V_48 + V_54 ) ;
F_5 ( V_38 , V_48 + V_55 ) ;
F_5 ( V_37 , V_48 + V_56 ) ;
} else {
V_11 = V_36 << 4 | V_39 ;
F_5 ( V_11 , V_48 + V_57 ) ;
F_5 ( V_38 , V_48 + V_58 ) ;
F_5 ( V_37 , V_48 + V_59 ) ;
}
return 0 ;
}
static int F_20 ( struct V_9 * V_9 )
{
T_1 V_11 ;
void T_2 * V_48 ;
int V_69 = 0 ;
V_48 = F_14 ( V_9 ) ;
V_11 = F_4 ( V_48 + V_51 ) | V_70 ;
F_5 ( V_11 , V_48 + V_51 ) ;
do {
V_11 = F_4 ( V_48 + V_51 ) ;
if ( V_11 & V_71 )
break;
F_21 ( 1 ) ;
} while ( ++ V_69 < V_72 );
if ( V_69 == V_72 ) {
F_22 ( L_1 ) ;
return - V_23 ;
}
return 0 ;
}
static void F_23 ( struct V_9 * V_9 )
{
T_1 V_11 ;
void T_2 * V_48 ;
V_48 = F_14 ( V_9 ) ;
V_11 = F_4 ( V_48 + V_51 ) & ~ V_70 ;
F_5 ( V_11 , V_48 + V_51 ) ;
}
static int F_24 ( struct V_9 * V_9 , struct V_9 * V_18 )
{
T_1 V_11 , V_73 ;
V_11 = F_4 ( V_74 ) ;
if ( V_18 == & V_25 ) {
V_11 &= ~ V_75 ;
F_5 ( V_11 , V_74 ) ;
V_11 = F_4 ( V_74 ) ;
V_11 &= ~ V_76 ;
V_11 |= ( V_77 <<
V_78 ) ;
} else {
if ( V_18 == & V_79 ) {
V_73 = V_77 ;
} else if ( V_18 == & V_27 ) {
V_73 = V_80 ;
} else if ( V_18 == & V_29 ) {
V_73 = V_81 ;
} else
return - V_23 ;
V_11 &= ~ V_76 ;
V_11 |= ( V_73 << V_78 ) ;
F_5 ( V_11 , V_74 ) ;
V_11 = F_4 ( V_74 ) ;
V_11 |= V_75 ;
}
F_5 ( V_11 , V_74 ) ;
return 0 ;
}
static unsigned long F_25 ( struct V_9 * V_9 )
{
T_1 V_11 , div ;
unsigned long V_50 ;
V_50 = F_17 ( V_9 -> V_18 ) ;
V_11 = F_4 ( V_74 ) ;
if ( V_9 -> V_18 == & V_27 ) {
div = ( ( V_11 & V_82 ) >>
V_83 ) + 1 ;
} else if ( V_9 -> V_18 == & V_29 ) {
div = ( ( V_11 & V_84 ) >>
V_85 ) + 1 ;
} else
div = 1 ;
return V_50 / div ;
}
static int F_26 ( struct V_9 * V_9 , struct V_9 * V_18 )
{
T_1 V_11 ;
V_11 = F_4 ( V_74 ) ;
if ( V_18 == & V_27 )
V_11 &= ~ V_86 ;
else
V_11 |= V_86 ;
F_5 ( V_11 , V_74 ) ;
return 0 ;
}
static int F_27 ( struct V_9 * V_9 , struct V_9 * V_18 )
{
T_1 V_11 ;
if ( V_18 == & V_87 )
V_11 = F_4 ( V_74 ) & ~ V_88 ;
else
return - V_23 ;
F_5 ( V_11 , V_74 ) ;
return 0 ;
}
static unsigned long F_28 ( struct V_9 * V_9 )
{
T_1 V_89 , div ;
unsigned long V_50 ;
V_50 = F_17 ( V_9 -> V_18 ) ;
V_89 = F_4 ( V_90 ) ;
div = ( V_89 & V_91 ) + 1 ;
return V_50 / div ;
}
static int F_29 ( struct V_9 * V_9 , unsigned long V_66 )
{
T_1 V_11 , V_92 ;
unsigned long V_50 ;
V_50 = F_17 ( V_9 -> V_18 ) ;
V_92 = V_50 / V_66 - 1 ;
V_11 = F_4 ( V_90 ) ;
V_11 &= ~ V_91 ;
V_11 |= V_92 << V_93 ;
F_5 ( V_11 , V_90 ) ;
return 0 ;
}
static int F_30 ( struct V_9 * V_9 , struct V_9 * V_18 )
{
T_1 V_11 , V_94 ;
int V_69 = 0 ;
V_94 = F_10 ( V_18 , & V_95 , & V_29 , & V_79 , NULL ) ;
V_11 = F_4 ( V_96 ) & ~ V_97 ;
V_11 |= V_94 << V_98 ;
F_5 ( V_11 , V_96 ) ;
do {
V_11 = F_4 ( V_99 ) ;
if ( ! ( V_11 & V_100 ) )
break;
F_21 ( 1 ) ;
} while ( ++ V_69 < V_72 );
if ( V_69 == V_72 ) {
F_22 ( L_2 ) ;
return - V_23 ;
}
return 0 ;
}
static int F_31 ( struct V_9 * V_9 , struct V_9 * V_18 )
{
T_1 V_11 ;
V_11 = F_4 ( V_101 ) ;
if ( V_18 == & V_27 )
V_11 &= ~ V_102 ;
else if ( V_18 == & V_103 )
V_11 |= V_102 ;
else
return - V_23 ;
F_5 ( V_11 , V_101 ) ;
return 0 ;
}
static unsigned long F_32 ( struct V_9 * V_9 )
{
T_1 V_11 , div ;
unsigned long V_50 ;
V_50 = F_17 ( V_9 -> V_18 ) ;
V_11 = F_4 ( V_101 ) ;
div = ( ( V_11 & V_104 ) >>
V_105 ) + 1 ;
return V_50 / div ;
}
static int F_33 ( struct V_9 * V_9 , unsigned long V_66 )
{
T_1 V_11 , div ;
unsigned long V_50 ;
int V_69 = 0 ;
V_50 = F_17 ( V_9 -> V_18 ) ;
div = V_50 / V_66 ;
if ( div > 8 || div < 1 || ( ( V_50 / div ) != V_66 ) )
return - V_23 ;
V_11 = F_4 ( V_101 ) ;
V_11 &= ~ V_104 ;
V_11 |= ( div - 1 ) << V_105 ;
F_5 ( V_11 , V_101 ) ;
do {
V_11 = F_4 ( V_99 ) ;
if ( ! ( V_11 & V_106 ) )
break;
F_21 ( 1 ) ;
} while ( ++ V_69 < V_72 );
if ( V_69 == V_72 ) {
F_22 ( L_3 ) ;
return - V_23 ;
}
return 0 ;
}
static unsigned long F_34 ( struct V_9 * V_9 ,
unsigned long V_66 )
{
T_1 div ;
unsigned long V_50 ;
V_50 = F_17 ( V_9 -> V_18 ) ;
div = V_50 / V_66 ;
if ( div > 8 )
div = 8 ;
else if ( div == 0 )
div ++ ;
return V_50 / div ;
}
static int F_35 ( struct V_9 * V_9 )
{
T_1 V_11 ;
F_6 ( V_9 ) ;
V_11 = F_4 ( V_107 ) ;
if ( F_15 () )
V_11 &= ~ V_108 ;
else if ( F_36 () )
V_11 &= ~ V_109 ;
F_5 ( V_11 , V_107 ) ;
return 0 ;
}
static void F_37 ( struct V_9 * V_9 )
{
T_1 V_11 ;
F_9 ( V_9 ) ;
V_11 = F_4 ( V_107 ) ;
if ( F_15 () )
V_11 |= V_108 ;
else if ( F_36 () )
V_11 &= ~ V_109 ;
F_5 ( V_11 , V_107 ) ;
}
static unsigned long F_38 ( struct V_9 * V_9 )
{
T_1 V_11 , div ;
unsigned long V_50 ;
V_50 = F_17 ( V_9 -> V_18 ) ;
V_11 = F_4 ( V_101 ) ;
div = ( ( V_11 & V_110 ) >>
V_111 ) + 1 ;
return V_50 / div ;
}
static unsigned long F_39 ( struct V_9 * V_9 )
{
T_1 V_11 , V_112 , V_113 , V_114 ;
unsigned long V_50 ;
V_50 = F_17 ( V_9 -> V_18 ) ;
if ( V_9 -> V_18 == & V_115 || V_9 -> V_18 == & V_79 ) {
V_11 = F_4 ( V_101 ) ;
V_112 = ( ( V_11 & V_116 ) >>
V_117 ) + 1 ;
V_113 = ( ( V_11 & V_118 ) >>
V_119 ) + 1 ;
V_114 = ( ( V_11 & V_120 ) >>
V_121 ) + 1 ;
return V_50 / ( V_112 * V_113 * V_114 ) ;
} else if ( V_9 -> V_18 == & V_122 )
return V_50 ;
else
F_11 () ;
}
static int F_40 ( struct V_9 * V_9 , struct V_9 * V_18 )
{
T_1 V_11 ;
V_11 = F_4 ( V_96 ) ;
V_11 &= ~ V_123 ;
V_11 &= ~ V_124 ;
if ( V_18 == & V_122 )
V_11 |= V_124 ;
else if ( V_18 == & V_79 )
V_11 |= V_123 ;
else if ( V_18 != & V_115 )
return - V_23 ;
F_5 ( V_11 , V_96 ) ;
return 0 ;
}
static unsigned long F_41 ( struct V_9 * V_9 )
{
unsigned long V_66 ;
T_1 V_11 , div ;
V_11 = F_4 ( V_101 ) ;
div = ( ( V_11 & V_125 ) >>
V_126 ) + 1 ;
V_66 = F_17 ( V_9 -> V_18 ) / div ;
F_42 ( V_66 == 0 ) ;
return V_66 ;
}
static unsigned long F_43 ( struct V_9 * V_9 ,
unsigned long V_66 )
{
T_1 div ;
unsigned long V_50 = F_17 ( V_9 -> V_18 ) ;
if ( ! V_66 )
return - V_23 ;
div = V_50 / V_66 ;
if ( V_50 % V_66 )
div ++ ;
if ( div > 8 )
return - V_23 ;
return V_50 / div ;
}
static int F_44 ( struct V_9 * V_9 , unsigned long V_66 )
{
T_1 V_11 , div ;
div = F_17 ( V_9 -> V_18 ) / V_66 ;
if ( div == 0 )
div ++ ;
if ( ( ( F_17 ( V_9 -> V_18 ) / div ) != V_66 ) || ( div > 8 ) )
return - V_23 ;
V_11 = F_4 ( V_101 ) ;
V_11 &= ~ V_125 ;
V_11 |= ( div - 1 ) << V_126 ;
F_5 ( V_11 , V_101 ) ;
while ( F_4 ( V_99 ) &
V_127 ) {
}
return 0 ;
}
static unsigned long F_45 ( struct V_9 * V_9 )
{
return V_128 ;
}
static unsigned long F_46 ( struct V_9 * V_9 )
{
return V_129 ;
}
static unsigned long F_47 ( struct V_9 * V_9 )
{
return V_130 ;
}
static unsigned long F_48 ( struct V_9 * V_9 )
{
return V_131 ;
}
static unsigned long F_49 ( struct V_9 * V_9 )
{
T_1 V_11 , div ;
V_11 = F_4 ( V_101 ) ;
div = ( ( V_11 & V_132 ) >>
V_133 ) + 1 ;
return F_17 ( V_9 -> V_18 ) / div ;
}
static unsigned long F_50 ( struct V_9 * V_9 )
{
unsigned long V_66 ;
T_1 V_11 , div ;
V_11 = F_4 ( V_101 ) ;
div = ( ( V_11 & V_134 ) >>
V_135 ) + 1 ;
V_66 = F_17 ( V_9 -> V_18 ) / div ;
return V_66 ;
}
static int F_51 ( struct V_9 * V_9 )
{
T_1 V_11 ;
F_6 ( V_9 ) ;
V_11 = F_4 ( V_136 ) ;
V_11 &= ~ V_137 ;
F_5 ( V_11 , V_136 ) ;
V_11 = F_4 ( V_107 ) ;
V_11 &= ~ V_138 ;
F_5 ( V_11 , V_107 ) ;
return 0 ;
}
static void F_52 ( struct V_9 * V_9 )
{
T_1 V_11 ;
F_7 ( V_9 ) ;
V_11 = F_4 ( V_136 ) ;
V_11 |= V_137 ;
F_5 ( V_11 , V_136 ) ;
V_11 = F_4 ( V_107 ) ;
V_11 |= V_138 ;
F_5 ( V_11 , V_107 ) ;
}
static int F_53 ( struct V_9 * V_9 )
{
T_1 V_11 ;
F_6 ( V_9 ) ;
V_11 = F_4 ( V_136 ) ;
V_11 &= ~ V_139 ;
F_5 ( V_11 , V_136 ) ;
V_11 = F_4 ( V_107 ) ;
V_11 &= ~ V_140 ;
F_5 ( V_11 , V_107 ) ;
return 0 ;
}
static void F_54 ( struct V_9 * V_9 )
{
T_1 V_11 ;
F_7 ( V_9 ) ;
V_11 = F_4 ( V_136 ) ;
V_11 |= V_139 ;
F_5 ( V_11 , V_136 ) ;
V_11 = F_4 ( V_107 ) ;
V_11 |= V_140 ;
F_5 ( V_11 , V_107 ) ;
}
static int F_55 ( struct V_9 * V_9 , struct V_9 * V_18 )
{
T_1 V_11 ;
V_11 = F_4 ( V_141 ) & ~ V_142 ;
if ( V_18 == & V_29 )
V_11 |= 1 << V_143 ;
F_5 ( V_11 , V_141 ) ;
return 0 ;
}
static int F_56 ( struct V_9 * V_9 , struct V_9 * V_18 )
{
T_1 V_11 ;
V_11 = F_4 ( V_141 ) ;
if ( V_18 == & V_144 )
V_11 &= ~ V_145 ;
else if ( V_18 == & V_146 )
V_11 |= V_145 ;
else
return - V_23 ;
F_5 ( V_11 , V_141 ) ;
return 0 ;
}
static int F_57 ( struct V_9 * V_9 , struct V_9 * V_18 )
{
T_1 V_11 ;
V_11 = F_4 ( V_141 ) ;
if ( V_18 == & V_144 )
V_11 &= ~ V_147 ;
else if ( V_18 == & V_146 )
V_11 |= V_147 ;
else
return - V_23 ;
F_5 ( V_11 , V_141 ) ;
return 0 ;
}
static int F_58 ( struct V_9 * V_9 , struct V_9 * V_18 )
{
T_1 V_11 ;
V_11 = F_4 ( V_141 ) ;
if ( V_18 == & V_144 )
V_11 &= ~ V_148 ;
else if ( V_18 == & V_149 )
V_11 |= V_148 ;
else
return - V_23 ;
F_5 ( V_11 , V_141 ) ;
return 0 ;
}
static int F_59 ( struct V_9 * V_9 , struct V_9 * V_18 )
{
T_1 V_11 ;
V_11 = F_4 ( V_141 ) ;
if ( V_18 == & V_144 )
V_11 &= ~ V_147 ;
else if ( V_18 == & V_149 )
V_11 |= V_147 ;
else
return - V_23 ;
F_5 ( V_11 , V_141 ) ;
return 0 ;
}
static void F_60 ( void )
{
T_1 V_11 ;
V_150 . V_151 ( & V_150 , & V_79 ) ;
V_11 = F_4 ( V_101 ) ;
V_11 &= ~ V_116 ;
V_11 &= ~ V_118 ;
V_11 &= ~ V_120 ;
V_11 |= ( 2 << V_117 ) ;
F_5 ( V_11 , V_101 ) ;
}
int T_4 F_61 ( unsigned long V_152 , unsigned long V_153 ,
unsigned long V_154 , unsigned long V_155 )
{
int V_69 ;
V_129 = V_152 ;
V_128 = V_154 ;
V_131 = V_155 ;
V_130 = V_153 ;
for ( V_69 = 0 ; V_69 < F_62 ( V_156 ) ; V_69 ++ )
F_63 ( & V_156 [ V_69 ] ) ;
F_60 () ;
F_64 ( & V_157 ) ;
F_64 ( & V_115 ) ;
F_64 ( & V_158 ) ;
F_65 () ;
F_66 ( & V_158 ) ;
F_67 () ;
F_68 ( & V_159 , & V_87 ) ;
F_68 ( & V_160 , & V_27 ) ;
F_68 ( & V_144 , & V_27 ) ;
F_68 ( & V_146 , & V_27 ) ;
F_69 ( & V_144 , 166250000 ) ;
F_69 ( & V_146 , 166250000 ) ;
F_70 ( & V_161 , F_71 ( V_162 ) ,
V_163 ) ;
return 0 ;
}
int T_4 F_72 ( unsigned long V_152 , unsigned long V_153 ,
unsigned long V_154 , unsigned long V_155 )
{
int V_69 ;
V_129 = V_152 ;
V_128 = V_154 ;
V_131 = V_155 ;
V_130 = V_153 ;
for ( V_69 = 0 ; V_69 < F_62 ( V_164 ) ; V_69 ++ )
F_63 ( & V_164 [ V_69 ] ) ;
F_60 () ;
F_68 ( & V_165 , & V_29 ) ;
F_64 ( & V_157 ) ;
F_64 ( & V_115 ) ;
F_64 ( & V_158 ) ;
F_73 () ;
F_66 ( & V_158 ) ;
F_74 () ;
F_68 ( & V_144 , & V_27 ) ;
F_68 ( & V_149 , & V_27 ) ;
F_69 ( & V_144 , 200000000 ) ;
F_69 ( & V_149 , 200000000 ) ;
F_70 ( & V_161 , F_75 ( V_166 ) ,
V_167 ) ;
return 0 ;
}
