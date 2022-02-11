static void F_1 ( struct V_1 * V_2 ,
enum V_3 V_4 )
{
if ( V_4 )
V_5 = V_6 | V_7 ;
else
V_5 = ~ ( V_6 | V_7 ) ;
F_2 ( V_5 , V_8 ) ;
}
static int T_1 F_3 ( struct V_9 * V_10 )
{
struct V_11 * V_12 ;
int V_13 ;
V_12 = F_4 ( V_10 , V_14 , 0 ) ;
if ( ! V_12 )
return - V_15 ;
V_8 = F_5 ( V_12 -> V_16 , F_6 ( V_12 ) ) ;
if ( ! V_8 )
return - V_17 ;
V_5 = V_6 | V_7 ;
F_2 ( V_5 , V_8 ) ;
V_13 = F_7 ( & V_10 -> V_18 , & V_19 ) ;
if ( V_13 )
goto V_20;
return 0 ;
V_20:
F_8 ( V_8 ) ;
V_8 = NULL ;
return V_13 ;
}
static int T_2 F_9 ( struct V_9 * V_10 )
{
F_10 ( & V_19 ) ;
if ( V_8 ) {
F_8 ( V_8 ) ;
V_8 = NULL ;
}
return 0 ;
}
