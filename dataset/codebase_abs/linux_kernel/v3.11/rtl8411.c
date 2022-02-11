static T_1 F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
F_2 ( V_2 , V_4 , & V_3 ) ;
return V_3 & 0x0F ;
}
static int F_3 ( struct V_1 * V_2 )
{
T_1 V_3 = 0 ;
F_2 ( V_2 , V_5 , & V_3 ) ;
if ( V_3 & 0x2 )
return 1 ;
else
return 0 ;
}
static int F_4 ( struct V_1 * V_2 )
{
return F_5 ( V_2 , V_6 ,
V_7 | V_8 , V_9 ) ;
}
static int F_6 ( struct V_1 * V_2 )
{
if ( F_3 ( V_2 ) )
F_5 ( V_2 , V_10 , 0xFF , 0xF5 ) ;
return F_5 ( V_2 , V_6 ,
V_7 | V_8 , V_9 ) ;
}
static int F_7 ( struct V_1 * V_2 )
{
return F_5 ( V_2 , V_11 , 0x01 , 0x00 ) ;
}
static int F_8 ( struct V_1 * V_2 )
{
return F_5 ( V_2 , V_11 , 0x01 , 0x01 ) ;
}
static int F_9 ( struct V_1 * V_2 )
{
return F_5 ( V_2 , V_12 , 0xFF , 0x0D ) ;
}
static int F_10 ( struct V_1 * V_2 )
{
return F_5 ( V_2 , V_12 , 0x08 , 0x00 ) ;
}
static int F_11 ( struct V_1 * V_2 , int V_13 )
{
int V_14 ;
F_12 ( V_2 ) ;
F_13 ( V_2 , V_15 , V_16 ,
V_17 , V_18 ) ;
F_13 ( V_2 , V_15 , V_19 ,
V_20 , V_21 ) ;
V_14 = F_14 ( V_2 , 100 ) ;
if ( V_14 < 0 )
return V_14 ;
F_15 ( 150 ) ;
V_14 = F_5 ( V_2 , V_16 ,
V_17 , V_22 ) ;
if ( V_14 < 0 )
return V_14 ;
F_15 ( 150 ) ;
V_14 = F_5 ( V_2 , V_16 ,
V_17 , V_23 ) ;
if ( V_14 < 0 )
return V_14 ;
F_15 ( 150 ) ;
V_14 = F_5 ( V_2 , V_16 ,
V_17 , V_24 ) ;
if ( V_14 < 0 )
return V_14 ;
return F_5 ( V_2 , V_19 , V_20 , V_25 ) ;
}
static int F_16 ( struct V_1 * V_2 , int V_13 )
{
int V_14 ;
V_14 = F_5 ( V_2 , V_16 ,
V_17 , V_26 ) ;
if ( V_14 < 0 )
return V_14 ;
return F_5 ( V_2 , V_19 ,
V_20 , V_21 ) ;
}
static int F_17 ( struct V_1 * V_2 , T_1 V_27 )
{
T_1 V_28 , V_3 ;
int V_14 ;
V_28 = ( V_29 << V_30 ) | V_31 ;
if ( V_27 == V_32 ) {
V_14 = F_5 ( V_2 ,
V_33 , 0x07 , V_34 ) ;
if ( V_14 < 0 )
return V_14 ;
V_3 = ( V_35 << V_30 ) | V_36 ;
} else if ( V_27 == V_37 ) {
V_14 = F_5 ( V_2 ,
V_33 , 0x07 , V_38 ) ;
if ( V_14 < 0 )
return V_14 ;
V_3 = ( V_39 << V_30 ) | V_40 ;
} else {
return - V_41 ;
}
return F_5 ( V_2 , V_19 , V_28 , V_3 ) ;
}
static unsigned int F_18 ( struct V_1 * V_2 )
{
unsigned int V_42 ;
V_42 = F_19 ( V_2 , V_43 ) ;
V_42 &= V_44 ;
if ( ! V_42 ) {
F_5 ( V_2 , V_6 ,
V_7 , V_9 ) ;
F_5 ( V_2 , V_45 , 0xe0 , 0x00 ) ;
return 0 ;
}
if ( F_20 ( V_42 ) > 1 ) {
F_5 ( V_2 , V_16 ,
V_17 , V_18 ) ;
F_21 ( 100 ) ;
V_42 = F_19 ( V_2 , V_43 ) ;
if ( V_42 & V_46 )
V_42 = V_46 ;
else if ( V_42 & V_47 )
V_42 = V_47 ;
else
V_42 = 0 ;
F_5 ( V_2 , V_16 ,
V_17 , V_26 ) ;
F_22 ( & ( V_2 -> V_48 -> V_49 ) ,
L_1 ,
V_42 ) ;
}
if ( V_42 & V_46 ) {
F_5 ( V_2 , V_45 , 0xe0 , 0x40 ) ;
F_5 ( V_2 , V_6 ,
V_7 , V_50 ) ;
} else if ( V_42 & V_47 ) {
F_5 ( V_2 , V_45 , 0xe0 , 0x80 ) ;
F_5 ( V_2 , V_6 ,
V_7 , V_51 ) ;
}
return V_42 ;
}
static int F_23 ( int V_52 , int V_53 )
{
int V_54 ;
if ( V_53 == V_55 )
V_54 = V_52 * 4 / 5 - 2 ;
else
V_54 = ( V_52 + 2 ) * 5 / 4 ;
return V_54 ;
}
void F_24 ( struct V_1 * V_2 )
{
V_2 -> V_56 = V_57 | V_58 ;
V_2 -> V_59 = 2 ;
V_2 -> V_60 = & V_61 ;
V_2 -> V_62 = F_1 ( V_2 ) ;
V_2 -> V_63 = V_64 ;
V_2 -> V_65 = V_66 ;
V_2 -> V_67 = V_68 ;
V_2 -> V_69 = V_70 ;
}
void F_25 ( struct V_1 * V_2 )
{
V_2 -> V_56 = V_57 | V_58 ;
V_2 -> V_59 = 2 ;
V_2 -> V_60 = & V_71 ;
V_2 -> V_62 = F_1 ( V_2 ) ;
if ( F_3 ( V_2 ) ) {
V_2 -> V_63 =
V_72 ;
V_2 -> V_65 =
V_73 ;
V_2 -> V_67 =
V_74 ;
V_2 -> V_69 =
V_75 ;
} else {
V_2 -> V_63 =
V_76 ;
V_2 -> V_65 =
V_77 ;
V_2 -> V_67 =
V_78 ;
V_2 -> V_69 =
V_79 ;
}
}
