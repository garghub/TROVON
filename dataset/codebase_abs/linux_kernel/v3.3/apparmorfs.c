static char * F_1 ( int V_1 , const char T_1 * V_2 ,
T_2 V_3 , T_2 V_4 ,
T_3 * V_5 )
{
char * V_6 ;
F_2 ( V_4 > V_3 ) ;
if ( * V_5 != 0 )
return F_3 ( - V_7 ) ;
if ( ! F_4 ( V_1 ) )
return F_3 ( - V_8 ) ;
V_6 = F_5 ( V_3 ) ;
if ( V_6 == NULL )
return F_3 ( - V_9 ) ;
if ( F_6 ( V_6 , V_2 , V_4 ) ) {
F_7 ( V_6 ) ;
return F_3 ( - V_10 ) ;
}
return V_6 ;
}
static T_4 F_8 ( struct V_11 * V_12 , const char T_1 * V_13 , T_2 V_14 ,
T_3 * V_5 )
{
char * V_6 ;
T_4 error ;
V_6 = F_1 ( V_15 , V_13 , V_14 , V_14 , V_5 ) ;
error = F_9 ( V_6 ) ;
if ( ! F_10 ( V_6 ) ) {
error = F_11 ( V_6 , V_14 , V_16 ) ;
F_7 ( V_6 ) ;
}
return error ;
}
static T_4 F_12 ( struct V_11 * V_12 , const char T_1 * V_13 ,
T_2 V_14 , T_3 * V_5 )
{
char * V_6 ;
T_4 error ;
V_6 = F_1 ( V_17 , V_13 , V_14 , V_14 , V_5 ) ;
error = F_9 ( V_6 ) ;
if ( ! F_10 ( V_6 ) ) {
error = F_11 ( V_6 , V_14 , V_18 ) ;
F_7 ( V_6 ) ;
}
return error ;
}
static T_4 F_13 ( struct V_11 * V_12 , const char T_1 * V_13 ,
T_2 V_14 , T_3 * V_5 )
{
char * V_6 ;
T_4 error ;
V_6 = F_1 ( V_19 , V_13 , V_14 + 1 , V_14 , V_5 ) ;
error = F_9 ( V_6 ) ;
if ( ! F_10 ( V_6 ) ) {
V_6 [ V_14 ] = 0 ;
error = F_14 ( V_6 , V_14 ) ;
F_7 ( V_6 ) ;
}
return error ;
}
static void T_5 F_15 ( const char * V_20 )
{
struct V_21 * V_21 ;
V_21 = F_16 ( V_20 , V_22 , strlen ( V_20 ) ) ;
if ( ! F_10 ( V_21 ) ) {
F_17 ( V_21 ) ;
F_18 ( V_21 ) ;
}
}
static int T_5 F_19 ( const char * V_20 , T_6 V_23 ,
const struct V_24 * V_25 )
{
struct V_21 * V_21 ;
V_21 = F_20 ( V_20 , V_26 | V_23 , V_22 ,
NULL , V_25 ) ;
return F_10 ( V_21 ) ? F_9 ( V_21 ) : 0 ;
}
void T_5 F_21 ( void )
{
if ( V_22 ) {
F_15 ( L_1 ) ;
F_15 ( L_2 ) ;
F_15 ( L_3 ) ;
F_17 ( V_22 ) ;
V_22 = NULL ;
}
}
static int T_5 F_22 ( void )
{
int error ;
if ( ! V_27 )
return 0 ;
if ( V_22 ) {
F_23 ( L_4 , V_28 ) ;
return - V_29 ;
}
V_22 = F_24 ( L_5 , NULL ) ;
if ( F_10 ( V_22 ) ) {
error = F_9 ( V_22 ) ;
V_22 = NULL ;
goto error;
}
error = F_19 ( L_3 , 0640 , & V_30 ) ;
if ( error )
goto error;
error = F_19 ( L_2 , 0640 , & V_31 ) ;
if ( error )
goto error;
error = F_19 ( L_1 , 0640 , & V_32 ) ;
if ( error )
goto error;
F_25 ( L_6 ) ;
return 0 ;
error:
F_21 () ;
F_23 ( L_7 ) ;
return error ;
}
