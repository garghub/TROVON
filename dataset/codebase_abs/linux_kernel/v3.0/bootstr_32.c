char * T_1
F_1 ( void )
{
int V_1 ;
char * V_2 , * V_3 ;
if ( V_4 ) {
return V_5 ;
}
switch( V_6 ) {
case V_7 :
V_2 = V_5 ;
for( V_1 = 1 ; V_1 < 8 ; V_1 ++ ) {
V_3 = ( * ( V_8 -> V_9 ) ) -> V_10 [ V_1 ] ;
if ( V_3 == NULL )
break;
while( * V_3 != 0 ) {
if( V_2 >= V_5 + V_11 - 2 ) {
break;
}
* V_2 ++ = * V_3 ++ ;
}
* V_2 ++ = ' ' ;
}
* V_2 = 0 ;
break;
case V_12 :
case V_13 :
F_2 ( V_5 , * V_8 -> V_14 . V_15 , sizeof( V_5 ) ) ;
break;
default:
break;
}
V_4 = 1 ;
return V_5 ;
}
