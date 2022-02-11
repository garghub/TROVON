static int F_1 ( struct V_1 * V_1 , const char * V_2 ,
void * V_3 , T_1 V_4 , int type )
{
int V_5 ;
char * V_6 ;
T_1 V_7 ;
T_1 V_8 = V_9 ;
if ( V_2 == NULL )
return - V_10 ;
if ( strcmp ( V_2 , L_1 ) == 0 )
return - V_10 ;
V_7 = strlen ( V_2 ) ;
V_6 = F_2 ( V_8 + V_7 + 1 , V_11 ) ;
if ( ! V_6 )
return - V_12 ;
memcpy ( V_6 , V_13 , V_8 ) ;
memcpy ( V_6 + V_8 , V_2 , V_7 ) ;
V_6 [ V_8 + V_7 ] = '\0' ;
V_5 = F_3 ( V_1 , V_6 , V_3 , V_4 ) ;
F_4 ( V_6 ) ;
return V_5 ;
}
static int F_5 ( struct V_1 * V_1 , const char * V_2 ,
const void * V_14 , T_1 V_4 , int V_15 , int type )
{
int V_5 ;
char * V_6 ;
T_1 V_7 ;
T_1 V_8 = V_9 ;
if ( V_2 == NULL )
return - V_10 ;
if ( strcmp ( V_2 , L_1 ) == 0 )
return - V_10 ;
V_7 = strlen ( V_2 ) ;
V_6 = F_2 ( V_8 + V_7 + 1 , V_11 ) ;
if ( ! V_6 )
return - V_12 ;
memcpy ( V_6 , V_13 , V_8 ) ;
memcpy ( V_6 + V_8 , V_2 , V_7 ) ;
V_6 [ V_8 + V_7 ] = '\0' ;
V_5 = F_6 ( V_1 , V_6 , V_14 , V_4 , V_15 ) ;
F_4 ( V_6 ) ;
return V_5 ;
}
