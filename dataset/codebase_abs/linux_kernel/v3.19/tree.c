static int F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_2 -> V_3 ) != F_2 ( V_2 -> V_4 ) ;
}
void F_3 ( void )
{
if ( ! F_4 ( V_5 . V_6 ) ) {
F_5 ( F_6 ( L_1 ) ,
F_4 ( V_5 . V_4 ) ,
F_6 ( L_2 ) ) ;
F_7 ( V_5 . V_6 , 1 ) ;
}
}
void F_8 ( void )
{
if ( ! F_4 ( V_7 . V_6 ) ) {
F_5 ( F_6 ( L_3 ) ,
F_4 ( V_7 . V_4 ) ,
F_6 ( L_2 ) ) ;
F_7 ( V_7 . V_6 , 1 ) ;
}
}
static void F_9 ( void )
{
unsigned long V_8 ;
struct V_9 * V_10 ;
struct V_11 * V_12 ;
int V_13 ;
struct V_1 * V_2 ;
F_10 ( V_8 ) ;
V_13 = F_11 ( V_14 ) ;
F_12 ( V_14 , 0 ) ;
F_13 (rsp) {
V_10 = F_14 ( V_2 -> V_15 ) ;
if ( ! ( V_13 & V_2 -> V_16 ) )
continue;
F_15 () ;
if ( F_2 ( V_10 -> V_17 -> V_3 ) !=
F_2 ( V_10 -> V_18 ) )
continue;
V_12 = F_16 ( & V_11 ) ;
F_17 () ;
F_18 ( 2 , & V_12 -> V_19 ) ;
F_19 () ;
break;
}
F_20 ( V_8 ) ;
}
void F_21 ( void )
{
F_22 ( F_6 ( L_4 ) ) ;
F_3 () ;
F_23 () ;
if ( F_24 ( F_11 ( V_14 ) ) )
F_9 () ;
F_22 ( F_6 ( L_5 ) ) ;
}
long F_25 ( void )
{
return V_20 . V_3 ;
}
long F_26 ( void )
{
return V_21 . V_3 ;
}
void F_27 ( void )
{
F_28 ( V_22 ) ;
}
void F_29 ( void )
{
F_28 ( & V_21 ) ;
}
void F_30 ( void )
{
struct V_1 * V_2 ;
F_13 (rsp) {
F_31 ( L_6 ,
V_2 -> V_23 , V_2 -> V_24 , V_2 -> V_25 -> V_26 ) ;
}
}
void F_32 ( void )
{
V_27 ++ ;
V_28 = 0 ;
}
void F_33 ( enum V_29 V_30 , int * V_8 ,
unsigned long * V_4 , unsigned long * V_3 )
{
struct V_1 * V_2 = NULL ;
switch ( V_30 ) {
case V_31 :
V_2 = V_22 ;
break;
case V_32 :
V_2 = & V_21 ;
break;
case V_33 :
V_2 = & V_20 ;
break;
default:
break;
}
if ( V_2 != NULL ) {
* V_8 = F_2 ( V_2 -> V_34 ) ;
* V_4 = F_2 ( V_2 -> V_4 ) ;
* V_3 = F_2 ( V_2 -> V_3 ) ;
return;
}
* V_8 = 0 ;
* V_4 = 0 ;
* V_3 = 0 ;
}
void F_34 ( unsigned long V_35 )
{
V_28 ++ ;
}
void F_35 ( void )
{
F_28 ( & V_20 ) ;
}
static int
F_36 ( struct V_9 * V_10 )
{
return & V_10 -> V_36 != V_10 -> V_37 [ V_38 ] &&
V_10 -> V_37 [ V_38 ] != NULL ;
}
static struct V_39 * F_37 ( struct V_1 * V_2 )
{
return & V_2 -> V_40 [ 0 ] ;
}
static int F_38 ( struct V_1 * V_2 )
{
struct V_39 * V_41 = F_37 ( V_2 ) ;
int V_42 = ( F_2 ( V_41 -> V_3 ) + 1 ) & 0x1 ;
int * V_43 = & V_41 -> V_44 [ V_42 ] ;
return F_2 ( * V_43 ) ;
}
static int
F_39 ( struct V_1 * V_2 , struct V_9 * V_10 )
{
int V_45 ;
if ( F_1 ( V_2 ) )
return 0 ;
if ( F_38 ( V_2 ) )
return 1 ;
if ( ! V_10 -> V_37 [ V_46 ] )
return 0 ;
if ( * V_10 -> V_37 [ V_47 ] )
return 1 ;
for ( V_45 = V_48 ; V_45 < V_46 ; V_45 ++ )
if ( V_10 -> V_37 [ V_45 - 1 ] != V_10 -> V_37 [ V_45 ] &&
F_40 ( F_2 ( V_2 -> V_3 ) ,
V_10 -> V_49 [ V_45 ] ) )
return 1 ;
return 0 ;
}
static void F_41 ( long long V_50 , bool V_51 )
{
struct V_1 * V_2 ;
struct V_9 * V_10 ;
struct V_11 * V_12 = F_16 ( & V_11 ) ;
F_42 ( F_6 ( L_7 ) , V_50 , V_12 -> V_52 ) ;
if ( ! V_51 && ! F_43 ( V_53 ) ) {
struct V_54 * T_1 V_55 =
F_44 ( F_45 () ) ;
F_42 ( F_6 ( L_8 ) , V_50 , 0 ) ;
F_46 ( V_56 ) ;
F_47 ( 1 , L_9 ,
V_53 -> V_57 , V_53 -> V_58 ,
T_1 -> V_57 , T_1 -> V_58 ) ;
}
F_13 (rsp) {
V_10 = F_16 ( V_2 -> V_15 ) ;
F_48 ( V_10 ) ;
}
F_49 () ;
F_17 () ;
F_50 ( & V_12 -> V_19 ) ;
F_19 () ;
F_51 ( F_52 ( & V_12 -> V_19 ) & 0x1 ) ;
F_53 () ;
F_54 ( ! F_55 ( & V_59 ) ,
L_10 ) ;
F_54 ( ! F_55 ( & V_60 ) ,
L_11 ) ;
F_54 ( ! F_55 ( & V_61 ) ,
L_12 ) ;
}
static void F_56 ( bool V_51 )
{
long long V_50 ;
struct V_11 * V_12 ;
V_12 = F_16 ( & V_11 ) ;
V_50 = V_12 -> V_52 ;
F_51 ( ( V_50 & V_62 ) == 0 ) ;
if ( ( V_50 & V_62 ) == V_63 ) {
V_12 -> V_52 = 0 ;
F_41 ( V_50 , V_51 ) ;
} else {
V_12 -> V_52 -= V_63 ;
}
}
void F_57 ( void )
{
unsigned long V_8 ;
F_10 ( V_8 ) ;
F_56 ( false ) ;
F_58 ( 0 ) ;
F_20 ( V_8 ) ;
}
void F_59 ( void )
{
F_56 ( 1 ) ;
}
void F_60 ( void )
{
unsigned long V_8 ;
long long V_50 ;
struct V_11 * V_12 ;
F_10 ( V_8 ) ;
V_12 = F_16 ( & V_11 ) ;
V_50 = V_12 -> V_52 ;
V_12 -> V_52 -- ;
F_51 ( V_12 -> V_52 < 0 ) ;
if ( V_12 -> V_52 )
F_42 ( F_6 ( L_13 ) , V_50 , V_12 -> V_52 ) ;
else
F_41 ( V_50 , true ) ;
F_58 ( 1 ) ;
F_20 ( V_8 ) ;
}
static void F_61 ( long long V_50 , int V_51 )
{
struct V_11 * V_12 = F_16 ( & V_11 ) ;
F_62 () ;
F_17 () ;
F_50 ( & V_12 -> V_19 ) ;
F_19 () ;
F_51 ( ! ( F_52 ( & V_12 -> V_19 ) & 0x1 ) ) ;
F_63 () ;
F_42 ( F_6 ( L_14 ) , V_50 , V_12 -> V_52 ) ;
if ( ! V_51 && ! F_43 ( V_53 ) ) {
struct V_54 * T_1 V_55 =
F_44 ( F_45 () ) ;
F_42 ( F_6 ( L_15 ) ,
V_50 , V_12 -> V_52 ) ;
F_46 ( V_56 ) ;
F_47 ( 1 , L_9 ,
V_53 -> V_57 , V_53 -> V_58 ,
T_1 -> V_57 , T_1 -> V_58 ) ;
}
}
static void F_64 ( bool V_51 )
{
struct V_11 * V_12 ;
long long V_50 ;
V_12 = F_16 ( & V_11 ) ;
V_50 = V_12 -> V_52 ;
F_51 ( V_50 < 0 ) ;
if ( V_50 & V_62 ) {
V_12 -> V_52 += V_63 ;
} else {
V_12 -> V_52 = V_64 ;
F_61 ( V_50 , V_51 ) ;
}
}
void F_65 ( void )
{
unsigned long V_8 ;
F_10 ( V_8 ) ;
F_64 ( false ) ;
F_66 ( 0 ) ;
F_20 ( V_8 ) ;
}
void F_67 ( void )
{
F_64 ( 1 ) ;
}
void F_68 ( void )
{
unsigned long V_8 ;
struct V_11 * V_12 ;
long long V_50 ;
F_10 ( V_8 ) ;
V_12 = F_16 ( & V_11 ) ;
V_50 = V_12 -> V_52 ;
V_12 -> V_52 ++ ;
F_51 ( V_12 -> V_52 == 0 ) ;
if ( V_50 )
F_42 ( F_6 ( L_16 ) , V_50 , V_12 -> V_52 ) ;
else
F_61 ( V_50 , true ) ;
F_66 ( 1 ) ;
F_20 ( V_8 ) ;
}
void F_69 ( void )
{
struct V_11 * V_12 = F_16 ( & V_11 ) ;
if ( V_12 -> V_65 == 0 &&
( F_52 ( & V_12 -> V_19 ) & 0x1 ) )
return;
V_12 -> V_65 ++ ;
F_17 () ;
F_50 ( & V_12 -> V_19 ) ;
F_19 () ;
F_51 ( ! ( F_52 ( & V_12 -> V_19 ) & 0x1 ) ) ;
}
void F_70 ( void )
{
struct V_11 * V_12 = F_16 ( & V_11 ) ;
if ( V_12 -> V_65 == 0 ||
-- V_12 -> V_65 != 0 )
return;
F_17 () ;
F_50 ( & V_12 -> V_19 ) ;
F_19 () ;
F_51 ( F_52 ( & V_12 -> V_19 ) & 0x1 ) ;
}
bool T_2 F_71 ( void )
{
return F_52 ( F_16 ( & V_11 . V_19 ) ) & 0x1 ;
}
bool T_2 F_72 ( void )
{
bool V_66 ;
F_73 () ;
V_66 = F_71 () ;
F_74 () ;
return V_66 ;
}
bool F_75 ( void )
{
struct V_9 * V_10 ;
struct V_39 * V_41 ;
bool V_66 ;
if ( F_76 () )
return true ;
F_73 () ;
V_10 = F_16 ( & V_5 ) ;
V_41 = V_10 -> V_17 ;
V_66 = ( V_10 -> V_67 & V_41 -> V_68 ) ||
! V_69 ;
F_74 () ;
return V_66 ;
}
static int F_77 ( void )
{
return F_4 ( V_11 . V_52 ) <= 1 ;
}
static int F_78 ( struct V_9 * V_10 ,
bool * V_70 , unsigned long * V_71 )
{
V_10 -> V_72 = F_79 ( 0 , & V_10 -> V_19 -> V_19 ) ;
F_80 ( V_10 , V_70 , V_71 ) ;
if ( ( V_10 -> V_72 & 0x1 ) == 0 ) {
F_81 ( V_10 -> V_2 -> V_23 , V_10 -> V_4 , V_10 -> V_73 , F_6 ( L_17 ) ) ;
return 1 ;
} else {
return 0 ;
}
}
static int F_82 ( struct V_9 * V_10 ,
bool * V_70 , unsigned long * V_71 )
{
unsigned int V_74 ;
int * V_75 ;
unsigned int V_76 ;
V_74 = ( unsigned int ) F_79 ( 0 , & V_10 -> V_19 -> V_19 ) ;
V_76 = ( unsigned int ) V_10 -> V_72 ;
if ( ( V_74 & 0x1 ) == 0 || F_83 ( V_74 , V_76 + 2 ) ) {
F_81 ( V_10 -> V_2 -> V_23 , V_10 -> V_4 , V_10 -> V_73 , F_6 ( L_17 ) ) ;
V_10 -> V_77 ++ ;
return 1 ;
}
if ( F_84 ( V_10 -> V_2 -> V_78 + 2 , V_79 ) )
return 0 ;
F_85 () ;
if ( F_86 ( V_10 -> V_73 ) ) {
F_81 ( V_10 -> V_2 -> V_23 , V_10 -> V_4 , V_10 -> V_73 , F_6 ( L_18 ) ) ;
V_10 -> V_80 ++ ;
return 1 ;
}
V_75 = & F_87 ( V_14 , V_10 -> V_73 ) ;
if ( F_84 ( V_79 ,
V_10 -> V_2 -> V_78 + V_81 ) ||
F_84 ( V_79 , V_10 -> V_2 -> V_82 ) ) {
if ( ! ( F_2 ( * V_75 ) & V_10 -> V_2 -> V_16 ) ) {
F_2 ( V_10 -> V_18 ) =
F_2 ( V_10 -> V_17 -> V_3 ) ;
F_15 () ;
F_2 ( * V_75 ) =
F_2 ( * V_75 ) + V_10 -> V_2 -> V_16 ;
F_88 ( V_10 -> V_73 ) ;
V_10 -> V_2 -> V_82 += 5 ;
} else if ( F_84 ( V_79 , V_10 -> V_2 -> V_82 ) ) {
F_88 ( V_10 -> V_73 ) ;
V_10 -> V_2 -> V_82 += 5 ;
}
}
return 0 ;
}
static void F_89 ( struct V_1 * V_2 )
{
unsigned long V_83 = V_79 ;
unsigned long j1 ;
V_2 -> V_78 = V_83 ;
F_90 () ;
j1 = F_91 () ;
F_2 ( V_2 -> V_84 ) = V_83 + j1 ;
V_2 -> V_82 = V_83 + j1 / 2 ;
}
static void F_92 ( struct V_1 * V_2 )
{
int V_73 ;
unsigned long V_8 ;
struct V_39 * V_41 ;
F_93 (rsp, rnp) {
F_94 ( & V_41 -> V_85 , V_8 ) ;
if ( V_41 -> V_86 != 0 ) {
for ( V_73 = 0 ; V_73 <= V_41 -> V_87 - V_41 -> V_88 ; V_73 ++ )
if ( V_41 -> V_86 & ( 1UL << V_73 ) )
F_95 ( V_41 -> V_88 + V_73 ) ;
}
F_96 ( & V_41 -> V_85 , V_8 ) ;
}
}
static void F_97 ( struct V_1 * V_2 )
{
int V_73 ;
long V_89 ;
unsigned long V_8 ;
int V_90 = 0 ;
struct V_39 * V_41 = F_37 ( V_2 ) ;
long V_91 = 0 ;
F_94 ( & V_41 -> V_85 , V_8 ) ;
V_89 = V_79 - F_2 ( V_2 -> V_84 ) ;
if ( V_89 < V_92 || ! F_1 ( V_2 ) ) {
F_96 ( & V_41 -> V_85 , V_8 ) ;
return;
}
F_2 ( V_2 -> V_84 ) = V_79 + 3 * F_91 () + 3 ;
F_96 ( & V_41 -> V_85 , V_8 ) ;
F_98 ( L_19 ,
V_2 -> V_23 ) ;
F_99 () ;
F_93 (rsp, rnp) {
F_94 ( & V_41 -> V_85 , V_8 ) ;
V_90 += F_100 ( V_41 ) ;
if ( V_41 -> V_86 != 0 ) {
for ( V_73 = 0 ; V_73 <= V_41 -> V_87 - V_41 -> V_88 ; V_73 ++ )
if ( V_41 -> V_86 & ( 1UL << V_73 ) ) {
F_101 ( V_2 ,
V_41 -> V_88 + V_73 ) ;
V_90 ++ ;
}
}
F_96 ( & V_41 -> V_85 , V_8 ) ;
}
V_41 = F_37 ( V_2 ) ;
F_94 ( & V_41 -> V_85 , V_8 ) ;
V_90 += F_100 ( V_41 ) ;
F_96 ( & V_41 -> V_85 , V_8 ) ;
F_102 () ;
F_103 (cpu)
V_91 += F_104 ( V_2 -> V_15 , V_73 ) -> V_93 ;
F_105 ( L_20 ,
F_45 () , ( long ) ( V_79 - V_2 -> V_78 ) ,
( long ) V_2 -> V_4 , ( long ) V_2 -> V_3 , V_91 ) ;
if ( V_90 == 0 )
F_98 ( L_21 ) ;
else
F_92 ( V_2 ) ;
F_106 ( V_2 ) ;
F_28 ( V_2 ) ;
}
static void F_107 ( struct V_1 * V_2 )
{
int V_73 ;
unsigned long V_8 ;
struct V_39 * V_41 = F_37 ( V_2 ) ;
long V_91 = 0 ;
F_98 ( L_22 , V_2 -> V_23 ) ;
F_99 () ;
F_101 ( V_2 , F_45 () ) ;
F_102 () ;
F_103 (cpu)
V_91 += F_104 ( V_2 -> V_15 , V_73 ) -> V_93 ;
F_105 ( L_23 ,
V_79 - V_2 -> V_78 ,
( long ) V_2 -> V_4 , ( long ) V_2 -> V_3 , V_91 ) ;
F_92 ( V_2 ) ;
F_94 ( & V_41 -> V_85 , V_8 ) ;
if ( F_84 ( V_79 , F_2 ( V_2 -> V_84 ) ) )
F_2 ( V_2 -> V_84 ) = V_79 +
3 * F_91 () + 3 ;
F_96 ( & V_41 -> V_85 , V_8 ) ;
F_88 ( F_45 () ) ;
}
static void F_108 ( struct V_1 * V_2 , struct V_9 * V_10 )
{
unsigned long V_3 ;
unsigned long V_4 ;
unsigned long V_94 ;
unsigned long V_83 ;
unsigned long V_95 ;
struct V_39 * V_41 ;
if ( V_96 || ! F_1 ( V_2 ) )
return;
V_83 = V_79 ;
V_4 = F_2 ( V_2 -> V_4 ) ;
F_109 () ;
V_95 = F_2 ( V_2 -> V_84 ) ;
F_109 () ;
V_94 = F_2 ( V_2 -> V_78 ) ;
F_109 () ;
V_3 = F_2 ( V_2 -> V_3 ) ;
if ( F_84 ( V_3 , V_4 ) ||
F_40 ( V_83 , V_95 ) ||
F_84 ( V_94 , V_95 ) )
return;
V_41 = V_10 -> V_17 ;
if ( F_1 ( V_2 ) &&
( F_2 ( V_41 -> V_86 ) & V_10 -> V_67 ) ) {
F_107 ( V_2 ) ;
} else if ( F_1 ( V_2 ) &&
F_84 ( V_83 , V_95 + V_92 ) ) {
F_97 ( V_2 ) ;
}
}
void F_110 ( void )
{
struct V_1 * V_2 ;
F_13 (rsp)
F_2 ( V_2 -> V_84 ) = V_79 + V_97 / 2 ;
}
static void F_111 ( struct V_9 * V_10 )
{
int V_45 ;
if ( F_112 ( V_10 ) )
return;
V_10 -> V_36 = NULL ;
for ( V_45 = 0 ; V_45 < V_98 ; V_45 ++ )
V_10 -> V_37 [ V_45 ] = & V_10 -> V_36 ;
}
static unsigned long F_113 ( struct V_1 * V_2 ,
struct V_39 * V_41 )
{
if ( F_37 ( V_2 ) == V_41 && V_41 -> V_4 == V_41 -> V_3 )
return V_41 -> V_3 + 1 ;
return V_41 -> V_3 + 2 ;
}
static void F_114 ( struct V_39 * V_41 , struct V_9 * V_10 ,
unsigned long V_99 , const char * V_100 )
{
F_115 ( V_10 -> V_2 -> V_23 , V_41 -> V_4 ,
V_41 -> V_3 , V_99 , V_41 -> V_101 ,
V_41 -> V_88 , V_41 -> V_87 , V_100 ) ;
}
static bool V_55
F_116 ( struct V_39 * V_41 , struct V_9 * V_10 ,
unsigned long * V_102 )
{
unsigned long V_99 ;
int V_45 ;
bool V_66 = false ;
struct V_39 * V_103 = F_37 ( V_10 -> V_2 ) ;
V_99 = F_113 ( V_10 -> V_2 , V_41 ) ;
F_114 ( V_41 , V_10 , V_99 , F_6 ( L_24 ) ) ;
if ( V_41 -> V_44 [ V_99 & 0x1 ] ) {
F_114 ( V_41 , V_10 , V_99 , F_6 ( L_25 ) ) ;
goto V_104;
}
if ( V_41 -> V_4 != V_41 -> V_3 ||
F_2 ( V_103 -> V_4 ) != F_2 ( V_103 -> V_3 ) ) {
V_41 -> V_44 [ V_99 & 0x1 ] ++ ;
F_114 ( V_41 , V_10 , V_99 , F_6 ( L_26 ) ) ;
goto V_104;
}
if ( V_41 != V_103 ) {
F_117 ( & V_103 -> V_85 ) ;
F_118 () ;
}
V_99 = F_113 ( V_10 -> V_2 , V_103 ) ;
for ( V_45 = V_38 ; V_45 < V_46 ; V_45 ++ )
if ( F_40 ( V_99 , V_10 -> V_49 [ V_45 ] ) )
V_10 -> V_49 [ V_45 ] = V_99 ;
if ( V_103 -> V_44 [ V_99 & 0x1 ] ) {
F_114 ( V_41 , V_10 , V_99 , F_6 ( L_27 ) ) ;
goto V_105;
}
V_103 -> V_44 [ V_99 & 0x1 ] ++ ;
if ( V_103 -> V_4 != V_103 -> V_3 ) {
F_114 ( V_41 , V_10 , V_99 , F_6 ( L_28 ) ) ;
} else {
F_114 ( V_41 , V_10 , V_99 , F_6 ( L_29 ) ) ;
V_66 = F_119 ( V_10 -> V_2 , V_103 , V_10 ) ;
}
V_105:
if ( V_41 != V_103 )
F_120 ( & V_103 -> V_85 ) ;
V_104:
if ( V_102 != NULL )
* V_102 = V_99 ;
return V_66 ;
}
static int F_121 ( struct V_1 * V_2 , struct V_39 * V_41 )
{
int V_99 = V_41 -> V_3 ;
int V_106 ;
struct V_9 * V_10 = F_16 ( V_2 -> V_15 ) ;
F_122 ( V_2 , V_41 ) ;
V_41 -> V_44 [ V_99 & 0x1 ] = 0 ;
V_106 = V_41 -> V_44 [ ( V_99 + 1 ) & 0x1 ] ;
F_114 ( V_41 , V_10 , V_99 ,
V_106 ? F_6 ( L_30 ) : F_6 ( L_31 ) ) ;
return V_106 ;
}
static void F_123 ( struct V_1 * V_2 )
{
if ( V_53 == V_2 -> V_25 ||
! F_2 ( V_2 -> V_34 ) ||
! V_2 -> V_25 )
return;
F_124 ( & V_2 -> V_107 ) ;
}
static bool F_125 ( struct V_1 * V_2 , struct V_39 * V_41 ,
struct V_9 * V_10 )
{
unsigned long V_99 ;
int V_45 ;
bool V_66 ;
if ( ! V_10 -> V_37 [ V_46 ] || ! * V_10 -> V_37 [ V_38 ] )
return false ;
V_99 = F_113 ( V_2 , V_41 ) ;
for ( V_45 = V_46 - 1 ; V_45 > V_38 ; V_45 -- )
if ( V_10 -> V_37 [ V_45 ] != V_10 -> V_37 [ V_45 - 1 ] &&
! F_84 ( V_10 -> V_49 [ V_45 ] , V_99 ) )
break;
if ( ++ V_45 >= V_46 )
return false ;
for (; V_45 <= V_46 ; V_45 ++ ) {
V_10 -> V_37 [ V_45 ] = V_10 -> V_37 [ V_46 ] ;
V_10 -> V_49 [ V_45 ] = V_99 ;
}
V_66 = F_116 ( V_41 , V_10 , NULL ) ;
if ( ! * V_10 -> V_37 [ V_48 ] )
F_5 ( V_2 -> V_23 , V_10 -> V_4 , F_6 ( L_32 ) ) ;
else
F_5 ( V_2 -> V_23 , V_10 -> V_4 , F_6 ( L_33 ) ) ;
return V_66 ;
}
static bool F_126 ( struct V_1 * V_2 , struct V_39 * V_41 ,
struct V_9 * V_10 )
{
int V_45 , V_83 ;
if ( ! V_10 -> V_37 [ V_46 ] || ! * V_10 -> V_37 [ V_38 ] )
return false ;
for ( V_45 = V_48 ; V_45 < V_46 ; V_45 ++ ) {
if ( F_40 ( V_41 -> V_3 , V_10 -> V_49 [ V_45 ] ) )
break;
V_10 -> V_37 [ V_38 ] = V_10 -> V_37 [ V_45 ] ;
}
for ( V_83 = V_48 ; V_83 < V_45 ; V_83 ++ )
V_10 -> V_37 [ V_83 ] = V_10 -> V_37 [ V_38 ] ;
for ( V_83 = V_48 ; V_45 < V_46 ; V_45 ++ , V_83 ++ ) {
if ( V_10 -> V_37 [ V_83 ] == V_10 -> V_37 [ V_46 ] )
break;
V_10 -> V_37 [ V_83 ] = V_10 -> V_37 [ V_45 ] ;
V_10 -> V_49 [ V_83 ] = V_10 -> V_49 [ V_45 ] ;
}
return F_125 ( V_2 , V_41 , V_10 ) ;
}
static bool F_127 ( struct V_1 * V_2 , struct V_39 * V_41 ,
struct V_9 * V_10 )
{
bool V_66 ;
if ( V_10 -> V_3 == V_41 -> V_3 ) {
V_66 = F_125 ( V_2 , V_41 , V_10 ) ;
} else {
V_66 = F_126 ( V_2 , V_41 , V_10 ) ;
V_10 -> V_3 = V_41 -> V_3 ;
F_5 ( V_2 -> V_23 , V_10 -> V_4 , F_6 ( L_34 ) ) ;
}
if ( V_10 -> V_4 != V_41 -> V_4 ) {
V_10 -> V_4 = V_41 -> V_4 ;
F_5 ( V_2 -> V_23 , V_10 -> V_4 , F_6 ( L_35 ) ) ;
V_10 -> V_6 = 0 ;
V_10 -> V_108 = ! ! ( V_41 -> V_86 & V_10 -> V_67 ) ;
F_128 ( V_10 ) ;
}
return V_66 ;
}
static void F_129 ( struct V_1 * V_2 , struct V_9 * V_10 )
{
unsigned long V_8 ;
bool V_109 ;
struct V_39 * V_41 ;
F_10 ( V_8 ) ;
V_41 = V_10 -> V_17 ;
if ( ( V_10 -> V_4 == F_2 ( V_41 -> V_4 ) &&
V_10 -> V_3 == F_2 ( V_41 -> V_3 ) ) ||
! F_130 ( & V_41 -> V_85 ) ) {
F_20 ( V_8 ) ;
return;
}
F_118 () ;
V_109 = F_127 ( V_2 , V_41 , V_10 ) ;
F_96 ( & V_41 -> V_85 , V_8 ) ;
if ( V_109 )
F_123 ( V_2 ) ;
}
static int F_131 ( struct V_1 * V_2 )
{
struct V_9 * V_10 ;
struct V_39 * V_41 = F_37 ( V_2 ) ;
F_132 () ;
F_133 ( & V_41 -> V_85 ) ;
F_118 () ;
if ( ! F_2 ( V_2 -> V_34 ) ) {
F_134 ( & V_41 -> V_85 ) ;
return 0 ;
}
F_2 ( V_2 -> V_34 ) = 0 ;
if ( F_51 ( F_1 ( V_2 ) ) ) {
F_134 ( & V_41 -> V_85 ) ;
return 0 ;
}
F_89 ( V_2 ) ;
F_135 ( & V_2 -> V_4 , V_2 -> V_4 + 1 ) ;
F_5 ( V_2 -> V_23 , V_2 -> V_4 , F_6 ( L_36 ) ) ;
F_134 ( & V_41 -> V_85 ) ;
F_136 ( & V_2 -> V_110 ) ;
F_118 () ;
F_137 (rsp, rnp) {
F_133 ( & V_41 -> V_85 ) ;
F_118 () ;
V_10 = F_16 ( V_2 -> V_15 ) ;
F_138 ( V_41 ) ;
V_41 -> V_86 = V_41 -> V_68 ;
F_2 ( V_41 -> V_4 ) = V_2 -> V_4 ;
F_51 ( V_41 -> V_3 != V_2 -> V_3 ) ;
F_2 ( V_41 -> V_3 ) = V_2 -> V_3 ;
if ( V_41 == V_10 -> V_17 )
( void ) F_127 ( V_2 , V_41 , V_10 ) ;
F_139 ( V_41 ) ;
F_140 ( V_2 -> V_23 , V_41 -> V_4 ,
V_41 -> V_101 , V_41 -> V_88 ,
V_41 -> V_87 , V_41 -> V_86 ) ;
F_134 ( & V_41 -> V_85 ) ;
F_141 () ;
}
F_142 ( & V_2 -> V_110 ) ;
return 1 ;
}
static int F_143 ( struct V_1 * V_2 , int V_111 )
{
int V_112 = V_111 ;
bool V_70 = false ;
unsigned long V_71 ;
struct V_39 * V_41 = F_37 ( V_2 ) ;
V_2 -> V_113 ++ ;
if ( V_112 == V_114 ) {
if ( F_144 ( V_2 ) ) {
V_70 = true ;
V_71 = V_79 - V_97 / 4 ;
}
F_145 ( V_2 , F_78 ,
& V_70 , & V_71 ) ;
F_146 ( V_2 , V_70 , V_71 ) ;
V_112 = V_115 ;
} else {
V_70 = false ;
F_145 ( V_2 , F_82 , & V_70 , & V_71 ) ;
}
if ( F_2 ( V_2 -> V_34 ) & V_116 ) {
F_133 ( & V_41 -> V_85 ) ;
F_118 () ;
F_2 ( V_2 -> V_34 ) =
F_2 ( V_2 -> V_34 ) & ~ V_116 ;
F_134 ( & V_41 -> V_85 ) ;
}
return V_112 ;
}
static void F_147 ( struct V_1 * V_2 )
{
unsigned long V_117 ;
bool V_118 = false ;
int V_119 = 0 ;
struct V_9 * V_10 ;
struct V_39 * V_41 = F_37 ( V_2 ) ;
F_133 ( & V_41 -> V_85 ) ;
F_118 () ;
V_117 = V_79 - V_2 -> V_78 ;
if ( V_117 > V_2 -> V_120 )
V_2 -> V_120 = V_117 ;
F_134 ( & V_41 -> V_85 ) ;
F_137 (rsp, rnp) {
F_133 ( & V_41 -> V_85 ) ;
F_118 () ;
F_2 ( V_41 -> V_3 ) = V_2 -> V_4 ;
V_10 = F_16 ( V_2 -> V_15 ) ;
if ( V_41 == V_10 -> V_17 )
V_118 = F_127 ( V_2 , V_41 , V_10 ) || V_118 ;
V_119 += F_121 ( V_2 , V_41 ) ;
F_134 ( & V_41 -> V_85 ) ;
F_141 () ;
}
V_41 = F_37 ( V_2 ) ;
F_133 ( & V_41 -> V_85 ) ;
F_118 () ;
F_148 ( V_41 , V_119 ) ;
F_2 ( V_2 -> V_3 ) = V_2 -> V_4 ;
F_5 ( V_2 -> V_23 , V_2 -> V_3 , F_6 ( L_37 ) ) ;
V_2 -> V_112 = V_121 ;
V_10 = F_16 ( V_2 -> V_15 ) ;
V_118 = F_126 ( V_2 , V_41 , V_10 ) || V_118 ;
if ( V_118 || F_39 ( V_2 , V_10 ) ) {
F_2 ( V_2 -> V_34 ) = V_122 ;
F_5 ( V_2 -> V_23 ,
F_2 ( V_2 -> V_4 ) ,
F_6 ( L_38 ) ) ;
}
F_134 ( & V_41 -> V_85 ) ;
}
static int T_3 F_149 ( void * V_123 )
{
int V_112 ;
int V_124 ;
unsigned long V_83 ;
int V_66 ;
struct V_1 * V_2 = V_123 ;
struct V_39 * V_41 = F_37 ( V_2 ) ;
for (; ; ) {
for (; ; ) {
F_5 ( V_2 -> V_23 ,
F_2 ( V_2 -> V_4 ) ,
F_6 ( L_39 ) ) ;
V_2 -> V_24 = V_125 ;
F_150 ( V_2 -> V_107 ,
F_2 ( V_2 -> V_34 ) &
V_122 ) ;
if ( F_131 ( V_2 ) )
break;
F_141 () ;
F_151 ( F_152 ( V_53 ) ) ;
F_5 ( V_2 -> V_23 ,
F_2 ( V_2 -> V_4 ) ,
F_6 ( L_40 ) ) ;
}
V_112 = V_114 ;
V_83 = V_126 ;
if ( V_83 > V_127 ) {
V_83 = V_127 ;
V_126 = V_127 ;
}
V_66 = 0 ;
for (; ; ) {
if ( ! V_66 )
V_2 -> V_128 = V_79 + V_83 ;
F_5 ( V_2 -> V_23 ,
F_2 ( V_2 -> V_4 ) ,
F_6 ( L_41 ) ) ;
V_2 -> V_24 = V_129 ;
V_66 = F_153 ( V_2 -> V_107 ,
( ( V_124 = F_2 ( V_2 -> V_34 ) ) &
V_116 ) ||
( ! F_2 ( V_41 -> V_86 ) &&
! F_154 ( V_41 ) ) ,
V_83 ) ;
if ( ! F_2 ( V_41 -> V_86 ) &&
! F_154 ( V_41 ) )
break;
if ( F_84 ( V_79 , V_2 -> V_128 ) ||
( V_124 & V_116 ) ) {
F_5 ( V_2 -> V_23 ,
F_2 ( V_2 -> V_4 ) ,
F_6 ( L_42 ) ) ;
V_112 = F_143 ( V_2 , V_112 ) ;
F_5 ( V_2 -> V_23 ,
F_2 ( V_2 -> V_4 ) ,
F_6 ( L_43 ) ) ;
F_141 () ;
} else {
F_141 () ;
F_151 ( F_152 ( V_53 ) ) ;
F_5 ( V_2 -> V_23 ,
F_2 ( V_2 -> V_4 ) ,
F_6 ( L_44 ) ) ;
}
V_83 = V_130 ;
if ( V_83 > V_127 ) {
V_83 = V_127 ;
V_130 = V_127 ;
} else if ( V_83 < 1 ) {
V_83 = 1 ;
V_130 = 1 ;
}
}
F_147 ( V_2 ) ;
}
}
static bool
F_119 ( struct V_1 * V_2 , struct V_39 * V_41 ,
struct V_9 * V_10 )
{
if ( ! V_2 -> V_25 || ! F_39 ( V_2 , V_10 ) ) {
return false ;
}
F_2 ( V_2 -> V_34 ) = V_122 ;
F_5 ( V_2 -> V_23 , F_2 ( V_2 -> V_4 ) ,
F_6 ( L_38 ) ) ;
return true ;
}
static bool F_155 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_16 ( V_2 -> V_15 ) ;
struct V_39 * V_41 = F_37 ( V_2 ) ;
bool V_66 = false ;
V_66 = F_126 ( V_2 , V_41 , V_10 ) || V_66 ;
V_66 = F_119 ( V_2 , V_41 , V_10 ) || V_66 ;
return V_66 ;
}
static void F_156 ( struct V_1 * V_2 , unsigned long V_8 )
__releases( rcu_get_root( V_2 )->lock
static void
F_157 ( unsigned long V_131 , struct V_1 * V_2 ,
struct V_39 * V_41 , unsigned long V_8 )
__releases( V_41 -> V_85 )
{
struct V_39 * V_132 ;
for (; ; ) {
if ( ! ( V_41 -> V_86 & V_131 ) ) {
F_96 ( & V_41 -> V_85 , V_8 ) ;
return;
}
V_41 -> V_86 &= ~ V_131 ;
F_158 ( V_2 -> V_23 , V_41 -> V_4 ,
V_131 , V_41 -> V_86 , V_41 -> V_101 ,
V_41 -> V_88 , V_41 -> V_87 ,
! ! V_41 -> V_133 ) ;
if ( V_41 -> V_86 != 0 || F_154 ( V_41 ) ) {
F_96 ( & V_41 -> V_85 , V_8 ) ;
return;
}
V_131 = V_41 -> V_67 ;
if ( V_41 -> V_134 == NULL ) {
break;
}
F_96 ( & V_41 -> V_85 , V_8 ) ;
V_132 = V_41 ;
V_41 = V_41 -> V_134 ;
F_94 ( & V_41 -> V_85 , V_8 ) ;
F_118 () ;
F_51 ( V_132 -> V_86 ) ;
}
F_156 ( V_2 , V_8 ) ;
}
static void
F_159 ( int V_73 , struct V_1 * V_2 , struct V_9 * V_10 )
{
unsigned long V_8 ;
unsigned long V_131 ;
bool V_109 ;
struct V_39 * V_41 ;
V_41 = V_10 -> V_17 ;
F_94 ( & V_41 -> V_85 , V_8 ) ;
F_118 () ;
if ( V_10 -> V_6 == 0 || V_10 -> V_4 != V_41 -> V_4 ||
V_41 -> V_3 == V_41 -> V_4 ) {
V_10 -> V_6 = 0 ;
F_96 ( & V_41 -> V_85 , V_8 ) ;
return;
}
V_131 = V_10 -> V_67 ;
if ( ( V_41 -> V_86 & V_131 ) == 0 ) {
F_96 ( & V_41 -> V_85 , V_8 ) ;
} else {
V_10 -> V_108 = 0 ;
V_109 = F_125 ( V_2 , V_41 , V_10 ) ;
F_157 ( V_131 , V_2 , V_41 , V_8 ) ;
if ( V_109 )
F_123 ( V_2 ) ;
}
}
static void
F_160 ( struct V_1 * V_2 , struct V_9 * V_10 )
{
F_129 ( V_2 , V_10 ) ;
if ( ! V_10 -> V_108 )
return;
if ( ! V_10 -> V_6 )
return;
F_159 ( V_10 -> V_73 , V_2 , V_10 ) ;
}
static void
F_161 ( int V_73 , struct V_1 * V_2 ,
struct V_39 * V_41 , struct V_9 * V_10 )
{
if ( F_162 ( V_10 -> V_73 ) )
return;
if ( V_10 -> V_36 != NULL ) {
V_2 -> V_135 += V_10 -> V_135 ;
V_2 -> V_93 += V_10 -> V_93 ;
V_10 -> V_136 += V_10 -> V_93 ;
V_10 -> V_135 = 0 ;
F_2 ( V_10 -> V_93 ) = 0 ;
}
if ( * V_10 -> V_37 [ V_38 ] != NULL ) {
* V_2 -> V_137 = * V_10 -> V_37 [ V_38 ] ;
V_2 -> V_137 = V_10 -> V_37 [ V_46 ] ;
* V_10 -> V_37 [ V_38 ] = NULL ;
}
if ( V_10 -> V_36 != NULL ) {
* V_2 -> V_138 = V_10 -> V_36 ;
V_2 -> V_138 = V_10 -> V_37 [ V_38 ] ;
}
F_111 ( V_10 ) ;
}
static void F_163 ( struct V_1 * V_2 , unsigned long V_8 )
{
int V_45 ;
struct V_9 * V_10 = F_14 ( V_2 -> V_15 ) ;
if ( F_164 ( V_2 , V_10 , V_8 ) )
return;
V_10 -> V_135 += V_2 -> V_135 ;
V_10 -> V_93 += V_2 -> V_93 ;
V_10 -> V_139 += V_2 -> V_93 ;
if ( V_2 -> V_135 != V_2 -> V_93 )
F_165 () ;
V_2 -> V_135 = 0 ;
V_2 -> V_93 = 0 ;
if ( V_2 -> V_140 != NULL ) {
* V_2 -> V_138 = * V_10 -> V_37 [ V_38 ] ;
* V_10 -> V_37 [ V_38 ] = V_2 -> V_140 ;
for ( V_45 = V_98 - 1 ; V_45 >= V_38 ; V_45 -- )
if ( V_10 -> V_37 [ V_45 ] == V_10 -> V_37 [ V_38 ] )
V_10 -> V_37 [ V_45 ] = V_2 -> V_138 ;
V_2 -> V_140 = NULL ;
V_2 -> V_138 = & V_2 -> V_140 ;
}
if ( V_2 -> V_141 != NULL ) {
* V_10 -> V_37 [ V_46 ] = V_2 -> V_141 ;
V_10 -> V_37 [ V_46 ] = V_2 -> V_137 ;
V_2 -> V_141 = NULL ;
V_2 -> V_137 = & V_2 -> V_141 ;
}
}
static void F_166 ( struct V_1 * V_2 )
{
F_167 (unsigned long mask) ;
F_167 ( struct V_9 * V_10 = F_16 ( V_2 -> V_15 ) ) ;
F_167 ( struct V_39 * V_41 = V_10 -> V_17 ) ;
F_167 ( V_131 = V_10 -> V_67 ) ;
F_5 ( V_2 -> V_23 ,
V_41 -> V_4 + 1 - ! ! ( V_41 -> V_86 & V_131 ) ,
F_6 ( L_45 ) ) ;
}
static void F_168 ( int V_73 , struct V_1 * V_2 )
{
unsigned long V_8 ;
unsigned long V_131 ;
int V_142 = 0 ;
struct V_9 * V_10 = F_104 ( V_2 -> V_15 , V_73 ) ;
struct V_39 * V_41 = V_10 -> V_17 ;
F_169 ( V_41 , - 1 ) ;
F_136 ( & V_2 -> V_110 ) ;
F_94 ( & V_2 -> V_143 , V_8 ) ;
F_161 ( V_73 , V_2 , V_41 , V_10 ) ;
F_163 ( V_2 , V_8 ) ;
V_131 = V_10 -> V_67 ;
do {
F_117 ( & V_41 -> V_85 ) ;
F_118 () ;
V_41 -> V_68 &= ~ V_131 ;
if ( V_41 -> V_68 != 0 ) {
if ( V_41 != V_10 -> V_17 )
F_120 ( & V_41 -> V_85 ) ;
break;
}
if ( V_41 == V_10 -> V_17 )
V_142 = F_170 ( V_2 , V_41 , V_10 ) ;
else
F_120 ( & V_41 -> V_85 ) ;
V_131 = V_41 -> V_67 ;
V_41 = V_41 -> V_134 ;
} while ( V_41 != NULL );
F_120 ( & V_2 -> V_143 ) ;
V_41 = V_10 -> V_17 ;
if ( V_142 & V_144 )
F_171 ( V_41 , V_8 ) ;
else
F_96 ( & V_41 -> V_85 , V_8 ) ;
if ( V_142 & V_145 )
F_172 ( V_2 , V_41 , true ) ;
F_47 ( V_10 -> V_93 != 0 || V_10 -> V_36 != NULL ,
L_46 ,
V_73 , V_10 -> V_93 , V_10 -> V_36 ) ;
F_111 ( V_10 ) ;
V_10 -> V_37 [ V_46 ] = NULL ;
F_142 ( & V_2 -> V_110 ) ;
}
static void F_166 ( struct V_1 * V_2 )
{
}
static void F_168 ( int V_73 , struct V_1 * V_2 )
{
}
static void F_173 ( struct V_1 * V_2 , struct V_9 * V_10 )
{
unsigned long V_8 ;
struct V_146 * V_147 , * V_148 , * * V_149 ;
long V_150 , V_151 , V_152 ;
int V_45 ;
if ( ! F_36 ( V_10 ) ) {
F_174 ( V_2 -> V_23 , V_10 -> V_135 , V_10 -> V_93 , 0 ) ;
F_175 ( V_2 -> V_23 , 0 , ! ! F_2 ( V_10 -> V_36 ) ,
F_176 () , F_43 ( V_53 ) ,
F_177 () ) ;
return;
}
F_10 ( V_8 ) ;
F_51 ( F_86 ( F_45 () ) ) ;
V_150 = V_10 -> V_153 ;
F_174 ( V_2 -> V_23 , V_10 -> V_135 , V_10 -> V_93 , V_150 ) ;
V_148 = V_10 -> V_36 ;
V_10 -> V_36 = * V_10 -> V_37 [ V_38 ] ;
* V_10 -> V_37 [ V_38 ] = NULL ;
V_149 = V_10 -> V_37 [ V_38 ] ;
for ( V_45 = V_98 - 1 ; V_45 >= 0 ; V_45 -- )
if ( V_10 -> V_37 [ V_45 ] == V_10 -> V_37 [ V_38 ] )
V_10 -> V_37 [ V_45 ] = & V_10 -> V_36 ;
F_20 ( V_8 ) ;
V_151 = V_152 = 0 ;
while ( V_148 ) {
V_147 = V_148 -> V_147 ;
F_178 ( V_147 ) ;
F_179 ( V_148 ) ;
if ( F_180 ( V_2 -> V_23 , V_148 ) )
V_152 ++ ;
V_148 = V_147 ;
if ( ++ V_151 >= V_150 &&
( F_176 () ||
( ! F_43 ( V_53 ) && ! F_177 () ) ) )
break;
}
F_10 ( V_8 ) ;
F_175 ( V_2 -> V_23 , V_151 , ! ! V_148 , F_176 () ,
F_43 ( V_53 ) ,
F_177 () ) ;
if ( V_148 != NULL ) {
* V_149 = V_10 -> V_36 ;
V_10 -> V_36 = V_148 ;
for ( V_45 = 0 ; V_45 < V_98 ; V_45 ++ )
if ( & V_10 -> V_36 == V_10 -> V_37 [ V_45 ] )
V_10 -> V_37 [ V_45 ] = V_149 ;
else
break;
}
F_15 () ;
V_10 -> V_135 -= V_152 ;
F_2 ( V_10 -> V_93 ) = V_10 -> V_93 - V_151 ;
V_10 -> V_154 += V_151 ;
if ( V_10 -> V_153 == V_155 && V_10 -> V_93 <= V_156 )
V_10 -> V_153 = V_153 ;
if ( V_10 -> V_93 == 0 && V_10 -> V_157 != 0 ) {
V_10 -> V_157 = 0 ;
V_10 -> V_158 = V_2 -> V_113 ;
} else if ( V_10 -> V_93 < V_10 -> V_157 - V_159 )
V_10 -> V_157 = V_10 -> V_93 ;
F_51 ( ( V_10 -> V_36 == NULL ) != ( V_10 -> V_93 == 0 ) ) ;
F_20 ( V_8 ) ;
if ( F_36 ( V_10 ) )
F_181 () ;
}
void F_182 ( int V_51 )
{
F_22 ( F_6 ( L_47 ) ) ;
F_183 () ;
if ( V_51 || F_77 () ) {
F_3 () ;
F_8 () ;
} else if ( ! F_184 () ) {
F_8 () ;
}
F_185 () ;
if ( F_186 () )
F_181 () ;
if ( V_51 )
F_187 ( V_53 ) ;
F_22 ( F_6 ( L_48 ) ) ;
}
static void F_145 ( struct V_1 * V_2 ,
int (* F_188)( struct V_9 * V_2 , bool * V_70 ,
unsigned long * V_71 ) ,
bool * V_70 , unsigned long * V_71 )
{
unsigned long V_160 ;
int V_73 ;
unsigned long V_8 ;
unsigned long V_131 ;
struct V_39 * V_41 ;
F_93 (rsp, rnp) {
F_141 () ;
V_131 = 0 ;
F_94 ( & V_41 -> V_85 , V_8 ) ;
F_118 () ;
if ( ! F_1 ( V_2 ) ) {
F_96 ( & V_41 -> V_85 , V_8 ) ;
return;
}
if ( V_41 -> V_86 == 0 ) {
F_189 ( V_41 , V_8 ) ;
continue;
}
V_73 = V_41 -> V_88 ;
V_160 = 1 ;
for (; V_73 <= V_41 -> V_87 ; V_73 ++ , V_160 <<= 1 ) {
if ( ( V_41 -> V_86 & V_160 ) != 0 ) {
if ( ( V_41 -> V_68 & V_160 ) != 0 )
* V_70 = false ;
if ( F_188 ( F_104 ( V_2 -> V_15 , V_73 ) , V_70 , V_71 ) )
V_131 |= V_160 ;
}
}
if ( V_131 != 0 ) {
F_157 ( V_131 , V_2 , V_41 , V_8 ) ;
continue;
}
F_96 ( & V_41 -> V_85 , V_8 ) ;
}
V_41 = F_37 ( V_2 ) ;
if ( V_41 -> V_86 == 0 ) {
F_94 ( & V_41 -> V_85 , V_8 ) ;
F_118 () ;
F_189 ( V_41 , V_8 ) ;
}
}
static void F_28 ( struct V_1 * V_2 )
{
unsigned long V_8 ;
bool V_66 ;
struct V_39 * V_41 ;
struct V_39 * V_161 = NULL ;
V_41 = F_4 ( V_2 -> V_15 -> V_17 ) ;
for (; V_41 != NULL ; V_41 = V_41 -> V_134 ) {
V_66 = ( F_2 ( V_2 -> V_34 ) & V_116 ) ||
! F_130 ( & V_41 -> V_162 ) ;
if ( V_161 != NULL )
F_120 ( & V_161 -> V_162 ) ;
if ( V_66 ) {
V_2 -> V_163 ++ ;
return;
}
V_161 = V_41 ;
}
F_94 ( & V_161 -> V_85 , V_8 ) ;
F_118 () ;
F_120 ( & V_161 -> V_162 ) ;
if ( F_2 ( V_2 -> V_34 ) & V_116 ) {
V_2 -> V_163 ++ ;
F_96 ( & V_161 -> V_85 , V_8 ) ;
return;
}
F_2 ( V_2 -> V_34 ) =
F_2 ( V_2 -> V_34 ) | V_116 ;
F_96 ( & V_161 -> V_85 , V_8 ) ;
F_123 ( V_2 ) ;
}
static void
F_190 ( struct V_1 * V_2 )
{
unsigned long V_8 ;
bool V_109 ;
struct V_9 * V_10 = F_14 ( V_2 -> V_15 ) ;
F_51 ( V_10 -> V_164 == 0 ) ;
F_160 ( V_2 , V_10 ) ;
F_10 ( V_8 ) ;
if ( F_39 ( V_2 , V_10 ) ) {
F_117 ( & F_37 ( V_2 ) -> V_85 ) ;
V_109 = F_155 ( V_2 ) ;
F_96 ( & F_37 ( V_2 ) -> V_85 , V_8 ) ;
if ( V_109 )
F_123 ( V_2 ) ;
} else {
F_20 ( V_8 ) ;
}
if ( F_36 ( V_10 ) )
F_191 ( V_2 , V_10 ) ;
F_48 ( V_10 ) ;
}
static void F_192 ( struct V_165 * V_166 )
{
struct V_1 * V_2 ;
if ( F_86 ( F_45 () ) )
return;
F_22 ( F_6 ( L_49 ) ) ;
F_13 (rsp)
F_190 ( V_2 ) ;
F_22 ( F_6 ( L_50 ) ) ;
}
static void F_191 ( struct V_1 * V_2 , struct V_9 * V_10 )
{
if ( F_24 ( ! F_2 ( V_69 ) ) )
return;
if ( F_193 ( ! V_2 -> V_167 ) ) {
F_173 ( V_2 , V_10 ) ;
return;
}
F_194 () ;
}
static void F_181 ( void )
{
if ( F_195 ( F_45 () ) )
F_196 ( V_168 ) ;
}
static void F_197 ( struct V_1 * V_2 , struct V_9 * V_10 ,
struct V_146 * V_169 , unsigned long V_8 )
{
bool V_109 ;
if ( ! F_72 () && F_195 ( F_45 () ) )
F_181 () ;
if ( F_198 ( V_8 ) || F_86 ( F_45 () ) )
return;
if ( F_24 ( V_10 -> V_93 > V_10 -> V_157 + V_159 ) ) {
F_129 ( V_2 , V_10 ) ;
if ( ! F_1 ( V_2 ) ) {
struct V_39 * V_103 = F_37 ( V_2 ) ;
F_117 ( & V_103 -> V_85 ) ;
F_118 () ;
V_109 = F_155 ( V_2 ) ;
F_120 ( & V_103 -> V_85 ) ;
if ( V_109 )
F_123 ( V_2 ) ;
} else {
V_10 -> V_153 = V_155 ;
if ( V_2 -> V_113 == V_10 -> V_158 &&
* V_10 -> V_37 [ V_38 ] != V_169 )
F_28 ( V_2 ) ;
V_10 -> V_158 = V_2 -> V_113 ;
V_10 -> V_157 = V_10 -> V_93 ;
}
}
}
static void F_199 ( struct V_146 * V_170 )
{
}
static void
F_200 ( struct V_146 * V_169 , void (* F_201)( struct V_146 * V_171 ) ,
struct V_1 * V_2 , int V_73 , bool V_172 )
{
unsigned long V_8 ;
struct V_9 * V_10 ;
F_51 ( ( unsigned long ) V_169 & 0x1 ) ;
if ( F_202 ( V_169 ) ) {
F_2 ( V_169 -> F_201 ) = F_199 ;
F_47 ( 1 , L_51 ) ;
return;
}
V_169 -> F_201 = F_201 ;
V_169 -> V_147 = NULL ;
F_10 ( V_8 ) ;
V_10 = F_16 ( V_2 -> V_15 ) ;
if ( F_24 ( V_10 -> V_37 [ V_46 ] == NULL ) || V_73 != - 1 ) {
int V_173 ;
if ( V_73 != - 1 )
V_10 = F_104 ( V_2 -> V_15 , V_73 ) ;
V_173 = ! F_203 ( V_10 , V_169 , V_172 , V_8 ) ;
F_51 ( V_173 ) ;
F_20 ( V_8 ) ;
return;
}
F_2 ( V_10 -> V_93 ) = V_10 -> V_93 + 1 ;
if ( V_172 )
V_10 -> V_135 ++ ;
else
F_165 () ;
F_15 () ;
* V_10 -> V_37 [ V_46 ] = V_169 ;
V_10 -> V_37 [ V_46 ] = & V_169 -> V_147 ;
if ( F_204 ( ( unsigned long ) F_201 ) )
F_205 ( V_2 -> V_23 , V_169 , ( unsigned long ) F_201 ,
V_10 -> V_135 , V_10 -> V_93 ) ;
else
F_206 ( V_2 -> V_23 , V_169 , V_10 -> V_135 , V_10 -> V_93 ) ;
F_197 ( V_2 , V_10 , V_169 , V_8 ) ;
F_20 ( V_8 ) ;
}
void F_207 ( struct V_146 * V_169 , void (* F_201)( struct V_146 * V_171 ) )
{
F_200 ( V_169 , F_201 , & V_20 , - 1 , 0 ) ;
}
void F_208 ( struct V_146 * V_169 , void (* F_201)( struct V_146 * V_171 ) )
{
F_200 ( V_169 , F_201 , & V_21 , - 1 , 0 ) ;
}
void F_209 ( struct V_146 * V_169 ,
void (* F_201)( struct V_146 * V_171 ) )
{
F_200 ( V_169 , F_201 , V_22 , - 1 , 1 ) ;
}
static inline int F_210 ( void )
{
int V_66 ;
F_211 () ;
F_73 () ;
V_66 = F_212 () <= 1 ;
F_74 () ;
return V_66 ;
}
void F_213 ( void )
{
F_54 ( ! F_55 ( & V_60 ) &&
! F_55 ( & V_59 ) &&
! F_55 ( & V_61 ) ,
L_52 ) ;
if ( F_210 () )
return;
if ( V_174 )
F_214 () ;
else
F_215 ( F_207 ) ;
}
void F_216 ( void )
{
F_54 ( ! F_55 ( & V_60 ) &&
! F_55 ( & V_59 ) &&
! F_55 ( & V_61 ) ,
L_53 ) ;
if ( F_210 () )
return;
if ( V_174 )
F_217 () ;
else
F_215 ( F_208 ) ;
}
unsigned long F_218 ( void )
{
F_15 () ;
return F_219 ( & V_22 -> V_4 ) ;
}
void F_220 ( unsigned long V_175 )
{
unsigned long V_176 ;
V_176 = F_219 ( & V_22 -> V_3 ) ;
if ( F_84 ( V_175 , V_176 ) )
F_221 () ;
}
static int F_222 ( void * V_177 )
{
F_15 () ;
return 0 ;
}
void F_214 ( void )
{
T_4 V_178 ;
bool V_179 = false ;
int V_73 ;
long V_180 , V_100 , V_76 ;
int V_181 = 0 ;
struct V_1 * V_2 = & V_20 ;
if ( F_84 ( ( V_182 ) F_223 ( & V_2 -> V_183 ) ,
( V_182 ) F_223 ( & V_2 -> V_184 ) +
V_97 / 8 ) ) {
F_213 () ;
F_224 ( & V_2 -> V_185 ) ;
return;
}
V_76 = F_225 ( & V_2 -> V_183 ) ;
V_180 = V_76 ;
if ( ! F_226 () ) {
F_215 ( F_207 ) ;
F_224 ( & V_2 -> V_186 ) ;
return;
}
F_51 ( F_86 ( F_227 () ) ) ;
V_179 = F_228 ( & V_178 , V_187 ) ;
if ( V_179 ) {
F_229 ( V_178 , V_188 ) ;
F_230 ( F_227 () , V_178 ) ;
F_231 (cpu, cm) {
struct V_11 * V_12 = & F_87 ( V_11 , V_73 ) ;
if ( ! ( F_79 ( 0 , & V_12 -> V_19 ) & 0x1 ) )
F_230 ( V_73 , V_178 ) ;
}
if ( F_232 ( V_178 ) == 0 )
goto V_189;
}
while ( F_233 ( V_179 ? V_178 : V_188 ,
F_222 ,
NULL ) == - V_190 ) {
F_234 () ;
F_224 ( & V_2 -> V_191 ) ;
V_100 = F_223 ( & V_2 -> V_184 ) ;
if ( F_84 ( ( V_182 ) V_100 , ( V_182 ) V_180 ) ) {
F_17 () ;
F_224 ( & V_2 -> V_192 ) ;
F_235 ( V_178 ) ;
return;
}
if ( V_181 ++ < 10 ) {
F_236 ( V_181 * F_212 () ) ;
} else {
F_215 ( F_207 ) ;
F_224 ( & V_2 -> V_186 ) ;
F_235 ( V_178 ) ;
return;
}
V_100 = F_223 ( & V_2 -> V_184 ) ;
if ( F_84 ( ( V_182 ) V_100 , ( V_182 ) V_180 ) ) {
F_17 () ;
F_224 ( & V_2 -> V_193 ) ;
F_235 ( V_178 ) ;
return;
}
if ( ! F_226 () ) {
F_215 ( F_207 ) ;
F_224 ( & V_2 -> V_186 ) ;
F_235 ( V_178 ) ;
return;
}
V_76 = F_223 ( & V_2 -> V_183 ) ;
F_15 () ;
}
F_224 ( & V_2 -> V_194 ) ;
V_189:
F_235 ( V_178 ) ;
do {
F_224 ( & V_2 -> V_195 ) ;
V_100 = F_223 ( & V_2 -> V_184 ) ;
if ( F_84 ( ( V_182 ) V_100 , ( V_182 ) V_76 ) ) {
F_17 () ;
F_224 ( & V_2 -> V_196 ) ;
break;
}
} while ( F_237 ( & V_2 -> V_184 , V_100 , V_76 ) != V_100 );
F_224 ( & V_2 -> V_197 ) ;
F_234 () ;
}
static int F_238 ( struct V_1 * V_2 , struct V_9 * V_10 )
{
struct V_39 * V_41 = V_10 -> V_17 ;
V_10 -> V_198 ++ ;
F_108 ( V_2 , V_10 ) ;
if ( F_239 ( V_2 ) )
return 0 ;
if ( V_69 &&
V_10 -> V_108 && ! V_10 -> V_6 ) {
V_10 -> V_199 ++ ;
} else if ( V_10 -> V_108 && V_10 -> V_6 ) {
V_10 -> V_200 ++ ;
return 1 ;
}
if ( F_36 ( V_10 ) ) {
V_10 -> V_201 ++ ;
return 1 ;
}
if ( F_39 ( V_2 , V_10 ) ) {
V_10 -> V_202 ++ ;
return 1 ;
}
if ( F_2 ( V_41 -> V_3 ) != V_10 -> V_3 ) {
V_10 -> V_203 ++ ;
return 1 ;
}
if ( F_2 ( V_41 -> V_4 ) != V_10 -> V_4 ) {
V_10 -> V_204 ++ ;
return 1 ;
}
if ( F_240 ( V_10 ) ) {
V_10 -> V_205 ++ ;
return 1 ;
}
V_10 -> V_206 ++ ;
return 0 ;
}
static int F_186 ( void )
{
struct V_1 * V_2 ;
F_13 (rsp)
if ( F_238 ( V_2 , F_16 ( V_2 -> V_15 ) ) )
return 1 ;
return 0 ;
}
static int V_55 F_241 ( bool * V_207 )
{
bool V_208 = true ;
bool V_209 = false ;
struct V_9 * V_10 ;
struct V_1 * V_2 ;
F_13 (rsp) {
V_10 = F_16 ( V_2 -> V_15 ) ;
if ( ! V_10 -> V_36 )
continue;
V_209 = true ;
if ( V_10 -> V_93 != V_10 -> V_135 || ! V_207 ) {
V_208 = false ;
break;
}
}
if ( V_207 )
* V_207 = V_208 ;
return V_209 ;
}
static void F_242 ( struct V_1 * V_2 , const char * V_100 ,
int V_73 , unsigned long V_210 )
{
F_243 ( V_2 -> V_23 , V_100 , V_73 ,
F_52 ( & V_2 -> V_211 ) , V_210 ) ;
}
static void F_244 ( struct V_146 * V_170 )
{
struct V_9 * V_10 = F_245 ( V_170 , struct V_9 , V_212 ) ;
struct V_1 * V_2 = V_10 -> V_2 ;
if ( F_246 ( & V_2 -> V_211 ) ) {
F_242 ( V_2 , L_54 , - 1 , V_2 -> V_213 ) ;
F_247 ( & V_2 -> V_214 ) ;
} else {
F_242 ( V_2 , L_55 , - 1 , V_2 -> V_213 ) ;
}
}
static void F_248 ( void * type )
{
struct V_1 * V_2 = type ;
struct V_9 * V_10 = F_14 ( V_2 -> V_15 ) ;
F_242 ( V_2 , L_56 , - 1 , V_2 -> V_213 ) ;
F_50 ( & V_2 -> V_211 ) ;
V_2 -> V_215 ( & V_10 -> V_212 , F_244 ) ;
}
static void F_249 ( struct V_1 * V_2 )
{
int V_73 ;
struct V_9 * V_10 ;
unsigned long V_76 = F_2 ( V_2 -> V_213 ) ;
unsigned long V_216 ;
F_242 ( V_2 , L_57 , - 1 , V_76 ) ;
F_136 ( & V_2 -> V_217 ) ;
F_15 () ;
V_216 = V_2 -> V_213 ;
F_242 ( V_2 , L_58 , - 1 , V_216 ) ;
if ( F_84 ( V_216 , ( V_76 + 3 ) & ~ 0x1 ) ) {
F_242 ( V_2 , L_59 , - 1 , V_216 ) ;
F_15 () ;
F_142 ( & V_2 -> V_217 ) ;
return;
}
F_2 ( V_2 -> V_213 ) = V_2 -> V_213 + 1 ;
F_51 ( ( V_2 -> V_213 & 0x1 ) != 1 ) ;
F_242 ( V_2 , L_60 , - 1 , V_2 -> V_213 ) ;
F_15 () ;
F_250 ( & V_2 -> V_214 ) ;
F_251 ( & V_2 -> V_211 , 1 ) ;
F_252 () ;
F_103 (cpu) {
if ( ! F_195 ( V_73 ) && ! F_162 ( V_73 ) )
continue;
V_10 = F_104 ( V_2 -> V_15 , V_73 ) ;
if ( F_162 ( V_73 ) ) {
if ( ! F_253 ( V_2 , V_73 ) ) {
F_242 ( V_2 , L_61 , V_73 ,
V_2 -> V_213 ) ;
} else {
F_242 ( V_2 , L_62 , V_73 ,
V_2 -> V_213 ) ;
F_50 ( & V_2 -> V_211 ) ;
F_200 ( & V_10 -> V_212 ,
F_244 , V_2 , V_73 , 0 ) ;
}
} else if ( F_2 ( V_10 -> V_93 ) ) {
F_242 ( V_2 , L_63 , V_73 ,
V_2 -> V_213 ) ;
F_254 ( V_73 , F_248 , V_2 , 1 ) ;
} else {
F_242 ( V_2 , L_64 , V_73 ,
V_2 -> V_213 ) ;
}
}
F_234 () ;
if ( F_246 ( & V_2 -> V_211 ) )
F_247 ( & V_2 -> V_214 ) ;
F_15 () ;
F_2 ( V_2 -> V_213 ) = V_2 -> V_213 + 1 ;
F_51 ( ( V_2 -> V_213 & 0x1 ) != 0 ) ;
F_242 ( V_2 , L_65 , - 1 , V_2 -> V_213 ) ;
F_15 () ;
F_255 ( & V_2 -> V_214 ) ;
F_142 ( & V_2 -> V_217 ) ;
}
void F_256 ( void )
{
F_249 ( & V_21 ) ;
}
void F_257 ( void )
{
F_249 ( & V_20 ) ;
}
static void T_5
F_258 ( int V_73 , struct V_1 * V_2 )
{
unsigned long V_8 ;
struct V_9 * V_10 = F_104 ( V_2 -> V_15 , V_73 ) ;
struct V_39 * V_41 = F_37 ( V_2 ) ;
F_94 ( & V_41 -> V_85 , V_8 ) ;
V_10 -> V_67 = 1UL << ( V_73 - V_10 -> V_17 -> V_88 ) ;
F_111 ( V_10 ) ;
V_10 -> V_135 = 0 ;
F_2 ( V_10 -> V_93 ) = 0 ;
V_10 -> V_19 = & F_87 ( V_11 , V_73 ) ;
F_51 ( V_10 -> V_19 -> V_52 != V_64 ) ;
F_51 ( F_52 ( & V_10 -> V_19 -> V_19 ) != 1 ) ;
V_10 -> V_73 = V_73 ;
V_10 -> V_2 = V_2 ;
F_259 ( V_10 ) ;
F_96 ( & V_41 -> V_85 , V_8 ) ;
}
static void
F_260 ( int V_73 , struct V_1 * V_2 )
{
unsigned long V_8 ;
unsigned long V_131 ;
struct V_9 * V_10 = F_104 ( V_2 -> V_15 , V_73 ) ;
struct V_39 * V_41 = F_37 ( V_2 ) ;
F_136 ( & V_2 -> V_110 ) ;
F_94 ( & V_41 -> V_85 , V_8 ) ;
V_10 -> V_164 = 1 ;
V_10 -> V_157 = 0 ;
V_10 -> V_158 = V_2 -> V_113 ;
V_10 -> V_153 = V_153 ;
F_111 ( V_10 ) ;
V_10 -> V_19 -> V_52 = V_64 ;
F_261 ( V_10 -> V_19 ) ;
F_251 ( & V_10 -> V_19 -> V_19 ,
( F_52 ( & V_10 -> V_19 -> V_19 ) & ~ 0x1 ) + 1 ) ;
F_120 ( & V_41 -> V_85 ) ;
V_41 = V_10 -> V_17 ;
V_131 = V_10 -> V_67 ;
do {
F_117 ( & V_41 -> V_85 ) ;
V_41 -> V_68 |= V_131 ;
V_131 = V_41 -> V_67 ;
if ( V_41 == V_10 -> V_17 ) {
V_10 -> V_4 = V_41 -> V_3 ;
V_10 -> V_3 = V_41 -> V_3 ;
V_10 -> V_6 = 0 ;
V_10 -> V_108 = 0 ;
F_5 ( V_2 -> V_23 , V_10 -> V_4 , F_6 ( L_66 ) ) ;
}
F_120 ( & V_41 -> V_85 ) ;
V_41 = V_41 -> V_134 ;
} while ( V_41 != NULL && ! ( V_41 -> V_68 & V_131 ) );
F_20 ( V_8 ) ;
F_142 ( & V_2 -> V_110 ) ;
}
static void F_262 ( int V_73 )
{
struct V_1 * V_2 ;
F_13 (rsp)
F_260 ( V_73 , V_2 ) ;
}
static int F_263 ( struct V_218 * V_219 ,
unsigned long V_220 , void * V_221 )
{
long V_73 = ( long ) V_221 ;
struct V_9 * V_10 = F_104 ( V_22 -> V_15 , V_73 ) ;
struct V_39 * V_41 = V_10 -> V_17 ;
struct V_1 * V_2 ;
F_22 ( F_6 ( L_67 ) ) ;
switch ( V_220 ) {
case V_222 :
case V_223 :
F_262 ( V_73 ) ;
F_264 ( V_73 ) ;
F_265 ( V_73 ) ;
break;
case V_224 :
case V_225 :
F_169 ( V_41 , - 1 ) ;
break;
case V_226 :
F_169 ( V_41 , V_73 ) ;
break;
case V_227 :
case V_228 :
F_13 (rsp)
F_166 ( V_2 ) ;
break;
case V_229 :
case V_230 :
case V_231 :
case V_232 :
F_13 (rsp) {
F_168 ( V_73 , V_2 ) ;
F_48 ( F_104 ( V_2 -> V_15 , V_73 ) ) ;
}
break;
default:
break;
}
F_22 ( F_6 ( L_68 ) ) ;
return V_233 ;
}
static int F_266 ( struct V_218 * V_219 ,
unsigned long V_220 , void * V_221 )
{
switch ( V_220 ) {
case V_234 :
case V_235 :
if ( V_236 <= 256 )
V_174 = 1 ;
break;
case V_237 :
case V_238 :
V_174 = 0 ;
break;
default:
break;
}
return V_233 ;
}
static int T_5 F_267 ( void )
{
unsigned long V_8 ;
struct V_39 * V_41 ;
struct V_1 * V_2 ;
struct V_54 * V_239 ;
V_69 = 1 ;
F_13 (rsp) {
V_239 = F_268 ( F_149 , V_2 , L_69 , V_2 -> V_23 ) ;
F_269 ( F_270 ( V_239 ) ) ;
V_41 = F_37 ( V_2 ) ;
F_94 ( & V_41 -> V_85 , V_8 ) ;
V_2 -> V_25 = V_239 ;
F_96 ( & V_41 -> V_85 , V_8 ) ;
}
F_271 () ;
F_272 () ;
return 0 ;
}
void F_273 ( void )
{
F_151 ( F_212 () != 1 ) ;
F_151 ( F_274 () > 0 ) ;
V_240 = 1 ;
}
static void T_5 F_275 ( struct V_1 * V_2 )
{
int V_45 ;
V_2 -> V_241 [ V_242 - 1 ] = V_243 ;
for ( V_45 = V_242 - 2 ; V_45 >= 0 ; V_45 -- )
V_2 -> V_241 [ V_45 ] = V_244 ;
}
static void T_5 F_275 ( struct V_1 * V_2 )
{
int V_245 ;
int V_246 ;
int V_45 ;
V_246 = V_236 ;
for ( V_45 = V_242 - 1 ; V_45 >= 0 ; V_45 -- ) {
V_245 = V_2 -> V_247 [ V_45 ] ;
V_2 -> V_241 [ V_45 ] = ( V_246 + V_245 - 1 ) / V_245 ;
V_246 = V_245 ;
}
}
static void T_5 F_276 ( struct V_1 * V_2 ,
struct V_9 T_6 * V_15 )
{
static const char * const V_248 [] = {
L_70 ,
L_71 ,
L_72 ,
L_73 } ;
static const char * const V_249 [] = {
L_74 ,
L_75 ,
L_76 ,
L_77 } ;
static T_7 V_250 = 0x1 ;
int V_251 = 1 ;
int V_45 ;
int V_83 ;
struct V_39 * V_41 ;
F_277 ( V_252 > F_278 ( V_248 ) ) ;
if ( V_242 > V_253 )
F_279 ( L_78 ) ;
for ( V_45 = 0 ; V_45 < V_242 ; V_45 ++ )
V_2 -> V_247 [ V_45 ] = V_254 [ V_45 ] ;
for ( V_45 = 1 ; V_45 < V_242 ; V_45 ++ )
V_2 -> V_101 [ V_45 ] = V_2 -> V_101 [ V_45 - 1 ] + V_2 -> V_247 [ V_45 - 1 ] ;
F_275 ( V_2 ) ;
V_2 -> V_16 = V_250 ;
V_250 <<= 1 ;
for ( V_45 = V_242 - 1 ; V_45 >= 0 ; V_45 -- ) {
V_251 *= V_2 -> V_241 [ V_45 ] ;
V_41 = V_2 -> V_101 [ V_45 ] ;
for ( V_83 = 0 ; V_83 < V_2 -> V_247 [ V_45 ] ; V_83 ++ , V_41 ++ ) {
F_280 ( & V_41 -> V_85 ) ;
F_281 ( & V_41 -> V_85 ,
& V_255 [ V_45 ] , V_248 [ V_45 ] ) ;
F_280 ( & V_41 -> V_162 ) ;
F_281 ( & V_41 -> V_162 ,
& V_256 [ V_45 ] , V_249 [ V_45 ] ) ;
V_41 -> V_4 = V_2 -> V_4 ;
V_41 -> V_3 = V_2 -> V_3 ;
V_41 -> V_86 = 0 ;
V_41 -> V_68 = 0 ;
V_41 -> V_88 = V_83 * V_251 ;
V_41 -> V_87 = ( V_83 + 1 ) * V_251 - 1 ;
if ( V_41 -> V_87 >= V_236 )
V_41 -> V_87 = V_236 - 1 ;
if ( V_45 == 0 ) {
V_41 -> V_257 = 0 ;
V_41 -> V_67 = 0 ;
V_41 -> V_134 = NULL ;
} else {
V_41 -> V_257 = V_83 % V_2 -> V_241 [ V_45 - 1 ] ;
V_41 -> V_67 = 1UL << V_41 -> V_257 ;
V_41 -> V_134 = V_2 -> V_101 [ V_45 - 1 ] +
V_83 / V_2 -> V_241 [ V_45 - 1 ] ;
}
V_41 -> V_101 = V_45 ;
F_282 ( & V_41 -> V_258 ) ;
F_283 ( V_41 ) ;
}
}
V_2 -> V_15 = V_15 ;
F_284 ( & V_2 -> V_107 ) ;
V_41 = V_2 -> V_101 [ V_242 - 1 ] ;
F_103 (i) {
while ( V_45 > V_41 -> V_87 )
V_41 ++ ;
F_104 ( V_2 -> V_15 , V_45 ) -> V_17 = V_41 ;
F_258 ( V_45 , V_2 ) ;
}
F_285 ( & V_2 -> V_259 , & V_260 ) ;
}
static void T_5 F_286 ( void )
{
V_182 V_261 ;
int V_45 ;
int V_83 ;
int V_262 = V_236 ;
int V_263 [ V_252 + 1 ] ;
V_261 = V_264 + V_236 / V_265 ;
if ( V_126 == V_97 )
V_126 = V_261 ;
if ( V_130 == V_97 )
V_130 = V_261 ;
if ( V_243 == V_266 &&
V_236 == V_267 )
return;
F_31 ( L_79 ,
V_243 , V_236 ) ;
V_263 [ 0 ] = 1 ;
V_263 [ 1 ] = V_243 ;
for ( V_45 = 2 ; V_45 <= V_252 ; V_45 ++ )
V_263 [ V_45 ] = V_263 [ V_45 - 1 ] * V_244 ;
if ( V_243 < V_266 ||
V_243 > sizeof( unsigned long ) * 8 ||
V_262 > V_263 [ V_252 ] ) {
F_151 ( 1 ) ;
return;
}
for ( V_45 = 1 ; V_45 <= V_252 ; V_45 ++ )
if ( V_262 <= V_263 [ V_45 ] ) {
for ( V_83 = 0 ; V_83 <= V_45 ; V_83 ++ )
V_254 [ V_83 ] =
F_287 ( V_262 , V_263 [ V_45 - V_83 ] ) ;
V_242 = V_45 ;
for ( V_83 = V_45 + 1 ; V_83 <= V_252 ; V_83 ++ )
V_254 [ V_83 ] = 0 ;
break;
}
V_268 = 0 ;
for ( V_45 = 0 ; V_45 <= V_252 ; V_45 ++ )
V_268 += V_254 [ V_45 ] ;
V_268 -= V_262 ;
}
void T_5 F_288 ( void )
{
int V_73 ;
F_289 () ;
F_286 () ;
F_276 ( & V_21 , & V_7 ) ;
F_276 ( & V_20 , & V_5 ) ;
F_290 () ;
F_291 ( V_168 , F_192 ) ;
F_292 ( F_263 , 0 ) ;
F_293 ( F_266 , 0 ) ;
F_294 (cpu)
F_263 ( NULL , V_222 , ( void * ) ( long ) V_73 ) ;
F_295 () ;
}
