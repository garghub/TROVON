static int F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_7 * V_8 = F_2 ( V_4 -> V_9 ) ;
T_1 V_10 ;
V_10 = F_3 ( V_11 ) -> V_10 ;
if ( F_4 () ) {
if ( ! V_2 -> V_12 )
return - 1 ;
V_10 = V_2 -> V_12 -> V_13 ;
}
if ( ! V_10 )
return - 1 ;
if ( ! F_5 ( V_2 , & V_8 -> V_14 , NULL ) )
return - 1 ;
V_6 -> V_10 = V_10 ;
V_6 -> V_15 = 0 ;
return F_6 ( V_2 , & V_8 -> V_16 , V_6 ) ;
}
static unsigned long F_7 ( struct V_3 * V_4 , T_1 V_17 )
{
return 0UL ;
}
static int F_8 ( struct V_3 * V_4 )
{
return 0 ;
}
static void F_9 ( struct V_18 * V_9 )
{
struct V_7 * V_8 = F_10 ( V_9 ,
struct V_7 ,
V_19 ) ;
F_11 ( & V_8 -> V_16 ) ;
F_12 ( & V_8 -> V_14 ) ;
F_13 ( V_8 ) ;
}
static int F_14 ( struct V_20 * V_20 , struct V_1 * V_21 ,
struct V_3 * V_4 , unsigned long V_22 ,
T_1 V_17 , struct V_23 * * V_24 ,
unsigned long * V_25 , bool V_26 )
{
struct V_23 * V_27 [ V_28 + 1 ] ;
struct V_7 * V_8 = F_15 ( V_4 -> V_9 ) ;
struct V_7 * V_29 ;
struct V_30 V_31 ;
struct V_32 V_33 ;
int V_34 ;
if ( ! V_24 [ V_35 ] )
return - V_36 ;
if ( ! V_8 && ! V_17 )
return - V_36 ;
if ( V_8 && V_17 != V_8 -> V_17 )
return - V_37 ;
V_29 = F_16 ( sizeof( * V_8 ) , V_38 ) ;
if ( ! V_29 )
return - V_39 ;
F_17 ( & V_29 -> V_16 , V_40 , V_41 ) ;
V_29 -> V_17 = V_17 ;
V_29 -> V_4 = V_4 ;
V_34 = F_18 ( V_27 , V_28 , V_24 [ V_35 ] ,
V_42 ) ;
if ( V_34 < 0 )
goto V_43;
F_17 ( & V_33 , V_40 , V_41 ) ;
V_34 = F_19 ( V_20 , V_4 , V_27 , V_24 [ V_44 ] , & V_33 , V_26 ) ;
if ( V_34 < 0 )
goto V_43;
V_34 = F_20 ( V_4 , V_27 [ V_45 ] , & V_31 ) ;
if ( V_34 < 0 ) {
F_11 ( & V_33 ) ;
goto V_43;
}
F_21 ( V_4 , & V_29 -> V_16 , & V_33 ) ;
F_22 ( V_4 , & V_29 -> V_14 , & V_31 ) ;
F_23 ( V_4 -> V_9 , V_29 ) ;
if ( V_8 )
F_24 ( & V_8 -> V_19 , F_9 ) ;
return 0 ;
V_43:
F_13 ( V_29 ) ;
return V_34 ;
}
static void F_25 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = F_15 ( V_4 -> V_9 ) ;
if ( V_8 ) {
F_26 ( V_4 -> V_9 , NULL ) ;
F_24 ( & V_8 -> V_19 , F_9 ) ;
}
}
static int F_27 ( struct V_3 * V_4 , unsigned long V_25 )
{
return - V_46 ;
}
static void F_28 ( struct V_3 * V_4 , struct V_47 * V_25 )
{
struct V_7 * V_8 = F_15 ( V_4 -> V_9 ) ;
if ( V_25 -> V_48 < V_25 -> V_49 )
goto V_49;
if ( V_25 -> V_50 ( V_4 , ( unsigned long ) V_8 , V_25 ) < 0 ) {
V_25 -> V_51 = 1 ;
return;
}
V_49:
V_25 -> V_48 ++ ;
}
static int F_29 ( struct V_20 * V_20 , struct V_3 * V_4 , unsigned long V_52 ,
struct V_1 * V_2 , struct V_53 * V_31 )
{
struct V_7 * V_8 = F_15 ( V_4 -> V_9 ) ;
struct V_23 * V_54 ;
V_31 -> V_55 = V_8 -> V_17 ;
V_54 = F_30 ( V_2 , V_35 ) ;
if ( V_54 == NULL )
goto V_56;
if ( F_31 ( V_2 , & V_8 -> V_16 ) < 0 ||
F_32 ( V_2 , & V_8 -> V_14 , V_45 ) < 0 )
goto V_56;
F_33 ( V_2 , V_54 ) ;
if ( F_34 ( V_2 , & V_8 -> V_16 ) < 0 )
goto V_56;
return V_2 -> V_57 ;
V_56:
F_35 ( V_2 , V_54 ) ;
return - 1 ;
}
static int T_2 F_36 ( void )
{
return F_37 ( & V_58 ) ;
}
static void T_3 F_38 ( void )
{
F_39 ( & V_58 ) ;
}
