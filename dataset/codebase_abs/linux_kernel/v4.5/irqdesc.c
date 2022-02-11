static void T_1 F_1 ( void )
{
F_2 ( & V_1 , V_2 ) ;
F_3 ( V_1 ) ;
}
static void T_1 F_1 ( void )
{
}
static int F_4 ( struct V_3 * V_4 , T_2 V_5 , int V_6 )
{
if ( ! F_5 ( & V_4 -> V_7 . V_8 ,
V_5 , V_6 ) )
return - V_9 ;
#ifdef F_6
if ( ! F_5 ( & V_4 -> V_10 , V_5 , V_6 ) ) {
F_7 ( V_4 -> V_7 . V_8 ) ;
return - V_9 ;
}
#endif
return 0 ;
}
static void F_8 ( struct V_3 * V_4 , int V_6 )
{
F_9 ( V_4 -> V_7 . V_8 , V_1 ) ;
#ifdef F_6
F_10 ( V_4 -> V_10 ) ;
#endif
#ifdef F_11
V_4 -> V_7 . V_6 = V_6 ;
#endif
}
static inline int
F_4 ( struct V_3 * V_4 , T_2 V_5 , int V_6 ) { return 0 ; }
static inline void F_8 ( struct V_3 * V_4 , int V_6 ) { }
static void F_12 ( unsigned int V_11 , struct V_3 * V_4 , int V_6 ,
struct V_12 * V_13 )
{
int V_14 ;
V_4 -> V_7 . V_15 = NULL ;
V_4 -> V_7 . V_16 = NULL ;
V_4 -> V_17 . V_18 = & V_4 -> V_7 ;
V_4 -> V_17 . V_11 = V_11 ;
V_4 -> V_17 . V_19 = & V_20 ;
V_4 -> V_17 . V_21 = NULL ;
F_13 ( V_4 , ~ 0 , V_22 ) ;
F_14 ( & V_4 -> V_17 , V_23 ) ;
V_4 -> V_24 = V_25 ;
V_4 -> V_26 = 1 ;
V_4 -> V_27 = 0 ;
V_4 -> V_28 = 0 ;
V_4 -> V_29 = NULL ;
V_4 -> V_13 = V_13 ;
F_15 ( V_14 )
* F_16 ( V_4 -> V_30 , V_14 ) = 0 ;
F_8 ( V_4 , V_6 ) ;
}
static void F_17 ( unsigned int V_11 , struct V_3 * V_4 )
{
F_18 ( & V_31 , V_11 , V_4 ) ;
}
struct V_3 * F_19 ( unsigned int V_11 )
{
return F_20 ( & V_31 , V_11 ) ;
}
static void F_21 ( unsigned int V_11 )
{
F_22 ( & V_31 , V_11 ) ;
}
static void F_23 ( struct V_3 * V_4 )
{
#ifdef F_6
F_7 ( V_4 -> V_10 ) ;
#endif
F_7 ( V_4 -> V_7 . V_8 ) ;
}
static inline void F_23 ( struct V_3 * V_4 ) { }
void F_24 ( void )
{
F_25 ( & V_32 ) ;
}
void F_26 ( void )
{
F_27 ( & V_32 ) ;
}
static struct V_3 * F_28 ( int V_11 , int V_6 , struct V_12 * V_13 )
{
struct V_3 * V_4 ;
T_2 V_5 = V_33 ;
V_4 = F_29 ( sizeof( * V_4 ) , V_5 , V_6 ) ;
if ( ! V_4 )
return NULL ;
V_4 -> V_30 = F_30 (unsigned int) ;
if ( ! V_4 -> V_30 )
goto V_34;
if ( F_4 ( V_4 , V_5 , V_6 ) )
goto V_35;
F_31 ( & V_4 -> V_36 ) ;
F_32 ( & V_4 -> V_36 , & V_37 ) ;
F_33 ( & V_4 -> V_38 ) ;
F_12 ( V_11 , V_4 , V_6 , V_13 ) ;
return V_4 ;
V_35:
F_34 ( V_4 -> V_30 ) ;
V_34:
F_35 ( V_4 ) ;
return NULL ;
}
static void F_36 ( struct V_39 * V_40 )
{
struct V_3 * V_4 = F_37 ( V_40 , struct V_3 , V_38 ) ;
F_23 ( V_4 ) ;
F_34 ( V_4 -> V_30 ) ;
F_35 ( V_4 ) ;
}
static void F_38 ( unsigned int V_11 )
{
struct V_3 * V_4 = F_19 ( V_11 ) ;
F_39 ( V_11 , V_4 ) ;
F_25 ( & V_32 ) ;
F_21 ( V_11 ) ;
F_27 ( & V_32 ) ;
F_40 ( & V_4 -> V_38 , F_36 ) ;
}
static int F_41 ( unsigned int V_41 , unsigned int V_42 , int V_6 ,
struct V_12 * V_13 )
{
struct V_3 * V_4 ;
int V_43 ;
for ( V_43 = 0 ; V_43 < V_42 ; V_43 ++ ) {
V_4 = F_28 ( V_41 + V_43 , V_6 , V_13 ) ;
if ( ! V_4 )
goto V_44;
F_25 ( & V_32 ) ;
F_17 ( V_41 + V_43 , V_4 ) ;
F_27 ( & V_32 ) ;
}
return V_41 ;
V_44:
for ( V_43 -- ; V_43 >= 0 ; V_43 -- )
F_38 ( V_41 + V_43 ) ;
F_25 ( & V_32 ) ;
F_42 ( V_45 , V_41 , V_42 ) ;
F_27 ( & V_32 ) ;
return - V_9 ;
}
static int F_43 ( unsigned int V_46 )
{
if ( V_46 > V_47 )
return - V_9 ;
V_48 = V_46 ;
return 0 ;
}
int T_1 F_44 ( void )
{
int V_43 , V_49 , V_6 = V_50 ;
struct V_3 * V_4 ;
F_1 () ;
V_49 = F_45 () ;
F_46 ( V_51 L_1 , V_52 , V_48 , V_49 ) ;
if ( F_47 ( V_48 > V_47 ) )
V_48 = V_47 ;
if ( F_47 ( V_49 > V_47 ) )
V_49 = V_47 ;
if ( V_49 > V_48 )
V_48 = V_49 ;
for ( V_43 = 0 ; V_43 < V_49 ; V_43 ++ ) {
V_4 = F_28 ( V_43 , V_6 , NULL ) ;
F_48 ( V_43 , V_45 ) ;
F_17 ( V_43 , V_4 ) ;
}
return F_49 () ;
}
int T_1 F_44 ( void )
{
int V_53 , V_43 , V_6 = V_50 ;
struct V_3 * V_4 ;
F_1 () ;
F_46 ( V_51 L_2 , V_52 ) ;
V_4 = V_3 ;
V_53 = F_50 ( V_3 ) ;
for ( V_43 = 0 ; V_43 < V_53 ; V_43 ++ ) {
V_4 [ V_43 ] . V_30 = F_30 (unsigned int) ;
F_4 ( & V_4 [ V_43 ] , V_33 , V_6 ) ;
F_31 ( & V_4 [ V_43 ] . V_36 ) ;
F_32 ( & V_4 [ V_43 ] . V_36 , & V_37 ) ;
F_12 ( V_43 , & V_4 [ V_43 ] , V_6 , NULL ) ;
}
return F_49 () ;
}
struct V_3 * F_19 ( unsigned int V_11 )
{
return ( V_11 < V_52 ) ? V_3 + V_11 : NULL ;
}
static void F_38 ( unsigned int V_11 )
{
struct V_3 * V_4 = F_19 ( V_11 ) ;
unsigned long V_54 ;
F_51 ( & V_4 -> V_36 , V_54 ) ;
F_12 ( V_11 , V_4 , F_52 ( V_4 ) , NULL ) ;
F_53 ( & V_4 -> V_36 , V_54 ) ;
}
static inline int F_41 ( unsigned int V_41 , unsigned int V_42 , int V_6 ,
struct V_12 * V_13 )
{
T_3 V_43 ;
for ( V_43 = 0 ; V_43 < V_42 ; V_43 ++ ) {
struct V_3 * V_4 = F_19 ( V_41 + V_43 ) ;
V_4 -> V_13 = V_13 ;
}
return V_41 ;
}
static int F_43 ( unsigned int V_46 )
{
return - V_9 ;
}
void F_54 ( unsigned int V_11 )
{
F_25 ( & V_32 ) ;
F_55 ( V_45 , V_11 , 1 ) ;
F_27 ( & V_32 ) ;
}
void F_56 ( unsigned int V_11 )
{
F_38 ( V_11 ) ;
}
int F_57 ( unsigned int V_11 )
{
struct V_3 * V_4 = F_19 ( V_11 ) ;
if ( ! V_4 )
return - V_55 ;
F_58 ( V_4 ) ;
return 0 ;
}
int F_59 ( struct V_56 * V_57 , unsigned int V_58 ,
bool V_59 , struct V_60 * V_61 )
{
struct V_60 * V_62 = F_60 ( V_61 ) ;
unsigned int V_11 = V_58 ;
int V_63 = 0 ;
F_61 () ;
#ifdef F_62
if ( V_59 )
V_11 = F_63 ( V_57 , V_58 ) ;
#endif
if ( F_64 ( ! V_11 || V_11 >= V_48 ) ) {
F_65 ( V_11 ) ;
V_63 = - V_55 ;
} else {
F_57 ( V_11 ) ;
}
F_66 () ;
F_60 ( V_62 ) ;
return V_63 ;
}
void F_67 ( unsigned int V_64 , unsigned int V_42 )
{
int V_43 ;
if ( V_64 >= V_48 || ( V_64 + V_42 ) > V_48 )
return;
for ( V_43 = 0 ; V_43 < V_42 ; V_43 ++ )
F_38 ( V_64 + V_43 ) ;
F_25 ( & V_32 ) ;
F_42 ( V_45 , V_64 , V_42 ) ;
F_27 ( & V_32 ) ;
}
int T_4
F_68 ( int V_11 , unsigned int V_64 , unsigned int V_42 , int V_6 ,
struct V_12 * V_13 )
{
int V_41 , V_63 ;
if ( ! V_42 )
return - V_55 ;
if ( V_11 >= 0 ) {
if ( V_64 > V_11 )
return - V_55 ;
V_64 = V_11 ;
} else {
V_64 = F_69 ( V_64 ) ;
}
F_25 ( & V_32 ) ;
V_41 = F_70 ( V_45 , V_47 ,
V_64 , V_42 , 0 ) ;
V_63 = - V_65 ;
if ( V_11 >= 0 && V_41 != V_11 )
goto V_44;
if ( V_41 + V_42 > V_48 ) {
V_63 = F_43 ( V_41 + V_42 ) ;
if ( V_63 )
goto V_44;
}
F_55 ( V_45 , V_41 , V_42 ) ;
F_27 ( & V_32 ) ;
return F_41 ( V_41 , V_42 , V_6 , V_13 ) ;
V_44:
F_27 ( & V_32 ) ;
return V_63 ;
}
unsigned int F_71 ( int V_42 , int V_6 )
{
int V_43 , V_11 = F_68 ( - 1 , 0 , V_42 , V_6 , NULL ) ;
if ( V_11 < 0 )
return 0 ;
for ( V_43 = V_11 ; V_42 > 0 ; V_43 ++ , V_42 -- ) {
if ( F_72 ( V_43 , V_6 ) )
goto V_44;
F_73 ( V_43 , V_66 ) ;
}
return V_11 ;
V_44:
for ( V_43 -- ; V_43 >= V_11 ; V_43 -- ) {
F_74 ( V_43 , V_66 | V_67 ) ;
F_75 ( V_43 ) ;
}
F_67 ( V_11 , V_42 ) ;
return 0 ;
}
void F_76 ( unsigned int V_64 , int V_42 )
{
int V_43 , V_68 ;
for ( V_43 = V_64 , V_68 = V_42 ; V_68 > 0 ; V_43 ++ , V_68 -- ) {
F_74 ( V_43 , V_66 | V_67 ) ;
F_75 ( V_43 ) ;
}
F_67 ( V_64 , V_42 ) ;
}
unsigned int F_77 ( unsigned int V_69 )
{
return F_78 ( V_45 , V_48 , V_69 ) ;
}
struct V_3 *
F_79 ( unsigned int V_11 , unsigned long * V_54 , bool V_70 ,
unsigned int V_71 )
{
struct V_3 * V_4 = F_19 ( V_11 ) ;
if ( V_4 ) {
if ( V_71 & V_72 ) {
if ( ( V_71 & V_73 ) &&
! F_80 ( V_4 ) )
return NULL ;
if ( ! ( V_71 & V_73 ) &&
F_80 ( V_4 ) )
return NULL ;
}
if ( V_70 )
F_81 ( V_4 ) ;
F_51 ( & V_4 -> V_36 , * V_54 ) ;
}
return V_4 ;
}
void F_82 ( struct V_3 * V_4 , unsigned long V_54 , bool V_70 )
{
F_53 ( & V_4 -> V_36 , V_54 ) ;
if ( V_70 )
F_83 ( V_4 ) ;
}
int F_84 ( unsigned int V_11 )
{
struct V_3 * V_4 = F_19 ( V_11 ) ;
if ( ! V_4 )
return - V_55 ;
if ( V_4 -> V_74 )
return - V_55 ;
V_4 -> V_74 = F_85 ( sizeof( * V_4 -> V_74 ) , V_33 ) ;
if ( ! V_4 -> V_74 )
return - V_9 ;
F_86 ( V_11 ) ;
return 0 ;
}
void F_87 ( unsigned int V_11 )
{
F_88 ( F_19 ( V_11 ) ) ;
}
unsigned int F_89 ( unsigned int V_11 , int V_14 )
{
struct V_3 * V_4 = F_19 ( V_11 ) ;
return V_4 && V_4 -> V_30 ?
* F_16 ( V_4 -> V_30 , V_14 ) : 0 ;
}
unsigned int V_30 ( unsigned int V_11 )
{
struct V_3 * V_4 = F_19 ( V_11 ) ;
int V_14 ;
unsigned int V_75 = 0 ;
if ( ! V_4 || ! V_4 -> V_30 )
return 0 ;
F_15 (cpu)
V_75 += * F_16 ( V_4 -> V_30 , V_14 ) ;
return V_75 ;
}
unsigned int F_90 ( unsigned int V_11 )
{
unsigned int V_75 ;
F_24 () ;
V_75 = V_30 ( V_11 ) ;
F_26 () ;
return V_75 ;
}
