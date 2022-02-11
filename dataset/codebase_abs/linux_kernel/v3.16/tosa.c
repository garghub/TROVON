static int F_1 ( struct V_1 * V_2 , T_1 V_3 , void * V_4 )
{
int V_5 ;
V_5 = F_2 ( V_6 , L_1 ) ;
if ( V_5 ) {
F_3 ( V_7 L_2 ) ;
goto V_8;
}
V_5 = F_4 ( V_6 ) ;
if ( V_5 )
goto V_9;
return 0 ;
V_9:
F_5 ( V_6 ) ;
V_8:
return V_5 ;
}
static void F_6 ( struct V_1 * V_2 , void * V_4 )
{
F_5 ( V_6 ) ;
}
static void F_7 ( struct V_1 * V_2 , int V_10 )
{
if ( V_10 & V_11 ) {
F_8 ( V_12 , 0 ) ;
F_9 ( V_2 , V_10 ) ;
F_10 ( V_13 , 0 ) ;
} else {
F_9 ( V_2 , V_10 ) ;
F_8 ( V_12 , 1 ) ;
}
}
static int F_11 ( struct V_1 * V_2 )
{
int V_14 ;
V_14 = F_2 ( V_13 , L_3 ) ;
if ( V_14 )
goto V_15;
V_14 = F_10 ( V_13 , 0 ) ;
if ( V_14 )
goto V_16;
V_14 = F_2 ( V_12 , L_4 ) ;
if ( V_14 )
goto V_17;
V_14 = F_10 ( V_12 , 0 ) ;
if ( V_14 )
goto V_18;
F_7 ( V_2 , V_19 | V_11 ) ;
return 0 ;
V_18:
F_5 ( V_12 ) ;
V_17:
V_16:
F_5 ( V_13 ) ;
V_15:
return V_14 ;
}
static void F_12 ( struct V_1 * V_2 )
{
F_7 ( V_2 , V_19 | V_11 ) ;
F_5 ( V_12 ) ;
F_5 ( V_13 ) ;
}
static int F_13 ( struct V_1 * V_2 )
{
int V_14 = F_2 ( V_20 , L_5 ) ;
if ( V_14 )
goto V_21;
V_14 = F_4 ( V_20 ) ;
if ( V_14 )
goto V_22;
return 0 ;
V_22:
F_5 ( V_20 ) ;
V_21:
return V_14 ;
}
static void F_14 ( struct V_1 * V_2 )
{
F_5 ( V_20 ) ;
}
static int F_15 ( void )
{
return F_16 ( V_20 ) == 0 ;
}
static int F_17 ( struct V_23 * V_2 )
{
int V_24 ;
V_24 = F_2 ( V_25 , L_6 ) ;
if ( V_24 )
goto V_26;
V_24 = F_2 ( V_27 , L_7 ) ;
if ( V_24 )
goto V_28;
V_24 = F_2 ( V_29 , L_8 ) ;
if ( V_24 )
goto V_30;
V_24 = F_10 ( V_29 , 0 ) ;
if ( V_24 )
goto V_31;
V_24 = F_10 ( V_27 , 0 ) ;
if ( V_24 )
goto V_32;
V_24 = F_10 ( V_25 , 0 ) ;
if ( V_24 )
goto V_33;
F_18 ( 1 ) ;
F_8 ( V_27 , 1 ) ;
F_18 ( 10 ) ;
F_8 ( V_25 , 1 ) ;
F_8 ( V_29 , 1 ) ;
return 0 ;
V_33:
V_32:
V_31:
F_5 ( V_29 ) ;
V_30:
F_5 ( V_27 ) ;
V_28:
F_5 ( V_25 ) ;
V_26:
return V_24 ;
}
static int F_19 ( struct V_23 * V_2 )
{
F_5 ( V_29 ) ;
F_5 ( V_27 ) ;
F_5 ( V_25 ) ;
return 0 ;
}
static int F_20 ( struct V_23 * V_2 )
{
F_8 ( V_27 , 1 ) ;
F_18 ( 10 ) ;
F_8 ( V_29 , 1 ) ;
F_18 ( 10 ) ;
return 0 ;
}
static int F_21 ( struct V_23 * V_2 )
{
F_8 ( V_29 , 0 ) ;
F_8 ( V_27 , 0 ) ;
return 0 ;
}
static int F_22 ( struct V_23 * V_2 )
{
int V_24 ;
V_24 = F_2 ( V_34 , L_9 ) ;
if ( V_24 )
goto V_35;
V_24 = F_10 ( V_34 , 1 ) ;
if ( V_24 )
goto V_36;
return V_24 ;
V_36:
F_5 ( V_34 ) ;
V_35:
return V_24 ;
}
static void F_23 ( struct V_23 * V_2 )
{
F_5 ( V_34 ) ;
}
static void F_24 ( void )
{
F_25 ( V_37 , NULL ) ;
}
static void F_26 ( enum V_38 V_10 , const char * V_39 )
{
T_2 V_40 = F_27 ( V_41 ) ;
if( ( V_40 & 0xffff0000 ) == 0x7ff00000 )
F_28 ( ( V_40 & 0xffff ) | 0x7ee00000 , V_41 ) ;
F_24 () ;
}
static void T_3 F_29 ( void )
{
F_30 ( F_31 ( V_42 ) ) ;
F_32 ( NULL ) ;
F_33 ( NULL ) ;
F_34 ( NULL ) ;
F_35 ( V_43 , 1 ) ;
F_36 ( V_44 , 0 , 0 ) ;
V_45 = F_24 ;
V_46 |= V_47 ;
V_48 = 0x01 ;
F_37 ( & V_49 ) ;
F_38 ( & V_50 ) ;
F_39 ( NULL ) ;
F_40 ( NULL ) ;
V_51 = & V_52 ;
F_41 ( 2 , & V_53 ) ;
F_42 ( V_54 , F_43 ( V_54 ) ) ;
F_44 ( L_10 , V_55 . V_56 , L_11 , NULL ) ;
F_45 ( V_57 , F_43 ( V_57 ) ) ;
}
static void T_3 F_46 ( struct V_58 * V_59 , char * * V_60 )
{
F_47 () ;
F_48 ( 0xa0000000 , V_61 ) ;
}
