static inline int
F_1 ( struct V_1 * V_2 )
{
return ! F_2 ( & V_2 -> V_3 ) ;
}
static void
F_3 ( struct V_1 * V_2 )
{
if ( F_1 ( V_2 ) ) {
F_4 ( & V_2 -> V_3 ) ;
F_5 ( & V_2 -> V_4 . V_5 ) ;
}
}
static void
F_6 ( struct V_1 * V_2 , T_1 V_6 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
F_7 ( ! ( V_2 -> V_10 || V_2 -> V_11 ) ) ;
F_8 ( V_8 -> V_12 , V_2 ) ;
F_9 ( & V_8 -> V_13 ) ;
}
static void
F_10 ( struct V_1 * V_2 )
__releases( T_2 )
{
if ( V_2 -> V_11 )
F_11 ( & V_14 ) ;
if ( V_2 -> V_10 >= V_15 )
V_2 -> V_10 -= V_15 ;
V_2 -> V_10 -- ;
if ( ! ( V_2 -> V_10 || V_2 -> V_11 ) ) {
if ( ! F_1 ( V_2 ) )
goto V_16;
F_7 ( F_2 ( & V_2 -> V_17 ) ) ;
F_12 ( & V_2 -> V_17 , & V_18 ) ;
}
F_13 ( & T_2 ) ;
return;
V_16:
F_13 ( & T_2 ) ;
F_6 ( V_2 , V_19 ) ;
}
static int
F_14 ( struct V_20 * V_21 , struct V_22 * V_23 )
{
F_15 ( V_24 ) ;
struct V_7 * V_8 ;
struct V_1 * V_25 , * V_26 ;
int V_27 = 0 ;
int V_28 = V_23 -> V_28 ;
T_1 V_6 = V_23 -> V_6 ;
F_16 ( L_1 , V_28 ) ;
F_17 ( & T_2 ) ;
while ( V_28 -- && ! F_2 ( & V_18 ) ) {
struct V_1 * V_2 =
F_18 ( V_18 . V_29 ,
struct V_1 , V_17 ) ;
F_19 ( & V_2 -> V_17 , & V_24 ) ;
F_3 ( V_2 ) ;
}
F_20 (cache, &mb_cache_list, c_cache_list) {
F_16 ( L_2 , V_8 -> V_30 ,
F_21 ( & V_8 -> V_13 ) ) ;
V_27 += F_21 ( & V_8 -> V_13 ) ;
}
F_13 ( & T_2 ) ;
F_22 (entry, tmp, &free_list, e_lru_list) {
F_6 ( V_25 , V_6 ) ;
}
return ( V_27 / 100 ) * V_31 ;
}
struct V_7 *
F_23 ( const char * V_32 , int V_33 )
{
int V_34 , V_35 = 1 << V_33 ;
struct V_7 * V_8 = NULL ;
V_8 = F_24 ( sizeof( struct V_7 ) , V_19 ) ;
if ( ! V_8 )
return NULL ;
V_8 -> V_30 = V_32 ;
F_25 ( & V_8 -> V_13 , 0 ) ;
V_8 -> V_36 = V_33 ;
V_8 -> V_37 = F_24 ( V_35 * sizeof( struct V_38 ) ,
V_19 ) ;
if ( ! V_8 -> V_37 )
goto V_39;
for ( V_34 = 0 ; V_34 < V_35 ; V_34 ++ )
F_26 ( & V_8 -> V_37 [ V_34 ] ) ;
V_8 -> V_40 = F_24 ( V_35 * sizeof( struct V_38 ) ,
V_19 ) ;
if ( ! V_8 -> V_40 )
goto V_39;
for ( V_34 = 0 ; V_34 < V_35 ; V_34 ++ )
F_26 ( & V_8 -> V_40 [ V_34 ] ) ;
V_8 -> V_12 = F_27 ( V_32 ,
sizeof( struct V_1 ) , 0 ,
V_41 | V_42 , NULL ) ;
if ( ! V_8 -> V_12 )
goto V_43;
V_8 -> V_44 = V_35 << 4 ;
F_17 ( & T_2 ) ;
F_28 ( & V_8 -> V_45 , & V_46 ) ;
F_13 ( & T_2 ) ;
return V_8 ;
V_43:
F_29 ( V_8 -> V_40 ) ;
V_39:
F_29 ( V_8 -> V_37 ) ;
F_29 ( V_8 ) ;
return NULL ;
}
void
F_30 ( struct V_47 * V_48 )
{
F_15 ( V_24 ) ;
struct V_38 * V_49 , * V_50 ;
F_17 ( & T_2 ) ;
F_31 (l, ltmp, &mb_cache_lru_list) {
struct V_1 * V_2 =
F_18 ( V_49 , struct V_1 , V_17 ) ;
if ( V_2 -> V_51 == V_48 ) {
F_19 ( & V_2 -> V_17 , & V_24 ) ;
F_3 ( V_2 ) ;
}
}
F_13 ( & T_2 ) ;
F_31 (l, ltmp, &free_list) {
F_6 ( F_18 ( V_49 , struct V_1 ,
V_17 ) , V_19 ) ;
}
}
void
F_32 ( struct V_7 * V_8 )
{
F_15 ( V_24 ) ;
struct V_38 * V_49 , * V_50 ;
F_17 ( & T_2 ) ;
F_31 (l, ltmp, &mb_cache_lru_list) {
struct V_1 * V_2 =
F_18 ( V_49 , struct V_1 , V_17 ) ;
if ( V_2 -> V_9 == V_8 ) {
F_19 ( & V_2 -> V_17 , & V_24 ) ;
F_3 ( V_2 ) ;
}
}
F_5 ( & V_8 -> V_45 ) ;
F_13 ( & T_2 ) ;
F_31 (l, ltmp, &free_list) {
F_6 ( F_18 ( V_49 , struct V_1 ,
V_17 ) , V_19 ) ;
}
if ( F_21 ( & V_8 -> V_13 ) > 0 ) {
F_33 ( L_3 ,
V_8 -> V_30 ,
F_21 ( & V_8 -> V_13 ) ) ;
}
F_34 ( V_8 -> V_12 ) ;
F_29 ( V_8 -> V_40 ) ;
F_29 ( V_8 -> V_37 ) ;
F_29 ( V_8 ) ;
}
struct V_1 *
F_35 ( struct V_7 * V_8 , T_1 V_52 )
{
struct V_1 * V_2 = NULL ;
if ( F_21 ( & V_8 -> V_13 ) >= V_8 -> V_44 ) {
F_17 ( & T_2 ) ;
if ( ! F_2 ( & V_18 ) ) {
V_2 = F_18 ( V_18 . V_29 ,
struct V_1 , V_17 ) ;
F_4 ( & V_2 -> V_17 ) ;
F_3 ( V_2 ) ;
}
F_13 ( & T_2 ) ;
}
if ( ! V_2 ) {
V_2 = F_36 ( V_8 -> V_12 , V_52 ) ;
if ( ! V_2 )
return NULL ;
F_37 ( & V_8 -> V_13 ) ;
F_26 ( & V_2 -> V_17 ) ;
F_26 ( & V_2 -> V_3 ) ;
V_2 -> V_9 = V_8 ;
V_2 -> V_11 = 0 ;
}
V_2 -> V_10 = 1 + V_15 ;
return V_2 ;
}
int
F_38 ( struct V_1 * V_2 , struct V_47 * V_48 ,
T_3 V_53 , unsigned int V_54 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
unsigned int V_55 ;
struct V_38 * V_49 ;
int error = - V_56 ;
V_55 = F_39 ( ( unsigned long ) V_48 + ( V_53 & 0xffffffff ) ,
V_8 -> V_36 ) ;
F_17 ( & T_2 ) ;
F_40 (l, &cache->c_block_hash[bucket]) {
struct V_1 * V_2 =
F_18 ( V_49 , struct V_1 , V_3 ) ;
if ( V_2 -> V_51 == V_48 && V_2 -> V_57 == V_53 )
goto V_58;
}
F_3 ( V_2 ) ;
V_2 -> V_51 = V_48 ;
V_2 -> V_57 = V_53 ;
F_28 ( & V_2 -> V_3 , & V_8 -> V_37 [ V_55 ] ) ;
V_2 -> V_4 . V_59 = V_54 ;
V_55 = F_39 ( V_54 , V_8 -> V_36 ) ;
F_28 ( & V_2 -> V_4 . V_5 , & V_8 -> V_40 [ V_55 ] ) ;
error = 0 ;
V_58:
F_13 ( & T_2 ) ;
return error ;
}
void
F_41 ( struct V_1 * V_2 )
{
F_17 ( & T_2 ) ;
F_10 ( V_2 ) ;
}
void
F_42 ( struct V_1 * V_2 )
{
F_17 ( & T_2 ) ;
F_7 ( F_2 ( & V_2 -> V_17 ) ) ;
F_3 ( V_2 ) ;
F_10 ( V_2 ) ;
}
struct V_1 *
F_43 ( struct V_7 * V_8 , struct V_47 * V_48 ,
T_3 V_53 )
{
unsigned int V_55 ;
struct V_38 * V_49 ;
struct V_1 * V_2 ;
V_55 = F_39 ( ( unsigned long ) V_48 + ( V_53 & 0xffffffff ) ,
V_8 -> V_36 ) ;
F_17 ( & T_2 ) ;
F_44 (l, &cache->c_block_hash[bucket]) {
V_2 = F_18 ( V_49 , struct V_1 , V_3 ) ;
if ( V_2 -> V_51 == V_48 && V_2 -> V_57 == V_53 ) {
F_45 ( V_60 ) ;
if ( ! F_2 ( & V_2 -> V_17 ) )
F_4 ( & V_2 -> V_17 ) ;
while ( V_2 -> V_10 > 0 ) {
V_2 -> V_11 ++ ;
F_46 ( & V_14 , & V_60 ,
V_61 ) ;
F_13 ( & T_2 ) ;
F_47 () ;
F_17 ( & T_2 ) ;
V_2 -> V_11 -- ;
}
F_48 ( & V_14 , & V_60 ) ;
V_2 -> V_10 += 1 + V_15 ;
if ( ! F_1 ( V_2 ) ) {
F_10 ( V_2 ) ;
return NULL ;
}
goto V_62;
}
}
V_2 = NULL ;
V_62:
F_13 ( & T_2 ) ;
return V_2 ;
}
static struct V_1 *
F_49 ( struct V_38 * V_49 , struct V_38 * V_63 ,
struct V_47 * V_48 , unsigned int V_54 )
{
while ( V_49 != V_63 ) {
struct V_1 * V_2 =
F_18 ( V_49 , struct V_1 , V_4 . V_5 ) ;
if ( V_2 -> V_51 == V_48 && V_2 -> V_4 . V_59 == V_54 ) {
F_45 ( V_60 ) ;
if ( ! F_2 ( & V_2 -> V_17 ) )
F_4 ( & V_2 -> V_17 ) ;
V_2 -> V_10 ++ ;
while ( V_2 -> V_10 >= V_15 ) {
V_2 -> V_11 ++ ;
F_46 ( & V_14 , & V_60 ,
V_61 ) ;
F_13 ( & T_2 ) ;
F_47 () ;
F_17 ( & T_2 ) ;
V_2 -> V_11 -- ;
}
F_48 ( & V_14 , & V_60 ) ;
if ( ! F_1 ( V_2 ) ) {
F_10 ( V_2 ) ;
F_17 ( & T_2 ) ;
return F_50 ( - V_64 ) ;
}
return V_2 ;
}
V_49 = V_49 -> V_29 ;
}
return NULL ;
}
struct V_1 *
F_51 ( struct V_7 * V_8 , struct V_47 * V_48 ,
unsigned int V_54 )
{
unsigned int V_55 = F_39 ( V_54 , V_8 -> V_36 ) ;
struct V_38 * V_49 ;
struct V_1 * V_2 ;
F_17 ( & T_2 ) ;
V_49 = V_8 -> V_40 [ V_55 ] . V_29 ;
V_2 = F_49 ( V_49 , & V_8 -> V_40 [ V_55 ] , V_48 , V_54 ) ;
F_13 ( & T_2 ) ;
return V_2 ;
}
struct V_1 *
F_52 ( struct V_1 * V_65 ,
struct V_47 * V_48 , unsigned int V_54 )
{
struct V_7 * V_8 = V_65 -> V_9 ;
unsigned int V_55 = F_39 ( V_54 , V_8 -> V_36 ) ;
struct V_38 * V_49 ;
struct V_1 * V_2 ;
F_17 ( & T_2 ) ;
V_49 = V_65 -> V_4 . V_5 . V_29 ;
V_2 = F_49 ( V_49 , & V_8 -> V_40 [ V_55 ] , V_48 , V_54 ) ;
F_10 ( V_65 ) ;
return V_2 ;
}
static int T_4 F_53 ( void )
{
F_54 ( & V_66 ) ;
return 0 ;
}
static void T_5 F_55 ( void )
{
F_56 ( & V_66 ) ;
}
