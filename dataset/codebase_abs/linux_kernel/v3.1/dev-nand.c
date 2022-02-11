static int T_1 F_1 ( struct V_1 * V_2 )
{
void * V_3 ;
int V_4 ;
V_4 = sizeof( struct V_5 ) * V_2 -> V_6 ;
if ( V_4 ) {
V_3 = F_2 ( V_2 -> V_7 , V_4 , V_8 ) ;
V_2 -> V_7 = V_3 ;
if ( ! V_3 )
return - V_9 ;
}
if ( V_2 -> V_10 && V_2 -> V_11 ) {
V_4 = sizeof( int ) * V_2 -> V_11 ;
V_3 = F_2 ( V_2 -> V_10 , V_4 , V_8 ) ;
V_2 -> V_10 = V_3 ;
if ( ! V_3 )
return - V_9 ;
}
if ( V_2 -> V_12 ) {
V_3 = F_2 ( V_2 -> V_12 ,
sizeof( struct V_13 ) , V_8 ) ;
V_2 -> V_12 = V_3 ;
if ( ! V_3 )
return - V_9 ;
}
return 0 ;
}
void T_1 F_3 ( struct V_14 * V_15 )
{
struct V_14 * V_16 ;
int V_4 ;
int V_17 ;
V_16 = F_4 ( V_15 , sizeof( struct V_14 ) ,
& V_18 ) ;
if ( ! V_16 )
return;
V_4 = sizeof( struct V_1 ) * V_16 -> V_19 ;
if ( V_4 ) {
struct V_1 * V_20 = V_16 -> V_21 ;
struct V_1 * V_22 ;
int V_23 ;
V_22 = F_2 ( V_20 , V_4 , V_8 ) ;
V_16 -> V_21 = V_22 ;
if ( ! V_22 ) {
F_5 ( V_24 L_1 , V_25 ) ;
return;
}
for ( V_23 = 0 ; V_23 < V_16 -> V_19 ; V_23 ++ ) {
V_17 = F_1 ( V_22 ) ;
if ( V_17 ) {
F_5 ( V_24 L_2 ,
V_25 , V_23 ) ;
return;
}
V_22 ++ ;
}
}
}
