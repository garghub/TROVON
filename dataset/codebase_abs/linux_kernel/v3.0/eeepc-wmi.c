static T_1 F_1 ( T_2 V_1 , T_3 V_2 ,
void * V_3 , void * * V_4 )
{
F_2 ( L_1 , V_5 ) ;
* ( bool * ) V_3 = true ;
return V_6 ;
}
static int F_3 ( void )
{
T_1 V_7 ;
bool V_8 = false ;
V_7 = F_4 ( V_5 , F_1 ,
& V_8 , NULL ) ;
if ( F_5 ( V_7 ) || ! V_8 )
return 0 ;
return - 1 ;
}
static int F_6 ( struct V_9 * V_10 )
{
if ( F_3 () ) {
F_2 ( L_2
L_3 ) ;
F_2 ( L_4
L_5 ) ;
F_2 ( L_6
L_7 ) ;
return - V_11 ;
}
return 0 ;
}
static void F_7 ( struct V_12 * V_13 )
{
const char * V_14 ;
V_14 = F_8 ( V_15 ) ;
if ( ! V_14 )
return;
if ( strcmp ( V_14 , L_8 ) == 0 ) {
V_13 -> V_16 = true ;
F_9 ( L_9 ) ;
}
}
static void F_10 ( struct V_12 * V_13 )
{
V_13 -> V_16 = V_16 ;
F_7 ( V_13 ) ;
}
static int T_4 F_11 ( void )
{
return F_12 ( & V_12 ) ;
}
static void T_5 F_13 ( void )
{
F_14 ( & V_12 ) ;
}
