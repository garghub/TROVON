static inline unsigned long F_1 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
return F_2 ( V_2 -> V_4 . V_5 + ( V_3 << V_2 -> V_4 . V_6 ) ) ;
}
static inline void F_3 ( struct V_1 * V_2 , unsigned V_7 ,
unsigned long V_3 )
{
F_4 ( V_7 , V_2 -> V_4 . V_5 + ( V_3 << V_2 -> V_4 . V_6 ) ) ;
}
static inline struct V_1 * F_5 ( struct V_8 * V_9 )
{
return F_6 ( V_9 , struct V_1 , V_4 ) ;
}
static unsigned int F_7 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_5 ( V_9 ) ;
if ( V_2 -> V_10 )
return V_11 | V_12 | V_13 | V_14 ;
return V_14 ;
}
static void F_8 ( struct V_1 * V_2 , bool V_15 )
{
unsigned long V_16 ;
V_16 = V_2 -> V_17 ;
if ( V_15 )
V_16 |= V_18 ;
else
V_16 &= ~ V_18 ;
if ( V_16 != V_2 -> V_17 ) {
F_3 ( V_2 , V_16 , V_19 ) ;
V_2 -> V_17 = V_16 ;
}
return;
}
static void F_9 ( struct V_1 * V_2 , bool V_15 )
{
unsigned long V_16 ;
V_16 = V_2 -> V_17 ;
if ( V_15 )
V_16 |= V_20 ;
else
V_16 &= ~ V_20 ;
if ( V_16 != V_2 -> V_17 ) {
F_3 ( V_2 , V_16 , V_19 ) ;
V_2 -> V_17 = V_16 ;
}
return;
}
static void F_10 ( struct V_8 * V_9 , unsigned int V_21 )
{
struct V_1 * V_2 = F_5 ( V_9 ) ;
unsigned long V_16 ;
int V_22 ;
V_16 = V_2 -> V_17 ;
V_2 -> V_23 = ! ! ( V_21 & V_24 ) ;
F_8 ( V_2 , V_2 -> V_23 ) ;
V_22 = ! ! ( V_21 & V_25 ) ;
F_9 ( V_2 , V_22 ) ;
return;
}
static void F_11 ( struct V_8 * V_9 , int V_26 )
{
struct V_1 * V_2 = F_5 ( V_9 ) ;
unsigned long V_27 ;
V_27 = V_2 -> V_28 ;
if ( V_26 )
V_27 |= V_29 ;
else
V_27 &= ~ V_29 ;
F_3 ( V_2 , V_27 , V_30 ) ;
V_2 -> V_28 = V_27 ;
}
static void F_12 ( struct V_1 * V_2 ,
unsigned int V_31 )
{
if ( V_2 -> V_32 )
F_13 ( F_14 ( V_31 * V_2 -> V_33 * 1000000 ,
V_2 -> V_32 ) ) ;
}
static void F_15 ( struct V_1 * V_2 , T_1 V_34 )
{
unsigned long V_35 = V_2 -> V_36 ;
if ( V_2 -> V_37 -> V_38 ) {
V_35 |= V_34 & ( V_39 | V_40 ) ;
F_3 ( V_2 , V_35 , V_41 ) ;
} else {
V_35 &= ~ V_42 ;
F_3 ( V_2 , V_35 , V_41 ) ;
F_13 ( 60 ) ;
V_35 |= V_34 & ( V_39 | V_40 ) ;
F_3 ( V_2 , V_35 , V_41 ) ;
V_35 |= V_42 ;
F_3 ( V_2 , V_35 , V_41 ) ;
}
F_1 ( V_2 , V_43 ) ;
F_12 ( V_2 , 1 ) ;
}
static int F_16 ( struct V_1 * V_2 , unsigned int V_44 )
{
unsigned long V_45 ;
unsigned int V_46 ;
unsigned long V_27 ;
int V_47 ;
if ( V_2 -> V_32 == V_44 )
return 0 ;
if ( V_2 -> V_37 -> V_48 ) {
V_45 = V_44 * 16 ;
V_47 = F_17 ( V_2 -> V_49 , V_45 ) ;
if ( V_47 < 0 ) {
F_18 ( V_2 -> V_4 . V_50 ,
L_1 , V_45 ) ;
return V_47 ;
}
V_46 = 1 ;
} else {
V_45 = F_19 ( V_2 -> V_49 ) ;
V_46 = F_20 ( V_45 , V_44 * 16 ) ;
}
V_27 = V_2 -> V_28 ;
V_27 |= V_51 ;
F_3 ( V_2 , V_27 , V_30 ) ;
F_3 ( V_2 , V_46 & 0xFF , V_52 ) ;
F_3 ( V_2 , ( ( V_46 >> 8 ) & 0xFF ) , V_53 ) ;
V_27 &= ~ V_51 ;
F_3 ( V_2 , V_27 , V_30 ) ;
F_1 ( V_2 , V_43 ) ;
V_2 -> V_32 = V_44 ;
F_12 ( V_2 , 2 ) ;
return 0 ;
}
static char F_21 ( struct V_1 * V_2 ,
unsigned long V_54 )
{
char V_55 = V_56 ;
if ( F_22 ( V_54 & V_57 ) ) {
if ( V_54 & V_58 ) {
V_55 |= V_59 ;
V_2 -> V_4 . V_60 . V_61 ++ ;
F_18 ( V_2 -> V_4 . V_50 , L_2 ) ;
} else if ( V_54 & V_62 ) {
V_55 |= V_63 ;
V_2 -> V_4 . V_60 . V_64 ++ ;
F_18 ( V_2 -> V_4 . V_50 , L_3 ) ;
} else if ( V_54 & V_65 ) {
V_55 |= V_66 ;
V_2 -> V_4 . V_60 . V_67 ++ ;
F_18 ( V_2 -> V_4 . V_50 , L_4 ) ;
} else if ( V_54 & V_68 ) {
F_18 ( V_2 -> V_4 . V_50 , L_5 ) ;
V_2 -> V_4 . V_60 . V_69 ++ ;
if ( ! ( V_54 & V_70 ) && ( V_54 & V_71 ) )
F_15 ( V_2 , V_39 ) ;
}
}
return V_55 ;
}
static int F_23 ( struct V_8 * V_9 )
{
return 0 ;
}
static void F_24 ( struct V_8 * V_9 )
{
}
static void F_25 ( struct V_1 * V_2 , int V_72 )
{
struct V_73 * V_74 = & V_2 -> V_4 . V_75 -> V_74 ;
int V_76 ;
for ( V_76 = 0 ; V_76 < V_72 ; V_76 ++ ) {
F_26 ( F_27 ( V_74 ) ) ;
if ( V_2 -> V_37 -> V_77 ) {
unsigned long V_54 = F_1 ( V_2 , V_78 ) ;
if ( ( V_54 & V_79 ) )
break;
}
F_3 ( V_2 , V_74 -> V_80 [ V_74 -> V_81 ] , V_52 ) ;
V_74 -> V_81 = ( V_74 -> V_81 + 1 ) & ( V_82 - 1 ) ;
V_2 -> V_4 . V_60 . V_83 ++ ;
}
}
static void F_28 ( struct V_1 * V_2 ,
unsigned int V_84 )
{
if ( V_84 > V_85 )
V_84 = V_85 ;
V_2 -> V_86 = V_87 ;
V_2 -> V_88 = V_84 ;
V_2 -> V_89 |= V_90 ;
F_3 ( V_2 , V_2 -> V_89 , V_53 ) ;
}
static void F_29 ( void * args )
{
struct V_1 * V_2 = args ;
struct V_73 * V_74 = & V_2 -> V_4 . V_75 -> V_74 ;
struct V_91 V_75 ;
unsigned long V_92 ;
int V_93 ;
F_30 ( V_2 -> V_94 , V_2 -> V_95 , & V_75 ) ;
V_93 = V_2 -> V_96 - V_75 . V_97 ;
F_31 ( V_2 -> V_98 ) ;
F_32 ( & V_2 -> V_4 . V_99 , V_92 ) ;
V_74 -> V_81 = ( V_74 -> V_81 + V_93 ) & ( V_82 - 1 ) ;
V_2 -> V_86 = 0 ;
if ( F_33 ( V_74 ) < V_100 )
F_34 ( & V_2 -> V_4 ) ;
F_35 ( V_2 ) ;
F_36 ( & V_2 -> V_4 . V_99 , V_92 ) ;
}
static int F_37 ( struct V_1 * V_2 ,
unsigned long V_93 )
{
struct V_73 * V_74 = & V_2 -> V_4 . V_75 -> V_74 ;
T_2 V_101 ;
F_38 ( V_2 -> V_4 . V_50 , V_2 -> V_102 ,
V_82 , V_103 ) ;
V_2 -> V_88 = V_93 & ~ ( 0xF ) ;
V_101 = V_2 -> V_102 + V_74 -> V_81 ;
V_2 -> V_98 = F_39 ( V_2 -> V_94 ,
V_101 , V_2 -> V_88 , V_104 ,
V_105 ) ;
if ( ! V_2 -> V_98 ) {
F_18 ( V_2 -> V_4 . V_50 , L_6 ) ;
return - V_106 ;
}
V_2 -> V_98 -> V_107 = F_29 ;
V_2 -> V_98 -> V_108 = V_2 ;
V_2 -> V_86 = V_109 ;
V_2 -> V_96 = V_2 -> V_88 ;
V_2 -> V_110 = F_40 ( V_2 -> V_98 ) ;
F_41 ( V_2 -> V_94 ) ;
return 0 ;
}
static void F_35 ( struct V_1 * V_2 )
{
unsigned long V_81 ;
unsigned long V_93 ;
struct V_73 * V_74 = & V_2 -> V_4 . V_75 -> V_74 ;
V_81 = ( unsigned long ) & V_74 -> V_80 [ V_74 -> V_81 ] ;
V_93 = F_42 ( V_74 -> V_111 , V_74 -> V_81 , V_82 ) ;
if ( ! V_93 )
return;
if ( V_93 < V_85 )
F_28 ( V_2 , V_93 ) ;
else if ( F_43 ( V_81 ) > 0 )
F_28 ( V_2 , F_43 ( V_81 ) ) ;
else
F_37 ( V_2 , V_93 ) ;
}
static void F_44 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_5 ( V_9 ) ;
struct V_73 * V_74 = & V_9 -> V_75 -> V_74 ;
if ( ! F_27 ( V_74 ) && ! V_2 -> V_86 )
F_35 ( V_2 ) ;
}
static unsigned int F_45 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_5 ( V_9 ) ;
unsigned int V_47 = 0 ;
unsigned long V_92 ;
F_32 ( & V_9 -> V_99 , V_92 ) ;
if ( ! V_2 -> V_86 ) {
unsigned long V_54 = F_1 ( V_2 , V_78 ) ;
if ( ( V_54 & V_112 ) == V_112 )
V_47 = V_113 ;
}
F_36 ( & V_9 -> V_99 , V_92 ) ;
return V_47 ;
}
static void F_46 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_5 ( V_9 ) ;
struct V_73 * V_74 = & V_2 -> V_4 . V_75 -> V_74 ;
struct V_91 V_75 ;
int V_93 ;
F_47 ( V_2 -> V_94 ) ;
F_30 ( V_2 -> V_94 , V_2 -> V_110 , & V_75 ) ;
V_93 = V_2 -> V_96 - V_75 . V_97 ;
F_31 ( V_2 -> V_98 ) ;
V_74 -> V_81 = ( V_74 -> V_81 + V_93 ) & ( V_82 - 1 ) ;
V_2 -> V_86 = 0 ;
return;
}
static void F_48 ( struct V_1 * V_2 )
{
struct V_73 * V_74 = & V_2 -> V_4 . V_75 -> V_74 ;
F_25 ( V_2 , V_2 -> V_88 ) ;
V_2 -> V_86 = 0 ;
if ( F_33 ( V_74 ) < V_100 )
F_34 ( & V_2 -> V_4 ) ;
F_35 ( V_2 ) ;
return;
}
static void F_49 ( struct V_1 * V_2 ,
struct V_114 * V_115 )
{
do {
char V_55 = V_56 ;
unsigned long V_54 = 0 ;
unsigned char V_116 ;
V_54 = F_1 ( V_2 , V_78 ) ;
if ( ! ( V_54 & V_70 ) )
break;
V_55 = F_21 ( V_2 , V_54 ) ;
V_116 = ( unsigned char ) F_1 ( V_2 , V_117 ) ;
V_2 -> V_4 . V_60 . V_118 ++ ;
if ( ! F_50 ( & V_2 -> V_4 , V_116 ) && V_115 )
F_51 ( V_115 , V_116 , V_55 ) ;
} while ( 1 );
return;
}
static void F_52 ( struct V_1 * V_2 ,
struct V_114 * V_115 , int V_93 )
{
int V_119 ;
V_2 -> V_4 . V_60 . V_118 += V_93 ;
if ( ! V_115 ) {
F_18 ( V_2 -> V_4 . V_50 , L_7 ) ;
return;
}
F_53 ( V_2 -> V_4 . V_50 , V_2 -> V_120 ,
V_121 , V_122 ) ;
V_119 = F_54 ( V_115 ,
( ( unsigned char * ) ( V_2 -> V_123 ) ) , V_93 ) ;
if ( V_119 != V_93 ) {
F_55 ( 1 ) ;
F_18 ( V_2 -> V_4 . V_50 , L_8 ) ;
}
F_38 ( V_2 -> V_4 . V_50 , V_2 -> V_120 ,
V_121 , V_103 ) ;
}
static void F_56 ( void * args )
{
struct V_1 * V_2 = args ;
struct V_8 * V_9 = & V_2 -> V_4 ;
int V_93 = V_2 -> V_124 ;
struct V_125 * V_115 = F_57 ( & V_2 -> V_4 . V_75 -> V_126 ) ;
struct V_114 * V_126 = & V_9 -> V_75 -> V_126 ;
unsigned long V_92 ;
F_31 ( V_2 -> V_127 ) ;
F_32 ( & V_9 -> V_99 , V_92 ) ;
if ( V_2 -> V_23 )
F_8 ( V_2 , false ) ;
if ( V_93 )
F_52 ( V_2 , V_126 , V_93 ) ;
F_49 ( V_2 , V_126 ) ;
if ( V_115 ) {
F_36 ( & V_9 -> V_99 , V_92 ) ;
F_58 ( V_126 ) ;
F_32 ( & V_9 -> V_99 , V_92 ) ;
F_59 ( V_115 ) ;
}
F_60 ( V_2 ) ;
if ( V_2 -> V_23 )
F_8 ( V_2 , true ) ;
F_36 ( & V_9 -> V_99 , V_92 ) ;
}
static void F_61 ( struct V_1 * V_2 ,
unsigned long * V_92 )
{
struct V_91 V_75 ;
struct V_125 * V_115 = F_57 ( & V_2 -> V_4 . V_75 -> V_126 ) ;
struct V_114 * V_126 = & V_2 -> V_4 . V_75 -> V_126 ;
struct V_8 * V_9 = & V_2 -> V_4 ;
int V_93 ;
if ( V_2 -> V_23 )
F_8 ( V_2 , false ) ;
F_47 ( V_2 -> V_128 ) ;
F_30 ( V_2 -> V_128 , V_2 -> V_95 , & V_75 ) ;
V_93 = V_2 -> V_124 - V_75 . V_97 ;
if ( V_93 )
F_52 ( V_2 , V_126 , V_93 ) ;
F_49 ( V_2 , V_126 ) ;
if ( V_115 ) {
F_36 ( & V_9 -> V_99 , * V_92 ) ;
F_58 ( V_126 ) ;
F_32 ( & V_9 -> V_99 , * V_92 ) ;
F_59 ( V_115 ) ;
}
F_60 ( V_2 ) ;
if ( V_2 -> V_23 )
F_8 ( V_2 , true ) ;
}
static int F_60 ( struct V_1 * V_2 )
{
unsigned int V_93 = V_121 ;
V_2 -> V_127 = F_39 ( V_2 -> V_128 ,
V_2 -> V_120 , V_93 , V_129 ,
V_105 ) ;
if ( ! V_2 -> V_127 ) {
F_18 ( V_2 -> V_4 . V_50 , L_9 ) ;
return - V_106 ;
}
V_2 -> V_127 -> V_107 = F_56 ;
V_2 -> V_127 -> V_108 = V_2 ;
F_38 ( V_2 -> V_4 . V_50 , V_2 -> V_120 ,
V_93 , V_103 ) ;
V_2 -> V_124 = V_93 ;
V_2 -> V_95 = F_40 ( V_2 -> V_127 ) ;
F_41 ( V_2 -> V_128 ) ;
return 0 ;
}
static void F_62 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_5 ( V_9 ) ;
unsigned long V_130 ;
V_130 = F_1 ( V_2 , V_131 ) ;
if ( ! ( V_130 & V_132 ) )
return;
if ( V_130 & V_133 )
V_2 -> V_4 . V_60 . V_134 ++ ;
if ( V_130 & V_135 )
V_2 -> V_4 . V_60 . V_136 ++ ;
if ( V_130 & V_137 )
F_63 ( & V_2 -> V_4 , V_130 & V_138 ) ;
if ( V_130 & V_139 )
F_64 ( & V_2 -> V_4 , V_130 & V_140 ) ;
return;
}
static T_3 F_65 ( int V_141 , void * V_142 )
{
struct V_1 * V_2 = V_142 ;
struct V_8 * V_9 = & V_2 -> V_4 ;
unsigned long V_143 ;
unsigned long V_144 ;
bool V_145 = false ;
unsigned long V_92 ;
F_32 ( & V_9 -> V_99 , V_92 ) ;
while ( 1 ) {
V_143 = F_1 ( V_2 , V_146 ) ;
if ( V_143 & V_147 ) {
if ( V_145 ) {
F_61 ( V_2 , & V_92 ) ;
if ( V_2 -> V_148 ) {
V_144 = V_2 -> V_89 ;
V_144 |= ( V_149 | V_150 |
V_151 ) ;
V_2 -> V_89 = V_144 ;
F_3 ( V_2 , V_144 , V_53 ) ;
}
}
F_36 ( & V_9 -> V_99 , V_92 ) ;
return V_152 ;
}
switch ( ( V_143 >> 1 ) & 0x7 ) {
case 0 :
F_62 ( V_9 ) ;
break;
case 1 :
V_2 -> V_89 &= ~ V_90 ;
F_3 ( V_2 , V_2 -> V_89 , V_53 ) ;
F_48 ( V_2 ) ;
break;
case 4 :
case 6 :
case 2 :
if ( ! V_145 ) {
V_145 = true ;
V_144 = V_2 -> V_89 ;
V_144 |= V_153 ;
F_3 ( V_2 , V_144 , V_53 ) ;
V_144 &= ~ ( V_153 | V_149 |
V_150 | V_151 ) ;
V_2 -> V_89 = V_144 ;
F_3 ( V_2 , V_144 , V_53 ) ;
}
break;
case 3 :
F_21 ( V_2 ,
F_1 ( V_2 , V_78 ) ) ;
break;
case 5 :
case 7 :
break;
}
}
}
static void F_66 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_5 ( V_9 ) ;
struct V_125 * V_115 ;
struct V_114 * V_126 = & V_9 -> V_75 -> V_126 ;
struct V_91 V_75 ;
unsigned long V_144 ;
int V_93 ;
if ( V_2 -> V_23 )
F_8 ( V_2 , false ) ;
if ( ! V_2 -> V_148 )
return;
V_115 = F_57 ( & V_2 -> V_4 . V_75 -> V_126 ) ;
F_12 ( V_2 , 1 ) ;
V_144 = V_2 -> V_89 ;
V_144 &= ~ ( V_153 | V_149 | V_150 |
V_151 ) ;
V_2 -> V_89 = V_144 ;
F_3 ( V_2 , V_144 , V_53 ) ;
V_2 -> V_148 = 0 ;
if ( V_2 -> V_128 ) {
F_47 ( V_2 -> V_128 ) ;
F_30 ( V_2 -> V_128 , V_2 -> V_95 , & V_75 ) ;
F_31 ( V_2 -> V_127 ) ;
V_93 = V_2 -> V_124 - V_75 . V_97 ;
F_52 ( V_2 , V_126 , V_93 ) ;
F_49 ( V_2 , V_126 ) ;
} else {
F_49 ( V_2 , V_126 ) ;
}
if ( V_115 ) {
F_58 ( V_126 ) ;
F_59 ( V_115 ) ;
}
return;
}
static void F_67 ( struct V_1 * V_2 )
{
unsigned long V_92 ;
unsigned long V_154 = F_14 ( 10000000 , V_2 -> V_32 ) ;
unsigned long V_155 = V_2 -> V_4 . V_156 * V_154 ;
unsigned long V_157 ;
unsigned long V_54 ;
unsigned long V_130 ;
unsigned long V_16 ;
F_3 ( V_2 , 0 , V_53 ) ;
V_54 = F_1 ( V_2 , V_78 ) ;
if ( ( V_54 & V_158 ) != V_158 ) {
V_130 = F_1 ( V_2 , V_131 ) ;
V_16 = F_1 ( V_2 , V_19 ) ;
if ( ( V_16 & V_159 ) && ( V_130 & V_140 ) )
F_18 ( V_2 -> V_4 . V_50 ,
L_10 ) ;
while ( ( V_54 & V_158 ) != V_158 ) {
V_157 = F_68 ( V_155 , 100lu ) ;
F_13 ( V_157 ) ;
V_155 -= V_157 ;
if ( ! V_155 ) {
V_130 = F_1 ( V_2 , V_131 ) ;
V_16 = F_1 ( V_2 , V_19 ) ;
if ( ( V_16 & V_159 ) &&
( V_130 & V_140 ) )
F_18 ( V_2 -> V_4 . V_50 ,
L_11 ) ;
break;
}
V_54 = F_1 ( V_2 , V_78 ) ;
}
}
F_32 ( & V_2 -> V_4 . V_99 , V_92 ) ;
F_15 ( V_2 , V_40 | V_39 ) ;
V_2 -> V_32 = 0 ;
F_36 ( & V_2 -> V_4 . V_99 , V_92 ) ;
F_69 ( V_2 -> V_49 ) ;
}
static int F_70 ( struct V_1 * V_2 )
{
int V_47 ;
V_2 -> V_36 = 0 ;
V_2 -> V_17 = 0 ;
V_2 -> V_28 = 0 ;
V_2 -> V_89 = 0 ;
V_2 -> V_32 = 0 ;
F_71 ( V_2 -> V_49 ) ;
F_72 ( V_2 -> V_49 ) ;
F_13 ( 10 ) ;
F_73 ( V_2 -> V_49 ) ;
V_2 -> V_148 = 0 ;
V_2 -> V_86 = 0 ;
V_2 -> V_36 = V_42 ;
V_2 -> V_36 |= V_160 ;
V_2 -> V_36 |= V_161 ;
F_3 ( V_2 , V_2 -> V_36 , V_41 ) ;
V_2 -> V_28 = V_162 ;
F_16 ( V_2 , V_163 ) ;
V_2 -> V_36 |= V_164 ;
F_3 ( V_2 , V_2 -> V_36 , V_41 ) ;
V_47 = F_60 ( V_2 ) ;
if ( V_47 < 0 ) {
F_18 ( V_2 -> V_4 . V_50 , L_12 ) ;
return V_47 ;
}
V_2 -> V_148 = 1 ;
V_2 -> V_89 = V_149 | V_150 | V_151 ;
F_3 ( V_2 , V_2 -> V_89 , V_53 ) ;
return 0 ;
}
static int F_74 ( struct V_1 * V_2 ,
bool V_165 )
{
struct V_166 * V_166 ;
unsigned char * V_167 ;
T_2 V_168 ;
int V_47 ;
struct V_169 V_170 ;
T_4 V_171 ;
F_75 ( V_171 ) ;
F_76 ( V_172 , V_171 ) ;
V_166 = F_77 ( V_171 , NULL , NULL ) ;
if ( ! V_166 ) {
F_18 ( V_2 -> V_4 . V_50 ,
L_13 ) ;
return - V_173 ;
}
if ( V_165 ) {
V_167 = F_78 ( V_2 -> V_4 . V_50 ,
V_121 ,
& V_168 , V_174 ) ;
if ( ! V_167 ) {
F_18 ( V_2 -> V_4 . V_50 ,
L_14 ) ;
F_79 ( V_166 ) ;
return - V_175 ;
}
} else {
V_168 = F_80 ( V_2 -> V_4 . V_50 ,
V_2 -> V_4 . V_75 -> V_74 . V_80 , V_82 ,
V_103 ) ;
V_167 = V_2 -> V_4 . V_75 -> V_74 . V_80 ;
}
V_170 . V_176 = V_2 -> V_177 ;
if ( V_165 ) {
V_170 . V_178 = V_2 -> V_4 . V_179 ;
V_170 . V_180 = V_181 ;
V_170 . V_182 = 4 ;
} else {
V_170 . V_183 = V_2 -> V_4 . V_179 ;
V_170 . V_184 = V_181 ;
V_170 . V_185 = 16 ;
}
V_47 = F_81 ( V_166 , & V_170 ) ;
if ( V_47 < 0 ) {
F_18 ( V_2 -> V_4 . V_50 ,
L_15 , V_47 ) ;
goto V_186;
}
if ( V_165 ) {
V_2 -> V_128 = V_166 ;
V_2 -> V_123 = V_167 ;
V_2 -> V_120 = V_168 ;
} else {
V_2 -> V_94 = V_166 ;
V_2 -> V_187 = V_167 ;
V_2 -> V_102 = V_168 ;
}
return 0 ;
V_186:
F_79 ( V_166 ) ;
return V_47 ;
}
static void F_82 ( struct V_1 * V_2 ,
bool V_165 )
{
struct V_166 * V_166 ;
if ( V_165 ) {
F_83 ( V_2 -> V_4 . V_50 , V_121 ,
V_2 -> V_123 , V_2 -> V_120 ) ;
V_166 = V_2 -> V_128 ;
V_2 -> V_128 = NULL ;
V_2 -> V_120 = 0 ;
V_2 -> V_123 = NULL ;
} else {
F_84 ( V_2 -> V_4 . V_50 , V_2 -> V_102 ,
V_82 , V_103 ) ;
V_166 = V_2 -> V_94 ;
V_2 -> V_94 = NULL ;
V_2 -> V_102 = 0 ;
V_2 -> V_187 = NULL ;
}
F_79 ( V_166 ) ;
}
static int F_85 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_5 ( V_9 ) ;
int V_47 ;
V_47 = F_74 ( V_2 , false ) ;
if ( V_47 < 0 ) {
F_18 ( V_9 -> V_50 , L_16 , V_47 ) ;
return V_47 ;
}
V_47 = F_74 ( V_2 , true ) ;
if ( V_47 < 0 ) {
F_18 ( V_9 -> V_50 , L_17 , V_47 ) ;
goto V_188;
}
V_47 = F_70 ( V_2 ) ;
if ( V_47 < 0 ) {
F_18 ( V_9 -> V_50 , L_18 , V_47 ) ;
goto V_189;
}
V_47 = F_86 ( V_9 -> V_141 , F_65 , V_190 ,
F_87 ( V_9 -> V_50 ) , V_2 ) ;
if ( V_47 < 0 ) {
F_18 ( V_9 -> V_50 , L_19 , V_9 -> V_141 ) ;
goto V_189;
}
return 0 ;
V_189:
F_82 ( V_2 , true ) ;
V_188:
F_82 ( V_2 , false ) ;
return V_47 ;
}
static void F_88 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_5 ( V_9 ) ;
F_67 ( V_2 ) ;
V_2 -> V_148 = 0 ;
V_2 -> V_86 = 0 ;
F_82 ( V_2 , true ) ;
F_82 ( V_2 , false ) ;
F_89 ( V_9 -> V_141 , V_2 ) ;
}
static void F_90 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_5 ( V_9 ) ;
if ( V_2 -> V_10 ) {
V_2 -> V_89 |= V_191 ;
F_3 ( V_2 , V_2 -> V_89 , V_53 ) ;
}
}
static void F_91 ( struct V_8 * V_9 ,
struct V_192 * V_193 , struct V_192 * V_194 )
{
struct V_1 * V_2 = F_5 ( V_9 ) ;
unsigned int V_44 ;
unsigned long V_92 ;
unsigned int V_27 ;
int V_33 = 1 ;
struct V_195 * V_196 = F_92 ( V_2 -> V_49 ) ;
unsigned long V_197 = F_19 ( V_196 ) ;
int V_198 = ( V_2 -> V_37 -> V_48 ) ? 0x7FFF : 0xFFFF ;
V_198 *= 16 ;
F_32 ( & V_9 -> V_99 , V_92 ) ;
if ( V_2 -> V_23 )
F_8 ( V_2 , false ) ;
F_3 ( V_2 , V_2 -> V_89 | V_153 , V_53 ) ;
F_1 ( V_2 , V_53 ) ;
F_3 ( V_2 , 0 , V_53 ) ;
F_1 ( V_2 , V_53 ) ;
V_27 = V_2 -> V_28 ;
V_27 &= ~ V_199 ;
V_193 -> V_200 &= ~ V_201 ;
if ( ( V_193 -> V_200 & V_202 ) == V_202 ) {
V_33 ++ ;
if ( V_193 -> V_200 & V_203 ) {
V_27 |= V_199 ;
V_27 &= ~ V_204 ;
V_27 &= ~ V_205 ;
} else {
V_27 |= V_199 ;
V_27 |= V_204 ;
V_27 &= ~ V_205 ;
}
}
V_27 &= ~ V_206 ;
switch ( V_193 -> V_200 & V_207 ) {
case V_208 :
V_27 |= V_209 ;
V_33 += 5 ;
break;
case V_210 :
V_27 |= V_211 ;
V_33 += 6 ;
break;
case V_212 :
V_27 |= V_213 ;
V_33 += 7 ;
break;
default:
V_27 |= V_206 ;
V_33 += 8 ;
break;
}
if ( V_193 -> V_200 & V_214 ) {
V_27 |= V_215 ;
V_33 += 2 ;
} else {
V_27 &= ~ V_215 ;
V_33 ++ ;
}
F_3 ( V_2 , V_27 , V_30 ) ;
V_2 -> V_28 = V_27 ;
V_2 -> V_33 = V_33 ;
V_44 = F_93 ( V_9 , V_193 , V_194 ,
V_197 / V_198 ,
V_197 / 16 ) ;
F_36 ( & V_9 -> V_99 , V_92 ) ;
F_16 ( V_2 , V_44 ) ;
if ( F_94 ( V_193 ) )
F_95 ( V_193 , V_44 , V_44 ) ;
F_32 ( & V_9 -> V_99 , V_92 ) ;
if ( V_193 -> V_200 & V_216 ) {
V_2 -> V_17 |= V_159 ;
V_2 -> V_17 &= ~ V_18 ;
F_3 ( V_2 , V_2 -> V_17 , V_19 ) ;
if ( V_2 -> V_23 )
F_8 ( V_2 , true ) ;
} else {
V_2 -> V_17 &= ~ V_159 ;
V_2 -> V_17 &= ~ V_18 ;
F_3 ( V_2 , V_2 -> V_17 , V_19 ) ;
}
F_96 ( V_9 , V_193 -> V_200 , V_44 ) ;
F_1 ( V_2 , V_53 ) ;
F_3 ( V_2 , V_2 -> V_89 , V_53 ) ;
F_1 ( V_2 , V_53 ) ;
F_36 ( & V_9 -> V_99 , V_92 ) ;
return;
}
static void F_97 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_5 ( V_9 ) ;
V_2 -> V_88 = 0 ;
if ( V_2 -> V_94 )
F_47 ( V_2 -> V_94 ) ;
return;
}
static const char * F_98 ( struct V_8 * V_9 )
{
return V_217 ;
}
static int F_99 ( struct V_218 * V_219 ,
struct V_1 * V_2 )
{
struct V_220 * V_221 = V_219 -> V_50 . V_222 ;
T_5 V_223 [ 2 ] ;
int V_126 ;
if ( F_100 ( V_221 , L_20 ,
V_223 , 2 ) >= 0 ) {
V_2 -> V_177 = V_223 [ 1 ] ;
} else {
F_18 ( & V_219 -> V_50 , L_21 ) ;
return - V_224 ;
}
V_126 = F_101 ( V_221 , L_22 ) ;
if ( V_126 < 0 ) {
F_18 ( & V_219 -> V_50 , L_23 , V_126 ) ;
return V_126 ;
}
V_2 -> V_4 . line = V_126 ;
V_2 -> V_10 = F_102 ( V_221 ,
L_24 ) ;
return 0 ;
}
static int F_103 ( struct V_218 * V_219 )
{
struct V_1 * V_2 ;
struct V_8 * V_9 ;
struct V_225 * V_225 ;
int V_47 ;
const struct V_226 * V_37 ;
const struct V_227 * V_228 ;
V_228 = F_104 ( V_229 , & V_219 -> V_50 ) ;
if ( ! V_228 ) {
F_18 ( & V_219 -> V_50 , L_25 ) ;
return - V_230 ;
}
V_37 = V_228 -> V_142 ;
V_2 = F_105 ( & V_219 -> V_50 , sizeof( * V_2 ) , V_174 ) ;
if ( ! V_2 ) {
F_18 ( & V_219 -> V_50 , L_26 ) ;
return - V_175 ;
}
V_47 = F_99 ( V_219 , V_2 ) ;
if ( V_47 < 0 )
return V_47 ;
V_9 = & V_2 -> V_4 ;
V_9 -> V_50 = & V_219 -> V_50 ;
V_9 -> V_231 = & V_232 ;
V_9 -> type = V_233 ;
V_9 -> V_156 = 32 ;
V_2 -> V_37 = V_37 ;
F_106 ( V_219 , V_2 ) ;
V_225 = F_107 ( V_219 , V_234 , 0 ) ;
if ( ! V_225 ) {
F_18 ( & V_219 -> V_50 , L_27 ) ;
return - V_230 ;
}
V_9 -> V_179 = V_225 -> V_235 ;
V_9 -> V_5 = F_108 ( & V_219 -> V_50 , V_225 ) ;
if ( F_109 ( V_9 -> V_5 ) )
return F_110 ( V_9 -> V_5 ) ;
V_2 -> V_49 = F_111 ( & V_219 -> V_50 , NULL ) ;
if ( F_109 ( V_2 -> V_49 ) ) {
F_18 ( & V_219 -> V_50 , L_28 ) ;
return F_110 ( V_2 -> V_49 ) ;
}
V_9 -> V_236 = V_237 ;
V_9 -> V_141 = F_112 ( V_219 , 0 ) ;
V_9 -> V_6 = 2 ;
V_47 = F_113 ( & V_238 , V_9 ) ;
if ( V_47 < 0 ) {
F_18 ( & V_219 -> V_50 , L_29 , V_47 ) ;
return V_47 ;
}
return V_47 ;
}
static int F_114 ( struct V_218 * V_219 )
{
struct V_1 * V_2 = F_115 ( V_219 ) ;
struct V_8 * V_9 = & V_2 -> V_4 ;
F_116 ( & V_238 , V_9 ) ;
return 0 ;
}
static int F_117 ( struct V_239 * V_50 )
{
struct V_1 * V_2 = F_118 ( V_50 ) ;
struct V_8 * V_9 = & V_2 -> V_4 ;
return F_119 ( & V_238 , V_9 ) ;
}
static int F_120 ( struct V_239 * V_50 )
{
struct V_1 * V_2 = F_118 ( V_50 ) ;
struct V_8 * V_9 = & V_2 -> V_4 ;
return F_121 ( & V_238 , V_9 ) ;
}
static int T_6 F_122 ( void )
{
int V_47 ;
V_47 = F_123 ( & V_238 ) ;
if ( V_47 < 0 ) {
F_124 ( L_30 ,
V_238 . V_240 ) ;
return V_47 ;
}
V_47 = F_125 ( & V_241 ) ;
if ( V_47 < 0 ) {
F_124 ( L_31 , V_47 ) ;
F_126 ( & V_238 ) ;
return V_47 ;
}
return 0 ;
}
static void T_7 F_127 ( void )
{
F_128 ( L_32 ) ;
F_129 ( & V_241 ) ;
F_126 ( & V_238 ) ;
}
