static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
T_1 V_4 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_3 = F_3 ( V_2 -> V_7 , V_6 -> V_8 . V_9 , & V_4 ) ;
if ( V_3 != 0 ) {
F_4 ( & V_2 -> V_10 , L_1 , V_3 ) ;
return V_3 ;
}
return ( V_4 & V_6 -> V_11 ) ? V_12 : V_13 ;
}
static int F_5 ( struct V_14 * V_15 )
{
struct V_16 * V_17 = F_6 ( V_15 -> V_10 . V_18 ) ;
int V_19 ;
T_1 V_4 ;
for ( V_19 = 0 ; V_19 < V_20 ; V_19 ++ ) {
if ( V_21 [ V_19 ] . V_22 ) {
if ( F_3 ( V_17 -> V_7 ,
V_21 [ V_19 ] . V_22 ,
& V_4 ) < 0 ) {
F_4 ( & V_15 -> V_10 ,
L_2 ) ;
return - V_23 ;
}
if ( V_4 & V_21 [ V_19 ] . V_24 ) {
V_21 [ V_19 ] . V_8 . V_25 =
V_21 [ V_19 ] . V_26 ;
}
}
}
return 0 ;
}
static int F_7 ( struct V_14 * V_15 )
{
struct V_16 * V_17 = F_6 ( V_15 -> V_10 . V_18 ) ;
struct V_27 V_28 = {} ;
struct V_1 * V_2 ;
int V_19 ;
T_1 V_29 , V_30 ;
if ( F_5 ( V_15 ) )
return - V_23 ;
if ( F_3 ( V_17 -> V_7 , V_31 , & V_29 ) < 0 ) {
F_4 ( & V_15 -> V_10 , L_3 ) ;
return - V_23 ;
}
F_8 ( & V_15 -> V_10 , L_4 , V_29 ) ;
V_30 = ( V_29 & 0xFF ) ;
switch ( V_30 ) {
case V_32 :
V_21 [ V_33 ] . V_8 . V_34 =
V_35 ;
break;
default:
break;
}
for ( V_19 = 0 ; V_19 < V_20 ; V_19 ++ ) {
V_28 . V_10 = & V_15 -> V_10 ;
V_28 . V_36 = & V_21 [ V_19 ] ;
V_28 . V_7 = V_17 -> V_7 ;
V_2 = F_9 ( & V_15 -> V_10 ,
& V_21 [ V_19 ] . V_8 , & V_28 ) ;
if ( F_10 ( V_2 ) ) {
F_4 ( & V_15 -> V_10 , L_5 ,
V_21 [ V_19 ] . V_8 . V_37 ) ;
return F_11 ( V_2 ) ;
}
}
return 0 ;
}
