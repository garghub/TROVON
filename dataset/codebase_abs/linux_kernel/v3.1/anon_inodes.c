static char * F_1 ( struct V_1 * V_1 , char * V_2 , int V_3 )
{
return F_2 ( V_1 , V_2 , V_3 , L_1 ,
V_1 -> V_4 . V_5 ) ;
}
static struct V_1 * F_3 ( struct V_6 * V_7 ,
int V_8 , const char * V_9 , void * V_10 )
{
return F_4 ( V_7 , L_2 , NULL ,
& V_11 , V_12 ) ;
}
static int F_5 ( struct V_13 * V_13 )
{
return 0 ;
}
struct V_14 * F_6 ( const char * V_5 ,
const struct V_15 * V_16 ,
void * V_17 , int V_8 )
{
struct V_18 V_19 ;
struct V_20 V_20 ;
struct V_14 * V_14 ;
int error ;
if ( F_7 ( V_21 ) )
return F_8 ( - V_22 ) ;
if ( V_16 -> V_23 && ! F_9 ( V_16 -> V_23 ) )
return F_8 ( - V_24 ) ;
error = - V_25 ;
V_19 . V_5 = V_5 ;
V_19 . V_26 = strlen ( V_5 ) ;
V_19 . V_27 = 0 ;
V_20 . V_1 = F_10 ( V_28 -> V_29 , & V_19 ) ;
if ( ! V_20 . V_1 )
goto V_30;
V_20 . V_31 = F_11 ( V_28 ) ;
F_12 ( V_21 ) ;
F_13 ( V_20 . V_1 , V_21 ) ;
error = - V_32 ;
V_14 = F_14 ( & V_20 , F_15 ( V_8 ) , V_16 ) ;
if ( ! V_14 )
goto V_33;
V_14 -> V_34 = V_21 -> V_35 ;
V_14 -> V_36 = 0 ;
V_14 -> V_37 = V_8 & ( V_38 | V_39 ) ;
V_14 -> V_40 = 0 ;
V_14 -> V_41 = V_17 ;
return V_14 ;
V_33:
F_16 ( & V_20 ) ;
V_30:
F_17 ( V_16 -> V_23 ) ;
return F_8 ( error ) ;
}
int F_18 ( const char * V_5 , const struct V_15 * V_16 ,
void * V_17 , int V_8 )
{
int error , V_42 ;
struct V_14 * V_14 ;
error = F_19 ( V_8 ) ;
if ( error < 0 )
return error ;
V_42 = error ;
V_14 = F_6 ( V_5 , V_16 , V_17 , V_8 ) ;
if ( F_7 ( V_14 ) ) {
error = F_20 ( V_14 ) ;
goto V_43;
}
F_21 ( V_42 , V_14 ) ;
return V_42 ;
V_43:
F_22 ( V_42 ) ;
return error ;
}
static struct V_44 * F_23 ( void )
{
struct V_44 * V_44 = F_24 ( V_28 -> V_29 ) ;
if ( ! V_44 )
return F_8 ( - V_25 ) ;
V_44 -> V_45 = F_25 () ;
V_44 -> V_46 = & V_47 ;
V_44 -> V_35 -> V_48 = & V_49 ;
V_44 -> V_50 = V_51 ;
V_44 -> V_52 = V_53 | V_54 ;
V_44 -> V_55 = F_26 () ;
V_44 -> V_56 = F_27 () ;
V_44 -> V_57 |= V_58 ;
V_44 -> V_59 = V_44 -> V_60 = V_44 -> V_61 = V_62 ;
return V_44 ;
}
static int T_1 F_28 ( void )
{
int error ;
error = F_29 ( & V_63 ) ;
if ( error )
goto V_64;
V_28 = F_30 ( & V_63 ) ;
if ( F_7 ( V_28 ) ) {
error = F_20 ( V_28 ) ;
goto V_65;
}
V_21 = F_23 () ;
if ( F_7 ( V_21 ) ) {
error = F_20 ( V_21 ) ;
goto V_66;
}
return 0 ;
V_66:
F_31 ( V_28 ) ;
V_65:
F_32 ( & V_63 ) ;
V_64:
F_33 ( V_67 L_3 , error ) ;
}
