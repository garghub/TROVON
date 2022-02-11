static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_5 ;
V_4 = F_2 ( & V_2 -> V_6 , sizeof( * V_4 ) , V_7 ) ;
if ( ! V_4 )
return - V_8 ;
F_3 ( V_2 , V_4 ) ;
V_4 -> V_9 = F_4 ( NULL ) ;
if ( F_5 ( V_4 -> V_9 ) )
return F_6 ( V_4 -> V_9 ) ;
V_4 -> V_10 = F_7 ( V_2 , V_11 ) ;
if ( F_5 ( V_4 -> V_10 ) )
return F_6 ( V_4 -> V_10 ) ;
V_4 -> V_12 = F_2 ( & V_2 -> V_6 ,
sizeof( struct V_13 ) * V_4 -> V_10 -> V_14 ,
V_7 ) ;
if ( ! V_4 -> V_12 ) {
F_8 ( V_4 -> V_10 ) ;
return - V_8 ;
}
for ( V_5 = 0 ; V_5 < V_4 -> V_10 -> V_14 ; V_5 ++ ) {
V_4 -> V_12 [ V_5 ] = F_9 ( & V_4 -> V_10 -> V_12 [ V_5 ] ) ;
if ( ! V_4 -> V_12 ) {
F_8 ( V_4 -> V_10 ) ;
return - V_8 ;
}
F_10 ( V_4 -> V_9 , V_4 -> V_12 [ V_5 ] ) ;
}
return 0 ;
}
static int F_11 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_5 ;
V_4 = F_12 ( V_2 ) ;
for ( V_5 = 0 ; V_5 < V_4 -> V_10 -> V_14 ; V_5 ++ )
F_13 ( V_4 -> V_12 [ V_5 ] ) ;
F_8 ( V_4 -> V_10 ) ;
F_14 ( V_4 -> V_9 ) ;
return 0 ;
}
static int T_1 F_15 ( void )
{
return F_16 ( & V_15 ) ;
}
