static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_5 ;
V_5 = F_2 ( V_2 -> V_6 , V_4 -> clock ) ;
if ( V_5 )
F_3 ( V_2 -> V_7 , L_1 , V_4 -> clock ) ;
V_2 -> V_8 = F_4 ( V_2 -> V_6 ) ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_9 * V_10 ;
V_10 = F_6 ( V_2 -> V_7 , sizeof( * V_10 ) , V_11 ) ;
if ( ! V_10 )
return - V_12 ;
V_10 -> V_13 = F_7 ( V_2 -> V_7 -> V_14 ,
L_2 ) ;
if ( F_8 ( V_10 -> V_13 ) )
V_10 -> V_13 = NULL ;
V_10 -> V_15 = F_9 ( V_2 -> V_7 -> V_14 , L_3 ) ;
if ( V_10 -> V_15 < 0 )
V_10 -> V_15 = 0 ;
V_2 -> V_10 = V_10 ;
return 0 ;
}
static int F_10 ( struct V_16 * V_17 , struct V_3 * V_4 )
{
struct V_18 * V_19 = F_11 ( V_17 ) ;
struct V_9 * V_10 ;
struct V_1 * V_2 ;
int V_20 , V_21 ;
int V_5 ;
V_2 = V_19 -> V_2 ;
V_10 = V_2 -> V_10 ;
if ( ! V_10 || ! V_10 -> V_13 )
return 0 ;
if ( V_4 -> V_22 == V_23 ) {
V_5 = F_12 ( V_10 -> V_13 , V_24 ,
V_25 , 0 ) ;
V_20 = 3000000 ;
V_21 = 3000000 ;
} else if ( V_4 -> V_22 == V_26 ) {
V_5 = F_12 ( V_10 -> V_13 , V_24 ,
V_25 , V_25 ) ;
V_20 = 1800000 ;
V_21 = 1800000 ;
} else {
F_13 ( V_2 -> V_7 , L_4 ) ;
return - V_27 ;
}
if ( V_5 ) {
F_13 ( V_2 -> V_7 , L_5 ) ;
return V_5 ;
}
if ( F_14 ( V_17 -> V_28 . V_29 ) )
return 0 ;
V_5 = F_15 ( V_17 -> V_28 . V_29 , V_20 , V_21 ) ;
if ( V_5 ) {
F_13 ( V_2 -> V_7 , L_6 ,
V_5 , V_20 , V_21 ) ;
return V_5 ;
}
return 0 ;
}
static void F_16 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_5 ;
unsigned int clock ;
clock = ( V_4 -> clock <= 25000000 ) ? 25000000 : V_4 -> clock ;
V_5 = F_2 ( V_2 -> V_30 , clock ) ;
if ( V_5 )
F_3 ( V_2 -> V_7 , L_1 , clock ) ;
V_2 -> V_8 = F_4 ( V_2 -> V_30 ) ;
}
static int F_17 ( struct V_18 * V_19 , T_1 V_31 )
{
return 0 ;
}
static void F_18 ( struct V_1 * V_2 , int V_32 ,
int V_33 )
{
T_1 V_34 ;
T_1 V_35 ;
T_1 V_36 = 0 ;
T_1 V_37 = 0 ;
T_1 V_38 ;
int V_15 ;
struct V_9 * V_10 ;
V_10 = V_2 -> V_10 ;
V_15 = V_10 -> V_15 ;
V_34 = V_39 [ V_15 ] [ V_32 ] . V_34 ;
V_35 = V_39 [ V_15 ] [ V_32 ] . V_35 ;
if ( V_33 == - 1 )
V_33 = ( V_39 [ V_15 ] [ V_32 ] . V_40 +
V_39 [ V_15 ] [ V_32 ] . V_41 ) / 2 ;
switch ( V_32 ) {
case V_42 :
if ( V_33 >= V_43 &&
V_33 <= V_44 )
V_36 = 1 ;
case V_45 :
if ( V_33 >= V_46 &&
V_33 <= V_47 )
V_37 = 1 ;
break;
}
F_19 ( V_2 , V_48 , 0x0 ) ;
F_20 ( 5 , 10 ) ;
V_38 = F_21 ( V_49 , V_33 ) |
F_21 ( V_50 , V_35 ) |
F_21 ( V_51 , V_34 ) ;
F_19 ( V_2 , V_52 , V_38 ) ;
F_19 ( V_2 , V_53 , V_37 ) ;
V_38 = F_21 ( V_54 , V_55 ) |
F_21 ( V_56 , V_36 ) ;
F_19 ( V_2 , V_48 , ( unsigned int ) V_38 | V_57 ) ;
F_20 ( 1000 , 2000 ) ;
}
static int F_22 ( struct V_1 * V_2 )
{
F_19 ( V_2 , V_58 , F_23 ( V_59 ,
V_60 ) ) ;
F_18 ( V_2 , V_61 , - 1 ) ;
V_2 -> V_8 /= ( V_55 + 1 ) ;
return 0 ;
}
static int F_24 ( struct V_1 * V_2 , bool V_62 )
{
int V_5 ;
unsigned int V_63 ;
struct V_9 * V_10 ;
V_10 = V_2 -> V_10 ;
V_63 = V_62 ? V_64 : 0 ;
V_5 = F_12 ( V_10 -> V_13 , V_65 ,
V_64 , V_63 ) ;
if ( V_5 ) {
F_25 ( V_2 -> V_7 , L_7 , V_63 ) ;
return V_5 ;
}
return 0 ;
}
static void F_26 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_5 ;
unsigned long V_66 ;
unsigned long V_67 ;
struct V_9 * V_10 = V_2 -> V_10 ;
if ( ! V_4 -> clock || V_4 -> clock == V_10 -> V_68 )
return;
V_66 = V_4 -> clock * ( V_55 + 1 ) ;
V_5 = F_2 ( V_2 -> V_6 , V_66 ) ;
if ( V_5 ) {
F_25 ( V_2 -> V_7 , L_8 , V_66 ) ;
return;
}
V_67 = F_4 ( V_2 -> V_6 ) ;
F_18 ( V_2 , V_4 -> V_32 , - 1 ) ;
V_2 -> V_8 = V_67 / ( V_55 + 1 ) ;
V_2 -> V_69 = 0 ;
V_10 -> V_68 = V_2 -> V_8 ;
}
static int F_27 ( unsigned int V_70 )
{
int V_71 ;
int V_72 ;
unsigned int V_73 ;
unsigned int V_74 ;
unsigned int V_75 = 0 ;
unsigned int V_76 = 0 ;
unsigned int V_77 = 0 ;
if ( ! V_70 )
return - V_78 ;
if ( ~ V_70 == 0 )
return 0 ;
V_71 = F_28 ( V_70 ) - 1 ;
while ( V_71 < 32 ) {
V_73 = F_29 ( V_70 , V_71 ) ;
V_74 = F_28 ( ~ V_73 ) - 1 ;
if ( V_74 > V_76 ) {
V_76 = V_74 ;
V_75 = V_71 ;
}
V_72 = F_28 ( V_73 >> V_74 ) - 1 ;
if ( V_72 < 0 )
break;
V_71 += V_74 + V_72 ;
}
V_77 = V_75 + V_76 / 2 ;
if ( V_77 >= 32 )
V_77 %= 32 ;
return V_77 ;
}
static int F_30 ( struct V_18 * V_19 , T_1 V_31 )
{
int V_71 = 0 ;
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_16 * V_17 = V_19 -> V_17 ;
int V_33 = 0 ;
T_1 V_79 = 0 ;
int V_80 = 0 ;
for ( V_71 = 0 ; V_71 < V_81 ; ++ V_71 , ++ V_33 ) {
V_33 %= 32 ;
F_19 ( V_2 , V_82 , ~ 0 ) ;
F_18 ( V_2 , V_17 -> V_4 . V_32 , V_33 ) ;
if ( ! F_31 ( V_17 , V_31 , NULL ) )
V_79 |= ( 1 << V_33 ) ;
else
V_79 &= ~ ( 1 << V_33 ) ;
}
V_80 = F_27 ( V_79 ) ;
if ( V_80 < 0 ) {
F_25 ( V_2 -> V_7 , L_9 ) ;
return - V_78 ;
}
F_18 ( V_2 , V_17 -> V_4 . V_32 , V_80 ) ;
F_32 ( V_2 -> V_7 , L_10 ,
V_80 , V_79 ) ;
return 0 ;
}
static int F_33 ( struct V_16 * V_17 ,
struct V_3 * V_4 )
{
int V_5 = 0 ;
struct V_18 * V_19 = F_11 ( V_17 ) ;
struct V_9 * V_10 ;
struct V_1 * V_2 ;
V_2 = V_19 -> V_2 ;
V_10 = V_2 -> V_10 ;
if ( ! V_10 || ! V_10 -> V_13 )
return 0 ;
if ( V_10 -> V_15 == V_83 )
return 0 ;
if ( V_4 -> V_22 == V_23 )
V_5 = F_24 ( V_2 , 0 ) ;
else if ( V_4 -> V_22 == V_26 )
V_5 = F_24 ( V_2 , 1 ) ;
if ( V_5 )
return V_5 ;
if ( ! F_8 ( V_17 -> V_28 . V_29 ) ) {
V_5 = F_34 ( V_17 , V_4 ) ;
if ( V_5 ) {
F_25 ( V_2 -> V_7 , L_11 , V_5 ) ;
return V_5 ;
}
}
return 0 ;
}
static int F_35 ( struct V_84 * V_85 )
{
const struct V_86 * V_87 ;
const struct V_88 * V_89 ;
V_89 = F_36 ( V_90 , V_85 -> V_7 . V_14 ) ;
V_87 = V_89 -> V_91 ;
return F_37 ( V_85 , V_87 ) ;
}
