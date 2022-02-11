int main ( int V_1 , char * V_2 [] )
{
T_1 V_3 ;
long V_4 ;
unsigned long V_5 ;
T_2 * V_6 = NULL ;
int V_7 = 1 ;
if ( V_1 < 2 ) {
fprintf ( V_8 , L_1 , V_2 [ 0 ] ) ;
goto V_9;
}
V_6 = fopen ( V_2 [ 1 ] , L_2 ) ;
if ( ! V_6 ) {
perror ( V_2 [ 1 ] ) ;
goto V_9;
}
if ( fseek ( V_6 , - 4L , V_10 ) ) {
perror ( V_2 [ 1 ] ) ;
}
if ( fread ( & V_3 , sizeof( V_3 ) , 1 , V_6 ) != 1 ) {
perror ( V_2 [ 1 ] ) ;
goto V_9;
}
V_4 = ftell ( V_6 ) ;
V_3 = F_1 ( & V_3 ) ;
V_5 = ( V_3 > V_4 ) ? V_3 - V_4 : 0 ;
V_5 += V_3 >> 12 ;
V_5 += 64 * 1024 + 128 ;
V_5 = ( V_5 + 4095 ) & ~ 4095 ;
printf ( L_3 ) ;
printf ( L_4 ) ;
printf ( L_5 , V_4 ) ;
printf ( L_6 ) ;
printf ( L_7 , ( unsigned long ) V_3 ) ;
printf ( L_8 ) ;
printf ( L_9 , V_5 ) ;
printf ( L_10 ) ;
printf ( L_11 , V_5 ) ;
printf ( L_12 ) ;
printf ( L_13 ) ;
printf ( L_14 , V_2 [ 1 ] ) ;
printf ( L_15 ) ;
V_7 = 0 ;
V_9:
if ( V_6 )
fclose ( V_6 ) ;
return V_7 ;
}
