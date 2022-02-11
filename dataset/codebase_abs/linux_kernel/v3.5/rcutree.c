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
int V_61 ;
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
V_61 = F_69 ( V_46 ) ;
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
V_12 . V_59 = V_23 + V_77 / 2 ;
V_13 . V_59 = V_23 + V_77 / 2 ;
F_81 () ;
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
} else
V_7 -> V_80 = 0 ;
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
static void
F_89 ( struct V_1 * V_2 , struct V_20 * V_46 , struct V_6 * V_7 )
{
if ( V_7 -> V_3 != V_46 -> V_3 ) {
V_7 -> V_18 [ V_19 ] = V_7 -> V_18 [ V_81 ] ;
V_7 -> V_18 [ V_81 ] = V_7 -> V_18 [ V_82 ] ;
V_7 -> V_18 [ V_82 ] = V_7 -> V_18 [ V_83 ] ;
V_7 -> V_3 = V_46 -> V_3 ;
F_6 ( V_2 -> V_24 , V_7 -> V_4 , L_24 ) ;
if ( F_23 ( V_7 -> V_4 , V_7 -> V_3 ) )
V_7 -> V_4 = V_7 -> V_3 ;
if ( ( V_46 -> V_65 & V_7 -> V_48 ) == 0 )
V_7 -> V_80 = 0 ;
}
}
static void
F_90 ( struct V_1 * V_2 , struct V_6 * V_7 )
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
F_89 ( V_2 , V_46 , V_7 ) ;
F_65 ( & V_46 -> V_62 , V_39 ) ;
}
static void
F_91 ( struct V_1 * V_2 , struct V_20 * V_46 , struct V_6 * V_7 )
{
F_89 ( V_2 , V_46 , V_7 ) ;
V_7 -> V_18 [ V_82 ] = V_7 -> V_18 [ V_83 ] ;
V_7 -> V_18 [ V_81 ] = V_7 -> V_18 [ V_83 ] ;
F_84 ( V_2 , V_46 , V_7 ) ;
}
static void
F_92 ( struct V_1 * V_2 , unsigned long V_39 )
__releases( rcu_get_root( V_2 )->lock
static void F_93 ( struct V_1 * V_2 , unsigned long V_39 )
__releases( rcu_get_root( V_2 )->lock
static void
F_94 ( unsigned long V_84 , struct V_1 * V_2 ,
struct V_20 * V_46 , unsigned long V_39 )
__releases( V_46 -> V_62 )
{
struct V_20 * V_85 ;
for (; ; ) {
if ( ! ( V_46 -> V_65 & V_84 ) ) {
F_65 ( & V_46 -> V_62 , V_39 ) ;
return;
}
V_46 -> V_65 &= ~ V_84 ;
F_95 ( V_2 -> V_24 , V_46 -> V_4 ,
V_84 , V_46 -> V_65 , V_46 -> V_86 ,
V_46 -> V_67 , V_46 -> V_66 ,
! ! V_46 -> V_87 ) ;
if ( V_46 -> V_65 != 0 || F_96 ( V_46 ) ) {
F_65 ( & V_46 -> V_62 , V_39 ) ;
return;
}
V_84 = V_46 -> V_48 ;
if ( V_46 -> V_88 == NULL ) {
break;
}
F_65 ( & V_46 -> V_62 , V_39 ) ;
V_85 = V_46 ;
V_46 = V_46 -> V_88 ;
F_64 ( & V_46 -> V_62 , V_39 ) ;
F_36 ( V_85 -> V_65 ) ;
}
F_93 ( V_2 , V_39 ) ;
}
static void
F_97 ( int V_5 , struct V_1 * V_2 , struct V_6 * V_7 , long V_89 )
{
unsigned long V_39 ;
unsigned long V_84 ;
struct V_20 * V_46 ;
V_46 = V_7 -> V_47 ;
F_64 ( & V_46 -> V_62 , V_39 ) ;
if ( V_89 != V_46 -> V_4 || V_46 -> V_3 == V_46 -> V_4 ) {
V_7 -> V_10 = 0 ;
F_65 ( & V_46 -> V_62 , V_39 ) ;
return;
}
V_84 = V_7 -> V_48 ;
if ( ( V_46 -> V_65 & V_84 ) == 0 ) {
F_65 ( & V_46 -> V_62 , V_39 ) ;
} else {
V_7 -> V_80 = 0 ;
V_7 -> V_18 [ V_82 ] = V_7 -> V_18 [ V_83 ] ;
F_94 ( V_84 , V_2 , V_46 , V_39 ) ;
}
}
static void
F_98 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
if ( F_88 ( V_2 , V_7 ) )
return;
if ( ! V_7 -> V_80 )
return;
if ( ! V_7 -> V_10 )
return;
F_97 ( V_7 -> V_5 , V_2 , V_7 , V_7 -> V_9 ) ;
}
static void
F_99 ( int V_5 , struct V_1 * V_2 ,
struct V_20 * V_46 , struct V_6 * V_7 )
{
int V_90 ;
if ( V_7 -> V_17 != NULL ) {
V_2 -> V_91 += V_7 -> V_91 ;
V_2 -> V_92 += V_7 -> V_92 ;
V_7 -> V_93 += V_7 -> V_92 ;
V_7 -> V_91 = 0 ;
V_7 -> V_92 = 0 ;
}
if ( * V_7 -> V_18 [ V_19 ] != NULL ) {
* V_2 -> V_94 = * V_7 -> V_18 [ V_19 ] ;
V_2 -> V_94 = V_7 -> V_18 [ V_83 ] ;
* V_7 -> V_18 [ V_19 ] = NULL ;
}
if ( V_7 -> V_17 != NULL ) {
* V_2 -> V_95 = V_7 -> V_17 ;
V_2 -> V_95 = V_7 -> V_18 [ V_19 ] ;
}
V_7 -> V_17 = NULL ;
for ( V_90 = 0 ; V_90 < V_96 ; V_90 ++ )
V_7 -> V_18 [ V_90 ] = & V_7 -> V_17 ;
}
static void F_100 ( struct V_1 * V_2 )
{
int V_90 ;
struct V_6 * V_7 = F_101 ( V_2 -> V_97 ) ;
if ( V_2 -> V_98 &&
V_2 -> V_98 != V_29 )
return;
V_7 -> V_91 += V_2 -> V_91 ;
V_7 -> V_92 += V_2 -> V_92 ;
V_7 -> V_99 += V_2 -> V_92 ;
if ( V_2 -> V_91 != V_2 -> V_92 )
F_102 () ;
V_2 -> V_91 = 0 ;
V_2 -> V_92 = 0 ;
if ( V_2 -> V_100 != NULL ) {
* V_2 -> V_95 = * V_7 -> V_18 [ V_19 ] ;
* V_7 -> V_18 [ V_19 ] = V_2 -> V_100 ;
for ( V_90 = V_96 - 1 ; V_90 >= V_19 ; V_90 -- )
if ( V_7 -> V_18 [ V_90 ] == V_7 -> V_18 [ V_19 ] )
V_7 -> V_18 [ V_90 ] = V_2 -> V_95 ;
V_2 -> V_100 = NULL ;
V_2 -> V_95 = & V_2 -> V_100 ;
}
if ( V_2 -> V_101 != NULL ) {
* V_7 -> V_18 [ V_83 ] = V_2 -> V_101 ;
V_7 -> V_18 [ V_83 ] = V_2 -> V_94 ;
V_2 -> V_101 = NULL ;
V_2 -> V_94 = & V_2 -> V_101 ;
}
}
static void F_103 ( struct V_1 * V_2 )
{
F_104 (unsigned long mask) ;
F_104 ( struct V_6 * V_7 = F_105 ( V_2 -> V_97 ) ) ;
F_104 ( struct V_20 * V_46 = V_7 -> V_47 ) ;
F_104 ( V_84 = V_7 -> V_48 ) ;
F_6 ( V_2 -> V_24 ,
V_46 -> V_4 + 1 - ! ! ( V_46 -> V_65 & V_84 ) ,
L_25 ) ;
}
static void F_106 ( int V_5 , struct V_1 * V_2 )
{
unsigned long V_39 ;
unsigned long V_84 ;
int V_102 = 0 ;
struct V_6 * V_7 = F_107 ( V_2 -> V_97 , V_5 ) ;
struct V_20 * V_46 = V_7 -> V_47 ;
F_108 ( V_5 ) ;
F_109 ( V_46 , - 1 ) ;
F_64 ( & V_2 -> V_103 , V_39 ) ;
F_99 ( V_5 , V_2 , V_46 , V_7 ) ;
F_100 ( V_2 ) ;
V_84 = V_7 -> V_48 ;
do {
F_110 ( & V_46 -> V_62 ) ;
V_46 -> V_49 &= ~ V_84 ;
if ( V_46 -> V_49 != 0 ) {
if ( V_46 != V_7 -> V_47 )
F_111 ( & V_46 -> V_62 ) ;
break;
}
if ( V_46 == V_7 -> V_47 )
V_102 = F_112 ( V_2 , V_46 , V_7 ) ;
else
F_111 ( & V_46 -> V_62 ) ;
V_84 = V_46 -> V_48 ;
V_46 = V_46 -> V_88 ;
} while ( V_46 != NULL );
F_111 ( & V_2 -> V_103 ) ;
V_46 = V_7 -> V_47 ;
if ( V_102 & V_104 )
F_113 ( V_46 , V_39 ) ;
else
F_65 ( & V_46 -> V_62 , V_39 ) ;
if ( V_102 & V_105 )
F_114 ( V_2 , V_46 , true ) ;
}
static void F_100 ( struct V_1 * V_2 )
{
}
static void F_103 ( struct V_1 * V_2 )
{
}
static void F_106 ( int V_5 , struct V_1 * V_2 )
{
}
static void F_115 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
unsigned long V_39 ;
struct V_106 * V_107 , * V_108 , * * V_109 ;
int V_110 , V_111 , V_112 , V_90 ;
if ( ! F_18 ( V_7 ) ) {
F_116 ( V_2 -> V_24 , V_7 -> V_91 , V_7 -> V_92 , 0 ) ;
F_117 ( V_2 -> V_24 , 0 , ! ! F_2 ( V_7 -> V_17 ) ,
F_118 () , F_27 ( V_29 ) ,
F_119 () ) ;
return;
}
F_41 ( V_39 ) ;
F_36 ( F_22 ( F_29 () ) ) ;
V_110 = V_7 -> V_113 ;
F_116 ( V_2 -> V_24 , V_7 -> V_91 , V_7 -> V_92 , V_110 ) ;
V_108 = V_7 -> V_17 ;
V_7 -> V_17 = * V_7 -> V_18 [ V_19 ] ;
* V_7 -> V_18 [ V_19 ] = NULL ;
V_109 = V_7 -> V_18 [ V_19 ] ;
for ( V_90 = V_96 - 1 ; V_90 >= 0 ; V_90 -- )
if ( V_7 -> V_18 [ V_90 ] == V_7 -> V_18 [ V_19 ] )
V_7 -> V_18 [ V_90 ] = & V_7 -> V_17 ;
F_43 ( V_39 ) ;
V_111 = V_112 = 0 ;
while ( V_108 ) {
V_107 = V_108 -> V_107 ;
F_120 ( V_107 ) ;
F_121 ( V_108 ) ;
if ( F_122 ( V_2 -> V_24 , V_108 ) )
V_112 ++ ;
V_108 = V_107 ;
if ( ++ V_111 >= V_110 &&
( F_118 () ||
( ! F_27 ( V_29 ) && ! F_119 () ) ) )
break;
}
F_41 ( V_39 ) ;
F_117 ( V_2 -> V_24 , V_111 , ! ! V_108 , F_118 () ,
F_27 ( V_29 ) ,
F_119 () ) ;
if ( V_108 != NULL ) {
* V_109 = V_7 -> V_17 ;
V_7 -> V_17 = V_108 ;
for ( V_90 = 0 ; V_90 < V_96 ; V_90 ++ )
if ( & V_7 -> V_17 == V_7 -> V_18 [ V_90 ] )
V_7 -> V_18 [ V_90 ] = V_109 ;
else
break;
}
F_123 () ;
V_7 -> V_91 -= V_112 ;
V_7 -> V_92 -= V_111 ;
V_7 -> V_114 += V_111 ;
if ( V_7 -> V_113 == V_115 && V_7 -> V_92 <= V_116 )
V_7 -> V_113 = V_113 ;
if ( V_7 -> V_92 == 0 && V_7 -> V_117 != 0 ) {
V_7 -> V_117 = 0 ;
V_7 -> V_118 = V_2 -> V_119 ;
} else if ( V_7 -> V_92 < V_7 -> V_117 - V_120 )
V_7 -> V_117 = V_7 -> V_92 ;
F_43 ( V_39 ) ;
if ( F_18 ( V_7 ) )
F_124 () ;
}
void F_125 ( int V_5 , int V_121 )
{
F_9 ( L_26 ) ;
F_126 () ;
if ( V_121 || F_56 () ) {
F_3 ( V_5 ) ;
F_7 ( V_5 ) ;
} else if ( ! F_127 () ) {
F_7 ( V_5 ) ;
}
F_128 ( V_5 ) ;
if ( F_129 ( V_5 ) )
F_124 () ;
F_9 ( L_27 ) ;
}
static void F_130 ( struct V_1 * V_2 , int (* F_131)( struct V_6 * ) )
{
unsigned long V_122 ;
int V_5 ;
unsigned long V_39 ;
unsigned long V_84 ;
struct V_20 * V_46 ;
F_68 (rsp, rnp) {
V_84 = 0 ;
F_64 ( & V_46 -> V_62 , V_39 ) ;
if ( ! F_1 ( V_2 ) ) {
F_65 ( & V_46 -> V_62 , V_39 ) ;
return;
}
if ( V_46 -> V_65 == 0 ) {
F_132 ( V_46 , V_39 ) ;
continue;
}
V_5 = V_46 -> V_67 ;
V_122 = 1 ;
for (; V_5 <= V_46 -> V_66 ; V_5 ++ , V_122 <<= 1 ) {
if ( ( V_46 -> V_65 & V_122 ) != 0 &&
F_131 ( F_107 ( V_2 -> V_97 , V_5 ) ) )
V_84 |= V_122 ;
}
if ( V_84 != 0 ) {
F_94 ( V_84 , V_2 , V_46 , V_39 ) ;
continue;
}
F_65 ( & V_46 -> V_62 , V_39 ) ;
}
V_46 = F_20 ( V_2 ) ;
if ( V_46 -> V_65 == 0 ) {
F_64 ( & V_46 -> V_62 , V_39 ) ;
F_132 ( V_46 , V_39 ) ;
}
}
static void F_14 ( struct V_1 * V_2 , int V_123 )
{
unsigned long V_39 ;
struct V_20 * V_46 = F_20 ( V_2 ) ;
F_9 ( L_28 ) ;
if ( ! F_1 ( V_2 ) ) {
F_9 ( L_29 ) ;
return;
}
if ( ! F_133 ( & V_2 -> V_124 , V_39 ) ) {
V_2 -> V_125 ++ ;
F_9 ( L_29 ) ;
return;
}
if ( V_123 && F_76 ( V_2 -> V_126 , V_23 ) )
goto V_127;
V_2 -> V_119 ++ ;
F_110 ( & V_46 -> V_62 ) ;
V_2 -> V_126 = V_23 + V_128 ;
if( ! F_1 ( V_2 ) ) {
V_2 -> V_129 ++ ;
F_111 ( & V_46 -> V_62 ) ;
goto V_127;
}
V_2 -> V_130 = 1 ;
switch ( V_2 -> V_131 ) {
case V_132 :
case V_133 :
break;
case V_134 :
if ( V_135 != V_134 )
break;
F_111 ( & V_46 -> V_62 ) ;
F_130 ( V_2 , F_57 ) ;
F_110 ( & V_46 -> V_62 ) ;
if ( F_1 ( V_2 ) )
V_2 -> V_131 = V_136 ;
break;
case V_136 :
F_111 ( & V_46 -> V_62 ) ;
F_130 ( V_2 , F_59 ) ;
F_110 ( & V_46 -> V_62 ) ;
break;
}
V_2 -> V_130 = 0 ;
if ( V_2 -> V_137 ) {
F_111 ( & V_2 -> V_124 ) ;
V_2 -> V_137 = 0 ;
F_92 ( V_2 , V_39 ) ;
F_9 ( L_29 ) ;
return;
}
F_111 ( & V_46 -> V_62 ) ;
V_127:
F_65 ( & V_2 -> V_124 , V_39 ) ;
F_9 ( L_29 ) ;
}
static void
F_134 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
unsigned long V_39 ;
F_36 ( V_7 -> V_138 == 0 ) ;
if ( F_23 ( F_2 ( V_2 -> V_126 ) , V_23 ) )
F_14 ( V_2 , 1 ) ;
F_90 ( V_2 , V_7 ) ;
F_98 ( V_2 , V_7 ) ;
if ( F_19 ( V_2 , V_7 ) ) {
F_64 ( & F_20 ( V_2 ) -> V_62 , V_39 ) ;
F_92 ( V_2 , V_39 ) ;
}
if ( F_18 ( V_7 ) )
F_135 ( V_2 , V_7 ) ;
}
static void F_136 ( struct V_139 * V_140 )
{
F_9 ( L_30 ) ;
F_134 ( & V_12 ,
& F_42 ( V_8 ) ) ;
F_134 ( & V_13 , & F_42 ( V_11 ) ) ;
F_137 () ;
F_9 ( L_31 ) ;
}
static void F_135 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
if ( F_138 ( ! F_2 ( V_50 ) ) )
return;
if ( F_139 ( ! V_2 -> V_141 ) ) {
F_115 ( V_2 , V_7 ) ;
return;
}
F_140 () ;
}
static void F_124 ( void )
{
F_141 ( V_142 ) ;
}
static void
F_142 ( struct V_106 * V_143 , void (* F_143)( struct V_106 * V_144 ) ,
struct V_1 * V_2 , bool V_145 )
{
unsigned long V_39 ;
struct V_6 * V_7 ;
F_36 ( ( unsigned long ) V_143 & 0x3 ) ;
F_144 ( V_143 ) ;
V_143 -> F_143 = F_143 ;
V_143 -> V_107 = NULL ;
F_123 () ;
F_41 ( V_39 ) ;
V_7 = F_105 ( V_2 -> V_97 ) ;
V_7 -> V_92 ++ ;
if ( V_145 )
V_7 -> V_91 ++ ;
else
F_102 () ;
F_123 () ;
* V_7 -> V_18 [ V_83 ] = V_143 ;
V_7 -> V_18 [ V_83 ] = & V_143 -> V_107 ;
if ( F_145 ( ( unsigned long ) F_143 ) )
F_146 ( V_2 -> V_24 , V_143 , ( unsigned long ) F_143 ,
V_7 -> V_91 , V_7 -> V_92 ) ;
else
F_147 ( V_2 -> V_24 , V_143 , V_7 -> V_91 , V_7 -> V_92 ) ;
if ( F_148 ( V_39 ) ) {
F_43 ( V_39 ) ;
return;
}
if ( F_138 ( V_7 -> V_92 > V_7 -> V_117 + V_120 ) ) {
F_90 ( V_2 , V_7 ) ;
F_88 ( V_2 , V_7 ) ;
if ( ! F_1 ( V_2 ) ) {
unsigned long V_146 ;
struct V_20 * V_147 = F_20 ( V_2 ) ;
F_64 ( & V_147 -> V_62 , V_146 ) ;
F_92 ( V_2 , V_146 ) ;
} else {
V_7 -> V_113 = V_115 ;
if ( V_2 -> V_119 == V_7 -> V_118 &&
* V_7 -> V_18 [ V_19 ] != V_143 )
F_14 ( V_2 , 0 ) ;
V_7 -> V_118 = V_2 -> V_119 ;
V_7 -> V_117 = V_7 -> V_92 ;
}
} else if ( F_23 ( F_2 ( V_2 -> V_126 ) , V_23 ) )
F_14 ( V_2 , 1 ) ;
F_43 ( V_39 ) ;
}
void F_149 ( struct V_106 * V_143 , void (* F_143)( struct V_106 * V_144 ) )
{
F_142 ( V_143 , F_143 , & V_12 , 0 ) ;
}
void F_150 ( struct V_106 * V_143 , void (* F_143)( struct V_106 * V_144 ) )
{
F_142 ( V_143 , F_143 , & V_13 , 0 ) ;
}
static inline int F_151 ( void )
{
F_152 () ;
return F_153 () <= 1 ;
}
void F_154 ( void )
{
F_38 ( ! F_39 ( & V_37 ) &&
! F_39 ( & V_36 ) &&
! F_39 ( & V_38 ) ,
L_32 ) ;
if ( F_151 () )
return;
F_155 ( F_149 ) ;
}
void F_156 ( void )
{
F_38 ( ! F_39 ( & V_37 ) &&
! F_39 ( & V_36 ) &&
! F_39 ( & V_38 ) ,
L_33 ) ;
if ( F_151 () )
return;
F_155 ( F_150 ) ;
}
static int F_157 ( void * V_148 )
{
F_123 () ;
return 0 ;
}
void F_158 ( void )
{
int V_149 , V_150 , V_53 , V_151 = 0 ;
V_149 = V_53 = F_159 ( & V_152 ) ;
F_160 () ;
F_36 ( F_22 ( F_161 () ) ) ;
while ( F_162 ( V_153 ,
F_157 ,
NULL ) == - V_154 ) {
F_163 () ;
if ( V_151 ++ < 10 )
F_164 ( V_151 * F_153 () ) ;
else {
F_154 () ;
return;
}
V_150 = F_37 ( & V_155 ) ;
if ( F_60 ( ( unsigned ) V_150 , ( unsigned ) V_149 ) ) {
F_123 () ;
return;
}
F_160 () ;
V_53 = F_37 ( & V_152 ) ;
F_123 () ;
}
do {
V_150 = F_37 ( & V_155 ) ;
if ( F_60 ( ( unsigned ) V_150 , ( unsigned ) V_53 ) ) {
F_123 () ;
break;
}
} while ( F_165 ( & V_155 , V_150 , V_53 ) != V_150 );
F_163 () ;
}
static int F_166 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
struct V_20 * V_46 = V_7 -> V_47 ;
V_7 -> V_156 ++ ;
F_78 ( V_2 , V_7 ) ;
if ( V_50 &&
V_7 -> V_80 && ! V_7 -> V_10 ) {
V_7 -> V_157 ++ ;
if ( ! V_7 -> V_158 &&
F_23 ( F_2 ( V_2 -> V_126 ) - 1 ,
V_23 ) )
F_77 () ;
} else if ( V_7 -> V_80 && V_7 -> V_10 ) {
V_7 -> V_159 ++ ;
return 1 ;
}
if ( F_18 ( V_7 ) ) {
V_7 -> V_160 ++ ;
return 1 ;
}
if ( F_19 ( V_2 , V_7 ) ) {
V_7 -> V_161 ++ ;
return 1 ;
}
if ( F_2 ( V_46 -> V_3 ) != V_7 -> V_3 ) {
V_7 -> V_162 ++ ;
return 1 ;
}
if ( F_2 ( V_46 -> V_4 ) != V_7 -> V_4 ) {
V_7 -> V_163 ++ ;
return 1 ;
}
if ( F_1 ( V_2 ) &&
F_23 ( F_2 ( V_2 -> V_126 ) , V_23 ) ) {
V_7 -> V_164 ++ ;
return 1 ;
}
V_7 -> V_165 ++ ;
return 0 ;
}
static int F_129 ( int V_5 )
{
return F_166 ( & V_12 , & F_4 ( V_8 , V_5 ) ) ||
F_166 ( & V_13 , & F_4 ( V_11 , V_5 ) ) ||
F_167 ( V_5 ) ;
}
static int F_168 ( int V_5 )
{
return F_4 ( V_8 , V_5 ) . V_17 ||
F_4 ( V_11 , V_5 ) . V_17 ||
F_169 ( V_5 ) ;
}
static void F_170 ( struct V_106 * V_166 )
{
if ( F_171 ( & V_167 ) )
F_172 ( & V_168 ) ;
}
static void F_173 ( void * type )
{
int V_5 = F_29 () ;
struct V_106 * V_143 = & F_4 ( V_169 , V_5 ) ;
void (* F_174)( struct V_106 * V_143 ,
void (* F_143)( struct V_106 * V_143 ) );
F_34 ( & V_167 ) ;
F_174 = type ;
F_174 ( V_143 , F_170 ) ;
}
static void F_175 ( struct V_1 * V_2 ,
void (* F_174)( struct V_106 * V_143 ,
void (* F_143)( struct V_106 * V_143 ) ) )
{
int V_5 ;
unsigned long V_39 ;
struct V_6 * V_7 ;
struct V_106 V_170 ;
F_176 ( & V_170 ) ;
F_177 ( & V_171 ) ;
F_123 () ;
F_178 ( & V_168 ) ;
F_179 ( & V_167 , 1 ) ;
F_64 ( & V_2 -> V_103 , V_39 ) ;
V_2 -> V_98 = V_29 ;
F_65 ( & V_2 -> V_103 , V_39 ) ;
F_180 (cpu) {
F_52 () ;
V_7 = F_107 ( V_2 -> V_97 , V_5 ) ;
if ( F_22 ( V_5 ) ) {
F_53 () ;
while ( F_22 ( V_5 ) && F_2 ( V_7 -> V_92 ) )
F_181 ( 1 ) ;
} else if ( F_2 ( V_7 -> V_92 ) ) {
F_182 ( V_5 , F_173 ,
( void * ) F_174 , 1 ) ;
F_53 () ;
} else {
F_53 () ;
}
}
F_64 ( & V_2 -> V_103 , V_39 ) ;
F_100 ( V_2 ) ;
V_2 -> V_98 = NULL ;
F_65 ( & V_2 -> V_103 , V_39 ) ;
F_34 ( & V_167 ) ;
F_35 () ;
F_174 ( & V_170 , F_170 ) ;
if ( F_171 ( & V_167 ) )
F_172 ( & V_168 ) ;
F_183 ( & V_168 ) ;
F_184 ( & V_171 ) ;
F_185 ( & V_170 ) ;
}
void F_186 ( void )
{
F_175 ( & V_13 , F_150 ) ;
}
void F_187 ( void )
{
F_175 ( & V_12 , F_149 ) ;
}
static void T_1
F_188 ( int V_5 , struct V_1 * V_2 )
{
unsigned long V_39 ;
int V_90 ;
struct V_6 * V_7 = F_107 ( V_2 -> V_97 , V_5 ) ;
struct V_20 * V_46 = F_20 ( V_2 ) ;
F_64 ( & V_46 -> V_62 , V_39 ) ;
V_7 -> V_48 = 1UL << ( V_5 - V_7 -> V_47 -> V_67 ) ;
V_7 -> V_17 = NULL ;
for ( V_90 = 0 ; V_90 < V_96 ; V_90 ++ )
V_7 -> V_18 [ V_90 ] = & V_7 -> V_17 ;
V_7 -> V_91 = 0 ;
V_7 -> V_92 = 0 ;
V_7 -> V_35 = & F_4 ( V_26 , V_5 ) ;
F_36 ( V_7 -> V_35 -> V_40 != V_43 ) ;
F_36 ( F_37 ( & V_7 -> V_35 -> V_35 ) != 1 ) ;
V_7 -> V_5 = V_5 ;
V_7 -> V_2 = V_2 ;
F_65 ( & V_46 -> V_62 , V_39 ) ;
}
static void T_2
F_189 ( int V_5 , struct V_1 * V_2 , int V_158 )
{
unsigned long V_39 ;
unsigned long V_84 ;
struct V_6 * V_7 = F_107 ( V_2 -> V_97 , V_5 ) ;
struct V_20 * V_46 = F_20 ( V_2 ) ;
F_64 ( & V_46 -> V_62 , V_39 ) ;
V_7 -> V_138 = 1 ;
V_7 -> V_158 = V_158 ;
V_7 -> V_117 = 0 ;
V_7 -> V_118 = V_2 -> V_119 ;
V_7 -> V_113 = V_113 ;
V_7 -> V_35 -> V_40 = V_43 ;
F_179 ( & V_7 -> V_35 -> V_35 ,
( F_37 ( & V_7 -> V_35 -> V_35 ) & ~ 0x1 ) + 1 ) ;
F_190 ( V_5 ) ;
F_111 ( & V_46 -> V_62 ) ;
F_110 ( & V_2 -> V_103 ) ;
V_46 = V_7 -> V_47 ;
V_84 = V_7 -> V_48 ;
do {
F_110 ( & V_46 -> V_62 ) ;
V_46 -> V_49 |= V_84 ;
V_84 = V_46 -> V_48 ;
if ( V_46 == V_7 -> V_47 ) {
V_7 -> V_4 = V_46 -> V_3 ;
V_7 -> V_3 = V_46 -> V_3 ;
V_7 -> V_10 = 0 ;
V_7 -> V_80 = 0 ;
V_7 -> V_9 = V_46 -> V_4 - 1 ;
F_6 ( V_2 -> V_24 , V_7 -> V_4 , L_34 ) ;
}
F_111 ( & V_46 -> V_62 ) ;
V_46 = V_46 -> V_88 ;
} while ( V_46 != NULL && ! ( V_46 -> V_49 & V_84 ) );
F_65 ( & V_2 -> V_103 , V_39 ) ;
}
static void T_2 F_191 ( int V_5 )
{
F_189 ( V_5 , & V_12 , 0 ) ;
F_189 ( V_5 , & V_13 , 0 ) ;
F_192 ( V_5 ) ;
}
static int T_2 F_193 ( struct V_72 * V_172 ,
unsigned long V_173 , void * V_174 )
{
long V_5 = ( long ) V_174 ;
struct V_6 * V_7 = F_107 ( V_1 -> V_97 , V_5 ) ;
struct V_20 * V_46 = V_7 -> V_47 ;
F_9 ( L_35 ) ;
switch ( V_173 ) {
case V_175 :
case V_176 :
F_191 ( V_5 ) ;
F_194 ( V_5 ) ;
break;
case V_177 :
case V_178 :
F_109 ( V_46 , - 1 ) ;
F_195 ( V_5 , 1 ) ;
break;
case V_179 :
F_109 ( V_46 , V_5 ) ;
F_195 ( V_5 , 0 ) ;
break;
case V_180 :
case V_181 :
F_103 ( & V_13 ) ;
F_103 ( & V_12 ) ;
F_196 () ;
F_46 ( V_5 ) ;
break;
case V_182 :
case V_183 :
case V_184 :
case V_185 :
F_106 ( V_5 , & V_13 ) ;
F_106 ( V_5 , & V_12 ) ;
F_197 ( V_5 ) ;
break;
default:
break;
}
F_9 ( L_36 ) ;
return V_186 ;
}
void F_198 ( void )
{
F_199 ( F_153 () != 1 ) ;
F_199 ( F_200 () > 0 ) ;
V_187 = 1 ;
}
static void T_1 F_201 ( struct V_1 * V_2 )
{
int V_90 ;
for ( V_90 = V_188 - 1 ; V_90 > 0 ; V_90 -- )
V_2 -> V_189 [ V_90 ] = V_190 ;
V_2 -> V_189 [ 0 ] = V_191 ;
}
static void T_1 F_201 ( struct V_1 * V_2 )
{
int V_192 ;
int V_193 ;
int V_90 ;
V_193 = V_194 ;
for ( V_90 = V_188 - 1 ; V_90 >= 0 ; V_90 -- ) {
V_192 = V_2 -> V_195 [ V_90 ] ;
V_2 -> V_189 [ V_90 ] = ( V_193 + V_192 - 1 ) / V_192 ;
V_193 = V_192 ;
}
}
static void T_1 F_202 ( struct V_1 * V_2 ,
struct V_6 T_3 * V_97 )
{
static char * V_196 [] = { L_37 ,
L_38 ,
L_39 ,
L_40 } ;
int V_197 = 1 ;
int V_90 ;
int V_69 ;
struct V_20 * V_46 ;
F_203 ( V_198 > F_204 ( V_196 ) ) ;
for ( V_90 = 1 ; V_90 < V_188 ; V_90 ++ )
V_2 -> V_86 [ V_90 ] = V_2 -> V_86 [ V_90 - 1 ] + V_2 -> V_195 [ V_90 - 1 ] ;
F_201 ( V_2 ) ;
for ( V_90 = V_188 - 1 ; V_90 >= 0 ; V_90 -- ) {
V_197 *= V_2 -> V_189 [ V_90 ] ;
V_46 = V_2 -> V_86 [ V_90 ] ;
for ( V_69 = 0 ; V_69 < V_2 -> V_195 [ V_90 ] ; V_69 ++ , V_46 ++ ) {
F_205 ( & V_46 -> V_62 ) ;
F_206 ( & V_46 -> V_62 ,
& V_199 [ V_90 ] , V_196 [ V_90 ] ) ;
V_46 -> V_4 = 0 ;
V_46 -> V_65 = 0 ;
V_46 -> V_49 = 0 ;
V_46 -> V_67 = V_69 * V_197 ;
V_46 -> V_66 = ( V_69 + 1 ) * V_197 - 1 ;
if ( V_46 -> V_66 >= V_194 )
V_46 -> V_66 = V_194 - 1 ;
if ( V_90 == 0 ) {
V_46 -> V_200 = 0 ;
V_46 -> V_48 = 0 ;
V_46 -> V_88 = NULL ;
} else {
V_46 -> V_200 = V_69 % V_2 -> V_189 [ V_90 - 1 ] ;
V_46 -> V_48 = 1UL << V_46 -> V_200 ;
V_46 -> V_88 = V_2 -> V_86 [ V_90 - 1 ] +
V_69 / V_2 -> V_189 [ V_90 - 1 ] ;
}
V_46 -> V_86 = V_90 ;
F_207 ( & V_46 -> V_201 ) ;
}
}
V_2 -> V_97 = V_97 ;
V_46 = V_2 -> V_86 [ V_188 - 1 ] ;
F_180 (i) {
while ( V_90 > V_46 -> V_66 )
V_46 ++ ;
F_107 ( V_2 -> V_97 , V_90 ) -> V_47 = V_46 ;
F_188 ( V_90 , V_2 ) ;
}
}
void T_1 F_208 ( void )
{
int V_5 ;
F_209 () ;
F_202 ( & V_12 , & V_8 ) ;
F_202 ( & V_13 , & V_11 ) ;
F_210 () ;
F_211 ( V_142 , F_136 ) ;
F_212 ( F_193 , 0 ) ;
F_213 (cpu)
F_193 ( NULL , V_175 , ( void * ) ( long ) V_5 ) ;
F_82 () ;
}
