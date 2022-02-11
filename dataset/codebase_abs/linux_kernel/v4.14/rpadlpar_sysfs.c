static T_1 F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 , T_2 V_6 )
{
char V_7 [ V_8 ] ;
char * V_9 ;
int V_10 ;
if ( V_6 >= V_8 )
return 0 ;
memcpy ( V_7 , V_5 , V_6 ) ;
V_9 = strchr ( V_7 , '\n' ) ;
if ( ! V_9 )
V_9 = & V_7 [ V_6 ] ;
* V_9 = '\0' ;
V_10 = F_2 ( V_7 ) ;
if ( V_10 )
return V_10 ;
return V_6 ;
}
static T_1 F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
return sprintf ( V_5 , L_1 ) ;
}
static T_1 F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 , T_2 V_6 )
{
char V_7 [ V_8 ] ;
int V_10 ;
char * V_9 ;
if ( V_6 >= V_8 )
return 0 ;
memcpy ( V_7 , V_5 , V_6 ) ;
V_9 = strchr ( V_7 , '\n' ) ;
if ( ! V_9 )
V_9 = & V_7 [ V_6 ] ;
* V_9 = '\0' ;
V_10 = F_5 ( V_7 ) ;
if ( V_10 )
return V_10 ;
return V_6 ;
}
static T_1 F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
return sprintf ( V_5 , L_1 ) ;
}
int F_7 ( void )
{
int error ;
V_11 = F_8 ( V_12 ,
& V_13 -> V_2 ) ;
if ( ! V_11 )
return - V_14 ;
error = F_9 ( V_11 , & V_15 ) ;
if ( error )
F_10 ( V_11 ) ;
return error ;
}
void F_11 ( void )
{
F_12 ( V_11 , & V_15 ) ;
F_10 ( V_11 ) ;
}
