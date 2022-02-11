static T_1 F_1 ( const struct V_1 * V_2 )
{
return V_2 -> V_3 - V_2 -> V_4 ;
}
void F_2 ( struct V_5 * V_6 , const struct V_5 * V_7 ,
const struct V_8 * V_9 )
{
const long * V_10 = ( long * ) ( ( V_11 * ) & V_9 -> V_12 + V_9 -> V_2 . V_4 ) ;
const long * V_13 = ( long * ) ( ( V_11 * ) V_7 + V_9 -> V_2 . V_4 ) ;
long * V_14 = ( long * ) ( ( V_11 * ) V_6 + V_9 -> V_2 . V_4 ) ;
int V_15 ;
for ( V_15 = 0 ; V_15 < F_1 ( & V_9 -> V_2 ) ; V_15 += sizeof( long ) )
* V_14 ++ = * V_13 ++ & * V_10 ++ ;
}
struct V_16 * F_3 ( void )
{
struct V_16 * V_17 ;
V_17 = F_4 ( V_18 , V_19 ) ;
if ( ! V_17 )
return F_5 ( - V_20 ) ;
F_6 ( & V_17 -> V_21 ) ;
V_17 -> V_22 = NULL ;
V_17 -> V_9 = NULL ;
return V_17 ;
}
int F_7 ( struct V_23 * V_24 )
{
return V_24 -> V_25 ;
}
static struct V_26 * F_8 ( unsigned int V_27 )
{
struct V_26 * V_28 ;
int V_15 , V_29 ;
V_28 = F_9 ( sizeof( struct V_30 ) ,
V_27 , V_19 ) ;
if ( ! V_28 )
return NULL ;
V_29 = F_10 ( V_28 , 0 , V_27 , V_19 ) ;
if ( V_29 ) {
F_11 ( V_28 ) ;
return NULL ;
}
for ( V_15 = 0 ; V_15 < V_27 ; V_15 ++ )
F_12 ( (struct V_30 * )
F_13 ( V_28 , V_15 ) ) ;
return V_28 ;
}
static void F_14 ( struct V_16 * V_17 )
{
F_15 ( (struct V_31 V_32 * ) V_17 -> V_22 ) ;
F_16 ( V_18 , V_17 ) ;
}
static void F_17 ( struct V_33 * V_34 )
{
struct V_16 * V_17 = F_18 ( V_34 , struct V_16 , V_34 ) ;
F_14 ( V_17 ) ;
}
static void F_19 ( struct V_33 * V_34 )
{
struct V_8 * V_9 = F_18 ( V_34 , struct V_8 , V_34 ) ;
F_15 ( V_9 ) ;
}
static void F_20 ( struct V_8 * V_9 , bool V_35 )
{
if ( ! V_9 )
return;
F_21 ( ! V_9 -> V_36 ) ;
V_9 -> V_36 -- ;
if ( ! V_9 -> V_36 ) {
F_22 ( & V_9 -> V_37 ) ;
if ( V_35 )
F_23 ( & V_9 -> V_34 , F_19 ) ;
else
F_15 ( V_9 ) ;
}
}
void F_24 ( struct V_16 * V_17 , bool V_35 )
{
if ( ! V_17 )
return;
F_20 ( V_17 -> V_9 , V_35 ) ;
if ( V_35 )
F_23 ( & V_17 -> V_34 , F_17 ) ;
else
F_14 ( V_17 ) ;
}
static void F_25 ( struct V_26 * V_28 )
{
F_11 ( V_28 ) ;
}
static void F_26 ( struct V_38 * V_39 )
{
int V_15 ;
if ( V_39 -> V_40 )
goto V_41;
for ( V_15 = 0 ; V_15 < V_39 -> V_27 ; V_15 ++ ) {
struct V_16 * V_17 ;
struct V_30 * V_42 = F_13 ( V_39 -> V_28 , V_15 ) ;
struct V_43 * V_44 ;
int V_45 = V_39 -> V_46 ;
F_27 (flow, n, head, hash_node[ver]) {
F_28 ( & V_17 -> V_47 [ V_45 ] ) ;
F_24 ( V_17 , false ) ;
}
}
V_41:
F_25 ( V_39 -> V_28 ) ;
F_15 ( V_39 ) ;
}
static struct V_38 * F_29 ( int V_48 )
{
struct V_38 * V_39 = F_30 ( sizeof( * V_39 ) , V_19 ) ;
if ( ! V_39 )
return NULL ;
V_39 -> V_28 = F_8 ( V_48 ) ;
if ( ! V_39 -> V_28 ) {
F_15 ( V_39 ) ;
return NULL ;
}
V_39 -> V_27 = V_48 ;
V_39 -> V_46 = 0 ;
V_39 -> V_40 = false ;
F_31 ( & V_39 -> V_49 , sizeof( V_50 ) ) ;
return V_39 ;
}
int F_32 ( struct V_23 * V_24 )
{
struct V_38 * V_39 ;
V_39 = F_29 ( V_51 ) ;
if ( ! V_39 )
return - V_20 ;
F_33 ( V_24 -> V_39 , V_39 ) ;
F_34 ( & V_24 -> V_52 ) ;
V_24 -> V_53 = V_54 ;
V_24 -> V_25 = 0 ;
return 0 ;
}
static void F_35 ( struct V_33 * V_34 )
{
struct V_38 * V_39 = F_18 ( V_34 , struct V_38 , V_34 ) ;
F_26 ( V_39 ) ;
}
static void F_36 ( struct V_38 * V_39 , bool V_35 )
{
if ( ! V_39 )
return;
if ( V_35 )
F_23 ( & V_39 -> V_34 , F_35 ) ;
else
F_26 ( V_39 ) ;
}
void F_37 ( struct V_23 * V_24 )
{
struct V_38 * V_39 = F_38 ( V_24 -> V_39 ) ;
F_36 ( V_39 , false ) ;
}
struct V_16 * F_39 ( struct V_38 * V_39 ,
V_50 * V_55 , V_50 * V_56 )
{
struct V_16 * V_17 ;
struct V_30 * V_42 ;
int V_45 ;
int V_15 ;
V_45 = V_39 -> V_46 ;
while ( * V_55 < V_39 -> V_27 ) {
V_15 = 0 ;
V_42 = F_13 ( V_39 -> V_28 , * V_55 ) ;
F_40 (flow, head, hash_node[ver]) {
if ( V_15 < * V_56 ) {
V_15 ++ ;
continue;
}
* V_56 = V_15 + 1 ;
return V_17 ;
}
( * V_55 ) ++ ;
* V_56 = 0 ;
}
return NULL ;
}
static struct V_30 * F_41 ( struct V_38 * V_39 , V_50 V_57 )
{
V_57 = F_42 ( V_57 , V_39 -> V_49 ) ;
return F_13 ( V_39 -> V_28 ,
( V_57 & ( V_39 -> V_27 - 1 ) ) ) ;
}
static void F_43 ( struct V_38 * V_39 , struct V_16 * V_17 )
{
struct V_30 * V_42 ;
V_42 = F_41 ( V_39 , V_17 -> V_57 ) ;
F_44 ( & V_17 -> V_47 [ V_39 -> V_46 ] , V_42 ) ;
}
static void F_45 ( struct V_38 * V_58 ,
struct V_38 * V_59 )
{
int V_60 ;
int V_15 ;
V_60 = V_58 -> V_46 ;
V_59 -> V_46 = ! V_60 ;
for ( V_15 = 0 ; V_15 < V_58 -> V_27 ; V_15 ++ ) {
struct V_16 * V_17 ;
struct V_30 * V_42 ;
V_42 = F_13 ( V_58 -> V_28 , V_15 ) ;
F_46 (flow, head, hash_node[old_ver])
F_43 ( V_59 , V_17 ) ;
}
V_58 -> V_40 = true ;
}
static struct V_38 * F_47 ( struct V_38 * V_39 ,
int V_27 )
{
struct V_38 * V_61 ;
V_61 = F_29 ( V_27 ) ;
if ( ! V_61 )
return NULL ;
F_45 ( V_39 , V_61 ) ;
return V_61 ;
}
int F_48 ( struct V_23 * V_23 )
{
struct V_38 * V_62 ;
struct V_38 * V_61 ;
V_62 = F_38 ( V_23 -> V_39 ) ;
V_61 = F_29 ( V_51 ) ;
if ( ! V_61 )
return - V_20 ;
F_33 ( V_23 -> V_39 , V_61 ) ;
V_23 -> V_53 = V_54 ;
V_23 -> V_25 = 0 ;
F_36 ( V_62 , true ) ;
return 0 ;
}
static V_50 F_49 ( const struct V_5 * V_12 , int V_63 ,
int V_64 )
{
V_50 * V_65 = ( V_50 * ) ( ( V_11 * ) V_12 + V_63 ) ;
int V_66 = ( V_64 - V_63 ) >> 2 ;
F_50 ( sizeof( long ) % sizeof( V_50 ) ) ;
return F_51 ( V_65 , V_66 , 0 ) ;
}
static int F_52 ( const struct V_5 * V_12 )
{
if ( V_12 -> V_67 . V_68 )
return 0 ;
else
return F_53 ( F_54 ( struct V_5 , V_69 ) ,
sizeof( long ) ) ;
}
static bool F_55 ( const struct V_5 * V_70 ,
const struct V_5 * V_71 ,
int V_63 , int V_64 )
{
const long * V_72 = ( long * ) ( ( V_11 * ) V_70 + V_63 ) ;
const long * V_73 = ( long * ) ( ( V_11 * ) V_71 + V_63 ) ;
long V_74 = 0 ;
int V_15 ;
for ( V_15 = V_63 ; V_15 < V_64 ; V_15 += sizeof( long ) )
V_74 |= * V_72 ++ ^ * V_73 ++ ;
return V_74 == 0 ;
}
static bool F_56 ( const struct V_16 * V_17 ,
const struct V_5 * V_12 ,
int V_63 , int V_64 )
{
return F_55 ( & V_17 -> V_12 , V_12 , V_63 , V_64 ) ;
}
bool F_57 ( const struct V_16 * V_17 ,
struct V_75 * V_76 )
{
struct V_5 * V_12 = V_76 -> V_12 ;
int V_63 = F_52 ( V_12 ) ;
int V_64 = V_76 -> V_2 . V_3 ;
return F_55 ( & V_17 -> V_77 , V_12 , V_63 , V_64 ) ;
}
static struct V_16 * F_58 ( struct V_38 * V_39 ,
const struct V_5 * V_78 ,
struct V_8 * V_9 )
{
struct V_16 * V_17 ;
struct V_30 * V_42 ;
int V_63 = V_9 -> V_2 . V_4 ;
int V_64 = V_9 -> V_2 . V_3 ;
V_50 V_57 ;
struct V_5 V_79 ;
F_2 ( & V_79 , V_78 , V_9 ) ;
V_57 = F_49 ( & V_79 , V_63 , V_64 ) ;
V_42 = F_41 ( V_39 , V_57 ) ;
F_40 (flow, head, hash_node[ti->node_ver]) {
if ( V_17 -> V_9 == V_9 && V_17 -> V_57 == V_57 &&
F_56 ( V_17 , & V_79 ,
V_63 , V_64 ) )
return V_17 ;
}
return NULL ;
}
struct V_16 * F_59 ( struct V_23 * V_80 ,
const struct V_5 * V_12 ,
V_50 * V_81 )
{
struct V_38 * V_39 = F_60 ( V_80 -> V_39 ) ;
struct V_8 * V_9 ;
struct V_16 * V_17 ;
* V_81 = 0 ;
F_61 (mask, &tbl->mask_list, list) {
( * V_81 ) ++ ;
V_17 = F_58 ( V_39 , V_12 , V_9 ) ;
if ( V_17 )
return V_17 ;
}
return NULL ;
}
int F_62 ( const struct V_23 * V_24 )
{
struct V_8 * V_9 ;
int V_82 = 0 ;
F_63 (mask, &table->mask_list, list)
V_82 ++ ;
return V_82 ;
}
static struct V_38 * F_64 ( struct V_38 * V_39 )
{
return F_47 ( V_39 , V_39 -> V_27 * 2 ) ;
}
void F_65 ( struct V_23 * V_24 , struct V_16 * V_17 )
{
struct V_38 * V_39 = F_38 ( V_24 -> V_39 ) ;
F_21 ( V_24 -> V_25 == 0 ) ;
F_66 ( & V_17 -> V_47 [ V_39 -> V_46 ] ) ;
V_24 -> V_25 -- ;
}
static struct V_8 * F_67 ( void )
{
struct V_8 * V_9 ;
V_9 = F_30 ( sizeof( * V_9 ) , V_19 ) ;
if ( V_9 )
V_9 -> V_36 = 0 ;
return V_9 ;
}
static void F_68 ( struct V_8 * V_9 )
{
V_9 -> V_36 ++ ;
}
static bool F_69 ( const struct V_8 * V_83 ,
const struct V_8 * V_84 )
{
V_11 * V_85 = ( V_11 * ) & V_83 -> V_12 + V_83 -> V_2 . V_4 ;
V_11 * V_86 = ( V_11 * ) & V_84 -> V_12 + V_84 -> V_2 . V_4 ;
return ( V_83 -> V_2 . V_3 == V_84 -> V_2 . V_3 )
&& ( V_83 -> V_2 . V_4 == V_84 -> V_2 . V_4 )
&& ( memcmp ( V_85 , V_86 , F_1 ( & V_83 -> V_2 ) ) == 0 ) ;
}
static struct V_8 * F_70 ( const struct V_23 * V_80 ,
const struct V_8 * V_9 )
{
struct V_87 * V_88 ;
F_71 (ml, &tbl->mask_list) {
struct V_8 * V_10 ;
V_10 = F_18 ( V_88 , struct V_8 , V_37 ) ;
if ( F_69 ( V_9 , V_10 ) )
return V_10 ;
}
return NULL ;
}
static int F_72 ( struct V_23 * V_80 , struct V_16 * V_17 ,
struct V_8 * V_59 )
{
struct V_8 * V_9 ;
V_9 = F_70 ( V_80 , V_59 ) ;
if ( ! V_9 ) {
V_9 = F_67 () ;
if ( ! V_9 )
return - V_20 ;
V_9 -> V_12 = V_59 -> V_12 ;
V_9 -> V_2 = V_59 -> V_2 ;
F_73 ( & V_9 -> V_37 , & V_80 -> V_52 ) ;
}
F_68 ( V_9 ) ;
V_17 -> V_9 = V_9 ;
return 0 ;
}
int F_74 ( struct V_23 * V_24 , struct V_16 * V_17 ,
struct V_8 * V_9 )
{
struct V_38 * V_61 = NULL ;
struct V_38 * V_39 ;
int V_29 ;
V_29 = F_72 ( V_24 , V_17 , V_9 ) ;
if ( V_29 )
return V_29 ;
V_17 -> V_57 = F_49 ( & V_17 -> V_12 , V_17 -> V_9 -> V_2 . V_4 ,
V_17 -> V_9 -> V_2 . V_3 ) ;
V_39 = F_38 ( V_24 -> V_39 ) ;
F_43 ( V_39 , V_17 ) ;
V_24 -> V_25 ++ ;
if ( V_24 -> V_25 > V_39 -> V_27 )
V_61 = F_64 ( V_39 ) ;
else if ( F_75 ( V_54 , V_24 -> V_53 + V_89 ) )
V_61 = F_47 ( V_39 , V_39 -> V_27 ) ;
if ( V_61 ) {
F_33 ( V_24 -> V_39 , V_61 ) ;
F_36 ( V_39 , true ) ;
V_24 -> V_53 = V_54 ;
}
return 0 ;
}
int F_76 ( void )
{
F_50 ( F_77 ( struct V_5 ) % F_77 ( long ) ) ;
F_50 ( sizeof( struct V_5 ) % sizeof( long ) ) ;
V_18 = F_78 ( L_1 , sizeof( struct V_16 ) , 0 ,
0 , NULL ) ;
if ( V_18 == NULL )
return - V_20 ;
return 0 ;
}
void F_79 ( void )
{
F_80 ( V_18 ) ;
}
