static inline unsigned long F_1 ( struct V_1 * V_2 )
{
if ( F_2 ( V_2 ) )
return V_3 ;
else
return V_4 ;
}
static inline unsigned long F_3 ( struct V_1 * V_2 )
{
if ( F_2 ( V_2 ) )
return V_5 ;
else
return V_6 ;
}
static unsigned long F_4 ( unsigned long V_7 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
unsigned long V_9 , V_10 ;
if ( V_7 != F_3 ( V_2 ) )
return - V_11 ;
F_5 ( & V_2 -> V_12 ) ;
V_9 = F_6 ( NULL , 0 , V_7 , V_13 | V_14 ,
V_15 | V_16 , V_17 , 0 , & V_10 ) ;
F_7 ( & V_2 -> V_12 ) ;
if ( V_10 )
F_8 ( V_9 , V_10 ) ;
return V_9 ;
}
static int F_9 ( struct V_18 * V_18 , struct V_19 * V_20 ,
enum V_21 type )
{
int V_22 = 0 ;
static const int V_23 [] = {
F_10 ( struct V_19 , V_24 ) ,
F_10 ( struct V_19 , V_25 ) ,
F_10 ( struct V_19 , V_26 ) ,
F_10 ( struct V_19 , V_27 ) ,
F_10 ( struct V_19 , V_28 ) ,
F_10 ( struct V_19 , V_29 ) ,
F_10 ( struct V_19 , V_30 ) ,
F_10 ( struct V_19 , V_31 ) ,
#ifdef F_11
F_10 ( struct V_19 , V_32 ) ,
F_10 ( struct V_19 , V_33 ) ,
F_10 ( struct V_19 , V_34 ) ,
F_10 ( struct V_19 , V_35 ) ,
F_10 ( struct V_19 , V_36 ) ,
F_10 ( struct V_19 , V_37 ) ,
F_10 ( struct V_19 , V_38 ) ,
F_10 ( struct V_19 , V_39 ) ,
#endif
} ;
int V_40 = F_12 ( V_23 ) ;
if ( F_13 ( F_11 ) && ! V_18 -> V_41 )
V_40 -= 8 ;
switch ( type ) {
case V_42 :
V_22 = F_14 ( V_18 -> V_43 . V_44 ) ;
if ( F_15 ( V_18 -> V_45 . V_44 ) )
V_22 += 8 ;
break;
case V_46 :
V_22 = F_16 ( V_18 -> V_47 . V_44 ) ;
if ( F_17 ( V_18 -> V_45 . V_44 ) )
V_22 += 8 ;
break;
case V_48 :
V_22 = F_18 ( V_18 -> V_47 . V_44 ) ;
if ( F_15 ( V_18 -> V_45 . V_44 ) )
V_22 += 8 ;
break;
default:
F_19 ( L_1 ) ;
F_20 () ;
break;
}
if ( V_22 >= V_40 ) {
F_21 ( 1 , L_2 ) ;
return - V_11 ;
}
return V_23 [ V_22 ] ;
}
static void T_1 * F_22 ( struct V_18 * V_18 , struct V_19 * V_20 )
{
unsigned long V_9 , V_49 , V_50 ;
int V_51 , V_52 , V_53 ;
T_2 V_47 ;
F_23 ( V_18 ) ;
F_24 ( V_18 ) ;
V_47 = V_18 -> V_47 . V_44 ;
if ( F_25 ( V_18 -> V_43 . V_44 ) == 3 ) {
V_51 = F_9 ( V_18 , V_20 , V_42 ) ;
if ( V_51 < 0 )
goto V_54;
V_9 = F_26 ( V_20 , V_51 ) ;
} else {
if ( V_18 -> V_47 . V_55 ) {
V_52 = F_9 ( V_18 , V_20 , V_48 ) ;
if ( V_52 < 0 )
goto V_54;
V_53 = F_9 ( V_18 , V_20 , V_46 ) ;
if ( V_53 < 0 )
goto V_54;
V_49 = F_26 ( V_20 , V_52 ) ;
V_50 = F_26 ( V_20 , V_53 ) ;
V_9 = V_49 + V_50 * ( 1 << F_27 ( V_47 ) ) ;
} else {
V_51 = F_9 ( V_18 , V_20 , V_42 ) ;
if ( V_51 < 0 )
goto V_54;
V_9 = F_26 ( V_20 , V_51 ) ;
}
V_9 += V_18 -> V_56 . V_44 ;
}
return ( void T_1 * ) V_9 ;
V_54:
return ( void T_1 * ) - 1 ;
}
static int F_28 ( struct V_18 * V_18 ,
struct V_19 * V_20 )
{
unsigned char V_57 [ V_58 ] ;
int V_41 = ! F_29 ( V_59 ) ;
int V_60 ;
int V_61 ;
V_60 = F_30 ( V_57 , ( void T_1 * ) V_20 -> V_62 , sizeof( V_57 ) ) ;
V_61 = sizeof( V_57 ) - V_60 ;
if ( ! V_61 )
return - V_63 ;
F_31 ( V_18 , V_57 , V_61 , V_41 ) ;
F_32 ( V_18 ) ;
if ( V_61 < V_18 -> V_64 )
return - V_63 ;
F_33 ( V_18 ) ;
if ( V_18 -> V_65 . V_66 [ 0 ] != 0x0f )
goto V_67;
if ( ( V_18 -> V_65 . V_66 [ 1 ] != 0x1a ) &&
( V_18 -> V_65 . V_66 [ 1 ] != 0x1b ) )
goto V_67;
return 0 ;
V_67:
return - V_11 ;
}
T_3 * F_34 ( struct V_19 * V_20 )
{
const struct V_68 * V_69 ;
const struct V_70 * V_71 ;
T_3 * V_72 = NULL ;
struct V_18 V_18 ;
T_4 V_73 ;
int V_74 ;
V_74 = F_28 ( & V_18 , V_20 ) ;
if ( V_74 )
goto V_75;
F_23 ( & V_18 ) ;
V_73 = F_35 ( V_18 . V_43 . V_44 ) ;
if ( V_73 > 3 ) {
V_74 = - V_11 ;
goto V_75;
}
V_69 = F_36 ( V_76 ) ;
if ( ! V_69 ) {
V_74 = - V_11 ;
goto V_75;
}
V_71 = & V_69 -> V_71 [ V_73 ] ;
V_72 = F_37 ( sizeof( * V_72 ) , V_77 ) ;
if ( ! V_72 ) {
V_74 = - V_78 ;
goto V_75;
}
V_72 -> V_79 = ( void T_1 * ) ( unsigned long ) V_71 -> V_80 ;
V_72 -> V_81 = ( void T_1 * ) ( unsigned long ) ~ V_71 -> V_82 ;
V_72 -> V_83 = 0 ;
V_72 -> V_84 = V_85 ;
V_72 -> V_86 = 0 ;
V_72 -> V_87 = V_88 ;
V_72 -> V_89 = F_22 ( & V_18 , V_20 ) ;
if ( V_72 -> V_89 == ( void * ) - 1 ) {
V_74 = - V_11 ;
goto V_75;
}
F_38 ( V_72 -> V_89 , V_71 ) ;
return V_72 ;
V_75:
F_39 ( V_72 ) ;
return F_40 ( V_74 ) ;
}
static T_1 void * F_41 ( void )
{
const struct V_90 * V_91 ;
if ( ! F_42 ( V_92 ) )
return V_93 ;
V_91 = F_36 ( V_94 ) ;
if ( ! V_91 )
return V_93 ;
if ( ! ( V_91 -> V_95 & V_96 ) )
return V_93 ;
return ( void T_1 * ) ( unsigned long )
( V_91 -> V_95 & V_97 ) ;
}
int F_43 ( void )
{
void T_1 * V_98 = V_93 ;
struct V_1 * V_2 = V_8 -> V_2 ;
int V_99 = 0 ;
V_98 = F_41 () ;
F_5 ( & V_2 -> V_12 ) ;
V_2 -> V_100 = V_98 ;
if ( V_2 -> V_100 == V_93 )
V_99 = - V_101 ;
F_7 ( & V_2 -> V_12 ) ;
return V_99 ;
}
int F_44 ( void )
{
struct V_1 * V_2 = V_8 -> V_2 ;
if ( ! F_42 ( V_92 ) )
return - V_101 ;
F_5 ( & V_2 -> V_12 ) ;
V_2 -> V_100 = V_93 ;
F_7 ( & V_2 -> V_12 ) ;
return 0 ;
}
static int F_45 ( struct V_1 * V_2 ,
unsigned long * V_102 ,
unsigned long T_1 * V_9 ,
unsigned long V_103 , unsigned long V_104 )
{
int V_99 ;
if ( F_2 ( V_2 ) ) {
V_99 = F_46 ( V_102 ,
V_9 , V_103 , V_104 ) ;
} else {
T_5 V_105 ( V_106 ) ;
T_5 V_107 = V_103 ;
T_5 V_108 = V_104 ;
T_5 T_1 * V_109 = ( T_5 T_1 * ) V_9 ;
V_99 = F_46 ( & V_106 ,
V_109 , V_107 , V_108 ) ;
* V_102 = V_106 ;
}
return V_99 ;
}
static int F_47 ( struct V_1 * V_2 , long T_1 * V_110 )
{
unsigned long V_111 = 0 ;
unsigned long V_112 = 0 ;
unsigned long V_113 ;
unsigned long V_114 ;
int V_99 = 0 ;
V_113 = F_4 ( F_3 ( V_2 ) ) ;
if ( F_48 ( ( void * ) V_113 ) )
return F_49 ( ( void * ) V_113 ) ;
V_114 = V_113 | V_115 ;
V_99 = F_45 ( V_2 , & V_112 , V_110 ,
V_111 , V_114 ) ;
if ( V_99 )
goto V_116;
if ( V_112 & V_115 ) {
V_99 = 0 ;
goto V_116;
}
if ( V_111 != V_112 ) {
V_99 = - V_11 ;
goto V_116;
}
F_50 ( V_113 ) ;
return 0 ;
V_116:
F_51 ( V_113 , F_3 ( V_2 ) ) ;
return V_99 ;
}
static int F_52 ( void )
{
unsigned long V_110 , V_98 ;
const struct V_90 * V_91 ;
struct V_1 * V_2 = V_8 -> V_2 ;
V_91 = F_36 ( V_94 ) ;
if ( ! V_91 )
return - V_11 ;
V_98 = V_91 -> V_95 & V_97 ;
V_110 = V_91 -> V_117 & V_118 ;
if ( ( V_110 < V_98 ) ||
( V_110 >= V_98 + F_1 ( V_2 ) ) )
return - V_11 ;
return F_47 ( V_2 , ( long T_1 * ) V_110 ) ;
}
int F_53 ( void )
{
if ( ! F_54 ( V_8 -> V_2 ) )
return - V_11 ;
if ( F_52 () ) {
F_55 ( V_85 , V_8 ) ;
}
return 0 ;
}
static int F_56 ( long T_1 * V_9 , int V_119 )
{
long V_120 ;
int V_121 = 1 ;
V_120 = F_57 ( ( unsigned long ) V_9 , V_121 ,
V_119 ? V_122 : 0 , NULL , NULL ) ;
if ( ! V_120 )
return - V_63 ;
if ( V_120 < 0 )
return V_120 ;
return 0 ;
}
static unsigned long F_58 ( struct V_1 * V_2 ,
unsigned long V_110 )
{
unsigned long V_113 = V_110 ;
int V_123 ;
V_113 &= ~ V_115 ;
if ( F_2 ( V_2 ) )
V_123 = 8 ;
else
V_123 = 4 ;
V_113 &= ~ ( V_123 - 1 ) ;
return V_113 ;
}
int F_59 ( struct V_1 * V_2 , unsigned long * V_124 ,
long T_1 * V_125 )
{
T_5 V_126 ;
int V_99 ;
if ( F_2 ( V_2 ) )
return F_60 ( * V_124 , V_125 ) ;
V_99 = F_60 ( V_126 , ( T_5 T_1 * ) V_125 ) ;
* V_124 = V_126 ;
return V_99 ;
}
static int F_61 ( struct V_1 * V_2 ,
long T_1 * V_125 ,
unsigned long * V_127 )
{
int V_99 ;
int V_128 ;
unsigned long V_110 ;
unsigned long V_113 ;
if ( ! F_62 ( V_129 , ( V_125 ) , sizeof( * V_125 ) ) )
return - V_63 ;
while ( 1 ) {
int V_130 = 0 ;
F_63 () ;
V_99 = F_59 ( V_2 , & V_110 , V_125 ) ;
F_64 () ;
if ( ! V_99 )
break;
if ( V_99 == - V_63 )
V_99 = F_56 ( V_125 , V_130 ) ;
if ( V_99 )
return V_99 ;
}
V_128 = V_110 & V_115 ;
V_113 = F_58 ( V_2 , V_110 ) ;
if ( ! V_128 && V_113 )
return - V_11 ;
if ( ! V_128 )
return - V_131 ;
* V_127 = V_113 ;
return 0 ;
}
static inline int F_65 ( struct V_1 * V_2 )
{
if ( F_2 ( V_2 ) )
return V_132 ;
else
return V_133 ;
}
static unsigned long F_66 ( struct V_1 * V_2 ,
unsigned long V_9 )
{
unsigned long V_134 ;
unsigned long V_135 = V_9 ;
if ( F_2 ( V_2 ) ) {
V_135 >>= 3 ;
V_134 = V_136 ;
} else {
V_135 >>= 2 ;
V_134 = V_137 ;
}
V_135 &= ( V_134 - 1 ) ;
V_135 *= F_65 ( V_2 ) ;
return V_135 ;
}
static inline unsigned long F_67 ( struct V_1 * V_2 )
{
unsigned long long V_138 ;
unsigned long long V_139 = ( 1ULL << 30 ) ;
if ( ! F_2 ( V_2 ) )
return ( 4ULL * V_139 ) / V_140 ;
V_138 = ( 1ULL << V_141 . V_142 ) ;
return V_138 / V_143 ;
}
static T_6 int F_68 ( struct V_1 * V_2 ,
unsigned long V_113 ,
unsigned long V_144 , unsigned long V_145 )
{
struct V_146 * V_147 ;
unsigned long V_9 , V_7 ;
unsigned long V_148 ;
unsigned long V_149 ;
V_148 = V_113 + F_66 ( V_2 , V_144 ) ;
V_149 = V_113 + F_66 ( V_2 , V_145 - 1 ) ;
V_149 += F_65 ( V_2 ) ;
V_147 = F_69 ( V_2 , V_148 ) ;
if ( ! V_147 || V_147 -> V_150 > V_148 )
return - V_11 ;
V_9 = V_148 ;
while ( V_147 && V_147 -> V_150 < V_149 ) {
if ( ! ( V_147 -> V_151 & V_17 ) )
return - V_11 ;
V_7 = F_70 ( V_147 -> V_152 , V_149 ) - V_9 ;
F_71 ( V_147 , V_9 , V_7 , NULL ) ;
F_72 ( V_9 , V_9 + V_7 ) ;
V_147 = V_147 -> V_153 ;
V_9 = V_147 -> V_150 ;
}
return 0 ;
}
static unsigned long F_73 ( struct V_1 * V_2 ,
unsigned long V_9 )
{
if ( F_2 ( V_2 ) ) {
int V_154 = 8 ;
V_9 &= ( ( 1UL << V_141 . V_142 ) - 1 ) ;
return ( V_9 / F_67 ( V_2 ) ) * V_154 ;
} else {
int V_154 = 4 ;
return ( V_9 / F_67 ( V_2 ) ) * V_154 ;
}
}
static int F_74 ( struct V_1 * V_2 ,
long T_1 * V_110 , unsigned long V_113 )
{
unsigned long V_111 = V_113 | V_115 ;
unsigned long V_105 ( V_112 ) ;
int V_99 ;
while ( 1 ) {
int V_130 = 1 ;
unsigned long V_155 = 0 ;
F_63 () ;
V_99 = F_45 ( V_2 , & V_112 ,
V_110 , V_111 , V_155 ) ;
F_64 () ;
if ( ! V_99 )
break;
if ( V_99 == - V_63 )
V_99 = F_56 ( V_110 , V_130 ) ;
if ( V_99 )
return V_99 ;
}
if ( V_112 != V_111 ) {
if ( ! V_112 )
return 0 ;
return - V_11 ;
}
return F_75 ( V_2 , V_113 , F_3 ( V_2 ) ) ;
}
static int F_76 ( struct V_1 * V_2 ,
unsigned long V_148 , unsigned long V_149 )
{
struct V_146 * V_156 ;
struct V_146 * V_157 ;
unsigned long V_158 = V_148 & ~ ( F_67 ( V_2 ) - 1 ) ;
unsigned long V_159 = V_158 + F_67 ( V_2 ) ;
unsigned long V_105 ( V_113 ) ;
void T_1 * V_160 ;
int V_99 ;
V_156 = F_77 ( V_2 , V_148 , & V_157 ) ;
while ( V_156 && ( V_156 -> V_151 & V_17 ) )
V_156 = V_156 -> V_153 ;
while ( V_157 && ( V_157 -> V_151 & V_17 ) )
V_157 = V_157 -> V_161 ;
V_156 = F_77 ( V_2 , V_148 , & V_157 ) ;
if ( ( ! V_157 || V_157 -> V_152 <= V_158 ) &&
( ! V_156 || V_156 -> V_150 >= V_159 ) ) {
V_148 = V_158 ;
V_149 = V_159 ;
}
V_160 = V_2 -> V_100 + F_73 ( V_2 , V_148 ) ;
V_99 = F_61 ( V_2 , V_160 , & V_113 ) ;
if ( V_99 == - V_131 ) {
V_99 = 0 ;
return 0 ;
}
if ( V_99 )
return V_99 ;
if ( ( V_148 == V_158 ) &&
( V_149 == V_159 ) )
return F_74 ( V_2 , V_160 , V_113 ) ;
return F_68 ( V_2 , V_113 , V_148 , V_149 ) ;
}
static int F_78 ( struct V_1 * V_2 ,
unsigned long V_148 , unsigned long V_149 )
{
unsigned long V_162 ;
F_79 ( V_148 , V_149 ) ;
V_162 = V_148 ;
while ( V_162 < V_149 ) {
int V_99 ;
unsigned long V_163 = F_80 ( V_162 + 1 ,
F_67 ( V_2 ) ) ;
unsigned long V_164 = V_149 ;
if ( V_164 > V_163 )
V_164 = V_163 ;
V_99 = F_76 ( V_2 , V_162 , V_164 ) ;
if ( V_99 )
return V_99 ;
V_162 = V_163 ;
}
return 0 ;
}
void F_81 ( struct V_1 * V_2 , struct V_146 * V_147 ,
unsigned long V_148 , unsigned long V_149 )
{
int V_99 ;
if ( ! F_54 ( V_8 -> V_2 ) )
return;
do {
if ( V_147 -> V_151 & V_17 )
return;
V_147 = V_147 -> V_153 ;
} while ( V_147 && V_147 -> V_150 < V_149 );
V_99 = F_78 ( V_2 , V_148 , V_149 ) ;
if ( V_99 )
F_55 ( V_85 , V_8 ) ;
}
