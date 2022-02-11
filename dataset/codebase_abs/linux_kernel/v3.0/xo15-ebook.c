static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned long long V_5 ;
T_1 V_6 ;
V_6 = F_3 ( V_2 -> V_7 , L_1 , NULL , & V_5 ) ;
if ( F_4 ( V_6 ) )
return - V_8 ;
F_5 ( V_4 -> V_9 , V_10 , ! V_5 ) ;
F_6 ( V_4 -> V_9 ) ;
return 0 ;
}
static void F_7 ( struct V_1 * V_2 , T_2 V_11 )
{
switch ( V_11 ) {
case V_12 :
case V_13 :
F_1 ( V_2 ) ;
break;
default:
F_8 ( ( V_14 ,
L_2 , V_11 ) ) ;
break;
}
}
static int F_9 ( struct V_1 * V_2 )
{
return F_1 ( V_2 ) ;
}
static int F_10 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_15 * V_9 ;
const char * V_16 = F_11 ( V_2 ) ;
char * V_17 , * V_18 ;
int error ;
V_4 = F_12 ( sizeof( struct V_3 ) , V_19 ) ;
if ( ! V_4 )
return - V_20 ;
V_2 -> V_21 = V_4 ;
V_4 -> V_9 = V_9 = F_13 () ;
if ( ! V_9 ) {
error = - V_20 ;
goto V_22;
}
V_17 = F_14 ( V_2 ) ;
V_18 = F_15 ( V_2 ) ;
if ( strcmp ( V_16 , V_23 ) ) {
F_16 ( L_3 , V_16 ) ;
error = - V_24 ;
goto V_25;
}
strcpy ( V_17 , V_26 ) ;
sprintf ( V_18 , L_4 , V_27 , V_28 ) ;
snprintf ( V_4 -> V_29 , sizeof( V_4 -> V_29 ) , L_5 , V_16 ) ;
V_9 -> V_17 = V_17 ;
V_9 -> V_29 = V_4 -> V_29 ;
V_9 -> V_30 . V_31 = V_32 ;
V_9 -> V_33 . V_34 = & V_2 -> V_33 ;
V_9 -> V_35 [ 0 ] = F_17 ( V_36 ) ;
F_18 ( V_10 , V_9 -> V_37 ) ;
error = F_19 ( V_9 ) ;
if ( error )
goto V_25;
F_1 ( V_2 ) ;
if ( V_2 -> V_38 . V_39 . V_40 ) {
F_20 ( V_2 -> V_38 . V_41 ,
V_2 -> V_38 . V_42 ) ;
F_21 ( & V_2 -> V_33 , true ) ;
}
return 0 ;
V_25:
F_22 ( V_9 ) ;
V_22:
F_23 ( V_4 ) ;
return error ;
}
static int F_24 ( struct V_1 * V_2 , int type )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_25 ( V_4 -> V_9 ) ;
F_23 ( V_4 ) ;
return 0 ;
}
static int T_3 F_26 ( void )
{
return F_27 ( & V_43 ) ;
}
static void T_4 F_28 ( void )
{
F_29 ( & V_43 ) ;
}
