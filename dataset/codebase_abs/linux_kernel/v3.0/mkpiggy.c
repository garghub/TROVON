static T_1 F_1 ( const void * V_1 )
{
const T_2 * V_2 = V_1 ;
return ( T_1 ) V_2 [ 0 ] + ( ( T_1 ) V_2 [ 1 ] << 8 ) +
( ( T_1 ) V_2 [ 2 ] << 16 ) + ( ( T_1 ) V_2 [ 3 ] << 24 ) ;
}
int main ( int V_3 , char * V_4 [] )
{
T_1 V_5 ;
long V_6 ;
unsigned long V_7 ;
T_3 * V_8 ;
if ( V_3 < 2 ) {
fprintf ( V_9 , L_1 , V_4 [ 0 ] ) ;
return 1 ;
}
V_8 = fopen ( V_4 [ 1 ] , L_2 ) ;
if ( ! V_8 ) {
perror ( V_4 [ 1 ] ) ;
return 1 ;
}
if ( fseek ( V_8 , - 4L , V_10 ) ) {
perror ( V_4 [ 1 ] ) ;
}
if ( fread ( & V_5 , sizeof( V_5 ) , 1 , V_8 ) != 1 ) {
perror ( V_4 [ 1 ] ) ;
return 1 ;
}
V_6 = ftell ( V_8 ) ;
V_5 = F_1 ( & V_5 ) ;
fclose ( V_8 ) ;
V_7 = ( V_5 > V_6 ) ? V_5 - V_6 : 0 ;
V_7 += V_5 >> 12 ;
V_7 += 64 * 1024 + 128 ;
V_7 = ( V_7 + 4095 ) & ~ 4095 ;
printf ( L_3 ) ;
printf ( L_4 ) ;
printf ( L_5 , V_6 ) ;
printf ( L_6 ) ;
printf ( L_7 , ( unsigned long ) V_5 ) ;
printf ( L_8 ) ;
printf ( L_9 , V_7 ) ;
printf ( L_10 ) ;
printf ( L_11 , V_7 ) ;
printf ( L_12 ) ;
printf ( L_13 ) ;
printf ( L_14 , V_4 [ 1 ] ) ;
printf ( L_15 ) ;
return 0 ;
}
