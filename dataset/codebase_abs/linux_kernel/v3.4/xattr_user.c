static int
F_1 ( struct V_1 * V_1 , const char * V_2 , void * V_3 , T_1 V_4 ,
int V_5 )
{
if ( strlen ( V_2 ) < sizeof( V_6 ) )
return - V_7 ;
if ( ! F_2 ( V_1 -> V_8 ) )
return - V_9 ;
return F_3 ( V_1 -> V_10 , V_2 , V_3 , V_4 ) ;
}
static int
F_4 ( struct V_1 * V_1 , const char * V_2 , const void * V_3 ,
T_1 V_4 , int V_11 , int V_5 )
{
if ( strlen ( V_2 ) < sizeof( V_6 ) )
return - V_7 ;
if ( ! F_2 ( V_1 -> V_8 ) )
return - V_9 ;
return F_5 ( V_1 -> V_10 , V_2 , V_3 , V_4 , V_11 ) ;
}
static T_1 F_6 ( struct V_1 * V_1 , char * V_12 , T_1 V_13 ,
const char * V_2 , T_1 V_14 , int V_5 )
{
const T_1 V_15 = V_14 + 1 ;
if ( ! F_2 ( V_1 -> V_8 ) )
return 0 ;
if ( V_12 && V_15 <= V_13 ) {
memcpy ( V_12 , V_2 , V_14 ) ;
V_12 [ V_14 ] = '\0' ;
}
return V_15 ;
}
