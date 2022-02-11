static int F_1 ( struct V_1 * V_2 ,
enum V_3 V_4 )
{
int V_5 ;
struct V_6 * V_7 = V_2 -> V_7 ;
if ( V_4 == V_2 -> V_4 )
return 0 ;
V_5 = F_2 ( V_7 , V_8 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_7 -> V_9 , L_1 ) ;
return V_5 ;
}
if ( V_4 == V_10 ) {
V_5 &= ~ V_11 ;
V_5 |= V_12 ;
} else {
V_5 &= ~ V_11 ;
V_5 &= ~ V_12 ;
}
V_5 = F_4 ( V_7 , V_8 , V_5 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_7 -> V_9 , L_2 ) ;
return V_5 ;
}
V_2 -> V_4 = V_4 ;
return V_5 ;
}
static int F_5 ( struct V_1 * V_2 , T_1 V_13 )
{
int V_5 , V_14 = V_15 ;
struct V_6 * V_7 = V_2 -> V_7 ;
do {
V_5 = F_2 ( V_7 , V_13 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_7 -> V_9 , L_3 ) ;
return V_5 ;
}
} while ( V_14 -- > 0 && V_5 & V_16 );
if ( V_5 & V_16 ) {
F_3 ( & V_7 -> V_9 , L_4 ) ;
return - V_17 ;
}
return V_5 ;
}
static int F_6 ( struct V_18 * V_19 ,
struct V_20 const * V_21 ,
int * V_22 , int * V_23 , long V_24 )
{
struct V_1 * V_2 = F_7 ( V_19 ) ;
int V_5 ;
switch ( V_24 ) {
case V_25 :
F_8 ( & V_2 -> V_26 ) ;
V_5 = F_5 ( V_2 , V_21 -> V_13 ) ;
F_9 ( & V_2 -> V_26 ) ;
if ( V_5 < 0 )
return V_5 ;
* V_22 = F_10 ( V_5 , 5 ) ;
return V_27 ;
case V_28 :
* V_22 = 0 ;
* V_23 = V_29 ;
return V_30 ;
default:
return - V_31 ;
}
return - V_31 ;
}
static int F_11 ( struct V_6 * V_7 ,
const struct V_32 * V_33 )
{
int V_5 ;
struct V_18 * V_19 ;
struct V_1 * V_2 ;
V_19 = F_12 ( & V_7 -> V_9 , sizeof( * V_2 ) ) ;
if ( ! V_19 ) {
F_3 ( & V_7 -> V_9 , L_5 ) ;
return - V_34 ;
}
V_2 = F_7 ( V_19 ) ;
V_2 -> V_7 = V_7 ;
F_13 ( V_7 , V_19 ) ;
F_14 ( & V_2 -> V_26 ) ;
V_2 -> V_4 = V_35 ;
V_19 -> V_9 . V_36 = & V_7 -> V_9 ;
V_19 -> V_37 = & V_38 ;
V_19 -> V_39 = V_40 ;
V_19 -> V_41 = V_42 ;
V_19 -> V_43 = V_44 ;
V_19 -> V_45 = F_15 ( V_44 ) ;
V_5 = F_1 ( V_2 , V_10 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_16 ( V_19 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_7 -> V_9 , L_6 ) ;
F_1 ( V_2 , V_35 ) ;
}
return V_5 ;
}
static int F_17 ( struct V_6 * V_7 )
{
struct V_18 * V_19 = F_18 ( V_7 ) ;
F_19 ( V_19 ) ;
return F_1 ( F_7 ( V_19 ) , V_35 ) ;
}
static int F_20 ( struct V_46 * V_9 )
{
struct V_1 * V_2 ;
V_2 = F_7 ( F_18 ( F_21 ( V_9 ) ) ) ;
return F_1 ( V_2 , V_35 ) ;
}
static int F_22 ( struct V_46 * V_9 )
{
struct V_1 * V_2 ;
V_2 = F_7 ( F_18 ( F_21 ( V_9 ) ) ) ;
return F_1 ( V_2 , V_10 ) ;
}
