static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 -> V_4 . V_5 ) ;
struct V_6 V_7 = { } ;
struct V_8 * V_9 ;
struct V_10 * V_11 ;
int V_12 ;
switch ( V_3 -> V_13 ) {
case V_14 :
V_11 = V_15 ;
break;
case V_16 :
V_11 = V_17 ;
break;
default:
return - V_18 ;
}
V_7 . V_4 = V_2 -> V_4 . V_5 ;
V_7 . V_19 = V_3 -> V_19 ;
for ( V_12 = 0 ; V_12 < V_20 ; V_12 ++ ) {
if ( ! V_11 [ V_12 ] . V_21 )
continue;
V_9 = F_3 ( & V_2 -> V_4 ,
& V_11 [ V_12 ] ,
& V_7 ) ;
if ( F_4 ( V_9 ) ) {
F_5 ( & V_2 -> V_4 , L_1 ,
V_11 [ V_12 ] . V_21 ) ;
return F_6 ( V_9 ) ;
}
}
return 0 ;
}
