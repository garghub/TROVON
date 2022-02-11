bool F_1 ( T_1 V_1 , T_2 V_2 , unsigned long V_3 )
{
if ( V_2 & V_4 )
return false ;
if ( V_5 . V_6 && ( V_2 & V_7 ) )
return false ;
if ( V_5 . V_8 && ! ( V_3 & V_9 ) )
return false ;
return F_2 ( & V_5 . V_10 , V_1 ) ;
}
static int T_3 F_3 ( char * V_11 )
{
return F_4 ( & V_5 . V_10 , V_11 ) ;
}
static int T_3 F_5 ( void )
{
struct V_12 * V_13 ;
T_4 V_14 = V_15 | V_16 | V_17 ;
V_13 = F_6 ( L_1 , NULL , & V_5 . V_10 ) ;
if ( F_7 ( V_13 ) )
return F_8 ( V_13 ) ;
if ( ! F_9 ( L_2 , V_14 , V_13 ,
& V_5 . V_6 ) )
goto V_18;
if ( ! F_9 ( L_3 , V_14 , V_13 ,
& V_5 . V_8 ) )
goto V_18;
return 0 ;
V_18:
F_10 ( V_13 ) ;
return - V_19 ;
}
