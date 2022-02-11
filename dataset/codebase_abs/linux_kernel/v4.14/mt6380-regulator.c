static int F_1 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
int V_4 , V_5 = 0 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
switch ( V_3 ) {
case V_8 :
V_5 = V_9 ;
break;
case V_10 :
V_5 = V_11 ;
break;
default:
return - V_12 ;
}
V_5 <<= F_3 ( V_7 -> V_13 ) - 1 ;
V_4 = F_4 ( V_2 -> V_14 , V_7 -> V_15 ,
V_7 -> V_13 , V_5 ) ;
return V_4 ;
}
static unsigned int F_5 ( struct V_1 * V_2 )
{
unsigned int V_5 ;
unsigned int V_3 ;
int V_4 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
V_4 = F_6 ( V_2 -> V_14 , V_7 -> V_15 , & V_5 ) ;
if ( V_4 < 0 )
return V_4 ;
V_5 &= V_7 -> V_13 ;
V_5 >>= F_3 ( V_7 -> V_13 ) - 1 ;
switch ( V_5 ) {
case V_9 :
V_3 = V_8 ;
break;
case V_11 :
V_3 = V_10 ;
break;
default:
return - V_12 ;
}
return V_3 ;
}
static int F_7 ( struct V_16 * V_17 )
{
struct V_14 * V_14 = F_8 ( V_17 -> V_18 . V_19 , NULL ) ;
struct V_20 V_21 = {} ;
struct V_1 * V_2 ;
int V_22 ;
for ( V_22 = 0 ; V_22 < V_23 ; V_22 ++ ) {
V_21 . V_18 = & V_17 -> V_18 ;
V_21 . V_24 = & V_25 [ V_22 ] ;
V_21 . V_14 = V_14 ;
V_2 = F_9 ( & V_17 -> V_18 ,
& V_25 [ V_22 ] . V_26 ,
& V_21 ) ;
if ( F_10 ( V_2 ) ) {
F_11 ( & V_17 -> V_18 , L_1 ,
V_25 [ V_22 ] . V_26 . V_27 ) ;
return F_12 ( V_2 ) ;
}
}
return 0 ;
}
