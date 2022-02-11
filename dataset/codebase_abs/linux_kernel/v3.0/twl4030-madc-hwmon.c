static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
struct V_8 V_9 ;
long V_10 ;
V_9 . V_11 = ( 1 << V_7 -> V_12 ) ;
V_9 . V_13 = V_14 ;
V_9 . V_15 = NULL ;
V_10 = F_3 ( & V_9 ) ;
if ( V_10 < 0 )
return V_10 ;
return sprintf ( V_5 , L_1 , V_9 . V_16 [ V_7 -> V_12 ] ) ;
}
static int T_2 F_4 ( struct V_17 * V_18 )
{
int V_19 ;
struct V_1 * V_20 ;
V_19 = F_5 ( & V_18 -> V_2 . V_21 , & V_22 ) ;
if ( V_19 )
goto V_23;
V_20 = F_6 ( & V_18 -> V_2 ) ;
if ( F_7 ( V_20 ) ) {
F_8 ( & V_18 -> V_2 , L_2 ) ;
V_19 = F_9 ( V_20 ) ;
goto V_24;
}
return 0 ;
V_24:
F_10 ( & V_18 -> V_2 . V_21 , & V_22 ) ;
V_23:
return V_19 ;
}
static int T_3 F_11 ( struct V_17 * V_18 )
{
F_12 ( & V_18 -> V_2 ) ;
F_10 ( & V_18 -> V_2 . V_21 , & V_22 ) ;
return 0 ;
}
static int T_4 F_13 ( void )
{
return F_14 ( & V_25 ) ;
}
static void T_5 F_15 ( void )
{
F_16 ( & V_25 ) ;
}
