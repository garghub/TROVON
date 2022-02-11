static int F_1 ( struct V_1 * V_2 ,
enum V_3 V_4 ,
union V_5 * V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_9 * V_10 = V_8 -> V_11 -> V_10 ;
int V_12 ;
T_1 V_13 ;
switch ( V_4 ) {
case V_14 :
V_12 = F_3 ( V_10 , V_15 , & V_13 ) ;
if ( V_12 )
return V_12 ;
if ( V_13 & ( 1 << 4 ) )
V_6 -> V_16 = 0 ;
else
V_6 -> V_16 = 1 ;
break;
case V_17 :
V_12 = F_3 ( V_10 , V_15 , & V_13 ) ;
if ( V_12 )
return V_12 ;
if ( V_13 & ( 1 << 3 ) )
V_6 -> V_16 = 0 ;
else
V_6 -> V_16 = 1 ;
break;
default:
return - V_18 ;
}
return 0 ;
}
static int F_4 ( struct V_19 * V_20 )
{
struct V_21 * V_11 = F_5 ( V_20 -> V_22 . V_23 ) ;
struct V_24 * V_25 = F_6 ( V_11 -> V_22 ) ;
struct V_26 V_27 = {} ;
struct V_7 * V_8 ;
struct V_9 * V_10 ;
int V_12 = 0 ;
if ( ! V_25 ) {
F_7 ( V_20 -> V_22 . V_23 , L_1 ) ;
return - V_28 ;
}
V_8 = F_8 ( & V_20 -> V_22 , sizeof( struct V_7 ) ,
V_29 ) ;
if ( ! V_8 )
return - V_30 ;
V_8 -> V_22 = & V_20 -> V_22 ;
V_8 -> V_11 = V_11 ;
F_9 ( V_20 , V_8 ) ;
V_10 = V_8 -> V_11 -> V_10 ;
if ( V_25 -> V_31 >= 10 && V_25 -> V_31 <= 45 ) {
F_10 ( V_10 , V_32 ,
( V_25 -> V_31 / 5 - 2 ) << 5 , 0x7 << 5 ) ;
} else if ( V_25 -> V_31 == 0 ) {
F_11 ( V_8 -> V_22 ,
L_2 ) ;
} else {
F_7 ( V_8 -> V_22 , L_3 ) ;
return - V_18 ;
}
switch ( V_25 -> V_33 ) {
case 100 :
F_10 ( V_10 , V_32 , 0x1 << 3 , 0x3 << 3 ) ;
break;
case 150 :
F_10 ( V_10 , V_32 , 0x0 << 3 , 0x3 << 3 ) ;
break;
case 200 :
F_10 ( V_10 , V_32 , 0x2 << 3 , 0x3 << 3 ) ;
break;
case - 1 :
F_10 ( V_10 , V_32 , 0x3 << 3 , 0x3 << 3 ) ;
break;
case 0 :
F_11 ( V_8 -> V_22 ,
L_4 ) ;
break;
default:
F_7 ( V_8 -> V_22 , L_5 ) ;
return - V_18 ;
}
switch ( V_25 -> V_34 ) {
case 5 :
F_10 ( V_10 , V_35 , 0x0 << 4 , 0x3 << 4 ) ;
break;
case 6 :
F_10 ( V_10 , V_35 , 0x1 << 4 , 0x3 << 4 ) ;
break;
case 7 :
F_10 ( V_10 , V_35 , 0x2 << 4 , 0x3 << 4 ) ;
break;
case - 1 :
F_10 ( V_10 , V_35 , 0x3 << 4 , 0x3 << 4 ) ;
break;
case 0 :
F_11 ( V_8 -> V_22 ,
L_6 ) ;
break;
default:
F_7 ( V_8 -> V_22 , L_7 ) ;
return - V_18 ;
}
V_27 . V_36 = V_8 ;
V_8 -> V_37 = F_12 ( V_8 -> V_22 ,
& V_38 ,
& V_27 ) ;
if ( F_13 ( V_8 -> V_37 ) ) {
V_12 = F_14 ( V_8 -> V_37 ) ;
F_7 ( V_8 -> V_22 , L_8 ,
V_12 ) ;
return V_12 ;
}
return 0 ;
}
