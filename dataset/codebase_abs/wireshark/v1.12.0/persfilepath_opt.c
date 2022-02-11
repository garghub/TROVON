T_1
F_1 ( int T_2 V_1 , const char * V_2 )
{
T_3 * V_3 , * V_4 ;
V_4 = strchr ( V_2 , ':' ) ;
if ( V_4 == NULL ) {
return FALSE ;
}
V_3 = V_4 ;
* V_3 ++ = '\0' ;
while ( isspace ( ( V_5 ) * V_3 ) )
V_3 ++ ;
if ( * V_3 == '\0' ) {
* V_4 = ':' ;
return FALSE ;
}
if( F_2 ( V_3 ) != V_6 ) {
* V_4 = ':' ;
return FALSE ;
}
if ( strcmp ( V_2 , L_1 ) == 0 ) {
F_3 ( V_3 ) ;
} else if ( strcmp ( V_2 , L_2 ) == 0 ) {
F_4 ( V_3 ) ;
} else {
return FALSE ;
}
* V_4 = ':' ;
return TRUE ;
}
