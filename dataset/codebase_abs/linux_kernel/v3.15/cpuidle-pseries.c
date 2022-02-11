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
F_1 ( & V_1 ) ;
F_9 () ;
F_12 ( V_11 ) ;
while ( ! F_13 () ) {
F_14 () ;
F_15 () ;
}
F_16 () ;
F_17 ( V_11 ) ;
F_18 () ;
F_5 ( V_1 ) ;
return V_10 ;
}
static void F_19 ( void )
{
if ( F_20 () ) {
F_21 () ;
#ifdef F_22
if ( F_23 ( ! ( F_24 () & V_12 ) ) )
F_25 () ;
#endif
}
}
static int F_26 ( struct V_6 * V_7 ,
struct V_8 * V_9 ,
int V_10 )
{
unsigned long V_1 ;
F_1 ( & V_1 ) ;
F_4 () -> V_13 = 1 ;
F_16 () ;
F_19 () ;
F_4 () -> V_13 = 0 ;
F_5 ( V_1 ) ;
return V_10 ;
}
static int F_27 ( struct V_6 * V_7 ,
struct V_8 * V_9 ,
int V_10 )
{
unsigned long V_1 ;
F_1 ( & V_1 ) ;
F_19 () ;
F_5 ( V_1 ) ;
return V_10 ;
}
static int F_28 ( struct V_14 * V_15 ,
unsigned long V_16 , void * V_17 )
{
int V_18 = ( unsigned long ) V_17 ;
struct V_6 * V_7 =
F_29 ( V_19 , V_18 ) ;
if ( V_7 && F_30 () ) {
switch ( V_16 ) {
case V_20 :
case V_21 :
F_31 () ;
F_32 ( V_7 ) ;
F_33 () ;
break;
case V_22 :
case V_23 :
F_31 () ;
F_34 ( V_7 ) ;
F_33 () ;
break;
default:
return V_24 ;
}
}
return V_25 ;
}
static int F_35 ( void )
{
int V_26 ;
struct V_8 * V_9 = & V_27 ;
V_9 -> V_28 = 0 ;
for ( V_26 = 0 ; V_26 < V_29 ; ++ V_26 ) {
if ( V_30 [ V_26 ] . V_31 == NULL )
continue;
V_9 -> V_32 [ V_9 -> V_28 ] =
V_30 [ V_26 ] ;
V_9 -> V_28 += 1 ;
}
return 0 ;
}
static int F_36 ( void )
{
if ( V_33 != V_34 )
return - V_35 ;
if ( F_37 ( V_36 ) ) {
if ( F_38 ( F_4 () ) ) {
V_30 = V_37 ;
V_29 = F_39 ( V_37 ) ;
} else {
V_30 = V_38 ;
V_29 = F_39 ( V_38 ) ;
}
} else
return - V_35 ;
return 0 ;
}
static int T_2 F_40 ( void )
{
int V_39 ;
V_39 = F_36 () ;
if ( V_39 )
return V_39 ;
F_35 () ;
V_39 = F_41 ( & V_27 , NULL ) ;
if ( V_39 ) {
F_42 ( V_40 L_1 ) ;
return V_39 ;
}
F_43 ( & V_41 ) ;
F_42 ( V_40 L_2 ) ;
return 0 ;
}
