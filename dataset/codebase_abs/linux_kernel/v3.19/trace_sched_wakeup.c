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
static void
F_47 ( struct V_1 * V_2 ,
struct V_52 * V_54 ,
struct V_52 * V_55 ,
unsigned long V_19 , int V_5 )
{
struct V_56 * V_57 = & V_58 ;
struct V_59 * V_60 = V_2 -> V_11 . V_60 ;
struct V_61 * V_62 ;
struct V_63 * V_64 ;
V_62 = F_48 ( V_60 , V_65 ,
sizeof( * V_64 ) , V_19 , V_5 ) ;
if ( ! V_62 )
return;
V_64 = F_49 ( V_62 ) ;
V_64 -> V_66 = V_54 -> V_67 ;
V_64 -> V_68 = V_54 -> V_69 ;
V_64 -> V_70 = V_54 -> V_71 ;
V_64 -> V_72 = V_55 -> V_67 ;
V_64 -> V_73 = V_55 -> V_69 ;
V_64 -> V_74 = V_55 -> V_71 ;
V_64 -> V_75 = F_50 ( V_55 ) ;
if ( ! F_51 ( V_57 , V_64 , V_60 , V_62 ) )
F_52 ( V_60 , V_62 , V_19 , V_5 ) ;
}
static void
F_53 ( struct V_1 * V_2 ,
struct V_52 * V_76 ,
struct V_52 * V_77 ,
unsigned long V_19 , int V_5 )
{
struct V_56 * V_57 = & V_78 ;
struct V_61 * V_62 ;
struct V_63 * V_64 ;
struct V_59 * V_60 = V_2 -> V_11 . V_60 ;
V_62 = F_48 ( V_60 , V_79 ,
sizeof( * V_64 ) , V_19 , V_5 ) ;
if ( ! V_62 )
return;
V_64 = F_49 ( V_62 ) ;
V_64 -> V_66 = V_77 -> V_67 ;
V_64 -> V_68 = V_77 -> V_69 ;
V_64 -> V_70 = V_77 -> V_71 ;
V_64 -> V_72 = V_76 -> V_67 ;
V_64 -> V_73 = V_76 -> V_69 ;
V_64 -> V_74 = V_76 -> V_71 ;
V_64 -> V_75 = F_50 ( V_76 ) ;
if ( ! F_51 ( V_57 , V_64 , V_60 , V_62 ) )
F_52 ( V_60 , V_62 , V_19 , V_5 ) ;
}
static void T_3
F_54 ( void * V_51 ,
struct V_52 * V_54 , struct V_52 * V_55 )
{
struct V_3 * V_4 ;
T_2 V_80 , V_81 , V_49 ;
unsigned long V_19 ;
long V_6 ;
int V_7 ;
int V_5 ;
F_55 ( V_54 ) ;
if ( F_8 ( ! V_32 ) )
return;
F_56 () ;
if ( V_55 != V_8 )
return;
V_5 = F_3 () ;
V_7 = F_5 () ;
V_6 = F_7 ( & F_6 ( V_18 -> V_11 . V_4 , V_7 ) -> V_6 ) ;
if ( F_2 ( V_6 != 1 ) )
goto V_12;
F_12 ( V_19 ) ;
F_57 ( & V_82 ) ;
if ( F_8 ( ! V_32 || V_55 != V_8 ) )
goto V_83;
V_4 = F_6 ( V_18 -> V_11 . V_4 , V_84 ) ;
F_42 ( V_18 , V_85 , V_86 , V_19 , V_5 ) ;
F_47 ( V_18 , V_54 , V_55 , V_19 , V_5 ) ;
V_80 = V_4 -> V_87 ;
V_81 = F_58 ( V_7 ) ;
V_49 = V_81 - V_80 ;
if ( ! F_45 ( V_18 , V_49 ) )
goto V_83;
if ( F_2 ( ! F_59 () ) ) {
V_18 -> V_37 = V_49 ;
F_60 ( V_18 , V_8 , V_84 ) ;
}
V_83:
F_61 ( V_18 ) ;
F_62 ( & V_82 ) ;
F_14 ( V_19 ) ;
V_12:
F_9 ( & F_6 ( V_18 -> V_11 . V_4 , V_7 ) -> V_6 ) ;
}
static void F_61 ( struct V_1 * V_2 )
{
V_84 = - 1 ;
V_88 = - 1 ;
V_89 = 0 ;
if ( V_8 )
F_63 ( V_8 ) ;
V_8 = NULL ;
}
static void F_29 ( struct V_1 * V_2 )
{
unsigned long V_19 ;
F_64 ( & V_2 -> V_11 ) ;
F_12 ( V_19 ) ;
F_57 ( & V_82 ) ;
F_61 ( V_2 ) ;
F_62 ( & V_82 ) ;
F_14 ( V_19 ) ;
}
static void
F_65 ( void * V_51 , struct V_52 * V_90 , int V_91 )
{
struct V_3 * V_4 ;
int V_7 = F_66 () ;
unsigned long V_19 ;
long V_6 ;
int V_5 ;
if ( F_2 ( ! V_32 ) )
return;
F_55 ( V_90 ) ;
F_55 ( V_92 ) ;
if ( V_89 || ( V_93 && ! F_67 ( V_90 ) ) ||
( V_94 && ! F_67 ( V_90 ) && ! F_68 ( V_90 ) ) ||
( ! F_67 ( V_90 ) && ( V_90 -> V_69 >= V_88 || V_90 -> V_69 >= V_92 -> V_69 ) ) )
return;
V_5 = F_3 () ;
V_6 = F_7 ( & F_6 ( V_18 -> V_11 . V_4 , V_7 ) -> V_6 ) ;
if ( F_8 ( V_6 != 1 ) )
goto V_12;
F_57 ( & V_82 ) ;
if ( ! V_32 || V_89 ||
( ! F_67 ( V_90 ) && V_90 -> V_69 >= V_88 ) )
goto V_95;
F_61 ( V_18 ) ;
V_84 = F_50 ( V_90 ) ;
V_9 = V_84 ;
V_88 = V_90 -> V_69 ;
if ( F_67 ( V_90 ) )
V_89 = 1 ;
else
V_89 = 0 ;
V_8 = V_90 ;
F_69 ( V_8 ) ;
F_30 ( V_19 ) ;
V_4 = F_6 ( V_18 -> V_11 . V_4 , V_84 ) ;
V_4 -> V_87 = F_58 ( V_7 ) ;
F_53 ( V_18 , V_90 , V_92 , V_19 , V_5 ) ;
F_42 ( V_18 , V_86 , V_96 , V_19 , V_5 ) ;
V_95:
F_62 ( & V_82 ) ;
V_12:
F_9 ( & F_6 ( V_18 -> V_11 . V_4 , V_7 ) -> V_6 ) ;
}
static void F_70 ( struct V_1 * V_2 )
{
int V_22 ;
V_22 = F_71 ( F_65 , NULL ) ;
if ( V_22 ) {
F_72 ( L_1
L_2 ) ;
return;
}
V_22 = F_73 ( F_65 , NULL ) ;
if ( V_22 ) {
F_72 ( L_1
L_3 ) ;
goto V_97;
}
V_22 = F_74 ( F_54 , NULL ) ;
if ( V_22 ) {
F_72 ( L_4
L_5 ) ;
goto V_98;
}
V_22 = F_75 ( F_46 , NULL ) ;
if ( V_22 ) {
F_72 ( L_1
L_6 ) ;
return;
}
F_29 ( V_2 ) ;
F_76 () ;
if ( F_25 ( V_2 , F_22 () ) )
F_77 ( V_99 L_7 ) ;
return;
V_98:
F_78 ( F_65 , NULL ) ;
V_97:
F_79 ( F_65 , NULL ) ;
}
static void F_80 ( struct V_1 * V_2 )
{
V_32 = 0 ;
F_27 ( V_2 , F_22 () ) ;
F_81 ( F_54 , NULL ) ;
F_78 ( F_65 , NULL ) ;
F_79 ( F_65 , NULL ) ;
F_82 ( F_46 , NULL ) ;
}
static int F_83 ( struct V_1 * V_2 )
{
V_100 = V_24 ;
F_84 ( V_2 , V_101 , 1 ) ;
F_84 ( V_2 , V_102 , 1 ) ;
V_2 -> V_37 = 0 ;
V_18 = V_2 ;
F_85 ( V_2 , F_11 ) ;
F_70 ( V_2 ) ;
V_103 = true ;
return 0 ;
}
static int F_86 ( struct V_1 * V_2 )
{
if ( V_103 )
return - V_104 ;
V_93 = 0 ;
V_94 = 0 ;
return F_83 ( V_2 ) ;
}
static int F_87 ( struct V_1 * V_2 )
{
if ( V_103 )
return - V_104 ;
V_93 = 0 ;
V_94 = 1 ;
return F_83 ( V_2 ) ;
}
static int F_88 ( struct V_1 * V_2 )
{
if ( V_103 )
return - V_104 ;
V_93 = 1 ;
V_94 = 0 ;
return F_83 ( V_2 ) ;
}
static void F_89 ( struct V_1 * V_2 )
{
int V_105 = V_100 & V_102 ;
int V_106 = V_100 & V_101 ;
F_80 ( V_2 ) ;
F_29 ( V_2 ) ;
F_84 ( V_2 , V_102 , V_105 ) ;
F_84 ( V_2 , V_101 , V_106 ) ;
F_90 ( V_2 ) ;
V_103 = false ;
}
static void F_91 ( struct V_1 * V_2 )
{
F_29 ( V_2 ) ;
V_32 = 1 ;
}
static void F_92 ( struct V_1 * V_2 )
{
V_32 = 0 ;
}
T_4 static int F_93 ( void )
{
int V_22 ;
V_22 = F_94 ( & V_107 ) ;
if ( V_22 )
return V_22 ;
V_22 = F_94 ( & V_108 ) ;
if ( V_22 )
return V_22 ;
V_22 = F_94 ( & V_109 ) ;
if ( V_22 )
return V_22 ;
return 0 ;
}
