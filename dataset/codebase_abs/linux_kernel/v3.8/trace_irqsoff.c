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
* V_7 = V_5 -> V_7 [ V_10 ] ;
V_9 = F_11 ( & ( * V_7 ) -> V_9 ) ;
if ( F_7 ( V_9 == 1 ) )
return 1 ;
F_12 ( & ( * V_7 ) -> V_9 ) ;
return 0 ;
}
static void
F_13 ( unsigned long V_12 , unsigned long V_13 ,
struct V_14 * V_15 , struct V_16 * V_16 )
{
struct V_4 * V_5 = V_17 ;
struct V_6 * V_7 ;
unsigned long V_8 ;
if ( ! F_5 ( V_5 , & V_7 , & V_8 ) )
return;
F_14 ( V_5 , V_12 , V_13 , V_8 , F_2 () ) ;
F_12 ( & V_7 -> V_9 ) ;
}
static int F_15 ( T_1 V_18 , T_1 V_19 , int V_20 )
{
int V_10 ;
if ( ! ( V_19 & V_21 ) )
return - V_22 ;
if ( ! ( F_16 () ^ V_20 ) )
return 0 ;
F_17 ( V_17 , ! V_20 ) ;
F_18 (cpu)
F_8 ( V_11 , V_10 ) = 0 ;
V_23 = 0 ;
F_19 ( V_17 ) ;
return F_20 ( V_17 , V_20 ) ;
}
static int F_21 ( struct V_24 * V_25 )
{
struct V_4 * V_5 = V_17 ;
struct V_6 * V_7 ;
unsigned long V_8 ;
int V_26 ;
int V_27 ;
if ( ! F_5 ( V_5 , & V_7 , & V_8 ) )
return 0 ;
V_27 = F_2 () ;
V_26 = F_22 ( V_5 , V_25 , V_8 , V_27 ) ;
F_12 ( & V_7 -> V_9 ) ;
return V_26 ;
}
static void F_23 ( struct V_28 * V_25 )
{
struct V_4 * V_5 = V_17 ;
struct V_6 * V_7 ;
unsigned long V_8 ;
int V_27 ;
if ( ! F_5 ( V_5 , & V_7 , & V_8 ) )
return;
V_27 = F_2 () ;
F_24 ( V_5 , V_25 , V_8 , V_27 ) ;
F_12 ( & V_7 -> V_9 ) ;
}
static void F_25 ( struct V_29 * V_30 )
{
if ( F_16 () )
F_26 ( V_30 ) ;
}
static void F_27 ( struct V_29 * V_30 )
{
if ( V_30 -> V_31 )
F_28 ( V_30 ) ;
}
static enum V_32 F_29 ( struct V_29 * V_30 )
{
if ( F_16 () )
return F_30 ( V_30 , V_33 ) ;
return V_34 ;
}
static void F_31 ( struct V_35 * V_36 )
{
if ( F_16 () )
F_32 ( V_36 , V_33 ) ;
else
F_33 ( V_36 ) ;
}
static void
F_34 ( struct V_4 * V_5 ,
unsigned long V_12 , unsigned long V_13 ,
unsigned long V_8 , int V_27 )
{
if ( F_16 () )
F_35 ( V_5 , V_12 , V_13 , V_8 , V_27 ) ;
else
F_14 ( V_5 , V_12 , V_13 , V_8 , V_27 ) ;
}
static int F_15 ( T_1 V_18 , T_1 V_19 , int V_20 )
{
return - V_22 ;
}
static int F_21 ( struct V_24 * V_25 )
{
return - 1 ;
}
static enum V_32 F_29 ( struct V_29 * V_30 )
{
return V_34 ;
}
static void F_23 ( struct V_28 * V_25 ) { }
static void F_25 ( struct V_29 * V_30 ) { }
static void F_27 ( struct V_29 * V_30 ) { }
static void F_31 ( struct V_35 * V_36 )
{
F_33 ( V_36 ) ;
}
static void F_31 ( struct V_35 * V_36 )
{
F_36 ( V_36 ) ;
}
static int F_37 ( T_2 V_37 )
{
if ( V_38 ) {
if ( V_37 < V_38 )
return 0 ;
} else {
if ( V_37 <= V_23 )
return 0 ;
}
return 1 ;
}
static void
F_38 ( struct V_4 * V_5 ,
struct V_6 * V_7 ,
unsigned long V_13 ,
int V_10 )
{
T_2 V_39 , V_40 , V_37 ;
unsigned long V_8 ;
int V_27 ;
V_39 = V_7 -> V_41 ;
V_40 = F_39 ( V_10 ) ;
V_37 = V_40 - V_39 ;
F_9 ( V_8 ) ;
V_27 = F_2 () ;
if ( ! F_37 ( V_37 ) )
goto V_42;
F_40 ( & V_43 , V_8 ) ;
if ( ! F_37 ( V_37 ) )
goto V_44;
F_34 ( V_5 , V_45 , V_13 , V_8 , V_27 ) ;
F_41 ( V_5 , V_8 , 5 , V_27 ) ;
if ( V_7 -> V_46 != V_47 )
goto V_44;
V_7 -> V_48 = V_13 ;
if ( F_7 ( ! F_42 () ) ) {
V_23 = V_37 ;
F_43 ( V_5 , V_49 , V_10 ) ;
}
V_47 ++ ;
V_44:
F_44 ( & V_43 , V_8 ) ;
V_42:
V_7 -> V_46 = V_47 ;
V_7 -> V_41 = F_39 ( V_10 ) ;
F_34 ( V_5 , V_45 , V_13 , V_8 , V_27 ) ;
}
static inline void
F_45 ( unsigned long V_12 , unsigned long V_13 )
{
int V_10 ;
struct V_4 * V_5 = V_17 ;
struct V_6 * V_7 ;
unsigned long V_8 ;
if ( F_7 ( ! V_50 ) )
return;
V_10 = F_6 () ;
if ( F_8 ( V_11 , V_10 ) )
return;
V_7 = V_5 -> V_7 [ V_10 ] ;
if ( F_46 ( ! V_7 ) || F_47 ( & V_7 -> V_9 ) )
return;
F_48 ( & V_7 -> V_9 ) ;
V_7 -> V_46 = V_47 ;
V_7 -> V_41 = F_39 ( V_10 ) ;
V_7 -> V_51 = V_13 ? : V_12 ;
F_9 ( V_8 ) ;
F_34 ( V_5 , V_12 , V_13 , V_8 , F_2 () ) ;
F_8 ( V_11 , V_10 ) = 1 ;
F_12 ( & V_7 -> V_9 ) ;
}
static inline void
F_49 ( unsigned long V_12 , unsigned long V_13 )
{
int V_10 ;
struct V_4 * V_5 = V_17 ;
struct V_6 * V_7 ;
unsigned long V_8 ;
V_10 = F_6 () ;
if ( F_46 ( F_8 ( V_11 , V_10 ) ) )
F_8 ( V_11 , V_10 ) = 0 ;
else
return;
if ( ! V_50 )
return;
V_7 = V_5 -> V_7 [ V_10 ] ;
if ( F_46 ( ! V_7 ) ||
! V_7 -> V_51 || F_47 ( & V_7 -> V_9 ) )
return;
F_48 ( & V_7 -> V_9 ) ;
F_9 ( V_8 ) ;
F_34 ( V_5 , V_12 , V_13 , V_8 , F_2 () ) ;
F_38 ( V_5 , V_7 , V_13 ? : V_12 , V_10 ) ;
V_7 -> V_51 = 0 ;
F_12 ( & V_7 -> V_9 ) ;
}
void F_50 ( void )
{
if ( F_1 () || F_3 () )
F_45 ( V_45 , V_52 ) ;
}
void F_51 ( void )
{
if ( F_1 () || F_3 () )
F_49 ( V_45 , V_52 ) ;
}
void F_52 ( unsigned long V_53 , unsigned long V_54 )
{
if ( ! F_1 () && F_3 () )
F_49 ( V_53 , V_54 ) ;
}
void F_53 ( unsigned long V_53 , unsigned long V_54 )
{
if ( ! F_1 () && F_3 () )
F_45 ( V_53 , V_54 ) ;
}
void F_54 ( unsigned long V_12 )
{
}
void F_55 ( unsigned long V_12 )
{
}
inline void F_56 ( struct V_55 * V_56 )
{
}
void F_57 ( void )
{
if ( ! F_1 () && F_3 () )
F_49 ( V_45 , V_52 ) ;
}
void F_58 ( void )
{
if ( ! F_1 () && F_3 () )
F_45 ( V_45 , V_52 ) ;
}
void F_59 ( unsigned long V_57 )
{
if ( ! F_1 () && F_3 () )
F_49 ( V_45 , V_57 ) ;
}
void F_60 ( unsigned long V_57 )
{
if ( ! F_1 () && F_3 () )
F_45 ( V_45 , V_57 ) ;
}
void F_61 ( unsigned long V_53 , unsigned long V_54 )
{
if ( F_1 () && ! F_3 () )
F_49 ( V_53 , V_54 ) ;
}
void F_62 ( unsigned long V_53 , unsigned long V_54 )
{
if ( F_1 () && ! F_3 () )
F_45 ( V_53 , V_54 ) ;
}
static int F_20 ( struct V_4 * V_5 , int V_58 )
{
int V_26 = 0 ;
if ( ! V_58 )
V_26 = F_63 ( & V_59 ) ;
else
V_26 = F_64 ( & F_23 ,
& F_21 ) ;
if ( ! V_26 && F_65 () )
V_50 = 1 ;
else
V_50 = 0 ;
return V_26 ;
}
static void F_17 ( struct V_4 * V_5 , int V_58 )
{
V_50 = 0 ;
if ( ! V_58 )
F_66 ( & V_59 ) ;
else
F_67 () ;
}
static void F_68 ( struct V_4 * V_5 )
{
V_60 = V_61 & V_62 ;
V_61 |= V_62 ;
V_23 = 0 ;
V_17 = V_5 ;
F_69 () ;
F_19 ( V_5 ) ;
if ( F_20 ( V_5 , F_16 () ) )
F_70 ( V_63 L_1 ) ;
}
static void F_71 ( struct V_4 * V_5 )
{
F_17 ( V_5 , F_16 () ) ;
if ( ! V_60 )
V_61 &= ~ V_62 ;
}
static void F_72 ( struct V_4 * V_5 )
{
V_50 = 1 ;
}
static void F_73 ( struct V_4 * V_5 )
{
V_50 = 0 ;
}
static int F_74 ( struct V_4 * V_5 )
{
V_1 = V_3 ;
F_68 ( V_5 ) ;
return 0 ;
}
static int F_75 ( struct V_4 * V_5 )
{
V_1 = V_2 ;
F_68 ( V_5 ) ;
return 0 ;
}
static int F_76 ( struct V_4 * V_5 )
{
V_1 = V_3 | V_2 ;
F_68 ( V_5 ) ;
return 0 ;
}
T_3 static int F_77 ( void )
{
F_78 ( V_64 ) ;
F_79 ( V_65 ) ;
F_80 ( V_66 ) ;
return 0 ;
}
