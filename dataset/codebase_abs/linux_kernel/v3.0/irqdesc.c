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
static void F_12 ( unsigned int V_11 , struct V_3 * V_4 , int V_6 )
{
int V_12 ;
V_4 -> V_7 . V_11 = V_11 ;
V_4 -> V_7 . V_13 = & V_14 ;
V_4 -> V_7 . V_15 = NULL ;
V_4 -> V_7 . V_16 = NULL ;
V_4 -> V_7 . V_17 = NULL ;
F_13 ( V_4 , ~ 0 , V_18 ) ;
F_14 ( & V_4 -> V_7 , V_19 ) ;
V_4 -> V_20 = V_21 ;
V_4 -> V_22 = 1 ;
V_4 -> V_23 = 0 ;
V_4 -> V_24 = 0 ;
V_4 -> V_25 = NULL ;
F_15 ( V_12 )
* F_16 ( V_4 -> V_26 , V_12 ) = 0 ;
F_8 ( V_4 , V_6 ) ;
}
static void F_17 ( unsigned int V_11 , struct V_3 * V_4 )
{
F_18 ( & V_27 , V_11 , V_4 ) ;
}
struct V_3 * F_19 ( unsigned int V_11 )
{
return F_20 ( & V_27 , V_11 ) ;
}
static void F_21 ( unsigned int V_11 )
{
F_22 ( & V_27 , V_11 ) ;
}
static void F_23 ( struct V_3 * V_4 )
{
#ifdef F_6
F_7 ( V_4 -> V_10 ) ;
#endif
F_7 ( V_4 -> V_7 . V_8 ) ;
}
static inline void F_23 ( struct V_3 * V_4 ) { }
static struct V_3 * F_24 ( int V_11 , int V_6 )
{
struct V_3 * V_4 ;
T_2 V_5 = V_28 ;
V_4 = F_25 ( sizeof( * V_4 ) , V_5 , V_6 ) ;
if ( ! V_4 )
return NULL ;
V_4 -> V_26 = F_26 (unsigned int) ;
if ( ! V_4 -> V_26 )
goto V_29;
if ( F_4 ( V_4 , V_5 , V_6 ) )
goto V_30;
F_27 ( & V_4 -> V_31 ) ;
F_28 ( & V_4 -> V_31 , & V_32 ) ;
F_12 ( V_11 , V_4 , V_6 ) ;
return V_4 ;
V_30:
F_29 ( V_4 -> V_26 ) ;
V_29:
F_30 ( V_4 ) ;
return NULL ;
}
static void F_31 ( unsigned int V_11 )
{
struct V_3 * V_4 = F_19 ( V_11 ) ;
F_32 ( V_11 , V_4 ) ;
F_33 ( & V_33 ) ;
F_21 ( V_11 ) ;
F_34 ( & V_33 ) ;
F_23 ( V_4 ) ;
F_29 ( V_4 -> V_26 ) ;
F_30 ( V_4 ) ;
}
static int F_35 ( unsigned int V_34 , unsigned int V_35 , int V_6 )
{
struct V_3 * V_4 ;
int V_36 ;
for ( V_36 = 0 ; V_36 < V_35 ; V_36 ++ ) {
V_4 = F_24 ( V_34 + V_36 , V_6 ) ;
if ( ! V_4 )
goto V_37;
F_33 ( & V_33 ) ;
F_17 ( V_34 + V_36 , V_4 ) ;
F_34 ( & V_33 ) ;
}
return V_34 ;
V_37:
for ( V_36 -- ; V_36 >= 0 ; V_36 -- )
F_31 ( V_34 + V_36 ) ;
F_33 ( & V_33 ) ;
F_36 ( V_38 , V_34 , V_35 ) ;
F_34 ( & V_33 ) ;
return - V_9 ;
}
static int F_37 ( unsigned int V_39 )
{
if ( V_39 > V_40 )
return - V_9 ;
V_41 = V_39 ;
return 0 ;
}
int T_1 F_38 ( void )
{
int V_36 , V_42 , V_6 = V_43 ;
struct V_3 * V_4 ;
F_1 () ;
V_42 = F_39 () ;
F_40 ( V_44 L_1 , V_45 , V_41 , V_42 ) ;
if ( F_41 ( V_41 > V_40 ) )
V_41 = V_40 ;
if ( F_41 ( V_42 > V_40 ) )
V_42 = V_40 ;
if ( V_42 > V_41 )
V_41 = V_42 ;
for ( V_36 = 0 ; V_36 < V_42 ; V_36 ++ ) {
V_4 = F_24 ( V_36 , V_6 ) ;
F_42 ( V_36 , V_38 ) ;
F_17 ( V_36 , V_4 ) ;
}
return F_43 () ;
}
int T_1 F_38 ( void )
{
int V_46 , V_36 , V_6 = V_43 ;
struct V_3 * V_4 ;
F_1 () ;
F_40 ( V_44 L_2 , V_45 ) ;
V_4 = V_3 ;
V_46 = F_44 ( V_3 ) ;
for ( V_36 = 0 ; V_36 < V_46 ; V_36 ++ ) {
V_4 [ V_36 ] . V_26 = F_26 (unsigned int) ;
F_4 ( & V_4 [ V_36 ] , V_28 , V_6 ) ;
F_27 ( & V_4 [ V_36 ] . V_31 ) ;
F_28 ( & V_4 [ V_36 ] . V_31 , & V_32 ) ;
F_12 ( V_36 , & V_4 [ V_36 ] , V_6 ) ;
}
return F_43 () ;
}
struct V_3 * F_19 ( unsigned int V_11 )
{
return ( V_11 < V_45 ) ? V_3 + V_11 : NULL ;
}
static void F_31 ( unsigned int V_11 )
{
F_45 ( V_11 ) ;
}
static inline int F_35 ( unsigned int V_34 , unsigned int V_35 , int V_6 )
{
return V_34 ;
}
static int F_37 ( unsigned int V_39 )
{
return - V_9 ;
}
int F_46 ( unsigned int V_11 )
{
struct V_3 * V_4 = F_19 ( V_11 ) ;
if ( ! V_4 )
return - V_47 ;
F_47 ( V_11 , V_4 ) ;
return 0 ;
}
void F_48 ( unsigned int V_48 , unsigned int V_35 )
{
int V_36 ;
if ( V_48 >= V_41 || ( V_48 + V_35 ) > V_41 )
return;
for ( V_36 = 0 ; V_36 < V_35 ; V_36 ++ )
F_31 ( V_48 + V_36 ) ;
F_33 ( & V_33 ) ;
F_36 ( V_38 , V_48 , V_35 ) ;
F_34 ( & V_33 ) ;
}
int T_3
F_49 ( int V_11 , unsigned int V_48 , unsigned int V_35 , int V_6 )
{
int V_34 , V_49 ;
if ( ! V_35 )
return - V_47 ;
if ( V_11 >= 0 ) {
if ( V_48 > V_11 )
return - V_47 ;
V_48 = V_11 ;
}
F_33 ( & V_33 ) ;
V_34 = F_50 ( V_38 , V_40 ,
V_48 , V_35 , 0 ) ;
V_49 = - V_50 ;
if ( V_11 >= 0 && V_34 != V_11 )
goto V_37;
if ( V_34 + V_35 > V_41 ) {
V_49 = F_37 ( V_34 + V_35 ) ;
if ( V_49 )
goto V_37;
}
F_51 ( V_38 , V_34 , V_35 ) ;
F_34 ( & V_33 ) ;
return F_35 ( V_34 , V_35 , V_6 ) ;
V_37:
F_34 ( & V_33 ) ;
return V_49 ;
}
int F_52 ( unsigned int V_48 , unsigned int V_35 )
{
unsigned int V_34 ;
int V_49 = 0 ;
if ( ! V_35 || ( V_48 + V_35 ) > V_41 )
return - V_47 ;
F_33 ( & V_33 ) ;
V_34 = F_50 ( V_38 , V_41 , V_48 , V_35 , 0 ) ;
if ( V_34 == V_48 )
F_51 ( V_38 , V_34 , V_35 ) ;
else
V_49 = - V_50 ;
F_34 ( & V_33 ) ;
return V_49 ;
}
unsigned int F_53 ( unsigned int V_51 )
{
return F_54 ( V_38 , V_41 , V_51 ) ;
}
struct V_3 *
F_55 ( unsigned int V_11 , unsigned long * V_52 , bool V_53 )
{
struct V_3 * V_4 = F_19 ( V_11 ) ;
if ( V_4 ) {
if ( V_53 )
F_56 ( V_4 ) ;
F_57 ( & V_4 -> V_31 , * V_52 ) ;
}
return V_4 ;
}
void F_58 ( struct V_3 * V_4 , unsigned long V_52 , bool V_53 )
{
F_59 ( & V_4 -> V_31 , V_52 ) ;
if ( V_53 )
F_60 ( V_4 ) ;
}
void F_45 ( unsigned int V_11 )
{
struct V_3 * V_4 = F_19 ( V_11 ) ;
unsigned long V_52 ;
F_57 ( & V_4 -> V_31 , V_52 ) ;
F_12 ( V_11 , V_4 , F_11 ( V_4 ) ) ;
F_59 ( & V_4 -> V_31 , V_52 ) ;
}
unsigned int F_61 ( unsigned int V_11 , int V_12 )
{
struct V_3 * V_4 = F_19 ( V_11 ) ;
return V_4 && V_4 -> V_26 ?
* F_16 ( V_4 -> V_26 , V_12 ) : 0 ;
}
unsigned int V_26 ( unsigned int V_11 )
{
struct V_3 * V_4 = F_19 ( V_11 ) ;
int V_12 ;
int V_54 = 0 ;
if ( ! V_4 || ! V_4 -> V_26 )
return 0 ;
F_15 (cpu)
V_54 += * F_16 ( V_4 -> V_26 , V_12 ) ;
return V_54 ;
}
