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
struct V_28 * V_33 [ V_34 + 1 ] ;
struct V_35 * V_36 ;
struct F_1 * V_7 ;
int V_9 ;
T_1 V_37 = 0 ;
T_1 V_38 = 0 ;
int V_39 = 0 ;
int V_10 ;
if ( ! V_29 )
return - V_40 ;
V_10 = F_9 ( V_33 , V_34 , V_29 , V_41 ) ;
if ( V_10 < 0 )
return V_10 ;
if ( ! V_33 [ V_42 ] )
return - V_40 ;
V_36 = F_10 ( V_33 [ V_42 ] ) ;
switch ( V_36 -> V_43 ) {
case V_18 :
break;
case V_20 :
if ( ! V_33 [ V_44 ] )
return - V_40 ;
V_37 = F_11 ( V_33 [ V_44 ] ) ;
if ( V_37 >= V_45 )
return - V_46 ;
if ( V_33 [ V_47 ] ) {
V_38 = F_12 ( V_33 [ V_47 ] ) ;
switch ( V_38 ) {
case F_13 ( V_48 ) :
case F_13 ( V_49 ) :
break;
default:
return - V_50 ;
}
} else {
V_38 = F_13 ( V_48 ) ;
}
break;
default:
return - V_40 ;
}
V_9 = V_36 -> V_43 ;
if ( ! F_14 ( V_36 -> V_51 , V_4 , V_32 ) ) {
V_39 = F_15 ( V_36 -> V_51 , V_30 , V_4 , sizeof( * V_7 ) ,
V_32 , false ) ;
if ( V_39 )
return V_39 ;
V_39 = V_52 ;
} else {
if ( V_32 )
return 0 ;
F_16 ( V_4 , V_32 ) ;
if ( ! V_31 )
return - V_53 ;
}
V_7 = F_17 ( V_4 ) ;
F_18 ( & V_7 -> V_11 ) ;
V_7 -> V_17 = V_9 ;
V_7 -> V_22 = V_37 ;
V_7 -> V_21 = V_38 ;
V_7 -> V_16 = V_36 -> V_9 ;
F_19 ( & V_7 -> V_11 ) ;
if ( V_39 == V_52 )
F_20 ( V_4 ) ;
return V_39 ;
}
static int F_21 ( struct V_1 * V_2 , struct V_3 * V_4 ,
int V_32 , int V_54 )
{
unsigned char * V_55 = F_22 ( V_2 ) ;
struct F_1 * V_7 = V_4 -> V_8 ;
struct V_35 V_56 = {
. V_51 = V_7 -> V_57 ,
. V_58 = V_7 -> V_59 - V_54 ,
. V_60 = V_7 -> V_61 - V_32 ,
. V_9 = V_7 -> V_16 ,
. V_43 = V_7 -> V_17 ,
} ;
struct V_62 V_63 ;
if ( F_23 ( V_2 , V_42 , sizeof( V_56 ) , & V_56 ) )
goto V_64;
if ( V_7 -> V_17 == V_20 &&
( F_24 ( V_2 , V_44 , V_7 -> V_22 ) ||
F_25 ( V_2 , V_47 , V_7 -> V_21 ) ) )
goto V_64;
V_63 . V_65 = F_26 ( V_14 - V_7 -> V_12 . V_65 ) ;
V_63 . V_13 = F_26 ( V_14 - V_7 -> V_12 . V_13 ) ;
V_63 . V_66 = F_26 ( V_7 -> V_12 . V_66 ) ;
if ( F_23 ( V_2 , V_67 , sizeof( V_63 ) , & V_63 ) )
goto V_64;
return V_2 -> V_68 ;
V_64:
F_27 ( V_2 , V_55 ) ;
return - 1 ;
}
static int T_2 F_28 ( void )
{
return F_29 ( & V_69 , V_70 ) ;
}
static void T_3 F_30 ( void )
{
F_31 ( & V_69 ) ;
}
