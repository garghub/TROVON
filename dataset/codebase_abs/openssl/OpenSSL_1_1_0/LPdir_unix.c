const char * F_1 ( T_1 * * V_1 , const char * V_2 )
{
struct V_3 * V_4 = NULL ;
if ( V_1 == NULL || V_2 == NULL ) {
V_5 = V_6 ;
return 0 ;
}
V_5 = 0 ;
if ( * V_1 == NULL ) {
* V_1 = malloc ( sizeof( * * V_1 ) ) ;
if ( * V_1 == NULL ) {
V_5 = V_7 ;
return 0 ;
}
memset ( * V_1 , 0 , sizeof( * * V_1 ) ) ;
( * V_1 ) -> V_8 = F_2 ( V_2 ) ;
if ( ( * V_1 ) -> V_8 == NULL ) {
int V_9 = V_5 ;
free ( * V_1 ) ;
* V_1 = NULL ;
V_5 = V_9 ;
return 0 ;
}
}
V_4 = F_3 ( ( * V_1 ) -> V_8 ) ;
if ( V_4 == NULL ) {
return 0 ;
}
strncpy ( ( * V_1 ) -> V_10 , V_4 -> V_11 ,
sizeof( ( * V_1 ) -> V_10 ) - 1 ) ;
( * V_1 ) -> V_10 [ sizeof( ( * V_1 ) -> V_10 ) - 1 ] = '\0' ;
return ( * V_1 ) -> V_10 ;
}
int F_4 ( T_1 * * V_1 )
{
if ( V_1 != NULL && * V_1 != NULL ) {
int V_12 = F_5 ( ( * V_1 ) -> V_8 ) ;
free ( * V_1 ) ;
switch ( V_12 ) {
case 0 :
return 1 ;
case - 1 :
return 0 ;
default:
break;
}
}
V_5 = V_6 ;
return 0 ;
}
