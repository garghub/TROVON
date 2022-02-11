static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_3 =
F_2 ( V_2 -> V_4 , struct V_3 , V_5 ) ;
int V_6 = - V_7 ;
switch ( V_2 -> V_8 ) {
case V_9 :
if ( ! V_3 -> V_10 )
return 0 ;
V_6 = F_3 ( V_3 , V_2 -> V_11 ) ;
break;
case V_12 :
if ( ! V_3 -> V_10 )
return 0 ;
V_6 = F_4 ( V_3 , V_2 -> V_11 ) ;
break;
case V_13 :
V_6 = F_5 ( V_3 , V_2 -> V_11 ) ;
break;
case V_14 :
V_6 = F_6 ( V_3 , V_2 -> V_11 ) ;
break;
}
return V_6 ;
}
static int F_7 ( struct V_15 * V_15 )
{
T_1 V_16 ;
int V_6 ;
V_6 = F_8 ( V_15 , V_17 , & V_16 ) ;
if ( V_6 < 0 )
return - V_18 ;
if ( V_16 != 0x19 )
return - V_18 ;
F_9 ( L_1 ) ;
V_15 -> V_3 . V_19 . V_20 = V_21 ;
V_15 -> V_3 . V_19 . V_22 = F_10 ( V_21 ) ;
return 0 ;
}
static int F_11 ( struct V_15 * V_15 )
{
struct V_23 * V_24 = & V_15 -> V_3 . V_5 ;
F_12 ( V_24 , 2 ) ;
F_13 ( V_24 , & V_25 ,
V_14 , 0 , 32768 , 1 , 20000 ) ;
F_13 ( V_24 , & V_25 ,
V_13 , 0 , 15 , 1 , 10 ) ;
return V_24 -> error ;
}
static int F_14 ( struct V_15 * V_15 )
{
int V_6 = 0 , V_26 ;
for ( V_26 = 0 ; V_26 < F_10 ( V_27 ) ; V_26 ++ )
F_15 ( V_15 , V_27 [ V_26 ] . V_28 , V_27 [ V_26 ] . V_16 ) ;
V_6 = F_16 ( V_15 , ( V_29 * ) V_30 ,
F_10 ( V_30 ) ) ;
return ( V_6 < 0 ) ? V_6 : 0 ;
}
static int F_17 ( struct V_15 * V_15 )
{
int V_6 ;
struct V_3 * V_3 = (struct V_3 * ) V_15 ;
struct V_19 * V_19 = & V_15 -> V_3 . V_19 ;
T_2 V_31 = V_19 -> V_20 [ V_15 -> V_3 . V_32 ] . V_31 ;
if ( V_31 & V_33 ) {
F_18 ( V_34 , L_2 ) ;
F_15 ( V_15 , V_35 , 0x02 ) ;
F_15 ( V_15 , V_36 , 0x06 ) ;
F_15 ( V_15 , V_37 , 0x10 ) ;
} else {
F_15 ( V_15 , V_35 , 0x01 ) ;
F_15 ( V_15 , V_36 , 0x0a ) ;
F_15 ( V_15 , V_37 , 0x00 ) ;
}
V_6 = F_15 ( V_15 , V_38 , V_39 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_19 ( V_15 , V_40 , 0 ) ;
if ( V_6 < 0 )
return V_6 ;
F_18 ( V_41 , L_3 ) ;
return 0 ;
}
static int F_20 ( struct V_15 * V_15 )
{
struct V_3 * V_3 = (struct V_3 * ) V_15 ;
int V_6 ;
V_6 = F_15 ( V_15 , V_38 , V_42 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_19 ( V_15 , V_40 , V_43 ) ;
if ( V_6 < 0 )
return V_6 ;
F_18 ( V_41 , L_4 ) ;
return 0 ;
}
static int F_21 ( struct V_15 * V_15 )
{
V_29 V_26 ;
int V_6 = 0 ;
F_9 ( L_5 ) ;
for ( V_26 = 0 ; V_26 < 0xff && ! V_6 ; V_26 ++ ) {
T_1 V_16 ;
V_6 = F_8 ( V_15 , V_26 , & V_16 ) ;
F_9 ( L_6 , V_26 , V_16 ) ;
}
return ( V_6 < 0 ) ? V_6 : 0 ;
}
static int F_3 ( struct V_3 * V_3 , T_3 V_11 )
{
int V_6 ;
T_1 V_44 ;
struct V_15 * V_15 = (struct V_15 * ) V_3 ;
V_6 = F_8 ( V_15 , V_45 , & V_44 ) ;
if ( V_6 < 0 )
return V_6 ;
if ( V_11 )
V_44 |= V_46 ;
else
V_44 &= ~ V_46 ;
F_18 ( V_34 , L_7 , V_11 ) ;
V_6 = F_19 ( V_15 , V_45 , V_44 ) ;
return ( V_6 < 0 ) ? V_6 : 0 ;
}
static int F_4 ( struct V_3 * V_3 , T_3 V_11 )
{
int V_6 ;
T_1 V_44 ;
struct V_15 * V_15 = (struct V_15 * ) V_3 ;
V_6 = F_8 ( V_15 , V_45 , & V_44 ) ;
if ( V_6 < 0 )
return V_6 ;
if ( V_11 )
V_44 |= V_47 ;
else
V_44 &= ~ V_47 ;
F_18 ( V_34 , L_8 , V_11 ) ;
V_6 = F_19 ( V_15 , V_45 , V_44 ) ;
return ( V_6 < 0 ) ? V_6 : 0 ;
}
static int F_5 ( struct V_3 * V_3 , T_3 V_11 )
{
int V_6 ;
struct V_15 * V_15 = (struct V_15 * ) V_3 ;
F_18 ( V_34 , L_9 , V_11 ) ;
V_6 = F_19 ( V_15 , V_48 , 0xf0 | ( V_11 & 0xf ) ) ;
return ( V_6 < 0 ) ? V_6 : 0 ;
}
static int F_6 ( struct V_3 * V_3 , T_3 V_11 )
{
int V_6 ;
struct V_15 * V_15 = (struct V_15 * ) V_3 ;
unsigned int V_49 , V_50 ;
V_11 = ( V_11 * V_11 >> 14 ) + V_11 / 4 ;
V_49 = V_11 % V_51 ;
V_50 = F_22 ( 512 , V_11 / V_51 ) ;
F_18 ( V_34 , L_10 ,
V_50 , V_49 ) ;
V_6 = F_19 ( V_15 , V_52 , V_49 >> 8 ) ;
if ( V_6 < 0 )
goto V_53;
V_6 = F_19 ( V_15 , V_54 , V_49 & 0xff ) ;
if ( V_6 < 0 )
goto V_53;
V_6 = F_19 ( V_15 , V_55 , V_50 >> 8 ) ;
if ( V_6 < 0 )
goto V_53;
V_6 = F_19 ( V_15 , V_56 , V_50 & 0xff ) ;
V_53:
return V_6 ;
}
