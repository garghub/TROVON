static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( & V_2 -> V_5 ) ;
int V_6 ;
V_4 -> V_7 = F_3 () ;
if ( ! V_4 -> V_7 )
return - V_8 ;
V_6 = F_4 ( V_4 -> V_7 , V_9 , NULL ) ;
if ( V_6 )
goto V_10;
V_4 -> V_7 -> V_5 . V_11 = & V_2 -> V_5 ;
V_4 -> V_7 -> V_12 = L_1 ;
V_4 -> V_7 -> V_13 . V_14 = V_15 ;
V_6 = F_5 ( V_4 -> V_7 ) ;
if ( V_6 )
goto V_10;
return 0 ;
V_10:
F_6 ( V_4 -> V_7 ) ;
return V_6 ;
}
static void F_7 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( & V_2 -> V_5 ) ;
F_8 ( V_4 -> V_7 ) ;
}
static void F_9 ( T_1 V_16 , T_2 V_17 , void * V_18 )
{
struct V_1 * V_2 = V_18 ;
struct V_3 * V_4 = F_2 ( & V_2 -> V_5 ) ;
if ( ! F_10 ( V_4 -> V_7 , V_17 , 1 , true ) )
F_11 ( & V_2 -> V_5 , L_2 ,
V_17 ) ;
}
static int F_12 ( struct V_1 * V_2 )
{
T_1 V_16 = F_13 ( & V_2 -> V_5 ) ;
struct V_3 * V_4 ;
T_3 V_19 ;
int V_20 ;
V_19 = F_14 ( V_16 , L_3 , NULL , NULL ) ;
if ( ! F_15 ( V_19 ) ) {
F_16 ( & V_2 -> V_5 , L_4 ) ;
return - V_21 ;
}
V_4 = F_17 ( & V_2 -> V_5 , sizeof( * V_4 ) , V_22 ) ;
if ( ! V_4 )
return - V_8 ;
F_18 ( & V_2 -> V_5 , V_4 ) ;
V_20 = F_1 ( V_2 ) ;
if ( V_20 ) {
F_19 ( L_5 ) ;
return V_20 ;
}
V_19 = F_20 ( V_16 ,
V_23 ,
F_9 ,
V_2 ) ;
if ( F_21 ( V_19 ) ) {
V_20 = - V_24 ;
goto V_25;
}
return 0 ;
V_25:
F_7 ( V_2 ) ;
return V_20 ;
}
static int F_22 ( struct V_1 * V_2 )
{
T_1 V_16 = F_13 ( & V_2 -> V_5 ) ;
F_7 ( V_2 ) ;
F_23 ( V_16 , V_23 , F_9 ) ;
return 0 ;
}
static T_3 T_4
F_24 ( T_1 V_16 , T_2 V_26 , void * V_18 , void * * V_27 )
{
const struct V_28 * V_29 = V_18 ;
struct V_30 * V_5 ;
if ( F_25 ( V_16 , & V_5 ) != 0 )
return V_31 ;
if ( F_26 ( V_5 , V_29 ) == 0 )
if ( F_27 ( V_5 ) )
F_11 ( & V_5 -> V_5 ,
L_6 ) ;
return V_31 ;
}
static int T_4 F_28 ( void )
{
F_29 ( V_32 , V_33 ,
V_34 , F_24 , NULL ,
( void * ) V_35 , NULL ) ;
return F_30 ( & V_36 ) ;
}
static void T_5 F_31 ( void )
{
F_32 ( & V_36 ) ;
}
