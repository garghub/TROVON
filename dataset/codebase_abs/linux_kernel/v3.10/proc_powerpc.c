static T_1 F_1 ( struct V_1 * V_1 , T_1 V_2 , int V_3 )
{
T_1 V_4 ;
switch( V_3 ) {
case 0 :
V_4 = V_2 ;
break;
case 1 :
V_4 = V_1 -> V_5 + V_2 ;
break;
case 2 :
V_4 = V_6 + V_2 ;
break;
default:
return - V_7 ;
}
if ( V_4 < 0 || V_4 > V_6 )
return - V_7 ;
return ( V_1 -> V_5 = V_4 ) ;
}
static T_2 F_2 ( struct V_1 * V_1 , char T_3 * V_8 , T_4 V_9 ,
T_1 * V_10 )
{
return F_3 ( V_8 , V_9 , V_10 ,
F_4 ( F_5 ( V_1 ) ) , V_6 ) ;
}
static int F_6 ( struct V_1 * V_1 , struct V_11 * V_12 )
{
if ( ( V_12 -> V_13 - V_12 -> V_14 ) > V_6 )
return - V_7 ;
F_7 ( V_12 , V_12 -> V_14 ,
F_8 ( F_4 ( F_5 ( V_1 ) ) ) >> V_15 ,
V_6 , V_12 -> V_16 ) ;
return 0 ;
}
static int T_5 F_9 ( void )
{
struct V_17 * V_18 ;
V_18 = F_10 ( L_1 , V_19 | V_20 , NULL ,
& V_21 , V_22 ) ;
if ( ! V_18 )
return 1 ;
F_11 ( V_18 , V_6 ) ;
return 0 ;
}
static int T_5 F_12 ( void )
{
struct V_17 * V_23 ;
V_23 = F_13 ( L_2 , NULL ) ;
if ( ! V_23 )
return 1 ;
#ifdef F_14
if ( ! F_15 ( L_3 , NULL , L_2 ) )
F_16 ( L_4 ) ;
#endif
if ( ! F_17 ( L_5 ) )
return 0 ;
if ( ! F_13 ( L_6 , V_23 ) )
return 1 ;
if ( ! F_15 ( L_6 , NULL , L_7 ) )
return 1 ;
return 0 ;
}
