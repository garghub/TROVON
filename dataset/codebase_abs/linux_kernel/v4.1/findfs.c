int F_1 ( const char * V_1 , long V_2 )
{
struct V_3 V_4 ;
if ( V_3 ( V_1 , & V_4 ) < 0 )
return - V_5 ;
else if ( ( long ) V_4 . V_6 != V_2 )
return - V_5 ;
return 0 ;
}
const char * F_2 ( const char * V_7 , long V_2 ,
char * V_8 , int V_9 ,
const char * const * V_10 )
{
const char * const * V_11 ;
char V_12 [ 128 ] ;
char type [ 100 ] ;
T_1 * V_13 ;
if ( V_10 ) {
V_11 = V_10 ;
while ( * V_11 ) {
if ( F_1 ( * V_11 , V_2 ) == 0 ) {
strncpy ( V_8 , * V_11 , V_9 - 1 ) ;
V_8 [ V_9 - 1 ] = 0 ;
return V_8 ;
}
V_11 ++ ;
}
}
V_13 = fopen ( L_1 , L_2 ) ;
if ( V_13 == NULL )
return NULL ;
snprintf ( V_12 , 128 , L_3 , V_9 ) ;
while ( fscanf ( V_13 , V_12 , V_8 , type ) == 2 ) {
if ( strcmp ( type , V_7 ) == 0 )
break;
}
fclose ( V_13 ) ;
if ( strcmp ( type , V_7 ) != 0 )
return NULL ;
return V_8 ;
}
