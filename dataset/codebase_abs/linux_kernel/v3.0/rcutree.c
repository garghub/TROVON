static int F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_2 -> V_3 ) != F_2 ( V_2 -> V_4 ) ;
}
void F_3 ( int V_5 )
{
struct V_6 * V_7 = & F_4 ( V_8 , V_5 ) ;
V_7 -> V_9 = V_7 -> V_4 - 1 ;
F_5 () ;
V_7 -> V_10 = 1 ;
}
void F_6 ( int V_5 )
{
struct V_6 * V_7 = & F_4 ( V_11 , V_5 ) ;
V_7 -> V_9 = V_7 -> V_4 - 1 ;
F_5 () ;
V_7 -> V_10 = 1 ;
}
void F_7 ( int V_5 )
{
F_3 ( V_5 ) ;
F_8 ( V_5 ) ;
}
long F_9 ( void )
{
return V_12 . V_3 ;
}
long F_10 ( void )
{
return V_13 . V_3 ;
}
void F_11 ( void )
{
F_12 ( & V_13 , 0 ) ;
}
void F_13 ( void )
{
V_14 ++ ;
V_15 = 0 ;
}
void F_14 ( unsigned long V_16 )
{
V_15 ++ ;
}
void F_15 ( void )
{
F_12 ( & V_12 , 0 ) ;
}
static int
F_16 ( struct V_6 * V_7 )
{
return & V_7 -> V_17 != V_7 -> V_18 [ V_19 ] ;
}
static int
F_17 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
return * V_7 -> V_18 [ V_19 ] && ! F_1 ( V_2 ) ;
}
static struct V_20 * F_18 ( struct V_1 * V_2 )
{
return & V_2 -> V_21 [ 0 ] ;
}
static int F_19 ( struct V_6 * V_7 )
{
if ( F_20 ( V_7 -> V_5 ) ) {
V_7 -> V_22 ++ ;
return 1 ;
}
if ( V_7 -> V_23 )
return 0 ;
if ( V_7 -> V_5 != F_21 () )
F_22 ( V_7 -> V_5 ) ;
else
F_23 () ;
V_7 -> V_24 ++ ;
return 0 ;
}
void F_24 ( void )
{
unsigned long V_25 ;
struct V_26 * V_27 ;
F_25 ( V_25 ) ;
V_27 = & F_26 ( V_26 ) ;
if ( -- V_27 -> V_28 ) {
F_27 ( V_25 ) ;
return;
}
F_28 () ;
F_29 ( & V_27 -> V_29 ) ;
F_30 () ;
F_31 ( F_32 ( & V_27 -> V_29 ) & 0x1 ) ;
F_27 ( V_25 ) ;
if ( F_33 () &&
( F_26 ( V_8 ) . V_17 ||
F_26 ( V_11 ) . V_17 ||
F_34 ( F_21 () ) ) )
F_23 () ;
}
void F_35 ( void )
{
unsigned long V_25 ;
struct V_26 * V_27 ;
F_25 ( V_25 ) ;
V_27 = & F_26 ( V_26 ) ;
if ( V_27 -> V_28 ++ ) {
F_27 ( V_25 ) ;
return;
}
F_28 () ;
F_29 ( & V_27 -> V_29 ) ;
F_30 () ;
F_31 ( ! ( F_32 ( & V_27 -> V_29 ) & 0x1 ) ) ;
F_27 ( V_25 ) ;
}
void F_36 ( void )
{
struct V_26 * V_27 = & F_26 ( V_26 ) ;
if ( V_27 -> V_30 == 0 &&
( F_32 ( & V_27 -> V_29 ) & 0x1 ) )
return;
V_27 -> V_30 ++ ;
F_28 () ;
F_29 ( & V_27 -> V_29 ) ;
F_30 () ;
F_31 ( ! ( F_32 ( & V_27 -> V_29 ) & 0x1 ) ) ;
}
void F_37 ( void )
{
struct V_26 * V_27 = & F_26 ( V_26 ) ;
if ( V_27 -> V_30 == 0 ||
-- V_27 -> V_30 != 0 )
return;
F_28 () ;
F_29 ( & V_27 -> V_29 ) ;
F_30 () ;
F_31 ( F_32 ( & V_27 -> V_29 ) & 0x1 ) ;
}
void F_38 ( void )
{
F_35 () ;
}
void F_39 ( void )
{
F_24 () ;
}
static int F_40 ( struct V_6 * V_7 )
{
V_7 -> V_31 = F_41 ( 0 , & V_7 -> V_29 -> V_29 ) ;
return 0 ;
}
static int F_42 ( struct V_6 * V_7 )
{
unsigned long V_32 ;
unsigned long V_33 ;
V_32 = ( unsigned long ) F_41 ( 0 , & V_7 -> V_29 -> V_29 ) ;
V_33 = ( unsigned long ) V_7 -> V_31 ;
if ( ( V_32 & 0x1 ) == 0 || F_43 ( V_32 , V_33 + 2 ) ) {
V_7 -> V_34 ++ ;
return 1 ;
}
return F_19 ( V_7 ) ;
}
static int F_40 ( struct V_6 * V_7 )
{
return 0 ;
}
static int F_42 ( struct V_6 * V_7 )
{
return F_19 ( V_7 ) ;
}
static void F_44 ( struct V_1 * V_2 )
{
V_2 -> V_35 = V_36 ;
V_2 -> V_37 = V_36 + V_38 ;
}
static void F_45 ( struct V_1 * V_2 )
{
int V_5 ;
long V_39 ;
unsigned long V_25 ;
struct V_20 * V_40 = F_18 ( V_2 ) ;
F_46 ( & V_40 -> V_41 , V_25 ) ;
V_39 = V_36 - V_2 -> V_37 ;
if ( V_39 < V_42 || ! F_1 ( V_2 ) ) {
F_47 ( & V_40 -> V_41 , V_25 ) ;
return;
}
V_2 -> V_37 = V_36 + V_43 ;
F_48 ( V_40 ) ;
F_47 ( & V_40 -> V_41 , V_25 ) ;
F_49 ( V_44 L_1 ,
V_2 -> V_45 ) ;
F_50 (rsp, rnp) {
F_46 ( & V_40 -> V_41 , V_25 ) ;
F_48 ( V_40 ) ;
F_47 ( & V_40 -> V_41 , V_25 ) ;
if ( V_40 -> V_46 == 0 )
continue;
for ( V_5 = 0 ; V_5 <= V_40 -> V_47 - V_40 -> V_48 ; V_5 ++ )
if ( V_40 -> V_46 & ( 1UL << V_5 ) )
F_49 ( L_2 , V_40 -> V_48 + V_5 ) ;
}
F_49 ( L_3 ,
F_21 () , ( long ) ( V_36 - V_2 -> V_35 ) ) ;
F_51 () ;
F_52 ( V_2 ) ;
F_12 ( V_2 , 0 ) ;
}
static void F_53 ( struct V_1 * V_2 )
{
unsigned long V_25 ;
struct V_20 * V_40 = F_18 ( V_2 ) ;
F_49 ( V_44 L_4 ,
V_2 -> V_45 , F_21 () , V_36 - V_2 -> V_35 ) ;
F_51 () ;
F_46 ( & V_40 -> V_41 , V_25 ) ;
if ( F_43 ( V_36 , V_2 -> V_37 ) )
V_2 -> V_37 =
V_36 + V_43 ;
F_47 ( & V_40 -> V_41 , V_25 ) ;
F_23 () ;
}
static void F_54 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
unsigned long V_49 ;
unsigned long V_50 ;
struct V_20 * V_40 ;
if ( V_51 )
return;
V_49 = F_2 ( V_36 ) ;
V_50 = F_2 ( V_2 -> V_37 ) ;
V_40 = V_7 -> V_52 ;
if ( ( F_2 ( V_40 -> V_46 ) & V_7 -> V_53 ) && F_43 ( V_49 , V_50 ) ) {
F_53 ( V_2 ) ;
} else if ( F_1 ( V_2 ) &&
F_43 ( V_49 , V_50 + V_42 ) ) {
F_45 ( V_2 ) ;
}
}
static int F_55 ( struct V_54 * V_55 , unsigned long V_56 , void * V_57 )
{
V_51 = 1 ;
return V_58 ;
}
void F_56 ( void )
{
V_12 . V_37 = V_36 + V_59 / 2 ;
V_13 . V_37 = V_36 + V_59 / 2 ;
F_57 () ;
}
static void T_1 F_58 ( void )
{
F_59 ( & V_60 , & V_61 ) ;
}
static void F_60 ( struct V_1 * V_2 , struct V_20 * V_40 , struct V_6 * V_7 )
{
if ( V_7 -> V_4 != V_40 -> V_4 ) {
V_7 -> V_4 = V_40 -> V_4 ;
if ( V_40 -> V_46 & V_7 -> V_53 ) {
V_7 -> V_62 = 1 ;
V_7 -> V_10 = 0 ;
} else
V_7 -> V_62 = 0 ;
}
}
static void F_61 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
unsigned long V_25 ;
struct V_20 * V_40 ;
F_25 ( V_25 ) ;
V_40 = V_7 -> V_52 ;
if ( V_7 -> V_4 == F_2 ( V_40 -> V_4 ) ||
! F_62 ( & V_40 -> V_41 ) ) {
F_27 ( V_25 ) ;
return;
}
F_60 ( V_2 , V_40 , V_7 ) ;
F_47 ( & V_40 -> V_41 , V_25 ) ;
}
static int
F_63 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
unsigned long V_25 ;
int V_63 = 0 ;
F_25 ( V_25 ) ;
if ( V_7 -> V_4 != V_2 -> V_4 ) {
F_61 ( V_2 , V_7 ) ;
V_63 = 1 ;
}
F_27 ( V_25 ) ;
return V_63 ;
}
static void
F_64 ( struct V_1 * V_2 , struct V_20 * V_40 , struct V_6 * V_7 )
{
if ( V_7 -> V_3 != V_40 -> V_3 ) {
V_7 -> V_18 [ V_19 ] = V_7 -> V_18 [ V_64 ] ;
V_7 -> V_18 [ V_64 ] = V_7 -> V_18 [ V_65 ] ;
V_7 -> V_18 [ V_65 ] = V_7 -> V_18 [ V_66 ] ;
V_7 -> V_3 = V_40 -> V_3 ;
if ( F_65 ( V_7 -> V_4 , V_7 -> V_3 ) )
V_7 -> V_4 = V_7 -> V_3 ;
if ( ( V_40 -> V_46 & V_7 -> V_53 ) == 0 )
V_7 -> V_62 = 0 ;
}
}
static void
F_66 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
unsigned long V_25 ;
struct V_20 * V_40 ;
F_25 ( V_25 ) ;
V_40 = V_7 -> V_52 ;
if ( V_7 -> V_3 == F_2 ( V_40 -> V_3 ) ||
! F_62 ( & V_40 -> V_41 ) ) {
F_27 ( V_25 ) ;
return;
}
F_64 ( V_2 , V_40 , V_7 ) ;
F_47 ( & V_40 -> V_41 , V_25 ) ;
}
static void
F_67 ( struct V_1 * V_2 , struct V_20 * V_40 , struct V_6 * V_7 )
{
F_64 ( V_2 , V_40 , V_7 ) ;
V_7 -> V_18 [ V_65 ] = V_7 -> V_18 [ V_66 ] ;
V_7 -> V_18 [ V_64 ] = V_7 -> V_18 [ V_66 ] ;
F_60 ( V_2 , V_40 , V_7 ) ;
}
static void
F_68 ( struct V_1 * V_2 , unsigned long V_25 )
__releases( rcu_get_root( V_2 )->lock
static void F_69 ( struct V_1 * V_2 , unsigned long V_25 )
__releases( rcu_get_root( V_2 )->lock
static void
F_70 ( unsigned long V_67 , struct V_1 * V_2 ,
struct V_20 * V_40 , unsigned long V_25 )
__releases( V_40 -> V_41 )
{
struct V_20 * V_68 ;
for (; ; ) {
if ( ! ( V_40 -> V_46 & V_67 ) ) {
F_47 ( & V_40 -> V_41 , V_25 ) ;
return;
}
V_40 -> V_46 &= ~ V_67 ;
if ( V_40 -> V_46 != 0 || F_71 ( V_40 ) ) {
F_47 ( & V_40 -> V_41 , V_25 ) ;
return;
}
V_67 = V_40 -> V_53 ;
if ( V_40 -> V_69 == NULL ) {
break;
}
F_47 ( & V_40 -> V_41 , V_25 ) ;
V_68 = V_40 ;
V_40 = V_40 -> V_69 ;
F_46 ( & V_40 -> V_41 , V_25 ) ;
F_31 ( V_68 -> V_46 ) ;
}
F_69 ( V_2 , V_25 ) ;
}
static void
F_72 ( int V_5 , struct V_1 * V_2 , struct V_6 * V_7 , long V_70 )
{
unsigned long V_25 ;
unsigned long V_67 ;
struct V_20 * V_40 ;
V_40 = V_7 -> V_52 ;
F_46 ( & V_40 -> V_41 , V_25 ) ;
if ( V_70 != V_40 -> V_3 ) {
V_7 -> V_10 = 0 ;
F_47 ( & V_40 -> V_41 , V_25 ) ;
return;
}
V_67 = V_7 -> V_53 ;
if ( ( V_40 -> V_46 & V_67 ) == 0 ) {
F_47 ( & V_40 -> V_41 , V_25 ) ;
} else {
V_7 -> V_62 = 0 ;
V_7 -> V_18 [ V_65 ] = V_7 -> V_18 [ V_66 ] ;
F_70 ( V_67 , V_2 , V_40 , V_25 ) ;
}
}
static void
F_73 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
if ( F_63 ( V_2 , V_7 ) )
return;
if ( ! V_7 -> V_62 )
return;
if ( ! V_7 -> V_10 )
return;
F_72 ( V_7 -> V_5 , V_2 , V_7 , V_7 -> V_9 ) ;
}
static void F_74 ( struct V_1 * V_2 )
{
int V_71 ;
int V_72 = F_75 ( V_73 ) ;
struct V_6 * V_7 = F_76 ( V_2 -> V_74 ) ;
struct V_6 * V_75 = F_77 ( V_2 -> V_74 , V_72 ) ;
if ( V_7 -> V_17 == NULL )
return;
* V_75 -> V_18 [ V_66 ] = V_7 -> V_17 ;
V_75 -> V_18 [ V_66 ] = V_7 -> V_18 [ V_66 ] ;
V_75 -> V_76 += V_7 -> V_76 ;
V_75 -> V_77 += V_7 -> V_76 ;
V_7 -> V_78 += V_7 -> V_76 ;
V_7 -> V_17 = NULL ;
for ( V_71 = 0 ; V_71 < V_79 ; V_71 ++ )
V_7 -> V_18 [ V_71 ] = & V_7 -> V_17 ;
V_7 -> V_76 = 0 ;
}
static void F_78 ( int V_5 , struct V_1 * V_2 )
{
unsigned long V_25 ;
unsigned long V_67 ;
int V_80 = 0 ;
struct V_6 * V_7 = F_77 ( V_2 -> V_74 , V_5 ) ;
struct V_20 * V_40 ;
F_79 ( V_5 ) ;
F_46 ( & V_2 -> V_81 , V_25 ) ;
V_40 = V_7 -> V_52 ;
V_67 = V_7 -> V_53 ;
do {
F_80 ( & V_40 -> V_41 ) ;
V_40 -> V_82 &= ~ V_67 ;
if ( V_40 -> V_82 != 0 ) {
if ( V_40 != V_7 -> V_52 )
F_81 ( & V_40 -> V_41 ) ;
break;
}
if ( V_40 == V_7 -> V_52 )
V_80 = F_82 ( V_2 , V_40 , V_7 ) ;
else
F_81 ( & V_40 -> V_41 ) ;
V_67 = V_40 -> V_53 ;
V_40 = V_40 -> V_69 ;
} while ( V_40 != NULL );
F_81 ( & V_2 -> V_81 ) ;
V_40 = V_7 -> V_52 ;
if ( V_80 & V_83 )
F_83 ( V_40 , V_25 ) ;
else
F_47 ( & V_40 -> V_41 , V_25 ) ;
if ( V_80 & V_84 )
F_84 ( V_2 , V_40 ) ;
F_85 ( V_40 , - 1 ) ;
}
static void F_86 ( int V_5 )
{
F_78 ( V_5 , & V_12 ) ;
F_78 ( V_5 , & V_13 ) ;
F_87 ( V_5 ) ;
}
static void F_74 ( struct V_1 * V_2 )
{
}
static void F_86 ( int V_5 )
{
}
static void F_88 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
unsigned long V_25 ;
struct V_85 * V_86 , * V_87 , * * V_88 ;
int V_89 ;
if ( ! F_16 ( V_7 ) )
return;
F_25 ( V_25 ) ;
V_87 = V_7 -> V_17 ;
V_7 -> V_17 = * V_7 -> V_18 [ V_19 ] ;
* V_7 -> V_18 [ V_19 ] = NULL ;
V_88 = V_7 -> V_18 [ V_19 ] ;
for ( V_89 = V_79 - 1 ; V_89 >= 0 ; V_89 -- )
if ( V_7 -> V_18 [ V_89 ] == V_7 -> V_18 [ V_19 ] )
V_7 -> V_18 [ V_89 ] = & V_7 -> V_17 ;
F_27 ( V_25 ) ;
V_89 = 0 ;
while ( V_87 ) {
V_86 = V_87 -> V_86 ;
F_89 ( V_86 ) ;
F_90 ( V_87 ) ;
F_91 ( V_87 ) ;
V_87 = V_86 ;
if ( ++ V_89 >= V_7 -> V_90 )
break;
}
F_25 ( V_25 ) ;
V_7 -> V_76 -= V_89 ;
V_7 -> V_91 += V_89 ;
if ( V_87 != NULL ) {
* V_88 = V_7 -> V_17 ;
V_7 -> V_17 = V_87 ;
for ( V_89 = 0 ; V_89 < V_79 ; V_89 ++ )
if ( & V_7 -> V_17 == V_7 -> V_18 [ V_89 ] )
V_7 -> V_18 [ V_89 ] = V_88 ;
else
break;
}
if ( V_7 -> V_90 == V_92 && V_7 -> V_76 <= V_93 )
V_7 -> V_90 = V_90 ;
if ( V_7 -> V_76 == 0 && V_7 -> V_94 != 0 ) {
V_7 -> V_94 = 0 ;
V_7 -> V_95 = V_2 -> V_96 ;
} else if ( V_7 -> V_76 < V_7 -> V_94 - V_97 )
V_7 -> V_94 = V_7 -> V_76 ;
F_27 ( V_25 ) ;
if ( F_16 ( V_7 ) )
F_92 () ;
}
void F_93 ( int V_5 , int V_98 )
{
if ( V_98 ||
( F_94 ( V_5 ) && V_99 &&
! F_95 () && F_96 () <= ( 1 << V_100 ) ) ) {
F_3 ( V_5 ) ;
F_6 ( V_5 ) ;
} else if ( ! F_95 () ) {
F_6 ( V_5 ) ;
}
F_97 ( V_5 ) ;
if ( F_98 ( V_5 ) )
F_92 () ;
}
static void F_99 ( struct V_1 * V_2 , int (* F_100)( struct V_6 * ) )
{
unsigned long V_101 ;
int V_5 ;
unsigned long V_25 ;
unsigned long V_67 ;
struct V_20 * V_40 ;
F_50 (rsp, rnp) {
V_67 = 0 ;
F_46 ( & V_40 -> V_41 , V_25 ) ;
if ( ! F_1 ( V_2 ) ) {
F_47 ( & V_40 -> V_41 , V_25 ) ;
return;
}
if ( V_40 -> V_46 == 0 ) {
F_101 ( V_40 , V_25 ) ;
continue;
}
V_5 = V_40 -> V_48 ;
V_101 = 1 ;
for (; V_5 <= V_40 -> V_47 ; V_5 ++ , V_101 <<= 1 ) {
if ( ( V_40 -> V_46 & V_101 ) != 0 &&
F_100 ( F_77 ( V_2 -> V_74 , V_5 ) ) )
V_67 |= V_101 ;
}
if ( V_67 != 0 ) {
F_70 ( V_67 , V_2 , V_40 , V_25 ) ;
continue;
}
F_47 ( & V_40 -> V_41 , V_25 ) ;
}
V_40 = F_18 ( V_2 ) ;
if ( V_40 -> V_46 == 0 ) {
F_46 ( & V_40 -> V_41 , V_25 ) ;
F_101 ( V_40 , V_25 ) ;
}
}
static void F_12 ( struct V_1 * V_2 , int V_102 )
{
unsigned long V_25 ;
struct V_20 * V_40 = F_18 ( V_2 ) ;
if ( ! F_1 ( V_2 ) )
return;
if ( ! F_102 ( & V_2 -> V_103 , V_25 ) ) {
V_2 -> V_104 ++ ;
return;
}
if ( V_102 && F_43 ( V_2 -> V_105 , V_36 ) )
goto V_106;
V_2 -> V_96 ++ ;
F_80 ( & V_40 -> V_41 ) ;
V_2 -> V_105 = V_36 + V_107 ;
if( ! F_1 ( V_2 ) ) {
V_2 -> V_108 ++ ;
F_81 ( & V_40 -> V_41 ) ;
goto V_106;
}
V_2 -> V_109 = 1 ;
switch ( V_2 -> V_110 ) {
case V_111 :
case V_112 :
break;
case V_113 :
if ( V_114 != V_113 )
break;
F_81 ( & V_40 -> V_41 ) ;
F_99 ( V_2 , F_40 ) ;
F_80 ( & V_40 -> V_41 ) ;
if ( F_1 ( V_2 ) )
V_2 -> V_110 = V_115 ;
break;
case V_115 :
F_81 ( & V_40 -> V_41 ) ;
F_99 ( V_2 , F_42 ) ;
F_80 ( & V_40 -> V_41 ) ;
break;
}
V_2 -> V_109 = 0 ;
if ( V_2 -> V_116 ) {
F_81 ( & V_2 -> V_103 ) ;
V_2 -> V_116 = 0 ;
F_68 ( V_2 , V_25 ) ;
return;
}
F_81 ( & V_40 -> V_41 ) ;
V_106:
F_47 ( & V_2 -> V_103 , V_25 ) ;
}
static void F_12 ( struct V_1 * V_2 , int V_102 )
{
F_23 () ;
}
static void
F_103 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
unsigned long V_25 ;
F_31 ( V_7 -> V_117 == 0 ) ;
if ( F_65 ( F_2 ( V_2 -> V_105 ) , V_36 ) )
F_12 ( V_2 , 1 ) ;
F_66 ( V_2 , V_7 ) ;
F_73 ( V_2 , V_7 ) ;
if ( F_17 ( V_2 , V_7 ) ) {
F_46 ( & F_18 ( V_2 ) -> V_41 , V_25 ) ;
F_68 ( V_2 , V_25 ) ;
}
if ( F_16 ( V_7 ) )
F_104 ( V_2 , V_7 ) ;
}
static void F_105 ( struct V_118 * V_119 )
{
F_103 ( & V_12 ,
& F_26 ( V_8 ) ) ;
F_103 ( & V_13 , & F_26 ( V_11 ) ) ;
F_106 () ;
F_107 () ;
}
static void F_104 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
if ( F_108 ( ! F_2 ( V_120 ) ) )
return;
if ( F_109 ( ! V_2 -> V_121 ) ) {
F_88 ( V_2 , V_7 ) ;
return;
}
F_110 () ;
}
static void F_92 ( void )
{
F_111 ( V_122 ) ;
}
static void
F_112 ( struct V_85 * V_123 , void (* F_113)( struct V_85 * V_124 ) ,
struct V_1 * V_2 )
{
unsigned long V_25 ;
struct V_6 * V_7 ;
F_114 ( V_123 ) ;
V_123 -> F_113 = F_113 ;
V_123 -> V_86 = NULL ;
F_115 () ;
F_25 ( V_25 ) ;
V_7 = F_76 ( V_2 -> V_74 ) ;
* V_7 -> V_18 [ V_66 ] = V_123 ;
V_7 -> V_18 [ V_66 ] = & V_123 -> V_86 ;
V_7 -> V_76 ++ ;
if ( F_116 ( V_25 ) ) {
F_27 ( V_25 ) ;
return;
}
if ( F_108 ( V_7 -> V_76 > V_7 -> V_94 + V_97 ) ) {
F_66 ( V_2 , V_7 ) ;
F_63 ( V_2 , V_7 ) ;
if ( ! F_1 ( V_2 ) ) {
unsigned long V_125 ;
struct V_20 * V_126 = F_18 ( V_2 ) ;
F_46 ( & V_126 -> V_41 , V_125 ) ;
F_68 ( V_2 , V_125 ) ;
} else {
V_7 -> V_90 = V_92 ;
if ( V_2 -> V_96 == V_7 -> V_95 &&
* V_7 -> V_18 [ V_19 ] != V_123 )
F_12 ( V_2 , 0 ) ;
V_7 -> V_95 = V_2 -> V_96 ;
V_7 -> V_94 = V_7 -> V_76 ;
}
} else if ( F_65 ( F_2 ( V_2 -> V_105 ) , V_36 ) )
F_12 ( V_2 , 1 ) ;
F_27 ( V_25 ) ;
}
void F_117 ( struct V_85 * V_123 , void (* F_113)( struct V_85 * V_124 ) )
{
F_112 ( V_123 , F_113 , & V_12 ) ;
}
void F_118 ( struct V_85 * V_123 , void (* F_113)( struct V_85 * V_124 ) )
{
F_112 ( V_123 , F_113 , & V_13 ) ;
}
void F_119 ( void )
{
struct V_127 V_124 ;
if ( F_120 () )
return;
F_121 ( & V_124 . V_123 ) ;
F_122 ( & V_124 . V_128 ) ;
F_117 ( & V_124 . V_123 , V_129 ) ;
F_123 ( & V_124 . V_128 ) ;
F_124 ( & V_124 . V_123 ) ;
}
void F_125 ( void )
{
struct V_127 V_124 ;
if ( F_120 () )
return;
F_121 ( & V_124 . V_123 ) ;
F_122 ( & V_124 . V_128 ) ;
F_118 ( & V_124 . V_123 , V_129 ) ;
F_123 ( & V_124 . V_128 ) ;
F_124 ( & V_124 . V_123 ) ;
}
static int F_126 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
struct V_20 * V_40 = V_7 -> V_52 ;
V_7 -> V_130 ++ ;
F_54 ( V_2 , V_7 ) ;
if ( V_7 -> V_62 && ! V_7 -> V_10 ) {
V_7 -> V_131 ++ ;
if ( ! V_7 -> V_23 &&
F_65 ( F_2 ( V_2 -> V_105 ) - 1 ,
V_36 ) )
F_23 () ;
} else if ( V_7 -> V_62 && V_7 -> V_10 ) {
V_7 -> V_132 ++ ;
return 1 ;
}
if ( F_16 ( V_7 ) ) {
V_7 -> V_133 ++ ;
return 1 ;
}
if ( F_17 ( V_2 , V_7 ) ) {
V_7 -> V_134 ++ ;
return 1 ;
}
if ( F_2 ( V_40 -> V_3 ) != V_7 -> V_3 ) {
V_7 -> V_135 ++ ;
return 1 ;
}
if ( F_2 ( V_40 -> V_4 ) != V_7 -> V_4 ) {
V_7 -> V_136 ++ ;
return 1 ;
}
if ( F_1 ( V_2 ) &&
F_65 ( F_2 ( V_2 -> V_105 ) , V_36 ) ) {
V_7 -> V_137 ++ ;
return 1 ;
}
V_7 -> V_138 ++ ;
return 0 ;
}
static int F_98 ( int V_5 )
{
return F_126 ( & V_12 , & F_4 ( V_8 , V_5 ) ) ||
F_126 ( & V_13 , & F_4 ( V_11 , V_5 ) ) ||
F_127 ( V_5 ) ;
}
static int F_128 ( int V_5 )
{
return F_4 ( V_8 , V_5 ) . V_17 ||
F_4 ( V_11 , V_5 ) . V_17 ||
F_34 ( V_5 ) ;
}
static void F_129 ( struct V_85 * V_139 )
{
if ( F_130 ( & V_140 ) )
F_131 ( & V_141 ) ;
}
static void F_132 ( void * type )
{
int V_5 = F_21 () ;
struct V_85 * V_123 = & F_4 ( V_142 , V_5 ) ;
void (* F_133)( struct V_85 * V_123 ,
void (* F_113)( struct V_85 * V_123 ) );
F_29 ( & V_140 ) ;
F_133 = type ;
F_133 ( V_123 , F_129 ) ;
}
static void F_134 ( struct V_1 * V_2 ,
void (* F_133)( struct V_85 * V_123 ,
void (* F_113)( struct V_85 * V_123 ) ) )
{
F_135 ( F_136 () ) ;
F_137 ( & V_143 ) ;
F_122 ( & V_141 ) ;
F_138 ( & V_140 , 1 ) ;
F_139 ( F_132 , ( void * ) F_133 , 1 ) ;
if ( F_130 ( & V_140 ) )
F_131 ( & V_141 ) ;
F_123 ( & V_141 ) ;
F_140 ( & V_143 ) ;
}
void F_141 ( void )
{
F_134 ( & V_13 , F_118 ) ;
}
void F_142 ( void )
{
F_134 ( & V_12 , F_117 ) ;
}
static void T_1
F_143 ( int V_5 , struct V_1 * V_2 )
{
unsigned long V_25 ;
int V_71 ;
struct V_6 * V_7 = F_77 ( V_2 -> V_74 , V_5 ) ;
struct V_20 * V_40 = F_18 ( V_2 ) ;
F_46 ( & V_40 -> V_41 , V_25 ) ;
V_7 -> V_53 = 1UL << ( V_5 - V_7 -> V_52 -> V_48 ) ;
V_7 -> V_17 = NULL ;
for ( V_71 = 0 ; V_71 < V_79 ; V_71 ++ )
V_7 -> V_18 [ V_71 ] = & V_7 -> V_17 ;
V_7 -> V_76 = 0 ;
#ifdef F_144
V_7 -> V_29 = & F_4 ( V_26 , V_5 ) ;
#endif
V_7 -> V_5 = V_5 ;
F_47 ( & V_40 -> V_41 , V_25 ) ;
}
static void T_2
F_145 ( int V_5 , struct V_1 * V_2 , int V_23 )
{
unsigned long V_25 ;
unsigned long V_67 ;
struct V_6 * V_7 = F_77 ( V_2 -> V_74 , V_5 ) ;
struct V_20 * V_40 = F_18 ( V_2 ) ;
F_46 ( & V_40 -> V_41 , V_25 ) ;
V_7 -> V_10 = 0 ;
V_7 -> V_62 = 1 ;
V_7 -> V_117 = 1 ;
V_7 -> V_23 = V_23 ;
V_7 -> V_94 = 0 ;
V_7 -> V_95 = V_2 -> V_96 ;
V_7 -> V_90 = V_90 ;
F_81 ( & V_40 -> V_41 ) ;
F_80 ( & V_2 -> V_81 ) ;
V_40 = V_7 -> V_52 ;
V_67 = V_7 -> V_53 ;
do {
F_80 ( & V_40 -> V_41 ) ;
V_40 -> V_82 |= V_67 ;
V_67 = V_40 -> V_53 ;
if ( V_40 == V_7 -> V_52 ) {
V_7 -> V_4 = V_40 -> V_3 ;
V_7 -> V_3 = V_40 -> V_3 ;
V_7 -> V_9 = V_40 -> V_3 - 1 ;
}
F_81 ( & V_40 -> V_41 ) ;
V_40 = V_40 -> V_69 ;
} while ( V_40 != NULL && ! ( V_40 -> V_82 & V_67 ) );
F_47 ( & V_2 -> V_81 , V_25 ) ;
}
static void T_2 F_146 ( int V_5 )
{
F_145 ( V_5 , & V_12 , 0 ) ;
F_145 ( V_5 , & V_13 , 0 ) ;
F_147 ( V_5 ) ;
}
static int T_2 F_148 ( struct V_54 * V_144 ,
unsigned long V_145 , void * V_146 )
{
long V_5 = ( long ) V_146 ;
struct V_6 * V_7 = F_77 ( V_1 -> V_74 , V_5 ) ;
struct V_20 * V_40 = V_7 -> V_52 ;
switch ( V_145 ) {
case V_147 :
case V_148 :
F_146 ( V_5 ) ;
F_149 ( V_5 ) ;
break;
case V_149 :
case V_150 :
F_85 ( V_40 , - 1 ) ;
F_150 ( V_5 , 1 ) ;
break;
case V_151 :
F_85 ( V_40 , V_5 ) ;
F_150 ( V_5 , 0 ) ;
break;
case V_152 :
case V_153 :
F_74 ( & V_13 ) ;
F_74 ( & V_12 ) ;
F_151 () ;
break;
case V_154 :
case V_155 :
case V_156 :
case V_157 :
F_86 ( V_5 ) ;
break;
default:
break;
}
return V_158 ;
}
void F_152 ( void )
{
F_153 ( F_154 () != 1 ) ;
F_153 ( F_155 () > 0 ) ;
V_99 = 1 ;
}
static void T_1 F_156 ( struct V_1 * V_2 )
{
int V_71 ;
for ( V_71 = V_159 - 1 ; V_71 > 0 ; V_71 -- )
V_2 -> V_160 [ V_71 ] = V_161 ;
V_2 -> V_160 [ 0 ] = V_162 ;
}
static void T_1 F_156 ( struct V_1 * V_2 )
{
int V_163 ;
int V_164 ;
int V_71 ;
V_164 = V_165 ;
for ( V_71 = V_159 - 1 ; V_71 >= 0 ; V_71 -- ) {
V_163 = V_2 -> V_166 [ V_71 ] ;
V_2 -> V_160 [ V_71 ] = ( V_164 + V_163 - 1 ) / V_163 ;
V_164 = V_163 ;
}
}
static void T_1 F_157 ( struct V_1 * V_2 ,
struct V_6 T_3 * V_74 )
{
static char * V_167 [] = { L_5 ,
L_6 ,
L_7 ,
L_8 } ;
int V_168 = 1 ;
int V_71 ;
int V_49 ;
struct V_20 * V_40 ;
F_158 ( V_169 > F_159 ( V_167 ) ) ;
for ( V_71 = 1 ; V_71 < V_159 ; V_71 ++ )
V_2 -> V_170 [ V_71 ] = V_2 -> V_170 [ V_71 - 1 ] + V_2 -> V_166 [ V_71 - 1 ] ;
F_156 ( V_2 ) ;
for ( V_71 = V_159 - 1 ; V_71 >= 0 ; V_71 -- ) {
V_168 *= V_2 -> V_160 [ V_71 ] ;
V_40 = V_2 -> V_170 [ V_71 ] ;
for ( V_49 = 0 ; V_49 < V_2 -> V_166 [ V_71 ] ; V_49 ++ , V_40 ++ ) {
F_160 ( & V_40 -> V_41 ) ;
F_161 ( & V_40 -> V_41 ,
& V_171 [ V_71 ] , V_167 [ V_71 ] ) ;
V_40 -> V_4 = 0 ;
V_40 -> V_46 = 0 ;
V_40 -> V_82 = 0 ;
V_40 -> V_48 = V_49 * V_168 ;
V_40 -> V_47 = ( V_49 + 1 ) * V_168 - 1 ;
if ( V_40 -> V_47 >= V_165 )
V_40 -> V_47 = V_165 - 1 ;
if ( V_71 == 0 ) {
V_40 -> V_172 = 0 ;
V_40 -> V_53 = 0 ;
V_40 -> V_69 = NULL ;
} else {
V_40 -> V_172 = V_49 % V_2 -> V_160 [ V_71 - 1 ] ;
V_40 -> V_53 = 1UL << V_40 -> V_172 ;
V_40 -> V_69 = V_2 -> V_170 [ V_71 - 1 ] +
V_49 / V_2 -> V_160 [ V_71 - 1 ] ;
}
V_40 -> V_170 = V_71 ;
F_162 ( & V_40 -> V_173 ) ;
}
}
V_2 -> V_74 = V_74 ;
V_40 = V_2 -> V_170 [ V_159 - 1 ] ;
F_163 (i) {
while ( V_71 > V_40 -> V_47 )
V_40 ++ ;
F_77 ( V_2 -> V_74 , V_71 ) -> V_52 = V_40 ;
F_143 ( V_71 , V_2 ) ;
}
}
void T_1 F_164 ( void )
{
int V_5 ;
F_165 () ;
F_157 ( & V_12 , & V_8 ) ;
F_157 ( & V_13 , & V_11 ) ;
F_166 () ;
F_167 ( V_122 , F_105 ) ;
F_168 ( F_148 , 0 ) ;
F_169 (cpu)
F_148 ( NULL , V_147 , ( void * ) ( long ) V_5 ) ;
F_58 () ;
}
