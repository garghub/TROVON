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
static void F_14 ( struct V_14 * V_15 , int V_16 , int V_17 )
{
if ( V_17 )
F_15 ( V_18 , V_19 ) ;
else
F_15 ( V_18 , V_20 ) ;
}
static T_1 void F_16 ( void )
{
int V_1 ;
V_1 = F_11 ( V_21 , V_22 , L_5 ) ;
if ( V_1 ) {
F_3 ( V_6 L_6 , V_1 ) ;
return;
}
V_23 . V_24 = F_17 ( V_21 ) ;
F_12 ( & V_25 ) ;
}
static int F_18 ( struct V_14 * V_15 , unsigned V_26 , unsigned V_27 )
{
F_11 ( V_26 + 6 , V_28 , L_7 ) ;
F_11 ( V_26 + 7 , V_28 , L_8 ) ;
return 0 ;
}
static int T_1 F_19 ( void )
{
if ( ( V_29 >= V_30 && V_29 < 0x100 ) ||
V_29 >= V_31 ) {
V_32 . V_33 = & V_34 ;
V_35 . V_36 -- ;
} else {
V_32 . V_33 = & V_37 ;
}
V_32 . V_38 = & V_35 ;
F_20 ( & V_32 ,
V_39 | V_40 ,
V_41 ) ;
V_32 . V_42 -> V_43 . V_44 = true ;
V_32 . V_42 -> V_43 . V_45 = L_9 ;
F_21 ( 1 , 2200 , L_10 , 7 + V_46 , & V_32 ) ;
F_22 ( 2 , 100 , V_47 ,
F_23 ( V_47 ) ) ;
#if F_24 ( V_48 ) || F_24 ( V_49 )
V_50 . V_4 = F_17 ( V_5 ) ;
V_51 [ 0 ] . V_24 = F_17 ( V_3 ) ;
#endif
F_22 ( 3 , 400 , V_51 ,
F_23 ( V_51 ) ) ;
return 0 ;
}
static void T_1 F_25 ( void )
{
F_26 ( 54 , V_52 ) ;
F_26 ( 86 , V_53 ) ;
F_26 ( 164 , V_53 ) ;
F_27 ( & V_54 ) ;
}
static inline void F_25 ( void )
{
}
static void F_28 ( bool V_55 )
{
F_8 ( V_56 , V_55 ) ;
}
static void T_1 F_29 ( void )
{
int V_24 , V_57 ;
V_57 = F_30 ( V_58 ,
F_23 ( V_58 ) ) ;
if ( V_57 < 0 )
goto error;
V_24 = F_17 ( V_59 ) ;
if ( V_24 < 0 )
goto V_60;
V_61 . V_62 = F_28 ;
V_63 [ V_64 ] . V_24 = V_24 ;
return;
V_60:
F_4 ( V_59 ) ;
F_4 ( V_56 ) ;
error:
F_3 ( V_6 L_11 ) ;
V_61 . V_62 = NULL ;
}
static void F_31 ( bool V_55 )
{
F_8 ( V_65 , V_55 ) ;
}
static void T_1 F_32 ( void )
{
int V_66 ;
F_26 ( V_65 , V_53 ) ;
F_26 ( V_67 , V_68 ) ;
V_66 = F_30 ( V_69 ,
F_23 ( V_69 ) ) ;
if ( V_66 < 0 ) {
F_3 ( V_6 L_12 ) ;
V_70 . V_71 = 0 ;
return;
}
V_70 . V_72 = F_31 ;
V_63 [ V_73 ] . V_24 =
F_17 ( V_67 ) ;
}
static void T_1 F_33 ( void )
{
F_12 ( & V_74 ) ;
}
static void T_1 F_33 ( void )
{
}
static void T_1 F_34 ( void )
{
F_12 ( & V_75 ) ;
}
static void T_1 F_35 ( void )
{
if ( F_36 () == V_76 ) {
F_37 ( L_13 ) ;
F_12 ( & V_77 ) ;
}
}
void T_1 F_38 ( void )
{
F_19 () ;
F_39 () ;
F_40 ( V_78 ) ;
F_25 () ;
F_13 () ;
F_29 () ;
F_32 () ;
F_16 () ;
F_33 () ;
F_41 ( V_63 ,
F_23 ( V_63 ) ) ;
V_18 = F_42 ( L_14 ) ;
if ( V_18 )
F_43 ( V_79 ) ;
F_9 () ;
F_34 () ;
F_35 () ;
}
