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
if ( F_15 ( V_18 -> V_45 . V_44 ) == 1 )
V_22 += 8 ;
break;
case V_46 :
V_22 = F_16 ( V_18 -> V_47 . V_44 ) ;
if ( F_17 ( V_18 -> V_45 . V_44 ) == 1 )
V_22 += 8 ;
break;
case V_48 :
V_22 = F_18 ( V_18 -> V_47 . V_44 ) ;
if ( F_15 ( V_18 -> V_45 . V_44 ) == 1 )
V_22 += 8 ;
break;
default:
F_19 ( L_1 ) ;
F_20 () ;
break;
}
if ( V_22 > V_40 ) {
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
const struct V_68 * V_69 , * V_68 ;
T_3 * V_70 = NULL ;
struct V_18 V_18 ;
T_4 V_71 ;
int V_72 ;
V_72 = F_28 ( & V_18 , V_20 ) ;
if ( V_72 )
goto V_73;
F_23 ( & V_18 ) ;
V_71 = F_35 ( V_18 . V_43 . V_44 ) ;
if ( V_71 > 3 ) {
V_72 = - V_11 ;
goto V_73;
}
V_69 = F_36 ( V_74 ) ;
if ( ! V_69 ) {
V_72 = - V_11 ;
goto V_73;
}
V_68 = & V_69 [ V_71 ] ;
V_70 = F_37 ( sizeof( * V_70 ) , V_75 ) ;
if ( ! V_70 ) {
V_72 = - V_76 ;
goto V_73;
}
V_70 -> V_77 = ( void T_1 * ) ( unsigned long ) V_68 -> V_78 ;
V_70 -> V_79 = ( void T_1 * ) ( unsigned long ) ~ V_68 -> V_80 ;
V_70 -> V_81 = 0 ;
V_70 -> V_82 = V_83 ;
V_70 -> V_84 = 0 ;
V_70 -> V_85 = V_86 ;
V_70 -> V_87 = F_22 ( & V_18 , V_20 ) ;
if ( V_70 -> V_87 == ( void * ) - 1 ) {
V_72 = - V_11 ;
goto V_73;
}
F_38 ( V_70 -> V_87 , V_68 ) ;
return V_70 ;
V_73:
F_39 ( V_70 ) ;
return F_40 ( V_72 ) ;
}
static T_1 void * F_41 ( void )
{
const struct V_88 * V_88 ;
if ( ! F_42 ( V_89 ) )
return V_90 ;
V_88 = F_36 ( V_91 ) ;
if ( ! V_88 )
return V_90 ;
if ( ! ( V_88 -> V_92 & V_93 ) )
return V_90 ;
return ( void T_1 * ) ( unsigned long )
( V_88 -> V_92 & V_94 ) ;
}
int F_43 ( void )
{
void T_1 * V_95 = V_90 ;
struct V_1 * V_2 = V_8 -> V_2 ;
int V_96 = 0 ;
V_95 = F_41 () ;
F_5 ( & V_2 -> V_12 ) ;
V_2 -> V_97 = V_95 ;
if ( V_2 -> V_97 == V_90 )
V_96 = - V_98 ;
F_7 ( & V_2 -> V_12 ) ;
return V_96 ;
}
int F_44 ( void )
{
struct V_1 * V_2 = V_8 -> V_2 ;
if ( ! F_42 ( V_89 ) )
return - V_98 ;
F_5 ( & V_2 -> V_12 ) ;
V_2 -> V_97 = V_90 ;
F_7 ( & V_2 -> V_12 ) ;
return 0 ;
}
static int F_45 ( struct V_1 * V_2 ,
unsigned long * V_99 ,
unsigned long T_1 * V_9 ,
unsigned long V_100 , unsigned long V_101 )
{
int V_96 ;
if ( F_2 ( V_2 ) ) {
V_96 = F_46 ( V_99 ,
V_9 , V_100 , V_101 ) ;
} else {
T_5 V_102 ( V_103 ) ;
T_5 V_104 = V_100 ;
T_5 V_105 = V_101 ;
T_5 T_1 * V_106 = ( T_5 T_1 * ) V_9 ;
V_96 = F_46 ( & V_103 ,
V_106 , V_104 , V_105 ) ;
* V_99 = V_103 ;
}
return V_96 ;
}
static int F_47 ( struct V_1 * V_2 , long T_1 * V_107 )
{
unsigned long V_108 = 0 ;
unsigned long V_109 = 0 ;
unsigned long V_110 ;
unsigned long V_111 ;
int V_96 = 0 ;
V_110 = F_4 ( F_3 ( V_2 ) ) ;
if ( F_48 ( ( void * ) V_110 ) )
return F_49 ( ( void * ) V_110 ) ;
V_111 = V_110 | V_112 ;
V_96 = F_45 ( V_2 , & V_109 , V_107 ,
V_108 , V_111 ) ;
if ( V_96 )
goto V_113;
if ( V_109 & V_112 ) {
V_96 = 0 ;
goto V_113;
}
if ( V_108 != V_109 ) {
V_96 = - V_11 ;
goto V_113;
}
F_50 ( V_110 ) ;
return 0 ;
V_113:
F_51 ( V_110 , F_3 ( V_2 ) ) ;
return V_96 ;
}
static int F_52 ( void )
{
unsigned long V_107 , V_95 ;
const struct V_88 * V_88 ;
struct V_1 * V_2 = V_8 -> V_2 ;
V_88 = F_36 ( V_91 ) ;
if ( ! V_88 )
return - V_11 ;
V_95 = V_88 -> V_92 & V_94 ;
V_107 = V_88 -> V_114 & V_115 ;
if ( ( V_107 < V_95 ) ||
( V_107 >= V_95 + F_1 ( V_2 ) ) )
return - V_11 ;
return F_47 ( V_2 , ( long T_1 * ) V_107 ) ;
}
int F_53 ( void )
{
if ( ! F_54 ( V_8 -> V_2 ) )
return - V_11 ;
if ( F_52 () ) {
F_55 ( V_83 , V_8 ) ;
}
return 0 ;
}
static int F_56 ( long T_1 * V_9 , int V_116 )
{
long V_117 ;
int V_118 = 1 ;
int V_119 = 0 ;
V_117 = F_57 ( V_8 , V_8 -> V_2 , ( unsigned long ) V_9 ,
V_118 , V_116 , V_119 , NULL , NULL ) ;
if ( ! V_117 )
return - V_63 ;
if ( V_117 < 0 )
return V_117 ;
return 0 ;
}
static unsigned long F_58 ( struct V_1 * V_2 ,
unsigned long V_107 )
{
unsigned long V_110 = V_107 ;
int V_120 ;
V_110 &= ~ V_112 ;
if ( F_2 ( V_2 ) )
V_120 = 8 ;
else
V_120 = 4 ;
V_110 &= ~ ( V_120 - 1 ) ;
return V_110 ;
}
static int F_59 ( struct V_1 * V_2 ,
long T_1 * V_121 ,
unsigned long * V_122 )
{
int V_96 ;
int V_123 ;
unsigned long V_107 ;
unsigned long V_110 ;
if ( ! F_60 ( V_124 , ( V_121 ) , sizeof( * V_121 ) ) )
return - V_63 ;
while ( 1 ) {
int V_125 = 0 ;
F_61 () ;
V_96 = F_62 ( V_107 , V_121 ) ;
F_63 () ;
if ( ! V_96 )
break;
if ( V_96 == - V_63 )
V_96 = F_56 ( V_121 , V_125 ) ;
if ( V_96 )
return V_96 ;
}
V_123 = V_107 & V_112 ;
V_110 = F_58 ( V_2 , V_107 ) ;
if ( ! V_123 && V_110 )
return - V_11 ;
if ( ! V_123 )
return - V_126 ;
* V_122 = V_110 ;
return 0 ;
}
static inline int F_64 ( struct V_1 * V_2 )
{
if ( F_2 ( V_2 ) )
return V_127 ;
else
return V_128 ;
}
static unsigned long F_65 ( struct V_1 * V_2 ,
unsigned long V_9 )
{
unsigned long V_129 ;
unsigned long V_130 = V_9 ;
if ( F_2 ( V_2 ) ) {
V_130 >>= 3 ;
V_129 = V_131 ;
} else {
V_130 >>= 2 ;
V_129 = V_132 ;
}
V_130 &= ( V_129 - 1 ) ;
V_130 *= F_64 ( V_2 ) ;
return V_130 ;
}
static inline unsigned long F_66 ( struct V_1 * V_2 )
{
unsigned long long V_133 = ( 1ULL << V_134 . V_135 ) ;
if ( F_2 ( V_2 ) )
return V_133 / V_136 ;
else
return V_133 / V_137 ;
}
static T_6 int F_67 ( struct V_1 * V_2 ,
unsigned long V_110 ,
unsigned long V_138 , unsigned long V_139 )
{
struct V_140 * V_141 ;
unsigned long V_9 , V_7 ;
unsigned long V_142 ;
unsigned long V_143 ;
V_142 = V_110 + F_65 ( V_2 , V_138 ) ;
V_143 = V_110 + F_65 ( V_2 , V_139 - 1 ) ;
V_143 += F_64 ( V_2 ) ;
V_141 = F_68 ( V_2 , V_142 ) ;
if ( ! V_141 || V_141 -> V_144 > V_142 )
return - V_11 ;
V_9 = V_142 ;
while ( V_141 && V_141 -> V_144 < V_143 ) {
if ( ! ( V_141 -> V_145 & V_17 ) )
return - V_11 ;
V_7 = F_69 ( V_141 -> V_146 , V_143 ) - V_9 ;
F_70 ( V_141 , V_9 , V_7 , NULL ) ;
F_71 ( V_9 , V_9 + V_7 ) ;
V_141 = V_141 -> V_147 ;
V_9 = V_141 -> V_144 ;
}
return 0 ;
}
static unsigned long F_72 ( struct V_1 * V_2 ,
unsigned long V_9 )
{
if ( F_2 ( V_2 ) ) {
int V_148 = 8 ;
V_9 &= ( ( 1UL << V_134 . V_135 ) - 1 ) ;
return ( V_9 / F_66 ( V_2 ) ) * V_148 ;
} else {
int V_148 = 4 ;
return ( V_9 / F_66 ( V_2 ) ) * V_148 ;
}
}
static int F_73 ( struct V_1 * V_2 ,
long T_1 * V_107 , unsigned long V_110 )
{
unsigned long V_108 = V_110 | V_112 ;
unsigned long V_102 ( V_109 ) ;
int V_96 ;
while ( 1 ) {
int V_125 = 1 ;
unsigned long V_149 = 0 ;
F_61 () ;
V_96 = F_45 ( V_2 , & V_109 ,
V_107 , V_108 , V_149 ) ;
F_63 () ;
if ( ! V_96 )
break;
if ( V_96 == - V_63 )
V_96 = F_56 ( V_107 , V_125 ) ;
if ( V_96 )
return V_96 ;
}
if ( V_109 != V_108 ) {
if ( ! V_109 )
return 0 ;
return - V_11 ;
}
return F_74 ( V_2 , V_110 , F_3 ( V_2 ) ) ;
}
static int F_75 ( struct V_1 * V_2 ,
unsigned long V_142 , unsigned long V_143 )
{
struct V_140 * V_150 ;
struct V_140 * V_151 ;
unsigned long V_152 = V_142 & ~ ( F_66 ( V_2 ) - 1 ) ;
unsigned long V_153 = V_152 + F_66 ( V_2 ) ;
unsigned long V_102 ( V_110 ) ;
void T_1 * V_154 ;
int V_96 ;
V_150 = F_76 ( V_2 , V_142 , & V_151 ) ;
while ( V_150 && ( V_150 -> V_145 & V_17 ) )
V_150 = V_150 -> V_147 ;
while ( V_151 && ( V_151 -> V_145 & V_17 ) )
V_151 = V_151 -> V_155 ;
V_150 = F_76 ( V_2 , V_142 , & V_151 ) ;
if ( ( ! V_151 || V_151 -> V_146 <= V_152 ) &&
( ! V_150 || V_150 -> V_144 >= V_153 ) ) {
V_142 = V_152 ;
V_143 = V_153 ;
}
V_154 = V_2 -> V_97 + F_72 ( V_2 , V_142 ) ;
V_96 = F_59 ( V_2 , V_154 , & V_110 ) ;
if ( V_96 == - V_126 ) {
V_96 = 0 ;
return 0 ;
}
if ( V_96 )
return V_96 ;
if ( ( V_142 == V_152 ) &&
( V_143 == V_153 ) )
return F_73 ( V_2 , V_154 , V_110 ) ;
return F_67 ( V_2 , V_110 , V_142 , V_143 ) ;
}
static int F_77 ( struct V_1 * V_2 ,
unsigned long V_142 , unsigned long V_143 )
{
unsigned long V_156 ;
F_78 ( V_142 , V_143 ) ;
V_156 = V_142 ;
while ( V_156 < V_143 ) {
int V_96 ;
unsigned long V_157 = F_79 ( V_156 + 1 ,
F_66 ( V_2 ) ) ;
unsigned long V_158 = V_143 ;
if ( V_158 > V_157 )
V_158 = V_157 ;
V_96 = F_75 ( V_2 , V_156 , V_158 ) ;
if ( V_96 )
return V_96 ;
V_156 = V_157 ;
}
return 0 ;
}
void F_80 ( struct V_1 * V_2 , struct V_140 * V_141 ,
unsigned long V_142 , unsigned long V_143 )
{
int V_96 ;
if ( ! F_54 ( V_8 -> V_2 ) )
return;
do {
if ( V_141 -> V_145 & V_17 )
return;
V_141 = V_141 -> V_147 ;
} while ( V_141 && V_141 -> V_144 < V_143 );
V_96 = F_77 ( V_2 , V_142 , V_143 ) ;
if ( V_96 )
F_55 ( V_83 , V_8 ) ;
}
