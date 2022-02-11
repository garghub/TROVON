static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( F_3 ( V_3 , V_4 ) ,
struct V_1 , V_5 ) ;
}
static inline struct V_1 * F_4 ( struct V_6 * V_7 )
{
return F_2 ( F_5 ( V_7 , V_4 ) ,
struct V_1 , V_5 ) ;
}
static struct F_3 * F_6 ( struct V_8 * V_9 ,
struct V_2 * V_3 )
{
struct V_1 * V_10 ;
V_10 = F_7 ( sizeof( * V_10 ) , V_11 ) ;
if ( ! V_10 )
return F_8 ( - V_12 ) ;
if ( V_3 -> V_13 )
V_10 -> V_14 = F_1 ( V_3 -> V_13 ) -> V_14 ;
return & V_10 -> V_5 ;
}
static void F_9 ( struct V_8 * V_9 , struct V_2 * V_3 )
{
F_10 ( F_1 ( V_3 ) ) ;
}
static T_1 F_11 ( struct V_2 * V_3 , struct V_15 * V_16 )
{
return F_1 ( V_3 ) -> V_14 ;
}
static int F_12 ( struct V_2 * V_3 , struct V_15 * V_16 , T_1 V_17 )
{
F_1 ( V_3 ) -> V_14 = ( V_18 ) V_17 ;
return 0 ;
}
static int F_13 ( struct V_8 * V_9 , struct V_2 * V_3 )
{
return F_14 ( V_3 , V_9 , V_19 , F_15 ( V_19 ) ) ;
}
static int F_16 ( struct V_20 * V_21 , struct V_22 * V_23 ,
struct V_24 * V_25 )
{
struct V_26 * V_27 = V_23 -> V_28 ;
V_18 V_14 ;
F_17 () ;
V_14 = F_4 ( V_29 ) -> V_14 ;
F_18 () ;
if ( F_19 () ) {
if ( ! V_21 -> V_30 )
return - 1 ;
V_14 = V_21 -> V_30 -> V_31 ;
}
if ( ! V_14 )
return - 1 ;
if ( ! F_20 ( V_21 , & V_27 -> V_32 , NULL ) )
return - 1 ;
V_25 -> V_14 = V_14 ;
V_25 -> V_33 = 0 ;
return F_21 ( V_21 , & V_27 -> V_34 , V_25 ) ;
}
static unsigned long F_22 ( struct V_22 * V_23 , V_18 V_35 )
{
return 0UL ;
}
static void F_23 ( struct V_22 * V_23 , unsigned long V_36 )
{
}
static int F_24 ( struct V_22 * V_23 )
{
return 0 ;
}
static int F_25 ( struct V_22 * V_23 , unsigned long V_37 ,
V_18 V_35 , struct V_38 * * V_39 ,
unsigned long * V_40 )
{
struct V_38 * V_41 [ V_42 + 1 ] ;
struct V_26 * V_27 = V_23 -> V_28 ;
struct V_43 V_44 ;
struct V_45 V_46 ;
int V_47 ;
if ( ! V_39 [ V_48 ] )
return - V_49 ;
if ( V_27 == NULL ) {
if ( ! V_35 )
return - V_49 ;
V_27 = F_7 ( sizeof( * V_27 ) , V_11 ) ;
if ( V_27 == NULL )
return - V_50 ;
V_27 -> V_35 = V_35 ;
F_26 ( V_23 ) ;
V_23 -> V_28 = V_27 ;
F_27 ( V_23 ) ;
}
if ( V_35 != V_27 -> V_35 )
return - V_51 ;
V_47 = F_28 ( V_41 , V_42 , V_39 [ V_48 ] ,
V_52 ) ;
if ( V_47 < 0 )
return V_47 ;
V_47 = F_29 ( V_23 , V_41 , V_39 [ V_53 ] , & V_46 , & V_54 ) ;
if ( V_47 < 0 )
return V_47 ;
V_47 = F_30 ( V_23 , V_41 [ V_55 ] , & V_44 ) ;
if ( V_47 < 0 )
return V_47 ;
F_31 ( V_23 , & V_27 -> V_34 , & V_46 ) ;
F_32 ( V_23 , & V_27 -> V_32 , & V_44 ) ;
return 0 ;
}
static void F_33 ( struct V_22 * V_23 )
{
struct V_26 * V_27 = V_23 -> V_28 ;
if ( V_27 ) {
F_34 ( V_23 , & V_27 -> V_34 ) ;
F_35 ( V_23 , & V_27 -> V_32 ) ;
F_10 ( V_27 ) ;
}
}
static int F_36 ( struct V_22 * V_23 , unsigned long V_40 )
{
return - V_56 ;
}
static void F_37 ( struct V_22 * V_23 , struct V_57 * V_40 )
{
struct V_26 * V_27 = V_23 -> V_28 ;
if ( V_40 -> V_58 < V_40 -> V_59 )
goto V_59;
if ( V_40 -> V_60 ( V_23 , ( unsigned long ) V_27 , V_40 ) < 0 ) {
V_40 -> V_61 = 1 ;
return;
}
V_59:
V_40 -> V_58 ++ ;
}
static int F_38 ( struct V_22 * V_23 , unsigned long V_62 ,
struct V_20 * V_21 , struct V_63 * V_44 )
{
struct V_26 * V_27 = V_23 -> V_28 ;
unsigned char * V_64 = F_39 ( V_21 ) ;
struct V_38 * V_65 ;
V_44 -> V_66 = V_27 -> V_35 ;
V_65 = F_40 ( V_21 , V_48 ) ;
if ( V_65 == NULL )
goto V_67;
if ( F_41 ( V_21 , & V_27 -> V_34 , & V_54 ) < 0 ||
F_42 ( V_21 , & V_27 -> V_32 , V_55 ) < 0 )
goto V_67;
F_43 ( V_21 , V_65 ) ;
if ( F_44 ( V_21 , & V_27 -> V_34 , & V_54 ) < 0 )
goto V_67;
return V_21 -> V_68 ;
V_67:
F_45 ( V_21 , V_64 ) ;
return - 1 ;
}
static int T_2 F_46 ( void )
{
int V_69 ;
V_69 = F_47 ( & V_70 ) ;
if ( V_69 )
goto V_71;
#ifndef F_48
F_49 () ;
V_4 = V_70 . V_72 ;
#endif
V_69 = F_50 ( & V_73 ) ;
if ( V_69 )
F_51 ( & V_70 ) ;
V_71:
return V_69 ;
}
static void T_3 F_52 ( void )
{
F_53 ( & V_73 ) ;
#ifndef F_48
V_4 = - 1 ;
F_54 () ;
#endif
F_51 ( & V_70 ) ;
}
