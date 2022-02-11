static int T_1
F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_2 , V_3 , V_4 ,
V_5 ) ;
}
static int
F_3 ( struct V_6 * V_7 )
{
return 0 ;
}
static int T_1
F_4 ( struct V_6 * V_7 )
{
int V_8 ;
if ( ( V_8 = F_5 ( V_7 ) ) < 0 )
goto error;
V_9 [ V_10 ] . V_11 = V_8 ;
V_12 . V_13 = V_8 ;
if ( ( V_8 = F_5 ( V_7 ) ) < 0 )
goto error;
V_9 [ V_14 ] . V_11 = V_8 ;
V_12 . V_15 = V_8 ;
if ( ( V_8 = F_5 ( V_7 ) ) < 0 )
goto error;
V_9 [ V_16 ] . V_11 = V_8 ;
V_17 . V_18 = V_8 ;
if ( ( V_8 = F_6 ( V_7 , & V_17 ,
F_1 ) ) < 0 )
goto error;
F_7 ( V_7 , L_1 ) ;
return 0 ;
error:
F_3 ( V_7 ) ;
return V_8 ;
}
static int T_1
F_8 ( void )
{
return F_9 ( & V_19 , F_4 ) ;
}
static void T_2
F_10 ( void )
{
F_11 ( & V_19 ) ;
}
