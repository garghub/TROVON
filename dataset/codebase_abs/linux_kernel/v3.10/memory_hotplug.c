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
int T_2 F_61 ( int V_57 , struct V_44 * V_44 , unsigned long V_69 ,
unsigned long V_41 )
{
unsigned long V_27 ;
int V_71 = 0 ;
int V_72 , V_73 ;
V_72 = F_26 ( V_69 ) ;
V_73 = F_26 ( V_69 + V_41 - 1 ) ;
for ( V_27 = V_72 ; V_27 <= V_73 ; V_27 ++ ) {
V_71 = F_57 ( V_57 , V_44 , V_27 << V_74 ) ;
if ( V_71 && ( V_71 != - V_70 ) )
break;
V_71 = 0 ;
}
return V_71 ;
}
static int F_62 ( int V_57 , struct V_44 * V_44 ,
unsigned long V_23 ,
unsigned long V_40 )
{
struct V_28 * V_29 ;
for (; V_23 < V_40 ; V_23 += V_32 ) {
V_29 = F_60 ( V_23 ) ;
if ( F_63 ( ! F_64 ( V_29 ) ) )
continue;
if ( F_63 ( F_36 ( V_23 ) != V_57 ) )
continue;
if ( V_44 && V_44 != F_65 ( F_45 ( V_23 ) ) )
continue;
return V_23 ;
}
return 0 ;
}
static int F_66 ( int V_57 , struct V_44 * V_44 ,
unsigned long V_23 ,
unsigned long V_40 )
{
struct V_28 * V_29 ;
unsigned long V_39 ;
V_39 = V_40 - 1 ;
for (; V_39 >= V_23 ; V_39 -= V_32 ) {
V_29 = F_60 ( V_39 ) ;
if ( F_63 ( ! F_64 ( V_29 ) ) )
continue;
if ( F_63 ( F_36 ( V_39 ) != V_57 ) )
continue;
if ( V_44 && V_44 != F_65 ( F_45 ( V_39 ) ) )
continue;
return V_39 ;
}
return 0 ;
}
static void F_67 ( struct V_44 * V_44 , unsigned long V_23 ,
unsigned long V_40 )
{
unsigned long V_53 = V_44 -> V_53 ;
unsigned long F_51 = V_44 -> V_53 + V_44 -> V_54 ;
unsigned long V_39 ;
struct V_28 * V_29 ;
int V_57 = F_68 ( V_44 ) ;
F_38 ( V_44 ) ;
if ( V_53 == V_23 ) {
V_39 = F_62 ( V_57 , V_44 , V_40 ,
F_51 ) ;
if ( V_39 ) {
V_44 -> V_53 = V_39 ;
V_44 -> V_54 = F_51 - V_39 ;
}
} else if ( F_51 == V_40 ) {
V_39 = F_66 ( V_57 , V_44 , V_53 ,
V_23 ) ;
if ( V_39 )
V_44 -> V_54 = V_39 - V_53 + 1 ;
}
V_39 = V_53 ;
for (; V_39 < F_51 ; V_39 += V_32 ) {
V_29 = F_60 ( V_39 ) ;
if ( F_63 ( ! F_64 ( V_29 ) ) )
continue;
if ( F_65 ( F_45 ( V_39 ) ) != V_44 )
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
static void F_69 ( struct V_37 * V_38 ,
unsigned long V_23 , unsigned long V_40 )
{
unsigned long V_75 = V_38 -> V_51 ;
unsigned long F_35 =
V_38 -> V_51 + V_38 -> V_68 ;
unsigned long V_39 ;
struct V_28 * V_29 ;
int V_57 = V_38 -> V_43 ;
if ( V_75 == V_23 ) {
V_39 = F_62 ( V_57 , NULL , V_40 ,
F_35 ) ;
if ( V_39 ) {
V_38 -> V_51 = V_39 ;
V_38 -> V_68 = F_35 - V_39 ;
}
} else if ( F_35 == V_40 ) {
V_39 = F_66 ( V_57 , NULL , V_75 ,
V_23 ) ;
if ( V_39 )
V_38 -> V_68 = V_39 - V_75 + 1 ;
}
V_39 = V_75 ;
for (; V_39 < F_35 ; V_39 += V_32 ) {
V_29 = F_60 ( V_39 ) ;
if ( F_63 ( ! F_64 ( V_29 ) ) )
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
static void F_70 ( struct V_44 * V_44 , unsigned long V_23 )
{
struct V_37 * V_38 = V_44 -> V_58 ;
int V_41 = V_32 ;
int V_55 ;
unsigned long V_9 ;
V_55 = V_44 - V_38 -> V_46 ;
F_50 ( V_44 -> V_58 , & V_9 ) ;
F_67 ( V_44 , V_23 , V_23 + V_41 ) ;
F_69 ( V_38 , V_23 , V_23 + V_41 ) ;
F_52 ( V_44 -> V_58 , & V_9 ) ;
}
static int F_71 ( struct V_44 * V_44 , struct V_28 * V_29 )
{
unsigned long V_23 ;
int V_76 ;
int V_63 = - V_77 ;
if ( ! F_64 ( V_29 ) )
return V_63 ;
V_63 = F_72 ( V_29 ) ;
if ( V_63 )
return V_63 ;
V_76 = F_73 ( V_29 ) ;
V_23 = F_74 ( V_76 ) ;
F_70 ( V_44 , V_23 ) ;
F_75 ( V_44 , V_29 ) ;
return 0 ;
}
int F_76 ( struct V_44 * V_44 , unsigned long V_69 ,
unsigned long V_41 )
{
unsigned long V_27 ;
int V_78 ;
T_4 V_3 , V_4 ;
int V_63 = 0 ;
F_9 ( V_69 & ~ V_79 ) ;
F_9 ( V_41 % V_32 ) ;
V_3 = V_69 << V_33 ;
V_4 = V_41 * V_80 ;
V_63 = F_77 ( & V_12 , V_3 , V_4 ) ;
if ( V_63 ) {
T_4 V_81 = V_3 + V_4 - 1 ;
F_78 ( L_3 ,
& V_3 , & V_81 , V_63 ) ;
}
V_78 = V_41 / V_32 ;
for ( V_27 = 0 ; V_27 < V_78 ; V_27 ++ ) {
unsigned long V_39 = V_69 + V_27 * V_32 ;
V_63 = F_71 ( V_44 , F_60 ( V_39 ) ) ;
if ( V_63 )
break;
}
return V_63 ;
}
int F_79 ( T_5 V_82 )
{
int V_83 = - V_77 ;
F_1 () ;
if ( V_84 == V_85 ) {
V_84 = V_82 ;
V_83 = 0 ;
}
F_4 () ;
return V_83 ;
}
int F_80 ( T_5 V_82 )
{
int V_83 = - V_77 ;
F_1 () ;
if ( V_84 == V_82 ) {
V_84 = V_85 ;
V_83 = 0 ;
}
F_4 () ;
return V_83 ;
}
void F_81 ( struct V_14 * V_14 )
{
unsigned long V_39 = F_82 ( V_14 ) ;
if ( V_39 >= V_86 )
V_86 = V_39 + 1 ;
}
void F_83 ( struct V_14 * V_14 )
{
V_22 ++ ;
#ifdef F_84
if ( F_85 ( V_14 ) )
V_87 ++ ;
#endif
}
void F_86 ( struct V_14 * V_14 )
{
F_87 ( V_14 ) ;
F_88 ( V_14 ) ;
F_89 ( V_14 ) ;
}
static void V_85 ( struct V_14 * V_14 )
{
F_81 ( V_14 ) ;
F_83 ( V_14 ) ;
F_86 ( V_14 ) ;
}
static int F_90 ( unsigned long V_23 , unsigned long V_41 ,
void * V_88 )
{
unsigned long V_27 ;
unsigned long V_89 = * ( unsigned long * ) V_88 ;
struct V_14 * V_14 ;
if ( F_91 ( F_45 ( V_23 ) ) )
for ( V_27 = 0 ; V_27 < V_41 ; V_27 ++ ) {
V_14 = F_45 ( V_23 + V_27 ) ;
(* V_84)( V_14 ) ;
V_89 ++ ;
}
* ( unsigned long * ) V_88 = V_89 ;
return 0 ;
}
static bool F_92 ( struct V_44 * V_44 )
{
return true ;
}
static bool F_92 ( struct V_44 * V_44 )
{
return F_93 ( F_68 ( V_44 ) , V_90 ) ;
}
static void F_94 ( unsigned long V_41 ,
struct V_44 * V_44 , struct V_91 * V_88 )
{
int V_57 = F_68 ( V_44 ) ;
enum V_55 V_92 = V_93 ;
if ( V_94 == V_90 )
V_92 = V_95 ;
if ( F_43 ( V_44 ) <= V_92 && ! F_93 ( V_57 , V_90 ) )
V_88 -> V_96 = V_57 ;
else
V_88 -> V_96 = - 1 ;
#ifdef F_84
V_92 = V_97 ;
if ( V_94 == V_98 )
V_92 = V_95 ;
if ( F_43 ( V_44 ) <= V_92 && ! F_93 ( V_57 , V_98 ) )
V_88 -> V_99 = V_57 ;
else
V_88 -> V_99 = - 1 ;
#else
V_88 -> V_99 = V_88 -> V_96 ;
#endif
if ( ! F_93 ( V_57 , V_94 ) )
V_88 -> V_100 = V_57 ;
else
V_88 -> V_100 = - 1 ;
}
static void F_95 ( int V_42 , struct V_91 * V_88 )
{
if ( V_88 -> V_96 >= 0 )
F_96 ( V_42 , V_90 ) ;
if ( V_88 -> V_99 >= 0 )
F_96 ( V_42 , V_98 ) ;
F_96 ( V_42 , V_94 ) ;
}
int T_2 F_97 ( unsigned long V_39 , unsigned long V_41 , int V_101 )
{
unsigned long V_89 = 0 ;
struct V_44 * V_44 ;
int V_102 = 0 ;
int V_57 ;
int V_63 ;
struct V_91 V_88 ;
F_1 () ;
V_44 = F_65 ( F_45 ( V_39 ) ) ;
if ( ( F_43 ( V_44 ) > V_93 || V_101 == V_103 ) &&
! F_92 ( V_44 ) ) {
F_4 () ;
return - 1 ;
}
if ( V_101 == V_104 && F_43 ( V_44 ) == V_95 ) {
if ( F_49 ( V_44 - 1 , V_44 , V_39 , V_39 + V_41 ) ) {
F_4 () ;
return - 1 ;
}
}
if ( V_101 == V_103 && F_43 ( V_44 ) == V_95 - 1 ) {
if ( F_53 ( V_44 , V_44 + 1 , V_39 , V_39 + V_41 ) ) {
F_4 () ;
return - 1 ;
}
}
V_44 = F_65 ( F_45 ( V_39 ) ) ;
V_88 . V_23 = V_39 ;
V_88 . V_41 = V_41 ;
F_94 ( V_41 , V_44 , & V_88 ) ;
V_57 = F_98 ( F_45 ( V_39 ) ) ;
V_63 = V_91 ( V_105 , & V_88 ) ;
V_63 = F_99 ( V_63 ) ;
if ( V_63 ) {
V_91 ( V_106 , & V_88 ) ;
F_4 () ;
return V_63 ;
}
F_2 ( & V_107 ) ;
if ( ! F_100 ( V_44 ) ) {
V_102 = 1 ;
F_101 ( NULL , V_44 ) ;
}
V_63 = F_102 ( V_39 , V_41 , & V_89 ,
F_90 ) ;
if ( V_63 ) {
if ( V_102 )
F_103 ( V_44 ) ;
F_6 ( & V_107 ) ;
F_11 ( V_108 L_4 ,
( unsigned long long ) V_39 << V_33 ,
( ( ( unsigned long long ) V_39 + V_41 )
<< V_33 ) - 1 ) ;
V_91 ( V_106 , & V_88 ) ;
F_4 () ;
return V_63 ;
}
V_44 -> V_109 += V_89 ;
V_44 -> V_110 += V_89 ;
V_44 -> V_58 -> V_111 += V_89 ;
if ( V_89 ) {
F_95 ( F_68 ( V_44 ) , & V_88 ) ;
if ( V_102 )
F_101 ( NULL , NULL ) ;
else
F_104 ( V_44 ) ;
}
F_6 ( & V_107 ) ;
F_105 () ;
if ( V_89 )
F_106 ( F_68 ( V_44 ) ) ;
V_112 = F_107 () ;
F_108 () ;
if ( V_89 )
V_91 ( V_113 , & V_88 ) ;
F_4 () ;
return 0 ;
}
static T_6 T_2 * F_109 ( int V_57 , T_1 V_3 )
{
struct V_37 * V_38 ;
unsigned long V_114 [ V_47 ] = { 0 } ;
unsigned long V_115 [ V_47 ] = { 0 } ;
unsigned long V_23 = V_3 >> V_33 ;
V_38 = F_110 ( V_57 ) ;
if ( ! V_38 ) {
V_38 = F_111 ( V_57 ) ;
if ( ! V_38 )
return NULL ;
F_112 ( V_57 , V_38 ) ;
}
F_113 ( V_57 , V_114 , V_23 , V_115 ) ;
F_2 ( & V_107 ) ;
F_101 ( V_38 , NULL ) ;
F_6 ( & V_107 ) ;
return V_38 ;
}
static void F_114 ( int V_57 , T_6 * V_38 )
{
F_112 ( V_57 , NULL ) ;
F_115 ( V_38 ) ;
return;
}
int F_116 ( int V_57 )
{
T_6 * V_38 ;
int V_63 ;
F_1 () ;
V_38 = F_109 ( V_57 , 0 ) ;
if ( ! V_38 ) {
V_63 = - V_116 ;
goto V_117;
}
F_117 ( V_57 ) ;
V_63 = F_118 ( V_57 ) ;
F_9 ( V_63 ) ;
V_117:
F_4 () ;
return V_63 ;
}
int T_2 F_119 ( int V_57 , T_1 V_3 , T_1 V_4 )
{
T_6 * V_38 = NULL ;
bool V_118 ;
bool V_119 ;
struct V_2 * V_5 ;
int V_63 ;
F_1 () ;
V_5 = F_7 ( V_3 , V_4 ) ;
V_63 = - V_70 ;
if ( ! V_5 )
goto V_117;
{
void * V_120 = F_110 ( V_57 ) ;
V_118 = ! V_120 ;
}
V_119 = ! F_120 ( V_57 ) ;
if ( V_119 ) {
V_38 = F_109 ( V_57 , V_3 ) ;
V_63 = - V_116 ;
if ( ! V_38 )
goto error;
}
V_63 = F_121 ( V_57 , V_3 , V_4 ) ;
if ( V_63 < 0 )
goto error;
F_117 ( V_57 ) ;
if ( V_119 ) {
V_63 = F_118 ( V_57 ) ;
F_9 ( V_63 ) ;
}
F_122 ( V_3 , V_3 + V_4 , L_1 ) ;
goto V_117;
error:
if ( V_118 )
F_114 ( V_57 , V_38 ) ;
F_13 ( V_5 ) ;
V_117:
F_4 () ;
return V_63 ;
}
static inline int F_123 ( struct V_14 * V_14 )
{
return F_124 ( V_14 ) && F_125 ( V_14 ) >= V_121 ;
}
static struct V_14 * F_126 ( struct V_14 * V_14 )
{
F_9 ( F_82 ( V_14 ) & ( V_122 - 1 ) ) ;
if ( F_123 ( V_14 ) ) {
int V_123 ;
V_123 = F_125 ( V_14 ) ;
if ( ( V_123 < V_124 ) && ( V_123 >= V_121 ) )
return V_14 + ( 1 << V_123 ) ;
}
return V_14 + V_122 ;
}
int F_127 ( unsigned long V_23 , unsigned long V_41 )
{
struct V_14 * V_14 = F_45 ( V_23 ) ;
struct V_14 * V_125 = V_14 + V_41 ;
for (; V_14 < V_125 ; V_14 = F_126 ( V_14 ) ) {
if ( ! F_128 ( V_14 ) )
return 0 ;
F_129 () ;
}
return 1 ;
}
static int F_130 ( unsigned long V_23 , unsigned long V_40 )
{
unsigned long V_39 ;
struct V_44 * V_44 = NULL ;
struct V_14 * V_14 ;
int V_27 ;
for ( V_39 = V_23 ;
V_39 < V_40 ;
V_39 += V_126 ) {
V_27 = 0 ;
while ( ( V_27 < V_126 ) && ! F_131 ( V_39 + V_27 ) )
V_27 ++ ;
if ( V_27 == V_126 )
continue;
V_14 = F_45 ( V_39 + V_27 ) ;
if ( V_44 && F_65 ( V_14 ) != V_44 )
return 0 ;
V_44 = F_65 ( V_14 ) ;
}
return 1 ;
}
static unsigned long F_132 ( unsigned long V_3 , unsigned long V_8 )
{
unsigned long V_39 ;
struct V_14 * V_14 ;
for ( V_39 = V_3 ; V_39 < V_8 ; V_39 ++ ) {
if ( F_32 ( V_39 ) ) {
V_14 = F_45 ( V_39 ) ;
if ( F_133 ( V_14 ) )
return V_39 ;
}
}
return 0 ;
}
static int
F_134 ( unsigned long V_23 , unsigned long V_40 )
{
unsigned long V_39 ;
struct V_14 * V_14 ;
int V_127 = V_128 ;
int V_129 = 0 ;
int V_63 = 0 ;
F_135 ( V_130 ) ;
for ( V_39 = V_23 ; V_39 < V_40 && V_127 > 0 ; V_39 ++ ) {
if ( ! F_32 ( V_39 ) )
continue;
V_14 = F_45 ( V_39 ) ;
if ( ! F_136 ( V_14 ) )
continue;
V_63 = F_137 ( V_14 ) ;
if ( ! V_63 ) {
F_138 ( V_14 ) ;
F_139 ( & V_14 -> V_15 , & V_130 ) ;
V_127 -- ;
F_140 ( V_14 , V_131 +
F_141 ( V_14 ) ) ;
} else {
#ifdef F_142
F_11 ( V_132 L_5 ,
V_39 ) ;
F_143 ( V_14 ) ;
#endif
F_138 ( V_14 ) ;
if ( F_144 ( V_14 ) ) {
V_129 ++ ;
V_63 = - V_133 ;
break;
}
}
}
if ( ! F_145 ( & V_130 ) ) {
if ( V_129 ) {
F_146 ( & V_130 ) ;
goto V_117;
}
V_63 = F_147 ( & V_130 , V_134 , 0 ,
V_135 , V_136 ) ;
if ( V_63 )
F_146 ( & V_130 ) ;
}
V_117:
return V_63 ;
}
static int
F_148 ( unsigned long V_3 , unsigned long V_41 ,
void * V_137 )
{
F_149 ( V_3 , V_3 + V_41 ) ;
return 0 ;
}
static void
F_150 ( unsigned long V_23 , unsigned long V_40 )
{
F_102 ( V_23 , V_40 - V_23 , NULL ,
F_148 ) ;
}
static int
F_151 ( unsigned long V_23 , unsigned long V_41 ,
void * V_137 )
{
int V_63 ;
long V_138 = * ( long * ) V_137 ;
V_63 = F_152 ( V_23 , V_23 + V_41 , true ) ;
V_138 = V_41 ;
if ( ! V_63 )
* ( long * ) V_137 += V_138 ;
return V_63 ;
}
static long
F_153 ( unsigned long V_23 , unsigned long V_40 )
{
long V_138 = 0 ;
int V_63 ;
V_63 = F_102 ( V_23 , V_40 - V_23 , & V_138 ,
F_151 ) ;
if ( V_63 < 0 )
V_138 = ( long ) V_63 ;
return V_138 ;
}
static bool F_154 ( struct V_44 * V_44 , unsigned long V_41 )
{
return true ;
}
static bool F_154 ( struct V_44 * V_44 , unsigned long V_41 )
{
struct V_37 * V_38 = V_44 -> V_58 ;
unsigned long V_110 = 0 ;
enum V_55 V_139 ;
for ( V_139 = 0 ; V_139 <= V_93 ; V_139 ++ )
V_110 += V_38 -> V_46 [ V_139 ] . V_110 ;
if ( V_110 > V_41 )
return true ;
V_110 = 0 ;
for (; V_139 <= V_95 ; V_139 ++ )
V_110 += V_38 -> V_46 [ V_139 ] . V_110 ;
return V_110 == 0 ;
}
static void F_155 ( unsigned long V_41 ,
struct V_44 * V_44 , struct V_91 * V_88 )
{
struct V_37 * V_38 = V_44 -> V_58 ;
unsigned long V_110 = 0 ;
enum V_55 V_139 , V_92 = V_93 ;
if ( V_94 == V_90 )
V_92 = V_95 ;
for ( V_139 = 0 ; V_139 <= V_92 ; V_139 ++ )
V_110 += V_38 -> V_46 [ V_139 ] . V_110 ;
if ( F_43 ( V_44 ) <= V_92 && V_41 >= V_110 )
V_88 -> V_96 = F_68 ( V_44 ) ;
else
V_88 -> V_96 = - 1 ;
#ifdef F_84
V_92 = V_97 ;
if ( V_94 == V_98 )
V_92 = V_95 ;
for (; V_139 <= V_92 ; V_139 ++ )
V_110 += V_38 -> V_46 [ V_139 ] . V_110 ;
if ( F_43 ( V_44 ) <= V_92 && V_41 >= V_110 )
V_88 -> V_99 = F_68 ( V_44 ) ;
else
V_88 -> V_99 = - 1 ;
#else
V_88 -> V_99 = V_88 -> V_96 ;
#endif
V_92 = V_95 ;
for (; V_139 <= V_92 ; V_139 ++ )
V_110 += V_38 -> V_46 [ V_139 ] . V_110 ;
if ( V_41 >= V_110 )
V_88 -> V_100 = F_68 ( V_44 ) ;
else
V_88 -> V_100 = - 1 ;
}
static void F_156 ( int V_42 , struct V_91 * V_88 )
{
if ( V_88 -> V_96 >= 0 )
F_157 ( V_42 , V_90 ) ;
if ( ( V_94 != V_90 ) &&
( V_88 -> V_99 >= 0 ) )
F_157 ( V_42 , V_98 ) ;
if ( ( V_94 != V_98 ) &&
( V_88 -> V_100 >= 0 ) )
F_157 ( V_42 , V_94 ) ;
}
static int T_2 F_158 ( unsigned long V_23 ,
unsigned long V_40 , unsigned long V_140 )
{
unsigned long V_39 , V_41 , V_141 ;
long V_142 ;
int V_63 , V_143 , V_144 , V_42 ;
struct V_44 * V_44 ;
struct V_91 V_88 ;
F_9 ( V_23 >= V_40 ) ;
if ( ! F_159 ( V_23 , V_122 ) )
return - V_77 ;
if ( ! F_159 ( V_40 , V_122 ) )
return - V_77 ;
if ( ! F_130 ( V_23 , V_40 ) )
return - V_77 ;
F_1 () ;
V_44 = F_65 ( F_45 ( V_23 ) ) ;
V_42 = F_68 ( V_44 ) ;
V_41 = V_40 - V_23 ;
V_63 = - V_77 ;
if ( F_43 ( V_44 ) <= V_93 && ! F_154 ( V_44 , V_41 ) )
goto V_117;
V_63 = F_160 ( V_23 , V_40 ,
V_145 , true ) ;
if ( V_63 )
goto V_117;
V_88 . V_23 = V_23 ;
V_88 . V_41 = V_41 ;
F_155 ( V_41 , V_44 , & V_88 ) ;
V_63 = V_91 ( V_146 , & V_88 ) ;
V_63 = F_99 ( V_63 ) ;
if ( V_63 )
goto V_147;
V_39 = V_23 ;
V_141 = V_148 + V_140 ;
V_143 = 0 ;
V_144 = 5 ;
V_149:
V_63 = - V_150 ;
if ( F_161 ( V_148 , V_141 ) )
goto V_147;
V_63 = - V_151 ;
if ( F_162 ( V_152 ) )
goto V_147;
V_63 = 0 ;
if ( V_143 ) {
F_163 () ;
F_129 () ;
F_164 () ;
}
V_39 = F_132 ( V_23 , V_40 ) ;
if ( V_39 ) {
V_63 = F_134 ( V_39 , V_40 ) ;
if ( ! V_63 ) {
V_143 = 1 ;
goto V_149;
} else {
if ( V_63 < 0 )
if ( -- V_144 == 0 )
goto V_147;
F_165 () ;
V_143 = 1 ;
goto V_149;
}
}
F_163 () ;
F_165 () ;
F_164 () ;
V_142 = F_153 ( V_23 , V_40 ) ;
if ( V_142 < 0 ) {
V_63 = - V_133 ;
goto V_147;
}
F_11 ( V_153 L_6 , V_142 ) ;
F_150 ( V_23 , V_40 ) ;
F_166 ( V_23 , V_40 , V_145 ) ;
V_44 -> V_109 -= V_142 ;
V_44 -> V_110 -= V_142 ;
V_44 -> V_58 -> V_111 -= V_142 ;
V_22 -= V_142 ;
F_105 () ;
if ( ! F_100 ( V_44 ) ) {
F_103 ( V_44 ) ;
F_2 ( & V_107 ) ;
F_101 ( NULL , NULL ) ;
F_6 ( & V_107 ) ;
} else
F_104 ( V_44 ) ;
F_156 ( V_42 , & V_88 ) ;
if ( V_88 . V_100 >= 0 )
F_167 ( V_42 ) ;
V_112 = F_107 () ;
F_108 () ;
V_91 ( V_154 , & V_88 ) ;
F_4 () ;
return 0 ;
V_147:
F_11 ( V_153 L_7 ,
( unsigned long long ) V_23 << V_33 ,
( ( unsigned long long ) V_40 << V_33 ) - 1 ) ;
V_91 ( V_155 , & V_88 ) ;
F_166 ( V_23 , V_40 , V_145 ) ;
V_117:
F_4 () ;
return V_63 ;
}
int F_168 ( unsigned long V_23 , unsigned long V_41 )
{
return F_158 ( V_23 , V_23 + V_41 , 120 * V_156 ) ;
}
static int F_169 ( unsigned long V_23 , unsigned long V_40 ,
void * V_88 , int (* F_170)( struct V_157 * , void * ) )
{
struct V_157 * V_158 = NULL ;
struct V_28 * V_159 ;
unsigned long V_39 , V_26 ;
int V_63 ;
for ( V_39 = V_23 ; V_39 < V_40 ; V_39 += V_32 ) {
V_26 = F_26 ( V_39 ) ;
if ( ! F_171 ( V_26 ) )
continue;
V_159 = F_27 ( V_26 ) ;
if ( V_158 )
if ( ( V_26 >= V_158 -> V_160 ) &&
( V_26 <= V_158 -> V_161 ) )
continue;
V_158 = F_172 ( V_159 , V_158 ) ;
if ( ! V_158 )
continue;
V_63 = F_170 ( V_158 , V_88 ) ;
if ( V_63 ) {
F_173 ( & V_158 -> V_162 . V_163 ) ;
return V_63 ;
}
}
if ( V_158 )
F_173 ( & V_158 -> V_162 . V_163 ) ;
return 0 ;
}
static int F_174 ( struct V_157 * V_158 , void * V_88 )
{
int * V_63 = V_88 ;
int error = F_175 ( V_158 ) ;
if ( error != 0 && * V_63 == 0 )
* V_63 = error ;
return 0 ;
}
static int F_176 ( struct V_157 * V_158 , void * V_88 )
{
int V_63 = ! F_177 ( V_158 ) ;
if ( F_63 ( V_63 ) ) {
T_7 V_164 , V_165 ;
V_164 = F_178 ( F_74 ( V_158 -> V_160 ) ) ;
V_165 = F_178 ( F_74 ( V_158 -> V_161 + 1 ) ) - 1 ;
F_78 ( L_8
L_9 ,
& V_164 , & V_165 ) ;
}
return V_63 ;
}
static int F_179 ( void * V_137 )
{
struct V_37 * V_38 = V_137 ;
int V_166 ;
F_180 (cpu) {
if ( F_181 ( V_166 ) == V_38 -> V_43 )
return - V_133 ;
}
return 0 ;
}
static void F_182 ( void * V_137 )
{
#ifdef F_183
struct V_37 * V_38 = V_137 ;
int V_166 ;
F_184 (cpu)
if ( F_181 ( V_166 ) == V_38 -> V_43 )
F_185 ( V_166 ) ;
#endif
}
static int F_186 ( void * V_137 )
{
int V_63 = F_179 ( V_137 ) ;
if ( V_63 )
return V_63 ;
F_182 ( V_137 ) ;
return 0 ;
}
void F_187 ( int V_57 )
{
T_6 * V_38 = F_110 ( V_57 ) ;
unsigned long V_23 = V_38 -> V_51 ;
unsigned long V_40 = V_23 + V_38 -> V_68 ;
unsigned long V_39 ;
struct V_14 * V_167 = F_29 ( V_38 ) ;
int V_27 ;
for ( V_39 = V_23 ; V_39 < V_40 ; V_39 += V_32 ) {
unsigned long V_26 = F_26 ( V_39 ) ;
if ( ! F_171 ( V_26 ) )
continue;
if ( F_36 ( V_39 ) != V_57 )
continue;
return;
}
if ( F_188 ( F_186 , V_38 , NULL ) )
return;
F_189 ( V_57 ) ;
F_190 ( V_57 ) ;
if ( ! F_191 ( V_167 ) && ! F_192 ( V_167 ) )
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
int V_168 = 1 ;
V_23 = F_196 ( V_3 ) ;
V_40 = F_197 ( V_3 + V_4 - 1 ) ;
V_149:
F_169 ( V_23 , V_40 , & V_63 ,
F_174 ) ;
if ( V_63 ) {
if ( ! V_168 )
return V_63 ;
V_168 = 0 ;
V_63 = 0 ;
goto V_149;
}
F_1 () ;
V_63 = F_169 ( V_23 , V_40 , NULL ,
F_176 ) ;
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
int F_168 ( unsigned long V_23 , unsigned long V_41 )
{
return - V_77 ;
}
int F_195 ( int V_57 , T_1 V_3 , T_1 V_4 )
{
return - V_77 ;
}
