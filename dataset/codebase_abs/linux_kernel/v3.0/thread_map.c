static int F_1 ( const struct V_1 * V_2 )
{
if ( V_2 -> V_3 [ 0 ] == '.' )
return 0 ;
else
return 1 ;
}
struct V_4 * F_2 ( T_1 V_5 )
{
struct V_4 * V_6 ;
char V_7 [ 256 ] ;
int V_8 ;
struct V_1 * * V_9 = NULL ;
int V_10 ;
sprintf ( V_7 , L_1 , V_5 ) ;
V_8 = F_3 ( V_7 , & V_9 , F_1 , NULL ) ;
if ( V_8 <= 0 )
return NULL ;
V_6 = malloc ( sizeof( * V_6 ) + sizeof( T_1 ) * V_8 ) ;
if ( V_6 != NULL ) {
for ( V_10 = 0 ; V_10 < V_8 ; V_10 ++ )
V_6 -> V_11 [ V_10 ] = atoi ( V_9 [ V_10 ] -> V_3 ) ;
V_6 -> V_12 = V_8 ;
}
for ( V_10 = 0 ; V_10 < V_8 ; V_10 ++ )
free ( V_9 [ V_10 ] ) ;
free ( V_9 ) ;
return V_6 ;
}
struct V_4 * F_4 ( T_1 V_13 )
{
struct V_4 * V_6 = malloc ( sizeof( * V_6 ) + sizeof( T_1 ) ) ;
if ( V_6 != NULL ) {
V_6 -> V_11 [ 0 ] = V_13 ;
V_6 -> V_12 = 1 ;
}
return V_6 ;
}
struct V_4 * F_5 ( T_1 V_5 , T_1 V_13 )
{
if ( V_5 != - 1 )
return F_2 ( V_5 ) ;
return F_4 ( V_13 ) ;
}
void F_6 ( struct V_4 * V_6 )
{
free ( V_6 ) ;
}
