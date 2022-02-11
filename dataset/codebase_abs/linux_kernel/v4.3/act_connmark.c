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
V_20 , & V_10 ) )
goto V_30;
V_17 . V_38 = V_14 -> V_17 ;
V_17 . V_39 = V_40 ;
V_8 = F_8 ( F_9 ( V_2 -> V_41 ) , & V_17 , & V_10 ) ;
if ( ! V_8 )
goto V_30;
V_19 = F_10 ( V_8 ) ;
V_14 -> V_36 . V_37 ++ ;
V_2 -> V_35 = V_19 -> V_35 ;
F_11 ( V_19 ) ;
V_30:
F_12 ( & V_14 -> V_21 ) ;
return V_14 -> V_42 ;
}
static int F_13 ( struct V_43 * V_43 , struct V_44 * V_45 ,
struct V_44 * V_46 , struct V_3 * V_4 ,
int V_47 , int V_48 )
{
struct V_44 * V_49 [ V_50 + 1 ] ;
struct V_13 * V_51 ;
struct V_52 * V_53 ;
int V_54 = 0 ;
if ( ! V_45 )
return - V_55 ;
V_54 = F_14 ( V_49 , V_50 , V_45 , V_56 ) ;
if ( V_54 < 0 )
return V_54 ;
V_53 = F_15 ( V_49 [ V_57 ] ) ;
if ( ! F_16 ( V_53 -> V_58 , V_4 , V_48 ) ) {
V_54 = F_17 ( V_53 -> V_58 , V_46 , V_4 , sizeof( * V_51 ) ,
V_48 , false ) ;
if ( V_54 )
return V_54 ;
V_51 = F_18 ( V_4 ) ;
V_51 -> V_42 = V_53 -> V_59 ;
V_51 -> V_17 = V_53 -> V_17 ;
F_19 ( V_4 ) ;
V_54 = V_60 ;
} else {
V_51 = F_18 ( V_4 ) ;
if ( V_48 )
return 0 ;
F_20 ( V_4 , V_48 ) ;
if ( ! V_47 )
return - V_61 ;
V_51 -> V_42 = V_53 -> V_59 ;
V_51 -> V_17 = V_53 -> V_17 ;
}
return V_54 ;
}
static inline int F_21 ( struct V_1 * V_2 , struct V_3 * V_4 ,
int V_48 , int V_62 )
{
unsigned char * V_63 = F_22 ( V_2 ) ;
struct V_13 * V_51 = V_4 -> V_15 ;
struct V_52 V_64 = {
. V_58 = V_51 -> V_65 ,
. V_66 = V_51 -> V_67 - V_62 ,
. V_68 = V_51 -> V_69 - V_48 ,
. V_59 = V_51 -> V_42 ,
. V_17 = V_51 -> V_17 ,
} ;
struct V_70 V_71 ;
if ( F_23 ( V_2 , V_57 , sizeof( V_64 ) , & V_64 ) )
goto V_72;
V_71 . V_73 = F_24 ( V_24 - V_51 -> V_22 . V_73 ) ;
V_71 . V_23 = F_24 ( V_24 - V_51 -> V_22 . V_23 ) ;
V_71 . V_74 = F_24 ( V_51 -> V_22 . V_74 ) ;
if ( F_23 ( V_2 , V_75 , sizeof( V_71 ) , & V_71 ) )
goto V_72;
return V_2 -> V_28 ;
V_72:
F_25 ( V_2 , V_63 ) ;
return - 1 ;
}
static int T_1 F_26 ( void )
{
return F_27 ( & V_76 , V_77 ) ;
}
static void T_2 F_28 ( void )
{
F_29 ( & V_76 ) ;
}
