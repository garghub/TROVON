const char * F_1 ( unsigned int V_1 )
{
const struct V_2 * V_3 ;
for ( V_3 = V_4 ; V_3 -> V_5 != NULL ; V_3 ++ )
if ( V_3 -> V_6 == V_1 )
return V_3 -> V_5 ;
return NULL ;
}
int F_2 ( const char * V_5 )
{
const struct V_2 * V_3 ;
for ( V_3 = V_4 ; V_3 -> V_5 != NULL ; V_3 ++ )
if ( ! strcmp ( V_3 -> V_5 , V_5 ) )
return F_3 ( V_3 -> V_6 ) ;
return - V_7 ;
}
