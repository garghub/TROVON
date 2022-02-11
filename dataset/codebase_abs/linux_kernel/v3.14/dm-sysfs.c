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
static T_1 F_5 ( struct V_8 * V_9 , char * V_14 )
{
if ( F_6 ( V_9 , V_14 , NULL ) )
return - V_12 ;
strcat ( V_14 , L_1 ) ;
return strlen ( V_14 ) ;
}
static T_1 F_7 ( struct V_8 * V_9 , char * V_14 )
{
if ( F_6 ( V_9 , NULL , V_14 ) )
return - V_12 ;
strcat ( V_14 , L_1 ) ;
return strlen ( V_14 ) ;
}
static T_1 F_8 ( struct V_8 * V_9 , char * V_14 )
{
sprintf ( V_14 , L_2 , F_9 ( V_9 ) ) ;
return strlen ( V_14 ) ;
}
int F_10 ( struct V_8 * V_9 )
{
return F_11 ( F_12 ( V_9 ) , & V_15 ,
& F_13 ( F_14 ( V_9 ) ) -> V_2 ,
L_3 , L_4 ) ;
}
void F_15 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_12 ( V_9 ) ;
F_16 ( V_2 ) ;
F_17 ( F_18 ( V_2 ) ) ;
}
