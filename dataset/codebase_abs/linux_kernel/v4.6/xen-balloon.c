static void F_1 ( struct V_1 * V_2 ,
const char * * V_3 , unsigned int V_4 )
{
unsigned long long V_5 ;
int V_6 ;
V_6 = F_2 ( V_7 , L_1 , L_2 , L_3 , & V_5 ) ;
if ( V_6 != 1 ) {
return;
}
F_3 ( V_5 >> ( V_8 - 10 ) ) ;
}
static int F_4 ( struct V_9 * V_10 ,
unsigned long V_11 ,
void * V_12 )
{
int V_6 ;
V_6 = F_5 ( & V_13 ) ;
if ( V_6 )
F_6 ( L_4 ) ;
return V_14 ;
}
static int T_1 F_7 ( void )
{
if ( ! F_8 () )
return - V_15 ;
F_9 ( L_5 ) ;
F_10 ( & V_16 ) ;
F_11 ( & V_16 ) ;
F_12 ( & V_17 ) ;
return 0 ;
}
static T_2 F_13 ( struct V_18 * V_19 , struct V_20 * V_21 ,
char * V_22 )
{
return sprintf ( V_22 , L_6 , F_14 ( V_23 . V_24 ) ) ;
}
static T_2 F_15 ( struct V_18 * V_19 ,
struct V_20 * V_21 ,
const char * V_22 ,
T_3 V_25 )
{
char * V_26 ;
unsigned long long V_27 ;
if ( ! F_16 ( V_28 ) )
return - V_29 ;
V_27 = F_17 ( V_22 , & V_26 , 0 ) * 1024 ;
F_3 ( V_27 >> V_8 ) ;
return V_25 ;
}
static T_2 F_18 ( struct V_18 * V_19 , struct V_20 * V_21 ,
char * V_22 )
{
return sprintf ( V_22 , L_7 ,
( unsigned long long ) V_23 . V_24
<< V_8 ) ;
}
static T_2 F_19 ( struct V_18 * V_19 ,
struct V_20 * V_21 ,
const char * V_22 ,
T_3 V_25 )
{
char * V_26 ;
unsigned long long V_27 ;
if ( ! F_16 ( V_28 ) )
return - V_29 ;
V_27 = F_20 ( V_22 , & V_26 ) ;
F_3 ( V_27 >> V_8 ) ;
return V_25 ;
}
static int F_10 ( struct V_18 * V_19 )
{
int error ;
error = F_21 ( & V_30 , NULL ) ;
if ( error )
return error ;
V_19 -> V_31 = 0 ;
V_19 -> V_32 = & V_30 ;
V_19 -> V_33 = V_34 ;
error = F_22 ( V_19 ) ;
if ( error ) {
F_23 ( & V_30 ) ;
return error ;
}
return 0 ;
}
