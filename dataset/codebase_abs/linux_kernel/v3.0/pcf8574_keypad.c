static short F_1 ( struct V_1 * V_2 )
{
unsigned char V_3 , V_4 , V_5 , V_6 ;
F_2 ( V_2 -> V_7 , 240 ) ;
V_3 = 0xF & ( ~ ( F_3 ( V_2 -> V_7 ) >> 4 ) ) ;
F_2 ( V_2 -> V_7 , 15 ) ;
V_4 = 0xF & ( ~ F_3 ( V_2 -> V_7 ) ) ;
for ( V_5 = 0 ; V_3 > 0 ; V_5 ++ )
V_3 = V_3 >> 1 ;
for ( V_6 = 0 ; V_4 > 0 ; V_6 ++ )
V_4 = V_4 >> 1 ;
return ( ( V_5 - 1 ) * 4 ) + V_6 ;
}
static T_1 F_4 ( int V_8 , void * V_9 )
{
struct V_1 * V_2 = V_9 ;
unsigned char V_10 = F_1 ( V_2 ) ;
if ( V_2 -> V_11 != V_10 ) {
int V_12 = V_10 < F_5 ( V_2 -> V_13 ) ;
unsigned short V_14 = V_12 ?
V_2 -> V_13 [ V_10 ] : V_2 -> V_13 [ V_2 -> V_11 ] ;
F_6 ( V_2 -> V_15 , V_14 , V_12 ) ;
F_7 ( V_2 -> V_15 ) ;
V_2 -> V_11 = V_10 ;
}
return V_16 ;
}
static int T_2 F_8 ( struct V_17 * V_7 , const struct V_18 * V_19 )
{
int V_20 , V_21 ;
struct V_22 * V_15 ;
struct V_1 * V_2 ;
if ( F_2 ( V_7 , 240 ) < 0 ) {
F_9 ( & V_7 -> V_23 , L_1 ) ;
return - V_24 ;
}
V_2 = F_10 ( sizeof( * V_2 ) , V_25 ) ;
if ( ! V_2 )
return - V_26 ;
V_15 = F_11 () ;
if ( ! V_15 ) {
F_9 ( & V_7 -> V_23 , L_2 ) ;
V_21 = - V_26 ;
goto V_27;
}
V_2 -> V_15 = V_15 ;
V_2 -> V_7 = V_7 ;
V_15 -> V_28 [ 0 ] = F_12 ( V_29 ) ;
V_15 -> V_14 = V_2 -> V_13 ;
V_15 -> V_30 = sizeof( V_2 -> V_13 [ 0 ] ) ;
V_15 -> V_31 = F_5 ( V_2 -> V_13 ) ;
for ( V_20 = 0 ; V_20 < F_5 ( V_32 ) ; V_20 ++ ) {
V_2 -> V_13 [ V_20 ] = V_32 [ V_20 ] ;
F_13 ( V_2 -> V_13 [ V_20 ] & V_33 , V_15 -> V_34 ) ;
}
sprintf ( V_2 -> V_35 , V_36 ) ;
sprintf ( V_2 -> V_37 , L_3 ) ;
V_15 -> V_35 = V_2 -> V_35 ;
V_15 -> V_37 = V_2 -> V_37 ;
V_15 -> V_19 . V_38 = V_39 ;
V_15 -> V_19 . V_40 = 0x0001 ;
V_15 -> V_19 . V_41 = 0x0001 ;
V_15 -> V_19 . V_42 = 0x0100 ;
V_2 -> V_11 = F_1 ( V_2 ) ;
V_21 = F_14 ( V_7 -> V_8 , NULL , F_4 ,
V_43 | V_44 ,
V_36 , V_2 ) ;
if ( V_21 ) {
F_9 ( & V_7 -> V_23 , L_4 , V_7 -> V_8 ) ;
goto V_45;
}
V_21 = F_15 ( V_15 ) ;
if ( V_21 ) {
F_9 ( & V_7 -> V_23 , L_5 ) ;
goto V_46;
}
F_16 ( V_7 , V_2 ) ;
return 0 ;
V_46:
F_17 ( V_7 -> V_8 , V_2 ) ;
V_45:
F_18 ( V_15 ) ;
V_27:
F_19 ( V_2 ) ;
return V_21 ;
}
static int T_3 F_20 ( struct V_17 * V_7 )
{
struct V_1 * V_2 = F_21 ( V_7 ) ;
F_17 ( V_7 -> V_8 , V_2 ) ;
F_22 ( V_2 -> V_15 ) ;
F_19 ( V_2 ) ;
return 0 ;
}
static int F_23 ( struct V_47 * V_23 )
{
struct V_17 * V_7 = F_24 ( V_23 ) ;
F_25 ( V_7 -> V_8 ) ;
return 0 ;
}
static int F_26 ( struct V_47 * V_23 )
{
struct V_17 * V_7 = F_24 ( V_23 ) ;
F_27 ( V_7 -> V_8 ) ;
return 0 ;
}
static int T_4 F_28 ( void )
{
return F_29 ( & V_48 ) ;
}
static void T_5 F_30 ( void )
{
F_31 ( & V_48 ) ;
}
