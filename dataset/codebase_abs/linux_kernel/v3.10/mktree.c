int main ( int V_1 , char * V_2 [] )
{
int V_3 , V_4 ;
int V_5 , V_6 ;
unsigned int V_7 , * V_8 ;
struct V_9 V_10 ;
T_1 V_11 ;
if ( V_1 < 5 ) {
fprintf ( V_12 , L_1 , V_2 [ 0 ] ) ;
exit ( 1 ) ;
}
if ( V_9 ( V_2 [ 1 ] , & V_10 ) < 0 ) {
perror ( L_2 ) ;
exit ( 2 ) ;
}
V_5 = ( V_10 . V_13 + V_14 ) / V_14 ;
V_11 . V_15 = F_1 ( 0x0052504F ) ;
V_11 . V_16 = F_1 ( strtoul ( V_2 [ 3 ] , NULL , 0 ) ) ;
V_11 . V_17 = F_1 ( strtoul ( V_2 [ 4 ] , NULL , 0 ) ) ;
V_11 . V_18 = F_1 ( V_5 ) ;
V_11 . V_19 = 0 ;
V_11 . V_20 = 0 ;
V_11 . V_21 [ 0 ] = 0 ;
V_11 . V_21 [ 1 ] = 0 ;
if ( ( V_3 = F_2 ( V_2 [ 1 ] , V_22 ) ) < 0 ) {
perror ( L_3 ) ;
exit ( 3 ) ;
}
if ( ( V_4 = F_2 ( V_2 [ 2 ] , ( V_23 | V_24 | V_25 ) , 0666 ) ) < 0 ) {
perror ( L_4 ) ;
exit ( 3 ) ;
}
V_7 = 0 ;
V_8 = ( void * ) & V_11 ;
for ( V_6 = 0 ; V_6 < sizeof( V_11 ) / sizeof( unsigned int ) ; V_6 ++ )
V_7 += * V_8 ++ ;
if ( F_3 ( V_3 , V_26 , sizeof( V_26 ) ) != sizeof( V_26 ) ) {
fprintf ( V_12 , L_5 ,
V_2 [ 1 ] ) ;
exit ( 4 ) ;
}
if ( V_26 [ 0 ] != F_1 ( 0x7f454c46 ) ) {
fprintf ( V_12 , L_6 , V_2 [ 1 ] ) ;
exit ( 4 ) ;
}
if ( F_4 ( V_3 , ( 64 * 1024 ) , V_27 ) < 0 ) {
fprintf ( V_12 , L_7 , V_2 [ 1 ] ) ;
exit ( 4 ) ;
}
V_5 -= ( 64 * 1024 ) / V_14 ;
if ( F_5 ( V_4 , & V_11 , sizeof( V_11 ) ) != sizeof( V_11 ) ) {
perror ( L_8 ) ;
exit ( 5 ) ;
}
while ( V_5 -- > 0 ) {
if ( F_3 ( V_3 , V_26 , sizeof( V_26 ) ) < 0 ) {
perror ( L_9 ) ;
exit ( 5 ) ;
}
V_8 = V_26 ;
for ( V_6 = 0 ; V_6 < sizeof( V_26 ) / sizeof( unsigned int ) ; V_6 ++ )
V_7 += * V_8 ++ ;
if ( F_5 ( V_4 , V_26 , sizeof( V_26 ) ) != sizeof( V_26 ) ) {
perror ( L_8 ) ;
exit ( 5 ) ;
}
}
V_11 . V_20 = F_1 ( V_7 ) ;
if ( F_4 ( V_4 , 0 , V_27 ) < 0 ) {
perror ( L_10 ) ;
exit ( 1 ) ;
}
if ( F_5 ( V_4 , & V_11 , sizeof( V_11 ) ) != sizeof( V_11 ) ) {
perror ( L_11 ) ;
exit ( 1 ) ;
}
exit ( 0 ) ;
}
