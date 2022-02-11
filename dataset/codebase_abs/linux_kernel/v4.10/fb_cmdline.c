int F_1 ( const char * V_1 , char * * V_2 )
{
char * V_3 , * V_4 = NULL ;
int V_5 = 0 ;
int V_6 = strlen ( V_1 ) , V_7 ;
if ( V_6 && V_8 && strncmp ( V_1 , L_1 , 4 ) )
V_5 = 1 ;
if ( V_6 && ! V_5 ) {
for ( V_7 = 0 ; V_7 < V_9 ; V_7 ++ ) {
if ( V_10 [ V_7 ] == NULL )
continue;
if ( ! V_10 [ V_7 ] [ 0 ] )
continue;
V_3 = V_10 [ V_7 ] ;
if ( ! strncmp ( V_1 , V_3 , V_6 ) &&
V_3 [ V_6 ] == ':' )
V_4 = V_3 + V_6 + 1 ;
}
}
if ( ! V_4 && V_2 && V_11 )
V_4 = F_2 ( V_11 , V_12 ) ;
if ( V_4 && ! strncmp ( V_4 , L_2 , 3 ) )
V_5 = 1 ;
if ( V_2 )
* V_2 = V_4 ;
return V_5 ;
}
static int T_1 F_3 ( char * V_4 )
{
int V_7 , V_13 = 0 ;
if ( ! V_4 || ! * V_4 )
V_13 = 1 ;
if ( ! V_13 && ! strncmp ( V_4 , L_3 , 6 ) ) {
V_8 = 1 ;
V_13 = 1 ;
}
if ( ! V_13 && ! strchr ( V_4 , ':' ) ) {
V_11 = V_4 ;
V_13 = 1 ;
}
if ( ! V_13 ) {
for ( V_7 = 0 ; V_7 < V_9 ; V_7 ++ ) {
if ( V_10 [ V_7 ] == NULL ) {
V_10 [ V_7 ] = V_4 ;
break;
}
}
}
return 1 ;
}
