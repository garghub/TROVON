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
V_20 . type = V_23 ;
V_20 . V_24 = & V_22 ;
V_20 . V_24 -> V_25 = V_26 ;
V_20 . V_24 -> V_11 = & V_8 -> V_11 ;
V_20 . V_24 -> V_14 = V_14 ;
return V_16 -> V_27 -> V_28 ( V_16 , V_4 -> V_17 -> V_29 , V_4 -> V_30 ,
& V_20 ) ;
}
static void F_11 ( struct V_3 * V_4 ,
struct V_7 * V_8 ,
unsigned long V_14 )
{
struct V_15 * V_16 = V_4 -> V_17 -> V_18 -> V_16 ;
struct V_19 V_20 ;
struct V_21 V_22 = { 0 } ;
V_20 . type = V_23 ;
V_20 . V_24 = & V_22 ;
V_20 . V_24 -> V_25 = V_31 ;
V_20 . V_24 -> V_11 = NULL ;
V_20 . V_24 -> V_14 = V_14 ;
V_16 -> V_27 -> V_28 ( V_16 , V_4 -> V_17 -> V_29 , V_4 -> V_30 ,
& V_20 ) ;
}
static bool F_12 ( struct V_3 * V_4 , bool V_32 )
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
static unsigned long F_16 ( struct V_3 * V_4 , T_1 V_29 )
{
return 0UL ;
}
static int F_17 ( struct V_33 * V_33 , struct V_3 * V_4 ,
struct V_7 * V_8 ,
unsigned long V_34 , struct V_35 * * V_36 ,
struct V_35 * V_37 , bool V_38 )
{
struct V_39 V_40 ;
int V_41 ;
F_18 ( & V_40 , V_42 , 0 ) ;
V_41 = F_19 ( V_33 , V_4 , V_36 , V_37 , & V_40 , V_38 ) ;
if ( V_41 < 0 )
return V_41 ;
if ( V_36 [ V_43 ] ) {
V_8 -> V_6 . V_44 = F_20 ( V_36 [ V_43 ] ) ;
F_21 ( V_4 , & V_8 -> V_6 , V_34 ) ;
}
F_22 ( V_4 , & V_8 -> V_11 , & V_40 ) ;
return 0 ;
}
static int F_23 ( struct V_33 * V_33 , struct V_1 * V_45 ,
struct V_3 * V_4 , unsigned long V_34 ,
T_1 V_29 , struct V_35 * * V_46 ,
unsigned long * V_47 , bool V_38 )
{
struct V_7 * V_8 = F_13 ( V_4 -> V_9 ) ;
struct V_15 * V_16 = V_4 -> V_17 -> V_18 -> V_16 ;
struct V_35 * V_36 [ V_48 + 1 ] ;
struct V_7 * V_49 ;
T_1 V_10 = 0 ;
int V_41 ;
if ( ! V_46 [ V_50 ] )
return - V_51 ;
if ( V_8 )
return - V_52 ;
V_41 = F_24 ( V_36 , V_48 ,
V_46 [ V_50 ] , V_53 ) ;
if ( V_41 < 0 )
return V_41 ;
if ( V_36 [ V_54 ] ) {
V_10 = F_20 ( V_36 [ V_54 ] ) ;
if ( ! F_25 ( V_10 ) )
return - V_51 ;
}
V_49 = F_26 ( sizeof( * V_49 ) , V_55 ) ;
if ( ! V_49 )
return - V_56 ;
F_18 ( & V_49 -> V_11 , V_42 , 0 ) ;
if ( ! V_29 )
V_29 = 1 ;
V_49 -> V_29 = V_29 ;
V_49 -> V_10 = V_10 ;
V_41 = F_17 ( V_33 , V_4 , V_49 , V_34 , V_36 , V_46 [ V_57 ] , V_38 ) ;
if ( V_41 )
goto V_58;
if ( F_14 ( V_16 , V_4 , V_10 ) ) {
V_41 = F_10 ( V_4 , V_49 , ( unsigned long ) V_49 ) ;
if ( V_41 ) {
if ( F_3 ( V_10 ) )
goto V_58;
else
V_41 = 0 ;
}
}
* V_47 = ( unsigned long ) V_8 ;
F_27 ( V_4 -> V_9 , V_49 ) ;
if ( V_8 )
F_15 ( & V_8 -> V_13 , F_6 ) ;
return 0 ;
V_58:
F_9 ( V_49 ) ;
return V_41 ;
}
static int F_28 ( struct V_3 * V_4 , unsigned long V_47 )
{
return - V_59 ;
}
static void F_29 ( struct V_3 * V_4 , struct V_60 * V_47 )
{
struct V_7 * V_8 = F_13 ( V_4 -> V_9 ) ;
if ( V_47 -> V_61 < V_47 -> V_62 )
goto V_62;
if ( V_47 -> V_63 ( V_4 , ( unsigned long ) V_8 , V_47 ) < 0 )
V_47 -> V_64 = 1 ;
V_62:
V_47 -> V_61 ++ ;
}
static int F_30 ( struct V_33 * V_33 , struct V_3 * V_4 , unsigned long V_65 ,
struct V_1 * V_2 , struct V_66 * V_67 )
{
struct V_7 * V_8 = (struct V_7 * ) V_65 ;
struct V_35 * V_68 ;
if ( ! V_8 )
return V_2 -> V_69 ;
V_67 -> V_70 = V_8 -> V_29 ;
V_68 = F_31 ( V_2 , V_50 ) ;
if ( ! V_68 )
goto V_71;
if ( V_8 -> V_6 . V_44 &&
F_32 ( V_2 , V_43 , V_8 -> V_6 . V_44 ) )
goto V_71;
if ( F_33 ( V_2 , & V_8 -> V_11 ) )
goto V_71;
F_34 ( V_2 , V_68 ) ;
if ( F_35 ( V_2 , & V_8 -> V_11 ) < 0 )
goto V_71;
return V_2 -> V_69 ;
V_71:
F_36 ( V_2 , V_68 ) ;
return - 1 ;
}
static int T_2 F_37 ( void )
{
return F_38 ( & V_72 ) ;
}
static void T_3 F_39 ( void )
{
F_40 ( & V_72 ) ;
}
