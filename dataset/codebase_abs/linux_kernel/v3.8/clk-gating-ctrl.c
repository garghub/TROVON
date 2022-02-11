static struct V_1 * F_1 (
struct V_2 * V_3 , void * V_4 )
{
struct V_5 * V_6 = (struct V_5 * ) V_4 ;
int V_7 ;
if ( V_3 -> V_8 < 1 )
return F_2 ( - V_9 ) ;
for ( V_7 = 0 ; V_7 < V_6 -> V_10 ; V_7 ++ ) {
struct V_11 * V_12 =
F_3 ( F_4 ( V_6 -> V_13 [ V_7 ] ) ) ;
if ( V_3 -> args [ 0 ] == V_12 -> V_14 )
return V_6 -> V_13 [ V_7 ] ;
}
return F_2 ( - V_15 ) ;
}
static void T_1 F_5 (
struct V_16 * V_17 , const struct V_18 * V_19 )
{
struct V_5 * V_6 ;
struct V_1 * V_1 ;
void T_2 * V_20 ;
const char * V_21 = NULL ;
int V_7 ;
V_20 = F_6 ( V_17 , 0 ) ;
V_1 = F_7 ( V_17 , 0 ) ;
if ( ! F_8 ( V_1 ) ) {
V_21 = F_9 ( V_1 ) ;
F_10 ( V_1 ) ;
}
V_6 = F_11 ( sizeof( struct V_5 ) , V_22 ) ;
if ( F_12 ( ! V_6 ) )
return;
F_13 ( & V_6 -> V_23 ) ;
for ( V_7 = 0 ; V_19 [ V_7 ] . V_24 ; )
V_7 ++ ;
V_6 -> V_10 = V_7 ;
V_6 -> V_13 = F_11 ( V_6 -> V_10 * sizeof( struct V_1 * ) ,
V_22 ) ;
if ( F_12 ( ! V_6 -> V_13 ) ) {
F_14 ( V_6 ) ;
return;
}
for ( V_7 = 0 ; V_7 < V_6 -> V_10 ; V_7 ++ ) {
T_3 V_25 = 0 ;
const char * V_26 =
( V_19 [ V_7 ] . V_26 ) ? V_19 [ V_7 ] . V_26 : V_21 ;
if ( ! strcmp ( V_19 [ V_7 ] . V_24 , L_1 ) )
V_25 |= V_27 ;
V_6 -> V_13 [ V_7 ] = F_15 ( NULL , V_19 [ V_7 ] . V_24 , V_26 ,
V_25 , V_20 , V_19 [ V_7 ] . V_14 , 0 , & V_6 -> V_23 ) ;
F_12 ( F_8 ( V_6 -> V_13 [ V_7 ] ) ) ;
}
F_16 ( V_17 , F_1 , V_6 ) ;
}
void T_1 F_17 ( void )
{
struct V_16 * V_17 ;
F_18 (np, clk_gating_match) {
const struct V_28 * V_29 =
F_19 ( V_30 , V_17 ) ;
F_5 ( V_17 ,
( const struct V_18 * ) V_29 -> V_4 ) ;
}
}
