static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
T_2 V_4 ;
int V_5 = 50 ;
while ( V_5 -- > 0 ) {
V_4 = F_2 ( V_2 -> V_6 ,
V_7 ) ;
if ( V_4 < 0 )
return V_4 ;
if ( V_4 & V_8 )
break;
F_3 ( 100 ) ;
}
if ( V_5 < 0 )
return - V_9 ;
return F_2 ( V_2 -> V_6 , V_3 ) ;
}
static int F_4 ( struct V_10 * V_11 ,
struct V_12 const * V_13 , int * V_14 ,
int * V_15 , long V_16 )
{
struct V_1 * V_2 = F_5 ( V_11 ) ;
T_2 V_4 ;
switch ( V_16 ) {
case V_17 :
if ( V_13 -> type == V_18 ) {
V_4 = F_1 ( V_2 , V_19 ) ;
if ( V_4 < 0 )
return V_4 ;
* V_14 = F_6 ( V_4 , 15 ) ;
} else if ( V_13 -> type == V_20 ) {
V_4 = F_1 ( V_2 , V_21 ) ;
if ( V_4 < 0 )
return V_4 ;
* V_14 = F_6 ( V_4 , 15 ) >> V_22 ;
} else {
break;
}
return V_23 ;
case V_24 :
if ( V_13 -> type == V_18 ) {
* V_14 = 0 ;
* V_15 = 156250 ;
} else if ( V_13 -> type == V_20 ) {
* V_14 = 31 ;
* V_15 = 250000 ;
} else {
break;
}
return V_25 ;
default:
break;
}
return - V_26 ;
}
static T_3 F_7 ( struct V_27 * V_28 ,
struct V_29 * V_30 , char * V_31 )
{
struct V_1 * V_2 = F_5 ( F_8 ( V_28 ) ) ;
int V_32 = ( V_2 -> V_33 & V_34 )
>> V_35 ;
return sprintf ( V_31 , L_1 , V_36 [ V_32 ] ) ;
}
static T_3 F_9 ( struct V_27 * V_28 ,
struct V_29 * V_30 ,
const char * V_31 , T_4 V_37 )
{
struct V_10 * V_11 = F_8 ( V_28 ) ;
struct V_1 * V_2 = F_5 ( V_11 ) ;
int V_38 ;
bool V_39 = false ;
for ( V_38 = 0 ; V_38 < F_10 ( V_36 ) ; V_38 ++ )
if ( F_11 ( V_31 , V_36 [ V_38 ] ) ) {
V_39 = true ;
break;
}
if ( ! V_39 )
return - V_26 ;
V_2 -> V_33 &= ~ V_34 ;
V_2 -> V_33 |= V_38 << V_35 ;
return F_12 ( V_2 -> V_6 , V_7 ,
V_2 -> V_33 ) ;
}
static bool F_13 ( struct V_40 * V_6 )
{
int V_41 , V_42 ;
V_41 = F_2 ( V_6 , V_43 ) ;
if ( V_41 < 0 )
return false ;
V_42 = F_2 ( V_6 , V_44 ) ;
if ( V_42 < 0 )
return false ;
return V_41 == V_45 && V_42 == V_46 ;
}
static int F_14 ( struct V_40 * V_6 ,
const struct V_47 * V_48 )
{
struct V_10 * V_11 ;
struct V_1 * V_2 ;
int V_4 ;
if ( ! F_15 ( V_6 -> V_49 , V_50 ) )
return - V_51 ;
if ( ! F_13 ( V_6 ) ) {
F_16 ( & V_6 -> V_28 , L_2 ) ;
return - V_51 ;
}
V_11 = F_17 ( & V_6 -> V_28 , sizeof( * V_2 ) ) ;
if ( ! V_11 )
return - V_52 ;
V_2 = F_5 ( V_11 ) ;
F_18 ( V_6 , V_11 ) ;
V_2 -> V_6 = V_6 ;
V_11 -> V_28 . V_53 = & V_6 -> V_28 ;
V_11 -> V_54 = F_19 ( & V_6 -> V_28 ) ;
V_11 -> V_55 = V_56 ;
V_11 -> V_57 = & V_58 ;
V_11 -> V_59 = V_60 ;
V_11 -> V_61 = F_10 ( V_60 ) ;
V_4 = F_2 ( V_2 -> V_6 , V_7 ) ;
if ( V_4 < 0 )
return V_4 ;
V_2 -> V_33 = V_4 ;
return F_20 ( V_11 ) ;
}
static int F_21 ( struct V_1 * V_2 )
{
return F_12 ( V_2 -> V_6 , V_7 ,
V_2 -> V_33 & ~ V_62 ) ;
}
static int F_22 ( struct V_40 * V_6 )
{
struct V_10 * V_11 = F_23 ( V_6 ) ;
F_24 ( V_11 ) ;
F_21 ( F_5 ( V_11 ) ) ;
return 0 ;
}
static int F_25 ( struct V_27 * V_28 )
{
struct V_10 * V_11 = F_23 ( F_26 ( V_28 ) ) ;
return F_21 ( F_5 ( V_11 ) ) ;
}
static int F_27 ( struct V_27 * V_28 )
{
struct V_1 * V_2 = F_5 ( F_23 (
F_26 ( V_28 ) ) ) ;
return F_12 ( V_2 -> V_6 , V_7 ,
V_2 -> V_33 | V_62 ) ;
}
