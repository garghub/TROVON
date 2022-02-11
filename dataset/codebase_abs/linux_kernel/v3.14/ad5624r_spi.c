static int F_1 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_4 , T_2 V_5 , T_1 V_6 )
{
T_3 V_7 ;
T_1 V_8 [ 3 ] ;
V_7 = ( 0 << 22 ) | ( V_3 << 19 ) | ( V_4 << 16 ) | ( V_5 << ( 16 - V_6 ) ) ;
V_8 [ 0 ] = V_7 >> 16 ;
V_8 [ 1 ] = V_7 >> 8 ;
V_8 [ 2 ] = V_7 ;
return F_2 ( V_2 , V_8 , 3 ) ;
}
static int F_3 ( struct V_9 * V_10 ,
struct V_11 const * V_12 ,
int * V_5 ,
int * V_13 ,
long V_14 )
{
struct V_15 * V_16 = F_4 ( V_10 ) ;
switch ( V_14 ) {
case V_17 :
* V_5 = V_16 -> V_18 ;
* V_13 = V_12 -> V_19 . V_20 ;
return V_21 ;
}
return - V_22 ;
}
static int F_5 ( struct V_9 * V_10 ,
struct V_11 const * V_12 ,
int V_5 ,
int V_13 ,
long V_23 )
{
struct V_15 * V_16 = F_4 ( V_10 ) ;
int V_24 ;
switch ( V_23 ) {
case V_25 :
if ( V_5 >= ( 1 << V_12 -> V_19 . V_20 ) || V_5 < 0 )
return - V_22 ;
return F_1 ( V_16 -> V_26 ,
V_27 ,
V_12 -> V_28 , V_5 ,
V_12 -> V_19 . V_29 ) ;
default:
V_24 = - V_22 ;
}
return - V_22 ;
}
static int F_6 ( struct V_9 * V_10 ,
const struct V_11 * V_12 )
{
struct V_15 * V_16 = F_4 ( V_10 ) ;
return V_16 -> V_30 ;
}
static int F_7 ( struct V_9 * V_10 ,
const struct V_11 * V_12 , unsigned int V_31 )
{
struct V_15 * V_16 = F_4 ( V_10 ) ;
V_16 -> V_30 = V_31 ;
return 0 ;
}
static T_4 F_8 ( struct V_9 * V_10 ,
T_5 V_32 , const struct V_11 * V_12 , char * V_33 )
{
struct V_15 * V_16 = F_4 ( V_10 ) ;
return sprintf ( V_33 , L_1 ,
! ! ( V_16 -> V_34 & ( 1 << V_12 -> V_35 ) ) ) ;
}
static T_4 F_9 ( struct V_9 * V_10 ,
T_5 V_32 , const struct V_11 * V_12 , const char * V_33 ,
T_6 V_6 )
{
bool V_36 ;
int V_24 ;
struct V_15 * V_16 = F_4 ( V_10 ) ;
V_24 = F_10 ( V_33 , & V_36 ) ;
if ( V_24 )
return V_24 ;
if ( V_36 )
V_16 -> V_34 |= ( 1 << V_12 -> V_35 ) ;
else
V_16 -> V_34 &= ~ ( 1 << V_12 -> V_35 ) ;
V_24 = F_1 ( V_16 -> V_26 , V_37 , 0 ,
( V_16 -> V_30 << 4 ) |
V_16 -> V_34 , 16 ) ;
return V_24 ? V_24 : V_6 ;
}
static int F_11 ( struct V_1 * V_2 )
{
struct V_15 * V_16 ;
struct V_9 * V_10 ;
int V_24 , V_38 = 0 ;
V_10 = F_12 ( & V_2 -> V_39 , sizeof( * V_16 ) ) ;
if ( ! V_10 )
return - V_40 ;
V_16 = F_4 ( V_10 ) ;
V_16 -> V_41 = F_13 ( & V_2 -> V_39 , L_2 ) ;
if ( ! F_14 ( V_16 -> V_41 ) ) {
V_24 = F_15 ( V_16 -> V_41 ) ;
if ( V_24 )
return V_24 ;
V_24 = F_16 ( V_16 -> V_41 ) ;
if ( V_24 < 0 )
goto V_42;
V_38 = V_24 ;
}
F_17 ( V_2 , V_10 ) ;
V_16 -> V_43 =
& V_44 [ F_18 ( V_2 ) -> V_45 ] ;
if ( V_38 )
V_16 -> V_18 = V_38 / 1000 ;
else
V_16 -> V_18 = V_16 -> V_43 -> V_46 ;
V_16 -> V_26 = V_2 ;
V_10 -> V_39 . V_47 = & V_2 -> V_39 ;
V_10 -> V_48 = F_18 ( V_2 ) -> V_48 ;
V_10 -> V_49 = & V_50 ;
V_10 -> V_51 = V_52 ;
V_10 -> V_53 = V_16 -> V_43 -> V_53 ;
V_10 -> V_54 = V_55 ;
V_24 = F_1 ( V_2 , V_56 , 0 ,
! ! V_38 , 16 ) ;
if ( V_24 )
goto V_42;
V_24 = F_19 ( V_10 ) ;
if ( V_24 )
goto V_42;
return 0 ;
V_42:
if ( ! F_14 ( V_16 -> V_41 ) )
F_20 ( V_16 -> V_41 ) ;
return V_24 ;
}
static int F_21 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_22 ( V_2 ) ;
struct V_15 * V_16 = F_4 ( V_10 ) ;
F_23 ( V_10 ) ;
if ( ! F_14 ( V_16 -> V_41 ) )
F_20 ( V_16 -> V_41 ) ;
return 0 ;
}
