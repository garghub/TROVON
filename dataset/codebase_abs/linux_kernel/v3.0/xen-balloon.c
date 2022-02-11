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
V_13 . V_18 = F_1 ;
V_19 . V_20 = F_4 ;
F_11 ( & V_19 ) ;
return 0 ;
}
static void F_12 ( void )
{
return;
}
static T_2 F_13 ( struct V_21 * V_22 , struct V_23 * V_24 ,
char * V_25 )
{
return sprintf ( V_25 , L_6 , F_14 ( V_26 . V_27 ) ) ;
}
static T_2 F_15 ( struct V_21 * V_22 ,
struct V_23 * V_24 ,
const char * V_25 ,
T_3 V_28 )
{
char * V_29 ;
unsigned long long V_30 ;
if ( ! F_16 ( V_31 ) )
return - V_32 ;
V_30 = F_17 ( V_25 , & V_29 , 0 ) * 1024 ;
F_3 ( V_30 >> V_8 ) ;
return V_28 ;
}
static T_2 F_18 ( struct V_21 * V_22 , struct V_23 * V_24 ,
char * V_25 )
{
return sprintf ( V_25 , L_7 ,
( unsigned long long ) V_26 . V_27
<< V_8 ) ;
}
static T_2 F_19 ( struct V_21 * V_22 ,
struct V_23 * V_24 ,
const char * V_25 ,
T_3 V_28 )
{
char * V_29 ;
unsigned long long V_30 ;
if ( ! F_16 ( V_31 ) )
return - V_32 ;
V_30 = F_20 ( V_25 , & V_29 ) ;
F_3 ( V_30 >> V_8 ) ;
return V_28 ;
}
static int F_10 ( struct V_21 * V_33 )
{
int V_34 , error ;
error = F_21 ( & V_35 ) ;
if ( error )
return error ;
V_33 -> V_36 = 0 ;
V_33 -> V_37 = & V_35 ;
error = F_22 ( V_33 ) ;
if ( error ) {
F_23 ( & V_35 ) ;
return error ;
}
for ( V_34 = 0 ; V_34 < F_24 ( V_38 ) ; V_34 ++ ) {
error = F_25 ( V_33 , V_38 [ V_34 ] ) ;
if ( error )
goto V_39;
}
error = F_26 ( & V_33 -> V_40 , & V_41 ) ;
if ( error )
goto V_39;
return 0 ;
V_39:
while ( -- V_34 >= 0 )
F_27 ( V_33 , V_38 [ V_34 ] ) ;
F_28 ( V_33 ) ;
F_23 ( & V_35 ) ;
return error ;
}
