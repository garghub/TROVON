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
V_47 = F_41 ( sizeof( struct V_43 ) ) >> V_39 ;
V_23 = F_40 ( V_44 ) ;
for ( V_33 = 0 ; V_33 < V_47 ; V_33 ++ , V_23 ++ )
F_26 ( V_48 , V_23 , V_50 ) ;
V_45 = V_44 -> V_51 ;
V_46 = F_46 ( V_44 ) ;
for (; V_45 < V_46 ; V_45 += V_38 ) {
if ( F_43 ( V_45 ) && ( F_47 ( V_45 ) == V_48 ) )
F_36 ( V_45 ) ;
}
}
static void T_3 F_48 ( struct V_52 * V_52 , unsigned long V_29 ,
unsigned long V_46 )
{
unsigned long V_53 ;
F_49 ( V_52 ) ;
V_53 = F_50 ( V_52 ) ;
if ( F_51 ( V_52 ) || V_29 < V_52 -> V_54 )
V_52 -> V_54 = V_29 ;
V_52 -> V_55 = F_52 ( V_53 , V_46 ) -
V_52 -> V_54 ;
F_53 ( V_52 ) ;
}
static void F_54 ( struct V_52 * V_52 , unsigned long V_29 ,
unsigned long V_46 )
{
F_49 ( V_52 ) ;
if ( V_46 - V_29 ) {
V_52 -> V_54 = V_29 ;
V_52 -> V_55 = V_46 - V_29 ;
} else {
V_52 -> V_54 = 0 ;
V_52 -> V_55 = 0 ;
}
F_53 ( V_52 ) ;
}
static void F_55 ( struct V_52 * V_52 , unsigned long V_29 ,
unsigned long V_46 )
{
enum V_56 V_57 = F_56 ( V_52 ) ;
int V_58 = V_52 -> V_59 -> V_49 ;
unsigned long V_45 ;
for ( V_45 = V_29 ; V_45 < V_46 ; V_45 ++ )
F_57 ( F_58 ( V_45 ) , V_57 , V_58 , V_45 ) ;
}
static int T_4 F_59 ( struct V_52 * V_52 ,
unsigned long V_29 , unsigned long V_60 )
{
if ( ! F_60 ( V_52 ) )
return F_61 ( V_52 , V_29 , V_60 ) ;
return 0 ;
}
static int T_3 F_62 ( struct V_52 * V_61 , struct V_52 * V_62 ,
unsigned long V_29 , unsigned long V_46 )
{
int V_63 ;
unsigned long V_17 ;
unsigned long V_64 ;
V_63 = F_59 ( V_61 , V_29 , V_46 - V_29 ) ;
if ( V_63 )
return V_63 ;
F_63 ( V_61 -> V_59 , & V_17 ) ;
if ( V_46 > F_50 ( V_62 ) )
goto V_65;
if ( V_29 > V_62 -> V_54 )
goto V_65;
if ( V_46 <= V_62 -> V_54 )
goto V_65;
if ( ! F_51 ( V_61 ) )
V_64 = V_61 -> V_54 ;
else
V_64 = V_29 ;
F_54 ( V_61 , V_64 , V_46 ) ;
F_54 ( V_62 , V_46 , F_50 ( V_62 ) ) ;
F_64 ( V_61 -> V_59 , & V_17 ) ;
F_55 ( V_61 , V_29 , V_46 ) ;
return 0 ;
V_65:
F_64 ( V_61 -> V_59 , & V_17 ) ;
return - 1 ;
}
static int T_3 F_65 ( struct V_52 * V_61 , struct V_52 * V_62 ,
unsigned long V_29 , unsigned long V_46 )
{
int V_63 ;
unsigned long V_17 ;
unsigned long V_66 ;
V_63 = F_59 ( V_62 , V_29 , V_46 - V_29 ) ;
if ( V_63 )
return V_63 ;
F_63 ( V_61 -> V_59 , & V_17 ) ;
if ( V_61 -> V_54 > V_29 )
goto V_65;
if ( F_50 ( V_61 ) > V_46 )
goto V_65;
if ( V_29 >= F_50 ( V_61 ) )
goto V_65;
if ( ! F_51 ( V_62 ) )
V_66 = F_50 ( V_62 ) ;
else
V_66 = V_46 ;
F_54 ( V_61 , V_61 -> V_54 , V_29 ) ;
F_54 ( V_62 , V_29 , V_66 ) ;
F_64 ( V_61 -> V_59 , & V_17 ) ;
F_55 ( V_62 , V_29 , V_46 ) ;
return 0 ;
V_65:
F_64 ( V_61 -> V_59 , & V_17 ) ;
return - 1 ;
}
static struct V_52 * T_3 F_66 ( int V_67 ,
unsigned long V_29 , unsigned long V_46 )
{
struct V_52 * V_52 = F_67 ( F_58 ( V_29 ) ) ;
int V_63 = 0 ;
if ( V_67 < 0 )
V_63 = F_62 ( V_52 + V_67 , V_52 ,
V_29 , V_46 ) ;
else if ( V_67 )
V_63 = F_65 ( V_52 , V_52 + V_67 ,
V_29 , V_46 ) ;
if ( V_63 )
return NULL ;
return V_52 + V_67 ;
}
static void T_3 F_68 ( struct V_43 * V_44 , unsigned long V_29 ,
unsigned long V_46 )
{
unsigned long V_68 = F_46 ( V_44 ) ;
if ( ! V_44 -> V_69 || V_29 < V_44 -> V_51 )
V_44 -> V_51 = V_29 ;
V_44 -> V_69 = F_52 ( V_68 , V_46 ) -
V_44 -> V_51 ;
}
static int T_3 F_69 ( struct V_52 * V_52 , unsigned long V_70 )
{
struct V_43 * V_44 = V_52 -> V_59 ;
int V_47 = V_38 ;
int V_58 = V_44 -> V_49 ;
int V_56 ;
unsigned long V_17 , V_45 ;
int V_63 ;
V_56 = V_52 - V_44 -> V_71 ;
V_63 = F_59 ( V_52 , V_70 , V_47 ) ;
if ( V_63 )
return V_63 ;
F_63 ( V_52 -> V_59 , & V_17 ) ;
F_48 ( V_52 , V_70 , V_70 + V_47 ) ;
F_68 ( V_52 -> V_59 , V_70 ,
V_70 + V_47 ) ;
F_64 ( V_52 -> V_59 , & V_17 ) ;
F_70 ( V_47 , V_58 , V_56 ,
V_70 , V_72 ) ;
for ( V_45 = V_70 ; V_45 < V_70 + V_47 ; V_45 ++ ) {
if ( ! F_43 ( V_45 ) )
continue;
F_71 ( F_58 ( V_45 ) ) ;
}
return 0 ;
}
static int T_3 F_72 ( int V_58 , struct V_52 * V_52 ,
unsigned long V_70 )
{
int V_63 ;
if ( F_43 ( V_70 ) )
return - V_21 ;
V_63 = F_73 ( V_52 , V_70 ) ;
if ( V_63 < 0 )
return V_63 ;
V_63 = F_69 ( V_52 , V_70 ) ;
if ( V_63 < 0 )
return V_63 ;
return F_74 ( V_58 , F_75 ( V_70 ) ) ;
}
int T_4 F_76 ( int V_58 , struct V_52 * V_52 , unsigned long V_70 ,
unsigned long V_47 )
{
unsigned long V_33 ;
int V_73 = 0 ;
int V_74 , V_75 ;
struct V_76 * V_77 ;
F_77 ( V_52 ) ;
V_74 = F_37 ( V_70 ) ;
V_75 = F_37 ( V_70 + V_47 - 1 ) ;
V_77 = F_78 ( ( unsigned long ) F_58 ( V_70 ) ) ;
if ( V_77 ) {
if ( V_77 -> V_78 != V_70
|| F_79 ( V_77 ) > V_47 ) {
F_80 ( L_5 ) ;
V_73 = - V_79 ;
goto V_80;
}
V_77 -> V_81 = 0 ;
}
for ( V_33 = V_74 ; V_33 <= V_75 ; V_33 ++ ) {
V_73 = F_72 ( V_58 , V_52 , F_81 ( V_33 ) ) ;
if ( V_73 && ( V_73 != - V_21 ) )
break;
V_73 = 0 ;
}
F_82 () ;
V_80:
F_83 ( V_52 ) ;
return V_73 ;
}
static int F_84 ( int V_58 , struct V_52 * V_52 ,
unsigned long V_29 ,
unsigned long V_46 )
{
struct V_34 * V_35 ;
for (; V_29 < V_46 ; V_29 += V_38 ) {
V_35 = F_75 ( V_29 ) ;
if ( F_9 ( ! F_85 ( V_35 ) ) )
continue;
if ( F_9 ( F_86 ( V_29 ) != V_58 ) )
continue;
if ( V_52 && V_52 != F_67 ( F_58 ( V_29 ) ) )
continue;
return V_29 ;
}
return 0 ;
}
static int F_87 ( int V_58 , struct V_52 * V_52 ,
unsigned long V_29 ,
unsigned long V_46 )
{
struct V_34 * V_35 ;
unsigned long V_45 ;
V_45 = V_46 - 1 ;
for (; V_45 >= V_29 ; V_45 -= V_38 ) {
V_35 = F_75 ( V_45 ) ;
if ( F_9 ( ! F_85 ( V_35 ) ) )
continue;
if ( F_9 ( F_86 ( V_45 ) != V_58 ) )
continue;
if ( V_52 && V_52 != F_67 ( F_58 ( V_45 ) ) )
continue;
return V_45 ;
}
return 0 ;
}
static void F_88 ( struct V_52 * V_52 , unsigned long V_29 ,
unsigned long V_46 )
{
unsigned long V_54 = V_52 -> V_54 ;
unsigned long V_82 = F_50 ( V_52 ) ;
unsigned long F_50 = V_82 ;
unsigned long V_45 ;
struct V_34 * V_35 ;
int V_58 = F_89 ( V_52 ) ;
F_49 ( V_52 ) ;
if ( V_54 == V_29 ) {
V_45 = F_84 ( V_58 , V_52 , V_46 ,
F_50 ) ;
if ( V_45 ) {
V_52 -> V_54 = V_45 ;
V_52 -> V_55 = F_50 - V_45 ;
}
} else if ( F_50 == V_46 ) {
V_45 = F_87 ( V_58 , V_52 , V_54 ,
V_29 ) ;
if ( V_45 )
V_52 -> V_55 = V_45 - V_54 + 1 ;
}
V_45 = V_54 ;
for (; V_45 < F_50 ; V_45 += V_38 ) {
V_35 = F_75 ( V_45 ) ;
if ( F_9 ( ! F_85 ( V_35 ) ) )
continue;
if ( F_67 ( F_58 ( V_45 ) ) != V_52 )
continue;
if ( V_29 == V_45 )
continue;
F_53 ( V_52 ) ;
return;
}
V_52 -> V_54 = 0 ;
V_52 -> V_55 = 0 ;
F_53 ( V_52 ) ;
}
static void F_90 ( struct V_43 * V_44 ,
unsigned long V_29 , unsigned long V_46 )
{
unsigned long V_83 = V_44 -> V_51 ;
unsigned long V_84 = F_46 ( V_44 ) ;
unsigned long F_46 = V_84 ;
unsigned long V_45 ;
struct V_34 * V_35 ;
int V_58 = V_44 -> V_49 ;
if ( V_83 == V_29 ) {
V_45 = F_84 ( V_58 , NULL , V_46 ,
F_46 ) ;
if ( V_45 ) {
V_44 -> V_51 = V_45 ;
V_44 -> V_69 = F_46 - V_45 ;
}
} else if ( F_46 == V_46 ) {
V_45 = F_87 ( V_58 , NULL , V_83 ,
V_29 ) ;
if ( V_45 )
V_44 -> V_69 = V_45 - V_83 + 1 ;
}
V_45 = V_83 ;
for (; V_45 < F_46 ; V_45 += V_38 ) {
V_35 = F_75 ( V_45 ) ;
if ( F_9 ( ! F_85 ( V_35 ) ) )
continue;
if ( F_86 ( V_45 ) != V_58 )
continue;
if ( V_29 == V_45 )
continue;
return;
}
V_44 -> V_51 = 0 ;
V_44 -> V_69 = 0 ;
}
static void F_91 ( struct V_52 * V_52 , unsigned long V_29 )
{
struct V_43 * V_44 = V_52 -> V_59 ;
int V_47 = V_38 ;
int V_56 ;
unsigned long V_17 ;
V_56 = V_52 - V_44 -> V_71 ;
F_63 ( V_52 -> V_59 , & V_17 ) ;
F_88 ( V_52 , V_29 , V_29 + V_47 ) ;
F_90 ( V_44 , V_29 , V_29 + V_47 ) ;
F_64 ( V_52 -> V_59 , & V_17 ) ;
}
static int F_92 ( struct V_52 * V_52 , struct V_34 * V_35 ,
unsigned long V_85 )
{
unsigned long V_29 ;
int V_86 ;
int V_63 = - V_79 ;
if ( ! F_85 ( V_35 ) )
return V_63 ;
V_63 = F_93 ( V_35 ) ;
if ( V_63 )
return V_63 ;
V_86 = F_94 ( V_35 ) ;
V_29 = F_81 ( V_86 ) ;
F_91 ( V_52 , V_29 ) ;
F_95 ( V_52 , V_35 , V_85 ) ;
return 0 ;
}
int F_96 ( struct V_52 * V_52 , unsigned long V_70 ,
unsigned long V_47 )
{
unsigned long V_33 ;
unsigned long V_85 = 0 ;
int V_87 , V_63 = 0 ;
if ( F_97 ( V_52 ) ) {
struct V_23 * V_23 = F_58 ( V_70 ) ;
struct V_76 * V_77 ;
V_77 = F_78 ( ( unsigned long ) V_23 ) ;
if ( V_77 )
V_85 = F_79 ( V_77 ) ;
} else {
T_5 V_10 , V_11 ;
V_10 = V_70 << V_39 ;
V_11 = V_47 * V_88 ;
V_63 = F_98 ( & V_20 , V_10 ,
V_11 ) ;
if ( V_63 ) {
T_5 V_89 = V_10 + V_11 - 1 ;
F_99 ( L_6 ,
& V_10 , & V_89 , V_63 ) ;
}
}
F_77 ( V_52 ) ;
F_31 ( V_70 & ~ V_90 ) ;
F_31 ( V_47 % V_38 ) ;
V_87 = V_47 / V_38 ;
for ( V_33 = 0 ; V_33 < V_87 ; V_33 ++ ) {
unsigned long V_45 = V_70 + V_33 * V_38 ;
V_63 = F_92 ( V_52 , F_75 ( V_45 ) , V_85 ) ;
V_85 = 0 ;
if ( V_63 )
break;
}
F_83 ( V_52 ) ;
return V_63 ;
}
int F_100 ( T_6 V_91 )
{
int V_92 = - V_79 ;
F_2 () ;
F_5 ( & V_93 ) ;
if ( V_94 == V_95 ) {
V_94 = V_91 ;
V_92 = 0 ;
}
F_6 ( & V_93 ) ;
F_7 () ;
return V_92 ;
}
int F_101 ( T_6 V_91 )
{
int V_92 = - V_79 ;
F_2 () ;
F_5 ( & V_93 ) ;
if ( V_94 == V_91 ) {
V_94 = V_95 ;
V_92 = 0 ;
}
F_6 ( & V_93 ) ;
F_7 () ;
return V_92 ;
}
void F_102 ( struct V_23 * V_23 )
{
}
void F_103 ( struct V_23 * V_23 )
{
F_104 ( V_23 , 1 ) ;
}
void F_105 ( struct V_23 * V_23 )
{
F_106 ( V_23 ) ;
}
static void V_95 ( struct V_23 * V_23 )
{
F_102 ( V_23 ) ;
F_103 ( V_23 ) ;
F_105 ( V_23 ) ;
}
static int F_107 ( unsigned long V_29 , unsigned long V_47 ,
void * V_96 )
{
unsigned long V_33 ;
unsigned long V_97 = * ( unsigned long * ) V_96 ;
struct V_23 * V_23 ;
if ( F_108 ( F_58 ( V_29 ) ) )
for ( V_33 = 0 ; V_33 < V_47 ; V_33 ++ ) {
V_23 = F_58 ( V_29 + V_33 ) ;
(* V_94)( V_23 ) ;
V_97 ++ ;
}
* ( unsigned long * ) V_96 = V_97 ;
return 0 ;
}
static bool F_109 ( struct V_52 * V_52 )
{
return true ;
}
static bool F_109 ( struct V_52 * V_52 )
{
return F_110 ( F_89 ( V_52 ) , V_98 ) ;
}
static void F_111 ( unsigned long V_47 ,
struct V_52 * V_52 , struct V_99 * V_96 )
{
int V_58 = F_89 ( V_52 ) ;
enum V_56 V_100 = V_101 ;
if ( V_102 == V_98 )
V_100 = V_103 ;
if ( F_56 ( V_52 ) <= V_100 && ! F_110 ( V_58 , V_98 ) )
V_96 -> V_104 = V_58 ;
else
V_96 -> V_104 = - 1 ;
#ifdef F_112
V_100 = V_105 ;
if ( V_102 == V_106 )
V_100 = V_103 ;
if ( F_56 ( V_52 ) <= V_100 && ! F_110 ( V_58 , V_106 ) )
V_96 -> V_107 = V_58 ;
else
V_96 -> V_107 = - 1 ;
#else
V_96 -> V_107 = V_96 -> V_104 ;
#endif
if ( ! F_110 ( V_58 , V_102 ) )
V_96 -> V_108 = V_58 ;
else
V_96 -> V_108 = - 1 ;
}
static void F_113 ( int V_48 , struct V_99 * V_96 )
{
if ( V_96 -> V_104 >= 0 )
F_114 ( V_48 , V_98 ) ;
if ( V_96 -> V_107 >= 0 )
F_114 ( V_48 , V_106 ) ;
F_114 ( V_48 , V_102 ) ;
}
bool F_115 ( unsigned long V_45 , unsigned long V_47 ,
enum V_56 V_109 , int * V_67 )
{
struct V_52 * V_52 = F_67 ( F_58 ( V_45 ) ) ;
enum V_56 V_110 = F_56 ( V_52 ) ;
int V_33 ;
* V_67 = 0 ;
if ( V_110 < V_109 ) {
if ( V_45 + V_47 != F_50 ( V_52 ) )
return false ;
for ( V_33 = V_110 + 1 ; V_33 < V_109 ; V_33 ++ )
if ( F_60 ( V_52 - V_110 + V_33 ) )
return false ;
}
if ( V_109 < V_110 ) {
if ( V_45 != V_52 -> V_54 )
return false ;
for ( V_33 = V_109 + 1 ; V_33 < V_110 ; V_33 ++ )
if ( F_60 ( V_52 - V_110 + V_33 ) )
return false ;
}
* V_67 = V_109 - V_110 ;
return true ;
}
int T_4 F_116 ( unsigned long V_45 , unsigned long V_47 , int V_111 )
{
unsigned long V_17 ;
unsigned long V_97 = 0 ;
struct V_52 * V_52 ;
int V_112 = 0 ;
int V_58 ;
int V_63 ;
struct V_99 V_96 ;
int V_67 = 0 ;
V_52 = F_67 ( F_58 ( V_45 ) ) ;
if ( ( F_56 ( V_52 ) > V_101 ||
V_111 == V_113 ) &&
! F_109 ( V_52 ) )
return - V_79 ;
if ( V_111 == V_114 ) {
if ( ! F_115 ( V_45 , V_47 , V_101 , & V_67 ) )
return - V_79 ;
} else if ( V_111 == V_113 ) {
if ( ! F_115 ( V_45 , V_47 , V_103 , & V_67 ) )
return - V_79 ;
}
V_52 = F_66 ( V_67 , V_45 , V_45 + V_47 ) ;
if ( ! V_52 )
return - V_79 ;
V_96 . V_29 = V_45 ;
V_96 . V_47 = V_47 ;
F_111 ( V_47 , V_52 , & V_96 ) ;
V_58 = F_89 ( V_52 ) ;
V_63 = V_99 ( V_115 , & V_96 ) ;
V_63 = F_117 ( V_63 ) ;
if ( V_63 )
goto V_116;
F_5 ( & V_117 ) ;
if ( ! F_118 ( V_52 ) ) {
V_112 = 1 ;
F_119 ( NULL , V_52 ) ;
}
V_63 = F_120 ( V_45 , V_47 , & V_97 ,
F_107 ) ;
if ( V_63 ) {
if ( V_112 )
F_121 ( V_52 ) ;
F_6 ( & V_117 ) ;
goto V_116;
}
V_52 -> V_118 += V_97 ;
F_63 ( V_52 -> V_59 , & V_17 ) ;
V_52 -> V_59 -> V_119 += V_97 ;
F_64 ( V_52 -> V_59 , & V_17 ) ;
if ( V_97 ) {
F_113 ( V_58 , & V_96 ) ;
if ( V_112 )
F_119 ( NULL , NULL ) ;
else
F_122 ( V_52 ) ;
}
F_6 ( & V_117 ) ;
F_123 () ;
if ( V_97 ) {
F_124 ( V_58 ) ;
F_125 ( V_58 ) ;
}
V_120 = F_126 () ;
F_127 () ;
if ( V_97 )
V_99 ( V_121 , & V_96 ) ;
return 0 ;
V_116:
F_22 ( L_7 ,
( unsigned long long ) V_45 << V_39 ,
( ( ( unsigned long long ) V_45 + V_47 ) << V_39 ) - 1 ) ;
V_99 ( V_122 , & V_96 ) ;
return V_63 ;
}
static void F_128 ( T_7 * V_44 )
{
struct V_52 * V_82 ;
for ( V_82 = V_44 -> V_71 ; V_82 < V_44 -> V_71 + V_123 ; V_82 ++ )
V_82 -> V_118 = 0 ;
V_44 -> V_119 = 0 ;
}
static T_7 T_4 * F_129 ( int V_58 , T_2 V_10 )
{
struct V_43 * V_44 ;
unsigned long V_124 [ V_123 ] = { 0 } ;
unsigned long V_125 [ V_123 ] = { 0 } ;
unsigned long V_29 = F_130 ( V_10 ) ;
V_44 = F_131 ( V_58 ) ;
if ( ! V_44 ) {
V_44 = F_132 ( V_58 ) ;
if ( ! V_44 )
return NULL ;
F_133 ( V_58 , V_44 ) ;
} else {
V_44 -> V_126 = 0 ;
V_44 -> V_127 = 0 ;
V_44 -> V_128 = 0 ;
}
F_134 ( V_58 , V_124 , V_29 , V_125 ) ;
V_44 -> V_129 = F_135 ( struct V_130 ) ;
F_5 ( & V_117 ) ;
F_119 ( V_44 , NULL ) ;
F_6 ( & V_117 ) ;
F_136 ( V_44 ) ;
F_128 ( V_44 ) ;
return V_44 ;
}
static void F_137 ( int V_58 , T_7 * V_44 )
{
F_133 ( V_58 , NULL ) ;
F_138 ( V_44 -> V_129 ) ;
F_139 ( V_44 ) ;
return;
}
int F_140 ( int V_58 )
{
T_7 * V_44 ;
int V_63 ;
if ( F_141 ( V_58 ) )
return 0 ;
F_12 () ;
V_44 = F_129 ( V_58 , 0 ) ;
if ( ! V_44 ) {
F_142 ( L_8 , V_58 ) ;
V_63 = - V_14 ;
goto V_80;
}
F_143 ( V_58 ) ;
V_63 = F_144 ( V_58 ) ;
F_31 ( V_63 ) ;
if ( V_44 -> V_131 -> V_132 -> V_52 == NULL ) {
F_5 ( & V_117 ) ;
F_119 ( NULL , NULL ) ;
F_6 ( & V_117 ) ;
}
V_80:
F_17 () ;
return V_63 ;
}
static int F_145 ( T_2 V_10 , T_2 V_11 )
{
T_2 V_29 = F_130 ( V_10 ) ;
T_2 V_47 = V_11 >> V_39 ;
if ( ( V_29 & ~ V_90 ) ||
( V_47 % V_38 ) || ( ! V_47 ) ) {
F_142 ( L_9 ,
( unsigned long long ) V_10 ,
( unsigned long long ) V_11 ) ;
return - V_79 ;
}
return 0 ;
}
static int F_146 ( int V_58 , T_2 V_10 , T_2 V_11 )
{
unsigned long V_29 = V_10 >> V_39 ;
T_7 * V_44 = F_131 ( V_58 ) ;
struct V_52 * V_133 = V_44 -> V_71 + V_103 ;
if ( F_51 ( V_133 ) )
return 0 ;
if ( V_133 -> V_54 <= V_29 )
return 1 ;
return 0 ;
}
int F_147 ( int V_58 , T_2 V_10 , T_2 V_11 , int V_134 ,
bool V_135 )
{
#ifdef F_148
if ( V_135 )
return V_136 ;
#endif
if ( F_146 ( V_58 , V_10 , V_11 ) )
return V_103 ;
return V_134 ;
}
static int F_149 ( struct V_137 * V_138 , void * V_96 )
{
return F_150 ( V_138 , V_121 , V_139 ) ;
}
int T_4 F_151 ( int V_58 , struct V_9 * V_12 , bool V_140 )
{
T_2 V_10 , V_11 ;
T_7 * V_44 = NULL ;
bool V_141 ;
bool V_142 ;
int V_63 ;
V_10 = V_12 -> V_10 ;
V_11 = F_152 ( V_12 ) ;
V_63 = F_145 ( V_10 , V_11 ) ;
if ( V_63 )
return V_63 ;
{
void * V_84 = F_131 ( V_58 ) ;
V_141 = ! V_84 ;
}
F_12 () ;
F_153 ( V_10 , V_11 , V_58 ) ;
V_142 = ! F_141 ( V_58 ) ;
if ( V_142 ) {
V_44 = F_129 ( V_58 , V_10 ) ;
V_63 = - V_14 ;
if ( ! V_44 )
goto error;
}
V_63 = F_154 ( V_58 , V_10 , V_11 , false ) ;
if ( V_63 < 0 )
goto error;
F_143 ( V_58 ) ;
if ( V_142 ) {
V_63 = F_144 ( V_58 ) ;
F_31 ( V_63 ) ;
}
F_155 ( V_10 , V_10 + V_11 , L_3 ) ;
if ( V_140 )
F_156 ( F_130 ( V_10 ) , F_157 ( V_10 + V_11 - 1 ) ,
NULL , F_149 ) ;
goto V_80;
error:
if ( V_141 )
F_137 ( V_58 , V_44 ) ;
F_158 ( V_10 , V_11 ) ;
V_80:
F_17 () ;
return V_63 ;
}
int T_4 F_159 ( int V_58 , T_2 V_10 , T_2 V_11 )
{
struct V_9 * V_12 ;
int V_63 ;
V_12 = F_18 ( V_10 , V_11 ) ;
if ( F_160 ( V_12 ) )
return F_161 ( V_12 ) ;
V_63 = F_151 ( V_58 , V_12 , V_2 ) ;
if ( V_63 < 0 )
F_24 ( V_12 ) ;
return V_63 ;
}
static inline int F_162 ( struct V_23 * V_23 )
{
return F_163 ( V_23 ) && F_164 ( V_23 ) >= V_143 ;
}
static struct V_23 * F_165 ( struct V_23 * V_23 )
{
F_31 ( F_166 ( V_23 ) & ( V_144 - 1 ) ) ;
if ( F_162 ( V_23 ) ) {
int V_145 ;
V_145 = F_164 ( V_23 ) ;
if ( ( V_145 < V_146 ) && ( V_145 >= V_143 ) )
return V_23 + ( 1 << V_145 ) ;
}
return V_23 + V_144 ;
}
bool F_167 ( unsigned long V_29 , unsigned long V_47 )
{
struct V_23 * V_23 = F_58 ( V_29 ) ;
struct V_23 * V_147 = V_23 + V_47 ;
for (; V_23 < V_147 ; V_23 = F_165 ( V_23 ) ) {
if ( ! F_168 ( V_23 ) )
return false ;
F_169 () ;
}
return true ;
}
int F_170 ( unsigned long V_29 , unsigned long V_46 ,
unsigned long * V_148 , unsigned long * V_149 )
{
unsigned long V_45 , V_150 ;
unsigned long V_10 , V_16 ;
struct V_52 * V_52 = NULL ;
struct V_23 * V_23 ;
int V_33 ;
for ( V_45 = V_29 , V_150 = F_171 ( V_29 + 1 ) ;
V_45 < V_46 ;
V_45 = V_150 , V_150 += V_38 ) {
if ( ! F_172 ( F_37 ( V_45 ) ) )
continue;
for (; V_45 < V_150 && V_45 < V_46 ;
V_45 += V_151 ) {
V_33 = 0 ;
while ( ( V_33 < V_151 ) &&
! F_173 ( V_45 + V_33 ) )
V_33 ++ ;
if ( V_33 == V_151 )
continue;
V_23 = F_58 ( V_45 + V_33 ) ;
if ( V_52 && F_67 ( V_23 ) != V_52 )
return 0 ;
if ( ! V_52 )
V_10 = V_45 + V_33 ;
V_52 = F_67 ( V_23 ) ;
V_16 = V_45 + V_151 ;
}
}
if ( V_52 ) {
* V_148 = V_10 ;
* V_149 = V_16 ;
return 1 ;
} else {
return 0 ;
}
}
static unsigned long F_174 ( unsigned long V_10 , unsigned long V_16 )
{
unsigned long V_45 ;
struct V_23 * V_23 ;
for ( V_45 = V_10 ; V_45 < V_16 ; V_45 ++ ) {
if ( F_43 ( V_45 ) ) {
V_23 = F_58 ( V_45 ) ;
if ( F_175 ( V_23 ) )
return V_45 ;
if ( F_176 ( V_23 ) ) {
if ( F_177 ( V_23 ) )
return V_45 ;
else
V_45 = F_178 ( V_45 + 1 ,
1 << F_179 ( V_23 ) ) - 1 ;
}
}
}
return 0 ;
}
static struct V_23 * F_180 ( struct V_23 * V_23 , unsigned long V_152 ,
int * * V_153 )
{
T_8 V_154 = V_155 | V_156 ;
int V_58 = F_181 ( V_23 ) ;
T_9 V_157 = V_158 [ V_102 ] ;
struct V_23 * V_159 = NULL ;
if ( F_176 ( V_23 ) )
return F_182 ( F_183 ( F_184 ( V_23 ) ) ,
F_185 ( V_58 , V_157 ) ) ;
F_186 ( V_58 , V_157 ) ;
if ( F_187 ( V_23 )
|| ( F_56 ( F_67 ( V_23 ) ) == V_103 ) )
V_154 |= V_160 ;
if ( ! F_188 ( V_157 ) )
V_159 = F_189 ( V_154 , 0 ,
F_190 ( V_58 , V_154 ) , & V_157 ) ;
if ( ! V_159 )
V_159 = F_191 ( V_154 , 0 ,
F_190 ( V_58 , V_154 ) ) ;
return V_159 ;
}
static int
F_192 ( unsigned long V_29 , unsigned long V_46 )
{
unsigned long V_45 ;
struct V_23 * V_23 ;
int V_161 = V_162 ;
int V_163 = 0 ;
int V_63 = 0 ;
F_193 ( V_164 ) ;
for ( V_45 = V_29 ; V_45 < V_46 && V_161 > 0 ; V_45 ++ ) {
if ( ! F_43 ( V_45 ) )
continue;
V_23 = F_58 ( V_45 ) ;
if ( F_176 ( V_23 ) ) {
struct V_23 * V_165 = F_184 ( V_23 ) ;
V_45 = F_166 ( V_165 ) + ( 1 << F_179 ( V_165 ) ) - 1 ;
if ( F_179 ( V_165 ) > V_166 ) {
V_63 = - V_167 ;
break;
}
if ( F_194 ( V_23 , & V_164 ) )
V_161 -= 1 << F_179 ( V_165 ) ;
continue;
}
if ( ! F_195 ( V_23 ) )
continue;
V_63 = F_196 ( V_23 ) ;
if ( ! V_63 ) {
F_197 ( V_23 ) ;
F_198 ( & V_23 -> V_24 , & V_164 ) ;
V_161 -- ;
F_199 ( V_23 , V_168 +
F_200 ( V_23 ) ) ;
} else {
#ifdef F_201
F_202 ( L_10 , V_45 ) ;
F_203 ( V_23 , L_11 ) ;
#endif
F_197 ( V_23 ) ;
if ( F_204 ( V_23 ) ) {
V_163 ++ ;
V_63 = - V_167 ;
break;
}
}
}
if ( ! F_205 ( & V_164 ) ) {
if ( V_163 ) {
F_206 ( & V_164 ) ;
goto V_80;
}
V_63 = F_207 ( & V_164 , F_180 , NULL , 0 ,
V_169 , V_170 ) ;
if ( V_63 )
F_206 ( & V_164 ) ;
}
V_80:
return V_63 ;
}
static int
F_208 ( unsigned long V_10 , unsigned long V_47 ,
void * V_171 )
{
F_209 ( V_10 , V_10 + V_47 ) ;
return 0 ;
}
static void
F_210 ( unsigned long V_29 , unsigned long V_46 )
{
F_120 ( V_29 , V_46 - V_29 , NULL ,
F_208 ) ;
}
static int
F_211 ( unsigned long V_29 , unsigned long V_47 ,
void * V_171 )
{
int V_63 ;
long V_172 = * ( long * ) V_171 ;
V_63 = F_212 ( V_29 , V_29 + V_47 , true ) ;
V_172 = V_47 ;
if ( ! V_63 )
* ( long * ) V_171 += V_172 ;
return V_63 ;
}
static long
F_213 ( unsigned long V_29 , unsigned long V_46 )
{
long V_172 = 0 ;
int V_63 ;
V_63 = F_120 ( V_29 , V_46 - V_29 , & V_172 ,
F_211 ) ;
if ( V_63 < 0 )
V_172 = ( long ) V_63 ;
return V_172 ;
}
static bool F_214 ( struct V_52 * V_52 , unsigned long V_47 )
{
return true ;
}
static bool F_214 ( struct V_52 * V_52 , unsigned long V_47 )
{
struct V_43 * V_44 = V_52 -> V_59 ;
unsigned long V_118 = 0 ;
enum V_56 V_173 ;
for ( V_173 = 0 ; V_173 <= V_101 ; V_173 ++ )
V_118 += V_44 -> V_71 [ V_173 ] . V_118 ;
if ( V_118 > V_47 )
return true ;
V_118 = 0 ;
for (; V_173 <= V_103 ; V_173 ++ )
V_118 += V_44 -> V_71 [ V_173 ] . V_118 ;
return V_118 == 0 ;
}
static int T_1 F_215 ( char * V_84 )
{
#ifdef F_216
V_174 = true ;
#else
F_99 ( L_12 ) ;
#endif
return 0 ;
}
static void F_217 ( unsigned long V_47 ,
struct V_52 * V_52 , struct V_99 * V_96 )
{
struct V_43 * V_44 = V_52 -> V_59 ;
unsigned long V_118 = 0 ;
enum V_56 V_173 , V_100 = V_101 ;
if ( V_102 == V_98 )
V_100 = V_103 ;
for ( V_173 = 0 ; V_173 <= V_100 ; V_173 ++ )
V_118 += V_44 -> V_71 [ V_173 ] . V_118 ;
if ( F_56 ( V_52 ) <= V_100 && V_47 >= V_118 )
V_96 -> V_104 = F_89 ( V_52 ) ;
else
V_96 -> V_104 = - 1 ;
#ifdef F_112
V_100 = V_105 ;
if ( V_102 == V_106 )
V_100 = V_103 ;
for (; V_173 <= V_100 ; V_173 ++ )
V_118 += V_44 -> V_71 [ V_173 ] . V_118 ;
if ( F_56 ( V_52 ) <= V_100 && V_47 >= V_118 )
V_96 -> V_107 = F_89 ( V_52 ) ;
else
V_96 -> V_107 = - 1 ;
#else
V_96 -> V_107 = V_96 -> V_104 ;
#endif
V_100 = V_103 ;
for (; V_173 <= V_100 ; V_173 ++ )
V_118 += V_44 -> V_71 [ V_173 ] . V_118 ;
if ( V_47 >= V_118 )
V_96 -> V_108 = F_89 ( V_52 ) ;
else
V_96 -> V_108 = - 1 ;
}
static void F_218 ( int V_48 , struct V_99 * V_96 )
{
if ( V_96 -> V_104 >= 0 )
F_219 ( V_48 , V_98 ) ;
if ( ( V_102 != V_98 ) &&
( V_96 -> V_107 >= 0 ) )
F_219 ( V_48 , V_106 ) ;
if ( ( V_102 != V_106 ) &&
( V_96 -> V_108 >= 0 ) )
F_219 ( V_48 , V_102 ) ;
}
static int T_4 F_220 ( unsigned long V_29 ,
unsigned long V_46 , unsigned long V_175 )
{
unsigned long V_45 , V_47 , V_176 ;
long V_177 ;
int V_63 , V_178 , V_179 , V_48 ;
unsigned long V_17 ;
unsigned long V_148 , V_149 ;
struct V_52 * V_52 ;
struct V_99 V_96 ;
if ( ! F_221 ( V_29 , V_144 ) )
return - V_79 ;
if ( ! F_221 ( V_46 , V_144 ) )
return - V_79 ;
if ( ! F_170 ( V_29 , V_46 , & V_148 , & V_149 ) )
return - V_79 ;
V_52 = F_67 ( F_58 ( V_148 ) ) ;
V_48 = F_89 ( V_52 ) ;
V_47 = V_46 - V_29 ;
if ( F_56 ( V_52 ) <= V_101 && ! F_214 ( V_52 , V_47 ) )
return - V_79 ;
V_63 = F_222 ( V_29 , V_46 ,
V_180 , true ) ;
if ( V_63 )
return V_63 ;
V_96 . V_29 = V_29 ;
V_96 . V_47 = V_47 ;
F_217 ( V_47 , V_52 , & V_96 ) ;
V_63 = V_99 ( V_181 , & V_96 ) ;
V_63 = F_117 ( V_63 ) ;
if ( V_63 )
goto V_182;
V_45 = V_29 ;
V_176 = V_183 + V_175 ;
V_178 = 0 ;
V_179 = 5 ;
V_184:
V_63 = - V_185 ;
if ( F_223 ( V_183 , V_176 ) )
goto V_182;
V_63 = - V_186 ;
if ( F_224 ( V_5 ) )
goto V_182;
V_63 = 0 ;
if ( V_178 ) {
F_225 () ;
F_169 () ;
F_226 ( V_52 ) ;
}
V_45 = F_174 ( V_29 , V_46 ) ;
if ( V_45 ) {
V_63 = F_192 ( V_45 , V_46 ) ;
if ( ! V_63 ) {
V_178 = 1 ;
goto V_184;
} else {
if ( V_63 < 0 )
if ( -- V_179 == 0 )
goto V_182;
F_227 () ;
V_178 = 1 ;
goto V_184;
}
}
F_225 () ;
F_227 () ;
F_226 ( V_52 ) ;
V_63 = F_228 ( V_29 , V_46 ) ;
if ( V_63 )
goto V_182;
V_177 = F_213 ( V_29 , V_46 ) ;
if ( V_177 < 0 ) {
V_63 = - V_167 ;
goto V_182;
}
F_229 ( L_13 , V_177 ) ;
F_210 ( V_29 , V_46 ) ;
F_230 ( V_29 , V_46 , V_180 ) ;
F_104 ( F_58 ( V_29 ) , - V_177 ) ;
V_52 -> V_118 -= V_177 ;
F_63 ( V_52 -> V_59 , & V_17 ) ;
V_52 -> V_59 -> V_119 -= V_177 ;
F_64 ( V_52 -> V_59 , & V_17 ) ;
F_123 () ;
if ( ! F_118 ( V_52 ) ) {
F_121 ( V_52 ) ;
F_5 ( & V_117 ) ;
F_119 ( NULL , NULL ) ;
F_6 ( & V_117 ) ;
} else
F_122 ( V_52 ) ;
F_218 ( V_48 , & V_96 ) ;
if ( V_96 . V_108 >= 0 ) {
F_231 ( V_48 ) ;
F_232 ( V_48 ) ;
}
V_120 = F_126 () ;
F_127 () ;
V_99 ( V_139 , & V_96 ) ;
return 0 ;
V_182:
F_22 ( L_14 ,
( unsigned long long ) V_29 << V_39 ,
( ( unsigned long long ) V_46 << V_39 ) - 1 ) ;
V_99 ( V_187 , & V_96 ) ;
F_230 ( V_29 , V_46 , V_180 ) ;
return V_63 ;
}
int F_233 ( unsigned long V_29 , unsigned long V_47 )
{
return F_220 ( V_29 , V_29 + V_47 , 120 * V_188 ) ;
}
int F_156 ( unsigned long V_29 , unsigned long V_46 ,
void * V_96 , int (* F_234)( struct V_137 * , void * ) )
{
struct V_137 * V_138 = NULL ;
struct V_34 * V_189 ;
unsigned long V_45 , V_32 ;
int V_63 ;
for ( V_45 = V_29 ; V_45 < V_46 ; V_45 += V_38 ) {
V_32 = F_37 ( V_45 ) ;
if ( ! F_172 ( V_32 ) )
continue;
V_189 = F_38 ( V_32 ) ;
if ( V_138 )
if ( ( V_32 >= V_138 -> V_190 ) &&
( V_32 <= V_138 -> V_191 ) )
continue;
V_138 = F_235 ( V_189 , V_138 ) ;
if ( ! V_138 )
continue;
V_63 = F_234 ( V_138 , V_96 ) ;
if ( V_63 ) {
F_236 ( & V_138 -> V_192 . V_193 ) ;
return V_63 ;
}
}
if ( V_138 )
F_236 ( & V_138 -> V_192 . V_193 ) ;
return 0 ;
}
static int F_237 ( struct V_137 * V_138 , void * V_96 )
{
int V_63 = ! F_238 ( V_138 ) ;
if ( F_9 ( V_63 ) ) {
T_10 V_194 , V_195 ;
V_194 = F_239 ( F_81 ( V_138 -> V_190 ) ) ;
V_195 = F_239 ( F_81 ( V_138 -> V_191 + 1 ) ) - 1 ;
F_99 ( L_15 ,
& V_194 , & V_195 ) ;
}
return V_63 ;
}
static int F_240 ( T_7 * V_44 )
{
int V_196 ;
F_241 (cpu) {
if ( F_242 ( V_196 ) == V_44 -> V_49 )
return - V_167 ;
}
return 0 ;
}
static void F_243 ( T_7 * V_44 )
{
#ifdef F_244
int V_196 ;
F_245 (cpu)
if ( F_242 ( V_196 ) == V_44 -> V_49 )
F_246 ( V_196 ) ;
#endif
}
static int F_247 ( T_7 * V_44 )
{
int V_63 ;
V_63 = F_240 ( V_44 ) ;
if ( V_63 )
return V_63 ;
F_243 ( V_44 ) ;
return 0 ;
}
void F_248 ( int V_58 )
{
T_7 * V_44 = F_131 ( V_58 ) ;
unsigned long V_29 = V_44 -> V_51 ;
unsigned long V_46 = V_29 + V_44 -> V_69 ;
unsigned long V_45 ;
for ( V_45 = V_29 ; V_45 < V_46 ; V_45 += V_38 ) {
unsigned long V_32 = F_37 ( V_45 ) ;
if ( ! F_172 ( V_32 ) )
continue;
if ( F_86 ( V_45 ) != V_58 )
continue;
return;
}
if ( F_247 ( V_44 ) )
return;
F_249 ( V_58 ) ;
F_250 ( V_58 ) ;
}
void T_4 F_251 ( int V_58 , T_2 V_10 , T_2 V_11 )
{
int V_63 ;
F_31 ( F_145 ( V_10 , V_11 ) ) ;
F_12 () ;
V_63 = F_156 ( F_130 ( V_10 ) , F_157 ( V_10 + V_11 - 1 ) , NULL ,
F_237 ) ;
if ( V_63 )
F_252 () ;
F_253 ( V_10 , V_10 + V_11 , L_3 ) ;
F_254 ( V_10 , V_11 ) ;
F_158 ( V_10 , V_11 ) ;
F_255 ( V_10 , V_11 ) ;
F_248 ( V_58 ) ;
F_17 () ;
}
