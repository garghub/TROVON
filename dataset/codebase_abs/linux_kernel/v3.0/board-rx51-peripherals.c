static void F_1 ( bool V_1 )
{
F_2 ( V_2 , V_1 ) ;
}
static void T_1 F_3 ( void )
{
F_4 ( F_5 ( V_2 ,
V_3 , L_1 ) ) ;
F_6 ( & V_4 ) ;
}
static void T_1 F_7 ( void )
{
F_6 ( & V_5 ) ;
}
static void T_1 F_7 ( void )
{
}
static void F_8 ( struct V_6 * V_7 , int V_8 , int V_9 )
{
if ( V_9 )
F_9 ( V_10 , V_11 ) ;
else
F_9 ( V_10 , V_12 ) ;
}
static T_1 void F_10 ( void )
{
int V_13 ;
V_13 = F_5 ( V_14 , V_15 , L_2 ) ;
if ( V_13 ) {
F_11 ( V_16 L_3 , V_13 ) ;
return;
}
V_17 . V_18 = F_12 ( V_14 ) ;
F_6 ( & V_19 ) ;
}
static int F_13 ( struct V_6 * V_7 , unsigned V_20 , unsigned V_21 )
{
F_5 ( V_20 + 6 , V_3 , L_4 ) ;
F_5 ( V_20 + 7 , V_3 , L_5 ) ;
return 0 ;
}
static int T_1 F_14 ( void )
{
if ( ( V_22 >= V_23 && V_22 < 0x100 ) ||
V_22 >= V_24 ) {
V_25 . V_26 = & V_27 ;
V_28 . V_29 -- ;
} else {
V_25 . V_26 = & V_30 ;
}
V_25 . V_31 = & V_28 ;
F_15 ( 1 , 2200 , L_6 , V_32 , & V_25 ) ;
F_16 ( 2 , 100 , V_33 ,
F_17 ( V_33 ) ) ;
F_16 ( 3 , 400 , NULL , 0 ) ;
return 0 ;
}
static void T_1 F_18 ( void )
{
F_19 ( 54 , V_34 ) ;
F_19 ( 86 , V_35 ) ;
F_19 ( 164 , V_35 ) ;
F_20 ( & V_36 ) ;
}
static inline void F_18 ( void )
{
}
static void F_21 ( bool V_37 )
{
F_2 ( V_38 , V_37 ) ;
}
static void T_1 F_22 ( void )
{
int V_18 , V_39 ;
V_39 = F_23 ( V_40 ,
F_17 ( V_40 ) ) ;
if ( V_39 < 0 )
goto error;
V_18 = F_12 ( V_41 ) ;
if ( V_18 < 0 )
goto V_42;
V_43 . V_44 = F_21 ;
V_45 [ V_46 ] . V_18 = V_18 ;
return;
V_42:
F_24 ( V_41 ) ;
F_24 ( V_38 ) ;
error:
F_11 ( V_16 L_7 ) ;
V_43 . V_44 = NULL ;
}
void T_1 F_25 ( void )
{
F_14 () ;
F_26 ( V_47 ) ;
F_18 () ;
F_7 () ;
F_22 () ;
F_10 () ;
F_27 ( V_45 ,
F_17 ( V_45 ) ) ;
V_10 = F_28 ( L_8 ) ;
if ( V_10 )
F_29 ( V_48 ) ;
F_3 () ;
}
