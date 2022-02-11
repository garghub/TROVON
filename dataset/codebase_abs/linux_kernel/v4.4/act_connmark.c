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
struct V_43 * V_48 [ V_49 + 1 ] ;
struct V_13 * V_50 ;
struct V_51 * V_52 ;
int V_53 = 0 ;
if ( ! V_44 )
return - V_54 ;
V_53 = F_13 ( V_48 , V_49 , V_44 , V_55 ) ;
if ( V_53 < 0 )
return V_53 ;
V_52 = F_14 ( V_48 [ V_56 ] ) ;
if ( ! F_15 ( V_52 -> V_57 , V_4 , V_47 ) ) {
V_53 = F_16 ( V_52 -> V_57 , V_45 , V_4 , sizeof( * V_50 ) ,
V_47 , false ) ;
if ( V_53 )
return V_53 ;
V_50 = F_17 ( V_4 ) ;
V_50 -> V_42 = V_52 -> V_58 ;
V_50 -> V_38 = V_38 ;
V_50 -> V_17 = V_52 -> V_17 ;
F_18 ( V_4 ) ;
V_53 = V_59 ;
} else {
V_50 = F_17 ( V_4 ) ;
if ( V_47 )
return 0 ;
F_19 ( V_4 , V_47 ) ;
if ( ! V_46 )
return - V_60 ;
V_50 -> V_42 = V_52 -> V_58 ;
V_50 -> V_17 = V_52 -> V_17 ;
}
return V_53 ;
}
static inline int F_20 ( struct V_1 * V_2 , struct V_3 * V_4 ,
int V_47 , int V_61 )
{
unsigned char * V_62 = F_21 ( V_2 ) ;
struct V_13 * V_50 = V_4 -> V_15 ;
struct V_51 V_63 = {
. V_57 = V_50 -> V_64 ,
. V_65 = V_50 -> V_66 - V_61 ,
. V_67 = V_50 -> V_68 - V_47 ,
. V_58 = V_50 -> V_42 ,
. V_17 = V_50 -> V_17 ,
} ;
struct V_69 V_70 ;
if ( F_22 ( V_2 , V_56 , sizeof( V_63 ) , & V_63 ) )
goto V_71;
V_70 . V_72 = F_23 ( V_24 - V_50 -> V_22 . V_72 ) ;
V_70 . V_23 = F_23 ( V_24 - V_50 -> V_22 . V_23 ) ;
V_70 . V_73 = F_23 ( V_50 -> V_22 . V_73 ) ;
if ( F_22 ( V_2 , V_74 , sizeof( V_70 ) , & V_70 ) )
goto V_71;
return V_2 -> V_28 ;
V_71:
F_24 ( V_2 , V_62 ) ;
return - 1 ;
}
static int T_1 F_25 ( void )
{
return F_26 ( & V_75 , V_76 ) ;
}
static void T_2 F_27 ( void )
{
F_28 ( & V_75 ) ;
}
