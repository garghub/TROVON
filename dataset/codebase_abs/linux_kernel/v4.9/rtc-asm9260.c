static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
T_2 V_5 ;
unsigned long V_6 = 0 ;
F_2 ( & V_4 -> V_7 -> V_8 ) ;
V_5 = F_3 ( V_4 -> V_9 + V_10 ) ;
if ( ! V_5 ) {
F_4 ( & V_4 -> V_7 -> V_8 ) ;
return V_11 ;
}
F_5 ( 0 , V_4 -> V_9 + V_10 ) ;
F_4 ( & V_4 -> V_7 -> V_8 ) ;
V_6 |= V_12 | V_13 ;
F_6 ( V_4 -> V_7 , 1 , V_6 ) ;
return V_14 ;
}
static int F_7 ( struct V_15 * V_16 , struct V_17 * V_18 )
{
struct V_3 * V_4 = F_8 ( V_16 ) ;
T_2 V_19 , V_20 , V_21 ;
V_19 = F_3 ( V_4 -> V_9 + V_22 ) ;
V_20 = F_3 ( V_4 -> V_9 + V_23 ) ;
V_21 = F_3 ( V_4 -> V_9 + V_24 ) ;
if ( V_20 != F_3 ( V_4 -> V_9 + V_23 ) ) {
V_19 = F_3 ( V_4 -> V_9 + V_22 ) ;
V_20 = F_3 ( V_4 -> V_9 + V_23 ) ;
V_21 = F_3 ( V_4 -> V_9 + V_24 ) ;
}
V_18 -> V_25 = ( V_19 >> V_26 ) & V_27 ;
V_18 -> V_28 = ( V_19 >> V_29 ) & V_30 ;
V_18 -> V_31 = ( V_19 >> V_32 ) & V_33 ;
V_18 -> V_34 = ( V_19 >> V_35 ) & V_36 ;
V_18 -> V_37 = ( V_20 >> V_38 ) & V_39 ;
V_18 -> V_40 = ( V_20 >> V_41 ) & V_42 ;
V_18 -> V_43 = ( V_20 >> V_44 ) & V_45 ;
V_18 -> V_46 = ( V_21 >> V_47 ) & V_48 ;
return 0 ;
}
static int F_9 ( struct V_15 * V_16 , struct V_17 * V_18 )
{
struct V_3 * V_4 = F_8 ( V_16 ) ;
F_5 ( 0 , V_4 -> V_9 + V_49 ) ;
F_5 ( V_18 -> V_43 , V_4 -> V_9 + V_50 ) ;
F_5 ( V_18 -> V_40 , V_4 -> V_9 + V_51 ) ;
F_5 ( V_18 -> V_37 , V_4 -> V_9 + V_52 ) ;
F_5 ( V_18 -> V_34 , V_4 -> V_9 + V_53 ) ;
F_5 ( V_18 -> V_46 , V_4 -> V_9 + V_54 ) ;
F_5 ( V_18 -> V_31 , V_4 -> V_9 + V_55 ) ;
F_5 ( V_18 -> V_28 , V_4 -> V_9 + V_56 ) ;
F_5 ( V_18 -> V_25 , V_4 -> V_9 + V_49 ) ;
return 0 ;
}
static int F_10 ( struct V_15 * V_16 , struct V_57 * V_58 )
{
struct V_3 * V_4 = F_8 ( V_16 ) ;
V_58 -> time . V_43 = F_3 ( V_4 -> V_9 + V_59 ) ;
V_58 -> time . V_40 = F_3 ( V_4 -> V_9 + V_60 ) ;
V_58 -> time . V_37 = F_3 ( V_4 -> V_9 + V_61 ) ;
V_58 -> time . V_34 = F_3 ( V_4 -> V_9 + V_62 ) ;
V_58 -> time . V_46 = F_3 ( V_4 -> V_9 + V_63 ) ;
V_58 -> time . V_31 = F_3 ( V_4 -> V_9 + V_64 ) ;
V_58 -> time . V_28 = F_3 ( V_4 -> V_9 + V_65 ) ;
V_58 -> time . V_25 = F_3 ( V_4 -> V_9 + V_66 ) ;
V_58 -> V_67 = F_3 ( V_4 -> V_9 + V_68 ) ? 1 : 0 ;
V_58 -> V_69 = F_3 ( V_4 -> V_9 + V_10 ) ? 1 : 0 ;
return F_11 ( & V_58 -> time ) ;
}
static int F_12 ( struct V_15 * V_16 , struct V_57 * V_58 )
{
struct V_3 * V_4 = F_8 ( V_16 ) ;
F_5 ( V_58 -> time . V_43 , V_4 -> V_9 + V_59 ) ;
F_5 ( V_58 -> time . V_40 , V_4 -> V_9 + V_60 ) ;
F_5 ( V_58 -> time . V_37 , V_4 -> V_9 + V_61 ) ;
F_5 ( V_58 -> time . V_34 , V_4 -> V_9 + V_62 ) ;
F_5 ( V_58 -> time . V_46 , V_4 -> V_9 + V_63 ) ;
F_5 ( V_58 -> time . V_31 , V_4 -> V_9 + V_64 ) ;
F_5 ( V_58 -> time . V_28 , V_4 -> V_9 + V_65 ) ;
F_5 ( V_58 -> time . V_25 , V_4 -> V_9 + V_66 ) ;
F_5 ( V_58 -> V_67 ? 0 : V_70 , V_4 -> V_9 + V_68 ) ;
return 0 ;
}
static int F_13 ( struct V_15 * V_16 , unsigned int V_67 )
{
struct V_3 * V_4 = F_8 ( V_16 ) ;
F_5 ( V_67 ? 0 : V_70 , V_4 -> V_9 + V_68 ) ;
return 0 ;
}
static int F_14 ( struct V_71 * V_72 )
{
struct V_3 * V_4 ;
struct V_15 * V_16 = & V_72 -> V_16 ;
struct V_73 * V_74 ;
int V_75 , V_76 ;
T_2 V_77 ;
V_4 = F_15 ( V_16 , sizeof( struct V_3 ) , V_78 ) ;
if ( ! V_4 )
return - V_79 ;
V_4 -> V_16 = & V_72 -> V_16 ;
F_16 ( V_72 , V_4 ) ;
V_75 = F_17 ( V_72 , 0 ) ;
if ( V_75 < 0 ) {
F_18 ( V_16 , L_1 ) ;
return V_75 ;
}
V_74 = F_19 ( V_72 , V_80 , 0 ) ;
V_4 -> V_9 = F_20 ( V_16 , V_74 ) ;
if ( F_21 ( V_4 -> V_9 ) )
return F_22 ( V_4 -> V_9 ) ;
V_4 -> V_81 = F_23 ( V_16 , L_2 ) ;
V_76 = F_24 ( V_4 -> V_81 ) ;
if ( V_76 ) {
F_18 ( V_16 , L_3 ) ;
return V_76 ;
}
V_77 = F_3 ( V_4 -> V_9 + V_82 ) ;
if ( ( V_77 & ( V_83 | V_84 ) ) != V_83 ) {
F_5 ( V_84 , V_4 -> V_9 + V_82 ) ;
V_77 = 0 ;
}
F_5 ( V_83 | V_77 , V_4 -> V_9 + V_82 ) ;
F_5 ( 0 , V_4 -> V_9 + V_10 ) ;
F_5 ( V_70 , V_4 -> V_9 + V_68 ) ;
V_4 -> V_7 = F_25 ( V_16 , F_26 ( V_16 ) ,
& V_85 , V_86 ) ;
if ( F_21 ( V_4 -> V_7 ) ) {
V_76 = F_22 ( V_4 -> V_7 ) ;
F_18 ( V_16 , L_4 , V_76 ) ;
goto V_87;
}
V_76 = F_27 ( V_16 , V_75 , NULL ,
F_1 , V_88 ,
F_26 ( V_16 ) , V_4 ) ;
if ( V_76 < 0 ) {
F_18 ( V_16 , L_5 ,
V_75 , V_76 ) ;
goto V_87;
}
return 0 ;
V_87:
F_28 ( V_4 -> V_81 ) ;
return V_76 ;
}
static int F_29 ( struct V_71 * V_72 )
{
struct V_3 * V_4 = F_30 ( V_72 ) ;
F_5 ( V_70 , V_4 -> V_9 + V_68 ) ;
F_28 ( V_4 -> V_81 ) ;
return 0 ;
}
