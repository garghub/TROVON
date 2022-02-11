static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 V_7 ;
struct V_8 V_9 ;
int V_10 ;
T_1 V_11 = 0 ;
T_2 V_12 ;
struct V_13 * V_14 = F_2 ( V_2 ) ;
struct V_15 * V_16 = V_14 -> V_17 ;
V_9 . V_11 = 1 ;
V_9 . V_18 = V_16 -> V_19 ;
V_9 . V_20 = V_16 -> V_21 ;
F_3 ( & V_16 -> V_22 ) ;
F_4 ( & V_7 ) ;
F_5 ( & V_9 , & V_7 ) ;
V_10 = F_6 ( V_16 -> V_23 , & V_7 ) ;
if ( V_10 )
goto V_24;
V_12 = ( ( ( T_2 ) ( V_16 -> V_21 [ 0 ] ) ) << 4 ) | ( ( V_16 -> V_21 [ 1 ] & 0xF0 ) >> 4 ) ;
V_11 = sprintf ( V_5 , L_1 , V_12 ) ;
V_24:
F_7 ( & V_16 -> V_22 ) ;
return V_10 ? V_10 : V_11 ;
}
static int T_3 F_8 ( struct V_25 * V_26 )
{
struct V_15 * V_16 ;
int V_10 = 0 ;
V_16 = F_9 ( sizeof( * V_16 ) , V_27 ) ;
if ( V_16 == NULL ) {
V_10 = - V_28 ;
goto V_24;
}
F_10 ( V_26 , V_16 ) ;
F_11 ( & V_16 -> V_22 ) ;
V_16 -> V_23 = V_26 ;
V_16 -> V_14 = F_12 ( 0 ) ;
if ( V_16 -> V_14 == NULL ) {
V_10 = - V_28 ;
goto V_29;
}
V_16 -> V_14 -> V_2 . V_30 = & V_26 -> V_2 ;
V_16 -> V_14 -> V_31 = & V_32 ;
V_16 -> V_14 -> V_17 = ( void * ) ( V_16 ) ;
V_16 -> V_14 -> V_33 = V_34 ;
V_10 = F_13 ( V_16 -> V_14 ) ;
if ( V_10 )
goto V_35;
V_26 -> V_36 = 830000 ;
V_26 -> V_37 = V_38 ;
F_14 ( V_26 ) ;
return 0 ;
V_35:
F_15 ( V_16 -> V_14 ) ;
V_29:
F_16 ( V_16 ) ;
V_24:
return V_10 ;
}
static int T_4 F_17 ( struct V_25 * V_26 )
{
struct V_15 * V_16 = F_18 ( V_26 ) ;
F_19 ( V_16 -> V_14 ) ;
F_16 ( V_16 ) ;
return 0 ;
}
static T_5 int F_20 ( void )
{
return F_21 ( & V_39 ) ;
}
static T_6 void F_22 ( void )
{
F_23 ( & V_39 ) ;
}
