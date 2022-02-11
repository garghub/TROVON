static bool F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
return V_4 && F_2 ( V_4 -> V_5 , V_2 -> V_6 ) ;
}
static void F_3 ( struct V_7 * V_8 )
{
int V_9 ;
if ( ! V_8 )
return;
for ( V_9 = 0 ; V_9 < V_10 ; V_9 ++ )
F_4 ( V_8 -> V_11 [ V_9 ] ) ;
F_5 ( & V_8 -> V_12 ) ;
F_4 ( V_8 ) ;
}
static struct V_7 * F_6 ( struct V_13 * V_13 , struct V_1 * V_2 ,
T_1 V_14 )
{
struct V_7 * V_8 ;
int V_9 ;
V_8 = F_7 ( sizeof( * V_8 ) , V_14 , V_2 -> V_15 ) ;
if ( ! V_8 )
return NULL ;
V_8 -> V_2 = V_2 ;
F_8 ( & V_8 -> V_16 ) ;
V_8 -> V_13 = V_13 ;
F_9 ( & V_8 -> V_17 , 1 ) ;
if ( V_13 != & V_18 ) {
if ( F_10 ( & V_8 -> V_12 , V_2 , V_14 ) )
goto V_19;
V_8 -> V_12 . V_8 = V_8 ;
}
for ( V_9 = 0 ; V_9 < V_10 ; V_9 ++ ) {
struct V_3 * V_4 = V_3 [ V_9 ] ;
struct V_20 * V_11 ;
if ( ! F_1 ( V_2 , V_4 ) )
continue;
V_11 = F_7 ( V_4 -> V_21 , V_14 , V_2 -> V_15 ) ;
if ( ! V_11 )
goto V_19;
V_8 -> V_11 [ V_9 ] = V_11 ;
V_11 -> V_8 = V_8 ;
V_11 -> V_5 = V_9 ;
}
return V_8 ;
V_19:
F_3 ( V_8 ) ;
return NULL ;
}
struct V_7 * F_11 ( struct V_13 * V_13 , struct V_1 * V_2 ,
bool V_22 )
{
struct V_7 * V_8 ;
V_8 = F_12 ( V_13 -> V_23 ) ;
if ( V_8 && V_8 -> V_2 == V_2 )
return V_8 ;
V_8 = F_13 ( & V_13 -> V_24 , V_2 -> V_25 ) ;
if ( V_8 && V_8 -> V_2 == V_2 ) {
if ( V_22 ) {
F_14 ( V_2 -> V_26 ) ;
F_15 ( V_13 -> V_23 , V_8 ) ;
}
return V_8 ;
}
return NULL ;
}
struct V_7 * F_16 ( struct V_13 * V_13 , struct V_1 * V_2 )
{
F_17 ( ! F_18 () ) ;
if ( F_19 ( F_20 ( V_2 ) ) )
return NULL ;
return F_11 ( V_13 , V_2 , false ) ;
}
static struct V_7 * F_21 ( struct V_13 * V_13 ,
struct V_1 * V_2 ,
struct V_7 * V_27 )
{
struct V_7 * V_8 ;
struct V_28 * V_29 ;
int V_9 , V_30 ;
F_17 ( ! F_18 () ) ;
F_14 ( V_2 -> V_26 ) ;
if ( ! F_22 ( & V_13 -> V_31 ) ) {
V_30 = - V_32 ;
goto V_33;
}
V_29 = F_23 ( & V_2 -> V_34 ,
V_13 -> V_31 . V_25 , V_35 ) ;
if ( ! V_29 ) {
V_30 = - V_36 ;
goto V_37;
}
if ( ! V_27 ) {
V_27 = F_6 ( V_13 , V_2 , V_35 ) ;
if ( F_19 ( ! V_27 ) ) {
V_30 = - V_36 ;
goto V_38;
}
}
V_8 = V_27 ;
V_8 -> V_29 = V_29 ;
if ( F_24 ( V_13 ) ) {
V_8 -> V_39 = F_11 ( F_24 ( V_13 ) , V_2 , false ) ;
if ( F_17 ( ! V_8 -> V_39 ) ) {
V_30 = - V_32 ;
goto V_38;
}
F_25 ( V_8 -> V_39 ) ;
}
for ( V_9 = 0 ; V_9 < V_10 ; V_9 ++ ) {
struct V_3 * V_4 = V_3 [ V_9 ] ;
if ( V_8 -> V_11 [ V_9 ] && V_4 -> V_40 )
V_4 -> V_40 ( V_8 ) ;
}
F_26 ( & V_13 -> V_41 ) ;
V_30 = F_27 ( & V_13 -> V_24 , V_2 -> V_25 , V_8 ) ;
if ( F_28 ( ! V_30 ) ) {
F_29 ( & V_8 -> V_42 , & V_13 -> V_43 ) ;
F_30 ( & V_8 -> V_16 , & V_2 -> V_43 ) ;
for ( V_9 = 0 ; V_9 < V_10 ; V_9 ++ ) {
struct V_3 * V_4 = V_3 [ V_9 ] ;
if ( V_8 -> V_11 [ V_9 ] && V_4 -> V_44 )
V_4 -> V_44 ( V_8 ) ;
}
}
V_8 -> V_45 = true ;
F_31 ( & V_13 -> V_41 ) ;
if ( ! V_30 )
return V_8 ;
F_32 ( V_8 ) ;
return F_33 ( V_30 ) ;
V_38:
F_34 ( V_29 ) ;
V_37:
F_35 ( & V_13 -> V_31 ) ;
V_33:
F_3 ( V_27 ) ;
return F_33 ( V_30 ) ;
}
struct V_7 * F_36 ( struct V_13 * V_13 ,
struct V_1 * V_2 )
{
struct V_7 * V_8 ;
F_17 ( ! F_18 () ) ;
F_14 ( V_2 -> V_26 ) ;
if ( F_19 ( F_20 ( V_2 ) ) )
return F_33 ( F_37 ( V_2 ) ? - V_32 : - V_46 ) ;
V_8 = F_11 ( V_13 , V_2 , true ) ;
if ( V_8 )
return V_8 ;
while ( true ) {
struct V_13 * V_47 = V_13 ;
struct V_13 * V_39 = F_24 ( V_13 ) ;
while ( V_39 && ! F_11 ( V_39 , V_2 , false ) ) {
V_47 = V_39 ;
V_39 = F_24 ( V_39 ) ;
}
V_8 = F_21 ( V_47 , V_2 , NULL ) ;
if ( V_47 == V_13 || F_38 ( V_8 ) )
return V_8 ;
}
}
static void F_39 ( struct V_7 * V_8 )
{
struct V_13 * V_13 = V_8 -> V_13 ;
int V_9 ;
F_14 ( V_8 -> V_2 -> V_26 ) ;
F_14 ( & V_13 -> V_41 ) ;
F_17 ( F_40 ( & V_8 -> V_16 ) ) ;
F_17 ( F_41 ( & V_8 -> V_42 ) ) ;
for ( V_9 = 0 ; V_9 < V_10 ; V_9 ++ ) {
struct V_3 * V_4 = V_3 [ V_9 ] ;
if ( V_8 -> V_11 [ V_9 ] && V_4 -> V_48 )
V_4 -> V_48 ( V_8 ) ;
}
V_8 -> V_45 = false ;
F_42 ( & V_13 -> V_24 , V_8 -> V_2 -> V_25 ) ;
F_43 ( & V_8 -> V_16 ) ;
F_44 ( & V_8 -> V_42 ) ;
if ( F_45 ( V_13 -> V_23 ) == V_8 )
F_15 ( V_13 -> V_23 , NULL ) ;
F_32 ( V_8 ) ;
}
static void F_46 ( struct V_1 * V_2 )
{
struct V_7 * V_8 , * V_49 ;
F_14 ( V_2 -> V_26 ) ;
F_47 (blkg, n, &q->blkg_list, q_node) {
struct V_13 * V_13 = V_8 -> V_13 ;
F_26 ( & V_13 -> V_41 ) ;
F_39 ( V_8 ) ;
F_31 ( & V_13 -> V_41 ) ;
}
}
void F_48 ( struct V_50 * V_50 )
{
struct V_7 * V_8 = F_49 ( V_50 , struct V_7 , V_50 ) ;
int V_9 ;
for ( V_9 = 0 ; V_9 < V_10 ; V_9 ++ ) {
struct V_3 * V_4 = V_3 [ V_9 ] ;
if ( V_8 -> V_11 [ V_9 ] && V_4 -> V_51 )
V_4 -> V_51 ( V_8 ) ;
}
F_35 ( & V_8 -> V_13 -> V_31 ) ;
if ( V_8 -> V_39 )
F_32 ( V_8 -> V_39 ) ;
F_34 ( V_8 -> V_29 ) ;
F_3 ( V_8 ) ;
}
struct V_52 * F_50 ( struct V_52 * V_12 ,
struct V_1 * V_2 )
{
struct V_53 * V_54 ;
struct V_7 * V_8 ;
if ( V_12 == & V_2 -> V_55 ) {
V_54 = & V_2 -> V_43 ;
if ( F_40 ( V_54 ) )
return NULL ;
} else {
V_8 = F_49 ( V_12 , struct V_7 , V_12 ) ;
V_54 = & V_8 -> V_16 ;
}
V_54 = V_54 -> V_56 ;
if ( V_54 == & V_2 -> V_57 -> V_16 )
V_54 = V_54 -> V_56 ;
if ( V_54 == & V_2 -> V_43 )
return NULL ;
V_8 = F_49 ( V_54 , struct V_7 , V_16 ) ;
return & V_8 -> V_12 ;
}
static int F_51 ( struct V_58 * V_31 ,
struct V_59 * V_59 , T_2 V_60 )
{
struct V_13 * V_13 = F_52 ( V_31 ) ;
struct V_7 * V_8 ;
int V_9 ;
F_53 ( & V_61 ) ;
F_54 ( & V_13 -> V_41 ) ;
F_55 (blkg, &blkcg->blkg_list, blkcg_node) {
for ( V_9 = 0 ; V_9 < V_10 ; V_9 ++ ) {
struct V_3 * V_4 = V_3 [ V_9 ] ;
if ( F_1 ( V_8 -> V_2 , V_4 ) &&
V_4 -> V_62 )
V_4 -> V_62 ( V_8 ) ;
}
}
F_56 ( & V_13 -> V_41 ) ;
F_57 ( & V_61 ) ;
return 0 ;
}
static const char * F_58 ( struct V_7 * V_8 )
{
if ( V_8 -> V_2 -> V_34 . V_63 )
return F_59 ( V_8 -> V_2 -> V_34 . V_63 ) ;
return NULL ;
}
void F_60 ( struct V_64 * V_65 , struct V_13 * V_13 ,
T_2 (* F_61)( struct V_64 * ,
struct V_20 * , int ) ,
const struct V_3 * V_4 , int V_66 ,
bool V_67 )
{
struct V_7 * V_8 ;
T_2 V_68 = 0 ;
F_62 () ;
F_63 (blkg, &blkcg->blkg_list, blkcg_node) {
F_54 ( V_8 -> V_2 -> V_26 ) ;
if ( F_1 ( V_8 -> V_2 , V_4 ) )
V_68 += F_61 ( V_65 , V_8 -> V_11 [ V_4 -> V_5 ] , V_66 ) ;
F_56 ( V_8 -> V_2 -> V_26 ) ;
}
F_64 () ;
if ( V_67 )
F_65 ( V_65 , L_1 , ( unsigned long long ) V_68 ) ;
}
T_2 F_66 ( struct V_64 * V_65 , struct V_20 * V_11 , T_2 V_69 )
{
const char * V_70 = F_58 ( V_11 -> V_8 ) ;
if ( ! V_70 )
return 0 ;
F_65 ( V_65 , L_2 , V_70 , ( unsigned long long ) V_69 ) ;
return V_69 ;
}
T_2 F_67 ( struct V_64 * V_65 , struct V_20 * V_11 ,
const struct V_71 * V_72 )
{
static const char * V_73 [] = {
[ V_74 ] = L_3 ,
[ V_75 ] = L_4 ,
[ V_76 ] = L_5 ,
[ V_77 ] = L_6 ,
} ;
const char * V_70 = F_58 ( V_11 -> V_8 ) ;
T_2 V_69 ;
int V_9 ;
if ( ! V_70 )
return 0 ;
for ( V_9 = 0 ; V_9 < V_78 ; V_9 ++ )
F_65 ( V_65 , L_7 , V_70 , V_73 [ V_9 ] ,
( unsigned long long ) V_72 -> V_79 [ V_9 ] ) ;
V_69 = V_72 -> V_79 [ V_74 ] + V_72 -> V_79 [ V_75 ] ;
F_65 ( V_65 , L_8 , V_70 , ( unsigned long long ) V_69 ) ;
return V_69 ;
}
T_2 F_68 ( struct V_64 * V_65 , struct V_20 * V_11 , int V_80 )
{
return F_66 ( V_65 , V_11 , F_69 ( ( void * ) V_11 + V_80 ) ) ;
}
T_2 F_70 ( struct V_64 * V_65 , struct V_20 * V_11 ,
int V_80 )
{
struct V_71 V_72 = F_71 ( ( void * ) V_11 + V_80 ) ;
return F_67 ( V_65 , V_11 , & V_72 ) ;
}
T_2 F_72 ( struct V_20 * V_11 , int V_80 )
{
struct V_3 * V_4 = V_3 [ V_11 -> V_5 ] ;
struct V_7 * V_81 ;
struct V_58 * V_82 ;
T_2 V_83 = 0 ;
F_14 ( V_11 -> V_8 -> V_2 -> V_26 ) ;
F_62 () ;
F_73 (pos_blkg, pos_css, pd_to_blkg(pd)) {
struct V_20 * V_84 = F_74 ( V_81 , V_4 ) ;
struct V_85 * V_86 = ( void * ) V_84 + V_80 ;
if ( V_81 -> V_45 )
V_83 += F_69 ( V_86 ) ;
}
F_64 () ;
return V_83 ;
}
struct V_71 F_75 ( struct V_20 * V_11 ,
int V_80 )
{
struct V_3 * V_4 = V_3 [ V_11 -> V_5 ] ;
struct V_7 * V_81 ;
struct V_58 * V_82 ;
struct V_71 V_83 = { } ;
int V_9 ;
F_14 ( V_11 -> V_8 -> V_2 -> V_26 ) ;
F_62 () ;
F_73 (pos_blkg, pos_css, pd_to_blkg(pd)) {
struct V_20 * V_84 = F_74 ( V_81 , V_4 ) ;
struct V_71 * V_72 = ( void * ) V_84 + V_80 ;
struct V_71 V_87 ;
if ( ! V_81 -> V_45 )
continue;
V_87 = F_71 ( V_72 ) ;
for ( V_9 = 0 ; V_9 < V_78 ; V_9 ++ )
V_83 . V_79 [ V_9 ] += V_87 . V_79 [ V_9 ] ;
}
F_64 () ;
return V_83 ;
}
int F_76 ( struct V_13 * V_13 , const struct V_3 * V_4 ,
const char * V_88 , struct V_89 * V_90 )
__acquires( T_3 ) __acquires( V_91 -> V_92 -> V_26 )
{
struct V_93 * V_91 ;
struct V_7 * V_8 ;
unsigned int V_94 , V_95 ;
unsigned long long V_69 ;
int V_96 , V_30 ;
if ( sscanf ( V_88 , L_9 , & V_94 , & V_95 , & V_69 ) != 3 )
return - V_32 ;
V_91 = F_77 ( F_78 ( V_94 , V_95 ) , & V_96 ) ;
if ( ! V_91 )
return - V_32 ;
if ( V_96 ) {
F_79 ( V_91 ) ;
return - V_32 ;
}
F_62 () ;
F_54 ( V_91 -> V_92 -> V_26 ) ;
if ( F_1 ( V_91 -> V_92 , V_4 ) )
V_8 = F_36 ( V_13 , V_91 -> V_92 ) ;
else
V_8 = F_33 ( - V_32 ) ;
if ( F_38 ( V_8 ) ) {
V_30 = F_80 ( V_8 ) ;
F_64 () ;
F_56 ( V_91 -> V_92 -> V_26 ) ;
F_79 ( V_91 ) ;
if ( V_30 == - V_46 ) {
F_81 ( 10 ) ;
V_30 = F_82 () ;
}
return V_30 ;
}
V_90 -> V_91 = V_91 ;
V_90 -> V_8 = V_8 ;
V_90 -> V_69 = V_69 ;
return 0 ;
}
void F_83 ( struct V_89 * V_90 )
__releases( V_90 -> V_91 -> V_92 -> V_26 ) __releases( T_3 )
{
F_56 ( V_90 -> V_91 -> V_92 -> V_26 ) ;
F_64 () ;
F_79 ( V_90 -> V_91 ) ;
}
static void F_84 ( struct V_58 * V_31 )
{
struct V_13 * V_13 = F_52 ( V_31 ) ;
F_54 ( & V_13 -> V_41 ) ;
while ( ! F_85 ( & V_13 -> V_43 ) ) {
struct V_7 * V_8 = F_86 ( V_13 -> V_43 . V_97 ,
struct V_7 , V_42 ) ;
struct V_1 * V_2 = V_8 -> V_2 ;
if ( F_87 ( V_2 -> V_26 ) ) {
F_39 ( V_8 ) ;
F_31 ( V_2 -> V_26 ) ;
} else {
F_56 ( & V_13 -> V_41 ) ;
F_88 () ;
F_54 ( & V_13 -> V_41 ) ;
}
}
F_56 ( & V_13 -> V_41 ) ;
F_89 ( V_13 ) ;
}
static void F_90 ( struct V_58 * V_31 )
{
struct V_13 * V_13 = F_52 ( V_31 ) ;
F_53 ( & V_61 ) ;
F_91 ( & V_13 -> V_98 ) ;
F_57 ( & V_61 ) ;
if ( V_13 != & V_18 ) {
int V_9 ;
for ( V_9 = 0 ; V_9 < V_10 ; V_9 ++ )
F_4 ( V_13 -> V_11 [ V_9 ] ) ;
F_4 ( V_13 ) ;
}
}
static struct V_58 *
F_92 ( struct V_58 * V_99 )
{
struct V_13 * V_13 ;
struct V_58 * V_30 ;
int V_9 ;
F_53 ( & V_61 ) ;
if ( ! V_99 ) {
V_13 = & V_18 ;
goto V_100;
}
V_13 = F_93 ( sizeof( * V_13 ) , V_101 ) ;
if ( ! V_13 ) {
V_30 = F_33 ( - V_36 ) ;
goto V_102;
}
for ( V_9 = 0 ; V_9 < V_10 ; V_9 ++ ) {
struct V_3 * V_4 = V_3 [ V_9 ] ;
struct V_103 * V_104 ;
if ( ! V_4 || ! V_4 -> V_105 )
continue;
F_94 ( V_13 -> V_11 [ V_9 ] ) ;
V_104 = F_93 ( V_4 -> V_105 , V_101 ) ;
if ( ! V_104 ) {
V_30 = F_33 ( - V_36 ) ;
goto V_106;
}
V_13 -> V_11 [ V_9 ] = V_104 ;
V_104 -> V_5 = V_9 ;
V_4 -> V_107 ( V_13 ) ;
}
V_100:
F_95 ( & V_13 -> V_41 ) ;
F_96 ( & V_13 -> V_24 , V_35 ) ;
F_97 ( & V_13 -> V_43 ) ;
#ifdef F_98
F_8 ( & V_13 -> V_108 ) ;
#endif
F_99 ( & V_13 -> V_98 , & V_109 ) ;
F_57 ( & V_61 ) ;
return & V_13 -> V_31 ;
V_106:
for ( V_9 -- ; V_9 >= 0 ; V_9 -- )
F_4 ( V_13 -> V_11 [ V_9 ] ) ;
V_102:
F_4 ( V_13 ) ;
F_57 ( & V_61 ) ;
return V_30 ;
}
int F_100 ( struct V_1 * V_2 )
{
struct V_7 * V_27 , * V_8 ;
bool V_110 ;
int V_30 ;
V_27 = F_6 ( & V_18 , V_2 , V_101 ) ;
if ( ! V_27 )
return - V_36 ;
V_110 = ! F_101 ( V_101 ) ;
F_62 () ;
F_54 ( V_2 -> V_26 ) ;
V_8 = F_21 ( & V_18 , V_2 , V_27 ) ;
F_56 ( V_2 -> V_26 ) ;
F_64 () ;
if ( V_110 )
F_102 () ;
if ( F_38 ( V_8 ) ) {
F_4 ( V_27 ) ;
return F_80 ( V_8 ) ;
}
V_2 -> V_57 = V_8 ;
V_2 -> V_55 . V_8 = V_8 ;
V_30 = F_103 ( V_2 ) ;
if ( V_30 ) {
F_54 ( V_2 -> V_26 ) ;
F_46 ( V_2 ) ;
F_56 ( V_2 -> V_26 ) ;
}
return V_30 ;
}
void F_104 ( struct V_1 * V_2 )
{
F_14 ( V_2 -> V_26 ) ;
if ( ! V_2 -> V_57 )
return;
F_105 ( V_2 ) ;
}
void F_106 ( struct V_1 * V_2 )
{
F_54 ( V_2 -> V_26 ) ;
F_46 ( V_2 ) ;
F_56 ( V_2 -> V_26 ) ;
F_107 ( V_2 ) ;
}
static int F_108 ( struct V_58 * V_31 ,
struct V_111 * V_112 )
{
struct V_113 * V_114 ;
struct V_115 * V_116 ;
int V_30 = 0 ;
F_109 (task, tset) {
F_110 ( V_114 ) ;
V_116 = V_114 -> V_115 ;
if ( V_116 && F_111 ( & V_116 -> V_117 ) > 1 )
V_30 = - V_32 ;
F_112 ( V_114 ) ;
if ( V_30 )
break;
}
return V_30 ;
}
int F_113 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
F_114 ( V_118 ) ;
struct V_7 * V_8 ;
struct V_20 * V_11 , * V_119 ;
int V_79 = 0 , V_30 ;
if ( F_1 ( V_2 , V_4 ) )
return 0 ;
F_115 ( V_2 ) ;
F_54 ( V_2 -> V_26 ) ;
F_116 (blkg, &q->blkg_list, q_node)
V_79 ++ ;
F_56 ( V_2 -> V_26 ) ;
while ( V_79 -- ) {
V_11 = F_7 ( V_4 -> V_21 , V_101 , V_2 -> V_15 ) ;
if ( ! V_11 ) {
V_30 = - V_36 ;
goto V_120;
}
F_99 ( & V_11 -> V_121 , & V_118 ) ;
}
F_54 ( V_2 -> V_26 ) ;
F_116 (blkg, &q->blkg_list, q_node) {
if ( F_117 ( F_40 ( & V_118 ) ) ) {
V_30 = - V_36 ;
goto V_122;
}
V_11 = F_118 ( & V_118 , struct V_20 , V_121 ) ;
F_43 ( & V_11 -> V_121 ) ;
F_26 ( & V_8 -> V_13 -> V_41 ) ;
V_8 -> V_11 [ V_4 -> V_5 ] = V_11 ;
V_11 -> V_8 = V_8 ;
V_11 -> V_5 = V_4 -> V_5 ;
V_4 -> V_40 ( V_8 ) ;
F_31 ( & V_8 -> V_13 -> V_41 ) ;
}
F_119 ( V_4 -> V_5 , V_2 -> V_6 ) ;
V_30 = 0 ;
V_122:
F_56 ( V_2 -> V_26 ) ;
V_120:
F_120 ( V_2 ) ;
F_47 (pd, nd, &pds, alloc_node)
F_4 ( V_11 ) ;
return V_30 ;
}
void F_121 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
struct V_7 * V_8 ;
if ( ! F_1 ( V_2 , V_4 ) )
return;
F_115 ( V_2 ) ;
F_54 ( V_2 -> V_26 ) ;
F_122 ( V_4 -> V_5 , V_2 -> V_6 ) ;
F_116 (blkg, &q->blkg_list, q_node) {
F_26 ( & V_8 -> V_13 -> V_41 ) ;
if ( V_4 -> V_48 )
V_4 -> V_48 ( V_8 ) ;
if ( V_4 -> V_51 )
V_4 -> V_51 ( V_8 ) ;
F_4 ( V_8 -> V_11 [ V_4 -> V_5 ] ) ;
V_8 -> V_11 [ V_4 -> V_5 ] = NULL ;
F_31 ( & V_8 -> V_13 -> V_41 ) ;
}
F_56 ( V_2 -> V_26 ) ;
F_120 ( V_2 ) ;
}
int F_123 ( struct V_3 * V_4 )
{
struct V_13 * V_13 ;
int V_9 , V_30 ;
if ( F_117 ( V_4 -> V_21 < sizeof( struct V_20 ) ) )
return - V_32 ;
F_53 ( & V_123 ) ;
F_53 ( & V_61 ) ;
V_30 = - V_124 ;
for ( V_9 = 0 ; V_9 < V_10 ; V_9 ++ )
if ( ! V_3 [ V_9 ] )
break;
if ( V_9 >= V_10 )
goto V_125;
V_4 -> V_5 = V_9 ;
V_3 [ V_4 -> V_5 ] = V_4 ;
if ( V_4 -> V_105 ) {
F_116 (blkcg, &all_blkcgs, all_blkcgs_node) {
struct V_103 * V_104 ;
V_104 = F_93 ( V_4 -> V_105 , V_101 ) ;
if ( ! V_104 ) {
F_57 ( & V_61 ) ;
goto V_126;
}
V_13 -> V_11 [ V_4 -> V_5 ] = V_104 ;
V_104 -> V_5 = V_4 -> V_5 ;
V_4 -> V_107 ( V_13 ) ;
}
}
F_57 ( & V_61 ) ;
if ( V_4 -> V_127 )
F_117 ( F_124 ( & V_128 ,
V_4 -> V_127 ) ) ;
F_57 ( & V_123 ) ;
return 0 ;
V_126:
if ( V_4 -> V_105 ) {
F_116 (blkcg, &all_blkcgs, all_blkcgs_node) {
F_4 ( V_13 -> V_11 [ V_4 -> V_5 ] ) ;
V_13 -> V_11 [ V_4 -> V_5 ] = NULL ;
}
}
V_3 [ V_4 -> V_5 ] = NULL ;
V_125:
F_57 ( & V_61 ) ;
F_57 ( & V_123 ) ;
return V_30 ;
}
void F_125 ( struct V_3 * V_4 )
{
struct V_13 * V_13 ;
F_53 ( & V_123 ) ;
if ( F_117 ( V_3 [ V_4 -> V_5 ] != V_4 ) )
goto V_122;
if ( V_4 -> V_127 )
F_126 ( V_4 -> V_127 ) ;
F_53 ( & V_61 ) ;
if ( V_4 -> V_105 ) {
F_116 (blkcg, &all_blkcgs, all_blkcgs_node) {
F_4 ( V_13 -> V_11 [ V_4 -> V_5 ] ) ;
V_13 -> V_11 [ V_4 -> V_5 ] = NULL ;
}
}
V_3 [ V_4 -> V_5 ] = NULL ;
F_57 ( & V_61 ) ;
V_122:
F_57 ( & V_123 ) ;
}
