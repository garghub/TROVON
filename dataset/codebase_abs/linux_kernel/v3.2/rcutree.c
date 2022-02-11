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
if ( V_7 -> V_24 )
return 0 ;
if ( V_7 -> V_5 != F_24 () )
F_25 ( V_7 -> V_5 ) ;
else
F_26 () ;
V_7 -> V_25 ++ ;
return 0 ;
}
void F_27 ( void )
{
unsigned long V_26 ;
struct V_27 * V_28 ;
F_28 ( V_26 ) ;
V_28 = & F_29 ( V_27 ) ;
if ( -- V_28 -> V_29 ) {
F_30 ( V_26 ) ;
return;
}
F_31 ( L_7 ) ;
F_32 () ;
F_33 ( & V_28 -> V_30 ) ;
F_34 () ;
F_35 ( F_36 ( & V_28 -> V_30 ) & 0x1 ) ;
F_30 ( V_26 ) ;
}
void F_37 ( void )
{
unsigned long V_26 ;
struct V_27 * V_28 ;
F_28 ( V_26 ) ;
V_28 = & F_29 ( V_27 ) ;
if ( V_28 -> V_29 ++ ) {
F_30 ( V_26 ) ;
return;
}
F_32 () ;
F_33 ( & V_28 -> V_30 ) ;
F_34 () ;
F_35 ( ! ( F_36 ( & V_28 -> V_30 ) & 0x1 ) ) ;
F_31 ( L_8 ) ;
F_30 ( V_26 ) ;
}
void F_38 ( void )
{
struct V_27 * V_28 = & F_29 ( V_27 ) ;
if ( V_28 -> V_31 == 0 &&
( F_36 ( & V_28 -> V_30 ) & 0x1 ) )
return;
V_28 -> V_31 ++ ;
F_32 () ;
F_33 ( & V_28 -> V_30 ) ;
F_34 () ;
F_35 ( ! ( F_36 ( & V_28 -> V_30 ) & 0x1 ) ) ;
}
void F_39 ( void )
{
struct V_27 * V_28 = & F_29 ( V_27 ) ;
if ( V_28 -> V_31 == 0 ||
-- V_28 -> V_31 != 0 )
return;
F_32 () ;
F_33 ( & V_28 -> V_30 ) ;
F_34 () ;
F_35 ( F_36 ( & V_28 -> V_30 ) & 0x1 ) ;
}
void F_40 ( void )
{
F_37 () ;
}
void F_41 ( void )
{
F_27 () ;
}
static int F_42 ( struct V_6 * V_7 )
{
V_7 -> V_32 = F_43 ( 0 , & V_7 -> V_30 -> V_30 ) ;
return 0 ;
}
static int F_44 ( struct V_6 * V_7 )
{
unsigned int V_33 ;
unsigned int V_34 ;
V_33 = ( unsigned int ) F_43 ( 0 , & V_7 -> V_30 -> V_30 ) ;
V_34 = ( unsigned int ) V_7 -> V_32 ;
if ( ( V_33 & 0x1 ) == 0 || F_45 ( V_33 , V_34 + 2 ) ) {
F_23 ( V_7 -> V_2 -> V_22 , V_7 -> V_4 , V_7 -> V_5 , L_9 ) ;
V_7 -> V_35 ++ ;
return 1 ;
}
return F_21 ( V_7 ) ;
}
static int F_42 ( struct V_6 * V_7 )
{
return 0 ;
}
static int F_44 ( struct V_6 * V_7 )
{
return F_21 ( V_7 ) ;
}
static void F_46 ( struct V_1 * V_2 )
{
V_2 -> V_36 = V_37 ;
V_2 -> V_38 = V_37 + V_39 ;
}
static void F_47 ( struct V_1 * V_2 )
{
int V_5 ;
long V_40 ;
unsigned long V_26 ;
int V_41 ;
struct V_20 * V_42 = F_20 ( V_2 ) ;
F_48 ( & V_42 -> V_43 , V_26 ) ;
V_40 = V_37 - V_2 -> V_38 ;
if ( V_40 < V_44 || ! F_1 ( V_2 ) ) {
F_49 ( & V_42 -> V_43 , V_26 ) ;
return;
}
V_2 -> V_38 = V_37 + V_45 ;
V_41 = F_50 ( V_42 ) ;
F_49 ( & V_42 -> V_43 , V_26 ) ;
F_51 ( V_46 L_10 ,
V_2 -> V_22 ) ;
F_52 (rsp, rnp) {
F_48 ( & V_42 -> V_43 , V_26 ) ;
V_41 += F_50 ( V_42 ) ;
F_49 ( & V_42 -> V_43 , V_26 ) ;
if ( V_42 -> V_47 == 0 )
continue;
for ( V_5 = 0 ; V_5 <= V_42 -> V_48 - V_42 -> V_49 ; V_5 ++ )
if ( V_42 -> V_47 & ( 1UL << V_5 ) ) {
F_51 ( L_11 , V_42 -> V_49 + V_5 ) ;
V_41 ++ ;
}
}
F_51 ( L_12 ,
F_24 () , ( long ) ( V_37 - V_2 -> V_36 ) ) ;
if ( V_41 == 0 )
F_51 ( V_46 L_13 ) ;
else if ( ! F_53 () )
F_54 () ;
F_55 ( V_2 ) ;
F_14 ( V_2 , 0 ) ;
}
static void F_56 ( struct V_1 * V_2 )
{
unsigned long V_26 ;
struct V_20 * V_42 = F_20 ( V_2 ) ;
F_51 ( V_46 L_14 ,
V_2 -> V_22 , F_24 () , V_37 - V_2 -> V_36 ) ;
if ( ! F_53 () )
F_54 () ;
F_48 ( & V_42 -> V_43 , V_26 ) ;
if ( F_57 ( V_37 , V_2 -> V_38 ) )
V_2 -> V_38 =
V_37 + V_45 ;
F_49 ( & V_42 -> V_43 , V_26 ) ;
F_26 () ;
}
static void F_58 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
unsigned long V_50 ;
unsigned long V_51 ;
struct V_20 * V_42 ;
if ( V_52 )
return;
V_50 = F_2 ( V_37 ) ;
V_51 = F_2 ( V_2 -> V_38 ) ;
V_42 = V_7 -> V_53 ;
if ( ( F_2 ( V_42 -> V_47 ) & V_7 -> V_54 ) && F_57 ( V_50 , V_51 ) ) {
F_56 ( V_2 ) ;
} else if ( F_1 ( V_2 ) &&
F_57 ( V_50 , V_51 + V_44 ) ) {
F_47 ( V_2 ) ;
}
}
static int F_59 ( struct V_55 * V_56 , unsigned long V_57 , void * V_58 )
{
V_52 = 1 ;
return V_59 ;
}
void F_60 ( void )
{
V_12 . V_38 = V_37 + V_60 / 2 ;
V_13 . V_38 = V_37 + V_60 / 2 ;
F_61 () ;
}
static void T_1 F_62 ( void )
{
F_63 ( & V_61 , & V_62 ) ;
}
static void F_64 ( struct V_1 * V_2 , struct V_20 * V_42 , struct V_6 * V_7 )
{
if ( V_7 -> V_4 != V_42 -> V_4 ) {
V_7 -> V_4 = V_42 -> V_4 ;
F_6 ( V_2 -> V_22 , V_7 -> V_4 , L_15 ) ;
if ( V_42 -> V_47 & V_7 -> V_54 ) {
V_7 -> V_63 = 1 ;
V_7 -> V_10 = 0 ;
} else
V_7 -> V_63 = 0 ;
}
}
static void F_65 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
unsigned long V_26 ;
struct V_20 * V_42 ;
F_28 ( V_26 ) ;
V_42 = V_7 -> V_53 ;
if ( V_7 -> V_4 == F_2 ( V_42 -> V_4 ) ||
! F_66 ( & V_42 -> V_43 ) ) {
F_30 ( V_26 ) ;
return;
}
F_64 ( V_2 , V_42 , V_7 ) ;
F_49 ( & V_42 -> V_43 , V_26 ) ;
}
static int
F_67 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
unsigned long V_26 ;
int V_64 = 0 ;
F_28 ( V_26 ) ;
if ( V_7 -> V_4 != V_2 -> V_4 ) {
F_65 ( V_2 , V_7 ) ;
V_64 = 1 ;
}
F_30 ( V_26 ) ;
return V_64 ;
}
static void
F_68 ( struct V_1 * V_2 , struct V_20 * V_42 , struct V_6 * V_7 )
{
if ( V_7 -> V_3 != V_42 -> V_3 ) {
V_7 -> V_18 [ V_19 ] = V_7 -> V_18 [ V_65 ] ;
V_7 -> V_18 [ V_65 ] = V_7 -> V_18 [ V_66 ] ;
V_7 -> V_18 [ V_66 ] = V_7 -> V_18 [ V_67 ] ;
V_7 -> V_3 = V_42 -> V_3 ;
F_6 ( V_2 -> V_22 , V_7 -> V_4 , L_16 ) ;
if ( F_69 ( V_7 -> V_4 , V_7 -> V_3 ) )
V_7 -> V_4 = V_7 -> V_3 ;
if ( ( V_42 -> V_47 & V_7 -> V_54 ) == 0 )
V_7 -> V_63 = 0 ;
}
}
static void
F_70 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
unsigned long V_26 ;
struct V_20 * V_42 ;
F_28 ( V_26 ) ;
V_42 = V_7 -> V_53 ;
if ( V_7 -> V_3 == F_2 ( V_42 -> V_3 ) ||
! F_66 ( & V_42 -> V_43 ) ) {
F_30 ( V_26 ) ;
return;
}
F_68 ( V_2 , V_42 , V_7 ) ;
F_49 ( & V_42 -> V_43 , V_26 ) ;
}
static void
F_71 ( struct V_1 * V_2 , struct V_20 * V_42 , struct V_6 * V_7 )
{
F_68 ( V_2 , V_42 , V_7 ) ;
V_7 -> V_18 [ V_66 ] = V_7 -> V_18 [ V_67 ] ;
V_7 -> V_18 [ V_65 ] = V_7 -> V_18 [ V_67 ] ;
F_64 ( V_2 , V_42 , V_7 ) ;
}
static void
F_72 ( struct V_1 * V_2 , unsigned long V_26 )
__releases( rcu_get_root( V_2 )->lock
static void F_73 ( struct V_1 * V_2 , unsigned long V_26 )
__releases( rcu_get_root( V_2 )->lock
static void
F_74 ( unsigned long V_68 , struct V_1 * V_2 ,
struct V_20 * V_42 , unsigned long V_26 )
__releases( V_42 -> V_43 )
{
struct V_20 * V_69 ;
for (; ; ) {
if ( ! ( V_42 -> V_47 & V_68 ) ) {
F_49 ( & V_42 -> V_43 , V_26 ) ;
return;
}
V_42 -> V_47 &= ~ V_68 ;
F_75 ( V_2 -> V_22 , V_42 -> V_4 ,
V_68 , V_42 -> V_47 , V_42 -> V_70 ,
V_42 -> V_49 , V_42 -> V_48 ,
! ! V_42 -> V_71 ) ;
if ( V_42 -> V_47 != 0 || F_76 ( V_42 ) ) {
F_49 ( & V_42 -> V_43 , V_26 ) ;
return;
}
V_68 = V_42 -> V_54 ;
if ( V_42 -> V_72 == NULL ) {
break;
}
F_49 ( & V_42 -> V_43 , V_26 ) ;
V_69 = V_42 ;
V_42 = V_42 -> V_72 ;
F_48 ( & V_42 -> V_43 , V_26 ) ;
F_35 ( V_69 -> V_47 ) ;
}
F_73 ( V_2 , V_26 ) ;
}
static void
F_77 ( int V_5 , struct V_1 * V_2 , struct V_6 * V_7 , long V_73 )
{
unsigned long V_26 ;
unsigned long V_68 ;
struct V_20 * V_42 ;
V_42 = V_7 -> V_53 ;
F_48 ( & V_42 -> V_43 , V_26 ) ;
if ( V_73 != V_42 -> V_4 || V_42 -> V_3 == V_42 -> V_4 ) {
V_7 -> V_10 = 0 ;
F_49 ( & V_42 -> V_43 , V_26 ) ;
return;
}
V_68 = V_7 -> V_54 ;
if ( ( V_42 -> V_47 & V_68 ) == 0 ) {
F_49 ( & V_42 -> V_43 , V_26 ) ;
} else {
V_7 -> V_63 = 0 ;
V_7 -> V_18 [ V_66 ] = V_7 -> V_18 [ V_67 ] ;
F_74 ( V_68 , V_2 , V_42 , V_26 ) ;
}
}
static void
F_78 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
if ( F_67 ( V_2 , V_7 ) )
return;
if ( ! V_7 -> V_63 )
return;
if ( ! V_7 -> V_10 )
return;
F_77 ( V_7 -> V_5 , V_2 , V_7 , V_7 -> V_9 ) ;
}
static void F_79 ( struct V_1 * V_2 )
{
int V_74 ;
int V_75 = F_80 ( V_76 ) ;
struct V_6 * V_7 = F_81 ( V_2 -> V_77 ) ;
struct V_6 * V_78 = F_82 ( V_2 -> V_77 , V_75 ) ;
if ( V_7 -> V_17 == NULL )
return;
* V_78 -> V_18 [ V_67 ] = V_7 -> V_17 ;
V_78 -> V_18 [ V_67 ] = V_7 -> V_18 [ V_67 ] ;
V_78 -> V_79 += V_7 -> V_79 ;
V_78 -> V_80 += V_7 -> V_79 ;
V_7 -> V_81 += V_7 -> V_79 ;
V_7 -> V_17 = NULL ;
for ( V_74 = 0 ; V_74 < V_82 ; V_74 ++ )
V_7 -> V_18 [ V_74 ] = & V_7 -> V_17 ;
V_7 -> V_79 = 0 ;
}
static void F_83 ( int V_5 , struct V_1 * V_2 )
{
unsigned long V_26 ;
unsigned long V_68 ;
int V_83 = 0 ;
struct V_6 * V_7 = F_82 ( V_2 -> V_77 , V_5 ) ;
struct V_20 * V_42 ;
F_84 ( V_5 ) ;
F_48 ( & V_2 -> V_84 , V_26 ) ;
V_42 = V_7 -> V_53 ;
V_68 = V_7 -> V_54 ;
do {
F_85 ( & V_42 -> V_43 ) ;
V_42 -> V_85 &= ~ V_68 ;
if ( V_42 -> V_85 != 0 ) {
if ( V_42 != V_7 -> V_53 )
F_86 ( & V_42 -> V_43 ) ;
else
F_6 ( V_2 -> V_22 ,
V_42 -> V_4 + 1 -
! ! ( V_42 -> V_47 & V_68 ) ,
L_17 ) ;
break;
}
if ( V_42 == V_7 -> V_53 ) {
F_6 ( V_2 -> V_22 ,
V_42 -> V_4 + 1 -
! ! ( V_42 -> V_47 & V_68 ) ,
L_17 ) ;
V_83 = F_87 ( V_2 , V_42 , V_7 ) ;
} else
F_86 ( & V_42 -> V_43 ) ;
V_68 = V_42 -> V_54 ;
V_42 = V_42 -> V_72 ;
} while ( V_42 != NULL );
F_86 ( & V_2 -> V_84 ) ;
V_42 = V_7 -> V_53 ;
if ( V_83 & V_86 )
F_88 ( V_42 , V_26 ) ;
else
F_49 ( & V_42 -> V_43 , V_26 ) ;
if ( V_83 & V_87 )
F_89 ( V_2 , V_42 ) ;
F_90 ( V_42 , - 1 ) ;
}
static void F_91 ( int V_5 )
{
F_83 ( V_5 , & V_12 ) ;
F_83 ( V_5 , & V_13 ) ;
F_92 ( V_5 ) ;
}
static void F_79 ( struct V_1 * V_2 )
{
}
static void F_91 ( int V_5 )
{
}
static void F_93 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
unsigned long V_26 ;
struct V_88 * V_89 , * V_90 , * * V_91 ;
int V_92 , V_93 ;
if ( ! F_18 ( V_7 ) ) {
F_94 ( V_2 -> V_22 , 0 , 0 ) ;
F_95 ( V_2 -> V_22 , 0 ) ;
return;
}
F_28 ( V_26 ) ;
V_92 = V_7 -> V_94 ;
F_94 ( V_2 -> V_22 , V_7 -> V_79 , V_92 ) ;
V_90 = V_7 -> V_17 ;
V_7 -> V_17 = * V_7 -> V_18 [ V_19 ] ;
* V_7 -> V_18 [ V_19 ] = NULL ;
V_91 = V_7 -> V_18 [ V_19 ] ;
for ( V_93 = V_82 - 1 ; V_93 >= 0 ; V_93 -- )
if ( V_7 -> V_18 [ V_93 ] == V_7 -> V_18 [ V_19 ] )
V_7 -> V_18 [ V_93 ] = & V_7 -> V_17 ;
F_30 ( V_26 ) ;
V_93 = 0 ;
while ( V_90 ) {
V_89 = V_90 -> V_89 ;
F_96 ( V_89 ) ;
F_97 ( V_90 ) ;
F_98 ( V_2 -> V_22 , V_90 ) ;
V_90 = V_89 ;
if ( ++ V_93 >= V_92 )
break;
}
F_28 ( V_26 ) ;
F_95 ( V_2 -> V_22 , V_93 ) ;
V_7 -> V_79 -= V_93 ;
V_7 -> V_95 += V_93 ;
if ( V_90 != NULL ) {
* V_91 = V_7 -> V_17 ;
V_7 -> V_17 = V_90 ;
for ( V_93 = 0 ; V_93 < V_82 ; V_93 ++ )
if ( & V_7 -> V_17 == V_7 -> V_18 [ V_93 ] )
V_7 -> V_18 [ V_93 ] = V_91 ;
else
break;
}
if ( V_7 -> V_94 == V_96 && V_7 -> V_79 <= V_97 )
V_7 -> V_94 = V_94 ;
if ( V_7 -> V_79 == 0 && V_7 -> V_98 != 0 ) {
V_7 -> V_98 = 0 ;
V_7 -> V_99 = V_2 -> V_100 ;
} else if ( V_7 -> V_79 < V_7 -> V_98 - V_101 )
V_7 -> V_98 = V_7 -> V_79 ;
F_30 ( V_26 ) ;
if ( F_18 ( V_7 ) )
F_99 () ;
}
void F_100 ( int V_5 , int V_102 )
{
F_9 ( L_18 ) ;
if ( V_102 ||
( F_101 ( V_5 ) && V_103 &&
! F_102 () && F_103 () <= ( 1 << V_104 ) ) ) {
F_3 ( V_5 ) ;
F_7 ( V_5 ) ;
} else if ( ! F_102 () ) {
F_7 ( V_5 ) ;
}
F_104 ( V_5 ) ;
if ( F_105 ( V_5 ) )
F_99 () ;
F_9 ( L_19 ) ;
}
static void F_106 ( struct V_1 * V_2 , int (* F_107)( struct V_6 * ) )
{
unsigned long V_105 ;
int V_5 ;
unsigned long V_26 ;
unsigned long V_68 ;
struct V_20 * V_42 ;
F_52 (rsp, rnp) {
V_68 = 0 ;
F_48 ( & V_42 -> V_43 , V_26 ) ;
if ( ! F_1 ( V_2 ) ) {
F_49 ( & V_42 -> V_43 , V_26 ) ;
return;
}
if ( V_42 -> V_47 == 0 ) {
F_108 ( V_42 , V_26 ) ;
continue;
}
V_5 = V_42 -> V_49 ;
V_105 = 1 ;
for (; V_5 <= V_42 -> V_48 ; V_5 ++ , V_105 <<= 1 ) {
if ( ( V_42 -> V_47 & V_105 ) != 0 &&
F_107 ( F_82 ( V_2 -> V_77 , V_5 ) ) )
V_68 |= V_105 ;
}
if ( V_68 != 0 ) {
F_74 ( V_68 , V_2 , V_42 , V_26 ) ;
continue;
}
F_49 ( & V_42 -> V_43 , V_26 ) ;
}
V_42 = F_20 ( V_2 ) ;
if ( V_42 -> V_47 == 0 ) {
F_48 ( & V_42 -> V_43 , V_26 ) ;
F_108 ( V_42 , V_26 ) ;
}
}
static void F_14 ( struct V_1 * V_2 , int V_106 )
{
unsigned long V_26 ;
struct V_20 * V_42 = F_20 ( V_2 ) ;
F_9 ( L_20 ) ;
if ( ! F_1 ( V_2 ) ) {
F_9 ( L_21 ) ;
return;
}
if ( ! F_109 ( & V_2 -> V_107 , V_26 ) ) {
V_2 -> V_108 ++ ;
F_9 ( L_21 ) ;
return;
}
if ( V_106 && F_57 ( V_2 -> V_109 , V_37 ) )
goto V_110;
V_2 -> V_100 ++ ;
F_85 ( & V_42 -> V_43 ) ;
V_2 -> V_109 = V_37 + V_111 ;
if( ! F_1 ( V_2 ) ) {
V_2 -> V_112 ++ ;
F_86 ( & V_42 -> V_43 ) ;
goto V_110;
}
V_2 -> V_113 = 1 ;
switch ( V_2 -> V_114 ) {
case V_115 :
case V_116 :
break;
case V_117 :
if ( V_118 != V_117 )
break;
F_86 ( & V_42 -> V_43 ) ;
F_106 ( V_2 , F_42 ) ;
F_85 ( & V_42 -> V_43 ) ;
if ( F_1 ( V_2 ) )
V_2 -> V_114 = V_119 ;
break;
case V_119 :
F_86 ( & V_42 -> V_43 ) ;
F_106 ( V_2 , F_44 ) ;
F_85 ( & V_42 -> V_43 ) ;
break;
}
V_2 -> V_113 = 0 ;
if ( V_2 -> V_120 ) {
F_86 ( & V_2 -> V_107 ) ;
V_2 -> V_120 = 0 ;
F_72 ( V_2 , V_26 ) ;
F_9 ( L_21 ) ;
return;
}
F_86 ( & V_42 -> V_43 ) ;
V_110:
F_49 ( & V_2 -> V_107 , V_26 ) ;
F_9 ( L_21 ) ;
}
static void F_14 ( struct V_1 * V_2 , int V_106 )
{
F_26 () ;
}
static void
F_110 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
unsigned long V_26 ;
F_35 ( V_7 -> V_121 == 0 ) ;
if ( F_69 ( F_2 ( V_2 -> V_109 ) , V_37 ) )
F_14 ( V_2 , 1 ) ;
F_70 ( V_2 , V_7 ) ;
F_78 ( V_2 , V_7 ) ;
if ( F_19 ( V_2 , V_7 ) ) {
F_48 ( & F_20 ( V_2 ) -> V_43 , V_26 ) ;
F_72 ( V_2 , V_26 ) ;
}
if ( F_18 ( V_7 ) )
F_111 ( V_2 , V_7 ) ;
}
static void F_112 ( struct V_122 * V_123 )
{
F_9 ( L_22 ) ;
F_110 ( & V_12 ,
& F_29 ( V_8 ) ) ;
F_110 ( & V_13 , & F_29 ( V_11 ) ) ;
F_113 () ;
F_9 ( L_23 ) ;
}
static void F_111 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
if ( F_114 ( ! F_2 ( V_124 ) ) )
return;
if ( F_115 ( ! V_2 -> V_125 ) ) {
F_93 ( V_2 , V_7 ) ;
return;
}
F_116 () ;
}
static void F_99 ( void )
{
F_117 ( V_126 ) ;
}
static void
F_118 ( struct V_88 * V_127 , void (* F_119)( struct V_88 * V_128 ) ,
struct V_1 * V_2 )
{
unsigned long V_26 ;
struct V_6 * V_7 ;
F_120 ( V_127 ) ;
V_127 -> F_119 = F_119 ;
V_127 -> V_89 = NULL ;
F_121 () ;
F_28 ( V_26 ) ;
V_7 = F_81 ( V_2 -> V_77 ) ;
* V_7 -> V_18 [ V_67 ] = V_127 ;
V_7 -> V_18 [ V_67 ] = & V_127 -> V_89 ;
V_7 -> V_79 ++ ;
if ( F_122 ( ( unsigned long ) F_119 ) )
F_123 ( V_2 -> V_22 , V_127 , ( unsigned long ) F_119 ,
V_7 -> V_79 ) ;
else
F_124 ( V_2 -> V_22 , V_127 , V_7 -> V_79 ) ;
if ( F_125 ( V_26 ) ) {
F_30 ( V_26 ) ;
return;
}
if ( F_114 ( V_7 -> V_79 > V_7 -> V_98 + V_101 ) ) {
F_70 ( V_2 , V_7 ) ;
F_67 ( V_2 , V_7 ) ;
if ( ! F_1 ( V_2 ) ) {
unsigned long V_129 ;
struct V_20 * V_130 = F_20 ( V_2 ) ;
F_48 ( & V_130 -> V_43 , V_129 ) ;
F_72 ( V_2 , V_129 ) ;
} else {
V_7 -> V_94 = V_96 ;
if ( V_2 -> V_100 == V_7 -> V_99 &&
* V_7 -> V_18 [ V_19 ] != V_127 )
F_14 ( V_2 , 0 ) ;
V_7 -> V_99 = V_2 -> V_100 ;
V_7 -> V_98 = V_7 -> V_79 ;
}
} else if ( F_69 ( F_2 ( V_2 -> V_109 ) , V_37 ) )
F_14 ( V_2 , 1 ) ;
F_30 ( V_26 ) ;
}
void F_126 ( struct V_88 * V_127 , void (* F_119)( struct V_88 * V_128 ) )
{
F_118 ( V_127 , F_119 , & V_12 ) ;
}
void F_127 ( struct V_88 * V_127 , void (* F_119)( struct V_88 * V_128 ) )
{
F_118 ( V_127 , F_119 , & V_13 ) ;
}
void F_128 ( void )
{
if ( F_129 () )
return;
F_130 ( F_126 ) ;
}
void F_131 ( void )
{
if ( F_129 () )
return;
F_130 ( F_127 ) ;
}
static int F_132 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
struct V_20 * V_42 = V_7 -> V_53 ;
V_7 -> V_131 ++ ;
F_58 ( V_2 , V_7 ) ;
if ( V_124 &&
V_7 -> V_63 && ! V_7 -> V_10 ) {
V_7 -> V_132 ++ ;
if ( ! V_7 -> V_24 &&
F_69 ( F_2 ( V_2 -> V_109 ) - 1 ,
V_37 ) )
F_26 () ;
} else if ( V_7 -> V_63 && V_7 -> V_10 ) {
V_7 -> V_133 ++ ;
return 1 ;
}
if ( F_18 ( V_7 ) ) {
V_7 -> V_134 ++ ;
return 1 ;
}
if ( F_19 ( V_2 , V_7 ) ) {
V_7 -> V_135 ++ ;
return 1 ;
}
if ( F_2 ( V_42 -> V_3 ) != V_7 -> V_3 ) {
V_7 -> V_136 ++ ;
return 1 ;
}
if ( F_2 ( V_42 -> V_4 ) != V_7 -> V_4 ) {
V_7 -> V_137 ++ ;
return 1 ;
}
if ( F_1 ( V_2 ) &&
F_69 ( F_2 ( V_2 -> V_109 ) , V_37 ) ) {
V_7 -> V_138 ++ ;
return 1 ;
}
V_7 -> V_139 ++ ;
return 0 ;
}
static int F_105 ( int V_5 )
{
return F_132 ( & V_12 , & F_4 ( V_8 , V_5 ) ) ||
F_132 ( & V_13 , & F_4 ( V_11 , V_5 ) ) ||
F_133 ( V_5 ) ;
}
static int F_134 ( int V_5 )
{
return F_4 ( V_8 , V_5 ) . V_17 ||
F_4 ( V_11 , V_5 ) . V_17 ||
F_135 ( V_5 ) ;
}
static void F_136 ( struct V_88 * V_140 )
{
if ( F_137 ( & V_141 ) )
F_138 ( & V_142 ) ;
}
static void F_139 ( void * type )
{
int V_5 = F_24 () ;
struct V_88 * V_127 = & F_4 ( V_143 , V_5 ) ;
void (* F_140)( struct V_88 * V_127 ,
void (* F_119)( struct V_88 * V_127 ) );
F_33 ( & V_141 ) ;
F_140 = type ;
F_140 ( V_127 , F_136 ) ;
}
static void F_141 ( struct V_1 * V_2 ,
void (* F_140)( struct V_88 * V_127 ,
void (* F_119)( struct V_88 * V_127 ) ) )
{
F_142 ( F_143 () ) ;
F_144 ( & V_144 ) ;
F_145 ( & V_142 ) ;
F_146 ( & V_141 , 1 ) ;
F_147 ( F_139 , ( void * ) F_140 , 1 ) ;
if ( F_137 ( & V_141 ) )
F_138 ( & V_142 ) ;
F_148 ( & V_142 ) ;
F_149 ( & V_144 ) ;
}
void F_150 ( void )
{
F_141 ( & V_13 , F_127 ) ;
}
void F_151 ( void )
{
F_141 ( & V_12 , F_126 ) ;
}
static void T_1
F_152 ( int V_5 , struct V_1 * V_2 )
{
unsigned long V_26 ;
int V_74 ;
struct V_6 * V_7 = F_82 ( V_2 -> V_77 , V_5 ) ;
struct V_20 * V_42 = F_20 ( V_2 ) ;
F_48 ( & V_42 -> V_43 , V_26 ) ;
V_7 -> V_54 = 1UL << ( V_5 - V_7 -> V_53 -> V_49 ) ;
V_7 -> V_17 = NULL ;
for ( V_74 = 0 ; V_74 < V_82 ; V_74 ++ )
V_7 -> V_18 [ V_74 ] = & V_7 -> V_17 ;
V_7 -> V_79 = 0 ;
#ifdef F_153
V_7 -> V_30 = & F_4 ( V_27 , V_5 ) ;
#endif
V_7 -> V_5 = V_5 ;
V_7 -> V_2 = V_2 ;
F_49 ( & V_42 -> V_43 , V_26 ) ;
}
static void T_2
F_154 ( int V_5 , struct V_1 * V_2 , int V_24 )
{
unsigned long V_26 ;
unsigned long V_68 ;
struct V_6 * V_7 = F_82 ( V_2 -> V_77 , V_5 ) ;
struct V_20 * V_42 = F_20 ( V_2 ) ;
F_48 ( & V_42 -> V_43 , V_26 ) ;
V_7 -> V_121 = 1 ;
V_7 -> V_24 = V_24 ;
V_7 -> V_98 = 0 ;
V_7 -> V_99 = V_2 -> V_100 ;
V_7 -> V_94 = V_94 ;
F_86 ( & V_42 -> V_43 ) ;
F_85 ( & V_2 -> V_84 ) ;
V_42 = V_7 -> V_53 ;
V_68 = V_7 -> V_54 ;
do {
F_85 ( & V_42 -> V_43 ) ;
V_42 -> V_85 |= V_68 ;
V_68 = V_42 -> V_54 ;
if ( V_42 == V_7 -> V_53 ) {
V_7 -> V_4 = V_42 -> V_3 ;
V_7 -> V_3 = V_42 -> V_3 ;
V_7 -> V_10 = 0 ;
V_7 -> V_63 = 0 ;
V_7 -> V_9 = V_42 -> V_4 - 1 ;
F_6 ( V_2 -> V_22 , V_7 -> V_4 , L_24 ) ;
}
F_86 ( & V_42 -> V_43 ) ;
V_42 = V_42 -> V_72 ;
} while ( V_42 != NULL && ! ( V_42 -> V_85 & V_68 ) );
F_49 ( & V_2 -> V_84 , V_26 ) ;
}
static void T_2 F_155 ( int V_5 )
{
F_154 ( V_5 , & V_12 , 0 ) ;
F_154 ( V_5 , & V_13 , 0 ) ;
F_156 ( V_5 ) ;
}
static int T_2 F_157 ( struct V_55 * V_145 ,
unsigned long V_146 , void * V_147 )
{
long V_5 = ( long ) V_147 ;
struct V_6 * V_7 = F_82 ( V_1 -> V_77 , V_5 ) ;
struct V_20 * V_42 = V_7 -> V_53 ;
F_9 ( L_25 ) ;
switch ( V_146 ) {
case V_148 :
case V_149 :
F_155 ( V_5 ) ;
F_158 ( V_5 ) ;
break;
case V_150 :
case V_151 :
F_90 ( V_42 , - 1 ) ;
F_159 ( V_5 , 1 ) ;
break;
case V_152 :
F_90 ( V_42 , V_5 ) ;
F_159 ( V_5 , 0 ) ;
break;
case V_153 :
case V_154 :
F_79 ( & V_13 ) ;
F_79 ( & V_12 ) ;
F_160 () ;
break;
case V_155 :
case V_156 :
case V_157 :
case V_158 :
F_91 ( V_5 ) ;
break;
default:
break;
}
F_9 ( L_26 ) ;
return V_159 ;
}
void F_161 ( void )
{
F_162 ( F_163 () != 1 ) ;
F_162 ( F_164 () > 0 ) ;
V_103 = 1 ;
}
static void T_1 F_165 ( struct V_1 * V_2 )
{
int V_74 ;
for ( V_74 = V_160 - 1 ; V_74 > 0 ; V_74 -- )
V_2 -> V_161 [ V_74 ] = V_162 ;
V_2 -> V_161 [ 0 ] = V_163 ;
}
static void T_1 F_165 ( struct V_1 * V_2 )
{
int V_164 ;
int V_165 ;
int V_74 ;
V_165 = V_166 ;
for ( V_74 = V_160 - 1 ; V_74 >= 0 ; V_74 -- ) {
V_164 = V_2 -> V_167 [ V_74 ] ;
V_2 -> V_161 [ V_74 ] = ( V_165 + V_164 - 1 ) / V_164 ;
V_165 = V_164 ;
}
}
static void T_1 F_166 ( struct V_1 * V_2 ,
struct V_6 T_3 * V_77 )
{
static char * V_168 [] = { L_27 ,
L_28 ,
L_29 ,
L_30 } ;
int V_169 = 1 ;
int V_74 ;
int V_50 ;
struct V_20 * V_42 ;
F_167 ( V_170 > F_168 ( V_168 ) ) ;
for ( V_74 = 1 ; V_74 < V_160 ; V_74 ++ )
V_2 -> V_70 [ V_74 ] = V_2 -> V_70 [ V_74 - 1 ] + V_2 -> V_167 [ V_74 - 1 ] ;
F_165 ( V_2 ) ;
for ( V_74 = V_160 - 1 ; V_74 >= 0 ; V_74 -- ) {
V_169 *= V_2 -> V_161 [ V_74 ] ;
V_42 = V_2 -> V_70 [ V_74 ] ;
for ( V_50 = 0 ; V_50 < V_2 -> V_167 [ V_74 ] ; V_50 ++ , V_42 ++ ) {
F_169 ( & V_42 -> V_43 ) ;
F_170 ( & V_42 -> V_43 ,
& V_171 [ V_74 ] , V_168 [ V_74 ] ) ;
V_42 -> V_4 = 0 ;
V_42 -> V_47 = 0 ;
V_42 -> V_85 = 0 ;
V_42 -> V_49 = V_50 * V_169 ;
V_42 -> V_48 = ( V_50 + 1 ) * V_169 - 1 ;
if ( V_42 -> V_48 >= V_166 )
V_42 -> V_48 = V_166 - 1 ;
if ( V_74 == 0 ) {
V_42 -> V_172 = 0 ;
V_42 -> V_54 = 0 ;
V_42 -> V_72 = NULL ;
} else {
V_42 -> V_172 = V_50 % V_2 -> V_161 [ V_74 - 1 ] ;
V_42 -> V_54 = 1UL << V_42 -> V_172 ;
V_42 -> V_72 = V_2 -> V_70 [ V_74 - 1 ] +
V_50 / V_2 -> V_161 [ V_74 - 1 ] ;
}
V_42 -> V_70 = V_74 ;
F_171 ( & V_42 -> V_173 ) ;
}
}
V_2 -> V_77 = V_77 ;
V_42 = V_2 -> V_70 [ V_160 - 1 ] ;
F_172 (i) {
while ( V_74 > V_42 -> V_48 )
V_42 ++ ;
F_82 ( V_2 -> V_77 , V_74 ) -> V_53 = V_42 ;
F_152 ( V_74 , V_2 ) ;
}
}
void T_1 F_173 ( void )
{
int V_5 ;
F_174 () ;
F_166 ( & V_12 , & V_8 ) ;
F_166 ( & V_13 , & V_11 ) ;
F_175 () ;
F_176 ( V_126 , F_112 ) ;
F_177 ( F_157 , 0 ) ;
F_178 (cpu)
F_157 ( NULL , V_148 , ( void * ) ( long ) V_5 ) ;
F_62 () ;
}
