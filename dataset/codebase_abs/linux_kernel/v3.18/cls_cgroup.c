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
static void F_8 ( struct V_3 * V_4 , unsigned long V_18 )
{
}
static int F_9 ( struct V_3 * V_4 )
{
return 0 ;
}
static void F_10 ( struct V_19 * V_9 )
{
struct V_7 * V_8 = F_11 ( V_9 ,
struct V_7 ,
V_20 ) ;
F_12 ( & V_8 -> V_16 ) ;
F_13 ( & V_8 -> V_14 ) ;
F_14 ( V_8 ) ;
}
static int F_15 ( struct V_21 * V_21 , struct V_1 * V_22 ,
struct V_3 * V_4 , unsigned long V_23 ,
T_1 V_17 , struct V_24 * * V_25 ,
unsigned long * V_26 , bool V_27 )
{
struct V_24 * V_28 [ V_29 + 1 ] ;
struct V_7 * V_8 = F_16 ( V_4 -> V_9 ) ;
struct V_7 * V_30 ;
struct V_31 V_32 ;
struct V_33 V_34 ;
int V_35 ;
if ( ! V_25 [ V_36 ] )
return - V_37 ;
if ( ! V_8 && ! V_17 )
return - V_37 ;
if ( V_8 && V_17 != V_8 -> V_17 )
return - V_38 ;
V_30 = F_17 ( sizeof( * V_8 ) , V_39 ) ;
if ( ! V_30 )
return - V_40 ;
F_18 ( & V_30 -> V_16 , V_41 , V_42 ) ;
if ( V_8 )
V_30 -> V_17 = V_8 -> V_17 ;
else
V_30 -> V_17 = V_17 ;
V_30 -> V_4 = V_4 ;
V_35 = F_19 ( V_28 , V_29 , V_25 [ V_36 ] ,
V_43 ) ;
if ( V_35 < 0 )
goto V_44;
F_18 ( & V_34 , V_41 , V_42 ) ;
V_35 = F_20 ( V_21 , V_4 , V_28 , V_25 [ V_45 ] , & V_34 , V_27 ) ;
if ( V_35 < 0 )
goto V_44;
V_35 = F_21 ( V_4 , V_28 [ V_46 ] , & V_32 ) ;
if ( V_35 < 0 ) {
F_12 ( & V_34 ) ;
goto V_44;
}
F_22 ( V_4 , & V_30 -> V_16 , & V_34 ) ;
F_23 ( V_4 , & V_30 -> V_14 , & V_32 ) ;
F_24 ( V_4 -> V_9 , V_30 ) ;
if ( V_8 )
F_25 ( & V_8 -> V_20 , F_10 ) ;
return 0 ;
V_44:
F_14 ( V_30 ) ;
return V_35 ;
}
static void F_26 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = F_16 ( V_4 -> V_9 ) ;
if ( V_8 ) {
F_27 ( V_4 -> V_9 , NULL ) ;
F_25 ( & V_8 -> V_20 , F_10 ) ;
}
}
static int F_28 ( struct V_3 * V_4 , unsigned long V_26 )
{
return - V_47 ;
}
static void F_29 ( struct V_3 * V_4 , struct V_48 * V_26 )
{
struct V_7 * V_8 = F_16 ( V_4 -> V_9 ) ;
if ( V_26 -> V_49 < V_26 -> V_50 )
goto V_50;
if ( V_26 -> V_51 ( V_4 , ( unsigned long ) V_8 , V_26 ) < 0 ) {
V_26 -> V_52 = 1 ;
return;
}
V_50:
V_26 -> V_49 ++ ;
}
static int F_30 ( struct V_21 * V_21 , struct V_3 * V_4 , unsigned long V_53 ,
struct V_1 * V_2 , struct V_54 * V_32 )
{
struct V_7 * V_8 = F_16 ( V_4 -> V_9 ) ;
unsigned char * V_55 = F_31 ( V_2 ) ;
struct V_24 * V_56 ;
V_32 -> V_57 = V_8 -> V_17 ;
V_56 = F_32 ( V_2 , V_36 ) ;
if ( V_56 == NULL )
goto V_58;
if ( F_33 ( V_2 , & V_8 -> V_16 ) < 0 ||
F_34 ( V_2 , & V_8 -> V_14 , V_46 ) < 0 )
goto V_58;
F_35 ( V_2 , V_56 ) ;
if ( F_36 ( V_2 , & V_8 -> V_16 ) < 0 )
goto V_58;
return V_2 -> V_59 ;
V_58:
F_37 ( V_2 , V_55 ) ;
return - 1 ;
}
static int T_2 F_38 ( void )
{
return F_39 ( & V_60 ) ;
}
static void T_3 F_40 ( void )
{
F_41 ( & V_60 ) ;
}
