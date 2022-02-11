static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 ) ;
}
static int T_1 F_3 ( void )
{
return F_4 ( & V_3 ) ;
}
struct V_1 * F_5 ( struct V_1 * V_4 , void * V_5 ,
const struct V_6 * * V_7 ,
const char * V_8 , ... )
{
struct V_1 * V_2 ;
T_2 V_9 ;
int V_10 ;
V_2 = F_6 ( sizeof( * V_2 ) , V_11 ) ;
if ( ! V_2 )
return F_7 ( - V_12 ) ;
F_8 ( V_2 ) ;
V_2 -> V_13 = & V_3 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_7 = V_7 ;
F_9 ( V_2 , V_5 ) ;
va_start ( V_9 , V_8 ) ;
V_10 = F_10 ( & V_2 -> V_14 , V_8 , V_9 ) ;
va_end ( V_9 ) ;
if ( V_10 )
goto error;
V_10 = F_11 ( V_2 ) ;
if ( V_10 )
goto error;
return V_2 ;
error:
F_12 ( V_2 ) ;
return F_7 ( V_10 ) ;
}
void F_13 ( struct V_1 * V_2 )
{
if ( ! V_2 || F_14 ( V_2 ) )
return;
F_15 ( V_2 ) ;
}
int F_16 ( struct V_1 * V_2 , struct V_1 * V_15 )
{
int V_10 ;
if ( ! V_2 || F_14 ( V_2 ) )
return - V_16 ;
V_10 = F_17 ( & V_2 -> V_14 , L_1 ,
& V_15 -> V_14 , F_18 ( V_15 ) ) ;
if ( V_10 )
return V_10 ;
V_10 = F_19 ( & V_15 -> V_14 , & V_2 -> V_14 , L_2 ) ;
if ( V_10 )
F_20 ( & V_2 -> V_14 , L_1 ,
F_18 ( V_15 ) ) ;
return V_10 ;
}
void F_21 ( struct V_1 * V_2 , struct V_1 * V_15 )
{
if ( ! V_2 || F_14 ( V_2 ) )
return;
F_22 ( & V_15 -> V_14 , L_2 ) ;
F_20 ( & V_2 -> V_14 , L_1 , F_18 ( V_15 ) ) ;
}
