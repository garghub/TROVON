static inline int F_1 ( struct V_1 * V_2 , int V_3 )
{
return 0 ;
}
static int
F_2 ( struct V_1 * V_2 ,
struct V_4 * * V_5 ,
int * V_6 )
{
long V_7 ;
int V_8 ;
if ( F_3 ( ! V_9 ) )
return 0 ;
* V_6 = F_4 () ;
F_5 () ;
V_8 = F_6 () ;
if ( V_8 != V_10 )
goto V_11;
* V_5 = F_7 ( V_2 -> V_12 . V_5 , V_8 ) ;
V_7 = F_8 ( & ( * V_5 ) -> V_7 ) ;
if ( F_9 ( V_7 != 1 ) )
goto V_13;
return 1 ;
V_13:
F_10 ( & ( * V_5 ) -> V_7 ) ;
V_11:
F_11 () ;
return 0 ;
}
static void
F_12 ( unsigned long V_14 , unsigned long V_15 ,
struct V_16 * V_17 , struct V_18 * V_18 )
{
struct V_1 * V_2 = V_19 ;
struct V_4 * V_5 ;
unsigned long V_20 ;
int V_6 ;
if ( ! F_2 ( V_2 , & V_5 , & V_6 ) )
return;
F_13 ( V_20 ) ;
F_14 ( V_2 , V_14 , V_15 , V_20 , V_6 ) ;
F_15 ( V_20 ) ;
F_10 ( & V_5 -> V_7 ) ;
F_11 () ;
}
static int F_16 ( struct V_1 * V_2 , int V_21 , int V_3 )
{
int V_22 ;
if ( V_23 || ( ! V_3 && ! ( V_2 -> V_24 & V_25 ) ) )
return 0 ;
if ( V_21 )
V_22 = F_17 ( & V_26 ,
& V_27 ) ;
else
V_22 = F_18 ( V_2 -> V_28 ) ;
if ( ! V_22 )
V_23 = true ;
return V_22 ;
}
static void F_19 ( struct V_1 * V_2 , int V_21 )
{
if ( ! V_23 )
return;
if ( V_21 )
F_20 () ;
else
F_21 ( V_2 -> V_28 ) ;
V_23 = false ;
}
static int F_22 ( struct V_1 * V_2 , T_1 V_29 , int V_3 )
{
if ( ! ( V_29 & V_25 ) )
return 0 ;
if ( V_3 )
F_16 ( V_2 , F_23 ( V_2 ) , 1 ) ;
else
F_19 ( V_2 , F_23 ( V_2 ) ) ;
return 1 ;
}
static int F_16 ( struct V_1 * V_2 , int V_21 , int V_3 )
{
return 0 ;
}
static void F_19 ( struct V_1 * V_2 , int V_21 ) { }
static int F_22 ( struct V_1 * V_2 , T_1 V_29 , int V_3 )
{
return 0 ;
}
static int F_24 ( struct V_1 * V_2 , T_1 V_29 , int V_3 )
{
struct V_30 * V_30 = V_2 -> V_31 ;
if ( F_22 ( V_2 , V_29 , V_3 ) )
return 0 ;
#ifdef F_25
if ( V_29 & V_32 )
return F_1 ( V_2 , V_3 ) ;
#endif
return F_26 ( V_30 , V_29 , V_3 ) ;
}
static int F_27 ( struct V_1 * V_2 , int V_21 )
{
int V_22 ;
V_22 = F_16 ( V_2 , V_21 , 0 ) ;
if ( ! V_22 && F_28 () )
V_33 = 1 ;
else
V_33 = 0 ;
return V_22 ;
}
static void F_29 ( struct V_1 * V_2 , int V_21 )
{
V_33 = 0 ;
F_19 ( V_2 , V_21 ) ;
}
static int F_1 ( struct V_1 * V_2 , int V_3 )
{
if ( ! ( F_23 ( V_2 ) ^ V_3 ) )
return 0 ;
F_29 ( V_2 , ! V_3 ) ;
F_30 ( V_19 ) ;
V_2 -> V_34 = 0 ;
return F_27 ( V_2 , V_3 ) ;
}
static int V_27 ( struct V_35 * V_36 )
{
struct V_1 * V_2 = V_19 ;
struct V_4 * V_5 ;
unsigned long V_20 ;
int V_6 , V_22 = 0 ;
if ( ! F_2 ( V_2 , & V_5 , & V_6 ) )
return 0 ;
F_31 ( V_20 ) ;
V_22 = F_32 ( V_2 , V_36 , V_20 , V_6 ) ;
F_10 ( & V_5 -> V_7 ) ;
F_11 () ;
return V_22 ;
}
static void V_26 ( struct V_37 * V_36 )
{
struct V_1 * V_2 = V_19 ;
struct V_4 * V_5 ;
unsigned long V_20 ;
int V_6 ;
if ( ! F_2 ( V_2 , & V_5 , & V_6 ) )
return;
F_31 ( V_20 ) ;
F_33 ( V_2 , V_36 , V_20 , V_6 ) ;
F_10 ( & V_5 -> V_7 ) ;
F_11 () ;
return;
}
static void F_34 ( struct V_38 * V_39 )
{
if ( F_23 ( V_39 -> V_2 ) )
F_35 ( V_39 ) ;
}
static void F_36 ( struct V_38 * V_39 )
{
if ( V_39 -> V_40 )
F_37 ( V_39 ) ;
}
static enum V_41 F_38 ( struct V_38 * V_39 )
{
if ( F_23 ( V_39 -> V_2 ) )
return F_39 ( V_39 , V_42 ) ;
return V_43 ;
}
static void F_40 ( struct V_44 * V_45 )
{
if ( F_23 ( V_19 ) )
F_41 ( V_45 , V_42 ) ;
else
F_42 ( V_45 ) ;
}
static void
F_43 ( struct V_1 * V_2 ,
unsigned long V_14 , unsigned long V_15 ,
unsigned long V_20 , int V_6 )
{
if ( F_23 ( V_2 ) )
F_44 ( V_2 , V_14 , V_15 , V_20 , V_6 ) ;
else
F_14 ( V_2 , V_14 , V_15 , V_20 , V_6 ) ;
}
static enum V_41 F_38 ( struct V_38 * V_39 )
{
return V_43 ;
}
static void F_34 ( struct V_38 * V_39 ) { }
static void F_36 ( struct V_38 * V_39 ) { }
static int V_27 ( struct V_35 * V_36 )
{
return - 1 ;
}
static void V_26 ( struct V_37 * V_36 ) { }
static void F_40 ( struct V_44 * V_45 )
{
F_42 ( V_45 ) ;
}
static void F_40 ( struct V_44 * V_45 )
{
F_45 ( V_45 ) ;
}
static bool F_46 ( struct V_1 * V_2 , T_2 V_46 )
{
if ( V_47 ) {
if ( V_46 < V_47 )
return false ;
} else {
if ( V_46 <= V_2 -> V_34 )
return false ;
}
return true ;
}
static void
F_47 ( void * V_48 , struct V_49 * V_50 , int V_8 )
{
if ( V_50 != V_9 )
return;
V_10 = V_8 ;
}
static void
F_48 ( struct V_1 * V_2 ,
struct V_49 * V_51 ,
struct V_49 * V_52 ,
unsigned long V_20 , int V_6 )
{
struct V_53 * V_54 = & V_55 ;
struct V_56 * V_57 = V_2 -> V_12 . V_57 ;
struct V_58 * V_59 ;
struct V_60 * V_61 ;
V_59 = F_49 ( V_57 , V_62 ,
sizeof( * V_61 ) , V_20 , V_6 ) ;
if ( ! V_59 )
return;
V_61 = F_50 ( V_59 ) ;
V_61 -> V_63 = V_51 -> V_64 ;
V_61 -> V_65 = V_51 -> V_66 ;
V_61 -> V_67 = V_51 -> V_68 ;
V_61 -> V_69 = V_52 -> V_64 ;
V_61 -> V_70 = V_52 -> V_66 ;
V_61 -> V_71 = V_52 -> V_68 ;
V_61 -> V_72 = F_51 ( V_52 ) ;
if ( ! F_52 ( V_54 , V_61 , V_57 , V_59 ) )
F_53 ( V_2 , V_57 , V_59 , V_20 , V_6 ) ;
}
static void
F_54 ( struct V_1 * V_2 ,
struct V_49 * V_73 ,
struct V_49 * V_74 ,
unsigned long V_20 , int V_6 )
{
struct V_53 * V_54 = & V_75 ;
struct V_58 * V_59 ;
struct V_60 * V_61 ;
struct V_56 * V_57 = V_2 -> V_12 . V_57 ;
V_59 = F_49 ( V_57 , V_76 ,
sizeof( * V_61 ) , V_20 , V_6 ) ;
if ( ! V_59 )
return;
V_61 = F_50 ( V_59 ) ;
V_61 -> V_63 = V_74 -> V_64 ;
V_61 -> V_65 = V_74 -> V_66 ;
V_61 -> V_67 = V_74 -> V_68 ;
V_61 -> V_69 = V_73 -> V_64 ;
V_61 -> V_70 = V_73 -> V_66 ;
V_61 -> V_71 = V_73 -> V_68 ;
V_61 -> V_72 = F_51 ( V_73 ) ;
if ( ! F_52 ( V_54 , V_61 , V_57 , V_59 ) )
F_53 ( V_2 , V_57 , V_59 , V_20 , V_6 ) ;
}
static void T_3
F_55 ( void * V_48 , bool V_77 ,
struct V_49 * V_51 , struct V_49 * V_52 )
{
struct V_4 * V_5 ;
T_2 V_78 , V_79 , V_46 ;
unsigned long V_20 ;
long V_7 ;
int V_8 ;
int V_6 ;
F_56 ( V_51 ) ;
if ( F_9 ( ! V_33 ) )
return;
F_57 () ;
if ( V_52 != V_9 )
return;
V_6 = F_4 () ;
V_8 = F_6 () ;
V_7 = F_8 ( & F_7 ( V_19 -> V_12 . V_5 , V_8 ) -> V_7 ) ;
if ( F_3 ( V_7 != 1 ) )
goto V_13;
F_13 ( V_20 ) ;
F_58 ( & V_80 ) ;
if ( F_9 ( ! V_33 || V_52 != V_9 ) )
goto V_81;
V_5 = F_7 ( V_19 -> V_12 . V_5 , V_82 ) ;
F_43 ( V_19 , V_83 , V_84 , V_20 , V_6 ) ;
F_48 ( V_19 , V_51 , V_52 , V_20 , V_6 ) ;
V_78 = V_5 -> V_85 ;
V_79 = F_59 ( V_8 ) ;
V_46 = V_79 - V_78 ;
if ( ! F_46 ( V_19 , V_46 ) )
goto V_81;
if ( F_3 ( ! F_60 () ) ) {
V_19 -> V_34 = V_46 ;
F_61 ( V_19 , V_9 , V_82 ) ;
}
V_81:
F_62 ( V_19 ) ;
F_63 ( & V_80 ) ;
F_15 ( V_20 ) ;
V_13:
F_10 ( & F_7 ( V_19 -> V_12 . V_5 , V_8 ) -> V_7 ) ;
}
static void F_62 ( struct V_1 * V_2 )
{
V_82 = - 1 ;
V_86 = - 1 ;
V_87 = 0 ;
if ( V_9 )
F_64 ( V_9 ) ;
V_9 = NULL ;
}
static void F_30 ( struct V_1 * V_2 )
{
unsigned long V_20 ;
F_65 ( & V_2 -> V_12 ) ;
F_13 ( V_20 ) ;
F_58 ( & V_80 ) ;
F_62 ( V_2 ) ;
F_63 ( & V_80 ) ;
F_15 ( V_20 ) ;
}
static void
F_66 ( void * V_48 , struct V_49 * V_88 )
{
struct V_4 * V_5 ;
int V_8 = F_67 () ;
unsigned long V_20 ;
long V_7 ;
int V_6 ;
if ( F_3 ( ! V_33 ) )
return;
F_56 ( V_88 ) ;
F_56 ( V_89 ) ;
if ( V_87 || ( V_90 && ! F_68 ( V_88 ) ) ||
( V_91 && ! F_68 ( V_88 ) && ! F_69 ( V_88 ) ) ||
( ! F_68 ( V_88 ) && ( V_88 -> V_66 >= V_86 || V_88 -> V_66 >= V_89 -> V_66 ) ) )
return;
V_6 = F_4 () ;
V_7 = F_8 ( & F_7 ( V_19 -> V_12 . V_5 , V_8 ) -> V_7 ) ;
if ( F_9 ( V_7 != 1 ) )
goto V_13;
F_58 ( & V_80 ) ;
if ( ! V_33 || V_87 ||
( ! F_68 ( V_88 ) && V_88 -> V_66 >= V_86 ) )
goto V_92;
F_62 ( V_19 ) ;
V_82 = F_51 ( V_88 ) ;
V_10 = V_82 ;
V_86 = V_88 -> V_66 ;
if ( F_68 ( V_88 ) )
V_87 = 1 ;
else
V_87 = 0 ;
V_9 = V_88 ;
F_70 ( V_9 ) ;
F_31 ( V_20 ) ;
V_5 = F_7 ( V_19 -> V_12 . V_5 , V_82 ) ;
V_5 -> V_85 = F_59 ( V_8 ) ;
F_54 ( V_19 , V_88 , V_89 , V_20 , V_6 ) ;
F_43 ( V_19 , V_84 , V_93 , V_20 , V_6 ) ;
V_92:
F_63 ( & V_80 ) ;
V_13:
F_10 ( & F_7 ( V_19 -> V_12 . V_5 , V_8 ) -> V_7 ) ;
}
static void F_71 ( struct V_1 * V_2 )
{
int V_22 ;
V_22 = F_72 ( F_66 , NULL ) ;
if ( V_22 ) {
F_73 ( L_1
L_2 ) ;
return;
}
V_22 = F_74 ( F_66 , NULL ) ;
if ( V_22 ) {
F_73 ( L_1
L_3 ) ;
goto V_94;
}
V_22 = F_75 ( F_55 , NULL ) ;
if ( V_22 ) {
F_73 ( L_4
L_5 ) ;
goto V_95;
}
V_22 = F_76 ( F_47 , NULL ) ;
if ( V_22 ) {
F_73 ( L_1
L_6 ) ;
return;
}
F_30 ( V_2 ) ;
F_77 () ;
if ( F_27 ( V_2 , F_23 ( V_2 ) ) )
F_78 ( V_96 L_7 ) ;
return;
V_95:
F_79 ( F_66 , NULL ) ;
V_94:
F_80 ( F_66 , NULL ) ;
}
static void F_81 ( struct V_1 * V_2 )
{
V_33 = 0 ;
F_29 ( V_2 , F_23 ( V_2 ) ) ;
F_82 ( F_55 , NULL ) ;
F_79 ( F_66 , NULL ) ;
F_80 ( F_66 , NULL ) ;
F_83 ( F_47 , NULL ) ;
}
static int F_84 ( struct V_1 * V_2 )
{
V_97 = V_2 -> V_24 ;
F_85 ( V_2 , V_98 , 1 ) ;
F_85 ( V_2 , V_99 , 1 ) ;
V_2 -> V_34 = 0 ;
V_19 = V_2 ;
F_86 ( V_2 , F_12 ) ;
F_71 ( V_2 ) ;
V_100 = true ;
return 0 ;
}
static int F_87 ( struct V_1 * V_2 )
{
if ( V_100 )
return - V_101 ;
V_90 = 0 ;
V_91 = 0 ;
return F_84 ( V_2 ) ;
}
static int F_88 ( struct V_1 * V_2 )
{
if ( V_100 )
return - V_101 ;
V_90 = 0 ;
V_91 = 1 ;
return F_84 ( V_2 ) ;
}
static int F_89 ( struct V_1 * V_2 )
{
if ( V_100 )
return - V_101 ;
V_90 = 1 ;
V_91 = 0 ;
return F_84 ( V_2 ) ;
}
static void F_90 ( struct V_1 * V_2 )
{
int V_102 = V_97 & V_99 ;
int V_103 = V_97 & V_98 ;
F_81 ( V_2 ) ;
F_30 ( V_2 ) ;
F_85 ( V_2 , V_99 , V_102 ) ;
F_85 ( V_2 , V_98 , V_103 ) ;
F_91 ( V_2 ) ;
V_100 = false ;
}
static void F_92 ( struct V_1 * V_2 )
{
F_30 ( V_2 ) ;
V_33 = 1 ;
}
static void F_93 ( struct V_1 * V_2 )
{
V_33 = 0 ;
}
T_4 static int F_94 ( void )
{
int V_22 ;
V_22 = F_95 ( & V_104 ) ;
if ( V_22 )
return V_22 ;
V_22 = F_95 ( & V_105 ) ;
if ( V_22 )
return V_22 ;
V_22 = F_95 ( & V_106 ) ;
if ( V_22 )
return V_22 ;
return 0 ;
}
