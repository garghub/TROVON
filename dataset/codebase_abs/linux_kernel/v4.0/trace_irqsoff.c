static inline int
F_1 ( void )
{
return ( ( V_1 & V_2 ) && F_2 () ) ;
}
static inline int
F_3 ( void )
{
return ( ( V_1 & V_3 ) &&
F_4 () ) ;
}
static int F_5 ( struct V_4 * V_5 ,
struct V_6 * * V_7 ,
unsigned long * V_8 )
{
long V_9 ;
int V_10 ;
V_10 = F_6 () ;
if ( F_7 ( ! F_8 ( V_11 , V_10 ) ) )
return 0 ;
F_9 ( * V_8 ) ;
if ( ! F_10 ( * V_8 ) )
return 0 ;
* V_7 = F_11 ( V_5 -> V_12 . V_7 , V_10 ) ;
V_9 = F_12 ( & ( * V_7 ) -> V_9 ) ;
if ( F_7 ( V_9 == 1 ) )
return 1 ;
F_13 ( & ( * V_7 ) -> V_9 ) ;
return 0 ;
}
static void
F_14 ( unsigned long V_13 , unsigned long V_14 ,
struct V_15 * V_16 , struct V_17 * V_17 )
{
struct V_4 * V_5 = V_18 ;
struct V_6 * V_7 ;
unsigned long V_8 ;
if ( ! F_5 ( V_5 , & V_7 , & V_8 ) )
return;
F_15 ( V_5 , V_13 , V_14 , V_8 , F_2 () ) ;
F_13 ( & V_7 -> V_9 ) ;
}
static int
F_16 ( struct V_4 * V_5 , T_1 V_19 , T_1 V_20 , int V_21 )
{
int V_10 ;
if ( ! ( V_20 & V_22 ) )
return - V_23 ;
if ( ! ( F_17 () ^ V_21 ) )
return 0 ;
F_18 ( V_18 , ! V_21 ) ;
F_19 (cpu)
F_8 ( V_11 , V_10 ) = 0 ;
V_5 -> V_24 = 0 ;
F_20 ( & V_18 -> V_12 ) ;
return F_21 ( V_18 , V_21 ) ;
}
static int F_22 ( struct V_25 * V_26 )
{
struct V_4 * V_5 = V_18 ;
struct V_6 * V_7 ;
unsigned long V_8 ;
int V_27 ;
int V_28 ;
if ( ! F_5 ( V_5 , & V_7 , & V_8 ) )
return 0 ;
V_28 = F_2 () ;
V_27 = F_23 ( V_5 , V_26 , V_8 , V_28 ) ;
F_13 ( & V_7 -> V_9 ) ;
return V_27 ;
}
static void F_24 ( struct V_29 * V_26 )
{
struct V_4 * V_5 = V_18 ;
struct V_6 * V_7 ;
unsigned long V_8 ;
int V_28 ;
if ( ! F_5 ( V_5 , & V_7 , & V_8 ) )
return;
V_28 = F_2 () ;
F_25 ( V_5 , V_26 , V_8 , V_28 ) ;
F_13 ( & V_7 -> V_9 ) ;
}
static void F_26 ( struct V_30 * V_31 )
{
if ( F_17 () )
F_27 ( V_31 ) ;
}
static void F_28 ( struct V_30 * V_31 )
{
if ( V_31 -> V_32 )
F_29 ( V_31 ) ;
}
static enum V_33 F_30 ( struct V_30 * V_31 )
{
if ( F_17 () )
return F_31 ( V_31 , V_34 ) ;
return V_35 ;
}
static void F_32 ( struct V_36 * V_37 )
{
if ( F_17 () )
F_33 ( V_37 , V_34 ) ;
else
F_34 ( V_37 ) ;
}
static void
F_35 ( struct V_4 * V_5 ,
unsigned long V_13 , unsigned long V_14 ,
unsigned long V_8 , int V_28 )
{
if ( F_17 () )
F_36 ( V_5 , V_13 , V_14 , V_8 , V_28 ) ;
else
F_15 ( V_5 , V_13 , V_14 , V_8 , V_28 ) ;
}
static int
F_16 ( struct V_4 * V_5 , T_1 V_19 , T_1 V_20 , int V_21 )
{
return - V_23 ;
}
static int F_22 ( struct V_25 * V_26 )
{
return - 1 ;
}
static enum V_33 F_30 ( struct V_30 * V_31 )
{
return V_35 ;
}
static void F_24 ( struct V_29 * V_26 ) { }
static void F_26 ( struct V_30 * V_31 ) { }
static void F_28 ( struct V_30 * V_31 ) { }
static void F_32 ( struct V_36 * V_37 )
{
F_34 ( V_37 ) ;
}
static void F_32 ( struct V_36 * V_37 )
{
F_37 ( V_37 ) ;
}
static int F_38 ( struct V_4 * V_5 , T_2 V_38 )
{
if ( V_39 ) {
if ( V_38 < V_39 )
return 0 ;
} else {
if ( V_38 <= V_5 -> V_24 )
return 0 ;
}
return 1 ;
}
static void
F_39 ( struct V_4 * V_5 ,
struct V_6 * V_7 ,
unsigned long V_14 ,
int V_10 )
{
T_2 V_40 , V_41 , V_38 ;
unsigned long V_8 ;
int V_28 ;
V_40 = V_7 -> V_42 ;
V_41 = F_40 ( V_10 ) ;
V_38 = V_41 - V_40 ;
F_9 ( V_8 ) ;
V_28 = F_2 () ;
if ( ! F_38 ( V_5 , V_38 ) )
goto V_43;
F_41 ( & V_44 , V_8 ) ;
if ( ! F_38 ( V_5 , V_38 ) )
goto V_45;
F_35 ( V_5 , V_46 , V_14 , V_8 , V_28 ) ;
F_42 ( V_5 , V_8 , 5 , V_28 ) ;
if ( V_7 -> V_47 != V_48 )
goto V_45;
V_7 -> V_49 = V_14 ;
if ( F_7 ( ! F_43 () ) ) {
V_5 -> V_24 = V_38 ;
F_44 ( V_5 , V_50 , V_10 ) ;
}
V_48 ++ ;
V_45:
F_45 ( & V_44 , V_8 ) ;
V_43:
V_7 -> V_47 = V_48 ;
V_7 -> V_42 = F_40 ( V_10 ) ;
F_35 ( V_5 , V_46 , V_14 , V_8 , V_28 ) ;
}
static inline void
F_46 ( unsigned long V_13 , unsigned long V_14 )
{
int V_10 ;
struct V_4 * V_5 = V_18 ;
struct V_6 * V_7 ;
unsigned long V_8 ;
if ( ! V_51 || ! F_47 () )
return;
V_10 = F_6 () ;
if ( F_8 ( V_11 , V_10 ) )
return;
V_7 = F_11 ( V_5 -> V_12 . V_7 , V_10 ) ;
if ( F_48 ( ! V_7 ) || F_49 ( & V_7 -> V_9 ) )
return;
F_50 ( & V_7 -> V_9 ) ;
V_7 -> V_47 = V_48 ;
V_7 -> V_42 = F_40 ( V_10 ) ;
V_7 -> V_52 = V_14 ? : V_13 ;
F_9 ( V_8 ) ;
F_35 ( V_5 , V_13 , V_14 , V_8 , F_2 () ) ;
F_8 ( V_11 , V_10 ) = 1 ;
F_13 ( & V_7 -> V_9 ) ;
}
static inline void
F_51 ( unsigned long V_13 , unsigned long V_14 )
{
int V_10 ;
struct V_4 * V_5 = V_18 ;
struct V_6 * V_7 ;
unsigned long V_8 ;
V_10 = F_6 () ;
if ( F_48 ( F_8 ( V_11 , V_10 ) ) )
F_8 ( V_11 , V_10 ) = 0 ;
else
return;
if ( ! V_51 || ! F_47 () )
return;
V_7 = F_11 ( V_5 -> V_12 . V_7 , V_10 ) ;
if ( F_48 ( ! V_7 ) ||
! V_7 -> V_52 || F_49 ( & V_7 -> V_9 ) )
return;
F_50 ( & V_7 -> V_9 ) ;
F_9 ( V_8 ) ;
F_35 ( V_5 , V_13 , V_14 , V_8 , F_2 () ) ;
F_39 ( V_5 , V_7 , V_14 ? : V_13 , V_10 ) ;
V_7 -> V_52 = 0 ;
F_13 ( & V_7 -> V_9 ) ;
}
void F_52 ( void )
{
if ( F_1 () || F_3 () )
F_46 ( V_46 , V_53 ) ;
}
void F_53 ( void )
{
if ( F_1 () || F_3 () )
F_51 ( V_46 , V_53 ) ;
}
void F_54 ( unsigned long V_54 , unsigned long V_55 )
{
if ( ! F_1 () && F_3 () )
F_51 ( V_54 , V_55 ) ;
}
void F_55 ( unsigned long V_54 , unsigned long V_55 )
{
if ( ! F_1 () && F_3 () )
F_46 ( V_54 , V_55 ) ;
}
void F_56 ( unsigned long V_13 )
{
}
void F_57 ( unsigned long V_13 )
{
}
inline void F_58 ( struct V_56 * V_57 )
{
}
void F_59 ( void )
{
if ( ! F_1 () && F_3 () )
F_51 ( V_46 , V_53 ) ;
}
void F_60 ( void )
{
if ( ! F_1 () && F_3 () )
F_46 ( V_46 , V_53 ) ;
}
T_3 void F_61 ( unsigned long V_58 )
{
if ( ! F_1 () && F_3 () )
F_51 ( V_46 , V_58 ) ;
}
T_3 void F_62 ( unsigned long V_58 )
{
if ( ! F_1 () && F_3 () )
F_46 ( V_46 , V_58 ) ;
}
void F_63 ( unsigned long V_54 , unsigned long V_55 )
{
if ( F_1 () && ! F_3 () )
F_51 ( V_54 , V_55 ) ;
}
void F_64 ( unsigned long V_54 , unsigned long V_55 )
{
if ( F_1 () && ! F_3 () )
F_46 ( V_54 , V_55 ) ;
}
static int F_65 ( struct V_4 * V_5 , int V_59 , int V_21 )
{
int V_27 ;
if ( V_60 || ( ! V_21 && ! ( V_61 & V_62 ) ) )
return 0 ;
if ( V_59 )
V_27 = F_66 ( & F_24 ,
& F_22 ) ;
else
V_27 = F_67 ( V_5 -> V_63 ) ;
if ( ! V_27 )
V_60 = true ;
return V_27 ;
}
static void F_68 ( struct V_4 * V_5 , int V_59 )
{
if ( ! V_60 )
return;
if ( V_59 )
F_69 () ;
else
F_70 ( V_5 -> V_63 ) ;
V_60 = false ;
}
static void F_71 ( struct V_4 * V_5 , int V_21 )
{
if ( V_21 )
F_65 ( V_5 , F_17 () , 1 ) ;
else
F_68 ( V_5 , F_17 () ) ;
}
static int F_72 ( struct V_4 * V_5 , T_1 V_64 , int V_21 )
{
struct V_65 * V_65 = V_5 -> V_66 ;
if ( V_64 & V_62 )
F_71 ( V_5 , V_21 ) ;
return F_73 ( V_65 , V_64 , V_21 ) ;
}
static int F_21 ( struct V_4 * V_5 , int V_59 )
{
int V_27 ;
V_27 = F_65 ( V_5 , V_59 , 0 ) ;
if ( ! V_27 && F_47 () )
V_51 = 1 ;
else
V_51 = 0 ;
return V_27 ;
}
static void F_18 ( struct V_4 * V_5 , int V_59 )
{
V_51 = 0 ;
F_68 ( V_5 , V_59 ) ;
}
static int F_74 ( struct V_4 * V_5 )
{
if ( V_67 )
return - V_68 ;
V_69 = V_61 ;
F_75 ( V_5 , V_70 , 1 ) ;
F_75 ( V_5 , V_71 , 1 ) ;
V_5 -> V_24 = 0 ;
V_18 = V_5 ;
F_76 () ;
F_20 ( & V_5 -> V_12 ) ;
F_77 ( V_5 , F_14 ) ;
if ( F_21 ( V_5 , ( V_5 -> V_8 & V_72 &&
F_17 () ) ) )
F_78 ( V_73 L_1 ) ;
V_67 = true ;
return 0 ;
}
static void F_79 ( struct V_4 * V_5 )
{
int V_74 = V_69 & V_71 ;
int V_75 = V_69 & V_70 ;
F_18 ( V_5 , F_17 () ) ;
F_75 ( V_5 , V_71 , V_74 ) ;
F_75 ( V_5 , V_70 , V_75 ) ;
F_80 ( V_5 ) ;
V_67 = false ;
}
static void F_81 ( struct V_4 * V_5 )
{
V_51 = 1 ;
}
static void F_82 ( struct V_4 * V_5 )
{
V_51 = 0 ;
}
static int F_83 ( struct V_4 * V_5 )
{
V_1 = V_3 ;
return F_74 ( V_5 ) ;
}
static int F_84 ( struct V_4 * V_5 )
{
V_1 = V_2 ;
return F_74 ( V_5 ) ;
}
static int F_85 ( struct V_4 * V_5 )
{
V_1 = V_3 | V_2 ;
return F_74 ( V_5 ) ;
}
T_4 static int F_86 ( void )
{
F_87 ( V_76 ) ;
F_88 ( V_77 ) ;
F_89 ( V_78 ) ;
return 0 ;
}
