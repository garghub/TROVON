void T_1 F_1 ( unsigned int V_1 ,
void (* putc)( unsigned int V_2 , unsigned char V_3 ) )
{
V_4 = V_1 ;
V_5 = putc ;
}
int F_2 ( unsigned int V_2 , char V_6 )
{
if ( V_2 >= V_4 )
return - V_7 ;
V_6 = F_3 ( & V_8 , V_6 ) ;
if ( V_6 < 0 )
return V_6 ;
V_5 ( V_2 , V_6 ) ;
return 0 ;
}
static T_2 F_4 ( struct V_9 * V_10 ,
struct V_11 * V_12 ,
const char * V_13 , T_3 V_14 )
{
unsigned int V_15 = V_10 -> V_16 ;
F_2 ( V_15 , V_13 [ 0 ] ) ;
return V_14 ;
}
static T_2 F_5 ( struct V_9 * V_10 ,
struct V_11 * V_12 ,
const char * V_13 , T_3 V_14 )
{
unsigned int V_15 = V_10 -> V_16 ;
V_5 ( V_15 , V_13 [ 0 ] ) ;
return V_14 ;
}
static T_2 F_6 ( struct V_17 * V_18 ,
struct V_19 * V_12 ,
char * V_13 )
{
memcpy ( V_13 , & V_8 , sizeof( V_8 ) ) ;
return sizeof( V_8 ) ;
}
static T_2 F_7 ( struct V_17 * V_18 ,
struct V_19 * V_12 ,
const char * V_13 , T_3 V_14 )
{
if ( V_14 != sizeof( V_8 ) )
return - V_7 ;
memcpy ( & V_8 , V_13 , V_14 ) ;
return V_14 ;
}
static int T_1 F_8 ( void )
{
int error , V_20 ;
if ( ! V_4 )
return - V_21 ;
error = F_9 ( & V_22 ) ;
if ( error )
return error ;
error = F_10 ( & V_22 ,
& V_23 ) ;
if ( error )
return error ;
for ( V_20 = 0 ; V_20 < V_4 ; V_20 ++ ) {
struct V_9 * V_10 ;
V_10 = F_11 ( sizeof( * V_10 ) , V_24 ) ;
if ( ! V_10 ) {
error = - V_21 ;
break;
}
V_10 -> V_16 = V_20 ;
V_10 -> V_25 = & V_22 ;
error = F_12 ( V_10 ) ;
if ( ! error ) {
F_13 ( V_10 , & V_26 ) ;
F_13 ( V_10 , & V_27 ) ;
}
}
return error ;
}
