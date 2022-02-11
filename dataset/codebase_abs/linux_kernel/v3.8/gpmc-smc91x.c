static int F_1 ( void )
{
struct V_1 V_2 ;
struct V_3 V_4 ;
const int V_5 = 10 ;
const int V_6 = 20 ;
const int V_7 = 5 ;
const int V_8 = 25 ;
const int V_9 = 15 ;
const int V_10 = 5 ;
const int V_11 = 5 ;
const int V_12 = 185 ;
T_1 V_13 ;
V_13 = V_14 ;
if ( V_15 -> V_16 & V_17 )
V_13 |= V_18 ;
if ( V_15 -> V_16 & V_19 )
V_13 |= V_20 ;
if ( V_15 -> V_16 & V_21 )
V_13 |= V_22 ;
if ( V_15 -> V_23 )
V_13 |= F_2 ( V_15 -> V_23 ) ;
F_3 ( V_15 -> V_24 , V_25 , V_13 ) ;
if ( V_15 -> V_16 & V_17 )
return 0 ;
memset ( & V_4 , 0 , sizeof( V_4 ) ) ;
V_4 . V_26 = V_5 * 1000 ;
V_4 . V_27 = V_8 * 1000 ;
V_4 . V_28 = V_6 * 1000 ;
V_4 . V_29 = V_9 * 1000 ;
V_4 . V_30 = ( V_12 - V_5 ) * 1000 ;
V_4 . V_31 = V_5 * 1000 ;
V_4 . V_32 = V_10 * 1000 ;
V_4 . V_33 = V_11 * 1000 ;
V_4 . V_34 = V_7 * 1000 ;
V_4 . V_35 = ( V_12 - V_5 ) * 1000 ;
F_4 ( & V_2 , & V_4 ) ;
return F_5 ( V_15 -> V_24 , & V_2 ) ;
}
void T_2 F_6 ( struct V_36 * V_37 )
{
unsigned long V_38 ;
int V_39 ;
V_15 = V_37 ;
if ( V_15 -> V_16 & V_40 )
V_15 -> V_41 = F_1 ;
if ( F_7 ( V_15 -> V_24 , V_42 , & V_38 ) < 0 ) {
F_8 ( V_43 L_1 ) ;
return;
}
V_44 [ 0 ] . V_45 = V_38 + 0x300 ;
V_44 [ 0 ] . V_46 = V_38 + 0x30f ;
V_44 [ 1 ] . V_16 |= ( V_15 -> V_16 & V_47 ) ;
if ( V_15 -> V_41 ) {
V_39 = V_15 -> V_41 () ;
if ( V_39 != 0 )
goto V_48;
}
if ( F_9 ( V_15 -> V_49 , V_50 , L_2 ) < 0 )
goto V_48;
V_44 [ 1 ] . V_45 = F_10 ( V_15 -> V_49 ) ;
if ( V_15 -> V_51 ) {
V_39 = F_9 ( V_15 -> V_51 ,
V_52 , L_3 ) ;
if ( V_39 )
goto V_53;
}
if ( V_15 -> V_54 ) {
V_39 = F_9 ( V_15 -> V_54 ,
V_52 , L_4 ) ;
if ( V_39 )
goto V_55;
F_11 ( V_15 -> V_54 , 1 ) ;
F_12 ( 100 ) ;
F_11 ( V_15 -> V_54 , 0 ) ;
}
if ( F_13 ( & V_56 ) < 0 ) {
F_8 ( V_43 L_5 ) ;
F_14 ( V_15 -> V_54 ) ;
goto V_55;
}
return;
V_55:
if ( V_15 -> V_51 )
F_14 ( V_15 -> V_51 ) ;
V_53:
F_14 ( V_15 -> V_49 ) ;
V_48:
F_15 ( V_15 -> V_24 ) ;
F_8 ( V_43 L_6 ) ;
}
