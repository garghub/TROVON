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
static int F_4 ( struct V_5 * V_6 , int V_7 )
{
F_5 ( F_6 ( V_8 ) , ! V_7 ) ;
return 0 ;
}
static int F_7 ( struct V_5 * V_6 )
{
return F_8 ( F_6 ( V_9 ) ) ;
}
static int F_9 ( struct V_5 * V_6 , T_2 V_10 ,
void * V_11 )
{
int V_12 ;
V_12 = F_10 ( V_13 , L_4 ) ;
if ( V_12 )
return V_12 ;
F_11 ( V_13 ) ;
#ifdef F_12
V_12 = F_10 ( V_14 , L_5 ) ;
if ( V_12 )
goto V_15;
F_11 ( V_14 ) ;
#endif
V_12 = F_13 ( F_14 ( F_6 ( V_16 ) ) , V_10 ,
V_17 , L_4 , V_11 ) ;
if ( V_12 )
goto V_18;
return 0 ;
V_18:
#ifdef F_12
F_15 ( V_14 ) ;
V_15:
#endif
F_15 ( V_13 ) ;
return V_12 ;
}
static void F_16 ( struct V_5 * V_6 , void * V_11 )
{
F_17 ( F_14 ( F_6 ( V_16 ) ) , V_11 ) ;
F_15 ( V_13 ) ;
F_15 ( V_14 ) ;
}
static int T_1 F_18 ( void )
{
int V_19 , V_12 = - V_20 ;
struct V_21 * V_22 = F_19 ( & V_23 ) ;
if ( F_20 ( V_22 ) )
return F_21 ( V_22 ) ;
V_19 = F_22 ( & V_22 -> V_6 ,
V_24 , V_24 ,
V_25 ,
V_26 | V_27 ) ;
if ( ! ( V_19 & V_26 ) )
goto V_28;
V_12 = F_23 ( V_22 ) ;
if ( V_12 )
V_28:
F_24 ( V_22 ) ;
return V_12 ;
}
static int F_25 ( struct V_21 * V_22 )
{
return F_26 ( V_22 -> V_29 , V_30 ) ;
}
static int F_27 ( struct V_21 * V_22 )
{
return F_26 ( V_22 -> V_29 , V_30 ) ;
}
static int T_1 F_28 ( char * V_31 )
{
if ( ! strcmp ( V_31 , L_6 ) )
V_32 = true ;
else if ( ! strcmp ( V_31 , L_7 ) )
V_32 = false ;
else
F_29 ( L_8
L_9 ) ;
return 1 ;
}
static void T_1 F_30 ( void )
{
int V_12 ;
F_31 () ;
F_32 ( 0 , V_33 , F_33 ( V_33 ) ) ;
F_34 ( V_34 , 1 ) ;
F_35 ( V_35 , F_33 ( V_35 ) ,
L_10 ) ;
#define F_36 (PAD_CTL_DRV_MAX | PAD_CTL_SRE_FAST | PAD_CTL_HYS_CMOS \
| PAD_CTL_ODE_CMOS | PAD_CTL_100K_PU)
F_37 ( V_36 , F_36 ) ;
F_37 ( V_37 , F_36 ) ;
F_37 ( V_38 , F_36 ) ;
F_37 ( V_39 , F_36 ) ;
F_37 ( V_40 , F_36 ) ;
F_37 ( V_41 , F_36 ) ;
F_37 ( V_42 , F_36 ) ;
F_37 ( V_43 , F_36 ) ;
F_37 ( V_44 , F_36 ) ;
F_37 ( V_45 , F_36 ) ;
F_37 ( V_46 , F_36 ) ;
F_37 ( V_47 , F_36 ) ;
if ( F_3 () == V_3 )
F_35 ( V_48 ,
F_33 ( V_48 ) , L_11 ) ;
else
F_35 ( V_49 ,
F_33 ( V_49 ) ,
L_11 ) ;
F_38 ( V_50 , F_33 ( V_50 ) ) ;
F_39 () ;
F_40 ( & V_51 ) ;
F_41 ( & V_51 ) ;
F_42 ( & V_51 ) ;
F_43 () ;
V_12 = F_10 ( F_6 ( V_52 ) , L_12 ) ;
if ( V_12 )
F_2 ( L_13 ) ;
else {
F_11 ( F_6 ( V_52 ) ) ;
V_53 [ 1 ] . V_54 =
F_14 ( F_6 ( V_52 ) ) ;
V_53 [ 1 ] . V_55 =
F_14 ( F_6 ( V_52 ) ) ;
F_44 ( & V_56 ) ;
}
F_45 ( 1 , V_57 ,
F_33 ( V_57 ) ) ;
F_46 ( & V_58 ) ;
F_47 ( & V_59 ) ;
F_48 ( & V_60 ) ;
F_49 ( 0 , & V_61 ) ;
F_50 () ;
F_51 ( & V_62 ) ;
V_12 = F_10 ( F_6 ( V_8 ) , L_14 ) ;
if ( ! V_12 )
F_52 ( F_6 ( V_8 ) , 1 ) ;
else
V_63 . V_64 = NULL ;
F_18 () ;
V_65 [ 1 ] . V_54 =
F_14 ( F_6 ( F_53 ( 48 , 105 ) ) ) ;
V_65 [ 1 ] . V_55 =
F_14 ( F_6 ( F_53 ( 48 , 105 ) ) ) ;
F_44 ( & V_66 ) ;
if ( V_32 ) {
V_67 . V_68 = F_54 ( V_69 |
V_70 ) ;
if ( V_67 . V_68 )
F_55 ( & V_67 ) ;
}
V_71 . V_68 = F_54 ( V_69 |
V_70 ) ;
if ( V_71 . V_68 )
F_56 ( 2 , & V_71 ) ;
if ( ! V_32 )
F_57 ( & V_72 ) ;
}
static void T_1 F_58 ( void )
{
F_59 ( 26000000 ) ;
}
static void T_1 F_60 ( void )
{
V_24 = F_61 ( V_25 ,
V_25 ) ;
}
static void T_1 F_62 ( void )
{
F_63 () ;
}
