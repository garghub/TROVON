int main ( int V_1 , char * V_2 [] )
{
T_1 V_3 ;
long V_4 ;
T_2 * V_5 = NULL ;
int V_6 = 1 ;
if ( V_1 < 2 ) {
fprintf ( V_7 , L_1 , V_2 [ 0 ] ) ;
goto V_8;
}
V_5 = fopen ( V_2 [ 1 ] , L_2 ) ;
if ( ! V_5 ) {
perror ( V_2 [ 1 ] ) ;
goto V_8;
}
if ( fseek ( V_5 , - 4L , V_9 ) ) {
perror ( V_2 [ 1 ] ) ;
}
if ( fread ( & V_3 , sizeof( V_3 ) , 1 , V_5 ) != 1 ) {
perror ( V_2 [ 1 ] ) ;
goto V_8;
}
V_4 = ftell ( V_5 ) ;
V_3 = F_1 ( & V_3 ) ;
printf ( L_3 ) ;
printf ( L_4 ) ;
printf ( L_5 , V_4 ) ;
printf ( L_6 ) ;
printf ( L_7 , ( unsigned long ) V_3 ) ;
printf ( L_8 ) ;
printf ( L_9 ) ;
printf ( L_10 , V_2 [ 1 ] ) ;
printf ( L_11 ) ;
V_6 = 0 ;
V_8:
if ( V_5 )
fclose ( V_5 ) ;
return V_6 ;
}
