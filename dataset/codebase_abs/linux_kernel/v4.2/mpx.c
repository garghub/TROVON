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
unsigned long V_8 ;
unsigned long V_9 , V_10 ;
struct V_1 * V_2 = V_11 -> V_2 ;
T_1 V_12 ;
struct V_13 * V_14 ;
if ( V_7 != F_3 ( V_2 ) )
return - V_15 ;
F_5 ( & V_2 -> V_16 ) ;
if ( V_2 -> V_17 > V_18 ) {
V_8 = - V_19 ;
goto V_20;
}
V_9 = F_6 ( NULL , 0 , V_7 , 0 , V_21 | V_22 ) ;
if ( V_9 & ~ V_23 ) {
V_8 = V_9 ;
goto V_20;
}
V_12 = V_24 | V_25 | V_26 |
V_2 -> V_27 | V_28 | V_29 | V_30 ;
V_10 = V_9 >> V_31 ;
V_8 = F_7 ( NULL , V_9 , V_7 , V_12 , V_10 ) ;
if ( F_8 ( V_8 ) )
goto V_20;
V_14 = F_9 ( V_2 , V_8 ) ;
if ( ! V_14 ) {
V_8 = - V_19 ;
goto V_20;
}
if ( V_12 & V_32 ) {
F_10 ( & V_2 -> V_16 ) ;
F_11 ( V_8 , V_7 ) ;
return V_8 ;
}
V_20:
F_10 ( & V_2 -> V_16 ) ;
return V_8 ;
}
static int F_12 ( struct V_33 * V_33 , struct V_34 * V_35 ,
enum V_36 type )
{
int V_37 = 0 ;
static const int V_38 [] = {
F_13 ( struct V_34 , V_39 ) ,
F_13 ( struct V_34 , V_40 ) ,
F_13 ( struct V_34 , V_41 ) ,
F_13 ( struct V_34 , V_42 ) ,
F_13 ( struct V_34 , V_43 ) ,
F_13 ( struct V_34 , V_44 ) ,
F_13 ( struct V_34 , V_45 ) ,
F_13 ( struct V_34 , V_46 ) ,
#ifdef F_14
F_13 ( struct V_34 , V_47 ) ,
F_13 ( struct V_34 , V_48 ) ,
F_13 ( struct V_34 , V_49 ) ,
F_13 ( struct V_34 , V_50 ) ,
F_13 ( struct V_34 , V_51 ) ,
F_13 ( struct V_34 , V_52 ) ,
F_13 ( struct V_34 , V_53 ) ,
F_13 ( struct V_34 , V_54 ) ,
#endif
} ;
int V_55 = F_15 ( V_38 ) ;
if ( F_16 ( F_14 ) && ! V_33 -> V_56 )
V_55 -= 8 ;
switch ( type ) {
case V_57 :
V_37 = F_17 ( V_33 -> V_58 . V_59 ) ;
if ( F_18 ( V_33 -> V_60 . V_59 ) == 1 )
V_37 += 8 ;
break;
case V_61 :
V_37 = F_19 ( V_33 -> V_62 . V_59 ) ;
if ( F_20 ( V_33 -> V_60 . V_59 ) == 1 )
V_37 += 8 ;
break;
case V_63 :
V_37 = F_21 ( V_33 -> V_62 . V_59 ) ;
if ( F_18 ( V_33 -> V_60 . V_59 ) == 1 )
V_37 += 8 ;
break;
default:
F_22 ( L_1 ) ;
F_23 () ;
break;
}
if ( V_37 > V_55 ) {
F_24 ( 1 , L_2 ) ;
return - V_15 ;
}
return V_38 [ V_37 ] ;
}
static void T_2 * F_25 ( struct V_33 * V_33 , struct V_34 * V_35 )
{
unsigned long V_9 , V_64 , V_65 ;
int V_66 , V_67 , V_68 ;
T_3 V_62 ;
F_26 ( V_33 ) ;
F_27 ( V_33 ) ;
V_62 = V_33 -> V_62 . V_59 ;
if ( F_28 ( V_33 -> V_58 . V_59 ) == 3 ) {
V_66 = F_12 ( V_33 , V_35 , V_57 ) ;
if ( V_66 < 0 )
goto V_69;
V_9 = F_29 ( V_35 , V_66 ) ;
} else {
if ( V_33 -> V_62 . V_70 ) {
V_67 = F_12 ( V_33 , V_35 , V_63 ) ;
if ( V_67 < 0 )
goto V_69;
V_68 = F_12 ( V_33 , V_35 , V_61 ) ;
if ( V_68 < 0 )
goto V_69;
V_64 = F_29 ( V_35 , V_67 ) ;
V_65 = F_29 ( V_35 , V_68 ) ;
V_9 = V_64 + V_65 * ( 1 << F_30 ( V_62 ) ) ;
} else {
V_66 = F_12 ( V_33 , V_35 , V_57 ) ;
if ( V_66 < 0 )
goto V_69;
V_9 = F_29 ( V_35 , V_66 ) ;
}
V_9 += V_33 -> V_71 . V_59 ;
}
return ( void T_2 * ) V_9 ;
V_69:
return ( void T_2 * ) - 1 ;
}
static int F_31 ( struct V_33 * V_33 ,
struct V_34 * V_35 )
{
unsigned char V_72 [ V_73 ] ;
int V_56 = ! F_32 ( V_74 ) ;
int V_75 ;
int V_76 ;
V_75 = F_33 ( V_72 , ( void T_2 * ) V_35 -> V_77 , sizeof( V_72 ) ) ;
V_76 = sizeof( V_72 ) - V_75 ;
if ( ! V_76 )
return - V_78 ;
F_34 ( V_33 , V_72 , V_76 , V_56 ) ;
F_35 ( V_33 ) ;
if ( V_76 < V_33 -> V_79 )
return - V_78 ;
F_36 ( V_33 ) ;
if ( V_33 -> V_80 . V_81 [ 0 ] != 0x0f )
goto V_82;
if ( ( V_33 -> V_80 . V_81 [ 1 ] != 0x1a ) &&
( V_33 -> V_80 . V_81 [ 1 ] != 0x1b ) )
goto V_82;
return 0 ;
V_82:
return - V_15 ;
}
T_4 * F_37 ( struct V_34 * V_35 )
{
const struct V_83 * V_84 , * V_83 ;
T_4 * V_85 = NULL ;
struct V_33 V_33 ;
T_5 V_86 ;
int V_87 ;
V_87 = F_31 ( & V_33 , V_35 ) ;
if ( V_87 )
goto V_88;
F_26 ( & V_33 ) ;
V_86 = F_38 ( V_33 . V_58 . V_59 ) ;
if ( V_86 > 3 ) {
V_87 = - V_15 ;
goto V_88;
}
V_84 = F_39 ( V_89 ) ;
if ( ! V_84 ) {
V_87 = - V_15 ;
goto V_88;
}
V_83 = & V_84 [ V_86 ] ;
V_85 = F_40 ( sizeof( * V_85 ) , V_90 ) ;
if ( ! V_85 ) {
V_87 = - V_19 ;
goto V_88;
}
V_85 -> V_91 = ( void T_2 * ) ( unsigned long ) V_83 -> V_92 ;
V_85 -> V_93 = ( void T_2 * ) ( unsigned long ) ~ V_83 -> V_94 ;
V_85 -> V_95 = 0 ;
V_85 -> V_96 = V_97 ;
V_85 -> V_98 = 0 ;
V_85 -> V_99 = V_100 ;
V_85 -> V_101 = F_25 ( & V_33 , V_35 ) ;
if ( V_85 -> V_101 == ( void * ) - 1 ) {
V_87 = - V_15 ;
goto V_88;
}
F_41 ( V_85 -> V_101 , V_83 ) ;
return V_85 ;
V_88:
F_42 ( V_85 ) ;
return F_43 ( V_87 ) ;
}
static T_2 void * F_44 ( void )
{
const struct V_102 * V_102 ;
if ( ! F_45 ( V_103 ) )
return V_104 ;
V_102 = F_39 ( V_105 ) ;
if ( ! V_102 )
return V_104 ;
if ( ! ( V_102 -> V_106 & V_107 ) )
return V_104 ;
return ( void T_2 * ) ( unsigned long )
( V_102 -> V_106 & V_108 ) ;
}
int F_46 ( void )
{
void T_2 * V_109 = V_104 ;
struct V_1 * V_2 = V_11 -> V_2 ;
int V_8 = 0 ;
V_109 = F_44 () ;
F_5 ( & V_2 -> V_16 ) ;
V_2 -> V_110 = V_109 ;
if ( V_2 -> V_110 == V_104 )
V_8 = - V_111 ;
F_10 ( & V_2 -> V_16 ) ;
return V_8 ;
}
int F_47 ( void )
{
struct V_1 * V_2 = V_11 -> V_2 ;
if ( ! F_45 ( V_103 ) )
return - V_111 ;
F_5 ( & V_2 -> V_16 ) ;
V_2 -> V_110 = V_104 ;
F_10 ( & V_2 -> V_16 ) ;
return 0 ;
}
static int F_48 ( struct V_1 * V_2 ,
unsigned long * V_112 ,
unsigned long T_2 * V_9 ,
unsigned long V_113 , unsigned long V_114 )
{
int V_8 ;
if ( F_2 ( V_2 ) ) {
V_8 = F_49 ( V_112 ,
V_9 , V_113 , V_114 ) ;
} else {
T_6 V_115 ( V_116 ) ;
T_6 V_117 = V_113 ;
T_6 V_118 = V_114 ;
T_6 T_2 * V_119 = ( T_6 T_2 * ) V_9 ;
V_8 = F_49 ( & V_116 ,
V_119 , V_117 , V_118 ) ;
* V_112 = V_116 ;
}
return V_8 ;
}
static int F_50 ( struct V_1 * V_2 , long T_2 * V_120 )
{
unsigned long V_121 = 0 ;
unsigned long V_122 = 0 ;
unsigned long V_123 ;
unsigned long V_124 ;
int V_8 = 0 ;
V_123 = F_4 ( F_3 ( V_2 ) ) ;
if ( F_51 ( ( void * ) V_123 ) )
return F_52 ( ( void * ) V_123 ) ;
V_124 = V_123 | V_125 ;
V_8 = F_48 ( V_2 , & V_122 , V_120 ,
V_121 , V_124 ) ;
if ( V_8 )
goto V_126;
if ( V_122 & V_125 ) {
V_8 = 0 ;
goto V_126;
}
if ( V_121 != V_122 ) {
V_8 = - V_15 ;
goto V_126;
}
F_53 ( V_123 ) ;
return 0 ;
V_126:
F_54 ( V_123 , F_3 ( V_2 ) ) ;
return V_8 ;
}
static int F_55 ( void )
{
unsigned long V_120 , V_109 ;
const struct V_102 * V_102 ;
struct V_1 * V_2 = V_11 -> V_2 ;
V_102 = F_39 ( V_105 ) ;
if ( ! V_102 )
return - V_15 ;
V_109 = V_102 -> V_106 & V_108 ;
V_120 = V_102 -> V_127 & V_128 ;
if ( ( V_120 < V_109 ) ||
( V_120 >= V_109 + F_1 ( V_2 ) ) )
return - V_15 ;
return F_50 ( V_2 , ( long T_2 * ) V_120 ) ;
}
int F_56 ( void )
{
if ( ! F_57 ( V_11 -> V_2 ) )
return - V_15 ;
if ( F_55 () ) {
F_58 ( V_97 , V_11 ) ;
}
return 0 ;
}
static int F_59 ( long T_2 * V_9 , int V_129 )
{
long V_130 ;
int V_131 = 1 ;
int V_132 = 0 ;
V_130 = F_60 ( V_11 , V_11 -> V_2 , ( unsigned long ) V_9 ,
V_131 , V_129 , V_132 , NULL , NULL ) ;
if ( ! V_130 )
return - V_78 ;
if ( V_130 < 0 )
return V_130 ;
return 0 ;
}
static unsigned long F_61 ( struct V_1 * V_2 ,
unsigned long V_120 )
{
unsigned long V_123 = V_120 ;
int V_133 ;
V_123 &= ~ V_125 ;
if ( F_2 ( V_2 ) )
V_133 = 8 ;
else
V_133 = 4 ;
V_123 &= ~ ( V_133 - 1 ) ;
return V_123 ;
}
static int F_62 ( struct V_1 * V_2 ,
long T_2 * V_134 ,
unsigned long * V_135 )
{
int V_8 ;
int V_136 ;
unsigned long V_120 ;
unsigned long V_123 ;
if ( ! F_63 ( V_137 , ( V_134 ) , sizeof( * V_134 ) ) )
return - V_78 ;
while ( 1 ) {
int V_138 = 0 ;
F_64 () ;
V_8 = F_65 ( V_120 , V_134 ) ;
F_66 () ;
if ( ! V_8 )
break;
if ( V_8 == - V_78 )
V_8 = F_59 ( V_134 , V_138 ) ;
if ( V_8 )
return V_8 ;
}
V_136 = V_120 & V_125 ;
V_123 = F_61 ( V_2 , V_120 ) ;
if ( ! V_136 && V_123 )
return - V_15 ;
if ( ! V_136 )
return - V_139 ;
* V_135 = V_123 ;
return 0 ;
}
static inline int F_67 ( struct V_1 * V_2 )
{
if ( F_2 ( V_2 ) )
return V_140 ;
else
return V_141 ;
}
static unsigned long F_68 ( struct V_1 * V_2 ,
unsigned long V_9 )
{
unsigned long V_142 ;
unsigned long V_143 = V_9 ;
if ( F_2 ( V_2 ) ) {
V_143 >>= 3 ;
V_142 = V_144 ;
} else {
V_143 >>= 2 ;
V_142 = V_145 ;
}
V_143 &= ( V_142 - 1 ) ;
V_143 *= F_67 ( V_2 ) ;
return V_143 ;
}
static inline unsigned long F_69 ( struct V_1 * V_2 )
{
unsigned long long V_146 = ( 1ULL << V_147 . V_148 ) ;
if ( F_2 ( V_2 ) )
return V_146 / V_149 ;
else
return V_146 / V_150 ;
}
static T_7 int F_70 ( struct V_1 * V_2 ,
unsigned long V_123 ,
unsigned long V_151 , unsigned long V_152 )
{
struct V_13 * V_14 ;
unsigned long V_9 , V_7 ;
unsigned long V_153 ;
unsigned long V_154 ;
V_153 = V_123 + F_68 ( V_2 , V_151 ) ;
V_154 = V_123 + F_68 ( V_2 , V_152 - 1 ) ;
V_154 += F_67 ( V_2 ) ;
V_14 = F_9 ( V_2 , V_153 ) ;
if ( ! V_14 || V_14 -> V_155 > V_153 )
return - V_15 ;
V_9 = V_153 ;
while ( V_14 && V_14 -> V_155 < V_154 ) {
if ( ! ( V_14 -> V_12 & V_26 ) )
return - V_15 ;
V_7 = F_71 ( V_14 -> V_156 , V_154 ) - V_9 ;
F_72 ( V_14 , V_9 , V_7 , NULL ) ;
F_73 ( V_9 , V_9 + V_7 ) ;
V_14 = V_14 -> V_157 ;
V_9 = V_14 -> V_155 ;
}
return 0 ;
}
static unsigned long F_74 ( struct V_1 * V_2 ,
unsigned long V_9 )
{
if ( F_2 ( V_2 ) ) {
int V_158 = 8 ;
V_9 &= ( ( 1UL << V_147 . V_148 ) - 1 ) ;
return ( V_9 / F_69 ( V_2 ) ) * V_158 ;
} else {
int V_158 = 4 ;
return ( V_9 / F_69 ( V_2 ) ) * V_158 ;
}
}
static int F_75 ( struct V_1 * V_2 ,
long T_2 * V_120 , unsigned long V_123 )
{
unsigned long V_121 = V_123 | V_125 ;
unsigned long V_115 ( V_122 ) ;
int V_8 ;
while ( 1 ) {
int V_138 = 1 ;
unsigned long V_159 = 0 ;
F_64 () ;
V_8 = F_48 ( V_2 , & V_122 ,
V_120 , V_121 , V_159 ) ;
F_66 () ;
if ( ! V_8 )
break;
if ( V_8 == - V_78 )
V_8 = F_59 ( V_120 , V_138 ) ;
if ( V_8 )
return V_8 ;
}
if ( V_122 != V_121 ) {
if ( ! V_122 )
return 0 ;
return - V_15 ;
}
return F_76 ( V_2 , V_123 , F_3 ( V_2 ) ) ;
}
static int F_77 ( struct V_1 * V_2 ,
unsigned long V_153 , unsigned long V_154 )
{
struct V_13 * V_160 ;
struct V_13 * V_161 ;
unsigned long V_162 = V_153 & ~ ( F_69 ( V_2 ) - 1 ) ;
unsigned long V_163 = V_162 + F_69 ( V_2 ) ;
unsigned long V_115 ( V_123 ) ;
void T_2 * V_164 ;
int V_8 ;
V_160 = F_78 ( V_2 , V_153 , & V_161 ) ;
while ( V_160 && ( V_160 -> V_12 & V_26 ) )
V_160 = V_160 -> V_157 ;
while ( V_161 && ( V_161 -> V_12 & V_26 ) )
V_161 = V_161 -> V_165 ;
V_160 = F_78 ( V_2 , V_153 , & V_161 ) ;
if ( ( ! V_161 || V_161 -> V_156 <= V_162 ) &&
( ! V_160 || V_160 -> V_155 >= V_163 ) ) {
V_153 = V_162 ;
V_154 = V_163 ;
}
V_164 = V_2 -> V_110 + F_74 ( V_2 , V_153 ) ;
V_8 = F_62 ( V_2 , V_164 , & V_123 ) ;
if ( V_8 == - V_139 ) {
V_8 = 0 ;
return 0 ;
}
if ( V_8 )
return V_8 ;
if ( ( V_153 == V_162 ) &&
( V_154 == V_163 ) )
return F_75 ( V_2 , V_164 , V_123 ) ;
return F_70 ( V_2 , V_123 , V_153 , V_154 ) ;
}
static int F_79 ( struct V_1 * V_2 ,
unsigned long V_153 , unsigned long V_154 )
{
unsigned long V_166 ;
F_80 ( V_153 , V_154 ) ;
V_166 = V_153 ;
while ( V_166 < V_154 ) {
int V_8 ;
unsigned long V_167 = F_81 ( V_166 + 1 ,
F_69 ( V_2 ) ) ;
unsigned long V_168 = V_154 ;
if ( V_168 > V_167 )
V_168 = V_167 ;
V_8 = F_77 ( V_2 , V_166 , V_168 ) ;
if ( V_8 )
return V_8 ;
V_166 = V_167 ;
}
return 0 ;
}
void F_82 ( struct V_1 * V_2 , struct V_13 * V_14 ,
unsigned long V_153 , unsigned long V_154 )
{
int V_8 ;
if ( ! F_57 ( V_11 -> V_2 ) )
return;
do {
if ( V_14 -> V_12 & V_26 )
return;
V_14 = V_14 -> V_157 ;
} while ( V_14 && V_14 -> V_155 < V_154 );
V_8 = F_79 ( V_2 , V_153 , V_154 ) ;
if ( V_8 )
F_58 ( V_97 , V_11 ) ;
}
