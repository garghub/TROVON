static int F_1 ( void * V_1 , T_1 V_2 )
{
V_3 = ( int ) V_2 ;
return 0 ;
}
static int F_2 ( void * V_1 , T_1 * V_2 )
{
* V_2 = ( T_1 ) V_3 ;
return 0 ;
}
static int F_3 ( struct V_4 * V_4 , struct V_5 * V_5 )
{
return 0 ;
}
static T_2 F_4 (
struct V_5 * V_5 ,
const char T_3 * V_6 ,
T_4 V_7 ,
T_5 * V_8 )
{
int V_9 ;
unsigned int V_1 ;
F_5 ( V_10 L_1 ,
V_11 , ( int ) V_3 , ( int ) V_7 , ( int ) * V_8 ) ;
if ( V_7 > sizeof( V_12 ) )
return - V_13 ;
if ( F_6 ( V_12 , V_6 , V_7 ) )
return - V_13 ;
V_12 [ V_7 ] = 0 ;
V_9 = sscanf ( V_12 , L_2 , & V_1 ) ;
if ( V_9 < 1 ) {
F_5 ( V_14 L_3 , V_11 , V_9 ) ;
return - V_15 ;
}
F_7 ( & V_1 , V_16 + V_3 ) ;
return 0 ;
}
static T_2 F_8 (
struct V_5 * V_5 ,
char T_3 * V_6 ,
T_4 V_7 ,
T_5 * V_8 )
{
int V_17 = 0 ;
unsigned int V_1 ;
F_5 ( V_10 L_1 ,
V_11 , ( int ) V_3 , ( int ) V_7 , ( int ) * V_8 ) ;
if ( * V_8 )
return 0 ;
V_1 = F_9 ( V_16 + V_3 ) ;
V_17 = snprintf ( V_12 , 4 , L_4 , V_1 ) ;
if ( V_17 > 0 ) {
if ( V_17 > V_7 )
V_17 = V_7 ;
if ( F_10 ( V_6 , V_12 , V_17 ) )
return - V_13 ;
}
F_5 ( V_10 L_5 , V_11 , V_17 ) ;
if ( V_17 < 0 )
return 0 ;
* V_8 += V_17 ;
return V_17 ;
}
int F_11 ( void )
{
struct V_18 * V_19 = F_12 ( L_6 , NULL ) ;
if ( F_13 ( V_19 ) ) {
F_5 ( V_14 L_7 ,
__FILE__ , __LINE__ , F_14 ( V_19 ) ) ;
return - 1 ;
}
if ( F_15 ( L_8 , 0644 , V_19 , 0 , & V_20 )
== NULL ) {
F_5 ( V_14 L_9 ,
__FILE__ , __LINE__ ) ;
return - 1 ;
}
if ( F_15 ( L_10 , 0644 , V_19 , 0 , & V_21 )
== NULL ) {
F_5 ( V_14 L_11 ,
__FILE__ , __LINE__ ) ;
return - 1 ;
}
V_3 = 0 ;
V_16 = ( V_22 ) V_23 ;
return 0 ;
}
