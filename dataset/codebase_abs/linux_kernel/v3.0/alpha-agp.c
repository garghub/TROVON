static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
T_1 * V_5 = V_6 -> V_7 ;
T_2 V_8 ;
unsigned long V_9 ;
struct V_10 * V_10 ;
V_8 = ( unsigned long ) V_4 -> V_11 - V_2 -> V_12
+ V_5 -> V_13 . V_14 ;
V_9 = V_5 -> V_15 -> V_16 ( V_5 , V_8 ) ;
if ( V_9 == ( unsigned long ) - V_17 )
return V_18 ;
V_10 = F_2 ( F_3 ( V_9 ) ) ;
F_4 ( V_10 ) ;
V_4 -> V_10 = V_10 ;
return 0 ;
}
static int F_5 ( void )
{
return V_19 [ 0 ] . V_20 ;
}
static int F_6 ( void )
{
T_1 * V_5 = V_6 -> V_7 ;
V_6 -> V_21 = V_5 -> V_13 . V_14 ;
return 0 ;
}
static void F_7 ( void )
{
T_1 * V_5 = V_6 -> V_7 ;
V_5 -> V_15 -> V_22 ( V_5 ) ;
}
static void F_8 ( struct V_23 * V_24 )
{
T_1 * V_5 = V_6 -> V_7 ;
V_25 . V_26 ( V_5 -> V_27 , 0 , - 1 ) ;
}
static void F_9 ( struct V_28 * V_29 , T_3 V_30 )
{
T_1 * V_5 = V_29 -> V_7 ;
V_5 -> V_30 . V_31 = F_10 ( V_29 , V_30 ,
V_5 -> V_32 . V_31 ) ;
V_5 -> V_30 . V_33 . V_34 = 1 ;
V_5 -> V_15 -> V_35 ( V_5 ) ;
F_11 ( V_5 -> V_30 . V_31 , false ) ;
}
static int F_12 ( struct V_23 * V_24 , T_4 V_36 ,
int type )
{
T_1 * V_5 = V_6 -> V_7 ;
int V_37 , V_38 ;
void * V_39 ;
if ( type >= V_40 || V_24 -> type >= V_40 )
return - V_17 ;
V_39 = V_6 -> V_41 ;
V_37 = F_13 ( V_39 ) -> V_37 ;
if ( ( V_36 + V_24 -> V_42 ) > V_37 )
return - V_17 ;
V_38 = V_5 -> V_15 -> V_43 ( V_5 , V_36 , V_24 ) ;
F_14 () ;
F_8 ( V_24 ) ;
return V_38 ;
}
static int F_15 ( struct V_23 * V_24 , T_4 V_36 ,
int type )
{
T_1 * V_5 = V_6 -> V_7 ;
int V_38 ;
V_38 = V_5 -> V_15 -> V_44 ( V_5 , V_36 , V_24 ) ;
F_8 ( V_24 ) ;
return V_38 ;
}
static int F_16 ( struct V_28 * V_45 )
{
return 0 ;
}
int T_5
F_17 ( void )
{
T_1 * V_5 = V_25 . V_46 () ;
struct V_47 * V_48 ;
struct V_49 * V_50 ;
if ( ! V_5 )
return - V_51 ;
if ( V_5 -> V_15 -> V_52 ( V_5 ) )
return - V_51 ;
V_50 = V_19 ;
V_50 -> V_20 = V_5 -> V_13 . V_20 / ( 1024 * 1024 ) ;
V_50 -> V_37 = V_5 -> V_13 . V_20 / V_53 ;
V_50 -> V_54 = F_18 ( V_50 -> V_37 / 1024 ) ;
V_48 = F_19 () ;
if ( ! V_48 )
return - V_55 ;
V_48 -> V_56 = 0xffff ;
V_48 -> V_57 = 0xffff ;
V_48 -> V_58 = V_5 -> V_27 ;
V_59 = F_20 () ;
if ( ! V_59 )
goto V_60;
V_59 -> V_61 = & V_62 ;
V_59 -> V_63 = & V_64 ;
V_59 -> V_41 = V_50 ;
V_59 -> V_7 = V_5 ;
V_59 -> V_65 = V_48 ;
V_59 -> V_30 = V_5 -> V_32 . V_31 ;
F_21 (KERN_INFO PFX L_1 , agp->hose->index) ;
return F_22 ( V_59 ) ;
V_60:
F_23 ( V_48 ) ;
return - V_55 ;
}
static int T_5 F_24 ( void )
{
if ( V_66 )
return - V_17 ;
if ( V_25 . V_46 )
return F_17 () ;
return - V_51 ;
}
static void T_6 F_25 ( void )
{
F_26 ( V_59 ) ;
F_27 ( V_59 ) ;
}
