static int F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = V_1 -> V_4 ;
F_2 ( V_3 -> V_5 ) ;
return 0 ;
}
static void F_3 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = V_1 -> V_4 ;
F_4 ( V_3 -> V_5 ) ;
}
static int F_5 ( struct V_1 * V_1 , unsigned char V_6 )
{
struct V_2 * V_3 = V_1 -> V_4 ;
F_6 ( V_3 -> V_5 ) ;
F_7 ( V_3 -> V_7 , 0 ) ;
V_3 -> V_8 = V_9 ;
V_3 -> V_10 = V_6 ;
F_8 ( & V_3 -> V_11 , F_9 ( 200 ) ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_1 , unsigned char V_6 )
{
struct V_2 * V_3 = V_1 -> V_4 ;
int V_12 = 0 ;
if ( F_11 () ) {
F_12 ( & V_3 -> V_13 ) ;
F_5 ( V_1 , V_6 ) ;
if ( ! F_13 ( & V_3 -> V_14 ,
F_14 ( 10000 ) ) )
V_12 = V_15 ;
F_15 ( & V_3 -> V_13 ) ;
} else {
F_5 ( V_1 , V_6 ) ;
}
return V_12 ;
}
static void F_16 ( struct V_16 * V_17 )
{
struct V_18 * V_19 = F_17 ( V_17 ) ;
struct V_2 * V_3 = F_18 ( V_19 ,
struct V_2 ,
V_11 ) ;
F_2 ( V_3 -> V_5 ) ;
F_7 ( V_3 -> V_20 , 0 ) ;
F_19 ( V_3 -> V_7 ) ;
}
static T_1 F_20 ( struct V_2 * V_3 )
{
unsigned char V_21 , V_22 ;
int V_23 ;
int V_24 = 0 ;
static unsigned long V_25 ;
V_21 = V_3 -> V_26 ;
V_22 = V_3 -> V_27 ;
if ( V_25 == 0 )
V_25 = V_28 ;
if ( ( V_28 - V_25 ) > F_9 ( 100 ) ) {
F_21 ( V_3 -> V_29 ,
L_1 ) ;
goto V_30;
}
V_25 = V_28 ;
V_23 = F_22 ( V_3 -> V_20 ) ;
if ( F_23 ( V_23 < 0 ) ) {
F_21 ( V_3 -> V_29 , L_2 ,
V_23 ) ;
goto V_30;
}
switch ( V_22 ) {
case V_31 :
if ( F_23 ( V_23 ) ) {
F_21 ( V_3 -> V_29 , L_3 ) ;
goto V_30;
}
break;
case V_32 :
case V_33 :
case V_34 :
case V_35 :
case V_36 :
case V_37 :
case V_38 :
case V_39 :
if ( V_23 )
V_21 |= ( V_23 << ( V_22 - 1 ) ) ;
break;
case V_40 :
if ( ! ( ( F_24 ( V_21 ) & 1 ) ^ V_23 ) ) {
V_24 |= V_41 ;
F_25 ( V_3 -> V_29 , L_4 ) ;
if ( ! V_3 -> V_42 )
goto V_30;
}
if ( ! V_3 -> V_42 ) {
if ( V_21 == V_43 )
goto V_30;
else if ( V_21 == V_44 )
break;
}
F_26 ( V_3 -> V_1 , V_21 , V_24 ) ;
F_27 ( V_3 -> V_29 , L_5 , V_21 ) ;
break;
case V_45 :
if ( F_23 ( ! V_23 ) ) {
F_21 ( V_3 -> V_29 , L_6 ) ;
goto V_30;
}
V_22 = V_21 = 0 ;
V_25 = 0 ;
goto V_46;
default:
F_21 ( V_3 -> V_29 , L_7 ) ;
goto V_30;
}
V_22 ++ ;
goto V_46;
V_30:
V_22 = V_21 = 0 ;
V_25 = 0 ;
F_5 ( V_3 -> V_1 , V_47 ) ;
V_46:
V_3 -> V_27 = V_22 ;
V_3 -> V_26 = V_21 ;
return V_48 ;
}
static T_1 F_28 ( struct V_2 * V_3 )
{
unsigned char V_21 , V_22 ;
int V_23 ;
static unsigned long V_25 ;
V_22 = V_3 -> V_49 ;
V_21 = V_3 -> V_10 ;
if ( V_25 == 0 )
V_25 = V_28 ;
if ( ( V_28 - V_25 ) > F_9 ( 100 ) ) {
F_21 ( V_3 -> V_29 ,
L_8 ) ;
goto V_30;
}
V_25 = V_28 ;
switch ( V_22 ) {
case V_31 :
F_21 ( V_3 -> V_29 ,
L_9 ) ;
goto V_30;
case V_32 :
case V_33 :
case V_34 :
case V_35 :
case V_36 :
case V_37 :
case V_38 :
case V_39 :
V_23 = V_21 & F_29 ( V_22 - 1 ) ;
F_30 ( V_3 -> V_20 , V_23 ) ;
break;
case V_40 :
V_23 = ! ( F_24 ( V_21 ) & 1 ) ;
F_30 ( V_3 -> V_20 , V_23 ) ;
break;
case V_45 :
F_19 ( V_3 -> V_20 ) ;
break;
case V_50 :
break;
case V_51 :
F_19 ( V_3 -> V_20 ) ;
V_23 = F_22 ( V_3 -> V_20 ) ;
if ( V_23 ) {
F_25 ( V_3 -> V_29 , L_10 ) ;
goto V_30;
}
V_3 -> V_8 = V_52 ;
F_31 ( & V_3 -> V_14 ) ;
V_22 = 1 ;
V_25 = 0 ;
goto V_46;
default:
F_19 ( V_3 -> V_20 ) ;
F_21 ( V_3 -> V_29 , L_11 ) ;
goto V_30;
}
V_22 ++ ;
goto V_46;
V_30:
V_22 = 1 ;
V_25 = 0 ;
F_19 ( V_3 -> V_20 ) ;
F_5 ( V_3 -> V_1 , V_3 -> V_10 ) ;
V_46:
V_3 -> V_49 = V_22 ;
return V_48 ;
}
static T_1 F_32 ( int V_5 , void * V_53 )
{
struct V_2 * V_3 = V_53 ;
return V_3 -> V_8 ? F_28 ( V_3 ) :
F_20 ( V_3 ) ;
}
static int F_33 ( struct V_54 * V_29 ,
struct V_2 * V_3 )
{
V_3 -> V_20 = F_34 ( V_29 , L_12 , V_55 ) ;
if ( F_35 ( V_3 -> V_20 ) ) {
F_21 ( V_29 , L_13 ,
F_36 ( V_3 -> V_20 ) ) ;
return F_36 ( V_3 -> V_20 ) ;
}
V_3 -> V_7 = F_34 ( V_29 , L_14 , V_55 ) ;
if ( F_35 ( V_3 -> V_7 ) ) {
F_21 ( V_29 , L_15 ,
F_36 ( V_3 -> V_7 ) ) ;
return F_36 ( V_3 -> V_7 ) ;
}
V_3 -> V_42 = F_37 ( V_29 ,
L_16 ) ;
return 0 ;
}
static int F_38 ( struct V_56 * V_57 )
{
struct V_2 * V_3 ;
struct V_1 * V_1 ;
struct V_54 * V_29 = & V_57 -> V_29 ;
int error ;
V_3 = F_39 ( V_29 , sizeof( struct V_2 ) , V_58 ) ;
V_1 = F_40 ( sizeof( struct V_1 ) , V_58 ) ;
if ( ! V_3 || ! V_1 ) {
error = - V_59 ;
goto V_60;
}
error = F_33 ( V_29 , V_3 ) ;
if ( error )
goto V_60;
if ( F_41 ( V_3 -> V_20 ) ||
F_41 ( V_3 -> V_7 ) ) {
F_21 ( V_29 , L_17 ) ;
error = - V_61 ;
}
V_3 -> V_5 = F_42 ( V_57 , 0 ) ;
if ( V_3 -> V_5 < 0 ) {
F_21 ( V_29 , L_18 ,
V_3 -> V_5 ) ;
error = V_3 -> V_5 ;
goto V_60;
}
error = F_43 ( V_29 , V_3 -> V_5 , F_32 ,
V_62 , V_63 , V_3 ) ;
if ( error ) {
F_21 ( V_29 , L_19 ,
V_3 -> V_5 , error ) ;
goto V_60;
}
F_4 ( V_3 -> V_5 ) ;
V_1 -> V_64 . type = V_65 ;
V_1 -> V_66 = F_1 ;
V_1 -> V_67 = F_3 ;
V_1 -> V_68 = V_3 -> V_42 ? F_10 : NULL ;
V_1 -> V_4 = V_3 ;
V_1 -> V_29 . V_69 = V_29 ;
F_44 ( V_1 -> V_70 , F_45 ( V_29 ) , sizeof( V_1 -> V_70 ) ) ;
F_44 ( V_1 -> V_71 , F_45 ( V_29 ) , sizeof( V_1 -> V_71 ) ) ;
V_3 -> V_1 = V_1 ;
V_3 -> V_29 = V_29 ;
V_3 -> V_8 = V_52 ;
V_3 -> V_49 = 1 ;
F_46 ( & V_3 -> V_11 , F_16 ) ;
F_47 ( & V_3 -> V_14 ) ;
F_48 ( & V_3 -> V_13 ) ;
F_49 ( V_1 ) ;
F_50 ( V_57 , V_3 ) ;
return 0 ;
V_60:
F_51 ( V_1 ) ;
return error ;
}
static int F_52 ( struct V_56 * V_57 )
{
struct V_2 * V_3 = F_53 ( V_57 ) ;
F_54 ( V_3 -> V_1 ) ;
return 0 ;
}
