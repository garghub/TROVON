static inline T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
static inline void F_3 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_5 )
{
F_4 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static int F_5 ( struct V_6 * V_7 )
{
struct V_1 * V_8 = F_6 ( V_7 ) ;
T_1 V_9 = F_1 ( V_8 , V_10 ) ;
return ! ! ( V_9 & V_11 ) ;
}
static int F_7 ( struct V_1 * V_8 )
{
struct V_6 * V_7 = V_8 -> V_7 ;
struct V_12 * V_13 = V_7 -> V_13 ;
T_1 V_9 ;
T_1 V_14 = V_15 ;
if ( F_8 ( V_7 ) ) {
F_9 ( V_13 , L_1 ) ;
return 0 ;
}
if ( V_8 -> V_16 == 1 ) {
F_10 ( V_7 -> V_17 + V_14 + V_18 ,
4 , & V_9 ) ;
if ( ( V_9 & V_19 ) != V_20 ) {
V_9 &= ~ ( ( T_1 ) V_19 ) ;
V_9 |= V_20 ;
F_11 ( V_7 -> V_17 + V_14 +
V_18 , 4 , V_9 ) ;
}
F_10 ( V_7 -> V_17 + V_14 + V_21 ,
2 , & V_9 ) ;
if ( ( V_9 & V_19 ) != V_20 ) {
V_9 &= ~ ( ( T_1 ) V_19 ) ;
V_9 |= V_20 ;
F_11 ( V_7 -> V_17 + V_14 +
V_21 , 2 , V_9 ) ;
}
}
V_9 = F_1 ( V_8 , V_22 ) ;
V_9 |= V_23 ;
F_3 ( V_8 , V_22 , V_9 ) ;
return F_12 ( V_7 ) ;
}
static void F_13 ( struct V_1 * V_8 )
{
F_3 ( V_8 , V_24 ,
~ V_25 ) ;
F_3 ( V_8 ,
V_26 , V_25 ) ;
F_3 ( V_8 , V_27 ,
~ V_28 & ~ V_29 ) ;
F_3 ( V_8 , V_30 ,
V_29 | V_28 ) ;
}
static void F_14 ( struct V_31 * V_32 )
{
struct V_6 * V_7 = F_15 ( V_32 ) ;
struct V_1 * V_8 = F_6 ( V_7 ) ;
V_32 -> V_33 &= V_34 ;
V_32 -> V_35 &= V_34 ;
V_32 -> V_36 &= V_34 ;
V_32 -> V_37 &= V_34 ;
F_16 ( V_32 ) ;
F_7 ( V_8 ) ;
F_17 ( V_32 ) ;
F_13 ( V_8 ) ;
}
static int F_18 ( struct V_38 * V_39 , unsigned int V_40 ,
T_2 V_41 )
{
F_19 ( V_40 , & V_42 , V_43 ) ;
F_20 ( V_40 , V_39 -> V_44 ) ;
return 0 ;
}
static int F_21 ( struct V_31 * V_32 )
{
struct V_6 * V_7 = F_15 ( V_32 ) ;
struct V_12 * V_13 = V_7 -> V_13 ;
struct V_1 * V_8 = F_6 ( V_7 ) ;
struct V_45 * V_46 = V_13 -> V_47 ;
struct V_45 * V_48 = F_22 ( V_46 , NULL ) ;
if ( ! V_48 ) {
F_9 ( V_13 , L_2 ) ;
return - V_49 ;
}
V_8 -> V_38 = F_23 ( V_48 , 4 ,
& V_50 , V_32 ) ;
if ( ! V_8 -> V_38 ) {
F_9 ( V_13 , L_3 ) ;
return - V_49 ;
}
return 0 ;
}
static T_3 F_24 ( int V_40 , void * V_51 )
{
struct V_1 * V_8 = V_51 ;
struct V_6 * V_7 = V_8 -> V_7 ;
struct V_31 * V_32 = & V_7 -> V_32 ;
T_1 V_9 ;
V_9 = F_1 ( V_8 , V_27 ) ;
switch ( V_9 ) {
case V_29 :
F_25 ( V_32 ) ;
break;
case V_52 :
case V_53 :
case V_54 :
case V_55 :
F_26 ( F_27 ( V_8 -> V_38 ,
F_28 ( V_9 ) ) ) ;
break;
}
F_3 ( V_8 , V_27 , V_9 ) ;
return V_56 ;
}
static T_3 F_29 ( int V_40 , void * V_51 )
{
struct V_1 * V_8 = V_51 ;
struct V_6 * V_7 = V_8 -> V_7 ;
struct V_12 * V_13 = V_7 -> V_13 ;
T_1 V_9 ;
V_9 = F_1 ( V_8 , V_24 ) ;
if ( V_9 & V_57 )
F_30 ( V_13 , L_4 ) ;
if ( V_9 & V_58 )
F_30 ( V_13 , L_5 ) ;
if ( V_9 & V_59 )
F_30 ( V_13 , L_6 ) ;
if ( V_9 & V_60 )
F_30 ( V_13 , L_7 ) ;
if ( V_9 & V_61 )
F_30 ( V_13 , L_8 ) ;
if ( V_9 & V_62 )
F_30 ( V_13 , L_9 ) ;
if ( V_9 & V_63 )
F_30 ( V_13 ,
L_10 ) ;
if ( V_9 & V_64 )
F_30 ( V_13 ,
L_11 ) ;
if ( V_9 & V_65 )
F_30 ( V_13 , L_12 ) ;
if ( V_9 & V_66 )
F_30 ( V_13 , L_13 ) ;
if ( V_9 & V_67 )
F_30 ( V_13 , L_14 ) ;
if ( V_9 & V_68 )
F_30 ( V_13 , L_15 ) ;
if ( V_9 & V_69 )
F_30 ( V_13 , L_16 ) ;
F_3 ( V_8 , V_24 , V_9 ) ;
return V_56 ;
}
static int T_4 F_31 ( struct V_1 * V_8 ,
struct V_70 * V_71 )
{
int V_72 ;
struct V_6 * V_7 = V_8 -> V_7 ;
struct V_31 * V_32 = & V_7 -> V_32 ;
struct V_12 * V_13 = V_7 -> V_13 ;
struct V_73 * V_74 ;
V_32 -> V_40 = F_32 ( V_71 , 1 ) ;
if ( V_32 -> V_40 < 0 ) {
F_9 ( V_13 , L_17 ) ;
return - V_75 ;
}
V_72 = F_33 ( V_13 , V_32 -> V_40 , F_24 ,
V_76 | V_77 ,
L_18 , V_8 ) ;
if ( V_72 ) {
F_9 ( V_13 , L_19 ) ;
return V_72 ;
}
V_72 = F_21 ( V_32 ) ;
if ( V_72 < 0 )
return V_72 ;
V_74 = F_34 ( V_71 , V_78 , L_20 ) ;
V_7 -> V_17 = F_35 ( V_13 , V_74 -> V_79 , F_36 ( V_74 ) ) ;
if ( ! V_7 -> V_17 )
return - V_80 ;
V_72 = F_37 ( V_32 ) ;
if ( V_72 ) {
F_9 ( V_13 , L_21 ) ;
return V_72 ;
}
return 0 ;
}
static void F_38 ( struct V_1 * V_8 )
{
int V_81 = V_8 -> V_81 ;
while ( V_81 -- ) {
F_39 ( V_8 -> V_82 [ V_81 ] ) ;
F_40 ( V_8 -> V_82 [ V_81 ] ) ;
}
}
static int F_41 ( struct V_1 * V_8 )
{
int V_81 = V_8 -> V_81 ;
int V_72 ;
int V_83 ;
for ( V_83 = 0 ; V_83 < V_81 ; V_83 ++ ) {
V_72 = F_42 ( V_8 -> V_82 [ V_83 ] ) ;
if ( V_72 < 0 )
goto V_84;
V_72 = F_43 ( V_8 -> V_82 [ V_83 ] ) ;
if ( V_72 < 0 ) {
F_40 ( V_8 -> V_82 [ V_83 ] ) ;
goto V_84;
}
}
return 0 ;
V_84:
while ( -- V_83 >= 0 ) {
F_39 ( V_8 -> V_82 [ V_83 ] ) ;
F_40 ( V_8 -> V_82 [ V_83 ] ) ;
}
return V_72 ;
}
static int T_4 F_44 ( struct V_70 * V_71 )
{
T_1 V_9 ;
int V_72 ;
int V_40 ;
int V_83 ;
int V_81 ;
struct V_82 * * V_82 ;
void T_5 * V_4 ;
struct V_73 * V_74 ;
struct V_6 * V_7 ;
struct V_31 * V_32 ;
struct V_1 * V_8 ;
struct V_12 * V_13 = & V_71 -> V_13 ;
struct V_45 * V_85 = V_13 -> V_47 ;
char V_86 [ 10 ] ;
struct V_87 * V_88 ;
V_8 = F_45 ( V_13 , sizeof( * V_8 ) , V_89 ) ;
if ( ! V_8 )
return - V_80 ;
V_7 = F_45 ( V_13 , sizeof( * V_7 ) , V_89 ) ;
if ( ! V_7 )
return - V_80 ;
V_7 -> V_13 = V_13 ;
V_7 -> V_90 = & V_91 ;
V_32 = & V_7 -> V_32 ;
V_32 -> V_90 = & V_92 ;
V_40 = F_32 ( V_71 , 0 ) ;
if ( V_40 < 0 ) {
F_9 ( V_13 , L_17 ) ;
return - V_75 ;
}
V_72 = F_33 ( V_13 , V_40 , F_29 ,
V_76 , L_22 , V_8 ) ;
if ( V_72 ) {
F_9 ( V_13 , L_19 ) ;
return V_72 ;
}
V_74 = F_34 ( V_71 , V_78 , L_23 ) ;
V_4 = F_46 ( V_13 , V_74 -> V_79 , F_36 ( V_74 ) ) ;
if ( ! V_4 )
return - V_80 ;
V_81 = F_47 ( V_85 , L_24 ) ;
if ( V_81 < 0 ) {
F_9 ( V_13 , L_25 ) ;
return V_81 ;
}
V_82 = F_45 ( V_13 , sizeof( * V_82 ) * V_81 , V_89 ) ;
if ( ! V_82 )
return - V_80 ;
for ( V_83 = 0 ; V_83 < V_81 ; V_83 ++ ) {
snprintf ( V_86 , sizeof( V_86 ) , L_26 , V_83 ) ;
V_82 [ V_83 ] = F_48 ( V_13 , V_86 ) ;
if ( F_49 ( V_82 [ V_83 ] ) )
return F_50 ( V_82 [ V_83 ] ) ;
}
V_8 -> V_4 = V_4 ;
V_8 -> V_82 = V_82 ;
V_8 -> V_7 = V_7 ;
V_8 -> V_81 = V_81 ;
V_72 = F_41 ( V_8 ) ;
if ( V_72 ) {
F_9 ( V_13 , L_27 ) ;
return V_72 ;
}
F_51 ( V_71 , V_8 ) ;
F_52 ( V_13 ) ;
V_72 = F_53 ( V_13 ) ;
if ( V_72 < 0 ) {
F_9 ( V_13 , L_28 ) ;
goto V_93;
}
V_88 = F_54 ( V_13 , NULL , V_94 ) ;
if ( F_49 ( V_88 ) ) {
V_72 = F_50 ( V_88 ) ;
F_9 ( & V_71 -> V_13 , L_29 , V_72 ) ;
goto V_95;
}
V_9 = F_1 ( V_8 , V_22 ) ;
V_9 &= ~ V_23 ;
F_3 ( V_8 , V_22 , V_9 ) ;
V_8 -> V_16 = F_55 ( V_85 ) ;
if ( V_8 -> V_16 < 0 || V_8 -> V_16 > 2 )
V_8 -> V_16 = 2 ;
V_72 = F_31 ( V_8 , V_71 ) ;
if ( V_72 < 0 )
goto V_95;
return 0 ;
V_95:
F_56 ( V_13 ) ;
V_93:
F_57 ( V_13 ) ;
F_38 ( V_8 ) ;
return V_72 ;
}
static int F_58 ( struct V_12 * V_13 )
{
struct V_1 * V_8 = F_59 ( V_13 ) ;
struct V_6 * V_7 = V_8 -> V_7 ;
T_1 V_96 ;
V_96 = F_60 ( V_7 , V_97 ) ;
V_96 &= ~ V_98 ;
F_61 ( V_7 , V_97 , V_96 ) ;
return 0 ;
}
static int F_62 ( struct V_12 * V_13 )
{
struct V_1 * V_8 = F_59 ( V_13 ) ;
struct V_6 * V_7 = V_8 -> V_7 ;
T_1 V_96 ;
V_96 = F_60 ( V_7 , V_97 ) ;
V_96 |= V_98 ;
F_61 ( V_7 , V_97 , V_96 ) ;
return 0 ;
}
static int F_63 ( struct V_12 * V_13 )
{
struct V_1 * V_8 = F_59 ( V_13 ) ;
F_38 ( V_8 ) ;
return 0 ;
}
static int F_64 ( struct V_12 * V_13 )
{
struct V_1 * V_8 = F_59 ( V_13 ) ;
int V_72 ;
V_72 = F_41 ( V_8 ) ;
if ( V_72 ) {
F_9 ( V_13 , L_27 ) ;
return V_72 ;
}
return 0 ;
}
