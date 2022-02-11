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
return & V_8 -> V_5 ;
}
static int F_9 ( struct V_2 * V_3 )
{
if ( V_3 -> V_11 )
F_1 ( V_3 ) -> V_12 =
F_1 ( V_3 -> V_11 ) -> V_12 ;
return 0 ;
}
static void F_10 ( struct V_2 * V_3 )
{
F_11 ( F_1 ( V_3 ) ) ;
}
static int F_12 ( const void * V_13 , struct V_14 * V_14 , unsigned V_15 )
{
int V_16 ;
struct V_17 * V_18 = F_13 ( V_14 , & V_16 ) ;
if ( V_18 )
V_18 -> V_19 -> V_20 = ( V_21 ) ( unsigned long ) V_13 ;
return 0 ;
}
static void F_14 ( struct V_2 * V_3 , struct V_22 * V_23 )
{
struct V_6 * V_7 ;
void * V_13 ;
F_15 (p, cgrp, tset) {
F_16 ( V_7 ) ;
V_13 = ( void * ) ( unsigned long ) F_17 ( V_7 ) ;
F_18 ( V_7 -> V_24 , 0 , F_12 , V_13 ) ;
F_19 ( V_7 ) ;
}
}
static T_1 F_20 ( struct V_2 * V_3 , struct V_25 * V_26 )
{
return F_1 ( V_3 ) -> V_12 ;
}
static int F_21 ( struct V_2 * V_3 , struct V_25 * V_26 , T_1 V_27 )
{
F_1 ( V_3 ) -> V_12 = ( V_21 ) V_27 ;
return 0 ;
}
static int F_22 ( struct V_28 * V_29 , const struct V_30 * V_31 ,
struct V_32 * V_33 )
{
struct V_34 * V_35 = V_31 -> V_36 ;
V_21 V_12 ;
F_23 () ;
V_12 = F_4 ( V_37 ) -> V_12 ;
F_24 () ;
if ( F_25 () ) {
if ( ! V_29 -> V_19 )
return - 1 ;
V_12 = V_29 -> V_19 -> V_20 ;
}
if ( ! V_12 )
return - 1 ;
if ( ! F_26 ( V_29 , & V_35 -> V_38 , NULL ) )
return - 1 ;
V_33 -> V_12 = V_12 ;
V_33 -> V_39 = 0 ;
return F_27 ( V_29 , & V_35 -> V_40 , V_33 ) ;
}
static unsigned long F_28 ( struct V_30 * V_31 , V_21 V_41 )
{
return 0UL ;
}
static void F_29 ( struct V_30 * V_31 , unsigned long V_42 )
{
}
static int F_30 ( struct V_30 * V_31 )
{
return 0 ;
}
static int F_31 ( struct V_28 * V_43 ,
struct V_30 * V_31 , unsigned long V_44 ,
V_21 V_41 , struct V_45 * * V_46 ,
unsigned long * V_47 )
{
struct V_45 * V_48 [ V_49 + 1 ] ;
struct V_34 * V_35 = V_31 -> V_36 ;
struct V_50 V_51 ;
struct V_52 V_53 ;
int V_16 ;
if ( ! V_46 [ V_54 ] )
return - V_55 ;
if ( V_35 == NULL ) {
if ( ! V_41 )
return - V_55 ;
V_35 = F_7 ( sizeof( * V_35 ) , V_9 ) ;
if ( V_35 == NULL )
return - V_56 ;
V_35 -> V_41 = V_41 ;
F_32 ( V_31 ) ;
V_31 -> V_36 = V_35 ;
F_33 ( V_31 ) ;
}
if ( V_41 != V_35 -> V_41 )
return - V_57 ;
V_16 = F_34 ( V_48 , V_49 , V_46 [ V_54 ] ,
V_58 ) ;
if ( V_16 < 0 )
return V_16 ;
V_16 = F_35 ( V_31 , V_48 , V_46 [ V_59 ] , & V_53 , & V_60 ) ;
if ( V_16 < 0 )
return V_16 ;
V_16 = F_36 ( V_31 , V_48 [ V_61 ] , & V_51 ) ;
if ( V_16 < 0 )
return V_16 ;
F_37 ( V_31 , & V_35 -> V_40 , & V_53 ) ;
F_38 ( V_31 , & V_35 -> V_38 , & V_51 ) ;
return 0 ;
}
static void F_39 ( struct V_30 * V_31 )
{
struct V_34 * V_35 = V_31 -> V_36 ;
if ( V_35 ) {
F_40 ( V_31 , & V_35 -> V_40 ) ;
F_41 ( V_31 , & V_35 -> V_38 ) ;
F_11 ( V_35 ) ;
}
}
static int F_42 ( struct V_30 * V_31 , unsigned long V_47 )
{
return - V_62 ;
}
static void F_43 ( struct V_30 * V_31 , struct V_63 * V_47 )
{
struct V_34 * V_35 = V_31 -> V_36 ;
if ( V_47 -> V_64 < V_47 -> V_65 )
goto V_65;
if ( V_47 -> V_66 ( V_31 , ( unsigned long ) V_35 , V_47 ) < 0 ) {
V_47 -> V_67 = 1 ;
return;
}
V_65:
V_47 -> V_64 ++ ;
}
static int F_44 ( struct V_30 * V_31 , unsigned long V_68 ,
struct V_28 * V_29 , struct V_69 * V_51 )
{
struct V_34 * V_35 = V_31 -> V_36 ;
unsigned char * V_70 = F_45 ( V_29 ) ;
struct V_45 * V_71 ;
V_51 -> V_72 = V_35 -> V_41 ;
V_71 = F_46 ( V_29 , V_54 ) ;
if ( V_71 == NULL )
goto V_73;
if ( F_47 ( V_29 , & V_35 -> V_40 , & V_60 ) < 0 ||
F_48 ( V_29 , & V_35 -> V_38 , V_61 ) < 0 )
goto V_73;
F_49 ( V_29 , V_71 ) ;
if ( F_50 ( V_29 , & V_35 -> V_40 , & V_60 ) < 0 )
goto V_73;
return V_29 -> V_74 ;
V_73:
F_51 ( V_29 , V_70 ) ;
return - 1 ;
}
static int T_2 F_52 ( void )
{
int V_75 ;
V_75 = F_53 ( & V_76 ) ;
if ( V_75 )
goto V_77;
V_75 = F_54 ( & V_78 ) ;
if ( V_75 )
F_55 ( & V_76 ) ;
V_77:
return V_75 ;
}
static void T_3 F_56 ( void )
{
F_57 ( & V_78 ) ;
F_55 ( & V_76 ) ;
}
