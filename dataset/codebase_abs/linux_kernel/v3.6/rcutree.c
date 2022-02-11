static int F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_2 -> V_3 ) != F_2 ( V_2 -> V_4 ) ;
}
void F_3 ( int V_5 )
{
struct V_6 * V_7 = & F_4 ( V_8 , V_5 ) ;
V_7 -> V_9 = V_7 -> V_4 ;
F_5 () ;
if ( V_7 -> V_10 == 0 )
F_6 ( L_1 , V_7 -> V_4 , L_2 ) ;
V_7 -> V_10 = 1 ;
}
void F_7 ( int V_5 )
{
struct V_6 * V_7 = & F_4 ( V_11 , V_5 ) ;
V_7 -> V_9 = V_7 -> V_4 ;
F_5 () ;
if ( V_7 -> V_10 == 0 )
F_6 ( L_3 , V_7 -> V_4 , L_2 ) ;
V_7 -> V_10 = 1 ;
}
void F_8 ( int V_5 )
{
F_9 ( L_4 ) ;
F_3 ( V_5 ) ;
F_10 ( V_5 ) ;
F_9 ( L_5 ) ;
}
long F_11 ( void )
{
return V_12 . V_3 ;
}
long F_12 ( void )
{
return V_13 . V_3 ;
}
void F_13 ( void )
{
F_14 ( & V_13 , 0 ) ;
}
void F_15 ( void )
{
V_14 ++ ;
V_15 = 0 ;
}
void F_16 ( unsigned long V_16 )
{
V_15 ++ ;
}
void F_17 ( void )
{
F_14 ( & V_12 , 0 ) ;
}
static int
F_18 ( struct V_6 * V_7 )
{
return & V_7 -> V_17 != V_7 -> V_18 [ V_19 ] ;
}
static int
F_19 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
return * V_7 -> V_18 [ V_19 ] && ! F_1 ( V_2 ) ;
}
static struct V_20 * F_20 ( struct V_1 * V_2 )
{
return & V_2 -> V_21 [ 0 ] ;
}
static int F_21 ( struct V_6 * V_7 )
{
if ( F_22 ( V_7 -> V_5 ) &&
F_23 ( V_7 -> V_2 -> V_22 + 2 , V_23 ) ) {
F_24 ( V_7 -> V_2 -> V_24 , V_7 -> V_4 , V_7 -> V_5 , L_6 ) ;
V_7 -> V_25 ++ ;
return 1 ;
}
return 0 ;
}
static void F_25 ( struct V_26 * V_27 , long long V_28 )
{
F_26 ( L_7 , V_28 , 0 ) ;
if ( ! F_27 ( V_29 ) ) {
struct V_30 * V_31 = F_28 ( F_29 () ) ;
F_26 ( L_8 , V_28 , 0 ) ;
F_30 ( V_32 ) ;
F_31 ( 1 , L_9 ,
V_29 -> V_33 , V_29 -> V_34 ,
V_31 -> V_33 , V_31 -> V_34 ) ;
}
F_32 ( F_29 () ) ;
F_33 () ;
F_34 ( & V_27 -> V_35 ) ;
F_35 () ;
F_36 ( F_37 ( & V_27 -> V_35 ) & 0x1 ) ;
F_38 ( ! F_39 ( & V_36 ) ,
L_10 ) ;
F_38 ( ! F_39 ( & V_37 ) ,
L_11 ) ;
F_38 ( ! F_39 ( & V_38 ) ,
L_12 ) ;
}
void F_40 ( void )
{
unsigned long V_39 ;
long long V_28 ;
struct V_26 * V_27 ;
F_41 ( V_39 ) ;
V_27 = & F_42 ( V_26 ) ;
V_28 = V_27 -> V_40 ;
F_36 ( ( V_28 & V_41 ) == 0 ) ;
if ( ( V_28 & V_41 ) == V_42 )
V_27 -> V_40 = 0 ;
else
V_27 -> V_40 -= V_42 ;
F_25 ( V_27 , V_28 ) ;
F_43 ( V_39 ) ;
}
void F_44 ( void )
{
unsigned long V_39 ;
long long V_28 ;
struct V_26 * V_27 ;
F_41 ( V_39 ) ;
V_27 = & F_42 ( V_26 ) ;
V_28 = V_27 -> V_40 ;
V_27 -> V_40 -- ;
F_36 ( V_27 -> V_40 < 0 ) ;
if ( V_27 -> V_40 )
F_26 ( L_13 , V_28 , V_27 -> V_40 ) ;
else
F_25 ( V_27 , V_28 ) ;
F_43 ( V_39 ) ;
}
static void F_45 ( struct V_26 * V_27 , long long V_28 )
{
F_33 () ;
F_34 ( & V_27 -> V_35 ) ;
F_35 () ;
F_36 ( ! ( F_37 ( & V_27 -> V_35 ) & 0x1 ) ) ;
F_46 ( F_29 () ) ;
F_26 ( L_14 , V_28 , V_27 -> V_40 ) ;
if ( ! F_27 ( V_29 ) ) {
struct V_30 * V_31 = F_28 ( F_29 () ) ;
F_26 ( L_15 ,
V_28 , V_27 -> V_40 ) ;
F_30 ( V_32 ) ;
F_31 ( 1 , L_9 ,
V_29 -> V_33 , V_29 -> V_34 ,
V_31 -> V_33 , V_31 -> V_34 ) ;
}
}
void F_47 ( void )
{
unsigned long V_39 ;
struct V_26 * V_27 ;
long long V_28 ;
F_41 ( V_39 ) ;
V_27 = & F_42 ( V_26 ) ;
V_28 = V_27 -> V_40 ;
F_36 ( V_28 < 0 ) ;
if ( V_28 & V_41 )
V_27 -> V_40 += V_42 ;
else
V_27 -> V_40 = V_43 ;
F_45 ( V_27 , V_28 ) ;
F_43 ( V_39 ) ;
}
void F_48 ( void )
{
unsigned long V_39 ;
struct V_26 * V_27 ;
long long V_28 ;
F_41 ( V_39 ) ;
V_27 = & F_42 ( V_26 ) ;
V_28 = V_27 -> V_40 ;
V_27 -> V_40 ++ ;
F_36 ( V_27 -> V_40 == 0 ) ;
if ( V_28 )
F_26 ( L_16 , V_28 , V_27 -> V_40 ) ;
else
F_45 ( V_27 , V_28 ) ;
F_43 ( V_39 ) ;
}
void F_49 ( void )
{
struct V_26 * V_27 = & F_42 ( V_26 ) ;
if ( V_27 -> V_44 == 0 &&
( F_37 ( & V_27 -> V_35 ) & 0x1 ) )
return;
V_27 -> V_44 ++ ;
F_33 () ;
F_34 ( & V_27 -> V_35 ) ;
F_35 () ;
F_36 ( ! ( F_37 ( & V_27 -> V_35 ) & 0x1 ) ) ;
}
void F_50 ( void )
{
struct V_26 * V_27 = & F_42 ( V_26 ) ;
if ( V_27 -> V_44 == 0 ||
-- V_27 -> V_44 != 0 )
return;
F_33 () ;
F_34 ( & V_27 -> V_35 ) ;
F_35 () ;
F_36 ( F_37 ( & V_27 -> V_35 ) & 0x1 ) ;
}
int F_51 ( void )
{
int V_45 ;
F_52 () ;
V_45 = ( F_37 ( & F_42 ( V_26 ) . V_35 ) & 0x1 ) == 0 ;
F_53 () ;
return V_45 ;
}
bool F_54 ( void )
{
struct V_6 * V_7 ;
struct V_20 * V_46 ;
bool V_45 ;
if ( F_55 () )
return 1 ;
F_52 () ;
V_7 = & F_42 ( V_8 ) ;
V_46 = V_7 -> V_47 ;
V_45 = ( V_7 -> V_48 & V_46 -> V_49 ) ||
! V_50 ;
F_53 () ;
return V_45 ;
}
int F_56 ( void )
{
return F_42 ( V_26 ) . V_40 <= 1 ;
}
static int F_57 ( struct V_6 * V_7 )
{
V_7 -> V_51 = F_58 ( 0 , & V_7 -> V_35 -> V_35 ) ;
return ( V_7 -> V_51 & 0x1 ) == 0 ;
}
static int F_59 ( struct V_6 * V_7 )
{
unsigned int V_52 ;
unsigned int V_53 ;
V_52 = ( unsigned int ) F_58 ( 0 , & V_7 -> V_35 -> V_35 ) ;
V_53 = ( unsigned int ) V_7 -> V_51 ;
if ( ( V_52 & 0x1 ) == 0 || F_60 ( V_52 , V_53 + 2 ) ) {
F_24 ( V_7 -> V_2 -> V_24 , V_7 -> V_4 , V_7 -> V_5 , L_17 ) ;
V_7 -> V_54 ++ ;
return 1 ;
}
return F_21 ( V_7 ) ;
}
static int F_61 ( void )
{
int V_55 = F_2 ( V_56 ) ;
if ( V_55 < 3 ) {
F_2 ( V_56 ) = 3 ;
V_55 = 3 ;
} else if ( V_55 > 300 ) {
F_2 ( V_56 ) = 300 ;
V_55 = 300 ;
}
return V_55 * V_57 + V_58 ;
}
static void F_62 ( struct V_1 * V_2 )
{
V_2 -> V_22 = V_23 ;
V_2 -> V_59 = V_23 + F_61 () ;
}
static void F_63 ( struct V_1 * V_2 )
{
int V_5 ;
long V_60 ;
unsigned long V_39 ;
int V_61 = 0 ;
struct V_20 * V_46 = F_20 ( V_2 ) ;
F_64 ( & V_46 -> V_62 , V_39 ) ;
V_60 = V_23 - V_2 -> V_59 ;
if ( V_60 < V_63 || ! F_1 ( V_2 ) ) {
F_65 ( & V_46 -> V_62 , V_39 ) ;
return;
}
V_2 -> V_59 = V_23 + 3 * F_61 () + 3 ;
F_65 ( & V_46 -> V_62 , V_39 ) ;
F_66 ( V_64 L_18 ,
V_2 -> V_24 ) ;
F_67 () ;
F_68 (rsp, rnp) {
F_64 ( & V_46 -> V_62 , V_39 ) ;
V_61 += F_69 ( V_46 ) ;
F_65 ( & V_46 -> V_62 , V_39 ) ;
if ( V_46 -> V_65 == 0 )
continue;
for ( V_5 = 0 ; V_5 <= V_46 -> V_66 - V_46 -> V_67 ; V_5 ++ )
if ( V_46 -> V_65 & ( 1UL << V_5 ) ) {
F_70 ( V_2 , V_46 -> V_67 + V_5 ) ;
V_61 ++ ;
}
}
V_46 = F_20 ( V_2 ) ;
F_64 ( & V_46 -> V_62 , V_39 ) ;
V_61 += F_69 ( V_46 ) ;
F_65 ( & V_46 -> V_62 , V_39 ) ;
F_71 () ;
F_66 ( V_68 L_19 ,
F_29 () , ( long ) ( V_23 - V_2 -> V_22 ) ) ;
if ( V_61 == 0 )
F_66 ( V_64 L_20 ) ;
else if ( ! F_72 () )
F_73 () ;
F_74 ( V_2 ) ;
F_14 ( V_2 , 0 ) ;
}
static void F_75 ( struct V_1 * V_2 )
{
unsigned long V_39 ;
struct V_20 * V_46 = F_20 ( V_2 ) ;
F_66 ( V_64 L_21 , V_2 -> V_24 ) ;
F_67 () ;
F_70 ( V_2 , F_29 () ) ;
F_71 () ;
F_66 ( V_68 L_22 , V_23 - V_2 -> V_22 ) ;
if ( ! F_72 () )
F_73 () ;
F_64 ( & V_46 -> V_62 , V_39 ) ;
if ( F_76 ( V_23 , V_2 -> V_59 ) )
V_2 -> V_59 = V_23 +
3 * F_61 () + 3 ;
F_65 ( & V_46 -> V_62 , V_39 ) ;
F_77 () ;
}
static void F_78 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
unsigned long V_69 ;
unsigned long V_70 ;
struct V_20 * V_46 ;
if ( V_71 )
return;
V_69 = F_2 ( V_23 ) ;
V_70 = F_2 ( V_2 -> V_59 ) ;
V_46 = V_7 -> V_47 ;
if ( ( F_2 ( V_46 -> V_65 ) & V_7 -> V_48 ) && F_76 ( V_69 , V_70 ) ) {
F_75 ( V_2 ) ;
} else if ( F_1 ( V_2 ) &&
F_76 ( V_69 , V_70 + V_63 ) ) {
F_63 ( V_2 ) ;
}
}
static int F_79 ( struct V_72 * V_73 , unsigned long V_74 , void * V_75 )
{
V_71 = 1 ;
return V_76 ;
}
void F_80 ( void )
{
struct V_1 * V_2 ;
F_81 (rsp)
V_2 -> V_59 = V_23 + V_77 / 2 ;
}
static void T_1 F_82 ( void )
{
F_83 ( & V_78 , & V_79 ) ;
}
static void F_84 ( struct V_1 * V_2 , struct V_20 * V_46 , struct V_6 * V_7 )
{
if ( V_7 -> V_4 != V_46 -> V_4 ) {
V_7 -> V_4 = V_46 -> V_4 ;
F_6 ( V_2 -> V_24 , V_7 -> V_4 , L_23 ) ;
if ( V_46 -> V_65 & V_7 -> V_48 ) {
V_7 -> V_80 = 1 ;
V_7 -> V_10 = 0 ;
} else {
V_7 -> V_80 = 0 ;
}
F_85 ( V_7 ) ;
}
}
static void F_86 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
unsigned long V_39 ;
struct V_20 * V_46 ;
F_41 ( V_39 ) ;
V_46 = V_7 -> V_47 ;
if ( V_7 -> V_4 == F_2 ( V_46 -> V_4 ) ||
! F_87 ( & V_46 -> V_62 ) ) {
F_43 ( V_39 ) ;
return;
}
F_84 ( V_2 , V_46 , V_7 ) ;
F_65 ( & V_46 -> V_62 , V_39 ) ;
}
static int
F_88 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
unsigned long V_39 ;
int V_45 = 0 ;
F_41 ( V_39 ) ;
if ( V_7 -> V_4 != V_2 -> V_4 ) {
F_86 ( V_2 , V_7 ) ;
V_45 = 1 ;
}
F_43 ( V_39 ) ;
return V_45 ;
}
static void F_89 ( struct V_6 * V_7 )
{
int V_81 ;
V_7 -> V_17 = NULL ;
for ( V_81 = 0 ; V_81 < V_82 ; V_81 ++ )
V_7 -> V_18 [ V_81 ] = & V_7 -> V_17 ;
}
static void
F_90 ( struct V_1 * V_2 , struct V_20 * V_46 , struct V_6 * V_7 )
{
if ( V_7 -> V_3 != V_46 -> V_3 ) {
V_7 -> V_18 [ V_19 ] = V_7 -> V_18 [ V_83 ] ;
V_7 -> V_18 [ V_83 ] = V_7 -> V_18 [ V_84 ] ;
V_7 -> V_18 [ V_84 ] = V_7 -> V_18 [ V_85 ] ;
V_7 -> V_3 = V_46 -> V_3 ;
F_6 ( V_2 -> V_24 , V_7 -> V_4 , L_24 ) ;
if ( F_23 ( V_7 -> V_4 , V_7 -> V_3 ) )
V_7 -> V_4 = V_7 -> V_3 ;
if ( ( V_46 -> V_65 & V_7 -> V_48 ) == 0 )
V_7 -> V_80 = 0 ;
}
}
static void
F_91 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
unsigned long V_39 ;
struct V_20 * V_46 ;
F_41 ( V_39 ) ;
V_46 = V_7 -> V_47 ;
if ( V_7 -> V_3 == F_2 ( V_46 -> V_3 ) ||
! F_87 ( & V_46 -> V_62 ) ) {
F_43 ( V_39 ) ;
return;
}
F_90 ( V_2 , V_46 , V_7 ) ;
F_65 ( & V_46 -> V_62 , V_39 ) ;
}
static void
F_92 ( struct V_1 * V_2 , struct V_20 * V_46 , struct V_6 * V_7 )
{
F_90 ( V_2 , V_46 , V_7 ) ;
V_7 -> V_18 [ V_84 ] = V_7 -> V_18 [ V_85 ] ;
V_7 -> V_18 [ V_83 ] = V_7 -> V_18 [ V_85 ] ;
F_84 ( V_2 , V_46 , V_7 ) ;
}
static void
F_93 ( struct V_1 * V_2 , unsigned long V_39 )
__releases( rcu_get_root( V_2 )->lock
static void F_94 ( struct V_1 * V_2 , unsigned long V_39 )
__releases( rcu_get_root( V_2 )->lock
static void
F_95 ( unsigned long V_86 , struct V_1 * V_2 ,
struct V_20 * V_46 , unsigned long V_39 )
__releases( V_46 -> V_62 )
{
struct V_20 * V_87 ;
for (; ; ) {
if ( ! ( V_46 -> V_65 & V_86 ) ) {
F_65 ( & V_46 -> V_62 , V_39 ) ;
return;
}
V_46 -> V_65 &= ~ V_86 ;
F_96 ( V_2 -> V_24 , V_46 -> V_4 ,
V_86 , V_46 -> V_65 , V_46 -> V_88 ,
V_46 -> V_67 , V_46 -> V_66 ,
! ! V_46 -> V_89 ) ;
if ( V_46 -> V_65 != 0 || F_97 ( V_46 ) ) {
F_65 ( & V_46 -> V_62 , V_39 ) ;
return;
}
V_86 = V_46 -> V_48 ;
if ( V_46 -> V_90 == NULL ) {
break;
}
F_65 ( & V_46 -> V_62 , V_39 ) ;
V_87 = V_46 ;
V_46 = V_46 -> V_90 ;
F_64 ( & V_46 -> V_62 , V_39 ) ;
F_36 ( V_87 -> V_65 ) ;
}
F_94 ( V_2 , V_39 ) ;
}
static void
F_98 ( int V_5 , struct V_1 * V_2 , struct V_6 * V_7 , long V_91 )
{
unsigned long V_39 ;
unsigned long V_86 ;
struct V_20 * V_46 ;
V_46 = V_7 -> V_47 ;
F_64 ( & V_46 -> V_62 , V_39 ) ;
if ( V_91 != V_46 -> V_4 || V_46 -> V_3 == V_46 -> V_4 ) {
V_7 -> V_10 = 0 ;
F_65 ( & V_46 -> V_62 , V_39 ) ;
return;
}
V_86 = V_7 -> V_48 ;
if ( ( V_46 -> V_65 & V_86 ) == 0 ) {
F_65 ( & V_46 -> V_62 , V_39 ) ;
} else {
V_7 -> V_80 = 0 ;
V_7 -> V_18 [ V_84 ] = V_7 -> V_18 [ V_85 ] ;
F_95 ( V_86 , V_2 , V_46 , V_39 ) ;
}
}
static void
F_99 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
if ( F_88 ( V_2 , V_7 ) )
return;
if ( ! V_7 -> V_80 )
return;
if ( ! V_7 -> V_10 )
return;
F_98 ( V_7 -> V_5 , V_2 , V_7 , V_7 -> V_9 ) ;
}
static void
F_100 ( int V_5 , struct V_1 * V_2 ,
struct V_20 * V_46 , struct V_6 * V_7 )
{
if ( V_7 -> V_17 != NULL ) {
V_2 -> V_92 += V_7 -> V_92 ;
V_2 -> V_93 += V_7 -> V_93 ;
V_7 -> V_94 += V_7 -> V_93 ;
V_7 -> V_92 = 0 ;
F_2 ( V_7 -> V_93 ) = 0 ;
}
if ( * V_7 -> V_18 [ V_19 ] != NULL ) {
* V_2 -> V_95 = * V_7 -> V_18 [ V_19 ] ;
V_2 -> V_95 = V_7 -> V_18 [ V_85 ] ;
* V_7 -> V_18 [ V_19 ] = NULL ;
}
if ( V_7 -> V_17 != NULL ) {
* V_2 -> V_96 = V_7 -> V_17 ;
V_2 -> V_96 = V_7 -> V_18 [ V_19 ] ;
}
F_89 ( V_7 ) ;
}
static void F_101 ( struct V_1 * V_2 )
{
int V_81 ;
struct V_6 * V_7 = F_102 ( V_2 -> V_97 ) ;
if ( V_2 -> V_98 &&
V_2 -> V_98 != V_29 )
return;
V_7 -> V_92 += V_2 -> V_92 ;
V_7 -> V_93 += V_2 -> V_93 ;
V_7 -> V_99 += V_2 -> V_93 ;
if ( V_2 -> V_92 != V_2 -> V_93 )
F_103 () ;
V_2 -> V_92 = 0 ;
V_2 -> V_93 = 0 ;
if ( V_2 -> V_100 != NULL ) {
* V_2 -> V_96 = * V_7 -> V_18 [ V_19 ] ;
* V_7 -> V_18 [ V_19 ] = V_2 -> V_100 ;
for ( V_81 = V_82 - 1 ; V_81 >= V_19 ; V_81 -- )
if ( V_7 -> V_18 [ V_81 ] == V_7 -> V_18 [ V_19 ] )
V_7 -> V_18 [ V_81 ] = V_2 -> V_96 ;
V_2 -> V_100 = NULL ;
V_2 -> V_96 = & V_2 -> V_100 ;
}
if ( V_2 -> V_101 != NULL ) {
* V_7 -> V_18 [ V_85 ] = V_2 -> V_101 ;
V_7 -> V_18 [ V_85 ] = V_2 -> V_95 ;
V_2 -> V_101 = NULL ;
V_2 -> V_95 = & V_2 -> V_101 ;
}
}
static void F_104 ( struct V_1 * V_2 )
{
F_105 (unsigned long mask) ;
F_105 ( struct V_6 * V_7 = F_106 ( V_2 -> V_97 ) ) ;
F_105 ( struct V_20 * V_46 = V_7 -> V_47 ) ;
F_105 ( V_86 = V_7 -> V_48 ) ;
F_6 ( V_2 -> V_24 ,
V_46 -> V_4 + 1 - ! ! ( V_46 -> V_65 & V_86 ) ,
L_25 ) ;
}
static void F_107 ( int V_5 , struct V_1 * V_2 )
{
unsigned long V_39 ;
unsigned long V_86 ;
int V_102 = 0 ;
struct V_6 * V_7 = F_108 ( V_2 -> V_97 , V_5 ) ;
struct V_20 * V_46 = V_7 -> V_47 ;
F_109 ( V_5 ) ;
F_110 ( V_46 , - 1 ) ;
F_64 ( & V_2 -> V_103 , V_39 ) ;
F_100 ( V_5 , V_2 , V_46 , V_7 ) ;
F_101 ( V_2 ) ;
V_86 = V_7 -> V_48 ;
do {
F_111 ( & V_46 -> V_62 ) ;
V_46 -> V_49 &= ~ V_86 ;
if ( V_46 -> V_49 != 0 ) {
if ( V_46 != V_7 -> V_47 )
F_112 ( & V_46 -> V_62 ) ;
break;
}
if ( V_46 == V_7 -> V_47 )
V_102 = F_113 ( V_2 , V_46 , V_7 ) ;
else
F_112 ( & V_46 -> V_62 ) ;
V_86 = V_46 -> V_48 ;
V_46 = V_46 -> V_90 ;
} while ( V_46 != NULL );
F_112 ( & V_2 -> V_103 ) ;
V_46 = V_7 -> V_47 ;
if ( V_102 & V_104 )
F_114 ( V_46 , V_39 ) ;
else
F_65 ( & V_46 -> V_62 , V_39 ) ;
if ( V_102 & V_105 )
F_115 ( V_2 , V_46 , true ) ;
F_31 ( V_7 -> V_93 != 0 || V_7 -> V_17 != NULL ,
L_26 ,
V_5 , V_7 -> V_93 , V_7 -> V_17 ) ;
}
static void F_101 ( struct V_1 * V_2 )
{
}
static void F_104 ( struct V_1 * V_2 )
{
}
static void F_107 ( int V_5 , struct V_1 * V_2 )
{
}
static void F_116 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
unsigned long V_39 ;
struct V_106 * V_107 , * V_108 , * * V_109 ;
int V_110 , V_111 , V_112 , V_81 ;
if ( ! F_18 ( V_7 ) ) {
F_117 ( V_2 -> V_24 , V_7 -> V_92 , V_7 -> V_93 , 0 ) ;
F_118 ( V_2 -> V_24 , 0 , ! ! F_2 ( V_7 -> V_17 ) ,
F_119 () , F_27 ( V_29 ) ,
F_120 () ) ;
return;
}
F_41 ( V_39 ) ;
F_36 ( F_22 ( F_29 () ) ) ;
V_110 = V_7 -> V_113 ;
F_117 ( V_2 -> V_24 , V_7 -> V_92 , V_7 -> V_93 , V_110 ) ;
V_108 = V_7 -> V_17 ;
V_7 -> V_17 = * V_7 -> V_18 [ V_19 ] ;
* V_7 -> V_18 [ V_19 ] = NULL ;
V_109 = V_7 -> V_18 [ V_19 ] ;
for ( V_81 = V_82 - 1 ; V_81 >= 0 ; V_81 -- )
if ( V_7 -> V_18 [ V_81 ] == V_7 -> V_18 [ V_19 ] )
V_7 -> V_18 [ V_81 ] = & V_7 -> V_17 ;
F_43 ( V_39 ) ;
V_111 = V_112 = 0 ;
while ( V_108 ) {
V_107 = V_108 -> V_107 ;
F_121 ( V_107 ) ;
F_122 ( V_108 ) ;
if ( F_123 ( V_2 -> V_24 , V_108 ) )
V_112 ++ ;
V_108 = V_107 ;
if ( ++ V_111 >= V_110 &&
( F_119 () ||
( ! F_27 ( V_29 ) && ! F_120 () ) ) )
break;
}
F_41 ( V_39 ) ;
F_118 ( V_2 -> V_24 , V_111 , ! ! V_108 , F_119 () ,
F_27 ( V_29 ) ,
F_120 () ) ;
if ( V_108 != NULL ) {
* V_109 = V_7 -> V_17 ;
V_7 -> V_17 = V_108 ;
for ( V_81 = 0 ; V_81 < V_82 ; V_81 ++ )
if ( & V_7 -> V_17 == V_7 -> V_18 [ V_81 ] )
V_7 -> V_18 [ V_81 ] = V_109 ;
else
break;
}
F_124 () ;
V_7 -> V_92 -= V_112 ;
F_2 ( V_7 -> V_93 ) -= V_111 ;
V_7 -> V_114 += V_111 ;
if ( V_7 -> V_113 == V_115 && V_7 -> V_93 <= V_116 )
V_7 -> V_113 = V_113 ;
if ( V_7 -> V_93 == 0 && V_7 -> V_117 != 0 ) {
V_7 -> V_117 = 0 ;
V_7 -> V_118 = V_2 -> V_119 ;
} else if ( V_7 -> V_93 < V_7 -> V_117 - V_120 )
V_7 -> V_117 = V_7 -> V_93 ;
F_36 ( ( V_7 -> V_17 == NULL ) != ( V_7 -> V_93 == 0 ) ) ;
F_43 ( V_39 ) ;
if ( F_18 ( V_7 ) )
F_125 () ;
}
void F_126 ( int V_5 , int V_121 )
{
F_9 ( L_27 ) ;
F_127 () ;
if ( V_121 || F_56 () ) {
F_3 ( V_5 ) ;
F_7 ( V_5 ) ;
} else if ( ! F_128 () ) {
F_7 ( V_5 ) ;
}
F_129 ( V_5 ) ;
if ( F_130 ( V_5 ) )
F_125 () ;
F_9 ( L_28 ) ;
}
static void F_131 ( struct V_1 * V_2 , int (* F_132)( struct V_6 * ) )
{
unsigned long V_122 ;
int V_5 ;
unsigned long V_39 ;
unsigned long V_86 ;
struct V_20 * V_46 ;
F_68 (rsp, rnp) {
V_86 = 0 ;
F_64 ( & V_46 -> V_62 , V_39 ) ;
if ( ! F_1 ( V_2 ) ) {
F_65 ( & V_46 -> V_62 , V_39 ) ;
return;
}
if ( V_46 -> V_65 == 0 ) {
F_133 ( V_46 , V_39 ) ;
continue;
}
V_5 = V_46 -> V_67 ;
V_122 = 1 ;
for (; V_5 <= V_46 -> V_66 ; V_5 ++ , V_122 <<= 1 ) {
if ( ( V_46 -> V_65 & V_122 ) != 0 &&
F_132 ( F_108 ( V_2 -> V_97 , V_5 ) ) )
V_86 |= V_122 ;
}
if ( V_86 != 0 ) {
F_95 ( V_86 , V_2 , V_46 , V_39 ) ;
continue;
}
F_65 ( & V_46 -> V_62 , V_39 ) ;
}
V_46 = F_20 ( V_2 ) ;
if ( V_46 -> V_65 == 0 ) {
F_64 ( & V_46 -> V_62 , V_39 ) ;
F_133 ( V_46 , V_39 ) ;
}
}
static void F_14 ( struct V_1 * V_2 , int V_123 )
{
unsigned long V_39 ;
struct V_20 * V_46 = F_20 ( V_2 ) ;
F_9 ( L_29 ) ;
if ( ! F_1 ( V_2 ) ) {
F_9 ( L_30 ) ;
return;
}
if ( ! F_134 ( & V_2 -> V_124 , V_39 ) ) {
V_2 -> V_125 ++ ;
F_9 ( L_30 ) ;
return;
}
if ( V_123 && F_76 ( V_2 -> V_126 , V_23 ) )
goto V_127;
V_2 -> V_119 ++ ;
F_111 ( & V_46 -> V_62 ) ;
V_2 -> V_126 = V_23 + V_128 ;
if( ! F_1 ( V_2 ) ) {
V_2 -> V_129 ++ ;
F_112 ( & V_46 -> V_62 ) ;
goto V_127;
}
V_2 -> V_130 = 1 ;
switch ( V_2 -> V_131 ) {
case V_132 :
case V_133 :
break;
case V_134 :
F_112 ( & V_46 -> V_62 ) ;
F_131 ( V_2 , F_57 ) ;
F_111 ( & V_46 -> V_62 ) ;
if ( F_1 ( V_2 ) )
V_2 -> V_131 = V_135 ;
break;
case V_135 :
F_112 ( & V_46 -> V_62 ) ;
F_131 ( V_2 , F_59 ) ;
F_111 ( & V_46 -> V_62 ) ;
break;
}
V_2 -> V_130 = 0 ;
if ( V_2 -> V_136 ) {
F_112 ( & V_2 -> V_124 ) ;
V_2 -> V_136 = 0 ;
F_93 ( V_2 , V_39 ) ;
F_9 ( L_30 ) ;
return;
}
F_112 ( & V_46 -> V_62 ) ;
V_127:
F_65 ( & V_2 -> V_124 , V_39 ) ;
F_9 ( L_30 ) ;
}
static void
F_135 ( struct V_1 * V_2 )
{
unsigned long V_39 ;
struct V_6 * V_7 = F_102 ( V_2 -> V_97 ) ;
F_36 ( V_7 -> V_137 == 0 ) ;
if ( F_23 ( F_2 ( V_2 -> V_126 ) , V_23 ) )
F_14 ( V_2 , 1 ) ;
F_91 ( V_2 , V_7 ) ;
F_99 ( V_2 , V_7 ) ;
if ( F_19 ( V_2 , V_7 ) ) {
F_64 ( & F_20 ( V_2 ) -> V_62 , V_39 ) ;
F_93 ( V_2 , V_39 ) ;
}
if ( F_18 ( V_7 ) )
F_136 ( V_2 , V_7 ) ;
}
static void F_137 ( struct V_138 * V_139 )
{
struct V_1 * V_2 ;
F_9 ( L_31 ) ;
F_81 (rsp)
F_135 ( V_2 ) ;
F_9 ( L_32 ) ;
}
static void F_136 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
if ( F_138 ( ! F_2 ( V_50 ) ) )
return;
if ( F_139 ( ! V_2 -> V_140 ) ) {
F_116 ( V_2 , V_7 ) ;
return;
}
F_140 () ;
}
static void F_125 ( void )
{
F_141 ( V_141 ) ;
}
static void F_142 ( struct V_1 * V_2 , struct V_6 * V_7 ,
struct V_106 * V_142 , unsigned long V_39 )
{
if ( F_51 () && F_143 ( F_29 () ) )
F_125 () ;
if ( F_144 ( V_39 ) || F_22 ( F_29 () ) )
return;
if ( F_138 ( V_7 -> V_93 > V_7 -> V_117 + V_120 ) ) {
F_91 ( V_2 , V_7 ) ;
F_88 ( V_2 , V_7 ) ;
if ( ! F_1 ( V_2 ) ) {
unsigned long V_143 ;
struct V_20 * V_144 = F_20 ( V_2 ) ;
F_64 ( & V_144 -> V_62 , V_143 ) ;
F_93 ( V_2 , V_143 ) ;
} else {
V_7 -> V_113 = V_115 ;
if ( V_2 -> V_119 == V_7 -> V_118 &&
* V_7 -> V_18 [ V_19 ] != V_142 )
F_14 ( V_2 , 0 ) ;
V_7 -> V_118 = V_2 -> V_119 ;
V_7 -> V_117 = V_7 -> V_93 ;
}
} else if ( F_23 ( F_2 ( V_2 -> V_126 ) , V_23 ) )
F_14 ( V_2 , 1 ) ;
}
static void
F_145 ( struct V_106 * V_142 , void (* F_146)( struct V_106 * V_145 ) ,
struct V_1 * V_2 , bool V_146 )
{
unsigned long V_39 ;
struct V_6 * V_7 ;
F_36 ( ( unsigned long ) V_142 & 0x3 ) ;
F_147 ( V_142 ) ;
V_142 -> F_146 = F_146 ;
V_142 -> V_107 = NULL ;
F_124 () ;
F_41 ( V_39 ) ;
V_7 = F_106 ( V_2 -> V_97 ) ;
F_2 ( V_7 -> V_93 ) ++ ;
if ( V_146 )
V_7 -> V_92 ++ ;
else
F_103 () ;
F_124 () ;
* V_7 -> V_18 [ V_85 ] = V_142 ;
V_7 -> V_18 [ V_85 ] = & V_142 -> V_107 ;
if ( F_148 ( ( unsigned long ) F_146 ) )
F_149 ( V_2 -> V_24 , V_142 , ( unsigned long ) F_146 ,
V_7 -> V_92 , V_7 -> V_93 ) ;
else
F_150 ( V_2 -> V_24 , V_142 , V_7 -> V_92 , V_7 -> V_93 ) ;
F_142 ( V_2 , V_7 , V_142 , V_39 ) ;
F_43 ( V_39 ) ;
}
void F_151 ( struct V_106 * V_142 , void (* F_146)( struct V_106 * V_145 ) )
{
F_145 ( V_142 , F_146 , & V_12 , 0 ) ;
}
void F_152 ( struct V_106 * V_142 , void (* F_146)( struct V_106 * V_145 ) )
{
F_145 ( V_142 , F_146 , & V_13 , 0 ) ;
}
static inline int F_153 ( void )
{
int V_45 ;
F_154 () ;
F_52 () ;
V_45 = F_155 () <= 1 ;
F_53 () ;
return V_45 ;
}
void F_156 ( void )
{
F_38 ( ! F_39 ( & V_37 ) &&
! F_39 ( & V_36 ) &&
! F_39 ( & V_38 ) ,
L_33 ) ;
if ( F_153 () )
return;
F_157 ( F_151 ) ;
}
void F_158 ( void )
{
F_38 ( ! F_39 ( & V_37 ) &&
! F_39 ( & V_36 ) &&
! F_39 ( & V_38 ) ,
L_34 ) ;
if ( F_153 () )
return;
F_157 ( F_152 ) ;
}
static int F_159 ( void * V_147 )
{
F_124 () ;
return 0 ;
}
void F_160 ( void )
{
int V_148 , V_149 , V_53 , V_150 = 0 ;
V_148 = V_53 = F_161 ( & V_151 ) ;
F_162 () ;
F_36 ( F_22 ( F_163 () ) ) ;
while ( F_164 ( V_152 ,
F_159 ,
NULL ) == - V_153 ) {
F_165 () ;
if ( V_150 ++ < 10 ) {
F_166 ( V_150 * F_155 () ) ;
} else {
F_156 () ;
return;
}
V_149 = F_37 ( & V_154 ) ;
if ( F_60 ( ( unsigned ) V_149 , ( unsigned ) V_148 ) ) {
F_124 () ;
return;
}
F_162 () ;
V_53 = F_37 ( & V_151 ) ;
F_124 () ;
}
do {
V_149 = F_37 ( & V_154 ) ;
if ( F_60 ( ( unsigned ) V_149 , ( unsigned ) V_53 ) ) {
F_124 () ;
break;
}
} while ( F_167 ( & V_154 , V_149 , V_53 ) != V_149 );
F_165 () ;
}
static int F_168 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
struct V_20 * V_46 = V_7 -> V_47 ;
V_7 -> V_155 ++ ;
F_78 ( V_2 , V_7 ) ;
if ( V_50 &&
V_7 -> V_80 && ! V_7 -> V_10 ) {
V_7 -> V_156 ++ ;
if ( ! V_7 -> V_157 &&
F_23 ( F_2 ( V_2 -> V_126 ) - 1 ,
V_23 ) )
F_77 () ;
} else if ( V_7 -> V_80 && V_7 -> V_10 ) {
V_7 -> V_158 ++ ;
return 1 ;
}
if ( F_18 ( V_7 ) ) {
V_7 -> V_159 ++ ;
return 1 ;
}
if ( F_19 ( V_2 , V_7 ) ) {
V_7 -> V_160 ++ ;
return 1 ;
}
if ( F_2 ( V_46 -> V_3 ) != V_7 -> V_3 ) {
V_7 -> V_161 ++ ;
return 1 ;
}
if ( F_2 ( V_46 -> V_4 ) != V_7 -> V_4 ) {
V_7 -> V_162 ++ ;
return 1 ;
}
if ( F_1 ( V_2 ) &&
F_23 ( F_2 ( V_2 -> V_126 ) , V_23 ) ) {
V_7 -> V_163 ++ ;
return 1 ;
}
V_7 -> V_164 ++ ;
return 0 ;
}
static int F_130 ( int V_5 )
{
struct V_1 * V_2 ;
F_81 (rsp)
if ( F_168 ( V_2 , F_108 ( V_2 -> V_97 , V_5 ) ) )
return 1 ;
return 0 ;
}
static int F_169 ( int V_5 )
{
struct V_1 * V_2 ;
F_81 (rsp)
if ( F_108 ( V_2 -> V_97 , V_5 ) -> V_17 )
return 1 ;
return 0 ;
}
static void F_170 ( struct V_1 * V_2 , char * V_149 ,
int V_5 , unsigned long V_165 )
{
F_171 ( V_2 -> V_24 , V_149 , V_5 ,
F_37 ( & V_2 -> V_166 ) , V_165 ) ;
}
static void F_172 ( struct V_106 * V_167 )
{
struct V_6 * V_7 = F_173 ( V_167 , struct V_6 , V_168 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
if ( F_174 ( & V_2 -> V_166 ) ) {
F_170 ( V_2 , L_35 , - 1 , V_2 -> V_169 ) ;
F_175 ( & V_2 -> V_170 ) ;
} else {
F_170 ( V_2 , L_36 , - 1 , V_2 -> V_169 ) ;
}
}
static void F_176 ( void * type )
{
struct V_1 * V_2 = type ;
struct V_6 * V_7 = F_102 ( V_2 -> V_97 ) ;
F_170 ( V_2 , L_37 , - 1 , V_2 -> V_169 ) ;
F_34 ( & V_2 -> V_166 ) ;
V_2 -> V_171 ( & V_7 -> V_168 , F_172 ) ;
}
static void F_177 ( struct V_1 * V_2 )
{
int V_5 ;
unsigned long V_39 ;
struct V_6 * V_7 ;
struct V_6 V_172 ;
unsigned long V_53 = F_2 ( V_2 -> V_169 ) ;
unsigned long V_173 ;
F_178 ( & V_172 . V_168 ) ;
F_170 ( V_2 , L_38 , - 1 , V_53 ) ;
F_179 ( & V_2 -> V_174 ) ;
F_124 () ;
V_173 = F_2 ( V_2 -> V_169 ) ;
F_170 ( V_2 , L_39 , - 1 , V_173 ) ;
if ( F_76 ( V_173 , ( ( V_53 + 1 ) & ~ 0x1 ) + 2 ) ) {
F_170 ( V_2 , L_40 , - 1 , V_173 ) ;
F_124 () ;
F_180 ( & V_2 -> V_174 ) ;
return;
}
F_2 ( V_2 -> V_169 ) ++ ;
F_36 ( ( V_2 -> V_169 & 0x1 ) != 1 ) ;
F_170 ( V_2 , L_41 , - 1 , V_2 -> V_169 ) ;
F_124 () ;
F_181 ( & V_2 -> V_170 ) ;
F_182 ( & V_2 -> V_166 , 1 ) ;
F_64 ( & V_2 -> V_103 , V_39 ) ;
V_2 -> V_98 = V_29 ;
F_65 ( & V_2 -> V_103 , V_39 ) ;
F_183 (cpu) {
F_52 () ;
V_7 = F_108 ( V_2 -> V_97 , V_5 ) ;
if ( F_22 ( V_5 ) ) {
F_170 ( V_2 , L_42 , V_5 ,
V_2 -> V_169 ) ;
F_53 () ;
while ( F_22 ( V_5 ) && F_2 ( V_7 -> V_93 ) )
F_184 ( 1 ) ;
} else if ( F_2 ( V_7 -> V_93 ) ) {
F_170 ( V_2 , L_43 , V_5 ,
V_2 -> V_169 ) ;
F_185 ( V_5 , F_176 , V_2 , 1 ) ;
F_53 () ;
} else {
F_170 ( V_2 , L_44 , V_5 ,
V_2 -> V_169 ) ;
F_53 () ;
}
}
F_64 ( & V_2 -> V_103 , V_39 ) ;
F_101 ( V_2 ) ;
V_2 -> V_98 = NULL ;
F_65 ( & V_2 -> V_103 , V_39 ) ;
F_34 ( & V_2 -> V_166 ) ;
F_35 () ;
V_172 . V_2 = V_2 ;
V_2 -> V_171 ( & V_172 . V_168 , F_172 ) ;
if ( F_174 ( & V_2 -> V_166 ) )
F_175 ( & V_2 -> V_170 ) ;
F_124 () ;
F_2 ( V_2 -> V_169 ) ++ ;
F_36 ( ( V_2 -> V_169 & 0x1 ) != 0 ) ;
F_170 ( V_2 , L_45 , - 1 , V_2 -> V_169 ) ;
F_124 () ;
F_186 ( & V_2 -> V_170 ) ;
F_180 ( & V_2 -> V_174 ) ;
F_187 ( & V_172 . V_168 ) ;
}
void F_188 ( void )
{
F_177 ( & V_13 ) ;
}
void F_189 ( void )
{
F_177 ( & V_12 ) ;
}
static void T_1
F_190 ( int V_5 , struct V_1 * V_2 )
{
unsigned long V_39 ;
struct V_6 * V_7 = F_108 ( V_2 -> V_97 , V_5 ) ;
struct V_20 * V_46 = F_20 ( V_2 ) ;
F_64 ( & V_46 -> V_62 , V_39 ) ;
V_7 -> V_48 = 1UL << ( V_5 - V_7 -> V_47 -> V_67 ) ;
F_89 ( V_7 ) ;
V_7 -> V_92 = 0 ;
F_2 ( V_7 -> V_93 ) = 0 ;
V_7 -> V_35 = & F_4 ( V_26 , V_5 ) ;
F_36 ( V_7 -> V_35 -> V_40 != V_43 ) ;
F_36 ( F_37 ( & V_7 -> V_35 -> V_35 ) != 1 ) ;
V_7 -> V_5 = V_5 ;
V_7 -> V_2 = V_2 ;
F_65 ( & V_46 -> V_62 , V_39 ) ;
}
static void T_2
F_191 ( int V_5 , struct V_1 * V_2 , int V_157 )
{
unsigned long V_39 ;
unsigned long V_86 ;
struct V_6 * V_7 = F_108 ( V_2 -> V_97 , V_5 ) ;
struct V_20 * V_46 = F_20 ( V_2 ) ;
F_64 ( & V_46 -> V_62 , V_39 ) ;
V_7 -> V_137 = 1 ;
V_7 -> V_157 = V_157 ;
V_7 -> V_117 = 0 ;
V_7 -> V_118 = V_2 -> V_119 ;
V_7 -> V_113 = V_113 ;
V_7 -> V_35 -> V_40 = V_43 ;
F_182 ( & V_7 -> V_35 -> V_35 ,
( F_37 ( & V_7 -> V_35 -> V_35 ) & ~ 0x1 ) + 1 ) ;
F_192 ( V_5 ) ;
F_112 ( & V_46 -> V_62 ) ;
F_111 ( & V_2 -> V_103 ) ;
V_46 = V_7 -> V_47 ;
V_86 = V_7 -> V_48 ;
do {
F_111 ( & V_46 -> V_62 ) ;
V_46 -> V_49 |= V_86 ;
V_86 = V_46 -> V_48 ;
if ( V_46 == V_7 -> V_47 ) {
V_7 -> V_4 = V_46 -> V_3 ;
V_7 -> V_3 = V_46 -> V_3 ;
V_7 -> V_10 = 0 ;
V_7 -> V_80 = 0 ;
V_7 -> V_9 = V_46 -> V_4 - 1 ;
F_6 ( V_2 -> V_24 , V_7 -> V_4 , L_46 ) ;
}
F_112 ( & V_46 -> V_62 ) ;
V_46 = V_46 -> V_90 ;
} while ( V_46 != NULL && ! ( V_46 -> V_49 & V_86 ) );
F_65 ( & V_2 -> V_103 , V_39 ) ;
}
static void T_2 F_193 ( int V_5 )
{
struct V_1 * V_2 ;
F_81 (rsp)
F_191 ( V_5 , V_2 ,
strcmp ( V_2 -> V_24 , L_47 ) == 0 ) ;
}
static int T_2 F_194 ( struct V_72 * V_175 ,
unsigned long V_176 , void * V_177 )
{
long V_5 = ( long ) V_177 ;
struct V_6 * V_7 = F_108 ( V_1 -> V_97 , V_5 ) ;
struct V_20 * V_46 = V_7 -> V_47 ;
struct V_1 * V_2 ;
F_9 ( L_48 ) ;
switch ( V_176 ) {
case V_178 :
case V_179 :
F_193 ( V_5 ) ;
F_195 ( V_5 ) ;
break;
case V_180 :
case V_181 :
F_110 ( V_46 , - 1 ) ;
F_196 ( V_5 , 1 ) ;
break;
case V_182 :
F_110 ( V_46 , V_5 ) ;
F_196 ( V_5 , 0 ) ;
break;
case V_183 :
case V_184 :
F_81 (rsp)
F_104 ( V_2 ) ;
F_46 ( V_5 ) ;
break;
case V_185 :
case V_186 :
case V_187 :
case V_188 :
F_81 (rsp)
F_107 ( V_5 , V_2 ) ;
break;
default:
break;
}
F_9 ( L_49 ) ;
return V_189 ;
}
void F_197 ( void )
{
F_198 ( F_155 () != 1 ) ;
F_198 ( F_199 () > 0 ) ;
V_190 = 1 ;
}
static void T_1 F_200 ( struct V_1 * V_2 )
{
int V_81 ;
for ( V_81 = V_191 - 1 ; V_81 > 0 ; V_81 -- )
V_2 -> V_192 [ V_81 ] = V_193 ;
V_2 -> V_192 [ 0 ] = V_194 ;
}
static void T_1 F_200 ( struct V_1 * V_2 )
{
int V_195 ;
int V_196 ;
int V_81 ;
V_196 = V_197 ;
for ( V_81 = V_191 - 1 ; V_81 >= 0 ; V_81 -- ) {
V_195 = V_2 -> V_198 [ V_81 ] ;
V_2 -> V_192 [ V_81 ] = ( V_196 + V_195 - 1 ) / V_195 ;
V_196 = V_195 ;
}
}
static void T_1 F_201 ( struct V_1 * V_2 ,
struct V_6 T_3 * V_97 )
{
static char * V_199 [] = { L_50 ,
L_51 ,
L_52 ,
L_53 } ;
int V_200 = 1 ;
int V_81 ;
int V_69 ;
struct V_20 * V_46 ;
F_202 ( V_201 > F_203 ( V_199 ) ) ;
for ( V_81 = 0 ; V_81 < V_191 ; V_81 ++ )
V_2 -> V_198 [ V_81 ] = V_202 [ V_81 ] ;
for ( V_81 = 1 ; V_81 < V_191 ; V_81 ++ )
V_2 -> V_88 [ V_81 ] = V_2 -> V_88 [ V_81 - 1 ] + V_2 -> V_198 [ V_81 - 1 ] ;
F_200 ( V_2 ) ;
for ( V_81 = V_191 - 1 ; V_81 >= 0 ; V_81 -- ) {
V_200 *= V_2 -> V_192 [ V_81 ] ;
V_46 = V_2 -> V_88 [ V_81 ] ;
for ( V_69 = 0 ; V_69 < V_2 -> V_198 [ V_81 ] ; V_69 ++ , V_46 ++ ) {
F_204 ( & V_46 -> V_62 ) ;
F_205 ( & V_46 -> V_62 ,
& V_203 [ V_81 ] , V_199 [ V_81 ] ) ;
V_46 -> V_4 = 0 ;
V_46 -> V_65 = 0 ;
V_46 -> V_49 = 0 ;
V_46 -> V_67 = V_69 * V_200 ;
V_46 -> V_66 = ( V_69 + 1 ) * V_200 - 1 ;
if ( V_46 -> V_66 >= V_197 )
V_46 -> V_66 = V_197 - 1 ;
if ( V_81 == 0 ) {
V_46 -> V_204 = 0 ;
V_46 -> V_48 = 0 ;
V_46 -> V_90 = NULL ;
} else {
V_46 -> V_204 = V_69 % V_2 -> V_192 [ V_81 - 1 ] ;
V_46 -> V_48 = 1UL << V_46 -> V_204 ;
V_46 -> V_90 = V_2 -> V_88 [ V_81 - 1 ] +
V_69 / V_2 -> V_192 [ V_81 - 1 ] ;
}
V_46 -> V_88 = V_81 ;
F_206 ( & V_46 -> V_205 ) ;
}
}
V_2 -> V_97 = V_97 ;
V_46 = V_2 -> V_88 [ V_191 - 1 ] ;
F_183 (i) {
while ( V_81 > V_46 -> V_66 )
V_46 ++ ;
F_108 ( V_2 -> V_97 , V_81 ) -> V_47 = V_46 ;
F_190 ( V_81 , V_2 ) ;
}
F_207 ( & V_2 -> V_206 , & V_207 ) ;
}
static void T_1 F_208 ( void )
{
int V_81 ;
int V_69 ;
int V_208 = V_209 ;
int V_210 [ V_201 + 1 ] ;
if ( V_194 == V_211 )
return;
V_210 [ 0 ] = 1 ;
V_210 [ 1 ] = V_194 ;
for ( V_81 = 2 ; V_81 <= V_201 ; V_81 ++ )
V_210 [ V_81 ] = V_210 [ V_81 - 1 ] * V_193 ;
if ( V_194 < V_211 ||
V_194 > sizeof( unsigned long ) * 8 ||
V_208 > V_210 [ V_201 ] ) {
F_198 ( 1 ) ;
return;
}
for ( V_81 = 1 ; V_81 <= V_201 ; V_81 ++ )
if ( V_208 <= V_210 [ V_81 ] ) {
for ( V_69 = 0 ; V_69 <= V_81 ; V_69 ++ )
V_202 [ V_69 ] =
F_209 ( V_208 , V_210 [ V_81 - V_69 ] ) ;
V_191 = V_81 ;
for ( V_69 = V_81 + 1 ; V_69 <= V_201 ; V_69 ++ )
V_202 [ V_69 ] = 0 ;
break;
}
V_212 = 0 ;
for ( V_81 = 0 ; V_81 <= V_201 ; V_81 ++ )
V_212 += V_202 [ V_81 ] ;
V_212 -= V_208 ;
}
void T_1 F_210 ( void )
{
int V_5 ;
F_211 () ;
F_208 () ;
F_201 ( & V_12 , & V_8 ) ;
F_201 ( & V_13 , & V_11 ) ;
F_212 () ;
F_213 ( V_141 , F_137 ) ;
F_214 ( F_194 , 0 ) ;
F_215 (cpu)
F_194 ( NULL , V_178 , ( void * ) ( long ) V_5 ) ;
F_82 () ;
}
