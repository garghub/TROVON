static int F_1 ( struct V_1 * V_2 , void * V_3 , T_1 V_4 , bool V_5 )
{
void T_2 * V_6 = ( void T_2 * ) V_2 -> V_7 ;
* ( V_8 * ) V_3 = F_2 ( V_6 + 8 ) & 0xffff ;
return 2 ;
}
static int F_3 ( struct V_9 * V_10 , const struct V_11 * V_12 )
{
void T_2 * V_6 ;
int V_13 ;
V_14 = F_4 ( & V_10 -> V_10 , NULL ) ;
if ( F_5 ( V_14 ) ) {
F_6 ( & V_10 -> V_10 , L_1 ) ;
V_13 = F_7 ( V_14 ) ;
return V_13 ;
}
F_8 ( V_14 ) ;
V_13 = F_9 ( V_10 , V_10 -> V_10 . V_15 ) ;
if ( V_13 )
return V_13 ;
V_13 = - V_16 ;
V_6 = F_10 ( V_10 -> V_17 . V_18 , F_11 ( & V_10 -> V_17 ) ) ;
if ( ! V_6 )
goto V_19;
V_20 . V_7 = ( unsigned long ) V_6 ;
V_13 = F_12 ( & V_20 ) ;
if ( V_13 )
goto V_21;
return 0 ;
V_21:
F_13 ( V_6 ) ;
V_19:
F_14 ( V_10 ) ;
F_15 ( V_14 ) ;
F_16 ( V_14 ) ;
return V_13 ;
}
static int F_17 ( struct V_9 * V_10 )
{
void T_2 * V_6 = ( void T_2 * ) V_20 . V_7 ;
F_18 ( & V_20 ) ;
F_13 ( V_6 ) ;
F_14 ( V_10 ) ;
F_15 ( V_14 ) ;
F_16 ( V_14 ) ;
return 0 ;
}
static int T_3 F_19 ( void )
{
return F_20 ( & V_22 ) ;
}
static void T_4 F_21 ( void )
{
F_22 ( & V_22 ) ;
}
