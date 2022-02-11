static inline T_1 F_1 ( struct V_1 * V_2 , unsigned V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
static inline void F_3 ( struct V_1 * V_2 , unsigned V_3 , T_1 V_5 )
{
F_4 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static inline void F_5 ( struct V_1 * V_2 , int V_6 )
{
T_2 V_7 ;
while ( V_6 -- ) {
V_7 = F_1 ( V_2 , V_8 ) ;
if ( V_2 -> V_9 )
* V_2 -> V_9 ++ = V_7 ;
}
}
static inline void F_6 ( struct V_1 * V_2 , int V_6 )
{
T_2 V_7 ;
if ( V_6 > V_2 -> V_6 )
V_6 = V_2 -> V_6 ;
while ( V_6 -- ) {
V_7 = V_2 -> V_10 ? * V_2 -> V_10 ++ : 0 ;
F_3 ( V_2 , V_8 , V_7 ) ;
V_2 -> V_6 -- ;
}
}
static T_3 F_7 ( int V_11 , void * V_12 )
{
struct V_13 * V_14 = V_12 ;
struct V_1 * V_2 = F_8 ( V_14 ) ;
T_1 V_15 = F_1 ( V_2 , V_16 ) ;
if ( V_2 -> V_6 && ( V_15 & V_17 ) ) {
F_5 ( V_2 , 12 ) ;
F_6 ( V_2 , 12 ) ;
return V_18 ;
}
if ( V_15 & V_19 ) {
if ( V_2 -> V_6 ) {
F_6 ( V_2 , 16 ) ;
} else {
V_15 &= ~ ( V_20 | V_21 ) ;
F_3 ( V_2 , V_16 , V_15 ) ;
F_9 ( & V_2 -> V_22 ) ;
}
return V_18 ;
}
return V_23 ;
}
static int F_10 ( struct V_24 * V_25 ,
struct V_26 * V_27 )
{
struct V_1 * V_2 = F_8 ( V_25 -> V_14 ) ;
unsigned long V_28 , V_29 , V_30 ;
T_1 V_15 = V_20 | V_21 | V_31 ;
V_28 = V_27 -> V_32 ;
V_29 = F_11 ( V_2 -> V_33 ) ;
if ( V_28 >= V_29 / 2 ) {
V_30 = 2 ;
} else if ( V_28 ) {
V_30 = F_12 ( F_13 ( V_29 , V_28 ) ) ;
if ( V_30 >= 65536 )
V_30 = 0 ;
} else
V_30 = 0 ;
if ( V_25 -> V_34 & V_35 )
V_15 |= V_36 ;
if ( V_25 -> V_34 & V_37 )
V_15 |= V_38 ;
if ( ! ( V_25 -> V_34 & V_39 ) ) {
if ( V_25 -> V_34 & V_40 ) {
V_15 |= V_41 ;
V_15 |= V_42 << V_25 -> V_43 ;
}
V_15 |= V_25 -> V_43 ;
}
F_14 ( V_2 -> V_22 ) ;
V_2 -> V_10 = V_27 -> V_10 ;
V_2 -> V_9 = V_27 -> V_9 ;
V_2 -> V_6 = V_27 -> V_6 ;
F_3 ( V_2 , V_44 , V_30 ) ;
F_3 ( V_2 , V_16 , V_15 ) ;
return 0 ;
}
static int F_15 ( struct V_24 * V_25 ,
struct V_26 * V_27 , bool V_45 )
{
struct V_1 * V_2 = F_8 ( V_25 -> V_14 ) ;
T_1 V_15 = F_1 ( V_2 , V_16 ) ;
while ( V_15 & V_46 ) {
F_5 ( V_2 , 1 ) ;
V_15 = F_1 ( V_2 , V_16 ) ;
}
if ( V_27 -> V_47 )
F_16 ( V_27 -> V_47 ) ;
if ( V_45 )
F_3 ( V_2 , V_16 , V_15 & ~ V_31 ) ;
return 0 ;
}
static int F_17 ( struct V_13 * V_14 ,
struct V_48 * V_49 )
{
struct V_1 * V_2 = F_8 ( V_14 ) ;
struct V_26 * V_27 ;
struct V_24 * V_25 = V_49 -> V_25 ;
int V_50 = 0 ;
unsigned int V_51 ;
bool V_45 ;
F_18 (tfr, &mesg->transfers, transfer_list) {
V_50 = F_10 ( V_25 , V_27 ) ;
if ( V_50 )
goto V_52;
V_51 = F_19 ( & V_2 -> V_22 ,
F_20 ( V_53 ) ) ;
if ( ! V_51 ) {
V_50 = - V_54 ;
goto V_52;
}
V_45 = V_27 -> V_45 ||
F_21 ( & V_27 -> V_55 , & V_49 -> V_56 ) ;
V_50 = F_15 ( V_25 , V_27 , V_45 ) ;
if ( V_50 )
goto V_52;
V_49 -> V_57 += ( V_27 -> V_6 - V_2 -> V_6 ) ;
}
V_52:
F_3 ( V_2 , V_16 ,
V_58 | V_59 ) ;
V_49 -> V_60 = V_50 ;
F_22 ( V_14 ) ;
return 0 ;
}
static int F_23 ( struct V_61 * V_62 )
{
struct V_13 * V_14 ;
struct V_1 * V_2 ;
struct V_63 * V_64 ;
int V_50 ;
V_14 = F_24 ( & V_62 -> V_65 , sizeof( * V_2 ) ) ;
if ( ! V_14 ) {
F_25 ( & V_62 -> V_65 , L_1 ) ;
return - V_66 ;
}
F_26 ( V_62 , V_14 ) ;
V_14 -> V_67 = V_68 ;
V_14 -> V_69 = F_27 ( 8 ) ;
V_14 -> V_70 = - 1 ;
V_14 -> V_71 = 3 ;
V_14 -> V_72 = F_17 ;
V_14 -> V_65 . V_73 = V_62 -> V_65 . V_73 ;
V_2 = F_8 ( V_14 ) ;
F_28 ( & V_2 -> V_22 ) ;
V_64 = F_29 ( V_62 , V_74 , 0 ) ;
V_2 -> V_4 = F_30 ( & V_62 -> V_65 , V_64 ) ;
if ( F_31 ( V_2 -> V_4 ) ) {
V_50 = F_32 ( V_2 -> V_4 ) ;
goto V_75;
}
V_2 -> V_33 = F_33 ( & V_62 -> V_65 , NULL ) ;
if ( F_31 ( V_2 -> V_33 ) ) {
V_50 = F_32 ( V_2 -> V_33 ) ;
F_25 ( & V_62 -> V_65 , L_2 , V_50 ) ;
goto V_75;
}
V_2 -> V_11 = F_34 ( V_62 -> V_65 . V_73 , 0 ) ;
if ( V_2 -> V_11 <= 0 ) {
F_25 ( & V_62 -> V_65 , L_3 , V_2 -> V_11 ) ;
V_50 = V_2 -> V_11 ? V_2 -> V_11 : - V_76 ;
goto V_75;
}
F_35 ( V_2 -> V_33 ) ;
V_50 = F_36 ( V_2 -> V_11 , F_7 , 0 ,
F_37 ( & V_62 -> V_65 ) , V_14 ) ;
if ( V_50 ) {
F_25 ( & V_62 -> V_65 , L_4 , V_50 ) ;
goto V_77;
}
F_3 ( V_2 , V_16 ,
V_58 | V_59 ) ;
V_50 = F_38 ( V_14 ) ;
if ( V_50 ) {
F_25 ( & V_62 -> V_65 , L_5 , V_50 ) ;
goto V_78;
}
return 0 ;
V_78:
F_39 ( V_2 -> V_11 , V_14 ) ;
V_77:
F_40 ( V_2 -> V_33 ) ;
V_75:
F_41 ( V_14 ) ;
return V_50 ;
}
static int F_42 ( struct V_61 * V_62 )
{
struct V_13 * V_14 = F_43 ( F_44 ( V_62 ) ) ;
struct V_1 * V_2 = F_8 ( V_14 ) ;
F_39 ( V_2 -> V_11 , V_14 ) ;
F_45 ( V_14 ) ;
F_3 ( V_2 , V_16 ,
V_58 | V_59 ) ;
F_40 ( V_2 -> V_33 ) ;
F_41 ( V_14 ) ;
return 0 ;
}
