static unsigned long F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return F_3 ( F_4 ( V_2 -> V_5 . V_6 ) ,
V_4 -> V_7 ) * V_4 -> V_8 /
V_4 -> V_9 ;
}
static unsigned long F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return F_3 ( F_4 ( V_2 -> V_5 . V_6 ) ,
V_4 -> V_10 ) * V_4 -> V_11 /
V_4 -> V_12 ;
}
static int F_6 ( struct V_1 * V_2 ,
enum V_13 V_14 ,
union V_15 * V_16 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
switch ( V_14 ) {
case V_17 :
V_16 -> V_18 = V_19 ;
break;
case V_20 :
V_16 -> V_18 = V_4 -> V_21 ;
break;
case V_22 :
if ( V_4 -> V_7 >= 0 )
V_16 -> V_18 = F_1 ( V_2 ) ;
else
return - V_23 ;
break;
case V_24 :
if ( V_4 -> V_10 >= 0 )
V_16 -> V_18 = F_5 ( V_2 ) ;
else
return - V_23 ;
break;
case V_25 :
if ( V_4 -> V_26 >= 0 )
V_16 -> V_18 = V_4 -> V_26 ;
else
return - V_23 ;
break;
case V_27 :
if ( V_4 -> V_28 >= 0 )
V_16 -> V_18 = V_4 -> V_28 ;
else
return - V_23 ;
break;
case V_29 :
V_16 -> V_18 = 1 ;
break;
default:
return - V_23 ;
}
return 0 ;
}
static void F_7 ( struct V_1 * V_2 )
{
F_8 ( & V_30 ) ;
}
static void F_9 ( struct V_1 * V_2 )
{
int V_31 = V_19 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_10 ( & V_32 ) ;
V_19 = ( V_4 -> V_33 >= 0 ) ?
( F_11 ( V_4 -> V_33 ) ?
V_34 :
V_35 ) :
V_36 ;
if ( V_31 != V_19 ) {
F_12 ( L_1 , V_2 -> V_37 -> V_38 , V_31 ,
V_19 ) ;
F_13 ( V_2 ) ;
}
F_14 ( & V_32 ) ;
}
static void F_15 ( struct V_39 * V_40 )
{
F_9 ( V_41 ) ;
}
static T_1 F_16 ( int V_42 , void * V_43 )
{
F_8 ( & V_30 ) ;
return V_44 ;
}
static int F_17 ( struct V_45 * V_5 )
{
F_18 ( & V_30 ) ;
return 0 ;
}
static int F_19 ( struct V_45 * V_5 )
{
F_8 ( & V_30 ) ;
return 0 ;
}
static int F_20 ( struct V_46 * V_5 )
{
int V_47 = 0 ;
int V_48 = 1 ;
int V_49 = 0 ;
struct V_3 * V_4 = V_5 -> V_5 . V_50 ;
struct V_51 V_52 = {} ;
if ( ! V_4 ) {
F_21 ( & V_5 -> V_5 , L_2 ) ;
return - V_23 ;
}
V_52 . V_53 = V_4 ;
if ( V_5 -> V_54 != - 1 )
return - V_23 ;
if ( ! V_4 ) {
F_21 ( & V_5 -> V_5 , L_3 ) ;
return - V_23 ;
}
if ( F_22 ( V_4 -> V_33 ) ) {
V_47 = F_23 ( V_4 -> V_33 , L_4 ) ;
if ( V_47 )
goto V_55;
V_47 = F_24 ( V_4 -> V_33 ) ;
if ( V_47 )
goto V_56;
V_47 = F_25 ( F_26 ( V_4 -> V_33 ) ,
F_16 , 0 ,
L_5 , V_5 ) ;
if ( V_47 )
goto V_56;
V_48 ++ ;
}
if ( V_4 -> V_21 >= 0 )
V_48 ++ ;
if ( V_4 -> V_10 >= 0 )
V_48 ++ ;
if ( V_4 -> V_7 >= 0 )
V_48 ++ ;
if ( V_4 -> V_26 >= 0 )
V_48 ++ ;
if ( V_4 -> V_28 >= 0 )
V_48 ++ ;
V_57 = F_27 ( V_48 * sizeof( * V_57 ) , V_58 ) ;
if ( ! V_57 ) {
V_47 = - V_59 ;
goto V_60;
}
V_57 [ V_49 ++ ] = V_29 ;
if ( V_4 -> V_33 >= 0 )
V_57 [ V_49 ++ ] = V_17 ;
if ( V_4 -> V_21 >= 0 )
V_57 [ V_49 ++ ] = V_20 ;
if ( V_4 -> V_10 >= 0 )
V_57 [ V_49 ++ ] = V_24 ;
if ( V_4 -> V_7 >= 0 )
V_57 [ V_49 ++ ] = V_22 ;
if ( V_4 -> V_26 >= 0 )
V_57 [ V_49 ++ ] = V_25 ;
if ( V_4 -> V_28 >= 0 )
V_57 [ V_49 ++ ] = V_27 ;
F_28 ( & V_30 , F_15 ) ;
if ( ! V_4 -> V_61 ) {
F_29 ( & V_5 -> V_5 , L_6
L_7
L_8 ) ;
V_62 . V_38 = L_9 ;
} else
V_62 . V_38 = V_4 -> V_61 ;
V_62 . V_63 = V_57 ;
V_62 . V_64 = V_48 ;
V_41 = F_30 ( & V_5 -> V_5 , & V_62 , & V_52 ) ;
if ( ! F_31 ( V_41 ) ) {
F_8 ( & V_30 ) ;
} else {
V_47 = F_32 ( V_41 ) ;
goto V_65;
}
return 0 ;
V_65:
F_33 ( V_57 ) ;
V_60:
if ( F_22 ( V_4 -> V_33 ) )
F_34 ( F_26 ( V_4 -> V_33 ) , V_5 ) ;
V_56:
if ( F_22 ( V_4 -> V_33 ) )
F_35 ( V_4 -> V_33 ) ;
V_55:
return V_47 ;
}
static int F_36 ( struct V_46 * V_5 )
{
struct V_3 * V_4 = V_5 -> V_5 . V_50 ;
if ( V_4 && F_22 ( V_4 -> V_33 ) ) {
F_34 ( F_26 ( V_4 -> V_33 ) , V_5 ) ;
F_35 ( V_4 -> V_33 ) ;
}
F_37 ( & V_30 ) ;
F_38 ( V_41 ) ;
F_33 ( V_57 ) ;
return 0 ;
}
