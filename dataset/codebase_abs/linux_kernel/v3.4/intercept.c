static int F_1 ( struct V_1 * V_2 )
{
int V_3 = ( V_2 -> V_4 . V_5 -> V_6 & 0x00f0 ) >> 4 ;
int V_7 = V_2 -> V_4 . V_5 -> V_6 & 0x000f ;
int V_8 = V_2 -> V_4 . V_5 -> V_9 >> 28 ;
int V_10 = ( ( V_2 -> V_4 . V_5 -> V_9 & 0x0fff0000 ) >> 16 ) +
( ( V_2 -> V_4 . V_5 -> V_9 & 0xff00 ) << 4 ) ;
T_1 V_11 ;
int V_12 , V_13 ;
V_2 -> V_14 . V_15 ++ ;
if ( ( V_2 -> V_4 . V_5 -> V_9 & 0xff ) != 0x2f )
return - V_16 ;
V_11 = V_10 ;
if ( V_8 )
V_11 += V_2 -> V_17 -> V_18 . V_19 . V_20 [ V_8 ] ;
if ( V_11 & 7 )
return F_2 ( V_2 , V_21 ) ;
V_12 = V_3 ;
F_3 ( V_2 , 5 , L_1 , V_3 , V_7 , V_8 ,
V_10 ) ;
do {
V_13 = F_4 ( V_2 , V_11 ,
& V_2 -> V_4 . V_5 -> V_22 [ V_12 ] ) ;
if ( V_13 == - V_23 ) {
F_2 ( V_2 , V_24 ) ;
break;
}
V_11 += 8 ;
if ( V_12 == V_7 )
break;
V_12 = ( V_12 + 1 ) % 16 ;
} while ( 1 );
return 0 ;
}
static int F_5 ( struct V_1 * V_2 )
{
int V_3 = ( V_2 -> V_4 . V_5 -> V_6 & 0x00f0 ) >> 4 ;
int V_7 = V_2 -> V_4 . V_5 -> V_6 & 0x000f ;
int V_8 = V_2 -> V_4 . V_5 -> V_9 >> 28 ;
int V_10 = ( ( V_2 -> V_4 . V_5 -> V_9 & 0x0fff0000 ) >> 16 ) ;
T_1 V_11 ;
T_2 V_25 = 0 ;
int V_12 , V_13 ;
V_2 -> V_14 . V_26 ++ ;
V_11 = V_10 ;
if ( V_8 )
V_11 += V_2 -> V_17 -> V_18 . V_19 . V_20 [ V_8 ] ;
if ( V_11 & 3 )
return F_2 ( V_2 , V_21 ) ;
F_3 ( V_2 , 5 , L_2 , V_3 , V_7 , V_8 ,
V_10 ) ;
V_12 = V_3 ;
do {
V_13 = F_6 ( V_2 , V_11 , & V_25 ) ;
if ( V_13 == - V_23 ) {
F_2 ( V_2 , V_24 ) ;
break;
}
V_2 -> V_4 . V_5 -> V_22 [ V_12 ] &= 0xffffffff00000000ul ;
V_2 -> V_4 . V_5 -> V_22 [ V_12 ] |= V_25 ;
V_11 += 4 ;
if ( V_12 == V_7 )
break;
V_12 = ( V_12 + 1 ) % 16 ;
} while ( 1 );
return 0 ;
}
static int F_7 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_4 . V_5 -> V_27 ) {
case 0x0 :
V_2 -> V_14 . V_28 ++ ;
break;
case 0x10 :
V_2 -> V_14 . V_29 ++ ;
break;
case 0x14 :
V_2 -> V_14 . V_30 ++ ;
break;
default:
break;
}
return 0 ;
}
static int F_8 ( struct V_1 * V_2 )
{
int V_13 = 0 ;
V_2 -> V_14 . V_31 ++ ;
F_9 ( & V_2 -> V_4 . V_32 . V_33 ) ;
if ( V_2 -> V_4 . V_32 . V_34 & V_35 ) {
V_2 -> V_4 . V_32 . V_34 &= ~ V_35 ;
V_13 = V_36 ;
V_2 -> V_17 -> V_37 = V_38 ;
}
if ( V_2 -> V_4 . V_32 . V_34 & V_39 ) {
F_10 ( V_40 ,
& V_2 -> V_4 . V_5 -> V_41 ) ;
V_2 -> V_4 . V_32 . V_34 &= ~ V_39 ;
F_3 ( V_2 , 3 , L_3 , L_4 ) ;
V_13 = - V_16 ;
}
if ( V_2 -> V_4 . V_32 . V_34 & V_42 ) {
V_2 -> V_4 . V_32 . V_34 &= ~ V_42 ;
F_11 ( & V_2 -> V_4 . V_32 . V_33 ) ;
V_13 = F_12 ( V_2 ,
V_43 ) ;
if ( V_13 >= 0 )
V_13 = - V_16 ;
} else
F_11 ( & V_2 -> V_4 . V_32 . V_33 ) ;
return V_13 ;
}
static int F_13 ( struct V_1 * V_2 )
{
unsigned long V_44 ;
int V_45 = V_2 -> V_4 . V_5 -> V_9 >> 16 ;
int V_13 ;
V_2 -> V_14 . V_46 ++ ;
if ( V_45 == 0x37 ) {
V_44 = F_14 ( V_2 -> V_4 . V_5 -> V_47 ,
V_2 -> V_4 . V_48 ) ;
if ( F_15 ( V_44 ) ) {
V_13 = - V_16 ;
goto V_49;
}
V_13 = F_16 ( ( char V_50 * ) V_44 ,
V_51 ) ;
if ( V_13 ) {
V_13 = - V_16 ;
goto V_49;
}
V_44 = F_14 ( V_2 -> V_4 . V_5 -> V_47 + V_51 ,
V_2 -> V_4 . V_48 ) ;
if ( F_15 ( V_44 ) ) {
V_13 = - V_16 ;
goto V_49;
}
V_13 = F_16 ( ( char V_50 * ) V_44 ,
V_51 ) ;
if ( V_13 ) {
V_13 = - V_16 ;
goto V_49;
}
} else
V_13 = - V_16 ;
V_49:
if ( V_13 )
F_3 ( V_2 , 2 , L_5 ,
V_45 ) ;
return V_13 ;
}
static int F_17 ( struct V_1 * V_2 )
{
T_3 V_52 ;
V_2 -> V_14 . V_53 ++ ;
V_52 = V_54 [ V_2 -> V_4 . V_5 -> V_6 >> 8 ] ;
if ( V_52 )
return V_52 ( V_2 ) ;
return - V_16 ;
}
static int F_18 ( struct V_1 * V_2 )
{
V_2 -> V_14 . V_55 ++ ;
return F_2 ( V_2 , V_2 -> V_4 . V_5 -> V_56 ) ;
}
static int F_19 ( struct V_1 * V_2 )
{
int V_13 , V_57 ;
V_2 -> V_14 . V_58 ++ ;
V_13 = F_17 ( V_2 ) ;
V_57 = F_18 ( V_2 ) ;
if ( V_13 == - V_16 )
V_2 -> V_4 . V_5 -> V_27 = 0x04 ;
if ( V_13 )
return V_13 ;
return V_57 ;
}
int F_20 ( struct V_1 * V_2 )
{
T_3 V_59 ;
T_4 V_60 = V_2 -> V_4 . V_5 -> V_27 ;
if ( V_60 & 3 || ( V_60 >> 2 ) >= F_21 ( V_61 ) )
return - V_16 ;
V_59 = V_61 [ V_60 >> 2 ] ;
if ( V_59 )
return V_59 ( V_2 ) ;
return - V_16 ;
}
