bool F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
if ( F_2 ( V_2 == V_1 ) )
return false ;
if ( V_3 & V_4 )
return false ;
if ( V_5 . V_6 && ( V_3 & V_7 ) )
return false ;
if ( V_5 . V_8 && ! ( V_2 -> V_9 & V_10 ) )
return false ;
return F_3 ( & V_5 . V_11 , V_2 -> V_12 ) ;
}
static int T_2 F_4 ( char * V_13 )
{
return F_5 ( & V_5 . V_11 , V_13 ) ;
}
static int T_2 F_6 ( void )
{
struct V_14 * V_15 ;
T_3 V_16 = V_17 | V_18 | V_19 ;
V_15 = F_7 ( L_1 , NULL , & V_5 . V_11 ) ;
if ( F_8 ( V_15 ) )
return F_9 ( V_15 ) ;
if ( ! F_10 ( L_2 , V_16 , V_15 ,
& V_5 . V_6 ) )
goto V_20;
if ( ! F_10 ( L_3 , V_16 , V_15 ,
& V_5 . V_8 ) )
goto V_20;
return 0 ;
V_20:
F_11 ( V_15 ) ;
return - V_21 ;
}
