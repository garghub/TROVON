static T_1 F_1 ( struct V_1 * V_1 , T_1 V_2 , int V_3 )
{
T_1 V_4 ;
struct V_5 * V_6 = F_2 ( V_1 -> V_7 . V_8 -> V_9 ) ;
switch( V_3 ) {
case 0 :
V_4 = V_2 ;
break;
case 1 :
V_4 = V_1 -> V_10 + V_2 ;
break;
case 2 :
V_4 = V_6 -> V_11 + V_2 ;
break;
default:
return - V_12 ;
}
if ( V_4 < 0 || V_4 > V_6 -> V_11 )
return - V_12 ;
return ( V_1 -> V_10 = V_4 ) ;
}
static T_2 F_3 ( struct V_1 * V_1 , char T_3 * V_13 , T_4 V_14 ,
T_1 * V_15 )
{
struct V_5 * V_6 = F_2 ( V_1 -> V_7 . V_8 -> V_9 ) ;
return F_4 ( V_13 , V_14 , V_15 , V_6 -> V_16 , V_6 -> V_11 ) ;
}
static int F_5 ( struct V_1 * V_1 , struct V_17 * V_18 )
{
struct V_5 * V_6 = F_2 ( V_1 -> V_7 . V_8 -> V_9 ) ;
if ( ( V_18 -> V_19 - V_18 -> V_20 ) > V_6 -> V_11 )
return - V_12 ;
F_6 ( V_18 , V_18 -> V_20 , F_7 ( V_6 -> V_16 ) >> V_21 ,
V_6 -> V_11 , V_18 -> V_22 ) ;
return 0 ;
}
static int T_5 F_8 ( void )
{
struct V_5 * V_23 ;
V_23 = F_9 ( L_1 , V_24 | V_25 , NULL ,
& V_26 , V_27 ) ;
if ( ! V_23 )
return 1 ;
V_23 -> V_11 = V_28 ;
return 0 ;
}
static int T_5 F_10 ( void )
{
struct V_5 * V_29 ;
V_29 = F_11 ( L_2 , NULL ) ;
if ( ! V_29 )
return 1 ;
#ifdef F_12
if ( ! F_13 ( L_3 , NULL , L_2 ) )
F_14 ( L_4 ) ;
#endif
if ( ! F_15 ( L_5 ) )
return 0 ;
if ( ! F_11 ( L_6 , V_29 ) )
return 1 ;
if ( ! F_13 ( L_6 , NULL , L_7 ) )
return 1 ;
return 0 ;
}
