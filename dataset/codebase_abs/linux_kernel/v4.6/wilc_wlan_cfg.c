static int F_1 ( T_1 * V_1 , T_2 V_2 , T_3 V_3 , T_1 V_4 )
{
T_1 * V_5 ;
if ( ( V_2 + 4 ) >= V_6 )
return 0 ;
V_5 = & V_1 [ V_2 ] ;
V_5 [ 0 ] = ( T_1 ) V_3 ;
V_5 [ 1 ] = ( T_1 ) ( V_3 >> 8 ) ;
V_5 [ 2 ] = 1 ;
V_5 [ 3 ] = V_4 ;
return 4 ;
}
static int F_2 ( T_1 * V_1 , T_2 V_2 , T_3 V_3 , T_3 V_7 )
{
T_1 * V_5 ;
if ( ( V_2 + 5 ) >= V_6 )
return 0 ;
V_5 = & V_1 [ V_2 ] ;
V_5 [ 0 ] = ( T_1 ) V_3 ;
V_5 [ 1 ] = ( T_1 ) ( V_3 >> 8 ) ;
V_5 [ 2 ] = 2 ;
V_5 [ 3 ] = ( T_1 ) V_7 ;
V_5 [ 4 ] = ( T_1 ) ( V_7 >> 8 ) ;
return 5 ;
}
static int F_3 ( T_1 * V_1 , T_2 V_2 , T_3 V_3 , T_2 V_8 )
{
T_1 * V_5 ;
if ( ( V_2 + 7 ) >= V_6 )
return 0 ;
V_5 = & V_1 [ V_2 ] ;
V_5 [ 0 ] = ( T_1 ) V_3 ;
V_5 [ 1 ] = ( T_1 ) ( V_3 >> 8 ) ;
V_5 [ 2 ] = 4 ;
V_5 [ 3 ] = ( T_1 ) V_8 ;
V_5 [ 4 ] = ( T_1 ) ( V_8 >> 8 ) ;
V_5 [ 5 ] = ( T_1 ) ( V_8 >> 16 ) ;
V_5 [ 6 ] = ( T_1 ) ( V_8 >> 24 ) ;
return 7 ;
}
static int F_4 ( T_1 * V_1 , T_2 V_2 , T_3 V_3 , T_1 * V_9 , T_2 V_10 )
{
T_1 * V_5 ;
if ( ( V_2 + V_10 + 3 ) >= V_6 )
return 0 ;
V_5 = & V_1 [ V_2 ] ;
V_5 [ 0 ] = ( T_1 ) V_3 ;
V_5 [ 1 ] = ( T_1 ) ( V_3 >> 8 ) ;
V_5 [ 2 ] = ( T_1 ) V_10 ;
if ( ( V_9 != NULL ) && ( V_10 != 0 ) )
memcpy ( & V_5 [ 3 ] , V_9 , V_10 ) ;
return ( V_10 + 3 ) ;
}
static int F_5 ( T_1 * V_1 , T_2 V_2 , T_3 V_3 , T_1 * V_11 , T_2 V_10 )
{
T_1 * V_5 ;
T_2 V_12 ;
T_1 V_13 = 0 ;
if ( ( V_2 + V_10 + 5 ) >= V_6 )
return 0 ;
V_5 = & V_1 [ V_2 ] ;
V_5 [ 0 ] = ( T_1 ) V_3 ;
V_5 [ 1 ] = ( T_1 ) ( V_3 >> 8 ) ;
V_5 [ 2 ] = ( T_1 ) V_10 ;
V_5 [ 3 ] = ( T_1 ) ( V_10 >> 8 ) ;
if ( ( V_11 != NULL ) && ( V_10 != 0 ) ) {
memcpy ( & V_5 [ 4 ] , V_11 , V_10 ) ;
for ( V_12 = 0 ; V_12 < V_10 ; V_12 ++ ) {
V_13 += V_5 [ V_12 + 4 ] ;
}
}
V_5 [ V_10 + 4 ] = V_13 ;
return ( V_10 + 5 ) ;
}
static void F_6 ( T_1 * V_14 , int V_10 )
{
T_2 V_15 , V_16 = 0 , V_12 = 0 ;
while ( V_10 > 0 ) {
V_12 = 0 ;
V_15 = V_14 [ 0 ] | ( V_14 [ 1 ] << 8 ) ;
V_15 = F_7 ( V_15 ) ;
switch ( ( V_15 >> 12 ) & 0x7 ) {
case V_17 :
do {
if ( V_18 [ V_12 ] . V_3 == V_19 )
break;
if ( V_18 [ V_12 ] . V_3 == V_15 ) {
V_18 [ V_12 ] . V_20 = V_14 [ 3 ] ;
break;
}
V_12 ++ ;
} while ( 1 );
V_16 = 2 ;
break;
case V_21 :
do {
if ( V_22 [ V_12 ] . V_3 == V_19 )
break;
if ( V_22 [ V_12 ] . V_3 == V_15 ) {
V_22 [ V_12 ] . V_20 = F_8 ( V_14 [ 3 ] | ( V_14 [ 4 ] << 8 ) ) ;
break;
}
V_12 ++ ;
} while ( 1 );
V_16 = 3 ;
break;
case V_23 :
do {
if ( V_24 [ V_12 ] . V_3 == V_19 )
break;
if ( V_24 [ V_12 ] . V_3 == V_15 ) {
V_24 [ V_12 ] . V_20 = F_7 ( V_14 [ 3 ] | ( V_14 [ 4 ] << 8 ) | ( V_14 [ 5 ] << 16 ) | ( V_14 [ 6 ] << 24 ) ) ;
break;
}
V_12 ++ ;
} while ( 1 );
V_16 = 5 ;
break;
case V_25 :
do {
if ( V_26 [ V_12 ] . V_3 == V_19 )
break;
if ( V_26 [ V_12 ] . V_3 == V_15 ) {
if ( V_15 == V_27 ) {
static int V_28 ;
V_12 += V_28 ;
V_28 ^= 1 ;
}
memcpy ( V_26 [ V_12 ] . V_9 , & V_14 [ 2 ] , ( V_14 [ 2 ] + 1 ) ) ;
break;
}
V_12 ++ ;
} while ( 1 );
V_16 = 1 + V_14 [ 2 ] ;
break;
default:
break;
}
V_10 -= ( 2 + V_16 ) ;
V_14 += ( 2 + V_16 ) ;
}
}
static int F_9 ( T_1 * V_14 , int V_10 )
{
struct V_29 * V_30 = & V_31 ;
T_2 V_15 , V_16 ;
int type = V_32 ;
V_15 = V_14 [ 0 ] | ( V_14 [ 1 ] << 8 ) ;
V_16 = V_14 [ 2 ] ;
if ( ( V_16 == 1 ) && ( V_15 == V_33 ) ) {
V_30 -> V_34 = V_14 [ 3 ] ;
type = V_32 ;
}
return type ;
}
int F_10 ( T_1 * V_1 , T_2 V_2 , T_3 V_3 , T_1 * V_5 , int V_10 )
{
T_1 type = ( V_3 >> 12 ) & 0xf ;
int V_35 = 0 ;
switch ( type ) {
case V_36 :
if ( V_10 >= 1 )
V_35 = F_1 ( V_1 , V_2 , V_3 , * V_5 ) ;
break;
case V_37 :
if ( V_10 >= 2 )
V_35 = F_2 ( V_1 , V_2 , V_3 ,
* ( ( T_3 * ) V_5 ) ) ;
break;
case V_38 :
if ( V_10 >= 4 )
V_35 = F_3 ( V_1 , V_2 , V_3 ,
* ( ( T_2 * ) V_5 ) ) ;
break;
case V_39 :
V_35 = F_4 ( V_1 , V_2 , V_3 , V_5 , V_10 ) ;
break;
case V_40 :
V_35 = F_5 ( V_1 , V_2 , V_3 , V_5 , V_10 ) ;
break;
}
return V_35 ;
}
int F_11 ( T_1 * V_1 , T_2 V_2 , T_3 V_3 )
{
T_1 * V_5 ;
if ( ( V_2 + 2 ) >= V_6 )
return 0 ;
V_5 = & V_1 [ V_2 ] ;
V_5 [ 0 ] = ( T_1 ) V_3 ;
V_5 [ 1 ] = ( T_1 ) ( V_3 >> 8 ) ;
return 2 ;
}
int F_12 ( T_3 V_15 , T_1 * V_41 , T_2 V_42 )
{
T_2 type = ( V_15 >> 12 ) & 0xf ;
int V_12 , V_35 = 0 ;
if ( V_15 == V_33 ) {
* ( ( T_2 * ) V_41 ) = V_31 . V_34 ;
return 4 ;
}
V_12 = 0 ;
if ( type == V_36 ) {
do {
if ( V_18 [ V_12 ] . V_3 == V_19 )
break;
if ( V_18 [ V_12 ] . V_3 == V_15 ) {
memcpy ( V_41 , & V_18 [ V_12 ] . V_20 , 1 ) ;
V_35 = 1 ;
break;
}
V_12 ++ ;
} while ( 1 );
} else if ( type == V_37 ) {
do {
if ( V_22 [ V_12 ] . V_3 == V_19 )
break;
if ( V_22 [ V_12 ] . V_3 == V_15 ) {
memcpy ( V_41 , & V_22 [ V_12 ] . V_20 , 2 ) ;
V_35 = 2 ;
break;
}
V_12 ++ ;
} while ( 1 );
} else if ( type == V_38 ) {
do {
if ( V_24 [ V_12 ] . V_3 == V_19 )
break;
if ( V_24 [ V_12 ] . V_3 == V_15 ) {
memcpy ( V_41 , & V_24 [ V_12 ] . V_20 , 4 ) ;
V_35 = 4 ;
break;
}
V_12 ++ ;
} while ( 1 );
} else if ( type == V_39 ) {
do {
if ( V_26 [ V_12 ] . V_3 == V_19 )
break;
if ( V_26 [ V_12 ] . V_3 == V_15 ) {
T_2 V_10 = V_26 [ V_12 ] . V_9 [ 0 ] ;
if ( V_42 >= V_10 ) {
if ( V_26 [ V_12 ] . V_3 == V_27 ) {
static int V_28 ;
V_12 += V_28 ;
V_28 ^= 1 ;
}
memcpy ( V_41 , & V_26 [ V_12 ] . V_9 [ 1 ] , V_10 ) ;
V_35 = V_10 ;
}
break;
}
V_12 ++ ;
} while ( 1 );
}
return V_35 ;
}
int F_13 ( struct V_43 * V_43 , T_1 * V_1 , int V_10 ,
struct V_44 * V_45 )
{
int V_35 = 1 ;
T_1 V_46 ;
T_1 V_47 ;
V_46 = V_1 [ 0 ] ;
V_47 = V_1 [ 1 ] ;
V_1 += 4 ;
V_10 -= 4 ;
switch ( V_46 ) {
case 'R' :
F_6 ( V_1 , V_10 ) ;
V_45 -> type = V_48 ;
V_45 -> V_49 = V_47 ;
break;
case 'I' :
V_45 -> type = F_9 ( V_1 , V_10 ) ;
V_45 -> V_49 = V_47 ;
F_14 ( V_43 , V_1 - 4 , V_10 + 4 ) ;
break;
case 'N' :
F_15 ( V_43 , V_1 - 4 , V_10 + 4 ) ;
V_45 -> type = 0 ;
break;
case 'S' :
F_16 ( V_43 , V_1 - 4 , V_10 + 4 ) ;
break;
default:
V_45 -> type = 0 ;
V_45 -> V_49 = V_47 ;
V_35 = 0 ;
break;
}
return V_35 ;
}
int F_17 ( void )
{
memset ( ( void * ) & V_31 , 0 , sizeof( struct V_29 ) ) ;
return 1 ;
}
