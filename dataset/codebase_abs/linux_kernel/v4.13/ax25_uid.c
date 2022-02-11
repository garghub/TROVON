T_1 * F_1 ( T_2 V_1 )
{
T_1 * V_2 , * V_3 = NULL ;
F_2 ( & V_4 ) ;
F_3 (ax25_uid, &ax25_uid_list) {
if ( F_4 ( V_2 -> V_1 , V_1 ) ) {
F_5 ( V_2 ) ;
V_3 = V_2 ;
break;
}
}
F_6 ( & V_4 ) ;
return V_3 ;
}
int F_7 ( int V_5 , struct V_6 * V_7 )
{
T_1 * V_2 ;
T_1 * V_8 ;
unsigned long V_3 ;
switch ( V_5 ) {
case V_9 :
V_3 = - V_10 ;
F_2 ( & V_4 ) ;
F_3 (ax25_uid, &ax25_uid_list) {
if ( F_8 ( & V_7 -> V_11 , & V_2 -> V_12 ) == 0 ) {
V_3 = F_9 ( F_10 () , V_2 -> V_1 ) ;
break;
}
}
F_6 ( & V_4 ) ;
return V_3 ;
case V_13 :
{
T_2 V_14 ;
if ( ! F_11 ( V_15 ) )
return - V_16 ;
V_14 = F_12 ( F_10 () , V_7 -> V_17 ) ;
if ( ! F_13 ( V_14 ) )
return - V_18 ;
V_8 = F_1 ( V_14 ) ;
if ( V_8 ) {
F_14 ( V_8 ) ;
return - V_19 ;
}
if ( V_7 -> V_17 == 0 )
return - V_18 ;
if ( ( V_2 = F_15 ( sizeof( * V_2 ) , V_20 ) ) == NULL )
return - V_21 ;
F_16 ( & V_2 -> V_22 , 1 ) ;
V_2 -> V_1 = V_14 ;
V_2 -> V_12 = V_7 -> V_11 ;
F_17 ( & V_4 ) ;
F_18 ( & V_2 -> V_23 , & V_24 ) ;
F_19 ( & V_4 ) ;
return 0 ;
}
case V_25 :
if ( ! F_11 ( V_15 ) )
return - V_16 ;
V_2 = NULL ;
F_17 ( & V_4 ) ;
F_3 (ax25_uid, &ax25_uid_list) {
if ( F_8 ( & V_7 -> V_11 , & V_2 -> V_12 ) == 0 )
break;
}
if ( V_2 == NULL ) {
F_19 ( & V_4 ) ;
return - V_10 ;
}
F_20 ( & V_2 -> V_23 ) ;
F_14 ( V_2 ) ;
F_19 ( & V_4 ) ;
return 0 ;
default:
return - V_18 ;
}
return - V_18 ;
}
static void * F_21 ( struct V_26 * V_27 , T_3 * V_28 )
__acquires( V_4 )
{
F_2 ( & V_4 ) ;
return F_22 ( & V_24 , * V_28 ) ;
}
static void * F_23 ( struct V_26 * V_27 , void * V_29 , T_3 * V_28 )
{
return F_24 ( V_29 , & V_24 , V_28 ) ;
}
static void F_25 ( struct V_26 * V_27 , void * V_29 )
__releases( V_4 )
{
F_6 ( & V_4 ) ;
}
static int F_26 ( struct V_26 * V_27 , void * V_29 )
{
char V_30 [ 11 ] ;
if ( V_29 == V_31 )
F_27 ( V_27 , L_1 , V_32 ) ;
else {
struct T_1 * V_33 ;
V_33 = F_28 ( V_29 , struct T_1 , V_23 ) ;
F_27 ( V_27 , L_2 ,
F_9 ( F_29 ( V_27 ) , V_33 -> V_1 ) ,
F_30 ( V_30 , & V_33 -> V_12 ) ) ;
}
return 0 ;
}
static int F_31 ( struct V_34 * V_34 , struct V_35 * V_35 )
{
return F_32 ( V_35 , & V_36 ) ;
}
void T_4 F_33 ( void )
{
T_1 * V_2 ;
F_17 ( & V_4 ) ;
V_37:
F_3 (ax25_uid, &ax25_uid_list) {
F_20 ( & V_2 -> V_23 ) ;
F_14 ( V_2 ) ;
goto V_37;
}
F_19 ( & V_4 ) ;
}
