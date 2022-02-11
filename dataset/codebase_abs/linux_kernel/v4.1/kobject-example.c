static T_1 F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
return sprintf ( V_5 , L_1 , V_6 ) ;
}
static T_1 F_2 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 , T_2 V_7 )
{
int V_8 ;
V_8 = F_3 ( V_5 , 10 , & V_6 ) ;
if ( V_8 < 0 )
return V_8 ;
return V_7 ;
}
static T_1 F_4 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
int V_9 ;
if ( strcmp ( V_4 -> V_4 . V_10 , L_2 ) == 0 )
V_9 = V_11 ;
else
V_9 = V_12 ;
return sprintf ( V_5 , L_1 , V_9 ) ;
}
static T_1 F_5 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 , T_2 V_7 )
{
int V_9 , V_8 ;
V_8 = F_3 ( V_5 , 10 , & V_9 ) ;
if ( V_8 < 0 )
return V_8 ;
if ( strcmp ( V_4 -> V_4 . V_10 , L_2 ) == 0 )
V_11 = V_9 ;
else
V_12 = V_9 ;
return V_7 ;
}
static int T_3 F_6 ( void )
{
int V_13 ;
V_14 = F_7 ( L_3 , V_15 ) ;
if ( ! V_14 )
return - V_16 ;
V_13 = F_8 ( V_14 , & V_17 ) ;
if ( V_13 )
F_9 ( V_14 ) ;
return V_13 ;
}
static void T_4 F_10 ( void )
{
F_9 ( V_14 ) ;
}
