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
F_10 ( V_36 > 0 ) ;
F_10 ( V_29 != NULL ) ;
* V_29 = NULL ;
V_34 = F_11 ( sizeof( struct V_1 ) , V_37 ) ;
if ( ! V_34 )
return - V_38 ;
if ( V_33 == NULL )
V_33 = & V_39 ;
F_12 ( V_33 -> V_19 >= 4 ) ;
V_34 -> V_19 = V_33 -> V_19 ;
V_34 -> V_40 = V_41 ;
F_13 ( & V_34 -> V_42 ) ;
F_14 ( & V_34 -> V_20 ) ;
* V_29 = V_34 ;
return V_35 ;
}
int F_15 ( struct V_1 * V_2 , bool V_43 )
{
struct V_1 * V_7 = (struct V_1 * ) V_2 ;
struct V_44 V_45 ;
int V_35 = 0 ;
T_3 V_46 ;
struct V_9 * V_47 , * V_48 ;
F_10 ( V_36 > 0 ) ;
if ( ! V_2 ) {
V_35 = - V_49 ;
return V_35 ;
}
F_3 ( & V_7 -> V_20 ) ;
if ( ! V_43 ) {
V_35 = F_16 ( V_2 , & V_45 ) ;
if ( ! V_35 ) {
if ( V_45 . V_50 > 0 ) {
V_35 = - V_51 ;
}
}
}
if ( ! V_35 ) {
for ( V_46 = 0 ; V_46 < V_52 ; V_46 ++ ) {
if ( V_7 -> V_53 [ V_46 ] != NULL ) {
F_17
( V_7 -> V_53 [ V_46 ] ) ;
V_7 -> V_53 [ V_46 ] = NULL ;
}
}
}
F_18 (node, tmp, &cmm_mgr_obj->node_free_list,
link) {
F_19 ( & V_47 -> V_27 ) ;
F_20 ( V_47 ) ;
}
F_8 ( & V_7 -> V_20 ) ;
if ( ! V_35 ) {
F_21 ( & V_7 -> V_20 ) ;
F_20 ( V_7 ) ;
}
return V_35 ;
}
void F_22 ( void )
{
F_10 ( V_36 > 0 ) ;
V_36 -- ;
}
int F_23 ( struct V_1 * V_2 , void * V_8 , T_1 V_54 )
{
struct V_1 * V_7 = (struct V_1 * ) V_2 ;
int V_35 = - V_49 ;
struct V_9 * V_55 , * V_48 ;
struct V_12 * V_13 ;
struct V_4 * V_5 ;
F_10 ( V_36 > 0 ) ;
F_10 ( V_8 != NULL ) ;
if ( V_54 == 0 ) {
V_5 = & V_17 ;
V_54 = V_5 -> V_18 ;
}
if ( ! V_2 || ! ( V_54 > 0 ) ) {
V_35 = - V_49 ;
return V_35 ;
}
V_13 = F_2 ( V_7 , V_54 ) ;
if ( ! V_13 )
return V_35 ;
F_3 ( & V_7 -> V_20 ) ;
F_18 (curr, tmp, &allocator->in_use_list, link) {
if ( V_55 -> V_22 == ( T_1 ) V_8 ) {
F_19 ( & V_55 -> V_27 ) ;
F_6 ( V_13 , V_55 ) ;
V_35 = 0 ;
break;
}
}
F_8 ( & V_7 -> V_20 ) ;
return V_35 ;
}
int F_24 ( void * V_56 , struct V_1 * * V_29 )
{
int V_35 = 0 ;
struct V_30 * V_31 ;
F_10 ( V_36 > 0 ) ;
F_10 ( V_29 != NULL ) ;
if ( V_56 != NULL )
V_35 = F_25 ( V_56 , & V_31 ) ;
else
V_31 = F_26 () ;
if ( ! V_35 )
V_35 = F_27 ( V_31 , V_29 ) ;
return V_35 ;
}
int F_16 ( struct V_1 * V_2 ,
struct V_44 * V_57 )
{
struct V_1 * V_7 = (struct V_1 * ) V_2 ;
T_1 V_58 ;
int V_35 = 0 ;
struct V_12 * V_59 ;
struct V_9 * V_55 ;
F_10 ( V_57 != NULL ) ;
if ( ! V_2 ) {
V_35 = - V_49 ;
return V_35 ;
}
F_3 ( & V_7 -> V_20 ) ;
V_57 -> V_60 = 0 ;
V_57 -> V_50 = 0 ;
V_57 -> V_19 = V_7 -> V_19 ;
for ( V_58 = 1 ; V_58 <= V_52 ; V_58 ++ ) {
V_59 = F_2 ( V_7 , V_58 ) ;
if ( ! V_59 )
continue;
V_57 -> V_60 ++ ;
V_57 -> V_61 [ V_58 - 1 ] . V_62 =
V_59 -> V_63 - V_59 -> V_64 ;
V_57 -> V_61 [ V_58 - 1 ] . V_65 =
V_59 -> V_64 + V_59 -> V_66 ;
V_57 -> V_61 [ V_58 - 1 ] . V_67 =
V_59 -> V_63 ;
V_57 -> V_61 [ V_58 - 1 ] . V_68 =
V_59 -> V_66 ;
V_57 -> V_61 [ V_58 - 1 ] . V_69 =
V_59 -> V_70 ;
V_57 -> V_61 [ V_58 - 1 ] . V_64 =
V_59 -> V_64 ;
V_57 -> V_61 [ V_58 - 1 ] . V_71 =
V_59 -> V_72 - V_59 -> V_64 ;
V_57 -> V_61 [ V_58 - 1 ] . V_73 = 0 ;
F_28 (curr, &altr->in_use_list, link) {
V_57 -> V_50 ++ ;
V_57 -> V_61 [ V_58 - 1 ] . V_73 ++ ;
}
}
F_8 ( & V_7 -> V_20 ) ;
return V_35 ;
}
bool F_29 ( void )
{
bool V_74 = true ;
F_10 ( V_36 >= 0 ) ;
if ( V_74 )
V_36 ++ ;
F_30 ( ( V_74 && ( V_36 > 0 ) ) || ( ! V_74 && ( V_36 >= 0 ) ) ) ;
return V_74 ;
}
int F_31 ( struct V_1 * V_2 ,
T_1 V_75 , T_1 V_76 ,
T_1 V_77 , T_4 V_78 ,
T_1 V_79 , T_1 V_80 ,
T_1 * V_81 , T_1 V_82 )
{
struct V_1 * V_7 = (struct V_1 * ) V_2 ;
struct V_12 * V_83 = NULL ;
int V_35 = 0 ;
struct V_9 * V_11 ;
T_3 V_46 ;
F_10 ( V_76 > 0 ) ;
F_10 ( V_81 != NULL ) ;
F_10 ( V_75 != 0 ) ;
F_10 ( V_82 != 0 ) ;
F_10 ( ( V_78 <= V_84 ) &&
( V_78 >= V_85 ) ) ;
F_32 ( V_86 , L_1
L_2 ,
V_87 , V_75 , V_76 , V_77 ,
V_79 , V_80 , V_82 ) ;
if ( ! V_2 )
return - V_49 ;
F_3 ( & V_7 -> V_20 ) ;
V_46 = F_33 ( V_7 ) ;
if ( V_46 < 0 ) {
V_35 = - V_51 ;
goto V_88;
}
if ( V_76 < V_7 -> V_19 ) {
V_35 = - V_89 ;
goto V_88;
}
V_83 = F_11 ( sizeof( struct V_12 ) , V_37 ) ;
if ( ! V_83 ) {
V_35 = - V_38 ;
goto V_88;
}
V_83 -> V_90 = V_2 ;
V_83 -> V_63 = V_75 ;
V_83 -> V_66 = V_76 ;
V_83 -> V_72 = V_82 ;
V_83 -> V_91 = V_77 ;
V_83 -> V_78 = V_78 ;
V_83 -> V_70 = V_79 ;
V_83 -> V_64 = V_80 ;
if ( V_83 -> V_72 == 0 ) {
V_35 = - V_51 ;
goto V_88;
}
* V_81 = ( T_1 ) V_46 + 1 ;
F_13 ( & V_83 -> V_92 ) ;
F_13 ( & V_83 -> V_28 ) ;
V_11 = F_5 ( V_7 , V_75 ,
V_83 -> V_72 , V_76 ) ;
if ( V_11 ) {
F_7 ( & V_11 -> V_27 , & V_83 -> V_92 ) ;
} else {
V_35 = - V_38 ;
goto V_88;
}
V_7 -> V_53 [ V_46 ] = V_83 ;
V_88:
if ( V_35 && V_83 )
F_17 ( V_83 ) ;
F_8 ( & V_7 -> V_20 ) ;
return V_35 ;
}
int F_34 ( struct V_1 * V_2 ,
T_1 V_54 )
{
struct V_1 * V_7 = (struct V_1 * ) V_2 ;
int V_35 = 0 ;
struct V_12 * V_83 ;
T_1 V_93 = V_54 ;
F_10 ( V_54 > 0 ) ;
if ( ! V_2 )
return - V_49 ;
if ( V_54 == V_94 )
V_93 = 1 ;
if ( ( V_93 <= 0 ) || ( V_93 > V_52 ) )
return - V_89 ;
while ( V_93 <= V_52 ) {
F_3 ( & V_7 -> V_20 ) ;
V_83 = V_7 -> V_53 [ V_93 - 1 ] ;
if ( V_83 != NULL ) {
F_17 ( V_83 ) ;
V_7 -> V_53 [ V_93 - 1 ] = NULL ;
} else if ( V_54 != V_94 ) {
V_35 = - V_51 ;
}
F_8 ( & V_7 -> V_20 ) ;
if ( V_54 != V_94 )
break;
V_93 ++ ;
}
return V_35 ;
}
static void F_17 ( struct V_12 * V_83 )
{
struct V_9 * V_55 , * V_48 ;
F_10 ( V_83 != NULL ) ;
F_18 (curr, tmp, &psma->free_list, link) {
F_19 ( & V_55 -> V_27 ) ;
F_20 ( V_55 ) ;
}
F_18 (curr, tmp, &psma->in_use_list, link) {
F_19 ( & V_55 -> V_27 ) ;
F_20 ( V_55 ) ;
}
if ( ( void * ) V_83 -> V_72 != NULL )
F_35 ( ( void * ) V_83 -> V_72 ) ;
F_20 ( V_83 ) ;
}
static T_3 F_33 ( struct V_1 * V_7 )
{
T_3 V_46 = - 1 ;
F_10 ( V_7 != NULL ) ;
for ( V_46 = 0 ; V_46 < V_52 ; V_46 ++ ) {
if ( V_7 -> V_53 [ V_46 ] == NULL )
break;
}
if ( V_46 == V_52 )
V_46 = - 1 ;
return V_46 ;
}
static struct V_9 * F_5 ( struct V_1 * V_7 , T_1 V_95 ,
T_1 V_96 , T_1 V_76 )
{
struct V_9 * V_10 ;
F_10 ( V_7 != NULL ) ;
F_10 ( V_95 != 0 ) ;
F_10 ( V_96 != 0 ) ;
F_10 ( V_76 != 0 ) ;
if ( F_36 ( & V_7 -> V_42 ) ) {
V_10 = F_11 ( sizeof( struct V_9 ) , V_37 ) ;
if ( ! V_10 )
return NULL ;
} else {
V_10 = F_37 ( & V_7 -> V_42 ,
struct V_9 , V_27 ) ;
F_38 ( & V_10 -> V_27 ) ;
}
V_10 -> V_22 = V_95 ;
V_10 -> V_23 = V_96 ;
V_10 -> V_21 = V_76 ;
return V_10 ;
}
static void F_39 ( struct V_1 * V_7 , struct V_9 * V_10 )
{
F_10 ( V_10 != NULL ) ;
F_7 ( & V_10 -> V_27 , & V_7 -> V_42 ) ;
}
static struct V_9 * F_4 ( struct V_12 * V_13 ,
T_1 V_3 )
{
struct V_9 * V_47 , * V_48 ;
if ( ! V_13 )
return NULL ;
F_18 (node, tmp, &allocator->free_list, link) {
if ( V_3 <= V_47 -> V_21 ) {
F_19 ( & V_47 -> V_27 ) ;
return V_47 ;
}
}
return NULL ;
}
static void F_6 ( struct V_12 * V_13 ,
struct V_9 * V_47 )
{
struct V_9 * V_55 ;
if ( ! V_47 ) {
F_40 ( L_3 , V_87 ) ;
return;
}
F_28 (curr, &allocator->free_list, link) {
if ( F_41 ( V_55 ) == V_47 -> V_22 ) {
V_55 -> V_21 += V_47 -> V_21 ;
F_39 ( V_13 -> V_90 , V_47 ) ;
return;
}
if ( V_55 -> V_22 == F_41 ( V_47 ) ) {
V_55 -> V_22 = V_47 -> V_22 ;
V_55 -> V_23 = V_47 -> V_23 ;
V_55 -> V_21 += V_47 -> V_21 ;
F_39 ( V_13 -> V_90 , V_47 ) ;
return;
}
}
F_28 (curr, &allocator->free_list, link) {
if ( V_55 -> V_21 >= V_47 -> V_21 ) {
F_7 ( & V_47 -> V_27 , & V_55 -> V_27 ) ;
return;
}
}
F_7 ( & V_47 -> V_27 , & V_13 -> V_92 ) ;
}
static struct V_12 * F_2 ( struct V_1 * V_7 ,
T_1 V_54 )
{
F_10 ( V_7 != NULL ) ;
F_10 ( ( V_54 > 0 ) && ( V_54 <= V_52 ) ) ;
return V_7 -> V_53 [ V_54 - 1 ] ;
}
int F_42 ( struct V_97 * * V_98 ,
struct V_1 * V_2 ,
struct V_99 * V_100 )
{
struct V_101 * V_102 = NULL ;
int V_35 = 0 ;
F_10 ( V_36 > 0 ) ;
F_10 ( V_98 != NULL ) ;
F_10 ( V_2 != NULL ) ;
* V_98 = NULL ;
if ( V_100 == NULL )
V_100 = & V_103 ;
V_102 = F_11 ( sizeof( struct V_101 ) , V_37 ) ;
if ( V_102 != NULL ) {
V_102 -> V_90 = V_2 ;
V_102 -> V_18 = V_100 -> V_18 ;
} else {
V_35 = - V_38 ;
}
if ( ! V_35 )
* V_98 = (struct V_97 * ) V_102 ;
return V_35 ;
}
void * F_43 ( struct V_97 * V_98 , void * V_104 ,
T_1 V_105 )
{
struct V_101 * V_106 = (struct V_101 * ) V_98 ;
void * V_107 = NULL ;
void * V_108 ;
struct V_4 V_109 ;
F_10 ( V_36 > 0 ) ;
F_10 ( V_98 != NULL ) ;
F_10 ( V_106 -> V_90 != NULL ) ;
F_10 ( V_104 != NULL ) ;
F_10 ( V_105 > 0 ) ;
F_10 ( V_106 -> V_18 > 0 ) ;
if ( V_106 ) {
V_109 . V_18 = V_106 -> V_18 ;
F_44 ( 0 , V_104 ) ;
V_107 =
F_1 ( V_106 -> V_90 , V_105 , & V_109 , NULL ) ;
if ( V_107 ) {
V_108 = F_45 ( V_98 ,
V_107 , V_110 ) ;
F_44 ( ( T_1 ) V_108 , V_104 ) ;
}
}
return V_107 ;
}
int F_46 ( struct V_97 * V_98 , void * V_111 )
{
struct V_101 * V_106 = (struct V_101 * ) V_98 ;
int V_35 = - V_51 ;
void * V_8 = NULL ;
F_10 ( V_36 > 0 ) ;
F_10 ( V_111 != NULL ) ;
F_10 ( V_106 -> V_18 > 0 ) ;
if ( V_106 ) {
V_8 = F_45 ( V_98 , V_111 , V_112 ) ;
if ( V_8 ) {
V_35 = F_23 ( V_106 -> V_90 , V_8 ,
V_106 -> V_18 ) ;
if ( V_35 ) {
F_12 ( false ) ;
}
}
}
return V_35 ;
}
int F_47 ( struct V_97 * V_98 , T_2 * * V_113 ,
T_1 V_76 , T_1 V_114 , bool V_115 )
{
struct V_101 * V_106 = (struct V_101 * ) V_98 ;
int V_35 = 0 ;
F_10 ( V_36 > 0 ) ;
F_10 ( V_113 != NULL ) ;
F_10 ( ( V_114 > 0 ) && ( V_114 <= V_52 ) ) ;
if ( V_106 ) {
if ( V_115 ) {
V_106 -> V_116 = ( T_1 ) * V_113 ;
V_106 -> V_117 = V_76 ;
} else {
* V_113 = ( T_2 * ) V_106 -> V_116 ;
}
} else {
V_35 = - V_49 ;
}
return V_35 ;
}
void * F_45 ( struct V_97 * V_98 , void * V_113 ,
enum V_118 V_119 )
{
T_1 V_120 = 0 ;
struct V_101 * V_106 = (struct V_101 * ) V_98 ;
struct V_1 * V_7 = NULL ;
struct V_12 * V_13 = NULL ;
T_1 V_121 = 0 ;
F_10 ( V_36 > 0 ) ;
F_10 ( V_113 != NULL ) ;
F_10 ( ( V_119 >= V_112 ) && ( V_119 <= V_122 ) ) ;
if ( ! V_106 )
goto V_123;
V_7 = (struct V_1 * ) V_106 -> V_90 ;
F_12 ( V_106 -> V_18 > 0 ) ;
V_13 = V_7 -> V_53 [ V_106 -> V_18 - 1 ] ;
if ( ! V_13 )
goto V_123;
if ( ( V_119 == V_124 ) || ( V_119 == V_112 ) ||
( V_119 == V_110 ) ) {
if ( V_119 == V_110 ) {
V_121 = ( T_2 * ) V_113 - ( T_2 * ) ( V_13 -> V_63 -
V_13 ->
V_64 ) ;
V_120 = V_106 -> V_116 + V_121 ;
if ( ( V_120 < V_106 -> V_116 ) ||
( V_120 >=
( V_106 -> V_116 +
V_106 -> V_117 ) ) ) {
V_120 = 0 ;
}
} else {
V_121 =
( T_2 * ) V_113 - ( T_2 * ) V_106 -> V_116 ;
V_120 =
V_13 -> V_63 - V_13 -> V_64 +
V_121 ;
}
} else {
V_120 = ( T_1 ) V_113 ;
}
if ( ( V_119 == V_124 ) || ( V_119 == V_125 ) ) {
V_120 =
F_48 ( ( V_13 -> V_63 - V_13 -> V_64 ) ,
V_120 ,
V_13 -> V_91 *
V_13 -> V_78 ) ;
} else if ( V_119 == V_122 ) {
V_120 =
F_49 ( V_13 -> V_63 - V_13 -> V_64 ,
V_120 ,
V_13 -> V_91 *
V_13 -> V_78 ) ;
}
V_123:
return ( void * ) V_120 ;
}
