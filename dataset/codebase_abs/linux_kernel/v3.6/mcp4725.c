static int F_1 ( struct V_1 * V_2 )
{
T_1 V_3 [ 2 ] ;
V_3 [ 0 ] = 0x3 << 4 ;
V_3 [ 1 ] = 0 ;
return F_2 ( F_3 ( V_2 ) , V_3 , 2 ) ;
}
static int F_4 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_5 ( V_2 ) ;
struct V_6 * V_7 = F_6 ( V_5 ) ;
T_1 V_3 [ 2 ] ;
V_3 [ 0 ] = ( V_7 -> V_8 >> 8 ) & 0xf ;
V_3 [ 1 ] = V_7 -> V_8 & 0xff ;
return F_2 ( F_3 ( V_2 ) , V_3 , 2 ) ;
}
static int F_7 ( struct V_4 * V_5 , int V_9 )
{
struct V_6 * V_7 = F_6 ( V_5 ) ;
T_1 V_3 [ 2 ] ;
int V_10 ;
if ( V_9 >= ( 1 << 12 ) || V_9 < 0 )
return - V_11 ;
V_3 [ 0 ] = ( V_9 >> 8 ) & 0xf ;
V_3 [ 1 ] = V_9 & 0xff ;
V_10 = F_2 ( V_7 -> V_12 , V_3 , 2 ) ;
if ( V_10 < 0 )
return V_10 ;
else if ( V_10 != 2 )
return - V_13 ;
else
return 0 ;
}
static int F_8 ( struct V_4 * V_5 ,
struct V_14 const * V_15 ,
int * V_9 , int * V_16 , long V_17 )
{
struct V_6 * V_7 = F_6 ( V_5 ) ;
unsigned long V_18 ;
switch ( V_17 ) {
case V_19 :
* V_9 = V_7 -> V_8 ;
return V_20 ;
case V_21 :
V_18 = ( V_7 -> V_22 * 1000 ) >> 12 ;
* V_9 = V_18 / 1000000 ;
* V_16 = V_18 % 1000000 ;
return V_23 ;
}
return - V_11 ;
}
static int F_9 ( struct V_4 * V_5 ,
struct V_14 const * V_15 ,
int V_9 , int V_16 , long V_17 )
{
struct V_6 * V_7 = F_6 ( V_5 ) ;
int V_10 ;
switch ( V_17 ) {
case V_19 :
V_10 = F_7 ( V_5 , V_9 ) ;
V_7 -> V_8 = V_9 ;
break;
default:
V_10 = - V_11 ;
break;
}
return V_10 ;
}
static int T_2 F_10 ( struct V_24 * V_12 ,
const struct V_25 * V_26 )
{
struct V_6 * V_7 ;
struct V_4 * V_5 ;
struct V_27 * V_28 = V_12 -> V_2 . V_28 ;
T_1 V_29 [ 3 ] ;
int V_30 ;
if ( ! V_28 || ! V_28 -> V_22 ) {
F_11 ( & V_12 -> V_2 , L_1 ) ;
V_30 = - V_11 ;
goto exit;
}
V_5 = F_12 ( sizeof( * V_7 ) ) ;
if ( V_5 == NULL ) {
V_30 = - V_31 ;
goto exit;
}
V_7 = F_6 ( V_5 ) ;
F_13 ( V_12 , V_5 ) ;
V_7 -> V_12 = V_12 ;
V_5 -> V_2 . V_32 = & V_12 -> V_2 ;
V_5 -> V_33 = & V_34 ;
V_5 -> V_35 = & V_36 ;
V_5 -> V_37 = 1 ;
V_5 -> V_38 = V_39 ;
V_7 -> V_22 = V_28 -> V_22 ;
V_30 = F_14 ( V_12 , V_29 , 3 ) ;
if ( V_30 < 0 ) {
F_11 ( & V_12 -> V_2 , L_2 ) ;
goto V_40;
}
V_7 -> V_8 = ( V_29 [ 1 ] << 4 ) | ( V_29 [ 2 ] >> 4 ) ;
V_30 = F_15 ( V_5 ) ;
if ( V_30 )
goto V_40;
F_16 ( & V_12 -> V_2 , L_3 ) ;
return 0 ;
V_40:
F_17 ( V_5 ) ;
exit:
return V_30 ;
}
static int T_3 F_18 ( struct V_24 * V_12 )
{
struct V_4 * V_5 = F_19 ( V_12 ) ;
F_20 ( V_5 ) ;
F_17 ( V_5 ) ;
return 0 ;
}
