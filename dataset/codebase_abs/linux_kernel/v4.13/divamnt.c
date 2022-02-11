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
int F_2 ( void * V_4 , void T_1 * V_5 , const void * V_6 ,
int V_7 )
{
return ( F_3 ( V_5 , V_6 , V_7 ) ) ;
}
int F_4 ( void * V_4 , void * V_5 , const void T_1 * V_6 ,
int V_7 )
{
return ( F_5 ( V_5 , V_6 , V_7 ) ) ;
}
void F_6 ( T_2 * V_8 , T_2 * V_9 )
{
struct V_10 time ;
F_7 ( & time ) ;
* V_8 = ( T_2 ) time . V_11 ;
* V_9 = ( T_2 ) ( time . V_12 / V_13 ) ;
}
static unsigned int F_8 ( struct V_14 * V_14 , T_3 * V_15 )
{
unsigned int V_16 = 0 ;
F_9 ( V_14 , & V_17 , V_15 ) ;
V_16 = V_18 | V_19 ;
if ( V_14 -> V_20 || F_10 () ) {
V_16 |= V_21 | V_22 ;
}
return ( V_16 ) ;
}
static int F_11 ( struct V_23 * V_24 , struct V_14 * V_25 )
{
int V_26 ;
F_12 ( & V_27 ) ;
if ( F_13 ( 0 , & V_28 ) )
V_26 = - V_29 ;
else {
V_25 -> V_20 = NULL ;
V_26 = F_14 ( V_24 , V_25 ) ;
}
F_15 ( & V_27 ) ;
return V_26 ;
}
static int F_16 ( struct V_23 * V_24 , struct V_14 * V_25 )
{
if ( V_25 -> V_20 ) {
F_17 ( 0 , V_25 -> V_20 ) ;
V_25 -> V_20 = NULL ;
}
F_18 ( 0 , & V_28 ) ;
return ( 0 ) ;
}
static T_4 F_19 ( struct V_14 * V_14 , const char T_1 * V_30 ,
T_5 V_31 , T_6 * V_32 )
{
return ( F_20 ( ( char T_1 * ) V_30 , ( int ) V_31 ) ) ;
}
static T_4 F_21 ( struct V_14 * V_14 , char T_1 * V_30 ,
T_5 V_31 , T_6 * V_32 )
{
return ( F_20 ( V_30 , ( int ) V_31 ) ) ;
}
static void F_22 ( void )
{
F_23 ( V_33 , V_34 ) ;
}
static int T_7 F_24 ( void )
{
if ( ( V_33 = F_25 ( 0 , V_34 , & V_35 ) ) < 0 )
{
F_26 ( V_36 L_2 ,
V_37 ) ;
return ( 0 ) ;
}
return ( 1 ) ;
}
void F_27 ( void )
{
F_28 ( & V_17 ) ;
}
static int T_7 F_29 ( void )
{
char V_38 [ 50 ] ;
int V_26 = 0 ;
void * V_39 = NULL ;
F_30 ( & V_17 ) ;
F_26 ( V_40 L_3 , V_41 ) ;
F_26 ( V_40 L_4 , V_37 , V_42 ) ;
strcpy ( V_38 , V_43 ) ;
F_26 ( L_5 , F_1 ( V_38 ) , V_44 ) ;
if ( ! F_24 () ) {
V_26 = - V_45 ;
goto V_46;
}
if ( ! ( F_31 ( & V_47 , & V_39 , V_48 ) ) ) {
F_26 ( V_36 L_6 ,
V_37 ) ;
F_22 () ;
V_26 = - V_45 ;
goto V_46;
}
F_26 ( V_40 L_7 ,
V_37 , V_39 , ( V_47 / 1024 ) ,
( V_48 == 0 ) ? L_8 : L_9 , V_33 ) ;
V_46:
return ( V_26 ) ;
}
static void T_8 F_32 ( void )
{
F_22 () ;
F_33 () ;
F_26 ( V_40 L_10 , V_37 ) ;
}
