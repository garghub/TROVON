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
V_9 = F_7 ( V_9 , 21 ) ;
V_8 = ( V_6 & 0xf ) + 1 ;
F_4 ( V_12 -> V_15 , F_5 ( F_6 ( V_12 -> V_16 ) , 5 ) ,
V_18 , & V_6 ) ;
V_7 = V_6 >> 16 ;
V_10 = ( V_7 + V_14 -> V_19 ) << V_8 ;
V_10 -= V_9 ;
V_10 *= V_14 -> V_20 ;
V_10 = ( V_10 * 15625 ) >> ( 10 + V_8 ) ;
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
static void T_5 F_12 ( struct V_11 * V_23 )
{
T_2 V_6 ;
if ( ! F_13 ( V_24 , V_23 ) )
return;
F_4 ( V_23 -> V_15 ,
F_5 ( F_6 ( V_23 -> V_16 ) , 5 ) ,
V_17 , & V_6 ) ;
if ( ( V_6 & 0xf ) != 0xe )
return;
V_6 &= ~ 0xf ;
V_6 |= 0x9 ;
F_14 ( V_23 -> V_15 ,
F_5 ( F_6 ( V_23 -> V_16 ) , 5 ) ,
V_17 , V_6 ) ;
}
static void T_5 F_15 ( struct V_11 * V_12 ,
struct V_13 * V_14 )
{
T_2 V_6 ;
T_4 V_25 ;
F_16 ( V_12 , V_26 , & V_6 ) ;
V_14 -> V_19 = V_6 >> 16 ;
V_25 = V_6 & 0xffff ;
F_4 ( V_12 -> V_15 , F_5 ( F_6 ( V_12 -> V_16 ) , 5 ) ,
V_18 , & V_6 ) ;
V_14 -> V_20 = ( ( V_6 & 0x3ff ) << 6 ) | ( ( V_6 >> 10 ) & 0x3f ) ;
V_25 *= V_14 -> V_20 ;
if ( ( V_25 >> 16 ) >= 256 )
F_17 ( & V_12 -> V_2 , L_3
L_4 ,
( unsigned int ) ( V_25 >> 16 ) ) ;
V_14 -> V_21 = ( V_25 * 15625 ) >> 10 ;
}
static int T_5 F_18 ( struct V_11 * V_23 ,
const struct V_27 * V_28 )
{
struct V_13 * V_14 ;
struct V_1 * V_2 ;
int V_29 ;
F_12 ( V_23 ) ;
if ( ! F_10 ( V_23 ) ) {
V_29 = - V_30 ;
goto exit;
}
V_14 = F_19 ( sizeof( struct V_13 ) , V_31 ) ;
if ( ! V_14 ) {
V_29 = - V_32 ;
goto exit;
}
F_15 ( V_23 , V_14 ) ;
V_2 = & V_23 -> V_2 ;
F_20 ( V_2 , V_14 ) ;
V_29 = F_21 ( & V_2 -> V_33 , & V_34 ) ;
if ( V_29 )
goto V_35;
V_14 -> V_36 = F_22 ( V_2 ) ;
if ( F_23 ( V_14 -> V_36 ) ) {
V_29 = F_24 ( V_14 -> V_36 ) ;
goto V_37;
}
return 0 ;
V_37:
F_25 ( & V_2 -> V_33 , & V_34 ) ;
V_35:
F_26 ( V_14 ) ;
exit:
return V_29 ;
}
static void T_6 F_27 ( struct V_11 * V_23 )
{
struct V_1 * V_2 ;
struct V_13 * V_14 ;
V_2 = & V_23 -> V_2 ;
V_14 = F_3 ( V_2 ) ;
F_28 ( V_14 -> V_36 ) ;
F_25 ( & V_2 -> V_33 , & V_34 ) ;
F_20 ( V_2 , NULL ) ;
F_26 ( V_14 ) ;
}
static int T_7 F_29 ( void )
{
return F_30 ( & V_38 ) ;
}
static void T_8 F_31 ( void )
{
F_32 ( & V_38 ) ;
}
