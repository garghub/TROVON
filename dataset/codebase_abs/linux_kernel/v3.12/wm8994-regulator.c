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
struct V_16 * V_17 = F_5 ( V_8 -> V_14 ) ;
int V_18 = V_13 -> V_18 % F_6 ( V_17 -> V_5 ) ;
struct V_19 V_20 = { } ;
struct V_4 * V_5 ;
int V_21 ;
F_7 ( & V_13 -> V_14 , L_1 , V_18 + 1 ) ;
V_5 = F_8 ( & V_13 -> V_14 , sizeof( struct V_4 ) , V_22 ) ;
if ( V_5 == NULL ) {
F_9 ( & V_13 -> V_14 , L_2 ) ;
return - V_23 ;
}
V_5 -> V_8 = V_8 ;
V_5 -> V_24 = V_25 [ V_18 ] ;
V_5 -> V_24 . V_26 = V_26 ( V_8 -> V_14 ) ;
V_20 . V_14 = V_8 -> V_14 ;
V_20 . V_27 = V_5 ;
V_20 . V_28 = V_8 -> V_28 ;
V_20 . V_29 = & V_5 -> V_29 ;
if ( V_17 )
V_20 . V_30 = V_17 -> V_5 [ V_18 ] . V_31 ;
else if ( V_8 -> V_14 -> V_32 )
V_20 . V_30 = V_8 -> V_17 . V_5 [ V_18 ] . V_31 ;
if ( ! V_17 || ! V_17 -> V_5 [ V_18 ] . V_29 || V_8 -> V_14 -> V_32 ) {
F_7 ( V_8 -> V_14 , L_3 ,
V_5 -> V_24 . V_26 , V_5 -> V_24 . V_24 ) ;
V_5 -> V_29 = V_33 [ V_18 ] ;
V_5 -> V_29 . V_34 = & V_5 -> V_24 ;
if ( ! V_20 . V_30 )
V_5 -> V_29 . V_35 . V_36 = 0 ;
} else {
V_5 -> V_29 = * V_17 -> V_5 [ V_18 ] . V_29 ;
}
V_5 -> V_37 = F_10 ( & V_38 [ V_18 ] , & V_20 ) ;
if ( F_11 ( V_5 -> V_37 ) ) {
V_21 = F_12 ( V_5 -> V_37 ) ;
F_9 ( V_8 -> V_14 , L_4 ,
V_18 + 1 , V_21 ) ;
goto V_39;
}
F_13 ( V_13 , V_5 ) ;
return 0 ;
V_39:
return V_21 ;
}
static int F_14 ( struct V_12 * V_13 )
{
struct V_4 * V_5 = F_15 ( V_13 ) ;
F_16 ( V_5 -> V_37 ) ;
return 0 ;
}
