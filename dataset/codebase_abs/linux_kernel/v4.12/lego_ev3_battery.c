static int F_1 ( struct V_1 * V_2 ,
enum V_3 V_4 ,
union V_5 * V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
int V_9 ;
switch ( V_4 ) {
case V_10 :
V_6 -> V_11 = V_8 -> V_12 ;
break;
case V_13 :
F_3 ( V_8 -> V_14 , & V_6 -> V_11 ) ;
V_6 -> V_11 *= 2000 ;
V_6 -> V_11 += 200000 ;
F_3 ( V_8 -> V_15 , & V_9 ) ;
V_9 *= 1000 ;
V_9 /= 15 ;
V_6 -> V_11 += V_9 ;
break;
case V_16 :
V_6 -> V_11 = V_8 -> V_17 ;
break;
case V_18 :
V_6 -> V_11 = V_8 -> V_19 ;
break;
case V_20 :
F_3 ( V_8 -> V_15 , & V_6 -> V_11 ) ;
V_6 -> V_11 *= 20000 ;
V_6 -> V_11 /= 15 ;
break;
case V_21 :
V_6 -> V_11 = V_22 ;
break;
default:
return - V_23 ;
}
return 0 ;
}
static int F_4 ( struct V_1 * V_2 ,
enum V_3 V_4 ,
const union V_5 * V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
switch ( V_4 ) {
case V_10 :
if ( V_8 -> V_12 != V_24 )
return - V_23 ;
switch ( V_6 -> V_11 ) {
case V_25 :
V_8 -> V_12 = V_25 ;
V_8 -> V_17 = 7800000 ;
V_8 -> V_19 = 5400000 ;
break;
default:
return - V_23 ;
}
break;
default:
return - V_23 ;
}
return 0 ;
}
static int F_5 ( struct V_1 * V_2 ,
enum V_3 V_4 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
return V_4 == V_10 &&
V_8 -> V_12 == V_24 ;
}
static int F_6 ( struct V_26 * V_27 )
{
struct V_28 * V_29 = & V_27 -> V_29 ;
struct V_7 * V_8 ;
struct V_30 V_31 = {} ;
int V_32 ;
V_8 = F_7 ( V_29 , sizeof( * V_8 ) , V_33 ) ;
if ( ! V_8 )
return - V_34 ;
F_8 ( V_27 , V_8 ) ;
V_8 -> V_14 = F_9 ( V_29 , L_1 ) ;
V_32 = F_10 ( V_8 -> V_14 ) ;
if ( V_32 ) {
if ( V_32 != - V_35 )
F_11 ( V_29 , L_2 ) ;
return V_32 ;
}
V_8 -> V_15 = F_9 ( V_29 , L_3 ) ;
V_32 = F_10 ( V_8 -> V_15 ) ;
if ( V_32 ) {
if ( V_32 != - V_35 )
F_11 ( V_29 , L_4 ) ;
return V_32 ;
}
V_8 -> V_36 = F_12 ( V_29 , L_5 , V_37 ) ;
V_32 = F_10 ( V_8 -> V_36 ) ;
if ( V_32 ) {
if ( V_32 != - V_35 )
F_11 ( V_29 , L_6 ) ;
return V_32 ;
}
if ( F_13 ( V_8 -> V_36 ) ) {
V_8 -> V_12 = V_38 ;
V_8 -> V_17 = 84000000 ;
V_8 -> V_19 = 60000000 ;
} else {
V_8 -> V_12 = V_24 ;
V_8 -> V_17 = 90000000 ;
V_8 -> V_19 = 48000000 ;
}
V_31 . V_39 = V_27 -> V_29 . V_39 ;
V_31 . V_40 = V_8 ;
V_8 -> V_2 = F_14 ( V_29 , & V_41 ,
& V_31 ) ;
V_32 = F_10 ( V_8 -> V_2 ) ;
if ( V_32 ) {
F_11 ( V_29 , L_7 ) ;
return V_32 ;
}
return 0 ;
}
