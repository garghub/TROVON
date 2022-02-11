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
V_17 -> V_25 = V_26 ;
V_19 = F_6 ( V_27 ,
V_22 | V_28 , 0 ) ;
if ( ! V_19 )
goto V_29;
F_7 ( & V_19 -> V_30 ) ;
F_8 ( V_17 -> V_19 [ 0 ] , V_19 ) ;
F_9 (node)
if ( V_20 != 0 )
F_8 ( V_17 -> V_19 [ V_20 ] , NULL ) ;
return V_17 ;
V_29:
F_10 ( V_21 , V_17 ) ;
return F_5 ( - V_23 ) ;
}
int F_11 ( const struct V_31 * V_32 )
{
return V_32 -> V_33 ;
}
static struct V_34 * F_12 ( unsigned int V_35 )
{
struct V_34 * V_36 ;
int V_15 , V_29 ;
V_36 = F_13 ( sizeof( struct V_37 ) ,
V_35 , V_22 ) ;
if ( ! V_36 )
return NULL ;
V_29 = F_14 ( V_36 , 0 , V_35 , V_22 ) ;
if ( V_29 ) {
F_15 ( V_36 ) ;
return NULL ;
}
for ( V_15 = 0 ; V_15 < V_35 ; V_15 ++ )
F_16 ( (struct V_37 * )
F_17 ( V_36 , V_15 ) ) ;
return V_36 ;
}
static void F_18 ( struct V_16 * V_17 )
{
int V_20 ;
F_19 ( (struct V_38 V_39 * ) V_17 -> V_24 ) ;
F_9 (node)
if ( V_17 -> V_19 [ V_20 ] )
F_10 ( V_27 ,
(struct V_18 V_39 * ) V_17 -> V_19 [ V_20 ] ) ;
F_10 ( V_21 , V_17 ) ;
}
static void F_20 ( struct V_40 * V_41 )
{
struct V_16 * V_17 = F_21 ( V_41 , struct V_16 , V_41 ) ;
F_18 ( V_17 ) ;
}
void F_22 ( struct V_16 * V_17 , bool V_42 )
{
if ( ! V_17 )
return;
if ( V_42 )
F_23 ( & V_17 -> V_41 , F_20 ) ;
else
F_18 ( V_17 ) ;
}
static void F_24 ( struct V_34 * V_36 )
{
F_15 ( V_36 ) ;
}
static void F_25 ( struct V_43 * V_44 )
{
F_24 ( V_44 -> V_36 ) ;
F_19 ( V_44 ) ;
}
static struct V_43 * F_26 ( int V_45 )
{
struct V_43 * V_44 = F_27 ( sizeof( * V_44 ) , V_22 ) ;
if ( ! V_44 )
return NULL ;
V_44 -> V_36 = F_12 ( V_45 ) ;
if ( ! V_44 -> V_36 ) {
F_19 ( V_44 ) ;
return NULL ;
}
V_44 -> V_35 = V_45 ;
V_44 -> V_46 = 0 ;
V_44 -> V_47 = false ;
F_28 ( & V_44 -> V_48 , sizeof( V_49 ) ) ;
return V_44 ;
}
int F_29 ( struct V_31 * V_32 )
{
struct V_43 * V_44 ;
V_44 = F_26 ( V_50 ) ;
if ( ! V_44 )
return - V_23 ;
F_30 ( V_32 -> V_44 , V_44 ) ;
F_31 ( & V_32 -> V_51 ) ;
V_32 -> V_52 = V_53 ;
V_32 -> V_33 = 0 ;
return 0 ;
}
static void F_32 ( struct V_40 * V_41 )
{
struct V_43 * V_44 = F_21 ( V_41 , struct V_43 , V_41 ) ;
F_25 ( V_44 ) ;
}
static void F_33 ( struct V_43 * V_44 , bool V_42 )
{
int V_15 ;
if ( ! V_44 )
return;
if ( V_44 -> V_47 )
goto V_54;
for ( V_15 = 0 ; V_15 < V_44 -> V_35 ; V_15 ++ ) {
struct V_16 * V_17 ;
struct V_37 * V_55 = F_17 ( V_44 -> V_36 , V_15 ) ;
struct V_56 * V_57 ;
int V_58 = V_44 -> V_46 ;
F_34 (flow, n, head, hash_node[ver]) {
F_35 ( & V_17 -> V_59 [ V_58 ] ) ;
F_22 ( V_17 , V_42 ) ;
}
}
V_54:
if ( V_42 )
F_23 ( & V_44 -> V_41 , F_32 ) ;
else
F_25 ( V_44 ) ;
}
void F_36 ( struct V_31 * V_32 )
{
struct V_43 * V_44 = F_37 ( V_32 -> V_44 ) ;
F_33 ( V_44 , false ) ;
}
struct V_16 * F_38 ( struct V_43 * V_44 ,
V_49 * V_60 , V_49 * V_61 )
{
struct V_16 * V_17 ;
struct V_37 * V_55 ;
int V_58 ;
int V_15 ;
V_58 = V_44 -> V_46 ;
while ( * V_60 < V_44 -> V_35 ) {
V_15 = 0 ;
V_55 = F_17 ( V_44 -> V_36 , * V_60 ) ;
F_39 (flow, head, hash_node[ver]) {
if ( V_15 < * V_61 ) {
V_15 ++ ;
continue;
}
* V_61 = V_15 + 1 ;
return V_17 ;
}
( * V_60 ) ++ ;
* V_61 = 0 ;
}
return NULL ;
}
static struct V_37 * F_40 ( struct V_43 * V_44 , V_49 V_62 )
{
V_62 = F_41 ( V_62 , V_44 -> V_48 ) ;
return F_17 ( V_44 -> V_36 ,
( V_62 & ( V_44 -> V_35 - 1 ) ) ) ;
}
static void F_42 ( struct V_43 * V_44 , struct V_16 * V_17 )
{
struct V_37 * V_55 ;
V_55 = F_40 ( V_44 , V_17 -> V_62 ) ;
F_43 ( & V_17 -> V_59 [ V_44 -> V_46 ] , V_55 ) ;
}
static void F_44 ( struct V_43 * V_63 ,
struct V_43 * V_64 )
{
int V_65 ;
int V_15 ;
V_65 = V_63 -> V_46 ;
V_64 -> V_46 = ! V_65 ;
for ( V_15 = 0 ; V_15 < V_63 -> V_35 ; V_15 ++ ) {
struct V_16 * V_17 ;
struct V_37 * V_55 ;
V_55 = F_17 ( V_63 -> V_36 , V_15 ) ;
F_45 (flow, head, hash_node[old_ver])
F_42 ( V_64 , V_17 ) ;
}
V_63 -> V_47 = true ;
}
static struct V_43 * F_46 ( struct V_43 * V_44 ,
int V_35 )
{
struct V_43 * V_66 ;
V_66 = F_26 ( V_35 ) ;
if ( ! V_66 )
return NULL ;
F_44 ( V_44 , V_66 ) ;
return V_66 ;
}
int F_47 ( struct V_31 * V_31 )
{
struct V_43 * V_67 ;
struct V_43 * V_66 ;
V_67 = F_48 ( V_31 -> V_44 ) ;
V_66 = F_26 ( V_50 ) ;
if ( ! V_66 )
return - V_23 ;
F_30 ( V_31 -> V_44 , V_66 ) ;
V_31 -> V_52 = V_53 ;
V_31 -> V_33 = 0 ;
F_33 ( V_67 , true ) ;
return 0 ;
}
static V_49 F_49 ( const struct V_5 * V_12 , int V_68 ,
int V_69 )
{
const V_49 * V_70 = ( const V_49 * ) ( ( const V_11 * ) V_12 + V_68 ) ;
int V_71 = ( V_69 - V_68 ) >> 2 ;
F_50 ( sizeof( long ) % sizeof( V_49 ) ) ;
return F_51 ( V_70 , V_71 , 0 ) ;
}
static int F_52 ( const struct V_5 * V_12 )
{
if ( V_12 -> V_72 . V_73 )
return 0 ;
else
return F_53 ( F_54 ( struct V_5 , V_74 ) ,
sizeof( long ) ) ;
}
static bool F_55 ( const struct V_5 * V_75 ,
const struct V_5 * V_76 ,
int V_68 , int V_69 )
{
const long * V_77 = ( const long * ) ( ( const V_11 * ) V_75 + V_68 ) ;
const long * V_78 = ( const long * ) ( ( const V_11 * ) V_76 + V_68 ) ;
long V_79 = 0 ;
int V_15 ;
for ( V_15 = V_68 ; V_15 < V_69 ; V_15 += sizeof( long ) )
V_79 |= * V_77 ++ ^ * V_78 ++ ;
return V_79 == 0 ;
}
static bool F_56 ( const struct V_16 * V_17 ,
const struct V_5 * V_12 ,
int V_68 , int V_69 )
{
return F_55 ( & V_17 -> V_12 , V_12 , V_68 , V_69 ) ;
}
bool F_57 ( const struct V_16 * V_17 ,
const struct V_80 * V_81 )
{
struct V_5 * V_12 = V_81 -> V_12 ;
int V_68 = F_52 ( V_12 ) ;
int V_69 = V_81 -> V_2 . V_3 ;
return F_55 ( & V_17 -> V_82 , V_12 , V_68 , V_69 ) ;
}
static struct V_16 * F_58 ( struct V_43 * V_44 ,
const struct V_5 * V_83 ,
const struct V_8 * V_9 )
{
struct V_16 * V_17 ;
struct V_37 * V_55 ;
int V_68 = V_9 -> V_2 . V_4 ;
int V_69 = V_9 -> V_2 . V_3 ;
V_49 V_62 ;
struct V_5 V_84 ;
F_2 ( & V_84 , V_83 , V_9 ) ;
V_62 = F_49 ( & V_84 , V_68 , V_69 ) ;
V_55 = F_40 ( V_44 , V_62 ) ;
F_39 (flow, head, hash_node[ti->node_ver]) {
if ( V_17 -> V_9 == V_9 && V_17 -> V_62 == V_62 &&
F_56 ( V_17 , & V_84 ,
V_68 , V_69 ) )
return V_17 ;
}
return NULL ;
}
struct V_16 * F_59 ( struct V_31 * V_85 ,
const struct V_5 * V_12 ,
V_49 * V_86 )
{
struct V_43 * V_44 = F_60 ( V_85 -> V_44 ) ;
struct V_8 * V_9 ;
struct V_16 * V_17 ;
* V_86 = 0 ;
F_61 (mask, &tbl->mask_list, list) {
( * V_86 ) ++ ;
V_17 = F_58 ( V_44 , V_12 , V_9 ) ;
if ( V_17 )
return V_17 ;
}
return NULL ;
}
struct V_16 * F_62 ( struct V_31 * V_85 ,
const struct V_5 * V_12 )
{
V_49 T_2 V_86 ;
return F_59 ( V_85 , V_12 , & V_86 ) ;
}
struct V_16 * F_63 ( struct V_31 * V_85 ,
const struct V_80 * V_81 )
{
struct V_43 * V_44 = F_60 ( V_85 -> V_44 ) ;
struct V_8 * V_9 ;
struct V_16 * V_17 ;
F_64 (mask, &tbl->mask_list, list) {
V_17 = F_58 ( V_44 , V_81 -> V_12 , V_9 ) ;
if ( V_17 && F_57 ( V_17 , V_81 ) )
return V_17 ;
}
return NULL ;
}
int F_65 ( const struct V_31 * V_32 )
{
struct V_8 * V_9 ;
int V_87 = 0 ;
F_64 (mask, &table->mask_list, list)
V_87 ++ ;
return V_87 ;
}
static struct V_43 * F_66 ( struct V_43 * V_44 )
{
return F_46 ( V_44 , V_44 -> V_35 * 2 ) ;
}
static void F_67 ( struct V_31 * V_85 , struct V_8 * V_9 )
{
if ( V_9 ) {
F_68 () ;
F_69 ( ! V_9 -> V_88 ) ;
V_9 -> V_88 -- ;
if ( ! V_9 -> V_88 ) {
F_70 ( & V_9 -> V_89 ) ;
F_71 ( V_9 , V_41 ) ;
}
}
}
void F_72 ( struct V_31 * V_32 , struct V_16 * V_17 )
{
struct V_43 * V_44 = F_48 ( V_32 -> V_44 ) ;
F_69 ( V_32 -> V_33 == 0 ) ;
F_35 ( & V_17 -> V_59 [ V_44 -> V_46 ] ) ;
V_32 -> V_33 -- ;
F_67 ( V_32 , V_17 -> V_9 ) ;
}
static struct V_8 * F_73 ( void )
{
struct V_8 * V_9 ;
V_9 = F_27 ( sizeof( * V_9 ) , V_22 ) ;
if ( V_9 )
V_9 -> V_88 = 1 ;
return V_9 ;
}
static bool F_74 ( const struct V_8 * V_90 ,
const struct V_8 * V_91 )
{
const V_11 * V_92 = ( const V_11 * ) & V_90 -> V_12 + V_90 -> V_2 . V_4 ;
const V_11 * V_93 = ( const V_11 * ) & V_91 -> V_12 + V_91 -> V_2 . V_4 ;
return ( V_90 -> V_2 . V_3 == V_91 -> V_2 . V_3 )
&& ( V_90 -> V_2 . V_4 == V_91 -> V_2 . V_4 )
&& ( memcmp ( V_92 , V_93 , F_1 ( & V_90 -> V_2 ) ) == 0 ) ;
}
static struct V_8 * F_75 ( const struct V_31 * V_85 ,
const struct V_8 * V_9 )
{
struct V_94 * V_95 ;
F_76 (ml, &tbl->mask_list) {
struct V_8 * V_10 ;
V_10 = F_21 ( V_95 , struct V_8 , V_89 ) ;
if ( F_74 ( V_9 , V_10 ) )
return V_10 ;
}
return NULL ;
}
static int F_77 ( struct V_31 * V_85 , struct V_16 * V_17 ,
const struct V_8 * V_64 )
{
struct V_8 * V_9 ;
V_9 = F_75 ( V_85 , V_64 ) ;
if ( ! V_9 ) {
V_9 = F_73 () ;
if ( ! V_9 )
return - V_23 ;
V_9 -> V_12 = V_64 -> V_12 ;
V_9 -> V_2 = V_64 -> V_2 ;
F_78 ( & V_9 -> V_89 , & V_85 -> V_51 ) ;
} else {
F_69 ( ! V_9 -> V_88 ) ;
V_9 -> V_88 ++ ;
}
V_17 -> V_9 = V_9 ;
return 0 ;
}
int F_79 ( struct V_31 * V_32 , struct V_16 * V_17 ,
const struct V_8 * V_9 )
{
struct V_43 * V_66 = NULL ;
struct V_43 * V_44 ;
int V_29 ;
V_29 = F_77 ( V_32 , V_17 , V_9 ) ;
if ( V_29 )
return V_29 ;
V_17 -> V_62 = F_49 ( & V_17 -> V_12 , V_17 -> V_9 -> V_2 . V_4 ,
V_17 -> V_9 -> V_2 . V_3 ) ;
V_44 = F_48 ( V_32 -> V_44 ) ;
F_42 ( V_44 , V_17 ) ;
V_32 -> V_33 ++ ;
if ( V_32 -> V_33 > V_44 -> V_35 )
V_66 = F_66 ( V_44 ) ;
else if ( F_80 ( V_53 , V_32 -> V_52 + V_96 ) )
V_66 = F_46 ( V_44 , V_44 -> V_35 ) ;
if ( V_66 ) {
F_30 ( V_32 -> V_44 , V_66 ) ;
F_33 ( V_44 , true ) ;
V_32 -> V_52 = V_53 ;
}
return 0 ;
}
int F_81 ( void )
{
F_50 ( F_82 ( struct V_5 ) % F_82 ( long ) ) ;
F_50 ( sizeof( struct V_5 ) % sizeof( long ) ) ;
V_21 = F_83 ( L_1 , sizeof( struct V_16 )
+ ( F_84 ()
* sizeof( struct V_18 * ) ) ,
0 , 0 , NULL ) ;
if ( V_21 == NULL )
return - V_23 ;
V_27
= F_83 ( L_2 , sizeof( struct V_18 ) ,
0 , V_97 , NULL ) ;
if ( V_27 == NULL ) {
F_85 ( V_21 ) ;
V_21 = NULL ;
return - V_23 ;
}
return 0 ;
}
void F_86 ( void )
{
F_85 ( V_27 ) ;
F_85 ( V_21 ) ;
}
