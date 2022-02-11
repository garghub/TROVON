static long F_1 ( struct V_1 * V_1 , unsigned int V_2 ,
unsigned long V_3 )
{
int V_4 = 0 ;
switch ( V_2 ) {
case V_5 :
if ( F_2 () == 1 )
V_4 = 0 ;
else
V_4 = ( ( F_3 () * V_6 ) %
V_7 ) / 8 ;
break;
case V_8 :
if ( F_4 ( ( unsigned long V_9 * ) V_3 ,
& V_10 , sizeof( unsigned long ) ) )
V_4 = - V_11 ;
break;
case V_12 :
if ( F_4 ( ( unsigned long V_9 * ) V_3 ,
& V_13 ,
sizeof( unsigned long ) ) )
V_4 = - V_11 ;
break;
case V_14 :
V_4 = F_5 ( V_15 ) ;
break;
case V_16 :
V_4 = 1 ;
break;
case V_17 :
if ( F_4 ( ( unsigned long V_9 * ) V_3 ,
( unsigned long * ) F_6 ( V_18 ) ,
sizeof( unsigned long ) ) )
V_4 = - V_11 ;
break;
default:
V_4 = - V_19 ;
break;
}
return V_4 ;
}
static int F_7 ( struct V_1 * V_1 , struct V_20 * V_21 )
{
unsigned long V_22 ;
if ( V_21 -> V_23 - V_21 -> V_24 != V_7 )
return - V_25 ;
if ( V_21 -> V_26 & V_27 )
return - V_28 ;
if ( V_7 > ( 1 << 16 ) )
return - V_29 ;
V_21 -> V_30 = F_8 ( V_21 -> V_30 ) ;
V_22 = V_31 | V_18 ;
V_22 &= ~ ( V_7 - 1 ) ;
V_22 &= 0xfffffffffffffffUL ;
if ( F_9 ( V_21 , V_21 -> V_24 , V_22 >> V_32 ,
V_7 , V_21 -> V_30 ) ) {
F_10 ( V_33 L_1 ) ;
return - V_34 ;
}
return 0 ;
}
static int T_1 F_11 ( void )
{
if ( ! F_12 () ) {
F_10 ( V_33 L_2 , V_35 ) ;
return - 1 ;
}
if ( V_13 < 100000 ) {
F_10 ( V_33 L_3 ,
V_35 ) ;
return - 1 ;
}
V_10 = ( ( unsigned long ) 1E15 +
V_13 / 2 ) /
V_13 ;
if ( F_13 ( & V_36 ) ) {
F_10 ( V_33 L_4 ,
V_35 ) ;
return - 1 ;
}
F_10 ( V_37 L_5 , V_38 ,
V_39 ,
V_13 / ( unsigned long ) 1E6 ) ;
return 0 ;
}
