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
if ( F_22 ( V_7 -> V_5 ) ) {
F_23 ( V_7 -> V_2 -> V_22 , V_7 -> V_4 , V_7 -> V_5 , L_6 ) ;
V_7 -> V_23 ++ ;
return 1 ;
}
if ( V_7 -> V_5 != F_24 () )
F_25 ( V_7 -> V_5 ) ;
else
F_26 () ;
V_7 -> V_24 ++ ;
return 0 ;
}
static void F_27 ( struct V_25 * V_26 , long long V_27 )
{
F_28 ( L_7 , V_27 , 0 ) ;
if ( ! F_29 ( V_28 ) ) {
struct V_29 * V_30 = F_30 ( F_24 () ) ;
F_28 ( L_8 , V_27 , 0 ) ;
F_31 ( V_31 ) ;
F_32 ( 1 , L_9 ,
V_28 -> V_32 , V_28 -> V_33 ,
V_30 -> V_32 , V_30 -> V_33 ) ;
}
F_33 ( F_24 () ) ;
F_34 () ;
F_35 ( & V_26 -> V_34 ) ;
F_36 () ;
F_37 ( F_38 ( & V_26 -> V_34 ) & 0x1 ) ;
}
void F_39 ( void )
{
unsigned long V_35 ;
long long V_27 ;
struct V_25 * V_26 ;
F_40 ( V_35 ) ;
V_26 = & F_41 ( V_25 ) ;
V_27 = V_26 -> V_36 ;
V_26 -> V_36 = 0 ;
F_27 ( V_26 , V_27 ) ;
F_42 ( V_35 ) ;
}
void F_43 ( void )
{
unsigned long V_35 ;
long long V_27 ;
struct V_25 * V_26 ;
F_40 ( V_35 ) ;
V_26 = & F_41 ( V_25 ) ;
V_27 = V_26 -> V_36 ;
V_26 -> V_36 -- ;
F_37 ( V_26 -> V_36 < 0 ) ;
if ( V_26 -> V_36 )
F_28 ( L_10 , V_27 , V_26 -> V_36 ) ;
else
F_27 ( V_26 , V_27 ) ;
F_42 ( V_35 ) ;
}
static void F_44 ( struct V_25 * V_26 , long long V_27 )
{
F_34 () ;
F_35 ( & V_26 -> V_34 ) ;
F_36 () ;
F_37 ( ! ( F_38 ( & V_26 -> V_34 ) & 0x1 ) ) ;
F_45 ( F_24 () ) ;
F_28 ( L_11 , V_27 , V_26 -> V_36 ) ;
if ( ! F_29 ( V_28 ) ) {
struct V_29 * V_30 = F_30 ( F_24 () ) ;
F_28 ( L_12 ,
V_27 , V_26 -> V_36 ) ;
F_31 ( V_31 ) ;
F_32 ( 1 , L_9 ,
V_28 -> V_32 , V_28 -> V_33 ,
V_30 -> V_32 , V_30 -> V_33 ) ;
}
}
void F_46 ( void )
{
unsigned long V_35 ;
struct V_25 * V_26 ;
long long V_27 ;
F_40 ( V_35 ) ;
V_26 = & F_41 ( V_25 ) ;
V_27 = V_26 -> V_36 ;
F_37 ( V_27 != 0 ) ;
V_26 -> V_36 = V_37 ;
F_44 ( V_26 , V_27 ) ;
F_42 ( V_35 ) ;
}
void F_47 ( void )
{
unsigned long V_35 ;
struct V_25 * V_26 ;
long long V_27 ;
F_40 ( V_35 ) ;
V_26 = & F_41 ( V_25 ) ;
V_27 = V_26 -> V_36 ;
V_26 -> V_36 ++ ;
F_37 ( V_26 -> V_36 == 0 ) ;
if ( V_27 )
F_28 ( L_13 , V_27 , V_26 -> V_36 ) ;
else
F_44 ( V_26 , V_27 ) ;
F_42 ( V_35 ) ;
}
void F_48 ( void )
{
struct V_25 * V_26 = & F_41 ( V_25 ) ;
if ( V_26 -> V_38 == 0 &&
( F_38 ( & V_26 -> V_34 ) & 0x1 ) )
return;
V_26 -> V_38 ++ ;
F_34 () ;
F_35 ( & V_26 -> V_34 ) ;
F_36 () ;
F_37 ( ! ( F_38 ( & V_26 -> V_34 ) & 0x1 ) ) ;
}
void F_49 ( void )
{
struct V_25 * V_26 = & F_41 ( V_25 ) ;
if ( V_26 -> V_38 == 0 ||
-- V_26 -> V_38 != 0 )
return;
F_34 () ;
F_35 ( & V_26 -> V_34 ) ;
F_36 () ;
F_37 ( F_38 ( & V_26 -> V_34 ) & 0x1 ) ;
}
int F_50 ( void )
{
int V_39 ;
F_51 () ;
V_39 = ( F_38 ( & F_41 ( V_25 ) . V_34 ) & 0x1 ) == 0 ;
F_52 () ;
return V_39 ;
}
int F_53 ( void )
{
return F_41 ( V_25 ) . V_36 <= 1 ;
}
static int F_54 ( struct V_6 * V_7 )
{
V_7 -> V_40 = F_55 ( 0 , & V_7 -> V_34 -> V_34 ) ;
return ( V_7 -> V_40 & 0x1 ) == 0 ;
}
static int F_56 ( struct V_6 * V_7 )
{
unsigned int V_41 ;
unsigned int V_42 ;
V_41 = ( unsigned int ) F_55 ( 0 , & V_7 -> V_34 -> V_34 ) ;
V_42 = ( unsigned int ) V_7 -> V_40 ;
if ( ( V_41 & 0x1 ) == 0 || F_57 ( V_41 , V_42 + 2 ) ) {
F_23 ( V_7 -> V_2 -> V_22 , V_7 -> V_4 , V_7 -> V_5 , L_14 ) ;
V_7 -> V_43 ++ ;
return 1 ;
}
return F_21 ( V_7 ) ;
}
static void F_58 ( struct V_1 * V_2 )
{
V_2 -> V_44 = V_45 ;
V_2 -> V_46 = V_45 + V_47 ;
}
static void F_59 ( struct V_1 * V_2 )
{
int V_5 ;
long V_48 ;
unsigned long V_35 ;
int V_49 ;
struct V_20 * V_50 = F_20 ( V_2 ) ;
F_60 ( & V_50 -> V_51 , V_35 ) ;
V_48 = V_45 - V_2 -> V_46 ;
if ( V_48 < V_52 || ! F_1 ( V_2 ) ) {
F_61 ( & V_50 -> V_51 , V_35 ) ;
return;
}
V_2 -> V_46 = V_45 + V_53 ;
V_49 = F_62 ( V_50 ) ;
F_61 ( & V_50 -> V_51 , V_35 ) ;
F_63 ( V_54 L_15 ,
V_2 -> V_22 ) ;
F_64 (rsp, rnp) {
F_60 ( & V_50 -> V_51 , V_35 ) ;
V_49 += F_62 ( V_50 ) ;
F_61 ( & V_50 -> V_51 , V_35 ) ;
if ( V_50 -> V_55 == 0 )
continue;
for ( V_5 = 0 ; V_5 <= V_50 -> V_56 - V_50 -> V_57 ; V_5 ++ )
if ( V_50 -> V_55 & ( 1UL << V_5 ) ) {
F_63 ( L_16 , V_50 -> V_57 + V_5 ) ;
V_49 ++ ;
}
}
F_63 ( L_17 ,
F_24 () , ( long ) ( V_45 - V_2 -> V_44 ) ) ;
if ( V_49 == 0 )
F_63 ( V_54 L_18 ) ;
else if ( ! F_65 () )
F_66 () ;
F_67 ( V_2 ) ;
F_14 ( V_2 , 0 ) ;
}
static void F_68 ( struct V_1 * V_2 )
{
unsigned long V_35 ;
struct V_20 * V_50 = F_20 ( V_2 ) ;
F_63 ( V_54 L_19 ,
V_2 -> V_22 , F_24 () , V_45 - V_2 -> V_44 ) ;
if ( ! F_65 () )
F_66 () ;
F_60 ( & V_50 -> V_51 , V_35 ) ;
if ( F_69 ( V_45 , V_2 -> V_46 ) )
V_2 -> V_46 =
V_45 + V_53 ;
F_61 ( & V_50 -> V_51 , V_35 ) ;
F_26 () ;
}
static void F_70 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
unsigned long V_58 ;
unsigned long V_59 ;
struct V_20 * V_50 ;
if ( V_60 )
return;
V_58 = F_2 ( V_45 ) ;
V_59 = F_2 ( V_2 -> V_46 ) ;
V_50 = V_7 -> V_61 ;
if ( ( F_2 ( V_50 -> V_55 ) & V_7 -> V_62 ) && F_69 ( V_58 , V_59 ) ) {
F_68 ( V_2 ) ;
} else if ( F_1 ( V_2 ) &&
F_69 ( V_58 , V_59 + V_52 ) ) {
F_59 ( V_2 ) ;
}
}
static int F_71 ( struct V_63 * V_64 , unsigned long V_65 , void * V_66 )
{
V_60 = 1 ;
return V_67 ;
}
void F_72 ( void )
{
V_12 . V_46 = V_45 + V_68 / 2 ;
V_13 . V_46 = V_45 + V_68 / 2 ;
F_73 () ;
}
static void T_1 F_74 ( void )
{
F_75 ( & V_69 , & V_70 ) ;
}
static void F_76 ( struct V_1 * V_2 , struct V_20 * V_50 , struct V_6 * V_7 )
{
if ( V_7 -> V_4 != V_50 -> V_4 ) {
V_7 -> V_4 = V_50 -> V_4 ;
F_6 ( V_2 -> V_22 , V_7 -> V_4 , L_20 ) ;
if ( V_50 -> V_55 & V_7 -> V_62 ) {
V_7 -> V_71 = 1 ;
V_7 -> V_10 = 0 ;
} else
V_7 -> V_71 = 0 ;
}
}
static void F_77 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
unsigned long V_35 ;
struct V_20 * V_50 ;
F_40 ( V_35 ) ;
V_50 = V_7 -> V_61 ;
if ( V_7 -> V_4 == F_2 ( V_50 -> V_4 ) ||
! F_78 ( & V_50 -> V_51 ) ) {
F_42 ( V_35 ) ;
return;
}
F_76 ( V_2 , V_50 , V_7 ) ;
F_61 ( & V_50 -> V_51 , V_35 ) ;
}
static int
F_79 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
unsigned long V_35 ;
int V_39 = 0 ;
F_40 ( V_35 ) ;
if ( V_7 -> V_4 != V_2 -> V_4 ) {
F_77 ( V_2 , V_7 ) ;
V_39 = 1 ;
}
F_42 ( V_35 ) ;
return V_39 ;
}
static void
F_80 ( struct V_1 * V_2 , struct V_20 * V_50 , struct V_6 * V_7 )
{
if ( V_7 -> V_3 != V_50 -> V_3 ) {
V_7 -> V_18 [ V_19 ] = V_7 -> V_18 [ V_72 ] ;
V_7 -> V_18 [ V_72 ] = V_7 -> V_18 [ V_73 ] ;
V_7 -> V_18 [ V_73 ] = V_7 -> V_18 [ V_74 ] ;
V_7 -> V_3 = V_50 -> V_3 ;
F_6 ( V_2 -> V_22 , V_7 -> V_4 , L_21 ) ;
if ( F_81 ( V_7 -> V_4 , V_7 -> V_3 ) )
V_7 -> V_4 = V_7 -> V_3 ;
if ( ( V_50 -> V_55 & V_7 -> V_62 ) == 0 )
V_7 -> V_71 = 0 ;
}
}
static void
F_82 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
unsigned long V_35 ;
struct V_20 * V_50 ;
F_40 ( V_35 ) ;
V_50 = V_7 -> V_61 ;
if ( V_7 -> V_3 == F_2 ( V_50 -> V_3 ) ||
! F_78 ( & V_50 -> V_51 ) ) {
F_42 ( V_35 ) ;
return;
}
F_80 ( V_2 , V_50 , V_7 ) ;
F_61 ( & V_50 -> V_51 , V_35 ) ;
}
static void
F_83 ( struct V_1 * V_2 , struct V_20 * V_50 , struct V_6 * V_7 )
{
F_80 ( V_2 , V_50 , V_7 ) ;
V_7 -> V_18 [ V_73 ] = V_7 -> V_18 [ V_74 ] ;
V_7 -> V_18 [ V_72 ] = V_7 -> V_18 [ V_74 ] ;
F_76 ( V_2 , V_50 , V_7 ) ;
}
static void
F_84 ( struct V_1 * V_2 , unsigned long V_35 )
__releases( rcu_get_root( V_2 )->lock
static void F_85 ( struct V_1 * V_2 , unsigned long V_35 )
__releases( rcu_get_root( V_2 )->lock
static void
F_86 ( unsigned long V_75 , struct V_1 * V_2 ,
struct V_20 * V_50 , unsigned long V_35 )
__releases( V_50 -> V_51 )
{
struct V_20 * V_76 ;
for (; ; ) {
if ( ! ( V_50 -> V_55 & V_75 ) ) {
F_61 ( & V_50 -> V_51 , V_35 ) ;
return;
}
V_50 -> V_55 &= ~ V_75 ;
F_87 ( V_2 -> V_22 , V_50 -> V_4 ,
V_75 , V_50 -> V_55 , V_50 -> V_77 ,
V_50 -> V_57 , V_50 -> V_56 ,
! ! V_50 -> V_78 ) ;
if ( V_50 -> V_55 != 0 || F_88 ( V_50 ) ) {
F_61 ( & V_50 -> V_51 , V_35 ) ;
return;
}
V_75 = V_50 -> V_62 ;
if ( V_50 -> V_79 == NULL ) {
break;
}
F_61 ( & V_50 -> V_51 , V_35 ) ;
V_76 = V_50 ;
V_50 = V_50 -> V_79 ;
F_60 ( & V_50 -> V_51 , V_35 ) ;
F_37 ( V_76 -> V_55 ) ;
}
F_85 ( V_2 , V_35 ) ;
}
static void
F_89 ( int V_5 , struct V_1 * V_2 , struct V_6 * V_7 , long V_80 )
{
unsigned long V_35 ;
unsigned long V_75 ;
struct V_20 * V_50 ;
V_50 = V_7 -> V_61 ;
F_60 ( & V_50 -> V_51 , V_35 ) ;
if ( V_80 != V_50 -> V_4 || V_50 -> V_3 == V_50 -> V_4 ) {
V_7 -> V_10 = 0 ;
F_61 ( & V_50 -> V_51 , V_35 ) ;
return;
}
V_75 = V_7 -> V_62 ;
if ( ( V_50 -> V_55 & V_75 ) == 0 ) {
F_61 ( & V_50 -> V_51 , V_35 ) ;
} else {
V_7 -> V_71 = 0 ;
V_7 -> V_18 [ V_73 ] = V_7 -> V_18 [ V_74 ] ;
F_86 ( V_75 , V_2 , V_50 , V_35 ) ;
}
}
static void
F_90 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
if ( F_79 ( V_2 , V_7 ) )
return;
if ( ! V_7 -> V_71 )
return;
if ( ! V_7 -> V_10 )
return;
F_89 ( V_7 -> V_5 , V_2 , V_7 , V_7 -> V_9 ) ;
}
static void F_91 ( struct V_1 * V_2 )
{
int V_81 ;
int V_82 = F_92 ( V_83 ) ;
struct V_6 * V_7 = F_93 ( V_2 -> V_84 ) ;
struct V_6 * V_85 = F_94 ( V_2 -> V_84 , V_82 ) ;
if ( V_7 -> V_17 == NULL )
return;
* V_85 -> V_18 [ V_74 ] = V_7 -> V_17 ;
V_85 -> V_18 [ V_74 ] = V_7 -> V_18 [ V_74 ] ;
V_85 -> V_86 += V_7 -> V_86 ;
V_85 -> V_87 += V_7 -> V_86 ;
V_7 -> V_88 += V_7 -> V_86 ;
V_7 -> V_17 = NULL ;
for ( V_81 = 0 ; V_81 < V_89 ; V_81 ++ )
V_7 -> V_18 [ V_81 ] = & V_7 -> V_17 ;
V_7 -> V_86 = 0 ;
}
static void F_95 ( int V_5 , struct V_1 * V_2 )
{
unsigned long V_35 ;
unsigned long V_75 ;
int V_90 = 0 ;
struct V_6 * V_7 = F_94 ( V_2 -> V_84 , V_5 ) ;
struct V_20 * V_50 ;
F_96 ( V_5 ) ;
F_60 ( & V_2 -> V_91 , V_35 ) ;
V_50 = V_7 -> V_61 ;
V_75 = V_7 -> V_62 ;
do {
F_97 ( & V_50 -> V_51 ) ;
V_50 -> V_92 &= ~ V_75 ;
if ( V_50 -> V_92 != 0 ) {
if ( V_50 != V_7 -> V_61 )
F_98 ( & V_50 -> V_51 ) ;
else
F_6 ( V_2 -> V_22 ,
V_50 -> V_4 + 1 -
! ! ( V_50 -> V_55 & V_75 ) ,
L_22 ) ;
break;
}
if ( V_50 == V_7 -> V_61 ) {
F_6 ( V_2 -> V_22 ,
V_50 -> V_4 + 1 -
! ! ( V_50 -> V_55 & V_75 ) ,
L_22 ) ;
V_90 = F_99 ( V_2 , V_50 , V_7 ) ;
} else
F_98 ( & V_50 -> V_51 ) ;
V_75 = V_50 -> V_62 ;
V_50 = V_50 -> V_79 ;
} while ( V_50 != NULL );
F_98 ( & V_2 -> V_91 ) ;
V_50 = V_7 -> V_61 ;
if ( V_90 & V_93 )
F_100 ( V_50 , V_35 ) ;
else
F_61 ( & V_50 -> V_51 , V_35 ) ;
if ( V_90 & V_94 )
F_101 ( V_2 , V_50 , true ) ;
F_102 ( V_50 , - 1 ) ;
}
static void F_103 ( int V_5 )
{
F_95 ( V_5 , & V_12 ) ;
F_95 ( V_5 , & V_13 ) ;
F_104 ( V_5 ) ;
}
static void F_91 ( struct V_1 * V_2 )
{
}
static void F_103 ( int V_5 )
{
}
static void F_105 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
unsigned long V_35 ;
struct V_95 * V_96 , * V_97 , * * V_98 ;
int V_99 , V_100 ;
if ( ! F_18 ( V_7 ) ) {
F_106 ( V_2 -> V_22 , 0 , 0 ) ;
F_107 ( V_2 -> V_22 , 0 , ! ! F_2 ( V_7 -> V_17 ) ,
F_108 () , F_29 ( V_28 ) ,
F_109 () ) ;
return;
}
F_40 ( V_35 ) ;
V_99 = V_7 -> V_101 ;
F_106 ( V_2 -> V_22 , V_7 -> V_86 , V_99 ) ;
V_97 = V_7 -> V_17 ;
V_7 -> V_17 = * V_7 -> V_18 [ V_19 ] ;
* V_7 -> V_18 [ V_19 ] = NULL ;
V_98 = V_7 -> V_18 [ V_19 ] ;
for ( V_100 = V_89 - 1 ; V_100 >= 0 ; V_100 -- )
if ( V_7 -> V_18 [ V_100 ] == V_7 -> V_18 [ V_19 ] )
V_7 -> V_18 [ V_100 ] = & V_7 -> V_17 ;
F_42 ( V_35 ) ;
V_100 = 0 ;
while ( V_97 ) {
V_96 = V_97 -> V_96 ;
F_110 ( V_96 ) ;
F_111 ( V_97 ) ;
F_112 ( V_2 -> V_22 , V_97 ) ;
V_97 = V_96 ;
if ( ++ V_100 >= V_99 &&
( F_108 () ||
( ! F_29 ( V_28 ) && ! F_109 () ) ) )
break;
}
F_40 ( V_35 ) ;
F_107 ( V_2 -> V_22 , V_100 , ! ! V_97 , F_108 () ,
F_29 ( V_28 ) ,
F_109 () ) ;
V_7 -> V_86 -= V_100 ;
V_7 -> V_102 += V_100 ;
if ( V_97 != NULL ) {
* V_98 = V_7 -> V_17 ;
V_7 -> V_17 = V_97 ;
for ( V_100 = 0 ; V_100 < V_89 ; V_100 ++ )
if ( & V_7 -> V_17 == V_7 -> V_18 [ V_100 ] )
V_7 -> V_18 [ V_100 ] = V_98 ;
else
break;
}
if ( V_7 -> V_101 == V_103 && V_7 -> V_86 <= V_104 )
V_7 -> V_101 = V_101 ;
if ( V_7 -> V_86 == 0 && V_7 -> V_105 != 0 ) {
V_7 -> V_105 = 0 ;
V_7 -> V_106 = V_2 -> V_107 ;
} else if ( V_7 -> V_86 < V_7 -> V_105 - V_108 )
V_7 -> V_105 = V_7 -> V_86 ;
F_42 ( V_35 ) ;
if ( F_18 ( V_7 ) )
F_113 () ;
}
void F_114 ( int V_5 , int V_109 )
{
F_9 ( L_23 ) ;
if ( V_109 || F_53 () ) {
F_3 ( V_5 ) ;
F_7 ( V_5 ) ;
} else if ( ! F_115 () ) {
F_7 ( V_5 ) ;
}
F_116 ( V_5 ) ;
if ( F_117 ( V_5 ) )
F_113 () ;
F_9 ( L_24 ) ;
}
static void F_118 ( struct V_1 * V_2 , int (* F_119)( struct V_6 * ) )
{
unsigned long V_110 ;
int V_5 ;
unsigned long V_35 ;
unsigned long V_75 ;
struct V_20 * V_50 ;
F_64 (rsp, rnp) {
V_75 = 0 ;
F_60 ( & V_50 -> V_51 , V_35 ) ;
if ( ! F_1 ( V_2 ) ) {
F_61 ( & V_50 -> V_51 , V_35 ) ;
return;
}
if ( V_50 -> V_55 == 0 ) {
F_120 ( V_50 , V_35 ) ;
continue;
}
V_5 = V_50 -> V_57 ;
V_110 = 1 ;
for (; V_5 <= V_50 -> V_56 ; V_5 ++ , V_110 <<= 1 ) {
if ( ( V_50 -> V_55 & V_110 ) != 0 &&
F_119 ( F_94 ( V_2 -> V_84 , V_5 ) ) )
V_75 |= V_110 ;
}
if ( V_75 != 0 ) {
F_86 ( V_75 , V_2 , V_50 , V_35 ) ;
continue;
}
F_61 ( & V_50 -> V_51 , V_35 ) ;
}
V_50 = F_20 ( V_2 ) ;
if ( V_50 -> V_55 == 0 ) {
F_60 ( & V_50 -> V_51 , V_35 ) ;
F_120 ( V_50 , V_35 ) ;
}
}
static void F_14 ( struct V_1 * V_2 , int V_111 )
{
unsigned long V_35 ;
struct V_20 * V_50 = F_20 ( V_2 ) ;
F_9 ( L_25 ) ;
if ( ! F_1 ( V_2 ) ) {
F_9 ( L_26 ) ;
return;
}
if ( ! F_121 ( & V_2 -> V_112 , V_35 ) ) {
V_2 -> V_113 ++ ;
F_9 ( L_26 ) ;
return;
}
if ( V_111 && F_69 ( V_2 -> V_114 , V_45 ) )
goto V_115;
V_2 -> V_107 ++ ;
F_97 ( & V_50 -> V_51 ) ;
V_2 -> V_114 = V_45 + V_116 ;
if( ! F_1 ( V_2 ) ) {
V_2 -> V_117 ++ ;
F_98 ( & V_50 -> V_51 ) ;
goto V_115;
}
V_2 -> V_118 = 1 ;
switch ( V_2 -> V_119 ) {
case V_120 :
case V_121 :
break;
case V_122 :
if ( V_123 != V_122 )
break;
F_98 ( & V_50 -> V_51 ) ;
F_118 ( V_2 , F_54 ) ;
F_97 ( & V_50 -> V_51 ) ;
if ( F_1 ( V_2 ) )
V_2 -> V_119 = V_124 ;
break;
case V_124 :
F_98 ( & V_50 -> V_51 ) ;
F_118 ( V_2 , F_56 ) ;
F_97 ( & V_50 -> V_51 ) ;
break;
}
V_2 -> V_118 = 0 ;
if ( V_2 -> V_125 ) {
F_98 ( & V_2 -> V_112 ) ;
V_2 -> V_125 = 0 ;
F_84 ( V_2 , V_35 ) ;
F_9 ( L_26 ) ;
return;
}
F_98 ( & V_50 -> V_51 ) ;
V_115:
F_61 ( & V_2 -> V_112 , V_35 ) ;
F_9 ( L_26 ) ;
}
static void F_14 ( struct V_1 * V_2 , int V_111 )
{
F_26 () ;
}
static void
F_122 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
unsigned long V_35 ;
F_37 ( V_7 -> V_126 == 0 ) ;
if ( F_81 ( F_2 ( V_2 -> V_114 ) , V_45 ) )
F_14 ( V_2 , 1 ) ;
F_82 ( V_2 , V_7 ) ;
F_90 ( V_2 , V_7 ) ;
if ( F_19 ( V_2 , V_7 ) ) {
F_60 ( & F_20 ( V_2 ) -> V_51 , V_35 ) ;
F_84 ( V_2 , V_35 ) ;
}
if ( F_18 ( V_7 ) )
F_123 ( V_2 , V_7 ) ;
}
static void F_124 ( struct V_127 * V_128 )
{
F_9 ( L_27 ) ;
F_122 ( & V_12 ,
& F_41 ( V_8 ) ) ;
F_122 ( & V_13 , & F_41 ( V_11 ) ) ;
F_125 () ;
F_9 ( L_28 ) ;
}
static void F_123 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
if ( F_126 ( ! F_2 ( V_129 ) ) )
return;
if ( F_127 ( ! V_2 -> V_130 ) ) {
F_105 ( V_2 , V_7 ) ;
return;
}
F_128 () ;
}
static void F_113 ( void )
{
F_129 ( V_131 ) ;
}
static void
F_130 ( struct V_95 * V_132 , void (* F_131)( struct V_95 * V_133 ) ,
struct V_1 * V_2 )
{
unsigned long V_35 ;
struct V_6 * V_7 ;
F_132 ( V_132 ) ;
V_132 -> F_131 = F_131 ;
V_132 -> V_96 = NULL ;
F_133 () ;
F_40 ( V_35 ) ;
V_7 = F_93 ( V_2 -> V_84 ) ;
* V_7 -> V_18 [ V_74 ] = V_132 ;
V_7 -> V_18 [ V_74 ] = & V_132 -> V_96 ;
V_7 -> V_86 ++ ;
if ( F_134 ( ( unsigned long ) F_131 ) )
F_135 ( V_2 -> V_22 , V_132 , ( unsigned long ) F_131 ,
V_7 -> V_86 ) ;
else
F_136 ( V_2 -> V_22 , V_132 , V_7 -> V_86 ) ;
if ( F_137 ( V_35 ) ) {
F_42 ( V_35 ) ;
return;
}
if ( F_126 ( V_7 -> V_86 > V_7 -> V_105 + V_108 ) ) {
F_82 ( V_2 , V_7 ) ;
F_79 ( V_2 , V_7 ) ;
if ( ! F_1 ( V_2 ) ) {
unsigned long V_134 ;
struct V_20 * V_135 = F_20 ( V_2 ) ;
F_60 ( & V_135 -> V_51 , V_134 ) ;
F_84 ( V_2 , V_134 ) ;
} else {
V_7 -> V_101 = V_103 ;
if ( V_2 -> V_107 == V_7 -> V_106 &&
* V_7 -> V_18 [ V_19 ] != V_132 )
F_14 ( V_2 , 0 ) ;
V_7 -> V_106 = V_2 -> V_107 ;
V_7 -> V_105 = V_7 -> V_86 ;
}
} else if ( F_81 ( F_2 ( V_2 -> V_114 ) , V_45 ) )
F_14 ( V_2 , 1 ) ;
F_42 ( V_35 ) ;
}
void F_138 ( struct V_95 * V_132 , void (* F_131)( struct V_95 * V_133 ) )
{
F_130 ( V_132 , F_131 , & V_12 ) ;
}
void F_139 ( struct V_95 * V_132 , void (* F_131)( struct V_95 * V_133 ) )
{
F_130 ( V_132 , F_131 , & V_13 ) ;
}
void F_140 ( void )
{
if ( F_141 () )
return;
F_142 ( F_138 ) ;
}
void F_143 ( void )
{
if ( F_141 () )
return;
F_142 ( F_139 ) ;
}
static int F_144 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
struct V_20 * V_50 = V_7 -> V_61 ;
V_7 -> V_136 ++ ;
F_70 ( V_2 , V_7 ) ;
if ( V_129 &&
V_7 -> V_71 && ! V_7 -> V_10 ) {
V_7 -> V_137 ++ ;
if ( ! V_7 -> V_138 &&
F_81 ( F_2 ( V_2 -> V_114 ) - 1 ,
V_45 ) )
F_26 () ;
} else if ( V_7 -> V_71 && V_7 -> V_10 ) {
V_7 -> V_139 ++ ;
return 1 ;
}
if ( F_18 ( V_7 ) ) {
V_7 -> V_140 ++ ;
return 1 ;
}
if ( F_19 ( V_2 , V_7 ) ) {
V_7 -> V_141 ++ ;
return 1 ;
}
if ( F_2 ( V_50 -> V_3 ) != V_7 -> V_3 ) {
V_7 -> V_142 ++ ;
return 1 ;
}
if ( F_2 ( V_50 -> V_4 ) != V_7 -> V_4 ) {
V_7 -> V_143 ++ ;
return 1 ;
}
if ( F_1 ( V_2 ) &&
F_81 ( F_2 ( V_2 -> V_114 ) , V_45 ) ) {
V_7 -> V_144 ++ ;
return 1 ;
}
V_7 -> V_145 ++ ;
return 0 ;
}
static int F_117 ( int V_5 )
{
return F_144 ( & V_12 , & F_4 ( V_8 , V_5 ) ) ||
F_144 ( & V_13 , & F_4 ( V_11 , V_5 ) ) ||
F_145 ( V_5 ) ;
}
static int F_146 ( int V_5 )
{
return F_4 ( V_8 , V_5 ) . V_17 ||
F_4 ( V_11 , V_5 ) . V_17 ||
F_147 ( V_5 ) ;
}
static void F_148 ( struct V_95 * V_146 )
{
if ( F_149 ( & V_147 ) )
F_150 ( & V_148 ) ;
}
static void F_151 ( void * type )
{
int V_5 = F_24 () ;
struct V_95 * V_132 = & F_4 ( V_149 , V_5 ) ;
void (* F_152)( struct V_95 * V_132 ,
void (* F_131)( struct V_95 * V_132 ) );
F_35 ( & V_147 ) ;
F_152 = type ;
F_152 ( V_132 , F_148 ) ;
}
static void F_153 ( struct V_1 * V_2 ,
void (* F_152)( struct V_95 * V_132 ,
void (* F_131)( struct V_95 * V_132 ) ) )
{
F_154 ( F_155 () ) ;
F_156 ( & V_150 ) ;
F_157 ( & V_148 ) ;
F_158 ( & V_147 , 1 ) ;
F_159 ( F_151 , ( void * ) F_152 , 1 ) ;
if ( F_149 ( & V_147 ) )
F_150 ( & V_148 ) ;
F_160 ( & V_148 ) ;
F_161 ( & V_150 ) ;
}
void F_162 ( void )
{
F_153 ( & V_13 , F_139 ) ;
}
void F_163 ( void )
{
F_153 ( & V_12 , F_138 ) ;
}
static void T_1
F_164 ( int V_5 , struct V_1 * V_2 )
{
unsigned long V_35 ;
int V_81 ;
struct V_6 * V_7 = F_94 ( V_2 -> V_84 , V_5 ) ;
struct V_20 * V_50 = F_20 ( V_2 ) ;
F_60 ( & V_50 -> V_51 , V_35 ) ;
V_7 -> V_62 = 1UL << ( V_5 - V_7 -> V_61 -> V_57 ) ;
V_7 -> V_17 = NULL ;
for ( V_81 = 0 ; V_81 < V_89 ; V_81 ++ )
V_7 -> V_18 [ V_81 ] = & V_7 -> V_17 ;
V_7 -> V_86 = 0 ;
V_7 -> V_34 = & F_4 ( V_25 , V_5 ) ;
F_37 ( V_7 -> V_34 -> V_36 != V_37 ) ;
F_37 ( F_38 ( & V_7 -> V_34 -> V_34 ) != 1 ) ;
V_7 -> V_5 = V_5 ;
V_7 -> V_2 = V_2 ;
F_61 ( & V_50 -> V_51 , V_35 ) ;
}
static void T_2
F_165 ( int V_5 , struct V_1 * V_2 , int V_138 )
{
unsigned long V_35 ;
unsigned long V_75 ;
struct V_6 * V_7 = F_94 ( V_2 -> V_84 , V_5 ) ;
struct V_20 * V_50 = F_20 ( V_2 ) ;
F_60 ( & V_50 -> V_51 , V_35 ) ;
V_7 -> V_126 = 1 ;
V_7 -> V_138 = V_138 ;
V_7 -> V_105 = 0 ;
V_7 -> V_106 = V_2 -> V_107 ;
V_7 -> V_101 = V_101 ;
V_7 -> V_34 -> V_36 = V_37 ;
F_158 ( & V_7 -> V_34 -> V_34 ,
( F_38 ( & V_7 -> V_34 -> V_34 ) & ~ 0x1 ) + 1 ) ;
F_166 ( V_5 ) ;
F_98 ( & V_50 -> V_51 ) ;
F_97 ( & V_2 -> V_91 ) ;
V_50 = V_7 -> V_61 ;
V_75 = V_7 -> V_62 ;
do {
F_97 ( & V_50 -> V_51 ) ;
V_50 -> V_92 |= V_75 ;
V_75 = V_50 -> V_62 ;
if ( V_50 == V_7 -> V_61 ) {
V_7 -> V_4 = V_50 -> V_3 ;
V_7 -> V_3 = V_50 -> V_3 ;
V_7 -> V_10 = 0 ;
V_7 -> V_71 = 0 ;
V_7 -> V_9 = V_50 -> V_4 - 1 ;
F_6 ( V_2 -> V_22 , V_7 -> V_4 , L_29 ) ;
}
F_98 ( & V_50 -> V_51 ) ;
V_50 = V_50 -> V_79 ;
} while ( V_50 != NULL && ! ( V_50 -> V_92 & V_75 ) );
F_61 ( & V_2 -> V_91 , V_35 ) ;
}
static void T_2 F_167 ( int V_5 )
{
F_165 ( V_5 , & V_12 , 0 ) ;
F_165 ( V_5 , & V_13 , 0 ) ;
F_168 ( V_5 ) ;
}
static int T_2 F_169 ( struct V_63 * V_151 ,
unsigned long V_152 , void * V_153 )
{
long V_5 = ( long ) V_153 ;
struct V_6 * V_7 = F_94 ( V_1 -> V_84 , V_5 ) ;
struct V_20 * V_50 = V_7 -> V_61 ;
F_9 ( L_30 ) ;
switch ( V_152 ) {
case V_154 :
case V_155 :
F_167 ( V_5 ) ;
F_170 ( V_5 ) ;
break;
case V_156 :
case V_157 :
F_102 ( V_50 , - 1 ) ;
F_171 ( V_5 , 1 ) ;
break;
case V_158 :
F_102 ( V_50 , V_5 ) ;
F_171 ( V_5 , 0 ) ;
break;
case V_159 :
case V_160 :
F_91 ( & V_13 ) ;
F_91 ( & V_12 ) ;
F_172 () ;
F_45 ( V_5 ) ;
break;
case V_161 :
case V_162 :
case V_163 :
case V_164 :
F_103 ( V_5 ) ;
break;
default:
break;
}
F_9 ( L_31 ) ;
return V_165 ;
}
void F_173 ( void )
{
F_174 ( F_175 () != 1 ) ;
F_174 ( F_176 () > 0 ) ;
V_166 = 1 ;
}
static void T_1 F_177 ( struct V_1 * V_2 )
{
int V_81 ;
for ( V_81 = V_167 - 1 ; V_81 > 0 ; V_81 -- )
V_2 -> V_168 [ V_81 ] = V_169 ;
V_2 -> V_168 [ 0 ] = V_170 ;
}
static void T_1 F_177 ( struct V_1 * V_2 )
{
int V_171 ;
int V_172 ;
int V_81 ;
V_172 = V_173 ;
for ( V_81 = V_167 - 1 ; V_81 >= 0 ; V_81 -- ) {
V_171 = V_2 -> V_174 [ V_81 ] ;
V_2 -> V_168 [ V_81 ] = ( V_172 + V_171 - 1 ) / V_171 ;
V_172 = V_171 ;
}
}
static void T_1 F_178 ( struct V_1 * V_2 ,
struct V_6 T_3 * V_84 )
{
static char * V_175 [] = { L_32 ,
L_33 ,
L_34 ,
L_35 } ;
int V_176 = 1 ;
int V_81 ;
int V_58 ;
struct V_20 * V_50 ;
F_179 ( V_177 > F_180 ( V_175 ) ) ;
for ( V_81 = 1 ; V_81 < V_167 ; V_81 ++ )
V_2 -> V_77 [ V_81 ] = V_2 -> V_77 [ V_81 - 1 ] + V_2 -> V_174 [ V_81 - 1 ] ;
F_177 ( V_2 ) ;
for ( V_81 = V_167 - 1 ; V_81 >= 0 ; V_81 -- ) {
V_176 *= V_2 -> V_168 [ V_81 ] ;
V_50 = V_2 -> V_77 [ V_81 ] ;
for ( V_58 = 0 ; V_58 < V_2 -> V_174 [ V_81 ] ; V_58 ++ , V_50 ++ ) {
F_181 ( & V_50 -> V_51 ) ;
F_182 ( & V_50 -> V_51 ,
& V_178 [ V_81 ] , V_175 [ V_81 ] ) ;
V_50 -> V_4 = 0 ;
V_50 -> V_55 = 0 ;
V_50 -> V_92 = 0 ;
V_50 -> V_57 = V_58 * V_176 ;
V_50 -> V_56 = ( V_58 + 1 ) * V_176 - 1 ;
if ( V_50 -> V_56 >= V_173 )
V_50 -> V_56 = V_173 - 1 ;
if ( V_81 == 0 ) {
V_50 -> V_179 = 0 ;
V_50 -> V_62 = 0 ;
V_50 -> V_79 = NULL ;
} else {
V_50 -> V_179 = V_58 % V_2 -> V_168 [ V_81 - 1 ] ;
V_50 -> V_62 = 1UL << V_50 -> V_179 ;
V_50 -> V_79 = V_2 -> V_77 [ V_81 - 1 ] +
V_58 / V_2 -> V_168 [ V_81 - 1 ] ;
}
V_50 -> V_77 = V_81 ;
F_183 ( & V_50 -> V_180 ) ;
}
}
V_2 -> V_84 = V_84 ;
V_50 = V_2 -> V_77 [ V_167 - 1 ] ;
F_184 (i) {
while ( V_81 > V_50 -> V_56 )
V_50 ++ ;
F_94 ( V_2 -> V_84 , V_81 ) -> V_61 = V_50 ;
F_164 ( V_81 , V_2 ) ;
}
}
void T_1 F_185 ( void )
{
int V_5 ;
F_186 () ;
F_178 ( & V_12 , & V_8 ) ;
F_178 ( & V_13 , & V_11 ) ;
F_187 () ;
F_188 ( V_131 , F_124 ) ;
F_189 ( F_169 , 0 ) ;
F_190 (cpu)
F_169 ( NULL , V_154 , ( void * ) ( long ) V_5 ) ;
F_74 () ;
}
