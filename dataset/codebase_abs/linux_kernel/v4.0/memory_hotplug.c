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
static void F_11 ( void )
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
static void F_16 ( void )
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
return F_59 ( V_47 , V_26 , V_62 ,
V_63 ) ;
return 0 ;
}
static int T_2 F_60 ( struct V_47 * V_64 , struct V_47 * V_65 ,
unsigned long V_26 , unsigned long V_43 )
{
int V_66 ;
unsigned long V_14 ;
unsigned long V_67 ;
V_66 = F_58 ( V_64 , V_26 , V_43 - V_26 ) ;
if ( V_66 )
return V_66 ;
F_61 ( V_64 -> V_61 , & V_14 ) ;
if ( V_43 > F_49 ( V_65 ) )
goto V_68;
if ( V_26 > V_65 -> V_56 )
goto V_68;
if ( V_43 <= V_65 -> V_56 )
goto V_68;
if ( ! F_50 ( V_64 ) )
V_67 = V_64 -> V_56 ;
else
V_67 = V_26 ;
F_53 ( V_64 , V_67 , V_43 ) ;
F_53 ( V_65 , V_43 , F_49 ( V_65 ) ) ;
F_62 ( V_64 -> V_61 , & V_14 ) ;
F_54 ( V_64 , V_26 , V_43 ) ;
return 0 ;
V_68:
F_62 ( V_64 -> V_61 , & V_14 ) ;
return - 1 ;
}
static int T_2 F_63 ( struct V_47 * V_64 , struct V_47 * V_65 ,
unsigned long V_26 , unsigned long V_43 )
{
int V_66 ;
unsigned long V_14 ;
unsigned long V_69 ;
V_66 = F_58 ( V_65 , V_26 , V_43 - V_26 ) ;
if ( V_66 )
return V_66 ;
F_61 ( V_64 -> V_61 , & V_14 ) ;
if ( V_64 -> V_56 > V_26 )
goto V_68;
if ( F_49 ( V_64 ) > V_43 )
goto V_68;
if ( V_26 >= F_49 ( V_64 ) )
goto V_68;
if ( ! F_50 ( V_65 ) )
V_69 = F_49 ( V_65 ) ;
else
V_69 = V_43 ;
F_53 ( V_64 , V_64 -> V_56 , V_26 ) ;
F_53 ( V_65 , V_26 , V_69 ) ;
F_62 ( V_64 -> V_61 , & V_14 ) ;
F_54 ( V_65 , V_26 , V_43 ) ;
return 0 ;
V_68:
F_62 ( V_64 -> V_61 , & V_14 ) ;
return - 1 ;
}
static void T_2 F_64 ( struct V_40 * V_41 , unsigned long V_26 ,
unsigned long V_43 )
{
unsigned long V_70 = F_45 ( V_41 ) ;
if ( ! V_41 -> V_71 || V_26 < V_41 -> V_54 )
V_41 -> V_54 = V_26 ;
V_41 -> V_71 = F_51 ( V_70 , V_43 ) -
V_41 -> V_54 ;
}
static int T_2 F_65 ( struct V_47 * V_47 , unsigned long V_72 )
{
struct V_40 * V_41 = V_47 -> V_61 ;
int V_44 = V_35 ;
int V_60 = V_41 -> V_46 ;
int V_58 ;
unsigned long V_14 ;
int V_66 ;
V_58 = V_47 - V_41 -> V_49 ;
V_66 = F_58 ( V_47 , V_72 , V_44 ) ;
if ( V_66 )
return V_66 ;
F_61 ( V_47 -> V_61 , & V_14 ) ;
F_47 ( V_47 , V_72 , V_72 + V_44 ) ;
F_64 ( V_47 -> V_61 , V_72 ,
V_72 + V_44 ) ;
F_62 ( V_47 -> V_61 , & V_14 ) ;
F_66 ( V_44 , V_60 , V_58 ,
V_72 , V_63 ) ;
return 0 ;
}
static int T_2 F_67 ( int V_60 , struct V_47 * V_47 ,
unsigned long V_72 )
{
int V_66 ;
if ( F_41 ( V_72 ) )
return - V_73 ;
V_66 = F_68 ( V_47 , V_72 ) ;
if ( V_66 < 0 )
return V_66 ;
V_66 = F_65 ( V_47 , V_72 ) ;
if ( V_66 < 0 )
return V_66 ;
return F_69 ( V_60 , F_70 ( V_72 ) ) ;
}
int T_3 F_71 ( int V_60 , struct V_47 * V_47 , unsigned long V_72 ,
unsigned long V_44 )
{
unsigned long V_30 ;
int V_74 = 0 ;
int V_75 , V_76 ;
V_75 = F_35 ( V_72 ) ;
V_76 = F_35 ( V_72 + V_44 - 1 ) ;
for ( V_30 = V_75 ; V_30 <= V_76 ; V_30 ++ ) {
V_74 = F_67 ( V_60 , V_47 , V_30 << V_77 ) ;
if ( V_74 && ( V_74 != - V_73 ) )
break;
V_74 = 0 ;
}
return V_74 ;
}
static int F_72 ( int V_60 , struct V_47 * V_47 ,
unsigned long V_26 ,
unsigned long V_43 )
{
struct V_31 * V_32 ;
for (; V_26 < V_43 ; V_26 += V_35 ) {
V_32 = F_70 ( V_26 ) ;
if ( F_8 ( ! F_73 ( V_32 ) ) )
continue;
if ( F_8 ( F_46 ( V_26 ) != V_60 ) )
continue;
if ( V_47 && V_47 != F_74 ( F_57 ( V_26 ) ) )
continue;
return V_26 ;
}
return 0 ;
}
static int F_75 ( int V_60 , struct V_47 * V_47 ,
unsigned long V_26 ,
unsigned long V_43 )
{
struct V_31 * V_32 ;
unsigned long V_42 ;
V_42 = V_43 - 1 ;
for (; V_42 >= V_26 ; V_42 -= V_35 ) {
V_32 = F_70 ( V_42 ) ;
if ( F_8 ( ! F_73 ( V_32 ) ) )
continue;
if ( F_8 ( F_46 ( V_42 ) != V_60 ) )
continue;
if ( V_47 && V_47 != F_74 ( F_57 ( V_42 ) ) )
continue;
return V_42 ;
}
return 0 ;
}
static void F_76 ( struct V_47 * V_47 , unsigned long V_26 ,
unsigned long V_43 )
{
unsigned long V_56 = V_47 -> V_56 ;
unsigned long V_78 = F_49 ( V_47 ) ;
unsigned long F_49 = V_78 ;
unsigned long V_42 ;
struct V_31 * V_32 ;
int V_60 = F_77 ( V_47 ) ;
F_48 ( V_47 ) ;
if ( V_56 == V_26 ) {
V_42 = F_72 ( V_60 , V_47 , V_43 ,
F_49 ) ;
if ( V_42 ) {
V_47 -> V_56 = V_42 ;
V_47 -> V_57 = F_49 - V_42 ;
}
} else if ( F_49 == V_43 ) {
V_42 = F_75 ( V_60 , V_47 , V_56 ,
V_26 ) ;
if ( V_42 )
V_47 -> V_57 = V_42 - V_56 + 1 ;
}
V_42 = V_56 ;
for (; V_42 < F_49 ; V_42 += V_35 ) {
V_32 = F_70 ( V_42 ) ;
if ( F_8 ( ! F_73 ( V_32 ) ) )
continue;
if ( F_74 ( F_57 ( V_42 ) ) != V_47 )
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
static void F_78 ( struct V_40 * V_41 ,
unsigned long V_26 , unsigned long V_43 )
{
unsigned long V_79 = V_41 -> V_54 ;
unsigned long V_80 = F_45 ( V_41 ) ;
unsigned long F_45 = V_80 ;
unsigned long V_42 ;
struct V_31 * V_32 ;
int V_60 = V_41 -> V_46 ;
if ( V_79 == V_26 ) {
V_42 = F_72 ( V_60 , NULL , V_43 ,
F_45 ) ;
if ( V_42 ) {
V_41 -> V_54 = V_42 ;
V_41 -> V_71 = F_45 - V_42 ;
}
} else if ( F_45 == V_43 ) {
V_42 = F_75 ( V_60 , NULL , V_79 ,
V_26 ) ;
if ( V_42 )
V_41 -> V_71 = V_42 - V_79 + 1 ;
}
V_42 = V_79 ;
for (; V_42 < F_45 ; V_42 += V_35 ) {
V_32 = F_70 ( V_42 ) ;
if ( F_8 ( ! F_73 ( V_32 ) ) )
continue;
if ( F_46 ( V_42 ) != V_60 )
continue;
if ( V_26 == V_42 )
continue;
return;
}
V_41 -> V_54 = 0 ;
V_41 -> V_71 = 0 ;
}
static void F_79 ( struct V_47 * V_47 , unsigned long V_26 )
{
struct V_40 * V_41 = V_47 -> V_61 ;
int V_44 = V_35 ;
int V_58 ;
unsigned long V_14 ;
V_58 = V_47 - V_41 -> V_49 ;
F_61 ( V_47 -> V_61 , & V_14 ) ;
F_76 ( V_47 , V_26 , V_26 + V_44 ) ;
F_78 ( V_41 , V_26 , V_26 + V_44 ) ;
F_62 ( V_47 -> V_61 , & V_14 ) ;
}
static int F_80 ( struct V_47 * V_47 , struct V_31 * V_32 )
{
unsigned long V_26 ;
int V_81 ;
int V_66 = - V_82 ;
if ( ! F_73 ( V_32 ) )
return V_66 ;
V_66 = F_81 ( V_32 ) ;
if ( V_66 )
return V_66 ;
V_81 = F_82 ( V_32 ) ;
V_26 = F_83 ( V_81 ) ;
F_79 ( V_47 , V_26 ) ;
F_84 ( V_47 , V_32 ) ;
return 0 ;
}
int F_85 ( struct V_47 * V_47 , unsigned long V_72 ,
unsigned long V_44 )
{
unsigned long V_30 ;
int V_83 ;
T_4 V_8 , V_9 ;
int V_66 = 0 ;
F_19 ( V_72 & ~ V_84 ) ;
F_19 ( V_44 % V_35 ) ;
V_8 = V_72 << V_36 ;
V_9 = V_44 * V_85 ;
V_66 = F_86 ( & V_17 , V_8 , V_9 ) ;
if ( V_66 ) {
T_4 V_86 = V_8 + V_9 - 1 ;
F_87 ( L_3 ,
& V_8 , & V_86 , V_66 ) ;
}
V_83 = V_44 / V_35 ;
for ( V_30 = 0 ; V_30 < V_83 ; V_30 ++ ) {
unsigned long V_42 = V_72 + V_30 * V_35 ;
V_66 = F_80 ( V_47 , F_70 ( V_42 ) ) ;
if ( V_66 )
break;
}
return V_66 ;
}
int F_88 ( T_5 V_87 )
{
int V_88 = - V_82 ;
F_1 () ;
F_4 ( & V_89 ) ;
if ( V_90 == V_91 ) {
V_90 = V_87 ;
V_88 = 0 ;
}
F_5 ( & V_89 ) ;
F_6 () ;
return V_88 ;
}
int F_89 ( T_5 V_87 )
{
int V_88 = - V_82 ;
F_1 () ;
F_4 ( & V_89 ) ;
if ( V_90 == V_87 ) {
V_90 = V_91 ;
V_88 = 0 ;
}
F_5 ( & V_89 ) ;
F_6 () ;
return V_88 ;
}
void F_90 ( struct V_19 * V_19 )
{
}
void F_91 ( struct V_19 * V_19 )
{
F_92 ( V_19 , 1 ) ;
}
void F_93 ( struct V_19 * V_19 )
{
F_94 ( V_19 ) ;
}
static void V_91 ( struct V_19 * V_19 )
{
F_90 ( V_19 ) ;
F_91 ( V_19 ) ;
F_93 ( V_19 ) ;
}
static int F_95 ( unsigned long V_26 , unsigned long V_44 ,
void * V_92 )
{
unsigned long V_30 ;
unsigned long V_93 = * ( unsigned long * ) V_92 ;
struct V_19 * V_19 ;
if ( F_96 ( F_57 ( V_26 ) ) )
for ( V_30 = 0 ; V_30 < V_44 ; V_30 ++ ) {
V_19 = F_57 ( V_26 + V_30 ) ;
(* V_90)( V_19 ) ;
V_93 ++ ;
}
* ( unsigned long * ) V_92 = V_93 ;
return 0 ;
}
static bool F_97 ( struct V_47 * V_47 )
{
return true ;
}
static bool F_97 ( struct V_47 * V_47 )
{
return F_98 ( F_77 ( V_47 ) , V_94 ) ;
}
static void F_99 ( unsigned long V_44 ,
struct V_47 * V_47 , struct V_95 * V_92 )
{
int V_60 = F_77 ( V_47 ) ;
enum V_58 V_96 = V_97 ;
if ( V_98 == V_94 )
V_96 = V_99 ;
if ( F_55 ( V_47 ) <= V_96 && ! F_98 ( V_60 , V_94 ) )
V_92 -> V_100 = V_60 ;
else
V_92 -> V_100 = - 1 ;
#ifdef F_100
V_96 = V_101 ;
if ( V_98 == V_102 )
V_96 = V_99 ;
if ( F_55 ( V_47 ) <= V_96 && ! F_98 ( V_60 , V_102 ) )
V_92 -> V_103 = V_60 ;
else
V_92 -> V_103 = - 1 ;
#else
V_92 -> V_103 = V_92 -> V_100 ;
#endif
if ( ! F_98 ( V_60 , V_98 ) )
V_92 -> V_104 = V_60 ;
else
V_92 -> V_104 = - 1 ;
}
static void F_101 ( int V_45 , struct V_95 * V_92 )
{
if ( V_92 -> V_100 >= 0 )
F_102 ( V_45 , V_94 ) ;
if ( V_92 -> V_103 >= 0 )
F_102 ( V_45 , V_102 ) ;
F_102 ( V_45 , V_98 ) ;
}
int T_3 F_103 ( unsigned long V_42 , unsigned long V_44 , int V_105 )
{
unsigned long V_14 ;
unsigned long V_93 = 0 ;
struct V_47 * V_47 ;
int V_106 = 0 ;
int V_60 ;
int V_66 ;
struct V_95 V_92 ;
F_11 () ;
V_47 = F_74 ( F_57 ( V_42 ) ) ;
V_66 = - V_82 ;
if ( ( F_55 ( V_47 ) > V_97 ||
V_105 == V_107 ) &&
! F_97 ( V_47 ) )
goto V_108;
if ( V_105 == V_109 &&
F_55 ( V_47 ) == V_99 ) {
if ( F_60 ( V_47 - 1 , V_47 , V_42 , V_42 + V_44 ) )
goto V_108;
}
if ( V_105 == V_107 &&
F_55 ( V_47 ) == V_99 - 1 ) {
if ( F_63 ( V_47 , V_47 + 1 , V_42 , V_42 + V_44 ) )
goto V_108;
}
V_47 = F_74 ( F_57 ( V_42 ) ) ;
V_92 . V_26 = V_42 ;
V_92 . V_44 = V_44 ;
F_99 ( V_44 , V_47 , & V_92 ) ;
V_60 = F_46 ( V_42 ) ;
V_66 = V_95 ( V_110 , & V_92 ) ;
V_66 = F_104 ( V_66 ) ;
if ( V_66 ) {
V_95 ( V_111 , & V_92 ) ;
goto V_108;
}
F_4 ( & V_112 ) ;
if ( ! F_105 ( V_47 ) ) {
V_106 = 1 ;
F_106 ( NULL , V_47 ) ;
}
V_66 = F_107 ( V_42 , V_44 , & V_93 ,
F_95 ) ;
if ( V_66 ) {
if ( V_106 )
F_108 ( V_47 ) ;
F_5 ( & V_112 ) ;
F_109 ( V_113 L_4 ,
( unsigned long long ) V_42 << V_36 ,
( ( ( unsigned long long ) V_42 + V_44 )
<< V_36 ) - 1 ) ;
V_95 ( V_111 , & V_92 ) ;
goto V_108;
}
V_47 -> V_114 += V_93 ;
F_61 ( V_47 -> V_61 , & V_14 ) ;
V_47 -> V_61 -> V_115 += V_93 ;
F_62 ( V_47 -> V_61 , & V_14 ) ;
if ( V_93 ) {
F_101 ( F_77 ( V_47 ) , & V_92 ) ;
if ( V_106 )
F_106 ( NULL , NULL ) ;
else
F_110 ( V_47 ) ;
}
F_5 ( & V_112 ) ;
F_111 () ;
if ( V_93 )
F_112 ( F_77 ( V_47 ) ) ;
V_116 = F_113 () ;
F_114 () ;
if ( V_93 )
V_95 ( V_117 , & V_92 ) ;
V_108:
F_16 () ;
return V_66 ;
}
static void F_115 ( T_6 * V_41 )
{
struct V_47 * V_78 ;
for ( V_78 = V_41 -> V_49 ; V_78 < V_41 -> V_49 + V_50 ; V_78 ++ )
V_78 -> V_114 = 0 ;
V_41 -> V_115 = 0 ;
}
static T_6 T_3 * F_116 ( int V_60 , T_1 V_8 )
{
struct V_40 * V_41 ;
unsigned long V_118 [ V_50 ] = { 0 } ;
unsigned long V_119 [ V_50 ] = { 0 } ;
unsigned long V_26 = F_117 ( V_8 ) ;
V_41 = F_118 ( V_60 ) ;
if ( ! V_41 ) {
V_41 = F_119 ( V_60 ) ;
if ( ! V_41 )
return NULL ;
F_120 ( V_60 , V_41 ) ;
} else {
V_41 -> V_120 = 0 ;
V_41 -> V_121 = 0 ;
}
F_121 ( V_60 , V_118 , V_26 , V_119 ) ;
F_4 ( & V_112 ) ;
F_106 ( V_41 , NULL ) ;
F_5 ( & V_112 ) ;
F_122 ( V_41 ) ;
F_115 ( V_41 ) ;
return V_41 ;
}
static void F_123 ( int V_60 , T_6 * V_41 )
{
F_120 ( V_60 , NULL ) ;
F_124 ( V_41 ) ;
return;
}
int F_125 ( int V_60 )
{
T_6 * V_41 ;
int V_66 ;
if ( F_126 ( V_60 ) )
return 0 ;
F_11 () ;
V_41 = F_116 ( V_60 , 0 ) ;
if ( ! V_41 ) {
F_127 ( L_5 , V_60 ) ;
V_66 = - V_122 ;
goto V_108;
}
F_128 ( V_60 ) ;
V_66 = F_129 ( V_60 ) ;
F_19 ( V_66 ) ;
if ( V_41 -> V_123 -> V_124 -> V_47 == NULL ) {
F_4 ( & V_112 ) ;
F_106 ( NULL , NULL ) ;
F_5 ( & V_112 ) ;
}
V_108:
F_16 () ;
return V_66 ;
}
static int F_130 ( T_1 V_8 , T_1 V_9 )
{
T_1 V_26 = F_117 ( V_8 ) ;
T_1 V_44 = V_9 >> V_36 ;
if ( ( V_26 & ~ V_84 ) ||
( V_44 % V_35 ) || ( ! V_44 ) ) {
F_127 ( L_6 ,
( unsigned long long ) V_8 ,
( unsigned long long ) V_9 ) ;
return - V_82 ;
}
return 0 ;
}
static int F_131 ( int V_60 , T_1 V_8 , T_1 V_9 )
{
unsigned long V_26 = V_8 >> V_36 ;
T_6 * V_41 = F_118 ( V_60 ) ;
struct V_47 * V_125 = V_41 -> V_49 + V_99 ;
if ( F_50 ( V_125 ) )
return 0 ;
if ( V_125 -> V_56 <= V_26 )
return 1 ;
return 0 ;
}
int F_132 ( int V_60 , T_1 V_8 , T_1 V_9 , int V_126 )
{
if ( F_131 ( V_60 , V_8 , V_9 ) )
return V_99 ;
return V_126 ;
}
int T_3 F_133 ( int V_60 , T_1 V_8 , T_1 V_9 )
{
T_6 * V_41 = NULL ;
bool V_127 ;
bool V_128 ;
struct V_7 * V_10 ;
int V_66 ;
V_66 = F_130 ( V_8 , V_9 ) ;
if ( V_66 )
return V_66 ;
V_10 = F_17 ( V_8 , V_9 ) ;
V_66 = - V_73 ;
if ( ! V_10 )
return V_66 ;
{
void * V_80 = F_118 ( V_60 ) ;
V_127 = ! V_80 ;
}
F_11 () ;
V_128 = ! F_126 ( V_60 ) ;
if ( V_128 ) {
V_41 = F_116 ( V_60 , V_8 ) ;
V_66 = - V_122 ;
if ( ! V_41 )
goto error;
}
V_66 = F_134 ( V_60 , V_8 , V_9 ) ;
if ( V_66 < 0 )
goto error;
F_128 ( V_60 ) ;
if ( V_128 ) {
V_66 = F_129 ( V_60 ) ;
F_19 ( V_66 ) ;
}
F_135 ( V_8 , V_8 + V_9 , L_1 ) ;
goto V_108;
error:
if ( V_127 )
F_123 ( V_60 , V_41 ) ;
F_23 ( V_10 ) ;
V_108:
F_16 () ;
return V_66 ;
}
static inline int F_136 ( struct V_19 * V_19 )
{
return F_137 ( V_19 ) && F_138 ( V_19 ) >= V_129 ;
}
static struct V_19 * F_139 ( struct V_19 * V_19 )
{
F_19 ( F_140 ( V_19 ) & ( V_130 - 1 ) ) ;
if ( F_136 ( V_19 ) ) {
int V_131 ;
V_131 = F_138 ( V_19 ) ;
if ( ( V_131 < V_132 ) && ( V_131 >= V_129 ) )
return V_19 + ( 1 << V_131 ) ;
}
return V_19 + V_130 ;
}
int F_141 ( unsigned long V_26 , unsigned long V_44 )
{
struct V_19 * V_19 = F_57 ( V_26 ) ;
struct V_19 * V_133 = V_19 + V_44 ;
for (; V_19 < V_133 ; V_19 = F_139 ( V_19 ) ) {
if ( ! F_142 ( V_19 ) )
return 0 ;
F_143 () ;
}
return 1 ;
}
int F_144 ( unsigned long V_26 , unsigned long V_43 )
{
unsigned long V_42 ;
struct V_47 * V_47 = NULL ;
struct V_19 * V_19 ;
int V_30 ;
for ( V_42 = V_26 ;
V_42 < V_43 ;
V_42 += V_134 ) {
V_30 = 0 ;
while ( ( V_30 < V_134 ) && ! F_145 ( V_42 + V_30 ) )
V_30 ++ ;
if ( V_30 == V_134 )
continue;
V_19 = F_57 ( V_42 + V_30 ) ;
if ( V_47 && F_74 ( V_19 ) != V_47 )
return 0 ;
V_47 = F_74 ( V_19 ) ;
}
return 1 ;
}
static unsigned long F_146 ( unsigned long V_8 , unsigned long V_13 )
{
unsigned long V_42 ;
struct V_19 * V_19 ;
for ( V_42 = V_8 ; V_42 < V_13 ; V_42 ++ ) {
if ( F_41 ( V_42 ) ) {
V_19 = F_57 ( V_42 ) ;
if ( F_147 ( V_19 ) )
return V_42 ;
if ( F_148 ( V_19 ) ) {
if ( F_149 ( V_19 ) )
return V_42 ;
else
V_42 = F_150 ( V_42 + 1 ,
1 << F_151 ( V_19 ) ) - 1 ;
}
}
}
return 0 ;
}
static int
F_152 ( unsigned long V_26 , unsigned long V_43 )
{
unsigned long V_42 ;
struct V_19 * V_19 ;
int V_135 = V_136 ;
int V_137 = 0 ;
int V_66 = 0 ;
F_153 ( V_138 ) ;
for ( V_42 = V_26 ; V_42 < V_43 && V_135 > 0 ; V_42 ++ ) {
if ( ! F_41 ( V_42 ) )
continue;
V_19 = F_57 ( V_42 ) ;
if ( F_148 ( V_19 ) ) {
struct V_19 * V_139 = F_154 ( V_19 ) ;
V_42 = F_140 ( V_139 ) + ( 1 << F_151 ( V_139 ) ) - 1 ;
if ( F_151 ( V_139 ) > V_77 ) {
V_66 = - V_140 ;
break;
}
if ( F_155 ( V_19 , & V_138 ) )
V_135 -= 1 << F_151 ( V_139 ) ;
continue;
}
if ( ! F_156 ( V_19 ) )
continue;
V_66 = F_157 ( V_19 ) ;
if ( ! V_66 ) {
F_158 ( V_19 ) ;
F_159 ( & V_19 -> V_20 , & V_138 ) ;
V_135 -- ;
F_160 ( V_19 , V_141 +
F_161 ( V_19 ) ) ;
} else {
#ifdef F_162
F_109 ( V_142 L_7 ,
V_42 ) ;
F_163 ( V_19 , L_8 ) ;
#endif
F_158 ( V_19 ) ;
if ( F_164 ( V_19 ) ) {
V_137 ++ ;
V_66 = - V_140 ;
break;
}
}
}
if ( ! F_165 ( & V_138 ) ) {
if ( V_137 ) {
F_166 ( & V_138 ) ;
goto V_108;
}
V_66 = F_167 ( & V_138 , V_143 , NULL , 0 ,
V_144 , V_145 ) ;
if ( V_66 )
F_166 ( & V_138 ) ;
}
V_108:
return V_66 ;
}
static int
F_168 ( unsigned long V_8 , unsigned long V_44 ,
void * V_146 )
{
F_169 ( V_8 , V_8 + V_44 ) ;
return 0 ;
}
static void
F_170 ( unsigned long V_26 , unsigned long V_43 )
{
F_107 ( V_26 , V_43 - V_26 , NULL ,
F_168 ) ;
}
static int
F_171 ( unsigned long V_26 , unsigned long V_44 ,
void * V_146 )
{
int V_66 ;
long V_147 = * ( long * ) V_146 ;
V_66 = F_172 ( V_26 , V_26 + V_44 , true ) ;
V_147 = V_44 ;
if ( ! V_66 )
* ( long * ) V_146 += V_147 ;
return V_66 ;
}
static long
F_173 ( unsigned long V_26 , unsigned long V_43 )
{
long V_147 = 0 ;
int V_66 ;
V_66 = F_107 ( V_26 , V_43 - V_26 , & V_147 ,
F_171 ) ;
if ( V_66 < 0 )
V_147 = ( long ) V_66 ;
return V_147 ;
}
static bool F_174 ( struct V_47 * V_47 , unsigned long V_44 )
{
return true ;
}
static bool F_174 ( struct V_47 * V_47 , unsigned long V_44 )
{
struct V_40 * V_41 = V_47 -> V_61 ;
unsigned long V_114 = 0 ;
enum V_58 V_148 ;
for ( V_148 = 0 ; V_148 <= V_97 ; V_148 ++ )
V_114 += V_41 -> V_49 [ V_148 ] . V_114 ;
if ( V_114 > V_44 )
return true ;
V_114 = 0 ;
for (; V_148 <= V_99 ; V_148 ++ )
V_114 += V_41 -> V_49 [ V_148 ] . V_114 ;
return V_114 == 0 ;
}
static int T_7 F_175 ( char * V_80 )
{
#ifdef F_176
F_177 ( true ) ;
V_149 = true ;
#else
F_87 ( L_9 ) ;
#endif
return 0 ;
}
static void F_178 ( unsigned long V_44 ,
struct V_47 * V_47 , struct V_95 * V_92 )
{
struct V_40 * V_41 = V_47 -> V_61 ;
unsigned long V_114 = 0 ;
enum V_58 V_148 , V_96 = V_97 ;
if ( V_98 == V_94 )
V_96 = V_99 ;
for ( V_148 = 0 ; V_148 <= V_96 ; V_148 ++ )
V_114 += V_41 -> V_49 [ V_148 ] . V_114 ;
if ( F_55 ( V_47 ) <= V_96 && V_44 >= V_114 )
V_92 -> V_100 = F_77 ( V_47 ) ;
else
V_92 -> V_100 = - 1 ;
#ifdef F_100
V_96 = V_101 ;
if ( V_98 == V_102 )
V_96 = V_99 ;
for (; V_148 <= V_96 ; V_148 ++ )
V_114 += V_41 -> V_49 [ V_148 ] . V_114 ;
if ( F_55 ( V_47 ) <= V_96 && V_44 >= V_114 )
V_92 -> V_103 = F_77 ( V_47 ) ;
else
V_92 -> V_103 = - 1 ;
#else
V_92 -> V_103 = V_92 -> V_100 ;
#endif
V_96 = V_99 ;
for (; V_148 <= V_96 ; V_148 ++ )
V_114 += V_41 -> V_49 [ V_148 ] . V_114 ;
if ( V_44 >= V_114 )
V_92 -> V_104 = F_77 ( V_47 ) ;
else
V_92 -> V_104 = - 1 ;
}
static void F_179 ( int V_45 , struct V_95 * V_92 )
{
if ( V_92 -> V_100 >= 0 )
F_180 ( V_45 , V_94 ) ;
if ( ( V_98 != V_94 ) &&
( V_92 -> V_103 >= 0 ) )
F_180 ( V_45 , V_102 ) ;
if ( ( V_98 != V_102 ) &&
( V_92 -> V_104 >= 0 ) )
F_180 ( V_45 , V_98 ) ;
}
static int T_3 F_181 ( unsigned long V_26 ,
unsigned long V_43 , unsigned long V_150 )
{
unsigned long V_42 , V_44 , V_151 ;
long V_152 ;
int V_66 , V_153 , V_154 , V_45 ;
unsigned long V_14 ;
struct V_47 * V_47 ;
struct V_95 V_92 ;
if ( ! F_182 ( V_26 , V_130 ) )
return - V_82 ;
if ( ! F_182 ( V_43 , V_130 ) )
return - V_82 ;
if ( ! F_144 ( V_26 , V_43 ) )
return - V_82 ;
F_11 () ;
V_47 = F_74 ( F_57 ( V_26 ) ) ;
V_45 = F_77 ( V_47 ) ;
V_44 = V_43 - V_26 ;
V_66 = - V_82 ;
if ( F_55 ( V_47 ) <= V_97 && ! F_174 ( V_47 , V_44 ) )
goto V_108;
V_66 = F_183 ( V_26 , V_43 ,
V_155 , true ) ;
if ( V_66 )
goto V_108;
V_92 . V_26 = V_26 ;
V_92 . V_44 = V_44 ;
F_178 ( V_44 , V_47 , & V_92 ) ;
V_66 = V_95 ( V_156 , & V_92 ) ;
V_66 = F_104 ( V_66 ) ;
if ( V_66 )
goto V_157;
V_42 = V_26 ;
V_151 = V_158 + V_150 ;
V_153 = 0 ;
V_154 = 5 ;
V_159:
V_66 = - V_160 ;
if ( F_184 ( V_158 , V_151 ) )
goto V_157;
V_66 = - V_161 ;
if ( F_185 ( V_3 ) )
goto V_157;
V_66 = 0 ;
if ( V_153 ) {
F_186 () ;
F_143 () ;
F_187 ( V_47 ) ;
}
V_42 = F_146 ( V_26 , V_43 ) ;
if ( V_42 ) {
V_66 = F_152 ( V_42 , V_43 ) ;
if ( ! V_66 ) {
V_153 = 1 ;
goto V_159;
} else {
if ( V_66 < 0 )
if ( -- V_154 == 0 )
goto V_157;
F_188 () ;
V_153 = 1 ;
goto V_159;
}
}
F_186 () ;
F_188 () ;
F_187 ( V_47 ) ;
F_189 ( V_26 , V_43 ) ;
V_152 = F_173 ( V_26 , V_43 ) ;
if ( V_152 < 0 ) {
V_66 = - V_140 ;
goto V_157;
}
F_109 ( V_162 L_10 , V_152 ) ;
F_170 ( V_26 , V_43 ) ;
F_190 ( V_26 , V_43 , V_155 ) ;
F_92 ( F_57 ( V_26 ) , - V_152 ) ;
V_47 -> V_114 -= V_152 ;
F_61 ( V_47 -> V_61 , & V_14 ) ;
V_47 -> V_61 -> V_115 -= V_152 ;
F_62 ( V_47 -> V_61 , & V_14 ) ;
F_111 () ;
if ( ! F_105 ( V_47 ) ) {
F_108 ( V_47 ) ;
F_4 ( & V_112 ) ;
F_106 ( NULL , NULL ) ;
F_5 ( & V_112 ) ;
} else
F_110 ( V_47 ) ;
F_179 ( V_45 , & V_92 ) ;
if ( V_92 . V_104 >= 0 )
F_191 ( V_45 ) ;
V_116 = F_113 () ;
F_114 () ;
V_95 ( V_163 , & V_92 ) ;
F_16 () ;
return 0 ;
V_157:
F_109 ( V_162 L_11 ,
( unsigned long long ) V_26 << V_36 ,
( ( unsigned long long ) V_43 << V_36 ) - 1 ) ;
V_95 ( V_164 , & V_92 ) ;
F_190 ( V_26 , V_43 , V_155 ) ;
V_108:
F_16 () ;
return V_66 ;
}
int F_192 ( unsigned long V_26 , unsigned long V_44 )
{
return F_181 ( V_26 , V_26 + V_44 , 120 * V_165 ) ;
}
int F_193 ( unsigned long V_26 , unsigned long V_43 ,
void * V_92 , int (* F_194)( struct V_166 * , void * ) )
{
struct V_166 * V_167 = NULL ;
struct V_31 * V_168 ;
unsigned long V_42 , V_29 ;
int V_66 ;
for ( V_42 = V_26 ; V_42 < V_43 ; V_42 += V_35 ) {
V_29 = F_35 ( V_42 ) ;
if ( ! F_195 ( V_29 ) )
continue;
V_168 = F_36 ( V_29 ) ;
if ( V_167 )
if ( ( V_29 >= V_167 -> V_169 ) &&
( V_29 <= V_167 -> V_170 ) )
continue;
V_167 = F_196 ( V_168 , V_167 ) ;
if ( ! V_167 )
continue;
V_66 = F_194 ( V_167 , V_92 ) ;
if ( V_66 ) {
F_197 ( & V_167 -> V_171 . V_172 ) ;
return V_66 ;
}
}
if ( V_167 )
F_197 ( & V_167 -> V_171 . V_172 ) ;
return 0 ;
}
static int F_198 ( struct V_166 * V_167 , void * V_92 )
{
int V_66 = ! F_199 ( V_167 ) ;
if ( F_8 ( V_66 ) ) {
T_8 V_173 , V_174 ;
V_173 = F_200 ( F_83 ( V_167 -> V_169 ) ) ;
V_174 = F_200 ( F_83 ( V_167 -> V_170 + 1 ) ) - 1 ;
F_87 ( L_12
L_13 ,
& V_173 , & V_174 ) ;
}
return V_66 ;
}
static int F_201 ( T_6 * V_41 )
{
int V_175 ;
F_202 (cpu) {
if ( F_203 ( V_175 ) == V_41 -> V_46 )
return - V_140 ;
}
return 0 ;
}
static void F_204 ( T_6 * V_41 )
{
#ifdef F_205
int V_175 ;
F_206 (cpu)
if ( F_203 ( V_175 ) == V_41 -> V_46 )
F_207 ( V_175 ) ;
#endif
}
static int F_208 ( T_6 * V_41 )
{
int V_66 ;
V_66 = F_201 ( V_41 ) ;
if ( V_66 )
return V_66 ;
F_204 ( V_41 ) ;
return 0 ;
}
void F_209 ( int V_60 )
{
T_6 * V_41 = F_118 ( V_60 ) ;
unsigned long V_26 = V_41 -> V_54 ;
unsigned long V_43 = V_26 + V_41 -> V_71 ;
unsigned long V_42 ;
int V_30 ;
for ( V_42 = V_26 ; V_42 < V_43 ; V_42 += V_35 ) {
unsigned long V_29 = F_35 ( V_42 ) ;
if ( ! F_195 ( V_29 ) )
continue;
if ( F_46 ( V_42 ) != V_60 )
continue;
return;
}
if ( F_208 ( V_41 ) )
return;
F_210 ( V_60 ) ;
F_211 ( V_60 ) ;
for ( V_30 = 0 ; V_30 < V_50 ; V_30 ++ ) {
struct V_47 * V_47 = V_41 -> V_49 + V_30 ;
if ( F_212 ( V_47 -> V_53 ) )
F_213 ( V_47 -> V_53 ) ;
}
}
void T_3 F_214 ( int V_60 , T_1 V_8 , T_1 V_9 )
{
int V_66 ;
F_19 ( F_130 ( V_8 , V_9 ) ) ;
F_11 () ;
V_66 = F_193 ( F_117 ( V_8 ) , F_215 ( V_8 + V_9 - 1 ) , NULL ,
F_198 ) ;
if ( V_66 )
F_216 () ;
F_217 ( V_8 , V_8 + V_9 , L_1 ) ;
F_218 ( V_8 , V_9 ) ;
F_209 ( V_60 ) ;
F_16 () ;
}
