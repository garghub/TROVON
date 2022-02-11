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
F_6 ( & V_5 -> V_2 ) ;
V_5 -> V_2 . V_12 = & V_3 ;
V_5 -> V_2 . V_6 = V_6 ;
V_5 -> V_2 . V_8 = V_8 ;
va_start ( V_10 , V_9 ) ;
V_11 = F_7 ( & V_5 -> V_2 . V_13 , V_9 , V_10 ) ;
va_end ( V_10 ) ;
if ( V_11 )
goto error;
V_11 = F_8 ( & V_5 -> V_2 ) ;
if ( V_11 )
goto error;
return 0 ;
error:
F_9 ( & V_5 -> V_2 ) ;
return V_11 ;
}
void F_10 ( struct V_4 * V_5 )
{
F_11 ( & V_5 -> V_2 ) ;
}
int F_12 ( struct V_4 * V_5 , struct V_1 * V_14 )
{
int V_11 ;
if ( ! V_5 || F_13 ( V_5 ) )
return - V_15 ;
V_11 = F_14 ( & V_5 -> V_2 . V_13 , L_1 ,
& V_14 -> V_13 , F_15 ( V_14 ) ) ;
if ( V_11 )
return V_11 ;
V_11 = F_16 ( & V_14 -> V_13 , & V_5 -> V_2 . V_13 , L_2 ) ;
if ( V_11 )
F_17 ( & V_5 -> V_2 . V_13 , L_1 ,
F_15 ( V_14 ) ) ;
return V_11 ;
}
void F_18 ( struct V_4 * V_5 , struct V_1 * V_14 )
{
if ( ! V_5 || F_13 ( V_5 ) )
return;
F_19 ( & V_14 -> V_13 , L_2 ) ;
F_17 ( & V_5 -> V_2 . V_13 , L_1 , F_15 ( V_14 ) ) ;
}
