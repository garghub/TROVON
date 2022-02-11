static void F_1 ( struct V_1 * V_2 ,
const char * V_3 , const char * V_4 )
{
unsigned long long V_5 ;
int V_6 ;
static bool V_7 ;
static long V_8 ;
V_6 = F_2 ( V_9 , L_1 , L_2 , L_3 , & V_5 ) ;
if ( V_6 != 1 ) {
return;
}
V_5 >>= V_10 - 10 ;
if ( V_7 ) {
F_3 ( V_5 - V_8 ) ;
return;
}
V_7 = true ;
V_8 = V_5 - V_11 . V_12 ;
}
static int F_4 ( struct V_13 * V_14 ,
unsigned long V_15 ,
void * V_16 )
{
int V_6 ;
V_6 = F_5 ( & V_17 ) ;
if ( V_6 )
F_6 ( L_4 ) ;
return V_18 ;
}
void F_7 ( void )
{
F_8 ( & V_19 ) ;
F_9 ( & V_19 ) ;
F_10 ( & V_20 ) ;
}
static T_1 F_11 ( struct V_21 * V_22 , struct V_23 * V_24 ,
char * V_25 )
{
return sprintf ( V_25 , L_5 , F_12 ( V_11 . V_12 ) ) ;
}
static T_1 F_13 ( struct V_21 * V_22 ,
struct V_23 * V_24 ,
const char * V_25 ,
T_2 V_26 )
{
char * V_27 ;
unsigned long long V_28 ;
if ( ! F_14 ( V_29 ) )
return - V_30 ;
V_28 = F_15 ( V_25 , & V_27 , 0 ) * 1024 ;
F_3 ( V_28 >> V_10 ) ;
return V_26 ;
}
static T_1 F_16 ( struct V_21 * V_22 , struct V_23 * V_24 ,
char * V_25 )
{
return sprintf ( V_25 , L_6 ,
( unsigned long long ) V_11 . V_12
<< V_10 ) ;
}
static T_1 F_17 ( struct V_21 * V_22 ,
struct V_23 * V_24 ,
const char * V_25 ,
T_2 V_26 )
{
char * V_27 ;
unsigned long long V_28 ;
if ( ! F_14 ( V_29 ) )
return - V_30 ;
V_28 = F_18 ( V_25 , & V_27 ) ;
F_3 ( V_28 >> V_10 ) ;
return V_26 ;
}
static int F_8 ( struct V_21 * V_22 )
{
int error ;
error = F_19 ( & V_31 , NULL ) ;
if ( error )
return error ;
V_22 -> V_32 = 0 ;
V_22 -> V_33 = & V_31 ;
V_22 -> V_34 = V_35 ;
error = F_20 ( V_22 ) ;
if ( error ) {
F_21 ( & V_31 ) ;
return error ;
}
return 0 ;
}
