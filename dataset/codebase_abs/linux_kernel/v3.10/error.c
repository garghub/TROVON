int F_1 ( void )
{
struct V_1 * V_2 ;
int V_3 ;
for ( V_3 = 0 ; V_3 < V_4 ; V_3 ++ )
F_2 ( & V_5 [ V_3 ] ) ;
for ( V_2 = V_6 ; V_2 -> V_7 != NULL ; V_2 ++ ) {
V_2 -> V_8 = strlen ( V_2 -> V_7 ) ;
V_3 = F_3 ( V_2 -> V_7 , V_2 -> V_8 , 0 ) % V_4 ;
F_4 ( & V_2 -> V_9 ) ;
F_5 ( & V_2 -> V_9 , & V_5 [ V_3 ] ) ;
}
return 1 ;
}
int F_6 ( char * V_10 , int V_11 )
{
int V_12 ;
struct V_1 * V_2 ;
int V_3 ;
V_12 = 0 ;
V_2 = NULL ;
V_3 = F_3 ( V_10 , V_11 , 0 ) % V_4 ;
F_7 (c, &hash_errmap[bucket], list) {
if ( V_2 -> V_8 == V_11 && ! memcmp ( V_2 -> V_7 , V_10 , V_11 ) ) {
V_12 = V_2 -> V_13 ;
break;
}
}
if ( V_12 == 0 ) {
V_10 [ V_11 ] = 0 ;
F_8 ( L_1 ,
V_14 , V_10 ) ;
V_12 = V_15 ;
}
return - V_12 ;
}
