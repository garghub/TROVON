static int F_1 ( struct V_1 * V_2 )
{
T_1 * V_3 = V_4 -> V_5 ;
T_2 V_6 ;
unsigned long V_7 ;
struct V_8 * V_8 ;
V_6 = V_2 -> V_9 - V_2 -> V_10 -> V_11 + V_3 -> V_12 . V_13 ;
V_7 = V_3 -> V_14 -> V_15 ( V_3 , V_6 ) ;
if ( V_7 == ( unsigned long ) - V_16 )
return V_17 ;
V_8 = F_2 ( F_3 ( V_7 ) ) ;
F_4 ( V_8 ) ;
V_2 -> V_8 = V_8 ;
return 0 ;
}
static int F_5 ( void )
{
return V_18 [ 0 ] . V_19 ;
}
static int F_6 ( void )
{
T_1 * V_3 = V_4 -> V_5 ;
V_4 -> V_20 = V_3 -> V_12 . V_13 ;
return 0 ;
}
static void F_7 ( void )
{
T_1 * V_3 = V_4 -> V_5 ;
V_3 -> V_14 -> V_21 ( V_3 ) ;
}
static void F_8 ( struct V_22 * V_23 )
{
T_1 * V_3 = V_4 -> V_5 ;
V_24 . V_25 ( V_3 -> V_26 , 0 , - 1 ) ;
}
static void F_9 ( struct V_27 * V_28 , T_3 V_29 )
{
T_1 * V_3 = V_28 -> V_5 ;
V_3 -> V_29 . V_30 = F_10 ( V_28 , V_29 ,
V_3 -> V_31 . V_30 ) ;
V_3 -> V_29 . V_32 . V_33 = 1 ;
V_3 -> V_14 -> V_34 ( V_3 ) ;
F_11 ( V_3 -> V_29 . V_30 , false ) ;
}
static int F_12 ( struct V_22 * V_23 , T_4 V_35 ,
int type )
{
T_1 * V_3 = V_4 -> V_5 ;
int V_36 , V_37 ;
void * V_38 ;
if ( type >= V_39 || V_23 -> type >= V_39 )
return - V_16 ;
V_38 = V_4 -> V_40 ;
V_36 = F_13 ( V_38 ) -> V_36 ;
if ( ( V_35 + V_23 -> V_41 ) > V_36 )
return - V_16 ;
V_37 = V_3 -> V_14 -> V_42 ( V_3 , V_35 , V_23 ) ;
F_14 () ;
F_8 ( V_23 ) ;
return V_37 ;
}
static int F_15 ( struct V_22 * V_23 , T_4 V_35 ,
int type )
{
T_1 * V_3 = V_4 -> V_5 ;
int V_37 ;
V_37 = V_3 -> V_14 -> V_43 ( V_3 , V_35 , V_23 ) ;
F_8 ( V_23 ) ;
return V_37 ;
}
static int F_16 ( struct V_27 * V_44 )
{
return 0 ;
}
int T_5
F_17 ( void )
{
T_1 * V_3 = V_24 . V_45 () ;
struct V_46 * V_47 ;
struct V_48 * V_49 ;
if ( ! V_3 )
return - V_50 ;
if ( V_3 -> V_14 -> V_51 ( V_3 ) )
return - V_50 ;
V_49 = V_18 ;
V_49 -> V_19 = V_3 -> V_12 . V_19 / ( 1024 * 1024 ) ;
V_49 -> V_36 = V_3 -> V_12 . V_19 / V_52 ;
V_49 -> V_53 = F_18 ( V_49 -> V_36 / 1024 ) ;
V_47 = F_19 ( NULL ) ;
if ( ! V_47 )
return - V_54 ;
V_47 -> V_55 = 0xffff ;
V_47 -> V_56 = 0xffff ;
V_47 -> V_57 = V_3 -> V_26 ;
V_58 = F_20 () ;
if ( ! V_58 )
goto V_59;
V_58 -> V_60 = & V_61 ;
V_58 -> V_62 = & V_63 ;
V_58 -> V_40 = V_49 ;
V_58 -> V_5 = V_3 ;
V_58 -> V_64 = V_47 ;
V_58 -> V_29 = V_3 -> V_31 . V_30 ;
F_21 (KERN_INFO PFX L_1 , agp->hose->index) ;
return F_22 ( V_58 ) ;
V_59:
F_23 ( V_47 ) ;
return - V_54 ;
}
static int T_5 F_24 ( void )
{
if ( V_65 )
return - V_16 ;
if ( V_24 . V_45 )
return F_17 () ;
return - V_50 ;
}
static void T_6 F_25 ( void )
{
F_26 ( V_58 ) ;
F_27 ( V_58 ) ;
}
