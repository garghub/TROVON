static int T_1 F_1 ( char * V_1 )
{
if ( ! strcmp ( L_1 , V_1 ) )
V_2 = V_3 ;
else if ( strcmp ( L_2 , V_1 ) )
F_2 ( L_3 , V_1 ) ;
return 1 ;
}
enum V_4 F_3 ( void )
{
return V_2 ;
}
static int F_4 ( struct V_5 * V_6 )
{
return F_5 ( F_6 ( V_7 ) ) ;
}
static int F_7 ( struct V_5 * V_6 , T_2 V_8 ,
void * V_9 )
{
int V_10 ;
V_10 = F_8 ( V_11 , L_4 ) ;
if ( V_10 )
return V_10 ;
F_9 ( V_11 ) ;
#ifdef F_10
V_10 = F_8 ( V_12 , L_5 ) ;
if ( V_10 )
goto V_13;
F_9 ( V_12 ) ;
#endif
V_10 = F_11 ( F_12 ( F_6 ( V_14 ) ) , V_8 ,
V_15 , L_4 , V_9 ) ;
if ( V_10 )
goto V_16;
return 0 ;
V_16:
#ifdef F_10
F_13 ( V_12 ) ;
V_13:
#endif
F_13 ( V_11 ) ;
return V_10 ;
}
static void F_14 ( struct V_5 * V_6 , void * V_9 )
{
F_15 ( F_12 ( F_6 ( V_14 ) ) , V_9 ) ;
F_13 ( V_11 ) ;
F_13 ( V_12 ) ;
}
static int F_16 ( struct V_17 * V_18 )
{
return F_17 ( V_18 -> V_19 , V_20 ) ;
}
static int F_18 ( struct V_17 * V_18 )
{
return F_17 ( V_18 -> V_19 , V_20 ) ;
}
static int T_1 F_19 ( char * V_21 )
{
if ( ! strcmp ( V_21 , L_6 ) )
V_22 = true ;
else if ( ! strcmp ( V_21 , L_7 ) )
V_22 = false ;
else
F_20 ( L_8
L_9 ) ;
return 1 ;
}
static void T_1 F_21 ( void )
{
F_22 () ;
F_23 ( 0 , V_23 , F_24 ( V_23 ) ) ;
F_25 ( V_24 , 1 ) ;
F_26 ( V_25 , F_24 ( V_25 ) ,
L_10 ) ;
#define F_27 (PAD_CTL_DRV_MAX | PAD_CTL_SRE_FAST | PAD_CTL_HYS_CMOS \
| PAD_CTL_ODE_CMOS | PAD_CTL_100K_PU)
F_28 ( V_26 , F_27 ) ;
F_28 ( V_27 , F_27 ) ;
F_28 ( V_28 , F_27 ) ;
F_28 ( V_29 , F_27 ) ;
F_28 ( V_30 , F_27 ) ;
F_28 ( V_31 , F_27 ) ;
F_28 ( V_32 , F_27 ) ;
F_28 ( V_33 , F_27 ) ;
F_28 ( V_34 , F_27 ) ;
F_28 ( V_35 , F_27 ) ;
F_28 ( V_36 , F_27 ) ;
F_28 ( V_37 , F_27 ) ;
if ( F_3 () == V_3 )
F_26 ( V_38 ,
F_24 ( V_38 ) , L_11 ) ;
else
F_26 ( V_39 ,
F_24 ( V_39 ) ,
L_11 ) ;
F_29 ( V_40 , F_24 ( V_40 ) ) ;
F_30 () ;
F_31 ( & V_41 ) ;
F_32 ( & V_41 ) ;
F_33 ( & V_41 ) ;
F_34 () ;
F_35 ( 1 , V_42 ,
F_24 ( V_42 ) ) ;
F_36 ( & V_43 ) ;
F_37 ( & V_44 ) ;
F_38 ( & V_45 ) ;
F_39 () ;
F_40 ( & V_46 ) ;
if ( V_22 ) {
V_47 . V_48 = F_41 ( V_49 |
V_50 ) ;
if ( V_47 . V_48 )
F_42 ( & V_47 ) ;
}
V_51 . V_48 = F_41 ( V_49 |
V_50 ) ;
if ( V_51 . V_48 )
F_43 ( 2 , & V_51 ) ;
if ( ! V_22 )
F_44 ( & V_52 ) ;
}
static void T_1 F_45 ( void )
{
F_46 ( 26000000 ) ;
}
static void T_1 F_47 ( void )
{
int V_10 ;
V_10 = F_8 ( F_6 ( V_53 ) , L_12 ) ;
if ( ! V_10 ) {
F_9 ( F_6 ( V_53 ) ) ;
V_54 [ 1 ] . V_55 =
F_12 ( F_6 ( V_53 ) ) ;
V_54 [ 1 ] . V_56 =
F_12 ( F_6 ( V_53 ) ) ;
F_48 ( & V_57 ) ;
} else {
F_2 ( L_13 ) ;
}
F_49 ( 0 , & V_58 ) ;
V_59 [ 1 ] . V_55 =
F_12 ( F_6 ( F_50 ( 48 , 105 ) ) ) ;
V_59 [ 1 ] . V_56 =
F_12 ( F_6 ( F_50 ( 48 , 105 ) ) ) ;
F_48 ( & V_60 ) ;
F_51 () ;
}
