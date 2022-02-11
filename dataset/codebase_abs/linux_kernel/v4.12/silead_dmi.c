static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
int error ;
if ( F_2 ( V_4 ) &&
! strncmp ( V_5 -> V_6 , V_2 -> V_7 , V_8 ) ) {
error = F_3 ( V_4 , V_5 -> V_9 ) ;
if ( error )
F_4 ( V_4 , L_1 , error ) ;
}
}
static int F_5 ( struct V_10 * V_11 ,
unsigned long V_12 , void * V_13 )
{
struct V_3 * V_4 = V_13 ;
struct V_1 * V_2 ;
switch ( V_12 ) {
case V_14 :
V_2 = F_6 ( V_4 ) ;
if ( V_2 )
F_1 ( V_2 ) ;
break;
default:
break;
}
return 0 ;
}
static int T_1 F_7 ( void )
{
const struct V_15 * V_16 ;
int error ;
V_16 = F_8 ( V_17 ) ;
if ( ! V_16 )
return 0 ;
V_5 = V_16 -> V_18 ;
error = F_9 ( & V_19 , & V_20 ) ;
if ( error )
F_10 ( L_2 ,
V_21 , error ) ;
return error ;
}
