static T_1 F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
F_2 ( V_2 , V_4 , & V_3 ) ;
return V_3 & 0x0F ;
}
static int F_3 ( struct V_1 * V_2 )
{
return F_4 ( V_2 , V_5 ,
V_6 | V_7 , V_8 ) ;
}
static int F_5 ( struct V_1 * V_2 )
{
return F_4 ( V_2 , V_9 , 0x01 , 0x00 ) ;
}
static int F_6 ( struct V_1 * V_2 )
{
return F_4 ( V_2 , V_9 , 0x01 , 0x01 ) ;
}
static int F_7 ( struct V_1 * V_2 )
{
return F_4 ( V_2 , V_10 , 0xFF , 0x0D ) ;
}
static int F_8 ( struct V_1 * V_2 )
{
return F_4 ( V_2 , V_10 , 0x08 , 0x00 ) ;
}
static int F_9 ( struct V_1 * V_2 , int V_11 )
{
int V_12 ;
F_10 ( V_2 ) ;
F_11 ( V_2 , V_13 , V_14 ,
V_15 , V_16 ) ;
F_11 ( V_2 , V_13 , V_17 ,
V_18 , V_19 ) ;
V_12 = F_12 ( V_2 , 100 ) ;
if ( V_12 < 0 )
return V_12 ;
F_13 ( 150 ) ;
V_12 = F_4 ( V_2 , V_14 ,
V_15 , V_20 ) ;
if ( V_12 < 0 )
return V_12 ;
F_13 ( 150 ) ;
V_12 = F_4 ( V_2 , V_14 ,
V_15 , V_21 ) ;
if ( V_12 < 0 )
return V_12 ;
F_13 ( 150 ) ;
V_12 = F_4 ( V_2 , V_14 ,
V_15 , V_22 ) ;
if ( V_12 < 0 )
return V_12 ;
return F_4 ( V_2 , V_17 , V_18 , V_23 ) ;
}
static int F_14 ( struct V_1 * V_2 , int V_11 )
{
int V_12 ;
V_12 = F_4 ( V_2 , V_14 ,
V_15 , V_24 ) ;
if ( V_12 < 0 )
return V_12 ;
return F_4 ( V_2 , V_17 ,
V_18 , V_19 ) ;
}
static int F_15 ( struct V_1 * V_2 , T_1 V_25 )
{
T_1 V_26 , V_3 ;
int V_12 ;
V_26 = ( V_27 << V_28 ) | V_29 ;
if ( V_25 == V_30 ) {
V_12 = F_4 ( V_2 ,
V_31 , 0x07 , V_32 ) ;
if ( V_12 < 0 )
return V_12 ;
V_3 = ( V_33 << V_28 ) | V_34 ;
} else if ( V_25 == V_35 ) {
V_12 = F_4 ( V_2 ,
V_31 , 0x07 , V_36 ) ;
if ( V_12 < 0 )
return V_12 ;
V_3 = ( V_37 << V_28 ) | V_38 ;
} else {
return - V_39 ;
}
return F_4 ( V_2 , V_17 , V_26 , V_3 ) ;
}
static unsigned int F_16 ( struct V_1 * V_2 )
{
unsigned int V_40 ;
V_40 = F_17 ( V_2 , V_41 ) ;
V_40 &= V_42 ;
if ( ! V_40 ) {
F_4 ( V_2 , V_5 ,
V_6 , V_8 ) ;
F_4 ( V_2 , V_43 , 0xe0 , 0x00 ) ;
return 0 ;
}
if ( F_18 ( V_40 ) > 1 ) {
F_4 ( V_2 , V_14 ,
V_15 , V_16 ) ;
F_19 ( 100 ) ;
V_40 = F_17 ( V_2 , V_41 ) ;
if ( V_40 & V_44 )
V_40 = V_44 ;
else if ( V_40 & V_45 )
V_40 = V_45 ;
else
V_40 = 0 ;
F_4 ( V_2 , V_14 ,
V_15 , V_24 ) ;
F_20 ( & ( V_2 -> V_46 -> V_47 ) ,
L_1 ,
V_40 ) ;
}
if ( V_40 & V_44 ) {
F_4 ( V_2 , V_43 , 0xe0 , 0x40 ) ;
F_4 ( V_2 , V_5 ,
V_6 , V_48 ) ;
} else if ( V_40 & V_45 ) {
F_4 ( V_2 , V_43 , 0xe0 , 0x80 ) ;
F_4 ( V_2 , V_5 ,
V_6 , V_49 ) ;
}
return V_40 ;
}
static int F_21 ( int V_50 , int V_51 )
{
int V_52 ;
if ( V_51 == V_53 )
V_52 = V_50 * 4 / 5 - 2 ;
else
V_52 = ( V_50 + 2 ) * 5 / 4 ;
return V_52 ;
}
void F_22 ( struct V_1 * V_2 )
{
V_2 -> V_54 = V_55 | V_56 ;
V_2 -> V_57 = 2 ;
V_2 -> V_58 = & V_59 ;
V_2 -> V_60 = F_1 ( V_2 ) ;
V_2 -> V_61 = V_62 ;
V_2 -> V_63 = V_64 ;
V_2 -> V_65 = V_66 ;
V_2 -> V_67 = V_68 ;
}
