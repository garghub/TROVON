static int F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_2 -> V_3 ) != F_2 ( V_2 -> V_4 ) ;
}
void F_3 ( int V_5 )
{
struct V_6 * V_7 = & F_4 ( V_8 , V_5 ) ;
if ( V_7 -> V_9 == 0 )
F_5 ( F_6 ( L_1 ) , V_7 -> V_4 , F_6 ( L_2 ) ) ;
V_7 -> V_9 = 1 ;
}
void F_7 ( int V_5 )
{
struct V_6 * V_7 = & F_4 ( V_10 , V_5 ) ;
if ( V_7 -> V_9 == 0 )
F_5 ( F_6 ( L_3 ) , V_7 -> V_4 , F_6 ( L_2 ) ) ;
V_7 -> V_9 = 1 ;
}
static void F_8 ( void )
{
unsigned long V_11 ;
struct V_6 * V_7 ;
struct V_12 * V_13 ;
int V_14 ;
struct V_1 * V_2 ;
F_9 ( V_11 ) ;
V_14 = F_10 ( V_15 ) ;
F_11 ( V_15 , 0 ) ;
F_12 (rsp) {
V_7 = F_13 ( V_2 -> V_16 ) ;
if ( ! ( V_14 & V_2 -> V_17 ) )
continue;
F_14 () ;
if ( F_2 ( V_7 -> V_18 -> V_3 ) !=
F_2 ( V_7 -> V_19 ) )
continue;
V_13 = F_15 ( & V_12 ) ;
F_16 () ;
F_17 ( 2 , & V_13 -> V_20 ) ;
F_18 () ;
break;
}
F_19 ( V_11 ) ;
}
void F_20 ( int V_5 )
{
F_21 ( F_6 ( L_4 ) ) ;
F_3 ( V_5 ) ;
F_22 ( V_5 ) ;
if ( F_23 ( F_10 ( V_15 ) ) )
F_8 () ;
F_21 ( F_6 ( L_5 ) ) ;
}
long F_24 ( void )
{
return V_21 . V_3 ;
}
long F_25 ( void )
{
return V_22 . V_3 ;
}
void F_26 ( void )
{
F_27 ( V_23 ) ;
}
void F_28 ( void )
{
F_27 ( & V_22 ) ;
}
void F_29 ( void )
{
struct V_1 * V_2 ;
F_12 (rsp) {
F_30 ( L_6 ,
V_2 -> V_24 , V_2 -> V_25 , V_2 -> V_26 -> V_27 ) ;
}
}
void F_31 ( void )
{
V_28 ++ ;
V_29 = 0 ;
}
void F_32 ( enum V_30 V_31 , int * V_11 ,
unsigned long * V_4 , unsigned long * V_3 )
{
struct V_1 * V_2 = NULL ;
switch ( V_31 ) {
case V_32 :
V_2 = V_23 ;
break;
case V_33 :
V_2 = & V_22 ;
break;
case V_34 :
V_2 = & V_21 ;
break;
default:
break;
}
if ( V_2 != NULL ) {
* V_11 = F_2 ( V_2 -> V_35 ) ;
* V_4 = F_2 ( V_2 -> V_4 ) ;
* V_3 = F_2 ( V_2 -> V_3 ) ;
return;
}
* V_11 = 0 ;
* V_4 = 0 ;
* V_3 = 0 ;
}
void F_33 ( unsigned long V_36 )
{
V_29 ++ ;
}
void F_34 ( void )
{
F_27 ( & V_21 ) ;
}
static int
F_35 ( struct V_6 * V_7 )
{
return & V_7 -> V_37 != V_7 -> V_38 [ V_39 ] &&
V_7 -> V_38 [ V_39 ] != NULL ;
}
static struct V_40 * F_36 ( struct V_1 * V_2 )
{
return & V_2 -> V_41 [ 0 ] ;
}
static int F_37 ( struct V_1 * V_2 )
{
struct V_40 * V_42 = F_36 ( V_2 ) ;
int V_43 = ( F_2 ( V_42 -> V_3 ) + 1 ) & 0x1 ;
int * V_44 = & V_42 -> V_45 [ V_43 ] ;
return F_2 ( * V_44 ) ;
}
static int
F_38 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
int V_46 ;
if ( F_1 ( V_2 ) )
return 0 ;
if ( F_37 ( V_2 ) )
return 1 ;
if ( ! V_7 -> V_38 [ V_47 ] )
return 0 ;
if ( * V_7 -> V_38 [ V_48 ] )
return 1 ;
for ( V_46 = V_49 ; V_46 < V_47 ; V_46 ++ )
if ( V_7 -> V_38 [ V_46 - 1 ] != V_7 -> V_38 [ V_46 ] &&
F_39 ( F_2 ( V_2 -> V_3 ) ,
V_7 -> V_50 [ V_46 ] ) )
return 1 ;
return 0 ;
}
static void F_40 ( struct V_12 * V_13 , long long V_51 ,
bool V_52 )
{
struct V_1 * V_2 ;
struct V_6 * V_7 ;
F_41 ( F_6 ( L_7 ) , V_51 , V_13 -> V_53 ) ;
if ( ! V_52 && ! F_42 ( V_54 ) ) {
struct V_55 * T_1 V_56 =
F_43 ( F_44 () ) ;
F_41 ( F_6 ( L_8 ) , V_51 , 0 ) ;
F_45 ( V_57 ) ;
F_46 ( 1 , L_9 ,
V_54 -> V_58 , V_54 -> V_59 ,
T_1 -> V_58 , T_1 -> V_59 ) ;
}
F_12 (rsp) {
V_7 = F_15 ( V_2 -> V_16 ) ;
F_47 ( V_7 ) ;
}
F_48 ( F_44 () ) ;
F_16 () ;
F_49 ( & V_13 -> V_20 ) ;
F_18 () ;
F_50 ( F_51 ( & V_13 -> V_20 ) & 0x1 ) ;
F_52 ( ! F_53 ( & V_60 ) ,
L_10 ) ;
F_52 ( ! F_53 ( & V_61 ) ,
L_11 ) ;
F_52 ( ! F_53 ( & V_62 ) ,
L_12 ) ;
}
static void F_54 ( bool V_52 )
{
long long V_51 ;
struct V_12 * V_13 ;
V_13 = F_15 ( & V_12 ) ;
V_51 = V_13 -> V_53 ;
F_50 ( ( V_51 & V_63 ) == 0 ) ;
if ( ( V_51 & V_63 ) == V_64 ) {
V_13 -> V_53 = 0 ;
F_40 ( V_13 , V_51 , V_52 ) ;
} else {
V_13 -> V_53 -= V_64 ;
}
}
void F_55 ( void )
{
unsigned long V_11 ;
F_9 ( V_11 ) ;
F_54 ( false ) ;
F_56 ( F_15 ( & V_12 ) , 0 ) ;
F_19 ( V_11 ) ;
}
void F_57 ( void )
{
F_54 ( 1 ) ;
}
void F_58 ( void )
{
unsigned long V_11 ;
long long V_51 ;
struct V_12 * V_13 ;
F_9 ( V_11 ) ;
V_13 = F_15 ( & V_12 ) ;
V_51 = V_13 -> V_53 ;
V_13 -> V_53 -- ;
F_50 ( V_13 -> V_53 < 0 ) ;
if ( V_13 -> V_53 )
F_41 ( F_6 ( L_13 ) , V_51 , V_13 -> V_53 ) ;
else
F_40 ( V_13 , V_51 , true ) ;
F_56 ( V_13 , 1 ) ;
F_19 ( V_11 ) ;
}
static void F_59 ( struct V_12 * V_13 , long long V_51 ,
int V_52 )
{
F_16 () ;
F_49 ( & V_13 -> V_20 ) ;
F_18 () ;
F_50 ( ! ( F_51 ( & V_13 -> V_20 ) & 0x1 ) ) ;
F_60 ( F_44 () ) ;
F_41 ( F_6 ( L_14 ) , V_51 , V_13 -> V_53 ) ;
if ( ! V_52 && ! F_42 ( V_54 ) ) {
struct V_55 * T_1 V_56 =
F_43 ( F_44 () ) ;
F_41 ( F_6 ( L_15 ) ,
V_51 , V_13 -> V_53 ) ;
F_45 ( V_57 ) ;
F_46 ( 1 , L_9 ,
V_54 -> V_58 , V_54 -> V_59 ,
T_1 -> V_58 , T_1 -> V_59 ) ;
}
}
static void F_61 ( bool V_52 )
{
struct V_12 * V_13 ;
long long V_51 ;
V_13 = F_15 ( & V_12 ) ;
V_51 = V_13 -> V_53 ;
F_50 ( V_51 < 0 ) ;
if ( V_51 & V_63 ) {
V_13 -> V_53 += V_64 ;
} else {
V_13 -> V_53 = V_65 ;
F_59 ( V_13 , V_51 , V_52 ) ;
}
}
void F_62 ( void )
{
unsigned long V_11 ;
F_9 ( V_11 ) ;
F_61 ( false ) ;
F_63 ( F_15 ( & V_12 ) , 0 ) ;
F_19 ( V_11 ) ;
}
void F_64 ( void )
{
F_61 ( 1 ) ;
}
void F_65 ( void )
{
unsigned long V_11 ;
struct V_12 * V_13 ;
long long V_51 ;
F_9 ( V_11 ) ;
V_13 = F_15 ( & V_12 ) ;
V_51 = V_13 -> V_53 ;
V_13 -> V_53 ++ ;
F_50 ( V_13 -> V_53 == 0 ) ;
if ( V_51 )
F_41 ( F_6 ( L_16 ) , V_51 , V_13 -> V_53 ) ;
else
F_59 ( V_13 , V_51 , true ) ;
F_63 ( V_13 , 1 ) ;
F_19 ( V_11 ) ;
}
void F_66 ( void )
{
struct V_12 * V_13 = F_15 ( & V_12 ) ;
if ( V_13 -> V_66 == 0 &&
( F_51 ( & V_13 -> V_20 ) & 0x1 ) )
return;
V_13 -> V_66 ++ ;
F_16 () ;
F_49 ( & V_13 -> V_20 ) ;
F_18 () ;
F_50 ( ! ( F_51 ( & V_13 -> V_20 ) & 0x1 ) ) ;
}
void F_67 ( void )
{
struct V_12 * V_13 = F_15 ( & V_12 ) ;
if ( V_13 -> V_66 == 0 ||
-- V_13 -> V_66 != 0 )
return;
F_16 () ;
F_49 ( & V_13 -> V_20 ) ;
F_18 () ;
F_50 ( F_51 ( & V_13 -> V_20 ) & 0x1 ) ;
}
bool T_2 F_68 ( void )
{
return F_51 ( F_15 ( & V_12 . V_20 ) ) & 0x1 ;
}
bool T_2 F_69 ( void )
{
int V_67 ;
F_70 () ;
V_67 = F_68 () ;
F_71 () ;
return V_67 ;
}
bool F_72 ( void )
{
struct V_6 * V_7 ;
struct V_40 * V_42 ;
bool V_67 ;
if ( F_73 () )
return true ;
F_70 () ;
V_7 = F_15 ( & V_8 ) ;
V_42 = V_7 -> V_18 ;
V_67 = ( V_7 -> V_68 & V_42 -> V_69 ) ||
! V_70 ;
F_71 () ;
return V_67 ;
}
static int F_74 ( void )
{
return F_75 ( V_12 . V_53 ) <= 1 ;
}
static int F_76 ( struct V_6 * V_7 ,
bool * V_71 , unsigned long * V_72 )
{
V_7 -> V_73 = F_77 ( 0 , & V_7 -> V_20 -> V_20 ) ;
F_78 ( V_7 , V_71 , V_72 ) ;
if ( ( V_7 -> V_73 & 0x1 ) == 0 ) {
F_79 ( V_7 -> V_2 -> V_24 , V_7 -> V_4 , V_7 -> V_5 , F_6 ( L_17 ) ) ;
return 1 ;
} else {
return 0 ;
}
}
static int F_80 ( struct V_6 * V_7 ,
bool * V_71 , unsigned long * V_72 )
{
unsigned int V_74 ;
int * V_75 ;
unsigned int V_76 ;
V_74 = ( unsigned int ) F_77 ( 0 , & V_7 -> V_20 -> V_20 ) ;
V_76 = ( unsigned int ) V_7 -> V_73 ;
if ( ( V_74 & 0x1 ) == 0 || F_81 ( V_74 , V_76 + 2 ) ) {
F_79 ( V_7 -> V_2 -> V_24 , V_7 -> V_4 , V_7 -> V_5 , F_6 ( L_17 ) ) ;
V_7 -> V_77 ++ ;
return 1 ;
}
if ( F_82 ( V_7 -> V_2 -> V_78 + 2 , V_79 ) )
return 0 ;
F_83 () ;
if ( F_84 ( V_7 -> V_5 ) ) {
F_79 ( V_7 -> V_2 -> V_24 , V_7 -> V_4 , V_7 -> V_5 , F_6 ( L_18 ) ) ;
V_7 -> V_80 ++ ;
return 1 ;
}
V_75 = & F_4 ( V_15 , V_7 -> V_5 ) ;
if ( F_82 ( V_79 ,
V_7 -> V_2 -> V_78 + V_81 ) ||
F_82 ( V_79 , V_7 -> V_2 -> V_82 ) ) {
if ( ! ( F_2 ( * V_75 ) & V_7 -> V_2 -> V_17 ) ) {
F_2 ( V_7 -> V_19 ) =
F_2 ( V_7 -> V_18 -> V_3 ) ;
F_14 () ;
F_2 ( * V_75 ) =
F_2 ( * V_75 ) + V_7 -> V_2 -> V_17 ;
F_85 ( V_7 -> V_5 ) ;
V_7 -> V_2 -> V_82 += 5 ;
} else if ( F_82 ( V_79 , V_7 -> V_2 -> V_82 ) ) {
F_85 ( V_7 -> V_5 ) ;
V_7 -> V_2 -> V_82 += 5 ;
}
}
return 0 ;
}
static void F_86 ( struct V_1 * V_2 )
{
unsigned long V_83 = V_79 ;
unsigned long j1 ;
V_2 -> V_78 = V_83 ;
F_87 () ;
j1 = F_88 () ;
F_2 ( V_2 -> V_84 ) = V_83 + j1 ;
V_2 -> V_82 = V_83 + j1 / 2 ;
}
static void F_89 ( struct V_1 * V_2 )
{
int V_5 ;
unsigned long V_11 ;
struct V_40 * V_42 ;
F_90 (rsp, rnp) {
F_91 ( & V_42 -> V_85 , V_11 ) ;
if ( V_42 -> V_86 != 0 ) {
for ( V_5 = 0 ; V_5 <= V_42 -> V_87 - V_42 -> V_88 ; V_5 ++ )
if ( V_42 -> V_86 & ( 1UL << V_5 ) )
F_92 ( V_42 -> V_88 + V_5 ) ;
}
F_93 ( & V_42 -> V_85 , V_11 ) ;
}
}
static void F_94 ( struct V_1 * V_2 )
{
int V_5 ;
long V_89 ;
unsigned long V_11 ;
int V_90 = 0 ;
struct V_40 * V_42 = F_36 ( V_2 ) ;
long V_91 = 0 ;
F_91 ( & V_42 -> V_85 , V_11 ) ;
V_89 = V_79 - F_2 ( V_2 -> V_84 ) ;
if ( V_89 < V_92 || ! F_1 ( V_2 ) ) {
F_93 ( & V_42 -> V_85 , V_11 ) ;
return;
}
F_2 ( V_2 -> V_84 ) = V_79 + 3 * F_88 () + 3 ;
F_93 ( & V_42 -> V_85 , V_11 ) ;
F_95 ( L_19 ,
V_2 -> V_24 ) ;
F_96 () ;
F_90 (rsp, rnp) {
F_91 ( & V_42 -> V_85 , V_11 ) ;
V_90 += F_97 ( V_42 ) ;
if ( V_42 -> V_86 != 0 ) {
for ( V_5 = 0 ; V_5 <= V_42 -> V_87 - V_42 -> V_88 ; V_5 ++ )
if ( V_42 -> V_86 & ( 1UL << V_5 ) ) {
F_98 ( V_2 ,
V_42 -> V_88 + V_5 ) ;
V_90 ++ ;
}
}
F_93 ( & V_42 -> V_85 , V_11 ) ;
}
V_42 = F_36 ( V_2 ) ;
F_91 ( & V_42 -> V_85 , V_11 ) ;
V_90 += F_97 ( V_42 ) ;
F_93 ( & V_42 -> V_85 , V_11 ) ;
F_99 () ;
F_100 (cpu)
V_91 += F_101 ( V_2 -> V_16 , V_5 ) -> V_93 ;
F_102 ( L_20 ,
F_44 () , ( long ) ( V_79 - V_2 -> V_78 ) ,
( long ) V_2 -> V_4 , ( long ) V_2 -> V_3 , V_91 ) ;
if ( V_90 == 0 )
F_95 ( L_21 ) ;
else
F_89 ( V_2 ) ;
F_103 ( V_2 ) ;
F_27 ( V_2 ) ;
}
static void F_104 ( struct V_1 * V_2 )
{
int V_5 ;
unsigned long V_11 ;
struct V_40 * V_42 = F_36 ( V_2 ) ;
long V_91 = 0 ;
F_95 ( L_22 , V_2 -> V_24 ) ;
F_96 () ;
F_98 ( V_2 , F_44 () ) ;
F_99 () ;
F_100 (cpu)
V_91 += F_101 ( V_2 -> V_16 , V_5 ) -> V_93 ;
F_102 ( L_23 ,
V_79 - V_2 -> V_78 ,
( long ) V_2 -> V_4 , ( long ) V_2 -> V_3 , V_91 ) ;
F_89 ( V_2 ) ;
F_91 ( & V_42 -> V_85 , V_11 ) ;
if ( F_82 ( V_79 , F_2 ( V_2 -> V_84 ) ) )
F_2 ( V_2 -> V_84 ) = V_79 +
3 * F_88 () + 3 ;
F_93 ( & V_42 -> V_85 , V_11 ) ;
F_85 ( F_44 () ) ;
}
static void F_105 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
unsigned long V_3 ;
unsigned long V_4 ;
unsigned long V_94 ;
unsigned long V_83 ;
unsigned long V_95 ;
struct V_40 * V_42 ;
if ( V_96 || ! F_1 ( V_2 ) )
return;
V_83 = V_79 ;
V_4 = F_2 ( V_2 -> V_4 ) ;
F_106 () ;
V_95 = F_2 ( V_2 -> V_84 ) ;
F_106 () ;
V_94 = F_2 ( V_2 -> V_78 ) ;
F_106 () ;
V_3 = F_2 ( V_2 -> V_3 ) ;
if ( F_82 ( V_3 , V_4 ) ||
F_39 ( V_83 , V_95 ) ||
F_82 ( V_94 , V_95 ) )
return;
V_42 = V_7 -> V_18 ;
if ( F_1 ( V_2 ) &&
( F_2 ( V_42 -> V_86 ) & V_7 -> V_68 ) ) {
F_104 ( V_2 ) ;
} else if ( F_1 ( V_2 ) &&
F_82 ( V_83 , V_95 + V_92 ) ) {
F_94 ( V_2 ) ;
}
}
void F_107 ( void )
{
struct V_1 * V_2 ;
F_12 (rsp)
F_2 ( V_2 -> V_84 ) = V_79 + V_97 / 2 ;
}
static void F_108 ( struct V_6 * V_7 )
{
int V_46 ;
if ( F_109 ( V_7 ) )
return;
V_7 -> V_37 = NULL ;
for ( V_46 = 0 ; V_46 < V_98 ; V_46 ++ )
V_7 -> V_38 [ V_46 ] = & V_7 -> V_37 ;
}
static unsigned long F_110 ( struct V_1 * V_2 ,
struct V_40 * V_42 )
{
if ( F_36 ( V_2 ) == V_42 && V_42 -> V_4 == V_42 -> V_3 )
return V_42 -> V_3 + 1 ;
return V_42 -> V_3 + 2 ;
}
static void F_111 ( struct V_40 * V_42 , struct V_6 * V_7 ,
unsigned long V_99 , const char * V_100 )
{
F_112 ( V_7 -> V_2 -> V_24 , V_42 -> V_4 ,
V_42 -> V_3 , V_99 , V_42 -> V_101 ,
V_42 -> V_88 , V_42 -> V_87 , V_100 ) ;
}
static bool V_56
F_113 ( struct V_40 * V_42 , struct V_6 * V_7 ,
unsigned long * V_102 )
{
unsigned long V_99 ;
int V_46 ;
bool V_67 = false ;
struct V_40 * V_103 = F_36 ( V_7 -> V_2 ) ;
V_99 = F_110 ( V_7 -> V_2 , V_42 ) ;
F_111 ( V_42 , V_7 , V_99 , F_6 ( L_24 ) ) ;
if ( V_42 -> V_45 [ V_99 & 0x1 ] ) {
F_111 ( V_42 , V_7 , V_99 , F_6 ( L_25 ) ) ;
goto V_104;
}
if ( V_42 -> V_4 != V_42 -> V_3 ||
F_2 ( V_103 -> V_4 ) != F_2 ( V_103 -> V_3 ) ) {
V_42 -> V_45 [ V_99 & 0x1 ] ++ ;
F_111 ( V_42 , V_7 , V_99 , F_6 ( L_26 ) ) ;
goto V_104;
}
if ( V_42 != V_103 ) {
F_114 ( & V_103 -> V_85 ) ;
F_115 () ;
}
V_99 = F_110 ( V_7 -> V_2 , V_103 ) ;
for ( V_46 = V_39 ; V_46 < V_47 ; V_46 ++ )
if ( F_39 ( V_99 , V_7 -> V_50 [ V_46 ] ) )
V_7 -> V_50 [ V_46 ] = V_99 ;
if ( V_103 -> V_45 [ V_99 & 0x1 ] ) {
F_111 ( V_42 , V_7 , V_99 , F_6 ( L_27 ) ) ;
goto V_105;
}
V_103 -> V_45 [ V_99 & 0x1 ] ++ ;
if ( V_103 -> V_4 != V_103 -> V_3 ) {
F_111 ( V_42 , V_7 , V_99 , F_6 ( L_28 ) ) ;
} else {
F_111 ( V_42 , V_7 , V_99 , F_6 ( L_29 ) ) ;
V_67 = F_116 ( V_7 -> V_2 , V_103 , V_7 ) ;
}
V_105:
if ( V_42 != V_103 )
F_117 ( & V_103 -> V_85 ) ;
V_104:
if ( V_102 != NULL )
* V_102 = V_99 ;
return V_67 ;
}
static int F_118 ( struct V_1 * V_2 , struct V_40 * V_42 )
{
int V_99 = V_42 -> V_3 ;
int V_106 ;
struct V_6 * V_7 = F_15 ( V_2 -> V_16 ) ;
F_119 ( V_2 , V_42 ) ;
V_42 -> V_45 [ V_99 & 0x1 ] = 0 ;
V_106 = V_42 -> V_45 [ ( V_99 + 1 ) & 0x1 ] ;
F_111 ( V_42 , V_7 , V_99 ,
V_106 ? F_6 ( L_30 ) : F_6 ( L_31 ) ) ;
return V_106 ;
}
static void F_120 ( struct V_1 * V_2 )
{
if ( V_54 == V_2 -> V_26 ||
! F_2 ( V_2 -> V_35 ) ||
! V_2 -> V_26 )
return;
F_121 ( & V_2 -> V_107 ) ;
}
static bool F_122 ( struct V_1 * V_2 , struct V_40 * V_42 ,
struct V_6 * V_7 )
{
unsigned long V_99 ;
int V_46 ;
bool V_67 ;
if ( ! V_7 -> V_38 [ V_47 ] || ! * V_7 -> V_38 [ V_39 ] )
return false ;
V_99 = F_110 ( V_2 , V_42 ) ;
for ( V_46 = V_47 - 1 ; V_46 > V_39 ; V_46 -- )
if ( V_7 -> V_38 [ V_46 ] != V_7 -> V_38 [ V_46 - 1 ] &&
! F_82 ( V_7 -> V_50 [ V_46 ] , V_99 ) )
break;
if ( ++ V_46 >= V_47 )
return false ;
for (; V_46 <= V_47 ; V_46 ++ ) {
V_7 -> V_38 [ V_46 ] = V_7 -> V_38 [ V_47 ] ;
V_7 -> V_50 [ V_46 ] = V_99 ;
}
V_67 = F_113 ( V_42 , V_7 , NULL ) ;
if ( ! * V_7 -> V_38 [ V_49 ] )
F_5 ( V_2 -> V_24 , V_7 -> V_4 , F_6 ( L_32 ) ) ;
else
F_5 ( V_2 -> V_24 , V_7 -> V_4 , F_6 ( L_33 ) ) ;
return V_67 ;
}
static bool F_123 ( struct V_1 * V_2 , struct V_40 * V_42 ,
struct V_6 * V_7 )
{
int V_46 , V_83 ;
if ( ! V_7 -> V_38 [ V_47 ] || ! * V_7 -> V_38 [ V_39 ] )
return false ;
for ( V_46 = V_49 ; V_46 < V_47 ; V_46 ++ ) {
if ( F_39 ( V_42 -> V_3 , V_7 -> V_50 [ V_46 ] ) )
break;
V_7 -> V_38 [ V_39 ] = V_7 -> V_38 [ V_46 ] ;
}
for ( V_83 = V_49 ; V_83 < V_46 ; V_83 ++ )
V_7 -> V_38 [ V_83 ] = V_7 -> V_38 [ V_39 ] ;
for ( V_83 = V_49 ; V_46 < V_47 ; V_46 ++ , V_83 ++ ) {
if ( V_7 -> V_38 [ V_83 ] == V_7 -> V_38 [ V_47 ] )
break;
V_7 -> V_38 [ V_83 ] = V_7 -> V_38 [ V_46 ] ;
V_7 -> V_50 [ V_83 ] = V_7 -> V_50 [ V_46 ] ;
}
return F_122 ( V_2 , V_42 , V_7 ) ;
}
static bool F_124 ( struct V_1 * V_2 , struct V_40 * V_42 ,
struct V_6 * V_7 )
{
bool V_67 ;
if ( V_7 -> V_3 == V_42 -> V_3 ) {
V_67 = F_122 ( V_2 , V_42 , V_7 ) ;
} else {
V_67 = F_123 ( V_2 , V_42 , V_7 ) ;
V_7 -> V_3 = V_42 -> V_3 ;
F_5 ( V_2 -> V_24 , V_7 -> V_4 , F_6 ( L_34 ) ) ;
}
if ( V_7 -> V_4 != V_42 -> V_4 ) {
V_7 -> V_4 = V_42 -> V_4 ;
F_5 ( V_2 -> V_24 , V_7 -> V_4 , F_6 ( L_35 ) ) ;
V_7 -> V_9 = 0 ;
V_7 -> V_108 = ! ! ( V_42 -> V_86 & V_7 -> V_68 ) ;
F_125 ( V_7 ) ;
}
return V_67 ;
}
static void F_126 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
unsigned long V_11 ;
bool V_109 ;
struct V_40 * V_42 ;
F_9 ( V_11 ) ;
V_42 = V_7 -> V_18 ;
if ( ( V_7 -> V_4 == F_2 ( V_42 -> V_4 ) &&
V_7 -> V_3 == F_2 ( V_42 -> V_3 ) ) ||
! F_127 ( & V_42 -> V_85 ) ) {
F_19 ( V_11 ) ;
return;
}
F_115 () ;
V_109 = F_124 ( V_2 , V_42 , V_7 ) ;
F_93 ( & V_42 -> V_85 , V_11 ) ;
if ( V_109 )
F_120 ( V_2 ) ;
}
static int F_128 ( struct V_1 * V_2 )
{
struct V_6 * V_7 ;
struct V_40 * V_42 = F_36 ( V_2 ) ;
F_129 () ;
F_130 ( & V_42 -> V_85 ) ;
F_115 () ;
if ( ! F_2 ( V_2 -> V_35 ) ) {
F_131 ( & V_42 -> V_85 ) ;
return 0 ;
}
F_2 ( V_2 -> V_35 ) = 0 ;
if ( F_50 ( F_1 ( V_2 ) ) ) {
F_131 ( & V_42 -> V_85 ) ;
return 0 ;
}
F_86 ( V_2 ) ;
F_132 ( & V_2 -> V_4 , V_2 -> V_4 + 1 ) ;
F_5 ( V_2 -> V_24 , V_2 -> V_4 , F_6 ( L_36 ) ) ;
F_131 ( & V_42 -> V_85 ) ;
F_133 ( & V_2 -> V_110 ) ;
F_115 () ;
F_134 (rsp, rnp) {
F_130 ( & V_42 -> V_85 ) ;
F_115 () ;
V_7 = F_15 ( V_2 -> V_16 ) ;
F_135 ( V_42 ) ;
V_42 -> V_86 = V_42 -> V_69 ;
F_2 ( V_42 -> V_4 ) = V_2 -> V_4 ;
F_50 ( V_42 -> V_3 != V_2 -> V_3 ) ;
F_2 ( V_42 -> V_3 ) = V_2 -> V_3 ;
if ( V_42 == V_7 -> V_18 )
( void ) F_124 ( V_2 , V_42 , V_7 ) ;
F_136 ( V_42 ) ;
F_137 ( V_2 -> V_24 , V_42 -> V_4 ,
V_42 -> V_101 , V_42 -> V_88 ,
V_42 -> V_87 , V_42 -> V_86 ) ;
F_131 ( & V_42 -> V_85 ) ;
F_138 () ;
}
F_139 ( & V_2 -> V_110 ) ;
return 1 ;
}
static int F_140 ( struct V_1 * V_2 , int V_111 )
{
int V_112 = V_111 ;
bool V_71 = false ;
unsigned long V_72 ;
struct V_40 * V_42 = F_36 ( V_2 ) ;
V_2 -> V_113 ++ ;
if ( V_112 == V_114 ) {
if ( F_141 ( V_2 ) ) {
V_71 = 1 ;
V_72 = V_79 - V_97 / 4 ;
}
F_142 ( V_2 , F_76 ,
& V_71 , & V_72 ) ;
F_143 ( V_2 , V_71 , V_72 ) ;
V_112 = V_115 ;
} else {
V_71 = 0 ;
F_142 ( V_2 , F_80 , & V_71 , & V_72 ) ;
}
if ( F_2 ( V_2 -> V_35 ) & V_116 ) {
F_130 ( & V_42 -> V_85 ) ;
F_115 () ;
F_2 ( V_2 -> V_35 ) &= ~ V_116 ;
F_131 ( & V_42 -> V_85 ) ;
}
return V_112 ;
}
static void F_144 ( struct V_1 * V_2 )
{
unsigned long V_117 ;
bool V_118 = false ;
int V_119 = 0 ;
struct V_6 * V_7 ;
struct V_40 * V_42 = F_36 ( V_2 ) ;
F_130 ( & V_42 -> V_85 ) ;
F_115 () ;
V_117 = V_79 - V_2 -> V_78 ;
if ( V_117 > V_2 -> V_120 )
V_2 -> V_120 = V_117 ;
F_131 ( & V_42 -> V_85 ) ;
F_134 (rsp, rnp) {
F_130 ( & V_42 -> V_85 ) ;
F_115 () ;
F_2 ( V_42 -> V_3 ) = V_2 -> V_4 ;
V_7 = F_15 ( V_2 -> V_16 ) ;
if ( V_42 == V_7 -> V_18 )
V_118 = F_124 ( V_2 , V_42 , V_7 ) || V_118 ;
V_119 += F_118 ( V_2 , V_42 ) ;
F_131 ( & V_42 -> V_85 ) ;
F_138 () ;
}
V_42 = F_36 ( V_2 ) ;
F_130 ( & V_42 -> V_85 ) ;
F_115 () ;
F_145 ( V_42 , V_119 ) ;
F_2 ( V_2 -> V_3 ) = V_2 -> V_4 ;
F_5 ( V_2 -> V_24 , V_2 -> V_3 , F_6 ( L_37 ) ) ;
V_2 -> V_112 = V_121 ;
V_7 = F_15 ( V_2 -> V_16 ) ;
V_118 = F_123 ( V_2 , V_42 , V_7 ) || V_118 ;
if ( V_118 || F_38 ( V_2 , V_7 ) ) {
F_2 ( V_2 -> V_35 ) = V_122 ;
F_5 ( V_2 -> V_24 ,
F_2 ( V_2 -> V_4 ) ,
F_6 ( L_38 ) ) ;
}
F_131 ( & V_42 -> V_85 ) ;
}
static int T_3 F_146 ( void * V_123 )
{
int V_112 ;
int V_124 ;
unsigned long V_83 ;
int V_67 ;
struct V_1 * V_2 = V_123 ;
struct V_40 * V_42 = F_36 ( V_2 ) ;
for (; ; ) {
for (; ; ) {
F_5 ( V_2 -> V_24 ,
F_2 ( V_2 -> V_4 ) ,
F_6 ( L_39 ) ) ;
V_2 -> V_25 = V_125 ;
F_147 ( V_2 -> V_107 ,
F_2 ( V_2 -> V_35 ) &
V_122 ) ;
if ( F_128 ( V_2 ) )
break;
F_138 () ;
F_148 ( V_54 ) ;
F_5 ( V_2 -> V_24 ,
F_2 ( V_2 -> V_4 ) ,
F_6 ( L_40 ) ) ;
}
V_112 = V_114 ;
V_83 = V_126 ;
if ( V_83 > V_127 ) {
V_83 = V_127 ;
V_126 = V_127 ;
}
V_67 = 0 ;
for (; ; ) {
if ( ! V_67 )
V_2 -> V_128 = V_79 + V_83 ;
F_5 ( V_2 -> V_24 ,
F_2 ( V_2 -> V_4 ) ,
F_6 ( L_41 ) ) ;
V_2 -> V_25 = V_129 ;
V_67 = F_149 ( V_2 -> V_107 ,
( ( V_124 = F_2 ( V_2 -> V_35 ) ) &
V_116 ) ||
( ! F_2 ( V_42 -> V_86 ) &&
! F_150 ( V_42 ) ) ,
V_83 ) ;
if ( ! F_2 ( V_42 -> V_86 ) &&
! F_150 ( V_42 ) )
break;
if ( F_82 ( V_79 , V_2 -> V_128 ) ||
( V_124 & V_116 ) ) {
F_5 ( V_2 -> V_24 ,
F_2 ( V_2 -> V_4 ) ,
F_6 ( L_42 ) ) ;
V_112 = F_140 ( V_2 , V_112 ) ;
F_5 ( V_2 -> V_24 ,
F_2 ( V_2 -> V_4 ) ,
F_6 ( L_43 ) ) ;
F_138 () ;
} else {
F_138 () ;
F_148 ( V_54 ) ;
F_5 ( V_2 -> V_24 ,
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
F_144 ( V_2 ) ;
}
}
static bool
F_116 ( struct V_1 * V_2 , struct V_40 * V_42 ,
struct V_6 * V_7 )
{
if ( ! V_2 -> V_26 || ! F_38 ( V_2 , V_7 ) ) {
return false ;
}
F_2 ( V_2 -> V_35 ) = V_122 ;
F_5 ( V_2 -> V_24 , F_2 ( V_2 -> V_4 ) ,
F_6 ( L_38 ) ) ;
return true ;
}
static bool F_151 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_15 ( V_2 -> V_16 ) ;
struct V_40 * V_42 = F_36 ( V_2 ) ;
bool V_67 = false ;
V_67 = F_123 ( V_2 , V_42 , V_7 ) || V_67 ;
V_67 = F_116 ( V_2 , V_42 , V_7 ) || V_67 ;
return V_67 ;
}
static void F_152 ( struct V_1 * V_2 , unsigned long V_11 )
__releases( rcu_get_root( V_2 )->lock
static void
F_153 ( unsigned long V_131 , struct V_1 * V_2 ,
struct V_40 * V_42 , unsigned long V_11 )
__releases( V_42 -> V_85 )
{
struct V_40 * V_132 ;
for (; ; ) {
if ( ! ( V_42 -> V_86 & V_131 ) ) {
F_93 ( & V_42 -> V_85 , V_11 ) ;
return;
}
V_42 -> V_86 &= ~ V_131 ;
F_154 ( V_2 -> V_24 , V_42 -> V_4 ,
V_131 , V_42 -> V_86 , V_42 -> V_101 ,
V_42 -> V_88 , V_42 -> V_87 ,
! ! V_42 -> V_133 ) ;
if ( V_42 -> V_86 != 0 || F_150 ( V_42 ) ) {
F_93 ( & V_42 -> V_85 , V_11 ) ;
return;
}
V_131 = V_42 -> V_68 ;
if ( V_42 -> V_134 == NULL ) {
break;
}
F_93 ( & V_42 -> V_85 , V_11 ) ;
V_132 = V_42 ;
V_42 = V_42 -> V_134 ;
F_91 ( & V_42 -> V_85 , V_11 ) ;
F_115 () ;
F_50 ( V_132 -> V_86 ) ;
}
F_152 ( V_2 , V_11 ) ;
}
static void
F_155 ( int V_5 , struct V_1 * V_2 , struct V_6 * V_7 )
{
unsigned long V_11 ;
unsigned long V_131 ;
bool V_109 ;
struct V_40 * V_42 ;
V_42 = V_7 -> V_18 ;
F_91 ( & V_42 -> V_85 , V_11 ) ;
F_115 () ;
if ( V_7 -> V_9 == 0 || V_7 -> V_4 != V_42 -> V_4 ||
V_42 -> V_3 == V_42 -> V_4 ) {
V_7 -> V_9 = 0 ;
F_93 ( & V_42 -> V_85 , V_11 ) ;
return;
}
V_131 = V_7 -> V_68 ;
if ( ( V_42 -> V_86 & V_131 ) == 0 ) {
F_93 ( & V_42 -> V_85 , V_11 ) ;
} else {
V_7 -> V_108 = 0 ;
V_109 = F_122 ( V_2 , V_42 , V_7 ) ;
F_153 ( V_131 , V_2 , V_42 , V_11 ) ;
if ( V_109 )
F_120 ( V_2 ) ;
}
}
static void
F_156 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
F_126 ( V_2 , V_7 ) ;
if ( ! V_7 -> V_108 )
return;
if ( ! V_7 -> V_9 )
return;
F_155 ( V_7 -> V_5 , V_2 , V_7 ) ;
}
static void
F_157 ( int V_5 , struct V_1 * V_2 ,
struct V_40 * V_42 , struct V_6 * V_7 )
{
if ( F_158 ( V_7 -> V_5 ) )
return;
if ( V_7 -> V_37 != NULL ) {
V_2 -> V_135 += V_7 -> V_135 ;
V_2 -> V_93 += V_7 -> V_93 ;
V_7 -> V_136 += V_7 -> V_93 ;
V_7 -> V_135 = 0 ;
F_2 ( V_7 -> V_93 ) = 0 ;
}
if ( * V_7 -> V_38 [ V_39 ] != NULL ) {
* V_2 -> V_137 = * V_7 -> V_38 [ V_39 ] ;
V_2 -> V_137 = V_7 -> V_38 [ V_47 ] ;
* V_7 -> V_38 [ V_39 ] = NULL ;
}
if ( V_7 -> V_37 != NULL ) {
* V_2 -> V_138 = V_7 -> V_37 ;
V_2 -> V_138 = V_7 -> V_38 [ V_39 ] ;
}
F_108 ( V_7 ) ;
}
static void F_159 ( struct V_1 * V_2 , unsigned long V_11 )
{
int V_46 ;
struct V_6 * V_7 = F_13 ( V_2 -> V_16 ) ;
if ( F_160 ( V_2 , V_7 , V_11 ) )
return;
V_7 -> V_135 += V_2 -> V_135 ;
V_7 -> V_93 += V_2 -> V_93 ;
V_7 -> V_139 += V_2 -> V_93 ;
if ( V_2 -> V_135 != V_2 -> V_93 )
F_161 () ;
V_2 -> V_135 = 0 ;
V_2 -> V_93 = 0 ;
if ( V_2 -> V_140 != NULL ) {
* V_2 -> V_138 = * V_7 -> V_38 [ V_39 ] ;
* V_7 -> V_38 [ V_39 ] = V_2 -> V_140 ;
for ( V_46 = V_98 - 1 ; V_46 >= V_39 ; V_46 -- )
if ( V_7 -> V_38 [ V_46 ] == V_7 -> V_38 [ V_39 ] )
V_7 -> V_38 [ V_46 ] = V_2 -> V_138 ;
V_2 -> V_140 = NULL ;
V_2 -> V_138 = & V_2 -> V_140 ;
}
if ( V_2 -> V_141 != NULL ) {
* V_7 -> V_38 [ V_47 ] = V_2 -> V_141 ;
V_7 -> V_38 [ V_47 ] = V_2 -> V_137 ;
V_2 -> V_141 = NULL ;
V_2 -> V_137 = & V_2 -> V_141 ;
}
}
static void F_162 ( struct V_1 * V_2 )
{
F_163 (unsigned long mask) ;
F_163 ( struct V_6 * V_7 = F_15 ( V_2 -> V_16 ) ) ;
F_163 ( struct V_40 * V_42 = V_7 -> V_18 ) ;
F_163 ( V_131 = V_7 -> V_68 ) ;
F_5 ( V_2 -> V_24 ,
V_42 -> V_4 + 1 - ! ! ( V_42 -> V_86 & V_131 ) ,
F_6 ( L_45 ) ) ;
}
static void F_164 ( int V_5 , struct V_1 * V_2 )
{
unsigned long V_11 ;
unsigned long V_131 ;
int V_142 = 0 ;
struct V_6 * V_7 = F_101 ( V_2 -> V_16 , V_5 ) ;
struct V_40 * V_42 = V_7 -> V_18 ;
F_165 ( V_42 , - 1 ) ;
F_133 ( & V_2 -> V_110 ) ;
F_91 ( & V_2 -> V_143 , V_11 ) ;
F_157 ( V_5 , V_2 , V_42 , V_7 ) ;
F_159 ( V_2 , V_11 ) ;
V_131 = V_7 -> V_68 ;
do {
F_114 ( & V_42 -> V_85 ) ;
F_115 () ;
V_42 -> V_69 &= ~ V_131 ;
if ( V_42 -> V_69 != 0 ) {
if ( V_42 != V_7 -> V_18 )
F_117 ( & V_42 -> V_85 ) ;
break;
}
if ( V_42 == V_7 -> V_18 )
V_142 = F_166 ( V_2 , V_42 , V_7 ) ;
else
F_117 ( & V_42 -> V_85 ) ;
V_131 = V_42 -> V_68 ;
V_42 = V_42 -> V_134 ;
} while ( V_42 != NULL );
F_117 ( & V_2 -> V_143 ) ;
V_42 = V_7 -> V_18 ;
if ( V_142 & V_144 )
F_167 ( V_42 , V_11 ) ;
else
F_93 ( & V_42 -> V_85 , V_11 ) ;
if ( V_142 & V_145 )
F_168 ( V_2 , V_42 , true ) ;
F_46 ( V_7 -> V_93 != 0 || V_7 -> V_37 != NULL ,
L_46 ,
V_5 , V_7 -> V_93 , V_7 -> V_37 ) ;
F_108 ( V_7 ) ;
V_7 -> V_38 [ V_47 ] = NULL ;
F_139 ( & V_2 -> V_110 ) ;
}
static void F_162 ( struct V_1 * V_2 )
{
}
static void F_164 ( int V_5 , struct V_1 * V_2 )
{
}
static void F_169 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
unsigned long V_11 ;
struct V_146 * V_147 , * V_148 , * * V_149 ;
long V_150 , V_151 , V_152 ;
int V_46 ;
if ( ! F_35 ( V_7 ) ) {
F_170 ( V_2 -> V_24 , V_7 -> V_135 , V_7 -> V_93 , 0 ) ;
F_171 ( V_2 -> V_24 , 0 , ! ! F_2 ( V_7 -> V_37 ) ,
F_172 () , F_42 ( V_54 ) ,
F_173 () ) ;
return;
}
F_9 ( V_11 ) ;
F_50 ( F_84 ( F_44 () ) ) ;
V_150 = V_7 -> V_153 ;
F_170 ( V_2 -> V_24 , V_7 -> V_135 , V_7 -> V_93 , V_150 ) ;
V_148 = V_7 -> V_37 ;
V_7 -> V_37 = * V_7 -> V_38 [ V_39 ] ;
* V_7 -> V_38 [ V_39 ] = NULL ;
V_149 = V_7 -> V_38 [ V_39 ] ;
for ( V_46 = V_98 - 1 ; V_46 >= 0 ; V_46 -- )
if ( V_7 -> V_38 [ V_46 ] == V_7 -> V_38 [ V_39 ] )
V_7 -> V_38 [ V_46 ] = & V_7 -> V_37 ;
F_19 ( V_11 ) ;
V_151 = V_152 = 0 ;
while ( V_148 ) {
V_147 = V_148 -> V_147 ;
F_174 ( V_147 ) ;
F_175 ( V_148 ) ;
if ( F_176 ( V_2 -> V_24 , V_148 ) )
V_152 ++ ;
V_148 = V_147 ;
if ( ++ V_151 >= V_150 &&
( F_172 () ||
( ! F_42 ( V_54 ) && ! F_173 () ) ) )
break;
}
F_9 ( V_11 ) ;
F_171 ( V_2 -> V_24 , V_151 , ! ! V_148 , F_172 () ,
F_42 ( V_54 ) ,
F_173 () ) ;
if ( V_148 != NULL ) {
* V_149 = V_7 -> V_37 ;
V_7 -> V_37 = V_148 ;
for ( V_46 = 0 ; V_46 < V_98 ; V_46 ++ )
if ( & V_7 -> V_37 == V_7 -> V_38 [ V_46 ] )
V_7 -> V_38 [ V_46 ] = V_149 ;
else
break;
}
F_14 () ;
V_7 -> V_135 -= V_152 ;
F_2 ( V_7 -> V_93 ) = V_7 -> V_93 - V_151 ;
V_7 -> V_154 += V_151 ;
if ( V_7 -> V_153 == V_155 && V_7 -> V_93 <= V_156 )
V_7 -> V_153 = V_153 ;
if ( V_7 -> V_93 == 0 && V_7 -> V_157 != 0 ) {
V_7 -> V_157 = 0 ;
V_7 -> V_158 = V_2 -> V_113 ;
} else if ( V_7 -> V_93 < V_7 -> V_157 - V_159 )
V_7 -> V_157 = V_7 -> V_93 ;
F_50 ( ( V_7 -> V_37 == NULL ) != ( V_7 -> V_93 == 0 ) ) ;
F_19 ( V_11 ) ;
if ( F_35 ( V_7 ) )
F_177 () ;
}
void F_178 ( int V_5 , int V_52 )
{
F_21 ( F_6 ( L_47 ) ) ;
F_179 () ;
if ( V_52 || F_74 () ) {
F_3 ( V_5 ) ;
F_7 ( V_5 ) ;
} else if ( ! F_180 () ) {
F_7 ( V_5 ) ;
}
F_181 ( V_5 ) ;
if ( F_182 ( V_5 ) )
F_177 () ;
F_21 ( F_6 ( L_48 ) ) ;
}
static void F_142 ( struct V_1 * V_2 ,
int (* F_183)( struct V_6 * V_2 , bool * V_71 ,
unsigned long * V_72 ) ,
bool * V_71 , unsigned long * V_72 )
{
unsigned long V_160 ;
int V_5 ;
unsigned long V_11 ;
unsigned long V_131 ;
struct V_40 * V_42 ;
F_90 (rsp, rnp) {
F_138 () ;
V_131 = 0 ;
F_91 ( & V_42 -> V_85 , V_11 ) ;
F_115 () ;
if ( ! F_1 ( V_2 ) ) {
F_93 ( & V_42 -> V_85 , V_11 ) ;
return;
}
if ( V_42 -> V_86 == 0 ) {
F_184 ( V_42 , V_11 ) ;
continue;
}
V_5 = V_42 -> V_88 ;
V_160 = 1 ;
for (; V_5 <= V_42 -> V_87 ; V_5 ++ , V_160 <<= 1 ) {
if ( ( V_42 -> V_86 & V_160 ) != 0 ) {
if ( ( V_42 -> V_69 & V_160 ) != 0 )
* V_71 = 0 ;
if ( F_183 ( F_101 ( V_2 -> V_16 , V_5 ) , V_71 , V_72 ) )
V_131 |= V_160 ;
}
}
if ( V_131 != 0 ) {
F_153 ( V_131 , V_2 , V_42 , V_11 ) ;
continue;
}
F_93 ( & V_42 -> V_85 , V_11 ) ;
}
V_42 = F_36 ( V_2 ) ;
if ( V_42 -> V_86 == 0 ) {
F_91 ( & V_42 -> V_85 , V_11 ) ;
F_115 () ;
F_184 ( V_42 , V_11 ) ;
}
}
static void F_27 ( struct V_1 * V_2 )
{
unsigned long V_11 ;
bool V_67 ;
struct V_40 * V_42 ;
struct V_40 * V_161 = NULL ;
V_42 = F_75 ( V_2 -> V_16 -> V_18 ) ;
for (; V_42 != NULL ; V_42 = V_42 -> V_134 ) {
V_67 = ( F_2 ( V_2 -> V_35 ) & V_116 ) ||
! F_127 ( & V_42 -> V_162 ) ;
if ( V_161 != NULL )
F_117 ( & V_161 -> V_162 ) ;
if ( V_67 ) {
V_2 -> V_163 ++ ;
return;
}
V_161 = V_42 ;
}
F_91 ( & V_161 -> V_85 , V_11 ) ;
F_115 () ;
F_117 ( & V_161 -> V_162 ) ;
if ( F_2 ( V_2 -> V_35 ) & V_116 ) {
V_2 -> V_163 ++ ;
F_93 ( & V_161 -> V_85 , V_11 ) ;
return;
}
F_2 ( V_2 -> V_35 ) |= V_116 ;
F_93 ( & V_161 -> V_85 , V_11 ) ;
F_121 ( & V_2 -> V_107 ) ;
}
static void
F_185 ( struct V_1 * V_2 )
{
unsigned long V_11 ;
bool V_109 ;
struct V_6 * V_7 = F_13 ( V_2 -> V_16 ) ;
F_50 ( V_7 -> V_164 == 0 ) ;
F_156 ( V_2 , V_7 ) ;
F_9 ( V_11 ) ;
if ( F_38 ( V_2 , V_7 ) ) {
F_114 ( & F_36 ( V_2 ) -> V_85 ) ;
V_109 = F_151 ( V_2 ) ;
F_93 ( & F_36 ( V_2 ) -> V_85 , V_11 ) ;
if ( V_109 )
F_120 ( V_2 ) ;
} else {
F_19 ( V_11 ) ;
}
if ( F_35 ( V_7 ) )
F_186 ( V_2 , V_7 ) ;
F_47 ( V_7 ) ;
}
static void F_187 ( struct V_165 * V_166 )
{
struct V_1 * V_2 ;
if ( F_84 ( F_44 () ) )
return;
F_21 ( F_6 ( L_49 ) ) ;
F_12 (rsp)
F_185 ( V_2 ) ;
F_21 ( F_6 ( L_50 ) ) ;
}
static void F_186 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
if ( F_23 ( ! F_2 ( V_70 ) ) )
return;
if ( F_188 ( ! V_2 -> V_167 ) ) {
F_169 ( V_2 , V_7 ) ;
return;
}
F_189 () ;
}
static void F_177 ( void )
{
if ( F_190 ( F_44 () ) )
F_191 ( V_168 ) ;
}
static void F_192 ( struct V_1 * V_2 , struct V_6 * V_7 ,
struct V_146 * V_169 , unsigned long V_11 )
{
bool V_109 ;
if ( ! F_69 () && F_190 ( F_44 () ) )
F_177 () ;
if ( F_193 ( V_11 ) || F_84 ( F_44 () ) )
return;
if ( F_23 ( V_7 -> V_93 > V_7 -> V_157 + V_159 ) ) {
F_126 ( V_2 , V_7 ) ;
if ( ! F_1 ( V_2 ) ) {
struct V_40 * V_103 = F_36 ( V_2 ) ;
F_114 ( & V_103 -> V_85 ) ;
F_115 () ;
V_109 = F_151 ( V_2 ) ;
F_117 ( & V_103 -> V_85 ) ;
if ( V_109 )
F_120 ( V_2 ) ;
} else {
V_7 -> V_153 = V_155 ;
if ( V_2 -> V_113 == V_7 -> V_158 &&
* V_7 -> V_38 [ V_39 ] != V_169 )
F_27 ( V_2 ) ;
V_7 -> V_158 = V_2 -> V_113 ;
V_7 -> V_157 = V_7 -> V_93 ;
}
}
}
static void F_194 ( struct V_146 * V_170 )
{
}
static void
F_195 ( struct V_146 * V_169 , void (* F_196)( struct V_146 * V_171 ) ,
struct V_1 * V_2 , int V_5 , bool V_172 )
{
unsigned long V_11 ;
struct V_6 * V_7 ;
F_50 ( ( unsigned long ) V_169 & 0x1 ) ;
if ( F_197 ( V_169 ) ) {
F_2 ( V_169 -> F_196 ) = F_194 ;
F_46 ( 1 , L_51 ) ;
return;
}
V_169 -> F_196 = F_196 ;
V_169 -> V_147 = NULL ;
F_9 ( V_11 ) ;
V_7 = F_15 ( V_2 -> V_16 ) ;
if ( F_23 ( V_7 -> V_38 [ V_47 ] == NULL ) || V_5 != - 1 ) {
int V_173 ;
if ( V_5 != - 1 )
V_7 = F_101 ( V_2 -> V_16 , V_5 ) ;
V_173 = ! F_198 ( V_7 , V_169 , V_172 , V_11 ) ;
F_50 ( V_173 ) ;
F_19 ( V_11 ) ;
return;
}
F_2 ( V_7 -> V_93 ) = V_7 -> V_93 + 1 ;
if ( V_172 )
V_7 -> V_135 ++ ;
else
F_161 () ;
F_14 () ;
* V_7 -> V_38 [ V_47 ] = V_169 ;
V_7 -> V_38 [ V_47 ] = & V_169 -> V_147 ;
if ( F_199 ( ( unsigned long ) F_196 ) )
F_200 ( V_2 -> V_24 , V_169 , ( unsigned long ) F_196 ,
V_7 -> V_135 , V_7 -> V_93 ) ;
else
F_201 ( V_2 -> V_24 , V_169 , V_7 -> V_135 , V_7 -> V_93 ) ;
F_192 ( V_2 , V_7 , V_169 , V_11 ) ;
F_19 ( V_11 ) ;
}
void F_202 ( struct V_146 * V_169 , void (* F_196)( struct V_146 * V_171 ) )
{
F_195 ( V_169 , F_196 , & V_21 , - 1 , 0 ) ;
}
void F_203 ( struct V_146 * V_169 , void (* F_196)( struct V_146 * V_171 ) )
{
F_195 ( V_169 , F_196 , & V_22 , - 1 , 0 ) ;
}
void F_204 ( struct V_146 * V_169 ,
void (* F_196)( struct V_146 * V_171 ) )
{
F_195 ( V_169 , F_196 , V_23 , - 1 , 1 ) ;
}
static inline int F_205 ( void )
{
int V_67 ;
F_206 () ;
F_70 () ;
V_67 = F_207 () <= 1 ;
F_71 () ;
return V_67 ;
}
void F_208 ( void )
{
F_52 ( ! F_53 ( & V_61 ) &&
! F_53 ( & V_60 ) &&
! F_53 ( & V_62 ) ,
L_52 ) ;
if ( F_205 () )
return;
if ( V_174 )
F_209 () ;
else
F_210 ( F_202 ) ;
}
void F_211 ( void )
{
F_52 ( ! F_53 ( & V_61 ) &&
! F_53 ( & V_60 ) &&
! F_53 ( & V_62 ) ,
L_53 ) ;
if ( F_205 () )
return;
if ( V_174 )
F_212 () ;
else
F_210 ( F_203 ) ;
}
unsigned long F_213 ( void )
{
F_14 () ;
return F_214 ( & V_23 -> V_4 ) ;
}
void F_215 ( unsigned long V_175 )
{
unsigned long V_176 ;
V_176 = F_214 ( & V_23 -> V_3 ) ;
if ( F_82 ( V_175 , V_176 ) )
F_216 () ;
}
static int F_217 ( void * V_177 )
{
F_14 () ;
return 0 ;
}
void F_209 ( void )
{
long V_178 , V_100 , V_76 ;
int V_179 = 0 ;
struct V_1 * V_2 = & V_21 ;
if ( F_82 ( ( V_180 ) F_218 ( & V_2 -> V_181 ) ,
( V_180 ) F_218 ( & V_2 -> V_182 ) +
V_97 / 8 ) ) {
F_208 () ;
F_219 ( & V_2 -> V_183 ) ;
return;
}
V_76 = F_220 ( & V_2 -> V_181 ) ;
V_178 = V_76 ;
F_221 () ;
F_50 ( F_84 ( F_222 () ) ) ;
while ( F_223 ( V_184 ,
F_217 ,
NULL ) == - V_185 ) {
F_224 () ;
F_219 ( & V_2 -> V_186 ) ;
V_100 = F_218 ( & V_2 -> V_182 ) ;
if ( F_82 ( ( V_180 ) V_100 , ( V_180 ) V_178 ) ) {
F_16 () ;
F_219 ( & V_2 -> V_187 ) ;
return;
}
if ( V_179 ++ < 10 ) {
F_225 ( V_179 * F_207 () ) ;
} else {
F_210 ( F_202 ) ;
F_219 ( & V_2 -> V_188 ) ;
return;
}
V_100 = F_218 ( & V_2 -> V_182 ) ;
if ( F_82 ( ( V_180 ) V_100 , ( V_180 ) V_178 ) ) {
F_16 () ;
F_219 ( & V_2 -> V_189 ) ;
return;
}
F_221 () ;
V_76 = F_218 ( & V_2 -> V_181 ) ;
F_14 () ;
}
F_219 ( & V_2 -> V_190 ) ;
do {
F_219 ( & V_2 -> V_191 ) ;
V_100 = F_218 ( & V_2 -> V_182 ) ;
if ( F_82 ( ( V_180 ) V_100 , ( V_180 ) V_76 ) ) {
F_16 () ;
F_219 ( & V_2 -> V_192 ) ;
break;
}
} while ( F_226 ( & V_2 -> V_182 , V_100 , V_76 ) != V_100 );
F_219 ( & V_2 -> V_193 ) ;
F_224 () ;
}
static int F_227 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
struct V_40 * V_42 = V_7 -> V_18 ;
V_7 -> V_194 ++ ;
F_105 ( V_2 , V_7 ) ;
if ( F_228 ( V_2 ) )
return 0 ;
if ( V_70 &&
V_7 -> V_108 && ! V_7 -> V_9 ) {
V_7 -> V_195 ++ ;
} else if ( V_7 -> V_108 && V_7 -> V_9 ) {
V_7 -> V_196 ++ ;
return 1 ;
}
if ( F_35 ( V_7 ) ) {
V_7 -> V_197 ++ ;
return 1 ;
}
if ( F_38 ( V_2 , V_7 ) ) {
V_7 -> V_198 ++ ;
return 1 ;
}
if ( F_2 ( V_42 -> V_3 ) != V_7 -> V_3 ) {
V_7 -> V_199 ++ ;
return 1 ;
}
if ( F_2 ( V_42 -> V_4 ) != V_7 -> V_4 ) {
V_7 -> V_200 ++ ;
return 1 ;
}
if ( F_229 ( V_7 ) ) {
V_7 -> V_201 ++ ;
return 1 ;
}
V_7 -> V_202 ++ ;
return 0 ;
}
static int F_182 ( int V_5 )
{
struct V_1 * V_2 ;
F_12 (rsp)
if ( F_227 ( V_2 , F_101 ( V_2 -> V_16 , V_5 ) ) )
return 1 ;
return 0 ;
}
static int V_56 F_230 ( int V_5 , bool * V_203 )
{
bool V_204 = true ;
bool V_205 = false ;
struct V_6 * V_7 ;
struct V_1 * V_2 ;
F_12 (rsp) {
V_7 = F_101 ( V_2 -> V_16 , V_5 ) ;
if ( ! V_7 -> V_37 )
continue;
V_205 = true ;
if ( V_7 -> V_93 != V_7 -> V_135 || ! V_203 ) {
V_204 = false ;
break;
}
}
if ( V_203 )
* V_203 = V_204 ;
return V_205 ;
}
static void F_231 ( struct V_1 * V_2 , const char * V_100 ,
int V_5 , unsigned long V_206 )
{
F_232 ( V_2 -> V_24 , V_100 , V_5 ,
F_51 ( & V_2 -> V_207 ) , V_206 ) ;
}
static void F_233 ( struct V_146 * V_170 )
{
struct V_6 * V_7 = F_234 ( V_170 , struct V_6 , V_208 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
if ( F_235 ( & V_2 -> V_207 ) ) {
F_231 ( V_2 , L_54 , - 1 , V_2 -> V_209 ) ;
F_236 ( & V_2 -> V_210 ) ;
} else {
F_231 ( V_2 , L_55 , - 1 , V_2 -> V_209 ) ;
}
}
static void F_237 ( void * type )
{
struct V_1 * V_2 = type ;
struct V_6 * V_7 = F_13 ( V_2 -> V_16 ) ;
F_231 ( V_2 , L_56 , - 1 , V_2 -> V_209 ) ;
F_49 ( & V_2 -> V_207 ) ;
V_2 -> V_211 ( & V_7 -> V_208 , F_233 ) ;
}
static void F_238 ( struct V_1 * V_2 )
{
int V_5 ;
struct V_6 * V_7 ;
unsigned long V_76 = F_2 ( V_2 -> V_209 ) ;
unsigned long V_212 ;
F_231 ( V_2 , L_57 , - 1 , V_76 ) ;
F_133 ( & V_2 -> V_213 ) ;
F_14 () ;
V_212 = V_2 -> V_209 ;
F_231 ( V_2 , L_58 , - 1 , V_212 ) ;
if ( F_82 ( V_212 , ( V_76 + 3 ) & ~ 0x1 ) ) {
F_231 ( V_2 , L_59 , - 1 , V_212 ) ;
F_14 () ;
F_139 ( & V_2 -> V_213 ) ;
return;
}
F_2 ( V_2 -> V_209 ) = V_2 -> V_209 + 1 ;
F_50 ( ( V_2 -> V_209 & 0x1 ) != 1 ) ;
F_231 ( V_2 , L_60 , - 1 , V_2 -> V_209 ) ;
F_14 () ;
F_239 ( & V_2 -> V_210 ) ;
F_240 ( & V_2 -> V_207 , 1 ) ;
F_221 () ;
F_100 (cpu) {
if ( ! F_190 ( V_5 ) && ! F_158 ( V_5 ) )
continue;
V_7 = F_101 ( V_2 -> V_16 , V_5 ) ;
if ( F_158 ( V_5 ) ) {
F_231 ( V_2 , L_61 , V_5 ,
V_2 -> V_209 ) ;
F_49 ( & V_2 -> V_207 ) ;
F_195 ( & V_7 -> V_208 , F_233 ,
V_2 , V_5 , 0 ) ;
} else if ( F_2 ( V_7 -> V_93 ) ) {
F_231 ( V_2 , L_62 , V_5 ,
V_2 -> V_209 ) ;
F_241 ( V_5 , F_237 , V_2 , 1 ) ;
} else {
F_231 ( V_2 , L_63 , V_5 ,
V_2 -> V_209 ) ;
}
}
F_224 () ;
if ( F_235 ( & V_2 -> V_207 ) )
F_236 ( & V_2 -> V_210 ) ;
F_14 () ;
F_2 ( V_2 -> V_209 ) = V_2 -> V_209 + 1 ;
F_50 ( ( V_2 -> V_209 & 0x1 ) != 0 ) ;
F_231 ( V_2 , L_64 , - 1 , V_2 -> V_209 ) ;
F_14 () ;
F_242 ( & V_2 -> V_210 ) ;
F_139 ( & V_2 -> V_213 ) ;
}
void F_243 ( void )
{
F_238 ( & V_22 ) ;
}
void F_244 ( void )
{
F_238 ( & V_21 ) ;
}
static void T_4
F_245 ( int V_5 , struct V_1 * V_2 )
{
unsigned long V_11 ;
struct V_6 * V_7 = F_101 ( V_2 -> V_16 , V_5 ) ;
struct V_40 * V_42 = F_36 ( V_2 ) ;
F_91 ( & V_42 -> V_85 , V_11 ) ;
V_7 -> V_68 = 1UL << ( V_5 - V_7 -> V_18 -> V_88 ) ;
F_108 ( V_7 ) ;
V_7 -> V_135 = 0 ;
F_2 ( V_7 -> V_93 ) = 0 ;
V_7 -> V_20 = & F_4 ( V_12 , V_5 ) ;
F_50 ( V_7 -> V_20 -> V_53 != V_65 ) ;
F_50 ( F_51 ( & V_7 -> V_20 -> V_20 ) != 1 ) ;
V_7 -> V_5 = V_5 ;
V_7 -> V_2 = V_2 ;
F_246 ( V_7 ) ;
F_93 ( & V_42 -> V_85 , V_11 ) ;
}
static void
F_247 ( int V_5 , struct V_1 * V_2 )
{
unsigned long V_11 ;
unsigned long V_131 ;
struct V_6 * V_7 = F_101 ( V_2 -> V_16 , V_5 ) ;
struct V_40 * V_42 = F_36 ( V_2 ) ;
F_133 ( & V_2 -> V_110 ) ;
F_91 ( & V_42 -> V_85 , V_11 ) ;
V_7 -> V_164 = 1 ;
V_7 -> V_157 = 0 ;
V_7 -> V_158 = V_2 -> V_113 ;
V_7 -> V_153 = V_153 ;
F_108 ( V_7 ) ;
V_7 -> V_20 -> V_53 = V_65 ;
F_248 ( V_7 -> V_20 ) ;
F_240 ( & V_7 -> V_20 -> V_20 ,
( F_51 ( & V_7 -> V_20 -> V_20 ) & ~ 0x1 ) + 1 ) ;
F_117 ( & V_42 -> V_85 ) ;
V_42 = V_7 -> V_18 ;
V_131 = V_7 -> V_68 ;
do {
F_114 ( & V_42 -> V_85 ) ;
V_42 -> V_69 |= V_131 ;
V_131 = V_42 -> V_68 ;
if ( V_42 == V_7 -> V_18 ) {
V_7 -> V_4 = V_42 -> V_3 ;
V_7 -> V_3 = V_42 -> V_3 ;
V_7 -> V_9 = 0 ;
V_7 -> V_108 = 0 ;
F_5 ( V_2 -> V_24 , V_7 -> V_4 , F_6 ( L_65 ) ) ;
}
F_117 ( & V_42 -> V_85 ) ;
V_42 = V_42 -> V_134 ;
} while ( V_42 != NULL && ! ( V_42 -> V_69 & V_131 ) );
F_19 ( V_11 ) ;
F_139 ( & V_2 -> V_110 ) ;
}
static void F_249 ( int V_5 )
{
struct V_1 * V_2 ;
F_12 (rsp)
F_247 ( V_5 , V_2 ) ;
}
static int F_250 ( struct V_214 * V_215 ,
unsigned long V_216 , void * V_217 )
{
long V_5 = ( long ) V_217 ;
struct V_6 * V_7 = F_101 ( V_23 -> V_16 , V_5 ) ;
struct V_40 * V_42 = V_7 -> V_18 ;
struct V_1 * V_2 ;
F_21 ( F_6 ( L_66 ) ) ;
switch ( V_216 ) {
case V_218 :
case V_219 :
F_249 ( V_5 ) ;
F_251 ( V_5 ) ;
break;
case V_220 :
case V_221 :
F_165 ( V_42 , - 1 ) ;
break;
case V_222 :
F_165 ( V_42 , V_5 ) ;
break;
case V_223 :
case V_224 :
F_12 (rsp)
F_162 ( V_2 ) ;
break;
case V_225 :
case V_226 :
case V_227 :
case V_228 :
F_12 (rsp)
F_164 ( V_5 , V_2 ) ;
break;
default:
break;
}
F_21 ( F_6 ( L_67 ) ) ;
return V_229 ;
}
static int F_252 ( struct V_214 * V_215 ,
unsigned long V_216 , void * V_217 )
{
switch ( V_216 ) {
case V_230 :
case V_231 :
if ( V_232 <= 256 )
V_174 = 1 ;
break;
case V_233 :
case V_234 :
V_174 = 0 ;
break;
default:
break;
}
return V_229 ;
}
static int T_4 F_253 ( void )
{
unsigned long V_11 ;
struct V_40 * V_42 ;
struct V_1 * V_2 ;
struct V_55 * V_235 ;
F_12 (rsp) {
V_235 = F_254 ( F_146 , V_2 , L_68 , V_2 -> V_24 ) ;
F_255 ( F_256 ( V_235 ) ) ;
V_42 = F_36 ( V_2 ) ;
F_91 ( & V_42 -> V_85 , V_11 ) ;
V_2 -> V_26 = V_235 ;
F_93 ( & V_42 -> V_85 , V_11 ) ;
F_257 ( V_2 ) ;
}
return 0 ;
}
void F_258 ( void )
{
F_259 ( F_207 () != 1 ) ;
F_259 ( F_260 () > 0 ) ;
V_236 = 1 ;
}
static void T_4 F_261 ( struct V_1 * V_2 )
{
int V_46 ;
V_2 -> V_237 [ V_238 - 1 ] = V_239 ;
for ( V_46 = V_238 - 2 ; V_46 >= 0 ; V_46 -- )
V_2 -> V_237 [ V_46 ] = V_240 ;
}
static void T_4 F_261 ( struct V_1 * V_2 )
{
int V_241 ;
int V_242 ;
int V_46 ;
V_242 = V_232 ;
for ( V_46 = V_238 - 1 ; V_46 >= 0 ; V_46 -- ) {
V_241 = V_2 -> V_243 [ V_46 ] ;
V_2 -> V_237 [ V_46 ] = ( V_242 + V_241 - 1 ) / V_241 ;
V_242 = V_241 ;
}
}
static void T_4 F_262 ( struct V_1 * V_2 ,
struct V_6 T_5 * V_16 )
{
static const char * const V_244 [] = {
L_69 ,
L_70 ,
L_71 ,
L_72 } ;
static const char * const V_245 [] = {
L_73 ,
L_74 ,
L_75 ,
L_76 } ;
static T_6 V_246 = 0x1 ;
int V_247 = 1 ;
int V_46 ;
int V_83 ;
struct V_40 * V_42 ;
F_263 ( V_248 > F_264 ( V_244 ) ) ;
if ( V_238 > V_249 )
F_265 ( L_77 ) ;
for ( V_46 = 0 ; V_46 < V_238 ; V_46 ++ )
V_2 -> V_243 [ V_46 ] = V_250 [ V_46 ] ;
for ( V_46 = 1 ; V_46 < V_238 ; V_46 ++ )
V_2 -> V_101 [ V_46 ] = V_2 -> V_101 [ V_46 - 1 ] + V_2 -> V_243 [ V_46 - 1 ] ;
F_261 ( V_2 ) ;
V_2 -> V_17 = V_246 ;
V_246 <<= 1 ;
for ( V_46 = V_238 - 1 ; V_46 >= 0 ; V_46 -- ) {
V_247 *= V_2 -> V_237 [ V_46 ] ;
V_42 = V_2 -> V_101 [ V_46 ] ;
for ( V_83 = 0 ; V_83 < V_2 -> V_243 [ V_46 ] ; V_83 ++ , V_42 ++ ) {
F_266 ( & V_42 -> V_85 ) ;
F_267 ( & V_42 -> V_85 ,
& V_251 [ V_46 ] , V_244 [ V_46 ] ) ;
F_266 ( & V_42 -> V_162 ) ;
F_267 ( & V_42 -> V_162 ,
& V_252 [ V_46 ] , V_245 [ V_46 ] ) ;
V_42 -> V_4 = V_2 -> V_4 ;
V_42 -> V_3 = V_2 -> V_3 ;
V_42 -> V_86 = 0 ;
V_42 -> V_69 = 0 ;
V_42 -> V_88 = V_83 * V_247 ;
V_42 -> V_87 = ( V_83 + 1 ) * V_247 - 1 ;
if ( V_42 -> V_87 >= V_232 )
V_42 -> V_87 = V_232 - 1 ;
if ( V_46 == 0 ) {
V_42 -> V_253 = 0 ;
V_42 -> V_68 = 0 ;
V_42 -> V_134 = NULL ;
} else {
V_42 -> V_253 = V_83 % V_2 -> V_237 [ V_46 - 1 ] ;
V_42 -> V_68 = 1UL << V_42 -> V_253 ;
V_42 -> V_134 = V_2 -> V_101 [ V_46 - 1 ] +
V_83 / V_2 -> V_237 [ V_46 - 1 ] ;
}
V_42 -> V_101 = V_46 ;
F_268 ( & V_42 -> V_254 ) ;
F_269 ( V_42 ) ;
}
}
V_2 -> V_16 = V_16 ;
F_270 ( & V_2 -> V_107 ) ;
V_42 = V_2 -> V_101 [ V_238 - 1 ] ;
F_100 (i) {
while ( V_46 > V_42 -> V_87 )
V_42 ++ ;
F_101 ( V_2 -> V_16 , V_46 ) -> V_18 = V_42 ;
F_245 ( V_46 , V_2 ) ;
}
F_271 ( & V_2 -> V_255 , & V_256 ) ;
}
static void T_4 F_272 ( void )
{
V_180 V_257 ;
int V_46 ;
int V_83 ;
int V_258 = V_232 ;
int V_259 [ V_248 + 1 ] ;
V_257 = V_260 + V_232 / V_261 ;
if ( V_126 == V_97 )
V_126 = V_257 ;
if ( V_130 == V_97 )
V_130 = V_257 ;
if ( V_239 == V_262 &&
V_232 == V_263 )
return;
F_30 ( L_78 ,
V_239 , V_232 ) ;
V_259 [ 0 ] = 1 ;
V_259 [ 1 ] = V_239 ;
for ( V_46 = 2 ; V_46 <= V_248 ; V_46 ++ )
V_259 [ V_46 ] = V_259 [ V_46 - 1 ] * V_240 ;
if ( V_239 < V_262 ||
V_239 > sizeof( unsigned long ) * 8 ||
V_258 > V_259 [ V_248 ] ) {
F_259 ( 1 ) ;
return;
}
for ( V_46 = 1 ; V_46 <= V_248 ; V_46 ++ )
if ( V_258 <= V_259 [ V_46 ] ) {
for ( V_83 = 0 ; V_83 <= V_46 ; V_83 ++ )
V_250 [ V_83 ] =
F_273 ( V_258 , V_259 [ V_46 - V_83 ] ) ;
V_238 = V_46 ;
for ( V_83 = V_46 + 1 ; V_83 <= V_248 ; V_83 ++ )
V_250 [ V_83 ] = 0 ;
break;
}
V_264 = 0 ;
for ( V_46 = 0 ; V_46 <= V_248 ; V_46 ++ )
V_264 += V_250 [ V_46 ] ;
V_264 -= V_258 ;
}
void T_4 F_274 ( void )
{
int V_5 ;
F_275 () ;
F_272 () ;
F_262 ( & V_22 , & V_10 ) ;
F_262 ( & V_21 , & V_8 ) ;
F_276 () ;
F_277 ( V_168 , F_187 ) ;
F_278 ( F_250 , 0 ) ;
F_279 ( F_252 , 0 ) ;
F_280 (cpu)
F_250 ( NULL , V_218 , ( void * ) ( long ) V_5 ) ;
}
