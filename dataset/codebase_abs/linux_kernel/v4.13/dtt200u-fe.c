static int F_1 ( struct V_1 * V_2 ,
enum V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_8 ;
F_2 ( & V_6 -> V_9 ) ;
V_6 -> V_10 [ 0 ] = V_11 ;
V_8 = F_3 ( V_6 -> V_12 , V_6 -> V_10 , 1 , V_6 -> V_10 , 3 , 0 ) ;
if ( V_8 < 0 ) {
* V_4 = 0 ;
F_4 ( & V_6 -> V_9 ) ;
return V_8 ;
}
switch ( V_6 -> V_10 [ 0 ] ) {
case 0x01 :
* V_4 = V_13 | V_14 |
V_15 | V_16 | V_17 ;
break;
case 0x00 :
* V_4 = V_18 ;
break;
default:
case 0x02 :
* V_4 = 0 ;
break;
}
F_4 ( & V_6 -> V_9 ) ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 , T_1 * V_19 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_8 ;
F_2 ( & V_6 -> V_9 ) ;
V_6 -> V_10 [ 0 ] = V_20 ;
V_8 = F_3 ( V_6 -> V_12 , V_6 -> V_10 , 1 , V_6 -> V_10 , 3 , 0 ) ;
if ( V_8 >= 0 )
* V_19 = ( V_6 -> V_10 [ 0 ] << 16 ) | ( V_6 -> V_10 [ 1 ] << 8 ) | V_6 -> V_10 [ 2 ] ;
F_4 ( & V_6 -> V_9 ) ;
return V_8 ;
}
static int F_6 ( struct V_1 * V_2 , T_1 * V_21 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_8 ;
F_2 ( & V_6 -> V_9 ) ;
V_6 -> V_10 [ 0 ] = V_22 ;
V_8 = F_3 ( V_6 -> V_12 , V_6 -> V_10 , 1 , V_6 -> V_10 , 2 , 0 ) ;
if ( V_8 >= 0 )
* V_21 = ( V_6 -> V_10 [ 0 ] << 8 ) | V_6 -> V_10 [ 1 ] ;
F_4 ( & V_6 -> V_9 ) ;
return V_8 ;
}
static int F_7 ( struct V_1 * V_2 , T_2 * V_23 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_8 ;
F_2 ( & V_6 -> V_9 ) ;
V_6 -> V_10 [ 0 ] = V_24 ;
V_8 = F_3 ( V_6 -> V_12 , V_6 -> V_10 , 1 , V_6 -> V_10 , 1 , 0 ) ;
if ( V_8 >= 0 )
* V_23 = ( V_6 -> V_10 [ 0 ] << 8 ) | V_6 -> V_10 [ 0 ] ;
F_4 ( & V_6 -> V_9 ) ;
return V_8 ;
}
static int F_8 ( struct V_1 * V_2 , T_2 * V_25 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_8 ;
F_2 ( & V_6 -> V_9 ) ;
V_6 -> V_10 [ 0 ] = V_26 ;
V_8 = F_3 ( V_6 -> V_12 , V_6 -> V_10 , 1 , V_6 -> V_10 , 1 , 0 ) ;
if ( V_8 >= 0 )
* V_25 = ~ ( ( V_6 -> V_10 [ 0 ] << 8 ) | V_6 -> V_10 [ 0 ] ) ;
F_4 ( & V_6 -> V_9 ) ;
return V_8 ;
}
static int F_9 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_8 ;
F_2 ( & V_6 -> V_9 ) ;
V_6 -> V_10 [ 0 ] = V_27 ;
V_8 = F_10 ( V_6 -> V_12 , V_6 -> V_10 , 1 ) ;
F_4 ( & V_6 -> V_9 ) ;
return V_8 ;
}
static int F_11 ( struct V_1 * V_2 )
{
return F_9 ( V_2 ) ;
}
static int F_12 ( struct V_1 * V_2 , struct V_28 * V_29 )
{
V_29 -> V_30 = 1500 ;
V_29 -> V_31 = 0 ;
V_29 -> V_32 = 0 ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 )
{
struct V_33 * V_34 = & V_2 -> V_35 ;
struct V_5 * V_6 = V_2 -> V_7 ;
int V_8 ;
T_2 V_36 = V_34 -> V_37 / 250000 ;
F_2 ( & V_6 -> V_9 ) ;
V_6 -> V_10 [ 0 ] = V_38 ;
switch ( V_34 -> V_39 ) {
case 8000000 :
V_6 -> V_10 [ 1 ] = 8 ;
break;
case 7000000 :
V_6 -> V_10 [ 1 ] = 7 ;
break;
case 6000000 :
V_6 -> V_10 [ 1 ] = 6 ;
break;
default:
V_8 = - V_40 ;
goto V_8;
}
V_8 = F_10 ( V_6 -> V_12 , V_6 -> V_10 , 2 ) ;
if ( V_8 < 0 )
goto V_8;
V_6 -> V_10 [ 0 ] = V_41 ;
V_6 -> V_10 [ 1 ] = V_36 & 0xff ;
V_6 -> V_10 [ 2 ] = ( V_36 >> 8 ) & 0xff ;
V_8 = F_10 ( V_6 -> V_12 , V_6 -> V_10 , 3 ) ;
if ( V_8 < 0 )
goto V_8;
V_8:
F_4 ( & V_6 -> V_9 ) ;
return V_8 ;
}
static int F_14 ( struct V_1 * V_2 ,
struct V_33 * V_34 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
memcpy ( V_34 , & V_6 -> V_34 , sizeof( struct V_33 ) ) ;
return 0 ;
}
static void F_15 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = (struct V_5 * ) V_2 -> V_7 ;
F_16 ( V_6 ) ;
}
struct V_1 * F_17 ( struct V_42 * V_12 )
{
struct V_5 * V_6 = NULL ;
V_6 = F_18 ( sizeof( struct V_5 ) , V_43 ) ;
if ( V_6 == NULL )
goto error;
F_19 ( L_1 ) ;
V_6 -> V_12 = V_12 ;
F_20 ( & V_6 -> V_9 ) ;
memcpy ( & V_6 -> V_44 . V_45 , & V_46 , sizeof( struct V_47 ) ) ;
V_6 -> V_44 . V_7 = V_6 ;
return & V_6 -> V_44 ;
error:
return NULL ;
}
