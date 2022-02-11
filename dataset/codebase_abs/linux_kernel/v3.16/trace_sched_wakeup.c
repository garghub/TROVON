static int
F_1 ( struct V_1 * V_2 ,
struct V_3 * * V_4 ,
int * V_5 )
{
long V_6 ;
int V_7 ;
if ( F_2 ( ! V_8 ) )
return 0 ;
* V_5 = F_3 () ;
F_4 () ;
V_7 = F_5 () ;
if ( V_7 != V_9 )
goto V_10;
* V_4 = F_6 ( V_2 -> V_11 . V_4 , V_7 ) ;
V_6 = F_7 ( & ( * V_4 ) -> V_6 ) ;
if ( F_8 ( V_6 != 1 ) )
goto V_12;
return 1 ;
V_12:
F_9 ( & ( * V_4 ) -> V_6 ) ;
V_10:
F_10 () ;
return 0 ;
}
static void
F_11 ( unsigned long V_13 , unsigned long V_14 ,
struct V_15 * V_16 , struct V_17 * V_17 )
{
struct V_1 * V_2 = V_18 ;
struct V_3 * V_4 ;
unsigned long V_19 ;
int V_5 ;
if ( ! F_1 ( V_2 , & V_4 , & V_5 ) )
return;
F_12 ( V_19 ) ;
F_13 ( V_2 , V_13 , V_14 , V_19 , V_5 ) ;
F_14 ( V_19 ) ;
F_9 ( & V_4 -> V_6 ) ;
F_10 () ;
}
static int F_15 ( struct V_1 * V_2 , int V_20 , int V_21 )
{
int V_22 ;
if ( V_23 || ( ! V_21 && ! ( V_24 & V_25 ) ) )
return 0 ;
if ( V_20 )
V_22 = F_16 ( & V_26 ,
& V_27 ) ;
else
V_22 = F_17 ( V_2 -> V_28 ) ;
if ( ! V_22 )
V_23 = true ;
return V_22 ;
}
static void F_18 ( struct V_1 * V_2 , int V_20 )
{
if ( ! V_23 )
return;
if ( V_20 )
F_19 () ;
else
F_20 ( V_2 -> V_28 ) ;
V_23 = false ;
}
static void F_21 ( struct V_1 * V_2 , int V_21 )
{
if ( V_21 )
F_15 ( V_2 , F_22 () , 1 ) ;
else
F_18 ( V_2 , F_22 () ) ;
}
static int F_23 ( struct V_1 * V_2 , T_1 V_29 , int V_21 )
{
struct V_30 * V_30 = V_2 -> V_31 ;
if ( V_29 & V_25 )
F_21 ( V_2 , V_21 ) ;
return F_24 ( V_30 , V_29 , V_21 ) ;
}
static int F_25 ( struct V_1 * V_2 , int V_20 )
{
int V_22 ;
V_22 = F_15 ( V_2 , V_20 , 0 ) ;
if ( ! V_22 && F_26 () )
V_32 = 1 ;
else
V_32 = 0 ;
return V_22 ;
}
static void F_27 ( struct V_1 * V_2 , int V_20 )
{
V_32 = 0 ;
F_18 ( V_2 , V_20 ) ;
}
static int
F_28 ( struct V_1 * V_2 , T_1 V_33 , T_1 V_34 , int V_21 )
{
if ( ! ( V_34 & V_35 ) )
return - V_36 ;
if ( ! ( F_22 () ^ V_21 ) )
return 0 ;
F_27 ( V_2 , ! V_21 ) ;
F_29 ( V_18 ) ;
V_2 -> V_37 = 0 ;
return F_25 ( V_2 , V_21 ) ;
}
static int V_27 ( struct V_38 * V_39 )
{
struct V_1 * V_2 = V_18 ;
struct V_3 * V_4 ;
unsigned long V_19 ;
int V_5 , V_22 = 0 ;
if ( ! F_1 ( V_2 , & V_4 , & V_5 ) )
return 0 ;
F_30 ( V_19 ) ;
V_22 = F_31 ( V_2 , V_39 , V_19 , V_5 ) ;
F_9 ( & V_4 -> V_6 ) ;
F_10 () ;
return V_22 ;
}
static void V_26 ( struct V_40 * V_39 )
{
struct V_1 * V_2 = V_18 ;
struct V_3 * V_4 ;
unsigned long V_19 ;
int V_5 ;
if ( ! F_1 ( V_2 , & V_4 , & V_5 ) )
return;
F_30 ( V_19 ) ;
F_32 ( V_2 , V_39 , V_19 , V_5 ) ;
F_9 ( & V_4 -> V_6 ) ;
F_10 () ;
return;
}
static void F_33 ( struct V_41 * V_42 )
{
if ( F_22 () )
F_34 ( V_42 ) ;
}
static void F_35 ( struct V_41 * V_42 )
{
if ( V_42 -> V_43 )
F_36 ( V_42 ) ;
}
static enum V_44 F_37 ( struct V_41 * V_42 )
{
if ( F_22 () )
return F_38 ( V_42 , V_45 ) ;
return V_46 ;
}
static void F_39 ( struct V_47 * V_48 )
{
if ( F_22 () )
F_40 ( V_48 , V_45 ) ;
else
F_41 ( V_48 ) ;
}
static void
F_42 ( struct V_1 * V_2 ,
unsigned long V_13 , unsigned long V_14 ,
unsigned long V_19 , int V_5 )
{
if ( F_22 () )
F_43 ( V_2 , V_13 , V_14 , V_19 , V_5 ) ;
else
F_13 ( V_2 , V_13 , V_14 , V_19 , V_5 ) ;
}
static int
F_28 ( struct V_1 * V_2 , T_1 V_33 , T_1 V_34 , int V_21 )
{
return - V_36 ;
}
static int V_27 ( struct V_38 * V_39 )
{
return - 1 ;
}
static enum V_44 F_37 ( struct V_41 * V_42 )
{
return V_46 ;
}
static void V_26 ( struct V_40 * V_39 ) { }
static void F_33 ( struct V_41 * V_42 ) { }
static void F_35 ( struct V_41 * V_42 ) { }
static void F_39 ( struct V_47 * V_48 )
{
F_41 ( V_48 ) ;
}
static void F_39 ( struct V_47 * V_48 )
{
F_44 ( V_48 ) ;
}
static int F_45 ( struct V_1 * V_2 , T_2 V_49 )
{
if ( V_50 ) {
if ( V_49 < V_50 )
return 0 ;
} else {
if ( V_49 <= V_2 -> V_37 )
return 0 ;
}
return 1 ;
}
static void
F_46 ( void * V_51 , struct V_52 * V_53 , int V_7 )
{
if ( V_53 != V_8 )
return;
V_9 = V_7 ;
}
static void T_3
F_47 ( void * V_51 ,
struct V_52 * V_54 , struct V_52 * V_55 )
{
struct V_3 * V_4 ;
T_2 V_56 , V_57 , V_49 ;
unsigned long V_19 ;
long V_6 ;
int V_7 ;
int V_5 ;
F_48 ( V_54 ) ;
if ( F_8 ( ! V_32 ) )
return;
F_49 () ;
if ( V_55 != V_8 )
return;
V_5 = F_3 () ;
V_7 = F_5 () ;
V_6 = F_7 ( & F_6 ( V_18 -> V_11 . V_4 , V_7 ) -> V_6 ) ;
if ( F_2 ( V_6 != 1 ) )
goto V_12;
F_12 ( V_19 ) ;
F_50 ( & V_58 ) ;
if ( F_8 ( ! V_32 || V_55 != V_8 ) )
goto V_59;
V_4 = F_6 ( V_18 -> V_11 . V_4 , V_60 ) ;
F_42 ( V_18 , V_61 , V_62 , V_19 , V_5 ) ;
F_51 ( V_18 , V_54 , V_55 , V_19 , V_5 ) ;
V_56 = V_4 -> V_63 ;
V_57 = F_52 ( V_7 ) ;
V_49 = V_57 - V_56 ;
if ( ! F_45 ( V_18 , V_49 ) )
goto V_59;
if ( F_2 ( ! F_53 () ) ) {
V_18 -> V_37 = V_49 ;
F_54 ( V_18 , V_8 , V_60 ) ;
}
V_59:
F_55 ( V_18 ) ;
F_56 ( & V_58 ) ;
F_14 ( V_19 ) ;
V_12:
F_9 ( & F_6 ( V_18 -> V_11 . V_4 , V_7 ) -> V_6 ) ;
}
static void F_55 ( struct V_1 * V_2 )
{
V_60 = - 1 ;
V_64 = - 1 ;
V_65 = 0 ;
if ( V_8 )
F_57 ( V_8 ) ;
V_8 = NULL ;
}
static void F_29 ( struct V_1 * V_2 )
{
unsigned long V_19 ;
F_58 ( & V_2 -> V_11 ) ;
F_12 ( V_19 ) ;
F_50 ( & V_58 ) ;
F_55 ( V_2 ) ;
F_56 ( & V_58 ) ;
F_14 ( V_19 ) ;
}
static void
F_59 ( void * V_51 , struct V_52 * V_66 , int V_67 )
{
struct V_3 * V_4 ;
int V_7 = F_60 () ;
unsigned long V_19 ;
long V_6 ;
int V_5 ;
if ( F_2 ( ! V_32 ) )
return;
F_48 ( V_66 ) ;
F_48 ( V_68 ) ;
if ( V_65 || ( V_69 && ! F_61 ( V_66 ) ) ||
( V_70 && ! F_61 ( V_66 ) && ! F_62 ( V_66 ) ) ||
( ! F_61 ( V_66 ) && ( V_66 -> V_71 >= V_64 || V_66 -> V_71 >= V_68 -> V_71 ) ) )
return;
V_5 = F_3 () ;
V_6 = F_7 ( & F_6 ( V_18 -> V_11 . V_4 , V_7 ) -> V_6 ) ;
if ( F_8 ( V_6 != 1 ) )
goto V_12;
F_50 ( & V_58 ) ;
if ( ! V_32 || V_65 ||
( ! F_61 ( V_66 ) && V_66 -> V_71 >= V_64 ) )
goto V_72;
F_55 ( V_18 ) ;
V_60 = F_63 ( V_66 ) ;
V_9 = V_60 ;
V_64 = V_66 -> V_71 ;
if ( F_61 ( V_66 ) )
V_65 = 1 ;
else
V_65 = 0 ;
V_8 = V_66 ;
F_64 ( V_8 ) ;
F_30 ( V_19 ) ;
V_4 = F_6 ( V_18 -> V_11 . V_4 , V_60 ) ;
V_4 -> V_63 = F_52 ( V_7 ) ;
F_65 ( V_18 , V_66 , V_68 , V_19 , V_5 ) ;
F_42 ( V_18 , V_62 , V_73 , V_19 , V_5 ) ;
V_72:
F_56 ( & V_58 ) ;
V_12:
F_9 ( & F_6 ( V_18 -> V_11 . V_4 , V_7 ) -> V_6 ) ;
}
static void F_66 ( struct V_1 * V_2 )
{
int V_22 ;
V_22 = F_67 ( F_59 , NULL ) ;
if ( V_22 ) {
F_68 ( L_1
L_2 ) ;
return;
}
V_22 = F_69 ( F_59 , NULL ) ;
if ( V_22 ) {
F_68 ( L_1
L_3 ) ;
goto V_74;
}
V_22 = F_70 ( F_47 , NULL ) ;
if ( V_22 ) {
F_68 ( L_4
L_5 ) ;
goto V_75;
}
V_22 = F_71 ( F_46 , NULL ) ;
if ( V_22 ) {
F_68 ( L_1
L_6 ) ;
return;
}
F_29 ( V_2 ) ;
F_72 () ;
if ( F_25 ( V_2 , F_22 () ) )
F_73 ( V_76 L_7 ) ;
return;
V_75:
F_74 ( F_59 , NULL ) ;
V_74:
F_75 ( F_59 , NULL ) ;
}
static void F_76 ( struct V_1 * V_2 )
{
V_32 = 0 ;
F_27 ( V_2 , F_22 () ) ;
F_77 ( F_47 , NULL ) ;
F_74 ( F_59 , NULL ) ;
F_75 ( F_59 , NULL ) ;
F_78 ( F_46 , NULL ) ;
}
static int F_79 ( struct V_1 * V_2 )
{
V_77 = V_24 ;
F_80 ( V_2 , V_78 , 1 ) ;
F_80 ( V_2 , V_79 , 1 ) ;
V_2 -> V_37 = 0 ;
V_18 = V_2 ;
F_81 ( V_2 , F_11 ) ;
F_66 ( V_2 ) ;
V_80 = true ;
return 0 ;
}
static int F_82 ( struct V_1 * V_2 )
{
if ( V_80 )
return - V_81 ;
V_69 = 0 ;
V_70 = 0 ;
return F_79 ( V_2 ) ;
}
static int F_83 ( struct V_1 * V_2 )
{
if ( V_80 )
return - V_81 ;
V_69 = 0 ;
V_70 = 1 ;
return F_79 ( V_2 ) ;
}
static int F_84 ( struct V_1 * V_2 )
{
if ( V_80 )
return - V_81 ;
V_69 = 1 ;
V_70 = 0 ;
return F_79 ( V_2 ) ;
}
static void F_85 ( struct V_1 * V_2 )
{
int V_82 = V_77 & V_79 ;
int V_83 = V_77 & V_78 ;
F_76 ( V_2 ) ;
F_29 ( V_2 ) ;
F_80 ( V_2 , V_79 , V_82 ) ;
F_80 ( V_2 , V_78 , V_83 ) ;
F_86 ( V_2 ) ;
V_80 = false ;
}
static void F_87 ( struct V_1 * V_2 )
{
F_29 ( V_2 ) ;
V_32 = 1 ;
}
static void F_88 ( struct V_1 * V_2 )
{
V_32 = 0 ;
}
T_4 static int F_89 ( void )
{
int V_22 ;
V_22 = F_90 ( & V_84 ) ;
if ( V_22 )
return V_22 ;
V_22 = F_90 ( & V_85 ) ;
if ( V_22 )
return V_22 ;
V_22 = F_90 ( & V_86 ) ;
if ( V_22 )
return V_22 ;
return 0 ;
}
