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
V_8 -> V_17 = 1 ;
if ( V_13 != & V_18 ) {
if ( F_9 ( & V_8 -> V_12 , V_2 , V_14 ) )
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
struct V_7 * F_10 ( struct V_13 * V_13 , struct V_1 * V_2 ,
bool V_22 )
{
struct V_7 * V_8 ;
V_8 = F_11 ( V_13 -> V_23 ) ;
if ( V_8 && V_8 -> V_2 == V_2 )
return V_8 ;
V_8 = F_12 ( & V_13 -> V_24 , V_2 -> V_25 ) ;
if ( V_8 && V_8 -> V_2 == V_2 ) {
if ( V_22 ) {
F_13 ( V_2 -> V_26 ) ;
F_14 ( V_13 -> V_23 , V_8 ) ;
}
return V_8 ;
}
return NULL ;
}
struct V_7 * F_15 ( struct V_13 * V_13 , struct V_1 * V_2 )
{
F_16 ( ! F_17 () ) ;
if ( F_18 ( F_19 ( V_2 ) ) )
return NULL ;
return F_10 ( V_13 , V_2 , false ) ;
}
static struct V_7 * F_20 ( struct V_13 * V_13 ,
struct V_1 * V_2 ,
struct V_7 * V_27 )
{
struct V_7 * V_8 ;
int V_9 , V_28 ;
F_16 ( ! F_17 () ) ;
F_13 ( V_2 -> V_26 ) ;
if ( ! F_21 ( & V_13 -> V_29 ) ) {
V_28 = - V_30 ;
goto V_31;
}
if ( ! V_27 ) {
V_27 = F_6 ( V_13 , V_2 , V_32 ) ;
if ( F_18 ( ! V_27 ) ) {
V_28 = - V_33 ;
goto V_34;
}
}
V_8 = V_27 ;
if ( F_22 ( V_13 ) ) {
V_8 -> V_35 = F_10 ( F_22 ( V_13 ) , V_2 , false ) ;
if ( F_16 ( ! V_8 -> V_35 ) ) {
V_28 = - V_30 ;
goto V_34;
}
F_23 ( V_8 -> V_35 ) ;
}
for ( V_9 = 0 ; V_9 < V_10 ; V_9 ++ ) {
struct V_3 * V_4 = V_3 [ V_9 ] ;
if ( V_8 -> V_11 [ V_9 ] && V_4 -> V_36 )
V_4 -> V_36 ( V_8 ) ;
}
F_24 ( & V_13 -> V_37 ) ;
V_28 = F_25 ( & V_13 -> V_24 , V_2 -> V_25 , V_8 ) ;
if ( F_26 ( ! V_28 ) ) {
F_27 ( & V_8 -> V_38 , & V_13 -> V_39 ) ;
F_28 ( & V_8 -> V_16 , & V_2 -> V_39 ) ;
for ( V_9 = 0 ; V_9 < V_10 ; V_9 ++ ) {
struct V_3 * V_4 = V_3 [ V_9 ] ;
if ( V_8 -> V_11 [ V_9 ] && V_4 -> V_40 )
V_4 -> V_40 ( V_8 ) ;
}
}
V_8 -> V_41 = true ;
F_29 ( & V_13 -> V_37 ) ;
if ( ! V_28 ) {
if ( V_13 == & V_18 ) {
V_2 -> V_42 = V_8 ;
V_2 -> V_43 . V_8 = V_8 ;
}
return V_8 ;
}
F_30 ( V_8 ) ;
return F_31 ( V_28 ) ;
V_34:
F_32 ( & V_13 -> V_29 ) ;
V_31:
F_3 ( V_27 ) ;
return F_31 ( V_28 ) ;
}
struct V_7 * F_33 ( struct V_13 * V_13 ,
struct V_1 * V_2 )
{
struct V_7 * V_8 ;
F_16 ( ! F_17 () ) ;
F_13 ( V_2 -> V_26 ) ;
if ( F_18 ( F_19 ( V_2 ) ) )
return F_31 ( F_34 ( V_2 ) ? - V_30 : - V_44 ) ;
V_8 = F_10 ( V_13 , V_2 , true ) ;
if ( V_8 )
return V_8 ;
while ( true ) {
struct V_13 * V_45 = V_13 ;
struct V_13 * V_35 = F_22 ( V_13 ) ;
while ( V_35 && ! F_10 ( V_35 , V_2 , false ) ) {
V_45 = V_35 ;
V_35 = F_22 ( V_35 ) ;
}
V_8 = F_20 ( V_45 , V_2 , NULL ) ;
if ( V_45 == V_13 || F_35 ( V_8 ) )
return V_8 ;
}
}
static void F_36 ( struct V_7 * V_8 )
{
struct V_13 * V_13 = V_8 -> V_13 ;
int V_9 ;
F_13 ( V_8 -> V_2 -> V_26 ) ;
F_13 ( & V_13 -> V_37 ) ;
F_16 ( F_37 ( & V_8 -> V_16 ) ) ;
F_16 ( F_38 ( & V_8 -> V_38 ) ) ;
for ( V_9 = 0 ; V_9 < V_10 ; V_9 ++ ) {
struct V_3 * V_4 = V_3 [ V_9 ] ;
if ( V_8 -> V_11 [ V_9 ] && V_4 -> V_46 )
V_4 -> V_46 ( V_8 ) ;
}
V_8 -> V_41 = false ;
F_39 ( & V_13 -> V_24 , V_8 -> V_2 -> V_25 ) ;
F_40 ( & V_8 -> V_16 ) ;
F_41 ( & V_8 -> V_38 ) ;
if ( F_42 ( V_13 -> V_23 ) == V_8 )
F_14 ( V_13 -> V_23 , NULL ) ;
if ( V_13 == & V_18 ) {
V_8 -> V_2 -> V_42 = NULL ;
V_8 -> V_2 -> V_43 . V_8 = NULL ;
}
F_30 ( V_8 ) ;
}
static void F_43 ( struct V_1 * V_2 )
{
struct V_7 * V_8 , * V_47 ;
F_13 ( V_2 -> V_26 ) ;
F_44 (blkg, n, &q->blkg_list, q_node) {
struct V_13 * V_13 = V_8 -> V_13 ;
F_24 ( & V_13 -> V_37 ) ;
F_36 ( V_8 ) ;
F_29 ( & V_13 -> V_37 ) ;
}
}
void F_45 ( struct V_48 * V_48 )
{
struct V_7 * V_8 = F_46 ( V_48 , struct V_7 , V_48 ) ;
int V_9 ;
for ( V_9 = 0 ; V_9 < V_10 ; V_9 ++ ) {
struct V_3 * V_4 = V_3 [ V_9 ] ;
if ( V_8 -> V_11 [ V_9 ] && V_4 -> V_49 )
V_4 -> V_49 ( V_8 ) ;
}
F_32 ( & V_8 -> V_13 -> V_29 ) ;
if ( V_8 -> V_35 ) {
F_47 ( V_8 -> V_2 -> V_26 ) ;
F_30 ( V_8 -> V_35 ) ;
F_48 ( V_8 -> V_2 -> V_26 ) ;
}
F_3 ( V_8 ) ;
}
struct V_50 * F_49 ( struct V_50 * V_12 ,
struct V_1 * V_2 )
{
struct V_51 * V_52 ;
struct V_7 * V_8 ;
if ( V_12 == & V_2 -> V_43 ) {
V_52 = & V_2 -> V_39 ;
if ( F_37 ( V_52 ) )
return NULL ;
} else {
V_8 = F_46 ( V_12 , struct V_7 , V_12 ) ;
V_52 = & V_8 -> V_16 ;
}
V_52 = V_52 -> V_53 ;
if ( V_52 == & V_2 -> V_42 -> V_16 )
V_52 = V_52 -> V_53 ;
if ( V_52 == & V_2 -> V_39 )
return NULL ;
V_8 = F_46 ( V_52 , struct V_7 , V_16 ) ;
return & V_8 -> V_12 ;
}
static int F_50 ( struct V_54 * V_29 ,
struct V_55 * V_55 , T_2 V_56 )
{
struct V_13 * V_13 = F_51 ( V_29 ) ;
struct V_7 * V_8 ;
int V_9 ;
F_52 ( & V_57 ) ;
F_47 ( & V_13 -> V_37 ) ;
F_53 (blkg, &blkcg->blkg_list, blkcg_node) {
for ( V_9 = 0 ; V_9 < V_10 ; V_9 ++ ) {
struct V_3 * V_4 = V_3 [ V_9 ] ;
if ( F_1 ( V_8 -> V_2 , V_4 ) &&
V_4 -> V_58 )
V_4 -> V_58 ( V_8 ) ;
}
}
F_48 ( & V_13 -> V_37 ) ;
F_54 ( & V_57 ) ;
return 0 ;
}
static const char * F_55 ( struct V_7 * V_8 )
{
if ( V_8 -> V_2 -> V_59 . V_60 )
return F_56 ( V_8 -> V_2 -> V_59 . V_60 ) ;
return NULL ;
}
void F_57 ( struct V_61 * V_62 , struct V_13 * V_13 ,
T_2 (* F_58)( struct V_61 * ,
struct V_20 * , int ) ,
const struct V_3 * V_4 , int V_63 ,
bool V_64 )
{
struct V_7 * V_8 ;
T_2 V_65 = 0 ;
F_59 () ;
F_60 (blkg, &blkcg->blkg_list, blkcg_node) {
F_47 ( V_8 -> V_2 -> V_26 ) ;
if ( F_1 ( V_8 -> V_2 , V_4 ) )
V_65 += F_58 ( V_62 , V_8 -> V_11 [ V_4 -> V_5 ] , V_63 ) ;
F_48 ( V_8 -> V_2 -> V_26 ) ;
}
F_61 () ;
if ( V_64 )
F_62 ( V_62 , L_1 , ( unsigned long long ) V_65 ) ;
}
T_2 F_63 ( struct V_61 * V_62 , struct V_20 * V_11 , T_2 V_66 )
{
const char * V_67 = F_55 ( V_11 -> V_8 ) ;
if ( ! V_67 )
return 0 ;
F_62 ( V_62 , L_2 , V_67 , ( unsigned long long ) V_66 ) ;
return V_66 ;
}
T_2 F_64 ( struct V_61 * V_62 , struct V_20 * V_11 ,
const struct V_68 * V_69 )
{
static const char * V_70 [] = {
[ V_71 ] = L_3 ,
[ V_72 ] = L_4 ,
[ V_73 ] = L_5 ,
[ V_74 ] = L_6 ,
} ;
const char * V_67 = F_55 ( V_11 -> V_8 ) ;
T_2 V_66 ;
int V_9 ;
if ( ! V_67 )
return 0 ;
for ( V_9 = 0 ; V_9 < V_75 ; V_9 ++ )
F_62 ( V_62 , L_7 , V_67 , V_70 [ V_9 ] ,
( unsigned long long ) V_69 -> V_76 [ V_9 ] ) ;
V_66 = V_69 -> V_76 [ V_71 ] + V_69 -> V_76 [ V_72 ] ;
F_62 ( V_62 , L_8 , V_67 , ( unsigned long long ) V_66 ) ;
return V_66 ;
}
T_2 F_65 ( struct V_61 * V_62 , struct V_20 * V_11 , int V_77 )
{
return F_63 ( V_62 , V_11 , F_66 ( ( void * ) V_11 + V_77 ) ) ;
}
T_2 F_67 ( struct V_61 * V_62 , struct V_20 * V_11 ,
int V_77 )
{
struct V_68 V_69 = F_68 ( ( void * ) V_11 + V_77 ) ;
return F_64 ( V_62 , V_11 , & V_69 ) ;
}
T_2 F_69 ( struct V_20 * V_11 , int V_77 )
{
struct V_3 * V_4 = V_3 [ V_11 -> V_5 ] ;
struct V_7 * V_78 ;
struct V_54 * V_79 ;
T_2 V_80 = 0 ;
F_13 ( V_11 -> V_8 -> V_2 -> V_26 ) ;
F_59 () ;
F_70 (pos_blkg, pos_css, pd_to_blkg(pd)) {
struct V_20 * V_81 = F_71 ( V_78 , V_4 ) ;
struct V_82 * V_83 = ( void * ) V_81 + V_77 ;
if ( V_78 -> V_41 )
V_80 += F_66 ( V_83 ) ;
}
F_61 () ;
return V_80 ;
}
struct V_68 F_72 ( struct V_20 * V_11 ,
int V_77 )
{
struct V_3 * V_4 = V_3 [ V_11 -> V_5 ] ;
struct V_7 * V_78 ;
struct V_54 * V_79 ;
struct V_68 V_80 = { } ;
int V_9 ;
F_13 ( V_11 -> V_8 -> V_2 -> V_26 ) ;
F_59 () ;
F_70 (pos_blkg, pos_css, pd_to_blkg(pd)) {
struct V_20 * V_81 = F_71 ( V_78 , V_4 ) ;
struct V_68 * V_69 = ( void * ) V_81 + V_77 ;
struct V_68 V_84 ;
if ( ! V_78 -> V_41 )
continue;
V_84 = F_68 ( V_69 ) ;
for ( V_9 = 0 ; V_9 < V_75 ; V_9 ++ )
V_80 . V_76 [ V_9 ] += V_84 . V_76 [ V_9 ] ;
}
F_61 () ;
return V_80 ;
}
int F_73 ( struct V_13 * V_13 , const struct V_3 * V_4 ,
const char * V_85 , struct V_86 * V_87 )
__acquires( T_3 ) __acquires( V_88 -> V_89 -> V_26 )
{
struct V_90 * V_88 ;
struct V_7 * V_8 ;
unsigned int V_91 , V_92 ;
unsigned long long V_66 ;
int V_93 , V_28 ;
if ( sscanf ( V_85 , L_9 , & V_91 , & V_92 , & V_66 ) != 3 )
return - V_30 ;
V_88 = F_74 ( F_75 ( V_91 , V_92 ) , & V_93 ) ;
if ( ! V_88 || V_93 )
return - V_30 ;
F_59 () ;
F_47 ( V_88 -> V_89 -> V_26 ) ;
if ( F_1 ( V_88 -> V_89 , V_4 ) )
V_8 = F_33 ( V_13 , V_88 -> V_89 ) ;
else
V_8 = F_31 ( - V_30 ) ;
if ( F_35 ( V_8 ) ) {
V_28 = F_76 ( V_8 ) ;
F_61 () ;
F_48 ( V_88 -> V_89 -> V_26 ) ;
F_77 ( V_88 ) ;
if ( V_28 == - V_44 ) {
F_78 ( 10 ) ;
V_28 = F_79 () ;
}
return V_28 ;
}
V_87 -> V_88 = V_88 ;
V_87 -> V_8 = V_8 ;
V_87 -> V_66 = V_66 ;
return 0 ;
}
void F_80 ( struct V_86 * V_87 )
__releases( V_87 -> V_88 -> V_89 -> V_26 ) __releases( T_3 )
{
F_48 ( V_87 -> V_88 -> V_89 -> V_26 ) ;
F_61 () ;
F_77 ( V_87 -> V_88 ) ;
}
static void F_81 ( struct V_54 * V_29 )
{
struct V_13 * V_13 = F_51 ( V_29 ) ;
F_47 ( & V_13 -> V_37 ) ;
while ( ! F_82 ( & V_13 -> V_39 ) ) {
struct V_7 * V_8 = F_83 ( V_13 -> V_39 . V_94 ,
struct V_7 , V_38 ) ;
struct V_1 * V_2 = V_8 -> V_2 ;
if ( F_84 ( V_2 -> V_26 ) ) {
F_36 ( V_8 ) ;
F_29 ( V_2 -> V_26 ) ;
} else {
F_48 ( & V_13 -> V_37 ) ;
F_85 () ;
F_47 ( & V_13 -> V_37 ) ;
}
}
F_48 ( & V_13 -> V_37 ) ;
}
static void F_86 ( struct V_54 * V_29 )
{
struct V_13 * V_13 = F_51 ( V_29 ) ;
if ( V_13 != & V_18 )
F_4 ( V_13 ) ;
}
static struct V_54 *
F_87 ( struct V_54 * V_95 )
{
static T_4 V_96 = F_88 ( 0 ) ;
struct V_13 * V_13 ;
if ( ! V_95 ) {
V_13 = & V_18 ;
goto V_97;
}
V_13 = F_89 ( sizeof( * V_13 ) , V_98 ) ;
if ( ! V_13 )
return F_31 ( - V_33 ) ;
V_13 -> V_99 = V_100 ;
V_13 -> V_101 = V_100 ;
V_13 -> V_25 = F_90 ( & V_96 ) ;
V_97:
F_91 ( & V_13 -> V_37 ) ;
F_92 ( & V_13 -> V_24 , V_32 ) ;
F_93 ( & V_13 -> V_39 ) ;
return & V_13 -> V_29 ;
}
int F_94 ( struct V_1 * V_2 )
{
F_95 () ;
return F_96 ( V_2 ) ;
}
void F_97 ( struct V_1 * V_2 )
{
F_13 ( V_2 -> V_26 ) ;
F_98 ( V_2 ) ;
}
void F_99 ( struct V_1 * V_2 )
{
F_47 ( V_2 -> V_26 ) ;
F_43 ( V_2 ) ;
F_48 ( V_2 -> V_26 ) ;
F_100 ( V_2 ) ;
}
static int F_101 ( struct V_54 * V_29 ,
struct V_102 * V_103 )
{
struct V_104 * V_105 ;
struct V_106 * V_107 ;
int V_28 = 0 ;
F_102 (task, css, tset) {
F_103 ( V_105 ) ;
V_107 = V_105 -> V_106 ;
if ( V_107 && F_104 ( & V_107 -> V_108 ) > 1 )
V_28 = - V_30 ;
F_105 ( V_105 ) ;
if ( V_28 )
break;
}
return V_28 ;
}
int F_106 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
F_107 ( V_109 ) ;
struct V_7 * V_8 , * V_27 ;
struct V_20 * V_11 , * V_47 ;
int V_76 = 0 , V_28 ;
bool V_110 ;
if ( F_1 ( V_2 , V_4 ) )
return 0 ;
V_27 = F_6 ( & V_18 , V_2 , V_98 ) ;
if ( ! V_27 )
return - V_33 ;
F_108 ( V_2 ) ;
V_110 = ! F_109 ( V_98 ) ;
F_47 ( V_2 -> V_26 ) ;
F_59 () ;
V_8 = F_10 ( & V_18 , V_2 , false ) ;
if ( V_8 )
F_3 ( V_27 ) ;
else
V_8 = F_20 ( & V_18 , V_2 , V_27 ) ;
F_61 () ;
if ( V_110 )
F_110 () ;
if ( F_35 ( V_8 ) ) {
V_28 = F_76 ( V_8 ) ;
goto V_111;
}
F_111 (blkg, &q->blkg_list, q_node)
V_76 ++ ;
F_48 ( V_2 -> V_26 ) ;
while ( V_76 -- ) {
V_11 = F_7 ( V_4 -> V_21 , V_98 , V_2 -> V_15 ) ;
if ( ! V_11 ) {
V_28 = - V_33 ;
goto V_112;
}
F_112 ( & V_11 -> V_113 , & V_109 ) ;
}
F_47 ( V_2 -> V_26 ) ;
F_111 (blkg, &q->blkg_list, q_node) {
if ( F_113 ( F_37 ( & V_109 ) ) ) {
V_28 = - V_33 ;
goto V_111;
}
V_11 = F_114 ( & V_109 , struct V_20 , V_113 ) ;
F_40 ( & V_11 -> V_113 ) ;
F_24 ( & V_8 -> V_13 -> V_37 ) ;
V_8 -> V_11 [ V_4 -> V_5 ] = V_11 ;
V_11 -> V_8 = V_8 ;
V_11 -> V_5 = V_4 -> V_5 ;
V_4 -> V_36 ( V_8 ) ;
F_29 ( & V_8 -> V_13 -> V_37 ) ;
}
F_115 ( V_4 -> V_5 , V_2 -> V_6 ) ;
V_28 = 0 ;
V_111:
F_48 ( V_2 -> V_26 ) ;
V_112:
F_116 ( V_2 ) ;
F_44 (pd, n, &pds, alloc_node)
F_4 ( V_11 ) ;
return V_28 ;
}
void F_117 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
struct V_7 * V_8 ;
if ( ! F_1 ( V_2 , V_4 ) )
return;
F_108 ( V_2 ) ;
F_47 ( V_2 -> V_26 ) ;
F_118 ( V_4 -> V_5 , V_2 -> V_6 ) ;
if ( F_119 ( V_2 -> V_6 , V_10 ) )
F_43 ( V_2 ) ;
F_111 (blkg, &q->blkg_list, q_node) {
F_24 ( & V_8 -> V_13 -> V_37 ) ;
if ( V_4 -> V_46 )
V_4 -> V_46 ( V_8 ) ;
if ( V_4 -> V_49 )
V_4 -> V_49 ( V_8 ) ;
F_4 ( V_8 -> V_11 [ V_4 -> V_5 ] ) ;
V_8 -> V_11 [ V_4 -> V_5 ] = NULL ;
F_29 ( & V_8 -> V_13 -> V_37 ) ;
}
F_48 ( V_2 -> V_26 ) ;
F_116 ( V_2 ) ;
}
int F_120 ( struct V_3 * V_4 )
{
int V_9 , V_28 ;
if ( F_113 ( V_4 -> V_21 < sizeof( struct V_20 ) ) )
return - V_30 ;
F_52 ( & V_57 ) ;
V_28 = - V_114 ;
for ( V_9 = 0 ; V_9 < V_10 ; V_9 ++ )
if ( ! V_3 [ V_9 ] )
break;
if ( V_9 >= V_10 )
goto V_111;
V_4 -> V_5 = V_9 ;
V_3 [ V_9 ] = V_4 ;
if ( V_4 -> V_115 )
F_113 ( F_121 ( & V_116 , V_4 -> V_115 ) ) ;
V_28 = 0 ;
V_111:
F_54 ( & V_57 ) ;
return V_28 ;
}
void F_122 ( struct V_3 * V_4 )
{
F_52 ( & V_57 ) ;
if ( F_113 ( V_3 [ V_4 -> V_5 ] != V_4 ) )
goto V_111;
if ( V_4 -> V_115 )
F_123 ( V_4 -> V_115 ) ;
V_3 [ V_4 -> V_5 ] = NULL ;
V_111:
F_54 ( & V_57 ) ;
}
