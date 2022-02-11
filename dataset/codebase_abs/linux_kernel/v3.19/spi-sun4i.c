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
if ( V_17 -> V_24 & V_25 )
V_3 &= ~ V_26 ;
else
V_3 |= V_26 ;
F_3 ( V_2 , V_20 , V_3 ) ;
}
static int F_12 ( struct V_27 * V_19 ,
struct V_16 * V_17 ,
struct V_28 * V_29 )
{
struct V_1 * V_2 = F_10 ( V_19 ) ;
unsigned int V_30 , div , V_31 ;
unsigned int V_32 = 0 ;
int V_33 = 0 ;
T_1 V_3 ;
if ( V_29 -> V_6 > V_34 )
return - V_35 ;
F_13 ( & V_2 -> V_36 ) ;
V_2 -> V_14 = V_29 -> V_14 ;
V_2 -> V_13 = V_29 -> V_13 ;
V_2 -> V_6 = V_29 -> V_6 ;
F_3 ( V_2 , V_37 , ~ 0 ) ;
V_3 = F_1 ( V_2 , V_20 ) ;
F_3 ( V_2 , V_20 ,
V_3 | V_38 | V_39 ) ;
if ( V_17 -> V_24 & V_40 )
V_3 |= V_41 ;
else
V_3 &= ~ V_41 ;
if ( V_17 -> V_24 & V_42 )
V_3 |= V_43 ;
else
V_3 &= ~ V_43 ;
if ( V_17 -> V_24 & V_44 )
V_3 |= V_45 ;
else
V_3 &= ~ V_45 ;
if ( V_2 -> V_13 )
V_3 &= ~ V_46 ;
else
V_3 |= V_46 ;
V_3 |= V_47 ;
F_3 ( V_2 , V_20 , V_3 ) ;
V_30 = F_14 ( V_2 -> V_48 ) ;
if ( V_30 < ( 2 * V_17 -> V_49 ) ) {
F_15 ( V_2 -> V_48 , 2 * V_17 -> V_49 ) ;
V_30 = F_14 ( V_2 -> V_48 ) ;
}
div = V_30 / ( 2 * V_17 -> V_49 ) ;
if ( div <= ( V_50 + 1 ) ) {
if ( div > 0 )
div -- ;
V_3 = F_16 ( div ) | V_51 ;
} else {
div = F_17 ( V_30 ) - F_17 ( V_17 -> V_49 ) ;
V_3 = F_18 ( div ) ;
}
F_3 ( V_2 , V_52 , V_3 ) ;
if ( V_2 -> V_14 )
V_32 = V_29 -> V_6 ;
F_3 ( V_2 , V_53 , F_19 ( V_29 -> V_6 ) ) ;
F_3 ( V_2 , V_54 , F_20 ( V_32 ) ) ;
F_7 ( V_2 , V_34 ) ;
F_3 ( V_2 , V_55 , V_56 ) ;
V_3 = F_1 ( V_2 , V_20 ) ;
F_3 ( V_2 , V_20 , V_3 | V_57 ) ;
V_31 = F_21 ( & V_2 -> V_36 ,
F_22 ( 1000 ) ) ;
if ( ! V_31 ) {
V_33 = - V_58 ;
goto V_59;
}
F_5 ( V_2 , V_34 ) ;
V_59:
F_3 ( V_2 , V_55 , 0 ) ;
return V_33 ;
}
static T_3 F_23 ( int V_60 , void * V_61 )
{
struct V_1 * V_2 = V_61 ;
T_1 V_62 = F_1 ( V_2 , V_37 ) ;
if ( V_62 & V_56 ) {
F_3 ( V_2 , V_37 , V_56 ) ;
F_24 ( & V_2 -> V_36 ) ;
return V_63 ;
}
return V_64 ;
}
static int F_25 ( struct V_65 * V_66 )
{
struct V_27 * V_19 = F_26 ( V_66 ) ;
struct V_1 * V_2 = F_10 ( V_19 ) ;
int V_33 ;
V_33 = F_27 ( V_2 -> V_67 ) ;
if ( V_33 ) {
F_28 ( V_66 , L_1 ) ;
goto V_59;
}
V_33 = F_27 ( V_2 -> V_48 ) ;
if ( V_33 ) {
F_28 ( V_66 , L_2 ) ;
goto V_68;
}
F_3 ( V_2 , V_20 ,
V_69 | V_70 | V_71 ) ;
return 0 ;
V_68:
F_29 ( V_2 -> V_67 ) ;
V_59:
return V_33 ;
}
static int F_30 ( struct V_65 * V_66 )
{
struct V_27 * V_19 = F_26 ( V_66 ) ;
struct V_1 * V_2 = F_10 ( V_19 ) ;
F_29 ( V_2 -> V_48 ) ;
F_29 ( V_2 -> V_67 ) ;
return 0 ;
}
static int F_31 ( struct V_72 * V_73 )
{
struct V_27 * V_19 ;
struct V_1 * V_2 ;
struct V_74 * V_75 ;
int V_33 = 0 , V_60 ;
V_19 = F_32 ( & V_73 -> V_66 , sizeof( struct V_1 ) ) ;
if ( ! V_19 ) {
F_28 ( & V_73 -> V_66 , L_3 ) ;
return - V_76 ;
}
F_33 ( V_73 , V_19 ) ;
V_2 = F_10 ( V_19 ) ;
V_75 = F_34 ( V_73 , V_77 , 0 ) ;
V_2 -> V_4 = F_35 ( & V_73 -> V_66 , V_75 ) ;
if ( F_36 ( V_2 -> V_4 ) ) {
V_33 = F_37 ( V_2 -> V_4 ) ;
goto V_78;
}
V_60 = F_38 ( V_73 , 0 ) ;
if ( V_60 < 0 ) {
F_28 ( & V_73 -> V_66 , L_4 ) ;
V_33 = - V_79 ;
goto V_78;
}
V_33 = F_39 ( & V_73 -> V_66 , V_60 , F_23 ,
0 , L_5 , V_2 ) ;
if ( V_33 ) {
F_28 ( & V_73 -> V_66 , L_6 ) ;
goto V_78;
}
V_2 -> V_19 = V_19 ;
V_19 -> V_80 = F_9 ;
V_19 -> V_81 = F_12 ;
V_19 -> V_82 = 4 ;
V_19 -> V_83 = V_40 | V_42 | V_25 | V_44 ;
V_19 -> V_84 = F_40 ( 8 ) ;
V_19 -> V_66 . V_85 = V_73 -> V_66 . V_85 ;
V_19 -> V_86 = true ;
V_2 -> V_67 = F_41 ( & V_73 -> V_66 , L_7 ) ;
if ( F_36 ( V_2 -> V_67 ) ) {
F_28 ( & V_73 -> V_66 , L_8 ) ;
V_33 = F_37 ( V_2 -> V_67 ) ;
goto V_78;
}
V_2 -> V_48 = F_41 ( & V_73 -> V_66 , L_9 ) ;
if ( F_36 ( V_2 -> V_48 ) ) {
F_28 ( & V_73 -> V_66 , L_10 ) ;
V_33 = F_37 ( V_2 -> V_48 ) ;
goto V_78;
}
F_42 ( & V_2 -> V_36 ) ;
V_33 = F_25 ( & V_73 -> V_66 ) ;
if ( V_33 ) {
F_28 ( & V_73 -> V_66 , L_11 ) ;
goto V_78;
}
F_43 ( & V_73 -> V_66 ) ;
F_44 ( & V_73 -> V_66 ) ;
F_45 ( & V_73 -> V_66 ) ;
V_33 = F_46 ( & V_73 -> V_66 , V_19 ) ;
if ( V_33 ) {
F_28 ( & V_73 -> V_66 , L_12 ) ;
goto V_87;
}
return 0 ;
V_87:
F_47 ( & V_73 -> V_66 ) ;
F_30 ( & V_73 -> V_66 ) ;
V_78:
F_48 ( V_19 ) ;
return V_33 ;
}
static int F_49 ( struct V_72 * V_73 )
{
F_47 ( & V_73 -> V_66 ) ;
return 0 ;
}
