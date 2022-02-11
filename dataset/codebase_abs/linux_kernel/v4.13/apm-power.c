static void F_1 ( unsigned int V_1 )
{
switch ( V_1 ) {
case V_2 :
F_2 ( V_3 ) ;
F_3 ( L_1 ) ;
break;
default:
break;
}
}
static void F_4 ( struct V_4 * V_5 , unsigned int type ,
unsigned int V_6 , int V_7 )
{
if ( V_7 != 1 )
return;
switch ( type ) {
case V_8 :
F_1 ( V_6 ) ;
break;
default:
break;
}
}
static int F_5 ( struct V_9 * V_10 ,
struct V_11 * V_12 ,
const struct V_13 * V_14 )
{
struct V_4 * V_5 ;
int error ;
V_5 = F_6 ( sizeof( struct V_4 ) , V_15 ) ;
if ( ! V_5 )
return - V_16 ;
V_5 -> V_12 = V_12 ;
V_5 -> V_10 = V_10 ;
V_5 -> V_17 = L_2 ;
error = F_7 ( V_5 ) ;
if ( error ) {
F_8 ( L_3 ,
error ) ;
F_9 ( V_5 ) ;
return error ;
}
error = F_10 ( V_5 ) ;
if ( error ) {
F_8 ( L_4 , error ) ;
F_11 ( V_5 ) ;
F_9 ( V_5 ) ;
return error ;
}
return 0 ;
}
static void F_12 ( struct V_4 * V_5 )
{
F_13 ( V_5 ) ;
F_11 ( V_5 ) ;
F_9 ( V_5 ) ;
}
static int T_1 F_14 ( void )
{
return F_15 ( & V_18 ) ;
}
static void T_2 F_16 ( void )
{
F_17 ( & V_18 ) ;
}
