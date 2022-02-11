static int
F_1 ( struct V_1 * V_1 , const char * V_2 , void * V_3 , T_1 V_4 ,
int V_5 )
{
if ( strlen ( V_2 ) < sizeof( V_6 ) )
return - V_7 ;
if ( ! F_2 ( V_1 -> V_8 ) )
return - V_9 ;
return F_3 ( F_4 ( V_1 ) , V_2 , V_3 , V_4 ) ;
}
static int
F_5 ( struct V_1 * V_1 , const char * V_2 , const void * V_3 ,
T_1 V_4 , int V_10 , int V_5 )
{
if ( strlen ( V_2 ) < sizeof( V_6 ) )
return - V_7 ;
if ( ! F_2 ( V_1 -> V_8 ) )
return - V_9 ;
return F_6 ( F_4 ( V_1 ) , V_2 , V_3 , V_4 , V_10 ) ;
}
static T_1 F_7 ( struct V_1 * V_1 , char * V_11 , T_1 V_12 ,
const char * V_2 , T_1 V_13 , int V_5 )
{
const T_1 V_14 = V_13 + 1 ;
if ( ! F_2 ( V_1 -> V_8 ) )
return 0 ;
if ( V_11 && V_14 <= V_12 ) {
memcpy ( V_11 , V_2 , V_13 ) ;
V_11 [ V_13 ] = '\0' ;
}
return V_14 ;
}
