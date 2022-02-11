static int F_1 ( struct V_1 * V_1 , int V_2 , int V_3 )
{
int V_4 ;
F_2 ( V_1 ) ;
if ( V_3 == V_5 )
V_4 = F_3 ( V_1 ,
V_6 ,
1 << V_2 ) ;
else
V_4 = F_4 ( V_1 ,
V_6 ,
1 << V_2 ) ;
F_5 ( V_1 ) ;
return V_4 ;
}
static int F_6 ( struct V_1 * V_1 , int V_2 , int V_7 )
{
if ( V_7 == V_8 )
return F_4 ( V_1 , V_9 ,
1 << V_2 ) ;
else
return F_3 ( V_1 ,
V_9 , 1 << V_2 ) ;
}
static int F_7 ( struct V_1 * V_1 , int V_2 , int V_10 )
{
T_1 V_11 ;
F_2 ( V_1 ) ;
switch ( V_2 ) {
case 0 :
V_11 = F_8 ( V_1 , V_12 )
& ~ V_13 ;
F_9 ( V_1 , V_12 ,
V_11 | ( ( V_10 & 0xf ) << 0 ) ) ;
break;
case 1 :
V_11 = F_8 ( V_1 , V_12 )
& ~ V_14 ;
F_9 ( V_1 , V_12 ,
V_11 | ( ( V_10 & 0xf ) << 4 ) ) ;
break;
case 2 :
V_11 = F_8 ( V_1 , V_12 )
& ~ V_15 ;
F_9 ( V_1 , V_12 ,
V_11 | ( ( V_10 & 0xf ) << 8 ) ) ;
break;
case 3 :
V_11 = F_8 ( V_1 , V_12 )
& ~ V_16 ;
F_9 ( V_1 , V_12 ,
V_11 | ( ( V_10 & 0xf ) << 12 ) ) ;
break;
case 4 :
V_11 = F_8 ( V_1 , V_17 )
& ~ V_18 ;
F_9 ( V_1 , V_17 ,
V_11 | ( ( V_10 & 0xf ) << 0 ) ) ;
break;
case 5 :
V_11 = F_8 ( V_1 , V_17 )
& ~ V_19 ;
F_9 ( V_1 , V_17 ,
V_11 | ( ( V_10 & 0xf ) << 4 ) ) ;
break;
case 6 :
V_11 = F_8 ( V_1 , V_17 )
& ~ V_20 ;
F_9 ( V_1 , V_17 ,
V_11 | ( ( V_10 & 0xf ) << 8 ) ) ;
break;
case 7 :
V_11 = F_8 ( V_1 , V_17 )
& ~ V_21 ;
F_9 ( V_1 , V_17 ,
V_11 | ( ( V_10 & 0xf ) << 12 ) ) ;
break;
case 8 :
V_11 = F_8 ( V_1 , V_22 )
& ~ V_23 ;
F_9 ( V_1 , V_22 ,
V_11 | ( ( V_10 & 0xf ) << 0 ) ) ;
break;
case 9 :
V_11 = F_8 ( V_1 , V_22 )
& ~ V_24 ;
F_9 ( V_1 , V_22 ,
V_11 | ( ( V_10 & 0xf ) << 4 ) ) ;
break;
case 10 :
V_11 = F_8 ( V_1 , V_22 )
& ~ V_25 ;
F_9 ( V_1 , V_22 ,
V_11 | ( ( V_10 & 0xf ) << 8 ) ) ;
break;
case 11 :
V_11 = F_8 ( V_1 , V_22 )
& ~ V_26 ;
F_9 ( V_1 , V_22 ,
V_11 | ( ( V_10 & 0xf ) << 12 ) ) ;
break;
case 12 :
V_11 = F_8 ( V_1 , V_27 )
& ~ V_28 ;
F_9 ( V_1 , V_27 ,
V_11 | ( ( V_10 & 0xf ) << 0 ) ) ;
break;
default:
F_5 ( V_1 ) ;
return - V_29 ;
}
F_5 ( V_1 ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_1 , int V_2 , int V_30 )
{
if ( V_30 )
return F_4 ( V_1 ,
V_31 ,
1 << V_2 ) ;
else
return F_3 ( V_1 ,
V_31 ,
1 << V_2 ) ;
}
static int F_11 ( struct V_1 * V_1 , int V_2 , int V_32 )
{
if ( V_32 )
return F_4 ( V_1 ,
V_33 ,
1 << V_2 ) ;
else
return F_3 ( V_1 ,
V_33 ,
1 << V_2 ) ;
}
static int F_12 ( struct V_1 * V_1 , int V_2 , int V_34 )
{
if ( V_34 == V_35 )
return F_4 ( V_1 ,
V_36 ,
1 << V_2 ) ;
else
return F_3 ( V_1 ,
V_36 ,
1 << V_2 ) ;
}
static int F_13 ( struct V_1 * V_1 , int V_2 , int V_37 )
{
if ( V_37 == V_38 )
return F_4 ( V_1 , V_39 , 1 << V_2 ) ;
else
return F_3 ( V_1 ,
V_39 , 1 << V_2 ) ;
}
int F_14 ( struct V_1 * V_1 , int V_2 , int V_3 , int V_10 ,
int V_34 , int V_40 , int V_37 , int V_41 )
{
if ( V_40 == V_42 ) {
if ( F_10 ( V_1 , V_2 , 0 ) )
goto V_43;
if ( F_11 ( V_1 , V_2 , 0 ) )
goto V_43;
} else if ( V_40 == V_44 ) {
if ( F_11 ( V_1 , V_2 , 0 ) )
goto V_43;
if ( F_10 ( V_1 , V_2 , 1 ) )
goto V_43;
} else if ( V_40 == V_45 ) {
if ( F_10 ( V_1 , V_2 , 0 ) )
goto V_43;
if ( F_11 ( V_1 , V_2 , 1 ) )
goto V_43;
}
if ( F_13 ( V_1 , V_2 , V_37 ) )
goto V_43;
if ( F_12 ( V_1 , V_2 , V_34 ) )
goto V_43;
if ( F_6 ( V_1 , V_2 , V_41 ) )
goto V_43;
if ( F_1 ( V_1 , V_2 , V_3 ) )
goto V_43;
return F_7 ( V_1 , V_2 , V_10 ) ;
V_43:
return - V_46 ;
}
