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
F_28 ( V_21 ) ;
}
void F_29 ( struct V_21 * V_21 )
{
unsigned long type ;
type = ( unsigned long ) V_21 -> V_22 . V_23 ;
F_30 ( type < V_25 ||
type > V_26 ) ;
if ( F_31 ( V_21 ) == 1 ) {
F_32 ( V_21 ) ;
F_27 ( V_21 , 0 ) ;
F_33 ( & V_21 -> V_22 ) ;
F_34 ( V_21 ) ;
}
}
static void F_35 ( unsigned long V_27 )
{
unsigned long * V_28 , V_29 , V_30 , V_31 ;
struct V_32 * V_33 ;
struct V_21 * V_21 , * V_34 ;
V_30 = F_36 ( V_27 ) ;
V_33 = F_37 ( V_30 ) ;
V_34 = F_38 ( V_33 -> V_35 , V_30 ) ;
V_21 = F_39 ( V_34 ) ;
V_29 = sizeof( struct V_21 ) * V_36 ;
V_29 = F_40 ( V_29 ) >> V_37 ;
for ( V_31 = 0 ; V_31 < V_29 ; V_31 ++ , V_21 ++ )
F_25 ( V_30 , V_21 , V_38 ) ;
V_28 = F_37 ( V_30 ) -> V_39 ;
V_21 = F_39 ( V_28 ) ;
V_29 = F_40 ( F_41 () ) >> V_37 ;
for ( V_31 = 0 ; V_31 < V_29 ; V_31 ++ , V_21 ++ )
F_25 ( V_30 , V_21 , V_40 ) ;
}
static void F_35 ( unsigned long V_27 )
{
unsigned long * V_28 , V_29 , V_30 , V_31 ;
struct V_32 * V_33 ;
struct V_21 * V_21 , * V_34 ;
if ( ! F_42 ( V_27 ) )
return;
V_30 = F_36 ( V_27 ) ;
V_33 = F_37 ( V_30 ) ;
V_34 = F_38 ( V_33 -> V_35 , V_30 ) ;
F_43 ( V_30 , V_34 , V_36 ) ;
V_28 = F_37 ( V_30 ) -> V_39 ;
V_21 = F_39 ( V_28 ) ;
V_29 = F_40 ( F_41 () ) >> V_37 ;
for ( V_31 = 0 ; V_31 < V_29 ; V_31 ++ , V_21 ++ )
F_25 ( V_30 , V_21 , V_40 ) ;
}
void F_44 ( struct V_41 * V_42 )
{
unsigned long V_31 , V_43 , V_44 , V_45 ;
int V_46 = V_42 -> V_47 ;
struct V_21 * V_21 ;
struct V_48 * V_48 ;
V_45 = F_40 ( sizeof( struct V_41 ) ) >> V_37 ;
V_21 = F_39 ( V_42 ) ;
for ( V_31 = 0 ; V_31 < V_45 ; V_31 ++ , V_21 ++ )
F_25 ( V_46 , V_21 , V_49 ) ;
V_48 = & V_42 -> V_50 [ 0 ] ;
for (; V_48 < V_42 -> V_50 + V_51 - 1 ; V_48 ++ ) {
if ( F_45 ( V_48 ) ) {
V_45 = V_48 -> V_52
* sizeof( V_53 ) ;
V_45 = F_40 ( V_45 ) >> V_37 ;
V_21 = F_39 ( V_48 -> V_54 ) ;
for ( V_31 = 0 ; V_31 < V_45 ; V_31 ++ , V_21 ++ )
F_25 ( V_46 , V_21 , V_49 ) ;
}
}
V_43 = V_42 -> V_55 ;
V_44 = F_46 ( V_42 ) ;
for (; V_43 < V_44 ; V_43 += V_36 ) {
if ( F_42 ( V_43 ) && ( F_47 ( V_43 ) == V_46 ) )
F_35 ( V_43 ) ;
}
}
static void T_2 F_48 ( struct V_48 * V_48 , unsigned long V_27 ,
unsigned long V_44 )
{
unsigned long V_56 ;
F_49 ( V_48 ) ;
V_56 = F_50 ( V_48 ) ;
if ( F_51 ( V_48 ) || V_27 < V_48 -> V_57 )
V_48 -> V_57 = V_27 ;
V_48 -> V_58 = F_52 ( V_56 , V_44 ) -
V_48 -> V_57 ;
F_53 ( V_48 ) ;
}
static void F_54 ( struct V_48 * V_48 , unsigned long V_27 ,
unsigned long V_44 )
{
F_49 ( V_48 ) ;
if ( V_44 - V_27 ) {
V_48 -> V_57 = V_27 ;
V_48 -> V_58 = V_44 - V_27 ;
} else {
V_48 -> V_57 = 0 ;
V_48 -> V_58 = 0 ;
}
F_53 ( V_48 ) ;
}
static void F_55 ( struct V_48 * V_48 , unsigned long V_27 ,
unsigned long V_44 )
{
enum V_59 V_60 = F_56 ( V_48 ) ;
int V_61 = V_48 -> V_62 -> V_47 ;
unsigned long V_43 ;
for ( V_43 = V_27 ; V_43 < V_44 ; V_43 ++ )
F_57 ( F_58 ( V_43 ) , V_60 , V_61 , V_43 ) ;
}
static int T_3 F_59 ( struct V_48 * V_48 ,
unsigned long V_27 , unsigned long V_63 )
{
if ( ! F_45 ( V_48 ) )
return F_60 ( V_48 , V_27 , V_63 ) ;
return 0 ;
}
static int T_2 F_61 ( struct V_48 * V_64 , struct V_48 * V_65 ,
unsigned long V_27 , unsigned long V_44 )
{
int V_66 ;
unsigned long V_15 ;
unsigned long V_67 ;
V_66 = F_59 ( V_64 , V_27 , V_44 - V_27 ) ;
if ( V_66 )
return V_66 ;
F_62 ( V_64 -> V_62 , & V_15 ) ;
if ( V_44 > F_50 ( V_65 ) )
goto V_68;
if ( V_27 > V_65 -> V_57 )
goto V_68;
if ( V_44 <= V_65 -> V_57 )
goto V_68;
if ( ! F_51 ( V_64 ) )
V_67 = V_64 -> V_57 ;
else
V_67 = V_27 ;
F_54 ( V_64 , V_67 , V_44 ) ;
F_54 ( V_65 , V_44 , F_50 ( V_65 ) ) ;
F_63 ( V_64 -> V_62 , & V_15 ) ;
F_55 ( V_64 , V_27 , V_44 ) ;
return 0 ;
V_68:
F_63 ( V_64 -> V_62 , & V_15 ) ;
return - 1 ;
}
static int T_2 F_64 ( struct V_48 * V_64 , struct V_48 * V_65 ,
unsigned long V_27 , unsigned long V_44 )
{
int V_66 ;
unsigned long V_15 ;
unsigned long V_69 ;
V_66 = F_59 ( V_65 , V_27 , V_44 - V_27 ) ;
if ( V_66 )
return V_66 ;
F_62 ( V_64 -> V_62 , & V_15 ) ;
if ( V_64 -> V_57 > V_27 )
goto V_68;
if ( F_50 ( V_64 ) > V_44 )
goto V_68;
if ( V_27 >= F_50 ( V_64 ) )
goto V_68;
if ( ! F_51 ( V_65 ) )
V_69 = F_50 ( V_65 ) ;
else
V_69 = V_44 ;
F_54 ( V_64 , V_64 -> V_57 , V_27 ) ;
F_54 ( V_65 , V_27 , V_69 ) ;
F_63 ( V_64 -> V_62 , & V_15 ) ;
F_55 ( V_65 , V_27 , V_44 ) ;
return 0 ;
V_68:
F_63 ( V_64 -> V_62 , & V_15 ) ;
return - 1 ;
}
static void T_2 F_65 ( struct V_41 * V_42 , unsigned long V_27 ,
unsigned long V_44 )
{
unsigned long V_70 = F_46 ( V_42 ) ;
if ( ! V_42 -> V_71 || V_27 < V_42 -> V_55 )
V_42 -> V_55 = V_27 ;
V_42 -> V_71 = F_52 ( V_70 , V_44 ) -
V_42 -> V_55 ;
}
static int T_2 F_66 ( struct V_48 * V_48 , unsigned long V_72 )
{
struct V_41 * V_42 = V_48 -> V_62 ;
int V_45 = V_36 ;
int V_61 = V_42 -> V_47 ;
int V_59 ;
unsigned long V_15 , V_43 ;
int V_66 ;
V_59 = V_48 - V_42 -> V_50 ;
V_66 = F_59 ( V_48 , V_72 , V_45 ) ;
if ( V_66 )
return V_66 ;
F_62 ( V_48 -> V_62 , & V_15 ) ;
F_48 ( V_48 , V_72 , V_72 + V_45 ) ;
F_65 ( V_48 -> V_62 , V_72 ,
V_72 + V_45 ) ;
F_63 ( V_48 -> V_62 , & V_15 ) ;
F_67 ( V_45 , V_61 , V_59 ,
V_72 , V_73 ) ;
for ( V_43 = V_72 ; V_43 < V_72 + V_45 ; V_43 ++ ) {
if ( ! F_42 ( V_43 ) )
continue;
F_68 ( F_58 ( V_43 ) ) ;
}
return 0 ;
}
static int T_2 F_69 ( int V_61 , struct V_48 * V_48 ,
unsigned long V_72 )
{
int V_66 ;
if ( F_42 ( V_72 ) )
return - V_19 ;
V_66 = F_70 ( V_48 , V_72 ) ;
if ( V_66 < 0 )
return V_66 ;
V_66 = F_66 ( V_48 , V_72 ) ;
if ( V_66 < 0 )
return V_66 ;
return F_71 ( V_61 , F_72 ( V_72 ) ) ;
}
int T_3 F_73 ( int V_61 , struct V_48 * V_48 , unsigned long V_72 ,
unsigned long V_45 )
{
unsigned long V_31 ;
int V_74 = 0 ;
int V_75 , V_76 ;
struct V_77 * V_78 ;
F_74 ( V_48 ) ;
V_75 = F_36 ( V_72 ) ;
V_76 = F_36 ( V_72 + V_45 - 1 ) ;
V_78 = F_75 ( ( unsigned long ) F_58 ( V_72 ) ) ;
if ( V_78 ) {
if ( V_78 -> V_79 != V_72
|| F_76 ( V_78 ) > V_45 ) {
F_77 ( L_3 ) ;
V_74 = - V_80 ;
goto V_81;
}
V_78 -> V_82 = 0 ;
}
for ( V_31 = V_75 ; V_31 <= V_76 ; V_31 ++ ) {
V_74 = F_69 ( V_61 , V_48 , F_78 ( V_31 ) ) ;
if ( V_74 && ( V_74 != - V_19 ) )
break;
V_74 = 0 ;
}
F_79 () ;
V_81:
F_80 ( V_48 ) ;
return V_74 ;
}
static int F_81 ( int V_61 , struct V_48 * V_48 ,
unsigned long V_27 ,
unsigned long V_44 )
{
struct V_32 * V_33 ;
for (; V_27 < V_44 ; V_27 += V_36 ) {
V_33 = F_72 ( V_27 ) ;
if ( F_8 ( ! F_82 ( V_33 ) ) )
continue;
if ( F_8 ( F_47 ( V_27 ) != V_61 ) )
continue;
if ( V_48 && V_48 != F_83 ( F_58 ( V_27 ) ) )
continue;
return V_27 ;
}
return 0 ;
}
static int F_84 ( int V_61 , struct V_48 * V_48 ,
unsigned long V_27 ,
unsigned long V_44 )
{
struct V_32 * V_33 ;
unsigned long V_43 ;
V_43 = V_44 - 1 ;
for (; V_43 >= V_27 ; V_43 -= V_36 ) {
V_33 = F_72 ( V_43 ) ;
if ( F_8 ( ! F_82 ( V_33 ) ) )
continue;
if ( F_8 ( F_47 ( V_43 ) != V_61 ) )
continue;
if ( V_48 && V_48 != F_83 ( F_58 ( V_43 ) ) )
continue;
return V_43 ;
}
return 0 ;
}
static void F_85 ( struct V_48 * V_48 , unsigned long V_27 ,
unsigned long V_44 )
{
unsigned long V_57 = V_48 -> V_57 ;
unsigned long V_83 = F_50 ( V_48 ) ;
unsigned long F_50 = V_83 ;
unsigned long V_43 ;
struct V_32 * V_33 ;
int V_61 = F_86 ( V_48 ) ;
F_49 ( V_48 ) ;
if ( V_57 == V_27 ) {
V_43 = F_81 ( V_61 , V_48 , V_44 ,
F_50 ) ;
if ( V_43 ) {
V_48 -> V_57 = V_43 ;
V_48 -> V_58 = F_50 - V_43 ;
}
} else if ( F_50 == V_44 ) {
V_43 = F_84 ( V_61 , V_48 , V_57 ,
V_27 ) ;
if ( V_43 )
V_48 -> V_58 = V_43 - V_57 + 1 ;
}
V_43 = V_57 ;
for (; V_43 < F_50 ; V_43 += V_36 ) {
V_33 = F_72 ( V_43 ) ;
if ( F_8 ( ! F_82 ( V_33 ) ) )
continue;
if ( F_83 ( F_58 ( V_43 ) ) != V_48 )
continue;
if ( V_27 == V_43 )
continue;
F_53 ( V_48 ) ;
return;
}
V_48 -> V_57 = 0 ;
V_48 -> V_58 = 0 ;
F_53 ( V_48 ) ;
}
static void F_87 ( struct V_41 * V_42 ,
unsigned long V_27 , unsigned long V_44 )
{
unsigned long V_84 = V_42 -> V_55 ;
unsigned long V_85 = F_46 ( V_42 ) ;
unsigned long F_46 = V_85 ;
unsigned long V_43 ;
struct V_32 * V_33 ;
int V_61 = V_42 -> V_47 ;
if ( V_84 == V_27 ) {
V_43 = F_81 ( V_61 , NULL , V_44 ,
F_46 ) ;
if ( V_43 ) {
V_42 -> V_55 = V_43 ;
V_42 -> V_71 = F_46 - V_43 ;
}
} else if ( F_46 == V_44 ) {
V_43 = F_84 ( V_61 , NULL , V_84 ,
V_27 ) ;
if ( V_43 )
V_42 -> V_71 = V_43 - V_84 + 1 ;
}
V_43 = V_84 ;
for (; V_43 < F_46 ; V_43 += V_36 ) {
V_33 = F_72 ( V_43 ) ;
if ( F_8 ( ! F_82 ( V_33 ) ) )
continue;
if ( F_47 ( V_43 ) != V_61 )
continue;
if ( V_27 == V_43 )
continue;
return;
}
V_42 -> V_55 = 0 ;
V_42 -> V_71 = 0 ;
}
static void F_88 ( struct V_48 * V_48 , unsigned long V_27 )
{
struct V_41 * V_42 = V_48 -> V_62 ;
int V_45 = V_36 ;
int V_59 ;
unsigned long V_15 ;
V_59 = V_48 - V_42 -> V_50 ;
F_62 ( V_48 -> V_62 , & V_15 ) ;
F_85 ( V_48 , V_27 , V_27 + V_45 ) ;
F_87 ( V_42 , V_27 , V_27 + V_45 ) ;
F_63 ( V_48 -> V_62 , & V_15 ) ;
}
static int F_89 ( struct V_48 * V_48 , struct V_32 * V_33 ,
unsigned long V_86 )
{
unsigned long V_27 ;
int V_87 ;
int V_66 = - V_80 ;
if ( ! F_82 ( V_33 ) )
return V_66 ;
V_66 = F_90 ( V_33 ) ;
if ( V_66 )
return V_66 ;
V_87 = F_91 ( V_33 ) ;
V_27 = F_78 ( V_87 ) ;
F_88 ( V_48 , V_27 ) ;
F_92 ( V_48 , V_33 , V_86 ) ;
return 0 ;
}
int F_93 ( struct V_48 * V_48 , unsigned long V_72 ,
unsigned long V_45 )
{
unsigned long V_31 ;
unsigned long V_86 = 0 ;
int V_88 , V_66 = 0 ;
if ( F_94 ( V_48 ) ) {
struct V_21 * V_21 = F_58 ( V_72 ) ;
struct V_77 * V_78 ;
V_78 = F_75 ( ( unsigned long ) V_21 ) ;
if ( V_78 )
V_86 = F_76 ( V_78 ) ;
} else {
T_4 V_8 , V_9 ;
V_8 = V_72 << V_37 ;
V_9 = V_45 * V_89 ;
V_66 = F_95 ( & V_18 , V_8 ,
V_9 ) ;
if ( V_66 ) {
T_4 V_90 = V_8 + V_9 - 1 ;
F_96 ( L_4 ,
& V_8 , & V_90 , V_66 ) ;
}
}
F_74 ( V_48 ) ;
F_30 ( V_72 & ~ V_91 ) ;
F_30 ( V_45 % V_36 ) ;
V_88 = V_45 / V_36 ;
for ( V_31 = 0 ; V_31 < V_88 ; V_31 ++ ) {
unsigned long V_43 = V_72 + V_31 * V_36 ;
V_66 = F_89 ( V_48 , F_72 ( V_43 ) , V_86 ) ;
V_86 = 0 ;
if ( V_66 )
break;
}
F_80 ( V_48 ) ;
return V_66 ;
}
int F_97 ( T_5 V_92 )
{
int V_93 = - V_80 ;
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
int F_98 ( T_5 V_92 )
{
int V_93 = - V_80 ;
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
void F_99 ( struct V_21 * V_21 )
{
}
void F_100 ( struct V_21 * V_21 )
{
F_101 ( V_21 , 1 ) ;
}
void F_102 ( struct V_21 * V_21 )
{
F_103 ( V_21 ) ;
}
static void V_96 ( struct V_21 * V_21 )
{
F_99 ( V_21 ) ;
F_100 ( V_21 ) ;
F_102 ( V_21 ) ;
}
static int F_104 ( unsigned long V_27 , unsigned long V_45 ,
void * V_97 )
{
unsigned long V_31 ;
unsigned long V_98 = * ( unsigned long * ) V_97 ;
struct V_21 * V_21 ;
if ( F_105 ( F_58 ( V_27 ) ) )
for ( V_31 = 0 ; V_31 < V_45 ; V_31 ++ ) {
V_21 = F_58 ( V_27 + V_31 ) ;
(* V_95)( V_21 ) ;
V_98 ++ ;
}
* ( unsigned long * ) V_97 = V_98 ;
return 0 ;
}
static bool F_106 ( struct V_48 * V_48 )
{
return true ;
}
static bool F_106 ( struct V_48 * V_48 )
{
return F_107 ( F_86 ( V_48 ) , V_99 ) ;
}
static void F_108 ( unsigned long V_45 ,
struct V_48 * V_48 , struct V_100 * V_97 )
{
int V_61 = F_86 ( V_48 ) ;
enum V_59 V_101 = V_102 ;
if ( V_103 == V_99 )
V_101 = V_104 ;
if ( F_56 ( V_48 ) <= V_101 && ! F_107 ( V_61 , V_99 ) )
V_97 -> V_105 = V_61 ;
else
V_97 -> V_105 = - 1 ;
#ifdef F_109
V_101 = V_106 ;
if ( V_103 == V_107 )
V_101 = V_104 ;
if ( F_56 ( V_48 ) <= V_101 && ! F_107 ( V_61 , V_107 ) )
V_97 -> V_108 = V_61 ;
else
V_97 -> V_108 = - 1 ;
#else
V_97 -> V_108 = V_97 -> V_105 ;
#endif
if ( ! F_107 ( V_61 , V_103 ) )
V_97 -> V_109 = V_61 ;
else
V_97 -> V_109 = - 1 ;
}
static void F_110 ( int V_46 , struct V_100 * V_97 )
{
if ( V_97 -> V_105 >= 0 )
F_111 ( V_46 , V_99 ) ;
if ( V_97 -> V_108 >= 0 )
F_111 ( V_46 , V_107 ) ;
F_111 ( V_46 , V_103 ) ;
}
int T_3 F_112 ( unsigned long V_43 , unsigned long V_45 , int V_110 )
{
unsigned long V_15 ;
unsigned long V_98 = 0 ;
struct V_48 * V_48 ;
int V_111 = 0 ;
int V_61 ;
int V_66 ;
struct V_100 V_97 ;
V_48 = F_83 ( F_58 ( V_43 ) ) ;
if ( ( F_56 ( V_48 ) > V_102 ||
V_110 == V_112 ) &&
! F_106 ( V_48 ) )
return - V_80 ;
if ( V_110 == V_113 &&
F_56 ( V_48 ) == V_104 ) {
if ( F_61 ( V_48 - 1 , V_48 , V_43 , V_43 + V_45 ) )
return - V_80 ;
}
if ( V_110 == V_112 &&
F_56 ( V_48 ) == V_104 - 1 ) {
if ( F_64 ( V_48 , V_48 + 1 , V_43 , V_43 + V_45 ) )
return - V_80 ;
}
V_48 = F_83 ( F_58 ( V_43 ) ) ;
V_97 . V_27 = V_43 ;
V_97 . V_45 = V_45 ;
F_108 ( V_45 , V_48 , & V_97 ) ;
V_61 = F_86 ( V_48 ) ;
V_66 = V_100 ( V_114 , & V_97 ) ;
V_66 = F_113 ( V_66 ) ;
if ( V_66 )
goto V_115;
F_4 ( & V_116 ) ;
if ( ! F_114 ( V_48 ) ) {
V_111 = 1 ;
F_115 ( NULL , V_48 ) ;
}
V_66 = F_116 ( V_43 , V_45 , & V_98 ,
F_104 ) ;
if ( V_66 ) {
if ( V_111 )
F_117 ( V_48 ) ;
F_5 ( & V_116 ) ;
goto V_115;
}
V_48 -> V_117 += V_98 ;
F_62 ( V_48 -> V_62 , & V_15 ) ;
V_48 -> V_62 -> V_118 += V_98 ;
F_63 ( V_48 -> V_62 , & V_15 ) ;
if ( V_98 ) {
F_110 ( V_61 , & V_97 ) ;
if ( V_111 )
F_115 ( NULL , NULL ) ;
else
F_118 ( V_48 ) ;
}
F_5 ( & V_116 ) ;
F_119 () ;
if ( V_98 ) {
F_120 ( V_61 ) ;
F_121 ( V_61 ) ;
}
V_119 = F_122 () ;
F_123 () ;
if ( V_98 )
V_100 ( V_120 , & V_97 ) ;
return 0 ;
V_115:
F_21 ( L_5 ,
( unsigned long long ) V_43 << V_37 ,
( ( ( unsigned long long ) V_43 + V_45 ) << V_37 ) - 1 ) ;
V_100 ( V_121 , & V_97 ) ;
return V_66 ;
}
static void F_124 ( T_6 * V_42 )
{
struct V_48 * V_83 ;
for ( V_83 = V_42 -> V_50 ; V_83 < V_42 -> V_50 + V_51 ; V_83 ++ )
V_83 -> V_117 = 0 ;
V_42 -> V_118 = 0 ;
}
static T_6 T_3 * F_125 ( int V_61 , T_1 V_8 )
{
struct V_41 * V_42 ;
unsigned long V_122 [ V_51 ] = { 0 } ;
unsigned long V_123 [ V_51 ] = { 0 } ;
unsigned long V_27 = F_126 ( V_8 ) ;
V_42 = F_127 ( V_61 ) ;
if ( ! V_42 ) {
V_42 = F_128 ( V_61 ) ;
if ( ! V_42 )
return NULL ;
F_129 ( V_61 , V_42 ) ;
} else {
V_42 -> V_124 = 0 ;
V_42 -> V_125 = 0 ;
}
F_130 ( V_61 , V_122 , V_27 , V_123 ) ;
F_4 ( & V_116 ) ;
F_115 ( V_42 , NULL ) ;
F_5 ( & V_116 ) ;
F_131 ( V_42 ) ;
F_124 ( V_42 ) ;
return V_42 ;
}
static void F_132 ( int V_61 , T_6 * V_42 )
{
F_129 ( V_61 , NULL ) ;
F_133 ( V_42 ) ;
return;
}
int F_134 ( int V_61 )
{
T_6 * V_42 ;
int V_66 ;
if ( F_135 ( V_61 ) )
return 0 ;
F_11 () ;
V_42 = F_125 ( V_61 , 0 ) ;
if ( ! V_42 ) {
F_136 ( L_6 , V_61 ) ;
V_66 = - V_12 ;
goto V_81;
}
F_137 ( V_61 ) ;
V_66 = F_138 ( V_61 ) ;
F_30 ( V_66 ) ;
if ( V_42 -> V_126 -> V_127 -> V_48 == NULL ) {
F_4 ( & V_116 ) ;
F_115 ( NULL , NULL ) ;
F_5 ( & V_116 ) ;
}
V_81:
F_16 () ;
return V_66 ;
}
static int F_139 ( T_1 V_8 , T_1 V_9 )
{
T_1 V_27 = F_126 ( V_8 ) ;
T_1 V_45 = V_9 >> V_37 ;
if ( ( V_27 & ~ V_91 ) ||
( V_45 % V_36 ) || ( ! V_45 ) ) {
F_136 ( L_7 ,
( unsigned long long ) V_8 ,
( unsigned long long ) V_9 ) ;
return - V_80 ;
}
return 0 ;
}
static int F_140 ( int V_61 , T_1 V_8 , T_1 V_9 )
{
unsigned long V_27 = V_8 >> V_37 ;
T_6 * V_42 = F_127 ( V_61 ) ;
struct V_48 * V_128 = V_42 -> V_50 + V_104 ;
if ( F_51 ( V_128 ) )
return 0 ;
if ( V_128 -> V_57 <= V_27 )
return 1 ;
return 0 ;
}
int F_141 ( int V_61 , T_1 V_8 , T_1 V_9 , int V_129 ,
bool V_130 )
{
#ifdef F_142
if ( V_130 )
return V_131 ;
#endif
if ( F_140 ( V_61 , V_8 , V_9 ) )
return V_104 ;
return V_129 ;
}
static int F_143 ( struct V_132 * V_133 , void * V_97 )
{
return F_144 ( V_133 , V_120 , V_134 ) ;
}
int T_3 F_145 ( int V_61 , struct V_7 * V_10 , bool V_135 )
{
T_1 V_8 , V_9 ;
T_6 * V_42 = NULL ;
bool V_136 ;
bool V_137 ;
int V_66 ;
V_8 = V_10 -> V_8 ;
V_9 = F_146 ( V_10 ) ;
V_66 = F_139 ( V_8 , V_9 ) ;
if ( V_66 )
return V_66 ;
{
void * V_85 = F_127 ( V_61 ) ;
V_136 = ! V_85 ;
}
F_11 () ;
F_147 ( V_8 , V_9 , V_61 ) ;
V_137 = ! F_135 ( V_61 ) ;
if ( V_137 ) {
V_42 = F_125 ( V_61 , V_8 ) ;
V_66 = - V_12 ;
if ( ! V_42 )
goto error;
}
V_66 = F_148 ( V_61 , V_8 , V_9 , false ) ;
if ( V_66 < 0 )
goto error;
F_137 ( V_61 ) ;
if ( V_137 ) {
V_66 = F_138 ( V_61 ) ;
F_30 ( V_66 ) ;
}
F_149 ( V_8 , V_8 + V_9 , L_1 ) ;
if ( V_135 )
F_150 ( F_126 ( V_8 ) , F_151 ( V_8 + V_9 - 1 ) ,
NULL , F_143 ) ;
goto V_81;
error:
if ( V_136 )
F_132 ( V_61 , V_42 ) ;
F_152 ( V_8 , V_9 ) ;
V_81:
F_16 () ;
return V_66 ;
}
int T_3 F_153 ( int V_61 , T_1 V_8 , T_1 V_9 )
{
struct V_7 * V_10 ;
int V_66 ;
V_10 = F_17 ( V_8 , V_9 ) ;
if ( F_154 ( V_10 ) )
return F_155 ( V_10 ) ;
V_66 = F_145 ( V_61 , V_10 , V_138 ) ;
if ( V_66 < 0 )
F_23 ( V_10 ) ;
return V_66 ;
}
static inline int F_156 ( struct V_21 * V_21 )
{
return F_157 ( V_21 ) && F_158 ( V_21 ) >= V_139 ;
}
static struct V_21 * F_159 ( struct V_21 * V_21 )
{
F_30 ( F_160 ( V_21 ) & ( V_140 - 1 ) ) ;
if ( F_156 ( V_21 ) ) {
int V_141 ;
V_141 = F_158 ( V_21 ) ;
if ( ( V_141 < V_142 ) && ( V_141 >= V_139 ) )
return V_21 + ( 1 << V_141 ) ;
}
return V_21 + V_140 ;
}
int F_161 ( unsigned long V_27 , unsigned long V_45 )
{
struct V_21 * V_21 = F_58 ( V_27 ) ;
struct V_21 * V_143 = V_21 + V_45 ;
for (; V_21 < V_143 ; V_21 = F_159 ( V_21 ) ) {
if ( ! F_162 ( V_21 ) )
return 0 ;
F_163 () ;
}
return 1 ;
}
int F_164 ( unsigned long V_27 , unsigned long V_44 )
{
unsigned long V_43 , V_144 ;
struct V_48 * V_48 = NULL ;
struct V_21 * V_21 ;
int V_31 ;
for ( V_43 = V_27 , V_144 = F_165 ( V_27 ) ;
V_43 < V_44 ;
V_43 = V_144 + 1 , V_144 += V_36 ) {
if ( ! F_166 ( F_36 ( V_43 ) ) )
continue;
for (; V_43 < V_144 && V_43 < V_44 ;
V_43 += V_145 ) {
V_31 = 0 ;
while ( ( V_31 < V_145 ) &&
! F_167 ( V_43 + V_31 ) )
V_31 ++ ;
if ( V_31 == V_145 )
continue;
V_21 = F_58 ( V_43 + V_31 ) ;
if ( V_48 && F_83 ( V_21 ) != V_48 )
return 0 ;
V_48 = F_83 ( V_21 ) ;
}
}
return 1 ;
}
static unsigned long F_168 ( unsigned long V_8 , unsigned long V_14 )
{
unsigned long V_43 ;
struct V_21 * V_21 ;
for ( V_43 = V_8 ; V_43 < V_14 ; V_43 ++ ) {
if ( F_42 ( V_43 ) ) {
V_21 = F_58 ( V_43 ) ;
if ( F_169 ( V_21 ) )
return V_43 ;
if ( F_170 ( V_21 ) ) {
if ( F_171 ( V_21 ) )
return V_43 ;
else
V_43 = F_172 ( V_43 + 1 ,
1 << F_173 ( V_21 ) ) - 1 ;
}
}
}
return 0 ;
}
static int
F_174 ( unsigned long V_27 , unsigned long V_44 )
{
unsigned long V_43 ;
struct V_21 * V_21 ;
int V_146 = V_147 ;
int V_148 = 0 ;
int V_66 = 0 ;
F_175 ( V_149 ) ;
for ( V_43 = V_27 ; V_43 < V_44 && V_146 > 0 ; V_43 ++ ) {
if ( ! F_42 ( V_43 ) )
continue;
V_21 = F_58 ( V_43 ) ;
if ( F_170 ( V_21 ) ) {
struct V_21 * V_150 = F_176 ( V_21 ) ;
V_43 = F_160 ( V_150 ) + ( 1 << F_173 ( V_150 ) ) - 1 ;
if ( F_173 ( V_150 ) > V_151 ) {
V_66 = - V_152 ;
break;
}
if ( F_177 ( V_21 , & V_149 ) )
V_146 -= 1 << F_173 ( V_150 ) ;
continue;
}
if ( ! F_178 ( V_21 ) )
continue;
V_66 = F_179 ( V_21 ) ;
if ( ! V_66 ) {
F_180 ( V_21 ) ;
F_181 ( & V_21 -> V_22 , & V_149 ) ;
V_146 -- ;
F_182 ( V_21 , V_153 +
F_183 ( V_21 ) ) ;
} else {
#ifdef F_184
F_185 ( L_8 , V_43 ) ;
F_186 ( V_21 , L_9 ) ;
#endif
F_180 ( V_21 ) ;
if ( F_187 ( V_21 ) ) {
V_148 ++ ;
V_66 = - V_152 ;
break;
}
}
}
if ( ! F_188 ( & V_149 ) ) {
if ( V_148 ) {
F_189 ( & V_149 ) ;
goto V_81;
}
V_66 = F_190 ( & V_149 , V_154 , NULL , 0 ,
V_155 , V_156 ) ;
if ( V_66 )
F_189 ( & V_149 ) ;
}
V_81:
return V_66 ;
}
static int
F_191 ( unsigned long V_8 , unsigned long V_45 ,
void * V_157 )
{
F_192 ( V_8 , V_8 + V_45 ) ;
return 0 ;
}
static void
F_193 ( unsigned long V_27 , unsigned long V_44 )
{
F_116 ( V_27 , V_44 - V_27 , NULL ,
F_191 ) ;
}
static int
F_194 ( unsigned long V_27 , unsigned long V_45 ,
void * V_157 )
{
int V_66 ;
long V_158 = * ( long * ) V_157 ;
V_66 = F_195 ( V_27 , V_27 + V_45 , true ) ;
V_158 = V_45 ;
if ( ! V_66 )
* ( long * ) V_157 += V_158 ;
return V_66 ;
}
static long
F_196 ( unsigned long V_27 , unsigned long V_44 )
{
long V_158 = 0 ;
int V_66 ;
V_66 = F_116 ( V_27 , V_44 - V_27 , & V_158 ,
F_194 ) ;
if ( V_66 < 0 )
V_158 = ( long ) V_66 ;
return V_158 ;
}
static bool F_197 ( struct V_48 * V_48 , unsigned long V_45 )
{
return true ;
}
static bool F_197 ( struct V_48 * V_48 , unsigned long V_45 )
{
struct V_41 * V_42 = V_48 -> V_62 ;
unsigned long V_117 = 0 ;
enum V_59 V_159 ;
for ( V_159 = 0 ; V_159 <= V_102 ; V_159 ++ )
V_117 += V_42 -> V_50 [ V_159 ] . V_117 ;
if ( V_117 > V_45 )
return true ;
V_117 = 0 ;
for (; V_159 <= V_104 ; V_159 ++ )
V_117 += V_42 -> V_50 [ V_159 ] . V_117 ;
return V_117 == 0 ;
}
static int T_7 F_198 ( char * V_85 )
{
#ifdef F_199
F_200 ( true ) ;
V_160 = true ;
#else
F_96 ( L_10 ) ;
#endif
return 0 ;
}
static void F_201 ( unsigned long V_45 ,
struct V_48 * V_48 , struct V_100 * V_97 )
{
struct V_41 * V_42 = V_48 -> V_62 ;
unsigned long V_117 = 0 ;
enum V_59 V_159 , V_101 = V_102 ;
if ( V_103 == V_99 )
V_101 = V_104 ;
for ( V_159 = 0 ; V_159 <= V_101 ; V_159 ++ )
V_117 += V_42 -> V_50 [ V_159 ] . V_117 ;
if ( F_56 ( V_48 ) <= V_101 && V_45 >= V_117 )
V_97 -> V_105 = F_86 ( V_48 ) ;
else
V_97 -> V_105 = - 1 ;
#ifdef F_109
V_101 = V_106 ;
if ( V_103 == V_107 )
V_101 = V_104 ;
for (; V_159 <= V_101 ; V_159 ++ )
V_117 += V_42 -> V_50 [ V_159 ] . V_117 ;
if ( F_56 ( V_48 ) <= V_101 && V_45 >= V_117 )
V_97 -> V_108 = F_86 ( V_48 ) ;
else
V_97 -> V_108 = - 1 ;
#else
V_97 -> V_108 = V_97 -> V_105 ;
#endif
V_101 = V_104 ;
for (; V_159 <= V_101 ; V_159 ++ )
V_117 += V_42 -> V_50 [ V_159 ] . V_117 ;
if ( V_45 >= V_117 )
V_97 -> V_109 = F_86 ( V_48 ) ;
else
V_97 -> V_109 = - 1 ;
}
static void F_202 ( int V_46 , struct V_100 * V_97 )
{
if ( V_97 -> V_105 >= 0 )
F_203 ( V_46 , V_99 ) ;
if ( ( V_103 != V_99 ) &&
( V_97 -> V_108 >= 0 ) )
F_203 ( V_46 , V_107 ) ;
if ( ( V_103 != V_107 ) &&
( V_97 -> V_109 >= 0 ) )
F_203 ( V_46 , V_103 ) ;
}
static int T_3 F_204 ( unsigned long V_27 ,
unsigned long V_44 , unsigned long V_161 )
{
unsigned long V_43 , V_45 , V_162 ;
long V_163 ;
int V_66 , V_164 , V_165 , V_46 ;
unsigned long V_15 ;
struct V_48 * V_48 ;
struct V_100 V_97 ;
if ( ! F_205 ( V_27 , V_140 ) )
return - V_80 ;
if ( ! F_205 ( V_44 , V_140 ) )
return - V_80 ;
if ( ! F_164 ( V_27 , V_44 ) )
return - V_80 ;
V_48 = F_83 ( F_58 ( V_27 ) ) ;
V_46 = F_86 ( V_48 ) ;
V_45 = V_44 - V_27 ;
if ( F_56 ( V_48 ) <= V_102 && ! F_197 ( V_48 , V_45 ) )
return - V_80 ;
V_66 = F_206 ( V_27 , V_44 ,
V_166 , true ) ;
if ( V_66 )
return V_66 ;
V_97 . V_27 = V_27 ;
V_97 . V_45 = V_45 ;
F_201 ( V_45 , V_48 , & V_97 ) ;
V_66 = V_100 ( V_167 , & V_97 ) ;
V_66 = F_113 ( V_66 ) ;
if ( V_66 )
goto V_168;
V_43 = V_27 ;
V_162 = V_169 + V_161 ;
V_164 = 0 ;
V_165 = 5 ;
V_170:
V_66 = - V_171 ;
if ( F_207 ( V_169 , V_162 ) )
goto V_168;
V_66 = - V_172 ;
if ( F_208 ( V_3 ) )
goto V_168;
V_66 = 0 ;
if ( V_164 ) {
F_209 () ;
F_163 () ;
F_210 ( V_48 ) ;
}
V_43 = F_168 ( V_27 , V_44 ) ;
if ( V_43 ) {
V_66 = F_174 ( V_43 , V_44 ) ;
if ( ! V_66 ) {
V_164 = 1 ;
goto V_170;
} else {
if ( V_66 < 0 )
if ( -- V_165 == 0 )
goto V_168;
F_211 () ;
V_164 = 1 ;
goto V_170;
}
}
F_209 () ;
F_211 () ;
F_210 ( V_48 ) ;
F_212 ( V_27 , V_44 ) ;
V_163 = F_196 ( V_27 , V_44 ) ;
if ( V_163 < 0 ) {
V_66 = - V_152 ;
goto V_168;
}
F_213 ( L_11 , V_163 ) ;
F_193 ( V_27 , V_44 ) ;
F_214 ( V_27 , V_44 , V_166 ) ;
F_101 ( F_58 ( V_27 ) , - V_163 ) ;
V_48 -> V_117 -= V_163 ;
F_62 ( V_48 -> V_62 , & V_15 ) ;
V_48 -> V_62 -> V_118 -= V_163 ;
F_63 ( V_48 -> V_62 , & V_15 ) ;
F_119 () ;
if ( ! F_114 ( V_48 ) ) {
F_117 ( V_48 ) ;
F_4 ( & V_116 ) ;
F_115 ( NULL , NULL ) ;
F_5 ( & V_116 ) ;
} else
F_118 ( V_48 ) ;
F_202 ( V_46 , & V_97 ) ;
if ( V_97 . V_109 >= 0 ) {
F_215 ( V_46 ) ;
F_216 ( V_46 ) ;
}
V_119 = F_122 () ;
F_123 () ;
V_100 ( V_134 , & V_97 ) ;
return 0 ;
V_168:
F_21 ( L_12 ,
( unsigned long long ) V_27 << V_37 ,
( ( unsigned long long ) V_44 << V_37 ) - 1 ) ;
V_100 ( V_173 , & V_97 ) ;
F_214 ( V_27 , V_44 , V_166 ) ;
return V_66 ;
}
int F_217 ( unsigned long V_27 , unsigned long V_45 )
{
return F_204 ( V_27 , V_27 + V_45 , 120 * V_174 ) ;
}
int F_150 ( unsigned long V_27 , unsigned long V_44 ,
void * V_97 , int (* F_218)( struct V_132 * , void * ) )
{
struct V_132 * V_133 = NULL ;
struct V_32 * V_175 ;
unsigned long V_43 , V_30 ;
int V_66 ;
for ( V_43 = V_27 ; V_43 < V_44 ; V_43 += V_36 ) {
V_30 = F_36 ( V_43 ) ;
if ( ! F_166 ( V_30 ) )
continue;
V_175 = F_37 ( V_30 ) ;
if ( V_133 )
if ( ( V_30 >= V_133 -> V_176 ) &&
( V_30 <= V_133 -> V_177 ) )
continue;
V_133 = F_219 ( V_175 , V_133 ) ;
if ( ! V_133 )
continue;
V_66 = F_218 ( V_133 , V_97 ) ;
if ( V_66 ) {
F_220 ( & V_133 -> V_178 . V_179 ) ;
return V_66 ;
}
}
if ( V_133 )
F_220 ( & V_133 -> V_178 . V_179 ) ;
return 0 ;
}
static int F_221 ( struct V_132 * V_133 , void * V_97 )
{
int V_66 = ! F_222 ( V_133 ) ;
if ( F_8 ( V_66 ) ) {
T_8 V_180 , V_181 ;
V_180 = F_223 ( F_78 ( V_133 -> V_176 ) ) ;
V_181 = F_223 ( F_78 ( V_133 -> V_177 + 1 ) ) - 1 ;
F_96 ( L_13 ,
& V_180 , & V_181 ) ;
}
return V_66 ;
}
static int F_224 ( T_6 * V_42 )
{
int V_182 ;
F_225 (cpu) {
if ( F_226 ( V_182 ) == V_42 -> V_47 )
return - V_152 ;
}
return 0 ;
}
static void F_227 ( T_6 * V_42 )
{
#ifdef F_228
int V_182 ;
F_229 (cpu)
if ( F_226 ( V_182 ) == V_42 -> V_47 )
F_230 ( V_182 ) ;
#endif
}
static int F_231 ( T_6 * V_42 )
{
int V_66 ;
V_66 = F_224 ( V_42 ) ;
if ( V_66 )
return V_66 ;
F_227 ( V_42 ) ;
return 0 ;
}
void F_232 ( int V_61 )
{
T_6 * V_42 = F_127 ( V_61 ) ;
unsigned long V_27 = V_42 -> V_55 ;
unsigned long V_44 = V_27 + V_42 -> V_71 ;
unsigned long V_43 ;
int V_31 ;
for ( V_43 = V_27 ; V_43 < V_44 ; V_43 += V_36 ) {
unsigned long V_30 = F_36 ( V_43 ) ;
if ( ! F_166 ( V_30 ) )
continue;
if ( F_47 ( V_43 ) != V_61 )
continue;
return;
}
if ( F_231 ( V_42 ) )
return;
F_233 ( V_61 ) ;
F_234 ( V_61 ) ;
for ( V_31 = 0 ; V_31 < V_51 ; V_31 ++ ) {
struct V_48 * V_48 = V_42 -> V_50 + V_31 ;
if ( F_235 ( V_48 -> V_54 ) ) {
F_236 ( V_48 -> V_54 ) ;
V_48 -> V_54 = NULL ;
}
}
}
void T_3 F_237 ( int V_61 , T_1 V_8 , T_1 V_9 )
{
int V_66 ;
F_30 ( F_139 ( V_8 , V_9 ) ) ;
F_11 () ;
V_66 = F_150 ( F_126 ( V_8 ) , F_151 ( V_8 + V_9 - 1 ) , NULL ,
F_221 ) ;
if ( V_66 )
F_238 () ;
F_239 ( V_8 , V_8 + V_9 , L_1 ) ;
F_240 ( V_8 , V_9 ) ;
F_152 ( V_8 , V_9 ) ;
F_241 ( V_8 , V_9 ) ;
F_232 ( V_61 ) ;
F_16 () ;
}
