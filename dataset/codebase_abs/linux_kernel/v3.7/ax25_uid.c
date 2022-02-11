T_1 * F_1 ( T_2 V_1 )
{
T_1 * V_2 , * V_3 = NULL ;
struct V_4 * V_5 ;
F_2 ( & V_6 ) ;
F_3 (ax25_uid, node, &ax25_uid_list) {
if ( F_4 ( V_2 -> V_1 , V_1 ) ) {
F_5 ( V_2 ) ;
V_3 = V_2 ;
break;
}
}
F_6 ( & V_6 ) ;
return V_3 ;
}
int F_7 ( int V_7 , struct V_8 * V_9 )
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
if ( F_8 ( & V_9 -> V_13 , & V_2 -> V_14 ) == 0 ) {
V_3 = F_9 ( F_10 () , V_2 -> V_1 ) ;
break;
}
}
F_6 ( & V_6 ) ;
return V_3 ;
case V_15 :
{
T_2 V_16 ;
if ( ! F_11 ( V_17 ) )
return - V_18 ;
V_16 = F_12 ( F_10 () , V_9 -> V_19 ) ;
if ( ! F_13 ( V_16 ) )
return - V_20 ;
V_10 = F_1 ( V_16 ) ;
if ( V_10 ) {
F_14 ( V_10 ) ;
return - V_21 ;
}
if ( V_9 -> V_19 == 0 )
return - V_20 ;
if ( ( V_2 = F_15 ( sizeof( * V_2 ) , V_22 ) ) == NULL )
return - V_23 ;
F_16 ( & V_2 -> V_24 , 1 ) ;
V_2 -> V_1 = V_16 ;
V_2 -> V_14 = V_9 -> V_13 ;
F_17 ( & V_6 ) ;
F_18 ( & V_2 -> V_25 , & V_26 ) ;
F_19 ( & V_6 ) ;
return 0 ;
}
case V_27 :
if ( ! F_11 ( V_17 ) )
return - V_18 ;
V_2 = NULL ;
F_17 ( & V_6 ) ;
F_3 (ax25_uid, node, &ax25_uid_list) {
if ( F_8 ( & V_9 -> V_13 , & V_2 -> V_14 ) == 0 )
break;
}
if ( V_2 == NULL ) {
F_19 ( & V_6 ) ;
return - V_12 ;
}
F_20 ( & V_2 -> V_25 ) ;
F_14 ( V_2 ) ;
F_19 ( & V_6 ) ;
return 0 ;
default:
return - V_20 ;
}
return - V_20 ;
}
static void * F_21 ( struct V_28 * V_29 , T_3 * V_30 )
__acquires( V_6 )
{
F_2 ( & V_6 ) ;
return F_22 ( & V_26 , * V_30 ) ;
}
static void * F_23 ( struct V_28 * V_29 , void * V_31 , T_3 * V_30 )
{
return F_24 ( V_31 , & V_26 , V_30 ) ;
}
static void F_25 ( struct V_28 * V_29 , void * V_31 )
__releases( V_6 )
{
F_6 ( & V_6 ) ;
}
static int F_26 ( struct V_28 * V_29 , void * V_31 )
{
char V_32 [ 11 ] ;
if ( V_31 == V_33 )
F_27 ( V_29 , L_1 , V_34 ) ;
else {
struct T_1 * V_35 ;
V_35 = F_28 ( V_31 , struct T_1 , V_25 ) ;
F_27 ( V_29 , L_2 ,
F_9 ( F_29 ( V_29 ) , V_35 -> V_1 ) ,
F_30 ( V_32 , & V_35 -> V_14 ) ) ;
}
return 0 ;
}
static int F_31 ( struct V_36 * V_36 , struct V_37 * V_37 )
{
return F_32 ( V_37 , & V_38 ) ;
}
void T_4 F_33 ( void )
{
T_1 * V_2 ;
struct V_4 * V_5 ;
F_17 ( & V_6 ) ;
V_39:
F_3 (ax25_uid, node, &ax25_uid_list) {
F_20 ( & V_2 -> V_25 ) ;
F_14 ( V_2 ) ;
goto V_39;
}
F_19 ( & V_6 ) ;
}
