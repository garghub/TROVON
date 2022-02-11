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
static void F_47 ( struct V_47 * V_47 , unsigned long V_26 ,
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
static int T_2 F_58 ( struct V_47 * V_47 ,
unsigned long V_26 , unsigned long V_62 )
{
if ( ! F_44 ( V_47 ) )
return F_59 ( V_47 , V_26 , V_62 ,
V_63 ) ;
return 0 ;
}
static int T_3 F_60 ( struct V_47 * V_64 , struct V_47 * V_65 ,
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
static int T_3 F_63 ( struct V_47 * V_64 , struct V_47 * V_65 ,
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
static void F_64 ( struct V_40 * V_41 , unsigned long V_26 ,
unsigned long V_43 )
{
unsigned long V_70 = F_45 ( V_41 ) ;
if ( ! V_41 -> V_71 || V_26 < V_41 -> V_54 )
V_41 -> V_54 = V_26 ;
V_41 -> V_71 = F_51 ( V_70 , V_43 ) -
V_41 -> V_54 ;
}
static int T_3 F_65 ( struct V_47 * V_47 , unsigned long V_72 )
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
static int T_3 F_67 ( int V_60 , struct V_47 * V_47 ,
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
int T_2 F_71 ( int V_60 , struct V_47 * V_47 , unsigned long V_72 ,
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
int T_2 F_103 ( unsigned long V_42 , unsigned long V_44 , int V_105 )
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
if ( ( F_55 ( V_47 ) > V_97 || V_105 == V_107 ) &&
! F_97 ( V_47 ) )
goto V_108;
if ( V_105 == V_109 && F_55 ( V_47 ) == V_99 ) {
if ( F_60 ( V_47 - 1 , V_47 , V_42 , V_42 + V_44 ) )
goto V_108;
}
if ( V_105 == V_107 && F_55 ( V_47 ) == V_99 - 1 ) {
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
static T_6 T_2 * F_115 ( int V_60 , T_1 V_8 )
{
struct V_40 * V_41 ;
unsigned long V_118 [ V_50 ] = { 0 } ;
unsigned long V_119 [ V_50 ] = { 0 } ;
unsigned long V_26 = F_116 ( V_8 ) ;
V_41 = F_117 ( V_60 ) ;
if ( ! V_41 ) {
V_41 = F_118 ( V_60 ) ;
if ( ! V_41 )
return NULL ;
F_119 ( V_60 , V_41 ) ;
}
F_120 ( V_60 , V_118 , V_26 , V_119 ) ;
F_4 ( & V_112 ) ;
F_106 ( V_41 , NULL ) ;
F_5 ( & V_112 ) ;
return V_41 ;
}
static void F_121 ( int V_60 , T_6 * V_41 )
{
F_119 ( V_60 , NULL ) ;
F_122 ( V_41 ) ;
return;
}
int F_123 ( int V_60 )
{
T_6 * V_41 ;
int V_66 ;
if ( F_124 ( V_60 ) )
return 0 ;
F_11 () ;
V_41 = F_115 ( V_60 , 0 ) ;
if ( ! V_41 ) {
F_125 ( L_5 , V_60 ) ;
V_66 = - V_120 ;
goto V_108;
}
F_126 ( V_60 ) ;
V_66 = F_127 ( V_60 ) ;
F_19 ( V_66 ) ;
if ( V_41 -> V_121 -> V_122 -> V_47 == NULL ) {
F_4 ( & V_112 ) ;
F_106 ( NULL , NULL ) ;
F_5 ( & V_112 ) ;
}
V_108:
F_16 () ;
return V_66 ;
}
static int F_128 ( T_1 V_8 , T_1 V_9 )
{
T_1 V_26 = F_116 ( V_8 ) ;
T_1 V_44 = V_9 >> V_36 ;
if ( ( V_26 & ~ V_84 ) ||
( V_44 % V_35 ) || ( ! V_44 ) ) {
F_125 ( L_6 ,
( unsigned long long ) V_8 ,
( unsigned long long ) V_9 ) ;
return - V_82 ;
}
return 0 ;
}
int T_2 F_129 ( int V_60 , T_1 V_8 , T_1 V_9 )
{
T_6 * V_41 = NULL ;
bool V_123 ;
bool V_124 ;
struct V_7 * V_10 ;
int V_66 ;
V_66 = F_128 ( V_8 , V_9 ) ;
if ( V_66 )
return V_66 ;
V_10 = F_17 ( V_8 , V_9 ) ;
V_66 = - V_73 ;
if ( ! V_10 )
return V_66 ;
{
void * V_80 = F_117 ( V_60 ) ;
V_123 = ! V_80 ;
}
F_11 () ;
V_124 = ! F_124 ( V_60 ) ;
if ( V_124 ) {
V_41 = F_115 ( V_60 , V_8 ) ;
V_66 = - V_120 ;
if ( ! V_41 )
goto error;
}
V_66 = F_130 ( V_60 , V_8 , V_9 ) ;
if ( V_66 < 0 )
goto error;
F_126 ( V_60 ) ;
if ( V_124 ) {
V_66 = F_127 ( V_60 ) ;
F_19 ( V_66 ) ;
}
F_131 ( V_8 , V_8 + V_9 , L_1 ) ;
goto V_108;
error:
if ( V_123 )
F_121 ( V_60 , V_41 ) ;
F_23 ( V_10 ) ;
V_108:
F_16 () ;
return V_66 ;
}
static inline int F_132 ( struct V_19 * V_19 )
{
return F_133 ( V_19 ) && F_134 ( V_19 ) >= V_125 ;
}
static struct V_19 * F_135 ( struct V_19 * V_19 )
{
F_19 ( F_136 ( V_19 ) & ( V_126 - 1 ) ) ;
if ( F_132 ( V_19 ) ) {
int V_127 ;
V_127 = F_134 ( V_19 ) ;
if ( ( V_127 < V_128 ) && ( V_127 >= V_125 ) )
return V_19 + ( 1 << V_127 ) ;
}
return V_19 + V_126 ;
}
int F_137 ( unsigned long V_26 , unsigned long V_44 )
{
struct V_19 * V_19 = F_57 ( V_26 ) ;
struct V_19 * V_129 = V_19 + V_44 ;
for (; V_19 < V_129 ; V_19 = F_135 ( V_19 ) ) {
if ( ! F_138 ( V_19 ) )
return 0 ;
F_139 () ;
}
return 1 ;
}
static int F_140 ( unsigned long V_26 , unsigned long V_43 )
{
unsigned long V_42 ;
struct V_47 * V_47 = NULL ;
struct V_19 * V_19 ;
int V_30 ;
for ( V_42 = V_26 ;
V_42 < V_43 ;
V_42 += V_130 ) {
V_30 = 0 ;
while ( ( V_30 < V_130 ) && ! F_141 ( V_42 + V_30 ) )
V_30 ++ ;
if ( V_30 == V_130 )
continue;
V_19 = F_57 ( V_42 + V_30 ) ;
if ( V_47 && F_74 ( V_19 ) != V_47 )
return 0 ;
V_47 = F_74 ( V_19 ) ;
}
return 1 ;
}
static unsigned long F_142 ( unsigned long V_8 , unsigned long V_13 )
{
unsigned long V_42 ;
struct V_19 * V_19 ;
for ( V_42 = V_8 ; V_42 < V_13 ; V_42 ++ ) {
if ( F_41 ( V_42 ) ) {
V_19 = F_57 ( V_42 ) ;
if ( F_143 ( V_19 ) )
return V_42 ;
if ( F_144 ( V_19 ) ) {
if ( F_145 ( V_19 ) )
return V_42 ;
else
V_42 = F_146 ( V_42 + 1 ,
1 << F_147 ( V_19 ) ) - 1 ;
}
}
}
return 0 ;
}
static int
F_148 ( unsigned long V_26 , unsigned long V_43 )
{
unsigned long V_42 ;
struct V_19 * V_19 ;
int V_131 = V_132 ;
int V_133 = 0 ;
int V_66 = 0 ;
F_149 ( V_134 ) ;
for ( V_42 = V_26 ; V_42 < V_43 && V_131 > 0 ; V_42 ++ ) {
if ( ! F_41 ( V_42 ) )
continue;
V_19 = F_57 ( V_42 ) ;
if ( F_144 ( V_19 ) ) {
struct V_19 * V_135 = F_150 ( V_19 ) ;
V_42 = F_136 ( V_135 ) + ( 1 << F_147 ( V_135 ) ) - 1 ;
if ( F_147 ( V_135 ) > V_77 ) {
V_66 = - V_136 ;
break;
}
if ( F_151 ( V_19 , & V_134 ) )
V_131 -= 1 << F_147 ( V_135 ) ;
continue;
}
if ( ! F_152 ( V_19 ) )
continue;
V_66 = F_153 ( V_19 ) ;
if ( ! V_66 ) {
F_154 ( V_19 ) ;
F_155 ( & V_19 -> V_20 , & V_134 ) ;
V_131 -- ;
F_156 ( V_19 , V_137 +
F_157 ( V_19 ) ) ;
} else {
#ifdef F_158
F_109 ( V_138 L_7 ,
V_42 ) ;
F_159 ( V_19 , L_8 ) ;
#endif
F_154 ( V_19 ) ;
if ( F_160 ( V_19 ) ) {
V_133 ++ ;
V_66 = - V_136 ;
break;
}
}
}
if ( ! F_161 ( & V_134 ) ) {
if ( V_133 ) {
F_162 ( & V_134 ) ;
goto V_108;
}
V_66 = F_163 ( & V_134 , V_139 , NULL , 0 ,
V_140 , V_141 ) ;
if ( V_66 )
F_162 ( & V_134 ) ;
}
V_108:
return V_66 ;
}
static int
F_164 ( unsigned long V_8 , unsigned long V_44 ,
void * V_142 )
{
F_165 ( V_8 , V_8 + V_44 ) ;
return 0 ;
}
static void
F_166 ( unsigned long V_26 , unsigned long V_43 )
{
F_107 ( V_26 , V_43 - V_26 , NULL ,
F_164 ) ;
}
static int
F_167 ( unsigned long V_26 , unsigned long V_44 ,
void * V_142 )
{
int V_66 ;
long V_143 = * ( long * ) V_142 ;
V_66 = F_168 ( V_26 , V_26 + V_44 , true ) ;
V_143 = V_44 ;
if ( ! V_66 )
* ( long * ) V_142 += V_143 ;
return V_66 ;
}
static long
F_169 ( unsigned long V_26 , unsigned long V_43 )
{
long V_143 = 0 ;
int V_66 ;
V_66 = F_107 ( V_26 , V_43 - V_26 , & V_143 ,
F_167 ) ;
if ( V_66 < 0 )
V_143 = ( long ) V_66 ;
return V_143 ;
}
static bool F_170 ( struct V_47 * V_47 , unsigned long V_44 )
{
return true ;
}
static bool F_170 ( struct V_47 * V_47 , unsigned long V_44 )
{
struct V_40 * V_41 = V_47 -> V_61 ;
unsigned long V_114 = 0 ;
enum V_58 V_144 ;
for ( V_144 = 0 ; V_144 <= V_97 ; V_144 ++ )
V_114 += V_41 -> V_49 [ V_144 ] . V_114 ;
if ( V_114 > V_44 )
return true ;
V_114 = 0 ;
for (; V_144 <= V_99 ; V_144 ++ )
V_114 += V_41 -> V_49 [ V_144 ] . V_114 ;
return V_114 == 0 ;
}
static int T_7 F_171 ( char * V_80 )
{
#ifdef F_172
F_173 ( true ) ;
V_145 = true ;
#else
F_87 ( L_9 ) ;
#endif
return 0 ;
}
static void F_174 ( unsigned long V_44 ,
struct V_47 * V_47 , struct V_95 * V_92 )
{
struct V_40 * V_41 = V_47 -> V_61 ;
unsigned long V_114 = 0 ;
enum V_58 V_144 , V_96 = V_97 ;
if ( V_98 == V_94 )
V_96 = V_99 ;
for ( V_144 = 0 ; V_144 <= V_96 ; V_144 ++ )
V_114 += V_41 -> V_49 [ V_144 ] . V_114 ;
if ( F_55 ( V_47 ) <= V_96 && V_44 >= V_114 )
V_92 -> V_100 = F_77 ( V_47 ) ;
else
V_92 -> V_100 = - 1 ;
#ifdef F_100
V_96 = V_101 ;
if ( V_98 == V_102 )
V_96 = V_99 ;
for (; V_144 <= V_96 ; V_144 ++ )
V_114 += V_41 -> V_49 [ V_144 ] . V_114 ;
if ( F_55 ( V_47 ) <= V_96 && V_44 >= V_114 )
V_92 -> V_103 = F_77 ( V_47 ) ;
else
V_92 -> V_103 = - 1 ;
#else
V_92 -> V_103 = V_92 -> V_100 ;
#endif
V_96 = V_99 ;
for (; V_144 <= V_96 ; V_144 ++ )
V_114 += V_41 -> V_49 [ V_144 ] . V_114 ;
if ( V_44 >= V_114 )
V_92 -> V_104 = F_77 ( V_47 ) ;
else
V_92 -> V_104 = - 1 ;
}
static void F_175 ( int V_45 , struct V_95 * V_92 )
{
if ( V_92 -> V_100 >= 0 )
F_176 ( V_45 , V_94 ) ;
if ( ( V_98 != V_94 ) &&
( V_92 -> V_103 >= 0 ) )
F_176 ( V_45 , V_102 ) ;
if ( ( V_98 != V_102 ) &&
( V_92 -> V_104 >= 0 ) )
F_176 ( V_45 , V_98 ) ;
}
static int T_2 F_177 ( unsigned long V_26 ,
unsigned long V_43 , unsigned long V_146 )
{
unsigned long V_42 , V_44 , V_147 ;
long V_148 ;
int V_66 , V_149 , V_150 , V_45 ;
unsigned long V_14 ;
struct V_47 * V_47 ;
struct V_95 V_92 ;
if ( ! F_178 ( V_26 , V_126 ) )
return - V_82 ;
if ( ! F_178 ( V_43 , V_126 ) )
return - V_82 ;
if ( ! F_140 ( V_26 , V_43 ) )
return - V_82 ;
F_11 () ;
V_47 = F_74 ( F_57 ( V_26 ) ) ;
V_45 = F_77 ( V_47 ) ;
V_44 = V_43 - V_26 ;
V_66 = - V_82 ;
if ( F_55 ( V_47 ) <= V_97 && ! F_170 ( V_47 , V_44 ) )
goto V_108;
V_66 = F_179 ( V_26 , V_43 ,
V_151 , true ) ;
if ( V_66 )
goto V_108;
V_92 . V_26 = V_26 ;
V_92 . V_44 = V_44 ;
F_174 ( V_44 , V_47 , & V_92 ) ;
V_66 = V_95 ( V_152 , & V_92 ) ;
V_66 = F_104 ( V_66 ) ;
if ( V_66 )
goto V_153;
V_42 = V_26 ;
V_147 = V_154 + V_146 ;
V_149 = 0 ;
V_150 = 5 ;
V_155:
V_66 = - V_156 ;
if ( F_180 ( V_154 , V_147 ) )
goto V_153;
V_66 = - V_157 ;
if ( F_181 ( V_3 ) )
goto V_153;
V_66 = 0 ;
if ( V_149 ) {
F_182 () ;
F_139 () ;
F_183 () ;
}
V_42 = F_142 ( V_26 , V_43 ) ;
if ( V_42 ) {
V_66 = F_148 ( V_42 , V_43 ) ;
if ( ! V_66 ) {
V_149 = 1 ;
goto V_155;
} else {
if ( V_66 < 0 )
if ( -- V_150 == 0 )
goto V_153;
F_184 () ;
V_149 = 1 ;
goto V_155;
}
}
F_182 () ;
F_184 () ;
F_183 () ;
F_185 ( V_26 , V_43 ) ;
V_148 = F_169 ( V_26 , V_43 ) ;
if ( V_148 < 0 ) {
V_66 = - V_136 ;
goto V_153;
}
F_109 ( V_158 L_10 , V_148 ) ;
F_166 ( V_26 , V_43 ) ;
F_186 ( V_26 , V_43 , V_151 ) ;
F_92 ( F_57 ( V_26 ) , - V_148 ) ;
V_47 -> V_114 -= V_148 ;
F_61 ( V_47 -> V_61 , & V_14 ) ;
V_47 -> V_61 -> V_115 -= V_148 ;
F_62 ( V_47 -> V_61 , & V_14 ) ;
F_111 () ;
if ( ! F_105 ( V_47 ) ) {
F_108 ( V_47 ) ;
F_4 ( & V_112 ) ;
F_106 ( NULL , NULL ) ;
F_5 ( & V_112 ) ;
} else
F_110 ( V_47 ) ;
F_175 ( V_45 , & V_92 ) ;
if ( V_92 . V_104 >= 0 )
F_187 ( V_45 ) ;
V_116 = F_113 () ;
F_114 () ;
V_95 ( V_159 , & V_92 ) ;
F_16 () ;
return 0 ;
V_153:
F_109 ( V_158 L_11 ,
( unsigned long long ) V_26 << V_36 ,
( ( unsigned long long ) V_43 << V_36 ) - 1 ) ;
V_95 ( V_160 , & V_92 ) ;
F_186 ( V_26 , V_43 , V_151 ) ;
V_108:
F_16 () ;
return V_66 ;
}
int F_188 ( unsigned long V_26 , unsigned long V_44 )
{
return F_177 ( V_26 , V_26 + V_44 , 120 * V_161 ) ;
}
int F_189 ( unsigned long V_26 , unsigned long V_43 ,
void * V_92 , int (* F_190)( struct V_162 * , void * ) )
{
struct V_162 * V_163 = NULL ;
struct V_31 * V_164 ;
unsigned long V_42 , V_29 ;
int V_66 ;
for ( V_42 = V_26 ; V_42 < V_43 ; V_42 += V_35 ) {
V_29 = F_35 ( V_42 ) ;
if ( ! F_191 ( V_29 ) )
continue;
V_164 = F_36 ( V_29 ) ;
if ( V_163 )
if ( ( V_29 >= V_163 -> V_165 ) &&
( V_29 <= V_163 -> V_166 ) )
continue;
V_163 = F_192 ( V_164 , V_163 ) ;
if ( ! V_163 )
continue;
V_66 = F_190 ( V_163 , V_92 ) ;
if ( V_66 ) {
F_193 ( & V_163 -> V_167 . V_168 ) ;
return V_66 ;
}
}
if ( V_163 )
F_193 ( & V_163 -> V_167 . V_168 ) ;
return 0 ;
}
static int F_194 ( struct V_162 * V_163 , void * V_92 )
{
int V_66 = ! F_195 ( V_163 ) ;
if ( F_8 ( V_66 ) ) {
T_8 V_169 , V_170 ;
V_169 = F_196 ( F_83 ( V_163 -> V_165 ) ) ;
V_170 = F_196 ( F_83 ( V_163 -> V_166 + 1 ) ) - 1 ;
F_87 ( L_12
L_13 ,
& V_169 , & V_170 ) ;
}
return V_66 ;
}
static int F_197 ( T_6 * V_41 )
{
int V_171 ;
F_198 (cpu) {
if ( F_199 ( V_171 ) == V_41 -> V_46 )
return - V_136 ;
}
return 0 ;
}
static void F_200 ( T_6 * V_41 )
{
#ifdef F_201
int V_171 ;
F_202 (cpu)
if ( F_199 ( V_171 ) == V_41 -> V_46 )
F_203 ( V_171 ) ;
#endif
}
static int F_204 ( T_6 * V_41 )
{
int V_66 ;
V_66 = F_197 ( V_41 ) ;
if ( V_66 )
return V_66 ;
F_200 ( V_41 ) ;
return 0 ;
}
void F_205 ( int V_60 )
{
T_6 * V_41 = F_117 ( V_60 ) ;
unsigned long V_26 = V_41 -> V_54 ;
unsigned long V_43 = V_26 + V_41 -> V_71 ;
unsigned long V_42 ;
struct V_19 * V_172 = F_38 ( V_41 ) ;
int V_30 ;
for ( V_42 = V_26 ; V_42 < V_43 ; V_42 += V_35 ) {
unsigned long V_29 = F_35 ( V_42 ) ;
if ( ! F_191 ( V_29 ) )
continue;
if ( F_46 ( V_42 ) != V_60 )
continue;
return;
}
if ( F_204 ( V_41 ) )
return;
F_206 ( V_60 ) ;
F_207 ( V_60 ) ;
if ( ! F_208 ( V_172 ) && ! F_209 ( V_172 ) )
return;
for ( V_30 = 0 ; V_30 < V_50 ; V_30 ++ ) {
struct V_47 * V_47 = V_41 -> V_49 + V_30 ;
if ( F_210 ( V_47 -> V_53 ) )
F_211 ( V_47 -> V_53 ) ;
}
memset ( V_41 , 0 , sizeof( * V_41 ) ) ;
}
void T_2 F_212 ( int V_60 , T_1 V_8 , T_1 V_9 )
{
int V_66 ;
F_19 ( F_128 ( V_8 , V_9 ) ) ;
F_11 () ;
V_66 = F_189 ( F_116 ( V_8 ) , F_213 ( V_8 + V_9 - 1 ) , NULL ,
F_194 ) ;
if ( V_66 )
F_214 () ;
F_215 ( V_8 , V_8 + V_9 , L_1 ) ;
F_216 ( V_8 , V_9 ) ;
F_205 ( V_60 ) ;
F_16 () ;
}
