static int F_1 ( struct V_1 * V_2 ,
T_1 * V_3 )
{
* V_3 = V_4 | V_5 |
V_6 | V_7 | V_8 ;
return 0 ;
}
static int F_2 ( struct V_1 * V_2 ,
T_1 * V_3 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
T_2 V_12 [] = { 0x00 , 0x00 , 0x00 , 0x00 ,
0x00 , 0x00 , 0x00 , 0x00 } ;
T_2 V_13 [ 4 ] ;
int V_14 , V_15 ;
* V_3 = 0 ;
V_15 = V_10 -> V_16 -> V_17 ( V_2 , 0x73 , sizeof( V_12 ) , V_12 , & V_14 , V_13 ) ;
if( V_15 )
return V_15 ;
if( V_14 != 4 ) {
F_3 ( V_18 L_1 , V_19 ) ;
return - V_20 ;
}
switch( V_13 [ 3 ] ) {
case 1 :
case 2 :
break;
case 3 :
* V_3 = V_4 | V_5 |
V_6 | V_7 | V_8 ;
break;
case 4 :
* V_3 = V_21 ;
break;
default:
F_4 ( L_2 ,
V_19 , V_13 [ 3 ] ) ;
return - V_20 ;
}
return 0 ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_22 * V_23 = & V_2 -> V_24 ;
struct V_9 * V_10 = (struct V_9 * ) V_2 -> V_11 ;
T_2 V_12 [] = { 0x00 , 0x00 , 0x00 , 0x03 ,
0x00 , 0x00 , 0x00 , 0x00 ,
0x00 , 0x00 , 0x00 , 0x01 ,
0x00 , 0x00 , 0x00 , 0xff ,
0x00 , 0x00 , 0x00 , 0xff } ;
T_3 V_25 = F_6 ( V_23 -> V_26 / 1000 ) ;
memcpy ( & V_12 [ 4 ] , & V_25 , sizeof ( V_27 ) ) ;
V_10 -> V_16 -> V_17 ( V_2 , 0x71 , sizeof( V_12 ) , V_12 , NULL , NULL ) ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_28 * V_29 )
{
V_29 -> V_30 = 1500 ;
V_29 -> V_31 = 0 ;
V_29 -> V_32 = 0 ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 )
{
struct V_22 * V_23 = & V_2 -> V_24 ;
struct V_9 * V_10 = (struct V_9 * ) V_2 -> V_11 ;
T_2 V_12 [] = { 0x00 , 0x00 , 0x00 , 0x01 ,
0x00 , 0x00 , 0x00 , 0x00 ,
0x00 , 0x00 , 0x00 , 0x01 ,
0x00 , 0x00 , 0x00 , 0x00 ,
0x00 , 0x00 , 0x00 , 0x00 ,
0x00 , 0x00 , 0x00 , 0x00 ,
0x00 , 0x00 , 0x00 , 0x00 ,
0x00 , 0x00 , 0x00 , 0x00 ,
0x00 , 0x00 , 0x00 , 0x00 ,
0x00 , 0x00 , 0x00 , 0x00 } ;
T_3 V_25 ;
T_3 V_33 ;
T_3 V_34 ;
T_3 V_35 ;
V_25 = F_6 ( V_23 -> V_26 +
( V_10 -> V_36 ? V_37 : V_38 ) ) ;
memcpy ( & V_12 [ 4 ] , & V_25 , sizeof( V_27 ) ) ;
V_33 = F_6 ( V_23 -> V_39 ) ;
memcpy ( & V_12 [ 12 ] , & V_33 , sizeof( V_27 ) ) ;
V_34 = F_6 ( V_10 -> V_36 ? V_37 : V_38 ) ;
memcpy ( & V_12 [ 24 ] , & V_34 , sizeof( V_27 ) ) ;
V_35 = F_6 ( V_10 -> V_40 ) ;
memcpy ( & V_12 [ 28 ] , & V_35 , sizeof( V_27 ) ) ;
V_10 -> V_16 -> V_17 ( V_2 , 0x71 , sizeof( V_12 ) , V_12 , NULL , NULL ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 , struct V_41 * V_42 )
{
struct V_9 * V_10 = (struct V_9 * ) V_2 -> V_11 ;
T_2 V_12 [] = { 0x00 , 0xff , 0x00 , 0x00 ,
0x00 , 0x00 , 0x00 , 0x00 ,
0x00 , 0x00 } ;
memcpy ( & V_12 [ 4 ] , V_42 -> V_43 , V_42 -> V_44 ) ;
V_10 -> V_16 -> V_17 ( V_2 , 0x72 ,
sizeof( V_12 ) - ( 6 - V_42 -> V_44 ) , V_12 ,
NULL , NULL ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 , T_4 V_45 )
{
struct V_9 * V_10 = (struct V_9 * ) V_2 -> V_11 ;
V_10 -> V_36 = ( V_46 == V_45 ) ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 , T_5 V_40 )
{
struct V_9 * V_10 = (struct V_9 * ) V_2 -> V_11 ;
switch ( V_40 ) {
case V_47 :
V_10 -> V_40 = 13 ;
break;
case V_48 :
V_10 -> V_40 = 18 ;
break;
default:
return - V_49 ;
}
return 0 ;
}
static void F_12 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = (struct V_9 * ) V_2 -> V_11 ;
F_13 ( V_10 ) ;
}
struct V_1 * F_14 ( const struct V_50 * V_16 )
{
struct V_9 * V_10 = NULL ;
V_10 = F_15 ( sizeof( struct V_9 ) , V_51 ) ;
if ( V_10 == NULL )
return NULL ;
V_10 -> V_16 = V_16 ;
memcpy ( & V_10 -> V_52 . V_53 , & V_54 , sizeof( struct V_55 ) ) ;
V_10 -> V_52 . V_11 = V_10 ;
return & V_10 -> V_52 ;
}
struct V_1 * F_16 ( const struct V_50 * V_16 )
{
struct V_9 * V_10 = NULL ;
V_10 = F_15 ( sizeof( struct V_9 ) , V_51 ) ;
if ( V_10 == NULL )
return NULL ;
V_10 -> V_16 = V_16 ;
V_10 -> V_40 = 0 ;
V_10 -> V_36 = 0 ;
memcpy ( & V_10 -> V_52 . V_53 , & V_56 , sizeof( struct V_55 ) ) ;
V_10 -> V_52 . V_11 = V_10 ;
return & V_10 -> V_52 ;
}
