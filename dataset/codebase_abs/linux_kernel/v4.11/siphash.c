T_1 F_1 ( const void * V_1 , T_2 V_2 , const T_3 * V_3 )
{
const T_4 * V_4 = V_1 + V_2 - ( V_2 % sizeof( T_1 ) ) ;
const T_4 V_5 = V_2 & ( sizeof( T_1 ) - 1 ) ;
T_1 V_6 ;
F_2 (len)
for (; V_1 != V_4 ; V_1 += sizeof( T_1 ) ) {
V_6 = F_3 ( V_1 ) ;
V_7 ^= V_6 ;
V_8 ;
V_8 ;
V_9 ^= V_6 ;
}
#if F_4 ( V_10 ) && V_11 == 64
if ( V_5 )
V_12 |= F_5 ( ( V_13 V_14 ) ( F_6 ( V_1 ) &
F_7 ( V_5 ) ) ) ;
#else
switch ( V_5 ) {
case 7 : V_12 |= ( ( T_1 ) V_4 [ 6 ] ) << 48 ;
case 6 : V_12 |= ( ( T_1 ) V_4 [ 5 ] ) << 40 ;
case 5 : V_12 |= ( ( T_1 ) V_4 [ 4 ] ) << 32 ;
case 4 : V_12 |= F_8 ( V_1 ) ; break;
case 3 : V_12 |= ( ( T_1 ) V_4 [ 2 ] ) << 16 ;
case 2 : V_12 |= F_9 ( V_1 ) ; break;
case 1 : V_12 |= V_4 [ 0 ] ;
}
#endif
V_15
}
T_1 F_10 ( const void * V_1 , T_2 V_2 , const T_3 * V_3 )
{
const T_4 * V_4 = V_1 + V_2 - ( V_2 % sizeof( T_1 ) ) ;
const T_4 V_5 = V_2 & ( sizeof( T_1 ) - 1 ) ;
T_1 V_6 ;
F_2 (len)
for (; V_1 != V_4 ; V_1 += sizeof( T_1 ) ) {
V_6 = F_11 ( V_1 ) ;
V_7 ^= V_6 ;
V_8 ;
V_8 ;
V_9 ^= V_6 ;
}
#if F_4 ( V_10 ) && V_11 == 64
if ( V_5 )
V_12 |= F_5 ( ( V_13 V_14 ) ( F_6 ( V_1 ) &
F_7 ( V_5 ) ) ) ;
#else
switch ( V_5 ) {
case 7 : V_12 |= ( ( T_1 ) V_4 [ 6 ] ) << 48 ;
case 6 : V_12 |= ( ( T_1 ) V_4 [ 5 ] ) << 40 ;
case 5 : V_12 |= ( ( T_1 ) V_4 [ 4 ] ) << 32 ;
case 4 : V_12 |= F_12 ( V_4 ) ; break;
case 3 : V_12 |= ( ( T_1 ) V_4 [ 2 ] ) << 16 ;
case 2 : V_12 |= F_13 ( V_4 ) ; break;
case 1 : V_12 |= V_4 [ 0 ] ;
}
#endif
V_15
}
T_1 F_14 ( const T_1 V_16 , const T_3 * V_3 )
{
F_2 ( 8 )
V_7 ^= V_16 ;
V_8 ;
V_8 ;
V_9 ^= V_16 ;
V_15
}
T_1 F_15 ( const T_1 V_16 , const T_1 V_17 , const T_3 * V_3 )
{
F_2 ( 16 )
V_7 ^= V_16 ;
V_8 ;
V_8 ;
V_9 ^= V_16 ;
V_7 ^= V_17 ;
V_8 ;
V_8 ;
V_9 ^= V_17 ;
V_15
}
T_1 F_16 ( const T_1 V_16 , const T_1 V_17 , const T_1 V_18 ,
const T_3 * V_3 )
{
F_2 ( 24 )
V_7 ^= V_16 ;
V_8 ;
V_8 ;
V_9 ^= V_16 ;
V_7 ^= V_17 ;
V_8 ;
V_8 ;
V_9 ^= V_17 ;
V_7 ^= V_18 ;
V_8 ;
V_8 ;
V_9 ^= V_18 ;
V_15
}
T_1 F_17 ( const T_1 V_16 , const T_1 V_17 , const T_1 V_18 ,
const T_1 V_19 , const T_3 * V_3 )
{
F_2 ( 32 )
V_7 ^= V_16 ;
V_8 ;
V_8 ;
V_9 ^= V_16 ;
V_7 ^= V_17 ;
V_8 ;
V_8 ;
V_9 ^= V_17 ;
V_7 ^= V_18 ;
V_8 ;
V_8 ;
V_9 ^= V_18 ;
V_7 ^= V_19 ;
V_8 ;
V_8 ;
V_9 ^= V_19 ;
V_15
}
T_1 F_18 ( const T_5 V_16 , const T_3 * V_3 )
{
F_2 ( 4 )
V_12 |= V_16 ;
V_15
}
T_1 F_19 ( const T_5 V_16 , const T_5 V_17 , const T_5 V_18 ,
const T_3 * V_3 )
{
T_1 V_20 = ( T_1 ) V_17 << 32 | V_16 ;
F_2 ( 12 )
V_7 ^= V_20 ;
V_8 ;
V_8 ;
V_9 ^= V_20 ;
V_12 |= V_18 ;
V_15
}
T_5 F_20 ( const void * V_1 , T_2 V_2 , const T_6 * V_3 )
{
const T_4 * V_4 = V_1 + V_2 - ( V_2 % sizeof( T_1 ) ) ;
const T_4 V_5 = V_2 & ( sizeof( T_1 ) - 1 ) ;
T_1 V_6 ;
F_21 (len)
for (; V_1 != V_4 ; V_1 += sizeof( T_1 ) ) {
V_6 = F_3 ( V_1 ) ;
V_7 ^= V_6 ;
V_21 ;
V_9 ^= V_6 ;
}
#if F_4 ( V_10 ) && V_11 == 64
if ( V_5 )
V_12 |= F_5 ( ( V_13 V_14 ) ( F_6 ( V_1 ) &
F_7 ( V_5 ) ) ) ;
#else
switch ( V_5 ) {
case 7 : V_12 |= ( ( T_1 ) V_4 [ 6 ] ) << 48 ;
case 6 : V_12 |= ( ( T_1 ) V_4 [ 5 ] ) << 40 ;
case 5 : V_12 |= ( ( T_1 ) V_4 [ 4 ] ) << 32 ;
case 4 : V_12 |= F_8 ( V_1 ) ; break;
case 3 : V_12 |= ( ( T_1 ) V_4 [ 2 ] ) << 16 ;
case 2 : V_12 |= F_9 ( V_1 ) ; break;
case 1 : V_12 |= V_4 [ 0 ] ;
}
#endif
V_22
}
T_5 F_22 ( const void * V_1 , T_2 V_2 ,
const T_6 * V_3 )
{
const T_4 * V_4 = V_1 + V_2 - ( V_2 % sizeof( T_1 ) ) ;
const T_4 V_5 = V_2 & ( sizeof( T_1 ) - 1 ) ;
T_1 V_6 ;
F_21 (len)
for (; V_1 != V_4 ; V_1 += sizeof( T_1 ) ) {
V_6 = F_11 ( V_1 ) ;
V_7 ^= V_6 ;
V_21 ;
V_9 ^= V_6 ;
}
#if F_4 ( V_10 ) && V_11 == 64
if ( V_5 )
V_12 |= F_5 ( ( V_13 V_14 ) ( F_6 ( V_1 ) &
F_7 ( V_5 ) ) ) ;
#else
switch ( V_5 ) {
case 7 : V_12 |= ( ( T_1 ) V_4 [ 6 ] ) << 48 ;
case 6 : V_12 |= ( ( T_1 ) V_4 [ 5 ] ) << 40 ;
case 5 : V_12 |= ( ( T_1 ) V_4 [ 4 ] ) << 32 ;
case 4 : V_12 |= F_12 ( V_4 ) ; break;
case 3 : V_12 |= ( ( T_1 ) V_4 [ 2 ] ) << 16 ;
case 2 : V_12 |= F_13 ( V_4 ) ; break;
case 1 : V_12 |= V_4 [ 0 ] ;
}
#endif
V_22
}
T_5 F_23 ( const T_5 V_16 , const T_6 * V_3 )
{
F_21 ( 4 )
V_12 |= V_16 ;
V_22
}
T_5 F_24 ( const T_5 V_16 , const T_5 V_17 , const T_6 * V_3 )
{
T_1 V_20 = ( T_1 ) V_17 << 32 | V_16 ;
F_21 ( 8 )
V_7 ^= V_20 ;
V_21 ;
V_9 ^= V_20 ;
V_22
}
T_5 F_25 ( const T_5 V_16 , const T_5 V_17 , const T_5 V_18 ,
const T_6 * V_3 )
{
T_1 V_20 = ( T_1 ) V_17 << 32 | V_16 ;
F_21 ( 12 )
V_7 ^= V_20 ;
V_21 ;
V_9 ^= V_20 ;
V_12 |= V_18 ;
V_22
}
T_5 F_26 ( const T_5 V_16 , const T_5 V_17 , const T_5 V_18 ,
const T_5 V_19 , const T_6 * V_3 )
{
T_1 V_20 = ( T_1 ) V_17 << 32 | V_16 ;
F_21 ( 16 )
V_7 ^= V_20 ;
V_21 ;
V_9 ^= V_20 ;
V_20 = ( T_1 ) V_19 << 32 | V_18 ;
V_7 ^= V_20 ;
V_21 ;
V_9 ^= V_20 ;
V_22
}
T_5 F_20 ( const void * V_1 , T_2 V_2 , const T_6 * V_3 )
{
const T_4 * V_4 = V_1 + V_2 - ( V_2 % sizeof( T_5 ) ) ;
const T_4 V_5 = V_2 & ( sizeof( T_5 ) - 1 ) ;
T_5 V_6 ;
F_21 (len)
for (; V_1 != V_4 ; V_1 += sizeof( T_5 ) ) {
V_6 = F_8 ( V_1 ) ;
V_7 ^= V_6 ;
V_21 ;
V_9 ^= V_6 ;
}
switch ( V_5 ) {
case 3 : V_12 |= ( ( T_5 ) V_4 [ 2 ] ) << 16 ;
case 2 : V_12 |= F_9 ( V_1 ) ; break;
case 1 : V_12 |= V_4 [ 0 ] ;
}
V_22
}
T_5 F_22 ( const void * V_1 , T_2 V_2 ,
const T_6 * V_3 )
{
const T_4 * V_4 = V_1 + V_2 - ( V_2 % sizeof( T_5 ) ) ;
const T_4 V_5 = V_2 & ( sizeof( T_5 ) - 1 ) ;
T_5 V_6 ;
F_21 (len)
for (; V_1 != V_4 ; V_1 += sizeof( T_5 ) ) {
V_6 = F_12 ( V_1 ) ;
V_7 ^= V_6 ;
V_21 ;
V_9 ^= V_6 ;
}
switch ( V_5 ) {
case 3 : V_12 |= ( ( T_5 ) V_4 [ 2 ] ) << 16 ;
case 2 : V_12 |= F_13 ( V_4 ) ; break;
case 1 : V_12 |= V_4 [ 0 ] ;
}
V_22
}
T_5 F_23 ( const T_5 V_16 , const T_6 * V_3 )
{
F_21 ( 4 )
V_7 ^= V_16 ;
V_21 ;
V_9 ^= V_16 ;
V_22
}
T_5 F_24 ( const T_5 V_16 , const T_5 V_17 , const T_6 * V_3 )
{
F_21 ( 8 )
V_7 ^= V_16 ;
V_21 ;
V_9 ^= V_16 ;
V_7 ^= V_17 ;
V_21 ;
V_9 ^= V_17 ;
V_22
}
T_5 F_25 ( const T_5 V_16 , const T_5 V_17 , const T_5 V_18 ,
const T_6 * V_3 )
{
F_21 ( 12 )
V_7 ^= V_16 ;
V_21 ;
V_9 ^= V_16 ;
V_7 ^= V_17 ;
V_21 ;
V_9 ^= V_17 ;
V_7 ^= V_18 ;
V_21 ;
V_9 ^= V_18 ;
V_22
}
T_5 F_26 ( const T_5 V_16 , const T_5 V_17 , const T_5 V_18 ,
const T_5 V_19 , const T_6 * V_3 )
{
F_21 ( 16 )
V_7 ^= V_16 ;
V_21 ;
V_9 ^= V_16 ;
V_7 ^= V_17 ;
V_21 ;
V_9 ^= V_17 ;
V_7 ^= V_18 ;
V_21 ;
V_9 ^= V_18 ;
V_7 ^= V_19 ;
V_21 ;
V_9 ^= V_19 ;
V_22
}
