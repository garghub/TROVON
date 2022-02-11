static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_9 ;
int V_10 ;
V_10 = F_2 ( V_9 , V_11 ,
F_3 ( V_4 ) * 256 ,
V_12 ) ;
if ( V_10 < 0 ) {
F_4 ( V_9 -> V_13 , L_1 , V_10 ) ;
return V_10 ;
}
V_10 = F_5 ( V_9 , 0 , V_14 ,
F_3 ( V_4 ) * 64 ,
F_3 ( V_4 ) * 256 ) ;
if ( V_10 < 0 ) {
F_4 ( V_9 -> V_13 , L_2 , V_10 ) ;
return V_10 ;
}
return 0 ;
}
static int F_6 ( const struct V_15 * V_16 )
{
V_17 = ( unsigned long ) V_16 -> V_18 ;
return 1 ;
}
static int F_7 ( struct V_5 * V_19 )
{
int V_10 ;
struct V_20 * V_21 = V_19 -> V_21 ;
struct V_22 * V_23 = V_19 -> V_23 ;
const struct V_24 * V_25 ;
int V_26 ;
V_23 -> V_27 . V_28 = true ;
V_10 = F_8 ( V_23 , V_29 ,
F_9 ( V_29 ) ) ;
if ( V_10 ) {
F_4 ( V_23 -> V_13 , L_3 ) ;
return V_10 ;
}
F_10 ( V_30 ) ;
switch ( F_11 ( V_17 ) ) {
case V_31 :
V_25 = V_32 ;
V_26 = F_9 ( V_32 ) ;
break;
case V_33 :
V_25 = V_34 ;
V_26 = F_9 ( V_34 ) ;
break;
default:
V_25 = V_35 ;
V_26 = F_9 ( V_35 ) ;
}
V_10 = F_12 ( & V_23 -> V_27 , V_25 , V_26 ) ;
if ( V_10 )
return V_10 ;
if ( V_17 & V_36 ) {
V_10 = F_13 ( V_21 , 0 , 0 ) ;
if ( V_10 )
return V_10 ;
}
F_14 ( & V_23 -> V_27 , L_4 ) ;
F_14 ( & V_23 -> V_27 , L_5 ) ;
return V_10 ;
}
static int F_15 ( struct V_37 * V_38 )
{
struct V_22 * V_23 = & V_39 ;
V_23 -> V_13 = & V_38 -> V_13 ;
return F_16 ( & V_38 -> V_13 , V_23 ) ;
}
