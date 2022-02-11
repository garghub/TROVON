static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 ) ;
}
static int T_1 F_3 ( void )
{
return F_4 ( & V_3 ) ;
}
int F_5 ( struct V_4 * V_5 ,
struct V_1 * V_6 ,
const struct V_7 * * V_8 ,
const char * V_9 , ... )
{
T_2 V_10 ;
int V_11 ;
V_5 -> V_2 = F_6 ( sizeof( * V_5 -> V_2 ) , V_12 ) ;
if ( ! V_5 -> V_2 )
return - V_13 ;
F_7 ( V_5 -> V_2 ) ;
V_5 -> V_2 -> V_14 = & V_3 ;
V_5 -> V_2 -> V_6 = V_6 ;
V_5 -> V_2 -> V_8 = V_8 ;
va_start ( V_10 , V_9 ) ;
V_11 = F_8 ( & V_5 -> V_2 -> V_15 , V_9 , V_10 ) ;
va_end ( V_10 ) ;
if ( V_11 )
goto error;
V_11 = F_9 ( V_5 -> V_2 ) ;
if ( V_11 )
goto error;
F_10 ( V_5 -> V_2 , V_5 ) ;
return 0 ;
error:
F_11 ( V_5 -> V_2 ) ;
return V_11 ;
}
void F_12 ( struct V_4 * V_5 )
{
F_10 ( V_5 -> V_2 , NULL ) ;
F_13 ( V_5 -> V_2 ) ;
V_5 -> V_2 = NULL ;
}
int F_14 ( struct V_4 * V_5 , struct V_1 * V_16 )
{
int V_11 ;
if ( ! V_5 || F_15 ( V_5 ) )
return - V_17 ;
V_11 = F_16 ( & V_5 -> V_2 -> V_15 , L_1 ,
& V_16 -> V_15 , F_17 ( V_16 ) ) ;
if ( V_11 )
return V_11 ;
V_11 = F_18 ( & V_16 -> V_15 , & V_5 -> V_2 -> V_15 , L_2 ) ;
if ( V_11 )
F_19 ( & V_5 -> V_2 -> V_15 , L_1 ,
F_17 ( V_16 ) ) ;
return V_11 ;
}
void F_20 ( struct V_4 * V_5 , struct V_1 * V_16 )
{
if ( ! V_5 || F_15 ( V_5 ) )
return;
F_21 ( & V_16 -> V_15 , L_2 ) ;
F_19 ( & V_5 -> V_2 -> V_15 , L_1 , F_17 ( V_16 ) ) ;
}
