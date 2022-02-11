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
static void F_12 ( void )
{
struct V_15 * V_16 = F_10 ( & V_15 ) ;
int V_17 ;
V_17 = F_13 ( & V_16 -> V_18 ) ;
F_14 ( F_15 ( V_19 ) && V_17 & 0x1 ) ;
}
static void F_16 ( void )
{
struct V_15 * V_16 = F_10 ( & V_15 ) ;
int V_17 ;
V_17 = F_13 ( & V_16 -> V_18 ) ;
F_14 ( F_15 ( V_19 ) && ! ( V_17 & 0x1 ) ) ;
}
static void F_17 ( void )
{
struct V_15 * V_16 = F_10 ( & V_15 ) ;
if ( F_18 ( & V_16 -> V_18 ) & 0x1 )
return;
F_19 ( 0x1 , & V_16 -> V_18 ) ;
}
bool F_20 ( void )
{
struct V_15 * V_16 = F_10 ( & V_15 ) ;
return ! ( F_18 ( & V_16 -> V_18 ) & 0x1 ) ;
}
int F_21 ( struct V_15 * V_16 )
{
int V_20 = F_22 ( 0 , & V_16 -> V_18 ) ;
return V_20 ;
}
static bool F_23 ( int V_20 )
{
return ! ( V_20 & 0x1 ) ;
}
static bool F_24 ( struct V_15 * V_16 , int V_20 )
{
return V_20 != F_21 ( V_16 ) ;
}
static void F_25 ( void )
{
struct V_15 * V_16 = F_10 ( & V_15 ) ;
int V_17 = F_22 ( 2 , & V_16 -> V_18 ) ;
F_14 ( ! ( V_17 & 0x1 ) ) ;
}
static void F_26 ( void )
{
struct V_21 * V_22 ;
int V_23 ;
struct V_4 * V_5 ;
V_23 = F_27 ( V_24 ) ;
F_28 ( V_24 , 0 ) ;
F_29 (rsp) {
V_22 = F_30 ( V_5 -> V_25 ) ;
if ( ! ( V_23 & V_5 -> V_26 ) )
continue;
F_31 () ;
if ( F_2 ( V_22 -> V_27 -> V_6 ) !=
F_2 ( V_22 -> V_28 ) )
continue;
F_25 () ;
break;
}
}
void F_32 ( void )
{
F_33 () ;
F_34 ( F_7 ( L_4 ) ) ;
F_4 () ;
F_35 () ;
if ( F_36 ( F_27 ( V_24 ) ) )
F_26 () ;
F_34 ( F_7 ( L_5 ) ) ;
F_33 () ;
}
void F_37 ( void )
{
unsigned long V_29 ;
F_33 () ;
if ( F_36 ( F_27 ( V_24 ) ) ) {
F_38 ( V_29 ) ;
F_26 () ;
F_39 ( V_29 ) ;
}
if ( F_36 ( F_27 ( V_8 . V_9 . V_11 . exp ) ) ) {
F_40 () ;
F_4 () ;
F_41 () ;
}
F_42 ( V_30 ) ;
F_33 () ;
}
unsigned long F_43 ( void )
{
return V_31 -> V_7 ;
}
unsigned long F_44 ( void )
{
return V_13 . V_7 ;
}
unsigned long F_45 ( void )
{
return V_32 . V_7 ;
}
unsigned long F_46 ( void )
{
return V_31 -> V_6 ;
}
unsigned long F_47 ( void )
{
return V_13 . V_6 ;
}
unsigned long F_48 ( void )
{
return V_32 . V_6 ;
}
unsigned long F_49 ( void )
{
return V_31 -> V_33 ;
}
unsigned long F_50 ( void )
{
return V_13 . V_33 ;
}
void F_51 ( void )
{
F_52 ( V_31 ) ;
}
void F_53 ( void )
{
F_52 ( & V_32 ) ;
}
void F_54 ( void )
{
F_52 ( & V_13 ) ;
}
void F_55 ( void )
{
struct V_4 * V_5 ;
F_29 (rsp) {
F_56 ( L_6 ,
V_5 -> V_34 , V_5 -> V_35 , V_5 -> V_36 -> V_37 ) ;
}
}
void F_57 ( void )
{
V_38 ++ ;
V_39 = 0 ;
}
void F_58 ( enum V_40 V_41 , int * V_29 ,
unsigned long * V_7 , unsigned long * V_6 )
{
struct V_4 * V_5 = NULL ;
switch ( V_41 ) {
case V_42 :
V_5 = V_31 ;
break;
case V_43 :
V_5 = & V_32 ;
break;
case V_44 :
V_5 = & V_13 ;
break;
default:
break;
}
if ( V_5 != NULL ) {
* V_29 = F_2 ( V_5 -> V_45 ) ;
* V_7 = F_2 ( V_5 -> V_7 ) ;
* V_6 = F_2 ( V_5 -> V_6 ) ;
return;
}
* V_29 = 0 ;
* V_7 = 0 ;
* V_6 = 0 ;
}
void F_59 ( unsigned long V_46 )
{
V_39 ++ ;
}
static int
F_60 ( struct V_21 * V_22 )
{
return & V_22 -> V_47 != V_22 -> V_48 [ V_49 ] &&
V_22 -> V_48 [ V_50 ] != NULL ;
}
static struct V_1 * F_61 ( struct V_4 * V_5 )
{
return & V_5 -> V_51 [ 0 ] ;
}
static int F_62 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = F_61 ( V_5 ) ;
int V_52 = ( F_2 ( V_2 -> V_6 ) + 1 ) & 0x1 ;
int * V_53 = & V_2 -> V_54 [ V_52 ] ;
return F_2 ( * V_53 ) ;
}
static bool
F_63 ( struct V_4 * V_5 , struct V_21 * V_22 )
{
int V_55 ;
if ( F_3 ( V_5 ) )
return false ;
if ( F_62 ( V_5 ) )
return true ;
if ( ! V_22 -> V_48 [ V_50 ] )
return false ;
if ( * V_22 -> V_48 [ V_56 ] )
return true ;
for ( V_55 = V_57 ; V_55 < V_50 ; V_55 ++ )
if ( V_22 -> V_48 [ V_55 - 1 ] != V_22 -> V_48 [ V_55 ] &&
F_64 ( F_2 ( V_5 -> V_6 ) ,
V_22 -> V_58 [ V_55 ] ) )
return true ;
return false ;
}
static void F_65 ( long long V_59 , bool V_60 )
{
struct V_4 * V_5 ;
struct V_21 * V_22 ;
F_66 (struct rcu_dynticks *rdtp = this_cpu_ptr(&rcu_dynticks);)
F_67 ( F_7 ( L_7 ) , V_59 , V_16 -> V_61 ) ;
if ( F_15 ( V_19 ) &&
! V_60 && ! F_68 ( V_62 ) ) {
struct V_63 * T_1 V_64 =
F_69 ( F_70 () ) ;
F_67 ( F_7 ( L_8 ) , V_59 , 0 ) ;
F_71 ( V_65 ) ;
F_72 ( 1 , L_9 ,
V_62 -> V_66 , V_62 -> V_67 ,
T_1 -> V_66 , T_1 -> V_67 ) ;
}
F_29 (rsp) {
V_22 = F_10 ( V_5 -> V_25 ) ;
F_73 ( V_22 ) ;
}
F_74 () ;
F_12 () ;
F_75 () ;
F_76 ( F_77 ( & V_68 ) ,
L_10 ) ;
F_76 ( F_77 ( & V_69 ) ,
L_11 ) ;
F_76 ( F_77 ( & V_70 ) ,
L_12 ) ;
}
static void F_78 ( bool V_60 )
{
long long V_59 ;
struct V_15 * V_16 ;
V_16 = F_10 ( & V_15 ) ;
V_59 = V_16 -> V_61 ;
F_14 ( F_15 ( V_19 ) &&
( V_59 & V_71 ) == 0 ) ;
if ( ( V_59 & V_71 ) == V_72 ) {
V_16 -> V_61 = 0 ;
F_65 ( V_59 , V_60 ) ;
} else {
V_16 -> V_61 -= V_72 ;
}
}
void F_79 ( void )
{
unsigned long V_29 ;
F_38 ( V_29 ) ;
F_78 ( false ) ;
F_80 ( 0 ) ;
F_39 ( V_29 ) ;
}
void F_81 ( void )
{
F_78 ( 1 ) ;
}
void F_82 ( void )
{
long long V_59 ;
struct V_15 * V_16 ;
F_76 ( ! F_83 () , L_13 ) ;
V_16 = F_10 ( & V_15 ) ;
V_59 = V_16 -> V_61 ;
V_16 -> V_61 -- ;
F_14 ( F_15 ( V_19 ) &&
V_16 -> V_61 < 0 ) ;
if ( V_16 -> V_61 )
F_67 ( F_7 ( L_14 ) , V_59 , V_16 -> V_61 ) ;
else
F_65 ( V_59 , true ) ;
F_80 ( 1 ) ;
}
void F_84 ( void )
{
unsigned long V_29 ;
F_38 ( V_29 ) ;
F_82 () ;
F_39 ( V_29 ) ;
}
static void F_85 ( long long V_59 , int V_60 )
{
F_66 (struct rcu_dynticks *rdtp = this_cpu_ptr(&rcu_dynticks);)
F_86 () ;
F_16 () ;
F_87 () ;
F_67 ( F_7 ( L_15 ) , V_59 , V_16 -> V_61 ) ;
if ( F_15 ( V_19 ) &&
! V_60 && ! F_68 ( V_62 ) ) {
struct V_63 * T_1 V_64 =
F_69 ( F_70 () ) ;
F_67 ( F_7 ( L_16 ) ,
V_59 , V_16 -> V_61 ) ;
F_71 ( V_65 ) ;
F_72 ( 1 , L_9 ,
V_62 -> V_66 , V_62 -> V_67 ,
T_1 -> V_66 , T_1 -> V_67 ) ;
}
}
static void F_88 ( bool V_60 )
{
struct V_15 * V_16 ;
long long V_59 ;
V_16 = F_10 ( & V_15 ) ;
V_59 = V_16 -> V_61 ;
F_14 ( F_15 ( V_19 ) && V_59 < 0 ) ;
if ( V_59 & V_71 ) {
V_16 -> V_61 += V_72 ;
} else {
V_16 -> V_61 = V_73 ;
F_85 ( V_59 , V_60 ) ;
}
}
void F_89 ( void )
{
unsigned long V_29 ;
F_38 ( V_29 ) ;
F_88 ( false ) ;
F_90 ( 0 ) ;
F_39 ( V_29 ) ;
}
void F_91 ( void )
{
F_88 ( 1 ) ;
}
void F_92 ( void )
{
struct V_15 * V_16 ;
long long V_59 ;
F_76 ( ! F_83 () , L_17 ) ;
V_16 = F_10 ( & V_15 ) ;
V_59 = V_16 -> V_61 ;
V_16 -> V_61 ++ ;
F_14 ( F_15 ( V_19 ) &&
V_16 -> V_61 == 0 ) ;
if ( V_59 )
F_67 ( F_7 ( L_18 ) , V_59 , V_16 -> V_61 ) ;
else
F_85 ( V_59 , true ) ;
F_90 ( 1 ) ;
}
void F_93 ( void )
{
unsigned long V_29 ;
F_38 ( V_29 ) ;
F_92 () ;
F_39 ( V_29 ) ;
}
void F_94 ( void )
{
struct V_15 * V_16 = F_10 ( & V_15 ) ;
int V_74 = 2 ;
F_14 ( V_16 -> V_75 < 0 ) ;
if ( F_20 () ) {
F_16 () ;
V_74 = 1 ;
}
V_16 -> V_75 += V_74 ;
F_33 () ;
}
void F_95 ( void )
{
struct V_15 * V_16 = F_10 ( & V_15 ) ;
F_14 ( V_16 -> V_75 <= 0 ) ;
F_14 ( F_20 () ) ;
if ( V_16 -> V_75 != 1 ) {
V_16 -> V_75 -= 2 ;
return;
}
V_16 -> V_75 = 0 ;
F_12 () ;
}
bool T_2 F_96 ( void )
{
return ! F_20 () ;
}
bool T_2 F_97 ( void )
{
bool V_76 ;
F_98 () ;
V_76 = F_96 () ;
F_99 () ;
return V_76 ;
}
bool F_100 ( void )
{
struct V_21 * V_22 ;
struct V_1 * V_2 ;
bool V_76 ;
if ( F_101 () )
return true ;
F_40 () ;
V_22 = F_10 ( & V_8 ) ;
V_2 = V_22 -> V_27 ;
V_76 = ( V_22 -> V_77 & F_1 ( V_2 ) ) ||
! V_78 ;
F_41 () ;
return V_76 ;
}
static int F_102 ( void )
{
return F_5 ( V_15 . V_61 ) <= 1 ;
}
static int F_103 ( struct V_21 * V_22 ,
bool * V_79 , unsigned long * V_80 )
{
V_22 -> V_81 = F_21 ( V_22 -> V_18 ) ;
F_104 ( V_22 , V_79 , V_80 ) ;
if ( F_23 ( V_22 -> V_81 ) ) {
F_105 ( V_22 -> V_5 -> V_34 , V_22 -> V_7 , V_22 -> V_82 , F_7 ( L_19 ) ) ;
if ( F_64 ( F_2 ( V_22 -> V_7 ) + V_83 / 4 ,
V_22 -> V_27 -> V_7 ) )
F_106 ( V_22 -> V_84 , true ) ;
return 1 ;
}
return 0 ;
}
static int F_107 ( struct V_21 * V_22 ,
bool * V_79 , unsigned long * V_80 )
{
unsigned long V_85 ;
int * V_86 ;
unsigned long V_87 ;
struct V_1 * V_2 ;
if ( F_24 ( V_22 -> V_18 , V_22 -> V_81 ) ) {
F_105 ( V_22 -> V_5 -> V_34 , V_22 -> V_7 , V_22 -> V_82 , F_7 ( L_19 ) ) ;
V_22 -> V_88 ++ ;
return 1 ;
}
V_85 = V_89 ;
V_87 = F_108 () ;
if ( V_85 > V_87 / 2 ) {
F_106 ( V_89 , V_87 ) ;
V_85 = V_87 / 2 ;
} else if ( V_85 < 1 ) {
F_106 ( V_89 , 1 ) ;
V_85 = 1 ;
}
V_2 = V_22 -> V_27 ;
if ( F_109 ( V_90 , V_22 -> V_5 -> V_91 + V_85 ) &&
F_2 ( V_22 -> V_92 ) != F_110 ( V_30 , V_22 -> V_82 ) &&
F_2 ( V_22 -> V_7 ) == V_2 -> V_7 && ! V_22 -> V_84 ) {
F_105 ( V_22 -> V_5 -> V_34 , V_22 -> V_7 , V_22 -> V_82 , F_7 ( L_20 ) ) ;
return 1 ;
}
if ( ! ( V_22 -> V_77 & F_1 ( V_2 ) ) ) {
F_105 ( V_22 -> V_5 -> V_34 , V_22 -> V_7 , V_22 -> V_82 , F_7 ( L_21 ) ) ;
V_22 -> V_93 ++ ;
return 1 ;
}
V_86 = & F_110 ( V_24 , V_22 -> V_82 ) ;
if ( F_109 ( V_90 , V_22 -> V_5 -> V_91 + V_85 ) ||
F_109 ( V_90 , V_22 -> V_5 -> V_94 ) ) {
if ( ! ( F_2 ( * V_86 ) & V_22 -> V_5 -> V_26 ) ) {
F_106 ( V_22 -> V_28 ,
F_2 ( V_22 -> V_27 -> V_6 ) ) ;
F_31 () ;
F_106 ( * V_86 ,
F_2 ( * V_86 ) + V_22 -> V_5 -> V_26 ) ;
}
V_22 -> V_5 -> V_94 += 5 ;
}
if ( V_90 - V_22 -> V_5 -> V_91 > F_108 () / 2 )
F_111 ( V_22 -> V_82 ) ;
return 0 ;
}
static void F_112 ( struct V_4 * V_5 )
{
unsigned long V_95 = V_90 ;
unsigned long j1 ;
V_5 -> V_91 = V_95 ;
F_113 () ;
j1 = F_108 () ;
F_106 ( V_5 -> V_96 , V_95 + j1 ) ;
V_5 -> V_94 = V_95 + j1 / 2 ;
V_5 -> V_97 = F_2 ( V_5 -> V_98 ) ;
}
static const char * F_114 ( short V_99 )
{
if ( V_99 < 0 || V_99 >= F_115 ( V_100 ) )
return L_22 ;
return V_100 [ V_99 ] ;
}
static void F_116 ( struct V_4 * V_5 )
{
unsigned long V_101 ;
unsigned long V_95 ;
V_95 = V_90 ;
V_101 = F_2 ( V_5 -> V_102 ) ;
if ( V_95 - V_101 > 2 * V_103 ) {
F_117 ( L_23 ,
V_5 -> V_34 , V_95 - V_101 ,
V_5 -> V_7 , V_5 -> V_6 ,
V_5 -> V_45 ,
F_114 ( V_5 -> V_35 ) , V_5 -> V_35 ,
V_5 -> V_36 ? V_5 -> V_36 -> V_37 : ~ 0 ) ;
if ( V_5 -> V_36 ) {
F_118 ( V_5 -> V_36 ) ;
F_119 ( V_5 -> V_36 ) ;
}
}
}
static void F_120 ( struct V_4 * V_5 )
{
int V_82 ;
unsigned long V_29 ;
struct V_1 * V_2 ;
F_121 (rsp, rnp) {
F_122 ( V_2 , V_29 ) ;
F_123 (rnp, cpu)
if ( V_2 -> V_104 & F_124 ( V_2 , V_82 ) )
if ( ! F_125 ( V_82 ) )
F_126 ( V_82 ) ;
F_127 ( V_2 , V_29 ) ;
}
}
static void F_128 ( struct V_4 * V_5 )
{
unsigned long V_95 ;
if ( ! V_105 )
return;
V_95 = F_2 ( V_5 -> V_106 ) ;
if ( F_109 ( V_90 , V_95 ) && V_5 -> V_36 &&
( F_3 ( V_5 ) || F_2 ( V_5 -> V_45 ) ) ) {
F_72 ( 1 , L_24 , V_5 -> V_34 ) ;
F_71 ( V_107 ) ;
F_119 ( V_5 -> V_36 ) ;
F_106 ( V_5 -> V_106 , V_95 + V_103 ) ;
}
}
static inline void F_129 ( void )
{
if ( V_108 )
F_130 ( L_25 ) ;
}
static void F_131 ( struct V_4 * V_5 , unsigned long V_7 )
{
int V_82 ;
long V_109 ;
unsigned long V_29 ;
unsigned long V_101 ;
unsigned long V_95 ;
int V_110 = 0 ;
struct V_1 * V_2 = F_61 ( V_5 ) ;
long V_111 = 0 ;
F_128 ( V_5 ) ;
if ( V_112 )
return;
F_122 ( V_2 , V_29 ) ;
V_109 = V_90 - F_2 ( V_5 -> V_96 ) ;
if ( V_109 < V_113 || ! F_3 ( V_5 ) ) {
F_127 ( V_2 , V_29 ) ;
return;
}
F_106 ( V_5 -> V_96 ,
V_90 + 3 * F_108 () + 3 ) ;
F_127 ( V_2 , V_29 ) ;
F_117 ( L_26 ,
V_5 -> V_34 ) ;
F_132 () ;
F_121 (rsp, rnp) {
F_122 ( V_2 , V_29 ) ;
V_110 += F_133 ( V_2 ) ;
if ( V_2 -> V_104 != 0 ) {
F_123 (rnp, cpu)
if ( V_2 -> V_104 & F_124 ( V_2 , V_82 ) ) {
F_134 ( V_5 , V_82 ) ;
V_110 ++ ;
}
}
F_127 ( V_2 , V_29 ) ;
}
F_135 () ;
F_136 (cpu)
V_111 += F_137 ( V_5 -> V_25 , V_82 ) -> V_114 ;
F_138 ( L_27 ,
F_70 () , ( long ) ( V_90 - V_5 -> V_91 ) ,
( long ) V_5 -> V_7 , ( long ) V_5 -> V_6 , V_111 ) ;
if ( V_110 ) {
F_120 ( V_5 ) ;
F_139 ( V_5 ) ;
} else {
if ( F_2 ( V_5 -> V_7 ) != V_7 ||
F_2 ( V_5 -> V_6 ) == V_7 ) {
F_117 ( L_28 ) ;
} else {
V_95 = V_90 ;
V_101 = F_2 ( V_5 -> V_102 ) ;
F_117 ( L_29 ,
V_5 -> V_34 , V_95 - V_101 , V_95 , V_101 ,
V_115 ,
F_61 ( V_5 ) -> V_104 ) ;
F_118 ( V_62 ) ;
}
}
F_116 ( V_5 ) ;
F_129 () ;
F_52 ( V_5 ) ;
}
static void F_140 ( struct V_4 * V_5 )
{
int V_82 ;
unsigned long V_29 ;
struct V_1 * V_2 = F_61 ( V_5 ) ;
long V_111 = 0 ;
F_128 ( V_5 ) ;
if ( V_112 )
return;
F_117 ( L_30 , V_5 -> V_34 ) ;
F_132 () ;
F_134 ( V_5 , F_70 () ) ;
F_135 () ;
F_136 (cpu)
V_111 += F_137 ( V_5 -> V_25 , V_82 ) -> V_114 ;
F_138 ( L_31 ,
V_90 - V_5 -> V_91 ,
( long ) V_5 -> V_7 , ( long ) V_5 -> V_6 , V_111 ) ;
F_116 ( V_5 ) ;
F_120 ( V_5 ) ;
F_122 ( V_2 , V_29 ) ;
if ( F_141 ( V_90 , F_2 ( V_5 -> V_96 ) ) )
F_106 ( V_5 -> V_96 ,
V_90 + 3 * F_108 () + 3 ) ;
F_127 ( V_2 , V_29 ) ;
F_129 () ;
F_111 ( F_70 () ) ;
}
static void F_142 ( struct V_4 * V_5 , struct V_21 * V_22 )
{
unsigned long V_6 ;
unsigned long V_7 ;
unsigned long V_116 ;
unsigned long V_95 ;
unsigned long V_117 ;
struct V_1 * V_2 ;
if ( ( V_112 && ! V_105 ) ||
! F_3 ( V_5 ) )
return;
F_128 ( V_5 ) ;
V_95 = V_90 ;
V_7 = F_2 ( V_5 -> V_7 ) ;
F_143 () ;
V_117 = F_2 ( V_5 -> V_96 ) ;
F_143 () ;
V_116 = F_2 ( V_5 -> V_91 ) ;
F_143 () ;
V_6 = F_2 ( V_5 -> V_6 ) ;
if ( F_141 ( V_6 , V_7 ) ||
F_64 ( V_95 , V_117 ) ||
F_141 ( V_116 , V_117 ) )
return;
V_2 = V_22 -> V_27 ;
if ( F_3 ( V_5 ) &&
( F_2 ( V_2 -> V_104 ) & V_22 -> V_77 ) ) {
F_140 ( V_5 ) ;
} else if ( F_3 ( V_5 ) &&
F_141 ( V_95 , V_117 + V_113 ) ) {
F_131 ( V_5 , V_7 ) ;
}
}
void F_144 ( void )
{
struct V_4 * V_5 ;
F_29 (rsp)
F_106 ( V_5 -> V_96 , V_90 + V_83 / 2 ) ;
}
static void F_145 ( struct V_21 * V_22 )
{
int V_55 ;
V_22 -> V_47 = NULL ;
for ( V_55 = 0 ; V_55 < V_118 ; V_55 ++ )
V_22 -> V_48 [ V_55 ] = & V_22 -> V_47 ;
}
static void F_146 ( struct V_21 * V_22 )
{
if ( F_147 ( V_22 ) )
return;
F_145 ( V_22 ) ;
}
static unsigned long F_148 ( struct V_4 * V_5 ,
struct V_1 * V_2 )
{
if ( F_61 ( V_5 ) == V_2 && V_2 -> V_7 == V_2 -> V_6 )
return V_2 -> V_6 + 1 ;
return V_2 -> V_6 + 2 ;
}
static void F_149 ( struct V_1 * V_2 , struct V_21 * V_22 ,
unsigned long V_119 , const char * V_10 )
{
F_150 ( V_22 -> V_5 -> V_34 , V_2 -> V_7 ,
V_2 -> V_6 , V_119 , V_2 -> V_120 ,
V_2 -> V_121 , V_2 -> V_122 , V_10 ) ;
}
static bool V_64
F_151 ( struct V_1 * V_2 , struct V_21 * V_22 ,
unsigned long * V_123 )
{
unsigned long V_119 ;
int V_55 ;
bool V_76 = false ;
struct V_1 * V_124 = F_61 ( V_22 -> V_5 ) ;
V_119 = F_148 ( V_22 -> V_5 , V_2 ) ;
F_149 ( V_2 , V_22 , V_119 , F_7 ( L_32 ) ) ;
if ( V_2 -> V_54 [ V_119 & 0x1 ] ) {
F_149 ( V_2 , V_22 , V_119 , F_7 ( L_33 ) ) ;
goto V_125;
}
if ( V_2 -> V_7 != V_2 -> V_6 ||
F_2 ( V_124 -> V_7 ) != F_2 ( V_124 -> V_6 ) ) {
V_2 -> V_54 [ V_119 & 0x1 ] ++ ;
F_149 ( V_2 , V_22 , V_119 , F_7 ( L_34 ) ) ;
goto V_125;
}
if ( V_2 != V_124 )
F_152 ( V_124 ) ;
V_119 = F_148 ( V_22 -> V_5 , V_124 ) ;
for ( V_55 = V_49 ; V_55 < V_50 ; V_55 ++ )
if ( F_64 ( V_119 , V_22 -> V_58 [ V_55 ] ) )
V_22 -> V_58 [ V_55 ] = V_119 ;
if ( V_124 -> V_54 [ V_119 & 0x1 ] ) {
F_149 ( V_2 , V_22 , V_119 , F_7 ( L_35 ) ) ;
goto V_126;
}
V_124 -> V_54 [ V_119 & 0x1 ] ++ ;
if ( V_124 -> V_7 != V_124 -> V_6 ) {
F_149 ( V_2 , V_22 , V_119 , F_7 ( L_36 ) ) ;
} else {
F_149 ( V_2 , V_22 , V_119 , F_7 ( L_37 ) ) ;
V_76 = F_153 ( V_22 -> V_5 , V_124 , V_22 ) ;
}
V_126:
if ( V_2 != V_124 )
F_154 ( V_124 ) ;
V_125:
if ( V_123 != NULL )
* V_123 = V_119 ;
return V_76 ;
}
static int F_155 ( struct V_4 * V_5 , struct V_1 * V_2 )
{
int V_119 = V_2 -> V_6 ;
int V_127 ;
struct V_21 * V_22 = F_10 ( V_5 -> V_25 ) ;
V_2 -> V_54 [ V_119 & 0x1 ] = 0 ;
V_127 = V_2 -> V_54 [ ( V_119 + 1 ) & 0x1 ] ;
F_149 ( V_2 , V_22 , V_119 ,
V_127 ? F_7 ( L_38 ) : F_7 ( L_39 ) ) ;
return V_127 ;
}
static void F_156 ( struct V_4 * V_5 )
{
if ( V_62 == V_5 -> V_36 ||
! F_2 ( V_5 -> V_45 ) ||
! V_5 -> V_36 )
return;
F_157 ( & V_5 -> V_128 ) ;
}
static bool F_158 ( struct V_4 * V_5 , struct V_1 * V_2 ,
struct V_21 * V_22 )
{
unsigned long V_119 ;
int V_55 ;
bool V_76 ;
if ( ! V_22 -> V_48 [ V_50 ] || ! * V_22 -> V_48 [ V_49 ] )
return false ;
V_119 = F_148 ( V_5 , V_2 ) ;
for ( V_55 = V_50 - 1 ; V_55 > V_49 ; V_55 -- )
if ( V_22 -> V_48 [ V_55 ] != V_22 -> V_48 [ V_55 - 1 ] &&
! F_141 ( V_22 -> V_58 [ V_55 ] , V_119 ) )
break;
if ( ++ V_55 >= V_50 )
return false ;
for (; V_55 <= V_50 ; V_55 ++ ) {
V_22 -> V_48 [ V_55 ] = V_22 -> V_48 [ V_50 ] ;
V_22 -> V_58 [ V_55 ] = V_119 ;
}
V_76 = F_151 ( V_2 , V_22 , NULL ) ;
if ( ! * V_22 -> V_48 [ V_57 ] )
F_6 ( V_5 -> V_34 , V_22 -> V_7 , F_7 ( L_40 ) ) ;
else
F_6 ( V_5 -> V_34 , V_22 -> V_7 , F_7 ( L_41 ) ) ;
return V_76 ;
}
static bool F_159 ( struct V_4 * V_5 , struct V_1 * V_2 ,
struct V_21 * V_22 )
{
int V_55 , V_95 ;
if ( ! V_22 -> V_48 [ V_50 ] || ! * V_22 -> V_48 [ V_49 ] )
return false ;
for ( V_55 = V_57 ; V_55 < V_50 ; V_55 ++ ) {
if ( F_64 ( V_2 -> V_6 , V_22 -> V_58 [ V_55 ] ) )
break;
V_22 -> V_48 [ V_49 ] = V_22 -> V_48 [ V_55 ] ;
}
for ( V_95 = V_57 ; V_95 < V_55 ; V_95 ++ )
V_22 -> V_48 [ V_95 ] = V_22 -> V_48 [ V_49 ] ;
for ( V_95 = V_57 ; V_55 < V_50 ; V_55 ++ , V_95 ++ ) {
if ( V_22 -> V_48 [ V_95 ] == V_22 -> V_48 [ V_50 ] )
break;
V_22 -> V_48 [ V_95 ] = V_22 -> V_48 [ V_55 ] ;
V_22 -> V_58 [ V_95 ] = V_22 -> V_58 [ V_55 ] ;
}
return F_158 ( V_5 , V_2 , V_22 ) ;
}
static bool F_160 ( struct V_4 * V_5 , struct V_1 * V_2 ,
struct V_21 * V_22 )
{
bool V_76 ;
bool V_129 ;
if ( V_22 -> V_6 == V_2 -> V_6 &&
! F_36 ( F_2 ( V_22 -> V_84 ) ) ) {
V_76 = F_158 ( V_5 , V_2 , V_22 ) ;
} else {
V_76 = F_159 ( V_5 , V_2 , V_22 ) ;
V_22 -> V_6 = V_2 -> V_6 ;
F_6 ( V_5 -> V_34 , V_22 -> V_7 , F_7 ( L_42 ) ) ;
}
if ( V_22 -> V_7 != V_2 -> V_7 || F_36 ( F_2 ( V_22 -> V_84 ) ) ) {
V_22 -> V_7 = V_2 -> V_7 ;
F_6 ( V_5 -> V_34 , V_22 -> V_7 , F_7 ( L_43 ) ) ;
V_129 = ! ! ( V_2 -> V_104 & V_22 -> V_77 ) ;
V_22 -> V_9 . V_11 . V_12 = V_129 ;
V_22 -> V_92 = F_5 ( V_30 ) ;
V_22 -> V_130 = V_129 ;
F_161 ( V_22 ) ;
F_106 ( V_22 -> V_84 , false ) ;
}
return V_76 ;
}
static void F_162 ( struct V_4 * V_5 , struct V_21 * V_22 )
{
unsigned long V_29 ;
bool V_131 ;
struct V_1 * V_2 ;
F_38 ( V_29 ) ;
V_2 = V_22 -> V_27 ;
if ( ( V_22 -> V_7 == F_2 ( V_2 -> V_7 ) &&
V_22 -> V_6 == F_2 ( V_2 -> V_6 ) &&
! F_36 ( F_2 ( V_22 -> V_84 ) ) ) ||
! F_163 ( V_2 ) ) {
F_39 ( V_29 ) ;
return;
}
V_131 = F_160 ( V_5 , V_2 , V_22 ) ;
F_127 ( V_2 , V_29 ) ;
if ( V_131 )
F_156 ( V_5 ) ;
}
static void F_164 ( struct V_4 * V_5 , int V_132 )
{
if ( V_132 > 0 &&
! ( V_5 -> V_7 % ( V_133 * V_134 * V_132 ) ) )
F_165 ( V_132 ) ;
}
static bool F_166 ( struct V_4 * V_5 )
{
unsigned long V_135 ;
struct V_21 * V_22 ;
struct V_1 * V_2 = F_61 ( V_5 ) ;
F_106 ( V_5 -> V_102 , V_90 ) ;
F_167 ( V_2 ) ;
if ( ! F_2 ( V_5 -> V_45 ) ) {
F_168 ( V_2 ) ;
return false ;
}
F_106 ( V_5 -> V_45 , 0 ) ;
if ( F_14 ( F_3 ( V_5 ) ) ) {
F_168 ( V_2 ) ;
return false ;
}
F_112 ( V_5 ) ;
F_169 ( & V_5 -> V_7 , V_5 -> V_7 + 1 ) ;
F_6 ( V_5 -> V_34 , V_5 -> V_7 , F_7 ( L_44 ) ) ;
F_168 ( V_2 ) ;
F_121 (rsp, rnp) {
F_164 ( V_5 , V_136 ) ;
F_167 ( V_2 ) ;
if ( V_2 -> V_137 == V_2 -> V_3 &&
! V_2 -> V_138 ) {
F_168 ( V_2 ) ;
continue;
}
V_135 = V_2 -> V_137 ;
V_2 -> V_137 = V_2 -> V_3 ;
if ( ! V_135 != ! V_2 -> V_137 ) {
if ( ! V_135 )
F_170 ( V_2 ) ;
else if ( F_171 ( V_2 ) )
V_2 -> V_138 = true ;
else
F_172 ( V_2 ) ;
}
if ( V_2 -> V_138 &&
( ! F_171 ( V_2 ) ||
V_2 -> V_137 ) ) {
V_2 -> V_138 = false ;
F_172 ( V_2 ) ;
}
F_168 ( V_2 ) ;
}
F_173 (rsp, rnp) {
F_164 ( V_5 , V_139 ) ;
F_167 ( V_2 ) ;
V_22 = F_10 ( V_5 -> V_25 ) ;
F_174 ( V_2 ) ;
V_2 -> V_104 = V_2 -> V_137 ;
F_106 ( V_2 -> V_7 , V_5 -> V_7 ) ;
if ( F_14 ( V_2 -> V_6 != V_5 -> V_6 ) )
F_106 ( V_2 -> V_6 , V_5 -> V_6 ) ;
if ( V_2 == V_22 -> V_27 )
( void ) F_160 ( V_5 , V_2 , V_22 ) ;
F_175 ( V_2 ) ;
F_176 ( V_5 -> V_34 , V_2 -> V_7 ,
V_2 -> V_120 , V_2 -> V_121 ,
V_2 -> V_122 , V_2 -> V_104 ) ;
F_168 ( V_2 ) ;
F_177 () ;
F_106 ( V_5 -> V_102 , V_90 ) ;
}
return true ;
}
static bool F_178 ( struct V_4 * V_5 , int * V_140 )
{
struct V_1 * V_2 = F_61 ( V_5 ) ;
* V_140 = F_2 ( V_5 -> V_45 ) ;
if ( * V_140 & V_141 )
return true ;
if ( ! F_2 ( V_2 -> V_104 ) && ! F_179 ( V_2 ) )
return true ;
return false ;
}
static void F_180 ( struct V_4 * V_5 , bool V_142 )
{
bool V_79 = false ;
unsigned long V_80 ;
struct V_1 * V_2 = F_61 ( V_5 ) ;
F_106 ( V_5 -> V_102 , V_90 ) ;
V_5 -> V_98 ++ ;
if ( V_142 ) {
if ( F_181 ( V_5 ) ) {
V_79 = true ;
V_80 = V_90 - V_83 / 4 ;
}
F_182 ( V_5 , F_103 ,
& V_79 , & V_80 ) ;
F_183 ( V_5 , V_79 , V_80 ) ;
} else {
V_79 = true ;
F_182 ( V_5 , F_107 , & V_79 , & V_80 ) ;
}
if ( F_2 ( V_5 -> V_45 ) & V_141 ) {
F_167 ( V_2 ) ;
F_106 ( V_5 -> V_45 ,
F_2 ( V_5 -> V_45 ) & ~ V_141 ) ;
F_168 ( V_2 ) ;
}
}
static void F_184 ( struct V_4 * V_5 )
{
unsigned long V_143 ;
bool V_144 = false ;
int V_145 = 0 ;
struct V_21 * V_22 ;
struct V_1 * V_2 = F_61 ( V_5 ) ;
struct V_146 * V_147 ;
F_106 ( V_5 -> V_102 , V_90 ) ;
F_167 ( V_2 ) ;
V_143 = V_90 - V_5 -> V_91 ;
if ( V_143 > V_5 -> V_148 )
V_5 -> V_148 = V_143 ;
F_168 ( V_2 ) ;
F_173 (rsp, rnp) {
F_167 ( V_2 ) ;
F_14 ( F_179 ( V_2 ) ) ;
F_14 ( V_2 -> V_104 ) ;
F_106 ( V_2 -> V_6 , V_5 -> V_7 ) ;
V_22 = F_10 ( V_5 -> V_25 ) ;
if ( V_2 == V_22 -> V_27 )
V_144 = F_160 ( V_5 , V_2 , V_22 ) || V_144 ;
V_145 += F_155 ( V_5 , V_2 ) ;
V_147 = F_185 ( V_2 ) ;
F_168 ( V_2 ) ;
F_186 ( V_147 ) ;
F_177 () ;
F_106 ( V_5 -> V_102 , V_90 ) ;
F_164 ( V_5 , V_149 ) ;
}
V_2 = F_61 ( V_5 ) ;
F_167 ( V_2 ) ;
F_187 ( V_2 , V_145 ) ;
F_106 ( V_5 -> V_6 , V_5 -> V_7 ) ;
F_6 ( V_5 -> V_34 , V_5 -> V_6 , F_7 ( L_45 ) ) ;
V_5 -> V_35 = V_150 ;
V_22 = F_10 ( V_5 -> V_25 ) ;
V_144 = F_159 ( V_5 , V_2 , V_22 ) || V_144 ;
if ( V_144 || F_63 ( V_5 , V_22 ) ) {
F_106 ( V_5 -> V_45 , V_151 ) ;
F_6 ( V_5 -> V_34 ,
F_2 ( V_5 -> V_7 ) ,
F_7 ( L_46 ) ) ;
}
F_168 ( V_2 ) ;
}
static int T_3 F_188 ( void * V_152 )
{
bool V_153 ;
int V_154 ;
unsigned long V_95 ;
int V_76 ;
struct V_4 * V_5 = V_152 ;
struct V_1 * V_2 = F_61 ( V_5 ) ;
F_189 () ;
for (; ; ) {
for (; ; ) {
F_6 ( V_5 -> V_34 ,
F_2 ( V_5 -> V_7 ) ,
F_7 ( L_47 ) ) ;
V_5 -> V_35 = V_155 ;
F_190 ( V_5 -> V_128 ,
F_2 ( V_5 -> V_45 ) &
V_151 ) ;
V_5 -> V_35 = V_156 ;
if ( F_166 ( V_5 ) )
break;
F_177 () ;
F_106 ( V_5 -> V_102 , V_90 ) ;
F_191 ( F_192 ( V_62 ) ) ;
F_6 ( V_5 -> V_34 ,
F_2 ( V_5 -> V_7 ) ,
F_7 ( L_48 ) ) ;
}
V_153 = true ;
V_95 = V_157 ;
if ( V_95 > V_103 ) {
V_95 = V_103 ;
V_157 = V_103 ;
}
V_76 = 0 ;
for (; ; ) {
if ( ! V_76 ) {
V_5 -> V_158 = V_90 + V_95 ;
F_106 ( V_5 -> V_106 ,
V_90 + 3 * V_95 ) ;
}
F_6 ( V_5 -> V_34 ,
F_2 ( V_5 -> V_7 ) ,
F_7 ( L_49 ) ) ;
V_5 -> V_35 = V_159 ;
V_76 = F_193 ( V_5 -> V_128 ,
F_178 ( V_5 , & V_154 ) , V_95 ) ;
V_5 -> V_35 = V_160 ;
if ( ! F_2 ( V_2 -> V_104 ) &&
! F_179 ( V_2 ) )
break;
if ( F_141 ( V_90 , V_5 -> V_158 ) ||
( V_154 & V_141 ) ) {
F_6 ( V_5 -> V_34 ,
F_2 ( V_5 -> V_7 ) ,
F_7 ( L_50 ) ) ;
F_180 ( V_5 , V_153 ) ;
V_153 = false ;
F_6 ( V_5 -> V_34 ,
F_2 ( V_5 -> V_7 ) ,
F_7 ( L_51 ) ) ;
F_177 () ;
F_106 ( V_5 -> V_102 , V_90 ) ;
V_76 = 0 ;
V_95 = V_115 ;
if ( V_95 > V_103 ) {
V_95 = V_103 ;
V_115 = V_103 ;
} else if ( V_95 < 1 ) {
V_95 = 1 ;
V_115 = 1 ;
}
} else {
F_177 () ;
F_106 ( V_5 -> V_102 , V_90 ) ;
F_191 ( F_192 ( V_62 ) ) ;
F_6 ( V_5 -> V_34 ,
F_2 ( V_5 -> V_7 ) ,
F_7 ( L_52 ) ) ;
V_76 = 1 ;
V_95 = V_90 ;
if ( F_109 ( V_90 , V_5 -> V_158 ) )
V_95 = 1 ;
else
V_95 = V_5 -> V_158 - V_95 ;
}
}
V_5 -> V_35 = V_161 ;
F_184 ( V_5 ) ;
V_5 -> V_35 = V_162 ;
}
}
static bool
F_153 ( struct V_4 * V_5 , struct V_1 * V_2 ,
struct V_21 * V_22 )
{
if ( ! V_5 -> V_36 || ! F_63 ( V_5 , V_22 ) ) {
return false ;
}
F_106 ( V_5 -> V_45 , V_151 ) ;
F_6 ( V_5 -> V_34 , F_2 ( V_5 -> V_7 ) ,
F_7 ( L_46 ) ) ;
return true ;
}
static bool F_194 ( struct V_4 * V_5 )
{
struct V_21 * V_22 = F_10 ( V_5 -> V_25 ) ;
struct V_1 * V_2 = F_61 ( V_5 ) ;
bool V_76 = false ;
V_76 = F_159 ( V_5 , V_2 , V_22 ) || V_76 ;
V_76 = F_153 ( V_5 , V_2 , V_22 ) || V_76 ;
return V_76 ;
}
static void F_195 ( struct V_4 * V_5 , unsigned long V_29 )
__releases( rcu_get_root( V_5 )->lock
static void
F_196 ( unsigned long V_163 , struct V_4 * V_5 ,
struct V_1 * V_2 , unsigned long V_116 , unsigned long V_29 )
__releases( V_2 -> V_164 )
{
unsigned long V_135 = 0 ;
struct V_1 * V_165 ;
for (; ; ) {
if ( ! ( V_2 -> V_104 & V_163 ) || V_2 -> V_7 != V_116 ) {
F_127 ( V_2 , V_29 ) ;
return;
}
F_14 ( V_135 ) ;
V_2 -> V_104 &= ~ V_163 ;
F_197 ( V_5 -> V_34 , V_2 -> V_7 ,
V_163 , V_2 -> V_104 , V_2 -> V_120 ,
V_2 -> V_121 , V_2 -> V_122 ,
! ! V_2 -> V_166 ) ;
if ( V_2 -> V_104 != 0 || F_179 ( V_2 ) ) {
F_127 ( V_2 , V_29 ) ;
return;
}
V_163 = V_2 -> V_77 ;
if ( V_2 -> V_167 == NULL ) {
break;
}
F_127 ( V_2 , V_29 ) ;
V_165 = V_2 ;
V_2 = V_2 -> V_167 ;
F_122 ( V_2 , V_29 ) ;
V_135 = V_165 -> V_104 ;
}
F_195 ( V_5 , V_29 ) ;
}
static void F_198 ( struct V_4 * V_5 ,
struct V_1 * V_2 , unsigned long V_29 )
__releases( V_2 -> V_164 )
{
unsigned long V_116 ;
unsigned long V_163 ;
struct V_1 * V_168 ;
if ( V_31 == & V_13 || V_5 != V_31 ||
V_2 -> V_104 != 0 || F_179 ( V_2 ) ) {
F_127 ( V_2 , V_29 ) ;
return;
}
V_168 = V_2 -> V_167 ;
if ( V_168 == NULL ) {
F_195 ( V_5 , V_29 ) ;
return;
}
V_116 = V_2 -> V_7 ;
V_163 = V_2 -> V_77 ;
F_154 ( V_2 ) ;
F_152 ( V_168 ) ;
F_196 ( V_163 , V_5 , V_168 , V_116 , V_29 ) ;
}
static void
F_199 ( int V_82 , struct V_4 * V_5 , struct V_21 * V_22 )
{
unsigned long V_29 ;
unsigned long V_163 ;
bool V_131 ;
struct V_1 * V_2 ;
V_2 = V_22 -> V_27 ;
F_122 ( V_2 , V_29 ) ;
if ( V_22 -> V_9 . V_11 . V_12 || V_22 -> V_7 != V_2 -> V_7 ||
V_2 -> V_6 == V_2 -> V_7 || V_22 -> V_84 ) {
V_22 -> V_9 . V_11 . V_12 = true ;
V_22 -> V_92 = F_5 ( V_30 ) ;
F_127 ( V_2 , V_29 ) ;
return;
}
V_163 = V_22 -> V_77 ;
if ( ( V_2 -> V_104 & V_163 ) == 0 ) {
F_127 ( V_2 , V_29 ) ;
} else {
V_22 -> V_130 = false ;
V_131 = F_158 ( V_5 , V_2 , V_22 ) ;
F_196 ( V_163 , V_5 , V_2 , V_2 -> V_7 , V_29 ) ;
if ( V_131 )
F_156 ( V_5 ) ;
}
}
static void
F_200 ( struct V_4 * V_5 , struct V_21 * V_22 )
{
F_162 ( V_5 , V_22 ) ;
if ( ! V_22 -> V_130 )
return;
if ( V_22 -> V_9 . V_11 . V_12 )
return;
F_199 ( V_22 -> V_82 , V_5 , V_22 ) ;
}
static void
F_201 ( int V_82 , struct V_4 * V_5 ,
struct V_1 * V_2 , struct V_21 * V_22 )
{
if ( ! F_15 ( V_169 ) || F_202 ( V_22 -> V_82 ) )
return;
if ( V_22 -> V_47 != NULL ) {
V_5 -> V_170 += V_22 -> V_170 ;
V_5 -> V_114 += V_22 -> V_114 ;
V_22 -> V_171 += V_22 -> V_114 ;
V_22 -> V_170 = 0 ;
F_106 ( V_22 -> V_114 , 0 ) ;
}
if ( * V_22 -> V_48 [ V_49 ] != NULL ) {
* V_5 -> V_172 = * V_22 -> V_48 [ V_49 ] ;
V_5 -> V_172 = V_22 -> V_48 [ V_50 ] ;
* V_22 -> V_48 [ V_49 ] = NULL ;
}
if ( V_22 -> V_47 != NULL ) {
* V_5 -> V_173 = V_22 -> V_47 ;
V_5 -> V_173 = V_22 -> V_48 [ V_49 ] ;
}
F_146 ( V_22 ) ;
V_22 -> V_48 [ V_50 ] = NULL ;
}
static void F_203 ( struct V_4 * V_5 , unsigned long V_29 )
{
int V_55 ;
struct V_21 * V_22 = F_30 ( V_5 -> V_25 ) ;
if ( ! F_15 ( V_169 ) ||
F_204 ( V_5 , V_22 , V_29 ) )
return;
V_22 -> V_170 += V_5 -> V_170 ;
V_22 -> V_114 += V_5 -> V_114 ;
V_22 -> V_174 += V_5 -> V_114 ;
if ( V_5 -> V_170 != V_5 -> V_114 )
F_205 () ;
V_5 -> V_170 = 0 ;
V_5 -> V_114 = 0 ;
if ( V_5 -> V_175 != NULL ) {
* V_5 -> V_173 = * V_22 -> V_48 [ V_49 ] ;
* V_22 -> V_48 [ V_49 ] = V_5 -> V_175 ;
for ( V_55 = V_118 - 1 ; V_55 >= V_49 ; V_55 -- )
if ( V_22 -> V_48 [ V_55 ] == V_22 -> V_48 [ V_49 ] )
V_22 -> V_48 [ V_55 ] = V_5 -> V_173 ;
V_5 -> V_175 = NULL ;
V_5 -> V_173 = & V_5 -> V_175 ;
}
if ( V_5 -> V_176 != NULL ) {
* V_22 -> V_48 [ V_50 ] = V_5 -> V_176 ;
V_22 -> V_48 [ V_50 ] = V_5 -> V_172 ;
V_5 -> V_176 = NULL ;
V_5 -> V_172 = & V_5 -> V_176 ;
}
}
static void F_206 ( struct V_4 * V_5 )
{
F_66 (unsigned long mask) ;
F_66 ( struct V_21 * V_22 = F_10 ( V_5 -> V_25 ) ) ;
F_66 ( struct V_1 * V_2 = V_22 -> V_27 ) ;
if ( ! F_15 ( V_169 ) )
return;
F_66 ( V_163 = V_22 -> V_77 ) ;
F_6 ( V_5 -> V_34 ,
V_2 -> V_7 + 1 - ! ! ( V_2 -> V_104 & V_163 ) ,
F_7 ( L_53 ) ) ;
}
static void F_172 ( struct V_1 * V_177 )
{
long V_163 ;
struct V_1 * V_2 = V_177 ;
if ( ! F_15 ( V_169 ) ||
V_2 -> V_137 || F_171 ( V_2 ) )
return;
for (; ; ) {
V_163 = V_2 -> V_77 ;
V_2 = V_2 -> V_167 ;
if ( ! V_2 )
break;
F_152 ( V_2 ) ;
V_2 -> V_137 &= ~ V_163 ;
V_2 -> V_104 &= ~ V_163 ;
if ( V_2 -> V_137 ) {
F_154 ( V_2 ) ;
return;
}
F_154 ( V_2 ) ;
}
}
static void F_207 ( int V_82 , struct V_4 * V_5 )
{
unsigned long V_29 ;
struct V_21 * V_22 = F_137 ( V_5 -> V_25 , V_82 ) ;
struct V_1 * V_2 = V_22 -> V_27 ;
if ( ! F_15 ( V_169 ) )
return;
F_208 ( V_2 , - 1 ) ;
F_209 ( & V_5 -> V_178 , V_29 ) ;
F_201 ( V_82 , V_5 , V_2 , V_22 ) ;
F_203 ( V_5 , V_29 ) ;
F_210 ( & V_5 -> V_178 , V_29 ) ;
F_72 ( V_22 -> V_114 != 0 || V_22 -> V_47 != NULL ,
L_54 ,
V_82 , V_22 -> V_114 , V_22 -> V_47 ) ;
}
static void F_211 ( struct V_4 * V_5 , struct V_21 * V_22 )
{
unsigned long V_29 ;
struct V_179 * V_180 , * V_181 , * * V_182 ;
long V_183 , V_184 , V_185 ;
int V_55 ;
if ( ! F_60 ( V_22 ) ) {
F_212 ( V_5 -> V_34 , V_22 -> V_170 , V_22 -> V_114 , 0 ) ;
F_213 ( V_5 -> V_34 , 0 , ! ! F_2 ( V_22 -> V_47 ) ,
F_214 () , F_68 ( V_62 ) ,
F_215 () ) ;
return;
}
F_38 ( V_29 ) ;
F_14 ( F_216 ( F_70 () ) ) ;
V_183 = V_22 -> V_186 ;
F_212 ( V_5 -> V_34 , V_22 -> V_170 , V_22 -> V_114 , V_183 ) ;
V_181 = V_22 -> V_47 ;
V_22 -> V_47 = * V_22 -> V_48 [ V_49 ] ;
* V_22 -> V_48 [ V_49 ] = NULL ;
V_182 = V_22 -> V_48 [ V_49 ] ;
for ( V_55 = V_118 - 1 ; V_55 >= 0 ; V_55 -- )
if ( V_22 -> V_48 [ V_55 ] == V_22 -> V_48 [ V_49 ] )
V_22 -> V_48 [ V_55 ] = & V_22 -> V_47 ;
F_39 ( V_29 ) ;
V_184 = V_185 = 0 ;
while ( V_181 ) {
V_180 = V_181 -> V_180 ;
F_217 ( V_180 ) ;
F_218 ( V_181 ) ;
if ( F_219 ( V_5 -> V_34 , V_181 ) )
V_185 ++ ;
V_181 = V_180 ;
if ( ++ V_184 >= V_183 &&
( F_214 () ||
( ! F_68 ( V_62 ) && ! F_215 () ) ) )
break;
}
F_38 ( V_29 ) ;
F_213 ( V_5 -> V_34 , V_184 , ! ! V_181 , F_214 () ,
F_68 ( V_62 ) ,
F_215 () ) ;
if ( V_181 != NULL ) {
* V_182 = V_22 -> V_47 ;
V_22 -> V_47 = V_181 ;
for ( V_55 = 0 ; V_55 < V_118 ; V_55 ++ )
if ( & V_22 -> V_47 == V_22 -> V_48 [ V_55 ] )
V_22 -> V_48 [ V_55 ] = V_182 ;
else
break;
}
F_31 () ;
V_22 -> V_170 -= V_185 ;
F_106 ( V_22 -> V_114 , V_22 -> V_114 - V_184 ) ;
V_22 -> V_187 += V_184 ;
if ( V_22 -> V_186 == V_188 && V_22 -> V_114 <= V_189 )
V_22 -> V_186 = V_186 ;
if ( V_22 -> V_114 == 0 && V_22 -> V_190 != 0 ) {
V_22 -> V_190 = 0 ;
V_22 -> V_191 = V_5 -> V_98 ;
} else if ( V_22 -> V_114 < V_22 -> V_190 - V_192 )
V_22 -> V_190 = V_22 -> V_114 ;
F_14 ( ( V_22 -> V_47 == NULL ) != ( V_22 -> V_114 == 0 ) ) ;
F_39 ( V_29 ) ;
if ( F_60 ( V_22 ) )
F_220 () ;
}
void F_221 ( int V_60 )
{
F_34 ( F_7 ( L_55 ) ) ;
F_222 () ;
if ( V_60 || F_102 () ) {
F_4 () ;
F_11 () ;
} else if ( ! F_223 () ) {
F_11 () ;
}
F_224 () ;
if ( F_225 () )
F_220 () ;
if ( V_60 )
F_226 ( V_62 ) ;
F_34 ( F_7 ( L_56 ) ) ;
}
static void F_182 ( struct V_4 * V_5 ,
int (* F_227)( struct V_21 * V_5 , bool * V_79 ,
unsigned long * V_80 ) ,
bool * V_79 , unsigned long * V_80 )
{
int V_82 ;
unsigned long V_29 ;
unsigned long V_163 ;
struct V_1 * V_2 ;
F_121 (rsp, rnp) {
F_177 () ;
V_163 = 0 ;
F_122 ( V_2 , V_29 ) ;
if ( V_2 -> V_104 == 0 ) {
if ( V_31 == & V_13 ||
V_5 != V_31 ||
F_179 ( V_2 ) ) {
F_228 ( V_2 , V_29 ) ;
continue;
}
if ( V_2 -> V_167 &&
( V_2 -> V_167 -> V_104 & V_2 -> V_77 ) ) {
F_198 ( V_5 , V_2 , V_29 ) ;
continue;
}
}
F_123 (rnp, cpu) {
unsigned long V_193 = F_124 ( V_2 , V_82 ) ;
if ( ( V_2 -> V_104 & V_193 ) != 0 ) {
if ( F_227 ( F_137 ( V_5 -> V_25 , V_82 ) , V_79 , V_80 ) )
V_163 |= V_193 ;
}
}
if ( V_163 != 0 ) {
F_196 ( V_163 , V_5 , V_2 , V_2 -> V_7 , V_29 ) ;
} else {
F_127 ( V_2 , V_29 ) ;
}
}
}
static void F_52 ( struct V_4 * V_5 )
{
unsigned long V_29 ;
bool V_76 ;
struct V_1 * V_2 ;
struct V_1 * V_194 = NULL ;
V_2 = F_5 ( V_5 -> V_25 -> V_27 ) ;
for (; V_2 != NULL ; V_2 = V_2 -> V_167 ) {
V_76 = ( F_2 ( V_5 -> V_45 ) & V_141 ) ||
! F_229 ( & V_2 -> V_195 ) ;
if ( V_194 != NULL )
F_230 ( & V_194 -> V_195 ) ;
if ( V_76 ) {
V_5 -> V_196 ++ ;
return;
}
V_194 = V_2 ;
}
F_122 ( V_194 , V_29 ) ;
F_230 ( & V_194 -> V_195 ) ;
if ( F_2 ( V_5 -> V_45 ) & V_141 ) {
V_5 -> V_196 ++ ;
F_127 ( V_194 , V_29 ) ;
return;
}
F_106 ( V_5 -> V_45 , F_2 ( V_5 -> V_45 ) | V_141 ) ;
F_127 ( V_194 , V_29 ) ;
F_156 ( V_5 ) ;
}
static void
F_231 ( struct V_4 * V_5 )
{
unsigned long V_29 ;
bool V_131 ;
struct V_21 * V_22 = F_30 ( V_5 -> V_25 ) ;
F_14 ( V_22 -> V_197 == 0 ) ;
F_200 ( V_5 , V_22 ) ;
F_38 ( V_29 ) ;
if ( F_63 ( V_5 , V_22 ) ) {
F_152 ( F_61 ( V_5 ) ) ;
V_131 = F_194 ( V_5 ) ;
F_127 ( F_61 ( V_5 ) , V_29 ) ;
if ( V_131 )
F_156 ( V_5 ) ;
} else {
F_39 ( V_29 ) ;
}
if ( F_60 ( V_22 ) )
F_232 ( V_5 , V_22 ) ;
F_73 ( V_22 ) ;
}
static T_4 void F_233 ( struct V_198 * V_199 )
{
struct V_4 * V_5 ;
if ( F_216 ( F_70 () ) )
return;
F_34 ( F_7 ( L_57 ) ) ;
F_29 (rsp)
F_231 ( V_5 ) ;
F_34 ( F_7 ( L_58 ) ) ;
}
static void F_232 ( struct V_4 * V_5 , struct V_21 * V_22 )
{
if ( F_36 ( ! F_2 ( V_78 ) ) )
return;
if ( F_234 ( ! V_5 -> V_200 ) ) {
F_211 ( V_5 , V_22 ) ;
return;
}
F_235 () ;
}
static void F_220 ( void )
{
if ( F_236 ( F_70 () ) )
F_237 ( V_201 ) ;
}
static void F_238 ( struct V_4 * V_5 , struct V_21 * V_22 ,
struct V_179 * V_202 , unsigned long V_29 )
{
bool V_131 ;
if ( ! F_97 () )
F_220 () ;
if ( F_239 ( V_29 ) || F_216 ( F_70 () ) )
return;
if ( F_36 ( V_22 -> V_114 > V_22 -> V_190 + V_192 ) ) {
F_162 ( V_5 , V_22 ) ;
if ( ! F_3 ( V_5 ) ) {
struct V_1 * V_124 = F_61 ( V_5 ) ;
F_152 ( V_124 ) ;
V_131 = F_194 ( V_5 ) ;
F_154 ( V_124 ) ;
if ( V_131 )
F_156 ( V_5 ) ;
} else {
V_22 -> V_186 = V_188 ;
if ( V_5 -> V_98 == V_22 -> V_191 &&
* V_22 -> V_48 [ V_49 ] != V_202 )
F_52 ( V_5 ) ;
V_22 -> V_191 = V_5 -> V_98 ;
V_22 -> V_190 = V_22 -> V_114 ;
}
}
}
static void F_240 ( struct V_179 * V_203 )
{
}
static void
F_241 ( struct V_179 * V_202 , T_5 V_204 ,
struct V_4 * V_5 , int V_82 , bool V_205 )
{
unsigned long V_29 ;
struct V_21 * V_22 ;
F_14 ( ( unsigned long ) V_202 & ( sizeof( void * ) - 1 ) ) ;
if ( F_242 ( V_202 ) ) {
F_106 ( V_202 -> V_204 , F_240 ) ;
F_72 ( 1 , L_59 ) ;
return;
}
V_202 -> V_204 = V_204 ;
V_202 -> V_180 = NULL ;
F_38 ( V_29 ) ;
V_22 = F_10 ( V_5 -> V_25 ) ;
if ( F_36 ( V_22 -> V_48 [ V_50 ] == NULL ) || V_82 != - 1 ) {
int V_206 ;
if ( V_82 != - 1 )
V_22 = F_137 ( V_5 -> V_25 , V_82 ) ;
if ( F_234 ( V_22 -> V_27 ) ) {
V_206 = ! F_243 ( V_22 , V_202 , V_205 , V_29 ) ;
F_14 ( V_206 ) ;
F_39 ( V_29 ) ;
return;
}
F_244 ( V_82 != - 1 ) ;
F_14 ( ! F_97 () ) ;
if ( ! F_234 ( V_22 -> V_47 ) )
F_145 ( V_22 ) ;
}
F_106 ( V_22 -> V_114 , V_22 -> V_114 + 1 ) ;
if ( V_205 )
V_22 -> V_170 ++ ;
else
F_205 () ;
F_31 () ;
* V_22 -> V_48 [ V_50 ] = V_202 ;
V_22 -> V_48 [ V_50 ] = & V_202 -> V_180 ;
if ( F_245 ( ( unsigned long ) V_204 ) )
F_246 ( V_5 -> V_34 , V_202 , ( unsigned long ) V_204 ,
V_22 -> V_170 , V_22 -> V_114 ) ;
else
F_247 ( V_5 -> V_34 , V_202 , V_22 -> V_170 , V_22 -> V_114 ) ;
F_238 ( V_5 , V_22 , V_202 , V_29 ) ;
F_39 ( V_29 ) ;
}
void F_248 ( struct V_179 * V_202 , T_5 V_204 )
{
F_241 ( V_202 , V_204 , & V_13 , - 1 , 0 ) ;
}
void F_249 ( struct V_179 * V_202 , T_5 V_204 )
{
F_241 ( V_202 , V_204 , & V_32 , - 1 , 0 ) ;
}
void F_250 ( struct V_179 * V_202 ,
T_5 V_204 )
{
F_241 ( V_202 , V_204 , V_31 , - 1 , 1 ) ;
}
static inline int F_251 ( void )
{
int V_76 ;
F_252 () ;
F_40 () ;
V_76 = F_253 () <= 1 ;
F_41 () ;
return V_76 ;
}
void F_254 ( void )
{
F_76 ( F_77 ( & V_69 ) ||
F_77 ( & V_68 ) ||
F_77 ( & V_70 ) ,
L_60 ) ;
if ( F_251 () )
return;
if ( F_255 () )
F_256 () ;
else
F_257 ( F_248 ) ;
}
void F_258 ( void )
{
F_76 ( F_77 ( & V_69 ) ||
F_77 ( & V_68 ) ||
F_77 ( & V_70 ) ,
L_61 ) ;
if ( F_251 () )
return;
if ( F_255 () )
F_259 () ;
else
F_257 ( F_249 ) ;
}
unsigned long F_260 ( void )
{
F_31 () ;
return F_261 ( & V_31 -> V_7 ) ;
}
void F_262 ( unsigned long V_207 )
{
unsigned long V_208 ;
V_208 = F_261 ( & V_31 -> V_6 ) ;
if ( F_141 ( V_207 , V_208 ) )
F_263 () ;
}
unsigned long F_264 ( void )
{
F_31 () ;
return F_261 ( & V_13 . V_7 ) ;
}
void F_265 ( unsigned long V_207 )
{
unsigned long V_208 ;
V_208 = F_261 ( & V_13 . V_6 ) ;
if ( F_141 ( V_207 , V_208 ) )
F_254 () ;
}
static void F_266 ( unsigned long * V_209 )
{
F_106 ( * V_209 , * V_209 + 1 ) ;
F_31 () ;
F_14 ( ! ( * V_209 & 0x1 ) ) ;
}
static void F_267 ( unsigned long * V_209 )
{
F_31 () ;
F_106 ( * V_209 , * V_209 + 1 ) ;
F_14 ( * V_209 & 0x1 ) ;
}
static unsigned long F_268 ( unsigned long * V_209 )
{
unsigned long V_10 ;
V_10 = ( F_2 ( * V_209 ) + 3 ) & ~ 0x1 ;
F_31 () ;
return V_10 ;
}
static bool F_269 ( unsigned long * V_209 , unsigned long V_10 )
{
return F_141 ( F_2 ( * V_209 ) , V_10 ) ;
}
static int F_270 ( struct V_4 * V_5 , struct V_21 * V_22 )
{
struct V_1 * V_2 = V_22 -> V_27 ;
V_22 -> V_210 ++ ;
F_142 ( V_5 , V_22 ) ;
if ( F_271 ( V_5 ) )
return 0 ;
if ( V_78 &&
V_22 -> V_130 && V_22 -> V_9 . V_11 . V_12 &&
V_22 -> V_92 == F_5 ( V_30 ) ) {
V_22 -> V_211 ++ ;
} else if ( V_22 -> V_130 && ! V_22 -> V_9 . V_11 . V_12 ) {
V_22 -> V_212 ++ ;
return 1 ;
}
if ( F_60 ( V_22 ) ) {
V_22 -> V_213 ++ ;
return 1 ;
}
if ( F_63 ( V_5 , V_22 ) ) {
V_22 -> V_214 ++ ;
return 1 ;
}
if ( F_2 ( V_2 -> V_6 ) != V_22 -> V_6 ) {
V_22 -> V_215 ++ ;
return 1 ;
}
if ( F_2 ( V_2 -> V_7 ) != V_22 -> V_7 ||
F_36 ( F_2 ( V_22 -> V_84 ) ) ) {
V_22 -> V_216 ++ ;
return 1 ;
}
if ( F_272 ( V_22 ) ) {
V_22 -> V_217 ++ ;
return 1 ;
}
V_22 -> V_218 ++ ;
return 0 ;
}
static int F_225 ( void )
{
struct V_4 * V_5 ;
F_29 (rsp)
if ( F_270 ( V_5 , F_10 ( V_5 -> V_25 ) ) )
return 1 ;
return 0 ;
}
static bool V_64 F_273 ( bool * V_219 )
{
bool V_220 = true ;
bool V_221 = false ;
struct V_21 * V_22 ;
struct V_4 * V_5 ;
F_29 (rsp) {
V_22 = F_10 ( V_5 -> V_25 ) ;
if ( ! V_22 -> V_47 )
continue;
V_221 = true ;
if ( V_22 -> V_114 != V_22 -> V_170 || ! V_219 ) {
V_220 = false ;
break;
}
}
if ( V_219 )
* V_219 = V_220 ;
return V_221 ;
}
static void F_274 ( struct V_4 * V_5 , const char * V_10 ,
int V_82 , unsigned long V_222 )
{
F_275 ( V_5 -> V_34 , V_10 , V_82 ,
F_18 ( & V_5 -> V_223 ) , V_222 ) ;
}
static void F_276 ( struct V_179 * V_203 )
{
struct V_21 * V_22 = F_277 ( V_203 , struct V_21 , V_224 ) ;
struct V_4 * V_5 = V_22 -> V_5 ;
if ( F_278 ( & V_5 -> V_223 ) ) {
F_274 ( V_5 , L_62 , - 1 , V_5 -> V_225 ) ;
F_279 ( & V_5 -> V_226 ) ;
} else {
F_274 ( V_5 , L_63 , - 1 , V_5 -> V_225 ) ;
}
}
static void F_280 ( void * type )
{
struct V_4 * V_5 = type ;
struct V_21 * V_22 = F_30 ( V_5 -> V_25 ) ;
F_274 ( V_5 , L_64 , - 1 , V_5 -> V_225 ) ;
F_281 ( & V_5 -> V_223 ) ;
V_5 -> V_227 ( & V_22 -> V_224 , F_276 ) ;
}
static void F_282 ( struct V_4 * V_5 )
{
int V_82 ;
struct V_21 * V_22 ;
unsigned long V_10 = F_268 ( & V_5 -> V_225 ) ;
F_274 ( V_5 , L_65 , - 1 , V_10 ) ;
F_283 ( & V_5 -> V_228 ) ;
if ( F_269 ( & V_5 -> V_225 , V_10 ) ) {
F_274 ( V_5 , L_66 , - 1 , V_5 -> V_225 ) ;
F_31 () ;
F_284 ( & V_5 -> V_228 ) ;
return;
}
F_266 ( & V_5 -> V_225 ) ;
F_274 ( V_5 , L_67 , - 1 , V_5 -> V_225 ) ;
F_285 ( & V_5 -> V_226 ) ;
F_286 ( & V_5 -> V_223 , 1 ) ;
F_287 () ;
F_136 (cpu) {
if ( ! F_236 ( V_82 ) && ! F_202 ( V_82 ) )
continue;
V_22 = F_137 ( V_5 -> V_25 , V_82 ) ;
if ( F_202 ( V_82 ) ) {
if ( ! F_288 ( V_5 , V_82 ) ) {
F_274 ( V_5 , L_68 , V_82 ,
V_5 -> V_225 ) ;
} else {
F_274 ( V_5 , L_69 , V_82 ,
V_5 -> V_225 ) ;
F_289 () ;
F_281 ( & V_5 -> V_223 ) ;
F_241 ( & V_22 -> V_224 ,
F_276 , V_5 , V_82 , 0 ) ;
}
} else if ( F_2 ( V_22 -> V_114 ) ) {
F_274 ( V_5 , L_70 , V_82 ,
V_5 -> V_225 ) ;
F_290 ( V_82 , F_280 , V_5 , 1 ) ;
} else {
F_274 ( V_5 , L_71 , V_82 ,
V_5 -> V_225 ) ;
}
}
F_291 () ;
if ( F_278 ( & V_5 -> V_223 ) )
F_279 ( & V_5 -> V_226 ) ;
F_292 ( & V_5 -> V_226 ) ;
F_274 ( V_5 , L_72 , - 1 , V_5 -> V_225 ) ;
F_267 ( & V_5 -> V_225 ) ;
F_284 ( & V_5 -> V_228 ) ;
}
void F_293 ( void )
{
F_282 ( & V_32 ) ;
}
void F_294 ( void )
{
F_282 ( & V_13 ) ;
}
static void F_170 ( struct V_1 * V_177 )
{
long V_163 ;
struct V_1 * V_2 = V_177 ;
for (; ; ) {
V_163 = V_2 -> V_77 ;
V_2 = V_2 -> V_167 ;
if ( V_2 == NULL )
return;
F_152 ( V_2 ) ;
V_2 -> V_137 |= V_163 ;
F_154 ( V_2 ) ;
}
}
static void T_6
F_295 ( int V_82 , struct V_4 * V_5 )
{
unsigned long V_29 ;
struct V_21 * V_22 = F_137 ( V_5 -> V_25 , V_82 ) ;
struct V_1 * V_2 = F_61 ( V_5 ) ;
F_122 ( V_2 , V_29 ) ;
V_22 -> V_77 = F_124 ( V_22 -> V_27 , V_82 ) ;
V_22 -> V_18 = & F_110 ( V_15 , V_82 ) ;
F_14 ( V_22 -> V_18 -> V_61 != V_73 ) ;
F_14 ( F_23 ( F_21 ( V_22 -> V_18 ) ) ) ;
V_22 -> V_82 = V_82 ;
V_22 -> V_5 = V_5 ;
F_296 ( V_22 ) ;
F_127 ( V_2 , V_29 ) ;
}
static void
F_297 ( int V_82 , struct V_4 * V_5 )
{
unsigned long V_29 ;
struct V_21 * V_22 = F_137 ( V_5 -> V_25 , V_82 ) ;
struct V_1 * V_2 = F_61 ( V_5 ) ;
F_122 ( V_2 , V_29 ) ;
V_22 -> V_190 = 0 ;
V_22 -> V_191 = V_5 -> V_98 ;
V_22 -> V_186 = V_186 ;
if ( ! V_22 -> V_47 )
F_146 ( V_22 ) ;
V_22 -> V_18 -> V_61 = V_73 ;
F_298 ( V_22 -> V_18 ) ;
F_17 () ;
F_154 ( V_2 ) ;
V_2 = V_22 -> V_27 ;
F_152 ( V_2 ) ;
if ( ! V_22 -> V_197 )
F_106 ( V_5 -> V_229 , F_2 ( V_5 -> V_229 ) + 1 ) ;
V_22 -> V_197 = true ;
V_22 -> V_7 = V_2 -> V_6 ;
V_22 -> V_6 = V_2 -> V_6 ;
V_22 -> V_9 . V_11 . V_12 = true ;
V_22 -> V_92 = F_110 ( V_30 , V_82 ) ;
V_22 -> V_130 = false ;
F_6 ( V_5 -> V_34 , V_22 -> V_7 , F_7 ( L_73 ) ) ;
F_127 ( V_2 , V_29 ) ;
}
int F_299 ( unsigned int V_82 )
{
struct V_4 * V_5 ;
F_29 (rsp)
F_297 ( V_82 , V_5 ) ;
F_300 ( V_82 ) ;
F_301 ( V_82 ) ;
return 0 ;
}
static void F_302 ( unsigned int V_82 , int V_230 )
{
struct V_21 * V_22 = F_137 ( V_31 -> V_25 , V_82 ) ;
F_208 ( V_22 -> V_27 , V_230 ) ;
}
int F_303 ( unsigned int V_82 )
{
F_304 ( V_82 ) ;
F_302 ( V_82 , - 1 ) ;
return 0 ;
}
int F_305 ( unsigned int V_82 )
{
F_302 ( V_82 , V_82 ) ;
return 0 ;
}
int F_306 ( unsigned int V_82 )
{
struct V_4 * V_5 ;
F_29 (rsp)
F_206 ( V_5 ) ;
return 0 ;
}
int F_307 ( unsigned int V_82 )
{
struct V_4 * V_5 ;
F_29 (rsp) {
F_207 ( V_82 , V_5 ) ;
F_73 ( F_137 ( V_5 -> V_25 , V_82 ) ) ;
}
return 0 ;
}
void F_308 ( unsigned int V_82 )
{
unsigned long V_29 ;
unsigned long V_163 ;
struct V_21 * V_22 ;
struct V_1 * V_2 ;
struct V_4 * V_5 ;
F_29 (rsp) {
V_22 = F_137 ( V_5 -> V_25 , V_82 ) ;
V_2 = V_22 -> V_27 ;
V_163 = V_22 -> V_77 ;
F_122 ( V_2 , V_29 ) ;
V_2 -> V_3 |= V_163 ;
V_2 -> V_231 |= V_163 ;
F_127 ( V_2 , V_29 ) ;
}
}
static void F_309 ( int V_82 , struct V_4 * V_5 )
{
unsigned long V_29 ;
unsigned long V_163 ;
struct V_21 * V_22 = F_137 ( V_5 -> V_25 , V_82 ) ;
struct V_1 * V_2 = V_22 -> V_27 ;
V_163 = V_22 -> V_77 ;
F_122 ( V_2 , V_29 ) ;
V_2 -> V_3 &= ~ V_163 ;
F_127 ( V_2 , V_29 ) ;
}
void F_310 ( unsigned int V_82 )
{
struct V_4 * V_5 ;
F_40 () ;
F_9 ( & V_13 ,
F_10 ( V_13 . V_25 ) , true ) ;
F_41 () ;
F_29 (rsp)
F_309 ( V_82 , V_5 ) ;
}
static int F_311 ( struct V_232 * V_233 ,
unsigned long V_234 , void * V_235 )
{
switch ( V_234 ) {
case V_236 :
case V_237 :
if ( V_238 <= 256 )
F_312 () ;
break;
case V_239 :
case V_240 :
if ( V_238 <= 256 )
F_313 () ;
break;
default:
break;
}
return V_241 ;
}
static int T_6 F_314 ( void )
{
unsigned long V_29 ;
int V_242 = V_243 ;
struct V_1 * V_2 ;
struct V_4 * V_5 ;
struct V_244 V_209 ;
struct V_63 * V_245 ;
if ( F_15 ( V_246 ) && V_243 < 1 )
V_243 = 1 ;
else if ( V_243 < 0 )
V_243 = 0 ;
else if ( V_243 > 99 )
V_243 = 99 ;
if ( V_243 != V_242 )
F_315 ( L_74 ,
V_243 , V_242 ) ;
V_78 = 1 ;
F_29 (rsp) {
V_245 = F_316 ( F_188 , V_5 , L_75 , V_5 -> V_34 ) ;
F_244 ( F_317 ( V_245 ) ) ;
V_2 = F_61 ( V_5 ) ;
F_122 ( V_2 , V_29 ) ;
V_5 -> V_36 = V_245 ;
if ( V_243 ) {
V_209 . V_247 = V_243 ;
F_318 ( V_245 , V_248 , & V_209 ) ;
}
F_127 ( V_2 , V_29 ) ;
F_119 ( V_245 ) ;
}
F_319 () ;
F_320 () ;
return 0 ;
}
void F_321 ( void )
{
F_191 ( F_253 () != 1 ) ;
F_191 ( F_322 () > 0 ) ;
F_323 () ;
V_249 = V_250 ;
F_323 () ;
}
static void T_6 F_324 ( int * V_251 , const int * V_252 )
{
int V_55 ;
if ( V_253 ) {
V_251 [ V_254 - 1 ] = V_255 ;
for ( V_55 = V_254 - 2 ; V_55 >= 0 ; V_55 -- )
V_251 [ V_55 ] = V_256 ;
} else {
int V_257 ;
int V_258 ;
V_258 = V_238 ;
for ( V_55 = V_254 - 1 ; V_55 >= 0 ; V_55 -- ) {
V_257 = V_252 [ V_55 ] ;
V_251 [ V_55 ] = ( V_258 + V_257 - 1 ) / V_257 ;
V_258 = V_257 ;
}
}
}
static void T_6 F_325 ( struct V_4 * V_5 )
{
static const char * const V_259 [] = V_260 ;
static const char * const V_261 [] = V_262 ;
static struct V_263 V_264 [ V_265 ] ;
static struct V_263 V_266 [ V_265 ] ;
static T_7 V_267 = 0x1 ;
int V_252 [ V_265 ] ;
int V_251 [ V_265 ] ;
int V_268 = 1 ;
int V_55 ;
int V_95 ;
struct V_1 * V_2 ;
F_326 ( V_265 > F_115 ( V_259 ) ) ;
if ( V_254 <= 0 || V_254 > V_265 )
F_130 ( L_76 ) ;
for ( V_55 = 0 ; V_55 < V_254 ; V_55 ++ )
V_252 [ V_55 ] = V_269 [ V_55 ] ;
for ( V_55 = 1 ; V_55 < V_254 ; V_55 ++ )
V_5 -> V_120 [ V_55 ] = V_5 -> V_120 [ V_55 - 1 ] + V_252 [ V_55 - 1 ] ;
F_324 ( V_251 , V_252 ) ;
V_5 -> V_26 = V_267 ;
V_267 <<= 1 ;
for ( V_55 = V_254 - 1 ; V_55 >= 0 ; V_55 -- ) {
V_268 *= V_251 [ V_55 ] ;
V_2 = V_5 -> V_120 [ V_55 ] ;
for ( V_95 = 0 ; V_95 < V_252 [ V_55 ] ; V_95 ++ , V_2 ++ ) {
F_327 ( & F_328 ( V_2 , V_164 ) ) ;
F_329 ( & F_328 ( V_2 , V_164 ) ,
& V_264 [ V_55 ] , V_259 [ V_55 ] ) ;
F_327 ( & V_2 -> V_195 ) ;
F_329 ( & V_2 -> V_195 ,
& V_266 [ V_55 ] , V_261 [ V_55 ] ) ;
V_2 -> V_7 = V_5 -> V_7 ;
V_2 -> V_6 = V_5 -> V_6 ;
V_2 -> V_104 = 0 ;
V_2 -> V_137 = 0 ;
V_2 -> V_121 = V_95 * V_268 ;
V_2 -> V_122 = ( V_95 + 1 ) * V_268 - 1 ;
if ( V_2 -> V_122 >= V_238 )
V_2 -> V_122 = V_238 - 1 ;
if ( V_55 == 0 ) {
V_2 -> V_270 = 0 ;
V_2 -> V_77 = 0 ;
V_2 -> V_167 = NULL ;
} else {
V_2 -> V_270 = V_95 % V_251 [ V_55 - 1 ] ;
V_2 -> V_77 = 1UL << V_2 -> V_270 ;
V_2 -> V_167 = V_5 -> V_120 [ V_55 - 1 ] +
V_95 / V_251 [ V_55 - 1 ] ;
}
V_2 -> V_120 = V_55 ;
F_330 ( & V_2 -> V_271 ) ;
F_331 ( V_2 ) ;
F_332 ( & V_2 -> V_272 [ 0 ] ) ;
F_332 ( & V_2 -> V_272 [ 1 ] ) ;
F_332 ( & V_2 -> V_272 [ 2 ] ) ;
F_332 ( & V_2 -> V_272 [ 3 ] ) ;
F_333 ( & V_2 -> V_273 ) ;
}
}
F_334 ( & V_5 -> V_128 ) ;
F_334 ( & V_5 -> V_274 ) ;
V_2 = V_5 -> V_120 [ V_254 - 1 ] ;
F_136 (i) {
while ( V_55 > V_2 -> V_122 )
V_2 ++ ;
F_137 ( V_5 -> V_25 , V_55 ) -> V_27 = V_2 ;
F_295 ( V_55 , V_5 ) ;
}
F_335 ( & V_5 -> V_275 , & V_276 ) ;
}
static void T_6 F_336 ( void )
{
T_8 V_277 ;
int V_55 ;
int V_278 [ V_265 ] ;
V_277 = V_279 + V_238 / V_280 ;
if ( V_157 == V_83 )
V_157 = V_277 ;
if ( V_115 == V_83 )
V_115 = V_277 ;
if ( V_255 == V_281 &&
V_238 == V_282 )
return;
F_56 ( L_77 ,
V_255 , V_238 ) ;
if ( V_255 < 2 ||
V_255 > sizeof( unsigned long ) * 8 ) {
V_255 = V_281 ;
F_191 ( 1 ) ;
return;
}
V_278 [ 0 ] = V_255 ;
for ( V_55 = 1 ; V_55 < V_265 ; V_55 ++ )
V_278 [ V_55 ] = V_278 [ V_55 - 1 ] * V_256 ;
if ( V_238 > V_278 [ V_265 - 1 ] ) {
V_255 = V_281 ;
F_191 ( 1 ) ;
return;
}
for ( V_55 = 0 ; V_238 > V_278 [ V_55 ] ; V_55 ++ ) {
}
V_254 = V_55 + 1 ;
for ( V_55 = 0 ; V_55 < V_254 ; V_55 ++ ) {
int V_283 = V_278 [ ( V_254 - 1 ) - V_55 ] ;
V_269 [ V_55 ] = F_337 ( V_238 , V_283 ) ;
}
V_133 = 0 ;
for ( V_55 = 0 ; V_55 < V_254 ; V_55 ++ )
V_133 += V_269 [ V_55 ] ;
}
static void T_6 F_338 ( struct V_4 * V_5 )
{
int V_120 = 0 ;
struct V_1 * V_2 ;
F_56 ( L_78 ) ;
F_56 ( L_79 ) ;
F_173 (rsp, rnp) {
if ( V_2 -> V_120 != V_120 ) {
F_138 ( L_80 ) ;
F_56 ( L_79 ) ;
V_120 = V_2 -> V_120 ;
}
F_138 ( L_81 , V_2 -> V_121 , V_2 -> V_122 , V_2 -> V_270 ) ;
}
F_138 ( L_80 ) ;
}
void T_6 F_339 ( void )
{
int V_82 ;
F_340 () ;
F_341 () ;
F_336 () ;
F_325 ( & V_32 ) ;
F_325 ( & V_13 ) ;
if ( V_284 )
F_338 ( & V_13 ) ;
F_342 () ;
F_343 ( V_201 , F_233 ) ;
F_344 ( F_311 , 0 ) ;
F_345 (cpu) {
F_299 ( V_82 ) ;
F_308 ( V_82 ) ;
}
}
