struct V_1 * F_1 ( struct V_2 * V_2 )
{
return F_2 ( F_3 ( V_2 , V_3 ) ,
struct V_1 , V_4 ) ;
}
static struct V_1 * F_4 ( struct V_5 * V_6 )
{
return F_2 ( F_5 ( V_6 , V_3 ) ,
struct V_1 , V_4 ) ;
}
struct V_1 * F_6 ( struct V_7 * V_7 )
{
if ( V_7 && V_7 -> V_8 )
return F_2 ( V_7 -> V_8 , struct V_1 , V_4 ) ;
return F_4 ( V_9 ) ;
}
static bool F_7 ( struct V_10 * V_11 ,
const struct V_12 * V_13 )
{
return V_13 && F_8 ( V_13 -> V_14 , V_11 -> V_15 ) ;
}
static void F_9 ( struct V_16 * V_17 )
{
int V_18 ;
if ( ! V_17 )
return;
for ( V_18 = 0 ; V_18 < V_19 ; V_18 ++ ) {
struct V_12 * V_13 = V_12 [ V_18 ] ;
struct V_20 * V_21 = V_17 -> V_21 [ V_18 ] ;
if ( ! V_21 )
continue;
if ( V_13 && V_13 -> V_22 )
V_13 -> V_22 ( V_17 ) ;
F_10 ( V_21 ) ;
}
F_10 ( V_17 ) ;
}
static struct V_16 * F_11 ( struct V_1 * V_1 , struct V_10 * V_11 )
{
struct V_16 * V_17 ;
int V_18 ;
V_17 = F_12 ( sizeof( * V_17 ) , V_23 , V_11 -> V_24 ) ;
if ( ! V_17 )
return NULL ;
V_17 -> V_11 = V_11 ;
F_13 ( & V_17 -> V_25 ) ;
V_17 -> V_1 = V_1 ;
V_17 -> V_26 = 1 ;
for ( V_18 = 0 ; V_18 < V_19 ; V_18 ++ ) {
struct V_12 * V_13 = V_12 [ V_18 ] ;
struct V_20 * V_21 ;
if ( ! F_7 ( V_11 , V_13 ) )
continue;
V_21 = F_12 ( V_13 -> V_27 , V_23 , V_11 -> V_24 ) ;
if ( ! V_21 ) {
F_9 ( V_17 ) ;
return NULL ;
}
V_17 -> V_21 [ V_18 ] = V_21 ;
V_21 -> V_17 = V_17 ;
if ( F_7 ( V_17 -> V_11 , V_13 ) )
V_13 -> V_28 ( V_17 ) ;
}
return V_17 ;
}
static struct V_16 * F_14 ( struct V_1 * V_1 ,
struct V_10 * V_11 )
{
struct V_16 * V_17 ;
V_17 = F_15 ( V_1 -> V_29 ) ;
if ( V_17 && V_17 -> V_11 == V_11 )
return V_17 ;
V_17 = F_16 ( & V_1 -> V_30 , V_11 -> V_31 ) ;
if ( V_17 && V_17 -> V_11 == V_11 )
return V_17 ;
return NULL ;
}
struct V_16 * F_17 ( struct V_1 * V_1 , struct V_10 * V_11 )
{
F_18 ( ! F_19 () ) ;
if ( F_20 ( F_21 ( V_11 ) ) )
return NULL ;
return F_14 ( V_1 , V_11 ) ;
}
static struct V_16 * F_22 ( struct V_1 * V_1 ,
struct V_10 * V_11 )
__releases( V_11 -> V_32 ) __acquires( V_11 -> V_32 )
{
struct V_16 * V_17 ;
int V_33 ;
F_18 ( ! F_19 () ) ;
F_23 ( V_11 -> V_32 ) ;
V_17 = F_14 ( V_1 , V_11 ) ;
if ( V_17 ) {
F_24 ( V_1 -> V_29 , V_17 ) ;
return V_17 ;
}
if ( ! F_25 ( & V_1 -> V_4 ) )
return F_26 ( - V_34 ) ;
V_33 = - V_35 ;
V_17 = F_11 ( V_1 , V_11 ) ;
if ( F_20 ( ! V_17 ) )
goto V_36;
V_33 = F_27 ( V_23 ) ;
if ( V_33 )
goto V_37;
F_28 ( & V_1 -> V_38 ) ;
V_33 = F_29 ( & V_1 -> V_30 , V_11 -> V_31 , V_17 ) ;
if ( F_30 ( ! V_33 ) ) {
F_31 ( & V_17 -> V_39 , & V_1 -> V_40 ) ;
F_32 ( & V_17 -> V_25 , & V_11 -> V_40 ) ;
}
F_33 ( & V_1 -> V_38 ) ;
F_34 () ;
if ( ! V_33 )
return V_17 ;
V_37:
F_9 ( V_17 ) ;
V_36:
F_35 ( & V_1 -> V_4 ) ;
return F_26 ( V_33 ) ;
}
struct V_16 * F_36 ( struct V_1 * V_1 ,
struct V_10 * V_11 )
{
if ( F_20 ( F_21 ( V_11 ) ) )
return F_26 ( F_37 ( V_11 ) ? - V_34 : - V_41 ) ;
return F_22 ( V_1 , V_11 ) ;
}
static void F_38 ( struct V_16 * V_17 )
{
struct V_1 * V_1 = V_17 -> V_1 ;
F_23 ( V_17 -> V_11 -> V_32 ) ;
F_23 ( & V_1 -> V_38 ) ;
F_18 ( F_39 ( & V_17 -> V_25 ) ) ;
F_18 ( F_40 ( & V_17 -> V_39 ) ) ;
F_41 ( & V_1 -> V_30 , V_17 -> V_11 -> V_31 ) ;
F_42 ( & V_17 -> V_25 ) ;
F_43 ( & V_17 -> V_39 ) ;
if ( F_44 ( V_1 -> V_29 ) == V_17 )
F_24 ( V_1 -> V_29 , NULL ) ;
F_45 ( V_17 ) ;
}
static void F_46 ( struct V_10 * V_11 )
{
struct V_16 * V_17 , * V_42 ;
F_23 ( V_11 -> V_32 ) ;
F_47 (blkg, n, &q->blkg_list, q_node) {
struct V_1 * V_1 = V_17 -> V_1 ;
F_28 ( & V_1 -> V_38 ) ;
F_38 ( V_17 ) ;
F_33 ( & V_1 -> V_38 ) ;
}
}
static void F_48 ( struct V_43 * V_43 )
{
F_9 ( F_2 ( V_43 , struct V_16 , V_43 ) ) ;
}
void F_49 ( struct V_16 * V_17 )
{
F_35 ( & V_17 -> V_1 -> V_4 ) ;
F_50 ( & V_17 -> V_43 , F_48 ) ;
}
static int F_51 ( struct V_2 * V_2 , struct V_44 * V_44 ,
T_1 V_45 )
{
struct V_1 * V_1 = F_1 ( V_2 ) ;
struct V_16 * V_17 ;
struct V_46 * V_42 ;
int V_18 ;
F_52 ( & V_47 ) ;
F_53 ( & V_1 -> V_38 ) ;
F_54 (blkg, n, &blkcg->blkg_list, blkcg_node) {
for ( V_18 = 0 ; V_18 < V_19 ; V_18 ++ ) {
struct V_12 * V_13 = V_12 [ V_18 ] ;
if ( F_7 ( V_17 -> V_11 , V_13 ) &&
V_13 -> V_48 )
V_13 -> V_48 ( V_17 ) ;
}
}
F_55 ( & V_1 -> V_38 ) ;
F_56 ( & V_47 ) ;
return 0 ;
}
static const char * F_57 ( struct V_16 * V_17 )
{
if ( V_17 -> V_11 -> V_49 . V_50 )
return F_58 ( V_17 -> V_11 -> V_49 . V_50 ) ;
return NULL ;
}
void F_59 ( struct V_51 * V_52 , struct V_1 * V_1 ,
T_1 (* F_60)( struct V_51 * ,
struct V_20 * , int ) ,
const struct V_12 * V_13 , int V_53 ,
bool V_54 )
{
struct V_16 * V_17 ;
struct V_46 * V_42 ;
T_1 V_55 = 0 ;
F_53 ( & V_1 -> V_38 ) ;
F_54 (blkg, n, &blkcg->blkg_list, blkcg_node)
if ( F_7 ( V_17 -> V_11 , V_13 ) )
V_55 += F_60 ( V_52 , V_17 -> V_21 [ V_13 -> V_14 ] , V_53 ) ;
F_55 ( & V_1 -> V_38 ) ;
if ( V_54 )
F_61 ( V_52 , L_1 , ( unsigned long long ) V_55 ) ;
}
T_1 F_62 ( struct V_51 * V_52 , struct V_20 * V_21 , T_1 V_56 )
{
const char * V_57 = F_57 ( V_21 -> V_17 ) ;
if ( ! V_57 )
return 0 ;
F_61 ( V_52 , L_2 , V_57 , ( unsigned long long ) V_56 ) ;
return V_56 ;
}
T_1 F_63 ( struct V_51 * V_52 , struct V_20 * V_21 ,
const struct V_58 * V_59 )
{
static const char * V_60 [] = {
[ V_61 ] = L_3 ,
[ V_62 ] = L_4 ,
[ V_63 ] = L_5 ,
[ V_64 ] = L_6 ,
} ;
const char * V_57 = F_57 ( V_21 -> V_17 ) ;
T_1 V_56 ;
int V_18 ;
if ( ! V_57 )
return 0 ;
for ( V_18 = 0 ; V_18 < V_65 ; V_18 ++ )
F_61 ( V_52 , L_7 , V_57 , V_60 [ V_18 ] ,
( unsigned long long ) V_59 -> V_66 [ V_18 ] ) ;
V_56 = V_59 -> V_66 [ V_61 ] + V_59 -> V_66 [ V_62 ] ;
F_61 ( V_52 , L_8 , V_57 , ( unsigned long long ) V_56 ) ;
return V_56 ;
}
T_1 F_64 ( struct V_51 * V_52 , struct V_20 * V_21 , int V_67 )
{
return F_62 ( V_52 , V_21 , F_65 ( ( void * ) V_21 + V_67 ) ) ;
}
T_1 F_66 ( struct V_51 * V_52 , struct V_20 * V_21 ,
int V_67 )
{
struct V_58 V_59 = F_67 ( ( void * ) V_21 + V_67 ) ;
return F_63 ( V_52 , V_21 , & V_59 ) ;
}
int F_68 ( struct V_1 * V_1 , const struct V_12 * V_13 ,
const char * V_68 , struct V_69 * V_70 )
__acquires( T_2 ) __acquires( V_71 -> V_72 -> V_32 )
{
struct V_73 * V_71 ;
struct V_16 * V_17 ;
unsigned int V_74 , V_75 ;
unsigned long long V_56 ;
int V_76 , V_33 ;
if ( sscanf ( V_68 , L_9 , & V_74 , & V_75 , & V_56 ) != 3 )
return - V_34 ;
V_71 = F_69 ( F_70 ( V_74 , V_75 ) , & V_76 ) ;
if ( ! V_71 || V_76 )
return - V_34 ;
F_71 () ;
F_53 ( V_71 -> V_72 -> V_32 ) ;
if ( F_7 ( V_71 -> V_72 , V_13 ) )
V_17 = F_36 ( V_1 , V_71 -> V_72 ) ;
else
V_17 = F_26 ( - V_34 ) ;
if ( F_72 ( V_17 ) ) {
V_33 = F_73 ( V_17 ) ;
F_74 () ;
F_55 ( V_71 -> V_72 -> V_32 ) ;
F_75 ( V_71 ) ;
if ( V_33 == - V_41 ) {
F_76 ( 10 ) ;
V_33 = F_77 () ;
}
return V_33 ;
}
V_70 -> V_71 = V_71 ;
V_70 -> V_17 = V_17 ;
V_70 -> V_56 = V_56 ;
return 0 ;
}
void F_78 ( struct V_69 * V_70 )
__releases( V_70 -> V_71 -> V_72 -> V_32 ) __releases( T_2 )
{
F_55 ( V_70 -> V_71 -> V_72 -> V_32 ) ;
F_74 () ;
F_75 ( V_70 -> V_71 ) ;
}
static int F_79 ( struct V_2 * V_2 )
{
struct V_1 * V_1 = F_1 ( V_2 ) ;
F_53 ( & V_1 -> V_38 ) ;
while ( ! F_80 ( & V_1 -> V_40 ) ) {
struct V_16 * V_17 = F_81 ( V_1 -> V_40 . V_77 ,
struct V_16 , V_39 ) ;
struct V_10 * V_11 = V_17 -> V_11 ;
if ( F_82 ( V_11 -> V_32 ) ) {
F_38 ( V_17 ) ;
F_33 ( V_11 -> V_32 ) ;
} else {
F_55 ( & V_1 -> V_38 ) ;
F_83 () ;
F_53 ( & V_1 -> V_38 ) ;
}
}
F_55 ( & V_1 -> V_38 ) ;
return 0 ;
}
static void F_84 ( struct V_2 * V_2 )
{
struct V_1 * V_1 = F_1 ( V_2 ) ;
if ( V_1 != & V_78 )
F_10 ( V_1 ) ;
}
static struct F_3 * F_85 ( struct V_2 * V_2 )
{
static T_3 V_79 = F_86 ( 0 ) ;
struct V_1 * V_1 ;
struct V_2 * V_80 = V_2 -> V_80 ;
if ( ! V_80 ) {
V_1 = & V_78 ;
goto V_81;
}
V_1 = F_87 ( sizeof( * V_1 ) , V_82 ) ;
if ( ! V_1 )
return F_26 ( - V_35 ) ;
V_1 -> V_83 = V_84 ;
V_1 -> V_31 = F_88 ( & V_79 ) ;
V_81:
F_89 ( & V_1 -> V_38 ) ;
F_90 ( & V_1 -> V_30 , V_23 ) ;
F_91 ( & V_1 -> V_40 ) ;
return & V_1 -> V_4 ;
}
int F_92 ( struct V_10 * V_11 )
{
F_93 () ;
return F_94 ( V_11 ) ;
}
void F_95 ( struct V_10 * V_11 )
{
F_23 ( V_11 -> V_32 ) ;
F_96 ( V_11 ) ;
}
void F_97 ( struct V_10 * V_11 )
{
F_53 ( V_11 -> V_32 ) ;
F_46 ( V_11 ) ;
F_55 ( V_11 -> V_32 ) ;
F_98 ( V_11 ) ;
}
static int F_99 ( struct V_2 * V_85 , struct V_86 * V_87 )
{
struct V_5 * V_88 ;
struct V_89 * V_90 ;
int V_33 = 0 ;
F_100 (task, cgrp, tset) {
F_101 ( V_88 ) ;
V_90 = V_88 -> V_89 ;
if ( V_90 && F_102 ( & V_90 -> V_91 ) > 1 )
V_33 = - V_34 ;
F_103 ( V_88 ) ;
if ( V_33 )
break;
}
return V_33 ;
}
int F_104 ( struct V_10 * V_11 ,
const struct V_12 * V_13 )
{
F_105 ( V_92 ) ;
struct V_16 * V_17 ;
struct V_20 * V_21 , * V_42 ;
int V_66 = 0 , V_33 ;
if ( F_7 ( V_11 , V_13 ) )
return 0 ;
F_106 ( V_11 ) ;
F_53 ( V_11 -> V_32 ) ;
F_71 () ;
V_17 = F_22 ( & V_78 , V_11 ) ;
F_74 () ;
if ( F_72 ( V_17 ) ) {
V_33 = F_73 ( V_17 ) ;
goto V_93;
}
V_11 -> V_94 = V_17 ;
F_107 (blkg, &q->blkg_list, q_node)
V_66 ++ ;
F_55 ( V_11 -> V_32 ) ;
while ( V_66 -- ) {
V_21 = F_12 ( V_13 -> V_27 , V_82 , V_11 -> V_24 ) ;
if ( ! V_21 ) {
V_33 = - V_35 ;
goto V_95;
}
F_108 ( & V_21 -> V_96 , & V_92 ) ;
}
F_53 ( V_11 -> V_32 ) ;
F_107 (blkg, &q->blkg_list, q_node) {
if ( F_109 ( F_39 ( & V_92 ) ) ) {
V_33 = - V_35 ;
goto V_93;
}
V_21 = F_110 ( & V_92 , struct V_20 , V_96 ) ;
F_42 ( & V_21 -> V_96 ) ;
F_28 ( & V_17 -> V_1 -> V_38 ) ;
V_17 -> V_21 [ V_13 -> V_14 ] = V_21 ;
V_21 -> V_17 = V_17 ;
V_13 -> V_28 ( V_17 ) ;
F_33 ( & V_17 -> V_1 -> V_38 ) ;
}
F_111 ( V_13 -> V_14 , V_11 -> V_15 ) ;
V_33 = 0 ;
V_93:
F_55 ( V_11 -> V_32 ) ;
V_95:
F_112 ( V_11 ) ;
F_47 (pd, n, &pds, alloc_node)
F_10 ( V_21 ) ;
return V_33 ;
}
void F_113 ( struct V_10 * V_11 ,
const struct V_12 * V_13 )
{
struct V_16 * V_17 ;
if ( ! F_7 ( V_11 , V_13 ) )
return;
F_106 ( V_11 ) ;
F_53 ( V_11 -> V_32 ) ;
F_114 ( V_13 -> V_14 , V_11 -> V_15 ) ;
if ( F_115 ( V_11 -> V_15 , V_19 ) )
F_46 ( V_11 ) ;
F_107 (blkg, &q->blkg_list, q_node) {
F_28 ( & V_17 -> V_1 -> V_38 ) ;
if ( V_13 -> V_22 )
V_13 -> V_22 ( V_17 ) ;
F_10 ( V_17 -> V_21 [ V_13 -> V_14 ] ) ;
V_17 -> V_21 [ V_13 -> V_14 ] = NULL ;
F_33 ( & V_17 -> V_1 -> V_38 ) ;
}
F_55 ( V_11 -> V_32 ) ;
F_112 ( V_11 ) ;
}
int F_116 ( struct V_12 * V_13 )
{
int V_18 , V_33 ;
if ( F_109 ( V_13 -> V_27 < sizeof( struct V_20 ) ) )
return - V_34 ;
F_52 ( & V_47 ) ;
V_33 = - V_97 ;
for ( V_18 = 0 ; V_18 < V_19 ; V_18 ++ )
if ( ! V_12 [ V_18 ] )
break;
if ( V_18 >= V_19 )
goto V_93;
V_13 -> V_14 = V_18 ;
V_12 [ V_18 ] = V_13 ;
if ( V_13 -> V_98 )
F_109 ( F_117 ( & V_99 , V_13 -> V_98 ) ) ;
V_33 = 0 ;
V_93:
F_56 ( & V_47 ) ;
return V_33 ;
}
void F_118 ( struct V_12 * V_13 )
{
F_52 ( & V_47 ) ;
if ( F_109 ( V_12 [ V_13 -> V_14 ] != V_13 ) )
goto V_93;
if ( V_13 -> V_98 )
F_119 ( & V_99 , V_13 -> V_98 ) ;
V_12 [ V_13 -> V_14 ] = NULL ;
V_93:
F_56 ( & V_47 ) ;
}
