static bool F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_5 )
{
struct V_6 * V_7 = & V_4 -> V_8 [ V_5 ] ;
T_1 V_9 = V_7 -> V_10 ;
T_1 V_11 = V_7 -> V_12 - V_7 -> V_10 ;
if ( F_2 () > 1 || ! F_3 () ) {
F_4 () ;
return false ;
}
F_5 ( V_13 , & V_2 -> V_14 ) ;
F_6 ( V_9 , V_11 ) ;
F_5 ( V_15 , & V_2 -> V_14 ) ;
return true ;
}
static bool F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_5 )
{
F_5 ( V_13 , & V_2 -> V_14 ) ;
F_8 () ;
F_9 () ;
F_10 ( 0 , V_16 ) ;
F_11 () ;
F_5 ( V_15 , & V_2 -> V_14 ) ;
return true ;
}
static inline bool F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_5 )
{
return true ;
}
static int T_2 F_12 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_5 )
{
T_1 V_14 = F_13 () ? F_14 ( V_2 -> V_14 ) : V_2 -> V_14 ;
bool V_17 = false ;
bool V_18 ;
F_15 () ;
V_18 = F_16 ( V_14 ) ;
F_17 () ;
if ( V_14 == 0 ) {
if ( V_18 )
V_17 = F_1 ( V_2 , V_4 ,
V_5 ) ;
else
F_4 () ;
} else {
V_17 = F_7 ( V_2 , V_4 , V_5 ) ;
}
F_18 () ;
F_19 ( V_14 ) ;
F_20 () ;
F_21 () ;
return ( V_17 ) ? V_5 : 0 ;
}
int T_3 F_22 ( void )
{
int V_19 ;
unsigned int V_14 ;
struct V_1 * V_2 ;
struct V_3 * V_4 = & V_20 ;
#ifdef F_23
V_21 = V_22 ;
#endif
V_19 = F_24 ( & V_20 ) ;
if ( V_19 ) {
F_25 ( L_1 ) ;
return V_19 ;
}
F_26 (cpu) {
V_2 = & F_27 ( V_23 , V_14 ) ;
V_2 -> V_14 = V_14 ;
V_2 -> V_24 = V_4 -> V_24 ;
V_19 = F_28 ( V_2 ) ;
if ( V_19 ) {
F_25 ( L_2 ,
V_14 ) ;
return V_19 ;
}
}
return 0 ;
}
