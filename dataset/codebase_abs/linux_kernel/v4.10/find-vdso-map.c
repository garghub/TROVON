static int F_1 ( void * * V_1 , void * * V_2 )
{
T_1 * V_3 ;
char line [ 128 ] ;
int V_4 = 0 ;
V_3 = fopen ( L_1 , L_2 ) ;
if ( ! V_3 ) {
fprintf ( V_5 , L_3 ) ;
return - 1 ;
}
while ( ! V_4 && fgets ( line , sizeof( line ) , V_3 ) ) {
int V_6 = - 1 ;
if ( 2 != sscanf ( line , L_4 ,
V_1 , V_2 , & V_6 ) )
continue;
if ( V_6 < 0 )
continue;
if ( ! strncmp ( & line [ V_6 ] , V_7 ,
sizeof( V_7 ) - 1 ) )
V_4 = 1 ;
}
fclose ( V_3 ) ;
return ! V_4 ;
}
