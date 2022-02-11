static T_1 F_1 ( struct V_1 * V_1 , T_1 V_2 , int V_3 )
{
T_1 V_4 ;
struct V_5 * V_6 = F_2 ( F_3 ( V_1 ) ) ;
switch( V_3 ) {
case 0 :
V_4 = V_2 ;
break;
case 1 :
V_4 = V_1 -> V_7 + V_2 ;
break;
case 2 :
V_4 = V_6 -> V_8 + V_2 ;
break;
default:
return - V_9 ;
}
if ( V_4 < 0 || V_4 > V_6 -> V_8 )
return - V_9 ;
return ( V_1 -> V_7 = V_4 ) ;
}
static T_2 F_4 ( struct V_1 * V_1 , char T_3 * V_10 , T_4 V_11 ,
T_1 * V_12 )
{
struct V_5 * V_6 = F_2 ( F_3 ( V_1 ) ) ;
return F_5 ( V_10 , V_11 , V_12 , V_6 -> V_13 , V_6 -> V_8 ) ;
}
static int F_6 ( struct V_1 * V_1 , struct V_14 * V_15 )
{
struct V_5 * V_6 = F_2 ( F_3 ( V_1 ) ) ;
if ( ( V_15 -> V_16 - V_15 -> V_17 ) > V_6 -> V_8 )
return - V_9 ;
F_7 ( V_15 , V_15 -> V_17 , F_8 ( V_6 -> V_13 ) >> V_18 ,
V_6 -> V_8 , V_15 -> V_19 ) ;
return 0 ;
}
static int T_5 F_9 ( void )
{
struct V_5 * V_20 ;
V_20 = F_10 ( L_1 , V_21 | V_22 , NULL ,
& V_23 , V_24 ) ;
if ( ! V_20 )
return 1 ;
V_20 -> V_8 = V_25 ;
return 0 ;
}
static int T_5 F_11 ( void )
{
struct V_5 * V_26 ;
V_26 = F_12 ( L_2 , NULL ) ;
if ( ! V_26 )
return 1 ;
#ifdef F_13
if ( ! F_14 ( L_3 , NULL , L_2 ) )
F_15 ( L_4 ) ;
#endif
if ( ! F_16 ( L_5 ) )
return 0 ;
if ( ! F_12 ( L_6 , V_26 ) )
return 1 ;
if ( ! F_14 ( L_6 , NULL , L_7 ) )
return 1 ;
return 0 ;
}
