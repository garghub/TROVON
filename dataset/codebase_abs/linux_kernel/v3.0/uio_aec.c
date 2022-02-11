static T_1 F_1 ( int V_1 , struct V_2 * V_3 )
{
void T_2 * V_4 = V_3 -> V_5 + V_6 ;
unsigned char V_7 = F_2 ( V_4 ) ;
if ( ( V_7 & V_8 ) && ( V_7 & V_9 ) ) {
V_7 = F_2 ( V_3 -> V_5 + V_10 ) ;
return V_11 ;
}
return V_12 ;
}
static void F_3 ( struct V_13 * V_14 , struct V_2 * V_15 )
{
V_3 ( & V_14 -> V_16 , L_1
L_2 ,
F_2 ( V_15 -> V_5 + 0x01 ) ,
F_2 ( V_15 -> V_5 + 0x00 ) ,
F_2 ( V_15 -> V_5 + 0x03 ) ,
F_2 ( V_15 -> V_5 + 0x02 ) ,
F_2 ( V_15 -> V_5 + 0x06 ) ,
F_2 ( V_15 -> V_5 + 0x07 ) ) ;
}
static int T_3 F_4 ( struct V_13 * V_14 , const struct V_17 * V_18 )
{
struct V_2 * V_19 ;
int V_20 ;
V_19 = F_5 ( sizeof( struct V_2 ) , V_21 ) ;
if ( ! V_19 )
return - V_22 ;
if ( F_6 ( V_14 ) )
goto V_23;
if ( F_7 ( V_14 , L_3 ) )
goto V_24;
V_19 -> V_25 = L_3 ;
V_19 -> V_26 [ 0 ] . V_27 = F_8 ( V_14 , 0 ) ;
if ( ! V_19 -> V_26 [ 0 ] . V_27 )
goto V_28;
V_19 -> V_5 = F_9 ( V_14 , 0 , 0 ) ;
if ( ! V_19 -> V_5 )
goto V_28;
V_19 -> V_26 [ 0 ] . V_29 = F_10 ( V_14 , 0 ) ;
V_19 -> V_26 [ 0 ] . V_30 = V_31 ;
V_19 -> V_32 = L_4 ;
V_19 -> V_1 = V_14 -> V_1 ;
V_19 -> V_33 = V_34 ;
V_19 -> V_35 = F_1 ;
F_3 ( V_14 , V_19 ) ;
V_20 = F_11 ( & V_14 -> V_16 , V_19 ) ;
if ( V_20 )
goto V_36;
F_12 ( V_37 , V_19 -> V_5 + V_38 ) ;
F_13 ( V_39 , V_19 -> V_5 + V_40 ) ;
if ( ! ( F_2 ( V_19 -> V_5 + V_6 )
& V_8 ) )
F_14 ( & V_14 -> V_16 , L_5 ) ;
F_15 ( V_14 , V_19 ) ;
return 0 ;
V_36:
F_16 ( V_14 , V_19 -> V_5 ) ;
V_28:
F_17 ( V_14 ) ;
V_24:
F_18 ( V_14 ) ;
V_23:
F_19 ( V_19 ) ;
return - V_41 ;
}
static void remove ( struct V_13 * V_14 )
{
struct V_2 * V_19 = F_20 ( V_14 ) ;
F_13 ( V_42 , V_19 -> V_5 + V_40 ) ;
F_12 ( V_42 , V_19 -> V_5 + V_38 ) ;
F_2 ( V_19 -> V_5 + V_10 ) ;
F_21 ( V_19 ) ;
F_17 ( V_14 ) ;
F_18 ( V_14 ) ;
F_15 ( V_14 , NULL ) ;
F_22 ( V_19 -> V_5 ) ;
F_19 ( V_19 ) ;
}
static int T_4 F_23 ( void )
{
return F_24 ( & V_43 ) ;
}
static void T_5 F_25 ( void )
{
F_26 ( & V_43 ) ;
}
