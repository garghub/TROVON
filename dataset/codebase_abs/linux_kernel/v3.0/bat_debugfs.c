static void F_1 ( struct V_1 * V_1 , char V_2 )
{
F_2 ( V_1 -> V_3 ) = V_2 ;
V_1 -> V_3 ++ ;
if ( V_1 -> V_3 - V_1 -> V_4 > V_5 )
V_1 -> V_4 = V_1 -> V_3 - V_5 ;
}
static int F_3 ( struct V_1 * V_1 , char * V_6 , ... )
{
T_1 args ;
static char V_7 [ 256 ] ;
char * V_8 ;
if ( ! V_1 )
return 0 ;
F_4 ( & V_1 -> V_9 ) ;
va_start ( args , V_6 ) ;
F_5 ( V_7 , sizeof( V_7 ) , V_6 , args ) ;
va_end ( args ) ;
for ( V_8 = V_7 ; * V_8 != 0 ; V_8 ++ )
F_1 ( V_1 , * V_8 ) ;
F_6 ( & V_1 -> V_9 ) ;
F_7 ( & V_1 -> V_10 ) ;
return 0 ;
}
int V_1 ( struct V_11 * V_11 , char * V_6 , ... )
{
T_1 args ;
char V_12 [ 256 ] ;
va_start ( args , V_6 ) ;
F_5 ( V_12 , sizeof( V_12 ) , V_6 , args ) ;
F_3 ( V_11 -> V_1 , L_1 ,
( V_13 / V_14 ) , V_12 ) ;
va_end ( args ) ;
return 0 ;
}
static int F_8 ( struct V_15 * V_15 , struct V_16 * V_16 )
{
F_9 ( V_15 , V_16 ) ;
V_16 -> V_17 = V_15 -> V_18 ;
F_10 () ;
return 0 ;
}
static int F_11 ( struct V_15 * V_15 , struct V_16 * V_16 )
{
F_12 () ;
return 0 ;
}
static T_2 F_13 ( struct V_16 * V_16 , char T_3 * V_19 ,
T_4 V_20 , T_5 * V_21 )
{
struct V_11 * V_11 = V_16 -> V_17 ;
struct V_1 * V_1 = V_11 -> V_1 ;
int error , V_22 = 0 ;
char V_2 ;
if ( ( V_16 -> V_23 & V_24 ) &&
! ( V_1 -> V_3 - V_1 -> V_4 ) )
return - V_25 ;
if ( ( ! V_19 ) || ( V_20 < 0 ) )
return - V_26 ;
if ( V_20 == 0 )
return 0 ;
if ( ! F_14 ( V_27 , V_19 , V_20 ) )
return - V_28 ;
error = F_15 ( V_1 -> V_10 ,
( V_1 -> V_4 - V_1 -> V_3 ) ) ;
if ( error )
return error ;
F_4 ( & V_1 -> V_9 ) ;
while ( ( ! error ) && ( V_22 < V_20 ) &&
( V_1 -> V_4 != V_1 -> V_3 ) ) {
V_2 = F_2 ( V_1 -> V_4 ) ;
V_1 -> V_4 ++ ;
F_6 ( & V_1 -> V_9 ) ;
error = F_16 ( V_2 , V_19 ) ;
F_4 ( & V_1 -> V_9 ) ;
V_19 ++ ;
V_22 ++ ;
}
F_6 ( & V_1 -> V_9 ) ;
if ( ! error )
return V_22 ;
return error ;
}
static unsigned int F_17 ( struct V_16 * V_16 , T_6 * V_29 )
{
struct V_11 * V_11 = V_16 -> V_17 ;
struct V_1 * V_1 = V_11 -> V_1 ;
F_18 ( V_16 , & V_1 -> V_10 , V_29 ) ;
if ( V_1 -> V_3 - V_1 -> V_4 )
return V_30 | V_31 ;
return 0 ;
}
static int F_19 ( struct V_11 * V_11 )
{
struct V_32 * V_33 ;
if ( ! V_11 -> V_34 )
goto V_35;
V_11 -> V_1 = F_20 ( sizeof( struct V_1 ) , V_36 ) ;
if ( ! V_11 -> V_1 )
goto V_35;
F_21 ( & V_11 -> V_1 -> V_9 ) ;
F_22 ( & V_11 -> V_1 -> V_10 ) ;
V_33 = F_23 ( L_2 , V_37 | V_38 ,
V_11 -> V_34 , V_11 , & V_39 ) ;
if ( V_33 )
goto V_35;
return 0 ;
V_35:
return 1 ;
}
static void F_24 ( struct V_11 * V_11 )
{
F_25 ( V_11 -> V_1 ) ;
V_11 -> V_1 = NULL ;
}
static int F_19 ( struct V_11 * V_11 )
{
V_11 -> V_1 = NULL ;
return 0 ;
}
static void F_24 ( struct V_11 * V_11 )
{
return;
}
static int F_26 ( struct V_15 * V_15 , struct V_16 * V_16 )
{
struct V_40 * V_41 = (struct V_40 * ) V_15 -> V_18 ;
return F_27 ( V_16 , V_42 , V_41 ) ;
}
static int F_28 ( struct V_15 * V_15 , struct V_16 * V_16 )
{
struct V_40 * V_41 = (struct V_40 * ) V_15 -> V_18 ;
return F_27 ( V_16 , V_43 , V_41 ) ;
}
static int F_29 ( struct V_15 * V_15 , struct V_16 * V_16 )
{
struct V_40 * V_41 = (struct V_40 * ) V_15 -> V_18 ;
return F_27 ( V_16 , V_44 , V_41 ) ;
}
static int F_30 ( struct V_15 * V_15 , struct V_16 * V_16 )
{
struct V_40 * V_41 = (struct V_40 * ) V_15 -> V_18 ;
return F_27 ( V_16 , V_45 , V_41 ) ;
}
static int F_31 ( struct V_15 * V_15 , struct V_16 * V_16 )
{
struct V_40 * V_41 = (struct V_40 * ) V_15 -> V_18 ;
return F_27 ( V_16 , V_46 , V_41 ) ;
}
static int F_32 ( struct V_15 * V_15 , struct V_16 * V_16 )
{
struct V_40 * V_41 = (struct V_40 * ) V_15 -> V_18 ;
return F_27 ( V_16 , V_47 , V_41 ) ;
}
void F_33 ( void )
{
V_48 = F_34 ( V_49 , NULL ) ;
if ( V_48 == F_35 ( - V_50 ) )
V_48 = NULL ;
}
void F_36 ( void )
{
if ( V_48 ) {
F_37 ( V_48 ) ;
V_48 = NULL ;
}
}
int F_38 ( struct V_40 * V_51 )
{
struct V_11 * V_11 = F_39 ( V_51 ) ;
struct V_52 * * V_53 ;
struct V_32 * V_16 ;
if ( ! V_48 )
goto V_54;
V_11 -> V_34 = F_34 ( V_51 -> V_55 , V_48 ) ;
if ( ! V_11 -> V_34 )
goto V_54;
F_40 ( V_11 ) ;
F_19 ( V_11 ) ;
for ( V_53 = V_56 ; * V_53 ; ++ V_53 ) {
V_16 = F_23 ( ( ( * V_53 ) -> V_57 ) . V_55 ,
V_37 | ( ( * V_53 ) -> V_57 ) . V_58 ,
V_11 -> V_34 ,
V_51 , & ( * V_53 ) -> V_59 ) ;
if ( ! V_16 ) {
F_41 ( V_51 , L_3 ,
V_51 -> V_55 , ( ( * V_53 ) -> V_57 ) . V_55 ) ;
goto V_60;
}
}
return 0 ;
V_60:
F_37 ( V_11 -> V_34 ) ;
V_11 -> V_34 = NULL ;
V_54:
#ifdef F_42
return - V_61 ;
#else
return 0 ;
#endif
}
void F_43 ( struct V_40 * V_51 )
{
struct V_11 * V_11 = F_39 ( V_51 ) ;
F_24 ( V_11 ) ;
if ( V_48 ) {
F_37 ( V_11 -> V_34 ) ;
V_11 -> V_34 = NULL ;
}
}
