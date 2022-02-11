void F_1 ( void )
{
F_2 ( & V_1 ) ;
}
void F_3 ( void )
{
F_4 ( & V_1 ) ;
}
static struct V_2 * F_5 ( T_1 V_3 , T_1 V_4 )
{
struct V_2 * V_5 ;
V_5 = F_6 ( sizeof( struct V_2 ) , V_6 ) ;
F_7 ( ! V_5 ) ;
V_5 -> V_7 = L_1 ;
V_5 -> V_3 = V_3 ;
V_5 -> V_8 = V_3 + V_4 - 1 ;
V_5 -> V_9 = V_10 | V_11 ;
if ( F_8 ( & V_12 , V_5 ) < 0 ) {
F_9 ( L_2 , V_5 ) ;
F_10 ( V_5 ) ;
V_5 = NULL ;
}
return V_5 ;
}
static void F_11 ( struct V_2 * V_5 )
{
if ( ! V_5 )
return;
F_12 ( V_5 ) ;
F_10 ( V_5 ) ;
return;
}
void F_13 ( unsigned long V_13 , struct V_14 * V_14 ,
unsigned long type )
{
V_14 -> V_15 . V_16 = (struct V_17 * ) type ;
F_14 ( V_14 ) ;
F_15 ( V_14 , V_13 ) ;
F_16 ( & V_14 -> V_18 ) ;
}
void F_17 ( struct V_14 * V_14 )
{
unsigned long type ;
type = ( unsigned long ) V_14 -> V_15 . V_16 ;
F_7 ( type < V_19 ||
type > V_20 ) ;
if ( F_18 ( & V_14 -> V_18 ) == 1 ) {
F_19 ( V_14 ) ;
F_15 ( V_14 , 0 ) ;
F_20 ( & V_14 -> V_15 ) ;
F_21 ( V_14 ) ;
}
}
static void F_22 ( unsigned long V_21 )
{
unsigned long * V_22 , V_23 , V_24 , V_25 ;
struct V_26 * V_27 ;
struct V_14 * V_14 , * V_28 ;
V_24 = F_23 ( V_21 ) ;
V_27 = F_24 ( V_24 ) ;
V_28 = F_25 ( V_27 -> V_29 , V_24 ) ;
V_14 = F_26 ( V_28 ) ;
V_23 = sizeof( struct V_14 ) * V_30 ;
V_23 = F_27 ( V_23 ) >> V_31 ;
for ( V_25 = 0 ; V_25 < V_23 ; V_25 ++ , V_14 ++ )
F_13 ( V_24 , V_14 , V_32 ) ;
V_22 = F_24 ( V_24 ) -> V_33 ;
V_14 = F_26 ( V_22 ) ;
V_23 = F_27 ( F_28 () ) >> V_31 ;
for ( V_25 = 0 ; V_25 < V_23 ; V_25 ++ , V_14 ++ )
F_13 ( V_24 , V_14 , V_34 ) ;
}
static void F_22 ( unsigned long V_21 )
{
unsigned long * V_22 , V_23 , V_24 , V_25 ;
struct V_26 * V_27 ;
struct V_14 * V_14 , * V_28 ;
if ( ! F_29 ( V_21 ) )
return;
V_24 = F_23 ( V_21 ) ;
V_27 = F_24 ( V_24 ) ;
V_28 = F_25 ( V_27 -> V_29 , V_24 ) ;
F_30 ( V_24 , V_28 , V_30 ) ;
V_22 = F_24 ( V_24 ) -> V_33 ;
V_14 = F_26 ( V_22 ) ;
V_23 = F_27 ( F_28 () ) >> V_31 ;
for ( V_25 = 0 ; V_25 < V_23 ; V_25 ++ , V_14 ++ )
F_13 ( V_24 , V_14 , V_34 ) ;
}
void F_31 ( struct V_35 * V_36 )
{
unsigned long V_25 , V_37 , V_38 , V_39 ;
int V_40 = V_36 -> V_41 ;
struct V_14 * V_14 ;
struct V_42 * V_42 ;
V_39 = F_27 ( sizeof( struct V_35 ) ) >> V_31 ;
V_14 = F_26 ( V_36 ) ;
for ( V_25 = 0 ; V_25 < V_39 ; V_25 ++ , V_14 ++ )
F_13 ( V_40 , V_14 , V_43 ) ;
V_42 = & V_36 -> V_44 [ 0 ] ;
for (; V_42 < V_36 -> V_44 + V_45 - 1 ; V_42 ++ ) {
if ( F_32 ( V_42 ) ) {
V_39 = V_42 -> V_46
* sizeof( V_47 ) ;
V_39 = F_27 ( V_39 ) >> V_31 ;
V_14 = F_26 ( V_42 -> V_48 ) ;
for ( V_25 = 0 ; V_25 < V_39 ; V_25 ++ , V_14 ++ )
F_13 ( V_40 , V_14 , V_43 ) ;
}
}
V_37 = V_36 -> V_49 ;
V_38 = F_33 ( V_36 ) ;
for (; V_37 < V_38 ; V_37 += V_30 ) {
if ( F_29 ( V_37 ) && ( F_34 ( V_37 ) == V_40 ) )
F_22 ( V_37 ) ;
}
}
static void F_35 ( struct V_42 * V_42 , unsigned long V_21 ,
unsigned long V_38 )
{
unsigned long V_50 ;
F_36 ( V_42 ) ;
V_50 = F_37 ( V_42 ) ;
if ( F_38 ( V_42 ) || V_21 < V_42 -> V_51 )
V_42 -> V_51 = V_21 ;
V_42 -> V_52 = F_39 ( V_50 , V_38 ) -
V_42 -> V_51 ;
F_40 ( V_42 ) ;
}
static void F_41 ( struct V_42 * V_42 , unsigned long V_21 ,
unsigned long V_38 )
{
F_36 ( V_42 ) ;
if ( V_38 - V_21 ) {
V_42 -> V_51 = V_21 ;
V_42 -> V_52 = V_38 - V_21 ;
} else {
V_42 -> V_51 = 0 ;
V_42 -> V_52 = 0 ;
}
F_40 ( V_42 ) ;
}
static void F_42 ( struct V_42 * V_42 , unsigned long V_21 ,
unsigned long V_38 )
{
enum V_53 V_54 = F_43 ( V_42 ) ;
int V_55 = V_42 -> V_56 -> V_41 ;
unsigned long V_37 ;
for ( V_37 = V_21 ; V_37 < V_38 ; V_37 ++ )
F_44 ( F_45 ( V_37 ) , V_54 , V_55 , V_37 ) ;
}
static int T_2 F_46 ( struct V_42 * V_42 ,
unsigned long V_21 , unsigned long V_57 )
{
if ( ! F_32 ( V_42 ) )
return F_47 ( V_42 , V_21 , V_57 ,
V_58 ) ;
return 0 ;
}
static int T_3 F_48 ( struct V_42 * V_59 , struct V_42 * V_60 ,
unsigned long V_21 , unsigned long V_38 )
{
int V_61 ;
unsigned long V_9 ;
unsigned long V_62 ;
V_61 = F_46 ( V_59 , V_21 , V_38 - V_21 ) ;
if ( V_61 )
return V_61 ;
F_49 ( V_59 -> V_56 , & V_9 ) ;
if ( V_38 > F_37 ( V_60 ) )
goto V_63;
if ( V_21 > V_60 -> V_51 )
goto V_63;
if ( V_38 <= V_60 -> V_51 )
goto V_63;
if ( ! F_38 ( V_59 ) )
V_62 = V_59 -> V_51 ;
else
V_62 = V_21 ;
F_41 ( V_59 , V_62 , V_38 ) ;
F_41 ( V_60 , V_38 , F_37 ( V_60 ) ) ;
F_50 ( V_59 -> V_56 , & V_9 ) ;
F_42 ( V_59 , V_21 , V_38 ) ;
return 0 ;
V_63:
F_50 ( V_59 -> V_56 , & V_9 ) ;
return - 1 ;
}
static int T_3 F_51 ( struct V_42 * V_59 , struct V_42 * V_60 ,
unsigned long V_21 , unsigned long V_38 )
{
int V_61 ;
unsigned long V_9 ;
unsigned long V_64 ;
V_61 = F_46 ( V_60 , V_21 , V_38 - V_21 ) ;
if ( V_61 )
return V_61 ;
F_49 ( V_59 -> V_56 , & V_9 ) ;
if ( V_59 -> V_51 > V_21 )
goto V_63;
if ( F_37 ( V_59 ) > V_38 )
goto V_63;
if ( V_21 >= F_37 ( V_59 ) )
goto V_63;
if ( ! F_38 ( V_60 ) )
V_64 = F_37 ( V_60 ) ;
else
V_64 = V_38 ;
F_41 ( V_59 , V_59 -> V_51 , V_21 ) ;
F_41 ( V_60 , V_21 , V_64 ) ;
F_50 ( V_59 -> V_56 , & V_9 ) ;
F_42 ( V_60 , V_21 , V_38 ) ;
return 0 ;
V_63:
F_50 ( V_59 -> V_56 , & V_9 ) ;
return - 1 ;
}
static void F_52 ( struct V_35 * V_36 , unsigned long V_21 ,
unsigned long V_38 )
{
unsigned long V_65 = F_33 ( V_36 ) ;
if ( ! V_36 -> V_66 || V_21 < V_36 -> V_49 )
V_36 -> V_49 = V_21 ;
V_36 -> V_66 = F_39 ( V_65 , V_38 ) -
V_36 -> V_49 ;
}
static int T_3 F_53 ( struct V_42 * V_42 , unsigned long V_67 )
{
struct V_35 * V_36 = V_42 -> V_56 ;
int V_39 = V_30 ;
int V_55 = V_36 -> V_41 ;
int V_53 ;
unsigned long V_9 ;
int V_61 ;
V_53 = V_42 - V_36 -> V_44 ;
V_61 = F_46 ( V_42 , V_67 , V_39 ) ;
if ( V_61 )
return V_61 ;
F_49 ( V_42 -> V_56 , & V_9 ) ;
F_35 ( V_42 , V_67 , V_67 + V_39 ) ;
F_52 ( V_42 -> V_56 , V_67 ,
V_67 + V_39 ) ;
F_50 ( V_42 -> V_56 , & V_9 ) ;
F_54 ( V_39 , V_55 , V_53 ,
V_67 , V_58 ) ;
return 0 ;
}
static int T_3 F_55 ( int V_55 , struct V_42 * V_42 ,
unsigned long V_67 )
{
int V_61 ;
if ( F_29 ( V_67 ) )
return - V_68 ;
V_61 = F_56 ( V_42 , V_67 ) ;
if ( V_61 < 0 )
return V_61 ;
V_61 = F_53 ( V_42 , V_67 ) ;
if ( V_61 < 0 )
return V_61 ;
return F_57 ( V_55 , F_58 ( V_67 ) ) ;
}
int T_2 F_59 ( int V_55 , struct V_42 * V_42 , unsigned long V_67 ,
unsigned long V_39 )
{
unsigned long V_25 ;
int V_69 = 0 ;
int V_70 , V_71 ;
V_70 = F_23 ( V_67 ) ;
V_71 = F_23 ( V_67 + V_39 - 1 ) ;
for ( V_25 = V_70 ; V_25 <= V_71 ; V_25 ++ ) {
V_69 = F_55 ( V_55 , V_42 , V_25 << V_72 ) ;
if ( V_69 && ( V_69 != - V_68 ) )
break;
V_69 = 0 ;
}
return V_69 ;
}
static int F_60 ( int V_55 , struct V_42 * V_42 ,
unsigned long V_21 ,
unsigned long V_38 )
{
struct V_26 * V_27 ;
for (; V_21 < V_38 ; V_21 += V_30 ) {
V_27 = F_58 ( V_21 ) ;
if ( F_61 ( ! F_62 ( V_27 ) ) )
continue;
if ( F_61 ( F_34 ( V_21 ) != V_55 ) )
continue;
if ( V_42 && V_42 != F_63 ( F_45 ( V_21 ) ) )
continue;
return V_21 ;
}
return 0 ;
}
static int F_64 ( int V_55 , struct V_42 * V_42 ,
unsigned long V_21 ,
unsigned long V_38 )
{
struct V_26 * V_27 ;
unsigned long V_37 ;
V_37 = V_38 - 1 ;
for (; V_37 >= V_21 ; V_37 -= V_30 ) {
V_27 = F_58 ( V_37 ) ;
if ( F_61 ( ! F_62 ( V_27 ) ) )
continue;
if ( F_61 ( F_34 ( V_37 ) != V_55 ) )
continue;
if ( V_42 && V_42 != F_63 ( F_45 ( V_37 ) ) )
continue;
return V_37 ;
}
return 0 ;
}
static void F_65 ( struct V_42 * V_42 , unsigned long V_21 ,
unsigned long V_38 )
{
unsigned long V_51 = V_42 -> V_51 ;
unsigned long V_73 = F_37 ( V_42 ) ;
unsigned long F_37 = V_73 ;
unsigned long V_37 ;
struct V_26 * V_27 ;
int V_55 = F_66 ( V_42 ) ;
F_36 ( V_42 ) ;
if ( V_51 == V_21 ) {
V_37 = F_60 ( V_55 , V_42 , V_38 ,
F_37 ) ;
if ( V_37 ) {
V_42 -> V_51 = V_37 ;
V_42 -> V_52 = F_37 - V_37 ;
}
} else if ( F_37 == V_38 ) {
V_37 = F_64 ( V_55 , V_42 , V_51 ,
V_21 ) ;
if ( V_37 )
V_42 -> V_52 = V_37 - V_51 + 1 ;
}
V_37 = V_51 ;
for (; V_37 < F_37 ; V_37 += V_30 ) {
V_27 = F_58 ( V_37 ) ;
if ( F_61 ( ! F_62 ( V_27 ) ) )
continue;
if ( F_63 ( F_45 ( V_37 ) ) != V_42 )
continue;
if ( V_21 == V_37 )
continue;
F_40 ( V_42 ) ;
return;
}
V_42 -> V_51 = 0 ;
V_42 -> V_52 = 0 ;
F_40 ( V_42 ) ;
}
static void F_67 ( struct V_35 * V_36 ,
unsigned long V_21 , unsigned long V_38 )
{
unsigned long V_74 = V_36 -> V_49 ;
unsigned long V_75 = F_33 ( V_36 ) ;
unsigned long F_33 = V_75 ;
unsigned long V_37 ;
struct V_26 * V_27 ;
int V_55 = V_36 -> V_41 ;
if ( V_74 == V_21 ) {
V_37 = F_60 ( V_55 , NULL , V_38 ,
F_33 ) ;
if ( V_37 ) {
V_36 -> V_49 = V_37 ;
V_36 -> V_66 = F_33 - V_37 ;
}
} else if ( F_33 == V_38 ) {
V_37 = F_64 ( V_55 , NULL , V_74 ,
V_21 ) ;
if ( V_37 )
V_36 -> V_66 = V_37 - V_74 + 1 ;
}
V_37 = V_74 ;
for (; V_37 < F_33 ; V_37 += V_30 ) {
V_27 = F_58 ( V_37 ) ;
if ( F_61 ( ! F_62 ( V_27 ) ) )
continue;
if ( F_34 ( V_37 ) != V_55 )
continue;
if ( V_21 == V_37 )
continue;
return;
}
V_36 -> V_49 = 0 ;
V_36 -> V_66 = 0 ;
}
static void F_68 ( struct V_42 * V_42 , unsigned long V_21 )
{
struct V_35 * V_36 = V_42 -> V_56 ;
int V_39 = V_30 ;
int V_53 ;
unsigned long V_9 ;
V_53 = V_42 - V_36 -> V_44 ;
F_49 ( V_42 -> V_56 , & V_9 ) ;
F_65 ( V_42 , V_21 , V_21 + V_39 ) ;
F_67 ( V_36 , V_21 , V_21 + V_39 ) ;
F_50 ( V_42 -> V_56 , & V_9 ) ;
}
static int F_69 ( struct V_42 * V_42 , struct V_26 * V_27 )
{
unsigned long V_21 ;
int V_76 ;
int V_61 = - V_77 ;
if ( ! F_62 ( V_27 ) )
return V_61 ;
V_61 = F_70 ( V_27 ) ;
if ( V_61 )
return V_61 ;
V_76 = F_71 ( V_27 ) ;
V_21 = F_72 ( V_76 ) ;
F_68 ( V_42 , V_21 ) ;
F_73 ( V_42 , V_27 ) ;
return 0 ;
}
int F_74 ( struct V_42 * V_42 , unsigned long V_67 ,
unsigned long V_39 )
{
unsigned long V_25 ;
int V_78 ;
T_4 V_3 , V_4 ;
int V_61 = 0 ;
F_7 ( V_67 & ~ V_79 ) ;
F_7 ( V_39 % V_30 ) ;
V_3 = V_67 << V_31 ;
V_4 = V_39 * V_80 ;
V_61 = F_75 ( & V_12 , V_3 , V_4 ) ;
if ( V_61 ) {
T_4 V_81 = V_3 + V_4 - 1 ;
F_76 ( L_3 ,
& V_3 , & V_81 , V_61 ) ;
}
V_78 = V_39 / V_30 ;
for ( V_25 = 0 ; V_25 < V_78 ; V_25 ++ ) {
unsigned long V_37 = V_67 + V_25 * V_30 ;
V_61 = F_69 ( V_42 , F_58 ( V_37 ) ) ;
if ( V_61 )
break;
}
return V_61 ;
}
int F_77 ( T_5 V_82 )
{
int V_83 = - V_77 ;
F_1 () ;
if ( V_84 == V_85 ) {
V_84 = V_82 ;
V_83 = 0 ;
}
F_3 () ;
return V_83 ;
}
int F_78 ( T_5 V_82 )
{
int V_83 = - V_77 ;
F_1 () ;
if ( V_84 == V_82 ) {
V_84 = V_85 ;
V_83 = 0 ;
}
F_3 () ;
return V_83 ;
}
void F_79 ( struct V_14 * V_14 )
{
}
void F_80 ( struct V_14 * V_14 )
{
F_81 ( V_14 , 1 ) ;
}
void F_82 ( struct V_14 * V_14 )
{
F_83 ( V_14 ) ;
}
static void V_85 ( struct V_14 * V_14 )
{
F_79 ( V_14 ) ;
F_80 ( V_14 ) ;
F_82 ( V_14 ) ;
}
static int F_84 ( unsigned long V_21 , unsigned long V_39 ,
void * V_86 )
{
unsigned long V_25 ;
unsigned long V_87 = * ( unsigned long * ) V_86 ;
struct V_14 * V_14 ;
if ( F_85 ( F_45 ( V_21 ) ) )
for ( V_25 = 0 ; V_25 < V_39 ; V_25 ++ ) {
V_14 = F_45 ( V_21 + V_25 ) ;
(* V_84)( V_14 ) ;
V_87 ++ ;
}
* ( unsigned long * ) V_86 = V_87 ;
return 0 ;
}
static bool F_86 ( struct V_42 * V_42 )
{
return true ;
}
static bool F_86 ( struct V_42 * V_42 )
{
return F_87 ( F_66 ( V_42 ) , V_88 ) ;
}
static void F_88 ( unsigned long V_39 ,
struct V_42 * V_42 , struct V_89 * V_86 )
{
int V_55 = F_66 ( V_42 ) ;
enum V_53 V_90 = V_91 ;
if ( V_92 == V_88 )
V_90 = V_93 ;
if ( F_43 ( V_42 ) <= V_90 && ! F_87 ( V_55 , V_88 ) )
V_86 -> V_94 = V_55 ;
else
V_86 -> V_94 = - 1 ;
#ifdef F_89
V_90 = V_95 ;
if ( V_92 == V_96 )
V_90 = V_93 ;
if ( F_43 ( V_42 ) <= V_90 && ! F_87 ( V_55 , V_96 ) )
V_86 -> V_97 = V_55 ;
else
V_86 -> V_97 = - 1 ;
#else
V_86 -> V_97 = V_86 -> V_94 ;
#endif
if ( ! F_87 ( V_55 , V_92 ) )
V_86 -> V_98 = V_55 ;
else
V_86 -> V_98 = - 1 ;
}
static void F_90 ( int V_40 , struct V_89 * V_86 )
{
if ( V_86 -> V_94 >= 0 )
F_91 ( V_40 , V_88 ) ;
if ( V_86 -> V_97 >= 0 )
F_91 ( V_40 , V_96 ) ;
F_91 ( V_40 , V_92 ) ;
}
int T_2 F_92 ( unsigned long V_37 , unsigned long V_39 , int V_99 )
{
unsigned long V_9 ;
unsigned long V_87 = 0 ;
struct V_42 * V_42 ;
int V_100 = 0 ;
int V_55 ;
int V_61 ;
struct V_89 V_86 ;
F_1 () ;
V_42 = F_63 ( F_45 ( V_37 ) ) ;
if ( ( F_43 ( V_42 ) > V_91 || V_99 == V_101 ) &&
! F_86 ( V_42 ) ) {
F_3 () ;
return - V_77 ;
}
if ( V_99 == V_102 && F_43 ( V_42 ) == V_93 ) {
if ( F_48 ( V_42 - 1 , V_42 , V_37 , V_37 + V_39 ) ) {
F_3 () ;
return - V_77 ;
}
}
if ( V_99 == V_101 && F_43 ( V_42 ) == V_93 - 1 ) {
if ( F_51 ( V_42 , V_42 + 1 , V_37 , V_37 + V_39 ) ) {
F_3 () ;
return - V_77 ;
}
}
V_42 = F_63 ( F_45 ( V_37 ) ) ;
V_86 . V_21 = V_37 ;
V_86 . V_39 = V_39 ;
F_88 ( V_39 , V_42 , & V_86 ) ;
V_55 = F_34 ( V_37 ) ;
V_61 = V_89 ( V_103 , & V_86 ) ;
V_61 = F_93 ( V_61 ) ;
if ( V_61 ) {
V_89 ( V_104 , & V_86 ) ;
F_3 () ;
return V_61 ;
}
F_2 ( & V_105 ) ;
if ( ! F_94 ( V_42 ) ) {
V_100 = 1 ;
F_95 ( NULL , V_42 ) ;
}
V_61 = F_96 ( V_37 , V_39 , & V_87 ,
F_84 ) ;
if ( V_61 ) {
if ( V_100 )
F_97 ( V_42 ) ;
F_4 ( & V_105 ) ;
F_98 ( V_106 L_4 ,
( unsigned long long ) V_37 << V_31 ,
( ( ( unsigned long long ) V_37 + V_39 )
<< V_31 ) - 1 ) ;
V_89 ( V_104 , & V_86 ) ;
F_3 () ;
return V_61 ;
}
V_42 -> V_107 += V_87 ;
F_49 ( V_42 -> V_56 , & V_9 ) ;
V_42 -> V_56 -> V_108 += V_87 ;
F_50 ( V_42 -> V_56 , & V_9 ) ;
if ( V_87 ) {
F_90 ( F_66 ( V_42 ) , & V_86 ) ;
if ( V_100 )
F_95 ( NULL , NULL ) ;
else
F_99 ( V_42 ) ;
}
F_4 ( & V_105 ) ;
F_100 () ;
if ( V_87 )
F_101 ( F_66 ( V_42 ) ) ;
V_109 = F_102 () ;
F_103 () ;
if ( V_87 )
V_89 ( V_110 , & V_86 ) ;
F_3 () ;
return 0 ;
}
static T_6 T_2 * F_104 ( int V_55 , T_1 V_3 )
{
struct V_35 * V_36 ;
unsigned long V_111 [ V_45 ] = { 0 } ;
unsigned long V_112 [ V_45 ] = { 0 } ;
unsigned long V_21 = V_3 >> V_31 ;
V_36 = F_105 ( V_55 ) ;
if ( ! V_36 ) {
V_36 = F_106 ( V_55 ) ;
if ( ! V_36 )
return NULL ;
F_107 ( V_55 , V_36 ) ;
}
F_108 ( V_55 , V_111 , V_21 , V_112 ) ;
F_2 ( & V_105 ) ;
F_95 ( V_36 , NULL ) ;
F_4 ( & V_105 ) ;
return V_36 ;
}
static void F_109 ( int V_55 , T_6 * V_36 )
{
F_107 ( V_55 , NULL ) ;
F_110 ( V_36 ) ;
return;
}
int F_111 ( int V_55 )
{
T_6 * V_36 ;
int V_61 ;
if ( F_112 ( V_55 ) )
return 0 ;
F_1 () ;
V_36 = F_104 ( V_55 , 0 ) ;
if ( ! V_36 ) {
F_113 ( L_5 , V_55 ) ;
V_61 = - V_113 ;
goto V_114;
}
F_114 ( V_55 ) ;
V_61 = F_115 ( V_55 ) ;
F_7 ( V_61 ) ;
if ( V_36 -> V_115 -> V_116 -> V_42 == NULL ) {
F_2 ( & V_105 ) ;
F_95 ( NULL , NULL ) ;
F_4 ( & V_105 ) ;
}
V_114:
F_3 () ;
return V_61 ;
}
static int F_116 ( T_1 V_3 , T_1 V_4 )
{
T_1 V_21 = V_3 >> V_31 ;
T_1 V_39 = V_4 >> V_31 ;
if ( ( V_21 & ~ V_79 ) ||
( V_39 % V_30 ) || ( ! V_39 ) ) {
F_113 ( L_6 ,
( unsigned long long ) V_3 ,
( unsigned long long ) V_4 ) ;
return - V_77 ;
}
return 0 ;
}
int T_2 F_117 ( int V_55 , T_1 V_3 , T_1 V_4 )
{
T_6 * V_36 = NULL ;
bool V_117 ;
bool V_118 ;
struct V_2 * V_5 ;
int V_61 ;
V_61 = F_116 ( V_3 , V_4 ) ;
if ( V_61 )
return V_61 ;
V_5 = F_5 ( V_3 , V_4 ) ;
V_61 = - V_68 ;
if ( ! V_5 )
return V_61 ;
{
void * V_75 = F_105 ( V_55 ) ;
V_117 = ! V_75 ;
}
F_1 () ;
V_118 = ! F_112 ( V_55 ) ;
if ( V_118 ) {
V_36 = F_104 ( V_55 , V_3 ) ;
V_61 = - V_113 ;
if ( ! V_36 )
goto error;
}
V_61 = F_118 ( V_55 , V_3 , V_4 ) ;
if ( V_61 < 0 )
goto error;
F_114 ( V_55 ) ;
if ( V_118 ) {
V_61 = F_115 ( V_55 ) ;
F_7 ( V_61 ) ;
}
F_119 ( V_3 , V_3 + V_4 , L_1 ) ;
goto V_114;
error:
if ( V_117 )
F_109 ( V_55 , V_36 ) ;
F_11 ( V_5 ) ;
V_114:
F_3 () ;
return V_61 ;
}
static inline int F_120 ( struct V_14 * V_14 )
{
return F_121 ( V_14 ) && F_122 ( V_14 ) >= V_119 ;
}
static struct V_14 * F_123 ( struct V_14 * V_14 )
{
F_7 ( F_124 ( V_14 ) & ( V_120 - 1 ) ) ;
if ( F_120 ( V_14 ) ) {
int V_121 ;
V_121 = F_122 ( V_14 ) ;
if ( ( V_121 < V_122 ) && ( V_121 >= V_119 ) )
return V_14 + ( 1 << V_121 ) ;
}
return V_14 + V_120 ;
}
int F_125 ( unsigned long V_21 , unsigned long V_39 )
{
struct V_14 * V_14 = F_45 ( V_21 ) ;
struct V_14 * V_123 = V_14 + V_39 ;
for (; V_14 < V_123 ; V_14 = F_123 ( V_14 ) ) {
if ( ! F_126 ( V_14 ) )
return 0 ;
F_127 () ;
}
return 1 ;
}
static int F_128 ( unsigned long V_21 , unsigned long V_38 )
{
unsigned long V_37 ;
struct V_42 * V_42 = NULL ;
struct V_14 * V_14 ;
int V_25 ;
for ( V_37 = V_21 ;
V_37 < V_38 ;
V_37 += V_124 ) {
V_25 = 0 ;
while ( ( V_25 < V_124 ) && ! F_129 ( V_37 + V_25 ) )
V_25 ++ ;
if ( V_25 == V_124 )
continue;
V_14 = F_45 ( V_37 + V_25 ) ;
if ( V_42 && F_63 ( V_14 ) != V_42 )
return 0 ;
V_42 = F_63 ( V_14 ) ;
}
return 1 ;
}
static unsigned long F_130 ( unsigned long V_3 , unsigned long V_8 )
{
unsigned long V_37 ;
struct V_14 * V_14 ;
for ( V_37 = V_3 ; V_37 < V_8 ; V_37 ++ ) {
if ( F_29 ( V_37 ) ) {
V_14 = F_45 ( V_37 ) ;
if ( F_131 ( V_14 ) )
return V_37 ;
if ( F_132 ( V_14 ) ) {
if ( F_133 ( V_14 ) )
return V_37 ;
else
V_37 = F_134 ( V_37 + 1 ,
1 << F_135 ( V_14 ) ) - 1 ;
}
}
}
return 0 ;
}
static int
F_136 ( unsigned long V_21 , unsigned long V_38 )
{
unsigned long V_37 ;
struct V_14 * V_14 ;
int V_125 = V_126 ;
int V_127 = 0 ;
int V_61 = 0 ;
F_137 ( V_128 ) ;
for ( V_37 = V_21 ; V_37 < V_38 && V_125 > 0 ; V_37 ++ ) {
if ( ! F_29 ( V_37 ) )
continue;
V_14 = F_45 ( V_37 ) ;
if ( F_132 ( V_14 ) ) {
struct V_14 * V_129 = F_138 ( V_14 ) ;
V_37 = F_124 ( V_129 ) + ( 1 << F_135 ( V_129 ) ) - 1 ;
if ( F_135 ( V_129 ) > V_72 ) {
V_61 = - V_130 ;
break;
}
if ( F_139 ( V_14 , & V_128 ) )
V_125 -= 1 << F_135 ( V_129 ) ;
continue;
}
if ( ! F_140 ( V_14 ) )
continue;
V_61 = F_141 ( V_14 ) ;
if ( ! V_61 ) {
F_142 ( V_14 ) ;
F_143 ( & V_14 -> V_15 , & V_128 ) ;
V_125 -- ;
F_144 ( V_14 , V_131 +
F_145 ( V_14 ) ) ;
} else {
#ifdef F_146
F_98 ( V_132 L_7 ,
V_37 ) ;
F_147 ( V_14 , L_8 ) ;
#endif
F_142 ( V_14 ) ;
if ( F_148 ( V_14 ) ) {
V_127 ++ ;
V_61 = - V_130 ;
break;
}
}
}
if ( ! F_149 ( & V_128 ) ) {
if ( V_127 ) {
F_150 ( & V_128 ) ;
goto V_114;
}
V_61 = F_151 ( & V_128 , V_133 , 0 ,
V_134 , V_135 ) ;
if ( V_61 )
F_150 ( & V_128 ) ;
}
V_114:
return V_61 ;
}
static int
F_152 ( unsigned long V_3 , unsigned long V_39 ,
void * V_136 )
{
F_153 ( V_3 , V_3 + V_39 ) ;
return 0 ;
}
static void
F_154 ( unsigned long V_21 , unsigned long V_38 )
{
F_96 ( V_21 , V_38 - V_21 , NULL ,
F_152 ) ;
}
static int
F_155 ( unsigned long V_21 , unsigned long V_39 ,
void * V_136 )
{
int V_61 ;
long V_137 = * ( long * ) V_136 ;
V_61 = F_156 ( V_21 , V_21 + V_39 , true ) ;
V_137 = V_39 ;
if ( ! V_61 )
* ( long * ) V_136 += V_137 ;
return V_61 ;
}
static long
F_157 ( unsigned long V_21 , unsigned long V_38 )
{
long V_137 = 0 ;
int V_61 ;
V_61 = F_96 ( V_21 , V_38 - V_21 , & V_137 ,
F_155 ) ;
if ( V_61 < 0 )
V_137 = ( long ) V_61 ;
return V_137 ;
}
static bool F_158 ( struct V_42 * V_42 , unsigned long V_39 )
{
return true ;
}
static bool F_158 ( struct V_42 * V_42 , unsigned long V_39 )
{
struct V_35 * V_36 = V_42 -> V_56 ;
unsigned long V_107 = 0 ;
enum V_53 V_138 ;
for ( V_138 = 0 ; V_138 <= V_91 ; V_138 ++ )
V_107 += V_36 -> V_44 [ V_138 ] . V_107 ;
if ( V_107 > V_39 )
return true ;
V_107 = 0 ;
for (; V_138 <= V_93 ; V_138 ++ )
V_107 += V_36 -> V_44 [ V_138 ] . V_107 ;
return V_107 == 0 ;
}
static int T_7 F_159 ( char * V_75 )
{
#ifdef F_160
F_161 ( true ) ;
V_139 = true ;
#else
F_76 ( L_9 ) ;
#endif
return 0 ;
}
static void F_162 ( unsigned long V_39 ,
struct V_42 * V_42 , struct V_89 * V_86 )
{
struct V_35 * V_36 = V_42 -> V_56 ;
unsigned long V_107 = 0 ;
enum V_53 V_138 , V_90 = V_91 ;
if ( V_92 == V_88 )
V_90 = V_93 ;
for ( V_138 = 0 ; V_138 <= V_90 ; V_138 ++ )
V_107 += V_36 -> V_44 [ V_138 ] . V_107 ;
if ( F_43 ( V_42 ) <= V_90 && V_39 >= V_107 )
V_86 -> V_94 = F_66 ( V_42 ) ;
else
V_86 -> V_94 = - 1 ;
#ifdef F_89
V_90 = V_95 ;
if ( V_92 == V_96 )
V_90 = V_93 ;
for (; V_138 <= V_90 ; V_138 ++ )
V_107 += V_36 -> V_44 [ V_138 ] . V_107 ;
if ( F_43 ( V_42 ) <= V_90 && V_39 >= V_107 )
V_86 -> V_97 = F_66 ( V_42 ) ;
else
V_86 -> V_97 = - 1 ;
#else
V_86 -> V_97 = V_86 -> V_94 ;
#endif
V_90 = V_93 ;
for (; V_138 <= V_90 ; V_138 ++ )
V_107 += V_36 -> V_44 [ V_138 ] . V_107 ;
if ( V_39 >= V_107 )
V_86 -> V_98 = F_66 ( V_42 ) ;
else
V_86 -> V_98 = - 1 ;
}
static void F_163 ( int V_40 , struct V_89 * V_86 )
{
if ( V_86 -> V_94 >= 0 )
F_164 ( V_40 , V_88 ) ;
if ( ( V_92 != V_88 ) &&
( V_86 -> V_97 >= 0 ) )
F_164 ( V_40 , V_96 ) ;
if ( ( V_92 != V_96 ) &&
( V_86 -> V_98 >= 0 ) )
F_164 ( V_40 , V_92 ) ;
}
static int T_2 F_165 ( unsigned long V_21 ,
unsigned long V_38 , unsigned long V_140 )
{
unsigned long V_37 , V_39 , V_141 ;
long V_142 ;
int V_61 , V_143 , V_144 , V_40 ;
unsigned long V_9 ;
struct V_42 * V_42 ;
struct V_89 V_86 ;
if ( ! F_166 ( V_21 , V_120 ) )
return - V_77 ;
if ( ! F_166 ( V_38 , V_120 ) )
return - V_77 ;
if ( ! F_128 ( V_21 , V_38 ) )
return - V_77 ;
F_1 () ;
V_42 = F_63 ( F_45 ( V_21 ) ) ;
V_40 = F_66 ( V_42 ) ;
V_39 = V_38 - V_21 ;
V_61 = - V_77 ;
if ( F_43 ( V_42 ) <= V_91 && ! F_158 ( V_42 , V_39 ) )
goto V_114;
V_61 = F_167 ( V_21 , V_38 ,
V_145 , true ) ;
if ( V_61 )
goto V_114;
V_86 . V_21 = V_21 ;
V_86 . V_39 = V_39 ;
F_162 ( V_39 , V_42 , & V_86 ) ;
V_61 = V_89 ( V_146 , & V_86 ) ;
V_61 = F_93 ( V_61 ) ;
if ( V_61 )
goto V_147;
V_37 = V_21 ;
V_141 = V_148 + V_140 ;
V_143 = 0 ;
V_144 = 5 ;
V_149:
V_61 = - V_150 ;
if ( F_168 ( V_148 , V_141 ) )
goto V_147;
V_61 = - V_151 ;
if ( F_169 ( V_152 ) )
goto V_147;
V_61 = 0 ;
if ( V_143 ) {
F_170 () ;
F_127 () ;
F_171 () ;
}
V_37 = F_130 ( V_21 , V_38 ) ;
if ( V_37 ) {
V_61 = F_136 ( V_37 , V_38 ) ;
if ( ! V_61 ) {
V_143 = 1 ;
goto V_149;
} else {
if ( V_61 < 0 )
if ( -- V_144 == 0 )
goto V_147;
F_172 () ;
V_143 = 1 ;
goto V_149;
}
}
F_170 () ;
F_172 () ;
F_171 () ;
F_173 ( V_21 , V_38 ) ;
V_142 = F_157 ( V_21 , V_38 ) ;
if ( V_142 < 0 ) {
V_61 = - V_130 ;
goto V_147;
}
F_98 ( V_153 L_10 , V_142 ) ;
F_154 ( V_21 , V_38 ) ;
F_174 ( V_21 , V_38 , V_145 ) ;
F_81 ( F_45 ( V_21 ) , - V_142 ) ;
V_42 -> V_107 -= V_142 ;
F_49 ( V_42 -> V_56 , & V_9 ) ;
V_42 -> V_56 -> V_108 -= V_142 ;
F_50 ( V_42 -> V_56 , & V_9 ) ;
F_100 () ;
if ( ! F_94 ( V_42 ) ) {
F_97 ( V_42 ) ;
F_2 ( & V_105 ) ;
F_95 ( NULL , NULL ) ;
F_4 ( & V_105 ) ;
} else
F_99 ( V_42 ) ;
F_163 ( V_40 , & V_86 ) ;
if ( V_86 . V_98 >= 0 )
F_175 ( V_40 ) ;
V_109 = F_102 () ;
F_103 () ;
V_89 ( V_154 , & V_86 ) ;
F_3 () ;
return 0 ;
V_147:
F_98 ( V_153 L_11 ,
( unsigned long long ) V_21 << V_31 ,
( ( unsigned long long ) V_38 << V_31 ) - 1 ) ;
V_89 ( V_155 , & V_86 ) ;
F_174 ( V_21 , V_38 , V_145 ) ;
V_114:
F_3 () ;
return V_61 ;
}
int F_176 ( unsigned long V_21 , unsigned long V_39 )
{
return F_165 ( V_21 , V_21 + V_39 , 120 * V_156 ) ;
}
int F_177 ( unsigned long V_21 , unsigned long V_38 ,
void * V_86 , int (* F_178)( struct V_157 * , void * ) )
{
struct V_157 * V_158 = NULL ;
struct V_26 * V_159 ;
unsigned long V_37 , V_24 ;
int V_61 ;
for ( V_37 = V_21 ; V_37 < V_38 ; V_37 += V_30 ) {
V_24 = F_23 ( V_37 ) ;
if ( ! F_179 ( V_24 ) )
continue;
V_159 = F_24 ( V_24 ) ;
if ( V_158 )
if ( ( V_24 >= V_158 -> V_160 ) &&
( V_24 <= V_158 -> V_161 ) )
continue;
V_158 = F_180 ( V_159 , V_158 ) ;
if ( ! V_158 )
continue;
V_61 = F_178 ( V_158 , V_86 ) ;
if ( V_61 ) {
F_181 ( & V_158 -> V_162 . V_163 ) ;
return V_61 ;
}
}
if ( V_158 )
F_181 ( & V_158 -> V_162 . V_163 ) ;
return 0 ;
}
static int F_182 ( struct V_157 * V_158 , void * V_86 )
{
int V_61 = ! F_183 ( V_158 ) ;
if ( F_61 ( V_61 ) ) {
T_8 V_164 , V_165 ;
V_164 = F_184 ( F_72 ( V_158 -> V_160 ) ) ;
V_165 = F_184 ( F_72 ( V_158 -> V_161 + 1 ) ) - 1 ;
F_76 ( L_12
L_13 ,
& V_164 , & V_165 ) ;
}
return V_61 ;
}
static int F_185 ( T_6 * V_36 )
{
int V_166 ;
F_186 (cpu) {
if ( F_187 ( V_166 ) == V_36 -> V_41 )
return - V_130 ;
}
return 0 ;
}
static void F_188 ( T_6 * V_36 )
{
#ifdef F_189
int V_166 ;
F_190 (cpu)
if ( F_187 ( V_166 ) == V_36 -> V_41 )
F_191 ( V_166 ) ;
#endif
}
static int F_192 ( T_6 * V_36 )
{
int V_61 ;
V_61 = F_185 ( V_36 ) ;
if ( V_61 )
return V_61 ;
F_188 ( V_36 ) ;
return 0 ;
}
void F_193 ( int V_55 )
{
T_6 * V_36 = F_105 ( V_55 ) ;
unsigned long V_21 = V_36 -> V_49 ;
unsigned long V_38 = V_21 + V_36 -> V_66 ;
unsigned long V_37 ;
struct V_14 * V_167 = F_26 ( V_36 ) ;
int V_25 ;
for ( V_37 = V_21 ; V_37 < V_38 ; V_37 += V_30 ) {
unsigned long V_24 = F_23 ( V_37 ) ;
if ( ! F_179 ( V_24 ) )
continue;
if ( F_34 ( V_37 ) != V_55 )
continue;
return;
}
if ( F_192 ( V_36 ) )
return;
F_194 ( V_55 ) ;
F_195 ( V_55 ) ;
if ( ! F_196 ( V_167 ) && ! F_197 ( V_167 ) )
return;
for ( V_25 = 0 ; V_25 < V_45 ; V_25 ++ ) {
struct V_42 * V_42 = V_36 -> V_44 + V_25 ;
if ( F_198 ( V_42 -> V_48 ) )
F_199 ( V_42 -> V_48 ) ;
}
memset ( V_36 , 0 , sizeof( * V_36 ) ) ;
}
void T_2 F_200 ( int V_55 , T_1 V_3 , T_1 V_4 )
{
int V_61 ;
F_7 ( F_116 ( V_3 , V_4 ) ) ;
F_1 () ;
V_61 = F_177 ( F_201 ( V_3 ) , F_202 ( V_3 + V_4 - 1 ) , NULL ,
F_182 ) ;
if ( V_61 ) {
F_3 () ;
F_203 () ;
}
F_204 ( V_3 , V_3 + V_4 , L_1 ) ;
F_205 ( V_3 , V_4 ) ;
F_193 ( V_55 ) ;
F_3 () ;
}
