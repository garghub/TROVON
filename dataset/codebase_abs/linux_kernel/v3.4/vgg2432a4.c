static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
unsigned int V_5 ;
int V_6 ;
V_6 = F_2 ( V_2 , 0x00e5 , 0x8000 ) ;
if ( V_6 )
goto V_7;
V_6 = F_2 ( V_2 , V_8 , V_9 ) ;
if ( V_6 )
goto V_7;
F_3 ( 15 ) ;
V_6 = F_4 ( V_2 , V_10 , F_5 ( V_10 ) ) ;
if ( V_6 != 0 )
goto V_7;
F_2 ( V_2 , V_11 , V_4 -> V_12 ) ;
F_2 ( V_2 , V_13 , V_4 -> V_14 ) ;
F_2 ( V_2 , V_15 , V_4 -> V_16 ) ;
F_2 ( V_2 , V_17 , V_4 -> V_18 ) ;
F_2 ( V_2 , V_19 , 0x0 ) ;
F_2 ( V_2 , V_20 , V_4 -> V_21 ) ;
V_6 = F_4 ( V_2 , V_22 , F_5 ( V_22 ) ) ;
if ( V_6 != 0 )
goto V_23;
F_3 ( 300 ) ;
V_6 = F_4 ( V_2 , V_24 , F_5 ( V_24 ) ) ;
if ( V_6 != 0 )
goto V_25;
F_3 ( 100 ) ;
F_2 ( V_2 , V_26 , 0x13c ) ;
F_3 ( 100 ) ;
F_2 ( V_2 , V_27 , 0x1c00 ) ;
F_2 ( V_2 , V_28 , 0x000e ) ;
F_3 ( 100 ) ;
F_2 ( V_2 , V_29 , 0x00 ) ;
F_2 ( V_2 , V_30 , 0x00 ) ;
V_6 = F_4 ( V_2 , V_31 , F_5 ( V_31 ) ) ;
if ( V_6 != 0 )
goto V_32;
F_2 ( V_2 , V_33 , 0x0 ) ;
F_2 ( V_2 , V_34 , V_4 -> V_35 - 1 ) ;
F_2 ( V_2 , V_36 , 0x0 ) ;
F_2 ( V_2 , V_37 , V_4 -> V_38 - 1 ) ;
F_2 ( V_2 , V_39 ,
F_6 ( ( ( V_4 -> V_38 - 240 ) / 8 ) + 0x1D ) ) ;
F_2 ( V_2 , V_40 , 0x1 ) ;
F_2 ( V_2 , V_41 , 0x00 ) ;
for ( V_5 = V_42 ; V_5 <= V_43 ;
V_5 ++ ) {
F_2 ( V_2 , V_5 , 0x0 ) ;
}
F_2 ( V_2 , V_44 , 0x10 ) ;
F_2 ( V_2 , V_45 , V_4 -> V_46 ) ;
F_2 ( V_2 , V_47 , V_4 -> V_48 ) ;
F_2 ( V_2 , V_49 , V_4 -> V_50 ) ;
F_2 ( V_2 , V_51 , V_4 -> V_52 ) ;
F_2 ( V_2 , V_53 , V_4 -> V_54 ) ;
V_2 -> V_55 = ( F_7 ( 3 ) | V_56 |
V_57 | V_58 |
0x40 ) ;
F_2 ( V_2 , V_59 , V_2 -> V_55 ) ;
return 0 ;
V_32:
V_25:
V_23:
V_7:
return V_6 ;
}
static int F_8 ( struct V_60 * V_61 , T_1 V_62 )
{
return F_9 ( F_10 ( & V_61 -> V_63 ) , V_62 ) ;
}
static int F_11 ( struct V_60 * V_61 )
{
return F_12 ( F_10 ( & V_61 -> V_63 ) ) ;
}
static int T_2 F_13 ( struct V_60 * V_61 )
{
int V_6 ;
V_6 = F_14 ( V_61 , & V_64 ) ;
if ( V_6 != 0 ) {
F_15 ( & V_61 -> V_63 , L_1 ) ;
return V_6 ;
}
return 0 ;
}
static int T_3 F_16 ( struct V_60 * V_61 )
{
return F_17 ( F_10 ( & V_61 -> V_63 ) ) ;
}
static void F_18 ( struct V_60 * V_61 )
{
F_19 ( F_10 ( & V_61 -> V_63 ) ) ;
}
