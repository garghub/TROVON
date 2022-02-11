static int
F_1 ( const struct V_1 * V_2 , struct V_3 * V_3 ,
const char * V_4 , void * V_5 , T_1 V_6 )
{
if ( strlen ( V_4 ) < sizeof( V_7 ) )
return - V_8 ;
if ( ! F_2 ( V_3 -> V_9 ) )
return - V_10 ;
return F_3 ( F_4 ( V_3 ) , V_4 , V_5 , V_6 ) ;
}
static int
F_5 ( const struct V_1 * V_2 , struct V_3 * V_3 ,
const char * V_4 , const void * V_5 , T_1 V_6 , int V_11 )
{
if ( strlen ( V_4 ) < sizeof( V_7 ) )
return - V_8 ;
if ( ! F_2 ( V_3 -> V_9 ) )
return - V_10 ;
return F_6 ( F_4 ( V_3 ) , V_4 , V_5 , V_6 , V_11 ) ;
}
static T_1 F_7 ( const struct V_1 * V_2 ,
struct V_3 * V_3 , char * V_12 , T_1 V_13 ,
const char * V_4 , T_1 V_14 )
{
const T_1 V_15 = V_14 + 1 ;
if ( ! F_2 ( V_3 -> V_9 ) )
return 0 ;
if ( V_12 && V_15 <= V_13 ) {
memcpy ( V_12 , V_4 , V_14 ) ;
V_12 [ V_14 ] = '\0' ;
}
return V_15 ;
}
