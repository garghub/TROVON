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
}
static void F_10 ( struct V_8 * V_9 , unsigned int V_21 )
{
struct V_1 * V_2 = F_5 ( V_9 ) ;
int V_22 ;
V_2 -> V_23 = ! ! ( V_21 & V_24 ) ;
F_8 ( V_2 , V_2 -> V_23 ) ;
V_22 = ! ! ( V_21 & V_25 ) ;
F_9 ( V_2 , V_22 ) ;
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
F_13 ( F_14 ( V_31 * 1000000 , V_2 -> V_32 * 16 ) ) ;
}
static void F_15 ( struct V_1 * V_2 ,
unsigned int V_33 )
{
if ( V_2 -> V_32 )
F_13 ( F_14 ( V_33 * V_2 -> V_34 * 1000000 ,
V_2 -> V_32 ) ) ;
}
static void F_16 ( struct V_1 * V_2 , T_1 V_35 )
{
unsigned long V_36 = V_2 -> V_37 ;
if ( V_2 -> V_38 -> V_39 ) {
V_36 |= V_35 & ( V_40 | V_41 ) ;
F_3 ( V_2 , V_36 , V_42 ) ;
} else {
V_36 &= ~ V_43 ;
F_3 ( V_2 , V_36 , V_42 ) ;
F_13 ( 60 ) ;
V_36 |= V_35 & ( V_40 | V_41 ) ;
F_3 ( V_2 , V_36 , V_42 ) ;
V_36 |= V_43 ;
F_3 ( V_2 , V_36 , V_42 ) ;
}
F_1 ( V_2 , V_44 ) ;
F_12 ( V_2 , 32 ) ;
}
static int F_17 ( struct V_1 * V_2 , unsigned int V_45 )
{
unsigned long V_46 ;
unsigned int V_47 ;
unsigned long V_27 ;
int V_48 ;
if ( V_2 -> V_32 == V_45 )
return 0 ;
if ( V_2 -> V_38 -> V_49 ) {
V_46 = V_45 * 16 ;
V_48 = F_18 ( V_2 -> V_50 , V_46 ) ;
if ( V_48 < 0 ) {
F_19 ( V_2 -> V_4 . V_51 ,
L_1 , V_46 ) ;
return V_48 ;
}
V_47 = 1 ;
} else {
V_46 = F_20 ( V_2 -> V_50 ) ;
V_47 = F_21 ( V_46 , V_45 * 16 ) ;
}
V_27 = V_2 -> V_28 ;
V_27 |= V_52 ;
F_3 ( V_2 , V_27 , V_30 ) ;
F_3 ( V_2 , V_47 & 0xFF , V_53 ) ;
F_3 ( V_2 , ( ( V_47 >> 8 ) & 0xFF ) , V_54 ) ;
V_27 &= ~ V_52 ;
F_3 ( V_2 , V_27 , V_30 ) ;
F_1 ( V_2 , V_44 ) ;
V_2 -> V_32 = V_45 ;
F_15 ( V_2 , 2 ) ;
return 0 ;
}
static char F_22 ( struct V_1 * V_2 ,
unsigned long V_55 )
{
char V_56 = V_57 ;
if ( F_23 ( V_55 & V_58 ) ) {
if ( V_55 & V_59 ) {
V_56 = V_60 ;
V_2 -> V_4 . V_61 . V_62 ++ ;
F_19 ( V_2 -> V_4 . V_51 , L_2 ) ;
} else if ( V_55 & V_63 ) {
V_56 = V_64 ;
V_2 -> V_4 . V_61 . V_65 ++ ;
F_19 ( V_2 -> V_4 . V_51 , L_3 ) ;
} else if ( V_55 & V_66 ) {
V_56 = V_67 ;
V_2 -> V_4 . V_61 . V_68 ++ ;
F_19 ( V_2 -> V_4 . V_51 , L_4 ) ;
} else if ( V_55 & V_69 ) {
F_19 ( V_2 -> V_4 . V_51 , L_5 ) ;
V_2 -> V_4 . V_61 . V_70 ++ ;
if ( ! ( V_55 & V_71 ) && ( V_55 & V_72 ) )
F_16 ( V_2 , V_40 ) ;
}
}
return V_56 ;
}
static int F_24 ( struct V_8 * V_9 )
{
return 0 ;
}
static void F_25 ( struct V_8 * V_9 )
{
}
static void F_26 ( struct V_1 * V_2 , int V_73 )
{
struct V_74 * V_75 = & V_2 -> V_4 . V_76 -> V_75 ;
int V_77 ;
for ( V_77 = 0 ; V_77 < V_73 ; V_77 ++ ) {
F_27 ( F_28 ( V_75 ) ) ;
if ( V_2 -> V_38 -> V_78 ) {
unsigned long V_55 = F_1 ( V_2 , V_79 ) ;
if ( ( V_55 & V_80 ) )
break;
}
F_3 ( V_2 , V_75 -> V_81 [ V_75 -> V_82 ] , V_53 ) ;
V_75 -> V_82 = ( V_75 -> V_82 + 1 ) & ( V_83 - 1 ) ;
V_2 -> V_4 . V_61 . V_84 ++ ;
}
}
static void F_29 ( struct V_1 * V_2 ,
unsigned int V_85 )
{
if ( V_85 > V_86 )
V_85 = V_86 ;
V_2 -> V_87 = V_88 ;
V_2 -> V_89 = V_85 ;
V_2 -> V_90 |= V_91 ;
F_3 ( V_2 , V_2 -> V_90 , V_54 ) ;
}
static void F_30 ( void * args )
{
struct V_1 * V_2 = args ;
struct V_74 * V_75 = & V_2 -> V_4 . V_76 -> V_75 ;
struct V_92 V_76 ;
unsigned long V_93 ;
unsigned int V_94 ;
F_31 ( V_2 -> V_95 , V_2 -> V_96 , & V_76 ) ;
V_94 = V_2 -> V_97 - V_76 . V_98 ;
F_32 ( V_2 -> V_99 ) ;
F_33 ( & V_2 -> V_4 . V_100 , V_93 ) ;
V_75 -> V_82 = ( V_75 -> V_82 + V_94 ) & ( V_83 - 1 ) ;
V_2 -> V_87 = 0 ;
if ( F_34 ( V_75 ) < V_101 )
F_35 ( & V_2 -> V_4 ) ;
F_36 ( V_2 ) ;
F_37 ( & V_2 -> V_4 . V_100 , V_93 ) ;
}
static int F_38 ( struct V_1 * V_2 ,
unsigned long V_94 )
{
struct V_74 * V_75 = & V_2 -> V_4 . V_76 -> V_75 ;
T_2 V_102 ;
F_39 ( V_2 -> V_4 . V_51 , V_2 -> V_103 ,
V_83 , V_104 ) ;
V_2 -> V_89 = V_94 & ~ ( 0xF ) ;
V_102 = V_2 -> V_103 + V_75 -> V_82 ;
V_2 -> V_99 = F_40 ( V_2 -> V_95 ,
V_102 , V_2 -> V_89 , V_105 ,
V_106 ) ;
if ( ! V_2 -> V_99 ) {
F_19 ( V_2 -> V_4 . V_51 , L_6 ) ;
return - V_107 ;
}
V_2 -> V_99 -> V_108 = F_30 ;
V_2 -> V_99 -> V_109 = V_2 ;
V_2 -> V_87 = V_110 ;
V_2 -> V_97 = V_2 -> V_89 ;
V_2 -> V_96 = F_41 ( V_2 -> V_99 ) ;
F_42 ( V_2 -> V_95 ) ;
return 0 ;
}
static void F_36 ( struct V_1 * V_2 )
{
unsigned long V_82 ;
unsigned long V_94 ;
struct V_74 * V_75 = & V_2 -> V_4 . V_76 -> V_75 ;
V_82 = ( unsigned long ) & V_75 -> V_81 [ V_75 -> V_82 ] ;
V_94 = F_43 ( V_75 -> V_111 , V_75 -> V_82 , V_83 ) ;
if ( ! V_94 )
return;
if ( V_94 < V_86 )
F_29 ( V_2 , V_94 ) ;
else if ( F_44 ( V_82 ) > 0 )
F_29 ( V_2 , F_44 ( V_82 ) ) ;
else
F_38 ( V_2 , V_94 ) ;
}
static void F_45 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_5 ( V_9 ) ;
struct V_74 * V_75 = & V_9 -> V_76 -> V_75 ;
if ( ! F_28 ( V_75 ) && ! V_2 -> V_87 )
F_36 ( V_2 ) ;
}
static unsigned int F_46 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_5 ( V_9 ) ;
unsigned int V_48 = 0 ;
unsigned long V_93 ;
F_33 ( & V_9 -> V_100 , V_93 ) ;
if ( ! V_2 -> V_87 ) {
unsigned long V_55 = F_1 ( V_2 , V_79 ) ;
if ( ( V_55 & V_112 ) == V_112 )
V_48 = V_113 ;
}
F_37 ( & V_9 -> V_100 , V_93 ) ;
return V_48 ;
}
static void F_47 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_5 ( V_9 ) ;
struct V_74 * V_75 = & V_2 -> V_4 . V_76 -> V_75 ;
struct V_92 V_76 ;
unsigned int V_94 ;
if ( V_2 -> V_87 != V_110 )
return;
F_48 ( V_2 -> V_95 ) ;
F_31 ( V_2 -> V_95 , V_2 -> V_96 , & V_76 ) ;
V_94 = V_2 -> V_97 - V_76 . V_98 ;
F_32 ( V_2 -> V_99 ) ;
V_75 -> V_82 = ( V_75 -> V_82 + V_94 ) & ( V_83 - 1 ) ;
V_2 -> V_87 = 0 ;
}
static void F_49 ( struct V_1 * V_2 )
{
struct V_74 * V_75 = & V_2 -> V_4 . V_76 -> V_75 ;
F_26 ( V_2 , V_2 -> V_89 ) ;
V_2 -> V_87 = 0 ;
if ( F_34 ( V_75 ) < V_101 )
F_35 ( & V_2 -> V_4 ) ;
F_36 ( V_2 ) ;
}
static void F_50 ( struct V_1 * V_2 ,
struct V_114 * V_115 )
{
do {
char V_56 = V_57 ;
unsigned long V_55 = 0 ;
unsigned char V_116 ;
V_55 = F_1 ( V_2 , V_79 ) ;
if ( ! ( V_55 & V_71 ) )
break;
V_56 = F_22 ( V_2 , V_55 ) ;
V_116 = ( unsigned char ) F_1 ( V_2 , V_117 ) ;
V_2 -> V_4 . V_61 . V_118 ++ ;
if ( ! F_51 ( & V_2 -> V_4 , V_116 ) && V_115 )
F_52 ( V_115 , V_116 , V_56 ) ;
} while ( 1 );
}
static void F_53 ( struct V_1 * V_2 ,
struct V_114 * V_115 ,
unsigned int V_94 )
{
int V_119 ;
if ( ! V_94 )
return;
V_2 -> V_4 . V_61 . V_118 += V_94 ;
if ( ! V_115 ) {
F_19 ( V_2 -> V_4 . V_51 , L_7 ) ;
return;
}
F_54 ( V_2 -> V_4 . V_51 , V_2 -> V_120 ,
V_121 , V_122 ) ;
V_119 = F_55 ( V_115 ,
( ( unsigned char * ) ( V_2 -> V_123 ) ) , V_94 ) ;
if ( V_119 != V_94 ) {
F_56 ( 1 ) ;
F_19 ( V_2 -> V_4 . V_51 , L_8 ) ;
}
F_39 ( V_2 -> V_4 . V_51 , V_2 -> V_120 ,
V_121 , V_104 ) ;
}
static void F_57 ( struct V_1 * V_2 ,
unsigned int V_98 )
{
struct V_114 * V_124 = & V_2 -> V_4 . V_76 -> V_124 ;
struct V_125 * V_115 = F_58 ( V_124 ) ;
unsigned int V_94 ;
F_32 ( V_2 -> V_126 ) ;
V_94 = V_2 -> V_127 - V_98 ;
F_53 ( V_2 , V_124 , V_94 ) ;
F_50 ( V_2 , V_124 ) ;
if ( V_115 ) {
F_59 ( V_124 ) ;
F_60 ( V_115 ) ;
}
}
static void F_61 ( void * args )
{
struct V_1 * V_2 = args ;
struct V_8 * V_9 = & V_2 -> V_4 ;
unsigned long V_93 ;
struct V_92 V_76 ;
enum V_128 V_129 ;
F_33 ( & V_9 -> V_100 , V_93 ) ;
V_129 = F_31 ( V_2 -> V_130 , V_2 -> V_131 , & V_76 ) ;
if ( V_129 == V_132 ) {
F_62 ( V_2 -> V_4 . V_51 , L_9 ) ;
goto V_133;
}
if ( V_2 -> V_23 )
F_8 ( V_2 , false ) ;
F_57 ( V_2 , 0 ) ;
F_63 ( V_2 ) ;
if ( V_2 -> V_23 )
F_8 ( V_2 , true ) ;
V_133:
F_37 ( & V_9 -> V_100 , V_93 ) ;
}
static void F_64 ( struct V_1 * V_2 )
{
struct V_92 V_76 ;
if ( V_2 -> V_23 )
F_8 ( V_2 , false ) ;
F_48 ( V_2 -> V_130 ) ;
F_31 ( V_2 -> V_130 , V_2 -> V_131 , & V_76 ) ;
F_57 ( V_2 , V_76 . V_98 ) ;
F_63 ( V_2 ) ;
if ( V_2 -> V_23 )
F_8 ( V_2 , true ) ;
}
static int F_63 ( struct V_1 * V_2 )
{
unsigned int V_94 = V_121 ;
V_2 -> V_126 = F_40 ( V_2 -> V_130 ,
V_2 -> V_120 , V_94 , V_134 ,
V_106 ) ;
if ( ! V_2 -> V_126 ) {
F_19 ( V_2 -> V_4 . V_51 , L_10 ) ;
return - V_107 ;
}
V_2 -> V_126 -> V_108 = F_61 ;
V_2 -> V_126 -> V_109 = V_2 ;
F_39 ( V_2 -> V_4 . V_51 , V_2 -> V_120 ,
V_94 , V_104 ) ;
V_2 -> V_127 = V_94 ;
V_2 -> V_131 = F_41 ( V_2 -> V_126 ) ;
F_42 ( V_2 -> V_130 ) ;
return 0 ;
}
static void F_65 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_5 ( V_9 ) ;
unsigned long V_135 ;
V_135 = F_1 ( V_2 , V_136 ) ;
if ( ! ( V_135 & V_137 ) )
return;
if ( V_135 & V_138 )
V_2 -> V_4 . V_61 . V_139 ++ ;
if ( V_135 & V_140 )
V_2 -> V_4 . V_61 . V_141 ++ ;
if ( V_135 & V_142 )
F_66 ( & V_2 -> V_4 , V_135 & V_143 ) ;
if ( V_135 & V_144 )
F_67 ( & V_2 -> V_4 , V_135 & V_145 ) ;
}
static T_3 F_68 ( int V_146 , void * V_147 )
{
struct V_1 * V_2 = V_147 ;
struct V_8 * V_9 = & V_2 -> V_4 ;
unsigned long V_148 ;
unsigned long V_149 ;
bool V_150 = false ;
unsigned long V_93 ;
F_33 ( & V_9 -> V_100 , V_93 ) ;
while ( 1 ) {
V_148 = F_1 ( V_2 , V_151 ) ;
if ( V_148 & V_152 ) {
if ( V_150 ) {
F_64 ( V_2 ) ;
if ( V_2 -> V_153 ) {
V_149 = V_2 -> V_90 ;
V_149 |= ( V_154 | V_155 |
V_156 ) ;
V_2 -> V_90 = V_149 ;
F_3 ( V_2 , V_149 , V_54 ) ;
}
}
F_37 ( & V_9 -> V_100 , V_93 ) ;
return V_157 ;
}
switch ( ( V_148 >> 1 ) & 0x7 ) {
case 0 :
F_65 ( V_9 ) ;
break;
case 1 :
V_2 -> V_90 &= ~ V_91 ;
F_3 ( V_2 , V_2 -> V_90 , V_54 ) ;
F_49 ( V_2 ) ;
break;
case 4 :
case 6 :
case 2 :
if ( ! V_150 ) {
V_150 = true ;
V_149 = V_2 -> V_90 ;
V_149 |= V_158 ;
F_3 ( V_2 , V_149 , V_54 ) ;
V_149 &= ~ ( V_158 | V_154 |
V_155 | V_156 ) ;
V_2 -> V_90 = V_149 ;
F_3 ( V_2 , V_149 , V_54 ) ;
}
break;
case 3 :
F_22 ( V_2 ,
F_1 ( V_2 , V_79 ) ) ;
break;
case 5 :
case 7 :
break;
}
}
}
static void F_69 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_5 ( V_9 ) ;
struct V_92 V_76 ;
unsigned long V_149 ;
if ( V_2 -> V_23 )
F_8 ( V_2 , false ) ;
if ( ! V_2 -> V_153 )
return;
F_15 ( V_2 , 1 ) ;
V_149 = V_2 -> V_90 ;
V_149 &= ~ ( V_158 | V_154 | V_155 |
V_156 ) ;
V_2 -> V_90 = V_149 ;
F_3 ( V_2 , V_149 , V_54 ) ;
V_2 -> V_153 = 0 ;
F_48 ( V_2 -> V_130 ) ;
F_31 ( V_2 -> V_130 , V_2 -> V_131 , & V_76 ) ;
F_57 ( V_2 , V_76 . V_98 ) ;
}
static void F_70 ( struct V_1 * V_2 )
{
unsigned long V_93 ;
unsigned long V_159 = F_14 ( 10000000 , V_2 -> V_32 ) ;
unsigned long V_160 = V_2 -> V_4 . V_161 * V_159 ;
unsigned long V_162 ;
unsigned long V_55 ;
unsigned long V_135 ;
unsigned long V_16 ;
F_3 ( V_2 , 0 , V_54 ) ;
V_55 = F_1 ( V_2 , V_79 ) ;
if ( ( V_55 & V_163 ) != V_163 ) {
V_135 = F_1 ( V_2 , V_136 ) ;
V_16 = F_1 ( V_2 , V_19 ) ;
if ( ( V_16 & V_164 ) && ( V_135 & V_145 ) )
F_19 ( V_2 -> V_4 . V_51 ,
L_11 ) ;
while ( ( V_55 & V_163 ) != V_163 ) {
V_162 = F_71 ( V_160 , 100lu ) ;
F_13 ( V_162 ) ;
V_160 -= V_162 ;
if ( ! V_160 ) {
V_135 = F_1 ( V_2 , V_136 ) ;
V_16 = F_1 ( V_2 , V_19 ) ;
if ( ( V_16 & V_164 ) &&
( V_135 & V_145 ) )
F_19 ( V_2 -> V_4 . V_51 ,
L_12 ) ;
break;
}
V_55 = F_1 ( V_2 , V_79 ) ;
}
}
F_33 ( & V_2 -> V_4 . V_100 , V_93 ) ;
F_16 ( V_2 , V_41 | V_40 ) ;
V_2 -> V_32 = 0 ;
F_37 ( & V_2 -> V_4 . V_100 , V_93 ) ;
F_72 ( V_2 -> V_50 ) ;
}
static int F_73 ( struct V_1 * V_2 )
{
int V_48 ;
V_2 -> V_37 = 0 ;
V_2 -> V_17 = 0 ;
V_2 -> V_28 = 0 ;
V_2 -> V_90 = 0 ;
V_2 -> V_32 = 0 ;
F_74 ( V_2 -> V_50 ) ;
F_75 ( V_2 -> V_165 ) ;
F_13 ( 10 ) ;
F_76 ( V_2 -> V_165 ) ;
V_2 -> V_153 = 0 ;
V_2 -> V_87 = 0 ;
V_2 -> V_37 = V_43 ;
V_2 -> V_37 |= V_166 ;
V_2 -> V_37 |= V_167 ;
F_3 ( V_2 , V_2 -> V_37 , V_42 ) ;
F_1 ( V_2 , V_44 ) ;
F_12 ( V_2 , 3 ) ;
V_2 -> V_28 = V_168 ;
F_17 ( V_2 , V_169 ) ;
V_2 -> V_37 |= V_170 ;
F_3 ( V_2 , V_2 -> V_37 , V_42 ) ;
V_48 = F_63 ( V_2 ) ;
if ( V_48 < 0 ) {
F_19 ( V_2 -> V_4 . V_51 , L_13 ) ;
return V_48 ;
}
V_2 -> V_153 = 1 ;
V_2 -> V_90 = V_154 | V_155 | V_156 ;
F_3 ( V_2 , V_2 -> V_90 , V_54 ) ;
return 0 ;
}
static void F_77 ( struct V_1 * V_2 ,
bool V_171 )
{
if ( V_171 ) {
F_48 ( V_2 -> V_130 ) ;
F_78 ( V_2 -> V_130 ) ;
F_79 ( V_2 -> V_4 . V_51 , V_121 ,
V_2 -> V_123 , V_2 -> V_120 ) ;
V_2 -> V_130 = NULL ;
V_2 -> V_120 = 0 ;
V_2 -> V_123 = NULL ;
} else {
F_48 ( V_2 -> V_95 ) ;
F_78 ( V_2 -> V_95 ) ;
F_80 ( V_2 -> V_4 . V_51 , V_2 -> V_103 ,
V_83 , V_104 ) ;
V_2 -> V_95 = NULL ;
V_2 -> V_103 = 0 ;
V_2 -> V_172 = NULL ;
}
}
static int F_81 ( struct V_1 * V_2 ,
bool V_171 )
{
struct V_173 * V_173 ;
unsigned char * V_174 ;
T_2 V_175 ;
int V_48 ;
struct V_176 V_177 ;
V_173 = F_82 ( V_2 -> V_4 . V_51 ,
V_171 ? L_14 : L_15 ) ;
if ( F_83 ( V_173 ) ) {
V_48 = F_84 ( V_173 ) ;
F_19 ( V_2 -> V_4 . V_51 ,
L_16 , V_48 ) ;
return V_48 ;
}
if ( V_171 ) {
V_174 = F_85 ( V_2 -> V_4 . V_51 ,
V_121 ,
& V_175 , V_178 ) ;
if ( ! V_174 ) {
F_19 ( V_2 -> V_4 . V_51 ,
L_17 ) ;
F_78 ( V_173 ) ;
return - V_179 ;
}
V_177 . V_180 = V_2 -> V_4 . V_181 ;
V_177 . V_182 = V_183 ;
V_177 . V_184 = 4 ;
V_2 -> V_130 = V_173 ;
V_2 -> V_123 = V_174 ;
V_2 -> V_120 = V_175 ;
} else {
V_175 = F_86 ( V_2 -> V_4 . V_51 ,
V_2 -> V_4 . V_76 -> V_75 . V_81 , V_83 ,
V_104 ) ;
if ( F_87 ( V_2 -> V_4 . V_51 , V_175 ) ) {
F_19 ( V_2 -> V_4 . V_51 , L_18 ) ;
F_78 ( V_173 ) ;
return - V_179 ;
}
V_174 = V_2 -> V_4 . V_76 -> V_75 . V_81 ;
V_177 . V_185 = V_2 -> V_4 . V_181 ;
V_177 . V_186 = V_183 ;
V_177 . V_187 = 16 ;
V_2 -> V_95 = V_173 ;
V_2 -> V_172 = V_174 ;
V_2 -> V_103 = V_175 ;
}
V_48 = F_88 ( V_173 , & V_177 ) ;
if ( V_48 < 0 ) {
F_19 ( V_2 -> V_4 . V_51 ,
L_19 , V_48 ) ;
F_77 ( V_2 , V_171 ) ;
return V_48 ;
}
return 0 ;
}
static int F_89 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_5 ( V_9 ) ;
int V_48 ;
V_48 = F_81 ( V_2 , false ) ;
if ( V_48 < 0 ) {
F_19 ( V_9 -> V_51 , L_20 , V_48 ) ;
return V_48 ;
}
V_48 = F_81 ( V_2 , true ) ;
if ( V_48 < 0 ) {
F_19 ( V_9 -> V_51 , L_21 , V_48 ) ;
goto V_188;
}
V_48 = F_73 ( V_2 ) ;
if ( V_48 < 0 ) {
F_19 ( V_9 -> V_51 , L_22 , V_48 ) ;
goto V_189;
}
V_48 = F_90 ( V_9 -> V_146 , F_68 , 0 ,
F_91 ( V_9 -> V_51 ) , V_2 ) ;
if ( V_48 < 0 ) {
F_19 ( V_9 -> V_51 , L_23 , V_9 -> V_146 ) ;
goto V_189;
}
return 0 ;
V_189:
F_77 ( V_2 , true ) ;
V_188:
F_77 ( V_2 , false ) ;
return V_48 ;
}
static void F_92 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_5 ( V_9 ) ;
V_2 -> V_89 = 0 ;
if ( V_2 -> V_95 )
F_48 ( V_2 -> V_95 ) ;
}
static void F_93 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_5 ( V_9 ) ;
F_70 ( V_2 ) ;
V_2 -> V_153 = 0 ;
V_2 -> V_87 = 0 ;
F_77 ( V_2 , true ) ;
F_77 ( V_2 , false ) ;
F_94 ( V_9 -> V_146 , V_2 ) ;
}
static void F_95 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_5 ( V_9 ) ;
if ( V_2 -> V_10 ) {
V_2 -> V_90 |= V_190 ;
F_3 ( V_2 , V_2 -> V_90 , V_54 ) ;
}
}
static void F_96 ( struct V_8 * V_9 ,
struct V_191 * V_192 , struct V_191 * V_193 )
{
struct V_1 * V_2 = F_5 ( V_9 ) ;
unsigned int V_45 ;
unsigned long V_93 ;
unsigned int V_27 ;
int V_34 = 1 ;
struct V_194 * V_195 = F_97 ( V_2 -> V_50 ) ;
unsigned long V_196 = F_20 ( V_195 ) ;
int V_197 = ( V_2 -> V_38 -> V_49 ) ? 0x7FFF : 0xFFFF ;
V_197 *= 16 ;
F_33 ( & V_9 -> V_100 , V_93 ) ;
if ( V_2 -> V_23 )
F_8 ( V_2 , false ) ;
F_3 ( V_2 , V_2 -> V_90 | V_158 , V_54 ) ;
F_1 ( V_2 , V_54 ) ;
F_3 ( V_2 , 0 , V_54 ) ;
F_1 ( V_2 , V_54 ) ;
V_27 = V_2 -> V_28 ;
V_27 &= ~ V_198 ;
V_192 -> V_199 &= ~ V_200 ;
if ( ( V_192 -> V_199 & V_201 ) == V_201 ) {
V_34 ++ ;
if ( V_192 -> V_199 & V_202 ) {
V_27 |= V_198 ;
V_27 &= ~ V_203 ;
V_27 &= ~ V_204 ;
} else {
V_27 |= V_198 ;
V_27 |= V_203 ;
V_27 &= ~ V_204 ;
}
}
V_27 &= ~ V_205 ;
switch ( V_192 -> V_199 & V_206 ) {
case V_207 :
V_27 |= V_208 ;
V_34 += 5 ;
break;
case V_209 :
V_27 |= V_210 ;
V_34 += 6 ;
break;
case V_211 :
V_27 |= V_212 ;
V_34 += 7 ;
break;
default:
V_27 |= V_205 ;
V_34 += 8 ;
break;
}
if ( V_192 -> V_199 & V_213 ) {
V_27 |= V_214 ;
V_34 += 2 ;
} else {
V_27 &= ~ V_214 ;
V_34 ++ ;
}
F_3 ( V_2 , V_27 , V_30 ) ;
V_2 -> V_28 = V_27 ;
V_2 -> V_34 = V_34 ;
V_45 = F_98 ( V_9 , V_192 , V_193 ,
V_196 / V_197 ,
V_196 / 16 ) ;
F_37 ( & V_9 -> V_100 , V_93 ) ;
F_17 ( V_2 , V_45 ) ;
if ( F_99 ( V_192 ) )
F_100 ( V_192 , V_45 , V_45 ) ;
F_33 ( & V_9 -> V_100 , V_93 ) ;
if ( V_192 -> V_199 & V_215 ) {
V_2 -> V_17 |= V_164 ;
V_2 -> V_17 &= ~ V_18 ;
F_3 ( V_2 , V_2 -> V_17 , V_19 ) ;
if ( V_2 -> V_23 )
F_8 ( V_2 , true ) ;
} else {
V_2 -> V_17 &= ~ V_164 ;
V_2 -> V_17 &= ~ V_18 ;
F_3 ( V_2 , V_2 -> V_17 , V_19 ) ;
}
F_101 ( V_9 , V_192 -> V_199 , V_45 ) ;
F_1 ( V_2 , V_54 ) ;
F_3 ( V_2 , V_2 -> V_90 , V_54 ) ;
F_1 ( V_2 , V_54 ) ;
F_37 ( & V_9 -> V_100 , V_93 ) ;
}
static const char * F_102 ( struct V_8 * V_9 )
{
return V_216 ;
}
static int F_103 ( struct V_217 * V_218 ,
struct V_1 * V_2 )
{
struct V_219 * V_220 = V_218 -> V_51 . V_221 ;
int V_124 ;
V_124 = F_104 ( V_220 , L_24 ) ;
if ( V_124 < 0 ) {
F_19 ( & V_218 -> V_51 , L_25 , V_124 ) ;
return V_124 ;
}
V_2 -> V_4 . line = V_124 ;
V_2 -> V_10 = F_105 ( V_220 ,
L_26 ) ;
return 0 ;
}
static int F_106 ( struct V_217 * V_218 )
{
struct V_1 * V_2 ;
struct V_8 * V_9 ;
struct V_222 * V_222 ;
int V_48 ;
const struct V_223 * V_38 ;
const struct V_224 * V_225 ;
V_225 = F_107 ( V_226 , & V_218 -> V_51 ) ;
if ( ! V_225 ) {
F_19 ( & V_218 -> V_51 , L_27 ) ;
return - V_227 ;
}
V_38 = V_225 -> V_147 ;
V_2 = F_108 ( & V_218 -> V_51 , sizeof( * V_2 ) , V_178 ) ;
if ( ! V_2 ) {
F_19 ( & V_218 -> V_51 , L_28 ) ;
return - V_179 ;
}
V_48 = F_103 ( V_218 , V_2 ) ;
if ( V_48 < 0 )
return V_48 ;
V_9 = & V_2 -> V_4 ;
V_9 -> V_51 = & V_218 -> V_51 ;
V_9 -> V_228 = & V_229 ;
V_9 -> type = V_230 ;
V_9 -> V_161 = 32 ;
V_2 -> V_38 = V_38 ;
F_109 ( V_218 , V_2 ) ;
V_222 = F_110 ( V_218 , V_231 , 0 ) ;
if ( ! V_222 ) {
F_19 ( & V_218 -> V_51 , L_29 ) ;
return - V_227 ;
}
V_9 -> V_181 = V_222 -> V_232 ;
V_9 -> V_5 = F_111 ( & V_218 -> V_51 , V_222 ) ;
if ( F_83 ( V_9 -> V_5 ) )
return F_84 ( V_9 -> V_5 ) ;
V_2 -> V_50 = F_112 ( & V_218 -> V_51 , NULL ) ;
if ( F_83 ( V_2 -> V_50 ) ) {
F_19 ( & V_218 -> V_51 , L_30 ) ;
return F_84 ( V_2 -> V_50 ) ;
}
V_2 -> V_165 = F_113 ( & V_218 -> V_51 , L_24 ) ;
if ( F_83 ( V_2 -> V_165 ) ) {
F_19 ( & V_218 -> V_51 , L_31 ) ;
return F_84 ( V_2 -> V_165 ) ;
}
V_9 -> V_233 = V_234 ;
V_9 -> V_146 = F_114 ( V_218 , 0 ) ;
V_9 -> V_6 = 2 ;
V_48 = F_115 ( & V_235 , V_9 ) ;
if ( V_48 < 0 ) {
F_19 ( & V_218 -> V_51 , L_32 , V_48 ) ;
return V_48 ;
}
return V_48 ;
}
static int F_116 ( struct V_217 * V_218 )
{
struct V_1 * V_2 = F_117 ( V_218 ) ;
struct V_8 * V_9 = & V_2 -> V_4 ;
F_118 ( & V_235 , V_9 ) ;
return 0 ;
}
static int F_119 ( struct V_236 * V_51 )
{
struct V_1 * V_2 = F_120 ( V_51 ) ;
struct V_8 * V_9 = & V_2 -> V_4 ;
return F_121 ( & V_235 , V_9 ) ;
}
static int F_122 ( struct V_236 * V_51 )
{
struct V_1 * V_2 = F_120 ( V_51 ) ;
struct V_8 * V_9 = & V_2 -> V_4 ;
return F_123 ( & V_235 , V_9 ) ;
}
static int T_4 F_124 ( void )
{
int V_48 ;
V_48 = F_125 ( & V_235 ) ;
if ( V_48 < 0 ) {
F_126 ( L_33 ,
V_235 . V_237 ) ;
return V_48 ;
}
V_48 = F_127 ( & V_238 ) ;
if ( V_48 < 0 ) {
F_126 ( L_34 , V_48 ) ;
F_128 ( & V_235 ) ;
return V_48 ;
}
return 0 ;
}
static void T_5 F_129 ( void )
{
F_130 ( L_35 ) ;
F_131 ( & V_238 ) ;
F_128 ( & V_235 ) ;
}
