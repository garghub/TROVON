static const char * F_1 ( struct V_1 * V_1 )
{
return L_1 ;
}
static const char * F_2 ( struct V_1 * V_1 )
{
return L_2 ;
}
static void F_3 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 =
F_4 ( V_4 , struct V_5 , V_4 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
if ( F_5 ( & V_8 -> V_9 ) )
F_6 ( & V_8 -> V_10 ) ;
F_7 ( & V_8 -> V_10 ) ;
}
static bool F_8 ( struct V_1 * V_1 )
{
struct V_7 * V_8 = F_9 ( V_1 ) ;
struct V_5 * V_4 = ( void * ) ( & V_8 [ 1 ] ) ;
unsigned V_11 ;
for ( V_11 = 0 ; V_11 < V_8 -> V_12 ; ++ V_11 ) {
V_4 [ V_11 ] . V_8 = V_8 ;
F_10 ( & V_8 -> V_10 ) ;
if ( F_11 ( V_8 -> V_13 [ V_11 ] , & V_4 [ V_11 ] . V_4 ,
F_3 ) ) {
F_7 ( & V_8 -> V_10 ) ;
if ( F_5 ( & V_8 -> V_9 ) )
return false ;
}
}
return true ;
}
static bool F_12 ( struct V_1 * V_1 )
{
struct V_7 * V_8 = F_9 ( V_1 ) ;
return F_13 ( & V_8 -> V_9 ) <= 0 ;
}
static void F_14 ( struct V_1 * V_1 )
{
struct V_7 * V_8 = F_9 ( V_1 ) ;
unsigned V_11 ;
for ( V_11 = 0 ; V_11 < V_8 -> V_12 ; ++ V_11 )
F_7 ( V_8 -> V_13 [ V_11 ] ) ;
F_15 ( V_8 -> V_13 ) ;
F_16 ( V_1 ) ;
}
struct V_7 * F_17 ( int V_12 , struct V_1 * * V_13 ,
T_1 V_14 , unsigned V_15 ,
bool V_16 )
{
struct V_7 * V_8 ;
T_2 V_17 = sizeof( * V_8 ) ;
V_17 += V_12 * sizeof( struct V_5 ) ;
V_8 = F_18 ( V_17 , V_18 ) ;
if ( ! V_8 )
return NULL ;
F_19 ( & V_8 -> V_19 ) ;
F_20 ( & V_8 -> V_10 , & V_20 , & V_8 -> V_19 ,
V_14 , V_15 ) ;
V_8 -> V_12 = V_12 ;
F_21 ( & V_8 -> V_9 , V_16 ? 1 : V_12 ) ;
V_8 -> V_13 = V_13 ;
return V_8 ;
}
