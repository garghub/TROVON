static int F_1 ( struct V_1 * V_2 ,
enum V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
T_1 V_8 = V_9 , V_10 [ 3 ] ;
F_2 ( V_6 -> V_11 , & V_8 , 1 , V_10 , 3 , 0 ) ;
switch ( V_10 [ 0 ] ) {
case 0x01 :
* V_4 = V_12 | V_13 |
V_14 | V_15 | V_16 ;
break;
case 0x00 :
* V_4 = V_17 ;
break;
default:
case 0x02 :
* V_4 = 0 ;
break;
}
return 0 ;
}
static int F_3 ( struct V_1 * V_2 , T_2 * V_18 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
T_1 V_19 = V_20 , V_10 [ 3 ] ;
F_2 ( V_6 -> V_11 , & V_19 , 1 , V_10 , 3 , 0 ) ;
* V_18 = ( V_10 [ 0 ] << 16 ) | ( V_10 [ 1 ] << 8 ) | V_10 [ 2 ] ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 , T_2 * V_21 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
T_1 V_19 = V_22 , V_10 [ 2 ] ;
F_2 ( V_6 -> V_11 , & V_19 , 1 , V_10 , 2 , 0 ) ;
* V_21 = ( V_10 [ 0 ] << 8 ) | V_10 [ 1 ] ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 , T_3 * V_23 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
T_1 V_19 = V_24 , V_10 ;
F_2 ( V_6 -> V_11 , & V_19 , 1 , & V_10 , 1 , 0 ) ;
* V_23 = ( V_10 << 8 ) | V_10 ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 , T_3 * V_25 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
T_1 V_19 = V_26 , V_27 ;
F_2 ( V_6 -> V_11 , & V_19 , 1 , & V_27 , 1 , 0 ) ;
* V_25 = ~ ( ( V_27 << 8 ) | V_27 ) ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
T_1 V_10 = V_28 ;
return F_8 ( V_6 -> V_11 , & V_10 , 1 ) ;
}
static int F_9 ( struct V_1 * V_2 )
{
return F_7 ( V_2 ) ;
}
static int F_10 ( struct V_1 * V_2 , struct V_29 * V_30 )
{
V_30 -> V_31 = 1500 ;
V_30 -> V_32 = 0 ;
V_30 -> V_33 = 0 ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 )
{
struct V_34 * V_35 = & V_2 -> V_36 ;
struct V_5 * V_6 = V_2 -> V_7 ;
int V_37 ;
enum V_3 V_8 ;
T_3 V_38 = V_35 -> V_39 / 250000 ;
T_1 V_40 [ 2 ] = { V_41 , 0 } , V_42 [ 3 ] = { V_43 , 0 , 0 } ;
switch ( V_35 -> V_44 ) {
case 8000000 :
V_40 [ 1 ] = 8 ;
break;
case 7000000 :
V_40 [ 1 ] = 7 ;
break;
case 6000000 :
V_40 [ 1 ] = 6 ;
break;
default:
return - V_45 ;
}
F_8 ( V_6 -> V_11 , V_40 , 2 ) ;
V_42 [ 1 ] = V_38 & 0xff ;
V_42 [ 2 ] = ( V_38 >> 8 ) & 0xff ;
F_8 ( V_6 -> V_11 , V_42 , 3 ) ;
for ( V_37 = 0 ; V_37 < 30 ; V_37 ++ ) {
F_12 ( 20 ) ;
F_1 ( V_2 , & V_8 ) ;
if ( V_8 & V_17 )
continue;
}
return 0 ;
}
static int F_13 ( struct V_1 * V_2 ,
struct V_34 * V_35 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
memcpy ( V_35 , & V_6 -> V_35 , sizeof( struct V_34 ) ) ;
return 0 ;
}
static void F_14 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = (struct V_5 * ) V_2 -> V_7 ;
F_15 ( V_6 ) ;
}
struct V_1 * F_16 ( struct V_46 * V_11 )
{
struct V_5 * V_6 = NULL ;
V_6 = F_17 ( sizeof( struct V_5 ) , V_47 ) ;
if ( V_6 == NULL )
goto error;
F_18 ( L_1 ) ;
V_6 -> V_11 = V_11 ;
memcpy ( & V_6 -> V_48 . V_49 , & V_50 , sizeof( struct V_51 ) ) ;
V_6 -> V_48 . V_7 = V_6 ;
return & V_6 -> V_48 ;
error:
return NULL ;
}
