static unsigned int F_1 ( const T_1 * V_1 , unsigned int V_2 )
{
unsigned int V_3 , V_4 , V_5 , V_6 ;
V_6 = 0 ;
V_4 = 0 ;
V_5 = 0 ;
for ( V_3 = 0 ; V_3 < V_2 ; V_3 ++ )
if ( F_2 ( V_1 [ V_3 ] . V_4 ) == V_7 &&
( V_4 != F_3 ( V_1 [ V_3 ] . V_4 ) ||
V_5 != V_1 [ V_3 ] . V_5 ) ) {
V_6 ++ ;
V_4 = F_3 ( V_1 [ V_3 ] . V_4 ) ;
V_5 = V_1 [ V_3 ] . V_5 ;
}
#ifdef F_4
V_6 ++ ;
#endif
return V_6 ;
}
static int F_5 ( const void * V_8 , const void * V_9 )
{
const T_1 * V_10 , * V_11 ;
V_11 = ( T_1 * ) V_8 ;
V_10 = ( T_1 * ) V_9 ;
if ( V_10 -> V_4 < V_11 -> V_4 )
return - 1 ;
else if ( V_10 -> V_4 > V_11 -> V_4 )
return 1 ;
else if ( V_10 -> V_5 < V_11 -> V_5 )
return - 1 ;
else if ( V_10 -> V_5 > V_11 -> V_5 )
return 1 ;
else
return 0 ;
}
static void F_6 ( void * V_8 , void * V_9 , int V_12 )
{
T_2 * V_10 , * V_11 , V_13 ;
int V_3 ;
V_11 = ( T_2 * ) V_8 ;
V_10 = ( T_2 * ) V_9 ;
for ( V_3 = 0 ; V_3 < sizeof( T_1 ) / sizeof( T_2 ) ; V_3 ++ ) {
V_13 = V_10 [ V_3 ] ;
V_10 [ V_3 ] = V_11 [ V_3 ] ;
V_11 [ V_3 ] = V_13 ;
}
}
static unsigned long F_7 ( const T_3 * V_14 ,
const T_4 * V_15 ,
const char * V_16 ,
int V_17 )
{
unsigned long V_18 = 0 ;
unsigned V_3 ;
for ( V_3 = 1 ; V_3 < V_14 -> V_19 ; V_3 ++ ) {
if ( ( strstr ( V_16 + V_15 [ V_3 ] . V_20 , L_1 ) != 0 )
!= V_17 )
continue;
if ( strstr ( V_16 + V_15 [ V_3 ] . V_20 , L_2 ) != 0 )
continue;
if ( V_15 [ V_3 ] . V_21 == V_22 ) {
F_8 ( L_3 , V_3 ) ;
F_8 ( L_4 ,
( void * ) V_14 + V_15 [ V_3 ] . V_23 ,
V_15 [ V_3 ] . V_24 / sizeof( T_1 ) ) ;
F_9 ( ( void * ) V_14 + V_15 [ V_3 ] . V_23 ,
V_15 [ V_3 ] . V_24 / sizeof( T_1 ) ,
sizeof( T_1 ) , F_5 , F_6 ) ;
V_18 += F_1 ( ( void * ) V_14
+ V_15 [ V_3 ] . V_23 ,
V_15 [ V_3 ] . V_24
/ sizeof( T_1 ) )
* sizeof( struct V_25 ) ;
}
}
return V_18 ;
}
int F_10 ( T_3 * V_14 ,
T_4 * V_15 ,
char * V_16 ,
struct V_26 * V_27 )
{
unsigned int V_3 ;
for ( V_3 = 0 ; V_3 < V_14 -> V_19 ; V_3 ++ ) {
if ( strcmp ( V_16 + V_15 [ V_3 ] . V_20 , L_5 ) == 0 )
V_27 -> V_28 . V_29 = V_3 ;
else if ( strcmp ( V_16 + V_15 [ V_3 ] . V_20 , L_6 ) == 0 )
V_27 -> V_28 . V_30 = V_3 ;
}
if ( ! V_27 -> V_28 . V_30 || ! V_27 -> V_28 . V_29 ) {
F_11 ( L_7 ) ;
return - V_31 ;
}
V_15 [ V_27 -> V_28 . V_30 ] . V_24
= F_7 ( V_14 , V_15 , V_16 , 0 ) ;
V_15 [ V_27 -> V_28 . V_29 ] . V_24
= F_7 ( V_14 , V_15 , V_16 , 1 ) ;
return 0 ;
}
int F_12 ( T_4 * V_15 ,
const char * V_32 ,
unsigned int V_33 ,
unsigned int V_34 ,
struct V_26 * V_26 )
{
F_11 ( V_35 L_8 ,
V_26 -> V_36 ) ;
return - V_31 ;
}
static inline int F_13 ( struct V_25 * V_37 , T_5 V_38 )
{
if ( V_37 -> V_39 [ 0 ] == 0x3d600000 + ( ( V_38 + 0x8000 ) >> 16 )
&& V_37 -> V_39 [ 1 ] == 0x396b0000 + ( V_38 & 0xffff ) )
return 1 ;
return 0 ;
}
static T_2 F_14 ( void * V_40 ,
T_5 V_38 ,
T_4 * V_15 ,
struct V_26 * V_41 )
{
struct V_25 * V_37 ;
F_8 ( L_9 , V_38 , ( unsigned int ) V_40 ) ;
if ( V_40 >= V_41 -> V_42
&& V_40 < V_41 -> V_42 + V_41 -> V_43 )
V_37 = ( void * ) V_15 [ V_41 -> V_28 . V_30 ] . V_44 ;
else
V_37 = ( void * ) V_15 [ V_41 -> V_28 . V_29 ] . V_44 ;
while ( V_37 -> V_39 [ 0 ] ) {
if ( F_13 ( V_37 , V_38 ) ) return ( T_2 ) V_37 ;
V_37 ++ ;
}
V_37 -> V_39 [ 0 ] = 0x3d600000 + ( ( V_38 + 0x8000 ) >> 16 ) ;
V_37 -> V_39 [ 1 ] = 0x396b0000 + ( V_38 & 0xffff ) ;
V_37 -> V_39 [ 2 ] = 0x7d6903a6 ;
V_37 -> V_39 [ 3 ] = 0x4e800420 ;
F_8 ( L_10 , V_38 , V_37 ) ;
return ( T_2 ) V_37 ;
}
int F_15 ( T_4 * V_15 ,
const char * V_32 ,
unsigned int V_33 ,
unsigned int V_34 ,
struct V_26 * V_26 )
{
unsigned int V_3 ;
T_1 * V_1 = ( void * ) V_15 [ V_34 ] . V_44 ;
T_6 * V_45 ;
T_2 * V_40 ;
T_2 V_46 ;
F_8 ( L_11 , V_34 ,
V_15 [ V_34 ] . V_47 ) ;
for ( V_3 = 0 ; V_3 < V_15 [ V_34 ] . V_24 / sizeof( * V_1 ) ; V_3 ++ ) {
V_40 = ( void * ) V_15 [ V_15 [ V_34 ] . V_47 ] . V_44
+ V_1 [ V_3 ] . V_48 ;
V_45 = ( T_6 * ) V_15 [ V_33 ] . V_44
+ F_3 ( V_1 [ V_3 ] . V_4 ) ;
V_46 = V_45 -> V_49 + V_1 [ V_3 ] . V_5 ;
switch ( F_2 ( V_1 [ V_3 ] . V_4 ) ) {
case V_50 :
* ( T_2 * ) V_40 = V_46 ;
break;
case V_51 :
* ( V_52 * ) V_40 = V_46 ;
break;
case V_53 :
* ( V_52 * ) V_40 = ( V_46 >> 16 ) ;
break;
case V_54 :
* ( V_52 * ) V_40 = ( V_46 + 0x8000 ) >> 16 ;
break;
case V_7 :
if ( ( int ) ( V_46 - ( T_2 ) V_40 ) < - 0x02000000
|| ( int ) ( V_46 - ( T_2 ) V_40 ) >= 0x02000000 )
V_46 = F_14 ( V_40 , V_46 ,
V_15 , V_26 ) ;
F_8 ( L_12 ,
V_46 , ( T_2 ) V_40 ) ;
F_8 ( L_13 ,
* ( T_2 * ) V_40 ) ;
* ( T_2 * ) V_40
= ( * ( T_2 * ) V_40 & ~ 0x03fffffc )
| ( ( V_46 - ( T_2 ) V_40 )
& 0x03fffffc ) ;
F_8 ( L_14 ,
* ( T_2 * ) V_40 ) ;
F_8 ( L_15 ,
* ( T_2 * ) V_40 & 0x03fffffc ,
( T_2 ) V_40 ,
( * ( T_2 * ) V_40 & 0x03fffffc )
+ ( T_2 ) V_40 ) ;
break;
case V_55 :
* ( T_2 * ) V_40 = V_46 - ( T_2 ) V_40 ;
break;
default:
F_11 ( L_16 ,
V_26 -> V_36 ,
F_2 ( V_1 [ V_3 ] . V_4 ) ) ;
return - V_31 ;
}
}
#ifdef F_4
V_26 -> V_28 . V_56 =
F_14 ( V_26 -> V_42 ,
( unsigned long ) V_57 ,
V_15 , V_26 ) ;
#endif
return 0 ;
}
