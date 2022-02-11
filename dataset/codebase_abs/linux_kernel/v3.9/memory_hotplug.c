void F_1 ( void )
{
F_2 ( & V_1 ) ;
F_3 () ;
}
void F_4 ( void )
{
F_5 () ;
F_6 ( & V_1 ) ;
}
static struct V_2 * F_7 ( T_1 V_3 , T_1 V_4 )
{
struct V_2 * V_5 ;
V_5 = F_8 ( sizeof( struct V_2 ) , V_6 ) ;
F_9 ( ! V_5 ) ;
V_5 -> V_7 = L_1 ;
V_5 -> V_3 = V_3 ;
V_5 -> V_8 = V_3 + V_4 - 1 ;
V_5 -> V_9 = V_10 | V_11 ;
if ( F_10 ( & V_12 , V_5 ) < 0 ) {
F_11 ( L_2 , V_5 ) ;
F_12 ( V_5 ) ;
V_5 = NULL ;
}
return V_5 ;
}
static void F_13 ( struct V_2 * V_5 )
{
if ( ! V_5 )
return;
F_14 ( V_5 ) ;
F_12 ( V_5 ) ;
return;
}
void F_15 ( unsigned long V_13 , struct V_14 * V_14 ,
unsigned long type )
{
V_14 -> V_15 . V_16 = (struct V_17 * ) type ;
F_16 ( V_14 ) ;
F_17 ( V_14 , V_13 ) ;
F_18 ( & V_14 -> V_18 ) ;
}
void T_2 F_19 ( struct V_14 * V_14 )
{
unsigned long type ;
static F_20 ( V_19 ) ;
type = ( unsigned long ) V_14 -> V_15 . V_16 ;
F_9 ( type < V_20 ||
type > V_21 ) ;
if ( F_21 ( & V_14 -> V_18 ) == 1 ) {
F_22 ( V_14 ) ;
F_17 ( V_14 , 0 ) ;
F_23 ( & V_14 -> V_15 ) ;
F_2 ( & V_19 ) ;
F_24 ( V_14 , 0 ) ;
F_6 ( & V_19 ) ;
V_22 ++ ;
}
}
static void F_25 ( unsigned long V_23 )
{
unsigned long * V_24 , V_25 , V_26 , V_27 ;
struct V_28 * V_29 ;
struct V_14 * V_14 , * V_30 ;
V_26 = F_26 ( V_23 ) ;
V_29 = F_27 ( V_26 ) ;
V_30 = F_28 ( V_29 -> V_31 , V_26 ) ;
V_14 = F_29 ( V_30 ) ;
V_25 = sizeof( struct V_14 ) * V_32 ;
V_25 = F_30 ( V_25 ) >> V_33 ;
for ( V_27 = 0 ; V_27 < V_25 ; V_27 ++ , V_14 ++ )
F_15 ( V_26 , V_14 , V_34 ) ;
V_24 = F_27 ( V_26 ) -> V_35 ;
V_14 = F_29 ( V_24 ) ;
V_25 = F_30 ( F_31 () ) >> V_33 ;
for ( V_27 = 0 ; V_27 < V_25 ; V_27 ++ , V_14 ++ )
F_15 ( V_26 , V_14 , V_36 ) ;
}
static void F_25 ( unsigned long V_23 )
{
unsigned long * V_24 , V_25 , V_26 , V_27 ;
struct V_28 * V_29 ;
struct V_14 * V_14 , * V_30 ;
if ( ! F_32 ( V_23 ) )
return;
V_26 = F_26 ( V_23 ) ;
V_29 = F_27 ( V_26 ) ;
V_30 = F_28 ( V_29 -> V_31 , V_26 ) ;
F_33 ( V_26 , V_30 , V_32 ) ;
V_24 = F_27 ( V_26 ) -> V_35 ;
V_14 = F_29 ( V_24 ) ;
V_25 = F_30 ( F_31 () ) >> V_33 ;
for ( V_27 = 0 ; V_27 < V_25 ; V_27 ++ , V_14 ++ )
F_15 ( V_26 , V_14 , V_36 ) ;
}
void F_34 ( struct V_37 * V_38 )
{
unsigned long V_27 , V_39 , V_40 , V_41 ;
int V_42 = V_38 -> V_43 ;
struct V_14 * V_14 ;
struct V_44 * V_44 ;
V_41 = F_30 ( sizeof( struct V_37 ) ) >> V_33 ;
V_14 = F_29 ( V_38 ) ;
for ( V_27 = 0 ; V_27 < V_41 ; V_27 ++ , V_14 ++ )
F_15 ( V_42 , V_14 , V_45 ) ;
V_44 = & V_38 -> V_46 [ 0 ] ;
for (; V_44 < V_38 -> V_46 + V_47 - 1 ; V_44 ++ ) {
if ( V_44 -> V_48 ) {
V_41 = V_44 -> V_49
* sizeof( V_50 ) ;
V_41 = F_30 ( V_41 ) >> V_33 ;
V_14 = F_29 ( V_44 -> V_48 ) ;
for ( V_27 = 0 ; V_27 < V_41 ; V_27 ++ , V_14 ++ )
F_15 ( V_42 , V_14 , V_45 ) ;
}
}
V_39 = V_38 -> V_51 ;
V_40 = F_35 ( V_38 ) ;
for (; V_39 < V_40 ; V_39 += V_32 ) {
if ( F_32 ( V_39 ) && ( F_36 ( V_39 ) == V_42 ) )
F_25 ( V_39 ) ;
}
}
static void F_37 ( struct V_44 * V_44 , unsigned long V_23 ,
unsigned long V_40 )
{
unsigned long V_52 ;
F_38 ( V_44 ) ;
V_52 = V_44 -> V_53 + V_44 -> V_54 ;
if ( ! V_44 -> V_54 || V_23 < V_44 -> V_53 )
V_44 -> V_53 = V_23 ;
V_44 -> V_54 = F_39 ( V_52 , V_40 ) -
V_44 -> V_53 ;
F_40 ( V_44 ) ;
}
static void F_41 ( struct V_44 * V_44 , unsigned long V_23 ,
unsigned long V_40 )
{
F_38 ( V_44 ) ;
if ( V_40 - V_23 ) {
V_44 -> V_53 = V_23 ;
V_44 -> V_54 = V_40 - V_23 ;
} else {
V_44 -> V_53 = 0 ;
V_44 -> V_54 = 0 ;
}
F_40 ( V_44 ) ;
}
static void F_42 ( struct V_44 * V_44 , unsigned long V_23 ,
unsigned long V_40 )
{
enum V_55 V_56 = F_43 ( V_44 ) ;
int V_57 = V_44 -> V_58 -> V_43 ;
unsigned long V_39 ;
for ( V_39 = V_23 ; V_39 < V_40 ; V_39 ++ )
F_44 ( F_45 ( V_39 ) , V_56 , V_57 , V_39 ) ;
}
static int T_2 F_46 ( struct V_44 * V_44 ,
unsigned long V_23 , unsigned long V_59 )
{
if ( ! F_47 ( V_44 ) )
return F_48 ( V_44 , V_23 , V_59 ,
V_60 ) ;
return 0 ;
}
static int T_3 F_49 ( struct V_44 * V_61 , struct V_44 * V_62 ,
unsigned long V_23 , unsigned long V_40 )
{
int V_63 ;
unsigned long V_9 ;
unsigned long V_64 ;
V_63 = F_46 ( V_61 , V_23 , V_40 - V_23 ) ;
if ( V_63 )
return V_63 ;
F_50 ( V_61 -> V_58 , & V_9 ) ;
if ( V_40 > F_51 ( V_62 ) )
goto V_65;
if ( V_23 > V_62 -> V_53 )
goto V_65;
if ( V_40 <= V_62 -> V_53 )
goto V_65;
if ( V_61 -> V_54 )
V_64 = V_61 -> V_53 ;
else
V_64 = V_23 ;
F_41 ( V_61 , V_64 , V_40 ) ;
F_41 ( V_62 , V_40 , F_51 ( V_62 ) ) ;
F_52 ( V_61 -> V_58 , & V_9 ) ;
F_42 ( V_61 , V_23 , V_40 ) ;
return 0 ;
V_65:
F_52 ( V_61 -> V_58 , & V_9 ) ;
return - 1 ;
}
static int T_3 F_53 ( struct V_44 * V_61 , struct V_44 * V_62 ,
unsigned long V_23 , unsigned long V_40 )
{
int V_63 ;
unsigned long V_9 ;
unsigned long V_66 ;
V_63 = F_46 ( V_62 , V_23 , V_40 - V_23 ) ;
if ( V_63 )
return V_63 ;
F_50 ( V_61 -> V_58 , & V_9 ) ;
if ( V_61 -> V_53 > V_23 )
goto V_65;
if ( F_51 ( V_61 ) > V_40 )
goto V_65;
if ( V_23 >= F_51 ( V_61 ) )
goto V_65;
if ( V_62 -> V_54 )
V_66 = F_51 ( V_62 ) ;
else
V_66 = V_40 ;
F_41 ( V_61 , V_61 -> V_53 , V_23 ) ;
F_41 ( V_62 , V_23 , V_66 ) ;
F_52 ( V_61 -> V_58 , & V_9 ) ;
F_42 ( V_62 , V_23 , V_40 ) ;
return 0 ;
V_65:
F_52 ( V_61 -> V_58 , & V_9 ) ;
return - 1 ;
}
static void F_54 ( struct V_37 * V_38 , unsigned long V_23 ,
unsigned long V_40 )
{
unsigned long V_67 =
V_38 -> V_51 + V_38 -> V_68 ;
if ( ! V_38 -> V_68 || V_23 < V_38 -> V_51 )
V_38 -> V_51 = V_23 ;
V_38 -> V_68 = F_39 ( V_67 , V_40 ) -
V_38 -> V_51 ;
}
static int T_3 F_55 ( struct V_44 * V_44 , unsigned long V_69 )
{
struct V_37 * V_38 = V_44 -> V_58 ;
int V_41 = V_32 ;
int V_57 = V_38 -> V_43 ;
int V_55 ;
unsigned long V_9 ;
int V_63 ;
V_55 = V_44 - V_38 -> V_46 ;
V_63 = F_46 ( V_44 , V_69 , V_41 ) ;
if ( V_63 )
return V_63 ;
F_50 ( V_44 -> V_58 , & V_9 ) ;
F_37 ( V_44 , V_69 , V_69 + V_41 ) ;
F_54 ( V_44 -> V_58 , V_69 ,
V_69 + V_41 ) ;
F_52 ( V_44 -> V_58 , & V_9 ) ;
F_56 ( V_41 , V_57 , V_55 ,
V_69 , V_60 ) ;
return 0 ;
}
static int T_3 F_57 ( int V_57 , struct V_44 * V_44 ,
unsigned long V_69 )
{
int V_41 = V_32 ;
int V_63 ;
if ( F_32 ( V_69 ) )
return - V_70 ;
V_63 = F_58 ( V_44 , V_69 , V_41 ) ;
if ( V_63 < 0 )
return V_63 ;
V_63 = F_55 ( V_44 , V_69 ) ;
if ( V_63 < 0 )
return V_63 ;
return F_59 ( V_57 , F_60 ( V_69 ) ) ;
}
static int F_61 ( int V_57 , struct V_44 * V_44 ,
unsigned long V_23 ,
unsigned long V_40 )
{
struct V_28 * V_29 ;
for (; V_23 < V_40 ; V_23 += V_32 ) {
V_29 = F_60 ( V_23 ) ;
if ( F_62 ( ! F_63 ( V_29 ) ) )
continue;
if ( F_62 ( F_36 ( V_23 ) != V_57 ) )
continue;
if ( V_44 && V_44 != F_64 ( F_45 ( V_23 ) ) )
continue;
return V_23 ;
}
return 0 ;
}
static int F_65 ( int V_57 , struct V_44 * V_44 ,
unsigned long V_23 ,
unsigned long V_40 )
{
struct V_28 * V_29 ;
unsigned long V_39 ;
V_39 = V_40 - 1 ;
for (; V_39 >= V_23 ; V_39 -= V_32 ) {
V_29 = F_60 ( V_39 ) ;
if ( F_62 ( ! F_63 ( V_29 ) ) )
continue;
if ( F_62 ( F_36 ( V_39 ) != V_57 ) )
continue;
if ( V_44 && V_44 != F_64 ( F_45 ( V_39 ) ) )
continue;
return V_39 ;
}
return 0 ;
}
static void F_66 ( struct V_44 * V_44 , unsigned long V_23 ,
unsigned long V_40 )
{
unsigned long V_53 = V_44 -> V_53 ;
unsigned long F_51 = V_44 -> V_53 + V_44 -> V_54 ;
unsigned long V_39 ;
struct V_28 * V_29 ;
int V_57 = F_67 ( V_44 ) ;
F_38 ( V_44 ) ;
if ( V_53 == V_23 ) {
V_39 = F_61 ( V_57 , V_44 , V_40 ,
F_51 ) ;
if ( V_39 ) {
V_44 -> V_53 = V_39 ;
V_44 -> V_54 = F_51 - V_39 ;
}
} else if ( F_51 == V_40 ) {
V_39 = F_65 ( V_57 , V_44 , V_53 ,
V_23 ) ;
if ( V_39 )
V_44 -> V_54 = V_39 - V_53 + 1 ;
}
V_39 = V_53 ;
for (; V_39 < F_51 ; V_39 += V_32 ) {
V_29 = F_60 ( V_39 ) ;
if ( F_62 ( ! F_63 ( V_29 ) ) )
continue;
if ( F_64 ( F_45 ( V_39 ) ) != V_44 )
continue;
if ( V_23 == V_39 )
continue;
F_40 ( V_44 ) ;
return;
}
V_44 -> V_53 = 0 ;
V_44 -> V_54 = 0 ;
F_40 ( V_44 ) ;
}
static void F_68 ( struct V_37 * V_38 ,
unsigned long V_23 , unsigned long V_40 )
{
unsigned long V_71 = V_38 -> V_51 ;
unsigned long F_35 =
V_38 -> V_51 + V_38 -> V_68 ;
unsigned long V_39 ;
struct V_28 * V_29 ;
int V_57 = V_38 -> V_43 ;
if ( V_71 == V_23 ) {
V_39 = F_61 ( V_57 , NULL , V_40 ,
F_35 ) ;
if ( V_39 ) {
V_38 -> V_51 = V_39 ;
V_38 -> V_68 = F_35 - V_39 ;
}
} else if ( F_35 == V_40 ) {
V_39 = F_65 ( V_57 , NULL , V_71 ,
V_23 ) ;
if ( V_39 )
V_38 -> V_68 = V_39 - V_71 + 1 ;
}
V_39 = V_71 ;
for (; V_39 < F_35 ; V_39 += V_32 ) {
V_29 = F_60 ( V_39 ) ;
if ( F_62 ( ! F_63 ( V_29 ) ) )
continue;
if ( F_36 ( V_39 ) != V_57 )
continue;
if ( V_23 == V_39 )
continue;
return;
}
V_38 -> V_51 = 0 ;
V_38 -> V_68 = 0 ;
}
static void F_69 ( struct V_44 * V_44 , unsigned long V_23 )
{
struct V_37 * V_38 = V_44 -> V_58 ;
int V_41 = V_32 ;
int V_55 ;
unsigned long V_9 ;
V_55 = V_44 - V_38 -> V_46 ;
F_50 ( V_44 -> V_58 , & V_9 ) ;
F_66 ( V_44 , V_23 , V_23 + V_41 ) ;
F_68 ( V_38 , V_23 , V_23 + V_41 ) ;
F_52 ( V_44 -> V_58 , & V_9 ) ;
}
static int F_70 ( struct V_44 * V_44 , struct V_28 * V_29 )
{
unsigned long V_23 ;
int V_72 ;
int V_63 = - V_73 ;
if ( ! F_63 ( V_29 ) )
return V_63 ;
V_63 = F_71 ( V_29 ) ;
if ( V_63 )
return V_63 ;
V_72 = F_72 ( V_29 ) ;
V_23 = F_73 ( V_72 ) ;
F_69 ( V_44 , V_23 ) ;
F_74 ( V_44 , V_29 ) ;
return 0 ;
}
int T_2 F_75 ( int V_57 , struct V_44 * V_44 , unsigned long V_69 ,
unsigned long V_41 )
{
unsigned long V_27 ;
int V_74 = 0 ;
int V_75 , V_76 ;
V_75 = F_26 ( V_69 ) ;
V_76 = F_26 ( V_69 + V_41 - 1 ) ;
for ( V_27 = V_75 ; V_27 <= V_76 ; V_27 ++ ) {
V_74 = F_57 ( V_57 , V_44 , V_27 << V_77 ) ;
if ( V_74 && ( V_74 != - V_70 ) )
break;
V_74 = 0 ;
}
return V_74 ;
}
int F_76 ( struct V_44 * V_44 , unsigned long V_69 ,
unsigned long V_41 )
{
unsigned long V_27 , V_63 = 0 ;
int V_78 ;
F_9 ( V_69 & ~ V_79 ) ;
F_9 ( V_41 % V_32 ) ;
F_77 ( V_69 << V_33 , V_41 * V_80 ) ;
V_78 = V_41 / V_32 ;
for ( V_27 = 0 ; V_27 < V_78 ; V_27 ++ ) {
unsigned long V_39 = V_69 + V_27 * V_32 ;
V_63 = F_70 ( V_44 , F_60 ( V_39 ) ) ;
if ( V_63 )
break;
}
return V_63 ;
}
int F_78 ( T_4 V_81 )
{
int V_82 = - V_73 ;
F_1 () ;
if ( V_83 == V_84 ) {
V_83 = V_81 ;
V_82 = 0 ;
}
F_4 () ;
return V_82 ;
}
int F_79 ( T_4 V_81 )
{
int V_82 = - V_73 ;
F_1 () ;
if ( V_83 == V_81 ) {
V_83 = V_84 ;
V_82 = 0 ;
}
F_4 () ;
return V_82 ;
}
void F_80 ( struct V_14 * V_14 )
{
unsigned long V_39 = F_81 ( V_14 ) ;
if ( V_39 >= V_85 )
V_85 = V_39 + 1 ;
}
void F_82 ( struct V_14 * V_14 )
{
V_22 ++ ;
#ifdef F_83
if ( F_84 ( V_14 ) )
V_86 ++ ;
#endif
}
void F_85 ( struct V_14 * V_14 )
{
F_86 ( V_14 ) ;
F_87 ( V_14 ) ;
F_88 ( V_14 ) ;
}
static void V_84 ( struct V_14 * V_14 )
{
F_80 ( V_14 ) ;
F_82 ( V_14 ) ;
F_85 ( V_14 ) ;
}
static int F_89 ( unsigned long V_23 , unsigned long V_41 ,
void * V_87 )
{
unsigned long V_27 ;
unsigned long V_88 = * ( unsigned long * ) V_87 ;
struct V_14 * V_14 ;
if ( F_90 ( F_45 ( V_23 ) ) )
for ( V_27 = 0 ; V_27 < V_41 ; V_27 ++ ) {
V_14 = F_45 ( V_23 + V_27 ) ;
(* V_83)( V_14 ) ;
V_88 ++ ;
}
* ( unsigned long * ) V_87 = V_88 ;
return 0 ;
}
static bool F_91 ( struct V_44 * V_44 )
{
return true ;
}
static bool F_91 ( struct V_44 * V_44 )
{
return F_92 ( F_67 ( V_44 ) , V_89 ) ;
}
static void F_93 ( unsigned long V_41 ,
struct V_44 * V_44 , struct V_90 * V_87 )
{
int V_57 = F_67 ( V_44 ) ;
enum V_55 V_91 = V_92 ;
if ( V_93 == V_89 )
V_91 = V_94 ;
if ( F_43 ( V_44 ) <= V_91 && ! F_92 ( V_57 , V_89 ) )
V_87 -> V_95 = V_57 ;
else
V_87 -> V_95 = - 1 ;
#ifdef F_83
V_91 = V_96 ;
if ( V_93 == V_97 )
V_91 = V_94 ;
if ( F_43 ( V_44 ) <= V_91 && ! F_92 ( V_57 , V_97 ) )
V_87 -> V_98 = V_57 ;
else
V_87 -> V_98 = - 1 ;
#else
V_87 -> V_98 = V_87 -> V_95 ;
#endif
if ( ! F_92 ( V_57 , V_93 ) )
V_87 -> V_99 = V_57 ;
else
V_87 -> V_99 = - 1 ;
}
static void F_94 ( int V_42 , struct V_90 * V_87 )
{
if ( V_87 -> V_95 >= 0 )
F_95 ( V_42 , V_89 ) ;
if ( V_87 -> V_98 >= 0 )
F_95 ( V_42 , V_97 ) ;
F_95 ( V_42 , V_93 ) ;
}
int T_2 F_96 ( unsigned long V_39 , unsigned long V_41 , int V_100 )
{
unsigned long V_88 = 0 ;
struct V_44 * V_44 ;
int V_101 = 0 ;
int V_57 ;
int V_63 ;
struct V_90 V_87 ;
F_1 () ;
V_44 = F_64 ( F_45 ( V_39 ) ) ;
if ( ( F_43 ( V_44 ) > V_92 || V_100 == V_102 ) &&
! F_91 ( V_44 ) ) {
F_4 () ;
return - 1 ;
}
if ( V_100 == V_103 && F_43 ( V_44 ) == V_94 ) {
if ( F_49 ( V_44 - 1 , V_44 , V_39 , V_39 + V_41 ) ) {
F_4 () ;
return - 1 ;
}
}
if ( V_100 == V_102 && F_43 ( V_44 ) == V_94 - 1 ) {
if ( F_53 ( V_44 , V_44 + 1 , V_39 , V_39 + V_41 ) ) {
F_4 () ;
return - 1 ;
}
}
V_44 = F_64 ( F_45 ( V_39 ) ) ;
V_87 . V_23 = V_39 ;
V_87 . V_41 = V_41 ;
F_93 ( V_41 , V_44 , & V_87 ) ;
V_57 = F_97 ( F_45 ( V_39 ) ) ;
V_63 = V_90 ( V_104 , & V_87 ) ;
V_63 = F_98 ( V_63 ) ;
if ( V_63 ) {
V_90 ( V_105 , & V_87 ) ;
F_4 () ;
return V_63 ;
}
F_2 ( & V_106 ) ;
if ( ! F_99 ( V_44 ) ) {
V_101 = 1 ;
F_100 ( NULL , V_44 ) ;
}
V_63 = F_101 ( V_39 , V_41 , & V_88 ,
F_89 ) ;
if ( V_63 ) {
if ( V_101 )
F_102 ( V_44 ) ;
F_6 ( & V_106 ) ;
F_11 ( V_107 L_3 ,
( unsigned long long ) V_39 << V_33 ,
( ( ( unsigned long long ) V_39 + V_41 )
<< V_33 ) - 1 ) ;
V_90 ( V_105 , & V_87 ) ;
F_4 () ;
return V_63 ;
}
V_44 -> V_108 += V_88 ;
V_44 -> V_109 += V_88 ;
V_44 -> V_58 -> V_110 += V_88 ;
if ( V_88 ) {
F_94 ( F_67 ( V_44 ) , & V_87 ) ;
if ( V_101 )
F_100 ( NULL , NULL ) ;
else
F_103 ( V_44 ) ;
}
F_6 ( & V_106 ) ;
F_104 () ;
if ( V_88 )
F_105 ( F_67 ( V_44 ) ) ;
V_111 = F_106 () ;
F_107 () ;
if ( V_88 )
V_90 ( V_112 , & V_87 ) ;
F_4 () ;
return 0 ;
}
static T_5 T_2 * F_108 ( int V_57 , T_1 V_3 )
{
struct V_37 * V_38 ;
unsigned long V_113 [ V_47 ] = { 0 } ;
unsigned long V_114 [ V_47 ] = { 0 } ;
unsigned long V_23 = V_3 >> V_33 ;
V_38 = F_109 ( V_57 ) ;
if ( ! V_38 ) {
V_38 = F_110 ( V_57 ) ;
if ( ! V_38 )
return NULL ;
F_111 ( V_57 , V_38 ) ;
}
F_112 ( V_57 , V_113 , V_23 , V_114 ) ;
F_2 ( & V_106 ) ;
F_100 ( V_38 , NULL ) ;
F_6 ( & V_106 ) ;
return V_38 ;
}
static void F_113 ( int V_57 , T_5 * V_38 )
{
F_111 ( V_57 , NULL ) ;
F_114 ( V_38 ) ;
return;
}
int F_115 ( int V_57 )
{
T_5 * V_38 ;
int V_63 ;
F_1 () ;
V_38 = F_108 ( V_57 , 0 ) ;
if ( ! V_38 ) {
V_63 = - V_115 ;
goto V_116;
}
F_116 ( V_57 ) ;
V_63 = F_117 ( V_57 ) ;
F_9 ( V_63 ) ;
V_116:
F_4 () ;
return V_63 ;
}
int T_2 F_118 ( int V_57 , T_1 V_3 , T_1 V_4 )
{
T_5 * V_38 = NULL ;
bool V_117 ;
bool V_118 ;
struct V_2 * V_5 ;
int V_63 ;
F_1 () ;
V_5 = F_7 ( V_3 , V_4 ) ;
V_63 = - V_70 ;
if ( ! V_5 )
goto V_116;
{
void * V_119 = F_109 ( V_57 ) ;
V_117 = ! V_119 ;
}
V_118 = ! F_119 ( V_57 ) ;
if ( V_118 ) {
V_38 = F_108 ( V_57 , V_3 ) ;
V_63 = - V_115 ;
if ( ! V_38 )
goto error;
}
V_63 = F_120 ( V_57 , V_3 , V_4 ) ;
if ( V_63 < 0 )
goto error;
F_116 ( V_57 ) ;
if ( V_118 ) {
V_63 = F_117 ( V_57 ) ;
F_9 ( V_63 ) ;
}
F_121 ( V_3 , V_3 + V_4 , L_1 ) ;
goto V_116;
error:
if ( V_117 )
F_113 ( V_57 , V_38 ) ;
F_13 ( V_5 ) ;
V_116:
F_4 () ;
return V_63 ;
}
static inline int F_122 ( struct V_14 * V_14 )
{
return F_123 ( V_14 ) && F_124 ( V_14 ) >= V_120 ;
}
static struct V_14 * F_125 ( struct V_14 * V_14 )
{
F_9 ( F_81 ( V_14 ) & ( V_121 - 1 ) ) ;
if ( F_122 ( V_14 ) ) {
int V_122 ;
V_122 = F_124 ( V_14 ) ;
if ( ( V_122 < V_123 ) && ( V_122 >= V_120 ) )
return V_14 + ( 1 << V_122 ) ;
}
return V_14 + V_121 ;
}
int F_126 ( unsigned long V_23 , unsigned long V_41 )
{
struct V_14 * V_14 = F_45 ( V_23 ) ;
struct V_14 * V_124 = V_14 + V_41 ;
for (; V_14 < V_124 ; V_14 = F_125 ( V_14 ) ) {
if ( ! F_127 ( V_14 ) )
return 0 ;
F_128 () ;
}
return 1 ;
}
static int F_129 ( unsigned long V_23 , unsigned long V_40 )
{
unsigned long V_39 ;
struct V_44 * V_44 = NULL ;
struct V_14 * V_14 ;
int V_27 ;
for ( V_39 = V_23 ;
V_39 < V_40 ;
V_39 += V_125 ) {
V_27 = 0 ;
while ( ( V_27 < V_125 ) && ! F_130 ( V_39 + V_27 ) )
V_27 ++ ;
if ( V_27 == V_125 )
continue;
V_14 = F_45 ( V_39 + V_27 ) ;
if ( V_44 && F_64 ( V_14 ) != V_44 )
return 0 ;
V_44 = F_64 ( V_14 ) ;
}
return 1 ;
}
static unsigned long F_131 ( unsigned long V_3 , unsigned long V_8 )
{
unsigned long V_39 ;
struct V_14 * V_14 ;
for ( V_39 = V_3 ; V_39 < V_8 ; V_39 ++ ) {
if ( F_32 ( V_39 ) ) {
V_14 = F_45 ( V_39 ) ;
if ( F_132 ( V_14 ) )
return V_39 ;
}
}
return 0 ;
}
static int
F_133 ( unsigned long V_23 , unsigned long V_40 )
{
unsigned long V_39 ;
struct V_14 * V_14 ;
int V_126 = V_127 ;
int V_128 = 0 ;
int V_63 = 0 ;
F_134 ( V_129 ) ;
for ( V_39 = V_23 ; V_39 < V_40 && V_126 > 0 ; V_39 ++ ) {
if ( ! F_32 ( V_39 ) )
continue;
V_14 = F_45 ( V_39 ) ;
if ( ! F_135 ( V_14 ) )
continue;
V_63 = F_136 ( V_14 ) ;
if ( ! V_63 ) {
F_137 ( V_14 ) ;
F_138 ( & V_14 -> V_15 , & V_129 ) ;
V_126 -- ;
F_139 ( V_14 , V_130 +
F_140 ( V_14 ) ) ;
} else {
#ifdef F_141
F_11 ( V_131 L_4 ,
V_39 ) ;
F_142 ( V_14 ) ;
#endif
F_137 ( V_14 ) ;
if ( F_143 ( V_14 ) ) {
V_128 ++ ;
V_63 = - V_132 ;
break;
}
}
}
if ( ! F_144 ( & V_129 ) ) {
if ( V_128 ) {
F_145 ( & V_129 ) ;
goto V_116;
}
V_63 = F_146 ( & V_129 , V_133 , 0 ,
V_134 , V_135 ) ;
if ( V_63 )
F_145 ( & V_129 ) ;
}
V_116:
return V_63 ;
}
static int
F_147 ( unsigned long V_3 , unsigned long V_41 ,
void * V_136 )
{
F_148 ( V_3 , V_3 + V_41 ) ;
return 0 ;
}
static void
F_149 ( unsigned long V_23 , unsigned long V_40 )
{
F_101 ( V_23 , V_40 - V_23 , NULL ,
F_147 ) ;
}
static int
F_150 ( unsigned long V_23 , unsigned long V_41 ,
void * V_136 )
{
int V_63 ;
long V_137 = * ( long * ) V_136 ;
V_63 = F_151 ( V_23 , V_23 + V_41 , true ) ;
V_137 = V_41 ;
if ( ! V_63 )
* ( long * ) V_136 += V_137 ;
return V_63 ;
}
static long
F_152 ( unsigned long V_23 , unsigned long V_40 )
{
long V_137 = 0 ;
int V_63 ;
V_63 = F_101 ( V_23 , V_40 - V_23 , & V_137 ,
F_150 ) ;
if ( V_63 < 0 )
V_137 = ( long ) V_63 ;
return V_137 ;
}
static bool F_153 ( struct V_44 * V_44 , unsigned long V_41 )
{
return true ;
}
static bool F_153 ( struct V_44 * V_44 , unsigned long V_41 )
{
struct V_37 * V_38 = V_44 -> V_58 ;
unsigned long V_109 = 0 ;
enum V_55 V_138 ;
for ( V_138 = 0 ; V_138 <= V_92 ; V_138 ++ )
V_109 += V_38 -> V_46 [ V_138 ] . V_109 ;
if ( V_109 > V_41 )
return true ;
V_109 = 0 ;
for (; V_138 <= V_94 ; V_138 ++ )
V_109 += V_38 -> V_46 [ V_138 ] . V_109 ;
return V_109 == 0 ;
}
static void F_154 ( unsigned long V_41 ,
struct V_44 * V_44 , struct V_90 * V_87 )
{
struct V_37 * V_38 = V_44 -> V_58 ;
unsigned long V_109 = 0 ;
enum V_55 V_138 , V_91 = V_92 ;
if ( V_93 == V_89 )
V_91 = V_94 ;
for ( V_138 = 0 ; V_138 <= V_91 ; V_138 ++ )
V_109 += V_38 -> V_46 [ V_138 ] . V_109 ;
if ( F_43 ( V_44 ) <= V_91 && V_41 >= V_109 )
V_87 -> V_95 = F_67 ( V_44 ) ;
else
V_87 -> V_95 = - 1 ;
#ifdef F_83
V_91 = V_96 ;
if ( V_93 == V_97 )
V_91 = V_94 ;
for (; V_138 <= V_91 ; V_138 ++ )
V_109 += V_38 -> V_46 [ V_138 ] . V_109 ;
if ( F_43 ( V_44 ) <= V_91 && V_41 >= V_109 )
V_87 -> V_98 = F_67 ( V_44 ) ;
else
V_87 -> V_98 = - 1 ;
#else
V_87 -> V_98 = V_87 -> V_95 ;
#endif
V_91 = V_94 ;
for (; V_138 <= V_91 ; V_138 ++ )
V_109 += V_38 -> V_46 [ V_138 ] . V_109 ;
if ( V_41 >= V_109 )
V_87 -> V_99 = F_67 ( V_44 ) ;
else
V_87 -> V_99 = - 1 ;
}
static void F_155 ( int V_42 , struct V_90 * V_87 )
{
if ( V_87 -> V_95 >= 0 )
F_156 ( V_42 , V_89 ) ;
if ( ( V_93 != V_89 ) &&
( V_87 -> V_98 >= 0 ) )
F_156 ( V_42 , V_97 ) ;
if ( ( V_93 != V_97 ) &&
( V_87 -> V_99 >= 0 ) )
F_156 ( V_42 , V_93 ) ;
}
static int T_2 F_157 ( unsigned long V_23 ,
unsigned long V_40 , unsigned long V_139 )
{
unsigned long V_39 , V_41 , V_140 ;
long V_141 ;
int V_63 , V_142 , V_143 , V_42 ;
struct V_44 * V_44 ;
struct V_90 V_87 ;
F_9 ( V_23 >= V_40 ) ;
if ( ! F_158 ( V_23 , V_121 ) )
return - V_73 ;
if ( ! F_158 ( V_40 , V_121 ) )
return - V_73 ;
if ( ! F_129 ( V_23 , V_40 ) )
return - V_73 ;
F_1 () ;
V_44 = F_64 ( F_45 ( V_23 ) ) ;
V_42 = F_67 ( V_44 ) ;
V_41 = V_40 - V_23 ;
V_63 = - V_73 ;
if ( F_43 ( V_44 ) <= V_92 && ! F_153 ( V_44 , V_41 ) )
goto V_116;
V_63 = F_159 ( V_23 , V_40 ,
V_144 , true ) ;
if ( V_63 )
goto V_116;
V_87 . V_23 = V_23 ;
V_87 . V_41 = V_41 ;
F_154 ( V_41 , V_44 , & V_87 ) ;
V_63 = V_90 ( V_145 , & V_87 ) ;
V_63 = F_98 ( V_63 ) ;
if ( V_63 )
goto V_146;
V_39 = V_23 ;
V_140 = V_147 + V_139 ;
V_142 = 0 ;
V_143 = 5 ;
V_148:
V_63 = - V_149 ;
if ( F_160 ( V_147 , V_140 ) )
goto V_146;
V_63 = - V_150 ;
if ( F_161 ( V_151 ) )
goto V_146;
V_63 = 0 ;
if ( V_142 ) {
F_162 () ;
F_128 () ;
F_163 () ;
}
V_39 = F_131 ( V_23 , V_40 ) ;
if ( V_39 ) {
V_63 = F_133 ( V_39 , V_40 ) ;
if ( ! V_63 ) {
V_142 = 1 ;
goto V_148;
} else {
if ( V_63 < 0 )
if ( -- V_143 == 0 )
goto V_146;
F_164 () ;
V_142 = 1 ;
goto V_148;
}
}
F_162 () ;
F_164 () ;
F_163 () ;
V_141 = F_152 ( V_23 , V_40 ) ;
if ( V_141 < 0 ) {
V_63 = - V_132 ;
goto V_146;
}
F_11 ( V_152 L_5 , V_141 ) ;
F_149 ( V_23 , V_40 ) ;
F_165 ( V_23 , V_40 , V_144 ) ;
V_44 -> V_108 -= V_141 ;
V_44 -> V_109 -= V_141 ;
V_44 -> V_58 -> V_110 -= V_141 ;
V_22 -= V_141 ;
F_104 () ;
if ( ! F_99 ( V_44 ) ) {
F_102 ( V_44 ) ;
F_2 ( & V_106 ) ;
F_100 ( NULL , NULL ) ;
F_6 ( & V_106 ) ;
} else
F_103 ( V_44 ) ;
F_155 ( V_42 , & V_87 ) ;
if ( V_87 . V_99 >= 0 )
F_166 ( V_42 ) ;
V_111 = F_106 () ;
F_107 () ;
V_90 ( V_153 , & V_87 ) ;
F_4 () ;
return 0 ;
V_146:
F_11 ( V_152 L_6 ,
( unsigned long long ) V_23 << V_33 ,
( ( unsigned long long ) V_40 << V_33 ) - 1 ) ;
V_90 ( V_154 , & V_87 ) ;
F_165 ( V_23 , V_40 , V_144 ) ;
V_116:
F_4 () ;
return V_63 ;
}
int F_167 ( unsigned long V_23 , unsigned long V_41 )
{
return F_157 ( V_23 , V_23 + V_41 , 120 * V_155 ) ;
}
static int F_168 ( unsigned long V_23 , unsigned long V_40 ,
void * V_87 , int (* F_169)( struct V_156 * , void * ) )
{
struct V_156 * V_157 = NULL ;
struct V_28 * V_158 ;
unsigned long V_39 , V_26 ;
int V_63 ;
for ( V_39 = V_23 ; V_39 < V_40 ; V_39 += V_32 ) {
V_26 = F_26 ( V_39 ) ;
if ( ! F_170 ( V_26 ) )
continue;
V_158 = F_27 ( V_26 ) ;
if ( V_157 )
if ( ( V_26 >= V_157 -> V_159 ) &&
( V_26 <= V_157 -> V_160 ) )
continue;
V_157 = F_171 ( V_158 , V_157 ) ;
if ( ! V_157 )
continue;
V_63 = F_169 ( V_157 , V_87 ) ;
if ( V_63 ) {
F_172 ( & V_157 -> V_161 . V_162 ) ;
return V_63 ;
}
}
if ( V_157 )
F_172 ( & V_157 -> V_161 . V_162 ) ;
return 0 ;
}
static int F_173 ( struct V_156 * V_157 , void * V_87 )
{
int * V_63 = V_87 ;
int error = F_174 ( V_157 ) ;
if ( error != 0 && * V_63 == 0 )
* V_63 = error ;
return 0 ;
}
static int F_175 ( struct V_156 * V_157 , void * V_87 )
{
int V_63 = ! F_176 ( V_157 ) ;
if ( F_62 ( V_63 ) )
F_177 ( L_7
L_8 ,
F_178 ( F_73 ( V_157 -> V_159 ) ) ,
F_178 ( F_73 ( V_157 -> V_160 + 1 ) ) - 1 ) ;
return V_63 ;
}
static int F_179 ( void * V_136 )
{
struct V_37 * V_38 = V_136 ;
int V_163 ;
F_180 (cpu) {
if ( F_181 ( V_163 ) == V_38 -> V_43 )
return - V_132 ;
}
return 0 ;
}
static void F_182 ( void * V_136 )
{
#ifdef F_183
struct V_37 * V_38 = V_136 ;
int V_163 ;
F_184 (cpu)
if ( F_181 ( V_163 ) == V_38 -> V_43 )
F_185 ( V_163 ) ;
#endif
}
static int F_186 ( void * V_136 )
{
int V_63 = F_179 ( V_136 ) ;
if ( V_63 )
return V_63 ;
F_182 ( V_136 ) ;
return 0 ;
}
void F_187 ( int V_57 )
{
T_5 * V_38 = F_109 ( V_57 ) ;
unsigned long V_23 = V_38 -> V_51 ;
unsigned long V_40 = V_23 + V_38 -> V_68 ;
unsigned long V_39 ;
struct V_14 * V_164 = F_29 ( V_38 ) ;
int V_27 ;
for ( V_39 = V_23 ; V_39 < V_40 ; V_39 += V_32 ) {
unsigned long V_26 = F_26 ( V_39 ) ;
if ( ! F_170 ( V_26 ) )
continue;
if ( F_36 ( V_39 ) != V_57 )
continue;
return;
}
if ( F_188 ( F_186 , V_38 , NULL ) )
return;
F_189 ( V_57 ) ;
F_190 ( V_57 ) ;
if ( ! F_191 ( V_164 ) && ! F_192 ( V_164 ) )
return;
for ( V_27 = 0 ; V_27 < V_47 ; V_27 ++ ) {
struct V_44 * V_44 = V_38 -> V_46 + V_27 ;
if ( F_193 ( V_44 -> V_48 ) )
F_194 ( V_44 -> V_48 ) ;
}
memset ( V_38 , 0 , sizeof( * V_38 ) ) ;
}
int T_2 F_195 ( int V_57 , T_1 V_3 , T_1 V_4 )
{
unsigned long V_23 , V_40 ;
int V_63 = 0 ;
int V_165 = 1 ;
V_23 = F_196 ( V_3 ) ;
V_40 = F_197 ( V_3 + V_4 - 1 ) ;
V_148:
F_168 ( V_23 , V_40 , & V_63 ,
F_173 ) ;
if ( V_63 ) {
if ( ! V_165 )
return V_63 ;
V_165 = 0 ;
V_63 = 0 ;
goto V_148;
}
F_1 () ;
V_63 = F_168 ( V_23 , V_40 , NULL ,
F_175 ) ;
if ( V_63 ) {
F_4 () ;
return V_63 ;
}
F_198 ( V_3 , V_3 + V_4 , L_1 ) ;
F_199 ( V_3 , V_4 ) ;
F_187 ( V_57 ) ;
F_4 () ;
return 0 ;
}
int F_167 ( unsigned long V_23 , unsigned long V_41 )
{
return - V_73 ;
}
int F_195 ( int V_57 , T_1 V_3 , T_1 V_4 )
{
return - V_73 ;
}
