static void F_1 ( struct V_1 * V_1 , T_1 V_2 , unsigned long V_3 )
{
* ( volatile T_1 * ) ( V_1 -> V_4 + V_3 ) = V_2 ;
}
static T_1 F_2 ( struct V_1 * V_1 , unsigned long V_3 )
{
return * ( volatile T_1 * ) ( V_1 -> V_4 + V_3 ) ;
}
static T_2 F_3 ( struct V_1 * V_1 , void * V_5 ,
T_3 V_6 , int V_7 )
{
return F_4 ( V_1 -> V_8 , V_5 , V_6 , V_7 ) ;
}
static int F_5 ( struct V_1 * V_1 , struct V_9 * V_10 ,
int V_11 , int V_7 )
{
return F_6 ( V_1 -> V_8 , V_10 , V_11 , V_7 ) ;
}
static void F_7 ( struct V_1 * V_1 , T_2 V_12 ,
T_3 V_6 , int V_7 )
{
F_8 ( V_1 -> V_8 , V_12 , V_6 , V_7 ) ;
}
static void F_9 ( struct V_1 * V_1 , struct V_9 * V_10 ,
int V_11 , int V_7 )
{
F_10 ( V_1 -> V_8 , V_10 , V_11 , V_7 ) ;
}
static int F_11 ( struct V_1 * V_1 )
{
if ( F_2 ( V_1 , V_13 ) & V_14 )
return 1 ;
return 0 ;
}
static void F_12 ( struct V_1 * V_1 )
{
F_13 ( ( int ) V_1 -> V_15 ) ;
}
static void F_14 ( struct V_1 * V_1 )
{
}
static void F_15 ( struct V_1 * V_1 )
{
F_13 ( ( int ) V_1 -> V_15 ) ;
}
static void F_16 ( struct V_1 * V_1 , T_4 V_12 , T_4 V_16 ,
T_4 V_17 , int V_18 , T_1 V_19 )
{
F_17 ( ! ( V_19 & V_20 ) ) ;
F_1 ( V_1 , ( V_16 >> 0 ) & 0xff , V_21 ) ;
F_1 ( V_1 , ( V_16 >> 8 ) & 0xff , V_22 ) ;
F_13 ( ( int ) V_1 -> V_15 ) ;
if ( V_18 )
F_18 ( ( int ) V_1 -> V_15 , V_23 ) ;
else
F_18 ( ( int ) V_1 -> V_15 , V_24 ) ;
F_19 ( ( int ) V_1 -> V_15 , V_12 ) ;
F_20 ( ( int ) V_1 -> V_15 , V_17 ) ;
F_21 ( ( int ) V_1 -> V_15 ) ;
F_22 ( V_1 , V_19 ) ;
}
static int F_23 ( struct V_1 * V_1 )
{
T_4 V_25 = F_24 ( ( int ) V_1 -> V_15 ) ;
if ( V_25 & ( V_26 | V_27 ) )
return 1 ;
return 0 ;
}
static int F_25 ( struct V_28 * V_8 )
{
struct V_29 * V_30 = & V_31 ;
struct V_32 * V_33 ;
struct V_1 * V_1 ;
struct V_34 * V_35 ;
int V_36 ;
V_33 = F_26 ( V_30 , sizeof( struct V_1 ) ) ;
V_36 = - V_37 ;
if ( ! V_33 )
goto V_38;
V_33 -> V_39 = 8 ;
V_1 = F_27 ( V_33 ) ;
V_1 -> V_33 = V_33 ;
V_1 -> V_8 = V_8 ;
V_1 -> V_40 = & V_41 ;
V_35 = F_28 ( V_8 , V_42 , 0 ) ;
if ( ! V_35 )
goto V_43;
V_1 -> V_4 = ( void V_44 * ) V_35 -> V_45 ;
if ( ! V_1 -> V_4 )
goto V_43;
V_35 = F_28 ( V_8 , V_42 , 1 ) ;
if ( ! V_35 )
goto V_43;
V_1 -> V_15 = ( void V_44 * ) V_35 -> V_45 ;
V_1 -> V_46 = F_29 ( V_1 -> V_8 , 16 ,
& V_1 -> V_47 ,
V_48 ) ;
if ( ! V_1 -> V_46 )
goto V_49;
V_33 -> V_50 = F_30 ( V_8 , 0 ) ;
V_36 = F_31 ( V_33 -> V_50 , V_51 , V_52 , L_1 , V_1 ) ;
if ( V_36 < 0 )
goto V_53;
V_1 -> V_54 = 7 ;
V_1 -> V_33 -> V_55 = V_1 -> V_54 ;
V_1 -> V_56 = ( 1 << V_1 -> V_54 ) ;
V_1 -> V_57 = 40000000 ;
F_32 ( & V_8 -> V_8 , V_1 ) ;
V_36 = F_33 ( V_1 , & V_8 -> V_8 ) ;
if ( V_36 )
goto V_58;
return 0 ;
V_58:
F_34 ( V_33 -> V_50 , V_1 ) ;
V_53:
F_35 ( V_1 -> V_8 , 16 ,
V_1 -> V_46 ,
V_1 -> V_47 ) ;
V_49:
V_43:
F_36 ( V_33 ) ;
V_38:
return V_36 ;
}
static int F_37 ( struct V_28 * V_8 )
{
struct V_1 * V_1 = F_38 ( & V_8 -> V_8 ) ;
unsigned int V_50 = V_1 -> V_33 -> V_50 ;
F_39 ( V_1 ) ;
F_34 ( V_50 , V_1 ) ;
F_35 ( V_1 -> V_8 , 16 ,
V_1 -> V_46 ,
V_1 -> V_47 ) ;
F_36 ( V_1 -> V_33 ) ;
return 0 ;
}
static int T_5 F_40 ( void )
{
return F_41 ( & V_59 ) ;
}
static void T_6 F_42 ( void )
{
F_43 ( & V_59 ) ;
}
