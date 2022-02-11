static T_1 F_1 ( const struct V_1 * V_2 )
{
return V_2 -> V_3 - V_2 -> V_4 ;
}
void F_2 ( struct V_5 * V_6 , const struct V_5 * V_7 ,
bool V_8 , const struct V_9 * V_10 )
{
int V_4 = V_8 ? 0 : V_10 -> V_2 . V_4 ;
int V_11 = V_8 ? sizeof *V_6 : F_1 ( & V_10 -> V_2 ) ;
const long * V_12 = ( const long * ) ( ( const V_13 * ) & V_10 -> V_14 + V_4 ) ;
const long * V_15 = ( const long * ) ( ( const V_13 * ) V_7 + V_4 ) ;
long * V_16 = ( long * ) ( ( V_13 * ) V_6 + V_4 ) ;
int V_17 ;
for ( V_17 = 0 ; V_17 < V_11 ; V_17 += sizeof( long ) )
* V_16 ++ = * V_15 ++ & * V_12 ++ ;
}
struct V_18 * F_3 ( void )
{
struct V_18 * V_19 ;
struct V_20 * V_21 ;
int V_22 ;
V_19 = F_4 ( V_23 , V_24 ) ;
if ( ! V_19 )
return F_5 ( - V_25 ) ;
V_19 -> V_26 = NULL ;
V_19 -> V_10 = NULL ;
V_19 -> V_27 . V_28 = NULL ;
V_19 -> V_27 . V_29 = 0 ;
V_19 -> V_30 = V_31 ;
V_21 = F_6 ( V_32 ,
V_24 | V_33 ,
F_7 ( 0 ) ? 0 : V_31 ) ;
if ( ! V_21 )
goto V_34;
F_8 ( & V_21 -> V_35 ) ;
F_9 ( V_19 -> V_21 [ 0 ] , V_21 ) ;
F_10 (node)
if ( V_22 != 0 )
F_9 ( V_19 -> V_21 [ V_22 ] , NULL ) ;
return V_19 ;
V_34:
F_11 ( V_23 , V_19 ) ;
return F_5 ( - V_25 ) ;
}
int F_12 ( const struct V_36 * V_37 )
{
return V_37 -> V_38 ;
}
static struct V_39 * F_13 ( unsigned int V_40 )
{
struct V_39 * V_41 ;
int V_17 , V_34 ;
V_41 = F_14 ( sizeof( struct V_42 ) ,
V_40 , V_24 ) ;
if ( ! V_41 )
return NULL ;
V_34 = F_15 ( V_41 , 0 , V_40 , V_24 ) ;
if ( V_34 ) {
F_16 ( V_41 ) ;
return NULL ;
}
for ( V_17 = 0 ; V_17 < V_40 ; V_17 ++ )
F_17 ( (struct V_42 * )
F_18 ( V_41 , V_17 ) ) ;
return V_41 ;
}
static void F_19 ( struct V_18 * V_19 )
{
int V_22 ;
if ( F_20 ( & V_19 -> V_27 ) )
F_21 ( V_19 -> V_27 . V_28 ) ;
if ( V_19 -> V_26 )
F_22 ( (struct V_43 V_44 * ) V_19 -> V_26 ) ;
F_10 (node)
if ( V_19 -> V_21 [ V_22 ] )
F_11 ( V_32 ,
(struct V_20 V_44 * ) V_19 -> V_21 [ V_22 ] ) ;
F_11 ( V_23 , V_19 ) ;
}
static void F_23 ( struct V_45 * V_46 )
{
struct V_18 * V_19 = F_24 ( V_46 , struct V_18 , V_46 ) ;
F_19 ( V_19 ) ;
}
void F_25 ( struct V_18 * V_19 , bool V_47 )
{
if ( ! V_19 )
return;
if ( V_47 )
F_26 ( & V_19 -> V_46 , F_23 ) ;
else
F_19 ( V_19 ) ;
}
static void F_27 ( struct V_39 * V_41 )
{
F_16 ( V_41 ) ;
}
static void F_28 ( struct V_48 * V_49 )
{
F_27 ( V_49 -> V_41 ) ;
F_21 ( V_49 ) ;
}
static struct V_48 * F_29 ( int V_50 )
{
struct V_48 * V_49 = F_30 ( sizeof( * V_49 ) , V_24 ) ;
if ( ! V_49 )
return NULL ;
V_49 -> V_41 = F_13 ( V_50 ) ;
if ( ! V_49 -> V_41 ) {
F_21 ( V_49 ) ;
return NULL ;
}
V_49 -> V_40 = V_50 ;
V_49 -> V_51 = 0 ;
V_49 -> V_52 = false ;
F_31 ( & V_49 -> V_53 , sizeof( V_54 ) ) ;
return V_49 ;
}
int F_32 ( struct V_36 * V_37 )
{
struct V_48 * V_49 , * V_55 ;
V_49 = F_29 ( V_56 ) ;
if ( ! V_49 )
return - V_25 ;
V_55 = F_29 ( V_56 ) ;
if ( ! V_55 )
goto V_57;
F_33 ( V_37 -> V_49 , V_49 ) ;
F_33 ( V_37 -> V_55 , V_55 ) ;
F_34 ( & V_37 -> V_58 ) ;
V_37 -> V_59 = V_60 ;
V_37 -> V_38 = 0 ;
V_37 -> V_61 = 0 ;
return 0 ;
V_57:
F_28 ( V_49 ) ;
return - V_25 ;
}
static void F_35 ( struct V_45 * V_46 )
{
struct V_48 * V_49 = F_24 ( V_46 , struct V_48 , V_46 ) ;
F_28 ( V_49 ) ;
}
static void F_36 ( struct V_48 * V_49 ,
struct V_48 * V_55 ,
bool V_47 )
{
int V_17 ;
if ( ! V_49 )
return;
F_37 ( ! V_55 ) ;
if ( V_49 -> V_52 )
goto V_62;
for ( V_17 = 0 ; V_17 < V_49 -> V_40 ; V_17 ++ ) {
struct V_18 * V_19 ;
struct V_42 * V_63 = F_18 ( V_49 -> V_41 , V_17 ) ;
struct V_64 * V_65 ;
int V_66 = V_49 -> V_51 ;
int V_67 = V_55 -> V_51 ;
F_38 (flow, n, head, flow_table.node[ver]) {
F_39 ( & V_19 -> V_36 . V_22 [ V_66 ] ) ;
if ( F_40 ( & V_19 -> V_27 ) )
F_39 ( & V_19 -> V_68 . V_22 [ V_67 ] ) ;
F_25 ( V_19 , V_47 ) ;
}
}
V_62:
if ( V_47 ) {
F_26 ( & V_49 -> V_46 , F_35 ) ;
F_26 ( & V_55 -> V_46 , F_35 ) ;
} else {
F_28 ( V_49 ) ;
F_28 ( V_55 ) ;
}
}
void F_41 ( struct V_36 * V_37 )
{
struct V_48 * V_49 = F_42 ( V_37 -> V_49 ) ;
struct V_48 * V_55 = F_42 ( V_37 -> V_55 ) ;
F_36 ( V_49 , V_55 , false ) ;
}
struct V_18 * F_43 ( struct V_48 * V_49 ,
V_54 * V_69 , V_54 * V_70 )
{
struct V_18 * V_19 ;
struct V_42 * V_63 ;
int V_66 ;
int V_17 ;
V_66 = V_49 -> V_51 ;
while ( * V_69 < V_49 -> V_40 ) {
V_17 = 0 ;
V_63 = F_18 ( V_49 -> V_41 , * V_69 ) ;
F_44 (flow, head, flow_table.node[ver]) {
if ( V_17 < * V_70 ) {
V_17 ++ ;
continue;
}
* V_70 = V_17 + 1 ;
return V_19 ;
}
( * V_69 ) ++ ;
* V_70 = 0 ;
}
return NULL ;
}
static struct V_42 * F_45 ( struct V_48 * V_49 , V_54 V_71 )
{
V_71 = F_46 ( V_71 , V_49 -> V_53 ) ;
return F_18 ( V_49 -> V_41 ,
( V_71 & ( V_49 -> V_40 - 1 ) ) ) ;
}
static void F_47 ( struct V_48 * V_49 ,
struct V_18 * V_19 )
{
struct V_42 * V_63 ;
V_63 = F_45 ( V_49 , V_19 -> V_36 . V_71 ) ;
F_48 ( & V_19 -> V_36 . V_22 [ V_49 -> V_51 ] , V_63 ) ;
}
static void F_49 ( struct V_48 * V_49 ,
struct V_18 * V_19 )
{
struct V_42 * V_63 ;
V_63 = F_45 ( V_49 , V_19 -> V_68 . V_71 ) ;
F_48 ( & V_19 -> V_68 . V_22 [ V_49 -> V_51 ] , V_63 ) ;
}
static void F_50 ( struct V_48 * V_72 ,
struct V_48 * V_73 , bool V_74 )
{
int V_75 ;
int V_17 ;
V_75 = V_72 -> V_51 ;
V_73 -> V_51 = ! V_75 ;
for ( V_17 = 0 ; V_17 < V_72 -> V_40 ; V_17 ++ ) {
struct V_18 * V_19 ;
struct V_42 * V_63 ;
V_63 = F_18 ( V_72 -> V_41 , V_17 ) ;
if ( V_74 )
F_51 (flow, head,
ufid_table.node[old_ver])
F_49 ( V_73 , V_19 ) ;
else
F_51 (flow, head,
flow_table.node[old_ver])
F_47 ( V_73 , V_19 ) ;
}
V_72 -> V_52 = true ;
}
static struct V_48 * F_52 ( struct V_48 * V_49 ,
int V_40 , bool V_74 )
{
struct V_48 * V_76 ;
V_76 = F_29 ( V_40 ) ;
if ( ! V_76 )
return NULL ;
F_50 ( V_49 , V_76 , V_74 ) ;
return V_76 ;
}
int F_53 ( struct V_36 * V_36 )
{
struct V_48 * V_77 , * V_76 ;
struct V_48 * V_78 , * V_79 ;
V_76 = F_29 ( V_56 ) ;
if ( ! V_76 )
return - V_25 ;
V_79 = F_29 ( V_56 ) ;
if ( ! V_79 )
goto V_80;
V_77 = F_54 ( V_36 -> V_49 ) ;
V_78 = F_54 ( V_36 -> V_55 ) ;
F_33 ( V_36 -> V_49 , V_76 ) ;
F_33 ( V_36 -> V_55 , V_79 ) ;
V_36 -> V_59 = V_60 ;
V_36 -> V_38 = 0 ;
V_36 -> V_61 = 0 ;
F_36 ( V_77 , V_78 , true ) ;
return 0 ;
V_80:
F_28 ( V_76 ) ;
return - V_25 ;
}
static V_54 F_55 ( const struct V_5 * V_14 ,
const struct V_1 * V_2 )
{
int V_81 = V_2 -> V_4 ;
int V_82 = V_2 -> V_3 ;
const V_54 * V_83 = ( const V_54 * ) ( ( const V_13 * ) V_14 + V_81 ) ;
int V_84 = ( V_82 - V_81 ) >> 2 ;
F_56 ( sizeof( long ) % sizeof( V_54 ) ) ;
return F_57 ( V_83 , V_84 , 0 ) ;
}
static int F_58 ( const struct V_5 * V_14 )
{
if ( V_14 -> V_85 . V_86 . V_87 . V_6 )
return 0 ;
else
return F_59 ( F_60 ( struct V_5 , V_88 ) ,
sizeof( long ) ) ;
}
static bool F_61 ( const struct V_5 * V_89 ,
const struct V_5 * V_90 ,
int V_81 , int V_82 )
{
const long * V_91 = ( const long * ) ( ( const V_13 * ) V_89 + V_81 ) ;
const long * V_92 = ( const long * ) ( ( const V_13 * ) V_90 + V_81 ) ;
long V_93 = 0 ;
int V_17 ;
for ( V_17 = V_81 ; V_17 < V_82 ; V_17 += sizeof( long ) )
V_93 |= * V_91 ++ ^ * V_92 ++ ;
return V_93 == 0 ;
}
static bool F_62 ( const struct V_18 * V_19 ,
const struct V_5 * V_14 ,
const struct V_1 * V_2 )
{
return F_61 ( & V_19 -> V_14 , V_14 , V_2 -> V_4 , V_2 -> V_3 ) ;
}
static bool F_63 ( const struct V_18 * V_19 ,
const struct V_94 * V_95 )
{
struct V_5 * V_14 = V_95 -> V_14 ;
int V_81 = F_58 ( V_14 ) ;
int V_82 = V_95 -> V_2 . V_3 ;
F_37 ( F_40 ( & V_19 -> V_27 ) ) ;
return F_61 ( V_19 -> V_27 . V_28 , V_14 , V_81 , V_82 ) ;
}
static struct V_18 * F_64 ( struct V_48 * V_49 ,
const struct V_5 * V_96 ,
const struct V_9 * V_10 )
{
struct V_18 * V_19 ;
struct V_42 * V_63 ;
V_54 V_71 ;
struct V_5 V_97 ;
F_2 ( & V_97 , V_96 , false , V_10 ) ;
V_71 = F_55 ( & V_97 , & V_10 -> V_2 ) ;
V_63 = F_45 ( V_49 , V_71 ) ;
F_44 (flow, head, flow_table.node[ti->node_ver]) {
if ( V_19 -> V_10 == V_10 && V_19 -> V_36 . V_71 == V_71 &&
F_62 ( V_19 , & V_97 , & V_10 -> V_2 ) )
return V_19 ;
}
return NULL ;
}
struct V_18 * F_65 ( struct V_36 * V_98 ,
const struct V_5 * V_14 ,
V_54 * V_99 )
{
struct V_48 * V_49 = F_66 ( V_98 -> V_49 ) ;
struct V_9 * V_10 ;
struct V_18 * V_19 ;
* V_99 = 0 ;
F_67 (mask, &tbl->mask_list, list) {
( * V_99 ) ++ ;
V_19 = F_64 ( V_49 , V_14 , V_10 ) ;
if ( V_19 )
return V_19 ;
}
return NULL ;
}
struct V_18 * F_68 ( struct V_36 * V_98 ,
const struct V_5 * V_14 )
{
V_54 T_2 V_99 ;
return F_65 ( V_98 , V_14 , & V_99 ) ;
}
struct V_18 * F_69 ( struct V_36 * V_98 ,
const struct V_94 * V_95 )
{
struct V_48 * V_49 = F_66 ( V_98 -> V_49 ) ;
struct V_9 * V_10 ;
struct V_18 * V_19 ;
F_70 (mask, &tbl->mask_list, list) {
V_19 = F_64 ( V_49 , V_95 -> V_14 , V_10 ) ;
if ( V_19 && F_20 ( & V_19 -> V_27 ) &&
F_63 ( V_19 , V_95 ) )
return V_19 ;
}
return NULL ;
}
static V_54 F_71 ( const struct V_100 * V_101 )
{
return F_72 ( V_101 -> V_74 , V_101 -> V_29 , 0 ) ;
}
static bool F_73 ( const struct V_18 * V_19 ,
const struct V_100 * V_101 )
{
if ( V_19 -> V_27 . V_29 != V_101 -> V_29 )
return false ;
return ! memcmp ( V_19 -> V_27 . V_74 , V_101 -> V_74 , V_101 -> V_29 ) ;
}
bool F_74 ( const struct V_18 * V_19 , const struct V_94 * V_95 )
{
if ( F_40 ( & V_19 -> V_27 ) )
return F_62 ( V_19 , V_95 -> V_14 , & V_95 -> V_2 ) ;
return F_63 ( V_19 , V_95 ) ;
}
struct V_18 * F_75 ( struct V_36 * V_98 ,
const struct V_100 * V_74 )
{
struct V_48 * V_49 = F_66 ( V_98 -> V_55 ) ;
struct V_18 * V_19 ;
struct V_42 * V_63 ;
V_54 V_71 ;
V_71 = F_71 ( V_74 ) ;
V_63 = F_45 ( V_49 , V_71 ) ;
F_44 (flow, head, ufid_table.node[ti->node_ver]) {
if ( V_19 -> V_68 . V_71 == V_71 &&
F_73 ( V_19 , V_74 ) )
return V_19 ;
}
return NULL ;
}
int F_76 ( const struct V_36 * V_37 )
{
struct V_9 * V_10 ;
int V_102 = 0 ;
F_70 (mask, &table->mask_list, list)
V_102 ++ ;
return V_102 ;
}
static struct V_48 * F_77 ( struct V_48 * V_49 ,
bool V_74 )
{
return F_52 ( V_49 , V_49 -> V_40 * 2 , V_74 ) ;
}
static void F_78 ( struct V_36 * V_98 , struct V_9 * V_10 )
{
if ( V_10 ) {
F_79 () ;
F_37 ( ! V_10 -> V_103 ) ;
V_10 -> V_103 -- ;
if ( ! V_10 -> V_103 ) {
F_80 ( & V_10 -> V_104 ) ;
F_81 ( V_10 , V_46 ) ;
}
}
}
void F_82 ( struct V_36 * V_37 , struct V_18 * V_19 )
{
struct V_48 * V_49 = F_54 ( V_37 -> V_49 ) ;
struct V_48 * V_55 = F_54 ( V_37 -> V_55 ) ;
F_37 ( V_37 -> V_38 == 0 ) ;
F_39 ( & V_19 -> V_36 . V_22 [ V_49 -> V_51 ] ) ;
V_37 -> V_38 -- ;
if ( F_40 ( & V_19 -> V_27 ) ) {
F_39 ( & V_19 -> V_68 . V_22 [ V_55 -> V_51 ] ) ;
V_37 -> V_61 -- ;
}
F_78 ( V_37 , V_19 -> V_10 ) ;
}
static struct V_9 * F_83 ( void )
{
struct V_9 * V_10 ;
V_10 = F_30 ( sizeof( * V_10 ) , V_24 ) ;
if ( V_10 )
V_10 -> V_103 = 1 ;
return V_10 ;
}
static bool F_84 ( const struct V_9 * V_105 ,
const struct V_9 * V_106 )
{
const V_13 * V_107 = ( const V_13 * ) & V_105 -> V_14 + V_105 -> V_2 . V_4 ;
const V_13 * V_108 = ( const V_13 * ) & V_106 -> V_14 + V_106 -> V_2 . V_4 ;
return ( V_105 -> V_2 . V_3 == V_106 -> V_2 . V_3 )
&& ( V_105 -> V_2 . V_4 == V_106 -> V_2 . V_4 )
&& ( memcmp ( V_107 , V_108 , F_1 ( & V_105 -> V_2 ) ) == 0 ) ;
}
static struct V_9 * F_85 ( const struct V_36 * V_98 ,
const struct V_9 * V_10 )
{
struct V_109 * V_110 ;
F_86 (ml, &tbl->mask_list) {
struct V_9 * V_12 ;
V_12 = F_24 ( V_110 , struct V_9 , V_104 ) ;
if ( F_84 ( V_10 , V_12 ) )
return V_12 ;
}
return NULL ;
}
static int F_87 ( struct V_36 * V_98 , struct V_18 * V_19 ,
const struct V_9 * V_73 )
{
struct V_9 * V_10 ;
V_10 = F_85 ( V_98 , V_73 ) ;
if ( ! V_10 ) {
V_10 = F_83 () ;
if ( ! V_10 )
return - V_25 ;
V_10 -> V_14 = V_73 -> V_14 ;
V_10 -> V_2 = V_73 -> V_2 ;
F_88 ( & V_10 -> V_104 , & V_98 -> V_58 ) ;
} else {
F_37 ( ! V_10 -> V_103 ) ;
V_10 -> V_103 ++ ;
}
V_19 -> V_10 = V_10 ;
return 0 ;
}
static void F_89 ( struct V_36 * V_37 , struct V_18 * V_19 )
{
struct V_48 * V_76 = NULL ;
struct V_48 * V_49 ;
V_19 -> V_36 . V_71 = F_55 ( & V_19 -> V_14 , & V_19 -> V_10 -> V_2 ) ;
V_49 = F_54 ( V_37 -> V_49 ) ;
F_47 ( V_49 , V_19 ) ;
V_37 -> V_38 ++ ;
if ( V_37 -> V_38 > V_49 -> V_40 )
V_76 = F_77 ( V_49 , false ) ;
else if ( F_90 ( V_60 , V_37 -> V_59 + V_111 ) )
V_76 = F_52 ( V_49 , V_49 -> V_40 , false ) ;
if ( V_76 ) {
F_33 ( V_37 -> V_49 , V_76 ) ;
F_26 ( & V_49 -> V_46 , F_35 ) ;
V_37 -> V_59 = V_60 ;
}
}
static void F_91 ( struct V_36 * V_37 , struct V_18 * V_19 )
{
struct V_48 * V_49 ;
V_19 -> V_68 . V_71 = F_71 ( & V_19 -> V_27 ) ;
V_49 = F_54 ( V_37 -> V_55 ) ;
F_49 ( V_49 , V_19 ) ;
V_37 -> V_61 ++ ;
if ( V_37 -> V_61 > V_49 -> V_40 ) {
struct V_48 * V_76 ;
V_76 = F_77 ( V_49 , true ) ;
if ( V_76 ) {
F_33 ( V_37 -> V_55 , V_76 ) ;
F_26 ( & V_49 -> V_46 , F_35 ) ;
}
}
}
int F_92 ( struct V_36 * V_37 , struct V_18 * V_19 ,
const struct V_9 * V_10 )
{
int V_34 ;
V_34 = F_87 ( V_37 , V_19 , V_10 ) ;
if ( V_34 )
return V_34 ;
F_89 ( V_37 , V_19 ) ;
if ( F_40 ( & V_19 -> V_27 ) )
F_91 ( V_37 , V_19 ) ;
return 0 ;
}
int F_93 ( void )
{
F_56 ( F_94 ( struct V_5 ) % F_94 ( long ) ) ;
F_56 ( sizeof( struct V_5 ) % sizeof( long ) ) ;
V_23 = F_95 ( L_1 , sizeof( struct V_18 )
+ ( V_112
* sizeof( struct V_20 * ) ) ,
0 , 0 , NULL ) ;
if ( V_23 == NULL )
return - V_25 ;
V_32
= F_95 ( L_2 , sizeof( struct V_20 ) ,
0 , V_113 , NULL ) ;
if ( V_32 == NULL ) {
F_96 ( V_23 ) ;
V_23 = NULL ;
return - V_25 ;
}
return 0 ;
}
void F_97 ( void )
{
F_96 ( V_32 ) ;
F_96 ( V_23 ) ;
}
