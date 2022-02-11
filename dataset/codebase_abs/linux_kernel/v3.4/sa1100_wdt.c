static int F_1 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
if ( F_2 ( 1 , & V_3 ) )
return - V_4 ;
V_5 = V_6 + V_7 ;
V_8 = V_9 ;
V_10 = V_11 ;
V_12 |= V_13 ;
return F_3 ( V_1 , V_2 ) ;
}
static int F_4 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
F_5 ( L_1 ) ;
F_6 ( 1 , & V_3 ) ;
return 0 ;
}
static T_1 F_7 ( struct V_2 * V_2 , const char T_2 * V_14 ,
T_3 V_15 , T_4 * V_16 )
{
if ( V_15 )
V_5 = V_6 + V_7 ;
return V_15 ;
}
static long F_8 ( struct V_2 * V_2 , unsigned int V_17 ,
unsigned long V_18 )
{
int V_19 = - V_20 ;
int time ;
void T_2 * V_21 = ( void T_2 * ) V_18 ;
int T_2 * V_22 = V_21 ;
switch ( V_17 ) {
case V_23 :
V_19 = F_9 ( V_21 , & V_24 ,
sizeof( V_24 ) ) ? - V_25 : 0 ;
break;
case V_26 :
V_19 = F_10 ( 0 , V_22 ) ;
break;
case V_27 :
V_19 = F_10 ( V_28 , V_22 ) ;
break;
case V_29 :
V_5 = V_6 + V_7 ;
V_19 = 0 ;
break;
case V_30 :
V_19 = F_11 ( time , V_22 ) ;
if ( V_19 )
break;
if ( time <= 0 || ( V_31 * ( long long ) time >= 0xffffffff ) ) {
V_19 = - V_32 ;
break;
}
V_7 = V_31 * time ;
V_5 = V_6 + V_7 ;
case V_33 :
V_19 = F_10 ( V_7 / V_31 , V_22 ) ;
break;
}
return V_19 ;
}
static int T_5 F_12 ( void )
{
int V_19 ;
V_31 = F_13 () ;
V_28 = ( V_34 & V_35 ) ?
V_36 : 0 ;
V_7 = V_31 * V_37 ;
V_19 = F_14 ( & V_38 ) ;
if ( V_19 == 0 )
F_15 ( L_2 ,
V_37 ) ;
return V_19 ;
}
static void T_6 F_16 ( void )
{
F_17 ( & V_38 ) ;
}
