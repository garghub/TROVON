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
struct V_13 * F_5 ( const char * V_5 ,
const struct V_14 * V_15 ,
void * V_16 , int V_8 )
{
struct V_17 V_18 ;
struct V_19 V_19 ;
struct V_13 * V_13 ;
if ( F_6 ( V_20 ) )
return F_7 ( - V_21 ) ;
if ( V_15 -> V_22 && ! F_8 ( V_15 -> V_22 ) )
return F_7 ( - V_23 ) ;
V_13 = F_7 ( - V_24 ) ;
V_18 . V_5 = V_5 ;
V_18 . V_25 = strlen ( V_5 ) ;
V_18 . V_26 = 0 ;
V_19 . V_1 = F_9 ( V_27 -> V_28 , & V_18 ) ;
if ( ! V_19 . V_1 )
goto V_29;
V_19 . V_30 = F_10 ( V_27 ) ;
F_11 ( V_20 ) ;
F_12 ( V_19 . V_1 , V_20 ) ;
V_13 = F_13 ( & V_19 , F_14 ( V_8 ) , V_15 ) ;
if ( F_6 ( V_13 ) )
goto V_31;
V_13 -> V_32 = V_20 -> V_33 ;
V_13 -> V_34 = V_8 & ( V_35 | V_36 ) ;
V_13 -> V_37 = V_16 ;
return V_13 ;
V_31:
F_15 ( & V_19 ) ;
V_29:
F_16 ( V_15 -> V_22 ) ;
return V_13 ;
}
int F_17 ( const char * V_5 , const struct V_14 * V_15 ,
void * V_16 , int V_8 )
{
int error , V_38 ;
struct V_13 * V_13 ;
error = F_18 ( V_8 ) ;
if ( error < 0 )
return error ;
V_38 = error ;
V_13 = F_5 ( V_5 , V_15 , V_16 , V_8 ) ;
if ( F_6 ( V_13 ) ) {
error = F_19 ( V_13 ) ;
goto V_39;
}
F_20 ( V_38 , V_13 ) ;
return V_38 ;
V_39:
F_21 ( V_38 ) ;
return error ;
}
static int T_1 F_22 ( void )
{
V_27 = F_23 ( & V_40 ) ;
if ( F_6 ( V_27 ) )
F_24 ( L_3 , F_19 ( V_27 ) ) ;
V_20 = F_25 ( V_27 -> V_28 ) ;
if ( F_6 ( V_20 ) )
F_24 ( L_4 , F_19 ( V_20 ) ) ;
return 0 ;
}
