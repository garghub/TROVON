static inline void F_1 ( T_1 V_1 , T_2 V_2 )
{
F_2 ( V_2 , V_3 -> V_4 + V_1 ) ;
}
static inline int F_3 ( T_1 V_1 )
{
return F_4 ( V_3 -> V_4 + V_1 ) ;
}
static void F_5 ( void )
{
F_6 ( V_3 -> V_5 , L_1 ) ;
F_6 ( V_3 -> V_5 , L_2 ,
F_3 ( V_6 ) ) ;
F_6 ( V_3 -> V_5 , L_3 ,
F_3 ( V_7 ) ) ;
F_6 ( V_3 -> V_5 , L_4 ,
F_3 ( V_8 ) ) ;
F_6 ( V_3 -> V_5 , L_5 ,
F_3 ( V_9 ) ) ;
F_6 ( V_3 -> V_5 , L_6 ,
F_3 ( V_10 ) ) ;
F_6 ( V_3 -> V_5 , L_7 ,
F_3 ( V_11 ) ) ;
F_6 ( V_3 -> V_5 , L_8 ,
F_3 ( V_12 ) ) ;
F_6 ( V_3 -> V_5 , L_9 ,
F_3 ( V_13 ) ) ;
F_6 ( V_3 -> V_5 , L_10 ,
F_3 ( V_14 ) ) ;
F_6 ( V_3 -> V_5 , L_11 ,
F_3 ( V_15 ) ) ;
F_6 ( V_3 -> V_5 , L_12 ,
F_3 ( V_16 ) ) ;
F_6 ( V_3 -> V_5 , L_13 ,
F_3 ( V_17 ) ) ;
F_6 ( V_3 -> V_5 , L_14 ,
F_3 ( V_18 ) ) ;
F_6 ( V_3 -> V_5 , L_15 ,
F_3 ( V_19 ) ) ;
F_6 ( V_3 -> V_5 , L_1 ) ;
}
static void F_7 ( int V_20 )
{
int V_21 = F_3 ( V_14 ) ;
if ( V_20 )
V_21 |= V_22 ;
else
V_21 &= ~ V_22 ;
F_1 ( V_14 , V_21 ) ;
}
static void F_8 ( int V_20 )
{
int V_21 = F_3 ( V_14 ) ;
if ( V_20 )
V_21 |= V_23 ;
else
V_21 &= ~ V_23 ;
F_1 ( V_14 , V_21 ) ;
}
void F_9 ( int V_24 )
{
int V_21 = F_3 ( V_14 ) ;
if ( V_24 )
V_21 |= V_3 -> V_25 ;
else
V_21 |= V_3 -> V_26 ;
F_1 ( V_14 , V_21 ) ;
}
void F_10 ( int V_24 )
{
int V_21 = F_3 ( V_14 ) ;
if ( V_24 )
V_21 &= ~ V_3 -> V_25 ;
else
V_21 &= ~ V_3 -> V_26 ;
F_1 ( V_14 , V_21 ) ;
}
int F_11 ( struct V_27 * V_28 )
{
int V_29 = 0 ;
int V_21 ;
if ( ! V_28 )
return - V_30 ;
V_3 -> V_28 = V_28 ;
V_29 |= V_28 -> V_29 & V_31 ;
F_1 ( V_8 , V_29 ) ;
if ( V_28 -> V_32 > V_33 )
V_28 -> V_32 = V_33 ;
F_1 ( V_18 , V_28 -> V_32 ) ;
F_1 ( V_11 , V_34 ) ;
V_21 = F_3 ( V_14 ) ;
V_21 &= ~ V_35 ;
V_21 |= V_28 -> V_36 & V_35 ;
V_3 -> V_25 = V_28 -> V_37 & ( V_38 | V_39 ) ;
F_1 ( V_14 , V_21 ) ;
return 0 ;
}
int F_12 ( struct V_27 * V_40 )
{
int V_29 = 0 ;
int V_21 ;
if ( ! V_40 )
return - V_30 ;
V_3 -> V_40 = V_40 ;
V_29 |= V_40 -> V_29 & V_41 ;
F_1 ( V_8 , V_29 ) ;
if ( V_40 -> V_32 > V_42 )
V_40 -> V_32 = V_42 ;
F_1 ( V_17 , V_40 -> V_32 ) ;
F_1 ( V_11 , V_43 ) ;
V_21 = F_3 ( V_14 ) ;
V_21 &= ~ V_35 ;
V_21 |= V_40 -> V_36 & V_35 ;
V_3 -> V_26 = V_40 -> V_37 & ( V_44 | V_45 ) ;
F_1 ( V_14 , V_21 ) ;
return 0 ;
}
int F_13 ( struct V_27 * V_28 )
{
int V_29 = 0 ;
if ( ! V_28 )
return - V_30 ;
V_29 |= V_28 -> V_29 & V_31 ;
F_1 ( V_9 , V_29 ) ;
F_1 ( V_12 , V_34 ) ;
V_3 -> V_25 = 0 ;
V_3 -> V_28 = NULL ;
return 0 ;
}
int F_14 ( struct V_27 * V_40 )
{
int V_29 = 0 ;
if ( ! V_40 )
return - V_30 ;
V_29 |= V_40 -> V_29 & V_41 ;
F_1 ( V_9 , V_29 ) ;
F_1 ( V_12 , V_43 ) ;
V_3 -> V_26 = 0 ;
V_3 -> V_40 = NULL ;
return 0 ;
}
static T_3 F_15 ( int V_46 , void * V_47 )
{
struct V_48 * V_49 = V_47 ;
int V_50 ;
V_50 = F_3 ( V_7 ) ;
F_1 ( V_7 , V_50 ) ;
if ( V_46 & V_51 ) {
F_16 ( V_49 -> V_5 , L_16 , V_50 ) ;
F_8 ( 1 ) ;
F_12 ( V_49 -> V_40 ) ;
F_8 ( 0 ) ;
}
if ( V_46 & V_52 ) {
F_16 ( V_49 -> V_5 , L_16 , V_50 ) ;
F_8 ( 1 ) ;
F_12 ( V_49 -> V_40 ) ;
F_8 ( 0 ) ;
}
if ( V_46 & V_53 ) {
F_6 ( V_49 -> V_5 , L_17 ) ;
}
if ( V_46 & V_54 ) {
F_16 ( V_49 -> V_5 , L_18 , V_50 ) ;
F_7 ( 1 ) ;
F_11 ( V_49 -> V_28 ) ;
F_7 ( 0 ) ;
}
if ( V_46 & V_55 ) {
F_16 ( V_49 -> V_5 , L_18 , V_50 ) ;
F_7 ( 1 ) ;
F_11 ( V_49 -> V_28 ) ;
F_7 ( 0 ) ;
}
if ( V_46 & V_56 ) {
F_6 ( V_49 -> V_5 , L_19 ) ;
}
return V_57 ;
}
int F_17 ( void )
{
int V_58 ;
F_18 ( V_3 -> V_59 ) ;
F_19 ( & V_3 -> V_60 ) ;
if ( ! V_3 -> free ) {
F_16 ( V_3 -> V_5 , L_20 ) ;
F_20 ( & V_3 -> V_60 ) ;
V_58 = - V_61 ;
goto V_62;
}
V_3 -> free = 0 ;
F_20 ( & V_3 -> V_60 ) ;
F_1 ( V_14 , 0x00 ) ;
V_58 = F_21 ( V_3 -> V_46 , F_15 ,
0 , L_21 , ( void * ) V_3 ) ;
if ( V_58 ) {
F_16 ( V_3 -> V_5 , L_22 ) ;
goto V_62;
}
return 0 ;
V_62:
F_22 ( V_3 -> V_59 ) ;
return V_58 ;
}
void F_23 ( void )
{
F_19 ( & V_3 -> V_60 ) ;
if ( V_3 -> free ) {
F_16 ( V_3 -> V_5 , L_23 ) ;
F_20 ( & V_3 -> V_60 ) ;
return;
}
V_3 -> free = 1 ;
F_20 ( & V_3 -> V_60 ) ;
F_22 ( V_3 -> V_59 ) ;
F_24 ( V_3 -> V_46 , ( void * ) V_3 ) ;
}
int F_25 ( int V_63 , int V_64 )
{
int V_65 ;
if ( ( V_63 > V_66 ) || ( V_64 > V_66 ) )
return - V_30 ;
V_65 = ( V_63 << V_67 ) | ( V_64 << V_68 ) ;
if ( V_63 )
V_65 |= V_69 ;
else
V_65 &= ~ V_69 ;
if ( V_64 )
V_65 |= V_70 ;
else
V_65 &= ~ V_70 ;
F_1 ( V_19 , V_65 ) ;
return 0 ;
}
int T_4 F_26 ( struct V_71 * V_72 )
{
struct V_73 * V_74 ;
int V_58 = 0 ;
V_3 = F_27 ( sizeof( struct V_48 ) , V_75 ) ;
if ( ! V_3 ) {
V_58 = - V_76 ;
goto exit;
}
V_74 = F_28 ( V_72 , V_77 , 0 ) ;
if ( V_74 == NULL ) {
F_16 ( & V_72 -> V_5 , L_24 ) ;
goto V_78;
}
F_29 ( & V_3 -> V_60 ) ;
V_3 -> free = 1 ;
V_3 -> V_4 = F_30 ( V_74 -> V_79 , F_31 ( V_74 ) ) ;
if ( ! V_3 -> V_4 ) {
V_58 = - V_76 ;
goto V_78;
}
V_3 -> V_46 = F_32 ( V_72 , 0 ) ;
V_3 -> V_59 = F_33 ( & V_72 -> V_5 , L_25 ) ;
if ( F_34 ( V_3 -> V_59 ) ) {
V_58 = F_35 ( V_3 -> V_59 ) ;
F_16 ( & V_72 -> V_5 , L_26 , V_58 ) ;
goto V_80;
}
V_3 -> V_5 = & V_72 -> V_5 ;
F_36 ( V_72 , V_3 ) ;
return 0 ;
V_80:
F_37 ( V_3 -> V_4 ) ;
V_78:
F_38 ( V_3 ) ;
exit:
return V_58 ;
}
int F_39 ( struct V_71 * V_72 )
{
struct V_48 * V_81 = F_40 ( V_72 ) ;
F_36 ( V_72 , NULL ) ;
F_41 ( V_81 -> V_59 ) ;
F_37 ( V_81 -> V_4 ) ;
V_81 -> V_59 = NULL ;
V_81 -> free = 0 ;
V_81 -> V_5 = NULL ;
F_38 ( V_81 ) ;
return 0 ;
}
