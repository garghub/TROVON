static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_3 = V_2 ;
struct V_4 * V_5 = V_3 -> V_5 ;
unsigned char V_6 ;
V_6 = F_2 ( V_3 -> V_7 ) ;
F_3 ( V_5 , V_6 & 0x7f , V_6 & 0x80 ? 0 : 1 ) ;
F_4 ( V_5 ) ;
return V_8 ;
}
static int T_2 F_5 ( struct V_9 * V_10 )
{
struct V_4 * V_5 ;
struct V_3 * V_3 ;
struct V_11 * V_12 ;
int V_1 , V_13 , error ;
V_12 = F_6 ( V_10 , V_14 , 0 ) ;
if ( ! V_12 ) {
F_7 ( & V_10 -> V_15 , L_1 ) ;
return - V_16 ;
}
V_1 = F_8 ( V_10 , 0 ) ;
if ( V_1 < 0 ) {
F_7 ( & V_10 -> V_15 , L_2 ) ;
return - V_16 ;
}
V_3 = F_9 ( sizeof( * V_3 ) , V_17 ) ;
V_5 = F_10 () ;
if ( ! V_3 || ! V_5 ) {
F_7 ( & V_10 -> V_15 , L_3 ) ;
error = - V_18 ;
goto V_19;
}
V_3 -> V_20 = V_12 ;
V_12 = F_11 ( V_12 -> V_21 , F_12 ( V_12 ) , V_10 -> V_22 ) ;
if ( ! V_12 ) {
F_7 ( & V_10 -> V_15 , L_4 ) ;
error = - V_23 ;
goto V_19;
}
V_3 -> V_7 = F_13 ( V_12 -> V_21 , F_12 ( V_12 ) ) ;
if ( ! V_3 -> V_7 ) {
F_7 ( & V_10 -> V_15 , L_5 ) ;
error = - V_24 ;
goto V_25;
}
V_3 -> V_5 = V_5 ;
V_3 -> V_1 = V_1 ;
V_5 -> V_22 = V_10 -> V_22 ;
V_5 -> V_26 = L_6 ;
V_5 -> V_15 . V_27 = & V_10 -> V_15 ;
F_14 ( V_5 , V_3 ) ;
V_5 -> V_28 . V_29 = V_30 ;
V_5 -> V_28 . V_31 = 0x0001 ;
V_5 -> V_28 . V_32 = 0x0001 ;
V_5 -> V_28 . V_33 = 0x0100 ;
V_5 -> V_34 = V_3 -> V_35 ;
V_5 -> V_36 = sizeof( V_3 -> V_35 [ 0 ] ) ;
V_5 -> V_37 = F_15 ( V_3 -> V_35 ) ;
F_16 ( V_38 , V_5 -> V_39 ) ;
for ( V_13 = 0 ; V_13 < F_15 ( V_3 -> V_35 ) ; V_13 ++ ) {
V_3 -> V_35 [ V_13 ] = V_13 ;
F_16 ( V_3 -> V_35 [ V_13 ] , V_5 -> V_40 ) ;
}
F_17 ( V_41 , V_5 -> V_40 ) ;
error = F_18 ( V_1 , & F_1 ,
V_42 , V_10 -> V_22 , V_3 ) ;
if ( error ) {
F_7 ( & V_10 -> V_15 , L_7 , V_1 ) ;
goto V_43;
}
error = F_19 ( V_5 ) ;
if ( error ) {
F_7 ( & V_10 -> V_15 , L_8 ) ;
goto V_44;
}
F_20 ( V_10 , V_3 ) ;
return 0 ;
V_44:
F_21 ( V_1 , V_3 ) ;
V_43:
F_22 ( V_3 -> V_7 ) ;
V_25:
F_23 ( V_12 -> V_21 , F_12 ( V_12 ) ) ;
V_19:
F_24 ( V_5 ) ;
F_25 ( V_3 ) ;
return error ;
}
static int T_3 F_26 ( struct V_9 * V_10 )
{
struct V_3 * V_3 = F_27 ( V_10 ) ;
F_21 ( V_3 -> V_1 , V_3 ) ;
F_22 ( V_3 -> V_7 ) ;
F_23 ( V_3 -> V_20 -> V_21 ,
F_12 ( V_3 -> V_20 ) ) ;
F_28 ( V_3 -> V_5 ) ;
F_25 ( V_3 ) ;
F_20 ( V_10 , NULL ) ;
return 0 ;
}
static int T_4 F_29 ( void )
{
return F_30 ( & V_45 ) ;
}
static void T_5 F_31 ( void )
{
F_32 ( & V_45 ) ;
}
