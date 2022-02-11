static int F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
F_2 ( V_2 ) ;
F_3 ( V_2 , V_4 , V_5 , 0x02 , 0x02 ) ;
F_3 ( V_2 , V_4 , V_6 , 0x03 , 0x00 ) ;
F_3 ( V_2 , V_4 , V_6 , 0x03 , 0x01 ) ;
F_3 ( V_2 , V_4 , V_7 , 0x0F , 0x02 ) ;
F_4 ( V_2 -> V_8 , V_9 , & V_3 ) ;
if ( V_3 & V_10 )
F_3 ( V_2 , V_4 , V_11 , 0xFF , 0xA3 ) ;
F_3 ( V_2 , V_4 , V_12 , 0x03 , 0x03 ) ;
F_3 ( V_2 , V_4 , 0xFF03 , 0x08 , 0x08 ) ;
F_3 ( V_2 , V_4 ,
V_13 , 0xFF , 0x96 ) ;
F_3 ( V_2 , V_4 ,
V_14 , 0xFF , 0x96 ) ;
F_3 ( V_2 , V_4 ,
V_15 , 0xFF , 0x96 ) ;
return F_5 ( V_2 , 100 ) ;
}
static int F_6 ( struct V_1 * V_2 )
{
return F_7 ( V_2 , 0x00 , 0xBA42 ) ;
}
static int F_8 ( struct V_1 * V_2 )
{
return F_9 ( V_2 , V_5 , 0x02 , 0x02 ) ;
}
static int F_10 ( struct V_1 * V_2 )
{
return F_9 ( V_2 , V_5 , 0x02 , 0x00 ) ;
}
static int F_11 ( struct V_1 * V_2 )
{
return F_9 ( V_2 , V_7 , 0x08 , 0x08 ) ;
}
static int F_12 ( struct V_1 * V_2 )
{
return F_9 ( V_2 , V_7 , 0x08 , 0x00 ) ;
}
static int F_13 ( struct V_1 * V_2 , int V_16 )
{
int V_17 ;
F_2 ( V_2 ) ;
F_3 ( V_2 , V_4 , V_18 ,
V_19 , V_20 ) ;
F_3 ( V_2 , V_4 , V_21 ,
V_22 , 0x02 ) ;
V_17 = F_5 ( V_2 , 100 ) ;
if ( V_17 < 0 )
return V_17 ;
F_14 ( 150 ) ;
F_2 ( V_2 ) ;
F_3 ( V_2 , V_4 , V_18 ,
V_19 , V_23 ) ;
F_3 ( V_2 , V_4 , V_21 ,
V_22 , 0x06 ) ;
V_17 = F_5 ( V_2 , 100 ) ;
if ( V_17 < 0 )
return V_17 ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 , int V_16 )
{
F_2 ( V_2 ) ;
F_3 ( V_2 , V_4 , V_18 ,
V_19 | V_24 ,
V_25 | V_26 ) ;
F_3 ( V_2 , V_4 , V_21 ,
V_22 , 0X00 ) ;
return F_5 ( V_2 , 100 ) ;
}
static int F_16 ( struct V_1 * V_2 , T_2 V_27 )
{
int V_17 ;
T_2 V_28 ;
if ( V_27 == V_29 ) {
V_17 = F_7 ( V_2 , 0x08 , 0x4FC0 | 0x24 ) ;
if ( V_17 < 0 )
return V_17 ;
V_28 = 0x96 ;
} else if ( V_27 == V_30 ) {
V_17 = F_7 ( V_2 , 0x11 , 0x3C02 ) ;
if ( V_17 < 0 )
return V_17 ;
V_17 = F_7 ( V_2 , 0x08 , 0x4C80 | 0x24 ) ;
if ( V_17 < 0 )
return V_17 ;
V_28 = 0xB3 ;
} else {
return - V_31 ;
}
F_2 ( V_2 ) ;
F_3 ( V_2 , V_4 , V_13 ,
0xFF , V_28 ) ;
F_3 ( V_2 , V_4 , V_14 ,
0xFF , V_28 ) ;
F_3 ( V_2 , V_4 , V_15 ,
0xFF , V_28 ) ;
return F_5 ( V_2 , 100 ) ;
}
void F_17 ( struct V_1 * V_2 )
{
V_2 -> V_32 = V_33 | V_34 ;
V_2 -> V_35 = 2 ;
V_2 -> V_36 = & V_37 ;
V_2 -> V_38 = V_39 ;
V_2 -> V_40 = V_41 ;
V_2 -> V_42 = V_43 ;
V_2 -> V_44 = V_45 ;
}
