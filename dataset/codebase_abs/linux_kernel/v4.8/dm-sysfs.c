static T_1 F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 ;
struct V_8 * V_9 ;
T_1 V_10 ;
V_7 = F_2 ( V_4 , struct V_6 , V_4 ) ;
if ( ! V_7 -> V_11 )
return - V_12 ;
V_9 = F_3 ( V_2 ) ;
if ( ! V_9 )
return - V_13 ;
V_10 = V_7 -> V_11 ( V_9 , V_5 ) ;
F_4 ( V_9 ) ;
return V_10 ;
}
static T_1 F_5 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 , T_2 V_14 )
{
struct V_6 * V_7 ;
struct V_8 * V_9 ;
T_1 V_10 ;
V_7 = F_2 ( V_4 , struct V_6 , V_4 ) ;
if ( ! V_7 -> V_15 )
return - V_12 ;
V_9 = F_3 ( V_2 ) ;
if ( ! V_9 )
return - V_13 ;
V_10 = V_7 -> V_15 ( V_9 , V_5 , V_14 ) ;
F_4 ( V_9 ) ;
return V_10 ;
}
static T_1 F_6 ( struct V_8 * V_9 , char * V_16 )
{
if ( F_7 ( V_9 , V_16 , NULL ) )
return - V_12 ;
strcat ( V_16 , L_1 ) ;
return strlen ( V_16 ) ;
}
static T_1 F_8 ( struct V_8 * V_9 , char * V_16 )
{
if ( F_7 ( V_9 , NULL , V_16 ) )
return - V_12 ;
strcat ( V_16 , L_1 ) ;
return strlen ( V_16 ) ;
}
static T_1 F_9 ( struct V_8 * V_9 , char * V_16 )
{
sprintf ( V_16 , L_2 , F_10 ( V_9 ) ) ;
return strlen ( V_16 ) ;
}
static T_1 F_11 ( struct V_8 * V_9 , char * V_16 )
{
sprintf ( V_16 , L_2 , F_12 ( V_9 ) ) ;
return strlen ( V_16 ) ;
}
int F_13 ( struct V_8 * V_9 )
{
return F_14 ( F_15 ( V_9 ) , & V_17 ,
& F_16 ( F_17 ( V_9 ) ) -> V_2 ,
L_3 , L_4 ) ;
}
void F_18 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_15 ( V_9 ) ;
F_19 ( V_2 ) ;
F_20 ( F_21 ( V_2 ) ) ;
}
