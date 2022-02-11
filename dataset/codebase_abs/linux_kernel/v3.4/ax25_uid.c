T_1 * F_1 ( T_2 V_1 )
{
T_1 * V_2 , * V_3 = NULL ;
struct V_4 * V_5 ;
F_2 ( & V_6 ) ;
F_3 (ax25_uid, node, &ax25_uid_list) {
if ( V_2 -> V_1 == V_1 ) {
F_4 ( V_2 ) ;
V_3 = V_2 ;
break;
}
}
F_5 ( & V_6 ) ;
return V_3 ;
}
int F_6 ( int V_7 , struct V_8 * V_9 )
{
T_1 * V_2 ;
struct V_4 * V_5 ;
T_1 * V_10 ;
unsigned long V_3 ;
switch ( V_7 ) {
case V_11 :
V_3 = - V_12 ;
F_2 ( & V_6 ) ;
F_3 (ax25_uid, node, &ax25_uid_list) {
if ( F_7 ( & V_9 -> V_13 , & V_2 -> V_14 ) == 0 ) {
V_3 = V_2 -> V_1 ;
break;
}
}
F_5 ( & V_6 ) ;
return V_3 ;
case V_15 :
if ( ! F_8 ( V_16 ) )
return - V_17 ;
V_10 = F_1 ( V_9 -> V_18 ) ;
if ( V_10 ) {
F_9 ( V_10 ) ;
return - V_19 ;
}
if ( V_9 -> V_18 == 0 )
return - V_20 ;
if ( ( V_2 = F_10 ( sizeof( * V_2 ) , V_21 ) ) == NULL )
return - V_22 ;
F_11 ( & V_2 -> V_23 , 1 ) ;
V_2 -> V_1 = V_9 -> V_18 ;
V_2 -> V_14 = V_9 -> V_13 ;
F_12 ( & V_6 ) ;
F_13 ( & V_2 -> V_24 , & V_25 ) ;
F_14 ( & V_6 ) ;
return 0 ;
case V_26 :
if ( ! F_8 ( V_16 ) )
return - V_17 ;
V_2 = NULL ;
F_12 ( & V_6 ) ;
F_3 (ax25_uid, node, &ax25_uid_list) {
if ( F_7 ( & V_9 -> V_13 , & V_2 -> V_14 ) == 0 )
break;
}
if ( V_2 == NULL ) {
F_14 ( & V_6 ) ;
return - V_12 ;
}
F_15 ( & V_2 -> V_24 ) ;
F_9 ( V_2 ) ;
F_14 ( & V_6 ) ;
return 0 ;
default:
return - V_20 ;
}
return - V_20 ;
}
static void * F_16 ( struct V_27 * V_28 , T_3 * V_29 )
__acquires( V_6 )
{
F_2 ( & V_6 ) ;
return F_17 ( & V_25 , * V_29 ) ;
}
static void * F_18 ( struct V_27 * V_28 , void * V_30 , T_3 * V_29 )
{
return F_19 ( V_30 , & V_25 , V_29 ) ;
}
static void F_20 ( struct V_27 * V_28 , void * V_30 )
__releases( V_6 )
{
F_5 ( & V_6 ) ;
}
static int F_21 ( struct V_27 * V_28 , void * V_30 )
{
char V_31 [ 11 ] ;
if ( V_30 == V_32 )
F_22 ( V_28 , L_1 , V_33 ) ;
else {
struct T_1 * V_34 ;
V_34 = F_23 ( V_30 , struct T_1 , V_24 ) ;
F_22 ( V_28 , L_2 , V_34 -> V_1 , F_24 ( V_31 , & V_34 -> V_14 ) ) ;
}
return 0 ;
}
static int F_25 ( struct V_35 * V_35 , struct V_36 * V_36 )
{
return F_26 ( V_36 , & V_37 ) ;
}
void T_4 F_27 ( void )
{
T_1 * V_2 ;
struct V_4 * V_5 ;
F_12 ( & V_6 ) ;
V_38:
F_3 (ax25_uid, node, &ax25_uid_list) {
F_15 ( & V_2 -> V_24 ) ;
F_9 ( V_2 ) ;
goto V_38;
}
F_14 ( & V_6 ) ;
}
