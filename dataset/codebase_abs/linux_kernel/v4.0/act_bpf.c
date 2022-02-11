static int F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct F_1 * V_7 = V_4 -> V_8 ;
int V_9 , V_10 ;
F_2 ( & V_7 -> V_11 ) ;
V_7 -> V_12 . V_13 = V_14 ;
F_3 ( & V_7 -> V_15 , V_2 ) ;
V_10 = F_4 ( V_7 -> V_16 , V_2 ) ;
switch ( V_10 ) {
case V_17 :
case V_18 :
case V_19 :
V_9 = V_10 ;
break;
case V_20 :
V_9 = V_10 ;
V_7 -> V_21 . V_22 ++ ;
break;
case V_23 :
V_9 = V_7 -> V_24 ;
break;
default:
V_9 = V_23 ;
break;
}
F_5 ( & V_7 -> V_11 ) ;
return V_9 ;
}
static int F_6 ( struct V_1 * V_2 , struct V_3 * V_4 ,
int V_25 , int V_26 )
{
unsigned char * V_27 = F_7 ( V_2 ) ;
struct F_1 * V_7 = V_4 -> V_8 ;
struct V_28 V_29 = {
. V_30 = V_7 -> V_31 ,
. V_32 = V_7 -> V_33 - V_26 ,
. V_34 = V_7 -> V_35 - V_25 ,
. V_9 = V_7 -> V_24 ,
} ;
struct V_36 V_37 ;
struct V_38 * V_39 ;
if ( F_8 ( V_2 , V_40 , sizeof( V_29 ) , & V_29 ) )
goto V_41;
if ( F_9 ( V_2 , V_42 , V_7 -> V_43 ) )
goto V_41;
V_39 = F_10 ( V_2 , V_44 , V_7 -> V_43 *
sizeof( struct V_45 ) ) ;
if ( ! V_39 )
goto V_41;
memcpy ( F_11 ( V_39 ) , V_7 -> V_46 , F_12 ( V_39 ) ) ;
V_37 . V_47 = F_13 ( V_14 - V_7 -> V_12 . V_47 ) ;
V_37 . V_13 = F_13 ( V_14 - V_7 -> V_12 . V_13 ) ;
V_37 . V_48 = F_13 ( V_7 -> V_12 . V_48 ) ;
if ( F_8 ( V_2 , V_49 , sizeof( V_37 ) , & V_37 ) )
goto V_41;
return V_2 -> V_50 ;
V_41:
F_14 ( V_2 , V_27 ) ;
return - 1 ;
}
static int F_15 ( struct V_51 * V_51 , struct V_38 * V_39 ,
struct V_38 * V_52 , struct V_3 * V_4 ,
int V_53 , int V_25 )
{
struct V_38 * V_54 [ V_55 + 1 ] ;
struct V_28 * V_56 ;
struct F_1 * V_7 ;
T_1 V_57 , V_43 ;
struct V_45 * V_46 ;
struct V_58 V_59 ;
struct V_60 * V_61 ;
int V_62 ;
if ( ! V_39 )
return - V_63 ;
V_62 = F_16 ( V_54 , V_55 , V_39 , V_64 ) ;
if ( V_62 < 0 )
return V_62 ;
if ( ! V_54 [ V_40 ] ||
! V_54 [ V_42 ] || ! V_54 [ V_44 ] )
return - V_63 ;
V_56 = F_11 ( V_54 [ V_40 ] ) ;
V_43 = F_17 ( V_54 [ V_42 ] ) ;
if ( V_43 > V_65 || V_43 == 0 )
return - V_63 ;
V_57 = V_43 * sizeof( * V_46 ) ;
if ( V_57 != F_12 ( V_54 [ V_44 ] ) )
return - V_63 ;
V_46 = F_18 ( V_57 , V_66 ) ;
if ( ! V_46 )
return - V_67 ;
memcpy ( V_46 , F_11 ( V_54 [ V_44 ] ) , V_57 ) ;
V_59 . V_50 = V_43 ;
V_59 . V_16 = V_46 ;
V_62 = F_19 ( & V_61 , & V_59 ) ;
if ( V_62 )
goto V_68;
if ( ! F_20 ( V_56 -> V_30 , V_4 , V_25 ) ) {
V_62 = F_21 ( V_56 -> V_30 , V_52 , V_4 , sizeof( * V_7 ) , V_25 ) ;
if ( V_62 )
goto V_69;
V_62 = V_70 ;
} else {
if ( V_25 )
goto V_69;
F_22 ( V_4 , V_25 ) ;
if ( ! V_53 ) {
V_62 = - V_71 ;
goto V_69;
}
}
V_7 = F_23 ( V_4 ) ;
F_24 ( & V_7 -> V_11 ) ;
V_7 -> V_24 = V_56 -> V_9 ;
V_7 -> V_43 = V_43 ;
V_7 -> V_46 = V_46 ;
V_7 -> V_16 = V_61 ;
F_25 ( & V_7 -> V_11 ) ;
if ( V_62 == V_70 )
F_26 ( V_4 ) ;
return V_62 ;
V_69:
F_27 ( V_61 ) ;
V_68:
F_28 ( V_46 ) ;
return V_62 ;
}
static void F_29 ( struct V_3 * V_4 , int V_25 )
{
struct F_1 * V_7 = V_4 -> V_8 ;
F_27 ( V_7 -> V_16 ) ;
}
static int T_2 F_30 ( void )
{
return F_31 ( & V_72 , V_73 ) ;
}
static void T_3 F_32 ( void )
{
F_33 ( & V_72 ) ;
}
