static int F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 ,
struct V_5 * V_6 )
{
const struct V_7 * V_8 ;
struct V_9 V_10 ;
enum V_11 V_12 ;
struct V_13 * V_14 = V_4 -> V_15 ;
struct V_16 V_17 ;
struct V_18 * V_19 ;
int V_20 ;
F_2 ( & V_14 -> V_21 ) ;
V_14 -> V_22 . V_23 = V_24 ;
F_3 ( & V_14 -> V_25 , V_2 ) ;
if ( V_2 -> V_26 == F_4 ( V_27 ) ) {
if ( V_2 -> V_28 < sizeof( struct V_29 ) )
goto V_30;
V_20 = V_31 ;
} else if ( V_2 -> V_26 == F_4 ( V_32 ) ) {
if ( V_2 -> V_28 < sizeof( struct V_33 ) )
goto V_30;
V_20 = V_34 ;
} else {
goto V_30;
}
V_19 = F_5 ( V_2 , & V_12 ) ;
if ( V_19 ) {
V_2 -> V_35 = V_19 -> V_35 ;
V_14 -> V_36 . V_37 ++ ;
goto V_30;
}
if ( ! F_6 ( V_2 , F_7 ( V_2 ) ,
V_20 , V_14 -> V_38 , & V_10 ) )
goto V_30;
V_17 . V_39 = V_14 -> V_17 ;
V_17 . V_40 = V_41 ;
V_8 = F_8 ( V_14 -> V_38 , & V_17 , & V_10 ) ;
if ( ! V_8 )
goto V_30;
V_19 = F_9 ( V_8 ) ;
V_14 -> V_36 . V_37 ++ ;
V_2 -> V_35 = V_19 -> V_35 ;
F_10 ( V_19 ) ;
V_30:
F_11 ( & V_14 -> V_21 ) ;
return V_14 -> V_42 ;
}
static int F_12 ( struct V_38 * V_38 , struct V_43 * V_44 ,
struct V_43 * V_45 , struct V_3 * V_4 ,
int V_46 , int V_47 )
{
struct V_48 * V_49 = F_13 ( V_38 , V_50 ) ;
struct V_43 * V_51 [ V_52 + 1 ] ;
struct V_13 * V_53 ;
struct V_54 * V_55 ;
int V_56 = 0 ;
if ( ! V_44 )
return - V_57 ;
V_56 = F_14 ( V_51 , V_52 , V_44 , V_58 ) ;
if ( V_56 < 0 )
return V_56 ;
V_55 = F_15 ( V_51 [ V_59 ] ) ;
if ( ! F_16 ( V_49 , V_55 -> V_60 , V_4 , V_47 ) ) {
V_56 = F_17 ( V_49 , V_55 -> V_60 , V_45 , V_4 ,
sizeof( * V_53 ) , V_47 , false ) ;
if ( V_56 )
return V_56 ;
V_53 = F_18 ( V_4 ) ;
V_53 -> V_42 = V_55 -> V_61 ;
V_53 -> V_38 = V_38 ;
V_53 -> V_17 = V_55 -> V_17 ;
F_19 ( V_49 , V_4 ) ;
V_56 = V_62 ;
} else {
V_53 = F_18 ( V_4 ) ;
if ( V_47 )
return 0 ;
F_20 ( V_4 , V_47 ) ;
if ( ! V_46 )
return - V_63 ;
V_53 -> V_42 = V_55 -> V_61 ;
V_53 -> V_17 = V_55 -> V_17 ;
}
return V_56 ;
}
static inline int F_21 ( struct V_1 * V_2 , struct V_3 * V_4 ,
int V_47 , int V_64 )
{
unsigned char * V_65 = F_22 ( V_2 ) ;
struct V_13 * V_53 = V_4 -> V_15 ;
struct V_54 V_66 = {
. V_60 = V_53 -> V_67 ,
. V_68 = V_53 -> V_69 - V_64 ,
. V_70 = V_53 -> V_71 - V_47 ,
. V_61 = V_53 -> V_42 ,
. V_17 = V_53 -> V_17 ,
} ;
struct V_72 V_73 ;
if ( F_23 ( V_2 , V_59 , sizeof( V_66 ) , & V_66 ) )
goto V_74;
V_73 . V_75 = F_24 ( V_24 - V_53 -> V_22 . V_75 ) ;
V_73 . V_23 = F_24 ( V_24 - V_53 -> V_22 . V_23 ) ;
V_73 . V_76 = F_24 ( V_53 -> V_22 . V_76 ) ;
if ( F_25 ( V_2 , V_77 , sizeof( V_73 ) , & V_73 ,
V_78 ) )
goto V_74;
return V_2 -> V_28 ;
V_74:
F_26 ( V_2 , V_65 ) ;
return - 1 ;
}
static int F_27 ( struct V_38 * V_38 , struct V_1 * V_2 ,
struct V_79 * V_80 , int type ,
struct V_3 * V_4 )
{
struct V_48 * V_49 = F_13 ( V_38 , V_50 ) ;
return F_28 ( V_49 , V_2 , V_80 , type , V_4 ) ;
}
static int F_29 ( struct V_38 * V_38 , struct V_3 * V_4 , T_1 V_60 )
{
struct V_48 * V_49 = F_13 ( V_38 , V_50 ) ;
return F_30 ( V_49 , V_4 , V_60 ) ;
}
static T_2 int F_31 ( struct V_38 * V_38 )
{
struct V_48 * V_49 = F_13 ( V_38 , V_50 ) ;
return F_32 ( V_49 , & V_81 , V_82 ) ;
}
static void T_3 F_33 ( struct V_38 * V_38 )
{
struct V_48 * V_49 = F_13 ( V_38 , V_50 ) ;
F_34 ( V_49 ) ;
}
static int T_4 F_35 ( void )
{
return F_36 ( & V_81 , & V_83 ) ;
}
static void T_5 F_37 ( void )
{
F_38 ( & V_81 , & V_83 ) ;
}
