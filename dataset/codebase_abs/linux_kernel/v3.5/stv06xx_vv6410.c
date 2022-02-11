static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_3 =
F_2 ( V_2 -> V_4 , struct V_3 , V_5 ) ;
int V_6 = - V_7 ;
switch ( V_2 -> V_8 ) {
case V_9 :
V_6 = F_3 ( V_3 , V_2 -> V_10 ) ;
break;
case V_11 :
V_6 = F_4 ( V_3 , V_2 -> V_10 ) ;
break;
case V_12 :
V_6 = F_5 ( V_3 , V_2 -> V_10 ) ;
break;
case V_13 :
V_6 = F_6 ( V_3 , V_2 -> V_10 ) ;
break;
}
return V_6 ;
}
static int F_7 ( struct V_14 * V_14 )
{
T_1 V_15 ;
int V_6 ;
V_6 = F_8 ( V_14 , V_16 , & V_15 ) ;
if ( V_6 < 0 )
return - V_17 ;
if ( V_15 != 0x19 )
return - V_17 ;
F_9 ( L_1 ) ;
V_14 -> V_3 . V_18 . V_19 = V_20 ;
V_14 -> V_3 . V_18 . V_21 = F_10 ( V_20 ) ;
return 0 ;
}
static int F_11 ( struct V_14 * V_14 )
{
struct V_22 * V_23 = & V_14 -> V_3 . V_5 ;
F_12 ( V_23 , 4 ) ;
F_13 ( V_23 , & V_24 ,
V_9 , 0 , 1 , 1 , 0 ) ;
F_13 ( V_23 , & V_24 ,
V_11 , 0 , 1 , 1 , 0 ) ;
F_13 ( V_23 , & V_24 ,
V_13 , 0 , 32768 , 1 , 20000 ) ;
F_13 ( V_23 , & V_24 ,
V_12 , 0 , 15 , 1 , 10 ) ;
return V_23 -> error ;
}
static int F_14 ( struct V_14 * V_14 )
{
int V_6 = 0 , V_25 ;
for ( V_25 = 0 ; V_25 < F_10 ( V_26 ) ; V_25 ++ )
F_15 ( V_14 , V_26 [ V_25 ] . V_27 , V_26 [ V_25 ] . V_15 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_16 ( V_14 , ( V_28 * ) V_29 ,
F_10 ( V_29 ) ) ;
return ( V_6 < 0 ) ? V_6 : 0 ;
}
static int F_17 ( struct V_14 * V_14 )
{
int V_6 ;
struct V_18 * V_18 = & V_14 -> V_3 . V_18 ;
T_2 V_30 = V_18 -> V_19 [ V_14 -> V_3 . V_31 ] . V_30 ;
if ( V_30 & V_32 ) {
F_18 ( V_33 , L_2 ) ;
F_15 ( V_14 , V_34 , 0x02 ) ;
F_15 ( V_14 , V_35 , 0x06 ) ;
F_15 ( V_14 , V_36 , 0x10 ) ;
} else {
F_15 ( V_14 , V_34 , 0x01 ) ;
F_15 ( V_14 , V_35 , 0x0a ) ;
F_15 ( V_14 , V_36 , 0x00 ) ;
}
V_6 = F_15 ( V_14 , V_37 , V_38 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_19 ( V_14 , V_39 , 0 ) ;
if ( V_6 < 0 )
return V_6 ;
F_18 ( V_40 , L_3 ) ;
return 0 ;
}
static int F_20 ( struct V_14 * V_14 )
{
int V_6 ;
V_6 = F_15 ( V_14 , V_37 , V_41 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_19 ( V_14 , V_39 , V_42 ) ;
if ( V_6 < 0 )
return V_6 ;
F_18 ( V_40 , L_4 ) ;
return ( V_6 < 0 ) ? V_6 : 0 ;
}
static int F_21 ( struct V_14 * V_14 )
{
V_28 V_25 ;
int V_6 = 0 ;
F_9 ( L_5 ) ;
for ( V_25 = 0 ; V_25 < 0xff && ! V_6 ; V_25 ++ ) {
T_1 V_15 ;
V_6 = F_8 ( V_14 , V_25 , & V_15 ) ;
F_9 ( L_6 , V_25 , V_15 ) ;
}
return ( V_6 < 0 ) ? V_6 : 0 ;
}
static int F_3 ( struct V_3 * V_3 , T_3 V_10 )
{
int V_6 ;
T_1 V_43 ;
struct V_14 * V_14 = (struct V_14 * ) V_3 ;
V_6 = F_8 ( V_14 , V_44 , & V_43 ) ;
if ( V_6 < 0 )
return V_6 ;
if ( V_10 )
V_43 |= V_45 ;
else
V_43 &= ~ V_45 ;
F_18 ( V_46 , L_7 , V_10 ) ;
V_6 = F_19 ( V_14 , V_44 , V_43 ) ;
return ( V_6 < 0 ) ? V_6 : 0 ;
}
static int F_4 ( struct V_3 * V_3 , T_3 V_10 )
{
int V_6 ;
T_1 V_43 ;
struct V_14 * V_14 = (struct V_14 * ) V_3 ;
V_6 = F_8 ( V_14 , V_44 , & V_43 ) ;
if ( V_6 < 0 )
return V_6 ;
if ( V_10 )
V_43 |= V_47 ;
else
V_43 &= ~ V_47 ;
F_18 ( V_46 , L_8 , V_10 ) ;
V_6 = F_19 ( V_14 , V_44 , V_43 ) ;
return ( V_6 < 0 ) ? V_6 : 0 ;
}
static int F_5 ( struct V_3 * V_3 , T_3 V_10 )
{
int V_6 ;
struct V_14 * V_14 = (struct V_14 * ) V_3 ;
F_18 ( V_46 , L_9 , V_10 ) ;
V_6 = F_19 ( V_14 , V_48 , 0xf0 | ( V_10 & 0xf ) ) ;
return ( V_6 < 0 ) ? V_6 : 0 ;
}
static int F_6 ( struct V_3 * V_3 , T_3 V_10 )
{
int V_6 ;
struct V_14 * V_14 = (struct V_14 * ) V_3 ;
unsigned int V_49 , V_50 ;
V_10 = ( V_10 * V_10 >> 14 ) + V_10 / 4 ;
V_49 = V_10 % V_51 ;
V_50 = F_22 ( 512 , V_10 / V_51 ) ;
F_18 ( V_46 , L_10 ,
V_50 , V_49 ) ;
V_6 = F_19 ( V_14 , V_52 , V_49 >> 8 ) ;
if ( V_6 < 0 )
goto V_53;
V_6 = F_19 ( V_14 , V_54 , V_49 & 0xff ) ;
if ( V_6 < 0 )
goto V_53;
V_6 = F_19 ( V_14 , V_55 , V_50 >> 8 ) ;
if ( V_6 < 0 )
goto V_53;
V_6 = F_19 ( V_14 , V_56 , V_50 & 0xff ) ;
V_53:
return V_6 ;
}
