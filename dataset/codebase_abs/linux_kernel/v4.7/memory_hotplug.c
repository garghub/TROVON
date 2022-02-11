static int T_1 F_1 ( char * V_1 )
{
if ( ! strcmp ( V_1 , L_1 ) )
V_2 = true ;
else if ( ! strcmp ( V_1 , L_2 ) )
V_2 = false ;
return 1 ;
}
void F_2 ( void )
{
F_3 () ;
if ( V_3 . V_4 == V_5 )
return;
F_4 () ;
F_5 ( & V_3 . V_6 ) ;
V_3 . V_7 ++ ;
F_6 ( & V_3 . V_6 ) ;
}
void F_7 ( void )
{
if ( V_3 . V_4 == V_5 )
return;
F_5 ( & V_3 . V_6 ) ;
if ( F_8 ( ! V_3 . V_7 ) )
V_3 . V_7 ++ ;
if ( ! -- V_3 . V_7 && F_9 ( V_3 . V_4 ) )
F_10 ( V_3 . V_4 ) ;
F_6 ( & V_3 . V_6 ) ;
F_11 () ;
}
void F_12 ( void )
{
V_3 . V_4 = V_5 ;
F_13 () ;
for (; ; ) {
F_5 ( & V_3 . V_6 ) ;
if ( F_14 ( ! V_3 . V_7 ) )
break;
F_15 ( V_8 ) ;
F_6 ( & V_3 . V_6 ) ;
F_16 () ;
}
}
void F_17 ( void )
{
V_3 . V_4 = NULL ;
F_6 ( & V_3 . V_6 ) ;
F_11 () ;
}
static struct V_9 * F_18 ( T_2 V_10 , T_2 V_11 )
{
struct V_9 * V_12 ;
V_12 = F_19 ( sizeof( struct V_9 ) , V_13 ) ;
if ( ! V_12 )
return F_20 ( - V_14 ) ;
V_12 -> V_15 = L_3 ;
V_12 -> V_10 = V_10 ;
V_12 -> V_16 = V_10 + V_11 - 1 ;
V_12 -> V_17 = V_18 | V_19 ;
if ( F_21 ( & V_20 , V_12 ) < 0 ) {
F_22 ( L_4 , V_12 ) ;
F_23 ( V_12 ) ;
return F_20 ( - V_21 ) ;
}
return V_12 ;
}
static void F_24 ( struct V_9 * V_12 )
{
if ( ! V_12 )
return;
F_25 ( V_12 ) ;
F_23 ( V_12 ) ;
return;
}
void F_26 ( unsigned long V_22 , struct V_23 * V_23 ,
unsigned long type )
{
V_23 -> V_24 . V_25 = (struct V_26 * ) type ;
F_27 ( V_23 ) ;
F_28 ( V_23 , V_22 ) ;
F_29 ( V_23 ) ;
}
void F_30 ( struct V_23 * V_23 )
{
unsigned long type ;
type = ( unsigned long ) V_23 -> V_24 . V_25 ;
F_31 ( type < V_27 ||
type > V_28 ) ;
if ( F_32 ( V_23 ) == 1 ) {
F_33 ( V_23 ) ;
F_28 ( V_23 , 0 ) ;
F_34 ( & V_23 -> V_24 ) ;
F_35 ( V_23 ) ;
}
}
static void F_36 ( unsigned long V_29 )
{
unsigned long * V_30 , V_31 , V_32 , V_33 ;
struct V_34 * V_35 ;
struct V_23 * V_23 , * V_36 ;
V_32 = F_37 ( V_29 ) ;
V_35 = F_38 ( V_32 ) ;
V_36 = F_39 ( V_35 -> V_37 , V_32 ) ;
V_23 = F_40 ( V_36 ) ;
V_31 = sizeof( struct V_23 ) * V_38 ;
V_31 = F_41 ( V_31 ) >> V_39 ;
for ( V_33 = 0 ; V_33 < V_31 ; V_33 ++ , V_23 ++ )
F_26 ( V_32 , V_23 , V_40 ) ;
V_30 = F_38 ( V_32 ) -> V_41 ;
V_23 = F_40 ( V_30 ) ;
V_31 = F_41 ( F_42 () ) >> V_39 ;
for ( V_33 = 0 ; V_33 < V_31 ; V_33 ++ , V_23 ++ )
F_26 ( V_32 , V_23 , V_42 ) ;
}
static void F_36 ( unsigned long V_29 )
{
unsigned long * V_30 , V_31 , V_32 , V_33 ;
struct V_34 * V_35 ;
struct V_23 * V_23 , * V_36 ;
if ( ! F_43 ( V_29 ) )
return;
V_32 = F_37 ( V_29 ) ;
V_35 = F_38 ( V_32 ) ;
V_36 = F_39 ( V_35 -> V_37 , V_32 ) ;
F_44 ( V_32 , V_36 , V_38 ) ;
V_30 = F_38 ( V_32 ) -> V_41 ;
V_23 = F_40 ( V_30 ) ;
V_31 = F_41 ( F_42 () ) >> V_39 ;
for ( V_33 = 0 ; V_33 < V_31 ; V_33 ++ , V_23 ++ )
F_26 ( V_32 , V_23 , V_42 ) ;
}
void T_1 F_45 ( struct V_43 * V_44 )
{
unsigned long V_33 , V_45 , V_46 , V_47 ;
int V_48 = V_44 -> V_49 ;
struct V_23 * V_23 ;
struct V_50 * V_50 ;
V_47 = F_41 ( sizeof( struct V_43 ) ) >> V_39 ;
V_23 = F_40 ( V_44 ) ;
for ( V_33 = 0 ; V_33 < V_47 ; V_33 ++ , V_23 ++ )
F_26 ( V_48 , V_23 , V_51 ) ;
V_50 = & V_44 -> V_52 [ 0 ] ;
for (; V_50 < V_44 -> V_52 + V_53 - 1 ; V_50 ++ ) {
if ( F_46 ( V_50 ) ) {
V_47 = V_50 -> V_54
* sizeof( V_55 ) ;
V_47 = F_41 ( V_47 ) >> V_39 ;
V_23 = F_40 ( V_50 -> V_56 ) ;
for ( V_33 = 0 ; V_33 < V_47 ; V_33 ++ , V_23 ++ )
F_26 ( V_48 , V_23 , V_51 ) ;
}
}
V_45 = V_44 -> V_57 ;
V_46 = F_47 ( V_44 ) ;
for (; V_45 < V_46 ; V_45 += V_38 ) {
if ( F_43 ( V_45 ) && ( F_48 ( V_45 ) == V_48 ) )
F_36 ( V_45 ) ;
}
}
static void T_3 F_49 ( struct V_50 * V_50 , unsigned long V_29 ,
unsigned long V_46 )
{
unsigned long V_58 ;
F_50 ( V_50 ) ;
V_58 = F_51 ( V_50 ) ;
if ( F_52 ( V_50 ) || V_29 < V_50 -> V_59 )
V_50 -> V_59 = V_29 ;
V_50 -> V_60 = F_53 ( V_58 , V_46 ) -
V_50 -> V_59 ;
F_54 ( V_50 ) ;
}
static void F_55 ( struct V_50 * V_50 , unsigned long V_29 ,
unsigned long V_46 )
{
F_50 ( V_50 ) ;
if ( V_46 - V_29 ) {
V_50 -> V_59 = V_29 ;
V_50 -> V_60 = V_46 - V_29 ;
} else {
V_50 -> V_59 = 0 ;
V_50 -> V_60 = 0 ;
}
F_54 ( V_50 ) ;
}
static void F_56 ( struct V_50 * V_50 , unsigned long V_29 ,
unsigned long V_46 )
{
enum V_61 V_62 = F_57 ( V_50 ) ;
int V_63 = V_50 -> V_64 -> V_49 ;
unsigned long V_45 ;
for ( V_45 = V_29 ; V_45 < V_46 ; V_45 ++ )
F_58 ( F_59 ( V_45 ) , V_62 , V_63 , V_45 ) ;
}
static int T_4 F_60 ( struct V_50 * V_50 ,
unsigned long V_29 , unsigned long V_65 )
{
if ( ! F_46 ( V_50 ) )
return F_61 ( V_50 , V_29 , V_65 ) ;
return 0 ;
}
static int T_3 F_62 ( struct V_50 * V_66 , struct V_50 * V_67 ,
unsigned long V_29 , unsigned long V_46 )
{
int V_68 ;
unsigned long V_17 ;
unsigned long V_69 ;
V_68 = F_60 ( V_66 , V_29 , V_46 - V_29 ) ;
if ( V_68 )
return V_68 ;
F_63 ( V_66 -> V_64 , & V_17 ) ;
if ( V_46 > F_51 ( V_67 ) )
goto V_70;
if ( V_29 > V_67 -> V_59 )
goto V_70;
if ( V_46 <= V_67 -> V_59 )
goto V_70;
if ( ! F_52 ( V_66 ) )
V_69 = V_66 -> V_59 ;
else
V_69 = V_29 ;
F_55 ( V_66 , V_69 , V_46 ) ;
F_55 ( V_67 , V_46 , F_51 ( V_67 ) ) ;
F_64 ( V_66 -> V_64 , & V_17 ) ;
F_56 ( V_66 , V_29 , V_46 ) ;
return 0 ;
V_70:
F_64 ( V_66 -> V_64 , & V_17 ) ;
return - 1 ;
}
static int T_3 F_65 ( struct V_50 * V_66 , struct V_50 * V_67 ,
unsigned long V_29 , unsigned long V_46 )
{
int V_68 ;
unsigned long V_17 ;
unsigned long V_71 ;
V_68 = F_60 ( V_67 , V_29 , V_46 - V_29 ) ;
if ( V_68 )
return V_68 ;
F_63 ( V_66 -> V_64 , & V_17 ) ;
if ( V_66 -> V_59 > V_29 )
goto V_70;
if ( F_51 ( V_66 ) > V_46 )
goto V_70;
if ( V_29 >= F_51 ( V_66 ) )
goto V_70;
if ( ! F_52 ( V_67 ) )
V_71 = F_51 ( V_67 ) ;
else
V_71 = V_46 ;
F_55 ( V_66 , V_66 -> V_59 , V_29 ) ;
F_55 ( V_67 , V_29 , V_71 ) ;
F_64 ( V_66 -> V_64 , & V_17 ) ;
F_56 ( V_67 , V_29 , V_46 ) ;
return 0 ;
V_70:
F_64 ( V_66 -> V_64 , & V_17 ) ;
return - 1 ;
}
static void T_3 F_66 ( struct V_43 * V_44 , unsigned long V_29 ,
unsigned long V_46 )
{
unsigned long V_72 = F_47 ( V_44 ) ;
if ( ! V_44 -> V_73 || V_29 < V_44 -> V_57 )
V_44 -> V_57 = V_29 ;
V_44 -> V_73 = F_53 ( V_72 , V_46 ) -
V_44 -> V_57 ;
}
static int T_3 F_67 ( struct V_50 * V_50 , unsigned long V_74 )
{
struct V_43 * V_44 = V_50 -> V_64 ;
int V_47 = V_38 ;
int V_63 = V_44 -> V_49 ;
int V_61 ;
unsigned long V_17 , V_45 ;
int V_68 ;
V_61 = V_50 - V_44 -> V_52 ;
V_68 = F_60 ( V_50 , V_74 , V_47 ) ;
if ( V_68 )
return V_68 ;
F_63 ( V_50 -> V_64 , & V_17 ) ;
F_49 ( V_50 , V_74 , V_74 + V_47 ) ;
F_66 ( V_50 -> V_64 , V_74 ,
V_74 + V_47 ) ;
F_64 ( V_50 -> V_64 , & V_17 ) ;
F_68 ( V_47 , V_63 , V_61 ,
V_74 , V_75 ) ;
for ( V_45 = V_74 ; V_45 < V_74 + V_47 ; V_45 ++ ) {
if ( ! F_43 ( V_45 ) )
continue;
F_69 ( F_59 ( V_45 ) ) ;
}
return 0 ;
}
static int T_3 F_70 ( int V_63 , struct V_50 * V_50 ,
unsigned long V_74 )
{
int V_68 ;
if ( F_43 ( V_74 ) )
return - V_21 ;
V_68 = F_71 ( V_50 , V_74 ) ;
if ( V_68 < 0 )
return V_68 ;
V_68 = F_67 ( V_50 , V_74 ) ;
if ( V_68 < 0 )
return V_68 ;
return F_72 ( V_63 , F_73 ( V_74 ) ) ;
}
int T_4 F_74 ( int V_63 , struct V_50 * V_50 , unsigned long V_74 ,
unsigned long V_47 )
{
unsigned long V_33 ;
int V_76 = 0 ;
int V_77 , V_78 ;
struct V_79 * V_80 ;
F_75 ( V_50 ) ;
V_77 = F_37 ( V_74 ) ;
V_78 = F_37 ( V_74 + V_47 - 1 ) ;
V_80 = F_76 ( ( unsigned long ) F_59 ( V_74 ) ) ;
if ( V_80 ) {
if ( V_80 -> V_81 != V_74
|| F_77 ( V_80 ) > V_47 ) {
F_78 ( L_5 ) ;
V_76 = - V_82 ;
goto V_83;
}
V_80 -> V_84 = 0 ;
}
for ( V_33 = V_77 ; V_33 <= V_78 ; V_33 ++ ) {
V_76 = F_70 ( V_63 , V_50 , F_79 ( V_33 ) ) ;
if ( V_76 && ( V_76 != - V_21 ) )
break;
V_76 = 0 ;
}
F_80 () ;
V_83:
F_81 ( V_50 ) ;
return V_76 ;
}
static int F_82 ( int V_63 , struct V_50 * V_50 ,
unsigned long V_29 ,
unsigned long V_46 )
{
struct V_34 * V_35 ;
for (; V_29 < V_46 ; V_29 += V_38 ) {
V_35 = F_73 ( V_29 ) ;
if ( F_9 ( ! F_83 ( V_35 ) ) )
continue;
if ( F_9 ( F_84 ( V_29 ) != V_63 ) )
continue;
if ( V_50 && V_50 != F_85 ( F_59 ( V_29 ) ) )
continue;
return V_29 ;
}
return 0 ;
}
static int F_86 ( int V_63 , struct V_50 * V_50 ,
unsigned long V_29 ,
unsigned long V_46 )
{
struct V_34 * V_35 ;
unsigned long V_45 ;
V_45 = V_46 - 1 ;
for (; V_45 >= V_29 ; V_45 -= V_38 ) {
V_35 = F_73 ( V_45 ) ;
if ( F_9 ( ! F_83 ( V_35 ) ) )
continue;
if ( F_9 ( F_84 ( V_45 ) != V_63 ) )
continue;
if ( V_50 && V_50 != F_85 ( F_59 ( V_45 ) ) )
continue;
return V_45 ;
}
return 0 ;
}
static void F_87 ( struct V_50 * V_50 , unsigned long V_29 ,
unsigned long V_46 )
{
unsigned long V_59 = V_50 -> V_59 ;
unsigned long V_85 = F_51 ( V_50 ) ;
unsigned long F_51 = V_85 ;
unsigned long V_45 ;
struct V_34 * V_35 ;
int V_63 = F_88 ( V_50 ) ;
F_50 ( V_50 ) ;
if ( V_59 == V_29 ) {
V_45 = F_82 ( V_63 , V_50 , V_46 ,
F_51 ) ;
if ( V_45 ) {
V_50 -> V_59 = V_45 ;
V_50 -> V_60 = F_51 - V_45 ;
}
} else if ( F_51 == V_46 ) {
V_45 = F_86 ( V_63 , V_50 , V_59 ,
V_29 ) ;
if ( V_45 )
V_50 -> V_60 = V_45 - V_59 + 1 ;
}
V_45 = V_59 ;
for (; V_45 < F_51 ; V_45 += V_38 ) {
V_35 = F_73 ( V_45 ) ;
if ( F_9 ( ! F_83 ( V_35 ) ) )
continue;
if ( F_85 ( F_59 ( V_45 ) ) != V_50 )
continue;
if ( V_29 == V_45 )
continue;
F_54 ( V_50 ) ;
return;
}
V_50 -> V_59 = 0 ;
V_50 -> V_60 = 0 ;
F_54 ( V_50 ) ;
}
static void F_89 ( struct V_43 * V_44 ,
unsigned long V_29 , unsigned long V_46 )
{
unsigned long V_86 = V_44 -> V_57 ;
unsigned long V_87 = F_47 ( V_44 ) ;
unsigned long F_47 = V_87 ;
unsigned long V_45 ;
struct V_34 * V_35 ;
int V_63 = V_44 -> V_49 ;
if ( V_86 == V_29 ) {
V_45 = F_82 ( V_63 , NULL , V_46 ,
F_47 ) ;
if ( V_45 ) {
V_44 -> V_57 = V_45 ;
V_44 -> V_73 = F_47 - V_45 ;
}
} else if ( F_47 == V_46 ) {
V_45 = F_86 ( V_63 , NULL , V_86 ,
V_29 ) ;
if ( V_45 )
V_44 -> V_73 = V_45 - V_86 + 1 ;
}
V_45 = V_86 ;
for (; V_45 < F_47 ; V_45 += V_38 ) {
V_35 = F_73 ( V_45 ) ;
if ( F_9 ( ! F_83 ( V_35 ) ) )
continue;
if ( F_84 ( V_45 ) != V_63 )
continue;
if ( V_29 == V_45 )
continue;
return;
}
V_44 -> V_57 = 0 ;
V_44 -> V_73 = 0 ;
}
static void F_90 ( struct V_50 * V_50 , unsigned long V_29 )
{
struct V_43 * V_44 = V_50 -> V_64 ;
int V_47 = V_38 ;
int V_61 ;
unsigned long V_17 ;
V_61 = V_50 - V_44 -> V_52 ;
F_63 ( V_50 -> V_64 , & V_17 ) ;
F_87 ( V_50 , V_29 , V_29 + V_47 ) ;
F_89 ( V_44 , V_29 , V_29 + V_47 ) ;
F_64 ( V_50 -> V_64 , & V_17 ) ;
}
static int F_91 ( struct V_50 * V_50 , struct V_34 * V_35 ,
unsigned long V_88 )
{
unsigned long V_29 ;
int V_89 ;
int V_68 = - V_82 ;
if ( ! F_83 ( V_35 ) )
return V_68 ;
V_68 = F_92 ( V_35 ) ;
if ( V_68 )
return V_68 ;
V_89 = F_93 ( V_35 ) ;
V_29 = F_79 ( V_89 ) ;
F_90 ( V_50 , V_29 ) ;
F_94 ( V_50 , V_35 , V_88 ) ;
return 0 ;
}
int F_95 ( struct V_50 * V_50 , unsigned long V_74 ,
unsigned long V_47 )
{
unsigned long V_33 ;
unsigned long V_88 = 0 ;
int V_90 , V_68 = 0 ;
if ( F_96 ( V_50 ) ) {
struct V_23 * V_23 = F_59 ( V_74 ) ;
struct V_79 * V_80 ;
V_80 = F_76 ( ( unsigned long ) V_23 ) ;
if ( V_80 )
V_88 = F_77 ( V_80 ) ;
} else {
T_5 V_10 , V_11 ;
V_10 = V_74 << V_39 ;
V_11 = V_47 * V_91 ;
V_68 = F_97 ( & V_20 , V_10 ,
V_11 ) ;
if ( V_68 ) {
T_5 V_92 = V_10 + V_11 - 1 ;
F_98 ( L_6 ,
& V_10 , & V_92 , V_68 ) ;
}
}
F_75 ( V_50 ) ;
F_31 ( V_74 & ~ V_93 ) ;
F_31 ( V_47 % V_38 ) ;
V_90 = V_47 / V_38 ;
for ( V_33 = 0 ; V_33 < V_90 ; V_33 ++ ) {
unsigned long V_45 = V_74 + V_33 * V_38 ;
V_68 = F_91 ( V_50 , F_73 ( V_45 ) , V_88 ) ;
V_88 = 0 ;
if ( V_68 )
break;
}
F_81 ( V_50 ) ;
return V_68 ;
}
int F_99 ( T_6 V_94 )
{
int V_95 = - V_82 ;
F_2 () ;
F_5 ( & V_96 ) ;
if ( V_97 == V_98 ) {
V_97 = V_94 ;
V_95 = 0 ;
}
F_6 ( & V_96 ) ;
F_7 () ;
return V_95 ;
}
int F_100 ( T_6 V_94 )
{
int V_95 = - V_82 ;
F_2 () ;
F_5 ( & V_96 ) ;
if ( V_97 == V_94 ) {
V_97 = V_98 ;
V_95 = 0 ;
}
F_6 ( & V_96 ) ;
F_7 () ;
return V_95 ;
}
void F_101 ( struct V_23 * V_23 )
{
}
void F_102 ( struct V_23 * V_23 )
{
F_103 ( V_23 , 1 ) ;
}
void F_104 ( struct V_23 * V_23 )
{
F_105 ( V_23 ) ;
}
static void V_98 ( struct V_23 * V_23 )
{
F_101 ( V_23 ) ;
F_102 ( V_23 ) ;
F_104 ( V_23 ) ;
}
static int F_106 ( unsigned long V_29 , unsigned long V_47 ,
void * V_99 )
{
unsigned long V_33 ;
unsigned long V_100 = * ( unsigned long * ) V_99 ;
struct V_23 * V_23 ;
if ( F_107 ( F_59 ( V_29 ) ) )
for ( V_33 = 0 ; V_33 < V_47 ; V_33 ++ ) {
V_23 = F_59 ( V_29 + V_33 ) ;
(* V_97)( V_23 ) ;
V_100 ++ ;
}
* ( unsigned long * ) V_99 = V_100 ;
return 0 ;
}
static bool F_108 ( struct V_50 * V_50 )
{
return true ;
}
static bool F_108 ( struct V_50 * V_50 )
{
return F_109 ( F_88 ( V_50 ) , V_101 ) ;
}
static void F_110 ( unsigned long V_47 ,
struct V_50 * V_50 , struct V_102 * V_99 )
{
int V_63 = F_88 ( V_50 ) ;
enum V_61 V_103 = V_104 ;
if ( V_105 == V_101 )
V_103 = V_106 ;
if ( F_57 ( V_50 ) <= V_103 && ! F_109 ( V_63 , V_101 ) )
V_99 -> V_107 = V_63 ;
else
V_99 -> V_107 = - 1 ;
#ifdef F_111
V_103 = V_108 ;
if ( V_105 == V_109 )
V_103 = V_106 ;
if ( F_57 ( V_50 ) <= V_103 && ! F_109 ( V_63 , V_109 ) )
V_99 -> V_110 = V_63 ;
else
V_99 -> V_110 = - 1 ;
#else
V_99 -> V_110 = V_99 -> V_107 ;
#endif
if ( ! F_109 ( V_63 , V_105 ) )
V_99 -> V_111 = V_63 ;
else
V_99 -> V_111 = - 1 ;
}
static void F_112 ( int V_48 , struct V_102 * V_99 )
{
if ( V_99 -> V_107 >= 0 )
F_113 ( V_48 , V_101 ) ;
if ( V_99 -> V_110 >= 0 )
F_113 ( V_48 , V_109 ) ;
F_113 ( V_48 , V_105 ) ;
}
int T_4 F_114 ( unsigned long V_45 , unsigned long V_47 , int V_112 )
{
unsigned long V_17 ;
unsigned long V_100 = 0 ;
struct V_50 * V_50 ;
int V_113 = 0 ;
int V_63 ;
int V_68 ;
struct V_102 V_99 ;
V_50 = F_85 ( F_59 ( V_45 ) ) ;
if ( ( F_57 ( V_50 ) > V_104 ||
V_112 == V_114 ) &&
! F_108 ( V_50 ) )
return - V_82 ;
if ( V_112 == V_115 &&
F_57 ( V_50 ) == V_106 ) {
if ( F_62 ( V_50 - 1 , V_50 , V_45 , V_45 + V_47 ) )
return - V_82 ;
}
if ( V_112 == V_114 &&
F_57 ( V_50 ) == V_106 - 1 ) {
if ( F_65 ( V_50 , V_50 + 1 , V_45 , V_45 + V_47 ) )
return - V_82 ;
}
V_50 = F_85 ( F_59 ( V_45 ) ) ;
V_99 . V_29 = V_45 ;
V_99 . V_47 = V_47 ;
F_110 ( V_47 , V_50 , & V_99 ) ;
V_63 = F_88 ( V_50 ) ;
V_68 = V_102 ( V_116 , & V_99 ) ;
V_68 = F_115 ( V_68 ) ;
if ( V_68 )
goto V_117;
F_5 ( & V_118 ) ;
if ( ! F_116 ( V_50 ) ) {
V_113 = 1 ;
F_117 ( NULL , V_50 ) ;
}
V_68 = F_118 ( V_45 , V_47 , & V_100 ,
F_106 ) ;
if ( V_68 ) {
if ( V_113 )
F_119 ( V_50 ) ;
F_6 ( & V_118 ) ;
goto V_117;
}
V_50 -> V_119 += V_100 ;
F_63 ( V_50 -> V_64 , & V_17 ) ;
V_50 -> V_64 -> V_120 += V_100 ;
F_64 ( V_50 -> V_64 , & V_17 ) ;
if ( V_100 ) {
F_112 ( V_63 , & V_99 ) ;
if ( V_113 )
F_117 ( NULL , NULL ) ;
else
F_120 ( V_50 ) ;
}
F_6 ( & V_118 ) ;
F_121 () ;
if ( V_100 ) {
F_122 ( V_63 ) ;
F_123 ( V_63 ) ;
}
V_121 = F_124 () ;
F_125 () ;
if ( V_100 )
V_102 ( V_122 , & V_99 ) ;
return 0 ;
V_117:
F_22 ( L_7 ,
( unsigned long long ) V_45 << V_39 ,
( ( ( unsigned long long ) V_45 + V_47 ) << V_39 ) - 1 ) ;
V_102 ( V_123 , & V_99 ) ;
return V_68 ;
}
static void F_126 ( T_7 * V_44 )
{
struct V_50 * V_85 ;
for ( V_85 = V_44 -> V_52 ; V_85 < V_44 -> V_52 + V_53 ; V_85 ++ )
V_85 -> V_119 = 0 ;
V_44 -> V_120 = 0 ;
}
static T_7 T_4 * F_127 ( int V_63 , T_2 V_10 )
{
struct V_43 * V_44 ;
unsigned long V_124 [ V_53 ] = { 0 } ;
unsigned long V_125 [ V_53 ] = { 0 } ;
unsigned long V_29 = F_128 ( V_10 ) ;
V_44 = F_129 ( V_63 ) ;
if ( ! V_44 ) {
V_44 = F_130 ( V_63 ) ;
if ( ! V_44 )
return NULL ;
F_131 ( V_63 , V_44 ) ;
} else {
V_44 -> V_126 = 0 ;
V_44 -> V_127 = 0 ;
}
F_132 ( V_63 , V_124 , V_29 , V_125 ) ;
F_5 ( & V_118 ) ;
F_117 ( V_44 , NULL ) ;
F_6 ( & V_118 ) ;
F_133 ( V_44 ) ;
F_126 ( V_44 ) ;
return V_44 ;
}
static void F_134 ( int V_63 , T_7 * V_44 )
{
F_131 ( V_63 , NULL ) ;
F_135 ( V_44 ) ;
return;
}
int F_136 ( int V_63 )
{
T_7 * V_44 ;
int V_68 ;
if ( F_137 ( V_63 ) )
return 0 ;
F_12 () ;
V_44 = F_127 ( V_63 , 0 ) ;
if ( ! V_44 ) {
F_138 ( L_8 , V_63 ) ;
V_68 = - V_14 ;
goto V_83;
}
F_139 ( V_63 ) ;
V_68 = F_140 ( V_63 ) ;
F_31 ( V_68 ) ;
if ( V_44 -> V_128 -> V_129 -> V_50 == NULL ) {
F_5 ( & V_118 ) ;
F_117 ( NULL , NULL ) ;
F_6 ( & V_118 ) ;
}
V_83:
F_17 () ;
return V_68 ;
}
static int F_141 ( T_2 V_10 , T_2 V_11 )
{
T_2 V_29 = F_128 ( V_10 ) ;
T_2 V_47 = V_11 >> V_39 ;
if ( ( V_29 & ~ V_93 ) ||
( V_47 % V_38 ) || ( ! V_47 ) ) {
F_138 ( L_9 ,
( unsigned long long ) V_10 ,
( unsigned long long ) V_11 ) ;
return - V_82 ;
}
return 0 ;
}
static int F_142 ( int V_63 , T_2 V_10 , T_2 V_11 )
{
unsigned long V_29 = V_10 >> V_39 ;
T_7 * V_44 = F_129 ( V_63 ) ;
struct V_50 * V_130 = V_44 -> V_52 + V_106 ;
if ( F_52 ( V_130 ) )
return 0 ;
if ( V_130 -> V_59 <= V_29 )
return 1 ;
return 0 ;
}
int F_143 ( int V_63 , T_2 V_10 , T_2 V_11 , int V_131 ,
bool V_132 )
{
#ifdef F_144
if ( V_132 )
return V_133 ;
#endif
if ( F_142 ( V_63 , V_10 , V_11 ) )
return V_106 ;
return V_131 ;
}
static int F_145 ( struct V_134 * V_135 , void * V_99 )
{
return F_146 ( V_135 , V_122 , V_136 ) ;
}
int T_4 F_147 ( int V_63 , struct V_9 * V_12 , bool V_137 )
{
T_2 V_10 , V_11 ;
T_7 * V_44 = NULL ;
bool V_138 ;
bool V_139 ;
int V_68 ;
V_10 = V_12 -> V_10 ;
V_11 = F_148 ( V_12 ) ;
V_68 = F_141 ( V_10 , V_11 ) ;
if ( V_68 )
return V_68 ;
{
void * V_87 = F_129 ( V_63 ) ;
V_138 = ! V_87 ;
}
F_12 () ;
F_149 ( V_10 , V_11 , V_63 ) ;
V_139 = ! F_137 ( V_63 ) ;
if ( V_139 ) {
V_44 = F_127 ( V_63 , V_10 ) ;
V_68 = - V_14 ;
if ( ! V_44 )
goto error;
}
V_68 = F_150 ( V_63 , V_10 , V_11 , false ) ;
if ( V_68 < 0 )
goto error;
F_139 ( V_63 ) ;
if ( V_139 ) {
V_68 = F_140 ( V_63 ) ;
F_31 ( V_68 ) ;
}
F_151 ( V_10 , V_10 + V_11 , L_3 ) ;
if ( V_137 )
F_152 ( F_128 ( V_10 ) , F_153 ( V_10 + V_11 - 1 ) ,
NULL , F_145 ) ;
goto V_83;
error:
if ( V_138 )
F_134 ( V_63 , V_44 ) ;
F_154 ( V_10 , V_11 ) ;
V_83:
F_17 () ;
return V_68 ;
}
int T_4 F_155 ( int V_63 , T_2 V_10 , T_2 V_11 )
{
struct V_9 * V_12 ;
int V_68 ;
V_12 = F_18 ( V_10 , V_11 ) ;
if ( F_156 ( V_12 ) )
return F_157 ( V_12 ) ;
V_68 = F_147 ( V_63 , V_12 , V_2 ) ;
if ( V_68 < 0 )
F_24 ( V_12 ) ;
return V_68 ;
}
static inline int F_158 ( struct V_23 * V_23 )
{
return F_159 ( V_23 ) && F_160 ( V_23 ) >= V_140 ;
}
static struct V_23 * F_161 ( struct V_23 * V_23 )
{
F_31 ( F_162 ( V_23 ) & ( V_141 - 1 ) ) ;
if ( F_158 ( V_23 ) ) {
int V_142 ;
V_142 = F_160 ( V_23 ) ;
if ( ( V_142 < V_143 ) && ( V_142 >= V_140 ) )
return V_23 + ( 1 << V_142 ) ;
}
return V_23 + V_141 ;
}
bool F_163 ( unsigned long V_29 , unsigned long V_47 )
{
struct V_23 * V_23 = F_59 ( V_29 ) ;
struct V_23 * V_144 = V_23 + V_47 ;
for (; V_23 < V_144 ; V_23 = F_161 ( V_23 ) ) {
if ( ! F_164 ( V_23 ) )
return false ;
F_165 () ;
}
return true ;
}
int F_166 ( unsigned long V_29 , unsigned long V_46 )
{
unsigned long V_45 , V_145 ;
struct V_50 * V_50 = NULL ;
struct V_23 * V_23 ;
int V_33 ;
for ( V_45 = V_29 , V_145 = F_167 ( V_29 ) ;
V_45 < V_46 ;
V_45 = V_145 + 1 , V_145 += V_38 ) {
if ( ! F_168 ( F_37 ( V_45 ) ) )
continue;
for (; V_45 < V_145 && V_45 < V_46 ;
V_45 += V_146 ) {
V_33 = 0 ;
while ( ( V_33 < V_146 ) &&
! F_169 ( V_45 + V_33 ) )
V_33 ++ ;
if ( V_33 == V_146 )
continue;
V_23 = F_59 ( V_45 + V_33 ) ;
if ( V_50 && F_85 ( V_23 ) != V_50 )
return 0 ;
V_50 = F_85 ( V_23 ) ;
}
}
return 1 ;
}
static unsigned long F_170 ( unsigned long V_10 , unsigned long V_16 )
{
unsigned long V_45 ;
struct V_23 * V_23 ;
for ( V_45 = V_10 ; V_45 < V_16 ; V_45 ++ ) {
if ( F_43 ( V_45 ) ) {
V_23 = F_59 ( V_45 ) ;
if ( F_171 ( V_23 ) )
return V_45 ;
if ( F_172 ( V_23 ) ) {
if ( F_173 ( V_23 ) )
return V_45 ;
else
V_45 = F_174 ( V_45 + 1 ,
1 << F_175 ( V_23 ) ) - 1 ;
}
}
}
return 0 ;
}
static int
F_176 ( unsigned long V_29 , unsigned long V_46 )
{
unsigned long V_45 ;
struct V_23 * V_23 ;
int V_147 = V_148 ;
int V_149 = 0 ;
int V_68 = 0 ;
F_177 ( V_150 ) ;
for ( V_45 = V_29 ; V_45 < V_46 && V_147 > 0 ; V_45 ++ ) {
if ( ! F_43 ( V_45 ) )
continue;
V_23 = F_59 ( V_45 ) ;
if ( F_172 ( V_23 ) ) {
struct V_23 * V_151 = F_178 ( V_23 ) ;
V_45 = F_162 ( V_151 ) + ( 1 << F_175 ( V_151 ) ) - 1 ;
if ( F_175 ( V_151 ) > V_152 ) {
V_68 = - V_153 ;
break;
}
if ( F_179 ( V_23 , & V_150 ) )
V_147 -= 1 << F_175 ( V_151 ) ;
continue;
}
if ( ! F_180 ( V_23 ) )
continue;
V_68 = F_181 ( V_23 ) ;
if ( ! V_68 ) {
F_182 ( V_23 ) ;
F_183 ( & V_23 -> V_24 , & V_150 ) ;
V_147 -- ;
F_184 ( V_23 , V_154 +
F_185 ( V_23 ) ) ;
} else {
#ifdef F_186
F_187 ( L_10 , V_45 ) ;
F_188 ( V_23 , L_11 ) ;
#endif
F_182 ( V_23 ) ;
if ( F_189 ( V_23 ) ) {
V_149 ++ ;
V_68 = - V_153 ;
break;
}
}
}
if ( ! F_190 ( & V_150 ) ) {
if ( V_149 ) {
F_191 ( & V_150 ) ;
goto V_83;
}
V_68 = F_192 ( & V_150 , V_155 , NULL , 0 ,
V_156 , V_157 ) ;
if ( V_68 )
F_191 ( & V_150 ) ;
}
V_83:
return V_68 ;
}
static int
F_193 ( unsigned long V_10 , unsigned long V_47 ,
void * V_158 )
{
F_194 ( V_10 , V_10 + V_47 ) ;
return 0 ;
}
static void
F_195 ( unsigned long V_29 , unsigned long V_46 )
{
F_118 ( V_29 , V_46 - V_29 , NULL ,
F_193 ) ;
}
static int
F_196 ( unsigned long V_29 , unsigned long V_47 ,
void * V_158 )
{
int V_68 ;
long V_159 = * ( long * ) V_158 ;
V_68 = F_197 ( V_29 , V_29 + V_47 , true ) ;
V_159 = V_47 ;
if ( ! V_68 )
* ( long * ) V_158 += V_159 ;
return V_68 ;
}
static long
F_198 ( unsigned long V_29 , unsigned long V_46 )
{
long V_159 = 0 ;
int V_68 ;
V_68 = F_118 ( V_29 , V_46 - V_29 , & V_159 ,
F_196 ) ;
if ( V_68 < 0 )
V_159 = ( long ) V_68 ;
return V_159 ;
}
static bool F_199 ( struct V_50 * V_50 , unsigned long V_47 )
{
return true ;
}
static bool F_199 ( struct V_50 * V_50 , unsigned long V_47 )
{
struct V_43 * V_44 = V_50 -> V_64 ;
unsigned long V_119 = 0 ;
enum V_61 V_160 ;
for ( V_160 = 0 ; V_160 <= V_104 ; V_160 ++ )
V_119 += V_44 -> V_52 [ V_160 ] . V_119 ;
if ( V_119 > V_47 )
return true ;
V_119 = 0 ;
for (; V_160 <= V_106 ; V_160 ++ )
V_119 += V_44 -> V_52 [ V_160 ] . V_119 ;
return V_119 == 0 ;
}
static int T_1 F_200 ( char * V_87 )
{
#ifdef F_201
F_202 ( true ) ;
V_161 = true ;
#else
F_98 ( L_12 ) ;
#endif
return 0 ;
}
static void F_203 ( unsigned long V_47 ,
struct V_50 * V_50 , struct V_102 * V_99 )
{
struct V_43 * V_44 = V_50 -> V_64 ;
unsigned long V_119 = 0 ;
enum V_61 V_160 , V_103 = V_104 ;
if ( V_105 == V_101 )
V_103 = V_106 ;
for ( V_160 = 0 ; V_160 <= V_103 ; V_160 ++ )
V_119 += V_44 -> V_52 [ V_160 ] . V_119 ;
if ( F_57 ( V_50 ) <= V_103 && V_47 >= V_119 )
V_99 -> V_107 = F_88 ( V_50 ) ;
else
V_99 -> V_107 = - 1 ;
#ifdef F_111
V_103 = V_108 ;
if ( V_105 == V_109 )
V_103 = V_106 ;
for (; V_160 <= V_103 ; V_160 ++ )
V_119 += V_44 -> V_52 [ V_160 ] . V_119 ;
if ( F_57 ( V_50 ) <= V_103 && V_47 >= V_119 )
V_99 -> V_110 = F_88 ( V_50 ) ;
else
V_99 -> V_110 = - 1 ;
#else
V_99 -> V_110 = V_99 -> V_107 ;
#endif
V_103 = V_106 ;
for (; V_160 <= V_103 ; V_160 ++ )
V_119 += V_44 -> V_52 [ V_160 ] . V_119 ;
if ( V_47 >= V_119 )
V_99 -> V_111 = F_88 ( V_50 ) ;
else
V_99 -> V_111 = - 1 ;
}
static void F_204 ( int V_48 , struct V_102 * V_99 )
{
if ( V_99 -> V_107 >= 0 )
F_205 ( V_48 , V_101 ) ;
if ( ( V_105 != V_101 ) &&
( V_99 -> V_110 >= 0 ) )
F_205 ( V_48 , V_109 ) ;
if ( ( V_105 != V_109 ) &&
( V_99 -> V_111 >= 0 ) )
F_205 ( V_48 , V_105 ) ;
}
static int T_4 F_206 ( unsigned long V_29 ,
unsigned long V_46 , unsigned long V_162 )
{
unsigned long V_45 , V_47 , V_163 ;
long V_164 ;
int V_68 , V_165 , V_166 , V_48 ;
unsigned long V_17 ;
struct V_50 * V_50 ;
struct V_102 V_99 ;
if ( ! F_207 ( V_29 , V_141 ) )
return - V_82 ;
if ( ! F_207 ( V_46 , V_141 ) )
return - V_82 ;
if ( ! F_166 ( V_29 , V_46 ) )
return - V_82 ;
V_50 = F_85 ( F_59 ( V_29 ) ) ;
V_48 = F_88 ( V_50 ) ;
V_47 = V_46 - V_29 ;
if ( F_57 ( V_50 ) <= V_104 && ! F_199 ( V_50 , V_47 ) )
return - V_82 ;
V_68 = F_208 ( V_29 , V_46 ,
V_167 , true ) ;
if ( V_68 )
return V_68 ;
V_99 . V_29 = V_29 ;
V_99 . V_47 = V_47 ;
F_203 ( V_47 , V_50 , & V_99 ) ;
V_68 = V_102 ( V_168 , & V_99 ) ;
V_68 = F_115 ( V_68 ) ;
if ( V_68 )
goto V_169;
V_45 = V_29 ;
V_163 = V_170 + V_162 ;
V_165 = 0 ;
V_166 = 5 ;
V_171:
V_68 = - V_172 ;
if ( F_209 ( V_170 , V_163 ) )
goto V_169;
V_68 = - V_173 ;
if ( F_210 ( V_5 ) )
goto V_169;
V_68 = 0 ;
if ( V_165 ) {
F_211 () ;
F_165 () ;
F_212 ( V_50 ) ;
}
V_45 = F_170 ( V_29 , V_46 ) ;
if ( V_45 ) {
V_68 = F_176 ( V_45 , V_46 ) ;
if ( ! V_68 ) {
V_165 = 1 ;
goto V_171;
} else {
if ( V_68 < 0 )
if ( -- V_166 == 0 )
goto V_169;
F_213 () ;
V_165 = 1 ;
goto V_171;
}
}
F_211 () ;
F_213 () ;
F_212 ( V_50 ) ;
F_214 ( V_29 , V_46 ) ;
V_164 = F_198 ( V_29 , V_46 ) ;
if ( V_164 < 0 ) {
V_68 = - V_153 ;
goto V_169;
}
F_215 ( L_13 , V_164 ) ;
F_195 ( V_29 , V_46 ) ;
F_216 ( V_29 , V_46 , V_167 ) ;
F_103 ( F_59 ( V_29 ) , - V_164 ) ;
V_50 -> V_119 -= V_164 ;
F_63 ( V_50 -> V_64 , & V_17 ) ;
V_50 -> V_64 -> V_120 -= V_164 ;
F_64 ( V_50 -> V_64 , & V_17 ) ;
F_121 () ;
if ( ! F_116 ( V_50 ) ) {
F_119 ( V_50 ) ;
F_5 ( & V_118 ) ;
F_117 ( NULL , NULL ) ;
F_6 ( & V_118 ) ;
} else
F_120 ( V_50 ) ;
F_204 ( V_48 , & V_99 ) ;
if ( V_99 . V_111 >= 0 ) {
F_217 ( V_48 ) ;
F_218 ( V_48 ) ;
}
V_121 = F_124 () ;
F_125 () ;
V_102 ( V_136 , & V_99 ) ;
return 0 ;
V_169:
F_22 ( L_14 ,
( unsigned long long ) V_29 << V_39 ,
( ( unsigned long long ) V_46 << V_39 ) - 1 ) ;
V_102 ( V_174 , & V_99 ) ;
F_216 ( V_29 , V_46 , V_167 ) ;
return V_68 ;
}
int F_219 ( unsigned long V_29 , unsigned long V_47 )
{
return F_206 ( V_29 , V_29 + V_47 , 120 * V_175 ) ;
}
int F_152 ( unsigned long V_29 , unsigned long V_46 ,
void * V_99 , int (* F_220)( struct V_134 * , void * ) )
{
struct V_134 * V_135 = NULL ;
struct V_34 * V_176 ;
unsigned long V_45 , V_32 ;
int V_68 ;
for ( V_45 = V_29 ; V_45 < V_46 ; V_45 += V_38 ) {
V_32 = F_37 ( V_45 ) ;
if ( ! F_168 ( V_32 ) )
continue;
V_176 = F_38 ( V_32 ) ;
if ( V_135 )
if ( ( V_32 >= V_135 -> V_177 ) &&
( V_32 <= V_135 -> V_178 ) )
continue;
V_135 = F_221 ( V_176 , V_135 ) ;
if ( ! V_135 )
continue;
V_68 = F_220 ( V_135 , V_99 ) ;
if ( V_68 ) {
F_222 ( & V_135 -> V_179 . V_180 ) ;
return V_68 ;
}
}
if ( V_135 )
F_222 ( & V_135 -> V_179 . V_180 ) ;
return 0 ;
}
static int F_223 ( struct V_134 * V_135 , void * V_99 )
{
int V_68 = ! F_224 ( V_135 ) ;
if ( F_9 ( V_68 ) ) {
T_8 V_181 , V_182 ;
V_181 = F_225 ( F_79 ( V_135 -> V_177 ) ) ;
V_182 = F_225 ( F_79 ( V_135 -> V_178 + 1 ) ) - 1 ;
F_98 ( L_15 ,
& V_181 , & V_182 ) ;
}
return V_68 ;
}
static int F_226 ( T_7 * V_44 )
{
int V_183 ;
F_227 (cpu) {
if ( F_228 ( V_183 ) == V_44 -> V_49 )
return - V_153 ;
}
return 0 ;
}
static void F_229 ( T_7 * V_44 )
{
#ifdef F_230
int V_183 ;
F_231 (cpu)
if ( F_228 ( V_183 ) == V_44 -> V_49 )
F_232 ( V_183 ) ;
#endif
}
static int F_233 ( T_7 * V_44 )
{
int V_68 ;
V_68 = F_226 ( V_44 ) ;
if ( V_68 )
return V_68 ;
F_229 ( V_44 ) ;
return 0 ;
}
void F_234 ( int V_63 )
{
T_7 * V_44 = F_129 ( V_63 ) ;
unsigned long V_29 = V_44 -> V_57 ;
unsigned long V_46 = V_29 + V_44 -> V_73 ;
unsigned long V_45 ;
int V_33 ;
for ( V_45 = V_29 ; V_45 < V_46 ; V_45 += V_38 ) {
unsigned long V_32 = F_37 ( V_45 ) ;
if ( ! F_168 ( V_32 ) )
continue;
if ( F_84 ( V_45 ) != V_63 )
continue;
return;
}
if ( F_233 ( V_44 ) )
return;
F_235 ( V_63 ) ;
F_236 ( V_63 ) ;
for ( V_33 = 0 ; V_33 < V_53 ; V_33 ++ ) {
struct V_50 * V_50 = V_44 -> V_52 + V_33 ;
if ( F_237 ( V_50 -> V_56 ) ) {
F_238 ( V_50 -> V_56 ) ;
V_50 -> V_56 = NULL ;
}
}
}
void T_4 F_239 ( int V_63 , T_2 V_10 , T_2 V_11 )
{
int V_68 ;
F_31 ( F_141 ( V_10 , V_11 ) ) ;
F_12 () ;
V_68 = F_152 ( F_128 ( V_10 ) , F_153 ( V_10 + V_11 - 1 ) , NULL ,
F_223 ) ;
if ( V_68 )
F_240 () ;
F_241 ( V_10 , V_10 + V_11 , L_3 ) ;
F_242 ( V_10 , V_11 ) ;
F_154 ( V_10 , V_11 ) ;
F_243 ( V_10 , V_11 ) ;
F_234 ( V_63 ) ;
F_17 () ;
}
