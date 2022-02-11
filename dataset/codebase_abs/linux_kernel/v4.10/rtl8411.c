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
static void F_4 ( struct V_1 * V_2 )
{
T_2 V_6 = 0 ;
T_1 V_7 = 0 ;
F_5 ( V_2 , V_8 , & V_6 ) ;
F_6 ( V_2 , L_1 , V_8 , V_6 ) ;
if ( ! F_7 ( V_6 ) )
return;
V_2 -> V_9 = F_8 ( V_6 ) ;
V_2 -> V_10 =
F_9 ( F_10 ( V_6 ) ) ;
V_2 -> V_11 &= 0x3F ;
V_2 -> V_11 |= F_11 ( V_6 ) ;
F_12 ( V_2 , V_12 , & V_7 ) ;
F_6 ( V_2 , L_1 , V_12 , V_7 ) ;
V_2 -> V_13 = F_13 ( V_7 ) ;
}
static void F_14 ( struct V_1 * V_2 )
{
T_2 V_14 = 0 ;
F_5 ( V_2 , V_8 , & V_14 ) ;
F_6 ( V_2 , L_1 , V_8 , V_14 ) ;
if ( ! F_7 ( V_14 ) )
return;
V_2 -> V_9 = F_8 ( V_14 ) ;
V_2 -> V_10 =
F_9 ( F_10 ( V_14 ) ) ;
V_2 -> V_13 =
F_9 ( F_15 ( V_14 ) ) ;
}
static void F_16 ( struct V_1 * V_2 , T_1 V_15 )
{
F_17 ( V_2 , V_16 , 0x07 , 0x07 ) ;
}
static int F_18 ( struct V_1 * V_2 )
{
F_19 ( V_2 ) ;
F_20 ( V_2 , V_17 , V_18 ,
0xFF , V_2 -> V_13 ) ;
F_20 ( V_2 , V_17 , V_19 ,
V_20 | V_21 , V_22 ) ;
return F_21 ( V_2 , 100 ) ;
}
static int F_22 ( struct V_1 * V_2 )
{
F_19 ( V_2 ) ;
if ( F_3 ( V_2 ) )
F_20 ( V_2 , V_17 ,
V_23 , 0xFF , 0xF5 ) ;
F_20 ( V_2 , V_17 , V_18 ,
0xFF , V_2 -> V_13 ) ;
F_20 ( V_2 , V_17 , V_19 ,
V_20 | V_21 , V_22 ) ;
F_20 ( V_2 , V_17 , V_24 ,
0x06 , 0x00 ) ;
return F_21 ( V_2 , 100 ) ;
}
static int F_23 ( struct V_1 * V_2 )
{
return F_17 ( V_2 , V_25 , 0x01 , 0x00 ) ;
}
static int F_24 ( struct V_1 * V_2 )
{
return F_17 ( V_2 , V_25 , 0x01 , 0x01 ) ;
}
static int F_25 ( struct V_1 * V_2 )
{
return F_17 ( V_2 , V_26 , 0xFF , 0x0D ) ;
}
static int F_26 ( struct V_1 * V_2 )
{
return F_17 ( V_2 , V_26 , 0x08 , 0x00 ) ;
}
static int F_27 ( struct V_1 * V_2 , int V_27 )
{
int V_28 ;
F_19 ( V_2 ) ;
F_20 ( V_2 , V_17 , V_29 ,
V_30 , V_31 ) ;
F_20 ( V_2 , V_17 , V_32 ,
V_33 , V_34 ) ;
V_28 = F_21 ( V_2 , 100 ) ;
if ( V_28 < 0 )
return V_28 ;
F_28 ( 150 ) ;
V_28 = F_17 ( V_2 , V_29 ,
V_30 , V_35 ) ;
if ( V_28 < 0 )
return V_28 ;
F_28 ( 150 ) ;
V_28 = F_17 ( V_2 , V_29 ,
V_30 , V_36 ) ;
if ( V_28 < 0 )
return V_28 ;
F_28 ( 150 ) ;
V_28 = F_17 ( V_2 , V_29 ,
V_30 , V_37 ) ;
if ( V_28 < 0 )
return V_28 ;
return F_17 ( V_2 , V_32 , V_33 , V_38 ) ;
}
static int F_29 ( struct V_1 * V_2 , int V_27 )
{
int V_28 ;
V_28 = F_17 ( V_2 , V_29 ,
V_30 , V_39 ) ;
if ( V_28 < 0 )
return V_28 ;
return F_17 ( V_2 , V_32 ,
V_33 , V_34 ) ;
}
static int F_30 ( struct V_1 * V_2 , T_1 V_40 ,
int V_41 , int V_42 )
{
T_1 V_43 , V_3 ;
int V_28 ;
V_43 = ( V_44 << V_41 ) | V_45 ;
if ( V_40 == V_46 ) {
V_28 = F_17 ( V_2 ,
V_18 , 0x07 , V_2 -> V_13 ) ;
if ( V_28 < 0 )
return V_28 ;
V_3 = ( V_47 << V_41 ) | V_48 ;
} else if ( V_40 == V_49 ) {
V_28 = F_17 ( V_2 ,
V_18 , 0x07 , V_2 -> V_10 ) ;
if ( V_28 < 0 )
return V_28 ;
V_3 = ( V_42 << V_41 ) | V_50 ;
} else {
return - V_51 ;
}
return F_17 ( V_2 , V_32 , V_43 , V_3 ) ;
}
static int F_31 ( struct V_1 * V_2 , T_1 V_40 )
{
return F_30 ( V_2 , V_40 ,
V_52 , V_53 ) ;
}
static int F_32 ( struct V_1 * V_2 , T_1 V_40 )
{
return F_30 ( V_2 , V_40 ,
V_54 , V_55 ) ;
}
static unsigned int F_33 ( struct V_1 * V_2 )
{
unsigned int V_56 ;
V_56 = F_34 ( V_2 , V_57 ) ;
V_56 &= V_58 ;
if ( ! V_56 ) {
F_17 ( V_2 , V_19 ,
V_20 , V_22 ) ;
F_17 ( V_2 , V_59 , 0xe0 , 0x00 ) ;
return 0 ;
}
if ( F_35 ( V_56 ) > 1 ) {
F_17 ( V_2 , V_29 ,
V_30 , V_31 ) ;
F_36 ( 100 ) ;
V_56 = F_34 ( V_2 , V_57 ) ;
if ( V_56 & V_60 )
V_56 = V_60 ;
else if ( V_56 & V_61 )
V_56 = V_61 ;
else
V_56 = 0 ;
F_17 ( V_2 , V_29 ,
V_30 , V_39 ) ;
F_6 ( V_2 , L_2 ,
V_56 ) ;
}
if ( V_56 & V_60 ) {
F_17 ( V_2 , V_59 , 0xe0 , 0x40 ) ;
F_17 ( V_2 , V_19 ,
V_20 , V_62 ) ;
} else if ( V_56 & V_61 ) {
F_17 ( V_2 , V_59 , 0xe0 , 0x80 ) ;
F_17 ( V_2 , V_19 ,
V_20 , V_63 ) ;
}
return V_56 ;
}
static int F_37 ( int V_64 , int V_65 )
{
int V_66 ;
if ( V_65 == V_67 )
V_66 = V_64 * 4 / 5 - 2 ;
else
V_66 = ( V_64 + 2 ) * 5 / 4 ;
return V_66 ;
}
static void F_38 ( struct V_1 * V_2 )
{
V_2 -> V_68 = V_69 | V_70 ;
V_2 -> V_71 = 2 ;
V_2 -> V_72 = 0 ;
V_2 -> V_11 = V_73 ;
V_2 -> V_10 = V_74 ;
V_2 -> V_13 = V_75 ;
V_2 -> V_9 = V_76 ;
V_2 -> V_77 = F_39 ( 23 , 7 , 14 ) ;
V_2 -> V_78 = F_39 ( 4 , 3 , 10 ) ;
V_2 -> V_79 = F_1 ( V_2 ) ;
}
void F_40 ( struct V_1 * V_2 )
{
F_38 ( V_2 ) ;
V_2 -> V_80 = & V_81 ;
F_41 ( V_2 , V_82 ) ;
}
void F_42 ( struct V_1 * V_2 )
{
F_38 ( V_2 ) ;
V_2 -> V_80 = & V_83 ;
if ( F_3 ( V_2 ) )
F_41 ( V_2 , V_84 ) ;
else
F_41 ( V_2 , V_85 ) ;
}
void F_43 ( struct V_1 * V_2 )
{
F_38 ( V_2 ) ;
V_2 -> V_80 = & V_86 ;
F_41 ( V_2 , V_82 ) ;
}
