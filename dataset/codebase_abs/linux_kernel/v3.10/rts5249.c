static T_1 F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
F_2 ( V_2 , V_4 , & V_3 ) ;
return V_3 & 0x0F ;
}
static int F_3 ( struct V_1 * V_2 )
{
F_4 ( V_2 ) ;
F_5 ( V_2 , V_5 , V_6 , 0x02 , 0x02 ) ;
F_5 ( V_2 , V_5 , V_7 , 0x03 , 0x00 ) ;
F_5 ( V_2 , V_5 , V_7 , 0x03 , 0x01 ) ;
F_5 ( V_2 , V_5 , V_8 , 0x0F , 0x02 ) ;
F_5 ( V_2 , V_5 ,
V_9 , 0xFF , 0x99 ) ;
F_5 ( V_2 , V_5 ,
V_10 , 0xFF , 0x99 ) ;
F_5 ( V_2 , V_5 ,
V_11 , 0xFF , 0x92 ) ;
return F_6 ( V_2 , 100 ) ;
}
static int F_7 ( struct V_1 * V_2 )
{
int V_12 ;
V_12 = F_8 ( V_2 , V_13 , 0xFE46 ) ;
if ( V_12 < 0 )
return V_12 ;
F_9 ( 1 ) ;
return F_8 ( V_2 , V_14 , 0x05C0 ) ;
}
static int F_10 ( struct V_1 * V_2 )
{
return F_11 ( V_2 , V_6 , 0x02 , 0x02 ) ;
}
static int F_12 ( struct V_1 * V_2 )
{
return F_11 ( V_2 , V_6 , 0x02 , 0x00 ) ;
}
static int F_13 ( struct V_1 * V_2 )
{
return F_11 ( V_2 , V_8 , 0x08 , 0x08 ) ;
}
static int F_14 ( struct V_1 * V_2 )
{
return F_11 ( V_2 , V_8 , 0x08 , 0x00 ) ;
}
static int F_15 ( struct V_1 * V_2 , int V_15 )
{
int V_12 ;
F_4 ( V_2 ) ;
F_5 ( V_2 , V_5 , V_16 ,
V_17 , V_18 ) ;
F_5 ( V_2 , V_5 , V_19 ,
V_20 , 0x02 ) ;
V_12 = F_6 ( V_2 , 100 ) ;
if ( V_12 < 0 )
return V_12 ;
F_9 ( 5 ) ;
F_4 ( V_2 ) ;
F_5 ( V_2 , V_5 , V_16 ,
V_17 , V_21 ) ;
F_5 ( V_2 , V_5 , V_19 ,
V_20 , 0x06 ) ;
V_12 = F_6 ( V_2 , 100 ) ;
if ( V_12 < 0 )
return V_12 ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 , int V_15 )
{
F_4 ( V_2 ) ;
F_5 ( V_2 , V_5 , V_16 ,
V_17 , V_22 ) ;
F_5 ( V_2 , V_5 , V_19 ,
V_20 , 0x00 ) ;
return F_6 ( V_2 , 100 ) ;
}
static int F_17 ( struct V_1 * V_2 , T_1 V_23 )
{
int V_12 ;
T_1 V_24 , V_25 , V_26 ;
if ( V_23 == V_27 ) {
V_12 = F_8 ( V_2 , V_28 , 0x4FC0 | 0x24 ) ;
if ( V_12 < 0 )
return V_12 ;
V_24 = 0x99 ;
V_25 = 0x99 ;
V_26 = 0x92 ;
} else if ( V_23 == V_29 ) {
V_12 = F_8 ( V_2 , V_30 , 0x3C02 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = F_8 ( V_2 , V_28 , 0x4C40 | 0x24 ) ;
if ( V_12 < 0 )
return V_12 ;
V_24 = 0xb3 ;
V_25 = 0xb3 ;
V_26 = 0xb3 ;
} else {
return - V_31 ;
}
F_4 ( V_2 ) ;
F_5 ( V_2 , V_5 , V_9 ,
0xFF , V_24 ) ;
F_5 ( V_2 , V_5 , V_10 ,
0xFF , V_25 ) ;
F_5 ( V_2 , V_5 , V_11 ,
0xFF , V_26 ) ;
return F_6 ( V_2 , 100 ) ;
}
void F_18 ( struct V_1 * V_2 )
{
V_2 -> V_32 = V_33 | V_34 ;
V_2 -> V_35 = 2 ;
V_2 -> V_36 = & V_37 ;
V_2 -> V_38 = F_1 ( V_2 ) ;
V_2 -> V_39 = V_40 ;
V_2 -> V_41 = V_42 ;
V_2 -> V_43 = V_44 ;
V_2 -> V_45 = V_46 ;
}
