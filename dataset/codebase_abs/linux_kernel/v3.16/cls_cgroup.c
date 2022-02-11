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
unsigned long * V_24 , bool V_25 )
{
struct V_22 * V_26 [ V_27 + 1 ] ;
struct V_7 * V_8 = V_4 -> V_9 ;
struct V_28 V_29 ;
struct V_30 V_31 ;
int V_32 ;
if ( ! V_23 [ V_33 ] )
return - V_34 ;
if ( V_8 == NULL ) {
if ( ! V_17 )
return - V_34 ;
V_8 = F_12 ( sizeof( * V_8 ) , V_35 ) ;
if ( V_8 == NULL )
return - V_36 ;
F_13 ( & V_8 -> V_16 , V_37 , V_38 ) ;
V_8 -> V_17 = V_17 ;
F_14 ( V_4 ) ;
V_4 -> V_9 = V_8 ;
F_15 ( V_4 ) ;
}
if ( V_17 != V_8 -> V_17 )
return - V_39 ;
V_32 = F_16 ( V_26 , V_27 , V_23 [ V_33 ] ,
V_40 ) ;
if ( V_32 < 0 )
return V_32 ;
F_13 ( & V_31 , V_37 , V_38 ) ;
V_32 = F_17 ( V_19 , V_4 , V_26 , V_23 [ V_41 ] , & V_31 , V_25 ) ;
if ( V_32 < 0 )
return V_32 ;
V_32 = F_18 ( V_4 , V_26 [ V_42 ] , & V_29 ) ;
if ( V_32 < 0 )
return V_32 ;
F_19 ( V_4 , & V_8 -> V_16 , & V_31 ) ;
F_20 ( V_4 , & V_8 -> V_14 , & V_29 ) ;
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
return - V_43 ;
}
static void F_26 ( struct V_3 * V_4 , struct V_44 * V_24 )
{
struct V_7 * V_8 = V_4 -> V_9 ;
if ( V_24 -> V_45 < V_24 -> V_46 )
goto V_46;
if ( V_24 -> V_47 ( V_4 , ( unsigned long ) V_8 , V_24 ) < 0 ) {
V_24 -> V_48 = 1 ;
return;
}
V_46:
V_24 -> V_45 ++ ;
}
static int F_27 ( struct V_19 * V_19 , struct V_3 * V_4 , unsigned long V_49 ,
struct V_1 * V_2 , struct V_50 * V_29 )
{
struct V_7 * V_8 = V_4 -> V_9 ;
unsigned char * V_51 = F_28 ( V_2 ) ;
struct V_22 * V_52 ;
V_29 -> V_53 = V_8 -> V_17 ;
V_52 = F_29 ( V_2 , V_33 ) ;
if ( V_52 == NULL )
goto V_54;
if ( F_30 ( V_2 , & V_8 -> V_16 ) < 0 ||
F_31 ( V_2 , & V_8 -> V_14 , V_42 ) < 0 )
goto V_54;
F_32 ( V_2 , V_52 ) ;
if ( F_33 ( V_2 , & V_8 -> V_16 ) < 0 )
goto V_54;
return V_2 -> V_55 ;
V_54:
F_34 ( V_2 , V_51 ) ;
return - 1 ;
}
static int T_2 F_35 ( void )
{
return F_36 ( & V_56 ) ;
}
static void T_3 F_37 ( void )
{
F_38 ( & V_56 ) ;
}
