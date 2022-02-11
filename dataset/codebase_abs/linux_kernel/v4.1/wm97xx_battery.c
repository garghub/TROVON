static unsigned long F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 . V_6 -> V_7 ;
struct V_8 * V_9 = V_4 -> V_10 ;
return F_2 ( F_3 ( V_2 -> V_5 . V_6 ) ,
V_9 -> V_11 ) * V_9 -> V_12 /
V_9 -> V_13 ;
}
static unsigned long F_4 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 . V_6 -> V_7 ;
struct V_8 * V_9 = V_4 -> V_10 ;
return F_2 ( F_3 ( V_2 -> V_5 . V_6 ) ,
V_9 -> V_14 ) * V_9 -> V_15 /
V_9 -> V_16 ;
}
static int F_5 ( struct V_1 * V_2 ,
enum V_17 V_18 ,
union V_19 * V_20 )
{
struct V_3 * V_4 = V_2 -> V_5 . V_6 -> V_7 ;
struct V_8 * V_9 = V_4 -> V_10 ;
switch ( V_18 ) {
case V_21 :
V_20 -> V_22 = V_23 ;
break;
case V_24 :
V_20 -> V_22 = V_9 -> V_25 ;
break;
case V_26 :
if ( V_9 -> V_11 >= 0 )
V_20 -> V_22 = F_1 ( V_2 ) ;
else
return - V_27 ;
break;
case V_28 :
if ( V_9 -> V_14 >= 0 )
V_20 -> V_22 = F_4 ( V_2 ) ;
else
return - V_27 ;
break;
case V_29 :
if ( V_9 -> V_30 >= 0 )
V_20 -> V_22 = V_9 -> V_30 ;
else
return - V_27 ;
break;
case V_31 :
if ( V_9 -> V_32 >= 0 )
V_20 -> V_22 = V_9 -> V_32 ;
else
return - V_27 ;
break;
case V_33 :
V_20 -> V_22 = 1 ;
break;
default:
return - V_27 ;
}
return 0 ;
}
static void F_6 ( struct V_1 * V_2 )
{
F_7 ( & V_34 ) ;
}
static void F_8 ( struct V_1 * V_2 )
{
int V_35 = V_23 ;
struct V_3 * V_4 = V_2 -> V_5 . V_6 -> V_7 ;
struct V_8 * V_9 = V_4 -> V_10 ;
F_9 ( & V_36 ) ;
V_23 = ( V_9 -> V_37 >= 0 ) ?
( F_10 ( V_9 -> V_37 ) ?
V_38 :
V_39 ) :
V_40 ;
if ( V_35 != V_23 ) {
F_11 ( L_1 , V_2 -> V_41 -> V_42 , V_35 ,
V_23 ) ;
F_12 ( V_2 ) ;
}
F_13 ( & V_36 ) ;
}
static void F_14 ( struct V_43 * V_44 )
{
F_8 ( V_45 ) ;
}
static T_1 F_15 ( int V_46 , void * V_47 )
{
F_7 ( & V_34 ) ;
return V_48 ;
}
static int F_16 ( struct V_49 * V_5 )
{
F_17 ( & V_34 ) ;
return 0 ;
}
static int F_18 ( struct V_49 * V_5 )
{
F_7 ( & V_34 ) ;
return 0 ;
}
static int F_19 ( struct V_50 * V_5 )
{
int V_51 = 0 ;
int V_52 = 1 ;
int V_53 = 0 ;
struct V_3 * V_4 = V_5 -> V_5 . V_7 ;
struct V_8 * V_9 ;
if ( ! V_4 ) {
F_20 ( & V_5 -> V_5 , L_2 ) ;
return - V_27 ;
}
V_9 = V_4 -> V_10 ;
if ( V_5 -> V_54 != - 1 )
return - V_27 ;
if ( ! V_9 ) {
F_20 ( & V_5 -> V_5 , L_3 ) ;
return - V_27 ;
}
if ( F_21 ( V_9 -> V_37 ) ) {
V_51 = F_22 ( V_9 -> V_37 , L_4 ) ;
if ( V_51 )
goto V_55;
V_51 = F_23 ( V_9 -> V_37 ) ;
if ( V_51 )
goto V_56;
V_51 = F_24 ( F_25 ( V_9 -> V_37 ) ,
F_15 , 0 ,
L_5 , V_5 ) ;
if ( V_51 )
goto V_56;
V_52 ++ ;
}
if ( V_9 -> V_25 >= 0 )
V_52 ++ ;
if ( V_9 -> V_14 >= 0 )
V_52 ++ ;
if ( V_9 -> V_11 >= 0 )
V_52 ++ ;
if ( V_9 -> V_30 >= 0 )
V_52 ++ ;
if ( V_9 -> V_32 >= 0 )
V_52 ++ ;
V_57 = F_26 ( V_52 * sizeof( * V_57 ) , V_58 ) ;
if ( ! V_57 ) {
V_51 = - V_59 ;
goto V_60;
}
V_57 [ V_53 ++ ] = V_33 ;
if ( V_9 -> V_37 >= 0 )
V_57 [ V_53 ++ ] = V_21 ;
if ( V_9 -> V_25 >= 0 )
V_57 [ V_53 ++ ] = V_24 ;
if ( V_9 -> V_14 >= 0 )
V_57 [ V_53 ++ ] = V_28 ;
if ( V_9 -> V_11 >= 0 )
V_57 [ V_53 ++ ] = V_26 ;
if ( V_9 -> V_30 >= 0 )
V_57 [ V_53 ++ ] = V_29 ;
if ( V_9 -> V_32 >= 0 )
V_57 [ V_53 ++ ] = V_31 ;
F_27 ( & V_34 , F_14 ) ;
if ( ! V_9 -> V_61 ) {
F_28 ( & V_5 -> V_5 , L_6
L_7
L_8 ) ;
V_62 . V_42 = L_9 ;
} else
V_62 . V_42 = V_9 -> V_61 ;
V_62 . V_63 = V_57 ;
V_62 . V_64 = V_52 ;
V_45 = F_29 ( & V_5 -> V_5 , & V_62 , NULL ) ;
if ( ! F_30 ( V_45 ) ) {
F_7 ( & V_34 ) ;
} else {
V_51 = F_31 ( V_45 ) ;
goto V_65;
}
return 0 ;
V_65:
F_32 ( V_57 ) ;
V_60:
if ( F_21 ( V_9 -> V_37 ) )
F_33 ( F_25 ( V_9 -> V_37 ) , V_5 ) ;
V_56:
if ( F_21 ( V_9 -> V_37 ) )
F_34 ( V_9 -> V_37 ) ;
V_55:
return V_51 ;
}
static int F_35 ( struct V_50 * V_5 )
{
struct V_3 * V_4 = V_5 -> V_5 . V_7 ;
struct V_8 * V_9 = V_4 -> V_10 ;
if ( V_9 && F_21 ( V_9 -> V_37 ) ) {
F_33 ( F_25 ( V_9 -> V_37 ) , V_5 ) ;
F_34 ( V_9 -> V_37 ) ;
}
F_36 ( & V_34 ) ;
F_37 ( V_45 ) ;
F_32 ( V_57 ) ;
return 0 ;
}
