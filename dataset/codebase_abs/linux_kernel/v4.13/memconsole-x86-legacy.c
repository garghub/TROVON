static T_1 F_1 ( char * V_1 , T_2 V_2 , T_3 V_3 )
{
return F_2 ( V_1 , V_3 , & V_2 , V_4 ,
V_5 ) ;
}
static void F_3 ( struct V_6 * V_7 )
{
F_4 ( L_1 ,
V_7 ) ;
F_4 ( L_2 ,
V_7 -> V_8 . V_9 , V_7 -> V_8 . V_10 ,
V_7 -> V_8 . V_11 , V_7 -> V_8 . V_12 ) ;
V_4 = F_5 ( V_7 -> V_8 . V_9 ) ;
V_5 = V_7 -> V_8 . V_12 ;
F_6 ( F_1 ) ;
}
static void F_7 ( struct V_6 * V_7 )
{
F_4 ( L_3 ,
V_7 ) ;
F_4 ( L_4 ,
V_7 -> V_13 . V_9 , V_7 -> V_13 . V_10 ,
V_7 -> V_13 . V_11 , V_7 -> V_13 . V_14 ) ;
V_4 = F_5 ( V_7 -> V_13 . V_9 + V_7 -> V_13 . V_10 ) ;
V_5 = V_7 -> V_13 . V_11 - V_7 -> V_13 . V_10 ;
F_6 ( F_1 ) ;
}
static bool F_8 ( void )
{
unsigned int V_15 ;
T_3 V_16 , V_17 ;
V_15 = F_9 () ;
if ( ! V_15 ) {
F_4 ( L_5 ) ;
return false ;
}
V_16 = * ( V_18 * ) F_5 ( V_15 ) ;
V_16 <<= 10 ;
for ( V_17 = 0 ; V_17 < V_16 ; V_17 ++ ) {
struct V_6 * V_7 = F_5 ( V_15 + V_17 ) ;
if ( V_7 -> V_19 == V_20 ) {
F_3 ( V_7 ) ;
return true ;
}
if ( V_7 -> V_19 == V_21 ) {
F_7 ( V_7 ) ;
return true ;
}
}
F_4 ( L_6 ) ;
return false ;
}
static bool T_4 F_10 ( void )
{
if ( ! F_11 ( V_22 ) )
return false ;
return F_8 () ;
}
static int T_4 F_12 ( void )
{
if ( ! F_10 () )
return - V_23 ;
return F_13 () ;
}
static void T_5 F_14 ( void )
{
F_15 () ;
}
