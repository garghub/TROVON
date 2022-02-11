static void F_1 ( struct V_1 * V_2 , enum V_3 V_4 )
{
struct V_5 * V_6 = F_2 ( & V_2 -> V_7 ) ;
switch ( V_4 ) {
case V_8 :
F_3 ( L_1 ,
( unsigned long ) V_2 -> V_9 ) ;
F_4 ( 2 , L_2 ) ;
F_5 ( 2 , V_2 ) ;
break;
case V_10 :
F_4 ( 2 , L_3 ) ;
F_5 ( 2 , V_2 ) ;
F_6 ( V_6 ) ;
break;
}
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_5 * V_6 ;
int V_11 ;
F_4 ( 2 , L_4 ) ;
F_5 ( 2 , V_2 ) ;
if ( V_2 -> V_12 . V_13 != V_14 )
return - V_15 ;
V_6 = F_8 ( sizeof( * V_6 ) , V_16 ) ;
if ( ! V_6 )
return - V_17 ;
F_9 ( & V_2 -> V_7 , V_6 ) ;
V_11 = F_10 ( V_6 , V_2 ) ;
if ( V_11 ) {
F_9 ( & V_2 -> V_7 , NULL ) ;
F_11 ( V_6 ) ;
goto V_18;
}
V_18:
return V_11 ;
}
static int F_12 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( & V_2 -> V_7 ) ;
F_13 ( V_6 ) ;
F_9 ( & V_2 -> V_7 , NULL ) ;
F_11 ( V_6 ) ;
return 0 ;
}
int T_1 F_14 ( void )
{
return F_15 ( & V_19 ) ;
}
void F_16 ( void )
{
F_17 ( & V_19 ) ;
}
