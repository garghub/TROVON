const char *
F_1 ( void * V_1 , T_1 V_2 )
{
T_2 * V_3 = ( T_2 * ) V_1 ;
T_3 * V_4 ;
T_4 V_5 = NULL ;
char * V_6 ;
V_4 = F_2 ( V_3 -> V_7 ) ;
if ( V_2 < V_4 -> V_8 -> V_9 )
V_5 = F_3 ( V_4 -> V_8 , T_4 , V_2 ) ;
F_4 ( V_4 ) ;
if ( V_5 ) {
if ( F_5 ( V_5 , V_10 , & V_6 ) == V_11 )
return V_6 ;
if ( F_5 ( V_5 , V_12 , & V_6 ) == V_11 )
return V_6 ;
}
return L_1 ;
}
const char *
F_6 ( void * V_1 , T_1 V_2 )
{
T_2 * V_3 = ( T_2 * ) V_1 ;
T_3 * V_4 ;
T_4 V_5 = NULL ;
char * V_6 ;
V_4 = F_2 ( V_3 -> V_7 ) ;
if ( V_2 < V_4 -> V_8 -> V_9 )
V_5 = F_3 ( V_4 -> V_8 , T_4 , V_2 ) ;
F_4 ( V_4 ) ;
if ( V_5 ) {
if ( F_5 ( V_5 , V_12 , & V_6 ) == V_11 )
return V_6 ;
}
return NULL ;
}
void
F_7 ( T_2 * V_3 )
{
memset ( V_3 , 0 , sizeof( T_2 ) ) ;
}
