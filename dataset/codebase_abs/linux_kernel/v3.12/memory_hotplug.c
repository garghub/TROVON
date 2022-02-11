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
unsigned long V_65 =
V_36 -> V_49 + V_36 -> V_66 ;
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
int V_39 = V_30 ;
int V_61 ;
if ( F_29 ( V_67 ) )
return - V_68 ;
V_61 = F_56 ( V_42 , V_67 , V_39 ) ;
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
unsigned long F_33 =
V_36 -> V_49 + V_36 -> V_66 ;
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
int V_75 ;
int V_61 = - V_76 ;
if ( ! F_62 ( V_27 ) )
return V_61 ;
V_61 = F_70 ( V_27 ) ;
if ( V_61 )
return V_61 ;
V_75 = F_71 ( V_27 ) ;
V_21 = F_72 ( V_75 ) ;
F_68 ( V_42 , V_21 ) ;
F_73 ( V_42 , V_27 ) ;
return 0 ;
}
int F_74 ( struct V_42 * V_42 , unsigned long V_67 ,
unsigned long V_39 )
{
unsigned long V_25 ;
int V_77 ;
T_4 V_3 , V_4 ;
int V_61 = 0 ;
F_7 ( V_67 & ~ V_78 ) ;
F_7 ( V_39 % V_30 ) ;
V_3 = V_67 << V_31 ;
V_4 = V_39 * V_79 ;
V_61 = F_75 ( & V_12 , V_3 , V_4 ) ;
if ( V_61 ) {
T_4 V_80 = V_3 + V_4 - 1 ;
F_76 ( L_3 ,
& V_3 , & V_80 , V_61 ) ;
}
V_77 = V_39 / V_30 ;
for ( V_25 = 0 ; V_25 < V_77 ; V_25 ++ ) {
unsigned long V_37 = V_67 + V_25 * V_30 ;
V_61 = F_69 ( V_42 , F_58 ( V_37 ) ) ;
if ( V_61 )
break;
}
return V_61 ;
}
int F_77 ( T_5 V_81 )
{
int V_82 = - V_76 ;
F_1 () ;
if ( V_83 == V_84 ) {
V_83 = V_81 ;
V_82 = 0 ;
}
F_3 () ;
return V_82 ;
}
int F_78 ( T_5 V_81 )
{
int V_82 = - V_76 ;
F_1 () ;
if ( V_83 == V_81 ) {
V_83 = V_84 ;
V_82 = 0 ;
}
F_3 () ;
return V_82 ;
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
static void V_84 ( struct V_14 * V_14 )
{
F_79 ( V_14 ) ;
F_80 ( V_14 ) ;
F_82 ( V_14 ) ;
}
static int F_84 ( unsigned long V_21 , unsigned long V_39 ,
void * V_85 )
{
unsigned long V_25 ;
unsigned long V_86 = * ( unsigned long * ) V_85 ;
struct V_14 * V_14 ;
if ( F_85 ( F_45 ( V_21 ) ) )
for ( V_25 = 0 ; V_25 < V_39 ; V_25 ++ ) {
V_14 = F_45 ( V_21 + V_25 ) ;
(* V_83)( V_14 ) ;
V_86 ++ ;
}
* ( unsigned long * ) V_85 = V_86 ;
return 0 ;
}
static bool F_86 ( struct V_42 * V_42 )
{
return true ;
}
static bool F_86 ( struct V_42 * V_42 )
{
return F_87 ( F_66 ( V_42 ) , V_87 ) ;
}
static void F_88 ( unsigned long V_39 ,
struct V_42 * V_42 , struct V_88 * V_85 )
{
int V_55 = F_66 ( V_42 ) ;
enum V_53 V_89 = V_90 ;
if ( V_91 == V_87 )
V_89 = V_92 ;
if ( F_43 ( V_42 ) <= V_89 && ! F_87 ( V_55 , V_87 ) )
V_85 -> V_93 = V_55 ;
else
V_85 -> V_93 = - 1 ;
#ifdef F_89
V_89 = V_94 ;
if ( V_91 == V_95 )
V_89 = V_92 ;
if ( F_43 ( V_42 ) <= V_89 && ! F_87 ( V_55 , V_95 ) )
V_85 -> V_96 = V_55 ;
else
V_85 -> V_96 = - 1 ;
#else
V_85 -> V_96 = V_85 -> V_93 ;
#endif
if ( ! F_87 ( V_55 , V_91 ) )
V_85 -> V_97 = V_55 ;
else
V_85 -> V_97 = - 1 ;
}
static void F_90 ( int V_40 , struct V_88 * V_85 )
{
if ( V_85 -> V_93 >= 0 )
F_91 ( V_40 , V_87 ) ;
if ( V_85 -> V_96 >= 0 )
F_91 ( V_40 , V_95 ) ;
F_91 ( V_40 , V_91 ) ;
}
int T_2 F_92 ( unsigned long V_37 , unsigned long V_39 , int V_98 )
{
unsigned long V_9 ;
unsigned long V_86 = 0 ;
struct V_42 * V_42 ;
int V_99 = 0 ;
int V_55 ;
int V_61 ;
struct V_88 V_85 ;
F_1 () ;
V_42 = F_63 ( F_45 ( V_37 ) ) ;
if ( ( F_43 ( V_42 ) > V_90 || V_98 == V_100 ) &&
! F_86 ( V_42 ) ) {
F_3 () ;
return - V_76 ;
}
if ( V_98 == V_101 && F_43 ( V_42 ) == V_92 ) {
if ( F_48 ( V_42 - 1 , V_42 , V_37 , V_37 + V_39 ) ) {
F_3 () ;
return - V_76 ;
}
}
if ( V_98 == V_100 && F_43 ( V_42 ) == V_92 - 1 ) {
if ( F_51 ( V_42 , V_42 + 1 , V_37 , V_37 + V_39 ) ) {
F_3 () ;
return - V_76 ;
}
}
V_42 = F_63 ( F_45 ( V_37 ) ) ;
V_85 . V_21 = V_37 ;
V_85 . V_39 = V_39 ;
F_88 ( V_39 , V_42 , & V_85 ) ;
V_55 = F_93 ( F_45 ( V_37 ) ) ;
V_61 = V_88 ( V_102 , & V_85 ) ;
V_61 = F_94 ( V_61 ) ;
if ( V_61 ) {
V_88 ( V_103 , & V_85 ) ;
F_3 () ;
return V_61 ;
}
F_2 ( & V_104 ) ;
if ( ! F_95 ( V_42 ) ) {
V_99 = 1 ;
F_96 ( NULL , V_42 ) ;
}
V_61 = F_97 ( V_37 , V_39 , & V_86 ,
F_84 ) ;
if ( V_61 ) {
if ( V_99 )
F_98 ( V_42 ) ;
F_4 ( & V_104 ) ;
F_99 ( V_105 L_4 ,
( unsigned long long ) V_37 << V_31 ,
( ( ( unsigned long long ) V_37 + V_39 )
<< V_31 ) - 1 ) ;
V_88 ( V_103 , & V_85 ) ;
F_3 () ;
return V_61 ;
}
V_42 -> V_106 += V_86 ;
F_49 ( V_42 -> V_56 , & V_9 ) ;
V_42 -> V_56 -> V_107 += V_86 ;
F_50 ( V_42 -> V_56 , & V_9 ) ;
if ( V_86 ) {
F_90 ( F_66 ( V_42 ) , & V_85 ) ;
if ( V_99 )
F_96 ( NULL , NULL ) ;
else
F_100 ( V_42 ) ;
}
F_4 ( & V_104 ) ;
F_101 () ;
if ( V_86 )
F_102 ( F_66 ( V_42 ) ) ;
V_108 = F_103 () ;
F_104 () ;
if ( V_86 )
V_88 ( V_109 , & V_85 ) ;
F_3 () ;
return 0 ;
}
static T_6 T_2 * F_105 ( int V_55 , T_1 V_3 )
{
struct V_35 * V_36 ;
unsigned long V_110 [ V_45 ] = { 0 } ;
unsigned long V_111 [ V_45 ] = { 0 } ;
unsigned long V_21 = V_3 >> V_31 ;
V_36 = F_106 ( V_55 ) ;
if ( ! V_36 ) {
V_36 = F_107 ( V_55 ) ;
if ( ! V_36 )
return NULL ;
F_108 ( V_55 , V_36 ) ;
}
F_109 ( V_55 , V_110 , V_21 , V_111 ) ;
F_2 ( & V_104 ) ;
F_96 ( V_36 , NULL ) ;
F_4 ( & V_104 ) ;
return V_36 ;
}
static void F_110 ( int V_55 , T_6 * V_36 )
{
F_108 ( V_55 , NULL ) ;
F_111 ( V_36 ) ;
return;
}
int F_112 ( int V_55 )
{
T_6 * V_36 ;
int V_61 ;
F_1 () ;
V_36 = F_105 ( V_55 , 0 ) ;
if ( ! V_36 ) {
V_61 = - V_112 ;
goto V_113;
}
F_113 ( V_55 ) ;
V_61 = F_114 ( V_55 ) ;
F_7 ( V_61 ) ;
V_113:
F_3 () ;
return V_61 ;
}
static int F_115 ( T_1 V_3 , T_1 V_4 )
{
T_1 V_21 = V_3 >> V_31 ;
T_1 V_39 = V_4 >> V_31 ;
if ( ( V_21 & ~ V_78 ) ||
( V_39 % V_30 ) || ( ! V_39 ) ) {
F_116 ( L_5 ,
( unsigned long long ) V_3 ,
( unsigned long long ) V_4 ) ;
return - V_76 ;
}
return 0 ;
}
int T_2 F_117 ( int V_55 , T_1 V_3 , T_1 V_4 )
{
T_6 * V_36 = NULL ;
bool V_114 ;
bool V_115 ;
struct V_2 * V_5 ;
int V_61 ;
V_61 = F_115 ( V_3 , V_4 ) ;
if ( V_61 )
return V_61 ;
F_1 () ;
V_5 = F_5 ( V_3 , V_4 ) ;
V_61 = - V_68 ;
if ( ! V_5 )
goto V_113;
{
void * V_116 = F_106 ( V_55 ) ;
V_114 = ! V_116 ;
}
V_115 = ! F_118 ( V_55 ) ;
if ( V_115 ) {
V_36 = F_105 ( V_55 , V_3 ) ;
V_61 = - V_112 ;
if ( ! V_36 )
goto error;
}
V_61 = F_119 ( V_55 , V_3 , V_4 ) ;
if ( V_61 < 0 )
goto error;
F_113 ( V_55 ) ;
if ( V_115 ) {
V_61 = F_114 ( V_55 ) ;
F_7 ( V_61 ) ;
}
F_120 ( V_3 , V_3 + V_4 , L_1 ) ;
goto V_113;
error:
if ( V_114 )
F_110 ( V_55 , V_36 ) ;
F_11 ( V_5 ) ;
V_113:
F_3 () ;
return V_61 ;
}
static inline int F_121 ( struct V_14 * V_14 )
{
return F_122 ( V_14 ) && F_123 ( V_14 ) >= V_117 ;
}
static struct V_14 * F_124 ( struct V_14 * V_14 )
{
F_7 ( F_125 ( V_14 ) & ( V_118 - 1 ) ) ;
if ( F_121 ( V_14 ) ) {
int V_119 ;
V_119 = F_123 ( V_14 ) ;
if ( ( V_119 < V_120 ) && ( V_119 >= V_117 ) )
return V_14 + ( 1 << V_119 ) ;
}
return V_14 + V_118 ;
}
int F_126 ( unsigned long V_21 , unsigned long V_39 )
{
struct V_14 * V_14 = F_45 ( V_21 ) ;
struct V_14 * V_121 = V_14 + V_39 ;
for (; V_14 < V_121 ; V_14 = F_124 ( V_14 ) ) {
if ( ! F_127 ( V_14 ) )
return 0 ;
F_128 () ;
}
return 1 ;
}
static int F_129 ( unsigned long V_21 , unsigned long V_38 )
{
unsigned long V_37 ;
struct V_42 * V_42 = NULL ;
struct V_14 * V_14 ;
int V_25 ;
for ( V_37 = V_21 ;
V_37 < V_38 ;
V_37 += V_122 ) {
V_25 = 0 ;
while ( ( V_25 < V_122 ) && ! F_130 ( V_37 + V_25 ) )
V_25 ++ ;
if ( V_25 == V_122 )
continue;
V_14 = F_45 ( V_37 + V_25 ) ;
if ( V_42 && F_63 ( V_14 ) != V_42 )
return 0 ;
V_42 = F_63 ( V_14 ) ;
}
return 1 ;
}
static unsigned long F_131 ( unsigned long V_3 , unsigned long V_8 )
{
unsigned long V_37 ;
struct V_14 * V_14 ;
for ( V_37 = V_3 ; V_37 < V_8 ; V_37 ++ ) {
if ( F_29 ( V_37 ) ) {
V_14 = F_45 ( V_37 ) ;
if ( F_132 ( V_14 ) )
return V_37 ;
if ( F_133 ( V_14 ) ) {
if ( F_134 ( V_14 ) )
return V_37 ;
else
V_37 = F_135 ( V_37 + 1 ,
1 << F_136 ( V_14 ) ) - 1 ;
}
}
}
return 0 ;
}
static int
F_137 ( unsigned long V_21 , unsigned long V_38 )
{
unsigned long V_37 ;
struct V_14 * V_14 ;
int V_123 = V_124 ;
int V_125 = 0 ;
int V_61 = 0 ;
F_138 ( V_126 ) ;
for ( V_37 = V_21 ; V_37 < V_38 && V_123 > 0 ; V_37 ++ ) {
if ( ! F_29 ( V_37 ) )
continue;
V_14 = F_45 ( V_37 ) ;
if ( F_133 ( V_14 ) ) {
struct V_14 * V_127 = F_139 ( V_14 ) ;
V_37 = F_125 ( V_127 ) + ( 1 << F_136 ( V_127 ) ) - 1 ;
if ( F_136 ( V_127 ) > V_72 ) {
V_61 = - V_128 ;
break;
}
if ( F_140 ( V_14 , & V_126 ) )
V_123 -= 1 << F_136 ( V_127 ) ;
continue;
}
if ( ! F_141 ( V_14 ) )
continue;
V_61 = F_142 ( V_14 ) ;
if ( ! V_61 ) {
F_143 ( V_14 ) ;
F_144 ( & V_14 -> V_15 , & V_126 ) ;
V_123 -- ;
F_145 ( V_14 , V_129 +
F_146 ( V_14 ) ) ;
} else {
#ifdef F_147
F_99 ( V_130 L_6 ,
V_37 ) ;
F_148 ( V_14 ) ;
#endif
F_143 ( V_14 ) ;
if ( F_149 ( V_14 ) ) {
V_125 ++ ;
V_61 = - V_128 ;
break;
}
}
}
if ( ! F_150 ( & V_126 ) ) {
if ( V_125 ) {
F_151 ( & V_126 ) ;
goto V_113;
}
V_61 = F_152 ( & V_126 , V_131 , 0 ,
V_132 , V_133 ) ;
if ( V_61 )
F_151 ( & V_126 ) ;
}
V_113:
return V_61 ;
}
static int
F_153 ( unsigned long V_3 , unsigned long V_39 ,
void * V_134 )
{
F_154 ( V_3 , V_3 + V_39 ) ;
return 0 ;
}
static void
F_155 ( unsigned long V_21 , unsigned long V_38 )
{
F_97 ( V_21 , V_38 - V_21 , NULL ,
F_153 ) ;
}
static int
F_156 ( unsigned long V_21 , unsigned long V_39 ,
void * V_134 )
{
int V_61 ;
long V_135 = * ( long * ) V_134 ;
V_61 = F_157 ( V_21 , V_21 + V_39 , true ) ;
V_135 = V_39 ;
if ( ! V_61 )
* ( long * ) V_134 += V_135 ;
return V_61 ;
}
static long
F_158 ( unsigned long V_21 , unsigned long V_38 )
{
long V_135 = 0 ;
int V_61 ;
V_61 = F_97 ( V_21 , V_38 - V_21 , & V_135 ,
F_156 ) ;
if ( V_61 < 0 )
V_135 = ( long ) V_61 ;
return V_135 ;
}
static bool F_159 ( struct V_42 * V_42 , unsigned long V_39 )
{
return true ;
}
static bool F_159 ( struct V_42 * V_42 , unsigned long V_39 )
{
struct V_35 * V_36 = V_42 -> V_56 ;
unsigned long V_106 = 0 ;
enum V_53 V_136 ;
for ( V_136 = 0 ; V_136 <= V_90 ; V_136 ++ )
V_106 += V_36 -> V_44 [ V_136 ] . V_106 ;
if ( V_106 > V_39 )
return true ;
V_106 = 0 ;
for (; V_136 <= V_92 ; V_136 ++ )
V_106 += V_36 -> V_44 [ V_136 ] . V_106 ;
return V_106 == 0 ;
}
static void F_160 ( unsigned long V_39 ,
struct V_42 * V_42 , struct V_88 * V_85 )
{
struct V_35 * V_36 = V_42 -> V_56 ;
unsigned long V_106 = 0 ;
enum V_53 V_136 , V_89 = V_90 ;
if ( V_91 == V_87 )
V_89 = V_92 ;
for ( V_136 = 0 ; V_136 <= V_89 ; V_136 ++ )
V_106 += V_36 -> V_44 [ V_136 ] . V_106 ;
if ( F_43 ( V_42 ) <= V_89 && V_39 >= V_106 )
V_85 -> V_93 = F_66 ( V_42 ) ;
else
V_85 -> V_93 = - 1 ;
#ifdef F_89
V_89 = V_94 ;
if ( V_91 == V_95 )
V_89 = V_92 ;
for (; V_136 <= V_89 ; V_136 ++ )
V_106 += V_36 -> V_44 [ V_136 ] . V_106 ;
if ( F_43 ( V_42 ) <= V_89 && V_39 >= V_106 )
V_85 -> V_96 = F_66 ( V_42 ) ;
else
V_85 -> V_96 = - 1 ;
#else
V_85 -> V_96 = V_85 -> V_93 ;
#endif
V_89 = V_92 ;
for (; V_136 <= V_89 ; V_136 ++ )
V_106 += V_36 -> V_44 [ V_136 ] . V_106 ;
if ( V_39 >= V_106 )
V_85 -> V_97 = F_66 ( V_42 ) ;
else
V_85 -> V_97 = - 1 ;
}
static void F_161 ( int V_40 , struct V_88 * V_85 )
{
if ( V_85 -> V_93 >= 0 )
F_162 ( V_40 , V_87 ) ;
if ( ( V_91 != V_87 ) &&
( V_85 -> V_96 >= 0 ) )
F_162 ( V_40 , V_95 ) ;
if ( ( V_91 != V_95 ) &&
( V_85 -> V_97 >= 0 ) )
F_162 ( V_40 , V_91 ) ;
}
static int T_2 F_163 ( unsigned long V_21 ,
unsigned long V_38 , unsigned long V_137 )
{
unsigned long V_37 , V_39 , V_138 ;
long V_139 ;
int V_61 , V_140 , V_141 , V_40 ;
unsigned long V_9 ;
struct V_42 * V_42 ;
struct V_88 V_85 ;
if ( ! F_164 ( V_21 , V_118 ) )
return - V_76 ;
if ( ! F_164 ( V_38 , V_118 ) )
return - V_76 ;
if ( ! F_129 ( V_21 , V_38 ) )
return - V_76 ;
F_1 () ;
V_42 = F_63 ( F_45 ( V_21 ) ) ;
V_40 = F_66 ( V_42 ) ;
V_39 = V_38 - V_21 ;
V_61 = - V_76 ;
if ( F_43 ( V_42 ) <= V_90 && ! F_159 ( V_42 , V_39 ) )
goto V_113;
V_61 = F_165 ( V_21 , V_38 ,
V_142 , true ) ;
if ( V_61 )
goto V_113;
V_85 . V_21 = V_21 ;
V_85 . V_39 = V_39 ;
F_160 ( V_39 , V_42 , & V_85 ) ;
V_61 = V_88 ( V_143 , & V_85 ) ;
V_61 = F_94 ( V_61 ) ;
if ( V_61 )
goto V_144;
V_37 = V_21 ;
V_138 = V_145 + V_137 ;
V_140 = 0 ;
V_141 = 5 ;
V_146:
V_61 = - V_147 ;
if ( F_166 ( V_145 , V_138 ) )
goto V_144;
V_61 = - V_148 ;
if ( F_167 ( V_149 ) )
goto V_144;
V_61 = 0 ;
if ( V_140 ) {
F_168 () ;
F_128 () ;
F_169 () ;
}
V_37 = F_131 ( V_21 , V_38 ) ;
if ( V_37 ) {
V_61 = F_137 ( V_37 , V_38 ) ;
if ( ! V_61 ) {
V_140 = 1 ;
goto V_146;
} else {
if ( V_61 < 0 )
if ( -- V_141 == 0 )
goto V_144;
F_170 () ;
V_140 = 1 ;
goto V_146;
}
}
F_168 () ;
F_170 () ;
F_169 () ;
F_171 ( V_21 , V_38 ) ;
V_139 = F_158 ( V_21 , V_38 ) ;
if ( V_139 < 0 ) {
V_61 = - V_128 ;
goto V_144;
}
F_99 ( V_150 L_7 , V_139 ) ;
F_155 ( V_21 , V_38 ) ;
F_172 ( V_21 , V_38 , V_142 ) ;
F_81 ( F_45 ( V_21 ) , - V_139 ) ;
V_42 -> V_106 -= V_139 ;
F_49 ( V_42 -> V_56 , & V_9 ) ;
V_42 -> V_56 -> V_107 -= V_139 ;
F_50 ( V_42 -> V_56 , & V_9 ) ;
F_101 () ;
if ( ! F_95 ( V_42 ) ) {
F_98 ( V_42 ) ;
F_2 ( & V_104 ) ;
F_96 ( NULL , NULL ) ;
F_4 ( & V_104 ) ;
} else
F_100 ( V_42 ) ;
F_161 ( V_40 , & V_85 ) ;
if ( V_85 . V_97 >= 0 )
F_173 ( V_40 ) ;
V_108 = F_103 () ;
F_104 () ;
V_88 ( V_151 , & V_85 ) ;
F_3 () ;
return 0 ;
V_144:
F_99 ( V_150 L_8 ,
( unsigned long long ) V_21 << V_31 ,
( ( unsigned long long ) V_38 << V_31 ) - 1 ) ;
V_88 ( V_152 , & V_85 ) ;
F_172 ( V_21 , V_38 , V_142 ) ;
V_113:
F_3 () ;
return V_61 ;
}
int F_174 ( unsigned long V_21 , unsigned long V_39 )
{
return F_163 ( V_21 , V_21 + V_39 , 120 * V_153 ) ;
}
int F_175 ( unsigned long V_21 , unsigned long V_38 ,
void * V_85 , int (* F_176)( struct V_154 * , void * ) )
{
struct V_154 * V_155 = NULL ;
struct V_26 * V_156 ;
unsigned long V_37 , V_24 ;
int V_61 ;
for ( V_37 = V_21 ; V_37 < V_38 ; V_37 += V_30 ) {
V_24 = F_23 ( V_37 ) ;
if ( ! F_177 ( V_24 ) )
continue;
V_156 = F_24 ( V_24 ) ;
if ( V_155 )
if ( ( V_24 >= V_155 -> V_157 ) &&
( V_24 <= V_155 -> V_158 ) )
continue;
V_155 = F_178 ( V_156 , V_155 ) ;
if ( ! V_155 )
continue;
V_61 = F_176 ( V_155 , V_85 ) ;
if ( V_61 ) {
F_179 ( & V_155 -> V_159 . V_160 ) ;
return V_61 ;
}
}
if ( V_155 )
F_179 ( & V_155 -> V_159 . V_160 ) ;
return 0 ;
}
static int F_180 ( struct V_154 * V_155 , void * V_85 )
{
int V_61 = ! F_181 ( V_155 ) ;
if ( F_61 ( V_61 ) ) {
T_7 V_161 , V_162 ;
V_161 = F_182 ( F_72 ( V_155 -> V_157 ) ) ;
V_162 = F_182 ( F_72 ( V_155 -> V_158 + 1 ) ) - 1 ;
F_76 ( L_9
L_10 ,
& V_161 , & V_162 ) ;
}
return V_61 ;
}
static int F_183 ( T_6 * V_36 )
{
int V_163 ;
F_184 (cpu) {
if ( F_185 ( V_163 ) == V_36 -> V_41 )
return - V_128 ;
}
return 0 ;
}
static void F_186 ( T_6 * V_36 )
{
#ifdef F_187
int V_163 ;
F_188 (cpu)
if ( F_185 ( V_163 ) == V_36 -> V_41 )
F_189 ( V_163 ) ;
#endif
}
static int F_190 ( T_6 * V_36 )
{
int V_61 ;
V_61 = F_183 ( V_36 ) ;
if ( V_61 )
return V_61 ;
F_186 ( V_36 ) ;
return 0 ;
}
void F_191 ( int V_55 )
{
T_6 * V_36 = F_106 ( V_55 ) ;
unsigned long V_21 = V_36 -> V_49 ;
unsigned long V_38 = V_21 + V_36 -> V_66 ;
unsigned long V_37 ;
struct V_14 * V_164 = F_26 ( V_36 ) ;
int V_25 ;
for ( V_37 = V_21 ; V_37 < V_38 ; V_37 += V_30 ) {
unsigned long V_24 = F_23 ( V_37 ) ;
if ( ! F_177 ( V_24 ) )
continue;
if ( F_34 ( V_37 ) != V_55 )
continue;
return;
}
if ( F_190 ( V_36 ) )
return;
F_192 ( V_55 ) ;
F_193 ( V_55 ) ;
if ( ! F_194 ( V_164 ) && ! F_195 ( V_164 ) )
return;
for ( V_25 = 0 ; V_25 < V_45 ; V_25 ++ ) {
struct V_42 * V_42 = V_36 -> V_44 + V_25 ;
if ( F_196 ( V_42 -> V_48 ) )
F_197 ( V_42 -> V_48 ) ;
}
memset ( V_36 , 0 , sizeof( * V_36 ) ) ;
}
void T_2 F_198 ( int V_55 , T_1 V_3 , T_1 V_4 )
{
int V_61 ;
F_7 ( F_115 ( V_3 , V_4 ) ) ;
F_1 () ;
V_61 = F_175 ( F_199 ( V_3 ) , F_200 ( V_3 + V_4 - 1 ) , NULL ,
F_180 ) ;
if ( V_61 ) {
F_3 () ;
F_201 () ;
}
F_202 ( V_3 , V_3 + V_4 , L_1 ) ;
F_203 ( V_3 , V_4 ) ;
F_191 ( V_55 ) ;
F_3 () ;
}
