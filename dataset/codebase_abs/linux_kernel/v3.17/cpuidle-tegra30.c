static bool F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_5 )
{
if ( F_2 () > 1 || ! F_3 () ) {
F_4 () ;
return false ;
}
F_5 ( V_6 , & V_2 -> V_7 ) ;
F_6 () ;
F_5 ( V_8 , & V_2 -> V_7 ) ;
return true ;
}
static bool F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_5 )
{
F_5 ( V_6 , & V_2 -> V_7 ) ;
F_8 () ;
F_9 ( 0 , V_9 ) ;
F_5 ( V_8 , & V_2 -> V_7 ) ;
return true ;
}
static inline bool F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_5 )
{
return true ;
}
static int F_10 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_5 )
{
bool V_10 = false ;
bool V_11 ;
F_11 () ;
V_11 = F_12 () ;
F_13 () ;
if ( V_2 -> V_7 == 0 ) {
if ( V_11 )
V_10 = F_1 ( V_2 , V_4 ,
V_5 ) ;
else
F_4 () ;
} else {
V_10 = F_7 ( V_2 , V_4 , V_5 ) ;
}
F_14 () ;
F_15 () ;
F_16 () ;
F_17 () ;
return ( V_10 ) ? V_5 : 0 ;
}
int T_1 F_18 ( void )
{
return F_19 ( & V_12 , NULL ) ;
}
