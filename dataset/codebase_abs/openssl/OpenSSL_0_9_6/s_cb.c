int T_1 F_1 ( int V_1 , T_2 * V_2 )
{
char V_3 [ 256 ] ;
T_3 * V_4 ;
int V_5 , V_6 ;
V_4 = F_2 ( V_2 ) ;
V_5 = F_3 ( V_2 ) ;
V_6 = F_4 ( V_2 ) ;
F_5 ( F_6 ( V_4 ) , V_3 , 256 ) ;
F_7 ( V_7 , L_1 , V_6 , V_3 ) ;
if ( ! V_1 )
{
F_7 ( V_7 , L_2 , V_5 ,
F_8 ( V_5 ) ) ;
if ( V_8 >= V_6 )
{
V_1 = 1 ;
V_9 = V_10 ;
}
else
{
V_1 = 0 ;
V_9 = V_11 ;
}
}
switch ( V_2 -> error )
{
case V_12 :
F_5 ( F_9 ( V_2 -> V_13 ) , V_3 , 256 ) ;
F_7 ( V_7 , L_3 , V_3 ) ;
break;
case V_14 :
case V_15 :
F_7 ( V_7 , L_4 ) ;
F_10 ( V_7 , F_11 ( V_2 -> V_13 ) ) ;
F_7 ( V_7 , L_5 ) ;
break;
case V_16 :
case V_17 :
F_7 ( V_7 , L_6 ) ;
F_10 ( V_7 , F_12 ( V_2 -> V_13 ) ) ;
F_7 ( V_7 , L_5 ) ;
break;
}
F_7 ( V_7 , L_7 , V_1 ) ;
return ( V_1 ) ;
}
int F_13 ( T_4 * V_2 , char * V_18 , char * V_19 )
{
if ( V_18 != NULL )
{
if ( F_14 ( V_2 , V_18 ,
V_20 ) <= 0 )
{
F_7 ( V_7 , L_8 , V_18 ) ;
F_15 ( V_7 ) ;
return ( 0 ) ;
}
if ( V_19 == NULL ) V_19 = V_18 ;
if ( F_16 ( V_2 , V_19 ,
V_20 ) <= 0 )
{
F_7 ( V_7 , L_9 , V_19 ) ;
F_15 ( V_7 ) ;
return ( 0 ) ;
}
if ( ! F_17 ( V_2 ) )
{
F_7 ( V_7 , L_10 ) ;
return ( 0 ) ;
}
}
return ( 1 ) ;
}
long T_1 F_18 ( T_5 * V_21 , int V_22 , const char * V_23 , int V_24 ,
long V_25 , long V_26 )
{
T_5 * V_27 ;
V_27 = ( T_5 * ) F_19 ( V_21 ) ;
if ( V_27 == NULL ) return ( V_26 ) ;
if ( V_22 == ( V_28 | V_29 ) )
{
F_7 ( V_27 , L_11 ,
V_21 , V_23 , V_24 , V_26 , V_26 ) ;
F_20 ( V_27 , V_23 , ( int ) V_26 ) ;
return ( V_26 ) ;
}
else if ( V_22 == ( V_30 | V_29 ) )
{
F_7 ( V_27 , L_12 ,
V_21 , V_23 , V_24 , V_26 , V_26 ) ;
F_20 ( V_27 , V_23 , ( int ) V_26 ) ;
}
return ( V_26 ) ;
}
void T_1 F_21 ( T_6 * V_31 , int V_32 , int V_26 )
{
char * V_33 ;
int V_34 ;
V_34 = V_32 & ~ V_35 ;
if ( V_34 & V_36 ) V_33 = L_13 ;
else if ( V_34 & V_37 ) V_33 = L_14 ;
else V_33 = L_15 ;
if ( V_32 & V_38 )
{
F_7 ( V_7 , L_16 , V_33 , F_22 ( V_31 ) ) ;
}
else if ( V_32 & V_39 )
{
V_33 = ( V_32 & V_40 ) ? L_17 : L_18 ;
F_7 ( V_7 , L_19 ,
V_33 ,
F_23 ( V_26 ) ,
F_24 ( V_26 ) ) ;
}
else if ( V_32 & V_41 )
{
if ( V_26 == 0 )
F_7 ( V_7 , L_20 ,
V_33 , F_22 ( V_31 ) ) ;
else if ( V_26 < 0 )
{
F_7 ( V_7 , L_21 ,
V_33 , F_22 ( V_31 ) ) ;
}
}
}
