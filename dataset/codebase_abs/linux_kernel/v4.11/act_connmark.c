static int F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 ,
struct V_5 * V_6 )
{
const struct V_7 * V_8 ;
struct V_9 V_10 ;
enum V_11 V_12 ;
struct V_13 * V_14 = F_2 ( V_4 ) ;
struct V_15 V_16 ;
struct V_17 * V_18 ;
int V_19 ;
F_3 ( & V_14 -> V_20 ) ;
F_4 ( & V_14 -> V_21 ) ;
F_5 ( & V_14 -> V_22 , V_2 ) ;
if ( V_2 -> V_23 == F_6 ( V_24 ) ) {
if ( V_2 -> V_25 < sizeof( struct V_26 ) )
goto V_27;
V_19 = V_28 ;
} else if ( V_2 -> V_23 == F_6 ( V_29 ) ) {
if ( V_2 -> V_25 < sizeof( struct V_30 ) )
goto V_27;
V_19 = V_31 ;
} else {
goto V_27;
}
V_18 = F_7 ( V_2 , & V_12 ) ;
if ( V_18 ) {
V_2 -> V_32 = V_18 -> V_32 ;
V_14 -> V_33 . V_34 ++ ;
goto V_27;
}
if ( ! F_8 ( V_2 , F_9 ( V_2 ) ,
V_19 , V_14 -> V_35 , & V_10 ) )
goto V_27;
V_16 . V_36 = V_14 -> V_16 ;
V_16 . V_37 = V_38 ;
V_8 = F_10 ( V_14 -> V_35 , & V_16 , & V_10 ) ;
if ( ! V_8 )
goto V_27;
V_18 = F_11 ( V_8 ) ;
V_14 -> V_33 . V_34 ++ ;
V_2 -> V_32 = V_18 -> V_32 ;
F_12 ( V_18 ) ;
V_27:
F_13 ( & V_14 -> V_20 ) ;
return V_14 -> V_39 ;
}
static int F_14 ( struct V_35 * V_35 , struct V_40 * V_41 ,
struct V_40 * V_42 , struct V_3 * * V_4 ,
int V_43 , int V_44 )
{
struct V_45 * V_46 = F_15 ( V_35 , V_47 ) ;
struct V_40 * V_48 [ V_49 + 1 ] ;
struct V_13 * V_50 ;
struct V_51 * V_52 ;
int V_53 = 0 ;
if ( ! V_41 )
return - V_54 ;
V_53 = F_16 ( V_48 , V_49 , V_41 , V_55 ) ;
if ( V_53 < 0 )
return V_53 ;
if ( ! V_48 [ V_56 ] )
return - V_54 ;
V_52 = F_17 ( V_48 [ V_56 ] ) ;
if ( ! F_18 ( V_46 , V_52 -> V_57 , V_4 , V_44 ) ) {
V_53 = F_19 ( V_46 , V_52 -> V_57 , V_42 , V_4 ,
& V_58 , V_44 , false ) ;
if ( V_53 )
return V_53 ;
V_50 = F_2 ( * V_4 ) ;
V_50 -> V_39 = V_52 -> V_59 ;
V_50 -> V_35 = V_35 ;
V_50 -> V_16 = V_52 -> V_16 ;
F_20 ( V_46 , * V_4 ) ;
V_53 = V_60 ;
} else {
V_50 = F_2 ( * V_4 ) ;
if ( V_44 )
return 0 ;
F_21 ( * V_4 , V_44 ) ;
if ( ! V_43 )
return - V_61 ;
V_50 -> V_39 = V_52 -> V_59 ;
V_50 -> V_16 = V_52 -> V_16 ;
}
return V_53 ;
}
static inline int F_22 ( struct V_1 * V_2 , struct V_3 * V_4 ,
int V_44 , int V_62 )
{
unsigned char * V_63 = F_23 ( V_2 ) ;
struct V_13 * V_50 = F_2 ( V_4 ) ;
struct V_51 V_64 = {
. V_57 = V_50 -> V_65 ,
. V_66 = V_50 -> V_67 - V_62 ,
. V_68 = V_50 -> V_69 - V_44 ,
. V_59 = V_50 -> V_39 ,
. V_16 = V_50 -> V_16 ,
} ;
struct V_70 V_71 ;
if ( F_24 ( V_2 , V_56 , sizeof( V_64 ) , & V_64 ) )
goto V_72;
F_25 ( & V_71 , & V_50 -> V_21 ) ;
if ( F_26 ( V_2 , V_73 , sizeof( V_71 ) , & V_71 ,
V_74 ) )
goto V_72;
return V_2 -> V_25 ;
V_72:
F_27 ( V_2 , V_63 ) ;
return - 1 ;
}
static int F_28 ( struct V_35 * V_35 , struct V_1 * V_2 ,
struct V_75 * V_76 , int type ,
const struct V_77 * V_78 )
{
struct V_45 * V_46 = F_15 ( V_35 , V_47 ) ;
return F_29 ( V_46 , V_2 , V_76 , type , V_78 ) ;
}
static int F_30 ( struct V_35 * V_35 , struct V_3 * * V_4 , T_1 V_57 )
{
struct V_45 * V_46 = F_15 ( V_35 , V_47 ) ;
return F_31 ( V_46 , V_4 , V_57 ) ;
}
static T_2 int F_32 ( struct V_35 * V_35 )
{
struct V_45 * V_46 = F_15 ( V_35 , V_47 ) ;
return F_33 ( V_46 , & V_58 , V_79 ) ;
}
static void T_3 F_34 ( struct V_35 * V_35 )
{
struct V_45 * V_46 = F_15 ( V_35 , V_47 ) ;
F_35 ( V_46 ) ;
}
static int T_4 F_36 ( void )
{
return F_37 ( & V_58 , & V_80 ) ;
}
static void T_5 F_38 ( void )
{
F_39 ( & V_58 , & V_80 ) ;
}
