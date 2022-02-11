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
static void * F_6 ( struct V_3 * V_4 , T_1 V_14 )
{
return NULL ;
}
static int F_7 ( struct V_3 * V_4 )
{
return 0 ;
}
static void F_8 ( struct V_7 * V_8 )
{
F_9 ( & V_8 -> V_13 ) ;
F_10 ( & V_8 -> V_11 ) ;
F_11 ( & V_8 -> V_13 ) ;
F_12 ( V_8 ) ;
}
static void F_13 ( struct V_15 * V_16 )
{
struct V_7 * V_8 = F_14 ( V_16 ,
struct V_7 ,
V_16 ) ;
F_15 () ;
F_8 ( V_8 ) ;
F_16 () ;
}
static void F_17 ( struct V_17 * V_9 )
{
struct V_7 * V_8 = F_14 ( V_9 ,
struct V_7 ,
V_18 ) ;
F_18 ( & V_8 -> V_16 , F_13 ) ;
F_19 ( & V_8 -> V_16 ) ;
}
static int F_20 ( struct V_19 * V_19 , struct V_1 * V_20 ,
struct V_3 * V_4 , unsigned long V_21 ,
T_1 V_14 , struct V_22 * * V_23 ,
void * * V_24 , bool V_25 )
{
struct V_22 * V_26 [ V_27 + 1 ] ;
struct V_7 * V_8 = F_21 ( V_4 -> V_9 ) ;
struct V_7 * V_28 ;
int V_29 ;
if ( ! V_23 [ V_30 ] )
return - V_31 ;
if ( ! V_8 && ! V_14 )
return - V_31 ;
if ( V_8 && V_14 != V_8 -> V_14 )
return - V_32 ;
V_28 = F_22 ( sizeof( * V_8 ) , V_33 ) ;
if ( ! V_28 )
return - V_34 ;
V_29 = F_23 ( & V_28 -> V_13 , V_35 , V_36 ) ;
if ( V_29 < 0 )
goto V_37;
V_28 -> V_14 = V_14 ;
V_28 -> V_4 = V_4 ;
V_29 = F_24 ( V_26 , V_27 , V_23 [ V_30 ] ,
V_38 , NULL ) ;
if ( V_29 < 0 )
goto V_37;
V_29 = F_25 ( V_19 , V_4 , V_26 , V_23 [ V_39 ] , & V_28 -> V_13 , V_25 ) ;
if ( V_29 < 0 )
goto V_37;
V_29 = F_26 ( V_4 , V_26 [ V_40 ] , & V_28 -> V_11 ) ;
if ( V_29 < 0 )
goto V_37;
F_27 ( V_4 -> V_9 , V_28 ) ;
if ( V_8 ) {
F_28 ( & V_8 -> V_13 ) ;
F_29 ( & V_8 -> V_18 , F_17 ) ;
}
return 0 ;
V_37:
F_9 ( & V_28 -> V_13 ) ;
F_12 ( V_28 ) ;
return V_29 ;
}
static void F_30 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = F_21 ( V_4 -> V_9 ) ;
if ( V_8 ) {
if ( F_28 ( & V_8 -> V_13 ) )
F_29 ( & V_8 -> V_18 , F_17 ) ;
else
F_8 ( V_8 ) ;
}
}
static int F_31 ( struct V_3 * V_4 , void * V_24 , bool * V_41 )
{
return - V_42 ;
}
static void F_32 ( struct V_3 * V_4 , struct V_43 * V_24 )
{
struct V_7 * V_8 = F_21 ( V_4 -> V_9 ) ;
if ( V_24 -> V_44 < V_24 -> V_45 )
goto V_45;
if ( V_24 -> V_46 ( V_4 , V_8 , V_24 ) < 0 ) {
V_24 -> V_47 = 1 ;
return;
}
V_45:
V_24 -> V_44 ++ ;
}
static int F_33 ( struct V_19 * V_19 , struct V_3 * V_4 , void * V_48 ,
struct V_1 * V_2 , struct V_49 * V_50 )
{
struct V_7 * V_8 = F_21 ( V_4 -> V_9 ) ;
struct V_22 * V_51 ;
V_50 -> V_52 = V_8 -> V_14 ;
V_51 = F_34 ( V_2 , V_30 ) ;
if ( V_51 == NULL )
goto V_53;
if ( F_35 ( V_2 , & V_8 -> V_13 ) < 0 ||
F_36 ( V_2 , & V_8 -> V_11 , V_40 ) < 0 )
goto V_53;
F_37 ( V_2 , V_51 ) ;
if ( F_38 ( V_2 , & V_8 -> V_13 ) < 0 )
goto V_53;
return V_2 -> V_54 ;
V_53:
F_39 ( V_2 , V_51 ) ;
return - 1 ;
}
static int T_2 F_40 ( void )
{
return F_41 ( & V_55 ) ;
}
static void T_3 F_42 ( void )
{
F_43 ( & V_55 ) ;
}
