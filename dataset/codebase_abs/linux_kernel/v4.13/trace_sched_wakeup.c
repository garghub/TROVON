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
if ( F_31 ( V_36 ) )
return 0 ;
if ( F_32 ( V_36 -> V_37 ) )
return 1 ;
if ( ! F_2 ( V_2 , & V_5 , & V_6 ) )
return 0 ;
F_33 ( V_20 ) ;
V_22 = F_34 ( V_2 , V_36 , V_20 , V_6 ) ;
F_10 ( & V_5 -> V_7 ) ;
F_11 () ;
return V_22 ;
}
static void V_26 ( struct V_38 * V_36 )
{
struct V_1 * V_2 = V_19 ;
struct V_4 * V_5 ;
unsigned long V_20 ;
int V_6 ;
if ( ! F_2 ( V_2 , & V_5 , & V_6 ) )
return;
F_33 ( V_20 ) ;
F_35 ( V_2 , V_36 , V_20 , V_6 ) ;
F_10 ( & V_5 -> V_7 ) ;
F_11 () ;
return;
}
static void F_36 ( struct V_39 * V_40 )
{
if ( F_23 ( V_40 -> V_2 ) )
F_37 ( V_40 ) ;
}
static void F_38 ( struct V_39 * V_40 )
{
if ( V_40 -> V_41 )
F_39 ( V_40 ) ;
}
static enum V_42 F_40 ( struct V_39 * V_40 )
{
if ( F_23 ( V_40 -> V_2 ) )
return F_41 ( V_40 , V_43 ) ;
return V_44 ;
}
static void F_42 ( struct V_45 * V_46 )
{
if ( F_23 ( V_19 ) )
F_43 ( V_46 , V_43 ) ;
else
F_44 ( V_46 ) ;
}
static void
F_45 ( struct V_1 * V_2 ,
unsigned long V_14 , unsigned long V_15 ,
unsigned long V_20 , int V_6 )
{
if ( F_23 ( V_2 ) )
F_46 ( V_2 , V_14 , V_15 , V_20 , V_6 ) ;
else
F_14 ( V_2 , V_14 , V_15 , V_20 , V_6 ) ;
}
static enum V_42 F_40 ( struct V_39 * V_40 )
{
return V_44 ;
}
static void F_36 ( struct V_39 * V_40 ) { }
static void F_38 ( struct V_39 * V_40 ) { }
static int V_27 ( struct V_35 * V_36 )
{
return - 1 ;
}
static void V_26 ( struct V_38 * V_36 ) { }
static void F_42 ( struct V_45 * V_46 )
{
F_44 ( V_46 ) ;
}
static void F_42 ( struct V_45 * V_46 )
{
F_47 ( V_46 ) ;
}
static bool F_48 ( struct V_1 * V_2 , T_2 V_47 )
{
if ( V_48 ) {
if ( V_47 < V_48 )
return false ;
} else {
if ( V_47 <= V_2 -> V_34 )
return false ;
}
return true ;
}
static void
F_49 ( void * V_49 , struct V_50 * V_51 , int V_8 )
{
if ( V_51 != V_9 )
return;
V_10 = V_8 ;
}
static void
F_50 ( struct V_1 * V_2 ,
struct V_50 * V_52 ,
struct V_50 * V_53 ,
unsigned long V_20 , int V_6 )
{
struct V_54 * V_55 = & V_56 ;
struct V_57 * V_58 = V_2 -> V_12 . V_58 ;
struct V_59 * V_60 ;
struct V_61 * V_62 ;
V_60 = F_51 ( V_58 , V_63 ,
sizeof( * V_62 ) , V_20 , V_6 ) ;
if ( ! V_60 )
return;
V_62 = F_52 ( V_60 ) ;
V_62 -> V_64 = V_52 -> V_65 ;
V_62 -> V_66 = V_52 -> V_67 ;
V_62 -> V_68 = V_52 -> V_69 ;
V_62 -> V_70 = V_53 -> V_65 ;
V_62 -> V_71 = V_53 -> V_67 ;
V_62 -> V_72 = V_53 -> V_69 ;
V_62 -> V_73 = F_53 ( V_53 ) ;
if ( ! F_54 ( V_55 , V_62 , V_58 , V_60 ) )
F_55 ( V_2 , V_58 , V_60 , V_20 , V_6 ) ;
}
static void
F_56 ( struct V_1 * V_2 ,
struct V_50 * V_74 ,
struct V_50 * V_75 ,
unsigned long V_20 , int V_6 )
{
struct V_54 * V_55 = & V_76 ;
struct V_59 * V_60 ;
struct V_61 * V_62 ;
struct V_57 * V_58 = V_2 -> V_12 . V_58 ;
V_60 = F_51 ( V_58 , V_77 ,
sizeof( * V_62 ) , V_20 , V_6 ) ;
if ( ! V_60 )
return;
V_62 = F_52 ( V_60 ) ;
V_62 -> V_64 = V_75 -> V_65 ;
V_62 -> V_66 = V_75 -> V_67 ;
V_62 -> V_68 = V_75 -> V_69 ;
V_62 -> V_70 = V_74 -> V_65 ;
V_62 -> V_71 = V_74 -> V_67 ;
V_62 -> V_72 = V_74 -> V_69 ;
V_62 -> V_73 = F_53 ( V_74 ) ;
if ( ! F_54 ( V_55 , V_62 , V_58 , V_60 ) )
F_55 ( V_2 , V_58 , V_60 , V_20 , V_6 ) ;
}
static void T_3
F_57 ( void * V_49 , bool V_78 ,
struct V_50 * V_52 , struct V_50 * V_53 )
{
struct V_4 * V_5 ;
T_2 V_79 , V_80 , V_47 ;
unsigned long V_20 ;
long V_7 ;
int V_8 ;
int V_6 ;
F_58 ( V_52 ) ;
if ( F_9 ( ! V_33 ) )
return;
F_59 () ;
if ( V_53 != V_9 )
return;
V_6 = F_4 () ;
V_8 = F_6 () ;
V_7 = F_8 ( & F_7 ( V_19 -> V_12 . V_5 , V_8 ) -> V_7 ) ;
if ( F_3 ( V_7 != 1 ) )
goto V_13;
F_13 ( V_20 ) ;
F_60 ( & V_81 ) ;
if ( F_9 ( ! V_33 || V_53 != V_9 ) )
goto V_82;
V_5 = F_7 ( V_19 -> V_12 . V_5 , V_83 ) ;
F_45 ( V_19 , V_84 , V_85 , V_20 , V_6 ) ;
F_50 ( V_19 , V_52 , V_53 , V_20 , V_6 ) ;
V_79 = V_5 -> V_86 ;
V_80 = F_61 ( V_8 ) ;
V_47 = V_80 - V_79 ;
if ( ! F_48 ( V_19 , V_47 ) )
goto V_82;
if ( F_3 ( ! F_62 () ) ) {
V_19 -> V_34 = V_47 ;
F_63 ( V_19 , V_9 , V_83 ) ;
}
V_82:
F_64 ( V_19 ) ;
F_65 ( & V_81 ) ;
F_15 ( V_20 ) ;
V_13:
F_10 ( & F_7 ( V_19 -> V_12 . V_5 , V_8 ) -> V_7 ) ;
}
static void F_64 ( struct V_1 * V_2 )
{
V_83 = - 1 ;
V_87 = - 1 ;
V_88 = 0 ;
if ( V_9 )
F_66 ( V_9 ) ;
V_9 = NULL ;
}
static void F_30 ( struct V_1 * V_2 )
{
unsigned long V_20 ;
F_67 ( & V_2 -> V_12 ) ;
F_13 ( V_20 ) ;
F_60 ( & V_81 ) ;
F_64 ( V_2 ) ;
F_65 ( & V_81 ) ;
F_15 ( V_20 ) ;
}
static void
F_68 ( void * V_49 , struct V_50 * V_89 )
{
struct V_4 * V_5 ;
int V_8 = F_69 () ;
unsigned long V_20 ;
long V_7 ;
int V_6 ;
if ( F_3 ( ! V_33 ) )
return;
F_58 ( V_89 ) ;
F_58 ( V_90 ) ;
if ( V_88 || ( V_91 && ! F_70 ( V_89 ) ) ||
( V_92 && ! F_70 ( V_89 ) && ! F_71 ( V_89 ) ) ||
( ! F_70 ( V_89 ) && ( V_89 -> V_67 >= V_87 || V_89 -> V_67 >= V_90 -> V_67 ) ) )
return;
V_6 = F_4 () ;
V_7 = F_8 ( & F_7 ( V_19 -> V_12 . V_5 , V_8 ) -> V_7 ) ;
if ( F_9 ( V_7 != 1 ) )
goto V_13;
F_60 ( & V_81 ) ;
if ( ! V_33 || V_88 ||
( ! F_70 ( V_89 ) && V_89 -> V_67 >= V_87 ) )
goto V_93;
F_64 ( V_19 ) ;
V_83 = F_53 ( V_89 ) ;
V_10 = V_83 ;
V_87 = V_89 -> V_67 ;
if ( F_70 ( V_89 ) )
V_88 = 1 ;
else
V_88 = 0 ;
V_9 = V_89 ;
F_72 ( V_9 ) ;
F_33 ( V_20 ) ;
V_5 = F_7 ( V_19 -> V_12 . V_5 , V_83 ) ;
V_5 -> V_86 = F_61 ( V_8 ) ;
F_56 ( V_19 , V_89 , V_90 , V_20 , V_6 ) ;
F_45 ( V_19 , V_85 , V_94 , V_20 , V_6 ) ;
V_93:
F_65 ( & V_81 ) ;
V_13:
F_10 ( & F_7 ( V_19 -> V_12 . V_5 , V_8 ) -> V_7 ) ;
}
static void F_73 ( struct V_1 * V_2 )
{
int V_22 ;
V_22 = F_74 ( F_68 , NULL ) ;
if ( V_22 ) {
F_75 ( L_1
L_2 ) ;
return;
}
V_22 = F_76 ( F_68 , NULL ) ;
if ( V_22 ) {
F_75 ( L_1
L_3 ) ;
goto V_95;
}
V_22 = F_77 ( F_57 , NULL ) ;
if ( V_22 ) {
F_75 ( L_4
L_5 ) ;
goto V_96;
}
V_22 = F_78 ( F_49 , NULL ) ;
if ( V_22 ) {
F_75 ( L_1
L_6 ) ;
return;
}
F_30 ( V_2 ) ;
F_79 () ;
if ( F_27 ( V_2 , F_23 ( V_2 ) ) )
F_80 ( V_97 L_7 ) ;
return;
V_96:
F_81 ( F_68 , NULL ) ;
V_95:
F_82 ( F_68 , NULL ) ;
}
static void F_83 ( struct V_1 * V_2 )
{
V_33 = 0 ;
F_29 ( V_2 , F_23 ( V_2 ) ) ;
F_84 ( F_57 , NULL ) ;
F_81 ( F_68 , NULL ) ;
F_82 ( F_68 , NULL ) ;
F_85 ( F_49 , NULL ) ;
}
static int F_86 ( struct V_1 * V_2 )
{
V_98 = V_2 -> V_24 ;
F_87 ( V_2 , V_99 , 1 ) ;
F_87 ( V_2 , V_100 , 1 ) ;
V_2 -> V_34 = 0 ;
V_19 = V_2 ;
F_88 ( V_2 , F_12 ) ;
F_73 ( V_2 ) ;
V_101 = true ;
return 0 ;
}
static int F_89 ( struct V_1 * V_2 )
{
if ( V_101 )
return - V_102 ;
V_91 = 0 ;
V_92 = 0 ;
return F_86 ( V_2 ) ;
}
static int F_90 ( struct V_1 * V_2 )
{
if ( V_101 )
return - V_102 ;
V_91 = 0 ;
V_92 = 1 ;
return F_86 ( V_2 ) ;
}
static int F_91 ( struct V_1 * V_2 )
{
if ( V_101 )
return - V_102 ;
V_91 = 1 ;
V_92 = 0 ;
return F_86 ( V_2 ) ;
}
static void F_92 ( struct V_1 * V_2 )
{
int V_103 = V_98 & V_100 ;
int V_104 = V_98 & V_99 ;
F_83 ( V_2 ) ;
F_30 ( V_2 ) ;
F_87 ( V_2 , V_100 , V_103 ) ;
F_87 ( V_2 , V_99 , V_104 ) ;
F_93 ( V_2 ) ;
V_101 = false ;
}
static void F_94 ( struct V_1 * V_2 )
{
F_30 ( V_2 ) ;
V_33 = 1 ;
}
static void F_95 ( struct V_1 * V_2 )
{
V_33 = 0 ;
}
T_4 static int F_96 ( void )
{
int V_22 ;
V_22 = F_97 ( & V_105 ) ;
if ( V_22 )
return V_22 ;
V_22 = F_97 ( & V_106 ) ;
if ( V_22 )
return V_22 ;
V_22 = F_97 ( & V_107 ) ;
if ( V_22 )
return V_22 ;
return 0 ;
}
