static inline void F_1 ( unsigned long * V_1 )
{
F_2 () ;
* V_1 = F_3 ( V_2 ) ;
F_4 () -> V_3 = 1 ;
}
static inline void F_5 ( unsigned long V_1 )
{
T_1 V_4 ;
V_4 = F_6 ( F_4 () -> V_5 ) ;
V_4 += F_3 ( V_2 ) - V_1 ;
F_4 () -> V_5 = F_7 ( V_4 ) ;
F_4 () -> V_3 = 0 ;
if ( F_8 () )
F_9 () ;
F_10 () ;
}
static int F_11 ( struct V_6 * V_7 ,
struct V_8 * V_9 ,
int V_10 )
{
unsigned long V_1 ;
T_1 V_11 ;
F_12 ( V_12 ) ;
F_1 ( & V_1 ) ;
F_9 () ;
V_11 = F_13 () + V_13 ;
while ( ! F_14 () ) {
F_15 () ;
F_16 () ;
if ( F_17 ( V_14 ) && F_13 () > V_11 ) {
F_18 ( V_12 ) ;
F_19 () ;
break;
}
}
F_20 () ;
F_18 ( V_12 ) ;
F_5 ( V_1 ) ;
return V_10 ;
}
static void F_21 ( void )
{
if ( F_22 () ) {
F_23 () ;
#ifdef F_24
if ( F_25 ( ! ( F_26 () & V_15 ) ) )
F_27 () ;
#endif
}
}
static int F_28 ( struct V_6 * V_7 ,
struct V_8 * V_9 ,
int V_10 )
{
unsigned long V_1 ;
F_1 ( & V_1 ) ;
F_4 () -> V_16 = 1 ;
F_20 () ;
F_21 () ;
F_4 () -> V_16 = 0 ;
F_5 ( V_1 ) ;
return V_10 ;
}
static int F_29 ( struct V_6 * V_7 ,
struct V_8 * V_9 ,
int V_10 )
{
unsigned long V_1 ;
F_1 ( & V_1 ) ;
F_21 () ;
F_5 ( V_1 ) ;
return V_10 ;
}
static int F_30 ( unsigned int V_17 )
{
struct V_6 * V_7 = F_31 ( V_18 , V_17 ) ;
if ( V_7 && F_32 () ) {
F_33 () ;
F_34 ( V_7 ) ;
F_35 () ;
}
return 0 ;
}
static int F_36 ( unsigned int V_17 )
{
struct V_6 * V_7 = F_31 ( V_18 , V_17 ) ;
if ( V_7 && F_32 () ) {
F_33 () ;
F_37 ( V_7 ) ;
F_35 () ;
}
return 0 ;
}
static int F_38 ( void )
{
int V_19 ;
struct V_8 * V_9 = & V_20 ;
V_9 -> V_21 = 0 ;
for ( V_19 = 0 ; V_19 < V_22 ; ++ V_19 ) {
if ( V_23 [ V_19 ] . V_24 == NULL )
continue;
V_9 -> V_25 [ V_9 -> V_21 ] =
V_23 [ V_19 ] ;
V_9 -> V_21 += 1 ;
}
return 0 ;
}
static int F_39 ( void )
{
if ( V_26 != V_27 )
return - V_28 ;
if ( F_40 ( V_29 ) ) {
if ( F_41 ( F_4 () ) ) {
V_23 = V_30 ;
V_22 = F_42 ( V_30 ) ;
} else {
V_23 = V_31 ;
V_22 = F_42 ( V_31 ) ;
}
} else
return - V_28 ;
if ( V_22 > 1 ) {
V_14 = true ;
V_13 = V_23 [ 1 ] . V_32 *
V_33 ;
}
return 0 ;
}
static int T_2 F_43 ( void )
{
int V_34 ;
V_34 = F_39 () ;
if ( V_34 )
return V_34 ;
F_38 () ;
V_34 = F_44 ( & V_20 , NULL ) ;
if ( V_34 ) {
F_45 ( V_35 L_1 ) ;
return V_34 ;
}
V_34 = F_46 ( V_36 ,
L_2 ,
F_30 , NULL ) ;
F_25 ( V_34 < 0 ) ;
V_34 = F_46 ( V_37 ,
L_3 , NULL ,
F_36 ) ;
F_25 ( V_34 < 0 ) ;
F_45 ( V_35 L_4 ) ;
return 0 ;
}
