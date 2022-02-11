static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
struct V_5 * V_6 = V_4 -> V_7 ;
T_2 V_8 , V_9 ;
V_8 = F_2 ( V_6 -> V_10 + V_11 ) ;
if ( V_8 & V_12 ) {
V_9 = F_2 ( V_6 -> V_13 + V_14 ) ;
F_3 ( V_15 , V_4 , 1 ,
V_9 >> V_16 ,
V_9 & ~ V_17 , 0 ,
0 , 0 , - 1 ,
V_4 -> V_18 , L_1 ) ;
}
if ( V_8 & V_19 ) {
T_2 V_20 = F_2 ( V_6 -> V_13 + V_21 ) ;
V_20 = ( V_20 >> 8 ) & 0xff ;
V_9 = F_2 ( V_6 -> V_13 + V_22 ) ;
F_3 ( V_23 , V_4 , 1 ,
V_9 >> V_16 ,
V_9 & ~ V_17 , V_20 ,
0 , 0 , - 1 ,
V_4 -> V_18 , L_1 ) ;
}
F_4 ( V_8 , V_6 -> V_10 + V_24 ) ;
return V_25 ;
}
static void F_5 ( struct V_3 * V_4 , T_3 V_26 )
{
struct V_5 * V_27 = V_4 -> V_7 ;
T_2 V_28 ;
V_28 = F_2 ( V_27 -> V_13 + V_29 ) ;
V_28 &= V_30 ;
V_28 |= ( V_26 << V_31 ) | V_32 ;
F_4 ( V_28 , V_27 -> V_13 + V_29 ) ;
}
static T_4 F_6 ( struct V_33 * V_34 ,
struct V_35 * V_36 , const char * V_37 , T_5 V_38 )
{
struct V_3 * V_4 = F_7 ( V_34 ) ;
T_3 V_26 ;
if ( F_8 ( V_37 , 16 , & V_26 ) )
return - V_39 ;
F_5 ( V_4 , V_26 ) ;
return V_38 ;
}
static int F_9 ( struct V_40 * V_41 )
{
const struct V_42 * V_43 ;
const struct V_44 * V_45 ;
struct V_46 V_47 [ 2 ] ;
struct V_3 * V_4 ;
struct V_5 * V_6 ;
struct V_48 * V_49 ;
struct V_50 * V_51 ;
void T_6 * V_52 ;
T_2 V_53 ;
int V_1 ;
int V_54 = 0 ;
V_43 = F_10 ( V_55 , & V_41 -> V_34 ) ;
if ( ! V_43 )
return - V_56 ;
V_47 [ 0 ] . type = V_57 ;
V_47 [ 0 ] . V_58 = 1 ;
V_47 [ 0 ] . V_59 = true ;
V_47 [ 1 ] . type = V_60 ;
V_47 [ 1 ] . V_58 = 1 ;
V_47 [ 1 ] . V_59 = false ;
V_4 = F_11 ( 0 , F_12 ( V_47 ) , V_47 ,
sizeof( struct V_5 ) ) ;
if ( ! V_4 )
return - V_61 ;
V_4 -> V_41 = & V_41 -> V_34 ;
V_6 = V_4 -> V_7 ;
F_13 ( V_41 , V_4 ) ;
if ( ! F_14 ( & V_41 -> V_34 , NULL , V_62 ) )
return - V_61 ;
V_51 = F_15 ( V_41 , V_63 , 0 ) ;
if ( ! V_51 ) {
F_16 ( & V_41 -> V_34 , L_2 ) ;
V_54 = - V_56 ;
goto V_64;
}
if ( ! F_17 ( & V_41 -> V_34 , V_51 -> V_65 ,
F_18 ( V_51 ) , F_19 ( & V_41 -> V_34 ) ) ) {
F_16 ( & V_41 -> V_34 , L_3 ) ;
V_54 = - V_66 ;
goto V_64;
}
V_52 = F_20 ( & V_41 -> V_34 , V_51 -> V_65 , F_18 ( V_51 ) ) ;
if ( ! V_52 ) {
F_16 ( & V_41 -> V_34 , L_4 ) ;
V_54 = - V_61 ;
goto V_64;
}
V_45 = V_43 -> V_67 ;
V_6 -> V_13 = V_52 + V_45 -> V_68 ;
V_6 -> V_10 = V_52 + V_45 -> V_69 ;
V_53 = F_2 ( V_6 -> V_13 + V_29 ) & 0x3 ;
if ( ! V_53 || ( V_53 == 0x2 ) ) {
F_16 ( & V_41 -> V_34 , L_5 ) ;
V_54 = - V_56 ;
goto V_64;
}
V_4 -> V_70 = V_71 ;
V_4 -> V_72 = V_73 | V_74 ;
V_4 -> V_75 = V_74 ;
V_4 -> V_76 = V_41 -> V_34 . V_77 -> V_78 ;
V_4 -> V_18 = V_43 -> V_79 ;
V_4 -> F_19 = F_19 ( & V_41 -> V_34 ) ;
V_4 -> V_80 = V_81 ;
V_49 = * V_4 -> V_82 ;
V_49 -> V_83 = ( ~ 0UL >> V_16 ) + 1 ;
V_49 -> V_84 = 8 ;
V_49 -> V_85 = V_86 ;
V_49 -> V_87 = V_88 ;
V_49 -> V_89 = V_90 ;
V_54 = F_21 ( V_4 , V_91 ) ;
if ( V_54 < 0 )
goto V_64;
V_1 = F_22 ( V_41 , 0 ) ;
V_54 = F_23 ( & V_41 -> V_34 , V_1 , F_1 ,
0 , F_19 ( & V_41 -> V_34 ) , V_4 ) ;
if ( V_54 < 0 ) {
F_16 ( & V_41 -> V_34 , L_6 , V_1 ) ;
goto V_92;
}
F_24 ( & V_41 -> V_34 , NULL ) ;
return 0 ;
V_92:
F_25 ( & V_41 -> V_34 ) ;
V_64:
F_26 ( & V_41 -> V_34 , NULL ) ;
F_27 ( V_4 ) ;
return V_54 ;
}
static int F_28 ( struct V_40 * V_41 )
{
struct V_3 * V_4 = F_29 ( V_41 ) ;
F_25 ( & V_41 -> V_34 ) ;
F_27 ( V_4 ) ;
return 0 ;
}
