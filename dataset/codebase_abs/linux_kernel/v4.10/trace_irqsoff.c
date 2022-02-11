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
static inline int F_5 ( struct V_4 * V_5 , int V_6 )
{
return - V_7 ;
}
static int F_6 ( struct V_4 * V_5 ,
struct V_8 * * V_9 ,
unsigned long * V_10 )
{
long V_11 ;
int V_12 ;
V_12 = F_7 () ;
if ( F_8 ( ! F_9 ( V_13 , V_12 ) ) )
return 0 ;
F_10 ( * V_10 ) ;
if ( ! F_11 ( * V_10 ) && ! F_2 () )
return 0 ;
* V_9 = F_12 ( V_5 -> V_14 . V_9 , V_12 ) ;
V_11 = F_13 ( & ( * V_9 ) -> V_11 ) ;
if ( F_8 ( V_11 == 1 ) )
return 1 ;
F_14 ( & ( * V_9 ) -> V_11 ) ;
return 0 ;
}
static void
F_15 ( unsigned long V_15 , unsigned long V_16 ,
struct V_17 * V_18 , struct V_19 * V_19 )
{
struct V_4 * V_5 = V_20 ;
struct V_8 * V_9 ;
unsigned long V_10 ;
if ( ! F_6 ( V_5 , & V_9 , & V_10 ) )
return;
F_16 ( V_5 , V_15 , V_16 , V_10 , F_2 () ) ;
F_14 ( & V_9 -> V_11 ) ;
}
static int F_5 ( struct V_4 * V_5 , int V_6 )
{
int V_12 ;
if ( ! ( F_17 ( V_5 ) ^ V_6 ) )
return 0 ;
F_18 ( V_20 , ! V_6 ) ;
F_19 (cpu)
F_9 ( V_13 , V_12 ) = 0 ;
V_5 -> V_21 = 0 ;
F_20 ( & V_20 -> V_14 ) ;
return F_21 ( V_20 , V_6 ) ;
}
static int F_22 ( struct V_22 * V_23 )
{
struct V_4 * V_5 = V_20 ;
struct V_8 * V_9 ;
unsigned long V_10 ;
int V_24 ;
int V_25 ;
if ( F_23 ( V_23 ) )
return 0 ;
if ( F_24 ( V_23 -> V_26 ) )
return 1 ;
if ( ! F_6 ( V_5 , & V_9 , & V_10 ) )
return 0 ;
V_25 = F_2 () ;
V_24 = F_25 ( V_5 , V_23 , V_10 , V_25 ) ;
F_14 ( & V_9 -> V_11 ) ;
return V_24 ;
}
static void F_26 ( struct V_27 * V_23 )
{
struct V_4 * V_5 = V_20 ;
struct V_8 * V_9 ;
unsigned long V_10 ;
int V_25 ;
if ( ! F_6 ( V_5 , & V_9 , & V_10 ) )
return;
V_25 = F_2 () ;
F_27 ( V_5 , V_23 , V_10 , V_25 ) ;
F_14 ( & V_9 -> V_11 ) ;
}
static void F_28 ( struct V_28 * V_29 )
{
if ( F_17 ( V_29 -> V_5 ) )
F_29 ( V_29 ) ;
}
static void F_30 ( struct V_28 * V_29 )
{
if ( V_29 -> V_30 )
F_31 ( V_29 ) ;
}
static enum V_31 F_32 ( struct V_28 * V_29 )
{
if ( F_17 ( V_29 -> V_5 ) )
return F_33 ( V_29 , V_32 ) ;
return V_33 ;
}
static void F_34 ( struct V_34 * V_35 )
{
struct V_4 * V_5 = V_20 ;
if ( F_17 ( V_5 ) )
F_35 ( V_35 , V_32 ) ;
else
F_36 ( V_35 ) ;
}
static void
F_37 ( struct V_4 * V_5 ,
unsigned long V_15 , unsigned long V_16 ,
unsigned long V_10 , int V_25 )
{
if ( F_17 ( V_5 ) )
F_38 ( V_5 , V_15 , V_16 , V_10 , V_25 ) ;
else
F_16 ( V_5 , V_15 , V_16 , V_10 , V_25 ) ;
}
static int F_22 ( struct V_22 * V_23 )
{
return - 1 ;
}
static enum V_31 F_32 ( struct V_28 * V_29 )
{
return V_33 ;
}
static void F_28 ( struct V_28 * V_29 ) { }
static void F_30 ( struct V_28 * V_29 ) { }
static void F_26 ( struct V_27 * V_23 ) { }
static void F_34 ( struct V_34 * V_35 )
{
F_36 ( V_35 ) ;
}
static void F_34 ( struct V_34 * V_35 )
{
F_39 ( V_35 ) ;
}
static bool F_40 ( struct V_4 * V_5 , T_1 V_36 )
{
if ( V_37 ) {
if ( V_36 < V_37 )
return false ;
} else {
if ( V_36 <= V_5 -> V_21 )
return false ;
}
return true ;
}
static void
F_41 ( struct V_4 * V_5 ,
struct V_8 * V_9 ,
unsigned long V_16 ,
int V_12 )
{
T_1 V_38 , V_39 , V_36 ;
unsigned long V_10 ;
int V_25 ;
V_38 = V_9 -> V_40 ;
V_39 = F_42 ( V_12 ) ;
V_36 = V_39 - V_38 ;
F_10 ( V_10 ) ;
V_25 = F_2 () ;
if ( ! F_40 ( V_5 , V_36 ) )
goto V_41;
F_43 ( & V_42 , V_10 ) ;
if ( ! F_40 ( V_5 , V_36 ) )
goto V_43;
F_37 ( V_5 , V_44 , V_16 , V_10 , V_25 ) ;
F_44 ( V_5 , V_10 , 5 , V_25 ) ;
if ( V_9 -> V_45 != V_46 )
goto V_43;
V_9 -> V_47 = V_16 ;
if ( F_8 ( ! F_45 () ) ) {
V_5 -> V_21 = V_36 ;
F_46 ( V_5 , V_48 , V_12 ) ;
}
V_46 ++ ;
V_43:
F_47 ( & V_42 , V_10 ) ;
V_41:
V_9 -> V_45 = V_46 ;
V_9 -> V_40 = F_42 ( V_12 ) ;
F_37 ( V_5 , V_44 , V_16 , V_10 , V_25 ) ;
}
static inline void
F_48 ( unsigned long V_15 , unsigned long V_16 )
{
int V_12 ;
struct V_4 * V_5 = V_20 ;
struct V_8 * V_9 ;
unsigned long V_10 ;
if ( ! V_49 || ! F_49 () )
return;
V_12 = F_7 () ;
if ( F_9 ( V_13 , V_12 ) )
return;
V_9 = F_12 ( V_5 -> V_14 . V_9 , V_12 ) ;
if ( F_50 ( ! V_9 ) || F_51 ( & V_9 -> V_11 ) )
return;
F_52 ( & V_9 -> V_11 ) ;
V_9 -> V_45 = V_46 ;
V_9 -> V_40 = F_42 ( V_12 ) ;
V_9 -> V_50 = V_16 ? : V_15 ;
F_10 ( V_10 ) ;
F_37 ( V_5 , V_15 , V_16 , V_10 , F_2 () ) ;
F_9 ( V_13 , V_12 ) = 1 ;
F_14 ( & V_9 -> V_11 ) ;
}
static inline void
F_53 ( unsigned long V_15 , unsigned long V_16 )
{
int V_12 ;
struct V_4 * V_5 = V_20 ;
struct V_8 * V_9 ;
unsigned long V_10 ;
V_12 = F_7 () ;
if ( F_50 ( F_9 ( V_13 , V_12 ) ) )
F_9 ( V_13 , V_12 ) = 0 ;
else
return;
if ( ! V_49 || ! F_49 () )
return;
V_9 = F_12 ( V_5 -> V_14 . V_9 , V_12 ) ;
if ( F_50 ( ! V_9 ) ||
! V_9 -> V_50 || F_51 ( & V_9 -> V_11 ) )
return;
F_52 ( & V_9 -> V_11 ) ;
F_10 ( V_10 ) ;
F_37 ( V_5 , V_15 , V_16 , V_10 , F_2 () ) ;
F_41 ( V_5 , V_9 , V_16 ? : V_15 , V_12 ) ;
V_9 -> V_50 = 0 ;
F_14 ( & V_9 -> V_11 ) ;
}
void F_54 ( void )
{
if ( F_1 () || F_3 () )
F_48 ( V_44 , V_51 ) ;
}
void F_55 ( void )
{
if ( F_1 () || F_3 () )
F_53 ( V_44 , V_51 ) ;
}
void F_56 ( unsigned long V_52 , unsigned long V_53 )
{
if ( ! F_1 () && F_3 () )
F_53 ( V_52 , V_53 ) ;
}
void F_57 ( unsigned long V_52 , unsigned long V_53 )
{
if ( ! F_1 () && F_3 () )
F_48 ( V_52 , V_53 ) ;
}
void F_58 ( unsigned long V_15 )
{
}
void F_59 ( unsigned long V_15 )
{
}
inline void F_60 ( struct V_54 * V_55 )
{
}
void F_61 ( void )
{
if ( ! F_1 () && F_3 () )
F_53 ( V_44 , V_51 ) ;
}
void F_62 ( void )
{
if ( ! F_1 () && F_3 () )
F_48 ( V_44 , V_51 ) ;
}
T_2 void F_63 ( unsigned long V_56 )
{
if ( ! F_1 () && F_3 () )
F_53 ( V_44 , V_56 ) ;
}
T_2 void F_64 ( unsigned long V_56 )
{
if ( ! F_1 () && F_3 () )
F_48 ( V_44 , V_56 ) ;
}
void F_65 ( unsigned long V_52 , unsigned long V_53 )
{
if ( F_1 () && ! F_3 () )
F_53 ( V_52 , V_53 ) ;
}
void F_66 ( unsigned long V_52 , unsigned long V_53 )
{
if ( F_1 () && ! F_3 () )
F_48 ( V_52 , V_53 ) ;
}
static int F_67 ( struct V_4 * V_5 , int V_57 , int V_6 )
{
int V_24 ;
if ( V_58 || ( ! V_6 && ! ( V_5 -> V_59 & V_60 ) ) )
return 0 ;
if ( V_57 )
V_24 = F_68 ( & F_26 ,
& F_22 ) ;
else
V_24 = F_69 ( V_5 -> V_61 ) ;
if ( ! V_24 )
V_58 = true ;
return V_24 ;
}
static void F_70 ( struct V_4 * V_5 , int V_57 )
{
if ( ! V_58 )
return;
if ( V_57 )
F_71 () ;
else
F_72 ( V_5 -> V_61 ) ;
V_58 = false ;
}
static int F_73 ( struct V_4 * V_5 , T_3 V_62 , int V_6 )
{
if ( ! ( V_62 & V_60 ) )
return 0 ;
if ( V_6 )
F_67 ( V_5 , F_17 ( V_5 ) , 1 ) ;
else
F_70 ( V_5 , F_17 ( V_5 ) ) ;
return 1 ;
}
static int F_67 ( struct V_4 * V_5 , int V_57 , int V_6 )
{
return 0 ;
}
static void F_70 ( struct V_4 * V_5 , int V_57 ) { }
static inline int F_73 ( struct V_4 * V_5 , T_3 V_62 , int V_6 )
{
return 0 ;
}
static int F_74 ( struct V_4 * V_5 , T_3 V_62 , int V_6 )
{
struct V_63 * V_63 = V_5 -> V_64 ;
if ( F_73 ( V_5 , V_62 , V_6 ) )
return 0 ;
#ifdef F_75
if ( V_62 & V_65 )
return F_5 ( V_5 , V_6 ) ;
#endif
return F_76 ( V_63 , V_62 , V_6 ) ;
}
static int F_21 ( struct V_4 * V_5 , int V_57 )
{
int V_24 ;
V_24 = F_67 ( V_5 , V_57 , 0 ) ;
if ( ! V_24 && F_49 () )
V_49 = 1 ;
else
V_49 = 0 ;
return V_24 ;
}
static void F_18 ( struct V_4 * V_5 , int V_57 )
{
V_49 = 0 ;
F_70 ( V_5 , V_57 ) ;
}
static int F_77 ( struct V_4 * V_5 )
{
if ( V_66 )
return - V_67 ;
V_68 = V_5 -> V_59 ;
F_78 ( V_5 , V_69 , 1 ) ;
F_78 ( V_5 , V_70 , 1 ) ;
V_5 -> V_21 = 0 ;
V_20 = V_5 ;
F_79 () ;
F_80 ( V_5 , F_15 ) ;
if ( F_21 ( V_5 , ( V_5 -> V_10 & V_71 &&
F_17 ( V_5 ) ) ) )
F_81 ( V_72 L_1 ) ;
V_66 = true ;
return 0 ;
}
static void F_82 ( struct V_4 * V_5 )
{
int V_73 = V_68 & V_70 ;
int V_74 = V_68 & V_69 ;
F_18 ( V_5 , F_17 ( V_5 ) ) ;
F_78 ( V_5 , V_70 , V_73 ) ;
F_78 ( V_5 , V_69 , V_74 ) ;
F_83 ( V_5 ) ;
V_66 = false ;
}
static void F_84 ( struct V_4 * V_5 )
{
V_49 = 1 ;
}
static void F_85 ( struct V_4 * V_5 )
{
V_49 = 0 ;
}
static int F_86 ( struct V_4 * V_5 )
{
V_1 = V_3 ;
return F_77 ( V_5 ) ;
}
static int F_87 ( struct V_4 * V_5 )
{
V_1 = V_2 ;
return F_77 ( V_5 ) ;
}
static int F_88 ( struct V_4 * V_5 )
{
V_1 = V_3 | V_2 ;
return F_77 ( V_5 ) ;
}
T_4 static int F_89 ( void )
{
F_90 ( V_75 ) ;
F_91 ( V_76 ) ;
F_92 ( V_77 ) ;
return 0 ;
}
