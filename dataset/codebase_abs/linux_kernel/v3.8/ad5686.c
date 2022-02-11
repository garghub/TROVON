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
struct V_17 V_18 ;
int V_19 ;
F_7 ( & V_18 ) ;
F_8 ( & V_12 [ 0 ] , & V_18 ) ;
F_8 ( & V_12 [ 1 ] , & V_18 ) ;
V_2 -> V_7 [ 0 ] . V_8 = F_2 ( F_3 ( V_20 ) |
F_4 ( V_4 ) ) ;
V_2 -> V_7 [ 1 ] . V_8 = F_2 ( F_3 ( V_21 ) ) ;
V_19 = F_9 ( V_2 -> V_9 , & V_18 ) ;
if ( V_19 < 0 )
return V_19 ;
return F_10 ( V_2 -> V_7 [ 2 ] . V_8 ) ;
}
static int F_11 ( struct V_22 * V_23 ,
const struct V_24 * V_25 )
{
struct V_1 * V_2 = F_12 ( V_23 ) ;
return ( ( V_2 -> V_26 >> ( V_25 -> V_27 * 2 ) ) & 0x3 ) - 1 ;
}
static int F_13 ( struct V_22 * V_23 ,
const struct V_24 * V_25 , unsigned int V_28 )
{
struct V_1 * V_2 = F_12 ( V_23 ) ;
V_2 -> V_26 &= ~ ( 0x3 << ( V_25 -> V_27 * 2 ) ) ;
V_2 -> V_26 |= ( ( V_28 + 1 ) << ( V_25 -> V_27 * 2 ) ) ;
return 0 ;
}
static T_3 F_14 ( struct V_22 * V_23 ,
T_4 V_29 , const struct V_24 * V_25 , char * V_30 )
{
struct V_1 * V_2 = F_12 ( V_23 ) ;
return sprintf ( V_30 , L_1 , ! ! ( V_2 -> V_31 &
( 0x3 << ( V_25 -> V_27 * 2 ) ) ) ) ;
}
static T_3 F_15 ( struct V_22 * V_23 ,
T_4 V_29 , const struct V_24 * V_25 , const char * V_30 ,
T_5 V_14 )
{
bool V_32 ;
int V_19 ;
struct V_1 * V_2 = F_12 ( V_23 ) ;
V_19 = F_16 ( V_30 , & V_32 ) ;
if ( V_19 )
return V_19 ;
if ( V_32 )
V_2 -> V_31 |= ( 0x3 << ( V_25 -> V_27 * 2 ) ) ;
else
V_2 -> V_31 &= ~ ( 0x3 << ( V_25 -> V_27 * 2 ) ) ;
V_19 = F_1 ( V_2 , V_33 , 0 ,
V_2 -> V_31 & V_2 -> V_26 , 0 ) ;
return V_19 ? V_19 : V_14 ;
}
static int F_17 ( struct V_22 * V_23 ,
struct V_24 const * V_25 ,
int * V_5 ,
int * V_34 ,
long V_18 )
{
struct V_1 * V_2 = F_12 ( V_23 ) ;
unsigned long V_35 ;
int V_19 ;
switch ( V_18 ) {
case V_36 :
F_18 ( & V_23 -> V_37 ) ;
V_19 = F_6 ( V_2 , V_25 -> V_38 ) ;
F_19 ( & V_23 -> V_37 ) ;
if ( V_19 < 0 )
return V_19 ;
* V_5 = V_19 ;
return V_39 ;
break;
case V_40 :
V_35 = ( V_2 -> V_41 * 100000 )
>> ( V_25 -> V_42 . V_43 ) ;
* V_5 = V_35 / 100000 ;
* V_34 = ( V_35 % 100000 ) * 10 ;
return V_44 ;
}
return - V_45 ;
}
static int F_20 ( struct V_22 * V_23 ,
struct V_24 const * V_25 ,
int V_5 ,
int V_34 ,
long V_46 )
{
struct V_1 * V_2 = F_12 ( V_23 ) ;
int V_19 ;
switch ( V_46 ) {
case V_36 :
if ( V_5 > ( 1 << V_25 -> V_42 . V_43 ) || V_5 < 0 )
return - V_45 ;
F_18 ( & V_23 -> V_37 ) ;
V_19 = F_1 ( V_2 ,
V_47 ,
V_25 -> V_38 ,
V_5 ,
V_25 -> V_42 . V_6 ) ;
F_19 ( & V_23 -> V_37 ) ;
break;
default:
V_19 = - V_45 ;
}
return V_19 ;
}
static int F_21 ( struct V_48 * V_9 )
{
struct V_1 * V_2 ;
struct V_22 * V_23 ;
int V_19 , V_49 = 0 , V_50 = 0 ;
V_23 = F_22 ( sizeof( * V_2 ) ) ;
if ( V_23 == NULL )
return - V_51 ;
V_2 = F_12 ( V_23 ) ;
F_23 ( V_9 , V_23 ) ;
V_2 -> V_52 = F_24 ( & V_9 -> V_53 , L_2 ) ;
if ( ! F_25 ( V_2 -> V_52 ) ) {
V_19 = F_26 ( V_2 -> V_52 ) ;
if ( V_19 )
goto V_54;
V_19 = F_27 ( V_2 -> V_52 ) ;
if ( V_19 < 0 )
goto V_55;
V_50 = V_19 ;
}
V_2 -> V_56 =
& V_57 [ F_28 ( V_9 ) -> V_58 ] ;
if ( V_50 )
V_2 -> V_41 = V_50 / 1000 ;
else
V_2 -> V_41 = V_2 -> V_56 -> V_59 ;
V_2 -> V_9 = V_9 ;
V_2 -> V_26 = 0x55 ;
V_23 -> V_53 . V_60 = & V_9 -> V_53 ;
V_23 -> V_61 = F_28 ( V_9 ) -> V_61 ;
V_23 -> V_62 = & V_63 ;
V_23 -> V_64 = V_65 ;
V_23 -> V_66 = V_2 -> V_56 -> V_27 ;
V_23 -> V_67 = V_68 ;
V_49 = 1 ;
V_19 = F_1 ( V_2 , V_69 , 0 ,
! ! V_50 , 0 ) ;
if ( V_19 )
goto V_55;
V_19 = F_29 ( V_23 ) ;
if ( V_19 )
goto V_55;
return 0 ;
V_55:
if ( ! F_25 ( V_2 -> V_52 ) )
F_30 ( V_2 -> V_52 ) ;
V_54:
if ( ! F_25 ( V_2 -> V_52 ) )
F_31 ( V_2 -> V_52 ) ;
F_32 ( V_23 ) ;
return V_19 ;
}
static int F_33 ( struct V_48 * V_9 )
{
struct V_22 * V_23 = F_34 ( V_9 ) ;
struct V_1 * V_2 = F_12 ( V_23 ) ;
F_35 ( V_23 ) ;
if ( ! F_25 ( V_2 -> V_52 ) ) {
F_30 ( V_2 -> V_52 ) ;
F_31 ( V_2 -> V_52 ) ;
}
F_32 ( V_23 ) ;
return 0 ;
}
