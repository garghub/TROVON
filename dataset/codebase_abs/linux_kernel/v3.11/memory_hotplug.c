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
void F_19 ( struct V_14 * V_14 )
{
unsigned long type ;
type = ( unsigned long ) V_14 -> V_15 . V_16 ;
F_9 ( type < V_19 ||
type > V_20 ) ;
if ( F_20 ( & V_14 -> V_18 ) == 1 ) {
F_21 ( V_14 ) ;
F_17 ( V_14 , 0 ) ;
F_22 ( & V_14 -> V_15 ) ;
F_23 ( V_14 ) ;
}
}
static void F_24 ( unsigned long V_21 )
{
unsigned long * V_22 , V_23 , V_24 , V_25 ;
struct V_26 * V_27 ;
struct V_14 * V_14 , * V_28 ;
V_24 = F_25 ( V_21 ) ;
V_27 = F_26 ( V_24 ) ;
V_28 = F_27 ( V_27 -> V_29 , V_24 ) ;
V_14 = F_28 ( V_28 ) ;
V_23 = sizeof( struct V_14 ) * V_30 ;
V_23 = F_29 ( V_23 ) >> V_31 ;
for ( V_25 = 0 ; V_25 < V_23 ; V_25 ++ , V_14 ++ )
F_15 ( V_24 , V_14 , V_32 ) ;
V_22 = F_26 ( V_24 ) -> V_33 ;
V_14 = F_28 ( V_22 ) ;
V_23 = F_29 ( F_30 () ) >> V_31 ;
for ( V_25 = 0 ; V_25 < V_23 ; V_25 ++ , V_14 ++ )
F_15 ( V_24 , V_14 , V_34 ) ;
}
static void F_24 ( unsigned long V_21 )
{
unsigned long * V_22 , V_23 , V_24 , V_25 ;
struct V_26 * V_27 ;
struct V_14 * V_14 , * V_28 ;
if ( ! F_31 ( V_21 ) )
return;
V_24 = F_25 ( V_21 ) ;
V_27 = F_26 ( V_24 ) ;
V_28 = F_27 ( V_27 -> V_29 , V_24 ) ;
F_32 ( V_24 , V_28 , V_30 ) ;
V_22 = F_26 ( V_24 ) -> V_33 ;
V_14 = F_28 ( V_22 ) ;
V_23 = F_29 ( F_30 () ) >> V_31 ;
for ( V_25 = 0 ; V_25 < V_23 ; V_25 ++ , V_14 ++ )
F_15 ( V_24 , V_14 , V_34 ) ;
}
void F_33 ( struct V_35 * V_36 )
{
unsigned long V_25 , V_37 , V_38 , V_39 ;
int V_40 = V_36 -> V_41 ;
struct V_14 * V_14 ;
struct V_42 * V_42 ;
V_39 = F_29 ( sizeof( struct V_35 ) ) >> V_31 ;
V_14 = F_28 ( V_36 ) ;
for ( V_25 = 0 ; V_25 < V_39 ; V_25 ++ , V_14 ++ )
F_15 ( V_40 , V_14 , V_43 ) ;
V_42 = & V_36 -> V_44 [ 0 ] ;
for (; V_42 < V_36 -> V_44 + V_45 - 1 ; V_42 ++ ) {
if ( V_42 -> V_46 ) {
V_39 = V_42 -> V_47
* sizeof( V_48 ) ;
V_39 = F_29 ( V_39 ) >> V_31 ;
V_14 = F_28 ( V_42 -> V_46 ) ;
for ( V_25 = 0 ; V_25 < V_39 ; V_25 ++ , V_14 ++ )
F_15 ( V_40 , V_14 , V_43 ) ;
}
}
V_37 = V_36 -> V_49 ;
V_38 = F_34 ( V_36 ) ;
for (; V_37 < V_38 ; V_37 += V_30 ) {
if ( F_31 ( V_37 ) && ( F_35 ( V_37 ) == V_40 ) )
F_24 ( V_37 ) ;
}
}
static void F_36 ( struct V_42 * V_42 , unsigned long V_21 ,
unsigned long V_38 )
{
unsigned long V_50 ;
F_37 ( V_42 ) ;
V_50 = V_42 -> V_51 + V_42 -> V_52 ;
if ( ! V_42 -> V_52 || V_21 < V_42 -> V_51 )
V_42 -> V_51 = V_21 ;
V_42 -> V_52 = F_38 ( V_50 , V_38 ) -
V_42 -> V_51 ;
F_39 ( V_42 ) ;
}
static void F_40 ( struct V_42 * V_42 , unsigned long V_21 ,
unsigned long V_38 )
{
F_37 ( V_42 ) ;
if ( V_38 - V_21 ) {
V_42 -> V_51 = V_21 ;
V_42 -> V_52 = V_38 - V_21 ;
} else {
V_42 -> V_51 = 0 ;
V_42 -> V_52 = 0 ;
}
F_39 ( V_42 ) ;
}
static void F_41 ( struct V_42 * V_42 , unsigned long V_21 ,
unsigned long V_38 )
{
enum V_53 V_54 = F_42 ( V_42 ) ;
int V_55 = V_42 -> V_56 -> V_41 ;
unsigned long V_37 ;
for ( V_37 = V_21 ; V_37 < V_38 ; V_37 ++ )
F_43 ( F_44 ( V_37 ) , V_54 , V_55 , V_37 ) ;
}
static int T_2 F_45 ( struct V_42 * V_42 ,
unsigned long V_21 , unsigned long V_57 )
{
if ( ! F_46 ( V_42 ) )
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
V_61 = F_45 ( V_59 , V_21 , V_38 - V_21 ) ;
if ( V_61 )
return V_61 ;
F_49 ( V_59 -> V_56 , & V_9 ) ;
if ( V_38 > F_50 ( V_60 ) )
goto V_63;
if ( V_21 > V_60 -> V_51 )
goto V_63;
if ( V_38 <= V_60 -> V_51 )
goto V_63;
if ( V_59 -> V_52 )
V_62 = V_59 -> V_51 ;
else
V_62 = V_21 ;
F_40 ( V_59 , V_62 , V_38 ) ;
F_40 ( V_60 , V_38 , F_50 ( V_60 ) ) ;
F_51 ( V_59 -> V_56 , & V_9 ) ;
F_41 ( V_59 , V_21 , V_38 ) ;
return 0 ;
V_63:
F_51 ( V_59 -> V_56 , & V_9 ) ;
return - 1 ;
}
static int T_3 F_52 ( struct V_42 * V_59 , struct V_42 * V_60 ,
unsigned long V_21 , unsigned long V_38 )
{
int V_61 ;
unsigned long V_9 ;
unsigned long V_64 ;
V_61 = F_45 ( V_60 , V_21 , V_38 - V_21 ) ;
if ( V_61 )
return V_61 ;
F_49 ( V_59 -> V_56 , & V_9 ) ;
if ( V_59 -> V_51 > V_21 )
goto V_63;
if ( F_50 ( V_59 ) > V_38 )
goto V_63;
if ( V_21 >= F_50 ( V_59 ) )
goto V_63;
if ( V_60 -> V_52 )
V_64 = F_50 ( V_60 ) ;
else
V_64 = V_38 ;
F_40 ( V_59 , V_59 -> V_51 , V_21 ) ;
F_40 ( V_60 , V_21 , V_64 ) ;
F_51 ( V_59 -> V_56 , & V_9 ) ;
F_41 ( V_60 , V_21 , V_38 ) ;
return 0 ;
V_63:
F_51 ( V_59 -> V_56 , & V_9 ) ;
return - 1 ;
}
static void F_53 ( struct V_35 * V_36 , unsigned long V_21 ,
unsigned long V_38 )
{
unsigned long V_65 =
V_36 -> V_49 + V_36 -> V_66 ;
if ( ! V_36 -> V_66 || V_21 < V_36 -> V_49 )
V_36 -> V_49 = V_21 ;
V_36 -> V_66 = F_38 ( V_65 , V_38 ) -
V_36 -> V_49 ;
}
static int T_3 F_54 ( struct V_42 * V_42 , unsigned long V_67 )
{
struct V_35 * V_36 = V_42 -> V_56 ;
int V_39 = V_30 ;
int V_55 = V_36 -> V_41 ;
int V_53 ;
unsigned long V_9 ;
int V_61 ;
V_53 = V_42 - V_36 -> V_44 ;
V_61 = F_45 ( V_42 , V_67 , V_39 ) ;
if ( V_61 )
return V_61 ;
F_49 ( V_42 -> V_56 , & V_9 ) ;
F_36 ( V_42 , V_67 , V_67 + V_39 ) ;
F_53 ( V_42 -> V_56 , V_67 ,
V_67 + V_39 ) ;
F_51 ( V_42 -> V_56 , & V_9 ) ;
F_55 ( V_39 , V_55 , V_53 ,
V_67 , V_58 ) ;
return 0 ;
}
static int T_3 F_56 ( int V_55 , struct V_42 * V_42 ,
unsigned long V_67 )
{
int V_39 = V_30 ;
int V_61 ;
if ( F_31 ( V_67 ) )
return - V_68 ;
V_61 = F_57 ( V_42 , V_67 , V_39 ) ;
if ( V_61 < 0 )
return V_61 ;
V_61 = F_54 ( V_42 , V_67 ) ;
if ( V_61 < 0 )
return V_61 ;
return F_58 ( V_55 , F_59 ( V_67 ) ) ;
}
int T_2 F_60 ( int V_55 , struct V_42 * V_42 , unsigned long V_67 ,
unsigned long V_39 )
{
unsigned long V_25 ;
int V_69 = 0 ;
int V_70 , V_71 ;
V_70 = F_25 ( V_67 ) ;
V_71 = F_25 ( V_67 + V_39 - 1 ) ;
for ( V_25 = V_70 ; V_25 <= V_71 ; V_25 ++ ) {
V_69 = F_56 ( V_55 , V_42 , V_25 << V_72 ) ;
if ( V_69 && ( V_69 != - V_68 ) )
break;
V_69 = 0 ;
}
return V_69 ;
}
static int F_61 ( int V_55 , struct V_42 * V_42 ,
unsigned long V_21 ,
unsigned long V_38 )
{
struct V_26 * V_27 ;
for (; V_21 < V_38 ; V_21 += V_30 ) {
V_27 = F_59 ( V_21 ) ;
if ( F_62 ( ! F_63 ( V_27 ) ) )
continue;
if ( F_62 ( F_35 ( V_21 ) != V_55 ) )
continue;
if ( V_42 && V_42 != F_64 ( F_44 ( V_21 ) ) )
continue;
return V_21 ;
}
return 0 ;
}
static int F_65 ( int V_55 , struct V_42 * V_42 ,
unsigned long V_21 ,
unsigned long V_38 )
{
struct V_26 * V_27 ;
unsigned long V_37 ;
V_37 = V_38 - 1 ;
for (; V_37 >= V_21 ; V_37 -= V_30 ) {
V_27 = F_59 ( V_37 ) ;
if ( F_62 ( ! F_63 ( V_27 ) ) )
continue;
if ( F_62 ( F_35 ( V_37 ) != V_55 ) )
continue;
if ( V_42 && V_42 != F_64 ( F_44 ( V_37 ) ) )
continue;
return V_37 ;
}
return 0 ;
}
static void F_66 ( struct V_42 * V_42 , unsigned long V_21 ,
unsigned long V_38 )
{
unsigned long V_51 = V_42 -> V_51 ;
unsigned long F_50 = V_42 -> V_51 + V_42 -> V_52 ;
unsigned long V_37 ;
struct V_26 * V_27 ;
int V_55 = F_67 ( V_42 ) ;
F_37 ( V_42 ) ;
if ( V_51 == V_21 ) {
V_37 = F_61 ( V_55 , V_42 , V_38 ,
F_50 ) ;
if ( V_37 ) {
V_42 -> V_51 = V_37 ;
V_42 -> V_52 = F_50 - V_37 ;
}
} else if ( F_50 == V_38 ) {
V_37 = F_65 ( V_55 , V_42 , V_51 ,
V_21 ) ;
if ( V_37 )
V_42 -> V_52 = V_37 - V_51 + 1 ;
}
V_37 = V_51 ;
for (; V_37 < F_50 ; V_37 += V_30 ) {
V_27 = F_59 ( V_37 ) ;
if ( F_62 ( ! F_63 ( V_27 ) ) )
continue;
if ( F_64 ( F_44 ( V_37 ) ) != V_42 )
continue;
if ( V_21 == V_37 )
continue;
F_39 ( V_42 ) ;
return;
}
V_42 -> V_51 = 0 ;
V_42 -> V_52 = 0 ;
F_39 ( V_42 ) ;
}
static void F_68 ( struct V_35 * V_36 ,
unsigned long V_21 , unsigned long V_38 )
{
unsigned long V_73 = V_36 -> V_49 ;
unsigned long F_34 =
V_36 -> V_49 + V_36 -> V_66 ;
unsigned long V_37 ;
struct V_26 * V_27 ;
int V_55 = V_36 -> V_41 ;
if ( V_73 == V_21 ) {
V_37 = F_61 ( V_55 , NULL , V_38 ,
F_34 ) ;
if ( V_37 ) {
V_36 -> V_49 = V_37 ;
V_36 -> V_66 = F_34 - V_37 ;
}
} else if ( F_34 == V_38 ) {
V_37 = F_65 ( V_55 , NULL , V_73 ,
V_21 ) ;
if ( V_37 )
V_36 -> V_66 = V_37 - V_73 + 1 ;
}
V_37 = V_73 ;
for (; V_37 < F_34 ; V_37 += V_30 ) {
V_27 = F_59 ( V_37 ) ;
if ( F_62 ( ! F_63 ( V_27 ) ) )
continue;
if ( F_35 ( V_37 ) != V_55 )
continue;
if ( V_21 == V_37 )
continue;
return;
}
V_36 -> V_49 = 0 ;
V_36 -> V_66 = 0 ;
}
static void F_69 ( struct V_42 * V_42 , unsigned long V_21 )
{
struct V_35 * V_36 = V_42 -> V_56 ;
int V_39 = V_30 ;
int V_53 ;
unsigned long V_9 ;
V_53 = V_42 - V_36 -> V_44 ;
F_49 ( V_42 -> V_56 , & V_9 ) ;
F_66 ( V_42 , V_21 , V_21 + V_39 ) ;
F_68 ( V_36 , V_21 , V_21 + V_39 ) ;
F_51 ( V_42 -> V_56 , & V_9 ) ;
}
static int F_70 ( struct V_42 * V_42 , struct V_26 * V_27 )
{
unsigned long V_21 ;
int V_74 ;
int V_61 = - V_75 ;
if ( ! F_63 ( V_27 ) )
return V_61 ;
V_61 = F_71 ( V_27 ) ;
if ( V_61 )
return V_61 ;
V_74 = F_72 ( V_27 ) ;
V_21 = F_73 ( V_74 ) ;
F_69 ( V_42 , V_21 ) ;
F_74 ( V_42 , V_27 ) ;
return 0 ;
}
int F_75 ( struct V_42 * V_42 , unsigned long V_67 ,
unsigned long V_39 )
{
unsigned long V_25 ;
int V_76 ;
T_4 V_3 , V_4 ;
int V_61 = 0 ;
F_9 ( V_67 & ~ V_77 ) ;
F_9 ( V_39 % V_30 ) ;
V_3 = V_67 << V_31 ;
V_4 = V_39 * V_78 ;
V_61 = F_76 ( & V_12 , V_3 , V_4 ) ;
if ( V_61 ) {
T_4 V_79 = V_3 + V_4 - 1 ;
F_77 ( L_3 ,
& V_3 , & V_79 , V_61 ) ;
}
V_76 = V_39 / V_30 ;
for ( V_25 = 0 ; V_25 < V_76 ; V_25 ++ ) {
unsigned long V_37 = V_67 + V_25 * V_30 ;
V_61 = F_70 ( V_42 , F_59 ( V_37 ) ) ;
if ( V_61 )
break;
}
return V_61 ;
}
int F_78 ( T_5 V_80 )
{
int V_81 = - V_75 ;
F_1 () ;
if ( V_82 == V_83 ) {
V_82 = V_80 ;
V_81 = 0 ;
}
F_4 () ;
return V_81 ;
}
int F_79 ( T_5 V_80 )
{
int V_81 = - V_75 ;
F_1 () ;
if ( V_82 == V_80 ) {
V_82 = V_83 ;
V_81 = 0 ;
}
F_4 () ;
return V_81 ;
}
void F_80 ( struct V_14 * V_14 )
{
}
void F_81 ( struct V_14 * V_14 )
{
F_82 ( V_14 , 1 ) ;
}
void F_83 ( struct V_14 * V_14 )
{
F_84 ( V_14 ) ;
}
static void V_83 ( struct V_14 * V_14 )
{
F_80 ( V_14 ) ;
F_81 ( V_14 ) ;
F_83 ( V_14 ) ;
}
static int F_85 ( unsigned long V_21 , unsigned long V_39 ,
void * V_84 )
{
unsigned long V_25 ;
unsigned long V_85 = * ( unsigned long * ) V_84 ;
struct V_14 * V_14 ;
if ( F_86 ( F_44 ( V_21 ) ) )
for ( V_25 = 0 ; V_25 < V_39 ; V_25 ++ ) {
V_14 = F_44 ( V_21 + V_25 ) ;
(* V_82)( V_14 ) ;
V_85 ++ ;
}
* ( unsigned long * ) V_84 = V_85 ;
return 0 ;
}
static bool F_87 ( struct V_42 * V_42 )
{
return true ;
}
static bool F_87 ( struct V_42 * V_42 )
{
return F_88 ( F_67 ( V_42 ) , V_86 ) ;
}
static void F_89 ( unsigned long V_39 ,
struct V_42 * V_42 , struct V_87 * V_84 )
{
int V_55 = F_67 ( V_42 ) ;
enum V_53 V_88 = V_89 ;
if ( V_90 == V_86 )
V_88 = V_91 ;
if ( F_42 ( V_42 ) <= V_88 && ! F_88 ( V_55 , V_86 ) )
V_84 -> V_92 = V_55 ;
else
V_84 -> V_92 = - 1 ;
#ifdef F_90
V_88 = V_93 ;
if ( V_90 == V_94 )
V_88 = V_91 ;
if ( F_42 ( V_42 ) <= V_88 && ! F_88 ( V_55 , V_94 ) )
V_84 -> V_95 = V_55 ;
else
V_84 -> V_95 = - 1 ;
#else
V_84 -> V_95 = V_84 -> V_92 ;
#endif
if ( ! F_88 ( V_55 , V_90 ) )
V_84 -> V_96 = V_55 ;
else
V_84 -> V_96 = - 1 ;
}
static void F_91 ( int V_40 , struct V_87 * V_84 )
{
if ( V_84 -> V_92 >= 0 )
F_92 ( V_40 , V_86 ) ;
if ( V_84 -> V_95 >= 0 )
F_92 ( V_40 , V_94 ) ;
F_92 ( V_40 , V_90 ) ;
}
int T_2 F_93 ( unsigned long V_37 , unsigned long V_39 , int V_97 )
{
unsigned long V_9 ;
unsigned long V_85 = 0 ;
struct V_42 * V_42 ;
int V_98 = 0 ;
int V_55 ;
int V_61 ;
struct V_87 V_84 ;
F_1 () ;
V_42 = F_64 ( F_44 ( V_37 ) ) ;
if ( ( F_42 ( V_42 ) > V_89 || V_97 == V_99 ) &&
! F_87 ( V_42 ) ) {
F_4 () ;
return - V_75 ;
}
if ( V_97 == V_100 && F_42 ( V_42 ) == V_91 ) {
if ( F_48 ( V_42 - 1 , V_42 , V_37 , V_37 + V_39 ) ) {
F_4 () ;
return - V_75 ;
}
}
if ( V_97 == V_99 && F_42 ( V_42 ) == V_91 - 1 ) {
if ( F_52 ( V_42 , V_42 + 1 , V_37 , V_37 + V_39 ) ) {
F_4 () ;
return - V_75 ;
}
}
V_42 = F_64 ( F_44 ( V_37 ) ) ;
V_84 . V_21 = V_37 ;
V_84 . V_39 = V_39 ;
F_89 ( V_39 , V_42 , & V_84 ) ;
V_55 = F_94 ( F_44 ( V_37 ) ) ;
V_61 = V_87 ( V_101 , & V_84 ) ;
V_61 = F_95 ( V_61 ) ;
if ( V_61 ) {
V_87 ( V_102 , & V_84 ) ;
F_4 () ;
return V_61 ;
}
F_2 ( & V_103 ) ;
if ( ! F_96 ( V_42 ) ) {
V_98 = 1 ;
F_97 ( NULL , V_42 ) ;
}
V_61 = F_98 ( V_37 , V_39 , & V_85 ,
F_85 ) ;
if ( V_61 ) {
if ( V_98 )
F_99 ( V_42 ) ;
F_6 ( & V_103 ) ;
F_100 ( V_104 L_4 ,
( unsigned long long ) V_37 << V_31 ,
( ( ( unsigned long long ) V_37 + V_39 )
<< V_31 ) - 1 ) ;
V_87 ( V_102 , & V_84 ) ;
F_4 () ;
return V_61 ;
}
V_42 -> V_105 += V_85 ;
F_49 ( V_42 -> V_56 , & V_9 ) ;
V_42 -> V_56 -> V_106 += V_85 ;
F_51 ( V_42 -> V_56 , & V_9 ) ;
if ( V_85 ) {
F_91 ( F_67 ( V_42 ) , & V_84 ) ;
if ( V_98 )
F_97 ( NULL , NULL ) ;
else
F_101 ( V_42 ) ;
}
F_6 ( & V_103 ) ;
F_102 () ;
if ( V_85 )
F_103 ( F_67 ( V_42 ) ) ;
V_107 = F_104 () ;
F_105 () ;
if ( V_85 )
V_87 ( V_108 , & V_84 ) ;
F_4 () ;
return 0 ;
}
static T_6 T_2 * F_106 ( int V_55 , T_1 V_3 )
{
struct V_35 * V_36 ;
unsigned long V_109 [ V_45 ] = { 0 } ;
unsigned long V_110 [ V_45 ] = { 0 } ;
unsigned long V_21 = V_3 >> V_31 ;
V_36 = F_107 ( V_55 ) ;
if ( ! V_36 ) {
V_36 = F_108 ( V_55 ) ;
if ( ! V_36 )
return NULL ;
F_109 ( V_55 , V_36 ) ;
}
F_110 ( V_55 , V_109 , V_21 , V_110 ) ;
F_2 ( & V_103 ) ;
F_97 ( V_36 , NULL ) ;
F_6 ( & V_103 ) ;
return V_36 ;
}
static void F_111 ( int V_55 , T_6 * V_36 )
{
F_109 ( V_55 , NULL ) ;
F_112 ( V_36 ) ;
return;
}
int F_113 ( int V_55 )
{
T_6 * V_36 ;
int V_61 ;
F_1 () ;
V_36 = F_106 ( V_55 , 0 ) ;
if ( ! V_36 ) {
V_61 = - V_111 ;
goto V_112;
}
F_114 ( V_55 ) ;
V_61 = F_115 ( V_55 ) ;
F_9 ( V_61 ) ;
V_112:
F_4 () ;
return V_61 ;
}
int T_2 F_116 ( int V_55 , T_1 V_3 , T_1 V_4 )
{
T_6 * V_36 = NULL ;
bool V_113 ;
bool V_114 ;
struct V_2 * V_5 ;
int V_61 ;
F_1 () ;
V_5 = F_7 ( V_3 , V_4 ) ;
V_61 = - V_68 ;
if ( ! V_5 )
goto V_112;
{
void * V_115 = F_107 ( V_55 ) ;
V_113 = ! V_115 ;
}
V_114 = ! F_117 ( V_55 ) ;
if ( V_114 ) {
V_36 = F_106 ( V_55 , V_3 ) ;
V_61 = - V_111 ;
if ( ! V_36 )
goto error;
}
V_61 = F_118 ( V_55 , V_3 , V_4 ) ;
if ( V_61 < 0 )
goto error;
F_114 ( V_55 ) ;
if ( V_114 ) {
V_61 = F_115 ( V_55 ) ;
F_9 ( V_61 ) ;
}
F_119 ( V_3 , V_3 + V_4 , L_1 ) ;
goto V_112;
error:
if ( V_113 )
F_111 ( V_55 , V_36 ) ;
F_13 ( V_5 ) ;
V_112:
F_4 () ;
return V_61 ;
}
static inline int F_120 ( struct V_14 * V_14 )
{
return F_121 ( V_14 ) && F_122 ( V_14 ) >= V_116 ;
}
static struct V_14 * F_123 ( struct V_14 * V_14 )
{
F_9 ( F_124 ( V_14 ) & ( V_117 - 1 ) ) ;
if ( F_120 ( V_14 ) ) {
int V_118 ;
V_118 = F_122 ( V_14 ) ;
if ( ( V_118 < V_119 ) && ( V_118 >= V_116 ) )
return V_14 + ( 1 << V_118 ) ;
}
return V_14 + V_117 ;
}
int F_125 ( unsigned long V_21 , unsigned long V_39 )
{
struct V_14 * V_14 = F_44 ( V_21 ) ;
struct V_14 * V_120 = V_14 + V_39 ;
for (; V_14 < V_120 ; V_14 = F_123 ( V_14 ) ) {
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
V_37 += V_121 ) {
V_25 = 0 ;
while ( ( V_25 < V_121 ) && ! F_129 ( V_37 + V_25 ) )
V_25 ++ ;
if ( V_25 == V_121 )
continue;
V_14 = F_44 ( V_37 + V_25 ) ;
if ( V_42 && F_64 ( V_14 ) != V_42 )
return 0 ;
V_42 = F_64 ( V_14 ) ;
}
return 1 ;
}
static unsigned long F_130 ( unsigned long V_3 , unsigned long V_8 )
{
unsigned long V_37 ;
struct V_14 * V_14 ;
for ( V_37 = V_3 ; V_37 < V_8 ; V_37 ++ ) {
if ( F_31 ( V_37 ) ) {
V_14 = F_44 ( V_37 ) ;
if ( F_131 ( V_14 ) )
return V_37 ;
}
}
return 0 ;
}
static int
F_132 ( unsigned long V_21 , unsigned long V_38 )
{
unsigned long V_37 ;
struct V_14 * V_14 ;
int V_122 = V_123 ;
int V_124 = 0 ;
int V_61 = 0 ;
F_133 ( V_125 ) ;
for ( V_37 = V_21 ; V_37 < V_38 && V_122 > 0 ; V_37 ++ ) {
if ( ! F_31 ( V_37 ) )
continue;
V_14 = F_44 ( V_37 ) ;
if ( ! F_134 ( V_14 ) )
continue;
V_61 = F_135 ( V_14 ) ;
if ( ! V_61 ) {
F_136 ( V_14 ) ;
F_137 ( & V_14 -> V_15 , & V_125 ) ;
V_122 -- ;
F_138 ( V_14 , V_126 +
F_139 ( V_14 ) ) ;
} else {
#ifdef F_140
F_100 ( V_127 L_5 ,
V_37 ) ;
F_141 ( V_14 ) ;
#endif
F_136 ( V_14 ) ;
if ( F_142 ( V_14 ) ) {
V_124 ++ ;
V_61 = - V_128 ;
break;
}
}
}
if ( ! F_143 ( & V_125 ) ) {
if ( V_124 ) {
F_144 ( & V_125 ) ;
goto V_112;
}
V_61 = F_145 ( & V_125 , V_129 , 0 ,
V_130 , V_131 ) ;
if ( V_61 )
F_144 ( & V_125 ) ;
}
V_112:
return V_61 ;
}
static int
F_146 ( unsigned long V_3 , unsigned long V_39 ,
void * V_132 )
{
F_147 ( V_3 , V_3 + V_39 ) ;
return 0 ;
}
static void
F_148 ( unsigned long V_21 , unsigned long V_38 )
{
F_98 ( V_21 , V_38 - V_21 , NULL ,
F_146 ) ;
}
static int
F_149 ( unsigned long V_21 , unsigned long V_39 ,
void * V_132 )
{
int V_61 ;
long V_133 = * ( long * ) V_132 ;
V_61 = F_150 ( V_21 , V_21 + V_39 , true ) ;
V_133 = V_39 ;
if ( ! V_61 )
* ( long * ) V_132 += V_133 ;
return V_61 ;
}
static long
F_151 ( unsigned long V_21 , unsigned long V_38 )
{
long V_133 = 0 ;
int V_61 ;
V_61 = F_98 ( V_21 , V_38 - V_21 , & V_133 ,
F_149 ) ;
if ( V_61 < 0 )
V_133 = ( long ) V_61 ;
return V_133 ;
}
static bool F_152 ( struct V_42 * V_42 , unsigned long V_39 )
{
return true ;
}
static bool F_152 ( struct V_42 * V_42 , unsigned long V_39 )
{
struct V_35 * V_36 = V_42 -> V_56 ;
unsigned long V_105 = 0 ;
enum V_53 V_134 ;
for ( V_134 = 0 ; V_134 <= V_89 ; V_134 ++ )
V_105 += V_36 -> V_44 [ V_134 ] . V_105 ;
if ( V_105 > V_39 )
return true ;
V_105 = 0 ;
for (; V_134 <= V_91 ; V_134 ++ )
V_105 += V_36 -> V_44 [ V_134 ] . V_105 ;
return V_105 == 0 ;
}
static void F_153 ( unsigned long V_39 ,
struct V_42 * V_42 , struct V_87 * V_84 )
{
struct V_35 * V_36 = V_42 -> V_56 ;
unsigned long V_105 = 0 ;
enum V_53 V_134 , V_88 = V_89 ;
if ( V_90 == V_86 )
V_88 = V_91 ;
for ( V_134 = 0 ; V_134 <= V_88 ; V_134 ++ )
V_105 += V_36 -> V_44 [ V_134 ] . V_105 ;
if ( F_42 ( V_42 ) <= V_88 && V_39 >= V_105 )
V_84 -> V_92 = F_67 ( V_42 ) ;
else
V_84 -> V_92 = - 1 ;
#ifdef F_90
V_88 = V_93 ;
if ( V_90 == V_94 )
V_88 = V_91 ;
for (; V_134 <= V_88 ; V_134 ++ )
V_105 += V_36 -> V_44 [ V_134 ] . V_105 ;
if ( F_42 ( V_42 ) <= V_88 && V_39 >= V_105 )
V_84 -> V_95 = F_67 ( V_42 ) ;
else
V_84 -> V_95 = - 1 ;
#else
V_84 -> V_95 = V_84 -> V_92 ;
#endif
V_88 = V_91 ;
for (; V_134 <= V_88 ; V_134 ++ )
V_105 += V_36 -> V_44 [ V_134 ] . V_105 ;
if ( V_39 >= V_105 )
V_84 -> V_96 = F_67 ( V_42 ) ;
else
V_84 -> V_96 = - 1 ;
}
static void F_154 ( int V_40 , struct V_87 * V_84 )
{
if ( V_84 -> V_92 >= 0 )
F_155 ( V_40 , V_86 ) ;
if ( ( V_90 != V_86 ) &&
( V_84 -> V_95 >= 0 ) )
F_155 ( V_40 , V_94 ) ;
if ( ( V_90 != V_94 ) &&
( V_84 -> V_96 >= 0 ) )
F_155 ( V_40 , V_90 ) ;
}
static int T_2 F_156 ( unsigned long V_21 ,
unsigned long V_38 , unsigned long V_135 )
{
unsigned long V_37 , V_39 , V_136 ;
long V_137 ;
int V_61 , V_138 , V_139 , V_40 ;
unsigned long V_9 ;
struct V_42 * V_42 ;
struct V_87 V_84 ;
F_9 ( V_21 >= V_38 ) ;
if ( ! F_157 ( V_21 , V_117 ) )
return - V_75 ;
if ( ! F_157 ( V_38 , V_117 ) )
return - V_75 ;
if ( ! F_128 ( V_21 , V_38 ) )
return - V_75 ;
F_1 () ;
V_42 = F_64 ( F_44 ( V_21 ) ) ;
V_40 = F_67 ( V_42 ) ;
V_39 = V_38 - V_21 ;
V_61 = - V_75 ;
if ( F_42 ( V_42 ) <= V_89 && ! F_152 ( V_42 , V_39 ) )
goto V_112;
V_61 = F_158 ( V_21 , V_38 ,
V_140 , true ) ;
if ( V_61 )
goto V_112;
V_84 . V_21 = V_21 ;
V_84 . V_39 = V_39 ;
F_153 ( V_39 , V_42 , & V_84 ) ;
V_61 = V_87 ( V_141 , & V_84 ) ;
V_61 = F_95 ( V_61 ) ;
if ( V_61 )
goto V_142;
V_37 = V_21 ;
V_136 = V_143 + V_135 ;
V_138 = 0 ;
V_139 = 5 ;
V_144:
V_61 = - V_145 ;
if ( F_159 ( V_143 , V_136 ) )
goto V_142;
V_61 = - V_146 ;
if ( F_160 ( V_147 ) )
goto V_142;
V_61 = 0 ;
if ( V_138 ) {
F_161 () ;
F_127 () ;
F_162 () ;
}
V_37 = F_130 ( V_21 , V_38 ) ;
if ( V_37 ) {
V_61 = F_132 ( V_37 , V_38 ) ;
if ( ! V_61 ) {
V_138 = 1 ;
goto V_144;
} else {
if ( V_61 < 0 )
if ( -- V_139 == 0 )
goto V_142;
F_163 () ;
V_138 = 1 ;
goto V_144;
}
}
F_161 () ;
F_163 () ;
F_162 () ;
V_137 = F_151 ( V_21 , V_38 ) ;
if ( V_137 < 0 ) {
V_61 = - V_128 ;
goto V_142;
}
F_100 ( V_148 L_6 , V_137 ) ;
F_148 ( V_21 , V_38 ) ;
F_164 ( V_21 , V_38 , V_140 ) ;
F_82 ( F_44 ( V_21 ) , - V_137 ) ;
V_42 -> V_105 -= V_137 ;
F_49 ( V_42 -> V_56 , & V_9 ) ;
V_42 -> V_56 -> V_106 -= V_137 ;
F_51 ( V_42 -> V_56 , & V_9 ) ;
F_102 () ;
if ( ! F_96 ( V_42 ) ) {
F_99 ( V_42 ) ;
F_2 ( & V_103 ) ;
F_97 ( NULL , NULL ) ;
F_6 ( & V_103 ) ;
} else
F_101 ( V_42 ) ;
F_154 ( V_40 , & V_84 ) ;
if ( V_84 . V_96 >= 0 )
F_165 ( V_40 ) ;
V_107 = F_104 () ;
F_105 () ;
V_87 ( V_149 , & V_84 ) ;
F_4 () ;
return 0 ;
V_142:
F_100 ( V_148 L_7 ,
( unsigned long long ) V_21 << V_31 ,
( ( unsigned long long ) V_38 << V_31 ) - 1 ) ;
V_87 ( V_150 , & V_84 ) ;
F_164 ( V_21 , V_38 , V_140 ) ;
V_112:
F_4 () ;
return V_61 ;
}
int F_166 ( unsigned long V_21 , unsigned long V_39 )
{
return F_156 ( V_21 , V_21 + V_39 , 120 * V_151 ) ;
}
int F_167 ( unsigned long V_21 , unsigned long V_38 ,
void * V_84 , int (* F_168)( struct V_152 * , void * ) )
{
struct V_152 * V_153 = NULL ;
struct V_26 * V_154 ;
unsigned long V_37 , V_24 ;
int V_61 ;
for ( V_37 = V_21 ; V_37 < V_38 ; V_37 += V_30 ) {
V_24 = F_25 ( V_37 ) ;
if ( ! F_169 ( V_24 ) )
continue;
V_154 = F_26 ( V_24 ) ;
if ( V_153 )
if ( ( V_24 >= V_153 -> V_155 ) &&
( V_24 <= V_153 -> V_156 ) )
continue;
V_153 = F_170 ( V_154 , V_153 ) ;
if ( ! V_153 )
continue;
V_61 = F_168 ( V_153 , V_84 ) ;
if ( V_61 ) {
F_171 ( & V_153 -> V_157 . V_158 ) ;
return V_61 ;
}
}
if ( V_153 )
F_171 ( & V_153 -> V_157 . V_158 ) ;
return 0 ;
}
static int F_172 ( struct V_152 * V_153 , void * V_84 )
{
int V_61 = ! F_173 ( V_153 ) ;
if ( F_62 ( V_61 ) ) {
T_7 V_159 , V_160 ;
V_159 = F_174 ( F_73 ( V_153 -> V_155 ) ) ;
V_160 = F_174 ( F_73 ( V_153 -> V_156 + 1 ) ) - 1 ;
F_77 ( L_8
L_9 ,
& V_159 , & V_160 ) ;
}
return V_61 ;
}
static int F_175 ( void * V_132 )
{
struct V_35 * V_36 = V_132 ;
int V_161 ;
F_176 (cpu) {
if ( F_177 ( V_161 ) == V_36 -> V_41 )
return - V_128 ;
}
return 0 ;
}
static void F_178 ( void * V_132 )
{
#ifdef F_179
struct V_35 * V_36 = V_132 ;
int V_161 ;
F_180 (cpu)
if ( F_177 ( V_161 ) == V_36 -> V_41 )
F_181 ( V_161 ) ;
#endif
}
static int F_182 ( void * V_132 )
{
int V_61 = F_175 ( V_132 ) ;
if ( V_61 )
return V_61 ;
F_178 ( V_132 ) ;
return 0 ;
}
void F_183 ( int V_55 )
{
T_6 * V_36 = F_107 ( V_55 ) ;
unsigned long V_21 = V_36 -> V_49 ;
unsigned long V_38 = V_21 + V_36 -> V_66 ;
unsigned long V_37 ;
struct V_14 * V_162 = F_28 ( V_36 ) ;
int V_25 ;
for ( V_37 = V_21 ; V_37 < V_38 ; V_37 += V_30 ) {
unsigned long V_24 = F_25 ( V_37 ) ;
if ( ! F_169 ( V_24 ) )
continue;
if ( F_35 ( V_37 ) != V_55 )
continue;
return;
}
if ( F_184 ( F_182 , V_36 , NULL ) )
return;
F_185 ( V_55 ) ;
F_186 ( V_55 ) ;
if ( ! F_187 ( V_162 ) && ! F_188 ( V_162 ) )
return;
for ( V_25 = 0 ; V_25 < V_45 ; V_25 ++ ) {
struct V_42 * V_42 = V_36 -> V_44 + V_25 ;
if ( F_189 ( V_42 -> V_46 ) )
F_190 ( V_42 -> V_46 ) ;
}
memset ( V_36 , 0 , sizeof( * V_36 ) ) ;
}
void T_2 F_191 ( int V_55 , T_1 V_3 , T_1 V_4 )
{
int V_61 ;
F_1 () ;
V_61 = F_167 ( F_192 ( V_3 ) , F_193 ( V_3 + V_4 - 1 ) , NULL ,
F_172 ) ;
if ( V_61 ) {
F_4 () ;
F_194 () ;
}
F_195 ( V_3 , V_3 + V_4 , L_1 ) ;
F_196 ( V_3 , V_4 ) ;
F_183 ( V_55 ) ;
F_4 () ;
}
