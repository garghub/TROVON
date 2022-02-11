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
static struct F_3 * F_6 ( struct V_2 * V_3 )
{
struct V_1 * V_8 ;
V_8 = F_7 ( sizeof( * V_8 ) , V_9 ) ;
if ( ! V_8 )
return F_8 ( - V_10 ) ;
if ( V_3 -> V_11 )
V_8 -> V_12 = F_1 ( V_3 -> V_11 ) -> V_12 ;
return & V_8 -> V_5 ;
}
static void F_9 ( struct V_2 * V_3 )
{
F_10 ( F_1 ( V_3 ) ) ;
}
static T_1 F_11 ( struct V_2 * V_3 , struct V_13 * V_14 )
{
return F_1 ( V_3 ) -> V_12 ;
}
static int F_12 ( struct V_2 * V_3 , struct V_13 * V_14 , T_1 V_15 )
{
F_1 ( V_3 ) -> V_12 = ( V_16 ) V_15 ;
return 0 ;
}
static int F_13 ( struct V_17 * V_18 , const struct V_19 * V_20 ,
struct V_21 * V_22 )
{
struct V_23 * V_24 = V_20 -> V_25 ;
V_16 V_12 ;
F_14 () ;
V_12 = F_4 ( V_26 ) -> V_12 ;
F_15 () ;
if ( F_16 () ) {
if ( ! V_18 -> V_27 )
return - 1 ;
V_12 = V_18 -> V_27 -> V_28 ;
}
if ( ! V_12 )
return - 1 ;
if ( ! F_17 ( V_18 , & V_24 -> V_29 , NULL ) )
return - 1 ;
V_22 -> V_12 = V_12 ;
V_22 -> V_30 = 0 ;
return F_18 ( V_18 , & V_24 -> V_31 , V_22 ) ;
}
static unsigned long F_19 ( struct V_19 * V_20 , V_16 V_32 )
{
return 0UL ;
}
static void F_20 ( struct V_19 * V_20 , unsigned long V_33 )
{
}
static int F_21 ( struct V_19 * V_20 )
{
return 0 ;
}
static int F_22 ( struct V_17 * V_34 ,
struct V_19 * V_20 , unsigned long V_35 ,
V_16 V_32 , struct V_36 * * V_37 ,
unsigned long * V_38 )
{
struct V_36 * V_39 [ V_40 + 1 ] ;
struct V_23 * V_24 = V_20 -> V_25 ;
struct V_41 V_42 ;
struct V_43 V_44 ;
int V_45 ;
if ( ! V_37 [ V_46 ] )
return - V_47 ;
if ( V_24 == NULL ) {
if ( ! V_32 )
return - V_47 ;
V_24 = F_7 ( sizeof( * V_24 ) , V_9 ) ;
if ( V_24 == NULL )
return - V_48 ;
V_24 -> V_32 = V_32 ;
F_23 ( V_20 ) ;
V_20 -> V_25 = V_24 ;
F_24 ( V_20 ) ;
}
if ( V_32 != V_24 -> V_32 )
return - V_49 ;
V_45 = F_25 ( V_39 , V_40 , V_37 [ V_46 ] ,
V_50 ) ;
if ( V_45 < 0 )
return V_45 ;
V_45 = F_26 ( V_20 , V_39 , V_37 [ V_51 ] , & V_44 , & V_52 ) ;
if ( V_45 < 0 )
return V_45 ;
V_45 = F_27 ( V_20 , V_39 [ V_53 ] , & V_42 ) ;
if ( V_45 < 0 )
return V_45 ;
F_28 ( V_20 , & V_24 -> V_31 , & V_44 ) ;
F_29 ( V_20 , & V_24 -> V_29 , & V_42 ) ;
return 0 ;
}
static void F_30 ( struct V_19 * V_20 )
{
struct V_23 * V_24 = V_20 -> V_25 ;
if ( V_24 ) {
F_31 ( V_20 , & V_24 -> V_31 ) ;
F_32 ( V_20 , & V_24 -> V_29 ) ;
F_10 ( V_24 ) ;
}
}
static int F_33 ( struct V_19 * V_20 , unsigned long V_38 )
{
return - V_54 ;
}
static void F_34 ( struct V_19 * V_20 , struct V_55 * V_38 )
{
struct V_23 * V_24 = V_20 -> V_25 ;
if ( V_38 -> V_56 < V_38 -> V_57 )
goto V_57;
if ( V_38 -> V_58 ( V_20 , ( unsigned long ) V_24 , V_38 ) < 0 ) {
V_38 -> V_59 = 1 ;
return;
}
V_57:
V_38 -> V_56 ++ ;
}
static int F_35 ( struct V_19 * V_20 , unsigned long V_60 ,
struct V_17 * V_18 , struct V_61 * V_42 )
{
struct V_23 * V_24 = V_20 -> V_25 ;
unsigned char * V_62 = F_36 ( V_18 ) ;
struct V_36 * V_63 ;
V_42 -> V_64 = V_24 -> V_32 ;
V_63 = F_37 ( V_18 , V_46 ) ;
if ( V_63 == NULL )
goto V_65;
if ( F_38 ( V_18 , & V_24 -> V_31 , & V_52 ) < 0 ||
F_39 ( V_18 , & V_24 -> V_29 , V_53 ) < 0 )
goto V_65;
F_40 ( V_18 , V_63 ) ;
if ( F_41 ( V_18 , & V_24 -> V_31 , & V_52 ) < 0 )
goto V_65;
return V_18 -> V_66 ;
V_65:
F_42 ( V_18 , V_62 ) ;
return - 1 ;
}
static int T_2 F_43 ( void )
{
int V_67 ;
V_67 = F_44 ( & V_68 ) ;
if ( V_67 )
goto V_69;
V_67 = F_45 ( & V_70 ) ;
if ( V_67 )
F_46 ( & V_68 ) ;
V_69:
return V_67 ;
}
static void T_3 F_47 ( void )
{
F_48 ( & V_70 ) ;
F_46 ( & V_68 ) ;
}
