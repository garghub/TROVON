static int F_1 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_6 , V_7 ;
switch ( V_3 ) {
case V_8 :
V_7 = V_9 ;
break;
case V_10 :
V_7 = V_11 ;
break;
default:
V_6 = - V_12 ;
goto V_13;
}
F_3 ( & V_2 -> V_14 , L_1 ,
V_5 -> V_15 , V_5 -> V_16 ,
V_5 -> V_17 , V_7 ) ;
V_7 <<= V_5 -> V_17 ;
V_6 = F_4 ( V_2 -> V_18 , V_5 -> V_15 ,
V_5 -> V_16 , V_7 ) ;
V_13:
if ( V_6 != 0 ) {
F_5 ( & V_2 -> V_14 ,
L_2 , V_6 ) ;
return V_6 ;
}
return 0 ;
}
static unsigned int F_6 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_6 , V_19 ;
V_6 = F_7 ( V_2 -> V_18 , V_5 -> V_15 , & V_19 ) ;
if ( V_6 != 0 ) {
F_5 ( & V_2 -> V_14 ,
L_3 , V_6 ) ;
return V_6 ;
}
switch ( ( V_19 & V_5 -> V_16 ) >> V_5 -> V_17 ) {
case V_11 :
return V_10 ;
case V_9 :
return V_8 ;
default:
return - V_12 ;
}
}
static int F_8 ( struct V_1 * V_2 )
{
int V_6 ;
T_1 V_19 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
V_6 = F_7 ( V_2 -> V_18 , V_5 -> V_20 . V_21 , & V_19 ) ;
if ( V_6 != 0 ) {
F_5 ( & V_2 -> V_14 , L_4 , V_6 ) ;
return V_6 ;
}
return ( V_19 & V_5 -> V_22 ) ? V_23 : V_24 ;
}
static int F_9 ( struct V_25 * V_26 )
{
struct V_27 * V_28 = F_10 ( V_26 -> V_14 . V_29 ) ;
int V_30 ;
T_1 V_19 ;
for ( V_30 = 0 ; V_30 < V_31 ; V_30 ++ ) {
if ( V_32 [ V_30 ] . V_33 ) {
if ( F_7 ( V_28 -> V_18 ,
V_32 [ V_30 ] . V_33 ,
& V_19 ) < 0 ) {
F_5 ( & V_26 -> V_14 ,
L_5 ) ;
return - V_34 ;
}
if ( V_19 & V_32 [ V_30 ] . V_35 ) {
V_32 [ V_30 ] . V_20 . V_36 =
V_32 [ V_30 ] . V_37 ;
}
}
}
return 0 ;
}
static int F_11 ( struct V_25 * V_26 )
{
struct V_27 * V_28 = F_10 ( V_26 -> V_14 . V_29 ) ;
struct V_38 V_39 = {} ;
struct V_1 * V_2 ;
int V_30 ;
T_1 V_40 , V_41 ;
if ( F_9 ( V_26 ) )
return - V_34 ;
if ( F_7 ( V_28 -> V_18 , V_42 , & V_40 ) < 0 ) {
F_5 ( & V_26 -> V_14 , L_6 ) ;
return - V_34 ;
}
F_12 ( & V_26 -> V_14 , L_7 , V_40 ) ;
V_41 = ( V_40 & 0xFF ) ;
switch ( V_41 ) {
case V_43 :
V_32 [ V_44 ] . V_20 . V_45 =
V_46 ;
break;
default:
break;
}
for ( V_30 = 0 ; V_30 < V_31 ; V_30 ++ ) {
V_39 . V_14 = & V_26 -> V_14 ;
V_39 . V_47 = & V_32 [ V_30 ] ;
V_39 . V_18 = V_28 -> V_18 ;
V_2 = F_13 ( & V_26 -> V_14 ,
& V_32 [ V_30 ] . V_20 , & V_39 ) ;
if ( F_14 ( V_2 ) ) {
F_5 ( & V_26 -> V_14 , L_8 ,
V_32 [ V_30 ] . V_20 . V_48 ) ;
return F_15 ( V_2 ) ;
}
}
return 0 ;
}
