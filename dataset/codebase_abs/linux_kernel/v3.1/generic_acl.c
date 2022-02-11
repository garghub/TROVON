static T_1
F_1 ( struct V_1 * V_1 , char * V_2 , T_1 V_3 ,
const char * V_4 , T_1 V_5 , int type )
{
struct V_6 * V_7 ;
const char * V_8 ;
T_1 V_9 ;
V_7 = F_2 ( V_1 -> V_10 , type ) ;
if ( ! V_7 )
return 0 ;
F_3 ( V_7 ) ;
switch ( type ) {
case V_11 :
V_8 = V_12 ;
break;
case V_13 :
V_8 = V_14 ;
break;
default:
return 0 ;
}
V_9 = strlen ( V_8 ) + 1 ;
if ( V_2 && V_9 <= V_3 )
memcpy ( V_2 , V_8 , V_9 ) ;
return V_9 ;
}
static int
F_4 ( struct V_1 * V_1 , const char * V_4 , void * V_15 ,
T_1 V_9 , int type )
{
struct V_6 * V_7 ;
int error ;
if ( strcmp ( V_4 , L_1 ) != 0 )
return - V_16 ;
V_7 = F_2 ( V_1 -> V_10 , type ) ;
if ( ! V_7 )
return - V_17 ;
error = F_5 ( V_7 , V_15 , V_9 ) ;
F_3 ( V_7 ) ;
return error ;
}
static int
F_6 ( struct V_1 * V_1 , const char * V_4 , const void * V_18 ,
T_1 V_9 , int V_19 , int type )
{
struct V_20 * V_20 = V_1 -> V_10 ;
struct V_6 * V_7 = NULL ;
int error ;
if ( strcmp ( V_4 , L_1 ) != 0 )
return - V_16 ;
if ( F_7 ( V_20 -> V_21 ) )
return - V_22 ;
if ( ! F_8 ( V_20 ) )
return - V_23 ;
if ( V_18 ) {
V_7 = F_9 ( V_18 , V_9 ) ;
if ( F_10 ( V_7 ) )
return F_11 ( V_7 ) ;
}
if ( V_7 ) {
error = F_12 ( V_7 ) ;
if ( error )
goto V_24;
switch ( type ) {
case V_11 :
error = F_13 ( V_7 , & V_20 -> V_21 ) ;
if ( error < 0 )
goto V_24;
V_20 -> V_25 = V_26 ;
if ( error == 0 ) {
F_3 ( V_7 ) ;
V_7 = NULL ;
}
break;
case V_13 :
if ( ! F_14 ( V_20 -> V_21 ) ) {
error = - V_16 ;
goto V_24;
}
break;
}
}
F_15 ( V_20 , type , V_7 ) ;
error = 0 ;
V_24:
F_3 ( V_7 ) ;
return error ;
}
int
F_16 ( struct V_20 * V_20 , struct V_20 * V_27 )
{
struct V_6 * V_7 = NULL ;
int error ;
if ( ! F_7 ( V_20 -> V_21 ) )
V_7 = F_2 ( V_27 , V_13 ) ;
if ( V_7 ) {
if ( F_14 ( V_20 -> V_21 ) )
F_15 ( V_20 , V_13 , V_7 ) ;
error = F_17 ( & V_7 , V_28 , & V_20 -> V_21 ) ;
if ( error < 0 )
return error ;
if ( error > 0 )
F_15 ( V_20 , V_11 , V_7 ) ;
} else {
V_20 -> V_21 &= ~ F_18 () ;
}
error = 0 ;
F_3 ( V_7 ) ;
return error ;
}
int
F_19 ( struct V_20 * V_20 )
{
struct V_6 * V_7 ;
int error = 0 ;
if ( F_7 ( V_20 -> V_21 ) )
return - V_22 ;
V_7 = F_2 ( V_20 , V_11 ) ;
if ( V_7 ) {
error = F_20 ( & V_7 , V_28 , V_20 -> V_21 ) ;
if ( error )
return error ;
F_15 ( V_20 , V_11 , V_7 ) ;
F_3 ( V_7 ) ;
}
return error ;
}
