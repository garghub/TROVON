static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
enum V_5 V_6 = F_3 ( V_2 ) ;
T_1 V_7 , V_8 = V_9 + V_6 ;
if ( F_4 ( V_4 -> V_10 , V_8 , & V_7 ) )
return - V_11 ;
V_7 = ( V_7 & V_12 ) >> V_13 ;
return V_14 * V_7 ;
}
static int F_5 ( struct V_15 * V_16 ,
struct V_3 * V_4 ,
enum V_5 V_6 )
{
struct V_17 * V_10 = V_4 -> V_10 ;
struct V_18 * V_19 = V_10 -> V_19 ;
enum V_20 V_21 ;
T_1 V_22 [] = {
[ V_23 ] = V_24 ,
[ V_25 ] = V_26 ,
[ V_27 ] = V_28 ,
[ V_29 ] = V_30 ,
[ V_31 ] = V_32 ,
[ V_33 ] = V_34 ,
} ;
switch ( V_6 ) {
case V_35 :
V_21 = V_31 ;
break;
case V_36 :
case V_37 :
V_21 = V_33 ;
break;
case V_38 :
V_21 = V_23 ;
break;
case V_39 ... V_40 :
V_21 = V_25 ;
break;
case V_41 :
V_21 = V_27 ;
break;
case V_42 :
V_21 = V_29 ;
break;
default:
return 0 ;
}
if ( ! V_19 || ! V_19 -> V_43 || ! V_19 -> V_43 [ V_21 ] )
goto V_44;
V_4 -> V_45 = V_19 -> V_43 [ V_21 ] ;
return 0 ;
V_44:
return F_6 ( V_10 , V_46 , V_22 [ V_21 ] , 0 ) ;
}
static int F_7 ( struct V_15 * V_16 )
{
struct V_17 * V_10 = F_8 ( V_16 -> V_47 . V_48 ) ;
int V_6 = V_16 -> V_6 ;
struct V_3 * V_4 ;
struct V_49 V_50 = { } ;
struct V_1 * V_2 ;
int V_51 ;
V_4 = F_9 ( & V_16 -> V_47 , sizeof( struct V_3 ) , V_52 ) ;
if ( ! V_4 )
return - V_53 ;
V_4 -> V_10 = V_10 ;
V_51 = F_5 ( V_16 , V_4 , V_6 ) ;
if ( V_51 )
return V_51 ;
if ( V_4 -> V_45 ) {
V_50 . V_54 = V_4 -> V_45 -> V_55 ;
V_50 . V_56 = V_4 -> V_45 -> V_57 ;
}
V_50 . V_47 = V_16 -> V_47 . V_48 ;
V_50 . V_58 = V_10 -> V_19 ? V_10 -> V_19 -> V_59 [ V_6 ] : NULL ;
V_50 . V_60 = V_4 ;
V_50 . V_61 = V_10 -> V_61 ;
V_2 = F_10 ( & V_16 -> V_47 , & V_62 [ V_6 ] , & V_50 ) ;
if ( F_11 ( V_2 ) ) {
V_51 = F_12 ( V_2 ) ;
F_13 ( & V_16 -> V_47 , L_1 ,
V_6 + 1 , V_51 ) ;
return V_51 ;
}
V_4 -> V_63 = V_2 ;
F_14 ( V_16 , V_4 ) ;
return 0 ;
}
static int F_15 ( struct V_15 * V_16 )
{
struct V_17 * V_10 = F_8 ( V_16 -> V_47 . V_48 ) ;
int V_6 = V_16 -> V_6 ;
struct V_3 * V_4 ;
struct V_49 V_50 = { } ;
struct V_1 * V_2 ;
int V_51 ;
V_4 = F_9 ( & V_16 -> V_47 , sizeof( struct V_3 ) , V_52 ) ;
if ( ! V_4 )
return - V_53 ;
V_4 -> V_10 = V_10 ;
V_51 = F_5 ( V_16 , V_4 , V_6 + V_38 ) ;
if ( V_51 )
return V_51 ;
if ( V_4 -> V_45 ) {
V_50 . V_54 = V_4 -> V_45 -> V_55 ;
V_50 . V_56 = V_4 -> V_45 -> V_57 ;
}
V_50 . V_47 = V_16 -> V_47 . V_48 ;
V_50 . V_58 = V_10 -> V_19 ? V_10 -> V_19 -> V_64 [ V_6 ] : NULL ;
V_50 . V_60 = V_4 ;
V_50 . V_61 = V_10 -> V_61 ;
V_2 = F_10 ( & V_16 -> V_47 , & V_65 [ V_6 ] , & V_50 ) ;
if ( F_11 ( V_2 ) ) {
V_51 = F_12 ( V_2 ) ;
F_13 ( & V_16 -> V_47 , L_2 ,
V_6 + 1 , V_51 ) ;
return V_51 ;
}
V_4 -> V_63 = V_2 ;
F_14 ( V_16 , V_4 ) ;
return 0 ;
}
static int T_2 F_16 ( void )
{
return F_17 ( V_66 , F_18 ( V_66 ) ) ;
}
static void T_3 F_19 ( void )
{
F_20 ( V_66 , F_18 ( V_66 ) ) ;
}
