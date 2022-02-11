static unsigned char F_1 ( unsigned char V_1 )
{
if ( V_1 & 0x80 )
return V_2 ;
return V_3 [ V_1 ] ;
}
static unsigned char F_1 ( unsigned char V_1 )
{
V_1 = V_4 [ V_1 ] ;
if ( V_1 & 0x80 )
return V_2 ;
return V_3 [ V_1 ] ;
}
T_1 * F_2 ( void )
{
return F_3 ( sizeof( T_1 ) ) ;
}
void F_4 ( T_1 * V_5 )
{
F_5 ( V_5 ) ;
}
int F_6 ( T_1 * V_6 , T_1 * V_7 )
{
memcpy ( V_6 , V_7 , sizeof( T_1 ) ) ;
return 1 ;
}
int F_7 ( T_1 * V_5 )
{
return V_5 -> V_8 ;
}
void F_8 ( T_1 * V_5 )
{
V_5 -> V_9 = 48 ;
V_5 -> V_8 = 0 ;
V_5 -> V_10 = 0 ;
}
int F_9 ( T_1 * V_5 , unsigned char * V_11 , int * V_12 ,
const unsigned char * V_13 , int V_14 )
{
int V_15 , V_16 ;
T_2 V_17 = 0 ;
* V_12 = 0 ;
if ( V_14 <= 0 )
return 0 ;
F_10 ( V_5 -> V_9 <= ( int ) sizeof( V_5 -> V_18 ) ) ;
if ( V_5 -> V_9 - V_5 -> V_8 > V_14 ) {
memcpy ( & ( V_5 -> V_18 [ V_5 -> V_8 ] ) , V_13 , V_14 ) ;
V_5 -> V_8 += V_14 ;
return 1 ;
}
if ( V_5 -> V_8 != 0 ) {
V_15 = V_5 -> V_9 - V_5 -> V_8 ;
memcpy ( & ( V_5 -> V_18 [ V_5 -> V_8 ] ) , V_13 , V_15 ) ;
V_13 += V_15 ;
V_14 -= V_15 ;
V_16 = F_11 ( V_11 , V_5 -> V_18 , V_5 -> V_9 ) ;
V_5 -> V_8 = 0 ;
V_11 += V_16 ;
* ( V_11 ++ ) = '\n' ;
* V_11 = '\0' ;
V_17 = V_16 + 1 ;
}
while ( V_14 >= V_5 -> V_9 && V_17 <= V_19 ) {
V_16 = F_11 ( V_11 , V_13 , V_5 -> V_9 ) ;
V_13 += V_5 -> V_9 ;
V_14 -= V_5 -> V_9 ;
V_11 += V_16 ;
* ( V_11 ++ ) = '\n' ;
* V_11 = '\0' ;
V_17 += V_16 + 1 ;
}
if ( V_17 > V_19 ) {
* V_12 = 0 ;
return 0 ;
}
if ( V_14 != 0 )
memcpy ( & ( V_5 -> V_18 [ 0 ] ) , V_13 , V_14 ) ;
V_5 -> V_8 = V_14 ;
* V_12 = V_17 ;
return 1 ;
}
void F_12 ( T_1 * V_5 , unsigned char * V_11 , int * V_12 )
{
unsigned int V_20 = 0 ;
if ( V_5 -> V_8 != 0 ) {
V_20 = F_11 ( V_11 , V_5 -> V_18 , V_5 -> V_8 ) ;
V_11 [ V_20 ++ ] = '\n' ;
V_11 [ V_20 ] = '\0' ;
V_5 -> V_8 = 0 ;
}
* V_12 = V_20 ;
}
int F_11 ( unsigned char * V_21 , const unsigned char * V_22 , int V_23 )
{
int V_15 , V_20 = 0 ;
unsigned long V_24 ;
for ( V_15 = V_23 ; V_15 > 0 ; V_15 -= 3 ) {
if ( V_15 >= 3 ) {
V_24 = ( ( ( unsigned long ) V_22 [ 0 ] ) << 16L ) |
( ( ( unsigned long ) V_22 [ 1 ] ) << 8L ) | V_22 [ 2 ] ;
* ( V_21 ++ ) = F_13 ( V_24 >> 18L ) ;
* ( V_21 ++ ) = F_13 ( V_24 >> 12L ) ;
* ( V_21 ++ ) = F_13 ( V_24 >> 6L ) ;
* ( V_21 ++ ) = F_13 ( V_24 ) ;
} else {
V_24 = ( ( unsigned long ) V_22 [ 0 ] ) << 16L ;
if ( V_15 == 2 )
V_24 |= ( ( unsigned long ) V_22 [ 1 ] << 8L ) ;
* ( V_21 ++ ) = F_13 ( V_24 >> 18L ) ;
* ( V_21 ++ ) = F_13 ( V_24 >> 12L ) ;
* ( V_21 ++ ) = ( V_15 == 1 ) ? '=' : F_13 ( V_24 >> 6L ) ;
* ( V_21 ++ ) = '=' ;
}
V_20 += 4 ;
V_22 += 3 ;
}
* V_21 = '\0' ;
return ( V_20 ) ;
}
void F_14 ( T_1 * V_5 )
{
V_5 -> V_8 = 0 ;
V_5 -> V_9 = 0 ;
V_5 -> V_10 = 0 ;
V_5 -> V_25 = 0 ;
}
int F_15 ( T_1 * V_5 , unsigned char * V_11 , int * V_12 ,
const unsigned char * V_13 , int V_14 )
{
int V_26 = 0 , V_27 = 0 , V_28 = - 1 , V_20 = 0 , V_15 , V_29 , V_30 , V_31 , V_32 ;
unsigned char * V_33 ;
V_31 = V_5 -> V_8 ;
V_33 = V_5 -> V_18 ;
if ( V_31 > 0 && V_33 [ V_31 - 1 ] == '=' ) {
V_27 ++ ;
if ( V_31 > 1 && V_33 [ V_31 - 2 ] == '=' )
V_27 ++ ;
}
if ( V_14 == 0 ) {
V_28 = 0 ;
goto V_34;
}
for ( V_15 = 0 ; V_15 < V_14 ; V_15 ++ ) {
V_30 = * ( V_13 ++ ) ;
V_29 = F_1 ( V_30 ) ;
if ( V_29 == V_2 ) {
V_28 = - 1 ;
goto V_34;
}
if ( V_30 == '=' ) {
V_27 ++ ;
} else if ( V_27 > 0 && F_16 ( V_29 ) ) {
V_28 = - 1 ;
goto V_34;
}
if ( V_27 > 2 ) {
V_28 = - 1 ;
goto V_34;
}
if ( V_29 == V_35 ) {
V_26 = 1 ;
goto V_36;
}
if ( F_16 ( V_29 ) ) {
if ( V_31 >= 64 ) {
V_28 = - 1 ;
goto V_34;
}
F_10 ( V_31 < ( int ) sizeof( V_5 -> V_18 ) ) ;
V_33 [ V_31 ++ ] = V_30 ;
}
if ( V_31 == 64 ) {
V_32 = F_17 ( V_11 , V_33 , V_31 ) ;
V_31 = 0 ;
if ( V_32 < 0 || V_27 > V_32 ) {
V_28 = - 1 ;
goto V_34;
}
V_20 += V_32 - V_27 ;
V_11 += V_32 - V_27 ;
}
}
V_36:
if ( V_31 > 0 ) {
if ( ( V_31 & 3 ) == 0 ) {
V_32 = F_17 ( V_11 , V_33 , V_31 ) ;
V_31 = 0 ;
if ( V_32 < 0 || V_27 > V_32 ) {
V_28 = - 1 ;
goto V_34;
}
V_20 += ( V_32 - V_27 ) ;
} else if ( V_26 ) {
V_28 = - 1 ;
goto V_34;
}
}
V_28 = V_26 || ( V_31 == 0 && V_27 ) ? 0 : 1 ;
V_34:
* V_12 = V_20 ;
V_5 -> V_8 = V_31 ;
return ( V_28 ) ;
}
int F_17 ( unsigned char * V_21 , const unsigned char * V_22 , int V_31 )
{
int V_15 , V_20 = 0 , V_1 , V_37 , V_38 , V_33 ;
unsigned long V_24 ;
while ( ( F_1 ( * V_22 ) == V_39 ) && ( V_31 > 0 ) ) {
V_22 ++ ;
V_31 -- ;
}
while ( ( V_31 > 3 ) && ( F_18 ( F_1 ( V_22 [ V_31 - 1 ] ) ) ) )
V_31 -- ;
if ( V_31 % 4 != 0 )
return ( - 1 ) ;
for ( V_15 = 0 ; V_15 < V_31 ; V_15 += 4 ) {
V_1 = F_1 ( * ( V_22 ++ ) ) ;
V_37 = F_1 ( * ( V_22 ++ ) ) ;
V_38 = F_1 ( * ( V_22 ++ ) ) ;
V_33 = F_1 ( * ( V_22 ++ ) ) ;
if ( ( V_1 & 0x80 ) || ( V_37 & 0x80 ) || ( V_38 & 0x80 ) || ( V_33 & 0x80 ) )
return ( - 1 ) ;
V_24 = ( ( ( ( unsigned long ) V_1 ) << 18L ) |
( ( ( unsigned long ) V_37 ) << 12L ) |
( ( ( unsigned long ) V_38 ) << 6L ) | ( ( ( unsigned long ) V_33 ) ) ) ;
* ( V_21 ++ ) = ( unsigned char ) ( V_24 >> 16L ) & 0xff ;
* ( V_21 ++ ) = ( unsigned char ) ( V_24 >> 8L ) & 0xff ;
* ( V_21 ++ ) = ( unsigned char ) ( V_24 ) & 0xff ;
V_20 += 3 ;
}
return ( V_20 ) ;
}
int F_19 ( T_1 * V_5 , unsigned char * V_11 , int * V_12 )
{
int V_15 ;
* V_12 = 0 ;
if ( V_5 -> V_8 != 0 ) {
V_15 = F_17 ( V_11 , V_5 -> V_18 , V_5 -> V_8 ) ;
if ( V_15 < 0 )
return ( - 1 ) ;
V_5 -> V_8 = 0 ;
* V_12 = V_15 ;
return ( 1 ) ;
} else
return ( 1 ) ;
}
