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
return 1 ;
} else {
if ( F_49 ( F_2 ( V_16 -> V_7 ) + V_80 / 4 ,
V_16 -> V_23 -> V_7 ) )
F_97 ( V_16 -> V_81 , true ) ;
return 0 ;
}
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
F_103 ( V_16 -> V_79 ) ;
V_16 -> V_5 -> V_90 += 5 ;
} else if ( F_100 ( V_87 , V_16 -> V_5 -> V_90 ) ) {
F_103 ( V_16 -> V_79 ) ;
V_16 -> V_5 -> V_90 += 5 ;
}
}
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
F_116 ( & V_2 -> V_103 , V_26 ) ;
}
}
static void F_117 ( struct V_4 * V_5 , unsigned long V_7 )
{
int V_79 ;
long V_104 ;
unsigned long V_26 ;
unsigned long V_97 ;
unsigned long V_91 ;
int V_105 = 0 ;
struct V_1 * V_2 = F_46 ( V_5 ) ;
long V_106 = 0 ;
F_114 ( V_2 , V_26 ) ;
V_104 = V_87 - F_2 ( V_5 -> V_92 ) ;
if ( V_104 < V_107 || ! F_3 ( V_5 ) ) {
F_116 ( & V_2 -> V_103 , V_26 ) ;
return;
}
F_97 ( V_5 -> V_92 ,
V_87 + 3 * F_106 () + 3 ) ;
F_116 ( & V_2 -> V_103 , V_26 ) ;
F_110 ( L_23 ,
V_5 -> V_30 ) ;
F_118 () ;
F_113 (rsp, rnp) {
F_114 ( V_2 , V_26 ) ;
V_105 += F_119 ( V_2 ) ;
if ( V_2 -> V_100 != 0 ) {
for ( V_79 = 0 ; V_79 <= V_2 -> V_101 - V_2 -> V_102 ; V_79 ++ )
if ( V_2 -> V_100 & ( 1UL << V_79 ) ) {
F_120 ( V_5 ,
V_2 -> V_102 + V_79 ) ;
V_105 ++ ;
}
}
F_116 ( & V_2 -> V_103 , V_26 ) ;
}
F_121 () ;
F_122 (cpu)
V_106 += F_123 ( V_5 -> V_21 , V_79 ) -> V_108 ;
F_124 ( L_24 ,
F_55 () , ( long ) ( V_87 - V_5 -> V_86 ) ,
( long ) V_5 -> V_7 , ( long ) V_5 -> V_6 , V_106 ) ;
if ( V_105 ) {
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
V_109 ,
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
long V_106 = 0 ;
F_110 ( L_27 , V_5 -> V_30 ) ;
F_118 () ;
F_120 ( V_5 , F_55 () ) ;
F_121 () ;
F_122 (cpu)
V_106 += F_123 ( V_5 -> V_21 , V_79 ) -> V_108 ;
F_124 ( L_28 ,
V_87 - V_5 -> V_86 ,
( long ) V_5 -> V_7 , ( long ) V_5 -> V_6 , V_106 ) ;
F_109 ( V_5 ) ;
F_112 ( V_5 ) ;
F_114 ( V_2 , V_26 ) ;
if ( F_100 ( V_87 , F_2 ( V_5 -> V_92 ) ) )
F_97 ( V_5 -> V_92 ,
V_87 + 3 * F_106 () + 3 ) ;
F_116 ( & V_2 -> V_103 , V_26 ) ;
F_103 ( F_55 () ) ;
}
static void F_127 ( struct V_4 * V_5 , struct V_15 * V_16 )
{
unsigned long V_6 ;
unsigned long V_7 ;
unsigned long V_110 ;
unsigned long V_91 ;
unsigned long V_111 ;
struct V_1 * V_2 ;
if ( V_112 || ! F_3 ( V_5 ) )
return;
V_91 = V_87 ;
V_7 = F_2 ( V_5 -> V_7 ) ;
F_128 () ;
V_111 = F_2 ( V_5 -> V_92 ) ;
F_128 () ;
V_110 = F_2 ( V_5 -> V_86 ) ;
F_128 () ;
V_6 = F_2 ( V_5 -> V_6 ) ;
if ( F_100 ( V_6 , V_7 ) ||
F_49 ( V_91 , V_111 ) ||
F_100 ( V_110 , V_111 ) )
return;
V_2 = V_16 -> V_23 ;
if ( F_3 ( V_5 ) &&
( F_2 ( V_2 -> V_100 ) & V_16 -> V_74 ) ) {
F_126 ( V_5 ) ;
} else if ( F_3 ( V_5 ) &&
F_100 ( V_91 , V_111 + V_107 ) ) {
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
for ( V_50 = 0 ; V_50 < V_113 ; V_50 ++ )
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
unsigned long V_114 , const char * V_10 )
{
F_135 ( V_16 -> V_5 -> V_30 , V_2 -> V_7 ,
V_2 -> V_6 , V_114 , V_2 -> V_115 ,
V_2 -> V_102 , V_2 -> V_101 , V_10 ) ;
}
static bool V_61
F_136 ( struct V_1 * V_2 , struct V_15 * V_16 ,
unsigned long * V_116 )
{
unsigned long V_114 ;
int V_50 ;
bool V_73 = false ;
struct V_1 * V_117 = F_46 ( V_16 -> V_5 ) ;
V_114 = F_133 ( V_16 -> V_5 , V_2 ) ;
F_134 ( V_2 , V_16 , V_114 , F_7 ( L_29 ) ) ;
if ( V_2 -> V_49 [ V_114 & 0x1 ] ) {
F_134 ( V_2 , V_16 , V_114 , F_7 ( L_30 ) ) ;
goto V_118;
}
if ( V_2 -> V_7 != V_2 -> V_6 ||
F_2 ( V_117 -> V_7 ) != F_2 ( V_117 -> V_6 ) ) {
V_2 -> V_49 [ V_114 & 0x1 ] ++ ;
F_134 ( V_2 , V_16 , V_114 , F_7 ( L_31 ) ) ;
goto V_118;
}
if ( V_2 != V_117 )
F_137 ( V_117 ) ;
V_114 = F_133 ( V_16 -> V_5 , V_117 ) ;
for ( V_50 = V_45 ; V_50 < V_51 ; V_50 ++ )
if ( F_49 ( V_114 , V_16 -> V_54 [ V_50 ] ) )
V_16 -> V_54 [ V_50 ] = V_114 ;
if ( V_117 -> V_49 [ V_114 & 0x1 ] ) {
F_134 ( V_2 , V_16 , V_114 , F_7 ( L_32 ) ) ;
goto V_119;
}
V_117 -> V_49 [ V_114 & 0x1 ] ++ ;
if ( V_117 -> V_7 != V_117 -> V_6 ) {
F_134 ( V_2 , V_16 , V_114 , F_7 ( L_33 ) ) ;
} else {
F_134 ( V_2 , V_16 , V_114 , F_7 ( L_34 ) ) ;
V_73 = F_138 ( V_16 -> V_5 , V_117 , V_16 ) ;
}
V_119:
if ( V_2 != V_117 )
F_139 ( & V_117 -> V_103 ) ;
V_118:
if ( V_116 != NULL )
* V_116 = V_114 ;
return V_73 ;
}
static int F_140 ( struct V_4 * V_5 , struct V_1 * V_2 )
{
int V_114 = V_2 -> V_6 ;
int V_120 ;
struct V_15 * V_16 = F_10 ( V_5 -> V_21 ) ;
F_141 ( V_5 , V_2 ) ;
V_2 -> V_49 [ V_114 & 0x1 ] = 0 ;
V_120 = V_2 -> V_49 [ ( V_114 + 1 ) & 0x1 ] ;
F_134 ( V_2 , V_16 , V_114 ,
V_120 ? F_7 ( L_35 ) : F_7 ( L_36 ) ) ;
return V_120 ;
}
static void F_142 ( struct V_4 * V_5 )
{
if ( V_59 == V_5 -> V_32 ||
! F_2 ( V_5 -> V_41 ) ||
! V_5 -> V_32 )
return;
F_143 ( & V_5 -> V_121 ) ;
}
static bool F_144 ( struct V_4 * V_5 , struct V_1 * V_2 ,
struct V_15 * V_16 )
{
unsigned long V_114 ;
int V_50 ;
bool V_73 ;
if ( ! V_16 -> V_44 [ V_51 ] || ! * V_16 -> V_44 [ V_45 ] )
return false ;
V_114 = F_133 ( V_5 , V_2 ) ;
for ( V_50 = V_51 - 1 ; V_50 > V_45 ; V_50 -- )
if ( V_16 -> V_44 [ V_50 ] != V_16 -> V_44 [ V_50 - 1 ] &&
! F_100 ( V_16 -> V_54 [ V_50 ] , V_114 ) )
break;
if ( ++ V_50 >= V_51 )
return false ;
for (; V_50 <= V_51 ; V_50 ++ ) {
V_16 -> V_44 [ V_50 ] = V_16 -> V_44 [ V_51 ] ;
V_16 -> V_54 [ V_50 ] = V_114 ;
}
V_73 = F_136 ( V_2 , V_16 , NULL ) ;
if ( ! * V_16 -> V_44 [ V_53 ] )
F_6 ( V_5 -> V_30 , V_16 -> V_7 , F_7 ( L_37 ) ) ;
else
F_6 ( V_5 -> V_30 , V_16 -> V_7 , F_7 ( L_38 ) ) ;
return V_73 ;
}
static bool F_145 ( struct V_4 * V_5 , struct V_1 * V_2 ,
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
return F_144 ( V_5 , V_2 , V_16 ) ;
}
static bool F_146 ( struct V_4 * V_5 , struct V_1 * V_2 ,
struct V_15 * V_16 )
{
bool V_73 ;
if ( V_16 -> V_6 == V_2 -> V_6 &&
! F_25 ( F_2 ( V_16 -> V_81 ) ) ) {
V_73 = F_144 ( V_5 , V_2 , V_16 ) ;
} else {
V_73 = F_145 ( V_5 , V_2 , V_16 ) ;
V_16 -> V_6 = V_2 -> V_6 ;
F_6 ( V_5 -> V_30 , V_16 -> V_7 , F_7 ( L_39 ) ) ;
}
if ( V_16 -> V_7 != V_2 -> V_7 || F_25 ( F_2 ( V_16 -> V_81 ) ) ) {
V_16 -> V_7 = V_2 -> V_7 ;
F_6 ( V_5 -> V_30 , V_16 -> V_7 , F_7 ( L_40 ) ) ;
V_16 -> V_9 . V_11 . V_12 = true ;
V_16 -> V_122 = F_5 ( V_27 ) ;
V_16 -> V_123 = ! ! ( V_2 -> V_100 & V_16 -> V_74 ) ;
F_147 ( V_16 ) ;
F_97 ( V_16 -> V_81 , false ) ;
}
return V_73 ;
}
static void F_148 ( struct V_4 * V_5 , struct V_15 * V_16 )
{
unsigned long V_26 ;
bool V_124 ;
struct V_1 * V_2 ;
F_27 ( V_26 ) ;
V_2 = V_16 -> V_23 ;
if ( ( V_16 -> V_7 == F_2 ( V_2 -> V_7 ) &&
V_16 -> V_6 == F_2 ( V_2 -> V_6 ) &&
! F_25 ( F_2 ( V_16 -> V_81 ) ) ) ||
! F_149 ( V_2 ) ) {
F_28 ( V_26 ) ;
return;
}
V_124 = F_146 ( V_5 , V_2 , V_16 ) ;
F_116 ( & V_2 -> V_103 , V_26 ) ;
if ( V_124 )
F_142 ( V_5 ) ;
}
static void F_150 ( struct V_4 * V_5 , int V_125 )
{
if ( V_125 > 0 &&
! ( V_5 -> V_7 % ( V_126 * V_127 * V_125 ) ) )
F_151 ( V_125 ) ;
}
static bool F_152 ( struct V_4 * V_5 )
{
unsigned long V_128 ;
struct V_15 * V_16 ;
struct V_1 * V_2 = F_46 ( V_5 ) ;
F_97 ( V_5 -> V_98 , V_87 ) ;
F_153 ( V_2 ) ;
if ( ! F_2 ( V_5 -> V_41 ) ) {
F_154 ( & V_2 -> V_103 ) ;
return false ;
}
F_97 ( V_5 -> V_41 , 0 ) ;
if ( F_61 ( F_3 ( V_5 ) ) ) {
F_154 ( & V_2 -> V_103 ) ;
return false ;
}
F_104 ( V_5 ) ;
F_155 ( & V_5 -> V_7 , V_5 -> V_7 + 1 ) ;
F_6 ( V_5 -> V_30 , V_5 -> V_7 , F_7 ( L_41 ) ) ;
F_154 ( & V_2 -> V_103 ) ;
F_113 (rsp, rnp) {
F_150 ( V_5 , V_129 ) ;
F_153 ( V_2 ) ;
if ( V_2 -> V_130 == V_2 -> V_3 &&
! V_2 -> V_131 ) {
F_154 ( & V_2 -> V_103 ) ;
continue;
}
V_128 = V_2 -> V_130 ;
V_2 -> V_130 = V_2 -> V_3 ;
if ( ! V_128 != ! V_2 -> V_130 ) {
if ( ! V_128 )
F_156 ( V_2 ) ;
else if ( F_157 ( V_2 ) )
V_2 -> V_131 = true ;
else
F_158 ( V_2 ) ;
}
if ( V_2 -> V_131 &&
( ! F_157 ( V_2 ) ||
V_2 -> V_130 ) ) {
V_2 -> V_131 = false ;
F_158 ( V_2 ) ;
}
F_154 ( & V_2 -> V_103 ) ;
}
F_159 (rsp, rnp) {
F_150 ( V_5 , V_132 ) ;
F_153 ( V_2 ) ;
V_16 = F_10 ( V_5 -> V_21 ) ;
F_160 ( V_2 ) ;
V_2 -> V_100 = V_2 -> V_130 ;
F_97 ( V_2 -> V_7 , V_5 -> V_7 ) ;
if ( F_61 ( V_2 -> V_6 != V_5 -> V_6 ) )
F_97 ( V_2 -> V_6 , V_5 -> V_6 ) ;
if ( V_2 == V_16 -> V_23 )
( void ) F_146 ( V_5 , V_2 , V_16 ) ;
F_161 ( V_2 ) ;
F_162 ( V_5 -> V_30 , V_2 -> V_7 ,
V_2 -> V_115 , V_2 -> V_102 ,
V_2 -> V_101 , V_2 -> V_100 ) ;
F_154 ( & V_2 -> V_103 ) ;
F_163 () ;
F_97 ( V_5 -> V_98 , V_87 ) ;
}
return true ;
}
static bool F_164 ( struct V_4 * V_5 , int * V_133 )
{
struct V_1 * V_2 = F_46 ( V_5 ) ;
* V_133 = F_2 ( V_5 -> V_41 ) ;
if ( * V_133 & V_134 )
return true ;
if ( ! F_2 ( V_2 -> V_100 ) && ! F_165 ( V_2 ) )
return true ;
return false ;
}
static void F_166 ( struct V_4 * V_5 , bool V_135 )
{
bool V_76 = false ;
unsigned long V_77 ;
struct V_1 * V_2 = F_46 ( V_5 ) ;
F_97 ( V_5 -> V_98 , V_87 ) ;
V_5 -> V_94 ++ ;
if ( V_135 ) {
if ( F_167 ( V_5 ) ) {
V_76 = true ;
V_77 = V_87 - V_80 / 4 ;
}
F_168 ( V_5 , F_93 ,
& V_76 , & V_77 ) ;
F_169 ( V_5 , V_76 , V_77 ) ;
} else {
V_76 = true ;
F_168 ( V_5 , F_98 , & V_76 , & V_77 ) ;
}
if ( F_2 ( V_5 -> V_41 ) & V_134 ) {
F_153 ( V_2 ) ;
F_97 ( V_5 -> V_41 ,
F_2 ( V_5 -> V_41 ) & ~ V_134 ) ;
F_154 ( & V_2 -> V_103 ) ;
}
}
static void F_170 ( struct V_4 * V_5 )
{
unsigned long V_136 ;
bool V_137 = false ;
int V_138 = 0 ;
struct V_15 * V_16 ;
struct V_1 * V_2 = F_46 ( V_5 ) ;
F_97 ( V_5 -> V_98 , V_87 ) ;
F_153 ( V_2 ) ;
V_136 = V_87 - V_5 -> V_86 ;
if ( V_136 > V_5 -> V_139 )
V_5 -> V_139 = V_136 ;
F_154 ( & V_2 -> V_103 ) ;
F_159 (rsp, rnp) {
F_153 ( V_2 ) ;
F_61 ( F_165 ( V_2 ) ) ;
F_61 ( V_2 -> V_100 ) ;
F_97 ( V_2 -> V_6 , V_5 -> V_7 ) ;
V_16 = F_10 ( V_5 -> V_21 ) ;
if ( V_2 == V_16 -> V_23 )
V_137 = F_146 ( V_5 , V_2 , V_16 ) || V_137 ;
V_138 += F_140 ( V_5 , V_2 ) ;
F_154 ( & V_2 -> V_103 ) ;
F_163 () ;
F_97 ( V_5 -> V_98 , V_87 ) ;
F_150 ( V_5 , V_140 ) ;
}
V_2 = F_46 ( V_5 ) ;
F_153 ( V_2 ) ;
F_171 ( V_2 , V_138 ) ;
F_97 ( V_5 -> V_6 , V_5 -> V_7 ) ;
F_6 ( V_5 -> V_30 , V_5 -> V_6 , F_7 ( L_42 ) ) ;
V_5 -> V_31 = V_141 ;
V_16 = F_10 ( V_5 -> V_21 ) ;
V_137 = F_145 ( V_5 , V_2 , V_16 ) || V_137 ;
if ( V_137 || F_48 ( V_5 , V_16 ) ) {
F_97 ( V_5 -> V_41 , V_142 ) ;
F_6 ( V_5 -> V_30 ,
F_2 ( V_5 -> V_7 ) ,
F_7 ( L_43 ) ) ;
}
F_154 ( & V_2 -> V_103 ) ;
}
static int T_3 F_172 ( void * V_143 )
{
bool V_144 ;
int V_145 ;
unsigned long V_91 ;
int V_73 ;
struct V_4 * V_5 = V_143 ;
struct V_1 * V_2 = F_46 ( V_5 ) ;
F_173 () ;
for (; ; ) {
for (; ; ) {
F_6 ( V_5 -> V_30 ,
F_2 ( V_5 -> V_7 ) ,
F_7 ( L_44 ) ) ;
V_5 -> V_31 = V_146 ;
F_174 ( V_5 -> V_121 ,
F_2 ( V_5 -> V_41 ) &
V_142 ) ;
V_5 -> V_31 = V_147 ;
if ( F_152 ( V_5 ) )
break;
F_163 () ;
F_97 ( V_5 -> V_98 , V_87 ) ;
F_175 ( F_176 ( V_59 ) ) ;
F_6 ( V_5 -> V_30 ,
F_2 ( V_5 -> V_7 ) ,
F_7 ( L_45 ) ) ;
}
V_144 = true ;
V_91 = V_148 ;
if ( V_91 > V_99 ) {
V_91 = V_99 ;
V_148 = V_99 ;
}
V_73 = 0 ;
for (; ; ) {
if ( ! V_73 )
V_5 -> V_149 = V_87 + V_91 ;
F_6 ( V_5 -> V_30 ,
F_2 ( V_5 -> V_7 ) ,
F_7 ( L_46 ) ) ;
V_5 -> V_31 = V_150 ;
V_73 = F_177 ( V_5 -> V_121 ,
F_164 ( V_5 , & V_145 ) , V_91 ) ;
V_5 -> V_31 = V_151 ;
if ( ! F_2 ( V_2 -> V_100 ) &&
! F_165 ( V_2 ) )
break;
if ( F_100 ( V_87 , V_5 -> V_149 ) ||
( V_145 & V_134 ) ) {
F_6 ( V_5 -> V_30 ,
F_2 ( V_5 -> V_7 ) ,
F_7 ( L_47 ) ) ;
F_166 ( V_5 , V_144 ) ;
V_144 = false ;
F_6 ( V_5 -> V_30 ,
F_2 ( V_5 -> V_7 ) ,
F_7 ( L_48 ) ) ;
F_163 () ;
F_97 ( V_5 -> V_98 , V_87 ) ;
} else {
F_163 () ;
F_97 ( V_5 -> V_98 , V_87 ) ;
F_175 ( F_176 ( V_59 ) ) ;
F_6 ( V_5 -> V_30 ,
F_2 ( V_5 -> V_7 ) ,
F_7 ( L_49 ) ) ;
}
V_91 = V_109 ;
if ( V_91 > V_99 ) {
V_91 = V_99 ;
V_109 = V_99 ;
} else if ( V_91 < 1 ) {
V_91 = 1 ;
V_109 = 1 ;
}
}
V_5 -> V_31 = V_152 ;
F_170 ( V_5 ) ;
V_5 -> V_31 = V_153 ;
}
}
static bool
F_138 ( struct V_4 * V_5 , struct V_1 * V_2 ,
struct V_15 * V_16 )
{
if ( ! V_5 -> V_32 || ! F_48 ( V_5 , V_16 ) ) {
return false ;
}
F_97 ( V_5 -> V_41 , V_142 ) ;
F_6 ( V_5 -> V_30 , F_2 ( V_5 -> V_7 ) ,
F_7 ( L_43 ) ) ;
return true ;
}
static bool F_178 ( struct V_4 * V_5 )
{
struct V_15 * V_16 = F_10 ( V_5 -> V_21 ) ;
struct V_1 * V_2 = F_46 ( V_5 ) ;
bool V_73 = false ;
V_73 = F_145 ( V_5 , V_2 , V_16 ) || V_73 ;
V_73 = F_138 ( V_5 , V_2 , V_16 ) || V_73 ;
return V_73 ;
}
static void F_179 ( struct V_4 * V_5 , unsigned long V_26 )
__releases( rcu_get_root( V_5 )->lock
static void
F_180 ( unsigned long V_154 , struct V_4 * V_5 ,
struct V_1 * V_2 , unsigned long V_110 , unsigned long V_26 )
__releases( V_2 -> V_103 )
{
unsigned long V_128 = 0 ;
struct V_1 * V_155 ;
for (; ; ) {
if ( ! ( V_2 -> V_100 & V_154 ) || V_2 -> V_7 != V_110 ) {
F_116 ( & V_2 -> V_103 , V_26 ) ;
return;
}
F_61 ( V_128 ) ;
V_2 -> V_100 &= ~ V_154 ;
F_181 ( V_5 -> V_30 , V_2 -> V_7 ,
V_154 , V_2 -> V_100 , V_2 -> V_115 ,
V_2 -> V_102 , V_2 -> V_101 ,
! ! V_2 -> V_156 ) ;
if ( V_2 -> V_100 != 0 || F_165 ( V_2 ) ) {
F_116 ( & V_2 -> V_103 , V_26 ) ;
return;
}
V_154 = V_2 -> V_74 ;
if ( V_2 -> V_157 == NULL ) {
break;
}
F_116 ( & V_2 -> V_103 , V_26 ) ;
V_155 = V_2 ;
V_2 = V_2 -> V_157 ;
F_114 ( V_2 , V_26 ) ;
V_128 = V_155 -> V_100 ;
}
F_179 ( V_5 , V_26 ) ;
}
static void F_182 ( struct V_4 * V_5 ,
struct V_1 * V_2 , unsigned long V_26 )
__releases( V_2 -> V_103 )
{
unsigned long V_110 ;
unsigned long V_154 ;
struct V_1 * V_158 ;
if ( V_28 == & V_13 || V_5 != V_28 ||
V_2 -> V_100 != 0 || F_165 ( V_2 ) ) {
F_116 ( & V_2 -> V_103 , V_26 ) ;
return;
}
V_158 = V_2 -> V_157 ;
if ( V_158 == NULL ) {
F_179 ( V_5 , V_26 ) ;
return;
}
V_110 = V_2 -> V_7 ;
V_154 = V_2 -> V_74 ;
F_139 ( & V_2 -> V_103 ) ;
F_137 ( V_158 ) ;
F_180 ( V_154 , V_5 , V_158 , V_110 , V_26 ) ;
}
static void
F_183 ( int V_79 , struct V_4 * V_5 , struct V_15 * V_16 )
{
unsigned long V_26 ;
unsigned long V_154 ;
bool V_124 ;
struct V_1 * V_2 ;
V_2 = V_16 -> V_23 ;
F_114 ( V_2 , V_26 ) ;
if ( ( V_16 -> V_9 . V_11 . V_12 &&
V_16 -> V_122 == F_5 ( V_27 ) ) ||
V_16 -> V_7 != V_2 -> V_7 || V_2 -> V_6 == V_2 -> V_7 ||
V_16 -> V_81 ) {
V_16 -> V_9 . V_11 . V_12 = true ;
V_16 -> V_122 = F_5 ( V_27 ) ;
F_116 ( & V_2 -> V_103 , V_26 ) ;
return;
}
V_154 = V_16 -> V_74 ;
if ( ( V_2 -> V_100 & V_154 ) == 0 ) {
F_116 ( & V_2 -> V_103 , V_26 ) ;
} else {
V_16 -> V_123 = 0 ;
V_124 = F_144 ( V_5 , V_2 , V_16 ) ;
F_180 ( V_154 , V_5 , V_2 , V_2 -> V_7 , V_26 ) ;
if ( V_124 )
F_142 ( V_5 ) ;
}
}
static void
F_184 ( struct V_4 * V_5 , struct V_15 * V_16 )
{
F_148 ( V_5 , V_16 ) ;
if ( ! V_16 -> V_123 )
return;
if ( V_16 -> V_9 . V_11 . V_12 &&
V_16 -> V_122 == F_5 ( V_27 ) )
return;
F_183 ( V_16 -> V_79 , V_5 , V_16 ) ;
}
static void
F_185 ( int V_79 , struct V_4 * V_5 ,
struct V_1 * V_2 , struct V_15 * V_16 )
{
if ( ! F_52 ( V_159 ) || F_186 ( V_16 -> V_79 ) )
return;
if ( V_16 -> V_43 != NULL ) {
V_5 -> V_160 += V_16 -> V_160 ;
V_5 -> V_108 += V_16 -> V_108 ;
V_16 -> V_161 += V_16 -> V_108 ;
V_16 -> V_160 = 0 ;
F_97 ( V_16 -> V_108 , 0 ) ;
}
if ( * V_16 -> V_44 [ V_45 ] != NULL ) {
* V_5 -> V_162 = * V_16 -> V_44 [ V_45 ] ;
V_5 -> V_162 = V_16 -> V_44 [ V_51 ] ;
* V_16 -> V_44 [ V_45 ] = NULL ;
}
if ( V_16 -> V_43 != NULL ) {
* V_5 -> V_163 = V_16 -> V_43 ;
V_5 -> V_163 = V_16 -> V_44 [ V_45 ] ;
}
F_131 ( V_16 ) ;
V_16 -> V_44 [ V_51 ] = NULL ;
}
static void F_187 ( struct V_4 * V_5 , unsigned long V_26 )
{
int V_50 ;
struct V_15 * V_16 = F_16 ( V_5 -> V_21 ) ;
if ( ! F_52 ( V_159 ) ||
F_188 ( V_5 , V_16 , V_26 ) )
return;
V_16 -> V_160 += V_5 -> V_160 ;
V_16 -> V_108 += V_5 -> V_108 ;
V_16 -> V_164 += V_5 -> V_108 ;
if ( V_5 -> V_160 != V_5 -> V_108 )
F_189 () ;
V_5 -> V_160 = 0 ;
V_5 -> V_108 = 0 ;
if ( V_5 -> V_165 != NULL ) {
* V_5 -> V_163 = * V_16 -> V_44 [ V_45 ] ;
* V_16 -> V_44 [ V_45 ] = V_5 -> V_165 ;
for ( V_50 = V_113 - 1 ; V_50 >= V_45 ; V_50 -- )
if ( V_16 -> V_44 [ V_50 ] == V_16 -> V_44 [ V_45 ] )
V_16 -> V_44 [ V_50 ] = V_5 -> V_163 ;
V_5 -> V_165 = NULL ;
V_5 -> V_163 = & V_5 -> V_165 ;
}
if ( V_5 -> V_166 != NULL ) {
* V_16 -> V_44 [ V_51 ] = V_5 -> V_166 ;
V_16 -> V_44 [ V_51 ] = V_5 -> V_162 ;
V_5 -> V_166 = NULL ;
V_5 -> V_162 = & V_5 -> V_166 ;
}
}
static void F_190 ( struct V_4 * V_5 )
{
F_191 (unsigned long mask) ;
F_191 ( struct V_15 * V_16 = F_10 ( V_5 -> V_21 ) ) ;
F_191 ( struct V_1 * V_2 = V_16 -> V_23 ) ;
if ( ! F_52 ( V_159 ) )
return;
F_191 ( V_154 = V_16 -> V_74 ) ;
F_6 ( V_5 -> V_30 ,
V_2 -> V_7 + 1 - ! ! ( V_2 -> V_100 & V_154 ) ,
F_7 ( L_50 ) ) ;
}
static void F_158 ( struct V_1 * V_167 )
{
long V_154 ;
struct V_1 * V_2 = V_167 ;
if ( ! F_52 ( V_159 ) ||
V_2 -> V_130 || F_157 ( V_2 ) )
return;
for (; ; ) {
V_154 = V_2 -> V_74 ;
V_2 = V_2 -> V_157 ;
if ( ! V_2 )
break;
F_137 ( V_2 ) ;
V_2 -> V_130 &= ~ V_154 ;
V_2 -> V_100 &= ~ V_154 ;
if ( V_2 -> V_130 ) {
F_139 ( & V_2 -> V_103 ) ;
return;
}
F_139 ( & V_2 -> V_103 ) ;
}
}
static void F_192 ( int V_79 , struct V_4 * V_5 )
{
unsigned long V_26 ;
unsigned long V_154 ;
struct V_15 * V_16 = F_123 ( V_5 -> V_21 , V_79 ) ;
struct V_1 * V_2 = V_16 -> V_23 ;
if ( ! F_52 ( V_159 ) )
return;
V_154 = V_16 -> V_74 ;
F_114 ( V_2 , V_26 ) ;
V_2 -> V_3 &= ~ V_154 ;
F_116 ( & V_2 -> V_103 , V_26 ) ;
}
static void F_193 ( int V_79 , struct V_4 * V_5 )
{
unsigned long V_26 ;
struct V_15 * V_16 = F_123 ( V_5 -> V_21 , V_79 ) ;
struct V_1 * V_2 = V_16 -> V_23 ;
if ( ! F_52 ( V_159 ) )
return;
F_194 ( V_2 , - 1 ) ;
F_195 ( & V_5 -> V_168 , V_26 ) ;
F_185 ( V_79 , V_5 , V_2 , V_16 ) ;
F_187 ( V_5 , V_26 ) ;
F_116 ( & V_5 -> V_168 , V_26 ) ;
F_57 ( V_16 -> V_108 != 0 || V_16 -> V_43 != NULL ,
L_51 ,
V_79 , V_16 -> V_108 , V_16 -> V_43 ) ;
}
static void F_196 ( struct V_4 * V_5 , struct V_15 * V_16 )
{
unsigned long V_26 ;
struct V_169 * V_170 , * V_171 , * * V_172 ;
long V_173 , V_174 , V_175 ;
int V_50 ;
if ( ! F_45 ( V_16 ) ) {
F_197 ( V_5 -> V_30 , V_16 -> V_160 , V_16 -> V_108 , 0 ) ;
F_198 ( V_5 -> V_30 , 0 , ! ! F_2 ( V_16 -> V_43 ) ,
F_199 () , F_53 ( V_59 ) ,
F_200 () ) ;
return;
}
F_27 ( V_26 ) ;
F_61 ( F_101 ( F_55 () ) ) ;
V_173 = V_16 -> V_176 ;
F_197 ( V_5 -> V_30 , V_16 -> V_160 , V_16 -> V_108 , V_173 ) ;
V_171 = V_16 -> V_43 ;
V_16 -> V_43 = * V_16 -> V_44 [ V_45 ] ;
* V_16 -> V_44 [ V_45 ] = NULL ;
V_172 = V_16 -> V_44 [ V_45 ] ;
for ( V_50 = V_113 - 1 ; V_50 >= 0 ; V_50 -- )
if ( V_16 -> V_44 [ V_50 ] == V_16 -> V_44 [ V_45 ] )
V_16 -> V_44 [ V_50 ] = & V_16 -> V_43 ;
F_28 ( V_26 ) ;
V_174 = V_175 = 0 ;
while ( V_171 ) {
V_170 = V_171 -> V_170 ;
F_201 ( V_170 ) ;
F_202 ( V_171 ) ;
if ( F_203 ( V_5 -> V_30 , V_171 ) )
V_175 ++ ;
V_171 = V_170 ;
if ( ++ V_174 >= V_173 &&
( F_199 () ||
( ! F_53 ( V_59 ) && ! F_200 () ) ) )
break;
}
F_27 ( V_26 ) ;
F_198 ( V_5 -> V_30 , V_174 , ! ! V_171 , F_199 () ,
F_53 ( V_59 ) ,
F_200 () ) ;
if ( V_171 != NULL ) {
* V_172 = V_16 -> V_43 ;
V_16 -> V_43 = V_171 ;
for ( V_50 = 0 ; V_50 < V_113 ; V_50 ++ )
if ( & V_16 -> V_43 == V_16 -> V_44 [ V_50 ] )
V_16 -> V_44 [ V_50 ] = V_172 ;
else
break;
}
F_17 () ;
V_16 -> V_160 -= V_175 ;
F_97 ( V_16 -> V_108 , V_16 -> V_108 - V_174 ) ;
V_16 -> V_177 += V_174 ;
if ( V_16 -> V_176 == V_178 && V_16 -> V_108 <= V_179 )
V_16 -> V_176 = V_176 ;
if ( V_16 -> V_108 == 0 && V_16 -> V_180 != 0 ) {
V_16 -> V_180 = 0 ;
V_16 -> V_181 = V_5 -> V_94 ;
} else if ( V_16 -> V_108 < V_16 -> V_180 - V_182 )
V_16 -> V_180 = V_16 -> V_108 ;
F_61 ( ( V_16 -> V_43 == NULL ) != ( V_16 -> V_108 == 0 ) ) ;
F_28 ( V_26 ) ;
if ( F_45 ( V_16 ) )
F_204 () ;
}
void F_205 ( int V_56 )
{
F_23 ( F_7 ( L_52 ) ) ;
F_206 () ;
if ( V_56 || F_92 () ) {
F_4 () ;
F_11 () ;
} else if ( ! F_207 () ) {
F_11 () ;
}
F_208 () ;
if ( F_209 () )
F_204 () ;
if ( V_56 )
F_210 ( V_59 ) ;
F_23 ( F_7 ( L_53 ) ) ;
}
static void F_168 ( struct V_4 * V_5 ,
int (* F_211)( struct V_15 * V_5 , bool * V_76 ,
unsigned long * V_77 ) ,
bool * V_76 , unsigned long * V_77 )
{
unsigned long V_183 ;
int V_79 ;
unsigned long V_26 ;
unsigned long V_154 ;
struct V_1 * V_2 ;
F_113 (rsp, rnp) {
F_163 () ;
V_154 = 0 ;
F_114 ( V_2 , V_26 ) ;
if ( V_2 -> V_100 == 0 ) {
if ( V_28 == & V_13 ||
V_5 != V_28 ||
F_165 ( V_2 ) ) {
F_212 ( V_2 , V_26 ) ;
continue;
}
if ( V_2 -> V_157 &&
( V_2 -> V_157 -> V_100 & V_2 -> V_74 ) ) {
F_182 ( V_5 , V_2 , V_26 ) ;
continue;
}
}
V_79 = V_2 -> V_102 ;
V_183 = 1 ;
for (; V_79 <= V_2 -> V_101 ; V_79 ++ , V_183 <<= 1 ) {
if ( ( V_2 -> V_100 & V_183 ) != 0 ) {
if ( F_211 ( F_123 ( V_5 -> V_21 , V_79 ) , V_76 , V_77 ) )
V_154 |= V_183 ;
}
}
if ( V_154 != 0 ) {
F_180 ( V_154 , V_5 , V_2 , V_2 -> V_7 , V_26 ) ;
} else {
F_116 ( & V_2 -> V_103 , V_26 ) ;
}
}
}
static void F_37 ( struct V_4 * V_5 )
{
unsigned long V_26 ;
bool V_73 ;
struct V_1 * V_2 ;
struct V_1 * V_184 = NULL ;
V_2 = F_5 ( V_5 -> V_21 -> V_23 ) ;
for (; V_2 != NULL ; V_2 = V_2 -> V_157 ) {
V_73 = ( F_2 ( V_5 -> V_41 ) & V_134 ) ||
! F_213 ( & V_2 -> V_185 ) ;
if ( V_184 != NULL )
F_139 ( & V_184 -> V_185 ) ;
if ( V_73 ) {
V_5 -> V_186 ++ ;
return;
}
V_184 = V_2 ;
}
F_114 ( V_184 , V_26 ) ;
F_139 ( & V_184 -> V_185 ) ;
if ( F_2 ( V_5 -> V_41 ) & V_134 ) {
V_5 -> V_186 ++ ;
F_116 ( & V_184 -> V_103 , V_26 ) ;
return;
}
F_97 ( V_5 -> V_41 , F_2 ( V_5 -> V_41 ) | V_134 ) ;
F_116 ( & V_184 -> V_103 , V_26 ) ;
F_142 ( V_5 ) ;
}
static void
F_214 ( struct V_4 * V_5 )
{
unsigned long V_26 ;
bool V_124 ;
struct V_15 * V_16 = F_16 ( V_5 -> V_21 ) ;
F_61 ( V_16 -> V_187 == 0 ) ;
F_184 ( V_5 , V_16 ) ;
F_27 ( V_26 ) ;
if ( F_48 ( V_5 , V_16 ) ) {
F_137 ( F_46 ( V_5 ) ) ;
V_124 = F_178 ( V_5 ) ;
F_116 ( & F_46 ( V_5 ) -> V_103 , V_26 ) ;
if ( V_124 )
F_142 ( V_5 ) ;
} else {
F_28 ( V_26 ) ;
}
if ( F_45 ( V_16 ) )
F_215 ( V_5 , V_16 ) ;
F_58 ( V_16 ) ;
}
static void F_216 ( struct V_188 * V_189 )
{
struct V_4 * V_5 ;
if ( F_101 ( F_55 () ) )
return;
F_23 ( F_7 ( L_54 ) ) ;
F_15 (rsp)
F_214 ( V_5 ) ;
F_23 ( F_7 ( L_55 ) ) ;
}
static void F_215 ( struct V_4 * V_5 , struct V_15 * V_16 )
{
if ( F_25 ( ! F_2 ( V_75 ) ) )
return;
if ( F_217 ( ! V_5 -> V_190 ) ) {
F_196 ( V_5 , V_16 ) ;
return;
}
F_218 () ;
}
static void F_204 ( void )
{
if ( F_219 ( F_55 () ) )
F_220 ( V_191 ) ;
}
static void F_221 ( struct V_4 * V_5 , struct V_15 * V_16 ,
struct V_169 * V_192 , unsigned long V_26 )
{
bool V_124 ;
if ( ! F_85 () )
F_204 () ;
if ( F_222 ( V_26 ) || F_101 ( F_55 () ) )
return;
if ( F_25 ( V_16 -> V_108 > V_16 -> V_180 + V_182 ) ) {
F_148 ( V_5 , V_16 ) ;
if ( ! F_3 ( V_5 ) ) {
struct V_1 * V_117 = F_46 ( V_5 ) ;
F_137 ( V_117 ) ;
V_124 = F_178 ( V_5 ) ;
F_139 ( & V_117 -> V_103 ) ;
if ( V_124 )
F_142 ( V_5 ) ;
} else {
V_16 -> V_176 = V_178 ;
if ( V_5 -> V_94 == V_16 -> V_181 &&
* V_16 -> V_44 [ V_45 ] != V_192 )
F_37 ( V_5 ) ;
V_16 -> V_181 = V_5 -> V_94 ;
V_16 -> V_180 = V_16 -> V_108 ;
}
}
}
static void F_223 ( struct V_169 * V_193 )
{
}
static void
F_224 ( struct V_169 * V_192 , T_4 V_194 ,
struct V_4 * V_5 , int V_79 , bool V_195 )
{
unsigned long V_26 ;
struct V_15 * V_16 ;
F_61 ( ( unsigned long ) V_192 & 0x1 ) ;
if ( F_225 ( V_192 ) ) {
F_97 ( V_192 -> V_194 , F_223 ) ;
F_57 ( 1 , L_56 ) ;
return;
}
V_192 -> V_194 = V_194 ;
V_192 -> V_170 = NULL ;
F_27 ( V_26 ) ;
V_16 = F_10 ( V_5 -> V_21 ) ;
if ( F_25 ( V_16 -> V_44 [ V_51 ] == NULL ) || V_79 != - 1 ) {
int V_196 ;
if ( V_79 != - 1 )
V_16 = F_123 ( V_5 -> V_21 , V_79 ) ;
if ( F_217 ( V_16 -> V_23 ) ) {
V_196 = ! F_226 ( V_16 , V_192 , V_195 , V_26 ) ;
F_61 ( V_196 ) ;
F_28 ( V_26 ) ;
return;
}
F_227 ( V_79 != - 1 ) ;
F_61 ( ! F_85 () ) ;
if ( ! F_217 ( V_16 -> V_43 ) )
F_130 ( V_16 ) ;
}
F_97 ( V_16 -> V_108 , V_16 -> V_108 + 1 ) ;
if ( V_195 )
V_16 -> V_160 ++ ;
else
F_189 () ;
F_17 () ;
* V_16 -> V_44 [ V_51 ] = V_192 ;
V_16 -> V_44 [ V_51 ] = & V_192 -> V_170 ;
if ( F_228 ( ( unsigned long ) V_194 ) )
F_229 ( V_5 -> V_30 , V_192 , ( unsigned long ) V_194 ,
V_16 -> V_160 , V_16 -> V_108 ) ;
else
F_230 ( V_5 -> V_30 , V_192 , V_16 -> V_160 , V_16 -> V_108 ) ;
F_221 ( V_5 , V_16 , V_192 , V_26 ) ;
F_28 ( V_26 ) ;
}
void F_231 ( struct V_169 * V_192 , T_4 V_194 )
{
F_224 ( V_192 , V_194 , & V_13 , - 1 , 0 ) ;
}
void F_232 ( struct V_169 * V_192 , T_4 V_194 )
{
F_224 ( V_192 , V_194 , & V_29 , - 1 , 0 ) ;
}
void F_233 ( struct V_169 * V_192 ,
T_4 V_194 )
{
F_224 ( V_192 , V_194 , V_28 , - 1 , 1 ) ;
}
static inline int F_234 ( void )
{
int V_73 ;
F_235 () ;
F_90 () ;
V_73 = F_236 () <= 1 ;
F_91 () ;
return V_73 ;
}
void F_237 ( void )
{
F_64 ( F_65 ( & V_66 ) ||
F_65 ( & V_65 ) ||
F_65 ( & V_67 ) ,
L_57 ) ;
if ( F_234 () )
return;
if ( F_238 () )
F_239 () ;
else
F_240 ( F_231 ) ;
}
void F_241 ( void )
{
F_64 ( F_65 ( & V_66 ) ||
F_65 ( & V_65 ) ||
F_65 ( & V_67 ) ,
L_58 ) ;
if ( F_234 () )
return;
if ( F_238 () )
F_242 () ;
else
F_240 ( F_232 ) ;
}
unsigned long F_243 ( void )
{
F_17 () ;
return F_244 ( & V_28 -> V_7 ) ;
}
void F_245 ( unsigned long V_197 )
{
unsigned long V_198 ;
V_198 = F_244 ( & V_28 -> V_6 ) ;
if ( F_100 ( V_197 , V_198 ) )
F_246 () ;
}
unsigned long F_247 ( void )
{
F_17 () ;
return F_244 ( & V_13 . V_7 ) ;
}
void F_248 ( unsigned long V_197 )
{
unsigned long V_198 ;
V_198 = F_244 ( & V_13 . V_6 ) ;
if ( F_100 ( V_197 , V_198 ) )
F_237 () ;
}
static void F_249 ( unsigned long * V_199 )
{
F_97 ( * V_199 , * V_199 + 1 ) ;
F_17 () ;
F_61 ( ! ( * V_199 & 0x1 ) ) ;
}
static void F_250 ( unsigned long * V_199 )
{
F_17 () ;
F_97 ( * V_199 , * V_199 + 1 ) ;
F_61 ( * V_199 & 0x1 ) ;
}
static unsigned long F_251 ( unsigned long * V_199 )
{
unsigned long V_10 ;
V_10 = ( F_2 ( * V_199 ) + 3 ) & ~ 0x1 ;
F_17 () ;
return V_10 ;
}
static bool F_252 ( unsigned long * V_199 , unsigned long V_10 )
{
return F_100 ( F_2 ( * V_199 ) , V_10 ) ;
}
static void F_253 ( struct V_4 * V_5 )
{
F_249 ( & V_5 -> V_200 ) ;
}
static void F_254 ( struct V_4 * V_5 )
{
F_250 ( & V_5 -> V_200 ) ;
F_17 () ;
}
static unsigned long F_255 ( struct V_4 * V_5 )
{
F_17 () ;
return F_251 ( & V_5 -> V_200 ) ;
}
static bool F_256 ( struct V_4 * V_5 , unsigned long V_10 )
{
return F_252 ( & V_5 -> V_200 , V_10 ) ;
}
static void F_257 ( struct V_4 * V_5 )
{
bool V_201 ;
unsigned long V_26 ;
unsigned long V_154 ;
unsigned long V_128 ;
int V_202 = F_2 ( V_5 -> V_202 ) ;
struct V_1 * V_2 ;
struct V_1 * V_203 ;
if ( F_217 ( V_202 == V_5 -> V_204 ) )
return;
V_5 -> V_204 = V_202 ;
F_113 (rsp, rnp) {
F_114 ( V_2 , V_26 ) ;
if ( V_2 -> V_205 == V_2 -> V_206 ) {
F_116 ( & V_2 -> V_103 , V_26 ) ;
continue;
}
V_128 = V_2 -> V_205 ;
V_2 -> V_205 = V_2 -> V_206 ;
F_116 ( & V_2 -> V_103 , V_26 ) ;
if ( V_128 )
continue;
V_154 = V_2 -> V_74 ;
V_203 = V_2 -> V_157 ;
V_201 = false ;
while ( V_203 ) {
F_114 ( V_203 , V_26 ) ;
if ( V_203 -> V_205 )
V_201 = true ;
V_203 -> V_205 |= V_154 ;
F_116 ( & V_203 -> V_103 , V_26 ) ;
if ( V_201 )
break;
V_154 = V_203 -> V_74 ;
V_203 = V_203 -> V_157 ;
}
}
}
static void V_61 F_258 ( struct V_4 * V_5 )
{
unsigned long V_26 ;
struct V_1 * V_2 ;
F_257 ( V_5 ) ;
F_159 (rsp, rnp) {
F_114 ( V_2 , V_26 ) ;
F_61 ( V_2 -> V_207 ) ;
V_2 -> V_207 = V_2 -> V_205 ;
F_116 ( & V_2 -> V_103 , V_26 ) ;
}
}
static int F_259 ( struct V_1 * V_2 )
{
return V_2 -> V_208 == NULL &&
F_2 ( V_2 -> V_207 ) == 0 ;
}
static void F_260 ( struct V_4 * V_5 , struct V_1 * V_2 ,
bool V_209 , unsigned long V_26 )
__releases( V_2 -> V_103 )
{
unsigned long V_154 ;
for (; ; ) {
if ( ! F_259 ( V_2 ) ) {
if ( ! V_2 -> V_207 )
F_212 ( V_2 , V_26 ) ;
else
F_116 ( & V_2 -> V_103 , V_26 ) ;
break;
}
if ( V_2 -> V_157 == NULL ) {
F_116 ( & V_2 -> V_103 , V_26 ) ;
if ( V_209 ) {
F_17 () ;
F_143 ( & V_5 -> V_210 ) ;
}
break;
}
V_154 = V_2 -> V_74 ;
F_139 ( & V_2 -> V_103 ) ;
V_2 = V_2 -> V_157 ;
F_137 ( V_2 ) ;
F_61 ( ! ( V_2 -> V_207 & V_154 ) ) ;
V_2 -> V_207 &= ~ V_154 ;
}
}
static void V_61 F_261 ( struct V_4 * V_5 ,
struct V_1 * V_2 , bool V_209 )
{
unsigned long V_26 ;
F_114 ( V_2 , V_26 ) ;
F_260 ( V_5 , V_2 , V_209 , V_26 ) ;
}
static void F_262 ( struct V_4 * V_5 , struct V_1 * V_2 ,
unsigned long V_154 , bool V_209 )
{
unsigned long V_26 ;
F_114 ( V_2 , V_26 ) ;
if ( ! ( V_2 -> V_207 & V_154 ) ) {
F_116 ( & V_2 -> V_103 , V_26 ) ;
return;
}
V_2 -> V_207 &= ~ V_154 ;
F_260 ( V_5 , V_2 , V_209 , V_26 ) ;
}
static void F_9 ( struct V_4 * V_5 , struct V_15 * V_16 ,
bool V_209 )
{
F_262 ( V_5 , V_16 -> V_23 , V_16 -> V_74 , V_209 ) ;
}
static bool F_263 ( struct V_4 * V_5 , struct V_1 * V_2 ,
struct V_15 * V_16 ,
T_5 * V_211 , unsigned long V_10 )
{
if ( F_256 ( V_5 , V_10 ) ) {
if ( V_2 )
F_264 ( & V_2 -> V_212 ) ;
else if ( V_16 )
F_264 ( & V_16 -> V_212 ) ;
F_18 () ;
F_265 ( V_211 ) ;
return true ;
}
return false ;
}
static struct V_1 * F_266 ( struct V_4 * V_5 , unsigned long V_10 )
{
struct V_15 * V_16 = F_123 ( V_5 -> V_21 , F_267 () ) ;
struct V_1 * V_213 ;
struct V_1 * V_214 = NULL ;
V_213 = F_46 ( V_5 ) ;
if ( ! F_268 ( & V_213 -> V_212 ) ) {
if ( F_269 ( & V_213 -> V_212 ) ) {
if ( F_263 ( V_5 , V_213 , NULL ,
& V_16 -> V_215 , V_10 ) )
return NULL ;
return V_213 ;
}
}
if ( F_263 ( V_5 , NULL , NULL , & V_16 -> V_216 , V_10 ) )
return NULL ;
F_270 ( & V_16 -> V_212 ) ;
V_213 = V_16 -> V_23 ;
for (; V_213 != NULL ; V_213 = V_213 -> V_157 ) {
if ( F_263 ( V_5 , V_214 , V_16 ,
& V_16 -> V_217 , V_10 ) )
return NULL ;
F_270 ( & V_213 -> V_212 ) ;
if ( V_214 )
F_264 ( & V_214 -> V_212 ) ;
else
F_264 ( & V_16 -> V_212 ) ;
V_214 = V_213 ;
}
if ( F_263 ( V_5 , V_214 , V_16 ,
& V_16 -> V_218 , V_10 ) )
return NULL ;
return V_214 ;
}
static void F_271 ( void * V_219 )
{
struct V_15 * V_16 ;
struct V_1 * V_2 ;
struct V_4 * V_5 = V_219 ;
V_16 = F_10 ( V_5 -> V_21 ) ;
V_2 = V_16 -> V_23 ;
if ( ! ( F_2 ( V_2 -> V_207 ) & V_16 -> V_74 ) ||
F_5 ( V_8 . V_9 . V_11 . exp ) )
return;
F_8 ( V_8 . V_9 . V_11 . exp , true ) ;
F_103 ( F_55 () ) ;
}
static void F_272 ( int V_79 )
{
struct V_15 * V_16 ;
int V_73 ;
struct V_1 * V_2 ;
struct V_4 * V_5 = & V_13 ;
V_16 = F_123 ( V_5 -> V_21 , V_79 ) ;
V_2 = V_16 -> V_23 ;
if ( ! ( F_2 ( V_2 -> V_207 ) & V_16 -> V_74 ) )
return;
V_73 = F_273 ( V_79 , F_271 , V_5 , 0 ) ;
F_61 ( V_73 ) ;
}
static void F_274 ( struct V_4 * V_5 ,
T_6 V_194 )
{
int V_79 ;
unsigned long V_26 ;
unsigned long V_154 ;
unsigned long V_220 ;
unsigned long V_221 ;
int V_73 ;
struct V_1 * V_2 ;
F_258 ( V_5 ) ;
F_113 (rsp, rnp) {
F_114 ( V_2 , V_26 ) ;
V_220 = 0 ;
for ( V_79 = V_2 -> V_102 ; V_79 <= V_2 -> V_101 ; V_79 ++ ) {
struct V_15 * V_16 = F_123 ( V_5 -> V_21 , V_79 ) ;
struct V_17 * V_18 = & F_102 ( V_17 , V_79 ) ;
if ( F_267 () == V_79 ||
! ( F_94 ( 0 , & V_18 -> V_25 ) & 0x1 ) )
V_220 |= V_16 -> V_74 ;
}
V_221 = V_2 -> V_207 & ~ V_220 ;
if ( F_157 ( V_2 ) )
V_2 -> V_208 = V_2 -> V_222 . V_170 ;
F_116 ( & V_2 -> V_103 , V_26 ) ;
V_154 = 1 ;
for ( V_79 = V_2 -> V_102 ; V_79 <= V_2 -> V_101 ; V_79 ++ , V_154 <<= 1 ) {
if ( ! ( V_221 & V_154 ) )
continue;
V_223:
V_73 = F_273 ( V_79 , V_194 , V_5 , 0 ) ;
if ( ! V_73 ) {
V_221 &= ~ V_154 ;
continue;
}
F_114 ( V_2 , V_26 ) ;
if ( F_219 ( V_79 ) &&
( V_2 -> V_207 & V_154 ) ) {
F_116 ( & V_2 -> V_103 , V_26 ) ;
F_151 ( 1 ) ;
if ( F_219 ( V_79 ) &&
( V_2 -> V_207 & V_154 ) )
goto V_223;
F_114 ( V_2 , V_26 ) ;
}
if ( ! ( V_2 -> V_207 & V_154 ) )
V_221 &= ~ V_154 ;
F_116 ( & V_2 -> V_103 , V_26 ) ;
}
V_220 |= V_221 ;
if ( V_220 )
F_262 ( V_5 , V_2 , V_220 , false ) ;
}
}
static void F_275 ( struct V_4 * V_5 )
{
int V_79 ;
unsigned long V_92 ;
unsigned long V_224 ;
unsigned long V_154 ;
int V_105 ;
struct V_1 * V_2 ;
struct V_1 * V_117 = F_46 ( V_5 ) ;
int V_73 ;
V_92 = F_106 () ;
V_224 = V_87 ;
for (; ; ) {
V_73 = F_177 (
V_5 -> V_210 ,
F_259 ( V_117 ) ,
V_92 ) ;
if ( V_73 > 0 || F_259 ( V_117 ) )
return;
if ( V_73 < 0 ) {
F_276 ( V_5 -> V_210 ,
F_259 ( V_117 ) ) ;
return;
}
F_110 ( L_59 ,
V_5 -> V_30 ) ;
V_105 = 0 ;
F_113 (rsp, rnp) {
V_105 = F_277 ( V_2 ) ;
V_154 = 1 ;
for ( V_79 = V_2 -> V_102 ; V_79 <= V_2 -> V_101 ; V_79 ++ , V_154 <<= 1 ) {
struct V_15 * V_16 ;
if ( ! ( V_2 -> V_207 & V_154 ) )
continue;
V_105 ++ ;
V_16 = F_123 ( V_5 -> V_21 , V_79 ) ;
F_124 ( L_60 , V_79 ,
L_61 [ F_219 ( V_79 ) ] ,
L_62 [ ! ! ( V_16 -> V_74 & V_2 -> V_205 ) ] ,
L_63 [ ! ! ( V_16 -> V_74 & V_2 -> V_206 ) ] ) ;
}
V_154 <<= 1 ;
}
F_124 ( L_64 ,
V_87 - V_224 , V_5 -> V_200 ,
V_117 -> V_207 , L_65 [ ! ! V_117 -> V_208 ] ) ;
if ( ! V_105 ) {
F_110 ( L_66 ) ;
F_159 (rsp, rnp) {
if ( V_2 == V_117 )
continue;
if ( F_259 ( V_2 ) )
continue;
F_124 ( L_67 ,
V_2 -> V_115 , V_2 -> V_102 , V_2 -> V_101 ,
V_2 -> V_207 ,
L_65 [ ! ! V_2 -> V_208 ] ) ;
}
F_124 ( L_68 ) ;
}
F_113 (rsp, rnp) {
V_154 = 1 ;
for ( V_79 = V_2 -> V_102 ; V_79 <= V_2 -> V_101 ; V_79 ++ , V_154 <<= 1 ) {
if ( ! ( V_2 -> V_207 & V_154 ) )
continue;
F_115 ( V_79 ) ;
}
}
V_92 = 3 * F_106 () + 3 ;
}
}
void F_239 ( void )
{
unsigned long V_10 ;
struct V_1 * V_2 ;
struct V_4 * V_5 = & V_13 ;
if ( F_234 () )
return;
if ( F_278 () ) {
F_240 ( F_231 ) ;
return;
}
V_10 = F_255 ( V_5 ) ;
V_2 = F_266 ( V_5 , V_10 ) ;
if ( V_2 == NULL )
return;
F_253 ( V_5 ) ;
F_274 ( V_5 , F_271 ) ;
F_275 ( V_5 ) ;
F_254 ( V_5 ) ;
F_264 ( & V_2 -> V_212 ) ;
}
static int F_279 ( struct V_4 * V_5 , struct V_15 * V_16 )
{
struct V_1 * V_2 = V_16 -> V_23 ;
V_16 -> V_225 ++ ;
F_127 ( V_5 , V_16 ) ;
if ( F_280 ( V_5 ) )
return 0 ;
if ( V_75 &&
V_16 -> V_123 && V_16 -> V_9 . V_11 . V_12 &&
V_16 -> V_122 == F_5 ( V_27 ) ) {
V_16 -> V_226 ++ ;
} else if ( V_16 -> V_123 &&
( ! V_16 -> V_9 . V_11 . V_12 ||
V_16 -> V_122 != F_5 ( V_27 ) ) ) {
V_16 -> V_227 ++ ;
return 1 ;
}
if ( F_45 ( V_16 ) ) {
V_16 -> V_228 ++ ;
return 1 ;
}
if ( F_48 ( V_5 , V_16 ) ) {
V_16 -> V_229 ++ ;
return 1 ;
}
if ( F_2 ( V_2 -> V_6 ) != V_16 -> V_6 ) {
V_16 -> V_230 ++ ;
return 1 ;
}
if ( F_2 ( V_2 -> V_7 ) != V_16 -> V_7 ||
F_25 ( F_2 ( V_16 -> V_81 ) ) ) {
V_16 -> V_231 ++ ;
return 1 ;
}
if ( F_281 ( V_16 ) ) {
V_16 -> V_232 ++ ;
return 1 ;
}
V_16 -> V_233 ++ ;
return 0 ;
}
static int F_209 ( void )
{
struct V_4 * V_5 ;
F_15 (rsp)
if ( F_279 ( V_5 , F_10 ( V_5 -> V_21 ) ) )
return 1 ;
return 0 ;
}
static bool V_61 F_282 ( bool * V_234 )
{
bool V_235 = true ;
bool V_236 = false ;
struct V_15 * V_16 ;
struct V_4 * V_5 ;
F_15 (rsp) {
V_16 = F_10 ( V_5 -> V_21 ) ;
if ( ! V_16 -> V_43 )
continue;
V_236 = true ;
if ( V_16 -> V_108 != V_16 -> V_160 || ! V_234 ) {
V_235 = false ;
break;
}
}
if ( V_234 )
* V_234 = V_235 ;
return V_236 ;
}
static void F_283 ( struct V_4 * V_5 , const char * V_10 ,
int V_79 , unsigned long V_201 )
{
F_284 ( V_5 -> V_30 , V_10 , V_79 ,
F_62 ( & V_5 -> V_237 ) , V_201 ) ;
}
static void F_285 ( struct V_169 * V_193 )
{
struct V_15 * V_16 = F_286 ( V_193 , struct V_15 , V_238 ) ;
struct V_4 * V_5 = V_16 -> V_5 ;
if ( F_287 ( & V_5 -> V_237 ) ) {
F_283 ( V_5 , L_69 , - 1 , V_5 -> V_239 ) ;
F_288 ( & V_5 -> V_240 ) ;
} else {
F_283 ( V_5 , L_70 , - 1 , V_5 -> V_239 ) ;
}
}
static void F_289 ( void * type )
{
struct V_4 * V_5 = type ;
struct V_15 * V_16 = F_16 ( V_5 -> V_21 ) ;
F_283 ( V_5 , L_71 , - 1 , V_5 -> V_239 ) ;
F_60 ( & V_5 -> V_237 ) ;
V_5 -> V_241 ( & V_16 -> V_238 , F_285 ) ;
}
static void F_290 ( struct V_4 * V_5 )
{
int V_79 ;
struct V_15 * V_16 ;
unsigned long V_10 = F_251 ( & V_5 -> V_239 ) ;
F_283 ( V_5 , L_72 , - 1 , V_10 ) ;
F_270 ( & V_5 -> V_242 ) ;
if ( F_252 ( & V_5 -> V_239 , V_10 ) ) {
F_283 ( V_5 , L_73 , - 1 , V_5 -> V_239 ) ;
F_17 () ;
F_264 ( & V_5 -> V_242 ) ;
return;
}
F_249 ( & V_5 -> V_239 ) ;
F_283 ( V_5 , L_74 , - 1 , V_5 -> V_239 ) ;
F_291 ( & V_5 -> V_240 ) ;
F_292 ( & V_5 -> V_237 , 1 ) ;
F_293 () ;
F_122 (cpu) {
if ( ! F_219 ( V_79 ) && ! F_186 ( V_79 ) )
continue;
V_16 = F_123 ( V_5 -> V_21 , V_79 ) ;
if ( F_186 ( V_79 ) ) {
if ( ! F_294 ( V_5 , V_79 ) ) {
F_283 ( V_5 , L_75 , V_79 ,
V_5 -> V_239 ) ;
} else {
F_283 ( V_5 , L_76 , V_79 ,
V_5 -> V_239 ) ;
F_18 () ;
F_60 ( & V_5 -> V_237 ) ;
F_224 ( & V_16 -> V_238 ,
F_285 , V_5 , V_79 , 0 ) ;
}
} else if ( F_2 ( V_16 -> V_108 ) ) {
F_283 ( V_5 , L_77 , V_79 ,
V_5 -> V_239 ) ;
F_273 ( V_79 , F_289 , V_5 , 1 ) ;
} else {
F_283 ( V_5 , L_78 , V_79 ,
V_5 -> V_239 ) ;
}
}
F_295 () ;
if ( F_287 ( & V_5 -> V_237 ) )
F_288 ( & V_5 -> V_240 ) ;
F_296 ( & V_5 -> V_240 ) ;
F_283 ( V_5 , L_79 , - 1 , V_5 -> V_239 ) ;
F_250 ( & V_5 -> V_239 ) ;
F_264 ( & V_5 -> V_242 ) ;
}
void F_297 ( void )
{
F_290 ( & V_29 ) ;
}
void F_298 ( void )
{
F_290 ( & V_13 ) ;
}
static void F_156 ( struct V_1 * V_167 )
{
long V_154 ;
struct V_1 * V_2 = V_167 ;
for (; ; ) {
V_154 = V_2 -> V_74 ;
V_2 = V_2 -> V_157 ;
if ( V_2 == NULL )
return;
F_137 ( V_2 ) ;
V_2 -> V_130 |= V_154 ;
F_139 ( & V_2 -> V_103 ) ;
}
}
static void T_7
F_299 ( int V_79 , struct V_4 * V_5 )
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
F_300 ( & V_16 -> V_212 ) ;
F_301 ( V_16 ) ;
F_116 ( & V_2 -> V_103 , V_26 ) ;
}
static void
F_302 ( int V_79 , struct V_4 * V_5 )
{
unsigned long V_26 ;
unsigned long V_154 ;
struct V_15 * V_16 = F_123 ( V_5 -> V_21 , V_79 ) ;
struct V_1 * V_2 = F_46 ( V_5 ) ;
F_114 ( V_2 , V_26 ) ;
V_16 -> V_180 = 0 ;
V_16 -> V_181 = V_5 -> V_94 ;
V_16 -> V_176 = V_176 ;
if ( ! V_16 -> V_43 )
F_131 ( V_16 ) ;
V_16 -> V_25 -> V_57 = V_70 ;
F_303 ( V_16 -> V_25 ) ;
F_292 ( & V_16 -> V_25 -> V_25 ,
( F_62 ( & V_16 -> V_25 -> V_25 ) & ~ 0x1 ) + 1 ) ;
F_139 ( & V_2 -> V_103 ) ;
V_2 = V_16 -> V_23 ;
V_154 = V_16 -> V_74 ;
F_137 ( V_2 ) ;
V_2 -> V_3 |= V_154 ;
V_2 -> V_206 |= V_154 ;
if ( ! V_16 -> V_187 )
F_97 ( V_5 -> V_202 , F_2 ( V_5 -> V_202 ) + 1 ) ;
V_16 -> V_187 = true ;
V_16 -> V_7 = V_2 -> V_6 ;
V_16 -> V_6 = V_2 -> V_6 ;
V_16 -> V_9 . V_11 . V_12 = true ;
V_16 -> V_122 = F_102 ( V_27 , V_79 ) ;
V_16 -> V_123 = false ;
F_6 ( V_5 -> V_30 , V_16 -> V_7 , F_7 ( L_80 ) ) ;
F_116 ( & V_2 -> V_103 , V_26 ) ;
}
static void F_304 ( int V_79 )
{
struct V_4 * V_5 ;
F_15 (rsp)
F_302 ( V_79 , V_5 ) ;
}
int F_305 ( struct V_243 * V_244 ,
unsigned long V_245 , void * V_246 )
{
long V_79 = ( long ) V_246 ;
struct V_15 * V_16 = F_123 ( V_28 -> V_21 , V_79 ) ;
struct V_1 * V_2 = V_16 -> V_23 ;
struct V_4 * V_5 ;
switch ( V_245 ) {
case V_247 :
case V_248 :
F_304 ( V_79 ) ;
F_306 ( V_79 ) ;
F_307 ( V_79 ) ;
break;
case V_249 :
case V_250 :
F_272 ( V_79 ) ;
F_194 ( V_2 , - 1 ) ;
break;
case V_251 :
F_194 ( V_2 , V_79 ) ;
break;
case V_252 :
case V_253 :
F_15 (rsp)
F_190 ( V_5 ) ;
break;
case V_254 :
F_90 () ;
F_9 ( & V_13 ,
F_10 ( V_13 . V_21 ) , true ) ;
F_91 () ;
F_15 (rsp) {
F_192 ( V_79 , V_5 ) ;
}
break;
case V_255 :
case V_256 :
case V_257 :
case V_258 :
F_15 (rsp) {
F_193 ( V_79 , V_5 ) ;
F_58 ( F_123 ( V_5 -> V_21 , V_79 ) ) ;
}
break;
default:
break;
}
return V_259 ;
}
static int F_308 ( struct V_243 * V_244 ,
unsigned long V_245 , void * V_246 )
{
switch ( V_245 ) {
case V_260 :
case V_261 :
if ( V_262 <= 256 )
F_309 () ;
break;
case V_263 :
case V_264 :
if ( V_262 <= 256 )
F_310 () ;
break;
default:
break;
}
return V_259 ;
}
static int T_7 F_311 ( void )
{
unsigned long V_26 ;
int V_265 = V_266 ;
struct V_1 * V_2 ;
struct V_4 * V_5 ;
struct V_267 V_199 ;
struct V_60 * V_268 ;
if ( F_52 ( V_269 ) && V_266 < 1 )
V_266 = 1 ;
else if ( V_266 < 0 )
V_266 = 0 ;
else if ( V_266 > 99 )
V_266 = 99 ;
if ( V_266 != V_265 )
F_312 ( L_81 ,
V_266 , V_265 ) ;
V_75 = 1 ;
F_15 (rsp) {
V_268 = F_313 ( F_172 , V_5 , L_82 , V_5 -> V_30 ) ;
F_227 ( F_314 ( V_268 ) ) ;
V_2 = F_46 ( V_5 ) ;
F_114 ( V_2 , V_26 ) ;
V_5 -> V_32 = V_268 ;
if ( V_266 ) {
V_199 . V_270 = V_266 ;
F_315 ( V_268 , V_271 , & V_199 ) ;
}
F_116 ( & V_2 -> V_103 , V_26 ) ;
F_316 ( V_268 ) ;
}
F_317 () ;
F_318 () ;
return 0 ;
}
void F_319 ( void )
{
F_175 ( F_236 () != 1 ) ;
F_175 ( F_320 () > 0 ) ;
V_272 = 1 ;
}
static void T_7 F_321 ( int * V_273 , const int * V_274 )
{
int V_50 ;
if ( V_275 ) {
V_273 [ V_276 - 1 ] = V_277 ;
for ( V_50 = V_276 - 2 ; V_50 >= 0 ; V_50 -- )
V_273 [ V_50 ] = V_278 ;
} else {
int V_279 ;
int V_280 ;
V_280 = V_262 ;
for ( V_50 = V_276 - 1 ; V_50 >= 0 ; V_50 -- ) {
V_279 = V_274 [ V_50 ] ;
V_273 [ V_50 ] = ( V_280 + V_279 - 1 ) / V_279 ;
V_280 = V_279 ;
}
}
}
static void T_7 F_322 ( struct V_4 * V_5 )
{
static const char * const V_281 [] = V_282 ;
static const char * const V_283 [] = V_284 ;
static const char * const exp [] = V_285 ;
static struct V_286 V_287 [ V_288 ] ;
static struct V_286 V_289 [ V_288 ] ;
static struct V_286 V_290 [ V_288 ] ;
static T_8 V_291 = 0x1 ;
int V_274 [ V_288 ] ;
int V_273 [ V_288 ] ;
int V_292 = 1 ;
int V_50 ;
int V_91 ;
struct V_1 * V_2 ;
F_323 ( V_288 > F_108 ( V_281 ) ) ;
if ( V_276 <= 0 || V_276 > V_288 )
F_324 ( L_83 ) ;
for ( V_50 = 0 ; V_50 < V_276 ; V_50 ++ )
V_274 [ V_50 ] = V_293 [ V_50 ] ;
for ( V_50 = 1 ; V_50 < V_276 ; V_50 ++ )
V_5 -> V_115 [ V_50 ] = V_5 -> V_115 [ V_50 - 1 ] + V_274 [ V_50 - 1 ] ;
F_321 ( V_273 , V_274 ) ;
V_5 -> V_22 = V_291 ;
V_291 <<= 1 ;
for ( V_50 = V_276 - 1 ; V_50 >= 0 ; V_50 -- ) {
V_292 *= V_273 [ V_50 ] ;
V_2 = V_5 -> V_115 [ V_50 ] ;
for ( V_91 = 0 ; V_91 < V_274 [ V_50 ] ; V_91 ++ , V_2 ++ ) {
F_325 ( & V_2 -> V_103 ) ;
F_326 ( & V_2 -> V_103 ,
& V_287 [ V_50 ] , V_281 [ V_50 ] ) ;
F_325 ( & V_2 -> V_185 ) ;
F_326 ( & V_2 -> V_185 ,
& V_289 [ V_50 ] , V_283 [ V_50 ] ) ;
V_2 -> V_7 = V_5 -> V_7 ;
V_2 -> V_6 = V_5 -> V_6 ;
V_2 -> V_100 = 0 ;
V_2 -> V_130 = 0 ;
V_2 -> V_102 = V_91 * V_292 ;
V_2 -> V_101 = ( V_91 + 1 ) * V_292 - 1 ;
if ( V_2 -> V_101 >= V_262 )
V_2 -> V_101 = V_262 - 1 ;
if ( V_50 == 0 ) {
V_2 -> V_294 = 0 ;
V_2 -> V_74 = 0 ;
V_2 -> V_157 = NULL ;
} else {
V_2 -> V_294 = V_91 % V_273 [ V_50 - 1 ] ;
V_2 -> V_74 = 1UL << V_2 -> V_294 ;
V_2 -> V_157 = V_5 -> V_115 [ V_50 - 1 ] +
V_91 / V_273 [ V_50 - 1 ] ;
}
V_2 -> V_115 = V_50 ;
F_327 ( & V_2 -> V_222 ) ;
F_328 ( V_2 ) ;
F_300 ( & V_2 -> V_212 ) ;
F_326 ( & V_2 -> V_212 ,
& V_290 [ V_50 ] , exp [ V_50 ] ) ;
}
}
F_329 ( & V_5 -> V_121 ) ;
F_329 ( & V_5 -> V_210 ) ;
V_2 = V_5 -> V_115 [ V_276 - 1 ] ;
F_122 (i) {
while ( V_50 > V_2 -> V_101 )
V_2 ++ ;
F_123 ( V_5 -> V_21 , V_50 ) -> V_23 = V_2 ;
F_299 ( V_50 , V_5 ) ;
}
F_330 ( & V_5 -> V_295 , & V_296 ) ;
}
static void T_7 F_331 ( void )
{
T_9 V_297 ;
int V_50 ;
int V_298 [ V_288 ] ;
V_297 = V_299 + V_262 / V_300 ;
if ( V_148 == V_80 )
V_148 = V_297 ;
if ( V_109 == V_80 )
V_109 = V_297 ;
if ( V_277 == V_301 &&
V_262 == V_302 )
return;
F_41 ( L_84 ,
V_277 , V_262 ) ;
if ( V_277 < 2 ||
V_277 > sizeof( unsigned long ) * 8 ) {
V_277 = V_301 ;
F_175 ( 1 ) ;
return;
}
V_298 [ 0 ] = V_277 ;
for ( V_50 = 1 ; V_50 < V_288 ; V_50 ++ )
V_298 [ V_50 ] = V_298 [ V_50 - 1 ] * V_278 ;
if ( V_262 > V_298 [ V_288 - 1 ] ) {
V_277 = V_301 ;
F_175 ( 1 ) ;
return;
}
for ( V_50 = 0 ; V_262 > V_298 [ V_50 ] ; V_50 ++ ) {
}
V_276 = V_50 + 1 ;
for ( V_50 = 0 ; V_50 < V_276 ; V_50 ++ ) {
int V_303 = V_298 [ ( V_276 - 1 ) - V_50 ] ;
V_293 [ V_50 ] = F_332 ( V_262 , V_303 ) ;
}
V_126 = 0 ;
for ( V_50 = 0 ; V_50 < V_276 ; V_50 ++ )
V_126 += V_293 [ V_50 ] ;
}
static void T_7 F_333 ( struct V_4 * V_5 )
{
int V_115 = 0 ;
struct V_1 * V_2 ;
F_41 ( L_85 ) ;
F_41 ( L_86 ) ;
F_159 (rsp, rnp) {
if ( V_2 -> V_115 != V_115 ) {
F_124 ( L_68 ) ;
F_41 ( L_86 ) ;
V_115 = V_2 -> V_115 ;
}
F_124 ( L_87 , V_2 -> V_102 , V_2 -> V_101 , V_2 -> V_294 ) ;
}
F_124 ( L_68 ) ;
}
void T_7 F_334 ( void )
{
int V_79 ;
F_335 () ;
F_336 () ;
F_331 () ;
F_322 ( & V_29 ) ;
F_322 ( & V_13 ) ;
if ( V_304 )
F_333 ( & V_13 ) ;
F_337 () ;
F_338 ( V_191 , F_216 ) ;
F_339 ( F_305 , 0 ) ;
F_340 ( F_308 , 0 ) ;
F_341 (cpu)
F_305 ( NULL , V_247 , ( void * ) ( long ) V_79 ) ;
}
