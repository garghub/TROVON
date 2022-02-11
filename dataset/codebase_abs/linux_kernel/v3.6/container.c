static int F_1 ( T_1 V_1 )
{
T_1 V_2 ;
T_2 V_3 ;
unsigned long long V_4 ;
V_3 = F_2 ( V_1 , L_1 , & V_2 ) ;
if ( F_3 ( V_3 ) )
return 1 ;
V_3 = F_4 ( V_1 , L_1 , NULL , & V_4 ) ;
if ( F_3 ( V_3 ) )
return 0 ;
return ( ( V_4 & V_5 ) == V_5 ) ;
}
static int F_5 ( struct V_6 * V_7 )
{
struct V_8 * V_9 ;
if ( ! V_7 ) {
F_6 (KERN_ERR PREFIX L_2 ) ;
return - V_10 ;
}
V_9 = F_7 ( sizeof( struct V_8 ) , V_11 ) ;
if ( ! V_9 )
return - V_12 ;
V_9 -> V_1 = V_7 -> V_1 ;
strcpy ( F_8 ( V_7 ) , V_13 ) ;
strcpy ( F_9 ( V_7 ) , V_14 ) ;
V_7 -> V_15 = V_9 ;
F_10 ( ( V_16 , L_3 ,
F_8 ( V_7 ) , F_11 ( V_7 ) ) ) ;
return 0 ;
}
static int F_12 ( struct V_6 * V_7 , int type )
{
T_2 V_3 = V_17 ;
struct V_8 * V_18 = NULL ;
V_18 = F_13 ( V_7 ) ;
F_14 ( V_18 ) ;
return V_3 ;
}
static int F_15 ( struct V_6 * * V_7 , T_1 V_1 )
{
T_1 V_19 ;
struct V_6 * V_20 ;
int V_21 ;
if ( F_16 ( V_1 , & V_19 ) ) {
return - V_22 ;
}
if ( F_17 ( V_19 , & V_20 ) ) {
return - V_22 ;
}
if ( F_18 ( V_7 , V_20 , V_1 , V_23 ) ) {
return - V_22 ;
}
V_21 = F_19 ( * V_7 ) ;
return V_21 ;
}
static void F_20 ( T_1 V_1 , T_3 type , void * V_24 )
{
struct V_6 * V_7 = NULL ;
int V_21 ;
int V_25 ;
T_2 V_3 ;
T_3 V_26 = V_27 ;
switch ( type ) {
case V_28 :
case V_29 :
F_6 ( V_30 L_4 ,
( type == V_28 ) ?
L_5 : L_6 ) ;
V_25 = F_1 ( V_1 ) ;
V_3 = F_17 ( V_1 , & V_7 ) ;
if ( ! V_25 ) {
if ( F_21 ( V_3 ) ) {
V_7 -> V_31 . V_32 = 1 ;
F_22 ( & V_7 -> V_33 . V_34 , V_35 ) ;
return;
}
break;
}
if ( ! F_3 ( V_3 ) || V_7 )
break;
V_21 = F_15 ( & V_7 , V_1 ) ;
if ( V_21 ) {
F_6 ( V_30 L_7 ) ;
break;
}
F_22 ( & V_7 -> V_33 . V_34 , V_36 ) ;
V_26 = V_37 ;
break;
case V_38 :
if ( ! F_17 ( V_1 , & V_7 ) && V_7 ) {
V_7 -> V_31 . V_32 = 1 ;
F_22 ( & V_7 -> V_33 . V_34 , V_35 ) ;
return;
}
break;
default:
return;
}
( void ) F_23 ( V_1 , type , V_26 , NULL ) ;
return;
}
static T_2
F_24 ( T_1 V_1 ,
T_3 V_39 , void * V_24 , void * * V_40 )
{
char * V_41 = NULL ;
struct V_42 * V_43 ;
T_2 V_3 ;
int * V_44 = V_24 ;
V_3 = F_25 ( V_1 , & V_43 ) ;
if ( F_3 ( V_3 ) ) {
return V_17 ;
}
if ( V_43 -> V_45 & V_46 )
V_41 = V_43 -> V_47 . string ;
if ( V_41 == NULL ) {
goto V_48;
}
if ( strcmp ( V_41 , L_8 ) && strcmp ( V_41 , L_9 ) &&
strcmp ( V_41 , L_10 ) ) {
goto V_48;
}
switch ( * V_44 ) {
case V_49 :
F_26 ( V_1 ,
V_50 ,
F_20 , NULL ) ;
break;
case V_51 :
F_27 ( V_1 ,
V_50 ,
F_20 ) ;
break;
default:
break;
}
V_48:
F_14 ( V_43 ) ;
return V_17 ;
}
static int T_4 F_28 ( void )
{
int V_21 = 0 ;
int V_44 = V_49 ;
V_21 = F_29 ( & V_52 ) ;
if ( V_21 < 0 ) {
return ( V_21 ) ;
}
F_30 ( V_53 ,
V_54 ,
V_55 ,
F_24 , NULL , & V_44 , NULL ) ;
return ( 0 ) ;
}
static void T_5 F_31 ( void )
{
int V_44 = V_51 ;
F_30 ( V_53 ,
V_54 ,
V_55 ,
F_24 , NULL , & V_44 , NULL ) ;
F_32 ( & V_52 ) ;
return;
}
