static void F_1 ( char * V_1 )
{
F_2 ( V_1 ) ;
}
static void F_3 ( void * V_2 , void * V_3 ,
T_1 * V_4 , int V_5 , long V_6 ,
void * V_7 )
{
if ( V_3 ) {
T_2 * V_8 = ( T_2 * ) V_3 ;
F_4 ( V_8 -> V_9 ) ;
F_2 ( V_8 -> V_10 ) ;
F_2 ( V_8 -> V_11 ) ;
F_5 ( V_8 -> V_12 , F_1 ) ;
F_2 ( V_8 ) ;
}
}
static int F_6 ( T_3 * V_13 , T_2 * * V_8 )
{
T_2 * V_14 = F_7 ( sizeof( * V_14 ) ) ;
int V_15 = 1 ;
if ( V_14 == NULL ) {
F_8 ( V_16 , V_17 ) ;
return 0 ;
}
V_14 -> V_12 = F_9 () ;
if ( V_14 -> V_12 == NULL ) {
F_8 ( V_16 , V_17 ) ;
F_2 ( V_14 ) ;
return 0 ;
}
V_14 -> V_18 = L_1 ;
V_14 -> V_19 = L_2 ;
V_14 -> V_20 = 1 ;
F_10 ( V_21 ) ;
if ( ( * V_8 = ( T_2 * ) F_11 ( V_13 ,
V_22 ) )
== NULL ) {
V_15 = F_12 ( V_13 , V_22 , V_14 ) ;
if ( V_15 ) {
* V_8 = V_14 ;
V_14 = NULL ;
}
}
F_13 ( V_21 ) ;
if ( V_14 )
F_14 ( V_14 -> V_12 ) ;
F_2 ( V_14 ) ;
return V_15 ;
}
static T_2 * F_15 ( T_3 * V_13 )
{
T_2 * V_8 ;
if ( V_22 < 0 ) {
int V_23 = F_16 ( 0 , NULL , NULL , NULL ,
F_3 ) ;
if ( V_23 == - 1 ) {
F_8 ( V_24 , V_25 ) ;
return NULL ;
}
F_10 ( V_21 ) ;
if ( V_22 < 0 ) {
V_22 = V_23 ;
V_23 = - 1 ;
}
F_13 ( V_21 ) ;
}
V_8 = ( T_2 * ) F_11 ( V_13 , V_22 ) ;
if ( ( V_8 == NULL ) && ! F_6 ( V_13 , & V_8 ) )
return NULL ;
return V_8 ;
}
static T_3 * F_17 ( void )
{
T_3 * V_15 = F_18 () ;
if ( V_15 == NULL )
return NULL ;
if ( ! F_19 ( V_15 , V_26 ) ||
! F_20 ( V_15 , V_27 ) ||
! F_21 ( V_15 , V_28 ) ||
! F_22 ( V_15 , V_29 ) ||
! F_23 ( V_15 , V_30 ) ||
! F_24 ( V_15 , V_31 ) ||
! F_25 ( V_15 , V_32 ) ) {
F_26 ( V_15 ) ;
return NULL ;
}
return V_15 ;
}
void F_27 ( void )
{
T_3 * V_33 = F_17 () ;
if ( ! V_33 )
return;
F_28 ( V_33 ) ;
F_26 ( V_33 ) ;
F_29 () ;
}
static int V_28 ( T_3 * V_13 )
{
return 0 ;
}
static int V_29 ( T_3 * V_13 )
{
return 0 ;
}
static int V_30 ( T_3 * V_13 , int V_34 , long V_35 , void * V_36 , void (* F_30) ( void ) )
{
T_2 * V_8 = F_15 ( V_13 ) ;
int V_37 ;
if ( ! V_8 ) {
F_8 ( V_38 , V_39 ) ;
return 0 ;
}
V_37 = ( ( V_8 -> V_9 == NULL ) ? 0 : 1 ) ;
if ( V_37 ) {
F_8 ( V_38 , V_40 ) ;
return 0 ;
}
switch ( V_34 ) {
case V_41 :
if ( V_36 && ( strlen ( ( const char * ) V_36 ) < 1 ) )
V_36 = NULL ;
F_2 ( V_8 -> V_10 ) ;
if ( V_36 )
V_8 -> V_10 = F_31 ( V_36 ) ;
else
V_8 -> V_10 = NULL ;
return ( V_8 -> V_10 ? 1 : 0 ) ;
case V_42 :
V_8 -> V_43 = ( ( V_35 == 0 ) ? 0 : 1 ) ;
return 1 ;
case V_44 :
if ( V_36 && ( strlen ( ( const char * ) V_36 ) < 1 ) )
V_36 = NULL ;
F_2 ( V_8 -> V_11 ) ;
if ( V_36 )
V_8 -> V_11 = F_31 ( V_36 ) ;
else
V_8 -> V_11 = NULL ;
return ( V_8 -> V_11 ? 1 : 0 ) ;
case V_45 :
if ( ( V_35 < 0 ) || ( V_35 > 2 ) ) {
F_8 ( V_38 , V_46 ) ;
return 0 ;
}
V_8 -> V_47 = ( int ) V_35 ;
return 1 ;
case V_48 :
return F_32 ( V_13 , V_8 ) ;
case V_49 :
if ( ( V_35 < 0 ) || ( V_35 > 2 ) ) {
F_8 ( V_38 , V_46 ) ;
return 0 ;
}
V_8 -> V_20 = ( int ) V_35 ;
return 1 ;
case V_50 :
if ( ! V_36 || ( strlen ( ( const char * ) V_36 ) < 1 ) ) {
F_8 ( V_38 , V_46 ) ;
return 0 ;
}
{
char * V_51 = F_31 ( V_36 ) ;
if ( V_51 == NULL ) {
F_8 ( V_38 , V_17 ) ;
return 0 ;
}
if ( ! F_33 ( V_8 -> V_12 , V_51 ) ) {
F_2 ( V_51 ) ;
F_8 ( V_38 , V_17 ) ;
return 0 ;
}
}
return 1 ;
default:
break;
}
F_8 ( V_38 , V_52 ) ;
return 0 ;
}
static int F_34 ( T_2 * V_8 )
{
int V_53 , V_54 ;
if ( ( V_8 -> V_20 != 2 ) && ( F_35 ( V_8 -> V_9 ,
V_8 -> V_10 , NULL ,
0 ) ) != NULL )
return 1 ;
if ( ! V_8 -> V_20 || ( V_53 = F_36 ( V_8 -> V_12 ) ) < 1 )
return 0 ;
for ( V_54 = 0 ; V_54 < V_53 ; V_54 ++ ) {
const char * V_1 = F_37 ( V_8 -> V_12 , V_54 ) ;
char * V_55 = F_38 ( V_8 -> V_9 , V_8 -> V_10 , V_1 ) ;
if ( ! V_55 )
return 0 ;
if ( F_35 ( V_8 -> V_9 , V_55 , NULL , 0 ) ) {
F_2 ( V_55 ) ;
return 1 ;
}
F_2 ( V_55 ) ;
}
return 0 ;
}
static int F_32 ( T_3 * V_13 , T_2 * V_8 )
{
T_3 V_56 ;
T_4 V_57 ;
if ( V_8 -> V_9 == NULL )
V_8 -> V_9 = F_39 () ;
if ( V_8 -> V_9 == NULL )
return 0 ;
if ( ! V_8 -> V_10 ) {
if ( ! V_8 -> V_11 )
return 0 ;
F_40 ( V_8 -> V_9 , V_58 ,
V_59 , NULL ) ;
V_8 -> V_10 =
F_41 ( V_8 -> V_9 , V_8 -> V_11 ) ;
}
if ( ! F_34 ( V_8 ) ) {
F_8 ( V_60 , V_61 ) ;
F_4 ( V_8 -> V_9 ) ;
V_8 -> V_9 = NULL ;
return 0 ;
}
if ( !
( V_8 -> V_62 =
( V_63 ) F_42 ( V_8 -> V_9 ,
V_8 -> V_19 ) ) ) {
V_8 -> V_62 = NULL ;
F_4 ( V_8 -> V_9 ) ;
V_8 -> V_9 = NULL ;
F_8 ( V_60 , V_64 ) ;
return 0 ;
}
if ( ! V_8 -> V_43 ) {
unsigned long V_65 = 0 ;
V_8 -> V_66 =
( V_67 ) F_42 ( V_8 -> V_9 ,
V_8 -> V_18 ) ;
if ( V_8 -> V_66 )
V_65 = V_8 -> V_66 ( V_68 ) ;
if ( V_65 < V_69 ) {
V_8 -> V_62 = NULL ;
V_8 -> V_66 = NULL ;
F_4 ( V_8 -> V_9 ) ;
V_8 -> V_9 = NULL ;
F_8 ( V_60 ,
V_70 ) ;
return 0 ;
}
}
memcpy ( & V_56 , V_13 , sizeof( T_3 ) ) ;
V_57 . V_71 = F_43 () ;
F_44 ( & V_57 . V_72 . V_73 , & V_57 . V_72 . V_74 ,
& V_57 . V_72 . V_75 ) ;
F_45 ( V_13 ) ;
if ( ! V_8 -> V_62 ( V_13 , V_8 -> V_11 , & V_57 ) ) {
V_8 -> V_62 = NULL ;
V_8 -> V_66 = NULL ;
F_4 ( V_8 -> V_9 ) ;
V_8 -> V_9 = NULL ;
F_8 ( V_60 , V_76 ) ;
memcpy ( V_13 , & V_56 , sizeof( T_3 ) ) ;
return 0 ;
}
if ( V_8 -> V_47 > 0 ) {
if ( ! F_28 ( V_13 ) ) {
if ( V_8 -> V_47 > 1 ) {
F_8 ( V_60 ,
V_77 ) ;
return 0 ;
}
F_29 () ;
}
}
return 1 ;
}
