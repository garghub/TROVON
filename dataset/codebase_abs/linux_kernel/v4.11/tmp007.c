static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
T_2 V_4 ;
int V_5 = 50 ;
while ( V_5 -- > 0 ) {
V_4 = F_2 ( V_2 -> V_6 ,
V_7 ) ;
if ( V_4 < 0 )
return V_4 ;
if ( ( V_4 & V_8 ) &&
! ( V_4 & V_9 ) )
break;
F_3 ( 100 ) ;
}
if ( V_5 < 0 )
return - V_10 ;
return F_2 ( V_2 -> V_6 , V_3 ) ;
}
static int F_4 ( struct V_1 * V_2 )
{
return F_5 ( V_2 -> V_6 , V_11 ,
V_2 -> V_12 & ~ V_13 ) ;
}
static int F_6 ( struct V_14 * V_15 ,
struct V_16 const * V_17 , int * V_18 ,
int * V_19 , long V_20 )
{
struct V_1 * V_2 = F_7 ( V_15 ) ;
T_2 V_4 ;
int V_21 ;
switch ( V_20 ) {
case V_22 :
switch ( V_17 -> V_23 ) {
case V_24 :
V_4 = F_2 ( V_2 -> V_6 , V_25 ) ;
if ( V_4 < 0 )
return V_4 ;
break;
case V_26 :
V_4 = F_1 ( V_2 , V_27 ) ;
if ( V_4 < 0 )
return V_4 ;
break;
default:
return - V_28 ;
}
* V_18 = F_8 ( V_4 , 15 ) >> V_29 ;
return V_30 ;
case V_31 :
* V_18 = 31 ;
* V_19 = 250000 ;
return V_32 ;
case V_33 :
V_21 = ( V_2 -> V_12 & V_34 )
>> V_35 ;
* V_18 = V_36 [ V_21 ] [ 0 ] ;
* V_19 = V_36 [ V_21 ] [ 1 ] ;
return V_32 ;
default:
return - V_28 ;
}
}
static int F_9 ( struct V_14 * V_15 ,
struct V_16 const * V_17 , int V_18 ,
int V_19 , long V_20 )
{
struct V_1 * V_2 = F_7 ( V_15 ) ;
int V_37 ;
T_3 V_38 ;
if ( V_20 == V_33 ) {
for ( V_37 = 0 ; V_37 < F_10 ( V_36 ) ; V_37 ++ ) {
if ( ( V_18 == V_36 [ V_37 ] [ 0 ] ) &&
( V_19 == V_36 [ V_37 ] [ 1 ] ) ) {
V_38 = V_2 -> V_12 & ~ V_34 ;
V_38 |= ( V_37 << V_35 ) ;
return F_5 ( V_2 -> V_6 ,
V_11 ,
V_2 -> V_12 = V_38 ) ;
}
}
}
return - V_28 ;
}
static bool F_11 ( struct V_39 * V_6 )
{
int V_40 , V_41 ;
V_40 = F_2 ( V_6 , V_42 ) ;
if ( V_40 < 0 )
return false ;
V_41 = F_2 ( V_6 , V_43 ) ;
if ( V_41 < 0 )
return false ;
return ( V_40 == V_44 && V_41 == V_45 ) ;
}
static int F_12 ( struct V_39 * V_6 ,
const struct V_46 * V_47 )
{
struct V_1 * V_2 ;
struct V_14 * V_15 ;
int V_4 ;
T_3 V_48 ;
if ( ! F_13 ( V_6 -> V_49 , V_50 ) )
return - V_51 ;
if ( ! F_11 ( V_6 ) ) {
F_14 ( & V_6 -> V_52 , L_1 ) ;
return - V_53 ;
}
V_15 = F_15 ( & V_6 -> V_52 , sizeof( * V_2 ) ) ;
if ( ! V_15 )
return - V_54 ;
V_2 = F_7 ( V_15 ) ;
F_16 ( V_6 , V_15 ) ;
V_2 -> V_6 = V_6 ;
V_15 -> V_52 . V_55 = & V_6 -> V_52 ;
V_15 -> V_56 = L_2 ;
V_15 -> V_57 = V_58 ;
V_15 -> V_59 = & V_60 ;
V_15 -> V_61 = V_62 ;
V_15 -> V_63 = F_10 ( V_62 ) ;
V_4 = F_2 ( V_2 -> V_6 , V_11 ) ;
if ( V_4 < 0 )
return V_4 ;
V_2 -> V_12 = V_4 ;
V_2 -> V_12 |= ( V_13 | V_64 | V_65 ) ;
V_4 = F_5 ( V_2 -> V_6 , V_11 ,
V_2 -> V_12 ) ;
if ( V_4 < 0 )
return V_4 ;
V_4 = F_2 ( V_2 -> V_6 , V_66 ) ;
if ( V_4 < 0 )
goto V_67;
V_48 = V_4 ;
V_48 |= ( V_8 | V_9 ) ;
V_4 = F_5 ( V_2 -> V_6 , V_66 , V_48 ) ;
if ( V_4 < 0 )
goto V_67;
return F_17 ( V_15 ) ;
V_67:
F_4 ( V_2 ) ;
return V_4 ;
}
static int F_18 ( struct V_39 * V_6 )
{
struct V_14 * V_15 = F_19 ( V_6 ) ;
struct V_1 * V_2 = F_7 ( V_15 ) ;
F_20 ( V_15 ) ;
F_4 ( V_2 ) ;
return 0 ;
}
static int F_21 ( struct V_68 * V_52 )
{
struct V_1 * V_2 = F_7 ( F_19 (
F_22 ( V_52 ) ) ) ;
return F_4 ( V_2 ) ;
}
static int F_23 ( struct V_68 * V_52 )
{
struct V_1 * V_2 = F_7 ( F_19 (
F_22 ( V_52 ) ) ) ;
return F_5 ( V_2 -> V_6 , V_11 ,
V_2 -> V_12 | V_13 ) ;
}
