void F_1 ( struct V_1 * V_2 ,
int (* F_2)
( struct V_1 * V_2 ,
struct V_3 * V_4 ) )
{
struct V_5 * V_6 ;
struct V_3 * V_4 ;
int V_7 ;
F_3 ( & V_8 ) ;
F_4 (be, &mdio_board_list, list) {
V_4 = & V_6 -> V_9 ;
if ( strcmp ( V_2 -> V_10 , V_4 -> V_11 ) )
continue;
V_7 = F_2 ( V_2 , V_4 ) ;
if ( V_7 )
continue;
}
F_5 ( & V_8 ) ;
}
int F_6 ( const struct V_3 * V_12 ,
unsigned int V_13 )
{
struct V_5 * V_6 ;
unsigned int V_14 ;
V_6 = F_7 ( V_13 , sizeof( * V_6 ) , V_15 ) ;
if ( ! V_6 )
return - V_16 ;
for ( V_14 = 0 ; V_14 < V_13 ; V_14 ++ , V_6 ++ , V_12 ++ ) {
memcpy ( & V_6 -> V_9 , V_12 , sizeof( * V_12 ) ) ;
F_3 ( & V_8 ) ;
F_8 ( & V_6 -> V_17 , & V_18 ) ;
F_5 ( & V_8 ) ;
}
return 0 ;
}
