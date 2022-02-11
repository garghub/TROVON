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
if ( V_8 -> V_11 [ V_9 ] )
V_3 [ V_9 ] -> F_4 ( V_8 -> V_11 [ V_9 ] ) ;
if ( V_8 -> V_12 != & V_13 )
F_5 ( & V_8 -> V_14 ) ;
F_6 ( & V_8 -> V_15 ) ;
F_6 ( & V_8 -> V_16 ) ;
F_7 ( V_8 ) ;
}
static struct V_7 * F_8 ( struct V_12 * V_12 , struct V_1 * V_2 ,
T_1 V_17 )
{
struct V_7 * V_8 ;
int V_9 ;
V_8 = F_9 ( sizeof( * V_8 ) , V_17 , V_2 -> V_18 ) ;
if ( ! V_8 )
return NULL ;
if ( F_10 ( & V_8 -> V_16 , V_17 ) ||
F_10 ( & V_8 -> V_15 , V_17 ) )
goto V_19;
V_8 -> V_2 = V_2 ;
F_11 ( & V_8 -> V_20 ) ;
V_8 -> V_12 = V_12 ;
F_12 ( & V_8 -> V_21 , 1 ) ;
if ( V_12 != & V_13 ) {
if ( F_13 ( & V_8 -> V_14 , V_2 , V_17 ) )
goto V_19;
V_8 -> V_14 . V_8 = V_8 ;
}
for ( V_9 = 0 ; V_9 < V_10 ; V_9 ++ ) {
struct V_3 * V_4 = V_3 [ V_9 ] ;
struct V_22 * V_11 ;
if ( ! F_1 ( V_2 , V_4 ) )
continue;
V_11 = V_4 -> V_23 ( V_17 , V_2 -> V_18 ) ;
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
struct V_7 * F_14 ( struct V_12 * V_12 ,
struct V_1 * V_2 , bool V_24 )
{
struct V_7 * V_8 ;
V_8 = F_15 ( & V_12 -> V_25 , V_2 -> V_26 ) ;
if ( V_8 && V_8 -> V_2 == V_2 ) {
if ( V_24 ) {
F_16 ( V_2 -> V_27 ) ;
F_17 ( V_12 -> V_28 , V_8 ) ;
}
return V_8 ;
}
return NULL ;
}
static struct V_7 * F_18 ( struct V_12 * V_12 ,
struct V_1 * V_2 ,
struct V_7 * V_29 )
{
struct V_7 * V_8 ;
struct V_30 * V_31 ;
int V_9 , V_32 ;
F_19 ( ! F_20 () ) ;
F_16 ( V_2 -> V_27 ) ;
if ( ! F_21 ( & V_12 -> V_33 ) ) {
V_32 = - V_34 ;
goto V_35;
}
V_31 = F_22 ( & V_2 -> V_36 ,
V_12 -> V_33 . V_26 , V_37 ) ;
if ( ! V_31 ) {
V_32 = - V_38 ;
goto V_39;
}
if ( ! V_29 ) {
V_29 = F_8 ( V_12 , V_2 , V_37 ) ;
if ( F_23 ( ! V_29 ) ) {
V_32 = - V_38 ;
goto V_40;
}
}
V_8 = V_29 ;
V_8 -> V_31 = V_31 ;
if ( F_24 ( V_12 ) ) {
V_8 -> V_41 = F_25 ( F_24 ( V_12 ) , V_2 , false ) ;
if ( F_19 ( ! V_8 -> V_41 ) ) {
V_32 = - V_34 ;
goto V_40;
}
F_26 ( V_8 -> V_41 ) ;
}
for ( V_9 = 0 ; V_9 < V_10 ; V_9 ++ ) {
struct V_3 * V_4 = V_3 [ V_9 ] ;
if ( V_8 -> V_11 [ V_9 ] && V_4 -> V_42 )
V_4 -> V_42 ( V_8 -> V_11 [ V_9 ] ) ;
}
F_27 ( & V_12 -> V_43 ) ;
V_32 = F_28 ( & V_12 -> V_25 , V_2 -> V_26 , V_8 ) ;
if ( F_29 ( ! V_32 ) ) {
F_30 ( & V_8 -> V_44 , & V_12 -> V_45 ) ;
F_31 ( & V_8 -> V_20 , & V_2 -> V_45 ) ;
for ( V_9 = 0 ; V_9 < V_10 ; V_9 ++ ) {
struct V_3 * V_4 = V_3 [ V_9 ] ;
if ( V_8 -> V_11 [ V_9 ] && V_4 -> V_46 )
V_4 -> V_46 ( V_8 -> V_11 [ V_9 ] ) ;
}
}
V_8 -> V_47 = true ;
F_32 ( & V_12 -> V_43 ) ;
if ( ! V_32 )
return V_8 ;
F_33 ( V_8 ) ;
return F_34 ( V_32 ) ;
V_40:
F_35 ( V_31 ) ;
V_39:
F_36 ( & V_12 -> V_33 ) ;
V_35:
F_3 ( V_29 ) ;
return F_34 ( V_32 ) ;
}
struct V_7 * F_37 ( struct V_12 * V_12 ,
struct V_1 * V_2 )
{
struct V_7 * V_8 ;
F_19 ( ! F_20 () ) ;
F_16 ( V_2 -> V_27 ) ;
if ( F_23 ( F_38 ( V_2 ) ) )
return F_34 ( F_39 ( V_2 ) ? - V_34 : - V_48 ) ;
V_8 = F_25 ( V_12 , V_2 , true ) ;
if ( V_8 )
return V_8 ;
while ( true ) {
struct V_12 * V_49 = V_12 ;
struct V_12 * V_41 = F_24 ( V_12 ) ;
while ( V_41 && ! F_25 ( V_41 , V_2 , false ) ) {
V_49 = V_41 ;
V_41 = F_24 ( V_41 ) ;
}
V_8 = F_18 ( V_49 , V_2 , NULL ) ;
if ( V_49 == V_12 || F_40 ( V_8 ) )
return V_8 ;
}
}
static void F_41 ( struct V_7 * V_8 )
{
struct V_12 * V_12 = V_8 -> V_12 ;
struct V_7 * V_41 = V_8 -> V_41 ;
int V_9 ;
F_16 ( V_8 -> V_2 -> V_27 ) ;
F_16 ( & V_12 -> V_43 ) ;
F_19 ( F_42 ( & V_8 -> V_20 ) ) ;
F_19 ( F_43 ( & V_8 -> V_44 ) ) ;
for ( V_9 = 0 ; V_9 < V_10 ; V_9 ++ ) {
struct V_3 * V_4 = V_3 [ V_9 ] ;
if ( V_8 -> V_11 [ V_9 ] && V_4 -> V_50 )
V_4 -> V_50 ( V_8 -> V_11 [ V_9 ] ) ;
}
if ( V_41 ) {
F_44 ( & V_41 -> V_16 , & V_8 -> V_16 ) ;
F_44 ( & V_41 -> V_15 , & V_8 -> V_15 ) ;
}
V_8 -> V_47 = false ;
F_45 ( & V_12 -> V_25 , V_8 -> V_2 -> V_26 ) ;
F_46 ( & V_8 -> V_20 ) ;
F_47 ( & V_8 -> V_44 ) ;
if ( F_48 ( V_12 -> V_28 ) == V_8 )
F_17 ( V_12 -> V_28 , NULL ) ;
F_33 ( V_8 ) ;
}
static void F_49 ( struct V_1 * V_2 )
{
struct V_7 * V_8 , * V_51 ;
F_16 ( V_2 -> V_27 ) ;
F_50 (blkg, n, &q->blkg_list, q_node) {
struct V_12 * V_12 = V_8 -> V_12 ;
F_27 ( & V_12 -> V_43 ) ;
F_41 ( V_8 ) ;
F_32 ( & V_12 -> V_43 ) ;
}
V_2 -> V_52 = NULL ;
V_2 -> V_53 . V_8 = NULL ;
}
void F_51 ( struct V_54 * V_54 )
{
struct V_7 * V_8 = F_52 ( V_54 , struct V_7 , V_54 ) ;
F_36 ( & V_8 -> V_12 -> V_33 ) ;
if ( V_8 -> V_41 )
F_33 ( V_8 -> V_41 ) ;
F_35 ( V_8 -> V_31 ) ;
F_3 ( V_8 ) ;
}
struct V_55 * F_53 ( struct V_55 * V_14 ,
struct V_1 * V_2 )
{
struct V_56 * V_57 ;
struct V_7 * V_8 ;
if ( V_14 == & V_2 -> V_53 ) {
V_57 = & V_2 -> V_45 ;
if ( F_42 ( V_57 ) )
return NULL ;
} else {
V_8 = F_52 ( V_14 , struct V_7 , V_14 ) ;
V_57 = & V_8 -> V_20 ;
}
V_57 = V_57 -> V_58 ;
if ( V_57 == & V_2 -> V_52 -> V_20 )
V_57 = V_57 -> V_58 ;
if ( V_57 == & V_2 -> V_45 )
return NULL ;
V_8 = F_52 ( V_57 , struct V_7 , V_20 ) ;
return & V_8 -> V_14 ;
}
static int F_54 ( struct V_59 * V_33 ,
struct V_60 * V_60 , T_2 V_61 )
{
struct V_12 * V_12 = F_55 ( V_33 ) ;
struct V_7 * V_8 ;
int V_9 ;
F_56 ( & V_62 ) ;
F_57 ( & V_12 -> V_43 ) ;
F_58 (blkg, &blkcg->blkg_list, blkcg_node) {
F_59 ( & V_8 -> V_16 ) ;
F_59 ( & V_8 -> V_15 ) ;
for ( V_9 = 0 ; V_9 < V_10 ; V_9 ++ ) {
struct V_3 * V_4 = V_3 [ V_9 ] ;
if ( V_8 -> V_11 [ V_9 ] && V_4 -> V_63 )
V_4 -> V_63 ( V_8 -> V_11 [ V_9 ] ) ;
}
}
F_60 ( & V_12 -> V_43 ) ;
F_61 ( & V_62 ) ;
return 0 ;
}
const char * F_62 ( struct V_7 * V_8 )
{
if ( V_8 -> V_2 -> V_36 . V_64 )
return F_63 ( V_8 -> V_2 -> V_36 . V_64 ) ;
return NULL ;
}
void F_64 ( struct V_65 * V_66 , struct V_12 * V_12 ,
T_2 (* F_65)( struct V_65 * ,
struct V_22 * , int ) ,
const struct V_3 * V_4 , int V_67 ,
bool V_68 )
{
struct V_7 * V_8 ;
T_2 V_69 = 0 ;
F_66 () ;
F_67 (blkg, &blkcg->blkg_list, blkcg_node) {
F_57 ( V_8 -> V_2 -> V_27 ) ;
if ( F_1 ( V_8 -> V_2 , V_4 ) )
V_69 += F_65 ( V_66 , V_8 -> V_11 [ V_4 -> V_5 ] , V_67 ) ;
F_60 ( V_8 -> V_2 -> V_27 ) ;
}
F_68 () ;
if ( V_68 )
F_69 ( V_66 , L_1 , ( unsigned long long ) V_69 ) ;
}
T_2 F_70 ( struct V_65 * V_66 , struct V_22 * V_11 , T_2 V_70 )
{
const char * V_71 = F_62 ( V_11 -> V_8 ) ;
if ( ! V_71 )
return 0 ;
F_69 ( V_66 , L_2 , V_71 , ( unsigned long long ) V_70 ) ;
return V_70 ;
}
T_2 F_71 ( struct V_65 * V_66 , struct V_22 * V_11 ,
const struct V_72 * V_73 )
{
static const char * V_74 [] = {
[ V_75 ] = L_3 ,
[ V_76 ] = L_4 ,
[ V_77 ] = L_5 ,
[ V_78 ] = L_6 ,
} ;
const char * V_71 = F_62 ( V_11 -> V_8 ) ;
T_2 V_70 ;
int V_9 ;
if ( ! V_71 )
return 0 ;
for ( V_9 = 0 ; V_9 < V_79 ; V_9 ++ )
F_69 ( V_66 , L_7 , V_71 , V_74 [ V_9 ] ,
( unsigned long long ) F_72 ( & V_73 -> V_80 [ V_9 ] ) ) ;
V_70 = F_72 ( & V_73 -> V_80 [ V_75 ] ) +
F_72 ( & V_73 -> V_80 [ V_76 ] ) ;
F_69 ( V_66 , L_8 , V_71 , ( unsigned long long ) V_70 ) ;
return V_70 ;
}
T_2 F_73 ( struct V_65 * V_66 , struct V_22 * V_11 , int V_81 )
{
return F_70 ( V_66 , V_11 , F_74 ( ( void * ) V_11 + V_81 ) ) ;
}
T_2 F_75 ( struct V_65 * V_66 , struct V_22 * V_11 ,
int V_81 )
{
struct V_72 V_73 = F_76 ( ( void * ) V_11 + V_81 ) ;
return F_71 ( V_66 , V_11 , & V_73 ) ;
}
static T_2 F_77 ( struct V_65 * V_66 ,
struct V_22 * V_11 , int V_81 )
{
struct V_72 V_73 = F_76 ( ( void * ) V_11 -> V_8 + V_81 ) ;
return F_71 ( V_66 , V_11 , & V_73 ) ;
}
int F_78 ( struct V_65 * V_66 , void * V_70 )
{
F_64 ( V_66 , F_55 ( F_79 ( V_66 ) ) ,
F_77 , ( void * ) F_80 ( V_66 ) -> V_82 ,
F_81 ( struct V_7 , V_16 ) , true ) ;
return 0 ;
}
int F_82 ( struct V_65 * V_66 , void * V_70 )
{
F_64 ( V_66 , F_55 ( F_79 ( V_66 ) ) ,
F_77 , ( void * ) F_80 ( V_66 ) -> V_82 ,
F_81 ( struct V_7 , V_15 ) , true ) ;
return 0 ;
}
static T_2 F_83 ( struct V_65 * V_66 ,
struct V_22 * V_11 ,
int V_81 )
{
struct V_72 V_73 = F_84 ( V_11 -> V_8 ,
NULL , V_81 ) ;
return F_71 ( V_66 , V_11 , & V_73 ) ;
}
int F_85 ( struct V_65 * V_66 , void * V_70 )
{
F_64 ( V_66 , F_55 ( F_79 ( V_66 ) ) ,
F_83 ,
( void * ) F_80 ( V_66 ) -> V_82 ,
F_81 ( struct V_7 , V_16 ) , true ) ;
return 0 ;
}
int F_86 ( struct V_65 * V_66 , void * V_70 )
{
F_64 ( V_66 , F_55 ( F_79 ( V_66 ) ) ,
F_83 ,
( void * ) F_80 ( V_66 ) -> V_82 ,
F_81 ( struct V_7 , V_15 ) , true ) ;
return 0 ;
}
T_2 F_87 ( struct V_7 * V_8 ,
struct V_3 * V_4 , int V_81 )
{
struct V_7 * V_83 ;
struct V_59 * V_84 ;
T_2 V_85 = 0 ;
F_16 ( V_8 -> V_2 -> V_27 ) ;
F_66 () ;
F_88 (pos_blkg, pos_css, blkg) {
struct V_86 * V_87 ;
if ( ! V_83 -> V_47 )
continue;
if ( V_4 )
V_87 = ( void * ) F_89 ( V_83 , V_4 ) + V_81 ;
else
V_87 = ( void * ) V_8 + V_81 ;
V_85 += F_74 ( V_87 ) + F_72 ( & V_87 -> V_80 ) ;
}
F_68 () ;
return V_85 ;
}
struct V_72 F_84 ( struct V_7 * V_8 ,
struct V_3 * V_4 , int V_81 )
{
struct V_7 * V_83 ;
struct V_59 * V_84 ;
struct V_72 V_85 = { } ;
int V_9 ;
F_16 ( V_8 -> V_2 -> V_27 ) ;
F_66 () ;
F_88 (pos_blkg, pos_css, blkg) {
struct V_72 * V_73 ;
if ( ! V_83 -> V_47 )
continue;
if ( V_4 )
V_73 = ( void * ) F_89 ( V_83 , V_4 ) + V_81 ;
else
V_73 = ( void * ) V_83 + V_81 ;
for ( V_9 = 0 ; V_9 < V_79 ; V_9 ++ )
F_90 ( F_72 ( & V_73 -> V_80 [ V_9 ] ) +
F_91 ( & V_73 -> V_88 [ V_9 ] ) ,
& V_85 . V_80 [ V_9 ] ) ;
}
F_68 () ;
return V_85 ;
}
int F_92 ( struct V_12 * V_12 , const struct V_3 * V_4 ,
char * V_89 , struct V_90 * V_91 )
__acquires( T_3 ) __acquires( V_92 -> V_93 -> V_27 )
{
struct V_94 * V_92 ;
struct V_7 * V_8 ;
unsigned int V_95 , V_96 ;
int V_97 , V_98 , V_32 ;
char * V_99 ;
if ( sscanf ( V_89 , L_9 , & V_95 , & V_96 , & V_97 ) != 2 )
return - V_100 ;
V_99 = V_89 + V_97 ;
if ( ! isspace ( * V_99 ) )
return - V_100 ;
V_99 = F_93 ( V_99 ) ;
V_92 = F_94 ( F_95 ( V_95 , V_96 ) , & V_98 ) ;
if ( ! V_92 )
return - V_34 ;
if ( V_98 ) {
F_96 ( V_92 ) ;
return - V_34 ;
}
F_66 () ;
F_57 ( V_92 -> V_93 -> V_27 ) ;
if ( F_1 ( V_92 -> V_93 , V_4 ) )
V_8 = F_37 ( V_12 , V_92 -> V_93 ) ;
else
V_8 = F_34 ( - V_101 ) ;
if ( F_40 ( V_8 ) ) {
V_32 = F_97 ( V_8 ) ;
F_68 () ;
F_60 ( V_92 -> V_93 -> V_27 ) ;
F_96 ( V_92 ) ;
if ( V_32 == - V_48 ) {
F_98 ( 10 ) ;
V_32 = F_99 () ;
}
return V_32 ;
}
V_91 -> V_92 = V_92 ;
V_91 -> V_8 = V_8 ;
V_91 -> V_99 = V_99 ;
return 0 ;
}
void F_100 ( struct V_90 * V_91 )
__releases( V_91 -> V_92 -> V_93 -> V_27 ) __releases( T_3 )
{
F_60 ( V_91 -> V_92 -> V_93 -> V_27 ) ;
F_68 () ;
F_96 ( V_91 -> V_92 ) ;
}
static int F_101 ( struct V_65 * V_66 , void * V_70 )
{
struct V_12 * V_12 = F_55 ( F_79 ( V_66 ) ) ;
struct V_7 * V_8 ;
F_66 () ;
F_67 (blkg, &blkcg->blkg_list, blkcg_node) {
const char * V_71 ;
struct V_72 V_73 ;
T_2 V_102 , V_103 , V_104 , V_105 ;
V_71 = F_62 ( V_8 ) ;
if ( ! V_71 )
continue;
F_57 ( V_8 -> V_2 -> V_27 ) ;
V_73 = F_84 ( V_8 , NULL ,
F_81 ( struct V_7 , V_16 ) ) ;
V_102 = F_72 ( & V_73 . V_80 [ V_75 ] ) ;
V_103 = F_72 ( & V_73 . V_80 [ V_76 ] ) ;
V_73 = F_84 ( V_8 , NULL ,
F_81 ( struct V_7 , V_15 ) ) ;
V_104 = F_72 ( & V_73 . V_80 [ V_75 ] ) ;
V_105 = F_72 ( & V_73 . V_80 [ V_76 ] ) ;
F_60 ( V_8 -> V_2 -> V_27 ) ;
if ( V_102 || V_103 || V_104 || V_105 )
F_69 ( V_66 , L_10 ,
V_71 , V_102 , V_103 , V_104 , V_105 ) ;
}
F_68 () ;
return 0 ;
}
static void F_102 ( struct V_59 * V_33 )
{
struct V_12 * V_12 = F_55 ( V_33 ) ;
F_57 ( & V_12 -> V_43 ) ;
while ( ! F_103 ( & V_12 -> V_45 ) ) {
struct V_7 * V_8 = F_104 ( V_12 -> V_45 . V_106 ,
struct V_7 , V_44 ) ;
struct V_1 * V_2 = V_8 -> V_2 ;
if ( F_105 ( V_2 -> V_27 ) ) {
F_41 ( V_8 ) ;
F_32 ( V_2 -> V_27 ) ;
} else {
F_60 ( & V_12 -> V_43 ) ;
F_106 () ;
F_57 ( & V_12 -> V_43 ) ;
}
}
F_60 ( & V_12 -> V_43 ) ;
F_107 ( V_12 ) ;
}
static void F_108 ( struct V_59 * V_33 )
{
struct V_12 * V_12 = F_55 ( V_33 ) ;
int V_9 ;
F_56 ( & V_62 ) ;
F_109 ( & V_12 -> V_107 ) ;
for ( V_9 = 0 ; V_9 < V_10 ; V_9 ++ )
if ( V_12 -> V_108 [ V_9 ] )
V_3 [ V_9 ] -> F_110 ( V_12 -> V_108 [ V_9 ] ) ;
F_61 ( & V_62 ) ;
F_7 ( V_12 ) ;
}
static struct V_59 *
F_111 ( struct V_59 * V_109 )
{
struct V_12 * V_12 ;
struct V_59 * V_32 ;
int V_9 ;
F_56 ( & V_62 ) ;
if ( ! V_109 ) {
V_12 = & V_13 ;
} else {
V_12 = F_112 ( sizeof( * V_12 ) , V_110 ) ;
if ( ! V_12 ) {
V_32 = F_34 ( - V_38 ) ;
goto V_111;
}
}
for ( V_9 = 0 ; V_9 < V_10 ; V_9 ++ ) {
struct V_3 * V_4 = V_3 [ V_9 ] ;
struct V_112 * V_108 ;
if ( ! V_4 || ! V_4 -> V_113 )
continue;
V_108 = V_4 -> V_113 ( V_110 ) ;
if ( ! V_108 ) {
V_32 = F_34 ( - V_38 ) ;
goto V_114;
}
V_12 -> V_108 [ V_9 ] = V_108 ;
V_108 -> V_12 = V_12 ;
V_108 -> V_5 = V_9 ;
if ( V_4 -> V_115 )
V_4 -> V_115 ( V_108 ) ;
}
F_113 ( & V_12 -> V_43 ) ;
F_114 ( & V_12 -> V_25 , V_37 ) ;
F_115 ( & V_12 -> V_45 ) ;
#ifdef F_116
F_11 ( & V_12 -> V_116 ) ;
#endif
F_117 ( & V_12 -> V_107 , & V_117 ) ;
F_61 ( & V_62 ) ;
return & V_12 -> V_33 ;
V_114:
for ( V_9 -- ; V_9 >= 0 ; V_9 -- )
if ( V_12 -> V_108 [ V_9 ] )
V_3 [ V_9 ] -> F_110 ( V_12 -> V_108 [ V_9 ] ) ;
V_111:
F_7 ( V_12 ) ;
F_61 ( & V_62 ) ;
return V_32 ;
}
int F_118 ( struct V_1 * V_2 )
{
struct V_7 * V_29 , * V_8 ;
bool V_118 ;
int V_32 ;
V_29 = F_8 ( & V_13 , V_2 , V_110 ) ;
if ( ! V_29 )
return - V_38 ;
V_118 = ! F_119 ( V_110 ) ;
F_66 () ;
F_57 ( V_2 -> V_27 ) ;
V_8 = F_18 ( & V_13 , V_2 , V_29 ) ;
F_60 ( V_2 -> V_27 ) ;
F_68 () ;
if ( V_118 )
F_120 () ;
if ( F_40 ( V_8 ) ) {
F_3 ( V_29 ) ;
return F_97 ( V_8 ) ;
}
V_2 -> V_52 = V_8 ;
V_2 -> V_53 . V_8 = V_8 ;
V_32 = F_121 ( V_2 ) ;
if ( V_32 ) {
F_57 ( V_2 -> V_27 ) ;
F_49 ( V_2 ) ;
F_60 ( V_2 -> V_27 ) ;
}
return V_32 ;
}
void F_122 ( struct V_1 * V_2 )
{
F_16 ( V_2 -> V_27 ) ;
if ( ! V_2 -> V_52 )
return;
F_123 ( V_2 ) ;
}
void F_124 ( struct V_1 * V_2 )
{
F_57 ( V_2 -> V_27 ) ;
F_49 ( V_2 ) ;
F_60 ( V_2 -> V_27 ) ;
F_125 ( V_2 ) ;
}
static int F_126 ( struct V_119 * V_120 )
{
struct V_121 * V_122 ;
struct V_59 * V_123 ;
struct V_124 * V_125 ;
int V_32 = 0 ;
F_127 (task, dst_css, tset) {
F_128 ( V_122 ) ;
V_125 = V_122 -> V_124 ;
if ( V_125 && F_129 ( & V_125 -> V_126 ) > 1 )
V_32 = - V_100 ;
F_130 ( V_122 ) ;
if ( V_32 )
break;
}
return V_32 ;
}
static void F_131 ( struct V_59 * V_127 )
{
int V_9 ;
F_56 ( & V_62 ) ;
for ( V_9 = 0 ; V_9 < V_10 ; V_9 ++ ) {
struct V_3 * V_4 = V_3 [ V_9 ] ;
struct V_12 * V_12 ;
if ( ! V_4 || ! V_4 -> V_128 )
continue;
F_132 (blkcg, &all_blkcgs, all_blkcgs_node)
if ( V_12 -> V_108 [ V_4 -> V_5 ] )
V_4 -> V_128 ( V_12 -> V_108 [ V_4 -> V_5 ] ) ;
}
F_61 ( & V_62 ) ;
}
int F_133 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
struct V_22 * V_129 = NULL ;
struct V_7 * V_8 ;
int V_32 ;
if ( F_1 ( V_2 , V_4 ) )
return 0 ;
F_134 ( V_2 ) ;
V_129:
if ( ! V_129 ) {
V_129 = V_4 -> V_23 ( V_110 , V_2 -> V_18 ) ;
if ( ! V_129 ) {
V_32 = - V_38 ;
goto V_130;
}
}
F_57 ( V_2 -> V_27 ) ;
F_132 (blkg, &q->blkg_list, q_node) {
struct V_22 * V_11 ;
if ( V_8 -> V_11 [ V_4 -> V_5 ] )
continue;
V_11 = V_4 -> V_23 ( V_37 , V_2 -> V_18 ) ;
if ( ! V_11 )
F_135 ( V_11 , V_129 ) ;
if ( ! V_11 ) {
F_60 ( V_2 -> V_27 ) ;
goto V_129;
}
V_8 -> V_11 [ V_4 -> V_5 ] = V_11 ;
V_11 -> V_8 = V_8 ;
V_11 -> V_5 = V_4 -> V_5 ;
if ( V_4 -> V_42 )
V_4 -> V_42 ( V_11 ) ;
}
F_136 ( V_4 -> V_5 , V_2 -> V_6 ) ;
V_32 = 0 ;
F_60 ( V_2 -> V_27 ) ;
V_130:
F_137 ( V_2 ) ;
if ( V_129 )
V_4 -> F_4 ( V_129 ) ;
return V_32 ;
}
void F_138 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
struct V_7 * V_8 ;
if ( ! F_1 ( V_2 , V_4 ) )
return;
F_134 ( V_2 ) ;
F_57 ( V_2 -> V_27 ) ;
F_139 ( V_4 -> V_5 , V_2 -> V_6 ) ;
F_132 (blkg, &q->blkg_list, q_node) {
F_27 ( & V_8 -> V_12 -> V_43 ) ;
if ( V_8 -> V_11 [ V_4 -> V_5 ] ) {
if ( V_4 -> V_50 )
V_4 -> V_50 ( V_8 -> V_11 [ V_4 -> V_5 ] ) ;
V_4 -> F_4 ( V_8 -> V_11 [ V_4 -> V_5 ] ) ;
V_8 -> V_11 [ V_4 -> V_5 ] = NULL ;
}
F_32 ( & V_8 -> V_12 -> V_43 ) ;
}
F_60 ( V_2 -> V_27 ) ;
F_137 ( V_2 ) ;
}
int F_140 ( struct V_3 * V_4 )
{
struct V_12 * V_12 ;
int V_9 , V_32 ;
F_56 ( & V_131 ) ;
F_56 ( & V_62 ) ;
V_32 = - V_132 ;
for ( V_9 = 0 ; V_9 < V_10 ; V_9 ++ )
if ( ! V_3 [ V_9 ] )
break;
if ( V_9 >= V_10 )
goto V_133;
V_4 -> V_5 = V_9 ;
V_3 [ V_4 -> V_5 ] = V_4 ;
if ( V_4 -> V_113 ) {
F_132 (blkcg, &all_blkcgs, all_blkcgs_node) {
struct V_112 * V_108 ;
V_108 = V_4 -> V_113 ( V_110 ) ;
if ( ! V_108 ) {
F_61 ( & V_62 ) ;
goto V_134;
}
V_12 -> V_108 [ V_4 -> V_5 ] = V_108 ;
V_108 -> V_12 = V_12 ;
V_108 -> V_5 = V_4 -> V_5 ;
V_4 -> V_115 ( V_108 ) ;
}
}
F_61 ( & V_62 ) ;
if ( V_4 -> V_135 )
F_141 ( F_142 ( & V_136 ,
V_4 -> V_135 ) ) ;
if ( V_4 -> V_137 )
F_141 ( F_143 ( & V_136 ,
V_4 -> V_137 ) ) ;
F_61 ( & V_131 ) ;
return 0 ;
V_134:
if ( V_4 -> V_113 ) {
F_132 (blkcg, &all_blkcgs, all_blkcgs_node) {
if ( V_12 -> V_108 [ V_4 -> V_5 ] ) {
V_4 -> F_110 ( V_12 -> V_108 [ V_4 -> V_5 ] ) ;
V_12 -> V_108 [ V_4 -> V_5 ] = NULL ;
}
}
}
V_3 [ V_4 -> V_5 ] = NULL ;
V_133:
F_61 ( & V_62 ) ;
F_61 ( & V_131 ) ;
return V_32 ;
}
void F_144 ( struct V_3 * V_4 )
{
struct V_12 * V_12 ;
F_56 ( & V_131 ) ;
if ( F_141 ( V_3 [ V_4 -> V_5 ] != V_4 ) )
goto V_138;
if ( V_4 -> V_135 )
F_145 ( V_4 -> V_135 ) ;
if ( V_4 -> V_137 )
F_145 ( V_4 -> V_137 ) ;
F_56 ( & V_62 ) ;
if ( V_4 -> V_113 ) {
F_132 (blkcg, &all_blkcgs, all_blkcgs_node) {
if ( V_12 -> V_108 [ V_4 -> V_5 ] ) {
V_4 -> F_110 ( V_12 -> V_108 [ V_4 -> V_5 ] ) ;
V_12 -> V_108 [ V_4 -> V_5 ] = NULL ;
}
}
}
V_3 [ V_4 -> V_5 ] = NULL ;
F_61 ( & V_62 ) ;
V_138:
F_61 ( & V_131 ) ;
}
