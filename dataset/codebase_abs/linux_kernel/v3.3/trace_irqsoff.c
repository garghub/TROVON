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
F_13 ( unsigned long V_12 , unsigned long V_13 )
{
struct V_4 * V_5 = V_14 ;
struct V_6 * V_7 ;
unsigned long V_8 ;
if ( ! F_5 ( V_5 , & V_7 , & V_8 ) )
return;
F_14 ( V_5 , V_12 , V_13 , V_8 , F_2 () ) ;
F_12 ( & V_7 -> V_9 ) ;
}
static int F_15 ( T_1 V_15 , T_1 V_16 , int V_17 )
{
int V_10 ;
if ( ! ( V_16 & V_18 ) )
return - V_19 ;
if ( ! ( F_16 () ^ V_17 ) )
return 0 ;
F_17 ( V_14 , ! V_17 ) ;
F_18 (cpu)
F_8 ( V_11 , V_10 ) = 0 ;
V_20 = 0 ;
F_19 ( V_14 ) ;
return F_20 ( V_14 , V_17 ) ;
}
static int F_21 ( struct V_21 * V_22 )
{
struct V_4 * V_5 = V_14 ;
struct V_6 * V_7 ;
unsigned long V_8 ;
int V_23 ;
int V_24 ;
if ( ! F_5 ( V_5 , & V_7 , & V_8 ) )
return 0 ;
V_24 = F_2 () ;
V_23 = F_22 ( V_5 , V_22 , V_8 , V_24 ) ;
F_12 ( & V_7 -> V_9 ) ;
return V_23 ;
}
static void F_23 ( struct V_25 * V_22 )
{
struct V_4 * V_5 = V_14 ;
struct V_6 * V_7 ;
unsigned long V_8 ;
int V_24 ;
if ( ! F_5 ( V_5 , & V_7 , & V_8 ) )
return;
V_24 = F_2 () ;
F_24 ( V_5 , V_22 , V_8 , V_24 ) ;
F_12 ( & V_7 -> V_9 ) ;
}
static void F_25 ( struct V_26 * V_27 )
{
if ( F_16 () )
F_26 ( V_27 ) ;
}
static void F_27 ( struct V_26 * V_27 )
{
if ( V_27 -> V_28 )
F_28 ( V_27 ) ;
}
static enum V_29 F_29 ( struct V_26 * V_27 )
{
if ( F_16 () )
return F_30 ( V_27 , V_30 ) ;
return V_31 ;
}
static void F_31 ( struct V_32 * V_33 )
{
if ( F_16 () )
F_32 ( V_33 , V_30 ) ;
else
F_33 ( V_33 ) ;
}
static void
F_34 ( struct V_4 * V_5 ,
unsigned long V_12 , unsigned long V_13 ,
unsigned long V_8 , int V_24 )
{
if ( F_16 () )
F_35 ( V_5 , V_12 , V_13 , V_8 , V_24 ) ;
else
F_14 ( V_5 , V_12 , V_13 , V_8 , V_24 ) ;
}
static int F_15 ( T_1 V_15 , T_1 V_16 , int V_17 )
{
return - V_19 ;
}
static int F_21 ( struct V_21 * V_22 )
{
return - 1 ;
}
static enum V_29 F_29 ( struct V_26 * V_27 )
{
return V_31 ;
}
static void F_23 ( struct V_25 * V_22 ) { }
static void F_25 ( struct V_26 * V_27 ) { }
static void F_27 ( struct V_26 * V_27 ) { }
static void F_31 ( struct V_32 * V_33 )
{
F_33 ( V_33 ) ;
}
static void F_31 ( struct V_32 * V_33 )
{
F_36 ( V_33 ) ;
}
static int F_37 ( T_2 V_34 )
{
if ( V_35 ) {
if ( V_34 < V_35 )
return 0 ;
} else {
if ( V_34 <= V_20 )
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
T_2 V_36 , V_37 , V_34 ;
unsigned long V_8 ;
int V_24 ;
V_36 = V_7 -> V_38 ;
V_37 = F_39 ( V_10 ) ;
V_34 = V_37 - V_36 ;
F_9 ( V_8 ) ;
V_24 = F_2 () ;
if ( ! F_37 ( V_34 ) )
goto V_39;
F_40 ( & V_40 , V_8 ) ;
if ( ! F_37 ( V_34 ) )
goto V_41;
F_34 ( V_5 , V_42 , V_13 , V_8 , V_24 ) ;
F_41 ( V_5 , V_8 , 5 , V_24 ) ;
if ( V_7 -> V_43 != V_44 )
goto V_41;
V_7 -> V_45 = V_13 ;
if ( F_7 ( ! F_42 () ) ) {
V_20 = V_34 ;
F_43 ( V_5 , V_46 , V_10 ) ;
}
V_44 ++ ;
V_41:
F_44 ( & V_40 , V_8 ) ;
V_39:
V_7 -> V_43 = V_44 ;
V_7 -> V_38 = F_39 ( V_10 ) ;
F_34 ( V_5 , V_42 , V_13 , V_8 , V_24 ) ;
}
static inline void
F_45 ( unsigned long V_12 , unsigned long V_13 )
{
int V_10 ;
struct V_4 * V_5 = V_14 ;
struct V_6 * V_7 ;
unsigned long V_8 ;
if ( F_7 ( ! V_47 ) )
return;
V_10 = F_6 () ;
if ( F_8 ( V_11 , V_10 ) )
return;
V_7 = V_5 -> V_7 [ V_10 ] ;
if ( F_46 ( ! V_7 ) || F_47 ( & V_7 -> V_9 ) )
return;
F_48 ( & V_7 -> V_9 ) ;
V_7 -> V_43 = V_44 ;
V_7 -> V_38 = F_39 ( V_10 ) ;
V_7 -> V_48 = V_13 ? : V_12 ;
F_9 ( V_8 ) ;
F_34 ( V_5 , V_12 , V_13 , V_8 , F_2 () ) ;
F_8 ( V_11 , V_10 ) = 1 ;
F_12 ( & V_7 -> V_9 ) ;
}
static inline void
F_49 ( unsigned long V_12 , unsigned long V_13 )
{
int V_10 ;
struct V_4 * V_5 = V_14 ;
struct V_6 * V_7 ;
unsigned long V_8 ;
V_10 = F_6 () ;
if ( F_46 ( F_8 ( V_11 , V_10 ) ) )
F_8 ( V_11 , V_10 ) = 0 ;
else
return;
if ( ! V_47 )
return;
V_7 = V_5 -> V_7 [ V_10 ] ;
if ( F_46 ( ! V_7 ) ||
! V_7 -> V_48 || F_47 ( & V_7 -> V_9 ) )
return;
F_48 ( & V_7 -> V_9 ) ;
F_9 ( V_8 ) ;
F_34 ( V_5 , V_12 , V_13 , V_8 , F_2 () ) ;
F_38 ( V_5 , V_7 , V_13 ? : V_12 , V_10 ) ;
V_7 -> V_48 = 0 ;
F_12 ( & V_7 -> V_9 ) ;
}
void F_50 ( void )
{
if ( F_1 () || F_3 () )
F_45 ( V_42 , V_49 ) ;
}
void F_51 ( void )
{
if ( F_1 () || F_3 () )
F_49 ( V_42 , V_49 ) ;
}
void F_52 ( unsigned long V_50 , unsigned long V_51 )
{
if ( ! F_1 () && F_3 () )
F_49 ( V_50 , V_51 ) ;
}
void F_53 ( unsigned long V_50 , unsigned long V_51 )
{
if ( ! F_1 () && F_3 () )
F_45 ( V_50 , V_51 ) ;
}
void F_54 ( unsigned long V_12 )
{
}
void F_55 ( unsigned long V_12 )
{
}
inline void F_56 ( struct V_52 * V_53 )
{
}
void F_57 ( void )
{
if ( ! F_1 () && F_3 () )
F_49 ( V_42 , V_49 ) ;
}
void F_58 ( void )
{
if ( ! F_1 () && F_3 () )
F_45 ( V_42 , V_49 ) ;
}
void F_59 ( unsigned long V_54 )
{
if ( ! F_1 () && F_3 () )
F_49 ( V_42 , V_54 ) ;
}
void F_60 ( unsigned long V_54 )
{
if ( ! F_1 () && F_3 () )
F_45 ( V_42 , V_54 ) ;
}
void F_61 ( unsigned long V_50 , unsigned long V_51 )
{
if ( F_1 () && ! F_3 () )
F_49 ( V_50 , V_51 ) ;
}
void F_62 ( unsigned long V_50 , unsigned long V_51 )
{
if ( F_1 () && ! F_3 () )
F_45 ( V_50 , V_51 ) ;
}
static int F_20 ( struct V_4 * V_5 , int V_55 )
{
int V_23 = 0 ;
if ( ! V_55 )
V_23 = F_63 ( & V_56 ) ;
else
V_23 = F_64 ( & F_23 ,
& F_21 ) ;
if ( ! V_23 && F_65 () )
V_47 = 1 ;
else
V_47 = 0 ;
return V_23 ;
}
static void F_17 ( struct V_4 * V_5 , int V_55 )
{
V_47 = 0 ;
if ( ! V_55 )
F_66 ( & V_56 ) ;
else
F_67 () ;
}
static void F_68 ( struct V_4 * V_5 )
{
V_57 = V_58 & V_59 ;
V_58 |= V_59 ;
V_20 = 0 ;
V_14 = V_5 ;
F_69 () ;
F_19 ( V_5 ) ;
if ( F_20 ( V_5 , F_16 () ) )
F_70 ( V_60 L_1 ) ;
}
static void F_71 ( struct V_4 * V_5 )
{
F_17 ( V_5 , F_16 () ) ;
if ( ! V_57 )
V_58 &= ~ V_59 ;
}
static void F_72 ( struct V_4 * V_5 )
{
V_47 = 1 ;
}
static void F_73 ( struct V_4 * V_5 )
{
V_47 = 0 ;
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
F_78 ( V_61 ) ;
F_79 ( V_62 ) ;
F_80 ( V_63 ) ;
return 0 ;
}
