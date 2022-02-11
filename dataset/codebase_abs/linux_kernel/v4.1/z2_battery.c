static unsigned long F_1 ( struct V_1 * V_2 )
{
int V_3 ;
V_3 = F_2 ( V_2 -> V_4 ,
V_2 -> V_5 -> V_6 ) ;
if ( V_3 < 0 )
return 0 ;
return V_3 * V_2 -> V_5 -> V_7 / V_2 -> V_5 -> V_8 ;
}
static int F_3 ( struct V_9 * V_10 ,
enum V_11 V_12 ,
union V_13 * V_14 )
{
struct V_1 * V_2 = F_4 ( V_10 ) ;
struct V_15 * V_5 = V_2 -> V_5 ;
switch ( V_12 ) {
case V_16 :
V_14 -> V_17 = V_2 -> V_18 ;
break;
case V_19 :
V_14 -> V_17 = V_5 -> V_20 ;
break;
case V_21 :
if ( V_5 -> V_6 >= 0 )
V_14 -> V_17 = F_1 ( V_2 ) ;
else
return - V_22 ;
break;
case V_23 :
if ( V_5 -> V_24 >= 0 )
V_14 -> V_17 = V_5 -> V_24 ;
else
return - V_22 ;
break;
case V_25 :
if ( V_5 -> V_26 >= 0 )
V_14 -> V_17 = V_5 -> V_26 ;
else
return - V_22 ;
break;
case V_27 :
V_14 -> V_17 = 1 ;
break;
default:
return - V_22 ;
}
return 0 ;
}
static void F_5 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = F_4 ( V_10 ) ;
F_6 ( & V_2 -> V_28 ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
int V_29 = V_2 -> V_18 ;
struct V_15 * V_5 ;
V_5 = V_2 -> V_5 ;
F_8 ( & V_2 -> V_30 ) ;
V_2 -> V_18 = ( V_5 -> V_31 >= 0 ) ?
( F_9 ( V_5 -> V_31 ) ?
V_32 :
V_33 ) :
V_34 ;
if ( V_29 != V_2 -> V_18 ) {
F_10 ( L_1 , V_2 -> V_10 -> V_35 -> V_36 ,
V_29 ,
V_2 -> V_18 ) ;
F_11 ( V_2 -> V_10 ) ;
}
F_12 ( & V_2 -> V_30 ) ;
}
static void F_13 ( struct V_37 * V_38 )
{
struct V_1 * V_2 ;
V_2 = F_14 ( V_38 , struct V_1 , V_28 ) ;
F_7 ( V_2 ) ;
}
static T_1 F_15 ( int V_39 , void * V_40 )
{
struct V_1 * V_2 = V_40 ;
F_6 ( & V_2 -> V_28 ) ;
return V_41 ;
}
static int F_16 ( struct V_1 * V_2 , int V_42 )
{
int V_43 = 0 ;
enum V_11 * V_44 ;
struct V_15 * V_5 = V_2 -> V_5 ;
if ( V_5 -> V_31 >= 0 )
V_42 ++ ;
if ( V_5 -> V_20 >= 0 )
V_42 ++ ;
if ( V_5 -> V_6 >= 0 )
V_42 ++ ;
if ( V_5 -> V_24 >= 0 )
V_42 ++ ;
if ( V_5 -> V_26 >= 0 )
V_42 ++ ;
V_44 = F_17 ( V_42 * sizeof( * V_44 ) , V_45 ) ;
if ( ! V_44 )
return - V_46 ;
V_44 [ V_43 ++ ] = V_27 ;
if ( V_5 -> V_31 >= 0 )
V_44 [ V_43 ++ ] = V_16 ;
if ( V_5 -> V_20 >= 0 )
V_44 [ V_43 ++ ] = V_19 ;
if ( V_5 -> V_6 >= 0 )
V_44 [ V_43 ++ ] = V_21 ;
if ( V_5 -> V_24 >= 0 )
V_44 [ V_43 ++ ] = V_23 ;
if ( V_5 -> V_26 >= 0 )
V_44 [ V_43 ++ ] = V_25 ;
if ( ! V_5 -> V_47 ) {
F_18 ( & V_2 -> V_4 -> V_48 ,
L_2
L_3
L_4 ) ;
V_2 -> V_49 . V_36 = V_50 ;
} else
V_2 -> V_49 . V_36 = V_5 -> V_47 ;
V_2 -> V_49 . V_51 = V_44 ;
V_2 -> V_49 . V_52 = V_42 ;
V_2 -> V_49 . type = V_53 ;
V_2 -> V_49 . V_54 = F_3 ;
V_2 -> V_49 . V_55 =
F_5 ;
V_2 -> V_49 . V_56 = 1 ;
return 0 ;
}
static int F_19 ( struct V_57 * V_4 ,
const struct V_58 * V_59 )
{
int V_60 = 0 ;
int V_42 = 1 ;
struct V_1 * V_2 ;
struct V_15 * V_5 = V_4 -> V_48 . V_61 ;
struct V_62 V_63 = {} ;
if ( V_5 == NULL ) {
F_20 ( & V_4 -> V_48 ,
L_5
L_6 ) ;
return - V_22 ;
}
V_2 = F_17 ( sizeof( * V_2 ) , V_45 ) ;
if ( V_2 == NULL )
return - V_46 ;
V_2 -> V_18 = V_34 ;
V_2 -> V_5 = V_5 ;
V_2 -> V_4 = V_4 ;
F_21 ( V_4 , V_2 ) ;
V_63 . V_64 = V_2 ;
F_22 ( & V_2 -> V_30 ) ;
if ( V_5 -> V_31 >= 0 && F_23 ( V_5 -> V_31 ) ) {
V_60 = F_24 ( V_5 -> V_31 , L_7 ) ;
if ( V_60 )
goto V_65;
V_60 = F_25 ( V_5 -> V_31 ) ;
if ( V_60 )
goto V_66;
F_26 ( F_27 ( V_5 -> V_31 ) ,
V_67 ) ;
V_60 = F_28 ( F_27 ( V_5 -> V_31 ) ,
F_15 , 0 ,
L_8 , V_2 ) ;
if ( V_60 )
goto V_68;
}
V_60 = F_16 ( V_2 , V_42 ) ;
if ( V_60 )
goto V_68;
F_29 ( & V_2 -> V_28 , F_13 ) ;
V_2 -> V_10 = F_30 ( & V_4 -> V_48 ,
& V_2 -> V_49 ,
& V_63 ) ;
if ( F_31 ( V_2 -> V_10 ) ) {
V_60 = F_32 ( V_2 -> V_10 ) ;
goto V_69;
}
F_6 ( & V_2 -> V_28 ) ;
return 0 ;
V_69:
F_33 ( V_2 -> V_49 . V_51 ) ;
V_68:
if ( V_5 -> V_31 >= 0 && F_23 ( V_5 -> V_31 ) )
F_34 ( F_27 ( V_5 -> V_31 ) , V_2 ) ;
V_66:
if ( V_5 -> V_31 >= 0 && F_23 ( V_5 -> V_31 ) )
F_35 ( V_5 -> V_31 ) ;
V_65:
F_33 ( V_2 ) ;
return V_60 ;
}
static int F_36 ( struct V_57 * V_4 )
{
struct V_1 * V_2 = F_37 ( V_4 ) ;
struct V_15 * V_5 = V_2 -> V_5 ;
F_38 ( & V_2 -> V_28 ) ;
F_39 ( V_2 -> V_10 ) ;
F_33 ( V_2 -> V_49 . V_51 ) ;
if ( V_5 -> V_31 >= 0 && F_23 ( V_5 -> V_31 ) ) {
F_34 ( F_27 ( V_5 -> V_31 ) , V_2 ) ;
F_35 ( V_5 -> V_31 ) ;
}
F_33 ( V_2 ) ;
return 0 ;
}
static int F_40 ( struct V_70 * V_48 )
{
struct V_57 * V_4 = F_41 ( V_48 ) ;
struct V_1 * V_2 = F_37 ( V_4 ) ;
F_42 ( & V_2 -> V_28 ) ;
return 0 ;
}
static int F_43 ( struct V_70 * V_48 )
{
struct V_57 * V_4 = F_41 ( V_48 ) ;
struct V_1 * V_2 = F_37 ( V_4 ) ;
F_6 ( & V_2 -> V_28 ) ;
return 0 ;
}
