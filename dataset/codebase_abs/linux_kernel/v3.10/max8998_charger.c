static int F_1 ( struct V_1 * V_2 ,
enum V_3 V_4 ,
union V_5 * V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 ,
struct V_7 , V_9 ) ;
struct V_10 * V_11 = V_8 -> V_12 -> V_11 ;
int V_13 ;
T_1 V_14 ;
switch ( V_4 ) {
case V_15 :
V_13 = F_3 ( V_11 , V_16 , & V_14 ) ;
if ( V_13 )
return V_13 ;
if ( V_14 & ( 1 << 4 ) )
V_6 -> V_17 = 0 ;
else
V_6 -> V_17 = 1 ;
break;
case V_18 :
V_13 = F_3 ( V_11 , V_16 , & V_14 ) ;
if ( V_13 )
return V_13 ;
if ( V_14 & ( 1 << 3 ) )
V_6 -> V_17 = 0 ;
else
V_6 -> V_17 = 1 ;
break;
default:
return - V_19 ;
}
return 0 ;
}
static int F_4 ( struct V_20 * V_21 )
{
struct V_22 * V_12 = F_5 ( V_21 -> V_23 . V_24 ) ;
struct V_25 * V_26 = F_6 ( V_12 -> V_23 ) ;
struct V_7 * V_8 ;
struct V_10 * V_11 ;
int V_13 = 0 ;
if ( ! V_26 ) {
F_7 ( V_21 -> V_23 . V_24 , L_1 ) ;
return - V_27 ;
}
V_8 = F_8 ( & V_21 -> V_23 , sizeof( struct V_7 ) ,
V_28 ) ;
if ( ! V_8 )
return - V_29 ;
V_8 -> V_23 = & V_21 -> V_23 ;
V_8 -> V_12 = V_12 ;
F_9 ( V_21 , V_8 ) ;
V_11 = V_8 -> V_12 -> V_11 ;
if ( V_26 -> V_30 >= 10 && V_26 -> V_30 <= 45 ) {
F_10 ( V_11 , V_31 ,
( V_26 -> V_30 / 5 - 2 ) << 5 , 0x7 << 5 ) ;
} else if ( V_26 -> V_30 == 0 ) {
F_11 ( V_8 -> V_23 ,
L_2 ) ;
} else {
F_7 ( V_8 -> V_23 , L_3 ) ;
V_13 = - V_19 ;
goto V_32;
}
switch ( V_26 -> V_33 ) {
case 100 :
F_10 ( V_11 , V_31 , 0x1 << 3 , 0x3 << 3 ) ;
break;
case 150 :
F_10 ( V_11 , V_31 , 0x0 << 3 , 0x3 << 3 ) ;
break;
case 200 :
F_10 ( V_11 , V_31 , 0x2 << 3 , 0x3 << 3 ) ;
break;
case - 1 :
F_10 ( V_11 , V_31 , 0x3 << 3 , 0x3 << 3 ) ;
break;
case 0 :
F_11 ( V_8 -> V_23 ,
L_4 ) ;
break;
default:
F_7 ( V_8 -> V_23 , L_5 ) ;
V_13 = - V_19 ;
goto V_32;
}
switch ( V_26 -> V_34 ) {
case 5 :
F_10 ( V_11 , V_35 , 0x0 << 4 , 0x3 << 4 ) ;
break;
case 6 :
F_10 ( V_11 , V_35 , 0x1 << 4 , 0x3 << 4 ) ;
break;
case 7 :
F_10 ( V_11 , V_35 , 0x2 << 4 , 0x3 << 4 ) ;
break;
case - 1 :
F_10 ( V_11 , V_35 , 0x3 << 4 , 0x3 << 4 ) ;
break;
case 0 :
F_11 ( V_8 -> V_23 ,
L_6 ) ;
break;
default:
F_7 ( V_8 -> V_23 , L_7 ) ;
V_13 = - V_19 ;
goto V_32;
}
V_8 -> V_9 . V_36 = L_8 ;
V_8 -> V_9 . type = V_37 ;
V_8 -> V_9 . V_38 = F_1 ;
V_8 -> V_9 . V_39 = V_40 ;
V_8 -> V_9 . V_41 = F_12 ( V_40 ) ;
V_13 = F_13 ( V_8 -> V_23 , & V_8 -> V_9 ) ;
if ( V_13 ) {
F_7 ( V_8 -> V_23 , L_9 ) ;
goto V_32;
}
return 0 ;
V_32:
return V_13 ;
}
static int F_14 ( struct V_20 * V_21 )
{
struct V_7 * V_8 = F_15 ( V_21 ) ;
F_16 ( & V_8 -> V_9 ) ;
return 0 ;
}
