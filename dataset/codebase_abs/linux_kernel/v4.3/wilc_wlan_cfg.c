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
static int V_17 ;
while ( V_10 > 0 ) {
V_12 = 0 ;
V_15 = V_14 [ 0 ] | ( V_14 [ 1 ] << 8 ) ;
#ifdef F_7
V_15 = F_8 ( V_15 ) ;
#endif
F_9 ( V_18 , L_1 , V_15 , V_17 ++ ) ;
switch ( ( V_15 >> 12 ) & 0x7 ) {
case V_19 :
do {
if ( V_20 [ V_12 ] . V_3 == V_21 )
break;
if ( V_20 [ V_12 ] . V_3 == V_15 ) {
V_20 [ V_12 ] . V_22 = V_14 [ 3 ] ;
break;
}
V_12 ++ ;
} while ( 1 );
V_16 = 2 ;
break;
case V_23 :
do {
if ( V_24 [ V_12 ] . V_3 == V_21 )
break;
if ( V_24 [ V_12 ] . V_3 == V_15 ) {
#ifdef F_7
V_24 [ V_12 ] . V_22 = ( V_14 [ 3 ] << 8 ) | ( V_14 [ 4 ] ) ;
#else
V_24 [ V_12 ] . V_22 = V_14 [ 3 ] | ( V_14 [ 4 ] << 8 ) ;
#endif
break;
}
V_12 ++ ;
} while ( 1 );
V_16 = 3 ;
break;
case V_25 :
do {
if ( V_26 [ V_12 ] . V_3 == V_21 )
break;
if ( V_26 [ V_12 ] . V_3 == V_15 ) {
#ifdef F_7
V_26 [ V_12 ] . V_22 = ( V_14 [ 3 ] << 24 ) | ( V_14 [ 4 ] << 16 ) | ( V_14 [ 5 ] << 8 ) | ( V_14 [ 6 ] ) ;
#else
V_26 [ V_12 ] . V_22 = V_14 [ 3 ] | ( V_14 [ 4 ] << 8 ) | ( V_14 [ 5 ] << 16 ) | ( V_14 [ 6 ] << 24 ) ;
#endif
break;
}
V_12 ++ ;
} while ( 1 );
V_16 = 5 ;
break;
case V_27 :
do {
if ( V_28 [ V_12 ] . V_3 == V_21 )
break;
if ( V_28 [ V_12 ] . V_3 == V_15 ) {
if ( V_15 == V_29 ) {
static int V_30 ;
F_9 ( V_18 , L_2 ,
V_10 ) ;
F_9 ( V_18 , L_3 , V_10 , V_30 ) ;
V_12 += V_30 ;
V_30 ^= 1 ;
}
memcpy ( V_28 [ V_12 ] . V_9 , & V_14 [ 2 ] , ( V_14 [ 2 ] + 1 ) ) ;
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
static int F_10 ( T_1 * V_14 , int V_10 )
{
T_4 * V_31 = ( T_4 * ) & V_32 ;
T_2 V_15 , V_16 ;
int type = V_33 ;
V_15 = V_14 [ 0 ] | ( V_14 [ 1 ] << 8 ) ;
V_16 = V_14 [ 2 ] ;
F_9 ( V_18 , L_4 , V_16 , V_15 ) ;
if ( ( V_16 == 1 ) && ( V_15 == V_34 ) ) {
V_31 -> V_35 = V_14 [ 3 ] ;
type = V_33 ;
}
return type ;
}
static int F_11 ( T_1 * V_1 , T_2 V_2 , T_3 V_3 , T_1 * V_5 , int V_10 )
{
T_1 type = ( V_3 >> 12 ) & 0xf ;
int V_36 = 0 ;
if ( type == 0 ) {
if ( V_10 >= 1 )
V_36 = F_1 ( V_1 , V_2 , V_3 , * V_5 ) ;
} else if ( type == 1 ) {
if ( V_10 >= 2 )
V_36 = F_2 ( V_1 , V_2 , V_3 , * ( ( T_3 * ) V_5 ) ) ;
} else if ( type == 2 ) {
if ( V_10 >= 4 )
V_36 = F_3 ( V_1 , V_2 , V_3 , * ( ( T_2 * ) V_5 ) ) ;
} else if ( type == 3 ) {
V_36 = F_4 ( V_1 , V_2 , V_3 , V_5 , V_10 ) ;
} else if ( type == 4 ) {
V_36 = F_5 ( V_1 , V_2 , V_3 , V_5 , V_10 ) ;
} else {
V_32 . V_37 ( V_38 , L_5 ) ;
}
return V_36 ;
}
static int F_12 ( T_1 * V_1 , T_2 V_2 , T_3 V_3 )
{
T_1 * V_5 ;
if ( ( V_2 + 2 ) >= V_6 )
return 0 ;
V_5 = & V_1 [ V_2 ] ;
V_5 [ 0 ] = ( T_1 ) V_3 ;
V_5 [ 1 ] = ( T_1 ) ( V_3 >> 8 ) ;
return 2 ;
}
static int F_13 ( T_3 V_15 , T_1 * V_39 , T_2 V_40 )
{
T_2 type = ( V_15 >> 12 ) & 0xf ;
int V_12 , V_36 = 0 ;
if ( V_15 == V_34 ) {
* ( ( T_2 * ) V_39 ) = V_32 . V_35 ;
return 4 ;
}
V_12 = 0 ;
if ( type == 0 ) {
do {
if ( V_20 [ V_12 ] . V_3 == V_21 )
break;
if ( V_20 [ V_12 ] . V_3 == V_15 ) {
memcpy ( V_39 , & V_20 [ V_12 ] . V_22 , 1 ) ;
V_36 = 1 ;
break;
}
V_12 ++ ;
} while ( 1 );
} else if ( type == 1 ) {
do {
if ( V_24 [ V_12 ] . V_3 == V_21 )
break;
if ( V_24 [ V_12 ] . V_3 == V_15 ) {
memcpy ( V_39 , & V_24 [ V_12 ] . V_22 , 2 ) ;
V_36 = 2 ;
break;
}
V_12 ++ ;
} while ( 1 );
} else if ( type == 2 ) {
do {
if ( V_26 [ V_12 ] . V_3 == V_21 )
break;
if ( V_26 [ V_12 ] . V_3 == V_15 ) {
memcpy ( V_39 , & V_26 [ V_12 ] . V_22 , 4 ) ;
V_36 = 4 ;
break;
}
V_12 ++ ;
} while ( 1 );
} else if ( type == 3 ) {
do {
if ( V_28 [ V_12 ] . V_3 == V_21 )
break;
if ( V_28 [ V_12 ] . V_3 == V_15 ) {
T_2 V_10 = V_28 [ V_12 ] . V_9 [ 0 ] ;
if ( V_40 >= V_10 ) {
if ( V_28 [ V_12 ] . V_3 == V_29 ) {
static int V_30 ;
F_9 ( V_18 , L_6 ,
V_10 ) ;
V_12 += V_30 ;
V_30 ^= 1 ;
}
memcpy ( V_39 , & V_28 [ V_12 ] . V_9 [ 1 ] , V_10 ) ;
V_36 = V_10 ;
}
break;
}
V_12 ++ ;
} while ( 1 );
} else {
V_32 . V_37 ( V_38 , L_7 , V_15 ) ;
}
return V_36 ;
}
static int F_14 ( T_1 * V_1 , int V_10 , T_5 * V_41 )
{
int V_36 = 1 ;
T_1 V_42 ;
T_1 V_43 ;
#ifdef F_15
T_6 * V_44 ;
bool V_45 = V_1 [ 2 ] ;
#ifdef F_7
V_44 = ( V_1 [ 4 ] << 24 ) | ( V_1 [ 5 ] << 16 ) | ( V_1 [ 6 ] << 8 ) | V_1 [ 7 ] ;
#else
V_44 = ( V_1 [ 7 ] << 24 ) | ( V_1 [ 6 ] << 16 ) | ( V_1 [ 5 ] << 8 ) | V_1 [ 4 ] ;
#endif
#endif
V_42 = V_1 [ 0 ] ;
V_43 = V_1 [ 1 ] ;
V_1 += 4 ;
V_10 -= 4 ;
switch ( V_42 ) {
case 'R' :
F_6 ( V_1 , V_10 ) ;
V_41 -> type = V_46 ;
V_41 -> V_47 = V_43 ;
break;
case 'I' :
V_41 -> type = F_10 ( V_1 , V_10 ) ;
V_41 -> V_47 = V_43 ;
F_9 ( V_48 , L_8 ) ;
F_16 ( V_1 - 4 , V_10 + 4 ) ;
break;
case 'L' :
#ifndef F_17
F_18 ( L_9 ) ;
#else
F_19 ( V_49 , L_10 , V_1 ) ;
break;
#endif
#if 1
case 'N' :
F_20 ( V_1 - 4 , V_10 + 4 ) ;
V_41 -> type = 0 ;
break;
#endif
case 'S' :
F_9 ( V_48 , L_11 ) ;
F_21 ( V_1 - 4 , V_10 + 4 ) ;
break;
#ifdef F_15
case 'T' :
F_9 ( V_48 , L_12 ) ;
F_22 () ;
break;
case 'A' :
F_9 ( V_48 , L_13 ) ;
F_23 ( V_44 , V_45 ) ;
break;
#endif
default:
F_9 ( V_48 , L_14 ,
V_1 [ 0 ] , V_1 [ 1 ] , V_1 [ 2 ] , V_1 [ 3 ] , V_1 [ 4 ] ,
V_1 [ 5 ] , V_1 [ 6 ] , V_1 [ 7 ] ) ;
V_41 -> type = 0 ;
V_41 -> V_47 = V_43 ;
V_36 = 0 ;
break;
}
return V_36 ;
}
static int F_24 ( T_7 V_50 )
{
memset ( ( void * ) & V_32 , 0 , sizeof( T_4 ) ) ;
V_32 . V_37 = V_50 ;
return 1 ;
}
