static int F_1 ( void * V_1 , T_1 V_2 )
{
* ( int * ) V_1 = F_2 ( int , V_2 , - V_3 , 0 ) ;
return 0 ;
}
static int F_3 ( void * V_1 , T_1 * V_2 )
{
* V_2 = * ( int * ) V_1 ;
return 0 ;
}
static struct V_4 * F_4 ( const char * V_5 , T_2 V_6 ,
struct V_4 * V_7 , int * V_8 )
{
return F_5 ( V_5 , V_6 , V_7 , V_8 , & V_9 ) ;
}
static int F_6 ( struct V_10 * V_11 ,
unsigned long V_2 , void * V_12 )
{
int V_13 = 0 ;
struct V_14 * V_15 =
F_7 ( V_11 , struct V_14 , V_11 ) ;
struct V_16 * V_17 ;
for ( V_17 = V_15 -> V_18 ; V_17 -> V_5 ; V_17 ++ ) {
if ( V_17 -> V_2 == V_2 ) {
V_13 = V_17 -> error ;
break;
}
}
if ( V_13 )
F_8 ( L_1 , V_13 , V_17 -> V_5 ) ;
return F_9 ( V_13 ) ;
}
struct V_4 * F_10 ( const char * V_5 , struct V_4 * V_7 ,
struct V_14 * V_15 , int V_19 )
{
struct V_16 * V_17 ;
T_2 V_6 = V_20 | V_21 | V_22 ;
struct V_4 * V_23 ;
struct V_4 * V_24 ;
V_15 -> V_11 . V_25 = F_6 ;
V_15 -> V_11 . V_19 = V_19 ;
V_23 = F_11 ( V_5 , V_7 ) ;
if ( ! V_23 )
return F_12 ( - V_26 ) ;
V_24 = F_11 ( L_2 , V_23 ) ;
if ( ! V_24 )
goto V_27;
for ( V_17 = V_15 -> V_18 ; V_17 -> V_5 ; V_17 ++ ) {
struct V_4 * V_28 ;
V_28 = F_11 ( V_17 -> V_5 , V_24 ) ;
if ( ! V_28 )
goto V_27;
if ( ! F_4 ( L_3 , V_6 , V_28 ,
& V_17 -> error ) )
goto V_27;
}
return V_23 ;
V_27:
F_13 ( V_23 ) ;
return F_12 ( - V_26 ) ;
}
static int T_3 F_14 ( void )
{
V_29 =
F_11 ( L_4 , NULL ) ;
if ( ! V_29 )
return - V_26 ;
return 0 ;
}
static void T_4 F_15 ( void )
{
F_13 ( V_29 ) ;
}
