static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( & V_2 -> V_5 ) ;
int V_6 ;
V_4 -> V_7 = F_3 ( & V_2 -> V_5 ) ;
if ( ! V_4 -> V_7 )
return - V_8 ;
V_6 = F_4 ( V_4 -> V_7 , V_9 , NULL ) ;
if ( V_6 )
return V_6 ;
V_4 -> V_7 -> V_5 . V_10 = & V_2 -> V_5 ;
V_4 -> V_7 -> V_11 = L_1 ;
V_4 -> V_7 -> V_12 . V_13 = V_14 ;
return F_5 ( V_4 -> V_7 ) ;
}
static void F_6 ( T_1 V_15 , T_2 V_16 , void * V_17 )
{
struct V_1 * V_2 = V_17 ;
struct V_3 * V_4 = F_2 ( & V_2 -> V_5 ) ;
if ( ! F_7 ( V_4 -> V_7 , V_16 , 1 , true ) )
F_8 ( & V_2 -> V_5 , L_2 ,
V_16 ) ;
}
static int F_9 ( struct V_1 * V_2 )
{
T_1 V_15 = F_10 ( & V_2 -> V_5 ) ;
struct V_3 * V_4 ;
T_3 V_18 ;
int V_19 ;
V_18 = F_11 ( V_15 , L_3 , NULL , NULL ) ;
if ( F_12 ( V_18 ) ) {
F_13 ( & V_2 -> V_5 , L_4 ) ;
return - V_20 ;
}
V_4 = F_14 ( & V_2 -> V_5 , sizeof( * V_4 ) , V_21 ) ;
if ( ! V_4 )
return - V_8 ;
F_15 ( & V_2 -> V_5 , V_4 ) ;
V_19 = F_1 ( V_2 ) ;
if ( V_19 ) {
F_16 ( L_5 ) ;
return V_19 ;
}
V_18 = F_17 ( V_15 ,
V_22 ,
F_6 ,
V_2 ) ;
if ( F_12 ( V_18 ) )
return - V_23 ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 )
{
T_1 V_15 = F_10 ( & V_2 -> V_5 ) ;
F_19 ( V_15 , V_22 , F_6 ) ;
return 0 ;
}
static T_3 T_4
F_20 ( T_1 V_15 , T_2 V_24 , void * V_17 , void * * V_25 )
{
const struct V_26 * V_27 = V_17 ;
struct V_28 * V_5 ;
if ( F_21 ( V_15 , & V_5 ) != 0 )
return V_29 ;
if ( F_22 ( V_5 , V_27 ) == 0 )
if ( F_23 ( V_5 , NULL ) )
F_8 ( & V_5 -> V_5 ,
L_6 ) ;
return V_29 ;
}
static int T_4 F_24 ( void )
{
F_25 ( V_30 , V_31 ,
V_32 , F_20 , NULL ,
( void * ) V_33 , NULL ) ;
return F_26 ( & V_34 ) ;
}
static void T_5 F_27 ( void )
{
F_28 ( & V_34 ) ;
}
