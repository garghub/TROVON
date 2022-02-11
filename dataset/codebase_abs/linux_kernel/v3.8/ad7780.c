static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static int F_3 ( struct V_2 * V_4 ,
enum V_5 V_6 )
{
struct V_1 * V_7 = F_1 ( V_4 ) ;
unsigned V_8 ;
switch ( V_6 ) {
case V_9 :
case V_10 :
V_8 = 1 ;
break;
default:
V_8 = 0 ;
break;
}
if ( F_4 ( V_7 -> V_11 ) )
F_5 ( V_7 -> V_11 , V_8 ) ;
return 0 ;
}
static int F_6 ( struct V_12 * V_13 ,
struct V_14 const * V_15 ,
int * V_8 ,
int * V_16 ,
long V_17 )
{
struct V_1 * V_7 = F_7 ( V_13 ) ;
unsigned long V_18 ;
switch ( V_17 ) {
case V_19 :
return F_8 ( V_13 , V_15 , V_8 ) ;
case V_20 :
V_18 = ( V_7 -> V_21 * 100000 * V_7 -> V_22 )
>> ( V_15 -> V_23 . V_24 - 1 ) ;
* V_8 = V_18 / 100000 ;
* V_16 = ( V_18 % 100000 ) * 10 ;
return V_25 ;
case V_26 :
* V_8 -= ( 1 << ( V_15 -> V_23 . V_24 - 1 ) ) ;
return V_27 ;
}
return - V_28 ;
}
static int F_9 ( struct V_2 * V_4 ,
unsigned int V_29 )
{
struct V_1 * V_7 = F_1 ( V_4 ) ;
const struct V_30 * V_31 = V_7 -> V_31 ;
if ( ( V_29 & V_32 ) ||
( ( V_29 & V_31 -> V_33 ) != V_31 -> V_34 ) )
return - V_35 ;
if ( V_29 & V_36 )
V_7 -> V_22 = 1 ;
else
V_7 -> V_22 = 128 ;
return 0 ;
}
static int F_10 ( struct V_37 * V_38 )
{
struct V_39 * V_40 = V_38 -> V_41 . V_42 ;
struct V_1 * V_7 ;
struct V_12 * V_13 ;
int V_43 , V_44 = 0 ;
V_13 = F_11 ( sizeof( * V_7 ) ) ;
if ( V_13 == NULL )
return - V_45 ;
V_7 = F_7 ( V_13 ) ;
V_7 -> V_22 = 1 ;
F_12 ( & V_7 -> V_3 , V_13 , V_38 , & V_46 ) ;
V_7 -> V_47 = F_13 ( & V_38 -> V_41 , L_1 ) ;
if ( ! F_14 ( V_7 -> V_47 ) ) {
V_43 = F_15 ( V_7 -> V_47 ) ;
if ( V_43 )
goto V_48;
V_44 = F_16 ( V_7 -> V_47 ) ;
}
V_7 -> V_31 =
& V_49 [ F_17 ( V_38 ) -> V_50 ] ;
if ( V_40 && V_40 -> V_51 )
V_7 -> V_21 = V_40 -> V_51 ;
else if ( V_44 )
V_7 -> V_21 = V_44 / 1000 ;
else
F_18 ( & V_38 -> V_41 , L_2 ) ;
F_19 ( V_38 , V_13 ) ;
V_13 -> V_41 . V_52 = & V_38 -> V_41 ;
V_13 -> V_53 = F_17 ( V_38 ) -> V_53 ;
V_13 -> V_54 = V_55 ;
V_13 -> V_56 = & V_7 -> V_31 -> V_57 ;
V_13 -> V_58 = 1 ;
V_13 -> V_59 = & V_60 ;
if ( V_40 && F_4 ( V_40 -> V_61 ) ) {
V_43 = F_20 ( V_40 -> V_61 , V_62 ,
L_3 ) ;
if ( V_43 ) {
F_21 ( & V_38 -> V_41 , L_4 ) ;
goto V_63;
}
V_7 -> V_11 = V_40 -> V_61 ;
} else {
V_7 -> V_11 = - 1 ;
}
V_43 = F_22 ( V_13 ) ;
if ( V_43 )
goto V_64;
V_43 = F_23 ( V_13 ) ;
if ( V_43 )
goto V_65;
return 0 ;
V_65:
F_24 ( V_13 ) ;
V_64:
if ( V_40 && F_4 ( V_40 -> V_61 ) )
F_25 ( V_40 -> V_61 ) ;
V_63:
if ( ! F_14 ( V_7 -> V_47 ) )
F_26 ( V_7 -> V_47 ) ;
V_48:
if ( ! F_14 ( V_7 -> V_47 ) )
F_27 ( V_7 -> V_47 ) ;
F_28 ( V_13 ) ;
return V_43 ;
}
static int F_29 ( struct V_37 * V_38 )
{
struct V_12 * V_13 = F_30 ( V_38 ) ;
struct V_1 * V_7 = F_7 ( V_13 ) ;
F_31 ( V_13 ) ;
F_24 ( V_13 ) ;
if ( F_4 ( V_7 -> V_11 ) )
F_25 ( V_7 -> V_11 ) ;
if ( ! F_14 ( V_7 -> V_47 ) ) {
F_26 ( V_7 -> V_47 ) ;
F_27 ( V_7 -> V_47 ) ;
}
F_28 ( V_13 ) ;
return 0 ;
}
