static T_1 F_1 ( struct V_1 * V_1 , T_1 V_2 , int V_3 )
{
return F_2 ( V_1 , V_2 , V_3 , V_4 ) ;
}
static T_2 F_3 ( struct V_1 * V_1 , char T_3 * V_5 , T_4 V_6 ,
T_1 * V_7 )
{
return F_4 ( V_5 , V_6 , V_7 ,
F_5 ( F_6 ( V_1 ) ) , V_4 ) ;
}
static int F_7 ( struct V_1 * V_1 , struct V_8 * V_9 )
{
if ( ( V_9 -> V_10 - V_9 -> V_11 ) > V_4 )
return - V_12 ;
F_8 ( V_9 , V_9 -> V_11 ,
F_9 ( F_5 ( F_6 ( V_1 ) ) ) >> V_13 ,
V_4 , V_9 -> V_14 ) ;
return 0 ;
}
static int T_5 F_10 ( void )
{
struct V_15 * V_16 ;
V_16 = F_11 ( L_1 , V_17 | V_18 , NULL ,
& V_19 , V_20 ) ;
if ( ! V_16 )
return 1 ;
F_12 ( V_16 , V_4 ) ;
return 0 ;
}
static int T_5 F_13 ( void )
{
struct V_15 * V_21 ;
V_21 = F_14 ( L_2 , NULL ) ;
if ( ! V_21 )
return 1 ;
#ifdef F_15
if ( ! F_16 ( L_3 , NULL , L_2 ) )
F_17 ( L_4 ) ;
#endif
if ( ! F_18 ( L_5 ) )
return 0 ;
if ( ! F_14 ( L_6 , V_21 ) )
return 1 ;
if ( ! F_16 ( L_6 , NULL , L_7 ) )
return 1 ;
return 0 ;
}
