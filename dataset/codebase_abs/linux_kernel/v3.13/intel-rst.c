static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 ;
unsigned long long V_8 ;
T_2 V_9 ;
V_7 = F_2 ( V_2 ) ;
V_9 = F_3 ( V_7 -> V_10 , L_1 , NULL , & V_8 ) ;
if ( ! F_4 ( V_9 ) )
return - V_11 ;
return sprintf ( V_5 , L_2 , V_8 ) ;
}
static T_1 F_5 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 , T_3 V_12 )
{
struct V_6 * V_7 ;
T_2 V_9 ;
unsigned long V_8 ;
int error ;
V_7 = F_2 ( V_2 ) ;
error = F_6 ( V_5 , 0 , & V_8 ) ;
if ( error )
return error ;
V_9 = F_7 ( V_7 -> V_10 , L_3 , V_8 ) ;
if ( ! F_4 ( V_9 ) )
return - V_11 ;
return V_12 ;
}
static T_1 F_8 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 ;
unsigned long long V_8 ;
T_2 V_9 ;
V_7 = F_2 ( V_2 ) ;
V_9 = F_3 ( V_7 -> V_10 , L_4 , NULL , & V_8 ) ;
if ( ! F_4 ( V_9 ) )
return - V_11 ;
return sprintf ( V_5 , L_2 , V_8 ) ;
}
static T_1 F_9 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 , T_3 V_12 )
{
struct V_6 * V_7 ;
T_2 V_9 ;
unsigned long V_8 ;
int error ;
V_7 = F_2 ( V_2 ) ;
error = F_6 ( V_5 , 0 , & V_8 ) ;
if ( error )
return error ;
V_9 = F_7 ( V_7 -> V_10 , L_5 , V_8 ) ;
if ( ! F_4 ( V_9 ) )
return - V_11 ;
return V_12 ;
}
static int F_10 ( struct V_6 * V_7 )
{
int error = 0 ;
error = F_11 ( & V_7 -> V_2 , & V_13 ) ;
if ( error )
goto V_14;
error = F_11 ( & V_7 -> V_2 , & V_15 ) ;
if ( error )
goto V_16;
return 0 ;
V_16:
F_12 ( & V_7 -> V_2 , & V_13 ) ;
V_14:
return error ;
}
static int F_13 ( struct V_6 * V_7 )
{
F_12 ( & V_7 -> V_2 , & V_15 ) ;
F_12 ( & V_7 -> V_2 , & V_13 ) ;
return 0 ;
}
