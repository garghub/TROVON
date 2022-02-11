static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 )
{
V_2 -> V_5 [ 1 ] = V_4 & 0xff ;
V_2 -> V_5 [ 0 ] = ( V_3 == 0 ) ? 0x00 : 0x80 ;
V_2 -> V_5 [ 0 ] |= 0x30 | ( ( V_4 >> 8 ) & 0x0f ) ;
return F_2 ( V_2 -> V_6 , V_2 -> V_5 , 2 ) ;
}
static int F_3 ( struct V_7 * V_8 ,
struct V_9 const * V_10 ,
int * V_4 ,
int * V_11 ,
long V_12 )
{
struct V_1 * V_2 = F_4 ( V_8 ) ;
switch ( V_12 ) {
case V_13 :
* V_4 = V_2 -> V_14 [ V_10 -> V_15 ] ;
return V_16 ;
case V_17 :
* V_4 = V_2 -> V_18 ;
* V_11 = V_10 -> V_19 . V_20 ;
return V_21 ;
default:
return - V_22 ;
}
}
static int F_5 ( struct V_7 * V_8 ,
struct V_9 const * V_10 ,
int V_4 ,
int V_11 ,
long V_12 )
{
struct V_1 * V_2 = F_4 ( V_8 ) ;
if ( V_11 != 0 )
return - V_22 ;
switch ( V_12 ) {
case V_13 :
if ( V_4 > F_6 ( V_10 -> V_19 . V_20 - 1 , 0 ) )
return - V_22 ;
V_4 <<= V_10 -> V_19 . V_23 ;
V_2 -> V_14 [ V_10 -> V_15 ] = V_4 ;
return F_1 ( V_2 , V_10 -> V_15 , V_4 ) ;
default:
return - V_22 ;
}
}
static int F_7 ( struct V_24 * V_6 )
{
struct V_7 * V_8 ;
struct V_1 * V_2 ;
const struct V_25 * V_26 ;
int V_27 ;
V_8 = F_8 ( & V_6 -> V_28 , sizeof( * V_2 ) ) ;
if ( V_8 == NULL )
return - V_29 ;
V_2 = F_4 ( V_8 ) ;
V_2 -> V_6 = V_6 ;
V_2 -> V_30 = F_9 ( & V_6 -> V_28 , L_1 ) ;
if ( F_10 ( V_2 -> V_30 ) ) {
F_11 ( & V_6 -> V_28 , L_2 ) ;
return F_12 ( V_2 -> V_30 ) ;
}
V_27 = F_13 ( V_2 -> V_30 ) ;
if ( V_27 ) {
F_11 ( & V_6 -> V_28 , L_3 ,
V_27 ) ;
return V_27 ;
}
V_27 = F_14 ( V_2 -> V_30 ) ;
if ( V_27 < 0 ) {
F_11 ( & V_6 -> V_28 , L_4 ,
V_27 ) ;
goto V_31;
}
V_2 -> V_18 = V_27 / 1000 ;
F_15 ( V_6 , V_8 ) ;
V_26 = F_16 ( V_6 ) ;
V_8 -> V_28 . V_32 = & V_6 -> V_28 ;
V_8 -> V_33 = & V_34 ;
V_8 -> V_35 = V_36 ;
V_8 -> V_37 = V_38 [ V_26 -> V_39 ] ;
V_8 -> V_40 = V_41 ;
V_8 -> V_42 = V_26 -> V_42 ;
V_27 = F_17 ( V_8 ) ;
if ( V_27 ) {
F_11 ( & V_6 -> V_28 , L_5 ,
V_27 ) ;
goto V_31;
}
return 0 ;
V_31:
F_18 ( V_2 -> V_30 ) ;
return V_27 ;
}
static int F_19 ( struct V_24 * V_6 )
{
struct V_7 * V_8 = F_20 ( V_6 ) ;
struct V_1 * V_2 ;
F_21 ( V_8 ) ;
V_2 = F_4 ( V_8 ) ;
F_18 ( V_2 -> V_30 ) ;
return 0 ;
}
