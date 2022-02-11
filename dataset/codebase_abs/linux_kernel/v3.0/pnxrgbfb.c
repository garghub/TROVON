static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
return 0 ;
}
static int F_2 ( T_1 V_5 , T_1 V_6 , T_1 V_7 , T_1 V_8 ,
T_1 V_9 , struct V_1 * V_2 )
{
if ( V_5 > 15 )
return 1 ;
V_10 [ V_5 ] = ( ( V_6 & 0xff00 ) << 8 ) | ( V_7 & 0xff00 ) |
( ( V_8 & 0xff00 ) >> 8 ) ;
return 0 ;
}
static int F_3 ( struct V_1 * V_2 , struct V_11 * V_12 )
{
return F_4 ( V_2 , V_12 , NULL ) ;
}
static int F_5 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = F_6 ( V_14 ) ;
if ( V_2 ) {
F_7 ( V_2 ) ;
F_8 ( & V_2 -> V_15 ) ;
F_9 ( V_2 ) ;
F_10 ( V_14 , NULL ) ;
}
F_11 ( V_16 , V_14 -> V_17 ) ;
F_12 ( V_14 -> V_17 ) ;
return 0 ;
}
static int T_2 F_13 ( struct V_13 * V_14 )
{
struct V_1 * V_2 ;
struct V_18 V_19 ;
int V_20 ;
char * V_21 ;
V_2 = F_14 ( sizeof( V_22 ) * 16 , & V_14 -> V_23 ) ;
if ( ! V_2 ) {
V_20 = - V_24 ;
goto V_25;
}
F_15 ( V_26 , ( void * * ) & V_2 -> V_27 ,
( V_28 * ) & V_29 . V_30 ,
& V_29 . V_31 ) ;
if ( ( V_20 = F_16 ( V_14 -> V_17 ) ) < 0 )
goto V_32;
else {
V_16 = V_20 ;
V_19 . V_33 = V_16 ;
V_19 . V_34 = ( V_22 * ) NULL ;
V_19 . V_35 = ( V_22 * ) V_29 . V_30 ;
V_19 . V_36 = 0 ;
V_19 . V_37 = 0 ;
V_19 . V_38 = V_39 ;
V_19 . V_40 = V_41 ;
if ( ( V_20 = F_17 ( V_19 , V_14 -> V_17 ) ) < 0 )
goto V_42;
if ( ( V_20 =
F_18 ( V_16 , V_43 ,
V_14 -> V_17 ) ) < 0 )
goto V_42;
if ( ( V_20 =
F_19 ( V_16 ,
V_44 ,
V_14 -> V_17 ) ) < 0 )
goto V_42;
}
if ( ! F_20 ( L_1 , & V_21 ) && V_21 &&
! strcmp ( V_21 , L_2 ) )
V_45 . V_3 = F_1 ;
V_2 -> V_46 = - 1 ;
V_2 -> V_47 = V_48 ;
V_2 -> V_49 = & V_45 ;
V_2 -> V_50 = V_29 ;
V_2 -> V_51 = V_52 ;
V_2 -> V_53 = V_29 . V_31 ;
V_2 -> V_54 = V_2 -> V_55 ;
V_2 -> V_55 = NULL ;
V_20 = F_21 ( & V_2 -> V_15 , 256 , 0 ) ;
if ( V_20 < 0 )
goto V_42;
V_20 = F_22 ( V_2 ) ;
if ( V_20 < 0 )
goto V_56;
F_10 ( V_14 , V_2 ) ;
return 0 ;
V_56:
F_8 ( & V_2 -> V_15 ) ;
V_42:
F_11 ( V_16 , V_14 -> V_17 ) ;
V_32:
F_9 ( V_2 ) ;
V_25:
return V_20 ;
}
static int T_3 F_23 ( void )
{
return F_24 ( & V_57 ) ;
}
static void T_4 F_25 ( void )
{
F_26 ( & V_57 ) ;
}
