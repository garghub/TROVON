struct V_1 * F_1 ( unsigned int V_2 , T_1 V_3 )
{
struct V_1 * V_4 ;
unsigned int V_5 ;
T_2 V_6 ;
if ( V_2 > 0xffff )
return NULL ;
V_6 = F_2 ( F_3 ( struct V_1 , V_7 [ V_8 ] ) ,
sizeof( void * ) ) ;
V_4 = F_4 ( V_6 + V_2 * sizeof( V_4 -> V_9 [ 0 ] ) , V_3 ) ;
if ( ! V_4 )
return NULL ;
F_5 ( & V_4 -> V_10 ) ;
V_4 -> V_9 = ( void * * ) ( ( char * ) V_4 + V_6 ) ;
F_6 (cpu) {
V_4 -> V_7 [ V_5 ] . V_11 = V_5 % V_2 ;
V_4 -> V_7 [ V_5 ] . V_12 = V_13 ;
}
V_4 -> V_2 = V_2 ;
return V_4 ;
}
static void F_7 ( struct V_14 * V_15 )
{
struct V_1 * V_4 = F_8 ( V_15 , struct V_1 , V_10 ) ;
F_9 ( V_4 ) ;
}
static inline void F_10 ( struct V_1 * V_4 )
{
F_11 ( & V_4 -> V_10 ) ;
}
int F_12 ( struct V_1 * V_4 )
{
return F_13 ( & V_4 -> V_10 , F_7 ) ;
}
static bool F_14 ( struct V_1 * V_4 , unsigned int V_5 ,
const struct V_16 * V_17 , T_3 V_12 )
{
int V_18 ;
F_15 (neigh, mask) {
if ( V_4 -> V_7 [ V_5 ] . V_12 > V_12 &&
V_4 -> V_7 [ V_18 ] . V_12 <= V_12 ) {
V_4 -> V_7 [ V_5 ] . V_11 = V_4 -> V_7 [ V_18 ] . V_11 ;
V_4 -> V_7 [ V_5 ] . V_12 = V_12 ;
return true ;
}
}
return false ;
}
static void F_16 ( const struct V_1 * V_4 , const char * V_19 )
{
unsigned V_11 ;
unsigned int V_5 ;
F_17 ( L_1 , V_4 , V_19 ) ;
F_6 (cpu) {
V_11 = V_4 -> V_7 [ V_5 ] . V_11 ;
F_17 ( L_2 ,
V_5 , V_11 , V_4 -> V_7 [ V_5 ] . V_12 ) ;
}
}
static inline void
F_16 ( const struct V_1 * V_4 , const char * V_19 )
{
}
int F_18 ( struct V_1 * V_4 , void * V_9 )
{
T_3 V_11 ;
F_19 ( V_4 -> V_20 >= V_4 -> V_2 ) ;
V_11 = V_4 -> V_20 ++ ;
V_4 -> V_9 [ V_11 ] = V_9 ;
return V_11 ;
}
int F_20 ( struct V_1 * V_4 , T_3 V_11 ,
const struct V_16 * V_21 )
{
T_4 V_22 ;
unsigned int V_5 ;
if ( F_21 ( ! F_22 ( & V_22 , V_23 ) ) )
return - V_24 ;
F_23 (cpu) {
if ( V_4 -> V_7 [ V_5 ] . V_11 == V_11 ) {
V_4 -> V_7 [ V_5 ] . V_12 = V_13 ;
F_24 ( V_5 , V_22 ) ;
}
}
F_16 ( V_4 , L_3 ) ;
F_15 (cpu, affinity) {
V_4 -> V_7 [ V_5 ] . V_11 = V_11 ;
V_4 -> V_7 [ V_5 ] . V_12 = 0 ;
F_25 ( V_22 , V_22 ,
F_26 ( F_27 ( V_5 ) ) ) ;
}
F_16 ( V_4 , L_4 ) ;
F_15 (cpu, update_mask) {
if ( F_14 ( V_4 , V_5 ,
F_28 ( V_5 ) , 1 ) )
continue;
if ( F_14 ( V_4 , V_5 ,
F_29 ( V_5 ) , 2 ) )
continue;
if ( F_14 ( V_4 , V_5 ,
F_26 ( F_27 ( V_5 ) ) , 3 ) )
continue;
}
F_16 ( V_4 , L_5 ) ;
F_30 ( V_22 ) ;
return 0 ;
}
void F_31 ( struct V_1 * V_4 )
{
struct V_25 * V_26 ;
T_3 V_11 ;
if ( ! V_4 )
return;
for ( V_11 = 0 ; V_11 < V_4 -> V_20 ; V_11 ++ ) {
V_26 = V_4 -> V_9 [ V_11 ] ;
F_32 ( V_26 -> V_27 . V_28 , NULL ) ;
}
F_12 ( V_4 ) ;
}
static void
F_33 ( struct V_29 * V_27 , const T_5 * V_17 )
{
struct V_25 * V_26 =
F_8 ( V_27 , struct V_25 , V_27 ) ;
int V_30 ;
V_30 = F_20 ( V_26 -> V_4 , V_26 -> V_11 , V_17 ) ;
if ( V_30 )
F_34 ( L_6 , V_30 ) ;
}
static void F_35 ( struct V_14 * V_15 )
{
struct V_25 * V_26 =
F_8 ( V_15 , struct V_25 , V_27 . V_14 ) ;
F_12 ( V_26 -> V_4 ) ;
F_9 ( V_26 ) ;
}
int F_36 ( struct V_1 * V_4 , int V_28 )
{
struct V_25 * V_26 = F_4 ( sizeof( * V_26 ) , V_23 ) ;
int V_30 ;
if ( ! V_26 )
return - V_24 ;
V_26 -> V_27 . V_27 = F_33 ;
V_26 -> V_27 . V_31 = F_35 ;
V_26 -> V_4 = V_4 ;
F_10 ( V_4 ) ;
V_26 -> V_11 = F_18 ( V_4 , V_26 ) ;
V_30 = F_32 ( V_28 , & V_26 -> V_27 ) ;
if ( V_30 ) {
F_12 ( V_26 -> V_4 ) ;
F_9 ( V_26 ) ;
}
return V_30 ;
}
