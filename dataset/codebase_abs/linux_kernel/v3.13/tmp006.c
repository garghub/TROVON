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
int V_17 ;
switch ( V_16 ) {
case V_18 :
if ( V_13 -> type == V_19 ) {
V_4 = F_1 ( V_2 , V_20 ) ;
if ( V_4 < 0 )
return V_4 ;
* V_14 = F_6 ( V_4 , 15 ) ;
} else if ( V_13 -> type == V_21 ) {
V_4 = F_1 ( V_2 , V_22 ) ;
if ( V_4 < 0 )
return V_4 ;
* V_14 = F_6 ( V_4 , 15 ) >> V_23 ;
} else {
break;
}
return V_24 ;
case V_25 :
if ( V_13 -> type == V_19 ) {
* V_14 = 0 ;
* V_15 = 156250 ;
} else if ( V_13 -> type == V_21 ) {
* V_14 = 31 ;
* V_15 = 250000 ;
} else {
break;
}
return V_26 ;
case V_27 :
V_17 = ( V_2 -> V_28 & V_29 )
>> V_30 ;
* V_14 = V_31 [ V_17 ] [ 0 ] ;
* V_15 = V_31 [ V_17 ] [ 1 ] ;
return V_26 ;
default:
break;
}
return - V_32 ;
}
static int F_7 ( struct V_10 * V_11 ,
struct V_12 const * V_33 ,
int V_14 ,
int V_15 ,
long V_16 )
{
struct V_1 * V_2 = F_5 ( V_11 ) ;
int V_34 ;
for ( V_34 = 0 ; V_34 < F_8 ( V_31 ) ; V_34 ++ )
if ( ( V_14 == V_31 [ V_34 ] [ 0 ] ) &&
( V_15 == V_31 [ V_34 ] [ 1 ] ) ) {
V_2 -> V_28 &= ~ V_29 ;
V_2 -> V_28 |= V_34 << V_30 ;
return F_9 ( V_2 -> V_6 ,
V_7 ,
V_2 -> V_28 ) ;
}
return - V_32 ;
}
static bool F_10 ( struct V_35 * V_6 )
{
int V_36 , V_37 ;
V_36 = F_2 ( V_6 , V_38 ) ;
if ( V_36 < 0 )
return false ;
V_37 = F_2 ( V_6 , V_39 ) ;
if ( V_37 < 0 )
return false ;
return V_36 == V_40 && V_37 == V_41 ;
}
static int F_11 ( struct V_35 * V_6 ,
const struct V_42 * V_43 )
{
struct V_10 * V_11 ;
struct V_1 * V_2 ;
int V_4 ;
if ( ! F_12 ( V_6 -> V_44 , V_45 ) )
return - V_46 ;
if ( ! F_10 ( V_6 ) ) {
F_13 ( & V_6 -> V_47 , L_1 ) ;
return - V_46 ;
}
V_11 = F_14 ( & V_6 -> V_47 , sizeof( * V_2 ) ) ;
if ( ! V_11 )
return - V_48 ;
V_2 = F_5 ( V_11 ) ;
F_15 ( V_6 , V_11 ) ;
V_2 -> V_6 = V_6 ;
V_11 -> V_47 . V_49 = & V_6 -> V_47 ;
V_11 -> V_50 = F_16 ( & V_6 -> V_47 ) ;
V_11 -> V_51 = V_52 ;
V_11 -> V_53 = & V_54 ;
V_11 -> V_55 = V_56 ;
V_11 -> V_57 = F_8 ( V_56 ) ;
V_4 = F_2 ( V_2 -> V_6 , V_7 ) ;
if ( V_4 < 0 )
return V_4 ;
V_2 -> V_28 = V_4 ;
return F_17 ( V_11 ) ;
}
static int F_18 ( struct V_1 * V_2 )
{
return F_9 ( V_2 -> V_6 , V_7 ,
V_2 -> V_28 & ~ V_58 ) ;
}
static int F_19 ( struct V_35 * V_6 )
{
struct V_10 * V_11 = F_20 ( V_6 ) ;
F_21 ( V_11 ) ;
F_18 ( F_5 ( V_11 ) ) ;
return 0 ;
}
static int F_22 ( struct V_59 * V_47 )
{
struct V_10 * V_11 = F_20 ( F_23 ( V_47 ) ) ;
return F_18 ( F_5 ( V_11 ) ) ;
}
static int F_24 ( struct V_59 * V_47 )
{
struct V_1 * V_2 = F_5 ( F_20 (
F_23 ( V_47 ) ) ) ;
return F_9 ( V_2 -> V_6 , V_7 ,
V_2 -> V_28 | V_58 ) ;
}
