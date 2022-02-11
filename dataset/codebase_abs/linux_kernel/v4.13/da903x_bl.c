static int F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_5 -> V_8 ;
T_1 V_9 ;
int V_10 = 0 ;
switch ( V_5 -> V_11 ) {
case V_12 :
V_10 = F_3 ( V_7 , V_13 ,
V_3 , 0x7f ) ;
if ( V_10 )
return V_10 ;
if ( V_5 -> V_14 && V_3 == 0 )
V_10 = F_4 ( V_7 ,
V_15 ,
V_16 ) ;
if ( V_5 -> V_14 == 0 && V_3 )
V_10 = F_5 ( V_7 ,
V_15 ,
V_16 ) ;
break;
case V_17 :
V_9 = F_6 ( V_3 ) ;
V_9 |= V_3 ? V_18 : 0 ;
V_10 = F_7 ( V_7 , V_19 , V_9 ) ;
break;
}
if ( V_10 )
return V_10 ;
V_5 -> V_14 = V_3 ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 )
{
int V_3 = V_2 -> V_20 . V_3 ;
if ( V_2 -> V_20 . V_21 != V_22 )
V_3 = 0 ;
if ( V_2 -> V_20 . V_23 != V_22 )
V_3 = 0 ;
if ( V_2 -> V_20 . V_24 & V_25 )
V_3 = 0 ;
return F_1 ( V_2 , V_3 ) ;
}
static int F_9 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
return V_5 -> V_14 ;
}
static int F_10 ( struct V_26 * V_27 )
{
struct V_28 * V_29 = F_11 ( & V_27 -> V_7 ) ;
struct V_4 * V_5 ;
struct V_1 * V_2 ;
struct V_30 V_20 ;
int V_31 ;
V_5 = F_12 ( & V_27 -> V_7 , sizeof( * V_5 ) , V_32 ) ;
if ( V_5 == NULL )
return - V_33 ;
switch ( V_27 -> V_11 ) {
case V_17 :
V_31 = V_34 ;
break;
case V_12 :
V_31 = V_35 ;
break;
default:
F_13 ( & V_27 -> V_7 , L_1 ,
V_27 -> V_11 ) ;
return - V_36 ;
}
V_5 -> V_11 = V_27 -> V_11 ;
V_5 -> V_8 = V_27 -> V_7 . V_37 ;
V_5 -> V_14 = 0 ;
if ( V_29 )
F_7 ( V_5 -> V_8 , V_15 ,
F_14 ( V_29 -> V_38 ) ) ;
memset ( & V_20 , 0 , sizeof( V_20 ) ) ;
V_20 . type = V_39 ;
V_20 . V_31 = V_31 ;
V_2 = F_15 ( & V_27 -> V_7 , V_27 -> V_40 ,
V_5 -> V_8 , V_5 ,
& V_41 , & V_20 ) ;
if ( F_16 ( V_2 ) ) {
F_13 ( & V_27 -> V_7 , L_2 ) ;
return F_17 ( V_2 ) ;
}
V_2 -> V_20 . V_3 = V_31 ;
F_18 ( V_27 , V_2 ) ;
F_19 ( V_2 ) ;
return 0 ;
}
