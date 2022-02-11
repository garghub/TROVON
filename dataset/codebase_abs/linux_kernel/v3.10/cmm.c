void * F_1 ( struct V_1 * V_2 , T_1 V_3 ,
struct V_4 * V_5 , void * * V_6 )
{
struct V_1 * V_7 = (struct V_1 * ) V_2 ;
void * V_8 = NULL ;
struct V_9 * V_10 = NULL ;
struct V_9 * V_11 = NULL ;
struct V_12 * V_13 = NULL ;
T_1 V_14 ;
T_2 * V_15 = NULL ;
T_3 V_16 ;
if ( V_5 == NULL )
V_5 = & V_17 ;
if ( V_6 != NULL )
* V_6 = NULL ;
if ( V_7 && ( V_3 != 0 ) ) {
if ( V_5 -> V_18 > 0 ) {
V_13 =
F_2 ( V_7 , V_5 -> V_18 ) ;
V_3 =
( ( V_3 - 1 ) & ~ ( V_7 -> V_19 -
1 ) )
+ V_7 -> V_19 ;
F_3 ( & V_7 -> V_20 ) ;
V_10 = F_4 ( V_13 , V_3 ) ;
}
if ( V_10 ) {
V_14 = ( V_10 -> V_21 - V_3 ) ;
if ( V_14 >= V_7 -> V_19 ) {
V_11 =
F_5 ( V_7 , V_10 -> V_22 + V_3 ,
V_10 -> V_23 + V_3 ,
( T_1 ) V_14 ) ;
F_6 ( V_13 , V_11 ) ;
V_10 -> V_21 = V_3 ;
}
V_10 -> V_24 = V_25 -> V_26 ;
F_7 ( & V_10 -> V_27 , & V_13 -> V_28 ) ;
V_8 = ( void * ) V_10 -> V_22 ;
V_15 = ( T_2 * ) V_10 -> V_23 ;
for ( V_16 = 0 ; V_16 < ( T_3 ) V_3 ; V_16 ++ , V_15 ++ )
* V_15 = 0 ;
if ( V_6 != NULL ) {
* V_6 = ( void * ) V_10 -> V_23 ;
}
}
F_8 ( & V_7 -> V_20 ) ;
}
return V_8 ;
}
int F_9 ( struct V_1 * * V_29 ,
struct V_30 * V_31 ,
const struct V_32 * V_33 )
{
struct V_1 * V_34 = NULL ;
int V_35 = 0 ;
* V_29 = NULL ;
V_34 = F_10 ( sizeof( struct V_1 ) , V_36 ) ;
if ( ! V_34 )
return - V_37 ;
if ( V_33 == NULL )
V_33 = & V_38 ;
V_34 -> V_19 = V_33 -> V_19 ;
V_34 -> V_39 = V_40 ;
F_11 ( & V_34 -> V_41 ) ;
F_12 ( & V_34 -> V_20 ) ;
* V_29 = V_34 ;
return V_35 ;
}
int F_13 ( struct V_1 * V_2 , bool V_42 )
{
struct V_1 * V_7 = (struct V_1 * ) V_2 ;
struct V_43 V_44 ;
int V_35 = 0 ;
T_3 V_45 ;
struct V_9 * V_46 , * V_47 ;
if ( ! V_2 ) {
V_35 = - V_48 ;
return V_35 ;
}
F_3 ( & V_7 -> V_20 ) ;
if ( ! V_42 ) {
V_35 = F_14 ( V_2 , & V_44 ) ;
if ( ! V_35 ) {
if ( V_44 . V_49 > 0 ) {
V_35 = - V_50 ;
}
}
}
if ( ! V_35 ) {
for ( V_45 = 0 ; V_45 < V_51 ; V_45 ++ ) {
if ( V_7 -> V_52 [ V_45 ] != NULL ) {
F_15
( V_7 -> V_52 [ V_45 ] ) ;
V_7 -> V_52 [ V_45 ] = NULL ;
}
}
}
F_16 (node, tmp, &cmm_mgr_obj->node_free_list,
link) {
F_17 ( & V_46 -> V_27 ) ;
F_18 ( V_46 ) ;
}
F_8 ( & V_7 -> V_20 ) ;
if ( ! V_35 ) {
F_19 ( & V_7 -> V_20 ) ;
F_18 ( V_7 ) ;
}
return V_35 ;
}
int F_20 ( struct V_1 * V_2 , void * V_8 , T_1 V_53 )
{
struct V_1 * V_7 = (struct V_1 * ) V_2 ;
int V_35 = - V_48 ;
struct V_9 * V_54 , * V_47 ;
struct V_12 * V_13 ;
struct V_4 * V_5 ;
if ( V_53 == 0 ) {
V_5 = & V_17 ;
V_53 = V_5 -> V_18 ;
}
if ( ! V_2 || ! ( V_53 > 0 ) ) {
V_35 = - V_48 ;
return V_35 ;
}
V_13 = F_2 ( V_7 , V_53 ) ;
if ( ! V_13 )
return V_35 ;
F_3 ( & V_7 -> V_20 ) ;
F_16 (curr, tmp, &allocator->in_use_list, link) {
if ( V_54 -> V_22 == ( T_1 ) V_8 ) {
F_17 ( & V_54 -> V_27 ) ;
F_6 ( V_13 , V_54 ) ;
V_35 = 0 ;
break;
}
}
F_8 ( & V_7 -> V_20 ) ;
return V_35 ;
}
int F_21 ( void * V_55 , struct V_1 * * V_29 )
{
int V_35 = 0 ;
struct V_30 * V_31 ;
if ( V_55 != NULL )
V_35 = F_22 ( V_55 , & V_31 ) ;
else
V_31 = F_23 () ;
if ( ! V_35 )
V_35 = F_24 ( V_31 , V_29 ) ;
return V_35 ;
}
int F_14 ( struct V_1 * V_2 ,
struct V_43 * V_56 )
{
struct V_1 * V_7 = (struct V_1 * ) V_2 ;
T_1 V_57 ;
int V_35 = 0 ;
struct V_12 * V_58 ;
struct V_9 * V_54 ;
if ( ! V_2 ) {
V_35 = - V_48 ;
return V_35 ;
}
F_3 ( & V_7 -> V_20 ) ;
V_56 -> V_59 = 0 ;
V_56 -> V_49 = 0 ;
V_56 -> V_19 = V_7 -> V_19 ;
for ( V_57 = 1 ; V_57 <= V_51 ; V_57 ++ ) {
V_58 = F_2 ( V_7 , V_57 ) ;
if ( ! V_58 )
continue;
V_56 -> V_59 ++ ;
V_56 -> V_60 [ V_57 - 1 ] . V_61 =
V_58 -> V_62 - V_58 -> V_63 ;
V_56 -> V_60 [ V_57 - 1 ] . V_64 =
V_58 -> V_63 + V_58 -> V_65 ;
V_56 -> V_60 [ V_57 - 1 ] . V_66 =
V_58 -> V_62 ;
V_56 -> V_60 [ V_57 - 1 ] . V_67 =
V_58 -> V_65 ;
V_56 -> V_60 [ V_57 - 1 ] . V_68 =
V_58 -> V_69 ;
V_56 -> V_60 [ V_57 - 1 ] . V_63 =
V_58 -> V_63 ;
V_56 -> V_60 [ V_57 - 1 ] . V_70 =
V_58 -> V_71 - V_58 -> V_63 ;
V_56 -> V_60 [ V_57 - 1 ] . V_72 = 0 ;
F_25 (curr, &altr->in_use_list, link) {
V_56 -> V_49 ++ ;
V_56 -> V_60 [ V_57 - 1 ] . V_72 ++ ;
}
}
F_8 ( & V_7 -> V_20 ) ;
return V_35 ;
}
int F_26 ( struct V_1 * V_2 ,
T_1 V_73 , T_1 V_74 ,
T_1 V_75 , T_4 V_76 ,
T_1 V_77 , T_1 V_78 ,
T_1 * V_79 , T_1 V_80 )
{
struct V_1 * V_7 = (struct V_1 * ) V_2 ;
struct V_12 * V_81 = NULL ;
int V_35 = 0 ;
struct V_9 * V_11 ;
T_3 V_45 ;
F_27 ( V_82 , L_1
L_2 ,
V_83 , V_73 , V_74 , V_75 ,
V_77 , V_78 , V_80 ) ;
if ( ! V_2 )
return - V_48 ;
F_3 ( & V_7 -> V_20 ) ;
V_45 = F_28 ( V_7 ) ;
if ( V_45 < 0 ) {
V_35 = - V_50 ;
goto V_84;
}
if ( V_74 < V_7 -> V_19 ) {
V_35 = - V_85 ;
goto V_84;
}
V_81 = F_10 ( sizeof( struct V_12 ) , V_36 ) ;
if ( ! V_81 ) {
V_35 = - V_37 ;
goto V_84;
}
V_81 -> V_86 = V_2 ;
V_81 -> V_62 = V_73 ;
V_81 -> V_65 = V_74 ;
V_81 -> V_71 = V_80 ;
V_81 -> V_87 = V_75 ;
V_81 -> V_76 = V_76 ;
V_81 -> V_69 = V_77 ;
V_81 -> V_63 = V_78 ;
if ( V_81 -> V_71 == 0 ) {
V_35 = - V_50 ;
goto V_84;
}
* V_79 = ( T_1 ) V_45 + 1 ;
F_11 ( & V_81 -> V_88 ) ;
F_11 ( & V_81 -> V_28 ) ;
V_11 = F_5 ( V_7 , V_73 ,
V_81 -> V_71 , V_74 ) ;
if ( V_11 ) {
F_7 ( & V_11 -> V_27 , & V_81 -> V_88 ) ;
} else {
V_35 = - V_37 ;
goto V_84;
}
V_7 -> V_52 [ V_45 ] = V_81 ;
V_84:
if ( V_35 && V_81 )
F_15 ( V_81 ) ;
F_8 ( & V_7 -> V_20 ) ;
return V_35 ;
}
int F_29 ( struct V_1 * V_2 ,
T_1 V_53 )
{
struct V_1 * V_7 = (struct V_1 * ) V_2 ;
int V_35 = 0 ;
struct V_12 * V_81 ;
T_1 V_89 = V_53 ;
if ( ! V_2 )
return - V_48 ;
if ( V_53 == V_90 )
V_89 = 1 ;
if ( ( V_89 <= 0 ) || ( V_89 > V_51 ) )
return - V_85 ;
while ( V_89 <= V_51 ) {
F_3 ( & V_7 -> V_20 ) ;
V_81 = V_7 -> V_52 [ V_89 - 1 ] ;
if ( V_81 != NULL ) {
F_15 ( V_81 ) ;
V_7 -> V_52 [ V_89 - 1 ] = NULL ;
} else if ( V_53 != V_90 ) {
V_35 = - V_50 ;
}
F_8 ( & V_7 -> V_20 ) ;
if ( V_53 != V_90 )
break;
V_89 ++ ;
}
return V_35 ;
}
static void F_15 ( struct V_12 * V_81 )
{
struct V_9 * V_54 , * V_47 ;
F_16 (curr, tmp, &psma->free_list, link) {
F_17 ( & V_54 -> V_27 ) ;
F_18 ( V_54 ) ;
}
F_16 (curr, tmp, &psma->in_use_list, link) {
F_17 ( & V_54 -> V_27 ) ;
F_18 ( V_54 ) ;
}
if ( ( void * ) V_81 -> V_71 != NULL )
F_30 ( ( void * ) V_81 -> V_71 ) ;
F_18 ( V_81 ) ;
}
static T_3 F_28 ( struct V_1 * V_7 )
{
T_3 V_45 = - 1 ;
for ( V_45 = 0 ; V_45 < V_51 ; V_45 ++ ) {
if ( V_7 -> V_52 [ V_45 ] == NULL )
break;
}
if ( V_45 == V_51 )
V_45 = - 1 ;
return V_45 ;
}
static struct V_9 * F_5 ( struct V_1 * V_7 , T_1 V_91 ,
T_1 V_92 , T_1 V_74 )
{
struct V_9 * V_10 ;
if ( F_31 ( & V_7 -> V_41 ) ) {
V_10 = F_10 ( sizeof( struct V_9 ) , V_36 ) ;
if ( ! V_10 )
return NULL ;
} else {
V_10 = F_32 ( & V_7 -> V_41 ,
struct V_9 , V_27 ) ;
F_33 ( & V_10 -> V_27 ) ;
}
V_10 -> V_22 = V_91 ;
V_10 -> V_23 = V_92 ;
V_10 -> V_21 = V_74 ;
return V_10 ;
}
static void F_34 ( struct V_1 * V_7 , struct V_9 * V_10 )
{
F_7 ( & V_10 -> V_27 , & V_7 -> V_41 ) ;
}
static struct V_9 * F_4 ( struct V_12 * V_13 ,
T_1 V_3 )
{
struct V_9 * V_46 , * V_47 ;
if ( ! V_13 )
return NULL ;
F_16 (node, tmp, &allocator->free_list, link) {
if ( V_3 <= V_46 -> V_21 ) {
F_17 ( & V_46 -> V_27 ) ;
return V_46 ;
}
}
return NULL ;
}
static void F_6 ( struct V_12 * V_13 ,
struct V_9 * V_46 )
{
struct V_9 * V_54 ;
if ( ! V_46 ) {
F_35 ( L_3 , V_83 ) ;
return;
}
F_25 (curr, &allocator->free_list, link) {
if ( F_36 ( V_54 ) == V_46 -> V_22 ) {
V_54 -> V_21 += V_46 -> V_21 ;
F_34 ( V_13 -> V_86 , V_46 ) ;
return;
}
if ( V_54 -> V_22 == F_36 ( V_46 ) ) {
V_54 -> V_22 = V_46 -> V_22 ;
V_54 -> V_23 = V_46 -> V_23 ;
V_54 -> V_21 += V_46 -> V_21 ;
F_34 ( V_13 -> V_86 , V_46 ) ;
return;
}
}
F_25 (curr, &allocator->free_list, link) {
if ( V_54 -> V_21 >= V_46 -> V_21 ) {
F_7 ( & V_46 -> V_27 , & V_54 -> V_27 ) ;
return;
}
}
F_7 ( & V_46 -> V_27 , & V_13 -> V_88 ) ;
}
static struct V_12 * F_2 ( struct V_1 * V_7 ,
T_1 V_53 )
{
return V_7 -> V_52 [ V_53 - 1 ] ;
}
int F_37 ( struct V_93 * * V_94 ,
struct V_1 * V_2 ,
struct V_95 * V_96 )
{
struct V_97 * V_98 = NULL ;
int V_35 = 0 ;
* V_94 = NULL ;
if ( V_96 == NULL )
V_96 = & V_99 ;
V_98 = F_10 ( sizeof( struct V_97 ) , V_36 ) ;
if ( V_98 != NULL ) {
V_98 -> V_86 = V_2 ;
V_98 -> V_18 = V_96 -> V_18 ;
} else {
V_35 = - V_37 ;
}
if ( ! V_35 )
* V_94 = (struct V_93 * ) V_98 ;
return V_35 ;
}
void * F_38 ( struct V_93 * V_94 , void * V_100 ,
T_1 V_101 )
{
struct V_97 * V_102 = (struct V_97 * ) V_94 ;
void * V_103 = NULL ;
void * V_104 ;
struct V_4 V_105 ;
if ( V_102 ) {
V_105 . V_18 = V_102 -> V_18 ;
F_39 ( 0 , V_100 ) ;
V_103 =
F_1 ( V_102 -> V_86 , V_101 , & V_105 , NULL ) ;
if ( V_103 ) {
V_104 = F_40 ( V_94 ,
V_103 , V_106 ) ;
F_39 ( ( T_1 ) V_104 , V_100 ) ;
}
}
return V_103 ;
}
int F_41 ( struct V_93 * V_94 , void * V_107 )
{
struct V_97 * V_102 = (struct V_97 * ) V_94 ;
int V_35 = - V_50 ;
void * V_8 = NULL ;
if ( V_102 ) {
V_8 = F_40 ( V_94 , V_107 , V_108 ) ;
if ( V_8 ) {
V_35 = F_20 ( V_102 -> V_86 , V_8 ,
V_102 -> V_18 ) ;
if ( V_35 ) {
F_35 ( L_4 ,
__FILE__ , __LINE__ ) ;
}
}
}
return V_35 ;
}
int F_42 ( struct V_93 * V_94 , T_2 * * V_109 ,
T_1 V_74 , T_1 V_110 , bool V_111 )
{
struct V_97 * V_102 = (struct V_97 * ) V_94 ;
int V_35 = 0 ;
if ( V_102 ) {
if ( V_111 ) {
V_102 -> V_112 = ( T_1 ) * V_109 ;
V_102 -> V_113 = V_74 ;
} else {
* V_109 = ( T_2 * ) V_102 -> V_112 ;
}
} else {
V_35 = - V_48 ;
}
return V_35 ;
}
void * F_40 ( struct V_93 * V_94 , void * V_109 ,
enum V_114 V_115 )
{
T_1 V_116 = 0 ;
struct V_97 * V_102 = (struct V_97 * ) V_94 ;
struct V_1 * V_7 = NULL ;
struct V_12 * V_13 = NULL ;
T_1 V_117 = 0 ;
if ( ! V_102 )
goto V_118;
V_7 = (struct V_1 * ) V_102 -> V_86 ;
V_13 = V_7 -> V_52 [ V_102 -> V_18 - 1 ] ;
if ( ! V_13 )
goto V_118;
if ( ( V_115 == V_119 ) || ( V_115 == V_108 ) ||
( V_115 == V_106 ) ) {
if ( V_115 == V_106 ) {
V_117 = ( T_2 * ) V_109 - ( T_2 * ) ( V_13 -> V_62 -
V_13 ->
V_63 ) ;
V_116 = V_102 -> V_112 + V_117 ;
if ( ( V_116 < V_102 -> V_112 ) ||
( V_116 >=
( V_102 -> V_112 +
V_102 -> V_113 ) ) ) {
V_116 = 0 ;
}
} else {
V_117 =
( T_2 * ) V_109 - ( T_2 * ) V_102 -> V_112 ;
V_116 =
V_13 -> V_62 - V_13 -> V_63 +
V_117 ;
}
} else {
V_116 = ( T_1 ) V_109 ;
}
if ( ( V_115 == V_119 ) || ( V_115 == V_120 ) ) {
V_116 =
F_43 ( ( V_13 -> V_62 - V_13 -> V_63 ) ,
V_116 ,
V_13 -> V_87 *
V_13 -> V_76 ) ;
} else if ( V_115 == V_121 ) {
V_116 =
F_44 ( V_13 -> V_62 - V_13 -> V_63 ,
V_116 ,
V_13 -> V_87 *
V_13 -> V_76 ) ;
}
V_118:
return ( void * ) V_116 ;
}
