static int F_1 ( struct V_1 * V_2 )
{
int V_3 = ( V_2 -> V_4 . V_5 -> V_6 & 0x00f0 ) >> 4 ;
int V_7 = V_2 -> V_4 . V_5 -> V_6 & 0x000f ;
T_1 V_8 ;
int V_9 , V_10 ;
V_2 -> V_11 . V_12 ++ ;
V_8 = F_2 ( V_2 ) ;
if ( V_8 & 7 )
return F_3 ( V_2 , V_13 ) ;
V_9 = V_3 ;
F_4 ( V_2 , 5 , L_1 , V_3 , V_7 ,
V_8 ) ;
F_5 ( V_2 , 1 , V_3 , V_7 , V_8 ) ;
do {
V_10 = F_6 ( V_2 , V_2 -> V_4 . V_5 -> V_14 [ V_9 ] ,
( T_1 V_15 * ) V_8 ) ;
if ( V_10 )
return F_3 ( V_2 , V_16 ) ;
V_8 += 8 ;
if ( V_9 == V_7 )
break;
V_9 = ( V_9 + 1 ) % 16 ;
} while ( 1 );
return 0 ;
}
static int F_7 ( struct V_1 * V_2 )
{
int V_3 = ( V_2 -> V_4 . V_5 -> V_6 & 0x00f0 ) >> 4 ;
int V_7 = V_2 -> V_4 . V_5 -> V_6 & 0x000f ;
T_1 V_8 ;
T_2 V_17 = 0 ;
int V_9 , V_10 ;
V_2 -> V_11 . V_18 ++ ;
V_8 = F_8 ( V_2 ) ;
if ( V_8 & 3 )
return F_3 ( V_2 , V_13 ) ;
F_4 ( V_2 , 5 , L_2 , V_3 , V_7 ,
V_8 ) ;
F_5 ( V_2 , 0 , V_3 , V_7 , V_8 ) ;
V_9 = V_3 ;
do {
V_10 = F_6 ( V_2 , V_17 , ( T_2 V_15 * ) V_8 ) ;
if ( V_10 )
return F_3 ( V_2 , V_16 ) ;
V_2 -> V_4 . V_5 -> V_14 [ V_9 ] &= 0xffffffff00000000ul ;
V_2 -> V_4 . V_5 -> V_14 [ V_9 ] |= V_17 ;
V_8 += 4 ;
if ( V_9 == V_7 )
break;
V_9 = ( V_9 + 1 ) % 16 ;
} while ( 1 );
return 0 ;
}
static int F_9 ( struct V_1 * V_2 )
{
T_3 V_19 ;
V_19 = V_20 [ V_2 -> V_4 . V_5 -> V_21 & 0xff ] ;
if ( V_19 )
return V_19 ( V_2 ) ;
return - V_22 ;
}
static int F_10 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_4 . V_5 -> V_23 ) {
case 0x0 :
V_2 -> V_11 . V_24 ++ ;
break;
case 0x10 :
V_2 -> V_11 . V_25 ++ ;
break;
case 0x14 :
V_2 -> V_11 . V_26 ++ ;
break;
default:
break;
}
return 0 ;
}
static int F_11 ( struct V_1 * V_2 )
{
int V_10 = 0 ;
V_2 -> V_11 . V_27 ++ ;
F_12 ( & V_2 -> V_4 . V_28 . V_29 ) ;
F_13 ( V_2 -> V_4 . V_28 . V_30 ) ;
if ( V_2 -> V_4 . V_28 . V_30 & V_31 ) {
V_2 -> V_4 . V_28 . V_30 &= ~ V_31 ;
V_10 = V_32 ;
V_2 -> V_33 -> V_34 = V_35 ;
}
if ( V_2 -> V_4 . V_28 . V_30 & V_36 ) {
F_14 ( V_37 ,
& V_2 -> V_4 . V_5 -> V_38 ) ;
V_2 -> V_4 . V_28 . V_30 &= ~ V_36 ;
F_4 ( V_2 , 3 , L_3 , L_4 ) ;
V_10 = - V_22 ;
}
if ( V_2 -> V_4 . V_28 . V_30 & V_39 ) {
V_2 -> V_4 . V_28 . V_30 &= ~ V_39 ;
F_15 ( & V_2 -> V_4 . V_28 . V_29 ) ;
V_10 = F_16 ( V_2 ,
V_40 ) ;
if ( V_10 >= 0 )
V_10 = - V_22 ;
} else
F_15 ( & V_2 -> V_4 . V_28 . V_29 ) ;
return V_10 ;
}
static int F_17 ( struct V_1 * V_2 )
{
unsigned long V_41 ;
int V_42 = V_2 -> V_4 . V_5 -> V_21 >> 16 ;
int V_10 ;
V_2 -> V_11 . V_43 ++ ;
F_18 ( V_2 , V_42 ) ;
if ( V_42 == 0x37 ) {
V_41 = F_19 ( V_2 -> V_4 . V_5 -> V_44 ,
V_2 -> V_4 . V_45 ) ;
if ( F_20 ( V_41 ) ) {
V_10 = - V_22 ;
goto V_46;
}
V_10 = F_21 ( ( char V_15 * ) V_41 ,
V_47 ) ;
if ( V_10 ) {
V_10 = - V_22 ;
goto V_46;
}
V_41 = F_19 ( V_2 -> V_4 . V_5 -> V_44 + V_47 ,
V_2 -> V_4 . V_45 ) ;
if ( F_20 ( V_41 ) ) {
V_10 = - V_22 ;
goto V_46;
}
V_10 = F_21 ( ( char V_15 * ) V_41 ,
V_47 ) ;
if ( V_10 ) {
V_10 = - V_22 ;
goto V_46;
}
} else
V_10 = - V_22 ;
V_46:
if ( V_10 )
F_4 ( V_2 , 2 , L_5 ,
V_42 ) ;
return V_10 ;
}
static int F_22 ( struct V_1 * V_2 )
{
T_3 V_19 ;
V_2 -> V_11 . V_48 ++ ;
F_23 ( V_2 ,
V_2 -> V_4 . V_5 -> V_6 ,
V_2 -> V_4 . V_5 -> V_21 ) ;
V_19 = V_49 [ V_2 -> V_4 . V_5 -> V_6 >> 8 ] ;
if ( V_19 )
return V_19 ( V_2 ) ;
return - V_22 ;
}
static int F_24 ( struct V_1 * V_2 )
{
V_2 -> V_11 . V_50 ++ ;
F_25 ( V_2 , V_2 -> V_4 . V_5 -> V_51 ) ;
return F_3 ( V_2 , V_2 -> V_4 . V_5 -> V_51 ) ;
}
static int F_26 ( struct V_1 * V_2 )
{
int V_10 , V_52 ;
V_2 -> V_11 . V_53 ++ ;
V_10 = F_22 ( V_2 ) ;
V_52 = F_24 ( V_2 ) ;
if ( V_10 == - V_22 )
V_2 -> V_4 . V_5 -> V_23 = 0x04 ;
if ( V_10 )
return V_10 ;
return V_52 ;
}
int F_27 ( struct V_1 * V_2 )
{
T_3 V_54 ;
T_4 V_55 = V_2 -> V_4 . V_5 -> V_23 ;
if ( V_55 & 3 || ( V_55 >> 2 ) >= F_28 ( V_56 ) )
return - V_22 ;
V_54 = V_56 [ V_55 >> 2 ] ;
if ( V_54 )
return V_54 ( V_2 ) ;
return - V_22 ;
}
