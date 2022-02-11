static int F_1 ( struct V_1 * V_1 , const char * V_2 ,
void * V_3 , T_1 V_4 , int type )
{
char * V_5 ;
int V_6 ;
if ( ! strcmp ( V_2 , L_1 ) )
return - V_7 ;
V_5 = F_2 ( V_8 * V_9 + 1 ,
V_10 ) ;
if ( ! V_5 )
return - V_11 ;
strcpy ( V_5 , V_12 ) ;
strcpy ( V_5 + V_13 , V_2 ) ;
V_6 = F_3 ( V_1 , V_5 , V_3 , V_4 ) ;
F_4 ( V_5 ) ;
return V_6 ;
}
static int F_5 ( struct V_1 * V_1 , const char * V_2 ,
const void * V_3 , T_1 V_4 , int V_14 , int type )
{
char * V_5 ;
int V_6 ;
if ( ! strcmp ( V_2 , L_1 ) )
return - V_7 ;
V_5 = F_2 ( V_8 * V_9 + 1 ,
V_10 ) ;
if ( ! V_5 )
return - V_11 ;
strcpy ( V_5 , V_12 ) ;
strcpy ( V_5 + V_13 , V_2 ) ;
V_6 = F_6 ( V_1 , V_5 , V_3 , V_4 , V_14 ) ;
F_4 ( V_5 ) ;
return V_6 ;
}
static T_1 F_7 ( struct V_1 * V_1 , char * V_15 ,
T_1 V_16 , const char * V_2 , T_1 V_17 , int type )
{
return - V_18 ;
}
