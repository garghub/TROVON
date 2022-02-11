static T_1 F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 , T_2 V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_9 * V_10 = F_3 ( V_8 ) ;
int V_11 ;
if ( ! F_4 ( V_2 , V_4 ) )
return V_6 ;
F_5 () ;
F_6 ( V_8 ) ;
V_11 = F_7 ( V_10 ) ;
if ( V_11 )
goto error;
V_11 = F_8 ( V_10 ) ;
if ( V_11 )
goto error;
F_9 ( V_10 -> V_12 ) ;
F_10 () ;
return V_6 ;
error:
F_10 () ;
return V_11 ;
}
static T_1 F_11 ( struct V_13 * V_14 , struct V_15 * V_16 ,
struct V_17 * V_4 , char * V_5 ,
T_3 V_18 , T_2 V_6 )
{
struct V_1 * V_2 = F_12 ( V_16 ) ;
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_9 * V_10 = F_3 ( V_8 ) ;
return F_13 ( V_5 , V_6 , & V_18 , V_10 -> V_19 ,
sizeof( V_10 -> V_19 ) ) ;
}
