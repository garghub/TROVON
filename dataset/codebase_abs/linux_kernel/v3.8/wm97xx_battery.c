static unsigned long F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 -> V_6 -> V_7 ;
struct V_8 * V_9 = V_4 -> V_10 ;
return F_2 ( F_3 ( V_2 -> V_5 -> V_6 ) ,
V_9 -> V_11 ) * V_9 -> V_12 /
V_9 -> V_13 ;
}
static unsigned long F_4 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 -> V_6 -> V_7 ;
struct V_8 * V_9 = V_4 -> V_10 ;
return F_2 ( F_3 ( V_2 -> V_5 -> V_6 ) ,
V_9 -> V_14 ) * V_9 -> V_15 /
V_9 -> V_16 ;
}
static int F_5 ( struct V_1 * V_2 ,
enum V_17 V_18 ,
union V_19 * V_20 )
{
struct V_3 * V_4 = V_2 -> V_5 -> V_6 -> V_7 ;
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
struct V_3 * V_4 = V_2 -> V_5 -> V_6 -> V_7 ;
struct V_8 * V_9 = V_4 -> V_10 ;
F_9 ( & V_36 ) ;
V_23 = ( V_9 -> V_37 >= 0 ) ?
( F_10 ( V_9 -> V_37 ) ?
V_38 :
V_39 ) :
V_40 ;
if ( V_35 != V_23 ) {
F_11 ( L_1 , V_2 -> V_41 , V_35 ,
V_23 ) ;
F_12 ( V_2 ) ;
}
F_13 ( & V_36 ) ;
}
static void F_14 ( struct V_42 * V_43 )
{
F_8 ( & V_2 ) ;
}
static T_1 F_15 ( int V_44 , void * V_45 )
{
F_7 ( & V_34 ) ;
return V_46 ;
}
static int F_16 ( struct V_47 * V_5 )
{
F_17 ( & V_34 ) ;
return 0 ;
}
static int F_18 ( struct V_47 * V_5 )
{
F_7 ( & V_34 ) ;
return 0 ;
}
static int F_19 ( struct V_48 * V_5 )
{
int V_49 = 0 ;
int V_50 = 1 ;
int V_51 = 0 ;
struct V_3 * V_4 = V_5 -> V_5 . V_7 ;
struct V_8 * V_9 ;
if ( ! V_4 ) {
F_20 ( & V_5 -> V_5 , L_2 ) ;
return - V_27 ;
}
V_9 = V_4 -> V_10 ;
if ( V_5 -> V_52 != - 1 )
return - V_27 ;
if ( ! V_9 ) {
F_20 ( & V_5 -> V_5 , L_3 ) ;
return - V_27 ;
}
if ( F_21 ( V_9 -> V_37 ) ) {
V_49 = F_22 ( V_9 -> V_37 , L_4 ) ;
if ( V_49 )
goto V_53;
V_49 = F_23 ( V_9 -> V_37 ) ;
if ( V_49 )
goto V_54;
V_49 = F_24 ( F_25 ( V_9 -> V_37 ) ,
F_15 , 0 ,
L_5 , V_5 ) ;
if ( V_49 )
goto V_54;
V_50 ++ ;
}
if ( V_9 -> V_25 >= 0 )
V_50 ++ ;
if ( V_9 -> V_14 >= 0 )
V_50 ++ ;
if ( V_9 -> V_11 >= 0 )
V_50 ++ ;
if ( V_9 -> V_30 >= 0 )
V_50 ++ ;
if ( V_9 -> V_32 >= 0 )
V_50 ++ ;
V_55 = F_26 ( V_50 * sizeof( * V_55 ) , V_56 ) ;
if ( ! V_55 ) {
V_49 = - V_57 ;
goto V_58;
}
V_55 [ V_51 ++ ] = V_33 ;
if ( V_9 -> V_37 >= 0 )
V_55 [ V_51 ++ ] = V_21 ;
if ( V_9 -> V_25 >= 0 )
V_55 [ V_51 ++ ] = V_24 ;
if ( V_9 -> V_14 >= 0 )
V_55 [ V_51 ++ ] = V_28 ;
if ( V_9 -> V_11 >= 0 )
V_55 [ V_51 ++ ] = V_26 ;
if ( V_9 -> V_30 >= 0 )
V_55 [ V_51 ++ ] = V_29 ;
if ( V_9 -> V_32 >= 0 )
V_55 [ V_51 ++ ] = V_31 ;
F_27 ( & V_34 , F_14 ) ;
if ( ! V_9 -> V_59 ) {
F_28 ( & V_5 -> V_5 , L_6
L_7
L_8 ) ;
V_2 . V_41 = L_9 ;
} else
V_2 . V_41 = V_9 -> V_59 ;
V_2 . V_60 = V_55 ;
V_2 . V_61 = V_50 ;
V_49 = F_29 ( & V_5 -> V_5 , & V_2 ) ;
if ( ! V_49 )
F_7 ( & V_34 ) ;
else
goto V_62;
return 0 ;
V_62:
F_30 ( V_55 ) ;
V_58:
if ( F_21 ( V_9 -> V_37 ) )
F_31 ( F_25 ( V_9 -> V_37 ) , V_5 ) ;
V_54:
if ( F_21 ( V_9 -> V_37 ) )
F_32 ( V_9 -> V_37 ) ;
V_53:
return V_49 ;
}
static int F_33 ( struct V_48 * V_5 )
{
struct V_3 * V_4 = V_5 -> V_5 . V_7 ;
struct V_8 * V_9 = V_4 -> V_10 ;
if ( V_9 && F_21 ( V_9 -> V_37 ) ) {
F_31 ( F_25 ( V_9 -> V_37 ) , V_5 ) ;
F_32 ( V_9 -> V_37 ) ;
}
F_34 ( & V_34 ) ;
F_35 ( & V_2 ) ;
F_30 ( V_55 ) ;
return 0 ;
}
