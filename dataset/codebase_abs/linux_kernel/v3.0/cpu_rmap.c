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
V_4 -> V_9 = ( void * * ) ( ( char * ) V_4 + V_6 ) ;
F_5 (cpu) {
V_4 -> V_7 [ V_5 ] . V_10 = V_5 % V_2 ;
V_4 -> V_7 [ V_5 ] . V_11 = V_12 ;
}
V_4 -> V_2 = V_2 ;
return V_4 ;
}
static bool F_6 ( struct V_1 * V_4 , unsigned int V_5 ,
const struct V_13 * V_14 , T_3 V_11 )
{
int V_15 ;
F_7 (neigh, mask) {
if ( V_4 -> V_7 [ V_5 ] . V_11 > V_11 &&
V_4 -> V_7 [ V_15 ] . V_11 <= V_11 ) {
V_4 -> V_7 [ V_5 ] . V_10 = V_4 -> V_7 [ V_15 ] . V_10 ;
V_4 -> V_7 [ V_5 ] . V_11 = V_11 ;
return true ;
}
}
return false ;
}
static void F_8 ( const struct V_1 * V_4 , const char * V_16 )
{
unsigned V_10 ;
unsigned int V_5 ;
F_9 ( L_1 , V_4 , V_16 ) ;
F_5 (cpu) {
V_10 = V_4 -> V_7 [ V_5 ] . V_10 ;
F_9 ( L_2 ,
V_5 , V_10 , V_4 -> V_7 [ V_5 ] . V_11 ) ;
}
}
static inline void
F_8 ( const struct V_1 * V_4 , const char * V_16 )
{
}
int F_10 ( struct V_1 * V_4 , void * V_9 )
{
T_3 V_10 ;
F_11 ( V_4 -> V_17 >= V_4 -> V_2 ) ;
V_10 = V_4 -> V_17 ++ ;
V_4 -> V_9 [ V_10 ] = V_9 ;
return V_10 ;
}
int F_12 ( struct V_1 * V_4 , T_3 V_10 ,
const struct V_13 * V_18 )
{
T_4 V_19 ;
unsigned int V_5 ;
if ( F_13 ( ! F_14 ( & V_19 , V_20 ) ) )
return - V_21 ;
F_15 (cpu) {
if ( V_4 -> V_7 [ V_5 ] . V_10 == V_10 ) {
V_4 -> V_7 [ V_5 ] . V_11 = V_12 ;
F_16 ( V_5 , V_19 ) ;
}
}
F_8 ( V_4 , L_3 ) ;
F_7 (cpu, affinity) {
V_4 -> V_7 [ V_5 ] . V_10 = V_10 ;
V_4 -> V_7 [ V_5 ] . V_11 = 0 ;
F_17 ( V_19 , V_19 ,
F_18 ( F_19 ( V_5 ) ) ) ;
}
F_8 ( V_4 , L_4 ) ;
F_7 (cpu, update_mask) {
if ( F_6 ( V_4 , V_5 ,
F_20 ( V_5 ) , 1 ) )
continue;
if ( F_6 ( V_4 , V_5 ,
F_21 ( V_5 ) , 2 ) )
continue;
if ( F_6 ( V_4 , V_5 ,
F_18 ( F_19 ( V_5 ) ) , 3 ) )
continue;
}
F_8 ( V_4 , L_5 ) ;
F_22 ( V_19 ) ;
return 0 ;
}
void F_23 ( struct V_1 * V_4 )
{
struct V_22 * V_23 ;
T_3 V_10 ;
if ( ! V_4 )
return;
for ( V_10 = 0 ; V_10 < V_4 -> V_17 ; V_10 ++ ) {
V_23 = V_4 -> V_9 [ V_10 ] ;
F_24 ( V_23 -> V_24 . V_25 , NULL ) ;
}
F_25 () ;
F_26 ( V_4 ) ;
}
static void
F_27 ( struct V_26 * V_24 , const T_5 * V_14 )
{
struct V_22 * V_23 =
F_28 ( V_24 , struct V_22 , V_24 ) ;
int V_27 ;
V_27 = F_12 ( V_23 -> V_4 , V_23 -> V_10 , V_14 ) ;
if ( V_27 )
F_29 ( L_6 , V_27 ) ;
}
static void F_30 ( struct V_28 * V_29 )
{
struct V_22 * V_23 =
F_28 ( V_29 , struct V_22 , V_24 . V_28 ) ;
F_26 ( V_23 ) ;
}
int F_31 ( struct V_1 * V_4 , int V_25 )
{
struct V_22 * V_23 = F_4 ( sizeof( * V_23 ) , V_20 ) ;
int V_27 ;
if ( ! V_23 )
return - V_21 ;
V_23 -> V_24 . V_24 = F_27 ;
V_23 -> V_24 . V_30 = F_30 ;
V_23 -> V_4 = V_4 ;
V_23 -> V_10 = F_10 ( V_4 , V_23 ) ;
V_27 = F_24 ( V_25 , & V_23 -> V_24 ) ;
if ( V_27 )
F_26 ( V_23 ) ;
return V_27 ;
}
