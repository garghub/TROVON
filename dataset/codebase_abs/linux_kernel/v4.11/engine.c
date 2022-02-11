bool
F_1 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 -> V_4 )
return V_2 -> V_3 -> V_4 ( V_2 ) ;
return false ;
}
void
F_2 ( struct V_1 * * V_5 )
{
struct V_1 * V_2 = * V_5 ;
if ( V_2 ) {
F_3 ( & V_2 -> V_6 . V_7 ) ;
if ( -- V_2 -> V_8 == 0 )
F_4 ( & V_2 -> V_6 , false ) ;
F_5 ( & V_2 -> V_6 . V_7 ) ;
* V_5 = NULL ;
}
}
struct V_1 *
F_6 ( struct V_1 * V_2 )
{
if ( V_2 ) {
F_3 ( & V_2 -> V_6 . V_7 ) ;
if ( ++ V_2 -> V_8 == 1 ) {
int V_9 = F_7 ( & V_2 -> V_6 ) ;
if ( V_9 ) {
V_2 -> V_8 -- ;
F_5 ( & V_2 -> V_6 . V_7 ) ;
return F_8 ( V_9 ) ;
}
}
F_5 ( & V_2 -> V_6 . V_7 ) ;
}
return V_2 ;
}
void
F_9 ( struct V_1 * V_2 , int V_10 )
{
struct V_11 * V_12 = V_2 -> V_6 . V_13 -> V_12 ;
if ( V_2 -> V_3 -> V_14 )
V_2 -> V_3 -> V_14 ( V_2 , V_10 , & V_12 -> V_14 . V_10 [ V_10 ] ) ;
}
static void
F_10 ( struct V_15 * V_6 )
{
struct V_1 * V_2 = V_1 ( V_6 ) ;
if ( V_2 -> V_3 -> V_16 )
V_2 -> V_3 -> V_16 ( V_2 ) ;
}
static int
F_11 ( struct V_15 * V_6 , bool V_17 )
{
struct V_1 * V_2 = V_1 ( V_6 ) ;
if ( V_2 -> V_3 -> V_18 )
return V_2 -> V_3 -> V_18 ( V_2 , V_17 ) ;
return 0 ;
}
static int
F_12 ( struct V_15 * V_6 )
{
struct V_1 * V_2 = V_1 ( V_6 ) ;
struct V_11 * V_12 = V_6 -> V_13 -> V_12 ;
int V_9 = 0 , V_19 ;
T_1 time ;
if ( ! V_2 -> V_8 ) {
F_13 ( V_6 , L_1 ) ;
return V_9 ;
}
if ( V_2 -> V_3 -> V_20 && ! V_2 -> V_6 . V_20 ) {
F_13 ( V_6 , L_2 ) ;
time = F_14 ( F_15 () ) ;
V_9 = V_2 -> V_3 -> V_20 ( V_2 ) ;
if ( V_9 ) {
F_13 ( V_6 , L_3 , V_9 ) ;
return V_9 ;
}
V_2 -> V_6 . V_20 = true ;
time = F_14 ( F_15 () ) - time ;
F_13 ( V_6 , L_4 , time ) ;
}
if ( V_2 -> V_3 -> V_21 )
V_9 = V_2 -> V_3 -> V_21 ( V_2 ) ;
for ( V_19 = 0 ; V_12 && V_19 < V_12 -> V_14 . V_22 ; V_19 ++ )
F_9 ( V_2 , V_19 ) ;
return V_9 ;
}
static void *
F_16 ( struct V_15 * V_6 )
{
struct V_1 * V_2 = V_1 ( V_6 ) ;
if ( V_2 -> V_3 -> V_23 )
return V_2 -> V_3 -> V_23 ( V_2 ) ;
return V_2 ;
}
int
F_17 ( const struct V_24 * V_3 ,
struct V_25 * V_13 , int V_26 , bool V_27 ,
struct V_1 * V_2 )
{
F_18 ( & V_24 , V_13 , V_26 , & V_2 -> V_6 ) ;
V_2 -> V_3 = V_3 ;
if ( ! F_19 ( V_13 -> V_28 , V_29 [ V_26 ] , V_27 ) ) {
F_20 ( & V_2 -> V_6 , L_5 ) ;
return - V_30 ;
}
F_21 ( & V_2 -> V_31 ) ;
return 0 ;
}
int
F_22 ( const struct V_24 * V_3 ,
struct V_25 * V_13 , int V_26 , bool V_27 ,
struct V_1 * * V_5 )
{
if ( ! ( * V_5 = F_23 ( sizeof( * * V_5 ) , V_32 ) ) )
return - V_33 ;
return F_17 ( V_3 , V_13 , V_26 , V_27 , * V_5 ) ;
}
