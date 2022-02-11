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
F_1 ( & V_1 ) ;
F_9 () ;
F_12 ( V_12 ) ;
V_11 = F_13 () + V_13 ;
while ( ! F_14 () ) {
F_15 () ;
F_16 () ;
if ( V_14 && F_13 () > V_11 )
break;
}
F_17 () ;
F_18 ( V_12 ) ;
F_19 () ;
F_5 ( V_1 ) ;
return V_10 ;
}
static void F_20 ( void )
{
if ( F_21 () ) {
F_22 () ;
#ifdef F_23
if ( F_24 ( ! ( F_25 () & V_15 ) ) )
F_26 () ;
#endif
}
}
static int F_27 ( struct V_6 * V_7 ,
struct V_8 * V_9 ,
int V_10 )
{
unsigned long V_1 ;
F_1 ( & V_1 ) ;
F_4 () -> V_16 = 1 ;
F_17 () ;
F_20 () ;
F_4 () -> V_16 = 0 ;
F_5 ( V_1 ) ;
return V_10 ;
}
static int F_28 ( struct V_6 * V_7 ,
struct V_8 * V_9 ,
int V_10 )
{
unsigned long V_1 ;
F_1 ( & V_1 ) ;
F_20 () ;
F_5 ( V_1 ) ;
return V_10 ;
}
static int F_29 ( unsigned int V_17 )
{
struct V_6 * V_7 = F_30 ( V_18 , V_17 ) ;
if ( V_7 && F_31 () ) {
F_32 () ;
F_33 ( V_7 ) ;
F_34 () ;
}
return 0 ;
}
static int F_35 ( unsigned int V_17 )
{
struct V_6 * V_7 = F_30 ( V_18 , V_17 ) ;
if ( V_7 && F_31 () ) {
F_32 () ;
F_36 ( V_7 ) ;
F_34 () ;
}
return 0 ;
}
static int F_37 ( void )
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
static int F_38 ( void )
{
if ( V_26 != V_27 )
return - V_28 ;
if ( F_39 ( V_29 ) ) {
if ( F_40 ( F_4 () ) ) {
V_23 = V_30 ;
V_22 = F_41 ( V_30 ) ;
} else {
V_23 = V_31 ;
V_22 = F_41 ( V_31 ) ;
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
static int T_2 F_42 ( void )
{
int V_34 ;
V_34 = F_38 () ;
if ( V_34 )
return V_34 ;
F_37 () ;
V_34 = F_43 ( & V_20 , NULL ) ;
if ( V_34 ) {
F_44 ( V_35 L_1 ) ;
return V_34 ;
}
V_34 = F_45 ( V_36 ,
L_2 ,
F_29 , NULL ) ;
F_24 ( V_34 < 0 ) ;
V_34 = F_45 ( V_37 ,
L_3 , NULL ,
F_35 ) ;
F_24 ( V_34 < 0 ) ;
F_44 ( V_35 L_4 ) ;
return 0 ;
}
