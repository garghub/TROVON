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
V_23 = V_16 -> V_28 -> V_29 ( V_16 , V_4 -> V_17 -> V_30 ,
V_4 -> V_31 -> V_32 ,
V_4 -> V_33 , & V_20 ) ;
if ( ! V_23 )
V_8 -> V_10 |= V_34 ;
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
V_20 . V_25 -> V_26 = V_35 ;
V_20 . V_25 -> V_11 = NULL ;
V_20 . V_25 -> V_14 = V_14 ;
V_16 -> V_28 -> V_29 ( V_16 , V_4 -> V_17 -> V_30 , V_4 -> V_31 -> V_32 ,
V_4 -> V_33 , & V_20 ) ;
}
static void F_12 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = F_13 ( V_4 -> V_9 ) ;
struct V_15 * V_16 = V_4 -> V_17 -> V_18 -> V_16 ;
if ( ! V_8 )
return;
if ( F_14 ( V_16 , V_4 , V_8 -> V_10 ) )
F_11 ( V_4 , V_8 , ( unsigned long ) V_8 ) ;
F_15 ( & V_8 -> V_13 , F_6 ) ;
}
static unsigned long F_16 ( struct V_3 * V_4 , T_1 V_30 )
{
return 0UL ;
}
static int F_17 ( struct V_36 * V_36 , struct V_3 * V_4 ,
struct V_7 * V_8 ,
unsigned long V_37 , struct V_38 * * V_39 ,
struct V_38 * V_40 , bool V_41 )
{
struct V_42 V_43 ;
int V_23 ;
V_23 = F_18 ( & V_43 , V_44 , 0 ) ;
if ( V_23 )
return V_23 ;
V_23 = F_19 ( V_36 , V_4 , V_39 , V_40 , & V_43 , V_41 ) ;
if ( V_23 < 0 )
goto V_45;
if ( V_39 [ V_46 ] ) {
V_8 -> V_6 . V_47 = F_20 ( V_39 [ V_46 ] ) ;
F_21 ( V_4 , & V_8 -> V_6 , V_37 ) ;
}
F_22 ( V_4 , & V_8 -> V_11 , & V_43 ) ;
return 0 ;
V_45:
F_8 ( & V_43 ) ;
return V_23 ;
}
static int F_23 ( struct V_36 * V_36 , struct V_1 * V_48 ,
struct V_3 * V_4 , unsigned long V_37 ,
T_1 V_30 , struct V_38 * * V_49 ,
unsigned long * V_50 , bool V_41 )
{
struct V_7 * V_8 = F_13 ( V_4 -> V_9 ) ;
struct V_15 * V_16 = V_4 -> V_17 -> V_18 -> V_16 ;
struct V_38 * V_39 [ V_51 + 1 ] ;
struct V_7 * V_52 ;
T_1 V_10 = 0 ;
int V_23 ;
if ( ! V_49 [ V_53 ] )
return - V_54 ;
if ( V_8 )
return - V_55 ;
V_23 = F_24 ( V_39 , V_51 , V_49 [ V_53 ] ,
V_56 , NULL ) ;
if ( V_23 < 0 )
return V_23 ;
if ( V_39 [ V_57 ] ) {
V_10 = F_20 ( V_39 [ V_57 ] ) ;
if ( ! F_25 ( V_10 ) )
return - V_54 ;
}
V_52 = F_26 ( sizeof( * V_52 ) , V_58 ) ;
if ( ! V_52 )
return - V_59 ;
V_23 = F_18 ( & V_52 -> V_11 , V_44 , 0 ) ;
if ( V_23 )
goto V_60;
if ( ! V_30 )
V_30 = 1 ;
V_52 -> V_30 = V_30 ;
V_52 -> V_10 = V_10 ;
V_23 = F_17 ( V_36 , V_4 , V_52 , V_37 , V_39 , V_49 [ V_61 ] , V_41 ) ;
if ( V_23 )
goto V_62;
if ( F_14 ( V_16 , V_4 , V_10 ) ) {
V_23 = F_10 ( V_4 , V_52 , ( unsigned long ) V_52 ) ;
if ( V_23 ) {
if ( F_3 ( V_10 ) )
goto V_63;
else
V_23 = 0 ;
}
}
if ( ! F_27 ( V_52 -> V_10 ) )
V_52 -> V_10 |= V_64 ;
* V_50 = ( unsigned long ) V_8 ;
F_28 ( V_4 -> V_9 , V_52 ) ;
return 0 ;
V_63:
V_62:
F_8 ( & V_52 -> V_11 ) ;
V_60:
F_9 ( V_52 ) ;
return V_23 ;
}
static int F_29 ( struct V_3 * V_4 , unsigned long V_50 , bool * V_65 )
{
return - V_66 ;
}
static void F_30 ( struct V_3 * V_4 , struct V_67 * V_50 )
{
struct V_7 * V_8 = F_13 ( V_4 -> V_9 ) ;
if ( V_50 -> V_68 < V_50 -> V_69 )
goto V_69;
if ( V_50 -> V_70 ( V_4 , ( unsigned long ) V_8 , V_50 ) < 0 )
V_50 -> V_71 = 1 ;
V_69:
V_50 -> V_68 ++ ;
}
static int F_31 ( struct V_36 * V_36 , struct V_3 * V_4 , unsigned long V_72 ,
struct V_1 * V_2 , struct V_73 * V_74 )
{
struct V_7 * V_8 = (struct V_7 * ) V_72 ;
struct V_38 * V_75 ;
if ( ! V_8 )
return V_2 -> V_76 ;
V_74 -> V_77 = V_8 -> V_30 ;
V_75 = F_32 ( V_2 , V_53 ) ;
if ( ! V_75 )
goto V_78;
if ( V_8 -> V_6 . V_47 &&
F_33 ( V_2 , V_46 , V_8 -> V_6 . V_47 ) )
goto V_78;
if ( V_8 -> V_10 && F_33 ( V_2 , V_57 , V_8 -> V_10 ) )
goto V_78;
if ( F_34 ( V_2 , & V_8 -> V_11 ) )
goto V_78;
F_35 ( V_2 , V_75 ) ;
if ( F_36 ( V_2 , & V_8 -> V_11 ) < 0 )
goto V_78;
return V_2 -> V_76 ;
V_78:
F_37 ( V_2 , V_75 ) ;
return - 1 ;
}
static int T_2 F_38 ( void )
{
return F_39 ( & V_79 ) ;
}
static void T_3 F_40 ( void )
{
F_41 ( & V_79 ) ;
}
