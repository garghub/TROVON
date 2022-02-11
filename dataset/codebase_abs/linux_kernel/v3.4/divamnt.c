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
struct V_10 V_11 ;
F_7 ( & V_11 ) ;
if ( V_11 . V_12 > V_13 . V_12 ) {
if ( V_13 . V_14 > V_11 . V_14 ) {
V_11 . V_12 -- ;
V_11 . V_14 += 1000000 ;
}
* V_8 = ( T_2 ) ( V_11 . V_12 - V_13 . V_12 ) ;
* V_9 = ( T_2 ) ( V_11 . V_14 - V_13 . V_14 ) ;
} else if ( V_11 . V_12 == V_13 . V_12 ) {
* V_8 = 0 ;
if ( V_13 . V_14 < V_11 . V_14 ) {
* V_9 = ( T_2 ) ( V_11 . V_14 - V_13 . V_14 ) ;
} else {
* V_9 = 0 ;
}
} else {
* V_8 = ( T_2 ) V_11 . V_12 ;
* V_9 = ( T_2 ) V_11 . V_14 ;
}
}
static unsigned int F_8 ( struct V_15 * V_15 , T_3 * V_16 )
{
unsigned int V_17 = 0 ;
F_9 ( V_15 , & V_18 , V_16 ) ;
V_17 = V_19 | V_20 ;
if ( V_15 -> V_21 || F_10 () ) {
V_17 |= V_22 | V_23 ;
}
return ( V_17 ) ;
}
static int F_11 ( struct V_24 * V_25 , struct V_15 * V_26 )
{
int V_27 ;
F_12 ( & V_28 ) ;
if ( F_13 ( 0 , & V_29 ) )
V_27 = - V_30 ;
else {
V_26 -> V_21 = NULL ;
V_27 = F_14 ( V_25 , V_26 ) ;
}
F_15 ( & V_28 ) ;
return V_27 ;
}
static int F_16 ( struct V_24 * V_25 , struct V_15 * V_26 )
{
if ( V_26 -> V_21 ) {
F_17 ( 0 , V_26 -> V_21 ) ;
V_26 -> V_21 = NULL ;
}
F_18 ( 0 , & V_29 ) ;
return ( 0 ) ;
}
static T_4 F_19 ( struct V_15 * V_15 , const char T_1 * V_31 ,
T_5 V_32 , T_6 * V_33 )
{
return ( F_20 ( ( char T_1 * ) V_31 , ( int ) V_32 ) ) ;
}
static T_4 F_21 ( struct V_15 * V_15 , char T_1 * V_31 ,
T_5 V_32 , T_6 * V_33 )
{
return ( F_20 ( V_31 , ( int ) V_32 ) ) ;
}
static void F_22 ( void )
{
F_23 ( V_34 , V_35 ) ;
}
static int T_7 F_24 ( void )
{
if ( ( V_34 = F_25 ( 0 , V_35 , & V_36 ) ) < 0 )
{
F_26 ( V_37 L_2 ,
V_38 ) ;
return ( 0 ) ;
}
return ( 1 ) ;
}
void F_27 ( void )
{
F_28 ( & V_18 ) ;
}
static int T_7 F_29 ( void )
{
char V_39 [ 50 ] ;
int V_27 = 0 ;
void * V_40 = NULL ;
F_7 ( & V_13 ) ;
F_30 ( & V_18 ) ;
F_26 ( V_41 L_3 , V_42 ) ;
F_26 ( V_41 L_4 , V_38 , V_43 ) ;
strcpy ( V_39 , V_44 ) ;
F_26 ( L_5 , F_1 ( V_39 ) , V_45 ) ;
if ( ! F_24 () ) {
V_27 = - V_46 ;
goto V_47;
}
if ( ! ( F_31 ( & V_48 , & V_40 , V_49 ) ) ) {
F_26 ( V_37 L_6 ,
V_38 ) ;
F_22 () ;
V_27 = - V_46 ;
goto V_47;
}
F_26 ( V_41 L_7 ,
V_38 , V_40 , ( V_48 / 1024 ) ,
( V_49 == 0 ) ? L_8 : L_9 , V_34 ) ;
V_47:
return ( V_27 ) ;
}
static void T_8 F_32 ( void )
{
F_22 () ;
F_33 () ;
F_26 ( V_41 L_10 , V_38 ) ;
}
