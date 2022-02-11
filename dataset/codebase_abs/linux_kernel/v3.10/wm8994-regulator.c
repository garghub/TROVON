static int F_1 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( V_3 > V_6 )
return - V_7 ;
switch ( V_5 -> V_8 -> type ) {
case V_9 :
return ( V_3 * 100000 ) + 900000 ;
case V_10 :
return ( V_3 * 100000 ) + 1000000 ;
case V_11 :
switch ( V_3 ) {
case 0 :
return - V_7 ;
default:
return ( V_3 * 100000 ) + 950000 ;
}
break;
default:
return - V_7 ;
}
}
static int F_3 ( struct V_12 * V_13 )
{
struct V_8 * V_8 = F_4 ( V_13 -> V_14 . V_15 ) ;
struct V_16 * V_17 = V_8 -> V_14 -> V_18 ;
int V_19 = V_13 -> V_19 % F_5 ( V_17 -> V_5 ) ;
struct V_20 V_21 = { } ;
struct V_4 * V_5 ;
int V_22 ;
F_6 ( & V_13 -> V_14 , L_1 , V_19 + 1 ) ;
V_5 = F_7 ( & V_13 -> V_14 , sizeof( struct V_4 ) , V_23 ) ;
if ( V_5 == NULL ) {
F_8 ( & V_13 -> V_14 , L_2 ) ;
return - V_24 ;
}
V_5 -> V_8 = V_8 ;
V_5 -> V_25 = V_26 [ V_19 ] ;
V_5 -> V_25 . V_27 = V_27 ( V_8 -> V_14 ) ;
V_21 . V_14 = V_8 -> V_14 ;
V_21 . V_28 = V_5 ;
V_21 . V_29 = V_8 -> V_29 ;
V_21 . V_30 = & V_5 -> V_30 ;
if ( V_17 )
V_21 . V_31 = V_17 -> V_5 [ V_19 ] . V_32 ;
else if ( V_8 -> V_14 -> V_33 )
V_21 . V_31 = V_8 -> V_17 . V_5 [ V_19 ] . V_32 ;
if ( ! V_17 || ! V_17 -> V_5 [ V_19 ] . V_30 || V_8 -> V_14 -> V_33 ) {
F_6 ( V_8 -> V_14 , L_3 ,
V_5 -> V_25 . V_27 , V_5 -> V_25 . V_25 ) ;
V_5 -> V_30 = V_34 [ V_19 ] ;
V_5 -> V_30 . V_35 = & V_5 -> V_25 ;
if ( ! V_21 . V_31 )
V_5 -> V_30 . V_36 . V_37 = 0 ;
} else {
V_5 -> V_30 = * V_17 -> V_5 [ V_19 ] . V_30 ;
}
V_5 -> V_38 = F_9 ( & V_39 [ V_19 ] , & V_21 ) ;
if ( F_10 ( V_5 -> V_38 ) ) {
V_22 = F_11 ( V_5 -> V_38 ) ;
F_8 ( V_8 -> V_14 , L_4 ,
V_19 + 1 , V_22 ) ;
goto V_40;
}
F_12 ( V_13 , V_5 ) ;
return 0 ;
V_40:
return V_22 ;
}
static int F_13 ( struct V_12 * V_13 )
{
struct V_4 * V_5 = F_14 ( V_13 ) ;
F_12 ( V_13 , NULL ) ;
F_15 ( V_5 -> V_38 ) ;
return 0 ;
}
