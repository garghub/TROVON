T_1 * F_1 ( T_1 * V_1 , T_2 V_2 )
{
struct V_3 * V_4 ;
struct V_3 V_5 ;
V_4 = F_2 ( & V_2 , & V_5 ) ;
if ( V_4 == NULL )
return NULL ;
if( ( V_4 -> V_6 >= 50 ) && ( V_4 -> V_6 < 150 ) )
return F_3 ( V_1 , V_2 ) ;
return F_4 ( V_1 , V_2 ) ;
}
int F_5 ( T_1 * V_2 )
{
if ( V_2 -> type == V_7 )
return F_6 ( V_2 ) ;
else if ( V_2 -> type == V_8 )
return F_7 ( V_2 ) ;
return 0 ;
}
T_3 * F_8 ( T_1 * V_2 , T_3 * * V_9 )
{
T_3 * V_10 ;
char * V_11 ;
if ( ! F_5 ( V_2 ) ) return NULL ;
if ( ! V_9 || ! * V_9 )
{
if ( ! ( V_10 = F_9 () ) )
return NULL ;
if ( V_9 ) * V_9 = V_10 ;
}
else V_10 = * V_9 ;
if ( V_2 -> type == V_7 )
{
if( ! F_10 ( V_10 , V_2 -> V_5 , V_2 -> V_12 ) )
return NULL ;
return V_10 ;
}
if ( ! F_10 ( V_10 , NULL , V_2 -> V_12 + 2 ) )
return NULL ;
V_11 = ( char * ) V_10 -> V_5 ;
if ( V_2 -> V_5 [ 0 ] >= '5' ) strcpy ( V_11 , L_1 ) ;
else strcpy ( V_11 , L_2 ) ;
F_11 ( V_11 , ( char * ) V_2 -> V_5 , V_2 -> V_12 + 2 ) ;
return V_10 ;
}
