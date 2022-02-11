int F_1 ( struct V_1 * V_2 )
{
struct V_3 V_4 ;
struct V_5 V_6 ;
int V_7 ;
memset ( & V_4 , 0 , sizeof( V_4 ) ) ;
memset ( & V_6 , 0 , sizeof( V_6 ) ) ;
V_4 . V_8 . V_9 = V_10 ;
V_4 . V_8 . V_11 = V_12 ;
V_4 . V_13 = V_14 ;
V_7 = F_2 ( & V_2 -> V_15 -> V_16 , & V_4 ,
& V_6 ) ;
if ( V_7 )
return V_7 ;
V_2 -> V_17 = V_6 . V_17 ;
return 0 ;
}
int F_3 ( struct V_18 * V_15 )
{
struct V_1 * V_2 = & V_15 -> V_2 ;
V_2 -> V_15 = V_15 ;
V_2 -> V_19 =
36 +
4 +
8 +
2 ;
switch ( V_15 -> V_20 -> V_21 . V_22 ) {
case V_23 :
V_15 -> V_2 . V_24 = V_25 ;
V_15 -> V_2 . V_26 = V_27 ;
break;
case V_28 :
V_15 -> V_2 . V_24 = V_29 ;
V_15 -> V_2 . V_26 = V_30 ;
break;
case V_31 :
V_15 -> V_2 . V_24 = V_32 ;
V_15 -> V_2 . V_26 = V_33 ;
break;
case V_34 :
V_15 -> V_2 . V_24 = V_35 ;
V_15 -> V_2 . V_26 = V_36 ;
break;
case V_37 :
case V_38 :
F_4 ( 1 ) ;
return - V_39 ;
}
return 0 ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_18 * V_15 = V_2 -> V_15 ;
F_6 ( V_15 , V_40 , L_1 ,
V_2 -> V_41 , V_2 -> V_42 ) ;
if ( V_2 -> V_41 != 2 &&
V_2 -> V_41 != 3 ) {
F_7 ( V_15 , L_2 ,
V_2 -> V_41 ) ;
return - V_43 ;
}
return 0 ;
}
int F_8 ( struct V_1 * V_2 )
{
struct V_18 * V_15 = V_2 -> V_15 ;
int V_7 ;
F_9 ( & V_2 -> V_44 ) ;
V_7 = F_10 ( V_2 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_11 ( & V_2 -> V_44 ,
V_45 ) ;
if ( V_7 == 0 ) {
F_12 ( V_15 , L_3 ) ;
return - V_46 ;
}
V_7 = F_5 ( V_2 ) ;
if ( V_7 ) {
F_12 ( V_15 , L_4 ,
V_7 ) ;
return V_7 ;
}
V_7 = F_13 ( V_2 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_14 ( V_2 ) ;
if ( V_7 ) {
F_12 ( V_15 , L_5 ,
V_7 ) ;
return V_7 ;
}
V_7 = F_15 ( V_2 ,
V_2 -> V_47 ,
V_2 -> V_48 ) ;
if ( V_7 ) {
F_12 ( V_15 , L_6 ,
V_7 ) ;
return V_7 ;
}
return 0 ;
}
