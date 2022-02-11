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
static int F_31 ( struct V_43 * V_43 , struct V_28 * V_44 ,
struct V_30 * V_31 , unsigned long V_45 ,
V_21 V_41 , struct V_46 * * V_47 ,
unsigned long * V_48 )
{
struct V_46 * V_49 [ V_50 + 1 ] ;
struct V_34 * V_35 = V_31 -> V_36 ;
struct V_51 V_52 ;
struct V_53 V_54 ;
int V_16 ;
if ( ! V_47 [ V_55 ] )
return - V_56 ;
if ( V_35 == NULL ) {
if ( ! V_41 )
return - V_56 ;
V_35 = F_7 ( sizeof( * V_35 ) , V_9 ) ;
if ( V_35 == NULL )
return - V_57 ;
V_35 -> V_41 = V_41 ;
F_32 ( V_31 ) ;
V_31 -> V_36 = V_35 ;
F_33 ( V_31 ) ;
}
if ( V_41 != V_35 -> V_41 )
return - V_58 ;
V_16 = F_34 ( V_49 , V_50 , V_47 [ V_55 ] ,
V_59 ) ;
if ( V_16 < 0 )
return V_16 ;
V_16 = F_35 ( V_43 , V_31 , V_49 , V_47 [ V_60 ] , & V_54 ,
& V_61 ) ;
if ( V_16 < 0 )
return V_16 ;
V_16 = F_36 ( V_31 , V_49 [ V_62 ] , & V_52 ) ;
if ( V_16 < 0 )
return V_16 ;
F_37 ( V_31 , & V_35 -> V_40 , & V_54 ) ;
F_38 ( V_31 , & V_35 -> V_38 , & V_52 ) ;
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
static int F_42 ( struct V_30 * V_31 , unsigned long V_48 )
{
return - V_63 ;
}
static void F_43 ( struct V_30 * V_31 , struct V_64 * V_48 )
{
struct V_34 * V_35 = V_31 -> V_36 ;
if ( V_48 -> V_65 < V_48 -> V_66 )
goto V_66;
if ( V_48 -> V_67 ( V_31 , ( unsigned long ) V_35 , V_48 ) < 0 ) {
V_48 -> V_68 = 1 ;
return;
}
V_66:
V_48 -> V_65 ++ ;
}
static int F_44 ( struct V_30 * V_31 , unsigned long V_69 ,
struct V_28 * V_29 , struct V_70 * V_52 )
{
struct V_34 * V_35 = V_31 -> V_36 ;
unsigned char * V_71 = F_45 ( V_29 ) ;
struct V_46 * V_72 ;
V_52 -> V_73 = V_35 -> V_41 ;
V_72 = F_46 ( V_29 , V_55 ) ;
if ( V_72 == NULL )
goto V_74;
if ( F_47 ( V_29 , & V_35 -> V_40 , & V_61 ) < 0 ||
F_48 ( V_29 , & V_35 -> V_38 , V_62 ) < 0 )
goto V_74;
F_49 ( V_29 , V_72 ) ;
if ( F_50 ( V_29 , & V_35 -> V_40 , & V_61 ) < 0 )
goto V_74;
return V_29 -> V_75 ;
V_74:
F_51 ( V_29 , V_71 ) ;
return - 1 ;
}
static int T_2 F_52 ( void )
{
int V_76 ;
V_76 = F_53 ( & V_77 ) ;
if ( V_76 )
goto V_78;
V_76 = F_54 ( & V_79 ) ;
if ( V_76 )
F_55 ( & V_77 ) ;
V_78:
return V_76 ;
}
static void T_3 F_56 ( void )
{
F_57 ( & V_79 ) ;
F_55 ( & V_77 ) ;
}
