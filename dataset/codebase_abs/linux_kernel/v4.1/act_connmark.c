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
goto V_28;
}
if ( ! F_6 ( V_2 , F_7 ( V_2 ) ,
V_18 , & V_10 ) )
goto V_28;
V_8 = F_8 ( F_9 ( V_2 -> V_36 ) , V_14 -> V_37 , & V_10 ) ;
if ( ! V_8 )
goto V_28;
V_17 = F_10 ( V_8 ) ;
V_14 -> V_34 . V_35 ++ ;
V_2 -> V_33 = V_17 -> V_33 ;
F_11 ( V_17 ) ;
V_28:
F_12 ( & V_14 -> V_19 ) ;
return V_14 -> V_38 ;
}
static int F_13 ( struct V_39 * V_39 , struct V_40 * V_41 ,
struct V_40 * V_42 , struct V_3 * V_4 ,
int V_43 , int V_44 )
{
struct V_40 * V_45 [ V_46 + 1 ] ;
struct V_13 * V_47 ;
struct V_48 * V_49 ;
int V_50 = 0 ;
if ( ! V_41 )
return - V_51 ;
V_50 = F_14 ( V_45 , V_46 , V_41 , V_52 ) ;
if ( V_50 < 0 )
return V_50 ;
V_49 = F_15 ( V_45 [ V_53 ] ) ;
if ( ! F_16 ( V_49 -> V_54 , V_4 , V_44 ) ) {
V_50 = F_17 ( V_49 -> V_54 , V_42 , V_4 , sizeof( * V_47 ) , V_44 ) ;
if ( V_50 )
return V_50 ;
V_47 = F_18 ( V_4 ) ;
V_47 -> V_38 = V_49 -> V_55 ;
V_47 -> V_37 = V_49 -> V_37 ;
F_19 ( V_4 ) ;
V_50 = V_56 ;
} else {
V_47 = F_18 ( V_4 ) ;
if ( V_44 )
return 0 ;
F_20 ( V_4 , V_44 ) ;
if ( ! V_43 )
return - V_57 ;
V_47 -> V_38 = V_49 -> V_55 ;
V_47 -> V_37 = V_49 -> V_37 ;
}
return V_50 ;
}
static inline int F_21 ( struct V_1 * V_2 , struct V_3 * V_4 ,
int V_44 , int V_58 )
{
unsigned char * V_59 = F_22 ( V_2 ) ;
struct V_13 * V_47 = V_4 -> V_15 ;
struct V_48 V_60 = {
. V_54 = V_47 -> V_61 ,
. V_62 = V_47 -> V_63 - V_58 ,
. V_64 = V_47 -> V_65 - V_44 ,
. V_55 = V_47 -> V_38 ,
. V_37 = V_47 -> V_37 ,
} ;
struct V_66 V_67 ;
if ( F_23 ( V_2 , V_53 , sizeof( V_60 ) , & V_60 ) )
goto V_68;
V_67 . V_69 = F_24 ( V_22 - V_47 -> V_20 . V_69 ) ;
V_67 . V_21 = F_24 ( V_22 - V_47 -> V_20 . V_21 ) ;
V_67 . V_70 = F_24 ( V_47 -> V_20 . V_70 ) ;
if ( F_23 ( V_2 , V_71 , sizeof( V_67 ) , & V_67 ) )
goto V_68;
return V_2 -> V_26 ;
V_68:
F_25 ( V_2 , V_59 ) ;
return - 1 ;
}
static int T_1 F_26 ( void )
{
return F_27 ( & V_72 , V_73 ) ;
}
static void T_2 F_28 ( void )
{
F_29 ( & V_72 ) ;
}
