static int F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 ,
struct V_5 * V_6 )
{
const struct V_7 * V_8 ;
struct V_9 V_10 ;
enum V_11 V_12 ;
struct V_13 * V_14 = V_4 -> V_15 ;
struct V_16 * V_17 ;
int V_18 ;
F_2 ( & V_14 -> V_19 ) ;
V_14 -> V_20 . V_21 = V_22 ;
F_3 ( & V_14 -> V_23 , V_2 ) ;
if ( V_2 -> V_24 == F_4 ( V_25 ) ) {
if ( V_2 -> V_26 < sizeof( struct V_27 ) )
goto V_28;
V_18 = V_29 ;
} else if ( V_2 -> V_24 == F_4 ( V_30 ) ) {
if ( V_2 -> V_26 < sizeof( struct V_31 ) )
goto V_28;
V_18 = V_32 ;
} else {
goto V_28;
}
V_17 = F_5 ( V_2 , & V_12 ) ;
if ( V_17 ) {
V_2 -> V_33 = V_17 -> V_33 ;
V_14 -> V_34 . V_35 ++ ;
F_6 ( V_17 ) ;
goto V_28;
}
if ( ! F_7 ( V_2 , F_8 ( V_2 ) ,
V_18 , & V_10 ) )
goto V_28;
V_8 = F_9 ( F_10 ( V_2 -> V_36 ) , V_14 -> V_37 , & V_10 ) ;
if ( ! V_8 )
goto V_28;
V_17 = F_11 ( V_8 ) ;
V_14 -> V_34 . V_35 ++ ;
V_2 -> V_33 = V_17 -> V_33 ;
F_6 ( V_17 ) ;
V_28:
V_2 -> V_38 = NULL ;
F_12 ( & V_14 -> V_19 ) ;
return V_14 -> V_39 ;
}
static int F_13 ( struct V_40 * V_40 , struct V_41 * V_42 ,
struct V_41 * V_43 , struct V_3 * V_4 ,
int V_44 , int V_45 )
{
struct V_41 * V_46 [ V_47 + 1 ] ;
struct V_13 * V_48 ;
struct V_49 * V_50 ;
int V_51 = 0 ;
if ( ! V_42 )
return - V_52 ;
V_51 = F_14 ( V_46 , V_47 , V_42 , V_53 ) ;
if ( V_51 < 0 )
return V_51 ;
V_50 = F_15 ( V_46 [ V_54 ] ) ;
if ( ! F_16 ( V_50 -> V_55 , V_4 , V_45 ) ) {
V_51 = F_17 ( V_50 -> V_55 , V_43 , V_4 , sizeof( * V_48 ) , V_45 ) ;
if ( V_51 )
return V_51 ;
V_48 = F_18 ( V_4 ) ;
V_48 -> V_39 = V_50 -> V_56 ;
V_48 -> V_37 = V_50 -> V_37 ;
F_19 ( V_4 ) ;
V_51 = V_57 ;
} else {
V_48 = F_18 ( V_4 ) ;
if ( V_45 )
return 0 ;
F_20 ( V_4 , V_45 ) ;
if ( ! V_44 )
return - V_58 ;
V_48 -> V_39 = V_50 -> V_56 ;
V_48 -> V_37 = V_50 -> V_37 ;
}
return V_51 ;
}
static inline int F_21 ( struct V_1 * V_2 , struct V_3 * V_4 ,
int V_45 , int V_59 )
{
unsigned char * V_60 = F_22 ( V_2 ) ;
struct V_13 * V_48 = V_4 -> V_15 ;
struct V_49 V_61 = {
. V_55 = V_48 -> V_62 ,
. V_63 = V_48 -> V_64 - V_59 ,
. V_65 = V_48 -> V_66 - V_45 ,
. V_56 = V_48 -> V_39 ,
. V_37 = V_48 -> V_37 ,
} ;
struct V_67 V_68 ;
if ( F_23 ( V_2 , V_54 , sizeof( V_61 ) , & V_61 ) )
goto V_69;
V_68 . V_70 = F_24 ( V_22 - V_48 -> V_20 . V_70 ) ;
V_68 . V_21 = F_24 ( V_22 - V_48 -> V_20 . V_21 ) ;
V_68 . V_71 = F_24 ( V_48 -> V_20 . V_71 ) ;
if ( F_23 ( V_2 , V_72 , sizeof( V_68 ) , & V_68 ) )
goto V_69;
return V_2 -> V_26 ;
V_69:
F_25 ( V_2 , V_60 ) ;
return - 1 ;
}
static int T_1 F_26 ( void )
{
return F_27 ( & V_73 , V_74 ) ;
}
static void T_2 F_28 ( void )
{
F_29 ( & V_73 ) ;
}
