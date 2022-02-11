static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
F_2 ( V_4 , V_5 , 1 ) ;
F_3 ( V_4 ) ;
return V_6 ;
}
static T_1 F_4 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
F_2 ( V_4 , V_5 , 0 ) ;
F_3 ( V_4 ) ;
return V_6 ;
}
static int T_2 F_5 ( struct V_7 * V_8 )
{
struct V_9 * V_10 = F_6 ( V_8 ) ;
if ( F_7 ( V_8 ) )
F_8 ( V_10 -> V_11 ) ;
return 0 ;
}
static int T_2 F_9 ( struct V_7 * V_8 )
{
struct V_9 * V_10 = F_6 ( V_8 ) ;
if ( F_7 ( V_8 ) )
F_10 ( V_10 -> V_11 ) ;
return 0 ;
}
static void F_11 ( struct V_12 * V_13 )
{
struct V_9 * V_10 = F_12 ( V_13 ) ;
int error ;
T_3 V_14 , V_15 ;
bool V_16 = V_17 == V_18 ;
if ( V_10 -> V_19 ) {
error = V_10 -> V_19 ( V_10 , V_16 ) ;
if ( error )
return;
}
V_14 = V_20 | V_21 ;
V_14 |= V_22 ;
V_15 = V_14 ;
if ( ! V_16 )
V_15 &= ~ V_22 ;
F_13 ( V_10 -> V_23 , V_24 , V_14 , V_15 ) ;
}
static int F_14 ( struct V_23 * V_23 ,
T_4 V_25 , T_4 V_26 , T_4 V_27 ,
T_3 V_28 )
{
int error ;
T_3 V_29 , V_30 , V_31 , V_32 , V_33 ;
unsigned int V_34 ;
V_33 = F_15 ( 7 ) ;
error = F_16 ( V_23 , V_26 , V_33 ) ;
if ( error )
return error ;
error = F_17 ( V_23 , V_26 , & V_34 ) ;
if ( error )
return error ;
V_34 &= V_35 ;
if ( V_34 == V_36 ) {
error = F_17 ( V_23 , V_25 , & V_34 ) ;
if ( error )
return error ;
V_31 = V_34 & V_37 ;
V_31 >>= V_38 ;
switch ( V_31 ) {
case 3 :
V_29 = 0 ;
V_30 = 0 ;
break;
case 2 :
V_29 = V_39 ;
V_30 = 0 ;
break;
case 1 :
V_29 = V_39 ;
V_30 = V_40 ;
break;
default:
F_18 ( L_1 , V_41 ) ;
return - V_42 ;
}
V_32 = V_34 & V_43 ;
V_32 = ( V_32 + 1 ) >> 1 ;
if ( V_32 > V_44 )
V_32 = V_44 ;
V_33 = F_15 ( 1 ) ;
error = F_16 ( V_23 , V_26 , V_33 ) ;
if ( error )
return error ;
error = F_13 ( V_23 , V_26 ,
V_45 | V_46
| V_40 ,
V_45 |
F_15 ( 1 ) | V_30 ) ;
if ( error )
return error ;
V_33 = F_15 ( 7 ) ;
error = F_16 ( V_23 , V_26 , V_33 ) ;
if ( error )
return error ;
error = F_13 ( V_23 , V_26 ,
V_45 |
V_46 |
V_35 ,
V_45 |
F_15 ( 7 ) |
V_47 ) ;
if ( error )
return error ;
error = F_13 ( V_23 , V_25 ,
V_48 |
V_49 |
V_39 |
V_44 ,
V_50 | V_51
| V_29 | V_32 ) ;
if ( error )
return error ;
}
error = F_13 ( V_23 , V_27 ,
V_28 , V_28 ) ;
if ( error )
return error ;
return F_13 ( V_23 , V_25 ,
V_48 | V_49 ,
V_52 | V_51 ) ;
}
static int F_19 ( struct V_23 * V_23 ,
T_4 V_25 , T_4 V_27 , T_3 V_28 )
{
int error ;
error = F_13 ( V_23 , V_27 ,
V_28 , V_28 ) ;
if ( error )
return error ;
return F_13 ( V_23 , V_25 ,
V_48 | V_49 ,
V_52 | V_51 ) ;
}
static int F_20 ( struct V_9 * V_10 , bool V_16 )
{
int error ;
struct V_23 * V_23 = V_10 -> V_23 ;
T_3 V_14 , V_15 ;
if ( ! V_16 ) {
F_14 ( V_23 ,
V_53 , V_54 ,
V_55 , F_21 ( 7 ) ) ;
F_14 ( V_23 ,
V_56 , V_57 ,
V_55 , F_21 ( 6 ) ) ;
F_14 ( V_23 ,
V_58 , V_59 ,
V_60 , F_21 ( 7 ) | F_21 ( 4 ) ) ;
F_19 ( V_23 ,
V_61 , V_60 ,
F_21 ( 1 ) ) ;
}
error = F_13 ( V_23 , V_62 , 0xbf , 0x93 ) ;
if ( error )
return error ;
V_14 = V_63 ;
V_15 = 0 ;
if ( V_16 )
V_15 = V_14 ;
return F_13 ( V_23 , V_64 , V_14 , V_15 ) ;
}
static int F_22 ( struct V_9 * V_10 , bool V_16 )
{
struct V_23 * V_23 = V_10 -> V_23 ;
T_3 V_14 = V_63 ;
T_3 V_15 = 0 ;
if ( V_16 )
V_15 = V_14 ;
return F_13 ( V_23 , V_65 , V_14 , V_15 ) ;
}
static int F_23 ( struct V_12 * V_13 )
{
struct V_3 * V_4 ;
int V_66 = F_24 ( V_13 , 0 ) ;
int V_11 = F_24 ( V_13 , 1 ) ;
int V_67 ;
unsigned int V_68 ;
unsigned int V_69 ;
struct V_23 * V_23 ;
struct V_9 * V_10 ;
T_5 V_70 ;
bool V_71 ;
if ( F_25 ( V_13 -> V_8 . V_72 , L_2 , & V_70 ) )
V_70 = 15625 ;
if ( V_70 > V_73 * 2 || V_70 < V_73 / 64 ) {
F_26 ( & V_13 -> V_8 , L_3 ) ;
return - V_74 ;
}
V_71 = F_27 ( V_13 -> V_8 . V_72 , L_4 ) ;
V_23 = F_28 ( V_13 -> V_8 . V_75 , NULL ) ;
if ( ! V_23 ) {
F_26 ( & V_13 -> V_8 , L_5 ) ;
return - V_76 ;
}
V_10 = F_29 ( & V_13 -> V_8 , sizeof( * V_10 ) , V_77 ) ;
if ( ! V_10 )
return - V_78 ;
V_10 -> V_19 = F_30 ( & V_13 -> V_8 ) ;
V_10 -> V_23 = V_23 ;
V_10 -> V_11 = V_11 ;
V_4 = F_31 ( & V_13 -> V_8 ) ;
if ( ! V_4 ) {
F_32 ( & V_13 -> V_8 , L_6 ) ;
return - V_78 ;
}
F_33 ( V_4 , V_79 , V_5 ) ;
V_4 -> V_80 = L_7 ;
V_4 -> V_81 = L_8 ;
V_68 = ( V_70 << 6 ) / V_73 ;
V_68 = F_34 ( V_68 ) ;
V_67 = F_17 ( V_23 , V_24 , & V_69 ) ;
if ( V_67 < 0 ) {
F_26 ( & V_13 -> V_8 , L_9 , V_67 ) ;
return V_67 ;
}
V_69 &= ~ V_82 ;
V_69 |= ( V_68 & V_82 ) ;
if ( V_71 )
V_69 |= V_83 ;
else
V_69 &= ~ V_83 ;
V_67 = F_16 ( V_23 , V_24 , V_69 ) ;
if ( V_67 < 0 ) {
F_26 ( & V_13 -> V_8 , L_10 , V_67 ) ;
return V_67 ;
}
V_67 = F_35 ( & V_13 -> V_8 , V_11 , F_1 ,
V_84 ,
L_11 , V_4 ) ;
if ( V_67 ) {
F_26 ( & V_13 -> V_8 , L_12 ,
V_11 , V_67 ) ;
return V_67 ;
}
V_67 = F_35 ( & V_13 -> V_8 , V_66 , F_4 ,
V_84 ,
L_13 , V_4 ) ;
if ( V_67 ) {
F_26 ( & V_13 -> V_8 , L_12 ,
V_66 , V_67 ) ;
return V_67 ;
}
V_67 = F_36 ( V_4 ) ;
if ( V_67 ) {
F_26 ( & V_13 -> V_8 , L_14 , V_67 ) ;
return V_67 ;
}
F_37 ( V_13 , V_10 ) ;
F_38 ( & V_13 -> V_8 , 1 ) ;
return 0 ;
}
