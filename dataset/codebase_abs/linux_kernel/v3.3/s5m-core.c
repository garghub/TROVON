int F_1 ( struct V_1 * V_2 , T_1 V_3 , void * V_4 )
{
return F_2 ( V_2 -> V_5 , V_3 , V_4 ) ;
}
int F_3 ( struct V_1 * V_2 , T_1 V_3 , int V_6 , T_1 * V_7 )
{
return F_4 ( V_2 -> V_5 , V_3 , V_7 , V_6 ) ; ;
}
int F_5 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_8 )
{
return F_6 ( V_2 -> V_5 , V_3 , V_8 ) ;
}
int F_7 ( struct V_1 * V_2 , T_1 V_3 , int V_6 , T_1 * V_7 )
{
return F_8 ( V_2 -> V_5 , V_3 , V_7 , V_6 * sizeof( V_9 ) ) ;
}
int F_9 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_10 , T_1 V_11 )
{
return F_10 ( V_2 -> V_5 , V_3 , V_11 , V_10 ) ;
}
static int F_11 ( struct V_12 * V_13 ,
const struct V_14 * V_15 )
{
struct V_16 * V_17 = V_13 -> V_18 . V_19 ;
struct V_1 * V_2 ;
int V_20 = 0 ;
int error ;
V_2 = F_12 ( sizeof( struct V_1 ) , V_21 ) ;
if ( V_2 == NULL )
return - V_22 ;
F_13 ( V_13 , V_2 ) ;
V_2 -> V_18 = & V_13 -> V_18 ;
V_2 -> V_13 = V_13 ;
V_2 -> V_23 = V_13 -> V_23 ;
V_2 -> type = V_15 -> V_24 ;
if ( V_17 ) {
V_2 -> V_25 = V_17 -> V_25 ;
V_2 -> V_26 = V_17 -> V_26 ;
V_2 -> V_27 = V_17 -> V_27 ;
V_2 -> V_28 = V_17 -> V_28 ;
}
V_2 -> V_5 = F_14 ( V_13 , & V_29 ) ;
if ( F_15 ( V_2 -> V_5 ) ) {
error = F_16 ( V_2 -> V_5 ) ;
F_17 ( & V_13 -> V_18 , L_1 ,
error ) ;
goto V_30;
}
V_2 -> V_31 = F_18 ( V_13 -> V_32 , V_33 ) ;
F_13 ( V_2 -> V_31 , V_2 ) ;
if ( V_17 && V_17 -> V_34 )
V_17 -> V_34 () ;
F_19 ( V_2 ) ;
F_20 ( V_2 -> V_18 ) ;
V_20 = F_21 ( V_2 -> V_18 , - 1 ,
V_35 , F_22 ( V_35 ) ,
NULL , 0 ) ;
if ( V_20 < 0 )
goto V_30;
return V_20 ;
V_30:
F_23 ( V_2 -> V_18 ) ;
F_24 ( V_2 ) ;
F_25 ( V_2 -> V_31 ) ;
F_26 ( V_2 -> V_5 ) ;
F_27 ( V_2 ) ;
return V_20 ;
}
static int F_28 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_29 ( V_13 ) ;
F_23 ( V_2 -> V_18 ) ;
F_24 ( V_2 ) ;
F_25 ( V_2 -> V_31 ) ;
F_26 ( V_2 -> V_5 ) ;
F_27 ( V_2 ) ;
return 0 ;
}
static int T_2 F_30 ( void )
{
return F_31 ( & V_36 ) ;
}
static void T_3 F_32 ( void )
{
F_33 ( & V_36 ) ;
}
