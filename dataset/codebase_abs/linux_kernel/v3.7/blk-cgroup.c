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
for ( V_9 = 0 ; V_9 < V_10 ; V_9 ++ ) {
struct V_3 * V_4 = V_3 [ V_9 ] ;
struct V_11 * V_12 = V_8 -> V_12 [ V_9 ] ;
if ( ! V_12 )
continue;
if ( V_4 && V_4 -> V_13 )
V_4 -> V_13 ( V_8 ) ;
F_4 ( V_12 ) ;
}
F_5 ( & V_8 -> V_14 ) ;
F_4 ( V_8 ) ;
}
static struct V_7 * F_6 ( struct V_15 * V_15 , struct V_1 * V_2 ,
T_1 V_16 )
{
struct V_7 * V_8 ;
int V_9 ;
V_8 = F_7 ( sizeof( * V_8 ) , V_16 , V_2 -> V_17 ) ;
if ( ! V_8 )
return NULL ;
V_8 -> V_2 = V_2 ;
F_8 ( & V_8 -> V_18 ) ;
V_8 -> V_15 = V_15 ;
V_8 -> V_19 = 1 ;
if ( V_15 != & V_20 ) {
if ( F_9 ( & V_8 -> V_14 , V_2 , V_16 ) )
goto V_21;
V_8 -> V_14 . V_8 = V_8 ;
}
for ( V_9 = 0 ; V_9 < V_10 ; V_9 ++ ) {
struct V_3 * V_4 = V_3 [ V_9 ] ;
struct V_11 * V_12 ;
if ( ! F_1 ( V_2 , V_4 ) )
continue;
V_12 = F_7 ( V_4 -> V_22 , V_16 , V_2 -> V_17 ) ;
if ( ! V_12 )
goto V_21;
V_8 -> V_12 [ V_9 ] = V_12 ;
V_12 -> V_8 = V_8 ;
if ( F_1 ( V_8 -> V_2 , V_4 ) )
V_4 -> V_23 ( V_8 ) ;
}
return V_8 ;
V_21:
F_3 ( V_8 ) ;
return NULL ;
}
static struct V_7 * F_10 ( struct V_15 * V_15 ,
struct V_1 * V_2 )
{
struct V_7 * V_8 ;
V_8 = F_11 ( V_15 -> V_24 ) ;
if ( V_8 && V_8 -> V_2 == V_2 )
return V_8 ;
V_8 = F_12 ( & V_15 -> V_25 , V_2 -> V_26 ) ;
if ( V_8 && V_8 -> V_2 == V_2 )
return V_8 ;
return NULL ;
}
struct V_7 * F_13 ( struct V_15 * V_15 , struct V_1 * V_2 )
{
F_14 ( ! F_15 () ) ;
if ( F_16 ( F_17 ( V_2 ) ) )
return NULL ;
return F_10 ( V_15 , V_2 ) ;
}
static struct V_7 * F_18 ( struct V_15 * V_15 ,
struct V_1 * V_2 ,
struct V_7 * V_27 )
{
struct V_7 * V_8 ;
int V_28 ;
F_14 ( ! F_15 () ) ;
F_19 ( V_2 -> V_29 ) ;
V_8 = F_10 ( V_15 , V_2 ) ;
if ( V_8 ) {
F_20 ( V_15 -> V_24 , V_8 ) ;
goto V_30;
}
if ( ! F_21 ( & V_15 -> V_31 ) ) {
V_8 = F_22 ( - V_32 ) ;
goto V_30;
}
if ( ! V_27 ) {
V_27 = F_6 ( V_15 , V_2 , V_33 ) ;
if ( F_16 ( ! V_27 ) ) {
V_8 = F_22 ( - V_34 ) ;
goto V_35;
}
}
V_8 = V_27 ;
F_23 ( & V_15 -> V_36 ) ;
V_28 = F_24 ( & V_15 -> V_25 , V_2 -> V_26 , V_8 ) ;
if ( F_25 ( ! V_28 ) ) {
F_26 ( & V_8 -> V_37 , & V_15 -> V_38 ) ;
F_27 ( & V_8 -> V_18 , & V_2 -> V_38 ) ;
}
F_28 ( & V_15 -> V_36 ) ;
if ( ! V_28 )
return V_8 ;
V_8 = F_22 ( V_28 ) ;
V_35:
F_29 ( & V_15 -> V_31 ) ;
V_30:
F_3 ( V_27 ) ;
return V_8 ;
}
struct V_7 * F_30 ( struct V_15 * V_15 ,
struct V_1 * V_2 )
{
if ( F_16 ( F_17 ( V_2 ) ) )
return F_22 ( F_31 ( V_2 ) ? - V_32 : - V_39 ) ;
return F_18 ( V_15 , V_2 , NULL ) ;
}
static void F_32 ( struct V_7 * V_8 )
{
struct V_15 * V_15 = V_8 -> V_15 ;
F_19 ( V_8 -> V_2 -> V_29 ) ;
F_19 ( & V_15 -> V_36 ) ;
F_14 ( F_33 ( & V_8 -> V_18 ) ) ;
F_14 ( F_34 ( & V_8 -> V_37 ) ) ;
F_35 ( & V_15 -> V_25 , V_8 -> V_2 -> V_26 ) ;
F_36 ( & V_8 -> V_18 ) ;
F_37 ( & V_8 -> V_37 ) ;
if ( F_38 ( V_15 -> V_24 ) == V_8 )
F_20 ( V_15 -> V_24 , NULL ) ;
F_39 ( V_8 ) ;
}
static void F_40 ( struct V_1 * V_2 )
{
struct V_7 * V_8 , * V_40 ;
F_19 ( V_2 -> V_29 ) ;
F_41 (blkg, n, &q->blkg_list, q_node) {
struct V_15 * V_15 = V_8 -> V_15 ;
F_23 ( & V_15 -> V_36 ) ;
F_32 ( V_8 ) ;
F_28 ( & V_15 -> V_36 ) ;
}
V_2 -> V_41 = NULL ;
V_2 -> V_42 . V_8 = NULL ;
}
static void F_42 ( struct V_43 * V_43 )
{
F_3 ( F_43 ( V_43 , struct V_7 , V_43 ) ) ;
}
void F_44 ( struct V_7 * V_8 )
{
F_29 ( & V_8 -> V_15 -> V_31 ) ;
F_45 ( & V_8 -> V_43 , F_42 ) ;
}
struct V_44 * F_46 ( struct V_44 * V_14 ,
struct V_1 * V_2 )
{
struct V_45 * V_46 ;
struct V_7 * V_8 ;
if ( V_14 == & V_2 -> V_42 ) {
V_46 = & V_2 -> V_38 ;
if ( F_33 ( V_46 ) )
return NULL ;
} else {
V_8 = F_43 ( V_14 , struct V_7 , V_14 ) ;
V_46 = & V_8 -> V_18 ;
}
V_46 = V_46 -> V_47 ;
if ( V_46 == & V_2 -> V_41 -> V_18 )
V_46 = V_46 -> V_47 ;
if ( V_46 == & V_2 -> V_38 )
return NULL ;
V_8 = F_43 ( V_46 , struct V_7 , V_18 ) ;
return & V_8 -> V_14 ;
}
static int F_47 ( struct V_48 * V_48 , struct V_49 * V_49 ,
T_2 V_50 )
{
struct V_15 * V_15 = F_48 ( V_48 ) ;
struct V_7 * V_8 ;
struct V_51 * V_40 ;
int V_9 ;
F_49 ( & V_52 ) ;
F_50 ( & V_15 -> V_36 ) ;
F_51 (blkg, n, &blkcg->blkg_list, blkcg_node) {
for ( V_9 = 0 ; V_9 < V_10 ; V_9 ++ ) {
struct V_3 * V_4 = V_3 [ V_9 ] ;
if ( F_1 ( V_8 -> V_2 , V_4 ) &&
V_4 -> V_53 )
V_4 -> V_53 ( V_8 ) ;
}
}
F_52 ( & V_15 -> V_36 ) ;
F_53 ( & V_52 ) ;
return 0 ;
}
static const char * F_54 ( struct V_7 * V_8 )
{
if ( V_8 -> V_2 -> V_54 . V_55 )
return F_55 ( V_8 -> V_2 -> V_54 . V_55 ) ;
return NULL ;
}
void F_56 ( struct V_56 * V_57 , struct V_15 * V_15 ,
T_2 (* F_57)( struct V_56 * ,
struct V_11 * , int ) ,
const struct V_3 * V_4 , int V_58 ,
bool V_59 )
{
struct V_7 * V_8 ;
struct V_51 * V_40 ;
T_2 V_60 = 0 ;
F_50 ( & V_15 -> V_36 ) ;
F_51 (blkg, n, &blkcg->blkg_list, blkcg_node)
if ( F_1 ( V_8 -> V_2 , V_4 ) )
V_60 += F_57 ( V_57 , V_8 -> V_12 [ V_4 -> V_5 ] , V_58 ) ;
F_52 ( & V_15 -> V_36 ) ;
if ( V_59 )
F_58 ( V_57 , L_1 , ( unsigned long long ) V_60 ) ;
}
T_2 F_59 ( struct V_56 * V_57 , struct V_11 * V_12 , T_2 V_61 )
{
const char * V_62 = F_54 ( V_12 -> V_8 ) ;
if ( ! V_62 )
return 0 ;
F_58 ( V_57 , L_2 , V_62 , ( unsigned long long ) V_61 ) ;
return V_61 ;
}
T_2 F_60 ( struct V_56 * V_57 , struct V_11 * V_12 ,
const struct V_63 * V_64 )
{
static const char * V_65 [] = {
[ V_66 ] = L_3 ,
[ V_67 ] = L_4 ,
[ V_68 ] = L_5 ,
[ V_69 ] = L_6 ,
} ;
const char * V_62 = F_54 ( V_12 -> V_8 ) ;
T_2 V_61 ;
int V_9 ;
if ( ! V_62 )
return 0 ;
for ( V_9 = 0 ; V_9 < V_70 ; V_9 ++ )
F_58 ( V_57 , L_7 , V_62 , V_65 [ V_9 ] ,
( unsigned long long ) V_64 -> V_71 [ V_9 ] ) ;
V_61 = V_64 -> V_71 [ V_66 ] + V_64 -> V_71 [ V_67 ] ;
F_58 ( V_57 , L_8 , V_62 , ( unsigned long long ) V_61 ) ;
return V_61 ;
}
T_2 F_61 ( struct V_56 * V_57 , struct V_11 * V_12 , int V_72 )
{
return F_59 ( V_57 , V_12 , F_62 ( ( void * ) V_12 + V_72 ) ) ;
}
T_2 F_63 ( struct V_56 * V_57 , struct V_11 * V_12 ,
int V_72 )
{
struct V_63 V_64 = F_64 ( ( void * ) V_12 + V_72 ) ;
return F_60 ( V_57 , V_12 , & V_64 ) ;
}
int F_65 ( struct V_15 * V_15 , const struct V_3 * V_4 ,
const char * V_73 , struct V_74 * V_75 )
__acquires( T_3 ) __acquires( V_76 -> V_77 -> V_29 )
{
struct V_78 * V_76 ;
struct V_7 * V_8 ;
unsigned int V_79 , V_80 ;
unsigned long long V_61 ;
int V_81 , V_28 ;
if ( sscanf ( V_73 , L_9 , & V_79 , & V_80 , & V_61 ) != 3 )
return - V_32 ;
V_76 = F_66 ( F_67 ( V_79 , V_80 ) , & V_81 ) ;
if ( ! V_76 || V_81 )
return - V_32 ;
F_68 () ;
F_50 ( V_76 -> V_77 -> V_29 ) ;
if ( F_1 ( V_76 -> V_77 , V_4 ) )
V_8 = F_30 ( V_15 , V_76 -> V_77 ) ;
else
V_8 = F_22 ( - V_32 ) ;
if ( F_69 ( V_8 ) ) {
V_28 = F_70 ( V_8 ) ;
F_71 () ;
F_52 ( V_76 -> V_77 -> V_29 ) ;
F_72 ( V_76 ) ;
if ( V_28 == - V_39 ) {
F_73 ( 10 ) ;
V_28 = F_74 () ;
}
return V_28 ;
}
V_75 -> V_76 = V_76 ;
V_75 -> V_8 = V_8 ;
V_75 -> V_61 = V_61 ;
return 0 ;
}
void F_75 ( struct V_74 * V_75 )
__releases( V_75 -> V_76 -> V_77 -> V_29 ) __releases( T_3 )
{
F_52 ( V_75 -> V_76 -> V_77 -> V_29 ) ;
F_71 () ;
F_72 ( V_75 -> V_76 ) ;
}
static int F_76 ( struct V_48 * V_48 )
{
struct V_15 * V_15 = F_48 ( V_48 ) ;
F_50 ( & V_15 -> V_36 ) ;
while ( ! F_77 ( & V_15 -> V_38 ) ) {
struct V_7 * V_8 = F_78 ( V_15 -> V_38 . V_82 ,
struct V_7 , V_37 ) ;
struct V_1 * V_2 = V_8 -> V_2 ;
if ( F_79 ( V_2 -> V_29 ) ) {
F_32 ( V_8 ) ;
F_28 ( V_2 -> V_29 ) ;
} else {
F_52 ( & V_15 -> V_36 ) ;
F_80 () ;
F_50 ( & V_15 -> V_36 ) ;
}
}
F_52 ( & V_15 -> V_36 ) ;
return 0 ;
}
static void F_81 ( struct V_48 * V_48 )
{
struct V_15 * V_15 = F_48 ( V_48 ) ;
if ( V_15 != & V_20 )
F_4 ( V_15 ) ;
}
static struct V_83 * F_82 ( struct V_48 * V_48 )
{
static T_4 V_84 = F_83 ( 0 ) ;
struct V_15 * V_15 ;
struct V_48 * V_85 = V_48 -> V_85 ;
if ( ! V_85 ) {
V_15 = & V_20 ;
goto V_86;
}
V_15 = F_84 ( sizeof( * V_15 ) , V_87 ) ;
if ( ! V_15 )
return F_22 ( - V_34 ) ;
V_15 -> V_88 = V_89 ;
V_15 -> V_26 = F_85 ( & V_84 ) ;
V_86:
F_86 ( & V_15 -> V_36 ) ;
F_87 ( & V_15 -> V_25 , V_33 ) ;
F_88 ( & V_15 -> V_38 ) ;
return & V_15 -> V_31 ;
}
int F_89 ( struct V_1 * V_2 )
{
F_90 () ;
return F_91 ( V_2 ) ;
}
void F_92 ( struct V_1 * V_2 )
{
F_19 ( V_2 -> V_29 ) ;
F_93 ( V_2 ) ;
}
void F_94 ( struct V_1 * V_2 )
{
F_50 ( V_2 -> V_29 ) ;
F_40 ( V_2 ) ;
F_52 ( V_2 -> V_29 ) ;
F_95 ( V_2 ) ;
}
static int F_96 ( struct V_48 * V_90 , struct V_91 * V_92 )
{
struct V_93 * V_94 ;
struct V_95 * V_96 ;
int V_28 = 0 ;
F_97 (task, cgrp, tset) {
F_98 ( V_94 ) ;
V_96 = V_94 -> V_95 ;
if ( V_96 && F_99 ( & V_96 -> V_97 ) > 1 )
V_28 = - V_32 ;
F_100 ( V_94 ) ;
if ( V_28 )
break;
}
return V_28 ;
}
int F_101 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
F_102 ( V_98 ) ;
struct V_7 * V_8 ;
struct V_11 * V_12 , * V_40 ;
int V_71 = 0 , V_28 ;
bool V_99 ;
if ( F_1 ( V_2 , V_4 ) )
return 0 ;
V_8 = F_6 ( & V_20 , V_2 , V_87 ) ;
if ( ! V_8 )
return - V_34 ;
V_99 = ! F_103 ( V_87 ) ;
F_104 ( V_2 ) ;
F_50 ( V_2 -> V_29 ) ;
F_68 () ;
V_8 = F_18 ( & V_20 , V_2 , V_8 ) ;
F_71 () ;
if ( V_99 )
F_105 () ;
if ( F_69 ( V_8 ) ) {
V_28 = F_70 ( V_8 ) ;
goto V_100;
}
V_2 -> V_41 = V_8 ;
V_2 -> V_42 . V_8 = V_8 ;
F_106 (blkg, &q->blkg_list, q_node)
V_71 ++ ;
F_52 ( V_2 -> V_29 ) ;
while ( V_71 -- ) {
V_12 = F_7 ( V_4 -> V_22 , V_87 , V_2 -> V_17 ) ;
if ( ! V_12 ) {
V_28 = - V_34 ;
goto V_30;
}
F_107 ( & V_12 -> V_101 , & V_98 ) ;
}
F_50 ( V_2 -> V_29 ) ;
F_106 (blkg, &q->blkg_list, q_node) {
if ( F_108 ( F_33 ( & V_98 ) ) ) {
V_28 = - V_34 ;
goto V_100;
}
V_12 = F_109 ( & V_98 , struct V_11 , V_101 ) ;
F_36 ( & V_12 -> V_101 ) ;
F_23 ( & V_8 -> V_15 -> V_36 ) ;
V_8 -> V_12 [ V_4 -> V_5 ] = V_12 ;
V_12 -> V_8 = V_8 ;
V_4 -> V_23 ( V_8 ) ;
F_28 ( & V_8 -> V_15 -> V_36 ) ;
}
F_110 ( V_4 -> V_5 , V_2 -> V_6 ) ;
V_28 = 0 ;
V_100:
F_52 ( V_2 -> V_29 ) ;
V_30:
F_111 ( V_2 ) ;
F_41 (pd, n, &pds, alloc_node)
F_4 ( V_12 ) ;
return V_28 ;
}
void F_112 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
struct V_7 * V_8 ;
if ( ! F_1 ( V_2 , V_4 ) )
return;
F_104 ( V_2 ) ;
F_50 ( V_2 -> V_29 ) ;
F_113 ( V_4 -> V_5 , V_2 -> V_6 ) ;
if ( F_114 ( V_2 -> V_6 , V_10 ) )
F_40 ( V_2 ) ;
F_106 (blkg, &q->blkg_list, q_node) {
F_23 ( & V_8 -> V_15 -> V_36 ) ;
if ( V_4 -> V_13 )
V_4 -> V_13 ( V_8 ) ;
F_4 ( V_8 -> V_12 [ V_4 -> V_5 ] ) ;
V_8 -> V_12 [ V_4 -> V_5 ] = NULL ;
F_28 ( & V_8 -> V_15 -> V_36 ) ;
}
F_52 ( V_2 -> V_29 ) ;
F_111 ( V_2 ) ;
}
int F_115 ( struct V_3 * V_4 )
{
int V_9 , V_28 ;
if ( F_108 ( V_4 -> V_22 < sizeof( struct V_11 ) ) )
return - V_32 ;
F_49 ( & V_52 ) ;
V_28 = - V_102 ;
for ( V_9 = 0 ; V_9 < V_10 ; V_9 ++ )
if ( ! V_3 [ V_9 ] )
break;
if ( V_9 >= V_10 )
goto V_100;
V_4 -> V_5 = V_9 ;
V_3 [ V_9 ] = V_4 ;
if ( V_4 -> V_103 )
F_108 ( F_116 ( & V_104 , V_4 -> V_103 ) ) ;
V_28 = 0 ;
V_100:
F_53 ( & V_52 ) ;
return V_28 ;
}
void F_117 ( struct V_3 * V_4 )
{
F_49 ( & V_52 ) ;
if ( F_108 ( V_3 [ V_4 -> V_5 ] != V_4 ) )
goto V_100;
if ( V_4 -> V_103 )
F_118 ( & V_104 , V_4 -> V_103 ) ;
V_3 [ V_4 -> V_5 ] = NULL ;
V_100:
F_53 ( & V_52 ) ;
}
