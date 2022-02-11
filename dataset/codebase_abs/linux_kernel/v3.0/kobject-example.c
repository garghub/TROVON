static T_1 F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
return sprintf ( V_5 , L_1 , V_6 ) ;
}
static T_1 F_2 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 , T_2 V_7 )
{
sscanf ( V_5 , L_2 , & V_6 ) ;
return V_7 ;
}
static T_1 F_3 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
int V_8 ;
if ( strcmp ( V_4 -> V_4 . V_9 , L_3 ) == 0 )
V_8 = V_10 ;
else
V_8 = V_11 ;
return sprintf ( V_5 , L_1 , V_8 ) ;
}
static T_1 F_4 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 , T_2 V_7 )
{
int V_8 ;
sscanf ( V_5 , L_2 , & V_8 ) ;
if ( strcmp ( V_4 -> V_4 . V_9 , L_3 ) == 0 )
V_10 = V_8 ;
else
V_11 = V_8 ;
return V_7 ;
}
static int T_3 F_5 ( void )
{
int V_12 ;
V_13 = F_6 ( L_4 , V_14 ) ;
if ( ! V_13 )
return - V_15 ;
V_12 = F_7 ( V_13 , & V_16 ) ;
if ( V_12 )
F_8 ( V_13 ) ;
return V_12 ;
}
static void T_4 F_9 ( void )
{
F_8 ( V_13 ) ;
}
