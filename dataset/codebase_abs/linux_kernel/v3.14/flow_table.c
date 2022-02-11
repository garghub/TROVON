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
struct V_16 * F_3 ( bool V_17 )
{
struct V_16 * V_18 ;
int V_19 ;
V_18 = F_4 ( V_20 , V_21 ) ;
if ( ! V_18 )
return F_5 ( - V_22 ) ;
V_18 -> V_23 = NULL ;
V_18 -> V_9 = NULL ;
V_18 -> V_24 . V_25 = V_17 ;
if ( ! V_17 ) {
V_18 -> V_24 . V_26 = F_6 ( sizeof( * V_18 -> V_24 . V_26 ) , V_21 ) ;
if ( ! V_18 -> V_24 . V_26 )
goto V_27;
F_7 ( & V_18 -> V_24 . V_26 -> V_28 ) ;
} else {
V_18 -> V_24 . V_29 = F_8 ( struct V_30 ) ;
if ( ! V_18 -> V_24 . V_29 )
goto V_27;
F_9 (cpu) {
struct V_30 * V_29 ;
V_29 = F_10 ( V_18 -> V_24 . V_29 , V_19 ) ;
F_7 ( & V_29 -> V_28 ) ;
}
}
return V_18 ;
V_27:
F_11 ( V_20 , V_18 ) ;
return F_5 ( - V_22 ) ;
}
int F_12 ( struct V_31 * V_32 )
{
return V_32 -> V_33 ;
}
static struct V_34 * F_13 ( unsigned int V_35 )
{
struct V_34 * V_36 ;
int V_15 , V_27 ;
V_36 = F_14 ( sizeof( struct V_37 ) ,
V_35 , V_21 ) ;
if ( ! V_36 )
return NULL ;
V_27 = F_15 ( V_36 , 0 , V_35 , V_21 ) ;
if ( V_27 ) {
F_16 ( V_36 ) ;
return NULL ;
}
for ( V_15 = 0 ; V_15 < V_35 ; V_15 ++ )
F_17 ( (struct V_37 * )
F_18 ( V_36 , V_15 ) ) ;
return V_36 ;
}
static void F_19 ( struct V_16 * V_18 )
{
F_20 ( (struct V_38 V_39 * ) V_18 -> V_23 ) ;
if ( V_18 -> V_24 . V_25 )
F_21 ( V_18 -> V_24 . V_29 ) ;
else
F_20 ( V_18 -> V_24 . V_26 ) ;
F_11 ( V_20 , V_18 ) ;
}
static void F_22 ( struct V_40 * V_41 )
{
struct V_16 * V_18 = F_23 ( V_41 , struct V_16 , V_41 ) ;
F_19 ( V_18 ) ;
}
void F_24 ( struct V_16 * V_18 , bool V_42 )
{
if ( ! V_18 )
return;
if ( V_18 -> V_9 ) {
struct V_8 * V_9 = V_18 -> V_9 ;
F_25 () ;
F_26 ( ! V_9 -> V_43 ) ;
V_9 -> V_43 -- ;
if ( ! V_9 -> V_43 ) {
F_27 ( & V_9 -> V_44 ) ;
if ( V_42 )
F_28 ( V_9 , V_41 ) ;
else
F_20 ( V_9 ) ;
}
}
if ( V_42 )
F_29 ( & V_18 -> V_41 , F_22 ) ;
else
F_19 ( V_18 ) ;
}
static void F_30 ( struct V_34 * V_36 )
{
F_16 ( V_36 ) ;
}
static void F_31 ( struct V_45 * V_46 )
{
F_30 ( V_46 -> V_36 ) ;
F_20 ( V_46 ) ;
}
static struct V_45 * F_32 ( int V_47 )
{
struct V_45 * V_46 = F_33 ( sizeof( * V_46 ) , V_21 ) ;
if ( ! V_46 )
return NULL ;
V_46 -> V_36 = F_13 ( V_47 ) ;
if ( ! V_46 -> V_36 ) {
F_20 ( V_46 ) ;
return NULL ;
}
V_46 -> V_35 = V_47 ;
V_46 -> V_48 = 0 ;
V_46 -> V_49 = false ;
F_34 ( & V_46 -> V_50 , sizeof( V_51 ) ) ;
return V_46 ;
}
int F_35 ( struct V_31 * V_32 )
{
struct V_45 * V_46 ;
V_46 = F_32 ( V_52 ) ;
if ( ! V_46 )
return - V_22 ;
F_36 ( V_32 -> V_46 , V_46 ) ;
F_37 ( & V_32 -> V_53 ) ;
V_32 -> V_54 = V_55 ;
V_32 -> V_33 = 0 ;
return 0 ;
}
static void F_38 ( struct V_40 * V_41 )
{
struct V_45 * V_46 = F_23 ( V_41 , struct V_45 , V_41 ) ;
F_31 ( V_46 ) ;
}
static void F_39 ( struct V_45 * V_46 , bool V_42 )
{
int V_15 ;
if ( ! V_46 )
return;
if ( V_46 -> V_49 )
goto V_56;
for ( V_15 = 0 ; V_15 < V_46 -> V_35 ; V_15 ++ ) {
struct V_16 * V_18 ;
struct V_37 * V_57 = F_18 ( V_46 -> V_36 , V_15 ) ;
struct V_58 * V_59 ;
int V_60 = V_46 -> V_48 ;
F_40 (flow, n, head, hash_node[ver]) {
F_41 ( & V_18 -> V_61 [ V_60 ] ) ;
F_24 ( V_18 , V_42 ) ;
}
}
V_56:
if ( V_42 )
F_29 ( & V_46 -> V_41 , F_38 ) ;
else
F_31 ( V_46 ) ;
}
void F_42 ( struct V_31 * V_32 , bool V_42 )
{
struct V_45 * V_46 = F_43 ( V_32 -> V_46 ) ;
F_39 ( V_46 , V_42 ) ;
}
struct V_16 * F_44 ( struct V_45 * V_46 ,
V_51 * V_62 , V_51 * V_63 )
{
struct V_16 * V_18 ;
struct V_37 * V_57 ;
int V_60 ;
int V_15 ;
V_60 = V_46 -> V_48 ;
while ( * V_62 < V_46 -> V_35 ) {
V_15 = 0 ;
V_57 = F_18 ( V_46 -> V_36 , * V_62 ) ;
F_45 (flow, head, hash_node[ver]) {
if ( V_15 < * V_63 ) {
V_15 ++ ;
continue;
}
* V_63 = V_15 + 1 ;
return V_18 ;
}
( * V_62 ) ++ ;
* V_63 = 0 ;
}
return NULL ;
}
static struct V_37 * F_46 ( struct V_45 * V_46 , V_51 V_64 )
{
V_64 = F_47 ( V_64 , V_46 -> V_50 ) ;
return F_18 ( V_46 -> V_36 ,
( V_64 & ( V_46 -> V_35 - 1 ) ) ) ;
}
static void F_48 ( struct V_45 * V_46 , struct V_16 * V_18 )
{
struct V_37 * V_57 ;
V_57 = F_46 ( V_46 , V_18 -> V_64 ) ;
F_49 ( & V_18 -> V_61 [ V_46 -> V_48 ] , V_57 ) ;
}
static void F_50 ( struct V_45 * V_65 ,
struct V_45 * V_66 )
{
int V_67 ;
int V_15 ;
V_67 = V_65 -> V_48 ;
V_66 -> V_48 = ! V_67 ;
for ( V_15 = 0 ; V_15 < V_65 -> V_35 ; V_15 ++ ) {
struct V_16 * V_18 ;
struct V_37 * V_57 ;
V_57 = F_18 ( V_65 -> V_36 , V_15 ) ;
F_51 (flow, head, hash_node[old_ver])
F_48 ( V_66 , V_18 ) ;
}
V_65 -> V_49 = true ;
}
static struct V_45 * F_52 ( struct V_45 * V_46 ,
int V_35 )
{
struct V_45 * V_68 ;
V_68 = F_32 ( V_35 ) ;
if ( ! V_68 )
return NULL ;
F_50 ( V_46 , V_68 ) ;
return V_68 ;
}
int F_53 ( struct V_31 * V_31 )
{
struct V_45 * V_69 ;
struct V_45 * V_68 ;
V_69 = F_43 ( V_31 -> V_46 ) ;
V_68 = F_32 ( V_52 ) ;
if ( ! V_68 )
return - V_22 ;
F_36 ( V_31 -> V_46 , V_68 ) ;
V_31 -> V_54 = V_55 ;
V_31 -> V_33 = 0 ;
F_39 ( V_69 , true ) ;
return 0 ;
}
static V_51 F_54 ( const struct V_5 * V_12 , int V_70 ,
int V_71 )
{
V_51 * V_72 = ( V_51 * ) ( ( V_11 * ) V_12 + V_70 ) ;
int V_73 = ( V_71 - V_70 ) >> 2 ;
F_55 ( sizeof( long ) % sizeof( V_51 ) ) ;
return F_56 ( V_72 , V_73 , 0 ) ;
}
static int F_57 ( const struct V_5 * V_12 )
{
if ( V_12 -> V_74 . V_75 )
return 0 ;
else
return F_58 ( F_59 ( struct V_5 , V_76 ) ,
sizeof( long ) ) ;
}
static bool F_60 ( const struct V_5 * V_77 ,
const struct V_5 * V_78 ,
int V_70 , int V_71 )
{
const long * V_79 = ( long * ) ( ( V_11 * ) V_77 + V_70 ) ;
const long * V_80 = ( long * ) ( ( V_11 * ) V_78 + V_70 ) ;
long V_81 = 0 ;
int V_15 ;
for ( V_15 = V_70 ; V_15 < V_71 ; V_15 += sizeof( long ) )
V_81 |= * V_79 ++ ^ * V_80 ++ ;
return V_81 == 0 ;
}
static bool F_61 ( const struct V_16 * V_18 ,
const struct V_5 * V_12 ,
int V_70 , int V_71 )
{
return F_60 ( & V_18 -> V_12 , V_12 , V_70 , V_71 ) ;
}
bool F_62 ( const struct V_16 * V_18 ,
struct V_82 * V_83 )
{
struct V_5 * V_12 = V_83 -> V_12 ;
int V_70 = F_57 ( V_12 ) ;
int V_71 = V_83 -> V_2 . V_3 ;
return F_60 ( & V_18 -> V_84 , V_12 , V_70 , V_71 ) ;
}
static struct V_16 * F_63 ( struct V_45 * V_46 ,
const struct V_5 * V_85 ,
struct V_8 * V_9 )
{
struct V_16 * V_18 ;
struct V_37 * V_57 ;
int V_70 = V_9 -> V_2 . V_4 ;
int V_71 = V_9 -> V_2 . V_3 ;
V_51 V_64 ;
struct V_5 V_86 ;
F_2 ( & V_86 , V_85 , V_9 ) ;
V_64 = F_54 ( & V_86 , V_70 , V_71 ) ;
V_57 = F_46 ( V_46 , V_64 ) ;
F_45 (flow, head, hash_node[ti->node_ver]) {
if ( V_18 -> V_9 == V_9 && V_18 -> V_64 == V_64 &&
F_61 ( V_18 , & V_86 ,
V_70 , V_71 ) )
return V_18 ;
}
return NULL ;
}
struct V_16 * F_64 ( struct V_31 * V_87 ,
const struct V_5 * V_12 ,
V_51 * V_88 )
{
struct V_45 * V_46 = F_65 ( V_87 -> V_46 ) ;
struct V_8 * V_9 ;
struct V_16 * V_18 ;
* V_88 = 0 ;
F_66 (mask, &tbl->mask_list, list) {
( * V_88 ) ++ ;
V_18 = F_63 ( V_46 , V_12 , V_9 ) ;
if ( V_18 )
return V_18 ;
}
return NULL ;
}
struct V_16 * F_67 ( struct V_31 * V_87 ,
const struct V_5 * V_12 )
{
V_51 T_2 V_88 ;
return F_64 ( V_87 , V_12 , & V_88 ) ;
}
int F_68 ( const struct V_31 * V_32 )
{
struct V_8 * V_9 ;
int V_89 = 0 ;
F_69 (mask, &table->mask_list, list)
V_89 ++ ;
return V_89 ;
}
static struct V_45 * F_70 ( struct V_45 * V_46 )
{
return F_52 ( V_46 , V_46 -> V_35 * 2 ) ;
}
void F_71 ( struct V_31 * V_32 , struct V_16 * V_18 )
{
struct V_45 * V_46 = F_43 ( V_32 -> V_46 ) ;
F_26 ( V_32 -> V_33 == 0 ) ;
F_41 ( & V_18 -> V_61 [ V_46 -> V_48 ] ) ;
V_32 -> V_33 -- ;
}
static struct V_8 * F_72 ( void )
{
struct V_8 * V_9 ;
V_9 = F_33 ( sizeof( * V_9 ) , V_21 ) ;
if ( V_9 )
V_9 -> V_43 = 1 ;
return V_9 ;
}
static bool F_73 ( const struct V_8 * V_90 ,
const struct V_8 * V_91 )
{
V_11 * V_92 = ( V_11 * ) & V_90 -> V_12 + V_90 -> V_2 . V_4 ;
V_11 * V_93 = ( V_11 * ) & V_91 -> V_12 + V_91 -> V_2 . V_4 ;
return ( V_90 -> V_2 . V_3 == V_91 -> V_2 . V_3 )
&& ( V_90 -> V_2 . V_4 == V_91 -> V_2 . V_4 )
&& ( memcmp ( V_92 , V_93 , F_1 ( & V_90 -> V_2 ) ) == 0 ) ;
}
static struct V_8 * F_74 ( const struct V_31 * V_87 ,
const struct V_8 * V_9 )
{
struct V_94 * V_95 ;
F_75 (ml, &tbl->mask_list) {
struct V_8 * V_10 ;
V_10 = F_23 ( V_95 , struct V_8 , V_44 ) ;
if ( F_73 ( V_9 , V_10 ) )
return V_10 ;
}
return NULL ;
}
static int F_76 ( struct V_31 * V_87 , struct V_16 * V_18 ,
struct V_8 * V_66 )
{
struct V_8 * V_9 ;
V_9 = F_74 ( V_87 , V_66 ) ;
if ( ! V_9 ) {
V_9 = F_72 () ;
if ( ! V_9 )
return - V_22 ;
V_9 -> V_12 = V_66 -> V_12 ;
V_9 -> V_2 = V_66 -> V_2 ;
F_77 ( & V_9 -> V_44 , & V_87 -> V_53 ) ;
} else {
F_26 ( ! V_9 -> V_43 ) ;
V_9 -> V_43 ++ ;
}
V_18 -> V_9 = V_9 ;
return 0 ;
}
int F_78 ( struct V_31 * V_32 , struct V_16 * V_18 ,
struct V_8 * V_9 )
{
struct V_45 * V_68 = NULL ;
struct V_45 * V_46 ;
int V_27 ;
V_27 = F_76 ( V_32 , V_18 , V_9 ) ;
if ( V_27 )
return V_27 ;
V_18 -> V_64 = F_54 ( & V_18 -> V_12 , V_18 -> V_9 -> V_2 . V_4 ,
V_18 -> V_9 -> V_2 . V_3 ) ;
V_46 = F_43 ( V_32 -> V_46 ) ;
F_48 ( V_46 , V_18 ) ;
V_32 -> V_33 ++ ;
if ( V_32 -> V_33 > V_46 -> V_35 )
V_68 = F_70 ( V_46 ) ;
else if ( F_79 ( V_55 , V_32 -> V_54 + V_96 ) )
V_68 = F_52 ( V_46 , V_46 -> V_35 ) ;
if ( V_68 ) {
F_36 ( V_32 -> V_46 , V_68 ) ;
F_39 ( V_46 , true ) ;
V_32 -> V_54 = V_55 ;
}
return 0 ;
}
int F_80 ( void )
{
F_55 ( F_81 ( struct V_5 ) % F_81 ( long ) ) ;
F_55 ( sizeof( struct V_5 ) % sizeof( long ) ) ;
V_20 = F_82 ( L_1 , sizeof( struct V_16 ) , 0 ,
0 , NULL ) ;
if ( V_20 == NULL )
return - V_22 ;
return 0 ;
}
void F_83 ( void )
{
F_84 ( V_20 ) ;
}
