static inline void F_1 ( unsigned long * V_1 )
{
* V_1 = F_2 ( V_2 ) ;
F_3 () -> V_3 = 1 ;
}
static inline void F_4 ( unsigned long V_1 )
{
T_1 V_4 ;
V_4 = F_5 ( F_3 () -> V_5 ) ;
V_4 += F_2 ( V_2 ) - V_1 ;
F_3 () -> V_5 = F_6 ( V_4 ) ;
F_3 () -> V_3 = 0 ;
}
static int F_7 ( struct V_6 * V_7 ,
struct V_8 * V_9 ,
int V_10 )
{
unsigned long V_1 ;
F_1 ( & V_1 ) ;
F_8 () ;
F_9 ( V_11 ) ;
while ( ! F_10 () ) {
F_11 () ;
F_12 () ;
}
F_13 () ;
F_14 ( V_11 ) ;
F_15 () ;
F_4 ( V_1 ) ;
return V_10 ;
}
static void F_16 ( void )
{
if ( F_17 () ) {
F_18 () ;
#ifdef F_19
if ( F_20 ( ! ( F_21 () & V_12 ) ) )
F_22 () ;
#endif
}
}
static int F_23 ( struct V_6 * V_7 ,
struct V_8 * V_9 ,
int V_10 )
{
unsigned long V_1 ;
F_1 ( & V_1 ) ;
F_3 () -> V_13 = 1 ;
F_13 () ;
F_16 () ;
F_3 () -> V_13 = 0 ;
F_4 ( V_1 ) ;
return V_10 ;
}
static int F_24 ( struct V_6 * V_7 ,
struct V_8 * V_9 ,
int V_10 )
{
unsigned long V_1 ;
F_1 ( & V_1 ) ;
F_16 () ;
F_4 ( V_1 ) ;
return V_10 ;
}
static int F_25 ( struct V_14 * V_15 ,
unsigned long V_16 , void * V_17 )
{
int V_18 = ( unsigned long ) V_17 ;
struct V_6 * V_7 =
F_26 ( V_19 , V_18 ) ;
if ( V_7 && F_27 () ) {
switch ( V_16 ) {
case V_20 :
case V_21 :
F_28 () ;
F_29 ( V_7 ) ;
F_30 () ;
break;
case V_22 :
case V_23 :
F_28 () ;
F_31 ( V_7 ) ;
F_30 () ;
break;
default:
return V_24 ;
}
}
return V_25 ;
}
static int F_32 ( void )
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
static int F_33 ( void )
{
if ( V_33 != V_34 )
return - V_35 ;
if ( F_34 ( V_36 ) ) {
if ( F_35 ( F_3 () ) ) {
V_30 = V_37 ;
V_29 = F_36 ( V_37 ) ;
} else {
V_30 = V_38 ;
V_29 = F_36 ( V_38 ) ;
}
} else
return - V_35 ;
return 0 ;
}
static int T_2 F_37 ( void )
{
int V_39 ;
V_39 = F_33 () ;
if ( V_39 )
return V_39 ;
F_32 () ;
V_39 = F_38 ( & V_27 , NULL ) ;
if ( V_39 ) {
F_39 ( V_40 L_1 ) ;
return V_39 ;
}
F_40 ( & V_41 ) ;
F_39 ( V_40 L_2 ) ;
return 0 ;
}
