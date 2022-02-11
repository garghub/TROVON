void F_1 ( void )
{
F_2 ( & V_1 ) ;
}
void F_3 ( void )
{
F_4 ( & V_1 ) ;
}
static int T_1 F_5 ( char * V_2 )
{
if ( ! strcmp ( V_2 , L_1 ) )
V_3 = true ;
else if ( ! strcmp ( V_2 , L_2 ) )
V_3 = false ;
return 1 ;
}
void F_6 ( void )
{
F_7 () ;
F_8 ( & V_1 ) ;
}
void F_9 ( void )
{
F_10 ( & V_1 ) ;
F_11 () ;
}
static struct V_4 * F_12 ( T_2 V_5 , T_2 V_6 )
{
struct V_4 * V_7 ;
V_7 = F_13 ( sizeof( struct V_4 ) , V_8 ) ;
if ( ! V_7 )
return F_14 ( - V_9 ) ;
V_7 -> V_10 = L_3 ;
V_7 -> V_5 = V_5 ;
V_7 -> V_11 = V_5 + V_6 - 1 ;
V_7 -> V_12 = V_13 | V_14 ;
if ( F_15 ( & V_15 , V_7 ) < 0 ) {
F_16 ( L_4 , V_7 ) ;
F_17 ( V_7 ) ;
return F_14 ( - V_16 ) ;
}
return V_7 ;
}
static void F_18 ( struct V_4 * V_7 )
{
if ( ! V_7 )
return;
F_19 ( V_7 ) ;
F_17 ( V_7 ) ;
return;
}
void F_20 ( unsigned long V_17 , struct V_18 * V_18 ,
unsigned long type )
{
V_18 -> V_19 = ( void * ) type ;
F_21 ( V_18 ) ;
F_22 ( V_18 , V_17 ) ;
F_23 ( V_18 ) ;
}
void F_24 ( struct V_18 * V_18 )
{
unsigned long type ;
type = ( unsigned long ) V_18 -> V_19 ;
F_25 ( type < V_20 ||
type > V_21 ) ;
if ( F_26 ( V_18 ) == 1 ) {
V_18 -> V_19 = NULL ;
F_27 ( V_18 ) ;
F_22 ( V_18 , 0 ) ;
F_28 ( & V_18 -> V_22 ) ;
F_29 ( V_18 ) ;
}
}
static void F_30 ( unsigned long V_23 )
{
unsigned long * V_24 , V_25 , V_26 , V_27 ;
struct V_28 * V_29 ;
struct V_18 * V_18 , * V_30 ;
V_26 = F_31 ( V_23 ) ;
V_29 = F_32 ( V_26 ) ;
V_30 = F_33 ( V_29 -> V_31 , V_26 ) ;
V_18 = F_34 ( V_30 ) ;
V_25 = sizeof( struct V_18 ) * V_32 ;
V_25 = F_35 ( V_25 ) >> V_33 ;
for ( V_27 = 0 ; V_27 < V_25 ; V_27 ++ , V_18 ++ )
F_20 ( V_26 , V_18 , V_34 ) ;
V_24 = F_32 ( V_26 ) -> V_35 ;
V_18 = F_34 ( V_24 ) ;
V_25 = F_35 ( F_36 () ) >> V_33 ;
for ( V_27 = 0 ; V_27 < V_25 ; V_27 ++ , V_18 ++ )
F_20 ( V_26 , V_18 , V_36 ) ;
}
static void F_30 ( unsigned long V_23 )
{
unsigned long * V_24 , V_25 , V_26 , V_27 ;
struct V_28 * V_29 ;
struct V_18 * V_18 , * V_30 ;
if ( ! F_37 ( V_23 ) )
return;
V_26 = F_31 ( V_23 ) ;
V_29 = F_32 ( V_26 ) ;
V_30 = F_33 ( V_29 -> V_31 , V_26 ) ;
F_38 ( V_26 , V_30 , V_32 ) ;
V_24 = F_32 ( V_26 ) -> V_35 ;
V_18 = F_34 ( V_24 ) ;
V_25 = F_35 ( F_36 () ) >> V_33 ;
for ( V_27 = 0 ; V_27 < V_25 ; V_27 ++ , V_18 ++ )
F_20 ( V_26 , V_18 , V_36 ) ;
}
void T_1 F_39 ( struct V_37 * V_38 )
{
unsigned long V_27 , V_39 , V_40 , V_41 ;
int V_42 = V_38 -> V_43 ;
struct V_18 * V_18 ;
V_41 = F_35 ( sizeof( struct V_37 ) ) >> V_33 ;
V_18 = F_34 ( V_38 ) ;
for ( V_27 = 0 ; V_27 < V_41 ; V_27 ++ , V_18 ++ )
F_20 ( V_42 , V_18 , V_44 ) ;
V_39 = V_38 -> V_45 ;
V_40 = F_40 ( V_38 ) ;
for (; V_39 < V_40 ; V_39 += V_32 ) {
if ( F_37 ( V_39 ) && ( F_41 ( V_39 ) == V_42 ) )
F_30 ( V_39 ) ;
}
}
static int T_3 F_42 ( int V_46 , unsigned long V_47 ,
bool V_48 )
{
int V_49 ;
int V_27 ;
if ( F_37 ( V_47 ) )
return - V_16 ;
V_49 = F_43 ( F_44 ( V_46 ) , V_47 ) ;
if ( V_49 < 0 )
return V_49 ;
for ( V_27 = 0 ; V_27 < V_32 ; V_27 ++ ) {
unsigned long V_39 = V_47 + V_27 ;
struct V_18 * V_18 ;
if ( ! F_37 ( V_39 ) )
continue;
V_18 = F_45 ( V_39 ) ;
F_46 ( V_18 , V_46 ) ;
F_47 ( V_18 ) ;
}
if ( ! V_48 )
return 0 ;
return F_48 ( V_46 , F_49 ( V_47 ) ) ;
}
int T_4 F_50 ( int V_46 , unsigned long V_47 ,
unsigned long V_41 , bool V_48 )
{
unsigned long V_27 ;
int V_50 = 0 ;
int V_51 , V_52 ;
struct V_53 * V_54 ;
V_51 = F_31 ( V_47 ) ;
V_52 = F_31 ( V_47 + V_41 - 1 ) ;
V_54 = F_51 ( ( unsigned long ) F_45 ( V_47 ) ) ;
if ( V_54 ) {
if ( V_54 -> V_55 != V_47
|| F_52 ( V_54 ) > V_41 ) {
F_53 ( L_5 ) ;
V_50 = - V_56 ;
goto V_57;
}
V_54 -> V_58 = 0 ;
}
for ( V_27 = V_51 ; V_27 <= V_52 ; V_27 ++ ) {
V_50 = F_42 ( V_46 , F_54 ( V_27 ) , V_48 ) ;
if ( V_50 && ( V_50 != - V_16 ) )
break;
V_50 = 0 ;
}
F_55 () ;
V_57:
return V_50 ;
}
static int F_56 ( int V_46 , struct V_59 * V_59 ,
unsigned long V_23 ,
unsigned long V_40 )
{
struct V_28 * V_29 ;
for (; V_23 < V_40 ; V_23 += V_32 ) {
V_29 = F_49 ( V_23 ) ;
if ( F_57 ( ! F_58 ( V_29 ) ) )
continue;
if ( F_57 ( F_59 ( V_23 ) != V_46 ) )
continue;
if ( V_59 && V_59 != F_60 ( F_45 ( V_23 ) ) )
continue;
return V_23 ;
}
return 0 ;
}
static int F_61 ( int V_46 , struct V_59 * V_59 ,
unsigned long V_23 ,
unsigned long V_40 )
{
struct V_28 * V_29 ;
unsigned long V_39 ;
V_39 = V_40 - 1 ;
for (; V_39 >= V_23 ; V_39 -= V_32 ) {
V_29 = F_49 ( V_39 ) ;
if ( F_57 ( ! F_58 ( V_29 ) ) )
continue;
if ( F_57 ( F_59 ( V_39 ) != V_46 ) )
continue;
if ( V_59 && V_59 != F_60 ( F_45 ( V_39 ) ) )
continue;
return V_39 ;
}
return 0 ;
}
static void F_62 ( struct V_59 * V_59 , unsigned long V_23 ,
unsigned long V_40 )
{
unsigned long V_60 = V_59 -> V_60 ;
unsigned long V_61 = F_63 ( V_59 ) ;
unsigned long F_63 = V_61 ;
unsigned long V_39 ;
struct V_28 * V_29 ;
int V_46 = F_64 ( V_59 ) ;
F_65 ( V_59 ) ;
if ( V_60 == V_23 ) {
V_39 = F_56 ( V_46 , V_59 , V_40 ,
F_63 ) ;
if ( V_39 ) {
V_59 -> V_60 = V_39 ;
V_59 -> V_62 = F_63 - V_39 ;
}
} else if ( F_63 == V_40 ) {
V_39 = F_61 ( V_46 , V_59 , V_60 ,
V_23 ) ;
if ( V_39 )
V_59 -> V_62 = V_39 - V_60 + 1 ;
}
V_39 = V_60 ;
for (; V_39 < F_63 ; V_39 += V_32 ) {
V_29 = F_49 ( V_39 ) ;
if ( F_57 ( ! F_58 ( V_29 ) ) )
continue;
if ( F_60 ( F_45 ( V_39 ) ) != V_59 )
continue;
if ( V_23 == V_39 )
continue;
F_66 ( V_59 ) ;
return;
}
V_59 -> V_60 = 0 ;
V_59 -> V_62 = 0 ;
F_66 ( V_59 ) ;
}
static void F_67 ( struct V_37 * V_38 ,
unsigned long V_23 , unsigned long V_40 )
{
unsigned long V_63 = V_38 -> V_45 ;
unsigned long V_64 = F_40 ( V_38 ) ;
unsigned long F_40 = V_64 ;
unsigned long V_39 ;
struct V_28 * V_29 ;
int V_46 = V_38 -> V_43 ;
if ( V_63 == V_23 ) {
V_39 = F_56 ( V_46 , NULL , V_40 ,
F_40 ) ;
if ( V_39 ) {
V_38 -> V_45 = V_39 ;
V_38 -> V_65 = F_40 - V_39 ;
}
} else if ( F_40 == V_40 ) {
V_39 = F_61 ( V_46 , NULL , V_63 ,
V_23 ) ;
if ( V_39 )
V_38 -> V_65 = V_39 - V_63 + 1 ;
}
V_39 = V_63 ;
for (; V_39 < F_40 ; V_39 += V_32 ) {
V_29 = F_49 ( V_39 ) ;
if ( F_57 ( ! F_58 ( V_29 ) ) )
continue;
if ( F_59 ( V_39 ) != V_46 )
continue;
if ( V_23 == V_39 )
continue;
return;
}
V_38 -> V_45 = 0 ;
V_38 -> V_65 = 0 ;
}
static void F_68 ( struct V_59 * V_59 , unsigned long V_23 )
{
struct V_37 * V_38 = V_59 -> V_66 ;
int V_41 = V_32 ;
unsigned long V_12 ;
F_69 ( V_59 -> V_66 , & V_12 ) ;
F_62 ( V_59 , V_23 , V_23 + V_41 ) ;
F_67 ( V_38 , V_23 , V_23 + V_41 ) ;
F_70 ( V_59 -> V_66 , & V_12 ) ;
}
static int F_71 ( struct V_59 * V_59 , struct V_28 * V_29 ,
unsigned long V_67 )
{
unsigned long V_23 ;
int V_68 ;
int V_49 = - V_56 ;
if ( ! F_58 ( V_29 ) )
return V_49 ;
V_49 = F_72 ( V_29 ) ;
if ( V_49 )
return V_49 ;
V_68 = F_73 ( V_29 ) ;
V_23 = F_54 ( V_68 ) ;
F_68 ( V_59 , V_23 ) ;
F_74 ( V_59 , V_29 , V_67 ) ;
return 0 ;
}
int F_75 ( struct V_59 * V_59 , unsigned long V_47 ,
unsigned long V_41 )
{
unsigned long V_27 ;
unsigned long V_67 = 0 ;
int V_69 , V_49 = 0 ;
if ( F_76 ( V_59 ) ) {
struct V_18 * V_18 = F_45 ( V_47 ) ;
struct V_53 * V_54 ;
V_54 = F_51 ( ( unsigned long ) V_18 ) ;
if ( V_54 )
V_67 = F_52 ( V_54 ) ;
} else {
T_5 V_5 , V_6 ;
V_5 = V_47 << V_33 ;
V_6 = V_41 * V_70 ;
V_49 = F_77 ( & V_15 , V_5 ,
V_6 ) ;
if ( V_49 ) {
T_5 V_71 = V_5 + V_6 - 1 ;
F_78 ( L_6 ,
& V_5 , & V_71 , V_49 ) ;
}
}
F_79 ( V_59 ) ;
F_25 ( V_47 & ~ V_72 ) ;
F_25 ( V_41 % V_32 ) ;
V_69 = V_41 / V_32 ;
for ( V_27 = 0 ; V_27 < V_69 ; V_27 ++ ) {
unsigned long V_39 = V_47 + V_27 * V_32 ;
V_49 = F_71 ( V_59 , F_49 ( V_39 ) , V_67 ) ;
V_67 = 0 ;
if ( V_49 )
break;
}
F_80 ( V_59 ) ;
return V_49 ;
}
int F_81 ( T_6 V_73 )
{
int V_74 = - V_56 ;
F_1 () ;
F_82 ( & V_75 ) ;
if ( V_76 == V_77 ) {
V_76 = V_73 ;
V_74 = 0 ;
}
F_83 ( & V_75 ) ;
F_3 () ;
return V_74 ;
}
int F_84 ( T_6 V_73 )
{
int V_74 = - V_56 ;
F_1 () ;
F_82 ( & V_75 ) ;
if ( V_76 == V_73 ) {
V_76 = V_77 ;
V_74 = 0 ;
}
F_83 ( & V_75 ) ;
F_3 () ;
return V_74 ;
}
void F_85 ( struct V_18 * V_18 )
{
}
void F_86 ( struct V_18 * V_18 )
{
F_87 ( V_18 , 1 ) ;
}
void F_88 ( struct V_18 * V_18 )
{
F_89 ( V_18 ) ;
}
static void V_77 ( struct V_18 * V_18 )
{
F_85 ( V_18 ) ;
F_86 ( V_18 ) ;
F_88 ( V_18 ) ;
}
static int F_90 ( unsigned long V_23 , unsigned long V_41 ,
void * V_78 )
{
unsigned long V_27 ;
unsigned long V_79 = * ( unsigned long * ) V_78 ;
struct V_18 * V_18 ;
if ( F_91 ( F_45 ( V_23 ) ) )
for ( V_27 = 0 ; V_27 < V_41 ; V_27 ++ ) {
V_18 = F_45 ( V_23 + V_27 ) ;
(* V_76)( V_18 ) ;
V_79 ++ ;
}
F_92 ( V_23 , V_23 + V_41 ) ;
* ( unsigned long * ) V_78 = V_79 ;
return 0 ;
}
static void F_93 ( unsigned long V_41 ,
struct V_59 * V_59 , struct V_80 * V_78 )
{
int V_46 = F_64 ( V_59 ) ;
enum V_81 V_82 = V_83 ;
if ( V_84 == V_85 )
V_82 = V_86 ;
if ( F_94 ( V_59 ) <= V_82 && ! F_95 ( V_46 , V_85 ) )
V_78 -> V_87 = V_46 ;
else
V_78 -> V_87 = - 1 ;
#ifdef F_96
V_82 = V_88 ;
if ( V_84 == V_89 )
V_82 = V_86 ;
if ( F_94 ( V_59 ) <= V_82 && ! F_95 ( V_46 , V_89 ) )
V_78 -> V_90 = V_46 ;
else
V_78 -> V_90 = - 1 ;
#else
V_78 -> V_90 = V_78 -> V_87 ;
#endif
if ( ! F_95 ( V_46 , V_84 ) )
V_78 -> V_91 = V_46 ;
else
V_78 -> V_91 = - 1 ;
}
static void F_97 ( int V_42 , struct V_80 * V_78 )
{
if ( V_78 -> V_87 >= 0 )
F_98 ( V_42 , V_85 ) ;
if ( V_78 -> V_90 >= 0 )
F_98 ( V_42 , V_89 ) ;
F_98 ( V_42 , V_84 ) ;
}
bool F_99 ( int V_46 , unsigned long V_39 , unsigned long V_41 , int V_92 )
{
struct V_37 * V_38 = F_44 ( V_46 ) ;
struct V_59 * V_93 = & V_38 -> V_94 [ V_86 ] ;
struct V_59 * V_95 = F_100 ( V_46 , V_39 , V_41 ) ;
if ( V_92 == V_96 ) {
if ( F_101 ( V_93 ) )
return true ;
return V_93 -> V_60 >= V_39 + V_41 ;
} else if ( V_92 == V_97 ) {
return F_63 ( V_95 ) <= V_39 ;
}
return V_92 == V_98 ;
}
static void T_3 F_102 ( struct V_59 * V_59 , unsigned long V_23 ,
unsigned long V_41 )
{
unsigned long V_99 = F_63 ( V_59 ) ;
if ( F_101 ( V_59 ) || V_23 < V_59 -> V_60 )
V_59 -> V_60 = V_23 ;
V_59 -> V_62 = F_103 ( V_23 + V_41 , V_99 ) - V_59 -> V_60 ;
}
static void T_3 F_104 ( struct V_37 * V_38 , unsigned long V_23 ,
unsigned long V_41 )
{
unsigned long V_99 = F_40 ( V_38 ) ;
if ( ! V_38 -> V_65 || V_23 < V_38 -> V_45 )
V_38 -> V_45 = V_23 ;
V_38 -> V_65 = F_103 ( V_23 + V_41 , V_99 ) - V_38 -> V_45 ;
}
void T_4 F_105 ( struct V_59 * V_59 ,
unsigned long V_23 , unsigned long V_41 )
{
struct V_37 * V_38 = V_59 -> V_66 ;
int V_46 = V_38 -> V_43 ;
unsigned long V_12 ;
if ( F_101 ( V_59 ) )
F_106 ( V_59 , V_23 , V_41 ) ;
F_79 ( V_59 ) ;
F_69 ( V_38 , & V_12 ) ;
F_65 ( V_59 ) ;
F_102 ( V_59 , V_23 , V_41 ) ;
F_66 ( V_59 ) ;
F_104 ( V_38 , V_23 , V_41 ) ;
F_70 ( V_38 , & V_12 ) ;
F_107 ( V_41 , V_46 , F_94 ( V_59 ) , V_23 , V_100 ) ;
F_80 ( V_59 ) ;
}
struct V_59 * F_100 ( int V_46 , unsigned long V_23 ,
unsigned long V_41 )
{
struct V_37 * V_38 = F_44 ( V_46 ) ;
int V_101 ;
for ( V_101 = 0 ; V_101 <= V_83 ; V_101 ++ ) {
struct V_59 * V_59 = & V_38 -> V_94 [ V_101 ] ;
if ( F_108 ( V_59 , V_23 , V_41 ) )
return V_59 ;
}
return & V_38 -> V_94 [ V_83 ] ;
}
static inline bool F_109 ( int V_46 , struct V_59 * V_95 ,
unsigned long V_23 , unsigned long V_41 )
{
if ( ! F_99 ( V_46 , V_23 , V_41 ,
V_96 ) )
return true ;
if ( ! F_110 () )
return false ;
return ! F_108 ( V_95 , V_23 , V_41 ) ;
}
static struct V_59 * T_3 F_111 ( int V_92 , int V_46 ,
unsigned long V_23 , unsigned long V_41 )
{
struct V_37 * V_38 = F_44 ( V_46 ) ;
struct V_59 * V_59 = F_100 ( V_46 , V_23 , V_41 ) ;
if ( V_92 == V_98 ) {
struct V_59 * V_93 = & V_38 -> V_94 [ V_86 ] ;
if ( F_109 ( V_46 , V_59 , V_23 , V_41 ) )
V_59 = V_93 ;
} else if ( V_92 == V_97 ) {
V_59 = & V_38 -> V_94 [ V_86 ] ;
}
F_105 ( V_59 , V_23 , V_41 ) ;
return V_59 ;
}
int T_4 F_112 ( unsigned long V_39 , unsigned long V_41 , int V_92 )
{
unsigned long V_12 ;
unsigned long V_79 = 0 ;
struct V_59 * V_59 ;
int V_102 = 0 ;
int V_46 ;
int V_49 ;
struct V_80 V_78 ;
V_46 = F_59 ( V_39 ) ;
if ( ! F_99 ( V_46 , V_39 , V_41 , V_92 ) )
return - V_56 ;
V_59 = F_111 ( V_92 , V_46 , V_39 , V_41 ) ;
V_78 . V_23 = V_39 ;
V_78 . V_41 = V_41 ;
F_93 ( V_41 , V_59 , & V_78 ) ;
V_49 = V_80 ( V_103 , & V_78 ) ;
V_49 = F_113 ( V_49 ) ;
if ( V_49 )
goto V_104;
F_82 ( & V_105 ) ;
if ( ! F_114 ( V_59 ) ) {
V_102 = 1 ;
F_115 ( NULL , V_59 ) ;
}
V_49 = F_116 ( V_39 , V_41 , & V_79 ,
F_90 ) ;
if ( V_49 ) {
if ( V_102 )
F_117 ( V_59 ) ;
F_83 ( & V_105 ) ;
goto V_104;
}
V_59 -> V_106 += V_79 ;
F_69 ( V_59 -> V_66 , & V_12 ) ;
V_59 -> V_66 -> V_107 += V_79 ;
F_70 ( V_59 -> V_66 , & V_12 ) ;
if ( V_79 ) {
F_97 ( V_46 , & V_78 ) ;
if ( V_102 )
F_115 ( NULL , NULL ) ;
else
F_118 ( V_59 ) ;
}
F_83 ( & V_105 ) ;
F_119 () ;
if ( V_79 ) {
F_120 ( V_46 ) ;
F_121 ( V_46 ) ;
}
V_108 = F_122 () ;
F_123 () ;
if ( V_79 )
V_80 ( V_109 , & V_78 ) ;
return 0 ;
V_104:
F_16 ( L_7 ,
( unsigned long long ) V_39 << V_33 ,
( ( ( unsigned long long ) V_39 + V_41 ) << V_33 ) - 1 ) ;
V_80 ( V_110 , & V_78 ) ;
return V_49 ;
}
static void F_124 ( T_7 * V_38 )
{
struct V_59 * V_61 ;
for ( V_61 = V_38 -> V_94 ; V_61 < V_38 -> V_94 + V_111 ; V_61 ++ )
V_61 -> V_106 = 0 ;
V_38 -> V_107 = 0 ;
}
static T_7 T_4 * F_125 ( int V_46 , T_2 V_5 )
{
struct V_37 * V_38 ;
unsigned long V_112 [ V_111 ] = { 0 } ;
unsigned long V_113 [ V_111 ] = { 0 } ;
unsigned long V_23 = F_126 ( V_5 ) ;
V_38 = F_44 ( V_46 ) ;
if ( ! V_38 ) {
V_38 = F_127 ( V_46 ) ;
if ( ! V_38 )
return NULL ;
F_128 ( V_46 , V_38 ) ;
} else {
V_38 -> V_114 = 0 ;
V_38 -> V_115 = 0 ;
V_38 -> V_116 = 0 ;
}
F_129 ( V_46 , V_112 , V_23 , V_113 ) ;
V_38 -> V_117 = F_130 ( struct V_118 ) ;
F_82 ( & V_105 ) ;
F_115 ( V_38 , NULL ) ;
F_83 ( & V_105 ) ;
F_131 ( V_38 ) ;
F_124 ( V_38 ) ;
return V_38 ;
}
static void F_132 ( int V_46 , T_7 * V_38 )
{
F_128 ( V_46 , NULL ) ;
F_133 ( V_38 -> V_117 ) ;
F_134 ( V_38 ) ;
return;
}
int F_135 ( int V_46 )
{
T_7 * V_38 ;
int V_49 ;
if ( F_136 ( V_46 ) )
return 0 ;
F_6 () ;
V_38 = F_125 ( V_46 , 0 ) ;
if ( ! V_38 ) {
F_137 ( L_8 , V_46 ) ;
V_49 = - V_9 ;
goto V_57;
}
F_138 ( V_46 ) ;
V_49 = F_139 ( V_46 ) ;
F_25 ( V_49 ) ;
if ( V_38 -> V_119 -> V_120 -> V_59 == NULL ) {
F_82 ( & V_105 ) ;
F_115 ( NULL , NULL ) ;
F_83 ( & V_105 ) ;
}
V_57:
F_9 () ;
return V_49 ;
}
static int F_140 ( T_2 V_5 , T_2 V_6 )
{
T_2 V_23 = F_126 ( V_5 ) ;
T_2 V_41 = V_6 >> V_33 ;
if ( ( V_23 & ~ V_72 ) ||
( V_41 % V_32 ) || ( ! V_41 ) ) {
F_137 ( L_9 ,
( unsigned long long ) V_5 ,
( unsigned long long ) V_6 ) ;
return - V_56 ;
}
return 0 ;
}
static int F_141 ( struct V_121 * V_122 , void * V_78 )
{
return F_142 ( & V_122 -> V_123 ) ;
}
int T_4 F_143 ( int V_46 , struct V_4 * V_7 , bool V_124 )
{
T_2 V_5 , V_6 ;
T_7 * V_38 = NULL ;
bool V_125 ;
bool V_126 ;
int V_49 ;
V_5 = V_7 -> V_5 ;
V_6 = F_144 ( V_7 ) ;
V_49 = F_140 ( V_5 , V_6 ) ;
if ( V_49 )
return V_49 ;
{
void * V_64 = F_44 ( V_46 ) ;
V_125 = ! V_64 ;
}
F_6 () ;
F_145 ( V_5 , V_6 , V_46 ) ;
V_126 = ! F_136 ( V_46 ) ;
if ( V_126 ) {
V_38 = F_125 ( V_46 , V_5 ) ;
V_49 = - V_9 ;
if ( ! V_38 )
goto error;
}
V_49 = F_146 ( V_46 , V_5 , V_6 , true ) ;
if ( V_49 < 0 )
goto error;
F_138 ( V_46 ) ;
if ( V_126 ) {
unsigned long V_23 = V_5 >> V_33 ;
unsigned long V_41 = V_6 >> V_33 ;
V_49 = F_147 ( V_46 ) ;
if ( V_49 )
goto V_127;
V_49 = F_148 ( V_46 , V_23 , V_41 ) ;
V_127:
F_25 ( V_49 ) ;
}
F_149 ( V_5 , V_5 + V_6 , L_3 ) ;
if ( V_124 )
F_150 ( F_126 ( V_5 ) , F_151 ( V_5 + V_6 - 1 ) ,
NULL , F_141 ) ;
goto V_57;
error:
if ( V_125 && V_38 )
F_132 ( V_46 , V_38 ) ;
F_152 ( V_5 , V_6 ) ;
V_57:
F_9 () ;
return V_49 ;
}
int T_4 F_153 ( int V_46 , T_2 V_5 , T_2 V_6 )
{
struct V_4 * V_7 ;
int V_49 ;
V_7 = F_12 ( V_5 , V_6 ) ;
if ( F_154 ( V_7 ) )
return F_155 ( V_7 ) ;
V_49 = F_143 ( V_46 , V_7 , V_3 ) ;
if ( V_49 < 0 )
F_18 ( V_7 ) ;
return V_49 ;
}
static inline int F_156 ( struct V_18 * V_18 )
{
return F_157 ( V_18 ) && F_158 ( V_18 ) >= V_128 ;
}
static struct V_18 * F_159 ( struct V_18 * V_18 )
{
F_25 ( F_160 ( V_18 ) & ( V_129 - 1 ) ) ;
if ( F_156 ( V_18 ) ) {
int V_130 ;
V_130 = F_158 ( V_18 ) ;
if ( ( V_130 < V_131 ) && ( V_130 >= V_128 ) )
return V_18 + ( 1 << V_130 ) ;
}
return V_18 + V_129 ;
}
bool F_161 ( unsigned long V_23 , unsigned long V_41 )
{
struct V_18 * V_18 = F_45 ( V_23 ) ;
struct V_18 * V_132 = V_18 + V_41 ;
for (; V_18 < V_132 ; V_18 = F_159 ( V_18 ) ) {
if ( ! F_162 ( V_18 ) )
return false ;
F_163 () ;
}
return true ;
}
int F_164 ( unsigned long V_23 , unsigned long V_40 ,
unsigned long * V_133 , unsigned long * V_134 )
{
unsigned long V_39 , V_135 ;
unsigned long V_5 , V_11 ;
struct V_59 * V_59 = NULL ;
struct V_18 * V_18 ;
int V_27 ;
for ( V_39 = V_23 , V_135 = F_165 ( V_23 + 1 ) ;
V_39 < V_40 ;
V_39 = V_135 , V_135 += V_32 ) {
if ( ! F_166 ( F_31 ( V_39 ) ) )
continue;
for (; V_39 < V_135 && V_39 < V_40 ;
V_39 += V_136 ) {
V_27 = 0 ;
while ( ( V_27 < V_136 ) &&
! F_167 ( V_39 + V_27 ) )
V_27 ++ ;
if ( V_27 == V_136 || V_39 + V_27 >= V_40 )
continue;
V_18 = F_45 ( V_39 + V_27 ) ;
if ( V_59 && F_60 ( V_18 ) != V_59 )
return 0 ;
if ( ! V_59 )
V_5 = V_39 + V_27 ;
V_59 = F_60 ( V_18 ) ;
V_11 = V_39 + V_136 ;
}
}
if ( V_59 ) {
* V_133 = V_5 ;
* V_134 = F_168 ( V_11 , V_40 ) ;
return 1 ;
} else {
return 0 ;
}
}
static unsigned long F_169 ( unsigned long V_5 , unsigned long V_11 )
{
unsigned long V_39 ;
struct V_18 * V_18 ;
for ( V_39 = V_5 ; V_39 < V_11 ; V_39 ++ ) {
if ( F_37 ( V_39 ) ) {
V_18 = F_45 ( V_39 ) ;
if ( F_170 ( V_18 ) )
return V_39 ;
if ( F_171 ( V_18 ) )
return V_39 ;
if ( F_172 ( V_18 ) ) {
if ( F_173 ( V_18 ) )
return V_39 ;
else
V_39 = F_174 ( V_39 + 1 ,
1 << F_175 ( V_18 ) ) - 1 ;
}
}
}
return 0 ;
}
static struct V_18 * F_176 ( struct V_18 * V_18 , unsigned long V_137 ,
int * * V_138 )
{
int V_46 = F_177 ( V_18 ) ;
T_8 V_139 = V_140 [ V_84 ] ;
F_178 ( V_46 , V_139 ) ;
if ( F_179 ( V_139 ) )
F_180 ( V_46 , V_139 ) ;
return F_181 ( V_18 , V_46 , & V_139 ) ;
}
static int
F_182 ( unsigned long V_23 , unsigned long V_40 )
{
unsigned long V_39 ;
struct V_18 * V_18 ;
int V_141 = V_142 ;
int V_143 = 0 ;
int V_49 = 0 ;
F_183 ( V_144 ) ;
for ( V_39 = V_23 ; V_39 < V_40 && V_141 > 0 ; V_39 ++ ) {
if ( ! F_37 ( V_39 ) )
continue;
V_18 = F_45 ( V_39 ) ;
if ( F_172 ( V_18 ) ) {
struct V_18 * V_145 = F_184 ( V_18 ) ;
V_39 = F_160 ( V_145 ) + ( 1 << F_175 ( V_145 ) ) - 1 ;
if ( F_175 ( V_145 ) > V_146 ) {
V_49 = - V_147 ;
break;
}
if ( F_185 ( V_18 , & V_144 ) )
V_141 -= 1 << F_175 ( V_145 ) ;
continue;
}
if ( ! F_186 ( V_18 ) )
continue;
if ( F_170 ( V_18 ) )
V_49 = F_187 ( V_18 ) ;
else
V_49 = F_188 ( V_18 , V_148 ) ;
if ( ! V_49 ) {
F_189 ( V_18 ) ;
F_190 ( & V_18 -> V_22 , & V_144 ) ;
V_141 -- ;
if ( ! F_171 ( V_18 ) )
F_191 ( V_18 , V_149 +
F_192 ( V_18 ) ) ;
} else {
#ifdef F_193
F_194 ( L_10 , V_39 ) ;
F_195 ( V_18 , L_11 ) ;
#endif
F_189 ( V_18 ) ;
if ( F_196 ( V_18 ) ) {
V_143 ++ ;
V_49 = - V_147 ;
break;
}
}
}
if ( ! F_197 ( & V_144 ) ) {
if ( V_143 ) {
F_198 ( & V_144 ) ;
goto V_57;
}
V_49 = F_199 ( & V_144 , F_176 , NULL , 0 ,
V_150 , V_151 ) ;
if ( V_49 )
F_198 ( & V_144 ) ;
}
V_57:
return V_49 ;
}
static int
F_200 ( unsigned long V_5 , unsigned long V_41 ,
void * V_152 )
{
F_201 ( V_5 , V_5 + V_41 ) ;
return 0 ;
}
static void
F_202 ( unsigned long V_23 , unsigned long V_40 )
{
F_116 ( V_23 , V_40 - V_23 , NULL ,
F_200 ) ;
}
static int
F_203 ( unsigned long V_23 , unsigned long V_41 ,
void * V_152 )
{
int V_49 ;
long V_153 = * ( long * ) V_152 ;
V_49 = F_204 ( V_23 , V_23 + V_41 , true ) ;
V_153 = V_41 ;
if ( ! V_49 )
* ( long * ) V_152 += V_153 ;
return V_49 ;
}
static long
F_205 ( unsigned long V_23 , unsigned long V_40 )
{
long V_153 = 0 ;
int V_49 ;
V_49 = F_116 ( V_23 , V_40 - V_23 , & V_153 ,
F_203 ) ;
if ( V_49 < 0 )
V_153 = ( long ) V_49 ;
return V_153 ;
}
static int T_1 F_206 ( char * V_64 )
{
#ifdef F_207
V_154 = true ;
#else
F_78 ( L_12 ) ;
#endif
return 0 ;
}
static void F_208 ( unsigned long V_41 ,
struct V_59 * V_59 , struct V_80 * V_78 )
{
struct V_37 * V_38 = V_59 -> V_66 ;
unsigned long V_106 = 0 ;
enum V_81 V_155 , V_82 = V_83 ;
if ( V_84 == V_85 )
V_82 = V_86 ;
for ( V_155 = 0 ; V_155 <= V_82 ; V_155 ++ )
V_106 += V_38 -> V_94 [ V_155 ] . V_106 ;
if ( F_94 ( V_59 ) <= V_82 && V_41 >= V_106 )
V_78 -> V_87 = F_64 ( V_59 ) ;
else
V_78 -> V_87 = - 1 ;
#ifdef F_96
V_82 = V_88 ;
if ( V_84 == V_89 )
V_82 = V_86 ;
for (; V_155 <= V_82 ; V_155 ++ )
V_106 += V_38 -> V_94 [ V_155 ] . V_106 ;
if ( F_94 ( V_59 ) <= V_82 && V_41 >= V_106 )
V_78 -> V_90 = F_64 ( V_59 ) ;
else
V_78 -> V_90 = - 1 ;
#else
V_78 -> V_90 = V_78 -> V_87 ;
#endif
V_82 = V_86 ;
for (; V_155 <= V_82 ; V_155 ++ )
V_106 += V_38 -> V_94 [ V_155 ] . V_106 ;
if ( V_41 >= V_106 )
V_78 -> V_91 = F_64 ( V_59 ) ;
else
V_78 -> V_91 = - 1 ;
}
static void F_209 ( int V_42 , struct V_80 * V_78 )
{
if ( V_78 -> V_87 >= 0 )
F_210 ( V_42 , V_85 ) ;
if ( ( V_84 != V_85 ) &&
( V_78 -> V_90 >= 0 ) )
F_210 ( V_42 , V_89 ) ;
if ( ( V_84 != V_89 ) &&
( V_78 -> V_91 >= 0 ) )
F_210 ( V_42 , V_84 ) ;
}
static int T_4 F_211 ( unsigned long V_23 ,
unsigned long V_40 , unsigned long V_156 )
{
unsigned long V_39 , V_41 , V_157 ;
long V_158 ;
int V_49 , V_159 , V_160 , V_42 ;
unsigned long V_12 ;
unsigned long V_133 , V_134 ;
struct V_59 * V_59 ;
struct V_80 V_78 ;
if ( ! F_212 ( V_23 , V_129 ) )
return - V_56 ;
if ( ! F_212 ( V_40 , V_129 ) )
return - V_56 ;
if ( ! F_164 ( V_23 , V_40 , & V_133 , & V_134 ) )
return - V_56 ;
V_59 = F_60 ( F_45 ( V_133 ) ) ;
V_42 = F_64 ( V_59 ) ;
V_41 = V_40 - V_23 ;
V_49 = F_213 ( V_23 , V_40 ,
V_161 , true ) ;
if ( V_49 )
return V_49 ;
V_78 . V_23 = V_23 ;
V_78 . V_41 = V_41 ;
F_208 ( V_41 , V_59 , & V_78 ) ;
V_49 = V_80 ( V_162 , & V_78 ) ;
V_49 = F_113 ( V_49 ) ;
if ( V_49 )
goto V_163;
V_39 = V_23 ;
V_157 = V_164 + V_156 ;
V_159 = 0 ;
V_160 = 5 ;
V_165:
V_49 = - V_166 ;
if ( F_214 ( V_164 , V_157 ) )
goto V_163;
V_49 = - V_167 ;
if ( F_215 ( V_168 ) )
goto V_163;
V_49 = 0 ;
if ( V_159 ) {
F_216 () ;
F_163 () ;
F_217 ( V_59 ) ;
}
V_39 = F_169 ( V_23 , V_40 ) ;
if ( V_39 ) {
V_49 = F_182 ( V_39 , V_40 ) ;
if ( ! V_49 ) {
V_159 = 1 ;
goto V_165;
} else {
if ( V_49 < 0 )
if ( -- V_160 == 0 )
goto V_163;
F_218 () ;
V_159 = 1 ;
goto V_165;
}
}
F_216 () ;
F_218 () ;
F_217 ( V_59 ) ;
V_49 = F_219 ( V_23 , V_40 ) ;
if ( V_49 )
goto V_163;
V_158 = F_205 ( V_23 , V_40 ) ;
if ( V_158 < 0 ) {
V_49 = - V_147 ;
goto V_163;
}
F_220 ( L_13 , V_158 ) ;
F_202 ( V_23 , V_40 ) ;
F_221 ( V_23 , V_40 , V_161 ) ;
F_87 ( F_45 ( V_23 ) , - V_158 ) ;
V_59 -> V_106 -= V_158 ;
F_69 ( V_59 -> V_66 , & V_12 ) ;
V_59 -> V_66 -> V_107 -= V_158 ;
F_70 ( V_59 -> V_66 , & V_12 ) ;
F_119 () ;
if ( ! F_114 ( V_59 ) ) {
F_117 ( V_59 ) ;
F_82 ( & V_105 ) ;
F_115 ( NULL , NULL ) ;
F_83 ( & V_105 ) ;
} else
F_118 ( V_59 ) ;
F_209 ( V_42 , & V_78 ) ;
if ( V_78 . V_91 >= 0 ) {
F_222 ( V_42 ) ;
F_223 ( V_42 ) ;
}
V_108 = F_122 () ;
F_123 () ;
V_80 ( V_169 , & V_78 ) ;
return 0 ;
V_163:
F_16 ( L_14 ,
( unsigned long long ) V_23 << V_33 ,
( ( unsigned long long ) V_40 << V_33 ) - 1 ) ;
V_80 ( V_170 , & V_78 ) ;
F_221 ( V_23 , V_40 , V_161 ) ;
return V_49 ;
}
int F_224 ( unsigned long V_23 , unsigned long V_41 )
{
return F_211 ( V_23 , V_23 + V_41 , 120 * V_171 ) ;
}
int F_150 ( unsigned long V_23 , unsigned long V_40 ,
void * V_78 , int (* F_225)( struct V_121 * , void * ) )
{
struct V_121 * V_122 = NULL ;
struct V_28 * V_172 ;
unsigned long V_39 , V_26 ;
int V_49 ;
for ( V_39 = V_23 ; V_39 < V_40 ; V_39 += V_32 ) {
V_26 = F_31 ( V_39 ) ;
if ( ! F_166 ( V_26 ) )
continue;
V_172 = F_32 ( V_26 ) ;
if ( V_122 )
if ( ( V_26 >= V_122 -> V_173 ) &&
( V_26 <= V_122 -> V_174 ) )
continue;
V_122 = F_226 ( V_172 , V_122 ) ;
if ( ! V_122 )
continue;
V_49 = F_225 ( V_122 , V_78 ) ;
if ( V_49 ) {
F_227 ( & V_122 -> V_123 . V_175 ) ;
return V_49 ;
}
}
if ( V_122 )
F_227 ( & V_122 -> V_123 . V_175 ) ;
return 0 ;
}
static int F_228 ( struct V_121 * V_122 , void * V_78 )
{
int V_49 = ! F_229 ( V_122 ) ;
if ( F_57 ( V_49 ) ) {
T_9 V_176 , V_177 ;
V_176 = F_230 ( F_54 ( V_122 -> V_173 ) ) ;
V_177 = F_230 ( F_54 ( V_122 -> V_174 + 1 ) ) - 1 ;
F_78 ( L_15 ,
& V_176 , & V_177 ) ;
}
return V_49 ;
}
static int F_231 ( T_7 * V_38 )
{
int V_178 ;
F_232 (cpu) {
if ( F_233 ( V_178 ) == V_38 -> V_43 )
return - V_147 ;
}
return 0 ;
}
static void F_234 ( T_7 * V_38 )
{
#ifdef F_235
int V_178 ;
F_236 (cpu)
if ( F_233 ( V_178 ) == V_38 -> V_43 )
F_237 ( V_178 ) ;
#endif
}
static int F_238 ( T_7 * V_38 )
{
int V_49 ;
V_49 = F_231 ( V_38 ) ;
if ( V_49 )
return V_49 ;
F_234 ( V_38 ) ;
return 0 ;
}
void F_239 ( int V_46 )
{
T_7 * V_38 = F_44 ( V_46 ) ;
unsigned long V_23 = V_38 -> V_45 ;
unsigned long V_40 = V_23 + V_38 -> V_65 ;
unsigned long V_39 ;
for ( V_39 = V_23 ; V_39 < V_40 ; V_39 += V_32 ) {
unsigned long V_26 = F_31 ( V_39 ) ;
if ( ! F_166 ( V_26 ) )
continue;
if ( F_59 ( V_39 ) != V_46 )
continue;
return;
}
if ( F_238 ( V_38 ) )
return;
F_240 ( V_46 ) ;
F_241 ( V_46 ) ;
}
void T_4 F_242 ( int V_46 , T_2 V_5 , T_2 V_6 )
{
int V_49 ;
F_25 ( F_140 ( V_5 , V_6 ) ) ;
F_6 () ;
V_49 = F_150 ( F_126 ( V_5 ) , F_151 ( V_5 + V_6 - 1 ) , NULL ,
F_228 ) ;
if ( V_49 )
F_243 () ;
F_244 ( V_5 , V_5 + V_6 , L_3 ) ;
F_245 ( V_5 , V_6 ) ;
F_152 ( V_5 , V_6 ) ;
F_246 ( V_5 , V_6 ) ;
F_239 ( V_46 ) ;
F_9 () ;
}
