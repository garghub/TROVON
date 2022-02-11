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
static int F_5 ( struct V_1 * V_2 , struct V_22 * V_23 )
{
struct V_9 * V_10 = (struct V_9 * ) V_2 -> V_11 ;
T_2 V_12 [] = { 0x00 , 0x00 , 0x00 , 0x03 ,
0x00 , 0x00 , 0x00 , 0x00 ,
0x00 , 0x00 , 0x00 , 0x01 ,
0x00 , 0x00 , 0x00 , 0xff ,
0x00 , 0x00 , 0x00 , 0xff } ;
T_3 V_24 = F_6 ( V_23 -> V_25 / 1000 ) ;
memcpy ( & V_12 [ 4 ] , & V_24 , sizeof ( V_26 ) ) ;
V_10 -> V_16 -> V_17 ( V_2 , 0x71 , sizeof( V_12 ) , V_12 , NULL , NULL ) ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_27 * V_28 )
{
V_28 -> V_29 = 1500 ;
V_28 -> V_30 = 0 ;
V_28 -> V_31 = 0 ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 , struct V_22 * V_23 )
{
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
T_3 V_24 ;
T_3 V_32 ;
T_3 V_33 ;
T_3 V_34 ;
V_24 = F_6 ( V_23 -> V_25 +
( V_10 -> V_35 ? V_36 : V_37 ) ) ;
memcpy ( & V_12 [ 4 ] , & V_24 , sizeof( V_26 ) ) ;
V_32 = F_6 ( V_23 -> V_38 . V_39 . V_40 ) ;
memcpy ( & V_12 [ 12 ] , & V_32 , sizeof( V_26 ) ) ;
V_33 = F_6 ( V_10 -> V_35 ? V_36 : V_37 ) ;
memcpy ( & V_12 [ 24 ] , & V_33 , sizeof( V_26 ) ) ;
V_34 = F_6 ( V_10 -> V_41 ) ;
memcpy ( & V_12 [ 28 ] , & V_34 , sizeof( V_26 ) ) ;
V_10 -> V_16 -> V_17 ( V_2 , 0x71 , sizeof( V_12 ) , V_12 , NULL , NULL ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 , struct V_42 * V_43 )
{
struct V_9 * V_10 = (struct V_9 * ) V_2 -> V_11 ;
T_2 V_12 [] = { 0x00 , 0xff , 0x00 , 0x00 ,
0x00 , 0x00 , 0x00 , 0x00 ,
0x00 , 0x00 } ;
memcpy ( & V_12 [ 4 ] , V_43 -> V_44 , V_43 -> V_45 ) ;
V_10 -> V_16 -> V_17 ( V_2 , 0x72 ,
sizeof( V_12 ) - ( 6 - V_43 -> V_45 ) , V_12 ,
NULL , NULL ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 , T_4 V_46 )
{
struct V_9 * V_10 = (struct V_9 * ) V_2 -> V_11 ;
V_10 -> V_35 = ( V_47 == V_46 ) ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 , T_5 V_41 )
{
struct V_9 * V_10 = (struct V_9 * ) V_2 -> V_11 ;
switch ( V_41 ) {
case V_48 :
V_10 -> V_41 = 13 ;
break;
case V_49 :
V_10 -> V_41 = 18 ;
break;
default:
return - V_50 ;
}
return 0 ;
}
static void F_12 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = (struct V_9 * ) V_2 -> V_11 ;
F_13 ( V_10 ) ;
}
struct V_1 * F_14 ( const struct V_51 * V_16 )
{
struct V_9 * V_10 = NULL ;
V_10 = F_15 ( sizeof( struct V_9 ) , V_52 ) ;
if ( V_10 == NULL )
return NULL ;
V_10 -> V_16 = V_16 ;
memcpy ( & V_10 -> V_53 . V_54 , & V_55 , sizeof( struct V_56 ) ) ;
V_10 -> V_53 . V_11 = V_10 ;
return & V_10 -> V_53 ;
}
struct V_1 * F_16 ( const struct V_51 * V_16 )
{
struct V_9 * V_10 = NULL ;
V_10 = F_15 ( sizeof( struct V_9 ) , V_52 ) ;
if ( V_10 == NULL )
return NULL ;
V_10 -> V_16 = V_16 ;
V_10 -> V_41 = 0 ;
V_10 -> V_35 = 0 ;
memcpy ( & V_10 -> V_53 . V_54 , & V_57 , sizeof( struct V_56 ) ) ;
V_10 -> V_53 . V_11 = V_10 ;
return & V_10 -> V_53 ;
}
