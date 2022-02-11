static int F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_7 * V_8 = F_2 ( V_4 -> V_9 ) ;
if ( F_3 ( V_8 -> V_10 ) )
return - 1 ;
* V_6 = V_8 -> V_6 ;
return F_4 ( V_2 , & V_8 -> V_11 , V_6 ) ;
}
static int F_5 ( struct V_3 * V_4 )
{
return 0 ;
}
static void F_6 ( struct V_7 * V_8 )
{
F_7 ( & V_8 -> V_11 ) ;
F_8 ( & V_8 -> V_11 ) ;
F_9 ( V_8 ) ;
}
static void F_10 ( struct V_12 * V_13 )
{
struct V_7 * V_8 = F_11 ( V_13 , struct V_7 ,
V_13 ) ;
F_12 () ;
F_6 ( V_8 ) ;
F_13 () ;
}
static void F_14 ( struct V_14 * V_15 )
{
struct V_7 * V_8 = F_11 ( V_15 , struct V_7 ,
V_15 ) ;
F_15 ( & V_8 -> V_13 , F_10 ) ;
F_16 ( & V_8 -> V_13 ) ;
}
static int F_17 ( struct V_3 * V_4 ,
struct V_7 * V_8 ,
unsigned long V_16 )
{
struct V_17 * V_18 = V_4 -> V_19 -> V_20 -> V_18 ;
struct V_21 V_22 = {} ;
int V_23 ;
F_18 ( & V_22 . V_24 , V_4 ) ;
V_22 . V_25 = V_26 ;
V_22 . V_11 = & V_8 -> V_11 ;
V_22 . V_16 = V_16 ;
V_23 = V_18 -> V_27 -> V_28 ( V_18 , V_29 ,
& V_22 ) ;
if ( ! V_23 )
V_8 -> V_10 |= V_30 ;
return V_23 ;
}
static void F_19 ( struct V_3 * V_4 ,
struct V_7 * V_8 ,
unsigned long V_16 )
{
struct V_17 * V_18 = V_4 -> V_19 -> V_20 -> V_18 ;
struct V_21 V_22 = {} ;
F_18 ( & V_22 . V_24 , V_4 ) ;
V_22 . V_25 = V_31 ;
V_22 . V_16 = V_16 ;
V_18 -> V_27 -> V_28 ( V_18 , V_29 , & V_22 ) ;
}
static void F_20 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = F_21 ( V_4 -> V_9 ) ;
struct V_17 * V_18 = V_4 -> V_19 -> V_20 -> V_18 ;
if ( ! V_8 )
return;
if ( F_22 ( V_18 , V_8 -> V_10 ) )
F_19 ( V_4 , V_8 , ( unsigned long ) V_8 ) ;
if ( F_23 ( & V_8 -> V_11 ) )
F_24 ( & V_8 -> V_15 , F_14 ) ;
else
F_6 ( V_8 ) ;
}
static void * F_25 ( struct V_3 * V_4 , T_1 V_32 )
{
return NULL ;
}
static int F_26 ( struct V_33 * V_33 , struct V_3 * V_4 ,
struct V_7 * V_8 ,
unsigned long V_34 , struct V_35 * * V_36 ,
struct V_35 * V_37 , bool V_38 )
{
int V_23 ;
V_23 = F_27 ( V_33 , V_4 , V_36 , V_37 , & V_8 -> V_11 , V_38 ) ;
if ( V_23 < 0 )
return V_23 ;
if ( V_36 [ V_39 ] ) {
V_8 -> V_6 . V_40 = F_28 ( V_36 [ V_39 ] ) ;
F_29 ( V_4 , & V_8 -> V_6 , V_34 ) ;
}
return 0 ;
}
static int F_30 ( struct V_33 * V_33 , struct V_1 * V_41 ,
struct V_3 * V_4 , unsigned long V_34 ,
T_1 V_32 , struct V_35 * * V_42 ,
void * * V_43 , bool V_38 )
{
struct V_7 * V_8 = F_21 ( V_4 -> V_9 ) ;
struct V_17 * V_18 = V_4 -> V_19 -> V_20 -> V_18 ;
struct V_35 * V_36 [ V_44 + 1 ] ;
struct V_7 * V_45 ;
T_1 V_10 = 0 ;
int V_23 ;
if ( ! V_42 [ V_46 ] )
return - V_47 ;
if ( V_8 )
return - V_48 ;
V_23 = F_31 ( V_36 , V_44 , V_42 [ V_46 ] ,
V_49 , NULL ) ;
if ( V_23 < 0 )
return V_23 ;
if ( V_36 [ V_50 ] ) {
V_10 = F_28 ( V_36 [ V_50 ] ) ;
if ( ! F_32 ( V_10 ) )
return - V_47 ;
}
V_45 = F_33 ( sizeof( * V_45 ) , V_51 ) ;
if ( ! V_45 )
return - V_52 ;
V_23 = F_34 ( & V_45 -> V_11 , V_53 , 0 ) ;
if ( V_23 )
goto V_54;
if ( ! V_32 )
V_32 = 1 ;
V_45 -> V_32 = V_32 ;
V_45 -> V_10 = V_10 ;
V_23 = F_26 ( V_33 , V_4 , V_45 , V_34 , V_36 , V_42 [ V_55 ] , V_38 ) ;
if ( V_23 )
goto V_56;
if ( F_22 ( V_18 , V_10 ) ) {
V_23 = F_17 ( V_4 , V_45 , ( unsigned long ) V_45 ) ;
if ( V_23 ) {
if ( F_3 ( V_10 ) )
goto V_57;
else
V_23 = 0 ;
}
}
if ( ! F_35 ( V_45 -> V_10 ) )
V_45 -> V_10 |= V_58 ;
* V_43 = V_8 ;
F_36 ( V_4 -> V_9 , V_45 ) ;
return 0 ;
V_57:
V_56:
F_7 ( & V_45 -> V_11 ) ;
V_54:
F_9 ( V_45 ) ;
return V_23 ;
}
static int F_37 ( struct V_3 * V_4 , void * V_43 , bool * V_59 )
{
return - V_60 ;
}
static void F_38 ( struct V_3 * V_4 , struct V_61 * V_43 )
{
struct V_7 * V_8 = F_21 ( V_4 -> V_9 ) ;
if ( V_43 -> V_62 < V_43 -> V_63 )
goto V_63;
if ( V_43 -> V_64 ( V_4 , V_8 , V_43 ) < 0 )
V_43 -> V_65 = 1 ;
V_63:
V_43 -> V_62 ++ ;
}
static int F_39 ( struct V_33 * V_33 , struct V_3 * V_4 , void * V_66 ,
struct V_1 * V_2 , struct V_67 * V_68 )
{
struct V_7 * V_8 = V_66 ;
struct V_35 * V_69 ;
if ( ! V_8 )
return V_2 -> V_70 ;
V_68 -> V_71 = V_8 -> V_32 ;
V_69 = F_40 ( V_2 , V_46 ) ;
if ( ! V_69 )
goto V_72;
if ( V_8 -> V_6 . V_40 &&
F_41 ( V_2 , V_39 , V_8 -> V_6 . V_40 ) )
goto V_72;
if ( V_8 -> V_10 && F_41 ( V_2 , V_50 , V_8 -> V_10 ) )
goto V_72;
if ( F_42 ( V_2 , & V_8 -> V_11 ) )
goto V_72;
F_43 ( V_2 , V_69 ) ;
if ( F_44 ( V_2 , & V_8 -> V_11 ) < 0 )
goto V_72;
return V_2 -> V_70 ;
V_72:
F_45 ( V_2 , V_69 ) ;
return - 1 ;
}
static void F_46 ( void * V_66 , T_1 V_40 , unsigned long V_73 )
{
struct V_7 * V_8 = V_66 ;
if ( V_8 && V_8 -> V_6 . V_40 == V_40 )
V_8 -> V_6 . V_74 = V_73 ;
}
static int T_2 F_47 ( void )
{
return F_48 ( & V_75 ) ;
}
static void T_3 F_49 ( void )
{
F_50 ( & V_75 ) ;
}
