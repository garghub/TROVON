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
struct V_1 * V_2 = F_4 ( V_10 , struct V_1 ,
V_10 ) ;
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
struct V_1 * V_2 = F_4 ( V_10 , struct V_1 ,
V_10 ) ;
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
F_10 ( L_1 , V_2 -> V_10 . V_35 , V_29 ,
V_2 -> V_18 ) ;
F_11 ( & V_2 -> V_10 ) ;
}
F_12 ( & V_2 -> V_30 ) ;
}
static void F_13 ( struct V_36 * V_37 )
{
struct V_1 * V_2 ;
V_2 = F_4 ( V_37 , struct V_1 , V_28 ) ;
F_7 ( V_2 ) ;
}
static T_1 F_14 ( int V_38 , void * V_39 )
{
struct V_1 * V_2 = V_39 ;
F_6 ( & V_2 -> V_28 ) ;
return V_40 ;
}
static int F_15 ( struct V_1 * V_2 , int V_41 )
{
int V_42 = 0 ;
enum V_11 * V_43 ;
struct V_15 * V_5 = V_2 -> V_5 ;
if ( V_5 -> V_31 >= 0 )
V_41 ++ ;
if ( V_5 -> V_20 >= 0 )
V_41 ++ ;
if ( V_5 -> V_6 >= 0 )
V_41 ++ ;
if ( V_5 -> V_24 >= 0 )
V_41 ++ ;
if ( V_5 -> V_26 >= 0 )
V_41 ++ ;
V_43 = F_16 ( V_41 * sizeof( * V_43 ) , V_44 ) ;
if ( ! V_43 )
return - V_45 ;
V_43 [ V_42 ++ ] = V_27 ;
if ( V_5 -> V_31 >= 0 )
V_43 [ V_42 ++ ] = V_16 ;
if ( V_5 -> V_20 >= 0 )
V_43 [ V_42 ++ ] = V_19 ;
if ( V_5 -> V_6 >= 0 )
V_43 [ V_42 ++ ] = V_21 ;
if ( V_5 -> V_24 >= 0 )
V_43 [ V_42 ++ ] = V_23 ;
if ( V_5 -> V_26 >= 0 )
V_43 [ V_42 ++ ] = V_25 ;
if ( ! V_5 -> V_46 ) {
F_17 ( & V_2 -> V_4 -> V_47 ,
L_2
L_3
L_4 ) ;
V_2 -> V_10 . V_35 = V_48 ;
} else
V_2 -> V_10 . V_35 = V_5 -> V_46 ;
V_2 -> V_10 . V_49 = V_43 ;
V_2 -> V_10 . V_50 = V_41 ;
V_2 -> V_10 . type = V_51 ;
V_2 -> V_10 . V_52 = F_3 ;
V_2 -> V_10 . V_53 = F_5 ;
V_2 -> V_10 . V_54 = 1 ;
return 0 ;
}
static int T_2 F_18 ( struct V_55 * V_4 ,
const struct V_56 * V_57 )
{
int V_58 = 0 ;
int V_41 = 1 ;
struct V_1 * V_2 ;
struct V_15 * V_5 = V_4 -> V_47 . V_59 ;
if ( V_5 == NULL ) {
F_19 ( & V_4 -> V_47 ,
L_5
L_6 ) ;
return - V_22 ;
}
V_2 = F_16 ( sizeof( * V_2 ) , V_44 ) ;
if ( V_2 == NULL )
return - V_45 ;
V_2 -> V_18 = V_34 ;
V_2 -> V_5 = V_5 ;
V_2 -> V_4 = V_4 ;
F_20 ( V_4 , V_2 ) ;
F_21 ( & V_2 -> V_30 ) ;
if ( V_5 -> V_31 >= 0 && F_22 ( V_5 -> V_31 ) ) {
V_58 = F_23 ( V_5 -> V_31 , L_7 ) ;
if ( V_58 )
goto V_60;
V_58 = F_24 ( V_5 -> V_31 ) ;
if ( V_58 )
goto V_61;
F_25 ( F_26 ( V_5 -> V_31 ) ,
V_62 ) ;
V_58 = F_27 ( F_26 ( V_5 -> V_31 ) ,
F_14 , 0 ,
L_8 , V_2 ) ;
if ( V_58 )
goto V_63;
}
V_58 = F_15 ( V_2 , V_41 ) ;
if ( V_58 )
goto V_63;
F_28 ( & V_2 -> V_28 , F_13 ) ;
V_58 = F_29 ( & V_4 -> V_47 , & V_2 -> V_10 ) ;
if ( V_58 )
goto V_64;
F_6 ( & V_2 -> V_28 ) ;
return 0 ;
V_64:
F_30 ( V_2 -> V_10 . V_49 ) ;
V_63:
if ( V_5 -> V_31 >= 0 && F_22 ( V_5 -> V_31 ) )
F_31 ( F_26 ( V_5 -> V_31 ) , V_2 ) ;
V_61:
if ( V_5 -> V_31 >= 0 && F_22 ( V_5 -> V_31 ) )
F_32 ( V_5 -> V_31 ) ;
V_60:
F_30 ( V_2 ) ;
return V_58 ;
}
static int T_3 F_33 ( struct V_55 * V_4 )
{
struct V_1 * V_2 = F_34 ( V_4 ) ;
struct V_15 * V_5 = V_2 -> V_5 ;
F_35 ( & V_2 -> V_28 ) ;
F_36 ( & V_2 -> V_10 ) ;
F_30 ( V_2 -> V_10 . V_49 ) ;
if ( V_5 -> V_31 >= 0 && F_22 ( V_5 -> V_31 ) ) {
F_31 ( F_26 ( V_5 -> V_31 ) , V_2 ) ;
F_32 ( V_5 -> V_31 ) ;
}
F_30 ( V_2 ) ;
return 0 ;
}
static int F_37 ( struct V_65 * V_47 )
{
struct V_55 * V_4 = F_38 ( V_47 ) ;
struct V_1 * V_2 = F_34 ( V_4 ) ;
F_39 ( & V_2 -> V_28 ) ;
return 0 ;
}
static int F_40 ( struct V_65 * V_47 )
{
struct V_55 * V_4 = F_38 ( V_47 ) ;
struct V_1 * V_2 = F_34 ( V_4 ) ;
F_6 ( & V_2 -> V_28 ) ;
return 0 ;
}
