static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_5 , int V_6 )
{
struct V_7 * V_8 ;
unsigned int V_9 ;
V_9 = V_2 -> V_10 -> V_11 ? 8 : V_2 -> V_10 -> V_9 ;
V_8 = F_2 ( V_4 , 0 ) ;
V_2 -> V_12 [ 0 ] = V_8 -> V_13 + V_4 -> V_14 [ 0 ]
+ V_6 * V_4 -> V_15 [ 0 ] + V_5 * V_9 / 8 ;
if ( V_2 -> V_10 -> V_11 ) {
V_9 = V_2 -> V_10 -> V_9 - 8 ;
V_8 = F_2 ( V_4 , 1 ) ;
V_2 -> V_12 [ 1 ] = V_8 -> V_13 + V_4 -> V_14 [ 1 ]
+ V_6 / ( V_9 == 4 ? 2 : 1 ) * V_4 -> V_15 [ 1 ]
+ V_5 * ( V_9 == 16 ? 2 : 1 ) ;
}
}
static void F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_16 * V_17 = V_2 -> V_18 . V_19 -> V_20 ;
T_1 V_10 ;
V_10 = V_21 | ( V_2 -> V_22 << V_23 ) ;
switch ( V_2 -> V_10 -> V_24 ) {
case V_25 :
case V_26 :
case V_27 :
case V_28 :
V_10 |= V_29 | V_30 ;
break;
case V_31 :
case V_32 :
case V_33 :
case V_34 :
V_10 |= V_29 | V_30 | V_35 ;
break;
case V_36 :
default:
V_10 |= V_29 ;
break;
}
switch ( V_2 -> V_10 -> V_24 ) {
case V_25 :
V_10 |= V_37 | V_38 | V_39 ;
break;
case V_31 :
V_10 |= V_37 | V_38 | V_40 ;
break;
case V_36 :
V_10 |= V_41 | V_38 | V_42 ;
break;
case V_32 :
case V_26 :
V_10 |= V_37 | V_43 ;
break;
case V_33 :
case V_27 :
V_10 |= V_37 | V_44 ;
break;
case V_34 :
case V_28 :
V_10 |= V_37 | V_45 ;
break;
}
#define F_4 ( V_17 , V_2 , T_2 ) \
dev_dbg(sdev->ddev->dev, "%s(%u): %s 0x%08x 0x%08x\n", __func__, \
splane->index, #reg, \
lcdc_read(sdev, reg(splane->index)), \
lcdc_read(sdev, reg(splane->index) + LCDC_SIDE_B_OFFSET))
F_4 ( V_17 , V_2 , V_46 ) ;
F_4 ( V_17 , V_2 , V_47 ) ;
F_4 ( V_17 , V_2 , V_48 ) ;
F_4 ( V_17 , V_2 , V_49 ) ;
F_4 ( V_17 , V_2 , V_50 ) ;
F_4 ( V_17 , V_2 , V_51 ) ;
F_5 ( V_17 , V_52 , F_6 ( V_2 -> V_53 ) ) ;
F_7 ( V_17 -> V_54 -> V_19 , L_1 , V_55 , V_2 -> V_53 ,
L_2 , F_8 ( V_17 , V_52 ) ) ;
F_5 ( V_17 , V_46 ( V_2 -> V_53 ) , V_10 ) ;
F_5 ( V_17 , V_47 ( V_2 -> V_53 ) ,
( V_2 -> V_56 << V_57 ) |
( V_2 -> V_58 << V_59 ) ) ;
F_5 ( V_17 , V_48 ( V_2 -> V_53 ) ,
( V_2 -> V_60 << V_61 ) |
( V_2 -> V_62 << V_63 ) ) ;
F_5 ( V_17 , V_49 ( V_2 -> V_53 ) ,
V_4 -> V_15 [ 0 ] << V_64 ) ;
F_1 ( V_2 , V_4 , V_2 -> V_65 , V_2 -> V_66 ) ;
F_5 ( V_17 , V_50 ( V_2 -> V_53 ) , V_2 -> V_12 [ 0 ] ) ;
if ( V_2 -> V_10 -> V_11 )
F_5 ( V_17 , V_51 ( V_2 -> V_53 ) , V_2 -> V_12 [ 1 ] ) ;
F_5 ( V_17 , V_52 ,
F_9 ( V_2 -> V_53 ) | F_10 ( V_2 -> V_53 ) ) ;
F_7 ( V_17 -> V_54 -> V_19 , L_1 , V_55 , V_2 -> V_53 ,
L_2 , F_8 ( V_17 , V_52 ) ) ;
F_4 ( V_17 , V_2 , V_46 ) ;
F_4 ( V_17 , V_2 , V_47 ) ;
F_4 ( V_17 , V_2 , V_48 ) ;
F_4 ( V_17 , V_2 , V_49 ) ;
F_4 ( V_17 , V_2 , V_50 ) ;
F_4 ( V_17 , V_2 , V_51 ) ;
}
void F_11 ( struct V_67 * V_18 )
{
struct V_1 * V_2 = F_12 ( V_18 ) ;
if ( V_18 -> V_4 == NULL )
return;
F_3 ( V_2 , V_18 -> V_4 ) ;
}
static int
F_13 ( struct V_67 * V_18 , struct V_68 * V_69 ,
struct V_3 * V_4 , int V_62 , int V_60 ,
unsigned int V_58 , unsigned int V_56 ,
T_3 V_65 , T_3 V_66 ,
T_3 V_70 , T_3 V_71 )
{
struct V_1 * V_2 = F_12 ( V_18 ) ;
struct V_16 * V_17 = V_18 -> V_19 -> V_20 ;
const struct V_72 * V_10 ;
V_10 = V_72 ( V_4 -> V_10 -> V_10 ) ;
if ( V_10 == NULL ) {
F_7 ( V_17 -> V_19 , L_3 ,
V_4 -> V_10 -> V_10 ) ;
return - V_73 ;
}
if ( V_70 >> 16 != V_58 || V_71 >> 16 != V_56 ) {
F_7 ( V_17 -> V_19 , L_4 , V_55 ) ;
return - V_73 ;
}
V_2 -> V_10 = V_10 ;
V_2 -> V_65 = V_65 >> 16 ;
V_2 -> V_66 = V_66 >> 16 ;
V_2 -> V_62 = V_62 ;
V_2 -> V_60 = V_60 ;
V_2 -> V_58 = V_58 ;
V_2 -> V_56 = V_56 ;
F_3 ( V_2 , V_4 ) ;
return 0 ;
}
static int F_14 ( struct V_67 * V_18 )
{
struct V_1 * V_2 = F_12 ( V_18 ) ;
struct V_16 * V_17 = V_18 -> V_19 -> V_20 ;
V_2 -> V_10 = NULL ;
F_5 ( V_17 , V_46 ( V_2 -> V_53 ) , 0 ) ;
return 0 ;
}
static void F_15 ( struct V_67 * V_18 )
{
F_14 ( V_18 ) ;
F_16 ( V_18 ) ;
}
int F_17 ( struct V_16 * V_17 , unsigned int V_53 )
{
struct V_1 * V_2 ;
int V_74 ;
V_2 = F_18 ( V_17 -> V_19 , sizeof( * V_2 ) , V_75 ) ;
if ( V_2 == NULL )
return - V_76 ;
V_2 -> V_53 = V_53 ;
V_2 -> V_22 = 255 ;
V_74 = F_19 ( V_17 -> V_54 , & V_2 -> V_18 , 1 ,
& V_77 , V_78 ,
F_20 ( V_78 ) , false ) ;
return V_74 ;
}
