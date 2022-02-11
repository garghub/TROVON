static int F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 ,
struct V_5 * V_6 )
{
int V_7 ;
if ( F_2 ( V_6 -> V_8 , L_1 ) ) {
switch ( V_4 -> V_9 ) {
case V_10 :
case V_11 :
case V_12 :
V_13 [ V_4 -> V_9 ] . V_4 . V_14 =
V_15 ;
V_13 [ V_4 -> V_9 ] . V_4 . V_16 =
F_3 ( V_15 ) ;
break;
case V_17 :
case V_18 :
case V_19 :
V_13 [ V_4 -> V_9 ] . V_4 . V_14 =
V_20 ;
V_13 [ V_4 -> V_9 ] . V_4 . V_16 =
F_3 ( V_20 ) ;
break;
default:
F_4 ( V_6 -> V_2 , L_2 ) ;
}
}
if ( V_4 -> V_9 <= V_12 && F_2 ( V_6 -> V_8 , L_3 ) ) {
V_7 = F_5 ( V_6 -> V_21 ,
V_13 [ V_4 -> V_9 ] . V_22 ,
V_13 [ V_4 -> V_9 ] . V_23 ,
V_13 [ V_4 -> V_9 ] . V_23 ) ;
if ( V_7 ) {
F_6 ( V_6 -> V_2 , L_4 ) ;
return V_7 ;
}
}
return 0 ;
}
static int F_7 ( struct V_24 * V_25 )
{
struct V_26 * V_27 = F_8 ( V_25 -> V_2 . V_28 ) ;
struct V_5 V_6 = { } ;
struct V_29 * V_30 ;
int V_31 ;
F_9 ( V_25 , V_27 ) ;
V_6 . V_2 = & V_25 -> V_2 ;
V_6 . V_2 -> V_8 = V_27 -> V_2 -> V_8 ;
V_6 . V_32 = V_27 ;
V_6 . V_21 = V_27 -> V_21 ;
for ( V_31 = 0 ; V_31 < F_3 ( V_13 ) ; V_31 ++ ) {
V_30 = F_10 ( & V_25 -> V_2 , & V_13 [ V_31 ] . V_4 ,
& V_6 ) ;
if ( F_11 ( V_30 ) ) {
F_6 ( V_27 -> V_2 , L_5 ,
V_25 -> V_33 ) ;
return F_12 ( V_30 ) ;
}
}
return 0 ;
}
