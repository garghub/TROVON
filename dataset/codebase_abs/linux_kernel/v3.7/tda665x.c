static int F_1 ( struct V_1 * V_2 , T_1 * V_3 )
{
const struct V_4 * V_5 = V_2 -> V_5 ;
int V_6 = 0 ;
struct V_7 V_8 = { . V_9 = V_5 -> V_9 , . V_10 = V_11 , . V_3 = V_3 , . V_12 = 2 } ;
V_6 = F_2 ( V_2 -> V_13 , & V_8 , 1 ) ;
if ( V_6 != 1 )
goto exit;
return V_6 ;
exit:
F_3 ( V_14 L_1 , V_15 , V_6 ) ;
return V_6 ;
}
static int F_4 ( struct V_1 * V_2 , T_1 * V_3 , T_1 V_16 )
{
const struct V_4 * V_5 = V_2 -> V_5 ;
int V_6 = 0 ;
struct V_7 V_8 = { . V_9 = V_5 -> V_9 , . V_10 = 0 , . V_3 = V_3 , . V_12 = V_16 } ;
V_6 = F_2 ( V_2 -> V_13 , & V_8 , 1 ) ;
if ( V_6 != 1 )
goto exit;
return V_6 ;
exit:
F_3 ( V_14 L_1 , V_15 , V_6 ) ;
return V_6 ;
}
static int F_5 ( struct V_17 * V_18 ,
enum V_19 V_20 ,
struct V_21 * V_22 )
{
struct V_1 * V_2 = V_18 -> V_23 ;
int V_6 = 0 ;
switch ( V_20 ) {
case V_24 :
V_22 -> V_25 = V_2 -> V_25 ;
break;
case V_26 :
break;
default:
F_3 ( V_14 L_2 , V_15 , V_20 ) ;
V_6 = - V_27 ;
break;
}
return V_6 ;
}
static int F_6 ( struct V_17 * V_18 , T_2 * V_28 )
{
struct V_1 * V_2 = V_18 -> V_23 ;
T_1 V_29 = 0 ;
int V_6 = 0 ;
* V_28 = 0 ;
V_6 = F_1 ( V_2 , & V_29 ) ;
if ( V_6 < 0 )
goto exit;
if ( ( V_29 >> 6 ) & 0x01 ) {
F_3 ( V_30 L_3 , V_15 ) ;
* V_28 = 1 ;
}
return V_6 ;
exit:
F_3 ( V_14 L_4 , V_15 ) ;
return V_6 ;
}
static int F_7 ( struct V_17 * V_18 ,
enum V_19 V_20 ,
struct V_21 * V_22 )
{
struct V_1 * V_2 = V_18 -> V_23 ;
const struct V_4 * V_5 = V_2 -> V_5 ;
T_2 V_25 , V_28 = 0 ;
T_1 V_3 [ 4 ] ;
int V_6 = 0 ;
if ( V_20 & V_24 ) {
V_25 = V_22 -> V_25 ;
if ( ( V_25 < V_5 -> V_31 ) || ( V_25 > V_5 -> V_32 ) ) {
F_3 ( V_14 L_5 , V_15 , V_25 ) ;
return - V_27 ;
}
V_25 += V_5 -> V_33 ;
V_25 *= V_5 -> V_34 ;
V_25 += V_5 -> V_35 >> 1 ;
V_25 /= V_5 -> V_35 ;
V_3 [ 0 ] = ( T_1 ) ( ( V_25 & 0x7f00 ) >> 8 ) ;
V_3 [ 1 ] = ( T_1 ) ( V_25 & 0x00ff ) >> 0 ;
V_3 [ 2 ] = 0x80 | 0x40 | 0x02 ;
V_3 [ 3 ] = 0x00 ;
V_25 = V_22 -> V_25 ;
if ( V_25 < 153000000 ) {
V_3 [ 3 ] |= 0x01 ;
if ( V_25 < 68000000 )
V_3 [ 3 ] |= 0x40 ;
if ( V_25 < 1040000000 )
V_3 [ 3 ] |= 0x60 ;
if ( V_25 < 1250000000 )
V_3 [ 3 ] |= 0x80 ;
else
V_3 [ 3 ] |= 0xa0 ;
} else if ( V_25 < 438000000 ) {
V_3 [ 3 ] |= 0x02 ;
if ( V_25 < 230000000 )
V_3 [ 3 ] |= 0x40 ;
if ( V_25 < 300000000 )
V_3 [ 3 ] |= 0x60 ;
else
V_3 [ 3 ] |= 0x80 ;
} else {
V_3 [ 3 ] |= 0x04 ;
if ( V_25 < 470000000 )
V_3 [ 3 ] |= 0x60 ;
if ( V_25 < 526000000 )
V_3 [ 3 ] |= 0x80 ;
else
V_3 [ 3 ] |= 0xa0 ;
}
V_6 = F_4 ( V_2 , V_3 , 5 ) ;
if ( V_6 < 0 )
goto exit;
F_3 ( V_30 L_6 , V_15 ) ;
F_8 ( 20 ) ;
V_6 = F_6 ( V_18 , & V_28 ) ;
if ( V_6 < 0 )
goto exit;
if ( V_28 == 1 ) {
F_3 ( V_30 L_7 , V_15 , V_28 ) ;
V_2 -> V_25 = V_25 ;
} else {
F_3 ( V_14 L_8 , V_15 , V_28 ) ;
}
} else {
F_3 ( V_14 L_2 , V_15 , V_20 ) ;
return - V_27 ;
}
return 0 ;
exit:
F_3 ( V_14 L_4 , V_15 ) ;
return V_6 ;
}
static int F_9 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = V_18 -> V_23 ;
V_18 -> V_23 = NULL ;
F_10 ( V_2 ) ;
return 0 ;
}
struct V_17 * F_11 ( struct V_17 * V_18 ,
const struct V_4 * V_5 ,
struct V_36 * V_13 )
{
struct V_1 * V_2 = NULL ;
struct V_37 * V_38 ;
V_2 = F_12 ( sizeof( struct V_1 ) , V_39 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_5 = V_5 ;
V_2 -> V_13 = V_13 ;
V_2 -> V_18 = V_18 ;
V_18 -> V_23 = V_2 ;
V_18 -> V_40 . V_41 = V_42 ;
V_38 = & V_18 -> V_40 . V_41 . V_38 ;
memcpy ( V_38 -> V_43 , V_5 -> V_43 , sizeof( V_5 -> V_43 ) ) ;
V_38 -> V_32 = V_5 -> V_32 ;
V_38 -> V_31 = V_5 -> V_31 ;
V_38 -> V_44 = V_5 -> V_33 ;
F_3 ( V_30 L_9 , V_15 , V_38 -> V_43 ) ;
return V_18 ;
}
