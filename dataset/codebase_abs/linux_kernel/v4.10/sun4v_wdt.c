static int F_1 ( struct V_1 * V_2 )
{
F_2 ( 0 , NULL ) ;
return 0 ;
}
static int F_3 ( struct V_1 * V_2 )
{
int V_3 ;
V_3 = F_2 ( V_2 -> V_4 * 1000 , NULL ) ;
if ( V_3 == V_5 )
return - V_6 ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 ,
unsigned int V_4 )
{
V_2 -> V_4 = V_4 ;
return 0 ;
}
static int T_1 F_5 ( void )
{
struct V_7 * V_8 ;
T_2 V_9 ;
const T_2 * V_10 ;
int V_11 = 0 ;
unsigned long V_12 = 1 , V_13 = 1 ;
V_8 = F_6 () ;
if ( ! V_8 )
return - V_14 ;
V_9 = F_7 ( V_8 , V_15 , L_1 ) ;
V_11 = - V_14 ;
if ( V_9 == V_15 )
goto V_16;
if ( F_8 ( V_17 , V_12 , & V_13 ) )
goto V_18;
V_10 = F_9 ( V_8 , V_9 , L_2 , NULL ) ;
V_11 = - V_6 ;
if ( V_10 ) {
if ( * V_10 == 0 ||
* V_10 > V_19 )
goto V_18;
}
V_10 = F_9 ( V_8 , V_9 , L_3 , NULL ) ;
if ( V_10 ) {
if ( * V_10 < V_2 . V_20 * 1000 )
goto V_18;
if ( * V_10 < V_2 . V_21 * 1000 )
V_2 . V_21 = * V_10 / 1000 ;
}
F_10 ( & V_2 , V_4 , NULL ) ;
F_11 ( & V_2 , V_22 ) ;
V_11 = F_12 ( & V_2 ) ;
if ( V_11 )
goto V_18;
F_13 ( L_4 ,
V_2 . V_4 , V_22 ) ;
F_14 ( V_8 ) ;
return 0 ;
V_18:
F_15 ( V_17 ) ;
V_16:
F_14 ( V_8 ) ;
return V_11 ;
}
static void T_3 F_16 ( void )
{
F_15 ( V_17 ) ;
F_17 ( & V_2 ) ;
}
