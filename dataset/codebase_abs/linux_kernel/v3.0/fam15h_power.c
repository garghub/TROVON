static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
T_2 V_6 , V_7 , V_8 ;
T_3 V_9 ;
T_4 V_10 ;
struct V_11 * V_12 = F_2 ( V_2 ) ;
struct V_13 * V_14 = F_3 ( V_2 ) ;
F_4 ( V_12 -> V_15 , F_5 ( F_6 ( V_12 -> V_16 ) , 5 ) ,
V_17 , & V_6 ) ;
V_9 = ( V_6 >> 4 ) & 0x3fffff ;
V_9 = F_7 ( V_9 , 22 ) ;
V_8 = V_6 & 0xf ;
F_4 ( V_12 -> V_15 , F_5 ( F_6 ( V_12 -> V_16 ) , 5 ) ,
V_18 , & V_6 ) ;
V_7 = V_6 >> 16 ;
V_10 = V_7 + V_14 -> V_19 -
( T_3 ) ( V_9 >> ( V_8 + 1 ) ) ;
V_10 *= V_14 -> V_20 ;
V_10 = ( V_10 * 15625 ) >> 10 ;
return sprintf ( V_5 , L_1 , ( unsigned int ) V_10 ) ;
}
static T_1 F_8 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_13 * V_14 = F_3 ( V_2 ) ;
return sprintf ( V_5 , L_1 , V_14 -> V_21 ) ;
}
static T_1 F_9 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
return sprintf ( V_5 , L_2 ) ;
}
static bool T_5 F_10 ( struct V_11 * V_12 )
{
T_2 V_6 ;
F_4 ( V_12 -> V_15 , F_5 ( F_6 ( V_12 -> V_16 ) , 3 ) ,
V_22 , & V_6 ) ;
if ( ( V_6 & F_11 ( 29 ) ) && ( ( V_6 >> 30 ) & 3 ) )
return false ;
return true ;
}
static void T_5 F_12 ( struct V_11 * V_12 ,
struct V_13 * V_14 )
{
T_2 V_6 ;
T_4 V_23 ;
F_13 ( V_12 , V_24 , & V_6 ) ;
V_14 -> V_19 = V_6 >> 16 ;
V_23 = V_6 & 0xffff ;
F_4 ( V_12 -> V_15 , F_5 ( F_6 ( V_12 -> V_16 ) , 5 ) ,
V_18 , & V_6 ) ;
V_14 -> V_20 = ( ( V_6 & 0x3ff ) << 6 ) | ( ( V_6 >> 10 ) & 0x3f ) ;
V_23 *= V_14 -> V_20 ;
if ( ( V_23 >> 16 ) >= 256 )
F_14 ( & V_12 -> V_2 , L_3
L_4 ,
( unsigned int ) ( V_23 >> 16 ) ) ;
V_14 -> V_21 = ( V_23 * 15625 ) >> 10 ;
}
static int T_5 F_15 ( struct V_11 * V_25 ,
const struct V_26 * V_27 )
{
struct V_13 * V_14 ;
struct V_1 * V_2 ;
int V_28 ;
if ( ! F_10 ( V_25 ) ) {
V_28 = - V_29 ;
goto exit;
}
V_14 = F_16 ( sizeof( struct V_13 ) , V_30 ) ;
if ( ! V_14 ) {
V_28 = - V_31 ;
goto exit;
}
F_12 ( V_25 , V_14 ) ;
V_2 = & V_25 -> V_2 ;
F_17 ( V_2 , V_14 ) ;
V_28 = F_18 ( & V_2 -> V_32 , & V_33 ) ;
if ( V_28 )
goto V_34;
V_14 -> V_35 = F_19 ( V_2 ) ;
if ( F_20 ( V_14 -> V_35 ) ) {
V_28 = F_21 ( V_14 -> V_35 ) ;
goto V_36;
}
return 0 ;
V_36:
F_22 ( & V_2 -> V_32 , & V_33 ) ;
V_34:
F_23 ( V_14 ) ;
exit:
return V_28 ;
}
static void T_6 F_24 ( struct V_11 * V_25 )
{
struct V_1 * V_2 ;
struct V_13 * V_14 ;
V_2 = & V_25 -> V_2 ;
V_14 = F_3 ( V_2 ) ;
F_25 ( V_14 -> V_35 ) ;
F_22 ( & V_2 -> V_32 , & V_33 ) ;
F_17 ( V_2 , NULL ) ;
F_23 ( V_14 ) ;
}
static int T_7 F_26 ( void )
{
return F_27 ( & V_37 ) ;
}
static void T_8 F_28 ( void )
{
F_29 ( & V_37 ) ;
}
