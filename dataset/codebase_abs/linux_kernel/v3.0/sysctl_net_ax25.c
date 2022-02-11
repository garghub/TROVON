void F_1 ( void )
{
T_1 * T_1 ;
int V_1 , V_2 ;
F_2 ( & V_3 ) ;
for ( V_4 = sizeof( V_5 ) , T_1 = V_6 ; T_1 != NULL ; T_1 = T_1 -> V_7 )
V_4 += sizeof( V_5 ) ;
if ( ( V_8 = F_3 ( V_4 , V_9 ) ) == NULL ) {
F_4 ( & V_3 ) ;
return;
}
for ( V_1 = 0 , T_1 = V_6 ; T_1 != NULL ; T_1 = T_1 -> V_7 ) {
struct V_5 * V_10 = F_5 ( V_11 ,
sizeof( V_11 ) ,
V_9 ) ;
if ( ! V_10 ) {
while ( V_1 -- )
F_6 ( V_8 [ V_1 ] . V_10 ) ;
F_6 ( V_8 ) ;
F_4 ( & V_3 ) ;
return;
}
V_8 [ V_1 ] . V_10 = T_1 -> V_12 = V_10 ;
V_8 [ V_1 ] . V_13 = T_1 -> V_14 -> V_15 ;
V_8 [ V_1 ] . V_16 = 0555 ;
for ( V_2 = 0 ; V_2 < V_17 ; V_2 ++ )
V_10 [ V_2 ] . V_18 = & T_1 -> V_19 [ V_2 ] ;
V_1 ++ ;
}
F_4 ( & V_3 ) ;
V_20 = F_7 ( V_21 , V_8 ) ;
}
void F_8 ( void )
{
V_5 * V_22 ;
F_9 ( V_20 ) ;
for ( V_22 = V_8 ; V_22 -> V_13 ; V_22 ++ )
F_6 ( V_22 -> V_10 ) ;
F_6 ( V_8 ) ;
}
