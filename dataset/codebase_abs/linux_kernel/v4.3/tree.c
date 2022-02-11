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
if ( ! F_5 ( V_8 . V_9 ) ) {
F_6 ( F_7 ( L_1 ) ,
F_5 ( V_8 . V_7 ) ,
F_7 ( L_2 ) ) ;
F_8 ( V_8 . V_9 , 1 ) ;
}
}
void F_9 ( void )
{
if ( ! F_5 ( V_10 . V_9 ) ) {
F_6 ( F_7 ( L_3 ) ,
F_5 ( V_10 . V_7 ) ,
F_7 ( L_2 ) ) ;
F_8 ( V_10 . V_9 , 1 ) ;
}
}
static void F_10 ( void )
{
unsigned long V_11 ;
struct V_12 * V_13 ;
struct V_14 * V_15 ;
int V_16 ;
struct V_4 * V_5 ;
F_11 ( V_11 ) ;
V_16 = F_12 ( V_17 ) ;
F_13 ( V_17 , 0 ) ;
F_14 (rsp) {
V_13 = F_15 ( V_5 -> V_18 ) ;
if ( ! ( V_16 & V_5 -> V_19 ) )
continue;
F_16 () ;
if ( F_2 ( V_13 -> V_20 -> V_6 ) !=
F_2 ( V_13 -> V_21 ) )
continue;
V_15 = F_17 ( & V_14 ) ;
F_18 () ;
F_19 ( 2 , & V_15 -> V_22 ) ;
F_20 () ;
break;
}
F_21 ( V_11 ) ;
}
void F_22 ( void )
{
F_23 ( F_7 ( L_4 ) ) ;
F_4 () ;
F_24 () ;
if ( F_25 ( F_12 ( V_17 ) ) )
F_10 () ;
F_23 ( F_7 ( L_5 ) ) ;
}
void F_26 ( void )
{
if ( F_25 ( F_12 ( V_17 ) ) )
F_10 () ;
F_27 ( V_23 ) ;
}
unsigned long F_28 ( void )
{
return V_24 -> V_7 ;
}
unsigned long F_29 ( void )
{
return V_25 . V_7 ;
}
unsigned long F_30 ( void )
{
return V_26 . V_7 ;
}
unsigned long F_31 ( void )
{
return V_24 -> V_6 ;
}
unsigned long F_32 ( void )
{
return V_25 . V_6 ;
}
unsigned long F_33 ( void )
{
return V_26 . V_6 ;
}
void F_34 ( void )
{
F_35 ( V_24 ) ;
}
void F_36 ( void )
{
F_35 ( & V_26 ) ;
}
void F_37 ( void )
{
F_35 ( & V_25 ) ;
}
void F_38 ( void )
{
struct V_4 * V_5 ;
F_14 (rsp) {
F_39 ( L_6 ,
V_5 -> V_27 , V_5 -> V_28 , V_5 -> V_29 -> V_30 ) ;
}
}
void F_40 ( void )
{
V_31 ++ ;
V_32 = 0 ;
}
void F_41 ( enum V_33 V_34 , int * V_11 ,
unsigned long * V_7 , unsigned long * V_6 )
{
struct V_4 * V_5 = NULL ;
switch ( V_34 ) {
case V_35 :
V_5 = V_24 ;
break;
case V_36 :
V_5 = & V_26 ;
break;
case V_37 :
V_5 = & V_25 ;
break;
default:
break;
}
if ( V_5 != NULL ) {
* V_11 = F_2 ( V_5 -> V_38 ) ;
* V_7 = F_2 ( V_5 -> V_7 ) ;
* V_6 = F_2 ( V_5 -> V_6 ) ;
return;
}
* V_11 = 0 ;
* V_7 = 0 ;
* V_6 = 0 ;
}
void F_42 ( unsigned long V_39 )
{
V_32 ++ ;
}
static int
F_43 ( struct V_12 * V_13 )
{
return & V_13 -> V_40 != V_13 -> V_41 [ V_42 ] &&
V_13 -> V_41 [ V_42 ] != NULL ;
}
static struct V_1 * F_44 ( struct V_4 * V_5 )
{
return & V_5 -> V_43 [ 0 ] ;
}
static int F_45 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = F_44 ( V_5 ) ;
int V_44 = ( F_2 ( V_2 -> V_6 ) + 1 ) & 0x1 ;
int * V_45 = & V_2 -> V_46 [ V_44 ] ;
return F_2 ( * V_45 ) ;
}
static int
F_46 ( struct V_4 * V_5 , struct V_12 * V_13 )
{
int V_47 ;
if ( F_3 ( V_5 ) )
return 0 ;
if ( F_45 ( V_5 ) )
return 1 ;
if ( ! V_13 -> V_41 [ V_48 ] )
return 0 ;
if ( * V_13 -> V_41 [ V_49 ] )
return 1 ;
for ( V_47 = V_50 ; V_47 < V_48 ; V_47 ++ )
if ( V_13 -> V_41 [ V_47 - 1 ] != V_13 -> V_41 [ V_47 ] &&
F_47 ( F_2 ( V_5 -> V_6 ) ,
V_13 -> V_51 [ V_47 ] ) )
return 1 ;
return 0 ;
}
static void F_48 ( long long V_52 , bool V_53 )
{
struct V_4 * V_5 ;
struct V_12 * V_13 ;
struct V_14 * V_15 = F_17 ( & V_14 ) ;
F_49 ( F_7 ( L_7 ) , V_52 , V_15 -> V_54 ) ;
if ( F_50 ( V_55 ) &&
! V_53 && ! F_51 ( V_56 ) ) {
struct V_57 * T_1 V_58 =
F_52 ( F_53 () ) ;
F_49 ( F_7 ( L_8 ) , V_52 , 0 ) ;
F_54 ( V_59 ) ;
F_55 ( 1 , L_9 ,
V_56 -> V_60 , V_56 -> V_61 ,
T_1 -> V_60 , T_1 -> V_61 ) ;
}
F_14 (rsp) {
V_13 = F_17 ( V_5 -> V_18 ) ;
F_56 ( V_13 ) ;
}
F_57 () ;
F_18 () ;
F_58 ( & V_15 -> V_22 ) ;
F_20 () ;
F_59 ( F_50 ( V_55 ) &&
F_60 ( & V_15 -> V_22 ) & 0x1 ) ;
F_61 () ;
F_62 ( F_63 ( & V_62 ) ,
L_10 ) ;
F_62 ( F_63 ( & V_63 ) ,
L_11 ) ;
F_62 ( F_63 ( & V_64 ) ,
L_12 ) ;
}
static void F_64 ( bool V_53 )
{
long long V_52 ;
struct V_14 * V_15 ;
V_15 = F_17 ( & V_14 ) ;
V_52 = V_15 -> V_54 ;
F_59 ( F_50 ( V_55 ) &&
( V_52 & V_65 ) == 0 ) ;
if ( ( V_52 & V_65 ) == V_66 ) {
V_15 -> V_54 = 0 ;
F_48 ( V_52 , V_53 ) ;
} else {
V_15 -> V_54 -= V_66 ;
}
}
void F_65 ( void )
{
unsigned long V_11 ;
F_11 ( V_11 ) ;
F_64 ( false ) ;
F_66 ( 0 ) ;
F_21 ( V_11 ) ;
}
void F_67 ( void )
{
F_64 ( 1 ) ;
}
void F_68 ( void )
{
unsigned long V_11 ;
long long V_52 ;
struct V_14 * V_15 ;
F_11 ( V_11 ) ;
V_15 = F_17 ( & V_14 ) ;
V_52 = V_15 -> V_54 ;
V_15 -> V_54 -- ;
F_59 ( F_50 ( V_55 ) &&
V_15 -> V_54 < 0 ) ;
if ( V_15 -> V_54 )
F_49 ( F_7 ( L_13 ) , V_52 , V_15 -> V_54 ) ;
else
F_48 ( V_52 , true ) ;
F_66 ( 1 ) ;
F_21 ( V_11 ) ;
}
static void F_69 ( long long V_52 , int V_53 )
{
struct V_14 * V_15 = F_17 ( & V_14 ) ;
F_70 () ;
F_18 () ;
F_58 ( & V_15 -> V_22 ) ;
F_20 () ;
F_59 ( F_50 ( V_55 ) &&
! ( F_60 ( & V_15 -> V_22 ) & 0x1 ) ) ;
F_71 () ;
F_49 ( F_7 ( L_14 ) , V_52 , V_15 -> V_54 ) ;
if ( F_50 ( V_55 ) &&
! V_53 && ! F_51 ( V_56 ) ) {
struct V_57 * T_1 V_58 =
F_52 ( F_53 () ) ;
F_49 ( F_7 ( L_15 ) ,
V_52 , V_15 -> V_54 ) ;
F_54 ( V_59 ) ;
F_55 ( 1 , L_9 ,
V_56 -> V_60 , V_56 -> V_61 ,
T_1 -> V_60 , T_1 -> V_61 ) ;
}
}
static void F_72 ( bool V_53 )
{
struct V_14 * V_15 ;
long long V_52 ;
V_15 = F_17 ( & V_14 ) ;
V_52 = V_15 -> V_54 ;
F_59 ( F_50 ( V_55 ) && V_52 < 0 ) ;
if ( V_52 & V_65 ) {
V_15 -> V_54 += V_66 ;
} else {
V_15 -> V_54 = V_67 ;
F_69 ( V_52 , V_53 ) ;
}
}
void F_73 ( void )
{
unsigned long V_11 ;
F_11 ( V_11 ) ;
F_72 ( false ) ;
F_74 ( 0 ) ;
F_21 ( V_11 ) ;
}
void F_75 ( void )
{
F_72 ( 1 ) ;
}
void F_76 ( void )
{
unsigned long V_11 ;
struct V_14 * V_15 ;
long long V_52 ;
F_11 ( V_11 ) ;
V_15 = F_17 ( & V_14 ) ;
V_52 = V_15 -> V_54 ;
V_15 -> V_54 ++ ;
F_59 ( F_50 ( V_55 ) &&
V_15 -> V_54 == 0 ) ;
if ( V_52 )
F_49 ( F_7 ( L_16 ) , V_52 , V_15 -> V_54 ) ;
else
F_69 ( V_52 , true ) ;
F_74 ( 1 ) ;
F_21 ( V_11 ) ;
}
void F_77 ( void )
{
struct V_14 * V_15 = F_17 ( & V_14 ) ;
int V_68 = 2 ;
F_59 ( V_15 -> V_69 < 0 ) ;
if ( ! ( F_60 ( & V_15 -> V_22 ) & 0x1 ) ) {
F_18 () ;
F_58 ( & V_15 -> V_22 ) ;
F_20 () ;
F_59 ( ! ( F_60 ( & V_15 -> V_22 ) & 0x1 ) ) ;
V_68 = 1 ;
}
V_15 -> V_69 += V_68 ;
F_78 () ;
}
void F_79 ( void )
{
struct V_14 * V_15 = F_17 ( & V_14 ) ;
F_59 ( V_15 -> V_69 <= 0 ) ;
F_59 ( ! ( F_60 ( & V_15 -> V_22 ) & 0x1 ) ) ;
if ( V_15 -> V_69 != 1 ) {
V_15 -> V_69 -= 2 ;
return;
}
V_15 -> V_69 = 0 ;
F_18 () ;
F_58 ( & V_15 -> V_22 ) ;
F_20 () ;
F_59 ( F_60 ( & V_15 -> V_22 ) & 0x1 ) ;
}
bool T_2 F_80 ( void )
{
return F_60 ( F_17 ( & V_14 . V_22 ) ) & 0x1 ;
}
bool T_2 F_81 ( void )
{
bool V_70 ;
F_82 () ;
V_70 = F_80 () ;
F_83 () ;
return V_70 ;
}
bool F_84 ( void )
{
struct V_12 * V_13 ;
struct V_1 * V_2 ;
bool V_70 ;
if ( F_85 () )
return true ;
F_86 () ;
V_13 = F_17 ( & V_8 ) ;
V_2 = V_13 -> V_20 ;
V_70 = ( V_13 -> V_71 & F_1 ( V_2 ) ) ||
! V_72 ;
F_87 () ;
return V_70 ;
}
static int F_88 ( void )
{
return F_5 ( V_14 . V_54 ) <= 1 ;
}
static int F_89 ( struct V_12 * V_13 ,
bool * V_73 , unsigned long * V_74 )
{
V_13 -> V_75 = F_90 ( 0 , & V_13 -> V_22 -> V_22 ) ;
F_91 ( V_13 , V_73 , V_74 ) ;
if ( ( V_13 -> V_75 & 0x1 ) == 0 ) {
F_92 ( V_13 -> V_5 -> V_27 , V_13 -> V_7 , V_13 -> V_76 , F_7 ( L_17 ) ) ;
return 1 ;
} else {
if ( F_47 ( F_2 ( V_13 -> V_7 ) + V_77 / 4 ,
V_13 -> V_20 -> V_7 ) )
F_93 ( V_13 -> V_78 , true ) ;
return 0 ;
}
}
static int F_94 ( struct V_12 * V_13 ,
bool * V_73 , unsigned long * V_74 )
{
unsigned int V_79 ;
int * V_80 ;
unsigned int V_81 ;
V_79 = ( unsigned int ) F_90 ( 0 , & V_13 -> V_22 -> V_22 ) ;
V_81 = ( unsigned int ) V_13 -> V_75 ;
if ( ( V_79 & 0x1 ) == 0 || F_95 ( V_79 , V_81 + 2 ) ) {
F_92 ( V_13 -> V_5 -> V_27 , V_13 -> V_7 , V_13 -> V_76 , F_7 ( L_17 ) ) ;
V_13 -> V_82 ++ ;
return 1 ;
}
if ( F_96 ( V_13 -> V_5 -> V_83 + 2 , V_84 ) )
return 0 ;
F_78 () ;
if ( F_97 ( V_13 -> V_76 ) ) {
F_92 ( V_13 -> V_5 -> V_27 , V_13 -> V_7 , V_13 -> V_76 , F_7 ( L_18 ) ) ;
V_13 -> V_85 ++ ;
return 1 ;
}
V_80 = & F_98 ( V_17 , V_13 -> V_76 ) ;
if ( F_96 ( V_84 ,
V_13 -> V_5 -> V_83 + V_86 ) ||
F_96 ( V_84 , V_13 -> V_5 -> V_87 ) ) {
if ( ! ( F_2 ( * V_80 ) & V_13 -> V_5 -> V_19 ) ) {
F_93 ( V_13 -> V_21 ,
F_2 ( V_13 -> V_20 -> V_6 ) ) ;
F_16 () ;
F_93 ( * V_80 ,
F_2 ( * V_80 ) + V_13 -> V_5 -> V_19 ) ;
F_99 ( V_13 -> V_76 ) ;
V_13 -> V_5 -> V_87 += 5 ;
} else if ( F_96 ( V_84 , V_13 -> V_5 -> V_87 ) ) {
F_99 ( V_13 -> V_76 ) ;
V_13 -> V_5 -> V_87 += 5 ;
}
}
return 0 ;
}
static void F_100 ( struct V_4 * V_5 )
{
unsigned long V_88 = V_84 ;
unsigned long j1 ;
V_5 -> V_83 = V_88 ;
F_101 () ;
j1 = F_102 () ;
F_93 ( V_5 -> V_89 , V_88 + j1 ) ;
V_5 -> V_87 = V_88 + j1 / 2 ;
V_5 -> V_90 = F_2 ( V_5 -> V_91 ) ;
}
static void F_103 ( struct V_4 * V_5 )
{
unsigned long V_92 ;
unsigned long V_88 ;
V_88 = V_84 ;
V_92 = F_2 ( V_5 -> V_93 ) ;
if ( V_88 - V_92 > 2 * V_94 )
F_104 ( L_19 ,
V_5 -> V_27 , V_88 - V_92 ,
V_5 -> V_7 , V_5 -> V_6 ,
V_5 -> V_38 , V_5 -> V_28 ,
V_5 -> V_29 ? V_5 -> V_29 -> V_30 : 0 ) ;
}
static void F_105 ( struct V_4 * V_5 )
{
int V_76 ;
unsigned long V_11 ;
struct V_1 * V_2 ;
F_106 (rsp, rnp) {
F_107 ( & V_2 -> V_95 , V_11 ) ;
if ( V_2 -> V_96 != 0 ) {
for ( V_76 = 0 ; V_76 <= V_2 -> V_97 - V_2 -> V_98 ; V_76 ++ )
if ( V_2 -> V_96 & ( 1UL << V_76 ) )
F_108 ( V_2 -> V_98 + V_76 ) ;
}
F_109 ( & V_2 -> V_95 , V_11 ) ;
}
}
static void F_110 ( struct V_4 * V_5 , unsigned long V_7 )
{
int V_76 ;
long V_99 ;
unsigned long V_11 ;
unsigned long V_92 ;
unsigned long V_88 ;
int V_100 = 0 ;
struct V_1 * V_2 = F_44 ( V_5 ) ;
long V_101 = 0 ;
F_107 ( & V_2 -> V_95 , V_11 ) ;
V_99 = V_84 - F_2 ( V_5 -> V_89 ) ;
if ( V_99 < V_102 || ! F_3 ( V_5 ) ) {
F_109 ( & V_2 -> V_95 , V_11 ) ;
return;
}
F_93 ( V_5 -> V_89 ,
V_84 + 3 * F_102 () + 3 ) ;
F_109 ( & V_2 -> V_95 , V_11 ) ;
F_104 ( L_20 ,
V_5 -> V_27 ) ;
F_111 () ;
F_106 (rsp, rnp) {
F_107 ( & V_2 -> V_95 , V_11 ) ;
V_100 += F_112 ( V_2 ) ;
if ( V_2 -> V_96 != 0 ) {
for ( V_76 = 0 ; V_76 <= V_2 -> V_97 - V_2 -> V_98 ; V_76 ++ )
if ( V_2 -> V_96 & ( 1UL << V_76 ) ) {
F_113 ( V_5 ,
V_2 -> V_98 + V_76 ) ;
V_100 ++ ;
}
}
F_109 ( & V_2 -> V_95 , V_11 ) ;
}
F_114 () ;
F_115 (cpu)
V_101 += F_116 ( V_5 -> V_18 , V_76 ) -> V_103 ;
F_117 ( L_21 ,
F_53 () , ( long ) ( V_84 - V_5 -> V_83 ) ,
( long ) V_5 -> V_7 , ( long ) V_5 -> V_6 , V_101 ) ;
if ( V_100 ) {
F_105 ( V_5 ) ;
} else {
if ( F_2 ( V_5 -> V_7 ) != V_7 ||
F_2 ( V_5 -> V_6 ) == V_7 ) {
F_104 ( L_22 ) ;
} else {
V_88 = V_84 ;
V_92 = F_2 ( V_5 -> V_93 ) ;
F_104 ( L_23 ,
V_5 -> V_27 , V_88 - V_92 , V_88 , V_92 ,
V_104 ,
F_44 ( V_5 ) -> V_96 ) ;
F_118 ( V_56 ) ;
}
}
F_119 ( V_5 ) ;
F_103 ( V_5 ) ;
F_35 ( V_5 ) ;
}
static void F_120 ( struct V_4 * V_5 )
{
int V_76 ;
unsigned long V_11 ;
struct V_1 * V_2 = F_44 ( V_5 ) ;
long V_101 = 0 ;
F_104 ( L_24 , V_5 -> V_27 ) ;
F_111 () ;
F_113 ( V_5 , F_53 () ) ;
F_114 () ;
F_115 (cpu)
V_101 += F_116 ( V_5 -> V_18 , V_76 ) -> V_103 ;
F_117 ( L_25 ,
V_84 - V_5 -> V_83 ,
( long ) V_5 -> V_7 , ( long ) V_5 -> V_6 , V_101 ) ;
F_103 ( V_5 ) ;
F_105 ( V_5 ) ;
F_107 ( & V_2 -> V_95 , V_11 ) ;
if ( F_96 ( V_84 , F_2 ( V_5 -> V_89 ) ) )
F_93 ( V_5 -> V_89 ,
V_84 + 3 * F_102 () + 3 ) ;
F_109 ( & V_2 -> V_95 , V_11 ) ;
F_99 ( F_53 () ) ;
}
static void F_121 ( struct V_4 * V_5 , struct V_12 * V_13 )
{
unsigned long V_6 ;
unsigned long V_7 ;
unsigned long V_105 ;
unsigned long V_88 ;
unsigned long V_106 ;
struct V_1 * V_2 ;
if ( V_107 || ! F_3 ( V_5 ) )
return;
V_88 = V_84 ;
V_7 = F_2 ( V_5 -> V_7 ) ;
F_122 () ;
V_106 = F_2 ( V_5 -> V_89 ) ;
F_122 () ;
V_105 = F_2 ( V_5 -> V_83 ) ;
F_122 () ;
V_6 = F_2 ( V_5 -> V_6 ) ;
if ( F_96 ( V_6 , V_7 ) ||
F_47 ( V_88 , V_106 ) ||
F_96 ( V_105 , V_106 ) )
return;
V_2 = V_13 -> V_20 ;
if ( F_3 ( V_5 ) &&
( F_2 ( V_2 -> V_96 ) & V_13 -> V_71 ) ) {
F_120 ( V_5 ) ;
} else if ( F_3 ( V_5 ) &&
F_96 ( V_88 , V_106 + V_102 ) ) {
F_110 ( V_5 , V_7 ) ;
}
}
void F_123 ( void )
{
struct V_4 * V_5 ;
F_14 (rsp)
F_93 ( V_5 -> V_89 , V_84 + V_77 / 2 ) ;
}
static void F_124 ( struct V_12 * V_13 )
{
int V_47 ;
V_13 -> V_40 = NULL ;
for ( V_47 = 0 ; V_47 < V_108 ; V_47 ++ )
V_13 -> V_41 [ V_47 ] = & V_13 -> V_40 ;
}
static void F_125 ( struct V_12 * V_13 )
{
if ( F_126 ( V_13 ) )
return;
F_124 ( V_13 ) ;
}
static unsigned long F_127 ( struct V_4 * V_5 ,
struct V_1 * V_2 )
{
if ( F_44 ( V_5 ) == V_2 && V_2 -> V_7 == V_2 -> V_6 )
return V_2 -> V_6 + 1 ;
return V_2 -> V_6 + 2 ;
}
static void F_128 ( struct V_1 * V_2 , struct V_12 * V_13 ,
unsigned long V_109 , const char * V_110 )
{
F_129 ( V_13 -> V_5 -> V_27 , V_2 -> V_7 ,
V_2 -> V_6 , V_109 , V_2 -> V_111 ,
V_2 -> V_98 , V_2 -> V_97 , V_110 ) ;
}
static bool V_58
F_130 ( struct V_1 * V_2 , struct V_12 * V_13 ,
unsigned long * V_112 )
{
unsigned long V_109 ;
int V_47 ;
bool V_70 = false ;
struct V_1 * V_113 = F_44 ( V_13 -> V_5 ) ;
V_109 = F_127 ( V_13 -> V_5 , V_2 ) ;
F_128 ( V_2 , V_13 , V_109 , F_7 ( L_26 ) ) ;
if ( V_2 -> V_46 [ V_109 & 0x1 ] ) {
F_128 ( V_2 , V_13 , V_109 , F_7 ( L_27 ) ) ;
goto V_114;
}
if ( V_2 -> V_7 != V_2 -> V_6 ||
F_2 ( V_113 -> V_7 ) != F_2 ( V_113 -> V_6 ) ) {
V_2 -> V_46 [ V_109 & 0x1 ] ++ ;
F_128 ( V_2 , V_13 , V_109 , F_7 ( L_28 ) ) ;
goto V_114;
}
if ( V_2 != V_113 ) {
F_131 ( & V_113 -> V_95 ) ;
F_132 () ;
}
V_109 = F_127 ( V_13 -> V_5 , V_113 ) ;
for ( V_47 = V_42 ; V_47 < V_48 ; V_47 ++ )
if ( F_47 ( V_109 , V_13 -> V_51 [ V_47 ] ) )
V_13 -> V_51 [ V_47 ] = V_109 ;
if ( V_113 -> V_46 [ V_109 & 0x1 ] ) {
F_128 ( V_2 , V_13 , V_109 , F_7 ( L_29 ) ) ;
goto V_115;
}
V_113 -> V_46 [ V_109 & 0x1 ] ++ ;
if ( V_113 -> V_7 != V_113 -> V_6 ) {
F_128 ( V_2 , V_13 , V_109 , F_7 ( L_30 ) ) ;
} else {
F_128 ( V_2 , V_13 , V_109 , F_7 ( L_31 ) ) ;
V_70 = F_133 ( V_13 -> V_5 , V_113 , V_13 ) ;
}
V_115:
if ( V_2 != V_113 )
F_134 ( & V_113 -> V_95 ) ;
V_114:
if ( V_112 != NULL )
* V_112 = V_109 ;
return V_70 ;
}
static int F_135 ( struct V_4 * V_5 , struct V_1 * V_2 )
{
int V_109 = V_2 -> V_6 ;
int V_116 ;
struct V_12 * V_13 = F_17 ( V_5 -> V_18 ) ;
F_136 ( V_5 , V_2 ) ;
V_2 -> V_46 [ V_109 & 0x1 ] = 0 ;
V_116 = V_2 -> V_46 [ ( V_109 + 1 ) & 0x1 ] ;
F_128 ( V_2 , V_13 , V_109 ,
V_116 ? F_7 ( L_32 ) : F_7 ( L_33 ) ) ;
return V_116 ;
}
static void F_137 ( struct V_4 * V_5 )
{
if ( V_56 == V_5 -> V_29 ||
! F_2 ( V_5 -> V_38 ) ||
! V_5 -> V_29 )
return;
F_138 ( & V_5 -> V_117 ) ;
}
static bool F_139 ( struct V_4 * V_5 , struct V_1 * V_2 ,
struct V_12 * V_13 )
{
unsigned long V_109 ;
int V_47 ;
bool V_70 ;
if ( ! V_13 -> V_41 [ V_48 ] || ! * V_13 -> V_41 [ V_42 ] )
return false ;
V_109 = F_127 ( V_5 , V_2 ) ;
for ( V_47 = V_48 - 1 ; V_47 > V_42 ; V_47 -- )
if ( V_13 -> V_41 [ V_47 ] != V_13 -> V_41 [ V_47 - 1 ] &&
! F_96 ( V_13 -> V_51 [ V_47 ] , V_109 ) )
break;
if ( ++ V_47 >= V_48 )
return false ;
for (; V_47 <= V_48 ; V_47 ++ ) {
V_13 -> V_41 [ V_47 ] = V_13 -> V_41 [ V_48 ] ;
V_13 -> V_51 [ V_47 ] = V_109 ;
}
V_70 = F_130 ( V_2 , V_13 , NULL ) ;
if ( ! * V_13 -> V_41 [ V_50 ] )
F_6 ( V_5 -> V_27 , V_13 -> V_7 , F_7 ( L_34 ) ) ;
else
F_6 ( V_5 -> V_27 , V_13 -> V_7 , F_7 ( L_35 ) ) ;
return V_70 ;
}
static bool F_140 ( struct V_4 * V_5 , struct V_1 * V_2 ,
struct V_12 * V_13 )
{
int V_47 , V_88 ;
if ( ! V_13 -> V_41 [ V_48 ] || ! * V_13 -> V_41 [ V_42 ] )
return false ;
for ( V_47 = V_50 ; V_47 < V_48 ; V_47 ++ ) {
if ( F_47 ( V_2 -> V_6 , V_13 -> V_51 [ V_47 ] ) )
break;
V_13 -> V_41 [ V_42 ] = V_13 -> V_41 [ V_47 ] ;
}
for ( V_88 = V_50 ; V_88 < V_47 ; V_88 ++ )
V_13 -> V_41 [ V_88 ] = V_13 -> V_41 [ V_42 ] ;
for ( V_88 = V_50 ; V_47 < V_48 ; V_47 ++ , V_88 ++ ) {
if ( V_13 -> V_41 [ V_88 ] == V_13 -> V_41 [ V_48 ] )
break;
V_13 -> V_41 [ V_88 ] = V_13 -> V_41 [ V_47 ] ;
V_13 -> V_51 [ V_88 ] = V_13 -> V_51 [ V_47 ] ;
}
return F_139 ( V_5 , V_2 , V_13 ) ;
}
static bool F_141 ( struct V_4 * V_5 , struct V_1 * V_2 ,
struct V_12 * V_13 )
{
bool V_70 ;
if ( V_13 -> V_6 == V_2 -> V_6 &&
! F_25 ( F_2 ( V_13 -> V_78 ) ) ) {
V_70 = F_139 ( V_5 , V_2 , V_13 ) ;
} else {
V_70 = F_140 ( V_5 , V_2 , V_13 ) ;
V_13 -> V_6 = V_2 -> V_6 ;
F_6 ( V_5 -> V_27 , V_13 -> V_7 , F_7 ( L_36 ) ) ;
}
if ( V_13 -> V_7 != V_2 -> V_7 || F_25 ( F_2 ( V_13 -> V_78 ) ) ) {
V_13 -> V_7 = V_2 -> V_7 ;
F_6 ( V_5 -> V_27 , V_13 -> V_7 , F_7 ( L_37 ) ) ;
V_13 -> V_9 = 0 ;
V_13 -> V_118 = F_5 ( V_23 ) ;
V_13 -> V_119 = ! ! ( V_2 -> V_96 & V_13 -> V_71 ) ;
F_142 ( V_13 ) ;
F_93 ( V_13 -> V_78 , false ) ;
}
return V_70 ;
}
static void F_143 ( struct V_4 * V_5 , struct V_12 * V_13 )
{
unsigned long V_11 ;
bool V_120 ;
struct V_1 * V_2 ;
F_11 ( V_11 ) ;
V_2 = V_13 -> V_20 ;
if ( ( V_13 -> V_7 == F_2 ( V_2 -> V_7 ) &&
V_13 -> V_6 == F_2 ( V_2 -> V_6 ) &&
! F_25 ( F_2 ( V_13 -> V_78 ) ) ) ||
! F_144 ( & V_2 -> V_95 ) ) {
F_21 ( V_11 ) ;
return;
}
F_132 () ;
V_120 = F_141 ( V_5 , V_2 , V_13 ) ;
F_109 ( & V_2 -> V_95 , V_11 ) ;
if ( V_120 )
F_137 ( V_5 ) ;
}
static void F_145 ( struct V_4 * V_5 , int V_121 )
{
if ( V_121 > 0 &&
! ( V_5 -> V_7 % ( V_122 * V_123 * V_121 ) ) )
F_146 ( V_121 ) ;
}
static int F_147 ( struct V_4 * V_5 )
{
unsigned long V_124 ;
struct V_12 * V_13 ;
struct V_1 * V_2 = F_44 ( V_5 ) ;
F_93 ( V_5 -> V_93 , V_84 ) ;
F_148 ( & V_2 -> V_95 ) ;
F_132 () ;
if ( ! F_2 ( V_5 -> V_38 ) ) {
F_149 ( & V_2 -> V_95 ) ;
return 0 ;
}
F_93 ( V_5 -> V_38 , 0 ) ;
if ( F_59 ( F_3 ( V_5 ) ) ) {
F_149 ( & V_2 -> V_95 ) ;
return 0 ;
}
F_100 ( V_5 ) ;
F_150 ( & V_5 -> V_7 , V_5 -> V_7 + 1 ) ;
F_6 ( V_5 -> V_27 , V_5 -> V_7 , F_7 ( L_38 ) ) ;
F_149 ( & V_2 -> V_95 ) ;
F_106 (rsp, rnp) {
F_145 ( V_5 , V_125 ) ;
F_148 ( & V_2 -> V_95 ) ;
F_132 () ;
if ( V_2 -> V_126 == V_2 -> V_3 &&
! V_2 -> V_127 ) {
F_149 ( & V_2 -> V_95 ) ;
continue;
}
V_124 = V_2 -> V_126 ;
V_2 -> V_126 = V_2 -> V_3 ;
if ( ! V_124 != ! V_2 -> V_126 ) {
if ( ! V_124 )
F_151 ( V_2 ) ;
else if ( F_152 ( V_2 ) )
V_2 -> V_127 = true ;
else
F_153 ( V_2 ) ;
}
if ( V_2 -> V_127 &&
( ! F_152 ( V_2 ) ||
V_2 -> V_126 ) ) {
V_2 -> V_127 = false ;
F_153 ( V_2 ) ;
}
F_149 ( & V_2 -> V_95 ) ;
}
F_154 (rsp, rnp) {
F_145 ( V_5 , V_128 ) ;
F_148 ( & V_2 -> V_95 ) ;
F_132 () ;
V_13 = F_17 ( V_5 -> V_18 ) ;
F_155 ( V_2 ) ;
V_2 -> V_96 = V_2 -> V_126 ;
F_93 ( V_2 -> V_7 , V_5 -> V_7 ) ;
if ( F_59 ( V_2 -> V_6 != V_5 -> V_6 ) )
F_93 ( V_2 -> V_6 , V_5 -> V_6 ) ;
if ( V_2 == V_13 -> V_20 )
( void ) F_141 ( V_5 , V_2 , V_13 ) ;
F_156 ( V_2 ) ;
F_157 ( V_5 -> V_27 , V_2 -> V_7 ,
V_2 -> V_111 , V_2 -> V_98 ,
V_2 -> V_97 , V_2 -> V_96 ) ;
F_149 ( & V_2 -> V_95 ) ;
F_158 () ;
F_93 ( V_5 -> V_93 , V_84 ) ;
}
return 1 ;
}
static bool F_159 ( struct V_4 * V_5 , int * V_129 )
{
struct V_1 * V_2 = F_44 ( V_5 ) ;
* V_129 = F_2 ( V_5 -> V_38 ) ;
if ( * V_129 & V_130 )
return true ;
if ( ! F_2 ( V_2 -> V_96 ) && ! F_160 ( V_2 ) )
return true ;
return false ;
}
static int F_161 ( struct V_4 * V_5 , int V_131 )
{
int V_132 = V_131 ;
bool V_73 = false ;
unsigned long V_74 ;
struct V_1 * V_2 = F_44 ( V_5 ) ;
F_93 ( V_5 -> V_93 , V_84 ) ;
V_5 -> V_91 ++ ;
if ( V_132 == V_133 ) {
if ( F_162 ( V_5 ) ) {
V_73 = true ;
V_74 = V_84 - V_77 / 4 ;
}
F_163 ( V_5 , F_89 ,
& V_73 , & V_74 ) ;
F_164 ( V_5 , V_73 , V_74 ) ;
V_132 = V_134 ;
} else {
V_73 = true ;
F_163 ( V_5 , F_94 , & V_73 , & V_74 ) ;
}
if ( F_2 ( V_5 -> V_38 ) & V_130 ) {
F_148 ( & V_2 -> V_95 ) ;
F_132 () ;
F_93 ( V_5 -> V_38 ,
F_2 ( V_5 -> V_38 ) & ~ V_130 ) ;
F_149 ( & V_2 -> V_95 ) ;
}
return V_132 ;
}
static void F_165 ( struct V_4 * V_5 )
{
unsigned long V_135 ;
bool V_136 = false ;
int V_137 = 0 ;
struct V_12 * V_13 ;
struct V_1 * V_2 = F_44 ( V_5 ) ;
F_93 ( V_5 -> V_93 , V_84 ) ;
F_148 ( & V_2 -> V_95 ) ;
F_132 () ;
V_135 = V_84 - V_5 -> V_83 ;
if ( V_135 > V_5 -> V_138 )
V_5 -> V_138 = V_135 ;
F_149 ( & V_2 -> V_95 ) ;
F_154 (rsp, rnp) {
F_148 ( & V_2 -> V_95 ) ;
F_132 () ;
F_59 ( F_160 ( V_2 ) ) ;
F_59 ( V_2 -> V_96 ) ;
F_93 ( V_2 -> V_6 , V_5 -> V_7 ) ;
V_13 = F_17 ( V_5 -> V_18 ) ;
if ( V_2 == V_13 -> V_20 )
V_136 = F_141 ( V_5 , V_2 , V_13 ) || V_136 ;
V_137 += F_135 ( V_5 , V_2 ) ;
F_149 ( & V_2 -> V_95 ) ;
F_158 () ;
F_93 ( V_5 -> V_93 , V_84 ) ;
F_145 ( V_5 , V_139 ) ;
}
V_2 = F_44 ( V_5 ) ;
F_148 ( & V_2 -> V_95 ) ;
F_132 () ;
F_166 ( V_2 , V_137 ) ;
F_93 ( V_5 -> V_6 , V_5 -> V_7 ) ;
F_6 ( V_5 -> V_27 , V_5 -> V_6 , F_7 ( L_39 ) ) ;
V_5 -> V_132 = V_140 ;
V_13 = F_17 ( V_5 -> V_18 ) ;
V_136 = F_140 ( V_5 , V_2 , V_13 ) || V_136 ;
if ( V_136 || F_46 ( V_5 , V_13 ) ) {
F_93 ( V_5 -> V_38 , V_141 ) ;
F_6 ( V_5 -> V_27 ,
F_2 ( V_5 -> V_7 ) ,
F_7 ( L_40 ) ) ;
}
F_149 ( & V_2 -> V_95 ) ;
}
static int T_3 F_167 ( void * V_142 )
{
int V_132 ;
int V_143 ;
unsigned long V_88 ;
int V_70 ;
struct V_4 * V_5 = V_142 ;
struct V_1 * V_2 = F_44 ( V_5 ) ;
F_168 () ;
for (; ; ) {
for (; ; ) {
F_6 ( V_5 -> V_27 ,
F_2 ( V_5 -> V_7 ) ,
F_7 ( L_41 ) ) ;
V_5 -> V_28 = V_144 ;
F_169 ( V_5 -> V_117 ,
F_2 ( V_5 -> V_38 ) &
V_141 ) ;
V_5 -> V_28 = V_145 ;
if ( F_147 ( V_5 ) )
break;
F_158 () ;
F_93 ( V_5 -> V_93 , V_84 ) ;
F_170 ( F_171 ( V_56 ) ) ;
F_6 ( V_5 -> V_27 ,
F_2 ( V_5 -> V_7 ) ,
F_7 ( L_42 ) ) ;
}
V_132 = V_133 ;
V_88 = V_146 ;
if ( V_88 > V_94 ) {
V_88 = V_94 ;
V_146 = V_94 ;
}
V_70 = 0 ;
for (; ; ) {
if ( ! V_70 )
V_5 -> V_147 = V_84 + V_88 ;
F_6 ( V_5 -> V_27 ,
F_2 ( V_5 -> V_7 ) ,
F_7 ( L_43 ) ) ;
V_5 -> V_28 = V_148 ;
V_70 = F_172 ( V_5 -> V_117 ,
F_159 ( V_5 , & V_143 ) , V_88 ) ;
V_5 -> V_28 = V_149 ;
if ( ! F_2 ( V_2 -> V_96 ) &&
! F_160 ( V_2 ) )
break;
if ( F_96 ( V_84 , V_5 -> V_147 ) ||
( V_143 & V_130 ) ) {
F_6 ( V_5 -> V_27 ,
F_2 ( V_5 -> V_7 ) ,
F_7 ( L_44 ) ) ;
V_132 = F_161 ( V_5 , V_132 ) ;
F_6 ( V_5 -> V_27 ,
F_2 ( V_5 -> V_7 ) ,
F_7 ( L_45 ) ) ;
F_158 () ;
F_93 ( V_5 -> V_93 , V_84 ) ;
} else {
F_158 () ;
F_93 ( V_5 -> V_93 , V_84 ) ;
F_170 ( F_171 ( V_56 ) ) ;
F_6 ( V_5 -> V_27 ,
F_2 ( V_5 -> V_7 ) ,
F_7 ( L_46 ) ) ;
}
V_88 = V_104 ;
if ( V_88 > V_94 ) {
V_88 = V_94 ;
V_104 = V_94 ;
} else if ( V_88 < 1 ) {
V_88 = 1 ;
V_104 = 1 ;
}
}
V_5 -> V_28 = V_150 ;
F_165 ( V_5 ) ;
V_5 -> V_28 = V_151 ;
}
}
static bool
F_133 ( struct V_4 * V_5 , struct V_1 * V_2 ,
struct V_12 * V_13 )
{
if ( ! V_5 -> V_29 || ! F_46 ( V_5 , V_13 ) ) {
return false ;
}
F_93 ( V_5 -> V_38 , V_141 ) ;
F_6 ( V_5 -> V_27 , F_2 ( V_5 -> V_7 ) ,
F_7 ( L_40 ) ) ;
return true ;
}
static bool F_173 ( struct V_4 * V_5 )
{
struct V_12 * V_13 = F_17 ( V_5 -> V_18 ) ;
struct V_1 * V_2 = F_44 ( V_5 ) ;
bool V_70 = false ;
V_70 = F_140 ( V_5 , V_2 , V_13 ) || V_70 ;
V_70 = F_133 ( V_5 , V_2 , V_13 ) || V_70 ;
return V_70 ;
}
static void F_174 ( struct V_4 * V_5 , unsigned long V_11 )
__releases( rcu_get_root( V_5 )->lock
static void
F_175 ( unsigned long V_152 , struct V_4 * V_5 ,
struct V_1 * V_2 , unsigned long V_105 , unsigned long V_11 )
__releases( V_2 -> V_95 )
{
unsigned long V_124 = 0 ;
struct V_1 * V_153 ;
for (; ; ) {
if ( ! ( V_2 -> V_96 & V_152 ) || V_2 -> V_7 != V_105 ) {
F_109 ( & V_2 -> V_95 , V_11 ) ;
return;
}
F_59 ( V_124 ) ;
V_2 -> V_96 &= ~ V_152 ;
F_176 ( V_5 -> V_27 , V_2 -> V_7 ,
V_152 , V_2 -> V_96 , V_2 -> V_111 ,
V_2 -> V_98 , V_2 -> V_97 ,
! ! V_2 -> V_154 ) ;
if ( V_2 -> V_96 != 0 || F_160 ( V_2 ) ) {
F_109 ( & V_2 -> V_95 , V_11 ) ;
return;
}
V_152 = V_2 -> V_71 ;
if ( V_2 -> V_155 == NULL ) {
break;
}
F_109 ( & V_2 -> V_95 , V_11 ) ;
V_153 = V_2 ;
V_2 = V_2 -> V_155 ;
F_107 ( & V_2 -> V_95 , V_11 ) ;
F_132 () ;
V_124 = V_153 -> V_96 ;
}
F_174 ( V_5 , V_11 ) ;
}
static void F_177 ( struct V_4 * V_5 ,
struct V_1 * V_2 , unsigned long V_11 )
__releases( V_2 -> V_95 )
{
unsigned long V_105 ;
unsigned long V_152 ;
struct V_1 * V_156 ;
if ( V_24 == & V_25 || V_5 != V_24 ||
V_2 -> V_96 != 0 || F_160 ( V_2 ) ) {
F_109 ( & V_2 -> V_95 , V_11 ) ;
return;
}
V_156 = V_2 -> V_155 ;
if ( V_156 == NULL ) {
F_174 ( V_5 , V_11 ) ;
return;
}
V_105 = V_2 -> V_7 ;
V_152 = V_2 -> V_71 ;
F_134 ( & V_2 -> V_95 ) ;
F_131 ( & V_156 -> V_95 ) ;
F_132 () ;
F_175 ( V_152 , V_5 , V_156 , V_105 , V_11 ) ;
}
static void
F_178 ( int V_76 , struct V_4 * V_5 , struct V_12 * V_13 )
{
unsigned long V_11 ;
unsigned long V_152 ;
bool V_120 ;
struct V_1 * V_2 ;
V_2 = V_13 -> V_20 ;
F_107 ( & V_2 -> V_95 , V_11 ) ;
F_132 () ;
if ( ( V_13 -> V_9 == 0 &&
V_13 -> V_118 == F_5 ( V_23 ) ) ||
V_13 -> V_7 != V_2 -> V_7 || V_2 -> V_6 == V_2 -> V_7 ||
V_13 -> V_78 ) {
V_13 -> V_9 = 0 ;
V_13 -> V_118 = F_5 ( V_23 ) ;
F_109 ( & V_2 -> V_95 , V_11 ) ;
return;
}
V_152 = V_13 -> V_71 ;
if ( ( V_2 -> V_96 & V_152 ) == 0 ) {
F_109 ( & V_2 -> V_95 , V_11 ) ;
} else {
V_13 -> V_119 = 0 ;
V_120 = F_139 ( V_5 , V_2 , V_13 ) ;
F_175 ( V_152 , V_5 , V_2 , V_2 -> V_7 , V_11 ) ;
if ( V_120 )
F_137 ( V_5 ) ;
}
}
static void
F_179 ( struct V_4 * V_5 , struct V_12 * V_13 )
{
F_143 ( V_5 , V_13 ) ;
if ( ! V_13 -> V_119 )
return;
if ( ! V_13 -> V_9 &&
V_13 -> V_118 == F_5 ( V_23 ) )
return;
F_178 ( V_13 -> V_76 , V_5 , V_13 ) ;
}
static void
F_180 ( int V_76 , struct V_4 * V_5 ,
struct V_1 * V_2 , struct V_12 * V_13 )
{
if ( ! F_50 ( V_157 ) || F_181 ( V_13 -> V_76 ) )
return;
if ( V_13 -> V_40 != NULL ) {
V_5 -> V_158 += V_13 -> V_158 ;
V_5 -> V_103 += V_13 -> V_103 ;
V_13 -> V_159 += V_13 -> V_103 ;
V_13 -> V_158 = 0 ;
F_93 ( V_13 -> V_103 , 0 ) ;
}
if ( * V_13 -> V_41 [ V_42 ] != NULL ) {
* V_5 -> V_160 = * V_13 -> V_41 [ V_42 ] ;
V_5 -> V_160 = V_13 -> V_41 [ V_48 ] ;
* V_13 -> V_41 [ V_42 ] = NULL ;
}
if ( V_13 -> V_40 != NULL ) {
* V_5 -> V_161 = V_13 -> V_40 ;
V_5 -> V_161 = V_13 -> V_41 [ V_42 ] ;
}
F_125 ( V_13 ) ;
V_13 -> V_41 [ V_48 ] = NULL ;
}
static void F_182 ( struct V_4 * V_5 , unsigned long V_11 )
{
int V_47 ;
struct V_12 * V_13 = F_15 ( V_5 -> V_18 ) ;
if ( ! F_50 ( V_157 ) ||
F_183 ( V_5 , V_13 , V_11 ) )
return;
V_13 -> V_158 += V_5 -> V_158 ;
V_13 -> V_103 += V_5 -> V_103 ;
V_13 -> V_162 += V_5 -> V_103 ;
if ( V_5 -> V_158 != V_5 -> V_103 )
F_184 () ;
V_5 -> V_158 = 0 ;
V_5 -> V_103 = 0 ;
if ( V_5 -> V_163 != NULL ) {
* V_5 -> V_161 = * V_13 -> V_41 [ V_42 ] ;
* V_13 -> V_41 [ V_42 ] = V_5 -> V_163 ;
for ( V_47 = V_108 - 1 ; V_47 >= V_42 ; V_47 -- )
if ( V_13 -> V_41 [ V_47 ] == V_13 -> V_41 [ V_42 ] )
V_13 -> V_41 [ V_47 ] = V_5 -> V_161 ;
V_5 -> V_163 = NULL ;
V_5 -> V_161 = & V_5 -> V_163 ;
}
if ( V_5 -> V_164 != NULL ) {
* V_13 -> V_41 [ V_48 ] = V_5 -> V_164 ;
V_13 -> V_41 [ V_48 ] = V_5 -> V_160 ;
V_5 -> V_164 = NULL ;
V_5 -> V_160 = & V_5 -> V_164 ;
}
}
static void F_185 ( struct V_4 * V_5 )
{
F_186 (unsigned long mask) ;
F_186 ( struct V_12 * V_13 = F_17 ( V_5 -> V_18 ) ) ;
F_186 ( struct V_1 * V_2 = V_13 -> V_20 ) ;
if ( ! F_50 ( V_157 ) )
return;
F_186 ( V_152 = V_13 -> V_71 ) ;
F_6 ( V_5 -> V_27 ,
V_2 -> V_7 + 1 - ! ! ( V_2 -> V_96 & V_152 ) ,
F_7 ( L_47 ) ) ;
}
static void F_153 ( struct V_1 * V_165 )
{
long V_152 ;
struct V_1 * V_2 = V_165 ;
if ( ! F_50 ( V_157 ) ||
V_2 -> V_126 || F_152 ( V_2 ) )
return;
for (; ; ) {
V_152 = V_2 -> V_71 ;
V_2 = V_2 -> V_155 ;
if ( ! V_2 )
break;
F_131 ( & V_2 -> V_95 ) ;
F_132 () ;
V_2 -> V_126 &= ~ V_152 ;
V_2 -> V_96 &= ~ V_152 ;
if ( V_2 -> V_126 ) {
F_134 ( & V_2 -> V_95 ) ;
return;
}
F_134 ( & V_2 -> V_95 ) ;
}
}
static void F_187 ( int V_76 , struct V_4 * V_5 )
{
unsigned long V_11 ;
unsigned long V_152 ;
struct V_12 * V_13 = F_116 ( V_5 -> V_18 , V_76 ) ;
struct V_1 * V_2 = V_13 -> V_20 ;
if ( ! F_50 ( V_157 ) )
return;
V_152 = V_13 -> V_71 ;
F_107 ( & V_2 -> V_95 , V_11 ) ;
F_132 () ;
V_2 -> V_3 &= ~ V_152 ;
F_109 ( & V_2 -> V_95 , V_11 ) ;
}
static void F_188 ( int V_76 , struct V_4 * V_5 )
{
unsigned long V_11 ;
struct V_12 * V_13 = F_116 ( V_5 -> V_18 , V_76 ) ;
struct V_1 * V_2 = V_13 -> V_20 ;
if ( ! F_50 ( V_157 ) )
return;
F_189 ( V_2 , - 1 ) ;
F_107 ( & V_5 -> V_166 , V_11 ) ;
F_180 ( V_76 , V_5 , V_2 , V_13 ) ;
F_182 ( V_5 , V_11 ) ;
F_109 ( & V_5 -> V_166 , V_11 ) ;
F_55 ( V_13 -> V_103 != 0 || V_13 -> V_40 != NULL ,
L_48 ,
V_76 , V_13 -> V_103 , V_13 -> V_40 ) ;
}
static void F_190 ( struct V_4 * V_5 , struct V_12 * V_13 )
{
unsigned long V_11 ;
struct V_167 * V_168 , * V_169 , * * V_170 ;
long V_171 , V_172 , V_173 ;
int V_47 ;
if ( ! F_43 ( V_13 ) ) {
F_191 ( V_5 -> V_27 , V_13 -> V_158 , V_13 -> V_103 , 0 ) ;
F_192 ( V_5 -> V_27 , 0 , ! ! F_2 ( V_13 -> V_40 ) ,
F_193 () , F_51 ( V_56 ) ,
F_194 () ) ;
return;
}
F_11 ( V_11 ) ;
F_59 ( F_97 ( F_53 () ) ) ;
V_171 = V_13 -> V_174 ;
F_191 ( V_5 -> V_27 , V_13 -> V_158 , V_13 -> V_103 , V_171 ) ;
V_169 = V_13 -> V_40 ;
V_13 -> V_40 = * V_13 -> V_41 [ V_42 ] ;
* V_13 -> V_41 [ V_42 ] = NULL ;
V_170 = V_13 -> V_41 [ V_42 ] ;
for ( V_47 = V_108 - 1 ; V_47 >= 0 ; V_47 -- )
if ( V_13 -> V_41 [ V_47 ] == V_13 -> V_41 [ V_42 ] )
V_13 -> V_41 [ V_47 ] = & V_13 -> V_40 ;
F_21 ( V_11 ) ;
V_172 = V_173 = 0 ;
while ( V_169 ) {
V_168 = V_169 -> V_168 ;
F_195 ( V_168 ) ;
F_196 ( V_169 ) ;
if ( F_197 ( V_5 -> V_27 , V_169 ) )
V_173 ++ ;
V_169 = V_168 ;
if ( ++ V_172 >= V_171 &&
( F_193 () ||
( ! F_51 ( V_56 ) && ! F_194 () ) ) )
break;
}
F_11 ( V_11 ) ;
F_192 ( V_5 -> V_27 , V_172 , ! ! V_169 , F_193 () ,
F_51 ( V_56 ) ,
F_194 () ) ;
if ( V_169 != NULL ) {
* V_170 = V_13 -> V_40 ;
V_13 -> V_40 = V_169 ;
for ( V_47 = 0 ; V_47 < V_108 ; V_47 ++ )
if ( & V_13 -> V_40 == V_13 -> V_41 [ V_47 ] )
V_13 -> V_41 [ V_47 ] = V_170 ;
else
break;
}
F_16 () ;
V_13 -> V_158 -= V_173 ;
F_93 ( V_13 -> V_103 , V_13 -> V_103 - V_172 ) ;
V_13 -> V_175 += V_172 ;
if ( V_13 -> V_174 == V_176 && V_13 -> V_103 <= V_177 )
V_13 -> V_174 = V_174 ;
if ( V_13 -> V_103 == 0 && V_13 -> V_178 != 0 ) {
V_13 -> V_178 = 0 ;
V_13 -> V_179 = V_5 -> V_91 ;
} else if ( V_13 -> V_103 < V_13 -> V_178 - V_180 )
V_13 -> V_178 = V_13 -> V_103 ;
F_59 ( ( V_13 -> V_40 == NULL ) != ( V_13 -> V_103 == 0 ) ) ;
F_21 ( V_11 ) ;
if ( F_43 ( V_13 ) )
F_198 () ;
}
void F_199 ( int V_53 )
{
F_23 ( F_7 ( L_49 ) ) ;
F_200 () ;
if ( V_53 || F_88 () ) {
F_4 () ;
F_9 () ;
} else if ( ! F_201 () ) {
F_9 () ;
}
F_202 () ;
if ( F_203 () )
F_198 () ;
if ( V_53 )
F_204 ( V_56 ) ;
F_23 ( F_7 ( L_50 ) ) ;
}
static void F_163 ( struct V_4 * V_5 ,
int (* F_205)( struct V_12 * V_5 , bool * V_73 ,
unsigned long * V_74 ) ,
bool * V_73 , unsigned long * V_74 )
{
unsigned long V_181 ;
int V_76 ;
unsigned long V_11 ;
unsigned long V_152 ;
struct V_1 * V_2 ;
F_106 (rsp, rnp) {
F_158 () ;
V_152 = 0 ;
F_107 ( & V_2 -> V_95 , V_11 ) ;
F_132 () ;
if ( V_2 -> V_96 == 0 ) {
if ( V_24 == & V_25 ||
V_5 != V_24 ||
F_160 ( V_2 ) ) {
F_206 ( V_2 , V_11 ) ;
continue;
}
if ( V_2 -> V_155 &&
( V_2 -> V_155 -> V_96 & V_2 -> V_71 ) ) {
F_177 ( V_5 , V_2 , V_11 ) ;
continue;
}
}
V_76 = V_2 -> V_98 ;
V_181 = 1 ;
for (; V_76 <= V_2 -> V_97 ; V_76 ++ , V_181 <<= 1 ) {
if ( ( V_2 -> V_96 & V_181 ) != 0 ) {
if ( F_205 ( F_116 ( V_5 -> V_18 , V_76 ) , V_73 , V_74 ) )
V_152 |= V_181 ;
}
}
if ( V_152 != 0 ) {
F_175 ( V_152 , V_5 , V_2 , V_2 -> V_7 , V_11 ) ;
} else {
F_109 ( & V_2 -> V_95 , V_11 ) ;
}
}
}
static void F_35 ( struct V_4 * V_5 )
{
unsigned long V_11 ;
bool V_70 ;
struct V_1 * V_2 ;
struct V_1 * V_182 = NULL ;
V_2 = F_5 ( V_5 -> V_18 -> V_20 ) ;
for (; V_2 != NULL ; V_2 = V_2 -> V_155 ) {
V_70 = ( F_2 ( V_5 -> V_38 ) & V_130 ) ||
! F_144 ( & V_2 -> V_183 ) ;
if ( V_182 != NULL )
F_134 ( & V_182 -> V_183 ) ;
if ( V_70 ) {
V_5 -> V_184 ++ ;
return;
}
V_182 = V_2 ;
}
F_107 ( & V_182 -> V_95 , V_11 ) ;
F_132 () ;
F_134 ( & V_182 -> V_183 ) ;
if ( F_2 ( V_5 -> V_38 ) & V_130 ) {
V_5 -> V_184 ++ ;
F_109 ( & V_182 -> V_95 , V_11 ) ;
return;
}
F_93 ( V_5 -> V_38 , F_2 ( V_5 -> V_38 ) | V_130 ) ;
F_109 ( & V_182 -> V_95 , V_11 ) ;
F_137 ( V_5 ) ;
}
static void
F_207 ( struct V_4 * V_5 )
{
unsigned long V_11 ;
bool V_120 ;
struct V_12 * V_13 = F_15 ( V_5 -> V_18 ) ;
F_59 ( V_13 -> V_185 == 0 ) ;
F_179 ( V_5 , V_13 ) ;
F_11 ( V_11 ) ;
if ( F_46 ( V_5 , V_13 ) ) {
F_131 ( & F_44 ( V_5 ) -> V_95 ) ;
V_120 = F_173 ( V_5 ) ;
F_109 ( & F_44 ( V_5 ) -> V_95 , V_11 ) ;
if ( V_120 )
F_137 ( V_5 ) ;
} else {
F_21 ( V_11 ) ;
}
if ( F_43 ( V_13 ) )
F_208 ( V_5 , V_13 ) ;
F_56 ( V_13 ) ;
}
static void F_209 ( struct V_186 * V_187 )
{
struct V_4 * V_5 ;
if ( F_97 ( F_53 () ) )
return;
F_23 ( F_7 ( L_51 ) ) ;
F_14 (rsp)
F_207 ( V_5 ) ;
F_23 ( F_7 ( L_52 ) ) ;
}
static void F_208 ( struct V_4 * V_5 , struct V_12 * V_13 )
{
if ( F_25 ( ! F_2 ( V_72 ) ) )
return;
if ( F_210 ( ! V_5 -> V_188 ) ) {
F_190 ( V_5 , V_13 ) ;
return;
}
F_211 () ;
}
static void F_198 ( void )
{
if ( F_212 ( F_53 () ) )
F_213 ( V_189 ) ;
}
static void F_214 ( struct V_4 * V_5 , struct V_12 * V_13 ,
struct V_167 * V_190 , unsigned long V_11 )
{
bool V_120 ;
if ( ! F_81 () )
F_198 () ;
if ( F_215 ( V_11 ) || F_97 ( F_53 () ) )
return;
if ( F_25 ( V_13 -> V_103 > V_13 -> V_178 + V_180 ) ) {
F_143 ( V_5 , V_13 ) ;
if ( ! F_3 ( V_5 ) ) {
struct V_1 * V_113 = F_44 ( V_5 ) ;
F_131 ( & V_113 -> V_95 ) ;
F_132 () ;
V_120 = F_173 ( V_5 ) ;
F_134 ( & V_113 -> V_95 ) ;
if ( V_120 )
F_137 ( V_5 ) ;
} else {
V_13 -> V_174 = V_176 ;
if ( V_5 -> V_91 == V_13 -> V_179 &&
* V_13 -> V_41 [ V_42 ] != V_190 )
F_35 ( V_5 ) ;
V_13 -> V_179 = V_5 -> V_91 ;
V_13 -> V_178 = V_13 -> V_103 ;
}
}
}
static void F_216 ( struct V_167 * V_191 )
{
}
static void
F_217 ( struct V_167 * V_190 , void (* F_218)( struct V_167 * V_192 ) ,
struct V_4 * V_5 , int V_76 , bool V_193 )
{
unsigned long V_11 ;
struct V_12 * V_13 ;
F_59 ( ( unsigned long ) V_190 & 0x1 ) ;
if ( F_219 ( V_190 ) ) {
F_93 ( V_190 -> F_218 , F_216 ) ;
F_55 ( 1 , L_53 ) ;
return;
}
V_190 -> F_218 = F_218 ;
V_190 -> V_168 = NULL ;
F_11 ( V_11 ) ;
V_13 = F_17 ( V_5 -> V_18 ) ;
if ( F_25 ( V_13 -> V_41 [ V_48 ] == NULL ) || V_76 != - 1 ) {
int V_194 ;
if ( V_76 != - 1 )
V_13 = F_116 ( V_5 -> V_18 , V_76 ) ;
if ( F_210 ( V_13 -> V_20 ) ) {
V_194 = ! F_220 ( V_13 , V_190 , V_193 , V_11 ) ;
F_59 ( V_194 ) ;
F_21 ( V_11 ) ;
return;
}
F_221 ( V_76 != - 1 ) ;
F_59 ( ! F_81 () ) ;
if ( ! F_210 ( V_13 -> V_40 ) )
F_124 ( V_13 ) ;
}
F_93 ( V_13 -> V_103 , V_13 -> V_103 + 1 ) ;
if ( V_193 )
V_13 -> V_158 ++ ;
else
F_184 () ;
F_16 () ;
* V_13 -> V_41 [ V_48 ] = V_190 ;
V_13 -> V_41 [ V_48 ] = & V_190 -> V_168 ;
if ( F_222 ( ( unsigned long ) F_218 ) )
F_223 ( V_5 -> V_27 , V_190 , ( unsigned long ) F_218 ,
V_13 -> V_158 , V_13 -> V_103 ) ;
else
F_224 ( V_5 -> V_27 , V_190 , V_13 -> V_158 , V_13 -> V_103 ) ;
F_214 ( V_5 , V_13 , V_190 , V_11 ) ;
F_21 ( V_11 ) ;
}
void F_225 ( struct V_167 * V_190 , void (* F_218)( struct V_167 * V_192 ) )
{
F_217 ( V_190 , F_218 , & V_25 , - 1 , 0 ) ;
}
void F_226 ( struct V_167 * V_190 , void (* F_218)( struct V_167 * V_192 ) )
{
F_217 ( V_190 , F_218 , & V_26 , - 1 , 0 ) ;
}
void F_227 ( struct V_167 * V_190 ,
void (* F_218)( struct V_167 * V_192 ) )
{
F_217 ( V_190 , F_218 , V_24 , - 1 , 1 ) ;
}
static inline int F_228 ( void )
{
int V_70 ;
F_229 () ;
F_86 () ;
V_70 = F_230 () <= 1 ;
F_87 () ;
return V_70 ;
}
void F_231 ( void )
{
F_62 ( F_63 ( & V_63 ) ||
F_63 ( & V_62 ) ||
F_63 ( & V_64 ) ,
L_54 ) ;
if ( F_228 () )
return;
if ( F_232 () )
F_233 () ;
else
F_234 ( F_225 ) ;
}
void F_235 ( void )
{
F_62 ( F_63 ( & V_63 ) ||
F_63 ( & V_62 ) ||
F_63 ( & V_64 ) ,
L_55 ) ;
if ( F_228 () )
return;
if ( F_232 () )
F_236 () ;
else
F_234 ( F_226 ) ;
}
unsigned long F_237 ( void )
{
F_16 () ;
return F_238 ( & V_24 -> V_7 ) ;
}
void F_239 ( unsigned long V_195 )
{
unsigned long V_196 ;
V_196 = F_238 ( & V_24 -> V_6 ) ;
if ( F_96 ( V_195 , V_196 ) )
F_240 () ;
}
unsigned long F_241 ( void )
{
F_16 () ;
return F_238 ( & V_25 . V_7 ) ;
}
void F_242 ( unsigned long V_195 )
{
unsigned long V_196 ;
V_196 = F_238 ( & V_25 . V_6 ) ;
if ( F_96 ( V_195 , V_196 ) )
F_231 () ;
}
static void F_243 ( unsigned long * V_197 )
{
F_93 ( * V_197 , * V_197 + 1 ) ;
F_16 () ;
F_59 ( ! ( * V_197 & 0x1 ) ) ;
}
static void F_244 ( unsigned long * V_197 )
{
F_16 () ;
F_93 ( * V_197 , * V_197 + 1 ) ;
F_59 ( * V_197 & 0x1 ) ;
}
static unsigned long F_245 ( unsigned long * V_197 )
{
unsigned long V_110 ;
F_16 () ;
V_110 = ( F_2 ( * V_197 ) + 3 ) & ~ 0x1 ;
F_16 () ;
return V_110 ;
}
static bool F_246 ( unsigned long * V_197 , unsigned long V_110 )
{
return F_96 ( F_2 ( * V_197 ) , V_110 ) ;
}
static void F_247 ( struct V_4 * V_5 )
{
F_243 ( & V_5 -> V_198 ) ;
}
static void F_248 ( struct V_4 * V_5 )
{
F_244 ( & V_5 -> V_198 ) ;
F_16 () ;
}
static unsigned long F_249 ( struct V_4 * V_5 )
{
return F_245 ( & V_5 -> V_198 ) ;
}
static bool F_250 ( struct V_4 * V_5 , unsigned long V_110 )
{
return F_246 ( & V_5 -> V_198 , V_110 ) ;
}
static bool F_251 ( struct V_4 * V_5 , struct V_1 * V_2 ,
struct V_12 * V_13 ,
T_4 * V_199 , unsigned long V_110 )
{
if ( F_250 ( V_5 , V_110 ) ) {
if ( V_2 )
F_252 ( & V_2 -> V_200 ) ;
else if ( V_13 )
F_252 ( & V_13 -> V_200 ) ;
F_18 () ;
F_253 ( V_199 ) ;
return true ;
}
return false ;
}
static struct V_1 * F_254 ( struct V_4 * V_5 , unsigned long V_110 )
{
struct V_12 * V_13 ;
struct V_1 * V_201 ;
struct V_1 * V_202 = NULL ;
V_201 = F_44 ( V_5 ) ;
if ( ! F_255 ( & V_201 -> V_200 ) ) {
if ( F_256 ( & V_201 -> V_200 ) ) {
if ( F_251 ( V_5 , V_201 , NULL ,
& V_5 -> V_203 , V_110 ) )
return NULL ;
return V_201 ;
}
}
V_13 = F_116 ( V_5 -> V_18 , F_257 () ) ;
if ( F_251 ( V_5 , NULL , NULL , & V_5 -> V_204 , V_110 ) )
return NULL ;
F_258 ( & V_13 -> V_200 ) ;
V_201 = V_13 -> V_20 ;
for (; V_201 != NULL ; V_201 = V_201 -> V_155 ) {
if ( F_251 ( V_5 , V_202 , V_13 ,
& V_5 -> V_205 , V_110 ) )
return NULL ;
F_258 ( & V_201 -> V_200 ) ;
if ( V_202 )
F_252 ( & V_202 -> V_200 ) ;
else
F_252 ( & V_13 -> V_200 ) ;
V_202 = V_201 ;
}
if ( F_251 ( V_5 , V_202 , V_13 ,
& V_5 -> V_206 , V_110 ) )
return NULL ;
return V_202 ;
}
static int F_259 ( void * V_207 )
{
struct V_12 * V_13 = V_207 ;
struct V_4 * V_5 = V_13 -> V_5 ;
V_13 -> V_208 = true ;
if ( F_260 ( & V_5 -> V_209 ) )
F_138 ( & V_5 -> V_210 ) ;
return 0 ;
}
static void F_261 ( struct V_4 * V_5 )
{
int V_76 ;
unsigned long V_89 ;
unsigned long V_211 ;
struct V_12 * V_13 ;
int V_70 ;
V_89 = F_102 () ;
V_211 = V_84 ;
for (; ; ) {
V_70 = F_172 (
V_5 -> V_210 ,
! F_60 ( & V_5 -> V_209 ) ,
V_89 ) ;
if ( V_70 > 0 )
return;
if ( V_70 < 0 ) {
F_262 ( V_5 -> V_210 ,
! F_60 ( & V_5 -> V_209 ) ) ;
return;
}
F_104 ( L_56 ,
V_5 -> V_27 ) ;
F_263 (cpu) {
V_13 = F_116 ( V_5 -> V_18 , V_76 ) ;
if ( V_13 -> V_208 )
continue;
F_117 ( L_57 , V_76 ) ;
}
F_117 ( L_58 ,
V_84 - V_211 , V_5 -> V_198 ) ;
F_263 (cpu) {
V_13 = F_116 ( V_5 -> V_18 , V_76 ) ;
if ( V_13 -> V_208 )
continue;
F_108 ( V_76 ) ;
}
V_89 = 3 * F_102 () + 3 ;
}
}
void F_233 ( void )
{
int V_76 ;
unsigned long V_110 ;
struct V_1 * V_2 ;
struct V_4 * V_5 = & V_25 ;
V_110 = F_249 ( V_5 ) ;
if ( ! F_264 () ) {
F_234 ( F_225 ) ;
F_253 ( & V_5 -> V_212 ) ;
return;
}
F_59 ( F_97 ( F_257 () ) ) ;
V_2 = F_254 ( V_5 , V_110 ) ;
if ( V_2 == NULL ) {
F_265 () ;
return;
}
F_247 ( V_5 ) ;
F_266 ( & V_5 -> V_210 ) ;
F_267 ( & V_5 -> V_209 , 1 ) ;
F_263 (cpu) {
struct V_12 * V_13 = F_116 ( V_5 -> V_18 , V_76 ) ;
struct V_14 * V_15 = & F_98 ( V_14 , V_76 ) ;
V_13 -> V_208 = false ;
if ( F_257 () == V_76 ||
! ( F_90 ( 0 , & V_15 -> V_22 ) & 0x1 ) )
continue;
F_58 ( & V_5 -> V_209 ) ;
F_268 ( V_76 , F_259 ,
V_13 , & V_13 -> V_213 ) ;
}
if ( ! F_260 ( & V_5 -> V_209 ) )
F_261 ( V_5 ) ;
F_248 ( V_5 ) ;
F_252 ( & V_2 -> V_200 ) ;
F_265 () ;
}
static int F_269 ( struct V_4 * V_5 , struct V_12 * V_13 )
{
struct V_1 * V_2 = V_13 -> V_20 ;
V_13 -> V_214 ++ ;
F_121 ( V_5 , V_13 ) ;
if ( F_270 ( V_5 ) )
return 0 ;
if ( V_72 &&
V_13 -> V_119 && ! V_13 -> V_9 &&
V_13 -> V_118 == F_5 ( V_23 ) ) {
V_13 -> V_215 ++ ;
} else if ( V_13 -> V_119 &&
( V_13 -> V_9 ||
V_13 -> V_118 != F_5 ( V_23 ) ) ) {
V_13 -> V_216 ++ ;
return 1 ;
}
if ( F_43 ( V_13 ) ) {
V_13 -> V_217 ++ ;
return 1 ;
}
if ( F_46 ( V_5 , V_13 ) ) {
V_13 -> V_218 ++ ;
return 1 ;
}
if ( F_2 ( V_2 -> V_6 ) != V_13 -> V_6 ) {
V_13 -> V_219 ++ ;
return 1 ;
}
if ( F_2 ( V_2 -> V_7 ) != V_13 -> V_7 ||
F_25 ( F_2 ( V_13 -> V_78 ) ) ) {
V_13 -> V_220 ++ ;
return 1 ;
}
if ( F_271 ( V_13 ) ) {
V_13 -> V_221 ++ ;
return 1 ;
}
V_13 -> V_222 ++ ;
return 0 ;
}
static int F_203 ( void )
{
struct V_4 * V_5 ;
F_14 (rsp)
if ( F_269 ( V_5 , F_17 ( V_5 -> V_18 ) ) )
return 1 ;
return 0 ;
}
static bool V_58 F_272 ( bool * V_223 )
{
bool V_224 = true ;
bool V_225 = false ;
struct V_12 * V_13 ;
struct V_4 * V_5 ;
F_14 (rsp) {
V_13 = F_17 ( V_5 -> V_18 ) ;
if ( ! V_13 -> V_40 )
continue;
V_225 = true ;
if ( V_13 -> V_103 != V_13 -> V_158 || ! V_223 ) {
V_224 = false ;
break;
}
}
if ( V_223 )
* V_223 = V_224 ;
return V_225 ;
}
static void F_273 ( struct V_4 * V_5 , const char * V_110 ,
int V_76 , unsigned long V_226 )
{
F_274 ( V_5 -> V_27 , V_110 , V_76 ,
F_60 ( & V_5 -> V_227 ) , V_226 ) ;
}
static void F_275 ( struct V_167 * V_191 )
{
struct V_12 * V_13 = F_276 ( V_191 , struct V_12 , V_228 ) ;
struct V_4 * V_5 = V_13 -> V_5 ;
if ( F_260 ( & V_5 -> V_227 ) ) {
F_273 ( V_5 , L_59 , - 1 , V_5 -> V_229 ) ;
F_277 ( & V_5 -> V_230 ) ;
} else {
F_273 ( V_5 , L_60 , - 1 , V_5 -> V_229 ) ;
}
}
static void F_278 ( void * type )
{
struct V_4 * V_5 = type ;
struct V_12 * V_13 = F_15 ( V_5 -> V_18 ) ;
F_273 ( V_5 , L_61 , - 1 , V_5 -> V_229 ) ;
F_58 ( & V_5 -> V_227 ) ;
V_5 -> V_231 ( & V_13 -> V_228 , F_275 ) ;
}
static void F_279 ( struct V_4 * V_5 )
{
int V_76 ;
struct V_12 * V_13 ;
unsigned long V_110 = F_245 ( & V_5 -> V_229 ) ;
F_273 ( V_5 , L_62 , - 1 , V_110 ) ;
F_258 ( & V_5 -> V_232 ) ;
if ( F_246 ( & V_5 -> V_229 , V_110 ) ) {
F_273 ( V_5 , L_63 , - 1 , V_5 -> V_229 ) ;
F_16 () ;
F_252 ( & V_5 -> V_232 ) ;
return;
}
F_243 ( & V_5 -> V_229 ) ;
F_273 ( V_5 , L_64 , - 1 , V_5 -> V_229 ) ;
F_280 ( & V_5 -> V_230 ) ;
F_267 ( & V_5 -> V_227 , 1 ) ;
F_281 () ;
F_115 (cpu) {
if ( ! F_212 ( V_76 ) && ! F_181 ( V_76 ) )
continue;
V_13 = F_116 ( V_5 -> V_18 , V_76 ) ;
if ( F_181 ( V_76 ) ) {
if ( ! F_282 ( V_5 , V_76 ) ) {
F_273 ( V_5 , L_65 , V_76 ,
V_5 -> V_229 ) ;
} else {
F_273 ( V_5 , L_66 , V_76 ,
V_5 -> V_229 ) ;
F_18 () ;
F_58 ( & V_5 -> V_227 ) ;
F_217 ( & V_13 -> V_228 ,
F_275 , V_5 , V_76 , 0 ) ;
}
} else if ( F_2 ( V_13 -> V_103 ) ) {
F_273 ( V_5 , L_67 , V_76 ,
V_5 -> V_229 ) ;
F_283 ( V_76 , F_278 , V_5 , 1 ) ;
} else {
F_273 ( V_5 , L_68 , V_76 ,
V_5 -> V_229 ) ;
}
}
F_265 () ;
if ( F_260 ( & V_5 -> V_227 ) )
F_277 ( & V_5 -> V_230 ) ;
F_284 ( & V_5 -> V_230 ) ;
F_273 ( V_5 , L_69 , - 1 , V_5 -> V_229 ) ;
F_244 ( & V_5 -> V_229 ) ;
F_252 ( & V_5 -> V_232 ) ;
}
void F_285 ( void )
{
F_279 ( & V_26 ) ;
}
void F_286 ( void )
{
F_279 ( & V_25 ) ;
}
static void F_151 ( struct V_1 * V_165 )
{
long V_152 ;
struct V_1 * V_2 = V_165 ;
for (; ; ) {
V_152 = V_2 -> V_71 ;
V_2 = V_2 -> V_155 ;
if ( V_2 == NULL )
return;
F_131 ( & V_2 -> V_95 ) ;
V_2 -> V_126 |= V_152 ;
F_134 ( & V_2 -> V_95 ) ;
}
}
static void T_5
F_287 ( int V_76 , struct V_4 * V_5 )
{
static struct V_233 V_234 ;
unsigned long V_11 ;
struct V_12 * V_13 = F_116 ( V_5 -> V_18 , V_76 ) ;
struct V_1 * V_2 = F_44 ( V_5 ) ;
F_107 ( & V_2 -> V_95 , V_11 ) ;
V_13 -> V_71 = 1UL << ( V_76 - V_13 -> V_20 -> V_98 ) ;
V_13 -> V_22 = & F_98 ( V_14 , V_76 ) ;
F_59 ( V_13 -> V_22 -> V_54 != V_67 ) ;
F_59 ( F_60 ( & V_13 -> V_22 -> V_22 ) != 1 ) ;
V_13 -> V_76 = V_76 ;
V_13 -> V_5 = V_5 ;
F_288 ( & V_13 -> V_200 ) ;
F_289 ( V_13 ) ;
F_109 ( & V_2 -> V_95 , V_11 ) ;
if ( V_5 == & V_25 )
F_290 ( & V_13 -> V_200 ,
& V_234 ,
L_70 ) ;
}
static void
F_291 ( int V_76 , struct V_4 * V_5 )
{
unsigned long V_11 ;
unsigned long V_152 ;
struct V_12 * V_13 = F_116 ( V_5 -> V_18 , V_76 ) ;
struct V_1 * V_2 = F_44 ( V_5 ) ;
F_107 ( & V_2 -> V_95 , V_11 ) ;
V_13 -> V_185 = 1 ;
V_13 -> V_178 = 0 ;
V_13 -> V_179 = V_5 -> V_91 ;
V_13 -> V_174 = V_174 ;
if ( ! V_13 -> V_40 )
F_125 ( V_13 ) ;
V_13 -> V_22 -> V_54 = V_67 ;
F_292 ( V_13 -> V_22 ) ;
F_267 ( & V_13 -> V_22 -> V_22 ,
( F_60 ( & V_13 -> V_22 -> V_22 ) & ~ 0x1 ) + 1 ) ;
F_134 ( & V_2 -> V_95 ) ;
V_2 = V_13 -> V_20 ;
V_152 = V_13 -> V_71 ;
F_131 ( & V_2 -> V_95 ) ;
F_132 () ;
V_2 -> V_3 |= V_152 ;
V_13 -> V_7 = V_2 -> V_6 ;
V_13 -> V_6 = V_2 -> V_6 ;
V_13 -> V_9 = false ;
V_13 -> V_118 = F_98 ( V_23 , V_76 ) ;
V_13 -> V_119 = false ;
F_6 ( V_5 -> V_27 , V_13 -> V_7 , F_7 ( L_71 ) ) ;
F_109 ( & V_2 -> V_95 , V_11 ) ;
}
static void F_293 ( int V_76 )
{
struct V_4 * V_5 ;
F_14 (rsp)
F_291 ( V_76 , V_5 ) ;
}
int F_294 ( struct V_235 * V_236 ,
unsigned long V_237 , void * V_238 )
{
long V_76 = ( long ) V_238 ;
struct V_12 * V_13 = F_116 ( V_24 -> V_18 , V_76 ) ;
struct V_1 * V_2 = V_13 -> V_20 ;
struct V_4 * V_5 ;
switch ( V_237 ) {
case V_239 :
case V_240 :
F_293 ( V_76 ) ;
F_295 ( V_76 ) ;
F_296 ( V_76 ) ;
break;
case V_241 :
case V_242 :
F_189 ( V_2 , - 1 ) ;
break;
case V_243 :
F_189 ( V_2 , V_76 ) ;
break;
case V_244 :
case V_245 :
F_14 (rsp)
F_185 ( V_5 ) ;
break;
case V_246 :
F_14 (rsp) {
F_187 ( V_76 , V_5 ) ;
}
break;
case V_247 :
case V_248 :
case V_249 :
case V_250 :
F_14 (rsp) {
F_188 ( V_76 , V_5 ) ;
F_56 ( F_116 ( V_5 -> V_18 , V_76 ) ) ;
}
break;
default:
break;
}
return V_251 ;
}
static int F_297 ( struct V_235 * V_236 ,
unsigned long V_237 , void * V_238 )
{
switch ( V_237 ) {
case V_252 :
case V_253 :
if ( V_254 <= 256 )
F_298 () ;
break;
case V_255 :
case V_256 :
if ( V_254 <= 256 )
F_299 () ;
break;
default:
break;
}
return V_251 ;
}
static int T_5 F_300 ( void )
{
unsigned long V_11 ;
int V_257 = V_258 ;
struct V_1 * V_2 ;
struct V_4 * V_5 ;
struct V_259 V_197 ;
struct V_57 * V_260 ;
if ( F_50 ( V_261 ) && V_258 < 1 )
V_258 = 1 ;
else if ( V_258 < 0 )
V_258 = 0 ;
else if ( V_258 > 99 )
V_258 = 99 ;
if ( V_258 != V_257 )
F_301 ( L_72 ,
V_258 , V_257 ) ;
V_72 = 1 ;
F_14 (rsp) {
V_260 = F_302 ( F_167 , V_5 , L_73 , V_5 -> V_27 ) ;
F_221 ( F_303 ( V_260 ) ) ;
V_2 = F_44 ( V_5 ) ;
F_107 ( & V_2 -> V_95 , V_11 ) ;
V_5 -> V_29 = V_260 ;
if ( V_258 ) {
V_197 . V_262 = V_258 ;
F_304 ( V_260 , V_263 , & V_197 ) ;
}
F_305 ( V_260 ) ;
F_109 ( & V_2 -> V_95 , V_11 ) ;
}
F_306 () ;
F_307 () ;
return 0 ;
}
void F_308 ( void )
{
F_170 ( F_230 () != 1 ) ;
F_170 ( F_309 () > 0 ) ;
V_264 = 1 ;
}
static void T_5 F_310 ( int * V_265 , const int * V_266 )
{
int V_47 ;
if ( V_267 ) {
V_265 [ V_268 - 1 ] = V_269 ;
for ( V_47 = V_268 - 2 ; V_47 >= 0 ; V_47 -- )
V_265 [ V_47 ] = V_270 ;
} else {
int V_271 ;
int V_272 ;
V_272 = V_254 ;
for ( V_47 = V_268 - 1 ; V_47 >= 0 ; V_47 -- ) {
V_271 = V_266 [ V_47 ] ;
V_265 [ V_47 ] = ( V_272 + V_271 - 1 ) / V_271 ;
V_272 = V_271 ;
}
}
}
static void T_5 F_311 ( struct V_4 * V_5 ,
struct V_12 T_6 * V_18 )
{
static const char * const V_273 [] = V_274 ;
static const char * const V_275 [] = V_276 ;
static const char * const exp [] = V_277 ;
static const char * const V_278 [] = V_279 ;
static T_7 V_280 = 0x1 ;
int V_266 [ V_281 ] ;
int V_265 [ V_281 ] ;
int V_282 = 1 ;
int V_47 ;
int V_88 ;
struct V_1 * V_2 ;
F_312 ( V_281 > F_313 ( V_273 ) ) ;
if ( V_268 <= 0 || V_268 > V_281 )
F_314 ( L_74 ) ;
for ( V_47 = 0 ; V_47 < V_268 ; V_47 ++ )
V_266 [ V_47 ] = V_283 [ V_47 ] ;
for ( V_47 = 1 ; V_47 < V_268 ; V_47 ++ )
V_5 -> V_111 [ V_47 ] = V_5 -> V_111 [ V_47 - 1 ] + V_266 [ V_47 - 1 ] ;
F_310 ( V_265 , V_266 ) ;
V_5 -> V_19 = V_280 ;
V_280 <<= 1 ;
for ( V_47 = V_268 - 1 ; V_47 >= 0 ; V_47 -- ) {
V_282 *= V_265 [ V_47 ] ;
V_2 = V_5 -> V_111 [ V_47 ] ;
for ( V_88 = 0 ; V_88 < V_266 [ V_47 ] ; V_88 ++ , V_2 ++ ) {
F_315 ( & V_2 -> V_95 ) ;
F_290 ( & V_2 -> V_95 ,
& V_284 [ V_47 ] , V_273 [ V_47 ] ) ;
F_315 ( & V_2 -> V_183 ) ;
F_290 ( & V_2 -> V_183 ,
& V_285 [ V_47 ] , V_275 [ V_47 ] ) ;
V_2 -> V_7 = V_5 -> V_7 ;
V_2 -> V_6 = V_5 -> V_6 ;
V_2 -> V_96 = 0 ;
V_2 -> V_126 = 0 ;
V_2 -> V_98 = V_88 * V_282 ;
V_2 -> V_97 = ( V_88 + 1 ) * V_282 - 1 ;
if ( V_2 -> V_97 >= V_254 )
V_2 -> V_97 = V_254 - 1 ;
if ( V_47 == 0 ) {
V_2 -> V_286 = 0 ;
V_2 -> V_71 = 0 ;
V_2 -> V_155 = NULL ;
} else {
V_2 -> V_286 = V_88 % V_265 [ V_47 - 1 ] ;
V_2 -> V_71 = 1UL << V_2 -> V_286 ;
V_2 -> V_155 = V_5 -> V_111 [ V_47 - 1 ] +
V_88 / V_265 [ V_47 - 1 ] ;
}
V_2 -> V_111 = V_47 ;
F_316 ( & V_2 -> V_287 ) ;
F_317 ( V_2 ) ;
F_288 ( & V_2 -> V_200 ) ;
if ( V_5 == & V_25 )
F_290 (
& V_2 -> V_200 ,
& V_288 [ V_47 ] , V_278 [ V_47 ] ) ;
else
F_290 (
& V_2 -> V_200 ,
& V_289 [ V_47 ] , exp [ V_47 ] ) ;
}
}
F_266 ( & V_5 -> V_117 ) ;
V_2 = V_5 -> V_111 [ V_268 - 1 ] ;
F_115 (i) {
while ( V_47 > V_2 -> V_97 )
V_2 ++ ;
F_116 ( V_5 -> V_18 , V_47 ) -> V_20 = V_2 ;
F_287 ( V_47 , V_5 ) ;
}
F_318 ( & V_5 -> V_290 , & V_291 ) ;
}
static void T_5 F_319 ( void )
{
T_8 V_292 ;
int V_47 ;
int V_293 [ V_281 ] ;
V_292 = V_294 + V_254 / V_295 ;
if ( V_146 == V_77 )
V_146 = V_292 ;
if ( V_104 == V_77 )
V_104 = V_292 ;
if ( V_269 == V_296 &&
V_254 == V_297 )
return;
F_39 ( L_75 ,
V_269 , V_254 ) ;
if ( V_269 < V_296 ||
V_269 > sizeof( unsigned long ) * 8 ) {
V_269 = V_296 ;
F_170 ( 1 ) ;
return;
}
V_293 [ 0 ] = V_269 ;
for ( V_47 = 1 ; V_47 < V_281 ; V_47 ++ )
V_293 [ V_47 ] = V_293 [ V_47 - 1 ] * V_270 ;
if ( V_254 > V_293 [ V_281 - 1 ] )
F_314 ( L_76 ) ;
for ( V_47 = 0 ; V_254 > V_293 [ V_47 ] ; V_47 ++ ) {
}
V_268 = V_47 + 1 ;
for ( V_47 = 0 ; V_47 < V_268 ; V_47 ++ ) {
int V_298 = V_293 [ ( V_268 - 1 ) - V_47 ] ;
V_283 [ V_47 ] = F_320 ( V_254 , V_298 ) ;
}
V_122 = 0 ;
for ( V_47 = 0 ; V_47 < V_268 ; V_47 ++ )
V_122 += V_283 [ V_47 ] ;
}
static void T_5 F_321 ( struct V_4 * V_5 )
{
int V_111 = 0 ;
struct V_1 * V_2 ;
F_39 ( L_77 ) ;
F_39 ( L_78 ) ;
F_154 (rsp, rnp) {
if ( V_2 -> V_111 != V_111 ) {
F_117 ( L_79 ) ;
F_39 ( L_78 ) ;
V_111 = V_2 -> V_111 ;
}
F_117 ( L_80 , V_2 -> V_98 , V_2 -> V_97 , V_2 -> V_286 ) ;
}
F_117 ( L_79 ) ;
}
void T_5 F_322 ( void )
{
int V_76 ;
F_323 () ;
F_324 () ;
F_319 () ;
F_311 ( & V_26 , & V_10 ) ;
F_311 ( & V_25 , & V_8 ) ;
if ( V_299 )
F_321 ( & V_25 ) ;
F_325 () ;
F_326 ( V_189 , F_209 ) ;
F_327 ( F_294 , 0 ) ;
F_328 ( F_297 , 0 ) ;
F_263 (cpu)
F_294 ( NULL , V_239 , ( void * ) ( long ) V_76 ) ;
}
