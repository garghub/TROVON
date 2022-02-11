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
F_19 ( ! V_10 ) ;
V_10 -> V_12 = L_1 ;
V_10 -> V_8 = V_8 ;
V_10 -> V_13 = V_8 + V_9 - 1 ;
V_10 -> V_14 = V_15 | V_16 ;
if ( F_20 ( & V_17 , V_10 ) < 0 ) {
F_21 ( L_2 , V_10 ) ;
F_22 ( V_10 ) ;
V_10 = NULL ;
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
void F_25 ( unsigned long V_18 , struct V_19 * V_19 ,
unsigned long type )
{
V_19 -> V_20 . V_21 = (struct V_22 * ) type ;
F_26 ( V_19 ) ;
F_27 ( V_19 , V_18 ) ;
F_28 ( & V_19 -> V_23 ) ;
}
void F_29 ( struct V_19 * V_19 )
{
unsigned long type ;
type = ( unsigned long ) V_19 -> V_20 . V_21 ;
F_19 ( type < V_24 ||
type > V_25 ) ;
if ( F_30 ( & V_19 -> V_23 ) == 1 ) {
F_31 ( V_19 ) ;
F_27 ( V_19 , 0 ) ;
F_32 ( & V_19 -> V_20 ) ;
F_33 ( V_19 ) ;
}
}
static void F_34 ( unsigned long V_26 )
{
unsigned long * V_27 , V_28 , V_29 , V_30 ;
struct V_31 * V_32 ;
struct V_19 * V_19 , * V_33 ;
V_29 = F_35 ( V_26 ) ;
V_32 = F_36 ( V_29 ) ;
V_33 = F_37 ( V_32 -> V_34 , V_29 ) ;
V_19 = F_38 ( V_33 ) ;
V_28 = sizeof( struct V_19 ) * V_35 ;
V_28 = F_39 ( V_28 ) >> V_36 ;
for ( V_30 = 0 ; V_30 < V_28 ; V_30 ++ , V_19 ++ )
F_25 ( V_29 , V_19 , V_37 ) ;
V_27 = F_36 ( V_29 ) -> V_38 ;
V_19 = F_38 ( V_27 ) ;
V_28 = F_39 ( F_40 () ) >> V_36 ;
for ( V_30 = 0 ; V_30 < V_28 ; V_30 ++ , V_19 ++ )
F_25 ( V_29 , V_19 , V_39 ) ;
}
static void F_34 ( unsigned long V_26 )
{
unsigned long * V_27 , V_28 , V_29 , V_30 ;
struct V_31 * V_32 ;
struct V_19 * V_19 , * V_33 ;
if ( ! F_41 ( V_26 ) )
return;
V_29 = F_35 ( V_26 ) ;
V_32 = F_36 ( V_29 ) ;
V_33 = F_37 ( V_32 -> V_34 , V_29 ) ;
F_42 ( V_29 , V_33 , V_35 ) ;
V_27 = F_36 ( V_29 ) -> V_38 ;
V_19 = F_38 ( V_27 ) ;
V_28 = F_39 ( F_40 () ) >> V_36 ;
for ( V_30 = 0 ; V_30 < V_28 ; V_30 ++ , V_19 ++ )
F_25 ( V_29 , V_19 , V_39 ) ;
}
void F_43 ( struct V_40 * V_41 )
{
unsigned long V_30 , V_42 , V_43 , V_44 ;
int V_45 = V_41 -> V_46 ;
struct V_19 * V_19 ;
struct V_47 * V_47 ;
V_44 = F_39 ( sizeof( struct V_40 ) ) >> V_36 ;
V_19 = F_38 ( V_41 ) ;
for ( V_30 = 0 ; V_30 < V_44 ; V_30 ++ , V_19 ++ )
F_25 ( V_45 , V_19 , V_48 ) ;
V_47 = & V_41 -> V_49 [ 0 ] ;
for (; V_47 < V_41 -> V_49 + V_50 - 1 ; V_47 ++ ) {
if ( F_44 ( V_47 ) ) {
V_44 = V_47 -> V_51
* sizeof( V_52 ) ;
V_44 = F_39 ( V_44 ) >> V_36 ;
V_19 = F_38 ( V_47 -> V_53 ) ;
for ( V_30 = 0 ; V_30 < V_44 ; V_30 ++ , V_19 ++ )
F_25 ( V_45 , V_19 , V_48 ) ;
}
}
V_42 = V_41 -> V_54 ;
V_43 = F_45 ( V_41 ) ;
for (; V_42 < V_43 ; V_42 += V_35 ) {
if ( F_41 ( V_42 ) && ( F_46 ( V_42 ) == V_45 ) )
F_34 ( V_42 ) ;
}
}
static void T_2 F_47 ( struct V_47 * V_47 , unsigned long V_26 ,
unsigned long V_43 )
{
unsigned long V_55 ;
F_48 ( V_47 ) ;
V_55 = F_49 ( V_47 ) ;
if ( F_50 ( V_47 ) || V_26 < V_47 -> V_56 )
V_47 -> V_56 = V_26 ;
V_47 -> V_57 = F_51 ( V_55 , V_43 ) -
V_47 -> V_56 ;
F_52 ( V_47 ) ;
}
static void F_53 ( struct V_47 * V_47 , unsigned long V_26 ,
unsigned long V_43 )
{
F_48 ( V_47 ) ;
if ( V_43 - V_26 ) {
V_47 -> V_56 = V_26 ;
V_47 -> V_57 = V_43 - V_26 ;
} else {
V_47 -> V_56 = 0 ;
V_47 -> V_57 = 0 ;
}
F_52 ( V_47 ) ;
}
static void F_54 ( struct V_47 * V_47 , unsigned long V_26 ,
unsigned long V_43 )
{
enum V_58 V_59 = F_55 ( V_47 ) ;
int V_60 = V_47 -> V_61 -> V_46 ;
unsigned long V_42 ;
for ( V_42 = V_26 ; V_42 < V_43 ; V_42 ++ )
F_56 ( F_57 ( V_42 ) , V_59 , V_60 , V_42 ) ;
}
static int T_3 F_58 ( struct V_47 * V_47 ,
unsigned long V_26 , unsigned long V_62 )
{
if ( ! F_44 ( V_47 ) )
return F_59 ( V_47 , V_26 , V_62 ) ;
return 0 ;
}
static int T_2 F_60 ( struct V_47 * V_63 , struct V_47 * V_64 ,
unsigned long V_26 , unsigned long V_43 )
{
int V_65 ;
unsigned long V_14 ;
unsigned long V_66 ;
V_65 = F_58 ( V_63 , V_26 , V_43 - V_26 ) ;
if ( V_65 )
return V_65 ;
F_61 ( V_63 -> V_61 , & V_14 ) ;
if ( V_43 > F_49 ( V_64 ) )
goto V_67;
if ( V_26 > V_64 -> V_56 )
goto V_67;
if ( V_43 <= V_64 -> V_56 )
goto V_67;
if ( ! F_50 ( V_63 ) )
V_66 = V_63 -> V_56 ;
else
V_66 = V_26 ;
F_53 ( V_63 , V_66 , V_43 ) ;
F_53 ( V_64 , V_43 , F_49 ( V_64 ) ) ;
F_62 ( V_63 -> V_61 , & V_14 ) ;
F_54 ( V_63 , V_26 , V_43 ) ;
return 0 ;
V_67:
F_62 ( V_63 -> V_61 , & V_14 ) ;
return - 1 ;
}
static int T_2 F_63 ( struct V_47 * V_63 , struct V_47 * V_64 ,
unsigned long V_26 , unsigned long V_43 )
{
int V_65 ;
unsigned long V_14 ;
unsigned long V_68 ;
V_65 = F_58 ( V_64 , V_26 , V_43 - V_26 ) ;
if ( V_65 )
return V_65 ;
F_61 ( V_63 -> V_61 , & V_14 ) ;
if ( V_63 -> V_56 > V_26 )
goto V_67;
if ( F_49 ( V_63 ) > V_43 )
goto V_67;
if ( V_26 >= F_49 ( V_63 ) )
goto V_67;
if ( ! F_50 ( V_64 ) )
V_68 = F_49 ( V_64 ) ;
else
V_68 = V_43 ;
F_53 ( V_63 , V_63 -> V_56 , V_26 ) ;
F_53 ( V_64 , V_26 , V_68 ) ;
F_62 ( V_63 -> V_61 , & V_14 ) ;
F_54 ( V_64 , V_26 , V_43 ) ;
return 0 ;
V_67:
F_62 ( V_63 -> V_61 , & V_14 ) ;
return - 1 ;
}
static void T_2 F_64 ( struct V_40 * V_41 , unsigned long V_26 ,
unsigned long V_43 )
{
unsigned long V_69 = F_45 ( V_41 ) ;
if ( ! V_41 -> V_70 || V_26 < V_41 -> V_54 )
V_41 -> V_54 = V_26 ;
V_41 -> V_70 = F_51 ( V_69 , V_43 ) -
V_41 -> V_54 ;
}
static int T_2 F_65 ( struct V_47 * V_47 , unsigned long V_71 )
{
struct V_40 * V_41 = V_47 -> V_61 ;
int V_44 = V_35 ;
int V_60 = V_41 -> V_46 ;
int V_58 ;
unsigned long V_14 , V_42 ;
int V_65 ;
V_58 = V_47 - V_41 -> V_49 ;
V_65 = F_58 ( V_47 , V_71 , V_44 ) ;
if ( V_65 )
return V_65 ;
F_61 ( V_47 -> V_61 , & V_14 ) ;
F_47 ( V_47 , V_71 , V_71 + V_44 ) ;
F_64 ( V_47 -> V_61 , V_71 ,
V_71 + V_44 ) ;
F_62 ( V_47 -> V_61 , & V_14 ) ;
F_66 ( V_44 , V_60 , V_58 ,
V_71 , V_72 ) ;
for ( V_42 = V_71 ; V_42 < V_71 + V_44 ; V_42 ++ ) {
if ( ! F_41 ( V_42 ) )
continue;
F_67 ( F_57 ( V_42 ) ) ;
}
return 0 ;
}
static int T_2 F_68 ( int V_60 , struct V_47 * V_47 ,
unsigned long V_71 )
{
int V_65 ;
if ( F_41 ( V_71 ) )
return - V_73 ;
V_65 = F_69 ( V_47 , V_71 ) ;
if ( V_65 < 0 )
return V_65 ;
V_65 = F_65 ( V_47 , V_71 ) ;
if ( V_65 < 0 )
return V_65 ;
return F_70 ( V_60 , F_71 ( V_71 ) ) ;
}
int T_3 F_72 ( int V_60 , struct V_47 * V_47 , unsigned long V_71 ,
unsigned long V_44 )
{
unsigned long V_30 ;
int V_74 = 0 ;
int V_75 , V_76 ;
V_75 = F_35 ( V_71 ) ;
V_76 = F_35 ( V_71 + V_44 - 1 ) ;
for ( V_30 = V_75 ; V_30 <= V_76 ; V_30 ++ ) {
V_74 = F_68 ( V_60 , V_47 , F_73 ( V_30 ) ) ;
if ( V_74 && ( V_74 != - V_73 ) )
break;
V_74 = 0 ;
}
F_74 () ;
return V_74 ;
}
static int F_75 ( int V_60 , struct V_47 * V_47 ,
unsigned long V_26 ,
unsigned long V_43 )
{
struct V_31 * V_32 ;
for (; V_26 < V_43 ; V_26 += V_35 ) {
V_32 = F_71 ( V_26 ) ;
if ( F_8 ( ! F_76 ( V_32 ) ) )
continue;
if ( F_8 ( F_46 ( V_26 ) != V_60 ) )
continue;
if ( V_47 && V_47 != F_77 ( F_57 ( V_26 ) ) )
continue;
return V_26 ;
}
return 0 ;
}
static int F_78 ( int V_60 , struct V_47 * V_47 ,
unsigned long V_26 ,
unsigned long V_43 )
{
struct V_31 * V_32 ;
unsigned long V_42 ;
V_42 = V_43 - 1 ;
for (; V_42 >= V_26 ; V_42 -= V_35 ) {
V_32 = F_71 ( V_42 ) ;
if ( F_8 ( ! F_76 ( V_32 ) ) )
continue;
if ( F_8 ( F_46 ( V_42 ) != V_60 ) )
continue;
if ( V_47 && V_47 != F_77 ( F_57 ( V_42 ) ) )
continue;
return V_42 ;
}
return 0 ;
}
static void F_79 ( struct V_47 * V_47 , unsigned long V_26 ,
unsigned long V_43 )
{
unsigned long V_56 = V_47 -> V_56 ;
unsigned long V_77 = F_49 ( V_47 ) ;
unsigned long F_49 = V_77 ;
unsigned long V_42 ;
struct V_31 * V_32 ;
int V_60 = F_80 ( V_47 ) ;
F_48 ( V_47 ) ;
if ( V_56 == V_26 ) {
V_42 = F_75 ( V_60 , V_47 , V_43 ,
F_49 ) ;
if ( V_42 ) {
V_47 -> V_56 = V_42 ;
V_47 -> V_57 = F_49 - V_42 ;
}
} else if ( F_49 == V_43 ) {
V_42 = F_78 ( V_60 , V_47 , V_56 ,
V_26 ) ;
if ( V_42 )
V_47 -> V_57 = V_42 - V_56 + 1 ;
}
V_42 = V_56 ;
for (; V_42 < F_49 ; V_42 += V_35 ) {
V_32 = F_71 ( V_42 ) ;
if ( F_8 ( ! F_76 ( V_32 ) ) )
continue;
if ( F_77 ( F_57 ( V_42 ) ) != V_47 )
continue;
if ( V_26 == V_42 )
continue;
F_52 ( V_47 ) ;
return;
}
V_47 -> V_56 = 0 ;
V_47 -> V_57 = 0 ;
F_52 ( V_47 ) ;
}
static void F_81 ( struct V_40 * V_41 ,
unsigned long V_26 , unsigned long V_43 )
{
unsigned long V_78 = V_41 -> V_54 ;
unsigned long V_79 = F_45 ( V_41 ) ;
unsigned long F_45 = V_79 ;
unsigned long V_42 ;
struct V_31 * V_32 ;
int V_60 = V_41 -> V_46 ;
if ( V_78 == V_26 ) {
V_42 = F_75 ( V_60 , NULL , V_43 ,
F_45 ) ;
if ( V_42 ) {
V_41 -> V_54 = V_42 ;
V_41 -> V_70 = F_45 - V_42 ;
}
} else if ( F_45 == V_43 ) {
V_42 = F_78 ( V_60 , NULL , V_78 ,
V_26 ) ;
if ( V_42 )
V_41 -> V_70 = V_42 - V_78 + 1 ;
}
V_42 = V_78 ;
for (; V_42 < F_45 ; V_42 += V_35 ) {
V_32 = F_71 ( V_42 ) ;
if ( F_8 ( ! F_76 ( V_32 ) ) )
continue;
if ( F_46 ( V_42 ) != V_60 )
continue;
if ( V_26 == V_42 )
continue;
return;
}
V_41 -> V_54 = 0 ;
V_41 -> V_70 = 0 ;
}
static void F_82 ( struct V_47 * V_47 , unsigned long V_26 )
{
struct V_40 * V_41 = V_47 -> V_61 ;
int V_44 = V_35 ;
int V_58 ;
unsigned long V_14 ;
V_58 = V_47 - V_41 -> V_49 ;
F_61 ( V_47 -> V_61 , & V_14 ) ;
F_79 ( V_47 , V_26 , V_26 + V_44 ) ;
F_81 ( V_41 , V_26 , V_26 + V_44 ) ;
F_62 ( V_47 -> V_61 , & V_14 ) ;
}
static int F_83 ( struct V_47 * V_47 , struct V_31 * V_32 )
{
unsigned long V_26 ;
int V_80 ;
int V_65 = - V_81 ;
if ( ! F_76 ( V_32 ) )
return V_65 ;
V_65 = F_84 ( V_32 ) ;
if ( V_65 )
return V_65 ;
V_80 = F_85 ( V_32 ) ;
V_26 = F_73 ( V_80 ) ;
F_82 ( V_47 , V_26 ) ;
F_86 ( V_47 , V_32 ) ;
return 0 ;
}
int F_87 ( struct V_47 * V_47 , unsigned long V_71 ,
unsigned long V_44 )
{
unsigned long V_30 ;
int V_82 ;
T_4 V_8 , V_9 ;
int V_65 = 0 ;
F_19 ( V_71 & ~ V_83 ) ;
F_19 ( V_44 % V_35 ) ;
V_8 = V_71 << V_36 ;
V_9 = V_44 * V_84 ;
if ( ! F_88 ( V_47 ) )
V_65 = F_89 ( & V_17 , V_8 , V_9 ) ;
if ( V_65 ) {
T_4 V_85 = V_8 + V_9 - 1 ;
F_90 ( L_3 ,
& V_8 , & V_85 , V_65 ) ;
}
V_82 = V_44 / V_35 ;
for ( V_30 = 0 ; V_30 < V_82 ; V_30 ++ ) {
unsigned long V_42 = V_71 + V_30 * V_35 ;
V_65 = F_83 ( V_47 , F_71 ( V_42 ) ) ;
if ( V_65 )
break;
}
return V_65 ;
}
int F_91 ( T_5 V_86 )
{
int V_87 = - V_81 ;
F_1 () ;
F_4 ( & V_88 ) ;
if ( V_89 == V_90 ) {
V_89 = V_86 ;
V_87 = 0 ;
}
F_5 ( & V_88 ) ;
F_6 () ;
return V_87 ;
}
int F_92 ( T_5 V_86 )
{
int V_87 = - V_81 ;
F_1 () ;
F_4 ( & V_88 ) ;
if ( V_89 == V_86 ) {
V_89 = V_90 ;
V_87 = 0 ;
}
F_5 ( & V_88 ) ;
F_6 () ;
return V_87 ;
}
void F_93 ( struct V_19 * V_19 )
{
}
void F_94 ( struct V_19 * V_19 )
{
F_95 ( V_19 , 1 ) ;
}
void F_96 ( struct V_19 * V_19 )
{
F_97 ( V_19 ) ;
}
static void V_90 ( struct V_19 * V_19 )
{
F_93 ( V_19 ) ;
F_94 ( V_19 ) ;
F_96 ( V_19 ) ;
}
static int F_98 ( unsigned long V_26 , unsigned long V_44 ,
void * V_91 )
{
unsigned long V_30 ;
unsigned long V_92 = * ( unsigned long * ) V_91 ;
struct V_19 * V_19 ;
if ( F_99 ( F_57 ( V_26 ) ) )
for ( V_30 = 0 ; V_30 < V_44 ; V_30 ++ ) {
V_19 = F_57 ( V_26 + V_30 ) ;
(* V_89)( V_19 ) ;
V_92 ++ ;
}
* ( unsigned long * ) V_91 = V_92 ;
return 0 ;
}
static bool F_100 ( struct V_47 * V_47 )
{
return true ;
}
static bool F_100 ( struct V_47 * V_47 )
{
return F_101 ( F_80 ( V_47 ) , V_93 ) ;
}
static void F_102 ( unsigned long V_44 ,
struct V_47 * V_47 , struct V_94 * V_91 )
{
int V_60 = F_80 ( V_47 ) ;
enum V_58 V_95 = V_96 ;
if ( V_97 == V_93 )
V_95 = V_98 ;
if ( F_55 ( V_47 ) <= V_95 && ! F_101 ( V_60 , V_93 ) )
V_91 -> V_99 = V_60 ;
else
V_91 -> V_99 = - 1 ;
#ifdef F_103
V_95 = V_100 ;
if ( V_97 == V_101 )
V_95 = V_98 ;
if ( F_55 ( V_47 ) <= V_95 && ! F_101 ( V_60 , V_101 ) )
V_91 -> V_102 = V_60 ;
else
V_91 -> V_102 = - 1 ;
#else
V_91 -> V_102 = V_91 -> V_99 ;
#endif
if ( ! F_101 ( V_60 , V_97 ) )
V_91 -> V_103 = V_60 ;
else
V_91 -> V_103 = - 1 ;
}
static void F_104 ( int V_45 , struct V_94 * V_91 )
{
if ( V_91 -> V_99 >= 0 )
F_105 ( V_45 , V_93 ) ;
if ( V_91 -> V_102 >= 0 )
F_105 ( V_45 , V_101 ) ;
F_105 ( V_45 , V_97 ) ;
}
int T_3 F_106 ( unsigned long V_42 , unsigned long V_44 , int V_104 )
{
unsigned long V_14 ;
unsigned long V_92 = 0 ;
struct V_47 * V_47 ;
int V_105 = 0 ;
int V_60 ;
int V_65 ;
struct V_94 V_91 ;
V_47 = F_77 ( F_57 ( V_42 ) ) ;
if ( ( F_55 ( V_47 ) > V_96 ||
V_104 == V_106 ) &&
! F_100 ( V_47 ) )
return - V_81 ;
if ( V_104 == V_107 &&
F_55 ( V_47 ) == V_98 ) {
if ( F_60 ( V_47 - 1 , V_47 , V_42 , V_42 + V_44 ) )
return - V_81 ;
}
if ( V_104 == V_106 &&
F_55 ( V_47 ) == V_98 - 1 ) {
if ( F_63 ( V_47 , V_47 + 1 , V_42 , V_42 + V_44 ) )
return - V_81 ;
}
V_47 = F_77 ( F_57 ( V_42 ) ) ;
V_91 . V_26 = V_42 ;
V_91 . V_44 = V_44 ;
F_102 ( V_44 , V_47 , & V_91 ) ;
V_60 = F_46 ( V_42 ) ;
V_65 = V_94 ( V_108 , & V_91 ) ;
V_65 = F_107 ( V_65 ) ;
if ( V_65 ) {
V_94 ( V_109 , & V_91 ) ;
return V_65 ;
}
F_4 ( & V_110 ) ;
if ( ! F_108 ( V_47 ) ) {
V_105 = 1 ;
F_109 ( NULL , V_47 ) ;
}
V_65 = F_110 ( V_42 , V_44 , & V_92 ,
F_98 ) ;
if ( V_65 ) {
if ( V_105 )
F_111 ( V_47 ) ;
F_5 ( & V_110 ) ;
F_112 ( V_111 L_4 ,
( unsigned long long ) V_42 << V_36 ,
( ( ( unsigned long long ) V_42 + V_44 )
<< V_36 ) - 1 ) ;
V_94 ( V_109 , & V_91 ) ;
return V_65 ;
}
V_47 -> V_112 += V_92 ;
F_61 ( V_47 -> V_61 , & V_14 ) ;
V_47 -> V_61 -> V_113 += V_92 ;
F_62 ( V_47 -> V_61 , & V_14 ) ;
if ( V_92 ) {
F_104 ( F_80 ( V_47 ) , & V_91 ) ;
if ( V_105 )
F_109 ( NULL , NULL ) ;
else
F_113 ( V_47 ) ;
}
F_5 ( & V_110 ) ;
F_114 () ;
if ( V_92 )
F_115 ( F_80 ( V_47 ) ) ;
V_114 = F_116 () ;
F_117 () ;
if ( V_92 )
V_94 ( V_115 , & V_91 ) ;
return 0 ;
}
static void F_118 ( T_6 * V_41 )
{
struct V_47 * V_77 ;
for ( V_77 = V_41 -> V_49 ; V_77 < V_41 -> V_49 + V_50 ; V_77 ++ )
V_77 -> V_112 = 0 ;
V_41 -> V_113 = 0 ;
}
static T_6 T_3 * F_119 ( int V_60 , T_1 V_8 )
{
struct V_40 * V_41 ;
unsigned long V_116 [ V_50 ] = { 0 } ;
unsigned long V_117 [ V_50 ] = { 0 } ;
unsigned long V_26 = F_120 ( V_8 ) ;
V_41 = F_121 ( V_60 ) ;
if ( ! V_41 ) {
V_41 = F_122 ( V_60 ) ;
if ( ! V_41 )
return NULL ;
F_123 ( V_60 , V_41 ) ;
} else {
V_41 -> V_118 = 0 ;
V_41 -> V_119 = 0 ;
}
F_124 ( V_60 , V_116 , V_26 , V_117 ) ;
F_4 ( & V_110 ) ;
F_109 ( V_41 , NULL ) ;
F_5 ( & V_110 ) ;
F_125 ( V_41 ) ;
F_118 ( V_41 ) ;
return V_41 ;
}
static void F_126 ( int V_60 , T_6 * V_41 )
{
F_123 ( V_60 , NULL ) ;
F_127 ( V_41 ) ;
return;
}
int F_128 ( int V_60 )
{
T_6 * V_41 ;
int V_65 ;
if ( F_129 ( V_60 ) )
return 0 ;
F_11 () ;
V_41 = F_119 ( V_60 , 0 ) ;
if ( ! V_41 ) {
F_130 ( L_5 , V_60 ) ;
V_65 = - V_120 ;
goto V_121;
}
F_131 ( V_60 ) ;
V_65 = F_132 ( V_60 ) ;
F_19 ( V_65 ) ;
if ( V_41 -> V_122 -> V_123 -> V_47 == NULL ) {
F_4 ( & V_110 ) ;
F_109 ( NULL , NULL ) ;
F_5 ( & V_110 ) ;
}
V_121:
F_16 () ;
return V_65 ;
}
static int F_133 ( T_1 V_8 , T_1 V_9 )
{
T_1 V_26 = F_120 ( V_8 ) ;
T_1 V_44 = V_9 >> V_36 ;
if ( ( V_26 & ~ V_83 ) ||
( V_44 % V_35 ) || ( ! V_44 ) ) {
F_130 ( L_6 ,
( unsigned long long ) V_8 ,
( unsigned long long ) V_9 ) ;
return - V_81 ;
}
return 0 ;
}
static int F_134 ( int V_60 , T_1 V_8 , T_1 V_9 )
{
unsigned long V_26 = V_8 >> V_36 ;
T_6 * V_41 = F_121 ( V_60 ) ;
struct V_47 * V_124 = V_41 -> V_49 + V_98 ;
if ( F_50 ( V_124 ) )
return 0 ;
if ( V_124 -> V_56 <= V_26 )
return 1 ;
return 0 ;
}
int F_135 ( int V_60 , T_1 V_8 , T_1 V_9 , int V_125 ,
bool V_126 )
{
#ifdef F_136
if ( V_126 )
return V_127 ;
#endif
if ( F_134 ( V_60 , V_8 , V_9 ) )
return V_98 ;
return V_125 ;
}
int T_3 F_137 ( int V_60 , struct V_7 * V_10 )
{
T_1 V_8 , V_9 ;
T_6 * V_41 = NULL ;
bool V_128 ;
bool V_129 ;
int V_65 ;
V_8 = V_10 -> V_8 ;
V_9 = F_138 ( V_10 ) ;
V_65 = F_133 ( V_8 , V_9 ) ;
if ( V_65 )
return V_65 ;
{
void * V_79 = F_121 ( V_60 ) ;
V_128 = ! V_79 ;
}
F_11 () ;
F_139 ( V_8 , V_9 , V_60 ) ;
V_129 = ! F_129 ( V_60 ) ;
if ( V_129 ) {
V_41 = F_119 ( V_60 , V_8 ) ;
V_65 = - V_120 ;
if ( ! V_41 )
goto error;
}
V_65 = F_140 ( V_60 , V_8 , V_9 , false ) ;
if ( V_65 < 0 )
goto error;
F_131 ( V_60 ) ;
if ( V_129 ) {
V_65 = F_132 ( V_60 ) ;
F_19 ( V_65 ) ;
}
F_141 ( V_8 , V_8 + V_9 , L_1 ) ;
goto V_121;
error:
if ( V_128 )
F_126 ( V_60 , V_41 ) ;
F_142 ( V_8 , V_9 ) ;
V_121:
F_16 () ;
return V_65 ;
}
int T_3 F_143 ( int V_60 , T_1 V_8 , T_1 V_9 )
{
struct V_7 * V_10 ;
int V_65 ;
V_10 = F_17 ( V_8 , V_9 ) ;
if ( ! V_10 )
return - V_73 ;
V_65 = F_137 ( V_60 , V_10 ) ;
if ( V_65 < 0 )
F_23 ( V_10 ) ;
return V_65 ;
}
static inline int F_144 ( struct V_19 * V_19 )
{
return F_145 ( V_19 ) && F_146 ( V_19 ) >= V_130 ;
}
static struct V_19 * F_147 ( struct V_19 * V_19 )
{
F_19 ( F_148 ( V_19 ) & ( V_131 - 1 ) ) ;
if ( F_144 ( V_19 ) ) {
int V_132 ;
V_132 = F_146 ( V_19 ) ;
if ( ( V_132 < V_133 ) && ( V_132 >= V_130 ) )
return V_19 + ( 1 << V_132 ) ;
}
return V_19 + V_131 ;
}
int F_149 ( unsigned long V_26 , unsigned long V_44 )
{
struct V_19 * V_19 = F_57 ( V_26 ) ;
struct V_19 * V_134 = V_19 + V_44 ;
for (; V_19 < V_134 ; V_19 = F_147 ( V_19 ) ) {
if ( ! F_150 ( V_19 ) )
return 0 ;
F_151 () ;
}
return 1 ;
}
int F_152 ( unsigned long V_26 , unsigned long V_43 )
{
unsigned long V_42 , V_135 ;
struct V_47 * V_47 = NULL ;
struct V_19 * V_19 ;
int V_30 ;
for ( V_42 = V_26 , V_135 = F_153 ( V_26 ) ;
V_42 < V_43 ;
V_42 = V_135 + 1 , V_135 += V_35 ) {
if ( ! F_154 ( F_35 ( V_42 ) ) )
continue;
for (; V_42 < V_135 && V_42 < V_43 ;
V_42 += V_136 ) {
V_30 = 0 ;
while ( ( V_30 < V_136 ) &&
! F_155 ( V_42 + V_30 ) )
V_30 ++ ;
if ( V_30 == V_136 )
continue;
V_19 = F_57 ( V_42 + V_30 ) ;
if ( V_47 && F_77 ( V_19 ) != V_47 )
return 0 ;
V_47 = F_77 ( V_19 ) ;
}
}
return 1 ;
}
static unsigned long F_156 ( unsigned long V_8 , unsigned long V_13 )
{
unsigned long V_42 ;
struct V_19 * V_19 ;
for ( V_42 = V_8 ; V_42 < V_13 ; V_42 ++ ) {
if ( F_41 ( V_42 ) ) {
V_19 = F_57 ( V_42 ) ;
if ( F_157 ( V_19 ) )
return V_42 ;
if ( F_158 ( V_19 ) ) {
if ( F_159 ( V_19 ) )
return V_42 ;
else
V_42 = F_160 ( V_42 + 1 ,
1 << F_161 ( V_19 ) ) - 1 ;
}
}
}
return 0 ;
}
static int
F_162 ( unsigned long V_26 , unsigned long V_43 )
{
unsigned long V_42 ;
struct V_19 * V_19 ;
int V_137 = V_138 ;
int V_139 = 0 ;
int V_65 = 0 ;
F_163 ( V_140 ) ;
for ( V_42 = V_26 ; V_42 < V_43 && V_137 > 0 ; V_42 ++ ) {
if ( ! F_41 ( V_42 ) )
continue;
V_19 = F_57 ( V_42 ) ;
if ( F_158 ( V_19 ) ) {
struct V_19 * V_141 = F_164 ( V_19 ) ;
V_42 = F_148 ( V_141 ) + ( 1 << F_161 ( V_141 ) ) - 1 ;
if ( F_161 ( V_141 ) > V_142 ) {
V_65 = - V_143 ;
break;
}
if ( F_165 ( V_19 , & V_140 ) )
V_137 -= 1 << F_161 ( V_141 ) ;
continue;
}
if ( ! F_166 ( V_19 ) )
continue;
V_65 = F_167 ( V_19 ) ;
if ( ! V_65 ) {
F_168 ( V_19 ) ;
F_169 ( & V_19 -> V_20 , & V_140 ) ;
V_137 -- ;
F_170 ( V_19 , V_144 +
F_171 ( V_19 ) ) ;
} else {
#ifdef F_172
F_112 ( V_145 L_7 ,
V_42 ) ;
F_173 ( V_19 , L_8 ) ;
#endif
F_168 ( V_19 ) ;
if ( F_174 ( V_19 ) ) {
V_139 ++ ;
V_65 = - V_143 ;
break;
}
}
}
if ( ! F_175 ( & V_140 ) ) {
if ( V_139 ) {
F_176 ( & V_140 ) ;
goto V_121;
}
V_65 = F_177 ( & V_140 , V_146 , NULL , 0 ,
V_147 , V_148 ) ;
if ( V_65 )
F_176 ( & V_140 ) ;
}
V_121:
return V_65 ;
}
static int
F_178 ( unsigned long V_8 , unsigned long V_44 ,
void * V_149 )
{
F_179 ( V_8 , V_8 + V_44 ) ;
return 0 ;
}
static void
F_180 ( unsigned long V_26 , unsigned long V_43 )
{
F_110 ( V_26 , V_43 - V_26 , NULL ,
F_178 ) ;
}
static int
F_181 ( unsigned long V_26 , unsigned long V_44 ,
void * V_149 )
{
int V_65 ;
long V_150 = * ( long * ) V_149 ;
V_65 = F_182 ( V_26 , V_26 + V_44 , true ) ;
V_150 = V_44 ;
if ( ! V_65 )
* ( long * ) V_149 += V_150 ;
return V_65 ;
}
static long
F_183 ( unsigned long V_26 , unsigned long V_43 )
{
long V_150 = 0 ;
int V_65 ;
V_65 = F_110 ( V_26 , V_43 - V_26 , & V_150 ,
F_181 ) ;
if ( V_65 < 0 )
V_150 = ( long ) V_65 ;
return V_150 ;
}
static bool F_184 ( struct V_47 * V_47 , unsigned long V_44 )
{
return true ;
}
static bool F_184 ( struct V_47 * V_47 , unsigned long V_44 )
{
struct V_40 * V_41 = V_47 -> V_61 ;
unsigned long V_112 = 0 ;
enum V_58 V_151 ;
for ( V_151 = 0 ; V_151 <= V_96 ; V_151 ++ )
V_112 += V_41 -> V_49 [ V_151 ] . V_112 ;
if ( V_112 > V_44 )
return true ;
V_112 = 0 ;
for (; V_151 <= V_98 ; V_151 ++ )
V_112 += V_41 -> V_49 [ V_151 ] . V_112 ;
return V_112 == 0 ;
}
static int T_7 F_185 ( char * V_79 )
{
#ifdef F_186
F_187 ( true ) ;
V_152 = true ;
#else
F_90 ( L_9 ) ;
#endif
return 0 ;
}
static void F_188 ( unsigned long V_44 ,
struct V_47 * V_47 , struct V_94 * V_91 )
{
struct V_40 * V_41 = V_47 -> V_61 ;
unsigned long V_112 = 0 ;
enum V_58 V_151 , V_95 = V_96 ;
if ( V_97 == V_93 )
V_95 = V_98 ;
for ( V_151 = 0 ; V_151 <= V_95 ; V_151 ++ )
V_112 += V_41 -> V_49 [ V_151 ] . V_112 ;
if ( F_55 ( V_47 ) <= V_95 && V_44 >= V_112 )
V_91 -> V_99 = F_80 ( V_47 ) ;
else
V_91 -> V_99 = - 1 ;
#ifdef F_103
V_95 = V_100 ;
if ( V_97 == V_101 )
V_95 = V_98 ;
for (; V_151 <= V_95 ; V_151 ++ )
V_112 += V_41 -> V_49 [ V_151 ] . V_112 ;
if ( F_55 ( V_47 ) <= V_95 && V_44 >= V_112 )
V_91 -> V_102 = F_80 ( V_47 ) ;
else
V_91 -> V_102 = - 1 ;
#else
V_91 -> V_102 = V_91 -> V_99 ;
#endif
V_95 = V_98 ;
for (; V_151 <= V_95 ; V_151 ++ )
V_112 += V_41 -> V_49 [ V_151 ] . V_112 ;
if ( V_44 >= V_112 )
V_91 -> V_103 = F_80 ( V_47 ) ;
else
V_91 -> V_103 = - 1 ;
}
static void F_189 ( int V_45 , struct V_94 * V_91 )
{
if ( V_91 -> V_99 >= 0 )
F_190 ( V_45 , V_93 ) ;
if ( ( V_97 != V_93 ) &&
( V_91 -> V_102 >= 0 ) )
F_190 ( V_45 , V_101 ) ;
if ( ( V_97 != V_101 ) &&
( V_91 -> V_103 >= 0 ) )
F_190 ( V_45 , V_97 ) ;
}
static int T_3 F_191 ( unsigned long V_26 ,
unsigned long V_43 , unsigned long V_153 )
{
unsigned long V_42 , V_44 , V_154 ;
long V_155 ;
int V_65 , V_156 , V_157 , V_45 ;
unsigned long V_14 ;
struct V_47 * V_47 ;
struct V_94 V_91 ;
if ( ! F_192 ( V_26 , V_131 ) )
return - V_81 ;
if ( ! F_192 ( V_43 , V_131 ) )
return - V_81 ;
if ( ! F_152 ( V_26 , V_43 ) )
return - V_81 ;
V_47 = F_77 ( F_57 ( V_26 ) ) ;
V_45 = F_80 ( V_47 ) ;
V_44 = V_43 - V_26 ;
if ( F_55 ( V_47 ) <= V_96 && ! F_184 ( V_47 , V_44 ) )
return - V_81 ;
V_65 = F_193 ( V_26 , V_43 ,
V_158 , true ) ;
if ( V_65 )
return V_65 ;
V_91 . V_26 = V_26 ;
V_91 . V_44 = V_44 ;
F_188 ( V_44 , V_47 , & V_91 ) ;
V_65 = V_94 ( V_159 , & V_91 ) ;
V_65 = F_107 ( V_65 ) ;
if ( V_65 )
goto V_160;
V_42 = V_26 ;
V_154 = V_161 + V_153 ;
V_156 = 0 ;
V_157 = 5 ;
V_162:
V_65 = - V_163 ;
if ( F_194 ( V_161 , V_154 ) )
goto V_160;
V_65 = - V_164 ;
if ( F_195 ( V_3 ) )
goto V_160;
V_65 = 0 ;
if ( V_156 ) {
F_196 () ;
F_151 () ;
F_197 ( V_47 ) ;
}
V_42 = F_156 ( V_26 , V_43 ) ;
if ( V_42 ) {
V_65 = F_162 ( V_42 , V_43 ) ;
if ( ! V_65 ) {
V_156 = 1 ;
goto V_162;
} else {
if ( V_65 < 0 )
if ( -- V_157 == 0 )
goto V_160;
F_198 () ;
V_156 = 1 ;
goto V_162;
}
}
F_196 () ;
F_198 () ;
F_197 ( V_47 ) ;
F_199 ( V_26 , V_43 ) ;
V_155 = F_183 ( V_26 , V_43 ) ;
if ( V_155 < 0 ) {
V_65 = - V_143 ;
goto V_160;
}
F_112 ( V_165 L_10 , V_155 ) ;
F_180 ( V_26 , V_43 ) ;
F_200 ( V_26 , V_43 , V_158 ) ;
F_95 ( F_57 ( V_26 ) , - V_155 ) ;
V_47 -> V_112 -= V_155 ;
F_61 ( V_47 -> V_61 , & V_14 ) ;
V_47 -> V_61 -> V_113 -= V_155 ;
F_62 ( V_47 -> V_61 , & V_14 ) ;
F_114 () ;
if ( ! F_108 ( V_47 ) ) {
F_111 ( V_47 ) ;
F_4 ( & V_110 ) ;
F_109 ( NULL , NULL ) ;
F_5 ( & V_110 ) ;
} else
F_113 ( V_47 ) ;
F_189 ( V_45 , & V_91 ) ;
if ( V_91 . V_103 >= 0 )
F_201 ( V_45 ) ;
V_114 = F_116 () ;
F_117 () ;
V_94 ( V_166 , & V_91 ) ;
return 0 ;
V_160:
F_112 ( V_165 L_11 ,
( unsigned long long ) V_26 << V_36 ,
( ( unsigned long long ) V_43 << V_36 ) - 1 ) ;
V_94 ( V_167 , & V_91 ) ;
F_200 ( V_26 , V_43 , V_158 ) ;
return V_65 ;
}
int F_202 ( unsigned long V_26 , unsigned long V_44 )
{
return F_191 ( V_26 , V_26 + V_44 , 120 * V_168 ) ;
}
int F_203 ( unsigned long V_26 , unsigned long V_43 ,
void * V_91 , int (* F_204)( struct V_169 * , void * ) )
{
struct V_169 * V_170 = NULL ;
struct V_31 * V_171 ;
unsigned long V_42 , V_29 ;
int V_65 ;
for ( V_42 = V_26 ; V_42 < V_43 ; V_42 += V_35 ) {
V_29 = F_35 ( V_42 ) ;
if ( ! F_154 ( V_29 ) )
continue;
V_171 = F_36 ( V_29 ) ;
if ( V_170 )
if ( ( V_29 >= V_170 -> V_172 ) &&
( V_29 <= V_170 -> V_173 ) )
continue;
V_170 = F_205 ( V_171 , V_170 ) ;
if ( ! V_170 )
continue;
V_65 = F_204 ( V_170 , V_91 ) ;
if ( V_65 ) {
F_206 ( & V_170 -> V_174 . V_175 ) ;
return V_65 ;
}
}
if ( V_170 )
F_206 ( & V_170 -> V_174 . V_175 ) ;
return 0 ;
}
static int F_207 ( struct V_169 * V_170 , void * V_91 )
{
int V_65 = ! F_208 ( V_170 ) ;
if ( F_8 ( V_65 ) ) {
T_8 V_176 , V_177 ;
V_176 = F_209 ( F_73 ( V_170 -> V_172 ) ) ;
V_177 = F_209 ( F_73 ( V_170 -> V_173 + 1 ) ) - 1 ;
F_90 ( L_12
L_13 ,
& V_176 , & V_177 ) ;
}
return V_65 ;
}
static int F_210 ( T_6 * V_41 )
{
int V_178 ;
F_211 (cpu) {
if ( F_212 ( V_178 ) == V_41 -> V_46 )
return - V_143 ;
}
return 0 ;
}
static void F_213 ( T_6 * V_41 )
{
#ifdef F_214
int V_178 ;
F_215 (cpu)
if ( F_212 ( V_178 ) == V_41 -> V_46 )
F_216 ( V_178 ) ;
#endif
}
static int F_217 ( T_6 * V_41 )
{
int V_65 ;
V_65 = F_210 ( V_41 ) ;
if ( V_65 )
return V_65 ;
F_213 ( V_41 ) ;
return 0 ;
}
void F_218 ( int V_60 )
{
T_6 * V_41 = F_121 ( V_60 ) ;
unsigned long V_26 = V_41 -> V_54 ;
unsigned long V_43 = V_26 + V_41 -> V_70 ;
unsigned long V_42 ;
int V_30 ;
for ( V_42 = V_26 ; V_42 < V_43 ; V_42 += V_35 ) {
unsigned long V_29 = F_35 ( V_42 ) ;
if ( ! F_154 ( V_29 ) )
continue;
if ( F_46 ( V_42 ) != V_60 )
continue;
return;
}
if ( F_217 ( V_41 ) )
return;
F_219 ( V_60 ) ;
F_220 ( V_60 ) ;
for ( V_30 = 0 ; V_30 < V_50 ; V_30 ++ ) {
struct V_47 * V_47 = V_41 -> V_49 + V_30 ;
if ( F_221 ( V_47 -> V_53 ) ) {
F_222 ( V_47 -> V_53 ) ;
V_47 -> V_53 = NULL ;
}
}
}
void T_3 F_223 ( int V_60 , T_1 V_8 , T_1 V_9 )
{
int V_65 ;
F_19 ( F_133 ( V_8 , V_9 ) ) ;
F_11 () ;
V_65 = F_203 ( F_120 ( V_8 ) , F_224 ( V_8 + V_9 - 1 ) , NULL ,
F_207 ) ;
if ( V_65 )
F_225 () ;
F_226 ( V_8 , V_8 + V_9 , L_1 ) ;
F_227 ( V_8 , V_9 ) ;
F_142 ( V_8 , V_9 ) ;
F_228 ( V_8 , V_9 ) ;
F_218 ( V_60 ) ;
F_16 () ;
}
