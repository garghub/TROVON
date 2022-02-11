static int F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_2 , & V_3 , V_4 ) ;
}
static void F_3 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
T_1 type , T_1 V_7 , int V_8 , T_2 V_9 )
{
F_4 ( V_2 , V_6 , type , V_7 , V_8 , V_9 , & V_3 ) ;
}
int T_3 F_5 ( void )
{
int V_10 ;
V_10 = F_6 ( & V_11 , V_4 ) ;
if ( V_10 )
goto V_12;
V_10 = F_7 ( & V_13 ) ;
if ( V_10 )
goto V_14;
V_12:
return V_10 ;
V_14:
F_8 ( & V_11 , V_4 ) ;
goto V_12;
}
void F_9 ( void )
{
F_10 ( & V_13 ) ;
F_8 ( & V_11 , V_4 ) ;
}
static int T_4 F_11 ( struct V_15 * V_15 )
{
return F_12 ( V_15 , & V_16 ) ;
}
static void T_5 F_13 ( struct V_15 * V_15 )
{
F_14 ( V_15 , & V_16 ) ;
}
int T_3 F_15 ( void )
{
return F_16 ( & V_17 ) ;
}
void F_17 ( void )
{
F_18 ( & V_17 ) ;
}
