static T_1
F_1 ( struct V_1 * V_1 , char * V_2 , T_1 V_3 ,
const char * V_4 , T_1 V_5 , int type )
{
const T_1 V_6 = V_7 ;
const T_1 V_8 = V_6 + V_5 + 1 ;
if ( ! F_2 ( V_9 ) )
return 0 ;
if ( V_2 && V_8 <= V_3 ) {
memcpy ( V_2 , V_10 , V_6 ) ;
memcpy ( V_2 + V_6 , V_4 , V_5 ) ;
V_2 [ V_6 + V_5 ] = '\0' ;
}
return V_8 ;
}
static int
F_3 ( struct V_1 * V_1 , const char * V_4 , void * V_11 ,
T_1 V_12 , int type )
{
if ( strcmp ( V_4 , L_1 ) == 0 )
return - V_13 ;
return F_4 ( V_1 -> V_14 , V_15 ,
V_4 , V_11 , V_12 ) ;
}
static int
F_5 ( struct V_1 * V_1 , const char * V_4 ,
const void * V_16 , T_1 V_12 , int V_17 , int type )
{
if ( strcmp ( V_4 , L_1 ) == 0 )
return - V_13 ;
return F_6 ( V_1 -> V_14 , V_15 ,
V_4 , V_16 , V_12 , V_17 ) ;
}
