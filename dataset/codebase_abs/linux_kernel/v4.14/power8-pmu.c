static int F_1 ( T_1 V_1 , unsigned int V_2 , T_1 V_3 [] )
{
int V_4 = 0 ;
V_4 = F_2 ( V_1 , V_3 ,
F_3 ( V_5 ) , V_2 ,
V_5 ) ;
return V_4 ;
}
static T_1 F_4 ( T_1 V_6 )
{
T_1 V_7 = 0 ;
if ( V_6 & V_8 )
return V_7 ;
if ( V_6 & V_9 )
return - 1 ;
if ( V_6 & V_10 )
return - 1 ;
if ( V_6 & V_11 )
return - 1 ;
if ( V_6 & V_12 ) {
V_7 |= V_13 ;
return V_7 ;
}
return - 1 ;
}
static void F_5 ( T_1 V_7 )
{
F_6 ( V_14 , ( F_7 ( V_14 ) | V_7 ) ) ;
}
static int T_2 F_8 ( void )
{
int V_15 ;
if ( ! V_16 -> V_17 ||
strcmp ( V_16 -> V_17 , L_1 ) )
return - V_18 ;
V_15 = F_9 ( & V_19 ) ;
if ( V_15 )
return V_15 ;
V_16 -> V_20 |= V_21 ;
if ( F_10 ( V_22 ) )
F_11 ( L_2 ) ;
return 0 ;
}
