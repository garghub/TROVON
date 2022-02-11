void
F_1 ( struct V_1 * * V_2 )
{
struct V_1 * V_3 = * V_2 ;
if ( V_3 ) {
F_2 ( & V_3 -> V_4 . V_5 ) ;
if ( -- V_3 -> V_6 == 0 )
F_3 ( & V_3 -> V_4 , false ) ;
F_4 ( & V_3 -> V_4 . V_5 ) ;
* V_2 = NULL ;
}
}
struct V_1 *
F_5 ( struct V_1 * V_3 )
{
if ( V_3 ) {
F_2 ( & V_3 -> V_4 . V_5 ) ;
if ( ++ V_3 -> V_6 == 1 ) {
int V_7 = F_6 ( & V_3 -> V_4 ) ;
if ( V_7 ) {
V_3 -> V_6 -- ;
F_4 ( & V_3 -> V_4 . V_5 ) ;
return F_7 ( V_7 ) ;
}
}
F_4 ( & V_3 -> V_4 . V_5 ) ;
}
return V_3 ;
}
void
F_8 ( struct V_1 * V_3 , int V_8 )
{
struct V_9 * V_10 = V_3 -> V_4 . V_11 -> V_10 ;
if ( V_3 -> V_12 -> V_13 )
V_3 -> V_12 -> V_13 ( V_3 , V_8 , & V_10 -> V_13 . V_8 [ V_8 ] ) ;
}
static void
F_9 ( struct V_14 * V_4 )
{
struct V_1 * V_3 = V_1 ( V_4 ) ;
if ( V_3 -> V_12 -> V_15 )
V_3 -> V_12 -> V_15 ( V_3 ) ;
}
static int
F_10 ( struct V_14 * V_4 , bool V_16 )
{
struct V_1 * V_3 = V_1 ( V_4 ) ;
if ( V_3 -> V_12 -> V_17 )
return V_3 -> V_12 -> V_17 ( V_3 , V_16 ) ;
return 0 ;
}
static int
F_11 ( struct V_14 * V_4 )
{
struct V_1 * V_3 = V_1 ( V_4 ) ;
struct V_9 * V_10 = V_4 -> V_11 -> V_10 ;
int V_7 = 0 , V_18 ;
T_1 time ;
if ( ! V_3 -> V_6 ) {
F_12 ( V_4 , L_1 ) ;
return V_7 ;
}
if ( V_3 -> V_12 -> V_19 && ! V_3 -> V_4 . V_19 ) {
F_12 ( V_4 , L_2 ) ;
time = F_13 ( F_14 () ) ;
V_7 = V_3 -> V_12 -> V_19 ( V_3 ) ;
if ( V_7 ) {
F_12 ( V_4 , L_3 , V_7 ) ;
return V_7 ;
}
V_3 -> V_4 . V_19 = true ;
time = F_13 ( F_14 () ) - time ;
F_12 ( V_4 , L_4 , time ) ;
}
if ( V_3 -> V_12 -> V_20 )
V_7 = V_3 -> V_12 -> V_20 ( V_3 ) ;
for ( V_18 = 0 ; V_10 && V_18 < V_10 -> V_13 . V_21 ; V_18 ++ )
F_8 ( V_3 , V_18 ) ;
return V_7 ;
}
static void *
F_15 ( struct V_14 * V_4 )
{
struct V_1 * V_3 = V_1 ( V_4 ) ;
if ( V_3 -> V_12 -> V_22 )
return V_3 -> V_12 -> V_22 ( V_3 ) ;
return V_3 ;
}
int
F_16 ( const struct V_23 * V_12 ,
struct V_24 * V_11 , int V_25 , bool V_26 ,
struct V_1 * V_3 )
{
F_17 ( & V_23 , V_11 , V_25 , & V_3 -> V_4 ) ;
V_3 -> V_12 = V_12 ;
if ( ! F_18 ( V_11 -> V_27 , V_28 [ V_25 ] , V_26 ) ) {
F_19 ( & V_3 -> V_4 , L_5 ) ;
return - V_29 ;
}
F_20 ( & V_3 -> V_30 ) ;
return 0 ;
}
int
F_21 ( const struct V_23 * V_12 ,
struct V_24 * V_11 , int V_25 , bool V_26 ,
struct V_1 * * V_2 )
{
if ( ! ( * V_2 = F_22 ( sizeof( * * V_2 ) , V_31 ) ) )
return - V_32 ;
return F_16 ( V_12 , V_11 , V_25 , V_26 , * V_2 ) ;
}
