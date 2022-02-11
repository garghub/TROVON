int F_1 ( struct V_1 * V_2 )
{
const char * V_3 ;
int V_4 , V_5 ;
V_4 = F_2 ( V_2 , L_1 , & V_3 ) ;
if ( V_4 < 0 )
return V_4 ;
for ( V_5 = 0 ; V_5 < F_3 ( V_6 ) ; V_5 ++ )
if ( ! strcasecmp ( V_3 , V_6 [ V_5 ] ) )
return V_5 ;
return - V_7 ;
}
const void * F_4 ( struct V_1 * V_2 )
{
struct V_8 * V_9 ;
V_9 = F_5 ( V_2 , L_2 , NULL ) ;
if ( V_9 && ( V_9 -> V_10 == 6 ) && F_6 ( V_9 -> V_11 ) )
return V_9 -> V_11 ;
V_9 = F_5 ( V_2 , L_3 , NULL ) ;
if ( V_9 && ( V_9 -> V_10 == 6 ) && F_6 ( V_9 -> V_11 ) )
return V_9 -> V_11 ;
V_9 = F_5 ( V_2 , L_4 , NULL ) ;
if ( V_9 && ( V_9 -> V_10 == 6 ) && F_6 ( V_9 -> V_11 ) )
return V_9 -> V_11 ;
return NULL ;
}
