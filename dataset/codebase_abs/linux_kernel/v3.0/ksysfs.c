static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
return sprintf ( V_5 , L_1 , ( unsigned long long ) V_6 ) ;
}
static T_1 F_2 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
return sprintf ( V_5 , L_2 , V_7 ) ;
}
static T_1 F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 , T_2 V_8 )
{
if ( V_8 + 1 > V_9 )
return - V_10 ;
memcpy ( V_7 , V_5 , V_8 ) ;
V_7 [ V_8 ] = '\0' ;
if ( V_8 && V_7 [ V_8 - 1 ] == '\n' )
V_7 [ V_8 - 1 ] = '\0' ;
return V_8 ;
}
static T_1 F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
return sprintf ( V_5 , L_3 , V_11 ) ;
}
static T_1 F_5 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 , T_2 V_8 )
{
int V_12 ;
if ( V_11 )
return - V_13 ;
F_6 ( ( char * ) V_5 ) ;
V_12 = F_7 () ;
if ( V_12 )
return V_12 ;
V_12 = F_8 () ;
if ( V_12 )
return V_12 ;
return V_8 ;
}
static T_1 F_9 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
return sprintf ( V_5 , L_3 , ! ! V_14 ) ;
}
static T_1 F_10 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
return sprintf ( V_5 , L_3 , ! ! V_15 ) ;
}
static T_1 F_11 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
return sprintf ( V_5 , L_4 , F_12 () ) ;
}
static T_1 F_13 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 , T_2 V_8 )
{
unsigned long V_16 ;
int V_12 ;
if ( F_14 ( V_5 , 0 , & V_16 ) )
return - V_17 ;
V_12 = F_15 ( V_16 ) ;
return V_12 < 0 ? V_12 : V_8 ;
}
static T_1 F_16 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
return sprintf ( V_5 , L_5 ,
F_17 () ,
( unsigned int ) V_18 ) ;
}
static T_1 F_18 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
return sprintf ( V_5 , L_3 , V_19 ) ;
}
static T_1 F_19 ( struct V_20 * V_21 , struct V_1 * V_2 ,
struct V_22 * V_23 ,
char * V_5 , T_3 V_24 , T_2 V_8 )
{
memcpy ( V_5 , & V_25 + V_24 , V_8 ) ;
return V_8 ;
}
static int T_4 F_20 ( void )
{
int error ;
V_26 = F_21 ( L_6 , NULL ) ;
if ( ! V_26 ) {
error = - V_27 ;
goto exit;
}
error = F_22 ( V_26 , & V_28 ) ;
if ( error )
goto V_29;
if ( V_30 > 0 ) {
V_31 . V_32 = V_30 ;
error = F_23 ( V_26 , & V_31 ) ;
if ( error )
goto V_33;
}
return 0 ;
V_33:
F_24 ( V_26 , & V_28 ) ;
V_29:
F_25 ( V_26 ) ;
exit:
return error ;
}
