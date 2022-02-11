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
static int F_22 ( struct V_19 * V_20 , unsigned long V_34 ,
V_16 V_32 , struct V_35 * * V_36 ,
unsigned long * V_37 )
{
struct V_35 * V_38 [ V_39 + 1 ] ;
struct V_23 * V_24 = V_20 -> V_25 ;
struct V_40 V_41 ;
struct V_42 V_43 ;
int V_44 ;
if ( ! V_36 [ V_45 ] )
return - V_46 ;
if ( V_24 == NULL ) {
if ( ! V_32 )
return - V_46 ;
V_24 = F_7 ( sizeof( * V_24 ) , V_9 ) ;
if ( V_24 == NULL )
return - V_47 ;
V_24 -> V_32 = V_32 ;
F_23 ( V_20 ) ;
V_20 -> V_25 = V_24 ;
F_24 ( V_20 ) ;
}
if ( V_32 != V_24 -> V_32 )
return - V_48 ;
V_44 = F_25 ( V_38 , V_39 , V_36 [ V_45 ] ,
V_49 ) ;
if ( V_44 < 0 )
return V_44 ;
V_44 = F_26 ( V_20 , V_38 , V_36 [ V_50 ] , & V_43 , & V_51 ) ;
if ( V_44 < 0 )
return V_44 ;
V_44 = F_27 ( V_20 , V_38 [ V_52 ] , & V_41 ) ;
if ( V_44 < 0 )
return V_44 ;
F_28 ( V_20 , & V_24 -> V_31 , & V_43 ) ;
F_29 ( V_20 , & V_24 -> V_29 , & V_41 ) ;
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
static int F_33 ( struct V_19 * V_20 , unsigned long V_37 )
{
return - V_53 ;
}
static void F_34 ( struct V_19 * V_20 , struct V_54 * V_37 )
{
struct V_23 * V_24 = V_20 -> V_25 ;
if ( V_37 -> V_55 < V_37 -> V_56 )
goto V_56;
if ( V_37 -> V_57 ( V_20 , ( unsigned long ) V_24 , V_37 ) < 0 ) {
V_37 -> V_58 = 1 ;
return;
}
V_56:
V_37 -> V_55 ++ ;
}
static int F_35 ( struct V_19 * V_20 , unsigned long V_59 ,
struct V_17 * V_18 , struct V_60 * V_41 )
{
struct V_23 * V_24 = V_20 -> V_25 ;
unsigned char * V_61 = F_36 ( V_18 ) ;
struct V_35 * V_62 ;
V_41 -> V_63 = V_24 -> V_32 ;
V_62 = F_37 ( V_18 , V_45 ) ;
if ( V_62 == NULL )
goto V_64;
if ( F_38 ( V_18 , & V_24 -> V_31 , & V_51 ) < 0 ||
F_39 ( V_18 , & V_24 -> V_29 , V_52 ) < 0 )
goto V_64;
F_40 ( V_18 , V_62 ) ;
if ( F_41 ( V_18 , & V_24 -> V_31 , & V_51 ) < 0 )
goto V_64;
return V_18 -> V_65 ;
V_64:
F_42 ( V_18 , V_61 ) ;
return - 1 ;
}
static int T_2 F_43 ( void )
{
int V_66 ;
V_66 = F_44 ( & V_67 ) ;
if ( V_66 )
goto V_68;
#ifndef F_45
F_46 () ;
V_4 = V_67 . V_69 ;
#endif
V_66 = F_47 ( & V_70 ) ;
if ( V_66 )
F_48 ( & V_67 ) ;
V_68:
return V_66 ;
}
static void T_3 F_49 ( void )
{
F_50 ( & V_70 ) ;
#ifndef F_45
V_4 = - 1 ;
F_51 () ;
#endif
F_48 ( & V_67 ) ;
}
