static T_1 F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_8 = V_7 -> V_9 ( V_7 ) ;
return sprintf ( V_5 , L_1 , V_8 ) ;
}
static T_1 F_3 (
struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 , T_2 V_10 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_11 ;
if ( sscanf ( V_5 , L_2 , & V_11 ) != 1 )
return - V_12 ;
V_7 -> V_13 ( V_7 , V_11 ) ;
return V_10 ;
}
static int F_4 ( void )
{
if ( ! V_14 ) {
V_14 = F_5 ( V_15 , L_3 ) ;
if ( F_6 ( V_14 ) )
return F_7 ( V_14 ) ;
F_8 ( & V_16 , 0 ) ;
}
return 0 ;
}
int F_9 ( struct V_6 * V_7 )
{
int V_17 ;
if ( ! V_7 || ! V_7 -> V_18 || ! V_7 -> V_13 || ! V_7 -> V_9 )
return - V_12 ;
V_17 = F_4 () ;
if ( V_17 < 0 )
return V_17 ;
V_7 -> V_19 = F_10 ( & V_16 ) ;
V_7 -> V_2 = F_11 ( V_14 , NULL ,
F_12 ( 0 , V_7 -> V_19 ) , NULL , L_4 , V_7 -> V_18 ) ;
if ( F_6 ( V_7 -> V_2 ) )
return F_7 ( V_7 -> V_2 ) ;
V_17 = F_13 ( V_7 -> V_2 , & V_20 ) ;
if ( V_17 < 0 )
goto V_21;
F_14 ( V_7 -> V_2 , V_7 ) ;
V_7 -> V_22 = 0 ;
return 0 ;
V_21:
F_15 ( V_14 , F_12 ( 0 , V_7 -> V_19 ) ) ;
F_16 ( L_5 ,
V_7 -> V_18 ) ;
return V_17 ;
}
void F_17 ( struct V_6 * V_7 )
{
V_7 -> V_13 ( V_7 , 0 ) ;
F_18 ( V_7 -> V_2 , & V_20 ) ;
F_15 ( V_14 , F_12 ( 0 , V_7 -> V_19 ) ) ;
F_14 ( V_7 -> V_2 , NULL ) ;
}
static int T_3 F_19 ( void )
{
return F_4 () ;
}
static void T_4 F_20 ( void )
{
F_21 ( V_14 ) ;
}
