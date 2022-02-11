static inline void F_1 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 )
{
F_2 ( V_4 , V_2 -> V_5 + V_3 ) ;
}
static inline int F_3 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_4 ( V_2 -> V_5 + V_3 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
F_6 ( V_2 -> V_6 , L_1 ) ;
F_6 ( V_2 -> V_6 , L_2 ,
F_3 ( V_2 , V_7 ) ) ;
F_6 ( V_2 -> V_6 , L_3 ,
F_3 ( V_2 , V_8 ) ) ;
F_6 ( V_2 -> V_6 , L_4 ,
F_3 ( V_2 , V_9 ) ) ;
F_6 ( V_2 -> V_6 , L_5 ,
F_3 ( V_2 , V_10 ) ) ;
F_6 ( V_2 -> V_6 , L_6 ,
F_3 ( V_2 , V_11 ) ) ;
F_6 ( V_2 -> V_6 , L_7 ,
F_3 ( V_2 , V_12 ) ) ;
F_6 ( V_2 -> V_6 , L_8 ,
F_3 ( V_2 , V_13 ) ) ;
F_6 ( V_2 -> V_6 , L_9 ,
F_3 ( V_2 , V_14 ) ) ;
F_6 ( V_2 -> V_6 , L_10 ,
F_3 ( V_2 , V_15 ) ) ;
F_6 ( V_2 -> V_6 , L_11 ,
F_3 ( V_2 , V_16 ) ) ;
F_6 ( V_2 -> V_6 , L_12 ,
F_3 ( V_2 , V_17 ) ) ;
F_6 ( V_2 -> V_6 , L_13 ,
F_3 ( V_2 , V_18 ) ) ;
F_6 ( V_2 -> V_6 , L_14 ,
F_3 ( V_2 , V_19 ) ) ;
F_6 ( V_2 -> V_6 , L_1 ) ;
}
static void F_5 ( struct V_1 * V_2 ) {}
static void F_7 ( struct V_1 * V_2 )
{
T_2 V_20 = F_3 ( V_2 , V_15 ) ;
V_20 |= ( V_21 | V_22 ) ;
F_1 ( V_2 , V_15 , V_20 ) ;
V_20 |= V_2 -> V_23 | V_2 -> V_24 ;
F_1 ( V_2 , V_15 , V_20 ) ;
V_20 &= ~ ( V_21 | V_22 ) ;
F_1 ( V_2 , V_15 , V_20 ) ;
}
static void F_8 ( struct V_1 * V_2 )
{
T_2 V_20 = F_3 ( V_2 , V_15 ) ;
V_20 |= ( V_21 | V_22 ) ;
F_1 ( V_2 , V_15 , V_20 ) ;
V_20 &= ~ ( V_2 -> V_23 | V_2 -> V_24 ) ;
F_1 ( V_2 , V_15 , V_20 ) ;
V_20 &= ~ ( V_21 | V_22 ) ;
F_1 ( V_2 , V_15 , V_20 ) ;
}
static inline int F_9 ( struct V_1 * V_2 )
{
return F_3 ( V_2 , V_15 ) &
( V_25 | V_26 ) ;
}
static void F_10 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_9 ,
V_27 | V_28 |
V_29 | V_30 ) ;
if ( V_2 -> V_31 ) {
T_2 V_32 = V_2 -> V_31 ;
F_1 ( V_2 , V_33 , V_32 ) ;
V_32 |= ( V_34 | V_35 ) ;
F_1 ( V_2 , V_33 , V_32 ) ;
}
F_1 ( V_2 , V_18 , V_2 -> V_36 ) ;
F_1 ( V_2 , V_19 , V_2 -> V_37 ) ;
F_1 ( V_2 , V_12 ,
V_38 | V_39 ) ;
}
static void F_11 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_10 ,
V_27 | V_28 ) ;
F_1 ( V_2 , V_13 , V_38 ) ;
F_1 ( V_2 , V_10 ,
V_29 | V_30 ) ;
F_1 ( V_2 , V_13 , V_39 ) ;
if ( V_2 -> V_31 )
F_1 ( V_2 , V_33 , 0 ) ;
}
static T_3 F_12 ( int V_40 , void * V_41 )
{
struct V_1 * V_2 = V_41 ;
int V_42 ;
V_42 = F_3 ( V_2 , V_8 ) ;
F_1 ( V_2 , V_8 , V_42 ) ;
if ( V_42 & V_28 )
F_6 ( V_2 -> V_6 , L_15 ) ;
if ( V_42 & V_27 )
F_6 ( V_2 -> V_6 , L_16 ) ;
if ( V_42 & V_43 )
F_6 ( V_2 -> V_6 , L_17 ) ;
if ( V_42 & V_30 )
F_6 ( V_2 -> V_6 , L_18 ) ;
if ( V_42 & V_29 )
F_6 ( V_2 -> V_6 , L_19 ) ;
if ( V_42 & V_44 )
F_6 ( V_2 -> V_6 , L_20 ) ;
return V_45 ;
}
static int F_13 ( struct V_46 * V_47 ,
struct V_48 * V_49 )
{
struct V_1 * V_2 = F_14 ( V_49 ) ;
F_15 ( & V_2 -> V_50 ) ;
if ( ! V_49 -> V_51 ) {
T_2 V_20 = F_3 ( V_2 , V_15 ) ;
F_1 ( V_2 , V_15 , V_20 | V_52 ) ;
F_10 ( V_2 ) ;
}
F_16 ( & V_2 -> V_50 ) ;
F_17 ( V_49 , V_47 ,
& V_53 [ V_47 -> V_54 ] ) ;
return 0 ;
}
static void F_18 ( struct V_46 * V_47 ,
struct V_48 * V_49 )
{
struct V_1 * V_2 = F_14 ( V_49 ) ;
F_15 ( & V_2 -> V_50 ) ;
if ( ! V_49 -> V_51 ) {
if ( F_9 ( V_2 ) ) {
F_8 ( V_2 ) ;
F_11 ( V_2 ) ;
}
}
F_16 ( & V_2 -> V_50 ) ;
}
static int F_19 ( struct V_46 * V_47 ,
struct V_55 * V_56 ,
struct V_48 * V_49 )
{
struct V_1 * V_2 = F_14 ( V_49 ) ;
int V_54 = V_47 -> V_54 ;
struct V_57 * V_58 ;
int V_59 ;
int V_60 = 0 ;
V_59 = F_20 ( V_56 ) ;
switch ( V_59 ) {
case 5 :
if ( V_54 == V_61 )
return - V_62 ;
V_60 |= 1 << 4 ;
case 4 :
if ( V_54 == V_61 )
return - V_62 ;
V_60 |= 1 << 3 ;
case 3 :
V_60 |= 1 << 2 ;
case 2 :
V_60 |= 1 << 1 ;
case 1 :
V_60 |= 1 << 0 ;
break;
default:
return - V_62 ;
}
V_58 = F_21 ( V_49 , V_47 ) ;
if ( V_54 == V_63 ) {
V_2 -> V_23 = V_60 << 3 ;
V_58 -> V_64 =
( V_65 - V_2 -> V_36 ) * V_59 ;
} else {
V_2 -> V_24 = V_60 << 0 ;
V_58 -> V_64 = V_2 -> V_37 * V_59 ;
}
return 0 ;
}
static int F_22 ( struct V_46 * V_47 ,
struct V_48 * V_49 )
{
struct V_1 * V_2 = F_14 ( V_49 ) ;
if ( ! F_9 ( V_2 ) ) {
F_7 ( V_2 ) ;
F_5 ( V_2 ) ;
}
return 0 ;
}
static int F_23 ( struct V_48 * V_49 )
{
struct V_1 * V_2 = F_14 ( V_49 ) ;
int V_66 ;
F_24 ( V_2 -> V_6 ) ;
F_25 ( V_2 -> V_6 ) ;
F_1 ( V_2 , V_15 , 0x00 ) ;
V_66 = F_26 ( V_2 -> V_40 , F_12 ,
0 , L_21 , ( void * ) V_2 ) ;
F_27 ( V_2 -> V_6 ) ;
if ( V_66 ) {
F_28 ( V_2 -> V_6 , L_22 ) ;
F_29 ( V_2 -> V_6 ) ;
}
V_2 -> V_36 = 2 ;
V_2 -> V_37 = V_67 - 3 ;
return V_66 ;
}
static int F_30 ( struct V_48 * V_49 )
{
struct V_1 * V_2 = F_14 ( V_49 ) ;
F_31 ( V_2 -> V_40 , ( void * ) V_2 ) ;
F_29 ( V_2 -> V_6 ) ;
return 0 ;
}
void F_32 ( struct V_68 * V_69 ,
T_4 V_70 , T_4 V_71 )
{
struct V_1 * V_2 = F_14 ( V_69 -> V_72 ) ;
V_2 -> V_31 = F_33 ( V_70 ) | F_34 ( V_71 ) ;
}
static int F_35 ( struct V_73 * V_74 )
{
struct V_1 * V_2 ;
struct V_75 * V_76 ;
V_2 = F_36 ( & V_74 -> V_6 , sizeof( struct V_1 ) , V_77 ) ;
if ( ! V_2 )
return - V_78 ;
F_37 ( V_74 , V_2 ) ;
F_38 ( & V_2 -> V_50 ) ;
V_76 = F_39 ( V_74 , V_79 , L_23 ) ;
if ( V_76 == NULL )
return - V_78 ;
V_53 [ 0 ] . V_80 = V_76 -> V_81 + V_16 ;
V_53 [ 1 ] . V_80 = V_76 -> V_81 + V_17 ;
V_76 = F_40 ( V_74 , V_79 , 0 ) ;
if ( V_76 == NULL )
return - V_78 ;
V_76 = F_39 ( V_74 , V_82 , L_24 ) ;
if ( ! V_76 )
return - V_83 ;
V_53 [ 0 ] . V_84 = V_76 -> V_81 ;
V_76 = F_39 ( V_74 , V_82 , L_25 ) ;
if ( ! V_76 )
return - V_83 ;
V_53 [ 1 ] . V_84 = V_76 -> V_81 ;
V_76 = F_39 ( V_74 , V_79 , L_26 ) ;
if ( V_76 == NULL )
return - V_78 ;
if ( ! F_41 ( & V_74 -> V_6 , V_76 -> V_81 ,
F_42 ( V_76 ) , L_21 ) )
return - V_85 ;
V_2 -> V_5 = F_43 ( & V_74 -> V_6 , V_76 -> V_81 ,
F_42 ( V_76 ) ) ;
if ( ! V_2 -> V_5 )
return - V_78 ;
V_2 -> V_40 = F_44 ( V_74 , 0 ) ;
if ( V_2 -> V_40 < 0 )
return V_2 -> V_40 ;
V_2 -> V_6 = & V_74 -> V_6 ;
return F_45 ( & V_74 -> V_6 , & V_86 ) ;
}
static int F_46 ( struct V_73 * V_74 )
{
F_47 ( & V_74 -> V_6 ) ;
return 0 ;
}
