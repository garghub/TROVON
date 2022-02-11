void F_1 ( void )
{
F_2 () ;
if ( V_1 . V_2 == V_3 )
return;
F_3 () ;
F_4 ( & V_1 . V_4 ) ;
V_1 . V_5 ++ ;
F_5 ( & V_1 . V_4 ) ;
}
void F_6 ( void )
{
if ( V_1 . V_2 == V_3 )
return;
F_4 ( & V_1 . V_4 ) ;
if ( F_7 ( ! V_1 . V_5 ) )
V_1 . V_5 ++ ;
if ( ! -- V_1 . V_5 && F_8 ( V_1 . V_2 ) )
F_9 ( V_1 . V_2 ) ;
F_5 ( & V_1 . V_4 ) ;
F_10 () ;
}
void F_11 ( void )
{
V_1 . V_2 = V_3 ;
F_12 () ;
for (; ; ) {
F_4 ( & V_1 . V_4 ) ;
if ( F_13 ( ! V_1 . V_5 ) )
break;
F_14 ( V_6 ) ;
F_5 ( & V_1 . V_4 ) ;
F_15 () ;
}
}
void F_16 ( void )
{
V_1 . V_2 = NULL ;
F_5 ( & V_1 . V_4 ) ;
F_10 () ;
}
static struct V_7 * F_17 ( T_1 V_8 , T_1 V_9 )
{
struct V_7 * V_10 ;
V_10 = F_18 ( sizeof( struct V_7 ) , V_11 ) ;
if ( ! V_10 )
return F_19 ( - V_12 ) ;
V_10 -> V_13 = L_1 ;
V_10 -> V_8 = V_8 ;
V_10 -> V_14 = V_8 + V_9 - 1 ;
V_10 -> V_15 = V_16 | V_17 ;
if ( F_20 ( & V_18 , V_10 ) < 0 ) {
F_21 ( L_2 , V_10 ) ;
F_22 ( V_10 ) ;
return F_19 ( - V_19 ) ;
}
return V_10 ;
}
static void F_23 ( struct V_7 * V_10 )
{
if ( ! V_10 )
return;
F_24 ( V_10 ) ;
F_22 ( V_10 ) ;
return;
}
void F_25 ( unsigned long V_20 , struct V_21 * V_21 ,
unsigned long type )
{
V_21 -> V_22 . V_23 = (struct V_24 * ) type ;
F_26 ( V_21 ) ;
F_27 ( V_21 , V_20 ) ;
F_28 ( & V_21 -> V_25 ) ;
}
void F_29 ( struct V_21 * V_21 )
{
unsigned long type ;
type = ( unsigned long ) V_21 -> V_22 . V_23 ;
F_30 ( type < V_26 ||
type > V_27 ) ;
if ( F_31 ( & V_21 -> V_25 ) == 1 ) {
F_32 ( V_21 ) ;
F_27 ( V_21 , 0 ) ;
F_33 ( & V_21 -> V_22 ) ;
F_34 ( V_21 ) ;
}
}
static void F_35 ( unsigned long V_28 )
{
unsigned long * V_29 , V_30 , V_31 , V_32 ;
struct V_33 * V_34 ;
struct V_21 * V_21 , * V_35 ;
V_31 = F_36 ( V_28 ) ;
V_34 = F_37 ( V_31 ) ;
V_35 = F_38 ( V_34 -> V_36 , V_31 ) ;
V_21 = F_39 ( V_35 ) ;
V_30 = sizeof( struct V_21 ) * V_37 ;
V_30 = F_40 ( V_30 ) >> V_38 ;
for ( V_32 = 0 ; V_32 < V_30 ; V_32 ++ , V_21 ++ )
F_25 ( V_31 , V_21 , V_39 ) ;
V_29 = F_37 ( V_31 ) -> V_40 ;
V_21 = F_39 ( V_29 ) ;
V_30 = F_40 ( F_41 () ) >> V_38 ;
for ( V_32 = 0 ; V_32 < V_30 ; V_32 ++ , V_21 ++ )
F_25 ( V_31 , V_21 , V_41 ) ;
}
static void F_35 ( unsigned long V_28 )
{
unsigned long * V_29 , V_30 , V_31 , V_32 ;
struct V_33 * V_34 ;
struct V_21 * V_21 , * V_35 ;
if ( ! F_42 ( V_28 ) )
return;
V_31 = F_36 ( V_28 ) ;
V_34 = F_37 ( V_31 ) ;
V_35 = F_38 ( V_34 -> V_36 , V_31 ) ;
F_43 ( V_31 , V_35 , V_37 ) ;
V_29 = F_37 ( V_31 ) -> V_40 ;
V_21 = F_39 ( V_29 ) ;
V_30 = F_40 ( F_41 () ) >> V_38 ;
for ( V_32 = 0 ; V_32 < V_30 ; V_32 ++ , V_21 ++ )
F_25 ( V_31 , V_21 , V_41 ) ;
}
void F_44 ( struct V_42 * V_43 )
{
unsigned long V_32 , V_44 , V_45 , V_46 ;
int V_47 = V_43 -> V_48 ;
struct V_21 * V_21 ;
struct V_49 * V_49 ;
V_46 = F_40 ( sizeof( struct V_42 ) ) >> V_38 ;
V_21 = F_39 ( V_43 ) ;
for ( V_32 = 0 ; V_32 < V_46 ; V_32 ++ , V_21 ++ )
F_25 ( V_47 , V_21 , V_50 ) ;
V_49 = & V_43 -> V_51 [ 0 ] ;
for (; V_49 < V_43 -> V_51 + V_52 - 1 ; V_49 ++ ) {
if ( F_45 ( V_49 ) ) {
V_46 = V_49 -> V_53
* sizeof( V_54 ) ;
V_46 = F_40 ( V_46 ) >> V_38 ;
V_21 = F_39 ( V_49 -> V_55 ) ;
for ( V_32 = 0 ; V_32 < V_46 ; V_32 ++ , V_21 ++ )
F_25 ( V_47 , V_21 , V_50 ) ;
}
}
V_44 = V_43 -> V_56 ;
V_45 = F_46 ( V_43 ) ;
for (; V_44 < V_45 ; V_44 += V_37 ) {
if ( F_42 ( V_44 ) && ( F_47 ( V_44 ) == V_47 ) )
F_35 ( V_44 ) ;
}
}
static void T_2 F_48 ( struct V_49 * V_49 , unsigned long V_28 ,
unsigned long V_45 )
{
unsigned long V_57 ;
F_49 ( V_49 ) ;
V_57 = F_50 ( V_49 ) ;
if ( F_51 ( V_49 ) || V_28 < V_49 -> V_58 )
V_49 -> V_58 = V_28 ;
V_49 -> V_59 = F_52 ( V_57 , V_45 ) -
V_49 -> V_58 ;
F_53 ( V_49 ) ;
}
static void F_54 ( struct V_49 * V_49 , unsigned long V_28 ,
unsigned long V_45 )
{
F_49 ( V_49 ) ;
if ( V_45 - V_28 ) {
V_49 -> V_58 = V_28 ;
V_49 -> V_59 = V_45 - V_28 ;
} else {
V_49 -> V_58 = 0 ;
V_49 -> V_59 = 0 ;
}
F_53 ( V_49 ) ;
}
static void F_55 ( struct V_49 * V_49 , unsigned long V_28 ,
unsigned long V_45 )
{
enum V_60 V_61 = F_56 ( V_49 ) ;
int V_62 = V_49 -> V_63 -> V_48 ;
unsigned long V_44 ;
for ( V_44 = V_28 ; V_44 < V_45 ; V_44 ++ )
F_57 ( F_58 ( V_44 ) , V_61 , V_62 , V_44 ) ;
}
static int T_3 F_59 ( struct V_49 * V_49 ,
unsigned long V_28 , unsigned long V_64 )
{
if ( ! F_45 ( V_49 ) )
return F_60 ( V_49 , V_28 , V_64 ) ;
return 0 ;
}
static int T_2 F_61 ( struct V_49 * V_65 , struct V_49 * V_66 ,
unsigned long V_28 , unsigned long V_45 )
{
int V_67 ;
unsigned long V_15 ;
unsigned long V_68 ;
V_67 = F_59 ( V_65 , V_28 , V_45 - V_28 ) ;
if ( V_67 )
return V_67 ;
F_62 ( V_65 -> V_63 , & V_15 ) ;
if ( V_45 > F_50 ( V_66 ) )
goto V_69;
if ( V_28 > V_66 -> V_58 )
goto V_69;
if ( V_45 <= V_66 -> V_58 )
goto V_69;
if ( ! F_51 ( V_65 ) )
V_68 = V_65 -> V_58 ;
else
V_68 = V_28 ;
F_54 ( V_65 , V_68 , V_45 ) ;
F_54 ( V_66 , V_45 , F_50 ( V_66 ) ) ;
F_63 ( V_65 -> V_63 , & V_15 ) ;
F_55 ( V_65 , V_28 , V_45 ) ;
return 0 ;
V_69:
F_63 ( V_65 -> V_63 , & V_15 ) ;
return - 1 ;
}
static int T_2 F_64 ( struct V_49 * V_65 , struct V_49 * V_66 ,
unsigned long V_28 , unsigned long V_45 )
{
int V_67 ;
unsigned long V_15 ;
unsigned long V_70 ;
V_67 = F_59 ( V_66 , V_28 , V_45 - V_28 ) ;
if ( V_67 )
return V_67 ;
F_62 ( V_65 -> V_63 , & V_15 ) ;
if ( V_65 -> V_58 > V_28 )
goto V_69;
if ( F_50 ( V_65 ) > V_45 )
goto V_69;
if ( V_28 >= F_50 ( V_65 ) )
goto V_69;
if ( ! F_51 ( V_66 ) )
V_70 = F_50 ( V_66 ) ;
else
V_70 = V_45 ;
F_54 ( V_65 , V_65 -> V_58 , V_28 ) ;
F_54 ( V_66 , V_28 , V_70 ) ;
F_63 ( V_65 -> V_63 , & V_15 ) ;
F_55 ( V_66 , V_28 , V_45 ) ;
return 0 ;
V_69:
F_63 ( V_65 -> V_63 , & V_15 ) ;
return - 1 ;
}
static void T_2 F_65 ( struct V_42 * V_43 , unsigned long V_28 ,
unsigned long V_45 )
{
unsigned long V_71 = F_46 ( V_43 ) ;
if ( ! V_43 -> V_72 || V_28 < V_43 -> V_56 )
V_43 -> V_56 = V_28 ;
V_43 -> V_72 = F_52 ( V_71 , V_45 ) -
V_43 -> V_56 ;
}
static int T_2 F_66 ( struct V_49 * V_49 , unsigned long V_73 )
{
struct V_42 * V_43 = V_49 -> V_63 ;
int V_46 = V_37 ;
int V_62 = V_43 -> V_48 ;
int V_60 ;
unsigned long V_15 , V_44 ;
int V_67 ;
V_60 = V_49 - V_43 -> V_51 ;
V_67 = F_59 ( V_49 , V_73 , V_46 ) ;
if ( V_67 )
return V_67 ;
F_62 ( V_49 -> V_63 , & V_15 ) ;
F_48 ( V_49 , V_73 , V_73 + V_46 ) ;
F_65 ( V_49 -> V_63 , V_73 ,
V_73 + V_46 ) ;
F_63 ( V_49 -> V_63 , & V_15 ) ;
F_67 ( V_46 , V_62 , V_60 ,
V_73 , V_74 ) ;
for ( V_44 = V_73 ; V_44 < V_73 + V_46 ; V_44 ++ ) {
if ( ! F_42 ( V_44 ) )
continue;
F_68 ( F_58 ( V_44 ) ) ;
}
return 0 ;
}
static int T_2 F_69 ( int V_62 , struct V_49 * V_49 ,
unsigned long V_73 )
{
int V_67 ;
if ( F_42 ( V_73 ) )
return - V_19 ;
V_67 = F_70 ( V_49 , V_73 ) ;
if ( V_67 < 0 )
return V_67 ;
V_67 = F_66 ( V_49 , V_73 ) ;
if ( V_67 < 0 )
return V_67 ;
return F_71 ( V_62 , F_72 ( V_73 ) ) ;
}
int T_3 F_73 ( int V_62 , struct V_49 * V_49 , unsigned long V_73 ,
unsigned long V_46 )
{
unsigned long V_32 ;
int V_75 = 0 ;
int V_76 , V_77 ;
struct V_78 * V_79 ;
V_76 = F_36 ( V_73 ) ;
V_77 = F_36 ( V_73 + V_46 - 1 ) ;
V_79 = F_74 ( ( unsigned long ) F_58 ( V_73 ) ) ;
if ( V_79 ) {
if ( V_79 -> V_80 != V_73
|| F_75 ( V_79 ) > V_46 ) {
F_76 ( L_3 ) ;
return - V_81 ;
}
V_79 -> V_82 = 0 ;
}
for ( V_32 = V_76 ; V_32 <= V_77 ; V_32 ++ ) {
V_75 = F_69 ( V_62 , V_49 , F_77 ( V_32 ) ) ;
if ( V_75 && ( V_75 != - V_19 ) )
break;
V_75 = 0 ;
}
F_78 () ;
return V_75 ;
}
static int F_79 ( int V_62 , struct V_49 * V_49 ,
unsigned long V_28 ,
unsigned long V_45 )
{
struct V_33 * V_34 ;
for (; V_28 < V_45 ; V_28 += V_37 ) {
V_34 = F_72 ( V_28 ) ;
if ( F_8 ( ! F_80 ( V_34 ) ) )
continue;
if ( F_8 ( F_47 ( V_28 ) != V_62 ) )
continue;
if ( V_49 && V_49 != F_81 ( F_58 ( V_28 ) ) )
continue;
return V_28 ;
}
return 0 ;
}
static int F_82 ( int V_62 , struct V_49 * V_49 ,
unsigned long V_28 ,
unsigned long V_45 )
{
struct V_33 * V_34 ;
unsigned long V_44 ;
V_44 = V_45 - 1 ;
for (; V_44 >= V_28 ; V_44 -= V_37 ) {
V_34 = F_72 ( V_44 ) ;
if ( F_8 ( ! F_80 ( V_34 ) ) )
continue;
if ( F_8 ( F_47 ( V_44 ) != V_62 ) )
continue;
if ( V_49 && V_49 != F_81 ( F_58 ( V_44 ) ) )
continue;
return V_44 ;
}
return 0 ;
}
static void F_83 ( struct V_49 * V_49 , unsigned long V_28 ,
unsigned long V_45 )
{
unsigned long V_58 = V_49 -> V_58 ;
unsigned long V_83 = F_50 ( V_49 ) ;
unsigned long F_50 = V_83 ;
unsigned long V_44 ;
struct V_33 * V_34 ;
int V_62 = F_84 ( V_49 ) ;
F_49 ( V_49 ) ;
if ( V_58 == V_28 ) {
V_44 = F_79 ( V_62 , V_49 , V_45 ,
F_50 ) ;
if ( V_44 ) {
V_49 -> V_58 = V_44 ;
V_49 -> V_59 = F_50 - V_44 ;
}
} else if ( F_50 == V_45 ) {
V_44 = F_82 ( V_62 , V_49 , V_58 ,
V_28 ) ;
if ( V_44 )
V_49 -> V_59 = V_44 - V_58 + 1 ;
}
V_44 = V_58 ;
for (; V_44 < F_50 ; V_44 += V_37 ) {
V_34 = F_72 ( V_44 ) ;
if ( F_8 ( ! F_80 ( V_34 ) ) )
continue;
if ( F_81 ( F_58 ( V_44 ) ) != V_49 )
continue;
if ( V_28 == V_44 )
continue;
F_53 ( V_49 ) ;
return;
}
V_49 -> V_58 = 0 ;
V_49 -> V_59 = 0 ;
F_53 ( V_49 ) ;
}
static void F_85 ( struct V_42 * V_43 ,
unsigned long V_28 , unsigned long V_45 )
{
unsigned long V_84 = V_43 -> V_56 ;
unsigned long V_85 = F_46 ( V_43 ) ;
unsigned long F_46 = V_85 ;
unsigned long V_44 ;
struct V_33 * V_34 ;
int V_62 = V_43 -> V_48 ;
if ( V_84 == V_28 ) {
V_44 = F_79 ( V_62 , NULL , V_45 ,
F_46 ) ;
if ( V_44 ) {
V_43 -> V_56 = V_44 ;
V_43 -> V_72 = F_46 - V_44 ;
}
} else if ( F_46 == V_45 ) {
V_44 = F_82 ( V_62 , NULL , V_84 ,
V_28 ) ;
if ( V_44 )
V_43 -> V_72 = V_44 - V_84 + 1 ;
}
V_44 = V_84 ;
for (; V_44 < F_46 ; V_44 += V_37 ) {
V_34 = F_72 ( V_44 ) ;
if ( F_8 ( ! F_80 ( V_34 ) ) )
continue;
if ( F_47 ( V_44 ) != V_62 )
continue;
if ( V_28 == V_44 )
continue;
return;
}
V_43 -> V_56 = 0 ;
V_43 -> V_72 = 0 ;
}
static void F_86 ( struct V_49 * V_49 , unsigned long V_28 )
{
struct V_42 * V_43 = V_49 -> V_63 ;
int V_46 = V_37 ;
int V_60 ;
unsigned long V_15 ;
V_60 = V_49 - V_43 -> V_51 ;
F_62 ( V_49 -> V_63 , & V_15 ) ;
F_83 ( V_49 , V_28 , V_28 + V_46 ) ;
F_85 ( V_43 , V_28 , V_28 + V_46 ) ;
F_63 ( V_49 -> V_63 , & V_15 ) ;
}
static int F_87 ( struct V_49 * V_49 , struct V_33 * V_34 ,
unsigned long V_86 )
{
unsigned long V_28 ;
int V_87 ;
int V_67 = - V_81 ;
if ( ! F_80 ( V_34 ) )
return V_67 ;
V_67 = F_88 ( V_34 ) ;
if ( V_67 )
return V_67 ;
V_87 = F_89 ( V_34 ) ;
V_28 = F_77 ( V_87 ) ;
F_86 ( V_49 , V_28 ) ;
F_90 ( V_49 , V_34 , V_86 ) ;
return 0 ;
}
int F_91 ( struct V_49 * V_49 , unsigned long V_73 ,
unsigned long V_46 )
{
unsigned long V_32 ;
unsigned long V_86 = 0 ;
int V_88 , V_67 = 0 ;
if ( F_92 ( V_49 ) ) {
struct V_21 * V_21 = F_58 ( V_73 ) ;
struct V_78 * V_79 ;
V_79 = F_74 ( ( unsigned long ) V_21 ) ;
if ( V_79 )
V_86 = F_75 ( V_79 ) ;
} else {
T_4 V_8 , V_9 ;
V_8 = V_73 << V_38 ;
V_9 = V_46 * V_89 ;
V_67 = F_93 ( & V_18 , V_8 ,
V_9 ) ;
if ( V_67 ) {
T_4 V_90 = V_8 + V_9 - 1 ;
F_94 ( L_4 ,
& V_8 , & V_90 , V_67 ) ;
}
}
F_30 ( V_73 & ~ V_91 ) ;
F_30 ( V_46 % V_37 ) ;
V_88 = V_46 / V_37 ;
for ( V_32 = 0 ; V_32 < V_88 ; V_32 ++ ) {
unsigned long V_44 = V_73 + V_32 * V_37 ;
V_67 = F_87 ( V_49 , F_72 ( V_44 ) , V_86 ) ;
V_86 = 0 ;
if ( V_67 )
break;
}
return V_67 ;
}
int F_95 ( T_5 V_92 )
{
int V_93 = - V_81 ;
F_1 () ;
F_4 ( & V_94 ) ;
if ( V_95 == V_96 ) {
V_95 = V_92 ;
V_93 = 0 ;
}
F_5 ( & V_94 ) ;
F_6 () ;
return V_93 ;
}
int F_96 ( T_5 V_92 )
{
int V_93 = - V_81 ;
F_1 () ;
F_4 ( & V_94 ) ;
if ( V_95 == V_92 ) {
V_95 = V_96 ;
V_93 = 0 ;
}
F_5 ( & V_94 ) ;
F_6 () ;
return V_93 ;
}
void F_97 ( struct V_21 * V_21 )
{
}
void F_98 ( struct V_21 * V_21 )
{
F_99 ( V_21 , 1 ) ;
}
void F_100 ( struct V_21 * V_21 )
{
F_101 ( V_21 ) ;
}
static void V_96 ( struct V_21 * V_21 )
{
F_97 ( V_21 ) ;
F_98 ( V_21 ) ;
F_100 ( V_21 ) ;
}
static int F_102 ( unsigned long V_28 , unsigned long V_46 ,
void * V_97 )
{
unsigned long V_32 ;
unsigned long V_98 = * ( unsigned long * ) V_97 ;
struct V_21 * V_21 ;
if ( F_103 ( F_58 ( V_28 ) ) )
for ( V_32 = 0 ; V_32 < V_46 ; V_32 ++ ) {
V_21 = F_58 ( V_28 + V_32 ) ;
(* V_95)( V_21 ) ;
V_98 ++ ;
}
* ( unsigned long * ) V_97 = V_98 ;
return 0 ;
}
static bool F_104 ( struct V_49 * V_49 )
{
return true ;
}
static bool F_104 ( struct V_49 * V_49 )
{
return F_105 ( F_84 ( V_49 ) , V_99 ) ;
}
static void F_106 ( unsigned long V_46 ,
struct V_49 * V_49 , struct V_100 * V_97 )
{
int V_62 = F_84 ( V_49 ) ;
enum V_60 V_101 = V_102 ;
if ( V_103 == V_99 )
V_101 = V_104 ;
if ( F_56 ( V_49 ) <= V_101 && ! F_105 ( V_62 , V_99 ) )
V_97 -> V_105 = V_62 ;
else
V_97 -> V_105 = - 1 ;
#ifdef F_107
V_101 = V_106 ;
if ( V_103 == V_107 )
V_101 = V_104 ;
if ( F_56 ( V_49 ) <= V_101 && ! F_105 ( V_62 , V_107 ) )
V_97 -> V_108 = V_62 ;
else
V_97 -> V_108 = - 1 ;
#else
V_97 -> V_108 = V_97 -> V_105 ;
#endif
if ( ! F_105 ( V_62 , V_103 ) )
V_97 -> V_109 = V_62 ;
else
V_97 -> V_109 = - 1 ;
}
static void F_108 ( int V_47 , struct V_100 * V_97 )
{
if ( V_97 -> V_105 >= 0 )
F_109 ( V_47 , V_99 ) ;
if ( V_97 -> V_108 >= 0 )
F_109 ( V_47 , V_107 ) ;
F_109 ( V_47 , V_103 ) ;
}
int T_3 F_110 ( unsigned long V_44 , unsigned long V_46 , int V_110 )
{
unsigned long V_15 ;
unsigned long V_98 = 0 ;
struct V_49 * V_49 ;
int V_111 = 0 ;
int V_62 ;
int V_67 ;
struct V_100 V_97 ;
V_49 = F_81 ( F_58 ( V_44 ) ) ;
if ( ( F_56 ( V_49 ) > V_102 ||
V_110 == V_112 ) &&
! F_104 ( V_49 ) )
return - V_81 ;
if ( V_110 == V_113 &&
F_56 ( V_49 ) == V_104 ) {
if ( F_61 ( V_49 - 1 , V_49 , V_44 , V_44 + V_46 ) )
return - V_81 ;
}
if ( V_110 == V_112 &&
F_56 ( V_49 ) == V_104 - 1 ) {
if ( F_64 ( V_49 , V_49 + 1 , V_44 , V_44 + V_46 ) )
return - V_81 ;
}
V_49 = F_81 ( F_58 ( V_44 ) ) ;
V_97 . V_28 = V_44 ;
V_97 . V_46 = V_46 ;
F_106 ( V_46 , V_49 , & V_97 ) ;
V_62 = F_47 ( V_44 ) ;
V_67 = V_100 ( V_114 , & V_97 ) ;
V_67 = F_111 ( V_67 ) ;
if ( V_67 ) {
V_100 ( V_115 , & V_97 ) ;
return V_67 ;
}
F_4 ( & V_116 ) ;
if ( ! F_112 ( V_49 ) ) {
V_111 = 1 ;
F_113 ( NULL , V_49 ) ;
}
V_67 = F_114 ( V_44 , V_46 , & V_98 ,
F_102 ) ;
if ( V_67 ) {
if ( V_111 )
F_115 ( V_49 ) ;
F_5 ( & V_116 ) ;
F_116 ( V_117 L_5 ,
( unsigned long long ) V_44 << V_38 ,
( ( ( unsigned long long ) V_44 + V_46 )
<< V_38 ) - 1 ) ;
V_100 ( V_115 , & V_97 ) ;
return V_67 ;
}
V_49 -> V_118 += V_98 ;
F_62 ( V_49 -> V_63 , & V_15 ) ;
V_49 -> V_63 -> V_119 += V_98 ;
F_63 ( V_49 -> V_63 , & V_15 ) ;
if ( V_98 ) {
F_108 ( F_84 ( V_49 ) , & V_97 ) ;
if ( V_111 )
F_113 ( NULL , NULL ) ;
else
F_117 ( V_49 ) ;
}
F_5 ( & V_116 ) ;
F_118 () ;
if ( V_98 )
F_119 ( F_84 ( V_49 ) ) ;
V_120 = F_120 () ;
F_121 () ;
if ( V_98 )
V_100 ( V_121 , & V_97 ) ;
return 0 ;
}
static void F_122 ( T_6 * V_43 )
{
struct V_49 * V_83 ;
for ( V_83 = V_43 -> V_51 ; V_83 < V_43 -> V_51 + V_52 ; V_83 ++ )
V_83 -> V_118 = 0 ;
V_43 -> V_119 = 0 ;
}
static T_6 T_3 * F_123 ( int V_62 , T_1 V_8 )
{
struct V_42 * V_43 ;
unsigned long V_122 [ V_52 ] = { 0 } ;
unsigned long V_123 [ V_52 ] = { 0 } ;
unsigned long V_28 = F_124 ( V_8 ) ;
V_43 = F_125 ( V_62 ) ;
if ( ! V_43 ) {
V_43 = F_126 ( V_62 ) ;
if ( ! V_43 )
return NULL ;
F_127 ( V_62 , V_43 ) ;
} else {
V_43 -> V_124 = 0 ;
V_43 -> V_125 = 0 ;
}
F_128 ( V_62 , V_122 , V_28 , V_123 ) ;
F_4 ( & V_116 ) ;
F_113 ( V_43 , NULL ) ;
F_5 ( & V_116 ) ;
F_129 ( V_43 ) ;
F_122 ( V_43 ) ;
return V_43 ;
}
static void F_130 ( int V_62 , T_6 * V_43 )
{
F_127 ( V_62 , NULL ) ;
F_131 ( V_43 ) ;
return;
}
int F_132 ( int V_62 )
{
T_6 * V_43 ;
int V_67 ;
if ( F_133 ( V_62 ) )
return 0 ;
F_11 () ;
V_43 = F_123 ( V_62 , 0 ) ;
if ( ! V_43 ) {
F_134 ( L_6 , V_62 ) ;
V_67 = - V_12 ;
goto V_126;
}
F_135 ( V_62 ) ;
V_67 = F_136 ( V_62 ) ;
F_30 ( V_67 ) ;
if ( V_43 -> V_127 -> V_128 -> V_49 == NULL ) {
F_4 ( & V_116 ) ;
F_113 ( NULL , NULL ) ;
F_5 ( & V_116 ) ;
}
V_126:
F_16 () ;
return V_67 ;
}
static int F_137 ( T_1 V_8 , T_1 V_9 )
{
T_1 V_28 = F_124 ( V_8 ) ;
T_1 V_46 = V_9 >> V_38 ;
if ( ( V_28 & ~ V_91 ) ||
( V_46 % V_37 ) || ( ! V_46 ) ) {
F_134 ( L_7 ,
( unsigned long long ) V_8 ,
( unsigned long long ) V_9 ) ;
return - V_81 ;
}
return 0 ;
}
static int F_138 ( int V_62 , T_1 V_8 , T_1 V_9 )
{
unsigned long V_28 = V_8 >> V_38 ;
T_6 * V_43 = F_125 ( V_62 ) ;
struct V_49 * V_129 = V_43 -> V_51 + V_104 ;
if ( F_51 ( V_129 ) )
return 0 ;
if ( V_129 -> V_58 <= V_28 )
return 1 ;
return 0 ;
}
int F_139 ( int V_62 , T_1 V_8 , T_1 V_9 , int V_130 ,
bool V_131 )
{
#ifdef F_140
if ( V_131 )
return V_132 ;
#endif
if ( F_138 ( V_62 , V_8 , V_9 ) )
return V_104 ;
return V_130 ;
}
int T_3 F_141 ( int V_62 , struct V_7 * V_10 )
{
T_1 V_8 , V_9 ;
T_6 * V_43 = NULL ;
bool V_133 ;
bool V_134 ;
int V_67 ;
V_8 = V_10 -> V_8 ;
V_9 = F_142 ( V_10 ) ;
V_67 = F_137 ( V_8 , V_9 ) ;
if ( V_67 )
return V_67 ;
{
void * V_85 = F_125 ( V_62 ) ;
V_133 = ! V_85 ;
}
F_11 () ;
F_143 ( V_8 , V_9 , V_62 ) ;
V_134 = ! F_133 ( V_62 ) ;
if ( V_134 ) {
V_43 = F_123 ( V_62 , V_8 ) ;
V_67 = - V_12 ;
if ( ! V_43 )
goto error;
}
V_67 = F_144 ( V_62 , V_8 , V_9 , false ) ;
if ( V_67 < 0 )
goto error;
F_135 ( V_62 ) ;
if ( V_134 ) {
V_67 = F_136 ( V_62 ) ;
F_30 ( V_67 ) ;
}
F_145 ( V_8 , V_8 + V_9 , L_1 ) ;
goto V_126;
error:
if ( V_133 )
F_130 ( V_62 , V_43 ) ;
F_146 ( V_8 , V_9 ) ;
V_126:
F_16 () ;
return V_67 ;
}
int T_3 F_147 ( int V_62 , T_1 V_8 , T_1 V_9 )
{
struct V_7 * V_10 ;
int V_67 ;
V_10 = F_17 ( V_8 , V_9 ) ;
if ( F_148 ( V_10 ) )
return F_149 ( V_10 ) ;
V_67 = F_141 ( V_62 , V_10 ) ;
if ( V_67 < 0 )
F_23 ( V_10 ) ;
return V_67 ;
}
static inline int F_150 ( struct V_21 * V_21 )
{
return F_151 ( V_21 ) && F_152 ( V_21 ) >= V_135 ;
}
static struct V_21 * F_153 ( struct V_21 * V_21 )
{
F_30 ( F_154 ( V_21 ) & ( V_136 - 1 ) ) ;
if ( F_150 ( V_21 ) ) {
int V_137 ;
V_137 = F_152 ( V_21 ) ;
if ( ( V_137 < V_138 ) && ( V_137 >= V_135 ) )
return V_21 + ( 1 << V_137 ) ;
}
return V_21 + V_136 ;
}
int F_155 ( unsigned long V_28 , unsigned long V_46 )
{
struct V_21 * V_21 = F_58 ( V_28 ) ;
struct V_21 * V_139 = V_21 + V_46 ;
for (; V_21 < V_139 ; V_21 = F_153 ( V_21 ) ) {
if ( ! F_156 ( V_21 ) )
return 0 ;
F_157 () ;
}
return 1 ;
}
int F_158 ( unsigned long V_28 , unsigned long V_45 )
{
unsigned long V_44 , V_140 ;
struct V_49 * V_49 = NULL ;
struct V_21 * V_21 ;
int V_32 ;
for ( V_44 = V_28 , V_140 = F_159 ( V_28 ) ;
V_44 < V_45 ;
V_44 = V_140 + 1 , V_140 += V_37 ) {
if ( ! F_160 ( F_36 ( V_44 ) ) )
continue;
for (; V_44 < V_140 && V_44 < V_45 ;
V_44 += V_141 ) {
V_32 = 0 ;
while ( ( V_32 < V_141 ) &&
! F_161 ( V_44 + V_32 ) )
V_32 ++ ;
if ( V_32 == V_141 )
continue;
V_21 = F_58 ( V_44 + V_32 ) ;
if ( V_49 && F_81 ( V_21 ) != V_49 )
return 0 ;
V_49 = F_81 ( V_21 ) ;
}
}
return 1 ;
}
static unsigned long F_162 ( unsigned long V_8 , unsigned long V_14 )
{
unsigned long V_44 ;
struct V_21 * V_21 ;
for ( V_44 = V_8 ; V_44 < V_14 ; V_44 ++ ) {
if ( F_42 ( V_44 ) ) {
V_21 = F_58 ( V_44 ) ;
if ( F_163 ( V_21 ) )
return V_44 ;
if ( F_164 ( V_21 ) ) {
if ( F_165 ( V_21 ) )
return V_44 ;
else
V_44 = F_166 ( V_44 + 1 ,
1 << F_167 ( V_21 ) ) - 1 ;
}
}
}
return 0 ;
}
static int
F_168 ( unsigned long V_28 , unsigned long V_45 )
{
unsigned long V_44 ;
struct V_21 * V_21 ;
int V_142 = V_143 ;
int V_144 = 0 ;
int V_67 = 0 ;
F_169 ( V_145 ) ;
for ( V_44 = V_28 ; V_44 < V_45 && V_142 > 0 ; V_44 ++ ) {
if ( ! F_42 ( V_44 ) )
continue;
V_21 = F_58 ( V_44 ) ;
if ( F_164 ( V_21 ) ) {
struct V_21 * V_146 = F_170 ( V_21 ) ;
V_44 = F_154 ( V_146 ) + ( 1 << F_167 ( V_146 ) ) - 1 ;
if ( F_167 ( V_146 ) > V_147 ) {
V_67 = - V_148 ;
break;
}
if ( F_171 ( V_21 , & V_145 ) )
V_142 -= 1 << F_167 ( V_146 ) ;
continue;
}
if ( ! F_172 ( V_21 ) )
continue;
V_67 = F_173 ( V_21 ) ;
if ( ! V_67 ) {
F_174 ( V_21 ) ;
F_175 ( & V_21 -> V_22 , & V_145 ) ;
V_142 -- ;
F_176 ( V_21 , V_149 +
F_177 ( V_21 ) ) ;
} else {
#ifdef F_178
F_116 ( V_150 L_8 ,
V_44 ) ;
F_179 ( V_21 , L_9 ) ;
#endif
F_174 ( V_21 ) ;
if ( F_180 ( V_21 ) ) {
V_144 ++ ;
V_67 = - V_148 ;
break;
}
}
}
if ( ! F_181 ( & V_145 ) ) {
if ( V_144 ) {
F_182 ( & V_145 ) ;
goto V_126;
}
V_67 = F_183 ( & V_145 , V_151 , NULL , 0 ,
V_152 , V_153 ) ;
if ( V_67 )
F_182 ( & V_145 ) ;
}
V_126:
return V_67 ;
}
static int
F_184 ( unsigned long V_8 , unsigned long V_46 ,
void * V_154 )
{
F_185 ( V_8 , V_8 + V_46 ) ;
return 0 ;
}
static void
F_186 ( unsigned long V_28 , unsigned long V_45 )
{
F_114 ( V_28 , V_45 - V_28 , NULL ,
F_184 ) ;
}
static int
F_187 ( unsigned long V_28 , unsigned long V_46 ,
void * V_154 )
{
int V_67 ;
long V_155 = * ( long * ) V_154 ;
V_67 = F_188 ( V_28 , V_28 + V_46 , true ) ;
V_155 = V_46 ;
if ( ! V_67 )
* ( long * ) V_154 += V_155 ;
return V_67 ;
}
static long
F_189 ( unsigned long V_28 , unsigned long V_45 )
{
long V_155 = 0 ;
int V_67 ;
V_67 = F_114 ( V_28 , V_45 - V_28 , & V_155 ,
F_187 ) ;
if ( V_67 < 0 )
V_155 = ( long ) V_67 ;
return V_155 ;
}
static bool F_190 ( struct V_49 * V_49 , unsigned long V_46 )
{
return true ;
}
static bool F_190 ( struct V_49 * V_49 , unsigned long V_46 )
{
struct V_42 * V_43 = V_49 -> V_63 ;
unsigned long V_118 = 0 ;
enum V_60 V_156 ;
for ( V_156 = 0 ; V_156 <= V_102 ; V_156 ++ )
V_118 += V_43 -> V_51 [ V_156 ] . V_118 ;
if ( V_118 > V_46 )
return true ;
V_118 = 0 ;
for (; V_156 <= V_104 ; V_156 ++ )
V_118 += V_43 -> V_51 [ V_156 ] . V_118 ;
return V_118 == 0 ;
}
static int T_7 F_191 ( char * V_85 )
{
#ifdef F_192
F_193 ( true ) ;
V_157 = true ;
#else
F_94 ( L_10 ) ;
#endif
return 0 ;
}
static void F_194 ( unsigned long V_46 ,
struct V_49 * V_49 , struct V_100 * V_97 )
{
struct V_42 * V_43 = V_49 -> V_63 ;
unsigned long V_118 = 0 ;
enum V_60 V_156 , V_101 = V_102 ;
if ( V_103 == V_99 )
V_101 = V_104 ;
for ( V_156 = 0 ; V_156 <= V_101 ; V_156 ++ )
V_118 += V_43 -> V_51 [ V_156 ] . V_118 ;
if ( F_56 ( V_49 ) <= V_101 && V_46 >= V_118 )
V_97 -> V_105 = F_84 ( V_49 ) ;
else
V_97 -> V_105 = - 1 ;
#ifdef F_107
V_101 = V_106 ;
if ( V_103 == V_107 )
V_101 = V_104 ;
for (; V_156 <= V_101 ; V_156 ++ )
V_118 += V_43 -> V_51 [ V_156 ] . V_118 ;
if ( F_56 ( V_49 ) <= V_101 && V_46 >= V_118 )
V_97 -> V_108 = F_84 ( V_49 ) ;
else
V_97 -> V_108 = - 1 ;
#else
V_97 -> V_108 = V_97 -> V_105 ;
#endif
V_101 = V_104 ;
for (; V_156 <= V_101 ; V_156 ++ )
V_118 += V_43 -> V_51 [ V_156 ] . V_118 ;
if ( V_46 >= V_118 )
V_97 -> V_109 = F_84 ( V_49 ) ;
else
V_97 -> V_109 = - 1 ;
}
static void F_195 ( int V_47 , struct V_100 * V_97 )
{
if ( V_97 -> V_105 >= 0 )
F_196 ( V_47 , V_99 ) ;
if ( ( V_103 != V_99 ) &&
( V_97 -> V_108 >= 0 ) )
F_196 ( V_47 , V_107 ) ;
if ( ( V_103 != V_107 ) &&
( V_97 -> V_109 >= 0 ) )
F_196 ( V_47 , V_103 ) ;
}
static int T_3 F_197 ( unsigned long V_28 ,
unsigned long V_45 , unsigned long V_158 )
{
unsigned long V_44 , V_46 , V_159 ;
long V_160 ;
int V_67 , V_161 , V_162 , V_47 ;
unsigned long V_15 ;
struct V_49 * V_49 ;
struct V_100 V_97 ;
if ( ! F_198 ( V_28 , V_136 ) )
return - V_81 ;
if ( ! F_198 ( V_45 , V_136 ) )
return - V_81 ;
if ( ! F_158 ( V_28 , V_45 ) )
return - V_81 ;
V_49 = F_81 ( F_58 ( V_28 ) ) ;
V_47 = F_84 ( V_49 ) ;
V_46 = V_45 - V_28 ;
if ( F_56 ( V_49 ) <= V_102 && ! F_190 ( V_49 , V_46 ) )
return - V_81 ;
V_67 = F_199 ( V_28 , V_45 ,
V_163 , true ) ;
if ( V_67 )
return V_67 ;
V_97 . V_28 = V_28 ;
V_97 . V_46 = V_46 ;
F_194 ( V_46 , V_49 , & V_97 ) ;
V_67 = V_100 ( V_164 , & V_97 ) ;
V_67 = F_111 ( V_67 ) ;
if ( V_67 )
goto V_165;
V_44 = V_28 ;
V_159 = V_166 + V_158 ;
V_161 = 0 ;
V_162 = 5 ;
V_167:
V_67 = - V_168 ;
if ( F_200 ( V_166 , V_159 ) )
goto V_165;
V_67 = - V_169 ;
if ( F_201 ( V_3 ) )
goto V_165;
V_67 = 0 ;
if ( V_161 ) {
F_202 () ;
F_157 () ;
F_203 ( V_49 ) ;
}
V_44 = F_162 ( V_28 , V_45 ) ;
if ( V_44 ) {
V_67 = F_168 ( V_44 , V_45 ) ;
if ( ! V_67 ) {
V_161 = 1 ;
goto V_167;
} else {
if ( V_67 < 0 )
if ( -- V_162 == 0 )
goto V_165;
F_204 () ;
V_161 = 1 ;
goto V_167;
}
}
F_202 () ;
F_204 () ;
F_203 ( V_49 ) ;
F_205 ( V_28 , V_45 ) ;
V_160 = F_189 ( V_28 , V_45 ) ;
if ( V_160 < 0 ) {
V_67 = - V_148 ;
goto V_165;
}
F_116 ( V_170 L_11 , V_160 ) ;
F_186 ( V_28 , V_45 ) ;
F_206 ( V_28 , V_45 , V_163 ) ;
F_99 ( F_58 ( V_28 ) , - V_160 ) ;
V_49 -> V_118 -= V_160 ;
F_62 ( V_49 -> V_63 , & V_15 ) ;
V_49 -> V_63 -> V_119 -= V_160 ;
F_63 ( V_49 -> V_63 , & V_15 ) ;
F_118 () ;
if ( ! F_112 ( V_49 ) ) {
F_115 ( V_49 ) ;
F_4 ( & V_116 ) ;
F_113 ( NULL , NULL ) ;
F_5 ( & V_116 ) ;
} else
F_117 ( V_49 ) ;
F_195 ( V_47 , & V_97 ) ;
if ( V_97 . V_109 >= 0 )
F_207 ( V_47 ) ;
V_120 = F_120 () ;
F_121 () ;
V_100 ( V_171 , & V_97 ) ;
return 0 ;
V_165:
F_116 ( V_170 L_12 ,
( unsigned long long ) V_28 << V_38 ,
( ( unsigned long long ) V_45 << V_38 ) - 1 ) ;
V_100 ( V_172 , & V_97 ) ;
F_206 ( V_28 , V_45 , V_163 ) ;
return V_67 ;
}
int F_208 ( unsigned long V_28 , unsigned long V_46 )
{
return F_197 ( V_28 , V_28 + V_46 , 120 * V_173 ) ;
}
int F_209 ( unsigned long V_28 , unsigned long V_45 ,
void * V_97 , int (* F_210)( struct V_174 * , void * ) )
{
struct V_174 * V_175 = NULL ;
struct V_33 * V_176 ;
unsigned long V_44 , V_31 ;
int V_67 ;
for ( V_44 = V_28 ; V_44 < V_45 ; V_44 += V_37 ) {
V_31 = F_36 ( V_44 ) ;
if ( ! F_160 ( V_31 ) )
continue;
V_176 = F_37 ( V_31 ) ;
if ( V_175 )
if ( ( V_31 >= V_175 -> V_177 ) &&
( V_31 <= V_175 -> V_178 ) )
continue;
V_175 = F_211 ( V_176 , V_175 ) ;
if ( ! V_175 )
continue;
V_67 = F_210 ( V_175 , V_97 ) ;
if ( V_67 ) {
F_212 ( & V_175 -> V_179 . V_180 ) ;
return V_67 ;
}
}
if ( V_175 )
F_212 ( & V_175 -> V_179 . V_180 ) ;
return 0 ;
}
static int F_213 ( struct V_174 * V_175 , void * V_97 )
{
int V_67 = ! F_214 ( V_175 ) ;
if ( F_8 ( V_67 ) ) {
T_8 V_181 , V_182 ;
V_181 = F_215 ( F_77 ( V_175 -> V_177 ) ) ;
V_182 = F_215 ( F_77 ( V_175 -> V_178 + 1 ) ) - 1 ;
F_94 ( L_13
L_14 ,
& V_181 , & V_182 ) ;
}
return V_67 ;
}
static int F_216 ( T_6 * V_43 )
{
int V_183 ;
F_217 (cpu) {
if ( F_218 ( V_183 ) == V_43 -> V_48 )
return - V_148 ;
}
return 0 ;
}
static void F_219 ( T_6 * V_43 )
{
#ifdef F_220
int V_183 ;
F_221 (cpu)
if ( F_218 ( V_183 ) == V_43 -> V_48 )
F_222 ( V_183 ) ;
#endif
}
static int F_223 ( T_6 * V_43 )
{
int V_67 ;
V_67 = F_216 ( V_43 ) ;
if ( V_67 )
return V_67 ;
F_219 ( V_43 ) ;
return 0 ;
}
void F_224 ( int V_62 )
{
T_6 * V_43 = F_125 ( V_62 ) ;
unsigned long V_28 = V_43 -> V_56 ;
unsigned long V_45 = V_28 + V_43 -> V_72 ;
unsigned long V_44 ;
int V_32 ;
for ( V_44 = V_28 ; V_44 < V_45 ; V_44 += V_37 ) {
unsigned long V_31 = F_36 ( V_44 ) ;
if ( ! F_160 ( V_31 ) )
continue;
if ( F_47 ( V_44 ) != V_62 )
continue;
return;
}
if ( F_223 ( V_43 ) )
return;
F_225 ( V_62 ) ;
F_226 ( V_62 ) ;
for ( V_32 = 0 ; V_32 < V_52 ; V_32 ++ ) {
struct V_49 * V_49 = V_43 -> V_51 + V_32 ;
if ( F_227 ( V_49 -> V_55 ) ) {
F_228 ( V_49 -> V_55 ) ;
V_49 -> V_55 = NULL ;
}
}
}
void T_3 F_229 ( int V_62 , T_1 V_8 , T_1 V_9 )
{
int V_67 ;
F_30 ( F_137 ( V_8 , V_9 ) ) ;
F_11 () ;
V_67 = F_209 ( F_124 ( V_8 ) , F_230 ( V_8 + V_9 - 1 ) , NULL ,
F_213 ) ;
if ( V_67 )
F_231 () ;
F_232 ( V_8 , V_8 + V_9 , L_1 ) ;
F_233 ( V_8 , V_9 ) ;
F_146 ( V_8 , V_9 ) ;
F_234 ( V_8 , V_9 ) ;
F_224 ( V_62 ) ;
F_16 () ;
}
