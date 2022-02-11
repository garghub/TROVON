static void F_1 ( struct V_1 * V_2 , int V_3 )
{
T_1 V_4 ;
F_2 ( & V_5 ) ;
V_4 = F_3 ( V_6 ) ;
if ( V_3 )
F_4 ( V_4 | ( V_7 | V_8 ) , V_6 ) ;
else
F_4 ( V_4 & ~ ( V_7 | V_8 ) , V_6 ) ;
F_5 ( & V_5 ) ;
}
static void F_6 ( struct V_1 * V_2 , int V_9 )
{
T_1 V_4 ;
F_2 ( & V_5 ) ;
V_4 = F_3 ( V_6 ) ;
if ( V_9 )
F_4 ( V_4 & ~ V_7 , V_6 ) ;
else
F_4 ( V_4 | V_7 , V_6 ) ;
F_5 ( & V_5 ) ;
}
static int F_7 ( struct V_1 * V_2 )
{
return F_3 ( V_10 ) & V_7 ;
}
static void F_8 ( struct V_1 * V_2 , int V_3 )
{
T_1 V_4 ;
F_2 ( & V_5 ) ;
V_4 = F_3 ( V_10 ) ;
if ( V_3 )
F_4 ( V_4 | V_7 , V_10 ) ;
else
F_4 ( V_4 & ~ V_7 , V_10 ) ;
F_5 ( & V_5 ) ;
}
static void F_9 ( struct V_1 * V_2 , int V_3 )
{
T_1 V_4 ;
F_2 ( & V_5 ) ;
V_4 = F_3 ( V_10 ) ;
if ( V_3 )
F_4 ( V_4 | V_8 , V_10 ) ;
else
F_4 ( V_4 & ~ V_8 , V_10 ) ;
F_5 ( & V_5 ) ;
}
static int T_2 F_10 ( void )
{
struct V_11 * V_12 ;
int V_13 = 0 ;
V_12 = F_11 ( 0x325 , 2 , L_1 ) ;
if ( ! V_12 )
return - V_14 ;
V_15 = F_12 ( L_2 ,
& V_16 , NULL ) ;
if ( ! V_15 ) {
V_13 = - V_17 ;
goto V_18;
}
return 0 ;
V_18:
F_13 ( 0x325 , 2 ) ;
return V_13 ;
}
static void T_3 F_14 ( void )
{
F_1 ( V_15 , 0 ) ;
F_15 ( V_15 ) ;
F_13 ( 0x325 , 2 ) ;
}
