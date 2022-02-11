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
struct V_15 * V_16 ;
struct V_17 * V_18 ;
int V_19 ;
struct V_4 * V_5 ;
V_19 = F_13 ( V_20 ) ;
F_14 ( V_20 , 0 ) ;
F_15 (rsp) {
V_16 = F_16 ( V_5 -> V_21 ) ;
if ( ! ( V_19 & V_5 -> V_22 ) )
continue;
F_17 () ;
if ( F_2 ( V_16 -> V_23 -> V_6 ) !=
F_2 ( V_16 -> V_24 ) )
continue;
V_18 = F_10 ( & V_17 ) ;
F_18 () ;
F_19 ( 2 , & V_18 -> V_25 ) ;
F_20 () ;
break;
}
}
void F_21 ( void )
{
F_22 () ;
F_23 ( F_7 ( L_4 ) ) ;
F_4 () ;
F_24 () ;
if ( F_25 ( F_13 ( V_20 ) ) )
F_12 () ;
F_23 ( F_7 ( L_5 ) ) ;
F_22 () ;
}
void F_26 ( void )
{
unsigned long V_26 ;
F_22 () ;
if ( F_25 ( F_13 ( V_20 ) ) ) {
F_27 ( V_26 ) ;
F_12 () ;
F_28 ( V_26 ) ;
}
F_29 ( V_27 ) ;
F_22 () ;
}
unsigned long F_30 ( void )
{
return V_28 -> V_7 ;
}
unsigned long F_31 ( void )
{
return V_13 . V_7 ;
}
unsigned long F_32 ( void )
{
return V_29 . V_7 ;
}
unsigned long F_33 ( void )
{
return V_28 -> V_6 ;
}
unsigned long F_34 ( void )
{
return V_13 . V_6 ;
}
unsigned long F_35 ( void )
{
return V_29 . V_6 ;
}
void F_36 ( void )
{
F_37 ( V_28 ) ;
}
void F_38 ( void )
{
F_37 ( & V_29 ) ;
}
void F_39 ( void )
{
F_37 ( & V_13 ) ;
}
void F_40 ( void )
{
struct V_4 * V_5 ;
F_15 (rsp) {
F_41 ( L_6 ,
V_5 -> V_30 , V_5 -> V_31 , V_5 -> V_32 -> V_33 ) ;
}
}
void F_42 ( void )
{
V_34 ++ ;
V_35 = 0 ;
}
void F_43 ( enum V_36 V_37 , int * V_26 ,
unsigned long * V_7 , unsigned long * V_6 )
{
struct V_4 * V_5 = NULL ;
switch ( V_37 ) {
case V_38 :
V_5 = V_28 ;
break;
case V_39 :
V_5 = & V_29 ;
break;
case V_40 :
V_5 = & V_13 ;
break;
default:
break;
}
if ( V_5 != NULL ) {
* V_26 = F_2 ( V_5 -> V_41 ) ;
* V_7 = F_2 ( V_5 -> V_7 ) ;
* V_6 = F_2 ( V_5 -> V_6 ) ;
return;
}
* V_26 = 0 ;
* V_7 = 0 ;
* V_6 = 0 ;
}
void F_44 ( unsigned long V_42 )
{
V_35 ++ ;
}
static int
F_45 ( struct V_15 * V_16 )
{
return & V_16 -> V_43 != V_16 -> V_44 [ V_45 ] &&
V_16 -> V_44 [ V_45 ] != NULL ;
}
static struct V_1 * F_46 ( struct V_4 * V_5 )
{
return & V_5 -> V_46 [ 0 ] ;
}
static int F_47 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = F_46 ( V_5 ) ;
int V_47 = ( F_2 ( V_2 -> V_6 ) + 1 ) & 0x1 ;
int * V_48 = & V_2 -> V_49 [ V_47 ] ;
return F_2 ( * V_48 ) ;
}
static bool
F_48 ( struct V_4 * V_5 , struct V_15 * V_16 )
{
int V_50 ;
if ( F_3 ( V_5 ) )
return false ;
if ( F_47 ( V_5 ) )
return true ;
if ( ! V_16 -> V_44 [ V_51 ] )
return false ;
if ( * V_16 -> V_44 [ V_52 ] )
return true ;
for ( V_50 = V_53 ; V_50 < V_51 ; V_50 ++ )
if ( V_16 -> V_44 [ V_50 - 1 ] != V_16 -> V_44 [ V_50 ] &&
F_49 ( F_2 ( V_5 -> V_6 ) ,
V_16 -> V_54 [ V_50 ] ) )
return true ;
return false ;
}
static void F_50 ( long long V_55 , bool V_56 )
{
struct V_4 * V_5 ;
struct V_15 * V_16 ;
struct V_17 * V_18 = F_10 ( & V_17 ) ;
F_51 ( F_7 ( L_7 ) , V_55 , V_18 -> V_57 ) ;
if ( F_52 ( V_58 ) &&
! V_56 && ! F_53 ( V_59 ) ) {
struct V_60 * T_1 V_61 =
F_54 ( F_55 () ) ;
F_51 ( F_7 ( L_8 ) , V_55 , 0 ) ;
F_56 ( V_62 ) ;
F_57 ( 1 , L_9 ,
V_59 -> V_63 , V_59 -> V_64 ,
T_1 -> V_63 , T_1 -> V_64 ) ;
}
F_15 (rsp) {
V_16 = F_10 ( V_5 -> V_21 ) ;
F_58 ( V_16 ) ;
}
F_59 () ;
F_18 () ;
F_60 ( & V_18 -> V_25 ) ;
F_20 () ;
F_61 ( F_52 ( V_58 ) &&
F_62 ( & V_18 -> V_25 ) & 0x1 ) ;
F_63 () ;
F_64 ( F_65 ( & V_65 ) ,
L_10 ) ;
F_64 ( F_65 ( & V_66 ) ,
L_11 ) ;
F_64 ( F_65 ( & V_67 ) ,
L_12 ) ;
}
static void F_66 ( bool V_56 )
{
long long V_55 ;
struct V_17 * V_18 ;
V_18 = F_10 ( & V_17 ) ;
V_55 = V_18 -> V_57 ;
F_61 ( F_52 ( V_58 ) &&
( V_55 & V_68 ) == 0 ) ;
if ( ( V_55 & V_68 ) == V_69 ) {
V_18 -> V_57 = 0 ;
F_50 ( V_55 , V_56 ) ;
} else {
V_18 -> V_57 -= V_69 ;
}
}
void F_67 ( void )
{
unsigned long V_26 ;
F_27 ( V_26 ) ;
F_66 ( false ) ;
F_68 ( 0 ) ;
F_28 ( V_26 ) ;
}
void F_69 ( void )
{
F_66 ( 1 ) ;
}
void F_70 ( void )
{
long long V_55 ;
struct V_17 * V_18 ;
F_64 ( ! F_71 () , L_13 ) ;
V_18 = F_10 ( & V_17 ) ;
V_55 = V_18 -> V_57 ;
V_18 -> V_57 -- ;
F_61 ( F_52 ( V_58 ) &&
V_18 -> V_57 < 0 ) ;
if ( V_18 -> V_57 )
F_51 ( F_7 ( L_14 ) , V_55 , V_18 -> V_57 ) ;
else
F_50 ( V_55 , true ) ;
F_68 ( 1 ) ;
}
void F_72 ( void )
{
unsigned long V_26 ;
F_27 ( V_26 ) ;
F_70 () ;
F_28 ( V_26 ) ;
}
static void F_73 ( long long V_55 , int V_56 )
{
struct V_17 * V_18 = F_10 ( & V_17 ) ;
F_74 () ;
F_18 () ;
F_60 ( & V_18 -> V_25 ) ;
F_20 () ;
F_61 ( F_52 ( V_58 ) &&
! ( F_62 ( & V_18 -> V_25 ) & 0x1 ) ) ;
F_75 () ;
F_51 ( F_7 ( L_15 ) , V_55 , V_18 -> V_57 ) ;
if ( F_52 ( V_58 ) &&
! V_56 && ! F_53 ( V_59 ) ) {
struct V_60 * T_1 V_61 =
F_54 ( F_55 () ) ;
F_51 ( F_7 ( L_16 ) ,
V_55 , V_18 -> V_57 ) ;
F_56 ( V_62 ) ;
F_57 ( 1 , L_9 ,
V_59 -> V_63 , V_59 -> V_64 ,
T_1 -> V_63 , T_1 -> V_64 ) ;
}
}
static void F_76 ( bool V_56 )
{
struct V_17 * V_18 ;
long long V_55 ;
V_18 = F_10 ( & V_17 ) ;
V_55 = V_18 -> V_57 ;
F_61 ( F_52 ( V_58 ) && V_55 < 0 ) ;
if ( V_55 & V_68 ) {
V_18 -> V_57 += V_69 ;
} else {
V_18 -> V_57 = V_70 ;
F_73 ( V_55 , V_56 ) ;
}
}
void F_77 ( void )
{
unsigned long V_26 ;
F_27 ( V_26 ) ;
F_76 ( false ) ;
F_78 ( 0 ) ;
F_28 ( V_26 ) ;
}
void F_79 ( void )
{
F_76 ( 1 ) ;
}
void F_80 ( void )
{
struct V_17 * V_18 ;
long long V_55 ;
F_64 ( ! F_71 () , L_17 ) ;
V_18 = F_10 ( & V_17 ) ;
V_55 = V_18 -> V_57 ;
V_18 -> V_57 ++ ;
F_61 ( F_52 ( V_58 ) &&
V_18 -> V_57 == 0 ) ;
if ( V_55 )
F_51 ( F_7 ( L_18 ) , V_55 , V_18 -> V_57 ) ;
else
F_73 ( V_55 , true ) ;
F_78 ( 1 ) ;
}
void F_81 ( void )
{
unsigned long V_26 ;
F_27 ( V_26 ) ;
F_80 () ;
F_28 ( V_26 ) ;
}
void F_82 ( void )
{
struct V_17 * V_18 = F_10 ( & V_17 ) ;
int V_71 = 2 ;
F_61 ( V_18 -> V_72 < 0 ) ;
if ( ! ( F_62 ( & V_18 -> V_25 ) & 0x1 ) ) {
F_18 () ;
F_60 ( & V_18 -> V_25 ) ;
F_20 () ;
F_61 ( ! ( F_62 ( & V_18 -> V_25 ) & 0x1 ) ) ;
V_71 = 1 ;
}
V_18 -> V_72 += V_71 ;
F_22 () ;
}
void F_83 ( void )
{
struct V_17 * V_18 = F_10 ( & V_17 ) ;
F_61 ( V_18 -> V_72 <= 0 ) ;
F_61 ( ! ( F_62 ( & V_18 -> V_25 ) & 0x1 ) ) ;
if ( V_18 -> V_72 != 1 ) {
V_18 -> V_72 -= 2 ;
return;
}
V_18 -> V_72 = 0 ;
F_18 () ;
F_60 ( & V_18 -> V_25 ) ;
F_20 () ;
F_61 ( F_62 ( & V_18 -> V_25 ) & 0x1 ) ;
}
bool T_2 F_84 ( void )
{
return F_62 ( F_10 ( & V_17 . V_25 ) ) & 0x1 ;
}
bool T_2 F_85 ( void )
{
bool V_73 ;
F_86 () ;
V_73 = F_84 () ;
F_87 () ;
return V_73 ;
}
bool F_88 ( void )
{
struct V_15 * V_16 ;
struct V_1 * V_2 ;
bool V_73 ;
if ( F_89 () )
return true ;
F_90 () ;
V_16 = F_10 ( & V_8 ) ;
V_2 = V_16 -> V_23 ;
V_73 = ( V_16 -> V_74 & F_1 ( V_2 ) ) ||
! V_75 ;
F_91 () ;
return V_73 ;
}
static int F_92 ( void )
{
return F_5 ( V_17 . V_57 ) <= 1 ;
}
static int F_93 ( struct V_15 * V_16 ,
bool * V_76 , unsigned long * V_77 )
{
V_16 -> V_78 = F_94 ( 0 , & V_16 -> V_25 -> V_25 ) ;
F_95 ( V_16 , V_76 , V_77 ) ;
if ( ( V_16 -> V_78 & 0x1 ) == 0 ) {
F_96 ( V_16 -> V_5 -> V_30 , V_16 -> V_7 , V_16 -> V_79 , F_7 ( L_19 ) ) ;
if ( F_49 ( F_2 ( V_16 -> V_7 ) + V_80 / 4 ,
V_16 -> V_23 -> V_7 ) )
F_97 ( V_16 -> V_81 , true ) ;
return 1 ;
}
return 0 ;
}
static int F_98 ( struct V_15 * V_16 ,
bool * V_76 , unsigned long * V_77 )
{
unsigned int V_82 ;
int * V_83 ;
unsigned int V_84 ;
V_82 = ( unsigned int ) F_94 ( 0 , & V_16 -> V_25 -> V_25 ) ;
V_84 = ( unsigned int ) V_16 -> V_78 ;
if ( ( V_82 & 0x1 ) == 0 || F_99 ( V_82 , V_84 + 2 ) ) {
F_96 ( V_16 -> V_5 -> V_30 , V_16 -> V_7 , V_16 -> V_79 , F_7 ( L_19 ) ) ;
V_16 -> V_85 ++ ;
return 1 ;
}
if ( F_100 ( V_16 -> V_5 -> V_86 + 2 , V_87 ) )
return 0 ;
F_22 () ;
if ( F_101 ( V_16 -> V_79 ) ) {
F_96 ( V_16 -> V_5 -> V_30 , V_16 -> V_7 , V_16 -> V_79 , F_7 ( L_20 ) ) ;
V_16 -> V_88 ++ ;
return 1 ;
}
V_83 = & F_102 ( V_20 , V_16 -> V_79 ) ;
if ( F_100 ( V_87 ,
V_16 -> V_5 -> V_86 + V_89 ) ||
F_100 ( V_87 , V_16 -> V_5 -> V_90 ) ) {
if ( ! ( F_2 ( * V_83 ) & V_16 -> V_5 -> V_22 ) ) {
F_97 ( V_16 -> V_24 ,
F_2 ( V_16 -> V_23 -> V_6 ) ) ;
F_17 () ;
F_97 ( * V_83 ,
F_2 ( * V_83 ) + V_16 -> V_5 -> V_22 ) ;
}
V_16 -> V_5 -> V_90 += 5 ;
}
if ( F_100 ( V_87 ,
V_16 -> V_5 -> V_86 + 2 * V_89 ) ||
F_100 ( V_87 , V_16 -> V_5 -> V_86 + V_89 ) )
F_103 ( V_16 -> V_79 ) ;
return 0 ;
}
static void F_104 ( struct V_4 * V_5 )
{
unsigned long V_91 = V_87 ;
unsigned long j1 ;
V_5 -> V_86 = V_91 ;
F_105 () ;
j1 = F_106 () ;
F_97 ( V_5 -> V_92 , V_91 + j1 ) ;
V_5 -> V_90 = V_91 + j1 / 2 ;
V_5 -> V_93 = F_2 ( V_5 -> V_94 ) ;
}
static const char * F_107 ( short V_95 )
{
if ( V_95 < 0 || V_95 >= F_108 ( V_96 ) )
return L_21 ;
return V_96 [ V_95 ] ;
}
static void F_109 ( struct V_4 * V_5 )
{
unsigned long V_97 ;
unsigned long V_91 ;
V_91 = V_87 ;
V_97 = F_2 ( V_5 -> V_98 ) ;
if ( V_91 - V_97 > 2 * V_99 ) {
F_110 ( L_22 ,
V_5 -> V_30 , V_91 - V_97 ,
V_5 -> V_7 , V_5 -> V_6 ,
V_5 -> V_41 ,
F_107 ( V_5 -> V_31 ) , V_5 -> V_31 ,
V_5 -> V_32 ? V_5 -> V_32 -> V_33 : ~ 0 ) ;
if ( V_5 -> V_32 )
F_111 ( V_5 -> V_32 ) ;
}
}
static void F_112 ( struct V_4 * V_5 )
{
int V_79 ;
unsigned long V_26 ;
struct V_1 * V_2 ;
F_113 (rsp, rnp) {
F_114 ( V_2 , V_26 ) ;
if ( V_2 -> V_100 != 0 ) {
for ( V_79 = 0 ; V_79 <= V_2 -> V_101 - V_2 -> V_102 ; V_79 ++ )
if ( V_2 -> V_100 & ( 1UL << V_79 ) )
F_115 ( V_2 -> V_102 + V_79 ) ;
}
F_116 ( V_2 , V_26 ) ;
}
}
static void F_117 ( struct V_4 * V_5 , unsigned long V_7 )
{
int V_79 ;
long V_103 ;
unsigned long V_26 ;
unsigned long V_97 ;
unsigned long V_91 ;
int V_104 = 0 ;
struct V_1 * V_2 = F_46 ( V_5 ) ;
long V_105 = 0 ;
F_114 ( V_2 , V_26 ) ;
V_103 = V_87 - F_2 ( V_5 -> V_92 ) ;
if ( V_103 < V_106 || ! F_3 ( V_5 ) ) {
F_116 ( V_2 , V_26 ) ;
return;
}
F_97 ( V_5 -> V_92 ,
V_87 + 3 * F_106 () + 3 ) ;
F_116 ( V_2 , V_26 ) ;
F_110 ( L_23 ,
V_5 -> V_30 ) ;
F_118 () ;
F_113 (rsp, rnp) {
F_114 ( V_2 , V_26 ) ;
V_104 += F_119 ( V_2 ) ;
if ( V_2 -> V_100 != 0 ) {
for ( V_79 = 0 ; V_79 <= V_2 -> V_101 - V_2 -> V_102 ; V_79 ++ )
if ( V_2 -> V_100 & ( 1UL << V_79 ) ) {
F_120 ( V_5 ,
V_2 -> V_102 + V_79 ) ;
V_104 ++ ;
}
}
F_116 ( V_2 , V_26 ) ;
}
F_121 () ;
F_122 (cpu)
V_105 += F_123 ( V_5 -> V_21 , V_79 ) -> V_107 ;
F_124 ( L_24 ,
F_55 () , ( long ) ( V_87 - V_5 -> V_86 ) ,
( long ) V_5 -> V_7 , ( long ) V_5 -> V_6 , V_105 ) ;
if ( V_104 ) {
F_112 ( V_5 ) ;
} else {
if ( F_2 ( V_5 -> V_7 ) != V_7 ||
F_2 ( V_5 -> V_6 ) == V_7 ) {
F_110 ( L_25 ) ;
} else {
V_91 = V_87 ;
V_97 = F_2 ( V_5 -> V_98 ) ;
F_110 ( L_26 ,
V_5 -> V_30 , V_91 - V_97 , V_91 , V_97 ,
V_108 ,
F_46 ( V_5 ) -> V_100 ) ;
F_111 ( V_59 ) ;
}
}
F_125 ( V_5 ) ;
F_109 ( V_5 ) ;
F_37 ( V_5 ) ;
}
static void F_126 ( struct V_4 * V_5 )
{
int V_79 ;
unsigned long V_26 ;
struct V_1 * V_2 = F_46 ( V_5 ) ;
long V_105 = 0 ;
F_110 ( L_27 , V_5 -> V_30 ) ;
F_118 () ;
F_120 ( V_5 , F_55 () ) ;
F_121 () ;
F_122 (cpu)
V_105 += F_123 ( V_5 -> V_21 , V_79 ) -> V_107 ;
F_124 ( L_28 ,
V_87 - V_5 -> V_86 ,
( long ) V_5 -> V_7 , ( long ) V_5 -> V_6 , V_105 ) ;
F_109 ( V_5 ) ;
F_112 ( V_5 ) ;
F_114 ( V_2 , V_26 ) ;
if ( F_100 ( V_87 , F_2 ( V_5 -> V_92 ) ) )
F_97 ( V_5 -> V_92 ,
V_87 + 3 * F_106 () + 3 ) ;
F_116 ( V_2 , V_26 ) ;
F_103 ( F_55 () ) ;
}
static void F_127 ( struct V_4 * V_5 , struct V_15 * V_16 )
{
unsigned long V_6 ;
unsigned long V_7 ;
unsigned long V_109 ;
unsigned long V_91 ;
unsigned long V_110 ;
struct V_1 * V_2 ;
if ( V_111 || ! F_3 ( V_5 ) )
return;
V_91 = V_87 ;
V_7 = F_2 ( V_5 -> V_7 ) ;
F_128 () ;
V_110 = F_2 ( V_5 -> V_92 ) ;
F_128 () ;
V_109 = F_2 ( V_5 -> V_86 ) ;
F_128 () ;
V_6 = F_2 ( V_5 -> V_6 ) ;
if ( F_100 ( V_6 , V_7 ) ||
F_49 ( V_91 , V_110 ) ||
F_100 ( V_109 , V_110 ) )
return;
V_2 = V_16 -> V_23 ;
if ( F_3 ( V_5 ) &&
( F_2 ( V_2 -> V_100 ) & V_16 -> V_74 ) ) {
F_126 ( V_5 ) ;
} else if ( F_3 ( V_5 ) &&
F_100 ( V_91 , V_110 + V_106 ) ) {
F_117 ( V_5 , V_7 ) ;
}
}
void F_129 ( void )
{
struct V_4 * V_5 ;
F_15 (rsp)
F_97 ( V_5 -> V_92 , V_87 + V_80 / 2 ) ;
}
static void F_130 ( struct V_15 * V_16 )
{
int V_50 ;
V_16 -> V_43 = NULL ;
for ( V_50 = 0 ; V_50 < V_112 ; V_50 ++ )
V_16 -> V_44 [ V_50 ] = & V_16 -> V_43 ;
}
static void F_131 ( struct V_15 * V_16 )
{
if ( F_132 ( V_16 ) )
return;
F_130 ( V_16 ) ;
}
static unsigned long F_133 ( struct V_4 * V_5 ,
struct V_1 * V_2 )
{
if ( F_46 ( V_5 ) == V_2 && V_2 -> V_7 == V_2 -> V_6 )
return V_2 -> V_6 + 1 ;
return V_2 -> V_6 + 2 ;
}
static void F_134 ( struct V_1 * V_2 , struct V_15 * V_16 ,
unsigned long V_113 , const char * V_10 )
{
F_135 ( V_16 -> V_5 -> V_30 , V_2 -> V_7 ,
V_2 -> V_6 , V_113 , V_2 -> V_114 ,
V_2 -> V_102 , V_2 -> V_101 , V_10 ) ;
}
static bool V_61
F_136 ( struct V_1 * V_2 , struct V_15 * V_16 ,
unsigned long * V_115 )
{
unsigned long V_113 ;
int V_50 ;
bool V_73 = false ;
struct V_1 * V_116 = F_46 ( V_16 -> V_5 ) ;
V_113 = F_133 ( V_16 -> V_5 , V_2 ) ;
F_134 ( V_2 , V_16 , V_113 , F_7 ( L_29 ) ) ;
if ( V_2 -> V_49 [ V_113 & 0x1 ] ) {
F_134 ( V_2 , V_16 , V_113 , F_7 ( L_30 ) ) ;
goto V_117;
}
if ( V_2 -> V_7 != V_2 -> V_6 ||
F_2 ( V_116 -> V_7 ) != F_2 ( V_116 -> V_6 ) ) {
V_2 -> V_49 [ V_113 & 0x1 ] ++ ;
F_134 ( V_2 , V_16 , V_113 , F_7 ( L_31 ) ) ;
goto V_117;
}
if ( V_2 != V_116 )
F_137 ( V_116 ) ;
V_113 = F_133 ( V_16 -> V_5 , V_116 ) ;
for ( V_50 = V_45 ; V_50 < V_51 ; V_50 ++ )
if ( F_49 ( V_113 , V_16 -> V_54 [ V_50 ] ) )
V_16 -> V_54 [ V_50 ] = V_113 ;
if ( V_116 -> V_49 [ V_113 & 0x1 ] ) {
F_134 ( V_2 , V_16 , V_113 , F_7 ( L_32 ) ) ;
goto V_118;
}
V_116 -> V_49 [ V_113 & 0x1 ] ++ ;
if ( V_116 -> V_7 != V_116 -> V_6 ) {
F_134 ( V_2 , V_16 , V_113 , F_7 ( L_33 ) ) ;
} else {
F_134 ( V_2 , V_16 , V_113 , F_7 ( L_34 ) ) ;
V_73 = F_138 ( V_16 -> V_5 , V_116 , V_16 ) ;
}
V_118:
if ( V_2 != V_116 )
F_139 ( V_116 ) ;
V_117:
if ( V_115 != NULL )
* V_115 = V_113 ;
return V_73 ;
}
static int F_140 ( struct V_4 * V_5 , struct V_1 * V_2 )
{
int V_113 = V_2 -> V_6 ;
int V_119 ;
struct V_15 * V_16 = F_10 ( V_5 -> V_21 ) ;
V_2 -> V_49 [ V_113 & 0x1 ] = 0 ;
V_119 = V_2 -> V_49 [ ( V_113 + 1 ) & 0x1 ] ;
F_134 ( V_2 , V_16 , V_113 ,
V_119 ? F_7 ( L_35 ) : F_7 ( L_36 ) ) ;
return V_119 ;
}
static void F_141 ( struct V_4 * V_5 )
{
if ( V_59 == V_5 -> V_32 ||
! F_2 ( V_5 -> V_41 ) ||
! V_5 -> V_32 )
return;
F_142 ( & V_5 -> V_120 ) ;
}
static bool F_143 ( struct V_4 * V_5 , struct V_1 * V_2 ,
struct V_15 * V_16 )
{
unsigned long V_113 ;
int V_50 ;
bool V_73 ;
if ( ! V_16 -> V_44 [ V_51 ] || ! * V_16 -> V_44 [ V_45 ] )
return false ;
V_113 = F_133 ( V_5 , V_2 ) ;
for ( V_50 = V_51 - 1 ; V_50 > V_45 ; V_50 -- )
if ( V_16 -> V_44 [ V_50 ] != V_16 -> V_44 [ V_50 - 1 ] &&
! F_100 ( V_16 -> V_54 [ V_50 ] , V_113 ) )
break;
if ( ++ V_50 >= V_51 )
return false ;
for (; V_50 <= V_51 ; V_50 ++ ) {
V_16 -> V_44 [ V_50 ] = V_16 -> V_44 [ V_51 ] ;
V_16 -> V_54 [ V_50 ] = V_113 ;
}
V_73 = F_136 ( V_2 , V_16 , NULL ) ;
if ( ! * V_16 -> V_44 [ V_53 ] )
F_6 ( V_5 -> V_30 , V_16 -> V_7 , F_7 ( L_37 ) ) ;
else
F_6 ( V_5 -> V_30 , V_16 -> V_7 , F_7 ( L_38 ) ) ;
return V_73 ;
}
static bool F_144 ( struct V_4 * V_5 , struct V_1 * V_2 ,
struct V_15 * V_16 )
{
int V_50 , V_91 ;
if ( ! V_16 -> V_44 [ V_51 ] || ! * V_16 -> V_44 [ V_45 ] )
return false ;
for ( V_50 = V_53 ; V_50 < V_51 ; V_50 ++ ) {
if ( F_49 ( V_2 -> V_6 , V_16 -> V_54 [ V_50 ] ) )
break;
V_16 -> V_44 [ V_45 ] = V_16 -> V_44 [ V_50 ] ;
}
for ( V_91 = V_53 ; V_91 < V_50 ; V_91 ++ )
V_16 -> V_44 [ V_91 ] = V_16 -> V_44 [ V_45 ] ;
for ( V_91 = V_53 ; V_50 < V_51 ; V_50 ++ , V_91 ++ ) {
if ( V_16 -> V_44 [ V_91 ] == V_16 -> V_44 [ V_51 ] )
break;
V_16 -> V_44 [ V_91 ] = V_16 -> V_44 [ V_50 ] ;
V_16 -> V_54 [ V_91 ] = V_16 -> V_54 [ V_50 ] ;
}
return F_143 ( V_5 , V_2 , V_16 ) ;
}
static bool F_145 ( struct V_4 * V_5 , struct V_1 * V_2 ,
struct V_15 * V_16 )
{
bool V_73 ;
if ( V_16 -> V_6 == V_2 -> V_6 &&
! F_25 ( F_2 ( V_16 -> V_81 ) ) ) {
V_73 = F_143 ( V_5 , V_2 , V_16 ) ;
} else {
V_73 = F_144 ( V_5 , V_2 , V_16 ) ;
V_16 -> V_6 = V_2 -> V_6 ;
F_6 ( V_5 -> V_30 , V_16 -> V_7 , F_7 ( L_39 ) ) ;
}
if ( V_16 -> V_7 != V_2 -> V_7 || F_25 ( F_2 ( V_16 -> V_81 ) ) ) {
V_16 -> V_7 = V_2 -> V_7 ;
F_6 ( V_5 -> V_30 , V_16 -> V_7 , F_7 ( L_40 ) ) ;
V_16 -> V_9 . V_11 . V_12 = true ;
V_16 -> V_121 = F_5 ( V_27 ) ;
V_16 -> V_122 = ! ! ( V_2 -> V_100 & V_16 -> V_74 ) ;
F_146 ( V_16 ) ;
F_97 ( V_16 -> V_81 , false ) ;
}
return V_73 ;
}
static void F_147 ( struct V_4 * V_5 , struct V_15 * V_16 )
{
unsigned long V_26 ;
bool V_123 ;
struct V_1 * V_2 ;
F_27 ( V_26 ) ;
V_2 = V_16 -> V_23 ;
if ( ( V_16 -> V_7 == F_2 ( V_2 -> V_7 ) &&
V_16 -> V_6 == F_2 ( V_2 -> V_6 ) &&
! F_25 ( F_2 ( V_16 -> V_81 ) ) ) ||
! F_148 ( V_2 ) ) {
F_28 ( V_26 ) ;
return;
}
V_123 = F_145 ( V_5 , V_2 , V_16 ) ;
F_116 ( V_2 , V_26 ) ;
if ( V_123 )
F_141 ( V_5 ) ;
}
static void F_149 ( struct V_4 * V_5 , int V_124 )
{
if ( V_124 > 0 &&
! ( V_5 -> V_7 % ( V_125 * V_126 * V_124 ) ) )
F_150 ( V_124 ) ;
}
static bool F_151 ( struct V_4 * V_5 )
{
unsigned long V_127 ;
struct V_15 * V_16 ;
struct V_1 * V_2 = F_46 ( V_5 ) ;
F_97 ( V_5 -> V_98 , V_87 ) ;
F_152 ( V_2 ) ;
if ( ! F_2 ( V_5 -> V_41 ) ) {
F_153 ( V_2 ) ;
return false ;
}
F_97 ( V_5 -> V_41 , 0 ) ;
if ( F_61 ( F_3 ( V_5 ) ) ) {
F_153 ( V_2 ) ;
return false ;
}
F_104 ( V_5 ) ;
F_154 ( & V_5 -> V_7 , V_5 -> V_7 + 1 ) ;
F_6 ( V_5 -> V_30 , V_5 -> V_7 , F_7 ( L_41 ) ) ;
F_153 ( V_2 ) ;
F_113 (rsp, rnp) {
F_149 ( V_5 , V_128 ) ;
F_152 ( V_2 ) ;
if ( V_2 -> V_129 == V_2 -> V_3 &&
! V_2 -> V_130 ) {
F_153 ( V_2 ) ;
continue;
}
V_127 = V_2 -> V_129 ;
V_2 -> V_129 = V_2 -> V_3 ;
if ( ! V_127 != ! V_2 -> V_129 ) {
if ( ! V_127 )
F_155 ( V_2 ) ;
else if ( F_156 ( V_2 ) )
V_2 -> V_130 = true ;
else
F_157 ( V_2 ) ;
}
if ( V_2 -> V_130 &&
( ! F_156 ( V_2 ) ||
V_2 -> V_129 ) ) {
V_2 -> V_130 = false ;
F_157 ( V_2 ) ;
}
F_153 ( V_2 ) ;
}
F_158 (rsp, rnp) {
F_149 ( V_5 , V_131 ) ;
F_152 ( V_2 ) ;
V_16 = F_10 ( V_5 -> V_21 ) ;
F_159 ( V_2 ) ;
V_2 -> V_100 = V_2 -> V_129 ;
F_97 ( V_2 -> V_7 , V_5 -> V_7 ) ;
if ( F_61 ( V_2 -> V_6 != V_5 -> V_6 ) )
F_97 ( V_2 -> V_6 , V_5 -> V_6 ) ;
if ( V_2 == V_16 -> V_23 )
( void ) F_145 ( V_5 , V_2 , V_16 ) ;
F_160 ( V_2 ) ;
F_161 ( V_5 -> V_30 , V_2 -> V_7 ,
V_2 -> V_114 , V_2 -> V_102 ,
V_2 -> V_101 , V_2 -> V_100 ) ;
F_153 ( V_2 ) ;
F_162 () ;
F_97 ( V_5 -> V_98 , V_87 ) ;
}
return true ;
}
static bool F_163 ( struct V_4 * V_5 , int * V_132 )
{
struct V_1 * V_2 = F_46 ( V_5 ) ;
* V_132 = F_2 ( V_5 -> V_41 ) ;
if ( * V_132 & V_133 )
return true ;
if ( ! F_2 ( V_2 -> V_100 ) && ! F_164 ( V_2 ) )
return true ;
return false ;
}
static void F_165 ( struct V_4 * V_5 , bool V_134 )
{
bool V_76 = false ;
unsigned long V_77 ;
struct V_1 * V_2 = F_46 ( V_5 ) ;
F_97 ( V_5 -> V_98 , V_87 ) ;
V_5 -> V_94 ++ ;
if ( V_134 ) {
if ( F_166 ( V_5 ) ) {
V_76 = true ;
V_77 = V_87 - V_80 / 4 ;
}
F_167 ( V_5 , F_93 ,
& V_76 , & V_77 ) ;
F_168 ( V_5 , V_76 , V_77 ) ;
} else {
V_76 = true ;
F_167 ( V_5 , F_98 , & V_76 , & V_77 ) ;
}
if ( F_2 ( V_5 -> V_41 ) & V_133 ) {
F_152 ( V_2 ) ;
F_97 ( V_5 -> V_41 ,
F_2 ( V_5 -> V_41 ) & ~ V_133 ) ;
F_153 ( V_2 ) ;
}
}
static void F_169 ( struct V_4 * V_5 )
{
unsigned long V_135 ;
bool V_136 = false ;
int V_137 = 0 ;
struct V_15 * V_16 ;
struct V_1 * V_2 = F_46 ( V_5 ) ;
struct V_138 * V_139 ;
F_97 ( V_5 -> V_98 , V_87 ) ;
F_152 ( V_2 ) ;
V_135 = V_87 - V_5 -> V_86 ;
if ( V_135 > V_5 -> V_140 )
V_5 -> V_140 = V_135 ;
F_153 ( V_2 ) ;
F_158 (rsp, rnp) {
F_152 ( V_2 ) ;
F_61 ( F_164 ( V_2 ) ) ;
F_61 ( V_2 -> V_100 ) ;
F_97 ( V_2 -> V_6 , V_5 -> V_7 ) ;
V_16 = F_10 ( V_5 -> V_21 ) ;
if ( V_2 == V_16 -> V_23 )
V_136 = F_145 ( V_5 , V_2 , V_16 ) || V_136 ;
V_137 += F_140 ( V_5 , V_2 ) ;
V_139 = F_170 ( V_2 ) ;
F_153 ( V_2 ) ;
F_171 ( V_139 ) ;
F_162 () ;
F_97 ( V_5 -> V_98 , V_87 ) ;
F_149 ( V_5 , V_141 ) ;
}
V_2 = F_46 ( V_5 ) ;
F_152 ( V_2 ) ;
F_172 ( V_2 , V_137 ) ;
F_97 ( V_5 -> V_6 , V_5 -> V_7 ) ;
F_6 ( V_5 -> V_30 , V_5 -> V_6 , F_7 ( L_42 ) ) ;
V_5 -> V_31 = V_142 ;
V_16 = F_10 ( V_5 -> V_21 ) ;
V_136 = F_144 ( V_5 , V_2 , V_16 ) || V_136 ;
if ( V_136 || F_48 ( V_5 , V_16 ) ) {
F_97 ( V_5 -> V_41 , V_143 ) ;
F_6 ( V_5 -> V_30 ,
F_2 ( V_5 -> V_7 ) ,
F_7 ( L_43 ) ) ;
}
F_153 ( V_2 ) ;
}
static int T_3 F_173 ( void * V_144 )
{
bool V_145 ;
int V_146 ;
unsigned long V_91 ;
int V_73 ;
struct V_4 * V_5 = V_144 ;
struct V_1 * V_2 = F_46 ( V_5 ) ;
F_174 () ;
for (; ; ) {
for (; ; ) {
F_6 ( V_5 -> V_30 ,
F_2 ( V_5 -> V_7 ) ,
F_7 ( L_44 ) ) ;
V_5 -> V_31 = V_147 ;
F_175 ( V_5 -> V_120 ,
F_2 ( V_5 -> V_41 ) &
V_143 ) ;
V_5 -> V_31 = V_148 ;
if ( F_151 ( V_5 ) )
break;
F_162 () ;
F_97 ( V_5 -> V_98 , V_87 ) ;
F_176 ( F_177 ( V_59 ) ) ;
F_6 ( V_5 -> V_30 ,
F_2 ( V_5 -> V_7 ) ,
F_7 ( L_45 ) ) ;
}
V_145 = true ;
V_91 = V_149 ;
if ( V_91 > V_99 ) {
V_91 = V_99 ;
V_149 = V_99 ;
}
V_73 = 0 ;
for (; ; ) {
if ( ! V_73 )
V_5 -> V_150 = V_87 + V_91 ;
F_6 ( V_5 -> V_30 ,
F_2 ( V_5 -> V_7 ) ,
F_7 ( L_46 ) ) ;
V_5 -> V_31 = V_151 ;
V_73 = F_178 ( V_5 -> V_120 ,
F_163 ( V_5 , & V_146 ) , V_91 ) ;
V_5 -> V_31 = V_152 ;
if ( ! F_2 ( V_2 -> V_100 ) &&
! F_164 ( V_2 ) )
break;
if ( F_100 ( V_87 , V_5 -> V_150 ) ||
( V_146 & V_133 ) ) {
F_6 ( V_5 -> V_30 ,
F_2 ( V_5 -> V_7 ) ,
F_7 ( L_47 ) ) ;
F_165 ( V_5 , V_145 ) ;
V_145 = false ;
F_6 ( V_5 -> V_30 ,
F_2 ( V_5 -> V_7 ) ,
F_7 ( L_48 ) ) ;
F_162 () ;
F_97 ( V_5 -> V_98 , V_87 ) ;
} else {
F_162 () ;
F_97 ( V_5 -> V_98 , V_87 ) ;
F_176 ( F_177 ( V_59 ) ) ;
F_6 ( V_5 -> V_30 ,
F_2 ( V_5 -> V_7 ) ,
F_7 ( L_49 ) ) ;
}
V_91 = V_108 ;
if ( V_91 > V_99 ) {
V_91 = V_99 ;
V_108 = V_99 ;
} else if ( V_91 < 1 ) {
V_91 = 1 ;
V_108 = 1 ;
}
}
V_5 -> V_31 = V_153 ;
F_169 ( V_5 ) ;
V_5 -> V_31 = V_154 ;
}
}
static bool
F_138 ( struct V_4 * V_5 , struct V_1 * V_2 ,
struct V_15 * V_16 )
{
if ( ! V_5 -> V_32 || ! F_48 ( V_5 , V_16 ) ) {
return false ;
}
F_97 ( V_5 -> V_41 , V_143 ) ;
F_6 ( V_5 -> V_30 , F_2 ( V_5 -> V_7 ) ,
F_7 ( L_43 ) ) ;
return true ;
}
static bool F_179 ( struct V_4 * V_5 )
{
struct V_15 * V_16 = F_10 ( V_5 -> V_21 ) ;
struct V_1 * V_2 = F_46 ( V_5 ) ;
bool V_73 = false ;
V_73 = F_144 ( V_5 , V_2 , V_16 ) || V_73 ;
V_73 = F_138 ( V_5 , V_2 , V_16 ) || V_73 ;
return V_73 ;
}
static void F_180 ( struct V_4 * V_5 , unsigned long V_26 )
__releases( rcu_get_root( V_5 )->lock
static void
F_181 ( unsigned long V_155 , struct V_4 * V_5 ,
struct V_1 * V_2 , unsigned long V_109 , unsigned long V_26 )
__releases( V_2 -> V_156 )
{
unsigned long V_127 = 0 ;
struct V_1 * V_157 ;
for (; ; ) {
if ( ! ( V_2 -> V_100 & V_155 ) || V_2 -> V_7 != V_109 ) {
F_116 ( V_2 , V_26 ) ;
return;
}
F_61 ( V_127 ) ;
V_2 -> V_100 &= ~ V_155 ;
F_182 ( V_5 -> V_30 , V_2 -> V_7 ,
V_155 , V_2 -> V_100 , V_2 -> V_114 ,
V_2 -> V_102 , V_2 -> V_101 ,
! ! V_2 -> V_158 ) ;
if ( V_2 -> V_100 != 0 || F_164 ( V_2 ) ) {
F_116 ( V_2 , V_26 ) ;
return;
}
V_155 = V_2 -> V_74 ;
if ( V_2 -> V_159 == NULL ) {
break;
}
F_116 ( V_2 , V_26 ) ;
V_157 = V_2 ;
V_2 = V_2 -> V_159 ;
F_114 ( V_2 , V_26 ) ;
V_127 = V_157 -> V_100 ;
}
F_180 ( V_5 , V_26 ) ;
}
static void F_183 ( struct V_4 * V_5 ,
struct V_1 * V_2 , unsigned long V_26 )
__releases( V_2 -> V_156 )
{
unsigned long V_109 ;
unsigned long V_155 ;
struct V_1 * V_160 ;
if ( V_28 == & V_13 || V_5 != V_28 ||
V_2 -> V_100 != 0 || F_164 ( V_2 ) ) {
F_116 ( V_2 , V_26 ) ;
return;
}
V_160 = V_2 -> V_159 ;
if ( V_160 == NULL ) {
F_180 ( V_5 , V_26 ) ;
return;
}
V_109 = V_2 -> V_7 ;
V_155 = V_2 -> V_74 ;
F_139 ( V_2 ) ;
F_137 ( V_160 ) ;
F_181 ( V_155 , V_5 , V_160 , V_109 , V_26 ) ;
}
static void
F_184 ( int V_79 , struct V_4 * V_5 , struct V_15 * V_16 )
{
unsigned long V_26 ;
unsigned long V_155 ;
bool V_123 ;
struct V_1 * V_2 ;
V_2 = V_16 -> V_23 ;
F_114 ( V_2 , V_26 ) ;
if ( ( V_16 -> V_9 . V_11 . V_12 &&
V_16 -> V_121 == F_5 ( V_27 ) ) ||
V_16 -> V_7 != V_2 -> V_7 || V_2 -> V_6 == V_2 -> V_7 ||
V_16 -> V_81 ) {
V_16 -> V_9 . V_11 . V_12 = true ;
V_16 -> V_121 = F_5 ( V_27 ) ;
F_116 ( V_2 , V_26 ) ;
return;
}
V_155 = V_16 -> V_74 ;
if ( ( V_2 -> V_100 & V_155 ) == 0 ) {
F_116 ( V_2 , V_26 ) ;
} else {
V_16 -> V_122 = false ;
V_123 = F_143 ( V_5 , V_2 , V_16 ) ;
F_181 ( V_155 , V_5 , V_2 , V_2 -> V_7 , V_26 ) ;
if ( V_123 )
F_141 ( V_5 ) ;
}
}
static void
F_185 ( struct V_4 * V_5 , struct V_15 * V_16 )
{
F_147 ( V_5 , V_16 ) ;
if ( ! V_16 -> V_122 )
return;
if ( V_16 -> V_9 . V_11 . V_12 &&
V_16 -> V_121 == F_5 ( V_27 ) )
return;
F_184 ( V_16 -> V_79 , V_5 , V_16 ) ;
}
static void
F_186 ( int V_79 , struct V_4 * V_5 ,
struct V_1 * V_2 , struct V_15 * V_16 )
{
if ( ! F_52 ( V_161 ) || F_187 ( V_16 -> V_79 ) )
return;
if ( V_16 -> V_43 != NULL ) {
V_5 -> V_162 += V_16 -> V_162 ;
V_5 -> V_107 += V_16 -> V_107 ;
V_16 -> V_163 += V_16 -> V_107 ;
V_16 -> V_162 = 0 ;
F_97 ( V_16 -> V_107 , 0 ) ;
}
if ( * V_16 -> V_44 [ V_45 ] != NULL ) {
* V_5 -> V_164 = * V_16 -> V_44 [ V_45 ] ;
V_5 -> V_164 = V_16 -> V_44 [ V_51 ] ;
* V_16 -> V_44 [ V_45 ] = NULL ;
}
if ( V_16 -> V_43 != NULL ) {
* V_5 -> V_165 = V_16 -> V_43 ;
V_5 -> V_165 = V_16 -> V_44 [ V_45 ] ;
}
F_131 ( V_16 ) ;
V_16 -> V_44 [ V_51 ] = NULL ;
}
static void F_188 ( struct V_4 * V_5 , unsigned long V_26 )
{
int V_50 ;
struct V_15 * V_16 = F_16 ( V_5 -> V_21 ) ;
if ( ! F_52 ( V_161 ) ||
F_189 ( V_5 , V_16 , V_26 ) )
return;
V_16 -> V_162 += V_5 -> V_162 ;
V_16 -> V_107 += V_5 -> V_107 ;
V_16 -> V_166 += V_5 -> V_107 ;
if ( V_5 -> V_162 != V_5 -> V_107 )
F_190 () ;
V_5 -> V_162 = 0 ;
V_5 -> V_107 = 0 ;
if ( V_5 -> V_167 != NULL ) {
* V_5 -> V_165 = * V_16 -> V_44 [ V_45 ] ;
* V_16 -> V_44 [ V_45 ] = V_5 -> V_167 ;
for ( V_50 = V_112 - 1 ; V_50 >= V_45 ; V_50 -- )
if ( V_16 -> V_44 [ V_50 ] == V_16 -> V_44 [ V_45 ] )
V_16 -> V_44 [ V_50 ] = V_5 -> V_165 ;
V_5 -> V_167 = NULL ;
V_5 -> V_165 = & V_5 -> V_167 ;
}
if ( V_5 -> V_168 != NULL ) {
* V_16 -> V_44 [ V_51 ] = V_5 -> V_168 ;
V_16 -> V_44 [ V_51 ] = V_5 -> V_164 ;
V_5 -> V_168 = NULL ;
V_5 -> V_164 = & V_5 -> V_168 ;
}
}
static void F_191 ( struct V_4 * V_5 )
{
F_192 (unsigned long mask) ;
F_192 ( struct V_15 * V_16 = F_10 ( V_5 -> V_21 ) ) ;
F_192 ( struct V_1 * V_2 = V_16 -> V_23 ) ;
if ( ! F_52 ( V_161 ) )
return;
F_192 ( V_155 = V_16 -> V_74 ) ;
F_6 ( V_5 -> V_30 ,
V_2 -> V_7 + 1 - ! ! ( V_2 -> V_100 & V_155 ) ,
F_7 ( L_50 ) ) ;
}
static void F_157 ( struct V_1 * V_169 )
{
long V_155 ;
struct V_1 * V_2 = V_169 ;
if ( ! F_52 ( V_161 ) ||
V_2 -> V_129 || F_156 ( V_2 ) )
return;
for (; ; ) {
V_155 = V_2 -> V_74 ;
V_2 = V_2 -> V_159 ;
if ( ! V_2 )
break;
F_137 ( V_2 ) ;
V_2 -> V_129 &= ~ V_155 ;
V_2 -> V_100 &= ~ V_155 ;
if ( V_2 -> V_129 ) {
F_139 ( V_2 ) ;
return;
}
F_139 ( V_2 ) ;
}
}
static void F_193 ( int V_79 , struct V_4 * V_5 )
{
unsigned long V_26 ;
struct V_15 * V_16 = F_123 ( V_5 -> V_21 , V_79 ) ;
struct V_1 * V_2 = V_16 -> V_23 ;
if ( ! F_52 ( V_161 ) )
return;
F_194 ( V_2 , - 1 ) ;
F_195 ( & V_5 -> V_170 , V_26 ) ;
F_186 ( V_79 , V_5 , V_2 , V_16 ) ;
F_188 ( V_5 , V_26 ) ;
F_196 ( & V_5 -> V_170 , V_26 ) ;
F_57 ( V_16 -> V_107 != 0 || V_16 -> V_43 != NULL ,
L_51 ,
V_79 , V_16 -> V_107 , V_16 -> V_43 ) ;
}
static void F_197 ( struct V_4 * V_5 , struct V_15 * V_16 )
{
unsigned long V_26 ;
struct V_171 * V_172 , * V_173 , * * V_174 ;
long V_175 , V_176 , V_177 ;
int V_50 ;
if ( ! F_45 ( V_16 ) ) {
F_198 ( V_5 -> V_30 , V_16 -> V_162 , V_16 -> V_107 , 0 ) ;
F_199 ( V_5 -> V_30 , 0 , ! ! F_2 ( V_16 -> V_43 ) ,
F_200 () , F_53 ( V_59 ) ,
F_201 () ) ;
return;
}
F_27 ( V_26 ) ;
F_61 ( F_101 ( F_55 () ) ) ;
V_175 = V_16 -> V_178 ;
F_198 ( V_5 -> V_30 , V_16 -> V_162 , V_16 -> V_107 , V_175 ) ;
V_173 = V_16 -> V_43 ;
V_16 -> V_43 = * V_16 -> V_44 [ V_45 ] ;
* V_16 -> V_44 [ V_45 ] = NULL ;
V_174 = V_16 -> V_44 [ V_45 ] ;
for ( V_50 = V_112 - 1 ; V_50 >= 0 ; V_50 -- )
if ( V_16 -> V_44 [ V_50 ] == V_16 -> V_44 [ V_45 ] )
V_16 -> V_44 [ V_50 ] = & V_16 -> V_43 ;
F_28 ( V_26 ) ;
V_176 = V_177 = 0 ;
while ( V_173 ) {
V_172 = V_173 -> V_172 ;
F_202 ( V_172 ) ;
F_203 ( V_173 ) ;
if ( F_204 ( V_5 -> V_30 , V_173 ) )
V_177 ++ ;
V_173 = V_172 ;
if ( ++ V_176 >= V_175 &&
( F_200 () ||
( ! F_53 ( V_59 ) && ! F_201 () ) ) )
break;
}
F_27 ( V_26 ) ;
F_199 ( V_5 -> V_30 , V_176 , ! ! V_173 , F_200 () ,
F_53 ( V_59 ) ,
F_201 () ) ;
if ( V_173 != NULL ) {
* V_174 = V_16 -> V_43 ;
V_16 -> V_43 = V_173 ;
for ( V_50 = 0 ; V_50 < V_112 ; V_50 ++ )
if ( & V_16 -> V_43 == V_16 -> V_44 [ V_50 ] )
V_16 -> V_44 [ V_50 ] = V_174 ;
else
break;
}
F_17 () ;
V_16 -> V_162 -= V_177 ;
F_97 ( V_16 -> V_107 , V_16 -> V_107 - V_176 ) ;
V_16 -> V_179 += V_176 ;
if ( V_16 -> V_178 == V_180 && V_16 -> V_107 <= V_181 )
V_16 -> V_178 = V_178 ;
if ( V_16 -> V_107 == 0 && V_16 -> V_182 != 0 ) {
V_16 -> V_182 = 0 ;
V_16 -> V_183 = V_5 -> V_94 ;
} else if ( V_16 -> V_107 < V_16 -> V_182 - V_184 )
V_16 -> V_182 = V_16 -> V_107 ;
F_61 ( ( V_16 -> V_43 == NULL ) != ( V_16 -> V_107 == 0 ) ) ;
F_28 ( V_26 ) ;
if ( F_45 ( V_16 ) )
F_205 () ;
}
void F_206 ( int V_56 )
{
F_23 ( F_7 ( L_52 ) ) ;
F_207 () ;
if ( V_56 || F_92 () ) {
F_4 () ;
F_11 () ;
} else if ( ! F_208 () ) {
F_11 () ;
}
F_209 () ;
if ( F_210 () )
F_205 () ;
if ( V_56 )
F_211 ( V_59 ) ;
F_23 ( F_7 ( L_53 ) ) ;
}
static void F_167 ( struct V_4 * V_5 ,
int (* F_212)( struct V_15 * V_5 , bool * V_76 ,
unsigned long * V_77 ) ,
bool * V_76 , unsigned long * V_77 )
{
unsigned long V_185 ;
int V_79 ;
unsigned long V_26 ;
unsigned long V_155 ;
struct V_1 * V_2 ;
F_113 (rsp, rnp) {
F_162 () ;
V_155 = 0 ;
F_114 ( V_2 , V_26 ) ;
if ( V_2 -> V_100 == 0 ) {
if ( V_28 == & V_13 ||
V_5 != V_28 ||
F_164 ( V_2 ) ) {
F_213 ( V_2 , V_26 ) ;
continue;
}
if ( V_2 -> V_159 &&
( V_2 -> V_159 -> V_100 & V_2 -> V_74 ) ) {
F_183 ( V_5 , V_2 , V_26 ) ;
continue;
}
}
V_79 = V_2 -> V_102 ;
V_185 = 1 ;
for (; V_79 <= V_2 -> V_101 ; V_79 ++ , V_185 <<= 1 ) {
if ( ( V_2 -> V_100 & V_185 ) != 0 ) {
if ( F_212 ( F_123 ( V_5 -> V_21 , V_79 ) , V_76 , V_77 ) )
V_155 |= V_185 ;
}
}
if ( V_155 != 0 ) {
F_181 ( V_155 , V_5 , V_2 , V_2 -> V_7 , V_26 ) ;
} else {
F_116 ( V_2 , V_26 ) ;
}
}
}
static void F_37 ( struct V_4 * V_5 )
{
unsigned long V_26 ;
bool V_73 ;
struct V_1 * V_2 ;
struct V_1 * V_186 = NULL ;
V_2 = F_5 ( V_5 -> V_21 -> V_23 ) ;
for (; V_2 != NULL ; V_2 = V_2 -> V_159 ) {
V_73 = ( F_2 ( V_5 -> V_41 ) & V_133 ) ||
! F_214 ( & V_2 -> V_187 ) ;
if ( V_186 != NULL )
F_215 ( & V_186 -> V_187 ) ;
if ( V_73 ) {
V_5 -> V_188 ++ ;
return;
}
V_186 = V_2 ;
}
F_114 ( V_186 , V_26 ) ;
F_215 ( & V_186 -> V_187 ) ;
if ( F_2 ( V_5 -> V_41 ) & V_133 ) {
V_5 -> V_188 ++ ;
F_116 ( V_186 , V_26 ) ;
return;
}
F_97 ( V_5 -> V_41 , F_2 ( V_5 -> V_41 ) | V_133 ) ;
F_116 ( V_186 , V_26 ) ;
F_142 ( & V_5 -> V_120 ) ;
}
static void
F_216 ( struct V_4 * V_5 )
{
unsigned long V_26 ;
bool V_123 ;
struct V_15 * V_16 = F_16 ( V_5 -> V_21 ) ;
F_61 ( V_16 -> V_189 == 0 ) ;
F_185 ( V_5 , V_16 ) ;
F_27 ( V_26 ) ;
if ( F_48 ( V_5 , V_16 ) ) {
F_137 ( F_46 ( V_5 ) ) ;
V_123 = F_179 ( V_5 ) ;
F_116 ( F_46 ( V_5 ) , V_26 ) ;
if ( V_123 )
F_141 ( V_5 ) ;
} else {
F_28 ( V_26 ) ;
}
if ( F_45 ( V_16 ) )
F_217 ( V_5 , V_16 ) ;
F_58 ( V_16 ) ;
}
static void F_218 ( struct V_190 * V_191 )
{
struct V_4 * V_5 ;
if ( F_101 ( F_55 () ) )
return;
F_23 ( F_7 ( L_54 ) ) ;
F_15 (rsp)
F_216 ( V_5 ) ;
F_23 ( F_7 ( L_55 ) ) ;
}
static void F_217 ( struct V_4 * V_5 , struct V_15 * V_16 )
{
if ( F_25 ( ! F_2 ( V_75 ) ) )
return;
if ( F_219 ( ! V_5 -> V_192 ) ) {
F_197 ( V_5 , V_16 ) ;
return;
}
F_220 () ;
}
static void F_205 ( void )
{
if ( F_221 ( F_55 () ) )
F_222 ( V_193 ) ;
}
static void F_223 ( struct V_4 * V_5 , struct V_15 * V_16 ,
struct V_171 * V_194 , unsigned long V_26 )
{
bool V_123 ;
if ( ! F_85 () )
F_205 () ;
if ( F_224 ( V_26 ) || F_101 ( F_55 () ) )
return;
if ( F_25 ( V_16 -> V_107 > V_16 -> V_182 + V_184 ) ) {
F_147 ( V_5 , V_16 ) ;
if ( ! F_3 ( V_5 ) ) {
struct V_1 * V_116 = F_46 ( V_5 ) ;
F_137 ( V_116 ) ;
V_123 = F_179 ( V_5 ) ;
F_139 ( V_116 ) ;
if ( V_123 )
F_141 ( V_5 ) ;
} else {
V_16 -> V_178 = V_180 ;
if ( V_5 -> V_94 == V_16 -> V_183 &&
* V_16 -> V_44 [ V_45 ] != V_194 )
F_37 ( V_5 ) ;
V_16 -> V_183 = V_5 -> V_94 ;
V_16 -> V_182 = V_16 -> V_107 ;
}
}
}
static void F_225 ( struct V_171 * V_195 )
{
}
static void
F_226 ( struct V_171 * V_194 , T_4 V_196 ,
struct V_4 * V_5 , int V_79 , bool V_197 )
{
unsigned long V_26 ;
struct V_15 * V_16 ;
F_61 ( ( unsigned long ) V_194 & 0x1 ) ;
if ( F_227 ( V_194 ) ) {
F_97 ( V_194 -> V_196 , F_225 ) ;
F_57 ( 1 , L_56 ) ;
return;
}
V_194 -> V_196 = V_196 ;
V_194 -> V_172 = NULL ;
F_27 ( V_26 ) ;
V_16 = F_10 ( V_5 -> V_21 ) ;
if ( F_25 ( V_16 -> V_44 [ V_51 ] == NULL ) || V_79 != - 1 ) {
int V_198 ;
if ( V_79 != - 1 )
V_16 = F_123 ( V_5 -> V_21 , V_79 ) ;
if ( F_219 ( V_16 -> V_23 ) ) {
V_198 = ! F_228 ( V_16 , V_194 , V_197 , V_26 ) ;
F_61 ( V_198 ) ;
F_28 ( V_26 ) ;
return;
}
F_229 ( V_79 != - 1 ) ;
F_61 ( ! F_85 () ) ;
if ( ! F_219 ( V_16 -> V_43 ) )
F_130 ( V_16 ) ;
}
F_97 ( V_16 -> V_107 , V_16 -> V_107 + 1 ) ;
if ( V_197 )
V_16 -> V_162 ++ ;
else
F_190 () ;
F_17 () ;
* V_16 -> V_44 [ V_51 ] = V_194 ;
V_16 -> V_44 [ V_51 ] = & V_194 -> V_172 ;
if ( F_230 ( ( unsigned long ) V_196 ) )
F_231 ( V_5 -> V_30 , V_194 , ( unsigned long ) V_196 ,
V_16 -> V_162 , V_16 -> V_107 ) ;
else
F_232 ( V_5 -> V_30 , V_194 , V_16 -> V_162 , V_16 -> V_107 ) ;
F_223 ( V_5 , V_16 , V_194 , V_26 ) ;
F_28 ( V_26 ) ;
}
void F_233 ( struct V_171 * V_194 , T_4 V_196 )
{
F_226 ( V_194 , V_196 , & V_13 , - 1 , 0 ) ;
}
void F_234 ( struct V_171 * V_194 , T_4 V_196 )
{
F_226 ( V_194 , V_196 , & V_29 , - 1 , 0 ) ;
}
void F_235 ( struct V_171 * V_194 ,
T_4 V_196 )
{
F_226 ( V_194 , V_196 , V_28 , - 1 , 1 ) ;
}
static inline int F_236 ( void )
{
int V_73 ;
F_237 () ;
F_90 () ;
V_73 = F_238 () <= 1 ;
F_91 () ;
return V_73 ;
}
void F_239 ( void )
{
F_64 ( F_65 ( & V_66 ) ||
F_65 ( & V_65 ) ||
F_65 ( & V_67 ) ,
L_57 ) ;
if ( F_236 () )
return;
if ( F_240 () )
F_241 () ;
else
F_242 ( F_233 ) ;
}
void F_243 ( void )
{
F_64 ( F_65 ( & V_66 ) ||
F_65 ( & V_65 ) ||
F_65 ( & V_67 ) ,
L_58 ) ;
if ( F_236 () )
return;
if ( F_240 () )
F_244 () ;
else
F_242 ( F_234 ) ;
}
unsigned long F_245 ( void )
{
F_17 () ;
return F_246 ( & V_28 -> V_7 ) ;
}
void F_247 ( unsigned long V_199 )
{
unsigned long V_200 ;
V_200 = F_246 ( & V_28 -> V_6 ) ;
if ( F_100 ( V_199 , V_200 ) )
F_248 () ;
}
unsigned long F_249 ( void )
{
F_17 () ;
return F_246 ( & V_13 . V_7 ) ;
}
void F_250 ( unsigned long V_199 )
{
unsigned long V_200 ;
V_200 = F_246 ( & V_13 . V_6 ) ;
if ( F_100 ( V_199 , V_200 ) )
F_239 () ;
}
static void F_251 ( unsigned long * V_201 )
{
F_97 ( * V_201 , * V_201 + 1 ) ;
F_17 () ;
F_61 ( ! ( * V_201 & 0x1 ) ) ;
}
static void F_252 ( unsigned long * V_201 )
{
F_17 () ;
F_97 ( * V_201 , * V_201 + 1 ) ;
F_61 ( * V_201 & 0x1 ) ;
}
static unsigned long F_253 ( unsigned long * V_201 )
{
unsigned long V_10 ;
V_10 = ( F_2 ( * V_201 ) + 3 ) & ~ 0x1 ;
F_17 () ;
return V_10 ;
}
static bool F_254 ( unsigned long * V_201 , unsigned long V_10 )
{
return F_100 ( F_2 ( * V_201 ) , V_10 ) ;
}
static void F_255 ( struct V_4 * V_5 )
{
F_251 ( & V_5 -> V_202 ) ;
}
static void F_256 ( struct V_4 * V_5 )
{
F_252 ( & V_5 -> V_202 ) ;
F_17 () ;
}
static unsigned long F_257 ( struct V_4 * V_5 )
{
F_17 () ;
return F_253 ( & V_5 -> V_202 ) ;
}
static bool F_258 ( struct V_4 * V_5 , unsigned long V_10 )
{
return F_254 ( & V_5 -> V_202 , V_10 ) ;
}
static void F_259 ( struct V_4 * V_5 )
{
bool V_203 ;
unsigned long V_26 ;
unsigned long V_155 ;
unsigned long V_127 ;
int V_204 = F_2 ( V_5 -> V_204 ) ;
struct V_1 * V_2 ;
struct V_1 * V_205 ;
if ( F_219 ( V_204 == V_5 -> V_206 ) )
return;
V_5 -> V_206 = V_204 ;
F_113 (rsp, rnp) {
F_114 ( V_2 , V_26 ) ;
if ( V_2 -> V_207 == V_2 -> V_208 ) {
F_116 ( V_2 , V_26 ) ;
continue;
}
V_127 = V_2 -> V_207 ;
V_2 -> V_207 = V_2 -> V_208 ;
F_116 ( V_2 , V_26 ) ;
if ( V_127 )
continue;
V_155 = V_2 -> V_74 ;
V_205 = V_2 -> V_159 ;
V_203 = false ;
while ( V_205 ) {
F_114 ( V_205 , V_26 ) ;
if ( V_205 -> V_207 )
V_203 = true ;
V_205 -> V_207 |= V_155 ;
F_116 ( V_205 , V_26 ) ;
if ( V_203 )
break;
V_155 = V_205 -> V_74 ;
V_205 = V_205 -> V_159 ;
}
}
}
static void V_61 F_260 ( struct V_4 * V_5 )
{
unsigned long V_26 ;
struct V_1 * V_2 ;
F_259 ( V_5 ) ;
F_158 (rsp, rnp) {
F_114 ( V_2 , V_26 ) ;
F_61 ( V_2 -> V_209 ) ;
V_2 -> V_209 = V_2 -> V_207 ;
F_116 ( V_2 , V_26 ) ;
}
}
static int F_261 ( struct V_1 * V_2 )
{
return V_2 -> V_210 == NULL &&
F_2 ( V_2 -> V_209 ) == 0 ;
}
static void F_262 ( struct V_4 * V_5 , struct V_1 * V_2 ,
bool V_211 , unsigned long V_26 )
__releases( V_2 -> V_156 )
{
unsigned long V_155 ;
for (; ; ) {
if ( ! F_261 ( V_2 ) ) {
if ( ! V_2 -> V_209 )
F_213 ( V_2 , V_26 ) ;
else
F_116 ( V_2 , V_26 ) ;
break;
}
if ( V_2 -> V_159 == NULL ) {
F_116 ( V_2 , V_26 ) ;
if ( V_211 ) {
F_17 () ;
F_142 ( & V_5 -> V_212 ) ;
}
break;
}
V_155 = V_2 -> V_74 ;
F_139 ( V_2 ) ;
V_2 = V_2 -> V_159 ;
F_137 ( V_2 ) ;
F_61 ( ! ( V_2 -> V_209 & V_155 ) ) ;
V_2 -> V_209 &= ~ V_155 ;
}
}
static void V_61 F_263 ( struct V_4 * V_5 ,
struct V_1 * V_2 , bool V_211 )
{
unsigned long V_26 ;
F_114 ( V_2 , V_26 ) ;
F_262 ( V_5 , V_2 , V_211 , V_26 ) ;
}
static void F_264 ( struct V_4 * V_5 , struct V_1 * V_2 ,
unsigned long V_155 , bool V_211 )
{
unsigned long V_26 ;
F_114 ( V_2 , V_26 ) ;
if ( ! ( V_2 -> V_209 & V_155 ) ) {
F_116 ( V_2 , V_26 ) ;
return;
}
V_2 -> V_209 &= ~ V_155 ;
F_262 ( V_5 , V_2 , V_211 , V_26 ) ;
}
static void F_9 ( struct V_4 * V_5 , struct V_15 * V_16 ,
bool V_211 )
{
F_264 ( V_5 , V_16 -> V_23 , V_16 -> V_74 , V_211 ) ;
}
static bool F_265 ( struct V_4 * V_5 , struct V_1 * V_2 ,
struct V_15 * V_16 ,
T_5 * V_213 , unsigned long V_10 )
{
if ( F_258 ( V_5 , V_10 ) ) {
if ( V_2 )
F_266 ( & V_2 -> V_214 ) ;
else if ( V_16 )
F_266 ( & V_16 -> V_214 ) ;
F_18 () ;
F_267 ( V_213 ) ;
return true ;
}
return false ;
}
static struct V_1 * F_268 ( struct V_4 * V_5 , unsigned long V_10 )
{
struct V_15 * V_16 = F_123 ( V_5 -> V_21 , F_269 () ) ;
struct V_1 * V_215 ;
struct V_1 * V_216 = NULL ;
V_215 = F_46 ( V_5 ) ;
if ( ! F_270 ( & V_215 -> V_214 ) ) {
if ( F_271 ( & V_215 -> V_214 ) ) {
if ( F_265 ( V_5 , V_215 , NULL ,
& V_16 -> V_217 , V_10 ) )
return NULL ;
return V_215 ;
}
}
if ( F_265 ( V_5 , NULL , NULL , & V_16 -> V_218 , V_10 ) )
return NULL ;
F_272 ( & V_16 -> V_214 ) ;
V_215 = V_16 -> V_23 ;
for (; V_215 != NULL ; V_215 = V_215 -> V_159 ) {
if ( F_265 ( V_5 , V_216 , V_16 ,
& V_16 -> V_219 , V_10 ) )
return NULL ;
F_272 ( & V_215 -> V_214 ) ;
if ( V_216 )
F_266 ( & V_216 -> V_214 ) ;
else
F_266 ( & V_16 -> V_214 ) ;
V_216 = V_215 ;
}
if ( F_265 ( V_5 , V_216 , V_16 ,
& V_16 -> V_220 , V_10 ) )
return NULL ;
return V_216 ;
}
static void F_273 ( void * V_221 )
{
struct V_15 * V_16 ;
struct V_1 * V_2 ;
struct V_4 * V_5 = V_221 ;
V_16 = F_10 ( V_5 -> V_21 ) ;
V_2 = V_16 -> V_23 ;
if ( ! ( F_2 ( V_2 -> V_209 ) & V_16 -> V_74 ) ||
F_5 ( V_8 . V_9 . V_11 . exp ) )
return;
F_8 ( V_8 . V_9 . V_11 . exp , true ) ;
F_103 ( F_55 () ) ;
}
static void F_274 ( int V_79 )
{
struct V_15 * V_16 ;
int V_73 ;
struct V_1 * V_2 ;
struct V_4 * V_5 = & V_13 ;
V_16 = F_123 ( V_5 -> V_21 , V_79 ) ;
V_2 = V_16 -> V_23 ;
if ( ! ( F_2 ( V_2 -> V_209 ) & V_16 -> V_74 ) )
return;
V_73 = F_275 ( V_79 , F_273 , V_5 , 0 ) ;
F_61 ( V_73 ) ;
}
static void F_276 ( struct V_4 * V_5 ,
T_6 V_196 )
{
int V_79 ;
unsigned long V_26 ;
unsigned long V_155 ;
unsigned long V_222 ;
unsigned long V_223 ;
int V_73 ;
struct V_1 * V_2 ;
F_260 ( V_5 ) ;
F_113 (rsp, rnp) {
F_114 ( V_2 , V_26 ) ;
V_222 = 0 ;
for ( V_79 = V_2 -> V_102 ; V_79 <= V_2 -> V_101 ; V_79 ++ ) {
struct V_15 * V_16 = F_123 ( V_5 -> V_21 , V_79 ) ;
struct V_17 * V_18 = & F_102 ( V_17 , V_79 ) ;
if ( F_269 () == V_79 ||
! ( F_94 ( 0 , & V_18 -> V_25 ) & 0x1 ) )
V_222 |= V_16 -> V_74 ;
}
V_223 = V_2 -> V_209 & ~ V_222 ;
if ( F_156 ( V_2 ) )
V_2 -> V_210 = V_2 -> V_224 . V_172 ;
F_116 ( V_2 , V_26 ) ;
V_155 = 1 ;
for ( V_79 = V_2 -> V_102 ; V_79 <= V_2 -> V_101 ; V_79 ++ , V_155 <<= 1 ) {
if ( ! ( V_223 & V_155 ) )
continue;
V_225:
V_73 = F_275 ( V_79 , V_196 , V_5 , 0 ) ;
if ( ! V_73 ) {
V_223 &= ~ V_155 ;
continue;
}
F_114 ( V_2 , V_26 ) ;
if ( F_221 ( V_79 ) &&
( V_2 -> V_209 & V_155 ) ) {
F_116 ( V_2 , V_26 ) ;
F_150 ( 1 ) ;
if ( F_221 ( V_79 ) &&
( V_2 -> V_209 & V_155 ) )
goto V_225;
F_114 ( V_2 , V_26 ) ;
}
if ( ! ( V_2 -> V_209 & V_155 ) )
V_223 &= ~ V_155 ;
F_116 ( V_2 , V_26 ) ;
}
V_222 |= V_223 ;
if ( V_222 )
F_264 ( V_5 , V_2 , V_222 , false ) ;
}
}
static void F_277 ( struct V_4 * V_5 )
{
int V_79 ;
unsigned long V_92 ;
unsigned long V_226 ;
unsigned long V_155 ;
int V_104 ;
struct V_1 * V_2 ;
struct V_1 * V_116 = F_46 ( V_5 ) ;
int V_73 ;
V_92 = F_106 () ;
V_226 = V_87 ;
for (; ; ) {
V_73 = F_278 (
V_5 -> V_212 ,
F_261 ( V_116 ) ,
V_92 ) ;
if ( V_73 > 0 || F_261 ( V_116 ) )
return;
if ( V_73 < 0 ) {
F_279 ( V_5 -> V_212 ,
F_261 ( V_116 ) ) ;
return;
}
F_110 ( L_59 ,
V_5 -> V_30 ) ;
V_104 = 0 ;
F_113 (rsp, rnp) {
V_104 = F_280 ( V_2 ) ;
V_155 = 1 ;
for ( V_79 = V_2 -> V_102 ; V_79 <= V_2 -> V_101 ; V_79 ++ , V_155 <<= 1 ) {
struct V_15 * V_16 ;
if ( ! ( V_2 -> V_209 & V_155 ) )
continue;
V_104 ++ ;
V_16 = F_123 ( V_5 -> V_21 , V_79 ) ;
F_124 ( L_60 , V_79 ,
L_61 [ F_221 ( V_79 ) ] ,
L_62 [ ! ! ( V_16 -> V_74 & V_2 -> V_207 ) ] ,
L_63 [ ! ! ( V_16 -> V_74 & V_2 -> V_208 ) ] ) ;
}
V_155 <<= 1 ;
}
F_124 ( L_64 ,
V_87 - V_226 , V_5 -> V_202 ,
V_116 -> V_209 , L_65 [ ! ! V_116 -> V_210 ] ) ;
if ( ! V_104 ) {
F_110 ( L_66 ) ;
F_158 (rsp, rnp) {
if ( V_2 == V_116 )
continue;
if ( F_261 ( V_2 ) )
continue;
F_124 ( L_67 ,
V_2 -> V_114 , V_2 -> V_102 , V_2 -> V_101 ,
V_2 -> V_209 ,
L_65 [ ! ! V_2 -> V_210 ] ) ;
}
F_124 ( L_68 ) ;
}
F_113 (rsp, rnp) {
V_155 = 1 ;
for ( V_79 = V_2 -> V_102 ; V_79 <= V_2 -> V_101 ; V_79 ++ , V_155 <<= 1 ) {
if ( ! ( V_2 -> V_209 & V_155 ) )
continue;
F_115 ( V_79 ) ;
}
}
V_92 = 3 * F_106 () + 3 ;
}
}
void F_241 ( void )
{
unsigned long V_10 ;
struct V_1 * V_2 ;
struct V_4 * V_5 = & V_13 ;
if ( F_236 () )
return;
if ( F_281 () ) {
F_242 ( F_233 ) ;
return;
}
V_10 = F_257 ( V_5 ) ;
V_2 = F_268 ( V_5 , V_10 ) ;
if ( V_2 == NULL )
return;
F_255 ( V_5 ) ;
F_276 ( V_5 , F_273 ) ;
F_277 ( V_5 ) ;
F_256 ( V_5 ) ;
F_266 ( & V_2 -> V_214 ) ;
}
static int F_282 ( struct V_4 * V_5 , struct V_15 * V_16 )
{
struct V_1 * V_2 = V_16 -> V_23 ;
V_16 -> V_227 ++ ;
F_127 ( V_5 , V_16 ) ;
if ( F_283 ( V_5 ) )
return 0 ;
if ( V_75 &&
V_16 -> V_122 && V_16 -> V_9 . V_11 . V_12 &&
V_16 -> V_121 == F_5 ( V_27 ) ) {
V_16 -> V_228 ++ ;
} else if ( V_16 -> V_122 &&
( ! V_16 -> V_9 . V_11 . V_12 ||
V_16 -> V_121 != F_5 ( V_27 ) ) ) {
V_16 -> V_229 ++ ;
return 1 ;
}
if ( F_45 ( V_16 ) ) {
V_16 -> V_230 ++ ;
return 1 ;
}
if ( F_48 ( V_5 , V_16 ) ) {
V_16 -> V_231 ++ ;
return 1 ;
}
if ( F_2 ( V_2 -> V_6 ) != V_16 -> V_6 ) {
V_16 -> V_232 ++ ;
return 1 ;
}
if ( F_2 ( V_2 -> V_7 ) != V_16 -> V_7 ||
F_25 ( F_2 ( V_16 -> V_81 ) ) ) {
V_16 -> V_233 ++ ;
return 1 ;
}
if ( F_284 ( V_16 ) ) {
V_16 -> V_234 ++ ;
return 1 ;
}
V_16 -> V_235 ++ ;
return 0 ;
}
static int F_210 ( void )
{
struct V_4 * V_5 ;
F_15 (rsp)
if ( F_282 ( V_5 , F_10 ( V_5 -> V_21 ) ) )
return 1 ;
return 0 ;
}
static bool V_61 F_285 ( bool * V_236 )
{
bool V_237 = true ;
bool V_238 = false ;
struct V_15 * V_16 ;
struct V_4 * V_5 ;
F_15 (rsp) {
V_16 = F_10 ( V_5 -> V_21 ) ;
if ( ! V_16 -> V_43 )
continue;
V_238 = true ;
if ( V_16 -> V_107 != V_16 -> V_162 || ! V_236 ) {
V_237 = false ;
break;
}
}
if ( V_236 )
* V_236 = V_237 ;
return V_238 ;
}
static void F_286 ( struct V_4 * V_5 , const char * V_10 ,
int V_79 , unsigned long V_203 )
{
F_287 ( V_5 -> V_30 , V_10 , V_79 ,
F_62 ( & V_5 -> V_239 ) , V_203 ) ;
}
static void F_288 ( struct V_171 * V_195 )
{
struct V_15 * V_16 = F_289 ( V_195 , struct V_15 , V_240 ) ;
struct V_4 * V_5 = V_16 -> V_5 ;
if ( F_290 ( & V_5 -> V_239 ) ) {
F_286 ( V_5 , L_69 , - 1 , V_5 -> V_241 ) ;
F_291 ( & V_5 -> V_242 ) ;
} else {
F_286 ( V_5 , L_70 , - 1 , V_5 -> V_241 ) ;
}
}
static void F_292 ( void * type )
{
struct V_4 * V_5 = type ;
struct V_15 * V_16 = F_16 ( V_5 -> V_21 ) ;
F_286 ( V_5 , L_71 , - 1 , V_5 -> V_241 ) ;
F_60 ( & V_5 -> V_239 ) ;
V_5 -> V_243 ( & V_16 -> V_240 , F_288 ) ;
}
static void F_293 ( struct V_4 * V_5 )
{
int V_79 ;
struct V_15 * V_16 ;
unsigned long V_10 = F_253 ( & V_5 -> V_241 ) ;
F_286 ( V_5 , L_72 , - 1 , V_10 ) ;
F_272 ( & V_5 -> V_244 ) ;
if ( F_254 ( & V_5 -> V_241 , V_10 ) ) {
F_286 ( V_5 , L_73 , - 1 , V_5 -> V_241 ) ;
F_17 () ;
F_266 ( & V_5 -> V_244 ) ;
return;
}
F_251 ( & V_5 -> V_241 ) ;
F_286 ( V_5 , L_74 , - 1 , V_5 -> V_241 ) ;
F_294 ( & V_5 -> V_242 ) ;
F_295 ( & V_5 -> V_239 , 1 ) ;
F_296 () ;
F_122 (cpu) {
if ( ! F_221 ( V_79 ) && ! F_187 ( V_79 ) )
continue;
V_16 = F_123 ( V_5 -> V_21 , V_79 ) ;
if ( F_187 ( V_79 ) ) {
if ( ! F_297 ( V_5 , V_79 ) ) {
F_286 ( V_5 , L_75 , V_79 ,
V_5 -> V_241 ) ;
} else {
F_286 ( V_5 , L_76 , V_79 ,
V_5 -> V_241 ) ;
F_18 () ;
F_60 ( & V_5 -> V_239 ) ;
F_226 ( & V_16 -> V_240 ,
F_288 , V_5 , V_79 , 0 ) ;
}
} else if ( F_2 ( V_16 -> V_107 ) ) {
F_286 ( V_5 , L_77 , V_79 ,
V_5 -> V_241 ) ;
F_275 ( V_79 , F_292 , V_5 , 1 ) ;
} else {
F_286 ( V_5 , L_78 , V_79 ,
V_5 -> V_241 ) ;
}
}
F_298 () ;
if ( F_290 ( & V_5 -> V_239 ) )
F_291 ( & V_5 -> V_242 ) ;
F_299 ( & V_5 -> V_242 ) ;
F_286 ( V_5 , L_79 , - 1 , V_5 -> V_241 ) ;
F_252 ( & V_5 -> V_241 ) ;
F_266 ( & V_5 -> V_244 ) ;
}
void F_300 ( void )
{
F_293 ( & V_29 ) ;
}
void F_301 ( void )
{
F_293 ( & V_13 ) ;
}
static void F_155 ( struct V_1 * V_169 )
{
long V_155 ;
struct V_1 * V_2 = V_169 ;
for (; ; ) {
V_155 = V_2 -> V_74 ;
V_2 = V_2 -> V_159 ;
if ( V_2 == NULL )
return;
F_137 ( V_2 ) ;
V_2 -> V_129 |= V_155 ;
F_139 ( V_2 ) ;
}
}
static void T_7
F_302 ( int V_79 , struct V_4 * V_5 )
{
unsigned long V_26 ;
struct V_15 * V_16 = F_123 ( V_5 -> V_21 , V_79 ) ;
struct V_1 * V_2 = F_46 ( V_5 ) ;
F_114 ( V_2 , V_26 ) ;
V_16 -> V_74 = 1UL << ( V_79 - V_16 -> V_23 -> V_102 ) ;
V_16 -> V_25 = & F_102 ( V_17 , V_79 ) ;
F_61 ( V_16 -> V_25 -> V_57 != V_70 ) ;
F_61 ( F_62 ( & V_16 -> V_25 -> V_25 ) != 1 ) ;
V_16 -> V_79 = V_79 ;
V_16 -> V_5 = V_5 ;
F_303 ( & V_16 -> V_214 ) ;
F_304 ( V_16 ) ;
F_116 ( V_2 , V_26 ) ;
}
static void
F_305 ( int V_79 , struct V_4 * V_5 )
{
unsigned long V_26 ;
unsigned long V_155 ;
struct V_15 * V_16 = F_123 ( V_5 -> V_21 , V_79 ) ;
struct V_1 * V_2 = F_46 ( V_5 ) ;
F_114 ( V_2 , V_26 ) ;
V_16 -> V_182 = 0 ;
V_16 -> V_183 = V_5 -> V_94 ;
V_16 -> V_178 = V_178 ;
if ( ! V_16 -> V_43 )
F_131 ( V_16 ) ;
V_16 -> V_25 -> V_57 = V_70 ;
F_306 ( V_16 -> V_25 ) ;
F_295 ( & V_16 -> V_25 -> V_25 ,
( F_62 ( & V_16 -> V_25 -> V_25 ) & ~ 0x1 ) + 1 ) ;
F_139 ( V_2 ) ;
V_2 = V_16 -> V_23 ;
V_155 = V_16 -> V_74 ;
F_137 ( V_2 ) ;
V_2 -> V_3 |= V_155 ;
V_2 -> V_208 |= V_155 ;
if ( ! V_16 -> V_189 )
F_97 ( V_5 -> V_204 , F_2 ( V_5 -> V_204 ) + 1 ) ;
V_16 -> V_189 = true ;
V_16 -> V_7 = V_2 -> V_6 ;
V_16 -> V_6 = V_2 -> V_6 ;
V_16 -> V_9 . V_11 . V_12 = true ;
V_16 -> V_121 = F_102 ( V_27 , V_79 ) ;
V_16 -> V_122 = false ;
F_6 ( V_5 -> V_30 , V_16 -> V_7 , F_7 ( L_80 ) ) ;
F_116 ( V_2 , V_26 ) ;
}
static void F_307 ( int V_79 )
{
struct V_4 * V_5 ;
F_15 (rsp)
F_305 ( V_79 , V_5 ) ;
}
static void F_308 ( int V_79 , struct V_4 * V_5 )
{
unsigned long V_26 ;
unsigned long V_155 ;
struct V_15 * V_16 = F_123 ( V_5 -> V_21 , V_79 ) ;
struct V_1 * V_2 = V_16 -> V_23 ;
if ( ! F_52 ( V_161 ) )
return;
V_155 = V_16 -> V_74 ;
F_114 ( V_2 , V_26 ) ;
V_2 -> V_3 &= ~ V_155 ;
F_116 ( V_2 , V_26 ) ;
}
void F_309 ( unsigned int V_79 )
{
struct V_4 * V_5 ;
F_90 () ;
F_9 ( & V_13 ,
F_10 ( V_13 . V_21 ) , true ) ;
F_91 () ;
F_15 (rsp)
F_308 ( V_79 , V_5 ) ;
}
int F_310 ( struct V_245 * V_246 ,
unsigned long V_247 , void * V_248 )
{
long V_79 = ( long ) V_248 ;
struct V_15 * V_16 = F_123 ( V_28 -> V_21 , V_79 ) ;
struct V_1 * V_2 = V_16 -> V_23 ;
struct V_4 * V_5 ;
switch ( V_247 ) {
case V_249 :
case V_250 :
F_307 ( V_79 ) ;
F_311 ( V_79 ) ;
F_312 ( V_79 ) ;
break;
case V_251 :
case V_252 :
F_274 ( V_79 ) ;
F_194 ( V_2 , - 1 ) ;
break;
case V_253 :
F_194 ( V_2 , V_79 ) ;
break;
case V_254 :
case V_255 :
F_15 (rsp)
F_191 ( V_5 ) ;
break;
case V_256 :
case V_257 :
case V_258 :
case V_259 :
F_15 (rsp) {
F_193 ( V_79 , V_5 ) ;
F_58 ( F_123 ( V_5 -> V_21 , V_79 ) ) ;
}
break;
default:
break;
}
return V_260 ;
}
static int F_313 ( struct V_245 * V_246 ,
unsigned long V_247 , void * V_248 )
{
switch ( V_247 ) {
case V_261 :
case V_262 :
if ( V_263 <= 256 )
F_314 () ;
break;
case V_264 :
case V_265 :
if ( V_263 <= 256 )
F_315 () ;
break;
default:
break;
}
return V_260 ;
}
static int T_7 F_316 ( void )
{
unsigned long V_26 ;
int V_266 = V_267 ;
struct V_1 * V_2 ;
struct V_4 * V_5 ;
struct V_268 V_201 ;
struct V_60 * V_269 ;
if ( F_52 ( V_270 ) && V_267 < 1 )
V_267 = 1 ;
else if ( V_267 < 0 )
V_267 = 0 ;
else if ( V_267 > 99 )
V_267 = 99 ;
if ( V_267 != V_266 )
F_317 ( L_81 ,
V_267 , V_266 ) ;
V_75 = 1 ;
F_15 (rsp) {
V_269 = F_318 ( F_173 , V_5 , L_82 , V_5 -> V_30 ) ;
F_229 ( F_319 ( V_269 ) ) ;
V_2 = F_46 ( V_5 ) ;
F_114 ( V_2 , V_26 ) ;
V_5 -> V_32 = V_269 ;
if ( V_267 ) {
V_201 . V_271 = V_267 ;
F_320 ( V_269 , V_272 , & V_201 ) ;
}
F_116 ( V_2 , V_26 ) ;
F_321 ( V_269 ) ;
}
F_322 () ;
F_323 () ;
return 0 ;
}
void F_324 ( void )
{
F_176 ( F_238 () != 1 ) ;
F_176 ( F_325 () > 0 ) ;
V_273 = 1 ;
}
static void T_7 F_326 ( int * V_274 , const int * V_275 )
{
int V_50 ;
if ( V_276 ) {
V_274 [ V_277 - 1 ] = V_278 ;
for ( V_50 = V_277 - 2 ; V_50 >= 0 ; V_50 -- )
V_274 [ V_50 ] = V_279 ;
} else {
int V_280 ;
int V_281 ;
V_281 = V_263 ;
for ( V_50 = V_277 - 1 ; V_50 >= 0 ; V_50 -- ) {
V_280 = V_275 [ V_50 ] ;
V_274 [ V_50 ] = ( V_281 + V_280 - 1 ) / V_280 ;
V_281 = V_280 ;
}
}
}
static void T_7 F_327 ( struct V_4 * V_5 )
{
static const char * const V_282 [] = V_283 ;
static const char * const V_284 [] = V_285 ;
static const char * const exp [] = V_286 ;
static struct V_287 V_288 [ V_289 ] ;
static struct V_287 V_290 [ V_289 ] ;
static struct V_287 V_291 [ V_289 ] ;
static T_8 V_292 = 0x1 ;
int V_275 [ V_289 ] ;
int V_274 [ V_289 ] ;
int V_293 = 1 ;
int V_50 ;
int V_91 ;
struct V_1 * V_2 ;
F_328 ( V_289 > F_108 ( V_282 ) ) ;
if ( V_277 <= 0 || V_277 > V_289 )
F_329 ( L_83 ) ;
for ( V_50 = 0 ; V_50 < V_277 ; V_50 ++ )
V_275 [ V_50 ] = V_294 [ V_50 ] ;
for ( V_50 = 1 ; V_50 < V_277 ; V_50 ++ )
V_5 -> V_114 [ V_50 ] = V_5 -> V_114 [ V_50 - 1 ] + V_275 [ V_50 - 1 ] ;
F_326 ( V_274 , V_275 ) ;
V_5 -> V_22 = V_292 ;
V_292 <<= 1 ;
for ( V_50 = V_277 - 1 ; V_50 >= 0 ; V_50 -- ) {
V_293 *= V_274 [ V_50 ] ;
V_2 = V_5 -> V_114 [ V_50 ] ;
for ( V_91 = 0 ; V_91 < V_275 [ V_50 ] ; V_91 ++ , V_2 ++ ) {
F_330 ( & F_331 ( V_2 , V_156 ) ) ;
F_332 ( & F_331 ( V_2 , V_156 ) ,
& V_288 [ V_50 ] , V_282 [ V_50 ] ) ;
F_330 ( & V_2 -> V_187 ) ;
F_332 ( & V_2 -> V_187 ,
& V_290 [ V_50 ] , V_284 [ V_50 ] ) ;
V_2 -> V_7 = V_5 -> V_7 ;
V_2 -> V_6 = V_5 -> V_6 ;
V_2 -> V_100 = 0 ;
V_2 -> V_129 = 0 ;
V_2 -> V_102 = V_91 * V_293 ;
V_2 -> V_101 = ( V_91 + 1 ) * V_293 - 1 ;
if ( V_2 -> V_101 >= V_263 )
V_2 -> V_101 = V_263 - 1 ;
if ( V_50 == 0 ) {
V_2 -> V_295 = 0 ;
V_2 -> V_74 = 0 ;
V_2 -> V_159 = NULL ;
} else {
V_2 -> V_295 = V_91 % V_274 [ V_50 - 1 ] ;
V_2 -> V_74 = 1UL << V_2 -> V_295 ;
V_2 -> V_159 = V_5 -> V_114 [ V_50 - 1 ] +
V_91 / V_274 [ V_50 - 1 ] ;
}
V_2 -> V_114 = V_50 ;
F_333 ( & V_2 -> V_224 ) ;
F_334 ( V_2 ) ;
F_303 ( & V_2 -> V_214 ) ;
F_332 ( & V_2 -> V_214 ,
& V_291 [ V_50 ] , exp [ V_50 ] ) ;
}
}
F_335 ( & V_5 -> V_120 ) ;
F_335 ( & V_5 -> V_212 ) ;
V_2 = V_5 -> V_114 [ V_277 - 1 ] ;
F_122 (i) {
while ( V_50 > V_2 -> V_101 )
V_2 ++ ;
F_123 ( V_5 -> V_21 , V_50 ) -> V_23 = V_2 ;
F_302 ( V_50 , V_5 ) ;
}
F_336 ( & V_5 -> V_296 , & V_297 ) ;
}
static void T_7 F_337 ( void )
{
T_9 V_298 ;
int V_50 ;
int V_299 [ V_289 ] ;
V_298 = V_300 + V_263 / V_301 ;
if ( V_149 == V_80 )
V_149 = V_298 ;
if ( V_108 == V_80 )
V_108 = V_298 ;
if ( V_278 == V_302 &&
V_263 == V_303 )
return;
F_41 ( L_84 ,
V_278 , V_263 ) ;
if ( V_278 < 2 ||
V_278 > sizeof( unsigned long ) * 8 ) {
V_278 = V_302 ;
F_176 ( 1 ) ;
return;
}
V_299 [ 0 ] = V_278 ;
for ( V_50 = 1 ; V_50 < V_289 ; V_50 ++ )
V_299 [ V_50 ] = V_299 [ V_50 - 1 ] * V_279 ;
if ( V_263 > V_299 [ V_289 - 1 ] ) {
V_278 = V_302 ;
F_176 ( 1 ) ;
return;
}
for ( V_50 = 0 ; V_263 > V_299 [ V_50 ] ; V_50 ++ ) {
}
V_277 = V_50 + 1 ;
for ( V_50 = 0 ; V_50 < V_277 ; V_50 ++ ) {
int V_304 = V_299 [ ( V_277 - 1 ) - V_50 ] ;
V_294 [ V_50 ] = F_338 ( V_263 , V_304 ) ;
}
V_125 = 0 ;
for ( V_50 = 0 ; V_50 < V_277 ; V_50 ++ )
V_125 += V_294 [ V_50 ] ;
}
static void T_7 F_339 ( struct V_4 * V_5 )
{
int V_114 = 0 ;
struct V_1 * V_2 ;
F_41 ( L_85 ) ;
F_41 ( L_86 ) ;
F_158 (rsp, rnp) {
if ( V_2 -> V_114 != V_114 ) {
F_124 ( L_68 ) ;
F_41 ( L_86 ) ;
V_114 = V_2 -> V_114 ;
}
F_124 ( L_87 , V_2 -> V_102 , V_2 -> V_101 , V_2 -> V_295 ) ;
}
F_124 ( L_68 ) ;
}
void T_7 F_340 ( void )
{
int V_79 ;
F_341 () ;
F_342 () ;
F_337 () ;
F_327 ( & V_29 ) ;
F_327 ( & V_13 ) ;
if ( V_305 )
F_339 ( & V_13 ) ;
F_343 () ;
F_344 ( V_193 , F_218 ) ;
F_345 ( F_310 , 0 ) ;
F_346 ( F_313 , 0 ) ;
F_347 (cpu)
F_310 ( NULL , V_249 , ( void * ) ( long ) V_79 ) ;
}
