static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
T_2 V_6 ;
F_2 ( F_3 ( V_2 ) ,
V_7 , & V_6 ) ;
return sprintf ( V_5 , L_1 , ( V_6 >> 21 ) * 125 ) ;
}
static T_1 F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
return sprintf ( V_5 , L_2 , 70 * 1000 ) ;
}
static T_1 F_5 ( struct V_1 * V_2 ,
struct V_3 * V_8 , char * V_5 )
{
struct V_9 * V_4 = F_6 ( V_8 ) ;
int V_10 = V_4 -> V_11 ;
T_2 V_6 ;
int V_12 ;
F_2 ( F_3 ( V_2 ) ,
V_13 , & V_6 ) ;
V_12 = ( ( V_6 >> 16 ) & 0x7f ) * 500 + 52000 ;
if ( V_10 )
V_12 -= ( ( V_6 >> 24 ) & 0xf ) * 500 ;
return sprintf ( V_5 , L_2 , V_12 ) ;
}
static T_1 F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
return sprintf ( V_5 , L_3 ) ;
}
static bool T_3 F_8 ( struct V_14 * V_15 )
{
T_2 V_16 , V_17 ;
if ( V_18 . V_19 != 0x10 )
return false ;
V_16 = F_9 ( 0x80000001 ) & V_20 ;
if ( V_16 == V_21 )
return true ;
if ( V_16 != V_22 )
return false ;
F_10 ( V_15 -> V_23 ,
F_11 ( F_12 ( V_15 -> V_24 ) , 2 ) ,
V_25 , & V_17 ) ;
if ( V_17 & V_26 )
return false ;
return V_18 . V_27 < 4 ||
( V_18 . V_27 == 4 && V_18 . V_28 <= 2 ) ;
}
static int T_3 F_13 ( struct V_14 * V_15 ,
const struct V_29 * V_30 )
{
struct V_1 * V_31 ;
T_2 V_32 , V_33 ;
int V_34 = F_8 ( V_15 ) ;
int V_35 ;
if ( V_34 && ! V_36 ) {
F_14 ( & V_15 -> V_2 ,
L_4 ) ;
V_35 = - V_37 ;
goto exit;
}
V_35 = F_15 ( & V_15 -> V_2 , & V_38 ) ;
if ( V_35 )
goto exit;
V_35 = F_15 ( & V_15 -> V_2 , & V_39 ) ;
if ( V_35 )
goto V_40;
F_2 ( V_15 , V_41 , & V_32 ) ;
F_2 ( V_15 , V_13 , & V_33 ) ;
if ( ( V_32 & V_42 ) && ( V_33 & V_43 ) ) {
V_35 = F_15 ( & V_15 -> V_2 ,
& V_44 . V_45 ) ;
if ( V_35 )
goto V_40;
V_35 = F_15 ( & V_15 -> V_2 ,
& V_46 . V_45 ) ;
if ( V_35 )
goto V_40;
}
V_35 = F_15 ( & V_15 -> V_2 , & V_47 ) ;
if ( V_35 )
goto V_40;
V_31 = F_16 ( & V_15 -> V_2 ) ;
if ( F_17 ( V_31 ) ) {
V_35 = F_18 ( V_31 ) ;
goto V_40;
}
F_19 ( V_15 , V_31 ) ;
if ( V_34 && V_36 )
F_20 ( & V_15 -> V_2 ,
L_5 ) ;
return 0 ;
V_40:
F_21 ( & V_15 -> V_2 , & V_47 ) ;
F_21 ( & V_15 -> V_2 , & V_38 ) ;
F_21 ( & V_15 -> V_2 , & V_39 ) ;
F_21 ( & V_15 -> V_2 ,
& V_44 . V_45 ) ;
F_21 ( & V_15 -> V_2 ,
& V_46 . V_45 ) ;
exit:
return V_35 ;
}
static void T_4 F_22 ( struct V_14 * V_15 )
{
F_23 ( F_24 ( V_15 ) ) ;
F_21 ( & V_15 -> V_2 , & V_47 ) ;
F_21 ( & V_15 -> V_2 , & V_38 ) ;
F_21 ( & V_15 -> V_2 , & V_39 ) ;
F_21 ( & V_15 -> V_2 ,
& V_44 . V_45 ) ;
F_21 ( & V_15 -> V_2 ,
& V_46 . V_45 ) ;
F_19 ( V_15 , NULL ) ;
}
static int T_5 F_25 ( void )
{
return F_26 ( & V_48 ) ;
}
static void T_6 F_27 ( void )
{
F_28 ( & V_48 ) ;
}
