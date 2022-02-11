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
static inline int
F_4 ( struct V_3 * V_4 , T_2 V_5 , int V_6 ) { return 0 ; }
static inline void F_8 ( struct V_3 * V_4 , int V_6 ) { }
static void F_11 ( unsigned int V_11 , struct V_3 * V_4 , int V_6 ,
struct V_12 * V_13 )
{
int V_14 ;
V_4 -> V_7 . V_15 = & V_4 -> V_16 ;
V_4 -> V_7 . V_11 = V_11 ;
V_4 -> V_7 . V_17 = & V_18 ;
V_4 -> V_7 . V_19 = NULL ;
V_4 -> V_7 . V_20 = NULL ;
V_4 -> V_7 . V_21 = NULL ;
F_12 ( V_4 , ~ 0 , V_22 ) ;
F_13 ( & V_4 -> V_7 , V_23 ) ;
V_4 -> V_24 = V_25 ;
V_4 -> V_26 = 1 ;
V_4 -> V_27 = 0 ;
V_4 -> V_28 = 0 ;
V_4 -> V_29 = NULL ;
V_4 -> V_13 = V_13 ;
F_14 ( V_14 )
* F_15 ( V_4 -> V_30 , V_14 ) = 0 ;
F_8 ( V_4 , V_6 ) ;
}
static void F_16 ( unsigned int V_11 , struct V_3 * V_4 )
{
F_17 ( & V_31 , V_11 , V_4 ) ;
}
struct V_3 * F_18 ( unsigned int V_11 )
{
return F_19 ( & V_31 , V_11 ) ;
}
static void F_20 ( unsigned int V_11 )
{
F_21 ( & V_31 , V_11 ) ;
}
static void F_22 ( struct V_3 * V_4 )
{
#ifdef F_6
F_7 ( V_4 -> V_10 ) ;
#endif
F_7 ( V_4 -> V_7 . V_8 ) ;
}
static inline void F_22 ( struct V_3 * V_4 ) { }
void F_23 ( void )
{
F_24 ( & V_32 ) ;
}
void F_25 ( void )
{
F_26 ( & V_32 ) ;
}
static struct V_3 * F_27 ( int V_11 , int V_6 , struct V_12 * V_13 )
{
struct V_3 * V_4 ;
T_2 V_5 = V_33 ;
V_4 = F_28 ( sizeof( * V_4 ) , V_5 , V_6 ) ;
if ( ! V_4 )
return NULL ;
V_4 -> V_30 = F_29 (unsigned int) ;
if ( ! V_4 -> V_30 )
goto V_34;
if ( F_4 ( V_4 , V_5 , V_6 ) )
goto V_35;
F_30 ( & V_4 -> V_36 ) ;
F_31 ( & V_4 -> V_36 , & V_37 ) ;
F_11 ( V_11 , V_4 , V_6 , V_13 ) ;
return V_4 ;
V_35:
F_32 ( V_4 -> V_30 ) ;
V_34:
F_33 ( V_4 ) ;
return NULL ;
}
static void F_34 ( unsigned int V_11 )
{
struct V_3 * V_4 = F_18 ( V_11 ) ;
F_35 ( V_11 , V_4 ) ;
F_24 ( & V_32 ) ;
F_20 ( V_11 ) ;
F_26 ( & V_32 ) ;
F_22 ( V_4 ) ;
F_32 ( V_4 -> V_30 ) ;
F_33 ( V_4 ) ;
}
static int F_36 ( unsigned int V_38 , unsigned int V_39 , int V_6 ,
struct V_12 * V_13 )
{
struct V_3 * V_4 ;
int V_40 ;
for ( V_40 = 0 ; V_40 < V_39 ; V_40 ++ ) {
V_4 = F_27 ( V_38 + V_40 , V_6 , V_13 ) ;
if ( ! V_4 )
goto V_41;
F_24 ( & V_32 ) ;
F_16 ( V_38 + V_40 , V_4 ) ;
F_26 ( & V_32 ) ;
}
return V_38 ;
V_41:
for ( V_40 -- ; V_40 >= 0 ; V_40 -- )
F_34 ( V_38 + V_40 ) ;
F_24 ( & V_32 ) ;
F_37 ( V_42 , V_38 , V_39 ) ;
F_26 ( & V_32 ) ;
return - V_9 ;
}
static int F_38 ( unsigned int V_43 )
{
if ( V_43 > V_44 )
return - V_9 ;
V_45 = V_43 ;
return 0 ;
}
int T_1 F_39 ( void )
{
int V_40 , V_46 , V_6 = V_47 ;
struct V_3 * V_4 ;
F_1 () ;
V_46 = F_40 () ;
F_41 ( V_48 L_1 , V_49 , V_45 , V_46 ) ;
if ( F_42 ( V_45 > V_44 ) )
V_45 = V_44 ;
if ( F_42 ( V_46 > V_44 ) )
V_46 = V_44 ;
if ( V_46 > V_45 )
V_45 = V_46 ;
for ( V_40 = 0 ; V_40 < V_46 ; V_40 ++ ) {
V_4 = F_27 ( V_40 , V_6 , NULL ) ;
F_43 ( V_40 , V_42 ) ;
F_16 ( V_40 , V_4 ) ;
}
return F_44 () ;
}
int T_1 F_39 ( void )
{
int V_50 , V_40 , V_6 = V_47 ;
struct V_3 * V_4 ;
F_1 () ;
F_41 ( V_48 L_2 , V_49 ) ;
V_4 = V_3 ;
V_50 = F_45 ( V_3 ) ;
for ( V_40 = 0 ; V_40 < V_50 ; V_40 ++ ) {
V_4 [ V_40 ] . V_30 = F_29 (unsigned int) ;
F_4 ( & V_4 [ V_40 ] , V_33 , V_6 ) ;
F_30 ( & V_4 [ V_40 ] . V_36 ) ;
F_31 ( & V_4 [ V_40 ] . V_36 , & V_37 ) ;
F_11 ( V_40 , & V_4 [ V_40 ] , V_6 , NULL ) ;
}
return F_44 () ;
}
struct V_3 * F_18 ( unsigned int V_11 )
{
return ( V_11 < V_49 ) ? V_3 + V_11 : NULL ;
}
static void F_34 ( unsigned int V_11 )
{
struct V_3 * V_4 = F_18 ( V_11 ) ;
unsigned long V_51 ;
F_46 ( & V_4 -> V_36 , V_51 ) ;
F_11 ( V_11 , V_4 , F_47 ( V_4 ) , NULL ) ;
F_48 ( & V_4 -> V_36 , V_51 ) ;
}
static inline int F_36 ( unsigned int V_38 , unsigned int V_39 , int V_6 ,
struct V_12 * V_13 )
{
T_3 V_40 ;
for ( V_40 = 0 ; V_40 < V_39 ; V_40 ++ ) {
struct V_3 * V_4 = F_18 ( V_38 + V_40 ) ;
V_4 -> V_13 = V_13 ;
}
return V_38 ;
}
static int F_38 ( unsigned int V_43 )
{
return - V_9 ;
}
void F_49 ( unsigned int V_11 )
{
F_24 ( & V_32 ) ;
F_50 ( V_42 , V_11 , 1 ) ;
F_26 ( & V_32 ) ;
}
void F_51 ( unsigned int V_11 )
{
F_34 ( V_11 ) ;
}
int F_52 ( unsigned int V_11 )
{
struct V_3 * V_4 = F_18 ( V_11 ) ;
if ( ! V_4 )
return - V_52 ;
F_53 ( V_11 , V_4 ) ;
return 0 ;
}
int F_54 ( struct V_53 * V_54 , unsigned int V_55 ,
bool V_56 , struct V_57 * V_58 )
{
struct V_57 * V_59 = F_55 ( V_58 ) ;
unsigned int V_11 = V_55 ;
int V_60 = 0 ;
F_56 () ;
#ifdef F_57
if ( V_56 )
V_11 = F_58 ( V_54 , V_55 ) ;
#endif
if ( F_59 ( ! V_11 || V_11 >= V_45 ) ) {
F_60 ( V_11 ) ;
V_60 = - V_52 ;
} else {
F_52 ( V_11 ) ;
}
F_61 () ;
F_55 ( V_59 ) ;
return V_60 ;
}
void F_62 ( unsigned int V_61 , unsigned int V_39 )
{
int V_40 ;
if ( V_61 >= V_45 || ( V_61 + V_39 ) > V_45 )
return;
for ( V_40 = 0 ; V_40 < V_39 ; V_40 ++ )
F_34 ( V_61 + V_40 ) ;
F_24 ( & V_32 ) ;
F_37 ( V_42 , V_61 , V_39 ) ;
F_26 ( & V_32 ) ;
}
int T_4
F_63 ( int V_11 , unsigned int V_61 , unsigned int V_39 , int V_6 ,
struct V_12 * V_13 )
{
int V_38 , V_60 ;
if ( ! V_39 )
return - V_52 ;
if ( V_11 >= 0 ) {
if ( V_61 > V_11 )
return - V_52 ;
V_61 = V_11 ;
} else {
V_61 = F_64 ( V_61 ) ;
}
F_24 ( & V_32 ) ;
V_38 = F_65 ( V_42 , V_44 ,
V_61 , V_39 , 0 ) ;
V_60 = - V_62 ;
if ( V_11 >= 0 && V_38 != V_11 )
goto V_41;
if ( V_38 + V_39 > V_45 ) {
V_60 = F_38 ( V_38 + V_39 ) ;
if ( V_60 )
goto V_41;
}
F_50 ( V_42 , V_38 , V_39 ) ;
F_26 ( & V_32 ) ;
return F_36 ( V_38 , V_39 , V_6 , V_13 ) ;
V_41:
F_26 ( & V_32 ) ;
return V_60 ;
}
unsigned int F_66 ( int V_39 , int V_6 )
{
int V_40 , V_11 = F_63 ( - 1 , 0 , V_39 , V_6 , NULL ) ;
if ( V_11 < 0 )
return 0 ;
for ( V_40 = V_11 ; V_39 > 0 ; V_40 ++ , V_39 -- ) {
if ( F_67 ( V_40 , V_6 ) )
goto V_41;
F_68 ( V_40 , V_63 ) ;
}
return V_11 ;
V_41:
for ( V_40 -- ; V_40 >= V_11 ; V_40 -- ) {
F_69 ( V_40 , V_63 | V_64 ) ;
F_70 ( V_40 ) ;
}
F_62 ( V_11 , V_39 ) ;
return 0 ;
}
void F_71 ( unsigned int V_61 , int V_39 )
{
int V_40 , V_65 ;
for ( V_40 = V_61 , V_65 = V_39 ; V_65 > 0 ; V_40 ++ , V_65 -- ) {
F_69 ( V_40 , V_63 | V_64 ) ;
F_70 ( V_40 ) ;
}
F_62 ( V_61 , V_39 ) ;
}
unsigned int F_72 ( unsigned int V_66 )
{
return F_73 ( V_42 , V_45 , V_66 ) ;
}
struct V_3 *
F_74 ( unsigned int V_11 , unsigned long * V_51 , bool V_67 ,
unsigned int V_68 )
{
struct V_3 * V_4 = F_18 ( V_11 ) ;
if ( V_4 ) {
if ( V_68 & V_69 ) {
if ( ( V_68 & V_70 ) &&
! F_75 ( V_4 ) )
return NULL ;
if ( ! ( V_68 & V_70 ) &&
F_75 ( V_4 ) )
return NULL ;
}
if ( V_67 )
F_76 ( V_4 ) ;
F_46 ( & V_4 -> V_36 , * V_51 ) ;
}
return V_4 ;
}
void F_77 ( struct V_3 * V_4 , unsigned long V_51 , bool V_67 )
{
F_48 ( & V_4 -> V_36 , V_51 ) ;
if ( V_67 )
F_78 ( V_4 ) ;
}
int F_79 ( unsigned int V_11 )
{
struct V_3 * V_4 = F_18 ( V_11 ) ;
if ( ! V_4 )
return - V_52 ;
if ( V_4 -> V_71 )
return - V_52 ;
V_4 -> V_71 = F_80 ( sizeof( * V_4 -> V_71 ) , V_33 ) ;
if ( ! V_4 -> V_71 )
return - V_9 ;
F_81 ( V_11 ) ;
return 0 ;
}
void F_82 ( unsigned int V_11 )
{
F_83 ( V_11 , F_18 ( V_11 ) ) ;
}
unsigned int F_84 ( unsigned int V_11 , int V_14 )
{
struct V_3 * V_4 = F_18 ( V_11 ) ;
return V_4 && V_4 -> V_30 ?
* F_15 ( V_4 -> V_30 , V_14 ) : 0 ;
}
unsigned int V_30 ( unsigned int V_11 )
{
struct V_3 * V_4 = F_18 ( V_11 ) ;
int V_14 ;
unsigned int V_72 = 0 ;
if ( ! V_4 || ! V_4 -> V_30 )
return 0 ;
F_14 (cpu)
V_72 += * F_15 ( V_4 -> V_30 , V_14 ) ;
return V_72 ;
}
unsigned int F_85 ( unsigned int V_11 )
{
unsigned int V_72 ;
F_23 () ;
V_72 = V_30 ( V_11 ) ;
F_25 () ;
return V_72 ;
}
