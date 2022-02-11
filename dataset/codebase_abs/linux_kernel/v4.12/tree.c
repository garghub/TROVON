unsigned long F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_2 -> V_3 ) ;
}
static int F_3 ( struct V_4 * V_5 )
{
return F_2 ( V_5 -> V_6 ) != F_2 ( V_5 -> V_7 ) ;
}
void F_4 ( void )
{
if ( ! F_5 ( V_8 . V_9 . V_10 ) )
return;
F_6 ( F_7 ( L_1 ) ,
F_5 ( V_8 . V_7 ) ,
F_7 ( L_2 ) ) ;
F_8 ( V_8 . V_9 . V_11 . V_12 , false ) ;
if ( ! F_5 ( V_8 . V_9 . V_11 . exp ) )
return;
F_8 ( V_8 . V_9 . V_11 . exp , false ) ;
F_9 ( & V_13 ,
F_10 ( & V_8 ) , true ) ;
}
void F_11 ( void )
{
if ( F_5 ( V_14 . V_9 . V_10 ) ) {
F_6 ( F_7 ( L_3 ) ,
F_5 ( V_14 . V_7 ) ,
F_7 ( L_2 ) ) ;
F_8 ( V_14 . V_9 . V_11 . V_12 , false ) ;
}
}
bool F_12 ( void )
{
return F_13 ( V_15 ) ;
}
static void F_14 ( void )
{
struct V_16 * V_17 = F_10 ( & V_16 ) ;
int V_18 ;
V_18 = F_15 ( V_19 , & V_17 -> V_20 ) ;
F_16 ( F_17 ( V_21 ) &&
( V_18 & V_19 ) ) ;
F_16 ( F_17 ( V_21 ) &&
( V_18 & V_22 ) ) ;
}
static void F_18 ( void )
{
struct V_16 * V_17 = F_10 ( & V_16 ) ;
int V_18 ;
V_18 = F_15 ( V_19 , & V_17 -> V_20 ) ;
F_16 ( F_17 ( V_21 ) &&
! ( V_18 & V_19 ) ) ;
if ( V_18 & V_22 ) {
F_19 ( V_22 , & V_17 -> V_20 ) ;
F_20 () ;
F_21 () ;
}
}
static void F_22 ( void )
{
struct V_16 * V_17 = F_10 ( & V_16 ) ;
if ( F_23 ( & V_17 -> V_20 ) & V_19 )
return;
F_24 ( V_19 , & V_17 -> V_20 ) ;
}
bool F_25 ( void )
{
struct V_16 * V_17 = F_10 ( & V_16 ) ;
return ! ( F_23 ( & V_17 -> V_20 ) & V_19 ) ;
}
int F_26 ( struct V_16 * V_17 )
{
int V_23 = F_15 ( 0 , & V_17 -> V_20 ) ;
return V_23 & ~ V_22 ;
}
static bool F_27 ( int V_23 )
{
return ! ( V_23 & V_19 ) ;
}
static bool F_28 ( struct V_16 * V_17 , int V_23 )
{
return V_23 != F_26 ( V_17 ) ;
}
static void F_29 ( void )
{
struct V_16 * V_17 = F_10 ( & V_16 ) ;
int V_24 = F_15 ( 2 * V_19 ,
& V_17 -> V_20 ) ;
F_16 ( ! ( V_24 & V_19 ) ) ;
}
bool F_30 ( int V_25 )
{
int V_26 ;
int V_27 ;
struct V_16 * V_17 = & F_31 ( V_16 , V_25 ) ;
do {
V_26 = F_23 ( & V_17 -> V_20 ) ;
if ( V_26 & V_19 )
return false ;
V_27 = V_26 | V_22 ;
} while ( F_32 ( & V_17 -> V_20 , V_26 , V_27 ) != V_26 );
return true ;
}
static void F_33 ( void )
{
F_34 ( V_16 . V_28 , false ) ;
F_29 () ;
}
void F_35 ( bool V_29 )
{
F_36 () ;
F_37 ( F_7 ( L_4 ) ) ;
F_4 () ;
F_38 () ;
if ( ! F_39 ( F_10 ( & V_16 . V_30 ) ) )
goto V_31;
F_40 ( V_16 . V_30 , false ) ;
if ( F_41 ( F_42 ( V_16 . V_28 ) ) )
F_33 () ;
F_43 ( V_16 . V_32 ) ;
if ( ! V_29 )
F_44 ( V_33 ) ;
V_31:
F_37 ( F_7 ( L_5 ) ) ;
F_36 () ;
}
void F_45 ( void )
{
unsigned long V_34 ;
if ( ! F_42 ( V_16 . V_30 ) )
return;
F_46 () ;
if ( ! F_39 ( F_10 ( & V_16 . V_30 ) ) ) {
F_47 () ;
return;
}
F_40 ( V_16 . V_30 , false ) ;
F_36 () ;
if ( F_41 ( F_42 ( V_16 . V_28 ) ) ) {
F_48 ( V_34 ) ;
F_33 () ;
F_49 ( V_34 ) ;
}
if ( F_41 ( F_42 ( V_8 . V_9 . V_11 . exp ) ) )
F_4 () ;
F_43 ( V_16 . V_32 ) ;
F_36 () ;
F_47 () ;
}
unsigned long F_50 ( void )
{
return V_35 -> V_7 ;
}
unsigned long F_51 ( void )
{
return V_13 . V_7 ;
}
unsigned long F_52 ( void )
{
return V_36 . V_7 ;
}
unsigned long F_53 ( void )
{
return V_35 -> V_6 ;
}
unsigned long F_54 ( void )
{
return V_13 . V_6 ;
}
unsigned long F_55 ( void )
{
return V_36 . V_6 ;
}
unsigned long F_56 ( void )
{
return V_35 -> V_37 ;
}
unsigned long F_57 ( void )
{
return V_13 . V_37 ;
}
void F_58 ( void )
{
F_59 ( V_35 ) ;
}
void F_60 ( void )
{
F_59 ( & V_36 ) ;
}
void F_61 ( void )
{
F_59 ( & V_13 ) ;
}
void F_62 ( void )
{
struct V_4 * V_5 ;
F_63 (rsp) {
F_64 ( L_6 ,
V_5 -> V_38 , V_5 -> V_39 , V_5 -> V_40 -> V_41 ) ;
}
}
void F_65 ( void )
{
V_42 ++ ;
V_43 = 0 ;
}
void F_66 ( enum V_44 V_45 , int * V_34 ,
unsigned long * V_7 , unsigned long * V_6 )
{
struct V_4 * V_5 = NULL ;
switch ( V_45 ) {
case V_46 :
V_5 = V_35 ;
break;
case V_47 :
V_5 = & V_36 ;
break;
case V_48 :
V_5 = & V_13 ;
break;
default:
break;
}
if ( V_5 == NULL )
return;
* V_34 = F_2 ( V_5 -> V_49 ) ;
* V_7 = F_2 ( V_5 -> V_7 ) ;
* V_6 = F_2 ( V_5 -> V_6 ) ;
}
void F_67 ( unsigned long V_50 )
{
V_43 ++ ;
}
static struct V_1 * F_68 ( struct V_4 * V_5 )
{
return & V_5 -> V_51 [ 0 ] ;
}
static int F_69 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = F_68 ( V_5 ) ;
int V_52 = ( F_2 ( V_2 -> V_6 ) + 1 ) & 0x1 ;
int * V_53 = & V_2 -> V_54 [ V_52 ] ;
return F_2 ( * V_53 ) ;
}
static bool
F_70 ( struct V_4 * V_5 , struct V_55 * V_56 )
{
if ( F_3 ( V_5 ) )
return false ;
if ( F_69 ( V_5 ) )
return true ;
if ( ! F_71 ( & V_56 -> V_57 ) )
return false ;
if ( ! F_72 ( & V_56 -> V_57 , V_58 ) )
return true ;
if ( F_73 ( & V_56 -> V_57 ,
F_2 ( V_5 -> V_6 ) ) )
return true ;
return false ;
}
static void F_74 ( bool V_59 )
{
struct V_4 * V_5 ;
struct V_55 * V_56 ;
struct V_16 * V_17 = F_10 ( & V_16 ) ;
F_75 ( F_7 ( L_7 ) , V_17 -> V_60 , 0 ) ;
if ( F_17 ( V_21 ) &&
! V_59 && ! F_76 ( V_33 ) ) {
struct V_61 * T_1 V_62 =
F_77 ( F_78 () ) ;
F_75 ( F_7 ( L_8 ) , V_17 -> V_60 , 0 ) ;
F_79 ( V_63 ) ;
F_80 ( 1 , L_9 ,
V_33 -> V_64 , V_33 -> V_65 ,
T_1 -> V_64 , T_1 -> V_65 ) ;
}
F_63 (rsp) {
V_56 = F_10 ( V_5 -> V_66 ) ;
F_81 ( V_56 ) ;
}
F_82 () ;
F_83 ( V_15 ) ;
V_17 -> V_60 = 0 ;
F_14 () ;
F_84 ( V_15 ) ;
F_85 () ;
F_86 ( F_87 ( & V_67 ) ,
L_10 ) ;
F_86 ( F_87 ( & V_68 ) ,
L_11 ) ;
F_86 ( F_87 ( & V_69 ) ,
L_12 ) ;
}
static void F_88 ( bool V_59 )
{
struct V_16 * V_17 ;
V_17 = F_10 ( & V_16 ) ;
F_16 ( F_17 ( V_21 ) &&
( V_17 -> V_60 & V_70 ) == 0 ) ;
if ( ( V_17 -> V_60 & V_70 ) == V_71 )
F_74 ( V_59 ) ;
else
V_17 -> V_60 -= V_71 ;
}
void F_89 ( void )
{
unsigned long V_34 ;
F_48 ( V_34 ) ;
F_88 ( false ) ;
F_90 ( 0 ) ;
F_49 ( V_34 ) ;
}
void F_91 ( void )
{
F_88 ( 1 ) ;
}
void F_92 ( void )
{
struct V_16 * V_17 ;
F_86 ( ! F_93 () , L_13 ) ;
V_17 = F_10 ( & V_16 ) ;
F_16 ( F_17 ( V_21 ) &&
V_17 -> V_60 < 1 ) ;
if ( V_17 -> V_60 <= 1 ) {
F_74 ( true ) ;
} else {
F_75 ( F_7 ( L_14 ) , V_17 -> V_60 , V_17 -> V_60 - 1 ) ;
V_17 -> V_60 -- ;
}
F_90 ( 1 ) ;
}
void F_94 ( void )
{
unsigned long V_34 ;
F_48 ( V_34 ) ;
F_92 () ;
F_49 ( V_34 ) ;
}
static void F_95 ( long long V_72 , int V_59 )
{
F_96 (struct rcu_dynticks *rdtp = this_cpu_ptr(&rcu_dynticks);)
F_97 () ;
F_18 () ;
F_98 () ;
F_75 ( F_7 ( L_15 ) , V_72 , V_17 -> V_60 ) ;
if ( F_17 ( V_21 ) &&
! V_59 && ! F_76 ( V_33 ) ) {
struct V_61 * T_1 V_62 =
F_77 ( F_78 () ) ;
F_75 ( F_7 ( L_16 ) ,
V_72 , V_17 -> V_60 ) ;
F_79 ( V_63 ) ;
F_80 ( 1 , L_9 ,
V_33 -> V_64 , V_33 -> V_65 ,
T_1 -> V_64 , T_1 -> V_65 ) ;
}
}
static void F_99 ( bool V_59 )
{
struct V_16 * V_17 ;
long long V_72 ;
V_17 = F_10 ( & V_16 ) ;
V_72 = V_17 -> V_60 ;
F_16 ( F_17 ( V_21 ) && V_72 < 0 ) ;
if ( V_72 & V_70 ) {
V_17 -> V_60 += V_71 ;
} else {
V_17 -> V_60 = V_73 ;
F_95 ( V_72 , V_59 ) ;
}
}
void F_100 ( void )
{
unsigned long V_34 ;
F_48 ( V_34 ) ;
F_99 ( false ) ;
F_101 ( 0 ) ;
F_49 ( V_34 ) ;
}
void F_102 ( void )
{
F_99 ( 1 ) ;
}
void F_103 ( void )
{
struct V_16 * V_17 ;
long long V_72 ;
F_86 ( ! F_93 () , L_17 ) ;
V_17 = F_10 ( & V_16 ) ;
V_72 = V_17 -> V_60 ;
V_17 -> V_60 ++ ;
F_16 ( F_17 ( V_21 ) &&
V_17 -> V_60 == 0 ) ;
if ( V_72 )
F_75 ( F_7 ( L_18 ) , V_72 , V_17 -> V_60 ) ;
else
F_95 ( V_72 , true ) ;
F_101 ( 1 ) ;
}
void F_104 ( void )
{
unsigned long V_34 ;
F_48 ( V_34 ) ;
F_103 () ;
F_49 ( V_34 ) ;
}
void F_105 ( void )
{
struct V_16 * V_17 = F_10 ( & V_16 ) ;
int V_74 = 2 ;
F_16 ( V_17 -> V_75 < 0 ) ;
if ( F_25 () ) {
F_18 () ;
V_74 = 1 ;
}
V_17 -> V_75 += V_74 ;
F_36 () ;
}
void F_106 ( void )
{
struct V_16 * V_17 = F_10 ( & V_16 ) ;
F_16 ( V_17 -> V_75 <= 0 ) ;
F_16 ( F_25 () ) ;
if ( V_17 -> V_75 != 1 ) {
V_17 -> V_75 -= 2 ;
return;
}
V_17 -> V_75 = 0 ;
F_14 () ;
}
bool T_2 F_107 ( void )
{
return ! F_25 () ;
}
bool T_2 F_108 ( void )
{
bool V_76 ;
F_109 () ;
V_76 = F_107 () ;
F_110 () ;
return V_76 ;
}
void F_111 ( struct V_61 * V_77 )
{
int V_25 ;
F_36 () ;
V_25 = F_112 ( V_77 ) ;
if ( ! F_113 ( V_77 ) )
return;
F_114 ( F_115 ( & V_16 . V_30 , V_25 ) , true ) ;
}
bool F_116 ( void )
{
struct V_55 * V_56 ;
struct V_1 * V_2 ;
bool V_76 ;
if ( F_117 () )
return true ;
F_46 () ;
V_56 = F_10 ( & V_8 ) ;
V_2 = V_56 -> V_78 ;
V_76 = ( V_56 -> V_79 & F_1 ( V_2 ) ) ||
! V_80 ;
F_47 () ;
return V_76 ;
}
static int F_118 ( void )
{
return F_5 ( V_16 . V_60 ) <= 1 ;
}
static int F_119 ( struct V_55 * V_56 ,
bool * V_81 , unsigned long * V_82 )
{
V_56 -> V_83 = F_26 ( V_56 -> V_20 ) ;
F_120 ( V_56 , V_81 , V_82 ) ;
if ( F_27 ( V_56 -> V_83 ) ) {
F_121 ( V_56 -> V_5 -> V_38 , V_56 -> V_7 , V_56 -> V_25 , F_7 ( L_19 ) ) ;
if ( F_122 ( F_2 ( V_56 -> V_7 ) + V_84 / 4 ,
V_56 -> V_78 -> V_7 ) )
F_123 ( V_56 -> V_85 , true ) ;
return 1 ;
}
return 0 ;
}
static int F_124 ( struct V_55 * V_56 ,
bool * V_81 , unsigned long * V_82 )
{
unsigned long V_86 ;
bool * V_87 ;
bool * V_88 ;
unsigned long V_89 ;
struct V_1 * V_2 ;
if ( F_28 ( V_56 -> V_20 , V_56 -> V_83 ) ) {
F_121 ( V_56 -> V_5 -> V_38 , V_56 -> V_7 , V_56 -> V_25 , F_7 ( L_19 ) ) ;
V_56 -> V_90 ++ ;
return 1 ;
}
V_86 = V_91 ;
V_89 = F_125 () ;
if ( V_86 > V_89 / 2 ) {
F_123 ( V_91 , V_89 ) ;
V_86 = V_89 / 2 ;
} else if ( V_86 < 1 ) {
F_123 ( V_91 , 1 ) ;
V_86 = 1 ;
}
V_2 = V_56 -> V_78 ;
V_88 = F_115 ( & V_16 . V_30 , V_56 -> V_25 ) ;
if ( F_126 ( V_92 , V_56 -> V_5 -> V_93 + V_86 ) &&
F_2 ( V_56 -> V_94 ) != F_31 ( V_16 . V_32 , V_56 -> V_25 ) &&
F_2 ( V_56 -> V_7 ) == V_2 -> V_7 && ! V_56 -> V_85 ) {
F_121 ( V_56 -> V_5 -> V_38 , V_56 -> V_7 , V_56 -> V_25 , F_7 ( L_20 ) ) ;
return 1 ;
} else {
F_114 ( V_88 , true ) ;
}
if ( ! ( V_56 -> V_79 & F_1 ( V_2 ) ) ) {
F_121 ( V_56 -> V_5 -> V_38 , V_56 -> V_7 , V_56 -> V_25 , F_7 ( L_21 ) ) ;
V_56 -> V_95 ++ ;
return 1 ;
}
V_87 = & F_31 ( V_16 . V_28 , V_56 -> V_25 ) ;
if ( ! F_2 ( * V_87 ) &&
( F_126 ( V_92 , V_56 -> V_5 -> V_93 + V_86 ) ||
F_126 ( V_92 , V_56 -> V_5 -> V_96 ) ) ) {
F_123 ( * V_87 , true ) ;
F_114 ( V_88 , true ) ;
V_56 -> V_5 -> V_96 += 5 ;
}
if ( V_92 - V_56 -> V_5 -> V_93 > F_125 () / 2 )
F_127 ( V_56 -> V_25 ) ;
return 0 ;
}
static void F_128 ( struct V_4 * V_5 )
{
unsigned long V_97 = V_92 ;
unsigned long j1 ;
V_5 -> V_93 = V_97 ;
F_129 () ;
j1 = F_125 () ;
F_123 ( V_5 -> V_98 , V_97 + j1 ) ;
V_5 -> V_96 = V_97 + j1 / 2 ;
V_5 -> V_99 = F_2 ( V_5 -> V_100 ) ;
}
static const char * F_130 ( short V_101 )
{
if ( V_101 < 0 || V_101 >= F_131 ( V_102 ) )
return L_22 ;
return V_102 [ V_101 ] ;
}
static void F_132 ( struct V_4 * V_5 )
{
unsigned long V_103 ;
unsigned long V_97 ;
V_97 = V_92 ;
V_103 = F_2 ( V_5 -> V_104 ) ;
if ( V_97 - V_103 > 2 * V_105 ) {
F_133 ( L_23 ,
V_5 -> V_38 , V_97 - V_103 ,
V_5 -> V_7 , V_5 -> V_6 ,
V_5 -> V_49 ,
F_130 ( V_5 -> V_39 ) , V_5 -> V_39 ,
V_5 -> V_40 ? V_5 -> V_40 -> V_41 : ~ 0 ) ;
if ( V_5 -> V_40 ) {
F_134 ( V_5 -> V_40 ) ;
F_135 ( V_5 -> V_40 ) ;
}
}
}
static void F_136 ( struct V_4 * V_5 )
{
int V_25 ;
unsigned long V_34 ;
struct V_1 * V_2 ;
F_137 (rsp, rnp) {
F_138 ( V_2 , V_34 ) ;
F_139 (rnp, cpu)
if ( V_2 -> V_106 & F_140 ( V_2 , V_25 ) )
if ( ! F_141 ( V_25 ) )
F_142 ( V_25 ) ;
F_143 ( V_2 , V_34 ) ;
}
}
static void F_144 ( struct V_4 * V_5 )
{
unsigned long V_97 ;
if ( ! V_107 )
return;
V_97 = F_2 ( V_5 -> V_108 ) ;
if ( F_126 ( V_92 , V_97 ) && V_5 -> V_40 &&
( F_3 ( V_5 ) || F_2 ( V_5 -> V_49 ) ) ) {
F_80 ( 1 , L_24 , V_5 -> V_38 ) ;
F_79 ( V_109 ) ;
F_135 ( V_5 -> V_40 ) ;
F_123 ( V_5 -> V_108 , V_97 + V_105 ) ;
}
}
static inline void F_145 ( void )
{
if ( V_110 )
F_146 ( L_25 ) ;
}
static void F_147 ( struct V_4 * V_5 , unsigned long V_7 )
{
int V_25 ;
long V_111 ;
unsigned long V_34 ;
unsigned long V_103 ;
unsigned long V_97 ;
int V_112 = 0 ;
struct V_1 * V_2 = F_68 ( V_5 ) ;
long V_113 = 0 ;
F_144 ( V_5 ) ;
if ( V_114 )
return;
F_138 ( V_2 , V_34 ) ;
V_111 = V_92 - F_2 ( V_5 -> V_98 ) ;
if ( V_111 < V_115 || ! F_3 ( V_5 ) ) {
F_143 ( V_2 , V_34 ) ;
return;
}
F_123 ( V_5 -> V_98 ,
V_92 + 3 * F_125 () + 3 ) ;
F_143 ( V_2 , V_34 ) ;
F_133 ( L_26 ,
V_5 -> V_38 ) ;
F_148 () ;
F_137 (rsp, rnp) {
F_138 ( V_2 , V_34 ) ;
V_112 += F_149 ( V_2 ) ;
if ( V_2 -> V_106 != 0 ) {
F_139 (rnp, cpu)
if ( V_2 -> V_106 & F_140 ( V_2 , V_25 ) ) {
F_150 ( V_5 , V_25 ) ;
V_112 ++ ;
}
}
F_143 ( V_2 , V_34 ) ;
}
F_151 () ;
F_152 (cpu)
V_113 += F_153 ( & F_115 ( V_5 -> V_66 ,
V_25 ) -> V_57 ) ;
F_154 ( L_27 ,
F_78 () , ( long ) ( V_92 - V_5 -> V_93 ) ,
( long ) V_5 -> V_7 , ( long ) V_5 -> V_6 , V_113 ) ;
if ( V_112 ) {
F_136 ( V_5 ) ;
F_155 ( V_5 ) ;
} else {
if ( F_2 ( V_5 -> V_7 ) != V_7 ||
F_2 ( V_5 -> V_6 ) == V_7 ) {
F_133 ( L_28 ) ;
} else {
V_97 = V_92 ;
V_103 = F_2 ( V_5 -> V_104 ) ;
F_133 ( L_29 ,
V_5 -> V_38 , V_97 - V_103 , V_97 , V_103 ,
V_116 ,
F_68 ( V_5 ) -> V_106 ) ;
F_134 ( V_33 ) ;
}
}
F_132 ( V_5 ) ;
F_145 () ;
F_59 ( V_5 ) ;
}
static void F_156 ( struct V_4 * V_5 )
{
int V_25 ;
unsigned long V_34 ;
struct V_1 * V_2 = F_68 ( V_5 ) ;
long V_113 = 0 ;
F_144 ( V_5 ) ;
if ( V_114 )
return;
F_133 ( L_30 , V_5 -> V_38 ) ;
F_148 () ;
F_150 ( V_5 , F_78 () ) ;
F_151 () ;
F_152 (cpu)
V_113 += F_153 ( & F_115 ( V_5 -> V_66 ,
V_25 ) -> V_57 ) ;
F_154 ( L_31 ,
V_92 - V_5 -> V_93 ,
( long ) V_5 -> V_7 , ( long ) V_5 -> V_6 , V_113 ) ;
F_132 ( V_5 ) ;
F_136 ( V_5 ) ;
F_138 ( V_2 , V_34 ) ;
if ( F_157 ( V_92 , F_2 ( V_5 -> V_98 ) ) )
F_123 ( V_5 -> V_98 ,
V_92 + 3 * F_125 () + 3 ) ;
F_143 ( V_2 , V_34 ) ;
F_145 () ;
F_127 ( F_78 () ) ;
}
static void F_158 ( struct V_4 * V_5 , struct V_55 * V_56 )
{
unsigned long V_6 ;
unsigned long V_7 ;
unsigned long V_117 ;
unsigned long V_97 ;
unsigned long V_118 ;
struct V_1 * V_2 ;
if ( ( V_114 && ! V_107 ) ||
! F_3 ( V_5 ) )
return;
F_144 ( V_5 ) ;
V_97 = V_92 ;
V_7 = F_2 ( V_5 -> V_7 ) ;
F_159 () ;
V_118 = F_2 ( V_5 -> V_98 ) ;
F_159 () ;
V_117 = F_2 ( V_5 -> V_93 ) ;
F_159 () ;
V_6 = F_2 ( V_5 -> V_6 ) ;
if ( F_157 ( V_6 , V_7 ) ||
F_122 ( V_97 , V_118 ) ||
F_157 ( V_117 , V_118 ) )
return;
V_2 = V_56 -> V_78 ;
if ( F_3 ( V_5 ) &&
( F_2 ( V_2 -> V_106 ) & V_56 -> V_79 ) ) {
F_156 ( V_5 ) ;
} else if ( F_3 ( V_5 ) &&
F_157 ( V_97 , V_118 + V_115 ) ) {
F_147 ( V_5 , V_7 ) ;
}
}
void F_160 ( void )
{
struct V_4 * V_5 ;
F_63 (rsp)
F_123 ( V_5 -> V_98 , V_92 + V_84 / 2 ) ;
}
static unsigned long F_161 ( struct V_4 * V_5 ,
struct V_1 * V_2 )
{
if ( F_68 ( V_5 ) == V_2 && V_2 -> V_7 == V_2 -> V_6 )
return V_2 -> V_6 + 1 ;
return V_2 -> V_6 + 2 ;
}
static void F_162 ( struct V_1 * V_2 , struct V_55 * V_56 ,
unsigned long V_119 , const char * V_10 )
{
F_163 ( V_56 -> V_5 -> V_38 , V_2 -> V_7 ,
V_2 -> V_6 , V_119 , V_2 -> V_120 ,
V_2 -> V_121 , V_2 -> V_122 , V_10 ) ;
}
static bool V_62
F_164 ( struct V_1 * V_2 , struct V_55 * V_56 ,
unsigned long * V_123 )
{
unsigned long V_119 ;
bool V_76 = false ;
struct V_1 * V_124 = F_68 ( V_56 -> V_5 ) ;
V_119 = F_161 ( V_56 -> V_5 , V_2 ) ;
F_162 ( V_2 , V_56 , V_119 , F_7 ( L_32 ) ) ;
if ( V_2 -> V_54 [ V_119 & 0x1 ] ) {
F_162 ( V_2 , V_56 , V_119 , F_7 ( L_33 ) ) ;
goto V_31;
}
if ( V_2 -> V_7 != V_2 -> V_6 ||
F_2 ( V_124 -> V_7 ) != F_2 ( V_124 -> V_6 ) ) {
V_2 -> V_54 [ V_119 & 0x1 ] ++ ;
F_162 ( V_2 , V_56 , V_119 , F_7 ( L_34 ) ) ;
goto V_31;
}
if ( V_2 != V_124 )
F_165 ( V_124 ) ;
V_119 = F_161 ( V_56 -> V_5 , V_124 ) ;
if ( ! F_166 ( V_56 -> V_25 ) )
( void ) F_167 ( & V_56 -> V_57 , V_119 ) ;
if ( V_124 -> V_54 [ V_119 & 0x1 ] ) {
F_162 ( V_2 , V_56 , V_119 , F_7 ( L_35 ) ) ;
goto V_125;
}
V_124 -> V_54 [ V_119 & 0x1 ] ++ ;
if ( V_124 -> V_7 != V_124 -> V_6 ) {
F_162 ( V_2 , V_56 , V_119 , F_7 ( L_36 ) ) ;
} else {
F_162 ( V_2 , V_56 , V_119 , F_7 ( L_37 ) ) ;
V_76 = F_168 ( V_56 -> V_5 , V_124 , V_56 ) ;
}
V_125:
if ( V_2 != V_124 )
F_169 ( V_124 ) ;
V_31:
if ( V_123 != NULL )
* V_123 = V_119 ;
return V_76 ;
}
static int F_170 ( struct V_4 * V_5 , struct V_1 * V_2 )
{
int V_119 = V_2 -> V_6 ;
int V_126 ;
struct V_55 * V_56 = F_10 ( V_5 -> V_66 ) ;
V_2 -> V_54 [ V_119 & 0x1 ] = 0 ;
V_126 = V_2 -> V_54 [ ( V_119 + 1 ) & 0x1 ] ;
F_162 ( V_2 , V_56 , V_119 ,
V_126 ? F_7 ( L_38 ) : F_7 ( L_39 ) ) ;
return V_126 ;
}
static void F_171 ( struct V_4 * V_5 )
{
if ( V_33 == V_5 -> V_40 ||
! F_2 ( V_5 -> V_49 ) ||
! V_5 -> V_40 )
return;
F_172 ( & V_5 -> V_127 ) ;
}
static bool F_173 ( struct V_4 * V_5 , struct V_1 * V_2 ,
struct V_55 * V_56 )
{
bool V_76 = false ;
if ( ! F_174 ( & V_56 -> V_57 ) )
return false ;
if ( F_167 ( & V_56 -> V_57 , F_161 ( V_5 , V_2 ) ) )
V_76 = F_164 ( V_2 , V_56 , NULL ) ;
if ( F_72 ( & V_56 -> V_57 , V_128 ) )
F_6 ( V_5 -> V_38 , V_56 -> V_7 , F_7 ( L_40 ) ) ;
else
F_6 ( V_5 -> V_38 , V_56 -> V_7 , F_7 ( L_41 ) ) ;
return V_76 ;
}
static bool F_175 ( struct V_4 * V_5 , struct V_1 * V_2 ,
struct V_55 * V_56 )
{
if ( ! F_174 ( & V_56 -> V_57 ) )
return false ;
F_176 ( & V_56 -> V_57 , V_2 -> V_6 ) ;
return F_173 ( V_5 , V_2 , V_56 ) ;
}
static bool F_177 ( struct V_4 * V_5 , struct V_1 * V_2 ,
struct V_55 * V_56 )
{
bool V_76 ;
bool V_129 ;
if ( V_56 -> V_6 == V_2 -> V_6 &&
! F_41 ( F_2 ( V_56 -> V_85 ) ) ) {
V_76 = F_173 ( V_5 , V_2 , V_56 ) ;
} else {
V_76 = F_175 ( V_5 , V_2 , V_56 ) ;
V_56 -> V_6 = V_2 -> V_6 ;
F_6 ( V_5 -> V_38 , V_56 -> V_7 , F_7 ( L_42 ) ) ;
}
if ( V_56 -> V_7 != V_2 -> V_7 || F_41 ( F_2 ( V_56 -> V_85 ) ) ) {
V_56 -> V_7 = V_2 -> V_7 ;
F_6 ( V_5 -> V_38 , V_56 -> V_7 , F_7 ( L_43 ) ) ;
V_129 = ! ! ( V_2 -> V_106 & V_56 -> V_79 ) ;
V_56 -> V_9 . V_11 . V_12 = V_129 ;
V_56 -> V_94 = F_5 ( V_16 . V_32 ) ;
V_56 -> V_130 = V_129 ;
F_178 ( V_56 ) ;
F_123 ( V_56 -> V_85 , false ) ;
}
return V_76 ;
}
static void F_179 ( struct V_4 * V_5 , struct V_55 * V_56 )
{
unsigned long V_34 ;
bool V_131 ;
struct V_1 * V_2 ;
F_48 ( V_34 ) ;
V_2 = V_56 -> V_78 ;
if ( ( V_56 -> V_7 == F_2 ( V_2 -> V_7 ) &&
V_56 -> V_6 == F_2 ( V_2 -> V_6 ) &&
! F_41 ( F_2 ( V_56 -> V_85 ) ) ) ||
! F_180 ( V_2 ) ) {
F_49 ( V_34 ) ;
return;
}
V_131 = F_177 ( V_5 , V_2 , V_56 ) ;
F_143 ( V_2 , V_34 ) ;
if ( V_131 )
F_171 ( V_5 ) ;
}
static void F_181 ( struct V_4 * V_5 , int V_132 )
{
if ( V_132 > 0 &&
! ( V_5 -> V_7 % ( V_133 * V_134 * V_132 ) ) )
F_182 ( V_132 ) ;
}
static bool F_183 ( struct V_4 * V_5 )
{
unsigned long V_135 ;
struct V_55 * V_56 ;
struct V_1 * V_2 = F_68 ( V_5 ) ;
F_123 ( V_5 -> V_104 , V_92 ) ;
F_184 ( V_2 ) ;
if ( ! F_2 ( V_5 -> V_49 ) ) {
F_185 ( V_2 ) ;
return false ;
}
F_123 ( V_5 -> V_49 , 0 ) ;
if ( F_16 ( F_3 ( V_5 ) ) ) {
F_185 ( V_2 ) ;
return false ;
}
F_128 ( V_5 ) ;
F_114 ( & V_5 -> V_7 , V_5 -> V_7 + 1 ) ;
F_6 ( V_5 -> V_38 , V_5 -> V_7 , F_7 ( L_44 ) ) ;
F_185 ( V_2 ) ;
F_137 (rsp, rnp) {
F_181 ( V_5 , V_136 ) ;
F_184 ( V_2 ) ;
if ( V_2 -> V_137 == V_2 -> V_3 &&
! V_2 -> V_138 ) {
F_185 ( V_2 ) ;
continue;
}
V_135 = V_2 -> V_137 ;
V_2 -> V_137 = V_2 -> V_3 ;
if ( ! V_135 != ! V_2 -> V_137 ) {
if ( ! V_135 )
F_186 ( V_2 ) ;
else if ( F_187 ( V_2 ) )
V_2 -> V_138 = true ;
else
F_188 ( V_2 ) ;
}
if ( V_2 -> V_138 &&
( ! F_187 ( V_2 ) ||
V_2 -> V_137 ) ) {
V_2 -> V_138 = false ;
F_188 ( V_2 ) ;
}
F_185 ( V_2 ) ;
}
F_189 (rsp, rnp) {
F_181 ( V_5 , V_139 ) ;
F_184 ( V_2 ) ;
V_56 = F_10 ( V_5 -> V_66 ) ;
F_190 ( V_2 ) ;
V_2 -> V_106 = V_2 -> V_137 ;
F_123 ( V_2 -> V_7 , V_5 -> V_7 ) ;
if ( F_16 ( V_2 -> V_6 != V_5 -> V_6 ) )
F_123 ( V_2 -> V_6 , V_5 -> V_6 ) ;
if ( V_2 == V_56 -> V_78 )
( void ) F_177 ( V_5 , V_2 , V_56 ) ;
F_191 ( V_2 ) ;
F_192 ( V_5 -> V_38 , V_2 -> V_7 ,
V_2 -> V_120 , V_2 -> V_121 ,
V_2 -> V_122 , V_2 -> V_106 ) ;
F_185 ( V_2 ) ;
F_193 () ;
F_123 ( V_5 -> V_104 , V_92 ) ;
}
return true ;
}
static bool F_194 ( struct V_4 * V_5 , int * V_140 )
{
struct V_1 * V_2 = F_68 ( V_5 ) ;
* V_140 = F_2 ( V_5 -> V_49 ) ;
if ( * V_140 & V_141 )
return true ;
if ( ! F_2 ( V_2 -> V_106 ) && ! F_195 ( V_2 ) )
return true ;
return false ;
}
static void F_196 ( struct V_4 * V_5 , bool V_142 )
{
bool V_81 = false ;
unsigned long V_82 ;
struct V_1 * V_2 = F_68 ( V_5 ) ;
F_123 ( V_5 -> V_104 , V_92 ) ;
V_5 -> V_100 ++ ;
if ( V_142 ) {
if ( F_197 ( V_5 ) ) {
V_81 = true ;
V_82 = V_92 - V_84 / 4 ;
}
F_198 ( V_5 , F_119 ,
& V_81 , & V_82 ) ;
F_199 ( V_5 , V_81 , V_82 ) ;
} else {
V_81 = true ;
F_198 ( V_5 , F_124 , & V_81 , & V_82 ) ;
}
if ( F_2 ( V_5 -> V_49 ) & V_141 ) {
F_184 ( V_2 ) ;
F_123 ( V_5 -> V_49 ,
F_2 ( V_5 -> V_49 ) & ~ V_141 ) ;
F_185 ( V_2 ) ;
}
}
static void F_200 ( struct V_4 * V_5 )
{
unsigned long V_143 ;
bool V_144 = false ;
int V_145 = 0 ;
struct V_55 * V_56 ;
struct V_1 * V_2 = F_68 ( V_5 ) ;
struct V_146 * V_147 ;
F_123 ( V_5 -> V_104 , V_92 ) ;
F_184 ( V_2 ) ;
V_143 = V_92 - V_5 -> V_93 ;
if ( V_143 > V_5 -> V_148 )
V_5 -> V_148 = V_143 ;
F_185 ( V_2 ) ;
F_189 (rsp, rnp) {
F_184 ( V_2 ) ;
F_16 ( F_195 ( V_2 ) ) ;
F_16 ( V_2 -> V_106 ) ;
F_123 ( V_2 -> V_6 , V_5 -> V_7 ) ;
V_56 = F_10 ( V_5 -> V_66 ) ;
if ( V_2 == V_56 -> V_78 )
V_144 = F_177 ( V_5 , V_2 , V_56 ) || V_144 ;
V_145 += F_170 ( V_5 , V_2 ) ;
V_147 = F_201 ( V_2 ) ;
F_185 ( V_2 ) ;
F_202 ( V_147 ) ;
F_193 () ;
F_123 ( V_5 -> V_104 , V_92 ) ;
F_181 ( V_5 , V_149 ) ;
}
V_2 = F_68 ( V_5 ) ;
F_184 ( V_2 ) ;
F_203 ( V_2 , V_145 ) ;
F_123 ( V_5 -> V_6 , V_5 -> V_7 ) ;
F_6 ( V_5 -> V_38 , V_5 -> V_6 , F_7 ( L_45 ) ) ;
V_5 -> V_39 = V_150 ;
V_56 = F_10 ( V_5 -> V_66 ) ;
V_144 = F_175 ( V_5 , V_2 , V_56 ) || V_144 ;
if ( V_144 || F_70 ( V_5 , V_56 ) ) {
F_123 ( V_5 -> V_49 , V_151 ) ;
F_6 ( V_5 -> V_38 ,
F_2 ( V_5 -> V_7 ) ,
F_7 ( L_46 ) ) ;
}
F_185 ( V_2 ) ;
}
static int T_3 F_204 ( void * V_152 )
{
bool V_153 ;
int V_154 ;
unsigned long V_97 ;
int V_76 ;
struct V_4 * V_5 = V_152 ;
struct V_1 * V_2 = F_68 ( V_5 ) ;
F_205 () ;
for (; ; ) {
for (; ; ) {
F_6 ( V_5 -> V_38 ,
F_2 ( V_5 -> V_7 ) ,
F_7 ( L_47 ) ) ;
V_5 -> V_39 = V_155 ;
F_206 ( V_5 -> V_127 ,
F_2 ( V_5 -> V_49 ) &
V_151 ) ;
V_5 -> V_39 = V_156 ;
if ( F_183 ( V_5 ) )
break;
F_193 () ;
F_123 ( V_5 -> V_104 , V_92 ) ;
F_207 ( F_208 ( V_33 ) ) ;
F_6 ( V_5 -> V_38 ,
F_2 ( V_5 -> V_7 ) ,
F_7 ( L_48 ) ) ;
}
V_153 = true ;
V_97 = V_157 ;
if ( V_97 > V_105 ) {
V_97 = V_105 ;
V_157 = V_105 ;
}
V_76 = 0 ;
for (; ; ) {
if ( ! V_76 ) {
V_5 -> V_158 = V_92 + V_97 ;
F_123 ( V_5 -> V_108 ,
V_92 + 3 * V_97 ) ;
}
F_6 ( V_5 -> V_38 ,
F_2 ( V_5 -> V_7 ) ,
F_7 ( L_49 ) ) ;
V_5 -> V_39 = V_159 ;
V_76 = F_209 ( V_5 -> V_127 ,
F_194 ( V_5 , & V_154 ) , V_97 ) ;
V_5 -> V_39 = V_160 ;
if ( ! F_2 ( V_2 -> V_106 ) &&
! F_195 ( V_2 ) )
break;
if ( F_157 ( V_92 , V_5 -> V_158 ) ||
( V_154 & V_141 ) ) {
F_6 ( V_5 -> V_38 ,
F_2 ( V_5 -> V_7 ) ,
F_7 ( L_50 ) ) ;
F_196 ( V_5 , V_153 ) ;
V_153 = false ;
F_6 ( V_5 -> V_38 ,
F_2 ( V_5 -> V_7 ) ,
F_7 ( L_51 ) ) ;
F_193 () ;
F_123 ( V_5 -> V_104 , V_92 ) ;
V_76 = 0 ;
V_97 = V_116 ;
if ( V_97 > V_105 ) {
V_97 = V_105 ;
V_116 = V_105 ;
} else if ( V_97 < 1 ) {
V_97 = 1 ;
V_116 = 1 ;
}
} else {
F_193 () ;
F_123 ( V_5 -> V_104 , V_92 ) ;
F_207 ( F_208 ( V_33 ) ) ;
F_6 ( V_5 -> V_38 ,
F_2 ( V_5 -> V_7 ) ,
F_7 ( L_52 ) ) ;
V_76 = 1 ;
V_97 = V_92 ;
if ( F_126 ( V_92 , V_5 -> V_158 ) )
V_97 = 1 ;
else
V_97 = V_5 -> V_158 - V_97 ;
}
}
V_5 -> V_39 = V_161 ;
F_200 ( V_5 ) ;
V_5 -> V_39 = V_162 ;
}
}
static bool
F_168 ( struct V_4 * V_5 , struct V_1 * V_2 ,
struct V_55 * V_56 )
{
if ( ! V_5 -> V_40 || ! F_70 ( V_5 , V_56 ) ) {
return false ;
}
F_123 ( V_5 -> V_49 , V_151 ) ;
F_6 ( V_5 -> V_38 , F_2 ( V_5 -> V_7 ) ,
F_7 ( L_46 ) ) ;
return true ;
}
static bool F_210 ( struct V_4 * V_5 )
{
struct V_55 * V_56 = F_10 ( V_5 -> V_66 ) ;
struct V_1 * V_2 = F_68 ( V_5 ) ;
bool V_76 = false ;
V_76 = F_175 ( V_5 , V_2 , V_56 ) || V_76 ;
V_76 = F_168 ( V_5 , V_2 , V_56 ) || V_76 ;
return V_76 ;
}
static void F_211 ( struct V_4 * V_5 , unsigned long V_34 )
__releases( rcu_get_root( V_5 )->lock
static void
F_212 ( unsigned long V_163 , struct V_4 * V_5 ,
struct V_1 * V_2 , unsigned long V_117 , unsigned long V_34 )
__releases( V_2 -> V_164 )
{
unsigned long V_135 = 0 ;
struct V_1 * V_165 ;
for (; ; ) {
if ( ! ( V_2 -> V_106 & V_163 ) || V_2 -> V_7 != V_117 ) {
F_143 ( V_2 , V_34 ) ;
return;
}
F_16 ( V_135 ) ;
V_2 -> V_106 &= ~ V_163 ;
F_213 ( V_5 -> V_38 , V_2 -> V_7 ,
V_163 , V_2 -> V_106 , V_2 -> V_120 ,
V_2 -> V_121 , V_2 -> V_122 ,
! ! V_2 -> V_166 ) ;
if ( V_2 -> V_106 != 0 || F_195 ( V_2 ) ) {
F_143 ( V_2 , V_34 ) ;
return;
}
V_163 = V_2 -> V_79 ;
if ( V_2 -> V_167 == NULL ) {
break;
}
F_143 ( V_2 , V_34 ) ;
V_165 = V_2 ;
V_2 = V_2 -> V_167 ;
F_138 ( V_2 , V_34 ) ;
V_135 = V_165 -> V_106 ;
}
F_211 ( V_5 , V_34 ) ;
}
static void F_214 ( struct V_4 * V_5 ,
struct V_1 * V_2 , unsigned long V_34 )
__releases( V_2 -> V_164 )
{
unsigned long V_117 ;
unsigned long V_163 ;
struct V_1 * V_168 ;
if ( V_35 == & V_13 || V_5 != V_35 ||
V_2 -> V_106 != 0 || F_195 ( V_2 ) ) {
F_143 ( V_2 , V_34 ) ;
return;
}
V_168 = V_2 -> V_167 ;
if ( V_168 == NULL ) {
F_211 ( V_5 , V_34 ) ;
return;
}
V_117 = V_2 -> V_7 ;
V_163 = V_2 -> V_79 ;
F_169 ( V_2 ) ;
F_165 ( V_168 ) ;
F_212 ( V_163 , V_5 , V_168 , V_117 , V_34 ) ;
}
static void
F_215 ( int V_25 , struct V_4 * V_5 , struct V_55 * V_56 )
{
unsigned long V_34 ;
unsigned long V_163 ;
bool V_131 ;
struct V_1 * V_2 ;
V_2 = V_56 -> V_78 ;
F_138 ( V_2 , V_34 ) ;
if ( V_56 -> V_9 . V_11 . V_12 || V_56 -> V_7 != V_2 -> V_7 ||
V_2 -> V_6 == V_2 -> V_7 || V_56 -> V_85 ) {
V_56 -> V_9 . V_11 . V_12 = true ;
V_56 -> V_94 = F_5 ( V_16 . V_32 ) ;
F_143 ( V_2 , V_34 ) ;
return;
}
V_163 = V_56 -> V_79 ;
if ( ( V_2 -> V_106 & V_163 ) == 0 ) {
F_143 ( V_2 , V_34 ) ;
} else {
V_56 -> V_130 = false ;
V_131 = F_173 ( V_5 , V_2 , V_56 ) ;
F_212 ( V_163 , V_5 , V_2 , V_2 -> V_7 , V_34 ) ;
if ( V_131 )
F_171 ( V_5 ) ;
}
}
static void
F_216 ( struct V_4 * V_5 , struct V_55 * V_56 )
{
F_179 ( V_5 , V_56 ) ;
if ( ! V_56 -> V_130 )
return;
if ( V_56 -> V_9 . V_11 . V_12 )
return;
F_215 ( V_56 -> V_25 , V_5 , V_56 ) ;
}
static void
F_217 ( int V_25 , struct V_4 * V_5 ,
struct V_1 * V_2 , struct V_55 * V_56 )
{
if ( ! F_17 ( V_169 ) || F_166 ( V_56 -> V_25 ) )
return;
V_56 -> V_170 += F_153 ( & V_56 -> V_57 ) ;
F_218 ( & V_56 -> V_57 , & V_5 -> V_171 ) ;
F_219 ( & V_56 -> V_57 , & V_5 -> V_172 ) ;
F_220 ( & V_56 -> V_57 , & V_5 -> V_171 ) ;
F_221 ( & V_56 -> V_57 ) ;
}
static void F_222 ( struct V_4 * V_5 , unsigned long V_34 )
{
struct V_55 * V_56 = F_223 ( V_5 -> V_66 ) ;
if ( ! F_17 ( V_169 ) ||
F_224 ( V_5 , V_56 , V_34 ) )
return;
V_56 -> V_173 += V_5 -> V_171 . V_174 ;
if ( V_5 -> V_171 . V_175 != V_5 -> V_171 . V_174 )
F_225 () ;
F_226 ( & V_56 -> V_57 , & V_5 -> V_171 ) ;
F_227 ( & V_56 -> V_57 , & V_5 -> V_171 ) ;
F_16 ( V_5 -> V_171 . V_176 ) ;
F_228 ( & V_56 -> V_57 , & V_5 -> V_172 ) ;
F_16 ( V_5 -> V_172 . V_176 ) ;
F_16 ( F_229 ( & V_56 -> V_57 ) !=
! F_153 ( & V_56 -> V_57 ) ) ;
}
static void F_230 ( struct V_4 * V_5 )
{
F_96 (unsigned long mask;)
F_96 (struct rcu_data *rdp = this_cpu_ptr(rsp->rda);)
F_96 (struct rcu_node *rnp = rdp->mynode;)
if ( ! F_17 ( V_169 ) )
return;
F_96 (mask = rdp->grpmask;)
F_6 ( V_5 -> V_38 ,
V_2 -> V_7 + 1 - ! ! ( V_2 -> V_106 & V_163 ) ,
F_7 ( L_53 ) ) ;
}
static void F_188 ( struct V_1 * V_177 )
{
long V_163 ;
struct V_1 * V_2 = V_177 ;
if ( ! F_17 ( V_169 ) ||
V_2 -> V_137 || F_187 ( V_2 ) )
return;
for (; ; ) {
V_163 = V_2 -> V_79 ;
V_2 = V_2 -> V_167 ;
if ( ! V_2 )
break;
F_165 ( V_2 ) ;
V_2 -> V_137 &= ~ V_163 ;
V_2 -> V_106 &= ~ V_163 ;
if ( V_2 -> V_137 ) {
F_169 ( V_2 ) ;
return;
}
F_169 ( V_2 ) ;
}
}
static void F_231 ( int V_25 , struct V_4 * V_5 )
{
unsigned long V_34 ;
struct V_55 * V_56 = F_115 ( V_5 -> V_66 , V_25 ) ;
struct V_1 * V_2 = V_56 -> V_78 ;
if ( ! F_17 ( V_169 ) )
return;
F_232 ( V_2 , - 1 ) ;
F_233 ( & V_5 -> V_178 , V_34 ) ;
F_217 ( V_25 , V_5 , V_2 , V_56 ) ;
F_222 ( V_5 , V_34 ) ;
F_234 ( & V_5 -> V_178 , V_34 ) ;
F_80 ( F_153 ( & V_56 -> V_57 ) != 0 ||
! F_229 ( & V_56 -> V_57 ) ,
L_54 ,
V_25 , F_153 ( & V_56 -> V_57 ) ,
F_235 ( & V_56 -> V_57 ) ) ;
}
static void F_236 ( struct V_4 * V_5 , struct V_55 * V_56 )
{
unsigned long V_34 ;
struct V_179 * V_180 ;
struct V_181 V_182 = F_237 ( V_182 ) ;
long V_183 , V_184 ;
if ( ! F_238 ( & V_56 -> V_57 ) ) {
F_239 ( V_5 -> V_38 ,
F_240 ( & V_56 -> V_57 ) ,
F_153 ( & V_56 -> V_57 ) , 0 ) ;
F_241 ( V_5 -> V_38 , 0 ,
! F_229 ( & V_56 -> V_57 ) ,
F_242 () , F_76 ( V_33 ) ,
F_243 () ) ;
return;
}
F_48 ( V_34 ) ;
F_16 ( F_244 ( F_78 () ) ) ;
V_183 = V_56 -> V_185 ;
F_239 ( V_5 -> V_38 , F_240 ( & V_56 -> V_57 ) ,
F_153 ( & V_56 -> V_57 ) , V_183 ) ;
F_220 ( & V_56 -> V_57 , & V_182 ) ;
F_49 ( V_34 ) ;
V_180 = F_245 ( & V_182 ) ;
for (; V_180 ; V_180 = F_245 ( & V_182 ) ) {
F_246 ( V_180 ) ;
if ( F_247 ( V_5 -> V_38 , V_180 ) )
F_248 ( & V_182 ) ;
if ( - V_182 . V_174 >= V_183 &&
( F_242 () ||
( ! F_76 ( V_33 ) && ! F_243 () ) ) )
break;
}
F_48 ( V_34 ) ;
V_184 = - V_182 . V_174 ;
F_241 ( V_5 -> V_38 , V_184 , ! ! V_182 . V_176 , F_242 () ,
F_76 ( V_33 ) , F_243 () ) ;
F_227 ( & V_56 -> V_57 , & V_182 ) ;
F_249 () ;
V_56 -> V_186 += V_184 ;
F_226 ( & V_56 -> V_57 , & V_182 ) ;
V_184 = F_153 ( & V_56 -> V_57 ) ;
if ( V_56 -> V_185 == V_187 && V_184 <= V_188 )
V_56 -> V_185 = V_185 ;
if ( V_184 == 0 && V_56 -> V_189 != 0 ) {
V_56 -> V_189 = 0 ;
V_56 -> V_190 = V_5 -> V_100 ;
} else if ( V_184 < V_56 -> V_189 - V_191 )
V_56 -> V_189 = V_184 ;
F_16 ( F_229 ( & V_56 -> V_57 ) != ( V_184 == 0 ) ) ;
F_49 ( V_34 ) ;
if ( F_238 ( & V_56 -> V_57 ) )
F_250 () ;
}
void F_251 ( int V_59 )
{
F_37 ( F_7 ( L_55 ) ) ;
F_252 () ;
if ( V_59 || F_118 () ) {
F_4 () ;
F_11 () ;
} else if ( ! F_253 () ) {
F_11 () ;
}
F_254 () ;
if ( F_255 () )
F_250 () ;
if ( V_59 )
F_256 ( V_33 ) ;
F_37 ( F_7 ( L_56 ) ) ;
}
static void F_198 ( struct V_4 * V_5 ,
int (* F_257)( struct V_55 * V_5 , bool * V_81 ,
unsigned long * V_82 ) ,
bool * V_81 , unsigned long * V_82 )
{
int V_25 ;
unsigned long V_34 ;
unsigned long V_163 ;
struct V_1 * V_2 ;
F_137 (rsp, rnp) {
F_193 () ;
V_163 = 0 ;
F_138 ( V_2 , V_34 ) ;
if ( V_2 -> V_106 == 0 ) {
if ( V_35 == & V_13 ||
V_5 != V_35 ||
F_195 ( V_2 ) ) {
F_258 ( V_2 , V_34 ) ;
continue;
}
if ( V_2 -> V_167 &&
( V_2 -> V_167 -> V_106 & V_2 -> V_79 ) ) {
F_214 ( V_5 , V_2 , V_34 ) ;
continue;
}
}
F_139 (rnp, cpu) {
unsigned long V_192 = F_140 ( V_2 , V_25 ) ;
if ( ( V_2 -> V_106 & V_192 ) != 0 ) {
if ( F_257 ( F_115 ( V_5 -> V_66 , V_25 ) , V_81 , V_82 ) )
V_163 |= V_192 ;
}
}
if ( V_163 != 0 ) {
F_212 ( V_163 , V_5 , V_2 , V_2 -> V_7 , V_34 ) ;
} else {
F_143 ( V_2 , V_34 ) ;
}
}
}
static void F_59 ( struct V_4 * V_5 )
{
unsigned long V_34 ;
bool V_76 ;
struct V_1 * V_2 ;
struct V_1 * V_193 = NULL ;
V_2 = F_5 ( V_5 -> V_66 -> V_78 ) ;
for (; V_2 != NULL ; V_2 = V_2 -> V_167 ) {
V_76 = ( F_2 ( V_5 -> V_49 ) & V_141 ) ||
! F_259 ( & V_2 -> V_194 ) ;
if ( V_193 != NULL )
F_260 ( & V_193 -> V_194 ) ;
if ( V_76 ) {
V_5 -> V_195 ++ ;
return;
}
V_193 = V_2 ;
}
F_138 ( V_193 , V_34 ) ;
F_260 ( & V_193 -> V_194 ) ;
if ( F_2 ( V_5 -> V_49 ) & V_141 ) {
V_5 -> V_195 ++ ;
F_143 ( V_193 , V_34 ) ;
return;
}
F_123 ( V_5 -> V_49 , F_2 ( V_5 -> V_49 ) | V_141 ) ;
F_143 ( V_193 , V_34 ) ;
F_171 ( V_5 ) ;
}
static void
F_261 ( struct V_4 * V_5 )
{
unsigned long V_34 ;
bool V_131 ;
struct V_55 * V_56 = F_223 ( V_5 -> V_66 ) ;
F_16 ( ! V_56 -> V_196 ) ;
F_216 ( V_5 , V_56 ) ;
F_48 ( V_34 ) ;
if ( F_70 ( V_5 , V_56 ) ) {
F_165 ( F_68 ( V_5 ) ) ;
V_131 = F_210 ( V_5 ) ;
F_143 ( F_68 ( V_5 ) , V_34 ) ;
if ( V_131 )
F_171 ( V_5 ) ;
} else {
F_49 ( V_34 ) ;
}
if ( F_238 ( & V_56 -> V_57 ) )
F_262 ( V_5 , V_56 ) ;
F_81 ( V_56 ) ;
}
static T_4 void F_263 ( struct V_197 * V_198 )
{
struct V_4 * V_5 ;
if ( F_244 ( F_78 () ) )
return;
F_37 ( F_7 ( L_57 ) ) ;
F_63 (rsp)
F_261 ( V_5 ) ;
F_37 ( F_7 ( L_58 ) ) ;
}
static void F_262 ( struct V_4 * V_5 , struct V_55 * V_56 )
{
if ( F_41 ( ! F_2 ( V_80 ) ) )
return;
if ( F_264 ( ! V_5 -> V_199 ) ) {
F_236 ( V_5 , V_56 ) ;
return;
}
F_265 () ;
}
static void F_250 ( void )
{
if ( F_266 ( F_78 () ) )
F_267 ( V_200 ) ;
}
static void F_268 ( struct V_4 * V_5 , struct V_55 * V_56 ,
struct V_179 * V_176 , unsigned long V_34 )
{
bool V_131 ;
if ( ! F_108 () )
F_250 () ;
if ( F_269 ( V_34 ) || F_244 ( F_78 () ) )
return;
if ( F_41 ( F_153 ( & V_56 -> V_57 ) >
V_56 -> V_189 + V_191 ) ) {
F_179 ( V_5 , V_56 ) ;
if ( ! F_3 ( V_5 ) ) {
struct V_1 * V_124 = F_68 ( V_5 ) ;
F_165 ( V_124 ) ;
V_131 = F_210 ( V_5 ) ;
F_169 ( V_124 ) ;
if ( V_131 )
F_171 ( V_5 ) ;
} else {
V_56 -> V_185 = V_187 ;
if ( V_5 -> V_100 == V_56 -> V_190 &&
F_270 ( & V_56 -> V_57 ) != V_176 )
F_59 ( V_5 ) ;
V_56 -> V_190 = V_5 -> V_100 ;
V_56 -> V_189 = F_153 ( & V_56 -> V_57 ) ;
}
}
}
static void F_271 ( struct V_179 * V_180 )
{
}
static void
F_272 ( struct V_179 * V_176 , T_5 V_201 ,
struct V_4 * V_5 , int V_25 , bool V_202 )
{
unsigned long V_34 ;
struct V_55 * V_56 ;
F_16 ( ( unsigned long ) V_176 & ( sizeof( void * ) - 1 ) ) ;
if ( F_273 ( V_176 ) ) {
F_123 ( V_176 -> V_201 , F_271 ) ;
F_80 ( 1 , L_59 ) ;
return;
}
V_176 -> V_201 = V_201 ;
V_176 -> V_203 = NULL ;
F_48 ( V_34 ) ;
V_56 = F_10 ( V_5 -> V_66 ) ;
if ( F_41 ( ! F_71 ( & V_56 -> V_57 ) ) || V_25 != - 1 ) {
int V_204 ;
if ( V_25 != - 1 )
V_56 = F_115 ( V_5 -> V_66 , V_25 ) ;
if ( F_264 ( V_56 -> V_78 ) ) {
V_204 = ! F_274 ( V_56 , V_176 , V_202 , V_34 ) ;
F_16 ( V_204 ) ;
F_49 ( V_34 ) ;
return;
}
F_275 ( V_25 != - 1 ) ;
F_16 ( ! F_108 () ) ;
if ( F_229 ( & V_56 -> V_57 ) )
F_276 ( & V_56 -> V_57 ) ;
}
F_277 ( & V_56 -> V_57 , V_176 , V_202 ) ;
if ( ! V_202 )
F_225 () ;
if ( F_278 ( ( unsigned long ) V_201 ) )
F_279 ( V_5 -> V_38 , V_176 , ( unsigned long ) V_201 ,
F_240 ( & V_56 -> V_57 ) ,
F_153 ( & V_56 -> V_57 ) ) ;
else
F_280 ( V_5 -> V_38 , V_176 ,
F_240 ( & V_56 -> V_57 ) ,
F_153 ( & V_56 -> V_57 ) ) ;
F_268 ( V_5 , V_56 , V_176 , V_34 ) ;
F_49 ( V_34 ) ;
}
void F_281 ( struct V_179 * V_176 , T_5 V_201 )
{
F_272 ( V_176 , V_201 , & V_13 , - 1 , 0 ) ;
}
void F_282 ( struct V_179 * V_176 , T_5 V_201 )
{
F_272 ( V_176 , V_201 , & V_36 , - 1 , 0 ) ;
}
void F_283 ( struct V_179 * V_176 ,
T_5 V_201 )
{
F_272 ( V_176 , V_201 , V_35 , - 1 , 1 ) ;
}
static inline int F_284 ( void )
{
int V_76 ;
F_285 () ;
F_46 () ;
V_76 = F_286 () <= 1 ;
F_47 () ;
return V_76 ;
}
void F_287 ( void )
{
F_86 ( F_87 ( & V_68 ) ||
F_87 ( & V_67 ) ||
F_87 ( & V_69 ) ,
L_60 ) ;
if ( F_284 () )
return;
if ( F_288 () )
F_289 () ;
else
F_290 ( F_281 ) ;
}
void F_291 ( void )
{
F_86 ( F_87 ( & V_68 ) ||
F_87 ( & V_67 ) ||
F_87 ( & V_69 ) ,
L_61 ) ;
if ( F_284 () )
return;
if ( F_288 () )
F_292 () ;
else
F_290 ( F_282 ) ;
}
unsigned long F_293 ( void )
{
F_249 () ;
return F_39 ( & V_35 -> V_7 ) ;
}
void F_294 ( unsigned long V_205 )
{
unsigned long V_206 ;
V_206 = F_39 ( & V_35 -> V_6 ) ;
if ( F_157 ( V_205 , V_206 ) )
F_295 () ;
}
unsigned long F_296 ( void )
{
F_249 () ;
return F_39 ( & V_13 . V_7 ) ;
}
void F_297 ( unsigned long V_205 )
{
unsigned long V_206 ;
V_206 = F_39 ( & V_13 . V_6 ) ;
if ( F_157 ( V_205 , V_206 ) )
F_287 () ;
}
static int F_298 ( struct V_4 * V_5 , struct V_55 * V_56 )
{
struct V_1 * V_2 = V_56 -> V_78 ;
V_56 -> V_207 ++ ;
F_158 ( V_5 , V_56 ) ;
if ( F_299 ( V_5 ) )
return 0 ;
if ( V_80 &&
V_56 -> V_130 && V_56 -> V_9 . V_11 . V_12 &&
V_56 -> V_94 == F_5 ( V_16 . V_32 ) ) {
V_56 -> V_208 ++ ;
} else if ( V_56 -> V_130 && ! V_56 -> V_9 . V_11 . V_12 ) {
V_56 -> V_209 ++ ;
return 1 ;
}
if ( F_238 ( & V_56 -> V_57 ) ) {
V_56 -> V_210 ++ ;
return 1 ;
}
if ( F_70 ( V_5 , V_56 ) ) {
V_56 -> V_211 ++ ;
return 1 ;
}
if ( F_2 ( V_2 -> V_6 ) != V_56 -> V_6 ) {
V_56 -> V_212 ++ ;
return 1 ;
}
if ( F_2 ( V_2 -> V_7 ) != V_56 -> V_7 ||
F_41 ( F_2 ( V_56 -> V_85 ) ) ) {
V_56 -> V_213 ++ ;
return 1 ;
}
if ( F_300 ( V_56 ) ) {
V_56 -> V_214 ++ ;
return 1 ;
}
V_56 -> V_215 ++ ;
return 0 ;
}
static int F_255 ( void )
{
struct V_4 * V_5 ;
F_63 (rsp)
if ( F_298 ( V_5 , F_10 ( V_5 -> V_66 ) ) )
return 1 ;
return 0 ;
}
static bool V_62 F_301 ( bool * V_216 )
{
bool V_217 = true ;
bool V_218 = false ;
struct V_55 * V_56 ;
struct V_4 * V_5 ;
F_63 (rsp) {
V_56 = F_10 ( V_5 -> V_66 ) ;
if ( F_229 ( & V_56 -> V_57 ) )
continue;
V_218 = true ;
if ( F_302 ( & V_56 -> V_57 ) || ! V_216 ) {
V_217 = false ;
break;
}
}
if ( V_216 )
* V_216 = V_217 ;
return V_218 ;
}
static void F_303 ( struct V_4 * V_5 , const char * V_10 ,
int V_25 , unsigned long V_219 )
{
F_304 ( V_5 -> V_38 , V_10 , V_25 ,
F_23 ( & V_5 -> V_220 ) , V_219 ) ;
}
static void F_305 ( struct V_179 * V_180 )
{
struct V_55 * V_56 = F_306 ( V_180 , struct V_55 , V_221 ) ;
struct V_4 * V_5 = V_56 -> V_5 ;
if ( F_307 ( & V_5 -> V_220 ) ) {
F_303 ( V_5 , L_62 , - 1 , V_5 -> V_222 ) ;
F_308 ( & V_5 -> V_223 ) ;
} else {
F_303 ( V_5 , L_63 , - 1 , V_5 -> V_222 ) ;
}
}
static void F_309 ( void * type )
{
struct V_4 * V_5 = type ;
struct V_55 * V_56 = F_223 ( V_5 -> V_66 ) ;
F_303 ( V_5 , L_64 , - 1 , V_5 -> V_222 ) ;
F_310 ( & V_5 -> V_220 ) ;
V_5 -> V_224 ( & V_56 -> V_221 , F_305 ) ;
}
static void F_311 ( struct V_4 * V_5 )
{
int V_25 ;
struct V_55 * V_56 ;
unsigned long V_10 = F_312 ( & V_5 -> V_222 ) ;
F_303 ( V_5 , L_65 , - 1 , V_10 ) ;
F_313 ( & V_5 -> V_225 ) ;
if ( F_314 ( & V_5 -> V_222 , V_10 ) ) {
F_303 ( V_5 , L_66 , - 1 , V_5 -> V_222 ) ;
F_249 () ;
F_315 ( & V_5 -> V_225 ) ;
return;
}
F_316 ( & V_5 -> V_222 ) ;
F_303 ( V_5 , L_67 , - 1 , V_5 -> V_222 ) ;
F_317 ( & V_5 -> V_223 ) ;
F_318 ( & V_5 -> V_220 , 1 ) ;
F_319 () ;
F_152 (cpu) {
if ( ! F_266 ( V_25 ) && ! F_166 ( V_25 ) )
continue;
V_56 = F_115 ( V_5 -> V_66 , V_25 ) ;
if ( F_166 ( V_25 ) ) {
if ( ! F_320 ( V_5 , V_25 ) ) {
F_303 ( V_5 , L_68 , V_25 ,
V_5 -> V_222 ) ;
} else {
F_303 ( V_5 , L_69 , V_25 ,
V_5 -> V_222 ) ;
F_321 () ;
F_310 ( & V_5 -> V_220 ) ;
F_272 ( & V_56 -> V_221 ,
F_305 , V_5 , V_25 , 0 ) ;
}
} else if ( F_153 ( & V_56 -> V_57 ) ) {
F_303 ( V_5 , L_70 , V_25 ,
V_5 -> V_222 ) ;
F_322 ( V_25 , F_309 , V_5 , 1 ) ;
} else {
F_303 ( V_5 , L_71 , V_25 ,
V_5 -> V_222 ) ;
}
}
F_323 () ;
if ( F_307 ( & V_5 -> V_220 ) )
F_308 ( & V_5 -> V_223 ) ;
F_324 ( & V_5 -> V_223 ) ;
F_303 ( V_5 , L_72 , - 1 , V_5 -> V_222 ) ;
F_325 ( & V_5 -> V_222 ) ;
F_315 ( & V_5 -> V_225 ) ;
}
void F_326 ( void )
{
F_311 ( & V_36 ) ;
}
void F_327 ( void )
{
F_311 ( & V_13 ) ;
}
static void F_186 ( struct V_1 * V_177 )
{
long V_163 ;
struct V_1 * V_2 = V_177 ;
for (; ; ) {
V_163 = V_2 -> V_79 ;
V_2 = V_2 -> V_167 ;
if ( V_2 == NULL )
return;
F_165 ( V_2 ) ;
V_2 -> V_137 |= V_163 ;
F_169 ( V_2 ) ;
}
}
static void T_6
F_328 ( int V_25 , struct V_4 * V_5 )
{
unsigned long V_34 ;
struct V_55 * V_56 = F_115 ( V_5 -> V_66 , V_25 ) ;
struct V_1 * V_2 = F_68 ( V_5 ) ;
F_138 ( V_2 , V_34 ) ;
V_56 -> V_79 = F_140 ( V_56 -> V_78 , V_25 ) ;
V_56 -> V_20 = & F_31 ( V_16 , V_25 ) ;
F_16 ( V_56 -> V_20 -> V_60 != V_73 ) ;
F_16 ( F_27 ( F_26 ( V_56 -> V_20 ) ) ) ;
V_56 -> V_25 = V_25 ;
V_56 -> V_5 = V_5 ;
F_329 ( V_56 ) ;
F_143 ( V_2 , V_34 ) ;
}
static void
F_330 ( int V_25 , struct V_4 * V_5 )
{
unsigned long V_34 ;
struct V_55 * V_56 = F_115 ( V_5 -> V_66 , V_25 ) ;
struct V_1 * V_2 = F_68 ( V_5 ) ;
F_138 ( V_2 , V_34 ) ;
V_56 -> V_189 = 0 ;
V_56 -> V_190 = V_5 -> V_100 ;
V_56 -> V_185 = V_185 ;
if ( F_229 ( & V_56 -> V_57 ) &&
! F_331 ( V_56 ) )
F_276 ( & V_56 -> V_57 ) ;
V_56 -> V_20 -> V_60 = V_73 ;
F_332 ( V_56 -> V_20 ) ;
F_22 () ;
F_169 ( V_2 ) ;
V_2 = V_56 -> V_78 ;
F_165 ( V_2 ) ;
if ( ! V_56 -> V_196 )
F_123 ( V_5 -> V_226 , F_2 ( V_5 -> V_226 ) + 1 ) ;
V_56 -> V_196 = true ;
V_56 -> V_7 = V_2 -> V_6 ;
V_56 -> V_6 = V_2 -> V_6 ;
V_56 -> V_9 . V_11 . V_12 = true ;
V_56 -> V_94 = F_31 ( V_16 . V_32 , V_25 ) ;
V_56 -> V_130 = false ;
F_6 ( V_5 -> V_38 , V_56 -> V_7 , F_7 ( L_73 ) ) ;
F_143 ( V_2 , V_34 ) ;
}
int F_333 ( unsigned int V_25 )
{
struct V_4 * V_5 ;
F_63 (rsp)
F_330 ( V_25 , V_5 ) ;
F_334 ( V_25 ) ;
F_335 ( V_25 ) ;
return 0 ;
}
static void F_336 ( unsigned int V_25 , int V_227 )
{
struct V_55 * V_56 = F_115 ( V_35 -> V_66 , V_25 ) ;
F_232 ( V_56 -> V_78 , V_227 ) ;
}
int F_337 ( unsigned int V_25 )
{
F_338 ( V_25 ) ;
F_336 ( V_25 , - 1 ) ;
if ( F_17 ( V_228 ) )
F_339 ( V_25 ) ;
return 0 ;
}
int F_340 ( unsigned int V_25 )
{
F_336 ( V_25 , V_25 ) ;
if ( F_17 ( V_228 ) )
F_341 ( V_25 ) ;
return 0 ;
}
int F_342 ( unsigned int V_25 )
{
struct V_4 * V_5 ;
F_63 (rsp)
F_230 ( V_5 ) ;
return 0 ;
}
int F_343 ( unsigned int V_25 )
{
struct V_4 * V_5 ;
F_63 (rsp) {
F_231 ( V_25 , V_5 ) ;
F_81 ( F_115 ( V_5 -> V_66 , V_25 ) ) ;
}
return 0 ;
}
void F_344 ( unsigned int V_25 )
{
unsigned long V_34 ;
unsigned long V_163 ;
struct V_55 * V_56 ;
struct V_1 * V_2 ;
struct V_4 * V_5 ;
F_63 (rsp) {
V_56 = F_115 ( V_5 -> V_66 , V_25 ) ;
V_2 = V_56 -> V_78 ;
V_163 = V_56 -> V_79 ;
F_138 ( V_2 , V_34 ) ;
V_2 -> V_3 |= V_163 ;
V_2 -> V_229 |= V_163 ;
F_143 ( V_2 , V_34 ) ;
}
}
static void F_345 ( int V_25 , struct V_4 * V_5 )
{
unsigned long V_34 ;
unsigned long V_163 ;
struct V_55 * V_56 = F_115 ( V_5 -> V_66 , V_25 ) ;
struct V_1 * V_2 = V_56 -> V_78 ;
V_163 = V_56 -> V_79 ;
F_138 ( V_2 , V_34 ) ;
V_2 -> V_3 &= ~ V_163 ;
F_143 ( V_2 , V_34 ) ;
}
void F_346 ( unsigned int V_25 )
{
struct V_4 * V_5 ;
F_46 () ;
F_9 ( & V_13 ,
F_10 ( V_13 . V_66 ) , true ) ;
F_47 () ;
F_63 (rsp)
F_345 ( V_25 , V_5 ) ;
}
static int F_347 ( struct V_230 * V_231 ,
unsigned long V_232 , void * V_233 )
{
switch ( V_232 ) {
case V_234 :
case V_235 :
if ( V_236 <= 256 )
F_348 () ;
break;
case V_237 :
case V_238 :
if ( V_236 <= 256 )
F_349 () ;
break;
default:
break;
}
return V_239 ;
}
static int T_6 F_350 ( void )
{
unsigned long V_34 ;
int V_240 = V_241 ;
struct V_1 * V_2 ;
struct V_4 * V_5 ;
struct V_242 V_243 ;
struct V_61 * V_77 ;
if ( F_17 ( V_244 ) && V_241 < 1 )
V_241 = 1 ;
else if ( V_241 < 0 )
V_241 = 0 ;
else if ( V_241 > 99 )
V_241 = 99 ;
if ( V_241 != V_240 )
F_351 ( L_74 ,
V_241 , V_240 ) ;
V_80 = 1 ;
F_63 (rsp) {
V_77 = F_352 ( F_204 , V_5 , L_75 , V_5 -> V_38 ) ;
F_275 ( F_353 ( V_77 ) ) ;
V_2 = F_68 ( V_5 ) ;
F_138 ( V_2 , V_34 ) ;
V_5 -> V_40 = V_77 ;
if ( V_241 ) {
V_243 . V_245 = V_241 ;
F_354 ( V_77 , V_246 , & V_243 ) ;
}
F_143 ( V_2 , V_34 ) ;
F_135 ( V_77 ) ;
}
F_355 () ;
F_356 () ;
return 0 ;
}
void F_357 ( void )
{
F_207 ( F_286 () != 1 ) ;
F_207 ( F_358 () > 0 ) ;
F_359 () ;
V_247 = V_248 ;
F_359 () ;
}
static void T_6 F_360 ( struct V_4 * V_5 )
{
static const char * const V_249 [] = V_250 ;
static const char * const V_251 [] = V_252 ;
static struct V_253 V_254 [ V_255 ] ;
static struct V_253 V_256 [ V_255 ] ;
int V_257 [ V_255 ] ;
int V_258 = 1 ;
int V_259 ;
int V_97 ;
struct V_1 * V_2 ;
F_361 ( V_255 > F_131 ( V_249 ) ) ;
if ( V_260 <= 0 || V_260 > V_255 )
F_146 ( L_76 ) ;
for ( V_259 = 1 ; V_259 < V_260 ; V_259 ++ )
V_5 -> V_120 [ V_259 ] = V_5 -> V_120 [ V_259 - 1 ] + V_261 [ V_259 - 1 ] ;
F_362 ( V_257 , V_261 ) ;
for ( V_259 = V_260 - 1 ; V_259 >= 0 ; V_259 -- ) {
V_258 *= V_257 [ V_259 ] ;
V_2 = V_5 -> V_120 [ V_259 ] ;
for ( V_97 = 0 ; V_97 < V_261 [ V_259 ] ; V_97 ++ , V_2 ++ ) {
F_363 ( & F_364 ( V_2 , V_164 ) ) ;
F_365 ( & F_364 ( V_2 , V_164 ) ,
& V_254 [ V_259 ] , V_249 [ V_259 ] ) ;
F_363 ( & V_2 -> V_194 ) ;
F_365 ( & V_2 -> V_194 ,
& V_256 [ V_259 ] , V_251 [ V_259 ] ) ;
V_2 -> V_7 = V_5 -> V_7 ;
V_2 -> V_6 = V_5 -> V_6 ;
V_2 -> V_106 = 0 ;
V_2 -> V_137 = 0 ;
V_2 -> V_121 = V_97 * V_258 ;
V_2 -> V_122 = ( V_97 + 1 ) * V_258 - 1 ;
if ( V_2 -> V_122 >= V_236 )
V_2 -> V_122 = V_236 - 1 ;
if ( V_259 == 0 ) {
V_2 -> V_262 = 0 ;
V_2 -> V_79 = 0 ;
V_2 -> V_167 = NULL ;
} else {
V_2 -> V_262 = V_97 % V_257 [ V_259 - 1 ] ;
V_2 -> V_79 = 1UL << V_2 -> V_262 ;
V_2 -> V_167 = V_5 -> V_120 [ V_259 - 1 ] +
V_97 / V_257 [ V_259 - 1 ] ;
}
V_2 -> V_120 = V_259 ;
F_366 ( & V_2 -> V_263 ) ;
F_367 ( V_2 ) ;
F_368 ( & V_2 -> V_264 [ 0 ] ) ;
F_368 ( & V_2 -> V_264 [ 1 ] ) ;
F_368 ( & V_2 -> V_264 [ 2 ] ) ;
F_368 ( & V_2 -> V_264 [ 3 ] ) ;
F_369 ( & V_2 -> V_265 ) ;
}
}
F_370 ( & V_5 -> V_127 ) ;
F_370 ( & V_5 -> V_266 ) ;
V_2 = V_5 -> V_120 [ V_260 - 1 ] ;
F_152 (i) {
while ( V_259 > V_2 -> V_122 )
V_2 ++ ;
F_115 ( V_5 -> V_66 , V_259 ) -> V_78 = V_2 ;
F_328 ( V_259 , V_5 ) ;
}
F_371 ( & V_5 -> V_267 , & V_268 ) ;
}
static void T_6 F_372 ( void )
{
T_7 V_269 ;
int V_259 ;
int V_270 [ V_255 ] ;
V_269 = V_271 + V_236 / V_272 ;
if ( V_157 == V_84 )
V_157 = V_269 ;
if ( V_116 == V_84 )
V_116 = V_269 ;
if ( V_273 == V_274 &&
V_236 == V_275 )
return;
F_64 ( L_77 ,
V_273 , V_236 ) ;
if ( V_273 < 2 ||
V_273 > sizeof( unsigned long ) * 8 ) {
V_273 = V_274 ;
F_207 ( 1 ) ;
return;
}
V_270 [ 0 ] = V_273 ;
for ( V_259 = 1 ; V_259 < V_255 ; V_259 ++ )
V_270 [ V_259 ] = V_270 [ V_259 - 1 ] * V_276 ;
if ( V_236 > V_270 [ V_255 - 1 ] ) {
V_273 = V_274 ;
F_207 ( 1 ) ;
return;
}
for ( V_259 = 0 ; V_236 > V_270 [ V_259 ] ; V_259 ++ ) {
}
V_260 = V_259 + 1 ;
for ( V_259 = 0 ; V_259 < V_260 ; V_259 ++ ) {
int V_277 = V_270 [ ( V_260 - 1 ) - V_259 ] ;
V_261 [ V_259 ] = F_373 ( V_236 , V_277 ) ;
}
V_133 = 0 ;
for ( V_259 = 0 ; V_259 < V_260 ; V_259 ++ )
V_133 += V_261 [ V_259 ] ;
}
static void T_6 F_374 ( struct V_4 * V_5 )
{
int V_120 = 0 ;
struct V_1 * V_2 ;
F_64 ( L_78 ) ;
F_64 ( L_79 ) ;
F_189 (rsp, rnp) {
if ( V_2 -> V_120 != V_120 ) {
F_154 ( L_80 ) ;
F_64 ( L_79 ) ;
V_120 = V_2 -> V_120 ;
}
F_154 ( L_81 , V_2 -> V_121 , V_2 -> V_122 , V_2 -> V_262 ) ;
}
F_154 ( L_80 ) ;
}
void T_6 F_375 ( void )
{
int V_25 ;
F_376 () ;
F_377 () ;
F_372 () ;
F_360 ( & V_36 ) ;
F_360 ( & V_13 ) ;
if ( V_278 )
F_374 ( & V_13 ) ;
F_378 () ;
F_379 ( V_200 , F_263 ) ;
F_380 ( F_347 , 0 ) ;
F_381 (cpu) {
F_333 ( V_25 ) ;
F_344 ( V_25 ) ;
if ( F_17 ( V_228 ) )
F_339 ( V_25 ) ;
}
}
