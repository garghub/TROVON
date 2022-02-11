static void F_1 ( struct V_1 * V_2 )
{
F_2 ( L_1 ,
V_2 ) ;
F_2 ( L_2 ,
V_2 -> V_3 . V_4 , V_2 -> V_3 . V_5 ,
V_2 -> V_3 . V_6 , V_2 -> V_3 . V_7 ) ;
F_3 ( F_4 ( V_2 -> V_3 . V_4 ) , V_2 -> V_3 . V_7 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
F_2 ( L_3 ,
V_2 ) ;
F_2 ( L_4 ,
V_2 -> V_8 . V_4 , V_2 -> V_8 . V_5 ,
V_2 -> V_8 . V_6 , V_2 -> V_8 . V_9 ) ;
F_3 ( F_4 ( V_2 -> V_8 . V_4 + V_2 -> V_8 . V_5 ) ,
V_2 -> V_8 . V_6 - V_2 -> V_8 . V_5 ) ;
}
static bool F_6 ( void )
{
unsigned int V_10 ;
T_1 V_11 , V_12 ;
V_10 = F_7 () ;
if ( ! V_10 ) {
F_2 ( L_5 ) ;
return false ;
}
V_11 = * ( V_13 * ) F_4 ( V_10 ) ;
V_11 <<= 10 ;
for ( V_12 = 0 ; V_12 < V_11 ; V_12 ++ ) {
struct V_1 * V_2 = F_4 ( V_10 + V_12 ) ;
if ( V_2 -> V_14 == V_15 ) {
F_1 ( V_2 ) ;
return true ;
}
if ( V_2 -> V_14 == V_16 ) {
F_5 ( V_2 ) ;
return true ;
}
}
F_2 ( L_6 ) ;
return false ;
}
static bool T_2 F_8 ( void )
{
if ( ! F_9 ( V_17 ) )
return false ;
return F_6 () ;
}
static int T_2 F_10 ( void )
{
if ( ! F_8 () )
return - V_18 ;
return F_11 () ;
}
static void T_3 F_12 ( void )
{
F_13 () ;
}
