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
V_19 = F_4 ( V_22 , V_23 ) ;
if ( ! V_19 )
return F_5 ( - V_24 ) ;
V_19 -> V_25 = - 1 ;
V_21 = F_6 ( V_26 ,
V_23 | V_27 ,
F_7 ( 0 ) ? 0 : V_28 ) ;
if ( ! V_21 )
goto V_29;
F_8 ( & V_21 -> V_30 ) ;
F_9 ( V_19 -> V_21 [ 0 ] , V_21 ) ;
return V_19 ;
V_29:
F_10 ( V_22 , V_19 ) ;
return F_5 ( - V_24 ) ;
}
int F_11 ( const struct V_31 * V_32 )
{
return V_32 -> V_33 ;
}
static struct V_34 * F_12 ( unsigned int V_35 )
{
struct V_34 * V_36 ;
int V_17 , V_29 ;
V_36 = F_13 ( sizeof( struct V_37 ) ,
V_35 , V_23 ) ;
if ( ! V_36 )
return NULL ;
V_29 = F_14 ( V_36 , 0 , V_35 , V_23 ) ;
if ( V_29 ) {
F_15 ( V_36 ) ;
return NULL ;
}
for ( V_17 = 0 ; V_17 < V_35 ; V_17 ++ )
F_16 ( (struct V_37 * )
F_17 ( V_36 , V_17 ) ) ;
return V_36 ;
}
static void F_18 ( struct V_18 * V_19 )
{
int V_38 ;
if ( F_19 ( & V_19 -> V_39 ) )
F_20 ( V_19 -> V_39 . V_40 ) ;
if ( V_19 -> V_41 )
F_21 ( (struct V_42 V_43 * ) V_19 -> V_41 ) ;
for ( V_38 = 0 ; V_38 < V_44 ; V_38 = F_22 ( V_38 , V_45 ) )
if ( V_19 -> V_21 [ V_38 ] )
F_10 ( V_26 ,
(struct V_20 V_43 * ) V_19 -> V_21 [ V_38 ] ) ;
F_10 ( V_22 , V_19 ) ;
}
static void F_23 ( struct V_46 * V_47 )
{
struct V_18 * V_19 = F_24 ( V_47 , struct V_18 , V_47 ) ;
F_18 ( V_19 ) ;
}
void F_25 ( struct V_18 * V_19 , bool V_48 )
{
if ( ! V_19 )
return;
if ( V_48 )
F_26 ( & V_19 -> V_47 , F_23 ) ;
else
F_18 ( V_19 ) ;
}
static void F_27 ( struct V_34 * V_36 )
{
F_15 ( V_36 ) ;
}
static void F_28 ( struct V_49 * V_50 )
{
F_27 ( V_50 -> V_36 ) ;
F_20 ( V_50 ) ;
}
static struct V_49 * F_29 ( int V_51 )
{
struct V_49 * V_50 = F_30 ( sizeof( * V_50 ) , V_23 ) ;
if ( ! V_50 )
return NULL ;
V_50 -> V_36 = F_12 ( V_51 ) ;
if ( ! V_50 -> V_36 ) {
F_20 ( V_50 ) ;
return NULL ;
}
V_50 -> V_35 = V_51 ;
V_50 -> V_52 = 0 ;
V_50 -> V_53 = false ;
F_31 ( & V_50 -> V_54 , sizeof( V_55 ) ) ;
return V_50 ;
}
int F_32 ( struct V_31 * V_32 )
{
struct V_49 * V_50 , * V_56 ;
V_50 = F_29 ( V_57 ) ;
if ( ! V_50 )
return - V_24 ;
V_56 = F_29 ( V_57 ) ;
if ( ! V_56 )
goto V_58;
F_33 ( V_32 -> V_50 , V_50 ) ;
F_33 ( V_32 -> V_56 , V_56 ) ;
F_34 ( & V_32 -> V_59 ) ;
V_32 -> V_60 = V_61 ;
V_32 -> V_33 = 0 ;
V_32 -> V_62 = 0 ;
return 0 ;
V_58:
F_28 ( V_50 ) ;
return - V_24 ;
}
static void F_35 ( struct V_46 * V_47 )
{
struct V_49 * V_50 = F_24 ( V_47 , struct V_49 , V_47 ) ;
F_28 ( V_50 ) ;
}
static void F_36 ( struct V_49 * V_50 ,
struct V_49 * V_56 ,
bool V_48 )
{
int V_17 ;
if ( ! V_50 )
return;
F_37 ( ! V_56 ) ;
if ( V_50 -> V_53 )
goto V_63;
for ( V_17 = 0 ; V_17 < V_50 -> V_35 ; V_17 ++ ) {
struct V_18 * V_19 ;
struct V_37 * V_64 = F_17 ( V_50 -> V_36 , V_17 ) ;
struct V_65 * V_66 ;
int V_67 = V_50 -> V_52 ;
int V_68 = V_56 -> V_52 ;
F_38 (flow, n, head, flow_table.node[ver]) {
F_39 ( & V_19 -> V_31 . V_69 [ V_67 ] ) ;
if ( F_40 ( & V_19 -> V_39 ) )
F_39 ( & V_19 -> V_70 . V_69 [ V_68 ] ) ;
F_25 ( V_19 , V_48 ) ;
}
}
V_63:
if ( V_48 ) {
F_26 ( & V_50 -> V_47 , F_35 ) ;
F_26 ( & V_56 -> V_47 , F_35 ) ;
} else {
F_28 ( V_50 ) ;
F_28 ( V_56 ) ;
}
}
void F_41 ( struct V_31 * V_32 )
{
struct V_49 * V_50 = F_42 ( V_32 -> V_50 ) ;
struct V_49 * V_56 = F_42 ( V_32 -> V_56 ) ;
F_36 ( V_50 , V_56 , false ) ;
}
struct V_18 * F_43 ( struct V_49 * V_50 ,
V_55 * V_71 , V_55 * V_72 )
{
struct V_18 * V_19 ;
struct V_37 * V_64 ;
int V_67 ;
int V_17 ;
V_67 = V_50 -> V_52 ;
while ( * V_71 < V_50 -> V_35 ) {
V_17 = 0 ;
V_64 = F_17 ( V_50 -> V_36 , * V_71 ) ;
F_44 (flow, head, flow_table.node[ver]) {
if ( V_17 < * V_72 ) {
V_17 ++ ;
continue;
}
* V_72 = V_17 + 1 ;
return V_19 ;
}
( * V_71 ) ++ ;
* V_72 = 0 ;
}
return NULL ;
}
static struct V_37 * F_45 ( struct V_49 * V_50 , V_55 V_73 )
{
V_73 = F_46 ( V_73 , V_50 -> V_54 ) ;
return F_17 ( V_50 -> V_36 ,
( V_73 & ( V_50 -> V_35 - 1 ) ) ) ;
}
static void F_47 ( struct V_49 * V_50 ,
struct V_18 * V_19 )
{
struct V_37 * V_64 ;
V_64 = F_45 ( V_50 , V_19 -> V_31 . V_73 ) ;
F_48 ( & V_19 -> V_31 . V_69 [ V_50 -> V_52 ] , V_64 ) ;
}
static void F_49 ( struct V_49 * V_50 ,
struct V_18 * V_19 )
{
struct V_37 * V_64 ;
V_64 = F_45 ( V_50 , V_19 -> V_70 . V_73 ) ;
F_48 ( & V_19 -> V_70 . V_69 [ V_50 -> V_52 ] , V_64 ) ;
}
static void F_50 ( struct V_49 * V_74 ,
struct V_49 * V_75 , bool V_76 )
{
int V_77 ;
int V_17 ;
V_77 = V_74 -> V_52 ;
V_75 -> V_52 = ! V_77 ;
for ( V_17 = 0 ; V_17 < V_74 -> V_35 ; V_17 ++ ) {
struct V_18 * V_19 ;
struct V_37 * V_64 ;
V_64 = F_17 ( V_74 -> V_36 , V_17 ) ;
if ( V_76 )
F_51 (flow, head,
ufid_table.node[old_ver])
F_49 ( V_75 , V_19 ) ;
else
F_51 (flow, head,
flow_table.node[old_ver])
F_47 ( V_75 , V_19 ) ;
}
V_74 -> V_53 = true ;
}
static struct V_49 * F_52 ( struct V_49 * V_50 ,
int V_35 , bool V_76 )
{
struct V_49 * V_78 ;
V_78 = F_29 ( V_35 ) ;
if ( ! V_78 )
return NULL ;
F_50 ( V_50 , V_78 , V_76 ) ;
return V_78 ;
}
int F_53 ( struct V_31 * V_31 )
{
struct V_49 * V_79 , * V_78 ;
struct V_49 * V_80 , * V_81 ;
V_78 = F_29 ( V_57 ) ;
if ( ! V_78 )
return - V_24 ;
V_81 = F_29 ( V_57 ) ;
if ( ! V_81 )
goto V_82;
V_79 = F_54 ( V_31 -> V_50 ) ;
V_80 = F_54 ( V_31 -> V_56 ) ;
F_33 ( V_31 -> V_50 , V_78 ) ;
F_33 ( V_31 -> V_56 , V_81 ) ;
V_31 -> V_60 = V_61 ;
V_31 -> V_33 = 0 ;
V_31 -> V_62 = 0 ;
F_36 ( V_79 , V_80 , true ) ;
return 0 ;
V_82:
F_28 ( V_78 ) ;
return - V_24 ;
}
static V_55 F_55 ( const struct V_5 * V_14 ,
const struct V_1 * V_2 )
{
int V_83 = V_2 -> V_4 ;
int V_84 = V_2 -> V_3 ;
const V_55 * V_85 = ( const V_55 * ) ( ( const V_13 * ) V_14 + V_83 ) ;
int V_86 = ( V_84 - V_83 ) >> 2 ;
F_56 ( sizeof( long ) % sizeof( V_55 ) ) ;
return F_57 ( V_85 , V_86 , 0 ) ;
}
static int F_58 ( const struct V_5 * V_14 )
{
if ( V_14 -> V_87 )
return 0 ;
else
return F_59 ( F_60 ( struct V_5 , V_88 ) ,
sizeof( long ) ) ;
}
static bool F_61 ( const struct V_5 * V_89 ,
const struct V_5 * V_90 ,
int V_83 , int V_84 )
{
const long * V_91 = ( const long * ) ( ( const V_13 * ) V_89 + V_83 ) ;
const long * V_92 = ( const long * ) ( ( const V_13 * ) V_90 + V_83 ) ;
long V_93 = 0 ;
int V_17 ;
for ( V_17 = V_83 ; V_17 < V_84 ; V_17 += sizeof( long ) )
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
int V_83 = F_58 ( V_14 ) ;
int V_84 = V_95 -> V_2 . V_3 ;
F_37 ( F_40 ( & V_19 -> V_39 ) ) ;
return F_61 ( V_19 -> V_39 . V_40 , V_14 , V_83 , V_84 ) ;
}
static struct V_18 * F_64 ( struct V_49 * V_50 ,
const struct V_5 * V_96 ,
const struct V_9 * V_10 )
{
struct V_18 * V_19 ;
struct V_37 * V_64 ;
V_55 V_73 ;
struct V_5 V_97 ;
F_2 ( & V_97 , V_96 , false , V_10 ) ;
V_73 = F_55 ( & V_97 , & V_10 -> V_2 ) ;
V_64 = F_45 ( V_50 , V_73 ) ;
F_44 (flow, head, flow_table.node[ti->node_ver]) {
if ( V_19 -> V_10 == V_10 && V_19 -> V_31 . V_73 == V_73 &&
F_62 ( V_19 , & V_97 , & V_10 -> V_2 ) )
return V_19 ;
}
return NULL ;
}
struct V_18 * F_65 ( struct V_31 * V_98 ,
const struct V_5 * V_14 ,
V_55 * V_99 )
{
struct V_49 * V_50 = F_66 ( V_98 -> V_50 ) ;
struct V_9 * V_10 ;
struct V_18 * V_19 ;
* V_99 = 0 ;
F_67 (mask, &tbl->mask_list, list) {
( * V_99 ) ++ ;
V_19 = F_64 ( V_50 , V_14 , V_10 ) ;
if ( V_19 )
return V_19 ;
}
return NULL ;
}
struct V_18 * F_68 ( struct V_31 * V_98 ,
const struct V_5 * V_14 )
{
V_55 T_2 V_99 ;
return F_65 ( V_98 , V_14 , & V_99 ) ;
}
struct V_18 * F_69 ( struct V_31 * V_98 ,
const struct V_94 * V_95 )
{
struct V_49 * V_50 = F_66 ( V_98 -> V_50 ) ;
struct V_9 * V_10 ;
struct V_18 * V_19 ;
F_70 (mask, &tbl->mask_list, list) {
V_19 = F_64 ( V_50 , V_95 -> V_14 , V_10 ) ;
if ( V_19 && F_19 ( & V_19 -> V_39 ) &&
F_63 ( V_19 , V_95 ) )
return V_19 ;
}
return NULL ;
}
static V_55 F_71 ( const struct V_100 * V_101 )
{
return F_72 ( V_101 -> V_76 , V_101 -> V_102 , 0 ) ;
}
static bool F_73 ( const struct V_18 * V_19 ,
const struct V_100 * V_101 )
{
if ( V_19 -> V_39 . V_102 != V_101 -> V_102 )
return false ;
return ! memcmp ( V_19 -> V_39 . V_76 , V_101 -> V_76 , V_101 -> V_102 ) ;
}
bool F_74 ( const struct V_18 * V_19 , const struct V_94 * V_95 )
{
if ( F_40 ( & V_19 -> V_39 ) )
return F_62 ( V_19 , V_95 -> V_14 , & V_95 -> V_2 ) ;
return F_63 ( V_19 , V_95 ) ;
}
struct V_18 * F_75 ( struct V_31 * V_98 ,
const struct V_100 * V_76 )
{
struct V_49 * V_50 = F_66 ( V_98 -> V_56 ) ;
struct V_18 * V_19 ;
struct V_37 * V_64 ;
V_55 V_73 ;
V_73 = F_71 ( V_76 ) ;
V_64 = F_45 ( V_50 , V_73 ) ;
F_44 (flow, head, ufid_table.node[ti->node_ver]) {
if ( V_19 -> V_70 . V_73 == V_73 &&
F_73 ( V_19 , V_76 ) )
return V_19 ;
}
return NULL ;
}
int F_76 ( const struct V_31 * V_32 )
{
struct V_9 * V_10 ;
int V_103 = 0 ;
F_70 (mask, &table->mask_list, list)
V_103 ++ ;
return V_103 ;
}
static struct V_49 * F_77 ( struct V_49 * V_50 ,
bool V_76 )
{
return F_52 ( V_50 , V_50 -> V_35 * 2 , V_76 ) ;
}
static void F_78 ( struct V_31 * V_98 , struct V_9 * V_10 )
{
if ( V_10 ) {
F_79 () ;
F_37 ( ! V_10 -> V_104 ) ;
V_10 -> V_104 -- ;
if ( ! V_10 -> V_104 ) {
F_80 ( & V_10 -> V_105 ) ;
F_81 ( V_10 , V_47 ) ;
}
}
}
void F_82 ( struct V_31 * V_32 , struct V_18 * V_19 )
{
struct V_49 * V_50 = F_54 ( V_32 -> V_50 ) ;
struct V_49 * V_56 = F_54 ( V_32 -> V_56 ) ;
F_37 ( V_32 -> V_33 == 0 ) ;
F_39 ( & V_19 -> V_31 . V_69 [ V_50 -> V_52 ] ) ;
V_32 -> V_33 -- ;
if ( F_40 ( & V_19 -> V_39 ) ) {
F_39 ( & V_19 -> V_70 . V_69 [ V_56 -> V_52 ] ) ;
V_32 -> V_62 -- ;
}
F_78 ( V_32 , V_19 -> V_10 ) ;
}
static struct V_9 * F_83 ( void )
{
struct V_9 * V_10 ;
V_10 = F_30 ( sizeof( * V_10 ) , V_23 ) ;
if ( V_10 )
V_10 -> V_104 = 1 ;
return V_10 ;
}
static bool F_84 ( const struct V_9 * V_106 ,
const struct V_9 * V_107 )
{
const V_13 * V_108 = ( const V_13 * ) & V_106 -> V_14 + V_106 -> V_2 . V_4 ;
const V_13 * V_109 = ( const V_13 * ) & V_107 -> V_14 + V_107 -> V_2 . V_4 ;
return ( V_106 -> V_2 . V_3 == V_107 -> V_2 . V_3 )
&& ( V_106 -> V_2 . V_4 == V_107 -> V_2 . V_4 )
&& ( memcmp ( V_108 , V_109 , F_1 ( & V_106 -> V_2 ) ) == 0 ) ;
}
static struct V_9 * F_85 ( const struct V_31 * V_98 ,
const struct V_9 * V_10 )
{
struct V_110 * V_111 ;
F_86 (ml, &tbl->mask_list) {
struct V_9 * V_12 ;
V_12 = F_24 ( V_111 , struct V_9 , V_105 ) ;
if ( F_84 ( V_10 , V_12 ) )
return V_12 ;
}
return NULL ;
}
static int F_87 ( struct V_31 * V_98 , struct V_18 * V_19 ,
const struct V_9 * V_75 )
{
struct V_9 * V_10 ;
V_10 = F_85 ( V_98 , V_75 ) ;
if ( ! V_10 ) {
V_10 = F_83 () ;
if ( ! V_10 )
return - V_24 ;
V_10 -> V_14 = V_75 -> V_14 ;
V_10 -> V_2 = V_75 -> V_2 ;
F_88 ( & V_10 -> V_105 , & V_98 -> V_59 ) ;
} else {
F_37 ( ! V_10 -> V_104 ) ;
V_10 -> V_104 ++ ;
}
V_19 -> V_10 = V_10 ;
return 0 ;
}
static void F_89 ( struct V_31 * V_32 , struct V_18 * V_19 )
{
struct V_49 * V_78 = NULL ;
struct V_49 * V_50 ;
V_19 -> V_31 . V_73 = F_55 ( & V_19 -> V_14 , & V_19 -> V_10 -> V_2 ) ;
V_50 = F_54 ( V_32 -> V_50 ) ;
F_47 ( V_50 , V_19 ) ;
V_32 -> V_33 ++ ;
if ( V_32 -> V_33 > V_50 -> V_35 )
V_78 = F_77 ( V_50 , false ) ;
else if ( F_90 ( V_61 , V_32 -> V_60 + V_112 ) )
V_78 = F_52 ( V_50 , V_50 -> V_35 , false ) ;
if ( V_78 ) {
F_33 ( V_32 -> V_50 , V_78 ) ;
F_26 ( & V_50 -> V_47 , F_35 ) ;
V_32 -> V_60 = V_61 ;
}
}
static void F_91 ( struct V_31 * V_32 , struct V_18 * V_19 )
{
struct V_49 * V_50 ;
V_19 -> V_70 . V_73 = F_71 ( & V_19 -> V_39 ) ;
V_50 = F_54 ( V_32 -> V_56 ) ;
F_49 ( V_50 , V_19 ) ;
V_32 -> V_62 ++ ;
if ( V_32 -> V_62 > V_50 -> V_35 ) {
struct V_49 * V_78 ;
V_78 = F_77 ( V_50 , true ) ;
if ( V_78 ) {
F_33 ( V_32 -> V_56 , V_78 ) ;
F_26 ( & V_50 -> V_47 , F_35 ) ;
}
}
}
int F_92 ( struct V_31 * V_32 , struct V_18 * V_19 ,
const struct V_9 * V_10 )
{
int V_29 ;
V_29 = F_87 ( V_32 , V_19 , V_10 ) ;
if ( V_29 )
return V_29 ;
F_89 ( V_32 , V_19 ) ;
if ( F_40 ( & V_19 -> V_39 ) )
F_91 ( V_32 , V_19 ) ;
return 0 ;
}
int F_93 ( void )
{
F_56 ( F_94 ( struct V_5 ) % F_94 ( long ) ) ;
F_56 ( sizeof( struct V_5 ) % sizeof( long ) ) ;
V_22 = F_95 ( L_1 , sizeof( struct V_18 )
+ ( V_44
* sizeof( struct V_20 * ) ) ,
0 , 0 , NULL ) ;
if ( V_22 == NULL )
return - V_24 ;
V_26
= F_95 ( L_2 , sizeof( struct V_20 ) ,
0 , V_113 , NULL ) ;
if ( V_26 == NULL ) {
F_96 ( V_22 ) ;
V_22 = NULL ;
return - V_24 ;
}
return 0 ;
}
void F_97 ( void )
{
F_96 ( V_26 ) ;
F_96 ( V_22 ) ;
}
