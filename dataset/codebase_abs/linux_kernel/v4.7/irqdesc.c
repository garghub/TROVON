static int T_1 F_1 ( char * V_1 )
{
F_2 ( & V_2 , V_3 ) ;
F_3 ( V_1 , V_2 ) ;
F_4 ( F_5 () , V_2 ) ;
return 1 ;
}
static void T_1 F_6 ( void )
{
#ifdef F_7
if ( ! V_2 )
F_2 ( & V_2 , V_3 ) ;
#endif
if ( F_8 ( V_2 ) )
F_9 ( V_2 ) ;
}
static void T_1 F_6 ( void )
{
}
static int F_10 ( struct V_4 * V_5 , T_2 V_6 , int V_7 )
{
if ( ! F_11 ( & V_5 -> V_8 . V_9 ,
V_6 , V_7 ) )
return - V_10 ;
#ifdef F_12
if ( ! F_11 ( & V_5 -> V_11 , V_6 , V_7 ) ) {
F_13 ( V_5 -> V_8 . V_9 ) ;
return - V_10 ;
}
#endif
return 0 ;
}
static void F_14 ( struct V_4 * V_5 , int V_7 )
{
F_15 ( V_5 -> V_8 . V_9 , V_2 ) ;
#ifdef F_12
F_16 ( V_5 -> V_11 ) ;
#endif
#ifdef F_17
V_5 -> V_8 . V_7 = V_7 ;
#endif
}
static inline int
F_10 ( struct V_4 * V_5 , T_2 V_6 , int V_7 ) { return 0 ; }
static inline void F_14 ( struct V_4 * V_5 , int V_7 ) { }
static void F_18 ( unsigned int V_12 , struct V_4 * V_5 , int V_7 ,
struct V_13 * V_14 )
{
int V_15 ;
V_5 -> V_8 . V_16 = NULL ;
V_5 -> V_8 . V_17 = NULL ;
V_5 -> V_18 . V_19 = & V_5 -> V_8 ;
V_5 -> V_18 . V_12 = V_12 ;
V_5 -> V_18 . V_20 = & V_21 ;
V_5 -> V_18 . V_22 = NULL ;
F_19 ( V_5 , ~ 0 , V_23 ) ;
F_20 ( & V_5 -> V_18 , V_24 ) ;
V_5 -> V_25 = V_26 ;
V_5 -> V_27 = 1 ;
V_5 -> V_28 = 0 ;
V_5 -> V_29 = 0 ;
V_5 -> V_30 = NULL ;
V_5 -> V_14 = V_14 ;
F_21 ( V_15 )
* F_22 ( V_5 -> V_31 , V_15 ) = 0 ;
F_14 ( V_5 , V_7 ) ;
}
static void F_23 ( unsigned int V_12 , struct V_4 * V_5 )
{
F_24 ( & V_32 , V_12 , V_5 ) ;
}
struct V_4 * F_25 ( unsigned int V_12 )
{
return F_26 ( & V_32 , V_12 ) ;
}
static void F_27 ( unsigned int V_12 )
{
F_28 ( & V_32 , V_12 ) ;
}
static void F_29 ( struct V_4 * V_5 )
{
#ifdef F_12
F_13 ( V_5 -> V_11 ) ;
#endif
F_13 ( V_5 -> V_8 . V_9 ) ;
}
static inline void F_29 ( struct V_4 * V_5 ) { }
void F_30 ( void )
{
F_31 ( & V_33 ) ;
}
void F_32 ( void )
{
F_33 ( & V_33 ) ;
}
static struct V_4 * F_34 ( int V_12 , int V_7 , struct V_13 * V_14 )
{
struct V_4 * V_5 ;
T_2 V_6 = V_34 ;
V_5 = F_35 ( sizeof( * V_5 ) , V_6 , V_7 ) ;
if ( ! V_5 )
return NULL ;
V_5 -> V_31 = F_36 (unsigned int) ;
if ( ! V_5 -> V_31 )
goto V_35;
if ( F_10 ( V_5 , V_6 , V_7 ) )
goto V_36;
F_37 ( & V_5 -> V_37 ) ;
F_38 ( & V_5 -> V_37 , & V_38 ) ;
F_39 ( & V_5 -> V_39 ) ;
F_18 ( V_12 , V_5 , V_7 , V_14 ) ;
return V_5 ;
V_36:
F_40 ( V_5 -> V_31 ) ;
V_35:
F_41 ( V_5 ) ;
return NULL ;
}
static void F_42 ( struct V_40 * V_41 )
{
struct V_4 * V_5 = F_43 ( V_41 , struct V_4 , V_39 ) ;
F_29 ( V_5 ) ;
F_40 ( V_5 -> V_31 ) ;
F_41 ( V_5 ) ;
}
static void F_44 ( unsigned int V_12 )
{
struct V_4 * V_5 = F_25 ( V_12 ) ;
F_45 ( V_12 , V_5 ) ;
F_31 ( & V_33 ) ;
F_27 ( V_12 ) ;
F_33 ( & V_33 ) ;
F_46 ( & V_5 -> V_39 , F_42 ) ;
}
static int F_47 ( unsigned int V_42 , unsigned int V_43 , int V_7 ,
struct V_13 * V_14 )
{
struct V_4 * V_5 ;
int V_44 ;
for ( V_44 = 0 ; V_44 < V_43 ; V_44 ++ ) {
V_5 = F_34 ( V_42 + V_44 , V_7 , V_14 ) ;
if ( ! V_5 )
goto V_45;
F_31 ( & V_33 ) ;
F_23 ( V_42 + V_44 , V_5 ) ;
F_33 ( & V_33 ) ;
}
return V_42 ;
V_45:
for ( V_44 -- ; V_44 >= 0 ; V_44 -- )
F_44 ( V_42 + V_44 ) ;
F_31 ( & V_33 ) ;
F_48 ( V_46 , V_42 , V_43 ) ;
F_33 ( & V_33 ) ;
return - V_10 ;
}
static int F_49 ( unsigned int V_47 )
{
if ( V_47 > V_48 )
return - V_10 ;
V_49 = V_47 ;
return 0 ;
}
int T_1 F_50 ( void )
{
int V_44 , V_50 , V_7 = V_51 ;
struct V_4 * V_5 ;
F_6 () ;
V_50 = F_51 () ;
F_52 ( V_52 L_1 , V_53 , V_49 , V_50 ) ;
if ( F_53 ( V_49 > V_48 ) )
V_49 = V_48 ;
if ( F_53 ( V_50 > V_48 ) )
V_50 = V_48 ;
if ( V_50 > V_49 )
V_49 = V_50 ;
for ( V_44 = 0 ; V_44 < V_50 ; V_44 ++ ) {
V_5 = F_34 ( V_44 , V_7 , NULL ) ;
F_54 ( V_44 , V_46 ) ;
F_23 ( V_44 , V_5 ) ;
}
return F_55 () ;
}
int T_1 F_50 ( void )
{
int V_54 , V_44 , V_7 = V_51 ;
struct V_4 * V_5 ;
F_6 () ;
F_52 ( V_52 L_2 , V_53 ) ;
V_5 = V_4 ;
V_54 = F_56 ( V_4 ) ;
for ( V_44 = 0 ; V_44 < V_54 ; V_44 ++ ) {
V_5 [ V_44 ] . V_31 = F_36 (unsigned int) ;
F_10 ( & V_5 [ V_44 ] , V_34 , V_7 ) ;
F_37 ( & V_5 [ V_44 ] . V_37 ) ;
F_38 ( & V_5 [ V_44 ] . V_37 , & V_38 ) ;
F_18 ( V_44 , & V_5 [ V_44 ] , V_7 , NULL ) ;
}
return F_55 () ;
}
struct V_4 * F_25 ( unsigned int V_12 )
{
return ( V_12 < V_53 ) ? V_4 + V_12 : NULL ;
}
static void F_44 ( unsigned int V_12 )
{
struct V_4 * V_5 = F_25 ( V_12 ) ;
unsigned long V_55 ;
F_57 ( & V_5 -> V_37 , V_55 ) ;
F_18 ( V_12 , V_5 , F_58 ( V_5 ) , NULL ) ;
F_59 ( & V_5 -> V_37 , V_55 ) ;
}
static inline int F_47 ( unsigned int V_42 , unsigned int V_43 , int V_7 ,
struct V_13 * V_14 )
{
T_3 V_44 ;
for ( V_44 = 0 ; V_44 < V_43 ; V_44 ++ ) {
struct V_4 * V_5 = F_25 ( V_42 + V_44 ) ;
V_5 -> V_14 = V_14 ;
}
return V_42 ;
}
static int F_49 ( unsigned int V_47 )
{
return - V_10 ;
}
void F_60 ( unsigned int V_12 )
{
F_31 ( & V_33 ) ;
F_61 ( V_46 , V_12 , 1 ) ;
F_33 ( & V_33 ) ;
}
void F_62 ( unsigned int V_12 )
{
F_44 ( V_12 ) ;
}
int F_63 ( unsigned int V_12 )
{
struct V_4 * V_5 = F_25 ( V_12 ) ;
if ( ! V_5 )
return - V_56 ;
F_64 ( V_5 ) ;
return 0 ;
}
int F_65 ( struct V_57 * V_58 , unsigned int V_59 ,
bool V_60 , struct V_61 * V_62 )
{
struct V_61 * V_63 = F_66 ( V_62 ) ;
unsigned int V_12 = V_59 ;
int V_64 = 0 ;
F_67 () ;
#ifdef F_68
if ( V_60 )
V_12 = F_69 ( V_58 , V_59 ) ;
#endif
if ( F_70 ( ! V_12 || V_12 >= V_49 ) ) {
F_71 ( V_12 ) ;
V_64 = - V_56 ;
} else {
F_63 ( V_12 ) ;
}
F_72 () ;
F_66 ( V_63 ) ;
return V_64 ;
}
void F_73 ( unsigned int V_65 , unsigned int V_43 )
{
int V_44 ;
if ( V_65 >= V_49 || ( V_65 + V_43 ) > V_49 )
return;
for ( V_44 = 0 ; V_44 < V_43 ; V_44 ++ )
F_44 ( V_65 + V_44 ) ;
F_31 ( & V_33 ) ;
F_48 ( V_46 , V_65 , V_43 ) ;
F_33 ( & V_33 ) ;
}
int T_4
F_74 ( int V_12 , unsigned int V_65 , unsigned int V_43 , int V_7 ,
struct V_13 * V_14 )
{
int V_42 , V_64 ;
if ( ! V_43 )
return - V_56 ;
if ( V_12 >= 0 ) {
if ( V_65 > V_12 )
return - V_56 ;
V_65 = V_12 ;
} else {
V_65 = F_75 ( V_65 ) ;
}
F_31 ( & V_33 ) ;
V_42 = F_76 ( V_46 , V_48 ,
V_65 , V_43 , 0 ) ;
V_64 = - V_66 ;
if ( V_12 >= 0 && V_42 != V_12 )
goto V_45;
if ( V_42 + V_43 > V_49 ) {
V_64 = F_49 ( V_42 + V_43 ) ;
if ( V_64 )
goto V_45;
}
F_61 ( V_46 , V_42 , V_43 ) ;
F_33 ( & V_33 ) ;
return F_47 ( V_42 , V_43 , V_7 , V_14 ) ;
V_45:
F_33 ( & V_33 ) ;
return V_64 ;
}
unsigned int F_77 ( int V_43 , int V_7 )
{
int V_44 , V_12 = F_74 ( - 1 , 0 , V_43 , V_7 , NULL ) ;
if ( V_12 < 0 )
return 0 ;
for ( V_44 = V_12 ; V_43 > 0 ; V_44 ++ , V_43 -- ) {
if ( F_78 ( V_44 , V_7 ) )
goto V_45;
F_79 ( V_44 , V_67 ) ;
}
return V_12 ;
V_45:
for ( V_44 -- ; V_44 >= V_12 ; V_44 -- ) {
F_80 ( V_44 , V_67 | V_68 ) ;
F_81 ( V_44 ) ;
}
F_73 ( V_12 , V_43 ) ;
return 0 ;
}
void F_82 ( unsigned int V_65 , int V_43 )
{
int V_44 , V_69 ;
for ( V_44 = V_65 , V_69 = V_43 ; V_69 > 0 ; V_44 ++ , V_69 -- ) {
F_80 ( V_44 , V_67 | V_68 ) ;
F_81 ( V_44 ) ;
}
F_73 ( V_65 , V_43 ) ;
}
unsigned int F_83 ( unsigned int V_70 )
{
return F_84 ( V_46 , V_49 , V_70 ) ;
}
struct V_4 *
F_85 ( unsigned int V_12 , unsigned long * V_55 , bool V_71 ,
unsigned int V_72 )
{
struct V_4 * V_5 = F_25 ( V_12 ) ;
if ( V_5 ) {
if ( V_72 & V_73 ) {
if ( ( V_72 & V_74 ) &&
! F_86 ( V_5 ) )
return NULL ;
if ( ! ( V_72 & V_74 ) &&
F_86 ( V_5 ) )
return NULL ;
}
if ( V_71 )
F_87 ( V_5 ) ;
F_57 ( & V_5 -> V_37 , * V_55 ) ;
}
return V_5 ;
}
void F_88 ( struct V_4 * V_5 , unsigned long V_55 , bool V_71 )
{
F_59 ( & V_5 -> V_37 , V_55 ) ;
if ( V_71 )
F_89 ( V_5 ) ;
}
int F_90 ( unsigned int V_12 ,
const struct V_75 * V_9 )
{
struct V_4 * V_5 = F_25 ( V_12 ) ;
if ( ! V_5 )
return - V_56 ;
if ( V_5 -> V_76 )
return - V_56 ;
V_5 -> V_76 = F_91 ( sizeof( * V_5 -> V_76 ) , V_34 ) ;
if ( ! V_5 -> V_76 )
return - V_10 ;
if ( V_9 )
V_5 -> V_77 = V_9 ;
else
V_5 -> V_77 = V_78 ;
F_92 ( V_12 ) ;
return 0 ;
}
int F_93 ( unsigned int V_12 )
{
return F_90 ( V_12 , NULL ) ;
}
int F_94 ( unsigned int V_12 , struct V_75 * V_9 )
{
struct V_4 * V_5 = F_25 ( V_12 ) ;
if ( ! V_5 || ! V_5 -> V_76 )
return - V_56 ;
if ( V_9 )
F_15 ( V_9 , V_5 -> V_77 ) ;
return 0 ;
}
void F_95 ( unsigned int V_12 )
{
F_96 ( F_25 ( V_12 ) ) ;
}
unsigned int F_97 ( unsigned int V_12 , int V_15 )
{
struct V_4 * V_5 = F_25 ( V_12 ) ;
return V_5 && V_5 -> V_31 ?
* F_22 ( V_5 -> V_31 , V_15 ) : 0 ;
}
unsigned int V_31 ( unsigned int V_12 )
{
struct V_4 * V_5 = F_25 ( V_12 ) ;
int V_15 ;
unsigned int V_79 = 0 ;
if ( ! V_5 || ! V_5 -> V_31 )
return 0 ;
F_21 (cpu)
V_79 += * F_22 ( V_5 -> V_31 , V_15 ) ;
return V_79 ;
}
unsigned int F_98 ( unsigned int V_12 )
{
unsigned int V_79 ;
F_30 () ;
V_79 = V_31 ( V_12 ) ;
F_32 () ;
return V_79 ;
}
