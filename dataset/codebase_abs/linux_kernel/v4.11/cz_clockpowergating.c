int F_1 ( struct V_1 * V_2 , enum V_3 V_4 , enum V_5 V_6 )
{
int V_7 = 0 ;
switch ( V_4 ) {
case V_8 :
case V_9 :
case V_10 :
case V_11 :
if ( V_6 == V_12 )
V_7 = F_2 ( V_2 ) ;
else
V_7 = F_3 ( V_2 ) ;
break;
case V_13 :
default:
break;
}
return V_7 ;
}
bool F_4 ( struct V_1 * V_2 , const struct V_14 * V_15 , enum V_3 V_4 )
{
return true ;
}
int F_5 ( struct V_1 * V_2 , bool V_16 )
{
return 0 ;
}
int F_6 ( struct V_1 * V_2 , T_1 V_17 , bool V_18 , T_1 args )
{
return 0 ;
}
int F_7 ( struct V_1 * V_2 , bool V_19 , bool V_20 )
{
return 0 ;
}
int F_8 ( struct V_1 * V_2 )
{
return 0 ;
}
int F_9 ( struct V_1 * V_2 )
{
return 0 ;
}
int F_10 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_11 ( struct V_1 * V_2 , void * V_21 , void * V_22 , void * V_23 , int V_24 )
{
return 0 ;
}
static int F_12 ( struct V_1 * V_2 , void * V_21 , void * V_22 , void * V_23 , int V_24 )
{
return 0 ;
}
int F_13 ( struct V_1 * V_2 , bool V_16 )
{
struct V_25 * V_25 = (struct V_25 * ) ( V_2 -> V_26 ) ;
T_1 V_27 = 0 ;
if ( V_16 &&
F_14 ( V_2 -> V_28 . V_29 ,
V_30 ) ) {
V_25 -> V_31 |= V_32 ;
V_27 |= V_33 ;
F_15 ( V_2 -> V_34 ,
V_35 , V_27 ) ;
} else {
V_27 |= V_33 ;
V_25 -> V_31 &= ~ V_32 ;
F_15 ( V_2 -> V_34 ,
V_36 , V_27 ) ;
}
return 0 ;
}
int F_16 ( struct V_1 * V_2 , bool V_16 )
{
struct V_25 * V_25 = (struct V_25 * ) ( V_2 -> V_26 ) ;
T_1 V_27 = 0 ;
if ( V_16 && F_14 (
V_2 -> V_28 . V_29 ,
V_37 ) ) {
V_25 -> V_31 |= V_38 ;
V_27 |= V_39 ;
F_15 ( V_2 -> V_34 ,
V_35 , V_27 ) ;
} else {
V_27 |= V_39 ;
V_25 -> V_31 &= ~ V_38 ;
F_15 ( V_2 -> V_34 ,
V_36 , V_27 ) ;
}
return 0 ;
}
int F_17 ( struct V_1 * V_2 , bool V_40 )
{
struct V_25 * V_25 = (struct V_25 * ) ( V_2 -> V_26 ) ;
V_25 -> V_41 = V_40 ;
if ( V_40 ) {
F_18 ( V_2 -> V_42 ,
V_43 ,
V_44 ) ;
F_19 ( V_2 -> V_42 ,
V_43 ,
V_45 ) ;
F_20 ( V_2 , true ) ;
F_2 ( V_2 ) ;
} else {
F_3 ( V_2 ) ;
F_19 ( V_2 -> V_42 ,
V_43 ,
V_46 ) ;
F_18 ( V_2 -> V_42 ,
V_43 ,
V_47 ) ;
F_20 ( V_2 , false ) ;
}
return 0 ;
}
int F_21 ( struct V_1 * V_2 , bool V_40 )
{
struct V_25 * V_25 = (struct V_25 * ) ( V_2 -> V_26 ) ;
if ( V_40 ) {
F_18 (
V_2 -> V_42 ,
V_48 ,
V_44 ) ;
F_19 (
V_2 -> V_42 ,
V_48 ,
V_45 ) ;
F_16 ( V_2 , false ) ;
F_22 ( V_2 ) ;
V_25 -> V_49 = true ;
} else {
F_23 ( V_2 ) ;
V_25 -> V_49 = false ;
F_19 (
V_2 -> V_42 ,
V_48 ,
V_46 ) ;
F_18 (
V_2 -> V_42 ,
V_48 ,
V_47 ) ;
F_24 ( V_2 ) ;
F_16 ( V_2 , true ) ;
return 0 ;
}
return 0 ;
}
