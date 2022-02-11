static T_1 F_1 ( const struct V_1 * V_2 )
{
return V_2 -> V_3 - V_2 -> V_4 ;
}
void F_2 ( struct V_5 * V_6 , const struct V_5 * V_7 ,
const struct V_8 * V_9 )
{
const long * V_10 = ( const long * ) ( ( const V_11 * ) & V_9 -> V_12 +
V_9 -> V_2 . V_4 ) ;
const long * V_13 = ( const long * ) ( ( const V_11 * ) V_7 +
V_9 -> V_2 . V_4 ) ;
long * V_14 = ( long * ) ( ( V_11 * ) V_6 + V_9 -> V_2 . V_4 ) ;
int V_15 ;
for ( V_15 = 0 ; V_15 < F_1 ( & V_9 -> V_2 ) ; V_15 += sizeof( long ) )
* V_14 ++ = * V_13 ++ & * V_10 ++ ;
}
struct V_16 * F_3 ( void )
{
struct V_16 * V_17 ;
struct V_18 * V_19 ;
int V_20 ;
V_17 = F_4 ( V_21 , V_22 ) ;
if ( ! V_17 )
return F_5 ( - V_23 ) ;
V_17 -> V_24 = NULL ;
V_17 -> V_9 = NULL ;
V_17 -> V_25 . V_26 = NULL ;
V_17 -> V_25 . V_27 = 0 ;
V_17 -> V_28 = V_29 ;
V_19 = F_6 ( V_30 ,
V_22 | V_31 , 0 ) ;
if ( ! V_19 )
goto V_32;
F_7 ( & V_19 -> V_33 ) ;
F_8 ( V_17 -> V_19 [ 0 ] , V_19 ) ;
F_9 (node)
if ( V_20 != 0 )
F_8 ( V_17 -> V_19 [ V_20 ] , NULL ) ;
return V_17 ;
V_32:
F_10 ( V_21 , V_17 ) ;
return F_5 ( - V_23 ) ;
}
int F_11 ( const struct V_34 * V_35 )
{
return V_35 -> V_36 ;
}
static struct V_37 * F_12 ( unsigned int V_38 )
{
struct V_37 * V_39 ;
int V_15 , V_32 ;
V_39 = F_13 ( sizeof( struct V_40 ) ,
V_38 , V_22 ) ;
if ( ! V_39 )
return NULL ;
V_32 = F_14 ( V_39 , 0 , V_38 , V_22 ) ;
if ( V_32 ) {
F_15 ( V_39 ) ;
return NULL ;
}
for ( V_15 = 0 ; V_15 < V_38 ; V_15 ++ )
F_16 ( (struct V_40 * )
F_17 ( V_39 , V_15 ) ) ;
return V_39 ;
}
static void F_18 ( struct V_16 * V_17 )
{
int V_20 ;
if ( F_19 ( & V_17 -> V_25 ) )
F_20 ( V_17 -> V_25 . V_26 ) ;
F_20 ( (struct V_41 V_42 * ) V_17 -> V_24 ) ;
F_9 (node)
if ( V_17 -> V_19 [ V_20 ] )
F_10 ( V_30 ,
(struct V_18 V_42 * ) V_17 -> V_19 [ V_20 ] ) ;
F_10 ( V_21 , V_17 ) ;
}
static void F_21 ( struct V_43 * V_44 )
{
struct V_16 * V_17 = F_22 ( V_44 , struct V_16 , V_44 ) ;
F_18 ( V_17 ) ;
}
void F_23 ( struct V_16 * V_17 , bool V_45 )
{
if ( ! V_17 )
return;
if ( V_45 )
F_24 ( & V_17 -> V_44 , F_21 ) ;
else
F_18 ( V_17 ) ;
}
static void F_25 ( struct V_37 * V_39 )
{
F_15 ( V_39 ) ;
}
static void F_26 ( struct V_46 * V_47 )
{
F_25 ( V_47 -> V_39 ) ;
F_20 ( V_47 ) ;
}
static struct V_46 * F_27 ( int V_48 )
{
struct V_46 * V_47 = F_28 ( sizeof( * V_47 ) , V_22 ) ;
if ( ! V_47 )
return NULL ;
V_47 -> V_39 = F_12 ( V_48 ) ;
if ( ! V_47 -> V_39 ) {
F_20 ( V_47 ) ;
return NULL ;
}
V_47 -> V_38 = V_48 ;
V_47 -> V_49 = 0 ;
V_47 -> V_50 = false ;
F_29 ( & V_47 -> V_51 , sizeof( V_52 ) ) ;
return V_47 ;
}
int F_30 ( struct V_34 * V_35 )
{
struct V_46 * V_47 , * V_53 ;
V_47 = F_27 ( V_54 ) ;
if ( ! V_47 )
return - V_23 ;
V_53 = F_27 ( V_54 ) ;
if ( ! V_53 )
goto V_55;
F_31 ( V_35 -> V_47 , V_47 ) ;
F_31 ( V_35 -> V_53 , V_53 ) ;
F_32 ( & V_35 -> V_56 ) ;
V_35 -> V_57 = V_58 ;
V_35 -> V_36 = 0 ;
V_35 -> V_59 = 0 ;
return 0 ;
V_55:
F_26 ( V_47 ) ;
return - V_23 ;
}
static void F_33 ( struct V_43 * V_44 )
{
struct V_46 * V_47 = F_22 ( V_44 , struct V_46 , V_44 ) ;
F_26 ( V_47 ) ;
}
static void F_34 ( struct V_46 * V_47 ,
struct V_46 * V_53 ,
bool V_45 )
{
int V_15 ;
if ( ! V_47 )
return;
F_35 ( ! V_53 ) ;
if ( V_47 -> V_50 )
goto V_60;
for ( V_15 = 0 ; V_15 < V_47 -> V_38 ; V_15 ++ ) {
struct V_16 * V_17 ;
struct V_40 * V_61 = F_17 ( V_47 -> V_39 , V_15 ) ;
struct V_62 * V_63 ;
int V_64 = V_47 -> V_49 ;
int V_65 = V_53 -> V_49 ;
F_36 (flow, n, head, flow_table.node[ver]) {
F_37 ( & V_17 -> V_34 . V_20 [ V_64 ] ) ;
if ( F_38 ( & V_17 -> V_25 ) )
F_37 ( & V_17 -> V_66 . V_20 [ V_65 ] ) ;
F_23 ( V_17 , V_45 ) ;
}
}
V_60:
if ( V_45 ) {
F_24 ( & V_47 -> V_44 , F_33 ) ;
F_24 ( & V_53 -> V_44 , F_33 ) ;
} else {
F_26 ( V_47 ) ;
F_26 ( V_53 ) ;
}
}
void F_39 ( struct V_34 * V_35 )
{
struct V_46 * V_47 = F_40 ( V_35 -> V_47 ) ;
struct V_46 * V_53 = F_40 ( V_35 -> V_53 ) ;
F_34 ( V_47 , V_53 , false ) ;
}
struct V_16 * F_41 ( struct V_46 * V_47 ,
V_52 * V_67 , V_52 * V_68 )
{
struct V_16 * V_17 ;
struct V_40 * V_61 ;
int V_64 ;
int V_15 ;
V_64 = V_47 -> V_49 ;
while ( * V_67 < V_47 -> V_38 ) {
V_15 = 0 ;
V_61 = F_17 ( V_47 -> V_39 , * V_67 ) ;
F_42 (flow, head, flow_table.node[ver]) {
if ( V_15 < * V_68 ) {
V_15 ++ ;
continue;
}
* V_68 = V_15 + 1 ;
return V_17 ;
}
( * V_67 ) ++ ;
* V_68 = 0 ;
}
return NULL ;
}
static struct V_40 * F_43 ( struct V_46 * V_47 , V_52 V_69 )
{
V_69 = F_44 ( V_69 , V_47 -> V_51 ) ;
return F_17 ( V_47 -> V_39 ,
( V_69 & ( V_47 -> V_38 - 1 ) ) ) ;
}
static void F_45 ( struct V_46 * V_47 ,
struct V_16 * V_17 )
{
struct V_40 * V_61 ;
V_61 = F_43 ( V_47 , V_17 -> V_34 . V_69 ) ;
F_46 ( & V_17 -> V_34 . V_20 [ V_47 -> V_49 ] , V_61 ) ;
}
static void F_47 ( struct V_46 * V_47 ,
struct V_16 * V_17 )
{
struct V_40 * V_61 ;
V_61 = F_43 ( V_47 , V_17 -> V_66 . V_69 ) ;
F_46 ( & V_17 -> V_66 . V_20 [ V_47 -> V_49 ] , V_61 ) ;
}
static void F_48 ( struct V_46 * V_70 ,
struct V_46 * V_71 , bool V_72 )
{
int V_73 ;
int V_15 ;
V_73 = V_70 -> V_49 ;
V_71 -> V_49 = ! V_73 ;
for ( V_15 = 0 ; V_15 < V_70 -> V_38 ; V_15 ++ ) {
struct V_16 * V_17 ;
struct V_40 * V_61 ;
V_61 = F_17 ( V_70 -> V_39 , V_15 ) ;
if ( V_72 )
F_49 (flow, head,
ufid_table.node[old_ver])
F_47 ( V_71 , V_17 ) ;
else
F_49 (flow, head,
flow_table.node[old_ver])
F_45 ( V_71 , V_17 ) ;
}
V_70 -> V_50 = true ;
}
static struct V_46 * F_50 ( struct V_46 * V_47 ,
int V_38 , bool V_72 )
{
struct V_46 * V_74 ;
V_74 = F_27 ( V_38 ) ;
if ( ! V_74 )
return NULL ;
F_48 ( V_47 , V_74 , V_72 ) ;
return V_74 ;
}
int F_51 ( struct V_34 * V_34 )
{
struct V_46 * V_75 , * V_74 ;
struct V_46 * V_76 , * V_77 ;
V_74 = F_27 ( V_54 ) ;
if ( ! V_74 )
return - V_23 ;
V_77 = F_27 ( V_54 ) ;
if ( ! V_77 )
goto V_78;
V_75 = F_52 ( V_34 -> V_47 ) ;
V_76 = F_52 ( V_34 -> V_53 ) ;
F_31 ( V_34 -> V_47 , V_74 ) ;
F_31 ( V_34 -> V_53 , V_77 ) ;
V_34 -> V_57 = V_58 ;
V_34 -> V_36 = 0 ;
V_34 -> V_59 = 0 ;
F_34 ( V_75 , V_76 , true ) ;
return 0 ;
V_78:
F_26 ( V_74 ) ;
return - V_23 ;
}
static V_52 F_53 ( const struct V_5 * V_12 ,
const struct V_1 * V_2 )
{
int V_79 = V_2 -> V_4 ;
int V_80 = V_2 -> V_3 ;
const V_52 * V_81 = ( const V_52 * ) ( ( const V_11 * ) V_12 + V_79 ) ;
int V_82 = ( V_80 - V_79 ) >> 2 ;
F_54 ( sizeof( long ) % sizeof( V_52 ) ) ;
return F_55 ( V_81 , V_82 , 0 ) ;
}
static int F_56 ( const struct V_5 * V_12 )
{
if ( V_12 -> V_83 . V_84 )
return 0 ;
else
return F_57 ( F_58 ( struct V_5 , V_85 ) ,
sizeof( long ) ) ;
}
static bool F_59 ( const struct V_5 * V_86 ,
const struct V_5 * V_87 ,
int V_79 , int V_80 )
{
const long * V_88 = ( const long * ) ( ( const V_11 * ) V_86 + V_79 ) ;
const long * V_89 = ( const long * ) ( ( const V_11 * ) V_87 + V_79 ) ;
long V_90 = 0 ;
int V_15 ;
for ( V_15 = V_79 ; V_15 < V_80 ; V_15 += sizeof( long ) )
V_90 |= * V_88 ++ ^ * V_89 ++ ;
return V_90 == 0 ;
}
static bool F_60 ( const struct V_16 * V_17 ,
const struct V_5 * V_12 ,
const struct V_1 * V_2 )
{
return F_59 ( & V_17 -> V_12 , V_12 , V_2 -> V_4 , V_2 -> V_3 ) ;
}
static bool F_61 ( const struct V_16 * V_17 ,
const struct V_91 * V_92 )
{
struct V_5 * V_12 = V_92 -> V_12 ;
int V_79 = F_56 ( V_12 ) ;
int V_80 = V_92 -> V_2 . V_3 ;
F_35 ( F_38 ( & V_17 -> V_25 ) ) ;
return F_59 ( V_17 -> V_25 . V_26 , V_12 , V_79 , V_80 ) ;
}
static struct V_16 * F_62 ( struct V_46 * V_47 ,
const struct V_5 * V_93 ,
const struct V_8 * V_9 )
{
struct V_16 * V_17 ;
struct V_40 * V_61 ;
V_52 V_69 ;
struct V_5 V_94 ;
F_2 ( & V_94 , V_93 , V_9 ) ;
V_69 = F_53 ( & V_94 , & V_9 -> V_2 ) ;
V_61 = F_43 ( V_47 , V_69 ) ;
F_42 (flow, head, flow_table.node[ti->node_ver]) {
if ( V_17 -> V_9 == V_9 && V_17 -> V_34 . V_69 == V_69 &&
F_60 ( V_17 , & V_94 , & V_9 -> V_2 ) )
return V_17 ;
}
return NULL ;
}
struct V_16 * F_63 ( struct V_34 * V_95 ,
const struct V_5 * V_12 ,
V_52 * V_96 )
{
struct V_46 * V_47 = F_64 ( V_95 -> V_47 ) ;
struct V_8 * V_9 ;
struct V_16 * V_17 ;
* V_96 = 0 ;
F_65 (mask, &tbl->mask_list, list) {
( * V_96 ) ++ ;
V_17 = F_62 ( V_47 , V_12 , V_9 ) ;
if ( V_17 )
return V_17 ;
}
return NULL ;
}
struct V_16 * F_66 ( struct V_34 * V_95 ,
const struct V_5 * V_12 )
{
V_52 T_2 V_96 ;
return F_63 ( V_95 , V_12 , & V_96 ) ;
}
struct V_16 * F_67 ( struct V_34 * V_95 ,
const struct V_91 * V_92 )
{
struct V_46 * V_47 = F_64 ( V_95 -> V_47 ) ;
struct V_8 * V_9 ;
struct V_16 * V_17 ;
F_68 (mask, &tbl->mask_list, list) {
V_17 = F_62 ( V_47 , V_92 -> V_12 , V_9 ) ;
if ( V_17 && F_19 ( & V_17 -> V_25 ) &&
F_61 ( V_17 , V_92 ) )
return V_17 ;
}
return NULL ;
}
static V_52 F_69 ( const struct V_97 * V_98 )
{
return F_70 ( V_98 -> V_72 , V_98 -> V_27 , 0 ) ;
}
static bool F_71 ( const struct V_16 * V_17 ,
const struct V_97 * V_98 )
{
if ( V_17 -> V_25 . V_27 != V_98 -> V_27 )
return false ;
return ! memcmp ( V_17 -> V_25 . V_72 , V_98 -> V_72 , V_98 -> V_27 ) ;
}
bool F_72 ( const struct V_16 * V_17 , const struct V_91 * V_92 )
{
if ( F_38 ( & V_17 -> V_25 ) )
return F_60 ( V_17 , V_92 -> V_12 , & V_92 -> V_2 ) ;
return F_61 ( V_17 , V_92 ) ;
}
struct V_16 * F_73 ( struct V_34 * V_95 ,
const struct V_97 * V_72 )
{
struct V_46 * V_47 = F_64 ( V_95 -> V_53 ) ;
struct V_16 * V_17 ;
struct V_40 * V_61 ;
V_52 V_69 ;
V_69 = F_69 ( V_72 ) ;
V_61 = F_43 ( V_47 , V_69 ) ;
F_42 (flow, head, ufid_table.node[ti->node_ver]) {
if ( V_17 -> V_66 . V_69 == V_69 &&
F_71 ( V_17 , V_72 ) )
return V_17 ;
}
return NULL ;
}
int F_74 ( const struct V_34 * V_35 )
{
struct V_8 * V_9 ;
int V_99 = 0 ;
F_68 (mask, &table->mask_list, list)
V_99 ++ ;
return V_99 ;
}
static struct V_46 * F_75 ( struct V_46 * V_47 ,
bool V_72 )
{
return F_50 ( V_47 , V_47 -> V_38 * 2 , V_72 ) ;
}
static void F_76 ( struct V_34 * V_95 , struct V_8 * V_9 )
{
if ( V_9 ) {
F_77 () ;
F_35 ( ! V_9 -> V_100 ) ;
V_9 -> V_100 -- ;
if ( ! V_9 -> V_100 ) {
F_78 ( & V_9 -> V_101 ) ;
F_79 ( V_9 , V_44 ) ;
}
}
}
void F_80 ( struct V_34 * V_35 , struct V_16 * V_17 )
{
struct V_46 * V_47 = F_52 ( V_35 -> V_47 ) ;
struct V_46 * V_53 = F_52 ( V_35 -> V_53 ) ;
F_35 ( V_35 -> V_36 == 0 ) ;
F_37 ( & V_17 -> V_34 . V_20 [ V_47 -> V_49 ] ) ;
V_35 -> V_36 -- ;
if ( F_38 ( & V_17 -> V_25 ) ) {
F_37 ( & V_17 -> V_66 . V_20 [ V_53 -> V_49 ] ) ;
V_35 -> V_59 -- ;
}
F_76 ( V_35 , V_17 -> V_9 ) ;
}
static struct V_8 * F_81 ( void )
{
struct V_8 * V_9 ;
V_9 = F_28 ( sizeof( * V_9 ) , V_22 ) ;
if ( V_9 )
V_9 -> V_100 = 1 ;
return V_9 ;
}
static bool F_82 ( const struct V_8 * V_102 ,
const struct V_8 * V_103 )
{
const V_11 * V_104 = ( const V_11 * ) & V_102 -> V_12 + V_102 -> V_2 . V_4 ;
const V_11 * V_105 = ( const V_11 * ) & V_103 -> V_12 + V_103 -> V_2 . V_4 ;
return ( V_102 -> V_2 . V_3 == V_103 -> V_2 . V_3 )
&& ( V_102 -> V_2 . V_4 == V_103 -> V_2 . V_4 )
&& ( memcmp ( V_104 , V_105 , F_1 ( & V_102 -> V_2 ) ) == 0 ) ;
}
static struct V_8 * F_83 ( const struct V_34 * V_95 ,
const struct V_8 * V_9 )
{
struct V_106 * V_107 ;
F_84 (ml, &tbl->mask_list) {
struct V_8 * V_10 ;
V_10 = F_22 ( V_107 , struct V_8 , V_101 ) ;
if ( F_82 ( V_9 , V_10 ) )
return V_10 ;
}
return NULL ;
}
static int F_85 ( struct V_34 * V_95 , struct V_16 * V_17 ,
const struct V_8 * V_71 )
{
struct V_8 * V_9 ;
V_9 = F_83 ( V_95 , V_71 ) ;
if ( ! V_9 ) {
V_9 = F_81 () ;
if ( ! V_9 )
return - V_23 ;
V_9 -> V_12 = V_71 -> V_12 ;
V_9 -> V_2 = V_71 -> V_2 ;
F_86 ( & V_9 -> V_101 , & V_95 -> V_56 ) ;
} else {
F_35 ( ! V_9 -> V_100 ) ;
V_9 -> V_100 ++ ;
}
V_17 -> V_9 = V_9 ;
return 0 ;
}
static void F_87 ( struct V_34 * V_35 , struct V_16 * V_17 )
{
struct V_46 * V_74 = NULL ;
struct V_46 * V_47 ;
V_17 -> V_34 . V_69 = F_53 ( & V_17 -> V_12 , & V_17 -> V_9 -> V_2 ) ;
V_47 = F_52 ( V_35 -> V_47 ) ;
F_45 ( V_47 , V_17 ) ;
V_35 -> V_36 ++ ;
if ( V_35 -> V_36 > V_47 -> V_38 )
V_74 = F_75 ( V_47 , false ) ;
else if ( F_88 ( V_58 , V_35 -> V_57 + V_108 ) )
V_74 = F_50 ( V_47 , V_47 -> V_38 , false ) ;
if ( V_74 ) {
F_31 ( V_35 -> V_47 , V_74 ) ;
F_24 ( & V_47 -> V_44 , F_33 ) ;
V_35 -> V_57 = V_58 ;
}
}
static void F_89 ( struct V_34 * V_35 , struct V_16 * V_17 )
{
struct V_46 * V_47 ;
V_17 -> V_66 . V_69 = F_69 ( & V_17 -> V_25 ) ;
V_47 = F_52 ( V_35 -> V_53 ) ;
F_47 ( V_47 , V_17 ) ;
V_35 -> V_59 ++ ;
if ( V_35 -> V_59 > V_47 -> V_38 ) {
struct V_46 * V_74 ;
V_74 = F_75 ( V_47 , true ) ;
if ( V_74 ) {
F_31 ( V_35 -> V_53 , V_74 ) ;
F_24 ( & V_47 -> V_44 , F_33 ) ;
}
}
}
int F_90 ( struct V_34 * V_35 , struct V_16 * V_17 ,
const struct V_8 * V_9 )
{
int V_32 ;
V_32 = F_85 ( V_35 , V_17 , V_9 ) ;
if ( V_32 )
return V_32 ;
F_87 ( V_35 , V_17 ) ;
if ( F_38 ( & V_17 -> V_25 ) )
F_89 ( V_35 , V_17 ) ;
return 0 ;
}
int F_91 ( void )
{
F_54 ( F_92 ( struct V_5 ) % F_92 ( long ) ) ;
F_54 ( sizeof( struct V_5 ) % sizeof( long ) ) ;
V_21 = F_93 ( L_1 , sizeof( struct V_16 )
+ ( F_94 ()
* sizeof( struct V_18 * ) ) ,
0 , 0 , NULL ) ;
if ( V_21 == NULL )
return - V_23 ;
V_30
= F_93 ( L_2 , sizeof( struct V_18 ) ,
0 , V_109 , NULL ) ;
if ( V_30 == NULL ) {
F_95 ( V_21 ) ;
V_21 = NULL ;
return - V_23 ;
}
return 0 ;
}
void F_96 ( void )
{
F_95 ( V_30 ) ;
F_95 ( V_21 ) ;
}
