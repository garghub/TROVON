static char * F_1 ( struct V_1 * V_1 , char * V_2 , int V_3 )
{
return F_2 ( V_1 , V_2 , V_3 , L_1 ,
V_1 -> V_4 . V_5 ) ;
}
static int F_3 ( struct V_6 * V_6 )
{
return 0 ;
}
static struct V_7 * F_4 ( struct V_8 * V_9 )
{
struct V_7 * V_7 = F_5 ( V_9 ) ;
if ( ! V_7 )
return F_6 ( - V_10 ) ;
V_7 -> V_11 = F_7 () ;
V_7 -> V_12 = & V_13 ;
V_7 -> V_14 -> V_15 = & V_16 ;
V_7 -> V_17 = V_18 ;
V_7 -> V_19 = V_20 | V_21 ;
V_7 -> V_22 = F_8 () ;
V_7 -> V_23 = F_9 () ;
V_7 -> V_24 |= V_25 ;
V_7 -> V_26 = V_7 -> V_27 = V_7 -> V_28 = V_29 ;
return V_7 ;
}
static struct V_1 * F_10 ( struct V_30 * V_31 ,
int V_32 , const char * V_33 , void * V_34 )
{
struct V_1 * V_35 ;
V_35 = F_11 ( V_31 , L_2 , NULL ,
& V_36 , V_37 ) ;
if ( ! F_12 ( V_35 ) ) {
struct V_8 * V_9 = V_35 -> V_38 ;
V_39 = F_4 ( V_9 ) ;
if ( F_12 ( V_39 ) ) {
F_13 ( V_35 ) ;
F_14 ( V_9 ) ;
V_35 = F_15 ( V_39 ) ;
}
}
return V_35 ;
}
struct V_40 * F_16 ( const char * V_5 ,
const struct V_41 * V_42 ,
void * V_43 , int V_32 )
{
struct V_44 V_45 ;
struct V_46 V_46 ;
struct V_40 * V_40 ;
struct V_7 * V_7 ;
if ( V_42 -> V_47 && ! F_17 ( V_42 -> V_47 ) )
return F_6 ( - V_48 ) ;
V_7 = F_4 ( V_49 -> V_50 ) ;
if ( F_12 ( V_7 ) ) {
V_40 = F_6 ( - V_10 ) ;
goto V_51;
}
V_40 = F_6 ( - V_10 ) ;
V_45 . V_5 = V_5 ;
V_45 . V_52 = strlen ( V_5 ) ;
V_45 . V_53 = 0 ;
V_46 . V_1 = F_18 ( V_49 -> V_50 , & V_45 ) ;
if ( ! V_46 . V_1 )
goto V_51;
V_46 . V_54 = F_19 ( V_49 ) ;
F_20 ( V_46 . V_1 , V_7 ) ;
V_40 = F_21 ( & V_46 , F_22 ( V_32 ) , V_42 ) ;
if ( F_12 ( V_40 ) )
goto V_55;
V_40 -> V_56 = V_7 -> V_14 ;
V_40 -> V_57 = V_32 & ( V_58 | V_59 ) ;
V_40 -> V_60 = V_43 ;
return V_40 ;
V_55:
F_23 ( & V_46 ) ;
V_51:
F_24 ( V_42 -> V_47 ) ;
return V_40 ;
}
struct V_40 * F_25 ( const char * V_5 ,
const struct V_41 * V_42 ,
void * V_43 , int V_32 )
{
struct V_44 V_45 ;
struct V_46 V_46 ;
struct V_40 * V_40 ;
if ( F_12 ( V_39 ) )
return F_6 ( - V_61 ) ;
if ( V_42 -> V_47 && ! F_17 ( V_42 -> V_47 ) )
return F_6 ( - V_48 ) ;
V_40 = F_6 ( - V_10 ) ;
V_45 . V_5 = V_5 ;
V_45 . V_52 = strlen ( V_5 ) ;
V_45 . V_53 = 0 ;
V_46 . V_1 = F_18 ( V_49 -> V_50 , & V_45 ) ;
if ( ! V_46 . V_1 )
goto V_51;
V_46 . V_54 = F_19 ( V_49 ) ;
F_26 ( V_39 ) ;
F_20 ( V_46 . V_1 , V_39 ) ;
V_40 = F_21 ( & V_46 , F_22 ( V_32 ) , V_42 ) ;
if ( F_12 ( V_40 ) )
goto V_55;
V_40 -> V_56 = V_39 -> V_14 ;
V_40 -> V_57 = V_32 & ( V_58 | V_59 ) ;
V_40 -> V_60 = V_43 ;
return V_40 ;
V_55:
F_23 ( & V_46 ) ;
V_51:
F_24 ( V_42 -> V_47 ) ;
return V_40 ;
}
int F_27 ( const char * V_5 , const struct V_41 * V_42 ,
void * V_43 , int V_32 )
{
int error , V_62 ;
struct V_40 * V_40 ;
error = F_28 ( V_32 ) ;
if ( error < 0 )
return error ;
V_62 = error ;
V_40 = F_25 ( V_5 , V_42 , V_43 , V_32 ) ;
if ( F_12 ( V_40 ) ) {
error = F_29 ( V_40 ) ;
goto V_63;
}
F_30 ( V_62 , V_40 ) ;
return V_62 ;
V_63:
F_31 ( V_62 ) ;
return error ;
}
static int T_1 F_32 ( void )
{
int error ;
error = F_33 ( & V_64 ) ;
if ( error )
goto V_65;
V_49 = F_34 ( & V_64 ) ;
if ( F_12 ( V_49 ) ) {
error = F_29 ( V_49 ) ;
goto V_66;
}
return 0 ;
V_66:
F_35 ( & V_64 ) ;
V_65:
F_36 ( V_67 L_3 , error ) ;
}
