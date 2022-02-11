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
if ( ! F_11 ( * V_10 ) )
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
if ( ! F_6 ( V_5 , & V_9 , & V_10 ) )
return 0 ;
V_25 = F_2 () ;
V_24 = F_23 ( V_5 , V_23 , V_10 , V_25 ) ;
F_14 ( & V_9 -> V_11 ) ;
return V_24 ;
}
static void F_24 ( struct V_26 * V_23 )
{
struct V_4 * V_5 = V_20 ;
struct V_8 * V_9 ;
unsigned long V_10 ;
int V_25 ;
if ( ! F_6 ( V_5 , & V_9 , & V_10 ) )
return;
V_25 = F_2 () ;
F_25 ( V_5 , V_23 , V_10 , V_25 ) ;
F_14 ( & V_9 -> V_11 ) ;
}
static void F_26 ( struct V_27 * V_28 )
{
if ( F_17 ( V_28 -> V_5 ) )
F_27 ( V_28 ) ;
}
static void F_28 ( struct V_27 * V_28 )
{
if ( V_28 -> V_29 )
F_29 ( V_28 ) ;
}
static enum V_30 F_30 ( struct V_27 * V_28 )
{
if ( F_17 ( V_28 -> V_5 ) )
return F_31 ( V_28 , V_31 ) ;
return V_32 ;
}
static void F_32 ( struct V_33 * V_34 )
{
struct V_4 * V_5 = V_20 ;
if ( F_17 ( V_5 ) )
F_33 ( V_34 , V_31 ) ;
else
F_34 ( V_34 ) ;
}
static void
F_35 ( struct V_4 * V_5 ,
unsigned long V_15 , unsigned long V_16 ,
unsigned long V_10 , int V_25 )
{
if ( F_17 ( V_5 ) )
F_36 ( V_5 , V_15 , V_16 , V_10 , V_25 ) ;
else
F_16 ( V_5 , V_15 , V_16 , V_10 , V_25 ) ;
}
static int F_22 ( struct V_22 * V_23 )
{
return - 1 ;
}
static enum V_30 F_30 ( struct V_27 * V_28 )
{
return V_32 ;
}
static void F_26 ( struct V_27 * V_28 ) { }
static void F_28 ( struct V_27 * V_28 ) { }
static void F_24 ( struct V_26 * V_23 ) { }
static void F_32 ( struct V_33 * V_34 )
{
F_34 ( V_34 ) ;
}
static void F_32 ( struct V_33 * V_34 )
{
F_37 ( V_34 ) ;
}
static bool F_38 ( struct V_4 * V_5 , T_1 V_35 )
{
if ( V_36 ) {
if ( V_35 < V_36 )
return false ;
} else {
if ( V_35 <= V_5 -> V_21 )
return false ;
}
return true ;
}
static void
F_39 ( struct V_4 * V_5 ,
struct V_8 * V_9 ,
unsigned long V_16 ,
int V_12 )
{
T_1 V_37 , V_38 , V_35 ;
unsigned long V_10 ;
int V_25 ;
V_37 = V_9 -> V_39 ;
V_38 = F_40 ( V_12 ) ;
V_35 = V_38 - V_37 ;
F_10 ( V_10 ) ;
V_25 = F_2 () ;
if ( ! F_38 ( V_5 , V_35 ) )
goto V_40;
F_41 ( & V_41 , V_10 ) ;
if ( ! F_38 ( V_5 , V_35 ) )
goto V_42;
F_35 ( V_5 , V_43 , V_16 , V_10 , V_25 ) ;
F_42 ( V_5 , V_10 , 5 , V_25 ) ;
if ( V_9 -> V_44 != V_45 )
goto V_42;
V_9 -> V_46 = V_16 ;
if ( F_8 ( ! F_43 () ) ) {
V_5 -> V_21 = V_35 ;
F_44 ( V_5 , V_47 , V_12 ) ;
}
V_45 ++ ;
V_42:
F_45 ( & V_41 , V_10 ) ;
V_40:
V_9 -> V_44 = V_45 ;
V_9 -> V_39 = F_40 ( V_12 ) ;
F_35 ( V_5 , V_43 , V_16 , V_10 , V_25 ) ;
}
static inline void
F_46 ( unsigned long V_15 , unsigned long V_16 )
{
int V_12 ;
struct V_4 * V_5 = V_20 ;
struct V_8 * V_9 ;
unsigned long V_10 ;
if ( ! V_48 || ! F_47 () )
return;
V_12 = F_7 () ;
if ( F_9 ( V_13 , V_12 ) )
return;
V_9 = F_12 ( V_5 -> V_14 . V_9 , V_12 ) ;
if ( F_48 ( ! V_9 ) || F_49 ( & V_9 -> V_11 ) )
return;
F_50 ( & V_9 -> V_11 ) ;
V_9 -> V_44 = V_45 ;
V_9 -> V_39 = F_40 ( V_12 ) ;
V_9 -> V_49 = V_16 ? : V_15 ;
F_10 ( V_10 ) ;
F_35 ( V_5 , V_15 , V_16 , V_10 , F_2 () ) ;
F_9 ( V_13 , V_12 ) = 1 ;
F_14 ( & V_9 -> V_11 ) ;
}
static inline void
F_51 ( unsigned long V_15 , unsigned long V_16 )
{
int V_12 ;
struct V_4 * V_5 = V_20 ;
struct V_8 * V_9 ;
unsigned long V_10 ;
V_12 = F_7 () ;
if ( F_48 ( F_9 ( V_13 , V_12 ) ) )
F_9 ( V_13 , V_12 ) = 0 ;
else
return;
if ( ! V_48 || ! F_47 () )
return;
V_9 = F_12 ( V_5 -> V_14 . V_9 , V_12 ) ;
if ( F_48 ( ! V_9 ) ||
! V_9 -> V_49 || F_49 ( & V_9 -> V_11 ) )
return;
F_50 ( & V_9 -> V_11 ) ;
F_10 ( V_10 ) ;
F_35 ( V_5 , V_15 , V_16 , V_10 , F_2 () ) ;
F_39 ( V_5 , V_9 , V_16 ? : V_15 , V_12 ) ;
V_9 -> V_49 = 0 ;
F_14 ( & V_9 -> V_11 ) ;
}
void F_52 ( void )
{
if ( F_1 () || F_3 () )
F_46 ( V_43 , V_50 ) ;
}
void F_53 ( void )
{
if ( F_1 () || F_3 () )
F_51 ( V_43 , V_50 ) ;
}
void F_54 ( unsigned long V_51 , unsigned long V_52 )
{
if ( ! F_1 () && F_3 () )
F_51 ( V_51 , V_52 ) ;
}
void F_55 ( unsigned long V_51 , unsigned long V_52 )
{
if ( ! F_1 () && F_3 () )
F_46 ( V_51 , V_52 ) ;
}
void F_56 ( unsigned long V_15 )
{
}
void F_57 ( unsigned long V_15 )
{
}
inline void F_58 ( struct V_53 * V_54 )
{
}
void F_59 ( void )
{
if ( ! F_1 () && F_3 () )
F_51 ( V_43 , V_50 ) ;
}
void F_60 ( void )
{
if ( ! F_1 () && F_3 () )
F_46 ( V_43 , V_50 ) ;
}
T_2 void F_61 ( unsigned long V_55 )
{
if ( ! F_1 () && F_3 () )
F_51 ( V_43 , V_55 ) ;
}
T_2 void F_62 ( unsigned long V_55 )
{
if ( ! F_1 () && F_3 () )
F_46 ( V_43 , V_55 ) ;
}
void F_63 ( unsigned long V_51 , unsigned long V_52 )
{
if ( F_1 () && ! F_3 () )
F_51 ( V_51 , V_52 ) ;
}
void F_64 ( unsigned long V_51 , unsigned long V_52 )
{
if ( F_1 () && ! F_3 () )
F_46 ( V_51 , V_52 ) ;
}
static int F_65 ( struct V_4 * V_5 , int V_56 , int V_6 )
{
int V_24 ;
if ( V_57 || ( ! V_6 && ! ( V_5 -> V_58 & V_59 ) ) )
return 0 ;
if ( V_56 )
V_24 = F_66 ( & F_24 ,
& F_22 ) ;
else
V_24 = F_67 ( V_5 -> V_60 ) ;
if ( ! V_24 )
V_57 = true ;
return V_24 ;
}
static void F_68 ( struct V_4 * V_5 , int V_56 )
{
if ( ! V_57 )
return;
if ( V_56 )
F_69 () ;
else
F_70 ( V_5 -> V_60 ) ;
V_57 = false ;
}
static int F_71 ( struct V_4 * V_5 , T_3 V_61 , int V_6 )
{
if ( ! ( V_61 & V_59 ) )
return 0 ;
if ( V_6 )
F_65 ( V_5 , F_17 ( V_5 ) , 1 ) ;
else
F_68 ( V_5 , F_17 ( V_5 ) ) ;
return 1 ;
}
static int F_65 ( struct V_4 * V_5 , int V_56 , int V_6 )
{
return 0 ;
}
static void F_68 ( struct V_4 * V_5 , int V_56 ) { }
static inline int F_71 ( struct V_4 * V_5 , T_3 V_61 , int V_6 )
{
return 0 ;
}
static int F_72 ( struct V_4 * V_5 , T_3 V_61 , int V_6 )
{
struct V_62 * V_62 = V_5 -> V_63 ;
if ( F_71 ( V_5 , V_61 , V_6 ) )
return 0 ;
#ifdef F_73
if ( V_61 & V_64 )
return F_5 ( V_5 , V_6 ) ;
#endif
return F_74 ( V_62 , V_61 , V_6 ) ;
}
static int F_21 ( struct V_4 * V_5 , int V_56 )
{
int V_24 ;
V_24 = F_65 ( V_5 , V_56 , 0 ) ;
if ( ! V_24 && F_47 () )
V_48 = 1 ;
else
V_48 = 0 ;
return V_24 ;
}
static void F_18 ( struct V_4 * V_5 , int V_56 )
{
V_48 = 0 ;
F_68 ( V_5 , V_56 ) ;
}
static int F_75 ( struct V_4 * V_5 )
{
if ( V_65 )
return - V_66 ;
V_67 = V_5 -> V_58 ;
F_76 ( V_5 , V_68 , 1 ) ;
F_76 ( V_5 , V_69 , 1 ) ;
V_5 -> V_21 = 0 ;
V_20 = V_5 ;
F_77 () ;
F_20 ( & V_5 -> V_14 ) ;
F_78 ( V_5 , F_15 ) ;
if ( F_21 ( V_5 , ( V_5 -> V_10 & V_70 &&
F_17 ( V_5 ) ) ) )
F_79 ( V_71 L_1 ) ;
V_65 = true ;
return 0 ;
}
static void F_80 ( struct V_4 * V_5 )
{
int V_72 = V_67 & V_69 ;
int V_73 = V_67 & V_68 ;
F_18 ( V_5 , F_17 ( V_5 ) ) ;
F_76 ( V_5 , V_69 , V_72 ) ;
F_76 ( V_5 , V_68 , V_73 ) ;
F_81 ( V_5 ) ;
V_65 = false ;
}
static void F_82 ( struct V_4 * V_5 )
{
V_48 = 1 ;
}
static void F_83 ( struct V_4 * V_5 )
{
V_48 = 0 ;
}
static int F_84 ( struct V_4 * V_5 )
{
V_1 = V_3 ;
return F_75 ( V_5 ) ;
}
static int F_85 ( struct V_4 * V_5 )
{
V_1 = V_2 ;
return F_75 ( V_5 ) ;
}
static int F_86 ( struct V_4 * V_5 )
{
V_1 = V_3 | V_2 ;
return F_75 ( V_5 ) ;
}
T_4 static int F_87 ( void )
{
F_88 ( V_74 ) ;
F_89 ( V_75 ) ;
F_90 ( V_76 ) ;
return 0 ;
}
