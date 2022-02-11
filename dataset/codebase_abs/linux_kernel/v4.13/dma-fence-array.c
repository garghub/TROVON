static const char * F_1 ( struct V_1 * V_2 )
{
return L_1 ;
}
static const char * F_2 ( struct V_1 * V_2 )
{
return L_2 ;
}
static void F_3 ( struct V_1 * V_3 ,
struct V_4 * V_5 )
{
struct V_6 * V_7 =
F_4 ( V_5 , struct V_6 , V_5 ) ;
struct V_8 * V_9 = V_7 -> V_9 ;
if ( F_5 ( & V_9 -> V_10 ) )
F_6 ( & V_9 -> V_11 ) ;
F_7 ( & V_9 -> V_11 ) ;
}
static bool F_8 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_9 ( V_2 ) ;
struct V_6 * V_5 = ( void * ) ( & V_9 [ 1 ] ) ;
unsigned V_12 ;
for ( V_12 = 0 ; V_12 < V_9 -> V_13 ; ++ V_12 ) {
V_5 [ V_12 ] . V_9 = V_9 ;
F_10 ( & V_9 -> V_11 ) ;
if ( F_11 ( V_9 -> V_14 [ V_12 ] , & V_5 [ V_12 ] . V_5 ,
F_3 ) ) {
F_7 ( & V_9 -> V_11 ) ;
if ( F_5 ( & V_9 -> V_10 ) )
return false ;
}
}
return true ;
}
static bool F_12 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_9 ( V_2 ) ;
return F_13 ( & V_9 -> V_10 ) <= 0 ;
}
static void F_14 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_9 ( V_2 ) ;
unsigned V_12 ;
for ( V_12 = 0 ; V_12 < V_9 -> V_13 ; ++ V_12 )
F_7 ( V_9 -> V_14 [ V_12 ] ) ;
F_15 ( V_9 -> V_14 ) ;
F_16 ( V_2 ) ;
}
struct V_8 * F_17 ( int V_13 ,
struct V_1 * * V_14 ,
T_1 V_15 , unsigned V_16 ,
bool V_17 )
{
struct V_8 * V_9 ;
T_2 V_18 = sizeof( * V_9 ) ;
V_18 += V_13 * sizeof( struct V_6 ) ;
V_9 = F_18 ( V_18 , V_19 ) ;
if ( ! V_9 )
return NULL ;
F_19 ( & V_9 -> V_20 ) ;
F_20 ( & V_9 -> V_11 , & V_21 , & V_9 -> V_20 ,
V_15 , V_16 ) ;
V_9 -> V_13 = V_13 ;
F_21 ( & V_9 -> V_10 , V_17 ? 1 : V_13 ) ;
V_9 -> V_14 = V_14 ;
return V_9 ;
}
bool F_22 ( struct V_1 * V_2 , T_1 V_15 )
{
struct V_8 * V_9 = F_9 ( V_2 ) ;
unsigned V_12 ;
if ( ! F_23 ( V_2 ) )
return V_2 -> V_15 == V_15 ;
for ( V_12 = 0 ; V_12 < V_9 -> V_13 ; V_12 ++ ) {
if ( V_9 -> V_14 [ V_12 ] -> V_15 != V_15 )
return false ;
}
return true ;
}
