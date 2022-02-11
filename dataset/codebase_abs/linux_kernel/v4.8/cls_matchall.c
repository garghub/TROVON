static int F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_7 * V_8 = F_2 ( V_4 -> V_9 ) ;
struct V_10 * V_11 = V_8 -> V_12 ;
if ( F_3 ( V_11 -> V_13 ) )
return - 1 ;
return F_4 ( V_2 , & V_11 -> V_14 , V_6 ) ;
}
static int F_5 ( struct V_3 * V_4 )
{
struct V_7 * V_8 ;
V_8 = F_6 ( sizeof( * V_8 ) , V_15 ) ;
if ( ! V_8 )
return - V_16 ;
F_7 ( V_4 -> V_9 , V_8 ) ;
return 0 ;
}
static void F_8 ( struct V_17 * V_8 )
{
struct V_10 * V_11 = F_9 ( V_8 , struct V_10 , V_18 ) ;
F_10 ( & V_11 -> V_14 ) ;
F_11 ( V_11 ) ;
}
static int F_12 ( struct V_3 * V_4 ,
struct V_10 * V_11 ,
unsigned long V_19 )
{
struct V_20 * V_21 = V_4 -> V_22 -> V_23 -> V_21 ;
struct V_24 V_25 ;
struct V_26 V_27 = { 0 } ;
V_25 . type = V_28 ;
V_25 . V_29 = & V_27 ;
V_25 . V_29 -> V_30 = V_31 ;
V_25 . V_29 -> V_14 = & V_11 -> V_14 ;
V_25 . V_29 -> V_19 = V_19 ;
return V_21 -> V_32 -> V_33 ( V_21 , V_4 -> V_22 -> V_34 , V_4 -> V_35 ,
& V_25 ) ;
}
static void F_13 ( struct V_3 * V_4 ,
struct V_10 * V_11 ,
unsigned long V_19 )
{
struct V_20 * V_21 = V_4 -> V_22 -> V_23 -> V_21 ;
struct V_24 V_25 ;
struct V_26 V_27 = { 0 } ;
V_25 . type = V_28 ;
V_25 . V_29 = & V_27 ;
V_25 . V_29 -> V_30 = V_36 ;
V_25 . V_29 -> V_14 = NULL ;
V_25 . V_29 -> V_19 = V_19 ;
V_21 -> V_32 -> V_33 ( V_21 , V_4 -> V_22 -> V_34 , V_4 -> V_35 ,
& V_25 ) ;
}
static bool F_14 ( struct V_3 * V_4 , bool V_37 )
{
struct V_7 * V_8 = F_15 ( V_4 -> V_9 ) ;
struct V_20 * V_21 = V_4 -> V_22 -> V_23 -> V_21 ;
struct V_10 * V_11 = V_8 -> V_12 ;
if ( ! V_37 && V_11 )
return false ;
if ( V_11 ) {
if ( F_16 ( V_21 , V_4 , V_11 -> V_13 ) )
F_13 ( V_4 , V_11 , ( unsigned long ) V_11 ) ;
F_17 ( & V_11 -> V_18 , F_8 ) ;
}
F_18 ( V_4 -> V_9 , NULL ) ;
F_19 ( V_8 , V_18 ) ;
return true ;
}
static unsigned long F_20 ( struct V_3 * V_4 , T_1 V_34 )
{
struct V_7 * V_8 = F_15 ( V_4 -> V_9 ) ;
struct V_10 * V_11 = V_8 -> V_12 ;
if ( V_11 && V_11 -> V_34 == V_34 )
return ( unsigned long ) V_11 ;
return 0 ;
}
static int F_21 ( struct V_38 * V_38 , struct V_3 * V_4 ,
struct V_10 * V_11 ,
unsigned long V_39 , struct V_40 * * V_41 ,
struct V_40 * V_42 , bool V_43 )
{
struct V_44 V_45 ;
int V_46 ;
F_22 ( & V_45 , V_47 , 0 ) ;
V_46 = F_23 ( V_38 , V_4 , V_41 , V_42 , & V_45 , V_43 ) ;
if ( V_46 < 0 )
return V_46 ;
if ( V_41 [ V_48 ] ) {
V_11 -> V_6 . V_49 = F_24 ( V_41 [ V_48 ] ) ;
F_25 ( V_4 , & V_11 -> V_6 , V_39 ) ;
}
F_26 ( V_4 , & V_11 -> V_14 , & V_45 ) ;
return 0 ;
}
static int F_27 ( struct V_38 * V_38 , struct V_1 * V_50 ,
struct V_3 * V_4 , unsigned long V_39 ,
T_1 V_34 , struct V_40 * * V_51 ,
unsigned long * V_52 , bool V_43 )
{
struct V_7 * V_8 = F_15 ( V_4 -> V_9 ) ;
struct V_10 * V_53 = (struct V_10 * ) * V_52 ;
struct V_20 * V_21 = V_4 -> V_22 -> V_23 -> V_21 ;
struct V_10 * V_11 ;
struct V_40 * V_41 [ V_54 + 1 ] ;
T_1 V_13 = 0 ;
int V_46 ;
if ( ! V_51 [ V_55 ] )
return - V_56 ;
if ( V_8 -> V_12 )
return - V_57 ;
if ( V_53 )
return - V_56 ;
V_46 = F_28 ( V_41 , V_54 ,
V_51 [ V_55 ] , V_58 ) ;
if ( V_46 < 0 )
return V_46 ;
if ( V_41 [ V_59 ] ) {
V_13 = F_24 ( V_41 [ V_59 ] ) ;
if ( ! F_29 ( V_13 ) )
return - V_56 ;
}
V_11 = F_6 ( sizeof( * V_11 ) , V_15 ) ;
if ( ! V_11 )
return - V_16 ;
F_22 ( & V_11 -> V_14 , V_47 , 0 ) ;
if ( ! V_34 )
V_34 = 1 ;
V_11 -> V_34 = V_34 ;
V_11 -> V_13 = V_13 ;
V_46 = F_21 ( V_38 , V_4 , V_11 , V_39 , V_41 , V_51 [ V_60 ] , V_43 ) ;
if ( V_46 )
goto V_61;
if ( F_16 ( V_21 , V_4 , V_13 ) ) {
V_46 = F_12 ( V_4 , V_11 , ( unsigned long ) V_11 ) ;
if ( V_46 ) {
if ( F_3 ( V_13 ) )
goto V_61;
else
V_46 = 0 ;
}
}
* V_52 = ( unsigned long ) V_11 ;
F_7 ( V_8 -> V_12 , V_11 ) ;
return 0 ;
V_61:
F_11 ( V_11 ) ;
return V_46 ;
}
static int F_30 ( struct V_3 * V_4 , unsigned long V_52 )
{
struct V_7 * V_8 = F_15 ( V_4 -> V_9 ) ;
struct V_10 * V_11 = (struct V_10 * ) V_52 ;
struct V_20 * V_21 = V_4 -> V_22 -> V_23 -> V_21 ;
if ( F_16 ( V_21 , V_4 , V_11 -> V_13 ) )
F_13 ( V_4 , V_11 , ( unsigned long ) V_11 ) ;
F_18 ( V_8 -> V_12 , NULL ) ;
F_31 ( V_4 , & V_11 -> V_6 ) ;
F_17 ( & V_11 -> V_18 , F_8 ) ;
return 0 ;
}
static void F_32 ( struct V_3 * V_4 , struct V_62 * V_52 )
{
struct V_7 * V_8 = F_15 ( V_4 -> V_9 ) ;
struct V_10 * V_11 = V_8 -> V_12 ;
if ( V_52 -> V_63 < V_52 -> V_64 )
goto V_64;
if ( V_52 -> V_65 ( V_4 , ( unsigned long ) V_11 , V_52 ) < 0 )
V_52 -> V_66 = 1 ;
V_64:
V_52 -> V_63 ++ ;
}
static int F_33 ( struct V_38 * V_38 , struct V_3 * V_4 , unsigned long V_67 ,
struct V_1 * V_2 , struct V_68 * V_69 )
{
struct V_10 * V_11 = (struct V_10 * ) V_67 ;
struct V_40 * V_70 ;
if ( ! V_11 )
return V_2 -> V_71 ;
V_69 -> V_72 = V_11 -> V_34 ;
V_70 = F_34 ( V_2 , V_55 ) ;
if ( ! V_70 )
goto V_73;
if ( V_11 -> V_6 . V_49 &&
F_35 ( V_2 , V_48 , V_11 -> V_6 . V_49 ) )
goto V_73;
if ( F_36 ( V_2 , & V_11 -> V_14 ) )
goto V_73;
F_37 ( V_2 , V_70 ) ;
if ( F_38 ( V_2 , & V_11 -> V_14 ) < 0 )
goto V_73;
return V_2 -> V_71 ;
V_73:
F_39 ( V_2 , V_70 ) ;
return - 1 ;
}
static int T_2 F_40 ( void )
{
return F_41 ( & V_74 ) ;
}
static void T_3 F_42 ( void )
{
F_43 ( & V_74 ) ;
}
