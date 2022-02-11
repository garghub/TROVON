static inline int F_1 ( T_1 V_1 )
{
return ( V_1 & ~ 0x0f ) * 1000 / 256 ;
}
static inline T_2 F_2 ( int V_1 )
{
return ( V_1 * 256 ) / 1000 ;
}
static int F_3 ( struct V_2 * V_3 , enum V_4 type ,
T_3 V_5 , int V_6 , long * V_7 )
{
struct V_8 * V_8 = F_4 ( V_3 ) ;
unsigned int V_9 ;
int V_10 , V_11 ;
if ( type == V_12 ) {
if ( V_5 == V_13 ) {
V_10 = F_5 ( V_8 -> V_14 , V_15 ,
& V_9 ) ;
if ( V_10 < 0 )
return V_10 ;
switch ( V_9 & V_16 ) {
case V_17 :
default:
* V_7 = 4000 ;
break;
case V_18 :
* V_7 = 1000 ;
break;
case V_19 :
* V_7 = 250 ;
break;
case V_20 :
* V_7 = 63 ;
break;
}
return 0 ;
}
return - V_21 ;
}
switch ( V_5 ) {
case V_22 :
if ( F_6 ( V_23 , V_8 -> V_24 ) ) {
F_7 ( V_3 , L_1 ,
V_25 ) ;
return - V_26 ;
}
V_10 = F_5 ( V_8 -> V_14 , V_27 , & V_9 ) ;
if ( V_10 < 0 )
return V_10 ;
* V_7 = F_1 ( V_9 ) ;
break;
case V_28 :
case V_29 :
V_10 = F_5 ( V_8 -> V_14 , V_5 == V_28 ?
V_30 : V_31 , & V_9 ) ;
if ( V_10 < 0 )
return V_10 ;
* V_7 = F_1 ( V_9 ) ;
break;
case V_32 :
case V_33 :
V_10 = F_5 ( V_8 -> V_14 , V_15 , & V_9 ) ;
if ( V_10 < 0 )
return V_10 ;
* V_7 = ! ! ( V_9 & ( V_5 == V_32 ?
V_34 : V_35 ) ) ;
break;
case V_36 :
case V_37 :
V_10 = F_5 ( V_8 -> V_14 , V_15 , & V_9 ) ;
if ( V_10 < 0 )
return V_10 ;
switch ( V_9 & V_38 ) {
case V_39 :
default:
V_11 = 0 ;
break;
case V_40 :
V_11 = 1000 ;
break;
case V_41 :
V_11 = 2000 ;
break;
case V_42 :
V_11 = 4000 ;
break;
}
V_10 = F_5 ( V_8 -> V_14 , V_5 == V_36 ?
V_30 : V_31 , & V_9 ) ;
if ( V_10 < 0 )
return V_10 ;
* V_7 = F_1 ( V_9 ) ;
if ( V_5 == V_36 )
* V_7 += V_11 ;
else
* V_7 -= V_11 ;
break;
default:
return - V_21 ;
}
return 0 ;
}
static int F_8 ( struct V_2 * V_3 , enum V_4 type ,
T_3 V_5 , int V_6 , long V_7 )
{
struct V_8 * V_8 = F_4 ( V_3 ) ;
T_3 V_9 , V_43 ;
int V_10 ;
if ( type == V_12 ) {
if ( V_5 == V_13 ) {
if ( V_7 < 156 )
V_43 = V_20 ;
else if ( V_7 < 625 )
V_43 = V_19 ;
else if ( V_7 < 2500 )
V_43 = V_18 ;
else
V_43 = V_17 ;
return F_9 ( V_8 -> V_14 ,
V_15 ,
V_16 ,
V_43 ) ;
}
return - V_21 ;
}
switch ( V_5 ) {
case V_28 :
case V_29 :
V_7 = F_10 ( V_7 , V_44 , V_45 ) ;
return F_11 ( V_8 -> V_14 ,
V_5 == V_28 ?
V_30 : V_31 ,
F_2 ( V_7 ) ) ;
case V_36 :
case V_37 :
V_7 = F_10 ( V_7 , V_44 , V_45 ) ;
V_10 = F_5 ( V_8 -> V_14 ,
V_5 == V_36 ?
V_30 : V_31 ,
& V_9 ) ;
if ( V_10 < 0 )
return V_10 ;
if ( V_5 == V_36 )
V_7 -= F_1 ( V_9 ) ;
else
V_7 = F_1 ( V_9 ) - V_7 ;
if ( V_7 < 500 )
V_43 = V_39 ;
else if ( V_7 < 1500 )
V_43 = V_40 ;
else if ( V_7 < 3000 )
V_43 = V_41 ;
else
V_43 = V_42 ;
return F_9 ( V_8 -> V_14 , V_15 ,
V_38 , V_43 ) ;
default:
return - V_21 ;
}
}
static T_4 F_12 ( const void * V_46 , enum V_4 type ,
T_3 V_5 , int V_6 )
{
if ( type == V_12 && V_5 == V_13 )
return 0644 ;
if ( type != V_47 )
return 0 ;
switch ( V_5 ) {
case V_22 :
case V_32 :
case V_33 :
return 0444 ;
case V_28 :
case V_29 :
case V_36 :
case V_37 :
return 0644 ;
default:
return 0 ;
}
}
static void F_13 ( void * V_46 )
{
struct V_8 * V_8 = V_46 ;
F_11 ( V_8 -> V_14 , V_15 , V_8 -> V_48 ) ;
}
static bool F_14 ( struct V_2 * V_3 , unsigned int V_49 )
{
return V_49 != V_27 ;
}
static bool F_15 ( struct V_2 * V_3 , unsigned int V_49 )
{
return V_49 == V_27 || V_49 == V_15 ;
}
static int F_16 ( struct V_50 * V_51 ,
const struct V_52 * V_53 )
{
struct V_2 * V_3 = & V_51 -> V_3 ;
struct V_2 * V_54 ;
struct V_8 * V_8 ;
int V_10 ;
T_3 V_55 ;
if ( ! F_17 ( V_51 -> V_56 ,
V_57 ) ) {
F_18 ( V_3 ,
L_2 ) ;
return - V_58 ;
}
V_8 = F_19 ( V_3 , sizeof( * V_8 ) , V_59 ) ;
if ( ! V_8 )
return - V_60 ;
F_20 ( V_3 , V_8 ) ;
V_8 -> V_14 = F_21 ( V_51 , & V_61 ) ;
if ( F_22 ( V_8 -> V_14 ) ) {
V_10 = F_23 ( V_8 -> V_14 ) ;
F_18 ( V_3 , L_3 , V_10 ) ;
return V_10 ;
}
V_10 = F_5 ( V_8 -> V_14 , V_15 , & V_55 ) ;
if ( V_10 < 0 ) {
F_18 ( V_3 , L_4 , V_10 ) ;
return V_10 ;
}
V_8 -> V_48 = V_55 ;
V_55 &= ~ V_62 ;
V_55 |= V_63 ;
V_55 &= ~ V_64 ;
V_10 = F_11 ( V_8 -> V_14 , V_15 , V_55 ) ;
if ( V_10 < 0 ) {
F_18 ( V_3 , L_5 , V_10 ) ;
return V_10 ;
}
V_8 -> V_24 = V_23 ;
if ( ( V_8 -> V_48 & V_62 ) ==
V_65 )
V_8 -> V_24 +=
F_24 ( V_66 ) ;
V_10 = F_25 ( V_3 , F_13 , V_8 ) ;
if ( V_10 ) {
F_18 ( V_3 , L_6 , V_10 ) ;
return V_10 ;
}
V_54 = F_26 ( V_3 , V_51 -> V_67 ,
V_8 ,
& V_68 ,
NULL ) ;
return F_27 ( V_54 ) ;
}
static int T_5 F_28 ( struct V_2 * V_3 )
{
struct V_8 * V_8 = F_4 ( V_3 ) ;
return F_9 ( V_8 -> V_14 , V_15 ,
V_62 , V_65 ) ;
}
static int T_5 F_29 ( struct V_2 * V_3 )
{
struct V_8 * V_8 = F_4 ( V_3 ) ;
int V_10 ;
V_10 = F_9 ( V_8 -> V_14 , V_15 ,
V_62 , V_63 ) ;
V_8 -> V_24 = V_23 +
F_24 ( V_66 ) ;
return V_10 ;
}
