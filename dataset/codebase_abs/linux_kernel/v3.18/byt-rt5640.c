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
struct V_22 * V_23 = & V_21 -> V_23 ;
struct V_24 * V_25 = V_19 -> V_25 ;
const struct V_26 * V_27 ;
int V_28 ;
V_25 -> V_23 . V_29 = true ;
V_10 = F_8 ( V_25 , V_30 ,
F_9 ( V_30 ) ) ;
if ( V_10 ) {
F_4 ( V_25 -> V_13 , L_3 ) ;
return V_10 ;
}
F_10 ( V_31 ) ;
switch ( F_11 ( V_17 ) ) {
case V_32 :
V_27 = V_33 ;
V_28 = F_9 ( V_33 ) ;
break;
case V_34 :
V_27 = V_35 ;
V_28 = F_9 ( V_35 ) ;
break;
default:
V_27 = V_36 ;
V_28 = F_9 ( V_36 ) ;
}
V_10 = F_12 ( V_23 , V_27 , V_28 ) ;
if ( V_10 )
return V_10 ;
if ( V_17 & V_37 ) {
V_10 = F_13 ( V_21 , 0 , 0 ) ;
if ( V_10 )
return V_10 ;
}
F_14 ( V_23 , L_4 ) ;
F_14 ( V_23 , L_5 ) ;
F_14 ( V_23 , L_6 ) ;
F_14 ( V_23 , L_7 ) ;
F_14 ( V_23 , L_8 ) ;
F_14 ( V_23 , L_9 ) ;
return V_10 ;
}
static int F_15 ( struct V_38 * V_39 )
{
struct V_24 * V_25 = & V_40 ;
V_25 -> V_13 = & V_39 -> V_13 ;
return F_16 ( & V_39 -> V_13 , V_25 ) ;
}
