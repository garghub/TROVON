static char * F_1 ( const char * V_1 )
{
char * V_2 ;
char * V_3 ;
if ( ( V_3 = strchr ( V_1 , ':' ) ) ) {
V_2 = V_3 + 2 ;
V_3 = strchr ( V_2 , '$' ) ;
* -- V_3 = 0 ;
} else
V_2 = L_1 ;
return V_2 ;
}
static int F_2 ( struct V_4 * V_5 , void * V_6 )
{
char V_7 [ 32 ] ;
F_3 ( V_5 , L_2 , V_8 ) ;
F_3 ( V_5 , L_3 , V_9 ) ;
F_3 ( V_5 , L_4 , V_10 ) ;
strcpy ( V_7 , V_11 ) ;
F_3 ( V_5 , L_5 , F_1 ( V_7 ) ) ;
F_3 ( V_5 , L_6 , V_12 ) ;
F_3 ( V_5 , L_7 , V_13 ) ;
return 0 ;
}
static int F_4 ( struct V_14 * V_14 , struct V_15 * V_15 )
{
return F_5 ( V_15 , F_2 , NULL ) ;
}
static int T_1 F_6 ( void )
{
V_16 = F_7 ( V_9 , V_17 , V_18 ,
& V_19 ) ;
if ( ! V_16 )
return ( 0 ) ;
return ( 1 ) ;
}
static void F_8 ( void )
{
if ( V_16 ) {
F_9 ( V_9 , V_18 ) ;
V_16 = NULL ;
}
}
static void F_10 ( void )
{
F_11 ( V_13 , V_20 ) ;
}
static int T_1 F_12 ( void )
{
if ( ( V_13 = F_13 ( 0 , V_20 , & V_21 ) ) < 0 )
{
F_14 ( V_22 L_8 ,
V_9 ) ;
return ( 0 ) ;
}
return ( 1 ) ;
}
static int T_1 F_15 ( void )
{
char V_7 [ 50 ] ;
int V_23 = 0 ;
F_14 ( V_24 L_2 , V_8 ) ;
F_14 ( V_24 L_9 , V_9 , V_10 ) ;
strcpy ( V_7 , V_11 ) ;
F_14 ( L_10 , F_1 ( V_7 ) , V_12 ) ;
if ( ! F_12 () ) {
V_23 = - V_25 ;
goto V_26;
}
if ( ! F_6 () ) {
F_10 () ;
F_14 ( V_22 L_11 ,
V_9 ) ;
V_23 = - V_25 ;
goto V_26;
}
if ( ! ( F_16 () ) ) {
F_8 () ;
F_10 () ;
F_14 ( V_22 L_12 ,
V_9 ) ;
V_23 = - V_25 ;
goto V_26;
}
F_14 ( V_24 L_13 , V_9 , V_13 ) ;
V_26:
return ( V_23 ) ;
}
static void T_2 F_17 ( void )
{
F_18 () ;
F_8 () ;
F_10 () ;
F_14 ( V_24 L_14 , V_9 ) ;
}
static int
F_19 ( void * V_27 , void * V_28 , const void * V_29 ,
int V_30 )
{
memcpy ( V_28 , V_29 , V_30 ) ;
return ( V_30 ) ;
}
static T_3
F_20 ( struct V_15 * V_15 , char T_4 * V_31 , T_5 V_32 , T_6 * V_33 )
{
T_7 * V_34 ;
int V_23 = - V_35 ;
void * V_36 ;
if ( ! V_15 -> V_37 ) {
return ( - V_38 ) ;
}
if ( !
( V_34 =
( T_7 * ) F_21 ( V_15 ->
V_37 ) ) )
{
return ( - V_38 ) ;
}
if ( V_34 -> V_39 ) {
return ( - V_38 ) ;
}
if ( ! ( V_36 = F_22 ( 0 , V_32 ) ) ) {
return ( - V_40 ) ;
}
V_23 = F_23 ( V_15 -> V_37 ,
V_15 , V_36 , V_32 ,
F_19 ) ;
switch ( V_23 ) {
case 0 :
V_23 = ( - V_41 ) ;
break;
case ( - 1 ) :
V_23 = ( - V_38 ) ;
break;
case ( - 2 ) :
V_23 = ( - V_42 ) ;
break;
}
if ( V_23 > 0 ) {
if ( F_24 ( V_31 , V_36 , V_23 ) ) {
V_23 = ( - V_42 ) ;
}
}
F_25 ( 0 , V_36 ) ;
F_26 ( ( L_15 , V_23 ) ) ;
return ( V_23 ) ;
}
static int
F_27 ( void * V_27 , void * V_28 , const void * V_29 ,
int V_30 )
{
memcpy ( V_28 , V_29 , V_30 ) ;
return ( V_30 ) ;
}
static int F_28 ( struct V_15 * V_15 , int V_43 )
{
T_7 * V_34 ;
void * V_44 =
F_29 ( ( V_45 ) V_43 , ( void * ) V_15 ) ;
if ( ! ( V_15 -> V_37 = V_44 ) ) {
return ( 0 ) ;
}
V_34 = ( T_7 * ) F_21 ( V_44 ) ;
F_30 ( & V_34 -> V_46 ) ;
F_30 ( & V_34 -> V_47 ) ;
F_31 ( & V_34 -> V_48 ) ;
V_34 -> V_48 . V_49 = ( void * ) V_50 ;
V_34 -> V_48 . V_36 = ( unsigned long ) V_34 ;
V_34 -> V_39 = 0 ;
V_34 -> V_43 = V_43 ;
return ( 1 ) ;
}
static T_3
F_32 ( struct V_15 * V_15 , const char T_4 * V_31 , T_5 V_32 ,
T_6 * V_33 )
{
T_7 * V_34 ;
int V_23 = - V_35 ;
void * V_36 ;
int V_43 = 0 ;
if ( ! V_15 -> V_37 ) {
if ( V_32 == sizeof( int ) ) {
if ( F_33
( ( void * ) & V_43 , V_31 ,
V_32 ) ) return ( - V_42 ) ;
if ( ! ( F_28 ( V_15 , V_43 ) ) )
return ( - V_38 ) ;
return ( V_32 ) ;
} else
return ( - V_38 ) ;
}
if ( ! ( V_34 =
( T_7 * ) F_21 ( V_15 ->
V_37 ) ) )
{
return ( - V_38 ) ;
}
if ( V_34 -> V_39 ) {
return ( - V_38 ) ;
}
if ( ! ( V_36 = F_22 ( 0 , V_32 ) ) ) {
return ( - V_40 ) ;
}
if ( F_33 ( V_36 , V_31 , V_32 ) ) {
V_23 = - V_42 ;
} else {
V_23 = F_34 ( V_15 -> V_37 ,
V_15 , V_36 , V_32 ,
F_27 ) ;
switch ( V_23 ) {
case 0 :
V_23 = ( - V_41 ) ;
break;
case ( - 1 ) :
V_23 = ( - V_38 ) ;
break;
case ( - 2 ) :
V_23 = ( - V_42 ) ;
break;
}
}
F_25 ( 0 , V_36 ) ;
F_26 ( ( L_16 , V_23 ) ) ;
return ( V_23 ) ;
}
static unsigned int F_35 ( struct V_15 * V_15 , T_8 * V_51 )
{
T_7 * V_34 ;
if ( ! V_15 -> V_37 ) {
return ( V_52 ) ;
}
if ( ( ! ( V_34 =
( T_7 * )
F_21 ( V_15 -> V_37 ) ) )
|| V_34 -> V_39 ) {
return ( V_52 ) ;
}
F_36 ( V_15 , & V_34 -> V_46 , V_51 ) ;
if ( V_34 -> V_39 ) {
return ( V_52 ) ;
}
switch ( F_37 ( V_15 -> V_37 , V_15 ) ) {
case ( - 1 ) :
return ( V_52 ) ;
case 0 :
return ( 0 ) ;
}
return ( V_53 | V_54 ) ;
}
static int F_38 ( struct V_14 * V_14 , struct V_15 * V_15 )
{
return ( 0 ) ;
}
static int F_39 ( struct V_14 * V_14 , struct V_15 * V_15 )
{
T_7 * V_34 ;
unsigned int V_43 ;
int V_23 = 0 ;
if ( ! ( V_15 -> V_37 ) ) {
V_23 = - V_38 ;
goto V_26;
}
if ( ! ( V_34 =
( T_7 * ) F_21 ( V_15 -> V_37 ) ) ) {
V_23 = - V_38 ;
goto V_26;
}
V_43 = V_34 -> V_43 ;
if ( ( V_23 = F_40 ( V_15 -> V_37 ) ) ) {
goto V_26;
}
if ( F_41
( ( int ) V_43 , V_15 -> V_37 ) ) {
V_23 = - V_38 ;
goto V_26;
}
V_26:
return ( V_23 ) ;
}
int F_42 ( void )
{
return ( sizeof( T_7 ) ) ;
}
void F_43 ( void * V_55 )
{
T_7 * V_34 =
( T_7 * ) V_55 ;
F_44 ( & V_34 -> V_46 ) ;
}
void F_45 ( void * V_55 )
{
T_7 * V_34 =
( T_7 * ) V_55 ;
F_44 ( & V_34 -> V_47 ) ;
}
static
void V_50 ( unsigned long V_36 )
{
T_7 * V_34 = ( T_7 * ) V_36 ;
V_34 -> V_39 = 1 ;
F_44 ( & V_34 -> V_46 ) ;
F_44 ( & V_34 -> V_47 ) ;
F_46 ((L_17))
}
static int F_40 ( void * V_56 )
{
struct V_57 * V_58 = V_59 ;
T_7 * V_34 ;
F_47 ( V_56 ) ;
if ( ! V_56 ) {
F_48 ((L_18))
return ( 0 ) ;
}
if ( ! ( V_34 =
( T_7 * )
F_21 ( V_56 ) ) ) {
F_48 ((L_19))
return ( 0 ) ;
}
if ( ! F_49 ( V_56 ) || V_34 -> V_39 ) {
return ( 0 ) ;
}
F_26 ((L_20, entity))
F_50 ( V_56 ) ;
{
F_51 ( V_51 , V_58 ) ;
F_52 ( & V_34 -> V_47 , & V_51 ) ;
for (; ; ) {
F_53 ( V_60 ) ;
if ( ! F_54 ( V_56 )
|| V_34 -> V_39 ) {
break;
}
F_55 () ;
}
F_53 ( V_61 ) ;
F_56 ( & V_34 -> V_47 , & V_51 ) ;
}
F_26 ((L_21, entity))
{
F_51 ( V_51 , V_58 ) ;
F_52 ( & V_34 -> V_47 , & V_51 ) ;
for (; ; ) {
F_53 ( V_60 ) ;
if ( ! F_49 ( V_56 )
|| V_34 -> V_39 ) {
break;
}
F_55 () ;
}
F_53 ( V_61 ) ;
F_56 ( & V_34 -> V_47 , & V_51 ) ;
}
F_26 ((L_22, entity,
p_os->aborted))
F_47 ( V_56 ) ;
V_34 -> V_39 = 0 ;
return ( 0 ) ;
}
void F_50 ( void * V_56 )
{
T_7 * V_34 ;
if ( V_56 &&
( ( V_34 =
( T_7 * )
F_21 ( V_56 ) ) ) ) {
F_57 ( & V_34 -> V_48 , V_62 + 10 * V_63 ) ;
}
}
void F_47 ( void * V_56 )
{
T_7 * V_34 ;
if ( V_56 &&
( ( V_34 =
( T_7 * )
F_21 ( V_56 ) ) ) ) {
F_58 ( & V_34 -> V_48 ) ;
}
}
