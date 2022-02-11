static bool F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_5 )
{
if ( F_2 () > 1 || ! F_3 () ) {
F_4 () ;
return false ;
}
F_5 () ;
F_6 () ;
F_7 () ;
return true ;
}
static bool F_8 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_5 )
{
F_5 () ;
F_9 () ;
F_10 ( 0 , V_6 ) ;
F_7 () ;
return true ;
}
static inline bool F_8 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_5 )
{
return true ;
}
static int F_11 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_5 )
{
bool V_7 = false ;
bool V_8 ;
F_12 () ;
V_8 = F_13 () ;
F_14 () ;
if ( V_2 -> V_9 == 0 ) {
if ( V_8 )
V_7 = F_1 ( V_2 , V_4 ,
V_5 ) ;
else
F_4 () ;
} else {
V_7 = F_8 ( V_2 , V_4 , V_5 ) ;
}
F_15 () ;
F_16 () ;
F_17 () ;
F_18 () ;
return ( V_7 ) ? V_5 : 0 ;
}
int T_1 F_19 ( void )
{
return F_20 ( & V_10 , NULL ) ;
}
