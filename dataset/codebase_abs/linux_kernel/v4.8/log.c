static char * F_1 ( struct V_1 * V_2 ,
T_1 V_3 )
{
return & V_2 -> V_4 [ V_3 & V_5 ] ;
}
static void F_2 ( struct V_1 * V_2 ,
char V_6 )
{
char * V_7 ;
V_7 = F_1 ( V_2 , V_2 -> V_8 ) ;
* V_7 = V_6 ;
V_2 -> V_8 ++ ;
if ( V_2 -> V_8 - V_2 -> V_9 > V_10 )
V_2 -> V_9 = V_2 -> V_8 - V_10 ;
}
static int F_3 ( struct V_1 * V_2 ,
const char * V_11 , ... )
{
T_2 args ;
static char V_12 [ 256 ] ;
char * V_13 ;
if ( ! V_2 )
return 0 ;
F_4 ( & V_2 -> V_14 ) ;
va_start ( args , V_11 ) ;
F_5 ( V_12 , sizeof( V_12 ) , V_11 , args ) ;
va_end ( args ) ;
for ( V_13 = V_12 ; * V_13 != 0 ; V_13 ++ )
F_2 ( V_2 , * V_13 ) ;
F_6 ( & V_2 -> V_14 ) ;
F_7 ( & V_2 -> V_15 ) ;
return 0 ;
}
int F_8 ( struct V_16 * V_17 , const char * V_11 , ... )
{
T_2 args ;
char V_18 [ 256 ] ;
va_start ( args , V_11 ) ;
F_5 ( V_18 , sizeof( V_18 ) , V_11 , args ) ;
F_3 ( V_17 -> V_2 , L_1 ,
F_9 ( V_19 ) , V_18 ) ;
va_end ( args ) ;
return 0 ;
}
static int F_10 ( struct V_20 * V_20 , struct V_21 * V_21 )
{
if ( ! F_11 ( V_22 ) )
return - V_23 ;
F_12 ( V_20 , V_21 ) ;
V_21 -> V_24 = V_20 -> V_25 ;
return 0 ;
}
static int F_13 ( struct V_20 * V_20 , struct V_21 * V_21 )
{
F_14 ( V_22 ) ;
return 0 ;
}
static bool F_15 ( struct V_1 * V_2 )
{
return ! ( V_2 -> V_9 - V_2 -> V_8 ) ;
}
static T_3 F_16 ( struct V_21 * V_21 , char T_4 * V_26 ,
T_1 V_27 , T_5 * V_28 )
{
struct V_16 * V_17 = V_21 -> V_24 ;
struct V_1 * V_2 = V_17 -> V_2 ;
int error , V_29 = 0 ;
char * V_7 ;
char V_6 ;
if ( ( V_21 -> V_30 & V_31 ) && F_15 ( V_2 ) )
return - V_32 ;
if ( ! V_26 )
return - V_33 ;
if ( V_27 == 0 )
return 0 ;
if ( ! F_17 ( V_34 , V_26 , V_27 ) )
return - V_35 ;
error = F_18 ( V_2 -> V_15 ,
( ! F_15 ( V_2 ) ) ) ;
if ( error )
return error ;
F_4 ( & V_2 -> V_14 ) ;
while ( ( ! error ) && ( V_29 < V_27 ) &&
( V_2 -> V_9 != V_2 -> V_8 ) ) {
V_7 = F_1 ( V_2 ,
V_2 -> V_9 ) ;
V_6 = * V_7 ;
V_2 -> V_9 ++ ;
F_6 ( & V_2 -> V_14 ) ;
error = F_19 ( V_6 , V_26 ) ;
F_4 ( & V_2 -> V_14 ) ;
V_26 ++ ;
V_29 ++ ;
}
F_6 ( & V_2 -> V_14 ) ;
if ( ! error )
return V_29 ;
return error ;
}
static unsigned int F_20 ( struct V_21 * V_21 , T_6 * V_36 )
{
struct V_16 * V_17 = V_21 -> V_24 ;
struct V_1 * V_2 = V_17 -> V_2 ;
F_21 ( V_21 , & V_2 -> V_15 , V_36 ) ;
if ( ! F_15 ( V_2 ) )
return V_37 | V_38 ;
return 0 ;
}
int F_22 ( struct V_16 * V_17 )
{
struct V_39 * V_40 ;
if ( ! V_17 -> V_41 )
goto V_42;
V_17 -> V_2 = F_23 ( sizeof( * V_17 -> V_2 ) , V_43 ) ;
if ( ! V_17 -> V_2 )
goto V_42;
F_24 ( & V_17 -> V_2 -> V_14 ) ;
F_25 ( & V_17 -> V_2 -> V_15 ) ;
V_40 = F_26 ( L_2 , V_44 | V_45 ,
V_17 -> V_41 , V_17 ,
& V_46 ) ;
if ( ! V_40 )
goto V_42;
return 0 ;
V_42:
return - V_47 ;
}
void F_27 ( struct V_16 * V_17 )
{
F_28 ( V_17 -> V_2 ) ;
V_17 -> V_2 = NULL ;
}
