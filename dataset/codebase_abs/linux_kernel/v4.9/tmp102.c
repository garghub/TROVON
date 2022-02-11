static inline int F_1 ( T_1 V_1 )
{
return ( ( V_1 & ~ 0x01 ) * 1000 ) / 128 ;
}
static inline T_2 F_2 ( int V_1 )
{
return ( V_1 * 128 ) / 1000 ;
}
static int F_3 ( struct V_2 * V_3 , enum V_4 type ,
T_3 V_5 , int V_6 , long * V_7 )
{
struct V_8 * V_8 = F_4 ( V_3 ) ;
unsigned int V_9 ;
int V_10 , V_11 ;
switch ( V_5 ) {
case V_12 :
if ( F_5 ( V_13 , V_8 -> V_14 ) ) {
F_6 ( V_3 , L_1 , V_15 ) ;
return - V_16 ;
}
V_11 = V_17 ;
break;
case V_18 :
V_11 = V_19 ;
break;
case V_20 :
V_11 = V_21 ;
break;
default:
return - V_22 ;
}
V_10 = F_7 ( V_8 -> V_23 , V_11 , & V_9 ) ;
if ( V_10 < 0 )
return V_10 ;
* V_7 = F_1 ( V_9 ) ;
return 0 ;
}
static int F_8 ( struct V_2 * V_3 , enum V_4 type ,
T_3 V_5 , int V_6 , long V_7 )
{
struct V_8 * V_8 = F_4 ( V_3 ) ;
int V_11 ;
switch ( V_5 ) {
case V_18 :
V_11 = V_19 ;
break;
case V_20 :
V_11 = V_21 ;
break;
default:
return - V_22 ;
}
V_7 = F_9 ( V_7 , - 256000 , 255000 ) ;
return F_10 ( V_8 -> V_23 , V_11 , F_2 ( V_7 ) ) ;
}
static T_4 F_11 ( const void * V_24 , enum V_4 type ,
T_3 V_5 , int V_6 )
{
if ( type != V_25 )
return 0 ;
switch ( V_5 ) {
case V_12 :
return V_26 ;
case V_18 :
case V_20 :
return V_26 | V_27 ;
default:
return 0 ;
}
}
static void F_12 ( void * V_24 )
{
struct V_8 * V_8 = V_24 ;
F_10 ( V_8 -> V_23 , V_28 , V_8 -> V_29 ) ;
}
static bool F_13 ( struct V_2 * V_3 , unsigned int V_11 )
{
return V_11 != V_17 ;
}
static bool F_14 ( struct V_2 * V_3 , unsigned int V_11 )
{
return V_11 == V_17 ;
}
static int F_15 ( struct V_30 * V_31 ,
const struct V_32 * V_33 )
{
struct V_2 * V_3 = & V_31 -> V_3 ;
struct V_2 * V_34 ;
struct V_8 * V_8 ;
unsigned int V_9 ;
int V_10 ;
if ( ! F_16 ( V_31 -> V_35 ,
V_36 ) ) {
F_17 ( V_3 ,
L_2 ) ;
return - V_37 ;
}
V_8 = F_18 ( V_3 , sizeof( * V_8 ) , V_38 ) ;
if ( ! V_8 )
return - V_39 ;
F_19 ( V_31 , V_8 ) ;
V_8 -> V_23 = F_20 ( V_31 , & V_40 ) ;
if ( F_21 ( V_8 -> V_23 ) )
return F_22 ( V_8 -> V_23 ) ;
V_10 = F_7 ( V_8 -> V_23 , V_28 , & V_9 ) ;
if ( V_10 < 0 ) {
F_17 ( V_3 , L_3 ) ;
return V_10 ;
}
if ( ( V_9 & ~ V_41 ) !=
( V_42 | V_43 ) ) {
F_17 ( V_3 , L_4 ) ;
return - V_37 ;
}
V_8 -> V_29 = V_9 ;
V_10 = F_23 ( V_3 , F_12 , V_8 ) ;
if ( V_10 )
return V_10 ;
V_9 &= ~ V_44 ;
V_9 |= V_45 ;
V_10 = F_10 ( V_8 -> V_23 , V_28 , V_9 ) ;
if ( V_10 < 0 ) {
F_17 ( V_3 , L_5 ) ;
return V_10 ;
}
V_8 -> V_14 = V_13 ;
if ( V_8 -> V_29 & V_46 ) {
V_8 -> V_14 += F_24 ( V_47 ) ;
}
V_34 = F_25 ( V_3 , V_31 -> V_48 ,
V_8 ,
& V_49 ,
NULL ) ;
if ( F_21 ( V_34 ) ) {
F_6 ( V_3 , L_6 ) ;
return F_22 ( V_34 ) ;
}
F_26 ( V_3 , L_7 ) ;
return 0 ;
}
static int F_27 ( struct V_2 * V_3 )
{
struct V_30 * V_31 = F_28 ( V_3 ) ;
struct V_8 * V_8 = F_29 ( V_31 ) ;
return F_30 ( V_8 -> V_23 , V_28 ,
V_46 , V_46 ) ;
}
static int F_31 ( struct V_2 * V_3 )
{
struct V_30 * V_31 = F_28 ( V_3 ) ;
struct V_8 * V_8 = F_29 ( V_31 ) ;
int V_10 ;
V_10 = F_30 ( V_8 -> V_23 , V_28 ,
V_46 , 0 ) ;
V_8 -> V_14 = V_13 + F_24 ( V_47 ) ;
return V_10 ;
}
