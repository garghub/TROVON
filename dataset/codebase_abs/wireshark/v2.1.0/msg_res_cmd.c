static int F_1 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 , void * T_4 V_4 )
{
T_5 V_5 = 0 ;
T_5 V_6 ;
T_6 V_7 , V_8 , V_9 ;
T_7 * V_10 ;
T_3 * V_11 ;
T_3 * V_12 = NULL ;
T_8 V_13 ;
{
V_6 = F_2 ( V_1 ) ;
V_10 = F_3 ( V_3 , V_14 , V_1 , V_5 , - 1 , L_1 ) ;
V_11 = F_4 ( V_10 , V_15 ) ;
while( V_5 < V_6 )
{
F_5 ( & V_13 , V_1 , V_5 ) ;
V_7 = F_6 ( & V_13 ) ;
V_8 = F_7 ( & V_13 ) ;
if( V_7 == - 1 || V_8 > V_16 || V_8 < 1 )
{
F_8 ( V_2 -> V_17 , V_18 , NULL , L_2 ) ;
F_9 ( V_11 , V_19 , V_1 , V_5 , ( V_6 - V_5 ) , V_20 ) ;
break;
}
V_9 = F_10 ( & V_13 ) ;
#ifdef F_11
F_3 ( V_11 , V_14 , V_1 , V_5 , ( V_8 + V_9 ) , L_3 , V_7 , ( V_8 + V_9 ) , V_5 , V_8 , V_6 ) ;
#endif
switch ( V_7 )
{
case V_21 :
V_12 = F_12 ( & V_13 , V_15 , V_11 , V_14 , V_1 , V_5 , V_8 , L_4 ) ;
F_13 ( V_12 , V_1 , V_5 + V_9 , V_8 ) ;
break;
case V_22 :
V_12 = F_12 ( & V_13 , V_15 , V_11 , V_14 , V_1 , V_5 , V_8 , L_5 ) ;
F_14 ( V_12 , V_1 , V_5 + V_9 , V_8 ) ;
break;
default:
F_15 ( & V_13 , V_11 , V_23 , V_1 , V_5 , V_20 ) ;
break;
}
V_5 += ( V_8 + V_9 ) ;
}
}
return F_16 ( V_1 ) ;
}
void F_17 ( void )
{
static T_9 V_24 [] =
{
{
& V_19 ,
{ L_6 , L_7 , V_25 , V_26 , NULL , 0 , NULL , V_27 }
} ,
{
& V_23 ,
{ L_8 , L_9 , V_25 , V_26 , NULL , 0x0 , NULL , V_27 }
}
} ;
static T_6 * V_28 [] =
{
& V_15 ,
} ;
V_14 = F_18 (
L_10 ,
L_11 ,
L_12
) ;
F_19 ( V_14 , V_24 , F_20 ( V_24 ) ) ;
F_21 ( V_28 , F_20 ( V_28 ) ) ;
}
void
F_22 ( void )
{
T_10 V_29 ;
V_29 = F_23 ( F_1 , V_14 ) ;
F_24 ( L_13 , V_30 , V_29 ) ;
}
