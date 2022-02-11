static void F_1 ( struct V_1 * V_2 ,
int V_3 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < V_2 -> V_5 ; V_4 ++ )
if ( ! F_2 ( V_2 -> V_6 [ V_4 ] ) )
F_3 ( V_2 -> V_6 [ V_4 ] , V_3 ) ;
}
static void F_4 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = F_5 ( V_8 -> V_2 ,
struct V_1 , V_2 ) ;
if ( ! F_2 ( V_2 -> V_9 ) && ! V_2 -> V_10 ) {
F_6 ( V_2 -> V_9 ) ;
V_2 -> V_10 = true ;
}
F_1 ( V_2 , 1 ) ;
}
static void F_7 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = F_5 ( V_8 -> V_2 ,
struct V_1 , V_2 ) ;
F_1 ( V_2 , 0 ) ;
}
static void F_8 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = F_5 ( V_8 -> V_2 ,
struct V_1 , V_2 ) ;
F_1 ( V_2 , 1 ) ;
if ( ! F_2 ( V_2 -> V_9 ) && V_2 -> V_10 ) {
F_9 ( V_2 -> V_9 ) ;
V_2 -> V_10 = false ;
}
}
static void F_10 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = F_5 ( V_8 -> V_2 ,
struct V_1 , V_2 ) ;
int V_4 ;
for ( V_4 = 0 ; V_4 < V_2 -> V_5 ; V_4 ++ )
if ( ! F_2 ( V_2 -> V_6 [ V_4 ] ) )
F_11 ( V_2 -> V_6 [ V_4 ] ) ;
if ( ! F_2 ( V_2 -> V_9 ) )
F_12 ( V_2 -> V_9 ) ;
F_13 ( V_2 ) ;
}
struct V_11 * F_14 ( struct V_7 * V_8 ,
struct V_12 * V_13 )
{
struct V_1 * V_2 ;
int V_4 , V_5 , V_14 = 0 ;
V_5 = F_15 ( V_13 -> V_15 , L_1 ) ;
if ( V_5 < 0 )
V_5 = 0 ;
V_2 = F_16 ( sizeof( struct V_1 ) + V_5 *
sizeof( struct V_16 * ) , V_17 ) ;
if ( ! V_2 )
return F_17 ( - V_18 ) ;
V_2 -> V_9 = F_18 ( V_13 , L_2 ) ;
if ( F_2 ( V_2 -> V_9 ) &&
F_19 ( V_2 -> V_9 ) != - V_19 ) {
V_14 = F_19 ( V_2 -> V_9 ) ;
goto free;
}
for ( V_4 = 0 ; V_4 < V_5 ; V_4 ++ ) {
V_2 -> V_6 [ V_4 ] = F_20 ( V_13 , L_3 , V_4 ,
V_20 ) ;
if ( F_2 ( V_2 -> V_6 [ V_4 ] ) &&
F_19 ( V_2 -> V_6 [ V_4 ] ) != - V_19 &&
F_19 ( V_2 -> V_6 [ V_4 ] ) != - V_21 ) {
V_14 = F_19 ( V_2 -> V_6 [ V_4 ] ) ;
while ( V_4 -- )
F_11 ( V_2 -> V_6 [ V_4 ] ) ;
goto F_12;
}
}
V_2 -> V_5 = V_5 ;
V_2 -> V_2 . V_22 = & V_23 ;
return & V_2 -> V_2 ;
F_12:
if ( ! F_2 ( V_2 -> V_9 ) )
F_12 ( V_2 -> V_9 ) ;
free:
F_13 ( V_2 ) ;
return F_17 ( V_14 ) ;
}
