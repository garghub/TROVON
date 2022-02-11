T_1 T_2 F_1 ( T_1 V_1 , unsigned char const * V_2 , T_3 V_3 )
{
int V_4 ;
while ( V_3 -- ) {
V_1 ^= * V_2 ++ ;
for ( V_4 = 0 ; V_4 < 8 ; V_4 ++ )
V_1 = ( V_1 >> 1 ) ^ ( ( V_1 & 1 ) ? V_5 : 0 ) ;
}
return V_1 ;
}
T_1 T_2 F_1 ( T_1 V_1 , unsigned char const * V_2 , T_3 V_3 )
{
# if V_6 == 8
const T_1 ( * V_7 ) [] = V_8 ;
V_1 = F_2 ( V_1 ) ;
V_1 = F_3 ( V_1 , V_2 , V_3 , V_7 ) ;
return F_4 ( V_1 ) ;
# elif V_6 == 4
while ( V_3 -- ) {
V_1 ^= * V_2 ++ ;
V_1 = ( V_1 >> 4 ) ^ V_8 [ V_1 & 15 ] ;
V_1 = ( V_1 >> 4 ) ^ V_8 [ V_1 & 15 ] ;
}
return V_1 ;
# elif V_6 == 2
while ( V_3 -- ) {
V_1 ^= * V_2 ++ ;
V_1 = ( V_1 >> 2 ) ^ V_8 [ V_1 & 3 ] ;
V_1 = ( V_1 >> 2 ) ^ V_8 [ V_1 & 3 ] ;
V_1 = ( V_1 >> 2 ) ^ V_8 [ V_1 & 3 ] ;
V_1 = ( V_1 >> 2 ) ^ V_8 [ V_1 & 3 ] ;
}
return V_1 ;
# endif
}
T_1 T_2 F_5 ( T_1 V_1 , unsigned char const * V_2 , T_3 V_3 )
{
int V_4 ;
while ( V_3 -- ) {
V_1 ^= * V_2 ++ << 24 ;
for ( V_4 = 0 ; V_4 < 8 ; V_4 ++ )
V_1 =
( V_1 << 1 ) ^ ( ( V_1 & 0x80000000 ) ? V_9 :
0 ) ;
}
return V_1 ;
}
T_1 T_2 F_5 ( T_1 V_1 , unsigned char const * V_2 , T_3 V_3 )
{
# if V_10 == 8
const T_1 ( * V_7 ) [] = V_11 ;
V_1 = F_6 ( V_1 ) ;
V_1 = F_3 ( V_1 , V_2 , V_3 , V_7 ) ;
return F_7 ( V_1 ) ;
# elif V_10 == 4
while ( V_3 -- ) {
V_1 ^= * V_2 ++ << 24 ;
V_1 = ( V_1 << 4 ) ^ V_11 [ V_1 >> 28 ] ;
V_1 = ( V_1 << 4 ) ^ V_11 [ V_1 >> 28 ] ;
}
return V_1 ;
# elif V_10 == 2
while ( V_3 -- ) {
V_1 ^= * V_2 ++ << 24 ;
V_1 = ( V_1 << 2 ) ^ V_11 [ V_1 >> 30 ] ;
V_1 = ( V_1 << 2 ) ^ V_11 [ V_1 >> 30 ] ;
V_1 = ( V_1 << 2 ) ^ V_11 [ V_1 >> 30 ] ;
V_1 = ( V_1 << 2 ) ^ V_11 [ V_1 >> 30 ] ;
}
return V_1 ;
# endif
}
static void F_8 ( unsigned char * V_12 , T_3 V_3 )
{
while ( V_3 -- ) {
unsigned char V_13 = F_9 ( * V_12 ) ;
* V_12 ++ = V_13 ;
}
}
static void F_10 ( unsigned char * V_12 , T_3 V_3 )
{
while ( V_3 -- )
* V_12 ++ = ( unsigned char ) F_11 () ;
}
static void F_12 ( T_1 V_13 , unsigned char * V_12 )
{
V_12 [ 0 ] = ( unsigned char ) ( V_13 >> 24 ) ;
V_12 [ 1 ] = ( unsigned char ) ( V_13 >> 16 ) ;
V_12 [ 2 ] = ( unsigned char ) ( V_13 >> 8 ) ;
V_12 [ 3 ] = ( unsigned char ) V_13 ;
}
static T_1 F_13 ( T_1 V_14 , unsigned char * V_12 , T_3 V_3 )
{
T_1 V_15 , V_16 ;
T_3 V_4 ;
V_15 = F_5 ( V_14 , V_12 , V_3 ) ;
F_12 ( V_15 , V_12 + V_3 ) ;
V_16 = F_5 ( V_14 , V_12 , V_3 + 4 ) ;
if ( V_16 )
printf ( L_1 ,
V_16 ) ;
for ( V_4 = 0 ; V_4 <= V_3 + 4 ; V_4 ++ ) {
V_16 = F_5 ( V_14 , V_12 , V_4 ) ;
V_16 = F_5 ( V_16 , V_12 + V_4 , V_3 + 4 - V_4 ) ;
if ( V_16 )
printf ( L_2 , V_16 ) ;
}
F_8 ( V_12 , V_3 + 4 ) ;
V_14 = F_14 ( V_14 ) ;
V_16 = F_14 ( V_15 ) ;
if ( V_15 != F_14 ( V_16 ) )
printf ( L_3 ,
V_15 , V_16 , F_14 ( V_16 ) ) ;
V_15 = F_1 ( V_14 , V_12 , V_3 ) ;
if ( V_15 != V_16 )
printf ( L_4 , V_15 ,
V_16 ) ;
V_16 = F_1 ( V_14 , V_12 , V_3 + 4 ) ;
if ( V_16 )
printf ( L_1 ,
V_16 ) ;
for ( V_4 = 0 ; V_4 <= V_3 + 4 ; V_4 ++ ) {
V_16 = F_1 ( V_14 , V_12 , V_4 ) ;
V_16 = F_1 ( V_16 , V_12 + V_4 , V_3 + 4 - V_4 ) ;
if ( V_16 )
printf ( L_2 , V_16 ) ;
}
return V_15 ;
}
int main ( void )
{
unsigned char V_17 [ V_18 + 4 ] ;
unsigned char V_19 [ V_18 + 4 ] ;
unsigned char V_20 [ V_18 + 4 ] ;
int V_4 , V_21 ;
T_1 V_15 , V_16 , V_22 ;
for ( V_4 = 0 ; V_4 <= V_18 ; V_4 ++ ) {
printf ( L_5 , V_4 ) ;
fflush ( stdout ) ;
F_10 ( V_17 , V_4 ) ;
F_10 ( V_19 , V_4 ) ;
for ( V_21 = 0 ; V_21 < V_4 ; V_21 ++ )
V_20 [ V_21 ] = V_17 [ V_21 ] ^ V_19 [ V_21 ] ;
V_15 = F_13 ( V_23 , V_17 , V_4 ) ;
V_16 = F_13 ( V_24 , V_19 , V_4 ) ;
V_22 = F_13 ( V_23 ^ V_24 , V_20 , V_4 ) ;
if ( V_22 != ( V_15 ^ V_16 ) )
printf ( L_6 ,
V_22 , V_15 , V_16 ) ;
}
printf ( L_7 ) ;
return 0 ;
}
