static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 ,
T_2 V_6 )
{
struct V_7 V_8 ;
struct V_9 V_10 ;
int V_11 ;
struct V_12 * V_13 = (struct V_12 * ) V_5 ;
struct V_14 * V_15 = F_2 ( V_2 ) ;
struct V_16 * V_17 = V_15 -> V_18 ;
V_10 . V_6 = V_6 ;
V_10 . V_19 = V_13 ;
F_3 ( & V_17 -> V_20 ) ;
F_4 ( & V_8 ) ;
F_5 ( & V_10 , & V_8 ) ;
V_11 = F_6 ( V_17 -> V_21 , & V_8 ) ;
if ( V_11 )
goto V_22;
V_22:
F_7 ( & V_17 -> V_20 ) ;
return V_11 ? V_11 : V_6 ;
}
static int T_3 F_8 ( struct V_23 * V_24 )
{
struct V_16 * V_17 ;
int V_11 = 0 ;
V_17 = F_9 ( sizeof( * V_17 ) , V_25 ) ;
if ( V_17 == NULL ) {
V_11 = - V_26 ;
goto V_22;
}
F_10 ( V_24 , V_17 ) ;
F_11 ( & V_17 -> V_20 ) ;
V_17 -> V_21 = V_24 ;
V_17 -> V_15 = F_12 ( 0 ) ;
if ( V_17 -> V_15 == NULL ) {
V_11 = - V_26 ;
goto V_27;
}
V_17 -> V_15 -> V_2 . V_28 = & V_24 -> V_2 ;
V_17 -> V_15 -> V_29 = & V_30 ;
V_17 -> V_15 -> V_18 = ( void * ) ( V_17 ) ;
V_17 -> V_15 -> V_31 = V_32 ;
V_11 = F_13 ( V_17 -> V_15 ) ;
if ( V_11 )
goto V_33;
V_24 -> V_34 = 2000000 ;
V_24 -> V_35 = V_36 ;
V_24 -> V_37 = 16 ;
F_14 ( V_24 ) ;
return 0 ;
V_33:
F_15 ( V_17 -> V_15 ) ;
V_27:
F_16 ( V_17 ) ;
V_22:
return V_11 ;
}
static int T_4 F_17 ( struct V_23 * V_24 )
{
struct V_16 * V_17 = F_18 ( V_24 ) ;
F_19 ( V_17 -> V_15 ) ;
F_16 ( V_17 ) ;
return 0 ;
}
static T_5 int F_20 ( void )
{
return F_21 ( & V_38 ) ;
}
static T_6 void F_22 ( void )
{
F_23 ( & V_38 ) ;
}
