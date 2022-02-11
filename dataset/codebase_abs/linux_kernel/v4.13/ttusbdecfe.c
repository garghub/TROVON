static int F_1 ( struct V_1 * V_2 ,
enum V_3 * V_4 )
{
* V_4 = V_5 | V_6 |
V_7 | V_8 | V_9 ;
return 0 ;
}
static int F_2 ( struct V_1 * V_2 ,
enum V_3 * V_4 )
{
struct V_10 * V_11 = V_2 -> V_12 ;
T_1 V_13 [] = { 0x00 , 0x00 , 0x00 , 0x00 ,
0x00 , 0x00 , 0x00 , 0x00 } ;
T_1 V_14 [ 4 ] ;
int V_15 , V_16 ;
* V_4 = 0 ;
V_16 = V_11 -> V_17 -> V_18 ( V_2 , 0x73 , sizeof( V_13 ) , V_13 , & V_15 , V_14 ) ;
if( V_16 )
return V_16 ;
if( V_15 != 4 ) {
F_3 ( V_19 L_1 , V_20 ) ;
return - V_21 ;
}
switch( V_14 [ 3 ] ) {
case 1 :
case 2 :
break;
case 3 :
* V_4 = V_5 | V_6 |
V_7 | V_8 | V_9 ;
break;
case 4 :
* V_4 = V_22 ;
break;
default:
F_4 ( L_2 ,
V_20 , V_14 [ 3 ] ) ;
return - V_21 ;
}
return 0 ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_23 * V_24 = & V_2 -> V_25 ;
struct V_10 * V_11 = (struct V_10 * ) V_2 -> V_12 ;
T_1 V_13 [] = { 0x00 , 0x00 , 0x00 , 0x03 ,
0x00 , 0x00 , 0x00 , 0x00 ,
0x00 , 0x00 , 0x00 , 0x01 ,
0x00 , 0x00 , 0x00 , 0xff ,
0x00 , 0x00 , 0x00 , 0xff } ;
T_2 V_26 = F_6 ( V_24 -> V_27 / 1000 ) ;
memcpy ( & V_13 [ 4 ] , & V_26 , sizeof ( V_28 ) ) ;
V_11 -> V_17 -> V_18 ( V_2 , 0x71 , sizeof( V_13 ) , V_13 , NULL , NULL ) ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_29 * V_30 )
{
V_30 -> V_31 = 1500 ;
V_30 -> V_32 = 0 ;
V_30 -> V_33 = 0 ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 )
{
struct V_23 * V_24 = & V_2 -> V_25 ;
struct V_10 * V_11 = (struct V_10 * ) V_2 -> V_12 ;
T_1 V_13 [] = { 0x00 , 0x00 , 0x00 , 0x01 ,
0x00 , 0x00 , 0x00 , 0x00 ,
0x00 , 0x00 , 0x00 , 0x01 ,
0x00 , 0x00 , 0x00 , 0x00 ,
0x00 , 0x00 , 0x00 , 0x00 ,
0x00 , 0x00 , 0x00 , 0x00 ,
0x00 , 0x00 , 0x00 , 0x00 ,
0x00 , 0x00 , 0x00 , 0x00 ,
0x00 , 0x00 , 0x00 , 0x00 ,
0x00 , 0x00 , 0x00 , 0x00 } ;
T_2 V_26 ;
T_2 V_34 ;
T_2 V_35 ;
T_2 V_36 ;
V_26 = F_6 ( V_24 -> V_27 +
( V_11 -> V_37 ? V_38 : V_39 ) ) ;
memcpy ( & V_13 [ 4 ] , & V_26 , sizeof( V_28 ) ) ;
V_34 = F_6 ( V_24 -> V_40 ) ;
memcpy ( & V_13 [ 12 ] , & V_34 , sizeof( V_28 ) ) ;
V_35 = F_6 ( V_11 -> V_37 ? V_38 : V_39 ) ;
memcpy ( & V_13 [ 24 ] , & V_35 , sizeof( V_28 ) ) ;
V_36 = F_6 ( V_11 -> V_41 ) ;
memcpy ( & V_13 [ 28 ] , & V_36 , sizeof( V_28 ) ) ;
V_11 -> V_17 -> V_18 ( V_2 , 0x71 , sizeof( V_13 ) , V_13 , NULL , NULL ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 , struct V_42 * V_43 )
{
struct V_10 * V_11 = (struct V_10 * ) V_2 -> V_12 ;
T_1 V_13 [] = { 0x00 , 0xff , 0x00 , 0x00 ,
0x00 , 0x00 , 0x00 , 0x00 ,
0x00 , 0x00 } ;
if ( V_43 -> V_44 > sizeof( V_13 ) - 4 )
return - V_45 ;
memcpy ( & V_13 [ 4 ] , V_43 -> V_46 , V_43 -> V_44 ) ;
V_11 -> V_17 -> V_18 ( V_2 , 0x72 ,
sizeof( V_13 ) - ( 6 - V_43 -> V_44 ) , V_13 ,
NULL , NULL ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 ,
enum V_47 V_48 )
{
struct V_10 * V_11 = (struct V_10 * ) V_2 -> V_12 ;
V_11 -> V_37 = ( V_49 == V_48 ) ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 ,
enum V_50 V_41 )
{
struct V_10 * V_11 = (struct V_10 * ) V_2 -> V_12 ;
switch ( V_41 ) {
case V_51 :
V_11 -> V_41 = 13 ;
break;
case V_52 :
V_11 -> V_41 = 18 ;
break;
default:
return - V_45 ;
}
return 0 ;
}
static void F_12 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = (struct V_10 * ) V_2 -> V_12 ;
F_13 ( V_11 ) ;
}
struct V_1 * F_14 ( const struct V_53 * V_17 )
{
struct V_10 * V_11 = NULL ;
V_11 = F_15 ( sizeof( struct V_10 ) , V_54 ) ;
if ( V_11 == NULL )
return NULL ;
V_11 -> V_17 = V_17 ;
memcpy ( & V_11 -> V_55 . V_56 , & V_57 , sizeof( struct V_58 ) ) ;
V_11 -> V_55 . V_12 = V_11 ;
return & V_11 -> V_55 ;
}
struct V_1 * F_16 ( const struct V_53 * V_17 )
{
struct V_10 * V_11 = NULL ;
V_11 = F_15 ( sizeof( struct V_10 ) , V_54 ) ;
if ( V_11 == NULL )
return NULL ;
V_11 -> V_17 = V_17 ;
V_11 -> V_41 = 0 ;
V_11 -> V_37 = 0 ;
memcpy ( & V_11 -> V_55 . V_56 , & V_59 , sizeof( struct V_58 ) ) ;
V_11 -> V_55 . V_12 = V_11 ;
return & V_11 -> V_55 ;
}
