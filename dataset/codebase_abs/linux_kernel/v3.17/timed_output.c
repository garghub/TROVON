static T_1 F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_8 = V_7 -> V_9 ( V_7 ) ;
return sprintf ( V_5 , L_1 , V_8 ) ;
}
static T_1 F_3 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 , T_2 V_10 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_11 ;
int V_12 ;
V_12 = F_4 ( V_5 , 0 , & V_11 ) ;
if ( V_12 != 0 )
return - V_13 ;
V_7 -> V_14 ( V_7 , V_11 ) ;
return V_10 ;
}
static int F_5 ( void )
{
if ( ! V_15 ) {
V_15 = F_6 ( V_16 , L_2 ) ;
if ( F_7 ( V_15 ) )
return F_8 ( V_15 ) ;
F_9 ( & V_17 , 0 ) ;
V_15 -> V_18 = V_19 ;
}
return 0 ;
}
int F_10 ( struct V_6 * V_7 )
{
int V_20 ;
if ( ! V_7 || ! V_7 -> V_21 || ! V_7 -> V_14 || ! V_7 -> V_9 )
return - V_13 ;
V_20 = F_5 () ;
if ( V_20 < 0 )
return V_20 ;
V_7 -> V_22 = F_11 ( & V_17 ) ;
V_7 -> V_2 = F_12 ( V_15 , NULL ,
F_13 ( 0 , V_7 -> V_22 ) , NULL , L_3 , V_7 -> V_21 ) ;
if ( F_7 ( V_7 -> V_2 ) )
return F_8 ( V_7 -> V_2 ) ;
F_14 ( V_7 -> V_2 , V_7 ) ;
V_7 -> V_23 = 0 ;
return 0 ;
}
void F_15 ( struct V_6 * V_7 )
{
V_7 -> V_14 ( V_7 , 0 ) ;
F_16 ( V_15 , F_13 ( 0 , V_7 -> V_22 ) ) ;
}
static int T_3 F_17 ( void )
{
return F_5 () ;
}
static void T_4 F_18 ( void )
{
F_19 ( V_15 ) ;
}
