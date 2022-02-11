static void F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
T_1 V_4 [ 4 ] [ 3 ] = {
{ 0x13 , 0x13 , 0x13 } ,
{ 0x96 , 0x96 , 0x96 } ,
{ 0x7F , 0x7F , 0x7F } ,
{ 0x96 , 0x96 , 0x96 } ,
} ;
T_1 V_5 [ 4 ] [ 3 ] = {
{ 0x99 , 0x99 , 0x99 } ,
{ 0xAA , 0xAA , 0xAA } ,
{ 0xFE , 0xFE , 0xFE } ,
{ 0xB3 , 0xB3 , 0xB3 } ,
} ;
T_1 ( * V_6 ) [ 3 ] , V_7 ;
if ( V_3 == V_8 ) {
V_6 = V_4 ;
V_7 = V_2 -> V_9 ;
} else {
V_6 = V_5 ;
V_7 = V_2 -> V_10 ;
}
F_2 ( V_2 , V_11 , V_12 ,
0xFF , V_6 [ V_7 ] [ 0 ] ) ;
F_2 ( V_2 , V_11 , V_13 ,
0xFF , V_6 [ V_7 ] [ 1 ] ) ;
F_2 ( V_2 , V_11 , V_14 ,
0xFF , V_6 [ V_7 ] [ 2 ] ) ;
}
static void F_3 ( struct V_1 * V_2 )
{
T_2 V_15 ;
F_4 ( V_2 , V_16 , & V_15 ) ;
F_5 ( V_2 , L_1 , V_16 , V_15 ) ;
if ( ! F_6 ( V_15 ) )
return;
V_2 -> V_17 = F_7 ( V_15 ) ;
V_2 -> V_10 = F_8 ( V_15 ) ;
V_2 -> V_18 &= 0x3F ;
V_2 -> V_18 |= F_9 ( V_15 ) ;
F_4 ( V_2 , V_19 , & V_15 ) ;
F_5 ( V_2 , L_1 , V_19 , V_15 ) ;
V_2 -> V_9 = F_10 ( V_15 ) ;
if ( F_11 ( V_15 ) )
V_2 -> V_20 |= V_21 ;
}
static void F_12 ( struct V_1 * V_2 , T_1 V_22 )
{
F_13 ( V_2 , V_23 + 1 , 0xFF , 0 ) ;
F_13 ( V_2 , V_23 + 2 , 0xFF , 0 ) ;
F_13 ( V_2 , V_23 + 3 , 0x01 , 0 ) ;
if ( V_22 == V_24 )
F_13 ( V_2 , V_25 , 0x10 , 0x10 ) ;
F_13 ( V_2 , V_26 , 0x03 , 0x03 ) ;
}
static int F_14 ( struct V_1 * V_2 )
{
T_3 V_27 ;
F_15 ( V_2 ) ;
F_2 ( V_2 , V_11 , V_28 , 0x02 , 0x02 ) ;
F_2 ( V_2 , V_11 , V_29 , 0x3F , 0 ) ;
F_2 ( V_2 , V_11 , V_30 , 0x03 , 0x00 ) ;
F_2 ( V_2 , V_11 , V_30 , 0x03 , 0x01 ) ;
F_2 ( V_2 , V_11 , V_31 , 0x0F , 0x02 ) ;
F_16 ( V_2 -> V_32 , V_33 , & V_27 ) ;
if ( V_27 & V_34 )
F_2 ( V_2 , V_11 , V_35 , 0xFF , 0xA3 ) ;
F_2 ( V_2 , V_11 , V_36 , 0x03 , 0x03 ) ;
F_1 ( V_2 , V_8 ) ;
if ( V_2 -> V_20 & V_21 )
F_2 ( V_2 , V_11 , V_37 , 0xB8 , 0xB8 ) ;
else
F_2 ( V_2 , V_11 , V_37 , 0xB8 , 0x88 ) ;
F_2 ( V_2 , V_11 , V_25 , 0x10 , 0x00 ) ;
return F_17 ( V_2 , 100 ) ;
}
static int F_18 ( struct V_1 * V_2 )
{
int V_38 ;
V_38 = F_13 ( V_2 , V_25 , V_39 , 0x00 ) ;
if ( V_38 < 0 )
return V_38 ;
return F_19 ( V_2 , 0x00 , 0xBA42 ) ;
}
static int F_20 ( struct V_1 * V_2 )
{
return F_13 ( V_2 , V_28 , 0x02 , 0x02 ) ;
}
static int F_21 ( struct V_1 * V_2 )
{
return F_13 ( V_2 , V_28 , 0x02 , 0x00 ) ;
}
static int F_22 ( struct V_1 * V_2 )
{
return F_13 ( V_2 , V_31 , 0x08 , 0x08 ) ;
}
static int F_23 ( struct V_1 * V_2 )
{
return F_13 ( V_2 , V_31 , 0x08 , 0x00 ) ;
}
static int F_24 ( struct V_1 * V_2 , int V_40 )
{
int V_38 ;
F_15 ( V_2 ) ;
F_2 ( V_2 , V_11 , V_41 ,
V_42 , V_43 ) ;
F_2 ( V_2 , V_11 , V_44 ,
V_45 , 0x02 ) ;
V_38 = F_17 ( V_2 , 100 ) ;
if ( V_38 < 0 )
return V_38 ;
F_25 ( 150 ) ;
F_15 ( V_2 ) ;
F_2 ( V_2 , V_11 , V_41 ,
V_42 , V_46 ) ;
F_2 ( V_2 , V_11 , V_44 ,
V_45 , 0x06 ) ;
V_38 = F_17 ( V_2 , 100 ) ;
if ( V_38 < 0 )
return V_38 ;
return 0 ;
}
static int F_26 ( struct V_1 * V_2 , int V_40 )
{
F_15 ( V_2 ) ;
F_2 ( V_2 , V_11 , V_41 ,
V_42 | V_47 ,
V_48 | V_49 ) ;
F_2 ( V_2 , V_11 , V_44 ,
V_45 , 0X00 ) ;
return F_17 ( V_2 , 100 ) ;
}
static int F_27 ( struct V_1 * V_2 , T_1 V_3 )
{
int V_38 ;
if ( V_3 == V_8 ) {
V_38 = F_19 ( V_2 , 0x08 , 0x4FC0 | 0x24 ) ;
if ( V_38 < 0 )
return V_38 ;
} else if ( V_3 == V_50 ) {
V_38 = F_19 ( V_2 , 0x11 , 0x3C02 ) ;
if ( V_38 < 0 )
return V_38 ;
V_38 = F_19 ( V_2 , 0x08 , 0x4C80 | 0x24 ) ;
if ( V_38 < 0 )
return V_38 ;
} else {
return - V_51 ;
}
F_15 ( V_2 ) ;
F_1 ( V_2 , V_3 ) ;
return F_17 ( V_2 , 100 ) ;
}
void F_28 ( struct V_1 * V_2 )
{
V_2 -> V_52 = V_53 | V_54 ;
V_2 -> V_55 = 2 ;
V_2 -> V_56 = & V_57 ;
V_2 -> V_20 = 0 ;
V_2 -> V_18 = V_58 ;
V_2 -> V_10 = V_59 ;
V_2 -> V_9 = V_59 ;
V_2 -> V_17 = V_60 ;
V_2 -> V_61 = F_29 ( 27 , 27 , 15 ) ;
V_2 -> V_62 = F_29 ( 30 , 7 , 7 ) ;
V_2 -> V_63 = V_64 ;
V_2 -> V_65 = V_66 ;
V_2 -> V_67 = V_68 ;
V_2 -> V_69 = V_70 ;
}
