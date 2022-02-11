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
static void F_99 ( struct V_1 * V_2 )
{
int V_90 ;
unsigned long V_84 ;
int V_91 = F_100 ( V_92 ) ;
struct V_6 * V_7 = F_101 ( V_2 -> V_93 ) ;
struct V_6 * V_94 = F_102 ( V_2 -> V_93 , V_91 ) ;
F_103 ( struct V_20 * V_46 = V_7 -> V_47 ) ;
if ( V_7 -> V_17 != NULL ) {
V_94 -> V_95 += V_7 -> V_95 ;
V_94 -> V_96 += V_7 -> V_96 ;
V_7 -> V_95 = 0 ;
V_7 -> V_96 = 0 ;
}
if ( V_7 -> V_17 != NULL &&
V_7 -> V_18 [ V_19 ] != & V_7 -> V_17 ) {
struct V_97 * V_98 ;
struct V_97 * * V_99 ;
struct V_97 * * V_100 ;
V_98 = V_7 -> V_17 ;
V_99 = V_94 -> V_18 [ V_19 ] ;
V_7 -> V_17 = * V_7 -> V_18 [ V_19 ] ;
* V_7 -> V_18 [ V_19 ] = * V_99 ;
* V_94 -> V_18 [ V_19 ] = V_98 ;
V_100 = V_7 -> V_18 [ V_19 ] ;
for ( V_90 = V_19 ; V_90 < V_101 ; V_90 ++ ) {
if ( V_94 -> V_18 [ V_90 ] == V_99 )
V_94 -> V_18 [ V_90 ] = V_100 ;
if ( V_7 -> V_18 [ V_90 ] == V_100 )
V_7 -> V_18 [ V_90 ] = & V_7 -> V_17 ;
}
}
if ( V_7 -> V_17 != NULL ) {
* V_94 -> V_18 [ V_83 ] = V_7 -> V_17 ;
V_94 -> V_18 [ V_83 ] =
V_7 -> V_18 [ V_83 ] ;
V_94 -> V_102 += V_7 -> V_96 ;
V_7 -> V_103 += V_7 -> V_96 ;
V_7 -> V_17 = NULL ;
for ( V_90 = 0 ; V_90 < V_101 ; V_90 ++ )
V_7 -> V_18 [ V_90 ] = & V_7 -> V_17 ;
}
V_84 = V_7 -> V_48 ;
F_6 ( V_2 -> V_24 ,
V_46 -> V_4 + 1 - ! ! ( V_46 -> V_65 & V_84 ) ,
L_25 ) ;
F_97 ( F_29 () , V_2 , V_7 , V_2 -> V_4 ) ;
}
static void F_104 ( int V_5 , struct V_1 * V_2 )
{
unsigned long V_39 ;
unsigned long V_84 ;
int V_104 = 0 ;
struct V_6 * V_7 = F_102 ( V_2 -> V_93 , V_5 ) ;
struct V_20 * V_46 = V_7 -> V_47 ;
F_105 ( V_5 ) ;
F_106 ( V_46 , - 1 ) ;
F_64 ( & V_2 -> V_105 , V_39 ) ;
V_84 = V_7 -> V_48 ;
do {
F_107 ( & V_46 -> V_62 ) ;
V_46 -> V_49 &= ~ V_84 ;
if ( V_46 -> V_49 != 0 ) {
if ( V_46 != V_7 -> V_47 )
F_108 ( & V_46 -> V_62 ) ;
break;
}
if ( V_46 == V_7 -> V_47 )
V_104 = F_109 ( V_2 , V_46 , V_7 ) ;
else
F_108 ( & V_46 -> V_62 ) ;
V_84 = V_46 -> V_48 ;
V_46 = V_46 -> V_88 ;
} while ( V_46 != NULL );
F_108 ( & V_2 -> V_105 ) ;
V_46 = V_7 -> V_47 ;
if ( V_104 & V_106 )
F_110 ( V_46 , V_39 ) ;
else
F_65 ( & V_46 -> V_62 , V_39 ) ;
if ( V_104 & V_107 )
F_111 ( V_2 , V_46 , true ) ;
}
static void F_99 ( struct V_1 * V_2 )
{
}
static void F_104 ( int V_5 , struct V_1 * V_2 )
{
}
static void F_112 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
unsigned long V_39 ;
struct V_97 * V_108 , * V_109 , * * V_110 ;
int V_111 , V_112 , V_113 ;
if ( ! F_18 ( V_7 ) ) {
F_113 ( V_2 -> V_24 , V_7 -> V_95 , V_7 -> V_96 , 0 ) ;
F_114 ( V_2 -> V_24 , 0 , ! ! F_2 ( V_7 -> V_17 ) ,
F_115 () , F_27 ( V_29 ) ,
F_116 () ) ;
return;
}
F_41 ( V_39 ) ;
F_36 ( F_22 ( F_29 () ) ) ;
V_111 = V_7 -> V_114 ;
F_113 ( V_2 -> V_24 , V_7 -> V_95 , V_7 -> V_96 , V_111 ) ;
V_109 = V_7 -> V_17 ;
V_7 -> V_17 = * V_7 -> V_18 [ V_19 ] ;
* V_7 -> V_18 [ V_19 ] = NULL ;
V_110 = V_7 -> V_18 [ V_19 ] ;
for ( V_112 = V_101 - 1 ; V_112 >= 0 ; V_112 -- )
if ( V_7 -> V_18 [ V_112 ] == V_7 -> V_18 [ V_19 ] )
V_7 -> V_18 [ V_112 ] = & V_7 -> V_17 ;
F_43 ( V_39 ) ;
V_112 = V_113 = 0 ;
while ( V_109 ) {
V_108 = V_109 -> V_108 ;
F_117 ( V_108 ) ;
F_118 ( V_109 ) ;
if ( F_119 ( V_2 -> V_24 , V_109 ) )
V_113 ++ ;
V_109 = V_108 ;
if ( ++ V_112 >= V_111 &&
( F_115 () ||
( ! F_27 ( V_29 ) && ! F_116 () ) ) )
break;
}
F_41 ( V_39 ) ;
F_114 ( V_2 -> V_24 , V_112 , ! ! V_109 , F_115 () ,
F_27 ( V_29 ) ,
F_116 () ) ;
V_7 -> V_95 -= V_113 ;
V_7 -> V_96 -= V_112 ;
V_7 -> V_115 += V_112 ;
if ( V_109 != NULL ) {
* V_110 = V_7 -> V_17 ;
V_7 -> V_17 = V_109 ;
for ( V_112 = 0 ; V_112 < V_101 ; V_112 ++ )
if ( & V_7 -> V_17 == V_7 -> V_18 [ V_112 ] )
V_7 -> V_18 [ V_112 ] = V_110 ;
else
break;
}
if ( V_7 -> V_114 == V_116 && V_7 -> V_96 <= V_117 )
V_7 -> V_114 = V_114 ;
if ( V_7 -> V_96 == 0 && V_7 -> V_118 != 0 ) {
V_7 -> V_118 = 0 ;
V_7 -> V_119 = V_2 -> V_120 ;
} else if ( V_7 -> V_96 < V_7 -> V_118 - V_121 )
V_7 -> V_118 = V_7 -> V_96 ;
F_43 ( V_39 ) ;
if ( F_18 ( V_7 ) )
F_120 () ;
}
void F_121 ( int V_5 , int V_122 )
{
F_9 ( L_26 ) ;
F_122 () ;
if ( V_122 || F_56 () ) {
F_3 ( V_5 ) ;
F_7 ( V_5 ) ;
} else if ( ! F_123 () ) {
F_7 ( V_5 ) ;
}
F_124 ( V_5 ) ;
if ( F_125 ( V_5 ) )
F_120 () ;
F_9 ( L_27 ) ;
}
static void F_126 ( struct V_1 * V_2 , int (* F_127)( struct V_6 * ) )
{
unsigned long V_123 ;
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
F_128 ( V_46 , V_39 ) ;
continue;
}
V_5 = V_46 -> V_67 ;
V_123 = 1 ;
for (; V_5 <= V_46 -> V_66 ; V_5 ++ , V_123 <<= 1 ) {
if ( ( V_46 -> V_65 & V_123 ) != 0 &&
F_127 ( F_102 ( V_2 -> V_93 , V_5 ) ) )
V_84 |= V_123 ;
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
F_128 ( V_46 , V_39 ) ;
}
}
static void F_14 ( struct V_1 * V_2 , int V_124 )
{
unsigned long V_39 ;
struct V_20 * V_46 = F_20 ( V_2 ) ;
F_9 ( L_28 ) ;
if ( ! F_1 ( V_2 ) ) {
F_9 ( L_29 ) ;
return;
}
if ( ! F_129 ( & V_2 -> V_125 , V_39 ) ) {
V_2 -> V_126 ++ ;
F_9 ( L_29 ) ;
return;
}
if ( V_124 && F_76 ( V_2 -> V_127 , V_23 ) )
goto V_128;
V_2 -> V_120 ++ ;
F_107 ( & V_46 -> V_62 ) ;
V_2 -> V_127 = V_23 + V_129 ;
if( ! F_1 ( V_2 ) ) {
V_2 -> V_130 ++ ;
F_108 ( & V_46 -> V_62 ) ;
goto V_128;
}
V_2 -> V_131 = 1 ;
switch ( V_2 -> V_132 ) {
case V_133 :
case V_134 :
break;
case V_135 :
if ( V_136 != V_135 )
break;
F_108 ( & V_46 -> V_62 ) ;
F_126 ( V_2 , F_57 ) ;
F_107 ( & V_46 -> V_62 ) ;
if ( F_1 ( V_2 ) )
V_2 -> V_132 = V_137 ;
break;
case V_137 :
F_108 ( & V_46 -> V_62 ) ;
F_126 ( V_2 , F_59 ) ;
F_107 ( & V_46 -> V_62 ) ;
break;
}
V_2 -> V_131 = 0 ;
if ( V_2 -> V_138 ) {
F_108 ( & V_2 -> V_125 ) ;
V_2 -> V_138 = 0 ;
F_92 ( V_2 , V_39 ) ;
F_9 ( L_29 ) ;
return;
}
F_108 ( & V_46 -> V_62 ) ;
V_128:
F_65 ( & V_2 -> V_125 , V_39 ) ;
F_9 ( L_29 ) ;
}
static void
F_130 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
unsigned long V_39 ;
F_36 ( V_7 -> V_139 == 0 ) ;
if ( F_23 ( F_2 ( V_2 -> V_127 ) , V_23 ) )
F_14 ( V_2 , 1 ) ;
F_90 ( V_2 , V_7 ) ;
F_98 ( V_2 , V_7 ) ;
if ( F_19 ( V_2 , V_7 ) ) {
F_64 ( & F_20 ( V_2 ) -> V_62 , V_39 ) ;
F_92 ( V_2 , V_39 ) ;
}
if ( F_18 ( V_7 ) )
F_131 ( V_2 , V_7 ) ;
}
static void F_132 ( struct V_140 * V_141 )
{
F_9 ( L_30 ) ;
F_130 ( & V_12 ,
& F_42 ( V_8 ) ) ;
F_130 ( & V_13 , & F_42 ( V_11 ) ) ;
F_133 () ;
F_9 ( L_31 ) ;
}
static void F_131 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
if ( F_134 ( ! F_2 ( V_50 ) ) )
return;
if ( F_135 ( ! V_2 -> V_142 ) ) {
F_112 ( V_2 , V_7 ) ;
return;
}
F_136 () ;
}
static void F_120 ( void )
{
F_137 ( V_143 ) ;
}
static void
F_138 ( struct V_97 * V_144 , void (* F_139)( struct V_97 * V_145 ) ,
struct V_1 * V_2 , bool V_146 )
{
unsigned long V_39 ;
struct V_6 * V_7 ;
F_36 ( ( unsigned long ) V_144 & 0x3 ) ;
F_140 ( V_144 ) ;
V_144 -> F_139 = F_139 ;
V_144 -> V_108 = NULL ;
F_141 () ;
F_41 ( V_39 ) ;
V_7 = F_101 ( V_2 -> V_93 ) ;
* V_7 -> V_18 [ V_83 ] = V_144 ;
V_7 -> V_18 [ V_83 ] = & V_144 -> V_108 ;
V_7 -> V_96 ++ ;
if ( V_146 )
V_7 -> V_95 ++ ;
if ( F_142 ( ( unsigned long ) F_139 ) )
F_143 ( V_2 -> V_24 , V_144 , ( unsigned long ) F_139 ,
V_7 -> V_95 , V_7 -> V_96 ) ;
else
F_144 ( V_2 -> V_24 , V_144 , V_7 -> V_95 , V_7 -> V_96 ) ;
if ( F_145 ( V_39 ) ) {
F_43 ( V_39 ) ;
return;
}
if ( F_134 ( V_7 -> V_96 > V_7 -> V_118 + V_121 ) ) {
F_90 ( V_2 , V_7 ) ;
F_88 ( V_2 , V_7 ) ;
if ( ! F_1 ( V_2 ) ) {
unsigned long V_147 ;
struct V_20 * V_148 = F_20 ( V_2 ) ;
F_64 ( & V_148 -> V_62 , V_147 ) ;
F_92 ( V_2 , V_147 ) ;
} else {
V_7 -> V_114 = V_116 ;
if ( V_2 -> V_120 == V_7 -> V_119 &&
* V_7 -> V_18 [ V_19 ] != V_144 )
F_14 ( V_2 , 0 ) ;
V_7 -> V_119 = V_2 -> V_120 ;
V_7 -> V_118 = V_7 -> V_96 ;
}
} else if ( F_23 ( F_2 ( V_2 -> V_127 ) , V_23 ) )
F_14 ( V_2 , 1 ) ;
F_43 ( V_39 ) ;
}
void F_146 ( struct V_97 * V_144 , void (* F_139)( struct V_97 * V_145 ) )
{
F_138 ( V_144 , F_139 , & V_12 , 0 ) ;
}
void F_147 ( struct V_97 * V_144 , void (* F_139)( struct V_97 * V_145 ) )
{
F_138 ( V_144 , F_139 , & V_13 , 0 ) ;
}
void F_148 ( void )
{
F_38 ( ! F_39 ( & V_37 ) &&
! F_39 ( & V_36 ) &&
! F_39 ( & V_38 ) ,
L_32 ) ;
if ( F_149 () )
return;
F_150 ( F_146 ) ;
}
void F_151 ( void )
{
F_38 ( ! F_39 ( & V_37 ) &&
! F_39 ( & V_36 ) &&
! F_39 ( & V_38 ) ,
L_33 ) ;
if ( F_149 () )
return;
F_150 ( F_147 ) ;
}
static int F_152 ( void * V_149 )
{
F_141 () ;
return 0 ;
}
void F_153 ( void )
{
int V_150 , V_151 , V_53 , V_152 = 0 ;
V_150 = V_53 = F_154 ( & V_153 ) ;
F_155 () ;
F_36 ( F_22 ( F_156 () ) ) ;
while ( F_157 ( V_92 ,
F_152 ,
NULL ) == - V_154 ) {
F_158 () ;
if ( V_152 ++ < 10 )
F_159 ( V_152 * F_160 () ) ;
else {
F_148 () ;
return;
}
V_151 = F_37 ( & V_155 ) ;
if ( F_60 ( ( unsigned ) V_151 , ( unsigned ) V_150 ) ) {
F_141 () ;
return;
}
F_155 () ;
V_53 = F_37 ( & V_153 ) ;
F_141 () ;
}
do {
V_151 = F_37 ( & V_155 ) ;
if ( F_60 ( ( unsigned ) V_151 , ( unsigned ) V_53 ) ) {
F_141 () ;
break;
}
} while ( F_161 ( & V_155 , V_151 , V_53 ) != V_151 );
F_158 () ;
}
static int F_162 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
struct V_20 * V_46 = V_7 -> V_47 ;
V_7 -> V_156 ++ ;
F_78 ( V_2 , V_7 ) ;
if ( V_50 &&
V_7 -> V_80 && ! V_7 -> V_10 ) {
V_7 -> V_157 ++ ;
if ( ! V_7 -> V_158 &&
F_23 ( F_2 ( V_2 -> V_127 ) - 1 ,
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
F_23 ( F_2 ( V_2 -> V_127 ) , V_23 ) ) {
V_7 -> V_164 ++ ;
return 1 ;
}
V_7 -> V_165 ++ ;
return 0 ;
}
static int F_125 ( int V_5 )
{
return F_162 ( & V_12 , & F_4 ( V_8 , V_5 ) ) ||
F_162 ( & V_13 , & F_4 ( V_11 , V_5 ) ) ||
F_163 ( V_5 ) ;
}
static int F_164 ( int V_5 )
{
return F_4 ( V_8 , V_5 ) . V_17 ||
F_4 ( V_11 , V_5 ) . V_17 ||
F_165 ( V_5 ) ;
}
static void F_166 ( struct V_97 * V_166 )
{
if ( F_167 ( & V_167 ) )
F_168 ( & V_168 ) ;
}
static void F_169 ( void * type )
{
int V_5 = F_29 () ;
struct V_97 * V_144 = & F_4 ( V_169 , V_5 ) ;
void (* F_170)( struct V_97 * V_144 ,
void (* F_139)( struct V_97 * V_144 ) );
F_34 ( & V_167 ) ;
F_170 = type ;
F_170 ( V_144 , F_166 ) ;
}
static void F_171 ( struct V_1 * V_2 ,
void (* F_170)( struct V_97 * V_144 ,
void (* F_139)( struct V_97 * V_144 ) ) )
{
F_172 ( F_173 () ) ;
F_174 ( & V_170 ) ;
F_175 ( & V_168 ) ;
F_176 ( & V_167 , 1 ) ;
F_177 ( F_169 , ( void * ) F_170 , 1 ) ;
if ( F_167 ( & V_167 ) )
F_168 ( & V_168 ) ;
F_178 ( & V_168 ) ;
F_179 ( & V_170 ) ;
}
void F_180 ( void )
{
F_171 ( & V_13 , F_147 ) ;
}
void F_181 ( void )
{
F_171 ( & V_12 , F_146 ) ;
}
static void T_1
F_182 ( int V_5 , struct V_1 * V_2 )
{
unsigned long V_39 ;
int V_90 ;
struct V_6 * V_7 = F_102 ( V_2 -> V_93 , V_5 ) ;
struct V_20 * V_46 = F_20 ( V_2 ) ;
F_64 ( & V_46 -> V_62 , V_39 ) ;
V_7 -> V_48 = 1UL << ( V_5 - V_7 -> V_47 -> V_67 ) ;
V_7 -> V_17 = NULL ;
for ( V_90 = 0 ; V_90 < V_101 ; V_90 ++ )
V_7 -> V_18 [ V_90 ] = & V_7 -> V_17 ;
V_7 -> V_95 = 0 ;
V_7 -> V_96 = 0 ;
V_7 -> V_35 = & F_4 ( V_26 , V_5 ) ;
F_36 ( V_7 -> V_35 -> V_40 != V_43 ) ;
F_36 ( F_37 ( & V_7 -> V_35 -> V_35 ) != 1 ) ;
V_7 -> V_5 = V_5 ;
V_7 -> V_2 = V_2 ;
F_65 ( & V_46 -> V_62 , V_39 ) ;
}
static void T_2
F_183 ( int V_5 , struct V_1 * V_2 , int V_158 )
{
unsigned long V_39 ;
unsigned long V_84 ;
struct V_6 * V_7 = F_102 ( V_2 -> V_93 , V_5 ) ;
struct V_20 * V_46 = F_20 ( V_2 ) ;
F_64 ( & V_46 -> V_62 , V_39 ) ;
V_7 -> V_139 = 1 ;
V_7 -> V_158 = V_158 ;
V_7 -> V_118 = 0 ;
V_7 -> V_119 = V_2 -> V_120 ;
V_7 -> V_114 = V_114 ;
V_7 -> V_35 -> V_40 = V_43 ;
F_176 ( & V_7 -> V_35 -> V_35 ,
( F_37 ( & V_7 -> V_35 -> V_35 ) & ~ 0x1 ) + 1 ) ;
F_184 ( V_5 ) ;
F_108 ( & V_46 -> V_62 ) ;
F_107 ( & V_2 -> V_105 ) ;
V_46 = V_7 -> V_47 ;
V_84 = V_7 -> V_48 ;
do {
F_107 ( & V_46 -> V_62 ) ;
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
F_108 ( & V_46 -> V_62 ) ;
V_46 = V_46 -> V_88 ;
} while ( V_46 != NULL && ! ( V_46 -> V_49 & V_84 ) );
F_65 ( & V_2 -> V_105 , V_39 ) ;
}
static void T_2 F_185 ( int V_5 )
{
F_183 ( V_5 , & V_12 , 0 ) ;
F_183 ( V_5 , & V_13 , 0 ) ;
F_186 ( V_5 ) ;
}
static int T_2 F_187 ( struct V_72 * V_171 ,
unsigned long V_172 , void * V_173 )
{
long V_5 = ( long ) V_173 ;
struct V_6 * V_7 = F_102 ( V_1 -> V_93 , V_5 ) ;
struct V_20 * V_46 = V_7 -> V_47 ;
F_9 ( L_35 ) ;
switch ( V_172 ) {
case V_174 :
case V_175 :
F_185 ( V_5 ) ;
F_188 ( V_5 ) ;
break;
case V_176 :
case V_177 :
F_106 ( V_46 , - 1 ) ;
F_189 ( V_5 , 1 ) ;
break;
case V_178 :
F_106 ( V_46 , V_5 ) ;
F_189 ( V_5 , 0 ) ;
break;
case V_179 :
case V_180 :
F_99 ( & V_13 ) ;
F_99 ( & V_12 ) ;
F_190 () ;
F_46 ( V_5 ) ;
break;
case V_181 :
case V_182 :
case V_183 :
case V_184 :
F_104 ( V_5 , & V_13 ) ;
F_104 ( V_5 , & V_12 ) ;
F_191 ( V_5 ) ;
break;
default:
break;
}
F_9 ( L_36 ) ;
return V_185 ;
}
void F_192 ( void )
{
F_193 ( F_160 () != 1 ) ;
F_193 ( F_194 () > 0 ) ;
V_186 = 1 ;
}
static void T_1 F_195 ( struct V_1 * V_2 )
{
int V_90 ;
for ( V_90 = V_187 - 1 ; V_90 > 0 ; V_90 -- )
V_2 -> V_188 [ V_90 ] = V_189 ;
V_2 -> V_188 [ 0 ] = V_190 ;
}
static void T_1 F_195 ( struct V_1 * V_2 )
{
int V_191 ;
int V_192 ;
int V_90 ;
V_192 = V_193 ;
for ( V_90 = V_187 - 1 ; V_90 >= 0 ; V_90 -- ) {
V_191 = V_2 -> V_194 [ V_90 ] ;
V_2 -> V_188 [ V_90 ] = ( V_192 + V_191 - 1 ) / V_191 ;
V_192 = V_191 ;
}
}
static void T_1 F_196 ( struct V_1 * V_2 ,
struct V_6 T_3 * V_93 )
{
static char * V_195 [] = { L_37 ,
L_38 ,
L_39 ,
L_40 } ;
int V_196 = 1 ;
int V_90 ;
int V_69 ;
struct V_20 * V_46 ;
F_197 ( V_197 > F_198 ( V_195 ) ) ;
for ( V_90 = 1 ; V_90 < V_187 ; V_90 ++ )
V_2 -> V_86 [ V_90 ] = V_2 -> V_86 [ V_90 - 1 ] + V_2 -> V_194 [ V_90 - 1 ] ;
F_195 ( V_2 ) ;
for ( V_90 = V_187 - 1 ; V_90 >= 0 ; V_90 -- ) {
V_196 *= V_2 -> V_188 [ V_90 ] ;
V_46 = V_2 -> V_86 [ V_90 ] ;
for ( V_69 = 0 ; V_69 < V_2 -> V_194 [ V_90 ] ; V_69 ++ , V_46 ++ ) {
F_199 ( & V_46 -> V_62 ) ;
F_200 ( & V_46 -> V_62 ,
& V_198 [ V_90 ] , V_195 [ V_90 ] ) ;
V_46 -> V_4 = 0 ;
V_46 -> V_65 = 0 ;
V_46 -> V_49 = 0 ;
V_46 -> V_67 = V_69 * V_196 ;
V_46 -> V_66 = ( V_69 + 1 ) * V_196 - 1 ;
if ( V_46 -> V_66 >= V_193 )
V_46 -> V_66 = V_193 - 1 ;
if ( V_90 == 0 ) {
V_46 -> V_199 = 0 ;
V_46 -> V_48 = 0 ;
V_46 -> V_88 = NULL ;
} else {
V_46 -> V_199 = V_69 % V_2 -> V_188 [ V_90 - 1 ] ;
V_46 -> V_48 = 1UL << V_46 -> V_199 ;
V_46 -> V_88 = V_2 -> V_86 [ V_90 - 1 ] +
V_69 / V_2 -> V_188 [ V_90 - 1 ] ;
}
V_46 -> V_86 = V_90 ;
F_201 ( & V_46 -> V_200 ) ;
}
}
V_2 -> V_93 = V_93 ;
V_46 = V_2 -> V_86 [ V_187 - 1 ] ;
F_202 (i) {
while ( V_90 > V_46 -> V_66 )
V_46 ++ ;
F_102 ( V_2 -> V_93 , V_90 ) -> V_47 = V_46 ;
F_182 ( V_90 , V_2 ) ;
}
}
void T_1 F_203 ( void )
{
int V_5 ;
F_204 () ;
F_196 ( & V_12 , & V_8 ) ;
F_196 ( & V_13 , & V_11 ) ;
F_205 () ;
F_206 ( V_143 , F_132 ) ;
F_207 ( F_187 , 0 ) ;
F_208 (cpu)
F_187 ( NULL , V_174 , ( void * ) ( long ) V_5 ) ;
F_82 () ;
}
