static bool F_1 ( unsigned char V_1 , unsigned char V_2 ,
struct V_3 * V_4 )
{
static bool V_5 ;
bool V_6 = false ;
if ( V_2 & V_7 )
return false ;
if ( F_2 ( V_1 == 0xe1 ) ) {
V_5 = true ;
V_6 = true ;
} else if ( F_2 ( V_5 ) ) {
V_5 = false ;
V_6 = true ;
}
return V_6 ;
}
static int F_3 ( const struct V_8 * V_9 )
{
V_10 = V_9 -> V_11 ;
return 1 ;
}
static void F_4 ( struct V_12 * V_13 )
{
int V_6 ;
V_10 = & V_14 ;
F_5 ( V_15 ) ;
V_13 -> V_10 = V_10 ;
V_13 -> V_16 = V_17 ;
if ( V_18 != - 1 )
V_10 -> V_18 = V_18 ;
else
V_18 = V_10 -> V_18 ;
if ( V_10 -> V_19 ) {
V_6 = F_6 ( V_10 -> V_19 ) ;
if ( V_6 ) {
F_7 ( L_1 ) ;
return;
}
F_8 ( L_2 ) ;
}
}
static int T_1 F_9 ( void )
{
return F_10 ( & V_20 ) ;
}
static void T_2 F_11 ( void )
{
F_12 ( & V_20 ) ;
}
