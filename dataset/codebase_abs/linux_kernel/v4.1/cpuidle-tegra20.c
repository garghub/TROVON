static int F_1 ( void )
{
int V_1 = 0 ;
F_2 () ;
if ( F_3 ( V_2 + V_3 ) == V_4 )
F_4 ( 1 ) ;
else
V_1 = - V_5 ;
F_5 () ;
return V_1 ;
}
static void F_6 ( void )
{
F_2 () ;
F_7 () ;
F_8 ( 1 ) ;
F_9 ( 1 ) ;
F_10 ( 1 , 0 ) ;
F_5 () ;
}
static int F_11 ( void )
{
if ( ! F_12 ( 1 ) || ! F_1 () )
return 0 ;
F_6 () ;
return - V_6 ;
}
static inline void F_6 ( void )
{
}
static inline int F_11 ( void )
{
return 0 ;
}
static bool F_13 ( struct V_7 * V_8 ,
struct V_9 * V_10 ,
int V_11 )
{
while ( F_14 () )
F_15 () ;
if ( F_11 () || ! F_16 () )
return false ;
F_17 () ;
F_18 () ;
F_19 () ;
if ( F_12 ( 1 ) )
F_6 () ;
return true ;
}
static bool F_20 ( struct V_7 * V_8 ,
struct V_9 * V_10 ,
int V_11 )
{
F_17 () ;
F_21 ( 0 , V_12 ) ;
F_7 () ;
F_19 () ;
return true ;
}
static inline bool F_20 ( struct V_7 * V_8 ,
struct V_9 * V_10 ,
int V_11 )
{
return true ;
}
static int F_22 ( struct V_7 * V_8 ,
struct V_9 * V_10 ,
int V_11 )
{
bool V_13 = false ;
if ( F_23 () )
F_24 ( V_14 ) = true ;
F_25 ( V_8 , & V_15 ) ;
if ( V_14 ) {
F_25 ( V_8 , & V_15 ) ;
V_14 = false ;
return - V_16 ;
}
F_26 () ;
F_27 () ;
F_28 () ;
if ( V_8 -> V_17 == 0 )
V_13 = F_13 ( V_8 , V_10 , V_11 ) ;
else
V_13 = F_20 ( V_8 , V_10 , V_11 ) ;
F_29 () ;
F_30 () ;
F_31 () ;
F_32 () ;
return V_13 ? V_11 : 0 ;
}
void F_33 ( void )
{
F_34 (
L_1 ) ;
V_18 . V_19 [ 1 ] . V_20 = true ;
}
int T_1 F_35 ( void )
{
return F_36 ( & V_18 , V_21 ) ;
}
