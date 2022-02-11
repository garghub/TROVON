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
F_5 ( V_14 L_1 ) ;
F_6 ( 1 , & V_3 ) ;
return 0 ;
}
static T_1 F_7 ( struct V_2 * V_2 , const char T_2 * V_15 ,
T_3 V_16 , T_4 * V_17 )
{
if ( V_16 )
V_5 = V_6 + V_7 ;
return V_16 ;
}
static long F_8 ( struct V_2 * V_2 , unsigned int V_18 ,
unsigned long V_19 )
{
int V_20 = - V_21 ;
int time ;
void T_2 * V_22 = ( void T_2 * ) V_19 ;
int T_2 * V_23 = V_22 ;
switch ( V_18 ) {
case V_24 :
V_20 = F_9 ( V_22 , & V_25 ,
sizeof( V_25 ) ) ? - V_26 : 0 ;
break;
case V_27 :
V_20 = F_10 ( 0 , V_23 ) ;
break;
case V_28 :
V_20 = F_10 ( V_29 , V_23 ) ;
break;
case V_30 :
V_5 = V_6 + V_7 ;
V_20 = 0 ;
break;
case V_31 :
V_20 = F_11 ( time , V_23 ) ;
if ( V_20 )
break;
if ( time <= 0 || ( V_32 * ( long long ) time >= 0xffffffff ) ) {
V_20 = - V_33 ;
break;
}
V_7 = V_32 * time ;
V_5 = V_6 + V_7 ;
case V_34 :
V_20 = F_10 ( V_7 / V_32 , V_23 ) ;
break;
}
return V_20 ;
}
static int T_5 F_12 ( void )
{
int V_20 ;
V_32 = F_13 () ;
V_29 = ( V_35 & V_36 ) ?
V_37 : 0 ;
V_7 = V_32 * V_38 ;
V_20 = F_14 ( & V_39 ) ;
if ( V_20 == 0 )
F_5 ( V_40
L_2 ,
V_38 ) ;
return V_20 ;
}
static void T_6 F_15 ( void )
{
F_16 ( & V_39 ) ;
}
