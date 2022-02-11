int F_1 ( struct V_1 * V_2 )
{
const char * V_3 ;
int V_4 , V_5 ;
V_4 = F_2 ( V_2 , L_1 , & V_3 ) ;
if ( V_4 < 0 )
V_4 = F_2 ( V_2 , L_2 , & V_3 ) ;
if ( V_4 < 0 )
return V_4 ;
for ( V_5 = 0 ; V_5 < V_6 ; V_5 ++ )
if ( ! strcasecmp ( V_3 , F_3 ( V_5 ) ) )
return V_5 ;
return - V_7 ;
}
static const void * F_4 ( struct V_1 * V_2 , const char * V_8 )
{
struct V_9 * V_10 = F_5 ( V_2 , V_8 , NULL ) ;
if ( V_10 && V_10 -> V_11 == V_12 && F_6 ( V_10 -> V_13 ) )
return V_10 -> V_13 ;
return NULL ;
}
const void * F_7 ( struct V_1 * V_2 )
{
const void * V_14 ;
V_14 = F_4 ( V_2 , L_3 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_4 ( V_2 , L_4 ) ;
if ( V_14 )
return V_14 ;
return F_4 ( V_2 , L_5 ) ;
}
