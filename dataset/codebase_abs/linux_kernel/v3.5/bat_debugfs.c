static void F_1 ( struct V_1 * V_1 , char V_2 )
{
F_2 ( V_1 -> V_3 ) = V_2 ;
V_1 -> V_3 ++ ;
if ( V_1 -> V_3 - V_1 -> V_4 > V_5 )
V_1 -> V_4 = V_1 -> V_3 - V_5 ;
}
static int F_3 ( struct V_1 * V_1 , const char * V_6 , ... )
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
int V_1 ( struct V_11 * V_11 , const char * V_6 , ... )
{
T_1 args ;
char V_12 [ 256 ] ;
va_start ( args , V_6 ) ;
F_5 ( V_12 , sizeof( V_12 ) , V_6 , args ) ;
F_3 ( V_11 -> V_1 , L_1 ,
F_8 ( V_13 ) , V_12 ) ;
va_end ( args ) ;
return 0 ;
}
static int F_9 ( struct V_14 * V_14 , struct V_15 * V_15 )
{
F_10 ( V_14 , V_15 ) ;
V_15 -> V_16 = V_14 -> V_17 ;
F_11 () ;
return 0 ;
}
static int F_12 ( struct V_14 * V_14 , struct V_15 * V_15 )
{
F_13 () ;
return 0 ;
}
static T_2 F_14 ( struct V_15 * V_15 , char T_3 * V_18 ,
T_4 V_19 , T_5 * V_20 )
{
struct V_11 * V_11 = V_15 -> V_16 ;
struct V_1 * V_1 = V_11 -> V_1 ;
int error , V_21 = 0 ;
char V_2 ;
if ( ( V_15 -> V_22 & V_23 ) &&
! ( V_1 -> V_3 - V_1 -> V_4 ) )
return - V_24 ;
if ( ! V_18 )
return - V_25 ;
if ( V_19 == 0 )
return 0 ;
if ( ! F_15 ( V_26 , V_18 , V_19 ) )
return - V_27 ;
error = F_16 ( V_1 -> V_10 ,
( V_1 -> V_4 - V_1 -> V_3 ) ) ;
if ( error )
return error ;
F_4 ( & V_1 -> V_9 ) ;
while ( ( ! error ) && ( V_21 < V_19 ) &&
( V_1 -> V_4 != V_1 -> V_3 ) ) {
V_2 = F_2 ( V_1 -> V_4 ) ;
V_1 -> V_4 ++ ;
F_6 ( & V_1 -> V_9 ) ;
error = F_17 ( V_2 , V_18 ) ;
F_4 ( & V_1 -> V_9 ) ;
V_18 ++ ;
V_21 ++ ;
}
F_6 ( & V_1 -> V_9 ) ;
if ( ! error )
return V_21 ;
return error ;
}
static unsigned int F_18 ( struct V_15 * V_15 , T_6 * V_28 )
{
struct V_11 * V_11 = V_15 -> V_16 ;
struct V_1 * V_1 = V_11 -> V_1 ;
F_19 ( V_15 , & V_1 -> V_10 , V_28 ) ;
if ( V_1 -> V_3 - V_1 -> V_4 )
return V_29 | V_30 ;
return 0 ;
}
static int F_20 ( struct V_11 * V_11 )
{
struct V_31 * V_32 ;
if ( ! V_11 -> V_33 )
goto V_34;
V_11 -> V_1 = F_21 ( sizeof( * V_11 -> V_1 ) , V_35 ) ;
if ( ! V_11 -> V_1 )
goto V_34;
F_22 ( & V_11 -> V_1 -> V_9 ) ;
F_23 ( & V_11 -> V_1 -> V_10 ) ;
V_32 = F_24 ( L_2 , V_36 | V_37 ,
V_11 -> V_33 , V_11 , & V_38 ) ;
if ( V_32 )
goto V_34;
return 0 ;
V_34:
return 1 ;
}
static void F_25 ( struct V_11 * V_11 )
{
F_26 ( V_11 -> V_1 ) ;
V_11 -> V_1 = NULL ;
}
static int F_20 ( struct V_11 * V_11 )
{
V_11 -> V_1 = NULL ;
return 0 ;
}
static void F_25 ( struct V_11 * V_11 )
{
return;
}
static int F_27 ( struct V_14 * V_14 , struct V_15 * V_15 )
{
return F_28 ( V_15 , V_39 , NULL ) ;
}
static int F_29 ( struct V_14 * V_14 , struct V_15 * V_15 )
{
struct V_40 * V_41 = (struct V_40 * ) V_14 -> V_17 ;
return F_28 ( V_15 , V_42 , V_41 ) ;
}
static int F_30 ( struct V_14 * V_14 , struct V_15 * V_15 )
{
struct V_40 * V_41 = (struct V_40 * ) V_14 -> V_17 ;
return F_28 ( V_15 , V_43 , V_41 ) ;
}
static int F_31 ( struct V_14 * V_14 , struct V_15 * V_15 )
{
struct V_40 * V_41 = (struct V_40 * ) V_14 -> V_17 ;
return F_28 ( V_15 , V_44 , V_41 ) ;
}
static int F_32 ( struct V_14 * V_14 , struct V_15 * V_15 )
{
struct V_40 * V_41 = (struct V_40 * ) V_14 -> V_17 ;
return F_28 ( V_15 , V_45 , V_41 ) ;
}
static int F_33 ( struct V_14 * V_14 , struct V_15 * V_15 )
{
struct V_40 * V_41 = (struct V_40 * ) V_14 -> V_17 ;
return F_28 ( V_15 , V_46 , V_41 ) ;
}
static int F_34 ( struct V_14 * V_14 , struct V_15 * V_15 )
{
struct V_40 * V_41 = (struct V_40 * ) V_14 -> V_17 ;
return F_28 ( V_15 , V_47 , V_41 ) ;
}
void F_35 ( void )
{
struct V_48 * V_49 ;
struct V_31 * V_15 ;
V_50 = F_36 ( V_51 , NULL ) ;
if ( V_50 == F_37 ( - V_52 ) )
V_50 = NULL ;
if ( ! V_50 )
goto V_53;
V_49 = & V_54 ;
V_15 = F_24 ( V_49 -> V_55 . V_56 ,
V_36 | V_49 -> V_55 . V_57 ,
V_50 , NULL , & V_49 -> V_58 ) ;
if ( ! V_15 )
F_38 ( L_3 , V_49 -> V_55 . V_56 ) ;
V_53:
return;
}
void F_39 ( void )
{
if ( V_50 ) {
F_40 ( V_50 ) ;
V_50 = NULL ;
}
}
int F_41 ( struct V_40 * V_59 )
{
struct V_11 * V_11 = F_42 ( V_59 ) ;
struct V_48 * * V_49 ;
struct V_31 * V_15 ;
if ( ! V_50 )
goto V_53;
V_11 -> V_33 = F_36 ( V_59 -> V_56 , V_50 ) ;
if ( ! V_11 -> V_33 )
goto V_53;
F_43 ( V_11 ) ;
F_20 ( V_11 ) ;
for ( V_49 = V_60 ; * V_49 ; ++ V_49 ) {
V_15 = F_24 ( ( ( * V_49 ) -> V_55 ) . V_56 ,
V_36 | ( ( * V_49 ) -> V_55 ) . V_57 ,
V_11 -> V_33 ,
V_59 , & ( * V_49 ) -> V_58 ) ;
if ( ! V_15 ) {
F_44 ( V_59 , L_4 ,
V_59 -> V_56 , ( ( * V_49 ) -> V_55 ) . V_56 ) ;
goto V_61;
}
}
return 0 ;
V_61:
F_40 ( V_11 -> V_33 ) ;
V_11 -> V_33 = NULL ;
V_53:
#ifdef F_45
return - V_62 ;
#else
return 0 ;
#endif
}
void F_46 ( struct V_40 * V_59 )
{
struct V_11 * V_11 = F_42 ( V_59 ) ;
F_25 ( V_11 ) ;
if ( V_50 ) {
F_40 ( V_11 -> V_33 ) ;
V_11 -> V_33 = NULL ;
}
}
