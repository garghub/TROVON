static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
int V_6 ;
T_1 V_7 = 0 ;
T_2 V_8 ;
struct V_9 * V_10 = F_2 ( F_3 ( V_2 ) ) ;
F_4 ( & V_10 -> V_11 ) ;
V_6 = F_5 ( V_10 -> V_12 , V_10 -> V_13 , 2 ) ;
if ( V_6 )
goto V_14;
V_8 = ( ( ( T_2 ) ( V_10 -> V_13 [ 0 ] ) ) << 4 ) | ( ( V_10 -> V_13 [ 1 ] & 0xF0 ) >> 4 ) ;
V_7 = sprintf ( V_5 , L_1 , V_8 ) ;
V_14:
F_6 ( & V_10 -> V_11 ) ;
return V_6 ? V_6 : V_7 ;
}
static int T_3 F_7 ( struct V_15 * V_16 )
{
struct V_17 * V_18 ;
struct V_9 * V_10 ;
int V_6 = 0 ;
V_18 = F_8 ( sizeof( * V_10 ) ) ;
if ( V_18 == NULL ) {
V_6 = - V_19 ;
goto V_14;
}
V_10 = F_2 ( V_18 ) ;
F_9 ( V_16 , V_18 ) ;
F_10 ( & V_10 -> V_11 ) ;
V_10 -> V_12 = V_16 ;
V_18 -> V_2 . V_20 = & V_16 -> V_2 ;
V_18 -> V_21 = & V_22 ;
V_18 -> V_23 = V_24 ;
V_6 = F_11 ( V_10 -> V_25 ) ;
if ( V_6 )
goto V_26;
V_16 -> V_27 = 830000 ;
V_16 -> V_28 = V_29 ;
F_12 ( V_16 ) ;
return 0 ;
V_26:
F_13 ( V_10 -> V_25 ) ;
V_14:
return V_6 ;
}
static int T_4 F_14 ( struct V_15 * V_16 )
{
F_15 ( F_16 ( V_16 ) ) ;
return 0 ;
}
static T_5 int F_17 ( void )
{
return F_18 ( & V_30 ) ;
}
static T_6 void F_19 ( void )
{
F_20 ( & V_30 ) ;
}
