static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
const struct V_5 * V_6 ;
const struct V_7 * V_8 ;
int error ;
V_6 = F_3 ( V_9 ) ;
if ( ! V_6 )
return;
V_8 = V_6 -> V_10 ;
if ( F_4 ( V_2 ) &&
! strncmp ( V_8 -> V_11 , V_4 -> V_12 , V_13 ) ) {
error = F_5 ( V_2 , V_8 -> V_14 ) ;
if ( error )
F_6 ( V_2 , L_1 , error ) ;
}
}
static int F_7 ( struct V_15 * V_16 ,
unsigned long V_17 , void * V_18 )
{
struct V_1 * V_2 = V_18 ;
switch ( V_17 ) {
case V_19 :
F_1 ( V_2 ) ;
break;
default:
break;
}
return 0 ;
}
static int T_1 F_8 ( void )
{
int error ;
error = F_9 ( & V_20 , & V_21 ) ;
if ( error )
F_10 ( L_2 ,
V_22 , error ) ;
return error ;
}
