static int F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct F_1 * V_7 = V_4 -> V_8 ;
int V_9 ;
int V_10 ;
F_2 ( & V_7 -> V_11 ) ;
V_7 -> V_12 . V_13 = V_14 ;
F_3 ( & V_7 -> V_15 , V_2 ) ;
V_9 = V_7 -> V_16 ;
switch ( V_7 -> V_17 ) {
case V_18 :
V_10 = F_4 ( V_2 ) ;
if ( V_10 )
goto V_19;
break;
case V_20 :
V_10 = F_5 ( V_2 , V_7 -> V_21 , V_7 -> V_22 ) ;
if ( V_10 )
goto V_19;
break;
default:
F_6 () ;
}
goto V_23;
V_19:
V_9 = V_24 ;
V_7 -> V_25 . V_26 ++ ;
V_23:
F_7 ( & V_7 -> V_11 ) ;
return V_9 ;
}
static int F_8 ( struct V_27 * V_27 , struct V_28 * V_29 ,
struct V_28 * V_30 , struct V_3 * V_4 ,
int V_31 , int V_32 )
{
struct V_33 * V_34 = F_9 ( V_27 , V_35 ) ;
struct V_28 * V_36 [ V_37 + 1 ] ;
struct V_38 * V_39 ;
struct F_1 * V_7 ;
int V_9 ;
T_1 V_40 = 0 ;
T_1 V_41 = 0 ;
int V_42 = 0 , V_43 = 0 ;
int V_10 ;
if ( ! V_29 )
return - V_44 ;
V_10 = F_10 ( V_36 , V_37 , V_29 , V_45 ) ;
if ( V_10 < 0 )
return V_10 ;
if ( ! V_36 [ V_46 ] )
return - V_44 ;
V_39 = F_11 ( V_36 [ V_46 ] ) ;
V_43 = F_12 ( V_34 , V_39 -> V_47 , V_4 , V_32 ) ;
if ( V_43 && V_32 )
return 0 ;
switch ( V_39 -> V_48 ) {
case V_18 :
break;
case V_20 :
if ( ! V_36 [ V_49 ] ) {
if ( V_43 )
F_13 ( V_4 , V_32 ) ;
return - V_44 ;
}
V_40 = F_14 ( V_36 [ V_49 ] ) ;
if ( V_40 >= V_50 ) {
if ( V_43 )
F_13 ( V_4 , V_32 ) ;
return - V_51 ;
}
if ( V_36 [ V_52 ] ) {
V_41 = F_15 ( V_36 [ V_52 ] ) ;
switch ( V_41 ) {
case F_16 ( V_53 ) :
case F_16 ( V_54 ) :
break;
default:
return - V_55 ;
}
} else {
V_41 = F_16 ( V_53 ) ;
}
break;
default:
if ( V_43 )
F_13 ( V_4 , V_32 ) ;
return - V_44 ;
}
V_9 = V_39 -> V_48 ;
if ( ! V_43 ) {
V_42 = F_17 ( V_34 , V_39 -> V_47 , V_30 , V_4 ,
sizeof( * V_7 ) , V_32 , false ) ;
if ( V_42 )
return V_42 ;
V_42 = V_56 ;
} else {
F_13 ( V_4 , V_32 ) ;
if ( ! V_31 )
return - V_57 ;
}
V_7 = F_18 ( V_4 ) ;
F_19 ( & V_7 -> V_11 ) ;
V_7 -> V_17 = V_9 ;
V_7 -> V_22 = V_40 ;
V_7 -> V_21 = V_41 ;
V_7 -> V_16 = V_39 -> V_9 ;
F_20 ( & V_7 -> V_11 ) ;
if ( V_42 == V_56 )
F_21 ( V_34 , V_4 ) ;
return V_42 ;
}
static int F_22 ( struct V_1 * V_2 , struct V_3 * V_4 ,
int V_32 , int V_58 )
{
unsigned char * V_59 = F_23 ( V_2 ) ;
struct F_1 * V_7 = V_4 -> V_8 ;
struct V_38 V_60 = {
. V_47 = V_7 -> V_61 ,
. V_62 = V_7 -> V_63 - V_58 ,
. V_64 = V_7 -> V_65 - V_32 ,
. V_9 = V_7 -> V_16 ,
. V_48 = V_7 -> V_17 ,
} ;
struct V_66 V_67 ;
if ( F_24 ( V_2 , V_46 , sizeof( V_60 ) , & V_60 ) )
goto V_68;
if ( V_7 -> V_17 == V_20 &&
( F_25 ( V_2 , V_49 , V_7 -> V_22 ) ||
F_26 ( V_2 , V_52 , V_7 -> V_21 ) ) )
goto V_68;
V_67 . V_69 = F_27 ( V_14 - V_7 -> V_12 . V_69 ) ;
V_67 . V_13 = F_27 ( V_14 - V_7 -> V_12 . V_13 ) ;
V_67 . V_70 = F_27 ( V_7 -> V_12 . V_70 ) ;
if ( F_24 ( V_2 , V_71 , sizeof( V_67 ) , & V_67 ) )
goto V_68;
return V_2 -> V_72 ;
V_68:
F_28 ( V_2 , V_59 ) ;
return - 1 ;
}
static int F_29 ( struct V_27 * V_27 , struct V_1 * V_2 ,
struct V_73 * V_74 , int type ,
struct V_3 * V_4 )
{
struct V_33 * V_34 = F_9 ( V_27 , V_35 ) ;
return F_30 ( V_34 , V_2 , V_74 , type , V_4 ) ;
}
static int F_31 ( struct V_27 * V_27 , struct V_3 * V_4 , T_2 V_47 )
{
struct V_33 * V_34 = F_9 ( V_27 , V_35 ) ;
return F_32 ( V_34 , V_4 , V_47 ) ;
}
static T_3 int F_33 ( struct V_27 * V_27 )
{
struct V_33 * V_34 = F_9 ( V_27 , V_35 ) ;
return F_34 ( V_34 , & V_75 , V_76 ) ;
}
static void T_4 F_35 ( struct V_27 * V_27 )
{
struct V_33 * V_34 = F_9 ( V_27 , V_35 ) ;
F_36 ( V_34 ) ;
}
static int T_5 F_37 ( void )
{
return F_38 ( & V_75 , & V_77 ) ;
}
static void T_6 F_39 ( void )
{
F_40 ( & V_75 , & V_77 ) ;
}
