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
V_15 | V_16 , V_17 , 0 , & V_10 , NULL ) ;
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
if ( V_72 -> V_89 == ( void T_1 * ) - 1 ) {
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
if ( F_44 ( V_2 , V_100 ) ) {
F_45 ( L_3
L_4 ,
V_8 -> V_101 , V_8 -> V_102 ) ;
V_99 = - V_103 ;
goto V_104;
}
V_2 -> V_105 . V_106 = V_98 ;
if ( V_2 -> V_105 . V_106 == V_93 )
V_99 = - V_103 ;
V_104:
F_7 ( & V_2 -> V_12 ) ;
return V_99 ;
}
int F_46 ( void )
{
struct V_1 * V_2 = V_8 -> V_2 ;
if ( ! F_42 ( V_92 ) )
return - V_103 ;
F_5 ( & V_2 -> V_12 ) ;
V_2 -> V_105 . V_106 = V_93 ;
F_7 ( & V_2 -> V_12 ) ;
return 0 ;
}
static int F_47 ( struct V_1 * V_2 ,
unsigned long * V_107 ,
unsigned long T_1 * V_9 ,
unsigned long V_108 , unsigned long V_109 )
{
int V_99 ;
if ( F_2 ( V_2 ) ) {
V_99 = F_48 ( V_107 ,
V_9 , V_108 , V_109 ) ;
} else {
T_5 V_110 ( V_111 ) ;
T_5 V_112 = V_108 ;
T_5 V_113 = V_109 ;
T_5 T_1 * V_114 = ( T_5 T_1 * ) V_9 ;
V_99 = F_48 ( & V_111 ,
V_114 , V_112 , V_113 ) ;
* V_107 = V_111 ;
}
return V_99 ;
}
static int F_49 ( struct V_1 * V_2 , long T_1 * V_115 )
{
unsigned long V_116 = 0 ;
unsigned long V_117 = 0 ;
unsigned long V_118 ;
unsigned long V_119 ;
int V_99 = 0 ;
V_118 = F_4 ( F_3 ( V_2 ) ) ;
if ( F_50 ( ( void * ) V_118 ) )
return F_51 ( ( void * ) V_118 ) ;
V_119 = V_118 | V_120 ;
V_99 = F_47 ( V_2 , & V_117 , V_115 ,
V_116 , V_119 ) ;
if ( V_99 )
goto V_121;
if ( V_117 & V_120 ) {
V_99 = 0 ;
goto V_121;
}
if ( V_116 != V_117 ) {
V_99 = - V_11 ;
goto V_121;
}
F_52 ( V_118 ) ;
return 0 ;
V_121:
F_53 ( V_118 , F_3 ( V_2 ) ) ;
return V_99 ;
}
static int F_54 ( void )
{
unsigned long V_115 , V_98 ;
const struct V_90 * V_91 ;
struct V_1 * V_2 = V_8 -> V_2 ;
V_91 = F_36 ( V_94 ) ;
if ( ! V_91 )
return - V_11 ;
V_98 = V_91 -> V_95 & V_97 ;
V_115 = V_91 -> V_122 & V_123 ;
if ( ( V_115 < V_98 ) ||
( V_115 >= V_98 + F_1 ( V_2 ) ) )
return - V_11 ;
return F_49 ( V_2 , ( long T_1 * ) V_115 ) ;
}
int F_55 ( void )
{
if ( ! F_56 ( V_8 -> V_2 ) )
return - V_11 ;
return F_54 () ;
}
static int F_57 ( long T_1 * V_9 , int V_124 )
{
long V_125 ;
int V_126 = 1 ;
V_125 = F_58 ( ( unsigned long ) V_9 , V_126 ,
V_124 ? V_127 : 0 , NULL , NULL ) ;
if ( ! V_125 )
return - V_63 ;
if ( V_125 < 0 )
return V_125 ;
return 0 ;
}
static unsigned long F_59 ( struct V_1 * V_2 ,
unsigned long V_115 )
{
unsigned long V_118 = V_115 ;
int V_128 ;
V_118 &= ~ V_120 ;
if ( F_2 ( V_2 ) )
V_128 = 8 ;
else
V_128 = 4 ;
V_118 &= ~ ( V_128 - 1 ) ;
return V_118 ;
}
static int F_60 ( struct V_1 * V_2 , unsigned long * V_129 ,
long T_1 * V_130 )
{
T_5 V_131 ;
int V_99 ;
if ( F_2 ( V_2 ) )
return F_61 ( * V_129 , V_130 ) ;
V_99 = F_61 ( V_131 , ( T_5 T_1 * ) V_130 ) ;
* V_129 = V_131 ;
return V_99 ;
}
static int F_62 ( struct V_1 * V_2 ,
long T_1 * V_130 ,
unsigned long * V_132 )
{
int V_99 ;
int V_133 ;
unsigned long V_115 ;
unsigned long V_118 ;
if ( ! F_63 ( V_134 , ( V_130 ) , sizeof( * V_130 ) ) )
return - V_63 ;
while ( 1 ) {
int V_135 = 0 ;
F_64 () ;
V_99 = F_60 ( V_2 , & V_115 , V_130 ) ;
F_65 () ;
if ( ! V_99 )
break;
if ( V_99 == - V_63 )
V_99 = F_57 ( V_130 , V_135 ) ;
if ( V_99 )
return V_99 ;
}
V_133 = V_115 & V_120 ;
V_118 = F_59 ( V_2 , V_115 ) ;
if ( ! V_133 && V_118 )
return - V_11 ;
if ( ! V_133 )
return - V_136 ;
* V_132 = V_118 ;
return 0 ;
}
static inline int F_66 ( struct V_1 * V_2 )
{
if ( F_2 ( V_2 ) )
return V_137 ;
else
return V_138 ;
}
static unsigned long F_67 ( struct V_1 * V_2 ,
unsigned long V_9 )
{
unsigned long V_139 ;
unsigned long V_140 = V_9 ;
if ( F_2 ( V_2 ) ) {
V_140 >>= 3 ;
V_139 = V_141 ;
} else {
V_140 >>= 2 ;
V_139 = V_142 ;
}
V_140 &= ( V_139 - 1 ) ;
V_140 *= F_66 ( V_2 ) ;
return V_140 ;
}
static inline unsigned long F_68 ( struct V_1 * V_2 )
{
unsigned long long V_143 ;
unsigned long long V_144 = ( 1ULL << 30 ) ;
if ( ! F_2 ( V_2 ) )
return ( 4ULL * V_144 ) / V_145 ;
V_143 = ( 1ULL << V_146 . V_147 ) ;
return V_143 / V_148 ;
}
static T_6 int F_69 ( struct V_1 * V_2 ,
unsigned long V_118 ,
unsigned long V_149 , unsigned long V_150 )
{
struct V_151 * V_152 ;
unsigned long V_9 , V_7 ;
unsigned long V_153 ;
unsigned long V_154 ;
V_153 = V_118 + F_67 ( V_2 , V_149 ) ;
V_154 = V_118 + F_67 ( V_2 , V_150 - 1 ) ;
V_154 += F_66 ( V_2 ) ;
V_152 = F_44 ( V_2 , V_153 ) ;
if ( ! V_152 || V_152 -> V_155 > V_153 )
return - V_11 ;
V_9 = V_153 ;
while ( V_152 && V_152 -> V_155 < V_154 ) {
if ( ! ( V_152 -> V_156 & V_17 ) )
return - V_11 ;
V_7 = F_70 ( V_152 -> V_157 , V_154 ) - V_9 ;
F_71 ( V_152 , V_9 , V_7 ) ;
F_72 ( V_9 , V_9 + V_7 ) ;
V_152 = V_152 -> V_158 ;
V_9 = V_152 -> V_155 ;
}
return 0 ;
}
static unsigned long F_73 ( struct V_1 * V_2 ,
unsigned long V_9 )
{
if ( F_2 ( V_2 ) ) {
int V_159 = 8 ;
V_9 &= ( ( 1UL << V_146 . V_147 ) - 1 ) ;
return ( V_9 / F_68 ( V_2 ) ) * V_159 ;
} else {
int V_159 = 4 ;
return ( V_9 / F_68 ( V_2 ) ) * V_159 ;
}
}
static int F_74 ( struct V_1 * V_2 ,
long T_1 * V_115 , unsigned long V_118 )
{
unsigned long V_116 = V_118 | V_120 ;
unsigned long V_110 ( V_117 ) ;
int V_99 ;
while ( 1 ) {
int V_135 = 1 ;
unsigned long V_160 = 0 ;
F_64 () ;
V_99 = F_47 ( V_2 , & V_117 ,
V_115 , V_116 , V_160 ) ;
F_65 () ;
if ( ! V_99 )
break;
if ( V_99 == - V_63 )
V_99 = F_57 ( V_115 , V_135 ) ;
if ( V_99 )
return V_99 ;
}
if ( V_117 != V_116 ) {
if ( ! V_117 )
return 0 ;
return - V_11 ;
}
return F_75 ( V_2 , V_118 , F_3 ( V_2 ) , NULL ) ;
}
static int F_76 ( struct V_1 * V_2 ,
unsigned long V_153 , unsigned long V_154 )
{
struct V_151 * V_161 ;
struct V_151 * V_162 ;
unsigned long V_163 = V_153 & ~ ( F_68 ( V_2 ) - 1 ) ;
unsigned long V_164 = V_163 + F_68 ( V_2 ) ;
unsigned long V_110 ( V_118 ) ;
void T_1 * V_165 ;
int V_99 ;
V_161 = F_77 ( V_2 , V_153 , & V_162 ) ;
while ( V_161 && ( V_161 -> V_156 & V_17 ) )
V_161 = V_161 -> V_158 ;
while ( V_162 && ( V_162 -> V_156 & V_17 ) )
V_162 = V_162 -> V_166 ;
V_161 = F_77 ( V_2 , V_153 , & V_162 ) ;
if ( ( ! V_162 || V_162 -> V_157 <= V_163 ) &&
( ! V_161 || V_161 -> V_155 >= V_164 ) ) {
V_153 = V_163 ;
V_154 = V_164 ;
}
V_165 = V_2 -> V_105 . V_106 + F_73 ( V_2 , V_153 ) ;
V_99 = F_62 ( V_2 , V_165 , & V_118 ) ;
if ( V_99 == - V_136 ) {
V_99 = 0 ;
return 0 ;
}
if ( V_99 )
return V_99 ;
if ( ( V_153 == V_163 ) &&
( V_154 == V_164 ) )
return F_74 ( V_2 , V_165 , V_118 ) ;
return F_69 ( V_2 , V_118 , V_153 , V_154 ) ;
}
static int F_78 ( struct V_1 * V_2 ,
unsigned long V_153 , unsigned long V_154 )
{
unsigned long V_167 ;
F_79 ( V_153 , V_154 ) ;
V_167 = V_153 ;
while ( V_167 < V_154 ) {
int V_99 ;
unsigned long V_168 = F_80 ( V_167 + 1 ,
F_68 ( V_2 ) ) ;
unsigned long V_169 = V_154 ;
if ( V_169 > V_168 )
V_169 = V_168 ;
V_99 = F_76 ( V_2 , V_167 , V_169 ) ;
if ( V_99 )
return V_99 ;
V_167 = V_168 ;
}
return 0 ;
}
void F_81 ( struct V_1 * V_2 , struct V_151 * V_152 ,
unsigned long V_153 , unsigned long V_154 )
{
int V_99 ;
if ( ! F_56 ( V_8 -> V_2 ) )
return;
do {
if ( V_152 -> V_156 & V_17 )
return;
V_152 = V_152 -> V_158 ;
} while ( V_152 && V_152 -> V_155 < V_154 );
V_99 = F_78 ( V_2 , V_153 , V_154 ) ;
if ( V_99 )
F_82 ( V_85 , V_8 ) ;
}
unsigned long F_83 ( unsigned long V_9 , unsigned long V_7 ,
unsigned long V_170 )
{
if ( ! F_56 ( V_8 -> V_2 ) )
return V_9 ;
if ( V_9 + V_7 <= V_100 )
return V_9 ;
if ( V_170 & V_171 )
return - V_78 ;
if ( V_7 > V_100 )
return - V_78 ;
return 0 ;
}
