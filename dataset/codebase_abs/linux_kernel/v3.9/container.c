static int F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
return 1 ;
}
static int F_2 ( T_1 V_5 )
{
T_1 V_6 ;
T_2 V_7 ;
unsigned long long V_8 ;
V_7 = F_3 ( V_5 , L_1 , & V_6 ) ;
if ( F_4 ( V_7 ) )
return 1 ;
V_7 = F_5 ( V_5 , L_1 , NULL , & V_8 ) ;
if ( F_4 ( V_7 ) )
return 0 ;
return ( ( V_8 & V_9 ) == V_9 ) ;
}
static void F_6 ( T_1 V_5 , T_3 type , void * V_10 )
{
struct V_1 * V_2 = NULL ;
int V_11 ;
int V_12 ;
T_2 V_7 ;
T_3 V_13 = V_14 ;
F_7 () ;
switch ( type ) {
case V_15 :
case V_16 :
F_8 ( L_2 ,
( type == V_15 ) ?
L_3 : L_4 ) ;
V_12 = F_2 ( V_5 ) ;
V_7 = F_9 ( V_5 , & V_2 ) ;
if ( ! V_12 ) {
if ( F_10 ( V_7 ) ) {
V_2 -> V_17 . V_18 = 1 ;
F_11 ( & V_2 -> V_19 . V_20 , V_21 ) ;
goto V_22;
}
break;
}
if ( ! F_4 ( V_7 ) || V_2 )
break;
V_11 = F_12 ( V_5 ) ;
if ( V_11 ) {
F_13 ( V_5 , L_5 ) ;
break;
}
V_11 = F_9 ( V_5 , & V_2 ) ;
if ( V_11 ) {
F_13 ( V_5 , L_6 ) ;
break;
}
F_11 ( & V_2 -> V_19 . V_20 , V_23 ) ;
V_13 = V_24 ;
break;
case V_25 :
if ( ! F_9 ( V_5 , & V_2 ) && V_2 ) {
V_2 -> V_17 . V_18 = 1 ;
F_11 ( & V_2 -> V_19 . V_20 , V_21 ) ;
goto V_22;
}
break;
default:
goto V_22;
}
( void ) F_14 ( V_5 , type , V_13 , NULL ) ;
V_22:
F_15 () ;
}
static bool F_16 ( T_1 V_5 )
{
struct V_26 * V_27 ;
bool V_28 = false ;
if ( F_4 ( F_17 ( V_5 , & V_27 ) ) )
return false ;
if ( V_27 -> V_29 & V_30 ) {
const struct V_3 * V_31 ;
for ( V_31 = V_32 ; V_31 -> V_31 [ 0 ] ; V_31 ++ ) {
V_28 = ! strcmp ( ( char * ) V_31 -> V_31 , V_27 -> V_33 . string ) ;
if ( V_28 )
break;
}
}
F_18 ( V_27 ) ;
return V_28 ;
}
static T_2 F_19 ( T_1 V_5 ,
T_3 V_34 , void * V_35 ,
void * * V_36 )
{
if ( F_16 ( V_5 ) )
F_20 ( V_5 , V_37 ,
F_6 , NULL ) ;
return V_38 ;
}
void T_4 F_21 ( void )
{
F_22 ( V_39 , V_40 , V_41 ,
F_19 , NULL ,
NULL , NULL ) ;
F_23 ( & V_42 ) ;
}
