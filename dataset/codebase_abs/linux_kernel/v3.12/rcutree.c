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
void F_8 ( int V_5 )
{
F_9 ( F_6 ( L_4 ) ) ;
F_3 ( V_5 ) ;
F_10 ( V_5 ) ;
F_9 ( F_6 ( L_5 ) ) ;
}
long F_11 ( void )
{
return V_11 . V_3 ;
}
long F_12 ( void )
{
return V_12 . V_3 ;
}
void F_13 ( void )
{
F_14 ( & V_12 ) ;
}
void F_15 ( void )
{
V_13 ++ ;
V_14 = 0 ;
}
void F_16 ( unsigned long V_15 )
{
V_14 ++ ;
}
void F_17 ( void )
{
F_14 ( & V_11 ) ;
}
static int
F_18 ( struct V_6 * V_7 )
{
return & V_7 -> V_16 != V_7 -> V_17 [ V_18 ] &&
V_7 -> V_17 [ V_18 ] != NULL ;
}
static int
F_19 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
int V_19 ;
if ( F_1 ( V_2 ) )
return 0 ;
if ( F_20 ( V_2 ) )
return 1 ;
if ( ! V_7 -> V_17 [ V_20 ] )
return 0 ;
if ( * V_7 -> V_17 [ V_21 ] )
return 1 ;
for ( V_19 = V_22 ; V_19 < V_20 ; V_19 ++ )
if ( V_7 -> V_17 [ V_19 - 1 ] != V_7 -> V_17 [ V_19 ] &&
F_21 ( F_2 ( V_2 -> V_3 ) ,
V_7 -> V_23 [ V_19 ] ) )
return 1 ;
return 0 ;
}
static struct V_24 * F_22 ( struct V_1 * V_2 )
{
return & V_2 -> V_25 [ 0 ] ;
}
static void F_23 ( struct V_26 * V_27 , long long V_28 ,
bool V_29 )
{
F_24 ( F_6 ( L_6 ) , V_28 , V_27 -> V_30 ) ;
if ( ! V_29 && ! F_25 ( V_31 ) ) {
struct V_32 * V_33 = F_26 ( F_27 () ) ;
F_24 ( F_6 ( L_7 ) , V_28 , 0 ) ;
F_28 ( V_34 ) ;
F_29 ( 1 , L_8 ,
V_31 -> V_35 , V_31 -> V_36 ,
V_33 -> V_35 , V_33 -> V_36 ) ;
}
F_30 ( F_27 () ) ;
F_31 () ;
F_32 ( & V_27 -> V_37 ) ;
F_33 () ;
F_34 ( F_35 ( & V_27 -> V_37 ) & 0x1 ) ;
F_36 ( ! F_37 ( & V_38 ) ,
L_9 ) ;
F_36 ( ! F_37 ( & V_39 ) ,
L_10 ) ;
F_36 ( ! F_37 ( & V_40 ) ,
L_11 ) ;
}
static void F_38 ( bool V_29 )
{
long long V_28 ;
struct V_26 * V_27 ;
V_27 = & F_39 ( V_26 ) ;
V_28 = V_27 -> V_30 ;
F_34 ( ( V_28 & V_41 ) == 0 ) ;
if ( ( V_28 & V_41 ) == V_42 )
V_27 -> V_30 = 0 ;
else
V_27 -> V_30 -= V_42 ;
F_23 ( V_27 , V_28 , V_29 ) ;
}
void F_40 ( void )
{
unsigned long V_43 ;
F_41 ( V_43 ) ;
F_38 ( false ) ;
F_42 ( & F_39 ( V_26 ) , 0 ) ;
F_43 ( V_43 ) ;
}
void F_44 ( void )
{
F_38 ( 1 ) ;
}
void F_45 ( void )
{
unsigned long V_43 ;
long long V_28 ;
struct V_26 * V_27 ;
F_41 ( V_43 ) ;
V_27 = & F_39 ( V_26 ) ;
V_28 = V_27 -> V_30 ;
V_27 -> V_30 -- ;
F_34 ( V_27 -> V_30 < 0 ) ;
if ( V_27 -> V_30 )
F_24 ( F_6 ( L_12 ) , V_28 , V_27 -> V_30 ) ;
else
F_23 ( V_27 , V_28 , true ) ;
F_42 ( V_27 , 1 ) ;
F_43 ( V_43 ) ;
}
static void F_46 ( struct V_26 * V_27 , long long V_28 ,
int V_29 )
{
F_31 () ;
F_32 ( & V_27 -> V_37 ) ;
F_33 () ;
F_34 ( ! ( F_35 ( & V_27 -> V_37 ) & 0x1 ) ) ;
F_47 ( F_27 () ) ;
F_24 ( F_6 ( L_13 ) , V_28 , V_27 -> V_30 ) ;
if ( ! V_29 && ! F_25 ( V_31 ) ) {
struct V_32 * V_33 = F_26 ( F_27 () ) ;
F_24 ( F_6 ( L_14 ) ,
V_28 , V_27 -> V_30 ) ;
F_28 ( V_34 ) ;
F_29 ( 1 , L_8 ,
V_31 -> V_35 , V_31 -> V_36 ,
V_33 -> V_35 , V_33 -> V_36 ) ;
}
}
static void F_48 ( bool V_29 )
{
struct V_26 * V_27 ;
long long V_28 ;
V_27 = & F_39 ( V_26 ) ;
V_28 = V_27 -> V_30 ;
F_34 ( V_28 < 0 ) ;
if ( V_28 & V_41 )
V_27 -> V_30 += V_42 ;
else
V_27 -> V_30 = V_44 ;
F_46 ( V_27 , V_28 , V_29 ) ;
}
void F_49 ( void )
{
unsigned long V_43 ;
F_41 ( V_43 ) ;
F_48 ( false ) ;
F_50 ( & F_39 ( V_26 ) , 0 ) ;
F_43 ( V_43 ) ;
}
void F_51 ( void )
{
F_48 ( 1 ) ;
}
void F_52 ( void )
{
unsigned long V_43 ;
struct V_26 * V_27 ;
long long V_28 ;
F_41 ( V_43 ) ;
V_27 = & F_39 ( V_26 ) ;
V_28 = V_27 -> V_30 ;
V_27 -> V_30 ++ ;
F_34 ( V_27 -> V_30 == 0 ) ;
if ( V_28 )
F_24 ( F_6 ( L_15 ) , V_28 , V_27 -> V_30 ) ;
else
F_46 ( V_27 , V_28 , true ) ;
F_50 ( V_27 , 1 ) ;
F_43 ( V_43 ) ;
}
void F_53 ( void )
{
struct V_26 * V_27 = & F_39 ( V_26 ) ;
if ( V_27 -> V_45 == 0 &&
( F_35 ( & V_27 -> V_37 ) & 0x1 ) )
return;
V_27 -> V_45 ++ ;
F_31 () ;
F_32 ( & V_27 -> V_37 ) ;
F_33 () ;
F_34 ( ! ( F_35 ( & V_27 -> V_37 ) & 0x1 ) ) ;
}
void F_54 ( void )
{
struct V_26 * V_27 = & F_39 ( V_26 ) ;
if ( V_27 -> V_45 == 0 ||
-- V_27 -> V_45 != 0 )
return;
F_31 () ;
F_32 ( & V_27 -> V_37 ) ;
F_33 () ;
F_34 ( F_35 ( & V_27 -> V_37 ) & 0x1 ) ;
}
int F_55 ( void )
{
int V_46 ;
F_56 () ;
V_46 = ( F_35 ( & F_39 ( V_26 ) . V_37 ) & 0x1 ) == 0 ;
F_57 () ;
return V_46 ;
}
bool F_58 ( void )
{
struct V_6 * V_7 ;
struct V_24 * V_47 ;
bool V_46 ;
if ( F_59 () )
return 1 ;
F_56 () ;
V_7 = & F_39 ( V_8 ) ;
V_47 = V_7 -> V_48 ;
V_46 = ( V_7 -> V_49 & V_47 -> V_50 ) ||
! V_51 ;
F_57 () ;
return V_46 ;
}
static int F_60 ( void )
{
return F_39 ( V_26 ) . V_30 <= 1 ;
}
static int F_61 ( struct V_6 * V_7 ,
bool * V_52 , unsigned long * V_53 )
{
V_7 -> V_54 = F_62 ( 0 , & V_7 -> V_37 -> V_37 ) ;
F_63 ( V_7 , V_52 , V_53 ) ;
return ( V_7 -> V_54 & 0x1 ) == 0 ;
}
static int F_64 ( struct V_6 * V_7 ,
bool * V_52 , unsigned long * V_53 )
{
unsigned int V_55 ;
unsigned int V_56 ;
V_55 = ( unsigned int ) F_62 ( 0 , & V_7 -> V_37 -> V_37 ) ;
V_56 = ( unsigned int ) V_7 -> V_54 ;
if ( ( V_55 & 0x1 ) == 0 || F_65 ( V_55 , V_56 + 2 ) ) {
F_66 ( V_7 -> V_2 -> V_57 , V_7 -> V_4 , V_7 -> V_5 , F_6 ( L_16 ) ) ;
V_7 -> V_58 ++ ;
return 1 ;
}
if ( F_67 ( V_7 -> V_2 -> V_59 + 2 , V_60 ) )
return 0 ;
F_68 () ;
if ( F_69 ( V_7 -> V_5 ) ) {
F_66 ( V_7 -> V_2 -> V_57 , V_7 -> V_4 , V_7 -> V_5 , F_6 ( L_17 ) ) ;
V_7 -> V_61 ++ ;
return 1 ;
}
F_70 ( V_7 -> V_5 ) ;
return 0 ;
}
static void F_71 ( struct V_1 * V_2 )
{
V_2 -> V_59 = V_60 ;
V_2 -> V_62 = V_60 + F_72 () ;
}
static void F_73 ( struct V_1 * V_2 )
{
int V_5 ;
unsigned long V_43 ;
struct V_24 * V_47 ;
F_74 (rsp, rnp) {
F_75 ( & V_47 -> V_63 , V_43 ) ;
if ( V_47 -> V_64 != 0 ) {
for ( V_5 = 0 ; V_5 <= V_47 -> V_65 - V_47 -> V_66 ; V_5 ++ )
if ( V_47 -> V_64 & ( 1UL << V_5 ) )
F_76 ( V_47 -> V_66 + V_5 ) ;
}
F_77 ( & V_47 -> V_63 , V_43 ) ;
}
}
static void F_78 ( struct V_1 * V_2 )
{
int V_5 ;
long V_67 ;
unsigned long V_43 ;
int V_68 = 0 ;
struct V_24 * V_47 = F_22 ( V_2 ) ;
long V_69 = 0 ;
F_75 ( & V_47 -> V_63 , V_43 ) ;
V_67 = V_60 - V_2 -> V_62 ;
if ( V_67 < V_70 || ! F_1 ( V_2 ) ) {
F_77 ( & V_47 -> V_63 , V_43 ) ;
return;
}
V_2 -> V_62 = V_60 + 3 * F_72 () + 3 ;
F_77 ( & V_47 -> V_63 , V_43 ) ;
F_79 ( L_18 ,
V_2 -> V_57 ) ;
F_80 () ;
F_74 (rsp, rnp) {
F_75 ( & V_47 -> V_63 , V_43 ) ;
V_68 += F_81 ( V_47 ) ;
if ( V_47 -> V_64 != 0 ) {
for ( V_5 = 0 ; V_5 <= V_47 -> V_65 - V_47 -> V_66 ; V_5 ++ )
if ( V_47 -> V_64 & ( 1UL << V_5 ) ) {
F_82 ( V_2 ,
V_47 -> V_66 + V_5 ) ;
V_68 ++ ;
}
}
F_77 ( & V_47 -> V_63 , V_43 ) ;
}
V_47 = F_22 ( V_2 ) ;
F_75 ( & V_47 -> V_63 , V_43 ) ;
V_68 += F_81 ( V_47 ) ;
F_77 ( & V_47 -> V_63 , V_43 ) ;
F_83 () ;
F_84 (cpu)
V_69 += F_85 ( V_2 -> V_71 , V_5 ) -> V_72 ;
F_86 ( L_19 ,
F_27 () , ( long ) ( V_60 - V_2 -> V_59 ) ,
V_2 -> V_4 , V_2 -> V_3 , V_69 ) ;
if ( V_68 == 0 )
F_79 ( L_20 ) ;
else if ( ! F_87 () )
F_73 ( V_2 ) ;
F_88 ( V_2 ) ;
F_14 ( V_2 ) ;
}
static void F_89 ( struct V_1 * V_2 )
{
int V_5 ;
unsigned long V_43 ;
struct V_24 * V_47 = F_22 ( V_2 ) ;
long V_69 = 0 ;
F_79 ( L_21 , V_2 -> V_57 ) ;
F_80 () ;
F_82 ( V_2 , F_27 () ) ;
F_83 () ;
F_84 (cpu)
V_69 += F_85 ( V_2 -> V_71 , V_5 ) -> V_72 ;
F_86 ( L_22 ,
V_60 - V_2 -> V_59 , V_2 -> V_4 , V_2 -> V_3 , V_69 ) ;
if ( ! F_87 () )
F_90 () ;
F_75 ( & V_47 -> V_63 , V_43 ) ;
if ( F_67 ( V_60 , V_2 -> V_62 ) )
V_2 -> V_62 = V_60 +
3 * F_72 () + 3 ;
F_77 ( & V_47 -> V_63 , V_43 ) ;
F_91 () ;
}
static void F_92 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
unsigned long V_73 ;
unsigned long V_74 ;
struct V_24 * V_47 ;
if ( V_75 )
return;
V_73 = F_2 ( V_60 ) ;
V_74 = F_2 ( V_2 -> V_62 ) ;
V_47 = V_7 -> V_48 ;
if ( F_1 ( V_2 ) &&
( F_2 ( V_47 -> V_64 ) & V_7 -> V_49 ) && F_67 ( V_73 , V_74 ) ) {
F_89 ( V_2 ) ;
} else if ( F_1 ( V_2 ) &&
F_67 ( V_73 , V_74 + V_70 ) ) {
F_78 ( V_2 ) ;
}
}
void F_93 ( void )
{
struct V_1 * V_2 ;
F_94 (rsp)
V_2 -> V_62 = V_60 + V_76 / 2 ;
}
static void F_95 ( struct V_6 * V_7 )
{
int V_19 ;
if ( F_96 ( V_7 ) )
return;
V_7 -> V_16 = NULL ;
for ( V_19 = 0 ; V_19 < V_77 ; V_19 ++ )
V_7 -> V_17 [ V_19 ] = & V_7 -> V_16 ;
}
static unsigned long F_97 ( struct V_1 * V_2 ,
struct V_24 * V_47 )
{
if ( F_22 ( V_2 ) == V_47 && V_47 -> V_4 == V_47 -> V_3 )
return V_47 -> V_3 + 1 ;
return V_47 -> V_3 + 2 ;
}
static void F_98 ( struct V_24 * V_47 , struct V_6 * V_7 ,
unsigned long V_78 , const char * V_79 )
{
F_99 ( V_7 -> V_2 -> V_57 , V_47 -> V_4 ,
V_47 -> V_3 , V_78 , V_47 -> V_80 ,
V_47 -> V_66 , V_47 -> V_65 , V_79 ) ;
}
static unsigned long T_1
F_100 ( struct V_24 * V_47 , struct V_6 * V_7 )
{
unsigned long V_78 ;
int V_19 ;
struct V_24 * V_81 = F_22 ( V_7 -> V_2 ) ;
V_78 = F_97 ( V_7 -> V_2 , V_47 ) ;
F_98 ( V_47 , V_7 , V_78 , F_6 ( L_23 ) ) ;
if ( V_47 -> V_82 [ V_78 & 0x1 ] ) {
F_98 ( V_47 , V_7 , V_78 , F_6 ( L_24 ) ) ;
return V_78 ;
}
if ( V_47 -> V_4 != V_47 -> V_3 ||
F_2 ( V_47 -> V_4 ) != F_2 ( V_47 -> V_3 ) ) {
V_47 -> V_82 [ V_78 & 0x1 ] ++ ;
F_98 ( V_47 , V_7 , V_78 , F_6 ( L_25 ) ) ;
return V_78 ;
}
if ( V_47 != V_81 )
F_101 ( & V_81 -> V_63 ) ;
V_78 = F_97 ( V_7 -> V_2 , V_81 ) ;
for ( V_19 = V_18 ; V_19 < V_20 ; V_19 ++ )
if ( F_21 ( V_78 , V_7 -> V_23 [ V_19 ] ) )
V_7 -> V_23 [ V_19 ] = V_78 ;
if ( V_81 -> V_82 [ V_78 & 0x1 ] ) {
F_98 ( V_47 , V_7 , V_78 , F_6 ( L_26 ) ) ;
goto V_83;
}
V_81 -> V_82 [ V_78 & 0x1 ] ++ ;
if ( V_81 -> V_4 != V_81 -> V_3 ) {
F_98 ( V_47 , V_7 , V_78 , F_6 ( L_27 ) ) ;
} else {
F_98 ( V_47 , V_7 , V_78 , F_6 ( L_28 ) ) ;
F_102 ( V_7 -> V_2 , V_81 , V_7 ) ;
}
V_83:
if ( V_47 != V_81 )
F_103 ( & V_81 -> V_63 ) ;
return V_78 ;
}
static int F_104 ( struct V_1 * V_2 , struct V_24 * V_47 )
{
int V_78 = V_47 -> V_3 ;
int V_84 ;
struct V_6 * V_7 = F_105 ( V_2 -> V_71 ) ;
F_106 ( V_2 , V_47 ) ;
V_47 -> V_82 [ V_78 & 0x1 ] = 0 ;
V_84 = V_47 -> V_82 [ ( V_78 + 1 ) & 0x1 ] ;
F_98 ( V_47 , V_7 , V_78 ,
V_84 ? F_6 ( L_29 ) : F_6 ( L_30 ) ) ;
return V_84 ;
}
static void F_107 ( struct V_1 * V_2 , struct V_24 * V_47 ,
struct V_6 * V_7 )
{
unsigned long V_78 ;
int V_19 ;
if ( ! V_7 -> V_17 [ V_20 ] || ! * V_7 -> V_17 [ V_18 ] )
return;
V_78 = F_97 ( V_2 , V_47 ) ;
for ( V_19 = V_20 - 1 ; V_19 > V_18 ; V_19 -- )
if ( V_7 -> V_17 [ V_19 ] != V_7 -> V_17 [ V_19 - 1 ] &&
! F_67 ( V_7 -> V_23 [ V_19 ] , V_78 ) )
break;
if ( ++ V_19 >= V_20 )
return;
for (; V_19 <= V_20 ; V_19 ++ ) {
V_7 -> V_17 [ V_19 ] = V_7 -> V_17 [ V_20 ] ;
V_7 -> V_23 [ V_19 ] = V_78 ;
}
F_100 ( V_47 , V_7 ) ;
if ( ! * V_7 -> V_17 [ V_22 ] )
F_5 ( V_2 -> V_57 , V_7 -> V_4 , F_6 ( L_31 ) ) ;
else
F_5 ( V_2 -> V_57 , V_7 -> V_4 , F_6 ( L_32 ) ) ;
}
static void F_108 ( struct V_1 * V_2 , struct V_24 * V_47 ,
struct V_6 * V_7 )
{
int V_19 , V_73 ;
if ( ! V_7 -> V_17 [ V_20 ] || ! * V_7 -> V_17 [ V_18 ] )
return;
for ( V_19 = V_22 ; V_19 < V_20 ; V_19 ++ ) {
if ( F_21 ( V_47 -> V_3 , V_7 -> V_23 [ V_19 ] ) )
break;
V_7 -> V_17 [ V_18 ] = V_7 -> V_17 [ V_19 ] ;
}
for ( V_73 = V_22 ; V_73 < V_19 ; V_73 ++ )
V_7 -> V_17 [ V_73 ] = V_7 -> V_17 [ V_18 ] ;
for ( V_73 = V_22 ; V_19 < V_20 ; V_19 ++ , V_73 ++ ) {
if ( V_7 -> V_17 [ V_73 ] == V_7 -> V_17 [ V_20 ] )
break;
V_7 -> V_17 [ V_73 ] = V_7 -> V_17 [ V_19 ] ;
V_7 -> V_23 [ V_73 ] = V_7 -> V_23 [ V_19 ] ;
}
F_107 ( V_2 , V_47 , V_7 ) ;
}
static void F_109 ( struct V_1 * V_2 , struct V_24 * V_47 , struct V_6 * V_7 )
{
if ( V_7 -> V_3 == V_47 -> V_3 ) {
F_107 ( V_2 , V_47 , V_7 ) ;
} else {
F_108 ( V_2 , V_47 , V_7 ) ;
V_7 -> V_3 = V_47 -> V_3 ;
F_5 ( V_2 -> V_57 , V_7 -> V_4 , F_6 ( L_33 ) ) ;
}
if ( V_7 -> V_4 != V_47 -> V_4 ) {
V_7 -> V_4 = V_47 -> V_4 ;
F_5 ( V_2 -> V_57 , V_7 -> V_4 , F_6 ( L_34 ) ) ;
V_7 -> V_9 = 0 ;
V_7 -> V_85 = ! ! ( V_47 -> V_64 & V_7 -> V_49 ) ;
F_110 ( V_7 ) ;
}
}
static void F_111 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
unsigned long V_43 ;
struct V_24 * V_47 ;
F_41 ( V_43 ) ;
V_47 = V_7 -> V_48 ;
if ( ( V_7 -> V_4 == F_2 ( V_47 -> V_4 ) &&
V_7 -> V_3 == F_2 ( V_47 -> V_3 ) ) ||
! F_112 ( & V_47 -> V_63 ) ) {
F_43 ( V_43 ) ;
return;
}
F_109 ( V_2 , V_47 , V_7 ) ;
F_77 ( & V_47 -> V_63 , V_43 ) ;
}
static int F_113 ( struct V_1 * V_2 )
{
struct V_6 * V_7 ;
struct V_24 * V_47 = F_22 ( V_2 ) ;
F_114 () ;
F_115 ( & V_47 -> V_63 ) ;
V_2 -> V_86 = 0 ;
if ( F_1 ( V_2 ) ) {
F_116 ( & V_47 -> V_63 ) ;
return 0 ;
}
V_2 -> V_4 ++ ;
F_5 ( V_2 -> V_57 , V_2 -> V_4 , F_6 ( L_35 ) ) ;
F_71 ( V_2 ) ;
F_116 ( & V_47 -> V_63 ) ;
F_117 ( & V_2 -> V_87 ) ;
F_118 (rsp, rnp) {
F_115 ( & V_47 -> V_63 ) ;
V_7 = F_105 ( V_2 -> V_71 ) ;
F_119 ( V_47 ) ;
V_47 -> V_64 = V_47 -> V_50 ;
F_2 ( V_47 -> V_4 ) = V_2 -> V_4 ;
F_34 ( V_47 -> V_3 != V_2 -> V_3 ) ;
F_2 ( V_47 -> V_3 ) = V_2 -> V_3 ;
if ( V_47 == V_7 -> V_48 )
F_109 ( V_2 , V_47 , V_7 ) ;
F_120 ( V_47 ) ;
F_121 ( V_2 -> V_57 , V_47 -> V_4 ,
V_47 -> V_80 , V_47 -> V_66 ,
V_47 -> V_65 , V_47 -> V_64 ) ;
F_116 ( & V_47 -> V_63 ) ;
#ifdef F_122
if ( ( F_123 () % ( V_88 + 1 ) ) == 0 &&
V_89 == V_90 )
F_124 ( 200 ) ;
#endif
F_125 () ;
}
F_126 ( & V_2 -> V_87 ) ;
return 1 ;
}
int F_127 ( struct V_1 * V_2 , int V_91 )
{
int V_92 = V_91 ;
bool V_52 = false ;
unsigned long V_53 ;
struct V_24 * V_47 = F_22 ( V_2 ) ;
V_2 -> V_93 ++ ;
if ( V_92 == V_94 ) {
if ( F_128 ( V_2 ) ) {
V_52 = 1 ;
V_53 = V_60 - V_76 / 4 ;
}
F_129 ( V_2 , F_61 ,
& V_52 , & V_53 ) ;
F_130 ( V_2 , V_52 , V_53 ) ;
V_92 = V_95 ;
} else {
V_52 = 0 ;
F_129 ( V_2 , F_64 , & V_52 , & V_53 ) ;
}
if ( F_2 ( V_2 -> V_86 ) & V_96 ) {
F_115 ( & V_47 -> V_63 ) ;
V_2 -> V_86 &= ~ V_96 ;
F_116 ( & V_47 -> V_63 ) ;
}
return V_92 ;
}
static void F_131 ( struct V_1 * V_2 )
{
unsigned long V_97 ;
int V_98 = 0 ;
struct V_6 * V_7 ;
struct V_24 * V_47 = F_22 ( V_2 ) ;
F_115 ( & V_47 -> V_63 ) ;
V_97 = V_60 - V_2 -> V_59 ;
if ( V_97 > V_2 -> V_99 )
V_2 -> V_99 = V_97 ;
F_116 ( & V_47 -> V_63 ) ;
F_118 (rsp, rnp) {
F_115 ( & V_47 -> V_63 ) ;
F_2 ( V_47 -> V_3 ) = V_2 -> V_4 ;
V_7 = F_105 ( V_2 -> V_71 ) ;
if ( V_47 == V_7 -> V_48 )
F_109 ( V_2 , V_47 , V_7 ) ;
V_98 += F_104 ( V_2 , V_47 ) ;
F_116 ( & V_47 -> V_63 ) ;
F_125 () ;
}
V_47 = F_22 ( V_2 ) ;
F_115 ( & V_47 -> V_63 ) ;
F_132 ( V_47 , V_98 ) ;
V_2 -> V_3 = V_2 -> V_4 ;
F_5 ( V_2 -> V_57 , V_2 -> V_3 , F_6 ( L_36 ) ) ;
V_2 -> V_92 = V_100 ;
V_7 = F_105 ( V_2 -> V_71 ) ;
F_108 ( V_2 , V_47 , V_7 ) ;
if ( F_19 ( V_2 , V_7 ) )
V_2 -> V_86 = 1 ;
F_116 ( & V_47 -> V_63 ) ;
}
static int T_2 F_133 ( void * V_101 )
{
int V_92 ;
unsigned long V_73 ;
int V_46 ;
struct V_1 * V_2 = V_101 ;
struct V_24 * V_47 = F_22 ( V_2 ) ;
for (; ; ) {
for (; ; ) {
F_134 ( V_2 -> V_102 ,
V_2 -> V_86 &
V_103 ) ;
if ( ( V_2 -> V_86 & V_103 ) &&
F_113 ( V_2 ) )
break;
F_125 () ;
F_135 ( V_31 ) ;
}
V_92 = V_94 ;
V_73 = V_104 ;
if ( V_73 > V_105 ) {
V_73 = V_105 ;
V_104 = V_105 ;
}
for (; ; ) {
V_2 -> V_106 = V_60 + V_73 ;
V_46 = F_136 ( V_2 -> V_102 ,
( V_2 -> V_86 & V_96 ) ||
( ! F_2 ( V_47 -> V_64 ) &&
! F_137 ( V_47 ) ) ,
V_73 ) ;
if ( ! F_2 ( V_47 -> V_64 ) &&
! F_137 ( V_47 ) )
break;
if ( V_46 == 0 || ( V_2 -> V_86 & V_96 ) ) {
V_92 = F_127 ( V_2 , V_92 ) ;
F_125 () ;
} else {
F_125 () ;
F_135 ( V_31 ) ;
}
V_73 = V_107 ;
if ( V_73 > V_105 ) {
V_73 = V_105 ;
V_107 = V_105 ;
} else if ( V_73 < 1 ) {
V_73 = 1 ;
V_107 = 1 ;
}
}
F_131 ( V_2 ) ;
}
}
static void F_138 ( struct V_108 * V_109 )
{
struct V_1 * V_2 = F_139 ( V_109 , struct V_1 , V_110 ) ;
F_140 ( & V_2 -> V_102 ) ;
}
static void
F_102 ( struct V_1 * V_2 , struct V_24 * V_47 ,
struct V_6 * V_7 )
{
if ( ! V_2 -> V_111 || ! F_19 ( V_2 , V_7 ) ) {
return;
}
V_2 -> V_86 = V_103 ;
if ( V_31 != V_2 -> V_111 )
F_141 ( & V_2 -> V_110 ) ;
}
static void
F_142 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_105 ( V_2 -> V_71 ) ;
struct V_24 * V_47 = F_22 ( V_2 ) ;
F_108 ( V_2 , V_47 , V_7 ) ;
F_102 ( V_2 , V_47 , V_7 ) ;
}
static void F_143 ( struct V_1 * V_2 , unsigned long V_43 )
__releases( rcu_get_root( V_2 )->lock
static void
F_144 ( unsigned long V_112 , struct V_1 * V_2 ,
struct V_24 * V_47 , unsigned long V_43 )
__releases( V_47 -> V_63 )
{
struct V_24 * V_113 ;
for (; ; ) {
if ( ! ( V_47 -> V_64 & V_112 ) ) {
F_77 ( & V_47 -> V_63 , V_43 ) ;
return;
}
V_47 -> V_64 &= ~ V_112 ;
F_145 ( V_2 -> V_57 , V_47 -> V_4 ,
V_112 , V_47 -> V_64 , V_47 -> V_80 ,
V_47 -> V_66 , V_47 -> V_65 ,
! ! V_47 -> V_114 ) ;
if ( V_47 -> V_64 != 0 || F_137 ( V_47 ) ) {
F_77 ( & V_47 -> V_63 , V_43 ) ;
return;
}
V_112 = V_47 -> V_49 ;
if ( V_47 -> V_115 == NULL ) {
break;
}
F_77 ( & V_47 -> V_63 , V_43 ) ;
V_113 = V_47 ;
V_47 = V_47 -> V_115 ;
F_75 ( & V_47 -> V_63 , V_43 ) ;
F_34 ( V_113 -> V_64 ) ;
}
F_143 ( V_2 , V_43 ) ;
}
static void
F_146 ( int V_5 , struct V_1 * V_2 , struct V_6 * V_7 )
{
unsigned long V_43 ;
unsigned long V_112 ;
struct V_24 * V_47 ;
V_47 = V_7 -> V_48 ;
F_75 ( & V_47 -> V_63 , V_43 ) ;
if ( V_7 -> V_9 == 0 || V_7 -> V_4 != V_47 -> V_4 ||
V_47 -> V_3 == V_47 -> V_4 ) {
V_7 -> V_9 = 0 ;
F_77 ( & V_47 -> V_63 , V_43 ) ;
return;
}
V_112 = V_7 -> V_49 ;
if ( ( V_47 -> V_64 & V_112 ) == 0 ) {
F_77 ( & V_47 -> V_63 , V_43 ) ;
} else {
V_7 -> V_85 = 0 ;
F_107 ( V_2 , V_47 , V_7 ) ;
F_144 ( V_112 , V_2 , V_47 , V_43 ) ;
}
}
static void
F_147 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
F_111 ( V_2 , V_7 ) ;
if ( ! V_7 -> V_85 )
return;
if ( ! V_7 -> V_9 )
return;
F_146 ( V_7 -> V_5 , V_2 , V_7 ) ;
}
static void
F_148 ( int V_5 , struct V_1 * V_2 ,
struct V_24 * V_47 , struct V_6 * V_7 )
{
if ( F_149 ( V_7 -> V_5 ) )
return;
if ( V_7 -> V_16 != NULL ) {
V_2 -> V_116 += V_7 -> V_116 ;
V_2 -> V_72 += V_7 -> V_72 ;
V_7 -> V_117 += V_7 -> V_72 ;
V_7 -> V_116 = 0 ;
F_2 ( V_7 -> V_72 ) = 0 ;
}
if ( * V_7 -> V_17 [ V_18 ] != NULL ) {
* V_2 -> V_118 = * V_7 -> V_17 [ V_18 ] ;
V_2 -> V_118 = V_7 -> V_17 [ V_20 ] ;
* V_7 -> V_17 [ V_18 ] = NULL ;
}
if ( V_7 -> V_16 != NULL ) {
* V_2 -> V_119 = V_7 -> V_16 ;
V_2 -> V_119 = V_7 -> V_17 [ V_18 ] ;
}
F_95 ( V_7 ) ;
}
static void F_150 ( struct V_1 * V_2 )
{
int V_19 ;
struct V_6 * V_7 = F_151 ( V_2 -> V_71 ) ;
if ( F_152 ( V_2 , V_7 ) )
return;
V_7 -> V_116 += V_2 -> V_116 ;
V_7 -> V_72 += V_2 -> V_72 ;
V_7 -> V_120 += V_2 -> V_72 ;
if ( V_2 -> V_116 != V_2 -> V_72 )
F_153 () ;
V_2 -> V_116 = 0 ;
V_2 -> V_72 = 0 ;
if ( V_2 -> V_121 != NULL ) {
* V_2 -> V_119 = * V_7 -> V_17 [ V_18 ] ;
* V_7 -> V_17 [ V_18 ] = V_2 -> V_121 ;
for ( V_19 = V_77 - 1 ; V_19 >= V_18 ; V_19 -- )
if ( V_7 -> V_17 [ V_19 ] == V_7 -> V_17 [ V_18 ] )
V_7 -> V_17 [ V_19 ] = V_2 -> V_119 ;
V_2 -> V_121 = NULL ;
V_2 -> V_119 = & V_2 -> V_121 ;
}
if ( V_2 -> V_122 != NULL ) {
* V_7 -> V_17 [ V_20 ] = V_2 -> V_122 ;
V_7 -> V_17 [ V_20 ] = V_2 -> V_118 ;
V_2 -> V_122 = NULL ;
V_2 -> V_118 = & V_2 -> V_122 ;
}
}
static void F_154 ( struct V_1 * V_2 )
{
F_155 (unsigned long mask) ;
F_155 ( struct V_6 * V_7 = F_105 ( V_2 -> V_71 ) ) ;
F_155 ( struct V_24 * V_47 = V_7 -> V_48 ) ;
F_155 ( V_112 = V_7 -> V_49 ) ;
F_5 ( V_2 -> V_57 ,
V_47 -> V_4 + 1 - ! ! ( V_47 -> V_64 & V_112 ) ,
F_6 ( L_37 ) ) ;
}
static void F_156 ( int V_5 , struct V_1 * V_2 )
{
unsigned long V_43 ;
unsigned long V_112 ;
int V_123 = 0 ;
struct V_6 * V_7 = F_85 ( V_2 -> V_71 , V_5 ) ;
struct V_24 * V_47 = V_7 -> V_48 ;
F_157 ( V_47 , - 1 ) ;
F_117 ( & V_2 -> V_87 ) ;
F_75 ( & V_2 -> V_124 , V_43 ) ;
F_148 ( V_5 , V_2 , V_47 , V_7 ) ;
F_150 ( V_2 ) ;
V_112 = V_7 -> V_49 ;
do {
F_101 ( & V_47 -> V_63 ) ;
V_47 -> V_50 &= ~ V_112 ;
if ( V_47 -> V_50 != 0 ) {
if ( V_47 != V_7 -> V_48 )
F_103 ( & V_47 -> V_63 ) ;
break;
}
if ( V_47 == V_7 -> V_48 )
V_123 = F_158 ( V_2 , V_47 , V_7 ) ;
else
F_103 ( & V_47 -> V_63 ) ;
V_112 = V_47 -> V_49 ;
V_47 = V_47 -> V_115 ;
} while ( V_47 != NULL );
F_103 ( & V_2 -> V_124 ) ;
V_47 = V_7 -> V_48 ;
if ( V_123 & V_125 )
F_159 ( V_47 , V_43 ) ;
else
F_77 ( & V_47 -> V_63 , V_43 ) ;
if ( V_123 & V_126 )
F_160 ( V_2 , V_47 , true ) ;
F_29 ( V_7 -> V_72 != 0 || V_7 -> V_16 != NULL ,
L_38 ,
V_5 , V_7 -> V_72 , V_7 -> V_16 ) ;
F_95 ( V_7 ) ;
V_7 -> V_17 [ V_20 ] = NULL ;
F_126 ( & V_2 -> V_87 ) ;
}
static void F_154 ( struct V_1 * V_2 )
{
}
static void F_156 ( int V_5 , struct V_1 * V_2 )
{
}
static void F_161 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
unsigned long V_43 ;
struct V_127 * V_128 , * V_129 , * * V_130 ;
long V_131 , V_132 , V_133 ;
int V_19 ;
if ( ! F_18 ( V_7 ) ) {
F_162 ( V_2 -> V_57 , V_7 -> V_116 , V_7 -> V_72 , 0 ) ;
F_163 ( V_2 -> V_57 , 0 , ! ! F_2 ( V_7 -> V_16 ) ,
F_164 () , F_25 ( V_31 ) ,
F_165 () ) ;
return;
}
F_41 ( V_43 ) ;
F_34 ( F_69 ( F_27 () ) ) ;
V_131 = V_7 -> V_134 ;
F_162 ( V_2 -> V_57 , V_7 -> V_116 , V_7 -> V_72 , V_131 ) ;
V_129 = V_7 -> V_16 ;
V_7 -> V_16 = * V_7 -> V_17 [ V_18 ] ;
* V_7 -> V_17 [ V_18 ] = NULL ;
V_130 = V_7 -> V_17 [ V_18 ] ;
for ( V_19 = V_77 - 1 ; V_19 >= 0 ; V_19 -- )
if ( V_7 -> V_17 [ V_19 ] == V_7 -> V_17 [ V_18 ] )
V_7 -> V_17 [ V_19 ] = & V_7 -> V_16 ;
F_43 ( V_43 ) ;
V_132 = V_133 = 0 ;
while ( V_129 ) {
V_128 = V_129 -> V_128 ;
F_166 ( V_128 ) ;
F_167 ( V_129 ) ;
if ( F_168 ( V_2 -> V_57 , V_129 ) )
V_133 ++ ;
V_129 = V_128 ;
if ( ++ V_132 >= V_131 &&
( F_164 () ||
( ! F_25 ( V_31 ) && ! F_165 () ) ) )
break;
}
F_41 ( V_43 ) ;
F_163 ( V_2 -> V_57 , V_132 , ! ! V_129 , F_164 () ,
F_25 ( V_31 ) ,
F_165 () ) ;
if ( V_129 != NULL ) {
* V_130 = V_7 -> V_16 ;
V_7 -> V_16 = V_129 ;
for ( V_19 = 0 ; V_19 < V_77 ; V_19 ++ )
if ( & V_7 -> V_16 == V_7 -> V_17 [ V_19 ] )
V_7 -> V_17 [ V_19 ] = V_130 ;
else
break;
}
F_169 () ;
V_7 -> V_116 -= V_133 ;
F_2 ( V_7 -> V_72 ) -= V_132 ;
V_7 -> V_135 += V_132 ;
if ( V_7 -> V_134 == V_136 && V_7 -> V_72 <= V_137 )
V_7 -> V_134 = V_134 ;
if ( V_7 -> V_72 == 0 && V_7 -> V_138 != 0 ) {
V_7 -> V_138 = 0 ;
V_7 -> V_139 = V_2 -> V_93 ;
} else if ( V_7 -> V_72 < V_7 -> V_138 - V_140 )
V_7 -> V_138 = V_7 -> V_72 ;
F_34 ( ( V_7 -> V_16 == NULL ) != ( V_7 -> V_72 == 0 ) ) ;
F_43 ( V_43 ) ;
if ( F_18 ( V_7 ) )
F_170 () ;
}
void F_171 ( int V_5 , int V_29 )
{
F_9 ( F_6 ( L_39 ) ) ;
F_172 () ;
if ( V_29 || F_60 () ) {
F_3 ( V_5 ) ;
F_7 ( V_5 ) ;
} else if ( ! F_173 () ) {
F_7 ( V_5 ) ;
}
F_174 ( V_5 ) ;
if ( F_175 ( V_5 ) )
F_170 () ;
F_9 ( F_6 ( L_40 ) ) ;
}
static void F_129 ( struct V_1 * V_2 ,
int (* F_176)( struct V_6 * V_2 , bool * V_52 ,
unsigned long * V_53 ) ,
bool * V_52 , unsigned long * V_53 )
{
unsigned long V_141 ;
int V_5 ;
unsigned long V_43 ;
unsigned long V_112 ;
struct V_24 * V_47 ;
F_74 (rsp, rnp) {
F_125 () ;
V_112 = 0 ;
F_75 ( & V_47 -> V_63 , V_43 ) ;
if ( ! F_1 ( V_2 ) ) {
F_77 ( & V_47 -> V_63 , V_43 ) ;
return;
}
if ( V_47 -> V_64 == 0 ) {
F_177 ( V_47 , V_43 ) ;
continue;
}
V_5 = V_47 -> V_66 ;
V_141 = 1 ;
for (; V_5 <= V_47 -> V_65 ; V_5 ++ , V_141 <<= 1 ) {
if ( ( V_47 -> V_64 & V_141 ) != 0 ) {
if ( ( V_47 -> V_50 & V_141 ) != 0 )
* V_52 = 0 ;
if ( F_176 ( F_85 ( V_2 -> V_71 , V_5 ) , V_52 , V_53 ) )
V_112 |= V_141 ;
}
}
if ( V_112 != 0 ) {
F_144 ( V_112 , V_2 , V_47 , V_43 ) ;
continue;
}
F_77 ( & V_47 -> V_63 , V_43 ) ;
}
V_47 = F_22 ( V_2 ) ;
if ( V_47 -> V_64 == 0 ) {
F_75 ( & V_47 -> V_63 , V_43 ) ;
F_177 ( V_47 , V_43 ) ;
}
}
static void F_14 ( struct V_1 * V_2 )
{
unsigned long V_43 ;
bool V_46 ;
struct V_24 * V_47 ;
struct V_24 * V_142 = NULL ;
V_47 = F_85 ( V_2 -> V_71 , F_178 () ) -> V_48 ;
for (; V_47 != NULL ; V_47 = V_47 -> V_115 ) {
V_46 = ( F_2 ( V_2 -> V_86 ) & V_96 ) ||
! F_112 ( & V_47 -> V_143 ) ;
if ( V_142 != NULL )
F_103 ( & V_142 -> V_143 ) ;
if ( V_46 ) {
V_2 -> V_144 ++ ;
return;
}
V_142 = V_47 ;
}
F_75 ( & V_142 -> V_63 , V_43 ) ;
F_103 ( & V_142 -> V_143 ) ;
if ( F_2 ( V_2 -> V_86 ) & V_96 ) {
V_2 -> V_144 ++ ;
F_77 ( & V_142 -> V_63 , V_43 ) ;
return;
}
V_2 -> V_86 |= V_96 ;
F_77 ( & V_142 -> V_63 , V_43 ) ;
F_140 ( & V_2 -> V_102 ) ;
}
static void
F_179 ( struct V_1 * V_2 )
{
unsigned long V_43 ;
struct V_6 * V_7 = F_151 ( V_2 -> V_71 ) ;
F_34 ( V_7 -> V_145 == 0 ) ;
F_147 ( V_2 , V_7 ) ;
F_41 ( V_43 ) ;
if ( F_19 ( V_2 , V_7 ) ) {
F_101 ( & F_22 ( V_2 ) -> V_63 ) ;
F_142 ( V_2 ) ;
F_77 ( & F_22 ( V_2 ) -> V_63 , V_43 ) ;
} else {
F_43 ( V_43 ) ;
}
if ( F_18 ( V_7 ) )
F_180 ( V_2 , V_7 ) ;
}
static void F_181 ( struct V_146 * V_147 )
{
struct V_1 * V_2 ;
if ( F_69 ( F_27 () ) )
return;
F_9 ( F_6 ( L_41 ) ) ;
F_94 (rsp)
F_179 ( V_2 ) ;
F_9 ( F_6 ( L_42 ) ) ;
}
static void F_180 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
if ( F_182 ( ! F_2 ( V_51 ) ) )
return;
if ( F_183 ( ! V_2 -> V_148 ) ) {
F_161 ( V_2 , V_7 ) ;
return;
}
F_184 () ;
}
static void F_170 ( void )
{
if ( F_185 ( F_27 () ) )
F_186 ( V_149 ) ;
}
static void F_187 ( struct V_1 * V_2 , struct V_6 * V_7 ,
struct V_127 * V_150 , unsigned long V_43 )
{
if ( F_55 () && F_185 ( F_27 () ) )
F_170 () ;
if ( F_188 ( V_43 ) || F_69 ( F_27 () ) )
return;
if ( F_182 ( V_7 -> V_72 > V_7 -> V_138 + V_140 ) ) {
F_111 ( V_2 , V_7 ) ;
if ( ! F_1 ( V_2 ) ) {
struct V_24 * V_81 = F_22 ( V_2 ) ;
F_101 ( & V_81 -> V_63 ) ;
F_142 ( V_2 ) ;
F_103 ( & V_81 -> V_63 ) ;
} else {
V_7 -> V_134 = V_136 ;
if ( V_2 -> V_93 == V_7 -> V_139 &&
* V_7 -> V_17 [ V_18 ] != V_150 )
F_14 ( V_2 ) ;
V_7 -> V_139 = V_2 -> V_93 ;
V_7 -> V_138 = V_7 -> V_72 ;
}
}
}
static void F_189 ( struct V_127 * V_151 )
{
}
static void
F_190 ( struct V_127 * V_150 , void (* F_191)( struct V_127 * V_152 ) ,
struct V_1 * V_2 , int V_5 , bool V_153 )
{
unsigned long V_43 ;
struct V_6 * V_7 ;
F_34 ( ( unsigned long ) V_150 & 0x3 ) ;
if ( F_192 ( V_150 ) ) {
F_2 ( V_150 -> F_191 ) = F_189 ;
F_29 ( 1 , L_43 ) ;
return;
}
V_150 -> F_191 = F_191 ;
V_150 -> V_128 = NULL ;
F_41 ( V_43 ) ;
V_7 = F_105 ( V_2 -> V_71 ) ;
if ( F_182 ( V_7 -> V_17 [ V_20 ] == NULL ) || V_5 != - 1 ) {
int V_154 ;
if ( V_5 != - 1 )
V_7 = F_85 ( V_2 -> V_71 , V_5 ) ;
V_154 = ! F_193 ( V_7 , V_150 , V_153 ) ;
F_34 ( V_154 ) ;
F_43 ( V_43 ) ;
return;
}
F_2 ( V_7 -> V_72 ) ++ ;
if ( V_153 )
V_7 -> V_116 ++ ;
else
F_153 () ;
F_169 () ;
* V_7 -> V_17 [ V_20 ] = V_150 ;
V_7 -> V_17 [ V_20 ] = & V_150 -> V_128 ;
if ( F_194 ( ( unsigned long ) F_191 ) )
F_195 ( V_2 -> V_57 , V_150 , ( unsigned long ) F_191 ,
V_7 -> V_116 , V_7 -> V_72 ) ;
else
F_196 ( V_2 -> V_57 , V_150 , V_7 -> V_116 , V_7 -> V_72 ) ;
F_187 ( V_2 , V_7 , V_150 , V_43 ) ;
F_43 ( V_43 ) ;
}
void F_197 ( struct V_127 * V_150 , void (* F_191)( struct V_127 * V_152 ) )
{
F_190 ( V_150 , F_191 , & V_11 , - 1 , 0 ) ;
}
void F_198 ( struct V_127 * V_150 , void (* F_191)( struct V_127 * V_152 ) )
{
F_190 ( V_150 , F_191 , & V_12 , - 1 , 0 ) ;
}
static inline int F_199 ( void )
{
int V_46 ;
F_200 () ;
F_56 () ;
V_46 = F_201 () <= 1 ;
F_57 () ;
return V_46 ;
}
void F_202 ( void )
{
F_36 ( ! F_37 ( & V_39 ) &&
! F_37 ( & V_38 ) &&
! F_37 ( & V_40 ) ,
L_44 ) ;
if ( F_199 () )
return;
if ( V_155 )
F_203 () ;
else
F_204 ( F_197 ) ;
}
void F_205 ( void )
{
F_36 ( ! F_37 ( & V_39 ) &&
! F_37 ( & V_38 ) &&
! F_37 ( & V_40 ) ,
L_45 ) ;
if ( F_199 () )
return;
if ( V_155 )
F_206 () ;
else
F_204 ( F_198 ) ;
}
static int F_207 ( void * V_156 )
{
F_169 () ;
return 0 ;
}
void F_203 ( void )
{
long V_157 , V_79 , V_56 ;
int V_158 = 0 ;
struct V_1 * V_2 = & V_11 ;
if ( F_67 ( ( V_159 ) F_208 ( & V_2 -> V_160 ) ,
( V_159 ) F_208 ( & V_2 -> V_161 ) +
V_76 / 8 ) ) {
F_202 () ;
F_209 ( & V_2 -> V_162 ) ;
return;
}
V_56 = F_210 ( & V_2 -> V_160 ) ;
V_157 = V_56 ;
F_211 () ;
F_34 ( F_69 ( F_178 () ) ) ;
while ( F_212 ( V_163 ,
F_207 ,
NULL ) == - V_164 ) {
F_213 () ;
F_209 ( & V_2 -> V_165 ) ;
V_79 = F_208 ( & V_2 -> V_161 ) ;
if ( F_67 ( ( V_159 ) V_79 , ( V_159 ) V_157 ) ) {
F_31 () ;
F_209 ( & V_2 -> V_166 ) ;
return;
}
if ( V_158 ++ < 10 ) {
F_124 ( V_158 * F_201 () ) ;
} else {
F_204 ( F_197 ) ;
F_209 ( & V_2 -> V_167 ) ;
return;
}
V_79 = F_208 ( & V_2 -> V_161 ) ;
if ( F_67 ( ( V_159 ) V_79 , ( V_159 ) V_157 ) ) {
F_31 () ;
F_209 ( & V_2 -> V_168 ) ;
return;
}
F_211 () ;
V_56 = F_208 ( & V_2 -> V_160 ) ;
F_169 () ;
}
F_209 ( & V_2 -> V_169 ) ;
do {
F_209 ( & V_2 -> V_170 ) ;
V_79 = F_208 ( & V_2 -> V_161 ) ;
if ( F_67 ( ( V_159 ) V_79 , ( V_159 ) V_56 ) ) {
F_31 () ;
F_209 ( & V_2 -> V_171 ) ;
break;
}
} while ( F_214 ( & V_2 -> V_161 , V_79 , V_56 ) != V_79 );
F_209 ( & V_2 -> V_172 ) ;
F_213 () ;
}
static int F_215 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
struct V_24 * V_47 = V_7 -> V_48 ;
V_7 -> V_173 ++ ;
F_92 ( V_2 , V_7 ) ;
if ( V_51 &&
V_7 -> V_85 && ! V_7 -> V_9 ) {
V_7 -> V_174 ++ ;
} else if ( V_7 -> V_85 && V_7 -> V_9 ) {
V_7 -> V_175 ++ ;
return 1 ;
}
if ( F_18 ( V_7 ) ) {
V_7 -> V_176 ++ ;
return 1 ;
}
if ( F_19 ( V_2 , V_7 ) ) {
V_7 -> V_177 ++ ;
return 1 ;
}
if ( F_2 ( V_47 -> V_3 ) != V_7 -> V_3 ) {
V_7 -> V_178 ++ ;
return 1 ;
}
if ( F_2 ( V_47 -> V_4 ) != V_7 -> V_4 ) {
V_7 -> V_179 ++ ;
return 1 ;
}
V_7 -> V_180 ++ ;
return 0 ;
}
static int F_175 ( int V_5 )
{
struct V_1 * V_2 ;
F_94 (rsp)
if ( F_215 ( V_2 , F_85 ( V_2 -> V_71 , V_5 ) ) )
return 1 ;
return 0 ;
}
static int F_216 ( int V_5 , bool * V_181 )
{
bool V_182 = true ;
bool V_183 = false ;
struct V_6 * V_7 ;
struct V_1 * V_2 ;
F_94 (rsp) {
V_7 = F_85 ( V_2 -> V_71 , V_5 ) ;
if ( V_7 -> V_72 != V_7 -> V_116 )
V_182 = false ;
if ( V_7 -> V_16 )
V_183 = true ;
}
if ( V_181 )
* V_181 = V_182 ;
return V_183 ;
}
static void F_217 ( struct V_1 * V_2 , const char * V_79 ,
int V_5 , unsigned long V_184 )
{
F_218 ( V_2 -> V_57 , V_79 , V_5 ,
F_35 ( & V_2 -> V_185 ) , V_184 ) ;
}
static void F_219 ( struct V_127 * V_151 )
{
struct V_6 * V_7 = F_139 ( V_151 , struct V_6 , V_186 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
if ( F_220 ( & V_2 -> V_185 ) ) {
F_217 ( V_2 , L_46 , - 1 , V_2 -> V_187 ) ;
F_221 ( & V_2 -> V_188 ) ;
} else {
F_217 ( V_2 , L_47 , - 1 , V_2 -> V_187 ) ;
}
}
static void F_222 ( void * type )
{
struct V_1 * V_2 = type ;
struct V_6 * V_7 = F_151 ( V_2 -> V_71 ) ;
F_217 ( V_2 , L_48 , - 1 , V_2 -> V_187 ) ;
F_32 ( & V_2 -> V_185 ) ;
V_2 -> V_189 ( & V_7 -> V_186 , F_219 ) ;
}
static void F_223 ( struct V_1 * V_2 )
{
int V_5 ;
struct V_6 * V_7 ;
unsigned long V_56 = F_2 ( V_2 -> V_187 ) ;
unsigned long V_190 ;
F_217 ( V_2 , L_49 , - 1 , V_56 ) ;
F_117 ( & V_2 -> V_191 ) ;
F_169 () ;
V_190 = V_2 -> V_187 ;
F_217 ( V_2 , L_50 , - 1 , V_190 ) ;
if ( F_67 ( V_190 , ( V_56 + 3 ) & ~ 0x1 ) ) {
F_217 ( V_2 , L_51 , - 1 , V_190 ) ;
F_169 () ;
F_126 ( & V_2 -> V_191 ) ;
return;
}
F_2 ( V_2 -> V_187 ) ++ ;
F_34 ( ( V_2 -> V_187 & 0x1 ) != 1 ) ;
F_217 ( V_2 , L_52 , - 1 , V_2 -> V_187 ) ;
F_169 () ;
F_224 ( & V_2 -> V_188 ) ;
F_225 ( & V_2 -> V_185 , 1 ) ;
F_211 () ;
F_84 (cpu) {
if ( ! F_185 ( V_5 ) && ! F_149 ( V_5 ) )
continue;
V_7 = F_85 ( V_2 -> V_71 , V_5 ) ;
if ( F_149 ( V_5 ) ) {
F_217 ( V_2 , L_53 , V_5 ,
V_2 -> V_187 ) ;
F_32 ( & V_2 -> V_185 ) ;
F_190 ( & V_7 -> V_186 , F_219 ,
V_2 , V_5 , 0 ) ;
} else if ( F_2 ( V_7 -> V_72 ) ) {
F_217 ( V_2 , L_54 , V_5 ,
V_2 -> V_187 ) ;
F_226 ( V_5 , F_222 , V_2 , 1 ) ;
} else {
F_217 ( V_2 , L_55 , V_5 ,
V_2 -> V_187 ) ;
}
}
F_213 () ;
if ( F_220 ( & V_2 -> V_185 ) )
F_221 ( & V_2 -> V_188 ) ;
F_169 () ;
F_2 ( V_2 -> V_187 ) ++ ;
F_34 ( ( V_2 -> V_187 & 0x1 ) != 0 ) ;
F_217 ( V_2 , L_56 , - 1 , V_2 -> V_187 ) ;
F_169 () ;
F_227 ( & V_2 -> V_188 ) ;
F_126 ( & V_2 -> V_191 ) ;
}
void F_228 ( void )
{
F_223 ( & V_12 ) ;
}
void F_229 ( void )
{
F_223 ( & V_11 ) ;
}
static void T_3
F_230 ( int V_5 , struct V_1 * V_2 )
{
unsigned long V_43 ;
struct V_6 * V_7 = F_85 ( V_2 -> V_71 , V_5 ) ;
struct V_24 * V_47 = F_22 ( V_2 ) ;
F_75 ( & V_47 -> V_63 , V_43 ) ;
V_7 -> V_49 = 1UL << ( V_5 - V_7 -> V_48 -> V_66 ) ;
F_95 ( V_7 ) ;
V_7 -> V_116 = 0 ;
F_2 ( V_7 -> V_72 ) = 0 ;
V_7 -> V_37 = & F_4 ( V_26 , V_5 ) ;
F_34 ( V_7 -> V_37 -> V_30 != V_44 ) ;
F_34 ( F_35 ( & V_7 -> V_37 -> V_37 ) != 1 ) ;
V_7 -> V_5 = V_5 ;
V_7 -> V_2 = V_2 ;
F_231 ( V_7 ) ;
F_77 ( & V_47 -> V_63 , V_43 ) ;
}
static void
F_232 ( int V_5 , struct V_1 * V_2 , int V_192 )
{
unsigned long V_43 ;
unsigned long V_112 ;
struct V_6 * V_7 = F_85 ( V_2 -> V_71 , V_5 ) ;
struct V_24 * V_47 = F_22 ( V_2 ) ;
F_117 ( & V_2 -> V_87 ) ;
F_75 ( & V_47 -> V_63 , V_43 ) ;
V_7 -> V_145 = 1 ;
V_7 -> V_192 = V_192 ;
V_7 -> V_138 = 0 ;
V_7 -> V_139 = V_2 -> V_93 ;
V_7 -> V_134 = V_134 ;
F_95 ( V_7 ) ;
V_7 -> V_37 -> V_30 = V_44 ;
F_233 ( V_7 -> V_37 ) ;
F_225 ( & V_7 -> V_37 -> V_37 ,
( F_35 ( & V_7 -> V_37 -> V_37 ) & ~ 0x1 ) + 1 ) ;
F_103 ( & V_47 -> V_63 ) ;
V_47 = V_7 -> V_48 ;
V_112 = V_7 -> V_49 ;
do {
F_101 ( & V_47 -> V_63 ) ;
V_47 -> V_50 |= V_112 ;
V_112 = V_47 -> V_49 ;
if ( V_47 == V_7 -> V_48 ) {
V_7 -> V_4 = V_47 -> V_3 ;
V_7 -> V_3 = V_47 -> V_3 ;
V_7 -> V_9 = 0 ;
V_7 -> V_85 = 0 ;
F_5 ( V_2 -> V_57 , V_7 -> V_4 , F_6 ( L_57 ) ) ;
}
F_103 ( & V_47 -> V_63 ) ;
V_47 = V_47 -> V_115 ;
} while ( V_47 != NULL && ! ( V_47 -> V_50 & V_112 ) );
F_43 ( V_43 ) ;
F_126 ( & V_2 -> V_87 ) ;
}
static void F_234 ( int V_5 )
{
struct V_1 * V_2 ;
F_94 (rsp)
F_232 ( V_5 , V_2 ,
strcmp ( V_2 -> V_57 , L_58 ) == 0 ) ;
}
static int F_235 ( struct V_193 * V_194 ,
unsigned long V_195 , void * V_196 )
{
long V_5 = ( long ) V_196 ;
struct V_6 * V_7 = F_85 ( V_1 -> V_71 , V_5 ) ;
struct V_24 * V_47 = V_7 -> V_48 ;
struct V_1 * V_2 ;
F_9 ( F_6 ( L_59 ) ) ;
switch ( V_195 ) {
case V_197 :
case V_198 :
F_234 ( V_5 ) ;
F_236 ( V_5 ) ;
break;
case V_199 :
case V_200 :
F_157 ( V_47 , - 1 ) ;
break;
case V_201 :
F_157 ( V_47 , V_5 ) ;
break;
case V_202 :
case V_203 :
F_94 (rsp)
F_154 ( V_2 ) ;
break;
case V_204 :
case V_205 :
case V_206 :
case V_207 :
F_94 (rsp)
F_156 ( V_5 , V_2 ) ;
break;
default:
break;
}
F_9 ( F_6 ( L_60 ) ) ;
return V_208 ;
}
static int F_237 ( struct V_193 * V_194 ,
unsigned long V_195 , void * V_196 )
{
switch ( V_195 ) {
case V_209 :
case V_210 :
if ( V_211 <= 256 )
V_155 = 1 ;
break;
case V_212 :
case V_213 :
V_155 = 0 ;
break;
default:
break;
}
return V_208 ;
}
static int T_3 F_238 ( void )
{
unsigned long V_43 ;
struct V_24 * V_47 ;
struct V_1 * V_2 ;
struct V_32 * V_214 ;
F_94 (rsp) {
V_214 = F_239 ( F_133 , V_2 , L_61 , V_2 -> V_57 ) ;
F_240 ( F_241 ( V_214 ) ) ;
V_47 = F_22 ( V_2 ) ;
F_75 ( & V_47 -> V_63 , V_43 ) ;
V_2 -> V_111 = V_214 ;
F_77 ( & V_47 -> V_63 , V_43 ) ;
F_242 ( V_2 ) ;
}
return 0 ;
}
void F_243 ( void )
{
F_244 ( F_201 () != 1 ) ;
F_244 ( F_245 () > 0 ) ;
V_215 = 1 ;
}
static void T_3 F_246 ( struct V_1 * V_2 )
{
int V_19 ;
for ( V_19 = V_216 - 1 ; V_19 > 0 ; V_19 -- )
V_2 -> V_217 [ V_19 ] = V_218 ;
V_2 -> V_217 [ 0 ] = V_219 ;
}
static void T_3 F_246 ( struct V_1 * V_2 )
{
int V_220 ;
int V_221 ;
int V_19 ;
V_221 = V_211 ;
for ( V_19 = V_216 - 1 ; V_19 >= 0 ; V_19 -- ) {
V_220 = V_2 -> V_222 [ V_19 ] ;
V_2 -> V_217 [ V_19 ] = ( V_221 + V_220 - 1 ) / V_220 ;
V_221 = V_220 ;
}
}
static void T_3 F_247 ( struct V_1 * V_2 ,
struct V_6 T_4 * V_71 )
{
static char * V_223 [] = { L_62 ,
L_63 ,
L_64 ,
L_65 } ;
static char * V_224 [] = { L_66 ,
L_67 ,
L_68 ,
L_69 } ;
int V_225 = 1 ;
int V_19 ;
int V_73 ;
struct V_24 * V_47 ;
F_248 ( V_226 > F_249 ( V_223 ) ) ;
if ( V_216 > V_227 )
F_250 ( L_70 ) ;
for ( V_19 = 0 ; V_19 < V_216 ; V_19 ++ )
V_2 -> V_222 [ V_19 ] = V_228 [ V_19 ] ;
for ( V_19 = 1 ; V_19 < V_216 ; V_19 ++ )
V_2 -> V_80 [ V_19 ] = V_2 -> V_80 [ V_19 - 1 ] + V_2 -> V_222 [ V_19 - 1 ] ;
F_246 ( V_2 ) ;
for ( V_19 = V_216 - 1 ; V_19 >= 0 ; V_19 -- ) {
V_225 *= V_2 -> V_217 [ V_19 ] ;
V_47 = V_2 -> V_80 [ V_19 ] ;
for ( V_73 = 0 ; V_73 < V_2 -> V_222 [ V_19 ] ; V_73 ++ , V_47 ++ ) {
F_251 ( & V_47 -> V_63 ) ;
F_252 ( & V_47 -> V_63 ,
& V_229 [ V_19 ] , V_223 [ V_19 ] ) ;
F_251 ( & V_47 -> V_143 ) ;
F_252 ( & V_47 -> V_143 ,
& V_230 [ V_19 ] , V_224 [ V_19 ] ) ;
V_47 -> V_4 = V_2 -> V_4 ;
V_47 -> V_3 = V_2 -> V_3 ;
V_47 -> V_64 = 0 ;
V_47 -> V_50 = 0 ;
V_47 -> V_66 = V_73 * V_225 ;
V_47 -> V_65 = ( V_73 + 1 ) * V_225 - 1 ;
if ( V_47 -> V_65 >= V_231 )
V_47 -> V_65 = V_231 - 1 ;
if ( V_19 == 0 ) {
V_47 -> V_232 = 0 ;
V_47 -> V_49 = 0 ;
V_47 -> V_115 = NULL ;
} else {
V_47 -> V_232 = V_73 % V_2 -> V_217 [ V_19 - 1 ] ;
V_47 -> V_49 = 1UL << V_47 -> V_232 ;
V_47 -> V_115 = V_2 -> V_80 [ V_19 - 1 ] +
V_73 / V_2 -> V_217 [ V_19 - 1 ] ;
}
V_47 -> V_80 = V_19 ;
F_253 ( & V_47 -> V_233 ) ;
F_254 ( V_47 ) ;
}
}
V_2 -> V_71 = V_71 ;
F_255 ( & V_2 -> V_102 ) ;
F_256 ( & V_2 -> V_110 , F_138 ) ;
V_47 = V_2 -> V_80 [ V_216 - 1 ] ;
F_84 (i) {
while ( V_19 > V_47 -> V_65 )
V_47 ++ ;
F_85 ( V_2 -> V_71 , V_19 ) -> V_48 = V_47 ;
F_230 ( V_19 , V_2 ) ;
}
F_257 ( & V_2 -> V_234 , & V_235 ) ;
}
static void T_3 F_258 ( void )
{
V_159 V_236 ;
int V_19 ;
int V_73 ;
int V_237 = V_211 ;
int V_238 [ V_226 + 1 ] ;
V_236 = V_239 + V_211 / V_240 ;
if ( V_104 == V_76 )
V_104 = V_236 ;
if ( V_107 == V_76 )
V_107 = V_236 ;
if ( V_219 == V_241 &&
V_211 == V_231 )
return;
V_238 [ 0 ] = 1 ;
V_238 [ 1 ] = V_219 ;
for ( V_19 = 2 ; V_19 <= V_226 ; V_19 ++ )
V_238 [ V_19 ] = V_238 [ V_19 - 1 ] * V_218 ;
if ( V_219 < V_241 ||
V_219 > sizeof( unsigned long ) * 8 ||
V_237 > V_238 [ V_226 ] ) {
F_244 ( 1 ) ;
return;
}
for ( V_19 = 1 ; V_19 <= V_226 ; V_19 ++ )
if ( V_237 <= V_238 [ V_19 ] ) {
for ( V_73 = 0 ; V_73 <= V_19 ; V_73 ++ )
V_228 [ V_73 ] =
F_259 ( V_237 , V_238 [ V_19 - V_73 ] ) ;
V_216 = V_19 ;
for ( V_73 = V_19 + 1 ; V_73 <= V_226 ; V_73 ++ )
V_228 [ V_73 ] = 0 ;
break;
}
V_88 = 0 ;
for ( V_19 = 0 ; V_19 <= V_226 ; V_19 ++ )
V_88 += V_228 [ V_19 ] ;
V_88 -= V_237 ;
}
void T_3 F_260 ( void )
{
int V_5 ;
F_261 () ;
F_258 () ;
F_247 ( & V_11 , & V_8 ) ;
F_247 ( & V_12 , & V_10 ) ;
F_262 () ;
F_263 ( V_149 , F_181 ) ;
F_264 ( F_235 , 0 ) ;
F_265 ( F_237 , 0 ) ;
F_266 (cpu)
F_235 ( NULL , V_197 , ( void * ) ( long ) V_5 ) ;
}
