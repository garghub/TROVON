static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
return sprintf ( V_5 , L_1 ) ;
}
static T_1 F_2 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_3 ( V_2 ) ;
int V_8 = F_4 ( V_4 ) -> V_9 ;
int V_10 ;
V_10 = F_5 ( V_7 -> V_11 , V_8 ) ;
if ( V_10 < 0 )
return V_10 ;
return sprintf ( V_5 , L_2 , F_6 ( V_10 , 1000 ) ) ;
}
static T_1 F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_3 ( V_2 ) ;
int V_8 = F_4 ( V_4 ) -> V_9 ;
int V_10 ;
V_10 = F_8 ( V_7 -> V_11 , V_8 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = 512180 - ( V_10 * 1000 ) ;
V_10 = F_6 ( V_10 * 10000 , 10983 ) ;
return sprintf ( V_5 , L_2 , V_10 ) ;
}
static T_1 F_9 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
int V_8 = F_4 ( V_4 ) -> V_9 ;
return sprintf ( V_5 , L_3 , V_12 [ V_8 ] ) ;
}
static int T_2 F_10 ( struct V_13 * V_14 )
{
struct V_11 * V_11 = F_3 ( V_14 -> V_2 . V_15 ) ;
struct V_6 * V_7 ;
int V_10 ;
V_7 = F_11 ( sizeof( struct V_6 ) , V_16 ) ;
if ( ! V_7 )
return - V_17 ;
V_7 -> V_11 = V_11 ;
V_10 = F_12 ( & V_14 -> V_2 . V_18 , & V_19 ) ;
if ( V_10 )
goto V_20;
V_7 -> V_21 = F_13 ( & V_14 -> V_2 ) ;
if ( F_14 ( V_7 -> V_21 ) ) {
V_10 = F_15 ( V_7 -> V_21 ) ;
goto V_22;
}
F_16 ( V_14 , V_7 ) ;
return 0 ;
V_22:
F_17 ( & V_14 -> V_2 . V_18 , & V_19 ) ;
V_20:
F_18 ( V_7 ) ;
return V_10 ;
}
static int T_3 F_19 ( struct V_13 * V_14 )
{
struct V_6 * V_7 = F_20 ( V_14 ) ;
F_21 ( V_7 -> V_21 ) ;
F_17 ( & V_14 -> V_2 . V_18 , & V_19 ) ;
F_16 ( V_14 , NULL ) ;
F_18 ( V_7 ) ;
return 0 ;
}
static int T_4 F_22 ( void )
{
return F_23 ( & V_23 ) ;
}
static void T_5 F_24 ( void )
{
F_25 ( & V_23 ) ;
}
