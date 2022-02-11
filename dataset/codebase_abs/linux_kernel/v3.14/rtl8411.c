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
F_6 ( & ( V_2 -> V_9 -> V_10 ) , L_1 , V_8 , V_6 ) ;
if ( ! F_7 ( V_6 ) )
return;
V_2 -> V_11 = F_8 ( V_6 ) ;
V_2 -> V_12 =
F_9 ( F_10 ( V_6 ) ) ;
V_2 -> V_13 &= 0x3F ;
V_2 -> V_13 |= F_11 ( V_6 ) ;
F_12 ( V_2 , V_14 , & V_7 ) ;
F_6 ( & ( V_2 -> V_9 -> V_10 ) , L_1 , V_14 , V_7 ) ;
V_2 -> V_15 = F_13 ( V_7 ) ;
}
static void F_14 ( struct V_1 * V_2 )
{
T_2 V_16 = 0 ;
F_5 ( V_2 , V_8 , & V_16 ) ;
F_6 ( & ( V_2 -> V_9 -> V_10 ) , L_1 , V_8 , V_16 ) ;
if ( ! F_7 ( V_16 ) )
return;
V_2 -> V_11 = F_8 ( V_16 ) ;
V_2 -> V_12 =
F_9 ( F_10 ( V_16 ) ) ;
V_2 -> V_15 =
F_9 ( F_15 ( V_16 ) ) ;
}
static void F_16 ( struct V_1 * V_2 , T_1 V_17 )
{
F_17 ( V_2 , V_18 , 0x07 , 0x07 ) ;
}
static int F_18 ( struct V_1 * V_2 )
{
F_19 ( V_2 ) ;
F_20 ( V_2 , V_19 , V_20 ,
0xFF , V_2 -> V_15 ) ;
F_20 ( V_2 , V_19 , V_21 ,
V_22 | V_23 , V_24 ) ;
return F_21 ( V_2 , 100 ) ;
}
static int F_22 ( struct V_1 * V_2 )
{
F_19 ( V_2 ) ;
if ( F_3 ( V_2 ) )
F_20 ( V_2 , V_19 ,
V_25 , 0xFF , 0xF5 ) ;
F_20 ( V_2 , V_19 , V_20 ,
0xFF , V_2 -> V_15 ) ;
F_20 ( V_2 , V_19 , V_21 ,
V_22 | V_23 , V_24 ) ;
F_20 ( V_2 , V_19 , V_26 ,
0x06 , 0x00 ) ;
return F_21 ( V_2 , 100 ) ;
}
static int F_23 ( struct V_1 * V_2 )
{
return F_17 ( V_2 , V_27 , 0x01 , 0x00 ) ;
}
static int F_24 ( struct V_1 * V_2 )
{
return F_17 ( V_2 , V_27 , 0x01 , 0x01 ) ;
}
static int F_25 ( struct V_1 * V_2 )
{
return F_17 ( V_2 , V_28 , 0xFF , 0x0D ) ;
}
static int F_26 ( struct V_1 * V_2 )
{
return F_17 ( V_2 , V_28 , 0x08 , 0x00 ) ;
}
static int F_27 ( struct V_1 * V_2 , int V_29 )
{
int V_30 ;
F_19 ( V_2 ) ;
F_20 ( V_2 , V_19 , V_31 ,
V_32 , V_33 ) ;
F_20 ( V_2 , V_19 , V_34 ,
V_35 , V_36 ) ;
V_30 = F_21 ( V_2 , 100 ) ;
if ( V_30 < 0 )
return V_30 ;
F_28 ( 150 ) ;
V_30 = F_17 ( V_2 , V_31 ,
V_32 , V_37 ) ;
if ( V_30 < 0 )
return V_30 ;
F_28 ( 150 ) ;
V_30 = F_17 ( V_2 , V_31 ,
V_32 , V_38 ) ;
if ( V_30 < 0 )
return V_30 ;
F_28 ( 150 ) ;
V_30 = F_17 ( V_2 , V_31 ,
V_32 , V_39 ) ;
if ( V_30 < 0 )
return V_30 ;
return F_17 ( V_2 , V_34 , V_35 , V_40 ) ;
}
static int F_29 ( struct V_1 * V_2 , int V_29 )
{
int V_30 ;
V_30 = F_17 ( V_2 , V_31 ,
V_32 , V_41 ) ;
if ( V_30 < 0 )
return V_30 ;
return F_17 ( V_2 , V_34 ,
V_35 , V_36 ) ;
}
static int F_30 ( struct V_1 * V_2 , T_1 V_42 ,
int V_43 , int V_44 )
{
T_1 V_45 , V_3 ;
int V_30 ;
V_45 = ( V_46 << V_43 ) | V_47 ;
if ( V_42 == V_48 ) {
V_30 = F_17 ( V_2 ,
V_20 , 0x07 , V_2 -> V_15 ) ;
if ( V_30 < 0 )
return V_30 ;
V_3 = ( V_49 << V_43 ) | V_50 ;
} else if ( V_42 == V_51 ) {
V_30 = F_17 ( V_2 ,
V_20 , 0x07 , V_2 -> V_12 ) ;
if ( V_30 < 0 )
return V_30 ;
V_3 = ( V_44 << V_43 ) | V_52 ;
} else {
return - V_53 ;
}
return F_17 ( V_2 , V_34 , V_45 , V_3 ) ;
}
static int F_31 ( struct V_1 * V_2 , T_1 V_42 )
{
return F_30 ( V_2 , V_42 ,
V_54 , V_55 ) ;
}
static int F_32 ( struct V_1 * V_2 , T_1 V_42 )
{
return F_30 ( V_2 , V_42 ,
V_56 , V_57 ) ;
}
static unsigned int F_33 ( struct V_1 * V_2 )
{
unsigned int V_58 ;
V_58 = F_34 ( V_2 , V_59 ) ;
V_58 &= V_60 ;
if ( ! V_58 ) {
F_17 ( V_2 , V_21 ,
V_22 , V_24 ) ;
F_17 ( V_2 , V_61 , 0xe0 , 0x00 ) ;
return 0 ;
}
if ( F_35 ( V_58 ) > 1 ) {
F_17 ( V_2 , V_31 ,
V_32 , V_33 ) ;
F_36 ( 100 ) ;
V_58 = F_34 ( V_2 , V_59 ) ;
if ( V_58 & V_62 )
V_58 = V_62 ;
else if ( V_58 & V_63 )
V_58 = V_63 ;
else
V_58 = 0 ;
F_17 ( V_2 , V_31 ,
V_32 , V_41 ) ;
F_6 ( & ( V_2 -> V_9 -> V_10 ) ,
L_2 ,
V_58 ) ;
}
if ( V_58 & V_62 ) {
F_17 ( V_2 , V_61 , 0xe0 , 0x40 ) ;
F_17 ( V_2 , V_21 ,
V_22 , V_64 ) ;
} else if ( V_58 & V_63 ) {
F_17 ( V_2 , V_61 , 0xe0 , 0x80 ) ;
F_17 ( V_2 , V_21 ,
V_22 , V_65 ) ;
}
return V_58 ;
}
static int F_37 ( int V_66 , int V_67 )
{
int V_68 ;
if ( V_67 == V_69 )
V_68 = V_66 * 4 / 5 - 2 ;
else
V_68 = ( V_66 + 2 ) * 5 / 4 ;
return V_68 ;
}
static void F_38 ( struct V_1 * V_2 )
{
V_2 -> V_70 = V_71 | V_72 ;
V_2 -> V_73 = 2 ;
V_2 -> V_74 = 0 ;
V_2 -> V_13 = V_75 ;
V_2 -> V_12 = V_76 ;
V_2 -> V_15 = V_77 ;
V_2 -> V_11 = V_78 ;
V_2 -> V_79 = F_39 ( 23 , 7 , 14 ) ;
V_2 -> V_80 = F_39 ( 4 , 3 , 10 ) ;
V_2 -> V_81 = F_1 ( V_2 ) ;
}
void F_40 ( struct V_1 * V_2 )
{
F_38 ( V_2 ) ;
V_2 -> V_82 = & V_83 ;
F_41 ( V_2 , V_84 ) ;
}
void F_42 ( struct V_1 * V_2 )
{
F_38 ( V_2 ) ;
V_2 -> V_82 = & V_85 ;
if ( F_3 ( V_2 ) )
F_41 ( V_2 , V_86 ) ;
else
F_41 ( V_2 , V_87 ) ;
}
void F_43 ( struct V_1 * V_2 )
{
F_38 ( V_2 ) ;
V_2 -> V_82 = & V_88 ;
F_41 ( V_2 , V_84 ) ;
}
