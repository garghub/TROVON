static int
F_1 ( struct V_1 * V_2 ,
struct V_1 * V_3 ,
struct V_4 * V_5 , void * V_6 , T_1 V_7 ,
struct V_1 * * V_8 )
{
struct V_9 * V_10 = V_9 ( V_2 ) ;
struct V_11 * V_12 ;
int V_13 ;
V_13 = F_2 ( V_2 , V_3 , V_5 , V_6 , V_7 , & V_12 ) ;
* V_8 = F_3 ( V_12 ) ;
if ( V_13 )
return V_13 ;
V_12 -> V_14 = V_10 -> V_15 ( V_10 , F_4 ( V_12 -> V_6 . V_16 ) ) ;
return 0 ;
}
static int
F_5 ( struct V_17 * V_12 , int V_18 )
{
struct V_19 * V_20 = V_12 -> V_21 . V_14 ;
if ( V_20 && V_20 -> V_22 -> V_18 )
return V_20 -> V_22 -> V_18 ( V_20 , V_18 ) ;
return V_20 ? 0 : - V_23 ;
}
static int
F_6 ( struct V_17 * V_12 , int V_24 )
{
return 0 ;
}
static int
F_7 ( struct V_17 * V_12 , int V_24 , int V_25 , bool V_26 )
{
struct V_19 * V_20 = V_12 -> V_21 . V_14 ;
if ( V_20 && V_20 -> V_22 -> V_27 )
return V_20 -> V_22 -> V_27 ( V_20 , V_24 , V_25 , V_26 ) ;
return V_20 ? 0 : - V_23 ;
}
static int
F_8 ( struct V_17 * V_12 , int V_28 , int V_29 , int V_30 , int V_31 )
{
struct V_19 * V_20 = V_12 -> V_21 . V_14 ;
if ( V_20 && V_20 -> V_22 -> V_32 )
return V_20 -> V_22 -> V_32 ( V_20 , V_28 , V_29 , V_30 ) ;
return V_20 ? 0 : - V_23 ;
}
static int
F_9 ( struct V_1 * V_2 ,
struct V_1 * V_3 ,
struct V_4 * V_5 , void * V_6 , T_1 V_7 ,
struct V_1 * * V_8 )
{
struct V_9 * V_10 = V_9 ( V_2 ) ;
struct V_17 * V_12 ;
int V_13 ;
V_13 = F_10 ( V_2 , V_3 , V_5 , V_6 , V_7 , & V_12 ) ;
* V_8 = F_3 ( V_12 ) ;
if ( V_13 )
return V_13 ;
V_12 -> V_21 . V_14 = V_10 -> V_15 ( V_10 , F_11 (
V_12 -> V_21 . V_6 . V_16 ) ) ;
return 0 ;
}
int
F_12 ( struct V_33 * V_34 , int V_35 , T_1 V_36 )
{
const T_1 V_37 = V_36 & V_38 ;
const T_1 V_39 = ( V_35 * 0x800 ) ;
F_13 ( V_34 , 0x61e004 + V_39 , 0x80000000 , 0x00000000 ) ;
F_14 ( V_34 , 0x61e004 + V_39 , 0x80000101 , 0x80000000 | V_37 ) ;
F_13 ( V_34 , 0x61e004 + V_39 , 0x80000000 , 0x00000000 ) ;
return 0 ;
}
int
F_15 ( struct V_1 * V_40 , T_1 V_41 , void * args , T_1 V_42 )
{
struct V_33 * V_34 = ( void * ) V_40 -> V_3 ;
const T_2 type = ( V_41 & V_43 ) >> 12 ;
const T_2 V_35 = ( V_41 & V_44 ) ;
T_1 * V_36 = args ;
int V_13 ;
if ( V_42 < sizeof( T_1 ) )
return - V_45 ;
V_41 &= ~ V_43 ;
V_41 &= ~ V_44 ;
switch ( V_41 ) {
case V_46 :
V_13 = V_34 -> V_47 . V_48 ( V_34 , V_35 , V_36 [ 0 ] ) ;
V_34 -> V_47 . type [ V_35 ] = type ;
break;
default:
return - V_45 ;
}
return V_13 ;
}
