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
F_5 ( V_8 -> V_2 , & V_8 -> V_14 ) ;
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
V_31 = F_22 ( V_2 -> V_36 ,
V_12 -> V_33 . V_26 ,
V_37 | V_38 ) ;
if ( ! V_31 ) {
V_32 = - V_39 ;
goto V_40;
}
if ( ! V_29 ) {
V_29 = F_8 ( V_12 , V_2 , V_37 | V_38 ) ;
if ( F_23 ( ! V_29 ) ) {
V_32 = - V_39 ;
goto V_41;
}
}
V_8 = V_29 ;
V_8 -> V_31 = V_31 ;
if ( F_24 ( V_12 ) ) {
V_8 -> V_42 = F_25 ( F_24 ( V_12 ) , V_2 , false ) ;
if ( F_19 ( ! V_8 -> V_42 ) ) {
V_32 = - V_34 ;
goto V_41;
}
F_26 ( V_8 -> V_42 ) ;
}
for ( V_9 = 0 ; V_9 < V_10 ; V_9 ++ ) {
struct V_3 * V_4 = V_3 [ V_9 ] ;
if ( V_8 -> V_11 [ V_9 ] && V_4 -> V_43 )
V_4 -> V_43 ( V_8 -> V_11 [ V_9 ] ) ;
}
F_27 ( & V_12 -> V_44 ) ;
V_32 = F_28 ( & V_12 -> V_25 , V_2 -> V_26 , V_8 ) ;
if ( F_29 ( ! V_32 ) ) {
F_30 ( & V_8 -> V_45 , & V_12 -> V_46 ) ;
F_31 ( & V_8 -> V_20 , & V_2 -> V_46 ) ;
for ( V_9 = 0 ; V_9 < V_10 ; V_9 ++ ) {
struct V_3 * V_4 = V_3 [ V_9 ] ;
if ( V_8 -> V_11 [ V_9 ] && V_4 -> V_47 )
V_4 -> V_47 ( V_8 -> V_11 [ V_9 ] ) ;
}
}
V_8 -> V_48 = true ;
F_32 ( & V_12 -> V_44 ) ;
if ( ! V_32 )
return V_8 ;
F_33 ( V_8 ) ;
return F_34 ( V_32 ) ;
V_41:
F_35 ( V_31 ) ;
V_40:
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
return F_34 ( F_39 ( V_2 ) ? - V_34 : - V_49 ) ;
V_8 = F_25 ( V_12 , V_2 , true ) ;
if ( V_8 )
return V_8 ;
while ( true ) {
struct V_12 * V_50 = V_12 ;
struct V_12 * V_42 = F_24 ( V_12 ) ;
while ( V_42 && ! F_25 ( V_42 , V_2 , false ) ) {
V_50 = V_42 ;
V_42 = F_24 ( V_42 ) ;
}
V_8 = F_18 ( V_50 , V_2 , NULL ) ;
if ( V_50 == V_12 || F_40 ( V_8 ) )
return V_8 ;
}
}
static void F_41 ( struct V_7 * V_8 )
{
struct V_12 * V_12 = V_8 -> V_12 ;
struct V_7 * V_42 = V_8 -> V_42 ;
int V_9 ;
F_16 ( V_8 -> V_2 -> V_27 ) ;
F_16 ( & V_12 -> V_44 ) ;
F_19 ( F_42 ( & V_8 -> V_20 ) ) ;
F_19 ( F_43 ( & V_8 -> V_45 ) ) ;
for ( V_9 = 0 ; V_9 < V_10 ; V_9 ++ ) {
struct V_3 * V_4 = V_3 [ V_9 ] ;
if ( V_8 -> V_11 [ V_9 ] && V_4 -> V_51 )
V_4 -> V_51 ( V_8 -> V_11 [ V_9 ] ) ;
}
if ( V_42 ) {
F_44 ( & V_42 -> V_16 , & V_8 -> V_16 ) ;
F_44 ( & V_42 -> V_15 , & V_8 -> V_15 ) ;
}
V_8 -> V_48 = false ;
F_45 ( & V_12 -> V_25 , V_8 -> V_2 -> V_26 ) ;
F_46 ( & V_8 -> V_20 ) ;
F_47 ( & V_8 -> V_45 ) ;
if ( F_48 ( V_12 -> V_28 ) == V_8 )
F_17 ( V_12 -> V_28 , NULL ) ;
F_33 ( V_8 ) ;
}
static void F_49 ( struct V_1 * V_2 )
{
struct V_7 * V_8 , * V_52 ;
F_16 ( V_2 -> V_27 ) ;
F_50 (blkg, n, &q->blkg_list, q_node) {
struct V_12 * V_12 = V_8 -> V_12 ;
F_27 ( & V_12 -> V_44 ) ;
F_41 ( V_8 ) ;
F_32 ( & V_12 -> V_44 ) ;
}
V_2 -> V_53 = NULL ;
V_2 -> V_54 . V_8 = NULL ;
}
void F_51 ( struct V_55 * V_55 )
{
struct V_7 * V_8 = F_52 ( V_55 , struct V_7 , V_55 ) ;
F_36 ( & V_8 -> V_12 -> V_33 ) ;
if ( V_8 -> V_42 )
F_33 ( V_8 -> V_42 ) ;
F_35 ( V_8 -> V_31 ) ;
F_3 ( V_8 ) ;
}
struct V_56 * F_53 ( struct V_56 * V_14 ,
struct V_1 * V_2 )
{
struct V_57 * V_58 ;
struct V_7 * V_8 ;
if ( V_14 == & V_2 -> V_54 ) {
V_58 = & V_2 -> V_46 ;
if ( F_42 ( V_58 ) )
return NULL ;
} else {
V_8 = F_52 ( V_14 , struct V_7 , V_14 ) ;
V_58 = & V_8 -> V_20 ;
}
V_58 = V_58 -> V_59 ;
if ( V_58 == & V_2 -> V_53 -> V_20 )
V_58 = V_58 -> V_59 ;
if ( V_58 == & V_2 -> V_46 )
return NULL ;
V_8 = F_52 ( V_58 , struct V_7 , V_20 ) ;
return & V_8 -> V_14 ;
}
static int F_54 ( struct V_60 * V_33 ,
struct V_61 * V_61 , T_2 V_62 )
{
struct V_12 * V_12 = F_55 ( V_33 ) ;
struct V_7 * V_8 ;
int V_9 ;
F_56 ( & V_63 ) ;
F_57 ( & V_12 -> V_44 ) ;
F_58 (blkg, &blkcg->blkg_list, blkcg_node) {
F_59 ( & V_8 -> V_16 ) ;
F_59 ( & V_8 -> V_15 ) ;
for ( V_9 = 0 ; V_9 < V_10 ; V_9 ++ ) {
struct V_3 * V_4 = V_3 [ V_9 ] ;
if ( V_8 -> V_11 [ V_9 ] && V_4 -> V_64 )
V_4 -> V_64 ( V_8 -> V_11 [ V_9 ] ) ;
}
}
F_60 ( & V_12 -> V_44 ) ;
F_61 ( & V_63 ) ;
return 0 ;
}
const char * F_62 ( struct V_7 * V_8 )
{
if ( V_8 -> V_2 -> V_36 -> V_65 )
return F_63 ( V_8 -> V_2 -> V_36 -> V_65 ) ;
return NULL ;
}
void F_64 ( struct V_66 * V_67 , struct V_12 * V_12 ,
T_2 (* F_65)( struct V_66 * ,
struct V_22 * , int ) ,
const struct V_3 * V_4 , int V_68 ,
bool V_69 )
{
struct V_7 * V_8 ;
T_2 V_70 = 0 ;
F_66 () ;
F_67 (blkg, &blkcg->blkg_list, blkcg_node) {
F_57 ( V_8 -> V_2 -> V_27 ) ;
if ( F_1 ( V_8 -> V_2 , V_4 ) )
V_70 += F_65 ( V_67 , V_8 -> V_11 [ V_4 -> V_5 ] , V_68 ) ;
F_60 ( V_8 -> V_2 -> V_27 ) ;
}
F_68 () ;
if ( V_69 )
F_69 ( V_67 , L_1 , ( unsigned long long ) V_70 ) ;
}
T_2 F_70 ( struct V_66 * V_67 , struct V_22 * V_11 , T_2 V_71 )
{
const char * V_72 = F_62 ( V_11 -> V_8 ) ;
if ( ! V_72 )
return 0 ;
F_69 ( V_67 , L_2 , V_72 , ( unsigned long long ) V_71 ) ;
return V_71 ;
}
T_2 F_71 ( struct V_66 * V_67 , struct V_22 * V_11 ,
const struct V_73 * V_74 )
{
static const char * V_75 [] = {
[ V_76 ] = L_3 ,
[ V_77 ] = L_4 ,
[ V_78 ] = L_5 ,
[ V_79 ] = L_6 ,
} ;
const char * V_72 = F_62 ( V_11 -> V_8 ) ;
T_2 V_71 ;
int V_9 ;
if ( ! V_72 )
return 0 ;
for ( V_9 = 0 ; V_9 < V_80 ; V_9 ++ )
F_69 ( V_67 , L_7 , V_72 , V_75 [ V_9 ] ,
( unsigned long long ) F_72 ( & V_74 -> V_81 [ V_9 ] ) ) ;
V_71 = F_72 ( & V_74 -> V_81 [ V_76 ] ) +
F_72 ( & V_74 -> V_81 [ V_77 ] ) ;
F_69 ( V_67 , L_8 , V_72 , ( unsigned long long ) V_71 ) ;
return V_71 ;
}
T_2 F_73 ( struct V_66 * V_67 , struct V_22 * V_11 , int V_82 )
{
return F_70 ( V_67 , V_11 , F_74 ( ( void * ) V_11 + V_82 ) ) ;
}
T_2 F_75 ( struct V_66 * V_67 , struct V_22 * V_11 ,
int V_82 )
{
struct V_73 V_74 = F_76 ( ( void * ) V_11 + V_82 ) ;
return F_71 ( V_67 , V_11 , & V_74 ) ;
}
static T_2 F_77 ( struct V_66 * V_67 ,
struct V_22 * V_11 , int V_82 )
{
struct V_73 V_74 = F_76 ( ( void * ) V_11 -> V_8 + V_82 ) ;
return F_71 ( V_67 , V_11 , & V_74 ) ;
}
int F_78 ( struct V_66 * V_67 , void * V_71 )
{
F_64 ( V_67 , F_55 ( F_79 ( V_67 ) ) ,
F_77 , ( void * ) F_80 ( V_67 ) -> V_83 ,
F_81 ( struct V_7 , V_16 ) , true ) ;
return 0 ;
}
int F_82 ( struct V_66 * V_67 , void * V_71 )
{
F_64 ( V_67 , F_55 ( F_79 ( V_67 ) ) ,
F_77 , ( void * ) F_80 ( V_67 ) -> V_83 ,
F_81 ( struct V_7 , V_15 ) , true ) ;
return 0 ;
}
static T_2 F_83 ( struct V_66 * V_67 ,
struct V_22 * V_11 ,
int V_82 )
{
struct V_73 V_74 = F_84 ( V_11 -> V_8 ,
NULL , V_82 ) ;
return F_71 ( V_67 , V_11 , & V_74 ) ;
}
int F_85 ( struct V_66 * V_67 , void * V_71 )
{
F_64 ( V_67 , F_55 ( F_79 ( V_67 ) ) ,
F_83 ,
( void * ) F_80 ( V_67 ) -> V_83 ,
F_81 ( struct V_7 , V_16 ) , true ) ;
return 0 ;
}
int F_86 ( struct V_66 * V_67 , void * V_71 )
{
F_64 ( V_67 , F_55 ( F_79 ( V_67 ) ) ,
F_83 ,
( void * ) F_80 ( V_67 ) -> V_83 ,
F_81 ( struct V_7 , V_15 ) , true ) ;
return 0 ;
}
T_2 F_87 ( struct V_7 * V_8 ,
struct V_3 * V_4 , int V_82 )
{
struct V_7 * V_84 ;
struct V_60 * V_85 ;
T_2 V_86 = 0 ;
F_16 ( V_8 -> V_2 -> V_27 ) ;
F_66 () ;
F_88 (pos_blkg, pos_css, blkg) {
struct V_87 * V_88 ;
if ( ! V_84 -> V_48 )
continue;
if ( V_4 )
V_88 = ( void * ) F_89 ( V_84 , V_4 ) + V_82 ;
else
V_88 = ( void * ) V_8 + V_82 ;
V_86 += F_74 ( V_88 ) + F_72 ( & V_88 -> V_81 ) ;
}
F_68 () ;
return V_86 ;
}
struct V_73 F_84 ( struct V_7 * V_8 ,
struct V_3 * V_4 , int V_82 )
{
struct V_7 * V_84 ;
struct V_60 * V_85 ;
struct V_73 V_86 = { } ;
int V_9 ;
F_16 ( V_8 -> V_2 -> V_27 ) ;
F_66 () ;
F_88 (pos_blkg, pos_css, blkg) {
struct V_73 * V_74 ;
if ( ! V_84 -> V_48 )
continue;
if ( V_4 )
V_74 = ( void * ) F_89 ( V_84 , V_4 ) + V_82 ;
else
V_74 = ( void * ) V_84 + V_82 ;
for ( V_9 = 0 ; V_9 < V_80 ; V_9 ++ )
F_90 ( F_72 ( & V_74 -> V_81 [ V_9 ] ) +
F_91 ( & V_74 -> V_89 [ V_9 ] ) ,
& V_86 . V_81 [ V_9 ] ) ;
}
F_68 () ;
return V_86 ;
}
static struct V_7 * F_92 ( struct V_12 * V_12 ,
const struct V_3 * V_4 ,
struct V_1 * V_2 )
{
F_19 ( ! F_20 () ) ;
F_16 ( V_2 -> V_27 ) ;
if ( ! F_1 ( V_2 , V_4 ) )
return F_34 ( - V_90 ) ;
if ( F_23 ( F_38 ( V_2 ) ) )
return F_34 ( F_39 ( V_2 ) ? - V_34 : - V_49 ) ;
return F_25 ( V_12 , V_2 , true ) ;
}
int F_93 ( struct V_12 * V_12 , const struct V_3 * V_4 ,
char * V_91 , struct V_92 * V_93 )
__acquires( T_3 ) __acquires( V_94 -> V_95 -> V_27 )
{
struct V_96 * V_94 ;
struct V_1 * V_2 ;
struct V_7 * V_8 ;
struct V_97 * V_98 ;
unsigned int V_99 , V_100 ;
int V_101 , V_102 , V_32 ;
char * V_103 ;
if ( sscanf ( V_91 , L_9 , & V_99 , & V_100 , & V_101 ) != 2 )
return - V_104 ;
V_103 = V_91 + V_101 ;
if ( ! isspace ( * V_103 ) )
return - V_104 ;
V_103 = F_94 ( V_103 ) ;
V_94 = F_95 ( F_96 ( V_99 , V_100 ) , & V_102 ) ;
if ( ! V_94 )
return - V_34 ;
if ( V_102 ) {
V_32 = - V_34 ;
goto V_105;
}
V_2 = V_94 -> V_95 ;
F_66 () ;
F_57 ( V_2 -> V_27 ) ;
V_8 = F_92 ( V_12 , V_4 , V_2 ) ;
if ( F_40 ( V_8 ) ) {
V_32 = F_97 ( V_8 ) ;
goto V_106;
}
if ( V_8 )
goto V_107;
while ( true ) {
struct V_12 * V_50 = V_12 ;
struct V_12 * V_42 ;
struct V_7 * V_29 ;
V_42 = F_24 ( V_12 ) ;
while ( V_42 && ! F_25 ( V_42 , V_2 , false ) ) {
V_50 = V_42 ;
V_42 = F_24 ( V_42 ) ;
}
F_60 ( V_2 -> V_27 ) ;
F_68 () ;
V_29 = F_8 ( V_50 , V_2 , V_108 ) ;
if ( F_23 ( ! V_29 ) ) {
V_32 = - V_39 ;
goto V_105;
}
F_66 () ;
F_57 ( V_2 -> V_27 ) ;
V_8 = F_92 ( V_50 , V_4 , V_2 ) ;
if ( F_40 ( V_8 ) ) {
V_32 = F_97 ( V_8 ) ;
goto V_106;
}
if ( V_8 ) {
F_3 ( V_29 ) ;
} else {
V_8 = F_18 ( V_50 , V_2 , V_29 ) ;
if ( F_23 ( F_40 ( V_8 ) ) ) {
V_32 = F_97 ( V_8 ) ;
goto V_106;
}
}
if ( V_50 == V_12 )
goto V_107;
}
V_107:
V_93 -> V_94 = V_94 ;
V_93 -> V_8 = V_8 ;
V_93 -> V_103 = V_103 ;
return 0 ;
V_106:
F_60 ( V_2 -> V_27 ) ;
F_68 () ;
V_105:
V_98 = V_94 -> V_109 -> V_98 ;
F_98 ( V_94 ) ;
F_99 ( V_98 ) ;
if ( V_32 == - V_49 ) {
F_100 ( 10 ) ;
V_32 = F_101 () ;
}
return V_32 ;
}
void F_102 ( struct V_92 * V_93 )
__releases( V_93 -> V_94 -> V_95 -> V_27 ) __releases( T_3 )
{
struct V_97 * V_98 ;
F_60 ( V_93 -> V_94 -> V_95 -> V_27 ) ;
F_68 () ;
V_98 = V_93 -> V_94 -> V_109 -> V_98 ;
F_98 ( V_93 -> V_94 ) ;
F_99 ( V_98 ) ;
}
static int F_103 ( struct V_66 * V_67 , void * V_71 )
{
struct V_12 * V_12 = F_55 ( F_79 ( V_67 ) ) ;
struct V_7 * V_8 ;
F_66 () ;
F_67 (blkg, &blkcg->blkg_list, blkcg_node) {
const char * V_72 ;
struct V_73 V_74 ;
T_2 V_110 , V_111 , V_112 , V_113 ;
V_72 = F_62 ( V_8 ) ;
if ( ! V_72 )
continue;
F_57 ( V_8 -> V_2 -> V_27 ) ;
V_74 = F_84 ( V_8 , NULL ,
F_81 ( struct V_7 , V_16 ) ) ;
V_110 = F_72 ( & V_74 . V_81 [ V_76 ] ) ;
V_111 = F_72 ( & V_74 . V_81 [ V_77 ] ) ;
V_74 = F_84 ( V_8 , NULL ,
F_81 ( struct V_7 , V_15 ) ) ;
V_112 = F_72 ( & V_74 . V_81 [ V_76 ] ) ;
V_113 = F_72 ( & V_74 . V_81 [ V_77 ] ) ;
F_60 ( V_8 -> V_2 -> V_27 ) ;
if ( V_110 || V_111 || V_112 || V_113 )
F_69 ( V_67 , L_10 ,
V_72 , V_110 , V_111 , V_112 , V_113 ) ;
}
F_68 () ;
return 0 ;
}
static void F_104 ( struct V_60 * V_33 )
{
struct V_12 * V_12 = F_55 ( V_33 ) ;
F_57 ( & V_12 -> V_44 ) ;
while ( ! F_105 ( & V_12 -> V_46 ) ) {
struct V_7 * V_8 = F_106 ( V_12 -> V_46 . V_114 ,
struct V_7 , V_45 ) ;
struct V_1 * V_2 = V_8 -> V_2 ;
if ( F_107 ( V_2 -> V_27 ) ) {
F_41 ( V_8 ) ;
F_32 ( V_2 -> V_27 ) ;
} else {
F_60 ( & V_12 -> V_44 ) ;
F_108 () ;
F_57 ( & V_12 -> V_44 ) ;
}
}
F_60 ( & V_12 -> V_44 ) ;
F_109 ( V_12 ) ;
}
static void F_110 ( struct V_60 * V_33 )
{
struct V_12 * V_12 = F_55 ( V_33 ) ;
int V_9 ;
F_56 ( & V_63 ) ;
F_111 ( & V_12 -> V_115 ) ;
for ( V_9 = 0 ; V_9 < V_10 ; V_9 ++ )
if ( V_12 -> V_116 [ V_9 ] )
V_3 [ V_9 ] -> F_112 ( V_12 -> V_116 [ V_9 ] ) ;
F_61 ( & V_63 ) ;
F_7 ( V_12 ) ;
}
static struct V_60 *
F_113 ( struct V_60 * V_117 )
{
struct V_12 * V_12 ;
struct V_60 * V_32 ;
int V_9 ;
F_56 ( & V_63 ) ;
if ( ! V_117 ) {
V_12 = & V_13 ;
} else {
V_12 = F_114 ( sizeof( * V_12 ) , V_108 ) ;
if ( ! V_12 ) {
V_32 = F_34 ( - V_39 ) ;
goto V_118;
}
}
for ( V_9 = 0 ; V_9 < V_10 ; V_9 ++ ) {
struct V_3 * V_4 = V_3 [ V_9 ] ;
struct V_119 * V_116 ;
if ( ! V_4 || ! V_4 -> V_120 )
continue;
V_116 = V_4 -> V_120 ( V_108 ) ;
if ( ! V_116 ) {
V_32 = F_34 ( - V_39 ) ;
goto V_121;
}
V_12 -> V_116 [ V_9 ] = V_116 ;
V_116 -> V_12 = V_12 ;
V_116 -> V_5 = V_9 ;
if ( V_4 -> V_122 )
V_4 -> V_122 ( V_116 ) ;
}
F_115 ( & V_12 -> V_44 ) ;
F_116 ( & V_12 -> V_25 , V_37 | V_38 ) ;
F_117 ( & V_12 -> V_46 ) ;
#ifdef F_118
F_11 ( & V_12 -> V_123 ) ;
#endif
F_119 ( & V_12 -> V_115 , & V_124 ) ;
F_61 ( & V_63 ) ;
return & V_12 -> V_33 ;
V_121:
for ( V_9 -- ; V_9 >= 0 ; V_9 -- )
if ( V_12 -> V_116 [ V_9 ] )
V_3 [ V_9 ] -> F_112 ( V_12 -> V_116 [ V_9 ] ) ;
if ( V_12 != & V_13 )
F_7 ( V_12 ) ;
V_118:
F_61 ( & V_63 ) ;
return V_32 ;
}
int F_120 ( struct V_1 * V_2 )
{
struct V_7 * V_29 , * V_8 ;
bool V_125 ;
int V_32 ;
V_29 = F_8 ( & V_13 , V_2 , V_108 ) ;
if ( ! V_29 )
return - V_39 ;
V_125 = ! F_121 ( V_108 ) ;
F_66 () ;
F_57 ( V_2 -> V_27 ) ;
V_8 = F_18 ( & V_13 , V_2 , V_29 ) ;
F_60 ( V_2 -> V_27 ) ;
F_68 () ;
if ( V_125 )
F_122 () ;
if ( F_40 ( V_8 ) )
return F_97 ( V_8 ) ;
V_2 -> V_53 = V_8 ;
V_2 -> V_54 . V_8 = V_8 ;
V_32 = F_123 ( V_2 ) ;
if ( V_32 ) {
F_57 ( V_2 -> V_27 ) ;
F_49 ( V_2 ) ;
F_60 ( V_2 -> V_27 ) ;
}
return V_32 ;
}
void F_124 ( struct V_1 * V_2 )
{
F_16 ( V_2 -> V_27 ) ;
if ( ! V_2 -> V_53 )
return;
F_125 ( V_2 ) ;
}
void F_126 ( struct V_1 * V_2 )
{
F_57 ( V_2 -> V_27 ) ;
F_49 ( V_2 ) ;
F_60 ( V_2 -> V_27 ) ;
F_127 ( V_2 ) ;
}
static int F_128 ( struct V_126 * V_127 )
{
struct V_128 * V_129 ;
struct V_60 * V_130 ;
struct V_131 * V_132 ;
int V_32 = 0 ;
F_129 (task, dst_css, tset) {
F_130 ( V_129 ) ;
V_132 = V_129 -> V_131 ;
if ( V_132 && F_131 ( & V_132 -> V_133 ) > 1 )
V_32 = - V_104 ;
F_132 ( V_129 ) ;
if ( V_32 )
break;
}
return V_32 ;
}
static void F_133 ( struct V_60 * V_134 )
{
int V_9 ;
F_56 ( & V_63 ) ;
for ( V_9 = 0 ; V_9 < V_10 ; V_9 ++ ) {
struct V_3 * V_4 = V_3 [ V_9 ] ;
struct V_12 * V_12 ;
if ( ! V_4 || ! V_4 -> V_135 )
continue;
F_134 (blkcg, &all_blkcgs, all_blkcgs_node)
if ( V_12 -> V_116 [ V_4 -> V_5 ] )
V_4 -> V_135 ( V_12 -> V_116 [ V_4 -> V_5 ] ) ;
}
F_61 ( & V_63 ) ;
}
int F_135 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
struct V_22 * V_136 = NULL ;
struct V_7 * V_8 ;
int V_32 ;
if ( F_1 ( V_2 , V_4 ) )
return 0 ;
if ( V_2 -> V_137 )
F_136 ( V_2 ) ;
else
F_137 ( V_2 ) ;
V_136:
if ( ! V_136 ) {
V_136 = V_4 -> V_23 ( V_108 , V_2 -> V_18 ) ;
if ( ! V_136 ) {
V_32 = - V_39 ;
goto V_138;
}
}
F_57 ( V_2 -> V_27 ) ;
F_134 (blkg, &q->blkg_list, q_node) {
struct V_22 * V_11 ;
if ( V_8 -> V_11 [ V_4 -> V_5 ] )
continue;
V_11 = V_4 -> V_23 ( V_37 | V_38 , V_2 -> V_18 ) ;
if ( ! V_11 )
F_138 ( V_11 , V_136 ) ;
if ( ! V_11 ) {
F_60 ( V_2 -> V_27 ) ;
goto V_136;
}
V_8 -> V_11 [ V_4 -> V_5 ] = V_11 ;
V_11 -> V_8 = V_8 ;
V_11 -> V_5 = V_4 -> V_5 ;
if ( V_4 -> V_43 )
V_4 -> V_43 ( V_11 ) ;
}
F_139 ( V_4 -> V_5 , V_2 -> V_6 ) ;
V_32 = 0 ;
F_60 ( V_2 -> V_27 ) ;
V_138:
if ( V_2 -> V_137 )
F_140 ( V_2 ) ;
else
F_141 ( V_2 ) ;
if ( V_136 )
V_4 -> F_4 ( V_136 ) ;
return V_32 ;
}
void F_142 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
struct V_7 * V_8 ;
if ( ! F_1 ( V_2 , V_4 ) )
return;
if ( V_2 -> V_137 )
F_136 ( V_2 ) ;
else
F_137 ( V_2 ) ;
F_57 ( V_2 -> V_27 ) ;
F_143 ( V_4 -> V_5 , V_2 -> V_6 ) ;
F_134 (blkg, &q->blkg_list, q_node) {
F_27 ( & V_8 -> V_12 -> V_44 ) ;
if ( V_8 -> V_11 [ V_4 -> V_5 ] ) {
if ( V_4 -> V_51 )
V_4 -> V_51 ( V_8 -> V_11 [ V_4 -> V_5 ] ) ;
V_4 -> F_4 ( V_8 -> V_11 [ V_4 -> V_5 ] ) ;
V_8 -> V_11 [ V_4 -> V_5 ] = NULL ;
}
F_32 ( & V_8 -> V_12 -> V_44 ) ;
}
F_60 ( V_2 -> V_27 ) ;
if ( V_2 -> V_137 )
F_140 ( V_2 ) ;
else
F_141 ( V_2 ) ;
}
int F_144 ( struct V_3 * V_4 )
{
struct V_12 * V_12 ;
int V_9 , V_32 ;
F_56 ( & V_139 ) ;
F_56 ( & V_63 ) ;
V_32 = - V_140 ;
for ( V_9 = 0 ; V_9 < V_10 ; V_9 ++ )
if ( ! V_3 [ V_9 ] )
break;
if ( V_9 >= V_10 )
goto V_141;
V_4 -> V_5 = V_9 ;
V_3 [ V_4 -> V_5 ] = V_4 ;
if ( V_4 -> V_120 ) {
F_134 (blkcg, &all_blkcgs, all_blkcgs_node) {
struct V_119 * V_116 ;
V_116 = V_4 -> V_120 ( V_108 ) ;
if ( ! V_116 )
goto V_142;
V_12 -> V_116 [ V_4 -> V_5 ] = V_116 ;
V_116 -> V_12 = V_12 ;
V_116 -> V_5 = V_4 -> V_5 ;
V_4 -> V_122 ( V_116 ) ;
}
}
F_61 ( & V_63 ) ;
if ( V_4 -> V_143 )
F_145 ( F_146 ( & V_144 ,
V_4 -> V_143 ) ) ;
if ( V_4 -> V_145 )
F_145 ( F_147 ( & V_144 ,
V_4 -> V_145 ) ) ;
F_61 ( & V_139 ) ;
return 0 ;
V_142:
if ( V_4 -> V_120 ) {
F_134 (blkcg, &all_blkcgs, all_blkcgs_node) {
if ( V_12 -> V_116 [ V_4 -> V_5 ] ) {
V_4 -> F_112 ( V_12 -> V_116 [ V_4 -> V_5 ] ) ;
V_12 -> V_116 [ V_4 -> V_5 ] = NULL ;
}
}
}
V_3 [ V_4 -> V_5 ] = NULL ;
V_141:
F_61 ( & V_63 ) ;
F_61 ( & V_139 ) ;
return V_32 ;
}
void F_148 ( struct V_3 * V_4 )
{
struct V_12 * V_12 ;
F_56 ( & V_139 ) ;
if ( F_145 ( V_3 [ V_4 -> V_5 ] != V_4 ) )
goto V_146;
if ( V_4 -> V_143 )
F_149 ( V_4 -> V_143 ) ;
if ( V_4 -> V_145 )
F_149 ( V_4 -> V_145 ) ;
F_56 ( & V_63 ) ;
if ( V_4 -> V_120 ) {
F_134 (blkcg, &all_blkcgs, all_blkcgs_node) {
if ( V_12 -> V_116 [ V_4 -> V_5 ] ) {
V_4 -> F_112 ( V_12 -> V_116 [ V_4 -> V_5 ] ) ;
V_12 -> V_116 [ V_4 -> V_5 ] = NULL ;
}
}
}
V_3 [ V_4 -> V_5 ] = NULL ;
F_61 ( & V_63 ) ;
V_146:
F_61 ( & V_139 ) ;
}
