static int F_1 ( struct V_1 * V_2 , T_1 * V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
T_2 V_7 = V_8 , V_9 [ 3 ] ;
F_2 ( V_5 -> V_10 , & V_7 , 1 , V_9 , 3 , 0 ) ;
switch ( V_9 [ 0 ] ) {
case 0x01 :
* V_3 = V_11 | V_12 |
V_13 | V_14 | V_15 ;
break;
case 0x00 :
* V_3 = V_16 ;
break;
default:
case 0x02 :
* V_3 = 0 ;
break;
}
return 0 ;
}
static int F_3 ( struct V_1 * V_2 , T_3 * V_17 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
T_2 V_18 = V_19 , V_9 [ 3 ] ;
F_2 ( V_5 -> V_10 , & V_18 , 1 , V_9 , 3 , 0 ) ;
* V_17 = ( V_9 [ 0 ] << 16 ) | ( V_9 [ 1 ] << 8 ) | V_9 [ 2 ] ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 , T_3 * V_20 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
T_2 V_18 = V_21 , V_9 [ 2 ] ;
F_2 ( V_5 -> V_10 , & V_18 , 1 , V_9 , 2 , 0 ) ;
* V_20 = ( V_9 [ 0 ] << 8 ) | V_9 [ 1 ] ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 , T_4 * V_22 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
T_2 V_18 = V_23 , V_9 ;
F_2 ( V_5 -> V_10 , & V_18 , 1 , & V_9 , 1 , 0 ) ;
* V_22 = ( V_9 << 8 ) | V_9 ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 , T_4 * V_24 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
T_2 V_18 = V_25 , V_26 ;
F_2 ( V_5 -> V_10 , & V_18 , 1 , & V_26 , 1 , 0 ) ;
* V_24 = ~ ( ( V_26 << 8 ) | V_26 ) ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
T_2 V_9 = V_27 ;
return F_8 ( V_5 -> V_10 , & V_9 , 1 ) ;
}
static int F_9 ( struct V_1 * V_2 )
{
return F_7 ( V_2 ) ;
}
static int F_10 ( struct V_1 * V_2 , struct V_28 * V_29 )
{
V_29 -> V_30 = 1500 ;
V_29 -> V_31 = 0 ;
V_29 -> V_32 = 0 ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 )
{
struct V_33 * V_34 = & V_2 -> V_35 ;
struct V_4 * V_5 = V_2 -> V_6 ;
int V_36 ;
T_1 V_7 ;
T_4 V_37 = V_34 -> V_38 / 250000 ;
T_2 V_39 [ 2 ] = { V_40 , 0 } , V_41 [ 3 ] = { V_42 , 0 , 0 } ;
switch ( V_34 -> V_43 ) {
case 8000000 :
V_39 [ 1 ] = 8 ;
break;
case 7000000 :
V_39 [ 1 ] = 7 ;
break;
case 6000000 :
V_39 [ 1 ] = 6 ;
break;
default:
return - V_44 ;
}
F_8 ( V_5 -> V_10 , V_39 , 2 ) ;
V_41 [ 1 ] = V_37 & 0xff ;
V_41 [ 2 ] = ( V_37 >> 8 ) & 0xff ;
F_8 ( V_5 -> V_10 , V_41 , 3 ) ;
for ( V_36 = 0 ; V_36 < 30 ; V_36 ++ ) {
F_12 ( 20 ) ;
F_1 ( V_2 , & V_7 ) ;
if ( V_7 & V_16 )
continue;
}
return 0 ;
}
static int F_13 ( struct V_1 * V_2 )
{
struct V_33 * V_34 = & V_2 -> V_35 ;
struct V_4 * V_5 = V_2 -> V_6 ;
memcpy ( V_34 , & V_5 -> V_34 , sizeof( struct V_33 ) ) ;
return 0 ;
}
static void F_14 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = (struct V_4 * ) V_2 -> V_6 ;
F_15 ( V_5 ) ;
}
struct V_1 * F_16 ( struct V_45 * V_10 )
{
struct V_4 * V_5 = NULL ;
V_5 = F_17 ( sizeof( struct V_4 ) , V_46 ) ;
if ( V_5 == NULL )
goto error;
F_18 ( L_1 ) ;
V_5 -> V_10 = V_10 ;
memcpy ( & V_5 -> V_47 . V_48 , & V_49 , sizeof( struct V_50 ) ) ;
V_5 -> V_47 . V_6 = V_5 ;
return & V_5 -> V_47 ;
error:
return NULL ;
}
