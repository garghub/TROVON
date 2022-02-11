void F_1 ( void )
{
F_2 ( & V_1 ) ;
F_3 () ;
}
void F_4 ( void )
{
F_5 () ;
F_6 ( & V_1 ) ;
}
static struct V_2 * F_7 ( T_1 V_3 , T_1 V_4 )
{
struct V_2 * V_5 ;
V_5 = F_8 ( sizeof( struct V_2 ) , V_6 ) ;
F_9 ( ! V_5 ) ;
V_5 -> V_7 = L_1 ;
V_5 -> V_3 = V_3 ;
V_5 -> V_8 = V_3 + V_4 - 1 ;
V_5 -> V_9 = V_10 | V_11 ;
if ( F_10 ( & V_12 , V_5 ) < 0 ) {
F_11 ( L_2 , V_5 ) ;
F_12 ( V_5 ) ;
V_5 = NULL ;
}
return V_5 ;
}
static void F_13 ( struct V_2 * V_5 )
{
if ( ! V_5 )
return;
F_14 ( V_5 ) ;
F_12 ( V_5 ) ;
return;
}
static void F_15 ( unsigned long V_13 , struct V_14 * V_14 ,
unsigned long type )
{
V_14 -> V_15 . V_16 = (struct V_17 * ) type ;
F_16 ( V_14 ) ;
F_17 ( V_14 , V_13 ) ;
F_18 ( & V_14 -> V_18 ) ;
}
void T_2 F_19 ( struct V_14 * V_14 )
{
unsigned long type ;
static F_20 ( V_19 ) ;
type = ( unsigned long ) V_14 -> V_15 . V_16 ;
F_9 ( type < V_20 ||
type > V_21 ) ;
if ( F_21 ( & V_14 -> V_18 ) == 1 ) {
F_22 ( V_14 ) ;
F_17 ( V_14 , 0 ) ;
F_23 ( & V_14 -> V_15 ) ;
F_2 ( & V_19 ) ;
F_24 ( V_14 , 0 ) ;
F_6 ( & V_19 ) ;
}
}
static void F_25 ( unsigned long V_22 )
{
unsigned long * V_23 , V_24 , V_25 , V_26 ;
struct V_27 * V_28 ;
struct V_14 * V_14 , * V_29 ;
V_25 = F_26 ( V_22 ) ;
V_28 = F_27 ( V_25 ) ;
V_29 = F_28 ( V_28 -> V_30 , V_25 ) ;
V_14 = F_29 ( V_29 ) ;
V_24 = sizeof( struct V_14 ) * V_31 ;
V_24 = F_30 ( V_24 ) >> V_32 ;
for ( V_26 = 0 ; V_26 < V_24 ; V_26 ++ , V_14 ++ )
F_15 ( V_25 , V_14 , V_33 ) ;
V_23 = F_27 ( V_25 ) -> V_34 ;
V_14 = F_29 ( V_23 ) ;
V_24 = F_30 ( F_31 () ) >> V_32 ;
for ( V_26 = 0 ; V_26 < V_24 ; V_26 ++ , V_14 ++ )
F_15 ( V_25 , V_14 , V_35 ) ;
}
void F_32 ( struct V_36 * V_37 )
{
unsigned long V_26 , V_38 , V_39 , V_40 ;
int V_41 = V_37 -> V_42 ;
struct V_14 * V_14 ;
struct V_43 * V_43 ;
V_40 = F_30 ( sizeof( struct V_36 ) ) >> V_32 ;
V_14 = F_29 ( V_37 ) ;
for ( V_26 = 0 ; V_26 < V_40 ; V_26 ++ , V_14 ++ )
F_15 ( V_41 , V_14 , V_44 ) ;
V_43 = & V_37 -> V_45 [ 0 ] ;
for (; V_43 < V_37 -> V_45 + V_46 - 1 ; V_43 ++ ) {
if ( V_43 -> V_47 ) {
V_40 = V_43 -> V_48
* sizeof( V_49 ) ;
V_40 = F_30 ( V_40 ) >> V_32 ;
V_14 = F_29 ( V_43 -> V_47 ) ;
for ( V_26 = 0 ; V_26 < V_40 ; V_26 ++ , V_14 ++ )
F_15 ( V_41 , V_14 , V_44 ) ;
}
}
V_38 = V_37 -> V_50 ;
V_39 = V_38 + V_37 -> V_51 ;
for (; V_38 < V_39 ; V_38 += V_31 ) {
if ( F_33 ( V_38 ) && ( F_34 ( V_38 ) == V_41 ) )
F_25 ( V_38 ) ;
}
}
static void F_35 ( struct V_43 * V_43 , unsigned long V_22 ,
unsigned long V_39 )
{
unsigned long V_52 ;
F_36 ( V_43 ) ;
V_52 = V_43 -> V_53 + V_43 -> V_54 ;
if ( ! V_43 -> V_54 || V_22 < V_43 -> V_53 )
V_43 -> V_53 = V_22 ;
V_43 -> V_54 = F_37 ( V_52 , V_39 ) -
V_43 -> V_53 ;
F_38 ( V_43 ) ;
}
static void F_39 ( struct V_43 * V_43 , unsigned long V_22 ,
unsigned long V_39 )
{
F_36 ( V_43 ) ;
if ( V_39 - V_22 ) {
V_43 -> V_53 = V_22 ;
V_43 -> V_54 = V_39 - V_22 ;
} else {
V_43 -> V_53 = 0 ;
V_43 -> V_54 = 0 ;
}
F_38 ( V_43 ) ;
}
static void F_40 ( struct V_43 * V_43 , unsigned long V_22 ,
unsigned long V_39 )
{
enum V_55 V_56 = F_41 ( V_43 ) ;
int V_57 = V_43 -> V_58 -> V_42 ;
unsigned long V_38 ;
for ( V_38 = V_22 ; V_38 < V_39 ; V_38 ++ )
F_42 ( F_43 ( V_38 ) , V_56 , V_57 , V_38 ) ;
}
static int T_3 F_44 ( struct V_43 * V_59 , struct V_43 * V_60 ,
unsigned long V_22 , unsigned long V_39 )
{
int V_61 ;
unsigned long V_9 ;
unsigned long V_62 ;
if ( ! V_59 -> V_47 ) {
V_61 = F_45 ( V_59 , V_22 ,
V_39 - V_22 , V_63 ) ;
if ( V_61 )
return V_61 ;
}
F_46 ( V_59 -> V_58 , & V_9 ) ;
if ( V_39 > V_60 -> V_53 + V_60 -> V_54 )
goto V_64;
if ( V_22 > V_60 -> V_53 )
goto V_64;
if ( V_39 <= V_60 -> V_53 )
goto V_64;
if ( V_59 -> V_54 )
V_62 = V_59 -> V_53 ;
else
V_62 = V_22 ;
F_39 ( V_59 , V_62 , V_39 ) ;
F_39 ( V_60 , V_39 , V_60 -> V_53 + V_60 -> V_54 ) ;
F_47 ( V_59 -> V_58 , & V_9 ) ;
F_40 ( V_59 , V_22 , V_39 ) ;
return 0 ;
V_64:
F_47 ( V_59 -> V_58 , & V_9 ) ;
return - 1 ;
}
static int T_3 F_48 ( struct V_43 * V_59 , struct V_43 * V_60 ,
unsigned long V_22 , unsigned long V_39 )
{
int V_61 ;
unsigned long V_9 ;
unsigned long V_65 ;
if ( ! V_60 -> V_47 ) {
V_61 = F_45 ( V_60 , V_22 ,
V_39 - V_22 , V_63 ) ;
if ( V_61 )
return V_61 ;
}
F_46 ( V_59 -> V_58 , & V_9 ) ;
if ( V_59 -> V_53 > V_22 )
goto V_64;
if ( V_59 -> V_53 + V_59 -> V_54 > V_39 )
goto V_64;
if ( V_22 >= V_59 -> V_53 + V_59 -> V_54 )
goto V_64;
if ( V_60 -> V_54 )
V_65 = V_60 -> V_53 + V_60 -> V_54 ;
else
V_65 = V_39 ;
F_39 ( V_59 , V_59 -> V_53 , V_22 ) ;
F_39 ( V_60 , V_22 , V_65 ) ;
F_47 ( V_59 -> V_58 , & V_9 ) ;
F_40 ( V_60 , V_22 , V_39 ) ;
return 0 ;
V_64:
F_47 ( V_59 -> V_58 , & V_9 ) ;
return - 1 ;
}
static void F_49 ( struct V_36 * V_37 , unsigned long V_22 ,
unsigned long V_39 )
{
unsigned long V_66 =
V_37 -> V_50 + V_37 -> V_51 ;
if ( ! V_37 -> V_51 || V_22 < V_37 -> V_50 )
V_37 -> V_50 = V_22 ;
V_37 -> V_51 = F_37 ( V_66 , V_39 ) -
V_37 -> V_50 ;
}
static int T_3 F_50 ( struct V_43 * V_43 , unsigned long V_67 )
{
struct V_36 * V_37 = V_43 -> V_58 ;
int V_40 = V_31 ;
int V_57 = V_37 -> V_42 ;
int V_55 ;
unsigned long V_9 ;
V_55 = V_43 - V_37 -> V_45 ;
if ( ! V_43 -> V_47 ) {
int V_61 ;
V_61 = F_45 ( V_43 , V_67 ,
V_40 , V_63 ) ;
if ( V_61 )
return V_61 ;
}
F_46 ( V_43 -> V_58 , & V_9 ) ;
F_35 ( V_43 , V_67 , V_67 + V_40 ) ;
F_49 ( V_43 -> V_58 , V_67 ,
V_67 + V_40 ) ;
F_47 ( V_43 -> V_58 , & V_9 ) ;
F_51 ( V_40 , V_57 , V_55 ,
V_67 , V_63 ) ;
return 0 ;
}
static int T_3 F_52 ( int V_57 , struct V_43 * V_43 ,
unsigned long V_67 )
{
int V_40 = V_31 ;
int V_61 ;
if ( F_33 ( V_67 ) )
return - V_68 ;
V_61 = F_53 ( V_43 , V_67 , V_40 ) ;
if ( V_61 < 0 )
return V_61 ;
V_61 = F_50 ( V_43 , V_67 ) ;
if ( V_61 < 0 )
return V_61 ;
return F_54 ( V_57 , F_55 ( V_67 ) ) ;
}
static int F_56 ( struct V_43 * V_43 , struct V_27 * V_28 )
{
return - V_69 ;
}
static int F_56 ( struct V_43 * V_43 , struct V_27 * V_28 )
{
unsigned long V_9 ;
struct V_36 * V_37 = V_43 -> V_58 ;
int V_61 = - V_70 ;
if ( ! F_57 ( V_28 ) )
return V_61 ;
V_61 = F_58 ( V_28 ) ;
if ( V_61 )
return V_61 ;
F_46 ( V_37 , & V_9 ) ;
F_59 ( V_43 , V_28 ) ;
F_47 ( V_37 , & V_9 ) ;
return 0 ;
}
int T_2 F_60 ( int V_57 , struct V_43 * V_43 , unsigned long V_67 ,
unsigned long V_40 )
{
unsigned long V_26 ;
int V_71 = 0 ;
int V_72 , V_73 ;
V_72 = F_26 ( V_67 ) ;
V_73 = F_26 ( V_67 + V_40 - 1 ) ;
for ( V_26 = V_72 ; V_26 <= V_73 ; V_26 ++ ) {
V_71 = F_52 ( V_57 , V_43 , V_26 << V_74 ) ;
if ( V_71 && ( V_71 != - V_68 ) )
break;
V_71 = 0 ;
}
return V_71 ;
}
int F_61 ( struct V_43 * V_43 , unsigned long V_67 ,
unsigned long V_40 )
{
unsigned long V_26 , V_61 = 0 ;
int V_75 ;
F_9 ( V_67 & ~ V_76 ) ;
F_9 ( V_40 % V_31 ) ;
F_62 ( V_67 << V_32 , V_40 * V_77 ) ;
V_75 = V_40 / V_31 ;
for ( V_26 = 0 ; V_26 < V_75 ; V_26 ++ ) {
unsigned long V_38 = V_67 + V_26 * V_31 ;
V_61 = F_56 ( V_43 , F_55 ( V_38 ) ) ;
if ( V_61 )
break;
}
return V_61 ;
}
int F_63 ( T_4 V_78 )
{
int V_79 = - V_70 ;
F_1 () ;
if ( V_80 == V_81 ) {
V_80 = V_78 ;
V_79 = 0 ;
}
F_4 () ;
return V_79 ;
}
int F_64 ( T_4 V_78 )
{
int V_79 = - V_70 ;
F_1 () ;
if ( V_80 == V_78 ) {
V_80 = V_81 ;
V_79 = 0 ;
}
F_4 () ;
return V_79 ;
}
void F_65 ( struct V_14 * V_14 )
{
unsigned long V_38 = F_66 ( V_14 ) ;
if ( V_38 >= V_82 )
V_82 = V_38 + 1 ;
}
void F_67 ( struct V_14 * V_14 )
{
V_83 ++ ;
#ifdef F_68
if ( F_69 ( V_14 ) )
V_84 ++ ;
#endif
}
void F_70 ( struct V_14 * V_14 )
{
F_71 ( V_14 ) ;
F_72 ( V_14 ) ;
F_73 ( V_14 ) ;
}
static void V_81 ( struct V_14 * V_14 )
{
F_65 ( V_14 ) ;
F_67 ( V_14 ) ;
F_70 ( V_14 ) ;
}
static int F_74 ( unsigned long V_22 , unsigned long V_40 ,
void * V_85 )
{
unsigned long V_26 ;
unsigned long V_86 = * ( unsigned long * ) V_85 ;
struct V_14 * V_14 ;
if ( F_75 ( F_43 ( V_22 ) ) )
for ( V_26 = 0 ; V_26 < V_40 ; V_26 ++ ) {
V_14 = F_43 ( V_22 + V_26 ) ;
(* V_80)( V_14 ) ;
V_86 ++ ;
}
* ( unsigned long * ) V_85 = V_86 ;
return 0 ;
}
static bool F_76 ( struct V_43 * V_43 )
{
return true ;
}
static bool F_76 ( struct V_43 * V_43 )
{
return F_77 ( F_78 ( V_43 ) , V_87 ) ;
}
static void F_79 ( unsigned long V_40 ,
struct V_43 * V_43 , struct V_88 * V_85 )
{
int V_57 = F_78 ( V_43 ) ;
enum V_55 V_89 = V_90 ;
if ( V_91 == V_87 )
V_89 = V_92 ;
if ( F_41 ( V_43 ) <= V_89 && ! F_77 ( V_57 , V_87 ) )
V_85 -> V_93 = V_57 ;
else
V_85 -> V_93 = - 1 ;
#ifdef F_68
V_89 = V_94 ;
if ( V_91 == V_95 )
V_89 = V_92 ;
if ( F_41 ( V_43 ) <= V_89 && ! F_77 ( V_57 , V_95 ) )
V_85 -> V_96 = V_57 ;
else
V_85 -> V_96 = - 1 ;
#else
V_85 -> V_96 = V_85 -> V_93 ;
#endif
if ( ! F_77 ( V_57 , V_91 ) )
V_85 -> V_97 = V_57 ;
else
V_85 -> V_97 = - 1 ;
}
static void F_80 ( int V_41 , struct V_88 * V_85 )
{
if ( V_85 -> V_93 >= 0 )
F_81 ( V_41 , V_87 ) ;
if ( V_85 -> V_96 >= 0 )
F_81 ( V_41 , V_95 ) ;
F_81 ( V_41 , V_91 ) ;
}
int T_2 F_82 ( unsigned long V_38 , unsigned long V_40 , int V_98 )
{
unsigned long V_86 = 0 ;
struct V_43 * V_43 ;
int V_99 = 0 ;
int V_57 ;
int V_61 ;
struct V_88 V_85 ;
F_1 () ;
V_43 = F_83 ( F_43 ( V_38 ) ) ;
if ( ( F_41 ( V_43 ) > V_90 || V_98 == V_100 ) &&
! F_76 ( V_43 ) ) {
F_4 () ;
return - 1 ;
}
if ( V_98 == V_101 && F_41 ( V_43 ) == V_92 ) {
if ( F_44 ( V_43 - 1 , V_43 , V_38 , V_38 + V_40 ) ) {
F_4 () ;
return - 1 ;
}
}
if ( V_98 == V_100 && F_41 ( V_43 ) == V_92 - 1 ) {
if ( F_48 ( V_43 , V_43 + 1 , V_38 , V_38 + V_40 ) ) {
F_4 () ;
return - 1 ;
}
}
V_43 = F_83 ( F_43 ( V_38 ) ) ;
V_85 . V_22 = V_38 ;
V_85 . V_40 = V_40 ;
F_79 ( V_40 , V_43 , & V_85 ) ;
V_57 = F_84 ( F_43 ( V_38 ) ) ;
V_61 = V_88 ( V_102 , & V_85 ) ;
V_61 = F_85 ( V_61 ) ;
if ( V_61 ) {
V_88 ( V_103 , & V_85 ) ;
F_4 () ;
return V_61 ;
}
F_2 ( & V_104 ) ;
if ( ! F_86 ( V_43 ) ) {
V_99 = 1 ;
F_87 ( NULL , V_43 ) ;
}
V_61 = F_88 ( V_38 , V_40 , & V_86 ,
F_74 ) ;
if ( V_61 ) {
if ( V_99 )
F_89 ( V_43 ) ;
F_6 ( & V_104 ) ;
F_11 ( V_105 L_3 ,
( unsigned long long ) V_38 << V_32 ,
( ( ( unsigned long long ) V_38 + V_40 )
<< V_32 ) - 1 ) ;
V_88 ( V_103 , & V_85 ) ;
F_4 () ;
return V_61 ;
}
V_43 -> V_106 += V_86 ;
V_43 -> V_107 += V_86 ;
V_43 -> V_58 -> V_108 += V_86 ;
if ( V_86 ) {
F_80 ( F_78 ( V_43 ) , & V_85 ) ;
if ( V_99 )
F_87 ( NULL , NULL ) ;
else
F_90 ( V_43 ) ;
}
F_6 ( & V_104 ) ;
F_91 () ;
if ( V_86 )
F_92 ( F_78 ( V_43 ) ) ;
V_109 = F_93 () ;
F_94 () ;
if ( V_86 )
V_88 ( V_110 , & V_85 ) ;
F_4 () ;
return 0 ;
}
static T_5 T_2 * F_95 ( int V_57 , T_1 V_3 )
{
struct V_36 * V_37 ;
unsigned long V_111 [ V_46 ] = { 0 } ;
unsigned long V_112 [ V_46 ] = { 0 } ;
unsigned long V_22 = V_3 >> V_32 ;
V_37 = F_96 ( V_57 ) ;
if ( ! V_37 )
return NULL ;
F_97 ( V_57 , V_37 ) ;
F_98 ( V_57 , V_111 , V_22 , V_112 ) ;
F_2 ( & V_104 ) ;
F_87 ( V_37 , NULL ) ;
F_6 ( & V_104 ) ;
return V_37 ;
}
static void F_99 ( int V_57 , T_5 * V_37 )
{
F_97 ( V_57 , NULL ) ;
F_100 ( V_37 ) ;
return;
}
int F_101 ( int V_57 )
{
T_5 * V_37 ;
int V_61 ;
F_1 () ;
V_37 = F_95 ( V_57 , 0 ) ;
if ( ! V_37 ) {
V_61 = - V_113 ;
goto V_114;
}
F_102 ( V_57 ) ;
V_61 = F_103 ( V_57 ) ;
F_9 ( V_61 ) ;
V_114:
F_4 () ;
return V_61 ;
}
int T_2 F_104 ( int V_57 , T_1 V_3 , T_1 V_4 )
{
T_5 * V_37 = NULL ;
int V_115 = 0 ;
struct V_2 * V_5 ;
int V_61 ;
F_1 () ;
V_5 = F_7 ( V_3 , V_4 ) ;
V_61 = - V_68 ;
if ( ! V_5 )
goto V_114;
if ( ! F_105 ( V_57 ) ) {
V_37 = F_95 ( V_57 , V_3 ) ;
V_61 = - V_113 ;
if ( ! V_37 )
goto error;
V_115 = 1 ;
}
V_61 = F_106 ( V_57 , V_3 , V_4 ) ;
if ( V_61 < 0 )
goto error;
F_102 ( V_57 ) ;
if ( V_115 ) {
V_61 = F_103 ( V_57 ) ;
F_9 ( V_61 ) ;
}
F_107 ( V_3 , V_3 + V_4 , L_1 ) ;
goto V_114;
error:
if ( V_115 )
F_99 ( V_57 , V_37 ) ;
if ( V_5 )
F_13 ( V_5 ) ;
V_114:
F_4 () ;
return V_61 ;
}
static inline int F_108 ( struct V_14 * V_14 )
{
return F_109 ( V_14 ) && F_110 ( V_14 ) >= V_116 ;
}
static struct V_14 * F_111 ( struct V_14 * V_14 )
{
F_9 ( F_66 ( V_14 ) & ( V_117 - 1 ) ) ;
if ( F_108 ( V_14 ) ) {
int V_118 ;
V_118 = F_110 ( V_14 ) ;
if ( ( V_118 < V_119 ) && ( V_118 >= V_116 ) )
return V_14 + ( 1 << V_118 ) ;
}
return V_14 + V_117 ;
}
int F_112 ( unsigned long V_22 , unsigned long V_40 )
{
struct V_14 * V_14 = F_43 ( V_22 ) ;
struct V_14 * V_120 = V_14 + V_40 ;
for (; V_14 < V_120 ; V_14 = F_111 ( V_14 ) ) {
if ( ! F_113 ( V_14 ) )
return 0 ;
F_114 () ;
}
return 1 ;
}
static int F_115 ( unsigned long V_22 , unsigned long V_39 )
{
unsigned long V_38 ;
struct V_43 * V_43 = NULL ;
struct V_14 * V_14 ;
int V_26 ;
for ( V_38 = V_22 ;
V_38 < V_39 ;
V_38 += V_121 ) {
V_26 = 0 ;
while ( ( V_26 < V_121 ) && ! F_116 ( V_38 + V_26 ) )
V_26 ++ ;
if ( V_26 == V_121 )
continue;
V_14 = F_43 ( V_38 + V_26 ) ;
if ( V_43 && F_83 ( V_14 ) != V_43 )
return 0 ;
V_43 = F_83 ( V_14 ) ;
}
return 1 ;
}
static unsigned long F_117 ( unsigned long V_3 , unsigned long V_8 )
{
unsigned long V_38 ;
struct V_14 * V_14 ;
for ( V_38 = V_3 ; V_38 < V_8 ; V_38 ++ ) {
if ( F_33 ( V_38 ) ) {
V_14 = F_43 ( V_38 ) ;
if ( F_118 ( V_14 ) )
return V_38 ;
}
}
return 0 ;
}
static int
F_119 ( unsigned long V_22 , unsigned long V_39 )
{
unsigned long V_38 ;
struct V_14 * V_14 ;
int V_122 = V_123 ;
int V_124 = 0 ;
int V_61 = 0 ;
F_120 ( V_125 ) ;
for ( V_38 = V_22 ; V_38 < V_39 && V_122 > 0 ; V_38 ++ ) {
if ( ! F_33 ( V_38 ) )
continue;
V_14 = F_43 ( V_38 ) ;
if ( ! F_121 ( V_14 ) )
continue;
V_61 = F_122 ( V_14 ) ;
if ( ! V_61 ) {
F_123 ( V_14 ) ;
F_124 ( & V_14 -> V_15 , & V_125 ) ;
V_122 -- ;
F_125 ( V_14 , V_126 +
F_126 ( V_14 ) ) ;
} else {
#ifdef F_127
F_11 ( V_127 L_4 ,
V_38 ) ;
F_128 ( V_14 ) ;
#endif
F_123 ( V_14 ) ;
if ( F_129 ( V_14 ) ) {
V_124 ++ ;
V_61 = - V_69 ;
break;
}
}
}
if ( ! F_130 ( & V_125 ) ) {
if ( V_124 ) {
F_131 ( & V_125 ) ;
goto V_114;
}
V_61 = F_132 ( & V_125 , V_128 , 0 ,
true , V_129 ,
V_130 ) ;
if ( V_61 )
F_131 ( & V_125 ) ;
}
V_114:
return V_61 ;
}
static int
F_133 ( unsigned long V_3 , unsigned long V_40 ,
void * V_131 )
{
F_134 ( V_3 , V_3 + V_40 ) ;
return 0 ;
}
static void
F_135 ( unsigned long V_22 , unsigned long V_39 )
{
F_88 ( V_22 , V_39 - V_22 , NULL ,
F_133 ) ;
}
static int
F_136 ( unsigned long V_22 , unsigned long V_40 ,
void * V_131 )
{
int V_61 ;
long V_132 = * ( long * ) V_131 ;
V_61 = F_137 ( V_22 , V_22 + V_40 , true ) ;
V_132 = V_40 ;
if ( ! V_61 )
* ( long * ) V_131 += V_132 ;
return V_61 ;
}
static long
F_138 ( unsigned long V_22 , unsigned long V_39 )
{
long V_132 = 0 ;
int V_61 ;
V_61 = F_88 ( V_22 , V_39 - V_22 , & V_132 ,
F_136 ) ;
if ( V_61 < 0 )
V_132 = ( long ) V_61 ;
return V_132 ;
}
static bool F_139 ( struct V_43 * V_43 , unsigned long V_40 )
{
return true ;
}
static bool F_139 ( struct V_43 * V_43 , unsigned long V_40 )
{
struct V_36 * V_37 = V_43 -> V_58 ;
unsigned long V_107 = 0 ;
enum V_55 V_133 ;
for ( V_133 = 0 ; V_133 <= V_90 ; V_133 ++ )
V_107 += V_37 -> V_45 [ V_133 ] . V_107 ;
if ( V_107 > V_40 )
return true ;
V_107 = 0 ;
for (; V_133 <= V_92 ; V_133 ++ )
V_107 += V_37 -> V_45 [ V_133 ] . V_107 ;
return V_107 == 0 ;
}
static void F_140 ( unsigned long V_40 ,
struct V_43 * V_43 , struct V_88 * V_85 )
{
struct V_36 * V_37 = V_43 -> V_58 ;
unsigned long V_107 = 0 ;
enum V_55 V_133 , V_89 = V_90 ;
if ( V_91 == V_87 )
V_89 = V_92 ;
for ( V_133 = 0 ; V_133 <= V_89 ; V_133 ++ )
V_107 += V_37 -> V_45 [ V_133 ] . V_107 ;
if ( F_41 ( V_43 ) <= V_89 && V_40 >= V_107 )
V_85 -> V_93 = F_78 ( V_43 ) ;
else
V_85 -> V_93 = - 1 ;
#ifdef F_68
V_89 = V_94 ;
if ( V_91 == V_95 )
V_89 = V_92 ;
for (; V_133 <= V_89 ; V_133 ++ )
V_107 += V_37 -> V_45 [ V_133 ] . V_107 ;
if ( F_41 ( V_43 ) <= V_89 && V_40 >= V_107 )
V_85 -> V_96 = F_78 ( V_43 ) ;
else
V_85 -> V_96 = - 1 ;
#else
V_85 -> V_96 = V_85 -> V_93 ;
#endif
V_89 = V_92 ;
for (; V_133 <= V_89 ; V_133 ++ )
V_107 += V_37 -> V_45 [ V_133 ] . V_107 ;
if ( V_40 >= V_107 )
V_85 -> V_97 = F_78 ( V_43 ) ;
else
V_85 -> V_97 = - 1 ;
}
static void F_141 ( int V_41 , struct V_88 * V_85 )
{
if ( V_85 -> V_93 >= 0 )
F_142 ( V_41 , V_87 ) ;
if ( ( V_91 != V_87 ) &&
( V_85 -> V_96 >= 0 ) )
F_142 ( V_41 , V_95 ) ;
if ( ( V_91 != V_95 ) &&
( V_85 -> V_97 >= 0 ) )
F_142 ( V_41 , V_91 ) ;
}
static int T_2 F_143 ( unsigned long V_22 ,
unsigned long V_39 , unsigned long V_134 )
{
unsigned long V_38 , V_40 , V_135 ;
long V_136 ;
int V_61 , V_137 , V_138 , V_41 ;
struct V_43 * V_43 ;
struct V_88 V_85 ;
F_9 ( V_22 >= V_39 ) ;
if ( ! F_144 ( V_22 , V_117 ) )
return - V_70 ;
if ( ! F_144 ( V_39 , V_117 ) )
return - V_70 ;
if ( ! F_115 ( V_22 , V_39 ) )
return - V_70 ;
F_1 () ;
V_43 = F_83 ( F_43 ( V_22 ) ) ;
V_41 = F_78 ( V_43 ) ;
V_40 = V_39 - V_22 ;
V_61 = - V_70 ;
if ( F_41 ( V_43 ) <= V_90 && ! F_139 ( V_43 , V_40 ) )
goto V_114;
V_61 = F_145 ( V_22 , V_39 ,
V_139 , true ) ;
if ( V_61 )
goto V_114;
V_85 . V_22 = V_22 ;
V_85 . V_40 = V_40 ;
F_140 ( V_40 , V_43 , & V_85 ) ;
V_61 = V_88 ( V_140 , & V_85 ) ;
V_61 = F_85 ( V_61 ) ;
if ( V_61 )
goto V_141;
V_38 = V_22 ;
V_135 = V_142 + V_134 ;
V_137 = 0 ;
V_138 = 5 ;
V_143:
V_61 = - V_144 ;
if ( F_146 ( V_142 , V_135 ) )
goto V_141;
V_61 = - V_145 ;
if ( F_147 ( V_146 ) )
goto V_141;
V_61 = 0 ;
if ( V_137 ) {
F_148 () ;
F_114 () ;
F_149 () ;
}
V_38 = F_117 ( V_22 , V_39 ) ;
if ( V_38 ) {
V_61 = F_119 ( V_38 , V_39 ) ;
if ( ! V_61 ) {
V_137 = 1 ;
goto V_143;
} else {
if ( V_61 < 0 )
if ( -- V_138 == 0 )
goto V_141;
F_150 () ;
V_137 = 1 ;
goto V_143;
}
}
F_148 () ;
F_150 () ;
F_149 () ;
V_136 = F_138 ( V_22 , V_39 ) ;
if ( V_136 < 0 ) {
V_61 = - V_69 ;
goto V_141;
}
F_11 ( V_147 L_5 , V_136 ) ;
F_135 ( V_22 , V_39 ) ;
F_151 ( V_22 , V_39 , V_139 ) ;
V_43 -> V_106 -= V_136 ;
V_43 -> V_107 -= V_136 ;
V_43 -> V_58 -> V_108 -= V_136 ;
V_83 -= V_136 ;
F_91 () ;
if ( ! F_86 ( V_43 ) ) {
F_89 ( V_43 ) ;
F_2 ( & V_104 ) ;
F_87 ( NULL , NULL ) ;
F_6 ( & V_104 ) ;
} else
F_90 ( V_43 ) ;
F_141 ( V_41 , & V_85 ) ;
if ( V_85 . V_97 >= 0 )
F_152 ( V_41 ) ;
V_109 = F_93 () ;
F_94 () ;
V_88 ( V_148 , & V_85 ) ;
F_4 () ;
return 0 ;
V_141:
F_11 ( V_147 L_6 ,
( unsigned long long ) V_22 << V_32 ,
( ( unsigned long long ) V_39 << V_32 ) - 1 ) ;
V_88 ( V_149 , & V_85 ) ;
F_151 ( V_22 , V_39 , V_139 ) ;
V_114:
F_4 () ;
return V_61 ;
}
int F_153 ( unsigned long V_22 , unsigned long V_40 )
{
return F_143 ( V_22 , V_22 + V_40 , 120 * V_150 ) ;
}
int F_154 ( T_1 V_3 , T_1 V_4 )
{
struct V_151 * V_152 = NULL ;
struct V_27 * V_153 ;
unsigned long V_22 , V_39 ;
unsigned long V_38 , V_25 ;
int V_61 ;
V_22 = F_155 ( V_3 ) ;
V_39 = V_22 + F_155 ( V_4 ) ;
for ( V_38 = V_22 ; V_38 < V_39 ; V_38 += V_31 ) {
V_25 = F_26 ( V_38 ) ;
if ( ! F_156 ( V_25 ) )
continue;
V_153 = F_27 ( V_25 ) ;
if ( V_152 )
if ( ( V_25 >= V_152 -> V_154 ) &&
( V_25 <= V_152 -> V_155 ) )
continue;
V_152 = F_157 ( V_153 , V_152 ) ;
if ( ! V_152 )
continue;
V_61 = F_158 ( V_152 ) ;
if ( V_61 ) {
F_159 ( & V_152 -> V_156 . V_157 ) ;
return V_61 ;
}
}
if ( V_152 )
F_159 ( & V_152 -> V_156 . V_157 ) ;
return 0 ;
}
int F_153 ( unsigned long V_22 , unsigned long V_40 )
{
return - V_70 ;
}
int F_154 ( T_1 V_3 , T_1 V_4 )
{
return - V_70 ;
}
