static void F_1 ( struct V_1 * V_2 ,
const char * V_3 , const char * V_4 )
{
unsigned long long V_5 , V_6 ;
int V_7 ;
static bool V_8 ;
static long V_9 ;
V_7 = F_2 ( V_10 , L_1 , L_2 , L_3 , & V_5 ) ;
if ( V_7 != 1 ) {
return;
}
V_5 >>= V_11 - 10 ;
if ( ! V_8 ) {
V_8 = true ;
V_7 = F_2 ( V_10 , L_1 , L_4 , L_3 ,
& V_6 ) ;
if ( V_7 != 1 )
V_6 = V_5 ;
else
V_6 >>= V_11 - 10 ;
V_9 = F_3 () ? 0
: V_6 - V_12 . V_13 ;
}
F_4 ( V_5 - V_9 ) ;
}
static int F_5 ( struct V_14 * V_15 ,
unsigned long V_16 ,
void * V_17 )
{
int V_7 ;
V_7 = F_6 ( & V_18 ) ;
if ( V_7 )
F_7 ( L_5 ) ;
return V_19 ;
}
void F_8 ( void )
{
F_9 ( & V_20 ) ;
F_10 ( & V_20 ) ;
F_11 ( & V_21 ) ;
}
static T_1 F_12 ( struct V_22 * V_23 , struct V_24 * V_25 ,
char * V_26 )
{
return sprintf ( V_26 , L_6 , F_13 ( V_12 . V_13 ) ) ;
}
static T_1 F_14 ( struct V_22 * V_23 ,
struct V_24 * V_25 ,
const char * V_26 ,
T_2 V_27 )
{
char * V_28 ;
unsigned long long V_29 ;
if ( ! F_15 ( V_30 ) )
return - V_31 ;
V_29 = F_16 ( V_26 , & V_28 , 0 ) * 1024 ;
F_4 ( V_29 >> V_11 ) ;
return V_27 ;
}
static T_1 F_17 ( struct V_22 * V_23 , struct V_24 * V_25 ,
char * V_26 )
{
return sprintf ( V_26 , L_7 ,
( unsigned long long ) V_12 . V_13
<< V_11 ) ;
}
static T_1 F_18 ( struct V_22 * V_23 ,
struct V_24 * V_25 ,
const char * V_26 ,
T_2 V_27 )
{
char * V_28 ;
unsigned long long V_29 ;
if ( ! F_15 ( V_30 ) )
return - V_31 ;
V_29 = F_19 ( V_26 , & V_28 ) ;
F_4 ( V_29 >> V_11 ) ;
return V_27 ;
}
static int F_9 ( struct V_22 * V_23 )
{
int error ;
error = F_20 ( & V_32 , NULL ) ;
if ( error )
return error ;
V_23 -> V_33 = 0 ;
V_23 -> V_34 = & V_32 ;
V_23 -> V_35 = V_36 ;
error = F_21 ( V_23 ) ;
if ( error ) {
F_22 ( & V_32 ) ;
return error ;
}
return 0 ;
}
