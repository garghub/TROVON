static inline T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
static inline void F_3 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_5 )
{
F_4 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static inline void F_5 ( struct V_1 * V_2 , int V_6 )
{
T_1 V_3 , V_7 ;
T_2 V_8 ;
V_3 = F_1 ( V_2 , V_9 ) ;
V_3 &= V_10 ;
V_7 = V_3 >> V_11 ;
if ( V_6 > V_7 )
V_6 = V_7 ;
while ( V_6 -- ) {
V_8 = F_6 ( V_2 -> V_4 + V_12 ) ;
if ( V_2 -> V_13 )
* V_2 -> V_13 ++ = V_8 ;
}
}
static inline void F_7 ( struct V_1 * V_2 , int V_6 )
{
T_2 V_8 ;
if ( V_6 > V_2 -> V_6 )
V_6 = V_2 -> V_6 ;
while ( V_6 -- ) {
V_8 = V_2 -> V_14 ? * V_2 -> V_14 ++ : 0 ;
F_8 ( V_8 , V_2 -> V_4 + V_15 ) ;
V_2 -> V_6 -- ;
}
}
static void F_9 ( struct V_16 * V_17 , bool V_18 )
{
struct V_1 * V_2 = F_10 ( V_17 -> V_19 ) ;
T_1 V_3 ;
V_3 = F_1 ( V_2 , V_20 ) ;
V_3 &= ~ V_21 ;
V_3 |= F_11 ( V_17 -> V_22 ) ;
if ( V_18 )
V_3 |= V_23 ;
else
V_3 &= ~ V_23 ;
F_3 ( V_2 , V_20 , V_3 ) ;
}
static T_3 F_12 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = F_10 ( V_17 -> V_19 ) ;
return V_2 -> V_24 - 1 ;
}
static int F_13 ( struct V_25 * V_19 ,
struct V_16 * V_17 ,
struct V_26 * V_27 )
{
struct V_1 * V_2 = F_10 ( V_19 ) ;
unsigned int V_28 , div , V_29 ;
unsigned int V_30 , V_31 , V_32 ;
unsigned int V_33 = 0 ;
int V_34 = 0 ;
T_1 V_3 ;
if ( V_27 -> V_6 > V_2 -> V_24 )
return - V_35 ;
F_14 ( & V_2 -> V_36 ) ;
V_2 -> V_14 = V_27 -> V_14 ;
V_2 -> V_13 = V_27 -> V_13 ;
V_2 -> V_6 = V_27 -> V_6 ;
F_3 ( V_2 , V_37 , ~ 0 ) ;
F_3 ( V_2 , V_38 ,
V_39 | V_40 ) ;
V_3 = F_1 ( V_2 , V_20 ) ;
if ( V_17 -> V_41 & V_42 )
V_3 |= V_43 ;
else
V_3 &= ~ V_43 ;
if ( V_17 -> V_41 & V_44 )
V_3 |= V_45 ;
else
V_3 &= ~ V_45 ;
if ( V_17 -> V_41 & V_46 )
V_3 |= V_47 ;
else
V_3 &= ~ V_47 ;
if ( V_2 -> V_13 )
V_3 &= ~ V_48 ;
else
V_3 |= V_48 ;
V_3 |= V_49 ;
F_3 ( V_2 , V_20 , V_3 ) ;
V_28 = F_15 ( V_2 -> V_50 ) ;
if ( V_28 < ( 2 * V_27 -> V_51 ) ) {
F_16 ( V_2 -> V_50 , 2 * V_27 -> V_51 ) ;
V_28 = F_15 ( V_2 -> V_50 ) ;
}
div = V_28 / ( 2 * V_27 -> V_51 ) ;
if ( div <= ( V_52 + 1 ) ) {
if ( div > 0 )
div -- ;
V_3 = F_17 ( div ) | V_53 ;
} else {
div = F_18 ( V_28 ) - F_18 ( V_27 -> V_51 ) ;
V_3 = F_19 ( div ) ;
}
F_3 ( V_2 , V_54 , V_3 ) ;
if ( V_2 -> V_14 )
V_33 = V_27 -> V_6 ;
F_3 ( V_2 , V_55 , F_20 ( V_27 -> V_6 ) ) ;
F_3 ( V_2 , V_56 , F_21 ( V_33 ) ) ;
F_3 ( V_2 , V_57 ,
F_22 ( V_33 ) ) ;
F_7 ( V_2 , V_2 -> V_24 ) ;
F_3 ( V_2 , V_58 , V_59 ) ;
V_3 = F_1 ( V_2 , V_20 ) ;
F_3 ( V_2 , V_20 , V_3 | V_60 ) ;
V_32 = F_23 ( V_27 -> V_6 * 8 * 2 / ( V_27 -> V_51 / 1000 ) , 100U ) ;
V_30 = V_61 ;
V_29 = F_24 ( & V_2 -> V_36 ,
F_25 ( V_32 ) ) ;
V_31 = V_61 ;
if ( ! V_29 ) {
F_26 ( & V_19 -> V_62 ,
L_1 ,
F_27 ( & V_17 -> V_62 ) , V_27 -> V_6 , V_27 -> V_51 ,
F_28 ( V_31 - V_30 ) , V_32 ) ;
V_34 = - V_63 ;
goto V_64;
}
F_5 ( V_2 , V_2 -> V_24 ) ;
V_64:
F_3 ( V_2 , V_58 , 0 ) ;
return V_34 ;
}
static T_4 F_29 ( int V_65 , void * V_66 )
{
struct V_1 * V_2 = V_66 ;
T_1 V_67 = F_1 ( V_2 , V_37 ) ;
if ( V_67 & V_59 ) {
F_3 ( V_2 , V_37 , V_59 ) ;
F_30 ( & V_2 -> V_36 ) ;
return V_68 ;
}
return V_69 ;
}
static int F_31 ( struct V_70 * V_62 )
{
struct V_25 * V_19 = F_32 ( V_62 ) ;
struct V_1 * V_2 = F_10 ( V_19 ) ;
int V_34 ;
V_34 = F_33 ( V_2 -> V_71 ) ;
if ( V_34 ) {
F_34 ( V_62 , L_2 ) ;
goto V_64;
}
V_34 = F_33 ( V_2 -> V_50 ) ;
if ( V_34 ) {
F_34 ( V_62 , L_3 ) ;
goto V_72;
}
V_34 = F_35 ( V_2 -> V_73 ) ;
if ( V_34 ) {
F_34 ( V_62 , L_4 ) ;
goto V_74;
}
F_3 ( V_2 , V_75 ,
V_76 | V_77 | V_78 ) ;
return 0 ;
V_74:
F_36 ( V_2 -> V_50 ) ;
V_72:
F_36 ( V_2 -> V_71 ) ;
V_64:
return V_34 ;
}
static int F_37 ( struct V_70 * V_62 )
{
struct V_25 * V_19 = F_32 ( V_62 ) ;
struct V_1 * V_2 = F_10 ( V_19 ) ;
F_38 ( V_2 -> V_73 ) ;
F_36 ( V_2 -> V_50 ) ;
F_36 ( V_2 -> V_71 ) ;
return 0 ;
}
static int F_39 ( struct V_79 * V_80 )
{
struct V_25 * V_19 ;
struct V_1 * V_2 ;
struct V_81 * V_82 ;
int V_34 = 0 , V_65 ;
V_19 = F_40 ( & V_80 -> V_62 , sizeof( struct V_1 ) ) ;
if ( ! V_19 ) {
F_34 ( & V_80 -> V_62 , L_5 ) ;
return - V_83 ;
}
F_41 ( V_80 , V_19 ) ;
V_2 = F_10 ( V_19 ) ;
V_82 = F_42 ( V_80 , V_84 , 0 ) ;
V_2 -> V_4 = F_43 ( & V_80 -> V_62 , V_82 ) ;
if ( F_44 ( V_2 -> V_4 ) ) {
V_34 = F_45 ( V_2 -> V_4 ) ;
goto V_85;
}
V_65 = F_46 ( V_80 , 0 ) ;
if ( V_65 < 0 ) {
F_34 ( & V_80 -> V_62 , L_6 ) ;
V_34 = - V_86 ;
goto V_85;
}
V_34 = F_47 ( & V_80 -> V_62 , V_65 , F_29 ,
0 , L_7 , V_2 ) ;
if ( V_34 ) {
F_34 ( & V_80 -> V_62 , L_8 ) ;
goto V_85;
}
V_2 -> V_19 = V_19 ;
V_2 -> V_24 = ( unsigned long ) F_48 ( & V_80 -> V_62 ) ;
V_19 -> V_87 = 100 * 1000 * 1000 ;
V_19 -> V_88 = 3 * 1000 ;
V_19 -> V_89 = F_9 ;
V_19 -> V_90 = F_13 ;
V_19 -> V_91 = 4 ;
V_19 -> V_92 = V_42 | V_44 | V_93 | V_46 ;
V_19 -> V_94 = F_49 ( 8 ) ;
V_19 -> V_62 . V_95 = V_80 -> V_62 . V_95 ;
V_19 -> V_96 = true ;
V_19 -> V_97 = F_12 ;
V_2 -> V_71 = F_50 ( & V_80 -> V_62 , L_9 ) ;
if ( F_44 ( V_2 -> V_71 ) ) {
F_34 ( & V_80 -> V_62 , L_10 ) ;
V_34 = F_45 ( V_2 -> V_71 ) ;
goto V_85;
}
V_2 -> V_50 = F_50 ( & V_80 -> V_62 , L_11 ) ;
if ( F_44 ( V_2 -> V_50 ) ) {
F_34 ( & V_80 -> V_62 , L_12 ) ;
V_34 = F_45 ( V_2 -> V_50 ) ;
goto V_85;
}
F_51 ( & V_2 -> V_36 ) ;
V_2 -> V_73 = F_52 ( & V_80 -> V_62 , NULL ) ;
if ( F_44 ( V_2 -> V_73 ) ) {
F_34 ( & V_80 -> V_62 , L_13 ) ;
V_34 = F_45 ( V_2 -> V_73 ) ;
goto V_85;
}
V_34 = F_31 ( & V_80 -> V_62 ) ;
if ( V_34 ) {
F_34 ( & V_80 -> V_62 , L_14 ) ;
goto V_85;
}
F_53 ( & V_80 -> V_62 ) ;
F_54 ( & V_80 -> V_62 ) ;
F_55 ( & V_80 -> V_62 ) ;
V_34 = F_56 ( & V_80 -> V_62 , V_19 ) ;
if ( V_34 ) {
F_34 ( & V_80 -> V_62 , L_15 ) ;
goto V_98;
}
return 0 ;
V_98:
F_57 ( & V_80 -> V_62 ) ;
F_37 ( & V_80 -> V_62 ) ;
V_85:
F_58 ( V_19 ) ;
return V_34 ;
}
static int F_59 ( struct V_79 * V_80 )
{
F_57 ( & V_80 -> V_62 ) ;
return 0 ;
}
