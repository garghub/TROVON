static unsigned int F_1 (
struct V_1 * V_2 )
{
struct V_3 * V_4 ;
unsigned int V_5 ;
V_4 = F_2 ( V_2 ) ;
F_3 ( V_2 -> V_6 , V_2 -> V_7 -> V_8 , & V_5 ) ;
if ( V_5 & ( V_4 -> V_9 ) )
return V_10 ;
return V_11 ;
}
static int F_4 ( struct V_1 * V_2 ,
unsigned int V_12 )
{
struct V_3 * V_4 ;
unsigned int V_13 ;
V_4 = F_2 ( V_2 ) ;
switch ( V_12 ) {
case V_11 :
V_13 = 0 ;
break;
case V_10 :
V_13 = V_4 -> V_9 ;
break;
default:
return - V_14 ;
}
F_5 ( V_2 -> V_6 , V_2 -> V_7 -> V_8 ,
V_4 -> V_9 , V_13 ) ;
return 0 ;
}
static int F_6 ( struct V_15 * V_16 )
{
struct V_17 * V_18 ;
struct V_1 * V_2 ;
struct V_19 V_20 = { } ;
unsigned int V_21 ;
V_18 = F_7 ( V_16 -> V_22 . V_23 ) ;
if ( ! V_18 ) {
F_8 ( & V_16 -> V_22 , L_1 ) ;
return - V_24 ;
}
for ( V_21 = 0 ; V_21 < F_9 ( V_3 ) ; V_21 ++ ) {
V_20 . V_22 = V_16 -> V_22 . V_23 ;
V_20 . V_6 = V_18 -> V_6 ;
V_20 . V_25 = & V_3 [ V_21 ] ;
V_2 = F_10 ( & V_16 -> V_22 ,
& V_3 [ V_21 ] . V_26 ,
& V_20 ) ;
if ( F_11 ( V_2 ) ) {
F_8 ( & V_16 -> V_22 , L_2 ,
V_3 [ V_21 ] . V_26 . V_27 ) ;
return F_12 ( V_2 ) ;
}
}
return 0 ;
}
