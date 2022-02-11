static int F_1 ( struct V_1 * V_2 , int V_3 ,
struct V_4 * V_5 )
{
if ( V_3 > 1 )
return - V_6 ;
V_5 -> V_7 = 3 ;
V_5 -> V_8 = ( ( V_3 + 1 ) * 8 ) - 3 ;
return 0 ;
}
static int F_2 ( struct V_1 * V_2 , int V_3 ,
struct V_4 * V_5 )
{
switch ( V_3 ) {
case 0 :
V_5 -> V_8 = 0 ;
V_5 -> V_7 = 4 ;
break;
case 1 :
V_5 -> V_8 = 6 ;
V_5 -> V_7 = 2 ;
break;
case 2 :
V_5 -> V_8 = 11 ;
V_5 -> V_7 = 2 ;
break;
default:
return - V_6 ;
}
return 0 ;
}
static int F_3 ( struct V_1 * V_2 , int V_3 ,
struct V_4 * V_5 )
{
if ( V_3 )
return - V_6 ;
V_5 -> V_7 = 3 ;
V_5 -> V_8 = 0 ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 , int V_3 ,
struct V_4 * V_5 )
{
switch ( V_3 ) {
case 0 :
V_5 -> V_8 = 3 ;
V_5 -> V_7 = 2 ;
break;
case 1 :
V_5 -> V_8 = 6 ;
V_5 -> V_7 = 2 ;
break;
default:
return - V_6 ;
}
return 0 ;
}
static int F_5 ( struct V_1 * V_2 , T_1 V_9 )
{
struct V_10 V_11 ;
struct V_12 V_13 ;
int V_14 ;
memset ( & V_13 , - 1 , V_15 ) ;
V_13 . V_16 = 0x0F ;
V_11 . V_17 = V_18 ;
V_11 . V_19 = 0 ;
V_11 . V_20 = V_2 -> V_21 ;
V_11 . V_22 = ( void * ) & V_13 ;
V_11 . V_23 = NULL ;
V_14 = F_6 ( V_2 , V_9 , & V_11 ) ;
if ( V_14 < 0 || V_11 . V_24 != V_15 ) {
F_7 ( V_25
L_1 ,
( int ) V_9 ) ;
return - V_26 ;
}
return 0 ;
}
int F_8 ( struct V_1 * V_2 , int V_27 )
{
struct V_28 * V_29 = F_9 ( V_2 ) ;
int V_14 ;
V_29 -> V_30 |= V_31 ;
V_14 = F_10 ( V_2 , 1 , V_27 ?
V_32 : V_33 ) ;
if ( V_14 )
return V_14 ;
V_29 -> V_34 = 0x05 ;
V_29 -> V_35 = 7 ;
V_29 -> V_36 = F_5 ;
if ( V_2 -> V_37 == V_38 )
F_11 ( V_2 , & V_39 ) ;
else if ( V_2 -> V_37 == V_40 )
F_11 ( V_2 , & V_41 ) ;
else
return - V_42 ;
V_14 = F_12 ( V_2 ) ;
if ( V_14 )
return V_14 ;
return F_13 ( V_2 , NULL , 0 ) ;
}
