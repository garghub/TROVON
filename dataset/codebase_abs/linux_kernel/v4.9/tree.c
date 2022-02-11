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
if ( F_25 ( F_13 ( V_8 . V_9 . V_11 . exp ) ) ) {
F_29 () ;
F_4 () ;
F_30 () ;
}
F_31 ( V_27 ) ;
F_22 () ;
}
unsigned long F_32 ( void )
{
return V_28 -> V_7 ;
}
unsigned long F_33 ( void )
{
return V_13 . V_7 ;
}
unsigned long F_34 ( void )
{
return V_29 . V_7 ;
}
unsigned long F_35 ( void )
{
return V_28 -> V_6 ;
}
unsigned long F_36 ( void )
{
return V_13 . V_6 ;
}
unsigned long F_37 ( void )
{
return V_29 . V_6 ;
}
unsigned long F_38 ( void )
{
return V_28 -> V_30 ;
}
unsigned long F_39 ( void )
{
return V_13 . V_30 ;
}
void F_40 ( void )
{
F_41 ( V_28 ) ;
}
void F_42 ( void )
{
F_41 ( & V_29 ) ;
}
void F_43 ( void )
{
F_41 ( & V_13 ) ;
}
void F_44 ( void )
{
struct V_4 * V_5 ;
F_15 (rsp) {
F_45 ( L_6 ,
V_5 -> V_31 , V_5 -> V_32 , V_5 -> V_33 -> V_34 ) ;
}
}
void F_46 ( void )
{
V_35 ++ ;
V_36 = 0 ;
}
void F_47 ( enum V_37 V_38 , int * V_26 ,
unsigned long * V_7 , unsigned long * V_6 )
{
struct V_4 * V_5 = NULL ;
switch ( V_38 ) {
case V_39 :
V_5 = V_28 ;
break;
case V_40 :
V_5 = & V_29 ;
break;
case V_41 :
V_5 = & V_13 ;
break;
default:
break;
}
if ( V_5 != NULL ) {
* V_26 = F_2 ( V_5 -> V_42 ) ;
* V_7 = F_2 ( V_5 -> V_7 ) ;
* V_6 = F_2 ( V_5 -> V_6 ) ;
return;
}
* V_26 = 0 ;
* V_7 = 0 ;
* V_6 = 0 ;
}
void F_48 ( unsigned long V_43 )
{
V_36 ++ ;
}
static int
F_49 ( struct V_15 * V_16 )
{
return & V_16 -> V_44 != V_16 -> V_45 [ V_46 ] &&
V_16 -> V_45 [ V_46 ] != NULL ;
}
static struct V_1 * F_50 ( struct V_4 * V_5 )
{
return & V_5 -> V_47 [ 0 ] ;
}
static int F_51 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = F_50 ( V_5 ) ;
int V_48 = ( F_2 ( V_2 -> V_6 ) + 1 ) & 0x1 ;
int * V_49 = & V_2 -> V_50 [ V_48 ] ;
return F_2 ( * V_49 ) ;
}
static bool
F_52 ( struct V_4 * V_5 , struct V_15 * V_16 )
{
int V_51 ;
if ( F_3 ( V_5 ) )
return false ;
if ( F_51 ( V_5 ) )
return true ;
if ( ! V_16 -> V_45 [ V_52 ] )
return false ;
if ( * V_16 -> V_45 [ V_53 ] )
return true ;
for ( V_51 = V_54 ; V_51 < V_52 ; V_51 ++ )
if ( V_16 -> V_45 [ V_51 - 1 ] != V_16 -> V_45 [ V_51 ] &&
F_53 ( F_2 ( V_5 -> V_6 ) ,
V_16 -> V_55 [ V_51 ] ) )
return true ;
return false ;
}
static void F_54 ( long long V_56 , bool V_57 )
{
struct V_4 * V_5 ;
struct V_15 * V_16 ;
struct V_17 * V_18 = F_10 ( & V_17 ) ;
F_55 ( F_7 ( L_7 ) , V_56 , V_18 -> V_58 ) ;
if ( F_56 ( V_59 ) &&
! V_57 && ! F_57 ( V_60 ) ) {
struct V_61 * T_1 V_62 =
F_58 ( F_59 () ) ;
F_55 ( F_7 ( L_8 ) , V_56 , 0 ) ;
F_60 ( V_63 ) ;
F_61 ( 1 , L_9 ,
V_60 -> V_64 , V_60 -> V_65 ,
T_1 -> V_64 , T_1 -> V_65 ) ;
}
F_15 (rsp) {
V_16 = F_10 ( V_5 -> V_21 ) ;
F_62 ( V_16 ) ;
}
F_63 () ;
F_18 () ;
F_64 ( & V_18 -> V_25 ) ;
F_20 () ;
F_65 ( F_56 ( V_59 ) &&
F_66 ( & V_18 -> V_25 ) & 0x1 ) ;
F_67 () ;
F_68 ( F_69 ( & V_66 ) ,
L_10 ) ;
F_68 ( F_69 ( & V_67 ) ,
L_11 ) ;
F_68 ( F_69 ( & V_68 ) ,
L_12 ) ;
}
static void F_70 ( bool V_57 )
{
long long V_56 ;
struct V_17 * V_18 ;
V_18 = F_10 ( & V_17 ) ;
V_56 = V_18 -> V_58 ;
F_65 ( F_56 ( V_59 ) &&
( V_56 & V_69 ) == 0 ) ;
if ( ( V_56 & V_69 ) == V_70 ) {
V_18 -> V_58 = 0 ;
F_54 ( V_56 , V_57 ) ;
} else {
V_18 -> V_58 -= V_70 ;
}
}
void F_71 ( void )
{
unsigned long V_26 ;
F_27 ( V_26 ) ;
F_70 ( false ) ;
F_72 ( 0 ) ;
F_28 ( V_26 ) ;
}
void F_73 ( void )
{
F_70 ( 1 ) ;
}
void F_74 ( void )
{
long long V_56 ;
struct V_17 * V_18 ;
F_68 ( ! F_75 () , L_13 ) ;
V_18 = F_10 ( & V_17 ) ;
V_56 = V_18 -> V_58 ;
V_18 -> V_58 -- ;
F_65 ( F_56 ( V_59 ) &&
V_18 -> V_58 < 0 ) ;
if ( V_18 -> V_58 )
F_55 ( F_7 ( L_14 ) , V_56 , V_18 -> V_58 ) ;
else
F_54 ( V_56 , true ) ;
F_72 ( 1 ) ;
}
void F_76 ( void )
{
unsigned long V_26 ;
F_27 ( V_26 ) ;
F_74 () ;
F_28 ( V_26 ) ;
}
static void F_77 ( long long V_56 , int V_57 )
{
struct V_17 * V_18 = F_10 ( & V_17 ) ;
F_78 () ;
F_18 () ;
F_64 ( & V_18 -> V_25 ) ;
F_20 () ;
F_65 ( F_56 ( V_59 ) &&
! ( F_66 ( & V_18 -> V_25 ) & 0x1 ) ) ;
F_79 () ;
F_55 ( F_7 ( L_15 ) , V_56 , V_18 -> V_58 ) ;
if ( F_56 ( V_59 ) &&
! V_57 && ! F_57 ( V_60 ) ) {
struct V_61 * T_1 V_62 =
F_58 ( F_59 () ) ;
F_55 ( F_7 ( L_16 ) ,
V_56 , V_18 -> V_58 ) ;
F_60 ( V_63 ) ;
F_61 ( 1 , L_9 ,
V_60 -> V_64 , V_60 -> V_65 ,
T_1 -> V_64 , T_1 -> V_65 ) ;
}
}
static void F_80 ( bool V_57 )
{
struct V_17 * V_18 ;
long long V_56 ;
V_18 = F_10 ( & V_17 ) ;
V_56 = V_18 -> V_58 ;
F_65 ( F_56 ( V_59 ) && V_56 < 0 ) ;
if ( V_56 & V_69 ) {
V_18 -> V_58 += V_70 ;
} else {
V_18 -> V_58 = V_71 ;
F_77 ( V_56 , V_57 ) ;
}
}
void F_81 ( void )
{
unsigned long V_26 ;
F_27 ( V_26 ) ;
F_80 ( false ) ;
F_82 ( 0 ) ;
F_28 ( V_26 ) ;
}
void F_83 ( void )
{
F_80 ( 1 ) ;
}
void F_84 ( void )
{
struct V_17 * V_18 ;
long long V_56 ;
F_68 ( ! F_75 () , L_17 ) ;
V_18 = F_10 ( & V_17 ) ;
V_56 = V_18 -> V_58 ;
V_18 -> V_58 ++ ;
F_65 ( F_56 ( V_59 ) &&
V_18 -> V_58 == 0 ) ;
if ( V_56 )
F_55 ( F_7 ( L_18 ) , V_56 , V_18 -> V_58 ) ;
else
F_77 ( V_56 , true ) ;
F_82 ( 1 ) ;
}
void F_85 ( void )
{
unsigned long V_26 ;
F_27 ( V_26 ) ;
F_84 () ;
F_28 ( V_26 ) ;
}
void F_86 ( void )
{
struct V_17 * V_18 = F_10 ( & V_17 ) ;
int V_72 = 2 ;
F_65 ( V_18 -> V_73 < 0 ) ;
if ( ! ( F_66 ( & V_18 -> V_25 ) & 0x1 ) ) {
F_18 () ;
F_64 ( & V_18 -> V_25 ) ;
F_20 () ;
F_65 ( ! ( F_66 ( & V_18 -> V_25 ) & 0x1 ) ) ;
V_72 = 1 ;
}
V_18 -> V_73 += V_72 ;
F_22 () ;
}
void F_87 ( void )
{
struct V_17 * V_18 = F_10 ( & V_17 ) ;
F_65 ( V_18 -> V_73 <= 0 ) ;
F_65 ( ! ( F_66 ( & V_18 -> V_25 ) & 0x1 ) ) ;
if ( V_18 -> V_73 != 1 ) {
V_18 -> V_73 -= 2 ;
return;
}
V_18 -> V_73 = 0 ;
F_18 () ;
F_64 ( & V_18 -> V_25 ) ;
F_20 () ;
F_65 ( F_66 ( & V_18 -> V_25 ) & 0x1 ) ;
}
bool T_2 F_88 ( void )
{
return F_66 ( F_10 ( & V_17 . V_25 ) ) & 0x1 ;
}
bool T_2 F_89 ( void )
{
bool V_74 ;
F_90 () ;
V_74 = F_88 () ;
F_91 () ;
return V_74 ;
}
bool F_92 ( void )
{
struct V_15 * V_16 ;
struct V_1 * V_2 ;
bool V_74 ;
if ( F_93 () )
return true ;
F_29 () ;
V_16 = F_10 ( & V_8 ) ;
V_2 = V_16 -> V_23 ;
V_74 = ( V_16 -> V_75 & F_1 ( V_2 ) ) ||
! V_76 ;
F_30 () ;
return V_74 ;
}
static int F_94 ( void )
{
return F_5 ( V_17 . V_58 ) <= 1 ;
}
static int F_95 ( struct V_15 * V_16 ,
bool * V_77 , unsigned long * V_78 )
{
V_16 -> V_79 = F_96 ( 0 , & V_16 -> V_25 -> V_25 ) ;
F_97 ( V_16 , V_77 , V_78 ) ;
if ( ( V_16 -> V_79 & 0x1 ) == 0 ) {
F_98 ( V_16 -> V_5 -> V_31 , V_16 -> V_7 , V_16 -> V_80 , F_7 ( L_19 ) ) ;
if ( F_53 ( F_2 ( V_16 -> V_7 ) + V_81 / 4 ,
V_16 -> V_23 -> V_7 ) )
F_99 ( V_16 -> V_82 , true ) ;
return 1 ;
}
return 0 ;
}
static int F_100 ( struct V_15 * V_16 ,
bool * V_77 , unsigned long * V_78 )
{
unsigned int V_83 ;
int * V_84 ;
unsigned int V_85 ;
V_83 = ( unsigned int ) F_96 ( 0 , & V_16 -> V_25 -> V_25 ) ;
V_85 = ( unsigned int ) V_16 -> V_79 ;
if ( ( V_83 & 0x1 ) == 0 || F_101 ( V_83 , V_85 + 2 ) ) {
F_98 ( V_16 -> V_5 -> V_31 , V_16 -> V_7 , V_16 -> V_80 , F_7 ( L_19 ) ) ;
V_16 -> V_86 ++ ;
return 1 ;
}
if ( F_102 ( V_16 -> V_5 -> V_87 + 2 , V_88 ) )
return 0 ;
F_22 () ;
if ( F_103 ( V_16 -> V_80 ) ) {
F_98 ( V_16 -> V_5 -> V_31 , V_16 -> V_7 , V_16 -> V_80 , F_7 ( L_20 ) ) ;
V_16 -> V_89 ++ ;
return 1 ;
}
V_84 = & F_104 ( V_20 , V_16 -> V_80 ) ;
if ( F_102 ( V_88 ,
V_16 -> V_5 -> V_87 + V_90 ) ||
F_102 ( V_88 , V_16 -> V_5 -> V_91 ) ) {
if ( ! ( F_2 ( * V_84 ) & V_16 -> V_5 -> V_22 ) ) {
F_99 ( V_16 -> V_24 ,
F_2 ( V_16 -> V_23 -> V_6 ) ) ;
F_17 () ;
F_99 ( * V_84 ,
F_2 ( * V_84 ) + V_16 -> V_5 -> V_22 ) ;
}
V_16 -> V_5 -> V_91 += 5 ;
}
if ( F_102 ( V_88 ,
V_16 -> V_5 -> V_87 + 2 * V_90 ) ||
F_102 ( V_88 , V_16 -> V_5 -> V_87 + V_90 ) )
F_105 ( V_16 -> V_80 ) ;
return 0 ;
}
static void F_106 ( struct V_4 * V_5 )
{
unsigned long V_92 = V_88 ;
unsigned long j1 ;
V_5 -> V_87 = V_92 ;
F_107 () ;
j1 = F_108 () ;
F_99 ( V_5 -> V_93 , V_92 + j1 ) ;
V_5 -> V_91 = V_92 + j1 / 2 ;
V_5 -> V_94 = F_2 ( V_5 -> V_95 ) ;
}
static const char * F_109 ( short V_96 )
{
if ( V_96 < 0 || V_96 >= F_110 ( V_97 ) )
return L_21 ;
return V_97 [ V_96 ] ;
}
static void F_111 ( struct V_4 * V_5 )
{
unsigned long V_98 ;
unsigned long V_92 ;
V_92 = V_88 ;
V_98 = F_2 ( V_5 -> V_99 ) ;
if ( V_92 - V_98 > 2 * V_100 ) {
F_112 ( L_22 ,
V_5 -> V_31 , V_92 - V_98 ,
V_5 -> V_7 , V_5 -> V_6 ,
V_5 -> V_42 ,
F_109 ( V_5 -> V_32 ) , V_5 -> V_32 ,
V_5 -> V_33 ? V_5 -> V_33 -> V_34 : ~ 0 ) ;
if ( V_5 -> V_33 ) {
F_113 ( V_5 -> V_33 ) ;
F_114 ( V_5 -> V_33 ) ;
}
}
}
static void F_115 ( struct V_4 * V_5 )
{
int V_80 ;
unsigned long V_26 ;
struct V_1 * V_2 ;
F_116 (rsp, rnp) {
F_117 ( V_2 , V_26 ) ;
if ( V_2 -> V_101 != 0 ) {
F_118 (rnp, cpu)
if ( V_2 -> V_101 & F_119 ( V_2 , V_80 ) )
F_120 ( V_80 ) ;
}
F_121 ( V_2 , V_26 ) ;
}
}
static void F_122 ( struct V_4 * V_5 )
{
unsigned long V_92 ;
if ( ! V_102 )
return;
V_92 = F_2 ( V_5 -> V_103 ) ;
if ( F_123 ( V_88 , V_92 ) && V_5 -> V_33 ) {
F_61 ( 1 , L_23 , V_5 -> V_31 ) ;
F_60 ( V_104 ) ;
F_114 ( V_5 -> V_33 ) ;
F_99 ( V_5 -> V_103 , V_92 + V_100 ) ;
}
}
static inline void F_124 ( void )
{
if ( V_105 )
F_125 ( L_24 ) ;
}
static void F_126 ( struct V_4 * V_5 , unsigned long V_7 )
{
int V_80 ;
long V_106 ;
unsigned long V_26 ;
unsigned long V_98 ;
unsigned long V_92 ;
int V_107 = 0 ;
struct V_1 * V_2 = F_50 ( V_5 ) ;
long V_108 = 0 ;
F_122 ( V_5 ) ;
if ( V_109 )
return;
F_117 ( V_2 , V_26 ) ;
V_106 = V_88 - F_2 ( V_5 -> V_93 ) ;
if ( V_106 < V_110 || ! F_3 ( V_5 ) ) {
F_121 ( V_2 , V_26 ) ;
return;
}
F_99 ( V_5 -> V_93 ,
V_88 + 3 * F_108 () + 3 ) ;
F_121 ( V_2 , V_26 ) ;
F_112 ( L_25 ,
V_5 -> V_31 ) ;
F_127 () ;
F_116 (rsp, rnp) {
F_117 ( V_2 , V_26 ) ;
V_107 += F_128 ( V_2 ) ;
if ( V_2 -> V_101 != 0 ) {
F_118 (rnp, cpu)
if ( V_2 -> V_101 & F_119 ( V_2 , V_80 ) ) {
F_129 ( V_5 , V_80 ) ;
V_107 ++ ;
}
}
F_121 ( V_2 , V_26 ) ;
}
F_130 () ;
F_131 (cpu)
V_108 += F_132 ( V_5 -> V_21 , V_80 ) -> V_111 ;
F_133 ( L_26 ,
F_59 () , ( long ) ( V_88 - V_5 -> V_87 ) ,
( long ) V_5 -> V_7 , ( long ) V_5 -> V_6 , V_108 ) ;
if ( V_107 ) {
F_115 ( V_5 ) ;
} else {
if ( F_2 ( V_5 -> V_7 ) != V_7 ||
F_2 ( V_5 -> V_6 ) == V_7 ) {
F_112 ( L_27 ) ;
} else {
V_92 = V_88 ;
V_98 = F_2 ( V_5 -> V_99 ) ;
F_112 ( L_28 ,
V_5 -> V_31 , V_92 - V_98 , V_92 , V_98 ,
V_112 ,
F_50 ( V_5 ) -> V_101 ) ;
F_113 ( V_60 ) ;
}
}
F_134 ( V_5 ) ;
F_111 ( V_5 ) ;
F_124 () ;
F_41 ( V_5 ) ;
}
static void F_135 ( struct V_4 * V_5 )
{
int V_80 ;
unsigned long V_26 ;
struct V_1 * V_2 = F_50 ( V_5 ) ;
long V_108 = 0 ;
F_122 ( V_5 ) ;
if ( V_109 )
return;
F_112 ( L_29 , V_5 -> V_31 ) ;
F_127 () ;
F_129 ( V_5 , F_59 () ) ;
F_130 () ;
F_131 (cpu)
V_108 += F_132 ( V_5 -> V_21 , V_80 ) -> V_111 ;
F_133 ( L_30 ,
V_88 - V_5 -> V_87 ,
( long ) V_5 -> V_7 , ( long ) V_5 -> V_6 , V_108 ) ;
F_111 ( V_5 ) ;
F_115 ( V_5 ) ;
F_117 ( V_2 , V_26 ) ;
if ( F_102 ( V_88 , F_2 ( V_5 -> V_93 ) ) )
F_99 ( V_5 -> V_93 ,
V_88 + 3 * F_108 () + 3 ) ;
F_121 ( V_2 , V_26 ) ;
F_124 () ;
F_105 ( F_59 () ) ;
}
static void F_136 ( struct V_4 * V_5 , struct V_15 * V_16 )
{
unsigned long V_6 ;
unsigned long V_7 ;
unsigned long V_113 ;
unsigned long V_92 ;
unsigned long V_114 ;
struct V_1 * V_2 ;
if ( ( V_109 && ! V_102 ) ||
! F_3 ( V_5 ) )
return;
F_122 ( V_5 ) ;
V_92 = V_88 ;
V_7 = F_2 ( V_5 -> V_7 ) ;
F_137 () ;
V_114 = F_2 ( V_5 -> V_93 ) ;
F_137 () ;
V_113 = F_2 ( V_5 -> V_87 ) ;
F_137 () ;
V_6 = F_2 ( V_5 -> V_6 ) ;
if ( F_102 ( V_6 , V_7 ) ||
F_53 ( V_92 , V_114 ) ||
F_102 ( V_113 , V_114 ) )
return;
V_2 = V_16 -> V_23 ;
if ( F_3 ( V_5 ) &&
( F_2 ( V_2 -> V_101 ) & V_16 -> V_75 ) ) {
F_135 ( V_5 ) ;
} else if ( F_3 ( V_5 ) &&
F_102 ( V_92 , V_114 + V_110 ) ) {
F_126 ( V_5 , V_7 ) ;
}
}
void F_138 ( void )
{
struct V_4 * V_5 ;
F_15 (rsp)
F_99 ( V_5 -> V_93 , V_88 + V_81 / 2 ) ;
}
static void F_139 ( struct V_15 * V_16 )
{
int V_51 ;
V_16 -> V_44 = NULL ;
for ( V_51 = 0 ; V_51 < V_115 ; V_51 ++ )
V_16 -> V_45 [ V_51 ] = & V_16 -> V_44 ;
}
static void F_140 ( struct V_15 * V_16 )
{
if ( F_141 ( V_16 ) )
return;
F_139 ( V_16 ) ;
}
static unsigned long F_142 ( struct V_4 * V_5 ,
struct V_1 * V_2 )
{
if ( F_50 ( V_5 ) == V_2 && V_2 -> V_7 == V_2 -> V_6 )
return V_2 -> V_6 + 1 ;
return V_2 -> V_6 + 2 ;
}
static void F_143 ( struct V_1 * V_2 , struct V_15 * V_16 ,
unsigned long V_116 , const char * V_10 )
{
F_144 ( V_16 -> V_5 -> V_31 , V_2 -> V_7 ,
V_2 -> V_6 , V_116 , V_2 -> V_117 ,
V_2 -> V_118 , V_2 -> V_119 , V_10 ) ;
}
static bool V_62
F_145 ( struct V_1 * V_2 , struct V_15 * V_16 ,
unsigned long * V_120 )
{
unsigned long V_116 ;
int V_51 ;
bool V_74 = false ;
struct V_1 * V_121 = F_50 ( V_16 -> V_5 ) ;
V_116 = F_142 ( V_16 -> V_5 , V_2 ) ;
F_143 ( V_2 , V_16 , V_116 , F_7 ( L_31 ) ) ;
if ( V_2 -> V_50 [ V_116 & 0x1 ] ) {
F_143 ( V_2 , V_16 , V_116 , F_7 ( L_32 ) ) ;
goto V_122;
}
if ( V_2 -> V_7 != V_2 -> V_6 ||
F_2 ( V_121 -> V_7 ) != F_2 ( V_121 -> V_6 ) ) {
V_2 -> V_50 [ V_116 & 0x1 ] ++ ;
F_143 ( V_2 , V_16 , V_116 , F_7 ( L_33 ) ) ;
goto V_122;
}
if ( V_2 != V_121 )
F_146 ( V_121 ) ;
V_116 = F_142 ( V_16 -> V_5 , V_121 ) ;
for ( V_51 = V_46 ; V_51 < V_52 ; V_51 ++ )
if ( F_53 ( V_116 , V_16 -> V_55 [ V_51 ] ) )
V_16 -> V_55 [ V_51 ] = V_116 ;
if ( V_121 -> V_50 [ V_116 & 0x1 ] ) {
F_143 ( V_2 , V_16 , V_116 , F_7 ( L_34 ) ) ;
goto V_123;
}
V_121 -> V_50 [ V_116 & 0x1 ] ++ ;
if ( V_121 -> V_7 != V_121 -> V_6 ) {
F_143 ( V_2 , V_16 , V_116 , F_7 ( L_35 ) ) ;
} else {
F_143 ( V_2 , V_16 , V_116 , F_7 ( L_36 ) ) ;
V_74 = F_147 ( V_16 -> V_5 , V_121 , V_16 ) ;
}
V_123:
if ( V_2 != V_121 )
F_148 ( V_121 ) ;
V_122:
if ( V_120 != NULL )
* V_120 = V_116 ;
return V_74 ;
}
static int F_149 ( struct V_4 * V_5 , struct V_1 * V_2 )
{
int V_116 = V_2 -> V_6 ;
int V_124 ;
struct V_15 * V_16 = F_10 ( V_5 -> V_21 ) ;
V_2 -> V_50 [ V_116 & 0x1 ] = 0 ;
V_124 = V_2 -> V_50 [ ( V_116 + 1 ) & 0x1 ] ;
F_143 ( V_2 , V_16 , V_116 ,
V_124 ? F_7 ( L_37 ) : F_7 ( L_38 ) ) ;
return V_124 ;
}
static void F_150 ( struct V_4 * V_5 )
{
if ( V_60 == V_5 -> V_33 ||
! F_2 ( V_5 -> V_42 ) ||
! V_5 -> V_33 )
return;
F_151 ( & V_5 -> V_125 ) ;
}
static bool F_152 ( struct V_4 * V_5 , struct V_1 * V_2 ,
struct V_15 * V_16 )
{
unsigned long V_116 ;
int V_51 ;
bool V_74 ;
if ( ! V_16 -> V_45 [ V_52 ] || ! * V_16 -> V_45 [ V_46 ] )
return false ;
V_116 = F_142 ( V_5 , V_2 ) ;
for ( V_51 = V_52 - 1 ; V_51 > V_46 ; V_51 -- )
if ( V_16 -> V_45 [ V_51 ] != V_16 -> V_45 [ V_51 - 1 ] &&
! F_102 ( V_16 -> V_55 [ V_51 ] , V_116 ) )
break;
if ( ++ V_51 >= V_52 )
return false ;
for (; V_51 <= V_52 ; V_51 ++ ) {
V_16 -> V_45 [ V_51 ] = V_16 -> V_45 [ V_52 ] ;
V_16 -> V_55 [ V_51 ] = V_116 ;
}
V_74 = F_145 ( V_2 , V_16 , NULL ) ;
if ( ! * V_16 -> V_45 [ V_54 ] )
F_6 ( V_5 -> V_31 , V_16 -> V_7 , F_7 ( L_39 ) ) ;
else
F_6 ( V_5 -> V_31 , V_16 -> V_7 , F_7 ( L_40 ) ) ;
return V_74 ;
}
static bool F_153 ( struct V_4 * V_5 , struct V_1 * V_2 ,
struct V_15 * V_16 )
{
int V_51 , V_92 ;
if ( ! V_16 -> V_45 [ V_52 ] || ! * V_16 -> V_45 [ V_46 ] )
return false ;
for ( V_51 = V_54 ; V_51 < V_52 ; V_51 ++ ) {
if ( F_53 ( V_2 -> V_6 , V_16 -> V_55 [ V_51 ] ) )
break;
V_16 -> V_45 [ V_46 ] = V_16 -> V_45 [ V_51 ] ;
}
for ( V_92 = V_54 ; V_92 < V_51 ; V_92 ++ )
V_16 -> V_45 [ V_92 ] = V_16 -> V_45 [ V_46 ] ;
for ( V_92 = V_54 ; V_51 < V_52 ; V_51 ++ , V_92 ++ ) {
if ( V_16 -> V_45 [ V_92 ] == V_16 -> V_45 [ V_52 ] )
break;
V_16 -> V_45 [ V_92 ] = V_16 -> V_45 [ V_51 ] ;
V_16 -> V_55 [ V_92 ] = V_16 -> V_55 [ V_51 ] ;
}
return F_152 ( V_5 , V_2 , V_16 ) ;
}
static bool F_154 ( struct V_4 * V_5 , struct V_1 * V_2 ,
struct V_15 * V_16 )
{
bool V_74 ;
bool V_126 ;
if ( V_16 -> V_6 == V_2 -> V_6 &&
! F_25 ( F_2 ( V_16 -> V_82 ) ) ) {
V_74 = F_152 ( V_5 , V_2 , V_16 ) ;
} else {
V_74 = F_153 ( V_5 , V_2 , V_16 ) ;
V_16 -> V_6 = V_2 -> V_6 ;
F_6 ( V_5 -> V_31 , V_16 -> V_7 , F_7 ( L_41 ) ) ;
}
if ( V_16 -> V_7 != V_2 -> V_7 || F_25 ( F_2 ( V_16 -> V_82 ) ) ) {
V_16 -> V_7 = V_2 -> V_7 ;
F_6 ( V_5 -> V_31 , V_16 -> V_7 , F_7 ( L_42 ) ) ;
V_126 = ! ! ( V_2 -> V_101 & V_16 -> V_75 ) ;
V_16 -> V_9 . V_11 . V_12 = V_126 ;
V_16 -> V_127 = F_5 ( V_27 ) ;
V_16 -> V_128 = V_126 ;
F_155 ( V_16 ) ;
F_99 ( V_16 -> V_82 , false ) ;
}
return V_74 ;
}
static void F_156 ( struct V_4 * V_5 , struct V_15 * V_16 )
{
unsigned long V_26 ;
bool V_129 ;
struct V_1 * V_2 ;
F_27 ( V_26 ) ;
V_2 = V_16 -> V_23 ;
if ( ( V_16 -> V_7 == F_2 ( V_2 -> V_7 ) &&
V_16 -> V_6 == F_2 ( V_2 -> V_6 ) &&
! F_25 ( F_2 ( V_16 -> V_82 ) ) ) ||
! F_157 ( V_2 ) ) {
F_28 ( V_26 ) ;
return;
}
V_129 = F_154 ( V_5 , V_2 , V_16 ) ;
F_121 ( V_2 , V_26 ) ;
if ( V_129 )
F_150 ( V_5 ) ;
}
static void F_158 ( struct V_4 * V_5 , int V_130 )
{
if ( V_130 > 0 &&
! ( V_5 -> V_7 % ( V_131 * V_132 * V_130 ) ) )
F_159 ( V_130 ) ;
}
static bool F_160 ( struct V_4 * V_5 )
{
unsigned long V_133 ;
struct V_15 * V_16 ;
struct V_1 * V_2 = F_50 ( V_5 ) ;
F_99 ( V_5 -> V_99 , V_88 ) ;
F_161 ( V_2 ) ;
if ( ! F_2 ( V_5 -> V_42 ) ) {
F_162 ( V_2 ) ;
return false ;
}
F_99 ( V_5 -> V_42 , 0 ) ;
if ( F_65 ( F_3 ( V_5 ) ) ) {
F_162 ( V_2 ) ;
return false ;
}
F_106 ( V_5 ) ;
F_163 ( & V_5 -> V_7 , V_5 -> V_7 + 1 ) ;
F_6 ( V_5 -> V_31 , V_5 -> V_7 , F_7 ( L_43 ) ) ;
F_162 ( V_2 ) ;
F_116 (rsp, rnp) {
F_158 ( V_5 , V_134 ) ;
F_161 ( V_2 ) ;
if ( V_2 -> V_135 == V_2 -> V_3 &&
! V_2 -> V_136 ) {
F_162 ( V_2 ) ;
continue;
}
V_133 = V_2 -> V_135 ;
V_2 -> V_135 = V_2 -> V_3 ;
if ( ! V_133 != ! V_2 -> V_135 ) {
if ( ! V_133 )
F_164 ( V_2 ) ;
else if ( F_165 ( V_2 ) )
V_2 -> V_136 = true ;
else
F_166 ( V_2 ) ;
}
if ( V_2 -> V_136 &&
( ! F_165 ( V_2 ) ||
V_2 -> V_135 ) ) {
V_2 -> V_136 = false ;
F_166 ( V_2 ) ;
}
F_162 ( V_2 ) ;
}
F_167 (rsp, rnp) {
F_158 ( V_5 , V_137 ) ;
F_161 ( V_2 ) ;
V_16 = F_10 ( V_5 -> V_21 ) ;
F_168 ( V_2 ) ;
V_2 -> V_101 = V_2 -> V_135 ;
F_99 ( V_2 -> V_7 , V_5 -> V_7 ) ;
if ( F_65 ( V_2 -> V_6 != V_5 -> V_6 ) )
F_99 ( V_2 -> V_6 , V_5 -> V_6 ) ;
if ( V_2 == V_16 -> V_23 )
( void ) F_154 ( V_5 , V_2 , V_16 ) ;
F_169 ( V_2 ) ;
F_170 ( V_5 -> V_31 , V_2 -> V_7 ,
V_2 -> V_117 , V_2 -> V_118 ,
V_2 -> V_119 , V_2 -> V_101 ) ;
F_162 ( V_2 ) ;
F_171 () ;
F_99 ( V_5 -> V_99 , V_88 ) ;
}
return true ;
}
static bool F_172 ( struct V_4 * V_5 , int * V_138 )
{
struct V_1 * V_2 = F_50 ( V_5 ) ;
* V_138 = F_2 ( V_5 -> V_42 ) ;
if ( * V_138 & V_139 )
return true ;
if ( ! F_2 ( V_2 -> V_101 ) && ! F_173 ( V_2 ) )
return true ;
return false ;
}
static void F_174 ( struct V_4 * V_5 , bool V_140 )
{
bool V_77 = false ;
unsigned long V_78 ;
struct V_1 * V_2 = F_50 ( V_5 ) ;
F_99 ( V_5 -> V_99 , V_88 ) ;
V_5 -> V_95 ++ ;
if ( V_140 ) {
if ( F_175 ( V_5 ) ) {
V_77 = true ;
V_78 = V_88 - V_81 / 4 ;
}
F_176 ( V_5 , F_95 ,
& V_77 , & V_78 ) ;
F_177 ( V_5 , V_77 , V_78 ) ;
} else {
V_77 = true ;
F_176 ( V_5 , F_100 , & V_77 , & V_78 ) ;
}
if ( F_2 ( V_5 -> V_42 ) & V_139 ) {
F_161 ( V_2 ) ;
F_99 ( V_5 -> V_42 ,
F_2 ( V_5 -> V_42 ) & ~ V_139 ) ;
F_162 ( V_2 ) ;
}
}
static void F_178 ( struct V_4 * V_5 )
{
unsigned long V_141 ;
bool V_142 = false ;
int V_143 = 0 ;
struct V_15 * V_16 ;
struct V_1 * V_2 = F_50 ( V_5 ) ;
struct V_144 * V_145 ;
F_99 ( V_5 -> V_99 , V_88 ) ;
F_161 ( V_2 ) ;
V_141 = V_88 - V_5 -> V_87 ;
if ( V_141 > V_5 -> V_146 )
V_5 -> V_146 = V_141 ;
F_162 ( V_2 ) ;
F_167 (rsp, rnp) {
F_161 ( V_2 ) ;
F_65 ( F_173 ( V_2 ) ) ;
F_65 ( V_2 -> V_101 ) ;
F_99 ( V_2 -> V_6 , V_5 -> V_7 ) ;
V_16 = F_10 ( V_5 -> V_21 ) ;
if ( V_2 == V_16 -> V_23 )
V_142 = F_154 ( V_5 , V_2 , V_16 ) || V_142 ;
V_143 += F_149 ( V_5 , V_2 ) ;
V_145 = F_179 ( V_2 ) ;
F_162 ( V_2 ) ;
F_180 ( V_145 ) ;
F_171 () ;
F_99 ( V_5 -> V_99 , V_88 ) ;
F_158 ( V_5 , V_147 ) ;
}
V_2 = F_50 ( V_5 ) ;
F_161 ( V_2 ) ;
F_181 ( V_2 , V_143 ) ;
F_99 ( V_5 -> V_6 , V_5 -> V_7 ) ;
F_6 ( V_5 -> V_31 , V_5 -> V_6 , F_7 ( L_44 ) ) ;
V_5 -> V_32 = V_148 ;
V_16 = F_10 ( V_5 -> V_21 ) ;
V_142 = F_153 ( V_5 , V_2 , V_16 ) || V_142 ;
if ( V_142 || F_52 ( V_5 , V_16 ) ) {
F_99 ( V_5 -> V_42 , V_149 ) ;
F_6 ( V_5 -> V_31 ,
F_2 ( V_5 -> V_7 ) ,
F_7 ( L_45 ) ) ;
}
F_162 ( V_2 ) ;
}
static int T_3 F_182 ( void * V_150 )
{
bool V_151 ;
int V_152 ;
unsigned long V_92 ;
int V_74 ;
struct V_4 * V_5 = V_150 ;
struct V_1 * V_2 = F_50 ( V_5 ) ;
F_183 () ;
for (; ; ) {
for (; ; ) {
F_6 ( V_5 -> V_31 ,
F_2 ( V_5 -> V_7 ) ,
F_7 ( L_46 ) ) ;
V_5 -> V_32 = V_153 ;
F_184 ( V_5 -> V_125 ,
F_2 ( V_5 -> V_42 ) &
V_149 ) ;
V_5 -> V_32 = V_154 ;
if ( F_160 ( V_5 ) )
break;
F_171 () ;
F_99 ( V_5 -> V_99 , V_88 ) ;
F_185 ( F_186 ( V_60 ) ) ;
F_6 ( V_5 -> V_31 ,
F_2 ( V_5 -> V_7 ) ,
F_7 ( L_47 ) ) ;
}
V_151 = true ;
V_92 = V_155 ;
if ( V_92 > V_100 ) {
V_92 = V_100 ;
V_155 = V_100 ;
}
V_74 = 0 ;
for (; ; ) {
if ( ! V_74 ) {
V_5 -> V_156 = V_88 + V_92 ;
F_99 ( V_5 -> V_103 ,
V_88 + 3 * V_92 ) ;
}
F_6 ( V_5 -> V_31 ,
F_2 ( V_5 -> V_7 ) ,
F_7 ( L_48 ) ) ;
V_5 -> V_32 = V_157 ;
V_74 = F_187 ( V_5 -> V_125 ,
F_172 ( V_5 , & V_152 ) , V_92 ) ;
V_5 -> V_32 = V_158 ;
if ( ! F_2 ( V_2 -> V_101 ) &&
! F_173 ( V_2 ) )
break;
if ( F_102 ( V_88 , V_5 -> V_156 ) ||
( V_152 & V_139 ) ) {
F_6 ( V_5 -> V_31 ,
F_2 ( V_5 -> V_7 ) ,
F_7 ( L_49 ) ) ;
F_174 ( V_5 , V_151 ) ;
V_151 = false ;
F_6 ( V_5 -> V_31 ,
F_2 ( V_5 -> V_7 ) ,
F_7 ( L_50 ) ) ;
F_171 () ;
F_99 ( V_5 -> V_99 , V_88 ) ;
V_74 = 0 ;
V_92 = V_112 ;
if ( V_92 > V_100 ) {
V_92 = V_100 ;
V_112 = V_100 ;
} else if ( V_92 < 1 ) {
V_92 = 1 ;
V_112 = 1 ;
}
} else {
F_171 () ;
F_99 ( V_5 -> V_99 , V_88 ) ;
F_185 ( F_186 ( V_60 ) ) ;
F_6 ( V_5 -> V_31 ,
F_2 ( V_5 -> V_7 ) ,
F_7 ( L_51 ) ) ;
V_74 = 1 ;
V_92 = V_88 ;
if ( F_123 ( V_88 , V_5 -> V_156 ) )
V_92 = 1 ;
else
V_92 = V_5 -> V_156 - V_92 ;
}
}
V_5 -> V_32 = V_159 ;
F_178 ( V_5 ) ;
V_5 -> V_32 = V_160 ;
}
}
static bool
F_147 ( struct V_4 * V_5 , struct V_1 * V_2 ,
struct V_15 * V_16 )
{
if ( ! V_5 -> V_33 || ! F_52 ( V_5 , V_16 ) ) {
return false ;
}
F_99 ( V_5 -> V_42 , V_149 ) ;
F_6 ( V_5 -> V_31 , F_2 ( V_5 -> V_7 ) ,
F_7 ( L_45 ) ) ;
return true ;
}
static bool F_188 ( struct V_4 * V_5 )
{
struct V_15 * V_16 = F_10 ( V_5 -> V_21 ) ;
struct V_1 * V_2 = F_50 ( V_5 ) ;
bool V_74 = false ;
V_74 = F_153 ( V_5 , V_2 , V_16 ) || V_74 ;
V_74 = F_147 ( V_5 , V_2 , V_16 ) || V_74 ;
return V_74 ;
}
static void F_189 ( struct V_4 * V_5 , unsigned long V_26 )
__releases( rcu_get_root( V_5 )->lock
static void
F_190 ( unsigned long V_161 , struct V_4 * V_5 ,
struct V_1 * V_2 , unsigned long V_113 , unsigned long V_26 )
__releases( V_2 -> V_162 )
{
unsigned long V_133 = 0 ;
struct V_1 * V_163 ;
for (; ; ) {
if ( ! ( V_2 -> V_101 & V_161 ) || V_2 -> V_7 != V_113 ) {
F_121 ( V_2 , V_26 ) ;
return;
}
F_65 ( V_133 ) ;
V_2 -> V_101 &= ~ V_161 ;
F_191 ( V_5 -> V_31 , V_2 -> V_7 ,
V_161 , V_2 -> V_101 , V_2 -> V_117 ,
V_2 -> V_118 , V_2 -> V_119 ,
! ! V_2 -> V_164 ) ;
if ( V_2 -> V_101 != 0 || F_173 ( V_2 ) ) {
F_121 ( V_2 , V_26 ) ;
return;
}
V_161 = V_2 -> V_75 ;
if ( V_2 -> V_165 == NULL ) {
break;
}
F_121 ( V_2 , V_26 ) ;
V_163 = V_2 ;
V_2 = V_2 -> V_165 ;
F_117 ( V_2 , V_26 ) ;
V_133 = V_163 -> V_101 ;
}
F_189 ( V_5 , V_26 ) ;
}
static void F_192 ( struct V_4 * V_5 ,
struct V_1 * V_2 , unsigned long V_26 )
__releases( V_2 -> V_162 )
{
unsigned long V_113 ;
unsigned long V_161 ;
struct V_1 * V_166 ;
if ( V_28 == & V_13 || V_5 != V_28 ||
V_2 -> V_101 != 0 || F_173 ( V_2 ) ) {
F_121 ( V_2 , V_26 ) ;
return;
}
V_166 = V_2 -> V_165 ;
if ( V_166 == NULL ) {
F_189 ( V_5 , V_26 ) ;
return;
}
V_113 = V_2 -> V_7 ;
V_161 = V_2 -> V_75 ;
F_148 ( V_2 ) ;
F_146 ( V_166 ) ;
F_190 ( V_161 , V_5 , V_166 , V_113 , V_26 ) ;
}
static void
F_193 ( int V_80 , struct V_4 * V_5 , struct V_15 * V_16 )
{
unsigned long V_26 ;
unsigned long V_161 ;
bool V_129 ;
struct V_1 * V_2 ;
V_2 = V_16 -> V_23 ;
F_117 ( V_2 , V_26 ) ;
if ( ( V_16 -> V_9 . V_11 . V_12 &&
V_16 -> V_127 == F_5 ( V_27 ) ) ||
V_16 -> V_7 != V_2 -> V_7 || V_2 -> V_6 == V_2 -> V_7 ||
V_16 -> V_82 ) {
V_16 -> V_9 . V_11 . V_12 = true ;
V_16 -> V_127 = F_5 ( V_27 ) ;
F_121 ( V_2 , V_26 ) ;
return;
}
V_161 = V_16 -> V_75 ;
if ( ( V_2 -> V_101 & V_161 ) == 0 ) {
F_121 ( V_2 , V_26 ) ;
} else {
V_16 -> V_128 = false ;
V_129 = F_152 ( V_5 , V_2 , V_16 ) ;
F_190 ( V_161 , V_5 , V_2 , V_2 -> V_7 , V_26 ) ;
if ( V_129 )
F_150 ( V_5 ) ;
}
}
static void
F_194 ( struct V_4 * V_5 , struct V_15 * V_16 )
{
F_156 ( V_5 , V_16 ) ;
if ( ! V_16 -> V_128 )
return;
if ( V_16 -> V_9 . V_11 . V_12 &&
V_16 -> V_127 == F_5 ( V_27 ) )
return;
F_193 ( V_16 -> V_80 , V_5 , V_16 ) ;
}
static void
F_195 ( int V_80 , struct V_4 * V_5 ,
struct V_1 * V_2 , struct V_15 * V_16 )
{
if ( ! F_56 ( V_167 ) || F_196 ( V_16 -> V_80 ) )
return;
if ( V_16 -> V_44 != NULL ) {
V_5 -> V_168 += V_16 -> V_168 ;
V_5 -> V_111 += V_16 -> V_111 ;
V_16 -> V_169 += V_16 -> V_111 ;
V_16 -> V_168 = 0 ;
F_99 ( V_16 -> V_111 , 0 ) ;
}
if ( * V_16 -> V_45 [ V_46 ] != NULL ) {
* V_5 -> V_170 = * V_16 -> V_45 [ V_46 ] ;
V_5 -> V_170 = V_16 -> V_45 [ V_52 ] ;
* V_16 -> V_45 [ V_46 ] = NULL ;
}
if ( V_16 -> V_44 != NULL ) {
* V_5 -> V_171 = V_16 -> V_44 ;
V_5 -> V_171 = V_16 -> V_45 [ V_46 ] ;
}
F_140 ( V_16 ) ;
V_16 -> V_45 [ V_52 ] = NULL ;
}
static void F_197 ( struct V_4 * V_5 , unsigned long V_26 )
{
int V_51 ;
struct V_15 * V_16 = F_16 ( V_5 -> V_21 ) ;
if ( ! F_56 ( V_167 ) ||
F_198 ( V_5 , V_16 , V_26 ) )
return;
V_16 -> V_168 += V_5 -> V_168 ;
V_16 -> V_111 += V_5 -> V_111 ;
V_16 -> V_172 += V_5 -> V_111 ;
if ( V_5 -> V_168 != V_5 -> V_111 )
F_199 () ;
V_5 -> V_168 = 0 ;
V_5 -> V_111 = 0 ;
if ( V_5 -> V_173 != NULL ) {
* V_5 -> V_171 = * V_16 -> V_45 [ V_46 ] ;
* V_16 -> V_45 [ V_46 ] = V_5 -> V_173 ;
for ( V_51 = V_115 - 1 ; V_51 >= V_46 ; V_51 -- )
if ( V_16 -> V_45 [ V_51 ] == V_16 -> V_45 [ V_46 ] )
V_16 -> V_45 [ V_51 ] = V_5 -> V_171 ;
V_5 -> V_173 = NULL ;
V_5 -> V_171 = & V_5 -> V_173 ;
}
if ( V_5 -> V_174 != NULL ) {
* V_16 -> V_45 [ V_52 ] = V_5 -> V_174 ;
V_16 -> V_45 [ V_52 ] = V_5 -> V_170 ;
V_5 -> V_174 = NULL ;
V_5 -> V_170 = & V_5 -> V_174 ;
}
}
static void F_200 ( struct V_4 * V_5 )
{
F_201 (unsigned long mask) ;
F_201 ( struct V_15 * V_16 = F_10 ( V_5 -> V_21 ) ) ;
F_201 ( struct V_1 * V_2 = V_16 -> V_23 ) ;
if ( ! F_56 ( V_167 ) )
return;
F_201 ( V_161 = V_16 -> V_75 ) ;
F_6 ( V_5 -> V_31 ,
V_2 -> V_7 + 1 - ! ! ( V_2 -> V_101 & V_161 ) ,
F_7 ( L_52 ) ) ;
}
static void F_166 ( struct V_1 * V_175 )
{
long V_161 ;
struct V_1 * V_2 = V_175 ;
if ( ! F_56 ( V_167 ) ||
V_2 -> V_135 || F_165 ( V_2 ) )
return;
for (; ; ) {
V_161 = V_2 -> V_75 ;
V_2 = V_2 -> V_165 ;
if ( ! V_2 )
break;
F_146 ( V_2 ) ;
V_2 -> V_135 &= ~ V_161 ;
V_2 -> V_101 &= ~ V_161 ;
if ( V_2 -> V_135 ) {
F_148 ( V_2 ) ;
return;
}
F_148 ( V_2 ) ;
}
}
static void F_202 ( int V_80 , struct V_4 * V_5 )
{
unsigned long V_26 ;
struct V_15 * V_16 = F_132 ( V_5 -> V_21 , V_80 ) ;
struct V_1 * V_2 = V_16 -> V_23 ;
if ( ! F_56 ( V_167 ) )
return;
F_203 ( V_2 , - 1 ) ;
F_204 ( & V_5 -> V_176 , V_26 ) ;
F_195 ( V_80 , V_5 , V_2 , V_16 ) ;
F_197 ( V_5 , V_26 ) ;
F_205 ( & V_5 -> V_176 , V_26 ) ;
F_61 ( V_16 -> V_111 != 0 || V_16 -> V_44 != NULL ,
L_53 ,
V_80 , V_16 -> V_111 , V_16 -> V_44 ) ;
}
static void F_206 ( struct V_4 * V_5 , struct V_15 * V_16 )
{
unsigned long V_26 ;
struct V_177 * V_178 , * V_179 , * * V_180 ;
long V_181 , V_182 , V_183 ;
int V_51 ;
if ( ! F_49 ( V_16 ) ) {
F_207 ( V_5 -> V_31 , V_16 -> V_168 , V_16 -> V_111 , 0 ) ;
F_208 ( V_5 -> V_31 , 0 , ! ! F_2 ( V_16 -> V_44 ) ,
F_209 () , F_57 ( V_60 ) ,
F_210 () ) ;
return;
}
F_27 ( V_26 ) ;
F_65 ( F_103 ( F_59 () ) ) ;
V_181 = V_16 -> V_184 ;
F_207 ( V_5 -> V_31 , V_16 -> V_168 , V_16 -> V_111 , V_181 ) ;
V_179 = V_16 -> V_44 ;
V_16 -> V_44 = * V_16 -> V_45 [ V_46 ] ;
* V_16 -> V_45 [ V_46 ] = NULL ;
V_180 = V_16 -> V_45 [ V_46 ] ;
for ( V_51 = V_115 - 1 ; V_51 >= 0 ; V_51 -- )
if ( V_16 -> V_45 [ V_51 ] == V_16 -> V_45 [ V_46 ] )
V_16 -> V_45 [ V_51 ] = & V_16 -> V_44 ;
F_28 ( V_26 ) ;
V_182 = V_183 = 0 ;
while ( V_179 ) {
V_178 = V_179 -> V_178 ;
F_211 ( V_178 ) ;
F_212 ( V_179 ) ;
if ( F_213 ( V_5 -> V_31 , V_179 ) )
V_183 ++ ;
V_179 = V_178 ;
if ( ++ V_182 >= V_181 &&
( F_209 () ||
( ! F_57 ( V_60 ) && ! F_210 () ) ) )
break;
}
F_27 ( V_26 ) ;
F_208 ( V_5 -> V_31 , V_182 , ! ! V_179 , F_209 () ,
F_57 ( V_60 ) ,
F_210 () ) ;
if ( V_179 != NULL ) {
* V_180 = V_16 -> V_44 ;
V_16 -> V_44 = V_179 ;
for ( V_51 = 0 ; V_51 < V_115 ; V_51 ++ )
if ( & V_16 -> V_44 == V_16 -> V_45 [ V_51 ] )
V_16 -> V_45 [ V_51 ] = V_180 ;
else
break;
}
F_17 () ;
V_16 -> V_168 -= V_183 ;
F_99 ( V_16 -> V_111 , V_16 -> V_111 - V_182 ) ;
V_16 -> V_185 += V_182 ;
if ( V_16 -> V_184 == V_186 && V_16 -> V_111 <= V_187 )
V_16 -> V_184 = V_184 ;
if ( V_16 -> V_111 == 0 && V_16 -> V_188 != 0 ) {
V_16 -> V_188 = 0 ;
V_16 -> V_189 = V_5 -> V_95 ;
} else if ( V_16 -> V_111 < V_16 -> V_188 - V_190 )
V_16 -> V_188 = V_16 -> V_111 ;
F_65 ( ( V_16 -> V_44 == NULL ) != ( V_16 -> V_111 == 0 ) ) ;
F_28 ( V_26 ) ;
if ( F_49 ( V_16 ) )
F_214 () ;
}
void F_215 ( int V_57 )
{
F_23 ( F_7 ( L_54 ) ) ;
F_216 () ;
if ( V_57 || F_94 () ) {
F_4 () ;
F_11 () ;
} else if ( ! F_217 () ) {
F_11 () ;
}
F_218 () ;
if ( F_219 () )
F_214 () ;
if ( V_57 )
F_220 ( V_60 ) ;
F_23 ( F_7 ( L_55 ) ) ;
}
static void F_176 ( struct V_4 * V_5 ,
int (* F_221)( struct V_15 * V_5 , bool * V_77 ,
unsigned long * V_78 ) ,
bool * V_77 , unsigned long * V_78 )
{
int V_80 ;
unsigned long V_26 ;
unsigned long V_161 ;
struct V_1 * V_2 ;
F_116 (rsp, rnp) {
F_171 () ;
V_161 = 0 ;
F_117 ( V_2 , V_26 ) ;
if ( V_2 -> V_101 == 0 ) {
if ( V_28 == & V_13 ||
V_5 != V_28 ||
F_173 ( V_2 ) ) {
F_222 ( V_2 , V_26 ) ;
continue;
}
if ( V_2 -> V_165 &&
( V_2 -> V_165 -> V_101 & V_2 -> V_75 ) ) {
F_192 ( V_5 , V_2 , V_26 ) ;
continue;
}
}
F_118 (rnp, cpu) {
unsigned long V_191 = F_119 ( V_2 , V_80 ) ;
if ( ( V_2 -> V_101 & V_191 ) != 0 ) {
if ( F_221 ( F_132 ( V_5 -> V_21 , V_80 ) , V_77 , V_78 ) )
V_161 |= V_191 ;
}
}
if ( V_161 != 0 ) {
F_190 ( V_161 , V_5 , V_2 , V_2 -> V_7 , V_26 ) ;
} else {
F_121 ( V_2 , V_26 ) ;
}
}
}
static void F_41 ( struct V_4 * V_5 )
{
unsigned long V_26 ;
bool V_74 ;
struct V_1 * V_2 ;
struct V_1 * V_192 = NULL ;
V_2 = F_5 ( V_5 -> V_21 -> V_23 ) ;
for (; V_2 != NULL ; V_2 = V_2 -> V_165 ) {
V_74 = ( F_2 ( V_5 -> V_42 ) & V_139 ) ||
! F_223 ( & V_2 -> V_193 ) ;
if ( V_192 != NULL )
F_224 ( & V_192 -> V_193 ) ;
if ( V_74 ) {
V_5 -> V_194 ++ ;
return;
}
V_192 = V_2 ;
}
F_117 ( V_192 , V_26 ) ;
F_224 ( & V_192 -> V_193 ) ;
if ( F_2 ( V_5 -> V_42 ) & V_139 ) {
V_5 -> V_194 ++ ;
F_121 ( V_192 , V_26 ) ;
return;
}
F_99 ( V_5 -> V_42 , F_2 ( V_5 -> V_42 ) | V_139 ) ;
F_121 ( V_192 , V_26 ) ;
F_150 ( V_5 ) ;
}
static void
F_225 ( struct V_4 * V_5 )
{
unsigned long V_26 ;
bool V_129 ;
struct V_15 * V_16 = F_16 ( V_5 -> V_21 ) ;
F_65 ( V_16 -> V_195 == 0 ) ;
F_194 ( V_5 , V_16 ) ;
F_27 ( V_26 ) ;
if ( F_52 ( V_5 , V_16 ) ) {
F_146 ( F_50 ( V_5 ) ) ;
V_129 = F_188 ( V_5 ) ;
F_121 ( F_50 ( V_5 ) , V_26 ) ;
if ( V_129 )
F_150 ( V_5 ) ;
} else {
F_28 ( V_26 ) ;
}
if ( F_49 ( V_16 ) )
F_226 ( V_5 , V_16 ) ;
F_62 ( V_16 ) ;
}
static T_4 void F_227 ( struct V_196 * V_197 )
{
struct V_4 * V_5 ;
if ( F_103 ( F_59 () ) )
return;
F_23 ( F_7 ( L_56 ) ) ;
F_15 (rsp)
F_225 ( V_5 ) ;
F_23 ( F_7 ( L_57 ) ) ;
}
static void F_226 ( struct V_4 * V_5 , struct V_15 * V_16 )
{
if ( F_25 ( ! F_2 ( V_76 ) ) )
return;
if ( F_228 ( ! V_5 -> V_198 ) ) {
F_206 ( V_5 , V_16 ) ;
return;
}
F_229 () ;
}
static void F_214 ( void )
{
if ( F_230 ( F_59 () ) )
F_231 ( V_199 ) ;
}
static void F_232 ( struct V_4 * V_5 , struct V_15 * V_16 ,
struct V_177 * V_200 , unsigned long V_26 )
{
bool V_129 ;
if ( ! F_89 () )
F_214 () ;
if ( F_233 ( V_26 ) || F_103 ( F_59 () ) )
return;
if ( F_25 ( V_16 -> V_111 > V_16 -> V_188 + V_190 ) ) {
F_156 ( V_5 , V_16 ) ;
if ( ! F_3 ( V_5 ) ) {
struct V_1 * V_121 = F_50 ( V_5 ) ;
F_146 ( V_121 ) ;
V_129 = F_188 ( V_5 ) ;
F_148 ( V_121 ) ;
if ( V_129 )
F_150 ( V_5 ) ;
} else {
V_16 -> V_184 = V_186 ;
if ( V_5 -> V_95 == V_16 -> V_189 &&
* V_16 -> V_45 [ V_46 ] != V_200 )
F_41 ( V_5 ) ;
V_16 -> V_189 = V_5 -> V_95 ;
V_16 -> V_188 = V_16 -> V_111 ;
}
}
}
static void F_234 ( struct V_177 * V_201 )
{
}
static void
F_235 ( struct V_177 * V_200 , T_5 V_202 ,
struct V_4 * V_5 , int V_80 , bool V_203 )
{
unsigned long V_26 ;
struct V_15 * V_16 ;
F_65 ( ( unsigned long ) V_200 & 0x1 ) ;
if ( F_236 ( V_200 ) ) {
F_99 ( V_200 -> V_202 , F_234 ) ;
F_61 ( 1 , L_58 ) ;
return;
}
V_200 -> V_202 = V_202 ;
V_200 -> V_178 = NULL ;
F_27 ( V_26 ) ;
V_16 = F_10 ( V_5 -> V_21 ) ;
if ( F_25 ( V_16 -> V_45 [ V_52 ] == NULL ) || V_80 != - 1 ) {
int V_204 ;
if ( V_80 != - 1 )
V_16 = F_132 ( V_5 -> V_21 , V_80 ) ;
if ( F_228 ( V_16 -> V_23 ) ) {
V_204 = ! F_237 ( V_16 , V_200 , V_203 , V_26 ) ;
F_65 ( V_204 ) ;
F_28 ( V_26 ) ;
return;
}
F_238 ( V_80 != - 1 ) ;
F_65 ( ! F_89 () ) ;
if ( ! F_228 ( V_16 -> V_44 ) )
F_139 ( V_16 ) ;
}
F_99 ( V_16 -> V_111 , V_16 -> V_111 + 1 ) ;
if ( V_203 )
V_16 -> V_168 ++ ;
else
F_199 () ;
F_17 () ;
* V_16 -> V_45 [ V_52 ] = V_200 ;
V_16 -> V_45 [ V_52 ] = & V_200 -> V_178 ;
if ( F_239 ( ( unsigned long ) V_202 ) )
F_240 ( V_5 -> V_31 , V_200 , ( unsigned long ) V_202 ,
V_16 -> V_168 , V_16 -> V_111 ) ;
else
F_241 ( V_5 -> V_31 , V_200 , V_16 -> V_168 , V_16 -> V_111 ) ;
F_232 ( V_5 , V_16 , V_200 , V_26 ) ;
F_28 ( V_26 ) ;
}
void F_242 ( struct V_177 * V_200 , T_5 V_202 )
{
F_235 ( V_200 , V_202 , & V_13 , - 1 , 0 ) ;
}
void F_243 ( struct V_177 * V_200 , T_5 V_202 )
{
F_235 ( V_200 , V_202 , & V_29 , - 1 , 0 ) ;
}
void F_244 ( struct V_177 * V_200 ,
T_5 V_202 )
{
F_235 ( V_200 , V_202 , V_28 , - 1 , 1 ) ;
}
static inline int F_245 ( void )
{
int V_74 ;
F_246 () ;
F_29 () ;
V_74 = F_247 () <= 1 ;
F_30 () ;
return V_74 ;
}
void F_248 ( void )
{
F_68 ( F_69 ( & V_67 ) ||
F_69 ( & V_66 ) ||
F_69 ( & V_68 ) ,
L_59 ) ;
if ( F_245 () )
return;
if ( F_249 () )
F_250 () ;
else
F_251 ( F_242 ) ;
}
void F_252 ( void )
{
F_68 ( F_69 ( & V_67 ) ||
F_69 ( & V_66 ) ||
F_69 ( & V_68 ) ,
L_60 ) ;
if ( F_245 () )
return;
if ( F_249 () )
F_253 () ;
else
F_251 ( F_243 ) ;
}
unsigned long F_254 ( void )
{
F_17 () ;
return F_255 ( & V_28 -> V_7 ) ;
}
void F_256 ( unsigned long V_205 )
{
unsigned long V_206 ;
V_206 = F_255 ( & V_28 -> V_6 ) ;
if ( F_102 ( V_205 , V_206 ) )
F_257 () ;
}
unsigned long F_258 ( void )
{
F_17 () ;
return F_255 ( & V_13 . V_7 ) ;
}
void F_259 ( unsigned long V_205 )
{
unsigned long V_206 ;
V_206 = F_255 ( & V_13 . V_6 ) ;
if ( F_102 ( V_205 , V_206 ) )
F_248 () ;
}
static void F_260 ( unsigned long * V_207 )
{
F_99 ( * V_207 , * V_207 + 1 ) ;
F_17 () ;
F_65 ( ! ( * V_207 & 0x1 ) ) ;
}
static void F_261 ( unsigned long * V_207 )
{
F_17 () ;
F_99 ( * V_207 , * V_207 + 1 ) ;
F_65 ( * V_207 & 0x1 ) ;
}
static unsigned long F_262 ( unsigned long * V_207 )
{
unsigned long V_10 ;
V_10 = ( F_2 ( * V_207 ) + 3 ) & ~ 0x1 ;
F_17 () ;
return V_10 ;
}
static bool F_263 ( unsigned long * V_207 , unsigned long V_10 )
{
return F_102 ( F_2 ( * V_207 ) , V_10 ) ;
}
static int F_264 ( struct V_4 * V_5 , struct V_15 * V_16 )
{
struct V_1 * V_2 = V_16 -> V_23 ;
V_16 -> V_208 ++ ;
F_136 ( V_5 , V_16 ) ;
if ( F_265 ( V_5 ) )
return 0 ;
if ( V_76 &&
V_16 -> V_128 && V_16 -> V_9 . V_11 . V_12 &&
V_16 -> V_127 == F_5 ( V_27 ) ) {
V_16 -> V_209 ++ ;
} else if ( V_16 -> V_128 &&
( ! V_16 -> V_9 . V_11 . V_12 ||
V_16 -> V_127 != F_5 ( V_27 ) ) ) {
V_16 -> V_210 ++ ;
return 1 ;
}
if ( F_49 ( V_16 ) ) {
V_16 -> V_211 ++ ;
return 1 ;
}
if ( F_52 ( V_5 , V_16 ) ) {
V_16 -> V_212 ++ ;
return 1 ;
}
if ( F_2 ( V_2 -> V_6 ) != V_16 -> V_6 ) {
V_16 -> V_213 ++ ;
return 1 ;
}
if ( F_2 ( V_2 -> V_7 ) != V_16 -> V_7 ||
F_25 ( F_2 ( V_16 -> V_82 ) ) ) {
V_16 -> V_214 ++ ;
return 1 ;
}
if ( F_266 ( V_16 ) ) {
V_16 -> V_215 ++ ;
return 1 ;
}
V_16 -> V_216 ++ ;
return 0 ;
}
static int F_219 ( void )
{
struct V_4 * V_5 ;
F_15 (rsp)
if ( F_264 ( V_5 , F_10 ( V_5 -> V_21 ) ) )
return 1 ;
return 0 ;
}
static bool V_62 F_267 ( bool * V_217 )
{
bool V_218 = true ;
bool V_219 = false ;
struct V_15 * V_16 ;
struct V_4 * V_5 ;
F_15 (rsp) {
V_16 = F_10 ( V_5 -> V_21 ) ;
if ( ! V_16 -> V_44 )
continue;
V_219 = true ;
if ( V_16 -> V_111 != V_16 -> V_168 || ! V_217 ) {
V_218 = false ;
break;
}
}
if ( V_217 )
* V_217 = V_218 ;
return V_219 ;
}
static void F_268 ( struct V_4 * V_5 , const char * V_10 ,
int V_80 , unsigned long V_220 )
{
F_269 ( V_5 -> V_31 , V_10 , V_80 ,
F_66 ( & V_5 -> V_221 ) , V_220 ) ;
}
static void F_270 ( struct V_177 * V_201 )
{
struct V_15 * V_16 = F_271 ( V_201 , struct V_15 , V_222 ) ;
struct V_4 * V_5 = V_16 -> V_5 ;
if ( F_272 ( & V_5 -> V_221 ) ) {
F_268 ( V_5 , L_61 , - 1 , V_5 -> V_223 ) ;
F_273 ( & V_5 -> V_224 ) ;
} else {
F_268 ( V_5 , L_62 , - 1 , V_5 -> V_223 ) ;
}
}
static void F_274 ( void * type )
{
struct V_4 * V_5 = type ;
struct V_15 * V_16 = F_16 ( V_5 -> V_21 ) ;
F_268 ( V_5 , L_63 , - 1 , V_5 -> V_223 ) ;
F_64 ( & V_5 -> V_221 ) ;
V_5 -> V_225 ( & V_16 -> V_222 , F_270 ) ;
}
static void F_275 ( struct V_4 * V_5 )
{
int V_80 ;
struct V_15 * V_16 ;
unsigned long V_10 = F_262 ( & V_5 -> V_223 ) ;
F_268 ( V_5 , L_64 , - 1 , V_10 ) ;
F_276 ( & V_5 -> V_226 ) ;
if ( F_263 ( & V_5 -> V_223 , V_10 ) ) {
F_268 ( V_5 , L_65 , - 1 , V_5 -> V_223 ) ;
F_17 () ;
F_277 ( & V_5 -> V_226 ) ;
return;
}
F_260 ( & V_5 -> V_223 ) ;
F_268 ( V_5 , L_66 , - 1 , V_5 -> V_223 ) ;
F_278 ( & V_5 -> V_224 ) ;
F_279 ( & V_5 -> V_221 , 1 ) ;
F_280 () ;
F_131 (cpu) {
if ( ! F_230 ( V_80 ) && ! F_196 ( V_80 ) )
continue;
V_16 = F_132 ( V_5 -> V_21 , V_80 ) ;
if ( F_196 ( V_80 ) ) {
if ( ! F_281 ( V_5 , V_80 ) ) {
F_268 ( V_5 , L_67 , V_80 ,
V_5 -> V_223 ) ;
} else {
F_268 ( V_5 , L_68 , V_80 ,
V_5 -> V_223 ) ;
F_18 () ;
F_64 ( & V_5 -> V_221 ) ;
F_235 ( & V_16 -> V_222 ,
F_270 , V_5 , V_80 , 0 ) ;
}
} else if ( F_2 ( V_16 -> V_111 ) ) {
F_268 ( V_5 , L_69 , V_80 ,
V_5 -> V_223 ) ;
F_282 ( V_80 , F_274 , V_5 , 1 ) ;
} else {
F_268 ( V_5 , L_70 , V_80 ,
V_5 -> V_223 ) ;
}
}
F_283 () ;
if ( F_272 ( & V_5 -> V_221 ) )
F_273 ( & V_5 -> V_224 ) ;
F_284 ( & V_5 -> V_224 ) ;
F_268 ( V_5 , L_71 , - 1 , V_5 -> V_223 ) ;
F_261 ( & V_5 -> V_223 ) ;
F_277 ( & V_5 -> V_226 ) ;
}
void F_285 ( void )
{
F_275 ( & V_29 ) ;
}
void F_286 ( void )
{
F_275 ( & V_13 ) ;
}
static void F_164 ( struct V_1 * V_175 )
{
long V_161 ;
struct V_1 * V_2 = V_175 ;
for (; ; ) {
V_161 = V_2 -> V_75 ;
V_2 = V_2 -> V_165 ;
if ( V_2 == NULL )
return;
F_146 ( V_2 ) ;
V_2 -> V_135 |= V_161 ;
F_148 ( V_2 ) ;
}
}
static void T_6
F_287 ( int V_80 , struct V_4 * V_5 )
{
unsigned long V_26 ;
struct V_15 * V_16 = F_132 ( V_5 -> V_21 , V_80 ) ;
struct V_1 * V_2 = F_50 ( V_5 ) ;
F_117 ( V_2 , V_26 ) ;
V_16 -> V_75 = F_119 ( V_16 -> V_23 , V_80 ) ;
V_16 -> V_25 = & F_104 ( V_17 , V_80 ) ;
F_65 ( V_16 -> V_25 -> V_58 != V_71 ) ;
F_65 ( F_66 ( & V_16 -> V_25 -> V_25 ) != 1 ) ;
V_16 -> V_80 = V_80 ;
V_16 -> V_5 = V_5 ;
F_288 ( V_16 ) ;
F_121 ( V_2 , V_26 ) ;
}
static void
F_289 ( int V_80 , struct V_4 * V_5 )
{
unsigned long V_26 ;
unsigned long V_161 ;
struct V_15 * V_16 = F_132 ( V_5 -> V_21 , V_80 ) ;
struct V_1 * V_2 = F_50 ( V_5 ) ;
F_117 ( V_2 , V_26 ) ;
V_16 -> V_188 = 0 ;
V_16 -> V_189 = V_5 -> V_95 ;
V_16 -> V_184 = V_184 ;
if ( ! V_16 -> V_44 )
F_140 ( V_16 ) ;
V_16 -> V_25 -> V_58 = V_71 ;
F_290 ( V_16 -> V_25 ) ;
F_279 ( & V_16 -> V_25 -> V_25 ,
( F_66 ( & V_16 -> V_25 -> V_25 ) & ~ 0x1 ) + 1 ) ;
F_148 ( V_2 ) ;
V_2 = V_16 -> V_23 ;
V_161 = V_16 -> V_75 ;
F_146 ( V_2 ) ;
if ( ! V_16 -> V_195 )
F_99 ( V_5 -> V_227 , F_2 ( V_5 -> V_227 ) + 1 ) ;
V_16 -> V_195 = true ;
V_16 -> V_7 = V_2 -> V_6 ;
V_16 -> V_6 = V_2 -> V_6 ;
V_16 -> V_9 . V_11 . V_12 = true ;
V_16 -> V_127 = F_104 ( V_27 , V_80 ) ;
V_16 -> V_128 = false ;
F_6 ( V_5 -> V_31 , V_16 -> V_7 , F_7 ( L_72 ) ) ;
F_121 ( V_2 , V_26 ) ;
}
int F_291 ( unsigned int V_80 )
{
struct V_4 * V_5 ;
F_15 (rsp)
F_289 ( V_80 , V_5 ) ;
F_292 ( V_80 ) ;
F_293 ( V_80 ) ;
return 0 ;
}
static void F_294 ( unsigned int V_80 , int V_228 )
{
struct V_15 * V_16 = F_132 ( V_28 -> V_21 , V_80 ) ;
F_203 ( V_16 -> V_23 , V_228 ) ;
}
int F_295 ( unsigned int V_80 )
{
F_296 ( V_80 ) ;
F_294 ( V_80 , - 1 ) ;
return 0 ;
}
int F_297 ( unsigned int V_80 )
{
F_294 ( V_80 , V_80 ) ;
return 0 ;
}
int F_298 ( unsigned int V_80 )
{
struct V_4 * V_5 ;
F_15 (rsp)
F_200 ( V_5 ) ;
return 0 ;
}
int F_299 ( unsigned int V_80 )
{
struct V_4 * V_5 ;
F_15 (rsp) {
F_202 ( V_80 , V_5 ) ;
F_62 ( F_132 ( V_5 -> V_21 , V_80 ) ) ;
}
return 0 ;
}
void F_300 ( unsigned int V_80 )
{
unsigned long V_26 ;
unsigned long V_161 ;
struct V_15 * V_16 ;
struct V_1 * V_2 ;
struct V_4 * V_5 ;
F_15 (rsp) {
V_16 = F_10 ( V_5 -> V_21 ) ;
V_2 = V_16 -> V_23 ;
V_161 = V_16 -> V_75 ;
F_117 ( V_2 , V_26 ) ;
V_2 -> V_3 |= V_161 ;
V_2 -> V_229 |= V_161 ;
F_121 ( V_2 , V_26 ) ;
}
}
static void F_301 ( int V_80 , struct V_4 * V_5 )
{
unsigned long V_26 ;
unsigned long V_161 ;
struct V_15 * V_16 = F_132 ( V_5 -> V_21 , V_80 ) ;
struct V_1 * V_2 = V_16 -> V_23 ;
V_161 = V_16 -> V_75 ;
F_117 ( V_2 , V_26 ) ;
V_2 -> V_3 &= ~ V_161 ;
F_121 ( V_2 , V_26 ) ;
}
void F_302 ( unsigned int V_80 )
{
struct V_4 * V_5 ;
F_29 () ;
F_9 ( & V_13 ,
F_10 ( V_13 . V_21 ) , true ) ;
F_30 () ;
F_15 (rsp)
F_301 ( V_80 , V_5 ) ;
}
static int F_303 ( struct V_230 * V_231 ,
unsigned long V_232 , void * V_233 )
{
switch ( V_232 ) {
case V_234 :
case V_235 :
if ( V_236 <= 256 )
F_304 () ;
break;
case V_237 :
case V_238 :
if ( V_236 <= 256 )
F_305 () ;
break;
default:
break;
}
return V_239 ;
}
static int T_6 F_306 ( void )
{
unsigned long V_26 ;
int V_240 = V_241 ;
struct V_1 * V_2 ;
struct V_4 * V_5 ;
struct V_242 V_207 ;
struct V_61 * V_243 ;
if ( F_56 ( V_244 ) && V_241 < 1 )
V_241 = 1 ;
else if ( V_241 < 0 )
V_241 = 0 ;
else if ( V_241 > 99 )
V_241 = 99 ;
if ( V_241 != V_240 )
F_307 ( L_73 ,
V_241 , V_240 ) ;
V_76 = 1 ;
F_15 (rsp) {
V_243 = F_308 ( F_182 , V_5 , L_74 , V_5 -> V_31 ) ;
F_238 ( F_309 ( V_243 ) ) ;
V_2 = F_50 ( V_5 ) ;
F_117 ( V_2 , V_26 ) ;
V_5 -> V_33 = V_243 ;
if ( V_241 ) {
V_207 . V_245 = V_241 ;
F_310 ( V_243 , V_246 , & V_207 ) ;
}
F_121 ( V_2 , V_26 ) ;
F_114 ( V_243 ) ;
}
F_311 () ;
F_312 () ;
return 0 ;
}
void F_313 ( void )
{
F_185 ( F_247 () != 1 ) ;
F_185 ( F_314 () > 0 ) ;
V_247 = 1 ;
}
static void T_6 F_315 ( int * V_248 , const int * V_249 )
{
int V_51 ;
if ( V_250 ) {
V_248 [ V_251 - 1 ] = V_252 ;
for ( V_51 = V_251 - 2 ; V_51 >= 0 ; V_51 -- )
V_248 [ V_51 ] = V_253 ;
} else {
int V_254 ;
int V_255 ;
V_255 = V_236 ;
for ( V_51 = V_251 - 1 ; V_51 >= 0 ; V_51 -- ) {
V_254 = V_249 [ V_51 ] ;
V_248 [ V_51 ] = ( V_255 + V_254 - 1 ) / V_254 ;
V_255 = V_254 ;
}
}
}
static void T_6 F_316 ( struct V_4 * V_5 )
{
static const char * const V_256 [] = V_257 ;
static const char * const V_258 [] = V_259 ;
static struct V_260 V_261 [ V_262 ] ;
static struct V_260 V_263 [ V_262 ] ;
static T_7 V_264 = 0x1 ;
int V_249 [ V_262 ] ;
int V_248 [ V_262 ] ;
int V_265 = 1 ;
int V_51 ;
int V_92 ;
struct V_1 * V_2 ;
F_317 ( V_262 > F_110 ( V_256 ) ) ;
if ( V_251 <= 0 || V_251 > V_262 )
F_125 ( L_75 ) ;
for ( V_51 = 0 ; V_51 < V_251 ; V_51 ++ )
V_249 [ V_51 ] = V_266 [ V_51 ] ;
for ( V_51 = 1 ; V_51 < V_251 ; V_51 ++ )
V_5 -> V_117 [ V_51 ] = V_5 -> V_117 [ V_51 - 1 ] + V_249 [ V_51 - 1 ] ;
F_315 ( V_248 , V_249 ) ;
V_5 -> V_22 = V_264 ;
V_264 <<= 1 ;
for ( V_51 = V_251 - 1 ; V_51 >= 0 ; V_51 -- ) {
V_265 *= V_248 [ V_51 ] ;
V_2 = V_5 -> V_117 [ V_51 ] ;
for ( V_92 = 0 ; V_92 < V_249 [ V_51 ] ; V_92 ++ , V_2 ++ ) {
F_318 ( & F_319 ( V_2 , V_162 ) ) ;
F_320 ( & F_319 ( V_2 , V_162 ) ,
& V_261 [ V_51 ] , V_256 [ V_51 ] ) ;
F_318 ( & V_2 -> V_193 ) ;
F_320 ( & V_2 -> V_193 ,
& V_263 [ V_51 ] , V_258 [ V_51 ] ) ;
V_2 -> V_7 = V_5 -> V_7 ;
V_2 -> V_6 = V_5 -> V_6 ;
V_2 -> V_101 = 0 ;
V_2 -> V_135 = 0 ;
V_2 -> V_118 = V_92 * V_265 ;
V_2 -> V_119 = ( V_92 + 1 ) * V_265 - 1 ;
if ( V_2 -> V_119 >= V_236 )
V_2 -> V_119 = V_236 - 1 ;
if ( V_51 == 0 ) {
V_2 -> V_267 = 0 ;
V_2 -> V_75 = 0 ;
V_2 -> V_165 = NULL ;
} else {
V_2 -> V_267 = V_92 % V_248 [ V_51 - 1 ] ;
V_2 -> V_75 = 1UL << V_2 -> V_267 ;
V_2 -> V_165 = V_5 -> V_117 [ V_51 - 1 ] +
V_92 / V_248 [ V_51 - 1 ] ;
}
V_2 -> V_117 = V_51 ;
F_321 ( & V_2 -> V_268 ) ;
F_322 ( V_2 ) ;
F_323 ( & V_2 -> V_269 [ 0 ] ) ;
F_323 ( & V_2 -> V_269 [ 1 ] ) ;
F_323 ( & V_2 -> V_269 [ 2 ] ) ;
F_323 ( & V_2 -> V_269 [ 3 ] ) ;
F_324 ( & V_2 -> V_270 ) ;
}
}
F_325 ( & V_5 -> V_125 ) ;
F_325 ( & V_5 -> V_271 ) ;
V_2 = V_5 -> V_117 [ V_251 - 1 ] ;
F_131 (i) {
while ( V_51 > V_2 -> V_119 )
V_2 ++ ;
F_132 ( V_5 -> V_21 , V_51 ) -> V_23 = V_2 ;
F_287 ( V_51 , V_5 ) ;
}
F_326 ( & V_5 -> V_272 , & V_273 ) ;
}
static void T_6 F_327 ( void )
{
T_8 V_274 ;
int V_51 ;
int V_275 [ V_262 ] ;
V_274 = V_276 + V_236 / V_277 ;
if ( V_155 == V_81 )
V_155 = V_274 ;
if ( V_112 == V_81 )
V_112 = V_274 ;
if ( V_252 == V_278 &&
V_236 == V_279 )
return;
F_45 ( L_76 ,
V_252 , V_236 ) ;
if ( V_252 < 2 ||
V_252 > sizeof( unsigned long ) * 8 ) {
V_252 = V_278 ;
F_185 ( 1 ) ;
return;
}
V_275 [ 0 ] = V_252 ;
for ( V_51 = 1 ; V_51 < V_262 ; V_51 ++ )
V_275 [ V_51 ] = V_275 [ V_51 - 1 ] * V_253 ;
if ( V_236 > V_275 [ V_262 - 1 ] ) {
V_252 = V_278 ;
F_185 ( 1 ) ;
return;
}
for ( V_51 = 0 ; V_236 > V_275 [ V_51 ] ; V_51 ++ ) {
}
V_251 = V_51 + 1 ;
for ( V_51 = 0 ; V_51 < V_251 ; V_51 ++ ) {
int V_280 = V_275 [ ( V_251 - 1 ) - V_51 ] ;
V_266 [ V_51 ] = F_328 ( V_236 , V_280 ) ;
}
V_131 = 0 ;
for ( V_51 = 0 ; V_51 < V_251 ; V_51 ++ )
V_131 += V_266 [ V_51 ] ;
}
static void T_6 F_329 ( struct V_4 * V_5 )
{
int V_117 = 0 ;
struct V_1 * V_2 ;
F_45 ( L_77 ) ;
F_45 ( L_78 ) ;
F_167 (rsp, rnp) {
if ( V_2 -> V_117 != V_117 ) {
F_133 ( L_79 ) ;
F_45 ( L_78 ) ;
V_117 = V_2 -> V_117 ;
}
F_133 ( L_80 , V_2 -> V_118 , V_2 -> V_119 , V_2 -> V_267 ) ;
}
F_133 ( L_79 ) ;
}
void T_6 F_330 ( void )
{
int V_80 ;
F_331 () ;
F_332 () ;
F_327 () ;
F_316 ( & V_29 ) ;
F_316 ( & V_13 ) ;
if ( V_281 )
F_329 ( & V_13 ) ;
F_333 () ;
F_334 ( V_199 , F_227 ) ;
F_335 ( F_303 , 0 ) ;
F_336 (cpu) {
F_291 ( V_80 ) ;
F_300 ( V_80 ) ;
}
}
