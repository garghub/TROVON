static struct V_1 *
F_1 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
struct V_6 * V_7 = V_6 ( V_3 ) ;
return V_7 -> V_8 ( V_7 , F_2 ( V_5 -> V_9 ) ) ;
}
static int
F_3 ( struct V_2 * V_3 , struct V_4 * V_5 ,
int V_10 , int V_11 )
{
struct V_1 * V_12 ;
int V_13 = - V_14 ;
V_12 = F_1 ( V_3 , V_5 ) ;
if ( V_12 ) {
if ( V_12 -> V_15 -> V_11 )
V_13 = V_12 -> V_15 -> V_11 ( V_12 , V_11 ) ;
else
V_13 = 0 ;
}
return V_13 ;
}
static int
F_4 ( struct V_2 * V_3 , struct V_4 * V_5 ,
int V_10 , int V_16 , int V_17 , bool V_18 )
{
struct V_1 * V_12 ;
int V_13 = - V_14 ;
V_12 = F_1 ( V_3 , V_5 ) ;
if ( V_12 && V_12 -> V_15 -> V_19 )
V_13 = V_12 -> V_15 -> V_19 ( V_12 , V_16 , V_17 , V_18 ) ;
return V_13 ;
}
static int
F_5 ( struct V_2 * V_3 , struct V_4 * V_5 ,
int V_10 , int V_20 , int V_21 , int V_22 )
{
struct V_1 * V_12 ;
int V_13 = - V_14 ;
V_12 = F_1 ( V_3 , V_5 ) ;
if ( V_12 ) {
if ( V_12 -> V_15 -> V_23 )
V_13 = V_12 -> V_15 -> V_23 ( V_12 , V_20 , V_21 , V_22 ) ;
else
V_13 = 0 ;
}
return V_13 ;
}
int
F_6 ( struct V_24 * V_25 , int V_26 , T_1 V_27 )
{
const T_1 V_28 = V_27 & V_29 ;
const T_1 V_30 = ( V_26 * 0x800 ) ;
F_7 ( V_25 , 0x61e004 + V_30 , 0x80000000 , 0x00000000 ) ;
F_8 ( V_25 , 0x61e004 + V_30 , 0x80000101 , 0x80000000 | V_28 ) ;
F_7 ( V_25 , 0x61e004 + V_30 , 0x80000000 , 0x00000000 ) ;
return 0 ;
}
int
F_9 ( struct V_31 * V_32 , T_1 V_33 , void * args , T_1 V_34 )
{
struct V_24 * V_25 = ( void * ) V_32 -> V_35 ;
const T_2 type = ( V_33 & V_36 ) >> 12 ;
const T_2 V_26 = ( V_33 & V_37 ) ;
T_1 * V_27 = args ;
int V_13 ;
if ( V_34 < sizeof( T_1 ) )
return - V_14 ;
V_33 &= ~ V_36 ;
V_33 &= ~ V_37 ;
switch ( V_33 ) {
case V_38 :
V_13 = V_25 -> V_39 . V_40 ( V_25 , V_26 , V_27 [ 0 ] ) ;
V_25 -> V_39 . type [ V_26 ] = type ;
break;
default:
return - V_14 ;
}
return V_13 ;
}
