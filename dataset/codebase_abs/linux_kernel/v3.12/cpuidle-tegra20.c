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
F_17 ( V_12 , & V_8 -> V_13 ) ;
F_18 () ;
F_17 ( V_14 , & V_8 -> V_13 ) ;
if ( F_12 ( 1 ) )
F_6 () ;
return true ;
}
static bool F_19 ( struct V_7 * V_8 ,
struct V_9 * V_10 ,
int V_11 )
{
F_17 ( V_12 , & V_8 -> V_13 ) ;
F_20 ( 0 , V_15 ) ;
F_7 () ;
F_17 ( V_14 , & V_8 -> V_13 ) ;
return true ;
}
static inline bool F_19 ( struct V_7 * V_8 ,
struct V_9 * V_10 ,
int V_11 )
{
return true ;
}
static int F_21 ( struct V_7 * V_8 ,
struct V_9 * V_10 ,
int V_11 )
{
bool V_16 = false ;
if ( F_22 () )
F_23 ( V_17 ) = true ;
F_24 ( V_8 , & V_18 ) ;
if ( V_17 ) {
F_24 ( V_8 , & V_18 ) ;
V_17 = false ;
return - V_19 ;
}
F_25 () ;
F_26 () ;
F_27 () ;
if ( V_8 -> V_13 == 0 )
V_16 = F_13 ( V_8 , V_10 , V_11 ) ;
else
V_16 = F_19 ( V_8 , V_10 , V_11 ) ;
F_28 () ;
F_29 () ;
F_30 () ;
F_31 () ;
return V_16 ? V_11 : 0 ;
}
void F_32 ( void )
{
F_33 (
L_1 ) ;
V_20 . V_21 [ 1 ] . V_22 = true ;
}
int T_1 F_34 ( void )
{
return F_35 ( & V_20 , V_23 ) ;
}
