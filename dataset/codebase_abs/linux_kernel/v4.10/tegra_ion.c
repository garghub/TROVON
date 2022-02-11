static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 . V_6 ;
int V_7 ;
int V_8 ;
V_9 = V_4 -> V_10 ;
V_11 = F_2 ( & V_2 -> V_5 , V_4 -> V_10 ,
sizeof( struct V_12 * ) , V_13 ) ;
V_14 = F_3 ( NULL ) ;
if ( F_4 ( V_14 ) )
return F_5 ( V_14 ) ;
for ( V_8 = 0 ; V_8 < V_9 ; V_8 ++ ) {
struct V_15 * V_16 = & V_4 -> V_11 [ V_8 ] ;
V_11 [ V_8 ] = F_6 ( V_16 ) ;
if ( F_7 ( V_11 [ V_8 ] ) ) {
V_7 = F_5 ( V_11 [ V_8 ] ) ;
goto V_7;
}
F_8 ( V_14 , V_11 [ V_8 ] ) ;
}
F_9 ( V_2 , V_14 ) ;
return 0 ;
V_7:
for ( V_8 = 0 ; V_8 < V_9 ; ++ V_8 )
F_10 ( V_11 [ V_8 ] ) ;
return V_7 ;
}
static int F_11 ( struct V_1 * V_2 )
{
struct V_17 * V_14 = F_12 ( V_2 ) ;
int V_8 ;
F_13 ( V_14 ) ;
for ( V_8 = 0 ; V_8 < V_9 ; V_8 ++ )
F_10 ( V_11 [ V_8 ] ) ;
return 0 ;
}
