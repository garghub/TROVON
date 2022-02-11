static int F_1 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
return F_2 ( V_3 , NULL , 0 , V_4 ) ;
}
static int F_3 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
( void ) F_2 ( V_5 , NULL , 0 , V_4 ) ;
return 0 ;
}
static T_1 F_4 ( struct V_2 * V_2 , char T_2 * V_6 ,
T_3 V_7 , T_4 * V_8 )
{
if ( ( V_2 -> V_9 & V_10 ) &&
! F_2 ( V_11 , NULL , 0 , V_4 ) )
return - V_12 ;
return F_2 ( V_13 , V_6 , V_7 , V_4 ) ;
}
static unsigned int F_5 ( struct V_2 * V_2 , T_5 * V_14 )
{
F_6 ( V_2 , & V_15 , V_14 ) ;
if ( F_2 ( V_11 , NULL , 0 , V_4 ) )
return V_16 | V_17 ;
return 0 ;
}
static int T_6 F_7 ( void )
{
F_8 ( L_1 , V_18 , NULL , & V_19 ) ;
return 0 ;
}
