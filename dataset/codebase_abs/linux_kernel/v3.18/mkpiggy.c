int main ( int V_1 , char * V_2 [] )
{
T_1 V_3 ;
long V_4 ;
unsigned long V_5 ;
unsigned long V_6 ;
T_2 * V_7 = NULL ;
int V_8 = 1 ;
if ( V_1 < 3 ) {
fprintf ( V_9 , L_1 ,
V_2 [ 0 ] ) ;
goto V_10;
}
V_7 = fopen ( V_2 [ 1 ] , L_2 ) ;
if ( ! V_7 ) {
perror ( V_2 [ 1 ] ) ;
goto V_10;
}
if ( fseek ( V_7 , - 4L , V_11 ) ) {
perror ( V_2 [ 1 ] ) ;
}
if ( fread ( & V_3 , sizeof( V_3 ) , 1 , V_7 ) != 1 ) {
perror ( V_2 [ 1 ] ) ;
goto V_10;
}
V_4 = ftell ( V_7 ) ;
V_3 = F_1 ( & V_3 ) ;
V_5 = ( V_3 > V_4 ) ? V_3 - V_4 : 0 ;
V_5 += V_3 >> 12 ;
V_5 += 64 * 1024 + 128 ;
V_5 = ( V_5 + 4095 ) & ~ 4095 ;
V_6 = atoi ( V_2 [ 2 ] ) ;
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
printf ( L_13 , V_6 ) ;
printf ( L_14 ) ;
printf ( L_15 ) ;
printf ( L_16 , V_2 [ 1 ] ) ;
printf ( L_17 ) ;
V_8 = 0 ;
V_10:
if ( V_7 )
fclose ( V_7 ) ;
return V_8 ;
}
