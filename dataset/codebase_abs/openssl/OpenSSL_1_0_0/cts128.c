T_1 F_1 ( const unsigned char * V_1 , unsigned char * V_2 ,
T_1 V_3 , const void * V_4 ,
unsigned char V_5 [ 16 ] , T_2 V_6 )
{ T_1 V_7 , V_8 ;
assert ( V_1 && V_2 && V_4 && V_5 ) ;
if ( V_3 <= 16 ) return 0 ;
if ( ( V_7 = V_3 % 16 ) == 0 ) V_7 = 16 ;
V_3 -= V_7 ;
F_2 ( V_1 , V_2 , V_3 , V_4 , V_5 , V_6 ) ;
V_1 += V_3 ;
V_2 += V_3 ;
for ( V_8 = 0 ; V_8 < V_7 ; ++ V_8 )
V_5 [ V_8 ] ^= V_1 [ V_8 ] ;
(* V_6)( V_5 , V_5 , V_4 ) ;
memcpy ( V_2 , V_2 - 16 , V_7 ) ;
memcpy ( V_2 - 16 , V_5 , 16 ) ;
return V_3 + V_7 ;
}
T_1 F_3 ( const unsigned char * V_1 , unsigned char * V_2 ,
T_1 V_3 , const void * V_4 ,
unsigned char V_5 [ 16 ] , T_3 V_9 )
{ T_1 V_7 ;
union { T_1 V_10 ; unsigned char V_11 [ 16 ] ; } V_12 ;
assert ( V_1 && V_2 && V_4 && V_5 ) ;
if ( V_3 <= 16 ) return 0 ;
if ( ( V_7 = V_3 % 16 ) == 0 ) V_7 = 16 ;
V_3 -= V_7 ;
(* V_9)( V_1 , V_2 , V_3 , V_4 , V_5 , 1 ) ;
V_1 += V_3 ;
V_2 += V_3 ;
#if F_4 ( V_13 )
memcpy ( V_12 . V_11 , V_2 - 16 , 16 ) ;
(* V_9)( V_1 , V_2 - 16 , V_7 , V_4 , V_5 , 1 ) ;
memcpy ( V_2 , V_12 . V_11 , V_7 ) ;
#else
{
T_1 V_8 ;
for ( V_8 = 0 ; V_8 < 16 ; V_8 += sizeof( T_1 ) )
* ( T_1 * ) ( V_12 . V_11 + V_8 ) = 0 ;
memcpy ( V_12 . V_11 , V_1 , V_7 ) ;
}
memcpy ( V_2 , V_2 - 16 , V_7 ) ;
(* V_9)( V_12 . V_11 , V_2 - 16 , 16 , V_4 , V_5 , 1 ) ;
#endif
return V_3 + V_7 ;
}
T_1 F_5 ( const unsigned char * V_1 , unsigned char * V_2 ,
T_1 V_3 , const void * V_4 ,
unsigned char V_5 [ 16 ] , T_2 V_6 )
{ T_1 V_7 , V_8 ;
union { T_1 V_10 ; unsigned char V_11 [ 32 ] ; } V_12 ;
assert ( V_1 && V_2 && V_4 && V_5 ) ;
if ( V_3 <= 16 ) return 0 ;
if ( ( V_7 = V_3 % 16 ) == 0 ) V_7 = 16 ;
V_3 -= 16 + V_7 ;
if ( V_3 ) {
F_6 ( V_1 , V_2 , V_3 , V_4 , V_5 , V_6 ) ;
V_1 += V_3 ;
V_2 += V_3 ;
}
(* V_6)( V_1 , V_12 . V_11 + 16 , V_4 ) ;
for ( V_8 = 0 ; V_8 < 16 ; V_8 += sizeof( T_1 ) )
* ( T_1 * ) ( V_12 . V_11 + V_8 ) = * ( T_1 * ) ( V_12 . V_11 + 16 + V_8 ) ;
memcpy ( V_12 . V_11 , V_1 + 16 , V_7 ) ;
(* V_6)( V_12 . V_11 , V_12 . V_11 , V_4 ) ;
for( V_8 = 0 ; V_8 < 16 ; ++ V_8 ) {
unsigned char V_11 = V_1 [ V_8 ] ;
V_2 [ V_8 ] = V_12 . V_11 [ V_8 ] ^ V_5 [ V_8 ] ;
V_5 [ V_8 ] = V_11 ;
}
for( V_7 += 16 ; V_8 < V_7 ; ++ V_8 )
V_2 [ V_8 ] = V_12 . V_11 [ V_8 ] ^ V_1 [ V_8 ] ;
return V_3 + V_7 - 16 ;
}
T_1 F_7 ( const unsigned char * V_1 , unsigned char * V_2 ,
T_1 V_3 , const void * V_4 ,
unsigned char V_5 [ 16 ] , T_3 V_9 )
{ T_1 V_7 , V_8 ;
union { T_1 V_10 ; unsigned char V_11 [ 32 ] ; } V_12 ;
assert ( V_1 && V_2 && V_4 && V_5 ) ;
if ( V_3 <= 16 ) return 0 ;
if ( ( V_7 = V_3 % 16 ) == 0 ) V_7 = 16 ;
V_3 -= 16 + V_7 ;
if ( V_3 ) {
(* V_9)( V_1 , V_2 , V_3 , V_4 , V_5 , 0 ) ;
V_1 += V_3 ;
V_2 += V_3 ;
}
for ( V_8 = 16 ; V_8 < 32 ; V_8 += sizeof( T_1 ) )
* ( T_1 * ) ( V_12 . V_11 + V_8 ) = 0 ;
(* V_9)( V_1 , V_12 . V_11 , 16 , V_4 , V_12 . V_11 + 16 , 0 ) ;
memcpy ( V_12 . V_11 , V_1 + 16 , V_7 ) ;
#if F_4 ( V_13 )
(* V_9)( V_12 . V_11 , V_2 , 16 + V_7 , V_4 , V_5 , 0 ) ;
#else
(* V_9)( V_12 . V_11 , V_12 . V_11 , 32 , V_4 , V_5 , 0 ) ;
memcpy ( V_2 , V_12 . V_11 , 16 + V_7 ) ;
#endif
return V_3 + V_7 ;
}
void F_8 ( const unsigned char * V_14 , T_1 V_3 )
{ unsigned char V_15 [ 64 ] ;
unsigned char V_16 [ sizeof( V_17 ) ] ;
unsigned char V_18 [ 64 ] ;
T_1 V_19 ;
printf ( L_1 , V_3 ) ; fflush ( stdout ) ;
if ( ( V_19 = V_3 % 16 ) == 0 ) V_19 = 16 ;
V_19 += 16 ;
memcpy ( V_16 , V_17 , sizeof( V_17 ) ) ;
F_1 ( V_20 , V_18 , V_3 , & V_21 , V_16 , ( T_2 ) V_22 ) ;
if ( memcmp ( V_18 , V_14 , V_3 ) )
fprintf ( V_23 , L_2 , V_3 ) , exit ( 1 ) ;
if ( memcmp ( V_16 , V_14 + V_3 - V_19 , sizeof( V_16 ) ) )
fprintf ( V_23 , L_3 , V_3 ) , exit ( 1 ) ;
memcpy ( V_16 , V_17 , sizeof( V_17 ) ) ;
F_5 ( V_18 , V_15 , V_3 , & V_24 , V_16 , ( T_2 ) V_25 ) ;
if ( memcmp ( V_15 , V_20 , V_3 ) )
fprintf ( V_23 , L_4 , V_3 ) , exit ( 2 ) ;
if ( memcmp ( V_16 , V_14 + V_3 - V_19 , sizeof( V_16 ) ) )
fprintf ( V_23 , L_3 , V_3 ) , exit ( 2 ) ;
memcpy ( V_16 , V_17 , sizeof( V_17 ) ) ;
F_3 ( V_20 , V_18 , V_3 , & V_21 , V_16 , ( T_3 ) V_26 ) ;
if ( memcmp ( V_18 , V_14 , V_3 ) )
fprintf ( V_23 , L_2 , V_3 ) , exit ( 3 ) ;
if ( memcmp ( V_16 , V_14 + V_3 - V_19 , sizeof( V_16 ) ) )
fprintf ( V_23 , L_3 , V_3 ) , exit ( 3 ) ;
memcpy ( V_16 , V_17 , sizeof( V_17 ) ) ;
F_7 ( V_18 , V_15 , V_3 , & V_24 , V_16 , ( T_3 ) V_26 ) ;
if ( memcmp ( V_15 , V_20 , V_3 ) )
fprintf ( V_23 , L_4 , V_3 ) , exit ( 4 ) ;
if ( memcmp ( V_16 , V_14 + V_3 - V_19 , sizeof( V_16 ) ) )
fprintf ( V_23 , L_3 , V_3 ) , exit ( 4 ) ;
}
main ()
{
F_9 ( V_27 , 128 , & V_21 ) ;
F_10 ( V_27 , 128 , & V_24 ) ;
F_8 ( V_28 , sizeof( V_28 ) ) ;
F_8 ( V_29 , sizeof( V_29 ) ) ;
F_8 ( V_30 , sizeof( V_30 ) ) ;
F_8 ( V_31 , sizeof( V_31 ) ) ;
F_8 ( V_32 , sizeof( V_32 ) ) ;
F_8 ( V_33 , sizeof( V_33 ) ) ;
exit ( 0 ) ;
}
