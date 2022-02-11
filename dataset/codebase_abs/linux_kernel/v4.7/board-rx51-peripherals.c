static int F_1 ( void )
{
int V_1 ;
int V_2 = V_3 ;
int V_4 = V_5 ;
V_1 = F_2 ( V_2 , L_1 ) ;
if ( V_1 ) {
F_3 ( V_6 L_2 ) ;
goto V_7;
}
V_1 = F_2 ( V_4 , L_3 ) ;
if ( V_1 ) {
F_4 ( V_2 ) ;
F_3 ( V_6 L_2 ) ;
goto V_7;
}
F_5 ( V_2 ) ;
F_5 ( V_4 ) ;
V_7:
return V_1 ;
}
static int F_6 ( void )
{
F_4 ( V_3 ) ;
F_4 ( V_5 ) ;
return 0 ;
}
static void F_7 ( bool V_8 )
{
F_8 ( V_9 , V_8 ) ;
}
static void T_1 F_9 ( void )
{
F_10 ( F_11 ( V_9 ,
V_10 , L_4 ) ) ;
F_12 ( & V_11 ) ;
F_12 ( & V_12 ) ;
}
static void T_1 F_13 ( void )
{
F_12 ( & V_13 ) ;
}
static void T_1 F_13 ( void )
{
}
static void F_14 ( struct V_14 * V_15 , int V_16 )
{
if ( V_16 )
F_15 ( V_17 , V_18 ) ;
else
F_15 ( V_17 , V_19 ) ;
}
static T_1 void F_16 ( void )
{
F_17 ( & V_20 ) ;
}
static int F_18 ( struct V_14 * V_15 , unsigned V_21 , unsigned V_22 )
{
F_11 ( V_21 + 6 , V_23 , L_5 ) ;
F_11 ( V_21 + 7 , V_23 , L_6 ) ;
return 0 ;
}
static int T_1 F_19 ( void )
{
#if F_20 ( V_24 ) && F_20 ( V_25 )
int V_1 ;
#endif
if ( ( V_26 >= V_27 && V_26 < 0x100 ) ||
V_26 >= V_28 ) {
V_29 . V_30 = & V_31 ;
V_32 . V_33 -- ;
} else {
V_29 . V_30 = & V_34 ;
}
V_29 . V_35 = & V_32 ;
F_21 ( & V_29 ,
V_36 | V_37 ,
V_38 ) ;
V_29 . V_39 -> V_40 . V_41 = true ;
V_29 . V_39 -> V_40 . V_42 = L_7 ;
F_22 ( 1 , 2200 , L_8 , 7 + V_43 , & V_29 ) ;
#if F_20 ( V_24 ) && F_20 ( V_25 )
V_1 = F_11 ( V_44 , V_45 , L_9 ) ;
if ( V_1 ) {
F_3 ( V_6 L_10 , V_1 ) ;
return V_1 ;
}
V_46 [ 0 ] . V_47 = F_23 ( V_44 ) ;
#endif
F_24 ( 2 , 100 , V_46 ,
F_25 ( V_46 ) ) ;
#if F_26 ( V_48 ) || F_26 ( V_49 )
V_50 . V_4 = F_23 ( V_5 ) ;
V_51 [ 0 ] . V_47 = F_23 ( V_3 ) ;
#endif
F_24 ( 3 , 400 , V_51 ,
F_25 ( V_51 ) ) ;
return 0 ;
}
static void T_1 F_27 ( void )
{
int V_47 , V_52 ;
V_52 = F_28 ( V_53 ,
F_25 ( V_53 ) ) ;
if ( V_52 < 0 )
goto error;
V_47 = F_23 ( V_54 ) ;
if ( V_47 < 0 )
goto V_55;
V_56 . V_57 = V_58 ;
V_59 [ V_60 ] . V_47 = V_47 ;
return;
V_55:
F_4 ( V_54 ) ;
error:
F_3 ( V_6 L_11 ) ;
V_56 . V_57 = - 1 ;
}
static void F_29 ( bool V_61 )
{
F_8 ( V_62 , V_61 ) ;
}
static void T_1 F_30 ( void )
{
int V_63 ;
F_31 ( V_62 , V_64 ) ;
F_31 ( V_65 , V_66 ) ;
V_63 = F_28 ( V_67 ,
F_25 ( V_67 ) ) ;
if ( V_63 < 0 ) {
F_3 ( V_6 L_12 ) ;
V_68 . V_69 = 0 ;
return;
}
V_68 . V_70 = F_29 ;
V_59 [ V_71 ] . V_47 =
F_23 ( V_65 ) ;
}
static void T_1 F_32 ( void )
{
F_12 ( & V_72 ) ;
}
static void T_1 F_32 ( void )
{
}
static void T_1 F_33 ( void )
{
F_12 ( & V_73 ) ;
}
static void T_1 F_34 ( void )
{
if ( F_35 () == V_74 ) {
F_36 ( L_13 ) ;
F_12 ( & V_75 ) ;
}
}
void T_1 F_37 ( void )
{
F_16 () ;
F_19 () ;
F_38 () ;
F_39 ( V_76 ) ;
F_13 () ;
F_27 () ;
F_30 () ;
F_32 () ;
F_40 ( V_59 ,
F_25 ( V_59 ) ) ;
V_17 = F_41 ( L_14 ) ;
if ( V_17 )
F_42 ( V_77 ) ;
F_9 () ;
F_33 () ;
F_34 () ;
}
