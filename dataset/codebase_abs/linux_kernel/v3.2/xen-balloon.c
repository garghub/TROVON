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
F_6 ( V_14 L_4 ) ;
return V_15 ;
}
static int T_1 F_7 ( void )
{
if ( ! F_8 () )
return - V_16 ;
F_9 ( L_5 ) ;
F_10 ( & V_17 ) ;
F_11 ( & V_17 ) ;
F_12 ( & V_18 ) ;
return 0 ;
}
static void F_13 ( void )
{
return;
}
static T_2 F_14 ( struct V_19 * V_20 , struct V_21 * V_22 ,
char * V_23 )
{
return sprintf ( V_23 , L_6 , F_15 ( V_24 . V_25 ) ) ;
}
static T_2 F_16 ( struct V_19 * V_20 ,
struct V_21 * V_22 ,
const char * V_23 ,
T_3 V_26 )
{
char * V_27 ;
unsigned long long V_28 ;
if ( ! F_17 ( V_29 ) )
return - V_30 ;
V_28 = F_18 ( V_23 , & V_27 , 0 ) * 1024 ;
F_3 ( V_28 >> V_8 ) ;
return V_26 ;
}
static T_2 F_19 ( struct V_19 * V_20 , struct V_21 * V_22 ,
char * V_23 )
{
return sprintf ( V_23 , L_7 ,
( unsigned long long ) V_24 . V_25
<< V_8 ) ;
}
static T_2 F_20 ( struct V_19 * V_20 ,
struct V_21 * V_22 ,
const char * V_23 ,
T_3 V_26 )
{
char * V_27 ;
unsigned long long V_28 ;
if ( ! F_17 ( V_29 ) )
return - V_30 ;
V_28 = F_21 ( V_23 , & V_27 ) ;
F_3 ( V_28 >> V_8 ) ;
return V_26 ;
}
static int F_10 ( struct V_19 * V_31 )
{
int V_32 , error ;
error = F_22 ( & V_33 ) ;
if ( error )
return error ;
V_31 -> V_34 = 0 ;
V_31 -> V_35 = & V_33 ;
error = F_23 ( V_31 ) ;
if ( error ) {
F_24 ( & V_33 ) ;
return error ;
}
for ( V_32 = 0 ; V_32 < F_25 ( V_36 ) ; V_32 ++ ) {
error = F_26 ( V_31 , V_36 [ V_32 ] ) ;
if ( error )
goto V_37;
}
error = F_27 ( & V_31 -> V_38 , & V_39 ) ;
if ( error )
goto V_37;
return 0 ;
V_37:
while ( -- V_32 >= 0 )
F_28 ( V_31 , V_36 [ V_32 ] ) ;
F_29 ( V_31 ) ;
F_24 ( & V_33 ) ;
return error ;
}
