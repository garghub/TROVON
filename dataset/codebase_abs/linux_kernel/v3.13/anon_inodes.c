static char * F_1 ( struct V_1 * V_1 , char * V_2 , int V_3 )
{
return F_2 ( V_1 , V_2 , V_3 , L_1 ,
V_1 -> V_4 . V_5 ) ;
}
static struct V_1 * F_3 ( struct V_6 * V_7 ,
int V_8 , const char * V_9 , void * V_10 )
{
struct V_1 * V_11 ;
V_11 = F_4 ( V_7 , L_2 , NULL ,
& V_12 , V_13 ) ;
if ( ! F_5 ( V_11 ) ) {
struct V_14 * V_15 = V_11 -> V_16 ;
V_17 = F_6 ( V_15 ) ;
if ( F_5 ( V_17 ) ) {
F_7 ( V_11 ) ;
F_8 ( V_15 ) ;
V_11 = F_9 ( V_17 ) ;
}
}
return V_11 ;
}
struct V_18 * F_10 ( const char * V_5 ,
const struct V_19 * V_20 ,
void * V_21 , int V_8 )
{
struct V_22 V_23 ;
struct V_24 V_24 ;
struct V_18 * V_18 ;
if ( F_5 ( V_17 ) )
return F_11 ( - V_25 ) ;
if ( V_20 -> V_26 && ! F_12 ( V_20 -> V_26 ) )
return F_11 ( - V_27 ) ;
V_18 = F_11 ( - V_28 ) ;
V_23 . V_5 = V_5 ;
V_23 . V_29 = strlen ( V_5 ) ;
V_23 . V_30 = 0 ;
V_24 . V_1 = F_13 ( V_31 -> V_32 , & V_23 ) ;
if ( ! V_24 . V_1 )
goto V_33;
V_24 . V_34 = F_14 ( V_31 ) ;
F_15 ( V_17 ) ;
F_16 ( V_24 . V_1 , V_17 ) ;
V_18 = F_17 ( & V_24 , F_18 ( V_8 ) , V_20 ) ;
if ( F_5 ( V_18 ) )
goto V_35;
V_18 -> V_36 = V_17 -> V_37 ;
V_18 -> V_38 = V_8 & ( V_39 | V_40 ) ;
V_18 -> V_41 = V_21 ;
return V_18 ;
V_35:
F_19 ( & V_24 ) ;
V_33:
F_20 ( V_20 -> V_26 ) ;
return V_18 ;
}
int F_21 ( const char * V_5 , const struct V_19 * V_20 ,
void * V_21 , int V_8 )
{
int error , V_42 ;
struct V_18 * V_18 ;
error = F_22 ( V_8 ) ;
if ( error < 0 )
return error ;
V_42 = error ;
V_18 = F_10 ( V_5 , V_20 , V_21 , V_8 ) ;
if ( F_5 ( V_18 ) ) {
error = F_23 ( V_18 ) ;
goto V_43;
}
F_24 ( V_42 , V_18 ) ;
return V_42 ;
V_43:
F_25 ( V_42 ) ;
return error ;
}
static int T_1 F_26 ( void )
{
int error ;
error = F_27 ( & V_44 ) ;
if ( error )
goto V_45;
V_31 = F_28 ( & V_44 ) ;
if ( F_5 ( V_31 ) ) {
error = F_23 ( V_31 ) ;
goto V_46;
}
return 0 ;
V_46:
F_29 ( & V_44 ) ;
V_45:
F_30 ( V_47 L_3 , error ) ;
}
