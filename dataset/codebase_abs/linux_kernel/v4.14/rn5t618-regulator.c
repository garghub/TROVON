static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 -> V_4 . V_5 ) ;
struct V_6 V_7 = { } ;
struct V_8 * V_9 ;
struct V_10 * V_11 ;
int V_12 ;
int V_13 = 0 ;
switch ( V_3 -> V_14 ) {
case V_15 :
V_11 = V_16 ;
V_13 = F_3 ( V_16 ) ;
break;
case V_17 :
V_11 = V_18 ;
V_13 = F_3 ( V_18 ) ;
break;
case V_19 :
V_11 = V_20 ;
V_13 = F_3 ( V_20 ) ;
break;
default:
return - V_21 ;
}
V_7 . V_4 = V_2 -> V_4 . V_5 ;
V_7 . V_22 = V_3 -> V_22 ;
for ( V_12 = 0 ; V_12 < V_13 ; V_12 ++ ) {
V_9 = F_4 ( & V_2 -> V_4 ,
& V_11 [ V_12 ] ,
& V_7 ) ;
if ( F_5 ( V_9 ) ) {
F_6 ( & V_2 -> V_4 , L_1 ,
V_11 [ V_12 ] . V_23 ) ;
return F_7 ( V_9 ) ;
}
}
return 0 ;
}
