static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 ;
struct V_8 V_9 = { V_10 , NULL } ;
union V_11 * V_12 ;
T_2 V_13 ;
V_7 = F_2 ( V_2 ) ;
V_13 = F_3 ( V_7 -> V_14 , L_1 , NULL , & V_9 ) ;
if ( ! F_4 ( V_13 ) )
return - V_15 ;
V_12 = V_9 . V_16 ;
if ( V_12 -> type != V_17 ) {
F_5 ( V_12 ) ;
return - V_15 ;
}
return sprintf ( V_5 , L_2 , V_12 -> integer . V_18 ) ;
}
static T_1 F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 , T_3 V_19 )
{
struct V_6 * V_7 ;
struct V_20 V_21 ;
union V_11 V_22 ;
T_2 V_13 ;
unsigned long V_18 ;
int error ;
V_7 = F_2 ( V_2 ) ;
error = F_7 ( V_5 , 0 , & V_18 ) ;
if ( error )
return error ;
V_22 . type = V_17 ;
V_22 . integer . V_18 = V_18 ;
V_21 . V_19 = 1 ;
V_21 . V_16 = & V_22 ;
V_13 = F_3 ( V_7 -> V_14 , L_3 , & V_21 , NULL ) ;
if ( ! F_4 ( V_13 ) )
return - V_15 ;
return V_19 ;
}
static T_1 F_8 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 ;
struct V_8 V_9 = { V_10 , NULL } ;
union V_11 * V_12 ;
T_2 V_13 ;
V_7 = F_2 ( V_2 ) ;
V_13 = F_3 ( V_7 -> V_14 , L_4 , NULL , & V_9 ) ;
if ( ! F_4 ( V_13 ) )
return - V_15 ;
V_12 = V_9 . V_16 ;
if ( V_12 -> type != V_17 ) {
F_5 ( V_12 ) ;
return - V_15 ;
}
return sprintf ( V_5 , L_2 , V_12 -> integer . V_18 ) ;
}
static T_1 F_9 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 , T_3 V_19 )
{
struct V_6 * V_7 ;
struct V_20 V_21 ;
union V_11 V_22 ;
T_2 V_13 ;
unsigned long V_18 ;
int error ;
V_7 = F_2 ( V_2 ) ;
error = F_7 ( V_5 , 0 , & V_18 ) ;
if ( error )
return error ;
V_22 . type = V_17 ;
V_22 . integer . V_18 = V_18 ;
V_21 . V_19 = 1 ;
V_21 . V_16 = & V_22 ;
V_13 = F_3 ( V_7 -> V_14 , L_5 , & V_21 , NULL ) ;
if ( ! F_4 ( V_13 ) )
return - V_15 ;
return V_19 ;
}
static int F_10 ( struct V_6 * V_7 )
{
int error = 0 ;
error = F_11 ( & V_7 -> V_2 , & V_23 ) ;
if ( error )
goto V_24;
error = F_11 ( & V_7 -> V_2 , & V_25 ) ;
if ( error )
goto V_26;
return 0 ;
V_26:
F_12 ( & V_7 -> V_2 , & V_23 ) ;
V_24:
return error ;
}
static int F_13 ( struct V_6 * V_7 )
{
F_12 ( & V_7 -> V_2 , & V_25 ) ;
F_12 ( & V_7 -> V_2 , & V_23 ) ;
return 0 ;
}
static int F_14 ( void )
{
return F_15 ( & V_27 ) ;
}
static void F_16 ( void )
{
F_17 ( & V_27 ) ;
}
