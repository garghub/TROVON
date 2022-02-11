static int F_1 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_4 , T_2 V_5 , T_1 V_6 )
{
T_3 V_7 ;
T_1 V_8 [ 3 ] ;
V_7 = ( V_3 << 20 ) | ( V_4 << 16 ) | ( V_5 << V_6 ) ;
V_8 [ 0 ] = V_7 >> 16 ;
V_8 [ 1 ] = V_7 >> 8 ;
V_8 [ 2 ] = V_7 ;
return F_2 ( V_2 , V_8 , sizeof( V_8 ) ) ;
}
static int F_3 ( struct V_9 * V_10 ,
struct V_11 const * V_12 ,
int * V_5 ,
int * V_13 ,
long V_14 )
{
struct V_15 * V_16 ;
const struct V_17 * V_18 = F_4 ( V_10 ) ;
const struct V_19 * V_20 = F_5 ( V_18 -> V_21 ) ;
V_16 = (struct V_15 * ) V_20 -> V_22 ;
switch ( V_14 ) {
case V_23 :
* V_5 = V_16 -> V_24 ;
* V_13 = V_12 -> V_25 . V_26 ;
return V_27 ;
}
return - V_28 ;
}
static int F_6 ( struct V_9 * V_10 ,
struct V_11 const * V_12 ,
int V_5 ,
int V_13 ,
long V_29 )
{
struct V_17 * V_18 = F_4 ( V_10 ) ;
switch ( V_29 ) {
case V_30 :
if ( V_5 >= ( 1 << V_12 -> V_25 . V_26 ) || V_5 < 0 )
return - V_28 ;
return F_1 ( V_18 -> V_21 ,
V_31 ,
V_12 -> V_32 , V_5 ,
V_12 -> V_25 . V_6 ) ;
default:
return - V_28 ;
}
}
static T_4 F_7 ( struct V_9 * V_10 ,
T_5 V_33 ,
const struct V_11 * V_12 ,
char * V_34 )
{
struct V_17 * V_18 = F_4 ( V_10 ) ;
return sprintf ( V_34 , L_1 ,
! ! ( V_18 -> V_35 & ( 1 << V_12 -> V_36 ) ) ) ;
}
static T_4 F_8 ( struct V_9 * V_10 ,
T_5 V_33 ,
const struct V_11 * V_12 ,
const char * V_34 ,
T_6 V_37 )
{
bool V_38 ;
int V_39 ;
struct V_17 * V_18 = F_4 ( V_10 ) ;
V_39 = F_9 ( V_34 , & V_38 ) ;
if ( V_39 )
return V_39 ;
if ( V_38 )
V_18 -> V_35 |= ( 1 << V_12 -> V_36 ) ;
else
V_18 -> V_35 &= ~ ( 1 << V_12 -> V_36 ) ;
V_39 = F_1 ( V_18 -> V_21 ,
V_40 ,
V_12 -> V_36 , 0 , 0 ) ;
return V_39 ? V_39 : V_37 ;
}
static int F_10 ( struct V_1 * V_2 )
{
struct V_17 * V_18 ;
struct V_9 * V_10 ;
struct V_15 * V_16 ;
int V_39 ;
V_10 = F_11 ( & V_2 -> V_41 , sizeof( * V_18 ) ) ;
if ( ! V_10 )
return - V_42 ;
V_18 = F_4 ( V_10 ) ;
F_12 ( V_2 , V_10 ) ;
V_18 -> V_21 = V_2 ;
V_16 = (struct V_15 * )
F_5 ( V_2 ) -> V_22 ;
V_10 -> V_41 . V_43 = & V_2 -> V_41 ;
V_10 -> V_44 = F_13 ( & V_2 -> V_41 ) ? F_13 ( & V_2 -> V_41 ) -> V_44
: F_5 ( V_2 ) -> V_44 ;
V_10 -> V_45 = & V_46 ;
V_10 -> V_47 = V_48 ;
V_10 -> V_49 = V_16 -> V_49 ;
V_10 -> V_50 = V_51 ;
V_39 = F_1 ( V_2 , V_52 , 0 , 0 , 0 ) ;
if ( V_39 ) {
F_14 ( & V_2 -> V_41 ,
L_2 , V_39 ) ;
return V_39 ;
}
return F_15 ( & V_2 -> V_41 , V_10 ) ;
}
