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
type = ( unsigned long ) V_14 -> V_15 . V_16 ;
F_9 ( type < V_19 ||
type > V_20 ) ;
if ( F_20 ( & V_14 -> V_18 ) == 1 ) {
F_21 ( V_14 ) ;
F_17 ( V_14 , 0 ) ;
F_22 ( & V_14 -> V_15 ) ;
F_23 ( V_14 , 0 ) ;
}
}
static void F_24 ( unsigned long V_21 )
{
unsigned long * V_22 , V_23 , V_24 , V_25 ;
struct V_26 * V_27 ;
struct V_14 * V_14 , * V_28 ;
if ( ! F_25 ( V_21 ) )
return;
V_24 = F_26 ( V_21 ) ;
V_27 = F_27 ( V_24 ) ;
V_28 = F_28 ( V_27 -> V_29 , V_24 ) ;
V_14 = F_29 ( V_28 ) ;
V_23 = sizeof( struct V_14 ) * V_30 ;
V_23 = F_30 ( V_23 ) >> V_31 ;
for ( V_25 = 0 ; V_25 < V_23 ; V_25 ++ , V_14 ++ )
F_15 ( V_24 , V_14 , V_32 ) ;
V_22 = F_27 ( V_24 ) -> V_33 ;
V_14 = F_29 ( V_22 ) ;
V_23 = F_30 ( F_31 () ) >> V_31 ;
for ( V_25 = 0 ; V_25 < V_23 ; V_25 ++ , V_14 ++ )
F_15 ( V_24 , V_14 , V_34 ) ;
}
void F_32 ( struct V_35 * V_36 )
{
unsigned long V_25 , V_37 , V_38 , V_39 ;
int V_40 = V_36 -> V_41 ;
struct V_14 * V_14 ;
struct V_42 * V_42 ;
V_39 = F_30 ( sizeof( struct V_35 ) ) >> V_31 ;
V_14 = F_29 ( V_36 ) ;
for ( V_25 = 0 ; V_25 < V_39 ; V_25 ++ , V_14 ++ )
F_15 ( V_40 , V_14 , V_43 ) ;
V_42 = & V_36 -> V_44 [ 0 ] ;
for (; V_42 < V_36 -> V_44 + V_45 - 1 ; V_42 ++ ) {
if ( V_42 -> V_46 ) {
V_39 = V_42 -> V_47
* sizeof( V_48 ) ;
V_39 = F_30 ( V_39 ) >> V_31 ;
V_14 = F_29 ( V_42 -> V_46 ) ;
for ( V_25 = 0 ; V_25 < V_39 ; V_25 ++ , V_14 ++ )
F_15 ( V_40 , V_14 , V_43 ) ;
}
}
V_37 = V_36 -> V_49 ;
V_38 = V_37 + V_36 -> V_50 ;
for (; V_37 < V_38 ; V_37 += V_30 )
F_24 ( V_37 ) ;
}
static void F_33 ( struct V_42 * V_42 , unsigned long V_21 ,
unsigned long V_38 )
{
unsigned long V_51 ;
F_34 ( V_42 ) ;
V_51 = V_42 -> V_52 + V_42 -> V_53 ;
if ( V_21 < V_42 -> V_52 )
V_42 -> V_52 = V_21 ;
V_42 -> V_53 = F_35 ( V_51 , V_38 ) -
V_42 -> V_52 ;
F_36 ( V_42 ) ;
}
static void F_37 ( struct V_35 * V_36 , unsigned long V_21 ,
unsigned long V_38 )
{
unsigned long V_54 =
V_36 -> V_49 + V_36 -> V_50 ;
if ( V_21 < V_36 -> V_49 )
V_36 -> V_49 = V_21 ;
V_36 -> V_50 = F_35 ( V_54 , V_38 ) -
V_36 -> V_49 ;
}
static int T_3 F_38 ( struct V_42 * V_42 , unsigned long V_55 )
{
struct V_35 * V_36 = V_42 -> V_56 ;
int V_39 = V_30 ;
int V_57 = V_36 -> V_41 ;
int V_58 ;
unsigned long V_9 ;
V_58 = V_42 - V_36 -> V_44 ;
if ( ! V_42 -> V_46 ) {
int V_59 ;
V_59 = F_39 ( V_42 , V_55 ,
V_39 , V_60 ) ;
if ( V_59 )
return V_59 ;
}
F_40 ( V_42 -> V_56 , & V_9 ) ;
F_33 ( V_42 , V_55 , V_55 + V_39 ) ;
F_37 ( V_42 -> V_56 , V_55 ,
V_55 + V_39 ) ;
F_41 ( V_42 -> V_56 , & V_9 ) ;
F_42 ( V_39 , V_57 , V_58 ,
V_55 , V_60 ) ;
return 0 ;
}
static int T_3 F_43 ( int V_57 , struct V_42 * V_42 ,
unsigned long V_55 )
{
int V_39 = V_30 ;
int V_59 ;
if ( F_25 ( V_55 ) )
return - V_61 ;
V_59 = F_44 ( V_42 , V_55 , V_39 ) ;
if ( V_59 < 0 )
return V_59 ;
V_59 = F_38 ( V_42 , V_55 ) ;
if ( V_59 < 0 )
return V_59 ;
return F_45 ( V_57 , F_46 ( V_55 ) ) ;
}
static int F_47 ( struct V_42 * V_42 , struct V_26 * V_27 )
{
return - V_62 ;
}
static int F_47 ( struct V_42 * V_42 , struct V_26 * V_27 )
{
unsigned long V_9 ;
struct V_35 * V_36 = V_42 -> V_56 ;
int V_59 = - V_63 ;
if ( ! F_48 ( V_27 ) )
return V_59 ;
V_59 = F_49 ( V_27 ) ;
if ( V_59 )
return V_59 ;
F_40 ( V_36 , & V_9 ) ;
F_50 ( V_42 , V_27 ) ;
F_41 ( V_36 , & V_9 ) ;
return 0 ;
}
int T_2 F_51 ( int V_57 , struct V_42 * V_42 , unsigned long V_55 ,
unsigned long V_39 )
{
unsigned long V_25 ;
int V_64 = 0 ;
int V_65 , V_66 ;
V_65 = F_26 ( V_55 ) ;
V_66 = F_26 ( V_55 + V_39 - 1 ) ;
for ( V_25 = V_65 ; V_25 <= V_66 ; V_25 ++ ) {
V_64 = F_43 ( V_57 , V_42 , V_25 << V_67 ) ;
if ( V_64 && ( V_64 != - V_61 ) )
break;
V_64 = 0 ;
}
return V_64 ;
}
int F_52 ( struct V_42 * V_42 , unsigned long V_55 ,
unsigned long V_39 )
{
unsigned long V_25 , V_59 = 0 ;
int V_68 ;
F_9 ( V_55 & ~ V_69 ) ;
F_9 ( V_39 % V_30 ) ;
V_68 = V_39 / V_30 ;
for ( V_25 = 0 ; V_25 < V_68 ; V_25 ++ ) {
unsigned long V_37 = V_55 + V_25 * V_30 ;
F_53 ( V_37 << V_31 ,
V_30 << V_31 ) ;
V_59 = F_47 ( V_42 , F_46 ( V_37 ) ) ;
if ( V_59 )
break;
}
return V_59 ;
}
int F_54 ( T_4 V_70 )
{
int V_71 = - V_63 ;
F_1 () ;
if ( V_72 == V_73 ) {
V_72 = V_70 ;
V_71 = 0 ;
}
F_4 () ;
return V_71 ;
}
int F_55 ( T_4 V_70 )
{
int V_71 = - V_63 ;
F_1 () ;
if ( V_72 == V_70 ) {
V_72 = V_73 ;
V_71 = 0 ;
}
F_4 () ;
return V_71 ;
}
void F_56 ( struct V_14 * V_14 )
{
unsigned long V_37 = F_57 ( V_14 ) ;
if ( V_37 >= V_74 )
V_74 = V_37 + 1 ;
}
void F_58 ( struct V_14 * V_14 )
{
V_75 ++ ;
#ifdef F_59
if ( F_60 ( V_14 ) )
V_76 ++ ;
#endif
}
void F_61 ( struct V_14 * V_14 )
{
F_62 ( V_14 ) ;
F_63 ( V_14 ) ;
F_64 ( V_14 ) ;
}
static void V_73 ( struct V_14 * V_14 )
{
F_56 ( V_14 ) ;
F_58 ( V_14 ) ;
F_61 ( V_14 ) ;
}
static int F_65 ( unsigned long V_21 , unsigned long V_39 ,
void * V_77 )
{
unsigned long V_25 ;
unsigned long V_78 = * ( unsigned long * ) V_77 ;
struct V_14 * V_14 ;
if ( F_66 ( F_67 ( V_21 ) ) )
for ( V_25 = 0 ; V_25 < V_39 ; V_25 ++ ) {
V_14 = F_67 ( V_21 + V_25 ) ;
(* V_72)( V_14 ) ;
V_78 ++ ;
}
* ( unsigned long * ) V_77 = V_78 ;
return 0 ;
}
int T_2 F_68 ( unsigned long V_37 , unsigned long V_39 )
{
unsigned long V_78 = 0 ;
struct V_42 * V_42 ;
int V_79 = 0 ;
int V_57 ;
int V_59 ;
struct V_80 V_77 ;
F_1 () ;
V_77 . V_21 = V_37 ;
V_77 . V_39 = V_39 ;
V_77 . V_81 = - 1 ;
V_57 = F_69 ( F_67 ( V_37 ) ) ;
if ( F_70 ( V_57 ) == 0 )
V_77 . V_81 = V_57 ;
V_59 = V_80 ( V_82 , & V_77 ) ;
V_59 = F_71 ( V_59 ) ;
if ( V_59 ) {
V_80 ( V_83 , & V_77 ) ;
F_4 () ;
return V_59 ;
}
V_42 = F_72 ( F_67 ( V_37 ) ) ;
F_2 ( & V_84 ) ;
if ( ! F_73 ( V_42 ) )
V_79 = 1 ;
V_59 = F_74 ( V_37 , V_39 , & V_78 ,
F_65 ) ;
if ( V_59 ) {
F_6 ( & V_84 ) ;
F_11 ( V_85 L_3 ,
( unsigned long long ) V_37 << V_31 ,
( ( ( unsigned long long ) V_37 + V_39 )
<< V_31 ) - 1 ) ;
V_80 ( V_83 , & V_77 ) ;
F_4 () ;
return V_59 ;
}
V_42 -> V_86 += V_78 ;
V_42 -> V_56 -> F_70 += V_78 ;
if ( V_79 )
F_75 ( V_42 ) ;
else
F_76 ( V_42 ) ;
F_6 ( & V_84 ) ;
F_77 () ;
if ( V_78 ) {
F_78 ( F_79 ( V_42 ) ) ;
F_80 ( F_79 ( V_42 ) , V_87 ) ;
}
V_88 = F_81 () ;
F_82 () ;
if ( V_78 )
V_80 ( V_89 , & V_77 ) ;
F_4 () ;
return 0 ;
}
static T_5 T_2 * F_83 ( int V_57 , T_1 V_3 )
{
struct V_35 * V_36 ;
unsigned long V_90 [ V_45 ] = { 0 } ;
unsigned long V_91 [ V_45 ] = { 0 } ;
unsigned long V_21 = V_3 >> V_31 ;
V_36 = F_84 ( V_57 ) ;
if ( ! V_36 )
return NULL ;
F_85 ( V_57 , V_36 ) ;
F_86 ( V_57 , V_90 , V_21 , V_91 ) ;
F_2 ( & V_84 ) ;
F_75 ( NULL ) ;
F_6 ( & V_84 ) ;
return V_36 ;
}
static void F_87 ( int V_57 , T_5 * V_36 )
{
F_85 ( V_57 , NULL ) ;
F_88 ( V_36 ) ;
return;
}
int F_89 ( int V_57 )
{
T_5 * V_36 ;
int V_59 ;
F_1 () ;
V_36 = F_83 ( V_57 , 0 ) ;
if ( ! V_36 ) {
V_59 = - V_92 ;
goto V_93;
}
F_90 ( V_57 ) ;
V_59 = F_91 ( V_57 ) ;
F_9 ( V_59 ) ;
V_93:
F_4 () ;
return V_59 ;
}
int T_2 F_92 ( int V_57 , T_1 V_3 , T_1 V_4 )
{
T_5 * V_36 = NULL ;
int V_94 = 0 ;
struct V_2 * V_5 ;
int V_59 ;
F_1 () ;
V_5 = F_7 ( V_3 , V_4 ) ;
V_59 = - V_61 ;
if ( ! V_5 )
goto V_93;
if ( ! F_93 ( V_57 ) ) {
V_36 = F_83 ( V_57 , V_3 ) ;
V_59 = - V_92 ;
if ( ! V_36 )
goto error;
V_94 = 1 ;
}
V_59 = F_94 ( V_57 , V_3 , V_4 ) ;
if ( V_59 < 0 )
goto error;
F_90 ( V_57 ) ;
if ( V_94 ) {
V_59 = F_91 ( V_57 ) ;
F_9 ( V_59 ) ;
}
F_95 ( V_3 , V_3 + V_4 , L_1 ) ;
goto V_93;
error:
if ( V_94 )
F_87 ( V_57 , V_36 ) ;
if ( V_5 )
F_13 ( V_5 ) ;
V_93:
F_4 () ;
return V_59 ;
}
static inline int F_96 ( struct V_14 * V_14 )
{
return F_97 ( V_14 ) && F_98 ( V_14 ) >= V_95 ;
}
static struct V_14 * F_99 ( struct V_14 * V_14 )
{
F_9 ( F_57 ( V_14 ) & ( V_96 - 1 ) ) ;
if ( F_96 ( V_14 ) ) {
int V_97 ;
V_97 = F_98 ( V_14 ) ;
if ( ( V_97 < V_98 ) && ( V_97 >= V_95 ) )
return V_14 + ( 1 << V_97 ) ;
}
return V_14 + V_96 ;
}
int F_100 ( unsigned long V_21 , unsigned long V_39 )
{
struct V_14 * V_14 = F_67 ( V_21 ) ;
struct V_14 * V_99 = V_14 + V_39 ;
for (; V_14 < V_99 ; V_14 = F_99 ( V_14 ) ) {
if ( ! F_101 ( V_14 ) )
return 0 ;
F_102 () ;
}
return 1 ;
}
static int F_103 ( unsigned long V_21 , unsigned long V_38 )
{
unsigned long V_37 ;
struct V_42 * V_42 = NULL ;
struct V_14 * V_14 ;
int V_25 ;
for ( V_37 = V_21 ;
V_37 < V_38 ;
V_37 += V_100 ) {
V_25 = 0 ;
while ( ( V_25 < V_100 ) && ! F_104 ( V_37 + V_25 ) )
V_25 ++ ;
if ( V_25 == V_100 )
continue;
V_14 = F_67 ( V_37 + V_25 ) ;
if ( V_42 && F_72 ( V_14 ) != V_42 )
return 0 ;
V_42 = F_72 ( V_14 ) ;
}
return 1 ;
}
static unsigned long F_105 ( unsigned long V_3 , unsigned long V_8 )
{
unsigned long V_37 ;
struct V_14 * V_14 ;
for ( V_37 = V_3 ; V_37 < V_8 ; V_37 ++ ) {
if ( F_25 ( V_37 ) ) {
V_14 = F_67 ( V_37 ) ;
if ( F_106 ( V_14 ) )
return V_37 ;
}
}
return 0 ;
}
static struct V_14 *
F_107 ( struct V_14 * V_14 , unsigned long V_101 , int * * V_102 )
{
return F_108 ( V_103 ) ;
}
static int
F_109 ( unsigned long V_21 , unsigned long V_38 )
{
unsigned long V_37 ;
struct V_14 * V_14 ;
int V_104 = V_105 ;
int V_106 = 0 ;
int V_59 = 0 ;
F_110 ( V_107 ) ;
for ( V_37 = V_21 ; V_37 < V_38 && V_104 > 0 ; V_37 ++ ) {
if ( ! F_25 ( V_37 ) )
continue;
V_14 = F_67 ( V_37 ) ;
if ( ! F_111 ( V_14 ) )
continue;
V_59 = F_112 ( V_14 ) ;
if ( ! V_59 ) {
F_113 ( V_14 ) ;
F_114 ( & V_14 -> V_15 , & V_107 ) ;
V_104 -- ;
F_115 ( V_14 , V_108 +
F_116 ( V_14 ) ) ;
} else {
#ifdef F_117
F_11 ( V_109 L_4 ,
V_37 ) ;
F_118 ( V_14 ) ;
#endif
F_113 ( V_14 ) ;
if ( F_119 ( V_14 ) ) {
V_106 ++ ;
V_59 = - V_62 ;
break;
}
}
}
if ( ! F_120 ( & V_107 ) ) {
if ( V_106 ) {
F_121 ( & V_107 ) ;
goto V_93;
}
V_59 = F_122 ( & V_107 , F_107 , 0 ,
true , V_110 ) ;
if ( V_59 )
F_121 ( & V_107 ) ;
}
V_93:
return V_59 ;
}
static int
F_123 ( unsigned long V_3 , unsigned long V_39 ,
void * V_111 )
{
F_124 ( V_3 , V_3 + V_39 ) ;
return 0 ;
}
static void
F_125 ( unsigned long V_21 , unsigned long V_38 )
{
F_74 ( V_21 , V_38 - V_21 , NULL ,
F_123 ) ;
}
static int
F_126 ( unsigned long V_21 , unsigned long V_39 ,
void * V_111 )
{
int V_59 ;
long V_112 = * ( long * ) V_111 ;
V_59 = F_127 ( V_21 , V_21 + V_39 ) ;
V_112 = V_39 ;
if ( ! V_59 )
* ( long * ) V_111 += V_112 ;
return V_59 ;
}
static long
F_128 ( unsigned long V_21 , unsigned long V_38 )
{
long V_112 = 0 ;
int V_59 ;
V_59 = F_74 ( V_21 , V_38 - V_21 , & V_112 ,
F_126 ) ;
if ( V_59 < 0 )
V_112 = ( long ) V_59 ;
return V_112 ;
}
static int T_2 F_129 ( unsigned long V_21 ,
unsigned long V_38 , unsigned long V_113 )
{
unsigned long V_37 , V_39 , V_114 ;
long V_115 ;
int V_59 , V_116 , V_117 , V_40 ;
struct V_42 * V_42 ;
struct V_80 V_77 ;
F_9 ( V_21 >= V_38 ) ;
if ( ! F_130 ( V_21 , V_96 ) )
return - V_63 ;
if ( ! F_130 ( V_38 , V_96 ) )
return - V_63 ;
if ( ! F_103 ( V_21 , V_38 ) )
return - V_63 ;
F_1 () ;
V_42 = F_72 ( F_67 ( V_21 ) ) ;
V_40 = F_79 ( V_42 ) ;
V_39 = V_38 - V_21 ;
V_59 = F_131 ( V_21 , V_38 , V_118 ) ;
if ( V_59 )
goto V_93;
V_77 . V_21 = V_21 ;
V_77 . V_39 = V_39 ;
V_77 . V_81 = - 1 ;
if ( V_39 >= F_70 ( V_40 ) )
V_77 . V_81 = V_40 ;
V_59 = V_80 ( V_119 , & V_77 ) ;
V_59 = F_71 ( V_59 ) ;
if ( V_59 )
goto V_120;
V_37 = V_21 ;
V_114 = V_121 + V_113 ;
V_116 = 0 ;
V_117 = 5 ;
V_122:
V_59 = - V_123 ;
if ( F_132 ( V_121 , V_114 ) )
goto V_120;
V_59 = - V_124 ;
if ( F_133 ( V_125 ) )
goto V_120;
V_59 = 0 ;
if ( V_116 ) {
F_134 () ;
F_102 () ;
F_135 () ;
}
V_37 = F_105 ( V_21 , V_38 ) ;
if ( V_37 ) {
V_59 = F_109 ( V_37 , V_38 ) ;
if ( ! V_59 ) {
V_116 = 1 ;
goto V_122;
} else {
if ( V_59 < 0 )
if ( -- V_117 == 0 )
goto V_120;
F_136 () ;
V_116 = 1 ;
goto V_122;
}
}
F_134 () ;
F_136 () ;
F_135 () ;
V_115 = F_128 ( V_21 , V_38 ) ;
if ( V_115 < 0 ) {
V_59 = - V_62 ;
goto V_120;
}
F_11 ( V_126 L_5 , V_115 ) ;
F_125 ( V_21 , V_38 ) ;
F_137 ( V_21 , V_38 , V_118 ) ;
V_42 -> V_86 -= V_115 ;
V_42 -> V_56 -> F_70 -= V_115 ;
V_75 -= V_115 ;
F_77 () ;
if ( ! F_70 ( V_40 ) ) {
F_138 ( V_40 , V_87 ) ;
F_139 ( V_40 ) ;
}
V_88 = F_81 () ;
F_82 () ;
V_80 ( V_127 , & V_77 ) ;
F_4 () ;
return 0 ;
V_120:
F_11 ( V_126 L_6 ,
( unsigned long long ) V_21 << V_31 ,
( ( unsigned long long ) V_38 << V_31 ) - 1 ) ;
V_80 ( V_128 , & V_77 ) ;
F_137 ( V_21 , V_38 , V_118 ) ;
V_93:
F_4 () ;
return V_59 ;
}
int F_140 ( T_1 V_3 , T_1 V_4 )
{
unsigned long V_21 , V_38 ;
V_21 = F_141 ( V_3 ) ;
V_38 = V_21 + F_141 ( V_4 ) ;
return F_129 ( V_21 , V_38 , 120 * V_129 ) ;
}
int F_140 ( T_1 V_3 , T_1 V_4 )
{
return - V_63 ;
}
