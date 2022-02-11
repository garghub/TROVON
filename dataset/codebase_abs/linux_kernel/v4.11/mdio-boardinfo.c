void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
struct V_7 * V_8 ;
int V_9 ;
F_2 ( & V_10 ) ;
F_3 (be, &mdio_board_list, list) {
V_8 = & V_4 -> V_11 ;
if ( strcmp ( V_2 -> V_12 , V_8 -> V_13 ) )
continue;
V_6 = F_4 ( V_2 , V_8 -> V_14 ) ;
if ( F_5 ( V_6 ) )
continue;
strncpy ( V_6 -> V_15 , V_8 -> V_15 ,
sizeof( V_6 -> V_15 ) ) ;
V_6 -> V_16 = V_17 ;
V_6 -> V_18 . V_19 = ( void * ) V_8 -> V_19 ;
V_9 = F_6 ( V_6 ) ;
if ( V_9 ) {
F_7 ( V_6 ) ;
continue;
}
}
F_8 ( & V_10 ) ;
}
int F_9 ( const struct V_7 * V_20 ,
unsigned int V_21 )
{
struct V_3 * V_4 ;
unsigned int V_22 ;
V_4 = F_10 ( V_21 , sizeof( * V_4 ) , V_23 ) ;
if ( ! V_4 )
return - V_24 ;
for ( V_22 = 0 ; V_22 < V_21 ; V_22 ++ , V_4 ++ , V_20 ++ ) {
memcpy ( & V_4 -> V_11 , V_20 , sizeof( * V_20 ) ) ;
F_2 ( & V_10 ) ;
F_11 ( & V_4 -> V_25 , & V_26 ) ;
F_8 ( & V_10 ) ;
}
return 0 ;
}
