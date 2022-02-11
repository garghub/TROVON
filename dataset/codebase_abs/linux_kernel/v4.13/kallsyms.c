T_1 F_1 ( char type )
{
type = tolower ( type ) ;
return ( type == 't' || type == 'w' ) ? V_1 : V_2 ;
}
int F_2 ( const char * V_3 , void * V_4 ,
int (* F_3)( void * V_4 , const char * V_5 ,
char type , T_2 V_6 ) )
{
char * line = NULL ;
T_3 V_7 ;
int V_8 = - 1 ;
T_4 * V_9 = fopen ( V_3 , L_1 ) ;
if ( V_9 == NULL )
goto V_10;
V_8 = 0 ;
while ( ! feof ( V_9 ) ) {
T_2 V_6 ;
int V_11 , V_12 ;
char V_13 ;
char * V_14 ;
V_11 = F_4 ( & line , & V_7 , V_9 ) ;
if ( V_11 < 0 || ! line )
break;
line [ -- V_11 ] = '\0' ;
V_12 = F_5 ( line , & V_6 ) ;
V_12 ++ ;
if ( V_12 + 2 >= V_11 )
continue;
V_13 = line [ V_12 ] ;
V_12 += 2 ;
V_14 = line + V_12 ;
V_12 = V_11 - V_12 ;
if ( V_12 >= V_15 ) {
V_8 = - 1 ;
break;
}
V_8 = F_3 ( V_4 , V_14 , V_13 , V_6 ) ;
if ( V_8 )
break;
}
free ( line ) ;
fclose ( V_9 ) ;
return V_8 ;
V_10:
return - 1 ;
}
