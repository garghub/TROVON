static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
struct V_5 * V_6 = V_4 -> V_7 ;
T_2 V_8 , V_9 ;
V_8 = F_2 ( V_6 -> V_10 + V_11 ) ;
if ( V_8 & V_12 ) {
V_9 = F_2 ( V_6 -> V_10 + V_13 ) ;
F_3 ( V_14 , V_4 , 1 ,
V_9 >> V_15 ,
V_9 & ~ V_16 , 0 ,
0 , 0 , - 1 ,
V_4 -> V_17 , L_1 ) ;
}
if ( V_8 & V_18 ) {
T_2 V_19 = F_2 ( V_6 -> V_10 + V_20 ) ;
V_19 = ( V_19 >> 8 ) & 0xff ;
V_9 = F_2 ( V_6 -> V_10 + V_21 ) ;
F_3 ( V_22 , V_4 , 1 ,
V_9 >> V_15 ,
V_9 & ~ V_16 , V_19 ,
0 , 0 , - 1 ,
V_4 -> V_17 , L_1 ) ;
}
F_4 ( V_8 , V_6 -> V_10 + V_23 ) ;
return V_24 ;
}
static T_3 F_5 ( struct V_25 * V_25 ,
const char T_4 * V_26 ,
T_5 V_27 , T_6 * V_28 )
{
struct V_3 * V_4 = V_25 -> V_29 ;
struct V_5 * V_30 = V_4 -> V_7 ;
char V_31 [ 32 ] ;
T_5 V_32 ;
T_2 V_33 ;
T_7 V_34 ;
V_32 = F_6 ( V_27 , ( sizeof( V_31 ) - 1 ) ) ;
if ( F_7 ( V_31 , V_26 , V_32 ) )
return - V_35 ;
V_31 [ V_32 ] = 0 ;
if ( ! F_8 ( V_31 , 16 , & V_34 ) ) {
V_33 = F_2 ( V_30 -> V_10 + V_36 ) ;
V_33 &= V_37 ;
V_33 |= ( V_34 << V_38 ) | V_39 ;
F_4 ( V_33 , V_30 -> V_10 + V_36 ) ;
}
return V_27 ;
}
static int F_9 ( struct V_40 * V_40 , struct V_25 * V_25 )
{
V_25 -> V_29 = V_40 -> V_41 ;
return 0 ;
}
static void T_8 F_10 ( struct V_3 * V_4 )
{
if ( V_4 -> V_42 )
F_11 ( L_2 , V_43 , V_4 -> V_42 , V_4 ,
& V_44 ) ;
;
}
static void T_8 F_10 ( struct V_3 * V_4 )
{}
static int T_8 F_12 ( struct V_45 * V_46 )
{
struct V_47 V_48 [ 2 ] ;
struct V_3 * V_4 ;
struct V_5 * V_6 ;
struct V_49 * V_50 ;
struct V_51 * V_52 ;
T_2 V_53 ;
int V_1 ;
int V_54 = 0 ;
V_48 [ 0 ] . type = V_55 ;
V_48 [ 0 ] . V_56 = 1 ;
V_48 [ 0 ] . V_57 = true ;
V_48 [ 1 ] . type = V_58 ;
V_48 [ 1 ] . V_56 = 1 ;
V_48 [ 1 ] . V_57 = false ;
V_4 = F_13 ( 0 , F_14 ( V_48 ) , V_48 ,
sizeof( struct V_5 ) ) ;
if ( ! V_4 )
return - V_59 ;
V_4 -> V_46 = & V_46 -> V_60 ;
V_6 = V_4 -> V_7 ;
F_15 ( V_46 , V_4 ) ;
if ( ! F_16 ( & V_46 -> V_60 , NULL , V_61 ) )
return - V_59 ;
V_52 = F_17 ( V_46 , V_62 , 0 ) ;
if ( ! V_52 ) {
F_18 ( & V_46 -> V_60 , L_3 ) ;
V_54 = - V_63 ;
goto V_64;
}
if ( ! F_19 ( & V_46 -> V_60 , V_52 -> V_65 ,
F_20 ( V_52 ) , F_21 ( & V_46 -> V_60 ) ) ) {
F_18 ( & V_46 -> V_60 , L_4 ) ;
V_54 = - V_66 ;
goto V_64;
}
V_6 -> V_10 = F_22 ( & V_46 -> V_60 ,
V_52 -> V_65 , F_20 ( V_52 ) ) ;
if ( ! V_6 -> V_10 ) {
F_18 ( & V_46 -> V_60 , L_5 ) ;
V_54 = - V_59 ;
goto V_64;
}
V_53 = F_2 ( V_6 -> V_10 + V_36 ) & 0x3 ;
if ( ! V_53 || ( V_53 == 0x2 ) ) {
F_18 ( & V_46 -> V_60 , L_6 ) ;
V_54 = - V_63 ;
goto V_64;
}
V_1 = F_23 ( V_46 , 0 ) ;
V_54 = F_24 ( & V_46 -> V_60 , V_1 , F_1 ,
0 , F_21 ( & V_46 -> V_60 ) , V_4 ) ;
if ( V_54 < 0 ) {
F_18 ( & V_46 -> V_60 , L_7 , V_1 ) ;
goto V_64;
}
V_4 -> V_67 = V_68 ;
V_4 -> V_69 = V_70 | V_71 ;
V_4 -> V_72 = V_71 ;
V_4 -> V_73 = F_21 ( & V_46 -> V_60 ) ;
V_4 -> V_74 = L_8 ;
V_4 -> V_17 = F_21 ( & V_46 -> V_60 ) ;
V_4 -> V_75 = V_76 ;
V_50 = * V_4 -> V_77 ;
V_50 -> V_78 = ( ~ 0UL >> V_15 ) + 1 ;
V_50 -> V_79 = 8 ;
V_50 -> V_80 = V_81 ;
V_50 -> V_82 = V_83 ;
V_50 -> V_84 = V_85 ;
V_54 = F_25 ( V_4 ) ;
if ( V_54 < 0 )
goto V_64;
F_10 ( V_4 ) ;
F_26 ( & V_46 -> V_60 , NULL ) ;
return 0 ;
V_64:
F_27 ( & V_46 -> V_60 , NULL ) ;
F_28 ( V_4 ) ;
return V_54 ;
}
static int F_29 ( struct V_45 * V_46 )
{
struct V_3 * V_4 = F_30 ( V_46 ) ;
F_31 ( & V_46 -> V_60 ) ;
F_28 ( V_4 ) ;
return 0 ;
}
