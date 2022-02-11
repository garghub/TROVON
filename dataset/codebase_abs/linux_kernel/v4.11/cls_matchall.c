static int F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_7 * V_8 = F_2 ( V_4 -> V_9 ) ;
if ( F_3 ( V_8 -> V_10 ) )
return - 1 ;
return F_4 ( V_2 , & V_8 -> V_11 , V_6 ) ;
}
static int F_5 ( struct V_3 * V_4 )
{
return 0 ;
}
static void F_6 ( struct V_12 * V_13 )
{
struct V_7 * V_8 = F_7 ( V_13 , struct V_7 ,
V_13 ) ;
F_8 ( & V_8 -> V_11 ) ;
F_9 ( V_8 ) ;
}
static int F_10 ( struct V_3 * V_4 ,
struct V_7 * V_8 ,
unsigned long V_14 )
{
struct V_15 * V_16 = V_4 -> V_17 -> V_18 -> V_16 ;
struct V_19 V_20 ;
struct V_21 V_22 = { 0 } ;
int V_23 ;
V_20 . type = V_24 ;
V_20 . V_25 = & V_22 ;
V_20 . V_25 -> V_26 = V_27 ;
V_20 . V_25 -> V_11 = & V_8 -> V_11 ;
V_20 . V_25 -> V_14 = V_14 ;
V_23 = V_16 -> V_28 -> V_29 ( V_16 , V_4 -> V_17 -> V_30 , V_4 -> V_31 ,
& V_20 ) ;
if ( ! V_23 )
V_8 -> V_10 |= V_32 ;
return V_23 ;
}
static void F_11 ( struct V_3 * V_4 ,
struct V_7 * V_8 ,
unsigned long V_14 )
{
struct V_15 * V_16 = V_4 -> V_17 -> V_18 -> V_16 ;
struct V_19 V_20 ;
struct V_21 V_22 = { 0 } ;
V_20 . type = V_24 ;
V_20 . V_25 = & V_22 ;
V_20 . V_25 -> V_26 = V_33 ;
V_20 . V_25 -> V_11 = NULL ;
V_20 . V_25 -> V_14 = V_14 ;
V_16 -> V_28 -> V_29 ( V_16 , V_4 -> V_17 -> V_30 , V_4 -> V_31 ,
& V_20 ) ;
}
static bool F_12 ( struct V_3 * V_4 , bool V_34 )
{
struct V_7 * V_8 = F_13 ( V_4 -> V_9 ) ;
struct V_15 * V_16 = V_4 -> V_17 -> V_18 -> V_16 ;
if ( ! V_8 )
return true ;
if ( F_14 ( V_16 , V_4 , V_8 -> V_10 ) )
F_11 ( V_4 , V_8 , ( unsigned long ) V_8 ) ;
F_15 ( & V_8 -> V_13 , F_6 ) ;
return true ;
}
static unsigned long F_16 ( struct V_3 * V_4 , T_1 V_30 )
{
return 0UL ;
}
static int F_17 ( struct V_35 * V_35 , struct V_3 * V_4 ,
struct V_7 * V_8 ,
unsigned long V_36 , struct V_37 * * V_38 ,
struct V_37 * V_39 , bool V_40 )
{
struct V_41 V_42 ;
int V_23 ;
V_23 = F_18 ( & V_42 , V_43 , 0 ) ;
if ( V_23 )
return V_23 ;
V_23 = F_19 ( V_35 , V_4 , V_38 , V_39 , & V_42 , V_40 ) ;
if ( V_23 < 0 )
goto V_44;
if ( V_38 [ V_45 ] ) {
V_8 -> V_6 . V_46 = F_20 ( V_38 [ V_45 ] ) ;
F_21 ( V_4 , & V_8 -> V_6 , V_36 ) ;
}
F_22 ( V_4 , & V_8 -> V_11 , & V_42 ) ;
return 0 ;
V_44:
F_8 ( & V_42 ) ;
return V_23 ;
}
static int F_23 ( struct V_35 * V_35 , struct V_1 * V_47 ,
struct V_3 * V_4 , unsigned long V_36 ,
T_1 V_30 , struct V_37 * * V_48 ,
unsigned long * V_49 , bool V_40 )
{
struct V_7 * V_8 = F_13 ( V_4 -> V_9 ) ;
struct V_15 * V_16 = V_4 -> V_17 -> V_18 -> V_16 ;
struct V_37 * V_38 [ V_50 + 1 ] ;
struct V_7 * V_51 ;
T_1 V_10 = 0 ;
int V_23 ;
if ( ! V_48 [ V_52 ] )
return - V_53 ;
if ( V_8 )
return - V_54 ;
V_23 = F_24 ( V_38 , V_50 ,
V_48 [ V_52 ] , V_55 ) ;
if ( V_23 < 0 )
return V_23 ;
if ( V_38 [ V_56 ] ) {
V_10 = F_20 ( V_38 [ V_56 ] ) ;
if ( ! F_25 ( V_10 ) )
return - V_53 ;
}
V_51 = F_26 ( sizeof( * V_51 ) , V_57 ) ;
if ( ! V_51 )
return - V_58 ;
V_23 = F_18 ( & V_51 -> V_11 , V_43 , 0 ) ;
if ( V_23 )
goto V_59;
if ( ! V_30 )
V_30 = 1 ;
V_51 -> V_30 = V_30 ;
V_51 -> V_10 = V_10 ;
V_23 = F_17 ( V_35 , V_4 , V_51 , V_36 , V_38 , V_48 [ V_60 ] , V_40 ) ;
if ( V_23 )
goto V_61;
if ( F_14 ( V_16 , V_4 , V_10 ) ) {
V_23 = F_10 ( V_4 , V_51 , ( unsigned long ) V_51 ) ;
if ( V_23 ) {
if ( F_3 ( V_10 ) )
goto V_62;
else
V_23 = 0 ;
}
}
if ( ! F_27 ( V_51 -> V_10 ) )
V_51 -> V_10 |= V_63 ;
* V_49 = ( unsigned long ) V_8 ;
F_28 ( V_4 -> V_9 , V_51 ) ;
if ( V_8 )
F_15 ( & V_8 -> V_13 , F_6 ) ;
return 0 ;
V_62:
V_61:
F_8 ( & V_51 -> V_11 ) ;
V_59:
F_9 ( V_51 ) ;
return V_23 ;
}
static int F_29 ( struct V_3 * V_4 , unsigned long V_49 )
{
return - V_64 ;
}
static void F_30 ( struct V_3 * V_4 , struct V_65 * V_49 )
{
struct V_7 * V_8 = F_13 ( V_4 -> V_9 ) ;
if ( V_49 -> V_66 < V_49 -> V_67 )
goto V_67;
if ( V_49 -> V_68 ( V_4 , ( unsigned long ) V_8 , V_49 ) < 0 )
V_49 -> V_69 = 1 ;
V_67:
V_49 -> V_66 ++ ;
}
static int F_31 ( struct V_35 * V_35 , struct V_3 * V_4 , unsigned long V_70 ,
struct V_1 * V_2 , struct V_71 * V_72 )
{
struct V_7 * V_8 = (struct V_7 * ) V_70 ;
struct V_37 * V_73 ;
if ( ! V_8 )
return V_2 -> V_74 ;
V_72 -> V_75 = V_8 -> V_30 ;
V_73 = F_32 ( V_2 , V_52 ) ;
if ( ! V_73 )
goto V_76;
if ( V_8 -> V_6 . V_46 &&
F_33 ( V_2 , V_45 , V_8 -> V_6 . V_46 ) )
goto V_76;
if ( V_8 -> V_10 && F_33 ( V_2 , V_56 , V_8 -> V_10 ) )
goto V_76;
if ( F_34 ( V_2 , & V_8 -> V_11 ) )
goto V_76;
F_35 ( V_2 , V_73 ) ;
if ( F_36 ( V_2 , & V_8 -> V_11 ) < 0 )
goto V_76;
return V_2 -> V_74 ;
V_76:
F_37 ( V_2 , V_73 ) ;
return - 1 ;
}
static int T_2 F_38 ( void )
{
return F_39 ( & V_77 ) ;
}
static void T_3 F_40 ( void )
{
F_41 ( & V_77 ) ;
}
