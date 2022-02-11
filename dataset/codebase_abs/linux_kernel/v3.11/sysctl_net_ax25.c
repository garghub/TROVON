int F_1 ( T_1 * T_1 )
{
char V_1 [ sizeof( L_1 ) + V_2 ] ;
int V_3 ;
struct V_4 * V_5 ;
V_5 = F_2 ( V_6 , sizeof( V_6 ) , V_7 ) ;
if ( ! V_5 )
return - V_8 ;
for ( V_3 = 0 ; V_3 < V_9 ; V_3 ++ )
V_5 [ V_3 ] . V_10 = & T_1 -> V_11 [ V_3 ] ;
snprintf ( V_1 , sizeof( V_1 ) , L_2 , T_1 -> V_12 -> V_13 ) ;
T_1 -> V_14 = F_3 ( & V_15 , V_1 , V_5 ) ;
if ( ! T_1 -> V_14 ) {
F_4 ( V_5 ) ;
return - V_8 ;
}
return 0 ;
}
void F_5 ( T_1 * T_1 )
{
struct V_16 * V_17 = T_1 -> V_14 ;
struct V_4 * V_5 ;
if ( V_17 ) {
T_1 -> V_14 = NULL ;
V_5 = V_17 -> V_18 ;
F_6 ( V_17 ) ;
F_4 ( V_5 ) ;
}
}
