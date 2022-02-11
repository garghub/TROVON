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
if ( ! F_5 ( & V_4 -> V_7 . V_8 , V_5 , V_6 ) )
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
V_4 -> V_7 . V_6 = V_6 ;
F_9 ( V_4 -> V_7 . V_8 , V_1 ) ;
#ifdef F_6
F_10 ( V_4 -> V_10 ) ;
#endif
}
static inline int F_11 ( struct V_3 * V_4 )
{
return V_4 -> V_7 . V_6 ;
}
static inline int
F_4 ( struct V_3 * V_4 , T_2 V_5 , int V_6 ) { return 0 ; }
static inline void F_8 ( struct V_3 * V_4 , int V_6 ) { }
static inline int F_11 ( struct V_3 * V_4 ) { return 0 ; }
static void F_12 ( unsigned int V_11 , struct V_3 * V_4 , int V_6 ,
struct V_12 * V_13 )
{
int V_14 ;
V_4 -> V_7 . V_11 = V_11 ;
V_4 -> V_7 . V_15 = & V_16 ;
V_4 -> V_7 . V_17 = NULL ;
V_4 -> V_7 . V_18 = NULL ;
V_4 -> V_7 . V_19 = NULL ;
F_13 ( V_4 , ~ 0 , V_20 ) ;
F_14 ( & V_4 -> V_7 , V_21 ) ;
V_4 -> V_22 = V_23 ;
V_4 -> V_24 = 1 ;
V_4 -> V_25 = 0 ;
V_4 -> V_26 = 0 ;
V_4 -> V_27 = NULL ;
V_4 -> V_13 = V_13 ;
F_15 ( V_14 )
* F_16 ( V_4 -> V_28 , V_14 ) = 0 ;
F_8 ( V_4 , V_6 ) ;
}
static void F_17 ( unsigned int V_11 , struct V_3 * V_4 )
{
F_18 ( & V_29 , V_11 , V_4 ) ;
}
struct V_3 * F_19 ( unsigned int V_11 )
{
return F_20 ( & V_29 , V_11 ) ;
}
static void F_21 ( unsigned int V_11 )
{
F_22 ( & V_29 , V_11 ) ;
}
static void F_23 ( struct V_3 * V_4 )
{
#ifdef F_6
F_7 ( V_4 -> V_10 ) ;
#endif
F_7 ( V_4 -> V_7 . V_8 ) ;
}
static inline void F_23 ( struct V_3 * V_4 ) { }
static struct V_3 * F_24 ( int V_11 , int V_6 , struct V_12 * V_13 )
{
struct V_3 * V_4 ;
T_2 V_5 = V_30 ;
V_4 = F_25 ( sizeof( * V_4 ) , V_5 , V_6 ) ;
if ( ! V_4 )
return NULL ;
V_4 -> V_28 = F_26 (unsigned int) ;
if ( ! V_4 -> V_28 )
goto V_31;
if ( F_4 ( V_4 , V_5 , V_6 ) )
goto V_32;
F_27 ( & V_4 -> V_33 ) ;
F_28 ( & V_4 -> V_33 , & V_34 ) ;
F_12 ( V_11 , V_4 , V_6 , V_13 ) ;
return V_4 ;
V_32:
F_29 ( V_4 -> V_28 ) ;
V_31:
F_30 ( V_4 ) ;
return NULL ;
}
static void F_31 ( unsigned int V_11 )
{
struct V_3 * V_4 = F_19 ( V_11 ) ;
F_32 ( V_11 , V_4 ) ;
F_33 ( & V_35 ) ;
F_21 ( V_11 ) ;
F_34 ( & V_35 ) ;
F_23 ( V_4 ) ;
F_29 ( V_4 -> V_28 ) ;
F_30 ( V_4 ) ;
}
static int F_35 ( unsigned int V_36 , unsigned int V_37 , int V_6 ,
struct V_12 * V_13 )
{
struct V_3 * V_4 ;
int V_38 ;
for ( V_38 = 0 ; V_38 < V_37 ; V_38 ++ ) {
V_4 = F_24 ( V_36 + V_38 , V_6 , V_13 ) ;
if ( ! V_4 )
goto V_39;
F_33 ( & V_35 ) ;
F_17 ( V_36 + V_38 , V_4 ) ;
F_34 ( & V_35 ) ;
}
return V_36 ;
V_39:
for ( V_38 -- ; V_38 >= 0 ; V_38 -- )
F_31 ( V_36 + V_38 ) ;
F_33 ( & V_35 ) ;
F_36 ( V_40 , V_36 , V_37 ) ;
F_34 ( & V_35 ) ;
return - V_9 ;
}
static int F_37 ( unsigned int V_41 )
{
if ( V_41 > V_42 )
return - V_9 ;
V_43 = V_41 ;
return 0 ;
}
int T_1 F_38 ( void )
{
int V_38 , V_44 , V_6 = V_45 ;
struct V_3 * V_4 ;
F_1 () ;
V_44 = F_39 () ;
F_40 ( V_46 L_1 , V_47 , V_43 , V_44 ) ;
if ( F_41 ( V_43 > V_42 ) )
V_43 = V_42 ;
if ( F_41 ( V_44 > V_42 ) )
V_44 = V_42 ;
if ( V_44 > V_43 )
V_43 = V_44 ;
for ( V_38 = 0 ; V_38 < V_44 ; V_38 ++ ) {
V_4 = F_24 ( V_38 , V_6 , NULL ) ;
F_42 ( V_38 , V_40 ) ;
F_17 ( V_38 , V_4 ) ;
}
return F_43 () ;
}
int T_1 F_38 ( void )
{
int V_48 , V_38 , V_6 = V_45 ;
struct V_3 * V_4 ;
F_1 () ;
F_40 ( V_46 L_2 , V_47 ) ;
V_4 = V_3 ;
V_48 = F_44 ( V_3 ) ;
for ( V_38 = 0 ; V_38 < V_48 ; V_38 ++ ) {
V_4 [ V_38 ] . V_28 = F_26 (unsigned int) ;
F_4 ( & V_4 [ V_38 ] , V_30 , V_6 ) ;
F_27 ( & V_4 [ V_38 ] . V_33 ) ;
F_28 ( & V_4 [ V_38 ] . V_33 , & V_34 ) ;
F_12 ( V_38 , & V_4 [ V_38 ] , V_6 , NULL ) ;
}
return F_43 () ;
}
struct V_3 * F_19 ( unsigned int V_11 )
{
return ( V_11 < V_47 ) ? V_3 + V_11 : NULL ;
}
static void F_31 ( unsigned int V_11 )
{
struct V_3 * V_4 = F_19 ( V_11 ) ;
unsigned long V_49 ;
F_45 ( & V_4 -> V_33 , V_49 ) ;
F_12 ( V_11 , V_4 , F_11 ( V_4 ) , NULL ) ;
F_46 ( & V_4 -> V_33 , V_49 ) ;
}
static inline int F_35 ( unsigned int V_36 , unsigned int V_37 , int V_6 ,
struct V_12 * V_13 )
{
T_3 V_38 ;
for ( V_38 = 0 ; V_38 < V_37 ; V_38 ++ ) {
struct V_3 * V_4 = F_19 ( V_36 + V_38 ) ;
V_4 -> V_13 = V_13 ;
}
return V_36 ;
}
static int F_37 ( unsigned int V_41 )
{
return - V_9 ;
}
void F_47 ( unsigned int V_11 )
{
F_33 ( & V_35 ) ;
F_48 ( V_40 , V_11 , 1 ) ;
F_34 ( & V_35 ) ;
}
void F_49 ( unsigned int V_11 )
{
F_31 ( V_11 ) ;
}
int F_50 ( unsigned int V_11 )
{
struct V_3 * V_4 = F_19 ( V_11 ) ;
if ( ! V_4 )
return - V_50 ;
F_51 ( V_11 , V_4 ) ;
return 0 ;
}
int F_52 ( struct V_51 * V_52 , unsigned int V_53 ,
bool V_54 , struct V_55 * V_56 )
{
struct V_55 * V_57 = F_53 ( V_56 ) ;
unsigned int V_11 = V_53 ;
int V_58 = 0 ;
F_54 () ;
#ifdef F_55
if ( V_54 )
V_11 = F_56 ( V_52 , V_53 ) ;
#endif
if ( F_57 ( ! V_11 || V_11 >= V_43 ) ) {
F_58 ( V_11 ) ;
V_58 = - V_50 ;
} else {
F_50 ( V_11 ) ;
}
F_59 () ;
F_53 ( V_57 ) ;
return V_58 ;
}
void F_60 ( unsigned int V_59 , unsigned int V_37 )
{
int V_38 ;
if ( V_59 >= V_43 || ( V_59 + V_37 ) > V_43 )
return;
for ( V_38 = 0 ; V_38 < V_37 ; V_38 ++ )
F_31 ( V_59 + V_38 ) ;
F_33 ( & V_35 ) ;
F_36 ( V_40 , V_59 , V_37 ) ;
F_34 ( & V_35 ) ;
}
int T_4
F_61 ( int V_11 , unsigned int V_59 , unsigned int V_37 , int V_6 ,
struct V_12 * V_13 )
{
int V_36 , V_58 ;
if ( ! V_37 )
return - V_50 ;
if ( V_11 >= 0 ) {
if ( V_59 > V_11 )
return - V_50 ;
V_59 = V_11 ;
} else {
V_59 = F_62 ( V_59 ) ;
}
F_33 ( & V_35 ) ;
V_36 = F_63 ( V_40 , V_42 ,
V_59 , V_37 , 0 ) ;
V_58 = - V_60 ;
if ( V_11 >= 0 && V_36 != V_11 )
goto V_39;
if ( V_36 + V_37 > V_43 ) {
V_58 = F_37 ( V_36 + V_37 ) ;
if ( V_58 )
goto V_39;
}
F_48 ( V_40 , V_36 , V_37 ) ;
F_34 ( & V_35 ) ;
return F_35 ( V_36 , V_37 , V_6 , V_13 ) ;
V_39:
F_34 ( & V_35 ) ;
return V_58 ;
}
unsigned int F_64 ( int V_37 , int V_6 )
{
int V_38 , V_11 = F_61 ( - 1 , 0 , V_37 , V_6 , NULL ) ;
if ( V_11 < 0 )
return 0 ;
for ( V_38 = V_11 ; V_37 > 0 ; V_38 ++ , V_37 -- ) {
if ( F_65 ( V_38 , V_6 ) )
goto V_39;
F_66 ( V_38 , V_61 ) ;
}
return V_11 ;
V_39:
for ( V_38 -- ; V_38 >= V_11 ; V_38 -- ) {
F_67 ( V_38 , V_61 | V_62 ) ;
F_68 ( V_38 ) ;
}
F_60 ( V_11 , V_37 ) ;
return 0 ;
}
void F_69 ( unsigned int V_59 , int V_37 )
{
int V_38 , V_63 ;
for ( V_38 = V_59 , V_63 = V_37 ; V_63 > 0 ; V_38 ++ , V_63 -- ) {
F_67 ( V_38 , V_61 | V_62 ) ;
F_68 ( V_38 ) ;
}
F_60 ( V_59 , V_37 ) ;
}
unsigned int F_70 ( unsigned int V_64 )
{
return F_71 ( V_40 , V_43 , V_64 ) ;
}
struct V_3 *
F_72 ( unsigned int V_11 , unsigned long * V_49 , bool V_65 ,
unsigned int V_66 )
{
struct V_3 * V_4 = F_19 ( V_11 ) ;
if ( V_4 ) {
if ( V_66 & V_67 ) {
if ( ( V_66 & V_68 ) &&
! F_73 ( V_4 ) )
return NULL ;
if ( ! ( V_66 & V_68 ) &&
F_73 ( V_4 ) )
return NULL ;
}
if ( V_65 )
F_74 ( V_4 ) ;
F_45 ( & V_4 -> V_33 , * V_49 ) ;
}
return V_4 ;
}
void F_75 ( struct V_3 * V_4 , unsigned long V_49 , bool V_65 )
{
F_46 ( & V_4 -> V_33 , V_49 ) ;
if ( V_65 )
F_76 ( V_4 ) ;
}
int F_77 ( unsigned int V_11 )
{
struct V_3 * V_4 = F_19 ( V_11 ) ;
if ( ! V_4 )
return - V_50 ;
if ( V_4 -> V_69 )
return - V_50 ;
V_4 -> V_69 = F_78 ( sizeof( * V_4 -> V_69 ) , V_30 ) ;
if ( ! V_4 -> V_69 )
return - V_9 ;
F_79 ( V_11 ) ;
return 0 ;
}
void F_80 ( unsigned int V_11 )
{
F_81 ( V_11 , F_19 ( V_11 ) ) ;
}
unsigned int F_82 ( unsigned int V_11 , int V_14 )
{
struct V_3 * V_4 = F_19 ( V_11 ) ;
return V_4 && V_4 -> V_28 ?
* F_16 ( V_4 -> V_28 , V_14 ) : 0 ;
}
unsigned int V_28 ( unsigned int V_11 )
{
struct V_3 * V_4 = F_19 ( V_11 ) ;
int V_14 ;
int V_70 = 0 ;
if ( ! V_4 || ! V_4 -> V_28 )
return 0 ;
F_15 (cpu)
V_70 += * F_16 ( V_4 -> V_28 , V_14 ) ;
return V_70 ;
}
