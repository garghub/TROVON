static int F_1 ( T_1 * V_1 ,
const unsigned char V_2 [ V_3 ] ,
const unsigned char V_4 [ V_5 ] , int V_6 )
{
T_2 * V_7 = F_2 ( V_1 ) ;
unsigned int V_8 ;
if ( V_2 )
for ( V_8 = 0 ; V_8 < V_3 ; V_8 += 4 ) {
V_7 -> V_7 . V_9 [ V_8 / 4 ] = F_3 ( V_2 + V_8 ) ;
}
if ( V_4 )
for ( V_8 = 0 ; V_8 < V_5 ; V_8 += 4 ) {
V_7 -> V_10 [ V_8 / 4 ] = F_3 ( V_4 + V_8 ) ;
}
V_7 -> V_11 = 0 ;
return 1 ;
}
static int F_4 ( T_1 * V_1 , unsigned char * V_12 ,
const unsigned char * V_13 , T_3 V_14 )
{
T_2 * V_7 = F_2 ( V_1 ) ;
unsigned int V_15 , V_16 , V_17 ;
if ( ( V_15 = V_7 -> V_11 ) ) {
while ( V_14 && V_15 < V_18 ) {
* V_12 ++ = * V_13 ++ ^ V_7 -> V_19 [ V_15 ++ ] ;
V_14 -- ;
}
V_7 -> V_11 = V_15 ;
if ( V_14 == 0 )
return 1 ;
if ( V_15 == V_18 ) {
V_7 -> V_11 = 0 ;
V_7 -> V_10 [ 0 ] ++ ;
if ( V_7 -> V_10 [ 0 ] == 0 )
V_7 -> V_10 [ 1 ] ++ ;
}
}
V_16 = ( unsigned int ) ( V_14 % V_18 ) ;
V_14 -= V_16 ;
V_17 = V_7 -> V_10 [ 0 ] ;
while ( V_14 >= V_18 ) {
T_3 V_20 = V_14 / V_18 ;
if ( sizeof( T_3 ) >sizeof( unsigned int ) && V_20 > ( 1U << 28 ) )
V_20 = ( 1U << 28 ) ;
V_17 += ( unsigned int ) V_20 ;
if ( V_17 < V_20 ) {
V_20 -= V_17 ;
V_17 = 0 ;
}
V_20 *= V_18 ;
F_5 ( V_12 , V_13 , V_20 , V_7 -> V_7 . V_9 , V_7 -> V_10 ) ;
V_14 -= V_20 ;
V_13 += V_20 ;
V_12 += V_20 ;
V_7 -> V_10 [ 0 ] = V_17 ;
if ( V_17 == 0 ) V_7 -> V_10 [ 1 ] ++ ;
}
if ( V_16 ) {
memset ( V_7 -> V_19 , 0 , sizeof( V_7 -> V_19 ) ) ;
F_5 ( V_7 -> V_19 , V_7 -> V_19 , V_18 ,
V_7 -> V_7 . V_9 , V_7 -> V_10 ) ;
for ( V_15 = 0 ; V_15 < V_16 ; V_15 ++ )
V_12 [ V_15 ] = V_13 [ V_15 ] ^ V_7 -> V_19 [ V_15 ] ;
V_7 -> V_11 = V_16 ;
}
return 1 ;
}
const T_4 * F_6 ( void )
{
return ( & V_21 ) ;
}
static int F_7 ( T_1 * V_1 ,
const unsigned char * V_22 ,
const unsigned char * V_4 , int V_6 )
{
T_5 * V_23 = F_8 ( V_1 ) ;
if ( ! V_22 && ! V_4 )
return 1 ;
V_23 -> V_14 . V_24 = 0 ;
V_23 -> V_14 . V_25 = 0 ;
V_23 -> V_24 = 0 ;
V_23 -> V_26 = 0 ;
V_23 -> V_27 = V_28 ;
if ( V_4 != NULL ) {
unsigned char V_29 [ V_5 ] = { 0 } ;
if ( V_23 -> V_30 <= V_5 )
memcpy ( V_29 + V_5 - V_23 -> V_30 , V_4 , V_23 -> V_30 ) ;
F_1 ( V_1 , V_22 , V_29 , V_6 ) ;
V_23 -> V_31 [ 0 ] = V_23 -> V_7 . V_10 [ 1 ] ;
V_23 -> V_31 [ 1 ] = V_23 -> V_7 . V_10 [ 2 ] ;
V_23 -> V_31 [ 2 ] = V_23 -> V_7 . V_10 [ 3 ] ;
} else {
F_1 ( V_1 , V_22 , NULL , V_6 ) ;
}
return 1 ;
}
static int F_9 ( T_1 * V_1 , unsigned char * V_12 ,
const unsigned char * V_32 , T_3 V_14 )
{
T_5 * V_23 = F_8 ( V_1 ) ;
T_3 V_16 , V_33 = V_23 -> V_27 ;
static const unsigned char V_34 [ V_35 ] = { 0 } ;
if ( ! V_23 -> V_26 ) {
V_23 -> V_7 . V_10 [ 0 ] = 0 ;
memset ( V_23 -> V_7 . V_19 , 0 , sizeof( V_23 -> V_7 . V_19 ) ) ;
F_5 ( V_23 -> V_7 . V_19 , V_23 -> V_7 . V_19 , V_18 ,
V_23 -> V_7 . V_7 . V_9 , V_23 -> V_7 . V_10 ) ;
F_10 ( F_11 ( V_23 ) , V_23 -> V_7 . V_19 ) ;
V_23 -> V_7 . V_10 [ 0 ] = 1 ;
V_23 -> V_7 . V_11 = 0 ;
V_23 -> V_14 . V_24 = V_23 -> V_14 . V_25 = 0 ;
V_23 -> V_26 = 1 ;
}
if ( V_32 ) {
if ( V_12 == NULL ) {
F_12 ( F_11 ( V_23 ) , V_32 , V_14 ) ;
V_23 -> V_14 . V_24 += V_14 ;
V_23 -> V_24 = 1 ;
return V_14 ;
} else {
if ( V_23 -> V_24 ) {
if ( ( V_16 = ( T_3 ) V_23 -> V_14 . V_24 % V_35 ) )
F_12 ( F_11 ( V_23 ) , V_34 ,
V_35 - V_16 ) ;
V_23 -> V_24 = 0 ;
}
V_23 -> V_27 = V_28 ;
if ( V_33 == V_28 )
V_33 = V_14 ;
else if ( V_14 != V_33 + V_35 )
return - 1 ;
if ( V_1 -> V_36 ) {
F_4 ( V_1 , V_12 , V_32 , V_33 ) ;
F_12 ( F_11 ( V_23 ) , V_12 , V_33 ) ;
V_32 += V_33 ;
V_12 += V_33 ;
V_23 -> V_14 . V_25 += V_33 ;
} else {
F_12 ( F_11 ( V_23 ) , V_32 , V_33 ) ;
F_4 ( V_1 , V_12 , V_32 , V_33 ) ;
V_32 += V_33 ;
V_12 += V_33 ;
V_23 -> V_14 . V_25 += V_33 ;
}
}
}
if ( V_32 == NULL
|| V_33 != V_14 ) {
const union {
long V_37 ;
char V_38 ;
} V_39 = { 1 } ;
unsigned char V_29 [ V_35 ] ;
if ( V_23 -> V_24 ) {
if ( ( V_16 = ( T_3 ) V_23 -> V_14 . V_24 % V_35 ) )
F_12 ( F_11 ( V_23 ) , V_34 ,
V_35 - V_16 ) ;
V_23 -> V_24 = 0 ;
}
if ( ( V_16 = ( T_3 ) V_23 -> V_14 . V_25 % V_35 ) )
F_12 ( F_11 ( V_23 ) , V_34 ,
V_35 - V_16 ) ;
if ( V_39 . V_38 ) {
F_12 ( F_11 ( V_23 ) ,
( unsigned char * ) & V_23 -> V_14 , V_35 ) ;
} else {
V_29 [ 0 ] = ( unsigned char ) ( V_23 -> V_14 . V_24 ) ;
V_29 [ 1 ] = ( unsigned char ) ( V_23 -> V_14 . V_24 >> 8 ) ;
V_29 [ 2 ] = ( unsigned char ) ( V_23 -> V_14 . V_24 >> 16 ) ;
V_29 [ 3 ] = ( unsigned char ) ( V_23 -> V_14 . V_24 >> 24 ) ;
V_29 [ 4 ] = ( unsigned char ) ( V_23 -> V_14 . V_24 >> 32 ) ;
V_29 [ 5 ] = ( unsigned char ) ( V_23 -> V_14 . V_24 >> 40 ) ;
V_29 [ 6 ] = ( unsigned char ) ( V_23 -> V_14 . V_24 >> 48 ) ;
V_29 [ 7 ] = ( unsigned char ) ( V_23 -> V_14 . V_24 >> 56 ) ;
V_29 [ 8 ] = ( unsigned char ) ( V_23 -> V_14 . V_25 ) ;
V_29 [ 9 ] = ( unsigned char ) ( V_23 -> V_14 . V_25 >> 8 ) ;
V_29 [ 10 ] = ( unsigned char ) ( V_23 -> V_14 . V_25 >> 16 ) ;
V_29 [ 11 ] = ( unsigned char ) ( V_23 -> V_14 . V_25 >> 24 ) ;
V_29 [ 12 ] = ( unsigned char ) ( V_23 -> V_14 . V_25 >> 32 ) ;
V_29 [ 13 ] = ( unsigned char ) ( V_23 -> V_14 . V_25 >> 40 ) ;
V_29 [ 14 ] = ( unsigned char ) ( V_23 -> V_14 . V_25 >> 48 ) ;
V_29 [ 15 ] = ( unsigned char ) ( V_23 -> V_14 . V_25 >> 56 ) ;
F_12 ( F_11 ( V_23 ) , V_29 , V_35 ) ;
}
F_13 ( F_11 ( V_23 ) , V_1 -> V_36 ? V_23 -> V_40
: V_29 ) ;
V_23 -> V_26 = 0 ;
if ( V_32 != NULL && V_14 != V_33 ) {
if ( V_1 -> V_36 ) {
memcpy ( V_12 , V_23 -> V_40 , V_35 ) ;
} else {
if ( F_14 ( V_29 , V_32 , V_35 ) ) {
memset ( V_12 , 0 , V_33 ) ;
return - 1 ;
}
}
}
else if ( ! V_1 -> V_36 ) {
if ( F_14 ( V_29 , V_23 -> V_40 , V_23 -> V_41 ) )
return - 1 ;
}
}
return V_14 ;
}
static int F_15 ( T_1 * V_1 )
{
T_5 * V_23 = F_8 ( V_1 ) ;
if ( V_23 )
F_16 ( V_1 -> V_42 , sizeof( * V_1 ) + F_17 () ) ;
return 1 ;
}
static int F_18 ( T_1 * V_1 , int type , int V_43 ,
void * V_44 )
{
T_5 * V_23 = F_8 ( V_1 ) ;
switch( type ) {
case V_45 :
if ( V_23 == NULL )
V_23 = V_1 -> V_42
= F_19 ( sizeof( * V_23 ) + F_17 () ) ;
if ( V_23 == NULL ) {
F_20 ( V_46 , V_47 ) ;
return 0 ;
}
V_23 -> V_14 . V_24 = 0 ;
V_23 -> V_14 . V_25 = 0 ;
V_23 -> V_24 = 0 ;
V_23 -> V_26 = 0 ;
V_23 -> V_41 = 0 ;
V_23 -> V_30 = 12 ;
V_23 -> V_27 = V_28 ;
return 1 ;
case V_48 :
if ( V_23 ) {
T_1 * V_49 = ( T_1 * ) V_44 ;
V_49 -> V_42 =
F_21 ( V_23 , sizeof( * V_23 ) + F_17 () ) ;
if ( V_49 -> V_42 == NULL ) {
F_20 ( V_46 , V_50 ) ;
return 0 ;
}
}
return 1 ;
case V_51 :
if ( V_43 <= 0 || V_43 > V_5 )
return 0 ;
V_23 -> V_30 = V_43 ;
return 1 ;
case V_52 :
if ( V_43 != 12 )
return 0 ;
V_23 -> V_31 [ 0 ] = V_23 -> V_7 . V_10 [ 1 ]
= F_3 ( ( unsigned char * ) V_44 ) ;
V_23 -> V_31 [ 1 ] = V_23 -> V_7 . V_10 [ 2 ]
= F_3 ( ( unsigned char * ) V_44 + 4 ) ;
V_23 -> V_31 [ 2 ] = V_23 -> V_7 . V_10 [ 3 ]
= F_3 ( ( unsigned char * ) V_44 + 8 ) ;
return 1 ;
case V_53 :
if ( V_43 <= 0 || V_43 > V_35 )
return 0 ;
if ( V_44 != NULL ) {
memcpy ( V_23 -> V_40 , V_44 , V_43 ) ;
V_23 -> V_41 = V_43 ;
}
return 1 ;
case V_54 :
if ( V_43 <= 0 || V_43 > V_35 || ! V_1 -> V_36 )
return 0 ;
memcpy ( V_44 , V_23 -> V_40 , V_43 ) ;
return 1 ;
case V_55 :
if ( V_43 != V_56 )
return 0 ;
{
unsigned int V_14 ;
unsigned char * V_24 = V_44 , V_29 [ V_35 ] ;
V_14 = V_24 [ V_56 - 2 ] << 8 |
V_24 [ V_56 - 1 ] ;
if ( ! V_1 -> V_36 ) {
V_14 -= V_35 ;
memcpy ( V_29 , V_24 , V_56 - 2 ) ;
V_24 = V_29 ;
V_29 [ V_56 - 2 ] = ( unsigned char ) ( V_14 >> 8 ) ;
V_29 [ V_56 - 1 ] = ( unsigned char ) V_14 ;
}
V_23 -> V_27 = V_14 ;
V_23 -> V_7 . V_10 [ 1 ] = V_23 -> V_31 [ 0 ] ;
V_23 -> V_7 . V_10 [ 2 ] = V_23 -> V_31 [ 1 ] ^ F_3 ( V_24 ) ;
V_23 -> V_7 . V_10 [ 3 ] = V_23 -> V_31 [ 2 ] ^ F_3 ( V_24 + 4 ) ;
V_23 -> V_26 = 0 ;
F_9 ( V_1 , NULL , V_24 , V_56 ) ;
return V_35 ;
}
case V_57 :
return 1 ;
default:
return - 1 ;
}
}
const T_4 * F_22 ( void )
{
return ( & V_58 ) ;
}
