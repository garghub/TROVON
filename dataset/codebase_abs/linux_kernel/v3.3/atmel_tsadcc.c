static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
struct V_5 * V_5 = V_4 -> V_6 ;
unsigned int V_7 ;
unsigned int V_8 ;
V_7 = F_2 ( V_9 ) ;
V_7 &= F_2 ( V_10 ) ;
if ( V_7 & V_11 ) {
V_8 = F_2 ( V_12 ) | V_13 ;
F_3 ( V_12 , V_8 ) ;
F_3 ( V_14 , V_15 ) ;
F_3 ( V_16 ,
F_4 ( 3 ) | V_11 ) ;
F_3 ( V_17 , V_18 ) ;
F_5 ( V_5 , V_19 , 0 ) ;
V_4 -> V_20 = 0 ;
F_6 ( V_5 ) ;
} else if ( V_7 & V_18 ) {
V_8 = F_2 ( V_12 ) ;
V_8 &= ~ V_13 ;
F_3 ( V_16 , V_18 ) ;
F_3 ( V_12 , V_8 ) ;
F_3 ( V_17 ,
F_4 ( 3 ) | V_11 ) ;
F_3 ( V_14 ,
V_21 | ( 0x0FFF << 16 ) ) ;
} else if ( V_7 & F_4 ( 3 ) ) {
if ( V_4 -> V_20 ) {
F_7 ( V_5 , V_22 , V_4 -> V_23 ) ;
F_7 ( V_5 , V_24 , V_4 -> V_25 ) ;
F_5 ( V_5 , V_19 , 1 ) ;
F_6 ( V_5 ) ;
} else
V_4 -> V_20 = 1 ;
V_4 -> V_23 = F_2 ( V_26 ) << 10 ;
V_4 -> V_23 /= F_2 ( V_27 ) ;
V_4 -> V_25 = F_2 ( V_28 ) << 10 ;
V_4 -> V_25 /= F_2 ( V_29 ) ;
}
return V_30 ;
}
static int T_2 F_8 ( struct V_31 * V_32 )
{
struct V_3 * V_4 ;
struct V_5 * V_5 ;
struct V_33 * V_34 ;
struct V_35 * V_36 = V_32 -> V_2 . V_37 ;
int V_38 = 0 ;
unsigned int V_39 ;
unsigned int V_8 ;
V_34 = F_9 ( V_32 , V_40 , 0 ) ;
if ( ! V_34 ) {
F_10 ( & V_32 -> V_2 , L_1 ) ;
return - V_41 ;
}
V_4 = F_11 ( sizeof( struct V_3 ) , V_42 ) ;
if ( ! V_4 ) {
F_10 ( & V_32 -> V_2 , L_2 ) ;
return - V_43 ;
}
F_12 ( V_32 , V_4 ) ;
V_5 = F_13 () ;
if ( ! V_5 ) {
F_10 ( & V_32 -> V_2 , L_3 ) ;
V_38 = - V_44 ;
goto V_45;
}
V_4 -> V_1 = F_14 ( V_32 , 0 ) ;
if ( V_4 -> V_1 < 0 ) {
F_10 ( & V_32 -> V_2 , L_4 ) ;
V_38 = - V_46 ;
goto V_47;
}
if ( ! F_15 ( V_34 -> V_48 , F_16 ( V_34 ) ,
L_5 ) ) {
F_10 ( & V_32 -> V_2 , L_6 ) ;
V_38 = - V_44 ;
goto V_47;
}
V_49 = F_17 ( V_34 -> V_48 , F_16 ( V_34 ) ) ;
if ( ! V_49 ) {
F_10 ( & V_32 -> V_2 , L_7 ) ;
V_38 = - V_43 ;
goto V_50;
}
V_38 = F_18 ( V_4 -> V_1 , F_1 , 0 ,
V_32 -> V_2 . V_51 -> V_52 , V_4 ) ;
if ( V_38 ) {
F_10 ( & V_32 -> V_2 , L_8 ) ;
goto V_53;
}
V_4 -> V_54 = F_19 ( & V_32 -> V_2 , L_9 ) ;
if ( F_20 ( V_4 -> V_54 ) ) {
F_10 ( & V_32 -> V_2 , L_10 ) ;
V_38 = F_21 ( V_4 -> V_54 ) ;
goto V_55;
}
V_4 -> V_6 = V_5 ;
V_4 -> V_20 = 0 ;
snprintf ( V_4 -> V_56 , sizeof( V_4 -> V_56 ) ,
L_11 , F_22 ( & V_32 -> V_2 ) ) ;
V_5 -> V_52 = L_12 ;
V_5 -> V_56 = V_4 -> V_56 ;
V_5 -> V_2 . V_57 = & V_32 -> V_2 ;
F_23 ( V_58 , V_5 -> V_59 ) ;
F_24 ( V_5 , V_22 , 0 , 0x3FF , 0 , 0 ) ;
F_24 ( V_5 , V_24 , 0 , 0x3FF , 0 , 0 ) ;
F_25 ( V_5 , V_60 , V_19 ) ;
F_26 ( V_4 -> V_54 ) ;
V_39 = F_27 ( V_4 -> V_54 ) ;
F_28 ( & V_32 -> V_2 , L_13 , V_39 ) ;
if ( ! V_36 )
goto V_61;
if ( ! V_36 -> V_62 )
V_36 -> V_62 = V_63 ;
V_39 = ( V_39 / ( 2 * V_36 -> V_62 ) ) - 1 ;
if ( F_29 () ) {
if ( V_39 > F_30 ( V_64 ) )
V_39 = F_30 ( V_64 ) ;
} else {
if ( V_39 > F_30 ( V_65 ) )
V_39 = F_30 ( V_65 ) ;
}
F_28 ( & V_32 -> V_2 , L_14 , V_39 ) ;
V_8 = V_66 |
( ( 0x00 << 5 ) & V_67 ) |
( ( 0x01 << 6 ) & V_68 ) |
( V_39 << 8 ) |
( ( 0x26 << 16 ) & V_69 ) |
( ( V_36 -> V_70 << 28 ) & V_13 ) ;
F_3 ( V_71 , V_72 ) ;
F_3 ( V_12 , V_8 ) ;
F_3 ( V_14 , V_15 ) ;
F_3 ( V_73 ,
( V_36 -> V_74 << 24 ) & V_75 ) ;
F_2 ( V_9 ) ;
F_3 ( V_17 , V_18 ) ;
V_38 = F_31 ( V_5 ) ;
if ( V_38 )
goto V_61;
return 0 ;
V_61:
F_32 ( V_4 -> V_54 ) ;
F_33 ( V_4 -> V_54 ) ;
V_55:
F_34 ( V_4 -> V_1 , V_4 ) ;
V_53:
F_35 ( V_49 ) ;
V_50:
F_36 ( V_34 -> V_48 , F_16 ( V_34 ) ) ;
V_47:
F_37 ( V_5 ) ;
V_45:
F_38 ( V_4 ) ;
return V_38 ;
}
static int T_3 F_39 ( struct V_31 * V_32 )
{
struct V_3 * V_4 = F_40 ( & V_32 -> V_2 ) ;
struct V_33 * V_34 ;
F_34 ( V_4 -> V_1 , V_4 ) ;
F_41 ( V_4 -> V_6 ) ;
V_34 = F_9 ( V_32 , V_40 , 0 ) ;
F_35 ( V_49 ) ;
F_36 ( V_34 -> V_48 , F_16 ( V_34 ) ) ;
F_32 ( V_4 -> V_54 ) ;
F_33 ( V_4 -> V_54 ) ;
F_38 ( V_4 ) ;
return 0 ;
}
