static int F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_7 * V_8 = V_4 -> V_9 ;
T_1 V_10 ;
F_2 () ;
V_10 = F_3 ( V_11 ) -> V_10 ;
F_4 () ;
if ( F_5 () ) {
if ( ! V_2 -> V_12 )
return - 1 ;
V_10 = V_2 -> V_12 -> V_13 ;
}
if ( ! V_10 )
return - 1 ;
if ( ! F_6 ( V_2 , & V_8 -> V_14 , NULL ) )
return - 1 ;
V_6 -> V_10 = V_10 ;
V_6 -> V_15 = 0 ;
return F_7 ( V_2 , & V_8 -> V_16 , V_6 ) ;
}
static unsigned long F_8 ( struct V_3 * V_4 , T_1 V_17 )
{
return 0UL ;
}
static void F_9 ( struct V_3 * V_4 , unsigned long V_18 )
{
}
static int F_10 ( struct V_3 * V_4 )
{
return 0 ;
}
static int F_11 ( struct V_19 * V_19 , struct V_1 * V_20 ,
struct V_3 * V_4 , unsigned long V_21 ,
T_1 V_17 , struct V_22 * * V_23 ,
unsigned long * V_24 )
{
struct V_22 * V_25 [ V_26 + 1 ] ;
struct V_7 * V_8 = V_4 -> V_9 ;
struct V_27 V_28 ;
struct V_29 V_30 ;
int V_31 ;
if ( ! V_23 [ V_32 ] )
return - V_33 ;
if ( V_8 == NULL ) {
if ( ! V_17 )
return - V_33 ;
V_8 = F_12 ( sizeof( * V_8 ) , V_34 ) ;
if ( V_8 == NULL )
return - V_35 ;
F_13 ( & V_8 -> V_16 , V_36 , V_37 ) ;
V_8 -> V_17 = V_17 ;
F_14 ( V_4 ) ;
V_4 -> V_9 = V_8 ;
F_15 ( V_4 ) ;
}
if ( V_17 != V_8 -> V_17 )
return - V_38 ;
V_31 = F_16 ( V_25 , V_26 , V_23 [ V_32 ] ,
V_39 ) ;
if ( V_31 < 0 )
return V_31 ;
F_13 ( & V_30 , V_36 , V_37 ) ;
V_31 = F_17 ( V_19 , V_4 , V_25 , V_23 [ V_40 ] , & V_30 ) ;
if ( V_31 < 0 )
return V_31 ;
V_31 = F_18 ( V_4 , V_25 [ V_41 ] , & V_28 ) ;
if ( V_31 < 0 )
return V_31 ;
F_19 ( V_4 , & V_8 -> V_16 , & V_30 ) ;
F_20 ( V_4 , & V_8 -> V_14 , & V_28 ) ;
return 0 ;
}
static void F_21 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = V_4 -> V_9 ;
if ( V_8 ) {
F_22 ( V_4 , & V_8 -> V_16 ) ;
F_23 ( V_4 , & V_8 -> V_14 ) ;
F_24 ( V_8 ) ;
}
}
static int F_25 ( struct V_3 * V_4 , unsigned long V_24 )
{
return - V_42 ;
}
static void F_26 ( struct V_3 * V_4 , struct V_43 * V_24 )
{
struct V_7 * V_8 = V_4 -> V_9 ;
if ( V_24 -> V_44 < V_24 -> V_45 )
goto V_45;
if ( V_24 -> V_46 ( V_4 , ( unsigned long ) V_8 , V_24 ) < 0 ) {
V_24 -> V_47 = 1 ;
return;
}
V_45:
V_24 -> V_44 ++ ;
}
static int F_27 ( struct V_19 * V_19 , struct V_3 * V_4 , unsigned long V_48 ,
struct V_1 * V_2 , struct V_49 * V_28 )
{
struct V_7 * V_8 = V_4 -> V_9 ;
unsigned char * V_50 = F_28 ( V_2 ) ;
struct V_22 * V_51 ;
V_28 -> V_52 = V_8 -> V_17 ;
V_51 = F_29 ( V_2 , V_32 ) ;
if ( V_51 == NULL )
goto V_53;
if ( F_30 ( V_2 , & V_8 -> V_16 ) < 0 ||
F_31 ( V_2 , & V_8 -> V_14 , V_41 ) < 0 )
goto V_53;
F_32 ( V_2 , V_51 ) ;
if ( F_33 ( V_2 , & V_8 -> V_16 ) < 0 )
goto V_53;
return V_2 -> V_54 ;
V_53:
F_34 ( V_2 , V_50 ) ;
return - 1 ;
}
static int T_2 F_35 ( void )
{
return F_36 ( & V_55 ) ;
}
static void T_3 F_37 ( void )
{
F_38 ( & V_55 ) ;
}
