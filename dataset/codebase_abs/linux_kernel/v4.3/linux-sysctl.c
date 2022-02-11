static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = ( void * ) V_4 ;
return sprintf ( V_5 , L_1 , * V_7 -> V_8 ) ;
}
static T_1 F_2 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_9 , T_2 V_10 )
{
struct V_6 * V_7 = ( void * ) V_4 ;
int V_11 ;
unsigned int V_12 ;
V_11 = F_3 ( V_9 , 10 , & V_12 ) ;
if ( V_11 )
return V_11 ;
* V_7 -> V_8 = V_12 ;
return V_10 ;
}
static T_1 F_4 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
return sprintf ( V_5 , L_2 ,
V_13 / ( 1 << ( 20 - V_14 ) ) ) ;
}
static T_1 F_5 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_9 , T_2 V_10 )
{
int V_11 ;
unsigned long V_12 ;
V_11 = F_6 ( V_9 , 10 , & V_12 ) ;
if ( V_11 )
return V_11 ;
V_12 *= 1 << ( 20 - V_14 ) ;
if ( V_12 > ( ( V_15 / 10 ) * 9 ) ) {
return - V_16 ;
}
if ( V_12 < 4 << ( 20 - V_14 ) ) {
return - V_16 ;
}
V_13 = V_12 ;
return V_10 ;
}
int F_7 ( void )
{
return F_8 ( V_17 , & V_18 ) ;
}
void F_9 ( void )
{
}
