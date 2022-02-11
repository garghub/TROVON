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
unsigned long V_14 , V_42 ;
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
for ( V_42 = V_72 ; V_42 < V_72 + V_44 ; V_42 ++ ) {
if ( ! F_41 ( V_42 ) )
continue;
F_67 ( F_57 ( V_42 ) ) ;
}
return 0 ;
}
static int T_2 F_68 ( int V_60 , struct V_47 * V_47 ,
unsigned long V_72 )
{
int V_66 ;
if ( F_41 ( V_72 ) )
return - V_73 ;
V_66 = F_69 ( V_47 , V_72 ) ;
if ( V_66 < 0 )
return V_66 ;
V_66 = F_65 ( V_47 , V_72 ) ;
if ( V_66 < 0 )
return V_66 ;
return F_70 ( V_60 , F_71 ( V_72 ) ) ;
}
int T_3 F_72 ( int V_60 , struct V_47 * V_47 , unsigned long V_72 ,
unsigned long V_44 )
{
unsigned long V_30 ;
int V_74 = 0 ;
int V_75 , V_76 ;
V_75 = F_35 ( V_72 ) ;
V_76 = F_35 ( V_72 + V_44 - 1 ) ;
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
V_41 -> V_71 = F_45 - V_42 ;
}
} else if ( F_45 == V_43 ) {
V_42 = F_78 ( V_60 , NULL , V_78 ,
V_26 ) ;
if ( V_42 )
V_41 -> V_71 = V_42 - V_78 + 1 ;
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
V_41 -> V_71 = 0 ;
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
int V_66 = - V_81 ;
if ( ! F_76 ( V_32 ) )
return V_66 ;
V_66 = F_84 ( V_32 ) ;
if ( V_66 )
return V_66 ;
V_80 = F_85 ( V_32 ) ;
V_26 = F_73 ( V_80 ) ;
F_82 ( V_47 , V_26 ) ;
F_86 ( V_47 , V_32 ) ;
return 0 ;
}
int F_87 ( struct V_47 * V_47 , unsigned long V_72 ,
unsigned long V_44 )
{
unsigned long V_30 ;
int V_82 ;
T_4 V_8 , V_9 ;
int V_66 = 0 ;
F_19 ( V_72 & ~ V_83 ) ;
F_19 ( V_44 % V_35 ) ;
V_8 = V_72 << V_36 ;
V_9 = V_44 * V_84 ;
if ( ! F_88 ( V_47 ) )
V_66 = F_89 ( & V_17 , V_8 , V_9 ) ;
if ( V_66 ) {
T_4 V_85 = V_8 + V_9 - 1 ;
F_90 ( L_3 ,
& V_8 , & V_85 , V_66 ) ;
}
V_82 = V_44 / V_35 ;
for ( V_30 = 0 ; V_30 < V_82 ; V_30 ++ ) {
unsigned long V_42 = V_72 + V_30 * V_35 ;
V_66 = F_83 ( V_47 , F_71 ( V_42 ) ) ;
if ( V_66 )
break;
}
return V_66 ;
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
int V_66 ;
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
V_66 = V_94 ( V_108 , & V_91 ) ;
V_66 = F_107 ( V_66 ) ;
if ( V_66 ) {
V_94 ( V_109 , & V_91 ) ;
return V_66 ;
}
F_4 ( & V_110 ) ;
if ( ! F_108 ( V_47 ) ) {
V_105 = 1 ;
F_109 ( NULL , V_47 ) ;
}
V_66 = F_110 ( V_42 , V_44 , & V_92 ,
F_98 ) ;
if ( V_66 ) {
if ( V_105 )
F_111 ( V_47 ) ;
F_5 ( & V_110 ) ;
F_112 ( V_111 L_4 ,
( unsigned long long ) V_42 << V_36 ,
( ( ( unsigned long long ) V_42 + V_44 )
<< V_36 ) - 1 ) ;
V_94 ( V_109 , & V_91 ) ;
return V_66 ;
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
int V_66 ;
if ( F_129 ( V_60 ) )
return 0 ;
F_11 () ;
V_41 = F_119 ( V_60 , 0 ) ;
if ( ! V_41 ) {
F_130 ( L_5 , V_60 ) ;
V_66 = - V_120 ;
goto V_121;
}
F_131 ( V_60 ) ;
V_66 = F_132 ( V_60 ) ;
F_19 ( V_66 ) ;
if ( V_41 -> V_122 -> V_123 -> V_47 == NULL ) {
F_4 ( & V_110 ) ;
F_109 ( NULL , NULL ) ;
F_5 ( & V_110 ) ;
}
V_121:
F_16 () ;
return V_66 ;
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
int T_3 F_137 ( int V_60 , T_1 V_8 , T_1 V_9 )
{
T_6 * V_41 = NULL ;
bool V_128 ;
bool V_129 ;
struct V_7 * V_10 ;
int V_66 ;
V_66 = F_133 ( V_8 , V_9 ) ;
if ( V_66 )
return V_66 ;
V_10 = F_17 ( V_8 , V_9 ) ;
V_66 = - V_73 ;
if ( ! V_10 )
return V_66 ;
{
void * V_79 = F_121 ( V_60 ) ;
V_128 = ! V_79 ;
}
F_11 () ;
F_138 ( V_8 , V_9 , V_60 ) ;
V_129 = ! F_129 ( V_60 ) ;
if ( V_129 ) {
V_41 = F_119 ( V_60 , V_8 ) ;
V_66 = - V_120 ;
if ( ! V_41 )
goto error;
}
V_66 = F_139 ( V_60 , V_8 , V_9 , false ) ;
if ( V_66 < 0 )
goto error;
F_131 ( V_60 ) ;
if ( V_129 ) {
V_66 = F_132 ( V_60 ) ;
F_19 ( V_66 ) ;
}
F_140 ( V_8 , V_8 + V_9 , L_1 ) ;
goto V_121;
error:
if ( V_128 )
F_126 ( V_60 , V_41 ) ;
F_23 ( V_10 ) ;
F_141 ( V_8 , V_9 ) ;
V_121:
F_16 () ;
return V_66 ;
}
static inline int F_142 ( struct V_19 * V_19 )
{
return F_143 ( V_19 ) && F_144 ( V_19 ) >= V_130 ;
}
static struct V_19 * F_145 ( struct V_19 * V_19 )
{
F_19 ( F_146 ( V_19 ) & ( V_131 - 1 ) ) ;
if ( F_142 ( V_19 ) ) {
int V_132 ;
V_132 = F_144 ( V_19 ) ;
if ( ( V_132 < V_133 ) && ( V_132 >= V_130 ) )
return V_19 + ( 1 << V_132 ) ;
}
return V_19 + V_131 ;
}
int F_147 ( unsigned long V_26 , unsigned long V_44 )
{
struct V_19 * V_19 = F_57 ( V_26 ) ;
struct V_19 * V_134 = V_19 + V_44 ;
for (; V_19 < V_134 ; V_19 = F_145 ( V_19 ) ) {
if ( ! F_148 ( V_19 ) )
return 0 ;
F_149 () ;
}
return 1 ;
}
int F_150 ( unsigned long V_26 , unsigned long V_43 )
{
unsigned long V_42 ;
struct V_47 * V_47 = NULL ;
struct V_19 * V_19 ;
int V_30 ;
for ( V_42 = V_26 ;
V_42 < V_43 ;
V_42 += V_135 ) {
V_30 = 0 ;
while ( ( V_30 < V_135 ) && ! F_151 ( V_42 + V_30 ) )
V_30 ++ ;
if ( V_30 == V_135 )
continue;
V_19 = F_57 ( V_42 + V_30 ) ;
if ( V_47 && F_77 ( V_19 ) != V_47 )
return 0 ;
V_47 = F_77 ( V_19 ) ;
}
return 1 ;
}
static unsigned long F_152 ( unsigned long V_8 , unsigned long V_13 )
{
unsigned long V_42 ;
struct V_19 * V_19 ;
for ( V_42 = V_8 ; V_42 < V_13 ; V_42 ++ ) {
if ( F_41 ( V_42 ) ) {
V_19 = F_57 ( V_42 ) ;
if ( F_153 ( V_19 ) )
return V_42 ;
if ( F_154 ( V_19 ) ) {
if ( F_155 ( V_19 ) )
return V_42 ;
else
V_42 = F_156 ( V_42 + 1 ,
1 << F_157 ( V_19 ) ) - 1 ;
}
}
}
return 0 ;
}
static int
F_158 ( unsigned long V_26 , unsigned long V_43 )
{
unsigned long V_42 ;
struct V_19 * V_19 ;
int V_136 = V_137 ;
int V_138 = 0 ;
int V_66 = 0 ;
F_159 ( V_139 ) ;
for ( V_42 = V_26 ; V_42 < V_43 && V_136 > 0 ; V_42 ++ ) {
if ( ! F_41 ( V_42 ) )
continue;
V_19 = F_57 ( V_42 ) ;
if ( F_154 ( V_19 ) ) {
struct V_19 * V_140 = F_160 ( V_19 ) ;
V_42 = F_146 ( V_140 ) + ( 1 << F_157 ( V_140 ) ) - 1 ;
if ( F_157 ( V_140 ) > V_141 ) {
V_66 = - V_142 ;
break;
}
if ( F_161 ( V_19 , & V_139 ) )
V_136 -= 1 << F_157 ( V_140 ) ;
continue;
}
if ( ! F_162 ( V_19 ) )
continue;
V_66 = F_163 ( V_19 ) ;
if ( ! V_66 ) {
F_164 ( V_19 ) ;
F_165 ( & V_19 -> V_20 , & V_139 ) ;
V_136 -- ;
F_166 ( V_19 , V_143 +
F_167 ( V_19 ) ) ;
} else {
#ifdef F_168
F_112 ( V_144 L_7 ,
V_42 ) ;
F_169 ( V_19 , L_8 ) ;
#endif
F_164 ( V_19 ) ;
if ( F_170 ( V_19 ) ) {
V_138 ++ ;
V_66 = - V_142 ;
break;
}
}
}
if ( ! F_171 ( & V_139 ) ) {
if ( V_138 ) {
F_172 ( & V_139 ) ;
goto V_121;
}
V_66 = F_173 ( & V_139 , V_145 , NULL , 0 ,
V_146 , V_147 ) ;
if ( V_66 )
F_172 ( & V_139 ) ;
}
V_121:
return V_66 ;
}
static int
F_174 ( unsigned long V_8 , unsigned long V_44 ,
void * V_148 )
{
F_175 ( V_8 , V_8 + V_44 ) ;
return 0 ;
}
static void
F_176 ( unsigned long V_26 , unsigned long V_43 )
{
F_110 ( V_26 , V_43 - V_26 , NULL ,
F_174 ) ;
}
static int
F_177 ( unsigned long V_26 , unsigned long V_44 ,
void * V_148 )
{
int V_66 ;
long V_149 = * ( long * ) V_148 ;
V_66 = F_178 ( V_26 , V_26 + V_44 , true ) ;
V_149 = V_44 ;
if ( ! V_66 )
* ( long * ) V_148 += V_149 ;
return V_66 ;
}
static long
F_179 ( unsigned long V_26 , unsigned long V_43 )
{
long V_149 = 0 ;
int V_66 ;
V_66 = F_110 ( V_26 , V_43 - V_26 , & V_149 ,
F_177 ) ;
if ( V_66 < 0 )
V_149 = ( long ) V_66 ;
return V_149 ;
}
static bool F_180 ( struct V_47 * V_47 , unsigned long V_44 )
{
return true ;
}
static bool F_180 ( struct V_47 * V_47 , unsigned long V_44 )
{
struct V_40 * V_41 = V_47 -> V_61 ;
unsigned long V_112 = 0 ;
enum V_58 V_150 ;
for ( V_150 = 0 ; V_150 <= V_96 ; V_150 ++ )
V_112 += V_41 -> V_49 [ V_150 ] . V_112 ;
if ( V_112 > V_44 )
return true ;
V_112 = 0 ;
for (; V_150 <= V_98 ; V_150 ++ )
V_112 += V_41 -> V_49 [ V_150 ] . V_112 ;
return V_112 == 0 ;
}
static int T_7 F_181 ( char * V_79 )
{
#ifdef F_182
F_183 ( true ) ;
V_151 = true ;
#else
F_90 ( L_9 ) ;
#endif
return 0 ;
}
static void F_184 ( unsigned long V_44 ,
struct V_47 * V_47 , struct V_94 * V_91 )
{
struct V_40 * V_41 = V_47 -> V_61 ;
unsigned long V_112 = 0 ;
enum V_58 V_150 , V_95 = V_96 ;
if ( V_97 == V_93 )
V_95 = V_98 ;
for ( V_150 = 0 ; V_150 <= V_95 ; V_150 ++ )
V_112 += V_41 -> V_49 [ V_150 ] . V_112 ;
if ( F_55 ( V_47 ) <= V_95 && V_44 >= V_112 )
V_91 -> V_99 = F_80 ( V_47 ) ;
else
V_91 -> V_99 = - 1 ;
#ifdef F_103
V_95 = V_100 ;
if ( V_97 == V_101 )
V_95 = V_98 ;
for (; V_150 <= V_95 ; V_150 ++ )
V_112 += V_41 -> V_49 [ V_150 ] . V_112 ;
if ( F_55 ( V_47 ) <= V_95 && V_44 >= V_112 )
V_91 -> V_102 = F_80 ( V_47 ) ;
else
V_91 -> V_102 = - 1 ;
#else
V_91 -> V_102 = V_91 -> V_99 ;
#endif
V_95 = V_98 ;
for (; V_150 <= V_95 ; V_150 ++ )
V_112 += V_41 -> V_49 [ V_150 ] . V_112 ;
if ( V_44 >= V_112 )
V_91 -> V_103 = F_80 ( V_47 ) ;
else
V_91 -> V_103 = - 1 ;
}
static void F_185 ( int V_45 , struct V_94 * V_91 )
{
if ( V_91 -> V_99 >= 0 )
F_186 ( V_45 , V_93 ) ;
if ( ( V_97 != V_93 ) &&
( V_91 -> V_102 >= 0 ) )
F_186 ( V_45 , V_101 ) ;
if ( ( V_97 != V_101 ) &&
( V_91 -> V_103 >= 0 ) )
F_186 ( V_45 , V_97 ) ;
}
static int T_3 F_187 ( unsigned long V_26 ,
unsigned long V_43 , unsigned long V_152 )
{
unsigned long V_42 , V_44 , V_153 ;
long V_154 ;
int V_66 , V_155 , V_156 , V_45 ;
unsigned long V_14 ;
struct V_47 * V_47 ;
struct V_94 V_91 ;
if ( ! F_188 ( V_26 , V_131 ) )
return - V_81 ;
if ( ! F_188 ( V_43 , V_131 ) )
return - V_81 ;
if ( ! F_150 ( V_26 , V_43 ) )
return - V_81 ;
V_47 = F_77 ( F_57 ( V_26 ) ) ;
V_45 = F_80 ( V_47 ) ;
V_44 = V_43 - V_26 ;
if ( F_55 ( V_47 ) <= V_96 && ! F_180 ( V_47 , V_44 ) )
return - V_81 ;
V_66 = F_189 ( V_26 , V_43 ,
V_157 , true ) ;
if ( V_66 )
return V_66 ;
V_91 . V_26 = V_26 ;
V_91 . V_44 = V_44 ;
F_184 ( V_44 , V_47 , & V_91 ) ;
V_66 = V_94 ( V_158 , & V_91 ) ;
V_66 = F_107 ( V_66 ) ;
if ( V_66 )
goto V_159;
V_42 = V_26 ;
V_153 = V_160 + V_152 ;
V_155 = 0 ;
V_156 = 5 ;
V_161:
V_66 = - V_162 ;
if ( F_190 ( V_160 , V_153 ) )
goto V_159;
V_66 = - V_163 ;
if ( F_191 ( V_3 ) )
goto V_159;
V_66 = 0 ;
if ( V_155 ) {
F_192 () ;
F_149 () ;
F_193 ( V_47 ) ;
}
V_42 = F_152 ( V_26 , V_43 ) ;
if ( V_42 ) {
V_66 = F_158 ( V_42 , V_43 ) ;
if ( ! V_66 ) {
V_155 = 1 ;
goto V_161;
} else {
if ( V_66 < 0 )
if ( -- V_156 == 0 )
goto V_159;
F_194 () ;
V_155 = 1 ;
goto V_161;
}
}
F_192 () ;
F_194 () ;
F_193 ( V_47 ) ;
F_195 ( V_26 , V_43 ) ;
V_154 = F_179 ( V_26 , V_43 ) ;
if ( V_154 < 0 ) {
V_66 = - V_142 ;
goto V_159;
}
F_112 ( V_164 L_10 , V_154 ) ;
F_176 ( V_26 , V_43 ) ;
F_196 ( V_26 , V_43 , V_157 ) ;
F_95 ( F_57 ( V_26 ) , - V_154 ) ;
V_47 -> V_112 -= V_154 ;
F_61 ( V_47 -> V_61 , & V_14 ) ;
V_47 -> V_61 -> V_113 -= V_154 ;
F_62 ( V_47 -> V_61 , & V_14 ) ;
F_114 () ;
if ( ! F_108 ( V_47 ) ) {
F_111 ( V_47 ) ;
F_4 ( & V_110 ) ;
F_109 ( NULL , NULL ) ;
F_5 ( & V_110 ) ;
} else
F_113 ( V_47 ) ;
F_185 ( V_45 , & V_91 ) ;
if ( V_91 . V_103 >= 0 )
F_197 ( V_45 ) ;
V_114 = F_116 () ;
F_117 () ;
V_94 ( V_165 , & V_91 ) ;
return 0 ;
V_159:
F_112 ( V_164 L_11 ,
( unsigned long long ) V_26 << V_36 ,
( ( unsigned long long ) V_43 << V_36 ) - 1 ) ;
V_94 ( V_166 , & V_91 ) ;
F_196 ( V_26 , V_43 , V_157 ) ;
return V_66 ;
}
int F_198 ( unsigned long V_26 , unsigned long V_44 )
{
return F_187 ( V_26 , V_26 + V_44 , 120 * V_167 ) ;
}
int F_199 ( unsigned long V_26 , unsigned long V_43 ,
void * V_91 , int (* F_200)( struct V_168 * , void * ) )
{
struct V_168 * V_169 = NULL ;
struct V_31 * V_170 ;
unsigned long V_42 , V_29 ;
int V_66 ;
for ( V_42 = V_26 ; V_42 < V_43 ; V_42 += V_35 ) {
V_29 = F_35 ( V_42 ) ;
if ( ! F_201 ( V_29 ) )
continue;
V_170 = F_36 ( V_29 ) ;
if ( V_169 )
if ( ( V_29 >= V_169 -> V_171 ) &&
( V_29 <= V_169 -> V_172 ) )
continue;
V_169 = F_202 ( V_170 , V_169 ) ;
if ( ! V_169 )
continue;
V_66 = F_200 ( V_169 , V_91 ) ;
if ( V_66 ) {
F_203 ( & V_169 -> V_173 . V_174 ) ;
return V_66 ;
}
}
if ( V_169 )
F_203 ( & V_169 -> V_173 . V_174 ) ;
return 0 ;
}
static int F_204 ( struct V_168 * V_169 , void * V_91 )
{
int V_66 = ! F_205 ( V_169 ) ;
if ( F_8 ( V_66 ) ) {
T_8 V_175 , V_176 ;
V_175 = F_206 ( F_73 ( V_169 -> V_171 ) ) ;
V_176 = F_206 ( F_73 ( V_169 -> V_172 + 1 ) ) - 1 ;
F_90 ( L_12
L_13 ,
& V_175 , & V_176 ) ;
}
return V_66 ;
}
static int F_207 ( T_6 * V_41 )
{
int V_177 ;
F_208 (cpu) {
if ( F_209 ( V_177 ) == V_41 -> V_46 )
return - V_142 ;
}
return 0 ;
}
static void F_210 ( T_6 * V_41 )
{
#ifdef F_211
int V_177 ;
F_212 (cpu)
if ( F_209 ( V_177 ) == V_41 -> V_46 )
F_213 ( V_177 ) ;
#endif
}
static int F_214 ( T_6 * V_41 )
{
int V_66 ;
V_66 = F_207 ( V_41 ) ;
if ( V_66 )
return V_66 ;
F_210 ( V_41 ) ;
return 0 ;
}
void F_215 ( int V_60 )
{
T_6 * V_41 = F_121 ( V_60 ) ;
unsigned long V_26 = V_41 -> V_54 ;
unsigned long V_43 = V_26 + V_41 -> V_71 ;
unsigned long V_42 ;
int V_30 ;
for ( V_42 = V_26 ; V_42 < V_43 ; V_42 += V_35 ) {
unsigned long V_29 = F_35 ( V_42 ) ;
if ( ! F_201 ( V_29 ) )
continue;
if ( F_46 ( V_42 ) != V_60 )
continue;
return;
}
if ( F_214 ( V_41 ) )
return;
F_216 ( V_60 ) ;
F_217 ( V_60 ) ;
for ( V_30 = 0 ; V_30 < V_50 ; V_30 ++ ) {
struct V_47 * V_47 = V_41 -> V_49 + V_30 ;
if ( F_218 ( V_47 -> V_53 ) ) {
F_219 ( V_47 -> V_53 ) ;
V_47 -> V_53 = NULL ;
}
}
}
void T_3 F_220 ( int V_60 , T_1 V_8 , T_1 V_9 )
{
int V_66 ;
F_19 ( F_133 ( V_8 , V_9 ) ) ;
F_11 () ;
V_66 = F_199 ( F_120 ( V_8 ) , F_221 ( V_8 + V_9 - 1 ) , NULL ,
F_204 ) ;
if ( V_66 )
F_222 () ;
F_223 ( V_8 , V_8 + V_9 , L_1 ) ;
F_224 ( V_8 , V_9 ) ;
F_141 ( V_8 , V_9 ) ;
F_225 ( V_8 , V_9 ) ;
F_215 ( V_60 ) ;
F_16 () ;
}
