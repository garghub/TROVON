static int F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
struct V_5 V_6 = { } ;
struct V_7 * V_8 ;
struct V_9 * V_9 ;
int V_10 , V_11 ;
unsigned int V_12 ;
V_9 = F_2 ( V_2 , & V_13 ) ;
if ( F_3 ( V_9 ) ) {
V_11 = F_4 ( V_9 ) ;
F_5 ( & V_2 -> V_14 , L_1 ,
V_11 ) ;
return V_11 ;
}
V_11 = F_6 ( V_9 , V_15 , & V_12 ) ;
if ( V_11 < 0 ) {
F_5 ( & V_2 -> V_14 , L_2 , V_11 ) ;
return V_11 ;
}
switch ( V_12 ) {
case V_16 :
case V_17 :
case V_18 :
break;
default:
F_5 ( & V_2 -> V_14 , L_3 , V_12 ) ;
return - V_19 ;
}
for ( V_10 = 0 ; V_10 < V_20 ; V_10 ++ ) {
V_6 . V_14 = & V_2 -> V_14 ;
V_6 . V_9 = V_9 ;
V_8 = F_7 ( & V_2 -> V_14 ,
& V_21 [ V_10 ] , & V_6 ) ;
if ( F_3 ( V_8 ) ) {
F_5 ( & V_2 -> V_14 ,
L_4 ) ;
return F_4 ( V_8 ) ;
}
}
return 0 ;
}
