char * F_1 ( char * V_1 , const T_1 * V_2 )
{
char V_3 , * V_4 ;
int V_5 ;
for ( V_5 = 0 , V_4 = V_1 ; V_5 < 6 ; V_5 ++ ) {
V_3 = ( V_2 -> V_6 [ V_5 ] >> 1 ) & 0x7F ;
if ( V_3 != ' ' ) * V_4 ++ = V_3 ;
}
* V_4 ++ = '-' ;
if ( ( V_5 = ( ( V_2 -> V_6 [ 6 ] >> 1 ) & 0x0F ) ) > 9 ) {
* V_4 ++ = '1' ;
V_5 -= 10 ;
}
* V_4 ++ = V_5 + '0' ;
* V_4 ++ = '\0' ;
if ( * V_1 == '\0' || * V_1 == '-' )
return L_1 ;
return V_1 ;
}
void F_2 ( T_1 * V_7 , const char * V_8 )
{
const char * V_4 ;
int V_5 ;
for ( V_4 = V_8 , V_5 = 0 ; V_5 < 6 ; V_5 ++ ) {
if ( * V_4 != '\0' && * V_4 != '-' )
V_7 -> V_6 [ V_5 ] = * V_4 ++ ;
else
V_7 -> V_6 [ V_5 ] = ' ' ;
V_7 -> V_6 [ V_5 ] <<= 1 ;
V_7 -> V_6 [ V_5 ] &= 0xFE ;
}
if ( * V_4 ++ == '\0' ) {
V_7 -> V_6 [ 6 ] = 0x00 ;
return;
}
V_7 -> V_6 [ 6 ] = * V_4 ++ - '0' ;
if ( * V_4 != '\0' ) {
V_7 -> V_6 [ 6 ] *= 10 ;
V_7 -> V_6 [ 6 ] += * V_4 ++ - '0' ;
}
V_7 -> V_6 [ 6 ] <<= 1 ;
V_7 -> V_6 [ 6 ] &= 0x1E ;
}
int F_3 ( const T_1 * V_2 , const T_1 * V_9 )
{
int V_10 = 0 ;
while ( V_10 < 6 ) {
if ( ( V_2 -> V_6 [ V_10 ] & 0xFE ) != ( V_9 -> V_6 [ V_10 ] & 0xFE ) )
return 1 ;
V_10 ++ ;
}
if ( ( V_2 -> V_6 [ V_10 ] & 0x1E ) == ( V_9 -> V_6 [ V_10 ] & 0x1E ) )
return 0 ;
return 2 ;
}
int F_4 ( const T_2 * V_11 , const T_2 * V_12 )
{
int V_13 ;
if ( V_11 -> V_14 != V_12 -> V_14 )
return 1 ;
if ( V_11 -> V_15 != V_12 -> V_15 )
return 1 ;
for ( V_13 = 0 ; V_13 < V_11 -> V_14 ; V_13 ++ )
if ( F_3 ( & V_11 -> V_16 [ V_13 ] , & V_12 -> V_16 [ V_13 ] ) != 0 )
return 1 ;
return 0 ;
}
const unsigned char * F_5 ( const unsigned char * V_1 , int V_17 ,
T_1 * V_18 , T_1 * V_19 , T_2 * V_20 , int * V_21 ,
int * V_22 )
{
int V_23 = 0 ;
if ( V_17 < 14 ) return NULL ;
if ( V_21 != NULL ) {
* V_21 = 0 ;
if ( V_1 [ 6 ] & V_24 )
* V_21 = V_25 ;
if ( V_1 [ 13 ] & V_24 )
* V_21 = V_26 ;
}
if ( V_22 != NULL )
* V_22 = ~ V_1 [ 13 ] & V_27 ;
if ( V_19 != NULL )
memcpy ( V_19 , V_1 + 0 , V_28 ) ;
if ( V_18 != NULL )
memcpy ( V_18 , V_1 + 7 , V_28 ) ;
V_1 += 2 * V_28 ;
V_17 -= 2 * V_28 ;
V_20 -> V_15 = - 1 ;
V_20 -> V_14 = 0 ;
while ( ! ( V_1 [ - 1 ] & V_29 ) ) {
if ( V_23 >= V_30 ) return NULL ;
if ( V_17 < 7 ) return NULL ;
memcpy ( & V_20 -> V_16 [ V_23 ] , V_1 , V_28 ) ;
V_20 -> V_14 = V_23 + 1 ;
if ( V_1 [ 6 ] & V_31 ) {
V_20 -> V_32 [ V_23 ] = 1 ;
V_20 -> V_15 = V_23 ;
} else {
V_20 -> V_32 [ V_23 ] = 0 ;
}
V_1 += V_28 ;
V_17 -= V_28 ;
V_23 ++ ;
}
return V_1 ;
}
int F_6 ( unsigned char * V_1 , const T_1 * V_18 ,
const T_1 * V_19 , const T_2 * V_23 , int V_33 , int V_34 )
{
int V_17 = 0 ;
int V_10 = 0 ;
memcpy ( V_1 , V_19 , V_28 ) ;
V_1 [ 6 ] &= ~ ( V_29 | V_24 ) ;
V_1 [ 6 ] |= V_35 ;
if ( V_33 == V_25 ) V_1 [ 6 ] |= V_24 ;
V_1 += V_28 ;
V_17 += V_28 ;
memcpy ( V_1 , V_18 , V_28 ) ;
V_1 [ 6 ] &= ~ ( V_29 | V_24 ) ;
V_1 [ 6 ] &= ~ V_35 ;
if ( V_34 == V_36 )
V_1 [ 6 ] |= V_35 ;
else
V_1 [ 6 ] |= V_37 ;
if ( V_33 == V_26 ) V_1 [ 6 ] |= V_24 ;
if ( V_23 == NULL || V_23 -> V_14 == 0 ) {
V_1 [ 6 ] |= V_29 ;
return 2 * V_28 ;
}
V_1 += V_28 ;
V_17 += V_28 ;
while ( V_10 < V_23 -> V_14 ) {
memcpy ( V_1 , & V_23 -> V_16 [ V_10 ] , V_28 ) ;
if ( V_23 -> V_32 [ V_10 ] )
V_1 [ 6 ] |= V_31 ;
else
V_1 [ 6 ] &= ~ V_31 ;
V_1 [ 6 ] &= ~ V_29 ;
V_1 [ 6 ] |= V_35 ;
V_1 += V_28 ;
V_17 += V_28 ;
V_10 ++ ;
}
V_1 [ - 1 ] |= V_29 ;
return V_17 ;
}
int F_7 ( const T_2 * V_38 )
{
if ( V_38 == NULL )
return 2 * V_28 ;
return V_28 * ( 2 + V_38 -> V_14 ) ;
}
void F_8 ( const T_2 * V_39 , T_2 * V_40 )
{
int V_10 ;
V_40 -> V_14 = V_39 -> V_14 ;
V_40 -> V_15 = V_39 -> V_14 - V_39 -> V_15 - 2 ;
for ( V_10 = 0 ; V_10 < V_39 -> V_14 ; V_10 ++ ) {
V_40 -> V_16 [ V_10 ] = V_39 -> V_16 [ V_39 -> V_14 - V_10 - 1 ] ;
if ( V_10 <= V_40 -> V_15 ) {
V_40 -> V_16 [ V_10 ] . V_6 [ 6 ] |= V_31 ;
V_40 -> V_32 [ V_10 ] = 1 ;
} else {
V_40 -> V_16 [ V_10 ] . V_6 [ 6 ] &= ~ V_31 ;
V_40 -> V_32 [ V_10 ] = 0 ;
}
}
}
