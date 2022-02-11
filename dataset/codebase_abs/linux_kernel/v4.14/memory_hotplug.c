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
struct V_4 * V_7 , * V_8 ;
V_7 = F_13 ( sizeof( struct V_4 ) , V_9 ) ;
if ( ! V_7 )
return F_14 ( - V_10 ) ;
V_7 -> V_11 = L_3 ;
V_7 -> V_5 = V_5 ;
V_7 -> V_12 = V_5 + V_6 - 1 ;
V_7 -> V_13 = V_14 | V_15 ;
V_8 = F_15 ( & V_16 , V_7 ) ;
if ( V_8 ) {
if ( V_8 -> V_17 == V_18 ) {
F_16 ( L_4
L_5 ,
( unsigned long long ) V_5 ) ;
}
F_16 ( L_6 , V_7 ) ;
F_17 ( V_7 ) ;
return F_14 ( - V_19 ) ;
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
void F_20 ( unsigned long V_20 , struct V_21 * V_21 ,
unsigned long type )
{
V_21 -> V_22 = ( void * ) type ;
F_21 ( V_21 ) ;
F_22 ( V_21 , V_20 ) ;
F_23 ( V_21 ) ;
}
void F_24 ( struct V_21 * V_21 )
{
unsigned long type ;
type = ( unsigned long ) V_21 -> V_22 ;
F_25 ( type < V_23 ||
type > V_24 ) ;
if ( F_26 ( V_21 ) == 1 ) {
V_21 -> V_22 = NULL ;
F_27 ( V_21 ) ;
F_22 ( V_21 , 0 ) ;
F_28 ( & V_21 -> V_25 ) ;
F_29 ( V_21 ) ;
}
}
static void F_30 ( unsigned long V_26 )
{
unsigned long * V_27 , V_28 , V_29 , V_30 ;
struct V_31 * V_32 ;
struct V_21 * V_21 , * V_33 ;
V_29 = F_31 ( V_26 ) ;
V_32 = F_32 ( V_29 ) ;
V_33 = F_33 ( V_32 -> V_34 , V_29 ) ;
V_21 = F_34 ( V_33 ) ;
V_28 = sizeof( struct V_21 ) * V_35 ;
V_28 = F_35 ( V_28 ) >> V_36 ;
for ( V_30 = 0 ; V_30 < V_28 ; V_30 ++ , V_21 ++ )
F_20 ( V_29 , V_21 , V_37 ) ;
V_27 = F_32 ( V_29 ) -> V_38 ;
V_21 = F_34 ( V_27 ) ;
V_28 = F_35 ( F_36 () ) >> V_36 ;
for ( V_30 = 0 ; V_30 < V_28 ; V_30 ++ , V_21 ++ )
F_20 ( V_29 , V_21 , V_39 ) ;
}
static void F_30 ( unsigned long V_26 )
{
unsigned long * V_27 , V_28 , V_29 , V_30 ;
struct V_31 * V_32 ;
struct V_21 * V_21 , * V_33 ;
if ( ! F_37 ( V_26 ) )
return;
V_29 = F_31 ( V_26 ) ;
V_32 = F_32 ( V_29 ) ;
V_33 = F_33 ( V_32 -> V_34 , V_29 ) ;
F_38 ( V_29 , V_33 , V_35 ) ;
V_27 = F_32 ( V_29 ) -> V_38 ;
V_21 = F_34 ( V_27 ) ;
V_28 = F_35 ( F_36 () ) >> V_36 ;
for ( V_30 = 0 ; V_30 < V_28 ; V_30 ++ , V_21 ++ )
F_20 ( V_29 , V_21 , V_39 ) ;
}
void T_1 F_39 ( struct V_40 * V_41 )
{
unsigned long V_30 , V_42 , V_43 , V_44 ;
int V_45 = V_41 -> V_46 ;
struct V_21 * V_21 ;
V_44 = F_35 ( sizeof( struct V_40 ) ) >> V_36 ;
V_21 = F_34 ( V_41 ) ;
for ( V_30 = 0 ; V_30 < V_44 ; V_30 ++ , V_21 ++ )
F_20 ( V_45 , V_21 , V_47 ) ;
V_42 = V_41 -> V_48 ;
V_43 = F_40 ( V_41 ) ;
for (; V_42 < V_43 ; V_42 += V_35 ) {
if ( F_37 ( V_42 ) && ( F_41 ( V_42 ) == V_45 ) )
F_30 ( V_42 ) ;
}
}
static int T_3 F_42 ( int V_49 , unsigned long V_50 ,
bool V_51 )
{
int V_52 ;
int V_30 ;
if ( F_37 ( V_50 ) )
return - V_19 ;
V_52 = F_43 ( F_44 ( V_49 ) , V_50 ) ;
if ( V_52 < 0 )
return V_52 ;
for ( V_30 = 0 ; V_30 < V_35 ; V_30 ++ ) {
unsigned long V_42 = V_50 + V_30 ;
struct V_21 * V_21 ;
if ( ! F_37 ( V_42 ) )
continue;
V_21 = F_45 ( V_42 ) ;
F_46 ( V_21 , V_49 ) ;
F_47 ( V_21 ) ;
}
if ( ! V_51 )
return 0 ;
return F_48 ( V_49 , F_49 ( V_50 ) ) ;
}
int T_4 F_50 ( int V_49 , unsigned long V_50 ,
unsigned long V_44 , bool V_51 )
{
unsigned long V_30 ;
int V_53 = 0 ;
int V_54 , V_55 ;
struct V_56 * V_57 ;
V_54 = F_31 ( V_50 ) ;
V_55 = F_31 ( V_50 + V_44 - 1 ) ;
V_57 = F_51 ( ( unsigned long ) F_45 ( V_50 ) ) ;
if ( V_57 ) {
if ( V_57 -> V_58 != V_50
|| F_52 ( V_57 ) > V_44 ) {
F_53 ( L_7 ) ;
V_53 = - V_59 ;
goto V_60;
}
V_57 -> V_61 = 0 ;
}
for ( V_30 = V_54 ; V_30 <= V_55 ; V_30 ++ ) {
V_53 = F_42 ( V_49 , F_54 ( V_30 ) , V_51 ) ;
if ( V_53 && ( V_53 != - V_19 ) )
break;
V_53 = 0 ;
F_55 () ;
}
F_56 () ;
V_60:
return V_53 ;
}
static unsigned long F_57 ( int V_49 , struct V_62 * V_62 ,
unsigned long V_26 ,
unsigned long V_43 )
{
struct V_31 * V_32 ;
for (; V_26 < V_43 ; V_26 += V_35 ) {
V_32 = F_49 ( V_26 ) ;
if ( F_58 ( ! F_59 ( V_32 ) ) )
continue;
if ( F_58 ( F_60 ( V_26 ) != V_49 ) )
continue;
if ( V_62 && V_62 != F_61 ( F_45 ( V_26 ) ) )
continue;
return V_26 ;
}
return 0 ;
}
static unsigned long F_62 ( int V_49 , struct V_62 * V_62 ,
unsigned long V_26 ,
unsigned long V_43 )
{
struct V_31 * V_32 ;
unsigned long V_42 ;
V_42 = V_43 - 1 ;
for (; V_42 >= V_26 ; V_42 -= V_35 ) {
V_32 = F_49 ( V_42 ) ;
if ( F_58 ( ! F_59 ( V_32 ) ) )
continue;
if ( F_58 ( F_60 ( V_42 ) != V_49 ) )
continue;
if ( V_62 && V_62 != F_61 ( F_45 ( V_42 ) ) )
continue;
return V_42 ;
}
return 0 ;
}
static void F_63 ( struct V_62 * V_62 , unsigned long V_26 ,
unsigned long V_43 )
{
unsigned long V_63 = V_62 -> V_63 ;
unsigned long V_64 = F_64 ( V_62 ) ;
unsigned long F_64 = V_64 ;
unsigned long V_42 ;
struct V_31 * V_32 ;
int V_49 = F_65 ( V_62 ) ;
F_66 ( V_62 ) ;
if ( V_63 == V_26 ) {
V_42 = F_57 ( V_49 , V_62 , V_43 ,
F_64 ) ;
if ( V_42 ) {
V_62 -> V_63 = V_42 ;
V_62 -> V_65 = F_64 - V_42 ;
}
} else if ( F_64 == V_43 ) {
V_42 = F_62 ( V_49 , V_62 , V_63 ,
V_26 ) ;
if ( V_42 )
V_62 -> V_65 = V_42 - V_63 + 1 ;
}
V_42 = V_63 ;
for (; V_42 < F_64 ; V_42 += V_35 ) {
V_32 = F_49 ( V_42 ) ;
if ( F_58 ( ! F_59 ( V_32 ) ) )
continue;
if ( F_61 ( F_45 ( V_42 ) ) != V_62 )
continue;
if ( V_26 == V_42 )
continue;
F_67 ( V_62 ) ;
return;
}
V_62 -> V_63 = 0 ;
V_62 -> V_65 = 0 ;
F_67 ( V_62 ) ;
}
static void F_68 ( struct V_40 * V_41 ,
unsigned long V_26 , unsigned long V_43 )
{
unsigned long V_66 = V_41 -> V_48 ;
unsigned long V_67 = F_40 ( V_41 ) ;
unsigned long F_40 = V_67 ;
unsigned long V_42 ;
struct V_31 * V_32 ;
int V_49 = V_41 -> V_46 ;
if ( V_66 == V_26 ) {
V_42 = F_57 ( V_49 , NULL , V_43 ,
F_40 ) ;
if ( V_42 ) {
V_41 -> V_48 = V_42 ;
V_41 -> V_68 = F_40 - V_42 ;
}
} else if ( F_40 == V_43 ) {
V_42 = F_62 ( V_49 , NULL , V_66 ,
V_26 ) ;
if ( V_42 )
V_41 -> V_68 = V_42 - V_66 + 1 ;
}
V_42 = V_66 ;
for (; V_42 < F_40 ; V_42 += V_35 ) {
V_32 = F_49 ( V_42 ) ;
if ( F_58 ( ! F_59 ( V_32 ) ) )
continue;
if ( F_60 ( V_42 ) != V_49 )
continue;
if ( V_26 == V_42 )
continue;
return;
}
V_41 -> V_48 = 0 ;
V_41 -> V_68 = 0 ;
}
static void F_69 ( struct V_62 * V_62 , unsigned long V_26 )
{
struct V_40 * V_41 = V_62 -> V_69 ;
int V_44 = V_35 ;
unsigned long V_13 ;
F_70 ( V_62 -> V_69 , & V_13 ) ;
F_63 ( V_62 , V_26 , V_26 + V_44 ) ;
F_68 ( V_41 , V_26 , V_26 + V_44 ) ;
F_71 ( V_62 -> V_69 , & V_13 ) ;
}
static int F_72 ( struct V_62 * V_62 , struct V_31 * V_32 ,
unsigned long V_70 )
{
unsigned long V_26 ;
int V_71 ;
int V_52 = - V_59 ;
if ( ! F_59 ( V_32 ) )
return V_52 ;
V_52 = F_73 ( V_32 ) ;
if ( V_52 )
return V_52 ;
V_71 = F_74 ( V_32 ) ;
V_26 = F_54 ( ( unsigned long ) V_71 ) ;
F_69 ( V_62 , V_26 ) ;
F_75 ( V_62 , V_32 , V_70 ) ;
return 0 ;
}
int F_76 ( struct V_62 * V_62 , unsigned long V_50 ,
unsigned long V_44 )
{
unsigned long V_30 ;
unsigned long V_70 = 0 ;
int V_72 , V_52 = 0 ;
if ( F_77 ( V_62 ) ) {
struct V_21 * V_21 = F_45 ( V_50 ) ;
struct V_56 * V_57 ;
V_57 = F_51 ( ( unsigned long ) V_21 ) ;
if ( V_57 )
V_70 = F_52 ( V_57 ) ;
} else {
T_5 V_5 , V_6 ;
V_5 = V_50 << V_36 ;
V_6 = V_44 * V_73 ;
V_52 = F_78 ( & V_16 , V_5 ,
V_6 ) ;
if ( V_52 ) {
T_5 V_74 = V_5 + V_6 - 1 ;
F_79 ( L_8 ,
& V_5 , & V_74 , V_52 ) ;
}
}
F_80 ( V_62 ) ;
F_25 ( V_50 & ~ V_75 ) ;
F_25 ( V_44 % V_35 ) ;
V_72 = V_44 / V_35 ;
for ( V_30 = 0 ; V_30 < V_72 ; V_30 ++ ) {
unsigned long V_42 = V_50 + V_30 * V_35 ;
V_52 = F_72 ( V_62 , F_49 ( V_42 ) , V_70 ) ;
V_70 = 0 ;
if ( V_52 )
break;
}
F_81 ( V_62 ) ;
return V_52 ;
}
int F_82 ( T_6 V_76 )
{
int V_77 = - V_59 ;
F_1 () ;
F_83 ( & V_78 ) ;
if ( V_79 == V_80 ) {
V_79 = V_76 ;
V_77 = 0 ;
}
F_84 ( & V_78 ) ;
F_3 () ;
return V_77 ;
}
int F_85 ( T_6 V_76 )
{
int V_77 = - V_59 ;
F_1 () ;
F_83 ( & V_78 ) ;
if ( V_79 == V_76 ) {
V_79 = V_80 ;
V_77 = 0 ;
}
F_84 ( & V_78 ) ;
F_3 () ;
return V_77 ;
}
void F_86 ( struct V_21 * V_21 )
{
}
void F_87 ( struct V_21 * V_21 )
{
F_88 ( V_21 , 1 ) ;
}
void F_89 ( struct V_21 * V_21 )
{
F_90 ( V_21 ) ;
}
static void V_80 ( struct V_21 * V_21 )
{
F_86 ( V_21 ) ;
F_87 ( V_21 ) ;
F_89 ( V_21 ) ;
}
static int F_91 ( unsigned long V_26 , unsigned long V_44 ,
void * V_81 )
{
unsigned long V_30 ;
unsigned long V_82 = * ( unsigned long * ) V_81 ;
struct V_21 * V_21 ;
if ( F_92 ( F_45 ( V_26 ) ) )
for ( V_30 = 0 ; V_30 < V_44 ; V_30 ++ ) {
V_21 = F_45 ( V_26 + V_30 ) ;
(* V_79)( V_21 ) ;
V_82 ++ ;
}
F_93 ( V_26 , V_26 + V_44 ) ;
* ( unsigned long * ) V_81 = V_82 ;
return 0 ;
}
static void F_94 ( unsigned long V_44 ,
struct V_62 * V_62 , struct V_83 * V_81 )
{
int V_49 = F_65 ( V_62 ) ;
enum V_84 V_85 = V_86 ;
if ( V_87 == V_88 )
V_85 = V_89 ;
if ( F_95 ( V_62 ) <= V_85 && ! F_96 ( V_49 , V_88 ) )
V_81 -> V_90 = V_49 ;
else
V_81 -> V_90 = - 1 ;
#ifdef F_97
V_85 = V_91 ;
if ( V_87 == V_92 )
V_85 = V_89 ;
if ( F_95 ( V_62 ) <= V_85 && ! F_96 ( V_49 , V_92 ) )
V_81 -> V_93 = V_49 ;
else
V_81 -> V_93 = - 1 ;
#else
V_81 -> V_93 = V_81 -> V_90 ;
#endif
if ( ! F_96 ( V_49 , V_87 ) )
V_81 -> V_94 = V_49 ;
else
V_81 -> V_94 = - 1 ;
}
static void F_98 ( int V_45 , struct V_83 * V_81 )
{
if ( V_81 -> V_90 >= 0 )
F_99 ( V_45 , V_88 ) ;
if ( V_81 -> V_93 >= 0 )
F_99 ( V_45 , V_92 ) ;
F_99 ( V_45 , V_87 ) ;
}
static void T_3 F_100 ( struct V_62 * V_62 , unsigned long V_26 ,
unsigned long V_44 )
{
unsigned long V_95 = F_64 ( V_62 ) ;
if ( F_101 ( V_62 ) || V_26 < V_62 -> V_63 )
V_62 -> V_63 = V_26 ;
V_62 -> V_65 = F_102 ( V_26 + V_44 , V_95 ) - V_62 -> V_63 ;
}
static void T_3 F_103 ( struct V_40 * V_41 , unsigned long V_26 ,
unsigned long V_44 )
{
unsigned long V_95 = F_40 ( V_41 ) ;
if ( ! V_41 -> V_68 || V_26 < V_41 -> V_48 )
V_41 -> V_48 = V_26 ;
V_41 -> V_68 = F_102 ( V_26 + V_44 , V_95 ) - V_41 -> V_48 ;
}
void T_4 F_104 ( struct V_62 * V_62 ,
unsigned long V_26 , unsigned long V_44 )
{
struct V_40 * V_41 = V_62 -> V_69 ;
int V_49 = V_41 -> V_46 ;
unsigned long V_13 ;
if ( F_101 ( V_62 ) )
F_105 ( V_62 , V_26 , V_44 ) ;
F_80 ( V_62 ) ;
F_70 ( V_41 , & V_13 ) ;
F_66 ( V_62 ) ;
F_100 ( V_62 , V_26 , V_44 ) ;
F_67 ( V_62 ) ;
F_103 ( V_41 , V_26 , V_44 ) ;
F_71 ( V_41 , & V_13 ) ;
F_106 ( V_44 , V_49 , F_95 ( V_62 ) , V_26 , V_96 ) ;
F_81 ( V_62 ) ;
}
static struct V_62 * F_107 ( int V_49 , unsigned long V_26 ,
unsigned long V_44 )
{
struct V_40 * V_41 = F_44 ( V_49 ) ;
int V_97 ;
for ( V_97 = 0 ; V_97 <= V_86 ; V_97 ++ ) {
struct V_62 * V_62 = & V_41 -> V_98 [ V_97 ] ;
if ( F_108 ( V_62 , V_26 , V_44 ) )
return V_62 ;
}
return & V_41 -> V_98 [ V_86 ] ;
}
static inline struct V_62 * F_109 ( int V_49 , unsigned long V_26 ,
unsigned long V_44 )
{
struct V_62 * V_99 = F_107 ( V_49 , V_26 ,
V_44 ) ;
struct V_62 * V_100 = & F_44 ( V_49 ) -> V_98 [ V_89 ] ;
bool V_101 = F_108 ( V_99 , V_26 , V_44 ) ;
bool V_102 = F_108 ( V_100 , V_26 , V_44 ) ;
if ( V_101 ^ V_102 )
return ( V_101 ) ? V_99 : V_100 ;
return V_103 ? V_100 : V_99 ;
}
struct V_62 * F_110 ( int V_104 , int V_49 , unsigned V_26 ,
unsigned long V_44 )
{
if ( V_104 == V_105 )
return F_107 ( V_49 , V_26 , V_44 ) ;
if ( V_104 == V_106 )
return & F_44 ( V_49 ) -> V_98 [ V_89 ] ;
return F_109 ( V_49 , V_26 , V_44 ) ;
}
static struct V_62 * T_3 F_111 ( int V_104 , int V_49 ,
unsigned long V_26 , unsigned long V_44 )
{
struct V_62 * V_62 ;
V_62 = F_110 ( V_104 , V_49 , V_26 , V_44 ) ;
F_104 ( V_62 , V_26 , V_44 ) ;
return V_62 ;
}
int T_4 F_112 ( unsigned long V_42 , unsigned long V_44 , int V_104 )
{
unsigned long V_13 ;
unsigned long V_82 = 0 ;
struct V_62 * V_62 ;
int V_107 = 0 ;
int V_49 ;
int V_52 ;
struct V_83 V_81 ;
V_49 = F_60 ( V_42 ) ;
V_62 = F_111 ( V_104 , V_49 , V_42 , V_44 ) ;
V_81 . V_26 = V_42 ;
V_81 . V_44 = V_44 ;
F_94 ( V_44 , V_62 , & V_81 ) ;
V_52 = V_83 ( V_108 , & V_81 ) ;
V_52 = F_113 ( V_52 ) ;
if ( V_52 )
goto V_109;
if ( ! F_114 ( V_62 ) ) {
V_107 = 1 ;
F_115 ( V_62 ) ;
}
V_52 = F_116 ( V_42 , V_44 , & V_82 ,
F_91 ) ;
if ( V_52 ) {
if ( V_107 )
F_117 ( V_62 ) ;
goto V_109;
}
V_62 -> V_110 += V_82 ;
F_70 ( V_62 -> V_69 , & V_13 ) ;
V_62 -> V_69 -> V_111 += V_82 ;
F_71 ( V_62 -> V_69 , & V_13 ) ;
if ( V_82 ) {
F_98 ( V_49 , & V_81 ) ;
if ( V_107 )
F_118 ( NULL ) ;
else
F_119 ( V_62 ) ;
}
F_120 () ;
if ( V_82 ) {
F_121 ( V_49 ) ;
F_122 ( V_49 ) ;
}
V_112 = F_123 () ;
F_124 () ;
if ( V_82 )
V_83 ( V_113 , & V_81 ) ;
return 0 ;
V_109:
F_16 ( L_9 ,
( unsigned long long ) V_42 << V_36 ,
( ( ( unsigned long long ) V_42 + V_44 ) << V_36 ) - 1 ) ;
V_83 ( V_114 , & V_81 ) ;
return V_52 ;
}
static void F_125 ( T_7 * V_41 )
{
struct V_62 * V_64 ;
for ( V_64 = V_41 -> V_98 ; V_64 < V_41 -> V_98 + V_115 ; V_64 ++ )
V_64 -> V_110 = 0 ;
V_41 -> V_111 = 0 ;
}
static T_7 T_4 * F_126 ( int V_49 , T_2 V_5 )
{
struct V_40 * V_41 ;
unsigned long V_116 [ V_115 ] = { 0 } ;
unsigned long V_117 [ V_115 ] = { 0 } ;
unsigned long V_26 = F_127 ( V_5 ) ;
V_41 = F_44 ( V_49 ) ;
if ( ! V_41 ) {
V_41 = F_128 ( V_49 ) ;
if ( ! V_41 )
return NULL ;
F_129 ( V_49 , V_41 ) ;
} else {
V_41 -> V_118 = 0 ;
V_41 -> V_119 = 0 ;
V_41 -> V_120 = 0 ;
}
F_130 ( V_49 , V_116 , V_26 , V_117 ) ;
V_41 -> V_121 = F_131 ( struct V_122 ) ;
F_118 ( V_41 ) ;
F_132 ( V_41 ) ;
F_125 ( V_41 ) ;
return V_41 ;
}
static void F_133 ( int V_49 , T_7 * V_41 )
{
F_129 ( V_49 , NULL ) ;
F_134 ( V_41 -> V_121 ) ;
F_135 ( V_41 ) ;
return;
}
int F_136 ( int V_49 )
{
T_7 * V_41 ;
int V_52 ;
if ( F_137 ( V_49 ) )
return 0 ;
F_6 () ;
V_41 = F_126 ( V_49 , 0 ) ;
if ( ! V_41 ) {
F_138 ( L_10 , V_49 ) ;
V_52 = - V_10 ;
goto V_60;
}
F_139 ( V_49 ) ;
V_52 = F_140 ( V_49 ) ;
F_25 ( V_52 ) ;
V_60:
F_9 () ;
return V_52 ;
}
static int F_141 ( T_2 V_5 , T_2 V_6 )
{
T_2 V_26 = F_127 ( V_5 ) ;
T_2 V_44 = V_6 >> V_36 ;
if ( ( V_26 & ~ V_75 ) ||
( V_44 % V_35 ) || ( ! V_44 ) ) {
F_138 ( L_11 ,
( unsigned long long ) V_5 ,
( unsigned long long ) V_6 ) ;
return - V_59 ;
}
return 0 ;
}
static int F_142 ( struct V_123 * V_124 , void * V_81 )
{
return F_143 ( & V_124 -> V_125 ) ;
}
int T_4 F_144 ( int V_49 , struct V_4 * V_7 , bool V_126 )
{
T_2 V_5 , V_6 ;
T_7 * V_41 = NULL ;
bool V_127 ;
bool V_128 ;
int V_52 ;
V_5 = V_7 -> V_5 ;
V_6 = F_145 ( V_7 ) ;
V_52 = F_141 ( V_5 , V_6 ) ;
if ( V_52 )
return V_52 ;
{
void * V_67 = F_44 ( V_49 ) ;
V_127 = ! V_67 ;
}
F_6 () ;
F_146 ( V_5 , V_6 , V_49 ) ;
V_128 = ! F_137 ( V_49 ) ;
if ( V_128 ) {
V_41 = F_126 ( V_49 , V_5 ) ;
V_52 = - V_10 ;
if ( ! V_41 )
goto error;
}
V_52 = F_147 ( V_49 , V_5 , V_6 , true ) ;
if ( V_52 < 0 )
goto error;
F_139 ( V_49 ) ;
if ( V_128 ) {
unsigned long V_26 = V_5 >> V_36 ;
unsigned long V_44 = V_6 >> V_36 ;
V_52 = F_148 ( V_49 ) ;
if ( V_52 )
goto V_129;
V_52 = F_149 ( V_49 , V_26 , V_44 ) ;
V_129:
F_25 ( V_52 ) ;
}
F_150 ( V_5 , V_5 + V_6 , L_3 ) ;
if ( V_126 )
F_151 ( F_127 ( V_5 ) , F_152 ( V_5 + V_6 - 1 ) ,
NULL , F_142 ) ;
goto V_60;
error:
if ( V_127 && V_41 )
F_133 ( V_49 , V_41 ) ;
F_153 ( V_5 , V_6 ) ;
V_60:
F_9 () ;
return V_52 ;
}
int T_4 F_154 ( int V_49 , T_2 V_5 , T_2 V_6 )
{
struct V_4 * V_7 ;
int V_52 ;
V_7 = F_12 ( V_5 , V_6 ) ;
if ( F_155 ( V_7 ) )
return F_156 ( V_7 ) ;
V_52 = F_144 ( V_49 , V_7 , V_3 ) ;
if ( V_52 < 0 )
F_18 ( V_7 ) ;
return V_52 ;
}
static inline int F_157 ( struct V_21 * V_21 )
{
return F_158 ( V_21 ) && F_159 ( V_21 ) >= V_130 ;
}
static struct V_21 * F_160 ( struct V_21 * V_21 )
{
F_25 ( F_161 ( V_21 ) & ( V_131 - 1 ) ) ;
if ( F_157 ( V_21 ) ) {
int V_132 ;
V_132 = F_159 ( V_21 ) ;
if ( ( V_132 < V_133 ) && ( V_132 >= V_130 ) )
return V_21 + ( 1 << V_132 ) ;
}
return V_21 + V_131 ;
}
bool F_162 ( unsigned long V_26 , unsigned long V_44 )
{
struct V_21 * V_21 = F_45 ( V_26 ) ;
struct V_21 * V_134 = V_21 + V_44 ;
for (; V_21 < V_134 ; V_21 = F_160 ( V_21 ) ) {
if ( ! F_163 ( V_21 ) )
return false ;
F_55 () ;
}
return true ;
}
int F_164 ( unsigned long V_26 , unsigned long V_43 ,
unsigned long * V_135 , unsigned long * V_136 )
{
unsigned long V_42 , V_137 ;
unsigned long V_5 , V_12 ;
struct V_62 * V_62 = NULL ;
struct V_21 * V_21 ;
int V_30 ;
for ( V_42 = V_26 , V_137 = F_165 ( V_26 + 1 ) ;
V_42 < V_43 ;
V_42 = V_137 , V_137 += V_35 ) {
if ( ! F_166 ( F_31 ( V_42 ) ) )
continue;
for (; V_42 < V_137 && V_42 < V_43 ;
V_42 += V_138 ) {
V_30 = 0 ;
while ( ( V_30 < V_138 ) &&
! F_167 ( V_42 + V_30 ) )
V_30 ++ ;
if ( V_30 == V_138 || V_42 + V_30 >= V_43 )
continue;
V_21 = F_45 ( V_42 + V_30 ) ;
if ( V_62 && F_61 ( V_21 ) != V_62 )
return 0 ;
if ( ! V_62 )
V_5 = V_42 + V_30 ;
V_62 = F_61 ( V_21 ) ;
V_12 = V_42 + V_138 ;
}
}
if ( V_62 ) {
* V_135 = V_5 ;
* V_136 = F_168 ( V_12 , V_43 ) ;
return 1 ;
} else {
return 0 ;
}
}
static unsigned long F_169 ( unsigned long V_5 , unsigned long V_12 )
{
unsigned long V_42 ;
struct V_21 * V_21 ;
for ( V_42 = V_5 ; V_42 < V_12 ; V_42 ++ ) {
if ( F_37 ( V_42 ) ) {
V_21 = F_45 ( V_42 ) ;
if ( F_170 ( V_21 ) )
return V_42 ;
if ( F_171 ( V_21 ) )
return V_42 ;
if ( F_172 ( V_21 ) ) {
if ( F_173 ( V_21 ) )
return V_42 ;
else
V_42 = F_174 ( V_42 + 1 ,
1 << F_175 ( V_21 ) ) - 1 ;
}
}
}
return 0 ;
}
static struct V_21 * F_176 ( struct V_21 * V_21 , unsigned long V_139 ,
int * * V_140 )
{
int V_49 = F_177 ( V_21 ) ;
T_8 V_141 = V_142 [ V_87 ] ;
F_178 ( V_49 , V_141 ) ;
if ( F_179 ( V_141 ) )
F_180 ( V_49 , V_141 ) ;
return F_181 ( V_21 , V_49 , & V_141 ) ;
}
static int
F_182 ( unsigned long V_26 , unsigned long V_43 )
{
unsigned long V_42 ;
struct V_21 * V_21 ;
int V_143 = V_144 ;
int V_145 = 0 ;
int V_52 = 0 ;
F_183 ( V_146 ) ;
for ( V_42 = V_26 ; V_42 < V_43 && V_143 > 0 ; V_42 ++ ) {
if ( ! F_37 ( V_42 ) )
continue;
V_21 = F_45 ( V_42 ) ;
if ( F_172 ( V_21 ) ) {
struct V_21 * V_147 = F_184 ( V_21 ) ;
V_42 = F_161 ( V_147 ) + ( 1 << F_175 ( V_147 ) ) - 1 ;
if ( F_175 ( V_147 ) > V_148 ) {
V_52 = - V_149 ;
break;
}
if ( F_185 ( V_21 , & V_146 ) )
V_143 -= 1 << F_175 ( V_147 ) ;
continue;
} else if ( F_186 () && F_187 ( V_21 ) )
V_42 = F_161 ( F_184 ( V_21 ) )
+ F_188 ( V_21 ) - 1 ;
if ( ! F_189 ( V_21 ) )
continue;
if ( F_170 ( V_21 ) )
V_52 = F_190 ( V_21 ) ;
else
V_52 = F_191 ( V_21 , V_150 ) ;
if ( ! V_52 ) {
F_192 ( V_21 ) ;
F_193 ( & V_21 -> V_25 , & V_146 ) ;
V_143 -- ;
if ( ! F_171 ( V_21 ) )
F_194 ( V_21 , V_151 +
F_195 ( V_21 ) ) ;
} else {
#ifdef F_196
F_197 ( L_12 , V_42 ) ;
F_198 ( V_21 , L_13 ) ;
#endif
F_192 ( V_21 ) ;
if ( F_199 ( V_21 ) ) {
V_145 ++ ;
V_52 = - V_149 ;
break;
}
}
}
if ( ! F_200 ( & V_146 ) ) {
if ( V_145 ) {
F_201 ( & V_146 ) ;
goto V_60;
}
V_52 = F_202 ( & V_146 , F_176 , NULL , 0 ,
V_152 , V_153 ) ;
if ( V_52 )
F_201 ( & V_146 ) ;
}
V_60:
return V_52 ;
}
static int
F_203 ( unsigned long V_5 , unsigned long V_44 ,
void * V_154 )
{
F_204 ( V_5 , V_5 + V_44 ) ;
return 0 ;
}
static void
F_205 ( unsigned long V_26 , unsigned long V_43 )
{
F_116 ( V_26 , V_43 - V_26 , NULL ,
F_203 ) ;
}
static int
F_206 ( unsigned long V_26 , unsigned long V_44 ,
void * V_154 )
{
int V_52 ;
long V_155 = * ( long * ) V_154 ;
V_52 = F_207 ( V_26 , V_26 + V_44 , true ) ;
V_155 = V_44 ;
if ( ! V_52 )
* ( long * ) V_154 += V_155 ;
return V_52 ;
}
static long
F_208 ( unsigned long V_26 , unsigned long V_43 )
{
long V_155 = 0 ;
int V_52 ;
V_52 = F_116 ( V_26 , V_43 - V_26 , & V_155 ,
F_206 ) ;
if ( V_52 < 0 )
V_155 = ( long ) V_52 ;
return V_155 ;
}
static int T_1 F_209 ( char * V_67 )
{
#ifdef F_210
V_103 = true ;
#else
F_79 ( L_14 ) ;
#endif
return 0 ;
}
static void F_211 ( unsigned long V_44 ,
struct V_62 * V_62 , struct V_83 * V_81 )
{
struct V_40 * V_41 = V_62 -> V_69 ;
unsigned long V_110 = 0 ;
enum V_84 V_156 , V_85 = V_86 ;
if ( V_87 == V_88 )
V_85 = V_89 ;
for ( V_156 = 0 ; V_156 <= V_85 ; V_156 ++ )
V_110 += V_41 -> V_98 [ V_156 ] . V_110 ;
if ( F_95 ( V_62 ) <= V_85 && V_44 >= V_110 )
V_81 -> V_90 = F_65 ( V_62 ) ;
else
V_81 -> V_90 = - 1 ;
#ifdef F_97
V_85 = V_91 ;
if ( V_87 == V_92 )
V_85 = V_89 ;
for (; V_156 <= V_85 ; V_156 ++ )
V_110 += V_41 -> V_98 [ V_156 ] . V_110 ;
if ( F_95 ( V_62 ) <= V_85 && V_44 >= V_110 )
V_81 -> V_93 = F_65 ( V_62 ) ;
else
V_81 -> V_93 = - 1 ;
#else
V_81 -> V_93 = V_81 -> V_90 ;
#endif
V_85 = V_89 ;
for (; V_156 <= V_85 ; V_156 ++ )
V_110 += V_41 -> V_98 [ V_156 ] . V_110 ;
if ( V_44 >= V_110 )
V_81 -> V_94 = F_65 ( V_62 ) ;
else
V_81 -> V_94 = - 1 ;
}
static void F_212 ( int V_45 , struct V_83 * V_81 )
{
if ( V_81 -> V_90 >= 0 )
F_213 ( V_45 , V_88 ) ;
if ( ( V_87 != V_88 ) &&
( V_81 -> V_93 >= 0 ) )
F_213 ( V_45 , V_92 ) ;
if ( ( V_87 != V_92 ) &&
( V_81 -> V_94 >= 0 ) )
F_213 ( V_45 , V_87 ) ;
}
static int T_4 F_214 ( unsigned long V_26 ,
unsigned long V_43 , unsigned long V_157 )
{
unsigned long V_42 , V_44 , V_158 ;
long V_159 ;
int V_52 , V_160 , V_161 , V_45 ;
unsigned long V_13 ;
unsigned long V_135 , V_136 ;
struct V_62 * V_62 ;
struct V_83 V_81 ;
if ( ! F_215 ( V_26 , V_131 ) )
return - V_59 ;
if ( ! F_215 ( V_43 , V_131 ) )
return - V_59 ;
if ( ! F_164 ( V_26 , V_43 , & V_135 , & V_136 ) )
return - V_59 ;
V_62 = F_61 ( F_45 ( V_135 ) ) ;
V_45 = F_65 ( V_62 ) ;
V_44 = V_43 - V_26 ;
V_52 = F_216 ( V_26 , V_43 ,
V_162 , true ) ;
if ( V_52 )
return V_52 ;
V_81 . V_26 = V_26 ;
V_81 . V_44 = V_44 ;
F_211 ( V_44 , V_62 , & V_81 ) ;
V_52 = V_83 ( V_163 , & V_81 ) ;
V_52 = F_113 ( V_52 ) ;
if ( V_52 )
goto V_164;
V_42 = V_26 ;
V_158 = V_165 + V_157 ;
V_160 = 0 ;
V_161 = 5 ;
V_166:
V_52 = - V_167 ;
if ( F_217 ( V_165 , V_158 ) )
goto V_164;
V_52 = - V_168 ;
if ( F_218 ( V_169 ) )
goto V_164;
V_52 = 0 ;
if ( V_160 ) {
F_219 () ;
F_55 () ;
F_220 ( V_62 ) ;
}
V_42 = F_169 ( V_26 , V_43 ) ;
if ( V_42 ) {
V_52 = F_182 ( V_42 , V_43 ) ;
if ( ! V_52 ) {
V_160 = 1 ;
goto V_166;
} else {
if ( V_52 < 0 )
if ( -- V_161 == 0 )
goto V_164;
F_221 () ;
V_160 = 1 ;
goto V_166;
}
}
F_219 () ;
F_221 () ;
F_220 ( V_62 ) ;
V_52 = F_222 ( V_26 , V_43 ) ;
if ( V_52 )
goto V_164;
V_159 = F_208 ( V_26 , V_43 ) ;
if ( V_159 < 0 ) {
V_52 = - V_149 ;
goto V_164;
}
F_223 ( L_15 , V_159 ) ;
F_205 ( V_26 , V_43 ) ;
F_224 ( V_26 , V_43 , V_162 ) ;
F_88 ( F_45 ( V_26 ) , - V_159 ) ;
V_62 -> V_110 -= V_159 ;
F_70 ( V_62 -> V_69 , & V_13 ) ;
V_62 -> V_69 -> V_111 -= V_159 ;
F_71 ( V_62 -> V_69 , & V_13 ) ;
F_120 () ;
if ( ! F_114 ( V_62 ) ) {
F_117 ( V_62 ) ;
F_118 ( NULL ) ;
} else
F_119 ( V_62 ) ;
F_212 ( V_45 , & V_81 ) ;
if ( V_81 . V_94 >= 0 ) {
F_225 ( V_45 ) ;
F_226 ( V_45 ) ;
}
V_112 = F_123 () ;
F_124 () ;
V_83 ( V_170 , & V_81 ) ;
return 0 ;
V_164:
F_16 ( L_16 ,
( unsigned long long ) V_26 << V_36 ,
( ( unsigned long long ) V_43 << V_36 ) - 1 ) ;
V_83 ( V_171 , & V_81 ) ;
F_224 ( V_26 , V_43 , V_162 ) ;
return V_52 ;
}
int F_227 ( unsigned long V_26 , unsigned long V_44 )
{
return F_214 ( V_26 , V_26 + V_44 , 120 * V_172 ) ;
}
int F_151 ( unsigned long V_26 , unsigned long V_43 ,
void * V_81 , int (* F_228)( struct V_123 * , void * ) )
{
struct V_123 * V_124 = NULL ;
struct V_31 * V_173 ;
unsigned long V_42 , V_29 ;
int V_52 ;
for ( V_42 = V_26 ; V_42 < V_43 ; V_42 += V_35 ) {
V_29 = F_31 ( V_42 ) ;
if ( ! F_166 ( V_29 ) )
continue;
V_173 = F_32 ( V_29 ) ;
if ( V_124 )
if ( ( V_29 >= V_124 -> V_174 ) &&
( V_29 <= V_124 -> V_175 ) )
continue;
V_124 = F_229 ( V_173 , V_124 ) ;
if ( ! V_124 )
continue;
V_52 = F_228 ( V_124 , V_81 ) ;
if ( V_52 ) {
F_230 ( & V_124 -> V_125 . V_176 ) ;
return V_52 ;
}
}
if ( V_124 )
F_230 ( & V_124 -> V_125 . V_176 ) ;
return 0 ;
}
static int F_231 ( struct V_123 * V_124 , void * V_81 )
{
int V_52 = ! F_232 ( V_124 ) ;
if ( F_58 ( V_52 ) ) {
T_9 V_177 , V_178 ;
V_177 = F_233 ( F_54 ( V_124 -> V_174 ) ) ;
V_178 = F_233 ( F_54 ( V_124 -> V_175 + 1 ) ) - 1 ;
F_79 ( L_17 ,
& V_177 , & V_178 ) ;
}
return V_52 ;
}
static int F_234 ( T_7 * V_41 )
{
int V_179 ;
F_235 (cpu) {
if ( F_236 ( V_179 ) == V_41 -> V_46 )
return - V_149 ;
}
return 0 ;
}
static void F_237 ( T_7 * V_41 )
{
#ifdef F_238
int V_179 ;
F_239 (cpu)
if ( F_236 ( V_179 ) == V_41 -> V_46 )
F_240 ( V_179 ) ;
#endif
}
static int F_241 ( T_7 * V_41 )
{
int V_52 ;
V_52 = F_234 ( V_41 ) ;
if ( V_52 )
return V_52 ;
F_237 ( V_41 ) ;
return 0 ;
}
void F_242 ( int V_49 )
{
T_7 * V_41 = F_44 ( V_49 ) ;
unsigned long V_26 = V_41 -> V_48 ;
unsigned long V_43 = V_26 + V_41 -> V_68 ;
unsigned long V_42 ;
for ( V_42 = V_26 ; V_42 < V_43 ; V_42 += V_35 ) {
unsigned long V_29 = F_31 ( V_42 ) ;
if ( ! F_166 ( V_29 ) )
continue;
if ( F_60 ( V_42 ) != V_49 )
continue;
return;
}
if ( F_241 ( V_41 ) )
return;
F_243 ( V_49 ) ;
F_244 ( V_49 ) ;
}
void T_4 F_245 ( int V_49 , T_2 V_5 , T_2 V_6 )
{
int V_52 ;
F_25 ( F_141 ( V_5 , V_6 ) ) ;
F_6 () ;
V_52 = F_151 ( F_127 ( V_5 ) , F_152 ( V_5 + V_6 - 1 ) , NULL ,
F_231 ) ;
if ( V_52 )
F_246 () ;
F_247 ( V_5 , V_5 + V_6 , L_3 ) ;
F_248 ( V_5 , V_6 ) ;
F_153 ( V_5 , V_6 ) ;
F_249 ( V_5 , V_6 ) ;
F_242 ( V_49 ) ;
F_9 () ;
}
