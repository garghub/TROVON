static int F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_7 * V_8 = F_2 ( V_4 -> V_9 ) ;
T_1 V_10 = F_3 ( V_2 ) ;
if ( ! V_10 )
return - 1 ;
if ( ! F_4 ( V_2 , & V_8 -> V_11 , NULL ) )
return - 1 ;
V_6 -> V_10 = V_10 ;
V_6 -> V_12 = 0 ;
return F_5 ( V_2 , & V_8 -> V_13 , V_6 ) ;
}
static unsigned long F_6 ( struct V_3 * V_4 , T_1 V_14 )
{
return 0UL ;
}
static int F_7 ( struct V_3 * V_4 )
{
return 0 ;
}
static void F_8 ( struct V_15 * V_9 )
{
struct V_7 * V_8 = F_9 ( V_9 ,
struct V_7 ,
V_16 ) ;
F_10 ( & V_8 -> V_13 ) ;
F_11 ( & V_8 -> V_11 ) ;
F_12 ( V_8 ) ;
}
static int F_13 ( struct V_17 * V_17 , struct V_1 * V_18 ,
struct V_3 * V_4 , unsigned long V_19 ,
T_1 V_14 , struct V_20 * * V_21 ,
unsigned long * V_22 , bool V_23 )
{
struct V_20 * V_24 [ V_25 + 1 ] ;
struct V_7 * V_8 = F_14 ( V_4 -> V_9 ) ;
struct V_7 * V_26 ;
struct V_27 V_28 ;
struct V_29 V_30 ;
int V_31 ;
if ( ! V_21 [ V_32 ] )
return - V_33 ;
if ( ! V_8 && ! V_14 )
return - V_33 ;
if ( V_8 && V_14 != V_8 -> V_14 )
return - V_34 ;
V_26 = F_15 ( sizeof( * V_8 ) , V_35 ) ;
if ( ! V_26 )
return - V_36 ;
V_31 = F_16 ( & V_26 -> V_13 , V_37 , V_38 ) ;
if ( V_31 < 0 )
goto V_39;
V_26 -> V_14 = V_14 ;
V_26 -> V_4 = V_4 ;
V_31 = F_17 ( V_24 , V_25 , V_21 [ V_32 ] ,
V_40 , NULL ) ;
if ( V_31 < 0 )
goto V_39;
V_31 = F_16 ( & V_30 , V_37 , V_38 ) ;
if ( V_31 < 0 )
goto V_39;
V_31 = F_18 ( V_17 , V_4 , V_24 , V_21 [ V_41 ] , & V_30 , V_23 ) ;
if ( V_31 < 0 ) {
F_10 ( & V_30 ) ;
goto V_39;
}
V_31 = F_19 ( V_4 , V_24 [ V_42 ] , & V_28 ) ;
if ( V_31 < 0 ) {
F_10 ( & V_30 ) ;
goto V_39;
}
F_20 ( V_4 , & V_26 -> V_13 , & V_30 ) ;
F_21 ( V_4 , & V_26 -> V_11 , & V_28 ) ;
F_22 ( V_4 -> V_9 , V_26 ) ;
if ( V_8 )
F_23 ( & V_8 -> V_16 , F_8 ) ;
return 0 ;
V_39:
F_10 ( & V_26 -> V_13 ) ;
F_12 ( V_26 ) ;
return V_31 ;
}
static void F_24 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = F_14 ( V_4 -> V_9 ) ;
if ( V_8 )
F_23 ( & V_8 -> V_16 , F_8 ) ;
}
static int F_25 ( struct V_3 * V_4 , unsigned long V_22 , bool * V_43 )
{
return - V_44 ;
}
static void F_26 ( struct V_3 * V_4 , struct V_45 * V_22 )
{
struct V_7 * V_8 = F_14 ( V_4 -> V_9 ) ;
if ( V_22 -> V_46 < V_22 -> V_47 )
goto V_47;
if ( V_22 -> V_48 ( V_4 , ( unsigned long ) V_8 , V_22 ) < 0 ) {
V_22 -> V_49 = 1 ;
return;
}
V_47:
V_22 -> V_46 ++ ;
}
static int F_27 ( struct V_17 * V_17 , struct V_3 * V_4 , unsigned long V_50 ,
struct V_1 * V_2 , struct V_51 * V_28 )
{
struct V_7 * V_8 = F_14 ( V_4 -> V_9 ) ;
struct V_20 * V_52 ;
V_28 -> V_53 = V_8 -> V_14 ;
V_52 = F_28 ( V_2 , V_32 ) ;
if ( V_52 == NULL )
goto V_54;
if ( F_29 ( V_2 , & V_8 -> V_13 ) < 0 ||
F_30 ( V_2 , & V_8 -> V_11 , V_42 ) < 0 )
goto V_54;
F_31 ( V_2 , V_52 ) ;
if ( F_32 ( V_2 , & V_8 -> V_13 ) < 0 )
goto V_54;
return V_2 -> V_55 ;
V_54:
F_33 ( V_2 , V_52 ) ;
return - 1 ;
}
static int T_2 F_34 ( void )
{
return F_35 ( & V_56 ) ;
}
static void T_3 F_36 ( void )
{
F_37 ( & V_56 ) ;
}
