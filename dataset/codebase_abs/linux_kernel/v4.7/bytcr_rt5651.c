static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_9 ;
int V_10 ;
F_2 ( V_9 , 50 ) ;
V_10 = F_3 ( V_9 , V_11 ,
F_4 ( V_4 ) * 512 ,
V_12 ) ;
if ( V_10 < 0 ) {
F_5 ( V_6 -> V_13 , L_1 , V_10 ) ;
return V_10 ;
}
V_10 = F_6 ( V_9 , 0 , V_14 ,
F_4 ( V_4 ) * 50 ,
F_4 ( V_4 ) * 512 ) ;
if ( V_10 < 0 ) {
F_5 ( V_6 -> V_13 , L_2 , V_10 ) ;
return V_10 ;
}
return 0 ;
}
static int F_7 ( struct V_5 * V_15 )
{
int V_10 ;
struct V_16 * V_17 = V_15 -> V_17 ;
const struct V_18 * V_19 ;
int V_20 ;
V_17 -> V_21 . V_22 = true ;
F_8 ( V_23 ) ;
switch ( F_9 ( V_24 ) ) {
case V_25 :
V_19 = V_26 ;
V_20 = F_10 ( V_26 ) ;
break;
case V_27 :
V_19 = V_28 ;
V_20 = F_10 ( V_28 ) ;
break;
default:
V_19 = V_29 ;
V_20 = F_10 ( V_29 ) ;
}
V_10 = F_11 ( V_17 , V_30 ,
F_10 ( V_30 ) ) ;
if ( V_10 ) {
F_5 ( V_17 -> V_13 , L_3 ) ;
return V_10 ;
}
F_12 ( & V_17 -> V_21 , L_4 ) ;
F_12 ( & V_17 -> V_21 , L_5 ) ;
return V_10 ;
}
static int F_13 ( struct V_5 * V_6 ,
struct V_3 * V_4 )
{
struct V_31 * V_32 = F_14 ( V_4 ,
V_33 ) ;
struct V_31 * V_34 = F_14 ( V_4 ,
V_35 ) ;
int V_10 ;
V_32 -> V_36 = V_32 -> V_37 = 48000 ;
V_34 -> V_36 = V_34 -> V_37 = 2 ;
F_15 ( V_4 , V_38 ) ;
V_10 = F_16 ( V_6 -> V_39 ,
V_40 |
V_41 |
V_42
) ;
if ( V_10 < 0 ) {
F_5 ( V_6 -> V_13 , L_6 , V_10 ) ;
return V_10 ;
}
V_10 = F_17 ( V_6 -> V_39 , 0x3 , 0x3 , 2 , 24 ) ;
if ( V_10 < 0 ) {
F_5 ( V_6 -> V_13 , L_7 , V_10 ) ;
return V_10 ;
}
return 0 ;
}
static int F_18 ( struct V_1 * V_2 )
{
return F_19 ( V_2 -> V_15 , 0 ,
V_33 ,
& V_43 ) ;
}
static int F_20 ( struct V_44 * V_45 )
{
int V_46 = 0 ;
V_47 . V_13 = & V_45 -> V_13 ;
V_46 = F_21 ( & V_45 -> V_13 , & V_47 ) ;
if ( V_46 ) {
F_5 ( & V_45 -> V_13 , L_8 ,
V_46 ) ;
return V_46 ;
}
F_22 ( V_45 , & V_47 ) ;
return V_46 ;
}
