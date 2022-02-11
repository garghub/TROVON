static int F_1 ( void )
{
return F_2 ( V_1 , V_2 ,
L_1 ) ;
}
static void F_3 ( void )
{
F_4 ( V_1 ) ;
}
static void F_5 ( bool V_3 )
{
F_6 ( V_1 , ! ! V_3 ) ;
}
static void F_7 ( bool V_4 )
{
F_6 ( V_5 , V_4 ) ;
}
static void T_1 F_8 ( void )
{
F_9 ( F_2 ( V_5 ,
V_6 , L_2 ) ) ;
F_10 ( & V_7 ) ;
}
static void T_1 F_11 ( void )
{
F_10 ( & V_8 ) ;
}
static void T_1 F_11 ( void )
{
}
static void F_12 ( struct V_9 * V_10 , int V_11 , int V_12 )
{
if ( V_12 )
F_13 ( V_13 , V_14 ) ;
else
F_13 ( V_13 , V_15 ) ;
}
static T_1 void F_14 ( void )
{
int V_16 ;
V_16 = F_2 ( V_17 , V_18 , L_3 ) ;
if ( V_16 ) {
F_15 ( V_19 L_4 , V_16 ) ;
return;
}
V_20 . V_21 = F_16 ( V_17 ) ;
F_10 ( & V_22 ) ;
}
static int F_17 ( struct V_9 * V_10 , unsigned V_23 , unsigned V_24 )
{
F_2 ( V_23 + 6 , V_25 , L_5 ) ;
F_2 ( V_23 + 7 , V_25 , L_6 ) ;
return 0 ;
}
static int T_1 F_18 ( void )
{
if ( ( V_26 >= V_27 && V_26 < 0x100 ) ||
V_26 >= V_28 ) {
V_29 . V_30 = & V_31 ;
V_32 . V_33 -- ;
} else {
V_29 . V_30 = & V_34 ;
}
V_29 . V_35 = & V_32 ;
F_19 ( & V_29 ,
V_36 | V_37 ,
V_38 ) ;
V_29 . V_39 -> V_40 . V_41 = true ;
V_29 . V_39 -> V_40 . V_42 = L_7 ;
F_20 ( 1 , 2200 , L_8 , V_43 , & V_29 ) ;
F_21 ( 2 , 100 , V_44 ,
F_22 ( V_44 ) ) ;
F_21 ( 3 , 400 , NULL , 0 ) ;
return 0 ;
}
static void T_1 F_23 ( void )
{
F_24 ( 54 , V_45 ) ;
F_24 ( 86 , V_46 ) ;
F_24 ( 164 , V_46 ) ;
F_25 ( & V_47 ) ;
}
static inline void F_23 ( void )
{
}
static void F_26 ( bool V_48 )
{
F_6 ( V_49 , V_48 ) ;
}
static void T_1 F_27 ( void )
{
int V_21 , V_50 ;
V_50 = F_28 ( V_51 ,
F_22 ( V_51 ) ) ;
if ( V_50 < 0 )
goto error;
V_21 = F_16 ( V_52 ) ;
if ( V_21 < 0 )
goto V_53;
V_54 . V_55 = F_26 ;
V_56 [ V_57 ] . V_21 = V_21 ;
return;
V_53:
F_4 ( V_52 ) ;
F_4 ( V_49 ) ;
error:
F_15 ( V_19 L_9 ) ;
V_54 . V_55 = NULL ;
}
static void F_29 ( bool V_48 )
{
F_6 ( V_58 , V_48 ) ;
}
static void T_1 F_30 ( void )
{
int V_59 ;
F_24 ( V_58 , V_46 ) ;
F_24 ( V_60 , V_61 ) ;
V_59 = F_28 ( V_62 ,
F_22 ( V_62 ) ) ;
if ( V_59 < 0 ) {
F_15 ( V_19 L_10 ) ;
V_63 . V_64 = 0 ;
return;
}
V_63 . V_65 = F_29 ;
V_56 [ V_66 ] . V_21 =
F_16 ( V_60 ) ;
}
void T_1 F_31 ( void )
{
F_18 () ;
F_32 () ;
F_33 ( V_67 ) ;
F_23 () ;
F_11 () ;
F_27 () ;
F_30 () ;
F_14 () ;
F_34 ( V_56 ,
F_22 ( V_56 ) ) ;
V_13 = F_35 ( L_11 ) ;
if ( V_13 )
F_36 ( V_68 ) ;
F_8 () ;
}
