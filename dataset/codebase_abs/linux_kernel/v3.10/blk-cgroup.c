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
V_12 -> V_5 = V_9 ;
if ( V_4 -> V_23 )
V_4 -> V_23 ( V_8 ) ;
}
return V_8 ;
V_21:
F_3 ( V_8 ) ;
return NULL ;
}
static struct V_7 * F_10 ( struct V_15 * V_15 ,
struct V_1 * V_2 , bool V_24 )
{
struct V_7 * V_8 ;
V_8 = F_11 ( V_15 -> V_25 ) ;
if ( V_8 && V_8 -> V_2 == V_2 )
return V_8 ;
V_8 = F_12 ( & V_15 -> V_26 , V_2 -> V_27 ) ;
if ( V_8 && V_8 -> V_2 == V_2 ) {
if ( V_24 ) {
F_13 ( V_2 -> V_28 ) ;
F_14 ( V_15 -> V_25 , V_8 ) ;
}
return V_8 ;
}
return NULL ;
}
struct V_7 * F_15 ( struct V_15 * V_15 , struct V_1 * V_2 )
{
F_16 ( ! F_17 () ) ;
if ( F_18 ( F_19 ( V_2 ) ) )
return NULL ;
return F_10 ( V_15 , V_2 , false ) ;
}
static struct V_7 * F_20 ( struct V_15 * V_15 ,
struct V_1 * V_2 ,
struct V_7 * V_29 )
{
struct V_7 * V_8 ;
int V_9 , V_30 ;
F_16 ( ! F_17 () ) ;
F_13 ( V_2 -> V_28 ) ;
if ( ! F_21 ( & V_15 -> V_31 ) ) {
V_30 = - V_32 ;
goto V_33;
}
if ( ! V_29 ) {
V_29 = F_6 ( V_15 , V_2 , V_34 ) ;
if ( F_18 ( ! V_29 ) ) {
V_30 = - V_35 ;
goto V_36;
}
}
V_8 = V_29 ;
if ( F_22 ( V_15 ) ) {
V_8 -> V_37 = F_10 ( F_22 ( V_15 ) , V_2 , false ) ;
if ( F_16 ( ! V_8 -> V_37 ) ) {
V_8 = F_23 ( - V_32 ) ;
goto V_36;
}
F_24 ( V_8 -> V_37 ) ;
}
F_25 ( & V_15 -> V_38 ) ;
V_30 = F_26 ( & V_15 -> V_26 , V_2 -> V_27 , V_8 ) ;
if ( F_27 ( ! V_30 ) ) {
F_28 ( & V_8 -> V_39 , & V_15 -> V_40 ) ;
F_29 ( & V_8 -> V_18 , & V_2 -> V_40 ) ;
for ( V_9 = 0 ; V_9 < V_10 ; V_9 ++ ) {
struct V_3 * V_4 = V_3 [ V_9 ] ;
if ( V_8 -> V_12 [ V_9 ] && V_4 -> V_41 )
V_4 -> V_41 ( V_8 ) ;
}
}
V_8 -> V_42 = true ;
F_30 ( & V_15 -> V_38 ) ;
if ( ! V_30 )
return V_8 ;
F_31 ( V_8 ) ;
return F_23 ( V_30 ) ;
V_36:
F_32 ( & V_15 -> V_31 ) ;
V_33:
F_3 ( V_29 ) ;
return F_23 ( V_30 ) ;
}
struct V_7 * F_33 ( struct V_15 * V_15 ,
struct V_1 * V_2 )
{
struct V_7 * V_8 ;
F_16 ( ! F_17 () ) ;
F_13 ( V_2 -> V_28 ) ;
if ( F_18 ( F_19 ( V_2 ) ) )
return F_23 ( F_34 ( V_2 ) ? - V_32 : - V_43 ) ;
V_8 = F_10 ( V_15 , V_2 , true ) ;
if ( V_8 )
return V_8 ;
while ( true ) {
struct V_15 * V_44 = V_15 ;
struct V_15 * V_37 = F_22 ( V_15 ) ;
while ( V_37 && ! F_10 ( V_37 , V_2 , false ) ) {
V_44 = V_37 ;
V_37 = F_22 ( V_37 ) ;
}
V_8 = F_20 ( V_44 , V_2 , NULL ) ;
if ( V_44 == V_15 || F_35 ( V_8 ) )
return V_8 ;
}
}
static void F_36 ( struct V_7 * V_8 )
{
struct V_15 * V_15 = V_8 -> V_15 ;
int V_9 ;
F_13 ( V_8 -> V_2 -> V_28 ) ;
F_13 ( & V_15 -> V_38 ) ;
F_16 ( F_37 ( & V_8 -> V_18 ) ) ;
F_16 ( F_38 ( & V_8 -> V_39 ) ) ;
for ( V_9 = 0 ; V_9 < V_10 ; V_9 ++ ) {
struct V_3 * V_4 = V_3 [ V_9 ] ;
if ( V_8 -> V_12 [ V_9 ] && V_4 -> V_45 )
V_4 -> V_45 ( V_8 ) ;
}
V_8 -> V_42 = false ;
F_39 ( & V_15 -> V_26 , V_8 -> V_2 -> V_27 ) ;
F_40 ( & V_8 -> V_18 ) ;
F_41 ( & V_8 -> V_39 ) ;
if ( F_42 ( V_15 -> V_25 ) == V_8 )
F_14 ( V_15 -> V_25 , NULL ) ;
F_31 ( V_8 ) ;
}
static void F_43 ( struct V_1 * V_2 )
{
struct V_7 * V_8 , * V_46 ;
F_13 ( V_2 -> V_28 ) ;
F_44 (blkg, n, &q->blkg_list, q_node) {
struct V_15 * V_15 = V_8 -> V_15 ;
F_25 ( & V_15 -> V_38 ) ;
F_36 ( V_8 ) ;
F_30 ( & V_15 -> V_38 ) ;
}
V_2 -> V_47 = NULL ;
V_2 -> V_48 . V_8 = NULL ;
}
static void F_45 ( struct V_49 * V_49 )
{
F_3 ( F_46 ( V_49 , struct V_7 , V_49 ) ) ;
}
void F_47 ( struct V_7 * V_8 )
{
F_32 ( & V_8 -> V_15 -> V_31 ) ;
if ( V_8 -> V_37 )
F_31 ( V_8 -> V_37 ) ;
F_48 ( & V_8 -> V_49 , F_45 ) ;
}
struct V_50 * F_49 ( struct V_50 * V_14 ,
struct V_1 * V_2 )
{
struct V_51 * V_52 ;
struct V_7 * V_8 ;
if ( V_14 == & V_2 -> V_48 ) {
V_52 = & V_2 -> V_40 ;
if ( F_37 ( V_52 ) )
return NULL ;
} else {
V_8 = F_46 ( V_14 , struct V_7 , V_14 ) ;
V_52 = & V_8 -> V_18 ;
}
V_52 = V_52 -> V_53 ;
if ( V_52 == & V_2 -> V_47 -> V_18 )
V_52 = V_52 -> V_53 ;
if ( V_52 == & V_2 -> V_40 )
return NULL ;
V_8 = F_46 ( V_52 , struct V_7 , V_18 ) ;
return & V_8 -> V_14 ;
}
static int F_50 ( struct V_54 * V_54 , struct V_55 * V_55 ,
T_2 V_56 )
{
struct V_15 * V_15 = F_51 ( V_54 ) ;
struct V_7 * V_8 ;
int V_9 ;
F_52 ( & V_57 ) ;
F_53 ( & V_15 -> V_38 ) ;
F_54 (blkg, &blkcg->blkg_list, blkcg_node) {
for ( V_9 = 0 ; V_9 < V_10 ; V_9 ++ ) {
struct V_3 * V_4 = V_3 [ V_9 ] ;
if ( F_1 ( V_8 -> V_2 , V_4 ) &&
V_4 -> V_58 )
V_4 -> V_58 ( V_8 ) ;
}
}
F_55 ( & V_15 -> V_38 ) ;
F_56 ( & V_57 ) ;
return 0 ;
}
static const char * F_57 ( struct V_7 * V_8 )
{
if ( V_8 -> V_2 -> V_59 . V_60 )
return F_58 ( V_8 -> V_2 -> V_59 . V_60 ) ;
return NULL ;
}
void F_59 ( struct V_61 * V_62 , struct V_15 * V_15 ,
T_2 (* F_60)( struct V_61 * ,
struct V_11 * , int ) ,
const struct V_3 * V_4 , int V_63 ,
bool V_64 )
{
struct V_7 * V_8 ;
T_2 V_65 = 0 ;
F_61 () ;
F_62 (blkg, &blkcg->blkg_list, blkcg_node) {
F_53 ( V_8 -> V_2 -> V_28 ) ;
if ( F_1 ( V_8 -> V_2 , V_4 ) )
V_65 += F_60 ( V_62 , V_8 -> V_12 [ V_4 -> V_5 ] , V_63 ) ;
F_55 ( V_8 -> V_2 -> V_28 ) ;
}
F_63 () ;
if ( V_64 )
F_64 ( V_62 , L_1 , ( unsigned long long ) V_65 ) ;
}
T_2 F_65 ( struct V_61 * V_62 , struct V_11 * V_12 , T_2 V_66 )
{
const char * V_67 = F_57 ( V_12 -> V_8 ) ;
if ( ! V_67 )
return 0 ;
F_64 ( V_62 , L_2 , V_67 , ( unsigned long long ) V_66 ) ;
return V_66 ;
}
T_2 F_66 ( struct V_61 * V_62 , struct V_11 * V_12 ,
const struct V_68 * V_69 )
{
static const char * V_70 [] = {
[ V_71 ] = L_3 ,
[ V_72 ] = L_4 ,
[ V_73 ] = L_5 ,
[ V_74 ] = L_6 ,
} ;
const char * V_67 = F_57 ( V_12 -> V_8 ) ;
T_2 V_66 ;
int V_9 ;
if ( ! V_67 )
return 0 ;
for ( V_9 = 0 ; V_9 < V_75 ; V_9 ++ )
F_64 ( V_62 , L_7 , V_67 , V_70 [ V_9 ] ,
( unsigned long long ) V_69 -> V_76 [ V_9 ] ) ;
V_66 = V_69 -> V_76 [ V_71 ] + V_69 -> V_76 [ V_72 ] ;
F_64 ( V_62 , L_8 , V_67 , ( unsigned long long ) V_66 ) ;
return V_66 ;
}
T_2 F_67 ( struct V_61 * V_62 , struct V_11 * V_12 , int V_77 )
{
return F_65 ( V_62 , V_12 , F_68 ( ( void * ) V_12 + V_77 ) ) ;
}
T_2 F_69 ( struct V_61 * V_62 , struct V_11 * V_12 ,
int V_77 )
{
struct V_68 V_69 = F_70 ( ( void * ) V_12 + V_77 ) ;
return F_66 ( V_62 , V_12 , & V_69 ) ;
}
T_2 F_71 ( struct V_11 * V_12 , int V_77 )
{
struct V_3 * V_4 = V_3 [ V_12 -> V_5 ] ;
struct V_7 * V_78 ;
struct V_54 * V_79 ;
T_2 V_80 ;
F_13 ( V_12 -> V_8 -> V_2 -> V_28 ) ;
V_80 = F_68 ( ( void * ) V_12 + V_77 ) ;
F_61 () ;
F_72 (pos_blkg, pos_cgrp, pd_to_blkg(pd)) {
struct V_11 * V_81 = F_73 ( V_78 , V_4 ) ;
struct V_82 * V_83 = ( void * ) V_81 + V_77 ;
if ( V_78 -> V_42 )
V_80 += F_68 ( V_83 ) ;
}
F_63 () ;
return V_80 ;
}
struct V_68 F_74 ( struct V_11 * V_12 ,
int V_77 )
{
struct V_3 * V_4 = V_3 [ V_12 -> V_5 ] ;
struct V_7 * V_78 ;
struct V_54 * V_79 ;
struct V_68 V_80 ;
int V_9 ;
F_13 ( V_12 -> V_8 -> V_2 -> V_28 ) ;
V_80 = F_70 ( ( void * ) V_12 + V_77 ) ;
F_61 () ;
F_72 (pos_blkg, pos_cgrp, pd_to_blkg(pd)) {
struct V_11 * V_81 = F_73 ( V_78 , V_4 ) ;
struct V_68 * V_69 = ( void * ) V_81 + V_77 ;
struct V_68 V_84 ;
if ( ! V_78 -> V_42 )
continue;
V_84 = F_70 ( V_69 ) ;
for ( V_9 = 0 ; V_9 < V_75 ; V_9 ++ )
V_80 . V_76 [ V_9 ] += V_84 . V_76 [ V_9 ] ;
}
F_63 () ;
return V_80 ;
}
int F_75 ( struct V_15 * V_15 , const struct V_3 * V_4 ,
const char * V_85 , struct V_86 * V_87 )
__acquires( T_3 ) __acquires( V_88 -> V_89 -> V_28 )
{
struct V_90 * V_88 ;
struct V_7 * V_8 ;
unsigned int V_91 , V_92 ;
unsigned long long V_66 ;
int V_93 , V_30 ;
if ( sscanf ( V_85 , L_9 , & V_91 , & V_92 , & V_66 ) != 3 )
return - V_32 ;
V_88 = F_76 ( F_77 ( V_91 , V_92 ) , & V_93 ) ;
if ( ! V_88 || V_93 )
return - V_32 ;
F_61 () ;
F_53 ( V_88 -> V_89 -> V_28 ) ;
if ( F_1 ( V_88 -> V_89 , V_4 ) )
V_8 = F_33 ( V_15 , V_88 -> V_89 ) ;
else
V_8 = F_23 ( - V_32 ) ;
if ( F_35 ( V_8 ) ) {
V_30 = F_78 ( V_8 ) ;
F_63 () ;
F_55 ( V_88 -> V_89 -> V_28 ) ;
F_79 ( V_88 ) ;
if ( V_30 == - V_43 ) {
F_80 ( 10 ) ;
V_30 = F_81 () ;
}
return V_30 ;
}
V_87 -> V_88 = V_88 ;
V_87 -> V_8 = V_8 ;
V_87 -> V_66 = V_66 ;
return 0 ;
}
void F_82 ( struct V_86 * V_87 )
__releases( V_87 -> V_88 -> V_89 -> V_28 ) __releases( T_3 )
{
F_55 ( V_87 -> V_88 -> V_89 -> V_28 ) ;
F_63 () ;
F_79 ( V_87 -> V_88 ) ;
}
static void F_83 ( struct V_54 * V_54 )
{
struct V_15 * V_15 = F_51 ( V_54 ) ;
F_53 ( & V_15 -> V_38 ) ;
while ( ! F_84 ( & V_15 -> V_40 ) ) {
struct V_7 * V_8 = F_85 ( V_15 -> V_40 . V_94 ,
struct V_7 , V_39 ) ;
struct V_1 * V_2 = V_8 -> V_2 ;
if ( F_86 ( V_2 -> V_28 ) ) {
F_36 ( V_8 ) ;
F_30 ( V_2 -> V_28 ) ;
} else {
F_55 ( & V_15 -> V_38 ) ;
F_87 () ;
F_53 ( & V_15 -> V_38 ) ;
}
}
F_55 ( & V_15 -> V_38 ) ;
}
static void F_88 ( struct V_54 * V_54 )
{
struct V_15 * V_15 = F_51 ( V_54 ) ;
if ( V_15 != & V_20 )
F_4 ( V_15 ) ;
}
static struct V_95 * F_89 ( struct V_54 * V_54 )
{
static T_4 V_96 = F_90 ( 0 ) ;
struct V_15 * V_15 ;
struct V_54 * V_37 = V_54 -> V_37 ;
if ( ! V_37 ) {
V_15 = & V_20 ;
goto V_97;
}
V_15 = F_91 ( sizeof( * V_15 ) , V_98 ) ;
if ( ! V_15 )
return F_23 ( - V_35 ) ;
V_15 -> V_99 = V_100 ;
V_15 -> V_101 = V_100 ;
V_15 -> V_27 = F_92 ( & V_96 ) ;
V_97:
F_93 ( & V_15 -> V_38 ) ;
F_94 ( & V_15 -> V_26 , V_34 ) ;
F_95 ( & V_15 -> V_40 ) ;
return & V_15 -> V_31 ;
}
int F_96 ( struct V_1 * V_2 )
{
F_97 () ;
return F_98 ( V_2 ) ;
}
void F_99 ( struct V_1 * V_2 )
{
F_13 ( V_2 -> V_28 ) ;
F_100 ( V_2 ) ;
}
void F_101 ( struct V_1 * V_2 )
{
F_53 ( V_2 -> V_28 ) ;
F_43 ( V_2 ) ;
F_55 ( V_2 -> V_28 ) ;
F_102 ( V_2 ) ;
}
static int F_103 ( struct V_54 * V_102 , struct V_103 * V_104 )
{
struct V_105 * V_106 ;
struct V_107 * V_108 ;
int V_30 = 0 ;
F_104 (task, cgrp, tset) {
F_105 ( V_106 ) ;
V_108 = V_106 -> V_107 ;
if ( V_108 && F_106 ( & V_108 -> V_109 ) > 1 )
V_30 = - V_32 ;
F_107 ( V_106 ) ;
if ( V_30 )
break;
}
return V_30 ;
}
int F_108 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
F_109 ( V_110 ) ;
struct V_7 * V_8 , * V_29 ;
struct V_11 * V_12 , * V_46 ;
int V_76 = 0 , V_30 ;
bool V_111 ;
if ( F_1 ( V_2 , V_4 ) )
return 0 ;
V_29 = F_6 ( & V_20 , V_2 , V_98 ) ;
if ( ! V_29 )
return - V_35 ;
F_110 ( V_2 ) ;
V_111 = ! F_111 ( V_98 ) ;
F_53 ( V_2 -> V_28 ) ;
F_61 () ;
V_8 = F_10 ( & V_20 , V_2 , false ) ;
if ( V_8 )
F_3 ( V_29 ) ;
else
V_8 = F_20 ( & V_20 , V_2 , V_29 ) ;
F_63 () ;
if ( V_111 )
F_112 () ;
if ( F_35 ( V_8 ) ) {
V_30 = F_78 ( V_8 ) ;
goto V_112;
}
V_2 -> V_47 = V_8 ;
V_2 -> V_48 . V_8 = V_8 ;
F_113 (blkg, &q->blkg_list, q_node)
V_76 ++ ;
F_55 ( V_2 -> V_28 ) ;
while ( V_76 -- ) {
V_12 = F_7 ( V_4 -> V_22 , V_98 , V_2 -> V_17 ) ;
if ( ! V_12 ) {
V_30 = - V_35 ;
goto V_113;
}
F_114 ( & V_12 -> V_114 , & V_110 ) ;
}
F_53 ( V_2 -> V_28 ) ;
F_113 (blkg, &q->blkg_list, q_node) {
if ( F_115 ( F_37 ( & V_110 ) ) ) {
V_30 = - V_35 ;
goto V_112;
}
V_12 = F_116 ( & V_110 , struct V_11 , V_114 ) ;
F_40 ( & V_12 -> V_114 ) ;
F_25 ( & V_8 -> V_15 -> V_38 ) ;
V_8 -> V_12 [ V_4 -> V_5 ] = V_12 ;
V_12 -> V_8 = V_8 ;
V_12 -> V_5 = V_4 -> V_5 ;
V_4 -> V_23 ( V_8 ) ;
F_30 ( & V_8 -> V_15 -> V_38 ) ;
}
F_117 ( V_4 -> V_5 , V_2 -> V_6 ) ;
V_30 = 0 ;
V_112:
F_55 ( V_2 -> V_28 ) ;
V_113:
F_118 ( V_2 ) ;
F_44 (pd, n, &pds, alloc_node)
F_4 ( V_12 ) ;
return V_30 ;
}
void F_119 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
struct V_7 * V_8 ;
if ( ! F_1 ( V_2 , V_4 ) )
return;
F_110 ( V_2 ) ;
F_53 ( V_2 -> V_28 ) ;
F_120 ( V_4 -> V_5 , V_2 -> V_6 ) ;
if ( F_121 ( V_2 -> V_6 , V_10 ) )
F_43 ( V_2 ) ;
F_113 (blkg, &q->blkg_list, q_node) {
F_25 ( & V_8 -> V_15 -> V_38 ) ;
if ( V_4 -> V_45 )
V_4 -> V_45 ( V_8 ) ;
if ( V_4 -> V_13 )
V_4 -> V_13 ( V_8 ) ;
F_4 ( V_8 -> V_12 [ V_4 -> V_5 ] ) ;
V_8 -> V_12 [ V_4 -> V_5 ] = NULL ;
F_30 ( & V_8 -> V_15 -> V_38 ) ;
}
F_55 ( V_2 -> V_28 ) ;
F_118 ( V_2 ) ;
}
int F_122 ( struct V_3 * V_4 )
{
int V_9 , V_30 ;
if ( F_115 ( V_4 -> V_22 < sizeof( struct V_11 ) ) )
return - V_32 ;
F_52 ( & V_57 ) ;
V_30 = - V_115 ;
for ( V_9 = 0 ; V_9 < V_10 ; V_9 ++ )
if ( ! V_3 [ V_9 ] )
break;
if ( V_9 >= V_10 )
goto V_112;
V_4 -> V_5 = V_9 ;
V_3 [ V_9 ] = V_4 ;
if ( V_4 -> V_116 )
F_115 ( F_123 ( & V_117 , V_4 -> V_116 ) ) ;
V_30 = 0 ;
V_112:
F_56 ( & V_57 ) ;
return V_30 ;
}
void F_124 ( struct V_3 * V_4 )
{
F_52 ( & V_57 ) ;
if ( F_115 ( V_3 [ V_4 -> V_5 ] != V_4 ) )
goto V_112;
if ( V_4 -> V_116 )
F_125 ( & V_117 , V_4 -> V_116 ) ;
V_3 [ V_4 -> V_5 ] = NULL ;
V_112:
F_56 ( & V_57 ) ;
}
