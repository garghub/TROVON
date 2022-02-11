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
static int F_15 ( int V_20 , int V_21 )
{
int V_22 ;
if ( V_23 || ( ! V_21 && ! ( V_24 & V_25 ) ) )
return 0 ;
if ( V_20 )
V_22 = F_16 ( & V_26 ,
& V_27 ) ;
else
V_22 = F_17 ( & V_28 ) ;
if ( ! V_22 )
V_23 = true ;
return V_22 ;
}
static void F_18 ( int V_20 )
{
if ( ! V_23 )
return;
if ( V_20 )
F_19 () ;
else
F_20 ( & V_28 ) ;
V_23 = false ;
}
static void F_21 ( int V_21 )
{
if ( V_21 )
F_15 ( F_22 () , 1 ) ;
else
F_18 ( F_22 () ) ;
}
static int F_23 ( struct V_29 * V_29 , T_1 V_30 , int V_21 )
{
if ( V_30 & V_25 )
F_21 ( V_21 ) ;
return F_24 ( V_29 , V_30 , V_21 ) ;
}
static int F_25 ( int V_20 )
{
int V_22 ;
V_22 = F_15 ( V_20 , 0 ) ;
if ( ! V_22 && F_26 () )
V_31 = 1 ;
else
V_31 = 0 ;
return V_22 ;
}
static void F_27 ( int V_20 )
{
V_31 = 0 ;
F_18 ( V_20 ) ;
}
static int F_28 ( T_1 V_32 , T_1 V_33 , int V_21 )
{
if ( ! ( V_33 & V_34 ) )
return - V_35 ;
if ( ! ( F_22 () ^ V_21 ) )
return 0 ;
F_27 ( ! V_21 ) ;
F_29 ( V_18 ) ;
V_36 = 0 ;
return F_25 ( V_21 ) ;
}
static int V_27 ( struct V_37 * V_38 )
{
struct V_1 * V_2 = V_18 ;
struct V_3 * V_4 ;
unsigned long V_19 ;
int V_5 , V_22 = 0 ;
if ( ! F_1 ( V_2 , & V_4 , & V_5 ) )
return 0 ;
F_30 ( V_19 ) ;
V_22 = F_31 ( V_2 , V_38 , V_19 , V_5 ) ;
F_9 ( & V_4 -> V_6 ) ;
F_10 () ;
return V_22 ;
}
static void V_26 ( struct V_39 * V_38 )
{
struct V_1 * V_2 = V_18 ;
struct V_3 * V_4 ;
unsigned long V_19 ;
int V_5 ;
if ( ! F_1 ( V_2 , & V_4 , & V_5 ) )
return;
F_30 ( V_19 ) ;
F_32 ( V_2 , V_38 , V_19 , V_5 ) ;
F_9 ( & V_4 -> V_6 ) ;
F_10 () ;
return;
}
static void F_33 ( struct V_40 * V_41 )
{
if ( F_22 () )
F_34 ( V_41 ) ;
}
static void F_35 ( struct V_40 * V_41 )
{
if ( V_41 -> V_42 )
F_36 ( V_41 ) ;
}
static enum V_43 F_37 ( struct V_40 * V_41 )
{
if ( F_22 () )
return F_38 ( V_41 , V_44 ) ;
return V_45 ;
}
static void F_39 ( struct V_46 * V_47 )
{
if ( F_22 () )
F_40 ( V_47 , V_44 ) ;
else
F_41 ( V_47 ) ;
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
static int F_28 ( T_1 V_32 , T_1 V_33 , int V_21 )
{
return - V_35 ;
}
static int V_27 ( struct V_37 * V_38 )
{
return - 1 ;
}
static enum V_43 F_37 ( struct V_40 * V_41 )
{
return V_45 ;
}
static void V_26 ( struct V_39 * V_38 ) { }
static void F_33 ( struct V_40 * V_41 ) { }
static void F_35 ( struct V_40 * V_41 ) { }
static void F_39 ( struct V_46 * V_47 )
{
F_41 ( V_47 ) ;
}
static void F_39 ( struct V_46 * V_47 )
{
F_44 ( V_47 ) ;
}
static int F_45 ( T_2 V_48 )
{
if ( V_49 ) {
if ( V_48 < V_49 )
return 0 ;
} else {
if ( V_48 <= V_36 )
return 0 ;
}
return 1 ;
}
static void
F_46 ( void * V_50 , struct V_51 * V_52 , int V_7 )
{
if ( V_52 != V_8 )
return;
V_9 = V_7 ;
}
static void T_3
F_47 ( void * V_50 ,
struct V_51 * V_53 , struct V_51 * V_54 )
{
struct V_3 * V_4 ;
T_2 V_55 , V_56 , V_48 ;
unsigned long V_19 ;
long V_6 ;
int V_7 ;
int V_5 ;
F_48 ( V_53 ) ;
if ( F_8 ( ! V_31 ) )
return;
F_49 () ;
if ( V_54 != V_8 )
return;
V_5 = F_3 () ;
V_7 = F_5 () ;
V_6 = F_7 ( & F_6 ( V_18 -> V_11 . V_4 , V_7 ) -> V_6 ) ;
if ( F_2 ( V_6 != 1 ) )
goto V_12;
F_12 ( V_19 ) ;
F_50 ( & V_57 ) ;
if ( F_8 ( ! V_31 || V_54 != V_8 ) )
goto V_58;
V_4 = F_6 ( V_18 -> V_11 . V_4 , V_59 ) ;
F_42 ( V_18 , V_60 , V_61 , V_19 , V_5 ) ;
F_51 ( V_18 , V_53 , V_54 , V_19 , V_5 ) ;
V_55 = V_4 -> V_62 ;
V_56 = F_52 ( V_7 ) ;
V_48 = V_56 - V_55 ;
if ( ! F_45 ( V_48 ) )
goto V_58;
if ( F_2 ( ! F_53 () ) ) {
V_36 = V_48 ;
F_54 ( V_18 , V_8 , V_59 ) ;
}
V_58:
F_55 ( V_18 ) ;
F_56 ( & V_57 ) ;
F_14 ( V_19 ) ;
V_12:
F_9 ( & F_6 ( V_18 -> V_11 . V_4 , V_7 ) -> V_6 ) ;
}
static void F_55 ( struct V_1 * V_2 )
{
V_59 = - 1 ;
V_63 = - 1 ;
V_64 = 0 ;
if ( V_8 )
F_57 ( V_8 ) ;
V_8 = NULL ;
}
static void F_29 ( struct V_1 * V_2 )
{
unsigned long V_19 ;
F_58 ( & V_2 -> V_11 ) ;
F_12 ( V_19 ) ;
F_50 ( & V_57 ) ;
F_55 ( V_2 ) ;
F_56 ( & V_57 ) ;
F_14 ( V_19 ) ;
}
static void
F_59 ( void * V_50 , struct V_51 * V_65 , int V_66 )
{
struct V_3 * V_4 ;
int V_7 = F_60 () ;
unsigned long V_19 ;
long V_6 ;
int V_5 ;
if ( F_2 ( ! V_31 ) )
return;
F_48 ( V_65 ) ;
F_48 ( V_67 ) ;
if ( V_64 || ( V_68 && ! F_61 ( V_65 ) ) ||
( V_69 && ! F_61 ( V_65 ) && ! F_62 ( V_65 ) ) ||
( ! F_61 ( V_65 ) && ( V_65 -> V_70 >= V_63 || V_65 -> V_70 >= V_67 -> V_70 ) ) )
return;
V_5 = F_3 () ;
V_6 = F_7 ( & F_6 ( V_18 -> V_11 . V_4 , V_7 ) -> V_6 ) ;
if ( F_8 ( V_6 != 1 ) )
goto V_12;
F_50 ( & V_57 ) ;
if ( ! V_31 || V_64 ||
( ! F_61 ( V_65 ) && V_65 -> V_70 >= V_63 ) )
goto V_71;
F_55 ( V_18 ) ;
V_59 = F_63 ( V_65 ) ;
V_9 = V_59 ;
V_63 = V_65 -> V_70 ;
if ( F_61 ( V_65 ) )
V_64 = 1 ;
else
V_64 = 0 ;
V_8 = V_65 ;
F_64 ( V_8 ) ;
F_30 ( V_19 ) ;
V_4 = F_6 ( V_18 -> V_11 . V_4 , V_59 ) ;
V_4 -> V_62 = F_52 ( V_7 ) ;
F_65 ( V_18 , V_65 , V_67 , V_19 , V_5 ) ;
F_42 ( V_18 , V_61 , V_72 , V_19 , V_5 ) ;
V_71:
F_56 ( & V_57 ) ;
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
goto V_73;
}
V_22 = F_70 ( F_47 , NULL ) ;
if ( V_22 ) {
F_68 ( L_4
L_5 ) ;
goto V_74;
}
V_22 = F_71 ( F_46 , NULL ) ;
if ( V_22 ) {
F_68 ( L_1
L_6 ) ;
return;
}
F_29 ( V_2 ) ;
F_72 () ;
if ( F_25 ( F_22 () ) )
F_73 ( V_75 L_7 ) ;
return;
V_74:
F_74 ( F_59 , NULL ) ;
V_73:
F_75 ( F_59 , NULL ) ;
}
static void F_76 ( struct V_1 * V_2 )
{
V_31 = 0 ;
F_27 ( F_22 () ) ;
F_77 ( F_47 , NULL ) ;
F_74 ( F_59 , NULL ) ;
F_75 ( F_59 , NULL ) ;
F_78 ( F_46 , NULL ) ;
}
static int F_79 ( struct V_1 * V_2 )
{
V_76 = V_24 ;
F_80 ( V_2 , V_77 , 1 ) ;
F_80 ( V_2 , V_78 , 1 ) ;
V_36 = 0 ;
V_18 = V_2 ;
F_66 ( V_2 ) ;
return 0 ;
}
static int F_81 ( struct V_1 * V_2 )
{
V_68 = 0 ;
V_69 = 0 ;
return F_79 ( V_2 ) ;
}
static int F_82 ( struct V_1 * V_2 )
{
V_68 = 0 ;
V_69 = 1 ;
return F_79 ( V_2 ) ;
}
static int F_83 ( struct V_1 * V_2 )
{
V_68 = 1 ;
V_69 = 0 ;
return F_79 ( V_2 ) ;
}
static void F_84 ( struct V_1 * V_2 )
{
int V_79 = V_76 & V_78 ;
int V_80 = V_76 & V_77 ;
F_76 ( V_2 ) ;
F_29 ( V_2 ) ;
F_80 ( V_2 , V_78 , V_79 ) ;
F_80 ( V_2 , V_77 , V_80 ) ;
}
static void F_85 ( struct V_1 * V_2 )
{
F_29 ( V_2 ) ;
V_31 = 1 ;
}
static void F_86 ( struct V_1 * V_2 )
{
V_31 = 0 ;
}
T_4 static int F_87 ( void )
{
int V_22 ;
V_22 = F_88 ( & V_81 ) ;
if ( V_22 )
return V_22 ;
V_22 = F_88 ( & V_82 ) ;
if ( V_22 )
return V_22 ;
V_22 = F_88 ( & V_83 ) ;
if ( V_22 )
return V_22 ;
return 0 ;
}
