static int F_1 ( struct V_1 * V_2 )
{
T_1 V_3 , V_4 ;
T_2 V_5 [ V_6 ] ;
memcpy ( V_5 + V_7 ,
V_2 -> V_8 -> V_9 , V_10 ) ;
F_2 ( V_5 , V_11 ,
F_3 ( V_2 -> V_8 -> V_12 ) ) ;
F_2 ( V_5 , V_13 , 0 ) ;
V_3 = ( V_2 -> V_14 ) ? 0 :
( 1 << V_15 ) ;
F_2 ( V_5 , V_16 , V_3 ) ;
switch ( V_2 -> V_17 ) {
case V_18 | V_19 :
V_4 = V_20 ;
break;
case V_18 :
V_4 = V_21 ;
break;
default:
V_4 = V_22 ;
break;
}
if ( V_2 -> V_17 & V_23 )
V_4 = V_24 ;
F_2 ( V_5 , V_25 , V_4 ) ;
return F_4 ( V_2 , V_26 , V_5 , sizeof( V_5 ) ,
NULL , 0 , NULL ) ;
}
static int F_5 ( struct V_1 * V_2 , T_1 * V_27 )
{
T_2 V_28 [ V_29 ] ;
T_3 V_30 ;
int V_31 ;
F_6 ( V_32 != 0 ) ;
V_31 = F_4 ( V_2 , V_33 , NULL , 0 ,
V_28 , sizeof( V_28 ) , & V_30 ) ;
if ( V_31 )
goto V_34;
* V_27 = F_7 ( V_28 , V_35 ) ;
return 0 ;
V_34:
F_8 ( V_2 , V_36 , V_2 -> V_8 , L_1 ,
V_37 , V_31 ) ;
return V_31 ;
}
int F_9 ( struct V_1 * V_2 , T_4 V_38 ,
T_1 V_39 , int V_40 , int V_41 )
{
T_2 V_42 [ V_43 ] ;
int V_31 ;
T_5 * V_44 ;
int V_45 = V_40 ? 1000 : 0 ;
T_1 V_46 ;
T_1 V_47 ;
F_6 ( V_48 != 0 ) ;
V_47 = ( ( V_49 ) V_38 ) >> 0 ;
V_46 = ( ( V_49 ) V_38 ) >> 32 ;
F_2 ( V_42 , V_50 , V_47 ) ;
F_2 ( V_42 , V_51 , V_46 ) ;
V_44 = ( T_5 * ) F_10 ( V_42 , V_52 ) ;
F_11 ( * V_44 ,
V_53 , ! ! V_40 ,
V_54 , V_41 ,
V_55 , 1 ,
V_56 , ! ! V_40 ,
V_57 , 0 ,
V_58 , 1 ,
V_59 , V_45 ) ;
F_2 ( V_42 , V_60 , V_39 ) ;
V_31 = F_4 ( V_2 , V_61 , V_42 , sizeof( V_42 ) ,
NULL , 0 , NULL ) ;
if ( V_31 )
goto V_34;
return 0 ;
V_34:
F_8 ( V_2 , V_36 , V_2 -> V_8 , L_2 ,
V_37 , V_40 ? L_3 : L_4 , V_31 ) ;
return V_31 ;
}
static int F_12 ( struct V_1 * V_2 )
{
int V_31 ;
V_31 = F_1 ( V_2 ) ;
if ( V_31 != 0 )
return V_31 ;
V_2 -> type -> V_62 ( V_2 ) ;
return 0 ;
}
static bool F_13 ( struct V_1 * V_2 )
{
T_1 V_27 ;
int V_31 = F_5 ( V_2 , & V_27 ) ;
return ( V_31 != 0 ) || ( V_27 != 0 ) ;
}
