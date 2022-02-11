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
static T_3 F_11 ( struct V_22 * V_23 ,
struct V_24 * V_25 , char * V_26 )
{
struct V_27 * V_28 = F_12 ( V_23 ) ;
struct V_1 * V_2 = F_13 ( V_28 ) ;
struct V_29 * V_30 = F_14 ( V_25 ) ;
char V_31 [] [ 15 ] = { L_1 , L_2 , L_3 , L_4 } ;
return sprintf ( V_26 , L_5 , V_31 [ ( V_2 -> V_32 >>
( V_30 -> V_33 * 2 ) ) & 0x3 ] ) ;
}
static T_3 F_15 ( struct V_22 * V_23 ,
struct V_24 * V_25 ,
const char * V_26 , T_4 V_14 )
{
struct V_27 * V_28 = F_12 ( V_23 ) ;
struct V_1 * V_2 = F_13 ( V_28 ) ;
struct V_29 * V_30 = F_14 ( V_25 ) ;
unsigned V_31 ;
if ( F_16 ( V_26 , L_2 ) )
V_31 = V_34 ;
else if ( F_16 ( V_26 , L_3 ) )
V_31 = V_35 ;
else if ( F_16 ( V_26 , L_4 ) )
V_31 = V_36 ;
else
return - V_37 ;
V_2 -> V_32 &= ~ ( 0x3 << ( V_30 -> V_33 * 2 ) ) ;
V_2 -> V_32 |= ( V_31 << ( V_30 -> V_33 * 2 ) ) ;
return V_14 ;
}
static T_3 F_17 ( struct V_22 * V_23 ,
struct V_24 * V_25 ,
char * V_26 )
{
struct V_27 * V_28 = F_12 ( V_23 ) ;
struct V_1 * V_2 = F_13 ( V_28 ) ;
struct V_29 * V_30 = F_14 ( V_25 ) ;
return sprintf ( V_26 , L_6 , ! ! ( V_2 -> V_38 &
( 0x3 << ( V_30 -> V_33 * 2 ) ) ) ) ;
}
static T_3 F_18 ( struct V_22 * V_23 ,
struct V_24 * V_25 ,
const char * V_26 , T_4 V_14 )
{
bool V_39 ;
int V_19 ;
struct V_27 * V_28 = F_12 ( V_23 ) ;
struct V_1 * V_2 = F_13 ( V_28 ) ;
struct V_29 * V_30 = F_14 ( V_25 ) ;
V_19 = F_19 ( V_26 , & V_39 ) ;
if ( V_19 )
return V_19 ;
if ( V_39 == true )
V_2 -> V_38 |= ( 0x3 << ( V_30 -> V_33 * 2 ) ) ;
else
V_2 -> V_38 &= ~ ( 0x3 << ( V_30 -> V_33 * 2 ) ) ;
V_19 = F_1 ( V_2 , V_40 , 0 ,
V_2 -> V_38 & V_2 -> V_32 , 0 ) ;
return V_19 ? V_19 : V_14 ;
}
static int F_20 ( struct V_27 * V_28 ,
struct V_41 const * V_42 ,
int * V_5 ,
int * V_43 ,
long V_18 )
{
struct V_1 * V_2 = F_13 ( V_28 ) ;
unsigned long V_44 ;
int V_19 ;
switch ( V_18 ) {
case 0 :
F_21 ( & V_28 -> V_45 ) ;
V_19 = F_6 ( V_2 , V_42 -> V_33 ) ;
F_22 ( & V_28 -> V_45 ) ;
if ( V_19 < 0 )
return V_19 ;
* V_5 = V_19 ;
return V_46 ;
break;
case V_47 :
V_44 = ( V_2 -> V_48 * 100000 )
>> ( V_42 -> V_49 . V_50 ) ;
* V_5 = V_44 / 100000 ;
* V_43 = ( V_44 % 100000 ) * 10 ;
return V_51 ;
}
return - V_37 ;
}
static int F_23 ( struct V_27 * V_28 ,
struct V_41 const * V_42 ,
int V_5 ,
int V_43 ,
long V_52 )
{
struct V_1 * V_2 = F_13 ( V_28 ) ;
int V_19 ;
switch ( V_52 ) {
case 0 :
if ( V_5 > ( 1 << V_42 -> V_49 . V_50 ) || V_5 < 0 )
return - V_37 ;
F_21 ( & V_28 -> V_45 ) ;
V_19 = F_1 ( V_2 ,
V_53 ,
V_42 -> V_33 ,
V_5 ,
V_42 -> V_49 . V_6 ) ;
F_22 ( & V_28 -> V_45 ) ;
break;
default:
V_19 = - V_37 ;
}
return V_19 ;
}
static int T_5 F_24 ( struct V_54 * V_9 )
{
struct V_1 * V_2 ;
struct V_27 * V_28 ;
int V_19 , V_55 = 0 , V_56 = 0 ;
V_28 = F_25 ( sizeof( * V_2 ) ) ;
if ( V_28 == NULL )
return - V_57 ;
V_2 = F_13 ( V_28 ) ;
F_26 ( V_9 , V_28 ) ;
V_2 -> V_58 = F_27 ( & V_9 -> V_23 , L_7 ) ;
if ( ! F_28 ( V_2 -> V_58 ) ) {
V_19 = F_29 ( V_2 -> V_58 ) ;
if ( V_19 )
goto V_59;
V_56 = F_30 ( V_2 -> V_58 ) ;
}
V_2 -> V_60 =
& V_61 [ F_31 ( V_9 ) -> V_62 ] ;
if ( V_56 )
V_2 -> V_48 = V_56 / 1000 ;
else
V_2 -> V_48 = V_2 -> V_60 -> V_63 ;
V_2 -> V_9 = V_9 ;
V_28 -> V_23 . V_64 = & V_9 -> V_23 ;
V_28 -> V_65 = F_31 ( V_9 ) -> V_65 ;
V_28 -> V_66 = & V_67 ;
V_28 -> V_68 = V_69 ;
V_28 -> V_70 = V_2 -> V_60 -> V_71 ;
V_28 -> V_72 = V_73 ;
V_55 = 1 ;
V_19 = F_1 ( V_2 , V_74 , 0 ,
! ! V_56 , 0 ) ;
if ( V_19 )
goto V_75;
V_19 = F_32 ( V_28 ) ;
if ( V_19 )
goto V_75;
return 0 ;
V_75:
if ( ! F_28 ( V_2 -> V_58 ) )
F_33 ( V_2 -> V_58 ) ;
V_59:
if ( ! F_28 ( V_2 -> V_58 ) )
F_34 ( V_2 -> V_58 ) ;
F_35 ( V_28 ) ;
return V_19 ;
}
static int T_6 F_36 ( struct V_54 * V_9 )
{
struct V_27 * V_28 = F_37 ( V_9 ) ;
struct V_1 * V_2 = F_13 ( V_28 ) ;
F_38 ( V_28 ) ;
if ( ! F_28 ( V_2 -> V_58 ) ) {
F_33 ( V_2 -> V_58 ) ;
F_34 ( V_2 -> V_58 ) ;
}
F_35 ( V_28 ) ;
return 0 ;
}
