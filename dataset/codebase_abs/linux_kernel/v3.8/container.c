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
static bool F_5 ( const char * V_6 )
{
const struct V_7 * V_8 ;
for ( V_8 = V_9 ;
V_8 -> V_10 [ 0 ] ; V_8 ++ ) {
if ( ! strcmp ( ( char * ) V_8 -> V_10 , V_6 ) )
return true ;
}
return false ;
}
static int F_6 ( struct V_11 * V_12 )
{
struct V_13 * V_14 ;
V_14 = F_7 ( sizeof( struct V_13 ) , V_15 ) ;
if ( ! V_14 )
return - V_16 ;
V_14 -> V_1 = V_12 -> V_1 ;
strcpy ( F_8 ( V_12 ) , V_17 ) ;
strcpy ( F_9 ( V_12 ) , V_18 ) ;
V_12 -> V_19 = V_14 ;
F_10 ( ( V_20 , L_2 ,
F_8 ( V_12 ) , F_11 ( V_12 ) ) ) ;
return 0 ;
}
static int F_12 ( struct V_11 * V_12 , int type )
{
T_2 V_3 = V_21 ;
struct V_13 * V_22 = NULL ;
V_22 = F_13 ( V_12 ) ;
F_14 ( V_22 ) ;
return V_3 ;
}
static int F_15 ( struct V_11 * * V_12 , T_1 V_1 )
{
T_1 V_23 ;
struct V_11 * V_24 ;
int V_25 ;
if ( F_16 ( V_1 , & V_23 ) ) {
return - V_26 ;
}
if ( F_17 ( V_23 , & V_24 ) ) {
return - V_26 ;
}
if ( F_18 ( V_12 , V_24 , V_1 , V_27 ) ) {
return - V_26 ;
}
V_25 = F_19 ( * V_12 ) ;
return V_25 ;
}
static void F_20 ( T_1 V_1 , T_3 type , void * V_28 )
{
struct V_11 * V_12 = NULL ;
int V_25 ;
int V_29 ;
T_2 V_3 ;
T_3 V_30 = V_31 ;
switch ( type ) {
case V_32 :
case V_33 :
F_21 ( L_3 ,
( type == V_32 ) ?
L_4 : L_5 ) ;
V_29 = F_1 ( V_1 ) ;
V_3 = F_17 ( V_1 , & V_12 ) ;
if ( ! V_29 ) {
if ( F_22 ( V_3 ) ) {
V_12 -> V_34 . V_35 = 1 ;
F_23 ( & V_12 -> V_36 . V_37 , V_38 ) ;
return;
}
break;
}
if ( ! F_3 ( V_3 ) || V_12 )
break;
V_25 = F_15 ( & V_12 , V_1 ) ;
if ( V_25 ) {
F_24 ( V_1 , L_6 ) ;
break;
}
F_23 ( & V_12 -> V_36 . V_37 , V_39 ) ;
V_30 = V_40 ;
break;
case V_41 :
if ( ! F_17 ( V_1 , & V_12 ) && V_12 ) {
V_12 -> V_34 . V_35 = 1 ;
F_23 ( & V_12 -> V_36 . V_37 , V_38 ) ;
return;
}
break;
default:
return;
}
( void ) F_25 ( V_1 , type , V_30 , NULL ) ;
return;
}
static T_2
F_26 ( T_1 V_1 ,
T_3 V_42 , void * V_28 , void * * V_43 )
{
char * V_6 = NULL ;
struct V_44 * V_45 ;
T_2 V_3 ;
int * V_46 = V_28 ;
V_3 = F_27 ( V_1 , & V_45 ) ;
if ( F_3 ( V_3 ) ) {
return V_21 ;
}
if ( V_45 -> V_47 & V_48 )
V_6 = V_45 -> V_49 . string ;
if ( V_6 == NULL ) {
goto V_50;
}
if ( ! F_5 ( V_6 ) )
goto V_50;
switch ( * V_46 ) {
case V_51 :
F_28 ( V_1 ,
V_52 ,
F_20 , NULL ) ;
break;
case V_53 :
F_29 ( V_1 ,
V_52 ,
F_20 ) ;
break;
default:
break;
}
V_50:
F_14 ( V_45 ) ;
return V_21 ;
}
static int T_4 F_30 ( void )
{
int V_25 = 0 ;
int V_46 = V_51 ;
V_25 = F_31 ( & V_54 ) ;
if ( V_25 < 0 ) {
return ( V_25 ) ;
}
F_32 ( V_55 ,
V_56 ,
V_57 ,
F_26 , NULL , & V_46 , NULL ) ;
return ( 0 ) ;
}
static void T_5 F_33 ( void )
{
int V_46 = V_53 ;
F_32 ( V_55 ,
V_56 ,
V_57 ,
F_26 , NULL , & V_46 , NULL ) ;
F_34 ( & V_54 ) ;
return;
}
