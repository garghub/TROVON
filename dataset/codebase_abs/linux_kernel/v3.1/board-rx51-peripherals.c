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
F_2 ( V_23 + 6 , V_6 , L_5 ) ;
F_2 ( V_23 + 7 , V_6 , L_6 ) ;
return 0 ;
}
static int T_1 F_18 ( void )
{
if ( ( V_25 >= V_26 && V_25 < 0x100 ) ||
V_25 >= V_27 ) {
V_28 . V_29 = & V_30 ;
V_31 . V_32 -- ;
} else {
V_28 . V_29 = & V_33 ;
}
V_28 . V_34 = & V_31 ;
F_19 ( & V_28 ,
V_35 | V_36 ,
V_37 ) ;
V_28 . V_38 -> V_39 . V_40 = true ;
V_28 . V_38 -> V_39 . V_41 = L_7 ;
F_20 ( 1 , 2200 , L_8 , V_42 , & V_28 ) ;
F_21 ( 2 , 100 , V_43 ,
F_22 ( V_43 ) ) ;
F_21 ( 3 , 400 , NULL , 0 ) ;
return 0 ;
}
static void T_1 F_23 ( void )
{
F_24 ( 54 , V_44 ) ;
F_24 ( 86 , V_45 ) ;
F_24 ( 164 , V_45 ) ;
F_25 ( & V_46 ) ;
}
static inline void F_23 ( void )
{
}
static void F_26 ( bool V_47 )
{
F_6 ( V_48 , V_47 ) ;
}
static void T_1 F_27 ( void )
{
int V_21 , V_49 ;
V_49 = F_28 ( V_50 ,
F_22 ( V_50 ) ) ;
if ( V_49 < 0 )
goto error;
V_21 = F_16 ( V_51 ) ;
if ( V_21 < 0 )
goto V_52;
V_53 . V_54 = F_26 ;
V_55 [ V_56 ] . V_21 = V_21 ;
return;
V_52:
F_4 ( V_51 ) ;
F_4 ( V_48 ) ;
error:
F_15 ( V_19 L_9 ) ;
V_53 . V_54 = NULL ;
}
void T_1 F_29 ( void )
{
F_18 () ;
F_30 () ;
F_31 ( V_57 ) ;
F_23 () ;
F_11 () ;
F_27 () ;
F_14 () ;
F_32 ( V_55 ,
F_22 ( V_55 ) ) ;
V_13 = F_33 ( L_10 ) ;
if ( V_13 )
F_34 ( V_58 ) ;
F_8 () ;
}
