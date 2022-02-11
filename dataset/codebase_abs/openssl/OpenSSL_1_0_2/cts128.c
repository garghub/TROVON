T_1 F_1 ( const unsigned char * V_1 ,
unsigned char * V_2 , T_1 V_3 ,
const void * V_4 , unsigned char V_5 [ 16 ] ,
T_2 V_6 )
{
T_1 V_7 , V_8 ;
assert ( V_1 && V_2 && V_4 && V_5 ) ;
if ( V_3 <= 16 )
return 0 ;
if ( ( V_7 = V_3 % 16 ) == 0 )
V_7 = 16 ;
V_3 -= V_7 ;
F_2 ( V_1 , V_2 , V_3 , V_4 , V_5 , V_6 ) ;
V_1 += V_3 ;
V_2 += V_3 ;
for ( V_8 = 0 ; V_8 < V_7 ; ++ V_8 )
V_5 [ V_8 ] ^= V_1 [ V_8 ] ;
(* V_6) ( V_5 , V_5 , V_4 ) ;
memcpy ( V_2 , V_2 - 16 , V_7 ) ;
memcpy ( V_2 - 16 , V_5 , 16 ) ;
return V_3 + V_7 ;
}
T_1 F_3 ( const unsigned char * V_1 ,
unsigned char * V_2 , T_1 V_3 ,
const void * V_4 ,
unsigned char V_5 [ 16 ] ,
T_2 V_6 )
{
T_1 V_7 , V_8 ;
assert ( V_1 && V_2 && V_4 && V_5 ) ;
if ( V_3 < 16 )
return 0 ;
V_7 = V_3 % 16 ;
V_3 -= V_7 ;
F_2 ( V_1 , V_2 , V_3 , V_4 , V_5 , V_6 ) ;
if ( V_7 == 0 )
return V_3 ;
V_1 += V_3 ;
V_2 += V_3 ;
for ( V_8 = 0 ; V_8 < V_7 ; ++ V_8 )
V_5 [ V_8 ] ^= V_1 [ V_8 ] ;
(* V_6) ( V_5 , V_5 , V_4 ) ;
memcpy ( V_2 - 16 + V_7 , V_5 , 16 ) ;
return V_3 + V_7 ;
}
T_1 F_4 ( const unsigned char * V_1 , unsigned char * V_2 ,
T_1 V_3 , const void * V_4 ,
unsigned char V_5 [ 16 ] , T_3 V_9 )
{
T_1 V_7 ;
union {
T_1 V_10 ;
unsigned char V_11 [ 16 ] ;
} V_12 ;
assert ( V_1 && V_2 && V_4 && V_5 ) ;
if ( V_3 <= 16 )
return 0 ;
if ( ( V_7 = V_3 % 16 ) == 0 )
V_7 = 16 ;
V_3 -= V_7 ;
(* V_9) ( V_1 , V_2 , V_3 , V_4 , V_5 , 1 ) ;
V_1 += V_3 ;
V_2 += V_3 ;
#if F_5 ( V_13 )
memcpy ( V_12 . V_11 , V_2 - 16 , 16 ) ;
(* V_9) ( V_1 , V_2 - 16 , V_7 , V_4 , V_5 , 1 ) ;
memcpy ( V_2 , V_12 . V_11 , V_7 ) ;
#else
memset ( V_12 . V_11 , 0 , sizeof( V_12 ) ) ;
memcpy ( V_12 . V_11 , V_1 , V_7 ) ;
memcpy ( V_2 , V_2 - 16 , V_7 ) ;
(* V_9) ( V_12 . V_11 , V_2 - 16 , 16 , V_4 , V_5 , 1 ) ;
#endif
return V_3 + V_7 ;
}
T_1 F_6 ( const unsigned char * V_1 , unsigned char * V_2 ,
T_1 V_3 , const void * V_4 ,
unsigned char V_5 [ 16 ] , T_3 V_9 )
{
T_1 V_7 ;
union {
T_1 V_10 ;
unsigned char V_11 [ 16 ] ;
} V_12 ;
assert ( V_1 && V_2 && V_4 && V_5 ) ;
if ( V_3 < 16 )
return 0 ;
V_7 = V_3 % 16 ;
V_3 -= V_7 ;
(* V_9) ( V_1 , V_2 , V_3 , V_4 , V_5 , 1 ) ;
if ( V_7 == 0 )
return V_3 ;
V_1 += V_3 ;
V_2 += V_3 ;
#if F_5 ( V_13 )
(* V_9) ( V_1 , V_2 - 16 + V_7 , V_7 , V_4 , V_5 , 1 ) ;
#else
memset ( V_12 . V_11 , 0 , sizeof( V_12 ) ) ;
memcpy ( V_12 . V_11 , V_1 , V_7 ) ;
(* V_9) ( V_12 . V_11 , V_2 - 16 + V_7 , 16 , V_4 , V_5 , 1 ) ;
#endif
return V_3 + V_7 ;
}
T_1 F_7 ( const unsigned char * V_1 ,
unsigned char * V_2 , T_1 V_3 ,
const void * V_4 , unsigned char V_5 [ 16 ] ,
T_2 V_6 )
{
T_1 V_7 , V_8 ;
union {
T_1 V_10 ;
unsigned char V_11 [ 32 ] ;
} V_12 ;
assert ( V_1 && V_2 && V_4 && V_5 ) ;
if ( V_3 <= 16 )
return 0 ;
if ( ( V_7 = V_3 % 16 ) == 0 )
V_7 = 16 ;
V_3 -= 16 + V_7 ;
if ( V_3 ) {
F_8 ( V_1 , V_2 , V_3 , V_4 , V_5 , V_6 ) ;
V_1 += V_3 ;
V_2 += V_3 ;
}
(* V_6) ( V_1 , V_12 . V_11 + 16 , V_4 ) ;
memcpy ( V_12 . V_11 , V_12 . V_11 + 16 , 16 ) ;
memcpy ( V_12 . V_11 , V_1 + 16 , V_7 ) ;
(* V_6) ( V_12 . V_11 , V_12 . V_11 , V_4 ) ;
for ( V_8 = 0 ; V_8 < 16 ; ++ V_8 ) {
unsigned char V_11 = V_1 [ V_8 ] ;
V_2 [ V_8 ] = V_12 . V_11 [ V_8 ] ^ V_5 [ V_8 ] ;
V_5 [ V_8 ] = V_11 ;
}
for ( V_7 += 16 ; V_8 < V_7 ; ++ V_8 )
V_2 [ V_8 ] = V_12 . V_11 [ V_8 ] ^ V_1 [ V_8 ] ;
return 16 + V_3 + V_7 ;
}
T_1 F_9 ( const unsigned char * V_1 ,
unsigned char * V_2 , T_1 V_3 ,
const void * V_4 ,
unsigned char V_5 [ 16 ] ,
T_2 V_6 )
{
T_1 V_7 , V_8 ;
union {
T_1 V_10 ;
unsigned char V_11 [ 32 ] ;
} V_12 ;
assert ( V_1 && V_2 && V_4 && V_5 ) ;
if ( V_3 < 16 )
return 0 ;
V_7 = V_3 % 16 ;
if ( V_7 == 0 ) {
F_8 ( V_1 , V_2 , V_3 , V_4 , V_5 , V_6 ) ;
return V_3 ;
}
V_3 -= 16 + V_7 ;
if ( V_3 ) {
F_8 ( V_1 , V_2 , V_3 , V_4 , V_5 , V_6 ) ;
V_1 += V_3 ;
V_2 += V_3 ;
}
(* V_6) ( V_1 + V_7 , V_12 . V_11 + 16 , V_4 ) ;
memcpy ( V_12 . V_11 , V_12 . V_11 + 16 , 16 ) ;
memcpy ( V_12 . V_11 , V_1 , V_7 ) ;
(* V_6) ( V_12 . V_11 , V_12 . V_11 , V_4 ) ;
for ( V_8 = 0 ; V_8 < 16 ; ++ V_8 ) {
unsigned char V_11 = V_1 [ V_8 ] ;
V_2 [ V_8 ] = V_12 . V_11 [ V_8 ] ^ V_5 [ V_8 ] ;
V_5 [ V_8 ] = V_1 [ V_8 + V_7 ] ;
V_12 . V_11 [ V_8 ] = V_11 ;
}
for ( V_7 += 16 ; V_8 < V_7 ; ++ V_8 )
V_2 [ V_8 ] = V_12 . V_11 [ V_8 ] ^ V_12 . V_11 [ V_8 - 16 ] ;
return 16 + V_3 + V_7 ;
}
T_1 F_10 ( const unsigned char * V_1 , unsigned char * V_2 ,
T_1 V_3 , const void * V_4 ,
unsigned char V_5 [ 16 ] , T_3 V_9 )
{
T_1 V_7 ;
union {
T_1 V_10 ;
unsigned char V_11 [ 32 ] ;
} V_12 ;
assert ( V_1 && V_2 && V_4 && V_5 ) ;
if ( V_3 <= 16 )
return 0 ;
if ( ( V_7 = V_3 % 16 ) == 0 )
V_7 = 16 ;
V_3 -= 16 + V_7 ;
if ( V_3 ) {
(* V_9) ( V_1 , V_2 , V_3 , V_4 , V_5 , 0 ) ;
V_1 += V_3 ;
V_2 += V_3 ;
}
memset ( V_12 . V_11 , 0 , sizeof( V_12 ) ) ;
(* V_9) ( V_1 , V_12 . V_11 , 16 , V_4 , V_12 . V_11 + 16 , 0 ) ;
memcpy ( V_12 . V_11 , V_1 + 16 , V_7 ) ;
#if F_5 ( V_13 )
(* V_9) ( V_12 . V_11 , V_2 , 16 + V_7 , V_4 , V_5 , 0 ) ;
#else
(* V_9) ( V_12 . V_11 , V_12 . V_11 , 32 , V_4 , V_5 , 0 ) ;
memcpy ( V_2 , V_12 . V_11 , 16 + V_7 ) ;
#endif
return 16 + V_3 + V_7 ;
}
T_1 F_11 ( const unsigned char * V_1 , unsigned char * V_2 ,
T_1 V_3 , const void * V_4 ,
unsigned char V_5 [ 16 ] , T_3 V_9 )
{
T_1 V_7 ;
union {
T_1 V_10 ;
unsigned char V_11 [ 32 ] ;
} V_12 ;
assert ( V_1 && V_2 && V_4 && V_5 ) ;
if ( V_3 < 16 )
return 0 ;
V_7 = V_3 % 16 ;
if ( V_7 == 0 ) {
(* V_9) ( V_1 , V_2 , V_3 , V_4 , V_5 , 0 ) ;
return V_3 ;
}
V_3 -= 16 + V_7 ;
if ( V_3 ) {
(* V_9) ( V_1 , V_2 , V_3 , V_4 , V_5 , 0 ) ;
V_1 += V_3 ;
V_2 += V_3 ;
}
memset ( V_12 . V_11 , 0 , sizeof( V_12 ) ) ;
(* V_9) ( V_1 + V_7 , V_12 . V_11 , 16 , V_4 , V_12 . V_11 + 16 , 0 ) ;
memcpy ( V_12 . V_11 , V_1 , V_7 ) ;
#if F_5 ( V_13 )
(* V_9) ( V_12 . V_11 , V_2 , 16 + V_7 , V_4 , V_5 , 0 ) ;
#else
(* V_9) ( V_12 . V_11 , V_12 . V_11 , 32 , V_4 , V_5 , 0 ) ;
memcpy ( V_2 , V_12 . V_11 , 16 + V_7 ) ;
#endif
return 16 + V_3 + V_7 ;
}
void F_12 ( const unsigned char * V_14 , T_1 V_3 )
{
unsigned char V_15 [ sizeof( V_16 ) ] ;
unsigned char V_17 [ 64 ] , V_18 [ 64 ] ;
T_1 V_19 ;
printf ( L_1 , V_3 ) ;
fflush ( stdout ) ;
if ( ( V_19 = V_3 % 16 ) == 0 )
V_19 = 16 ;
V_19 += 16 ;
memcpy ( V_15 , V_16 , sizeof( V_16 ) ) ;
F_1 ( V_20 , V_18 , V_3 , & V_21 , V_15 ,
( T_2 ) V_22 ) ;
if ( memcmp ( V_18 , V_14 , V_3 ) )
fprintf ( V_23 , L_2 , V_3 ) , exit ( 1 ) ;
if ( memcmp ( V_15 , V_14 + V_3 - V_19 , sizeof( V_15 ) ) )
fprintf ( V_23 , L_3 , V_3 ) , exit ( 1 ) ;
memcpy ( V_15 , V_16 , sizeof( V_16 ) ) ;
F_7 ( V_18 , V_17 , V_3 , & V_24 , V_15 ,
( T_2 ) V_25 ) ;
if ( memcmp ( V_17 , V_20 , V_3 ) )
fprintf ( V_23 , L_4 , V_3 ) , exit ( 2 ) ;
if ( memcmp ( V_15 , V_14 + V_3 - V_19 , sizeof( V_15 ) ) )
fprintf ( V_23 , L_3 , V_3 ) , exit ( 2 ) ;
memcpy ( V_15 , V_16 , sizeof( V_16 ) ) ;
F_4 ( V_20 , V_18 , V_3 , & V_21 , V_15 ,
( T_3 ) V_26 ) ;
if ( memcmp ( V_18 , V_14 , V_3 ) )
fprintf ( V_23 , L_2 , V_3 ) , exit ( 3 ) ;
if ( memcmp ( V_15 , V_14 + V_3 - V_19 , sizeof( V_15 ) ) )
fprintf ( V_23 , L_3 , V_3 ) , exit ( 3 ) ;
memcpy ( V_15 , V_16 , sizeof( V_16 ) ) ;
F_10 ( V_18 , V_17 , V_3 , & V_24 , V_15 ,
( T_3 ) V_26 ) ;
if ( memcmp ( V_17 , V_20 , V_3 ) )
fprintf ( V_23 , L_4 , V_3 ) , exit ( 4 ) ;
if ( memcmp ( V_15 , V_14 + V_3 - V_19 , sizeof( V_15 ) ) )
fprintf ( V_23 , L_3 , V_3 ) , exit ( 4 ) ;
}
void F_13 ( const unsigned char * V_14 , T_1 V_3 )
{
unsigned char V_15 [ sizeof( V_16 ) ] ;
unsigned char V_17 [ 64 ] , V_18 [ 64 ] , V_27 [ 64 ] ;
T_1 V_19 ;
printf ( L_5 , V_3 ) ;
fflush ( stdout ) ;
if ( ( V_19 = V_3 % 16 ) == 0 )
V_19 = 16 ;
V_3 -= 16 + V_19 ;
memcpy ( V_27 , V_14 , V_3 ) ;
memcpy ( V_27 + V_3 , V_14 + V_3 + 16 , V_19 ) ;
memcpy ( V_27 + V_3 + V_19 , V_14 + V_3 , 16 ) ;
V_3 += 16 + V_19 ;
V_19 = 16 ;
memcpy ( V_15 , V_16 , sizeof( V_16 ) ) ;
F_3 ( V_20 , V_18 , V_3 , & V_21 , V_15 ,
( T_2 ) V_22 ) ;
if ( memcmp ( V_18 , V_27 , V_3 ) )
fprintf ( V_23 , L_2 , V_3 ) , exit ( 1 ) ;
if ( memcmp ( V_15 , V_27 + V_3 - V_19 , sizeof( V_15 ) ) )
fprintf ( V_23 , L_3 , V_3 ) , exit ( 1 ) ;
memcpy ( V_15 , V_16 , sizeof( V_16 ) ) ;
F_9 ( V_18 , V_17 , V_3 , & V_24 , V_15 ,
( T_2 ) V_25 ) ;
if ( memcmp ( V_17 , V_20 , V_3 ) )
fprintf ( V_23 , L_4 , V_3 ) , exit ( 2 ) ;
if ( memcmp ( V_15 , V_27 + V_3 - V_19 , sizeof( V_15 ) ) )
fprintf ( V_23 , L_3 , V_3 ) , exit ( 2 ) ;
memcpy ( V_15 , V_16 , sizeof( V_16 ) ) ;
F_6 ( V_20 , V_18 , V_3 , & V_21 , V_15 ,
( T_3 ) V_26 ) ;
if ( memcmp ( V_18 , V_27 , V_3 ) )
fprintf ( V_23 , L_2 , V_3 ) , exit ( 3 ) ;
if ( memcmp ( V_15 , V_27 + V_3 - V_19 , sizeof( V_15 ) ) )
fprintf ( V_23 , L_3 , V_3 ) , exit ( 3 ) ;
memcpy ( V_15 , V_16 , sizeof( V_16 ) ) ;
F_11 ( V_18 , V_17 , V_3 , & V_24 , V_15 ,
( T_3 ) V_26 ) ;
if ( memcmp ( V_17 , V_20 , V_3 ) )
fprintf ( V_23 , L_4 , V_3 ) , exit ( 4 ) ;
if ( memcmp ( V_15 , V_27 + V_3 - V_19 , sizeof( V_15 ) ) )
fprintf ( V_23 , L_3 , V_3 ) , exit ( 4 ) ;
}
int main ()
{
F_14 ( V_28 , 128 , & V_21 ) ;
F_15 ( V_28 , 128 , & V_24 ) ;
F_12 ( V_29 , sizeof( V_29 ) ) ;
F_12 ( V_30 , sizeof( V_30 ) ) ;
F_12 ( V_31 , sizeof( V_31 ) ) ;
F_12 ( V_32 , sizeof( V_32 ) ) ;
F_12 ( V_33 , sizeof( V_33 ) ) ;
F_12 ( V_34 , sizeof( V_34 ) ) ;
F_13 ( V_29 , sizeof( V_29 ) ) ;
F_13 ( V_30 , sizeof( V_30 ) ) ;
F_13 ( V_31 , sizeof( V_31 ) ) ;
F_13 ( V_32 , sizeof( V_32 ) ) ;
F_13 ( V_33 , sizeof( V_33 ) ) ;
F_13 ( V_34 , sizeof( V_34 ) ) ;
return 0 ;
}
