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
if ( V_13 -> V_14 & V_15 )
return 0 ;
memset ( & V_4 , 0 , sizeof( V_4 ) ) ;
V_4 . V_16 = V_5 * 1000 ;
V_4 . V_17 = V_8 * 1000 ;
V_4 . V_18 = V_6 * 1000 ;
V_4 . V_19 = V_9 * 1000 ;
V_4 . V_20 = ( V_12 - V_5 ) * 1000 ;
V_4 . V_21 = V_5 * 1000 ;
V_4 . V_22 = V_10 * 1000 ;
V_4 . V_23 = V_11 * 1000 ;
V_4 . V_24 = V_7 * 1000 ;
V_4 . V_25 = ( V_12 - V_5 ) * 1000 ;
F_2 ( & V_2 , & V_26 , & V_4 ) ;
return F_3 ( V_13 -> V_27 , & V_2 ) ;
}
void T_1 F_4 ( struct V_28 * V_29 )
{
unsigned long V_30 ;
int V_31 ;
V_13 = V_29 ;
if ( V_13 -> V_14 & V_32 )
V_13 -> V_33 = F_1 ;
if ( F_5 ( V_13 -> V_27 , V_34 , & V_30 ) < 0 ) {
F_6 ( V_35 L_1 ) ;
return;
}
V_36 [ 0 ] . V_37 = V_30 + 0x300 ;
V_36 [ 0 ] . V_38 = V_30 + 0x30f ;
V_36 [ 1 ] . V_14 |= ( V_13 -> V_14 & V_39 ) ;
if ( V_13 -> V_14 & V_15 )
V_26 . V_40 = V_41 ;
if ( V_13 -> V_14 & V_42 )
V_26 . V_43 = true ;
if ( V_13 -> V_14 & V_44 )
V_26 . V_45 = true ;
if ( V_13 -> V_46 )
V_26 . V_46 = V_13 -> V_46 ;
V_31 = F_7 ( V_13 -> V_27 , & V_26 ) ;
if ( V_31 < 0 )
goto V_47;
if ( V_13 -> V_33 ) {
V_31 = V_13 -> V_33 () ;
if ( V_31 != 0 )
goto V_47;
}
if ( F_8 ( V_13 -> V_48 , V_49 , L_2 ) < 0 )
goto V_47;
V_36 [ 1 ] . V_37 = F_9 ( V_13 -> V_48 ) ;
if ( V_13 -> V_50 ) {
V_31 = F_8 ( V_13 -> V_50 ,
V_51 , L_3 ) ;
if ( V_31 )
goto V_52;
}
if ( V_13 -> V_53 ) {
V_31 = F_8 ( V_13 -> V_53 ,
V_51 , L_4 ) ;
if ( V_31 )
goto V_54;
F_10 ( V_13 -> V_53 , 1 ) ;
F_11 ( 100 ) ;
F_10 ( V_13 -> V_53 , 0 ) ;
}
if ( F_12 ( & V_55 ) < 0 ) {
F_6 ( V_35 L_5 ) ;
F_13 ( V_13 -> V_53 ) ;
goto V_54;
}
return;
V_54:
if ( V_13 -> V_50 )
F_13 ( V_13 -> V_50 ) ;
V_52:
F_13 ( V_13 -> V_48 ) ;
V_47:
F_14 ( V_13 -> V_27 ) ;
F_6 ( V_35 L_6 ) ;
}
