static T_1 void F_1 ( T_2 * V_1 )
{
V_1 -> V_2 [ 0 ] = - 1 ;
}
static T_1 void F_2 ( T_2 * V_1 )
{
int V_3 ;
memset ( V_1 , 0 , sizeof( T_2 ) ) ;
for ( V_3 = 0 ; V_3 < 8 ; ++ V_3 ) {
V_1 -> V_4 [ V_3 ] = V_5 [ V_3 ] ;
}
}
static void F_3 ( T_2 * V_1 , const T_3 * V_6 )
{
T_4 V_3 ;
const T_5 * V_7 = ( const T_5 * ) ( V_6 ) ;
F_2 ( V_1 ) ;
assert ( sizeof( T_3 ) == 64 ) ;
for ( V_3 = 0 ; V_3 < 8 ; ++ V_3 ) {
V_1 -> V_4 [ V_3 ] ^= F_4 ( V_7 + sizeof( V_1 -> V_4 [ V_3 ] ) * V_3 ) ;
}
}
int F_5 ( T_2 * V_8 )
{
T_3 V_6 [ 1 ] ;
V_6 -> V_9 = V_10 ;
V_6 -> V_11 = 0 ;
V_6 -> V_12 = 1 ;
V_6 -> V_13 = 1 ;
F_6 ( V_6 -> V_14 , 0 ) ;
F_7 ( V_6 -> V_15 , 0 ) ;
V_6 -> V_16 = 0 ;
V_6 -> V_17 = 0 ;
memset ( V_6 -> V_18 , 0 , sizeof( V_6 -> V_18 ) ) ;
memset ( V_6 -> V_19 , 0 , sizeof( V_6 -> V_19 ) ) ;
memset ( V_6 -> V_20 , 0 , sizeof( V_6 -> V_20 ) ) ;
F_3 ( V_8 , V_6 ) ;
return 1 ;
}
static void F_8 ( T_2 * V_1 ,
const T_5 * V_21 ,
T_4 V_22 )
{
T_6 V_23 [ 16 ] ;
T_6 V_24 [ 16 ] ;
int V_3 ;
T_4 V_25 ;
assert ( V_22 < V_26 || V_22 % V_26 == 0 ) ;
V_25 = V_22 < V_26 ? V_22 : V_26 ;
for ( V_3 = 0 ; V_3 < 8 ; ++ V_3 ) {
V_24 [ V_3 ] = V_1 -> V_4 [ V_3 ] ;
}
do {
for ( V_3 = 0 ; V_3 < 16 ; ++ V_3 ) {
V_23 [ V_3 ] = F_4 ( V_21 + V_3 * sizeof( V_23 [ V_3 ] ) ) ;
}
V_1 -> V_27 [ 0 ] += V_25 ;
V_1 -> V_27 [ 1 ] += ( V_1 -> V_27 [ 0 ] < V_25 ) ;
V_24 [ 8 ] = V_5 [ 0 ] ;
V_24 [ 9 ] = V_5 [ 1 ] ;
V_24 [ 10 ] = V_5 [ 2 ] ;
V_24 [ 11 ] = V_5 [ 3 ] ;
V_24 [ 12 ] = V_1 -> V_27 [ 0 ] ^ V_5 [ 4 ] ;
V_24 [ 13 ] = V_1 -> V_27 [ 1 ] ^ V_5 [ 5 ] ;
V_24 [ 14 ] = V_1 -> V_2 [ 0 ] ^ V_5 [ 6 ] ;
V_24 [ 15 ] = V_1 -> V_2 [ 1 ] ^ V_5 [ 7 ] ;
#define F_9 ( T_7 , V_3 , T_8 , T_9 , V_8 , T_10 ) \
do { \
a = a + b + m[blake2b_sigma[r][2*i+0]]; \
d = rotr64(d ^ a, 32); \
c = c + d; \
b = rotr64(b ^ c, 24); \
a = a + b + m[blake2b_sigma[r][2*i+1]]; \
d = rotr64(d ^ a, 16); \
c = c + d; \
b = rotr64(b ^ c, 63); \
} while (0)
#define F_10 ( T_7 ) \
do { \
G(r,0,v[ 0],v[ 4],v[ 8],v[12]); \
G(r,1,v[ 1],v[ 5],v[ 9],v[13]); \
G(r,2,v[ 2],v[ 6],v[10],v[14]); \
G(r,3,v[ 3],v[ 7],v[11],v[15]); \
G(r,4,v[ 0],v[ 5],v[10],v[15]); \
G(r,5,v[ 1],v[ 6],v[11],v[12]); \
G(r,6,v[ 2],v[ 7],v[ 8],v[13]); \
G(r,7,v[ 3],v[ 4],v[ 9],v[14]); \
} while (0)
#if F_11 ( V_28 )
for ( V_3 = 0 ; V_3 < 12 ; V_3 ++ ) {
F_10 ( V_3 ) ;
}
#else
F_10 ( 0 ) ;
F_10 ( 1 ) ;
F_10 ( 2 ) ;
F_10 ( 3 ) ;
F_10 ( 4 ) ;
F_10 ( 5 ) ;
F_10 ( 6 ) ;
F_10 ( 7 ) ;
F_10 ( 8 ) ;
F_10 ( 9 ) ;
F_10 ( 10 ) ;
F_10 ( 11 ) ;
#endif
for ( V_3 = 0 ; V_3 < 8 ; ++ V_3 ) {
V_1 -> V_4 [ V_3 ] = V_24 [ V_3 ] ^= V_24 [ V_3 + 8 ] ^ V_1 -> V_4 [ V_3 ] ;
}
#undef F_9
#undef F_10
V_21 += V_25 ;
V_22 -= V_25 ;
} while ( V_22 );
}
int F_12 ( T_2 * V_8 , const void * V_29 , T_4 V_30 )
{
const T_5 * V_31 = V_29 ;
T_4 V_32 ;
V_32 = sizeof( V_8 -> V_33 ) - V_8 -> V_34 ;
if ( V_30 > V_32 ) {
if ( V_8 -> V_34 ) {
memcpy ( V_8 -> V_33 + V_8 -> V_34 , V_31 , V_32 ) ;
F_8 ( V_8 , V_8 -> V_33 , V_26 ) ;
V_8 -> V_34 = 0 ;
V_31 += V_32 ;
V_30 -= V_32 ;
}
if ( V_30 > V_26 ) {
T_4 V_35 = V_30 % V_26 ;
V_35 = V_35 ? V_35 : V_26 ;
V_30 -= V_35 ;
F_8 ( V_8 , V_31 , V_30 ) ;
V_31 += V_30 ;
V_30 = V_35 ;
}
}
assert ( V_30 <= V_26 ) ;
memcpy ( V_8 -> V_33 + V_8 -> V_34 , V_31 , V_30 ) ;
V_8 -> V_34 += V_30 ;
return 1 ;
}
int F_13 ( unsigned char * V_36 , T_2 * V_8 )
{
int V_3 ;
F_1 ( V_8 ) ;
memset ( V_8 -> V_33 + V_8 -> V_34 , 0 , sizeof( V_8 -> V_33 ) - V_8 -> V_34 ) ;
F_8 ( V_8 , V_8 -> V_33 , V_8 -> V_34 ) ;
for ( V_3 = 0 ; V_3 < 8 ; ++ V_3 ) {
F_7 ( V_36 + sizeof( V_8 -> V_4 [ V_3 ] ) * V_3 , V_8 -> V_4 [ V_3 ] ) ;
}
F_14 ( V_8 , sizeof( T_2 ) ) ;
return 1 ;
}
