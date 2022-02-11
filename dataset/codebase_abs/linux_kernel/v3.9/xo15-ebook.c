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
static int F_9 ( struct V_2 * V_15 )
{
return F_1 ( F_10 ( V_15 ) ) ;
}
static int F_11 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_16 * V_9 ;
const char * V_17 = F_12 ( V_2 ) ;
char * V_18 , * V_19 ;
int error ;
V_4 = F_13 ( sizeof( struct V_3 ) , V_20 ) ;
if ( ! V_4 )
return - V_21 ;
V_2 -> V_22 = V_4 ;
V_4 -> V_9 = V_9 = F_14 () ;
if ( ! V_9 ) {
error = - V_21 ;
goto V_23;
}
V_18 = F_15 ( V_2 ) ;
V_19 = F_16 ( V_2 ) ;
if ( strcmp ( V_17 , V_24 ) ) {
F_17 ( L_3 , V_17 ) ;
error = - V_25 ;
goto V_26;
}
strcpy ( V_18 , V_27 ) ;
sprintf ( V_19 , L_4 , V_28 , V_29 ) ;
snprintf ( V_4 -> V_30 , sizeof( V_4 -> V_30 ) , L_5 , V_17 ) ;
V_9 -> V_18 = V_18 ;
V_9 -> V_30 = V_4 -> V_30 ;
V_9 -> V_31 . V_32 = V_33 ;
V_9 -> V_15 . V_34 = & V_2 -> V_15 ;
V_9 -> V_35 [ 0 ] = F_18 ( V_36 ) ;
F_19 ( V_10 , V_9 -> V_37 ) ;
error = F_20 ( V_9 ) ;
if ( error )
goto V_26;
F_1 ( V_2 ) ;
if ( V_2 -> V_38 . V_39 . V_40 ) {
F_21 ( V_2 -> V_38 . V_41 ,
V_2 -> V_38 . V_42 ) ;
F_22 ( & V_2 -> V_15 , true ) ;
}
return 0 ;
V_26:
F_23 ( V_9 ) ;
V_23:
F_24 ( V_4 ) ;
return error ;
}
static int F_25 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_26 ( V_4 -> V_9 ) ;
F_24 ( V_4 ) ;
return 0 ;
}
