static int F_1 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_4 , T_2 V_5 , T_1 V_6 )
{
V_5 <<= V_6 ;
V_2 -> V_7 [ 0 ] . V_8 = F_2 ( F_3 ( V_3 ) |
F_4 ( V_4 ) |
V_5 ) ;
return F_5 ( V_2 -> V_9 , & V_2 -> V_7 [ 0 ] . V_10 [ 1 ] , 3 ) ;
}
static int F_6 ( struct V_1 * V_2 , T_1 V_4 )
{
struct V_11 V_12 [] = {
{
. V_13 = & V_2 -> V_7 [ 0 ] . V_10 [ 1 ] ,
. V_14 = 3 ,
. V_15 = 1 ,
} , {
. V_13 = & V_2 -> V_7 [ 1 ] . V_10 [ 1 ] ,
. V_16 = & V_2 -> V_7 [ 2 ] . V_10 [ 1 ] ,
. V_14 = 3 ,
} ,
} ;
int V_17 ;
V_2 -> V_7 [ 0 ] . V_8 = F_2 ( F_3 ( V_18 ) |
F_4 ( V_4 ) ) ;
V_2 -> V_7 [ 1 ] . V_8 = F_2 ( F_3 ( V_19 ) ) ;
V_17 = F_7 ( V_2 -> V_9 , V_12 , F_8 ( V_12 ) ) ;
if ( V_17 < 0 )
return V_17 ;
return F_9 ( V_2 -> V_7 [ 2 ] . V_8 ) ;
}
static int F_10 ( struct V_20 * V_21 ,
const struct V_22 * V_23 )
{
struct V_1 * V_2 = F_11 ( V_21 ) ;
return ( ( V_2 -> V_24 >> ( V_23 -> V_25 * 2 ) ) & 0x3 ) - 1 ;
}
static int F_12 ( struct V_20 * V_21 ,
const struct V_22 * V_23 , unsigned int V_26 )
{
struct V_1 * V_2 = F_11 ( V_21 ) ;
V_2 -> V_24 &= ~ ( 0x3 << ( V_23 -> V_25 * 2 ) ) ;
V_2 -> V_24 |= ( ( V_26 + 1 ) << ( V_23 -> V_25 * 2 ) ) ;
return 0 ;
}
static T_3 F_13 ( struct V_20 * V_21 ,
T_4 V_27 , const struct V_22 * V_23 , char * V_28 )
{
struct V_1 * V_2 = F_11 ( V_21 ) ;
return sprintf ( V_28 , L_1 , ! ! ( V_2 -> V_29 &
( 0x3 << ( V_23 -> V_25 * 2 ) ) ) ) ;
}
static T_3 F_14 ( struct V_20 * V_21 ,
T_4 V_27 , const struct V_22 * V_23 , const char * V_28 ,
T_5 V_14 )
{
bool V_30 ;
int V_17 ;
struct V_1 * V_2 = F_11 ( V_21 ) ;
V_17 = F_15 ( V_28 , & V_30 ) ;
if ( V_17 )
return V_17 ;
if ( V_30 )
V_2 -> V_29 |= ( 0x3 << ( V_23 -> V_25 * 2 ) ) ;
else
V_2 -> V_29 &= ~ ( 0x3 << ( V_23 -> V_25 * 2 ) ) ;
V_17 = F_1 ( V_2 , V_31 , 0 ,
V_2 -> V_29 & V_2 -> V_24 , 0 ) ;
return V_17 ? V_17 : V_14 ;
}
static int F_16 ( struct V_20 * V_21 ,
struct V_22 const * V_23 ,
int * V_5 ,
int * V_32 ,
long V_33 )
{
struct V_1 * V_2 = F_11 ( V_21 ) ;
int V_17 ;
switch ( V_33 ) {
case V_34 :
F_17 ( & V_21 -> V_35 ) ;
V_17 = F_6 ( V_2 , V_23 -> V_36 ) ;
F_18 ( & V_21 -> V_35 ) ;
if ( V_17 < 0 )
return V_17 ;
* V_5 = V_17 ;
return V_37 ;
case V_38 :
* V_5 = V_2 -> V_39 ;
* V_32 = V_23 -> V_40 . V_41 ;
return V_42 ;
}
return - V_43 ;
}
static int F_19 ( struct V_20 * V_21 ,
struct V_22 const * V_23 ,
int V_5 ,
int V_32 ,
long V_44 )
{
struct V_1 * V_2 = F_11 ( V_21 ) ;
int V_17 ;
switch ( V_44 ) {
case V_34 :
if ( V_5 > ( 1 << V_23 -> V_40 . V_41 ) || V_5 < 0 )
return - V_43 ;
F_17 ( & V_21 -> V_35 ) ;
V_17 = F_1 ( V_2 ,
V_45 ,
V_23 -> V_36 ,
V_5 ,
V_23 -> V_40 . V_6 ) ;
F_18 ( & V_21 -> V_35 ) ;
break;
default:
V_17 = - V_43 ;
}
return V_17 ;
}
static int F_20 ( struct V_46 * V_9 )
{
struct V_1 * V_2 ;
struct V_20 * V_21 ;
int V_17 , V_47 = 0 , V_48 = 0 ;
V_21 = F_21 ( & V_9 -> V_49 , sizeof( * V_2 ) ) ;
if ( V_21 == NULL )
return - V_50 ;
V_2 = F_11 ( V_21 ) ;
F_22 ( V_9 , V_21 ) ;
V_2 -> V_51 = F_23 ( & V_9 -> V_49 , L_2 ) ;
if ( ! F_24 ( V_2 -> V_51 ) ) {
V_17 = F_25 ( V_2 -> V_51 ) ;
if ( V_17 )
return V_17 ;
V_17 = F_26 ( V_2 -> V_51 ) ;
if ( V_17 < 0 )
goto V_52;
V_48 = V_17 ;
}
V_2 -> V_53 =
& V_54 [ F_27 ( V_9 ) -> V_55 ] ;
if ( V_48 )
V_2 -> V_39 = V_48 / 1000 ;
else
V_2 -> V_39 = V_2 -> V_53 -> V_56 ;
V_2 -> V_9 = V_9 ;
V_2 -> V_24 = 0x55 ;
V_21 -> V_49 . V_57 = & V_9 -> V_49 ;
V_21 -> V_58 = F_27 ( V_9 ) -> V_58 ;
V_21 -> V_59 = & V_60 ;
V_21 -> V_61 = V_62 ;
V_21 -> V_63 = V_2 -> V_53 -> V_25 ;
V_21 -> V_64 = V_65 ;
V_47 = 1 ;
V_17 = F_1 ( V_2 , V_66 , 0 ,
! ! V_48 , 0 ) ;
if ( V_17 )
goto V_52;
V_17 = F_28 ( V_21 ) ;
if ( V_17 )
goto V_52;
return 0 ;
V_52:
if ( ! F_24 ( V_2 -> V_51 ) )
F_29 ( V_2 -> V_51 ) ;
return V_17 ;
}
static int F_30 ( struct V_46 * V_9 )
{
struct V_20 * V_21 = F_31 ( V_9 ) ;
struct V_1 * V_2 = F_11 ( V_21 ) ;
F_32 ( V_21 ) ;
if ( ! F_24 ( V_2 -> V_51 ) )
F_29 ( V_2 -> V_51 ) ;
return 0 ;
}
