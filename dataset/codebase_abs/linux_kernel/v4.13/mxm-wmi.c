int F_1 ( int V_1 )
{
struct V_2 args = {
. V_3 = V_4 ,
. args = 0 ,
. V_5 = 1 ,
} ;
struct V_6 V_7 = { ( V_8 ) sizeof( args ) , & args } ;
struct V_6 V_9 = { V_10 , NULL } ;
T_1 V_11 ;
F_2 ( L_1 , V_1 ) ;
V_11 = F_3 ( V_12 , 0x1 , V_1 , & V_7 ,
& V_9 ) ;
if ( F_4 ( V_11 ) )
return V_11 ;
F_2 ( L_2 , V_11 ) ;
return 0 ;
}
int F_5 ( int V_1 )
{
struct V_2 args = {
. V_3 = V_13 ,
. args = 0 ,
. V_5 = 1 ,
} ;
struct V_6 V_7 = { ( V_8 ) sizeof( args ) , & args } ;
struct V_6 V_9 = { V_10 , NULL } ;
T_1 V_11 ;
F_2 ( L_1 , V_1 ) ;
V_11 = F_3 ( V_12 , 0x1 , V_1 , & V_7 ,
& V_9 ) ;
if ( F_4 ( V_11 ) )
return V_11 ;
F_2 ( L_3 , V_11 ) ;
return 0 ;
}
bool F_6 ( void )
{
bool V_14 ;
V_14 = F_7 ( V_12 ) ;
return V_14 ;
}
static int T_2 F_8 ( void )
{
return 0 ;
}
static void T_3 F_9 ( void )
{
}
