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
static int F_29 ( struct V_17 * V_18 ,
unsigned long V_19 , void * V_20 )
{
int V_21 = ( unsigned long ) V_20 ;
struct V_6 * V_7 =
F_30 ( V_22 , V_21 ) ;
if ( V_7 && F_31 () ) {
switch ( V_19 ) {
case V_23 :
case V_24 :
F_32 () ;
F_33 ( V_7 ) ;
F_34 () ;
break;
case V_25 :
case V_26 :
F_32 () ;
F_35 ( V_7 ) ;
F_34 () ;
break;
default:
return V_27 ;
}
}
return V_28 ;
}
static int F_36 ( void )
{
int V_29 ;
struct V_8 * V_9 = & V_30 ;
V_9 -> V_31 = 0 ;
for ( V_29 = 0 ; V_29 < V_32 ; ++ V_29 ) {
if ( V_33 [ V_29 ] . V_34 == NULL )
continue;
V_9 -> V_35 [ V_9 -> V_31 ] =
V_33 [ V_29 ] ;
V_9 -> V_31 += 1 ;
}
return 0 ;
}
static int F_37 ( void )
{
if ( V_36 != V_37 )
return - V_38 ;
if ( F_38 ( V_39 ) ) {
if ( F_39 ( F_4 () ) ) {
V_33 = V_40 ;
V_32 = F_40 ( V_40 ) ;
} else {
V_33 = V_41 ;
V_32 = F_40 ( V_41 ) ;
}
} else
return - V_38 ;
if ( V_32 > 1 ) {
V_14 = true ;
V_13 = V_33 [ 1 ] . V_42 *
V_43 ;
}
return 0 ;
}
static int T_2 F_41 ( void )
{
int V_44 ;
V_44 = F_37 () ;
if ( V_44 )
return V_44 ;
F_36 () ;
V_44 = F_42 ( & V_30 , NULL ) ;
if ( V_44 ) {
F_43 ( V_45 L_1 ) ;
return V_44 ;
}
F_44 ( & V_46 ) ;
F_43 ( V_45 L_2 ) ;
return 0 ;
}
