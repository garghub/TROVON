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
return F_6 ( V_2 , 100 ) ;
}
static int F_7 ( struct V_1 * V_2 )
{
return F_8 ( V_2 , 0x00 , 0xBA42 ) ;
}
static int F_9 ( struct V_1 * V_2 )
{
return F_10 ( V_2 , V_6 , 0x02 , 0x02 ) ;
}
static int F_11 ( struct V_1 * V_2 )
{
return F_10 ( V_2 , V_6 , 0x02 , 0x00 ) ;
}
static int F_12 ( struct V_1 * V_2 )
{
return F_10 ( V_2 , V_8 , 0x08 , 0x08 ) ;
}
static int F_13 ( struct V_1 * V_2 )
{
return F_10 ( V_2 , V_8 , 0x08 , 0x00 ) ;
}
static int F_14 ( struct V_1 * V_2 , int V_9 )
{
int V_10 ;
F_4 ( V_2 ) ;
F_5 ( V_2 , V_5 , V_11 ,
V_12 , V_13 ) ;
F_5 ( V_2 , V_5 , V_14 ,
V_15 , 0x02 ) ;
V_10 = F_6 ( V_2 , 100 ) ;
if ( V_10 < 0 )
return V_10 ;
F_15 ( 150 ) ;
F_4 ( V_2 ) ;
F_5 ( V_2 , V_5 , V_11 ,
V_12 , V_16 ) ;
F_5 ( V_2 , V_5 , V_14 ,
V_15 , 0x06 ) ;
V_10 = F_6 ( V_2 , 100 ) ;
if ( V_10 < 0 )
return V_10 ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 , int V_9 )
{
F_4 ( V_2 ) ;
F_5 ( V_2 , V_5 , V_11 ,
V_12 | V_17 ,
V_18 | V_19 ) ;
F_5 ( V_2 , V_5 , V_14 ,
V_15 , 0X00 ) ;
return F_6 ( V_2 , 100 ) ;
}
static int F_17 ( struct V_1 * V_2 , T_1 V_20 )
{
int V_10 ;
if ( V_20 == V_21 ) {
V_10 = F_10 ( V_2 ,
V_22 , 0x07 , V_23 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_8 ( V_2 , 0x08 , 0x4FC0 | 0x24 ) ;
if ( V_10 < 0 )
return V_10 ;
} else if ( V_20 == V_24 ) {
V_10 = F_10 ( V_2 ,
V_22 , 0x07 , V_25 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_8 ( V_2 , 0x08 , 0x4C40 | 0x24 ) ;
if ( V_10 < 0 )
return V_10 ;
} else {
return - V_26 ;
}
return 0 ;
}
void F_18 ( struct V_1 * V_2 )
{
V_2 -> V_27 = V_28 | V_29 ;
V_2 -> V_30 = 2 ;
V_2 -> V_31 = & V_32 ;
V_2 -> V_33 = F_1 ( V_2 ) ;
if ( V_2 -> V_33 == V_34 ) {
V_2 -> V_35 = V_36 ;
V_2 -> V_37 = V_38 ;
} else {
V_2 -> V_35 = V_39 ;
V_2 -> V_37 = V_40 ;
}
V_2 -> V_41 = V_42 ;
V_2 -> V_43 = V_44 ;
}
