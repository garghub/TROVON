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
static int F_5 ( struct V_17 * V_18 , T_2 * V_19 )
{
struct V_1 * V_2 = V_18 -> V_20 ;
* V_19 = V_2 -> V_19 ;
return 0 ;
}
static int F_6 ( struct V_17 * V_18 , T_2 * V_21 )
{
struct V_1 * V_2 = V_18 -> V_20 ;
T_1 V_22 = 0 ;
int V_6 = 0 ;
* V_21 = 0 ;
V_6 = F_1 ( V_2 , & V_22 ) ;
if ( V_6 < 0 )
goto exit;
if ( ( V_22 >> 6 ) & 0x01 ) {
F_3 ( V_23 L_2 , V_15 ) ;
* V_21 = 1 ;
}
return V_6 ;
exit:
F_3 ( V_14 L_3 , V_15 ) ;
return V_6 ;
}
static int F_7 ( struct V_17 * V_18 ,
T_2 V_24 )
{
struct V_1 * V_2 = V_18 -> V_20 ;
const struct V_4 * V_5 = V_2 -> V_5 ;
T_2 V_19 , V_21 = 0 ;
T_1 V_3 [ 4 ] ;
int V_6 = 0 ;
if ( ( V_24 < V_5 -> V_25 )
|| ( V_24 > V_5 -> V_26 ) ) {
F_3 ( V_14 L_4 ,
V_15 , V_24 ) ;
return - V_27 ;
}
V_19 = V_24 ;
V_19 += V_5 -> V_28 ;
V_19 *= V_5 -> V_29 ;
V_19 += V_5 -> V_30 >> 1 ;
V_19 /= V_5 -> V_30 ;
V_3 [ 0 ] = ( T_1 ) ( ( V_19 & 0x7f00 ) >> 8 ) ;
V_3 [ 1 ] = ( T_1 ) ( V_19 & 0x00ff ) >> 0 ;
V_3 [ 2 ] = 0x80 | 0x40 | 0x02 ;
V_3 [ 3 ] = 0x00 ;
V_19 = V_24 ;
if ( V_19 < 153000000 ) {
V_3 [ 3 ] |= 0x01 ;
if ( V_19 < 68000000 )
V_3 [ 3 ] |= 0x40 ;
if ( V_19 < 1040000000 )
V_3 [ 3 ] |= 0x60 ;
if ( V_19 < 1250000000 )
V_3 [ 3 ] |= 0x80 ;
else
V_3 [ 3 ] |= 0xa0 ;
} else if ( V_19 < 438000000 ) {
V_3 [ 3 ] |= 0x02 ;
if ( V_19 < 230000000 )
V_3 [ 3 ] |= 0x40 ;
if ( V_19 < 300000000 )
V_3 [ 3 ] |= 0x60 ;
else
V_3 [ 3 ] |= 0x80 ;
} else {
V_3 [ 3 ] |= 0x04 ;
if ( V_19 < 470000000 )
V_3 [ 3 ] |= 0x60 ;
if ( V_19 < 526000000 )
V_3 [ 3 ] |= 0x80 ;
else
V_3 [ 3 ] |= 0xa0 ;
}
V_6 = F_4 ( V_2 , V_3 , 5 ) ;
if ( V_6 < 0 )
goto exit;
F_3 ( V_23 L_5 , V_15 ) ;
F_8 ( 20 ) ;
V_6 = F_6 ( V_18 , & V_21 ) ;
if ( V_6 < 0 )
goto exit;
if ( V_21 == 1 ) {
F_3 ( V_23 L_6 ,
V_15 , V_21 ) ;
V_2 -> V_19 = V_19 ;
} else {
F_3 ( V_14 L_7 ,
V_15 , V_21 ) ;
}
return 0 ;
exit:
F_3 ( V_14 L_3 , V_15 ) ;
return V_6 ;
}
static int F_9 ( struct V_17 * V_18 )
{
struct V_31 * V_32 = & V_18 -> V_33 ;
F_7 ( V_18 , V_32 -> V_19 ) ;
return 0 ;
}
static int F_10 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = V_18 -> V_20 ;
V_18 -> V_20 = NULL ;
F_11 ( V_2 ) ;
return 0 ;
}
struct V_17 * F_12 ( struct V_17 * V_18 ,
const struct V_4 * V_5 ,
struct V_34 * V_13 )
{
struct V_1 * V_2 = NULL ;
struct V_35 * V_36 ;
V_2 = F_13 ( sizeof( struct V_1 ) , V_37 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_5 = V_5 ;
V_2 -> V_13 = V_13 ;
V_2 -> V_18 = V_18 ;
V_18 -> V_20 = V_2 ;
V_18 -> V_38 . V_39 = V_40 ;
V_36 = & V_18 -> V_38 . V_39 . V_36 ;
memcpy ( V_36 -> V_41 , V_5 -> V_41 , sizeof( V_5 -> V_41 ) ) ;
V_36 -> V_26 = V_5 -> V_26 ;
V_36 -> V_25 = V_5 -> V_25 ;
V_36 -> V_42 = V_5 -> V_28 ;
F_3 ( V_23 L_8 , V_15 , V_36 -> V_41 ) ;
return V_18 ;
}
